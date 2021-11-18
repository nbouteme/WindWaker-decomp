#pragma once
#include <ctypes.h>

#include <profile_leaf_method_class.h>


namespace f_op_camera {
//[Data] Expected size is 0x000014
extern struct profile_leaf_method_class g_fopCam_Method;

undefined4 fopCam_Draw(int param_1);
profile_method_class * fopCam_Execute(camera_class *param_1);
int fopCam_IsDelete(void *param_1);
int fopCam_Delete(void *param_1);
int fopCam_Create(camera_class *param_1);
}
