#pragma once

#include <doltypes.h>

struct JUTFont;
struct JKRHeap;

struct JUTDbPrint {
	static JUTDbPrint *sDebugPrint;

	void *z;
	JUTFont *font;
	byte r, g, b, a;
	byte uk;  // padding
	JKRHeap *heap;

	JUTDbPrint(JUTFont *param_1, JKRHeap *param_2);

	static JUTDbPrint *start(JUTFont *param_1, JKRHeap *param_2);

	JUTFont *changeFont(JUTFont *param_1);

	void enter(int param_1, int param_2, int param_3, char *strbuf, int len);
	void drawString(int param_1, int param_2, int param_3, char *param_4);
	void flush();
};