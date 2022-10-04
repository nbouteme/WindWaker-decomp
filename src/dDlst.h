#pragma once

#include <dolphin/gx.h>

struct dDlst_peekZ_c__Entry {
	short mX, mY;
	u32 *mpDest;
};

struct dDlst_peekZ_c {
	char mCount;
	dDlst_peekZ_c__Entry mEntries[50];	// apparently 64?

	undefined4 newData(short param_1, short param_2, u32 *param_3);

	void peekData();
};

struct dDlst_list_c {
	dDlst_peekZ_c mPeekZ;

	void reset();
};