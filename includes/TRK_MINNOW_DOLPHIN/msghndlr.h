#pragma once
#include <ctypes.h>



namespace TRK_MINNOW_DOLPHIN {
//Expected size is 0x000004
extern undefined4 IsTRKConnected;

void TRKDoSetOption(int param_1);
void TRKDoStop(int param_1);
void TRKDoStep(int param_1);
void TRKDoContinue(int param_1);
void TRKDoFlushCache(int param_1);
void TRKDoWriteRegisters(int param_1);
void TRKDoReadRegisters(int param_1);
void TRKDoWriteMemory(int param_1);
void TRKDoReadMemory(int param_1);
void TRKDoCPUType(int param_1);
void TRKDoSupportMask(int param_1);
void TRKDoVersions(int param_1);
undefined4 TRKDoReset(int param_1);
int TRKDoDisconnect(int param_1);
void TRKDoConnect(int param_1);
void TRKDoUnsupported(int param_1);
void TRKStandardACK(int param_1,undefined param_2,undefined param_3);
void SetTRKConnected(undefined4 param_1);
undefined4 GetTRKConnected(void);
}
