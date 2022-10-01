#pragma once
#include "../../dolphin/gx.h"
#include "JUTDirectPrint.h"
#include "JUTXfb.h"
#include "JUtility.h"

#include <dolphin/vi.h>

struct JUTVideo {
	static JUTVideo *sManager;
	static ulong sVideoLastTick;
	static int sVideoInterval;

	gx::GXRenderModeObj *mpRenderMode;
	byte waitFinished;
	int flushesRemaining;
	int mRetraceCount;
	os::OSMessage mMesg;
	os::OSMessageQueue mMesgQ;
	void (*preRetraceCB)(ulong);
	void (*postRetraceCB)();
	vi::VIRetraceCallback mpOldPostRetraceProc, mpOldPreRetraceProc;

	void setRenderMode(gx::GXRenderModeObj *param_1);

	static JUTVideo *createManager(gx::GXRenderModeObj *obj);
	static void destroyManager();
	static void drawDoneCallback();
	static void preRetraceProc(u32 param_1);
	static void drawDoneStart();
	static void postRetraceProc(u32 param_1);
	static void dummyNoDrawWait();
	static JUTVideo *getManager();

	JUTVideo(gx::GXRenderModeObj *param_1);

	void waitRetraceIfNeed();

	gx::GXRenderModeObj *getRenderMode();

	~JUTVideo();
};