#pragma once

#include <doltypes.h>

#include "../J2DGraph/J2DGraph.h"
#include "../J2DGraph/J2DOrthoGraph.h"
#include "../JGadget.h"
#include "../JKernel/JKRDisposer.h"
#include "./JUTConsoleManager.h"
#include "./JUTFont.h"

struct JUTConsole : public JKRDisposer {
	JGadget::TLinkListNode linknode;
	uint beginning_of_line_x, lines;
	undefined *consolefreebuffer;
	bool ownmem;
	int caretheight, totalused, totalavailabl, caret_x, console_position_x, console_position_y, maxlines;
	JUTFont *font;
	float charspacing, linespacing;
	int outputwhere;  // 1 is regular, 2 is osreport, 3 is both
	gx::GXColor color, color2;
	byte candisplay, osreportdebug, shouldwrap;

	static uint getObjectSizeFromBufferSize(uint param_1, uint param_2);
	static uint getLineFromObjectSize(ulong param_1, uint param_2);
	static JUTConsole *create(uint param_1, uint param_2, JKRHeap *param_3);
	static JUTConsole *create(uint rsize, void *buffer, ulong param_3);

	JUTConsole(uint param_1, uint param_2, bool own);

	~JUTConsole();

	using EConsoleType = int;
	void doDraw(EConsoleType param_1);
	void clear();
	void print_f(char *param_1, ...);
	void print(char *param_1);
	void dumpToTerminal(uint param_1);
	void scroll(int param_1);
	int getUsedLine();
	int getLineOffset();

};