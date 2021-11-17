#pragma once
#include <ctypes.h>



namespace SComponent {
void cM3d_InDivPos1(double param_1,cXyz *param_2,cXyz *param_3,cXyz *param_4);
void cM3d_InDivPos2(undefined8 param_1,cXyz *param_2,cXyz *param_3,undefined4 param_4);
int cM3d_Len2dSqPntAndSegLine(float param_1,float param_2,float x2,float y2,float x1,float y1,float *pDstX,float *pDstY,float *pDstLen);
undefined4 cM3d_Len3dSqPntAndSegLine(cXyz *param_1,cXyz *param_2,cXyz *param_3,float *param_4);
double cM3d_SignedLenPlaAndPos(cM3dGPla *param_1,cXyz *param_2);
void cM3d_CalcPla(TVec3<float> *pV0,TVec3<float> *pV1,TVec3<float> *pV2,TVec3<float> *pNorm,float *pDist);
undefined4 cM3d_Cross_AabAab(float *param_1,float *param_2);
uint cM3d_Cross_AabCyl(float *param_1,float *param_2);
uint cM3d_Cross_AabSph(float *param_1,float *param_2);
undefined4 cM3d_Check_LinLin(cXyz *param_1,cXyz *param_2,float *param_3,float *param_4);
undefined4 cM3d_Cross_LinPla(int param_1,int param_2,undefined4 *param_3,char param_4,char param_5);
int cM3d_Cross_MinMaxBoxLine(cXyz *param_1,cXyz *param_2,cXyz *param_3,cXyz *param_4);
undefined4 cM3d_InclusionCheckPosIn3PosBox3d(double param_1,float *param_2,float *param_3,float *param_4,float *param_5);
undefined4 cM3d_CrossX_Tri(double param_1,float *param_2,int param_3);
undefined4 cM3d_CrossX_Tri(float *param_1,int param_2);
bool cM3d_CrossX_Tri(float *param_1,int param_2,float *param_3);
undefined4 cM3d_CrossY_Tri(int param_1,float *param_2);
undefined4 cM3d_CrossY_Tri(float *param_1,float *param_2,float *param_3,int param_4,float *param_5);
undefined4 cM3d_CrossY_Tri_Front(cXyz *param_1,cXyz *param_2,cXyz *param_3,cXyz *pPos);
bool cM3d_CrossY_Tri(float *param_1,float *param_2,float *param_3);
undefined4 cM3d_CrossY_Tri(double param_1,int param_2,float *param_3);
undefined4 cM3d_CrossY_Tri(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4);
undefined4 cM3d_CrossZ_Tri(double param_1,int param_2,float *param_3);
undefined4 cM3d_CrossZ_Tri(int param_1,float *param_2);
bool cM3d_CrossZ_Tri(float *param_1,float *param_2,float *param_3);
undefined4 cM3d_Cross_LinTri(undefined4 param_1,float *param_2,undefined4 param_3);
undefined4 cM3d_Cross_LinTri_Easy(float *param_1,undefined4 param_2);
uint cM3d_Cross_SphPnt(cXyz *param_1,cXyz *param_2);
uint cM3d_Cross_LinSph(cXyz *param_1,cXyz *param_2,cXyz *param_3);
undefined4 cM3d_Cross_LinSph_CrossPos(cXyz *param_1,cXyz *param_2,cXyz *param_3,cXyz *param_4);
undefined4 cM3d_Cross_CylSph(cXyz *param_1,cXyz *param_2,cXyz *param_3,float *param_4);
undefined4 cM3d_Cross_SphSph(cXyz *param_1,cXyz *param_2,float *param_3,float *param_4);
undefined4 cM3d_Cross_SphSph(cXyz *param_1,cXyz *param_2,cXyz *param_3);
void cM3d_CalcSphVsTriCrossPoint(cXyz *param_1,int param_2,float *param_3);
undefined4 cM3d_Cross_SphTri(cXyz *param_1,cM3dGPla *param_2,int param_3);
int cM3d_Cross_CylCyl(cM3dGCyl *param_1,cM3dGCyl *param_2,float *param_3);
undefined4 cM3d_Cross_CylCyl(float *param_1,float *param_2,float *param_3);
undefined4 cM3d_Cross_CylTri(float *param_1,int param_2,float *param_3);
int cM3d_Cross_CylLin(cXyz *param_1,cXyz *param_2,cXyz *param_3,float *param_4);
void cM3d_Cross_CylPntPnt(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,undefined4 param_5);
undefined4 cM3d_Cross_CylPnt(float *param_1,float *param_2);
undefined4 cM3d_Cross_CpsCps(cXyz *param_1,cXyz *param_2,cXyz *param_3);
uint cM3d_Cross_CpsCyl(cXyz *param_1,float *param_2,cXyz *param_3);
void cM3d_Cross_CpsSph_CrossPos(cXyz *param_1,cXyz *param_2,cXyz *param_3,cXyz *param_4);
undefined4 cM3d_Cross_CpsSph(cM3dGCps *param_1,cM3dGSph *param_2,cXyz *param_3);
undefined4 cM3d_Cross_TriTri(int param_1,int param_2,undefined4 param_3);
undefined4 cM3d_Cross_CpsTri(cXyz *param_1,int param_2,cXyz *param_3);
undefined4 cM3d_NearPos_Cps(cXyz *param_1,cXyz *param_2,cXyz *param_3);
void cM3d_CalcVecAngle(cXyz *param_1,short *param_2,undefined2 *param_3);
void cM3d_CalcVecZAngle(float *param_1,short *param_2);
undefined4 cM3d_UpMtx_Base(TVec3<float> *param_1,cXyz *param_2,MTX34 *param_3);
void cM3d_PlaneCrossLineProcWork(double param_1,double param_2,double param_3,double param_4,double param_5,double param_6,double param_7,float *param_8,float *param_9);
undefined4 cM3d_2PlaneCrossLine(cM3dGPla *param_1,cM3dGPla *param_2,cM3dGLin *param_3);
undefined4 cM3d_3PlaneCrossPos(cM3dGPla *param_1,cM3dGPla *param_2,cM3dGPla *param_3,cXyz *param_4);
double cM3d_lineVsPosSuisenCross(cXyz *param_1,cXyz *param_2,cXyz *param_3);
double cM3d_lineVsPosSuisenCross(cXyz *param_1,cXyz *param_2,cXyz *param_3,cXyz *param_4);
bool cM3d_2PlaneLinePosNearPos(cM3dGPla *param_1,cM3dGPla *param_2,undefined4 param_3,undefined4 param_4);
void cM3d_CrawVec(cXyz *param_1,cXyz *param_2,cXyz *param_3);
}
