#pragma once
#include <ctypes.h>


//Expected size is 0x00000c
extern undefined1 JKRThread;

//Expected size is 0x000004
extern struct JKRThreadSwitch * JKRThreadSwitch;


namespace JKernel {
//Expected size is 0x000004
extern undefined4 preEnd;

}
//Expected size is 0x000004
extern undefined1 JKRThreadSwitch;

//Expected size is 0x000004
extern undefined1 JKRThreadSwitch;


namespace JKRThreadSwitch {
JKRThreadSwitch * createManager(JKRHeap *param_1);
}

namespace JKernel {
void __sinit_JKRThread_cpp(void);
}
