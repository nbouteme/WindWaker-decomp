#pragma once
#include <ctypes.h>



namespace f_op_scene {
void fopScn_Draw(int param_1);
void fopScn_Execute(void *param_1);
void fopScn_IsDelete(void *param_1);
int fopScn_Delete(void *param_1);
void fopScn_Create(scene_class *param_1);
}
