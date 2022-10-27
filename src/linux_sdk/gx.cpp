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
	struct rgb5a3_texel {
		union {
			struct {
				u8 sel0 : 1;
				u8 a3 : 3;
				u8 r4 : 4;
				u8 g4 : 4;
				u8 b4 : 4;
			};
			struct {
				u8 sel1 : 1;
				u8 r5 : 5;
				u8 g5 : 5;
				u8 b5 : 5;
			};
			u16 internal;
		};
	};

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
		default:
			return -1;
		}
	}

	int GX2GL(GXPrimitive p) {
		switch (p) {
		case GXPrimitive::GX_LINES:
			return GL_LINES;
		case GXPrimitive::GX_LINESTRIP:
			return GL_LINE_STRIP;
		case GXPrimitive::GX_POINTS:
			return GL_POINTS;
		case GXPrimitive::GX_QUADS:	 // quads aren't supported anymore, so they'll be manually converted into tristrips
		case GXPrimitive::GX_TRIANGLESTRIP:
			return GL_TRIANGLE_STRIP;
		case GXPrimitive::GX_TRIANGLES:
			return GL_TRIANGLES;
		case GXPrimitive::GX_TRIANGLEFAN:
			return GL_TRIANGLE_FAN;
		default:
			return -1;
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
		default:
			return -1;
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
		default:
			return -1;
		}
	}

	int GX2GL(GXTexFmt Oxf) {
		// TODO: handle depth texture formats
		switch (Oxf & 0xf) {
		case GXTexFmt::GX_TF_I4:
			return GL_LUMINANCE4;
		case GXTexFmt::GX_TF_I8:
			return GL_LUMINANCE8;  // GL_UNSIGNED_BYTE
		case GXTexFmt::GX_TF_IA4:
			return GL_LUMINANCE4_ALPHA4;  // GL_UNSIGNED_BYTE
		case GXTexFmt::GX_TF_IA8:
			return GL_LUMINANCE8_ALPHA8;
		case GXTexFmt::GX_TF_RGB565:
			return GL_RGB565;  // GL_UNSIGNED_SHORT
		case GXTexFmt::GX_TF_RGB5A3:
			return GL_RGBA8UI;
		case GXTexFmt::GX_TF_RGBA8:
			return GL_RGBA8UI;
		case GXTexFmt::GX_TF_CMPR:
			return GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
		default:
			return -1;
		}
	}

	int GX2PType(GXTexFmt Oxf) {
		// TODO: handle depth texture formats
		switch (Oxf & 0xf) {
		case GXTexFmt::GX_TF_I4:
			return GL_UNSIGNED_BYTE;  // unsure
		case GXTexFmt::GX_TF_I8:
			return GL_UNSIGNED_BYTE;
		case GXTexFmt::GX_TF_IA4:
			return GL_UNSIGNED_BYTE;  // unsure
		case GXTexFmt::GX_TF_IA8:
			return GL_LUMINANCE8_ALPHA8;
		case GXTexFmt::GX_TF_RGB565:
			return GL_UNSIGNED_SHORT;  // unsure
		case GXTexFmt::GX_TF_RGB5A3:
			return GL_RGBA8UI;
		case GXTexFmt::GX_TF_RGBA8:
			return GL_RGBA8UI;
		default:
			return -1;
		}
	}
	int GX2Format(GXTexFmt Oxf) {
		// TODO: handle depth texture formats
		switch (Oxf & 0xf) {
		case GXTexFmt::GX_TF_I4:
			return GL_RED;	// unsure
		case GXTexFmt::GX_TF_I8:
			return GL_RED;
		case GXTexFmt::GX_TF_IA4:
			return GL_RG;  // unsure
		case GXTexFmt::GX_TF_IA8:
			return GL_RG;
		case GXTexFmt::GX_TF_RGB565:
			return GL_RGB;	// unsure
		case GXTexFmt::GX_TF_RGB5A3:
			return GL_RGBA;
		case GXTexFmt::GX_TF_RGBA8:
			return GL_RGBA;
		default:
			return -1;
		}
	}

	int GX2GL(GXTexWrapMode m) {
		switch (m) {
		case GXTexWrapMode::GX_CLAMP:
			return GL_CLAMP;
		case GXTexWrapMode::GX_MIRROR:
			return GL_MIRRORED_REPEAT;
		case GXTexWrapMode::GX_REPEAT:
			return GL_REPEAT;
		default:
			return -1;
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

		struct {
			int count;
			int type;
		} vat[8][GX_VA_MAX_ATTR];

		GXAttrType vdesc[GX_VA_MAX_ATTR];

		int currentVat;
		int currentPType;
		int currentExpectedVtxCnt;
		int currentSpecifiedPosCnt;
		int pendingDraw;

		uint vbo;
		void *vbuff;
		u64 writeOffset;
		int ubershader;
		uint gxubo;
		int gxubosize;
		void *ubuff;

		GXTlutRegionCallback regioncb;

		gx::GXTlutRegion small[16];
		gx::GXTlutRegion big[4];

		template <typename T>
		void write(T data) {
			memcpy(((char *)vbuff) + writeOffset, &data, sizeof(T));
			writeOffset += writeOffset;
		}

		void init() {
			glGenBuffers(1, &vbo);

			// allocate 4MB, expect to only write 1mb at most at once
			glNamedBufferStorage(vbo,
								 4 * 1024 * 1024,
								 nullptr,
								 GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT);
			vbuff = glMapNamedBuffer(vbo, GL_MAP_INVALIDATE_BUFFER_BIT | GL_MAP_FLUSH_EXPLICIT_BIT);
			glGenVertexArrays(1, &vao);

			ubershader = buildUbershader();
			GLuint blockIndex = glGetUniformBlockIndex(ubershader, "gxState");
			glGenBuffers(1, &gxubo);
			glBindBuffer(GL_UNIFORM_BUFFER, gxubo);

			glGetActiveUniformBlockiv(ubershader, blockIndex, GL_UNIFORM_BLOCK_DATA_SIZE, &gxubosize);

			glNamedBufferStorage(gxubo,
								 gxubosize,
								 nullptr,
								 GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT);
			ubuff = glMapNamedBuffer(vbo, GL_MAP_INVALIDATE_BUFFER_BIT | GL_MAP_FLUSH_EXPLICIT_BIT);
		}

		void updateGX() {
			memcpy(ubuff, &gxState, gxubosize);
			// use buffers for indexing matrices?
			glFlushMappedNamedBufferRange(gxubo, 0, gxubosize);
			glFlushMappedNamedBufferRange(vbo, 0, writeOffset);
			glUseProgram(ubershader);
		}

	} glState;

	byte *__peReg;

	void GXBegin(GXPrimitive a, GXVtxFmt b, unsigned short c) {
		if (glState.pendingDraw)
			GXFlush();
		glState.currentVat = a;
		glState.currentPType = b;
		glState.currentExpectedVtxCnt = c;
		glState.currentSpecifiedPosCnt = 0;
		glState.pendingDraw = 1;
	}

	void GXInitTexObjLOD(GXTexObj *, GXTexFilter, GXTexFilter, float, float, float, unsigned char, unsigned char, GXAnisotropy) {}

	void GXInitTexObj(GXTexObj *obj, void *data, u16 w, u16 h, GXTexFmt f, GXTexWrapMode ws, GXTexWrapMode wt, GXBool mm) {
		if (!obj->tid)
			glGenTextures(1, &obj->tid);
		obj->data = data;
		glTextureParameteri(obj->tid, GL_TEXTURE_WRAP_S, GX2GL(ws));
		glTextureParameteri(obj->tid, GL_TEXTURE_WRAP_T, GX2GL(wt));
		glTextureParameteri(obj->tid, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTextureParameteri(obj->tid, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTextureStorage2D(obj->tid,
						   4,
						   GX2GL(f),
						   w, h);

		if (f & 0xf == GXTexFmt::GX_TF_CMPR) {
			glCompressedTextureSubImage2D(obj->tid, 0, 0, 0, w, h, GL_COMPRESSED_RGBA_S3TC_DXT1_EXT, w * h / 2 /*Compression ratio for DXT1*/, data);
		} else {
			void *dp = data;
			if (f & 0xf == GXTexFmt::GX_TF_RGB5A3) {
				dp = recodeRGB5A3(data, w, h);
			}
			glTextureSubImage2D(obj->tid,
								0,
								0, 0,
								w, h,
								GX2Format(f),
								GX2PType(f),
								data);
		}

		if (mm)	 // ignore the mip map in the texture and generates our own
			glGenerateTextureMipmap(obj->tid);
	}

	void GXLoadTexObj(GXTexObj const *obj, GXTexMapID id) {
		glActiveTexture(id);
		glBindTexture(GL_TEXTURE_2D, obj->tid);
	}

	void GXInitTlutObj(
		GXTlutObj *tlut_obj,
		void *lut,
		GXTlutFmt fmt,
		u16 n_entries) {
		tlut_obj->lut = lut;
		tlut_obj->n_entries = n_entries;
		tlut_obj->fmt = fmt;
	}

	void GXInitTlutRegion(
		GXTlutRegion *region,
		u32 tmem_addr,
		GXTlutSize tlut_size) {
		if (!region->tlutid)
			glGenTextures(1, &region->tlutid);
		glTextureParameteri(region->tlutid, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTextureParameteri(region->tlutid, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureStorage1D(region->tlutid, 0,
						   GL_RGBA8UI,
						   tlut_size * 16);
	}

	u32 GXGetTexBufferSize(u16 w, u16 h, u32 f, GXBool m, u8 ml) {
		int iVar1;
		int iVar3;
		int iVar5;
		int iVar6;
		uint uVar7;

		switch (f) {
		case GX_TF_I4:
		case 8:
		case GX_TF_CMPR:
		case GX_CTF_R4:
		case GX_CTF_Z4:
			iVar1 = 3;
			iVar5 = 3;
			break;
		case GX_TF_I8:
		case GX_TF_IA4:
		case 9:
		case GX_TF_Z8:
		case GX_CTF_RA4:
		case GX_CTF_A8:
		case GX_CTF_R8:
		case GX_CTF_G8:
		case GX_CTF_B8:
		case GX_CTF_Z8M:
		case GX_CTF_Z8L:
			iVar1 = 3;
			iVar5 = 2;
			break;
		case GX_TF_IA8:
		case GX_TF_RGB565:
		case GX_TF_RGB5A3:
		case GX_TF_RGBA8:
		case 10:
		case GX_TF_Z16:
		case GX_TF_Z24X8:
		case GX_CTF_RA8:
		case GX_CTF_RG8:
		case GX_CTF_GB8:
		case GX_CTF_Z16L:
			iVar1 = 2;
			iVar5 = 2;
			break;
		default:
			iVar5 = 0;
			iVar1 = 0;
		}
		if ((f == GX_TF_RGBA8) || (f == GX_TF_Z24X8)) {
			iVar3 = 0x40; // size of a 4x4 block?
		} else {
			iVar3 = 0x20; // size of a 4x4 block?
		}
		if (m) {
			iVar6 = 0;
			while ((ml &&
					((iVar6 = iVar6 + iVar3 * ((int)(w + (1 << iVar1) + -1) >> iVar1) *
										  ((int)(h + (1 << iVar5) + -1) >> iVar5),
					  w != 1 ||
						  (h != 1))))) {
				if (w < 2) {
					w = 1;
				} else {
					w = (int)w >> 1;
				}
				if (h < 2) {
					h = 1;
				} else {
					h = (int)h >> 1;
				}
				ml--;
			}
		} else {
			iVar6 = iVar3 * ((int)((uint)w + (1 << iVar1) + -1) >> iVar1) *
					((int)((uint)h + (1 << iVar5) + -1) >> iVar5);
		}
		return iVar6;
	}

	GXTlutRegionCallback GXSetTlutRegionCallback(GXTlutRegionCallback f) {
		auto o = glState.regioncb;
		glState.regioncb = f;
		return o;
	}

	void GXLoadTlut(const GXTlutObj *tlut_obj, u32 tlut_name) {
		auto reg = glState.regioncb(tlut_name);
		glActiveTexture(GL_TEXTURE0 + 8);  // use that as the palette texture, shouldn't conflict
		glTextureSubImage1D(reg->tlutid, 0, 0, tlut_obj->n_entries, GL_RGBA, GL_UNSIGNED_BYTE, decodePalette(tlut_obj));
		glBindTexture(GL_TEXTURE_1D, reg->tlutid);
	}

	void GXClearVtxDesc() {
		memset(glState.vat, 0, sizeof(glState.vat));
	}

	void GXDrawDone() {
	}

	void *GXGetTexObjData(GXTexObj *param_1) {
		return param_1->data;
	}

	void GXSetVtxDesc(GXAttr a, GXAttrType t) {
		/*
			Basically used to describe if an attribute
			is refered directly through the attribute pointer
			or indirectly through an 8 or 16 bit index
			however opengl doesn't give that kind of control
			on a per-attribute basis, only when issuing drawing commands
			and entire vertices are indexed

			Dolphin's way of handling this seems to be to JIT a vertex loader
			that unpacks the vertices when doing vertex specification
		*/
		glState.vdesc[a] = t;
	}

	void GXSetVtxAttrFmt(GXVtxFmt i, GXAttr a, GXCompCnt c, GXCompType t, unsigned char s) {
		glState.vat[i][a] = {c, t};
	}

	void GXFlush() {
		if (glState.pendingDraw) {
			glState.updateGX();
			glFlushMappedNamedBufferRange(glState.vbo, 0, glState.writeOffset);
			auto c = glState.currentExpectedVtxCnt;
			if (glState.currentPType == GXPrimitive::GX_QUADS)
				c += c / 2;	 // a 4-vertices quad is two 3-vertices triangles
			glDrawArrays(GX2GL((GXPrimitive)glState.currentPType), 0, c);
		}

		glState.currentVat = 0;
		glState.currentPType = 0;
		glState.currentExpectedVtxCnt = 0;
		glState.currentSpecifiedPosCnt = 0;
		glState.pendingDraw = 0;
	}

	void GXInvalidateTexAll() {
		// reload all the textures?
	}

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
		default:
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
		param_1->color = param_2;
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
		glState.init();

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

		// Allocate TLUTs, 16 256-entry TLUTs and 4 1K-entry TLUTs.
		// 256-entry TLUTs are 8kB, 1k-entry TLUTs are 32kB.
		//
		for (int i = 0; i < 16; ++i)
			GXInitTlutRegion(glState.small + i, 0, GXTlutSize::GX_TLUT_256);
		for (int i = 0; i < 4; ++i)
			GXInitTlutRegion(glState.big + i, 0, GXTlutSize::GX_TLUT_1K);

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

	template <typename T, int N, bool inc = false>
	struct GXAttrWriter {
		T prevs[N][2];

		void write(T data[N]) {
			// todo: handle indirect modes
			if constexpr (inc) {
				glState.currentSpecifiedPosCnt += 1;
				if (glState.currentSpecifiedPosCnt / glState.vat[glState.currentVat][GX_VA_POS].count > glState.currentExpectedVtxCnt) {
				}  // error, specifying more vertices than expected
			}
			// if this attr is in direct mode...
			{
				if (glState.currentPType == GXPrimitive::GX_QUADS) {
					if (glState.currentSpecifiedPosCnt &&
						glState.currentSpecifiedPosCnt % 4 == 0) {
						glState.write(prevs);  // break the quad into two triangles
					}
				}
				memcpy(prevs[0], prevs[1], sizeof(prevs[0]));
				memcpy(prevs[1], data, sizeof(prevs[1]));
				glState.write(data);
			}
		}
	};

	GXAttrWriter<s16, 2, true> gp2s16;
	GXCDEC(GXPosition, 2, s16) {
		s16 arr[] = {x, y};
		gp2s16.write(arr);
	}

	GXAttrWriter<s16, 3, true> gp3s16;
	GXCDEC(GXPosition, 3, s16) {
		s16 arr[] = {x, y, z};
		gp3s16.write(arr);
	}

	GXAttrWriter<f32, 3, true> gp3f32;
	GXCDEC(GXPosition, 3, f32) {
		f32 arr[] = {x, y, z};
		gp3f32.write(arr);
	}

	GXAttrWriter<s16, 3> gt2s16;
	GXCDEC(GXTexCoord, 2, u8) {
		s16 arr[] = {x, y};
		gt2s16.write(arr);
	}

	GXAttrWriter<u16, 3> gt3s16;
	GXCDEC(GXTexCoord, 2, u16) {
		u16 arr[] = {x, y};
		gt3s16.write(arr);
	}

	GXAttrWriter<f32, 2> gt3f32;
	GXCDEC(GXTexCoord, 2, f32) {
		f32 arr[] = {x, y};
		gt3f32.write(arr);
	}

	GXAttrWriter<u32, 1> gt1u32;
	GXCDEC(GXColor, 1, u32) {
		u32 arr[] = {x};
		gt1u32.write(arr);
	}
}