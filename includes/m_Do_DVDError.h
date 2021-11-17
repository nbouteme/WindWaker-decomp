#pragma once
#include <ctypes.h>



namespace m_Do_DVDError {
//Expected size is 0x000318
extern undefined DvdErr_thread;

//Expected size is 0x001000
extern undefined DvdErr_stack;

//Expected size is 0x000028
extern undefined Alarm;

//Expected size is 0x000001
extern undefined1 mDoDvdErr_initialized;

void mDoDvdErr_ThdInit(undefined4 param_1,undefined4 param_2);
void mDoDvdErr_ThdCleanup(void);
void mDoDvdErr_Watch(void);
void AlarmHandler(void);
}
