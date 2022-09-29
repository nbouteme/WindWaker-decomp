#pragma once
#include <JFramework/JKernel/JKRExpHeap.h>
#include <JFramework/JKernel/JKRHeap.h>
#include <JFramework/JKernel/JKRSolidHeap.h>
#include <JFramework/JUtility/JUTAssert.h>

#include "./main.h"
#include "./printf.h"

namespace m_Do_ext {
	JKRHeap *mDoExt_SaveCurrentHeap;

	JKRExpHeap *zeldaHeap, *gameHeap, *archiveHeap, *commandHeap;

	JKRSolidHeap *m_Do_ext::mDoExt_createSolidHeap(int maxHeapSize, JKRHeap *param_2, uint param_3)

	{
		JKRSolidHeap *self;
		ulong maxSize;

		if (param_2 == (JKRHeap *)0x0) {
			param_2 = JKRHeap::sCurrentHeap;
		}
		if ((maxHeapSize == 0) || (maxHeapSize == -1)) {
			self = JKRSolidHeap::create(0xffffffff, param_2, false);
		} else {
			maxSize = (maxHeapSize + 0xfU & 0xfffffff0) + 0x80;
			if (0x10 < param_3) {
				maxSize = (param_3 + maxSize) - 0x10;
			}
			self = JKRSolidHeap::create(maxSize, param_2, false);
		}
		if (self != (JKRSolidHeap *)0x0) {
			self->setErrorFlag(true);
		}
		return self;
	}

	void mDoExt_setCurrentHeap(JKRHeap *param_1) {
		if (param_1 == (JKRHeap *)0x0) {
			JUTAssertion::getSDevice()->showAssert("m_Do_ext.cpp", 0xa7c, "heap != 0");
			m_Do_printf::OSPanic("m_Do_ext.cpp", 0xa7c, "Halt");
		}
		param_1->becomeCurrentHeap();
	}

	JKRSolidHeap *
	mDoExt_createSolidHeapToCurrent(int maxHeapSize, JKRHeap *param_2, uint param_3) {
		JKRHeap *pHeap;
		os::OSThread *pOVar1;
		ulong uVar2;

		pHeap = (JKRHeap *)m_Do_ext::mDoExt_createSolidHeap(maxHeapSize, param_2, param_3);
		if (pHeap == (JKRHeap *)0x0) {
			pHeap = (JKRHeap *)0x0;
		} else {
			pOVar1 = os::OSGetCurrentThread();
			if (pOVar1 != &m_Do_main::mainThread) {
				auto uVar2 = JUTAssertion::getSDevice();
				uVar2->showAssert("m_Do_ext.cpp", 0x9f1, "OSGetCurrentThread() == &mainThread");
				m_Do_printf::OSPanic("m_Do_ext.cpp", 0x9f1, "Halt");
			}
			if (m_Do_ext::mDoExt_SaveCurrentHeap != (JKRHeap *)0x0) {
				auto uVar2 = JUTAssertion::getSDevice();
				uVar2->showAssert("m_Do_ext.cpp", 0x9f2, "mDoExt_SaveCurrentHeap == 0");
				m_Do_printf::OSPanic("m_Do_ext.cpp", 0x9f2, "Halt");
			}
			m_Do_ext::mDoExt_SaveCurrentHeap = JKRHeap::sCurrentHeap;
			m_Do_ext::mDoExt_setCurrentHeap(pHeap);
		}
		return (JKRSolidHeap *)pHeap;
	}

	void m_Do_ext::mDoExt_restoreCurrentHeap(void) {
		os::OSThread *pOVar1;
		ulong uVar2;

		pOVar1 = os::OSGetCurrentThread();
		if (pOVar1 != &m_Do_main::mainThread) {
			auto uVar2 = JUTAssertion::getSDevice();
			uVar2->showAssert("m_Do_ext.cpp", 0xac2, "OSGetCurrentThread() == &mainThread");
			m_Do_printf::OSPanic("m_Do_ext.cpp", 0xac2, "Halt");
		}
		if (m_Do_ext::mDoExt_SaveCurrentHeap == (JKRHeap *)0x0) {
			auto uVar2 = JUTAssertion::getSDevice();
			uVar2->showAssert("m_Do_ext.cpp", 0xac3, "mDoExt_SaveCurrentHeap != 0");
			m_Do_printf::OSPanic("m_Do_ext.cpp", 0xac3, "Halt");
		}
		m_Do_ext::mDoExt_SaveCurrentHeap->becomeCurrentHeap();
		m_Do_ext::mDoExt_SaveCurrentHeap = (JKRHeap *)0x0;
	}

	uint mDoExt_adjustSolidHeap(JKRSolidHeap *param_1) {
		uint uVar1;

		if (!param_1) {
			return 0;
		}

		uVar1 = param_1->adjustSize();

		if (0x7f < uVar1) {
			uVar1 = uVar1 - 0x80;
		}
		return uVar1;
	}

	JKRExpHeap *mDoExt_getZeldaHeap() {
		return zeldaHeap;
	}

	JKRExpHeap *mDoExt_getGameHeap() {
		return gameHeap;
	}

	JKRExpHeap *mDoExt_getArchiveHeap() {
		return archiveHeap;
	}

	JKRExpHeap *mDoExt_getCommandHeap() {
		return commandHeap;
	}

	void mDoExt_createCommandHeap(ulong param_1, JKRHeap *param_2) {
		bool bVar1;
		ulong uVar2;

		bVar1 = false;
		if ((!commandHeap) || (param_1 == 0)) {
			bVar1 = true;
		}
		if (!bVar1) {
			auto uVar2 = JUTAssertion::getSDevice();
			uVar2->showAssert("m_Do_ext.cpp", 0x87d, "commandHeap == 0 || heapSize == 0");
			m_Do_printf::OSPanic("m_Do_ext.cpp", 0x87d, "Halt");
		}
		commandHeap = JKRExpHeap::create(param_1, param_2, true);
	}

	JKRHeap *mDoExt_createArchiveHeap(ulong param_1, JKRHeap *param_2) {
		bool bVar1;

		bVar1 = false;
		if ((archiveHeap == nullptr) || (param_1 == 0)) {
			bVar1 = true;
		}
		if (!bVar1) {
			auto uVar2 = JUTAssertion::getSDevice();
			uVar2->showAssert("m_Do_ext.cpp", 0x8bd, "archiveHeap == 0 || heapSize == 0");
			m_Do_printf::OSPanic("m_Do_ext.cpp", 0x8bd, "Halt");
		}
		archiveHeap = JKRExpHeap::create(param_1, param_2, true);
		archiveHeap->field1_0x6c = 1;
		return archiveHeap;
	}

	JKRHeap *mDoExt_createGameHeap(ulong param_1, JKRHeap *param_2) {
		bool bVar1;
		ulong uVar2;

		bVar1 = false;
		if ((gameHeap == nullptr) || (param_1 == 0)) {
			bVar1 = true;
		}
		if (!bVar1) {
			auto uVar2 = JUTAssertion::getSDevice();
			uVar2->showAssert("m_Do_ext.cpp", 0x802, "gameHeap == 0 || heapSize == 0");
			m_Do_printf::OSPanic("m_Do_ext.cpp", 0x802, "Halt");
		}
		gameHeap = JKRExpHeap::create(param_1, param_2, true);
		gameHeap->field1_0x6c = 1;
		return gameHeap;
	}

	JKRHeap *mDoExt_createZeldaHeap(ulong param_1, JKRHeap *param_2) {
		bool bVar1;
		ulong uVar2;

		bVar1 = false;
		if ((zeldaHeap == nullptr) || (param_1 == 0)) {
			bVar1 = true;
		}
		if (!bVar1) {
			auto uVar2 = JUTAssertion::getSDevice();
			uVar2->showAssert("m_Do_ext.cpp", 0x840, "zeldaHeap == 0 || heapSize == 0");
			m_Do_printf::OSPanic("m_Do_ext.cpp", 0x840, "Halt");
		}
		zeldaHeap = JKRExpHeap::create(param_1, param_2, true);
		return zeldaHeap;
	}

}