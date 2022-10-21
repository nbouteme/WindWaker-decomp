#include "J3DDrawBuffer.h"

int J3DDrawBuffer::allocBuffer(unsigned long param_1) {
	J3DPacket **ppJVar1;
	undefined4 uVar2;

	ppJVar1 = new J3DPacket *[param_1];
	this->mpPacketBuf = ppJVar1;
	if (this->mpPacketBuf == (J3DPacket **)0x0) {
		uVar2 = 4;
	} else {
		this->mPacketBufSize = param_1;
		frameInit();
		this->bufferfillrate =
			(this->max - this->end) / (float)this->mPacketBufSize;
		uVar2 = 0;
	}
	return uVar2;
}

using DrawFunc = void (J3DDrawBuffer::*)();

DrawFunc drawFuncTable[] = {
    &J3DDrawBuffer::drawHead,
    &J3DDrawBuffer::drawTail
};

void J3DDrawBuffer::draw() {
    (this->*drawFuncTable[mDrawType])();
}

void J3DDrawBuffer::drawHead() {
	J3DPacket *piVar1;
	uint uVar1;
	J3DPacket **ppJVar2;
	uint uVar3;

	uVar3 = this->mPacketBufSize;
	ppJVar2 = this->mpPacketBuf;
	for (uVar1 = 0; uVar1 < uVar3; uVar1 = uVar1 + 1) {
		for (piVar1 = ppJVar2[uVar1]; piVar1; piVar1 = piVar1->mpNextSibling) {
			piVar1->draw();
		}
	}
}

void J3DDrawBuffer::drawTail() {
	J3DPacket *piVar1;
	int iVar1;
	int iVar2;

	iVar1 = this->mPacketBufSize - 1;
	for (; - 1 < iVar1; iVar1 = iVar1 + -1) {
		for (piVar1 = this->mpPacketBuf[iVar1]; piVar1;
			 piVar1 = piVar1->mpNextSibling) {
			piVar1->draw();
		}
	}
}

int J3DDrawBuffer::entryImm(J3DPacket *, unsigned short) {
}

bool J3DDrawBuffer::entryInvalidSort(J3DMatPacket *) {
}

bool J3DDrawBuffer::entryMatSort(J3DMatPacket *) {
}

bool J3DDrawBuffer::entryMatAnmSort(J3DMatPacket *) {
}

bool J3DDrawBuffer::entryModelSort(J3DMatPacket *) {
}

bool J3DDrawBuffer::entryNonSort(J3DMatPacket *) {
}

bool J3DDrawBuffer::entryZSort(J3DMatPacket *) {
}

void J3DDrawBuffer::frameInit() {
	int iVar1;
	uint uVar2;

	iVar1 = 0;
	for (uVar2 = 0; uVar2 < this->mPacketBufSize; uVar2 = uVar2 + 1) {
		this->mpPacketBuf[uVar2] = nullptr;
	}
	this->mpFirstPacket = nullptr;
}

void J3DDrawBuffer::initialize() {
}

void J3DDrawBuffer::setCallBackPacket(J3DCallBackPacket *) {
}
