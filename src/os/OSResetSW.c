#include <os/OSResetSW.h>
#include <os/OSTime.h>
#include <os/OSInterrupt.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <os/OSResetSW.h>


namespace os {
undefined4 ResetCallback;
undefined4 Down;
undefined4 LastState;
undefined4 HoldUp;
undefined4 HoldDown;

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __OSResetSWInterruptHandler(void)

{
  uint uVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  _HoldDown = __OSGetSystemTime();
  uVar1 = DAT_800000f8 >> 2;
  do {
    uVar3 = __OSGetSystemTime();
    if (((uint)uVar3 - DAT_803f7a2c < (uVar1 / 0x1e848) * 100 >> 3) + 0x80000000 <=
        ((int)((ulonglong)uVar3 >> 0x20) - ((uint)((uint)uVar3 < DAT_803f7a2c) + HoldDown) ^
        0x80000000)) break;
  } while ((DAT_cc003000 & 0x10000) == 0);
  if ((DAT_cc003000 & 0x10000) == 0) {
    Down = 1;
    LastState = 1;
    __OSMaskInterrupts(0x200);
    pcVar2 = ResetCallback;
    if (ResetCallback != (code *)0x0) {
      ResetCallback = (code *)0x0;
      (*pcVar2)();
    }
  }
  HoldDown = (int)((ulonglong)_HoldDown >> 0x20);
  DAT_cc003000 = 2;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint OSGetResetButtonState(void)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint extraout_r4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  
  uVar2 = OSDisableInterrupts();
  _HoldUp = __OSGetSystemTime();
  uVar3 = (uint)((ulonglong)_HoldUp >> 0x20);
  uVar4 = (uint)_HoldUp;
  if ((DAT_cc003000 & 0x10000) == 0) {
    if (Down == 0) {
      Down = 1;
      uVar8 = (uint)((DAT_803f7a24 | HoldUp) != 0);
      _HoldDown = _HoldUp;
      _HoldUp = CONCAT44(HoldUp,DAT_803f7a24);
    }
    else {
      bVar1 = 1;
      if (((DAT_803f7a24 | HoldUp) == 0) &&
         ((uint)(((DAT_800000f8 >> 2) / 0x1e848) * 100 >> 3 < uVar4 - DAT_803f7a2c) +
          (uVar3 - ((uint)(uVar4 < DAT_803f7a2c) + HoldDown) ^ 0x80000000) < 0x80000001)) {
        bVar1 = 0;
      }
      uVar8 = (uint)bVar1;
      _HoldDown = CONCAT44(HoldDown,DAT_803f7a2c);
      _HoldUp = CONCAT44(HoldUp,DAT_803f7a24);
    }
  }
  else {
    if (Down == 0) {
      if (((DAT_803f7a24 | HoldUp) == 0) ||
         ((uVar4 - DAT_803f7a24 < ((DAT_800000f8 >> 2) / 1000) * 0x28) + 0x80000000 <=
          (uVar3 - ((uVar4 < DAT_803f7a24) + HoldUp) ^ 0x80000000))) {
        _HoldUp = 0;
        uVar8 = 0;
        _HoldDown = CONCAT44(HoldDown,DAT_803f7a2c);
      }
      else {
        uVar8 = 1;
        _HoldDown = CONCAT44(HoldDown,DAT_803f7a2c);
        _HoldUp = CONCAT44(HoldUp,DAT_803f7a24);
      }
    }
    else {
      Down = 0;
      uVar8 = LastState;
      if (LastState == 0) {
        _HoldDown = CONCAT44(HoldDown,DAT_803f7a2c);
        _HoldUp = 0;
      }
    }
  }
  LastState = uVar8;
  if ((DAT_800030e3 & 0x3f) != 0) {
    uVar7 = (DAT_800030e3 & 0x3f) * 0x3c;
    uVar5 = uVar7 * (DAT_800000f8 >> 2);
    uVar6 = DAT_803f79bc + uVar5;
    uVar5 = __OSStartTime +
            (int)((ulonglong)uVar7 * (ulonglong)(DAT_800000f8 >> 2) >> 0x20) +
            (uint)CARRY4(DAT_803f79bc,uVar5);
    if ((uVar5 ^ 0x80000000) < (uint)(uVar6 < uVar4) + (uVar3 ^ 0x80000000)) {
      uVar9 = Runtime.PPCEABI.H::__div2i(uVar3 - ((uVar4 < uVar6) + uVar5),uVar4 - uVar6,0);
      Runtime.PPCEABI.H::__div2i((int)((ulonglong)uVar9 >> 0x20),(int)uVar9,0,2);
      if ((extraout_r4 & 1) == 0) {
        uVar8 = 1;
      }
      else {
        uVar8 = 0;
      }
    }
  }
  OSRestoreInterrupts(uVar2);
  return uVar8;
}


void OSGetResetSwitchState(void)

{
  OSGetResetButtonState();
  return;
}

