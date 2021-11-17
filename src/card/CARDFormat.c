#include <card/CARDFormat.h>
#include <card/CARDFormat.h>
#include <card/CARDBios.h>
#include <card/CARDRdwr.h>
#include <os/OSRtc.h>
#include <os/OSTime.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <card/CARDCheck.h>
#include <os/OSCache.h>


namespace card {

void FormatCallback(int param_1,card_errors param_2)

{
  uint uVar1;
  code *pcVar2;
  
  if (-1 < (int)param_2) {
    __CARDBlock[param_1].mTotalBlocks = __CARDBlock[param_1].mTotalBlocks + 1;
    uVar1 = __CARDBlock[param_1].mTotalBlocks;
    if ((int)uVar1 < 5) {
      param_2 = __CARDEraseSector(param_1,__CARDBlock[param_1].mDataSize * uVar1,FormatCallback);
    }
    else {
      if (9 < (int)uVar1) {
        __CARDBlock[param_1].mCard_block.mpCurr_dir =
             &(__CARDBlock[param_1].mCard_block.mpWorkarea)->mWorkarea1;
        copy_bytes((byte *)__CARDBlock[param_1].mCard_block.mpCurr_dir,
                   (byte *)&(__CARDBlock[param_1].mCard_block.mpWorkarea)->mWorkarea2,0x2000);
        __CARDBlock[param_1].mCard_block.mpCurr_fat =
             (card_fat_block *)(__CARDBlock[param_1].mCard_block.mpWorkarea + 1);
        copy_bytes((byte *)__CARDBlock[param_1].mCard_block.mpCurr_fat,
                   (byte *)&__CARDBlock[param_1].mCard_block.mpWorkarea[1].mWorkarea1,0x2000);
        goto LAB_8031df24;
      }
      param_2 = __CARDWrite(param_1,__CARDBlock[param_1].mDataSize * (uVar1 - 5),0x2000,
                            (int)__CARDBlock[param_1].mCard_block.mpWorkarea + (uVar1 - 5) * 0x2000,
                            FormatCallback);
    }
    if (-1 < (int)param_2) {
      return;
    }
  }
LAB_8031df24:
  pcVar2 = (code *)__CARDBlock[param_1].mpAttach_cb;
  __CARDBlock[param_1].mpAttach_cb = (void *)0x0;
  __CARDPutControlBlock(__CARDBlock + param_1,param_2);
  (*pcVar2)(param_1,param_2);
  return;
}


/* WARNING: Type propagation algorithm not settling */

card_errors __CARDFormatRegionAsync(int card_slot,undefined2 param_2,code *attach_cb)

{
  uint uVar1;
  card_errors cVar2;
  int iVar3;
  int iVar4;
  uint extraout_r4;
  uint uVar5;
  uint extraout_r4_00;
  uint extraout_r4_01;
  uint extraout_r4_02;
  uint extraout_r4_03;
  uint extraout_r4_04;
  uint extraout_r4_05;
  uint extraout_r4_06;
  uint extraout_r4_07;
  uint extraout_r4_08;
  uint uVar6;
  card_dat *pcVar7;
  char *pcVar8;
  char *pcVar9;
  card_workarea *pcVar10;
  short sVar11;
  ulonglong uVar12;
  CardBlockData *local_40 [2];
  
  cVar2 = __CARDGetControlBlock(card_slot,local_40);
  if (-1 < (int)cVar2) {
    pcVar10 = (local_40[0]->mCard_block).mpWorkarea;
    FUN_800033a8((int)pcVar10,0xff,0x2000);
    uVar6 = (uint)DAT_cc00206e;
    *(undefined2 *)((pcVar10->mHeaderData).mDirEntries[0].mFilename + 0x1c) = param_2;
    iVar3 = os::__OSLockSram();
    *(undefined4 *)((pcVar10->mHeaderData).mDirEntries[0].mFilename + 0xc) =
         *(undefined4 *)(iVar3 + 0xc);
    *(uint *)((pcVar10->mHeaderData).mDirEntries[0].mFilename + 0x10) =
         (uint)*(byte *)(iVar3 + 0x12);
    os::__OSUnlockSram(0);
    uVar5 = extraout_r4;
    iVar4 = os::OSGetTime();
    iVar3 = os::__OSLockSramEx();
    pcVar9 = (char *)(iVar3 + card_slot * 0xc);
    pcVar8 = pcVar9;
    uVar1 = uVar5;
    iVar3 = iVar4;
    for (sVar11 = 0; sVar11 < 4; sVar11 = sVar11 + 8) {
      uVar12 = Runtime.PPCEABI.H::__shr2i
                         (iVar3 * 0x41c64e6d + (int)((ulonglong)uVar1 * 0x41c64e6d >> 0x20) +
                          (uint)(0xffffcfc6 < uVar1 * 0x41c64e6d),uVar1 * 0x41c64e6d + 0x3039,0x10);
      (pcVar10->mHeaderData).mDirEntries[0].mGamecode[sVar11] = (char)uVar12 + *pcVar8;
      uVar1 = (int)uVar12 * 0x41c64e6d;
      Runtime.PPCEABI.H::__shr2i
                ((int)(uVar12 >> 0x20) * 0x41c64e6d +
                 (int)((uVar12 & 0xffffffff) * 0x41c64e6d >> 0x20) + (uint)(0xffffcfc6 < uVar1),
                 uVar1 + 0x3039,0x10);
      uVar1 = (extraout_r4_00 & 0x7fff) * 0x41c64e6d;
      uVar12 = Runtime.PPCEABI.H::__shr2i
                         ((int)((ulonglong)(extraout_r4_00 & 0x7fff) * 0x41c64e6d >> 0x20) +
                          (uint)(0xffffcfc6 < uVar1),uVar1 + 0x3039,0x10);
      uVar1 = (int)uVar12 * 0x41c64e6d;
      (pcVar10->mHeaderData).mDirEntries[0].mGamecode[(short)(sVar11 + 1)] =
           (char)uVar12 + pcVar9[(short)(sVar11 + 1)];
      Runtime.PPCEABI.H::__shr2i
                ((int)(uVar12 >> 0x20) * 0x41c64e6d +
                 (int)((uVar12 & 0xffffffff) * 0x41c64e6d >> 0x20) + (uint)(0xffffcfc6 < uVar1),
                 uVar1 + 0x3039,0x10);
      uVar1 = (extraout_r4_01 & 0x7fff) * 0x41c64e6d;
      uVar12 = Runtime.PPCEABI.H::__shr2i
                         ((int)((ulonglong)(extraout_r4_01 & 0x7fff) * 0x41c64e6d >> 0x20) +
                          (uint)(0xffffcfc6 < uVar1),uVar1 + 0x3039,0x10);
      uVar1 = (int)uVar12 * 0x41c64e6d;
      (pcVar10->mHeaderData).mDirEntries[0].mGamecode[(short)(sVar11 + 2)] =
           (char)uVar12 + pcVar9[(short)(sVar11 + 2)];
      Runtime.PPCEABI.H::__shr2i
                ((int)(uVar12 >> 0x20) * 0x41c64e6d +
                 (int)((uVar12 & 0xffffffff) * 0x41c64e6d >> 0x20) + (uint)(0xffffcfc6 < uVar1),
                 uVar1 + 0x3039,0x10);
      uVar1 = (extraout_r4_02 & 0x7fff) * 0x41c64e6d;
      uVar12 = Runtime.PPCEABI.H::__shr2i
                         ((int)((ulonglong)(extraout_r4_02 & 0x7fff) * 0x41c64e6d >> 0x20) +
                          (uint)(0xffffcfc6 < uVar1),uVar1 + 0x3039,0x10);
      uVar1 = (int)uVar12 * 0x41c64e6d;
      (pcVar10->mHeaderData).mDirEntries[0].mGamecode[(short)(sVar11 + 3)] =
           (char)uVar12 + pcVar9[(short)(sVar11 + 3)];
      Runtime.PPCEABI.H::__shr2i
                ((int)(uVar12 >> 0x20) * 0x41c64e6d +
                 (int)((uVar12 & 0xffffffff) * 0x41c64e6d >> 0x20) + (uint)(0xffffcfc6 < uVar1),
                 uVar1 + 0x3039,0x10);
      uVar1 = (extraout_r4_03 & 0x7fff) * 0x41c64e6d;
      uVar12 = Runtime.PPCEABI.H::__shr2i
                         ((int)((ulonglong)(extraout_r4_03 & 0x7fff) * 0x41c64e6d >> 0x20) +
                          (uint)(0xffffcfc6 < uVar1),uVar1 + 0x3039,0x10);
      uVar1 = (int)uVar12 * 0x41c64e6d;
      (pcVar10->mHeaderData).mDirEntries[0].mGamecode[(short)(sVar11 + 4)] =
           (char)uVar12 + pcVar9[(short)(sVar11 + 4)];
      Runtime.PPCEABI.H::__shr2i
                ((int)(uVar12 >> 0x20) * 0x41c64e6d +
                 (int)((uVar12 & 0xffffffff) * 0x41c64e6d >> 0x20) + (uint)(0xffffcfc6 < uVar1),
                 uVar1 + 0x3039,0x10);
      uVar1 = (extraout_r4_04 & 0x7fff) * 0x41c64e6d;
      uVar12 = Runtime.PPCEABI.H::__shr2i
                         ((int)((ulonglong)(extraout_r4_04 & 0x7fff) * 0x41c64e6d >> 0x20) +
                          (uint)(0xffffcfc6 < uVar1),uVar1 + 0x3039,0x10);
      uVar1 = (int)uVar12 * 0x41c64e6d;
      (pcVar10->mHeaderData).mDirEntries[0].mGamecode[(short)(sVar11 + 5)] =
           (char)uVar12 + pcVar9[(short)(sVar11 + 5)];
      Runtime.PPCEABI.H::__shr2i
                ((int)(uVar12 >> 0x20) * 0x41c64e6d +
                 (int)((uVar12 & 0xffffffff) * 0x41c64e6d >> 0x20) + (uint)(0xffffcfc6 < uVar1),
                 uVar1 + 0x3039,0x10);
      uVar1 = (extraout_r4_05 & 0x7fff) * 0x41c64e6d;
      uVar12 = Runtime.PPCEABI.H::__shr2i
                         ((int)((ulonglong)(extraout_r4_05 & 0x7fff) * 0x41c64e6d >> 0x20) +
                          (uint)(0xffffcfc6 < uVar1),uVar1 + 0x3039,0x10);
      uVar1 = (int)uVar12 * 0x41c64e6d;
      (pcVar10->mHeaderData).mDirEntries[0].mGamecode[(short)(sVar11 + 6)] =
           (char)uVar12 + pcVar9[(short)(sVar11 + 6)];
      Runtime.PPCEABI.H::__shr2i
                ((int)(uVar12 >> 0x20) * 0x41c64e6d +
                 (int)((uVar12 & 0xffffffff) * 0x41c64e6d >> 0x20) + (uint)(0xffffcfc6 < uVar1),
                 uVar1 + 0x3039,0x10);
      uVar1 = (extraout_r4_06 & 0x7fff) * 0x41c64e6d;
      uVar12 = Runtime.PPCEABI.H::__shr2i
                         ((int)((ulonglong)(extraout_r4_06 & 0x7fff) * 0x41c64e6d >> 0x20) +
                          (uint)(0xffffcfc6 < uVar1),uVar1 + 0x3039,0x10);
      uVar1 = (int)uVar12 * 0x41c64e6d;
      (pcVar10->mHeaderData).mDirEntries[0].mGamecode[(short)(sVar11 + 7)] =
           (char)uVar12 + pcVar9[(short)(sVar11 + 7)];
      Runtime.PPCEABI.H::__shr2i
                ((int)(uVar12 >> 0x20) * 0x41c64e6d +
                 (int)((uVar12 & 0xffffffff) * 0x41c64e6d >> 0x20) + (uint)(0xffffcfc6 < uVar1),
                 uVar1 + 0x3039,0x10);
      uVar1 = extraout_r4_07 & 0x7fff;
      iVar3 = 0;
      pcVar8 = pcVar8 + 8;
    }
    pcVar9 = pcVar9 + sVar11;
    for (; sVar11 < 0xc; sVar11 = sVar11 + 1) {
      uVar12 = Runtime.PPCEABI.H::__shr2i
                         (iVar3 * 0x41c64e6d + (int)((ulonglong)uVar1 * 0x41c64e6d >> 0x20) +
                          (uint)(0xffffcfc6 < uVar1 * 0x41c64e6d),uVar1 * 0x41c64e6d + 0x3039,0x10);
      (pcVar10->mHeaderData).mDirEntries[0].mGamecode[sVar11] = (char)uVar12 + *pcVar9;
      uVar1 = (int)uVar12 * 0x41c64e6d;
      Runtime.PPCEABI.H::__shr2i
                ((int)(uVar12 >> 0x20) * 0x41c64e6d +
                 (int)((uVar12 & 0xffffffff) * 0x41c64e6d >> 0x20) + (uint)(0xffffcfc6 < uVar1),
                 uVar1 + 0x3039,0x10);
      uVar1 = extraout_r4_08 & 0x7fff;
      iVar3 = 0;
      pcVar9 = pcVar9 + 1;
    }
    os::__OSUnlockSramEx(0);
    *(uint *)((pcVar10->mHeaderData).mDirEntries[0].mFilename + 0x14) = uVar6;
    *(uint *)((pcVar10->mHeaderData).mDirEntries[0].mFilename + 8) = uVar5;
    *(int *)((pcVar10->mHeaderData).mDirEntries[0].mFilename + 4) = iVar4;
    *(undefined2 *)((pcVar10->mHeaderData).mDirEntries[0].mFilename + 0x18) = 0;
    *(undefined2 *)((pcVar10->mHeaderData).mDirEntries[0].mFilename + 0x1a) =
         *(undefined2 *)&local_40[0]->mMem_size;
    __CARDCheckSum(pcVar10,0x1fc,&(pcVar10->mHeaderData).mDirEntries[7].mChksum_01,
                   &(pcVar10->mHeaderData).mDirEntries[7].mChksum_02);
    for (sVar11 = 0; sVar11 < 2; sVar11 = sVar11 + 1) {
      pcVar7 = &((local_40[0]->mCard_block).mpWorkarea)->mWorkarea1 + sVar11;
      FUN_800033a8((int)pcVar7,0xff,0x2000);
      pcVar7->mDirEntries[0x7f].mPad_01 = sVar11;
      __CARDCheckSum(pcVar7,0x1ffc,&pcVar7->mDirEntries[0x7f].mChksum_01,
                     &pcVar7->mDirEntries[0x7f].mChksum_02);
    }
    for (sVar11 = 0; sVar11 < 2; sVar11 = sVar11 + 1) {
      pcVar7 = &(local_40[0]->mCard_block).mpWorkarea[1].mHeaderData + sVar11;
      FUN_800033a8((int)pcVar7,0,0x2000);
      *(short *)pcVar7->mDirEntries[0].mCompany = sVar11;
      *(short *)&pcVar7->mDirEntries[0].mPad_00 = local_40[0]->mMaxBlockSize + -5;
      *(undefined2 *)pcVar7->mDirEntries[0].mFilename = 4;
      __CARDCheckSum(pcVar7->mDirEntries[0].mCompany,0x1ffc,pcVar7,
                     pcVar7->mDirEntries[0].mGamecode + 2);
    }
    if (attach_cb == (code *)0x0) {
      attach_cb = __CARDDefaultApiCallback;
    }
    local_40[0]->mpAttach_cb = attach_cb;
    os::DCStoreRange((local_40[0]->mCard_block).mpWorkarea,0xa000);
    local_40[0]->mTotalBlocks = 0;
    cVar2 = __CARDEraseSector(card_slot,local_40[0]->mDataSize * local_40[0]->mTotalBlocks,
                              FormatCallback);
    if ((int)cVar2 < 0) {
      __CARDPutControlBlock(local_40[0],cVar2);
    }
  }
  return cVar2;
}


card_errors CARDFormat(int card_slot)

{
  undefined4 uVar1;
  card_errors cVar2;
  
  uVar1 = __CARDGetFontEncode();
  cVar2 = __CARDFormatRegionAsync(card_slot,uVar1,__CARDSyncCallback);
  if (-1 < (int)cVar2) {
    cVar2 = __CARDSync(card_slot);
  }
  return cVar2;
}

