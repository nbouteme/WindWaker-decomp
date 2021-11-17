#include <gx/GXMisc.h>
#include <gx/GXGeometry.h>
#include <base/PPCArch.h>
#include <os/OSTime.h>
#include <gx/GXFifo.h>
#include <os/OSInterrupt.h>
#include <gx/GXMisc.h>
#include <os/OSThread.h>
#include <os/OSContext.h>


namespace gx {
undefined4 TokenCB;
undefined4 DrawDoneCB;
undefined1 DrawDone;
undefined FinishQueue;

void GXSetMisc(int param_1,int param_2)

{
  undefined2 *puVar1;
  uint uVar2;
  
  puVar1 = gx;
  if (param_1 == 1) {
    gx[2] = (short)param_2;
    uVar2 = countLeadingZeros((uint)(ushort)puVar1[2]);
    *puVar1 = (short)(uVar2 >> 5);
    puVar1[1] = 1;
    if (puVar1[2] == 0) {
      return;
    }
    *(uint *)(puVar1 + 0x27a) = *(uint *)(puVar1 + 0x27a) | 8;
    return;
  }
  if (param_1 < 1) {
    return;
  }
  if (2 < param_1) {
    return;
  }
  *(char *)((int)gx + 0x4f1) = '\x01' - (param_2 == 0);
  return;
}


void GXFlush(void)

{
  if (*(int *)(gx + 0x4f4) != 0) {
    __GXSetDirtyState();
  }
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  base::PPCSync();
  return;
}


void GXAbortFrame(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  DAT_cc003018 = 1;
  iVar1 = os::OSGetTime();
  uVar3 = param_2;
  do {
    iVar2 = os::OSGetTime();
    bVar5 = uVar3 < param_2;
    uVar3 = uVar3 - param_2;
  } while ((uint)(0x32 < uVar3) + (iVar2 - ((uint)bVar5 + iVar1) ^ 0x80000000) < 0x80000001);
  DAT_cc003018 = 0;
  iVar1 = os::OSGetTime();
  uVar4 = uVar3;
  do {
    iVar2 = os::OSGetTime();
    bVar5 = uVar4 < uVar3;
    uVar4 = uVar4 - uVar3;
  } while ((uint)(5 < uVar4) + (iVar2 - ((uint)bVar5 + iVar1) ^ 0x80000000) < 0x80000001);
  __GXCleanGPFifo();
  return;
}


void GXSetDrawSync(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = os::OSDisableInterrupts();
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,param_1 & 0xffff | 0x48000000);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,param_1 & 0xffff | 0x47000000);
  if (*(int *)(gx + 0x4f4) != 0) {
    __GXSetDirtyState();
  }
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  base::PPCSync();
  os::OSRestoreInterrupts(uVar1);
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXSetDrawDone(void)

{
  undefined4 uVar1;
  
  uVar1 = os::OSDisableInterrupts();
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,0x45000002);
  if (*(int *)(gx + 0x4f4) != 0) {
    __GXSetDirtyState();
  }
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  base::PPCSync();
  DrawDone = 0;
  os::OSRestoreInterrupts(uVar1);
  return;
}


void GXDrawDone(void)

{
  undefined4 uVar1;
  
  uVar1 = os::OSDisableInterrupts();
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,0x45000002);
  GXFlush();
  DrawDone = '\0';
  os::OSRestoreInterrupts(uVar1);
  uVar1 = os::OSDisableInterrupts();
  while (DrawDone == '\0') {
    os::OSSleepThread(&FinishQueue);
  }
  os::OSRestoreInterrupts(uVar1);
  return;
}


void GXPixModeSync(void)

{
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x1dc));
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXPokeAlphaMode(int param_1,ushort param_2)

{
  *(ushort *)(__peReg + 6) = (ushort)(param_1 << 8) | param_2 & 0xff;
  return;
}


void GXPokeAlphaRead(ushort param_1)

{
  *(ushort *)(__peReg + 8) = param_1 & 0xfffb | 4;
  return;
}


void GXPokeAlphaUpdate(int param_1)

{
  *(ushort *)(__peReg + 2) = *(ushort *)(__peReg + 2) & 0xffef | (ushort)(param_1 << 4) & 0xff0;
  return;
}


void GXPokeBlendMode(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  ushort uVar3;
  
  uVar3 = 1;
  if ((param_1 != 1) && (param_1 != 3)) {
    uVar3 = 0;
  }
  iVar2 = countLeadingZeros(3 - param_1);
  uVar1 = countLeadingZeros(2 - param_1);
  *(ushort *)(__peReg + 2) =
       (*(ushort *)(__peReg + 2) & 0xf7fc | uVar3 | (ushort)(iVar2 << 6) & 0xf800 |
       (ushort)(uVar1 >> 4) & 0xfffe) & 0x81f | (ushort)(param_4 << 0xc) | (ushort)(param_2 << 8) |
       (ushort)(param_3 << 5);
  return;
}


void GXPokeColorUpdate(int param_1)

{
  *(ushort *)(__peReg + 2) = *(ushort *)(__peReg + 2) & 0xfff7 | (ushort)(param_1 << 3) & 0x7f8;
  return;
}


void GXPokeDstAlpha(int param_1,ushort param_2)

{
  *(ushort *)(__peReg + 4) = param_2 & 0xff | (ushort)(param_1 << 8);
  return;
}


void GXPokeDither(int param_1)

{
  *(ushort *)(__peReg + 2) = *(ushort *)(__peReg + 2) & 0xfffb | (ushort)(param_1 << 2) & 0x3fc;
  return;
}


void GXPokeZMode(ushort param_1,int param_2,int param_3)

{
  *__peReg = (param_1 & 0xf1 | (ushort)(param_2 << 1)) & 0xffef | (ushort)(param_3 << 4) & 0xff0;
  return;
}


void GXPeekARGB(uint param_1,uint param_2,undefined4 *param_3)

{
  *param_3 = *(undefined4 *)((param_1 & 0x3ff) << 2 | 0xc8000000 | (param_2 & 0xf3ff) << 0xc);
  return;
}


void GXPeekZ(uint param_1,uint param_2,undefined4 *param_3)

{
  *param_3 = *(undefined4 *)
              ((param_1 & 0x3ff) << 2 | 0xc8000000 | (param_2 & 0xf3ff) << 0xc | 0x400000);
  return;
}


undefined4 GXSetDrawSyncCallback(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = TokenCB;
  os::OSDisableInterrupts();
  TokenCB = param_1;
  os::OSRestoreInterrupts();
  return uVar1;
}


void GXTokenInterruptHandler(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined auStack720 [712];
  
  uVar1 = *(undefined2 *)(__peReg + 0xe);
  if (TokenCB != (code *)0x0) {
    os::OSClearContext(auStack720);
    os::OSSetCurrentContext(auStack720);
    (*TokenCB)(uVar1);
    os::OSClearContext(auStack720);
    os::OSSetCurrentContext(param_2);
  }
  *(ushort *)(__peReg + 10) = *(ushort *)(__peReg + 10) & 0xfffb | 4;
  return;
}


undefined4 GXSetDrawDoneCallback(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = DrawDoneCB;
  os::OSDisableInterrupts();
  DrawDoneCB = param_1;
  os::OSRestoreInterrupts();
  return uVar1;
}


void GXFinishInterruptHandler(undefined4 param_1,undefined4 param_2)

{
  undefined auStack720 [716];
  
  *(ushort *)(__peReg + 10) = *(ushort *)(__peReg + 10) & 0xfff7 | 8;
  DrawDone = 1;
  if (DrawDoneCB != (code *)0x0) {
    os::OSClearContext(auStack720);
    os::OSSetCurrentContext(auStack720);
    (*DrawDoneCB)();
    os::OSClearContext(auStack720);
    os::OSSetCurrentContext(param_2);
  }
  os::OSWakeupThread(&FinishQueue);
  return;
}


void __GXPEInit(void)

{
  os::__OSSetInterruptHandler(0x12,GXTokenInterruptHandler);
  os::__OSSetInterruptHandler(0x13,GXFinishInterruptHandler);
  os::OSInitThreadQueue(&FinishQueue);
  os::__OSUnmaskInterrupts(0x2000);
  os::__OSUnmaskInterrupts(0x1000);
  *(ushort *)(__peReg + 10) = *(ushort *)(__peReg + 10) & 0xfff0 | 0xf;
  return;
}

