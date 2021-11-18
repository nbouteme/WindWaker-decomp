#pragma once
#include <ctypes.h>

#include <profile_leaf_method_class.h>


namespace f_pc_leaf {
//[Data] Expected size is 0x000014
extern struct profile_leaf_method_class g_fpcLf_Method;

//[BSS] Expected size is 0x000004
extern undefined4 g_fpcLf_type;
int fpcLf_GetPriority(leafdraw_class *param_1);
void fpcLf_DrawMethod(void *param_1,void *param_2);
undefined4 fpcLf_Draw(leafdraw_class *param_1);
void fpcLf_Execute(leafdraw_class *param_1);
void fpcLf_IsDelete(leafdraw_class *param_1);
void fpcLf_Delete(leafdraw_class *param_1);
void fpcLf_Create(leafdraw_class *param_1);
}
