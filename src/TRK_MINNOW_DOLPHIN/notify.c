#include <TRK_MINNOW_DOLPHIN/notify.h>
#include <TRK_MINNOW_DOLPHIN/msgbuf.h>
#include <TRK_MINNOW_DOLPHIN/targimpl.h>
#include <TRK_MINNOW_DOLPHIN/support.h>


namespace TRK_MINNOW_DOLPHIN {

int TRKDoNotifyStopped(char param_1)

{
  int iVar1;
  uint uVar2;
  int local_18;
  undefined4 local_14;
  undefined4 local_10 [2];
  
  iVar1 = TRKGetFreeBuffer(&local_14,&local_18);
  if (iVar1 == 0) {
    uVar2 = *(uint *)(local_18 + 0xc);
    if (uVar2 < 0x880) {
      *(uint *)(local_18 + 0xc) = uVar2 + 1;
      iVar1 = 0;
      *(char *)(local_18 + uVar2 + 0x10) = param_1;
      *(int *)(local_18 + 8) = *(int *)(local_18 + 8) + 1;
    }
    else {
      iVar1 = 0x301;
    }
    if (iVar1 == 0) {
      if (param_1 == -0x70) {
        TRKTargetAddStopInfo(local_18);
      }
      else {
        TRKTargetAddExceptionInfo(local_18);
      }
    }
    iVar1 = TRKRequestSend(local_18,local_10,2,3,1);
    if (iVar1 == 0) {
      TRKReleaseBuffer(local_10[0]);
    }
    TRKReleaseBuffer(local_14);
  }
  return iVar1;
}

