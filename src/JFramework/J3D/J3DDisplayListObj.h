#pragma once

#include <dolphin/gd.h>

#include "J3DPacket.h"

struct J3DDisplayListObj {
	void *mpData[2];
	int mSize;
	int mCapacity;
	static int sInterruptFlag;

	static gd::GDLObj sGDLObj;

	void beginDL();
	void beginPatch();
	void swapBuffer();
	void callDL();
	int endDL();
	int endPatch();

	int newDisplayList(unsigned param_1);
	int newSingleDisplayList(unsigned param_1);
	void setSingleDisplayList(void *pData, unsigned size);
	int single_To_Double();
};
