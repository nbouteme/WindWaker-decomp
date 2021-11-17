#include <card/CARDOpen.h>
#include <MSL_C.PPCEABI.bare.H/mem.h>
#include <card/CARDBios.h>
#include <card/CARDDir.h>
#include <card/CARDOpen.h>


namespace card {

bool __CARDCompareFileName(card_file_header *file_header,char *filename)

{
  char cVar1;
  char cVar2;
  char *header_filename;
  int maxFilenameSize;
  
  header_filename = file_header->mFilename;
  maxFilenameSize = 0x20;
  do {
    maxFilenameSize = maxFilenameSize + -1;
    if (maxFilenameSize < 0) {
      if (*filename == '\0') {
        return true;
      }
      return false;
    }
    cVar1 = *header_filename;
    header_filename = header_filename + 1;
    cVar2 = *filename;
    filename = filename + 1;
    if (cVar1 != cVar2) {
      return false;
    }
  } while (cVar2 != '\0');
  return true;
}


card_errors __CARDAccess(CardBlockData *param_1,card_direntry *param_2)

{
  card_errors cVar1;
  int iVar2;
  
  if (param_2->mGamecode[0] == -1) {
    cVar1 = CARD_ERROR_NOFILE;
  }
  else {
    if ((param_1->mpDiskID == &__CARDDiskNone) ||
       ((iVar2 = MSL_C.PPCEABI.bare.H::memcmp(param_2,param_1->mpDiskID,4), iVar2 == 0 &&
        (iVar2 = MSL_C.PPCEABI.bare.H::memcmp(param_2->mCompany,param_1->mpDiskID + 4,2), iVar2 == 0
        )))) {
      cVar1 = CARD_ERROR_READY;
    }
    else {
      cVar1 = CARD_ERROR_NOPERM;
    }
  }
  return cVar1;
}


card_errors __CARDIsPublic(card_direntry *param_1)

{
  if (param_1->mGamecode[0] == -1) {
    return CARD_ERROR_NOFILE;
  }
  if ((param_1->mPermission & 4) != 0) {
    return CARD_ERROR_READY;
  }
  return CARD_ERROR_NOPERM;
}


/* 
   \brief Opens the file with the given filename and fills in the fileinformations.
   \param[in] chn CARD slot
   \param[in] filename name of the file to open.
   \param[out] file pointer to the card_file structure. It receives the fileinformations for later
   usage.
   \return \ref card_errors "card error codes" */

card_errors CARDOpen(int card_slot,char *filename,CARDFileInfo *file)

{
  int iVar1;
  card_errors card_status;
  card_file_header *currCardHeader;
  bool bVar2;
  card_direntry *cardHeader;
  char *gameID;
  int cardSlotCount;
  int cardSlotID;
  CardBlockData *local_2c [2];
  ushort cardIndex;
  CardBlockData *controlBlockHeader;
  
  file->mSlot = -1;
  card_status = __CARDGetControlBlock(card_slot,local_2c);
  controlBlockHeader = local_2c[0];
  if (-1 < (int)card_status) {
    if (local_2c[0]->mCardMounted == 0) {
      card_status = CARD_ERROR_NOCARD;
    }
    else {
      currCardHeader = (card_file_header *)__CARDGetDirBlock(local_2c[0]);
      cardSlotCount = 0;
      do {
        if (currCardHeader->mGameCode[0] == -1) {
          iVar1 = -4;
        }
        else {
          gameID = controlBlockHeader->mpDiskID;
          if ((gameID == &__CARDDiskNone) ||
             ((iVar1 = MSL_C.PPCEABI.bare.H::memcmp(currCardHeader,gameID,4), iVar1 == 0 &&
              (iVar1 = MSL_C.PPCEABI.bare.H::memcmp
                                 (currCardHeader->mCompany,controlBlockHeader->mpDiskID + 4,2),
              iVar1 == 0)))) {
            iVar1 = 0;
          }
          else {
            iVar1 = -10;
          }
        }
        if ((-1 < iVar1) && (bVar2 = __CARDCompareFileName(currCardHeader,filename), bVar2 != false)
           ) {
          card_status = CARD_ERROR_READY;
          cardSlotID = cardSlotCount;
          goto LAB_8031e850;
        }
        cardSlotCount = cardSlotCount + 1;
        currCardHeader = currCardHeader + 1;
      } while (cardSlotCount < 0x7f);
      card_status = CARD_ERROR_NOFILE;
    }
LAB_8031e850:
    if (-1 < (int)card_status) {
      cardHeader = __CARDGetDirBlock(local_2c[0]);
      cardIndex = cardHeader[cardSlotID].mBlock;
      if ((cardIndex < 5) || ((ushort)local_2c[0]->mMaxBlockSize <= cardIndex)) {
        card_status = CARD_ERROR_BROKEN;
      }
      else {
        file->mSlot = card_slot;
        file->mFilenum = cardSlotID;
        file->mOffset = 0;
        file->m_iblock = cardHeader[cardSlotID].mBlock;
      }
    }
    card_status = __CARDPutControlBlock(local_2c[0],card_status);
  }
  return card_status;
}


card_errors CARDClose(CARDFileInfo *card_slot)

{
  card_errors cVar1;
  CardBlockData *local_c [2];
  
  cVar1 = __CARDGetControlBlock(card_slot->mSlot,local_c);
  if (-1 < (int)cVar1) {
    card_slot->mSlot = -1;
    cVar1 = __CARDPutControlBlock(local_c[0],CARD_ERROR_READY);
  }
  return cVar1;
}

