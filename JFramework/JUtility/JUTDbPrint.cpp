#include "./JUTDbPrint.h"

#include <cstring>

#include "../../dolphin/gx.h"
#include "../J2DGraph/J2DOrthoGraph.h"
#include "../JKernel/JKRHeap.h"
#include "JUTFont.h"

struct JUTFont;

JUTDbPrint *JUTDbPrint::sDebugPrint;

JUTDbPrint::JUTDbPrint(JUTFont *param_1, JKRHeap *param_2) {
	JKRHeap *pJVar1;

	this->font = param_1;
	this->z = nullptr;
	pJVar1 = JKRHeap::sCurrentHeap;
	if (param_2) {
		pJVar1 = param_2;
	}
	this->heap = pJVar1;
	this->r = 0xff;
	this->g = 0xff;
	this->b = 0xff;
	this->a = 0xff;
	this->uk = 1;
}

JUTDbPrint *JUTDbPrint::start(JUTFont *param_1, JKRHeap *param_2) {
	JUTDbPrint *ret;

	ret = JUTDbPrint::sDebugPrint;
	if (!ret) {
		if (!param_2) {
			param_2 = JKRHeap::sCurrentHeap;
		}
		ret = new JUTDbPrint(param_1, param_2);
	}
	JUTDbPrint::sDebugPrint = ret;
	return ret;
}

JUTFont *JUTDbPrint::changeFont(JUTFont *param_1) {
	JUTFont *pJVar1;

	pJVar1 = this->font;
	if (param_1) {
		this->font = param_1;
	}
	return pJVar1;
}

void JUTDbPrint::enter(int param_1, int param_2, int param_3, char *strbuf, int len) {
	undefined2 *puVar1;

	if ((0 < len) &&
		(puVar1 = (undefined2 *)JKRHeap::alloc(len + 0x10, -4, this->heap), puVar1)) {
		puVar1[2] = (short)param_1;
		puVar1[3] = (short)param_2;
		puVar1[4] = (short)param_3;
		puVar1[5] = (short)len;
		strcpy((char *)(puVar1 + 6), strbuf);
		*(void **)puVar1 = this->z;
		this->z = puVar1;
	}
}

void JUTDbPrint::drawString(int param_1, int param_2, int param_3, char *param_4) {
	uint uVar1;
	JUTFont *this_00;
	undefined4 uVar2;
	undefined8 in_f31;
	double dVar3;
	undefined auStack8[8];

	uVar2 = 0;
	this_00 = this->font;
	uVar1 = this_00->getHeight();
	dVar3 = uVar1;
	uVar1 = this_00->getWidth();
	this_00->drawString_size_scale(param_1, param_2, uVar1, dVar3, (char *)param_4, param_3, true);
}

void JUTDbPrint::flush() {
	short sVar1;
	JUTDbPrint *pJVar2;
	JUTDbPrint *__ptr;
	JUTDbPrint *pJVar3;
	gx::GXColor local_e8;

	pJVar2 = (JUTDbPrint *)this->z;
	if (!(this->font && pJVar2)) {
		return;
	}

	struct J2DOrthoGraph local_e4(0.0, 0.0, 640.0, 480.0, -1.0, 1.0);
	local_e4.setPort();
	this->font->setGX();
	memcpy(&local_e8, &this->r, sizeof(gx::GXColor));
	this->font->setCharColor(&local_e8);
	pJVar3 = this;
	while ((__ptr = pJVar2)) {
		if (this->uk != '\0') {
			drawString((int)*(short *)&__ptr->font, (int)*(short *)((int)&__ptr->font + 2),
					   (int)*(short *)&__ptr->b, (char *)&__ptr->uk);
		}
		sVar1 = *(short *)&__ptr->r + -1;
		*(short *)&__ptr->r = sVar1;
		if (sVar1 < 1) {
			pJVar2 = (JUTDbPrint *)__ptr->z;
			JKRHeap::free(__ptr, this->heap);
			pJVar3->z = pJVar2;
		} else {
			pJVar2 = (JUTDbPrint *)__ptr->z;
			pJVar3 = __ptr;
		}
	}
}
