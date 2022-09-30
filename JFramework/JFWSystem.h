#pragma once
#include <dolphin/gx.h>
#include "JFWDisplay.h"
#include "JKernel/JKRThread.h"
#include "JUtility/JUTConsole.h"
#include "JUtility/JUTDbPrint.h"
#include "JUtility/JUTDirectPrint.h"

namespace JFramework {
	extern char JFWAutoAbortGfx;
	extern char init$2525;
	extern int prevFrame$2524;
	extern gx::GXTexObj clear_z_tobj;
	extern MTX34 e_mtx ;
	extern byte clear_z_TX[];
	extern os::OSTime nextTick$2569;

	void waitForTick(int param_1, uint param_2) ;
	void callDirectDraw(void) ;
	void JFWThreadAlarmHandler(os::OSAlarm *alarm, os::OSContext *ctx) ;
	void diagnoseGpHang(void) ;
	void JFWGXAbortAlarmHandler(os::OSAlarm *param_1, os::OSContext *param_2) ;
	void JFWGXDrawDoneAutoAbort(void) ;
}

struct JFWSystem {
	static char sInitCalled;
	static JUTConsole *systemConsole;
	static JKRHeap *systemHeap;
	static JKRHeap *rootHeap;
	static JKRThread *mainThread;
	static JUTDbPrint *debugPrint;
	static JUTResFont *systemFont;
	static JUTConsoleManager *systemConsoleManager;

	struct CSetUpParam {
		static int maxStdHeaps;
		static int sysHeapSize;
		static int fifoBufSize;
		static int aramAudioBufSize;
		static int aramGraphBufSize;
		static gx::GXRenderModeObj *renderMode;

		static int streamPriority;
		static int decompPriority;
		static int aPiecePriority;
		static ResFONT *systemFontRes;
		const static int exConsoleBufferSize = 0x24F8;
	};

	static void init(void);
	static void firstInit(void);
};