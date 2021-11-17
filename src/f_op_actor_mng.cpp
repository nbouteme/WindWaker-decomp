#include <f_op_actor_mng.h>
#include <f_op_scene_mng.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <f_pc_base.h>
#include <f_pc_priority.h>
#include <f_pc_manager.h>
#include <f_pc_searcher.h>
#include <f_op_actor_iter.h>
#include <SComponent/c_malloc.h>
#include <SComponent/c_lib.h>
#include <f_op_actor_mng.h>
#include <f_pc_layer.h>
#include <f_pc_stdcreate_req.h>
#include <d_stage.h>
#include <m_Do_ext.h>
#include <JKernel/JKRHeap.h>
#include <MSL_C.PPCEABI.bare.H/arith.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <mtx/mtx.h>
#include <J3DU/J3DUClipper.h>
#include <d_event.h>
#include <d_event_manager.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <SComponent/c_sxyz.h>
#include <SComponent/c_math.h>
#include <d_item.h>
#include <d_save.h>
#include <SComponent/c_data_tbl.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <d_com_static.h>
#include <f_op_actor.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <SComponent/c_bg_s.h>
#include <SComponent/c_bg_s_chk.h>
#include <SComponent/c_bg_s_lin_chk.h>
#include <d_bg_s_lin_chk.h>
#include <d_kankyo.h>
#include <d_bg_s_wtr_chk.h>
#include <d_bg_s.h>
#include <d_a_sea.h>
#include <d_com_inf_game.h>
#include <dBgS_SplGrpChk.h>
#include <fopAc_cullSizeBox.h>
#include <daPy_py_c.h>
#include <fopAc_cullSizeSphere.h>
#include <l_HIO.h>
#include <dBgS_WtrChk.h>


namespace f_op_actor_mng {
struct fopAc_cullSizeBox l_cullSizeBox[14];
struct fopAc_cullSizeSphere l_cullSizeSphere[8];
undefined min$4862;
undefined max$4898;
undefined4 fairy_offset_tbl$5080;
struct dBgS_WtrChk water_check$6113;
}

namespace fopAcM {
undefined1 HeapAdjustEntry;
undefined1 HeapAdjustVerbose;
byte HeapAdjustQuiet;
}

namespace f_op_actor_mng {
undefined l_hio;
undefined1 init$5082;
undefined1 init$6115;

/* __stdcall fopAcM_setStageLayer(void *) */

void fopAcM_setStageLayer(fopAc_ac_c *param_1)

{
  scene_class *psVar1;
  ulong uVar2;
  bool bVar3;
  uint uVar4;
  
  psVar1 = f_op_scene_mng::fopScnM_SearchByID(dStage_roomControl_c::mProcID);
  if (psVar1 == (scene_class *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"f_op_actor_mng.cpp",0xee,"stageProc != 0");
    m_Do_printf::OSPanic("f_op_actor_mng.cpp",0xee,"Halt");
  }
  bVar3 = f_pc_base::fpcBs_Is_JustOfType(f_pc_node::g_fpcNd_type,(psVar1->parent).parent.mSubType);
  if (bVar3 == false) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = (psVar1->parent).mLayer.mLayerID;
  }
  f_pc_priority::fpcPi_Change(&(param_1->parent).parent.mPi,uVar4,0xfffd,0xfffd);
  return;
}


/* __stdcall fopAcM_setRoomLayer(void *,
                                 int) */

void fopAcM_setRoomLayer(fopAc_ac_c *param_1,int param_2)

{
  room_of_scene_class *pRoomProc;
  ulong uVar1;
  bool bVar2;
  uint uVar3;
  
  if (-1 < param_2) {
    pRoomProc = (room_of_scene_class *)
                f_op_scene_mng::fopScnM_SearchByID
                          (dStage_roomControl_c::mStatus[param_2].mRoomBsPcId);
    if (pRoomProc == (room_of_scene_class *)0x0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"f_op_actor_mng.cpp",0x105,"roomProc != 0");
      m_Do_printf::OSPanic("f_op_actor_mng.cpp",0x105,"Halt");
    }
    bVar2 = f_pc_base::fpcBs_Is_JustOfType
                      (f_pc_node::g_fpcNd_type,(pRoomProc->parent).parent.parent.mSubType);
    if (bVar2 == false) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = (pRoomProc->parent).parent.mLayer.mLayerID;
    }
    f_pc_priority::fpcPi_Change(&(param_1->parent).parent.mPi,uVar3,0xfffd,0xfffd);
  }
  return;
}


/* __stdcall fopAcM_SearchByID(unsigned int,
                               fopAc_ac_c * *) */

undefined4 fopAcM_SearchByID(undefined4 param_1,fopAc_ac_c **param_2)

{
  int iVar1;
  fopAc_ac_c *pfVar2;
  undefined4 local_18 [5];
  
  local_18[0] = param_1;
  iVar1 = f_pc_manager::fpcM_IsCreating();
  if (iVar1 == 0) {
    pfVar2 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,local_18);
    *param_2 = pfVar2;
    if (*param_2 == (fopAc_ac_c *)0x0) {
      return 0;
    }
  }
  else {
    *param_2 = (fopAc_ac_c *)0x0;
  }
  return 1;
}


/* __stdcall fopAcM_SearchByName(short,
                                 fopAc_ac_c * *) */

undefined4 fopAcM_SearchByName(short param_1,fopAc_ac_c **param_2)

{
  fopAc_ac_c *pfVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  short local_18 [10];
  
  local_18[0] = param_1;
  pfVar1 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,local_18);
  *param_2 = pfVar1;
  pfVar1 = *param_2;
  if (pfVar1 == (fopAc_ac_c *)0x0) {
    uVar2 = 0;
  }
  else {
    if (pfVar1 == (fopAc_ac_c *)0x0) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = (pfVar1->parent).parent.mBsPcId;
    }
    iVar4 = f_pc_manager::fpcM_IsCreating(uVar3);
    if (iVar4 != 0) {
      *param_2 = (fopAc_ac_c *)0x0;
    }
    uVar2 = 1;
  }
  return uVar2;
}


/* __stdcall fopAcM_CreateAppend(void) */

fopAcM_prm_class * fopAcM_CreateAppend(void)

{
  fopAcM_prm_class *pPrm;
  
  pPrm = (fopAcM_prm_class *)cMl::memalignB(-4,0x24);
  if (pPrm != (fopAcM_prm_class *)0x0) {
    SComponent::cLib_memSet(pPrm,0,0x24);
    pPrm->mEnemyNo = -1;
    pPrm->mRoomNo = 0xff;
    pPrm->mScaleX = 10;
    pPrm->mScaleY = 10;
    pPrm->mScaleZ = 10;
    pPrm->mParentPcId = 0xffffffff;
    pPrm->mSubtype = 0xff;
  }
  return pPrm;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall createAppend(unsigned long,
                          cXyz *,
                          int,
                          csXyz *,
                          cXyz *,
                          signed char,
                          unsigned int) */

undefined4 *
createAppend
          (ulong parameters,cXyz *pPos,int roomNo,csXyz *angle,cXyz *scale,char subtype,
          uint parentUniqueID)

{
  float fVar1;
  fopAcM_prm_class *pAc;
  
  pAc = fopAcM_CreateAppend();
  if (pAc == (fopAcM_prm_class *)0x0) {
    pAc = (fopAcM_prm_class *)0x0;
  }
  else {
    if (pPos == (cXyz *)0x0) {
      (pAc->mPos).x = ::cXyz::Zero.x;
      (pAc->mPos).y = ::cXyz::Zero.y;
      (pAc->mPos).z = ::cXyz::Zero.z;
    }
    else {
      (pAc->mPos).x = pPos->x;
      (pAc->mPos).y = pPos->y;
      (pAc->mPos).z = pPos->z;
    }
    pAc->mRoomNo = (byte)roomNo;
    if (angle == (csXyz *)0x0) {
      (pAc->mRot).x = ::csXyz::Zero.x;
      (pAc->mRot).y = ::csXyz::Zero.y;
      (pAc->mRot).z = ::csXyz::Zero.z;
    }
    else {
      (pAc->mRot).x = angle->x;
      (pAc->mRot).y = angle->y;
      (pAc->mRot).z = angle->z;
    }
    fVar1 = 10_0;
    if (scale == (cXyz *)0x0) {
      pAc->mScaleX = 10;
      pAc->mScaleY = 10;
      pAc->mScaleZ = 10;
    }
    else {
      pAc->mScaleX = (byte)(int)(10_0 * scale->x);
      pAc->mScaleY = (byte)(int)(fVar1 * scale->y);
      pAc->mScaleZ = (byte)(int)(fVar1 * scale->z);
    }
    pAc->mParameters = parameters;
    pAc->mParentPcId = parentUniqueID;
    pAc->mSubtype = subtype;
  }
  return &pAc->mParameters;
}


/* __stdcall fopAcM_Log(fopAc_ac_c *,
                        char *) */

void fopAcM_Log(void)

{
  return;
}


/* __stdcall fopAcM_delete(fopAc_ac_c *) */

void fopAcM_delete(base_process_class *param_1)

{
  fopAcM_Log(param_1,"アクターの削除");
  f_pc_manager::fpcM_Delete(param_1);
  return;
}


/* __stdcall fopAcM_delete(unsigned int) */

void fopAcM_delete(undefined4 param_1)

{
  fopAc_ac_c *pfVar1;
  undefined4 local_18 [5];
  
  local_18[0] = param_1;
  pfVar1 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,local_18);
  if (pfVar1 != (fopAc_ac_c *)0x0) {
    fopAcM_Log(pfVar1,"アクターの削除");
    f_pc_manager::fpcM_Delete((base_process_class *)pfVar1);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fopAcM_create(short,
                           unsigned long,
                           cXyz *,
                           int,
                           csXyz *,
                           cXyz *,
                           signed char,
                           int *(void *)) */

undefined4
fopAcM_create
          (short procName,ulong parameters,cXyz *pPos,int roomNo,csXyz *pAngle,cXyz *pScale,
          byte subtype,undefined *param_8)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  layer_class *plVar3;
  
  puVar1 = createAppend(parameters,pPos,roomNo,pAngle,pScale,subtype,0xffffffff);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    plVar3 = f_pc_layer::fpcLy_CurrentLayer();
    uVar2 = f_pc_stdcreate_req::fpcSCtRq_Request(plVar3,procName,param_8,(void *)0x0,puVar1);
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall fopAcM_create(char *,
                           unsigned long,
                           cXyz *,
                           int,
                           csXyz *,
                           cXyz *,
                           int *(void *)) */

undefined4
fopAcM_create
          (char *param_1,ulong param_2,cXyz *param_3,int param_4,csXyz *param_5,cXyz *param_6,
          undefined *param_7)

{
  dStage__ObjectNameTable *pdVar1;
  undefined4 uVar2;
  
  pdVar1 = d_stage::dStage_searchName(param_1);
  if (pdVar1 == (dStage__ObjectNameTable *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = fopAcM_create(pdVar1->mProcName,param_2,param_3,param_4,param_5,param_6,pdVar1->mSubtype
                          ,param_7);
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fopAcM_fastCreate(short,
                               unsigned long,
                               cXyz *,
                               int,
                               csXyz *,
                               cXyz *,
                               signed char,
                               int *(void *),
                               void *) */

fopAc_ac_c *
fopAcM_fastCreate
          (short actorID,ulong parameters,cXyz *pPos,int roomNo,csXyz *pAngle,cXyz *pScale,
          byte subtype,undefined *pCallBack,void *pCallBackUserData)

{
  undefined2 in_register_0000000c;
  undefined4 *puVar1;
  fopAc_ac_c *pfVar2;
  
  puVar1 = createAppend(parameters,pPos,roomNo,pAngle,pScale,subtype,0xffffffff);
  if (puVar1 == (undefined4 *)0x0) {
    pfVar2 = (fopAc_ac_c *)0x0;
  }
  else {
    pfVar2 = (fopAc_ac_c *)
             f_pc_manager::fpcM_FastCreate
                       (CONCAT22(in_register_0000000c,actorID),pCallBack,pCallBackUserData);
  }
  return pfVar2;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall fopAcM_fastCreate(char *,
                               unsigned long,
                               cXyz *,
                               int,
                               csXyz *,
                               cXyz *,
                               int *(void *),
                               void *) */

fopAc_ac_c *
fopAcM_fastCreate
          (char *param_1,ulong param_2,cXyz *param_3,int param_4,csXyz *param_5,cXyz *param_6,
          undefined *param_7,void *param_8)

{
  dStage__ObjectNameTable *pdVar1;
  fopAc_ac_c *pfVar2;
  
  pdVar1 = d_stage::dStage_searchName(param_1);
  if (pdVar1 == (dStage__ObjectNameTable *)0x0) {
    pfVar2 = (fopAc_ac_c *)0x0;
  }
  else {
    pfVar2 = fopAcM_fastCreate(pdVar1->mProcName,param_2,param_3,param_4,param_5,param_6,
                               pdVar1->mSubtype,param_7,param_8);
  }
  return pfVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fopAcM_createChild(short,
                                unsigned int,
                                unsigned long,
                                cXyz *,
                                int,
                                csXyz *,
                                cXyz *,
                                signed char,
                                int *(void *)) */

undefined4
fopAcM_createChild
          (short param_1,uint parentUniqueID,ulong param_3,cXyz *param_4,int param_5,csXyz *param_6,
          cXyz *param_7,char param_8,undefined *param_9)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  layer_class *plVar3;
  
  puVar1 = createAppend(param_3,param_4,param_5,param_6,param_7,param_8,parentUniqueID);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    plVar3 = f_pc_layer::fpcLy_CurrentLayer();
    uVar2 = f_pc_stdcreate_req::fpcSCtRq_Request(plVar3,param_1,param_9,(void *)0x0,puVar1);
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall fopAcM_createChild(char *,
                                unsigned int,
                                unsigned long,
                                cXyz *,
                                int,
                                csXyz *,
                                cXyz *,
                                int *(void *)) */

int fopAcM_createChild
              (char *param_1,uint param_2,ulong param_3,cXyz *param_4,int param_5,csXyz *param_6,
              cXyz *param_7,undefined *param_8)

{
  dStage__ObjectNameTable *pdVar1;
  int iVar2;
  
  pdVar1 = d_stage::dStage_searchName(param_1);
  if (pdVar1 == (dStage__ObjectNameTable *)0x0) {
    iVar2 = -1;
  }
  else {
    iVar2 = fopAcM_createChild(pdVar1->mProcName,param_2,param_3,param_4,param_5,param_6,param_7,
                               pdVar1->mSubtype,param_8);
  }
  return iVar2;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __stdcall fopAcM_createChildFromOffset(short,
                                          unsigned int,
                                          unsigned long,
                                          cXyz *,
                                          int,
                                          csXyz *,
                                          cXyz *,
                                          signed char,
                                          int *(void *)) */

undefined4
fopAcM_createChildFromOffset
          (short param_1,uint param_2,ulong param_3,float *param_4,int param_5,short *param_6,
          cXyz *param_7,char param_8,undefined *param_9)

{
  short sVar1;
  int iVar2;
  fopAc_ac_c *pfVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  layer_class *plVar6;
  uint local_58;
  undefined4 local_54;
  short local_50;
  short local_4c;
  short sStack74;
  short local_48;
  cXyz local_44;
  float local_38;
  float local_34;
  float local_30;
  
  local_58 = param_2;
  pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_58);
  sVar1 = (pfVar3->mCurrent).mRot.y;
  if (param_4 == (float *)0x0) {
    local_38 = ::cXyz::Zero.x;
    local_34 = ::cXyz::Zero.y;
    local_30 = ::cXyz::Zero.z;
  }
  else {
    local_38 = *param_4;
    local_34 = param_4[1];
    local_30 = param_4[2];
  }
  if (param_6 == (short *)0x0) {
    sStack74 = ::csXyz::Zero.y;
    local_4c = ::csXyz::Zero.x;
    local_48 = ::csXyz::Zero.z;
  }
  else {
    local_4c = *param_6;
    sStack74 = param_6[1];
    local_48 = param_6[2];
  }
  local_50 = local_48;
  local_54 = CONCAT22(local_4c,sStack74 + sVar1);
  iVar2 = (int)((int)sVar1 & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  local_44.x = (pfVar3->mCurrent).mPos.x +
               local_30 * JKernel::JMath::jmaSinTable[iVar2] +
               local_38 * JKernel::JMath::jmaCosTable[iVar2];
  local_44.y = (pfVar3->mCurrent).mPos.y + local_34;
  local_44.z = (pfVar3->mCurrent).mPos.z +
               (local_30 * JKernel::JMath::jmaCosTable[iVar2] -
               local_38 * JKernel::JMath::jmaSinTable[iVar2]);
  puVar4 = createAppend(param_3,&local_44,param_5,(csXyz *)&local_54,param_7,param_8,param_2);
  if (puVar4 == (undefined4 *)0x0) {
    uVar5 = 0xffffffff;
  }
  else {
    plVar6 = f_pc_layer::fpcLy_CurrentLayer();
    uVar5 = f_pc_stdcreate_req::fpcSCtRq_Request(plVar6,param_1,param_9,(void *)0x0,puVar4);
  }
  return uVar5;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __stdcall fopAcM_createChildFromOffset(char *,
                                          unsigned int,
                                          unsigned long,
                                          cXyz *,
                                          int,
                                          csXyz *,
                                          cXyz *,
                                          int *(void *)) */

void fopAcM_createChildFromOffset
               (char *param_1,undefined4 param_2,undefined4 param_3,float *param_4,
               undefined4 param_5,short *param_6,undefined4 param_7,undefined4 param_8)

{
  short sVar1;
  int iVar2;
  fopAc_ac_c *pfVar3;
  undefined4 local_58;
  undefined4 local_54;
  short local_50;
  short local_4c;
  short sStack74;
  short local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  
  local_58 = param_2;
  pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_58);
  sVar1 = (pfVar3->mCurrent).mRot.y;
  if (param_4 == (float *)0x0) {
    local_44 = ::cXyz::Zero.x;
    local_40 = ::cXyz::Zero.y;
    local_3c = ::cXyz::Zero.z;
  }
  else {
    local_44 = *param_4;
    local_40 = param_4[1];
    local_3c = param_4[2];
  }
  if (param_6 == (short *)0x0) {
    sStack74 = ::csXyz::Zero.y;
    local_4c = ::csXyz::Zero.x;
    local_48 = ::csXyz::Zero.z;
  }
  else {
    local_4c = *param_6;
    sStack74 = param_6[1];
    local_48 = param_6[2];
  }
  local_50 = local_48;
  local_54 = CONCAT22(local_4c,sStack74 + sVar1);
  iVar2 = (int)((int)sVar1 & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  local_38 = (pfVar3->mCurrent).mPos.x +
             local_3c * JKernel::JMath::jmaSinTable[iVar2] +
             local_44 * JKernel::JMath::jmaCosTable[iVar2];
  local_34 = (pfVar3->mCurrent).mPos.y + local_40;
  local_30 = (pfVar3->mCurrent).mPos.z +
             (local_3c * JKernel::JMath::jmaCosTable[iVar2] -
             local_44 * JKernel::JMath::jmaSinTable[iVar2]);
  fopAcM_createChild(param_1,param_2,param_3,&local_38,param_5,&local_54,param_7,param_8);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fopAcM_createHeap(fopAc_ac_c *,
                               unsigned long,
                               unsigned long) */

bool fopAcM_createHeap
               (int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
               char *param_6)

{
  bool bVar1;
  ulong uVar2;
  JKRSolidHeap *pJVar3;
  JUTAssertion *this;
  
  if (param_1 == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"f_op_actor_mng.cpp",0x33b,"i_this");
    m_Do_printf::OSPanic("f_op_actor_mng.cpp",0x33b,"Halt");
  }
  if (*(int *)(param_1 + 0xf0) != 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"f_op_actor_mng.cpp",0x33c,"i_this->heap == 0");
    m_Do_printf::OSPanic("f_op_actor_mng.cpp",0x33c,"Halt");
  }
  fopAcM_Log(param_1,"アクターのヒープの生成");
  if (param_3 == 0) {
    param_3 = 0x20;
  }
  pJVar3 = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent(param_2,param_3);
  *(JKRSolidHeap **)(param_1 + 0xf0) = pJVar3;
  bVar1 = *(int *)(param_1 + 0xf0) != 0;
  if (!bVar1) {
    m_Do_printf::OSReport_Error("fopAcM_createHeap 確保失敗\n");
    this = (JUTAssertion *)JUTAssertion::getSDevice();
    JUTAssertion::setConfirmMessage
              (this,(ulong)"f_op_actor_mng.cpp",(char *)0x34c,(uint)(*(int *)(param_1 + 0xf0) != 0),
               true,param_6);
  }
  return bVar1;
}


/* __stdcall fopAcM_adjustHeap(fopAc_ac_c *) */

void fopAcM_adjustHeap(int param_1)

{
  m_Do_ext::mDoExt_restoreCurrentHeap();
  m_Do_ext::mDoExt_adjustSolidHeap(*(JKRSolidHeap **)(param_1 + 0xf0));
  return;
}


/* __stdcall fopAcM_DeleteHeap(fopAc_ac_c *) */

void fopAcM_DeleteHeap(int param_1)

{
  fopAcM_Log(param_1,"アクターのヒープの破壊");
  if (*(int *)(param_1 + 0xf0) != 0) {
    m_Do_ext::mDoExt_destroySolidHeap();
    *(undefined4 *)(param_1 + 0xf0) = 0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall fopAcM_entrySolidHeap(fopAc_ac_c *,
                                   int *(fopAc_ac_c *),
                                   unsigned long) */

undefined4
fopAcM_entrySolidHeap(fopAc_ac_c *pActor,void *pCreateHeapCB,ulong maxHeapSize)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  JKRExpHeap *this;
  uint uVar6;
  JKRSolidHeap *pJVar7;
  JKRSolidHeap *pHeap;
  
  pcVar2 = fopAcM_getProcNameString(pActor);
  pHeap = (JKRSolidHeap *)0x0;
  if (maxHeapSize != 0) {
    pHeap = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent(maxHeapSize,0x20);
    if (pHeap == (JKRSolidHeap *)0x0) {
      if (::fopAcM::HeapAdjustQuiet == 0) {
        m_Do_printf::OSReport_Warning("見積もりヒープが確保できませんでした。\n")
        ;
      }
    }
    else {
      iVar3 = (*(code *)pCreateHeapCB)(pActor);
      iVar4 = JKRHeap::getFreeSize(&pHeap->parent);
      if (0x1f < iVar4) {
        JKRHeap::alloc(0x20,0,(JKRHeap *)0x0);
      }
      m_Do_ext::mDoExt_restoreCurrentHeap();
      if (iVar3 == 0) {
        if (::fopAcM::HeapAdjustQuiet == 0) {
          m_Do_printf::OSReport_Error
                    ("見積もりヒープサイズ(%08x)で登録失敗しました。[%s]\n",
                     maxHeapSize,pcVar2);
        }
        m_Do_ext::mDoExt_destroySolidHeap(pHeap);
        pHeap = (JKRSolidHeap *)0x0;
      }
      else {
        iVar4 = (pHeap->parent).mSize;
        iVar3 = JKRHeap::getFreeSize(&pHeap->parent);
        uVar1 = (iVar4 - iVar3) + 0x1fU & 0xffffffe0;
        if (maxHeapSize < uVar1 + 0x40) {
          m_Do_ext::mDoExt_adjustSolidHeap(pHeap);
          pActor->mpHeap = &pHeap->parent;
          return 1;
        }
        if (::fopAcM::HeapAdjustVerbose != '\0') {
          m_Do_printf::OSReport_Warning
                    ("見積もりヒープサイズでは空きが多すぎます。 %08x %08x\n\x1b[m"
                     ,uVar1,maxHeapSize);
        }
      }
    }
  }
  if (pHeap == (JKRSolidHeap *)0x0) {
    pHeap = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent(-1,0x20);
    if (pHeap == (JKRSolidHeap *)0x0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"f_op_actor_mng.cpp",0x453,"heap");
      m_Do_printf::OSPanic("f_op_actor_mng.cpp",0x453,"Halt");
    }
    iVar3 = (*(code *)pCreateHeapCB)(pActor);
    m_Do_ext::mDoExt_restoreCurrentHeap();
    if (iVar3 == 0) {
      m_Do_printf::OSReport_Error("最大空きヒープサイズで登録失敗。[%s]\n",pcVar2);
      m_Do_ext::mDoExt_destroySolidHeap(pHeap);
      return 0;
    }
    if (::fopAcM::HeapAdjustQuiet == 0) {
      JKRHeap::getFreeSize(&pHeap->parent);
    }
  }
  if (pHeap != (JKRSolidHeap *)0x0) {
    if (::fopAcM::HeapAdjustEntry == '\0') {
      m_Do_ext::mDoExt_adjustSolidHeap(pHeap);
      pActor->mpHeap = &pHeap->parent;
      return 1;
    }
    pJVar7 = (JKRSolidHeap *)0x0;
    iVar4 = (pHeap->parent).mSize;
    iVar3 = JKRHeap::getFreeSize(&pHeap->parent);
    uVar1 = (iVar4 - iVar3) + 0xfU & 0xfffffff0;
    this = m_Do_ext::mDoExt_getGameHeap();
    uVar6 = JKRHeap::getFreeSize(&this->parent);
    if (uVar1 + 0x90 < uVar6) {
      pJVar7 = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent(uVar1,0x20);
    }
    if (pJVar7 != (JKRSolidHeap *)0x0) {
      if (pJVar7 < pHeap) {
        m_Do_ext::mDoExt_destroySolidHeap(pHeap);
        pHeap = (JKRSolidHeap *)0x0;
        iVar3 = (*(code *)pCreateHeapCB)(pActor);
        m_Do_ext::mDoExt_restoreCurrentHeap();
        if (iVar3 == 0) {
          uVar5 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar5,"f_op_actor_mng.cpp",0x48d,"result != 0");
          m_Do_printf::OSPanic("f_op_actor_mng.cpp",0x48d,"Halt");
          m_Do_printf::OSReport_Error("ぴったりサイズで、登録失敗？(バグ)\n");
          m_Do_ext::mDoExt_destroySolidHeap(pJVar7);
          pJVar7 = (JKRSolidHeap *)0x0;
        }
      }
      else {
        m_Do_ext::mDoExt_restoreCurrentHeap();
        m_Do_ext::mDoExt_destroySolidHeap(pJVar7);
        pJVar7 = (JKRSolidHeap *)0x0;
      }
    }
    if (pJVar7 != (JKRSolidHeap *)0x0) {
      m_Do_ext::mDoExt_adjustSolidHeap(pJVar7);
      pActor->mpHeap = &pJVar7->parent;
      return 1;
    }
    if (pHeap != (JKRSolidHeap *)0x0) {
      m_Do_ext::mDoExt_adjustSolidHeap(pHeap);
      pActor->mpHeap = &pHeap->parent;
      return 1;
    }
    m_Do_printf::OSReport_Error("ばぐばぐです\n");
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"f_op_actor_mng.cpp",0x4b5,"0");
    m_Do_printf::OSPanic("f_op_actor_mng.cpp",0x4b5,"Halt");
  }
  m_Do_printf::OSReport_Error("fopAcM_entrySolidHeap だめでした [%s]\n",pcVar2);
  return 0;
}


/* __stdcall fopAcM_setCullSizeBox(fopAc_ac_c *,
                                   float,
                                   float,
                                   float,
                                   float,
                                   float,
                                   float) */

void fopAcM_setCullSizeBox
               (fopAc_ac_c *param_1,double param_2,double param_3,double param_4,double param_5,
               double param_6,double param_7)

{
  (param_1->mCullSizeBoxMin).x = (float)param_2;
  (param_1->mCullSizeBoxMin).y = (float)param_3;
  (param_1->mCullSizeBoxMin).z = (float)param_4;
  (param_1->mCullSizeBoxMax).x = (float)param_5;
  (param_1->mCullSizeBoxMax).y = (float)param_6;
  (param_1->mCullSizeBoxMax).z = (float)param_7;
  return;
}


/* __stdcall fopAcM_setCullSizeSphere(fopAc_ac_c *,
                                      float,
                                      float,
                                      float,
                                      float) */

void fopAcM_setCullSizeSphere
               (fopAc_ac_c *param_1,float param_2,float param_3,float param_4,float param_5)

{
  (param_1->mCullSizeBoxMin).x = param_2;
  (param_1->mCullSizeBoxMin).y = param_3;
  (param_1->mCullSizeBoxMin).z = param_4;
  (param_1->mCullSizeBoxMax).x = param_5;
  return;
}


/* __stdcall fopAcM_addAngleY(fopAc_ac_c *,
                              short,
                              short) */

uint fopAcM_addAngleY(fopAc_ac_c *param_1,short param_2,short param_3)

{
  int iVar1;
  
  iVar1 = SComponent::cLib_chaseAngleS(&(param_1->mCurrent).mRot.y);
  return (uint)(iVar1 != 0);
}


/* __stdcall fopAcM_calcSpeed(fopAc_ac_c *) */

void fopAcM_calcSpeed(fopAc_ac_c *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int rotY;
  
  fVar1 = param_1->mVelocityFwd;
  rotY = (int)((int)(param_1->mCurrent).mRot.y & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar3 = (param_1->mVelocity).y + param_1->mAccelerationY;
  fVar2 = JKernel::JMath::jmaCosTable[rotY];
  if (fVar3 < param_1->mVelocityYMin) {
    fVar3 = param_1->mVelocityYMin;
  }
  (param_1->mVelocity).x = fVar1 * JKernel::JMath::jmaSinTable[rotY];
  (param_1->mVelocity).y = fVar3;
  (param_1->mVelocity).z = fVar1 * fVar2;
  return;
}


/* __stdcall fopAcM_posMove(fopAc_ac_c *,
                            cXyz const *) */

void fopAcM_posMove(fopAc_ac_c *param_1,cXyz *param_2)

{
  (param_1->mCurrent).mPos.x = (param_1->mCurrent).mPos.x + (param_1->mVelocity).x;
  (param_1->mCurrent).mPos.y = (param_1->mCurrent).mPos.y + (param_1->mVelocity).y;
  (param_1->mCurrent).mPos.z = (param_1->mCurrent).mPos.z + (param_1->mVelocity).z;
  if (param_2 == (cXyz *)0x0) {
    return;
  }
  (param_1->mCurrent).mPos.x = (param_1->mCurrent).mPos.x + param_2->x;
  (param_1->mCurrent).mPos.y = (param_1->mCurrent).mPos.y + param_2->y;
  (param_1->mCurrent).mPos.z = (param_1->mCurrent).mPos.z + param_2->z;
  return;
}


/* __stdcall fopAcM_posMoveF(fopAc_ac_c *,
                             cXyz const *) */

void fopAcM_posMoveF(fopAc_ac_c *param_1,cXyz *param_2)

{
  fopAcM_calcSpeed(param_1);
  fopAcM_posMove(param_1,param_2);
  return;
}


/* __stdcall fopAcM_searchActorAngleY(fopAc_ac_c *,
                                      fopAc_ac_c *) */

int fopAcM_searchActorAngleY(fopAc_ac_c *param_1,fopAc_ac_c *param_2)

{
  short sVar1;
  
  sVar1 = SComponent::cLib_targetAngleY(&(param_1->mCurrent).mPos,&(param_2->mCurrent).mPos);
  return (int)sVar1;
}


/* __stdcall fopAcM_seenActorAngleY(fopAc_ac_c *,
                                    fopAc_ac_c *) */

short fopAcM_seenActorAngleY(fopAc_ac_c *param_1,fopAc_ac_c *param_2)

{
  short sVar2;
  int iVar1;
  
  sVar2 = SComponent::cLib_targetAngleY(&(param_1->mCurrent).mPos,&(param_2->mCurrent).mPos);
  iVar1 = MSL_C.PPCEABI.bare.H::abs((int)(short)(sVar2 - (param_1->mCollisionRot).y));
  return (short)iVar1;
}


/* __stdcall fopAcM_searchActorDistance(fopAc_ac_c *,
                                        fopAc_ac_c *) */

double fopAcM_searchActorDistance(int param_1,int param_2)

{
  double dVar1;
  double dVar2;
  float fVar3;
  cXyz local_24;
  cXyz local_18 [2];
  
  ::cXyz::operator__(&local_24,(cXyz *)(param_2 + 0x1f8),(cXyz *)(param_1 + 0x1f8));
  local_18[0].x = local_24.x;
  local_18[0].y = local_24.y;
  local_18[0].z = local_24.z;
  fVar3 = mtx::PSVECSquareMag(local_18);
  dVar2 = (double)fVar3;
  if ((double)0_0 < dVar2) {
    dVar1 = 1.0 / SQRT(dVar2);
    dVar1 = _4524 * dVar1 * (_4525 - dVar2 * dVar1 * dVar1);
    dVar1 = _4524 * dVar1 * (_4525 - dVar2 * dVar1 * dVar1);
    dVar2 = (double)(float)(dVar2 * _4524 * dVar1 * (_4525 - dVar2 * dVar1 * dVar1));
  }
  return dVar2;
}


/* __stdcall fopAcM_searchActorDistance2(fopAc_ac_c *,
                                         fopAc_ac_c *) */

double fopAcM_searchActorDistance2(int param_1,int param_2)

{
  float fVar1;
  cXyz local_18;
  cXyz local_c;
  
  ::cXyz::operator__(&local_18,(cXyz *)(param_2 + 0x1f8),(cXyz *)(param_1 + 0x1f8));
  local_c.x = local_18.x;
  local_c.y = local_18.y;
  local_c.z = local_18.z;
  fVar1 = mtx::PSVECSquareMag(&local_c);
  return (double)fVar1;
}


/* __stdcall fopAcM_searchActorDistanceXZ(fopAc_ac_c *,
                                          fopAc_ac_c *) */

double fopAcM_searchActorDistanceXZ(int param_1,int param_2)

{
  double dVar1;
  double dVar2;
  float fVar3;
  cXyz local_24;
  cXyz local_18 [2];
  
  ::cXyz::operator__(local_18,(cXyz *)(param_2 + 0x1f8),(cXyz *)(param_1 + 0x1f8));
  local_24.x = local_18[0].x;
  local_24.y = 0_0;
  local_24.z = local_18[0].z;
  fVar3 = mtx::PSVECSquareMag(&local_24);
  dVar2 = (double)fVar3;
  if ((double)0_0 < dVar2) {
    dVar1 = 1.0 / SQRT(dVar2);
    dVar1 = _4524 * dVar1 * (_4525 - dVar2 * dVar1 * dVar1);
    dVar1 = _4524 * dVar1 * (_4525 - dVar2 * dVar1 * dVar1);
    dVar2 = (double)(float)(dVar2 * _4524 * dVar1 * (_4525 - dVar2 * dVar1 * dVar1));
  }
  return dVar2;
}


/* __stdcall fopAcM_searchActorDistanceXZ2(fopAc_ac_c *,
                                           fopAc_ac_c *) */

double fopAcM_searchActorDistanceXZ2(int param_1,int param_2)

{
  float fVar1;
  cXyz local_18;
  cXyz local_c;
  
  ::cXyz::operator__(&local_c,(cXyz *)(param_2 + 0x1f8),(cXyz *)(param_1 + 0x1f8));
  local_18.x = local_c.x;
  local_18.y = 0_0;
  local_18.z = local_c.z;
  fVar1 = mtx::PSVECSquareMag(&local_18);
  return (double)fVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80025594) */
/* __stdcall fopAcM_rollPlayerCrash(fopAc_ac_c *,
                                    float,
                                    unsigned long) */

undefined4
fopAcM_rollPlayerCrash(fopAc_ac_c *param_1,float param_2,undefined4 param_3)

{
  float fVar1;
  daPy_lk_c *pdVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar7 = (double)(_4688 + param_2);
  dVar6 = (double)fopAcM_searchActorDistanceXZ2
                            (param_1,d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor);
  pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  fVar1 = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent.mPos
          .y - (param_1->mCurrent).mPos.y;
  if (((((double)(float)(dVar7 * dVar7) <= dVar6) || (fVar1 <= _4689)) || (200_0 <= fVar1)) ||
     ((iVar3 = fopAcM_searchActorAngleY
                         (param_1,(fopAc_ac_c *)
                                  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor),
      _4691 <= JKernel::JMath::jmaCosTable
               [(int)((pdVar2->parent).parent.mCurrent.mRot.y - iVar3 & 0xffffU) >>
                (JKernel::JMath::jmaSinShift & 0x3f)] ||
      ((pdVar2->parent).parent.parent.parent.mProcName != 0xa9)))) {
    uVar4 = 0;
  }
  else {
    (*(code *)pdVar2->vtbl->onFrollCrashFlg)(pdVar2,param_3);
    uVar4 = 1;
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return uVar4;
}


/* __stdcall fopAcM_checkCullingBox(float *[][][][],
                                    float,
                                    float,
                                    float,
                                    float,
                                    float,
                                    float) */

uint fopAcM_checkCullingBox
               (MTX34 *param_1,float param_2,float param_3,float param_4,float param_5,float param_6
               ,float param_7)

{
  uint uVar1;
  cXyz local_48;
  cXyz local_3c;
  MTX34 MStack48;
  
  local_48.x = param_5;
  local_48.y = param_6;
  local_48.z = param_7;
  local_3c.x = param_2;
  local_3c.y = param_3;
  local_3c.z = param_4;
  mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,param_1,&MStack48);
  uVar1 = J3DUClipper::clip(&mDoLib_clipper::mClipper,&MStack48,&local_48,&local_3c);
  return (uint)(uVar1 != 0);
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fopAcM_cullingCheck(fopAc_ac_c *) */

uint fopAcM_cullingCheck(fopAc_ac_c *pActor)

{
  bool bVar1;
  MTX34 *pMtx;
  int iVar2;
  uint uVar3;
  cXyz local_88;
  cXyz local_7c;
  cXyz local_70;
  cXyz local_64;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  MTX34 local_40;
  float cullFar;
  float cullFarParam;
  
  if (pActor->mpCullMtx == (MTX34 *)0x0) {
    pMtx = (MTX34 *)&J3DGraphBase::j3dSys;
  }
  else {
    mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,pActor->mpCullMtx,&local_40);
    pMtx = &local_40;
  }
  cullFarParam = pActor->mCullFarDistanceRatio;
  cullFar = cullFarParam;
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode != 0) {
    cullFar = cullFarParam * d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mCullFarClipRatio;
  }
  uVar3 = (uint)pActor->mCullType;
  bVar1 = false;
  if ((uVar3 < 0xe) || (uVar3 == 0xe)) {
    bVar1 = true;
  }
  if (bVar1) {
    if (uVar3 == 0xe) {
      if (cullFarParam <= 0_0) {
        uVar3 = J3DUClipper::clip(&mDoLib_clipper::mClipper,pMtx,&pActor->mCullSizeBoxMax,
                                  &pActor->mCullSizeBoxMin);
      }
      else {
        mDoLib_clipper::mClipper.mFar = cullFar * mDoLib_clipper::mSystemFar;
        J3DUClipper::calcViewFrustum(&mDoLib_clipper::mClipper);
        uVar3 = J3DUClipper::clip(&mDoLib_clipper::mClipper,pMtx,&pActor->mCullSizeBoxMax,
                                  &pActor->mCullSizeBoxMin);
        mDoLib_clipper::mClipper.mFar = mDoLib_clipper::mSystemFar;
        J3DUClipper::calcViewFrustum(&mDoLib_clipper::mClipper);
      }
    }
    else {
      if (cullFarParam <= 0_0) {
        uVar3 = J3DUClipper::clip(&mDoLib_clipper::mClipper,pMtx,&l_cullSizeBox[uVar3].mMax,
                                  &l_cullSizeBox[uVar3].mMin);
      }
      else {
        mDoLib_clipper::mClipper.mFar = cullFar * mDoLib_clipper::mSystemFar;
        J3DUClipper::calcViewFrustum(&mDoLib_clipper::mClipper);
        uVar3 = J3DUClipper::clip(&mDoLib_clipper::mClipper,pMtx,&l_cullSizeBox[uVar3].mMax,
                                  &l_cullSizeBox[uVar3].mMin);
        mDoLib_clipper::mClipper.mFar = mDoLib_clipper::mSystemFar;
        J3DUClipper::calcViewFrustum(&mDoLib_clipper::mClipper);
      }
    }
  }
  else {
    if (uVar3 == 0x17) {
      if (cullFarParam <= 0_0) {
        local_70.x = (pActor->mCullSizeBoxMin).x;
        local_70.y = (pActor->mCullSizeBoxMin).y;
        local_70.z = (pActor->mCullSizeBoxMin).z;
        uVar3 = J3DUClipper::clip(&mDoLib_clipper::mClipper,pMtx,&local_70,
                                  (pActor->mCullSizeBoxMax).x);
      }
      else {
        mDoLib_clipper::mClipper.mFar = cullFar * mDoLib_clipper::mSystemFar;
        J3DUClipper::calcViewFrustum(&mDoLib_clipper::mClipper);
        local_64.x = (pActor->mCullSizeBoxMin).x;
        local_64.y = (pActor->mCullSizeBoxMin).y;
        local_64.z = (pActor->mCullSizeBoxMin).z;
        local_4c = local_64.x;
        local_48 = local_64.y;
        local_44 = local_64.z;
        uVar3 = J3DUClipper::clip(&mDoLib_clipper::mClipper,pMtx,&local_64,
                                  (pActor->mCullSizeBoxMax).x);
        mDoLib_clipper::mClipper.mFar = mDoLib_clipper::mSystemFar;
        J3DUClipper::calcViewFrustum(&mDoLib_clipper::mClipper);
      }
    }
    else {
      iVar2 = uVar3 - 0xf;
      if (cullFarParam <= 0_0) {
        local_88.x = l_cullSizeSphere[iVar2].mCenter.x;
        local_88.y = l_cullSizeSphere[iVar2].mCenter.y;
        local_88.z = l_cullSizeSphere[iVar2].mCenter.z;
        uVar3 = J3DUClipper::clip(&mDoLib_clipper::mClipper,pMtx,&local_88,
                                  l_cullSizeSphere[iVar2].mRadius);
      }
      else {
        mDoLib_clipper::mClipper.mFar = cullFar * mDoLib_clipper::mSystemFar;
        J3DUClipper::calcViewFrustum(&mDoLib_clipper::mClipper);
        local_7c.x = l_cullSizeSphere[iVar2].mCenter.x;
        local_7c.y = l_cullSizeSphere[iVar2].mCenter.y;
        local_7c.z = l_cullSizeSphere[iVar2].mCenter.z;
        local_58 = local_7c.x;
        local_54 = local_7c.y;
        local_50 = local_7c.z;
        uVar3 = J3DUClipper::clip(&mDoLib_clipper::mClipper,pMtx,&local_7c,
                                  l_cullSizeSphere[iVar2].mRadius);
        mDoLib_clipper::mClipper.mFar = mDoLib_clipper::mSystemFar;
        J3DUClipper::calcViewFrustum(&mDoLib_clipper::mClipper);
      }
    }
  }
  return uVar3;
}


/* __stdcall fopAcM_orderTalkEvent(fopAc_ac_c *,
                                   fopAc_ac_c *) */

void fopAcM_orderTalkEvent(fopAc_ac_c *param_1,fopAc_ac_c *param_2)

{
  dEvt_control_c::order
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,Talk,0x1ff,None,0x14f,param_1,
             param_2,-1,0xff);
  return;
}


/* __stdcall fopAcM_orderTalkXBtnEvent(fopAc_ac_c *,
                                       fopAc_ac_c *) */

void fopAcM_orderTalkXBtnEvent(fopAc_ac_c *param_1,fopAc_ac_c *param_2)

{
  dEvt_control_c::order
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,Talk_XBtn,500,None,0x14f,param_1,
             param_2,-1,0xff);
  return;
}


/* __stdcall fopAcM_orderTalkYBtnEvent(fopAc_ac_c *,
                                       fopAc_ac_c *) */

void fopAcM_orderTalkYBtnEvent(fopAc_ac_c *param_1,fopAc_ac_c *param_2)

{
  dEvt_control_c::order
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,Talk_YBtn,500,None,0x14f,param_1,
             param_2,-1,0xff);
  return;
}


/* __stdcall fopAcM_orderTalkZBtnEvent(fopAc_ac_c *,
                                       fopAc_ac_c *) */

void fopAcM_orderTalkZBtnEvent(fopAc_ac_c *param_1,fopAc_ac_c *param_2)

{
  dEvt_control_c::order
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,Talk_ZBtn,500,None,0x14f,param_1,
             param_2,-1,0xff);
  return;
}


/* __stdcall fopAcM_orderZHintEvent(fopAc_ac_c *,
                                    fopAc_ac_c *) */

void fopAcM_orderZHintEvent(fopAc_ac_c *param_1,fopAc_ac_c *param_2)

{
  dEvt_control_c::order
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,Talk,0x1ff,None,0xffff,param_1,
             param_2,-1,0xff);
  return;
}


/* __stdcall fopAcM_orderSpeakEvent(fopAc_ac_c *) */

void fopAcM_orderSpeakEvent(fopAc_ac_c *param_1)

{
  dEvt_control_c::order
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,Talk,0x1ea,None,0x14f,
             (fopAc_ac_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor,param_1,-1,0xff
            );
  return;
}


/* __stdcall fopAcM_orderDoorEvent(fopAc_ac_c *,
                                   fopAc_ac_c *) */

void fopAcM_orderDoorEvent(fopAc_ac_c *param_1,fopAc_ac_c *param_2)

{
  dEvt_control_c::order
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,Door,0xff,None,0xffff,param_1,
             param_2,-1,0xff);
  return;
}


/* __stdcall fopAcM_orderCatchEvent(fopAc_ac_c *,
                                    fopAc_ac_c *) */

void fopAcM_orderCatchEvent(fopAc_ac_c *param_1,fopAc_ac_c *param_2)

{
  dEvt_control_c::order
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,Catch,1,None,0xffff,param_1,param_2,
             -1,0xff);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall fopAcM_orderOtherEvent2(fopAc_ac_c *,
                                     char *,
                                     unsigned short,
                                     unsigned short) */

void fopAcM_orderOtherEvent2
               (fopAc_ac_c *pActor,char *pEventName,dEvt__OrderFlag flag,ushort param_4)

{
  short eventIdx;
  ushort priority;
  
  eventIdx = dEvent_manager_c::getEventIdx
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,pEventName,0xff);
  priority = dEvent_manager_c::getEventPrio
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,eventIdx);
  if (priority == 0) {
    priority = 0xff;
  }
  dEvt_control_c::orderOld
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,Other,priority,flag,param_4,pActor,
             (fopAc_ac_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor,pEventName);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fopAcM_orderChangeEvent(fopAc_ac_c *,
                                     char *,
                                     unsigned short,
                                     unsigned short) */

void fopAcM_orderChangeEvent
               (undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = dEvent_manager_c::getEventIdx
                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,param_2,0xff);
  fopAcM_orderChangeEventId(param_1,uVar1,param_3,param_4);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall fopAcM_orderChangeEvent(fopAc_ac_c *,
                                     fopAc_ac_c *,
                                     char *,
                                     unsigned short,
                                     unsigned short) */

void fopAcM_orderChangeEvent
               (undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = dEvent_manager_c::getEventIdx
                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,param_3,0xff);
  fopAcM_orderChangeEventId(param_1,param_2,uVar1,param_4,param_5);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall fopAcM_orderChangeEventId(fopAc_ac_c *,
                                       short,
                                       unsigned short,
                                       unsigned short) */

void fopAcM_orderChangeEventId
               (fopAc_ac_c *param_1,short param_2,dEvt__OrderFlag param_3,ushort param_4)

{
  ushort priority;
  
  priority = dEvent_manager_c::getEventPrio
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,param_2);
  if (priority == 0) {
    priority = 0xff;
  }
  dEvt_control_c::order
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,Change,priority,param_3,param_4,
             param_1,(fopAc_ac_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor,param_2
             ,0xff);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall fopAcM_orderChangeEventId(fopAc_ac_c *,
                                       fopAc_ac_c *,
                                       short,
                                       unsigned short,
                                       unsigned short) */

void fopAcM_orderChangeEventId
               (fopAc_ac_c *param_1,fopAc_ac_c *param_2,short param_3,dEvt__OrderFlag param_4,
               ushort param_5)

{
  ushort priority;
  
  priority = dEvent_manager_c::getEventPrio
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,param_3);
  if (priority == 0) {
    priority = 0xff;
  }
  dEvt_control_c::order
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,Change,priority,param_4,param_5,
             param_1,param_2,param_3,0xff);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall fopAcM_orderOtherEventId(fopAc_ac_c *,
                                      short,
                                      unsigned char,
                                      unsigned short,
                                      unsigned short,
                                      unsigned short) */

void fopAcM_orderOtherEventId
               (fopAc_ac_c *this,short eventIndex,byte param_3,ushort param_4,ushort param_5,
               dEvt__OrderFlag param_6)

{
  if (param_5 == 0) {
    param_5 = dEvent_manager_c::getEventPrio
                        (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,eventIndex);
    if (param_5 == 0) {
      param_5 = 0xff;
    }
  }
  dEvt_control_c::order
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,Other,param_5,param_6,param_4,this,
             (fopAc_ac_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor,eventIndex,
             param_3);
  return;
}


/* __stdcall fopAcM_orderPotentialEvent(fopAc_ac_c *,
                                        unsigned short,
                                        unsigned short,
                                        unsigned short) */

void fopAcM_orderPotentialEvent
               (fopAc_ac_c *param_1,dEvt__OrderFlag param_2,ushort param_3,ushort param_4)

{
  if (param_4 == 0) {
    param_4 = 0xff;
  }
  dEvt_control_c::order
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,Potential,param_4,param_2,param_3,
             param_1,(fopAc_ac_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor,-1,0xff
            );
  return;
}


/* __stdcall fopAcM_orderItemEvent(fopAc_ac_c *) */

void fopAcM_orderItemEvent(fopAc_ac_c *param_1)

{
  dEvt_control_c::order
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,Item,0xff,None,0xffff,
             (fopAc_ac_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor,param_1,-1,0xff
            );
  return;
}


/* __stdcall fopAcM_orderTreasureEvent(fopAc_ac_c *,
                                       fopAc_ac_c *) */

void fopAcM_orderTreasureEvent(fopAc_ac_c *param_1,fopAc_ac_c *param_2)

{
  dEvt_control_c::order
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,Treasure,0xff,None,0xffff,param_1,
             param_2,-1,0xff);
  return;
}


/* __stdcall fopAcM_getTalkEventPartner(fopAc_ac_c *) */

void fopAcM_getTalkEventPartner(void)

{
  dEvt_control_c::convPId
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mPtTalk);
  return;
}


/* __stdcall fopAcM_getItemEventPartner(fopAc_ac_c *) */

void fopAcM_getItemEventPartner(void)

{
  dEvt_control_c::convPId
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mPtItem);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fopAcM_getEventPartner(fopAc_ac_c *) */

void fopAcM_getEventPartner(fopAc_ac_c *param_1)

{
  fopAc_ac_c *pfVar1;
  
  pfVar1 = dEvt_control_c::convPId
                     (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mPt1);
  if (pfVar1 == param_1) {
    dEvt_control_c::convPId
              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mPt2);
  }
  else {
    dEvt_control_c::convPId
              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mPt1);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall fopAcM_createItemForPresentDemo(cXyz *,
                                             int,
                                             unsigned char,
                                             int,
                                             int,
                                             csXyz *,
                                             cXyz *) */

int fopAcM_createItemForPresentDemo
              (cXyz *param_1,dItem_data__ItemNo param_2,byte param_3,int param_4,int param_5,
              csXyz *param_6,cXyz *param_7)

{
  bool bVar1;
  ulong uVar2;
  int iVar3;
  int3 in_register_00000010;
  undefined3 in_register_00000014;
  
  iVar3 = CONCAT31(in_register_00000010,param_2);
  bVar1 = false;
  if ((-1 < in_register_00000010) && (iVar3 < 0x100)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"f_op_actor_mng.cpp",0x96d,"0 <= i_itemNo && i_itemNo < 256");
    m_Do_printf::OSPanic("f_op_actor_mng.cpp",0x96d,"Halt");
  }
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mCurStaffId = param_2;
  if (iVar3 == 0xff) {
    iVar3 = -1;
  }
  else {
    iVar3 = fopAcM_createDemoItem
                      (param_1,iVar3,param_4,param_6,param_5,param_7,
                       CONCAT31(in_register_00000014,param_3));
  }
  return iVar3;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall fopAcM_createItemForTrBoxDemo(cXyz *,
                                           int,
                                           int,
                                           int,
                                           csXyz *,
                                           cXyz *) */

undefined4
fopAcM_createItemForTrBoxDemo
          (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  bool bVar1;
  ulong uVar2;
  undefined4 uVar3;
  
  bVar1 = false;
  if ((-1 < param_2) && (param_2 < 0x100)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"f_op_actor_mng.cpp",0x99a,"0 <= i_itemNo && i_itemNo < 256");
    m_Do_printf::OSPanic("f_op_actor_mng.cpp",0x99a,"Halt");
  }
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mCurStaffId = (byte)param_2;
  if (param_2 == 0xff) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = fopAcM_createDemoItem(param_1,param_2,param_3,param_5,param_4,param_6,0);
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* __stdcall fopAcM_createItemFromTable(cXyz *,
                                        int,
                                        int,
                                        int,
                                        int,
                                        csXyz *,
                                        int,
                                        cXyz *) */

int fopAcM_createItemFromTable
              (cXyz *param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
              csXyz *param_6,undefined4 param_7,cXyz *param_8)

{
  dItem_data__ItemNo dVar1;
  bool bVar2;
  void *pvVar3;
  ulong uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  dItem_data__ItemNo *pdVar8;
  int iVar9;
  int iVar10;
  int unaff_r25;
  float fVar11;
  csXyz local_78;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  cXyz local_4c;
  longlong local_40;
  
  bVar2 = false;
  if (((((-1 < (int)param_2) && ((int)param_2 < 0x40)) && (-2 < param_3)) && (param_3 < 0x50)) ||
     (param_3 == 0x7f)) {
    bVar2 = true;
  }
  if (!bVar2) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar4,"f_op_actor_mng.cpp",0x9d2,
               "0 <= i_itemNo && i_itemNo < 64 && (-1 <= i_itemBitNo && i_itemBitNo <= 79) || i_itemBitNo == 127"
              );
    m_Do_printf::OSPanic("f_op_actor_mng.cpp",0x9d2,"Halt");
  }
  if (init_5082 == '\0') {
    local_58 = _4688;
    local_54 = 0_0;
    local_50 = 0_0;
    fairy_offset_tbl_5080 = _4688;
    DAT_803b9da0 = 0_0;
    DAT_803b9da4 = 0_0;
    Runtime.PPCEABI.H::__register_global_object(&fairy_offset_tbl_5080,::cXyz::_cXyz,&_5081);
    local_64 = _5233;
    local_60 = 0_0;
    local_5c = 0_0;
    DAT_803b9da8 = _5233;
    DAT_803b9dac = 0_0;
    DAT_803b9db0 = 0_0;
    Runtime.PPCEABI.H::__register_global_object(&DAT_803b9da8,::cXyz::_cXyz,&_5084);
    local_70 = 0_0;
    local_6c = 0_0;
    local_68 = _4688;
    DAT_803b9db4 = 0_0;
    DAT_803b9db8 = 0_0;
    DAT_803b9dbc = _4688;
    Runtime.PPCEABI.H::__register_global_object(&DAT_803b9db4,::cXyz::_cXyz,&_5085);
    init_5082 = '\x01';
  }
  local_4c.x = 0_0;
  local_4c.y = 0_0;
  local_4c.z = 0_0;
  ::csXyz::csXyz(&local_78,0,0,0);
  pvVar3 = d_com_inf_game::g_dComIfG_gameInfo.mpItemTableArchive;
  if ((0x1f < (int)param_2) && ((int)param_2 < 0x3f)) {
    iVar9 = param_2 - 0x20;
    if (iVar9 < 0xb) {
      if ((iVar9 < 5) && (0 < iVar9)) {
        uVar6 = ((uint)(ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                               mCurrHp * 100) /
                ((ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxHp &
                0xfc) & 0xff;
        if ((uVar6 == 0) || (0x14 < uVar6)) {
          if ((uVar6 < 0x15) || (0x28 < uVar6)) {
            if ((uVar6 < 0x29) || (0x50 < uVar6)) {
              if ((0x50 < uVar6) && (uVar6 < 0x65)) {
                iVar9 = 1;
              }
            }
            else {
              iVar9 = 2;
            }
          }
          else {
            iVar9 = 3;
          }
        }
        else {
          iVar9 = 4;
        }
      }
    }
    else {
      if (iVar9 < 0x15) {
        if (d_com_inf_game::g_dComIfG_gameInfo.mpItemTableArchive == (void *)0x0) {
          return -1;
        }
        pdVar8 = (dItem_data__ItemNo *)
                 ((int)d_com_inf_game::g_dComIfG_gameInfo.mpItemTableArchive + iVar9 * 0x10 + 0x10);
        iVar7 = 0;
        iVar10 = 0;
        while( true ) {
          dVar1 = *pdVar8;
          if (dVar1 == InvalidItem) {
            return unaff_r25;
          }
          if (0xf < iVar7) break;
          if (param_1 != (cXyz *)0x0) {
            local_4c.x = param_1->x;
            local_4c.y = param_1->y;
            local_4c.z = param_1->z;
          }
          if (param_6 != (csXyz *)0x0) {
            local_78.x = param_6->x;
            local_78.y = param_6->y;
            local_78.z = param_6->z;
          }
          if (iVar9 == 0x16) {
            mtx::PSVECAdd(&local_4c,(cXyz *)((int)&fairy_offset_tbl_5080 + iVar10),&local_4c);
            fVar11 = SComponent::cM_rndF(_5234);
            local_40 = (longlong)(int)fVar11;
            local_78.y = (short)(int)fVar11;
          }
          uVar6 = d_item::getItemNoByLife(dVar1);
          iVar5 = fopAcM_fastCreateItem2
                            (&local_4c,uVar6 & 0xff,param_3,param_4,param_5,&local_78,8,(cXyz *)0x0)
          ;
          if (iVar5 == 0) {
            unaff_r25 = -1;
          }
          else {
            unaff_r25 = *(int *)(iVar5 + 4);
          }
          if (unaff_r25 == -1) {
            return -1;
          }
          pdVar8 = pdVar8 + 1;
          iVar7 = iVar7 + 1;
          iVar10 = iVar10 + 0xc;
        }
        return unaff_r25;
      }
    }
    fVar11 = SComponent::cM_rndF(_5235);
    local_40 = (longlong)(int)fVar11;
    param_2 = (uint)*(byte *)((int)pvVar3 + (int)fVar11 + iVar9 * 0x10 + 0x10);
  }
  if ((param_2 == 0x3f) || (param_2 == 0xff)) {
    iVar9 = -1;
  }
  else {
    uVar6 = d_item::getItemNoByLife((dItem_data__ItemNo)param_2);
    iVar9 = fopAcM_fastCreateItem2
                      (param_1,uVar6 & 0xff,param_3,param_4,param_5,param_6,param_7,param_8);
    if (iVar9 == 0) {
      iVar9 = -1;
    }
    else {
      iVar9 = *(int *)(iVar9 + 4);
    }
  }
  return iVar9;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __stdcall fopAcM_createRaceItemFromTable(cXyz *,
                                            int,
                                            int,
                                            int,
                                            csXyz *,
                                            cXyz *,
                                            int) */

undefined4
fopAcM_createRaceItemFromTable
          (undefined4 param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7)

{
  bool bVar1;
  void *pvVar2;
  ulong uVar3;
  undefined4 uVar4;
  undefined uVar5;
  float fVar6;
  
  bVar1 = false;
  if (((((-1 < (int)param_2) && ((int)param_2 < 0x40)) && (-2 < param_3)) && (param_3 < 0x50)) ||
     (param_3 == 0x7f)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar3,"f_op_actor_mng.cpp",0xa64,
               "0 <= i_itemNo && i_itemNo < 64 && (-1 <= i_itemBitNo && i_itemBitNo <= 79) || i_itemBitNo == 127"
              );
    m_Do_printf::OSPanic("f_op_actor_mng.cpp",0xa64,"Halt");
  }
  pvVar2 = d_com_inf_game::g_dComIfG_gameInfo.mpItemTableArchive;
  if ((0x1f < (int)param_2) && ((int)param_2 < 0x3f)) {
    fVar6 = SComponent::cM_rndF(_5235);
    param_2 = (uint)*(byte *)((int)pvVar2 + (int)fVar6 + (param_2 - 0x20) * 0x10 + 0x10);
  }
  if ((param_2 == 0x3f) || (param_2 == 0xff)) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar5 = d_item::getItemNoByLife((dItem_data__ItemNo)param_2);
    uVar4 = fopAcM_createRaceItem(param_1,uVar5,param_3,param_5,param_4,param_6,param_7);
  }
  return uVar4;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall fopAcM_createShopItem(cXyz *,
                                   int,
                                   csXyz *,
                                   int,
                                   cXyz *,
                                   int *(void *)) */

int fopAcM_createShopItem
              (cXyz *pos,ulong itemNo,csXyz *rotation,int roomNo,cXyz *scale,undefined *param_6)

{
  bool bVar1;
  ulong uVar2;
  int uVar3;
  
  bVar1 = false;
  if ((-1 < (int)itemNo) && ((int)itemNo < 0x100)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"f_op_actor_mng.cpp",0xa9c,"0 <= i_itemNo && i_itemNo < 256");
    m_Do_printf::OSPanic("f_op_actor_mng.cpp",0xa9c,"Halt");
  }
  if (itemNo == 0xff) {
    uVar3 = -1;
  }
  else {
    uVar3 = fopAcM_create(0x105,itemNo,pos,roomNo,rotation,scale,0xff,param_6);
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall fopAcM_createRaceItem(cXyz *,
                                   int,
                                   int,
                                   csXyz *,
                                   int,
                                   cXyz *,
                                   int) */

undefined4
fopAcM_createRaceItem
          (cXyz *param_1,int param_2,uint param_3,csXyz *param_4,int param_5,cXyz *param_6,
          uint param_7)

{
  bool bVar1;
  ulong uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  bVar1 = false;
  if (((((-1 < param_2) && (param_2 < 0x100)) && (-2 < (int)param_3)) && ((int)param_3 < 0x50)) ||
     (param_3 == 0x7f)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar2,"f_op_actor_mng.cpp",0xacb,
               "0 <= i_itemNo && i_itemNo < 256 && (-1 <= i_itemBitNo && i_itemBitNo <= 79) || i_itemBitNo == 127"
              );
    m_Do_printf::OSPanic("f_op_actor_mng.cpp",0xacb,"Halt");
  }
  if (param_2 == 0xff) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar4 = d_item::check_itemno(param_2);
    uVar3 = fopAcM_create(0x104,(param_7 & 0xf) << 0xf | (param_3 & 0x7f) << 8 | uVar4 & 0xff,
                          param_1,param_5,param_4,param_6,0xff,(undefined *)0x0);
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall fopAcM_createDemoItem(cXyz *,
                                   int,
                                   int,
                                   csXyz *,
                                   int,
                                   cXyz *,
                                   unsigned char) */

undefined4
fopAcM_createDemoItem
          (cXyz *param_1,uint param_2,uint param_3,csXyz *param_4,int param_5,cXyz *param_6,
          uint param_7)

{
  bool bVar1;
  ulong uVar2;
  undefined4 uVar3;
  
  bVar1 = false;
  if (((((-1 < (int)param_2) && ((int)param_2 < 0x100)) && (-2 < (int)param_3)) &&
      ((int)param_3 < 0x50)) || (param_3 == 0x7f)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar2,"f_op_actor_mng.cpp",0xafd,
               "0 <= i_itemNo && i_itemNo < 256 && (-1 <= i_itemBitNo && i_itemBitNo <= 79) || i_itemBitNo == 127"
              );
    m_Do_printf::OSPanic("f_op_actor_mng.cpp",0xafd,"Halt");
  }
  if (param_2 == 0xff) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = fopAcM_create(0x103,(param_7 & 0xff) << 0x10 | param_2 & 0xff | (param_3 & 0x7f) << 8,
                          param_1,param_5,param_4,param_6,0xff,(undefined *)0x0);
  }
  return uVar3;
}


/* __stdcall fopAcM_createItemForBoss(cXyz *,
                                      int,
                                      int,
                                      csXyz *,
                                      cXyz *,
                                      int) */

void fopAcM_createItemForBoss
               (cXyz *position,int param_2,int roomNo,csXyz *rotation,cXyz *scale,int param_6)

{
  if (param_6 == 1) {
    fopAcM_createItem(position,HeartContainer,-1,roomNo,3,rotation,0xc,scale);
  }
  else {
    fopAcM_createItem(position,HeartContainer,-1,roomNo,3,rotation,5,scale);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Could not reconcile some variable overlaps */
/* __stdcall fopAcM_createItem(cXyz *,
                               int,
                               int,
                               int,
                               int,
                               csXyz *,
                               int,
                               cXyz *) */

undefined4
fopAcM_createItem
          (cXyz *position,dItem_data__ItemNo itemNo,int itemPickupFlag,int roomNo,uint param_5,
          csXyz *rotation,int itemAction,cXyz *scale)

{
  bool bVar1;
  ulong uVar2;
  undefined4 uVar3;
  uint uVar4;
  int3 in_register_00000010;
  int iVar5;
  csXyz rotationAndAuxParams;
  
  iVar5 = CONCAT31(in_register_00000010,itemNo);
  bVar1 = false;
  if (((((-1 < in_register_00000010) && (iVar5 < 0x100)) && (-2 < itemPickupFlag)) &&
      (itemPickupFlag < 0x50)) || (itemPickupFlag == 0x7f)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar2,"f_op_actor_mng.cpp",0xb63,
               "0 <= i_itemNo && i_itemNo < 256 && (-1 <= i_itemBitNo && i_itemBitNo <= 79) || i_itemBitNo == 127"
              );
    m_Do_printf::OSPanic("f_op_actor_mng.cpp",0xb63,"Halt");
  }
  if (iVar5 == 0xff) {
    uVar3 = 0xffffffff;
  }
  else {
    rotationAndAuxParams._0_4_ = ::csXyz::Zero._0_4_;
    if (rotation != (csXyz *)0x0) {
      rotationAndAuxParams._0_4_ = *(undefined4 *)rotation;
    }
    rotationAndAuxParams.z = 0xff;
    uVar4 = d_item::check_itemno(iVar5);
    uVar4 = itemAction << 0x1a |
            (param_5 & 3) << 0x18 | (itemPickupFlag & 0xffU) << 8 | uVar4 & 0xff | 0xff0000;
    if (iVar5 == 0x1e) {
      iVar5 = 0;
      do {
        fopAcM_create(0x101,uVar4,position,roomNo,&rotationAndAuxParams,scale,0xff,(undefined *)0x0)
        ;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 2);
    }
    else {
      if ((iVar5 < 0x1e) && (iVar5 == 0x16)) {
        uVar3 = fopAcM_create(0x16a,1,position,roomNo,rotation,scale,0xff,(undefined *)0x0);
        return uVar3;
      }
    }
    uVar3 = fopAcM_create(0x101,uVar4,position,roomNo,&rotationAndAuxParams,scale,0xff,
                          (undefined *)0x0);
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Could not reconcile some variable overlaps */
/* __stdcall fopAcM_fastCreateItem2(cXyz *,
                                    int,
                                    int,
                                    int,
                                    int,
                                    csXyz *,
                                    int,
                                    cXyz *) */

fopAc_ac_c *
fopAcM_fastCreateItem2
          (cXyz *position,int param_2,uint param_3,int roomNo,uint param_5,csXyz *rotation,
          int param_7,cXyz *scale)

{
  bool bVar1;
  ulong uVar2;
  fopAc_ac_c *pfVar3;
  uint uVar4;
  int iVar5;
  csXyz rotationAndAuxParams;
  
  bVar1 = false;
  if (((((-1 < param_2) && (param_2 < 0x100)) && (-2 < (int)param_3)) && ((int)param_3 < 0x50)) ||
     (param_3 == 0x7f)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar2,"f_op_actor_mng.cpp",0xbb3,
               "0 <= i_itemNo && i_itemNo < 256 && (-1 <= i_itemBitNo && i_itemBitNo <= 79) || i_itemBitNo == 127"
              );
    m_Do_printf::OSPanic("f_op_actor_mng.cpp",0xbb3,"Halt");
  }
  rotationAndAuxParams._0_4_ = ::csXyz::Zero._0_4_;
  if (param_2 == 0xff) {
    pfVar3 = (fopAc_ac_c *)0x0;
  }
  else {
    if (rotation != (csXyz *)0x0) {
      rotationAndAuxParams._0_4_ = *(undefined4 *)rotation;
    }
    rotationAndAuxParams.z = 0xff;
    uVar4 = d_item::check_itemno(param_2);
    uVar4 = param_7 << 0x1a |
            (param_5 & 3) << 0x18 | (param_3 & 0xff) << 8 | uVar4 & 0xff | 0xff0000;
    if (param_2 == 0x1e) {
      iVar5 = 0;
      do {
        fopAcM_fastCreate(0x101,uVar4,position,roomNo,&rotationAndAuxParams,scale,0xff,
                          (undefined *)0x0,(void *)0x0);
        iVar5 = iVar5 + 1;
      } while (iVar5 < 2);
    }
    else {
      if ((param_2 < 0x1e) && (param_2 == 0x16)) {
        pfVar3 = fopAcM_fastCreate(0x16a,1,position,roomNo,rotation,scale,0xff,(undefined *)0x0,
                                   (void *)0x0);
        return pfVar3;
      }
    }
    pfVar3 = fopAcM_fastCreate(0x101,uVar4,position,roomNo,&rotationAndAuxParams,scale,0xff,
                               (undefined *)0x0,(void *)0x0);
  }
  return pfVar3;
}


/* WARNING: Inlined function: FUN_80328ea8 */
/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328ef4 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall fopAcM_createItemForKP2(cXyz *,
                                     int,
                                     int,
                                     csXyz *,
                                     cXyz *,
                                     float,
                                     float,
                                     float,
                                     unsigned short) */

fopAc_ac_c *
fopAcM_createItemForKP2
          (double param_1,double param_2,double param_3,cXyz *param_4,uint param_5,int param_6,
          csXyz *param_7,cXyz *param_8,uint param_9)

{
  bool bVar1;
  ulong uVar2;
  fopAc_ac_c *pfVar3;
  
  bVar1 = false;
  if ((-1 < (int)param_5) && ((int)param_5 < 0x100)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"f_op_actor_mng.cpp",0xc25,"0 <= i_itemNo && i_itemNo < 256");
    m_Do_printf::OSPanic("f_op_actor_mng.cpp",0xc25,"Halt");
  }
  if (param_5 == 0xff) {
    pfVar3 = (fopAc_ac_c *)0x0;
  }
  else {
    pfVar3 = fopAcM_fastCreate(0x107,param_5 | (param_9 & 0xffff) << 8,param_4,param_6,param_7,
                               param_8,0xff,(undefined *)0x0,(void *)0x0);
    if (pfVar3 != (fopAc_ac_c *)0x0) {
      pfVar3->mVelocityFwd = (float)param_1;
      (pfVar3->mVelocity).y = (float)param_2;
      pfVar3->mAccelerationY = (float)param_3;
    }
  }
  return pfVar3;
}


/* __stdcall fopAcM_createItemForSimpleDemo(cXyz *,
                                            int,
                                            int,
                                            csXyz *,
                                            cXyz *,
                                            float,
                                            float) */

void fopAcM_createItemForSimpleDemo
               (double param_1,double param_2,cXyz *param_3,uint param_4,int param_5,csXyz *param_6,
               cXyz *param_7)

{
  daItem_c *pdVar1;
  
  pdVar1 = fopAcM_fastCreateItem
                     (param_3,param_4,param_5,param_6,param_7,param_1,param_2,(double)_5382,
                      0xffffffff,0);
  if (pdVar1 != (daItem_c *)0x0) {
    pdVar1->mCurAction = 5;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x8002722c) */
/* WARNING: Removing unreachable block (ram,0x80027224) */
/* WARNING: Removing unreachable block (ram,0x80027234) */
/* __stdcall fopAcM_fastCreateItem(cXyz *,
                                   int,
                                   int,
                                   csXyz *,
                                   cXyz *,
                                   float,
                                   float,
                                   float,
                                   int,
                                   int *(void *)) */

daItem_c *
fopAcM_fastCreateItem
          (cXyz *position,uint itemNo,int roomNum,csXyz *rotation,cXyz *scale,double speed,
          double param_7,double param_8,uint itemPickupFlag,undefined *param_10)

{
  ulong uVar1;
  daItem_c *item;
  uint parameters;
  bool bVar2;
  daItem_c *item2;
  int iVar3;
  undefined4 uVar4;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  float fVar5;
  csXyz rotationAndAuxParams;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  bVar2 = false;
  if ((-1 < (int)itemNo) && ((int)itemNo < 0x100)) {
    bVar2 = true;
  }
  if (!bVar2) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"f_op_actor_mng.cpp",0xc81,"0 <= i_itemNo && i_itemNo < 256");
    m_Do_printf::OSPanic("f_op_actor_mng.cpp",0xc81,"Halt");
  }
  if (itemNo == 0xff) {
    item = (daItem_c *)0x0;
  }
  else {
    parameters = d_item::check_itemno(itemNo);
    parameters = (itemPickupFlag & 0xff) << 8 | parameters & 0xff | 0x28ff0000;
    bVar2 = d_item::isHeart((dItem_data__ItemNo)itemNo);
    if (bVar2 != false) {
      speed = (double)(float)((double)_5453 * speed);
    }
    if (itemNo == 0x1e) {
      iVar3 = 0;
      do {
        if (rotation == (csXyz *)0x0) {
          rotationAndAuxParams.x = ::csXyz::Zero.x;
          rotationAndAuxParams.y = ::csXyz::Zero.y;
        }
        else {
          rotationAndAuxParams.x = rotation->x;
          rotationAndAuxParams.y = rotation->y;
        }
        rotationAndAuxParams.z = 0xff;
        fVar5 = SComponent::cM_rndFX(8192_0);
        rotationAndAuxParams.y = rotationAndAuxParams.y + (short)(int)fVar5;
        item2 = (daItem_c *)
                fopAcM_fastCreate(0x101,parameters,position,roomNum,&rotationAndAuxParams,scale,0xff
                                  ,param_10,(void *)0x0);
        if (item2 != (daItem_c *)0x0) {
          fVar5 = SComponent::cM_rndFX(_5456);
          (item2->parent).parent.mVelocityFwd = (float)(speed * (double)(_5455 + fVar5));
          fVar5 = SComponent::cM_rndFX(_5457);
          (item2->parent).parent.mVelocity.y = (float)(param_7 * (double)(_5455 + fVar5));
          (item2->parent).parent.mAccelerationY = (float)param_8;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 2);
    }
    else {
      if (((int)itemNo < 0x1e) && (itemNo == 0x16)) {
        item = (daItem_c *)
               fopAcM_fastCreate(0x16a,1,position,roomNum,rotation,scale,0xff,(undefined *)0x0,
                                 (void *)0x0);
        goto LAB_80027224;
      }
    }
    if (rotation == (csXyz *)0x0) {
      rotationAndAuxParams.x = ::csXyz::Zero.x;
      rotationAndAuxParams.y = ::csXyz::Zero.y;
    }
    else {
      rotationAndAuxParams.x = rotation->x;
      rotationAndAuxParams.y = rotation->y;
    }
    rotationAndAuxParams.z = 0xff;
    item = (daItem_c *)
           fopAcM_fastCreate(0x101,parameters,position,roomNum,&rotationAndAuxParams,scale,0xff,
                             param_10,(void *)0x0);
    if (item != (daItem_c *)0x0) {
      (item->parent).parent.mVelocityFwd = (float)speed;
      (item->parent).parent.mVelocity.y = (float)param_7;
      (item->parent).parent.mAccelerationY = (float)param_8;
    }
  }
LAB_80027224:
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  return item;
}


/* __stdcall stealItem_CB(void *) */

undefined4 stealItem_CB(int param_1)

{
  float fVar1;
  
  fVar1 = _5455;
  if (param_1 != 0) {
    *(float *)(param_1 + 0x214) = _5455;
    *(float *)(param_1 + 0x218) = fVar1;
    *(float *)(param_1 + 0x21c) = fVar1;
    *(byte *)(param_1 + 0x669) = *(byte *)(param_1 + 0x669) | 0x40;
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall fopAcM_createStealItem(cXyz *,
                                    int,
                                    int,
                                    csXyz *,
                                    int) */

void fopAcM_createStealItem
               (cXyz *param_1,undefined2 param_2,int param_3,csXyz *param_4,uint param_5)

{
  dItem_data__ItemNo dVar3;
  uint uVar1;
  int iVar2;
  
  dVar3 = d_item::getEmonoItemFromLifeBallTable(param_2);
  uVar1 = d_item::isLimitedItem(dVar3);
  if (uVar1 == 0) {
    iVar2 = d_item::isNonSavedEmono(dVar3);
    if (iVar2 == 0) {
      if (dVar3 == InvalidItem) {
        dVar3 = d_item::getItemFromLifeBallTableWithoutEmono(param_2);
      }
      param_5 = 0xffffffff;
    }
    else {
      if (param_5 != 0) {
        dVar3 = d_item::getItemFromLifeBallTableWithoutEmono(param_2);
      }
      param_5 = 0xffffffff;
    }
    goto LAB_8002738c;
  }
  if (((param_5 != 0x1f) && (param_5 != 0xffffffff)) && (param_5 != 0xff)) {
    if (((param_5 == 0x1f) || (param_5 == 0xffffffff)) || (param_5 == 0xff)) goto LAB_8002738c;
    if (dVar3 == BlueChuJelly) {
      iVar2 = dSv_memBit_c::isSwitch
                        ((dSv_memBit_c *)
                         (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mMemory + 0xe),param_5);
    }
    else {
      iVar2 = dSv_info_c::isItem(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,param_5,
                                 (int)(char)param_3);
    }
    if (iVar2 == 0) goto LAB_8002738c;
  }
  param_5 = 0xffffffff;
  dVar3 = d_item::getItemFromLifeBallTableWithoutEmono(param_2);
LAB_8002738c:
  fopAcM_fastCreateItem
            (param_1,(uint)dVar3,param_3,param_4,(cXyz *)0x0,(double)0_0,(double)0_0,(double)_6_0,
             param_5,stealItem_CB);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x8002775c) */
/* __stdcall fopAcM_createItemFromEnemyTable(unsigned short,
                                             int,
                                             int,
                                             cXyz *,
                                             csXyz *) */

void fopAcM_createItemFromEnemyTable
               (uint tableIndex,uint itemPickupFlag,int roomNo,cXyz *pos,csXyz *rot)

{
  uint uVar1;
  uint isLimited;
  int iVar2;
  uint itemIdx;
  undefined4 uVar3;
  undefined8 in_f31;
  double dVar4;
  float fVar5;
  cXyz local_88;
  uint itemTbl [16];
  undefined auStack8 [8];
  int tblIdx;
  dItem_data__ItemNo itemNo;
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar5 = SComponent::cM_rndF(15_99);
  tblIdx = (int)fVar5;
  local_88.x = ::cXyz::Zero.x;
  local_88.y = ::cXyz::Zero.y;
  local_88.z = ::cXyz::Zero.z;
  itemIdx = tableIndex & 0xffff;
  uVar1 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM0,itemIdx)
  ;
  itemTbl[0] = uVar1 & 0xff;
  uVar1 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM1,itemIdx)
  ;
  itemTbl[1] = uVar1 & 0xff;
  uVar1 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM2,itemIdx)
  ;
  itemTbl[2] = uVar1 & 0xff;
  uVar1 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM3,itemIdx)
  ;
  itemTbl[3] = uVar1 & 0xff;
  uVar1 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM4,itemIdx)
  ;
  itemTbl[4] = uVar1 & 0xff;
  uVar1 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM5,itemIdx)
  ;
  itemTbl[5] = uVar1 & 0xff;
  uVar1 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM6,itemIdx)
  ;
  itemTbl[6] = uVar1 & 0xff;
  uVar1 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM7,itemIdx)
  ;
  itemTbl[7] = uVar1 & 0xff;
  uVar1 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM8,itemIdx)
  ;
  itemTbl[8] = uVar1 & 0xff;
  uVar1 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM9,itemIdx)
  ;
  itemTbl[9] = uVar1 & 0xff;
  uVar1 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM10,itemIdx
                     );
  itemTbl[10] = uVar1 & 0xff;
  uVar1 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM11,itemIdx
                     );
  itemTbl[11] = uVar1 & 0xff;
  uVar1 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM12,itemIdx
                     );
  itemTbl[12] = uVar1 & 0xff;
  uVar1 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM13,itemIdx
                     );
  itemTbl[13] = uVar1 & 0xff;
  uVar1 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM14,itemIdx
                     );
  itemTbl[14] = uVar1 & 0xff;
  itemIdx = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                        d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM15,
                        itemIdx);
  itemTbl[15] = itemIdx & 0xff;
  itemIdx = itemTbl[tblIdx];
  itemNo = (dItem_data__ItemNo)itemIdx;
  isLimited = d_item::isLimitedItem(itemNo);
  if (isLimited == 0) {
    iVar2 = d_item::isNonSavedEmono(itemNo);
    if (iVar2 == 0) {
      itemPickupFlag = 0xffffffff;
    }
    else {
      if (itemPickupFlag != 0) {
        itemIdx = d_item::getItemFromLifeBallTableWithoutEmono(tableIndex & 0xffff);
        itemTbl[tblIdx] = itemIdx & 0xff;
      }
      itemPickupFlag = 0xffffffff;
    }
    goto LAB_80027708;
  }
  if (((itemPickupFlag != 0x1f) && (itemPickupFlag != 0xffffffff)) && (itemPickupFlag != 0xff)) {
    if (((itemPickupFlag == 0x1f) || (itemPickupFlag == 0xffffffff)) || (itemPickupFlag == 0xff))
    goto LAB_80027708;
    if ((itemIdx & 0xff) == 0x4b) {
      iVar2 = dSv_memBit_c::isSwitch
                        ((dSv_memBit_c *)
                         (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mMemory + 0xe),
                         itemPickupFlag);
    }
    else {
      iVar2 = dSv_info_c::isItem(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,itemPickupFlag,
                                 (int)(char)roomNo);
    }
    if (iVar2 == 0) goto LAB_80027708;
  }
  itemPickupFlag = 0xffffffff;
  itemTbl[tblIdx] = 3;
LAB_80027708:
  itemIdx = d_item::getItemNoByLife((dItem_data__ItemNo)itemTbl[tblIdx]);
  itemTbl[tblIdx] = itemIdx & 0xff;
  fVar5 = SComponent::cM_rndFX(10_0);
  dVar4 = (double)(50_0 + fVar5);
  fVar5 = SComponent::cM_rndFX(5_0);
  fopAcM_fastCreateItem
            (pos,itemTbl[tblIdx],roomNo,(csXyz *)0x0,&local_88,(double)fVar5,dVar4,(double)_6_0,
             itemPickupFlag,0);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __stdcall fopAcM_createIball(cXyz *,
                                int,
                                int,
                                csXyz *,
                                int) */

uint fopAcM_createIball
               (cXyz *pPos,int param_low,int roomNo,csXyz *pRot,int switchId)

{
  uint chance;
  int iVar1;
  daIball_c *this;
  uint uVar2;
  fopAc_ac_c *pfVar3;
  float random;
  
  uVar2 = param_low & 0xffff;
  chance = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_percent,uVar2);
  random = SComponent::cM_rndF(99_999);
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Cave09");
  if (((iVar1 == 0) ||
      (iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                         (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Cave10"),
      iVar1 == 0)) ||
     (this = (daIball_c *)
             MSL_C.PPCEABI.bare.H::strcmp
                       (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Cave11"),
     this == (daIball_c *)0x0)) {
    uVar2 = 0xffffffff;
  }
  else {
    if ((int)random < (int)(chance & 0xff)) {
      daIball_c::remove_old(this);
      pfVar3 = fopAcM_fastCreate(0x192,uVar2 | (switchId & 0xffU) << 0x10,pPos,roomNo,(csXyz *)0x0,
                                 (cXyz *)0x0,0xff,(undefined *)0x0,(void *)0x0);
      if (pfVar3 == (fopAc_ac_c *)0x0) {
        uVar2 = 0xffffffff;
      }
      else {
        uVar2 = (pfVar3->parent).parent.mBsPcId;
      }
    }
    else {
      fopAcM_createItemFromEnemyTable(uVar2,switchId,roomNo,pPos,pRot);
      if (uVar2 == 0) {
        uVar2 = 0xffffffff;
      }
      else {
        uVar2 = *(uint *)(uVar2 + 4);
      }
    }
  }
  return uVar2;
}


/* __stdcall fopAcM_createWarpFlower(cXyz *,
                                     csXyz *,
                                     int,
                                     unsigned char) */

void fopAcM_createWarpFlower(cXyz *param_1,csXyz *param_2,int param_3,uint param_4)

{
  fopAcM_create(0x6a,param_4 & 0xff,param_1,param_3,param_2,(cXyz *)0x0,0xff,(undefined *)0x0);
  return;
}


/* __stdcall enemySearchJugge(void *,
                              void *) */

fopAc_ac_c * enemySearchJugge(fopAc_ac_c *param_1)

{
  bool bVar1;
  
  if (((param_1 == (fopAc_ac_c *)0x0) ||
      (bVar1 = f_op_actor::fopAc_IsActor(param_1), bVar1 == false)) ||
     (param_1->mActorType != Enemy)) {
    param_1 = (fopAc_ac_c *)0x0;
  }
  return param_1;
}


/* __stdcall fopAcM_myRoomSearchEnemy(signed char) */

void fopAcM_myRoomSearchEnemy(char param_1)

{
  ulong uVar1;
  scene_class *psVar2;
  fopAc_ac_c *pfVar3;
  bool bVar5;
  uint uVar4;
  int local_18;
  
  if (param_1 < '\0') {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"f_op_actor_mng.cpp",0xe07,"roomNo >= 0");
    m_Do_printf::OSPanic("f_op_actor_mng.cpp",0xe07,"Halt");
  }
  psVar2 = f_op_scene_mng::fopScnM_SearchByID(dStage_roomControl_c::mStatus[param_1].mRoomBsPcId);
  if (psVar2 == (scene_class *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"f_op_actor_mng.cpp",0xe0a,"roomProc != 0");
    m_Do_printf::OSPanic("f_op_actor_mng.cpp",0xe0a,"Halt");
  }
  local_18 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->vtbl->
                       getGrabActorID)();
  pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_18);
  if ((pfVar3 == (fopAc_ac_c *)0x0) || (pfVar3->mActorType != Enemy)) {
    bVar5 = f_pc_base::fpcBs_Is_JustOfType(f_pc_node::g_fpcNd_type,(psVar2->parent).parent.mSubType)
    ;
    if (bVar5 == false) {
      uVar4 = 0xffffffff;
    }
    else {
      uVar4 = (psVar2->parent).mLayer.mLayerID;
    }
    f_pc_manager::fpcM_JudgeInLayer(uVar4,enemySearchJugge,0);
  }
  return;
}


/* __stdcall fopAcM_createDisappear(fopAc_ac_c *,
                                    cXyz *,
                                    unsigned char,
                                    unsigned char,
                                    unsigned char) */

uint fopAcM_createDisappear
               (int param_1,cXyz *param_2,uint param_3,uint param_4,uint param_5)

{
  fopAc_ac_c *pfVar1;
  uint uVar2;
  
  pfVar1 = fopAcM_fastCreate(0x193,param_4 & 0xff | (param_5 & 0xff) << 0x10 | (param_3 & 0xff) << 8
                             ,param_2,(int)*(char *)(param_1 + 0x20a),(csXyz *)(param_1 + 0x204),
                             (cXyz *)0x0,0xff,(undefined *)0x0,(void *)0x0);
  if (pfVar1 == (fopAc_ac_c *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    pfVar1->mItemTableIdx = *(int *)(param_1 + 0x288);
    uVar2 = (pfVar1->parent).parent.mBsPcId;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Removing unreachable block (ram,0x80027e08) */
/* __stdcall fopAcM_getGroundAngle(fopAc_ac_c *,
                                   csXyz *) */

bool fopAcM_getGroundAngle(fopAc_ac_c *param_1,csXyz *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  short unaff_r23;
  short unaff_r24;
  cBgS_PolyPassChk *pcVar5;
  bool bVar6;
  undefined4 uVar7;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  cBgS_GndChk local_9c;
  cBgS_PolyPassChk local_5c;
  undefined local_50 [20];
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  ::cBgS_GndChk::cBgS_GndChk(&local_9c);
  pcVar5 = &local_5c;
  local_5c.mbObjThrough = 0;
  local_5c.mbCamThrough = 0;
  local_5c.mbLinkThrough = 0;
  local_5c.mbArrowsAndLightThrough = 0;
  local_5c.mbBombThrough = 0;
  local_5c.mbBoomerangThrough = 0;
  local_5c.mbHookshotThrough = 0;
  local_50._4_4_ = 1;
  local_9c.parent.vtbl = &::dBgS_GndChk::__vt;
  local_9c.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371f08;
  local_5c.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_50._0_4_ = &PTR_80371f20;
  local_9c.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar5;
  if (pcVar5 != (cBgS_PolyPassChk *)0x0) {
    local_9c.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_50;
  }
  fVar1 = (param_1->mCurrent).mPos.x;
  fVar2 = (param_1->mCurrent).mPos.z;
  local_9c.mPos.y = (param_1->mCurrent).mPos.y + 50_0;
  local_9c.parent.mpPolyPassChk = pcVar5;
  local_9c.mPos.x = fVar1;
  local_9c.mPos.z = fVar2;
  dVar8 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_9c);
  fVar3 = (float)dVar8;
  if (_5764 == (float)dVar8) {
    bVar6 = false;
  }
  else {
    local_9c.mPos.y = 50_0 + (float)dVar8;
    local_9c.mPos.z = 10_0 + fVar2;
    dVar9 = (double)local_9c.mPos.z;
    local_9c.mPos.x = fVar1;
    dVar8 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_9c);
    bVar6 = (double)_5764 != dVar8;
    if (bVar6) {
      iVar4 = SComponent::cM_atan2s((float)(dVar8 - (double)fVar3),(float)(dVar9 - (double)fVar2));
      unaff_r24 = -(short)iVar4;
    }
    local_9c.mPos.x = 10_0 + fVar1;
    dVar9 = (double)local_9c.mPos.x;
    local_9c.mPos.y = 50_0 + fVar3;
    local_9c.mPos.z = fVar2;
    dVar8 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_9c);
    if ((double)_5764 == dVar8) {
      bVar6 = false;
    }
    else {
      iVar4 = SComponent::cM_atan2s((float)(dVar8 - (double)fVar3),(float)(dVar9 - (double)fVar1));
      unaff_r23 = (short)iVar4;
    }
  }
  if (bVar6 != false) {
    SComponent::cLib_addCalcAngleS(&param_2->x,unaff_r24,4,0x200,0x80);
    SComponent::cLib_addCalcAngleS(&param_2->z,unaff_r23,4,0x200,0x80);
  }
  local_5c.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_50._0_4_ = &PTR_80371f20;
  if (pcVar5 != (cBgS_PolyPassChk *)0x0) {
    local_5c.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_50._0_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x50) &&
       (local_50._0_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x50)) {
      local_50._0_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar5 != (cBgS_PolyPassChk *)0x0) &&
       (local_5c.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar5 != (cBgS_PolyPassChk *)0x0)) {
      local_5c.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_9c.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_9c.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_9c.parent);
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return bVar6;
}


/* __stdcall fopAcM_setCarryNow(fopAc_ac_c *,
                                int) */

void fopAcM_setCarryNow(fopAc_ac_c *param_1,int param_2)

{
  param_1->mStatus = param_1->mStatus | IsBeingCarried;
  if (param_2 != 0) {
    fopAcM_setStageLayer(param_1);
  }
  return;
}


/* __stdcall fopAcM_cancelCarryNow(fopAc_ac_c *) */

void fopAcM_cancelCarryNow(fopAc_ac_c *param_1)

{
  if ((param_1->mStatus & IsBeingCarried) != 0) {
    param_1->mStatus = param_1->mStatus & ~IsBeingCarried;
    fopAcM_setRoomLayer(param_1,(int)(char)(param_1->mCurrent).mRoomNo);
    (param_1->mCollisionRot).z = 0;
    if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode != 0) &&
       (param_1->mActorType != Enemy)) {
      param_1->mStatus = param_1->mStatus | 0x800;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x800281b8) */
/* __stdcall fopAcM_viewCutoffCheck(fopAc_ac_c *,
                                    float) */

undefined fopAcM_viewCutoffCheck(double param_1,fopAc_ac_c *param_2)

{
  camera_class *pcVar1;
  undefined uVar2;
  cBgS_PolyPassChk *pcVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f31;
  float fVar7;
  cXyz local_c4;
  cXyz local_b8;
  dBgS_LinChk local_ac;
  undefined auStack8 [8];
  
  pcVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if ((double)0_0 < param_1) {
    ::cXyz::operator__(&local_c4,
                       &(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mEyePos,
                       &param_2->mEyePos);
    local_b8.x = local_c4.x;
    local_b8.y = local_c4.y;
    local_b8.z = local_c4.z;
    fVar7 = mtx::PSVECSquareMag(&local_b8);
    dVar6 = (double)fVar7;
    if ((double)0_0 < dVar6) {
      dVar5 = 1.0 / SQRT(dVar6);
      dVar5 = _4524 * dVar5 * (_4525 - dVar6 * dVar5 * dVar5);
      dVar5 = _4524 * dVar5 * (_4525 - dVar6 * dVar5 * dVar5);
      dVar6 = (double)(float)(dVar6 * _4524 * dVar5 * (_4525 - dVar6 * dVar5 * dVar5));
    }
    if (param_1 < dVar6) {
      local_ac.parent.parent.mpPolyPassChk = (cBgS_PolyPassChk *)0x0;
      local_ac.parent.parent.mpGrpPassChk = (cBgS_GrpPassChk *)0x0;
      local_ac.parent.parent.mbExcludeSameProcID = true;
      local_ac.parent.mPolyInfo.mTriIdx = -1;
      local_ac.parent.mPolyInfo.mBgIndex = 0x100;
      local_ac.parent.mPolyInfo.mpBgW = (cBgW *)0x0;
      local_ac.parent.mPolyInfo.mProcID = -1;
      local_ac.parent.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
      local_ac.parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371fbc;
      local_ac.parent.mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
      ::cBgS_LinChk::ct(&local_ac.parent);
      pcVar3 = (cBgS_PolyPassChk *)&local_ac.mPolyPassChk;
      local_ac.mPolyPassChk.parent.mbObjThrough = 0;
      local_ac.mPolyPassChk.parent.mbCamThrough = 0;
      local_ac.mPolyPassChk.parent.mbLinkThrough = 0;
      local_ac.mPolyPassChk.parent.mbArrowsAndLightThrough = 0;
      local_ac.mPolyPassChk.parent.mbBombThrough = 0;
      local_ac.mPolyPassChk.parent.mbBoomerangThrough = 0;
      local_ac.mPolyPassChk.parent.mbHookshotThrough = 0;
      local_ac.mGrpPassChk.parent.mAttr = 1;
      local_ac.parent.parent.vtbl = (cBgS_Chk__vtbl *)&::dBgS_LinChk::__vt;
      local_ac.parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_80371f38;
      local_ac.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f44;
      local_ac.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f50;
      local_ac.parent.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar3;
      if (pcVar3 != (cBgS_PolyPassChk *)0x0) {
        local_ac.parent.parent.mpGrpPassChk = (cBgS_GrpPassChk *)&local_ac.mGrpPassChk;
      }
      local_ac.parent.parent.mpPolyPassChk = pcVar3;
      ::dBgS_LinChk::Set(&local_ac,&pcVar1->mEyePos,&param_2->mEyePos,param_2);
      uVar2 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_ac.parent);
      local_ac.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f44;
      local_ac.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f50;
      if (pcVar3 != (cBgS_PolyPassChk *)0x0) {
        local_ac.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
        local_ac.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
        if (((undefined *)register0x00000004 != &DAT_00000048) &&
           (local_ac.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
           (undefined *)register0x00000004 != &DAT_00000048)) {
          local_ac.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
        }
        if ((pcVar3 != (cBgS_PolyPassChk *)0x0) &&
           (local_ac.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
           pcVar3 != (cBgS_PolyPassChk *)0x0)) {
          local_ac.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
        }
      }
      local_ac.parent.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
      local_ac.parent.mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
      local_ac.parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
      cBgS_Chk::_cBgS_Chk((cBgS_Chk *)&local_ac);
      goto LAB_800281b8;
    }
  }
  uVar2 = 0;
LAB_800281b8:
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return uVar2;
}


/* WARNING: Removing unreachable block (ram,0x800282d8) */
/* __stdcall fopAcM_otoCheck(fopAc_ac_c *,
                             float) */

float fopAcM_otoCheck(double param_1,int param_2)

{
  float fVar1;
  cXyz *this;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f31;
  cXyz local_34;
  cXyz local_28;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  this = (cXyz *)d_kankyo::dKy_Sound_get();
  if (this[1].z != -NAN) {
    if (param_2 == 0) {
      fVar1 = -NAN;
    }
    else {
      fVar1 = *(float *)(param_2 + 4);
    }
    if (this[1].z != fVar1) {
      ::cXyz::operator__(&local_34,this,(cXyz *)(param_2 + 0x1f8));
      local_28.x = local_34.x;
      local_28.y = local_34.y;
      local_28.z = local_34.z;
      fVar1 = mtx::PSVECSquareMag(&local_28);
      dVar4 = (double)fVar1;
      if ((double)0_0 < dVar4) {
        dVar3 = 1.0 / SQRT(dVar4);
        dVar3 = _4524 * dVar3 * (_4525 - dVar4 * dVar3 * dVar3);
        dVar3 = _4524 * dVar3 * (_4525 - dVar4 * dVar3 * dVar3);
        dVar4 = (double)(float)(dVar4 * _4524 * dVar3 * (_4525 - dVar4 * dVar3 * dVar3));
      }
      if (dVar4 < param_1) {
        fVar1 = this[1].x;
        goto LAB_800282d8;
      }
    }
  }
  fVar1 = 0.0;
LAB_800282d8:
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return fVar1;
}


/* __stdcall fopAcM_getProcNameString(fopAc_ac_c *) */

char * fopAcM_getProcNameString(fopAc_ac_c *param_1)

{
  char *pcVar1;
  
  pcVar1 = d_stage::dStage_getName2((param_1->parent).parent.mBsTypeId,param_1->mSubtype);
  if (pcVar1 == (char *)0x0) {
    pcVar1 = "UNKOWN";
  }
  return pcVar1;
}


/* __stdcall fopAcM_findObjectCB(fopAc_ac_c *,
                                 void *) */

int fopAcM_findObjectCB(fopAc_ac_c *param_1,void *(*param_2) [3])

{
  ulong uVar1;
  dStage__ObjectNameTable *pdVar2;
  
  if (param_2 == (void *(*) [3])0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"f_op_actor_mng.cpp",0xfff,"Prm");
    m_Do_printf::OSPanic("f_op_actor_mng.cpp",0xfff,"Halt");
  }
  pdVar2 = d_stage::dStage_searchName((char *)(*param_2)[0]);
  if (pdVar2 == (dStage__ObjectNameTable *)0x0) {
    param_1 = (fopAc_ac_c *)0x0;
  }
  else {
    if (((pdVar2->mProcName != (param_1->parent).parent.mBsTypeId) ||
        (pdVar2->mSubtype != param_1->mSubtype)) ||
       (((*param_2)[1] != (void *)0x0 &&
        ((*param_2)[2] != (void *)((uint)(*param_2)[1] & (param_1->parent).parent.mParameters))))) {
      param_1 = (fopAc_ac_c *)0x0;
    }
  }
  return (int)param_1;
}


/* __stdcall fopAcM_searchFromName(char *,
                                   unsigned long,
                                   unsigned long) */

void fopAcM_searchFromName
               (char *actorName,ulong paramMaskToCheck,ulong desiredParamValue)

{
  char *local_18;
  ulong local_14;
  ulong local_10;
  
  local_18 = actorName;
  local_14 = paramMaskToCheck;
  local_10 = desiredParamValue;
  f_op_actor_iter::fopAcIt_Judge(fopAcM_findObjectCB,&local_18);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fopAcM_getWaterY(cXyz const *,
                              float *) */

uint fopAcM_getWaterY(cXyz *param_1,float *param_2)

{
  char cVar2;
  uint uVar1;
  uint uVar3;
  double dVar4;
  
  if (init_6115 == '\0') {
    ::dBgS_WtrChk::dBgS_WtrChk(&water_check_6113);
    Runtime.PPCEABI.H::__register_global_object();
    init_6115 = '\x01';
  }
  *param_2 = _5764;
  water_check_6113.parent.mStartPos.x = param_1->x;
  water_check_6113.parent.mStartPos.y = param_1->y - _6137;
  water_check_6113.parent.mStartPos.z = param_1->z;
  water_check_6113.parent.mEndPosY = _6138 + water_check_6113.parent.mStartPos.y;
  cVar2 = dBgS::SplGrpChk(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&water_check_6113.parent);
  if (cVar2 != '\0') {
    *param_2 = water_check_6113.parent.mHeight;
  }
  uVar3 = (uint)(cVar2 != '\0');
  uVar1 = d_a_sea::daSea_ChkArea(param_1->x,param_1->z);
  if ((uVar1 & 0xff) != 0) {
    dVar4 = (double)d_a_sea::daSea_calcWave((double)param_1->x,(double)param_1->z);
    if ((double)*param_2 < dVar4) {
      *param_2 = (float)dVar4;
    }
    uVar3 = 1;
  }
  return uVar3;
}

}

/* __thiscall dBgS_WtrChk::~dBgS_WtrChk(void) */

void __thiscall dBgS_WtrChk::_dBgS_WtrChk(dBgS_WtrChk *this)

{
  short in_r4;
  
  if (this != (dBgS_WtrChk *)0x0) {
    (this->parent).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&__vt;
    (this->parent).mChk.vtbl = (cBgS_Chk__vtbl *)&PTR_80372074;
    (this->parent).mDChk.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80372080;
    (this->parent).mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_8037208c;
    if (this != (dBgS_WtrChk *)0x0) {
      (this->parent).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&dBgS_SplGrpChk::__vt;
      (this->parent).mChk.vtbl = (cBgS_Chk__vtbl *)&PTR_80372044;
      (this->parent).mDChk.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80372050;
      (this->parent).mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_8037205c;
      if (this != (dBgS_WtrChk *)0xffffffdc) {
        (this->parent).mDChk.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
        (this->parent).mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
        if (this != (dBgS_WtrChk *)0xffffffd0) {
          (this->parent).mDChk.mGrpPassChk.parent.vtbl =
               (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt;
          if (this != (dBgS_WtrChk *)0xffffffd0) {
            (this->parent).mDChk.mGrpPassChk.parent.vtbl =
                 (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
          }
        }
        if ((this != (dBgS_WtrChk *)0xffffffdc) &&
           ((this->parent).mDChk.mPolyPassChk.parent.vtbl =
                 (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
           this != (dBgS_WtrChk *)0xffffffdc)) {
          (this->parent).mDChk.mPolyPassChk.parent.vtbl =
               (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
        }
      }
      cBgS_Chk::_cBgS_Chk(&(this->parent).mChk);
      if (this != (dBgS_WtrChk *)0x0) {
        (this->parent).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace f_op_actor_mng {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall fopAcM_setGbaName(fopAc_ac_c *,
                               unsigned char,
                               unsigned char,
                               unsigned char) */

void fopAcM_setGbaName
               (fopAc_ac_c *this,dItem_data__ItemNo itemNo,GbaNames gbaNameIfNotHaveItem,
               GbaNames gbaNameIfHaveItem)

{
  bool bVar1;
  
  bVar1 = d_com_inf_game::dComIfGs_checkGetItem(itemNo);
  if (((bVar1 == false) &&
      ((itemNo != HerosBow ||
       ((bVar1 = d_com_inf_game::dComIfGs_checkGetItem(FireAndIceArrows), bVar1 == false &&
        (bVar1 = d_com_inf_game::dComIfGs_checkGetItem(LightArrow), bVar1 == false)))))) &&
     ((itemNo != FireAndIceArrows ||
      (bVar1 = d_com_inf_game::dComIfGs_checkGetItem(LightArrow), bVar1 == false)))) {
    this->mGbaName = gbaNameIfNotHaveItem;
    return;
  }
  this->mGbaName = gbaNameIfHaveItem;
  return;
}


/* __stdcall fpoAcM_absolutePos(fopAc_ac_c *,
                                cXyz *,
                                cXyz *) */

void fpoAcM_absolutePos(fopAc_ac_c *param_1,cXyz *param_2,cXyz *param_3)

{
  int iVar1;
  
  param_3->x = (param_1->mCurrent).mPos.x;
  param_3->y = (param_1->mCurrent).mPos.y;
  param_3->z = (param_1->mCurrent).mPos.z;
  iVar1 = (int)((int)(param_1->mCollisionRot).y & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  param_3->x = param_3->x +
               param_2->z * JKernel::JMath::jmaSinTable[iVar1] +
               param_2->x * JKernel::JMath::jmaCosTable[iVar1];
  param_3->y = param_3->y + param_2->y;
  iVar1 = (int)((int)(param_1->mCollisionRot).y & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  param_3->z = param_3->z +
               (param_2->z * JKernel::JMath::jmaCosTable[iVar1] -
               param_2->x * JKernel::JMath::jmaSinTable[iVar1]);
  return;
}


/* __stdcall fpoAcM_relativePos(fopAc_ac_c *,
                                cXyz *,
                                cXyz *) */

void fpoAcM_relativePos(fopAc_ac_c *param_1,cXyz *param_2,cXyz *param_3)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  cXyz local_28;
  
  sVar1 = (param_1->mCollisionRot).y;
  ::cXyz::operator__(&local_28,param_2,&(param_1->mCurrent).mPos);
  uVar2 = (int)-sVar1 & 0xffff;
  iVar3 = (int)uVar2 >> (JKernel::JMath::jmaSinShift & 0x3f);
  param_3->x = local_28.z * JKernel::JMath::jmaSinTable[iVar3] +
               local_28.x * JKernel::JMath::jmaCosTable[iVar3];
  param_3->y = local_28.y;
  iVar3 = (int)uVar2 >> (JKernel::JMath::jmaSinShift & 0x3f);
  param_3->z = local_28.z * JKernel::JMath::jmaCosTable[iVar3] -
               local_28.x * JKernel::JMath::jmaSinTable[iVar3];
  return;
}

}

/* __thiscall dBgS_SplGrpChk::~dBgS_SplGrpChk(void) */

void __thiscall dBgS_SplGrpChk::_dBgS_SplGrpChk(dBgS_SplGrpChk *this)

{
  short in_r4;
  
  if (this != (dBgS_SplGrpChk *)0x0) {
    (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&__vt;
    (this->mChk).vtbl = (cBgS_Chk__vtbl *)&PTR_80372044;
    (this->mDChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80372050;
    (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_8037205c;
    if (this != (dBgS_SplGrpChk *)0xffffffdc) {
      (this->mDChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
      if (this != (dBgS_SplGrpChk *)0xffffffd0) {
        (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt;
        if (this != (dBgS_SplGrpChk *)0xffffffd0) {
          (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
        }
      }
      if ((this != (dBgS_SplGrpChk *)0xffffffdc) &&
         ((this->mDChk).mPolyPassChk.parent.vtbl =
               (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         this != (dBgS_SplGrpChk *)0xffffffdc)) {
        (this->mDChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt
        ;
      }
    }
    cBgS_Chk::_cBgS_Chk(&this->mChk);
    if (this != (dBgS_SplGrpChk *)0x0) {
      (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace f_op_actor_mng {

void __sinit_f_op_actor_mng_cpp(void)

{
  fopAc_cullSizeSphere local_388;
  cXyz local_378;
  fopAc_cullSizeSphere local_36c;
  cXyz local_35c;
  fopAc_cullSizeSphere local_350;
  cXyz local_340;
  fopAc_cullSizeSphere local_334;
  cXyz local_324;
  fopAc_cullSizeSphere local_318;
  cXyz local_308;
  fopAc_cullSizeSphere local_2fc;
  cXyz local_2ec;
  fopAc_cullSizeSphere local_2e0;
  cXyz local_2d0;
  fopAc_cullSizeSphere local_2c4;
  cXyz local_2b4;
  cXyz local_2a8;
  cXyz local_29c;
  cXyz local_290;
  cXyz local_284;
  cXyz local_278;
  cXyz local_26c;
  cXyz local_260;
  cXyz local_254;
  cXyz local_248;
  cXyz local_23c;
  cXyz local_230;
  cXyz local_224;
  cXyz local_218;
  cXyz local_20c;
  cXyz local_200;
  cXyz local_1f4;
  cXyz local_1e8;
  cXyz local_1dc;
  cXyz local_1d0;
  cXyz local_1c4;
  cXyz local_1b8;
  cXyz local_1ac;
  cXyz local_1a0;
  cXyz local_194;
  cXyz local_188;
  cXyz local_17c;
  cXyz local_170;
  cXyz local_164;
  fopAc_cullSizeBox fStack344;
  fopAc_cullSizeBox fStack320;
  fopAc_cullSizeBox fStack296;
  fopAc_cullSizeBox fStack272;
  fopAc_cullSizeBox fStack248;
  fopAc_cullSizeBox fStack224;
  fopAc_cullSizeBox fStack200;
  fopAc_cullSizeBox fStack176;
  fopAc_cullSizeBox fStack152;
  fopAc_cullSizeBox fStack128;
  fopAc_cullSizeBox fStack104;
  fopAc_cullSizeBox fStack80;
  fopAc_cullSizeBox fStack56;
  fopAc_cullSizeBox fStack32;
  
  Runtime.PPCEABI.H::__register_global_object(&l_hio,::l_HIO::_l_HIO,&_4034);
  local_164.x = _5233;
  local_164.y = 0_0;
  local_164.z = _5233;
  local_170.x = _4688;
  local_170.y = _6546;
  local_170.z = _4688;
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(&fStack32,&local_164,&local_170);
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(l_cullSizeBox,&fStack32);
  Runtime.PPCEABI.H::__register_global_object();
  local_17c.x = _25_0;
  local_17c.y = 0_0;
  local_17c.z = _25_0;
  local_188.x = 25_0;
  local_188.y = 50_0;
  local_188.z = 25_0;
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(&fStack56,&local_17c,&local_188);
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(l_cullSizeBox + 1,&fStack56);
  Runtime.PPCEABI.H::__register_global_object();
  local_194.x = _6549;
  local_194.y = 0_0;
  local_194.z = _6549;
  local_1a0.x = 50_0;
  local_1a0.y = _6550;
  local_1a0.z = 50_0;
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(&fStack80,&local_194,&local_1a0);
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(l_cullSizeBox + 2,&fStack80);
  Runtime.PPCEABI.H::__register_global_object();
  local_1ac.x = _6551;
  local_1ac.y = 0_0;
  local_1ac.z = _6551;
  local_1b8.x = _6552;
  local_1b8.y = 150_0;
  local_1b8.z = _6552;
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(&fStack104,&local_1ac,&local_1b8);
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(l_cullSizeBox + 3,&fStack104);
  Runtime.PPCEABI.H::__register_global_object();
  local_1c4.x = _4689;
  local_1c4.y = 0_0;
  local_1c4.z = _4689;
  local_1d0.x = _6550;
  local_1d0.y = _6554;
  local_1d0.z = _6550;
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(&fStack128,&local_1c4,&local_1d0);
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(l_cullSizeBox + 4,&fStack128);
  Runtime.PPCEABI.H::__register_global_object();
  local_1dc.x = _6555;
  local_1dc.y = 0_0;
  local_1dc.z = _6555;
  local_1e8.x = _6546;
  local_1e8.y = 250_0;
  local_1e8.z = _6546;
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(&fStack152,&local_1dc,&local_1e8);
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(l_cullSizeBox + 5,&fStack152);
  Runtime.PPCEABI.H::__register_global_object();
  local_1f4.x = _6557;
  local_1f4.y = 0_0;
  local_1f4.z = _6557;
  local_200.x = 150_0;
  local_200.y = 300_0;
  local_200.z = 150_0;
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(&fStack176,&local_1f4,&local_200);
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(l_cullSizeBox + 6,&fStack176);
  Runtime.PPCEABI.H::__register_global_object();
  local_20c.x = _6559;
  local_20c.y = 0_0;
  local_20c.z = _6559;
  local_218.x = 200_0;
  local_218.y = 400_0;
  local_218.z = 200_0;
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(&fStack200,&local_20c,&local_218);
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(l_cullSizeBox + 7,&fStack200);
  Runtime.PPCEABI.H::__register_global_object();
  local_224.x = _6561;
  local_224.y = 0_0;
  local_224.z = _6561;
  local_230.x = _6562;
  local_230.y = _6563;
  local_230.z = _6562;
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(&fStack224,&local_224,&local_230);
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(l_cullSizeBox + 8,&fStack224);
  Runtime.PPCEABI.H::__register_global_object();
  local_23c.x = _6564;
  local_23c.y = 0_0;
  local_23c.z = _6549;
  local_248.x = 250_0;
  local_248.y = _6565;
  local_248.z = 50_0;
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(&fStack248,&local_23c,&local_248);
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(l_cullSizeBox + 9,&fStack248);
  Runtime.PPCEABI.H::__register_global_object();
  local_254.x = _6566;
  local_254.y = 0_0;
  local_254.z = _6567;
  local_260.x = _4688;
  local_260.y = _6568;
  local_260.z = 150_0;
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(&fStack272,&local_254,&local_260);
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(l_cullSizeBox + 10,&fStack272);
  Runtime.PPCEABI.H::__register_global_object();
  local_26c.x = _6551;
  local_26c.y = 0_0;
  local_26c.z = _6551;
  local_278.x = _6552;
  local_278.y = _6569;
  local_278.z = _6552;
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(&fStack296,&local_26c,&local_278);
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(l_cullSizeBox + 0xb,&fStack296);
  Runtime.PPCEABI.H::__register_global_object();
  local_284.x = _6570;
  local_284.y = _4689;
  local_284.z = _6571;
  local_290.x = _6572;
  local_290.y = _6573;
  local_290.z = _6550;
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(&fStack320,&local_284,&local_290);
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(l_cullSizeBox + 0xc,&fStack320);
  Runtime.PPCEABI.H::__register_global_object();
  local_29c.x = _6566;
  local_29c.y = _6567;
  local_29c.z = _6566;
  local_2a8.x = _6574;
  local_2a8.y = _6575;
  local_2a8.z = _6574;
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(&fStack344,&local_29c,&local_2a8);
  ::fopAc_cullSizeBox::fopAc_cullSizeBox(l_cullSizeBox + 0xd,&fStack344);
  Runtime.PPCEABI.H::__register_global_object();
  local_2b4.x = 0_0;
  local_2b4.y = 0_0;
  local_2b4.z = 0_0;
  ::fopAc_cullSizeSphere::fopAc_cullSizeSphere(&local_2c4,&local_2b4,_6576);
  l_cullSizeSphere[0].mCenter.x = local_2c4.mCenter.x;
  l_cullSizeSphere[0].mCenter.y = local_2c4.mCenter.y;
  l_cullSizeSphere[0].mCenter.z = local_2c4.mCenter.z;
  l_cullSizeSphere[0].mRadius = local_2c4.mRadius;
  Runtime.PPCEABI.H::__register_global_object
            (l_cullSizeSphere,::fopAc_cullSizeSphere::_fopAc_cullSizeSphere,&_4718);
  local_2d0.x = 0_0;
  local_2d0.y = 0_0;
  local_2d0.z = 0_0;
  ::fopAc_cullSizeSphere::fopAc_cullSizeSphere(&local_2e0,&local_2d0,50_0);
  l_cullSizeSphere[1].mCenter.x = local_2e0.mCenter.x;
  l_cullSizeSphere[1].mCenter.y = local_2e0.mCenter.y;
  l_cullSizeSphere[1].mCenter.z = local_2e0.mCenter.z;
  l_cullSizeSphere[1].mRadius = local_2e0.mRadius;
  Runtime.PPCEABI.H::__register_global_object
            (0x803b9cd8,::fopAc_cullSizeSphere::_fopAc_cullSizeSphere,&_4719);
  local_2ec.x = 0_0;
  local_2ec.y = 0_0;
  local_2ec.z = 0_0;
  ::fopAc_cullSizeSphere::fopAc_cullSizeSphere(&local_2fc,&local_2ec,_6550);
  l_cullSizeSphere[2].mCenter.x = local_2fc.mCenter.x;
  l_cullSizeSphere[2].mCenter.y = local_2fc.mCenter.y;
  l_cullSizeSphere[2].mCenter.z = local_2fc.mCenter.z;
  l_cullSizeSphere[2].mRadius = local_2fc.mRadius;
  Runtime.PPCEABI.H::__register_global_object
            (0x803b9ce8,::fopAc_cullSizeSphere::_fopAc_cullSizeSphere,&_4720);
  local_308.x = 0_0;
  local_308.y = 0_0;
  local_308.z = 0_0;
  ::fopAc_cullSizeSphere::fopAc_cullSizeSphere(&local_318,&local_308,150_0);
  l_cullSizeSphere[3].mCenter.x = local_318.mCenter.x;
  l_cullSizeSphere[3].mCenter.y = local_318.mCenter.y;
  l_cullSizeSphere[3].mCenter.z = local_318.mCenter.z;
  l_cullSizeSphere[3].mRadius = local_318.mRadius;
  Runtime.PPCEABI.H::__register_global_object
            (0x803b9cf8,::fopAc_cullSizeSphere::_fopAc_cullSizeSphere,&_4721);
  local_324.x = 0_0;
  local_324.y = 0_0;
  local_324.z = 0_0;
  ::fopAc_cullSizeSphere::fopAc_cullSizeSphere(&local_334,&local_324,200_0);
  l_cullSizeSphere[4].mCenter.x = local_334.mCenter.x;
  l_cullSizeSphere[4].mCenter.y = local_334.mCenter.y;
  l_cullSizeSphere[4].mCenter.z = local_334.mCenter.z;
  l_cullSizeSphere[4].mRadius = local_334.mRadius;
  Runtime.PPCEABI.H::__register_global_object
            (0x803b9d08,::fopAc_cullSizeSphere::_fopAc_cullSizeSphere,&_4722);
  local_340.x = 0_0;
  local_340.y = 0_0;
  local_340.z = 0_0;
  ::fopAc_cullSizeSphere::fopAc_cullSizeSphere(&local_350,&local_340,250_0);
  l_cullSizeSphere[5].mCenter.x = local_350.mCenter.x;
  l_cullSizeSphere[5].mCenter.y = local_350.mCenter.y;
  l_cullSizeSphere[5].mCenter.z = local_350.mCenter.z;
  l_cullSizeSphere[5].mRadius = local_350.mRadius;
  Runtime.PPCEABI.H::__register_global_object
            (0x803b9d18,::fopAc_cullSizeSphere::_fopAc_cullSizeSphere,&_4723);
  local_35c.x = 0_0;
  local_35c.y = 0_0;
  local_35c.z = 0_0;
  ::fopAc_cullSizeSphere::fopAc_cullSizeSphere(&local_36c,&local_35c,300_0);
  l_cullSizeSphere[6].mCenter.x = local_36c.mCenter.x;
  l_cullSizeSphere[6].mCenter.y = local_36c.mCenter.y;
  l_cullSizeSphere[6].mCenter.z = local_36c.mCenter.z;
  l_cullSizeSphere[6].mRadius = local_36c.mRadius;
  Runtime.PPCEABI.H::__register_global_object
            (0x803b9d28,::fopAc_cullSizeSphere::_fopAc_cullSizeSphere,&_4724);
  local_378.x = 0_0;
  local_378.y = 0_0;
  local_378.z = 0_0;
  ::fopAc_cullSizeSphere::fopAc_cullSizeSphere(&local_388,&local_378,400_0);
  l_cullSizeSphere[7].mCenter.x = local_388.mCenter.x;
  l_cullSizeSphere[7].mCenter.y = local_388.mCenter.y;
  l_cullSizeSphere[7].mCenter.z = local_388.mCenter.z;
  l_cullSizeSphere[7].mRadius = local_388.mRadius;
  Runtime.PPCEABI.H::__register_global_object
            (0x803b9d38,::fopAc_cullSizeSphere::_fopAc_cullSizeSphere,&_4725);
  return;
}

}

/* __thiscall fopAc_cullSizeSphere::fopAc_cullSizeSphere(cXyz,
                                                         float) */

void __thiscall
fopAc_cullSizeSphere::fopAc_cullSizeSphere(fopAc_cullSizeSphere *this,cXyz *param_1,float param_2)

{
  (this->mCenter).x = param_1->x;
  (this->mCenter).y = param_1->y;
  (this->mCenter).z = param_1->z;
  this->mRadius = param_2;
  return;
}


/* __thiscall fopAc_cullSizeBox::fopAc_cullSizeBox(fopAc_cullSizeBox const &) */

void __thiscall
fopAc_cullSizeBox::fopAc_cullSizeBox(fopAc_cullSizeBox *this,fopAc_cullSizeBox *param_1)

{
  (this->mMin).x = (param_1->mMin).x;
  (this->mMin).y = (param_1->mMin).y;
  (this->mMin).z = (param_1->mMin).z;
  (this->mMax).x = (param_1->mMax).x;
  (this->mMax).y = (param_1->mMax).y;
  (this->mMax).z = (param_1->mMax).z;
  return;
}


/* __thiscall fopAc_cullSizeBox::fopAc_cullSizeBox(cXyz,
                                                   cXyz) */

void __thiscall
fopAc_cullSizeBox::fopAc_cullSizeBox(fopAc_cullSizeBox *this,cXyz *param_1,cXyz *param_2)

{
  (this->mMin).x = param_1->x;
  (this->mMin).y = param_1->y;
  (this->mMin).z = param_1->z;
  (this->mMax).x = param_2->x;
  (this->mMax).y = param_2->y;
  (this->mMax).z = param_2->z;
  return;
}


/* __thiscall l_HIO::~l_HIO(void) */

void __thiscall l_HIO::_l_HIO(l_HIO *this)

{
  short in_r4;
  
  if ((this != (l_HIO *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* [thunk]:__thiscall dBgS_WtrChk::~dBgS_WtrChk(void) */

void __thiscall dBgS_WtrChk::_dBgS_WtrChk(dBgS_WtrChk *this)

{
  _dBgS_WtrChk((dBgS_WtrChk *)&this[-1].parent.mStartPos.z);
  return;
}


/* [thunk]:__thiscall dBgS_WtrChk::~dBgS_WtrChk(void) */

void __thiscall dBgS_WtrChk::_dBgS_WtrChk(dBgS_WtrChk *this)

{
  _dBgS_WtrChk((dBgS_WtrChk *)&this[-1].parent.mChk.vtbl);
  return;
}


/* [thunk]:__thiscall dBgS_WtrChk::~dBgS_WtrChk(void) */

void __thiscall dBgS_WtrChk::_dBgS_WtrChk(dBgS_WtrChk *this)

{
  _dBgS_WtrChk((dBgS_WtrChk *)&this[-1].parent.mDChk.mPolyPassChk.parent.mbBombThrough);
  return;
}


/* [thunk]:__thiscall dBgS_SplGrpChk::~dBgS_SplGrpChk(void) */

void __thiscall dBgS_SplGrpChk::_dBgS_SplGrpChk(dBgS_SplGrpChk *this)

{
  _dBgS_SplGrpChk((dBgS_SplGrpChk *)&this[-1].mStartPos.z);
  return;
}


/* [thunk]:__thiscall dBgS_SplGrpChk::~dBgS_SplGrpChk(void) */

void __thiscall dBgS_SplGrpChk::_dBgS_SplGrpChk(dBgS_SplGrpChk *this)

{
  _dBgS_SplGrpChk((dBgS_SplGrpChk *)&this[-1].mChk.vtbl);
  return;
}


/* [thunk]:__thiscall dBgS_SplGrpChk::~dBgS_SplGrpChk(void) */

void __thiscall dBgS_SplGrpChk::_dBgS_SplGrpChk(dBgS_SplGrpChk *this)

{
  _dBgS_SplGrpChk((dBgS_SplGrpChk *)&this[-1].mDChk.mPolyPassChk.parent.mbBombThrough);
  return;
}


/* __thiscall daPy_py_c::onFrollCrashFlg(unsigned long) */

void __thiscall daPy_py_c::onFrollCrashFlg(daPy_py_c *this,ulong param_1)

{
  return;
}


/* __thiscall daPy_py_c::getGrabActorID(void) const */

undefined4 __thiscall daPy_py_c::getGrabActorID(daPy_py_c *this)

{
  return 0xffffffff;
}

