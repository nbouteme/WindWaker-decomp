#pragma once

struct JSUPtrList;

struct JSUPtrLink {
	void* mpData;
	JSUPtrList* mpList;
	JSUPtrLink* mpPrev;
	JSUPtrLink* mpNext;

	JSUPtrLink(void* any);
};