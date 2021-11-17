#pragma once
#include <ctypes.h>



namespace dvd {
//Expected size is 0x00003c
extern undefined4 CommandList;

//Expected size is 0x000028
extern undefined AlarmForWA;

//Expected size is 0x000028
extern undefined AlarmForTimeout;

//Expected size is 0x000028
extern undefined AlarmForBreak;

//Expected size is 0x00000c
extern undefined4 Prev;

//Expected size is 0x00000c
extern undefined4 Curr;

//Expected size is 0x000004
extern undefined4 StopAtNextInt;

//Expected size is 0x000004
extern undefined4 LastLength;

//Expected size is 0x000004
extern undefined4 Callback;

//Expected size is 0x000004
extern undefined4 ResetCoverCallback;

//Expected size is 0x000008
extern undefined4 LastResetEnd;

//Expected size is 0x000004
extern undefined4 ResetOccurred;

//Expected size is 0x000004
extern undefined4 WaitingCoverClose;

//Expected size is 0x000004
extern undefined4 Breaking;

//Expected size is 0x000004
extern undefined4 WorkAroundType;

//Expected size is 0x000004
extern undefined4 WorkAroundSeekLocation;

//Expected size is 0x000008
extern undefined4 LastReadFinished;

//Expected size is 0x000008
extern undefined4 LastReadIssued;

//Expected size is 0x000004
extern undefined4 LastCommandWasRead;

//Expected size is 0x000004
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
