#pragma once

namespace mDoMain {
	extern unsigned long long sPowerOnTime;
	extern int developmentMode;
	extern char COPYDATE_STRING[];
    extern int memMargin;
	extern int sHungUpTime;
}

namespace m_Do_main {
	extern os::OSThread mainThread;
	int main(int ac, int *av);
}  // namespace m_Do_main
