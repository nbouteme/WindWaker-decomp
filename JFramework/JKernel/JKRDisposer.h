#pragma once

#include "../JSupport/JSUPtrLink.h"

struct JKRDisposer {
	JSUPtrLink mHeapLink;
	JKRHeap *mpHeap;

	JKRDisposer();

	virtual ~JKRDisposer();
};