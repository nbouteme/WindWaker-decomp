#pragma once
#include <ctypes.h>



namespace SComponent {
//Expected size is 0x0001e0
extern undefined4 mtx;

void cLib_memCpy(byte *param_1,byte *param_2,int param_3);
void cLib_memSet(int param_1,uint param_2,uint param_3);
double cLib_addCalc(float *pSrc,float target,float speed,float maxVel,float minVel);
void cLib_addCalc2(float *pDst,float target,float speedRatio,float maxSpeed);
void cLib_addCalc0(float *param_1,float param_2,float param_3);
double cLib_addCalcPos(double param_1,double param_2,double param_3,cXyz *param_4,cXyz *param_5);
double cLib_addCalcPosXZ(double param_1,double param_2,double param_3,cXyz *param_4,cXyz *param_5);
void cLib_addCalcPos2(cXyz *param_1,cXyz *param_2,float param_3,float param_4);
void cLib_addCalcPosXZ2(cXyz *pDst,cXyz *pTarget,float speed,float maxVel);
int cLib_addCalcAngleS(short *pDst,short target,short speed,short maxVel,short param_5);
void cLib_addCalcAngleS2(short *pDst,short target,short speedRatio,short maxSpeed);
int cLib_addCalcAngleL(int *param_1,int param_2,int param_3,int param_4,int param_5);
undefined4 cLib_chaseUC(byte *param_1,byte param_2,ushort param_3);
undefined4 cLib_chaseS(short *param_1,short param_2,short param_3);
undefined4 cLib_chaseF(float *pDst,float target,float speed);
undefined4 cLib_chasePos(double param_1,cXyz *param_2,cXyz *param_3);
undefined4 cLib_chasePosXZ(cXyz *param_1,cXyz *param_2,double param_3);
undefined4 cLib_chaseAngleS(short *param_1,short param_2,short param_3);
short cLib_targetAngleY(cXyz *param_1,cXyz *param_2);
void cLib_targetAngleX(cXyz *param_1,cXyz *param_2);
void cLib_offsetPos(cXyz *param_1,cXyz *param_2,short param_3,cXyz *param_4);
short cLib_distanceAngleS(short param_1,short param_2);
void MtxInit(void);
void MtxTrans(double param_1,double param_2,double param_3,bool param_4);
void MtxRotX(double param_1,char param_2);
void MtxRotY(double param_1,char param_2);
void MtxRotZ(double param_1,char param_2);
void MtxScale(double param_1,double param_2,double param_3,char param_4);
void MtxPosition(cXyz *pSrc,cXyz *pDst);
void MtxPush(void);
void MtxPull(void);
}
