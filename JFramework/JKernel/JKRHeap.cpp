#include "JKRHeap.h"

#include <doltypes.h>
#include <machine/dolphin/printf.h>

#include "../../dolphin/os.h"
#include "../JSupport/JSUIosBase.h"
#include "../JUtility/JUTAssert.h"
#include "JKRExpHeap.h"
#include "JKernel.h"

char JKRHeap::sDefaultFillFlag = 1;

void (*JKRHeap::mErrorHandler)(JKRHeap *, u32, u32);

JKRExpHeap *JKRHeap::sRootHeap;
JKRExpHeap *JKRHeap::sSystemHeap;
JKRHeap *JKRHeap::sCurrentHeap;

char *JKRHeap::mCodeStart;
int JKRHeap::mMemorySize;
char *JKRHeap::mCodeEnd;
void *JKRHeap::mUserRamStart;
void *JKRHeap::mUserRamEnd;

JKRHeap *JKRHeap::findFromRoot(void *param_1) {
	JKRHeap *pJVar1;

	if (JKRHeap::sRootHeap == (JKRHeap *)0x0) {
		return nullptr;
	}
	return JKRHeap::sRootHeap->find(param_1);
}

JKRHeap *JKRHeap::find(void *pPtr) {
	JKRHeap *pJVar1;
	JSUPtrLink *pJVar2;

	if ((pPtr < this->mpDataBegin) || (this->mpDataEnd <= pPtr)) {
		return nullptr;
	}

	pJVar1 = this;
	if ((this->mChildHeap).mCount != 0) {
		pJVar2 = (this->mChildHeap).mpHead;
		if (pJVar2) {
			pJVar2 = (JSUPtrLink *)&pJVar2[-1].mpList;
		}
		while ((pJVar1 = this, pJVar2 != (JSUPtrLink *)0x0 &&
								   (pJVar1 = ((JKRHeap *)pJVar2->mpNext)->find(pPtr),
									pJVar1 == (JKRHeap *)0x0))) {
			pJVar2 = pJVar2[1].mpPrev;
			if (pJVar2) {
				pJVar2 = (JSUPtrLink *)&pJVar2[-1].mpList;
			}
		}
	}

	return pJVar1;
}

JKRHeap::JKRHeap(void *pData, unsigned long size, JKRHeap *pParent, bool pReportErrors) : JKRDisposer(), mChildHeapLink(this) {
	mChildHeap.initiate();
	mList.initiate();
	os::OSInitMutex(&mMutex);
	mSize = size;
	mpDataBegin = pData;
	mpDataEnd = (void *)(((char *)mpDataBegin) + size);
	if (!pParent) {
		becomeSystemHeap();
		becomeCurrentHeap();
	} else {
		JSUPtrLink *pLink = (JSUPtrLink *)&this->mChildHeap;

		if (pLink) {
			pLink = &this->mChildHeapLink;
		}

		pParent->mChildHeap.append(pLink);

		if (JKRHeap::sSystemHeap == JKRHeap::sRootHeap) {
			becomeSystemHeap();
		}

		if (JKRHeap::sCurrentHeap == JKRHeap::sRootHeap) {
			becomeCurrentHeap();
		}
	}

	this->mbReportErrors = pReportErrors;
	if (this->mbReportErrors && !JKRHeap::mErrorHandler) {
		JKRHeap::mErrorHandler = JKernel::JKRDefaultMemoryErrorRoutine;
	}
	this->mFillFlag = JKRHeap::sDefaultFillFlag;
	this->mbReportWarnings = false;
}

JKRHeap *JKRHeap::becomeSystemHeap() {
	auto ret = sSystemHeap;
	sSystemHeap = (JKRExpHeap *)this;
	return ret;
}

JKRHeap *JKRHeap::becomeCurrentHeap() {
	auto ret = sCurrentHeap;
	sCurrentHeap = this;
	return ret;
}

bool JKRHeap::initArena(char **param_1, unsigned long *param_2, int param_3) {
	char *pcVar1;
	void *pvVar2;
	void *uVar3;
	void *uVar4;
	void *iVar5;

	uVar3 = os::OSGetArenaLo();
	uVar4 = os::OSGetArenaHi();
	if (uVar3 != uVar4) {
		iVar5 = os::OSInitAlloc(uVar3, uVar4, param_3);
		pcVar1 = (char *)((long)iVar5 + 0x1fU & 0xffffffe0);
		pvVar2 = (void *)((unsigned long)uVar4 & 0xffffffe0);
#ifdef DOLPHIN
		JKRHeap::mCodeStart = &DAT_80000000;
		JKRHeap::mMemorySize = DAT_80000028;
#else
		JKRHeap::mCodeStart = nullptr;
		JKRHeap::mMemorySize = 0x01800000;
#endif
		JKRHeap::mCodeEnd = pcVar1;
		JKRHeap::mUserRamStart = pcVar1;
		JKRHeap::mUserRamEnd = pvVar2;
		os::OSSetArenaLo(pvVar2);
		os::OSSetArenaHi(pvVar2);
		*param_1 = pcVar1;
		*param_2 = (int)pvVar2 - (int)pcVar1;
	}
	return uVar3 != uVar4;
}

JKRHeap::~JKRHeap() {
	JSUPtrLink *pJVar1;

	pJVar1 = (JSUPtrLink *)&this->mChildHeap;
	if (pJVar1) {
		pJVar1 = &this->mChildHeapLink;
	}
	(this->mChildHeapLink).mpList->remove(pJVar1);
	if (pJVar1) {
		pJVar1 = (JSUPtrLink *)&pJVar1[-1].mpList;
	}
	if ((sCurrentHeap == this) &&
		(sCurrentHeap = JKRHeap::sRootHeap, pJVar1)) {
		sCurrentHeap = (JKRHeap *)pJVar1->mpNext;
	}
	if ((sSystemHeap == this) &&
		(sSystemHeap = sRootHeap, pJVar1)) {
		sSystemHeap = (JKRExpHeap *)pJVar1->mpNext;
	}
}

void *JKRHeap::alloc(unsigned long size, int param_2) {
	void *pvVar2;

	if (this->mbReportWarnings) {
		auto uVar1 = JUTAssertion::getSDevice();
		uVar1->setWarningMessage_f("JKRHeap.cpp", 0x134, "alloc %x byte in heap %x", size, this);
	}
	pvVar2 = do_alloc(size, param_2);
	return pvVar2;
}

void *JKRHeap::alloc(unsigned long size, int param_2, JKRHeap *pHeap) {
	void *pvVar1;

	if (pHeap == (JKRHeap *)0x0) {
		if (JKRHeap::sCurrentHeap == (JKRHeap *)0x0) {
			pvVar1 = (void *)0x0;
		} else {
			pvVar1 = JKRHeap::sCurrentHeap->alloc(size, param_2);
		}
	} else {
		pvVar1 = pHeap->alloc(size, param_2);
	}
	return pvVar1;
}

void JKRHeap::free(void *__ptr, JKRHeap *param_2) {
	if ((param_2 != (JKRHeap *)0x0) ||
		(param_2 = JKRHeap::findFromRoot(__ptr), param_2 != (JKRHeap *)0x0)) {
		param_2->free(__ptr);
	}
}

void JKRHeap::free(void *__ptr) {
	if (this->mbReportWarnings) {
		auto uVar1 = JUTAssertion::getSDevice();
		uVar1->setWarningMessage_f("JKRHeap.cpp", 0x164, "free %x in heap %x", __ptr, this);
	}
	do_free(__ptr);
}

void JKRHeap::callAllDisposer() {
	JSUPtrLink *pJVar1;
	JKRHeap *piVar2;

	while (pJVar1 = (this->mList).mpHead, pJVar1) {
		piVar2 = (JKRHeap *)pJVar1->mpData;
		piVar2->~JKRHeap();	 // hope it correctly rectifies the head pointer
	}
}

void JKRHeap::freeAll() {
	if (this->mbReportWarnings) {
		auto uVar1 = JUTAssertion::getSDevice();
		uVar1->setWarningMessage_f("JKRHeap.cpp", 0x198, "freeAll in heap %x", this);
	}
	do_freeAll();
}

void JKRHeap::freeTail() {
	if (this->mbReportWarnings) {
		auto uVar1 = JUTAssertion::getSDevice();
		uVar1->setWarningMessage_f("JKRHeap.cpp", 0x1a6, "freeTail in heap %x", this);
	}
	do_freeTail();
}

int JKRHeap::resize(void *param_1, ulong param_2, JKRHeap *param_3) {
	int iVar1;

	if ((param_3 == (JKRHeap *)0x0) &&
		(param_3 = JKRHeap::findFromRoot(param_1), param_3 == (JKRHeap *)0x0)) {
		iVar1 = -1;
	} else {
		iVar1 = param_3->resize(param_1, param_2);
	}
	return iVar1;
}

int JKRHeap::resize(void *param_1, unsigned long param_2) {
	if (this->mbReportWarnings) {
		auto uVar1 = JUTAssertion::getSDevice();
		uVar1->setWarningMessage_f("JKRHeap.cpp", 0x1d2, "resize block %x into %x in heap %x", param_1);
	}
	return do_resize(param_1, param_2);
}

int JKRHeap::do_getCurrentGroupId() {
	return 0;
}

int JKRHeap::do_changeGroupID(char param_1) {
	return 0;
}

void JKRHeap::state_register(TState *param_1, unsigned long param_2) {
	if (param_1 == (TState *)0x0) {
		auto uVar1 = JUTAssertion::getSDevice();
		uVar1->showAssert("JKRHeap.cpp", 0x442, "p != 0");
		m_Do_printf::OSPanic("JKRHeap.cpp", 0x442, "Halt");
	}
	if (param_1->heap != this) {
		auto uVar1 = JUTAssertion::getSDevice();
		uVar1->showAssert("JKRHeap.cpp", 0x443, "p->getHeap() == this");
		m_Do_printf::OSPanic("JKRHeap.cpp", 0x443, "Halt");
	}
}
unsigned JKRHeap::state_compare(TState *param_1, TState *param_2) {
	unsigned uVar1;

	if (param_1->heap != param_2->heap) {
		auto uVar2 = JUTAssertion::getSDevice();
		uVar2->showAssert("JKRHeap.cpp", 1099, "r1.getHeap() == r2.getHeap()");
		m_Do_printf::OSPanic("JKRHeap.cpp", 1099, "Halt");
	}
	return !!((int)param_2->check_code - (int)param_1->check_code);
}

void JKRHeap::state_dump(TState *param_1) {
	auto pJVar1 = JUTAssertion::getSDevice();
	pJVar1->setLogMessage_f("JKRHeap.cpp", 0x463, "check-code : 0x%08x", param_1->check_code);
	pJVar1->setLogMessage_f("JKRHeap.cpp", 0x464, "id         : 0x%08x", param_1->id);
	pJVar1->setLogMessage_f("JKRHeap.cpp", 0x465, "used size  : %u", param_1->used_size);
}

// TODO: check if correct
int JKRHeap::getSize(void *param_1, JKRHeap *param_2) {
	int iVar1;

	if ((param_2 == (JKRHeap *)0x0) &&
		(param_2 = JKRHeap::findFromRoot(param_1), param_2 == (JKRHeap *)0x0)) {
		iVar1 = -1;
	} else {
		iVar1 = param_2->getSize(param_1);
	}
	return iVar1;
}

int JKRHeap::getSize(void *param_1) {
	return do_getSize(param_1);
}

uint JKRHeap::getFreeSize() {
	return do_getFreeSize();
}

int JKRHeap::dump_sort() {
	return 1;
}

void *JKRHeap::getMaxFreeBlock() {
	return do_getMaxFreeBlock();
}

uint JKRHeap::getTotalFreeSize() {
	return do_getTotalFreeSize();
}

int JKRHeap::getCurrentGroupId() {
	return do_getCurrentGroupId();
}

unsigned JKRHeap::getMaxAllocatableSize(int param_1) {
	ulong uVar1;
	int iVar2;

	uVar1 = (ulong)do_getMaxFreeBlock();
	iVar2 = getFreeSize();
	return ~(param_1 - 1U) & iVar2 - (param_1 - 1U & param_1 - (uVar1 & 0xf));
}

void JKRHeap::dispose_subroutine(ulong param_1, ulong param_2) {
	JSUPtrLink *pJVar1;
	JKRHeap *piVar2;
	JSUPtrLink *pJVar2;
	JSUPtrLink *pJVar3;

	pJVar1 = (this->mList).mpHead;
	pJVar3 = (JSUPtrLink *)0x0;
	while (pJVar2 = pJVar1, pJVar2 != (JSUPtrLink *)0x0) {
		piVar2 = (JKRHeap *)pJVar2->mpData;
		if ((piVar2 < (void *)param_1) || ((void *)param_2 <= piVar2)) {
			pJVar1 = pJVar2->mpNext;
			pJVar3 = pJVar2;
		} else {
			piVar2->~JKRHeap();
			if (pJVar3 == (JSUPtrLink *)0x0) {
				pJVar1 = (this->mList).mpHead;
			} else {
				pJVar1 = pJVar3->mpNext;
			}
		}
	}
}

int JKRHeap::dispose(void *param_1, ulong param_2) {
	dispose_subroutine((ulong)param_1, (int)param_1 + param_2);
	return 0;
}

void JKRHeap::dispose(void *param_1, void *param_2) {
	dispose_subroutine((ulong)param_1, (ulong)param_2);
}

void JKRHeap::dispose() {
	JSUPtrLink *pJVar1;
	JKRHeap *piVar2;

	while (pJVar1 = (this->mList).mpHead, pJVar1 != (JSUPtrLink *)0x0) {
		piVar2 = (JKRHeap *)pJVar1->mpData;
		piVar2->~JKRHeap();
	}
}

void JKRHeap::copyMemory(void *param_1, void *param_2, ulong param_3) {
	uint uVar1;

	uVar1 = param_3 + 3 >> 2;
	if (uVar1 == 0) {
		return;
	}
	do {
		/* WARNING: Load size is inaccurate */
		*(undefined4 *)param_1 = *(undefined4 *)param_2;
		param_1 = (void *)((int)param_1 + 4);
		param_2 = (void *)((int)param_2 + 4);
		uVar1 = uVar1 - 1;
	} while (uVar1 != 0);
}

bool JKRHeap::setErrorFlag(bool param_1) {
	bool bVar1;

	bVar1 = this->mbReportErrors;
	this->mbReportErrors = param_1;
	return bVar1;
}

void *JKRHeap::setErrorHandler(void (*param_1)(JKRHeap *, u32, u32)) {
	void *puVar1;

	if (param_1 == nullptr) {
		param_1 = JKernel::JKRDefaultMemoryErrorRoutine;
	}
	puVar1 = JKRHeap::mErrorHandler;
	JKRHeap::mErrorHandler = param_1;
	return puVar1;
}
