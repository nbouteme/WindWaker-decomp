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
	struct TevState {
		int ksel;
		int kasel;
		GXColor c;

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
	};
	struct TexGenState {
		GXTexGenType func;
		GXTexGenSrc src;
		u32 mtxid;
		bool normalize;
		u32 ptmtx;
	};

	// represent the entire pipeline state, will be passed in a shader storage object on each drawcall
	// update is delayed to drawing commands or flushing
	struct {
		TevState tevs[8];
		TexGenState tgs[8];

		int texgens;
		int tevstages;
		int colchans;
		int dither;

		float point_sprite_uv_bias;
		uint current_mtx;
		mtx::Mtx norm_mat[10];
		mtx::Mtx pos_mat[10];
	} gxState;

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
		}
	}

	void GXEnableTexOffsets(GXTexCoordID coord,
							GXBool line_enable,
							GXBool point_enable) {
		//
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
		ushort a = param_2 & 0xff | (ushort)(param_1 << 8);
		//write_volatile_2(__peReg + 4, (ushort)(param_1 & 0xfffb | 4));
	}

	void GXPokeAlphaRead(GXBool param_1) {
		//write_volatile_2(__peReg + 8, (ushort)(param_1 & 0xfffb | 4));
	}

	void GXPokeDither(GXBool param_1) {
		//unused, init to false
	}

	void GXPokeAlphaMode(int param_1, ushort param_2) {
		//write_volatile_2(__peReg + 6, (ushort)(param_1 << 8) | param_2);
	}

	void GXPokeAlphaMode(
		GXCompare func,
		u8 threshold) {
		// unused but initialized to always
	}

	void GXClearGPMetric(void) {
		// unused so unimplemented
	}

	void *GXGetTexObjData(GXTexObj *param_1) {
		return 0;

		//return (param_1->dummy[3] & 0x1fffff) << 5;
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
		return;
	}

	void GXInitFifoBase(gx::GXFifoObj *, void *, unsigned int) {}

	void GXInitFifoPtrs(gx::GXFifoObj *, void *, void *) {}

	void GXInvalidateTexAll() {}

	void GXPeekZ(unsigned short, unsigned short, unsigned int *) {
		// glReadPixels?
	}

	void GXPixModeSync() {}
	void GXSaveCPUFifo(gx::GXFifoObj *) {}
	void GXSetColorUpdate(unsigned char) {}
	void GXSetCopyClamp(gx::_GXFBClamp) {}
	void GXSetCopyClear(gx::_GXColor, unsigned int) {}
	void GXSetCopyFilter(unsigned char, unsigned char const (*)[2], unsigned char, unsigned char const *) {}
	void GXSetDispCopyDst(unsigned short, unsigned short) {}
	void GXSetDispCopyGamma(gx::_GXGamma) {}
	void GXSetDispCopySrc(unsigned short, unsigned short, unsigned short, unsigned short) {}
	void GXSetFog(gx::_GXFogType, float, float, float, float, gx::_GXColor) {}
	void GXSetFogRangeAdj(unsigned char, unsigned short, gx::_GXFogAdjTable const *) {}
	void GXSetIndTexCoordScale(gx::_GXIndTexStageID, gx::_GXIndTexScale, gx::_GXIndTexScale) {}
	void GXSetIndTexMtx(gx::_GXIndTexMtxID, float const (*)[3], char) {}
	void GXSetMisc(gx::_GXMiscToken, unsigned int) {}
	void GXSetTevColorS10(gx::_GXTevRegID, gx::_GXColorS10) {}
	void GXSetTevDirect(gx::_GXTevStageID) {}
	void GXSetTevIndirect(gx::_GXTevStageID, gx::_GXIndTexStageID, gx::_GXIndTexFormat, gx::_GXIndTexBiasSel, gx::_GXIndTexMtxID, gx::_GXIndTexWrap, gx::_GXIndTexWrap, unsigned char, unsigned char, gx::_GXIndTexAlphaSel) {}
	void GXSetTevKColor(gx::_GXTevKColorID, gx::_GXColor) {}
	void GXSetTevSwapMode(gx::_GXTevStageID, gx::_GXTevSwapSel, gx::_GXTevSwapSel) {}
	void GXAbortFrame() {}
	void GXGetGPStatus(unsigned char *, unsigned char *, unsigned char *, unsigned char *, unsigned char *) {}
	void GXInitTexObjLOD(gx::_GXTexObj *, gx::_GXTexFilter, gx::_GXTexFilter, float, float, float, unsigned char, unsigned char, gx::_GXAnisotropy) {}
	void GXInvalidateVtxCache() {}
	void GXLoadTexMtxImm(float const (*)[4], unsigned int, gx::_GXTexMtxType) {}
	void GXReadXfRasMetric(unsigned int *, unsigned int *, unsigned int *, unsigned int *) {}
	void GXSetChanMatColor(gx::_GXChannelID, gx::_GXColor) {}
	void GXSetClipMode(gx::_GXClipMode) {
	}
	void GXSetCoPlanar(unsigned char) {}
	void GXSetDrawDone() {}
	void GXSetDstAlpha(unsigned char, unsigned char) {}
	void GXSetLineWidth(unsigned char, gx::_GXTexOffset) {}
	void GXSetNumIndStages(unsigned char) {}
	void GXSetProjection(float const (*)[4], gx::_GXProjectionType) {}
	void GXSetTevOp(gx::_GXTevStageID id, gx::_GXTevMode mode) {
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

	void GXSetViewport(float, float, float, float, float, float) {}
	void GXCopyDisp(void *, unsigned char) {}
	void GXInitTexObj(gx::_GXTexObj *, void *, unsigned short, unsigned short, gx::_GXTexFmt, gx::_GXTexWrapMode, gx::_GXTexWrapMode, unsigned char) {}

	void GXSetAlphaUpdate(unsigned char) {}

	void GXSetCurrentMtx(uint cmtx) {
		gxState.current_mtx = cmtx;
	}

	void GXSetPixelFmt(gx::_GXPixelFmt, gx::_GXZFmt16) {}

	void GXSetScissor(unsigned int, unsigned int, unsigned int, unsigned int) {}

	void GXSetTevColor(gx::_GXTevRegID id, gx::_GXColor c) {
		gxState.tevs[id].c = c;
	}

	void GXSetTexCoordGen2(GXTexCoordID dst_coord,
						   GXTexGenType func,
						   GXTexGenSrc src_param,
						   u32 mtx,
						   GXBool normalize,
						   u32 postmtx) {
		gxState.tgs[dst_coord] = {
			func,
			src_param,
			mtx,
			!!normalize,
			postmtx};
	}

	void GXSetZTexture(gx::_GXZTexOp, gx::_GXTexFmt, unsigned int) {}
	void GXBegin(gx::_GXPrimitive, gx::_GXVtxFmt, unsigned short) {}
	void GXClearVtxDesc() {}

	void GXDrawDone() {
	}

	void GXSetChanAmbColor(GXChannelID chan, GXColor amb_color) {}
	void GXSetIndTexOrder(GXIndTexStageID ind_stage, GXTexCoordID tex_coord,
						  GXTexMapID tex_map) {}

	void GXSetAlphaCompare(gx::_GXCompare, unsigned char, gx::_GXAlphaOp, gx::_GXCompare, unsigned char) {
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

		switch (a) {
		case GXCullMode::GX_CULL_ALL:
			glCullFace(GL_FRONT_AND_BACK);
			break;
		case GXCullMode::GX_CULL_BACK:
			glCullFace(GL_BACK);
			break;
		case GXCullMode::GX_CULL_FRONT:
			glCullFace(GL_FRONT);
			break;

		default:
			break;
		}
	}

	void GXSetTevAlphaIn(gx::_GXTevStageID id, gx::_GXTevAlphaArg a, gx::_GXTevAlphaArg b, gx::_GXTevAlphaArg c, gx::_GXTevAlphaArg d) {
		gxState.tevs[id].a_inputs[0] = a;
		gxState.tevs[id].a_inputs[1] = b;
		gxState.tevs[id].a_inputs[2] = c;
		gxState.tevs[id].a_inputs[3] = d;
	}

	void GXSetTevAlphaOp(gx::_GXTevStageID id, gx::_GXTevOp op, gx::_GXTevBias b, gx::_GXTevScale s, unsigned char c, gx::_GXTevRegID o) {
		gxState.tevs[id].aop = {
			op, b, s, c, o};
	}

	void GXSetTevColorIn(gx::_GXTevStageID id, gx::_GXTevColorArg a, gx::_GXTevColorArg b, gx::_GXTevColorArg c, gx::_GXTevColorArg d) {
		gxState.tevs[id].c_inputs[0] = a;
		gxState.tevs[id].c_inputs[1] = b;
		gxState.tevs[id].c_inputs[2] = c;
		gxState.tevs[id].c_inputs[3] = d;
	}

	void GXSetTevColorOp(gx::_GXTevStageID id, gx::_GXTevOp op, gx::_GXTevBias b, gx::_GXTevScale s, unsigned char c, gx::_GXTevRegID o) {
		gxState.tevs[id].cop = {
			op, b, s, c, o};
	}

	void GXSetTevSwapModeTable(gx::_GXTevSwapSel, gx::_GXTevColorChan, gx::_GXTevColorChan, gx::_GXTevColorChan, gx::_GXTevColorChan) {}

	// correct implementation required for the fake sea waves billboards to render properly
	void GXSetZCompLoc(GXBool) {
		// the opengl extension for this forbids writing to gl_fragdepth but it shouldnt be an issue?
		// early z test?
	}

	void GXLoadPosMtxImm(const f32 mtx[3][4], u32 id) {
		if (id >= 10)
			return;
		memcpy(gxState.pos_mat[id], mtx, sizeof(mtx));
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

	void GXSetZMode(unsigned char, gx::_GXCompare, unsigned char) {}
	void GXFlush() {}
	void GXLoadTexObj(gx::_GXTexObj const *, gx::_GXTexMapID) {}
	void GXSetBlendMode(gx::_GXBlendMode, gx::_GXBlendFactor, gx::_GXBlendFactor, gx::_GXLogicOp) {}
	void GXSetChanCtrl(gx::_GXChannelID, unsigned char, gx::_GXColorSrc, gx::_GXColorSrc, unsigned int, gx::_GXDiffuseFn, gx::_GXAttnFn) {}
	void GXSetTevOrder(gx::_GXTevStageID, gx::_GXTexCoordID, gx::_GXTexMapID, gx::_GXChannelID) {}
	void GXSetVtxDesc(gx::_GXAttr, gx::_GXAttrType) {}
	void GXSetVtxAttrFmt(gx::_GXVtxFmt, gx::_GXAttr, gx::_GXCompCnt, gx::_GXCompType, unsigned char) {}

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
		GXSetViewport(0.0F,	 // left
					  0.0F,	 // top
					  //(float)rmode->fbWidth,	// width
					  //(float)rmode->xfbHeight,	// height
					  640.0f,  // width
					  528.0f,  // height
					  0.0F,	   // nearz
					  1.0F);   // farz

		GXSetCoPlanar(GX_DISABLE);
		GXSetCullMode(GX_CULL_BACK);
		GXSetClipMode(GX_CLIP_ENABLE);
		//GXSetScissor(0, 0, (u32)rmode->fbWidth, (u32)rmode->efbHeight);
		GXSetScissor(0, 0, 640, 528);
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

		auto rmode = &::GXNtsc480Prog;
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

	u32 GXGetTexBufferSize(unsigned short, unsigned short, unsigned int, unsigned char, unsigned char) { return 0; }

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

	void GXLoadTlut(const GXTlutObj *tlut_obj, u32 tlut_name) {}

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