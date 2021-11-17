#include <card/CARDCreate.h>
#include <card/CARDDir.h>
#include <os/OSTime.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <card/CARDBios.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <MSL_C.PPCEABI.bare.H/mem.h>
#include <card/CARDOpen.h>
#include <card/CARDBlock.h>
#include <card/CARDCreate.h>


namespace card {

void CreateCallbackFat(int card_slot,card_errors card_status)

{
  card_direntry *dest_header;
  uint extraout_r4;
  code *callback;
  
  callback = (code *)__CARDBlock[card_slot].mpAttach_cb;
  __CARDBlock[card_slot].mpAttach_cb = (void *)0x0;
  if (-1 < (int)card_status) {
    dest_header = __CARDGetDirBlock(__CARDBlock + card_slot);
    dest_header = dest_header + __CARDBlock[card_slot].mDirIndex;
    copy_bytes((byte *)dest_header,(byte *)__CARDBlock[card_slot].mpDiskID,4);
    copy_bytes((byte *)dest_header->mCompany,(byte *)(__CARDBlock[card_slot].mpDiskID + 4),2);
    dest_header->mPermission = 4;
    dest_header->mCopytimes = 0;
    dest_header->mBlock = __CARDBlock[card_slot].mBlock;
    dest_header->mBannerfmt = 0;
    dest_header->mIconaddr = 0xffffffff;
    dest_header->mIconfmt = 0;
    dest_header->mIconspeed = 0;
    *(undefined4 *)&dest_header->mChksum_01 = 0xffffffff;
    dest_header->mIconspeed = dest_header->mIconspeed & 0xfffcU | 1;
    (__CARDBlock[card_slot].mpCardFile)->mOffset = 0;
    (__CARDBlock[card_slot].mpCardFile)->m_iblock = dest_header->mBlock;
    os::OSGetTime();
    Runtime.PPCEABI.H::__div2i();
    dest_header->mLastmodified = extraout_r4;
    card_status = __CARDUpdateDir(card_slot,callback);
    if (-1 < (int)card_status) {
      return;
    }
  }
  __CARDPutControlBlock(__CARDBlock + card_slot,card_status);
  if (callback != (code *)0x0) {
    (*callback)(card_slot,card_status);
  }
  return;
}


/* 
   \brief Creates a new file with the given filename and fills in the fileinformations. This
   function returns immediately. Asynchronous version.
   \param[in] chn CARD slot
   \param[in] filename name of the file to create.
   \param[in] size size of the newly created file.
   \param[out] file pointer to the card_file structure. It receives the fileinformations for later
   usage.
   \param[in] callback pointer to a callback function. This callback will be called when the create
   process has finished.
   \return \ref card_errors "card error codes" */

card_errors
CARDCreateAsync(int card_slot,char *filename,uint size,CARDFileInfo *file,code *callback)

{
  size_t sVar1;
  card_direntry *dir;
  bool bVar3;
  card_errors card_status;
  int iVar2;
  ushort dir_index_ctr;
  card_direntry *curr_dir;
  ushort dirIndex;
  CardBlockData *local_2c [2];
  
  sVar1 = MSL_C.PPCEABI.bare.H::strlen(filename);
  if (sVar1 < 0x21) {
    card_status = __CARDGetControlBlock(card_slot,local_2c);
    if (-1 < (int)card_status) {
      if ((size == 0) || (size != (size / (uint)local_2c[0]->mDataSize) * local_2c[0]->mDataSize)) {
        card_status = CARD_ERROR_FATAL_ERROR;
      }
      else {
        dirIndex = 0xffff;
        dir = __CARDGetDirBlock(local_2c[0]);
        curr_dir = dir;
        for (dir_index_ctr = 0; dir_index_ctr < 0x7f; dir_index_ctr = dir_index_ctr + 1) {
          if (curr_dir->mGamecode[0] == -1) {
            if (dirIndex == 0xffff) {
              dirIndex = dir_index_ctr;
            }
          }
          else {
            iVar2 = MSL_C.PPCEABI.bare.H::memcmp(curr_dir,local_2c[0]->mpDiskID,4);
            if (((iVar2 == 0) &&
                (iVar2 = MSL_C.PPCEABI.bare.H::memcmp
                                   (curr_dir->mCompany,local_2c[0]->mpDiskID + 4,2), iVar2 == 0)) &&
               (bVar3 = __CARDCompareFileName((card_file_header *)curr_dir,filename), bVar3 != false
               )) {
              card_status = __CARDPutControlBlock(local_2c[0],CARD_ERROR_EXIST);
              return card_status;
            }
          }
          curr_dir = curr_dir + 1;
        }
        if (dirIndex == 0xffff) {
          card_status = __CARDPutControlBlock(local_2c[0],CARD_ERROR_NOENT);
        }
        else {
          iVar2 = __CARDGetFatBlock(local_2c[0]);
          if (local_2c[0]->mDataSize * (uint)*(ushort *)(iVar2 + 6) < size) {
            card_status = __CARDPutControlBlock(local_2c[0],CARD_ERROR_INSSPACE);
          }
          else {
            if (callback == (code *)0x0) {
              callback = __CARDDefaultApiCallback;
            }
            local_2c[0]->mpAttach_cb = callback;
            local_2c[0]->mDirIndex = dirIndex;
            dir[dirIndex].mLength = (short)(size / (uint)local_2c[0]->mDataSize);
            MSL_C.PPCEABI.bare.H::strncpy(dir[dirIndex].mFilename,filename,0x20);
            local_2c[0]->mpCardFile = file;
            file->mSlot = card_slot;
            file->mFilenum = (uint)dirIndex;
            card_status = __CARDAllocBlock(card_slot,size / (uint)local_2c[0]->mDataSize);
            if ((int)card_status < 0) {
              card_status = __CARDPutControlBlock(local_2c[0],card_status);
            }
          }
        }
      }
    }
  }
  else {
    card_status = CARD_ERROR_NAMETOOLONG;
  }
  return card_status;
}


/* 
   \brief Creates a new file with the given filename and fills in the fileinformations. Synchronous
   version.
   \param[in] chn CARD slot
   \param[in] filename name of the file to create.
   \param[in] size size of the newly created file.
   \param[out] file pointer to the card_file structure. It receives the fileinformations for later
   usage.
   \return \ref card_errors "card error codes" */

card_errors CARDCreate(int card_slot,char *filename,int size,CARDFileInfo *file)

{
  card_errors cVar1;
  
  cVar1 = CARDCreateAsync(card_slot,filename,size,file,__CARDSyncCallback);
  if (-1 < (int)cVar1) {
    cVar1 = __CARDSync(card_slot);
  }
  return cVar1;
}

