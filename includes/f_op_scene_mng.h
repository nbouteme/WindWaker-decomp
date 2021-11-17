#pragma once
#include <ctypes.h>



namespace f_op_scene_mng {
scene_class * fopScnM_SearchByID(int param_1);
bool fopScnM_ChangeReq(scene_class *param_1,short procName,short fadeTime,ushort param_4);
uint fopScnM_DeleteReq(scene_class *param_1);
uint fopScnM_CreateReq(short param_1,short param_2,ushort param_3,void *param_4);
undefined4 fopScnM_ReRequest(undefined4 param_1,undefined4 param_2);
void fopScnM_Management(void);
void fopScnM_Init(void);
}
