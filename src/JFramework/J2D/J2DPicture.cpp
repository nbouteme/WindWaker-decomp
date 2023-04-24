#include "J2DPicture.h"

#include <JFramework/JUtility/JUTPalette.h>
#include <JFramework/JUtility/JUTResReference.h>
#include <JFramework/JUtility/JUTTexture.h>
#include <dolphin/mtx.h>
#include <machine/dolphin/graphic.h>

#include "../J2DGraph/J2DGrafContext.h"

int J2DPicture::getTypeID() {
	return 0x12;
}

void J2DPicture::swap(float *param_1, float *param_2) {
	float fVar1;

	fVar1 = *param_1;
	*param_1 = *param_2;
	*param_2 = fVar1;
}

void J2DPicture::changeTexture(char *param_1, byte param_2) {
	ResTIMG *pRVar1;

	pRVar1 = (ResTIMG *)JKRFileLoader::getGlbResource(param_1, 0);
	changeTexture(pRVar1, param_2);
}

void J2DPicture::drawSelf(MTX34 param_3, float param_1, float param_2) {
	if (this->mpTexture[0]) {
		drawFullSet(mScreenPos.mTL[0] + param_1,
					mScreenPos.mTL[1] + param_2,
					mPos.mBR[0] - mPos.mTL[0],
					mPos.mBR[1] - mPos.mTL[1],
					this->binding,
					this->mirror & 3,
					this->mirror >> 2 & 1,
					param_3);
	}
}

void J2DPicture::drawTexCoord(float param_2, float param_3, float param_4, float param_5,
							  float param_6, float param_7, float param_8, float param_9,
							  float param_10, float param_11, float param_12, float param_13,
							  MTX34 param_14) {
	uint uVar1, numTexGen;
	float dVar3 = param_10;
	float dVar4 = param_11;
	float dVar5 = param_12;
	float dVar6 = param_13;
	for (uVar1 = 0; numTexGen = this->mNumTexture, (uVar1 & 0xff) < numTexGen; uVar1 = uVar1 + 1) {
		if ((uVar1 & 0xff) < numTexGen) {
			this->mpTexture[uVar1 & 0xff]->load((gx::GXTexMapID)uVar1);
		}
	}
	float dVar8 = param_2 + param_4;
	float dVar7 = param_3 + param_5;
	using namespace gx;
	gx::GXSetNumTexGens(numTexGen);
	gx::GXColor local_118 = {0xff, 0xff, 0xff, 0xff};
	gx::GXColor local_114 = {0xff, 0xff, 0xff, 0xff};
	gx::GXColor local_110 = {0xff, 0xff, 0xff, 0xff};
	gx::GXColor local_10c = {0xff, 0xff, 0xff, 0xff};
	getNewColor(&local_118);
	setTevMode();
	MTX34 MStack264;
	mtx::MTXConcat(param_14, mDrawMtx, MStack264);
	gx::GXLoadPosMtxImm(MStack264, 0);
	gx::GXClearVtxDesc();
	gx::GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	gx::GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	gx::GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
	gx::GXSetVtxAttrFmt(GXVtxFmt::GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
	gx::GXSetVtxAttrFmt(GXVtxFmt::GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);

	// vertex format is [POS(3f);COL(4b);TEX(2f)]

	gx::GXBegin(gx::GXPrimitive::GX_QUADS, gx::GXVtxFmt::GX_VTXFMT0, 4);

	gx::GXPosition3f32(param_2, param_3, 0.0f);
	gx::GXColor1u32(*(u32 *)&local_118);
	gx::GXTexCoord2f32(param_6, param_7);

	gx::GXPosition3f32(dVar8, param_3, 0.0f);
	gx::GXColor1u32(*(u32 *)&local_114);
	gx::GXTexCoord2f32(param_8, param_9);

	gx::GXPosition3f32(dVar8, dVar7, 0.0f);
	gx::GXColor1u32(*(u32 *)&local_10c);
	gx::GXTexCoord2f32(dVar5, dVar6);

	gx::GXPosition3f32(param_2, dVar7, 0.0f);
	gx::GXColor1u32(*(u32 *)&local_110);
	gx::GXTexCoord2f32(dVar3, dVar4);

	gx::GXSetVtxAttrFmt(GXVtxFmt::GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_U16, 0xf);
	gx::GXSetVtxAttrFmt(GXVtxFmt::GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_S16, 0);
}

void J2DPicture::drawFullSet(float param_1,
							 float param_2,
							 float param_3,
							 float param_4,
							 J2DBinding binding,
							 J2DMirror mirror,
							 bool param_7,
							 MTX34 param_8) {
	uint uVar1, uVar2, uVar5, uVar3, uVar4;

	if (!param_7) {
		if ((mirror & 2) == 0) {
			uVar1 = binding >> 3;
		} else {
			uVar1 = binding >> 2;
		}
		uVar1 = uVar1 & 1;
		if ((mirror & 2) == 0) {
			uVar2 = binding >> 2;
		} else {
			uVar2 = binding >> 3;
		}
		uVar2 = uVar2 & 1;
		uVar5 = binding;
		if ((mirror & 1) == 0) {
			uVar5 = binding >> 1;
		}
		uVar5 = uVar5 & 1;
		if ((mirror & 1) == 0) {
			uVar3 = binding & 1;
		} else {
			uVar3 = binding >> 1 & 1;
		}
	} else {
		uVar1 = binding;
		if ((mirror & 2) == 0) {
			uVar1 = binding >> 1;
		}
		uVar1 = uVar1 & 1;
		uVar2 = binding;
		if ((mirror & 2) != 0) {
			uVar2 = binding >> 1;
		}
		uVar2 = uVar2 & 1;
		if ((mirror & 1) == 0) {
			uVar5 = binding >> 2;
		} else {
			uVar5 = binding >> 3;
		}
		uVar5 = uVar5 & 1;
		if ((mirror & 1) == 0) {
			uVar3 = binding >> 3 & 1;
		} else {
			uVar3 = binding >> 2 & 1;
		}
	}

	float local_58;
	float local_54;
	float local_50;
	float local_4c;

	auto pRVar6 = this->mpTexture[0]->mpTIMG;
	float dVar10 = pRVar6->mWidth;
	float dVar11 = pRVar6->mHeight;
	float dVar8 = param_4;
	if (param_7) {
		dVar8 = param_3;
	}
	float dVar9 = param_3;
	if (param_7) {
		dVar9 = param_4;
	}

	if (uVar1 == 0) {
		if (uVar2 == 0) {
			local_54 = (dVar8 / dVar10) * 0.5;
			local_4c = 0.5 - local_54;
			local_54 = local_54 + 0.5;
		} else {
			local_4c = 1.0 - (dVar8 / dVar10);
			local_54 = 1.0;
		}
	} else {
		local_4c = 0.0;
		if (uVar2 == 0) {
			local_54 = (dVar8 / dVar10);
		} else {
			local_54 = 1.0;
		}
	}

	if (uVar5 == 0) {
		if (uVar3 == 0) {
			local_58 = (dVar9 / dVar11) * 0.5;
			local_50 = 0.5 - local_58;
			local_58 = local_58 + 0.5;
		} else {
			local_50 = 1.0 - (dVar9 / dVar11);
			local_58 = 1.0;
		}
	} else {
		local_50 = 0.0;
		if (uVar3 == 0) {
			local_58 = (dVar9 / dVar11);
		} else {
			local_58 = 1.0;
		}
	}

	if ((mirror & 2)) {
		swap(&local_4c, &local_54);
	}
	if ((mirror & 1)) {
		swap(&local_50, &local_58);
	}
	if (param_4 == false) {
		drawTexCoord(0.0, 0.0, param_3, param_4, local_4c, local_50, local_54, local_50, local_4c, local_58,
					 local_54, local_58, param_8);
	} else {
		drawTexCoord(0.0, 0.0,
					 param_3, param_4, local_4c, local_58,
					 local_4c, local_50, local_54, local_58,
					 local_54, local_50, param_8);
	}
}

ResTIMG *J2DPicture::changeTexture(ResTIMG *param_1, uchar param_2) {
	byte bVar1;
	JUTTexture *pJVar2;
	ResTIMG *pRVar3;

	bVar1 = this->mNumTexture;
	if (param_2 < bVar1) {
		if (param_2 < bVar1) {
			pJVar2 = this->mpTexture[param_2];
		} else {
			pJVar2 = nullptr;
		}
		if ((pJVar2 == nullptr) || (param_1 == nullptr)) {
			pRVar3 = nullptr;
		} else {
			if (param_2 < bVar1) {
				pJVar2 = this->mpTexture[param_2];
			} else {
				pJVar2 = nullptr;
			}
			pRVar3 = pJVar2->mpTIMG;
			if (param_2 < bVar1) {
				pJVar2 = this->mpTexture[param_2];
			} else {
				pJVar2 = nullptr;
			}
			pJVar2->storeTIMG(param_1, '\0');
		}
	} else {
		pRVar3 = nullptr;
	}
	return pRVar3;
}

void J2DPicture::drawOut(float param_1, float param_2, float param_3, float param_4,
						 float param_5, float param_6, float param_7, float param_8) {
	TBox2<float> local_28;
	TBox2<float> local_18;

	local_28.mBR[0] = param_5 + param_7;
	local_28.mBR[1] = param_6 + param_8;
	local_18.mBR[0] = param_1 + param_3;
	local_18.mBR[1] = param_2 + param_4;
	local_28.mTL[0] = param_5;
	local_28.mTL[1] = param_6;
	local_18.mTL[0] = param_1;
	local_18.mTL[1] = param_2;
	drawOut(&local_18, &local_28);
}

void J2DPicture::drawOut(TBox2<float> *param_1, TBox2<float> *param_2) {
	using namespace gx;
	float fVar1;
	uint uVar2;
	uint uVar3;
	undefined4 uVar4;
	undefined8 in_f28;
	double dVar5;
	undefined8 in_f29;
	double dVar6;
	undefined8 in_f30;
	double dVar7;
	undefined8 in_f31;
	double dVar8;
	gx::GXColor local_e8[4];
	undefined4 local_e4;
	undefined4 local_e0;
	undefined4 local_dc;
	long long local_d8;
	undefined4 local_d0;
	uint uStack204;
	long long local_c8;
	undefined4 local_c0;
	uint uStack188;
	long long local_b8;
	undefined4 local_b0;
	uint uStack172;
	long long local_a8;
	undefined4 local_a0;
	uint uStack156;
	long long local_98;
	undefined4 local_90;
	uint uStack140;
	long long local_88;
	undefined4 local_80;
	uint uStack124;
	long long local_78;
	undefined4 local_70;
	uint uStack108;
	long long local_68;
	undefined4 local_60;
	uint uStack92;
	undefined auStack56[16];
	undefined auStack40[16];
	undefined auStack24[16];
	undefined auStack8[8];

	uVar4 = 0;
	if (mbDraw != 0) {
		for (uVar3 = 0; uVar2 = (uint)this->mNumTexture, (uVar3 & 0xff) < uVar2; uVar3 = uVar3 + 1) {
			if ((uVar3 & 0xff) < uVar2) {
				this->mpTexture[uVar3 & 0xff]->load((GXTexMapID)(uVar3 & 0xff));
			}
		}
		gx::GXSetNumTexGens(uVar2);
		fVar1 = param_2->mBR[0] - param_2->mTL[0];
		dVar8 = (double)((param_1->mTL[0] - param_2->mTL[0]) / fVar1);
		dVar7 = (double)((param_1->mBR[0] - param_2->mBR[0]) / fVar1 + 1.0);
		fVar1 = param_2->mBR[1] - param_2->mTL[1];
		dVar6 = (double)((param_1->mTL[1] - param_2->mTL[1]) / fVar1);
		dVar5 = (double)((param_1->mBR[1] - param_2->mBR[1]) / fVar1 + 1.0);
		mDrawAlpha = mAlpha;
		memset(local_e8, ~0, sizeof(local_e8));
		//local_e8 = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		//local_e4 = 0xffffffff;
		//local_e0 = 0xffffffff;
		//local_dc = 0xffffffff;
		getNewColor(local_e8);
		setTevMode();
		gx::GXClearVtxDesc();
		gx::GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
		gx::GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
		gx::GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
		gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
		gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);

		gx::GXBegin(GX_QUADS, GX_VTXFMT0, 4);

		gx::GXPosition3f32(param_1->mTL[0], param_1->mTL[1], 0.0f);
		gx::GXColor1u32(*(u32 *)&local_e8);
		gx::GXTexCoord2f32(dVar8, dVar6);

		gx::GXPosition3f32(param_1->mBR[0], param_1->mTL[1], 0.0f);
		gx::GXColor1u32(*(u32 *)&local_e4);
		gx::GXTexCoord2f32(dVar7, dVar6);

		gx::GXPosition3f32(param_1->mBR[0], param_1->mBR[1], 0.0f);
		gx::GXColor1u32(*(u32 *)&local_dc);
		gx::GXTexCoord2f32(dVar7, dVar5);

		gx::GXPosition3f32(param_1->mTL[0], param_1->mBR[1], 0.0f);
		gx::GXColor1u32(*(u32 *)&local_e0);
		gx::GXTexCoord2f32(dVar8, dVar5);

		gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_S16, 0);
		gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_U16, 0xf);
		gx::GXSetNumTexGens(0);
		gx::GXSetNumTevStages(1);
		gx::GXSetTevOp(GXTevStageID::GX_TEVSTAGE0, GX_PASSCLR);
		gx::GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
		gx::GXSetVtxDesc(GX_VA_TEX0, GX_NONE);
	}
}

void J2DPicture::insert(char *param_1, uchar param_2, float param_3) {
	ResTIMG *pRVar1;
	double dVar2;

	dVar2 = (double)param_3;
	pRVar1 = (ResTIMG *)JKRFileLoader::getGlbResource(param_1, 0);
	insert(pRVar1, param_2, dVar2);
}

undefined4 J2DPicture::insert(ResTIMG *param_1, uchar param_2, float param_3) {
	ushort uVar1;
	ushort uVar2;
	uint uVar3;
	undefined4 uVar4;
	JUTTexture *this_00;
	ResTIMG *pRVar5;
	uint uVar6;
	int iVar7;
	undefined4 uVar8;
	double dVar9;
	undefined8 in_f31;
	undefined auStack8[8];

	dVar9 = (double)param_3;
	uVar8 = 0;
	if ((((param_1 == nullptr) || (3 < this->mNumTexture)) || (3 < param_2)) ||
		(this->mNumTexture < param_2)) {
		uVar4 = 0;
	} else {
		this_00 = new JUTTexture;
		if (this_00 != nullptr) {
			this_00->mpPalette = nullptr;
			this_00->storeTIMG(param_1, '\0');
			this_00->field13_0x3b = this_00->field13_0x3b & 2;
		}
		for (uVar6 = 3; (uint)param_2 < (uVar6 & 0xff); uVar6 = uVar6 - 1) {
			uVar3 = uVar6 & 0xff;
			this->mpTexture[uVar3] = this->mpTexture[uVar3 - 1];
			this->mBlendKonstColorF[uVar3] = this->mBlendKonstColorF[uVar3 - 1];
			this->mBlendKonstAlphaF[uVar3] = this->mBlendKonstColorF[uVar3 + 3];
		}
		iVar7 = 1 << (uint)param_2;
		uVar6 = iVar7 - 1;
		this->field4_0xdd &= (byte)uVar6 | (byte)(((uint)this->field4_0xdd & ~uVar6) << 1);
		this->mpTexture[param_2] = this_00;
		this->field4_0xdd |= (byte)iVar7;
		this->mBlendKonstColorF[param_2] = dVar9;
		this->mBlendKonstAlphaF[param_2] = dVar9;
		if ((this->mNumTexture == 0) && (this->mpTexture[0] != nullptr)) {
			pRVar5 = this->mpTexture[0]->mpTIMG;
			uVar1 = pRVar5->mHeight;
			uVar2 = pRVar5->mWidth;
			mPos.mTL[0] = 0.0;
			mPos.mTL[1] = 0.0;
			mPos.mBR[0] = uVar2;
			mPos.mBR[1] = uVar1;
			calcMtx();
		}
		this->mNumTexture = this->mNumTexture + 1;
		setBlendKonstColor();
		setBlendKonstAlpha();
		uVar4 = 1;
	}
	return uVar4;
}

void J2DPicture::drawSelf(float param_1, float param_2) {
	double dVar1;
	double dVar2;
	MTX34 MStack72;

	dVar2 = (double)param_2;
	dVar1 = (double)param_1;
	mtx::MTXIdentity(MStack72);
	drawSelf(MStack72, dVar1, dVar2);  // TODO: overload
}

void J2DPicture::initinfo() {
	mMagic = 0x50494331;
	this->binding = 0xf;
	this->mirror = this->mirror & 4;
	this->mirror = this->mirror & 3;
	this->mBlendKonstColorF[0] = 1.0;
	this->mBlendKonstColorF[1] = 1.0;
	this->mBlendKonstColorF[2] = 1.0;
	this->mBlendKonstColorF[3] = 1.0;
	setBlendKonstColor();
	this->mBlendKonstAlphaF[0] = 1.0;
	this->mBlendKonstAlphaF[1] = 1.0;
	this->mBlendKonstAlphaF[2] = 1.0;
	this->mBlendKonstAlphaF[3] = 1.0;
	setBlendKonstAlpha();
	(this->mBgColor).r = 0;
	(this->mBgColor).g = 0;
	(this->mBgColor).b = 0;
	(this->mBgColor).a = 0;
	(this->mColorBase).r = 0xff;
	(this->mColorBase).g = 0xff;
	(this->mColorBase).b = 0xff;
	(this->mColorBase).a = 0xff;
	this->mNewColor[0].r = 0xff;
	this->mNewColor[0].g = 0xff;
	this->mNewColor[0].b = 0xff;
	this->mNewColor[0].a = 0xff;
	this->mNewColor[1].r = 0xff;
	this->mNewColor[1].g = 0xff;
	this->mNewColor[1].b = 0xff;
	this->mNewColor[1].a = 0xff;
	this->mNewColor[2].r = 0xff;
	this->mNewColor[2].g = 0xff;
	this->mNewColor[2].b = 0xff;
	this->mNewColor[2].a = 0xff;
	this->mNewColor[3].r = 0xff;
	this->mNewColor[3].g = 0xff;
	this->mNewColor[3].b = 0xff;
	this->mNewColor[3].a = 0xff;
}

J2DPicture::J2DPicture() {
	this->mColorBase = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	this->mBgColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	this->mBlendKonstColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	this->mBlendKonstAlpha = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	this->mpTexture[0] = nullptr;
	this->mNumTexture = 0;
	this->mpPalette = nullptr;
	initinfo();
}

void J2DPicture::drawOut(float param_1, float param_2, float param_3, float param_4,
						 float param_5, float param_6) {
	ResTIMG *pRVar1;
	TBox2<float> local_38;
	TBox2<float> local_28;
	undefined4 local_18;
	uint uStack20;
	undefined4 local_10;
	uint uStack12;

	if (this->mpTexture[0]) {
		pRVar1 = this->mpTexture[0]->mpTIMG;
		local_38.mBR[0] = param_5 + pRVar1->mWidth;
		local_38.mBR[1] = param_6 + pRVar1->mHeight;
		local_28.mBR[0] = param_1 + param_3;
		local_28.mBR[1] = param_2 + param_4;
		local_38.mTL[0] = param_5;
		local_38.mTL[1] = param_6;
		local_28.mTL[0] = param_1;
		local_28.mTL[1] = param_2;
		drawOut(&local_28, &local_38);
	}
}

void J2DPicture::private_initiate(ResTIMG *param_1, ResTLUT *param_2) {
	JUTTexture *this_00;
	JUTPalette *this_01;

	this->mpTexture[0] = nullptr;
	this->field4_0xdd = 1;
	this->mNumTexture = 0;
	if (param_1) {
		this_00 = new JUTTexture;
		if (this_00 != nullptr) {
			this_00->mpPalette = nullptr;
			this_00->storeTIMG(param_1, '\0');
			this_00->field13_0x3b = this_00->field13_0x3b & 2;
		}
		this->mpTexture[0] = this_00;
		this->mNumTexture = this->mNumTexture + 1;
	}
	this->mpPalette = nullptr;
	if (param_2 != nullptr) {
		this_01 = new JUTPalette;
		this_01->storeTLUT(gx::GXTlut::GX_TLUT0, param_2);
		this->mpPalette = this_01;
		this->mpTexture[0]->attachPalette(this->mpPalette);
	}
}

J2DPicture::J2DPicture(ulong param_1, TBox2<float> *param_2, ResTIMG *param_3, ResTLUT *param_4) {
	this->mpPalette = nullptr;
	this->mColorBase = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	this->mBgColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	this->mBlendKonstColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	this->mBlendKonstAlpha = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	private_initiate(param_3, param_4);
	initinfo();
}

J2DPicture::~J2DPicture() {
	int iVar1;
	int iVar2;

	iVar1 = 0;
	iVar2 = 0;
	while (true) {
		if ((int)(uint)this->mNumTexture <= iVar1)
			break;
		if (((uint)this->field4_0xdd & 1 << iVar1) != 0) {
			delete this->mpTexture[iVar2];
		}
		iVar1 = iVar1 + 1;
		iVar2 = iVar2 + 4;
	}
	delete this->mpPalette;
}

J2DPicture::J2DPicture(ResTIMG *param_1) {
	this->mColorBase = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	this->mBgColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	this->mBlendKonstColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	this->mBlendKonstAlpha = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	this->mpTexture[0] = nullptr;
	this->mNumTexture = 0;
	if (param_1 != nullptr) {
		insert(param_1, this->mNumTexture, 1.0);
	}
	this->mpPalette = nullptr;
	initinfo();
}

J2DPicture::J2DPicture(char *param_1) {
	this->mColorBase = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	this->mBgColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	this->mBlendKonstColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	this->mBlendKonstAlpha = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	this->mpTexture[0] = nullptr;
	this->mNumTexture = 0;
	if (param_1 != nullptr) {
		insert(param_1, this->mNumTexture, 1.0);
	}
	this->mpPalette = nullptr;
	initinfo();
}

void J2DPicture::initiate(ResTIMG *param_1, ResTLUT *param_2) {
	ushort uVar1;
	ushort uVar2;
	ResTIMG *pRVar3;

	private_initiate(param_1, param_2);
	if (this->mpTexture[0]) {
		pRVar3 = this->mpTexture[0]->mpTIMG;
		uVar1 = pRVar3->mHeight;
		uVar2 = pRVar3->mWidth;
		mPos.mTL[0] = 0.0;
		mPos.mTL[1] = 0.0;
		mPos.mBR[0] = uVar2;
		mPos.mBR[1] = uVar1;

		calcMtx();
	}
}

void J2DPicture::setBlendKonstColor() {
	float fVar1;
	float fVar2;
	uint uVar3;
	byte bVar4;
	uint uVar5;
	u8 local_18;
	u8 uStack23;
	u8 uStack22;
	u8 uStack21;

	uVar3 = 0;
	for (bVar4 = 1; bVar4 < this->mNumTexture; bVar4 = bVar4 + 1) {
		fVar1 = 0.0;
		for (uVar5 = 0; (uVar5 & 0xff) < (uint)bVar4; uVar5 = uVar5 + 1) {
			fVar1 = fVar1 + this->mBlendKonstColorF[uVar5 & 0xff];
		}
		fVar2 = fVar1 + this->mBlendKonstColorF[bVar4];
		if (fVar2 != 0.0) {
			uVar3 = uVar3 | ((int)((1.0 - fVar1 / fVar2) * 255.0) & 0xffU) << (bVar4 - 1) * 8;
		}
	}
	local_18 = (u8)(uVar3 >> 0x18);
	(this->mBlendKonstColor).r = local_18;
	uStack23 = (u8)(uVar3 >> 0x10);
	(this->mBlendKonstColor).g = uStack23;
	uStack22 = (u8)(uVar3 >> 8);
	(this->mBlendKonstColor).b = uStack22;
	uStack21 = (u8)uVar3;
	(this->mBlendKonstColor).a = uStack21;
	return;
}

void J2DPicture::setBlendKonstAlpha() {
	float fVar1;
	float fVar2;
	uint uVar3;
	byte bVar4;
	uint uVar5;
	u8 local_18;
	u8 uStack23;
	u8 uStack22;
	u8 uStack21;

	uVar3 = 0;
	for (bVar4 = 1; bVar4 < this->mNumTexture; bVar4 = bVar4 + 1) {
		fVar1 = 0.0;
		for (uVar5 = 0; (uVar5 & 0xff) < (uint)bVar4; uVar5 = uVar5 + 1) {
			fVar1 = fVar1 + this->mBlendKonstAlphaF[uVar5 & 0xff];
		}
		fVar2 = fVar1 + this->mBlendKonstAlphaF[bVar4];
		if (fVar2 != 0.0) {
			uVar3 = uVar3 | ((int)((1.0 - fVar1 / fVar2) * 255.0) & 0xffU) << (bVar4 - 1) * 8;
		}
	}
	local_18 = (u8)(uVar3 >> 0x18);
	(this->mBlendKonstAlpha).r = local_18;
	uStack23 = (u8)(uVar3 >> 0x10);
	(this->mBlendKonstAlpha).g = uStack23;
	uStack22 = (u8)(uVar3 >> 8);
	(this->mBlendKonstAlpha).b = uStack22;
	uStack21 = (u8)uVar3;
	(this->mBlendKonstAlpha).a = uStack21;
	return;
}

void J2DPicture::getNewColor(gx::GXColor *param_1) {
	uint uVar1;

	param_1->r = this->mNewColor[0].r;
	param_1->g = this->mNewColor[0].g;
	param_1->b = this->mNewColor[0].b;
	param_1->a = this->mNewColor[0].a;
	param_1[1].r = this->mNewColor[1].r;
	param_1[1].g = this->mNewColor[1].g;
	param_1[1].b = this->mNewColor[1].b;
	param_1[1].a = this->mNewColor[1].a;
	param_1[2].r = this->mNewColor[2].r;
	param_1[2].g = this->mNewColor[2].g;
	param_1[2].b = this->mNewColor[2].b;
	param_1[2].a = this->mNewColor[2].a;
	param_1[3].r = this->mNewColor[3].r;
	param_1[3].g = this->mNewColor[3].g;
	param_1[3].b = this->mNewColor[3].b;
	param_1[3].a = this->mNewColor[3].a;
	uVar1 = (uint)mDrawAlpha;
	if (uVar1 == 0xff) {
		return;
	}
	param_1->a = (u8)((param_1->a * uVar1) / 0xff);
	param_1[1].a = (u8)(((uint)param_1[1].a * (uint)mDrawAlpha) / 0xff);
	param_1[2].a = (u8)(((uint)param_1[2].a * (uint)mDrawAlpha) / 0xff);
	param_1[3].a = (u8)(((uint)param_1[3].a * (uint)mDrawAlpha) / 0xff);
	return;
}

int J2DPicture::remove(uchar param_1) {
	uint uVar1;
	uint uVar2;
	uint uVar3;
	int iVar4;
	uint uVar5;

	uVar5 = (uint)param_1;
	uVar1 = (uint)param_1;
	if ((uVar1 < this->mNumTexture) && (this->mNumTexture != 1)) {
		if (((uint)this->field4_0xdd & 1 << uVar1) != 0) {
			delete this->mpTexture[param_1];
		}
		for (; uVar2 = uVar5 & 0xff, (int)uVar2 < (int)(this->mNumTexture - 1); uVar5 = uVar5 + 1) {
			uVar3 = uVar5 & 0xff;
			this->mpTexture[uVar3] = this->mpTexture[uVar2 + 1];
			this->mBlendKonstColorF[uVar3] = this->mBlendKonstColorF[uVar2 + 1];
			this->mBlendKonstAlphaF[uVar3] = this->mBlendKonstAlphaF[uVar2 + 1];
		}
		this->field4_0xdd &= (char)((1 << uVar1) - 1U) |
			(byte)((int)((uint)this->field4_0xdd & ~((1 << (uVar1 + 1)) - 1U)) >> 1);
		this->mNumTexture = this->mNumTexture - 1;
		setBlendKonstColor();
		setBlendKonstAlpha();
		iVar4 = 1;
	} else {
		iVar4 = 0;
	}
	return iVar4;
}

void J2DPicture::setTevMode() {
	using namespace gx;
	GXTevStageID GVar1;
	uint uVar2;
	byte bVar3;
	gx::GXColor local_28;
	gx::GXColor local_24;
	gx::GXColor local_20;
	gx::GXColor local_1c;
	undefined4 local_18;
	gx::GXColor local_14;

	for (bVar3 = 0; bVar3 < this->mNumTexture; bVar3 = bVar3 + 1) {
		GVar1 = (GXTevStageID)bVar3;
		gx::GXSetTevOrder(GVar1, (GXTexCoordID)GVar1, (GXTexMapID)GVar1, GX_COLOR_NULL);
	}
	local_18 = 0xffffffff;
	local_14 = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	gx::GXSetTevColor(GX_TEVREG2, local_14);
	gx::GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_TEXC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
	if (this->mpTexture[0]->mpTIMG->mTranslucency == 0) {
		gx::GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_A2, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
	} else {
		gx::GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_TEXA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
	}
	gx::GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
	gx::GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
	local_1c = this->mBlendKonstColor;
	gx::GXSetTevKColor(GXTevKColorID::GX_KCOLOR0, local_1c);
	local_20 = this->mBlendKonstAlpha;
	gx::GXSetTevKColor(GXTevKColorID::GX_KCOLOR2, local_20);
	for (bVar3 = 1; bVar3 < this->mNumTexture; bVar3 = bVar3 + 1) {
		GVar1 = (GXTevStageID)bVar3;
		uVar2 = (uint)bVar3;
		gx::GXSetTevKColorSel(GVar1, (GXTevKColorSel)(uVar2 * -4 + 0x20));
		gx::GXSetTevKAlphaSel(GVar1, (GXTevKAlphaSel)(uVar2 * -4 + 0x22));
		gx::GXSetTevColorIn(GVar1, GX_CC_CPREV, GX_CC_TEXC, GX_CC_KONST, GX_CC_ZERO);
		if (this->mpTexture[uVar2]->mpTIMG->mTranslucency == 0) {
			gx::GXSetTevAlphaIn(GVar1, GX_CA_APREV, GX_CA_A2, GX_CA_KONST, GX_CA_ZERO);
		} else {
			gx::GXSetTevAlphaIn(GVar1, GX_CA_APREV, GX_CA_TEXA, GX_CA_KONST, GX_CA_ZERO);
		}
		gx::GXSetTevColorOp(GVar1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
		gx::GXSetTevAlphaOp(GVar1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
	}
	if (*(uint*)(&this->mBgColor) || (*(uint *)&this->mColorBase != 0xffffffff)) {
		GVar1 = (GXTevStageID)bVar3;
		gx::GXSetTevOrder(GVar1, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
		local_24 = this->mBgColor;
		gx::GXSetTevColor(GX_TEVREG0, local_24);
		local_28 = this->mColorBase;
		gx::GXSetTevColor(GX_TEVREG1, local_28);
		gx::GXSetTevColorIn(GVar1, GX_CC_C0, GX_CC_C1, GX_CC_CPREV, GX_CC_ZERO);
		gx::GXSetTevAlphaIn(GVar1, GX_CA_A0, GX_CA_A1, GX_CA_APREV, GX_CA_ZERO);
		gx::GXSetTevColorOp(GVar1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
		gx::GXSetTevAlphaOp(GVar1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
		bVar3 = bVar3 + 1;
	}
	if ((((mDrawAlpha != 0xff) || (*(uint *)&this->mNewColor[0] != 0xffffffff)) ||
		 (*(uint *)&this->mNewColor[1] != 0xffffffff)) ||
		((*(uint *)&this->mNewColor[2] != 0xffffffff ||
		 (*(uint *)&this->mNewColor[3] != 0xffffffff)))) {
		GVar1 = (GXTevStageID)bVar3;
		gx::GXSetTevOrder(GVar1, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
		gx::GXSetTevColorIn(GVar1, GX_CC_ZERO, GX_CC_CPREV, GX_CC_RASC, GX_CC_ZERO);
		gx::GXSetTevAlphaIn(GVar1, GX_CA_ZERO, GX_CA_APREV, GX_CA_RASA, GX_CA_ZERO);
		gx::GXSetTevColorOp(GVar1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
		gx::GXSetTevAlphaOp(GVar1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
		bVar3 = bVar3 + 1;
	}
	gx::GXSetNumTevStages(bVar3);
	gx::GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
	for (bVar3 = 0; bVar3 < this->mNumTexture; bVar3 = bVar3 + 1) {
		gx::GXSetTexCoordGen2((GXTexCoordID)bVar3, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, false, GX_PTIDENTITY);
	}
	gx::GXSetNumChans(1);
	return;
}

void J2DPicture::draw(float param_1, float param_2, float param_3, float param_4,
					  bool param_5, bool param_6, bool param_7)

{
	using namespace gx;
	uint uVar1;
	uint uVar2;
	undefined4 uVar3;
	double dVar4;
	double dVar5;
	double dVar6;
	double dVar7;
	undefined8 in_f28;
	undefined8 in_f29;
	undefined8 in_f30;
	undefined8 in_f31;
	GXColor local_98[4];
	undefined4 local_94;
	undefined4 local_90;
	undefined4 local_8c;
	MTX34 MStack136;
	undefined auStack56[16];
	undefined auStack40[16];
	undefined auStack24[16];
	undefined auStack8[8];

	dVar7 = (double)param_4;
	dVar5 = (double)param_2;
	dVar6 = (double)param_3;
	dVar4 = (double)param_1;
	uVar3 = 0;
	if (mbDraw != 0) {
		for (uVar2 = 0; uVar1 = (uint)this->mNumTexture, (uVar2 & 0xff) < uVar1; uVar2 = uVar2 + 1) {
			if ((uVar2 & 0xff) < uVar1) {
				this->mpTexture[uVar2 & 0xff]->load((GXTexMapID)(uVar2 & 0xff));
			}
		}
		gx::GXSetNumTexGens(uVar1);
		mDrawAlpha = mAlpha;
		memset(&local_98, ~0, sizeof(local_98));
		J2DPicture::getNewColor(local_98);
		J2DPicture::setTevMode();
		makeMatrix(dVar4, dVar5);
		gx::GXLoadPosMtxImm(mMtx, 0);
		gx::GXSetCurrentMtx(0);
		gx::GXClearVtxDesc();
		gx::GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
		gx::GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
		gx::GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
		gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);

		// vertex format is [POS(3f);COL(4b);TEX(2short?)]

		gx::GXBegin(GX_QUADS, GXVtxFmt::GX_VTXFMT0, 4);
		void write_volatile_4(uint, ...);
		void write_volatile_2(uint, ...);

		gx::GXPosition3f32(0.f, 0.f, 0.f);
		gx::GXColor1u32(*(u32 *)&local_98[0]);

		/*
			x: 0 | 1;
			negation causes all bits to be flipped if x is true
			-0 & 0x8000 -> 0x0000
			-1 & 0x8000 -> 0x8000
			The texture coordinate attribute is probably configured as 16 bits with 15 bit fraction so it's just a 0.0 or 1.0 in more conventional algebra

			The ~ flips the truth table
			~-0 & 0x8000 -> 0x8000
			~-1 & 0x8000 -> 0x0000
		*/
		if (param_7 == false) {
			gx::GXTexCoord2u16(-(ushort)(param_5)&0x8000,
							   -(ushort)(param_6)&0x8000);
		} else {
			gx::GXTexCoord2u16(-(ushort)(param_5)&0x8000,
							   ~-(ushort)(param_6)&0x8000);
		}
		gx::GXPosition3f32(dVar6, 0.f, 0.f);
		gx::GXColor1u32(*(u32 *)&local_98[1]);
		if (param_7 == false) {
			gx::GXTexCoord2u16(~-(ushort)(param_5)&0x8000,
							   -(ushort)(param_6)&0x8000);
		} else {
			gx::GXTexCoord2u16(-(ushort)(param_5)&0x8000,
							   -(ushort)(param_6)&0x8000);
		}
		gx::GXPosition3f32(dVar6, dVar7, 0.f);
		gx::GXColor1u32(*(u32 *)&local_98[2]);

		if (param_7 == false) {
			gx::GXTexCoord2u16(~-(ushort)(param_5)&0x8000,
							   ~-(ushort)(param_6)&0x8000);
		} else {
			gx::GXTexCoord2u16(~-(ushort)(param_5)&0x8000,
							   -(ushort)(param_6)&0x8000);
		}
		gx::GXPosition3f32(0.f, dVar7, 0.f);
		gx::GXColor1u32(*(u32 *)&local_98[3]);

		if (param_7 == false) {
			gx::GXTexCoord2u16(-(ushort)(param_5)&0x8000,
							   ~-(ushort)(param_6)&0x8000);
		} else {
			gx::GXTexCoord2u16(~-(ushort)(param_5)&0x8000,
							   ~-(ushort)(param_6)&0x8000);
		}
		gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_U16, 0xf);
		// implicit end?
		gx::GXSetNumTexGens(0);
		gx::GXSetNumTevStages(1);
		gx::GXSetTevOp(GXTevStageID::GX_TEVSTAGE0, GXTevMode::GX_PASSCLR);
		gx::GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
		mtx::MTXIdentity(MStack136);
		gx::GXLoadPosMtxImm(MStack136, 0);
		gx::GXSetVtxDesc(GX_VA_TEX0, GX_NONE);
	}
}

J2DPicture::J2DPicture(J2DPane *param_1, JSURandomInputStream *param_2) {
	int iVar1;
	ResTIMG *pRVar2;
	ResTLUT *pRVar3;
	JUTTexture *this_00;
	JUTPalette *this_01;
	int iVar4;
	int iVar5;
	char cVar6;
	undefined uStack376;
	byte local_177;
	byte local_176;
	char local_175;
	undefined4 local_174;
	undefined4 local_170;
	undefined4 local_16c;
	undefined4 local_168;
	undefined4 local_164;
	undefined4 local_160;
	undefined4 local_15c;
	undefined4 local_158;
	undefined4 local_154;
	undefined4 local_150;
	undefined4 local_14c;
	undefined4 local_148;
	undefined4 local_144;
	undefined4 local_140;
	undefined4 local_13c;
	undefined4 local_138;
	char local_134[8];
	int local_130;
	JUTResReference local_12c;

	this->mpPalette = nullptr;
	this->mColorBase = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	this->mBgColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	this->mBlendKonstColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	this->mBlendKonstAlpha = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	iVar1 = param_2->getPosition();
	param_2->read(&local_134, 8);
	mMagic = *(uint *)&local_134;
	makePaneStream(param_1, param_2);
	local_12c.rtype = 0;
	param_2->read(&local_175, 1);
	pRVar2 = (ResTIMG *)local_12c.getResource((JSUInputStream *)param_2, 0x54494d47, nullptr);
	pRVar3 = (ResTLUT *)local_12c.getResource((JSUInputStream *)param_2, 0x544c5554, nullptr);
	param_2->read(&local_176, 1);
	this->binding = local_176;
	cVar6 = local_175 + -3;
	if (local_175 == '\x03') {
		this->mirror = 0;
	} else {
		param_2->read(&local_177, 1);
		this->mirror = local_177;
		cVar6 = local_175 + -4;
	}
	if (cVar6 != '\0') {
		param_2->read(&uStack376, 1);
		cVar6 = cVar6 + -1;
	}
	local_138 = 0;
	(this->mBgColor).r = 0;
	(this->mBgColor).g = 0;
	(this->mBgColor).b = 0;
	(this->mBgColor).a = 0;
	local_13c = 0xffffffff;
	(this->mColorBase).r = 0xff;
	(this->mColorBase).g = 0xff;
	(this->mColorBase).b = 0xff;
	(this->mColorBase).a = 0xff;
	if (cVar6 != '\0') {
		param_2->read(&this->mBgColor, 4);
		cVar6 = cVar6 + -1;
	}
	if (cVar6 != '\0') {
		param_2->read(&mColorBase, 4);
		cVar6 = cVar6 + -1;
	}
	local_164 = 0xffffffff;
	local_160 = 0xffffffff;
	local_15c = 0xffffffff;
	local_158 = 0xffffffff;
	local_154 = 0xffffffff;
	local_150 = 0xffffffff;
	local_14c = 0xffffffff;
	local_148 = 0xffffffff;
	this->mNewColor[0].r = 0xff;
	this->mNewColor[0].g = 0xff;
	this->mNewColor[0].b = 0xff;
	this->mNewColor[0].a = 0xff;
	this->mNewColor[1].r = 0xff;
	this->mNewColor[1].g = 0xff;
	this->mNewColor[1].b = 0xff;
	this->mNewColor[1].a = 0xff;
	this->mNewColor[2].r = 0xff;
	this->mNewColor[2].g = 0xff;
	this->mNewColor[2].b = 0xff;
	this->mNewColor[2].a = 0xff;
	this->mNewColor[3].r = 0xff;
	this->mNewColor[3].g = 0xff;
	this->mNewColor[3].b = 0xff;
	this->mNewColor[3].a = 0xff;
	iVar4 = 0;
	for (iVar5 = 0; (cVar6 != '\0' && (iVar5 < 4)); iVar5 = iVar5 + 1) {
		param_2->read(&mNewColor[iVar4], 4);
		cVar6 = cVar6 + -1;
		iVar4 = iVar4 + 1;
	}
	param_2->seekPos(iVar1 + *(int *)(local_134 + 4), 0);
	this->mpTexture[0] = nullptr;
	this->mNumTexture = 0;
	this->field4_0xdd = 1;
	if (pRVar2 != nullptr) {
		this_00 = (JUTTexture *)new JUTTexture;
		this_00->mpPalette = nullptr;
		this_00->storeTIMG(pRVar2, '\0');
		this_00->field13_0x3b = this_00->field13_0x3b & 2;
		this->mpTexture[0] = this_00;
		this->mNumTexture = this->mNumTexture + 1;
	}
	if (pRVar3 != nullptr) {
		this_01 = new JUTPalette;
		if (this_01 != nullptr) {
			this_01->storeTLUT(gx::GXTlut::GX_TLUT0, pRVar3);
		}
		this->mpPalette = this_01;
		this->mpTexture[0]->attachPalette(this->mpPalette);
	}
	this->mBlendKonstColorF[0] = 1.0;
	this->mBlendKonstColorF[1] = 1.0;
	this->mBlendKonstColorF[2] = 1.0;
	this->mBlendKonstColorF[3] = 1.0;
	setBlendKonstColor();
	this->mBlendKonstAlphaF[0] = 1.0;
	this->mBlendKonstAlphaF[1] = 1.0;
	this->mBlendKonstAlphaF[2] = 1.0;
	this->mBlendKonstAlphaF[3] = 1.0;
	setBlendKonstAlpha();
}
