#include "J3DDisplayListObj.h"

#include <dolphin/gd.h>
#include <dolphin/gx.h>
#include <dolphin/os.h>
#include <dolphin/types.h>

#include "../JKernel/JKernel.h"

int J3DDisplayListObj::sInterruptFlag;

gd::GDLObj J3DDisplayListObj::sGDLObj;

void J3DDisplayListObj::swapBuffer() {
	void *pvVar1;

	pvVar1 = this->mpData[0];
	this->mpData[0] = this->mpData[1];
	this->mpData[1] = pvVar1;
}

void J3DDisplayListObj::beginDL() {
	swapBuffer();
	sInterruptFlag = os::OSDisableInterrupts();
	gd::GDInitGDLObj(&sGDLObj, this->mpData[0], this->mCapacity);
	gd::__GDCurrentDL = &J3DDisplayListObj::sGDLObj;
}

void J3DDisplayListObj::beginPatch() {
	beginDL();
}

void J3DDisplayListObj::callDL() {
	gx::GXCallDisplayList(this->mpData[0], this->mSize);
}

int J3DDisplayListObj::endDL() {
	gd::GDPadCurr32();
	os::OSRestoreInterrupts(sInterruptFlag);
	this->mSize = sGDLObj.ptr - sGDLObj.start;
	gd::GDFlushCurrToMem();
	gd::__GDCurrentDL = 0;
	return this->mSize;
}

int J3DDisplayListObj::endPatch() {
	os::OSRestoreInterrupts(sInterruptFlag);
	gd::__GDCurrentDL = 0;
	return this->mSize;
}

int J3DDisplayListObj::newDisplayList(unsigned param_1) {
	void *pvVar1;

	this->mCapacity = param_1 + 0x1f & 0xffffffe0;
	pvVar1 = new (0x20) unsigned char[this->mCapacity];
	this->mpData[0] = pvVar1;
	pvVar1 = new (0x20) unsigned char[this->mCapacity];
	this->mpData[1] = pvVar1;
	this->mSize = 0;
	if (!this->mpData[0] || !this->mpData[1])
		return 4;
	return 0;
}

int J3DDisplayListObj::newSingleDisplayList(unsigned param_1) {
	void *pvVar1;

	this->mCapacity = param_1 + 0x1f & 0xffffffe0;
	pvVar1 = new (0x20) unsigned char[this->mCapacity];
	this->mpData[0] = pvVar1;
	this->mpData[1] = this->mpData[0];
	this->mSize = 0;
	if (!this->mpData[0]) {
		return 4;
	}
	return 0;
}

void J3DDisplayListObj::setSingleDisplayList(void *pData, unsigned size) {
	this->mCapacity = size + 0x1f & 0xffffffe0;
	this->mpData[0] = pData;
	this->mpData[1] = this->mpData[0];
	this->mSize = size;
}

using byte = unsigned char;
using uint = unsigned;
extern "C" void copy_bytes(byte *d, byte *s, uint n);

int J3DDisplayListObj::single_To_Double() {
	void *pvVar1;

	if (this->mpData[0] != this->mpData[1])
		return 0;
	pvVar1 = new (0x20) unsigned char[this->mCapacity];
	this->mpData[1] = pvVar1;
	if (!this->mpData[1]) {
		return 4;
	}
	copy_bytes((byte *)this->mpData[1], (byte *)this->mpData[0], this->mCapacity);
	os::DCStoreRange(this->mpData[1], this->mCapacity);
	return 0;
}
