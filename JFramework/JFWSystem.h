#pragma once
#include <dolphin/gx.h>
#include "JFWDisplay.h"
#include "JKernel/JKRThread.h"
#include "JUtility/JUTConsole.h"
#include "JUtility/JUTDbPrint.h"
#include "JUtility/JUTDirectPrint.h"

namespace JFramework {
	char JFWAutoAbortGfx;
	char init$2525;
	int prevFrame$2524;
	gx::GXTexObj clear_z_tobj;
	MTX34 e_mtx = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 1, 1, 0},
	};

	byte clear_z_TX[] = {0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

	void JFramework::waitForTick(int param_1, uint param_2) {
		static u32 nextCount$2577;
		static char init$2578, init$2570;
		int iVar1;
		uint uVar2;
		os::OSTime lVar3;
		int local_18[4];

		if (param_1 == 0) {
			if (init$2578 == 0) {
				nextCount$2577 = vi::VIGetRetraceCount();
				init$2578 = 1;
			}
			uVar2 = 1;
			if ((param_2 & 0xffff) != 0) {
				uVar2 = param_2 & 0xffff;
			}
			do {
				iVar1 = os::OSReceiveMessage(&JUTVideo::sManager->mMesgQ, (void **)local_18, 1);
				lVar3 = nextTick$2569;
				if (iVar1 == 0) {
					local_18[0] = 0;
				}
			} while (local_18[0] - nextCount$2577 < 0);
			nextCount$2577 = local_18[0] + uVar2;
		} else {
			if (init$2570 == 0) {
				nextTick$2569 = os::OSGetTime();
				init$2570 = 1;
			}
			lVar3 = os::OSGetTime();
			while (true) {
				nextTick$2569 = nextTick$2569 >> 0x20;
				if (lVar3 < nextTick$2569)
					break;
				JFWDisplay::sManager->threadSleep((uint)lVar3);
				lVar3 = os::OSGetTime();
			}
			lVar3 = lVar3 + 0xc;
		}
		nextTick$2569 = (uint)lVar3;
	}

	os::OSTime nextTick$2569;

	void callDirectDraw(void) {
		JUTAssertion *self;
		void *puVar1;

		if ((short)JUTXfb::sManager->idx0 < 0) {
			puVar1 = (void *)0x0;
		} else {
			puVar1 = (&JUTXfb::sManager->xfb0)[(short)JUTXfb::sManager->idx0];
		}
		JUTDirectPrint::sDirectPrint->changeFrameBuffer(puVar1, JUTVideo::sManager->mpRenderMode->fbWidth, JUTVideo::sManager->mpRenderMode->efbHeight);
		JUTAssertion::flushMessage();
	}

	void JFWThreadAlarmHandler(os::OSAlarm *alarm, os::OSContext *ctx) {
		// ebin hack
		struct bepissed {
			os::OSAlarm alarm;
			os::OSThread *thread;
		};
		bepissed *bepis = (bepissed *)alarm;
		os::OSResumeThread(bepis->thread);
	}

	void diagnoseGpHang(void) {
		uint uVar1;
		uint uVar2;
		bool bVar3;
		gx::GXBool uStack56;
		byte local_37;
		byte local_36[2];
		uint local_34;
		uint local_30;
		uint local_2c;
		uint local_28;
		uint local_24;
		uint local_20;
		uint local_1c;
		uint local_18[2];

		gx::GXReadXfRasMetric(&local_1c, local_18, &local_24, &local_20);
		gx::GXReadXfRasMetric(&local_2c, &local_28, &local_34, &local_30);
		uVar1 = __builtin_clz(local_28 - local_18[0]);
		uVar2 = uVar1 >> 5 & 0xff;	// equivalent to local_28 == local_18[0] ?
		uVar1 = __builtin_clz(local_2c - local_1c);
		uVar1 = uVar1 >> 5 & 0xff;
		bVar3 = local_30 != local_20;  // equivalent to local_2c = local_1c ?
		gx::GXGetGPStatus(&uStack56, &uStack56, local_36, &local_37, &uStack56);
		m_Do_printf::OSReport("GP status %d%d%d%d%d%d --> ", (uint)local_36[0], (uint)local_37, uVar2, uVar1, bVar3, local_34 != local_24);
		if ((uVar1 == 0) && (bVar3)) {	// is the "bug" making these different?
			m_Do_printf::OSReport("GP hang due to XF stall bug.\n");
		} else if ((uVar2 == 0) && ((uVar1 != 0 && (bVar3)))) {
			m_Do_printf::OSReport("GP hang due to unterminated primitive.\n");
		} else if ((local_37 == 0) && (((uVar2 != 0 && (uVar1 != 0)) && (bVar3)))) {
			m_Do_printf::OSReport("GP hang due to illegal instruction.\n");
		} else if ((((local_36[0] == 0) || (local_37 == 0)) || ((uVar2 == 0 || ((uVar1 == 0 || (!bVar3)))))) || (local_34 == local_24)) {
			m_Do_printf::OSReport("GP is in unknown state.\n");
		} else {
			m_Do_printf::OSReport("GP appears to be not hung (waiting for input).\n");
		}
	}

	void JFWGXAbortAlarmHandler(os::OSAlarm *param_1, os::OSContext *param_2) {
		JFramework::diagnoseGpHang();
		auto uVar1 = JUTAssertion::getSDevice();
		if (JFramework::JFWAutoAbortGfx == 1) {
			m_Do_printf::OSReport("GXAbortFrame() を呼び出し、復帰します\n");
			uVar1->setWarningMessage_f("JFWDisplay.cpp", 0x54b, "GP FREEZE! AUTO RESUME");
			gx::GXAbortFrame();
			gx::GXSetDrawDone();
		} else {
			m_Do_printf::OSReport("自動復帰しません\n");
			uVar1->setWarningMessage_f("JFWDisplay.cpp", 0x546, "GP FREEZE!");
			uVar1->showAssert("JFWDisplay.cpp", 0x547, "0");
			m_Do_printf::OSPanic("JFWDisplay.cpp", 0x547, "Halt");
		}
		return;
	}

	void JFWGXDrawDoneAutoAbort(void) {
		os::OSAlarm alarm;

		if (JFramework::JFWAutoAbortGfx == 0) {
			gx::GXDrawDone();
		} else {
			os::OSCreateAlarm(&alarm);
			os::OSSetAlarm(&alarm, 162000000 >> 2, JFramework::JFWGXAbortAlarmHandler);
			gx::GXDrawDone();
			os::OSCancelAlarm(&alarm);
		}
		return;
	}
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