#pragma once
#include <ctypes.h>



namespace JAudio {
//[Data] Expected size is 0x001d20
extern undefined jdsp;

//[BSS] Expected size is 0x000050
extern undefined audio_task;
//[BSS] Expected size is 0x002000
extern undefined AUDIO_YIELD_BUFFER;
//[BSS] Expected size is 0x000080
extern undefined taskwork;
//[BSS] Expected size is 0x000004
extern undefined4 taskreadp;
//[BSS] Expected size is 0x000004
extern undefined4 taskwritep;
void DspHandShake(void);
void DspBoot(undefined4 param_1);
undefined4 DSPSendCommands2(undefined4 *param_1,uint param_2,int param_3);
void DspInitWork(void);
uint DspStartWork(undefined4 param_1,undefined4 param_2);
void DspFinishWork(short param_1);
}
