#pragma once
#include <ctypes.h>



namespace card {
card_fat_block * __CARDGetFatBlock(CardBlockData *param_1);
void WriteCallback(int param_1,card_errors param_2);
void EraseCallback(int param_1,card_errors param_2);
card_errors __CARDAllocBlock(int card_slot,uint size);
void __CARDUpdateFatBlock(int card_slot,int param_2,void *param_3);
}
