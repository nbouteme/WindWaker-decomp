#pragma once
#include <ctypes.h>



namespace card {
void WriteCallback(int param_1,card_errors param_2);
void EraseCallback(int param_1,card_errors param_2);
card_errors CARDWriteAsync(CARDFileInfo *file,void *buffer,uint len,uint offset,code *callback);
card_errors CARDWrite(CARDFileInfo *file,void *buffer,uint len,uint offset);
}
