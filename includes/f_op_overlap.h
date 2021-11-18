#pragma once
#include <ctypes.h>

#include <profile_leaf_method_class.h>


namespace f_op_overlap {
//[Data] Expected size is 0x000014
extern struct profile_leaf_method_class g_fopOvlp_Method;

void fopOvlp_Draw(int param_1);
void fopOvlp_Execute(void *param_1);
void fopOvlp_IsDelete(void *param_1);
void fopOvlp_Delete(void *param_1);
void fopOvlp_Create(void *param_1);
}
