#pragma once
#include <ctypes.h>



namespace dvd {
//[Data] Expected size is 0x000004
extern undefined4 FirstRead;

//[BSS] Expected size is 0x00003c
extern undefined4 CommandList;
//[BSS] Expected size is 0x000028
extern undefined AlarmForWA;
//[BSS] Expected size is 0x000028
extern undefined AlarmForTimeout;
//[BSS] Expected size is 0x000028
extern undefined AlarmForBreak;
//[BSS] Expected size is 0x00000c
extern undefined4 Prev;
//[BSS] Expected size is 0x00000c
extern undefined4 Curr;
//[BSS] Expected size is 0x000004
extern undefined4 StopAtNextInt;
//[BSS] Expected size is 0x000004
extern undefined4 LastLength;
//[BSS] Expected size is 0x000004
extern undefined4 Callback;
//[BSS] Expected size is 0x000004
extern undefined4 ResetCoverCallback;
//[BSS] Expected size is 0x000008
extern undefined4 LastResetEnd;
//[BSS] Expected size is 0x000004
extern undefined4 ResetOccurred;
//[BSS] Expected size is 0x000004
extern undefined4 WaitingCoverClose;
//[BSS] Expected size is 0x000004
extern undefined4 Breaking;
//[BSS] Expected size is 0x000004
extern undefined4 WorkAroundType;
//[BSS] Expected size is 0x000004
extern undefined4 WorkAroundSeekLocation;
//[BSS] Expected size is 0x000008
extern undefined4 LastReadFinished;
//[BSS] Expected size is 0x000008
extern undefined4 LastReadIssued;
//[BSS] Expected size is 0x000004
extern undefined4 LastCommandWasRead;
//[BSS] Expected size is 0x000004
extern undefined4 NextCommandNumber;
void __DVDInitWA(void);
void __DVDInterruptHandler(undefined4 param_1,undefined4 param_2);
void AlarmHandler(void);
void AlarmHandlerForTimeout(undefined4 param_1,undefined4 param_2);
void Read(undefined4 param_1,uint param_2,uint param_3,undefined4 param_4);
void SeekTwiceBeforeRead(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4);
undefined4 DVDLowRead(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4);
undefined4 DVDLowSeek(uint param_1,undefined4 param_2);
undefined4 DVDLowWaitCoverClose(undefined4 param_1);
undefined4 DVDLowReadDiskID(undefined4 param_1,undefined4 param_2);
undefined4 DVDLowStopMotor(undefined4 param_1);
undefined4 DVDLowRequestError(undefined4 param_1);
undefined4 DVDLowInquiry(undefined4 param_1,undefined4 param_2);
undefined4 DVDLowAudioStream(uint param_1,undefined4 param_2,uint param_3,undefined4 param_4);
undefined4 DVDLowRequestAudioStatus(uint param_1,undefined4 param_2);
undefined4 DVDLowAudioBufferConfig(int param_1,uint param_2,undefined4 param_3);
void DVDLowReset(void);
undefined4 DVDLowBreak(void);
undefined4 DVDLowClearCallback(void);
void __DVDLowSetWAType(undefined4 param_1,undefined4 param_2);
}
