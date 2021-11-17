#include <gx/GXFifo.h>
#include <os/OSThread.h>
#include <gx/GXFifo.h>
#include <os/OSContext.h>
#include <os/OSInterrupt.h>
#include <base/PPCArch.h>
#include <gx/GXMisc.h>


namespace gx {
undefined4 CPUFifo;
undefined4 GPFifo;
undefined4 __GXCurrentThread;
undefined1 CPGPLinked;
undefined4 GXOverflowSuspendInProgress;
undefined4 BreakPointCB;
undefined4 __GXOverflowCount;

void GXCPInterruptHandler(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined auStack720 [716];
  
  iVar1 = gx;
  *(uint *)(gx + 0xc) = (uint)*__cpReg;
  if (((*(uint *)(iVar1 + 8) >> 3 & 1) != 0) && ((*(uint *)(iVar1 + 0xc) >> 1 & 1) != 0)) {
    os::OSResumeThread(__GXCurrentThread);
    GXOverflowSuspendInProgress = 0;
    __GXWriteFifoIntReset(1,1);
    __GXWriteFifoIntEnable(1,0);
  }
  if (((*(uint *)(gx + 8) >> 2 & 1) != 0) && ((*(uint *)(gx + 0xc) & 1) != 0)) {
    __GXOverflowCount = __GXOverflowCount + 1;
    __GXWriteFifoIntEnable(0,1);
    __GXWriteFifoIntReset(1,0);
    GXOverflowSuspendInProgress = 1;
    os::OSSuspendThread(__GXCurrentThread);
  }
  iVar1 = gx;
  if (((*(uint *)(gx + 8) >> 5 & 1) != 0) && ((*(uint *)(gx + 0xc) >> 4 & 1) != 0)) {
    *(uint *)(gx + 8) = *(uint *)(gx + 8) & 0xffffffdf;
    __cpReg[1] = (ushort)*(undefined4 *)(iVar1 + 8);
    if (BreakPointCB != (code *)0x0) {
      os::OSClearContext(auStack720);
      os::OSSetCurrentContext(auStack720);
      (*BreakPointCB)();
      os::OSClearContext(auStack720);
      os::OSSetCurrentContext(param_2);
    }
  }
  return;
}


void GXInitFifoBase(int *param_1,int param_2,uint param_3)

{
  *param_1 = param_2;
  param_1[1] = param_2 + (param_3 - 4);
  param_1[2] = param_3;
  param_1[7] = 0;
  GXInitFifoLimits(param_1,param_3 - 0x4000,param_3 >> 1 & 0x7fffffe0);
  GXInitFifoPtrs(param_1,param_2,param_2);
  return;
}


void GXInitFifoPtrs(int param_1,int param_2,int param_3)

{
  os::OSDisableInterrupts();
  *(int *)(param_1 + 0x14) = param_2;
  *(int *)(param_1 + 0x18) = param_3;
  *(int *)(param_1 + 0x1c) = param_3 - param_2;
  if (*(int *)(param_1 + 0x1c) < 0) {
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 8);
  }
  os::OSRestoreInterrupts();
  return;
}


void GXInitFifoLimits(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x10) = param_3;
  return;
}


void GXSetCPUFifo(uint *param_1)

{
  undefined4 uVar1;
  
  uVar1 = os::OSDisableInterrupts();
  CPUFifo = param_1;
  if (param_1 == GPFifo) {
    *(uint *)(__piReg + 0xc) = *param_1 & 0x3fffffff;
    *(uint *)(__piReg + 0x10) = param_1[1] & 0x3fffffff;
    *(uint *)(__piReg + 0x14) = param_1[6] & 0x3bffffe0;
    CPGPLinked = '\x01';
    __GXWriteFifoIntReset(1,1);
    __GXWriteFifoIntEnable(1,0);
    __GXFifoLink(1);
  }
  else {
    if (CPGPLinked != '\0') {
      __GXFifoLink(0);
      CPGPLinked = '\0';
    }
    __GXWriteFifoIntEnable(0,0);
    *(uint *)(__piReg + 0xc) = *param_1 & 0x3fffffff;
    *(uint *)(__piReg + 0x10) = param_1[1] & 0x3fffffff;
    *(uint *)(__piReg + 0x14) = param_1[6] & 0x3bffffe0;
  }
  base::PPCSync();
  os::OSRestoreInterrupts(uVar1);
  return;
}


void GXSetGPFifo(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = os::OSDisableInterrupts();
  __GXFifoReadDisable();
  __GXWriteFifoIntEnable(0,0);
  GPFifo = param_1;
  *(short *)(__cpReg + 0x20) = (short)*param_1;
  *(short *)(__cpReg + 0x24) = (short)param_1[1];
  *(short *)(__cpReg + 0x30) = (short)param_1[7];
  *(short *)(__cpReg + 0x34) = (short)param_1[6];
  *(short *)(__cpReg + 0x38) = (short)param_1[5];
  *(short *)(__cpReg + 0x28) = (short)param_1[3];
  *(short *)(__cpReg + 0x2c) = (short)param_1[4];
  *(ushort *)(__cpReg + 0x22) = (ushort)((uint)*param_1 >> 0x10) & 0x3fff;
  *(ushort *)(__cpReg + 0x26) = (ushort)((uint)param_1[1] >> 0x10) & 0x3fff;
  *(short *)(__cpReg + 0x32) = (short)((uint)param_1[7] >> 0x10);
  *(ushort *)(__cpReg + 0x36) = (ushort)((uint)param_1[6] >> 0x10) & 0x3fff;
  *(ushort *)(__cpReg + 0x3a) = (ushort)((uint)param_1[5] >> 0x10) & 0x3fff;
  *(short *)(__cpReg + 0x2a) = (short)((uint)param_1[3] >> 0x10);
  *(short *)(__cpReg + 0x2e) = (short)((uint)param_1[4] >> 0x10);
  base::PPCSync();
  if (CPUFifo == GPFifo) {
    CPGPLinked = 1;
    __GXWriteFifoIntEnable(1,0);
    __GXFifoLink(1);
  }
  else {
    CPGPLinked = 0;
    __GXWriteFifoIntEnable(0,0);
    __GXFifoLink(0);
  }
  __GXWriteFifoIntReset(1,1);
  __GXFifoReadEnable();
  os::OSRestoreInterrupts(uVar1);
  return;
}


void GXSaveCPUFifo(void)

{
  __GXSaveCPUFifoAux();
  return;
}


void __GXSaveCPUFifoAux(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = os::OSDisableInterrupts();
  GXFlush();
  *param_1 = *(int *)(__piReg + 0xc) + -0x80000000;
  param_1[1] = *(int *)(__piReg + 0x10) + -0x80000000;
  param_1[6] = (*(uint *)(__piReg + 0x14) & 0xfbffffff) + 0x80000000;
  if (CPGPLinked == '\0') {
    param_1[7] = param_1[6] - param_1[5];
    if (param_1[7] < 0) {
      param_1[7] = param_1[7] + param_1[2];
    }
  }
  else {
    param_1[5] = CONCAT22(*(undefined2 *)(__cpReg + 0x3a),*(undefined2 *)(__cpReg + 0x38)) +
                 -0x80000000;
    param_1[7] = CONCAT22(*(undefined2 *)(__cpReg + 0x32),*(undefined2 *)(__cpReg + 0x30));
  }
  os::OSRestoreInterrupts(uVar1);
  return;
}


void GXGetGPStatus(byte *param_1,byte *param_2,byte *param_3,byte *param_4,byte *param_5)

{
  int iVar1;
  
  iVar1 = gx;
  *(uint *)(gx + 0xc) = (uint)*__cpReg;
  *param_1 = (byte)*(undefined4 *)(iVar1 + 0xc) & 1;
  *param_2 = (byte)(*(uint *)(iVar1 + 0xc) >> 1) & 1;
  *param_3 = (byte)(*(uint *)(iVar1 + 0xc) >> 2) & 1;
  *param_4 = (byte)(*(uint *)(iVar1 + 0xc) >> 3) & 1;
  *param_5 = (byte)(*(uint *)(iVar1 + 0xc) >> 4) & 1;
  return;
}


void __GXFifoInit(void)

{
  os::__OSSetInterruptHandler(0x11,GXCPInterruptHandler);
  os::__OSUnmaskInterrupts(0x4000);
  __GXCurrentThread = os::OSGetCurrentThread();
  CPUFifo = 0;
  GPFifo = 0;
  GXOverflowSuspendInProgress = 0;
  return;
}


void __GXFifoReadEnable(void)

{
  int iVar1;
  
  iVar1 = gx;
  *(uint *)(gx + 8) = *(uint *)(gx + 8) & 0xfffffffe | 1;
  *(short *)(__cpReg + 2) = (short)*(undefined4 *)(iVar1 + 8);
  return;
}


void __GXFifoReadDisable(void)

{
  int iVar1;
  
  iVar1 = gx;
  *(uint *)(gx + 8) = *(uint *)(gx + 8) & 0xfffffffe;
  *(short *)(__cpReg + 2) = (short)*(undefined4 *)(iVar1 + 8);
  return;
}


void __GXFifoLink(char param_1)

{
  int iVar1;
  
  iVar1 = gx;
  *(uint *)(gx + 8) = *(uint *)(gx + 8) & 0xffffffef | (uint)(param_1 != '\0') << 4;
  *(short *)(__cpReg + 2) = (short)*(undefined4 *)(iVar1 + 8);
  return;
}


void __GXWriteFifoIntEnable(uint param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = gx;
  *(uint *)(gx + 8) = *(uint *)(gx + 8) & 0xfffffffb | (param_1 & 0xff) << 2;
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & 0xfffffff7 | (param_2 & 0xff) << 3;
  *(short *)(__cpReg + 2) = (short)*(undefined4 *)(iVar1 + 8);
  return;
}


void __GXWriteFifoIntReset(uint param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = gx;
  *(uint *)(gx + 0x10) = *(uint *)(gx + 0x10) & 0xfffffffe | param_1 & 0xff;
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xfffffffd | (param_2 & 0xff) << 1;
  *(short *)(__cpReg + 4) = (short)*(undefined4 *)(iVar1 + 0x10);
  return;
}


/* WARNING: Removing unreachable block (ram,0x803213c0) */

void __GXCleanGPFifo(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 auStack156 [2];
  undefined4 local_94 [5];
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  
  puVar2 = (undefined4 *)GXGetGPFifo();
  if (puVar2 != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)GXGetCPUFifo();
    uVar6 = *puVar2;
    iVar7 = 0x10;
    puVar4 = puVar2 + -2;
    puVar5 = auStack156;
    do {
      uVar1 = puVar4[3];
      puVar5[2] = puVar4[2];
      puVar5[3] = uVar1;
      iVar7 = iVar7 + -1;
      puVar4 = puVar4 + 2;
      puVar5 = puVar5 + 2;
    } while (iVar7 != 0);
    os::OSDisableInterrupts();
    local_78 = 0;
    local_80 = uVar6;
    local_7c = uVar6;
    os::OSRestoreInterrupts();
    GXSetGPFifo(local_94);
    if (puVar3 == puVar2) {
      GXSetCPUFifo(local_94);
    }
    os::OSDisableInterrupts();
    puVar2[5] = uVar6;
    puVar2[6] = uVar6;
    puVar2[7] = 0;
    if ((int)puVar2[7] < 0) {
      puVar2[7] = puVar2[7] + puVar2[2];
    }
    os::OSRestoreInterrupts();
    GXSetGPFifo(puVar2);
    if (puVar3 == puVar2) {
      GXSetCPUFifo(puVar3);
    }
  }
  return;
}


undefined4 GXSetCurrentGXThread(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = os::OSDisableInterrupts();
  uVar1 = __GXCurrentThread;
  __GXCurrentThread = os::OSGetCurrentThread();
  os::OSRestoreInterrupts(uVar2);
  return uVar1;
}


undefined4 GXGetCurrentGXThread(void)

{
  return __GXCurrentThread;
}


undefined4 GXGetCPUFifo(void)

{
  return CPUFifo;
}


undefined4 GXGetGPFifo(void)

{
  return GPFifo;
}

