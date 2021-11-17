#include <os/OSMutex.h>
#include <os/OSThread.h>
#include <os/OSInterrupt.h>
#include <os/OSMutex.h>


namespace os {

void OSInitMutex(OSMutex *param_1)

{
  OSInitThreadQueue();
  param_1->thread = (OSThread *)0x0;
  param_1->count = 0;
  return;
}


void OSLockMutex(OSMutex *param_1)

{
  undefined4 uVar1;
  OSThread *pOVar2;
  OSMutex *pOVar3;
  
  uVar1 = OSDisableInterrupts();
  pOVar2 = (OSThread *)OSGetCurrentThread();
  do {
    if (param_1->thread == (OSThread *)0x0) {
      param_1->thread = pOVar2;
      param_1->count = param_1->count + 1;
      pOVar3 = *(OSMutex **)&pOVar2->field_0x2f8;
      if (pOVar3 == (OSMutex *)0x0) {
        pOVar2->field_0x2f4 = (int *)param_1;
      }
      else {
        (pOVar3->link).next = param_1;
      }
      (param_1->link).prev = pOVar3;
      (param_1->link).next = (OSMutex *)0x0;
      *(OSMutex **)&pOVar2->field_0x2f8 = param_1;
LAB_80305f48:
      OSRestoreInterrupts(uVar1);
      return;
    }
    if (param_1->thread == pOVar2) {
      param_1->count = param_1->count + 1;
      goto LAB_80305f48;
    }
    pOVar2->field_0x2f0 = (int)param_1;
    __OSPromoteThread(param_1->thread,pOVar2->field_0x2d0);
    OSSleepThread(param_1);
    pOVar2->field_0x2f0 = 0;
  } while( true );
}


void OSUnlockMutex(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar2 = OSDisableInterrupts();
  iVar3 = OSGetCurrentThread();
  if (*(int *)(param_1 + 8) == iVar3) {
    iVar1 = *(int *)(param_1 + 0xc) + -1;
    *(int *)(param_1 + 0xc) = iVar1;
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x10);
      iVar5 = *(int *)(param_1 + 0x14);
      if (iVar1 == 0) {
        *(int *)(iVar3 + 0x2f8) = iVar5;
      }
      else {
        *(int *)(iVar1 + 0x14) = iVar5;
      }
      if (iVar5 == 0) {
        *(int *)(iVar3 + 0x2f4) = iVar1;
      }
      else {
        *(int *)(iVar5 + 0x10) = iVar1;
      }
      *(undefined4 *)(param_1 + 8) = 0;
      if (*(int *)(iVar3 + 0x2d0) < *(int *)(iVar3 + 0x2d4)) {
        uVar4 = __OSGetEffectivePriority(iVar3);
        *(undefined4 *)(iVar3 + 0x2d0) = uVar4;
      }
      OSWakeupThread(param_1);
    }
  }
  OSRestoreInterrupts(uVar2);
  return;
}


void __OSUnlockAllMutex(int param_1)

{
  int iVar1;
  int iVar2;
  
  while (iVar1 = *(int *)(param_1 + 0x2f4), iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x10);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x2f8) = 0;
    }
    else {
      *(undefined4 *)(iVar2 + 0x14) = 0;
    }
    *(int *)(param_1 + 0x2f4) = iVar2;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 8) = 0;
    OSWakeupThread(iVar1);
  }
  return;
}


undefined4 OSTryLockMutex(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = OSDisableInterrupts();
  iVar2 = OSGetCurrentThread();
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = iVar2;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    iVar3 = *(int *)(iVar2 + 0x2f8);
    if (iVar3 == 0) {
      *(int *)(iVar2 + 0x2f4) = param_1;
    }
    else {
      *(int *)(iVar3 + 0x10) = param_1;
    }
    *(int *)(param_1 + 0x14) = iVar3;
    uVar4 = 1;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(int *)(iVar2 + 0x2f8) = param_1;
  }
  else {
    if (*(int *)(param_1 + 8) == iVar2) {
      uVar4 = 1;
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    }
    else {
      uVar4 = 0;
    }
  }
  OSRestoreInterrupts(uVar1);
  return uVar4;
}


void OSInitCond(void)

{
  OSInitThreadQueue();
  return;
}


void OSWaitCond(undefined4 param_1,OSMutex *param_2)

{
  undefined4 uVar1;
  OSThread *pOVar2;
  OSMutex *pOVar3;
  int iVar4;
  OSMutex *pOVar5;
  s32 sVar6;
  
  uVar1 = OSDisableInterrupts();
  pOVar2 = (OSThread *)OSGetCurrentThread();
  if (param_2->thread == pOVar2) {
    sVar6 = param_2->count;
    param_2->count = 0;
    pOVar3 = (param_2->link).next;
    pOVar5 = (param_2->link).prev;
    if (pOVar3 == (OSMutex *)0x0) {
      *(OSMutex **)&pOVar2->field_0x2f8 = pOVar5;
    }
    else {
      (pOVar3->link).prev = pOVar5;
    }
    if (pOVar5 == (OSMutex *)0x0) {
      pOVar2->field_0x2f4 = (int *)pOVar3;
    }
    else {
      (pOVar5->link).next = pOVar3;
    }
    param_2->thread = (OSThread *)0x0;
    if (pOVar2->field_0x2d0 < pOVar2->field_0x2d4) {
      iVar4 = __OSGetEffectivePriority(pOVar2);
      pOVar2->field_0x2d0 = iVar4;
    }
    OSDisableScheduler();
    OSWakeupThread(param_2);
    OSEnableScheduler();
    OSSleepThread(param_1);
    OSLockMutex(param_2);
    param_2->count = sVar6;
  }
  OSRestoreInterrupts(uVar1);
  return;
}


void OSSignalCond(void)

{
  OSWakeupThread();
  return;
}


undefined4 __OSCheckMutex(int *param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = *param_1;
  if ((iVar3 != 0) && (*(int *)(iVar3 + 0x2e4) != 0)) {
    return 0;
  }
  iVar5 = 0;
  if ((param_1[1] != 0) && (*(int *)(param_1[1] + 0x2e0) != 0)) {
    return 0;
  }
  do {
    if (iVar3 == 0) {
      if (param_1[2] == 0) {
        if (param_1[3] != 0) {
          return 0;
        }
      }
      else {
        if (param_1[3] < 1) {
          return 0;
        }
      }
      return 1;
    }
    iVar4 = *(int *)(iVar3 + 0x2e0);
    if ((iVar4 != 0) && (iVar3 != *(int *)(iVar4 + 0x2e4))) {
      return 0;
    }
    if ((*(int *)(iVar3 + 0x2e4) != 0) && (iVar3 != *(int *)(*(int *)(iVar3 + 0x2e4) + 0x2e0))) {
      return 0;
    }
    if (*(short *)(iVar3 + 0x2c8) != 4) {
      return 0;
    }
    piVar1 = (int *)(iVar3 + 0x2d0);
    bVar2 = iVar5 <= *piVar1;
    iVar3 = iVar4;
    iVar5 = *piVar1;
  } while (bVar2);
  return 0;
}


undefined4 __OSCheckDeadLock(int param_1)

{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 0x2f0); (iVar1 != 0 && (iVar1 = *(int *)(iVar1 + 8), iVar1 != 0));
      iVar1 = *(int *)(iVar1 + 0x2f0)) {
    if (iVar1 == param_1) {
      return 1;
    }
  }
  return 0;
}


undefined4 __OSCheckMutexes(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x2f4);
  while( true ) {
    if (iVar2 == 0) {
      return 1;
    }
    if (*(int *)(iVar2 + 8) != param_1) break;
    iVar1 = __OSCheckMutex(iVar2);
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = *(int *)(iVar2 + 0x10);
  }
  return 0;
}

