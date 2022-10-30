#include "JFWDisplay.h"

#include <GLFW/glfw3.h>

#include <cstdio>

#include "JFWSystem.h"

JFWDisplay *JFWDisplay::sManager;

uint JFWDisplay::getFrameRate() {
	return this->currentFrameRate;
}

void JFWDisplay::setFrameRate(ushort param_1) {
	this->currentFrameRate = param_1;
	this->targetFrameRateReached = 0;
}

JFWDisplay *JFWDisplay::getManager() {
	return JFWDisplay::sManager;
}

void JFWDisplay::clearEfb(gx::GXColor *param_1) {
	gx::GXColor local_8[2];

	local_8[0] = *param_1;
	clearEfb(0, 0, (uint)this->rendermodeptr->fbWidth, (uint)this->rendermodeptr->efbHeight,
			 local_8);
}

void JFWDisplay::drawendXfb_single() {
	JUTXfb *pJVar1;

	pJVar1 = JUTXfb::sManager;
	if (-1 < (short)JUTXfb::sManager->idx0) {
		prepareCopyDisp();
		JFramework::JFWGXDrawDoneAutoAbort();
		gx::GXFlush();
		pJVar1->idx1 = pJVar1->idx0;
	}
}

void JFWDisplay::waitBlanking(int param_1) {
	bool bVar1;

	while (bVar1 = 0 < param_1, param_1 = param_1 + -1, bVar1) {
		JFramework::waitForTick(this->targetFrameRateReached, this->currentFrameRate);
	}
}

void JFWDisplay::copyXfb_triple() {
	short sVar1;
	JUTXfb *pJVar2;
	void *puVar3;

	pJVar2 = JUTXfb::sManager;
	if (-1 < (short)JUTXfb::sManager->idx0) {
		prepareCopyDisp();
		sVar1 = pJVar2->idx0;
		if (sVar1 < 0) {
			puVar3 = (undefined *)0x0;
		} else {
			puVar3 = pJVar2->xfbs[sVar1];
		}
		gx::GXCopyDisp(puVar3, 1);
		gx::GXPixModeSync();
	}
}

JFWDisplay::~JFWDisplay() {
	waitBlanking(2);
	JUTProcBar::destroy();
	JUTXfb::destroyManager();
}

JFWDisplay::JFWDisplay(gx::GXRenderModeObj *param_1, JKRHeap *param_2, EXfbNumber param_3, bool param_4) {
	JUTXfb *pJVar1;

	this->clearColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	ctor_subroutine(param_1, param_4);
	pJVar1 = JUTXfb::createManager(param_1, param_2, param_3);
	this->xfbmanager = pJVar1;
}

// Sleep >UNTIL< the absolute time param_1
void JFWDisplay::threadSleep(os::OSTime param_1) {
	// holy degenerate
	undefined4 uVar1;

	struct {
		os::OSAlarm alarm;
		os::OSThread *thread;
	} bepis;
	bepis.thread = os::OSGetCurrentThread();
	os::OSCreateAlarm(&bepis.alarm);
	uVar1 = os::OSDisableInterrupts();
	os::OSSetAlarm(&bepis.alarm, param_1, JFramework::JFWThreadAlarmHandler);
	os::OSSuspendThread(bepis.thread);
	os::OSRestoreInterrupts(uVar1);
}

void JFWDisplay::clearEfb_init() {
	using namespace gx;
	gx::GXInitTexObj(&JFramework::clear_z_tobj, &JFramework::clear_z_TX, 4, 4, GX_TF_Z24X8, GX_REPEAT, GX_REPEAT, false);
	gx::GXInitTexObjLOD(&JFramework::clear_z_tobj, GXTexFilter::GX_NEAR, GXTexFilter::GX_NEAR, 0, 0, 0, false, false, GXAnisotropy::GX_ANISO_1);
}

void JFWDisplay::exchangeXfb_triple() {
	JUTXfb *pJVar1;
	short sVar2;

	pJVar1 = JUTXfb::sManager;
	if (-1 < (short)JUTXfb::sManager->idx0) {
		JFramework::callDirectDraw();
	}
	pJVar1->idx1 = pJVar1->idx0;
	sVar2 = pJVar1->idx0 + 1;
	do {
		if ((2 < sVar2) || (sVar2 < 0)) {
			sVar2 = 0;
		}
	} while (sVar2 == pJVar1->idx2);
	pJVar1->idx0 = sVar2;
}

void JFWDisplay::calcCombinationRatio() {
	uint uVar1;
	int iVar2;
	int iVar3;

	iVar2 = this->elapsedticks;
	for (iVar3 = JUTVideo::sVideoInterval; iVar3 < iVar2 * 2; iVar3 = iVar3 + JUTVideo::sVideoInterval) {
	}
	uVar1 = (iVar3 + iVar2 * -2) - this->elapsedtickssincevideo;
	if ((int)uVar1 < 0) {
		uVar1 = uVar1 + JUTVideo::sVideoInterval;
	}
	this->combRatio = (float)uVar1 / iVar2;
	if (1.0 < this->combRatio) {
		this->combRatio = 1.0;
	}
}

void JFWDisplay::preGX() {
	using namespace gx;
	gx::GXInvalidateTexAll();
	gx::GXInvalidateVtxCache();
	if (this->rendermodeptr->sample_pattern[0][1] == 0) {
		if (this->shouldUpdateAlpha == false) {
			gx::GXSetPixelFmt(GX_PF_RGB8_Z24, GX_ZC_LINEAR);
			gx::GXSetDither(0);
		} else {
			gx::GXSetPixelFmt(GX_PF_RGBA6_Z24, GX_ZC_LINEAR);
			gx::GXSetDither(1);
		}
	} else {
		gx::GXSetPixelFmt(GX_PF_RGB565_Z16, GX_ZC_LINEAR);
		gx::GXSetDither(1);
	}
}

void JFWDisplay::endRender() {
	JUTProcBar *pJVar1;
	int iVar2;
	uint uVar3;

	endGX();
	iVar2 = JUTXfb::sManager->xfbnum;
	if (iVar2 != 2) {
		if (iVar2 < 2) {
			if (0 < iVar2) {
				drawendXfb_single();
			}
		} else if (iVar2 < 4) {
			copyXfb_triple();
		}
	}
	pJVar1 = JUTProcBar::sManager;
	JUTProcBar::sManager->colorb[0] = 0xff;
	pJVar1->colorb[1] = 0x81;
	pJVar1->colorb[2] = 0x1e;
	uVar3 = os::OSGetTick();
	pJVar1->ticks = uVar3;
	calcCombinationRatio();
}

void JFWDisplay::ctor_subroutine(gx::GXRenderModeObj *rendermode, bool param_2) {
	uint uVar1;
	JUTProcBar *pJVar2;

	this->shouldUpdateAlpha = param_2;
	this->gxClampSetting = (gx::GXFBClamp)3;  //???
	(this->clearColor).r = 0;
	(this->clearColor).g = 0;
	(this->clearColor).b = 0;
	(this->clearColor).a = 0;
	this->zclear = 0xffffff;
	if (!rendermode) {
		rendermode = JUTVideo::sManager->mpRenderMode;
	}
	this->rendermodeptr = rendermode;
	this->gxGammaCopySetting = gx::GXGamma::GX_GM_1_0;
	this->mpFader = (JUTFader *)0x0;
	this->currentFrameRate = 1;
	this->targetFrameRateReached = 0;
	this->combRatio = 0.0;
	this->elapsedticks = 0;
	uVar1 = os::OSGetTick();
	this->ticks = uVar1;
	this->elapsedtickssincevideo = 0;
	this->xfbidx = 0;
	this->field_0x3e = 0;
	this->shoulddraw = 0;
	clearEfb_init();
	pJVar2 = JUTProcBar::create();
	pJVar2->clear();
}

void JFWDisplay::prepareCopyDisp() {
	ushort uVar1;
	ushort uVar2;
	ushort uVar3;
	gx::GXRenderModeObj *pGVar4;
	undefined8 uVar5;
	gx::GXColor local_28;

	pGVar4 = JUTVideo::sManager->mpRenderMode;
	uVar1 = pGVar4->fbWidth;
	uVar2 = pGVar4->efbHeight;
	uVar3 = pGVar4->xfbHeight;
	uVar5 = gx::GXGetYScaleFactor(uVar2, uVar3);
	local_28 = this->clearColor;
	gx::GXSetCopyClear(local_28, this->zclear);
	gx::GXSetDispCopySrc(0, 0, uVar1, uVar2);
	gx::GXSetDispCopyDst(uVar1, uVar3);
	gx::GXSetDispCopyYScale(uVar5);
	vi::VIFlush();
	gx::GXSetCopyFilter(pGVar4->aa, pGVar4->sample_pattern, true, pGVar4->vfilter);
	//gx::GXSetCopyFilter(pGVar4->pattern[0][1], pGVar4->pattern + 2, 1, pGVar4->filter + 2);
	gx::GXSetCopyClamp(this->gxClampSetting);
	gx::GXSetDispCopyGamma(this->gxGammaCopySetting);
	gx::GXSetZMode(true, gx::GX_LEQUAL, true);
	if (this->shouldUpdateAlpha != false) {
		gx::GXSetAlphaUpdate(1);
	}
}

void JFWDisplay::exchangeXfb_double() {
	ushort uVar1;
	JUTXfb *pJVar2;
	gx::GXColor local_18[4];

	pJVar2 = JUTXfb::sManager;
	void *puVar3;
	if (JUTXfb::sManager->idx1 == JUTXfb::sManager->idx2) {
		if (-1 < (short)JUTXfb::sManager->idx0) {
			prepareCopyDisp();
			if ((short)pJVar2->idx0 < 0) {
				puVar3 = (undefined *)0x0;
			} else {
				puVar3 = pJVar2->xfbs[pJVar2->idx0];
			}

			gx::GXCopyDisp(puVar3, 1);
			if (this->shoulddraw == 0) {
				gx::GXDrawDone();
				JUTVideo::dummyNoDrawWait();
			} else {
				JUTVideo::drawDoneStart();
			}
			if (this->shoulddraw == 0) {
				JFramework::callDirectDraw();
			}
		}
		uVar1 = pJVar2->idx0;
		pJVar2->idx1 = uVar1;
		pJVar2->idx0 = (uVar1 ^ 1) & -((short)uVar1 >> 0xf) - 1U;
	} else {
		local_18[0] = this->clearColor;
		clearEfb(local_18);
		if ((short)pJVar2->idx0 < 0) {
			pJVar2->idx0 = 0;
		}
	}
}

namespace vi {
	namespace hw_thread {
		extern GLFWwindow *window;
	}
}

void JFWDisplay::endGX() {
	JUTProcBar *this_00;
	uint uStack28;
	uint uStack20;

	struct J2DOrthoGraph local_f8(0.0, 0.0,
								  JUTVideo::sManager->mpRenderMode->fbWidth,
								  JUTVideo::sManager->mpRenderMode->efbHeight, -1.0, 1.0);
	if (this->mpFader != (JUTFader *)0x0) {
		local_f8.setPort();
		this->mpFader->control();
	}
	local_f8.setPort();
	JUTDbPrint::sDebugPrint->flush();
	if (JUTConsoleManager::sManager) {
		local_f8.setPort();
		JUTConsoleManager::sManager->draw();
	}
	local_f8.setPort();
	JUTProcBar::sManager->draw();
	if ((this->shoulddraw) || (JUTXfb::sManager->xfbnum == 1)) {
		//JUTAssertion::flushMessage_dbPrint((JUTAssertion *)this_00);
	}
#ifndef DOLPHIN
	glfwSwapBuffers(vi::hw_thread::window);
#endif
	gx::GXFlush();
}

void JFWDisplay::endFrame() {
	JUTProcBar *pJVar2;
	int iVar3;
	uint uVar4;
	JUTProcBar *pJVar1;

	pJVar1 = JUTProcBar::sManager;
	iVar3 = os::OSGetTick();

	//pJVar1->field35_0x2c = ((iVar3 - pJVar1->ticks) * 8) / ((162000000 >> 2) / 0x1e848);
	//if (pJVar1->field35_0x2c == 0) {
	//	pJVar1->field35_0x2c = 1;
	//}

	pJVar2 = JUTProcBar::sManager;
	//JUTProcBar::sManager->field_0x4c = 0xff;
	//pJVar2->field_0x4d = 0x81;
	//pJVar2->field_0x4e = 0x1e;
	//uVar4 = os::OSGetTick();
	//pJVar2->field48_0x3c = uVar4;
	iVar3 = JUTXfb::sManager->xfbnum;
	if (iVar3 == 2) {
		JFramework::JFWGXDrawDoneAutoAbort();
		gx::GXFlush();
	} else if ((1 < iVar3) && (iVar3 < 4)) {
		JFramework::JFWGXDrawDoneAutoAbort();
		gx::GXFlush();
	}
	pJVar2 = JUTProcBar::sManager;
	iVar3 = os::OSGetTick();

	//*(uint *)&pJVar2->field_0x40 =
	//	((iVar3 - pJVar2->field48_0x3c) * 8) / ((162000000 >> 2) / 0x1e848);
	//if (*(int *)&pJVar2->field_0x40 == 0) {
	//	*(undefined4 *)&pJVar2->field_0x40 = 1;
	//}

	pJVar2 = JUTProcBar::sManager;
	iVar3 = os::OSGetTick();

	// *(uint *)&pJVar2->field_0x18 =
	// 	(uint)((iVar3 - *(int *)&pJVar2->field_0x14) * 8) / ((162000000 >> 2) / 0x1e848);
	// if (*(int *)&pJVar2->field_0x18 == 0) {
	// 	*(undefined4 *)&pJVar2->field_0x18 = 1;
	// }

	if (JFramework::init$2525 == '\0') {
		JFramework::prevFrame$2524 = vi::VIGetRetraceCount();
		JFramework::init$2525 = '\x01';
	}
	iVar3 = vi::VIGetRetraceCount();

	//*(int *)&JUTProcBar::sManager->field_0x104 = iVar3 - JFramework::prevFrame$2524;

	JFramework::prevFrame$2524 = iVar3;
}

void JFWDisplay::beginRender() {
	JUTXfb *pJVar1;
	JUTProcBar *pJVar4;
	int iVar5;
	uint uVar6;
	undefined4 uVar7;
	gx::GXColor local_18[4];
	JUTProcBar *pJVar3;
	JUTProcBar *pJVar2;

	pJVar2 = JUTProcBar::sManager;
	iVar5 = os::OSGetTick();

	/*
		pJVar2->field66_0x54 =
			(uint)((iVar5 - pJVar2->field65_0x50) * 8) / ((162000000 >> 2) / 0x1e848);
		if (pJVar2->field66_0x54 == 0) {
			pJVar2->field66_0x54 = 1;
		}
		pJVar4 = JUTProcBar::sManager;
		JUTProcBar::sManager->field_0x60 = 0xff;
		pJVar4->field_0x61 = 0x81;
		pJVar4->field_0x62 = 0x1e;
		iVar5 = os::OSGetTick();
		pJVar4->field65_0x50 = iVar5;
		pJVar4 = JUTProcBar::sManager;
		JUTProcBar::sManager->field_0x10 = 0xff;
		pJVar4->field_0x11 = 0x81;
		pJVar4->field_0x12 = 0x1e;
		iVar5 = os::OSGetTick();
		pJVar4->field0_0x0 = iVar5;
		*/

	JFramework::waitForTick(this->targetFrameRateReached, this->currentFrameRate);
	vi::VIWaitForRetrace();
	JUTVideo::sManager->waitRetraceIfNeed();
	uVar6 = os::OSGetTick();
	this->elapsedticks = uVar6 - this->ticks;
	this->ticks = uVar6;
	this->elapsedtickssincevideo = this->ticks - JUTVideo::sVideoLastTick;
	pJVar4 = JUTProcBar::sManager;
	iVar5 = os::OSGetTick();
	/*
		pJVar4->field1_0x4 = (uint)((iVar5 - pJVar4->field0_0x0) * 8) / ((162000000 >> 2) / 0x1e848);
		if (pJVar4->field1_0x4 == 0) {
			pJVar4->field1_0x4 = 1;
		}
		pJVar4 = JUTProcBar::sManager;
		JUTProcBar::sManager->field_0x24 = 0xff;
		pJVar4->field_0x25 = 0x81;
		pJVar4->field_0x26 = 0x1e;
		uVar7 = os::OSGetTick();
		*(undefined4 *)&pJVar4->field_0x14 = uVar7;
		*/
	pJVar1 = JUTXfb::sManager;
	iVar5 = JUTXfb::sManager->xfbnum;
	if (iVar5 == 2) {
		exchangeXfb_double();
	} else if (iVar5 < 2) {
		if (0 < iVar5) {
			if (JUTXfb::sManager->renderStatus == 2) {
				JUTXfb::sManager->renderStatus = 1;
			} else {
				JUTXfb::sManager->renderStatus = 1;
				local_18[0] = this->clearColor;
				clearEfb(local_18);
			}
			pJVar1->idx0 = this->xfbidx;
		}
	} else if (iVar5 < 4) {
		exchangeXfb_triple();
	}
	preGX();
}

void JFWDisplay::clearEfb(int param_1, int param_2, int param_3, int param_4, gx::GXColor *param_5) {
	ushort uVar1;
	ushort uVar2;
	short sVar3;
	short sVar4;
	short sVar5;
	MTX44 MStack132;

	using namespace gx;
	mtx::MTXOrtho(MStack132, 0.0, this->rendermodeptr->efbHeight, 0.0, this->rendermodeptr->fbWidth, 0.0, 1.0);
	gx::GXSetProjection(MStack132, gx::GX_ORTHOGRAPHIC);
	gx::GXSetViewport(0, 0, this->rendermodeptr->fbWidth, this->rendermodeptr->efbHeight, 0.0, 1.0);
	gx::GXSetScissor(0, 0, this->rendermodeptr->fbWidth, this->rendermodeptr->efbHeight);
	gx::GXLoadPosMtxImm(JFramework::e_mtx, 0);
	gx::GXSetCurrentMtx(0);
	gx::GXClearVtxDesc();
	gx::GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	gx::GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
	// Vertex format is 2 short for position + 2 bytes for ST texture coordinates
	gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XY, GX_U16, 0);
	gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_U8, 0);
	gx::GXSetNumChans(0);
	gx::GXSetChanCtrl(GX_COLOR0A0, false, GX_SRC_REG, GX_SRC_REG, 0, GX_DF_NONE, GX_AF_NONE);
	gx::GXSetChanCtrl(GX_COLOR1A1, false, GX_SRC_REG, GX_SRC_REG, 0, GX_DF_NONE, GX_AF_NONE);
	gx::GXSetNumTexGens(1);
	gx::GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, false, GX_PTIDENTITY);
	gx::GXLoadTexObj(&JFramework::clear_z_tobj, GX_TEXMAP0);
	gx::GXSetNumTevStages(1);
	gx::GXSetTevColor(GX_TEVREG0, *param_5);
	gx::GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
	gx::GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_C0);
	gx::GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
	gx::GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_A0);
	gx::GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
	gx::GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
	gx::GXSetZTexture(GX_ZT_REPLACE, GXTexFmt::GX_TF_Z24X8, 0);
	gx::GXSetZCompLoc(0);
	gx::GXSetBlendMode(GX_BM_NONE, GX_BL_ZERO, GX_BL_ZERO, GX_LO_NOOP);
	if (this->shouldUpdateAlpha != false) {
		gx::GXSetAlphaUpdate(1);
		gx::GXSetDstAlpha(1, 0);
	}
	gx::GXSetZMode(true, GX_ALWAYS, true);
	gx::GXSetCullMode(gx::GXCullMode::GX_CULL_BACK);
	gx::GXBegin(GX_QUADS, GXVtxFmt::GX_VTXFMT0, 4);
	sVar5 = (short)param_1;

	// Vertex format is 2 short for position + 2 bytes for ST texture coordinates
	gx::GXPosition2s16(param_1, param_2);
	gx::GXTexCoord2u8(0, 0);

	sVar3 = sVar5 + (short)param_3;
	gx::GXPosition2s16(sVar3, sVar4);
	gx::GXTexCoord2u8(1, 0);

	sVar4 = sVar4 + (short)param_4;
	gx::GXPosition2s16(sVar3, sVar4);
	gx::GXTexCoord2u8(1, 1);

	gx::GXPosition2s16(sVar5, sVar4);
	gx::GXTexCoord2u8(0, 1);

	gx::GXSetZTexture(GX_ZT_DISABLE, GXTexFmt::GX_TF_Z24X8, 0);
	gx::GXSetZCompLoc(1);
	if (this->shouldUpdateAlpha != false) {
		gx::GXSetDstAlpha(0, 0);
	}

	// Supposedly, GXEnd should be called here?
}

JFWDisplay *JFWDisplay::createManager(JKRHeap *param_1, EXfbNumber param_2, bool param_3) {
	uint uVar1;
	JUTAssertion *ass;
	JFWDisplay *ret;

	ass = JUTAssertion::getSDevice();
	ass->setConfirmMessage("JFWDisplay.cpp", 0xf3, !!JFWDisplay::sManager, "sManager == 0");
	ret = JFWDisplay::sManager;
	if (JFWDisplay::sManager == nullptr) {
		ret = new JFWDisplay(nullptr, param_1, param_2, param_3);
	}
	JFWDisplay::sManager = ret;
	return JFWDisplay::sManager;
}
