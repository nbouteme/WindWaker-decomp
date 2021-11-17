#pragma once
#include <ctypes.h>

#include <Demangler/OSThread.h>


namespace m_Do_main {
//Expected size is 0x000318
extern struct OSThread mainThread;

//Expected size is 0x000001
extern undefined1 fillcheck_check_frame;

}

namespace mDoMain {
//Expected size is 0x000008
extern long sPowerOnTime;

//Expected size is 0x000008
extern undefined1 sHungUpTime;

}

namespace m_Do_main {
//Expected size is 0x000001
extern undefined1 mDisplayHeapSize;

//Expected size is 0x000001
extern undefined1 mSelectHeapBar;

//Expected size is 0x000001
extern undefined1 mCheckHeap;

//Expected size is 0x000004
extern float console_position_x$4105;

//Expected size is 0x000001
extern undefined1 init$4106;

//Expected size is 0x000004
extern float console_position_y$4108;

//Expected size is 0x000001
extern undefined1 init$4109;

//Expected size is 0x000004
extern float console_scroll$4111;

//Expected size is 0x000001
extern undefined1 init$4112;

//Expected size is 0x000004
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
