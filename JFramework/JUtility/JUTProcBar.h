#pragma once

#include "../J2DGraph/J2DGraph.h"

struct JUTProcBar {
	static JUTProcBar *sManager;

	struct CTime {
		int maxcount,
			remcount,
			count;

		CTime();
	};

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

	int unk;

	os::OSTick clearticks, ticks, ticks3, ticks4;
	int field33_0x104;

	byte colora[3], colorb[3], colorc[3], colord[3];

	int screensize, safeheight;
	byte mbDrawHeapBar, mbDrawProcessBar;
	int startofscan, width, height, skipheap;
	JKRHeap *overrideheap;

	static JUTProcBar *create();
	static void clear();
	static void destroy();

	JUTProcBar();

	void draw();
	void adjustMeterLength(ulong param_1, float *param_2, float param_3, float param_4, int *param_5);
	void bar_subroutine(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6,
						int param_7, TColor param_8, TColor param_9);
	void drawHeapBar();
};