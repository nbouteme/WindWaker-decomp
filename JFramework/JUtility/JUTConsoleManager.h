#pragma once

#include "../JFramework/JGadget.h"
#include "../JKernel/JKernel.h"
#include "./JUTAssert.h"

struct JUTConsoleManager {
	static JUTConsoleManager *sManager;
	JGadget::TNodeLinkList consoles;
	JUTConsole *console2 = nullptr, *console = nullptr;

	static JUTConsoleManager *createManager(JKRHeap *param_1);

	void appendConsole(JUTConsole *param_1);
	void draw();
	void drawDirect(bool waitforinterrupt);
	void removeConsole(JUTConsole *param_1);
	void setDirectConsole(JUTConsole *param_1);
};