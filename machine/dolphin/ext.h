#pragma once
#include <JFramework/JKernel/JKRExpHeap.h>
#include <JFramework/JKernel/JKRHeap.h>
#include <JFramework/JKernel/JKRSolidHeap.h>
#include <JFramework/JUtility/JUTAssert.h>

#include "./main.h"
#include "./printf.h"

namespace m_Do_ext {
	extern JKRHeap *mDoExt_SaveCurrentHeap;
	extern JKRExpHeap *zeldaHeap, *gameHeap, *archiveHeap, *commandHeap;

	JKRSolidHeap *mDoExt_createSolidHeap(int maxHeapSize, JKRHeap *param_2, uint param_3);
	void mDoExt_setCurrentHeap(JKRHeap *param_1);
	JKRSolidHeap *mDoExt_createSolidHeapToCurrent(int maxHeapSize, JKRHeap *param_2, uint param_3);
	void mDoExt_restoreCurrentHeap(void);
	uint mDoExt_adjustSolidHeap(JKRSolidHeap *param_1);
	JKRExpHeap *mDoExt_getZeldaHeap();
	JKRExpHeap *mDoExt_getGameHeap();
	JKRExpHeap *mDoExt_getArchiveHeap();
	JKRExpHeap *mDoExt_getCommandHeap();
	void mDoExt_createCommandHeap(ulong param_1, JKRHeap *param_2);
	JKRHeap *mDoExt_createArchiveHeap(ulong param_1, JKRHeap *param_2);
	JKRHeap *mDoExt_createGameHeap(ulong param_1, JKRHeap *param_2);
	JKRHeap *mDoExt_createZeldaHeap(ulong param_1, JKRHeap *param_2);

}