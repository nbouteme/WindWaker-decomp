#pragma once
#include <ctypes.h>



namespace card {
void UpdateIconOffsets(card_direntry *param_1,card_status *stats);
card_errors CARDGetStatus(int card_slot,int fileno,card_status *stats);
card_errors CARDSetStatusAsync(int card_slot,int fileno,card_status *status,void *callback);
card_errors CARDSetStatus(int card_slot,int fileno,card_status *stats);
}
