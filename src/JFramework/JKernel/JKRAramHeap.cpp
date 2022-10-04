#include "JKRAramHeap.h"

JKRAramBlock::JKRAramBlock(uint rupaddr, uint param_2, uint param_3, byte filltype, bool mode) : blocklink(this) {
	this->roundedupaddr = rupaddr;
	this->used = param_2;
	this->remainingsize = param_3;
	this->filltype = filltype;
	this->mode = mode;
}

JKRAramBlock::~JKRAramBlock() {
	JSUPtrList *this_00;
	JSUPtrLink *pJVar1;

	this_00 = (this->blocklink).mpList;
	pJVar1 = (this->blocklink).mpPrev;
	if (!pJVar1) {
		this->remainingsize = this->remainingsize + this->used;
		this->used = 0;
	} else {
		JKRAramBlock *puVar2 = (JKRAramBlock *)pJVar1->mpData;
		puVar2->remainingsize += this->used + this->remainingsize;
		this_00->remove(&this->blocklink);
	}
}

JKRAramBlock *JKRAramBlock::allocHead(uint param_1, byte param_2, JKRAramHeap *param_3) {
	ulong used;
	ulong remaining;
	ulong addr;
	JKRAramBlock *newBlock;

	addr = this->roundedupaddr;
	used = this->used;
	remaining = this->remainingsize;
	newBlock = new (param_3->heapptr, 0) JKRAramBlock(addr + used, param_1, remaining - param_1, param_2, false);
	this->remainingsize = 0;
	(this->blocklink).mpList->insert((this->blocklink).mpNext, &newBlock->blocklink);
	return newBlock;
}

JKRAramBlock *JKRAramBlock::allocTail(ulong size, byte align, JKRAramHeap *heap) {
	ulong uVar1;
	ulong uVar2;
	JKRAramBlock *this_00;
	ulong uVar3;

	uVar3 = this->remainingsize;
	uVar2 = this->roundedupaddr;
	uVar1 = this->used;
	this_00 = new (heap->heapptr, 0) JKRAramBlock((uVar2 + uVar1 + uVar3) - size, size, 0, align, true);

	this->remainingsize = this->remainingsize - size;
	(this->blocklink).mpList->insert((this->blocklink).mpNext, &this_00->blocklink);
	return this_00;
}

JSUPtrList JKRAramHeap::sAramList;

JKRAramHeap::JKRAramHeap(ulong baseaddr, ulong size) : JKRDisposer() {
	JKRHeap *pJVar1;
	JKRAramBlock *this_00;

	os::OSInitMutex(&this->mutex);
	pJVar1 = JKRHeap::findFromRoot(this);
	this->heapptr = pJVar1;
	this->sizedown = size & 0xffffffe0;
	this->roundedupaddr = baseaddr + 0x1f & 0xffffffe0;
	this->endofblock = this->roundedupaddr + this->sizedown;
	this->status = 0xff;
	this_00 = new (this->heapptr, 0) JKRAramBlock(this->roundedupaddr, 0, this->sizedown, 0xff, false);
	sAramList.append(&this_00->blocklink);
}

JKRAramBlock *JKRAramHeap::allocFromHead(uint size) {
	uint uVar1;
	uint uVar2;
	JKRAramBlock *pJVar3;
	JKRAramBlock *uVar4;
	JKRAramBlock *this_00;
	JSUPtrLink *pJVar5;
	uint uVar6;

	uVar1 = size + 0x1f & 0xffffffe0;
	uVar6 = 0xffffffff;
	pJVar3 = (JKRAramBlock *)0x0;
	for (pJVar5 = sAramList.mpHead; this_00 = pJVar3, pJVar5 != (JSUPtrLink *)0x0;
		 pJVar5 = pJVar5->mpNext) {
		this_00 = (JKRAramBlock *)pJVar5->mpData;
		uVar2 = this_00->remainingsize;
		if (((uVar1 <= uVar2) && (uVar2 < uVar6)) && (pJVar3 = this_00, uVar6 = uVar2, uVar2 == uVar1))
			break;
	}
	if (!this_00) {
		uVar4 = 0;
	} else {
		uVar4 = this_00->allocHead(uVar1, this->status, this);
	}
	return uVar4;
}

JKRAramBlock *JKRAramHeap::allocFromTail(uint param_1) {
	uint size;
	JKRAramBlock *uVar1;
	JKRAramBlock *this_00;
	JSUPtrLink *pJVar2;

	size = param_1 + 0x1f & 0xffffffe0;
	pJVar2 = sAramList.mpTail;
	while ((this_00 = (JKRAramBlock *)0x0, pJVar2 != (JSUPtrLink *)0x0 &&
											   (this_00 = (JKRAramBlock *)pJVar2->mpData, this_00->remainingsize < size))) {
		pJVar2 = pJVar2->mpPrev;
	}
	if (this_00 == (JKRAramBlock *)0x0) {
		uVar1 = 0;
	} else {
		uVar1 = this_00->allocTail(size, this->status, this);
	}
	return uVar1;
}

JKRAramBlock *JKRAramHeap::alloc(uint size, EAllocMode mode) {
	JKRAramBlock *uVar1;

	os::OSLockMutex(&this->mutex);
	if (mode == 0) {
		uVar1 = allocFromHead(size);
	} else {
		uVar1 = allocFromTail(size);
	}
	os::OSUnlockMutex(&this->mutex);
	return uVar1;
}

uint JKRAramHeap::getFreeSize() {
	JSUPtrLink *pJVar1;
	uint uVar2;

	uVar2 = 0;
	os::OSLockMutex(&this->mutex);
	for (pJVar1 = sAramList.mpHead; pJVar1 != (JSUPtrLink *)0x0; pJVar1 = pJVar1->mpNext) {
		if (uVar2 < *(uint *)(pJVar1->mpData + 0x1c)) {
			uVar2 = *(uint *)(pJVar1->mpData + 0x1c);
		}
	}
	os::OSUnlockMutex(&this->mutex);
	return uVar2;
}

uint JKRAramHeap::getTotalFreeSize() {
	JSUPtrLink *pJVar1;
	int iVar2;

	iVar2 = 0;
	os::OSLockMutex(&this->mutex);
	for (pJVar1 = JKRAramHeap::sAramList.mpHead; pJVar1 != (JSUPtrLink *)0x0; pJVar1 = pJVar1->mpNext) {
		iVar2 = iVar2 + *(int *)(pJVar1->mpData + 0x1c);
	}
	os::OSUnlockMutex(&this->mutex);
	return iVar2;
}

void JKRAramHeap::dump() {
	char *pcVar1;
	undefined *puVar2;
	JSUPtrLink *pJVar3;
	int iVar4;

	os::OSLockMutex(&this->mutex);
	m_Do_printf::OSReport("\nJKRAramHeap dump\n");
	m_Do_printf::OSReport(" attr  address:   size    gid\n");
	iVar4 = 0;
	for (pJVar3 = JKRAramHeap::sAramList.mpHead; pJVar3 != (JSUPtrLink *)0x0; pJVar3 = pJVar3->mpNext) {
		puVar2 = (undefined *)pJVar3->mpData;
		if (*(int *)(puVar2 + 0x18) != 0) {
			pcVar1 = "alloc";
			if (puVar2[0x21] != '\0') {
				pcVar1 = " temp";
			}
			m_Do_printf::OSReport("%s %08x: %08x  %3d\n", pcVar1, *(undefined4 *)(puVar2 + 0x14),
								  *(undefined4 *)(puVar2 + 0x18), (uint)(byte)puVar2[0x20]);
		}
		puVar2 = (undefined *)pJVar3->mpData;
		if (*(int *)(puVar2 + 0x1c) != 0) {
			m_Do_printf::OSReport(" free %08x: %08x    0\n", *(int *)(puVar2 + 0x14) + *(int *)(puVar2 + 0x18));
		}
		iVar4 = iVar4 + *(int *)(pJVar3->mpData + 0x18);
	}
	m_Do_printf::OSReport("%d / %d bytes (%6.2f%%) used\n",
						  iVar4, this->sizedown,
						  (double)iVar4 / this->sizedown * 100.0);
	os::OSUnlockMutex(&this->mutex);
	return;
}

JKRAramHeap::~JKRAramHeap() {}
