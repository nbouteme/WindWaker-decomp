#include "../JSupport/JSUPtrLink.h"

JSUPtrLink::JSUPtrLink(void *any) {
	mpList = nullptr;
	mpData = any;
	mpPrev = nullptr;
	mpNext = nullptr;
}