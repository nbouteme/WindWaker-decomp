#pragma once
#include <ctypes.h>

#include <Demangler/OSThread.h>


namespace m_Do_main {
//[Data] Expected size is 0x000024
extern pointer RootHeapCheck;

//[Data] Expected size is 0x000024
extern pointer SystemHeapCheck;

//[Data] Expected size is 0x000024
extern pointer ZeldaHeapCheck;

//[Data] Expected size is 0x000024
extern pointer GameHeapCheck;

//[Data] Expected size is 0x000024
extern pointer ArchiveHeapCheck;

//[Data] Expected size is 0x000024
extern pointer CommandHeapCheck;

//[Data] Expected size is 0x000018
extern pointer[6] * * * HeapCheckTable;

//[Data] Expected size is 0x000014
extern undefined * desc1$4076;

//[Data] Expected size is 0x000014
extern undefined * desc2$4077;

}

namespace mDoMain {
//[Data] Expected size is 0x000001
extern undefined1 developmentMode;

//[Data] Expected size is 0x000004
extern int memMargin;

}

namespace m_Do_main {
//[Data] Expected size is 0x000001
extern undefined1 mHeapBriefType;

//[BSS] Expected size is 0x000318
extern struct OSThread mainThread;
//[BSS] Expected size is 0x000001
extern undefined1 fillcheck_check_frame;
}

namespace mDoMain {
//[BSS] Expected size is 0x000008
extern long sPowerOnTime;
//[BSS] Expected size is 0x000008
extern undefined1 sHungUpTime;
}

namespace m_Do_main {
//[BSS] Expected size is 0x000001
extern undefined1 mDisplayHeapSize;
//[BSS] Expected size is 0x000001
extern undefined1 mSelectHeapBar;
//[BSS] Expected size is 0x000001
extern undefined1 mCheckHeap;
//[BSS] Expected size is 0x000004
extern float console_position_x$4105;
//[BSS] Expected size is 0x000001
extern undefined1 init$4106;
//[BSS] Expected size is 0x000004
extern float console_position_y$4108;
//[BSS] Expected size is 0x000001
extern undefined1 init$4109;
//[BSS] Expected size is 0x000004
extern float console_scroll$4111;
//[BSS] Expected size is 0x000001
extern undefined1 init$4112;
//[BSS] Expected size is 0x000004
extern undefined4 frame$4236;
void version_check(void);
}

namespace m_Do_main {
void CheckHeap(JUTGamePad *param_1);
int countUsed(int param_1);
}

namespace m_Do_main {
void debugDisplay(void);
undefined4 Debug_console(JUTGamePad *param_1,int param_2);
}

namespace m_Do_main {
void LOAD_COPYDATE(void);
void debug(void);
void main01(void);
void main(void);
}
