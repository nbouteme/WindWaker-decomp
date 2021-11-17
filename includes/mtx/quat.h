#pragma once
#include <ctypes.h>



namespace mtx {
undefined8 PSQUATMultiply(int param_1,int param_2,int param_3);
undefined8 PSQUATNormalize(int param_1,int param_2);
undefined8 PSQUATInverse(int param_1,int param_2);
void C_QUATRotAxisRad(double param_1,float *param_2,undefined4 param_3);
void C_QUATSlerp(double param_1,Quaternion *param_2,Quaternion *param_3,Quaternion *param_4);
}
