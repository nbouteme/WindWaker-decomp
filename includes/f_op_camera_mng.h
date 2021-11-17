#pragma once
#include <ctypes.h>



namespace f_op_camera_mng {
//Expected size is 0x000010
extern undefined l_fopCamM_id;

int fopCamM_GetParam(camera_class *param_1);
undefined4 fopCamM_Create(int param_1,short param_2,void *param_3);
void fopCamM_Management(void);
void fopCamM_Init(void);
}
