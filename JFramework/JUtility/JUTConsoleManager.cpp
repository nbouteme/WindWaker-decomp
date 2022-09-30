#include "JUTConsoleManager.h"

JUTConsoleManager *JUTConsoleManager::sManager;

JUTConsoleManager *JUTConsoleManager::createManager(JKRHeap *param_1) {
	ulong uVar1;
	JUTConsoleManager *self;

	if (JUTConsoleManager::sManager) {
		JUTAssertion::getSDevice()->showAssert("JUTConsole.cpp", 0x39a, "sManager == 0");
		m_Do_printf::OSPanic("JUTConsole.cpp", 0x39a, "Halt");
	}
	if (param_1 == (JKRHeap *)0x0) {
		param_1 = JKRHeap::sCurrentHeap;
	}
	self = new (param_1) JUTConsoleManager();
	JUTConsoleManager::sManager = self;
	return self;
}

void JUTConsoleManager::appendConsole(JUTConsole *param_1) {
	uint uVar2;
	ulong uVar3;

	if (!(JUTConsoleManager::sManager && param_1)) {
		JUTAssertion::getSDevice()->showAssert("JUTConsole.cpp", 0x3bf, "sManager != 0 && console != 0");
		m_Do_printf::OSPanic("JUTConsole.cpp", 0x3bf, "Halt");
	}
	auto foundconsole = this->consoles.Find(&param_1->linknode);
	if (foundconsole.node == &(this->consoles).head) {
		JUTAssertion::getSDevice()->showAssert("JUTConsole.cpp", 0x3c2, "soLink_.Find( console ) == soLink_.end()");
		m_Do_printf::OSPanic("JUTConsole.cpp", 0x3c2, "Halt");
	}
	auto local_3c = &(this->consoles).head;
	auto iStack64 = this->consoles.Insert(JGadget::TNodeLinkList::iterator{local_3c}, &param_1->linknode);
	if (!this->console2) {
		this->console2 = param_1;
	}
}

void JUTConsoleManager::draw() {
	auto linkedlist = (this->consoles).head.next;
	while (true) {
		auto console = my_container_of(linkedlist, JUTConsole, linknode);
		if (linkedlist == &(this->consoles).head)
			break;
		if (console != this->console2) {
			console->doDraw(1);
		}
		linkedlist = linkedlist->next;
	}
	if (this->console2) {
		this->console2->doDraw(0);
	}
}

void JUTConsoleManager::drawDirect(bool waitforinterrupt) {
	undefined4 uVar1;
	int iVar2;
	int iVar3;

	if (this->console) {
		if (waitforinterrupt != false) {
			uVar1 = os::OSEnableInterrupts();
			iVar2 = vi::VIGetRetraceCount();
			do {
				iVar3 = vi::VIGetRetraceCount();
			} while (iVar2 == iVar3);
			os::OSRestoreInterrupts(uVar1);
		}
		this->console->doDraw(2);
	}
}

void JUTConsoleManager::removeConsole(JUTConsole *param_1) {
	uint uVar2;
	ulong uVar3;
	JUTConsole *pJVar5;
	JGadget::TLinkListNode *pTVar4;

	if (!(JUTConsoleManager::sManager && param_1)) {
		JUTAssertion::getSDevice()->showAssert("JUTConsole.cpp", 0x3d6, "sManager != 0 && console != 0");
		m_Do_printf::OSPanic("JUTConsole.cpp", 0x3d6, "Halt");
	}
	auto local_1c = &(this->consoles).head;
	auto local_20 = this->consoles.Find(&param_1->linknode);
	auto local_18 = local_20;
	if (!(local_1c == local_20.node)) {
		JUTAssertion::getSDevice()->showAssert("JUTConsole.cpp", 0x3d9, "soLink_.Find( console ) != soLink_.end()");
		m_Do_printf::OSPanic("JUTConsole.cpp", 0x3d9, "Halt");
	}
	if (this->console2 == param_1) {
		if ((uint)(this->consoles).count < 2) {
			this->console2 = (JUTConsole *)0x0;
		} else {
			// TODO: wtf?
			if (param_1 == (JUTConsole *)((this->consoles).head.prev + -3)) {
				pTVar4 = (this->consoles).head.next;
			} else {
				pTVar4 = param_1->linknode.next;
			}
			this->console2 = (JUTConsole *)(pTVar4 + -3);
		}
	}
	pJVar5 = JUtility::JUTGetWarningConsole();
	if (pJVar5 == param_1) {
		JUtility::JUTSetWarningConsole(0);
	}
	pJVar5 = JUtility::JUTGetReportConsole();
	if (pJVar5 == param_1) {
		JUtility::JUTSetReportConsole(0);
	}
	this->consoles.Remove(&param_1->linknode);
}

void JUTConsoleManager::setDirectConsole(JUTConsole *param_1) {
	if (this->console != (JUTConsole *)0x0) {
		appendConsole(this->console);
	}
	if (param_1 != (JUTConsole *)0x0) {
		removeConsole(param_1);
	}
	this->console = param_1;
}
