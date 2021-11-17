#pragma once
#include <ctypes.h>



namespace card {
void BlockReadCallback(int param_1,card_errors param_2);
card_errors __CARDRead(int card_slot,uint len,uint offset,void *buffer,void *read_cb);
void BlockWriteCallback(int param_1,card_errors param_2);
card_errors __CARDWrite(int card_slot,int len,uint offset,void *buffer,void *callback);
}
