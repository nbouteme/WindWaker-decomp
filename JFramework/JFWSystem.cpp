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