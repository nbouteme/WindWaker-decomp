#pragma once
#include <ctypes.h>



namespace os {
//Expected size is 0x000020
extern undefined DriveInfo;

//Expected size is 0x000030
extern undefined DriveBlock;

//Expected size is 0x000004
extern undefined4 BootInfo;

//Expected size is 0x000004
extern undefined4 BI2DebugFlag;

//Expected size is 0x000004
extern undefined4 BI2DebugFlagHolder;

//Expected size is 0x000004
extern undefined4 __OSIsGcam;

//Expected size is 0x000004
extern undefined4 AreWeInitialized;

//Expected size is 0x000004
extern undefined4 OSExceptionTable;

//Expected size is 0x000004
extern undefined4 __OSSavedRegionEnd;

//Expected size is 0x000004
extern undefined4 __OSSavedRegionStart;

//Expected size is 0x000004
extern undefined4 __OSInIPL;

//Expected size is 0x000008
extern undefined4 __OSStartTime;

int OSGetConsoleType(void);
void ClearArena(void);
void InquiryCallback(undefined4 param_1,int param_2);
void OSInit(void);
void OSExceptionInit(void);
undefined4 __OSDBIntegrator(void);
undefined4 __OSDBJump(void);
undefined4 __OSSetExceptionHandler(uint param_1,undefined4 param_2);
undefined4 __OSGetExceptionHandler(uint param_1);
void OSExceptionVector(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void OSDefaultExceptionHandler(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8);
undefined4 __OSPSInit(void);
uint __OSGetDIConfig(void);
void OSRegisterVersion(undefined4 param_1);
}
