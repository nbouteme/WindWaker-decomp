#include "JKRThreadSwitch.h"

void (*JKRThreadSwitch::mUserPreCallback)(os::OSThread *param_1, os::OSThread *param_2);
void (*JKRThreadSwitch::mUserPostCallback)(os::OSThread *param_1, os::OSThread *param_2);
JKRThreadSwitch *JKRThreadSwitch::sManager;

void JKRThreadSwitch::callback(os::OSThread *param_1, os::OSThread *param_2) {
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
		auto puVar2 = (JKRThread *)pJVar4->mpData;
		if (puVar2->thread == pOVar3) {
			puVar2->newheap = JKRHeap::sCurrentHeap;
		}
		if ((puVar2->thread == param_2) && (JKRThreadSwitch::sManager->state != '\0')) {
			puVar2->newheap->becomeCurrentHeap();
		}
	}
	if (JKRThreadSwitch::mUserPostCallback) {
		JKRThreadSwitch::mUserPostCallback(pOVar3, param_2);
	}
}

JKRThreadSwitch::JKRThreadSwitch(JKRHeap *param_1) {
	this->heap = param_1;
	os::OSSetSwitchThreadCallback(JKRThreadSwitch::callback);
	this->state = 1;
	return;
}

JKRThreadSwitch *JKRThreadSwitch::createManager(JKRHeap *param_1) {
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
