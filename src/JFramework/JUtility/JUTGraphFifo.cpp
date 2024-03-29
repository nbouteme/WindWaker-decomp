#include "JUTGraphFifo.h"

#include "../JKernel/JKRExpHeap.h"
#include "../JKernel/JKernel.h"
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <fenv.h>

#include <cstdio>

char JUTGraphFifo::sInitiated;
JUTGraphFifo *JUTGraphFifo::sCurrentFifo;

JUTGraphFifo::JUTGraphFifo(ulong param_1) {
	void *pvVar1;

	this->fifosize = param_1 + 0x1f & 0xffffffe0;  // round to 0x20
	if (!JUTGraphFifo::sInitiated) {
		pvVar1 = JKRHeap::sSystemHeap->alloc(this->fifosize + 0xa0, 0x20);
		this->fifobuffer = pvVar1;
		this->fifobuffer = (void *)((intptr_t)this->fifobuffer + 0x1fU & 0xffffffe0);
		this->gxFifoObj = gx::GXInit(this->fifobuffer, this->fifosize);
		JUTGraphFifo::sInitiated = 1;
		sCurrentFifo = this;
	} else {
		pvVar1 = JKRHeap::sSystemHeap->alloc(this->fifosize + 0x80, 0x20);
		this->gxFifoObj = (gx::GXFifoObj *)pvVar1;
		this->fifobuffer = (void *)((intptr_t)this->gxFifoObj + 0x80);
		gx::GXInitFifoBase(this->gxFifoObj, this->fifobuffer, this->fifosize);
		gx::GXInitFifoPtrs(this->gxFifoObj, this->fifobuffer, this->fifobuffer);
	}
}

JUTGraphFifo::~JUTGraphFifo() {
#ifdef DOLPHIN
	gx::GXSaveCPUFifo(sCurrentFifo->gxFifoObj);
	do {
		gx::GXGetGPStatus(&mGpStatus.overhi,
						  &mGpStatus.underlow,
						  &mGpStatus.readIdle,
						  &mGpStatus.cmdIdle,
						  &mGpStatus.brkpt);
	} while (mGpStatus.readIdle == 0);
#else
// i think there's no equivalent here
#endif
	if (sCurrentFifo == this) {
		sCurrentFifo = nullptr;
	}
	JKRHeap::sSystemHeap->free(this->fifobuffer);
}
