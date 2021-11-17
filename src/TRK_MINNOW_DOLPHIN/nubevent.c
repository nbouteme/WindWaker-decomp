#include <TRK_MINNOW_DOLPHIN/nubevent.h>
#include <TRK_MINNOW_DOLPHIN/msgbuf.h>
#include <TRK_MINNOW_DOLPHIN/mutex_TRK.h>


namespace TRK_MINNOW_DOLPHIN {
undefined gTRKEventQueue;

void TRKDestructEvent(int param_1)

{
  TRKReleaseBuffer(*(undefined4 *)(param_1 + 8));
  return;
}


void TRKConstructEvent(undefined *param_1,undefined param_2)

{
  *param_1 = param_2;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0xffffffff;
  return;
}


undefined4 TRKPostEvent(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  TRKAcquireMutex(&gTRKEventQueue);
  if (DAT_803f1f04 == 2) {
    uVar2 = 0x100;
  }
  else {
    iVar1 = DAT_803f1f08 + DAT_803f1f04 >> 0x1f;
    iVar1 = (DAT_803f1f08 + DAT_803f1f04 & 1U ^ -iVar1) + iVar1;
    FUN_80003510(&DAT_803f1f0c + iVar1 * 0xc,param_1,0xc);
    (&DAT_803f1f10)[iVar1 * 3] = DAT_803f1f24;
    DAT_803f1f24 = DAT_803f1f24 + 1;
    if (DAT_803f1f24 < 0x100) {
      DAT_803f1f24 = 0x100;
    }
    DAT_803f1f04 = DAT_803f1f04 + 1;
  }
  TRKReleaseMutex(&gTRKEventQueue);
  return uVar2;
}


undefined4 TRKGetNextEvent(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  TRKAcquireMutex(&gTRKEventQueue);
  if (0 < DAT_803f1f04) {
    FUN_80003510(param_1,&DAT_803f1f0c + DAT_803f1f08 * 0xc,0xc);
    DAT_803f1f08 = DAT_803f1f08 + 1;
    DAT_803f1f04 = DAT_803f1f04 + -1;
    if (DAT_803f1f08 == 2) {
      DAT_803f1f08 = 0;
    }
    uVar1 = 1;
  }
  TRKReleaseMutex(&gTRKEventQueue);
  return uVar1;
}


undefined4 TRKInitializeEventQueue(void)

{
  TRKInitializeMutex(&gTRKEventQueue);
  TRKAcquireMutex(&gTRKEventQueue);
  DAT_803f1f04 = 0;
  DAT_803f1f08 = 0;
  DAT_803f1f24 = 0x100;
  TRKReleaseMutex();
  return 0;
}

