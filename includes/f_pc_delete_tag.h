#pragma once
#include <ctypes.h>

#include <node_list_class.h>


namespace f_pc_delete_tag {
//[Data] Expected size is 0x00000c
extern struct node_list_class g_fpcDtTg_Queue;

uint fpcDtTg_IsEmpty(void);
void fpcDtTg_ToDeleteQ(delete_tag_class *param_1);
void fpcDtTg_DeleteQTo(create_tag_class *param_1);
undefined4 fpcDtTg_Do(delete_tag_class *param_1,undefined *param_2);
undefined4 fpcDtTg_Init(delete_tag_class *param_1,void *param_2);
}
