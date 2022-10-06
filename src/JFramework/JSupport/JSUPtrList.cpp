#include "../JSupport/JSUPtrList.h"

void JSUPtrList::initiate() {
	this->mpHead = nullptr;
	this->mpTail = nullptr;
	this->mCount = 0;
}

void JSUPtrList::setFirst(JSUPtrLink *param_1) {
	param_1->mpList = this;
	param_1->mpPrev = nullptr;
	param_1->mpNext = nullptr;
	this->mpTail = param_1;
	this->mpHead = param_1;
	this->mCount = 1;
}

unsigned int JSUPtrList::append(JSUPtrLink *pLink) {
	unsigned int numberofleading0;
	unsigned int uVar2;

	if (pLink->mpList) {
		uVar2 = pLink->mpList->remove(pLink);
	}
	if (!pLink->mpList) {
		if (this->mCount == 0) {
			setFirst(pLink);
		} else {
			pLink->mpList = this;
			pLink->mpPrev = this->mpTail;
			pLink->mpNext = nullptr;
			this->mpTail->mpNext = pLink;
			this->mpTail = pLink;
			this->mCount = this->mCount + 1;
		}
	}
	return uVar2;
}

uint JSUPtrList::prepend(JSUPtrLink *param_1) {
	uint uVar2;

	auto uVar1 = param_1->mpList;
	if (uVar1) {
		uVar2 = param_1->mpList->remove(param_1);
	}
	if (!uVar1) {
		if (this->mCount == 0) {
			setFirst(param_1);
		} else {
			param_1->mpList = this;
			param_1->mpPrev = nullptr;
			param_1->mpNext = this->mpHead;
			this->mpHead->mpPrev = param_1;
			this->mpHead = param_1;
			this->mCount = this->mCount + 1;
		}
	}
	return uVar2;
}

uint JSUPtrList::insert(JSUPtrLink *param_1, JSUPtrLink *param_2) {
	uint uVar1;
	uint uVar2;
	JSUPtrLink *pJVar3;

	if (param_1 == this->mpHead) {
		uVar2 = prepend(param_2);
	} else if (param_1 == nullptr) {
		uVar2 = append(param_2);
	} else if (param_1->mpList == this) {
		auto uVar1 = (param_2->mpList);
		if (!uVar1) {
			uVar2 = param_2->mpList->remove(param_2);
		}
		if (uVar1) {
			pJVar3 = param_1->mpPrev;
			param_2->mpList = this;
			param_2->mpPrev = pJVar3;
			param_2->mpNext = param_1;
			pJVar3->mpNext = param_2;
			param_1->mpPrev = param_2;
			this->mCount = this->mCount + 1;
		}
	} else {
		uVar2 = 0;
	}
	return uVar2;
}

uint JSUPtrList::remove(JSUPtrLink *param_1) {
	uint uVar1;

	uVar1 = this - param_1->mpList;
	if (uVar1) {
		if (this->mCount == 1) {
			this->mpHead = nullptr;
			this->mpTail = nullptr;
		} else if (param_1 == this->mpHead) {
			param_1->mpNext->mpPrev = nullptr;
			this->mpHead = param_1->mpNext;
		} else if (param_1 == this->mpTail) {
			param_1->mpPrev->mpNext = nullptr;
			this->mpTail = param_1->mpPrev;
		} else {
			param_1->mpPrev->mpNext = param_1->mpNext;
			param_1->mpNext->mpPrev = param_1->mpPrev;
		}
		param_1->mpList = nullptr;
		this->mCount--;
	}
	return uVar1 != 0;
}