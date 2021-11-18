#pragma once
#include <ctypes.h>



namespace f_op_view {
//[Data] Expected size is 0x000014
extern undefined * g_fopVw_Method;

void fopVw_Draw(int param_1);
void fopVw_Execute(view_class *param_1);
void fopVw_IsDelete(void *param_1);
void fopVw_Delete(view_class *param_1);
void fopVw_Create(view_class *param_1);
}
