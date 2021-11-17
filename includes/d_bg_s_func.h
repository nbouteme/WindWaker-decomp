#pragma once
#include <ctypes.h>



namespace d_bg_s_func {
undefined8 dBgS_ObjGndChk_Func(cXyz *param_1);
undefined8 dBgS_ObjGndChk_Wtr_Func(float *param_1);
undefined4 dBgS_SplGrpChk_In_ObjGnd(double param_1,float *param_2,dBgS_SplGrpChk *param_3);
double dBgS_GetWaterHeight(float *param_1);
undefined4 dBgS_GetGndMtrlSndId_Func(double param_1,float *param_2);
}
