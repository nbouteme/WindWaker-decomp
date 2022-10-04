#pragma once

#include "../JSupport/JSUPtrLink.h"
struct JKRHeap;

struct JKRDisposer {
	JSUPtrLink mHeapLink;
	JKRHeap *mpHeap;

	JKRDisposer();

	virtual ~JKRDisposer();
};