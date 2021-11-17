#pragma once
#include <ctypes.h>



namespace gx {
void GXProject(double param_1,double param_2,double param_3,float *param_4,float *param_5,float *param_6,float *param_7,float *param_8,float *param_9);
void GXSetProjection(MTX44 *param_1,GXProjectionType param_2);
void GXSetProjectionv(float *param_1);
void GXGetProjectionv(float *param_1);
void GXLoadPosMtxImm(MTX34 *param_1,int param_2);
undefined8 GXLoadNrmMtxImm(int param_1,int param_2);
void GXSetCurrentMtx(uint param_1);
undefined8 GXLoadTexMtxImm(int param_1,GXTexMtx param_2,int param_3);
void GXSetViewportJitter(double param_1,double param_2,double param_3,double param_4,double param_5,double param_6,int param_7);
void GXSetViewport(void);
void GXGetViewportv(undefined4 *param_1);
void GXSetScissor(int param_1,int param_2,int param_3,int param_4);
void GXGetScissor(int *param_1,int *param_2,int *param_3,int *param_4);
void GXSetScissorBoxOffset(int param_1,int param_2);
void GXSetClipMode(bool param_1);
void __GXSetMatrixIndex(int param_1);
}
