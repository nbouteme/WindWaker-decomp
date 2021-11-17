#include <card/CARDStat.h>
#include <card/CARDBios.h>
#include <card/CARDDir.h>
#include <card/CARDOpen.h>
#include <card/CARDStat.h>
#include <os/OSTime.h>
#include <Runtime.PPCEABI.H/runtime.h>


namespace card {

void UpdateIconOffsets(card_direntry *param_1,card_status *stats)

{
  bool bVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  card_status *pcVar5;
  uint uVar6;
  int iVar7;
  
  uVar6 = param_1->mIconaddr;
  if (uVar6 == 0xffffffff) {
    *(undefined *)&stats->mBannerfmt = 0;
    uVar6 = 0;
    stats->mIconfmt = 0;
    stats->mIconspeed = 0;
  }
  bVar1 = false;
  bVar3 = param_1->mBannerfmt & 3;
  if (bVar3 == 2) {
    *(uint *)&stats->field_0x3c = uVar6;
    uVar6 = uVar6 + 0x1800;
    *(undefined4 *)&stats->field_0x40 = 0xffffffff;
  }
  else {
    if ((bVar3 < 2) && ((param_1->mBannerfmt & 3) != 0)) {
      *(uint *)&stats->field_0x3c = uVar6;
      iVar7 = uVar6 + 0xc00;
      uVar6 = uVar6 + 0xe00;
      *(int *)&stats->field_0x40 = iVar7;
    }
    else {
      *(undefined4 *)&stats->field_0x3c = 0xffffffff;
      *(undefined4 *)&stats->field_0x40 = 0xffffffff;
    }
  }
  iVar7 = 2;
  uVar4 = 0;
  pcVar5 = stats;
  do {
    uVar2 = (int)(uint)(ushort)param_1->mIconfmt >> (uVar4 & 0x3f) & 3;
    if (uVar2 == 2) {
      *(uint *)&pcVar5->field_0x44 = uVar6;
      uVar6 = uVar6 + 0x800;
    }
    else {
      if ((uVar2 < 2) && (uVar2 != 0)) {
        *(uint *)&pcVar5->field_0x44 = uVar6;
        bVar1 = true;
        uVar6 = uVar6 + 0x400;
      }
      else {
        *(undefined4 *)&pcVar5->field_0x44 = 0xffffffff;
      }
    }
    uVar2 = (int)(uint)(ushort)param_1->mIconfmt >> (uVar4 + 2 & 0x3f) & 3;
    if (uVar2 == 2) {
      *(uint *)&pcVar5->field_0x48 = uVar6;
      uVar6 = uVar6 + 0x800;
    }
    else {
      if ((uVar2 < 2) && (uVar2 != 0)) {
        *(uint *)&pcVar5->field_0x48 = uVar6;
        bVar1 = true;
        uVar6 = uVar6 + 0x400;
      }
      else {
        *(undefined4 *)&pcVar5->field_0x48 = 0xffffffff;
      }
    }
    uVar2 = (int)(uint)(ushort)param_1->mIconfmt >> (uVar4 + 4 & 0x3f) & 3;
    if (uVar2 == 2) {
      *(uint *)&pcVar5->field_0x4c = uVar6;
      uVar6 = uVar6 + 0x800;
    }
    else {
      if ((uVar2 < 2) && (uVar2 != 0)) {
        *(uint *)&pcVar5->field_0x4c = uVar6;
        bVar1 = true;
        uVar6 = uVar6 + 0x400;
      }
      else {
        *(undefined4 *)&pcVar5->field_0x4c = 0xffffffff;
      }
    }
    uVar2 = (int)(uint)(ushort)param_1->mIconfmt >> (uVar4 + 6 & 0x3f) & 3;
    if (uVar2 == 2) {
      *(uint *)&pcVar5->field_0x50 = uVar6;
      uVar6 = uVar6 + 0x800;
    }
    else {
      if ((uVar2 < 2) && (uVar2 != 0)) {
        *(uint *)&pcVar5->field_0x50 = uVar6;
        bVar1 = true;
        uVar6 = uVar6 + 0x400;
      }
      else {
        *(undefined4 *)&pcVar5->field_0x50 = 0xffffffff;
      }
    }
    uVar4 = uVar4 + 8;
    pcVar5 = (card_status *)(pcVar5->mFilename + 0x10);
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  if (bVar1) {
    *(uint *)&stats->field_0x64 = uVar6;
    uVar6 = uVar6 + 0x200;
  }
  else {
    *(undefined4 *)&stats->field_0x64 = 0xffffffff;
  }
  *(uint *)&stats->field_0x68 = uVar6;
  return;
}


card_errors CARDGetStatus(int card_slot,int fileno,card_status *stats)

{
  card_errors cVar1;
  card_direntry *pcVar2;
  CardBlockData *local_14 [2];
  
  if ((fileno < 0) || (0x7e < fileno)) {
    cVar1 = CARD_ERROR_FATAL_ERROR;
  }
  else {
    cVar1 = __CARDGetControlBlock(card_slot,local_14);
    if (-1 < (int)cVar1) {
      pcVar2 = __CARDGetDirBlock(local_14[0]);
      pcVar2 = pcVar2 + fileno;
      cVar1 = __CARDAccess(local_14[0],pcVar2);
      if (cVar1 == CARD_ERROR_NOPERM) {
        cVar1 = __CARDIsPublic(pcVar2);
      }
      if (-1 < (int)cVar1) {
        copy_bytes((byte *)stats->mGamecode,(byte *)pcVar2,4);
        copy_bytes((byte *)stats->mCompany,(byte *)pcVar2->mCompany,2);
        stats->mDataLength = (uint)(ushort)pcVar2->mLength * local_14[0]->mDataSize;
        copy_bytes((byte *)stats,(byte *)pcVar2->mFilename,0x20);
        stats->mLastmodified = pcVar2->mLastmodified;
        *(byte *)&stats->mBannerfmt = pcVar2->mBannerfmt;
        stats->mIconaddr = pcVar2->mIconaddr;
        stats->mIconfmt = pcVar2->mIconfmt;
        stats->mIconspeed = pcVar2->mIconspeed;
        stats->mCommentaddr = *(uint *)&pcVar2->mChksum_01;
        UpdateIconOffsets(pcVar2,stats);
      }
      cVar1 = __CARDPutControlBlock(local_14[0],cVar1);
    }
  }
  return cVar1;
}


card_errors CARDSetStatusAsync(int card_slot,int fileno,card_status *status,void *callback)

{
  card_errors cVar1;
  card_direntry *pcVar2;
  uint extraout_r4;
  CardBlockData *local_18 [2];
  
  if ((((fileno < 0) || (0x7e < fileno)) ||
      ((status->mIconaddr != 0xffffffff && (0x1ff < status->mIconaddr)))) ||
     ((status->mCommentaddr != 0xffffffff && (0x1fc0 < (status->mCommentaddr & 0x1fff))))) {
    cVar1 = CARD_ERROR_FATAL_ERROR;
  }
  else {
    cVar1 = __CARDGetControlBlock(card_slot,local_18);
    if (-1 < (int)cVar1) {
      pcVar2 = __CARDGetDirBlock(local_18[0]);
      pcVar2 = pcVar2 + fileno;
      cVar1 = __CARDAccess(local_18[0],pcVar2);
      if ((int)cVar1 < 0) {
        cVar1 = __CARDPutControlBlock(local_18[0],cVar1);
      }
      else {
        pcVar2->mBannerfmt = *(byte *)&status->mBannerfmt;
        pcVar2->mIconaddr = status->mIconaddr;
        pcVar2->mIconfmt = status->mIconfmt;
        pcVar2->mIconspeed = status->mIconspeed;
        *(uint *)&pcVar2->mChksum_01 = status->mCommentaddr;
        UpdateIconOffsets(pcVar2,status);
        if (pcVar2->mIconaddr == 0xffffffff) {
          pcVar2->mIconspeed = pcVar2->mIconspeed & 0xfffcU | 1;
        }
        os::OSGetTime();
        Runtime.PPCEABI.H::__div2i();
        pcVar2->mLastmodified = extraout_r4;
        cVar1 = __CARDUpdateDir(card_slot,callback);
        if ((int)cVar1 < 0) {
          __CARDPutControlBlock(local_18[0],cVar1);
        }
      }
    }
  }
  return cVar1;
}


card_errors CARDSetStatus(int card_slot,int fileno,card_status *stats)

{
  card_errors cVar1;
  
  cVar1 = CARDSetStatusAsync(card_slot,fileno,stats,__CARDSyncCallback);
  if (-1 < (int)cVar1) {
    cVar1 = __CARDSync(card_slot);
  }
  return cVar1;
}

