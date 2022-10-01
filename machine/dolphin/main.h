#pragma once

#include <dolphin/os.h>

namespace mDoMain {
	extern unsigned long long sPowerOnTime;
	extern int developmentMode;
	extern char COPYDATE_STRING[];
	extern int memMargin;
	extern int sHungUpTime;
}

struct JKRExpHeap;

namespace m_Do_main {
	extern os::OSThread mainThread;
	int main(int ac, int *av);
	int countUsed(JKRExpHeap *param_1);
}  // namespace m_Do_main
