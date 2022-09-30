#include "JFWSystem.h"

#include <doltypes.h>

#include "../dolphin/dvd.h"
#include "../dolphin/os.h"
#include "../machine/dolphin/printf.h"
#include "JFWSystem.h"
#include "JKernel/JKRAram.h"
#include "JKernel/JKRExpHeap.h"
#include "JKernel/JKRThread.h"
#include "JKernel/JKernel.h"
#include "JUTDbPrint.h"
#include "JUTGraphFifo.h"
#include "JUtility.h"
#include "JUtility/JUTAssert.h"
#include "JUtility/JUTException.h"
#include "JUtility/JUTFont.h"
#include "JUtility/JUTGamePad.h"
#include "JUtility/JUTVideo.h"

void JFWSystem::firstInit() {
	if (JFWSystem::rootHeap) {
		auto uVar1 = JUTAssertion::getSDevice();
		uVar1->showAssert("JFWSystem.cpp", 0x50, "rootHeap == 0");
		m_Do_printf::OSPanic("JFWSystem.cpp", 0x50, "");
	}
	os::OSInit();
	dvd::DVDInit();
	JFWSystem::rootHeap = JKRExpHeap::createRoot(JFWSystem::CSetUpParam::maxStdHeaps, false);
	JFWSystem::systemHeap = JKRExpHeap::create(JFWSystem::CSetUpParam::sysHeapSize, JFWSystem::rootHeap, false);
}

void JFWSystem::init(void) {
	ulong uVar1;
	JKRThread *thread;
	os::OSThread *pOVar2;
	JUTGraphFifo *gfifo;
	JUTDirectPrint *pJVar3;
	JUTResFont *pJVar4;
	JUTConsole *pJVar5;
	uint uVar6;
	void *jexcept;
	int iVar7;
	undefined4 uVar8;
	undefined8 in_f31;
	double dVar9;
	undefined auStack8[8];

	uVar8 = 0;
	if (JFWSystem::sInitCalled != 0) {
		JUTAssertion::getSDevice()->showAssert("JFWSystem.cpp", 0x65, "sInitCalled == false");
		m_Do_printf::OSPanic("JFWSystem.cpp", 0x65, "Halt");
	}
	if (JFWSystem::rootHeap == nullptr) {
		JFWSystem::firstInit();
	}
	JFWSystem::sInitCalled = 1;
	JKRAram::create(JFWSystem::CSetUpParam::aramAudioBufSize, JFWSystem::CSetUpParam::aramGraphBufSize,
					JFWSystem::CSetUpParam::streamPriority, JFWSystem::CSetUpParam::decompPriority,
					JFWSystem::CSetUpParam::aPiecePriority);
	JFWSystem::mainThread = new JKRThread(os::OSGetCurrentThread(), 4);
	JUTVideo::createManager(JFWSystem::CSetUpParam::renderMode);
	gfifo = new JUTGraphFifo(JFWSystem::CSetUpParam::fifoBufSize);
	JUTGamePad::init();
	pJVar3 = JUTDirectPrint::start();
	// JUTAssertion::create(); // nop
	JUTException::create(pJVar3);
	JFWSystem::systemFont = new JUTResFont((ResFONT *)JFWSystem::CSetUpParam::systemFontRes, nullptr);
	JFWSystem::debugPrint = JUTDbPrint::start(nullptr, nullptr);
	JFWSystem::debugPrint->changeFont(JFWSystem::systemFont);
	JFWSystem::systemConsoleManager = JUTConsoleManager::createManager(nullptr);
	pJVar5 = JUTConsole::create(0x3c, 200, nullptr);
	pJVar4 = JFWSystem::systemFont;
	JFWSystem::systemConsole = pJVar5;
	pJVar5->font = JFWSystem::systemFont;
	uVar6 = pJVar4->getHeight();
	dVar9 = (double)uVar6;
	uVar6 = pJVar4->getWidth();
	pJVar5->charspacing = uVar6;
	pJVar5->linespacing = (float)dVar9;
	if (JFWSystem::CSetUpParam::renderMode->efbHeight < 300) {
		uVar6 = pJVar4->getHeight();
		dVar9 = (double)(uVar6 * 0.5);
		uVar6 = pJVar4->getWidth();
		pJVar5 = JFWSystem::systemConsole;
		JFWSystem::systemConsole->charspacing = uVar6 * 0.85;
		pJVar5->linespacing = (float)dVar9;
		pJVar5 = JFWSystem::systemConsole;
		JFWSystem::systemConsole->console_position_x = 0x14;
		pJVar5->console_position_y = 0x19;
	} else {
		uVar6 = pJVar4->getHeight();
		dVar9 = (double)uVar6;
		uVar6 = pJVar4->getWidth();
		pJVar5 = JFWSystem::systemConsole;
		JFWSystem::systemConsole->charspacing =
			uVar6 * 0.85;
		pJVar5->linespacing = (float)dVar9;
		pJVar5 = JFWSystem::systemConsole;
		JFWSystem::systemConsole->console_position_x = 0x14;
		pJVar5->console_position_y = 0x32;
	}
	pJVar5 = JFWSystem::systemConsole;
	JFWSystem::systemConsole->maxlines = 0x19;
	if (pJVar5->lines < pJVar5->maxlines) {
		pJVar5->maxlines = pJVar5->lines;
	}
	JFWSystem::systemConsole->candisplay = 0;
	JFWSystem::systemConsole->outputwhere = 3;
	JUtility::JUTSetReportConsole(JFWSystem::systemConsole);
	JUtility::JUTSetWarningConsole(JFWSystem::systemConsole);
	uVar1 = 4;
	jexcept = JFWSystem::systemHeap->alloc(JFWSystem::CSetUpParam::exConsoleBufferSize, 4);
	JUTException::createConsole(jexcept, JFWSystem::CSetUpParam::exConsoleBufferSize);
}


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