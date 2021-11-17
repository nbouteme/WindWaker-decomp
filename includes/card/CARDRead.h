#pragma once
#include <ctypes.h>



namespace card {
card_errors __CARDSeek(CARDFileInfo *file,int len,uint offset,CardBlockData **param_4);
void ReadCallback(int param_1,card_errors param_2);
card_errors CARDReadAsync(CARDFileInfo *file,void *buffer,uint len,uint offset,void *callback);
card_errors CARDRead(CARDFileInfo *file,void *buffer,uint len,uint offset);
}
