#pragma once
#include <ctypes.h>



namespace f_pc_method_tag {
void fpcMtdTg_Do(process_method_tag_class *param_1);
int fpcMtdTg_ToMethodQ(node_list_class *param_1,create_tag_class *param_2);
void fpcMtdTg_MethodQTo(create_tag_class *param_1);
int fpcMtdTg_Init(process_method_tag_class *param_1,void *param_2,void *param_3);
}
