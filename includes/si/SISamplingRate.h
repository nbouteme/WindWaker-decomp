#pragma once
#include <ctypes.h>



namespace si {
//Expected size is 0x000004
extern undefined4 SamplingRate;

void SISetSamplingRate(uint param_1);
void SIRefreshSamplingRate(void);
}
