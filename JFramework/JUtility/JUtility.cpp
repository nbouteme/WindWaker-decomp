#include "JUtility.h"
#include <cstdio>

#include "JUTAssert.h"
#include <machine/dolphin/printf.h>
#include "../JKernel/JKRExpHeap.h"

int JUtility::sDrawWaiting;
int JUtility::init$2183;
void *JUtility::frameBuffer$2182;

int JUtility::channel_mask[4] = {1 << 31, 1 << 30, 1 << 29, 1 << 28};

float JUtility::oneFrameRate = 8.0;
float JUtility::oneFrameRateUser = 10.0;

void JUtility::JUTReportConsole(const char *, ...) {}
void JUtility::JUTSetReportConsole(JUTConsole *) {}
void JUtility::JUTSetWarningConsole(JUTConsole *) {}
void JUtility::JUTWarningConsole(const char *f, ...) {}
void JUtility::JUTWarningConsole_f(const char *f, ...) {}

void JUtility::JUTReport(int x, int y, const char *, ...) {}
void JUtility::JUTReport(int x, int y, int l, const char *, ...) {}


void JUtility::JUTConsole_print_f_va_(JUTConsole *param_1, char *param_2, va_list param_3) {
	ulong uVar1;
	char acStack1048[1036];

	if (param_1 == (JUTConsole *)0x0) {
		JUTAssertion::getSDevice()->showAssert("JUTConsole.cpp", 0x231, "console!=0");
		m_Do_printf::OSPanic("JUTConsole.cpp", 0x231, "Halt");
	}
	vsnprintf(acStack1048, 0x400, param_2, param_3);
	param_1->print(acStack1048);
}

int JUtility::addrToXPos(void *param_1, uint param_2) {
	return (float)param_2 * (double)(long long)param_1 / (float)JKRHeap::mMemorySize;
}

int JUtility::byteToXLen(uint param_1, uint param_2) {
	return (float)param_2 * (float)param_1 / (float)JKRHeap::mMemorySize;
}

JUTConsole *JUtility::sReportConsole, *JUtility::sWarningConsole;

JUTConsole *JUtility::JUTGetWarningConsole() {
	return sWarningConsole;
}

JUTConsole *JUtility::JUTGetReportConsole() {
	return sReportConsole;
}

void JUtility::heapBar(JKRHeap *param_1, int param_2, int param_3, undefined4 param_4, undefined4 param_5, uint param_6) {
	int iVar1;
	undefined4 local_64;
	undefined4 local_5c;
	uint uStack84;
	uint uStack76;
	uint uStack68;
	uint uStack60;
	uint heapStart;
	uint uStack44;
	uint heapEnd;
	uint uStack28;

	heapStart = param_2 + JUtility::addrToXPos(param_1->mpDataBegin, param_5);
	iVar1 = JUtility::addrToXPos(param_1->mpDataEnd, param_5);
	heapEnd = JUtility::byteToXLen(param_1->getTotalFreeSize(), param_5);
	local_5c = 0xff00c8ff;
	uStack28 = ((int)param_6 >> 1) + (uint)((int)param_6 < 0 && (param_6 & 1) != 0);
	uStack44 = uStack28 + param_3 + param_6 * -2;
	uStack68 = (param_2 + iVar1) - heapStart;
	J2DGraph::J2DFillBox((float)uStack84, (float)uStack76, (float)uStack68, (float)uStack60, (TColor)&local_5c);
	local_64 = 0xffb4faff;
	J2DGraph::J2DFillBox((float)heapStart, (float)uStack44, (float)heapEnd, (float)uStack28, (TColor)&local_64);
}
