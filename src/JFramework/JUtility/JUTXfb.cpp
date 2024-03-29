#include "JUTXfb.h"

#include "../JKernel/JKRExpHeap.h"

JUTXfb *JUTXfb::sManager;

void JUTXfb::clearIndex() {
	this->idx0 = -1;
	this->idx1 = -1;
	this->idx2 = -1;
}

void JUTXfb::common_init(int param_1) {
	this->xfbnum = param_1;
	clearIndex();
	this->renderStatus = 99;
}

void JUTXfb::initiate(ushort width, ushort height, JKRHeap *heap, EXfbNumber numexfb) {
	int xfbsize;

	if (!heap) {
		heap = JKRHeap::sSystemHeap;
	}
	xfbsize = (width + 0xf & 0xfff0) * (uint)height * 2;  // 16bpp
	this->xfbs[0] = new (heap, 0x20) byte[xfbsize];
	this->hasxfb[0] = 1;
	if (numexfb < 2) {
		this->xfbs[1] = nullptr;
		this->hasxfb[1] = 0;
	} else {
		this->xfbs[1] = new (heap, 0x20) byte[xfbsize];
		this->hasxfb[1] = 1;
	}
	if (numexfb < 3) {
		this->xfbs[2] = nullptr;
		this->hasxfb[2] = 0;
	} else {
		this->xfbs[2] = new (heap, 0x20) byte[xfbsize];
		this->hasxfb[2] = 1;
	}
}

JUTXfb::JUTXfb(gx::GXRenderModeObj *param_1, JKRHeap *heap, EXfbNumber xfbnum) {
	unsigned short height;
	gx::GXRenderModeObj *pGVar1;
	unsigned short width;

	common_init(xfbnum);
	if (!param_1) {
		pGVar1 = JUTVideo::sManager->mpRenderMode;
		width = pGVar1->fbWidth;
		height = pGVar1->efbHeight;
#ifdef DOLPHIN
		height = gx::GXGetNumXfbLines(height, gx::GXGetYScaleFactor(height, pGVar1->xfbHeight));
#else
// assume no EFB/XFB difference
#endif

		JUTXfb::initiate(width, height, heap, xfbnum);
	} else {
		JUTXfb::initiate(param_1->fbWidth, param_1->xfbHeight, heap, xfbnum);
	}
}

void JUTXfb::delXfb(int param_1) {
	if (this->hasxfb[param_1] && this->xfbs[param_1]) {
		delete[] (byte *)this->xfbs[param_1];
	}
}

JUTXfb::~JUTXfb() {
	int iVar1 = 0;
	do {
		delXfb(iVar1++);
	} while (iVar1 < 3);
	JUTXfb::sManager = nullptr;
}

JUTXfb *JUTXfb::createManager(gx::GXRenderModeObj *param_1, JKRHeap *heap, EXfbNumber param_3) {
	uint uVar1;
	/*
		JUTAssertion *this;
		JUTXfb *this_00;
		char *in_r8;

		this = (JUTAssertion *)JUTAssertion::getSDevice();
		uVar1 = countLeadingZeros(JUTXfb::sManager);
		JUTAssertion::setConfirmMessage(this, (ulong) "JUTXfb.cpp", (char *)0xcb, uVar1 >> 5, true, in_r8);
		*/
	auto self = JUTXfb::sManager;
	if (!self) {
		self = new JUTXfb(param_1, heap, param_3);
	}
	JUTXfb::sManager = self;
	return JUTXfb::sManager;
}

void JUTXfb::destroyManager(void) {
	/*
		JUTAssertion *self;
		char *in_r8;
		this = (JUTAssertion *)JUTAssertion::getSDevice();
		JUTAssertion::setConfirmMessage(self, (ulong) "JUTXfb.cpp", (char *)0x158, (uint)(JUTXfb::sManager != (JUTXfb *)0x0), true,
										in_r8);
										*/
	JUTXfb::sManager->~JUTXfb();
	JUTXfb::sManager = nullptr;
}
