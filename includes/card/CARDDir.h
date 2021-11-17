#pragma once
#include <ctypes.h>



namespace card {
card_direntry * __CARDGetDirBlock(CardBlockData *param_1);
void WriteCallback(int param_1,card_errors param_2);
void EraseCallback(int param_1,card_errors param_2);
card_errors __CARDUpdateDir(int card_slot,void *callback);
}
