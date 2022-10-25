#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <dolphin/gx.h>
#include <dolphin/mtx.h>
#include <dolphin/vi.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>

// used only as a reference
gx::GXRenderModeObj GXNtsc480Prog =
	{
		vi::VI_TVMODE_NTSC_PROG,		 // viDisplayMode
		640,							 // fbWidth
		480,							 // efbHeight
		480,							 // xfbHeight
		(VI_MAX_WIDTH_NTSC - 640) / 2,	 // viXOrigin
		(VI_MAX_HEIGHT_NTSC - 480) / 2,	 // viYOrigin
		640,							 // viWidth
		480,							 // viHeight
		vi::VI_XFBMODE_SF,				 // xFBmode
		0,								 // field_rendering
		0,								 // aa

		// sample points arranged in increasing Y order
		6, 6, 6, 6, 6, 6,  // pix 0, 3 sample points, 1/12 units, 4 bits each
		6, 6, 6, 6, 6, 6,  // pix 1
		6, 6, 6, 6, 6, 6,  // pix 2
		6, 6, 6, 6, 6, 6,  // pix 3

		// vertical filter[7], 1/64 units, 6 bits each
		0,	 // line n-1
		0,	 // line n-1
		21,	 // line n
		22,	 // line n
		21,	 // line n
		0,	 // line n+1
		0	 // line n+1
};

void GLAPIENTRY
MessageCallback(GLenum source,
				GLenum type,
				GLuint id,
				GLenum severity,
				GLsizei length,
				const GLchar *message,
				const void *userParam) {
	(void)id;
	(void)userParam;
	(void)length;
	(void)source;
	fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
			(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
			type, severity, message);
	if (type == GL_DEBUG_TYPE_ERROR)
		abort();
}

namespace gx {
	// GX use the same constants to indicate the same operation that uses
	// the other operand, but GL uses different, so we need contextual use
	int GX2GL(GXBlendFactor a, bool isdst) {
		switch (a) {
		case GXBlendFactor::GX_BL_ZERO:
			return GL_ZERO;
		case GXBlendFactor::GX_BL_ONE:
			return GL_ONE;
		//case GXBlendFactor::GX_BL_DSTCLR:
		case GXBlendFactor::GX_BL_SRCCLR:
			return isdst ? GL_SRC_COLOR : GL_DST_COLOR;
		//case GXBlendFactor::GX_BL_INVDSTCLR:
		case GXBlendFactor::GX_BL_INVSRCCLR:
			return isdst ? GL_ONE_MINUS_SRC_COLOR : GL_ONE_MINUS_DST_COLOR;
		case GXBlendFactor::GX_BL_SRCALPHA:
			return GL_SRC_ALPHA;
		case GXBlendFactor::GX_BL_INVSRCALPHA:
			return GL_ONE_MINUS_SRC_ALPHA;
		case GXBlendFactor::GX_BL_DSTALPHA:
			return GL_DST_ALPHA;
		case GXBlendFactor::GX_BL_INVDSTALPHA:
			return GL_ONE_MINUS_DST_ALPHA;
		}
	}

	int GX2GL(GXCompare b) {
		switch (b) {
		case GXCompare::GX_ALWAYS:
			return GL_ALWAYS;
		case GXCompare::GX_EQUAL:
			return GL_EQUAL;
		case GXCompare::GX_GEQUAL:
			return GL_GEQUAL;
		case GXCompare::GX_GREATER:
			return GL_GREATER;
		case GXCompare::GX_LEQUAL:
			return GL_LEQUAL;
		case GXCompare::GX_LESS:
			return GL_LESS;
		case GXCompare::GX_NEQUAL:
			return GL_NOTEQUAL;
		case GXCompare::GX_NEVER:
			return GL_NEVER;
		}
	}

	int GX2GL(GXCullMode a) {
		switch (a) {
		case GXCullMode::GX_CULL_ALL:
			return GL_FRONT_AND_BACK;
		case GXCullMode::GX_CULL_BACK:
			return GL_BACK;
		case GXCullMode::GX_CULL_FRONT:
			return GL_FRONT;
			break;
		}
	}

	struct IndSettings {
		GXIndTexStageID ind_stage;
		GXIndTexFormat format;
		GXIndTexBiasSel bias_sel;
		GXIndTexMtxID matrix_sel;
		GXIndTexWrap wrap_s;
		GXIndTexWrap wrap_t;
		GXBool add_prev;
		GXBool utc_lod;
		GXIndTexAlphaSel alpha_sel;
	};

	struct TevState {
		int ksel;
		int kasel;
		GXColor c;

		int ras_swizzle;
		int tex_swizzle;

		GXTevAlphaArg a_inputs[4];
		GXTevColorArg c_inputs[4];

		struct TevOp {
			GXTevOp op;
			GXTevBias bias;
			GXTevScale scale;
			GXBool clamp;
			GXTevRegID out_reg;
		};

		TevOp aop, cop;

		GXTexCoordID coord;
		GXTexMapID tmap;
		GXChannelID chan;

		IndSettings indirection;
	};
	struct TexGenState {
		GXTexGenType func;
		GXTexGenSrc src;
		u32 mtxid;
		u32 ptmtx;
		bool normalize;
		bool line_bias;
		bool point_bias;
	};

	using IndTMtx = f32[2][3];

	struct ChanState {
		GXBool enable;

		GXColorSrc amb_src;
		GXColorSrc mat_src;
		u32 light_mask;
		GXDiffuseFn diff_fn;
		GXAttnFn attn_fn;

		GXColor amb_color;
		GXColor mat_color;
	};

	struct IndTex {
		float ss, st;
		GXTexCoordID coord;
		GXTexMapID map;
	};

	// represent the entire pipeline state, will be passed in a shader storage object on each drawcall
	// update is delayed to drawing commands or flushing
	struct {
		int swizzles[4][4];

		GXColorS10 tregs[3];
		GXColor kregs[4];
		TevState tevs[8];
		TexGenState tgs[8];
		ChanState chans[2];
		IndTex indtex[4];
		IndTMtx indmtx[3];
		s8 inds[3];

		int texgens;
		int tevstages;
		int colchans;
		int indn;
		int dither;

		float point_sprite_uv_bias;
		float line_sprite_uv_bias;
		uint current_mtx;

		struct {
			GXCompare comp0;
			unsigned char ref0;
			GXAlphaOp op;
			GXCompare comp1;
			unsigned char ref1;
		} alphacomp;

		bool cupdate;
		bool aupdate;

		mtx::Mtx norm_mat[10];
		mtx::Mtx pos_mat[10];

		mtx::Mtx texmtx[10];

		mtx::Mtx pos_tex_trans[20];

		mtx::Mtx44 persp_proj;
		mtx::Mtx44 ortho_proj;
	} gxState;

	struct {
		u32 vao;
	} glState;

	namespace internal {
		struct GXLightObj {
			u32 reserved[3];
			gx::GXColor color;
			float a[3], k[3], lpos[3], dir[3];
		};

		struct GXTexObj {
		};
	}

	byte *__peReg;

	void GXBegin(GXPrimitive, GXVtxFmt, unsigned short) {}

	void GXInitTexObjLOD(GXTexObj *, GXTexFilter, GXTexFilter, float, float, float, unsigned char, unsigned char, GXAnisotropy) {}
	void GXInitTexObj(GXTexObj *, void *, unsigned short, unsigned short, GXTexFmt, GXTexWrapMode, GXTexWrapMode, unsigned char) {}
	void GXLoadTexObj(GXTexObj const *, GXTexMapID) {}

	u32 GXGetTexBufferSize(unsigned short, unsigned short, unsigned int, unsigned char, unsigned char) { return 0; }
	void GXLoadTlut(const GXTlutObj *tlut_obj, u32 tlut_name) {}

	void GXClearVtxDesc() {
		glDeleteVertexArrays(1, &glState.vao);
		glGenVertexArrays(1, &glState.vao);
	}

	void GXDrawDone() {
	}

	void *GXGetTexObjData(GXTexObj *param_1) {
		return 0;
	}

	void GXSetVtxDesc(GXAttr a, GXAttrType t) {

	}
	void GXSetVtxAttrFmt(GXVtxFmt, GXAttr, GXCompCnt, GXCompType, unsigned char) {}
	void GXFlush() {}

	void GXInvalidateTexAll() {}

	// could be used as a hint to refresh the VBOs?
	void GXInvalidateVtxCache() {}
	void GXSetDrawDone() {}

	void GXSetFog(GXFogType, float, float, float, float, GXColor) {}
	void GXSetFogRangeAdj(unsigned char, unsigned short, GXFogAdjTable const *) {}
	void GXSetDispCopyDst(unsigned short, unsigned short) {}
	void GXSetDispCopyGamma(GXGamma) {}
	void GXSetDispCopySrc(unsigned short, unsigned short, unsigned short, unsigned short) {}
	void GXSetCopyFilter(unsigned char, unsigned char const (*)[2], unsigned char, unsigned char const *) {}
	void GXSetCopyClear(GXColor, unsigned int) {
		// wut
	}
	// happens on JUTGraphFifo destruction which is hopefully never
	void GXInitFifoBase(gx::GXFifoObj *, void *, unsigned int) {}
	void GXInitFifoPtrs(gx::GXFifoObj *, void *, void *) {}
	void GXPixModeSync() {}
	void GXSaveCPUFifo(gx::GXFifoObj *) {}
	void GXSetCopyClamp(GXFBClamp) {}

	void GXSetDstAlpha(unsigned char, unsigned char) {}
	void GXCopyDisp(void *, unsigned char) {}

	void GXSetPixelFmt(GXPixelFmt, GXZFmt16) {}

	void GXSetZTexture(GXZTexOp, GXTexFmt, unsigned int) {}

	void GXSetPointSize(u8 size, GXTexOffset tex_offsets) {
		glPointSize((float)size / 6.0f);
		switch (tex_offsets) {
		case GXTexOffset::GX_TO_ZERO:
			gxState.point_sprite_uv_bias = 0;
			break;
		case GXTexOffset::GX_TO_SIXTEENTH:
			gxState.point_sprite_uv_bias = 1.0f / 16.0f;
			break;
		case GXTexOffset::GX_TO_EIGHTH:
			gxState.point_sprite_uv_bias = 1.0f / 8.0f;
			break;
		case GXTexOffset::GX_TO_FOURTH:
			gxState.point_sprite_uv_bias = 1.0f / 4.0f;
			break;
		case GXTexOffset::GX_TO_HALF:
			gxState.point_sprite_uv_bias = 1.0f / 2.0f;
			break;
		case GXTexOffset::GX_TO_ONE:
			gxState.point_sprite_uv_bias = 1.0f;
			break;
		default:
			break;
		}
	}

	void GXPeekZ(unsigned short x, unsigned short y, unsigned int *o) {
		glReadPixels(x, y, 1, 1, GL_DEPTH_STENCIL, GL_UNSIGNED_INT_24_8, o);
		*o &= 0xFFFFFF;
	}

	void GXSetIndTexCoordScale(GXIndTexStageID id, GXIndTexScale a, GXIndTexScale b) {
		gxState.indtex[id].ss = 1.0f / (1 << a);
		gxState.indtex[id].st = 1.0f / (1 << b);
	}

	void GXSetTevSwapMode(
		GXTevStageID stage,
		GXTevSwapSel ras_sel,
		GXTevSwapSel tex_sel) {
		gxState.tevs[stage].ras_swizzle = ras_sel;
		gxState.tevs[stage].tex_swizzle = tex_sel;
	}

	void GXSetChanAmbColor(GXChannelID id, GXColor col) {
		switch (id) {
		case GXChannelID::GX_COLOR0:
			gxState.chans[0].amb_color.r = col.r;
			gxState.chans[0].amb_color.g = col.g;
			gxState.chans[0].amb_color.b = col.b;
			break;
		case GXChannelID::GX_COLOR1:
			gxState.chans[1].amb_color.r = col.r;
			gxState.chans[1].amb_color.g = col.g;
			gxState.chans[1].amb_color.b = col.b;
			break;
		case GXChannelID::GX_ALPHA0:
			gxState.chans[0].amb_color.a = col.a;
			break;
		case GXChannelID::GX_ALPHA1:
			gxState.chans[1].amb_color.a = col.a;
			break;
		case GXChannelID::GX_COLOR0A0:
			gxState.chans[0].amb_color = col;
			break;
		case GXChannelID::GX_COLOR1A1:
			gxState.chans[1].amb_color = col;
			break;
		default:
			break;
		}
	}

	void GXSetIndTexOrder(GXIndTexStageID ind_stage, GXTexCoordID tex_coord,
						  GXTexMapID tex_map) {
		gxState.indtex[ind_stage].coord = tex_coord;
		gxState.indtex[ind_stage].map = tex_map;
	}

	void GXSetBlendMode(GXBlendMode a, GXBlendFactor b, GXBlendFactor c, GXLogicOp d) {
		/*
		GXSetBlendMode is always called with a blend mode, not an arithmetic mode, 
		however the game allows any mode to be set from externally loaded resources
		It's also called with the "new" mode subtract in J2DScreen::drawSelf
		*/
		switch (a) {
		case GXBlendMode::GX_BM_BLEND:
			glBlendEquation(GL_FUNC_ADD);
			glBlendFunc(GX2GL(b, false), GX2GL(c, true));
			break;
		case GXBlendMode::GX_BM_SUBTRACT:
			glBlendEquation(GL_FUNC_SUBTRACT);
			glBlendFunc(GL_ONE, GL_ONE);
			break;
		}
	}
	void GXSetChanCtrl(GXChannelID i, unsigned char a, GXColorSrc b, GXColorSrc c, u32 d, GXDiffuseFn e, GXAttnFn f) {
		gxState.chans[i].enable = a;
		gxState.chans[i].amb_src = b;
		gxState.chans[i].mat_src = c;
		gxState.chans[i].light_mask = d;
		gxState.chans[i].diff_fn = e;
		gxState.chans[i].attn_fn = f;
	}

	void GXSetTevOrder(GXTevStageID id, GXTexCoordID coord, GXTexMapID tmap, GXChannelID chan) {
		gxState.tevs[id].coord = coord;
		gxState.tevs[id].tmap = tmap;
		gxState.tevs[id].chan = chan;
	}

	void GXSetTevSwapModeTable(GXTevSwapSel i, GXTevColorChan r, GXTevColorChan g, GXTevColorChan b, GXTevColorChan a) {
		gxState.swizzles[i][0] = r;
		gxState.swizzles[i][1] = g;
		gxState.swizzles[i][2] = b;
		gxState.swizzles[i][3] = a;
	}

	// correct implementation required for the fake sea waves billboards to render properly
	void GXSetZCompLoc(GXBool) {
		// the opengl extension for this forbids writing to gl_fragdepth but it shouldnt be an issue?
		// early z test?
		// or is it just a matter of discarding a fragment if it doesnt pass the alpha test?
	}

	void GXSetIndTexMtx(
		GXIndTexMtxID mtx_sel,
		const IndTMtx offset_mtx,
		s8 scale_exp) {
		memcpy(gxState.indmtx[mtx_sel], offset_mtx, sizeof(IndTMtx));
		gxState.inds[mtx_sel] = scale_exp;
	}

	// controls XF and DLs flushing settings, irrelevant here
	void GXSetMisc(GXMiscToken, unsigned int) {}

	void GXSetTevColorS10(GXTevRegID id, GXColorS10 c) {
		gxState.tregs[id] = c;
	}

	void GXSetTevDirect(GXTevStageID a) {
		GXSetTevIndirect(a,
						 GXIndTexStageID::GX_INDTEXSTAGE0,
						 GXIndTexFormat::GX_ITF_8,
						 GXIndTexBiasSel::GX_ITB_NONE,
						 GXIndTexMtxID::GX_ITM_OFF,
						 GXIndTexWrap::GX_ITW_OFF,
						 GXIndTexWrap::GX_ITW_OFF,
						 0, 0,
						 GXIndTexAlphaSel::GX_ITBA_OFF);
	}

	void GXSetTevIndirect(GXTevStageID tev_stage,
						  GXIndTexStageID ind_stage,
						  GXIndTexFormat format,
						  GXIndTexBiasSel bias_sel,
						  GXIndTexMtxID matrix_sel,
						  GXIndTexWrap wrap_s,
						  GXIndTexWrap wrap_t,
						  GXBool add_prev,
						  GXBool utc_lod,
						  GXIndTexAlphaSel alpha_sel) {
		gxState.tevs[tev_stage].indirection = {
			ind_stage,
			format,
			bias_sel,
			matrix_sel,
			wrap_s,
			wrap_t,
			add_prev,
			utc_lod,
			alpha_sel};
	}

	void GXSetTevIndWarp(GXTevStageID tev_stage,
						 GXIndTexStageID ind_stage,
						 GXBool signed_offsets,
						 GXBool replace_mode,
						 GXIndTexMtxID matrix_sel) {
		auto wrap = (replace_mode) ? GX_ITW_0 : GX_ITW_OFF;
		GXSetTevIndirect(
			tev_stage,									  // tev stage
			ind_stage,									  // indirect stage
			GX_ITF_8,									  // format
			(signed_offsets) ? GX_ITB_STU : GX_ITB_NONE,  // bias
			matrix_sel,
			wrap,		 // wrap direct S
			wrap,		 // wrap direct T
			0,			 // add prev stage output?
			0,			 // use unmodified TC for LOD?
			GX_ITBA_OFF	 // bump alpha select
		);
	}

	void GXSetTevKColor(GXTevKColorID id, GXColor c) {
		gxState.kregs[id] = c;
	}

	// obviously only happens in catastrophic scenarios
	void GXAbortFrame() {}

	// used for crash/hang diagnostics, so not implemented
	void GXGetGPStatus(unsigned char *, unsigned char *, unsigned char *, unsigned char *, unsigned char *) {}

	void GXLoadTexMtxImm(float const (*mtx)[4], unsigned int id, GXTexMtxType t) {
		mtx::Mtx m;
		switch (t) {
		case GXTexMtxType::GX_MTX2x4:
			// TODO, convert 2x4 into 3x4
			break;
		case GXTexMtxType::GX_MTX3x4:
			memcpy(m, mtx, sizeof(m));
			break;
		}
		memcpy(gxState.texmtx + id, m, sizeof(m));
	}

	// used for crash/hang diagnostics, so not implemented
	void GXReadXfRasMetric(unsigned int *, unsigned int *, unsigned int *, unsigned int *) {}

	void GXSetClipMode(GXClipMode) {
		// no idea what to do here
	}

	void GXSetCoPlanar(unsigned char) {
		// the fabled zfreeze
		// fortunately the game just redundantly calls this function to disable the feature
		// so not implemented
	}

	void GXSetLineWidth(unsigned char size, GXTexOffset tex_offsets) {
		glPointSize((float)size / 6.0f);
		switch (tex_offsets) {
		case GXTexOffset::GX_TO_ZERO:
			gxState.line_sprite_uv_bias = 0;
			break;
		case GXTexOffset::GX_TO_SIXTEENTH:
			gxState.line_sprite_uv_bias = 1.0f / 16.0f;
			break;
		case GXTexOffset::GX_TO_EIGHTH:
			gxState.line_sprite_uv_bias = 1.0f / 8.0f;
			break;
		case GXTexOffset::GX_TO_FOURTH:
			gxState.line_sprite_uv_bias = 1.0f / 4.0f;
			break;
		case GXTexOffset::GX_TO_HALF:
			gxState.line_sprite_uv_bias = 1.0f / 2.0f;
			break;
		case GXTexOffset::GX_TO_ONE:
			gxState.line_sprite_uv_bias = 1.0f;
			break;
		default:
			break;
		}
	}

	void GXSetNumIndStages(unsigned char c) {
		gxState.indn = c;
	}

	void GXSetProjection(const mtx::Mtx44 m, GXProjectionType t) {
		if (t == GXProjectionType::GX_ORTHOGRAPHIC) {
			memcpy(gxState.ortho_proj, m, sizeof(mtx::Mtx44));
		} else {
			memcpy(gxState.persp_proj, m, sizeof(mtx::Mtx44));
		}
	}

	void GXSetViewport(float x, float y, float w, float h, float, float) {
		// cannot set depth bounds
		glViewport(x, y, w, h);
	}

	void GXSetScissor(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
		glScissor(a, b, c, d);
	}

	void GXSetAlphaCompare(GXCompare a, unsigned char b, GXAlphaOp c, GXCompare d, unsigned char e) {
		// basically like glAlphaFunc but with two bounds comparisons and an operator combining these comparisons
		// but has to be implemented in the fragment shader anyway
		gxState.alphacomp.comp0 = a;
		gxState.alphacomp.ref0 = b;
		gxState.alphacomp.op = c;
		gxState.alphacomp.comp1 = d;
		gxState.alphacomp.ref1 = e;
	}

	void GXSetZMode(unsigned char a, GXCompare b, unsigned char c) {
		if (a)
			glEnable(GL_DEPTH);
		else
			glDisable(GL_DEPTH);
		glDepthFunc(GX2GL(b));
		glDepthMask(c);
	}

	void GXEnableTexOffsets(GXTexCoordID coord,
							GXBool line_enable,
							GXBool point_enable) {
		gxState.tgs[coord].line_bias = line_enable;
		gxState.tgs[coord].point_bias = point_enable;
	}

	void GXPokeDstAlpha(GXBool enable, u8 alpha) {
		// supposed to be valid if the EFB has alpha
		// but is the verification done when calling this function, or when poking the efb?
		// unused so unimplemented
		// initialized to disabled
	}

	void GXSetGPMetric(GXPerf0 perf0, GXPerf1 perf1) {
		// unused so unimplemented
		// initialized to disabled
	}

	void GXPokeBlendMode(
		GXBlendMode type,
		GXBlendFactor src_factor,
		GXBlendFactor dst_factor,
		GXLogicOp op) {
		// unused so unimplemented
		// initialized to disabled
	}

	void GXPokeAlphaRead(GXAlphaReadMode mode) {
		// the h*ck is a snap
		// inited to ff and later set to none, allowing alpha reads from the efb
	}

	void GXSetFieldMask(GXBool odd_mask, GXBool even_mask) {
		// unused so unimplemented
	}

	void GXSetFieldMode(GXBool field_mode, GXBool half_aspect_ratio) {
		// unused so unimplemented
	}

	void GXSetScissorBoxOffset(
		s32 xoffset,
		s32 yoffset) {
		// unused so unimplemented
	}

	void GXSetDispCopyFrame2Field(GXCopyMode mode) {
		// unused so unimplemented
	}

	void GXClearBoundingBox() {
		// unused so unimplemented
	}

	void GXPokeDstAlpha(int param_1, ushort param_2) {
		// unused, inited to false, 0
	}

	void GXPokeAlphaRead(GXBool param_1) {
		//write_volatile_2(__peReg + 8, (ushort)(param_1 & 0xfffb | 4));
	}

	void GXPokeDither(GXBool param_1) {
		//unused, init to false
	}

	void GXPokeAlphaMode(
		GXCompare func,
		u8 threshold) {
		// unused but initialized to always
	}

	void GXClearGPMetric(void) {
		// unused so unimplemented
	}

	void GXLoadNrmMtxImm(const mtx::Mtx mtxPtr,
						 u32 id) {
		if (id > 10)
			return;
		memcpy(gxState.norm_mat + id, mtxPtr, sizeof(mtx::Mtx));
	}

	void GXInitLightColor(GXLightObj *param_1, _GXColor param_2) {
		auto ptr = (internal::GXLightObj *)param_1;
		ptr->color = param_2;
	}

	void GXPokeColorUpdate(GXBool) {
		// unused so unimplemented, initialized to true
	}

	void GXPokeAlphaUpdate(GXBool param_1) {
		// unused so unimplemented, initialized to true
	}
	void GXPokeZMode(
		GXBool compare_enable,
		GXCompare func,
		GXBool update_enable) {
		// unused so unimplemented, initialized to true, always, true
	}

	void GXInitFifoLimits(GXFifoObj *param_1, u32 hi_wm, u32 lo_wm) {
		param_1->hi_wm = hi_wm;
		param_1->lo_wm = lo_wm;
	}

	void GXSetColorUpdate(unsigned char c) {
		glColorMask(c, c, c, gxState.aupdate);
		gxState.cupdate = c;
	}

	void GXSetChanMatColor(GXChannelID id, GXColor col) {
		switch (id) {
		case GXChannelID::GX_COLOR0:
			gxState.chans[0].mat_color.r = col.r;
			gxState.chans[0].mat_color.g = col.g;
			gxState.chans[0].mat_color.b = col.b;
			break;
		case GXChannelID::GX_COLOR1:
			gxState.chans[1].mat_color.r = col.r;
			gxState.chans[1].mat_color.g = col.g;
			gxState.chans[1].mat_color.b = col.b;
			break;
		case GXChannelID::GX_ALPHA0:
			gxState.chans[0].mat_color.a = col.a;
			break;
		case GXChannelID::GX_ALPHA1:
			gxState.chans[1].mat_color.a = col.a;
			break;
		case GXChannelID::GX_COLOR0A0:
			gxState.chans[0].mat_color = col;
			break;
		case GXChannelID::GX_COLOR1A1:
			gxState.chans[1].mat_color = col;
			break;
		default:
			break;
		}
	}

	void GXSetTevOp(GXTevStageID id, GXTevMode mode) {
		GXTevColorArg carg = GX_CC_RASC;
		GXTevAlphaArg aarg = GX_CA_RASA;

		if (id != GX_TEVSTAGE0) {
			carg = GX_CC_CPREV;
			aarg = GX_CA_APREV;
		}

		switch (mode) {
		case GX_MODULATE:
			GXSetTevColorIn(id, GX_CC_ZERO, GX_CC_TEXC, carg, GX_CC_ZERO);
			GXSetTevAlphaIn(id, GX_CA_ZERO, GX_CA_TEXA, aarg, GX_CA_ZERO);
			break;
		case GX_DECAL:
			GXSetTevColorIn(id, carg, GX_CC_TEXC, GX_CC_TEXA, GX_CC_ZERO);
			GXSetTevAlphaIn(id, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, aarg);
			break;
		case GX_BLEND:
			GXSetTevColorIn(id, carg, GX_CC_ONE, GX_CC_TEXC, GX_CC_ZERO);
			GXSetTevAlphaIn(id, GX_CA_ZERO, GX_CA_TEXA, aarg, GX_CA_ZERO);
			break;
		case GX_REPLACE:
			GXSetTevColorIn(id, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
			GXSetTevAlphaIn(id, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_TEXA);
			break;
		case GX_PASSCLR:
			GXSetTevColorIn(id, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, carg);
			GXSetTevAlphaIn(id, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, aarg);
			break;
		default:
			break;
		}

		GXSetTevColorOp(id, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1, GX_TEVPREV);
		GXSetTevAlphaOp(id, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1, GX_TEVPREV);
	}

	void GXSetAlphaUpdate(unsigned char a) {
		glColorMask(gxState.cupdate, gxState.cupdate, gxState.cupdate, a);
		gxState.aupdate = a;
	}

	void GXSetCurrentMtx(uint cmtx) {
		gxState.current_mtx = cmtx;
	}

	void GXSetTevColor(GXTevRegID id, GXColor c) {
		gxState.tevs[id].c = c;
	}

	void GXSetTexCoordGen2(GXTexCoordID dst_coord,
						   GXTexGenType func,
						   GXTexGenSrc src_param,
						   u32 mtx,
						   GXBool normalize,
						   u32 postmtx) {
		gxState.tgs[dst_coord].func = func;
		gxState.tgs[dst_coord].src = src_param;
		gxState.tgs[dst_coord].mtxid = mtx;
		gxState.tgs[dst_coord].ptmtx = postmtx;
		gxState.tgs[dst_coord].normalize = normalize;
	}

	void GXSetCullMode(GXCullMode a) {
		switch (a) {
		case GXCullMode::GX_CULL_ALL:
		case GXCullMode::GX_CULL_BACK:
		case GXCullMode::GX_CULL_FRONT:
			glEnable(GL_CULL_FACE);
			break;
		case GXCullMode::GX_CULL_NONE:
			glDisable(GL_CULL_FACE);
			break;
		}

		glCullFace(GX2GL(a));
	}

	void GXSetTevAlphaIn(GXTevStageID id, GXTevAlphaArg a, GXTevAlphaArg b, GXTevAlphaArg c, GXTevAlphaArg d) {
		gxState.tevs[id].a_inputs[0] = a;
		gxState.tevs[id].a_inputs[1] = b;
		gxState.tevs[id].a_inputs[2] = c;
		gxState.tevs[id].a_inputs[3] = d;
	}

	void GXSetTevAlphaOp(GXTevStageID id, GXTevOp op, GXTevBias b, GXTevScale s, unsigned char c, GXTevRegID o) {
		gxState.tevs[id].aop = {
			op, b, s, c, o};
	}

	void GXSetTevColorIn(GXTevStageID id, GXTevColorArg a, GXTevColorArg b, GXTevColorArg c, GXTevColorArg d) {
		gxState.tevs[id].c_inputs[0] = a;
		gxState.tevs[id].c_inputs[1] = b;
		gxState.tevs[id].c_inputs[2] = c;
		gxState.tevs[id].c_inputs[3] = d;
	}

	void GXSetTevColorOp(GXTevStageID id, GXTevOp op, GXTevBias b, GXTevScale s, unsigned char c, GXTevRegID o) {
		gxState.tevs[id].cop = {
			op, b, s, c, o};
	}

	void GXLoadPosMtxImm(const f32 mtx[3][4], u32 id) {
		if (id >= 10)
			return;
		memcpy(gxState.pos_mat[id], mtx, sizeof(f32[3][4]));
	}

	void GXSetDither(unsigned char a) {
		gxState.dither = a;
	}

	void GXSetNumChans(unsigned char a) {
		gxState.colchans = a;
	}

	void GXSetNumTevStages(unsigned char a) {
		gxState.tevstages = a;
	}

	void GXSetNumTexGens(unsigned char a) {
		gxState.texgens = a;
	}

	OSThread *__GXCurrentThread;
	OSThread *GXGetCurrentGXThread() {
		return __GXCurrentThread;
	}

	u16 GXGetNumXfbLines(u16 efbHeight, f32 yscale) {
		uint uVar1;
		uint uVar2;
		uint uVar3;
		uint uVar4;

		uVar2 = ((double)(256.0 / yscale));
		efbHeight = (uint)efbHeight;
		uVar2 = uVar2 & 0x1ff;
		uVar3 = ((efbHeight - 1) * 256) / uVar2;
		uVar4 = uVar3 + 1;
		if ((128 < uVar2) && (uVar2 < 256)) {
			for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1) {
			}
			if (efbHeight == (efbHeight / uVar2) * uVar2) {
				uVar4 = uVar3 + 2;
			}
		}
		if (1024 < uVar4) {
			uVar4 = 1024;
		}
		return uVar4;
	}

	GXFifoObj *GXInit(void *buffer, unsigned int size) {
		static bool isinit = false;
		if (isinit)
			return 0;
		isinit = true;
		glewExperimental = GL_TRUE;
		auto e = glewInit();
		if (e != GLEW_OK) {
			puts((char *)glewGetErrorString(e));
			abort();
		}
		glGetError();
		glEnable(GL_DEBUG_OUTPUT);
		glDebugMessageCallback(MessageCallback, 0);

		GXSetTexCoordGen(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY);
		GXSetTexCoordGen(GX_TEXCOORD1, GX_TG_MTX2x4, GX_TG_TEX1, GX_IDENTITY);
		GXSetTexCoordGen(GX_TEXCOORD2, GX_TG_MTX2x4, GX_TG_TEX2, GX_IDENTITY);
		GXSetTexCoordGen(GX_TEXCOORD3, GX_TG_MTX2x4, GX_TG_TEX3, GX_IDENTITY);
		GXSetTexCoordGen(GX_TEXCOORD4, GX_TG_MTX2x4, GX_TG_TEX4, GX_IDENTITY);
		GXSetTexCoordGen(GX_TEXCOORD5, GX_TG_MTX2x4, GX_TG_TEX5, GX_IDENTITY);
		GXSetTexCoordGen(GX_TEXCOORD6, GX_TG_MTX2x4, GX_TG_TEX6, GX_IDENTITY);
		GXSetTexCoordGen(GX_TEXCOORD7, GX_TG_MTX2x4, GX_TG_TEX7, GX_IDENTITY);

		GXSetNumTexGens(1);
		GXClearVtxDesc();
		GXInvalidateVtxCache();

		GXSetLineWidth(6, GX_TO_ZERO);
		GXSetPointSize(6, GX_TO_ZERO);
		GXEnableTexOffsets(GX_TEXCOORD0, GX_DISABLE, GX_DISABLE);
		GXEnableTexOffsets(GX_TEXCOORD1, GX_DISABLE, GX_DISABLE);
		GXEnableTexOffsets(GX_TEXCOORD2, GX_DISABLE, GX_DISABLE);
		GXEnableTexOffsets(GX_TEXCOORD3, GX_DISABLE, GX_DISABLE);
		GXEnableTexOffsets(GX_TEXCOORD4, GX_DISABLE, GX_DISABLE);
		GXEnableTexOffsets(GX_TEXCOORD5, GX_DISABLE, GX_DISABLE);
		GXEnableTexOffsets(GX_TEXCOORD6, GX_DISABLE, GX_DISABLE);
		GXEnableTexOffsets(GX_TEXCOORD7, GX_DISABLE, GX_DISABLE);

		mtx::Mtx44 identity_mtx;
		mtx::MTXIdentity(identity_mtx);
		GXLoadPosMtxImm(identity_mtx, GX_PNMTX0);
		GXLoadNrmMtxImm(identity_mtx, GX_PNMTX0);
		GXSetCurrentMtx(GX_PNMTX0);
		GXLoadTexMtxImm(identity_mtx, GX_IDENTITY, GX_MTX3x4);
		GXLoadTexMtxImm(identity_mtx, GX_PTIDENTITY, GX_MTX3x4);
		auto rmode = &::GXNtsc480Prog;
		GXSetViewport(0.0F,						// left
					  0.0F,						// top
					  (float)rmode->fbWidth,	// width
					  (float)rmode->xfbHeight,	// height
					  0.0F,						// nearz
					  1.0F);					// farz

		GXSetCoPlanar(GX_DISABLE);
		GXSetCullMode(GX_CULL_BACK);
		GXSetClipMode(GX_CLIP_ENABLE);
		GXSetScissor(0, 0, (u32)rmode->fbWidth, (u32)rmode->efbHeight);
		GXSetScissorBoxOffset(0, 0);

		GXSetNumChans(0);  // no colors by default

		GXSetChanCtrl(
			GX_COLOR0A0,
			GX_DISABLE,
			GX_SRC_REG,
			GX_SRC_VTX,
			GX_LIGHT_NULL,
			GX_DF_NONE,
			GX_AF_NONE);

		GXColor BLACK = {0, 0, 0, 0};
		GXColor WHITE = {0xff, 0xff, 0xff, 0xff};
		GXSetChanAmbColor(GX_COLOR0A0, BLACK);
		GXSetChanMatColor(GX_COLOR0A0, WHITE);

		GXSetChanCtrl(
			GX_COLOR1A1,
			GX_DISABLE,
			GX_SRC_REG,
			GX_SRC_VTX,
			GX_LIGHT_NULL,
			GX_DF_NONE,
			GX_AF_NONE);

		GXSetChanAmbColor(GX_COLOR1A1, BLACK);
		GXSetChanMatColor(GX_COLOR1A1, WHITE);
		GXInvalidateTexAll();

		// TODO: allocate TLUT memory

		//GXSetTexRegionCallback(__GXDefaultTexRegionCallback);
		//GXSetTlutRegionCallback(__GXDefaultTlutRegionCallback);

		GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
		GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR0A0);
		GXSetTevOrder(GX_TEVSTAGE2, GX_TEXCOORD2, GX_TEXMAP2, GX_COLOR0A0);
		GXSetTevOrder(GX_TEVSTAGE3, GX_TEXCOORD3, GX_TEXMAP3, GX_COLOR0A0);
		GXSetTevOrder(GX_TEVSTAGE4, GX_TEXCOORD4, GX_TEXMAP4, GX_COLOR0A0);
		GXSetTevOrder(GX_TEVSTAGE5, GX_TEXCOORD5, GX_TEXMAP5, GX_COLOR0A0);
		GXSetTevOrder(GX_TEVSTAGE6, GX_TEXCOORD6, GX_TEXMAP6, GX_COLOR0A0);
		GXSetTevOrder(GX_TEVSTAGE7, GX_TEXCOORD7, GX_TEXMAP7, GX_COLOR0A0);
		GXSetTevOrder(GX_TEVSTAGE8, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
		GXSetTevOrder(GX_TEVSTAGE9, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
		GXSetTevOrder(GX_TEVSTAGE10, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
		GXSetTevOrder(GX_TEVSTAGE11, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
		GXSetTevOrder(GX_TEVSTAGE12, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
		GXSetTevOrder(GX_TEVSTAGE13, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
		GXSetTevOrder(GX_TEVSTAGE14, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
		GXSetTevOrder(GX_TEVSTAGE15, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);

		GXSetNumTevStages(1);
		GXSetTevOp(GX_TEVSTAGE0, GX_REPLACE);
		GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_AND, GX_ALWAYS, 0);
		GXSetZTexture(GX_ZT_DISABLE, GX_TF_Z8, 0);

		for (int i = GX_TEVSTAGE0; i < GX_MAX_TEVSTAGE; i++) {
			GXSetTevKColorSel((GXTevStageID)i, GX_TEV_KCSEL_1_4);
			GXSetTevKAlphaSel((GXTevStageID)i, GX_TEV_KASEL_1);
			GXSetTevSwapMode((GXTevStageID)i, GX_TEV_SWAP0, GX_TEV_SWAP0);
		}

		GXSetTevSwapModeTable(GX_TEV_SWAP0,
							  GX_CH_RED, GX_CH_GREEN, GX_CH_BLUE, GX_CH_ALPHA);
		GXSetTevSwapModeTable(GX_TEV_SWAP1,
							  GX_CH_RED, GX_CH_RED, GX_CH_RED, GX_CH_ALPHA);
		GXSetTevSwapModeTable(GX_TEV_SWAP2,
							  GX_CH_GREEN, GX_CH_GREEN, GX_CH_GREEN, GX_CH_ALPHA);
		GXSetTevSwapModeTable(GX_TEV_SWAP3,
							  GX_CH_BLUE, GX_CH_BLUE, GX_CH_BLUE, GX_CH_ALPHA);

		for (int i = GX_TEVSTAGE0; i < GX_MAX_TEVSTAGE; i++) {
			GXSetTevDirect((GXTevStageID)i);
		}
		GXSetNumIndStages(0);
		GXSetIndTexCoordScale(GX_INDTEXSTAGE0, GX_ITS_1, GX_ITS_1);
		GXSetIndTexCoordScale(GX_INDTEXSTAGE1, GX_ITS_1, GX_ITS_1);
		GXSetIndTexCoordScale(GX_INDTEXSTAGE2, GX_ITS_1, GX_ITS_1);
		GXSetIndTexCoordScale(GX_INDTEXSTAGE3, GX_ITS_1, GX_ITS_1);

		GXSetFog(GX_FOG_NONE, 0.0F, 1.0F, 0.1F, 1.0F, BLACK);
		GXSetFogRangeAdj(GX_DISABLE, 0, 0);
		GXSetBlendMode(GX_BM_NONE,
					   GX_BL_SRCALPHA,	   // src factor
					   GX_BL_INVSRCALPHA,  // dst factor
					   GX_LO_CLEAR);
		GXSetColorUpdate(GX_ENABLE);
		GXSetAlphaUpdate(GX_ENABLE);
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
		GXSetZCompLoc(GX_TRUE);	 // before texture
		GXSetDither(GX_ENABLE);
		GXSetDstAlpha(GX_DISABLE, 0);
		GXSetPixelFmt(GX_PF_RGB8_Z24, GX_ZC_LINEAR);
		GXSetFieldMask(GX_ENABLE, GX_ENABLE);
		GXSetFieldMode(false, GX_DISABLE);

		GXSetCopyClear(BLACK, GX_MAX_Z24);
		GXSetDispCopySrc(0, 0, rmode->fbWidth, rmode->efbHeight);
		GXSetDispCopyDst(rmode->fbWidth, rmode->efbHeight);
		GXSetDispCopyYScale((f32)(rmode->xfbHeight) / (f32)(rmode->efbHeight));
		GXSetCopyClamp((GXFBClamp)(GX_CLAMP_TOP | GX_CLAMP_BOTTOM));
		GXSetCopyFilter(rmode->aa, rmode->sample_pattern, GX_TRUE, rmode->vfilter);
		GXSetDispCopyGamma(GX_GM_1_0);
		GXSetDispCopyFrame2Field(GX_COPY_PROGRESSIVE);
		GXClearBoundingBox();

		GXPokeColorUpdate(GX_TRUE);
		GXPokeAlphaUpdate(GX_TRUE);
		GXPokeDither(GX_FALSE);
		GXPokeBlendMode(GX_BM_NONE, GX_BL_ZERO, GX_BL_ONE, GX_LO_SET);
		GXPokeAlphaMode(GX_ALWAYS, 0);
		GXPokeAlphaRead(GX_READ_FF);
		GXPokeDstAlpha(GX_DISABLE, 0);
		GXPokeZMode(GX_TRUE, GX_ALWAYS, GX_TRUE);

		GXSetGPMetric(GX_PERF0_NONE, GX_PERF1_NONE);
		GXClearGPMetric();

		return nullptr;
	}

	OSThread *GXSetCurrentGXThread() {
		bool bVar1;

		bVar1 = (bool)os::OSDisableInterrupts();
		auto uVar1 = __GXCurrentThread;
		__GXCurrentThread = os::OSGetCurrentThread();
		os::OSRestoreInterrupts(bVar1);
		return uVar1;
	}

	u32 GXSetDispCopyYScale(float) { return 480; }

	float GXGetYScaleFactor(unsigned short a, unsigned short b) {
		return (f32)a / (f32)b;	 // not my problem
	}

	using CB = void();
	CB *DrawDone;

	CB *GXSetDrawDoneCallback(CB *n) {
		CB *o = DrawDone;
		DrawDone = n;
		return o;
	}

	void GXInitTexObjCI(
		GXTexObj *obj,
		void *image_ptr,
		u16 width,
		u16 height,
		GXCITexFmt format,
		GXTexWrapMode wrap_s,
		GXTexWrapMode wrap_t,
		GXBool mipmap,
		u32 tlut_name) {
	}

	void GXInitTlutObj(
		GXTlutObj *tlut_obj,
		void *lut,
		GXTlutFmt fmt,
		u16 n_entries) {
	}

	void GXSetTevKColorSel(GXTevStageID stage, GXTevKColorSel sel) {
		gxState.tevs[stage].ksel = sel;
	}

	void GXSetTevKAlphaSel(GXTevStageID stage, GXTevKAlphaSel sel) {
		gxState.tevs[stage].kasel = sel;
	}

#define GXCDEC1(func, ts, td) \
	void func(const ts x)

#define GXCDEC2(func, ts, td) \
	void func(const ts x, const ts y)

#define GXCDEC3(func, ts, td) \
	void func(const ts x, const ts y, const ts z)

#define __GXCDEC4(func, ts, td) \
	void func(const ts x, const ts y, const ts z, const ts w)

#define GXCDEC(prfx, n, t) GXCDEC##n(prfx##n##t, t, t)

	GXCDEC(GXPosition, 2, s16) {
		//puts("pos2s16");
	}

	GXCDEC(GXPosition, 3, s16) {
		//puts("pos3s16");
	}

	GXCDEC(GXPosition, 3, f32) {
		//puts("pos3f32");
	}

	GXCDEC(GXTexCoord, 2, u8) {
		//puts("coord2u8");
	}

	GXCDEC(GXTexCoord, 2, u16) {
		//puts("coord2u16");
	}

	GXCDEC(GXTexCoord, 2, f32) {
		//puts("coord2f32");
	}

	GXCDEC(GXColor, 1, u32) {
		//puts("col1u32");
	}
}