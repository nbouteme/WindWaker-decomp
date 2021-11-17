#pragma once
#include <ctypes.h>



namespace card {
bool __CARDCompareFileName(card_file_header *file_header,char *filename);
card_errors __CARDAccess(CardBlockData *param_1,card_direntry *param_2);
card_errors __CARDIsPublic(card_direntry *param_1);
card_errors CARDOpen(int card_slot,char *filename,CARDFileInfo *file);
card_errors CARDClose(CARDFileInfo *card_slot);
}
