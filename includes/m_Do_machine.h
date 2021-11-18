#pragma once
#include <ctypes.h>



namespace m_Do_machine {
//[Data] Expected size is 0x00003c
extern undefined g_ntscZeldaIntDf;

//[Data] Expected size is 0x00003c
extern undefined g_ntscZeldaProg;

}

namespace mDoMch_render_c {
//[Data] Expected size is 0x000004
extern pointer mRenderModeObj;

}

namespace mDoMch {
//[BSS] Expected size is 0x000001
extern undefined1 mDebugFill;
}

namespace m_Do_machine {
//[BSS] Expected size is 0x000004
extern undefined4 solidHeapErrors;
//[BSS] Expected size is 0x000004
extern undefined4 gameHeapErrors;
//[BSS] Expected size is 0x000004
extern undefined4 zeldaHeapErrors;
//[BSS] Expected size is 0x000004
extern undefined4 commandHeapErrors;
//[BSS] Expected size is 0x000004
extern undefined4 archiveHeapErrors;
//[BSS] Expected size is 0x000004
extern undefined4 unknownHeapErrors;
//[BSS] Expected size is 0x000004
extern undefined4 heapErrors;
//[BSS] Expected size is 0x000005
extern undefined1 tmpString$4003;
//[BSS] Expected size is 0x000001
extern byte key_link$4106;
//[BSS] Expected size is 0x000001
extern byte key_ganon$4107;
//[BSS] Expected size is 0x000001
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
