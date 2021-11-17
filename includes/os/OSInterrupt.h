#pragma once
#include <ctypes.h>



namespace os {
//Expected size is 0x000004
extern undefined4 InterruptHandlerTable;

//Expected size is 0x000004
extern undefined4 __OSLastInterruptSrr0;

//Expected size is 0x000002
extern undefined2 __OSLastInterrupt;

//Expected size is 0x000008
extern undefined4 __OSLastInterruptTime;

ulonglong OSDisableInterrupts(void);
ulonglong OSEnableInterrupts(void);
uint OSRestoreInterrupts(void);
undefined4 __OSSetInterruptHandler(short param_1,undefined4 param_2);
undefined4 __OSGetInterruptHandler(short param_1);
void __OSInterruptInit(void);
uint SetInterruptMask(uint param_1,uint param_2);
uint __OSMaskInterrupts(uint param_1);
uint __OSUnmaskInterrupts(uint param_1);
void __OSDispatchInterrupt(undefined4 param_1,int param_2);
void ExternalInterruptHandler(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8);
}
