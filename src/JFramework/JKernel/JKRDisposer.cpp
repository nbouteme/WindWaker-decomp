#include "JKRDisposer.h"

#include "JKRHeap.h"

JKRDisposer::JKRDisposer() : mHeapLink(this) {
	mpHeap = JKRHeap::findFromRoot(this);
	if (mpHeap) {
		mpHeap->mList.append(&this->mHeapLink);
	}
}

JKRDisposer::~JKRDisposer() {
	if (this->mpHeap) {
		this->mpHeap->mList.remove(&this->mHeapLink);
	}
}
