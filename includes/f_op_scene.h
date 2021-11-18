#pragma once
#include <ctypes.h>

#include <profile_leaf_method_class.h>


namespace f_op_scene {
//[Data] Expected size is 0x000014
extern struct profile_leaf_method_class g_fopScn_Method;

void fopScn_Draw(int param_1);
void fopScn_Execute(void *param_1);
void fopScn_IsDelete(void *param_1);
int fopScn_Delete(void *param_1);
void fopScn_Create(scene_class *param_1);
}
