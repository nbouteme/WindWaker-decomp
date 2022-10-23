#pragma once

#include <dolphin/mtx.h>

#include "JKernel/JKRHeap.h"
#include "JUtility/JUTAssert.h"
#include "JUtility/JUTConsoleManager.h"
#include "JUtility/JUTFader.h"
#include "JUtility/JUTProcBar.h"
#include "JUtility/JUTXfb.h"

using EXfbNumber = int;

struct JFWDisplay {
	static JFWDisplay *sManager;

	JUTFader *mpFader;
	gx::GXRenderModeObj *rendermodeptr;
	gx::GXColor clearColor;
	uint zclear;
	JUTXfb *xfbmanager;
	gx::GXGamma gxGammaCopySetting;
	uint shoulddraw;
	ushort currentFrameRate;
	uint targetFrameRateReached;
	bool shouldUpdateAlpha;
	gx::GXFBClamp gxClampSetting;
	float combRatio;
	uint ticks, elapsedticks, elapsedtickssincevideo;
	ushort xfbidx;
	byte field_0x3e;

	static JFWDisplay *getManager();
	static JFWDisplay *createManager(JKRHeap *param_1, EXfbNumber param_2, bool param_3);

	JFWDisplay(gx::GXRenderModeObj *param_1, JKRHeap *param_2, EXfbNumber param_3, bool param_4);
	uint getFrameRate();
	void setFrameRate(ushort param_1);
	void clearEfb(gx::GXColor *param_1);
	void drawendXfb_single();
	void waitBlanking(int param_1);
	void copyXfb_triple();
	void threadSleep(os::OSTime param_1);
	void clearEfb_init();
	void exchangeXfb_triple();
	void calcCombinationRatio();
	void preGX();
	void endRender();
	void ctor_subroutine(gx::GXRenderModeObj *rendermode, bool param_2);
	void prepareCopyDisp();
	void exchangeXfb_double();
	void endGX();
	void endFrame();
	void beginRender();
	void clearEfb(int param_1, int param_2, int param_3, int param_4, gx::GXColor *param_5);
	~JFWDisplay();
};