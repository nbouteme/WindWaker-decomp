#include <dvd/dvdqueue.h>
#include <os/OSInterrupt.h>


namespace dvd {
undefined4 WaitingQueue;

void __DVDClearWaitingQueue(void)

{
  WaitingQueue = &WaitingQueue;
  DAT_803f10dc = &WaitingQueue;
  DAT_803f10e0 = &DAT_803f10e0;
  DAT_803f10e4 = &DAT_803f10e0;
  DAT_803f10e8 = &DAT_803f10e8;
  DAT_803f10ec = &DAT_803f10e8;
  DAT_803f10f0 = &DAT_803f10f0;
  DAT_803f10f4 = &DAT_803f10f0;
  return;
}


undefined4 __DVDPushWaitingQueue(int param_1,undefined4 *param_2)

{
  os::OSDisableInterrupts();
  *(undefined4 **)(&DAT_803f10dc)[param_1 * 2] = param_2;
  param_2[1] = (&DAT_803f10dc)[param_1 * 2];
  *param_2 = &WaitingQueue + param_1 * 2;
  (&DAT_803f10dc)[param_1 * 2] = param_2;
  os::OSRestoreInterrupts();
  return 1;
}


int ** __DVDPopWaitingQueue(void)

{
  undefined4 *puVar1;
  int **ppiVar2;
  int iVar3;
  int **ppiVar4;
  int iVar5;
  
  os::OSDisableInterrupts();
  iVar5 = 4;
  puVar1 = &WaitingQueue;
  iVar3 = 0;
  do {
    if ((undefined4 *)*puVar1 != puVar1) {
      os::OSRestoreInterrupts();
      os::OSDisableInterrupts();
      ppiVar2 = (int **)(&WaitingQueue + iVar3 * 2);
      ppiVar4 = (int **)*ppiVar2;
      *ppiVar2 = *ppiVar4;
      (*ppiVar4)[1] = (int)ppiVar2;
      os::OSRestoreInterrupts();
      *ppiVar4 = (int *)0x0;
      ppiVar4[1] = (int *)0x0;
      return ppiVar4;
    }
    puVar1 = puVar1 + 2;
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  os::OSRestoreInterrupts();
  return (int **)0x0;
}


undefined4 __DVDCheckWaitingQueue(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  os::OSDisableInterrupts();
  iVar2 = 4;
  puVar1 = &WaitingQueue;
  do {
    if ((undefined4 *)*puVar1 != puVar1) {
      os::OSRestoreInterrupts();
      return 1;
    }
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  os::OSRestoreInterrupts();
  return 0;
}


undefined4 __DVDDequeueWaitingQueue(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  os::OSDisableInterrupts();
  piVar2 = (int *)param_1[1];
  iVar3 = *param_1;
  if ((piVar2 == (int *)0x0) || (iVar3 == 0)) {
    os::OSRestoreInterrupts();
    uVar1 = 0;
  }
  else {
    *piVar2 = iVar3;
    *(int **)(iVar3 + 4) = piVar2;
    os::OSRestoreInterrupts();
    uVar1 = 1;
  }
  return uVar1;
}

