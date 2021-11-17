#pragma once
#include <ctypes.h>



namespace dvd {
//Expected size is 0x000020
extern undefined BB2;

//Expected size is 0x000020
extern undefined CurrDiskID;

//Expected size is 0x000030
extern undefined DummyCommandBlock;

//Expected size is 0x000028
extern undefined ResetAlarm;

//Expected size is 0x000004
extern undefined4 executing;

//Expected size is 0x000004
extern undefined4 IDShouldBe;

//Expected size is 0x000004
extern undefined4 bootInfo;

//Expected size is 0x000004
extern undefined4 PauseFlag;

//Expected size is 0x000004
extern undefined4 PausingFlag;

//Expected size is 0x000004
extern undefined4 AutoFinishing;

//Expected size is 0x000004
extern undefined4 FatalErrorFlag;

//Expected size is 0x000004
extern undefined4 CurrCommand;

//Expected size is 0x000004
extern undefined4 Canceling;

//Expected size is 0x000004
extern undefined4 CancelCallback;

//Expected size is 0x000004
extern undefined4 ResumeFromHere;

//Expected size is 0x000004
extern undefined4 CancelLastError;

//Expected size is 0x000004
extern undefined4 LastError;

//Expected size is 0x000004
extern undefined4 NumInternalRetry;

//Expected size is 0x000004
extern undefined4 ResetRequired;

//Expected size is 0x000004
extern undefined4 FirstTimeInBootrom;

//Expected size is 0x000004
extern undefined4 DVDInitialized;

//Expected size is 0x000004
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
