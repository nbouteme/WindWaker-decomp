#include <os/OSThread.h>
#include <os/OSInterrupt.h>
#include <os/OSThread.h>
#include <os/OSContext.h>
#include <os/OSMutex.h>
#include <m_Do_printf.h>


namespace os {
undefined4 RunQueue;
undefined IdleThread;
undefined DefaultThread;
undefined IdleContext;
undefined4 RunQueueBits;
undefined4 RunQueueHint;
undefined4 Reschedule;

void DefaultSwitchThreadCallback(void)

{
  return;
}


code * OSSetSwitchThreadCallback(code *param_1)

{
  code *pcVar1;
  
  OSDisableInterrupts();
  pcVar1 = SwitchThreadCallback;
  if (param_1 == (code *)0x0) {
    param_1 = DefaultSwitchThreadCallback;
  }
  SwitchThreadCallback = param_1;
  OSRestoreInterrupts();
  if (pcVar1 == DefaultSwitchThreadCallback) {
    pcVar1 = (code *)0x0;
  }
  return pcVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __OSThreadInit(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  DAT_803f0998 = 2;
  DAT_803f099a = 1;
  DAT_803f09a4 = 0x10;
  DAT_803f09a0 = 0x10;
  DAT_803f099c = 0;
  DAT_803f09a8 = 0xffffffff;
  DAT_803f09c0 = 0;
  OSInitThreadQueue(&DAT_803f09b8);
  DAT_803f09c8 = 0;
  DAT_803f09c4 = 0;
  DAT_800000d8 = &DefaultThread;
  OSClearContext(&DefaultThread);
  OSSetCurrentContext(&DefaultThread);
  DAT_803f09d4 = 0x8040cfa8;
  DAT_803f09d8 = &DAT_803fcfa8;
  _DAT_803fcfa8 = 0xdeadbabe;
  (*SwitchThreadCallback)(DAT_800000e4,&DefaultThread);
  DAT_800000e4 = &DefaultThread;
  OSClearStack(0);
  RunQueueBits = 0;
  iVar2 = 0;
  RunQueueHint = 0;
  puVar1 = &RunQueue;
  do {
    OSInitThreadQueue(puVar1);
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 2;
  } while (iVar2 < 0x20);
  OSInitThreadQueue(&DAT_800000dc);
  if (DAT_800000e0 == (undefined *)0x0) {
    DAT_800000dc = &DefaultThread;
  }
  else {
    *(undefined **)((int)DAT_800000e0 + 0x2fc) = &DefaultThread;
  }
  DAT_803f09d0 = (int)DAT_800000e0;
  DAT_803f09cc = 0;
  DAT_800000e0 = &DefaultThread;
  OSClearContext(&IdleContext);
  Reschedule = 0;
  return;
}


void OSInitThreadQueue(undefined4 *param_1)

{
  param_1[1] = 0;
  *param_1 = 0;
  return;
}


undefined4 OSGetCurrentThread(void)

{
  return DAT_800000e4;
}


undefined4 OSIsThreadTerminated(int param_1)

{
  bool bVar1;
  
  bVar1 = true;
  if ((*(short *)(param_1 + 0x2c8) != 8) && (*(short *)(param_1 + 0x2c8) != 0)) {
    bVar1 = false;
  }
  if (bVar1) {
    return 1;
  }
  return 0;
}


int OSDisableScheduler(void)

{
  int iVar1;
  
  OSDisableInterrupts();
  iVar1 = Reschedule;
  Reschedule = Reschedule + 1;
  OSRestoreInterrupts();
  return iVar1;
}


int OSEnableScheduler(void)

{
  int iVar1;
  
  OSDisableInterrupts();
  iVar1 = Reschedule;
  Reschedule = Reschedule + -1;
  OSRestoreInterrupts();
  return iVar1;
}


void UnsetRun(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x2e0);
  piVar2 = *(int **)(param_1 + 0x2dc);
  iVar3 = *(int *)(param_1 + 0x2e4);
  if (iVar1 == 0) {
    piVar2[1] = iVar3;
  }
  else {
    *(int *)(iVar1 + 0x2e4) = iVar3;
  }
  if (iVar3 == 0) {
    *piVar2 = iVar1;
  }
  else {
    *(int *)(iVar3 + 0x2e0) = iVar1;
  }
  if (*piVar2 == 0) {
    RunQueueBits = RunQueueBits & ~(1 << 0x1f - *(int *)(param_1 + 0x2d0));
  }
  *(undefined4 *)(param_1 + 0x2dc) = 0;
  return;
}


int __OSGetEffectivePriority(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(int *)(param_1 + 0x2d4);
  for (piVar3 = *(int **)(param_1 + 0x2f4); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[4]) {
    if ((*piVar3 != 0) && (iVar1 = *(int *)(*piVar3 + 0x2d0), iVar1 < iVar2)) {
      iVar2 = iVar1;
    }
  }
  return iVar2;
}


undefined4 SetEffectivePriority(int param_1,undefined4 param_2)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  uVar1 = *(ushort *)(param_1 + 0x2c8);
  if (uVar1 != 3) {
    if (uVar1 < 3) {
      if (uVar1 == 1) {
        UnsetRun(param_1);
        *(undefined4 *)(param_1 + 0x2d0) = param_2;
        *(undefined4 **)(param_1 + 0x2dc) = &RunQueue + *(int *)(param_1 + 0x2d0) * 2;
        iVar2 = (*(int **)(param_1 + 0x2dc))[1];
        if (iVar2 == 0) {
          **(int **)(param_1 + 0x2dc) = param_1;
        }
        else {
          *(int *)(iVar2 + 0x2e0) = param_1;
        }
        *(int *)(param_1 + 0x2e4) = iVar2;
        *(undefined4 *)(param_1 + 0x2e0) = 0;
        *(int *)(*(int *)(param_1 + 0x2dc) + 4) = param_1;
        RunQueueBits = RunQueueBits | 1 << 0x1f - *(int *)(param_1 + 0x2d0);
        RunQueueHint = 1;
      }
      else {
        if (uVar1 != 0) {
          RunQueueHint = 1;
          *(undefined4 *)(param_1 + 0x2d0) = param_2;
        }
      }
    }
    else {
      if (uVar1 < 5) {
        iVar2 = *(int *)(param_1 + 0x2e0);
        iVar4 = *(int *)(param_1 + 0x2e4);
        if (iVar2 == 0) {
          *(int *)(*(int *)(param_1 + 0x2dc) + 4) = iVar4;
        }
        else {
          *(int *)(iVar2 + 0x2e4) = iVar4;
        }
        if (iVar4 == 0) {
          **(int **)(param_1 + 0x2dc) = iVar2;
        }
        else {
          *(int *)(iVar4 + 0x2e0) = iVar2;
        }
        *(undefined4 *)(param_1 + 0x2d0) = param_2;
        piVar3 = *(int **)(param_1 + 0x2dc);
        for (iVar2 = *piVar3; (iVar2 != 0 && (*(int *)(iVar2 + 0x2d0) <= *(int *)(param_1 + 0x2d0)))
            ; iVar2 = *(int *)(iVar2 + 0x2e0)) {
        }
        if (iVar2 == 0) {
          iVar2 = piVar3[1];
          if (iVar2 == 0) {
            *piVar3 = param_1;
          }
          else {
            *(int *)(iVar2 + 0x2e0) = param_1;
          }
          *(int *)(param_1 + 0x2e4) = iVar2;
          *(undefined4 *)(param_1 + 0x2e0) = 0;
          *(int *)(*(int *)(param_1 + 0x2dc) + 4) = param_1;
        }
        else {
          *(int *)(param_1 + 0x2e0) = iVar2;
          iVar4 = *(int *)(iVar2 + 0x2e4);
          *(int *)(iVar2 + 0x2e4) = param_1;
          *(int *)(param_1 + 0x2e4) = iVar4;
          if (iVar4 == 0) {
            **(int **)(param_1 + 0x2dc) = param_1;
          }
          else {
            *(int *)(iVar4 + 0x2e0) = param_1;
          }
        }
        if (*(int *)(param_1 + 0x2f0) != 0) {
          return *(undefined4 *)(*(int *)(param_1 + 0x2f0) + 8);
        }
      }
    }
  }
  return 0;
}


void __OSPromoteThread(int param_1,int param_2)

{
  while( true ) {
    if (0 < *(int *)(param_1 + 0x2cc)) {
      return;
    }
    if (*(int *)(param_1 + 0x2d0) <= param_2) break;
    param_1 = SetEffectivePriority(param_1,param_2);
    if (param_1 == 0) {
      return;
    }
  }
  return;
}


int SelectThread(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (Reschedule < 1) {
    iVar2 = OSGetCurrentContext();
    iVar1 = DAT_800000e4;
    if (iVar2 == DAT_800000e4) {
      if (DAT_800000e4 != 0) {
        if (*(short *)(DAT_800000e4 + 0x2c8) == 2) {
          if ((param_1 == 0) &&
             (iVar2 = countLeadingZeros(RunQueueBits), *(int *)(DAT_800000e4 + 0x2d0) <= iVar2)) {
            return 0;
          }
          *(undefined2 *)(DAT_800000e4 + 0x2c8) = 1;
          *(undefined4 **)(iVar1 + 0x2dc) = &RunQueue + *(int *)(iVar1 + 0x2d0) * 2;
          iVar2 = (*(int **)(iVar1 + 0x2dc))[1];
          if (iVar2 == 0) {
            **(int **)(iVar1 + 0x2dc) = iVar1;
          }
          else {
            *(int *)(iVar2 + 0x2e0) = iVar1;
          }
          *(int *)(iVar1 + 0x2e4) = iVar2;
          *(undefined4 *)(iVar1 + 0x2e0) = 0;
          *(int *)(*(int *)(iVar1 + 0x2dc) + 4) = iVar1;
          RunQueueBits = RunQueueBits | 1 << 0x1f - *(int *)(iVar1 + 0x2d0);
          RunQueueHint = 1;
        }
        if (((*(ushort *)(iVar1 + 0x1a2) & 2) == 0) && (iVar1 = OSSaveContext(iVar1), iVar1 != 0)) {
          return 0;
        }
      }
      (*SwitchThreadCallback)(DAT_800000e4,0);
      DAT_800000e4 = 0;
      if (RunQueueBits == 0) {
        OSSetCurrentContext(&IdleContext);
        do {
          OSEnableInterrupts();
          do {
          } while (RunQueueBits == 0);
          OSDisableInterrupts();
        } while (RunQueueBits == 0);
        OSClearContext(&IdleContext);
      }
      RunQueueHint = 0;
      iVar4 = countLeadingZeros(RunQueueBits);
      piVar3 = &RunQueue + iVar4 * 2;
      iVar1 = *piVar3;
      iVar2 = *(int *)(iVar1 + 0x2e0);
      if (iVar2 == 0) {
        (&DAT_803f02bc)[iVar4 * 2] = 0;
      }
      else {
        *(undefined4 *)(iVar2 + 0x2e4) = 0;
      }
      *piVar3 = iVar2;
      if (*piVar3 == 0) {
        RunQueueBits = RunQueueBits & ~(1 << 0x1f - iVar4);
      }
      *(undefined4 *)(iVar1 + 0x2dc) = 0;
      *(undefined2 *)(iVar1 + 0x2c8) = 2;
      (*SwitchThreadCallback)(DAT_800000e4,iVar1);
      DAT_800000e4 = iVar1;
      OSSetCurrentContext(iVar1);
      OSLoadContext(iVar1);
    }
    else {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


void __OSReschedule(void)

{
  if (RunQueueHint != 0) {
    SelectThread(0);
  }
  return;
}


void OSYieldThread(void)

{
  undefined4 uVar1;
  
  uVar1 = OSDisableInterrupts();
  SelectThread(1);
  OSRestoreInterrupts(uVar1);
  return;
}


undefined4
OSCreateThread(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5,
                  int param_6,ushort param_7)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if ((param_6 < 0) || (0x1f < param_6)) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(param_1 + 0x2c8) = 1;
    uVar1 = param_4 & 0xfffffff8;
    *(ushort *)(param_1 + 0x2ca) = param_7 & 1;
    *(int *)(param_1 + 0x2d4) = param_6;
    *(int *)(param_1 + 0x2d0) = param_6;
    *(undefined4 *)(param_1 + 0x2cc) = 1;
    *(undefined4 *)(param_1 + 0x2d8) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x2f0) = 0;
    *(undefined4 *)(param_1 + 0x2ec) = 0;
    *(undefined4 *)(param_1 + 0x2e8) = 0;
    *(undefined4 *)(param_1 + 0x2f8) = 0;
    *(undefined4 *)(param_1 + 0x2f4) = 0;
    *(undefined4 *)(uVar1 - 8) = 0;
    *(undefined4 *)(uVar1 - 4) = 0;
    OSInitContext(param_1,param_2,uVar1 - 8);
    *(code **)(param_1 + 0x84) = OSExitThread;
    *(undefined4 *)(param_1 + 0xc) = param_3;
    *(uint *)(param_1 + 0x304) = param_4;
    *(uint *)(param_1 + 0x308) = param_4 - param_5;
    **(undefined4 **)(param_1 + 0x308) = 0xdeadbabe;
    *(undefined4 *)(param_1 + 0x30c) = 0;
    *(undefined4 *)(param_1 + 0x310) = 0;
    *(undefined4 *)(param_1 + 0x314) = 0;
    OSDisableInterrupts();
    if (DAT_803f0230 != 0) {
      iVar4 = 4;
      *(uint *)(param_1 + 0x19c) = *(uint *)(param_1 + 0x19c) | 0x900;
      *(ushort *)(param_1 + 0x1a2) = *(ushort *)(param_1 + 0x1a2) | 1;
      *(uint *)(param_1 + 0x194) = __OSFpscrEnableBits & 0xf8 | 4;
      iVar3 = param_1;
      do {
        *(undefined4 *)(iVar3 + 0x94) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x90) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x1cc) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x1c8) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x9c) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x98) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x1d4) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x1d0) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0xa4) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0xa0) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x1dc) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x1d8) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0xac) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0xa8) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x1e4) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x1e0) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0xb4) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0xb0) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x1ec) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x1e8) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0xbc) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0xb8) = 0xffffffff;
        *(undefined4 *)(iVar3 + 500) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x1f0) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0xc4) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0xc0) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x1fc) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x1f8) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0xcc) = 0xffffffff;
        *(undefined4 *)(iVar3 + 200) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x204) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x200) = 0xffffffff;
        iVar3 = iVar3 + 0x40;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    iVar3 = param_1;
    if (DAT_800000e0 != 0) {
      *(int *)(DAT_800000e0 + 0x2fc) = param_1;
      iVar3 = DAT_800000dc;
    }
    DAT_800000dc = iVar3;
    *(int *)(param_1 + 0x300) = DAT_800000e0;
    *(undefined4 *)(param_1 + 0x2fc) = 0;
    DAT_800000e0 = param_1;
    OSRestoreInterrupts();
    uVar2 = 1;
  }
  return uVar2;
}


void OSExitThread(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = OSDisableInterrupts();
  iVar1 = DAT_800000e4;
  OSClearContext(DAT_800000e4);
  if ((*(ushort *)(iVar1 + 0x2ca) & 1) == 0) {
    *(undefined2 *)(iVar1 + 0x2c8) = 8;
    *(undefined4 *)(iVar1 + 0x2d8) = param_1;
  }
  else {
    iVar4 = *(int *)(iVar1 + 0x2fc);
    iVar5 = *(int *)(iVar1 + 0x300);
    iVar2 = iVar5;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 0x300) = iVar5;
      iVar2 = DAT_800000e0;
    }
    DAT_800000e0 = iVar2;
    if (iVar5 != 0) {
      *(int *)(iVar5 + 0x2fc) = iVar4;
      iVar4 = DAT_800000dc;
    }
    DAT_800000dc = iVar4;
    *(undefined2 *)(iVar1 + 0x2c8) = 0;
  }
  __OSUnlockAllMutex(iVar1);
  OSWakeupThread(iVar1 + 0x2e8);
  RunQueueHint = 1;
  SelectThread(0);
  OSRestoreInterrupts(uVar3);
  return;
}


void OSCancelThread(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = OSDisableInterrupts();
  uVar1 = *(ushort *)(param_1 + 0x2c8);
  if (uVar1 == 3) {
LAB_80308410:
    OSRestoreInterrupts(uVar2);
  }
  else {
    if (uVar1 < 3) {
      if (uVar1 == 1) {
        if (*(int *)(param_1 + 0x2cc) < 1) {
          UnsetRun(param_1);
        }
      }
      else {
        if (uVar1 == 0) goto LAB_80308410;
        RunQueueHint = 1;
      }
    }
    else {
      if (4 < uVar1) goto LAB_80308410;
      iVar3 = *(int *)(param_1 + 0x2e0);
      iVar4 = *(int *)(param_1 + 0x2e4);
      if (iVar3 == 0) {
        *(int *)(*(int *)(param_1 + 0x2dc) + 4) = iVar4;
      }
      else {
        *(int *)(iVar3 + 0x2e4) = iVar4;
      }
      if (iVar4 == 0) {
        **(int **)(param_1 + 0x2dc) = iVar3;
      }
      else {
        *(int *)(iVar4 + 0x2e0) = iVar3;
      }
      *(undefined4 *)(param_1 + 0x2dc) = 0;
      if ((*(int *)(param_1 + 0x2cc) < 1) && (*(int *)(param_1 + 0x2f0) != 0)) {
        iVar3 = *(int *)(*(int *)(param_1 + 0x2f0) + 8);
        do {
          if ((0 < *(int *)(iVar3 + 0x2cc)) ||
             (iVar4 = __OSGetEffectivePriority(iVar3), *(int *)(iVar3 + 0x2d0) == iVar4)) break;
          iVar3 = SetEffectivePriority(iVar3);
        } while (iVar3 != 0);
      }
    }
    OSClearContext(param_1);
    if ((*(ushort *)(param_1 + 0x2ca) & 1) == 0) {
      *(undefined2 *)(param_1 + 0x2c8) = 8;
    }
    else {
      iVar3 = *(int *)(param_1 + 0x2fc);
      iVar5 = *(int *)(param_1 + 0x300);
      iVar4 = iVar5;
      if (iVar3 != 0) {
        *(int *)(iVar3 + 0x300) = iVar5;
        iVar4 = DAT_800000e0;
      }
      DAT_800000e0 = iVar4;
      if (iVar5 != 0) {
        *(int *)(iVar5 + 0x2fc) = iVar3;
        iVar3 = DAT_800000dc;
      }
      DAT_800000dc = iVar3;
      *(undefined2 *)(param_1 + 0x2c8) = 0;
    }
    __OSUnlockAllMutex(param_1);
    OSWakeupThread(param_1 + 0x2e8);
    if (RunQueueHint != 0) {
      SelectThread(0);
    }
    OSRestoreInterrupts(uVar2);
  }
  return;
}


undefined4 OSJoinThread(int param_1,undefined4 *param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = OSDisableInterrupts();
  if ((((*(ushort *)(param_1 + 0x2ca) & 1) == 0) && (*(short *)(param_1 + 0x2c8) != 8)) &&
     (*(int *)(param_1 + 0x2e8) == 0)) {
    OSSleepThread(param_1 + 0x2e8);
    iVar4 = DAT_800000dc;
    if (*(short *)(param_1 + 0x2c8) == 0) {
      bVar1 = false;
    }
    else {
      for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x2fc)) {
        if (param_1 == iVar4) {
          bVar1 = true;
          goto LAB_80308558;
        }
      }
      bVar1 = false;
    }
LAB_80308558:
    if (!bVar1) {
      OSRestoreInterrupts(uVar3);
      return 0;
    }
  }
  if (*(short *)(param_1 + 0x2c8) == 8) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1 + 0x2d8);
    }
    iVar4 = *(int *)(param_1 + 0x2fc);
    iVar5 = *(int *)(param_1 + 0x300);
    iVar2 = iVar5;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 0x300) = iVar5;
      iVar2 = DAT_800000e0;
    }
    DAT_800000e0 = iVar2;
    if (iVar5 != 0) {
      *(int *)(iVar5 + 0x2fc) = iVar4;
      iVar4 = DAT_800000dc;
    }
    DAT_800000dc = iVar4;
    *(undefined2 *)(param_1 + 0x2c8) = 0;
    OSRestoreInterrupts(uVar3);
    uVar3 = 1;
  }
  else {
    OSRestoreInterrupts(uVar3);
    uVar3 = 0;
  }
  return uVar3;
}


void OSDetachThread(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = OSDisableInterrupts();
  *(ushort *)(param_1 + 0x2ca) = *(ushort *)(param_1 + 0x2ca) | 1;
  if (*(short *)(param_1 + 0x2c8) == 8) {
    iVar3 = *(int *)(param_1 + 0x2fc);
    iVar4 = *(int *)(param_1 + 0x300);
    iVar1 = iVar4;
    if (iVar3 != 0) {
      *(int *)(iVar3 + 0x300) = iVar4;
      iVar1 = DAT_800000e0;
    }
    DAT_800000e0 = iVar1;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 0x2fc) = iVar3;
      iVar3 = DAT_800000dc;
    }
    DAT_800000dc = iVar3;
    *(undefined2 *)(param_1 + 0x2c8) = 0;
  }
  OSWakeupThread(param_1 + 0x2e8);
  OSRestoreInterrupts(uVar2);
  return;
}


int OSResumeThread(OSThread *param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  OSThread *pOVar5;
  int iVar6;
  int iVar7;
  OSThread *pOVar8;
  
  uVar3 = OSDisableInterrupts();
  iVar6 = param_1->field_0x2cc;
  param_1->field_0x2cc = iVar6 + -1;
  if ((int)param_1->field_0x2cc < 0) {
    param_1->field_0x2cc = 0;
  }
  else {
    if (param_1->field_0x2cc == 0) {
      uVar1 = param_1->field_0x2c8;
      if (uVar1 == 4) {
        iVar2 = param_1->field_0x2e0;
        pOVar5 = param_1->field_0x2e4;
        if (iVar2 == 0) {
          *(OSThread **)(param_1->field_0x2dc + 4) = pOVar5;
        }
        else {
          *(OSThread **)(iVar2 + 0x2e4) = pOVar5;
        }
        if (pOVar5 == (OSThread *)0x0) {
          *(int *)param_1->field_0x2dc = iVar2;
        }
        else {
          pOVar5->field_0x2e0 = iVar2;
        }
        iVar2 = param_1->field_0x2d4;
        for (piVar4 = param_1->field_0x2f4; piVar4 != (int *)0x0; piVar4 = (int *)piVar4[4]) {
          if ((*piVar4 != 0) && (iVar7 = *(int *)(*piVar4 + 0x2d0), iVar7 < iVar2)) {
            iVar2 = iVar7;
          }
        }
        param_1->field_0x2d0 = iVar2;
        pOVar5 = (OSThread *)param_1->field_0x2dc;
        for (pOVar8 = *(OSThread **)pOVar5;
            (pOVar8 != (OSThread *)0x0 && (pOVar8->field_0x2d0 <= param_1->field_0x2d0));
            pOVar8 = (OSThread *)pOVar8->field_0x2e0) {
        }
        if (pOVar8 == (OSThread *)0x0) {
          pOVar8 = *(OSThread **)&pOVar5->field_0x4;
          if (pOVar8 == (OSThread *)0x0) {
            *(OSThread **)pOVar5 = param_1;
          }
          else {
            pOVar8->field_0x2e0 = param_1;
          }
          param_1->field_0x2e4 = pOVar8;
          param_1->field_0x2e0 = 0;
          *(OSThread **)(param_1->field_0x2dc + 4) = param_1;
        }
        else {
          param_1->field_0x2e0 = pOVar8;
          pOVar5 = pOVar8->field_0x2e4;
          pOVar8->field_0x2e4 = param_1;
          param_1->field_0x2e4 = pOVar5;
          if (pOVar5 == (OSThread *)0x0) {
            *(OSThread **)param_1->field_0x2dc = param_1;
          }
          else {
            pOVar5->field_0x2e0 = param_1;
          }
        }
        if (param_1->field_0x2f0 != 0) {
          iVar2 = *(int *)(param_1->field_0x2f0 + 8);
          do {
            if ((0 < *(int *)(iVar2 + 0x2cc)) ||
               (iVar7 = __OSGetEffectivePriority(iVar2), *(int *)(iVar2 + 0x2d0) == iVar7)) break;
            iVar2 = SetEffectivePriority(iVar2);
          } while (iVar2 != 0);
        }
      }
      else {
        if ((uVar1 < 4) && (uVar1 == 1)) {
          iVar2 = param_1->field_0x2d4;
          for (piVar4 = param_1->field_0x2f4; piVar4 != (int *)0x0; piVar4 = (int *)piVar4[4]) {
            if ((*piVar4 != 0) && (iVar7 = *(int *)(*piVar4 + 0x2d0), iVar7 < iVar2)) {
              iVar2 = iVar7;
            }
          }
          param_1->field_0x2d0 = iVar2;
          param_1->field_0x2dc = (int)(&RunQueue + param_1->field_0x2d0 * 2);
          pOVar5 = *(OSThread **)&((OSThread *)param_1->field_0x2dc)->field_0x4;
          if (pOVar5 == (OSThread *)0x0) {
            *(OSThread **)(OSThread *)param_1->field_0x2dc = param_1;
          }
          else {
            pOVar5->field_0x2e0 = param_1;
          }
          param_1->field_0x2e4 = pOVar5;
          param_1->field_0x2e0 = 0;
          *(OSThread **)(param_1->field_0x2dc + 4) = param_1;
          RunQueueBits = RunQueueBits | 1 << 0x1f - param_1->field_0x2d0;
          RunQueueHint = 1;
        }
      }
      if (RunQueueHint != 0) {
        SelectThread(0);
      }
    }
  }
  OSRestoreInterrupts(uVar3);
  return iVar6;
}


int OSSuspendThread(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = OSDisableInterrupts();
  iVar3 = *(int *)(param_1 + 0x2cc);
  *(int *)(param_1 + 0x2cc) = iVar3 + 1;
  if (iVar3 == 0) {
    uVar1 = *(ushort *)(param_1 + 0x2c8);
    if (uVar1 != 3) {
      if (uVar1 < 3) {
        if (uVar1 == 1) {
          UnsetRun(param_1);
        }
        else {
          if (uVar1 != 0) {
            RunQueueHint = 1;
            *(undefined2 *)(param_1 + 0x2c8) = 1;
          }
        }
      }
      else {
        if (uVar1 < 5) {
          iVar4 = *(int *)(param_1 + 0x2e0);
          iVar5 = *(int *)(param_1 + 0x2e4);
          if (iVar4 == 0) {
            *(int *)(*(int *)(param_1 + 0x2dc) + 4) = iVar5;
          }
          else {
            *(int *)(iVar4 + 0x2e4) = iVar5;
          }
          if (iVar5 == 0) {
            **(int **)(param_1 + 0x2dc) = iVar4;
          }
          else {
            *(int *)(iVar5 + 0x2e0) = iVar4;
          }
          *(undefined4 *)(param_1 + 0x2d0) = 0x20;
          iVar4 = (*(int **)(param_1 + 0x2dc))[1];
          if (iVar4 == 0) {
            **(int **)(param_1 + 0x2dc) = param_1;
          }
          else {
            *(int *)(iVar4 + 0x2e0) = param_1;
          }
          *(int *)(param_1 + 0x2e4) = iVar4;
          *(undefined4 *)(param_1 + 0x2e0) = 0;
          *(int *)(*(int *)(param_1 + 0x2dc) + 4) = param_1;
          if (*(int *)(param_1 + 0x2f0) != 0) {
            iVar4 = *(int *)(*(int *)(param_1 + 0x2f0) + 8);
            do {
              if ((0 < *(int *)(iVar4 + 0x2cc)) ||
                 (iVar5 = __OSGetEffectivePriority(iVar4), *(int *)(iVar4 + 0x2d0) == iVar5)) break;
              iVar4 = SetEffectivePriority(iVar4);
            } while (iVar4 != 0);
          }
        }
      }
    }
    if (RunQueueHint != 0) {
      SelectThread(0);
    }
  }
  OSRestoreInterrupts(uVar2);
  return iVar3;
}


void OSSleepThread(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = OSDisableInterrupts();
  iVar1 = DAT_800000e4;
  *(undefined2 *)(DAT_800000e4 + 0x2c8) = 4;
  *(int **)(iVar1 + 0x2dc) = param_1;
  for (iVar4 = *param_1; (iVar4 != 0 && (*(int *)(iVar4 + 0x2d0) <= *(int *)(iVar1 + 0x2d0)));
      iVar4 = *(int *)(iVar4 + 0x2e0)) {
  }
  if (iVar4 == 0) {
    iVar4 = param_1[1];
    if (iVar4 == 0) {
      *param_1 = iVar1;
    }
    else {
      *(int *)(iVar4 + 0x2e0) = iVar1;
    }
    *(int *)(iVar1 + 0x2e4) = iVar4;
    *(undefined4 *)(iVar1 + 0x2e0) = 0;
    param_1[1] = iVar1;
  }
  else {
    *(int *)(iVar1 + 0x2e0) = iVar4;
    iVar3 = *(int *)(iVar4 + 0x2e4);
    *(int *)(iVar4 + 0x2e4) = iVar1;
    *(int *)(iVar1 + 0x2e4) = iVar3;
    if (iVar3 == 0) {
      *param_1 = iVar1;
    }
    else {
      *(int *)(iVar3 + 0x2e0) = iVar1;
    }
  }
  RunQueueHint = 1;
  SelectThread(0);
  OSRestoreInterrupts(uVar2);
  return;
}


void OSWakeupThread(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = OSDisableInterrupts();
  while (iVar3 = *param_1, iVar3 != 0) {
    iVar2 = *(int *)(iVar3 + 0x2e0);
    if (iVar2 == 0) {
      param_1[1] = 0;
    }
    else {
      *(undefined4 *)(iVar2 + 0x2e4) = 0;
    }
    *param_1 = iVar2;
    *(undefined2 *)(iVar3 + 0x2c8) = 1;
    if (*(int *)(iVar3 + 0x2cc) < 1) {
      *(undefined4 **)(iVar3 + 0x2dc) = &RunQueue + *(int *)(iVar3 + 0x2d0) * 2;
      iVar2 = (*(int **)(iVar3 + 0x2dc))[1];
      if (iVar2 == 0) {
        **(int **)(iVar3 + 0x2dc) = iVar3;
      }
      else {
        *(int *)(iVar2 + 0x2e0) = iVar3;
      }
      *(int *)(iVar3 + 0x2e4) = iVar2;
      *(undefined4 *)(iVar3 + 0x2e0) = 0;
      *(int *)(*(int *)(iVar3 + 0x2dc) + 4) = iVar3;
      RunQueueBits = RunQueueBits | 1 << 0x1f - *(int *)(iVar3 + 0x2d0);
      RunQueueHint = 1;
    }
  }
  if (RunQueueHint != 0) {
    SelectThread(0);
  }
  OSRestoreInterrupts(uVar1);
  return;
}


undefined4 OSSetThreadPriority(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_2 < 0) || (0x1f < param_2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = OSDisableInterrupts();
    if (*(int *)(param_1 + 0x2d4) != param_2) {
      *(int *)(param_1 + 0x2d4) = param_2;
      while (*(int *)(param_1 + 0x2cc) < 1) {
        iVar2 = __OSGetEffectivePriority(param_1);
        if ((*(int *)(param_1 + 0x2d0) == iVar2) ||
           (param_1 = SetEffectivePriority(param_1), param_1 == 0)) break;
      }
      if (RunQueueHint != 0) {
        SelectThread(0);
      }
    }
    OSRestoreInterrupts(uVar1);
    uVar1 = 1;
  }
  return uVar1;
}


undefined4 OSGetThreadPriority(int param_1)

{
  return *(undefined4 *)(param_1 + 0x2d4);
}


undefined4 CheckThreadQueue(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x2e4) != 0)) {
    return 0;
  }
  if ((param_1[1] != 0) && (*(int *)(param_1[1] + 0x2e0) != 0)) {
    return 0;
  }
  while( true ) {
    iVar2 = iVar1;
    if (iVar2 == 0) {
      return 1;
    }
    iVar1 = *(int *)(iVar2 + 0x2e0);
    if ((iVar1 != 0) && (iVar2 != *(int *)(iVar1 + 0x2e4))) break;
    if ((*(int *)(iVar2 + 0x2e4) != 0) && (iVar2 != *(int *)(*(int *)(iVar2 + 0x2e4) + 0x2e0))) {
      return 0;
    }
  }
  return 0;
}


int OSCheckActiveThreads(void)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  
  piVar8 = &RunQueue;
  iVar7 = 0;
  uVar4 = OSDisableInterrupts();
  iVar6 = 0;
  do {
    if ((RunQueueBits & 1 << 0x1f - iVar6) == 0) {
      if ((*piVar8 != 0) || (piVar8[1] != 0)) {
        m_Do_printf::OSReport(_834,0x5c3);
        m_Do_printf::OSPanic(_832,0x5c3,&_833);
      }
    }
    else {
      if ((*piVar8 == 0) || (piVar8[1] == 0)) {
        m_Do_printf::OSReport(_831,0x5be);
        m_Do_printf::OSPanic(_832,0x5be,&_833);
      }
    }
    iVar5 = CheckThreadQueue(piVar8);
    if (iVar5 == 0) {
      m_Do_printf::OSReport(_835,0x5c5);
      m_Do_printf::OSPanic(_832,0x5c5,&_833);
    }
    iVar6 = iVar6 + 1;
    piVar8 = piVar8 + 2;
  } while (iVar6 < 0x20);
  if ((DAT_800000dc != 0) && (*(int *)(DAT_800000dc + 0x300) != 0)) {
    m_Do_printf::OSReport(_836,0x5ca);
    m_Do_printf::OSPanic(_832,0x5ca,&_833);
  }
  iVar6 = DAT_800000dc;
  if ((DAT_800000e0 != 0) && (*(int *)(DAT_800000e0 + 0x2fc) != 0)) {
    m_Do_printf::OSReport(_837,0x5cc);
    m_Do_printf::OSPanic(_832,0x5cc,&_833);
    iVar6 = DAT_800000dc;
  }
  do {
    if (iVar6 == 0) {
      OSRestoreInterrupts(uVar4);
      return iVar7;
    }
    iVar7 = iVar7 + 1;
    if ((*(int *)(iVar6 + 0x2fc) != 0) && (iVar6 != *(int *)(*(int *)(iVar6 + 0x2fc) + 0x300))) {
      m_Do_printf::OSReport(_838,0x5d4);
      m_Do_printf::OSPanic(_832,0x5d4,&_833);
    }
    if ((*(int *)(iVar6 + 0x300) != 0) && (iVar6 != *(int *)(*(int *)(iVar6 + 0x300) + 0x2fc))) {
      m_Do_printf::OSReport(_839,0x5d6);
      m_Do_printf::OSPanic(_832,0x5d6,&_833);
    }
    if (**(int **)(iVar6 + 0x308) != -0x21524542) {
      m_Do_printf::OSReport(_840,0x5d9);
      m_Do_printf::OSPanic(_832,0x5d9,&_833);
    }
    if ((*(int *)(iVar6 + 0x2d0) < 0) || (0x20 < *(int *)(iVar6 + 0x2d0))) {
      m_Do_printf::OSReport(_841,0x5dc);
      m_Do_printf::OSPanic(_832,0x5dc,&_833);
    }
    if (*(int *)(iVar6 + 0x2cc) < 0) {
      m_Do_printf::OSReport(_842,0x5dd);
      m_Do_printf::OSPanic(_832,0x5dd,&_833);
    }
    iVar5 = CheckThreadQueue(iVar6 + 0x2e8);
    if (iVar5 == 0) {
      m_Do_printf::OSReport(_843,0x5de);
      m_Do_printf::OSPanic(_832,0x5de,&_833);
    }
    uVar1 = *(ushort *)(iVar6 + 0x2c8);
    if (uVar1 == 4) {
      if (*(int *)(iVar6 + 0x2dc) == 0) {
        m_Do_printf::OSReport(_849,0x5ef);
        m_Do_printf::OSPanic(_832,0x5ef,&_833);
      }
      iVar5 = CheckThreadQueue(*(undefined4 *)(iVar6 + 0x2dc));
      if (iVar5 == 0) {
        m_Do_printf::OSReport(_850,0x5f0);
        m_Do_printf::OSPanic(_832,0x5f0,&_833);
      }
      for (iVar5 = **(int **)(iVar6 + 0x2dc); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x2e0)) {
        if (iVar6 == iVar5) {
          bVar2 = true;
          goto LAB_80309374;
        }
      }
      bVar2 = false;
LAB_80309374:
      if (!bVar2) {
        m_Do_printf::OSReport(_851,0x5f1);
        m_Do_printf::OSPanic(_832,0x5f1,&_833);
      }
      if (*(int *)(iVar6 + 0x2cc) < 1) {
        iVar5 = *(int *)(iVar6 + 0x2d4);
        for (piVar8 = *(int **)(iVar6 + 0x2f4); piVar8 != (int *)0x0; piVar8 = (int *)piVar8[4]) {
          if ((*piVar8 != 0) && (iVar3 = *(int *)(*piVar8 + 0x2d0), iVar3 < iVar5)) {
            iVar5 = iVar3;
          }
        }
        if (*(int *)(iVar6 + 0x2d0) != iVar5) {
          m_Do_printf::OSReport(_846,0x5f4);
          m_Do_printf::OSPanic(_832,0x5f4,&_833);
        }
      }
      else {
        if (*(int *)(iVar6 + 0x2d0) != 0x20) {
          m_Do_printf::OSReport(_852,0x5f8);
          m_Do_printf::OSPanic(_832,0x5f8,&_833);
        }
      }
      iVar5 = __OSCheckDeadLock(iVar6);
      if (iVar5 != 0) {
        m_Do_printf::OSReport(_853,0x5fa);
        m_Do_printf::OSPanic(_832,0x5fa,&_833);
      }
    }
    else {
      if (uVar1 < 4) {
        if (uVar1 == 2) {
          if (0 < *(int *)(iVar6 + 0x2cc)) {
            m_Do_printf::OSReport(_847,0x5ea);
            m_Do_printf::OSPanic(_832,0x5ea,&_833);
          }
          if (*(int *)(iVar6 + 0x2dc) != 0) {
            m_Do_printf::OSReport(_848,0x5eb);
            m_Do_printf::OSPanic(_832,0x5eb,&_833);
          }
          iVar5 = *(int *)(iVar6 + 0x2d4);
          for (piVar8 = *(int **)(iVar6 + 0x2f4); piVar8 != (int *)0x0; piVar8 = (int *)piVar8[4]) {
            if ((*piVar8 != 0) && (iVar3 = *(int *)(*piVar8 + 0x2d0), iVar3 < iVar5)) {
              iVar5 = iVar3;
            }
          }
          if (*(int *)(iVar6 + 0x2d0) != iVar5) {
            m_Do_printf::OSReport(_846,0x5ec);
            m_Do_printf::OSPanic(_832,0x5ec,&_833);
          }
        }
        else {
          if ((1 < uVar1) || (uVar1 == 0)) goto LAB_803094bc;
          if (*(int *)(iVar6 + 0x2cc) < 1) {
            if (*(undefined4 **)(iVar6 + 0x2dc) != &RunQueue + *(int *)(iVar6 + 0x2d0) * 2) {
              m_Do_printf::OSReport(_844,0x5e4);
              m_Do_printf::OSPanic(_832,0x5e4,&_833);
            }
            for (iVar5 = (&RunQueue)[*(int *)(iVar6 + 0x2d0) * 2]; iVar5 != 0;
                iVar5 = *(int *)(iVar5 + 0x2e0)) {
              if (iVar6 == iVar5) {
                bVar2 = true;
                goto LAB_80309188;
              }
            }
            bVar2 = false;
LAB_80309188:
            if (!bVar2) {
              m_Do_printf::OSReport(_845,0x5e5);
              m_Do_printf::OSPanic(_832,0x5e5,&_833);
            }
            iVar5 = *(int *)(iVar6 + 0x2d4);
            for (piVar8 = *(int **)(iVar6 + 0x2f4); piVar8 != (int *)0x0; piVar8 = (int *)piVar8[4])
            {
              if ((*piVar8 != 0) && (iVar3 = *(int *)(*piVar8 + 0x2d0), iVar3 < iVar5)) {
                iVar5 = iVar3;
              }
            }
            if (*(int *)(iVar6 + 0x2d0) != iVar5) {
              m_Do_printf::OSReport(_846,0x5e6);
              m_Do_printf::OSPanic(_832,0x5e6,&_833);
            }
          }
        }
      }
      else {
        if (uVar1 == 8) {
          if ((*(int *)(iVar6 + 0x2f4) != 0) || (*(int *)(iVar6 + 0x2f8) != 0)) {
            m_Do_printf::OSReport(_854,0x5fe);
            m_Do_printf::OSPanic(_832,0x5fe,&_833);
          }
        }
        else {
LAB_803094bc:
          m_Do_printf::OSReport(_855,uVar1,iVar6);
          m_Do_printf::OSPanic(_832,0x604,&_833);
        }
      }
    }
    iVar5 = __OSCheckMutexes(iVar6);
    if (iVar5 == 0) {
      m_Do_printf::OSReport(_856,0x609);
      m_Do_printf::OSPanic(_832,0x609,&_833);
    }
    iVar6 = *(int *)(iVar6 + 0x2fc);
  } while( true );
}


void OSClearStack(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  
  uVar5 = param_1 & 0xff | (param_1 & 0xff) << 8 | param_1 << 0x18 | (param_1 & 0xff) << 0x10;
  puVar1 = (uint *)OSGetStackPointer();
  puVar4 = (uint *)(*(int *)(DAT_800000e4 + 0x308) + 4);
  uVar2 = (int)puVar1 + (3 - (int)puVar4);
  uVar3 = uVar2 >> 2;
  if (puVar4 < puVar1) {
    uVar2 = uVar2 >> 5;
    if (uVar2 != 0) {
      do {
        *puVar4 = uVar5;
        puVar4[1] = uVar5;
        puVar4[2] = uVar5;
        puVar4[3] = uVar5;
        puVar4[4] = uVar5;
        puVar4[5] = uVar5;
        puVar4[6] = uVar5;
        puVar4[7] = uVar5;
        puVar4 = puVar4 + 8;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
      uVar3 = uVar3 & 7;
      if (uVar3 == 0) {
        return;
      }
    }
    do {
      *puVar4 = uVar5;
      puVar4 = puVar4 + 1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return;
}

