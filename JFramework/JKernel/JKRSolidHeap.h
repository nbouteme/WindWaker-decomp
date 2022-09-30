#pragma once

#include <dolphin/os.h>

#include "JKRHeap.h"

struct JKRSolidHeap : public JKRHeap {
	ulong mRemainingSize;
	void *mpHead;
	void *mpTail;
	undefined *field4_0x78;

	JKRSolidHeap(void *param_1, ulong param_2, JKRHeap *param_3, bool param_4);

	ulong adjustSize();

	static JKRSolidHeap *create(ulong maxSize, JKRHeap *pParent, bool bReportErrors);

	bool check();
};