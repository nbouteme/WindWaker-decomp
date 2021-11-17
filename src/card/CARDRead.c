#include <card/CARDRead.h>
#include <card/CARDBios.h>
#include <card/CARDDir.h>
#include <card/CARDBlock.h>
#include <card/CARDRead.h>
#include <card/CARDRdwr.h>
#include <card/CARDOpen.h>
#include <os/OSCache.h>


namespace card {

card_errors __CARDSeek(CARDFileInfo *file,int len,uint offset,CardBlockData **param_4)

{
  int iVar1;
  card_errors cVar2;
  card_direntry *pcVar3;
  int iVar4;
  CardBlockData *local_18 [2];
  
  cVar2 = __CARDGetControlBlock(file->mSlot,local_18);
  if (-1 < (int)cVar2) {
    if (((file->m_iblock < 5) || ((uint)(ushort)local_18[0]->mMaxBlockSize <= (uint)file->m_iblock))
       || ((int)((uint)(ushort)local_18[0]->mMaxBlockSize * local_18[0]->mDataSize) <= file->mOffset
          )) {
      cVar2 = __CARDPutControlBlock(local_18[0],CARD_ERROR_FATAL_ERROR);
    }
    else {
      pcVar3 = __CARDGetDirBlock(local_18[0]);
      iVar1 = file->mFilenum;
      iVar4 = (uint)(ushort)pcVar3[iVar1].mLength * local_18[0]->mDataSize;
      if (((int)offset < iVar4) && ((int)(offset + len) <= iVar4)) {
        local_18[0]->mpCardFile = file;
        file->mLen = len;
        if ((int)offset < file->mOffset) {
          file->mOffset = 0;
          file->m_iblock = pcVar3[iVar1].mBlock;
          if ((file->m_iblock < 5) || ((ushort)local_18[0]->mMaxBlockSize <= file->m_iblock)) {
            cVar2 = __CARDPutControlBlock(local_18[0],CARD_ERROR_BROKEN);
            return cVar2;
          }
        }
        iVar1 = __CARDGetFatBlock(local_18[0]);
        do {
          if ((offset & ~(local_18[0]->mDataSize - 1U)) <= (uint)file->mOffset) {
            file->mOffset = offset;
            *param_4 = local_18[0];
            return CARD_ERROR_READY;
          }
          file->mOffset = file->mOffset + local_18[0]->mDataSize;
          file->m_iblock = *(u16 *)(iVar1 + (uint)file->m_iblock * 2);
        } while ((4 < file->m_iblock) && (file->m_iblock < (ushort)local_18[0]->mMaxBlockSize));
        cVar2 = __CARDPutControlBlock(local_18[0],CARD_ERROR_BROKEN);
      }
      else {
        cVar2 = __CARDPutControlBlock(local_18[0],CARD_ERROR_LIMIT);
      }
    }
  }
  return cVar2;
}


void ReadCallback(int param_1,card_errors param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint offset;
  int iVar4;
  code *pcVar5;
  CARDFileInfo *pCVar6;
  
  if (-1 < (int)param_2) {
    pCVar6 = __CARDBlock[param_1].mpCardFile;
    if (pCVar6->mLen < 0) {
      param_2 = CARD_ERROR_CANCELED;
    }
    else {
      iVar4 = (~(__CARDBlock[param_1].mDataSize - 1U) &
              pCVar6->mOffset + __CARDBlock[param_1].mDataSize) - pCVar6->mOffset;
      pCVar6->mLen = pCVar6->mLen - iVar4;
      if (0 < pCVar6->mLen) {
        iVar2 = __CARDGetFatBlock(__CARDBlock + param_1);
        pCVar6->mOffset = pCVar6->mOffset + iVar4;
        pCVar6->m_iblock = *(u16 *)(iVar2 + (uint)pCVar6->m_iblock * 2);
        uVar3 = (uint)pCVar6->m_iblock;
        if ((uVar3 < 5) || ((ushort)__CARDBlock[param_1].mMaxBlockSize <= uVar3)) {
          param_2 = CARD_ERROR_BROKEN;
        }
        else {
          uVar1 = __CARDBlock[param_1].mDataSize;
          offset = uVar1;
          if (pCVar6->mLen < (int)uVar1) {
            offset = pCVar6->mLen;
          }
          param_2 = __CARDRead(param_1,uVar1 * uVar3,offset,__CARDBlock[param_1].mpBuffer,
                               ReadCallback);
          if (-1 < (int)param_2) {
            return;
          }
        }
      }
    }
  }
  pcVar5 = (code *)__CARDBlock[param_1].mpAttach_cb;
  __CARDBlock[param_1].mpAttach_cb = (void *)0x0;
  __CARDPutControlBlock(__CARDBlock + param_1,param_2);
  (*pcVar5)(param_1,param_2);
  return;
}


/* \brief Reads the data from the file into the buffer from the given offset with the given length.
   This function returns immediately. Asynchronous version
   \param[in] file pointer to the card_file structure. It holds the fileinformations to read from.
   \param[out] buffer pointer to memory area read-in the data. The startaddress of the buffer should
   be aligned to a 32byte boundery.
   
   \param[in] len length of data to read.
   \param[in] offset offset into the file to read from.
   \param[in] callback pointer to a callback function. This callback will be called when the read
   process has finished.
   \return \ref card_errors "card error codes" */

card_errors CARDReadAsync(CARDFileInfo *file,void *buffer,uint len,uint offset,void *callback)

{
  int curr_slot;
  code *pcVar1;
  card_errors cVar2;
  card_direntry *curr_file_header;
  uint offset_00;
  uint uVar3;
  CardBlockData *local_1c [2];
  
  if (((offset & 0x1ff) == 0) && ((len & 0x1ff) == 0)) {
    cVar2 = __CARDSeek(file,len,offset,local_1c);
    if (-1 < (int)cVar2) {
      curr_file_header = __CARDGetDirBlock(local_1c[0]);
      curr_slot = file->mFilenum;
      cVar2 = __CARDAccess(local_1c[0],curr_file_header + curr_slot);
      if (cVar2 == CARD_ERROR_NOPERM) {
        cVar2 = __CARDIsPublic(curr_file_header + curr_slot);
      }
      if ((int)cVar2 < 0) {
        cVar2 = __CARDPutControlBlock(local_1c[0],cVar2);
      }
      else {
        os::DCInvalidateRange(buffer,len);
        pcVar1 = (code *)callback;
        if (callback == (void *)0x0) {
          pcVar1 = __CARDDefaultApiCallback;
        }
        local_1c[0]->mpAttach_cb = pcVar1;
        curr_slot = local_1c[0]->mDataSize;
        uVar3 = file->mOffset & curr_slot - 1U;
        offset_00 = curr_slot - uVar3;
        if ((int)len < (int)offset_00) {
          offset_00 = len;
        }
        cVar2 = __CARDRead(file->mSlot,uVar3 + curr_slot * (uint)file->m_iblock,offset_00,buffer,
                           ReadCallback);
        if ((int)cVar2 < 0) {
          __CARDPutControlBlock(local_1c[0],cVar2);
        }
      }
    }
  }
  else {
    cVar2 = CARD_ERROR_FATAL_ERROR;
  }
  return cVar2;
}


/* 
   \brief Reads the data from the file into the buffer from the given offset with the given length.
   Synchronous version
   \param[in] file pointer to the card_file structure. It holds the fileinformations to read from.
   \param[out] buffer pointer to memory area read-in the data. The startaddress of the buffer should
   be aligned to a 32byte boundery.
   \param[in] len length of data to read.
   \param[in] offset offset into the file to read from.
   \return \ref card_errors "card error codes" */

card_errors CARDRead(CARDFileInfo *file,void *buffer,uint len,uint offset)

{
  card_errors cVar1;
  
  cVar1 = CARDReadAsync(file,buffer,len,offset,__CARDSyncCallback);
  if (-1 < (int)cVar1) {
    cVar1 = __CARDSync(file->mSlot);
  }
  return cVar1;
}

