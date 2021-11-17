#include <os/OSRtc.h>
#include <os/OSRtc.h>
#include <exi/EXIBios.h>
#include <os/OSCache.h>
#include <os/OSInterrupt.h>


namespace os {
undefined2 Scb;

void WriteSramCallback(void)

{
  DAT_803f02ac = WriteSram((int)&Scb + DAT_803f02a0,DAT_803f02a0,0x40 - DAT_803f02a0);
  if (DAT_803f02ac != 0) {
    DAT_803f02a0 = 0x40;
  }
  return;
}


uint WriteSram(undefined4 param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint local_14 [2];
  
  iVar4 = exi::EXILock(0,1,WriteSramCallback);
  if (iVar4 == 0) {
    uVar5 = 0;
  }
  else {
    iVar4 = exi::EXISelect(0,1,3);
    if (iVar4 == 0) {
      exi::EXIUnlock(0);
      uVar5 = 0;
    }
    else {
      local_14[0] = param_2 * 0x40 + 0x100U | 0xa0000000;
      uVar6 = exi::EXIImm(0,local_14,4,1,0);
      uVar5 = countLeadingZeros(uVar6);
      uVar6 = exi::EXISync(0);
      uVar1 = countLeadingZeros(uVar6);
      uVar6 = exi::EXIImmEx(0,param_1,param_3,1);
      uVar2 = countLeadingZeros(uVar6);
      uVar6 = exi::EXIDeselect(0);
      uVar3 = countLeadingZeros(uVar6);
      exi::EXIUnlock(0);
      uVar5 = countLeadingZeros((uVar5 | uVar1 | uVar2 | uVar3) >> 5);
      uVar5 = uVar5 >> 5;
    }
  }
  return uVar5;
}


void __OSInitSram(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 local_10 [2];
  
  uVar7 = 0;
  DAT_803f02a4 = 0;
  DAT_803f02a8 = 0;
  DCInvalidateRange(&Scb,0x40);
  iVar5 = exi::EXILock(0,1,0);
  if (iVar5 != 0) {
    iVar5 = exi::EXISelect(0,1,3);
    if (iVar5 == 0) {
      exi::EXIUnlock(0);
    }
    else {
      local_10[0] = 0x20000100;
      uVar6 = exi::EXIImm(0,local_10,4,1,0);
      uVar7 = countLeadingZeros(uVar6);
      uVar6 = exi::EXISync(0);
      uVar1 = countLeadingZeros(uVar6);
      uVar6 = exi::EXIDma(0,&Scb,0x40,0,0);
      uVar2 = countLeadingZeros(uVar6);
      uVar6 = exi::EXISync(0);
      uVar3 = countLeadingZeros(uVar6);
      uVar6 = exi::EXIDeselect(0);
      uVar4 = countLeadingZeros(uVar6);
      exi::EXIUnlock(0);
      uVar7 = countLeadingZeros((uVar7 | uVar1 | uVar2 | uVar3 | uVar4) >> 5);
      uVar7 = uVar7 >> 5;
    }
  }
  DAT_803f02a0 = 0x40;
  DAT_803f02ac = uVar7;
  return;
}


undefined2 * __OSLockSram(void)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  
  puVar2 = &Scb;
  uVar1 = OSDisableInterrupts();
  if (DAT_803f02a8 == 0) {
    DAT_803f02a8 = 1;
    DAT_803f02a4 = uVar1;
  }
  else {
    OSRestoreInterrupts();
    puVar2 = (undefined2 *)0x0;
  }
  return puVar2;
}


undefined2 * __OSLockSramEx(void)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  
  uVar1 = OSDisableInterrupts();
  if (DAT_803f02a8 == 0) {
    puVar2 = &DAT_803f0274;
    DAT_803f02a8 = 1;
    DAT_803f02a4 = uVar1;
  }
  else {
    OSRestoreInterrupts();
    puVar2 = (undefined2 *)0x0;
  }
  return puVar2;
}


/* WARNING: Removing unreachable block (ram,0x8030717c) */
/* WARNING: Removing unreachable block (ram,0x803072a4) */

uint UnlockSram(int param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  ushort *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint local_20 [3];
  
  if (param_1 != 0) {
    if (param_2 == 0) {
      if (2 < (DAT_803f0273 & 3)) {
        DAT_803f0273 = DAT_803f0273 & 0xfc;
      }
      DAT_803f0262 = 0;
      Scb = 0;
      puVar7 = &DAT_803f026c;
      iVar10 = 4;
      do {
        Scb = Scb + *puVar7;
        uVar1 = *puVar7;
        puVar7 = puVar7 + 1;
        DAT_803f0262 = DAT_803f0262 + ~uVar1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    if (param_2 < DAT_803f02a0) {
      DAT_803f02a0 = param_2;
    }
    uVar2 = DAT_803f02a0;
    iVar8 = 0x40 - DAT_803f02a0;
    iVar9 = (int)&Scb + DAT_803f02a0;
    iVar10 = exi::EXILock(0,1,WriteSramCallback);
    if (iVar10 == 0) {
      DAT_803f02ac = 0;
    }
    else {
      iVar10 = exi::EXISelect(0,1,3);
      if (iVar10 == 0) {
        exi::EXIUnlock(0);
        DAT_803f02ac = 0;
      }
      else {
        local_20[0] = uVar2 * 0x40 + 0x100 | 0xa0000000;
        uVar6 = exi::EXIImm(0,local_20,4,1,0);
        uVar2 = countLeadingZeros(uVar6);
        uVar6 = exi::EXISync(0);
        uVar3 = countLeadingZeros(uVar6);
        uVar6 = exi::EXIImmEx(0,iVar9,iVar8,1);
        uVar4 = countLeadingZeros(uVar6);
        uVar6 = exi::EXIDeselect(0);
        uVar5 = countLeadingZeros(uVar6);
        exi::EXIUnlock(0);
        uVar2 = countLeadingZeros((uVar2 | uVar3 | uVar4 | uVar5) >> 5);
        DAT_803f02ac = uVar2 >> 5;
      }
    }
    if (DAT_803f02ac != 0) {
      DAT_803f02a0 = 0x40;
    }
  }
  DAT_803f02a8 = 0;
  OSRestoreInterrupts(DAT_803f02a4);
  return DAT_803f02ac;
}


void __OSUnlockSram(undefined4 param_1)

{
  UnlockSram(param_1,0);
  return;
}


void __OSUnlockSramEx(undefined4 param_1)

{
  UnlockSram(param_1,0x14);
  return;
}


undefined4 __OSSyncSram(void)

{
  return DAT_803f02ac;
}


bool OSGetSoundMode(void)

{
  byte bVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  
  puVar3 = &Scb;
  uVar2 = OSDisableInterrupts();
  if (DAT_803f02a8 == 0) {
    DAT_803f02a8 = 1;
    DAT_803f02a4 = uVar2;
  }
  else {
    OSRestoreInterrupts();
    puVar3 = (undefined2 *)0x0;
  }
  bVar1 = *(byte *)((int)puVar3 + 0x13);
  UnlockSram(0,0);
  return (bVar1 & 4) != 0;
}


void OSSetSoundMode(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined2 *puVar3;
  
  puVar3 = &Scb;
  uVar2 = (param_1 & 1) << 2;
  uVar1 = OSDisableInterrupts();
  if (DAT_803f02a8 == 0) {
    DAT_803f02a8 = 1;
    DAT_803f02a4 = uVar1;
  }
  else {
    OSRestoreInterrupts();
    puVar3 = (undefined2 *)0x0;
  }
  if (uVar2 == (*(byte *)((int)puVar3 + 0x13) & 4)) {
    UnlockSram(0,0);
  }
  else {
    *(byte *)((int)puVar3 + 0x13) = *(byte *)((int)puVar3 + 0x13) & 0xfb;
    *(byte *)((int)puVar3 + 0x13) = *(byte *)((int)puVar3 + 0x13) | (byte)uVar2;
    UnlockSram(1,0);
  }
  return;
}


byte OSGetProgressiveMode(void)

{
  byte bVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  
  puVar3 = &Scb;
  uVar2 = OSDisableInterrupts();
  if (DAT_803f02a8 == 0) {
    DAT_803f02a8 = 1;
    DAT_803f02a4 = uVar2;
  }
  else {
    OSRestoreInterrupts();
    puVar3 = (undefined2 *)0x0;
  }
  bVar1 = *(byte *)((int)puVar3 + 0x13);
  UnlockSram(0,0);
  return bVar1 >> 7;
}


void OSSetProgressiveMode(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined2 *puVar3;
  
  puVar3 = &Scb;
  uVar2 = (param_1 & 1) << 7;
  uVar1 = OSDisableInterrupts();
  if (DAT_803f02a8 == 0) {
    DAT_803f02a8 = 1;
    DAT_803f02a4 = uVar1;
  }
  else {
    OSRestoreInterrupts();
    puVar3 = (undefined2 *)0x0;
  }
  if (uVar2 == (*(byte *)((int)puVar3 + 0x13) & 0x80)) {
    UnlockSram(0,0);
  }
  else {
    *(byte *)((int)puVar3 + 0x13) = *(byte *)((int)puVar3 + 0x13) & 0x7f;
    *(byte *)((int)puVar3 + 0x13) = *(byte *)((int)puVar3 + 0x13) | (byte)uVar2;
    UnlockSram(1,0);
  }
  return;
}


undefined2 OSGetWirelessID(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  
  uVar2 = OSDisableInterrupts();
  if (DAT_803f02a8 == 0) {
    puVar3 = &DAT_803f0274;
    DAT_803f02a8 = 1;
    DAT_803f02a4 = uVar2;
  }
  else {
    OSRestoreInterrupts();
    puVar3 = (undefined2 *)0x0;
  }
  uVar1 = puVar3[param_1 + 0xe];
  UnlockSram(0,0x14);
  return uVar1;
}


void OSSetWirelessID(int param_1,short param_2)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  
  uVar1 = OSDisableInterrupts();
  if (DAT_803f02a8 == 0) {
    puVar2 = &DAT_803f0274;
    DAT_803f02a8 = 1;
    DAT_803f02a4 = uVar1;
  }
  else {
    OSRestoreInterrupts();
    puVar2 = (undefined2 *)0x0;
  }
  if (puVar2[param_1 + 0xe] == param_2) {
    UnlockSram(0,0x14);
  }
  else {
    puVar2[param_1 + 0xe] = param_2;
    UnlockSram(1,0x14);
  }
  return;
}

