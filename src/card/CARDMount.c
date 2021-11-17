#include <card/CARDMount.h>
#include <exi/EXIBios.h>
#include <os/OSInterrupt.h>
#include <card/CARDMount.h>
#include <card/CARDBios.h>
#include <card/CARDUnlock.h>
#include <os/OSRtc.h>
#include <os/OSCache.h>
#include <card/CARDRdwr.h>
#include <card/CARDCheck.h>
#include <os/OSAlarm.h>


namespace card {

bool IsCard(undefined1 *param_1)

{
  uint uVar1;
  
  if ((((uint)param_1 & 0xffff0000) != 0) && ((param_1 != &DAT_80000004 || (__CARDVendorID == -1))))
  {
    return false;
  }
  if (((uint)param_1 & 3) != 0) {
    return false;
  }
  uVar1 = (uint)param_1 & 0xfc;
  if (uVar1 != 0x20) {
    if (uVar1 < 0x20) {
      if (uVar1 != 8) {
        if (uVar1 < 8) {
          if (uVar1 != 4) {
            return false;
          }
        }
        else {
          if (uVar1 != 0x10) {
            return false;
          }
        }
      }
    }
    else {
      if (uVar1 != 0x80) {
        if (0x7f < uVar1) {
          return false;
        }
        if (uVar1 != 0x40) {
          return false;
        }
      }
    }
  }
  if (*(uint *)(&SectorSizeTable + ((uint)param_1 >> 9 & 0x1c)) == 0) {
    return false;
  }
  if ((((uint)param_1 & 0xfc) << 0x11) / *(uint *)(&SectorSizeTable + ((uint)param_1 >> 9 & 0x1c)) <
      8) {
    return false;
  }
  return true;
}


/* 
   \brief Performs a check against the desired EXI channel if a device is inserted
   \param[in] chn CARD slot
   \return \ref card_errors "card error codes" */

card_errors CARDProbe(int card_slot)

{
  card_errors cVar1;
  
  if ((DAT_800030e3 & 0x80) == 0) {
    cVar1 = exi::EXIProbe();
  }
  else {
    cVar1 = CARD_ERROR_READY;
  }
  return cVar1;
}


/* 
   \brief Performs a check against the desired EXI channel if a memory card is inserted or mounted
   \param[in] chn CARD slot
   \param[out] mem_size pointer to a integer variable, ready to take the resulting value (this param
   is optional and can be NULL)
   \param[out] sect_size pointer to a integer variable, ready to take the resulting value (this
   param is optional and can be NULL)
   \return \ref card_errors "card error codes" */

card_errors CARDProbeEx(int card_slot,uint *mem_size,uint *sect_size)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  card_errors cVar5;
  undefined1 *local_1c [2];
  
  if ((-1 < card_slot) && (card_slot < 2)) {
    if ((DAT_800030e3 & 0x80) != 0) {
      return CARD_ERROR_NOCARD;
    }
    uVar1 = os::OSDisableInterrupts();
    iVar2 = exi::EXIProbeEx(card_slot);
    if (iVar2 == -1) {
      cVar5 = CARD_ERROR_NOCARD;
    }
    else {
      if (iVar2 == 0) {
        cVar5 = CARD_ERROR_BUSY;
      }
      else {
        if (__CARDBlock[card_slot].mCardMounted == 0) {
          uVar3 = exi::EXIGetState(card_slot);
          if ((uVar3 & 8) == 0) {
            iVar2 = exi::EXIGetID(card_slot,0,local_1c);
            if (iVar2 == 0) {
              cVar5 = CARD_ERROR_BUSY;
            }
            else {
              bVar4 = IsCard(local_1c[0]);
              if (bVar4 == false) {
                cVar5 = CARD_ERROR_WRONGDEVICE;
              }
              else {
                if (mem_size != (uint *)0x0) {
                  *mem_size = (uint)local_1c[0] & 0xfc;
                }
                if (sect_size != (uint *)0x0) {
                  *sect_size = *(uint *)(&SectorSizeTable + ((uint)local_1c[0] >> 9 & 0x1c));
                }
                cVar5 = CARD_ERROR_READY;
              }
            }
          }
          else {
            cVar5 = CARD_ERROR_WRONGDEVICE;
          }
        }
        else {
          if ((int)__CARDBlock[card_slot].mCurrBlock < 1) {
            cVar5 = CARD_ERROR_BUSY;
          }
          else {
            if (mem_size != (uint *)0x0) {
              *mem_size = (uint)*(ushort *)&__CARDBlock[card_slot].mMem_size;
            }
            if (sect_size != (uint *)0x0) {
              *sect_size = __CARDBlock[card_slot].mDataSize;
            }
            cVar5 = CARD_ERROR_READY;
          }
        }
      }
    }
    os::OSRestoreInterrupts(uVar1);
    return cVar5;
  }
  return CARD_ERROR_FATAL_ERROR;
}


card_errors DoMount(int param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  short sVar8;
  byte bVar9;
  int iVar10;
  bool bVar11;
  undefined *puVar12;
  int iVar13;
  int iVar14;
  char *pcVar15;
  char *pcVar16;
  card_errors cVar17;
  byte local_1c [4];
  undefined1 *local_18 [2];
  
  if (__CARDBlock[param_1].mCurrBlock == 0) {
    iVar10 = exi::EXIGetID(param_1,0,local_18);
    if (iVar10 == 0) {
      cVar17 = CARD_ERROR_NOCARD;
    }
    else {
      bVar11 = IsCard(local_18[0]);
      if (bVar11 == false) {
        cVar17 = CARD_ERROR_WRONGDEVICE;
      }
      else {
        cVar17 = CARD_ERROR_READY;
      }
    }
    if (-1 < (int)cVar17) {
      __CARDBlock[param_1].field_0x108 = local_18[0];
      *(ushort *)&__CARDBlock[param_1].mMem_size = (ushort)local_18[0] & 0xfc;
      __CARDBlock[param_1].mDataSize = *(int *)(&SectorSizeTable + ((uint)local_18[0] >> 9 & 0x1c));
      __CARDBlock[param_1].mMaxBlockSize =
           (short)(((int)((uint)*(ushort *)&__CARDBlock[param_1].mMem_size << 0x14) >> 3) /
                  __CARDBlock[param_1].mDataSize);
      __CARDBlock[param_1].field_0x14 =
           *(undefined **)(&LatencyTable + ((uint)local_18[0] >> 6 & 0x1c));
      cVar17 = __CARDClearStatus(param_1);
      if ((-1 < (int)cVar17) && (cVar17 = __CARDReadStatus(param_1,local_1c), -1 < (int)cVar17)) {
        iVar10 = exi::EXIProbe(param_1);
        if (iVar10 == 0) {
          cVar17 = CARD_ERROR_NOCARD;
        }
        else {
          if ((local_1c[0] & 0x40) == 0) {
            cVar17 = __CARDUnlock(param_1,param_1 * 0x110 + -0x7fc0ece8);
            if (-1 < (int)cVar17) {
              iVar10 = os::__OSLockSramEx();
              puVar12 = (undefined *)(iVar10 + param_1 * 0xc);
              *puVar12 = *(undefined *)&__CARDBlock[param_1].field_0x18;
              cVar1 = *(char *)&__CARDBlock[param_1].field_0x18;
              puVar12[1] = *(undefined *)&__CARDBlock[param_1].field_0x19;
              iVar14 = 8;
              cVar2 = *(char *)&__CARDBlock[param_1].field_0x19;
              puVar12[2] = *(char *)&__CARDBlock[param_1].field_0x1a;
              cVar3 = *(char *)&__CARDBlock[param_1].field_0x1a;
              puVar12[3] = *(char *)&__CARDBlock[param_1].field_0x1b;
              cVar4 = *(char *)&__CARDBlock[param_1].field_0x1b;
              puVar12[4] = *(char *)&__CARDBlock[param_1].field_0x1c;
              cVar5 = *(char *)&__CARDBlock[param_1].field_0x1c;
              puVar12[5] = *(char *)&__CARDBlock[param_1].field_0x1d;
              cVar6 = *(char *)&__CARDBlock[param_1].field_0x1d;
              puVar12[6] = *(char *)&__CARDBlock[param_1].field_0x1e;
              cVar7 = *(char *)&__CARDBlock[param_1].field_0x1e;
              puVar12[7] = *(char *)&__CARDBlock[param_1].field_0x1f;
              bVar9 = cVar1 + cVar2 + cVar3 + cVar4 + cVar5 + cVar6 + cVar7 +
                      *(char *)&__CARDBlock[param_1].field_0x1f;
              pcVar15 = puVar12 + 8;
              iVar13 = 4;
              do {
                pcVar16 = __CARDBlock[param_1].mCard_block.mCmd + iVar14 + -0x16;
                iVar14 = iVar14 + 1;
                *pcVar15 = *pcVar16;
                pcVar15 = pcVar15 + 1;
                bVar9 = bVar9 + *pcVar16;
                iVar13 = iVar13 + -1;
              } while (iVar13 != 0);
              *(byte *)(iVar10 + param_1 + 0x26) = ~bVar9;
              os::__OSUnlockSramEx(1);
              return cVar17;
            }
          }
          else {
            __CARDBlock[param_1].mCurrBlock = 1;
            iVar13 = os::__OSLockSramEx();
            pcVar15 = (char *)(iVar13 + param_1 * 0xc);
            bVar9 = *pcVar15 + pcVar15[1] + pcVar15[2] + pcVar15[3] + pcVar15[4] + pcVar15[5] +
                    pcVar15[6] + pcVar15[7];
            pcVar15 = pcVar15 + 8;
            iVar10 = 4;
            do {
              cVar1 = *pcVar15;
              pcVar15 = pcVar15 + 1;
              bVar9 = bVar9 + cVar1;
              iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
            os::__OSUnlockSramEx(0);
            if (*(byte *)(iVar13 + param_1 + 0x26) == (byte)~bVar9) goto LAB_8031d89c;
            cVar17 = CARD_ERROR_IOERROR;
          }
        }
      }
    }
LAB_8031d978:
    exi::EXIUnlock(param_1);
    DoUnmount(param_1,cVar17);
  }
  else {
LAB_8031d89c:
    if (__CARDBlock[param_1].mCurrBlock == 1) {
      if (__CARDBlock[param_1].field_0x108 == &DAT_80000004) {
        iVar10 = os::__OSLockSramEx();
        sVar8 = *(short *)(iVar10 + param_1 * 0xc);
        os::__OSUnlockSramEx(0);
        if ((__CARDVendorID == -1) || (sVar8 != __CARDVendorID)) {
          cVar17 = CARD_ERROR_WRONGDEVICE;
          goto LAB_8031d978;
        }
      }
      __CARDBlock[param_1].mCurrBlock = 2;
      cVar17 = __CARDEnableInterrupt(param_1,1);
      if ((int)cVar17 < 0) goto LAB_8031d978;
      exi::EXISetExiCallback(param_1,__CARDExiHandler);
      exi::EXIUnlock(param_1);
      os::DCInvalidateRange(__CARDBlock[param_1].mCard_block.mpWorkarea,0xa000);
    }
    iVar10 = __CARDBlock[param_1].mCurrBlock - 2;
    cVar17 = __CARDRead(param_1,__CARDBlock[param_1].mDataSize * iVar10,0x2000,
                        (void *)((int)__CARDBlock[param_1].mCard_block.mpWorkarea + iVar10 * 0x2000)
                        ,__CARDMountCallback);
    if ((int)cVar17 < 0) {
      __CARDPutControlBlock(__CARDBlock + param_1,cVar17);
    }
  }
  return cVar17;
}


void __CARDMountCallback(int param_1,card_errors param_2)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  
  if (param_2 != CARD_ERROR_NOCARD) {
    if (-4 < (int)param_2) {
      if (param_2 == CARD_ERROR_UNLOCKED) {
        __CARDBlock[param_1].mpCardMount_cb = __CARDMountCallback;
        iVar2 = exi::EXILock(param_1,0,__CARDUnlockedHandler);
        if (iVar2 == 0) {
          return;
        }
        __CARDBlock[param_1].mpCardMount_cb = (void *)0x0;
        param_2 = DoMount(param_1);
      }
      else {
        if ((0 < (int)param_2) || ((int)param_2 < 0)) goto LAB_8031dab0;
        uVar1 = __CARDBlock[param_1].mCurrBlock + 1;
        __CARDBlock[param_1].mCurrBlock = uVar1;
        if (6 < (int)uVar1) {
          param_2 = __CARDVerify(__CARDBlock + param_1);
          goto LAB_8031dab0;
        }
        param_2 = DoMount(param_1);
      }
      if (-1 < (int)param_2) {
        return;
      }
      goto LAB_8031dab0;
    }
    if (param_2 != CARD_ERROR_IOERROR) goto LAB_8031dab0;
  }
  DoUnmount(param_1,param_2);
LAB_8031dab0:
  pcVar3 = (code *)__CARDBlock[param_1].mpAttach_cb;
  __CARDBlock[param_1].mpAttach_cb = (void *)0x0;
  __CARDPutControlBlock(__CARDBlock + param_1,param_2);
  (*pcVar3)(param_1,param_2);
  return;
}


/* 
   \brief Mounts the memory card in the slot CHN. This function returns immediately. Asynchronous
   version.
   \param[in] chn CARD slot
   \param[in] workarea pointer to memory area to hold the cards system area. The startaddress of the
   workdarea should be aligned on a 32byte boundery
   
   \param[in] detach_cb pointer to a callback function. This callback function will be called when
   the card is removed from the slot.
   \param[in] attach_cb pointer to a callback function. This callback function will be called when
   the mount process has finished.
   \return \ref card_errors "card error codes" */

card_errors CARDMountAsync(int card_slot,void *workarea,int detach_cb,code *attach_cb)

{
  card_errors cVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  CardBlockData *pCVar5;
  
  if ((card_slot < 0) || (1 < card_slot)) {
    cVar1 = CARD_ERROR_FATAL_ERROR;
  }
  else {
    if ((DAT_800030e3 & 0x80) == 0) {
      pCVar5 = __CARDBlock + card_slot;
      uVar2 = os::OSDisableInterrupts();
      if (__CARDBlock[card_slot].mStatus == CARD_ERROR_BUSY) {
        os::OSRestoreInterrupts(uVar2);
        cVar1 = CARD_ERROR_BUSY;
      }
      else {
        if ((pCVar5->mCardMounted == 0) && (uVar3 = exi::EXIGetState(card_slot), (uVar3 & 8) != 0))
        {
          os::OSRestoreInterrupts(uVar2);
          cVar1 = CARD_ERROR_WRONGDEVICE;
        }
        else {
          __CARDBlock[card_slot].mStatus = CARD_ERROR_BUSY;
          __CARDBlock[card_slot].mCard_block.mpWorkarea = (card_workarea *)workarea;
          __CARDBlock[card_slot].mpDetatch_cb = (void *)detach_cb;
          if (attach_cb == (code *)0x0) {
            attach_cb = __CARDDefaultApiCallback;
          }
          __CARDBlock[card_slot].mpAttach_cb = attach_cb;
          __CARDBlock[card_slot].mpExtHandler_cb = (void *)0x0;
          if ((pCVar5->mCardMounted == 0) &&
             (iVar4 = exi::EXIAttach(card_slot,__CARDExtHandler), iVar4 == 0)) {
            __CARDBlock[card_slot].mStatus = CARD_ERROR_NOCARD;
            os::OSRestoreInterrupts(uVar2);
            cVar1 = CARD_ERROR_NOCARD;
          }
          else {
            __CARDBlock[card_slot].mCurrBlock = 0;
            pCVar5->mCardMounted = 1;
            exi::EXISetExiCallback(card_slot,0);
            os::OSCancelAlarm(card_slot * 0x110 + -0x7fc0ec20);
            __CARDBlock[card_slot].mCard_block.mpCurr_dir = (card_dat *)0x0;
            __CARDBlock[card_slot].mCard_block.mpCurr_fat = (card_fat_block *)0x0;
            os::OSRestoreInterrupts(uVar2);
            __CARDBlock[card_slot].mpCardMount_cb = __CARDMountCallback;
            iVar4 = exi::EXILock(card_slot,0,__CARDUnlockedHandler);
            if (iVar4 == 0) {
              cVar1 = CARD_ERROR_READY;
            }
            else {
              __CARDBlock[card_slot].mpCardMount_cb = (void *)0x0;
              cVar1 = DoMount(card_slot);
            }
          }
        }
      }
    }
    else {
      cVar1 = CARD_ERROR_NOCARD;
    }
  }
  return cVar1;
}


/* 
   \brief Mounts the memory card in the slot CHN. Synchronous version.
   \param[in] chn CARD slot
   \param[in] workarea pointer to memory area to hold the cards system area. The startaddress of the
   workdarea should be aligned on a 32byte boundery
   \param[in] detach_cb pointer to a callback function. This callback function will be called when
   the card is removed from the slot.
   \return \ref card_errors "card error codes" */

card_errors CARDMount(int card_slot,void *workarea,int detatch_cb)

{
  card_errors cVar1;
  
  cVar1 = CARDMountAsync(card_slot,workarea,detatch_cb,__CARDSyncCallback);
  if (-1 < (int)cVar1) {
    cVar1 = __CARDSync(card_slot);
  }
  return cVar1;
}


void DoUnmount(int param_1,card_errors param_2)

{
  undefined4 uVar1;
  
  uVar1 = os::OSDisableInterrupts();
  if (__CARDBlock[param_1].mCardMounted != 0) {
    exi::EXISetExiCallback(param_1,0);
    exi::EXIDetach(param_1);
    os::OSCancelAlarm(param_1 * 0x110 + -0x7fc0ec20);
    __CARDBlock[param_1].mCardMounted = 0;
    __CARDBlock[param_1].mStatus = param_2;
    __CARDBlock[param_1].mCurrBlock = 0;
  }
  os::OSRestoreInterrupts(uVar1);
  return;
}


card_errors CARDUnmount(int card_slot)

{
  card_errors cVar1;
  undefined4 uVar2;
  CardBlockData *apCStack20 [2];
  
  cVar1 = __CARDGetControlBlock(card_slot,apCStack20);
  if (-1 < (int)cVar1) {
    uVar2 = os::OSDisableInterrupts();
    if (__CARDBlock[card_slot].mCardMounted != 0) {
      exi::EXISetExiCallback(card_slot,0);
      exi::EXIDetach(card_slot);
      os::OSCancelAlarm(card_slot * 0x110 + -0x7fc0ec20);
      __CARDBlock[card_slot].mCardMounted = 0;
      __CARDBlock[card_slot].mStatus = CARD_ERROR_NOCARD;
      __CARDBlock[card_slot].mCurrBlock = 0;
    }
    os::OSRestoreInterrupts(uVar2);
    cVar1 = CARD_ERROR_READY;
  }
  return cVar1;
}

