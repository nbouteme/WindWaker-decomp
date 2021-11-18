#pragma once
#include <ctypes.h>



namespace os {
//[Data] Expected size is 0x00003c
extern undefined4 __OSExceptionLocations;

//[Data] Expected size is 0x000004
extern pointer __OSVersion;

//[BSS] Expected size is 0x000020
extern undefined DriveInfo;
//[BSS] Expected size is 0x000030
extern undefined DriveBlock;
//[BSS] Expected size is 0x000004
extern undefined4 BootInfo;
//[BSS] Expected size is 0x000004
extern undefined4 BI2DebugFlag;
//[BSS] Expected size is 0x000004
extern undefined4 BI2DebugFlagHolder;
//[BSS] Expected size is 0x000004
extern undefined4 __OSIsGcam;
//[BSS] Expected size is 0x000004
extern undefined4 AreWeInitialized;
//[BSS] Expected size is 0x000004
extern undefined4 OSExceptionTable;
//[BSS] Expected size is 0x000004
extern undefined4 __OSSavedRegionEnd;
//[BSS] Expected size is 0x000004
extern undefined4 __OSSavedRegionStart;
//[BSS] Expected size is 0x000004
extern undefined4 __OSInIPL;
//[BSS] Expected size is 0x000008
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
