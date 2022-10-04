#pragma once

#include <doltypes.h>

struct J2DPrint {
	static char *mStrBuff;
	static byte mHeapFlag;
	static uint mStrBuffSize;

	static char *setBuffer(uint param_1);
};