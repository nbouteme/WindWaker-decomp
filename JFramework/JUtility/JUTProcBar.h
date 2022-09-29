#pragma once

#include "../J2DGraph/J2DGraph.h"

struct JUTProcBar {
	static JUTProcBar *sManager;

	struct CTime {
		int maxcount,
			remcount,
			count;

		CTime() {
			this->maxcount = 0;
			this->remcount = 0;
			this->count = 0;
		}
	};

	void draw() {
		//drawProcessBar();
		drawHeapBar();
	}

	static JUTProcBar *create() {
		JUTProcBar *this_00;

		this_00 = JUTProcBar::sManager;
		if (!JUTProcBar::sManager) {
			sManager = new JUTProcBar();
		}
		JUTProcBar::sManager = this_00;
		return sManager;
	}

	static void destroy() {
		if (sManager)
			sManager->~JUTProcBar();
		sManager = nullptr;
	}

	CTime mpTimeHistory[8];

	int drawcount;

	int field1_0x4,
		field2_0x8,
		field7_0x18,
		field8_0x1c,
		field9_0x20,
		field13_0x2c,
		field14_0x30,
		field15_0x34,
		field19_0x40,
		field20_0x44,
		field21_0x48,
		field27_0x54,
		field28_0x58,
		field29_0x5c,
		field34_0x108;

	JUTProcBar() {
		ushort xfbHeight;
		uint xfbHeight2;

		this->field1_0x4 = 0;
		this->field2_0x8 = 0;
		this->drawcount = 0;
		this->field7_0x18 = 0;
		this->field8_0x1c = 0;
		this->field9_0x20 = 0;
		this->field13_0x2c = 0;
		this->field14_0x30 = 0;
		this->field15_0x34 = 0;
		this->field19_0x40 = 0;
		this->field20_0x44 = 0;
		this->field21_0x48 = 0;
		this->field27_0x54 = 0;
		this->field28_0x58 = 0;
		this->field29_0x5c = 0;
		this->mbDrawProcessBar = 1;
		this->mbDrawHeapBar = 1;
		this->field34_0x108 = 0;
		xfbHeight = JUTVideo::sManager->mpRenderMode->xfbHeight;
		xfbHeight2 = (uint)xfbHeight;
		if (xfbHeight < 0x191) {
			screensize = 1;
			startofscan = 0x27;
			height = xfbHeight2 - 0x14;
			width = 0x232;
			this->safeheight = xfbHeight2 - 0x23;
		} else {
			screensize = 2;
			startofscan = 0x27;
			height = xfbHeight2 - 0x28;
			width = 0x232;
			this->safeheight = xfbHeight2 - 0x46;
		}
		this->unk = 1;
		this->skipheap = 0;
		overrideheap = 0;
	}
	int unk;

	void adjustMeterLength(ulong param_1, float *param_2, float param_3, float param_4, int *param_5) {
		float fVar1;
		bool bVar2;

		bVar2 = false;
		for (fVar1 = *param_2; param_3 < fVar1; fVar1 = fVar1 - 0.1) {
			if (((float)param_1 * fVar1 * 20.0) / 16666.0 <= (float)(width)-30.0)
				break;
			bVar2 = true;
		}
		if (param_4 <= fVar1) {
			*param_5 = 0;
		}
		if (param_4 - 0.2 < fVar1) {
			fVar1 = param_4;
		}
		if (((!bVar2) && (fVar1 < param_4)) && (*param_5 = *param_5 + 1, 0x1d < *param_5)) {
			if (((float)param_1 * fVar1 * 20.0) / 16666.0 < (float)width - 60.0) {
				fVar1 = fVar1 + 0.2;
			}
		}
		*param_2 = fVar1;
		return;
	}

	os::OSTick clearticks, ticks, ticks3, ticks4;
	int field33_0x104;
	static void clear() {
		JUTProcBar *pJVar2;
		int ticks;
		uint uVar3;
		undefined4 uVar4;
		JUTProcBar *pJVar1;

		pJVar2 = JUTProcBar::sManager;
		pJVar2->colora[0] = 0xff;
		pJVar2->colora[1] = 0x81;
		pJVar2->colora[2] = 0x1e;
		ticks = os::OSGetTick();
		pJVar2->clearticks = ticks;
		pJVar2 = JUTProcBar::sManager;
		pJVar2->colorb[0] = 0xff;
		pJVar2->colorb[1] = 0x81;
		pJVar2->colorb[2] = 0x1e;
		uVar3 = os::OSGetTick();
		pJVar2->ticks = uVar3;
		pJVar1 = JUTProcBar::sManager;
		pJVar2->colorc[0] = 0xff;
		pJVar1->colorc[1] = 0x81;
		pJVar1->colorc[2] = 0x1e;
		uVar4 = os::OSGetTick();
		pJVar1->ticks3 = uVar4;
		pJVar2 = JUTProcBar::sManager;
		pJVar2->colord[0] = 0xff;
		pJVar2->colord[1] = 0x81;
		pJVar2->colord[2] = 0x1e;
		ticks = os::OSGetTick();
		pJVar2->ticks4 = ticks;
		pJVar2->field33_0x104 = 0;

		JUtility::oneFrameRate = 8.0;
		JUtility::oneFrameRateUser = 10.0;
	}

	void bar_subroutine(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6,
						int param_7, TColor param_8, TColor param_9) {
		uint uVar1;

		uVar1 = (param_7 * param_4) / param_5;
		J2DGraph::J2DFillBox(param_1, param_2, (param_6 * param_4) / param_5, param_3, param_8);
		if (-1 < (int)uVar1) {
			if ((int)uVar1 < 6) {
				J2DGraph::J2DFillBox(param_1, param_2, uVar1, param_3, param_9);
			} else {
				J2DGraph::J2DFillBox((param_1 + (uVar1 - 6)), param_2, 6.0, param_3, param_9);
			}
		}
	}

	byte colora[3], colorb[3], colorc[3], colord[3];

	int screensize, safeheight;
	byte mbDrawHeapBar, mbDrawProcessBar;
	int startofscan, width, height, skipheap;
	JKRHeap *overrideheap;

	void drawHeapBar() {
		uint uVar1;
		int iVar2;
		int iVar3;
		JKRHeap *heap;

		if (!this->mbDrawHeapBar)
			return;

		uVar1 = screensize << 1;

		u32 local_c4 = 0x640032c8;
		J2DGraph::J2DFillBox((float)startofscan, (float)height + screensize * -4, (float)width, (float)uVar1, (TColor)&local_c4);

		u32 local_cc = 0x643296ff;
		J2DGraph::J2DDrawFrame((float)startofscan, (float)height + screensize * -4, (float)width, (float)uVar1, (TColor)&local_cc, 6);

		iVar2 = JUtility::addrToXPos(JKRHeap::mCodeStart, width);
		iVar3 = JUtility::addrToXPos(JKRHeap::mCodeEnd, width);

		u32 local_d4 = 0xff3296ff;
		J2DGraph::J2DFillBox((float)startofscan + iVar2, (float)height + screensize * -4,
							 (float)(startofscan + iVar3) - (startofscan + iVar2), (float)uVar1, (TColor)&local_d4);

		iVar2 = JUtility::addrToXPos(JKRHeap::mUserRamStart, width);
		iVar2 = JUtility::addrToXPos(JKRHeap::mUserRamEnd, width);	// probably a typo in the original code, they meant iVar3 and the compiler.

		u32 local_dc = 0x003296ff;
		J2DGraph::J2DFillBox((float)startofscan + iVar2, (float)height + screensize * -4, (float)(startofscan + iVar2) - (startofscan + iVar2) /* "y-you sure you want no optimizations?" */, (float)uVar1, (TColor)&local_dc);

		u32 local_e4 = 0xfafaff;
		J2DGraph::J2DFillBox((float)startofscan + iVar2, (float)height + screensize * -4, (float)JUtility::byteToXLen(JKRHeap::sRootHeap->getTotalFreeSize(), width), (float)((int)(uVar1 | screensize >> 0x1f) >> 1), (TColor)&local_e4);
		if (skipheap == 0) {
			heap = JKRHeap::sCurrentHeap;
			if (overrideheap) {
				heap = overrideheap;
			}
			if (heap != JKRHeap::sSystemHeap) {
				JUtility::heapBar(heap, startofscan, height, uVar1, width, uVar1);
			}
		}
	}
};