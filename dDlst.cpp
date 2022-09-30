#include "dDlst.h"

undefined4 dDlst_peekZ_c::newData(short param_1, short param_2, u32 *param_3) {
	dDlst_peekZ_c__Entry *pdVar1;

	if (0x3f < (byte)this->mCount) {
		return 0;
	}
	pdVar1 = this->mEntries + (byte)this->mCount;
	pdVar1->mX = param_1;
	pdVar1->mY = param_2;
	pdVar1->mpDest = param_3;
	this->mCount = this->mCount + '\x01';
	return 1;
}

void dDlst_peekZ_c::peekData() {
	int iVar1;
	dDlst_peekZ_c__Entry *pdVar2;

	pdVar2 = this->mEntries;
	for (iVar1 = 0; iVar1 < this->mCount; iVar1 = iVar1 + 1) {
		gx::GXPeekZ(pdVar2->mX, pdVar2->mY, pdVar2->mpDest);
		pdVar2 = pdVar2 + 1;
	}
	this->mCount = 0;
}

void dDlst_list_c::reset() {
    //TODO
}