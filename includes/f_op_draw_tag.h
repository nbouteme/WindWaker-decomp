#pragma once
#include <ctypes.h>

#include <node_lists_tree_class.h>


namespace f_op_draw_tag {
//[Data] Expected size is 0x000008
extern struct node_lists_tree_class g_fopDwTg_Queue;

//[BSS] Expected size is 0x002ee0
extern undefined lists$2178;
void fopDwTg_ToDrawQ(create_tag_class *param_1,int priority);
void fopDwTg_DrawQTo(create_tag_class *param_1);
undefined4 fopDwTg_Init(create_tag_class *param_1,void *param_2);
void fopDwTg_CreateQueue(void);
}
