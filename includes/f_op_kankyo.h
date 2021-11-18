#pragma once
#include <ctypes.h>



namespace f_op_kankyo {
//[Data] Expected size is 0x000014
extern undefined * g_fopKy_Method;

//[BSS] Expected size is 0x000004
extern int fopKy_KANKYO_TYPE;
undefined4 fopKy_Draw(int param_1);
profile_method_class * fopKy_Execute(kankyo_class *param_1);
int fopKy_IsDelete(void *param_1);
int fopKy_Delete(void *param_1);
int fopKy_Create(kankyo_class *param_1);
}
