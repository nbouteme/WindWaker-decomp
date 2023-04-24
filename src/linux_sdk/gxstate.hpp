#pragma once

#include <dolphin/gx.h>
#include <dolphin/mtx.h>

using vec3 = float[3];
using vec4 = float[4];
using vec2 = float[2];
using ivec4 = int[4];

namespace gx {
	using IndTMtx = f32[2][3];

	struct alignas(16) IndSettings {
		GXIndTexStageID ind_stage;	 // 4
		GXIndTexFormat format;		 // 8
		GXIndTexBiasSel bias_sel;	 // 12
		GXIndTexMtxID matrix_sel;	 // 16
		GXIndTexWrap wrap_s;		 // 20
		GXIndTexWrap wrap_t;		 // 24
		int add_prev;				 // 28
		int utc_lod;				 // 32
		GXIndTexAlphaSel alpha_sel;	 // 36
	};								 // 48

	struct alignas(16) TevOp {
		GXTevOp op;			 // 4
		GXTevBias bias;		 // 8
		GXTevScale scale;	 // 12
		int clamp;			 // 16
		GXTevRegID out_reg;	 // 20
		int a, b, c;		 // 32, pad to multiple of 16
	};

	struct alignas(16) TevState {
		int ksel;		  // 4
		int kasel;		  // 8
		GXColor c;		  // 12
		int ras_swizzle;  // 16

		int tex_swizzle;  // 20

		GXTevAlphaArg a_inputs[4] __attribute__((aligned(16)));	 // 36
		// int pa, pb, pc;				// 48
		GXTevColorArg c_inputs[4] __attribute__((aligned(16)));	 // 64
		//
		TevOp aop;	// 96
		TevOp cop;	// 128
		//
		GXTexCoordID coord __attribute__((aligned(16)));  // 132
		GXTexMapID tmap;								  // 136
		GXChannelID chan;								  // 140
		//
		IndSettings indirection;  // 188
	};

	static_assert(sizeof(TevOp) % 16 == 0);
	static_assert(sizeof(TevState) % 16 == 0);

	struct alignas(16) TexGenState {
		GXTexGenType func;	// 4
		GXTexGenSrc src;	// 8
		u32 mtxid;			// 12
		u32 ptmtx;			// 16
		int normalize;		// 20
		int line_bias;		// 24
		int point_bias;		// 28
	};

	static_assert(sizeof(TexGenState) % 16 == 0);

	struct alignas(16) ChanState {
		int enable;	 // 4

		GXColorSrc amb_src;	  // 8
		GXColorSrc mat_src;	  // 12
		u32 light_mask;		  // 16
		GXDiffuseFn diff_fn;  // 20
		GXAttnFn attn_fn;	  // 24

		GXColor amb_color;	// 28
		GXColor mat_color;	// 32
	};

	static_assert(sizeof(ChanState) % 16 == 0);

	struct alignas(16) IndTex {
		float ss, st;		 // 8
		GXTexCoordID coord;	 // 12
		GXTexMapID map;		 // 16
	};
	static_assert(sizeof(IndTex) % 16 == 0);

	using vec4 = float[4];

	struct alignas(16) AlphaTestStruct {
		GXCompare comp0;  // 4
		uint ref0;		  // 8
		GXAlphaOp op;	  // 12
		GXCompare comp1;  // 16
		uint ref1;		  // 20
	};

	// represent the entire pipeline state, will be passed in a shader storage object on each drawcall
	// update is delayed to drawing commands or flushing
	struct alignas(16) GXStateStruct {
		ivec4 swizzles[4];
		GXColorS10 tregs[4];
		GXColor kregs[4];
		TevState tevs[16];
		TexGenState tgs[8];
		ChanState chans[9];
		IndTex indtex[4];
		IndTMtx indmtx[3];

		s8 inds[4] __attribute__((aligned(16)));  // was s8[3], changed to match shader definition
		int texgens;
		int tevstages;

		int colchans;
		int indn;
		int dither;
		float point_sprite_uv_bias;

		float line_sprite_uv_bias;
		uint current_mtx;

		AlphaTestStruct alphacomp __attribute__((aligned(16)));

		int cupdate __attribute__((aligned(16)));
		int aupdate;
		vec4 dbg = {1, 0.5, 0, 1};

		vec4 matrix_mem[128] __attribute__((aligned(16)));
		vec4 norm_mat[32];	// 4th component ignored

		mtx::Mtx44 persp_proj;
		mtx::Mtx44 ortho_proj;
		bool isprojpersp;
	};
}
