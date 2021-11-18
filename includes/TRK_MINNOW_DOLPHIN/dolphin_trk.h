#pragma once
#include <ctypes.h>



namespace TRK_MINNOW_DOLPHIN {
//[Data] Expected size is 0x00003c
extern undefined4 TRK_ISR_OFFSETS;

//[BSS] Expected size is 0x000004
extern undefined4 lc_base;
undefined8 InitMetroTRK(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8);
undefined4 TRKInitializeTarget(void);
uint TRKTargetTranslate(uint param_1);
void EnableMetroTRKInterrupts(void);
}
