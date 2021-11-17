#pragma once
#include <ctypes.h>



namespace dsp {
//Expected size is 0x000004
extern undefined4 __DSP_init_flag;

ushort DSPCheckMailToDSP(void);
ushort DSPCheckMailFromDSP(void);
undefined4 DSPReadMailFromDSP(void);
void DSPSendMailToDSP(undefined4 param_1);
void DSPAssertInt(void);
void DSPInit(void);
}
