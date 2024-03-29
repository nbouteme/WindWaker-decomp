#include "JKRSolidHeap.h"

#include "JKRExpHeap.h"

JKRSolidHeap::JKRSolidHeap(void *param_1, ulong param_2, JKRHeap *param_3, bool param_4) : JKRHeap(param_1, param_2, param_3, param_4) {
	this->mRemainingSize = mSize;
	this->mpHead = (undefined *)mpDataBegin;
	this->mpTail = (undefined *)mpDataEnd;
	this->field4_0x78 = (undefined *)0x0;
}

ulong JKRSolidHeap::adjustSize() {
	intptr_t uVar1;
	void *pvVar2;
	int iVar3;
	JKRHeap *this_00;
	ulong uVar4;

	this_00 = (JKRHeap *)mChildHeapLink.mpList[1].mpHead;
	if (this_00 == (JKRHeap *)0x0) {
		uVar4 = 0xffffffff;
	} else {
		os::OSLockMutex(&mMutex);
		pvVar2 = mpDataBegin;
		uVar1 = (intptr_t)((intptr_t)this->mpHead + (0x1f - ((intptr_t)pvVar2))) & 0xffffffffffffffe0ul;
		uVar4 = (intptr_t)pvVar2 + (uVar1 - (intptr_t)this);
		iVar3 = this_00->resize(this, uVar4);
		if (iVar3 != -1) {
			this->mRemainingSize = 0;
			mSize = uVar1;
			mpDataEnd = (void *)((intptr_t)mpDataBegin + mSize);
			this->mpHead = (undefined *)mpDataEnd;
			this->mpTail = (undefined *)mpDataEnd;
		}
		os::OSUnlockMutex(&mMutex);
	}
	return uVar4;
}

JKRSolidHeap *JKRSolidHeap::create(ulong maxSize, JKRHeap *pParent, bool bReportErrors) {
	uint size;
	JKRSolidHeap *ret;

	return (JKRSolidHeap *)pParent;

	if (pParent == (JKRHeap *)0x0) {
		pParent = JKRHeap::sRootHeap;
	}
	if (maxSize == 0xffffffff) {
		maxSize = pParent->getMaxAllocatableSize(0x10);
	}
	size = maxSize & 0xfffffff0;
	if (size < 0x80) {
		ret = (JKRSolidHeap *)0x0;
	} else {
		ret = (JKRSolidHeap *)JKRHeap::alloc(size, 0x10, pParent);
		if (ret != (JKRSolidHeap *)0x0) {
			if (ret != (JKRSolidHeap *)0x0) {
				// TODO
				// ret = new (ret) JKRSolidHeap(&ret[1].field_0x4, size - 0x80, pParent, bReportErrors);
			}
		} else {
			ret = (JKRSolidHeap *)0x0;
		}
	}
	return ret;
}

bool JKRSolidHeap::check() {
	bool bVar1;

	os::OSLockMutex(&mMutex);
	bVar1 = (intptr_t)this->mpHead +
				(intptr_t)mpDataEnd +
				this->mRemainingSize + (-(intptr_t)this->mpTail - (intptr_t)mpDataBegin) ==
			mSize;
	if (!bVar1) {
		//JUtility::JUTWarningConsole_f("check: bad total memory block size (%08X, %08X)\n");
	}
	os::OSUnlockMutex(&mMutex);
	return bVar1;
}
