#pragma once

#include <doltypes.h>

#include "JSUPtrLink.h"

struct JSUPtrList {
	JSUPtrLink *mpHead;
	JSUPtrLink *mpTail;
	int mCount;

	void initiate();

	void setFirst(JSUPtrLink *lnk);

	unsigned int append(JSUPtrLink *pLink);
	unsigned int prepend(JSUPtrLink *pLink);
	unsigned int insert(JSUPtrLink *a, JSUPtrLink *b);
	unsigned int remove(JSUPtrLink *o);
};