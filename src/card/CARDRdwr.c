#include <card/CARDRdwr.h>
#include <card/CARDRdwr.h>
#include <card/CARDBios.h>


namespace card {

void BlockReadCallback(int param_1,card_errors param_2)

{
  int iVar1;
  code *pcVar2;
  
  if (-1 < (int)param_2) {
    *(int *)&__CARDBlock[param_1].field_0xb8 = *(int *)&__CARDBlock[param_1].field_0xb8 + 0x200;
    __CARDBlock[param_1].mDataLen = __CARDBlock[param_1].mDataLen + 0x200;
    __CARDBlock[param_1].mpBuffer = (void *)((int)__CARDBlock[param_1].mpBuffer + 0x200);
    iVar1 = __CARDBlock[param_1].mDataIndex + -1;
    __CARDBlock[param_1].mDataIndex = iVar1;
    if ((0 < iVar1) && (param_2 = __CARDReadSegment(param_1,BlockReadCallback), -1 < (int)param_2))
    {
      return;
    }
  }
  if (__CARDBlock[param_1].mpAttach_cb == (void *)0x0) {
    __CARDPutControlBlock(__CARDBlock + param_1,param_2);
  }
  pcVar2 = (code *)__CARDBlock[param_1].mpDefault_cb;
  if (pcVar2 != (code *)0x0) {
    __CARDBlock[param_1].mpDefault_cb = (void *)0x0;
    (*pcVar2)(param_1,param_2);
  }
  return;
}


card_errors __CARDRead(int card_slot,uint len,uint offset,void *buffer,void *read_cb)

{
  card_errors cVar1;
  
  if (__CARDBlock[card_slot].mCardMounted == 0) {
    cVar1 = CARD_ERROR_NOCARD;
  }
  else {
    __CARDBlock[card_slot].mpDefault_cb = read_cb;
                    /* mDataIndex = offset / 512 (0x200) */
    __CARDBlock[card_slot].mDataIndex = offset >> 9;
    __CARDBlock[card_slot].mDataLen = len;
    __CARDBlock[card_slot].mpBuffer = buffer;
    cVar1 = __CARDReadSegment(card_slot,BlockReadCallback);
  }
  return cVar1;
}


void BlockWriteCallback(int param_1,card_errors param_2)

{
  int iVar1;
  code *pcVar2;
  
  if (-1 < (int)param_2) {
    *(int *)&__CARDBlock[param_1].field_0xb8 = *(int *)&__CARDBlock[param_1].field_0xb8 + 0x80;
    __CARDBlock[param_1].mDataLen = __CARDBlock[param_1].mDataLen + 0x80;
    __CARDBlock[param_1].mpBuffer = (void *)((int)__CARDBlock[param_1].mpBuffer + 0x80);
    iVar1 = __CARDBlock[param_1].mDataIndex + -1;
    __CARDBlock[param_1].mDataIndex = iVar1;
    if ((0 < iVar1) && (param_2 = __CARDWritePage(param_1,BlockWriteCallback), -1 < (int)param_2)) {
      return;
    }
  }
  if (__CARDBlock[param_1].mpAttach_cb == (void *)0x0) {
    __CARDPutControlBlock(__CARDBlock + param_1,param_2);
  }
  pcVar2 = (code *)__CARDBlock[param_1].mpDefault_cb;
  if (pcVar2 != (code *)0x0) {
    __CARDBlock[param_1].mpDefault_cb = (void *)0x0;
    (*pcVar2)(param_1,param_2);
  }
  return;
}


card_errors __CARDWrite(int card_slot,int len,uint offset,void *buffer,void *callback)

{
  card_errors cVar1;
  
  if (__CARDBlock[card_slot].mCardMounted == 0) {
    cVar1 = CARD_ERROR_NOCARD;
  }
  else {
    __CARDBlock[card_slot].mpDefault_cb = callback;
                    /* mDataIndex = offset / 128 */
    __CARDBlock[card_slot].mDataIndex = offset >> 7;
    __CARDBlock[card_slot].mDataLen = len;
    __CARDBlock[card_slot].mpBuffer = buffer;
    cVar1 = __CARDWritePage(card_slot,BlockWriteCallback);
  }
  return cVar1;
}

