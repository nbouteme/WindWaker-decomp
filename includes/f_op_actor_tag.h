#pragma once
#include <ctypes.h>

#include <node_list_class.h>


namespace f_op_actor_tag {
//[Data] Expected size is 0x00000c
extern struct node_list_class g_fopAcTg_Queue;

void fopAcTg_ToActorQ(create_tag_class *param_1);
void fopAcTg_ActorQTo(create_tag_class *param_1);
undefined4 fopAcTg_Init(create_tag_class *param_1,void *param_2);
}
