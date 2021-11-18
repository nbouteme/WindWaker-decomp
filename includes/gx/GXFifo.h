#pragma once
#include <ctypes.h>



namespace gx {
//[BSS] Expected size is 0x000004
extern undefined4 CPUFifo;
//[BSS] Expected size is 0x000004
extern undefined4 GPFifo;
//[BSS] Expected size is 0x000004
extern undefined4 __GXCurrentThread;
//[BSS] Expected size is 0x000001
extern undefined1 CPGPLinked;
//[BSS] Expected size is 0x000004
extern undefined4 GXOverflowSuspendInProgress;
//[BSS] Expected size is 0x000004
extern undefined4 BreakPointCB;
//[BSS] Expected size is 0x000004
extern undefined4 __GXOverflowCount;
void GXCPInterruptHandler(undefined4 param_1,undefined4 param_2);
void GXInitFifoBase(int *param_1,int param_2,uint param_3);
void GXInitFifoPtrs(int param_1,int param_2,int param_3);
void GXInitFifoLimits(int param_1,undefined4 param_2,undefined4 param_3);
void GXSetCPUFifo(uint *param_1);
void GXSetGPFifo(undefined4 *param_1);
void GXSaveCPUFifo(void);
void __GXSaveCPUFifoAux(int *param_1);
void GXGetGPStatus(byte *param_1,byte *param_2,byte *param_3,byte *param_4,byte *param_5);
void __GXFifoInit(void);
void __GXFifoReadEnable(void);
void __GXFifoReadDisable(void);
void __GXFifoLink(char param_1);
void __GXWriteFifoIntEnable(uint param_1,uint param_2);
void __GXWriteFifoIntReset(uint param_1,uint param_2);
void __GXCleanGPFifo(void);
undefined4 GXSetCurrentGXThread(void);
undefined4 GXGetCurrentGXThread(void);
undefined4 GXGetCPUFifo(void);
undefined4 GXGetGPFifo(void);
}
