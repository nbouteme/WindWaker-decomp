#include <TRK_MINNOW_DOLPHIN/serpoll.h>
#include <TRK_MINNOW_DOLPHIN/nubevent.h>
#include <TRK_MINNOW_DOLPHIN/serpoll.h>
#include <TRK_MINNOW_DOLPHIN/msgbuf.h>
#include <TRK_MINNOW_DOLPHIN/dolphin_trk_glue.h>
#include <TRK_MINNOW_DOLPHIN/msghndlr.h>


namespace TRK_MINNOW_DOLPHIN {
undefined4 gTRKInputPendingPtr;
undefined4 gTRKFramingState;

undefined4 TRKTerminateSerialHandler(void)

{
  return 0;
}


undefined4 TRKInitializeSerialHandler(void)

{
  gTRKFramingState = 0xffffffff;
  DAT_803f38ec = 0;
  DAT_803f38f0 = 0;
  return 0;
}


void TRKProcessInput(undefined4 param_1)

{
  undefined auStack24 [8];
  undefined4 local_10;
  
  TRKConstructEvent(auStack24,2);
  gTRKFramingState = 0xffffffff;
  local_10 = param_1;
  TRKPostEvent(auStack24);
  return;
}


void TRKGetInput(void)

{
  undefined4 uVar1;
  byte local_18 [4];
  undefined auStack20 [8];
  int local_c;
  
  local_c = TRKTestForPacket();
  if (local_c != -1) {
    uVar1 = TRKGetBuffer();
    TRKSetBufferPosition(uVar1,0);
    TRKReadBuffer1_ui8(uVar1,local_18);
    if (local_18[0] < 0x80) {
      TRKConstructEvent(auStack20,2);
      gTRKFramingState = 0xffffffff;
      TRKPostEvent(auStack20);
    }
    else {
      TRKReleaseBuffer(local_c);
    }
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x80332104) */

int TRKTestForPacket(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte local_18 [12];
  
  iVar5 = 0;
  iVar3 = TRKReadUARTPoll(local_18);
  do {
    iVar2 = DAT_803f38e8;
    if ((iVar3 != 0) || (iVar5 != 0)) {
      return -1;
    }
    if (DAT_803f38ec != 2) {
      DAT_803f38f0 = 0;
    }
    if (DAT_803f38ec == 2) {
LAB_8033215c:
      if (local_18[0] == 0x7e) {
        if (DAT_803f38f0 == 0) {
          if (*(uint *)(DAT_803f38e8 + 8) < 2) {
            TRKStandardACK(DAT_803f38e8,0xff,2);
            if (gTRKFramingState != -1) {
              TRKReleaseBuffer();
              gTRKFramingState = -1;
            }
            bVar1 = false;
            DAT_803f38e8 = 0;
          }
          else {
            bVar1 = true;
            *(undefined4 *)(DAT_803f38e8 + 0xc) = 0;
            *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + -1;
          }
          if (bVar1) {
            iVar5 = gTRKFramingState;
            gTRKFramingState = 0xffffffff;
            DAT_803f38e8 = 0;
            DAT_803f38ec = 0;
            return iVar5;
          }
          DAT_803f38ec = 0;
        }
        else {
          TRKStandardACK(DAT_803f38e8,0xff,4);
          if (gTRKFramingState != -1) {
            TRKReleaseBuffer();
            gTRKFramingState = -1;
          }
          DAT_803f38e8 = 0;
          DAT_803f38ec = 0;
        }
      }
      else {
        if (DAT_803f38f0 == 0) {
          if (local_18[0] == 0x7d) {
            DAT_803f38f0 = 1;
            goto LAB_80332320;
          }
        }
        else {
          local_18[0] = local_18[0] ^ 0x20;
          DAT_803f38f0 = 0;
        }
        uVar4 = *(uint *)(DAT_803f38e8 + 0xc);
        if (uVar4 < 0x880) {
          *(uint *)(DAT_803f38e8 + 0xc) = uVar4 + 1;
          iVar5 = 0;
          *(byte *)(iVar2 + uVar4 + 0x10) = local_18[0];
          *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;
        }
        else {
          iVar5 = 0x301;
        }
        DAT_803f38f4 = DAT_803f38f4 + local_18[0];
      }
    }
    else {
      if (DAT_803f38ec < 2) {
        if (DAT_803f38ec == 0) {
          if (local_18[0] == 0x7e) {
            iVar5 = TRKGetFreeBuffer(&gTRKFramingState,&DAT_803f38e8);
            DAT_803f38f4 = '\0';
            DAT_803f38ec = 1;
          }
        }
        else {
          if (local_18[0] != 0x7e) {
            DAT_803f38ec = 2;
            goto LAB_8033215c;
          }
        }
      }
      else {
        if ((DAT_803f38ec < 4) && (local_18[0] == 0x7e)) {
          if (gTRKFramingState != -1) {
            TRKReleaseBuffer();
            gTRKFramingState = -1;
          }
          DAT_803f38e8 = 0;
          DAT_803f38ec = 0;
        }
      }
    }
LAB_80332320:
    iVar3 = TRKReadUARTPoll(local_18);
  } while( true );
}

