#pragma once
#include <ctypes.h>



namespace ar {
//[Data] Expected size is 0x000004
extern undefined4 __ARVersion;

//[BSS] Expected size is 0x000004
extern undefined4 __AR_Callback;
//[BSS] Expected size is 0x000004
extern undefined4 __AR_Size;
//[BSS] Expected size is 0x000004
extern undefined4 __AR_InternalSize;
//[BSS] Expected size is 0x000004
extern undefined4 __AR_ExpansionSize;
//[BSS] Expected size is 0x000004
extern undefined4 __AR_StackPointer;
//[BSS] Expected size is 0x000004
extern undefined4 __AR_FreeBlocks;
//[BSS] Expected size is 0x000004
extern undefined4 __AR_BlockLength;
//[BSS] Expected size is 0x000004
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
