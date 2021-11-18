#pragma once
#include <ctypes.h>



namespace si {
//[Data] Expected size is 0x000014
extern undefined4 Si;

//[Data] Expected size is 0x000010
extern undefined Type;

//[Data] Expected size is 0x000004
extern undefined4 __SIVersion;

//[BSS] Expected size is 0x000080
extern undefined4 Packet;
//[BSS] Expected size is 0x0000a0
extern undefined Alarm;
//[BSS] Expected size is 0x000020
extern undefined TypeTime;
//[BSS] Expected size is 0x000020
extern undefined XferTime;
//[BSS] Expected size is 0x000040
extern undefined TypeCallback;
//[BSS] Expected size is 0x000010
extern undefined4 RDSTHandler;
//[BSS] Expected size is 0x000010
extern undefined InputBufferValid;
//[BSS] Expected size is 0x000020
extern undefined InputBuffer;
//[BSS] Expected size is 0x000010
extern undefined4 InputBufferVcount;
//[BSS] Expected size is 0x000010
extern undefined cmdFixDevice$327;
//[BSS] Expected size is 0x000004
extern undefined cmdTypeAndStatus$78;
//[BSS] Expected size is 0x000004
extern undefined cmdTypeAndStatus$372;
//[BSS] Expected size is 0x000004
extern undefined4 __PADFixBits;
undefined4 SIBusy(void);
undefined4 SIIsChanBusy(int param_1);
uint CompleteTransfer(void);
void SIInterruptHandler(undefined4 param_1,undefined4 param_2);
bool SIEnablePollingInterrupt(int param_1);
undefined4 SIRegisterPollingHandler(int param_1);
undefined4 SIUnregisterPollingHandler(int param_1);
void SIInit(void);
undefined4 __SITransfer(uint param_1,undefined4 *param_2,int param_3,undefined4 param_4,int param_5,int param_6);
uint SIGetStatus(int param_1);
void SISetCommand(int param_1,undefined4 param_2);
void SITransferCommands(void);
uint SISetXY(int param_1,int param_2);
uint SIEnablePolling(uint param_1);
uint SIDisablePolling(uint param_1);
bool SIGetResponseRaw(int param_1);
int SIGetResponse(int param_1,undefined4 *param_2);
void AlarmHandler(int param_1);
undefined4 SITransfer(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,uint param_7,uint param_8);
void GetTypeCallback(int param_1,uint param_2);
int SIGetType(uint param_1);
undefined4 SIGetTypeAsync(int param_1,code *param_2);
uint SIDecodeType(uint param_1);
void SIProbe(void);
}
