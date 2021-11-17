#include <m_Do_MemCardRWmng.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <m_Do_MemCardRWmng.h>
#include <card/CARDWrite.h>
#include <card/CARDRead.h>
#include <JKernel/JKRAram.h>
#include <card/CARDNet.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <os/OSTime.h>
#include <m_Do_dvd_thread.h>
#include <card/CARDStat.h>


namespace m_Do_MemCardRWmng {
struct card_savebuffer sTmpBuf;
struct card_savebuffer sTmpBuf2;
undefined4 sSaveCount;

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall mDoMemCdRWm_Store(CARDFileInfo *,
                               void *,
                               unsigned long) */

card_errors mDoMemCdRWm_Store(CARDFileInfo *pInf,byte *data,int size)

{
  uint offset;
  card_errors cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  mDoMemCdRWm_BuildHeader(&sTmpBuf);
  cVar1 = card::CARDWrite(pInf,&sTmpBuf,0x2000,0);
  if (cVar1 == CARD_ERROR_READY) {
    iVar2 = mDoMemCdRWm_CheckCardStat(pInf);
    if (iVar2 == 0) {
      FUN_800033a8((int)&sTmpBuf,0,0x2000);
      cVar1 = card::CARDWrite(pInf,&sTmpBuf,0x2000,0x2000);
      if (cVar1 != CARD_ERROR_READY) {
        return cVar1;
      }
      cVar1 = card::CARDWrite(pInf,&sTmpBuf,0x2000,0x4000);
      if (cVar1 != CARD_ERROR_READY) {
        return cVar1;
      }
      sSaveCount = 0;
    }
    FUN_800033a8((int)&sTmpBuf,0,0x2000);
    sTmpBuf.field_0x4 = 0;
    copy_bytes(sTmpBuf.mSaveData[0].mData,data,size);
    sTmpBuf.mSaveCount = sSaveCount + 1;
    sSaveCount = sTmpBuf.mSaveCount;
    uVar3 = mDoMemCdRWm_CalcCheckSum(&sTmpBuf,0x1ffc);
    sTmpBuf.mCheckSum = uVar3;
    cVar1 = card::CARDWrite(pInf,&sTmpBuf,0x2000,0x2000);
    if ((((cVar1 == CARD_ERROR_READY) &&
         (cVar1 = card::CARDRead(pInf,&sTmpBuf,0x2000,0x2000), cVar1 == CARD_ERROR_READY)) &&
        (uVar4 = mDoMemCdRWm_CalcCheckSum(&sTmpBuf,0x1ffc), uVar3 == uVar4)) &&
       (((cVar1 = card::CARDWrite(pInf,&sTmpBuf,0x2000,0x4000), cVar1 == CARD_ERROR_READY &&
         (cVar1 = card::CARDRead(pInf,&sTmpBuf,0x2000,0x4000), cVar1 == CARD_ERROR_READY)) &&
        (uVar4 = mDoMemCdRWm_CalcCheckSum(&sTmpBuf,0x1ffc), uVar3 == uVar4)))) {
      if (DAT_803b4ff4 == 0) {
        uVar3 = (uint)d_com_inf_game::g_dComIfG_gameInfo._4752_1_;
        uVar4 = 0;
        iVar2 = 0;
        do {
          if ((1 << (uVar4 & 0xff) & 0xffU & (uint)d_com_inf_game::g_dComIfG_gameInfo._23547_1_) !=
              0) {
            FUN_800033a8((int)&sTmpBuf,0,0x2000);
            JKRAram::aramToMainRam
                      (*(JKRAramBlock **)
                        ((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow + iVar2 + -0x44),
                       (uchar *)&sTmpBuf,0x2000,0,0,0,(JKRHeap *)0x0,-1,(ulong *)0x0);
            offset = (uVar3 * 3 + 3 + uVar4) * 0x2000;
            cVar1 = card::CARDWrite(pInf,&sTmpBuf,0x2000,offset);
            if (cVar1 != CARD_ERROR_READY) {
              return cVar1;
            }
            cVar1 = card::CARDRead(pInf,&sTmpBuf,0x2000,offset);
            if (cVar1 != CARD_ERROR_READY) {
              return cVar1;
            }
          }
          uVar4 = uVar4 + 1;
          iVar2 = iVar2 + 4;
        } while ((int)uVar4 < 3);
      }
      else {
        uVar3 = (uint)DAT_file_slot;
        if (uVar3 < 3) {
          iVar6 = 0;
          iVar2 = DAT_803b4ff4;
          do {
            uVar4 = (uVar3 * 3 + 3 + iVar6) * 0x2000;
            cVar1 = card::CARDWrite(pInf,iVar2,0x2000,uVar4);
            if (cVar1 != CARD_ERROR_READY) {
              return cVar1;
            }
            cVar1 = card::CARDRead(pInf,&sTmpBuf,0x2000,uVar4);
            if (cVar1 != CARD_ERROR_READY) {
              return cVar1;
            }
            iVar5 = mDoMemCdRWm_TestCheckSumPictData(iVar2);
            if (iVar5 == 0) {
              return CARD_ERROR_READY;
            }
            iVar6 = iVar6 + 1;
            iVar2 = iVar2 + 0x2000;
          } while (iVar6 < 3);
        }
      }
      mDoMemCdRWm_SetCardStat(pInf);
    }
  }
  return cVar1;
}


/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* __stdcall mDoMemCdRWm_Restore(CARDFileInfo *,
                                 void *,
                                 unsigned long) */

card_errors mDoMemCdRWm_Restore(CARDFileInfo *file,byte *dest,int data_length)

{
  bool bVar1;
  bool bVar2;
  card_errors cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint local_38;
  undefined4 local_34;
  
  bVar1 = false;
  cVar3 = card::CARDRead(file,&sTmpBuf,0x2000,0x2000);
  if (cVar3 == CARD_ERROR_READY) {
    iVar4 = mDoMemCdRWm_TestCheckSumGameData(sTmpBuf.mSaveData);
    iVar5 = mDoMemCdRWm_TestCheckSumGameData(sTmpBuf.mSaveData + 1);
    iVar6 = mDoMemCdRWm_TestCheckSumGameData(sTmpBuf.mSaveData + 2);
    cVar3 = card::CARDRead(file,&sTmpBuf2,0x2000,0x4000);
    if (cVar3 == CARD_ERROR_READY) {
      iVar7 = mDoMemCdRWm_TestCheckSumGameData(sTmpBuf2.mSaveData);
      iVar8 = mDoMemCdRWm_TestCheckSumGameData(sTmpBuf2.mSaveData + 1);
      iVar9 = mDoMemCdRWm_TestCheckSumGameData(sTmpBuf2.mSaveData + 2);
      if ((iVar4 == 0) && (iVar7 != 0)) {
        copy_bytes(sTmpBuf.mSaveData[0].mData,sTmpBuf2.mSaveData[0].mData,0x770);
        bVar1 = true;
      }
      if ((iVar5 == 0) && (iVar9 != 0)) {
        copy_bytes(sTmpBuf.mSaveData[1].mData,sTmpBuf2.mSaveData[1].mData,0x770);
        bVar1 = true;
      }
      if ((iVar6 == 0) && (iVar9 != 0)) {
        copy_bytes(sTmpBuf.mSaveData[2].mData,sTmpBuf2.mSaveData[2].mData,0x770);
        bVar1 = true;
      }
      bVar2 = false;
      if (((((iVar4 == 0) && (iVar7 == 0)) && (iVar5 == 0)) && ((iVar8 == 0 && (iVar6 == 0)))) &&
         (iVar9 == 0)) {
        bVar2 = true;
      }
      iVar4 = mDoMemCdRWm_CheckCardStat(file);
      if (iVar4 == 0) {
        cVar3 = CARD_ERROR_FATAL_ERROR;
      }
      else {
        if ((!bVar1) ||
           ((cVar3 = card::CARDWrite(file,&sTmpBuf,0x2000,0x2000), cVar3 == CARD_ERROR_READY &&
            (cVar3 = card::CARDWrite(file,&sTmpBuf,0x2000,0x4000), cVar3 == CARD_ERROR_READY)))) {
          copy_bytes(dest,sTmpBuf.mSaveData[0].mData,data_length);
          sSaveCount = sTmpBuf.mSaveCount;
          DAT_803b5030 = sTmpBuf.field_0x4;
          if ((bVar2) ||
             ((DAT_803b4ff0 == (void *)0x0 ||
              (cVar3 = card::CARDRead(file,DAT_803b4ff0,0x12000,0x6000), cVar3 == CARD_ERROR_READY))
             )) {
            card::CARDGetSerialNo((uint)DAT_card_slot,&local_38);
            DAT_803b502c = local_34;
            DAT_CardSerialNo = local_38;
            cVar3 = CARD_ERROR_READY;
          }
        }
      }
    }
  }
  return cVar3;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall mDoMemCdRWm_BuildHeader(mDoMemCdRWm_HeaderData *) */

void mDoMemCdRWm_BuildHeader(card_savebuffer *param_1)

{
  int iVar1;
  mDoDvdThd_command_c *pmVar2;
  int iVar3;
  int32_t iVar4;
  node_class *pnVar5;
  OSCalendarTime OStack72;
  
  iVar4 = 0x20;
  MSL_C.PPCEABI.bare.H::snprintf(param_1->mHeaderGameName,0x20,"Zelda: The Wind Waker");
  iVar1 = os::OSGetTime();
  os::OSTicksToCalendarTime(iVar1,iVar4,&OStack72);
  MSL_C.PPCEABI.bare.H::snprintf
            (param_1->mSaveInfoStr,0x20,"%d/%d Save Data",OStack72.mon + 1,OStack72.mday);
  pmVar2 = mDoDvdThd_mountArchive_c::create("/res/CardIcon/cardicon.arc",'\0',(JKRHeap *)0x0);
  do {
  } while (pmVar2->mStatus == 0);
  pnVar5 = pmVar2[1].parent.mpNextNode;
  iVar1 = (*(code *)pnVar5->mpPrevNode[1].mpNextNode)(pnVar5,"ipl_banner.bti");
  iVar3 = (*(code *)pnVar5->mpPrevNode[1].mpNextNode)(pnVar5,"ipl_icon1.bti");
  copy_bytes((byte *)param_1,(byte *)(iVar1 + *(int *)(iVar1 + 0x1c)),
             (uint)*(ushort *)(iVar1 + 10) * 2 + 0xc00);
  copy_bytes(param_1->mSaveData[1].mData + 0x688,(byte *)(iVar3 + *(int *)(iVar3 + 0x1c)),
             (uint)*(ushort *)(iVar3 + 10) * 2 + 0x400);
  (*(code *)pnVar5->mpPrevNode[1].mpPrevNode)(pnVar5);
  if (pmVar2 != (mDoDvdThd_command_c *)0x0) {
    (*(code *)pmVar2->vtbl->_mDoDvdThd_toMainRam_c)(pmVar2,1);
  }
  return;
}


/* __stdcall mDoMemCdRWm_SetCardStat(CARDFileInfo *) */

void mDoMemCdRWm_SetCardStat(int param_1)

{
  byte local_4a;
  uint local_48;
  short local_44;
  short local_42;
  uint local_40;
  
  card::CARDGetStatus((uint)DAT_card_slot,*(undefined4 *)(param_1 + 4),
                      (card_status *)&stack0xffffff88);
  local_48 = 0;
  local_40 = 0x1c00;
  local_4a = local_4a & 0xf8 | 1;
  local_44 = 1;
  local_42 = 3;
  card::CARDSetStatus((uint)DAT_card_slot,*(int *)(param_1 + 4),(card_status *)&stack0xffffff88);
  return;
}


/* __stdcall mDoMemCdRWm_CheckCardStat(CARDFileInfo *) */

undefined4 mDoMemCdRWm_CheckCardStat(CARDFileInfo *file)

{
  byte local_4a;
  uint local_48;
  ushort local_44;
  ushort local_42;
  uint local_40;
  
  card::CARDGetStatus((uint)DAT_card_slot,file->mFilenum,(card_status *)&stack0xffffff88);
  if (((((((local_48 == 0) && (local_40 == 0x1c00)) && ((local_4a & 3) == 1)) &&
        (((local_4a & 4) == 0 && ((local_44 & 3) == 1)))) &&
       ((((local_44 >> 2 & 3) == 0 && (((local_44 >> 4 & 3) == 0 && ((local_44 >> 6 & 3) == 0)))) &&
        ((local_44 >> 8 & 3) == 0)))) &&
      (((((local_44 >> 10 & 3) == 0 && ((local_44 >> 0xc & 3) == 0)) && (local_44 >> 0xe == 0)) &&
       ((((local_42 & 3) == 3 && ((local_42 >> 2 & 3) == 0)) &&
        (((local_42 >> 4 & 3) == 0 && (((local_42 >> 6 & 3) == 0 && ((local_42 >> 8 & 3) == 0)))))))
       ))) && (((local_42 >> 10 & 3) == 0 &&
               (((local_42 >> 0xc & 3) == 0 && (local_42 >> 0xe == 0)))))) {
    return 1;
  }
  return 0;
}


/* __stdcall mDoMemCdRWm_CalcCheckSum(void *,
                                      unsigned long) */

uint mDoMemCdRWm_CalcCheckSum(ushort *pBuf,uint size)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  iVar1 = 0;
  for (size = size >> 1; size != 0; size = size - 1) {
    iVar1 = iVar1 + (uint)*pBuf;
    uVar2 = uVar2 + ~(uint)*pBuf & 0xffff;
    pBuf = pBuf + 1;
  }
  return iVar1 << 0x10 | uVar2;
}


/* __stdcall mDoMemCdRWm_CalcCheckSumPictData(void *,
                                              unsigned long) */

int mDoMemCdRWm_CalcCheckSumPictData(byte *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 != 0) {
    do {
      iVar1 = iVar1 + (uint)*param_1;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return iVar1;
}


/* __stdcall mDoMemCdRWm_TestCheckSumPictData(void *) */

uint mDoMemCdRWm_TestCheckSumPictData(int param_1)

{
  uint uVar1;
  
  uVar1 = mDoMemCdRWm_CalcCheckSumPictData(param_1,0x1ffe);
  uVar1 = countLeadingZeros((uint)*(ushort *)(param_1 + 0x1ffe) - (uVar1 & 0xffff));
  return uVar1 >> 5 & 0xff;
}


/* __stdcall mDoMemCdRWm_SetCheckSumPictData(unsigned char *) */

void mDoMemCdRWm_SetCheckSumPictData(int param_1)

{
  undefined2 uVar1;
  
  uVar1 = mDoMemCdRWm_CalcCheckSumPictData(param_1,0x1ffe);
  *(undefined2 *)(param_1 + 0x1ffe) = uVar1;
  return;
}


/* __stdcall mDoMemCdRWm_CalcCheckSumGameData(void *,
                                              unsigned long) */

undefined8 mDoMemCdRWm_CalcCheckSumGameData(byte *pData,int size)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  if (size != 0) {
    do {
      iVar1 = iVar1 + (uint)*pData;
      iVar2 = iVar2 + ~(uint)*pData;
      pData = pData + 1;
      size = size + -1;
    } while (size != 0);
  }
  return CONCAT44(iVar1,iVar2);
}


/* __stdcall mDoMemCdRWm_TestCheckSumGameData(void *) */

uint mDoMemCdRWm_TestCheckSumGameData(card_savedata *pData)

{
  uint ret;
  undefined8 csum;
  
  csum = mDoMemCdRWm_CalcCheckSumGameData(pData,0x768);
  ret = countLeadingZeros((uint)csum ^ *(uint *)(pData->mData + 0x76c) |
                          (uint)((ulonglong)csum >> 0x20) ^ *(uint *)(pData->mData + 0x768));
  return ret >> 5 & 0xff;
}


/* __stdcall mDoMemCdRWm_SetCheckSumGameData(unsigned char *,
                                             unsigned char) */

void mDoMemCdRWm_SetCheckSumGameData(int param_1,uint param_2)

{
  undefined8 uVar1;
  
  param_1 = param_1 + (param_2 & 0xff) * 0x770;
  uVar1 = mDoMemCdRWm_CalcCheckSumGameData(param_1,0x768);
  *(int *)(param_1 + 0x76c) = (int)uVar1;
  *(int *)(param_1 + 0x768) = (int)((ulonglong)uVar1 >> 0x20);
  return;
}

