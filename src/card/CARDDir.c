#include <card/CARDDir.h>
#include <card/CARDBios.h>
#include <card/CARDDir.h>
#include <card/CARDRdwr.h>
#include <card/CARDCheck.h>
#include <os/OSCache.h>


namespace card {

card_direntry * __CARDGetDirBlock(CardBlockData *param_1)

{
  return ((param_1->mCard_block).mpCurr_dir)->mDirEntries;
}


void WriteCallback(int param_1,card_errors param_2)

{
  card_dat *card_data_2;
  code *pcVar1;
  card_workarea *workarea;
  card_dat *card_data_1;
  
  if (-1 < (int)param_2) {
    workarea = __CARDBlock[param_1].mCard_block.mpWorkarea;
    card_data_1 = &workarea->mWorkarea1;
    card_data_2 = &workarea->mWorkarea2;
    if (__CARDBlock[param_1].mCard_block.mpCurr_dir == card_data_1) {
      __CARDBlock[param_1].mCard_block.mpCurr_dir = card_data_2;
      copy_bytes((byte *)card_data_2,(byte *)card_data_1,0x2000);
    }
    else {
      __CARDBlock[param_1].mCard_block.mpCurr_dir = card_data_1;
      copy_bytes((byte *)card_data_1,(byte *)card_data_2,0x2000);
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
  card_direntry *buffer;
  
  if (((int)param_2 < 0) ||
     (buffer = (card_direntry *)__CARDBlock[param_1].mCard_block.mpCurr_dir,
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


card_errors __CARDUpdateDir(int card_slot,void *callback)

{
  card_errors cVar1;
  card_dat *pcVar2;
  
  if (__CARDBlock[card_slot].mCardMounted == 0) {
    cVar1 = CARD_ERROR_NOCARD;
  }
  else {
    pcVar2 = __CARDBlock[card_slot].mCard_block.mpCurr_dir;
    pcVar2->mDirEntries[0x7f].mPad_01 = pcVar2->mDirEntries[0x7f].mPad_01 + 1;
    __CARDCheckSum(pcVar2,0x1ffc,&pcVar2->mDirEntries[0x7f].mChksum_01,
                   &pcVar2->mDirEntries[0x7f].mChksum_02);
    os::DCStoreRange(pcVar2,0x2000);
    __CARDBlock[card_slot].mpUpdate_cb = callback;
    cVar1 = __CARDEraseSector(card_slot,
                              __CARDBlock[card_slot].mDataSize *
                              ((uint)((int)pcVar2 -
                                     (int)__CARDBlock[card_slot].mCard_block.mpWorkarea) >> 0xd),
                              EraseCallback);
  }
  return cVar1;
}

