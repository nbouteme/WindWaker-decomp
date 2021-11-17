#include <os/OSAlarm.h>
#include <os/OS.h>
#include <os/OSAlarm.h>
#include <os/OSTime.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <base/PPCArch.h>
#include <os/OSInterrupt.h>
#include <os/OSContext.h>
#include <os/OSThread.h>


namespace os {
undefined4 AlarmQueue;

void OSInitAlarm(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)__OSGetExceptionHandler(8);
  if (pcVar1 != DecrementerExceptionHandler) {
    uRam803f79c4 = 0;
    AlarmQueue = 0;
    __OSSetExceptionHandler(8);
  }
  return;
}


void OSCreateAlarm(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return;
}


void InsertAlarm(undefined4 *param_1,undefined4 param_2,uint param_3,uint param_4,
                    undefined4 param_5)

{
  ulonglong uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  undefined8 uVar8;
  longlong lVar9;
  
  if (0x80000000 < (uint)(param_1[7] != 0) + (param_1[6] ^ 0x80000000)) {
    uVar8 = __OSGetSystemTime();
    uVar2 = (uint)((ulonglong)uVar8 >> 0x20);
    uVar4 = (uint)uVar8;
    param_3 = param_1[8];
    param_4 = param_1[9];
    if ((param_3 ^ 0x80000000) < (uint)(param_4 < uVar4) + (uVar2 ^ 0x80000000)) {
      iVar6 = param_1[6];
      uVar5 = param_1[7];
      lVar9 = Runtime.PPCEABI.H::__div2i
                        (uVar2 - ((uVar4 < param_4) + param_3),uVar4 - param_4,iVar6,uVar5);
      uVar1 = lVar9 + 1;
      uVar2 = uVar5 * (int)uVar1;
      bVar7 = CARRY4(param_4,uVar2);
      param_4 = param_4 + uVar2;
      param_3 = param_3 + iVar6 * (int)uVar1 +
                          (int)((ulonglong)uVar5 * (uVar1 & 0xffffffff) >> 0x20) +
                          uVar5 * (int)(uVar1 >> 0x20) + (uint)bVar7;
    }
  }
  *param_1 = param_5;
  param_1[3] = param_4;
  param_1[2] = param_3;
  puVar3 = AlarmQueue;
  while( true ) {
    if (puVar3 == (undefined4 *)0x0) {
      param_1[5] = 0;
      iVar6 = (int)puRam803f79c4;
      bVar7 = puRam803f79c4 == (undefined4 *)0x0;
      puVar3 = param_1;
      param_1[4] = puRam803f79c4;
      puRam803f79c4 = puVar3;
      if (bVar7) {
        AlarmQueue = param_1;
        puRam803f79c4 = param_1;
        uVar8 = __OSGetSystemTime();
        uVar4 = param_1[3] - (uint)uVar8;
        uVar2 = param_1[2] -
                ((uint)((uint)param_1[3] < (uint)uVar8) + (int)((ulonglong)uVar8 >> 0x20)) ^
                0x80000000;
        if (uVar2 < 0x80000000) {
          base::PPCMtdec(0);
        }
        else {
          if (uVar2 < (uVar4 < 0x80000000) + 0x80000000) {
            base::PPCMtdec(uVar4);
          }
          else {
            base::PPCMtdec(0x7fffffff);
          }
        }
      }
      else {
        *(undefined4 **)(iVar6 + 0x14) = param_1;
      }
      return;
    }
    if ((param_3 ^ 0x80000000) < (uint)(param_4 < (uint)puVar3[3]) + (puVar3[2] ^ 0x80000000))
    break;
    puVar3 = (undefined4 *)puVar3[5];
  }
  param_1[4] = puVar3[4];
  puVar3[4] = param_1;
  param_1[5] = puVar3;
  if (param_1[4] != 0) {
    *(undefined4 **)(param_1[4] + 0x14) = param_1;
    return;
  }
  AlarmQueue = param_1;
  uVar8 = __OSGetSystemTime();
  uVar4 = param_1[3] - (uint)uVar8;
  uVar2 = param_1[2] - ((uint)((uint)param_1[3] < (uint)uVar8) + (int)((ulonglong)uVar8 >> 0x20)) ^
          0x80000000;
  if (uVar2 < 0x80000000) {
    base::PPCMtdec(0);
    return;
  }
  if (uVar2 < (uVar4 < 0x80000000) + 0x80000000) {
    base::PPCMtdec(uVar4);
    return;
  }
  base::PPCMtdec(0x7fffffff);
  return;
}


void OSSetAlarm(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  longlong lVar1;
  undefined4 uVar2;
  longlong lVar3;
  
  uVar2 = OSDisableInterrupts();
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  lVar3 = __OSGetSystemTime();
  lVar1 = lVar3 + CONCAT44(param_3,param_4);
  InsertAlarm(param_1,(int)lVar3,(int)((ulonglong)lVar1 >> 0x20),(int)lVar1,param_5);
  OSRestoreInterrupts(uVar2);
  return;
}


void OSSetPeriodicAlarm
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar1 = OSDisableInterrupts();
  *(undefined4 *)(param_1 + 0x1c) = param_6;
  *(undefined4 *)(param_1 + 0x18) = param_5;
  uVar2 = __OSTimeToSystemTime(param_3,param_4);
  *(int *)(param_1 + 0x24) = (int)uVar2;
  *(int *)(param_1 + 0x20) = (int)((ulonglong)uVar2 >> 0x20);
  InsertAlarm(param_1,(int)uVar2,0,0,param_7);
  OSRestoreInterrupts(uVar1);
  return;
}


void OSCancelAlarm(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  
  uVar1 = OSDisableInterrupts();
  if (*param_1 == 0) {
    OSRestoreInterrupts(uVar1);
  }
  else {
    iVar4 = param_1[5];
    if (iVar4 == 0) {
      iRam803f79c4 = param_1[4];
    }
    else {
      *(int *)(iVar4 + 0x10) = param_1[4];
    }
    if (param_1[4] == 0) {
      AlarmQueue = iVar4;
      if (iVar4 != 0) {
        uVar5 = __OSGetSystemTime();
        uVar3 = *(uint *)(iVar4 + 0xc) - (uint)uVar5;
        uVar2 = *(int *)(iVar4 + 8) -
                ((uint)(*(uint *)(iVar4 + 0xc) < (uint)uVar5) + (int)((ulonglong)uVar5 >> 0x20)) ^
                0x80000000;
        if (uVar2 < 0x80000000) {
          base::PPCMtdec(0);
        }
        else {
          if (uVar2 < (uVar3 < 0x80000000) + 0x80000000) {
            base::PPCMtdec(uVar3);
          }
          else {
            base::PPCMtdec(0x7fffffff);
          }
        }
      }
    }
    else {
      *(int *)(param_1[4] + 0x14) = iVar4;
    }
    *param_1 = 0;
    OSRestoreInterrupts(uVar1);
  }
  return;
}


void DecrementerExceptionCallback(undefined4 param_1,undefined4 param_2)

{
  code **ppcVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  undefined8 uVar6;
  undefined auStack728 [712];
  
  uVar6 = __OSGetSystemTime();
  ppcVar1 = AlarmQueue;
  if (AlarmQueue == (code **)0x0) {
    OSLoadContext(param_2);
  }
  if (((uint)((ulonglong)uVar6 >> 0x20) ^ 0x80000000) <
      (uint)((code *)uVar6 < ppcVar1[3]) + ((uint)ppcVar1[2] ^ 0x80000000)) {
    uVar6 = __OSGetSystemTime();
    uVar4 = (int)ppcVar1[3] - (int)(code *)uVar6;
    uVar3 = (int)ppcVar1[2] - ((uint)(ppcVar1[3] < (code *)uVar6) + (int)((ulonglong)uVar6 >> 0x20))
            ^ 0x80000000;
    if (uVar3 < 0x80000000) {
      base::PPCMtdec(0);
    }
    else {
      if (uVar3 < (uVar4 < 0x80000000) + 0x80000000) {
        base::PPCMtdec(uVar4);
      }
      else {
        base::PPCMtdec(0x7fffffff);
      }
    }
    OSLoadContext(param_2);
  }
  AlarmQueue = (code **)ppcVar1[5];
  if (AlarmQueue == (code **)0x0) {
    uRam803f79c4 = 0;
  }
  else {
    *(undefined4 *)((int)AlarmQueue + 0x10) = 0;
  }
  pcVar5 = *ppcVar1;
  *ppcVar1 = (code *)0x0;
  if (0x80000000 < (uint)(ppcVar1[7] != (code *)0x0) + ((uint)ppcVar1[6] ^ 0x80000000)) {
    InsertAlarm(ppcVar1,0x80000000,0,0,pcVar5);
  }
  pcVar2 = (code *)AlarmQueue;
  if (AlarmQueue != (code **)0x0) {
    uVar6 = __OSGetSystemTime();
    uVar3 = *(uint *)(pcVar2 + 0xc);
    uVar4 = uVar3 - (uint)uVar6;
    uVar3 = *(int *)(pcVar2 + 8) - ((uint)(uVar3 < (uint)uVar6) + (int)((ulonglong)uVar6 >> 0x20)) ^
            0x80000000;
    if (uVar3 < 0x80000000) {
      base::PPCMtdec(0);
    }
    else {
      if (uVar3 < (uVar4 < 0x80000000) + 0x80000000) {
        base::PPCMtdec(uVar4);
      }
      else {
        base::PPCMtdec(0x7fffffff);
      }
    }
  }
  OSDisableScheduler();
  OSClearContext(auStack728);
  OSSetCurrentContext(auStack728);
  (*pcVar5)(ppcVar1,param_2);
  OSClearContext(auStack728);
  OSSetCurrentContext(param_2);
  OSEnableScheduler();
  __OSReschedule();
  OSLoadContext(param_2);
  return;
}


void DecrementerExceptionHandler
               (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 in_r0;
  undefined4 in_r11;
  undefined4 in_r12;
  undefined4 unaff_r14;
  undefined4 unaff_r15;
  undefined4 unaff_r16;
  undefined4 unaff_r17;
  undefined4 unaff_r18;
  undefined4 unaff_r19;
  undefined4 unaff_r20;
  undefined4 unaff_r21;
  undefined4 unaff_r22;
  undefined4 unaff_r23;
  undefined4 unaff_r24;
  undefined4 unaff_r25;
  undefined4 unaff_r26;
  undefined4 unaff_r27;
  undefined4 unaff_r28;
  undefined4 unaff_r29;
  undefined4 unaff_r30;
  undefined4 unaff_r31;
  undefined4 in_GQR1;
  undefined4 in_GQR7;
  
  *param_2 = in_r0;
  param_2[1] = register0x00000004;
  param_2[2] = 0x803ffd00;
  param_2[6] = param_4;
  param_2[7] = param_5;
  param_2[8] = param_6;
  param_2[9] = param_7;
  param_2[10] = param_8;
  param_2[0xb] = in_r11;
  param_2[0xc] = in_r12;
  param_2[0xd] = 0x803fe0e0;
  param_2[0xe] = unaff_r14;
  param_2[0xf] = unaff_r15;
  param_2[0x10] = unaff_r16;
  param_2[0x11] = unaff_r17;
  param_2[0x12] = unaff_r18;
  param_2[0x13] = unaff_r19;
  param_2[0x14] = unaff_r20;
  param_2[0x15] = unaff_r21;
  param_2[0x16] = unaff_r22;
  param_2[0x17] = unaff_r23;
  param_2[0x18] = unaff_r24;
  param_2[0x19] = unaff_r25;
  param_2[0x1a] = unaff_r26;
  param_2[0x1b] = unaff_r27;
  param_2[0x1c] = unaff_r28;
  param_2[0x1d] = unaff_r29;
  param_2[0x1e] = unaff_r30;
  param_2[0x1f] = unaff_r31;
  param_2[0x6a] = in_GQR1;
  param_2[0x6b] = 0x40004;
  param_2[0x6c] = 0x50005;
  param_2[0x6d] = 0x60006;
  param_2[0x6e] = 0x70007;
  param_2[0x6f] = 0x3d043d04;
  param_2[0x70] = in_GQR7;
  DecrementerExceptionCallback();
  return;
}

