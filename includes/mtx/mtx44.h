#pragma once
#include <ctypes.h>



namespace mtx {
void C_MTXPerspective(double param_1,double param_2,double param_3,double param_4,float *param_5);
void C_MTXOrtho(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6,MTX44 *param_7);
}
