#pragma once
#include <ctypes.h>



namespace vi {
//[Data] Expected size is 0x00017c
extern undefined timing;

//[Data] Expected size is 0x000032
extern undefined2 taps;

//[Data] Expected size is 0x000004
extern undefined4 __VIVersion;

//[BSS] Expected size is 0x000076
extern undefined2 regs;
//[BSS] Expected size is 0x000076
extern undefined shdwRegs;
//[BSS] Expected size is 0x000058
extern undefined2 HorVer;
//[BSS] Expected size is 0x000004
extern undefined4 IsInitialized;
//[BSS] Expected size is 0x000004
extern undefined4 retraceCount;
//[BSS] Expected size is 0x000004
extern undefined4 flushFlag;
//[BSS] Expected size is 0x000008
extern undefined retraceQueue;
//[BSS] Expected size is 0x000004
extern undefined4 PreCB;
//[BSS] Expected size is 0x000004
extern undefined4 PostCB;
//[BSS] Expected size is 0x000004
extern undefined4 encoderType;
//[BSS] Expected size is 0x000002
extern undefined2 displayOffsetH;
//[BSS] Expected size is 0x000002
extern undefined2 displayOffsetV;
//[BSS] Expected size is 0x000004
extern undefined4 changeMode;
//[BSS] Expected size is 0x000008
extern undefined4 changed;
//[BSS] Expected size is 0x000004
extern undefined4 shdwChangeMode;
//[BSS] Expected size is 0x000008
extern undefined4 shdwChanged;
//[BSS] Expected size is 0x000004
extern undefined4 CurrTiming;
//[BSS] Expected size is 0x000004
extern undefined4 CurrTvMode;
//[BSS] Expected size is 0x000004
extern undefined4 NextBufAddr;
//[BSS] Expected size is 0x000004
extern undefined4 CurrBufAddr;
//[BSS] Expected size is 0x000004
extern undefined4 FBSet;
//[BSS] Expected size is 0x000004
extern undefined4 message$341;
void __VIRetraceHandler(undefined4 param_1,undefined4 param_2);
undefined4 VISetPreRetraceCallback(undefined4 param_1);
undefined4 VISetPostRetraceCallback(undefined4 param_1);
undefined * getTiming(undefined4 param_1);
void __VIInit(uint param_1);
void VIInit(void);
void VIWaitForRetrace(void);
void setFbbRegs(int param_1,uint *param_2,uint *param_3,uint *param_4,uint *param_5);
void setVerticalRegs(uint param_1,ushort param_2,ushort param_3,short param_4,short param_5,short param_6,short param_7,short param_8,int param_9);
void VIConfigure(uint *param_1);
void VIFlush(void);
void VISetNextFrameBuffer(undefined4 param_1);
void VISetBlack(undefined4 param_1);
undefined4 VIGetRetraceCount(void);
undefined4 getCurrentFieldEvenOdd(void);
ushort VIGetNextField(void);
uint VIGetCurrentLine(void);
undefined4 VIGetTvFormat(void);
ushort VIGetDTVStatus(void);
}
