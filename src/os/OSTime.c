#include <os/OSTime.h>
#include <os/OSTime.h>
#include <os/OSInterrupt.h>
#include <Runtime.PPCEABI.H/runtime.h>


namespace os {

int OSGetTime(void)

{
  int in_TBUr;
  
  return in_TBUr;
}


void OSGetTick(void)

{
  return;
}


undefined8 __OSGetSystemTime(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = OSDisableInterrupts();
  uVar2 = (uint)uVar4;
  iVar1 = OSGetTime();
  iVar3 = DAT_800030dc + uVar2;
  iVar1 = DAT_800030d8 + iVar1 + (uint)CARRY4(DAT_800030dc,uVar2);
  OSRestoreInterrupts((int)((ulonglong)uVar4 >> 0x20));
  return CONCAT44(iVar1,iVar3);
}


undefined8 __OSTimeToSystemTime(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  OSDisableInterrupts();
  iVar1 = DAT_800030dc + param_2;
  iVar2 = DAT_800030d8 + param_1 + (uint)CARRY4(DAT_800030dc,param_2);
  OSRestoreInterrupts();
  return CONCAT44(iVar2,iVar1);
}


void GetDates(int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined *puVar7;
  int iVar8;
  
  iVar8 = param_1 + 6;
  iVar5 = iVar8 / 7 + (iVar8 >> 0x1f);
  iVar3 = param_1 / 0x16d + (param_1 >> 0x1f);
  uVar6 = iVar3 - (iVar3 >> 0x1f);
  iVar3 = uVar6 * 0x16d;
  *(int *)(param_2 + 0x18) = iVar8 + (iVar5 - (iVar5 >> 0x1f)) * -7;
  while( true ) {
    if ((int)uVar6 < 1) {
      iVar5 = 0;
    }
    else {
      iVar5 = uVar6 - 1;
      iVar8 = iVar5 / 400 + (iVar5 >> 0x1f);
      iVar5 = iVar5 / 100 + (iVar5 >> 0x1f);
      uVar4 = uVar6 + 3;
      iVar5 = (iVar8 - (iVar8 >> 0x1f)) +
              ((((int)uVar4 >> 2) + (uint)((int)uVar4 < 0 && (uVar4 & 3) != 0)) -
              (iVar5 - (iVar5 >> 0x1f)));
    }
    if (iVar3 + iVar5 <= param_1) break;
    iVar3 = iVar3 + -0x16d;
    uVar6 = uVar6 - 1;
  }
  *(uint *)(param_2 + 0x14) = uVar6;
  param_1 = param_1 - (iVar3 + iVar5);
  *(int *)(param_2 + 0x1c) = param_1;
  bVar2 = true;
  bVar1 = false;
  if ((uVar6 == (((int)uVar6 >> 2) + (uint)((int)uVar6 < 0 && (uVar6 & 3) != 0)) * 4) &&
     (iVar3 = (int)uVar6 / 100 + ((int)uVar6 >> 0x1f), uVar6 + (iVar3 - (iVar3 >> 0x1f)) * -100 != 0
     )) {
    bVar1 = true;
  }
  if ((!bVar1) &&
     (iVar3 = (int)uVar6 / 400 + ((int)uVar6 >> 0x1f), uVar6 + (iVar3 - (iVar3 >> 0x1f)) * -400 != 0
     )) {
    bVar2 = false;
  }
  if (bVar2) {
    puVar7 = &LeapYearDays;
  }
  else {
    puVar7 = &YearDays;
  }
  iVar5 = 0xc;
  iVar3 = 0x30;
  do {
    iVar3 = iVar3 + -4;
    iVar5 = iVar5 + -1;
  } while (param_1 < *(int *)(puVar7 + iVar3));
  *(int *)(param_2 + 0x10) = iVar5;
  *(int *)(param_2 + 0xc) = (param_1 - *(int *)(puVar7 + iVar3)) + 1;
  return;
}


void OSTicksToCalendarTime(int32_t param_1,int32_t param_2,OSCalendarTime *param_3)

{
  int extraout_r4;
  int extraout_r4_00;
  int extraout_r4_01;
  int extraout_r4_02;
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  undefined8 uVar7;
  
  lVar6 = Runtime.PPCEABI.H::__mod2i(param_1,param_2,0,DAT_800000f8 >> 2);
  if (((uint)((ulonglong)lVar6 >> 0x20) ^ 0x80000000) < 0x80000000) {
    lVar6 = lVar6 + 0x33900;
  }
  iVar5 = (int)((ulonglong)lVar6 >> 0x20);
  uVar3 = (uint)lVar6;
  uVar7 = Runtime.PPCEABI.H::__div2i
                    ((int)((ulonglong)(lVar6 * 8) >> 0x20),(int)(lVar6 * 8),0,
                     (DAT_800000f8 >> 2) / 0x1e848);
  Runtime.PPCEABI.H::__mod2i((int)((ulonglong)uVar7 >> 0x20),(int)uVar7,0,1000);
  param_3->usec = extraout_r4;
  uVar7 = Runtime.PPCEABI.H::__div2i(iVar5,uVar3,0,(DAT_800000f8 >> 2) / 1000);
  Runtime.PPCEABI.H::__mod2i((int)((ulonglong)uVar7 >> 0x20),(int)uVar7,0,1000);
  param_3->msec = extraout_r4_00;
  iVar5 = param_1 - ((uint)((uint)param_2 < uVar3) + iVar5);
  uVar7 = Runtime.PPCEABI.H::__div2i(iVar5,param_2 - uVar3,0,DAT_800000f8 >> 2);
  Runtime.PPCEABI.H::__div2i((int)((ulonglong)uVar7 >> 0x20),(int)uVar7,0,0x15180);
  iVar4 = extraout_r4_01 + 0xb2575;
  uVar7 = Runtime.PPCEABI.H::__div2i(iVar5,param_2 - uVar3,0,DAT_800000f8 >> 2);
  Runtime.PPCEABI.H::__mod2i((int)((ulonglong)uVar7 >> 0x20),(int)uVar7,0,0x15180);
  iVar5 = extraout_r4_02;
  if (extraout_r4_02 < 0) {
    iVar4 = extraout_r4_01 + 0xb2574;
    iVar5 = extraout_r4_02 + 0x15180;
  }
  GetDates(iVar4,param_3);
  iVar4 = iVar5 / 0x3c + (iVar5 >> 0x1f);
  iVar2 = iVar4 - (iVar4 >> 0x1f);
  iVar1 = iVar2 / 0x3c + (iVar2 >> 0x1f);
  param_3->hour = iVar1 - (iVar1 >> 0x1f);
  param_3->min = iVar2 + (iVar1 - (iVar1 >> 0x1f)) * -0x3c;
  param_3->sec = iVar5 + (iVar4 - (iVar4 >> 0x1f)) * -0x3c;
  return;
}

