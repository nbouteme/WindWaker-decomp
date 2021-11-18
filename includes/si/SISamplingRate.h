#pragma once
#include <ctypes.h>



namespace si {
//[Data] Expected size is 0x000030
extern undefined2 XYNTSC;

//[Data] Expected size is 0x000030
extern undefined XYPAL;

//[BSS] Expected size is 0x000004
extern undefined4 SamplingRate;
void SISetSamplingRate(uint param_1);
void SIRefreshSamplingRate(void);
}
