#pragma once
#include <ctypes.h>



namespace TRK_MINNOW_DOLPHIN {
//Expected size is 0x000002
extern undefined2 TRK_saved_exceptionID;

//Expected size is 0x0000a4
extern undefined4 gTRKState;

//Expected size is 0x000430
extern undefined4 gTRKCPUState;

//Expected size is 0x000094
extern undefined gTRKSaveState;

//Expected size is 0x000010
extern undefined TRKvalue128_temp;

void __TRK_get_MSR(void);
void __TRK_set_MSR(void);
void TRK_ppc_memcpy(int param_1,int param_2,int param_3);
undefined4 TRKInterruptHandler(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8);
void TRKExceptionHandler(undefined2 param_1);
undefined4 TRKSwapAndGo(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8);
void TRKInterruptHandlerEnableInterrupts(void);
void TRKTargetSetInputPendingPtr(undefined4 param_1);
undefined4 TRKPPCAccessFPRegister(undefined4 *param_1,uint param_2,int param_3);
undefined4 TRKTargetStop(void);
void TRKTargetSetStopped(undefined4 param_1);
undefined4 TRKTargetStopped(void);
undefined4 TRKTargetFlushCache(undefined4 param_1,uint param_2,uint param_3);
int TRKTargetSupportRequest(void);
undefined4 TRKTargetGetPC(void);
undefined4 TRKTargetStepOutOfRange(undefined4 param_1,undefined4 param_2,int param_3);
undefined4 TRKTargetSingleStep(int param_1,int param_2);
void TRKTargetAddExceptionInfo(undefined4 param_1);
void TRKTargetAddStopInfo(undefined4 param_1);
undefined4 TRKTargetInterrupt(byte *param_1);
void TRKPostInterruptEvent(void);
undefined4 TRKTargetCPUType(undefined *param_1);
undefined4 TRKTargetSupportMask(undefined *param_1);
undefined4 TRKTargetVersions(undefined *param_1);
int TRKTargetAccessExtended2(uint param_1,uint param_2,undefined4 param_3,int *param_4,int param_5);
uint TRKTargetAccessExtended1(uint param_1,uint param_2,undefined4 param_3,int *param_4,int param_5);
int TRKTargetAccessFP(uint param_1,uint param_2,undefined4 param_3,int *param_4,int param_5);
undefined4 TRKTargetAccessDefault(int param_1,uint param_2,undefined4 param_3,int *param_4,int param_5);
int TRKTargetAccessMemory(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 param_4,int param_5);
int TRKValidMemory32(uint param_1,int param_2,uint param_3);
}
