#pragma once

#include <dolphin/os.h>
#include <machine/dolphin/printf.h>

#include "JKRDisposer.h"
#include "JKRHeap.h"
#include "JKernel.h"
#include "../JSupport/JSUPtrLink.h"


struct JKRAramHeap;
struct JKRAramBlock {
	JSUPtrLink blocklink;
	uint roundedupaddr;
	uint used;
	uint remainingsize;
	uint filltype;
	uint mode;

	JKRAramBlock(uint rupaddr, uint param_2, uint param_3, byte filltype, bool mode);

	virtual ~JKRAramBlock();

	JKRAramBlock *allocHead(uint param_1, byte param_2, JKRAramHeap *param_3);
	JKRAramBlock *allocTail(ulong size, byte align, JKRAramHeap *heap);
};

using EAllocMode = uint;

// the inner layout is close to JKRHeap, yet its constructor isn't called?
struct JKRAramHeap : public JKRDisposer {
	static JSUPtrList sAramList;

	os::OSMutex mutex;
	JKRHeap *heapptr;
	uint roundedupaddr;
	int endofblock;
	uint sizedown;
	byte status;

	JKRAramHeap(ulong baseaddr, ulong size);

	JKRAramBlock *allocFromHead(uint size);
	JKRAramBlock *allocFromTail(uint param_1);
	JKRAramBlock *alloc(uint size, EAllocMode mode);
	uint getFreeSize();
	uint getTotalFreeSize();
	void dump();
	virtual ~JKRAramHeap();
};