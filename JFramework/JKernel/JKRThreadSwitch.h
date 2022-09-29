#pragma once

#include "../../dolphin/os.h"
#include "../../machine/dolphin/printf.h"
#include "../JUtility/JUTAssert.h"
#include "./JKRHeap.h"
#include "./JKRThread.h"
#include "./JKernel.h"

struct JKRThreadSwitch {
	JKRHeap *heap;
	int state;

	static void (*mUserPreCallback)(os::OSThread *param_1, os::OSThread *param_2);
	static void (*mUserPostCallback)(os::OSThread *param_1, os::OSThread *param_2);

	static void callback(os::OSThread *param_1, os::OSThread *param_2) {
		using namespace os;
		OSThread *pOVar1;
		undefined *puVar2;
		OSThread *pOVar3;
		JSUPtrLink *pJVar4;

		if (JKRThreadSwitch::mUserPreCallback) {
			JKRThreadSwitch::mUserPreCallback(param_1, param_2);
		}
		pOVar3 = param_1;
		if ((param_1 == nullptr) && (param_2 == nullptr)) {
			pOVar3 = nullptr;
			JKernel::preEnd = param_1;
		}
		pOVar1 = JKernel::preEnd;
		pJVar4 = JKRThread::sThreadList.mpHead;
		if ((pOVar3 == nullptr) && (param_2 == nullptr)) {
			JKernel::preEnd = nullptr;
			pOVar3 = pOVar1;
		}
		for (; pJVar4; pJVar4 = pJVar4->mpNext) {
			puVar2 = (undefined *)pJVar4->mpData;
			if (*(OSThread **)(puVar2 + 0x2c) == pOVar3) {
				*(JKRHeap **)(puVar2 + 0x60) = JKRHeap::sCurrentHeap;
			}
			if ((*(OSThread **)(puVar2 + 0x2c) == param_2) && (JKRThreadSwitch::sManager->state != '\0')) {
				(*(JKRHeap **)(puVar2 + 0x60))->becomeCurrentHeap();
			}
		}
		if (JKRThreadSwitch::mUserPostCallback) {
			JKRThreadSwitch::mUserPostCallback(pOVar3, param_2);
		}
	}

	JKRThreadSwitch(JKRHeap *param_1) {
		this->heap = param_1;
		os::OSSetSwitchThreadCallback(JKRThreadSwitch::callback);
		this->state = 1;
		return;
	}

	static JKRThreadSwitch *sManager;
	static JKRThreadSwitch *createManager(JKRHeap *param_1) {
		ulong uVar1;
		JKRThreadSwitch *self;

		if (JKRThreadSwitch::sManager) {
			auto uVar1 = JUTAssertion::getSDevice();
			uVar1->showAssert("JKRThread.cpp", 0xb8, "sManager == 0");
			m_Do_printf::OSPanic("JKRThread.cpp", 0xb8, "Halt");
		}
		if (param_1 == nullptr) {
			param_1 = JKRHeap::sCurrentHeap;
		}
		self = new (param_1, 0) JKRThreadSwitch(param_1);
		JKRThreadSwitch::sManager = self;
		return self;
	}
};