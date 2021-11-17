#include <os/OSReset.h>
#include <os/OSInterrupt.h>
#include <os/OSCache.h>
#include <os/OSReset.h>
#include <os/OSThread.h>
#include <os/OSAudioSystem.h>
#include <pad/Pad.h>
#include <os/OSRtc.h>
#include <os/OSReboot.h>


namespace os {
undefined4 ResetFunctionQueue;

void OSRegisterResetFunction(int param_1)

{
  int iVar1;
  int iVar2;
  
  for (iVar2 = ResetFunctionQueue; (iVar2 != 0 && (*(uint *)(iVar2 + 4) <= *(uint *)(param_1 + 4)));
      iVar2 = *(int *)(iVar2 + 8)) {
  }
  if (iVar2 != 0) {
    *(int *)(param_1 + 8) = iVar2;
    iVar1 = *(int *)(iVar2 + 0xc);
    *(int *)(iVar2 + 0xc) = param_1;
    *(int *)(param_1 + 0xc) = iVar1;
    if (iVar1 != 0) {
      *(int *)(iVar1 + 8) = param_1;
      return;
    }
    ResetFunctionQueue = param_1;
    return;
  }
  iVar2 = param_1;
  if (iRam803f7a0c != 0) {
    *(int *)(iRam803f7a0c + 8) = param_1;
    iVar2 = ResetFunctionQueue;
  }
  ResetFunctionQueue = iVar2;
  *(int *)(param_1 + 0xc) = iRam803f7a0c;
  *(undefined4 *)(param_1 + 8) = 0;
  iRam803f7a0c = param_1;
  return;
}


/* WARNING: Removing unreachable block (ram,0x803066d0) */
/* WARNING: Removing unreachable block (ram,0x803066fc) */

void Reset(void)

{
  instructionSynchronize();
  sync(0);
  do {
  } while( true );
}


void __OSDoHotReset(int param_1)

{
  OSDisableInterrupts();
  DAT_cc002002 = 0;
  ICFlashInvalidate();
  Reset(param_1 << 3);
  return;
}


void OSResetSystem(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  code **ppcVar6;
  undefined4 unaff_r31;
  
  OSDisableScheduler();
  __OSStopAudioSystem();
  if (param_1 == 2) {
    unaff_r31 = pad::__PADDisableRecalibration(1);
  }
  do {
    uVar5 = 0;
    for (ppcVar6 = ResetFunctionQueue; ppcVar6 != (code **)0x0; ppcVar6 = (code **)ppcVar6[2]) {
      uVar3 = (**ppcVar6)(0);
      uVar2 = countLeadingZeros(uVar3);
      uVar5 = uVar5 | uVar2 >> 5;
    }
    uVar3 = __OSSyncSram();
    uVar2 = countLeadingZeros(uVar3);
  } while ((uVar5 | uVar2 >> 5) != 0);
  if ((param_1 == 1) && (param_3 != 0)) {
    iVar4 = __OSLockSram();
    *(byte *)(iVar4 + 0x13) = *(byte *)(iVar4 + 0x13) | 0x40;
    __OSUnlockSram(1);
    do {
      iVar4 = __OSSyncSram();
    } while (iVar4 == 0);
  }
  OSDisableInterrupts();
  for (ppcVar6 = ResetFunctionQueue; ppcVar6 != (code **)0x0; ppcVar6 = (code **)ppcVar6[2]) {
    uVar3 = (**ppcVar6)(1);
    countLeadingZeros(uVar3);
  }
  __OSSyncSram();
  LCDisable();
  if (param_1 == 1) {
    OSDisableInterrupts();
    DAT_cc002002 = 0;
    ICFlashInvalidate();
    Reset(param_2 << 3);
    iVar4 = DAT_800000dc;
  }
  else {
    iVar4 = DAT_800000dc;
    if (param_1 == 0) {
      while (iVar4 != 0) {
        uVar1 = *(ushort *)(iVar4 + 0x2c8);
        iVar4 = *(int *)(iVar4 + 0x2fc);
        if ((uVar1 == 4) || ((uVar1 < 4 && (uVar1 == 1)))) {
          OSCancelThread();
        }
      }
      OSEnableScheduler();
      __OSReboot(param_2,param_3);
      iVar4 = DAT_800000dc;
    }
  }
  while (iVar4 != 0) {
    uVar1 = *(ushort *)(iVar4 + 0x2c8);
    iVar4 = *(int *)(iVar4 + 0x2fc);
    if ((uVar1 == 4) || ((uVar1 < 4 && (uVar1 == 1)))) {
      OSCancelThread();
    }
  }
  FUN_800033a8((int)&DAT_80000040,0,0x8c);
  FUN_800033a8((int)&DAT_800000d4,0,0x14);
  FUN_800033a8((int)&DAT_800000f4,0,4);
  FUN_800033a8((int)&DAT_80003000,0,0xc0);
  FUN_800033a8((int)&DAT_800030c8,0,0xc);
  FUN_800033a8((int)&DAT_800030e2,0,1);
  pad::__PADDisableRecalibration(unaff_r31);
  return;
}


uint OSGetResetCode(void)

{
  uint uVar1;
  
  if (DAT_800030e2 == '\0') {
    uVar1 = DAT_cc003024 >> 3;
  }
  else {
    uVar1 = 0x80000000;
  }
  return uVar1;
}

