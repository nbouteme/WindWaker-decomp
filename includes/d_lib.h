#pragma once
#include <ctypes.h>

#include <Demangler/Quaternion.h>


namespace d_lib {
//[Data] Expected size is 0x000010
extern struct Quaternion ZeroQuat;

}
//[Data] Expected size is 0x000010
extern pointer CSTControl;

//[Data] Expected size is 0x000010
extern pointer STControl;


namespace d_lib {
void dLib_setCirclePath(dLib_circle_path_c *pDst);
double dLib_getWaterY(cXyz *param_1,dBgS_ObjAcch *pAcch);
void dLib_waveRot(cXyz *pPos,float param_2,dLib_wave_c *pWave);
void dLib_debugDrawAxis(double param_1,MTX34 *param_2);
void dLib_debugDrawFan(void);
bool dLib_brkInit(J3DModelData *param_1,mDoExt_brkAnm *param_2,char *param_3,long param_4);
bool dLib_btkInit(J3DModelData *param_1,mDoExt_btkAnm *param_2,char *param_3,long param_4);
void dLib_setAnm(char *pName,mDoExt_McaMorf *pMorf,byte *param_3,byte *param_4,byte *param_5,void *param_6,void *param_7,byte param_8);
void dLib_bcks_setAnm(char *param_1,mDoExt_McaMorf *param_2,char *param_3,char *param_4,char *param_5,int param_6,int param_7,char param_8);
void dLib_scaleAnime(float *param_1,int param_2,int param_3,int *param_4,float param_5,float param_6,float param_7);
void dLib_getPosFromMtx(int param_1,undefined4 *param_2);
uint dLib_pathInfo(dPath **param_1,uint param_2);
void dLib_pathMove(cXyz *pDst,byte *pPointIdx,dPath *pPath,float speed,undefined *pCB,void *pUserData);
void dLib_setNextStageBySclsNum(uint param_1,byte roomIdx);
undefined4 dLib_setFirstMsg(ushort param_1,undefined4 param_2,undefined4 param_3);
void dLib_checkPlayerInCircle(undefined4 *param_1);
undefined4 dLib_checkActorInCircle(double param_1,double param_2,cXyz *param_3,int param_4);
undefined4 dLib_checkActorInFan(double param_1,double param_2,cXyz *param_3,int param_4,short param_5,short param_6);
}

namespace d_lib {
undefined4 dLib_getIplDaysFromSaveTime(undefined4 param_1,uint param_2);
void dLib_get_QuatFromTriangle(undefined4 *param_1,cXyz *param_2,cXyz *param_3,cXyz *param_4);
void dLib_calc_QuatFromTriangle(double param_1,Quaternion *param_2);
}
