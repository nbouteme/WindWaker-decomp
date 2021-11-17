#include <card/CARDWrite.h>
#include <card/CARDDir.h>
#include <os/OSTime.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <card/CARDBlock.h>
#include <card/CARDWrite.h>
#include <card/CARDBios.h>
#include <card/CARDRdwr.h>
#include <card/CARDRead.h>
#include <card/CARDOpen.h>
#include <os/OSCache.h>


namespace card {

void WriteCallback(int param_1,card_errors param_2)

{
  card_direntry *pcVar1;
  uint extraout_r4;
  void *callback;
  uint uVar2;
  int iVar3;
  CARDFileInfo *pCVar4;
  code *pcVar5;
  CardBlockData *pCVar6;
  
  pCVar6 = __CARDBlock + param_1;
  if (-1 < (int)param_2) {
    pCVar4 = __CARDBlock[param_1].mpCardFile;
    if (pCVar4->mLen < 0) {
      param_2 = CARD_ERROR_CANCELED;
    }
    else {
      pCVar4->mLen = pCVar4->mLen - __CARDBlock[param_1].mDataSize;
      if (pCVar4->mLen < 1) {
        pcVar1 = __CARDGetDirBlock(pCVar6);
        iVar3 = pCVar4->mFilenum;
        os::OSGetTime();
        Runtime.PPCEABI.H::__div2i();
        pcVar1[iVar3].mLastmodified = extraout_r4;
        callback = __CARDBlock[param_1].mpAttach_cb;
        __CARDBlock[param_1].mpAttach_cb = (void *)0x0;
        param_2 = __CARDUpdateDir(param_1,callback);
      }
      else {
        iVar3 = __CARDGetFatBlock(pCVar6);
        pCVar4->mOffset = pCVar4->mOffset + __CARDBlock[param_1].mDataSize;
        pCVar4->m_iblock = *(u16 *)(iVar3 + (uint)pCVar4->m_iblock * 2);
        uVar2 = (uint)pCVar4->m_iblock;
        if ((uVar2 < 5) || ((ushort)__CARDBlock[param_1].mMaxBlockSize <= uVar2)) {
          param_2 = CARD_ERROR_BROKEN;
          goto LAB_8031f24c;
        }
        param_2 = __CARDEraseSector(param_1,__CARDBlock[param_1].mDataSize * uVar2,EraseCallback);
      }
      if (-1 < (int)param_2) {
        return;
      }
    }
  }
LAB_8031f24c:
  pcVar5 = (code *)__CARDBlock[param_1].mpAttach_cb;
  __CARDBlock[param_1].mpAttach_cb = (void *)0x0;
  __CARDPutControlBlock(pCVar6,param_2);
  (*pcVar5)(param_1,param_2);
  return;
}


void EraseCallback(int param_1,card_errors param_2)

{
  code *pcVar1;
  
  if (((int)param_2 < 0) ||
     (param_2 = __CARDWrite(param_1,__CARDBlock[param_1].mDataSize *
                                    (uint)(__CARDBlock[param_1].mpCardFile)->m_iblock,
                            __CARDBlock[param_1].mDataSize,__CARDBlock[param_1].mpBuffer,
                            WriteCallback), (int)param_2 < 0)) {
    pcVar1 = (code *)__CARDBlock[param_1].mpAttach_cb;
    __CARDBlock[param_1].mpAttach_cb = (void *)0x0;
    __CARDPutControlBlock(__CARDBlock + param_1,param_2);
    (*pcVar1)(param_1,param_2);
  }
  return;
}


/* 
   \brief Writes the data to the file from the buffer to the given offset with the given length.
   This function returns immediately. Asynchronous version
   \param[in] file pointer to the card_file structure which holds the fileinformations.
   \param[in] buffer pointer to the memory area to read from. The startaddress of the buffer should
   be aligned on a 32byte boundery.
   \param[in] len length of data to write.
   \param[in] offset starting point in the file to start writing.
   \param[in] callback pointer to a callback function. This callback will be called when the write
   process has finished.
   \return \ref card_errors "card error codes" */

card_errors
CARDWriteAsync(CARDFileInfo *file,void *buffer,uint len,uint offset,code *callback)

{
  card_errors cVar1;
  card_direntry *pcVar2;
  uint uVar3;
  CardBlockData *local_1c [2];
  
  cVar1 = __CARDSeek(file,len,offset,local_1c);
  if (-1 < (int)cVar1) {
    uVar3 = local_1c[0]->mDataSize - 1;
    if (((offset & uVar3) == 0) && ((len & uVar3) == 0)) {
      pcVar2 = __CARDGetDirBlock(local_1c[0]);
      cVar1 = __CARDAccess(local_1c[0],pcVar2 + file->mFilenum);
      if ((int)cVar1 < 0) {
        cVar1 = __CARDPutControlBlock(local_1c[0],cVar1);
      }
      else {
        os::DCStoreRange(buffer,len);
        if (callback == (code *)0x0) {
          callback = __CARDDefaultApiCallback;
        }
        local_1c[0]->mpAttach_cb = callback;
        local_1c[0]->mpBuffer = buffer;
        cVar1 = __CARDEraseSector(file->mSlot,local_1c[0]->mDataSize * (uint)file->m_iblock,
                                  EraseCallback);
        if ((int)cVar1 < 0) {
          __CARDPutControlBlock(local_1c[0],cVar1);
        }
      }
    }
    else {
      cVar1 = __CARDPutControlBlock(local_1c[0],CARD_ERROR_FATAL_ERROR);
    }
  }
  return cVar1;
}


/* 
   \brief Writes the data to the file from the buffer to the given offset with the given length.
   Synchronous version
   \param[in] file pointer to the card_file structure which holds the fileinformations.
   \param[in] buffer pointer to the memory area to read from. The startaddress of the buffer should
   be aligned on a 32byte boundery.
   \param[in] len length of data to write.
   \param[in] offset starting point in the file to start writing.
   \return \ref card_errors "card error codes" */

card_errors CARDWrite(CARDFileInfo *file,void *buffer,uint len,uint offset)

{
  card_errors cVar1;
  
  cVar1 = CARDWriteAsync(file,buffer,len,offset,__CARDSyncCallback);
  if (-1 < (int)cVar1) {
    cVar1 = __CARDSync(file->mSlot);
  }
  return cVar1;
}

