#pragma once
#include <ctypes.h>



namespace f_pc_layer_tag {
undefined4 fpcLyTg_ToQueue(layer_management_tag_class *param_1,uint layerID,ushort param_3,ushort param_4);
bool fpcLyTg_QueueTo(layer_management_tag_class *param_1);
undefined4 fpcLyTg_Move(layer_management_tag_class *param_1,uint param_2,ushort param_3,ushort param_4);
uint fpcLyTg_Init(layer_management_tag_class *param_1,uint layerID,void *param_3);
}
