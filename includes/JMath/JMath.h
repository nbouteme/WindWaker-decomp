#pragma once
#include <ctypes.h>



namespace JKernel {

namespace JMath {
//Expected size is 0x000002
extern undefined2 jmaSinTableSize;

//Expected size is 0x000004
extern undefined4 jmaSinShift;

//Expected size is 0x000004
extern float * jmaSinTable;

//Expected size is 0x000004
extern float * jmaCosTable;

undefined4 JMANewSinTable(uint param_1);
void JMAEulerToQuat(int param_1,int param_2,int param_3,Quaternion *pDst);
void JMAQuatLerp(double param_1,float *param_2,float *param_3,float *param_4);
double JMAHermiteInterpolation(double param_1,double param_2,double param_3,double param_4,double param_5,double param_6,double param_7);
}
}
