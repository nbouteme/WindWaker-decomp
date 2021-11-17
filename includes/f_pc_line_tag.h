#pragma once
#include <ctypes.h>



namespace f_pc_line_tag {
uint fpcLnTg_Move(line_tag *param_1,int param_2);
void fpcLnTg_QueueTo(line_tag *param_1);
uint fpcLnTg_ToQueue(line_tag *param_1,int param_2);
void fpcLnTg_Init(line_tag *param_1,void *param_2);
}
