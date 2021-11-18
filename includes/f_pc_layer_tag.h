#pragma once
#include <ctypes.h>

#include <layer_management_tag_class.h>


namespace f_pc_layer_tag {
//[Data] Expected size is 0x00001c
extern struct layer_management_tag_class crear$2201;

undefined4 fpcLyTg_ToQueue(layer_management_tag_class *param_1,uint layerID,ushort param_3,ushort param_4);
bool fpcLyTg_QueueTo(layer_management_tag_class *param_1);
undefined4 fpcLyTg_Move(layer_management_tag_class *param_1,uint param_2,ushort param_3,ushort param_4);
uint fpcLyTg_Init(layer_management_tag_class *param_1,uint layerID,void *param_3);
}
