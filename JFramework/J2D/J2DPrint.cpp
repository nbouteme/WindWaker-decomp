#include "J2DPrint.h"

#include "../JKernel/JKRHeap.h"
#include "../../machine/dolphin/printf.h"
#include "../JKernel/JKernel.h"
#include "../JUtility/JUTAssert.h"

char *J2DPrint::mStrBuff;
byte J2DPrint::mHeapFlag;
uint J2DPrint::mStrBuffSize;

char *J2DPrint::setBuffer(uint param_1) {
	char *pcVar1;
	ulong uVar2;

	if (param_1 == 0) {
		JUTAssertion::getSDevice()->showAssert("J2DPrint.cpp", 0x144, "size > 0");
		m_Do_printf::OSPanic("J2DPrint.cpp", 0x144, "Halt");
	}
	pcVar1 = mStrBuff;
	if (mHeapFlag) {
		delete[] mStrBuff;
	}
	mStrBuff = new (JKRHeap::sSystemHeap, 0) char[param_1];
	mHeapFlag = 1;
	mStrBuffSize = param_1;
	return pcVar1;
}
