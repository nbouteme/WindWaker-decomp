#include "JKRExpHeap.h"
#include "../JKernel/JKernel.h"
#include "../JUtility/JUtility.h"
#include "../JUtility/JUTAssert.h"
#include <machine/dolphin/printf.h>

void JKRExpHeap::CMemBlock::initiate(CMemBlock *param_1, CMemBlock *param_2, ulong param_3, uchar param_4, uchar param_5) {
	this->id = 0x484d;
	this->fill2 = param_5;
	this->fill3 = param_4;
	this->addrsize = param_3;
	this->prev = param_1;
	this->next = param_2;
}

int JKRExpHeap::CMemBlock::allocFore(ulong param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5) {
	int iVar1;

	iVar1 = 0;
	this->fill3 = param_2;
	this->fill2 = param_3;
	if (param_1 + 0x10 <= this->addrsize) {
		(&this[1].fill3)[param_1] = param_4;
		(&this[1].fill2)[param_1] = param_5;
		*(ulong *)((int)&this[1].addrsize + param_1) = this->addrsize - (param_1 + 0x10);
		this->addrsize = param_1;
		iVar1 = (int)&this[1].id + param_1;
	}
	return iVar1;
}

JKRExpHeap::CMemBlock *JKRExpHeap::CMemBlock::allocBack(ulong param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5) {
	CMemBlock *iVar1;

	iVar1 = nullptr;
	if (this->addrsize < param_1 + 0x10) {
		this->fill3 = param_4;
		this->fill2 = 0x80;
	} else {
		iVar1 = (CMemBlock *)((int)this + (this->addrsize - param_1));
		iVar1->fill3 = param_4;
		iVar1->fill2 = param_5 | 0x80;
		iVar1->addrsize = param_1;
		this->fill3 = param_2;
		this->fill2 = param_3;
		this->addrsize = this->addrsize - (param_1 + 0x10);
	}
	return iVar1;
}

void JKRExpHeap::CMemBlock::free(void *__ptr) {
	JKRExpHeap::removeUsedBlock((JKRExpHeap *)__ptr, this);
	((JKRExpHeap *)__ptr)->recycleFreeBlock(this);
}

JKRExpHeap::CMemBlock *JKRExpHeap::CMemBlock::getHeapBlock(void *param_1) {
	if ((param_1) && (((CMemBlock *)((int)param_1 + -0x10))->id == 0x484d)) {
		return (CMemBlock *)((int)param_1 + -0x10);
	}
	return nullptr;
}

void JKRExpHeap::recycleFreeBlock(CMemBlock *param_1) {
	uint uVar1;
	CMemBlock *pCVar2;
	CMemBlock *pCVar3;
	ulong uVar4;

	uVar4 = param_1->addrsize;
	pCVar3 = (CMemBlock *)((int)&param_1->id + uVar4);
	param_1->id = 0;
	uVar1 = (byte)param_1->fill2 & 0x7f;
	if ((param_1->fill2 & 0x7f) != 0) {
		param_1 = (CMemBlock *)((int)param_1 - uVar1);
		uVar4 = uVar4 + uVar1;
		pCVar3 = (CMemBlock *)((int)&param_1->id + uVar4);
		param_1->fill3 = 0;
		param_1->fill2 = 0;
		param_1->addrsize = uVar4;
	}
	pCVar2 = this->freelist;
	if (pCVar2 == nullptr) {
		param_1->initiate(nullptr, nullptr, uVar4, 0, 0);
		this->freelist = param_1;
		this->freelistend = param_1;
		setFreeBlock(param_1, nullptr, nullptr);
	} else if (pCVar2 < pCVar3) {
		if (param_1 < this->freelistend) {
			for (; pCVar2; pCVar2 = pCVar2->next) {
				if ((pCVar2 < param_1) && (param_1 < pCVar2->next)) {
					param_1->next = pCVar2->next;
					param_1->prev = pCVar2;
					pCVar2->next = param_1;
					param_1->next->prev = param_1;
					param_1->fill3 = 0;
					joinTwoBlocks(param_1);
					joinTwoBlocks(pCVar2);
					return;
				}
			}
		} else {
			param_1->initiate(nullptr, nullptr, uVar4, 0, 0);
			setFreeBlock(param_1, this->freelistend, nullptr);
			joinTwoBlocks(param_1->prev);
		}
	} else {
		param_1->initiate(nullptr, nullptr, uVar4, 0, 0);
		setFreeBlock(param_1, nullptr, this->freelist);
		joinTwoBlocks(param_1);
	}
	return;
}

void JKRExpHeap::joinTwoBlocks(CMemBlock *param_1) {
	CMemBlock *pCVar1;
	uint uVar2;
	CMemBlock *pCVar3;
	uint uVar4;

	pCVar3 = param_1->next;
	uVar2 = (int)pCVar3 - ((byte)pCVar3->fill2 & 0x7f);
	uVar4 = (int)&param_1[1].id + param_1->addrsize;
	if (uVar2 < uVar4) {
		JUtility::JUTWarningConsole_f(":::Heap may be broken. (block = %x)", uVar2);
		m_Do_printf::OSReport(":::block = %x\n", param_1);
		pCVar1 = param_1->next;
		m_Do_printf::OSReport(":::joinTwoBlocks [%x %x %x][%x %x %x]\n", param_1, (uint)(byte)param_1->fill2,
							  param_1->addrsize, pCVar1, (uint)(byte)pCVar1->fill2, pCVar1->addrsize);
		m_Do_printf::OSReport(":::: endAddr = %x\n", uVar4);
		m_Do_printf::OSReport(":::: nextAddr = %x\n", uVar2);
		JKRHeap::sCurrentHeap->dump();
		m_Do_printf::OSPanic("JKRExpHeap.cpp", 0x6b6, ":::: Bad Block\n");
	}
	if (uVar4 == uVar2) {
		param_1->addrsize = pCVar3->addrsize + ((byte)pCVar3->fill2 & 0x7f) + param_1->addrsize + 0x10;
		setFreeBlock(param_1, param_1->prev, pCVar3->next);
	}
	return;
}

void JKRExpHeap::setFreeBlock(CMemBlock *param_1, CMemBlock *param_2, CMemBlock *param_3) {
	if (param_2 == nullptr) {
		this->freelist = param_1;
		param_1->prev = nullptr;
	} else {
		param_2->next = param_1;
		param_1->prev = param_2;
	}
	if (param_3 == nullptr) {
		this->freelistend = param_1;
		param_1->next = nullptr;
	} else {
		param_3->prev = param_1;
		param_1->next = param_3;
	}
	param_1->id = 0;
}

void JKRExpHeap::removeUsedBlock(JKRExpHeap *self, CMemBlock *param_1) {
	CMemBlock *puVar1;
	CMemBlock *puVar2;

	puVar2 = param_1->prev;
	puVar1 = param_1->next;
	if (puVar2 == nullptr) {
		self->head = puVar1;
	} else {
		puVar2->next = puVar1;
	}
	if (puVar1 == nullptr) {
		self->tail = puVar2;
		return;
	}
	puVar1->prev = puVar2;
}

int JKRExpHeap::getTotalUsedSize() {
	CMemBlock *pCVar1;
	int iVar2;

	os::OSLockMutex(&mMutex);
	iVar2 = 0;
	for (pCVar1 = this->head; pCVar1; pCVar1 = pCVar1->next) {
		iVar2 += pCVar1->addrsize + 0x10;
	}
	os::OSUnlockMutex(&mMutex);
	return iVar2;
}

JKRHeap *JKRExpHeap::createRoot(int param_1, bool param_2) {
	JKRExpHeap *pJVar1;
	JKRExpHeap *pJVar2;
	ulong local_18;
	JKRExpHeap *local_14[4];

	pJVar2 = (JKRExpHeap *)0x0;
	pJVar1 = (JKRExpHeap *)JKRHeap::sRootHeap;
	if (JKRHeap::sRootHeap == (JKRHeap *)0x0) {
		JKRHeap::initArena((char **)local_14, &local_18, param_1);
		pJVar2 = local_14[0];
		pJVar1 = local_14[0];
		if (local_14[0] != (JKRExpHeap *)0x0) {
			new (local_14[0]) JKRExpHeap(local_14[0] + 1, local_18 - 0x90, (JKRHeap *)0x0, param_1);
			//local_14[0]->JKRExpHeap(local_14[0] + 1, local_18 - 0x90, (JKRHeap *)0x0, param_1);
			pJVar2 = local_14[0];
			pJVar1 = local_14[0];
		}
	}
	JKRHeap::sRootHeap = pJVar1;
	pJVar2->field3_0x6e = 1;
	return pJVar2;
}

void JKRExpHeap::dump() {
}

uint JKRExpHeap::getHeapType() {
	return 0x45585048;
}

uint JKRExpHeap::do_getFreeSize() {
}

int JKRExpHeap::do_getCurrentGroupId() {
}

uint JKRExpHeap::do_getTotalFreeSize() {
	CMemBlock *pCVar1;
	int iVar2;

	iVar2 = 0;
	os::OSLockMutex(&mMutex);
	for (pCVar1 = this->freelist; pCVar1 != (CMemBlock *)0x0; pCVar1 = pCVar1->next) {
		iVar2 += pCVar1->addrsize;
	}
	os::OSUnlockMutex(&mMutex);
	return iVar2;
}

JKRExpHeap::CMemBlock *JKRExpHeap::do_getMaxFreeBlock() {
	ulong uVar1;
	CMemBlock *pCVar2;
	CMemBlock *pCVar3;

	os::OSLockMutex(&mMutex);
	uVar1 = 0;
	pCVar3 = (CMemBlock *)0x0;
	for (pCVar2 = this->freelist; pCVar2 != (CMemBlock *)0x0; pCVar2 = pCVar2->next) {
		if ((int)uVar1 < (int)pCVar2->addrsize) {
			uVar1 = pCVar2->addrsize;
			pCVar3 = pCVar2;
		}
	}
	os::OSUnlockMutex(&mMutex);
	return pCVar3;
}

JKRExpHeap *JKRExpHeap::create(ulong param_1, JKRHeap *param_2, bool param_3) {
	uint size;
	JKRExpHeap *pJVar1;
	JKRExpHeap *self;

	if (param_2 == (JKRHeap *)0x0) {
		param_2 = JKRHeap::sRootHeap;
	}
	if (param_1 == 0xffffffff) {
		param_1 = param_2->getMaxAllocatableSize(0x10);
	}
	size = param_1 & 0xfffffff0;
	if (size < 0xa0) {
		pJVar1 = (JKRExpHeap *)0x0;
	} else {
		self = (JKRExpHeap *)JKRHeap::alloc(size, 0x10, param_2);
		if (self != (JKRExpHeap *)0x0) {
			pJVar1 = self;
			if (self != (JKRExpHeap *)0x0) {
				new (self) JKRExpHeap(self + 1, size - 0x90, param_2, param_3);
			}
			if (pJVar1 == (JKRExpHeap *)0x0) {
				JKRHeap::free(self, (JKRHeap *)0x0);
				pJVar1 = (JKRExpHeap *)0x0;
			} else {
				pJVar1->field3_0x6e = 0;
			}
		} else {
			pJVar1 = (JKRExpHeap *)0x0;
		}
	}
	return pJVar1;
}

void JKRExpHeap::destroy() {
	do_destroy();
}

char field3_0x6e;

void JKRExpHeap::do_destroy() {
	JKRHeap *pJVar1;

	if (this->field3_0x6e == 0) {
		pJVar1 = (JKRHeap *)this->mChildHeapLink.mpList[1].mpHead;
		if (pJVar1 != (JKRHeap *)0x0) {
			this->~JKRExpHeap();
			JKRHeap::free(this, pJVar1);
		}
	} else {
		this->~JKRExpHeap();
	}
	return;
}

char field1_0x6c, gid;

JKRExpHeap::JKRExpHeap(void *param_1, ulong param_2, JKRHeap *param_3, bool param_4) : JKRHeap(param_1, param_2, param_3, param_4) {
	this->field1_0x6c = 0;
	this->gid = 0xff;
	this->freelist = (CMemBlock *)param_1;
	this->freelistend = this->freelist;
	this->freelist->initiate(nullptr, nullptr, param_2 - 0x10, 0, 0);
	this->head = nullptr;
	this->tail = nullptr;
}

JKRExpHeap::~JKRExpHeap() {
	dispose();
}

void JKRExpHeap::appendUsedList(CMemBlock *param_1) {
	CMemBlock *pCVar1;

	if (param_1 == nullptr) {
		m_Do_printf::OSPanic("JKRExpHeap.cpp", 0x5ba, ":::ERROR! appendUsedList\n");
	}
	pCVar1 = this->tail;
	param_1->id = 0x484d;
	if (pCVar1 == nullptr) {
		param_1->prev = nullptr;
	} else {
		pCVar1->next = param_1;
		param_1->prev = pCVar1;
	}
	this->tail = param_1;
	if (this->head == nullptr) {
		this->head = param_1;
	}
	param_1->next = nullptr;
}

JKRExpHeap::CMemBlock *JKRExpHeap::allocFromTail(uint param_1) {
	uint uVar1;
	CMemBlock *pCVar2;
	CMemBlock *pCVar3;
	CMemBlock *this_00;

	uVar1 = param_1 + 3 & 0xfffffffc;
	for (pCVar2 = this->freelistend;
		 (this_00 = nullptr, pCVar2 &&
								 (this_00 = pCVar2, pCVar2->addrsize < uVar1));
		 pCVar2 = pCVar2->prev) {
	}
	if (this_00 == nullptr) {
		pCVar2 = nullptr;
	} else {
		pCVar2 = (CMemBlock *)this_00->allocBack(uVar1, '\0', '\0', this->gid, '\0');
		pCVar3 = this_00;
		if (pCVar2 == nullptr) {
			removeFreeBlock(this_00);
			pCVar3 = nullptr;
			pCVar2 = this_00;
		}
		if (pCVar3) {
			setFreeBlock(pCVar3, this_00->prev, this_00->next);
		}
		appendUsedList(pCVar2);
		pCVar2 = pCVar2 + 1;
	}
	return pCVar2;
}

JKRExpHeap::CMemBlock *JKRExpHeap::allocFromTail(uint param_1, int param_2) {
	uint uVar1;
	uint uVar2;
	CMemBlock *pCVar3;
	ulong unaff_r28;
	CMemBlock *pCVar4;
	CMemBlock *pCVar5;
	uint uVar6;

	uVar6 = 0;
	pCVar4 = nullptr;
	pCVar3 = this->freelistend;
	do {
		pCVar5 = nullptr;
		if (pCVar3 == nullptr) {
		LAB_802b1cdc:
			if (pCVar5 == nullptr) {
				pCVar4 = nullptr;
			} else if (uVar6 < 0x10) {
				if (uVar6 == 0) {
					removeFreeBlock(pCVar5);
					pCVar4->initiate(nullptr, nullptr, unaff_r28, this->gid, 0x80);
					appendUsedList(pCVar4);
					pCVar4 = pCVar4 + 1;
				} else {
					removeFreeBlock(pCVar5);
					pCVar4->initiate(nullptr, nullptr, unaff_r28, this->gid, (byte)uVar6 | 0x80);
					appendUsedList(pCVar4);
					pCVar4 = pCVar4 + 1;
				}
			} else {
				pCVar4->initiate(nullptr, nullptr, unaff_r28, this->gid, 0x80);
				pCVar5->addrsize = (pCVar5->addrsize - unaff_r28) - 0x10;
				appendUsedList(pCVar4);
				pCVar4 = pCVar4 + 1;
			}
			return pCVar4;
		}
		uVar1 = pCVar3->addrsize;
		uVar2 = ~(param_2 - 1U) & (int)pCVar3 + ((uVar1 + 0x10) - param_1);
		unaff_r28 = (int)pCVar3 + ((uVar1 + 0x10) - uVar2);
		if (unaff_r28 <= uVar1) {
			uVar6 = uVar1 - unaff_r28;
			pCVar4 = (CMemBlock *)(uVar2 - 0x10);
			pCVar5 = pCVar3;
			goto LAB_802b1cdc;
		}
		pCVar3 = pCVar3->prev;
	} while (true);
}

JKRExpHeap::CMemBlock *JKRExpHeap::allocFromHead(uint param_1, int param_2) {
	uint uVar1;
	CMemBlock *pCVar2;
	CMemBlock *pCVar3;
	uint uVar4;
	CMemBlock *pCVar5;
	uint uVar6;
	CMemBlock *pCVar7;
	uint uVar8;
	CMemBlock *pCVar9;

	uVar1 = param_1 + 3 & 0xfffffffc;
	uVar4 = 0xffffffff;
	uVar8 = 0;
	pCVar9 = nullptr;
	for (pCVar5 = this->freelist; JKernel::DBfoundSize = uVar4, uVar6 = uVar8,
		pCVar5 != nullptr;
		 pCVar5 = pCVar5->next) {
		uVar6 = (~(param_2 - 1U) & (param_2 - 1U) + (int)(pCVar5 + 1)) - (int)(pCVar5 + 1);
		JKernel::DBfoundSize = pCVar5->addrsize;
		if (((uVar1 + uVar6 <= JKernel::DBfoundSize) && (JKernel::DBfoundSize < uVar4)) &&
			((pCVar9 = pCVar5, this->field1_0x6c != 0 ||
								   (uVar4 = JKernel::DBfoundSize, uVar8 = uVar6, JKernel::DBfoundSize == uVar1))))
			break;
	}
	JKernel::DBfoundOffset = uVar6;
	JKernel::DBfoundBlock = pCVar9;
	if (pCVar9 == nullptr) {
		pCVar5 = nullptr;
	} else if (uVar6 < 0x10) {
		if (uVar6 == 0) {
			pCVar2 = pCVar9->prev;
			pCVar7 = pCVar9->next;
			pCVar5 = (CMemBlock *)pCVar9->allocFore(uVar1, this->gid, '\0', '\0', '\0');
			removeFreeBlock(pCVar9);
			if (pCVar5 != nullptr) {
				setFreeBlock(pCVar5, pCVar2, pCVar7);
			}
			appendUsedList(pCVar9);
			pCVar5 = pCVar9 + 1;
		} else {
			pCVar2 = pCVar9->prev;
			pCVar7 = pCVar9->next;
			removeFreeBlock(pCVar9);
			pCVar5 = (CMemBlock *)((int)&pCVar9->id + uVar6);
			pCVar5->addrsize = pCVar9->addrsize - uVar6;
			pCVar9 = (CMemBlock *)
						 pCVar5->allocFore(uVar1, this->gid, (uchar)uVar6, '\0', '\0');
			if (pCVar9 != nullptr) {
				setFreeBlock(pCVar9, pCVar2, pCVar7);
			}
			appendUsedList(pCVar5);
			pCVar5 = pCVar5 + 1;
		}
	} else {
		pCVar7 = pCVar9->prev;
		pCVar5 = pCVar9->next;
		pCVar2 = (CMemBlock *)pCVar9->allocFore(uVar6 - 0x10, '\0', '\0', '\0', '\0');
		if (pCVar2 == nullptr) {
			pCVar3 = nullptr;
		} else {
			pCVar3 = (CMemBlock *)pCVar2->allocFore(uVar1, this->gid, '\0', '\0', '\0');
		}
		if (pCVar3 == nullptr) {
			setFreeBlock(pCVar9, pCVar7, pCVar5);
		} else {
			setFreeBlock(pCVar9, pCVar7, pCVar3);
			setFreeBlock(pCVar3, pCVar9, pCVar5);
		}
		appendUsedList(pCVar2);
		pCVar5 = pCVar2 + 1;
		JKernel::DBnewFreeBlock = pCVar3;
		JKernel::DBnewUsedBlock = pCVar2;
	}
	return pCVar5;
}

JKRExpHeap::CMemBlock *JKRExpHeap::allocFromHead(ulong param_1) {
	uint uVar1;
	uint uVar2;
	uint uVar3;
	CMemBlock *pCVar4;
	CMemBlock *pCVar5;

	uVar1 = param_1 + 3 & 0xfffffffc;
	uVar3 = 0xffffffff;
	pCVar5 = (CMemBlock *)0x0;
	for (pCVar4 = this->freelist;
		 (pCVar4 != (CMemBlock *)0x0 &&
		  (((uVar2 = pCVar4->addrsize, uVar2 < uVar1 || (uVar3 <= uVar2)) ||
			((pCVar5 = pCVar4, this->field1_0x6c == 0 && (uVar3 = uVar2, uVar2 != uVar1))))));
		 pCVar4 = pCVar4->next) {
	}
	if (pCVar5 == (CMemBlock *)0x0) {
		pCVar5 = (CMemBlock *)0x0;
	} else {
		pCVar4 = (CMemBlock *)pCVar5->allocFore(uVar1, this->gid, '\0', '\0', '\0');
		if (pCVar4 == (CMemBlock *)0x0) {
			removeFreeBlock(pCVar5);
		} else {
			setFreeBlock(pCVar4, pCVar5->prev, pCVar5->next);
		}
		appendUsedList(pCVar5);
		pCVar5 = pCVar5 + 1;
	}
	return pCVar5;
}

void *JKRExpHeap::do_alloc(ulong param_1, int param_2) {
	void *iVar1;

	os::OSLockMutex(&mMutex);
	if (param_1 < 4) {
		param_1 = 4;
	}
	if (param_2 < 0) {
		if (-param_2 < 5) {
			iVar1 = allocFromTail(param_1);
		} else {
			iVar1 = allocFromTail(param_1, -param_2);
		}
	} else if (param_2 < 5) {
		iVar1 = allocFromHead(param_1);
	} else {
		iVar1 = allocFromHead(param_1, param_2);
	}
	if (((iVar1 == 0) &&
		 (JUtility::JUTWarningConsole_f(":::cannot alloc memory (0x%x byte).\n", param_1),
		  this->mbReportErrors == true)) &&
		(JKRHeap::mErrorHandler)) {
		JKRHeap::mErrorHandler(this, param_1, param_2);
	}
	os::OSUnlockMutex(&mMutex);
	return iVar1;
}

void JKRExpHeap::do_free(void *param_1) {
	CMemBlock *this_00;
	ulong uVar1;

	os::OSLockMutex(&mMutex);
	if ((param_1 < mpDataBegin) || (mpDataEnd < param_1)) {
		auto uVar1 = JUTAssertion::getSDevice();
		uVar1->setWarningMessage_f("JKRExpHeap.cpp", 0x378, "free: memblock %x not in heap %x", param_1, this);
	} else {
		this_00 = JKRExpHeap::CMemBlock::getHeapBlock(param_1);
		if (this_00) {
			this_00->free(this);
		}
	}
	os::OSUnlockMutex(&mMutex);
	return;
}

void JKRExpHeap::do_freeAll() {
	os::OSLockMutex(&this->mMutex);
	callAllDisposer();
	this->freelist = (CMemBlock *)this->mpDataBegin;
	this->freelistend = this->freelist;
	this->freelist->initiate(nullptr, nullptr, this->mSize - 0x10, 0, 0);
	this->tail = nullptr;
	this->field10_0x84 = nullptr;
	os::OSUnlockMutex(&this->mMutex);
}

void JKRExpHeap::do_freeTail() {
	CMemBlock *pCVar1;
	CMemBlock *this_00;

	os::OSLockMutex(&mMutex);
	this_00 = this->head;
	while (true) {
		if (this_00 == nullptr)
			break;
		if ((this_00->fill2 & 0x80) == 0) {
			this_00 = this_00->next;
		} else {
			dispose(this_00 + 1, this_00->addrsize);
			pCVar1 = this_00->next;
			this_00->free(this);
			this_00 = pCVar1;
		}
	}
	os::OSUnlockMutex(&mMutex);
	return;
}

undefined JKRExpHeap::do_changeGroupID(uchar newid) {
	undefined uVar1;

	os::OSLockMutex(&mMutex);
	uVar1 = this->gid;
	this->gid = newid;
	os::OSUnlockMutex(&mMutex);
	return uVar1;
}

void JKRExpHeap::removeFreeBlock(CMemBlock *param_1) {
	CMemBlock *pCVar1;
	CMemBlock *pCVar2;

	pCVar2 = param_1->prev;
	pCVar1 = param_1->next;
	if (pCVar2 == nullptr) {
		this->freelist = pCVar1;
	} else {
		pCVar2->next = pCVar1;
	}
	if (pCVar1 == nullptr) {
		this->freelistend = pCVar2;
		return;
	}
	pCVar1->prev = pCVar2;
}

int JKRExpHeap::do_resize(void *param_1, ulong param_2) {
	CMemBlock *this_00;
	uint uVar1;
	CMemBlock *pCVar2;
	uint uVar3;
	CMemBlock *pCVar4;

	os::OSLockMutex(&mMutex);
	this_00 = JKRExpHeap::CMemBlock::getHeapBlock(param_1);
	if (((this_00 == nullptr) || (param_1 < mpDataBegin)) ||
		(mpDataEnd < param_1)) {
		os::OSUnlockMutex(&mMutex);
		uVar1 = (~0UL);
	} else {
		uVar1 = param_2 + 3 & 0xfffffffc;
		uVar3 = this_00->addrsize;
		if (uVar1 == uVar3) {
			os::OSUnlockMutex(&mMutex);
		} else {
			if (uVar3 < uVar1) {
				for (pCVar2 = this->freelist;
					 (pCVar4 = nullptr, pCVar2 &&
											(pCVar4 = pCVar2, pCVar2 != (CMemBlock *)((int)&this_00[1].id + uVar3)));
					 pCVar2 = pCVar2->next) {
				}
				if (pCVar4 == nullptr) {
					os::OSUnlockMutex(&mMutex);
					return -1;
				}
				if (uVar3 + pCVar4->addrsize + 0x10 < uVar1) {
					os::OSUnlockMutex(&mMutex);
					return -1;
				}
				removeFreeBlock(pCVar4);
				this_00->addrsize = pCVar4->addrsize + this_00->addrsize + 0x10;
				if ((0x10 < this_00->addrsize - uVar1) &&
					(pCVar2 = (CMemBlock *)
								  this_00->allocFore(uVar1, this_00->fill3, this_00->fill2, '\0', '\0'),
					 pCVar2)) {
					recycleFreeBlock(pCVar2);
				}
			} else if ((0x10 < uVar3 - uVar1) &&
					   (pCVar2 = (CMemBlock *)
									 this_00->allocFore(uVar1, this_00->fill3, this_00->fill2, '\0', '\0'),
						pCVar2)) {
				recycleFreeBlock(pCVar2);
			}
			os::OSUnlockMutex(&mMutex);
			uVar1 = this_00->addrsize;
		}
	}
	return uVar1;
}

int JKRExpHeap::do_getSize(void *param_1) {
	CMemBlock *pCVar1;
	ulong uVar2;

	os::OSLockMutex(&mMutex);
	pCVar1 = JKRExpHeap::CMemBlock::getHeapBlock(param_1);
	if (((pCVar1 == nullptr) || (param_1 < mpDataBegin)) ||
		(mpDataEnd < param_1)) {
		os::OSUnlockMutex(&mMutex);
		uVar2 = 0xffffffff;
	} else {
		os::OSUnlockMutex(&mMutex);
		uVar2 = pCVar1->addrsize;
	}
	return uVar2;
}

bool JKRExpHeap::check() {
	uint *puVar1;
	undefined1 *puVar2;
	ushort uVar3;
	int iVar4;
	CMemBlock *pCVar5;
	CMemBlock *pCVar6;
	int iVar7;
	int iVar8;

	os::OSLockMutex(&mMutex);
	iVar8 = 0;
	iVar7 = 1;
	pCVar6 = this->head;
	do {
		if (pCVar6 == (CMemBlock *)0x0) {
		LAB_802b2a30:
			for (pCVar6 = this->freelist; pCVar6 != (CMemBlock *)0x0; pCVar6 = pCVar6->next) {
				iVar8 = pCVar6->addrsize + iVar8 + 0x10;
				if (pCVar6->next == (CMemBlock *)0x0) {
					if (this->freelistend != pCVar6) {
						iVar7 = 0;
						JUtility::JUTWarningConsole_f(":::addr %08x: bad used list(REV) (%08x)\n", pCVar6);
					}
				} else {
					if (pCVar6->next->prev != pCVar6) {
						iVar7 = 0;
						JUtility::JUTWarningConsole_f(":::addr %08x: bad previous pointer (%08x)\n");
					}
					if (pCVar6->next < (CMemBlock *)((int)&pCVar6[1].id + pCVar6->addrsize)) {
						iVar7 = 0;
						JUtility::JUTWarningConsole_f(":::addr %08x: bad block size (%08x)\n", pCVar6);
					}
				}
			}
			iVar4 = mSize;
			if (iVar8 != iVar4) {
				iVar7 = 0;
				JUtility::JUTWarningConsole_f(":::bad total memory block size (%08X, %08X)\n", iVar4, iVar8);
			}
			if (iVar7 == 0) {
				JUtility::JUTWarningConsole(":::there is some error in this heap!\n");
			}
			os::OSUnlockMutex(&mMutex);
			return iVar7;
		}
		uVar3 = pCVar6->id;
		if (uVar3 != 0x484d) {
			iVar7 = 0;
			JUtility::JUTWarningConsole_f(":::addr %08x: bad heap signature. (%c%c)\n", pCVar6, uVar3 >> 8, uVar3 & 0xff);
		}
		pCVar5 = pCVar6->next;
		if (pCVar5 == (CMemBlock *)0x0) {
			if (this->tail != pCVar6) {
				iVar7 = 0;
				JUtility::JUTWarningConsole_f(":::addr %08x: bad used list(REV) (%08x)\n", pCVar6);
			}
		} else {
			if (pCVar5->id != 0x484d) {
				iVar7 = 0;
				JUtility::JUTWarningConsole_f(":::addr %08x: bad next pointer (%08x)\nabort\n", pCVar6);
				goto LAB_802b2a30;
			}
			if (pCVar5->prev != pCVar6) {
				iVar7 = 0;
				JUtility::JUTWarningConsole_f(":::addr %08x: bad previous pointer (%08x)\n", pCVar5, pCVar5->prev);
			}
		}
		puVar1 = &pCVar6->addrsize;
		puVar2 = &pCVar6->fill2;
		pCVar6 = pCVar6->next;
		iVar8 = *puVar1 + ((byte)*puVar2 & 0x7f) + iVar8 + 0x10;
	} while (true);
}
