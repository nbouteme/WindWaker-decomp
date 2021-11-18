#pragma once
#include <ctypes.h>



namespace JAudio {
//[Data] Expected size is 0x000002
extern undefined2 DSP_MIXERLEVEL;

//[BSS] Expected size is 0x000004
extern undefined4 flag;
//[BSS] Expected size is 0x000004
extern undefined4 d_waitflag;
void DSPReleaseHalt2(int param_1);
void DSPReleaseHalt(void);
void setup_callback(void);
void DsetupTable(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5);
void DsetMixerLevel(double param_1);
void DsyncFrame(uint param_1,undefined4 param_2,undefined4 param_3);
void dummy_callback(void);
void DsetDolbyDelay(undefined4 param_1,uint param_2);
}
