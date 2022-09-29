#pragma once

#include "../JSupport/JSUPtrLink.h"

struct JKRDisposer {
    JSUPtrLink mHeapLink;
    JKRHeap *mpHeap;

	JKRDisposer() : mHeapLink(this) {
        mpHeap = JKRHeap::findFromRoot(this);
        if (mpHeap) {
            mpHeap->mList.append(&this->mHeapLink);
        }
	}

    virtual ~JKRDisposer() {}
};