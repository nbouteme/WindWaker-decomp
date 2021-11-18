#pragma once
#include <ctypes.h>



namespace card {
//[Data] Expected size is 0x000020
extern undefined SectorSizeTable;

//[Data] Expected size is 0x000020
extern undefined LatencyTable;

bool IsCard(undefined1 *param_1);
card_errors CARDProbe(int card_slot);
card_errors CARDProbeEx(int card_slot,uint *mem_size,uint *sect_size);
card_errors DoMount(int param_1);
void __CARDMountCallback(int param_1,card_errors param_2);
card_errors CARDMountAsync(int card_slot,void *workarea,int detach_cb,code *attach_cb);
card_errors CARDMount(int card_slot,void *workarea,int detatch_cb);
void DoUnmount(int param_1,card_errors param_2);
card_errors CARDUnmount(int card_slot);
}
