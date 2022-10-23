#include "ext.h"

#include <JFramework/JKernel/JKRArchive.h>
#include <JFramework/JUtility/JUTFont.h>
#include <common/dComIfG_inf_c.h>
#define _GNU_SOURCE
#include <fenv.h>

struct JUTCacheFont;

namespace m_Do_ext {
	JKRHeap *mDoExt_SaveCurrentHeap;

	JKRExpHeap *zeldaHeap, *gameHeap, *archiveHeap, *commandHeap;

	ResFONT *mDoExt_resfont0;
	JUTFont *mDoExt_font0;

	int mDoExt_font0_getCount;

	int safeGameHeapSize;
	int safeZeldaHeapSize;
	int safeCommandHeapSize;
	int safeArchiveHeapSize;

	void mDoExt_setSafeGameHeapSize() {
		safeGameHeapSize = mDoExt_getGameHeap()->getTotalFreeSize();
	}

	void mDoExt_setSafeZeldaHeapSize() {
		safeZeldaHeapSize = mDoExt_getZeldaHeap()->getTotalFreeSize();
	}

	void mDoExt_setSafeCommandHeapSize() {
		safeCommandHeapSize = mDoExt_getCommandHeap()->getTotalFreeSize();
	}

	void mDoExt_setSafeArchiveHeapSize() {
		safeArchiveHeapSize = mDoExt_getArchiveHeap()->getTotalFreeSize();
	}

	void mDoExt_initFontCommon(JUTFont **mDoExt_font,
							   ResFONT **resfont,
							   JKRHeap *heap,
							   char *filename,
							   JKRArchive *archive, char param_6, int param_7, int param_8) {
		ulong uVar1;
		ResFONT *pRVar2;
		JUTFont *pJVar3;

		if (*mDoExt_font) {
			auto uVar1 = JUTAssertion::getSDevice();
			JUTAssertion::showAssert(uVar1, "m_Do_ext.cpp", 0x19f8, "mDoExt_font == 0");
			m_Do_printf::OSPanic("m_Do_ext.cpp", 0x19f8, "Halt");
		}
		if (*resfont != (ResFONT *)0x0) {
			auto uVar1 = JUTAssertion::getSDevice();
			JUTAssertion::showAssert(uVar1, "m_Do_ext.cpp", 0x19f9, "mDoExt_resfont == 0");
			m_Do_printf::OSPanic("m_Do_ext.cpp", 0x19f9, "Halt");
		}
		pRVar2 = (ResFONT *)JKRArchive::getGlbResource(0x524f4f54, filename, archive);
		*resfont = pRVar2;
		if (*resfont == (ResFONT *)0x0) {
			auto uVar1 = JUTAssertion::getSDevice();
			JUTAssertion::showAssert(uVar1, "m_Do_ext.cpp", 0x19fb, "mDoExt_resfont != 0");
			m_Do_printf::OSPanic("m_Do_ext.cpp", 0x19fb, "Halt");
		}
		if (param_6 == '\0') {
			pJVar3 = new (heap, 0) JUTCacheFont(*resfont, ((param_8 + 0x1fU & 0xffffffe0) + 0x40) * param_7, heap);
			if (pJVar3->mValid) {
				*mDoExt_font = pJVar3;
			}
			JKRFileLoader::removeResource(*resfont, nullptr);
			*resfont = (ResFONT *)0x0;
		} else {
			*mDoExt_font = new JUTResFont(*resfont, heap);
		}
		if ((*mDoExt_font) && ((*mDoExt_font)->mValid == 0)) {
			m_Do_printf::OSReport_FatalError("\nキャッシュフォントクラス作成に失敗しました\n");
			pJVar3 = *mDoExt_font;
			delete pJVar3;
			*mDoExt_font = nullptr;
		}
		if (*mDoExt_font == nullptr) {
			auto uVar1 = JUTAssertion::getSDevice();
			JUTAssertion::showAssert(uVar1, "m_Do_ext.cpp", 0x1a1d, "mDoExt_font != 0");
			m_Do_printf::OSPanic("m_Do_ext.cpp", 0x1a1d, "Halt");
		}
		return;
	}

	void mDoExt_initFont0(void) {
		JKRArchive *pJVar1;
		JKRExpHeap *pJVar2;

		pJVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFontArchive;
		pJVar2 = m_Do_ext::mDoExt_getZeldaHeap();
		m_Do_ext::mDoExt_initFontCommon(&m_Do_ext::mDoExt_font0,
										&m_Do_ext::mDoExt_resfont0,
										pJVar2, "rock_24_20_4i_usa.bfn",
										pJVar1, 1, 0, 0);
		return;
	}

	JUTFont *mDoExt_getMesgFont(void) {
		if (mDoExt_font0) {
			mDoExt_initFont0();
		}
		mDoExt_font0_getCount++;
		return mDoExt_font0;
	}

	JKRSolidHeap *mDoExt_createSolidHeap(int maxHeapSize, JKRHeap *param_2, uint param_3) {
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

		pHeap = (JKRHeap *)mDoExt_createSolidHeap(maxHeapSize, param_2, param_3);
		if (pHeap == (JKRHeap *)0x0) {
			pHeap = (JKRHeap *)0x0;
		} else {
			pOVar1 = os::OSGetCurrentThread();
			if (pOVar1 != &m_Do_main::mainThread) {
				auto uVar2 = JUTAssertion::getSDevice();
				uVar2->showAssert("m_Do_ext.cpp", 0x9f1, "OSGetCurrentThread() == &mainThread");
				m_Do_printf::OSPanic("m_Do_ext.cpp", 0x9f1, "Halt");
			}
			if (mDoExt_SaveCurrentHeap != (JKRHeap *)0x0) {
				auto uVar2 = JUTAssertion::getSDevice();
				uVar2->showAssert("m_Do_ext.cpp", 0x9f2, "mDoExt_SaveCurrentHeap == 0");
				m_Do_printf::OSPanic("m_Do_ext.cpp", 0x9f2, "Halt");
			}
			mDoExt_SaveCurrentHeap = JKRHeap::sCurrentHeap;
			mDoExt_setCurrentHeap(pHeap);
		}
		return (JKRSolidHeap *)pHeap;
	}

	void mDoExt_restoreCurrentHeap(void) {
		os::OSThread *pOVar1;
		ulong uVar2;

		pOVar1 = os::OSGetCurrentThread();
		if (pOVar1 != &m_Do_main::mainThread) {
			auto uVar2 = JUTAssertion::getSDevice();
			uVar2->showAssert("m_Do_ext.cpp", 0xac2, "OSGetCurrentThread() == &mainThread");
			m_Do_printf::OSPanic("m_Do_ext.cpp", 0xac2, "Halt");
		}
		if (mDoExt_SaveCurrentHeap == (JKRHeap *)0x0) {
			auto uVar2 = JUTAssertion::getSDevice();
			uVar2->showAssert("m_Do_ext.cpp", 0xac3, "mDoExt_SaveCurrentHeap != 0");
			m_Do_printf::OSPanic("m_Do_ext.cpp", 0xac3, "Halt");
		}
		mDoExt_SaveCurrentHeap->becomeCurrentHeap();
		mDoExt_SaveCurrentHeap = (JKRHeap *)0x0;
	}

	uint mDoExt_adjustSolidHeap(JKRSolidHeap *param_1) {
		uint uVar1;
		return 0;

		if (!param_1) {
			return 0;
		}

		//uVar1 = param_1->adjustSize();

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

	JKRSolidHeap *mDoExt_createSolidHeapFromGameToCurrent(int maxHeapSize, int param_2) {
		JKRExpHeap *pGameHeap;
		JKRSolidHeap *pJVar1;

		mDoExt_getGameHeap();
		pGameHeap = mDoExt_getGameHeap();
		return mDoExt_createSolidHeapToCurrent(maxHeapSize, pGameHeap, param_2);
	}

	void mDoExt_destroySolidHeap(JKRSolidHeap *param_1) {
		param_1->destroy();
	}
}