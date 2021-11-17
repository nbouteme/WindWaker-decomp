#pragma once
#include <ctypes.h>



namespace J2DGraph {
void J2DDrawLine(double param_1,double param_2,double param_3,double param_4,undefined4 *param_5,uchar param_6);
void J2DFillBox(double param_1,double param_2,double param_3,double param_4,undefined4 *param_5);
void J2DFillBox(TBox2<float> *param_1,undefined4 *param_2);
void J2DDrawFrame(double param_1,double param_2,double param_3,double param_4,undefined4 *param_5,undefined4 param_6);
void J2DDrawFrame(TBox2<float> *param_1,undefined4 *param_2,uchar param_3);
}
