#include "JUTException.h"

#include <dolphin/os/OSMemory.h>

#include "JUTDirectPrint.h"
#include "JUTGamePad.h"

JUTException::usercallback *JUTException::sPreUserCallback;
JUTException::usercallback *JUTException::sPostUserCallback;

os::OSTime JUTException::c3bcnt[4];
JUTException *JUTException::sErrorManager;
JSUPtrList JUTException::sMapFileList;
u32 JUTException::msr, JUTException::fpscr;
os::OSMessageQueue JUTException::sMessageQueue;
void *JUTException::sConsoleBuffer;
int JUTException::sConsoleBufferSize;
JUTConsole *JUTException::sConsole;

void JUTException::waitTime(u32 time) {
	if (time != 0) {
		auto lVar1 = os::OSGetTime();
		auto lVar2 = os::OSGetTime();
		do {
			lVar2 = os::OSGetTime();
		} while ((lVar2 - lVar1) / (os::OS_BUS_CLOCK / 4000) < time);
	}
}

JUTException::usercallback *JUTException::setPreUserCallback(usercallback *param_1) {
	usercallback *puVar1;

	puVar1 = sPreUserCallback;
	sPreUserCallback = param_1;
	return puVar1;
}

JUTException::usercallback *JUTException::setPostUserCallback(usercallback *param_1) {
	usercallback *puVar1;

	puVar1 = sPostUserCallback;
	sPostUserCallback = param_1;
	return puVar1;
}

void JUTException::errorHandler(os::OSError param_1, os::OSContext *param_2, ulong param_3, ulong param_4) {
	JUTException::msr = base::PPCMfmsr();
#ifndef DOLPHIN
	JUTException::fpscr = 0;
#else
	JUTException::fpscr = param_2->fpscr;
#endif
	os::OSFillFPUContext(param_2);
	os::OSSetErrorHandler(param_1, 0);
	if (param_1 == 0xf) {
		os::OSProtectRange(0, 0, 0, 3);
		os::OSProtectRange(1, 0, 0, 3);
		os::OSProtectRange(2, 0, 0, 3);
		os::OSProtectRange(3, 0, 0, 3);
	}
	JUtility::exCallbackObject.callback = JUTException::sPreUserCallback;
	JUtility::exCallbackObject.lowerpage = param_1;
	JUtility::exCallbackObject.ctx = (intptr_t)param_2;
	JUtility::exCallbackObject.interrupt = param_3;
	JUtility::exCallbackObject.arg = param_4;
	os::OSSendMessage(&JUTException::sMessageQueue, &JUtility::exCallbackObject, 1);
	os::OSEnableScheduler();
	os::OSYieldThread();
}

void JUTException::setFPException(ulong param_1) {
	os::__OSFpscrEnableBits = param_1;
	if (param_1 == 0) {
		os::OSSetErrorHandler(0x10, 0);
	} else {
		os::OSSetErrorHandler(0x10, (os::OSErrorHandler)JUTException::errorHandler);
	}
	return;
}

JUTException::JUTException(JUTDirectPrint *param_1) : JKRThread(0x4000, 0x10, 0) {
	this->field2_0x6c = param_1;
	os::OSSetErrorHandler(2, (os::OSErrorHandler)JUTException::errorHandler);
	os::OSSetErrorHandler(3, (os::OSErrorHandler)JUTException::errorHandler);
	os::OSSetErrorHandler(6, (os::OSErrorHandler)JUTException::errorHandler);
	os::OSSetErrorHandler(5, (os::OSErrorHandler)JUTException::errorHandler);
	os::OSSetErrorHandler(0xf, (os::OSErrorHandler)JUTException::errorHandler);
	JUTException::setFPException(0);
	JUTException::sPreUserCallback = nullptr;
	JUTException::sPostUserCallback = nullptr;
	this->padidx = (JUTGamePad *)0x0;
	this->padidx2 = -1;
	this->field5_0x78 = 10;
	this->field6_0x7c = 10;
	this->field7_0x80 = 0xffffffff;
	this->field8_0x84 = 0;
	this->field9_0x88 = 0x1f;
}

void JUTException::appendMapFile(const char *param_1) {
	int iVar1;
	JSUPtrLink *ppcVar2;
	JSUPtrLink *pJVar2;

	pJVar2 = JUTException::sMapFileList.mpHead;
	if (param_1 != (char *)0x0) {
		for (; pJVar2 != (JSUPtrLink *)0x0; pJVar2 = pJVar2->mpNext) {
			iVar1 = strcmp(param_1, *(char **)pJVar2->mpData);
			if (iVar1 == 0) {
				return;
			}
		}
		ppcVar2 = new JSUPtrLink((void *)param_1);
		sMapFileList.append(ppcVar2);
	}
	return;
}

JUTException *JUTException::create(JUTDirectPrint *param_1) {
	JUTException *self;

	if (JUTException::sErrorManager == (JUTException *)0x0) {
		self = new JUTException(param_1);
		JUTException::sErrorManager = self;
		os::OSResumeThread(self->thread);
	}
	return JUTException::sErrorManager;
}

void JUTException::createConsole(void *buffer, ulong objectSize) {
	JUTConsole *pJVar1;
	uint uVar2;

	if (((buffer) && (objectSize)) &&
		(uVar2 = JUTConsole::getLineFromObjectSize(objectSize, 0x32), uVar2 != 0)) {
		JUTException::sConsoleBuffer = buffer;
		JUTException::sConsoleBufferSize = objectSize;
		JUTException::sConsole = JUTConsole::create(0x32, buffer, objectSize);
		JUTConsoleManager::sManager->setDirectConsole(JUTException::sConsole);
		pJVar1 = JUTException::sConsole;
		JUTException::sConsole->charspacing = 10.0;
		pJVar1->linespacing = 6.0;
		pJVar1 = JUTException::sConsole;
		JUTException::sConsole->console_position_x = 0xc;
		pJVar1->console_position_y = 0x28;
		pJVar1 = JUTException::sConsole;
		JUTException::sConsole->maxlines = 0x17;
		if (pJVar1->lines < pJVar1->maxlines) {
			pJVar1->maxlines = pJVar1->lines;
		}
		JUTException::sConsole->candisplay = 1;
		JUTException::sConsole->outputwhere = 3;
	}
}
