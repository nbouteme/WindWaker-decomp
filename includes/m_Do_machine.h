#pragma once
#include <ctypes.h>



namespace mDoMch {
//Expected size is 0x000001
extern undefined1 mDebugFill;

}

namespace m_Do_machine {
//Expected size is 0x000004
extern undefined4 solidHeapErrors;

//Expected size is 0x000004
extern undefined4 gameHeapErrors;

//Expected size is 0x000004
extern undefined4 zeldaHeapErrors;

//Expected size is 0x000004
extern undefined4 commandHeapErrors;

//Expected size is 0x000004
extern undefined4 archiveHeapErrors;

//Expected size is 0x000004
extern undefined4 unknownHeapErrors;

//Expected size is 0x000004
extern undefined4 heapErrors;

//Expected size is 0x000005
extern undefined1 tmpString$4003;

//Expected size is 0x000001
extern byte key_link$4106;

//Expected size is 0x000001
extern byte key_ganon$4107;

//Expected size is 0x000001
extern byte key_zelda$4108;

char * myGetHeapTypeByString(JKRExpHeap *param_1);
void myMemoryErrorRoutine(JKRHeap *param_1,undefined4 param_2,undefined4 param_3);
void myHeapCheckRecursive(int *param_1);
void mDoMch_HeapCheckAll(void);
int developKeyCheck(int param_1,int param_2);
void myExceptionCallback(undefined4 param_1,undefined4 param_2);
void fault_callback_scroll(void);
undefined4 mDoMch_Create(void);
}
