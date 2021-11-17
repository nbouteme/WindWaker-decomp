#pragma once
#include <ctypes.h>



namespace vi {
//Expected size is 0x000076
extern undefined2 regs;

//Expected size is 0x000076
extern undefined shdwRegs;

//Expected size is 0x000058
extern undefined2 HorVer;

//Expected size is 0x000004
extern undefined4 IsInitialized;

//Expected size is 0x000004
extern undefined4 retraceCount;

//Expected size is 0x000004
extern undefined4 flushFlag;

//Expected size is 0x000008
extern undefined retraceQueue;

//Expected size is 0x000004
extern undefined4 PreCB;

//Expected size is 0x000004
extern undefined4 PostCB;

//Expected size is 0x000004
extern undefined4 encoderType;

//Expected size is 0x000002
extern undefined2 displayOffsetH;

//Expected size is 0x000002
extern undefined2 displayOffsetV;

//Expected size is 0x000004
extern undefined4 changeMode;

//Expected size is 0x000008
extern undefined4 changed;

//Expected size is 0x000004
extern undefined4 shdwChangeMode;

//Expected size is 0x000008
extern undefined4 shdwChanged;

//Expected size is 0x000004
extern undefined4 CurrTiming;

//Expected size is 0x000004
extern undefined4 CurrTvMode;

//Expected size is 0x000004
extern undefined4 NextBufAddr;

//Expected size is 0x000004
extern undefined4 CurrBufAddr;

//Expected size is 0x000004
extern undefined4 FBSet;

//Expected size is 0x000004
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
