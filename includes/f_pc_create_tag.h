#pragma once
#include <ctypes.h>

#include <node_list_class.h>


namespace f_pc_create_tag {
//[Data] Expected size is 0x00000c
extern struct node_list_class g_fpcCtTg_Queue;

void fpcCtTg_ToCreateQ(create_tag *param_1);
void fpcCtTg_CreateQTo(create_tag *param_1);
undefined4 fpcCtTg_Init(create_tag *param_1,void *param_2);
}
