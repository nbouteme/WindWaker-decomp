#pragma once

#include "../J2DGraph/J2DGraph.h"
#include "JUTConsole.h"

struct JUtility {
	using usercallback = void(void);

	static struct {
		usercallback *callback;
		u32 lowerpage, ctx, interrupt, arg;
	} exCallbackObject;

	static void JUTReportConsole(const char *, ...);
	static void JUTSetReportConsole(JUTConsole *);
	static void JUTSetWarningConsole(JUTConsole *);
	static void JUTWarningConsole(const char *f, ...);
	static void JUTWarningConsole_f(const char *f, ...);

	static void JUTReport(int x, int y, const char *, ...);
	static void JUTReport(int x, int y, int l, const char *, ...);
	static int sDrawWaiting;
	static int init$2183;
	static void *frameBuffer$2182;
	static int channel_mask[4];

	static float oneFrameRate;
	static float oneFrameRateUser;
	static JUTConsole *sReportConsole, *sWarningConsole;

	static void JUTConsole_print_f_va_(JUTConsole *param_1, char *param_2, va_list param_3);
	static int addrToXPos(void *param_1, uint param_2);
	static int byteToXLen(uint param_1, uint param_2);
	static JUTConsole *JUTGetWarningConsole();
	static JUTConsole *JUTGetReportConsole();
	static void heapBar(JKRHeap *param_1, int param_2, int param_3, undefined4 param_4, undefined4 param_5, uint param_6);
};