#include <card/CARDBios.h>
#include <os/OSThread.h>
#include <exi/EXIBios.h>
#include <os/OSAlarm.h>
#include <card/CARDBios.h>
#include <os/OSInterrupt.h>
#include <os/OSFont.h>
#include <os/OS.h>
#include <dsp/dsp.h>
#include <os/OSReset.h>
#include <card/CARDBlock.h>
#include <card/CARDDir.h>
#include <card/CARDMount.h>


namespace card {
struct CardBlockData __CARDBlock[2];
undefined __CARDDiskNone;
undefined2 __CARDEncode;

void __CARDDefaultApiCallback(void)

{
  return;
}


void __CARDSyncCallback(int param_1)

{
  os::OSWakeupThread(param_1 * 0x110 + -0x7fc0ec74);
  return;
}


void __CARDExtHandler(int card_slot)

{
  code *pcVar1;
  
  if (__CARDBlock[card_slot].mCardMounted != 0) {
    __CARDBlock[card_slot].mCardMounted = 0;
    exi::EXISetExiCallback(card_slot,0);
    os::OSCancelAlarm(card_slot * 0x110 + -0x7fc0ec20);
    pcVar1 = (code *)__CARDBlock[card_slot].mpExtHandler_cb;
    if (pcVar1 != (code *)0x0) {
      __CARDBlock[card_slot].mpExtHandler_cb = (void *)0x0;
      (*pcVar1)(card_slot,0xfffffffd);
    }
    if (__CARDBlock[card_slot].mStatus != CARD_ERROR_BUSY) {
      __CARDBlock[card_slot].mStatus = CARD_ERROR_NOCARD;
    }
    pcVar1 = (code *)__CARDBlock[card_slot].mpDetatch_cb;
    if ((pcVar1 != (code *)0x0) && (6 < (int)__CARDBlock[card_slot].mCurrBlock)) {
      __CARDBlock[card_slot].mpDetatch_cb = (void *)0x0;
      (*pcVar1)(card_slot,0xfffffffd);
    }
  }
  return;
}


void __CARDExiHandler(int param_1)

{
  code *pcVar1;
  int iVar2;
  card_errors cVar3;
  byte local_18 [12];
  
  os::OSCancelAlarm(param_1 * 0x110 + -0x7fc0ec20);
  if (__CARDBlock[param_1].mCardMounted == 0) {
    return;
  }
  iVar2 = exi::EXILock(param_1,0,0);
  if (iVar2 == 0) {
    cVar3 = CARD_ERROR_FATAL_ERROR;
  }
  else {
    cVar3 = __CARDReadStatus(param_1,local_18);
    if ((-1 < (int)cVar3) && (cVar3 = __CARDClearStatus(param_1), -1 < (int)cVar3)) {
      if ((local_18[0] & 0x18) == 0) {
        cVar3 = CARD_ERROR_READY;
      }
      else {
        cVar3 = CARD_ERROR_IOERROR;
      }
      if ((cVar3 == CARD_ERROR_IOERROR) &&
         (iVar2 = *(int *)&__CARDBlock[param_1].field_0xa8 + -1,
         *(int *)&__CARDBlock[param_1].field_0xa8 = iVar2, 0 < iVar2)) {
        cVar3 = Retry(param_1);
        if (-1 < (int)cVar3) {
          return;
        }
        goto LAB_80319850;
      }
    }
    exi::EXIUnlock(param_1);
  }
LAB_80319850:
  pcVar1 = (code *)__CARDBlock[param_1].mpExtHandler_cb;
  if (pcVar1 != (code *)0x0) {
    __CARDBlock[param_1].mpExtHandler_cb = (void *)0x0;
    (*pcVar1)(param_1,cVar3);
  }
  return;
}


void __CARDTxHandler(int param_1)

{
  bool bVar1;
  uint uVar2;
  code *pcVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar4 = exi::EXIDeselect(param_1);
  uVar2 = countLeadingZeros(uVar4);
  exi::EXIUnlock(param_1);
  pcVar3 = (code *)__CARDBlock[param_1].mpRead_cb;
  if (pcVar3 != (code *)0x0) {
    bVar1 = false;
    __CARDBlock[param_1].mpRead_cb = (void *)0x0;
    if ((uVar2 >> 5 == 0) && (iVar5 = exi::EXIProbe(param_1), iVar5 != 0)) {
      bVar1 = true;
    }
    if (bVar1) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0xfffffffd;
    }
    (*pcVar3)(param_1,uVar4);
  }
  return;
}


void __CARDUnlockedHandler(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  pcVar1 = (code *)__CARDBlock[param_1].mpCardMount_cb;
  if (pcVar1 != (code *)0x0) {
    __CARDBlock[param_1].mpCardMount_cb = (void *)0x0;
    iVar2 = exi::EXIProbe(param_1);
    if (iVar2 == 0) {
      uVar3 = 0xfffffffd;
    }
    else {
      uVar3 = 1;
    }
    (*pcVar1)(param_1,uVar3);
  }
  return;
}


card_errors __CARDEnableInterrupt(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  card_errors cVar5;
  undefined4 uVar6;
  undefined4 local_10 [2];
  
  iVar4 = exi::EXISelect(param_1,0,4);
  if (iVar4 == 0) {
    cVar5 = CARD_ERROR_NOCARD;
  }
  else {
    if (param_2 == 0) {
      local_10[0] = 0x81000000;
    }
    else {
      local_10[0] = 0x81010000;
    }
    uVar6 = exi::EXIImm(param_1,local_10,2,1,0);
    uVar1 = countLeadingZeros(uVar6);
    uVar6 = exi::EXISync(param_1);
    uVar2 = countLeadingZeros(uVar6);
    uVar6 = exi::EXIDeselect(param_1);
    uVar3 = countLeadingZeros(uVar6);
    if ((uVar1 | uVar2 | uVar3) >> 5 == 0) {
      cVar5 = CARD_ERROR_READY;
    }
    else {
      cVar5 = CARD_ERROR_NOCARD;
    }
  }
  return cVar5;
}


card_errors __CARDReadStatus(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  card_errors cVar7;
  undefined4 uVar8;
  undefined4 local_18 [3];
  
  iVar6 = exi::EXISelect(param_1,0,4);
  if (iVar6 == 0) {
    cVar7 = CARD_ERROR_NOCARD;
  }
  else {
    local_18[0] = 0x83000000;
    uVar8 = exi::EXIImm(param_1,local_18,2,1,0);
    uVar1 = countLeadingZeros(uVar8);
    uVar8 = exi::EXISync(param_1);
    uVar2 = countLeadingZeros(uVar8);
    uVar8 = exi::EXIImm(param_1,param_2,1,0,0);
    uVar3 = countLeadingZeros(uVar8);
    uVar8 = exi::EXISync(param_1);
    uVar4 = countLeadingZeros(uVar8);
    uVar8 = exi::EXIDeselect(param_1);
    uVar5 = countLeadingZeros(uVar8);
    if ((uVar1 | uVar2 | uVar3 | uVar4 | uVar5) >> 5 == 0) {
      cVar7 = CARD_ERROR_READY;
    }
    else {
      cVar7 = CARD_ERROR_NOCARD;
    }
  }
  return cVar7;
}


card_errors __CARDClearStatus(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  card_errors cVar5;
  undefined4 uVar6;
  undefined4 local_c;
  
  iVar4 = exi::EXISelect(param_1,0,4);
  if (iVar4 == 0) {
    cVar5 = CARD_ERROR_NOCARD;
  }
  else {
    local_c = 0x89000000;
    uVar6 = exi::EXIImm(param_1,&local_c,1,1,0);
    uVar1 = countLeadingZeros(uVar6);
    uVar6 = exi::EXISync(param_1);
    uVar2 = countLeadingZeros(uVar6);
    uVar6 = exi::EXIDeselect(param_1);
    uVar3 = countLeadingZeros(uVar6);
    if ((uVar1 | uVar2 | uVar3) >> 5 == 0) {
      cVar5 = CARD_ERROR_READY;
    }
    else {
      cVar5 = CARD_ERROR_NOCARD;
    }
  }
  return cVar5;
}


void TimeoutHandler(int param_1)

{
  code *pcVar1;
  CardBlockData *pCVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  pCVar2 = __CARDBlock;
  if (param_1 != -0x7fc0ec20) {
    uVar3 = 1;
    pCVar2 = __CARDBlock + 1;
    if (param_1 != -0x7fc0eb10) {
      uVar3 = 2;
      pCVar2 = __CARDBlock + 1;
    }
  }
  if (pCVar2->mCardMounted != 0) {
    exi::EXISetExiCallback(uVar3,0);
    pcVar1 = (code *)pCVar2->mpExtHandler_cb;
    if (pcVar1 != (code *)0x0) {
      pCVar2->mpExtHandler_cb = (void *)0x0;
      (*pcVar1)(uVar3,0xfffffffb);
    }
  }
  return;
}


/* WARNING: Type propagation algorithm not settling */

undefined4 Retry(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar4 = param_1 * 0x110;
  iVar2 = exi::EXISelect(param_1,0,4);
  if (iVar2 == 0) {
    exi::EXIUnlock(param_1);
    return 0xfffffffd;
  }
  os::OSCancelAlarm(iVar4 + -0x7fc0ec20);
  bVar1 = __CARDBlock[param_1].mFlags[0];
  if (bVar1 != 0xf3) {
    if (bVar1 < 0xf3) {
      if (bVar1 != 0xf1) {
        if (0xf0 < bVar1) {
          os::OSSetAlarm(iVar4 + -0x7fc0ec20,0x10624dd3,0,((DAT_800000f8 >> 2) / 1000) * 100,
                         TimeoutHandler);
        }
        goto LAB_80319de0;
      }
    }
    else {
      if (0xf4 < bVar1) goto LAB_80319de0;
    }
    uVar5 = __CARDBlock[param_1].mDataSize;
    uVar6 = (DAT_800000f8 >> 2) * 2;
    uVar5 = ((int)uVar5 >> 0xd) + (uint)((int)uVar5 < 0 && (uVar5 & 0x1fff) != 0);
    iVar2 = ((int)uVar5 >> 0x1f) * uVar6 + (int)((ulonglong)uVar5 * (ulonglong)uVar6 >> 0x20);
    os::OSSetAlarm(iVar4 + -0x7fc0ec20,iVar2,iVar2,uVar5 * uVar6,TimeoutHandler);
  }
LAB_80319de0:
  iVar2 = exi::EXIImmEx(param_1,iVar4 + -0x7fc0ec6c,__CARDBlock[param_1].field_0xa0,1);
  if (iVar2 == 0) {
    exi::EXIDeselect(param_1);
    exi::EXIUnlock(param_1);
    uVar3 = 0xfffffffd;
  }
  else {
    if ((__CARDBlock[param_1].mFlags[0] == 0x52) &&
       (iVar2 = exi::EXIImmEx(param_1,((__CARDBlock[param_1].mCard_block.mpWorkarea)->mHeaderData).
                                      mDirEntries + 8,__CARDBlock[param_1].field_0x14,1), iVar2 == 0
       )) {
      exi::EXIDeselect(param_1);
      exi::EXIUnlock(param_1);
      uVar3 = 0xfffffffd;
    }
    else {
      if (*(int *)&__CARDBlock[param_1].field_0xa4 == -1) {
        exi::EXIDeselect(param_1);
        exi::EXIUnlock(param_1);
        uVar3 = 0;
      }
      else {
        if (__CARDBlock[param_1].mFlags[0] == 0x52) {
          uVar3 = 0x200;
        }
        else {
          uVar3 = 0x80;
        }
        iVar2 = exi::EXIDma(param_1,__CARDBlock[param_1].mpBuffer,uVar3,
                            *(undefined4 *)&__CARDBlock[param_1].field_0xa4,__CARDTxHandler);
        if (iVar2 == 0) {
          exi::EXIDeselect(param_1);
          exi::EXIUnlock(param_1);
          uVar3 = 0xfffffffd;
        }
        else {
          uVar3 = 0;
        }
      }
    }
  }
  return uVar3;
}


void UnlockedCallback(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  code *pcVar3;
  
  if (-1 < param_2) {
    __CARDBlock[param_1].mpCardMount_cb = UnlockedCallback;
    iVar2 = exi::EXILock(param_1,0,__CARDUnlockedHandler);
    if (iVar2 == 0) {
      param_2 = 0;
    }
    else {
      __CARDBlock[param_1].mpCardMount_cb = (void *)0x0;
      param_2 = Retry(param_1);
    }
  }
  if (param_2 < 0) {
    bVar1 = __CARDBlock[param_1].mFlags[0];
    if (bVar1 != 0xf3) {
      if (bVar1 < 0xf3) {
        if (bVar1 == 0x52) {
          pcVar3 = (code *)__CARDBlock[param_1].mpRead_cb;
          if (pcVar3 == (code *)0x0) {
            return;
          }
          __CARDBlock[param_1].mpRead_cb = (void *)0x0;
          (*pcVar3)(param_1);
          return;
        }
        if (bVar1 < 0x52) {
          return;
        }
        if (bVar1 < 0xf1) {
          return;
        }
      }
      else {
        if (0xf4 < bVar1) {
          return;
        }
      }
      pcVar3 = (code *)__CARDBlock[param_1].mpExtHandler_cb;
      if (pcVar3 != (code *)0x0) {
        __CARDBlock[param_1].mpExtHandler_cb = (void *)0x0;
        (*pcVar3)(param_1);
      }
    }
  }
  return;
}


card_errors __CARDStart(int card_slot,void *read_callback,void *ext_handler)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  card_errors cVar7;
  
  uVar2 = os::OSDisableInterrupts();
  iVar5 = card_slot * 0x110;
  if (__CARDBlock[card_slot].mCardMounted == 0) {
    cVar7 = CARD_ERROR_NOCARD;
    goto LAB_8031a190;
  }
  if (read_callback != (void *)0x0) {
    __CARDBlock[card_slot].mpRead_cb = read_callback;
  }
  if (ext_handler != (void *)0x0) {
    __CARDBlock[card_slot].mpExtHandler_cb = ext_handler;
  }
  __CARDBlock[card_slot].mpCardMount_cb = UnlockedCallback;
  iVar3 = exi::EXILock(card_slot,0,__CARDUnlockedHandler);
  if (iVar3 == 0) {
    cVar7 = CARD_ERROR_BUSY;
    goto LAB_8031a190;
  }
  __CARDBlock[card_slot].mpCardMount_cb = (void *)0x0;
  iVar3 = exi::EXISelect(card_slot,0,4);
  if (iVar3 == 0) {
    exi::EXIUnlock(card_slot);
    cVar7 = CARD_ERROR_NOCARD;
    goto LAB_8031a190;
  }
  os::OSCancelAlarm(iVar5 + -0x7fc0ec20);
  bVar1 = __CARDBlock[card_slot].mFlags[0];
  if (bVar1 != 0xf3) {
    if (bVar1 < 0xf3) {
      if (bVar1 == 0xf1) {
LAB_8031a128:
        uVar4 = __CARDBlock[card_slot].mDataSize;
        uVar6 = (DAT_800000f8 >> 2) * 2;
        uVar4 = ((int)uVar4 >> 0xd) + (uint)((int)uVar4 < 0 && (uVar4 & 0x1fff) != 0);
        iVar3 = ((int)uVar4 >> 0x1f) * uVar6 + (int)((ulonglong)uVar4 * (ulonglong)uVar6 >> 0x20);
        os::OSSetAlarm(iVar5 + -0x7fc0ec20,iVar3,iVar3,uVar4 * uVar6,TimeoutHandler);
      }
      else {
        if (0xf0 < bVar1) {
          os::OSSetAlarm(iVar5 + -0x7fc0ec20,0x10624dd3,0,((DAT_800000f8 >> 2) / 1000) * 100,
                         TimeoutHandler);
        }
      }
    }
    else {
      if (bVar1 < 0xf5) goto LAB_8031a128;
    }
  }
  cVar7 = CARD_ERROR_READY;
LAB_8031a190:
  os::OSRestoreInterrupts(uVar2);
  return cVar7;
}


card_errors __CARDReadSegment(int card_slot,void *read_callback)

{
  card_errors cVar1;
  int iVar2;
  
  __CARDBlock[card_slot].mFlags[0] = 0x52;
  __CARDBlock[card_slot].mFlags[1] = (byte)((uint)__CARDBlock[card_slot].mDataLen >> 0x11) & 0x7f;
  __CARDBlock[card_slot].mFlags[2] = (byte)((uint)__CARDBlock[card_slot].mDataLen >> 9);
  __CARDBlock[card_slot].mFlags[3] = (byte)((uint)__CARDBlock[card_slot].mDataLen >> 7) & 3;
  __CARDBlock[card_slot].mFlags[4] = (byte)__CARDBlock[card_slot].mDataLen & 0x7f;
  __CARDBlock[card_slot].field_0xa0 = 5;
  *(undefined4 *)&__CARDBlock[card_slot].field_0xa4 = 0;
  *(undefined4 *)&__CARDBlock[card_slot].field_0xa8 = 0;
  cVar1 = __CARDStart(card_slot,read_callback,0);
  if (cVar1 == CARD_ERROR_BUSY) {
    cVar1 = CARD_ERROR_READY;
  }
  else {
    if (-1 < (int)cVar1) {
      iVar2 = exi::EXIImmEx(card_slot,card_slot * 0x110 + -0x7fc0ec6c,
                            __CARDBlock[card_slot].field_0xa0,1);
      if (((iVar2 == 0) ||
          (iVar2 = exi::EXIImmEx(card_slot,
                                 ((__CARDBlock[card_slot].mCard_block.mpWorkarea)->mHeaderData).
                                 mDirEntries + 8,__CARDBlock[card_slot].field_0x14,1), iVar2 == 0))
         || (iVar2 = exi::EXIDma(card_slot,__CARDBlock[card_slot].mpBuffer,0x200,
                                 *(undefined4 *)&__CARDBlock[card_slot].field_0xa4,__CARDTxHandler),
            iVar2 == 0)) {
        __CARDBlock[card_slot].mpRead_cb = (void *)0x0;
        exi::EXIDeselect(card_slot);
        exi::EXIUnlock(card_slot);
        cVar1 = CARD_ERROR_NOCARD;
      }
      else {
        cVar1 = CARD_ERROR_READY;
      }
    }
  }
  return cVar1;
}


card_errors __CARDWritePage(int card_slot,undefined4 param_2)

{
  card_errors cVar1;
  int iVar2;
  
  __CARDBlock[card_slot].mFlags[0] = 0xf2;
  __CARDBlock[card_slot].mFlags[1] = (byte)((uint)__CARDBlock[card_slot].mDataLen >> 0x11) & 0x7f;
  __CARDBlock[card_slot].mFlags[2] = (byte)((uint)__CARDBlock[card_slot].mDataLen >> 9);
  __CARDBlock[card_slot].mFlags[3] = (byte)((uint)__CARDBlock[card_slot].mDataLen >> 7) & 3;
  __CARDBlock[card_slot].mFlags[4] = (byte)__CARDBlock[card_slot].mDataLen & 0x7f;
  __CARDBlock[card_slot].field_0xa0 = 5;
  *(undefined4 *)&__CARDBlock[card_slot].field_0xa4 = 1;
  *(undefined4 *)&__CARDBlock[card_slot].field_0xa8 = 3;
  cVar1 = __CARDStart(card_slot,(void *)0x0,param_2);
  if (cVar1 == CARD_ERROR_BUSY) {
    cVar1 = CARD_ERROR_READY;
  }
  else {
    if (-1 < (int)cVar1) {
      iVar2 = exi::EXIImmEx(card_slot,card_slot * 0x110 + -0x7fc0ec6c,
                            __CARDBlock[card_slot].field_0xa0,1);
      if ((iVar2 == 0) ||
         (iVar2 = exi::EXIDma(card_slot,__CARDBlock[card_slot].mpBuffer,0x80,
                              *(undefined4 *)&__CARDBlock[card_slot].field_0xa4,__CARDTxHandler),
         iVar2 == 0)) {
        __CARDBlock[card_slot].mpExtHandler_cb = (void *)0x0;
        exi::EXIDeselect(card_slot);
        exi::EXIUnlock(card_slot);
        cVar1 = CARD_ERROR_NOCARD;
      }
      else {
        cVar1 = CARD_ERROR_READY;
      }
    }
  }
  return cVar1;
}


card_errors __CARDEraseSector(int card_slot,uint len,void *ext_handler)

{
  card_errors cVar1;
  int iVar2;
  
  __CARDBlock[card_slot].mFlags[0] = 0xf1;
  __CARDBlock[card_slot].mFlags[1] = (byte)(len >> 0x11) & 0x7f;
  __CARDBlock[card_slot].mFlags[2] = (byte)(len >> 9);
  __CARDBlock[card_slot].field_0xa0 = 3;
  *(undefined4 *)&__CARDBlock[card_slot].field_0xa4 = 0xffffffff;
  *(undefined4 *)&__CARDBlock[card_slot].field_0xa8 = 3;
  cVar1 = __CARDStart(card_slot,(void *)0x0,ext_handler);
  if (cVar1 == CARD_ERROR_BUSY) {
    cVar1 = CARD_ERROR_READY;
  }
  else {
    if (-1 < (int)cVar1) {
      iVar2 = exi::EXIImmEx(card_slot,card_slot * 0x110 + -0x7fc0ec6c,
                            __CARDBlock[card_slot].field_0xa0,1);
      if (iVar2 == 0) {
        __CARDBlock[card_slot].mpExtHandler_cb = (void *)0x0;
        cVar1 = CARD_ERROR_NOCARD;
      }
      else {
        cVar1 = CARD_ERROR_READY;
      }
      exi::EXIDeselect(card_slot);
      exi::EXIUnlock(card_slot);
    }
  }
  return cVar1;
}


/* WARNING: Unknown calling convention yet parameter storage is locked */

card_errors CARDInit(void)

{
  undefined *puVar1;
  int iVar2;
  CardBlockData *pCVar3;
  
  puVar1 = &DAT_803f0000;
  pCVar3 = __CARDBlock;
  if ((__CARDBlock[0].mpDiskID == (char *)0x0) || (__CARDBlock[1].mpDiskID == (char *)0x0)) {
    __CARDEncode = os::OSGetFontEncode();
    os::OSRegisterVersion(__CARDVersion);
    dsp::DSPInit();
    os::OSInitAlarm();
    iVar2 = 0;
    do {
      pCVar3->mStatus = CARD_ERROR_NOCARD;
      os::OSInitThreadQueue(&(pCVar3->mCard_block).field_0x5e);
      os::OSCreateAlarm(&pCVar3->field_0xe0);
      iVar2 = iVar2 + 1;
      pCVar3 = pCVar3 + 1;
    } while (iVar2 < 2);
    __CARDSetDiskID(0x80000000);
    puVar1 = (undefined *)os::OSRegisterResetFunction(&ResetFunctionInfo);
  }
  return (card_errors)puVar1;
}


undefined2 __CARDGetFontEncode(void)

{
  return __CARDEncode;
}


void __CARDSetDiskID(char *param_1)

{
  if (param_1 == (char *)0x0) {
    param_1 = &__CARDDiskNone;
  }
  __CARDBlock[0].mpDiskID = param_1;
  __CARDBlock[1].mpDiskID = param_1;
  return;
}


card_errors __CARDGetControlBlock(int card_slot,CardBlockData **param_2)

{
  card_errors cVar1;
  
  if (((card_slot < 0) || (1 < card_slot)) || (__CARDBlock[card_slot].mpDiskID == (char *)0x0)) {
    cVar1 = CARD_ERROR_FATAL_ERROR;
  }
  else {
    os::OSDisableInterrupts();
    if (__CARDBlock[card_slot].mCardMounted == 0) {
      cVar1 = CARD_ERROR_NOCARD;
    }
    else {
      if (__CARDBlock[card_slot].mStatus == CARD_ERROR_BUSY) {
        cVar1 = CARD_ERROR_BUSY;
      }
      else {
        __CARDBlock[card_slot].mStatus = CARD_ERROR_BUSY;
        cVar1 = CARD_ERROR_READY;
        __CARDBlock[card_slot].mpAttach_cb = (void *)0x0;
        *param_2 = __CARDBlock + card_slot;
      }
    }
    os::OSRestoreInterrupts();
  }
  return cVar1;
}


card_errors __CARDPutControlBlock(CardBlockData *param_1,card_errors param_2)

{
  os::OSDisableInterrupts();
  if (param_1->mCardMounted == 0) {
    if (param_1->mStatus == CARD_ERROR_BUSY) {
      param_1->mStatus = param_2;
    }
  }
  else {
    param_1->mStatus = param_2;
  }
  os::OSRestoreInterrupts();
  return param_2;
}


card_errors CARDFreeBlocks(int card_slot,CARDFileInfo *param_2,int *out__card_block_count)

{
  card_errors cVar1;
  card_fat_block *iVar2;
  card_direntry *pcVar2;
  ushort uVar3;
  CardBlockData *local_18 [3];
  
  cVar1 = __CARDGetControlBlock(card_slot,local_18);
  if (-1 < (int)cVar1) {
    iVar2 = (card_fat_block *)__CARDGetFatBlock(local_18[0]);
    pcVar2 = __CARDGetDirBlock(local_18[0]);
    if ((iVar2 == (card_fat_block *)0x0) || (pcVar2 == (card_direntry *)0x0)) {
      os::OSDisableInterrupts();
      if (local_18[0]->mCardMounted == 0) {
        if (local_18[0]->mStatus == CARD_ERROR_BUSY) {
          local_18[0]->mStatus = CARD_ERROR_BROKEN;
        }
      }
      else {
        local_18[0]->mStatus = CARD_ERROR_BROKEN;
      }
      os::OSRestoreInterrupts();
      cVar1 = CARD_ERROR_BROKEN;
    }
    else {
      if (param_2 != (CARDFileInfo *)0x0) {
        param_2->mSlot = local_18[0]->mDataSize * (uint)(ushort)iVar2->mFreeblocks;
      }
      if (out__card_block_count != (int *)0x0) {
        *out__card_block_count = 0;
        for (uVar3 = 0; uVar3 < 0x7f; uVar3 = uVar3 + 1) {
          if (pcVar2->mFilename[0] == -1) {
            *out__card_block_count = *out__card_block_count + 1;
          }
          pcVar2 = pcVar2 + 1;
        }
      }
      os::OSDisableInterrupts();
      if (local_18[0]->mCardMounted == 0) {
        if (local_18[0]->mStatus == CARD_ERROR_BUSY) {
          local_18[0]->mStatus = CARD_ERROR_READY;
        }
      }
      else {
        local_18[0]->mStatus = CARD_ERROR_READY;
      }
      os::OSRestoreInterrupts();
      cVar1 = CARD_ERROR_READY;
    }
  }
  return cVar1;
}


card_errors __CARDSync(int card_slot)

{
  card_errors cVar1;
  undefined4 uVar2;
  
  uVar2 = os::OSDisableInterrupts();
  while( true ) {
    if ((card_slot < 0) || (1 < card_slot)) {
      cVar1 = CARD_ERROR_FATAL_ERROR;
    }
    else {
      cVar1 = __CARDBlock[card_slot].mStatus;
    }
    if (cVar1 != CARD_ERROR_BUSY) break;
    os::OSSleepThread(card_slot * 0x110 + -0x7fc0ec74);
  }
  os::OSRestoreInterrupts(uVar2);
  return cVar1;
}


card_errors OnReset(int param_1)

{
  card_errors cVar1;
  
  if ((param_1 == 0) &&
     ((cVar1 = CARDUnmount(0), cVar1 == CARD_ERROR_BUSY ||
      (cVar1 = CARDUnmount(1), cVar1 == CARD_ERROR_BUSY)))) {
    cVar1 = CARD_ERROR_READY;
  }
  else {
    cVar1 = CARD_ERROR_UNLOCKED;
  }
  return cVar1;
}

