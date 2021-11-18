#pragma once
#include <ctypes.h>



namespace dvd {
//[Data] Expected size is 0x00000c
extern undefined4 ImmCommand;

//[Data] Expected size is 0x000004
extern undefined4 __DVDVersion;

//[Data] Expected size is 0x000004
extern undefined4 autoInvalidation;

//[Data] Expected size is 0x000004
extern undefined4 checkOptionalCommand;

//[Data] Expected size is 0x000004
extern undefined4 DmaCommand;

//[BSS] Expected size is 0x000020
extern undefined BB2;
//[BSS] Expected size is 0x000020
extern undefined CurrDiskID;
//[BSS] Expected size is 0x000030
extern undefined DummyCommandBlock;
//[BSS] Expected size is 0x000028
extern undefined ResetAlarm;
//[BSS] Expected size is 0x000004
extern undefined4 executing;
//[BSS] Expected size is 0x000004
extern undefined4 IDShouldBe;
//[BSS] Expected size is 0x000004
extern undefined4 bootInfo;
//[BSS] Expected size is 0x000004
extern undefined4 PauseFlag;
//[BSS] Expected size is 0x000004
extern undefined4 PausingFlag;
//[BSS] Expected size is 0x000004
extern undefined4 AutoFinishing;
//[BSS] Expected size is 0x000004
extern undefined4 FatalErrorFlag;
//[BSS] Expected size is 0x000004
extern undefined4 CurrCommand;
//[BSS] Expected size is 0x000004
extern undefined4 Canceling;
//[BSS] Expected size is 0x000004
extern undefined4 CancelCallback;
//[BSS] Expected size is 0x000004
extern undefined4 ResumeFromHere;
//[BSS] Expected size is 0x000004
extern undefined4 CancelLastError;
//[BSS] Expected size is 0x000004
extern undefined4 LastError;
//[BSS] Expected size is 0x000004
extern undefined4 NumInternalRetry;
//[BSS] Expected size is 0x000004
extern undefined4 ResetRequired;
//[BSS] Expected size is 0x000004
extern undefined4 FirstTimeInBootrom;
//[BSS] Expected size is 0x000004
extern undefined4 DVDInitialized;
//[BSS] Expected size is 0x000004
extern undefined4 LastState;
void defaultOptionalCommandChecker(void);
void DVDInit(void);
void stateReadingFST(void);
void cbForStateReadingFST(uint param_1);
void cbForStateError(int param_1);
void stateTimeout(void);
void stateGettingError(void);
undefined4 CategorizeError(uint param_1);
void cbForStateGettingError(uint param_1);
void cbForUnrecoveredError(uint param_1);
void cbForUnrecoveredErrorRetry(uint param_1);
void stateGoToRetry(void);
void cbForStateGoToRetry(uint param_1);
void stateCheckID(void);
void stateCheckID3(void);
void stateCheckID2a(void);
void cbForStateCheckID2a(uint param_1);
void stateCheckID2(void);
void cbForStateCheckID1(uint param_1);
void cbForStateCheckID2(uint param_1);
void cbForStateCheckID3(uint param_1);
void AlarmHandler(void);
void stateCoverClosed(void);
void stateCoverClosed_CMD(void);
void cbForStateCoverClosed(uint param_1);
void stateMotorStopped(void);
void cbForStateMotorStopped(void);
void stateReady(void);
void stateBusy(int param_1);
void cbForStateBusy(uint param_1);
undefined4 DVDReadAbsAsyncPrio(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6);
undefined4 DVDReadAbsAsyncForBS(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5);
undefined4 DVDReadDiskID(int param_1,undefined4 param_2,undefined4 param_3);
undefined4 DVDPrepareStreamAbsAsync(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
undefined4 DVDCancelStreamAsync(int param_1,undefined4 param_2);
undefined4 DVDStopStreamAtEndAsync(int param_1,undefined4 param_2);
undefined4 DVDGetStreamPlayAddrAsync(int param_1,undefined4 param_2);
undefined4 DVDInquiryAsync(int param_1,undefined4 param_2,undefined4 param_3);
void DVDReset(void);
int DVDGetCommandBlockStatus(int param_1);
int DVDGetDriveStatus(void);
undefined4 DVDSetAutoInvalidation(undefined4 param_1);
undefined4 DVDCancelAsync(int param_1,code *param_2);
undefined4 DVDCancel(int param_1);
void cbForCancelSync(void);
undefined4 DVDGetCurrentDiskID(void);
undefined4 DVDCheckDisk(void);
void __DVDPrepareResetAsync(code *param_1);
}
