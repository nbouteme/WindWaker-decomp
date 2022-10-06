#include "../JSupport/JSUPtrLink.h"

JSUPtrLink::JSUPtrLink(void *any) {
	mpList = (JSUPtrList*)0;
	mpData = any;
	mpPrev = (JSUPtrLink*)0;
	mpNext = (JSUPtrLink*)0;
}