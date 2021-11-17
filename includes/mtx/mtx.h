#pragma once
#include <ctypes.h>



namespace mtx {
void PSMTXIdentity(MTX34 *param_1);
void PSMTXCopy(MTX34 *param_1,MTX34 *param_2);
void PSMTXConcat(MTX34 *param_1,MTX34 *param_2,MTX34 *param_3);
undefined4 PSMTXInverse(int param_1,int param_2);
void PSMTXRotRad(MTX34 *param_1,char param_2,float param_3);
double PSMTXRotTrig(double param_1,double param_2,int param_3,uint param_4);
void C_MTXRotAxisRad(double param_1,float *param_2,undefined4 param_3);
double __PSMTXRotAxisRadInternal(double param_1,double param_2,int param_3,int param_4);
void PSMTXRotAxisRad(double param_1,undefined4 param_2,undefined4 param_3);
void PSMTXTrans(double param_1,double param_2,double param_3,MTX34 *param_4);
double PSMTXTransApply(double param_1,double param_2,double param_3,int param_4,int param_5);
void PSMTXScale(double param_1,double param_2,double param_3,MTX34 *param_4);
double PSMTXQuat(int param_1,int param_2);
void C_MTXLookAt(float *param_1,float *param_2,TVec3<float> *param_3,float *param_4);
void C_MTXLightPerspective(double param_1,double param_2,double param_3,double param_4,double param_5,double param_6,float *param_7);
void C_MTXLightOrtho(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6,float param_7,float param_8,MTX34 *param_9);
}
