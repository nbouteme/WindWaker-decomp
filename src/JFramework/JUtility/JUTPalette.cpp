#include "JUTPalette.h"

bool JUTPalette::load() {
	bool bVar1;

	bVar1 = this->mSize != 0;
	if (bVar1) {
		gx::GXLoadTlut(this, this->mTlut);
	}
	return bVar1;
}

void JUTPalette::storeTLUT(gx::GXTlut param_1, gx::GXTlutFmt param_2, JUTTransparency param_3, ushort param_4, void *param_5) {
	this->mTlut = param_1;
	this->mTlutFmt = param_2;
	this->mTransparency = param_3;
	this->mSize = param_4;
	this->mpData = param_5;
	gx::GXInitTlutObj(this, this->mpData, this->mTlutFmt, this->mSize);
}

void JUTPalette::storeTLUT(gx::GXTlut param_1, ResTLUT *param_2) {
	if (!param_2) {
		m_Do_printf::OSPanic("JUTPalette.cpp", 0x23, "JUTTexture: TLUT is NULL\n");
	}
	this->mTlut = param_1;
	this->mTlutFmt = param_2->mTlutFmt;
	this->mTransparency = param_2->mTransparency;
	this->mSize = param_2->mSize;
	this->mpData = param_2 + 1;
	gx::GXInitTlutObj(this, this->mpData, this->mTlutFmt, this->mSize);
	return;
}
