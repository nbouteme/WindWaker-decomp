#include "J2DGrafContext.h"

void C_MTXIdentity(MTX34 m) {
	m[0][0] = 1.0f;
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = 0.0f;

	m[1][0] = 0.0f;
	m[1][1] = 1.0f;
	m[1][2] = 0.0f;
	m[1][3] = 0.0f;

	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = 1.0f;
	m[2][3] = 0.0f;
}

void J2DGrafContext::setScissor() {
	float fVar1;
	float fVar2;
	float fVar3;
	float fVar4;
	float fVar5;
	float fVar6;
	bool bVar7;
	float fVar8;
	float fVar9;
	undefined4 uVar10;
	undefined4 uVar11;
	undefined4 uVar12;
	undefined4 uVar13;
	undefined4 uVar14;
	double dVar15;
	undefined8 in_f29;
	double dVar16;
	undefined8 in_f30;
	double dVar17;
	undefined8 in_f31;
	double dVar18;
	undefined auStack40[16];
	undefined auStack24[16];
	undefined auStack8[8];

	uVar14 = 0;
	fVar1 = (this->mScissor).mTL[0];
	fVar2 = (this->mScissor).mTL[1];
	fVar3 = (this->mScissor).mBR[0];
	fVar4 = (this->mScissor).mBR[1];
	if (fVar1 <= 0.0) {
		(this->mScissor).mTL[0] = 0.0;
	}
	if ((this->mScissor).mTL[1] <= 0.0) {
		(this->mScissor).mTL[1] = 0.0;
	}
	if (1024.0 <= (this->mScissor).mBR[0]) {
		(this->mScissor).mBR[0] = 1024.0;
	}
	if (1000.0 <= (this->mScissor).mBR[1]) {
		(this->mScissor).mBR[1] = 1000.0;
	}
	bVar7 = false;
	if ((fVar1 <= fVar3) && (fVar2 <= fVar4)) {
		bVar7 = true;
	}
	fVar5 = fVar2;
	fVar6 = fVar4;
	fVar8 = fVar1;
	if (!bVar7) {
		if (fVar3 <= fVar1) {
			fVar8 = fVar3;
		}
		if (fVar4 <= fVar2) {
			fVar5 = fVar4;
		}
		fVar9 = fVar3;
		if (fVar3 <= fVar1) {
			fVar9 = fVar1;
		}
		if (fVar4 <= fVar2) {
			fVar6 = fVar2;
		}
		if (fVar9 <= fVar3) {
			fVar9 = fVar3;
		}
		fVar3 = fVar9;
		if (fVar6 <= fVar4) {
			fVar6 = fVar4;
		}
	}
	dVar18 = (double)(fVar8 + 0.0);
	if ((double)(fVar8 + 0.0) <= 0.0) {
		dVar18 = 0.0;
	}
	dVar17 = (double)(fVar5 + -1.0);
	if ((double)(fVar5 + -1.0) <= 0.0) {
		dVar17 = 0.0;
	}
	dVar16 = (double)(fVar3 + 0.0);
	if (1024.0 <= (double)(fVar3 + 0.0)) {
		dVar16 = 1024.0;
	}
	dVar15 = (double)(fVar6 + -1.0);
	if (1000.0 <= (double)(fVar6 + -1.0)) {
		dVar15 = 1000.0;
	}
	bVar7 = false;
	if ((dVar18 <= dVar16) && (dVar17 <= dVar15)) {
		bVar7 = true;
	}
	if (bVar7) {
		uVar10 = (unsigned)((double)(float)(dVar15 - dVar17));
		uVar11 = (unsigned)((double)(float)(dVar16 - dVar18));
		uVar12 = (unsigned)(dVar17);
		uVar13 = (unsigned)(dVar18);
		gx::GXSetScissor(uVar13, uVar12, uVar11, uVar10);
	} else {
		gx::GXSetScissor(0, 0, 0, 0);
	}
}

void J2DGrafContext::setup2D() {
	using namespace gx;
	int iVar1;
	MTX34 MStack56;

	gx::GXSetNumIndStages(0);
	iVar1 = 0;
	do {
		gx::GXSetTevDirect(iVar1);
		iVar1 = iVar1 + 1;
	} while (iVar1 < 8);
	GXSetAlphaCompare(_GXCompare::GX_ALWAYS, 0, _GXAlphaOp::GX_AOP_AND, _GXCompare::GX_ALWAYS, 0);
	GXSetZMode(false, _GXCompare::GX_LEQUAL, false);
	GXSetTevOp(GXTevStageID::GX_TEVSTAGE0, GXTevMode::GX_PASSCLR);
	GXSetNumChans(1);
	GXSetNumTevStages(1);
	GXSetNumTexGens(0);
	GXSetTevOrder(GXTevStageID::GX_TEVSTAGE0, GXTexCoordID::GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
	GXSetCullMode(gx::GXCullMode::GX_CULL_NONE);
	GXLoadPosMtxImm(this->mMtx, 0);

	C_MTXIdentity(MStack56);
	//mtx::PSMTXIdentity(MStack56);

	GXLoadTexMtxImm(MStack56, GX_IDENTITY, GXTexMtxType::GX_MTX3x4);
	GXSetChanCtrl(GX_COLOR0A0, false, GX_SRC_REG, GX_SRC_VTX, 0, GX_DF_NONE, GX_AF_NONE);
	GXSetChanCtrl(GX_COLOR1A1, false, GX_SRC_REG, GX_SRC_REG, 0, GX_DF_NONE, GX_AF_NONE);
	GXSetCurrentMtx(0);
	GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, false, GX_PTIDENTITY);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_CLR_RGBA, GX_RGBA4, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_CLR_RGBA, GX_RGBX8, 0xf);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX1, GX_CLR_RGBA, GX_RGBX8, 0xf);
	GXSetLineWidth(this->mLineWidth, GXTexOffset::GX_TO_ZERO);
	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	GXSetVtxDesc(GX_VA_TEX0, GX_NONE);
}

void J2DGrafContext::setPort() {
	double dVar1;
	double dVar2;

	setScissor();
	setup2D();
	dVar2 = (this->mViewport).mTL[1];
	dVar1 = (this->mViewport).mTL[0];
	gx::GXSetViewport(dVar1, dVar2, (this->mViewport).mBR[0] - dVar1,
					  (this->mViewport).mBR[1] - dVar2, 0, 1.0);
}

void J2DGrafContext::place(TBox2<float> *pPos) {
	float fVar1;

	fVar1 = (pPos->mTL)[1];
	(this->mViewport).mTL[0] = (pPos->mTL)[0];
	(this->mViewport).mTL[1] = fVar1;
	fVar1 = (pPos->mBR)[1];
	(this->mViewport).mBR[0] = (pPos->mBR)[0];
	(this->mViewport).mBR[1] = fVar1;
	fVar1 = (pPos->mTL)[1];
	(this->mScissor).mTL[0] = (pPos->mTL)[0];
	(this->mScissor).mTL[1] = fVar1;
	fVar1 = (pPos->mBR)[1];
	(this->mScissor).mBR[0] = (pPos->mBR)[0];
	(this->mScissor).mBR[1] = fVar1;
}

void J2DGrafContext::place(float param_1, float param_2, float param_3, float param_4) {
	float local_18;
	float local_14;
	float local_10;
	float local_c;

	local_10 = param_1 + param_3;
	local_c = param_2 + param_4;
	local_18 = param_1;
	local_14 = param_2;
	place((TBox2<float> *)&local_18);
}

J2DTypeID J2DGrafContext::getGrafType() {
	return J2DTypeID::J2DGrafContext;
}

void J2DGrafContext::setLookat() {
}

void J2DGrafContext::fillBox(TBox2<float> *param_1) {
	gx::GXSetBlendMode(this->mBoxBlendMode, this->mBoxBlendSrc, this->mBoxBlendDst, gx::GX_LO_SET);
	gx::GXLoadPosMtxImm(this->mMtx, 0);
	gx::GXSetVtxAttrFmt(gx::GX_VTXFMT0, gx::GX_VA_POS, gx::GX_CLR_RGBA, gx::GX_F32, 0);
	gx::GXBegin(gx::GX_QUADS, gx::GX_VTXFMT0, 4);

	void write_volatile_4(uint, ...);

	write_volatile_4(0xcc008000, (param_1->mTL)[0]);
	write_volatile_4(0xcc008000, (param_1->mTL)[1]);
	write_volatile_4(0xcc008000, 0.0);
	write_volatile_4(0xcc008000, this->mColorTL);

	write_volatile_4(0xcc008000, (param_1->mBR)[0]);
	write_volatile_4(0xcc008000, (param_1->mTL)[1]);
	write_volatile_4(0xcc008000, 0.0);
	write_volatile_4(0xcc008000, this->mColorTR);

	write_volatile_4(0xcc008000, (param_1->mBR)[0]);
	write_volatile_4(0xcc008000, (param_1->mBR)[1]);
	write_volatile_4(0xcc008000, 0.0);
	write_volatile_4(0xcc008000, this->mColorBL);

	write_volatile_4(0xcc008000, (param_1->mTL)[0]);
	write_volatile_4(0xcc008000, (param_1->mBR)[1]);
	write_volatile_4(0xcc008000, 0.0);
	write_volatile_4(0xcc008000, this->mColorBR);
	gx::GXSetVtxAttrFmt(gx::GX_VTXFMT0, gx::GX_VA_POS, gx::GX_CLR_RGBA, gx::GX_RGBA4, 0);
}

void J2DGrafContext::setColor(TColor param_1, TColor param_2, TColor param_3, TColor param_4) {
	(this->mColorTL).r = *(u8 *)param_1;
	(this->mColorTL).g = *(u8 *)(param_1 + 1);
	(this->mColorTL).b = *(u8 *)(param_1 + 2);
	(this->mColorTL).a = *(u8 *)(param_1 + 3);
	(this->mColorTR).r = *(u8 *)param_2;
	(this->mColorTR).g = *(u8 *)(param_2 + 1);
	(this->mColorTR).b = *(u8 *)(param_2 + 2);
	(this->mColorTR).a = *(u8 *)(param_2 + 3);
	(this->mColorBR).r = *(u8 *)param_3;
	(this->mColorBR).g = *(u8 *)(param_3 + 1);
	(this->mColorBR).b = *(u8 *)(param_3 + 2);
	(this->mColorBR).a = *(u8 *)(param_3 + 3);
	(this->mColorBL).r = *(u8 *)param_4;
	(this->mColorBL).g = *(u8 *)(param_4 + 1);
	(this->mColorBL).b = *(u8 *)(param_4 + 2);
	(this->mColorBL).a = *(u8 *)(param_4 + 3);
	this->a = 1;
	this->b = 4;
	this->c = 5;
	this->mLineBlendMode = 1;
	this->mLineBlendSrc = 4;
	this->mLineBlendDst = 5;
	this->mBoxBlendMode = gx::GX_BM_BLEND;
	this->mBoxBlendSrc = gx::GX_BL_SRCALPHA;
	this->mBoxBlendDst = gx::GX_BL_INVSRCALPHA;
	if (((uint)this->mColorTL.a & 0xff) != 0xff) {
		return;
	}
	this->a = 0;
	this->b = 1;
	this->c = 0;
	if (((uint)this->mColorBR.a & 0xff) != 0xff) {
		return;
	}
	this->mLineBlendMode = 0;
	this->mLineBlendSrc = 1;
	this->mLineBlendDst = 0;
	if (((uint)this->mColorTR.a & 0xff) != 0xff) {
		return;
	}
	if (((uint)this->mColorBL.a & 0xff) != 0xff) {
		return;
	}
	this->mBoxBlendMode = gx::GX_BM_NONE;
	this->mBoxBlendSrc = gx::GX_BL_ONE;
	this->mBoxBlendDst = gx::GX_BL_ZERO;
	return;
}

void J2DGrafContext::setLineWidth(byte param_1) {
	this->mLineWidth = param_1;
	gx::GXSetLineWidth(this->mLineWidth, gx::_GXTexOffset::GX_TO_ZERO);
}

void J2DGrafContext::drawFrame(TBox2<float> *param_1) {
	using namespace gx;

	gx::GXSetBlendMode(this->mBoxBlendMode, this->mBoxBlendSrc, this->mBoxBlendDst,
					   GX_LO_SET);
	gx::GXLoadPosMtxImm(this->mMtx, 0);
	gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_CLR_RGBA, GX_F32, 0);
	gx::GXBegin(GXPrimitive::GX_LINESTRIP, GXVtxFmt::GX_VTXFMT0, 5);

	void write_volatile_4(u32, ...);
	write_volatile_4(0xcc008000, (param_1->mTL)[0]);
	write_volatile_4(0xcc008000, (param_1->mTL)[1]);
	write_volatile_4(0xcc008000, 0.0);
	write_volatile_4(0xcc008000, this->mColorTL);

	write_volatile_4(0xcc008000, (param_1->mBR)[0]);
	write_volatile_4(0xcc008000, (param_1->mTL)[1]);
	write_volatile_4(0xcc008000, 0.0);
	write_volatile_4(0xcc008000, this->mColorTR);

	write_volatile_4(0xcc008000, (param_1->mBR)[0]);
	write_volatile_4(0xcc008000, (param_1->mBR)[1]);
	write_volatile_4(0xcc008000, 0.0);
	write_volatile_4(0xcc008000, this->mColorBL);

	write_volatile_4(0xcc008000, (param_1->mTL)[0]);
	write_volatile_4(0xcc008000, (param_1->mBR)[1]);
	write_volatile_4(0xcc008000, 0.0);
	write_volatile_4(0xcc008000, this->mColorBR);

	write_volatile_4(0xcc008000, (param_1->mTL)[0]);
	write_volatile_4(0xcc008000, (param_1->mTL)[1]);
	write_volatile_4(0xcc008000, 0.0);
	write_volatile_4(0xcc008000, this->mColorTL);
	gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_CLR_RGBA, GX_RGBA4, 0);
	return;
}

J2DGrafContext::J2DGrafContext(float param_1, float param_2, float param_3, float param_4) {
	undefined4 local_24;
	undefined4 local_20;
	undefined4 local_1c;
	undefined4 local_18;
	undefined4 local_14;

	(this->mViewport).mTL[0] = param_1;
	(this->mViewport).mTL[1] = param_2;
	(this->mViewport).mBR[0] = param_1 + param_3;
	(this->mViewport).mBR[1] = param_2 + param_4;
	(this->mScissor).mTL[0] = param_1;
	(this->mScissor).mTL[1] = param_2;
	(this->mScissor).mBR[0] = param_1 + param_3;
	(this->mScissor).mBR[1] = param_2 + param_4;
	local_14 = 0xffffffff;
	this->mColorTL = *(gx::GXColor *)&local_14;
	this->mColorTR = *(gx::GXColor *)&local_14;
	this->mColorBR = *(gx::GXColor *)&local_14;
	this->mColorBL = *(gx::GXColor *)&local_14;
	local_18 = 0xffffffff;
	local_1c = 0xffffffff;
	local_20 = 0xffffffff;
	local_24 = 0xffffffff;
	setColor((TColor)&local_24, (TColor)&local_20, (TColor)&local_1c, (TColor)&local_18);
	setLineWidth(6);
}
