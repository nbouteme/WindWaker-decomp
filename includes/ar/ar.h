#pragma once
#include <ctypes.h>



namespace ar {
//Expected size is 0x000004
extern undefined4 __AR_Callback;

//Expected size is 0x000004
extern undefined4 __AR_Size;

//Expected size is 0x000004
extern undefined4 __AR_InternalSize;

//Expected size is 0x000004
extern undefined4 __AR_ExpansionSize;

//Expected size is 0x000004
extern undefined4 __AR_StackPointer;

//Expected size is 0x000004
extern undefined4 __AR_FreeBlocks;

//Expected size is 0x000004
extern undefined4 __AR_BlockLength;

//Expected size is 0x000004
extern undefined4 __AR_init_flag;

undefined4 ARRegisterDMACallback(undefined4 param_1);
void ARStartDMA(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
int ARAlloc(int param_1);
undefined4 ARInit(undefined4 param_1,undefined4 param_2);
undefined4 ARGetBaseAddress(void);
undefined4 ARGetSize(void);
void __ARHandler(undefined4 param_1,undefined4 param_2);
void __ARChecksize(void);
}
