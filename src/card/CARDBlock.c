#include <card/CARDBlock.h>
#include <card/CARDBios.h>
#include <card/CARDBlock.h>
#include <card/CARDRdwr.h>
#include <card/CARDCheck.h>
#include <os/OSCache.h>


namespace card {

card_fat_block * __CARDGetFatBlock(CardBlockData *param_1)

{
  return (param_1->mCard_block).mpCurr_fat;
}


void WriteCallback(int param_1,card_errors param_2)

{
  code *pcVar1;
  card_workarea *pcVar2;
  card_workarea *dst;
  card_fat_block *src;
  
  if (-1 < (int)param_2) {
    pcVar2 = __CARDBlock[param_1].mCard_block.mpWorkarea;
    dst = pcVar2 + 1;
    src = (card_fat_block *)&pcVar2[1].mWorkarea1;
    if ((card_workarea *)__CARDBlock[param_1].mCard_block.mpCurr_fat == dst) {
      __CARDBlock[param_1].mCard_block.mpCurr_fat = src;
      copy_bytes((byte *)src,(byte *)dst,0x2000);
    }
    else {
      __CARDBlock[param_1].mCard_block.mpCurr_fat = (card_fat_block *)dst;
      copy_bytes((byte *)dst,(byte *)src,0x2000);
    }
  }
  if (__CARDBlock[param_1].mpAttach_cb == (void *)0x0) {
    __CARDPutControlBlock(__CARDBlock + param_1,param_2);
  }
  pcVar1 = (code *)__CARDBlock[param_1].mpUpdate_cb;
  if (pcVar1 != (code *)0x0) {
    __CARDBlock[param_1].mpUpdate_cb = (void *)0x0;
    (*pcVar1)(param_1,param_2);
  }
  return;
}


void EraseCallback(int param_1,card_errors param_2)

{
  code *pcVar1;
  card_fat_block *buffer;
  
  if (((int)param_2 < 0) ||
     (buffer = __CARDBlock[param_1].mCard_block.mpCurr_fat,
     param_2 = __CARDWrite(param_1,__CARDBlock[param_1].mDataSize *
                                   ((uint)((int)buffer -
                                          (int)__CARDBlock[param_1].mCard_block.mpWorkarea) >> 0xd),
                           0x2000,buffer,WriteCallback), (int)param_2 < 0)) {
    if (__CARDBlock[param_1].mpAttach_cb == (void *)0x0) {
      __CARDPutControlBlock(__CARDBlock + param_1,param_2);
    }
    pcVar1 = (code *)__CARDBlock[param_1].mpUpdate_cb;
    if (pcVar1 != (code *)0x0) {
      __CARDBlock[param_1].mpUpdate_cb = (void *)0x0;
      (*pcVar1)(param_1,param_2);
    }
  }
  return;
}


card_errors __CARDAllocBlock(int card_slot,uint size)

{
  card_errors cVar1;
  card_fat_block *pcVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  ushort unaff_r31;
  
  if (__CARDBlock[card_slot].mCardMounted == 0) {
    cVar1 = CARD_ERROR_NOCARD;
  }
  else {
    pcVar2 = __CARDBlock[card_slot].mCard_block.mpCurr_fat;
    if ((ushort)pcVar2->mFreeblocks < size) {
      cVar1 = CARD_ERROR_INSSPACE;
    }
    else {
      pcVar2->mFreeblocks = pcVar2->mFreeblocks - (short)size;
      uVar3 = pcVar2->mLastalloc;
      uVar6 = 0;
      uVar5 = 0xffff;
      while (size != 0) {
        uVar6 = uVar6 + 1;
        if ((int)((ushort)__CARDBlock[card_slot].mMaxBlockSize - 5) < (int)(uVar6 & 0xffff)) {
          return CARD_ERROR_BROKEN;
        }
        uVar3 = uVar3 + 1;
        if ((uVar3 < 5) || ((uint)(ushort)__CARDBlock[card_slot].mMaxBlockSize <= (uint)uVar3)) {
          uVar3 = 5;
        }
        if (pcVar2->mFat[uVar3 - 5] == 0) {
          uVar4 = uVar3;
          if (uVar5 != 0xffff) {
            pcVar2->mFat[unaff_r31 - 5] = uVar3;
            uVar4 = uVar5;
          }
          pcVar2->mFat[uVar3 - 5] = -1;
          size = size - 1;
          unaff_r31 = uVar3;
          uVar5 = uVar4;
        }
      }
      pcVar2->mLastalloc = uVar3;
      __CARDBlock[card_slot].mBlock = uVar5;
      cVar1 = __CARDUpdateFatBlock(card_slot,pcVar2);
    }
  }
  return cVar1;
}


void __CARDUpdateFatBlock(int card_slot,int param_2,void *param_3)

{
  *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + 1;
  __CARDCheckSum(param_2 + 4,0x1ffc,param_2,param_2 + 2);
  os::DCStoreRange(param_2,0x2000);
  __CARDBlock[card_slot].mpUpdate_cb = param_3;
  __CARDEraseSector(card_slot,
                    __CARDBlock[card_slot].mDataSize *
                    ((uint)(param_2 - (int)__CARDBlock[card_slot].mCard_block.mpWorkarea) >> 0xd),
                    EraseCallback);
  return;
}

