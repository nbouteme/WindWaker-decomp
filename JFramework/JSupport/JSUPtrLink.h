#pragma once
#include "../JSupport/JSUPtrList.h"

struct JSUPtrLink {
	void* mpData;
	JSUPtrList* mpList;
	JSUPtrLink* mpPrev;
	JSUPtrLink* mpNext;

	JSUPtrLink(void* any);
};