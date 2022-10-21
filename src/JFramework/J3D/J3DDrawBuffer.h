#pragma once

#include <dolphin/mtx.h>

#include "J3DPacket.h"

struct J3DMatPacket;

struct J3DDrawBuffer {
	J3DPacket** mpPacketBuf;
	ulong mPacketBufSize;
	int mDrawType;
	int mSortType;
	float end;
	float max;
	float bufferfillrate;
	mtx::Mtx* mpNodeMtx;
	J3DCallBackPacket* mpFirstPacket;

	int allocBuffer(unsigned long);
	void draw();
	void drawHead();
	void drawTail();
	int entryImm(J3DPacket*, unsigned short);

    bool entryInvalidSort(J3DMatPacket *);
    bool entryMatSort(J3DMatPacket *);
    bool entryMatAnmSort(J3DMatPacket *);
    bool entryModelSort(J3DMatPacket *);
    bool entryNonSort(J3DMatPacket *);
    bool entryZSort(J3DMatPacket *);
    
    void frameInit();
    void initialize();
    void setCallBackPacket(J3DCallBackPacket *);
};