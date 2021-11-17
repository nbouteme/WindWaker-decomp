#pragma once
#include <ctypes.h>


//Expected size is 0x000004
extern struct JUTProcBar * JUTProcBar;


namespace JUtility {
//Expected size is 0x000004
extern undefined4 cnt$2296;

//Expected size is 0x000001
extern undefined1 init$2297;

//Expected size is 0x000004
extern undefined4 cntUser$2345;

//Expected size is 0x000001
extern undefined1 init$2346;

}

namespace JUtility {
int addrToXPos(int param_1,uint param_2);
int byteToXLen(uint param_1,uint param_2);
void heapBar(JKRHeap *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,uint param_6);
}

namespace JUTProcBar {
}
