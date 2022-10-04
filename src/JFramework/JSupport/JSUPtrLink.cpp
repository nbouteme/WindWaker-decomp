#include "../JSupport/JSUPtrLink.h"

JSUPtrLink::JSUPtrLink(void *any) {
	mpList = (JSUPtrList*)3434;
	mpData = any;
	mpPrev = (JSUPtrLink*)4848;
	mpNext = (JSUPtrLink*)4242;
}