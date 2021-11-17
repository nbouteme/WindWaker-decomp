#include <TRK_MINNOW_DOLPHIN/msghndlr.h>
#include <TRK_MINNOW_DOLPHIN/msgbuf.h>
#include <TRK_MINNOW_DOLPHIN/msg.h>
#include <TRK_MINNOW_DOLPHIN/target_options.h>
#include <TRK_MINNOW_DOLPHIN/targimpl.h>
#include <TRK_MINNOW_DOLPHIN/targcont.h>
#include <TRK_MINNOW_DOLPHIN/nubevent.h>


namespace TRK_MINNOW_DOLPHIN {
undefined4 IsTRKConnected;

void TRKDoSetOption(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined local_18;
  char local_17;
  undefined local_16 [14];
  
  local_16[0] = 0;
  local_17 = '\0';
  local_18 = 0;
  TRKSetBufferPosition(param_1,0);
  iVar1 = TRKReadBuffer1_ui8(param_1,local_16);
  if (iVar1 == 0) {
    iVar1 = TRKReadBuffer1_ui8(param_1,&local_17);
  }
  if (iVar1 == 0) {
    iVar1 = TRKReadBuffer1_ui8(param_1,&local_18);
  }
  if (iVar1 == 0) {
    if (local_17 == '\x01') {
      SetUseSerialIO(local_18);
    }
  }
  else {
    TRKResetBuffer(param_1,1);
    uVar2 = *(uint *)(param_1 + 0xc);
    if (uVar2 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar2 + 1;
      *(undefined *)(param_1 + uVar2 + 0x10) = 0x80;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    uVar2 = *(uint *)(param_1 + 0xc);
    if (uVar2 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar2 + 1;
      *(undefined *)(param_1 + uVar2 + 0x10) = 1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    iVar1 = 3;
    do {
      iVar3 = TRKMessageSend(param_1);
      iVar1 = iVar1 + -1;
      if (iVar3 == 0) break;
    } while (0 < iVar1);
  }
  TRKResetBuffer(param_1,1);
  uVar2 = *(uint *)(param_1 + 0xc);
  if (uVar2 < 0x880) {
    *(uint *)(param_1 + 0xc) = uVar2 + 1;
    *(undefined *)(param_1 + uVar2 + 0x10) = 0x80;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  uVar2 = *(uint *)(param_1 + 0xc);
  if (uVar2 < 0x880) {
    *(uint *)(param_1 + 0xc) = uVar2 + 1;
    *(undefined *)(param_1 + uVar2 + 0x10) = 0;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  iVar1 = 3;
  do {
    iVar3 = TRKMessageSend(param_1);
    iVar1 = iVar1 + -1;
    if (iVar3 == 0) {
      return;
    }
  } while (0 < iVar1);
  return;
}


void TRKDoStop(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined uVar4;
  
  iVar1 = TRKTargetStop();
  if (iVar1 == 0x704) {
    uVar4 = 0x21;
    goto LAB_8033268c;
  }
  if (iVar1 < 0x704) {
    if (iVar1 == 0) {
      uVar4 = 0;
      goto LAB_8033268c;
    }
  }
  else {
    if (iVar1 == 0x706) {
      uVar4 = 0x20;
      goto LAB_8033268c;
    }
    if (iVar1 < 0x706) {
      uVar4 = 0x22;
      goto LAB_8033268c;
    }
  }
  uVar4 = 1;
LAB_8033268c:
  TRKResetBuffer(param_1,1);
  uVar2 = *(uint *)(param_1 + 0xc);
  if (uVar2 < 0x880) {
    *(uint *)(param_1 + 0xc) = uVar2 + 1;
    *(undefined *)(param_1 + uVar2 + 0x10) = 0x80;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  uVar2 = *(uint *)(param_1 + 0xc);
  if (uVar2 < 0x880) {
    *(uint *)(param_1 + 0xc) = uVar2 + 1;
    *(undefined *)(param_1 + uVar2 + 0x10) = uVar4;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  iVar1 = 3;
  do {
    iVar3 = TRKMessageSend(param_1);
    iVar1 = iVar1 + -1;
    if (iVar3 == 0) {
      return;
    }
  } while (0 < iVar1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80332bfc) */
/* WARNING: Removing unreachable block (ram,0x80332818) */

void TRKDoStep(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char local_18;
  byte local_17;
  undefined auStack22 [2];
  uint local_14;
  uint local_10 [2];
  
  if (*(uint *)(param_1 + 8) < 3) {
    TRKResetBuffer(param_1,1);
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 2;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    iVar3 = 3;
    do {
      iVar2 = TRKMessageSend(param_1);
      iVar3 = iVar3 + -1;
      if (iVar2 == 0) {
        return;
      }
    } while (0 < iVar3);
    return;
  }
  TRKSetBufferPosition(param_1,0);
  iVar3 = TRKReadBuffer1_ui8(param_1,auStack22);
  if (iVar3 == 0) {
    iVar3 = TRKReadBuffer1_ui8(param_1,&local_17);
  }
  if (local_17 == 0x10) {
LAB_80332828:
    if (iVar3 == 0) {
      TRKReadBuffer1_ui8(param_1,&local_18);
    }
    if (local_18 == '\0') {
      TRKResetBuffer(param_1,1);
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        *(undefined *)(param_1 + uVar1 + 0x10) = 0x11;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      iVar3 = 3;
      do {
        iVar2 = TRKMessageSend(param_1);
        iVar3 = iVar3 + -1;
        if (iVar2 == 0) {
          return;
        }
      } while (0 < iVar3);
      return;
    }
  }
  else {
    if (local_17 < 0x10) {
      if (local_17 != 1) {
        if (local_17 != 0) goto LAB_80332a30;
        goto LAB_80332828;
      }
    }
    else {
      if (0x11 < local_17) {
LAB_80332a30:
        TRKResetBuffer(param_1,1);
        uVar1 = *(uint *)(param_1 + 0xc);
        if (uVar1 < 0x880) {
          *(uint *)(param_1 + 0xc) = uVar1 + 1;
          *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        }
        uVar1 = *(uint *)(param_1 + 0xc);
        if (uVar1 < 0x880) {
          *(uint *)(param_1 + 0xc) = uVar1 + 1;
          *(undefined *)(param_1 + uVar1 + 0x10) = 0x12;
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        }
        iVar3 = 3;
        do {
          iVar2 = TRKMessageSend(param_1);
          iVar3 = iVar3 + -1;
          if (iVar2 == 0) {
            return;
          }
        } while (0 < iVar3);
        return;
      }
    }
    if (*(int *)(param_1 + 8) != 10) {
      TRKResetBuffer(param_1,1);
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        *(undefined *)(param_1 + uVar1 + 0x10) = 2;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      iVar3 = 3;
      do {
        iVar2 = TRKMessageSend(param_1);
        iVar3 = iVar3 + -1;
        if (iVar2 == 0) {
          return;
        }
      } while (0 < iVar3);
      return;
    }
    if (iVar3 == 0) {
      iVar3 = TRKReadBuffer1_ui32(param_1,local_10);
    }
    if (iVar3 == 0) {
      TRKReadBuffer1_ui32(param_1,&local_14);
    }
    uVar1 = TRKTargetGetPC();
    if ((uVar1 < local_10[0]) || (local_14 < uVar1)) {
      TRKResetBuffer(param_1,1);
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        *(undefined *)(param_1 + uVar1 + 0x10) = 0x11;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      iVar3 = 3;
      do {
        iVar2 = TRKMessageSend(param_1);
        iVar3 = iVar3 + -1;
        if (iVar2 == 0) {
          return;
        }
      } while (0 < iVar3);
      return;
    }
  }
  iVar3 = TRKTargetStopped();
  if (iVar3 == 0) {
    TRKResetBuffer(param_1,1);
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 0x16;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    iVar3 = 3;
    do {
      iVar2 = TRKMessageSend(param_1);
      iVar3 = iVar3 + -1;
      if (iVar2 == 0) {
        return;
      }
    } while (0 < iVar3);
    return;
  }
  TRKResetBuffer(param_1,1);
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 < 0x880) {
    *(uint *)(param_1 + 0xc) = uVar1 + 1;
    *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 < 0x880) {
    *(uint *)(param_1 + 0xc) = uVar1 + 1;
    *(undefined *)(param_1 + uVar1 + 0x10) = 0;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  iVar3 = 3;
  do {
    iVar2 = TRKMessageSend(param_1);
    iVar3 = iVar3 + -1;
    if (iVar2 == 0) break;
  } while (0 < iVar3);
  if (iVar2 != 0) {
    return;
  }
  uVar1 = (uint)local_17;
  if (uVar1 == 0x10) {
LAB_80332c0c:
    uVar1 = countLeadingZeros(0x10 - uVar1);
    TRKTargetSingleStep(local_18,uVar1 >> 5);
  }
  else {
    if (uVar1 < 0x10) {
      if (uVar1 != 1) {
        if (uVar1 != 0) {
          return;
        }
        goto LAB_80332c0c;
      }
    }
    else {
      if (0x11 < uVar1) {
        return;
      }
    }
    uVar1 = countLeadingZeros(0x11 - uVar1);
    TRKTargetStepOutOfRange(local_10[0],local_14,uVar1 >> 5);
  }
  return;
}


void TRKDoContinue(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = TRKTargetStopped();
  if (iVar1 == 0) {
    TRKResetBuffer(param_1,1);
    uVar2 = *(uint *)(param_1 + 0xc);
    if (uVar2 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar2 + 1;
      *(undefined *)(param_1 + uVar2 + 0x10) = 0x80;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    uVar2 = *(uint *)(param_1 + 0xc);
    if (uVar2 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar2 + 1;
      *(undefined *)(param_1 + uVar2 + 0x10) = 0x16;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    iVar1 = 3;
    do {
      iVar3 = TRKMessageSend(param_1);
      iVar1 = iVar1 + -1;
      if (iVar3 == 0) {
        return;
      }
    } while (0 < iVar1);
  }
  else {
    TRKResetBuffer(param_1,1);
    uVar2 = *(uint *)(param_1 + 0xc);
    if (uVar2 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar2 + 1;
      *(undefined *)(param_1 + uVar2 + 0x10) = 0x80;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    uVar2 = *(uint *)(param_1 + 0xc);
    if (uVar2 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar2 + 1;
      *(undefined *)(param_1 + uVar2 + 0x10) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    iVar1 = 3;
    do {
      iVar3 = TRKMessageSend(param_1);
      iVar1 = iVar1 + -1;
      if (iVar3 == 0) break;
    } while (0 < iVar1);
    if (iVar3 == 0) {
      TRKTargetContinue();
    }
  }
  return;
}


void TRKDoFlushCache(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined uVar4;
  undefined local_18;
  undefined auStack23 [3];
  uint local_14;
  uint local_10 [2];
  
  if (*(int *)(param_1 + 8) == 10) {
    TRKSetBufferPosition(param_1,0);
    iVar3 = TRKReadBuffer1_ui8(param_1,auStack23);
    if (iVar3 == 0) {
      iVar3 = TRKReadBuffer1_ui8(param_1,&local_18);
    }
    if (iVar3 == 0) {
      iVar3 = TRKReadBuffer1_ui32(param_1,local_10);
    }
    if (iVar3 == 0) {
      iVar3 = TRKReadBuffer1_ui32(param_1,&local_14);
    }
    if (local_14 < local_10[0]) {
      TRKResetBuffer(param_1,1);
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        *(undefined *)(param_1 + uVar1 + 0x10) = 0x13;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      iVar3 = 3;
      do {
        iVar2 = TRKMessageSend(param_1);
        iVar3 = iVar3 + -1;
        if (iVar2 == 0) {
          return;
        }
      } while (0 < iVar3);
    }
    else {
      if (iVar3 == 0) {
        iVar3 = TRKTargetFlushCache(local_18);
      }
      if (iVar3 == 0) {
        TRKResetBuffer(param_1,1);
        uVar1 = *(uint *)(param_1 + 0xc);
        if (uVar1 < 0x880) {
          *(uint *)(param_1 + 0xc) = uVar1 + 1;
          *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        }
        uVar1 = *(uint *)(param_1 + 0xc);
        if (uVar1 < 0x880) {
          *(uint *)(param_1 + 0xc) = uVar1 + 1;
          *(undefined *)(param_1 + uVar1 + 0x10) = 0;
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        }
      }
      if (iVar3 == 0) {
        iVar3 = 3;
        do {
          iVar2 = TRKMessageSend(param_1);
          iVar3 = iVar3 + -1;
          if (iVar2 == 0) {
            return;
          }
        } while (0 < iVar3);
      }
      else {
        if (iVar3 == 0x703) {
          uVar4 = 0x12;
        }
        else {
          uVar4 = 3;
        }
        TRKResetBuffer(param_1,1);
        uVar1 = *(uint *)(param_1 + 0xc);
        if (uVar1 < 0x880) {
          *(uint *)(param_1 + 0xc) = uVar1 + 1;
          *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        }
        uVar1 = *(uint *)(param_1 + 0xc);
        if (uVar1 < 0x880) {
          *(uint *)(param_1 + 0xc) = uVar1 + 1;
          *(undefined *)(param_1 + uVar1 + 0x10) = uVar4;
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        }
        iVar3 = 3;
        do {
          iVar2 = TRKMessageSend(param_1);
          iVar3 = iVar3 + -1;
          if (iVar2 == 0) {
            return;
          }
        } while (0 < iVar3);
      }
    }
  }
  else {
    TRKResetBuffer(param_1,1);
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 2;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    iVar3 = 3;
    do {
      iVar2 = TRKMessageSend(param_1);
      iVar3 = iVar3 + -1;
      if (iVar2 == 0) {
        return;
      }
    } while (0 < iVar3);
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x8033324c) */

void TRKDoWriteRegisters(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined uVar4;
  byte local_18;
  undefined uStack23;
  ushort local_16;
  ushort local_14 [2];
  undefined auStack16 [8];
  
  if (*(uint *)(param_1 + 8) < 7) {
    TRKResetBuffer(param_1,1);
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 2;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    iVar3 = 3;
    do {
      iVar2 = TRKMessageSend(param_1);
      iVar3 = iVar3 + -1;
      if (iVar2 == 0) {
        return;
      }
    } while (0 < iVar3);
    return;
  }
  TRKSetBufferPosition(param_1,0);
  iVar3 = TRKReadBuffer1_ui8(param_1,&uStack23);
  if (iVar3 == 0) {
    iVar3 = TRKReadBuffer1_ui8(param_1,&local_18);
  }
  if (iVar3 == 0) {
    iVar3 = TRKReadBuffer1_ui16(param_1,local_14);
  }
  if (iVar3 == 0) {
    TRKReadBuffer1_ui16(param_1,&local_16);
  }
  if (local_16 < local_14[0]) {
    TRKResetBuffer(param_1,1);
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 0x14;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    iVar3 = 3;
    do {
      iVar2 = TRKMessageSend(param_1);
      iVar3 = iVar3 + -1;
      if (iVar2 == 0) {
        return;
      }
    } while (0 < iVar3);
    return;
  }
  if (local_18 == 2) {
    iVar3 = TRKTargetAccessExtended1(local_14[0],local_16,param_1,auStack16,0);
  }
  else {
    if (local_18 < 2) {
      if (local_18 == 0) {
        iVar3 = TRKTargetAccessDefault(local_14[0],local_16,param_1,auStack16,0);
      }
      else {
        iVar3 = TRKTargetAccessFP(local_14[0],local_16,param_1,auStack16,0);
      }
    }
    else {
      if (local_18 < 4) {
        iVar3 = TRKTargetAccessExtended2(local_14[0],local_16,param_1,auStack16,0);
      }
      else {
        iVar3 = 0x703;
      }
    }
  }
  if (iVar3 == 0) {
    TRKResetBuffer(param_1,1);
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
  }
  if (iVar3 == 0) {
    iVar3 = 3;
    do {
      iVar2 = TRKMessageSend(param_1);
      iVar3 = iVar3 + -1;
      if (iVar2 == 0) {
        return;
      }
    } while (0 < iVar3);
    return;
  }
  if (iVar3 == 0x703) {
    uVar4 = 0x12;
    goto LAB_803333ac;
  }
  if (iVar3 < 0x703) {
    if (iVar3 == 0x701) {
      uVar4 = 0x14;
      goto LAB_803333ac;
    }
    if (0x700 < iVar3) {
      uVar4 = 0x15;
      goto LAB_803333ac;
    }
    if (iVar3 == 0x302) {
      uVar4 = 2;
      goto LAB_803333ac;
    }
  }
  else {
    if (iVar3 == 0x706) {
      uVar4 = 0x20;
      goto LAB_803333ac;
    }
    if (iVar3 < 0x706) {
      if (iVar3 < 0x705) {
        uVar4 = 0x21;
      }
      else {
        uVar4 = 0x22;
      }
      goto LAB_803333ac;
    }
  }
  uVar4 = 3;
LAB_803333ac:
  TRKResetBuffer(param_1,1);
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 < 0x880) {
    *(uint *)(param_1 + 0xc) = uVar1 + 1;
    *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 < 0x880) {
    *(uint *)(param_1 + 0xc) = uVar1 + 1;
    *(undefined *)(param_1 + uVar1 + 0x10) = uVar4;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  iVar3 = 3;
  do {
    iVar2 = TRKMessageSend(param_1);
    iVar3 = iVar3 + -1;
    if (iVar2 == 0) {
      return;
    }
  } while (0 < iVar3);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80333684) */

void TRKDoReadRegisters(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined uVar5;
  byte local_18;
  undefined uStack23;
  ushort local_16;
  ushort local_14 [2];
  undefined auStack16 [8];
  
  if (*(int *)(param_1 + 8) != 6) {
    TRKResetBuffer(param_1,1);
    uVar2 = *(uint *)(param_1 + 0xc);
    if (uVar2 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar2 + 1;
      *(undefined *)(param_1 + uVar2 + 0x10) = 0x80;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    uVar2 = *(uint *)(param_1 + 0xc);
    if (uVar2 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar2 + 1;
      *(undefined *)(param_1 + uVar2 + 0x10) = 2;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    iVar4 = 3;
    do {
      iVar3 = TRKMessageSend(param_1);
      iVar4 = iVar4 + -1;
      if (iVar3 == 0) {
        return;
      }
    } while (0 < iVar4);
    return;
  }
  TRKSetBufferPosition(param_1,0);
  iVar4 = TRKReadBuffer1_ui8(param_1,&uStack23);
  if (iVar4 == 0) {
    iVar4 = TRKReadBuffer1_ui8(param_1,&local_18);
  }
  if (iVar4 == 0) {
    iVar4 = TRKReadBuffer1_ui16(param_1,local_14);
  }
  if (iVar4 == 0) {
    iVar4 = TRKReadBuffer1_ui16(param_1,&local_16);
  }
  if (local_16 < local_14[0]) {
    TRKResetBuffer(param_1,1);
    uVar2 = *(uint *)(param_1 + 0xc);
    if (uVar2 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar2 + 1;
      *(undefined *)(param_1 + uVar2 + 0x10) = 0x80;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    uVar2 = *(uint *)(param_1 + 0xc);
    if (uVar2 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar2 + 1;
      *(undefined *)(param_1 + uVar2 + 0x10) = 0x14;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    iVar4 = 3;
    do {
      iVar3 = TRKMessageSend(param_1);
      iVar4 = iVar4 + -1;
      if (iVar3 == 0) {
        return;
      }
    } while (0 < iVar4);
    return;
  }
  if (iVar4 == 0) {
    TRKResetBuffer(param_1,1);
    uVar2 = *(uint *)(param_1 + 0xc);
    if (uVar2 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar2 + 1;
      *(undefined *)(param_1 + uVar2 + 0x10) = 0x80;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    uVar2 = *(uint *)(param_1 + 0xc);
    if (uVar2 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar2 + 1;
      *(undefined *)(param_1 + uVar2 + 0x10) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
  }
  bVar1 = local_18 & 7;
  if (bVar1 == 2) {
    iVar4 = TRKTargetAccessExtended1(local_14[0],local_16,param_1,auStack16,1);
  }
  else {
    if (bVar1 < 2) {
      if ((local_18 & 7) == 0) {
        iVar4 = TRKTargetAccessDefault(local_14[0],local_16,param_1,auStack16,1);
      }
      else {
        iVar4 = TRKTargetAccessFP(local_14[0],local_16,param_1,auStack16,1);
      }
    }
    else {
      if (bVar1 < 4) {
        iVar4 = TRKTargetAccessExtended2(local_14[0],local_16,param_1,auStack16,1);
      }
      else {
        iVar4 = 0x703;
      }
    }
  }
  if (iVar4 == 0) {
    iVar4 = 3;
    do {
      iVar3 = TRKMessageSend(param_1);
      iVar4 = iVar4 + -1;
      if (iVar3 == 0) {
        return;
      }
    } while (0 < iVar4);
    return;
  }
  if (iVar4 == 0x704) {
    uVar5 = 0x21;
    goto LAB_80333778;
  }
  if (iVar4 < 0x704) {
    if (iVar4 == 0x702) {
      uVar5 = 0x15;
      goto LAB_80333778;
    }
    if (0x701 < iVar4) {
      uVar5 = 0x12;
      goto LAB_80333778;
    }
    if (0x700 < iVar4) {
      uVar5 = 0x14;
      goto LAB_80333778;
    }
  }
  else {
    if (iVar4 == 0x706) {
      uVar5 = 0x20;
      goto LAB_80333778;
    }
    if (iVar4 < 0x706) {
      uVar5 = 0x22;
      goto LAB_80333778;
    }
  }
  uVar5 = 3;
LAB_80333778:
  TRKResetBuffer(param_1,1);
  uVar2 = *(uint *)(param_1 + 0xc);
  if (uVar2 < 0x880) {
    *(uint *)(param_1 + 0xc) = uVar2 + 1;
    *(undefined *)(param_1 + uVar2 + 0x10) = 0x80;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  uVar2 = *(uint *)(param_1 + 0xc);
  if (uVar2 < 0x880) {
    *(uint *)(param_1 + 0xc) = uVar2 + 1;
    *(undefined *)(param_1 + uVar2 + 0x10) = uVar5;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  iVar4 = 3;
  do {
    iVar3 = TRKMessageSend(param_1);
    iVar4 = iVar4 + -1;
    if (iVar3 == 0) {
      return;
    }
  } while (0 < iVar4);
  return;
}


void TRKDoWriteMemory(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined uVar4;
  byte local_818;
  undefined uStack2071;
  ushort local_816;
  uint local_814;
  undefined4 local_810;
  undefined auStack2060 [2052];
  
  if (*(uint *)(param_1 + 8) < 9) {
    TRKResetBuffer(param_1,1);
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 2;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    iVar3 = 3;
    do {
      iVar2 = TRKMessageSend(param_1);
      iVar3 = iVar3 + -1;
      if (iVar2 == 0) {
        return;
      }
    } while (0 < iVar3);
  }
  else {
    TRKSetBufferPosition(param_1,0);
    iVar3 = TRKReadBuffer1_ui8(param_1,&uStack2071);
    if (iVar3 == 0) {
      iVar3 = TRKReadBuffer1_ui8(param_1,&local_818);
    }
    if (iVar3 == 0) {
      iVar3 = TRKReadBuffer1_ui16(param_1,&local_816);
    }
    if (iVar3 == 0) {
      iVar3 = TRKReadBuffer1_ui32(param_1,&local_810);
    }
    if ((local_818 & 2) == 0) {
      uVar1 = (uint)local_816;
      if ((*(int *)(param_1 + 8) == uVar1 + 8) && (uVar1 < 0x801)) {
        if (iVar3 == 0) {
          local_814 = uVar1;
          iVar3 = TRKReadBuffer(param_1,auStack2060);
          if (iVar3 == 0) {
            iVar3 = TRKTargetAccessMemory(auStack2060,local_810,&local_814,local_818 >> 3 & 1 ^ 1,0)
            ;
          }
          local_816 = (ushort)local_814;
        }
        if (iVar3 == 0) {
          TRKResetBuffer(param_1,1);
          uVar1 = *(uint *)(param_1 + 0xc);
          if (uVar1 < 0x880) {
            *(uint *)(param_1 + 0xc) = uVar1 + 1;
            *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
            *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
          }
          uVar1 = *(uint *)(param_1 + 0xc);
          if (uVar1 < 0x880) {
            *(uint *)(param_1 + 0xc) = uVar1 + 1;
            *(undefined *)(param_1 + uVar1 + 0x10) = 0;
            *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
          }
        }
        if (iVar3 == 0) {
          iVar3 = TRKAppendBuffer1_ui16(param_1,local_816);
        }
        if (iVar3 == 0) {
          iVar3 = 3;
          do {
            iVar2 = TRKMessageSend(param_1);
            iVar3 = iVar3 + -1;
            if (iVar2 == 0) {
              return;
            }
          } while (0 < iVar3);
        }
        else {
          switch(iVar3) {
          case 0x700:
            uVar4 = 0x13;
            break;
          default:
            uVar4 = 3;
            break;
          case 0x702:
            uVar4 = 0x15;
            break;
          case 0x704:
            uVar4 = 0x21;
            break;
          case 0x705:
            uVar4 = 0x22;
            break;
          case 0x706:
            uVar4 = 0x20;
          }
          TRKResetBuffer(param_1,1);
          uVar1 = *(uint *)(param_1 + 0xc);
          if (uVar1 < 0x880) {
            *(uint *)(param_1 + 0xc) = uVar1 + 1;
            *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
            *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
          }
          uVar1 = *(uint *)(param_1 + 0xc);
          if (uVar1 < 0x880) {
            *(uint *)(param_1 + 0xc) = uVar1 + 1;
            *(undefined *)(param_1 + uVar1 + 0x10) = uVar4;
            *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
          }
          iVar3 = 3;
          do {
            iVar2 = TRKMessageSend(param_1);
            iVar3 = iVar3 + -1;
            if (iVar2 == 0) {
              return;
            }
          } while (0 < iVar3);
        }
      }
      else {
        TRKResetBuffer(param_1,1);
        uVar1 = *(uint *)(param_1 + 0xc);
        if (uVar1 < 0x880) {
          *(uint *)(param_1 + 0xc) = uVar1 + 1;
          *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        }
        uVar1 = *(uint *)(param_1 + 0xc);
        if (uVar1 < 0x880) {
          *(uint *)(param_1 + 0xc) = uVar1 + 1;
          *(undefined *)(param_1 + uVar1 + 0x10) = 0x11;
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        }
        iVar3 = 3;
        do {
          iVar2 = TRKMessageSend(param_1);
          iVar3 = iVar3 + -1;
          if (iVar2 == 0) {
            return;
          }
        } while (0 < iVar3);
      }
    }
    else {
      TRKResetBuffer(param_1,1);
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        *(undefined *)(param_1 + uVar1 + 0x10) = 0x12;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      iVar3 = 3;
      do {
        iVar2 = TRKMessageSend(param_1);
        iVar3 = iVar3 + -1;
        if (iVar2 == 0) {
          return;
        }
      } while (0 < iVar3);
    }
  }
  return;
}


void TRKDoReadMemory(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined uVar4;
  byte local_818;
  undefined uStack2071;
  ushort local_816;
  uint local_814;
  undefined4 local_810;
  undefined auStack2060 [2052];
  
  if (*(int *)(param_1 + 8) == 8) {
    TRKSetBufferPosition(param_1,0);
    iVar3 = TRKReadBuffer1_ui8(param_1,&uStack2071);
    if (iVar3 == 0) {
      iVar3 = TRKReadBuffer1_ui8(param_1,&local_818);
    }
    if (iVar3 == 0) {
      iVar3 = TRKReadBuffer1_ui16(param_1,&local_816);
    }
    if (iVar3 == 0) {
      iVar3 = TRKReadBuffer1_ui32(param_1,&local_810);
    }
    if ((local_818 & 2) == 0) {
      if (local_816 < 0x801) {
        TRKResetBuffer(param_1,1);
        uVar1 = *(uint *)(param_1 + 0xc);
        if (uVar1 < 0x880) {
          *(uint *)(param_1 + 0xc) = uVar1 + 1;
          *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        }
        uVar1 = *(uint *)(param_1 + 0xc);
        if (uVar1 < 0x880) {
          *(uint *)(param_1 + 0xc) = uVar1 + 1;
          *(undefined *)(param_1 + uVar1 + 0x10) = 0;
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        }
        if (iVar3 == 0) {
          local_814 = (uint)local_816;
          iVar3 = TRKTargetAccessMemory(auStack2060,local_810,&local_814,local_818 >> 3 & 1 ^ 1,1);
          local_816 = (ushort)local_814;
          if (iVar3 == 0) {
            iVar3 = TRKAppendBuffer1_ui16(param_1,local_814 & 0xffff);
          }
          if (iVar3 == 0) {
            iVar3 = TRKAppendBuffer(param_1,auStack2060,local_814);
          }
        }
        if (iVar3 == 0) {
          iVar3 = 3;
          do {
            iVar2 = TRKMessageSend(param_1);
            iVar3 = iVar3 + -1;
            if (iVar2 == 0) {
              return;
            }
          } while (0 < iVar3);
        }
        else {
          switch(iVar3) {
          case 0x700:
            uVar4 = 0x13;
            break;
          default:
            uVar4 = 3;
            break;
          case 0x702:
            uVar4 = 0x15;
            break;
          case 0x704:
            uVar4 = 0x21;
            break;
          case 0x705:
            uVar4 = 0x22;
            break;
          case 0x706:
            uVar4 = 0x20;
          }
          TRKResetBuffer(param_1,1);
          uVar1 = *(uint *)(param_1 + 0xc);
          if (uVar1 < 0x880) {
            *(uint *)(param_1 + 0xc) = uVar1 + 1;
            *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
            *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
          }
          uVar1 = *(uint *)(param_1 + 0xc);
          if (uVar1 < 0x880) {
            *(uint *)(param_1 + 0xc) = uVar1 + 1;
            *(undefined *)(param_1 + uVar1 + 0x10) = uVar4;
            *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
          }
          iVar3 = 3;
          do {
            iVar2 = TRKMessageSend(param_1);
            iVar3 = iVar3 + -1;
            if (iVar2 == 0) {
              return;
            }
          } while (0 < iVar3);
        }
      }
      else {
        TRKResetBuffer(param_1,1);
        uVar1 = *(uint *)(param_1 + 0xc);
        if (uVar1 < 0x880) {
          *(uint *)(param_1 + 0xc) = uVar1 + 1;
          *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        }
        uVar1 = *(uint *)(param_1 + 0xc);
        if (uVar1 < 0x880) {
          *(uint *)(param_1 + 0xc) = uVar1 + 1;
          *(undefined *)(param_1 + uVar1 + 0x10) = 0x11;
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        }
        iVar3 = 3;
        do {
          iVar2 = TRKMessageSend(param_1);
          iVar3 = iVar3 + -1;
          if (iVar2 == 0) {
            return;
          }
        } while (0 < iVar3);
      }
    }
    else {
      TRKResetBuffer(param_1,1);
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        *(undefined *)(param_1 + uVar1 + 0x10) = 0x12;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      iVar3 = 3;
      do {
        iVar2 = TRKMessageSend(param_1);
        iVar3 = iVar3 + -1;
        if (iVar2 == 0) {
          return;
        }
      } while (0 < iVar3);
    }
  }
  else {
    TRKResetBuffer(param_1,1);
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 2;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    iVar3 = 3;
    do {
      iVar2 = TRKMessageSend(param_1);
      iVar3 = iVar3 + -1;
      if (iVar2 == 0) {
        return;
      }
    } while (0 < iVar3);
  }
  return;
}


void TRKDoCPUType(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined local_18;
  undefined local_17;
  undefined local_16;
  undefined local_15;
  undefined local_14;
  undefined local_13;
  undefined local_12;
  
  if (*(int *)(param_1 + 8) == 1) {
    TRKResetBuffer(param_1,1);
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    iVar3 = TRKTargetCPUType(&local_18);
    if (iVar3 == 0) {
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        iVar3 = 0;
        *(undefined *)(param_1 + uVar1 + 0x10) = local_18;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      else {
        iVar3 = 0x301;
      }
    }
    if (iVar3 == 0) {
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        iVar3 = 0;
        *(undefined *)(param_1 + uVar1 + 0x10) = local_17;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      else {
        iVar3 = 0x301;
      }
    }
    if (iVar3 == 0) {
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        iVar3 = 0;
        *(undefined *)(param_1 + uVar1 + 0x10) = local_16;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      else {
        iVar3 = 0x301;
      }
    }
    if (iVar3 == 0) {
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        iVar3 = 0;
        *(undefined *)(param_1 + uVar1 + 0x10) = local_15;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      else {
        iVar3 = 0x301;
      }
    }
    if (iVar3 == 0) {
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        iVar3 = 0;
        *(undefined *)(param_1 + uVar1 + 0x10) = local_14;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      else {
        iVar3 = 0x301;
      }
    }
    if (iVar3 == 0) {
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        iVar3 = 0;
        *(undefined *)(param_1 + uVar1 + 0x10) = local_13;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      else {
        iVar3 = 0x301;
      }
    }
    if (iVar3 == 0) {
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        iVar3 = 0;
        *(undefined *)(param_1 + uVar1 + 0x10) = local_12;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      else {
        iVar3 = 0x301;
      }
    }
    if (iVar3 == 0) {
      iVar3 = 3;
      do {
        iVar2 = TRKMessageSend(param_1);
        iVar3 = iVar3 + -1;
        if (iVar2 == 0) {
          return;
        }
      } while (0 < iVar3);
    }
    else {
      TRKResetBuffer(param_1,1);
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        *(undefined *)(param_1 + uVar1 + 0x10) = 3;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      iVar3 = 3;
      do {
        iVar2 = TRKMessageSend(param_1);
        iVar3 = iVar3 + -1;
        if (iVar2 == 0) {
          return;
        }
      } while (0 < iVar3);
    }
  }
  else {
    TRKResetBuffer(param_1,1);
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 2;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    iVar3 = 3;
    do {
      iVar2 = TRKMessageSend(param_1);
      iVar3 = iVar3 + -1;
      if (iVar2 == 0) {
        return;
      }
    } while (0 < iVar3);
  }
  return;
}


void TRKDoSupportMask(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined auStack40 [32];
  
  if (*(int *)(param_1 + 8) == 1) {
    TRKResetBuffer(param_1,1);
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    iVar3 = TRKTargetSupportMask(auStack40);
    if (iVar3 == 0) {
      iVar3 = TRKAppendBuffer(param_1,auStack40,0x20);
    }
    if (iVar3 == 0) {
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        iVar3 = 0;
        *(undefined *)(param_1 + uVar1 + 0x10) = 2;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      else {
        iVar3 = 0x301;
      }
    }
    if (iVar3 == 0) {
      iVar3 = 3;
      do {
        iVar2 = TRKMessageSend(param_1);
        iVar3 = iVar3 + -1;
        if (iVar2 == 0) {
          return;
        }
      } while (0 < iVar3);
    }
    else {
      TRKResetBuffer(param_1,1);
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        *(undefined *)(param_1 + uVar1 + 0x10) = 3;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      iVar3 = 3;
      do {
        iVar2 = TRKMessageSend(param_1);
        iVar3 = iVar3 + -1;
        if (iVar2 == 0) {
          return;
        }
      } while (0 < iVar3);
    }
  }
  else {
    TRKResetBuffer(param_1,1);
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 2;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    iVar3 = 3;
    do {
      iVar2 = TRKMessageSend(param_1);
      iVar3 = iVar3 + -1;
      if (iVar2 == 0) {
        return;
      }
    } while (0 < iVar3);
  }
  return;
}


void TRKDoVersions(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined local_18;
  undefined local_17;
  undefined local_16;
  undefined local_15;
  
  if (*(int *)(param_1 + 8) == 1) {
    TRKResetBuffer(param_1,1);
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    iVar3 = TRKTargetVersions(&local_18);
    if (iVar3 == 0) {
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        iVar3 = 0;
        *(undefined *)(param_1 + uVar1 + 0x10) = local_18;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      else {
        iVar3 = 0x301;
      }
    }
    if (iVar3 == 0) {
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        iVar3 = 0;
        *(undefined *)(param_1 + uVar1 + 0x10) = local_17;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      else {
        iVar3 = 0x301;
      }
    }
    if (iVar3 == 0) {
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        iVar3 = 0;
        *(undefined *)(param_1 + uVar1 + 0x10) = local_16;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      else {
        iVar3 = 0x301;
      }
    }
    if (iVar3 == 0) {
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        iVar3 = 0;
        *(undefined *)(param_1 + uVar1 + 0x10) = local_15;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      else {
        iVar3 = 0x301;
      }
    }
    if (iVar3 == 0) {
      iVar3 = 3;
      do {
        iVar2 = TRKMessageSend(param_1);
        iVar3 = iVar3 + -1;
        if (iVar2 == 0) {
          return;
        }
      } while (0 < iVar3);
    }
    else {
      TRKResetBuffer(param_1,1);
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      uVar1 = *(uint *)(param_1 + 0xc);
      if (uVar1 < 0x880) {
        *(uint *)(param_1 + 0xc) = uVar1 + 1;
        *(undefined *)(param_1 + uVar1 + 0x10) = 3;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      iVar3 = 3;
      do {
        iVar2 = TRKMessageSend(param_1);
        iVar3 = iVar3 + -1;
        if (iVar2 == 0) {
          return;
        }
      } while (0 < iVar3);
    }
  }
  else {
    TRKResetBuffer(param_1,1);
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar1 + 1;
      *(undefined *)(param_1 + uVar1 + 0x10) = 2;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    iVar3 = 3;
    do {
      iVar2 = TRKMessageSend(param_1);
      iVar3 = iVar3 + -1;
      if (iVar2 == 0) {
        return;
      }
    } while (0 < iVar3);
  }
  return;
}


undefined4 TRKDoReset(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  TRKResetBuffer(param_1,1);
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 < 0x880) {
    *(uint *)(param_1 + 0xc) = uVar1 + 1;
    *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 < 0x880) {
    *(uint *)(param_1 + 0xc) = uVar1 + 1;
    *(undefined *)(param_1 + uVar1 + 0x10) = 0;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  iVar3 = 3;
  do {
    iVar2 = TRKMessageSend(param_1);
    iVar3 = iVar3 + -1;
    if (iVar2 == 0) break;
  } while (0 < iVar3);
  FUN_80005468();
  return 0;
}


int TRKDoDisconnect(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined auStack40 [28];
  
  IsTRKConnected = 0;
  TRKResetBuffer(param_1,1);
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 < 0x880) {
    *(uint *)(param_1 + 0xc) = uVar1 + 1;
    *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 < 0x880) {
    *(uint *)(param_1 + 0xc) = uVar1 + 1;
    *(undefined *)(param_1 + uVar1 + 0x10) = 0;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  iVar3 = 3;
  do {
    iVar2 = TRKMessageSend(param_1);
    iVar3 = iVar3 + -1;
    if (iVar2 == 0) break;
  } while (0 < iVar3);
  if (iVar2 == 0) {
    TRKConstructEvent(auStack40,1);
    TRKPostEvent(auStack40);
  }
  return iVar2;
}


void TRKDoConnect(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  IsTRKConnected = 1;
  TRKResetBuffer(param_1,1);
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 < 0x880) {
    *(uint *)(param_1 + 0xc) = uVar1 + 1;
    *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 < 0x880) {
    *(uint *)(param_1 + 0xc) = uVar1 + 1;
    *(undefined *)(param_1 + uVar1 + 0x10) = 0;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  iVar3 = 3;
  do {
    iVar2 = TRKMessageSend(param_1);
    iVar3 = iVar3 + -1;
    if (iVar2 == 0) {
      return;
    }
  } while (0 < iVar3);
  return;
}


void TRKDoUnsupported(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  TRKResetBuffer(param_1,1);
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 < 0x880) {
    *(uint *)(param_1 + 0xc) = uVar1 + 1;
    *(undefined *)(param_1 + uVar1 + 0x10) = 0x80;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 < 0x880) {
    *(uint *)(param_1 + 0xc) = uVar1 + 1;
    *(undefined *)(param_1 + uVar1 + 0x10) = 0x10;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  iVar3 = 3;
  do {
    iVar2 = TRKMessageSend(param_1);
    iVar3 = iVar3 + -1;
    if (iVar2 == 0) {
      return;
    }
  } while (0 < iVar3);
  return;
}


void TRKStandardACK(int param_1,undefined param_2,undefined param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  TRKResetBuffer(param_1,1);
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 < 0x880) {
    *(uint *)(param_1 + 0xc) = uVar1 + 1;
    *(undefined *)(param_1 + uVar1 + 0x10) = param_2;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 < 0x880) {
    *(uint *)(param_1 + 0xc) = uVar1 + 1;
    *(undefined *)(param_1 + uVar1 + 0x10) = param_3;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  iVar3 = 3;
  do {
    iVar2 = TRKMessageSend(param_1);
    iVar3 = iVar3 + -1;
    if (iVar2 == 0) {
      return;
    }
  } while (0 < iVar3);
  return;
}


void SetTRKConnected(undefined4 param_1)

{
  IsTRKConnected = param_1;
  return;
}


undefined4 GetTRKConnected(void)

{
  return IsTRKConnected;
}

