#pragma once
#include <ctypes.h>



namespace card {
void FormatCallback(int param_1,card_errors param_2);
card_errors __CARDFormatRegionAsync(int card_slot,undefined2 param_2,code *attach_cb);
card_errors CARDFormat(int card_slot);
}
