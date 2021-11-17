#pragma once
#include <ctypes.h>



namespace card {
void CreateCallbackFat(int card_slot,card_errors card_status);
card_errors CARDCreateAsync(int card_slot,char *filename,uint size,CARDFileInfo *file,code *callback);
card_errors CARDCreate(int card_slot,char *filename,int size,CARDFileInfo *file);
}
