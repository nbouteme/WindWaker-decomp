#pragma once
#include <ctypes.h>



namespace JAudio {
//[BSS] Expected size is 0x00000c
extern undefined4 sync_stack;
//[BSS] Expected size is 0x000001
extern undefined1 DSP_prior_yield;
//[BSS] Expected size is 0x000004
extern undefined4 AUDIO_UPDATE_REQUEST;
//[BSS] Expected size is 0x000004
extern undefined4 DSP_prior_task;
void __DSPHandler(undefined4 param_1,undefined4 param_2);
void DsyncFrame2(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void Dsp_Update_Request(void);
uint Dsp_Running_Check(void);
void Dsp_Running_Start(void);
}
