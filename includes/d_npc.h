#pragma once
#include <ctypes.h>

#include <Demangler/dCcD_SrcCyl.h>


namespace d_npc {
//[Data] Expected size is 0x00001c
extern undefined * action_table$4553;

//[Data] Expected size is 0x0000a8
extern undefined4 cut_tbl$4554;

//[Data] Expected size is 0x000044
extern struct dCcD_SrcCyl dNpc_cyl_src;

//[BSS] Expected size is 0x000001
extern undefined1 init$4569;
}

namespace dNpc_PathRun_c {
void getPoint(cXyz *pDstPos,dNpc_PathRun_c *this,uchar pointIndex);
}

namespace d_npc {
undefined4 dNpc_setAnmIDRes(double param_1,double param_2,mDoExt_McaMorf *param_3,int param_4,ushort param_5,int param_6,char *param_7);
undefined4 dNpc_setAnmFNDirect(double param_1,double param_2,mDoExt_McaMorf *param_3,int param_4,char *param_5,char *param_6,char *param_7);
undefined4 dNpc_setAnm(double param_1,double param_2,mDoExt_McaMorf *param_3,int param_4,long param_5,int param_6,char *param_7);
void dNpc_setShadowModel(int param_1,int param_2,int param_3);
void dNpc_playerEyePos(float param_1,cXyz *outPos);
void dNpc_calc_DisXZ_AngY(cXyz *param_1,cXyz *param_2,float *param_3,short *param_4);
undefined4 dNpc_chkArasoi(void);
uint dNpc_chkLetterPassed(void);
}

namespace d_npc {
undefined4 dNpc_setAnm_2(double param_1,double param_2,mDoExt_McaMorf *param_3,int param_4,long param_5,int param_6,char *param_7);
}

namespace d_npc {
undefined4 dNpc_chkAttn(fopAc_ac_c *this,cXyz *destPos,double param_3,double param_4,double param_5,bool param_6);
}

namespace dNpc_EventCut_c {
dNpc_EventCut_c * findActorCallBack(fopAc_ac_c *pActor,dNpc_EventCut_c *pData);
}
