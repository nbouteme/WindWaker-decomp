#pragma once
#include <doltypes.h>

#include <cstdarg>
#include <cstdio>

#include <dolphin/os.h>

struct JUTDirectPrint {
	static JUTDirectPrint *sDirectPrint;
	static byte sAsciiTable[];
	static byte sFontData[];
	static byte sFontData2[];

	void *framebuffer;
	ushort width, height, scanwidth;
	uint totalsize;
	uint __unused;
	void *oldframebuffer;

	static JUTDirectPrint *start(void);

	JUTDirectPrint();

	void changeFrameBuffer(void *param_1, ushort param_2, ushort param_3);
	void erase(int param_1, int param_2, int param_3, int param_4);
	void drawChar(int param_1, int param_2, int param_3);
	void printSub(ushort param_1, ushort param_2, char *param_3, va_list param_4, bool param_5);
	void drawString(ushort param_1, ushort param_2, char *param_3);
	void drawString_f(ushort param_1, ushort param_2, char *param_3, ...);
};
