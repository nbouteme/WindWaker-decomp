#include "J3DSys.h"

void J3DSys::reinitTexture() {
	using namespace gx;
	GXTexObj GStack40;

	gx::GXInitTexObj(&GStack40, &J3DGraphBase::NullTexData, 4, 4, GX_TF_IA8, GX_CLAMP, GX_CLAMP, false);
	gx::GXLoadTexObj(&GStack40, GXTexMapID::GX_TEXMAP0);
	gx::GXLoadTexObj(&GStack40, GXTexMapID::GX_TEXMAP1);
	gx::GXLoadTexObj(&GStack40, GXTexMapID::GX_TEXMAP2);
	gx::GXLoadTexObj(&GStack40, GXTexMapID::GX_TEXMAP3);
	gx::GXLoadTexObj(&GStack40, GXTexMapID::GX_TEXMAP4);
	gx::GXLoadTexObj(&GStack40, GXTexMapID::GX_TEXMAP5);
	gx::GXLoadTexObj(&GStack40, GXTexMapID::GX_TEXMAP6);
	gx::GXLoadTexObj(&GStack40, GXTexMapID::GX_TEXMAP7);
}

void J3DSys::reinitGenMode() {
	gx::GXSetNumChans(0);
	gx::GXSetNumTexGens(1);
	gx::GXSetNumTevStages(1);
	gx::GXSetNumIndStages(0);
	gx::GXSetCullMode(gx::GXCullMode::GX_CULL_BACK);
	gx::GXSetCoPlanar(0);
}

namespace J3DGraphBase {
	gx::GXColor ColorBlack = {0, 0, 0, 0};
	gx::GXColor ColorWhite = {0xff, 0xff, 0xff, 0xff};
}

void J3DSys::reinitLighting() {
	using namespace gx;

	gx::GXSetChanCtrl(GX_COLOR0A0, false, GX_SRC_REG, GX_SRC_VTX, 0, GX_DF_NONE, GX_AF_NONE);
	gx::GXSetChanCtrl(GX_COLOR1A1, false, GX_SRC_REG, GX_SRC_VTX, 0, GX_DF_NONE, GX_AF_NONE);

	gx::GXSetChanAmbColor(GXChannelID::GX_COLOR0A0, J3DGraphBase::ColorBlack);
	gx::GXSetChanAmbColor(GXChannelID::GX_COLOR1A1, J3DGraphBase::ColorBlack);
	gx::GXSetChanMatColor(GXChannelID::GX_COLOR0A0, J3DGraphBase::ColorWhite);
	gx::GXSetChanMatColor(GXChannelID::GX_COLOR1A1, J3DGraphBase::ColorWhite);
}

void J3DSys::reinitTransform() {
	using namespace gx;
	gx::GXSetCurrentMtx(0);
	gx::GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, false, GX_PTIDENTITY);
	gx::GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX2x4, GX_TG_TEX1, GX_IDENTITY, false, GX_PTIDENTITY);
	gx::GXSetTexCoordGen2(GX_TEXCOORD2, GX_TG_MTX2x4, GX_TG_TEX2, GX_IDENTITY, false, GX_PTIDENTITY);
	gx::GXSetTexCoordGen2(GX_TEXCOORD3, GX_TG_MTX2x4, GX_TG_TEX3, GX_IDENTITY, false, GX_PTIDENTITY);
	gx::GXSetTexCoordGen2(GX_TEXCOORD4, GX_TG_MTX2x4, GX_TG_TEX4, GX_IDENTITY, false, GX_PTIDENTITY);
	gx::GXSetTexCoordGen2(GX_TEXCOORD5, GX_TG_MTX2x4, GX_TG_TEX5, GX_IDENTITY, false, GX_PTIDENTITY);
	gx::GXSetTexCoordGen2(GX_TEXCOORD6, GX_TG_MTX2x4, GX_TG_TEX6, GX_IDENTITY, false, GX_PTIDENTITY);
	gx::GXSetTexCoordGen2(GX_TEXCOORD7, GX_TG_MTX2x4, GX_TG_TEX7, GX_IDENTITY, false, GX_PTIDENTITY);
}

void J3DSys::reinitTevStages() {
	using namespace gx;
	GXTevStageID GVar1;

	gx::GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE2, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE3, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE4, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE5, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE6, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE7, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE8, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE9, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE10, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE11, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE12, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE13, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE14, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE15, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevColor(GX_TEVREG0, J3DGraphBase::ColorWhite);
	gx::GXSetTevColor(GX_TEVREG1, J3DGraphBase::ColorWhite);
	gx::GXSetTevColor(GX_TEVREG2, J3DGraphBase::ColorWhite);
	gx::GXSetTevKColor(GXTevKColorID::GX_KCOLOR0, J3DGraphBase::ColorWhite);
	gx::GXSetTevKColor(GXTevKColorID::GX_KCOLOR1, J3DGraphBase::ColorWhite);
	gx::GXSetTevKColor(GXTevKColorID::GX_KCOLOR2, J3DGraphBase::ColorWhite);
	gx::GXSetTevKColor(GXTevKColorID::GX_KCOLOR3, J3DGraphBase::ColorWhite);
	GVar1 = GX_TEVSTAGE0;
	do {
		gx::GXSetTevColorIn(GVar1, GX_CC_RASC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
		gx::GXSetTevColorOp(GVar1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
		gx::GXSetTevAlphaIn(GVar1, GX_CA_RASA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
		gx::GXSetTevAlphaOp(GVar1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
		gx::GXSetTevKColorSel(GVar1, GXTevKColorSel::GX_TEV_KCSEL_2_8);
		gx::GXSetTevKAlphaSel(GVar1, GXTevKAlphaSel::GX_TEV_KASEL_8_8);
		gx::GXSetTevSwapMode(GVar1, GXTevSwapSel::GX_TEV_SWAP0, GXTevSwapSel::GX_TEV_SWAP0);
		GVar1 = (GXTevStageID)(GVar1 + GX_TEVSTAGE1);
	} while (GVar1 < GX_MAX_TEVSTAGE);
	gx::GXSetTevSwapModeTable(GX_TEV_SWAP0, GX_CH_RED, GX_CH_GREEN, GX_CH_BLUE, GX_CH_ALPHA);
	gx::GXSetTevSwapModeTable(GX_TEV_SWAP1, GX_CH_RED, GX_CH_RED, GX_CH_RED, GX_CH_ALPHA);
	gx::GXSetTevSwapModeTable(GX_TEV_SWAP2, GX_CH_GREEN, GX_CH_GREEN, GX_CH_GREEN, GX_CH_ALPHA);
	gx::GXSetTevSwapModeTable(GX_TEV_SWAP3, GX_CH_BLUE, GX_CH_BLUE, GX_CH_BLUE, GX_CH_ALPHA);
	gx::GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_AND, GX_ALWAYS, 0);
}

void J3DSys::reinitIndStages() {
	using namespace gx;
	uint uVar1;

	uVar1 = 0;
	do {
		gx::GXSetTevDirect((GXTevStageID)uVar1);
		uVar1 = uVar1 + 1;
	} while (uVar1 < 0x10);

	gx::GXSetIndTexOrder(GX_INDTEXSTAGE0, GX_TEXCOORD0, GX_TEXMAP0);
	gx::GXSetIndTexOrder(GX_INDTEXSTAGE1, GX_TEXCOORD1, GX_TEXMAP1);
	gx::GXSetIndTexOrder(GX_INDTEXSTAGE2, GX_TEXCOORD2, GX_TEXMAP2);
	gx::GXSetIndTexOrder(GX_INDTEXSTAGE3, GX_TEXCOORD3, GX_TEXMAP3);
	gx::GXSetIndTexCoordScale(GX_INDTEXSTAGE0, GX_ITS_1, GX_ITS_1);
	gx::GXSetIndTexCoordScale(GX_INDTEXSTAGE1, GX_ITS_1, GX_ITS_1);
	gx::GXSetIndTexCoordScale(GX_INDTEXSTAGE2, GX_ITS_1, GX_ITS_1);
	gx::GXSetIndTexCoordScale(GX_INDTEXSTAGE3, GX_ITS_1, GX_ITS_1);
	gx::GXSetIndTexMtx(GX_ITM_0, (float(*)[3])J3DGraphBase::j3dIdentityMtx[3], 1);
	gx::GXSetIndTexMtx(GX_ITM_1, (float(*)[3])J3DGraphBase::j3dIdentityMtx[3], 1);
	gx::GXSetIndTexMtx(GX_ITM_2, (float(*)[3])J3DGraphBase::j3dIdentityMtx[3], 1);
	return;
}

void J3DSys::reinitPixelProc() {
	using namespace gx;

	gx::GXSetBlendMode(GX_BM_NONE, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
	gx::GXSetColorUpdate(true);
	gx::GXSetAlphaUpdate(1);
	gx::GXSetDither(1);
	gx::GXSetFog(GX_FOG_NONE, 0.0, 1.0, 0.1, 1.0, J3DGraphBase::ColorBlack);
	gx::GXSetFogRangeAdj(false, 0, nullptr);
	gx::GXSetZMode(true, GX_LEQUAL, true);
	gx::GXSetZCompLoc(1);
}

void J3DSys::reinitGX() {
	reinitGenMode();
	reinitLighting();
	reinitTransform();
	reinitTexture();
	reinitTevStages();
	reinitIndStages();
	reinitPixelProc();
}

void J3DSys::drawInit() {
	using namespace gx;
	undefined4 *puVar1;
	GXTevStageID GVar2;
	undefined4 uVar3;
	undefined4 *puVar4;
	undefined4 *puVar5;
	uint uVar6;
	byte bVar7;
	int iVar8;
	gx::GXColor local_40;
	gx::GXColor local_3c;
	undefined4 local_38;
	gx::GXColorS10 local_34;
	undefined4 local_30;
	float local_2c[7];

	gx::GXSetMisc(GX_MT_DL_SAVE_CONTEXT, 0);
	gx::GXInvalidateVtxCache();
	gx::GXSetCurrentMtx(0);
	gx::GXSetCullMode(gx::GXCullMode::GX_CULL_BACK);
	gx::GXSetCoPlanar(0);
	gx::GXSetClipMode(GXClipMode::GX_CLIP_ENABLE);
	gx::GXSetColorUpdate(true);
	gx::GXSetDither(1);
	gx::GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_NOOP);
	gx::GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_AND, GX_ALWAYS, 0);
	gx::GXSetZMode(true, GX_LEQUAL, true);
	gx::GXSetZCompLoc(1);
	gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_CLR_RGBA, GX_F32, 0);
	gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_CLR_RGB, GX_F32, 0);
	gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
	gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR1, GX_CLR_RGBA, GX_RGBA8, 0);
	gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_CLR_RGBA, GX_RGBA4, 7);
	gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX1, GX_CLR_RGBA, GX_RGBA4, 7);
	gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX2, GX_CLR_RGBA, GX_RGBA4, 7);
	gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX3, GX_CLR_RGBA, GX_RGBA4, 7);
	gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX4, GX_CLR_RGBA, GX_RGBA4, 7);
	gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX5, GX_CLR_RGBA, GX_RGBA4, 7);
	gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX6, GX_CLR_RGBA, GX_RGBA4, 7);
	gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX7, GX_CLR_RGBA, GX_RGBA4, 7);
	gx::GXSetNumIndStages(0);
	reinitTexture();
	gx::GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE2, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE3, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE4, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE5, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE6, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE7, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE8, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE9, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE10, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE11, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE12, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE13, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE14, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	gx::GXSetTevOrder(GX_TEVSTAGE15, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	uVar6 = 0;
	iVar8 = 0;
	do {
		gx::GXLoadTexMtxImm(J3DGraphBase::j3dIdentityMtx, iVar8 + GX_TEXMTX0, GXTexMtxType::GX_MTX3x4);
		uVar6 = uVar6 + 1;
		iVar8 = iVar8 + 3;
	} while (uVar6 < 10);

	float aaa[] = {1, 0, 0};

	for (bVar7 = 0; bVar7 < 3; bVar7 = bVar7 + 1) {
		gx::GXSetIndTexMtx((gx::GXIndTexMtxID)(bVar7 + GX_ITM_0), &aaa, 1);
	}
	//local_38 = 0xffffffff;
	local_3c = {0xff, 0xff, 0xff, 0xff};
	gx::GXSetChanMatColor(GXChannelID::GX_COLOR0A0, local_3c);
	gx::GXSetChanMatColor(GXChannelID::GX_COLOR1A1, local_3c);
	gx::GXSetNumChans(1);
	gx::GXSetNumTexGens(1);
	gx::GXSetNumTevStages(1);
	gx::GXSetChanCtrl(GX_COLOR0A0, false, GX_SRC_REG, GX_SRC_REG, 0, GX_DF_CLAMP, GX_AF_NONE);
	gx::GXSetChanCtrl(GX_COLOR1A1, false, GX_SRC_REG, GX_SRC_REG, 0, GX_DF_CLAMP, GX_AF_NONE);
	for (bVar7 = 0; bVar7 < 8; bVar7 = bVar7 + 1) {
		iVar8 = (uint)bVar7 * 4;
		gx::GXSetTexCoordGen2((gx::GXTexCoordID)bVar7,
							  (gx::GXTexGenType)J3DGraphBase::j3dDefaultTexCoordInfo[iVar8],	 // [0;10 ]
							  (gx::GXTexGenSrc)J3DGraphBase::j3dDefaultTexCoordInfo[iVar8 + 1],	 // [0; 20]
							  J3DGraphBase::j3dDefaultTexCoordInfo[iVar8 + 2],					 // u32
							  false, GX_PTIDENTITY);
	}
	for (bVar7 = 0; bVar7 < 4; bVar7 = bVar7 + 1) {
		gx::GXSetIndTexCoordScale((gx::GXIndTexStageID)bVar7, gx::GXIndTexScale::GX_ITS_1, gx::GXIndTexScale::GX_ITS_1);
	}
	for (bVar7 = 0; bVar7 < 4; bVar7 = bVar7 + 1) {
		local_40.r = local_40.g = local_40.b = local_40.a = 255;
		gx::GXSetTevKColor((gx::GXTevKColorID)bVar7, local_40);
	}
	for (bVar7 = 0; bVar7 < 4; bVar7 = bVar7 + 1) {
		//local_34 = 0xff00ff;
		local_30 = 0xff00ff;
		gx::GXSetTevColorS10((gx::GXTevRegID)bVar7, local_34);
	}
	for (bVar7 = 0; bVar7 < 0x10; bVar7 = bVar7 + 1) {
		GVar2 = (GXTevStageID)bVar7;
		gx::GXSetTevColorIn(GVar2, GX_CC_RASC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
		gx::GXSetTevColorOp(GVar2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
		gx::GXSetTevAlphaIn(GVar2, GX_CA_RASA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
		gx::GXSetTevAlphaOp(GVar2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
	}
	for (bVar7 = 0; bVar7 < 0x10; bVar7 = bVar7 + 1) {
		gx::GXSetTevSwapMode((gx::GXTevStageID)bVar7, gx::GXTevSwapSel::GX_TEV_SWAP0, gx::GXTevSwapSel::GX_TEV_SWAP0);
	}
	gx::GXSetTevSwapModeTable(gx::GXTevSwapSel::GX_TEV_SWAP0, GXTevColorChan::GX_CH_RED, GXTevColorChan::GX_CH_GREEN, GXTevColorChan::GX_CH_BLUE, GXTevColorChan::GX_CH_ALPHA);
	gx::GXSetTevSwapModeTable(gx::GXTevSwapSel::GX_TEV_SWAP1, GXTevColorChan::GX_CH_RED, GXTevColorChan::GX_CH_RED, GXTevColorChan::GX_CH_RED, GXTevColorChan::GX_CH_ALPHA);
	gx::GXSetTevSwapModeTable(gx::GXTevSwapSel::GX_TEV_SWAP2, GXTevColorChan::GX_CH_GREEN, GXTevColorChan::GX_CH_GREEN, GXTevColorChan::GX_CH_GREEN, GXTevColorChan::GX_CH_ALPHA);
	gx::GXSetTevSwapModeTable(gx::GXTevSwapSel::GX_TEV_SWAP3, GXTevColorChan::GX_CH_BLUE, GXTevColorChan::GX_CH_BLUE, GXTevColorChan::GX_CH_BLUE, GXTevColorChan::GX_CH_ALPHA);
	for (bVar7 = 0; bVar7 < 0x10; bVar7 = bVar7 + 1) {
		gx::GXSetTevIndirect((gx::GXTevStageID)bVar7,
							 gx::GXIndTexStageID::GX_INDTEXSTAGE0,
							 GXIndTexFormat::GX_ITF_8,
							 GXIndTexBiasSel::GX_ITB_NONE,
							 GXIndTexMtxID::GX_ITM_OFF,
							 GXIndTexWrap::GX_ITW_OFF, GXIndTexWrap::GX_ITW_OFF,
							 0, 0,
							 GXIndTexAlphaSel::GX_ITBA_OFF);
	}
	setTexCacheRegion(GXTexCacheSize::GX_TEXCACHE_32K);
}

void J3DSys::setTexCacheRegion(gx::GXTexCacheSize param_1) {
	// TODO
}

namespace J3DGraphBase {
	J3DSys j3dSys;
	MTX34 j3dIdentityMtx;
	void *NullTexData;

	byte j3dDefaultTexCoordInfo[] = {0x01, 0x04, 0x3c, 0x00, 0x01, 0x05, 0x3c, 0x00, 0x01, 0x06, 0x3c, 0x00, 0x01, 0x07, 0x3c, 0x00, 0x01, 0x08, 0x3c, 0x00, 0x01, 0x09, 0x3c, 0x00, 0x01, 0x0a, 0x3c, 0x00, 0x01, 0x0b, 0x3c, 0x00};
}