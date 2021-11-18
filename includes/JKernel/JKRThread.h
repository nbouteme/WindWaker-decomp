#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x00000c
extern undefined1 JKRThreadSwitch;

//[Data] Expected size is 0x000010
extern undefined1 JKRThread;

//[BSS] Expected size is 0x00000c
extern undefined1 JKRThread;
//[BSS] Expected size is 0x000004
extern struct JKRThreadSwitch * JKRThreadSwitch;

namespace JKernel {
//[BSS] Expected size is 0x000004
extern undefined4 preEnd;
}
//[BSS] Expected size is 0x000004
extern undefined1 JKRThreadSwitch;
//[BSS] Expected size is 0x000004
extern undefined1 JKRThreadSwitch;

namespace JKRThreadSwitch {
JKRThreadSwitch * createManager(JKRHeap *param_1);
}

namespace JKernel {
void __sinit_JKRThread_cpp(void);
}
