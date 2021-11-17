#pragma once
#include <ctypes.h>



namespace pad {
//Expected size is 0x000010
extern undefined Type;

//Expected size is 0x000030
extern undefined Origin;

//Expected size is 0x000010
extern undefined4 CmdProbeDevice;

//Expected size is 0x000004
extern undefined4 Initialized;

//Expected size is 0x000004
extern undefined4 EnabledBits;

//Expected size is 0x000004
extern undefined4 ResettingBits;

//Expected size is 0x000004
extern undefined4 RecalibrateBits;

//Expected size is 0x000004
extern undefined4 WaitingBits;

//Expected size is 0x000004
extern undefined4 CheckingBits;

//Expected size is 0x000004
extern undefined4 PendingBits;

//Expected size is 0x000004
extern undefined4 SamplingCallback;

//Expected size is 0x000004
extern undefined4 recalibrated$397;

//Expected size is 0x000004
extern undefined4 __PADSpec;

void UpdateOrigin(int param_1);
void PADOriginCallback(undefined4 param_1,uint param_2);
void PADOriginUpdateCallback(int param_1,uint param_2);
void PADProbeCallback(undefined4 param_1,uint param_2);
void PADTypeAndStatusCallback(undefined4 param_1,uint param_2);
void PADReceiveCheckCallback(int param_1,uint param_2);
undefined4 PADReset(uint param_1);
undefined4 PADRecalibrate(uint param_1);
undefined4 PADInit(void);
uint PADRead(ushort *param_1);
void PADControlMotor(int param_1,uint param_2);
void PADSetSpec(int param_1);
void SPEC0_MakeStatus(undefined4 param_1,ushort *param_2,uint *param_3);
void SPEC1_MakeStatus(undefined4 param_1,ushort *param_2,uint *param_3);
void SPEC2_MakeStatus(int param_1,ushort *param_2,undefined4 *param_3);
void PADSetAnalogMode(int param_1);
int OnReset(int param_1);
void SamplingHandler(undefined4 param_1,undefined4 param_2);
undefined4 PADSetSamplingCallback(int param_1);
bool __PADDisableRecalibration(int param_1);
}
