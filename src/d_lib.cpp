#include <d_lib.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <d_a_sea.h>
#include <SComponent/c_math.h>
#include <SComponent/c_lib.h>
#include <mtx/mtxvec.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <m_Do_ext.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <d_stage.h>
#include <d_com_inf_game.h>
#include <d_save.h>
#include <d_lib.h>
#include <os/OSTime.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_a_obj.h>
#include <mtx/quat.h>
#include <CSTControl.h>
#include <STControl.h>


namespace d_lib {

/* WARNING: Removing unreachable block (ram,0x800570b0) */
/* __stdcall dLib_setCirclePath(dLib_circle_path_c *) */

void dLib_setCirclePath(dLib_circle_path_c *pDst)

{
  undefined4 uVar1;
  undefined8 in_f31;
  double r;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  pDst->mAngle = pDst->mAngle + pDst->mAngleSpeed;
  r = (double)(pDst->mRadius +
              pDst->mWobbleAmplitude *
              JKernel::JMath::jmaSinTable
              [(int)((int)pDst->mAngle & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f)]);
  mtx::PSMTXTrans((double)(pDst->mTranslation).x,(double)(pDst->mTranslation).y,
                  (double)(pDst->mTranslation).z,&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,pDst->mAngle);
  mDoMtx_stack_c::transM((float)r,0_0,0_0);
  (pDst->mPos).x = mDoMtx_stack_c::now.m[0][3];
  (pDst->mPos).y = mDoMtx_stack_c::now.m[1][3];
  (pDst->mPos).z = mDoMtx_stack_c::now.m[2][3];
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8005714c) */
/* __stdcall dLib_getWaterY(cXyz &,
                            dBgS_ObjAcch &) */

double dLib_getWaterY(cXyz *param_1,dBgS_ObjAcch *pAcch)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar3 = (pAcch->parent).mFlags >> 0xb & 1;
  fVar1 = _1_0E9;
  if (uVar3 != 0) {
    fVar1 = (pAcch->parent).mWtrChk.parent.mHeight;
  }
  dVar6 = (double)fVar1;
  uVar2 = d_a_sea::daSea_ChkArea(param_1->x,param_1->z);
  if ((((uVar2 & 0xff) == 0) ||
      ((dVar5 = (double)d_a_sea::daSea_calcWave((double)param_1->x,(double)param_1->z), uVar3 != 0
       && (dVar5 <= dVar6)))) && (dVar5 = dVar6, uVar3 == 0)) {
    dVar5 = (double)0_0;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return dVar5;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80057340) */
/* WARNING: Removing unreachable block (ram,0x80057330) */
/* WARNING: Removing unreachable block (ram,0x80057338) */
/* WARNING: Removing unreachable block (ram,0x80057348) */
/* __stdcall dLib_waveRot(Vec *,
                          float,
                          dLib_wave_c *) */

void dLib_waveRot(cXyz *pPos,float param_2,dLib_wave_c *pWave)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar5 = (double)param_2;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  dVar9 = (double)(pPos->z - 300_0);
  dVar6 = (double)d_a_sea::daSea_calcWave((double)pPos->x,dVar9);
  dVar8 = (double)(300_0 + pPos->z);
  dVar7 = (double)d_a_sea::daSea_calcWave((double)pPos->x,dVar8);
  iVar2 = SComponent::cM_atan2s((float)(dVar7 - dVar6),(float)(dVar8 - dVar9));
  dVar8 = (double)(pPos->x - 300_0);
  dVar6 = (double)d_a_sea::daSea_calcWave(dVar8,(double)pPos->z);
  dVar9 = (double)(300_0 + pPos->x);
  dVar7 = (double)d_a_sea::daSea_calcWave(dVar9,(double)pPos->z);
  iVar3 = SComponent::cM_atan2s((float)(dVar7 - dVar6),(float)(dVar9 - dVar8));
  SComponent::cLib_addCalcAngleS2(&pWave->field_0x0,-(short)iVar2,10,0x200);
  SComponent::cLib_addCalcAngleS2(&pWave->field_0x2,(short)iVar3,10,0x200);
  pWave->field_0x4 = pWave->field_0x4 + 400;
  pWave->field_0x6 = pWave->field_0x6 + 0x1ae;
  dVar6 = _4049;
  fVar1 = (float)((double)150_0 + dVar5) + d_s_play::g_regHIO.mChild[12].mFloats[0];
  pWave->mRotX = (short)(int)((float)((double)CONCAT44(0x43300000,(int)pWave->field_0x0 ^ 0x80000000
                                                      ) - _4049) +
                             fVar1 * JKernel::JMath::jmaSinTable
                                     [(int)((int)pWave->field_0x4 & 0xffffU) >>
                                      (JKernel::JMath::jmaSinShift & 0x3f)]);
  pWave->mRotZ = (short)(int)((float)((double)CONCAT44(0x43300000,(int)pWave->field_0x2 ^ 0x80000000
                                                      ) - dVar6) +
                             fVar1 * JKernel::JMath::jmaCosTable
                                     [(int)((int)pWave->field_0x6 & 0xffffU) >>
                                      (JKernel::JMath::jmaSinShift & 0x3f)]);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  return;
}


/* __stdcall dLib_debugDrawAxis(float &[][][],
                                float) */

void dLib_debugDrawAxis(double param_1,MTX34 *param_2)

{
  cXyz cStack156;
  cXyz cStack144;
  cXyz cStack132;
  cXyz cStack120;
  cXyz cStack108;
  cXyz cStack96;
  cXyz local_54;
  cXyz local_48;
  cXyz local_3c;
  cXyz local_30;
  cXyz local_24;
  cXyz local_18 [2];
  
  local_18[0].x = (float)param_1;
  local_18[0].y = 0_0;
  local_18[0].z = 0_0;
  local_24.x = 0_0;
  local_24.y = (float)param_1;
  local_24.z = 0_0;
  local_30.x = 0_0;
  local_30.y = 0_0;
  local_30.z = (float)param_1;
  local_3c.x = 0_0;
  local_3c.y = 0_0;
  local_3c.z = 0_0;
  local_48.x = 0_0;
  local_48.y = 0_0;
  local_48.z = 0_0;
  local_54.x = 0_0;
  local_54.y = 0_0;
  local_54.z = 0_0;
  mtx::PSMTXCopy(param_2,&mDoMtx_stack_c::now);
  mtx::PSMTXMultVec(&mDoMtx_stack_c::now,local_18,&cStack96);
  mtx::PSMTXMultVec(&mDoMtx_stack_c::now,&local_24,&cStack108);
  mtx::PSMTXMultVec(&mDoMtx_stack_c::now,&local_30,&cStack120);
  mtx::PSMTXMultVec(&mDoMtx_stack_c::now,&local_3c,&cStack132);
  mtx::PSMTXMultVec(&mDoMtx_stack_c::now,&local_48,&cStack144);
  mtx::PSMTXMultVec(&mDoMtx_stack_c::now,&local_54,&cStack156);
  return;
}


/* __stdcall dLib_debugDrawFan(cXyz &,
                               short,
                               short,
                               float,
                               _GXColor const &) */

void dLib_debugDrawFan(void)

{
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dLib_brkInit(J3DModelData *,
                          mDoExt_brkAnm *,
                          char const *,
                          int) */

bool dLib_brkInit(J3DModelData *param_1,mDoExt_brkAnm *param_2,char *param_3,long param_4)

{
  J3DAnmTevRegKey *pJVar1;
  ulong uVar2;
  int iVar3;
  
  pJVar1 = (J3DAnmTevRegKey *)
           dRes_control_c::getRes
                     (param_3,param_4,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pJVar1 == (J3DAnmTevRegKey *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_lib.cpp",0xae,"brk != 0");
    m_Do_printf::OSPanic("d_lib.cpp",0xae,&DAT_8034f763);
  }
  iVar3 = ::mDoExt_brkAnm::init(param_2,param_1,pJVar1,true,Once,_4157,0,-1,false,0);
  return iVar3 != 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dLib_btkInit(J3DModelData *,
                          mDoExt_btkAnm *,
                          char const *,
                          int) */

bool dLib_btkInit(J3DModelData *param_1,mDoExt_btkAnm *param_2,char *param_3,long param_4)

{
  J3DAnmTextureSRTKey *pAnm;
  ulong uVar1;
  int iVar2;
  
  pAnm = (J3DAnmTextureSRTKey *)
         dRes_control_c::getRes
                   (param_3,param_4,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pAnm == (J3DAnmTextureSRTKey *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_lib.cpp",0xbb,"btk != 0");
    m_Do_printf::OSPanic("d_lib.cpp",0xbb,&DAT_8034f763);
  }
  iVar2 = ::mDoExt_btkAnm::init(param_2,param_1,pAnm,true,Once,_4157,0,-1,false,0);
  return iVar2 != 0;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __stdcall dLib_setAnm(char const *,
                         mDoExt_McaMorf *,
                         signed char *,
                         signed char *,
                         signed char *,
                         dLib_anm_idx_c const *,
                         dLib_anm_prm_c const *,
                         bool) */

void dLib_setAnm(char *pName,mDoExt_McaMorf *pMorf,byte *param_3,byte *param_4,byte *param_5,
                       void *param_6,void *param_7,byte param_8)

{
  byte bVar1;
  bool bVar2;
  J3DAnmTransform *pAnimRes;
  long fileIndex;
  void *pvVar3;
  void *pvVar4;
  
  bVar1 = *param_4;
  if ((((int)(char)*param_5 != (int)(char)bVar1) &&
      (*(char *)((int)param_7 + (char)bVar1 * 0x10) != -1)) || (param_8 == 1)) {
    *param_3 = *(byte *)((int)param_7 + (char)bVar1 * 0x10);
    pvVar4 = (void *)0x0;
    fileIndex = *(long *)((int)param_6 + (char)*param_3 * 8 + 4);
    if (-1 < fileIndex) {
      pvVar4 = dRes_control_c::getRes
                         (pName,fileIndex,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                          0x40);
    }
    pAnimRes = (J3DAnmTransform *)
               dRes_control_c::getRes
                         (pName,*(long *)((int)param_6 + (char)*param_3 * 8),
                          d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    pvVar3 = (void *)((int)param_7 + (char)*param_4 * 0x10);
    mDoExt_McaMorf::setAnm
              (pMorf,pAnimRes,*(int *)((int)pvVar3 + 0xc),*(float *)((int)pvVar3 + 4),
               *(float *)((int)pvVar3 + 8),0_0,_4211,pvVar4);
  }
  *param_5 = *param_4;
  bVar2 = true;
  if (((pMorf->mFrameCtrl).mFlags & 1) == 0) {
    if (0_0 != (pMorf->mFrameCtrl).mSpeed) {
      bVar2 = false;
    }
  }
  if (bVar2) {
    pvVar4 = (void *)((int)param_7 + (char)*param_4 * 0x10);
    bVar1 = *(byte *)((int)pvVar4 + 1);
    if ((bVar1 != 0xff) && (*(int *)((int)pvVar4 + 0xc) == 0)) {
      *param_4 = bVar1;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dLib_bcks_setAnm(char const *,
                              mDoExt_McaMorf *,
                              signed char *,
                              signed char *,
                              signed char *,
                              int const *,
                              dLib_anm_prm_c const *,
                              bool) */

void dLib_bcks_setAnm
               (char *param_1,mDoExt_McaMorf *param_2,char *param_3,char *param_4,char *param_5,
               int param_6,int param_7,char param_8)

{
  char cVar1;
  bool bVar2;
  J3DAnmTransform *pAnimRes;
  int iVar3;
  
  cVar1 = *param_4;
  if ((int)*param_5 == (int)cVar1) {
LAB_80057894:
    if (param_8 != '\x01') goto LAB_8005790c;
  }
  else {
    if (*(char *)(param_7 + cVar1 * 0x10) == -1) goto LAB_80057894;
  }
  *param_3 = *(char *)(param_7 + cVar1 * 0x10);
  pAnimRes = (J3DAnmTransform *)
             dRes_control_c::getRes
                       (param_1,*(long *)(param_6 + *param_3 * 4),
                        d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  iVar3 = param_7 + *param_4 * 0x10;
  mDoExt_McaMorf::setAnm
            (param_2,pAnimRes,*(int *)(iVar3 + 0xc),*(float *)(iVar3 + 4),*(float *)(iVar3 + 8),0_0,
             _4211,(void *)0x0);
LAB_8005790c:
  *param_5 = *param_4;
  bVar2 = true;
  if (((param_2->mFrameCtrl).mFlags & 1) == 0) {
    if (0_0 != (param_2->mFrameCtrl).mSpeed) {
      bVar2 = false;
    }
  }
  if (bVar2) {
    param_7 = param_7 + *param_4 * 0x10;
    cVar1 = *(char *)(param_7 + 1);
    if ((cVar1 != -1) && (*(int *)(param_7 + 0xc) == 0)) {
      *param_4 = cVar1;
    }
  }
  return;
}


/* __stdcall dLib_scaleAnime(float *,
                             float *,
                             int,
                             int *,
                             float,
                             float,
                             float) */

void dLib_scaleAnime
               (float *param_1,int param_2,int param_3,int *param_4,float param_5,float param_6,
               float param_7)

{
  int iVar1;
  double dVar2;
  
  iVar1 = *param_4;
  if (iVar1 < param_3) {
    dVar2 = SComponent::cLib_addCalc
                      (param_1,*(float *)(param_2 + iVar1 * 4),param_5,param_6,param_7);
    if (((double)0_0 == dVar2) && (*param_4 = *param_4 + -1, *param_4 < 0)) {
      *param_4 = 0;
    }
  }
  else {
    *param_4 = iVar1 + -1;
  }
  return;
}


/* __stdcall dLib_getPosFromMtx(float *[][][][],
                                cXyz *) */

void dLib_getPosFromMtx(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 0x2c);
  uVar2 = *(undefined4 *)(param_1 + 0x1c);
  *param_2 = *(undefined4 *)(param_1 + 0xc);
  param_2[1] = uVar2;
  param_2[2] = uVar1;
  return;
}


/* __stdcall dLib_pathInfo(dPath * *,
                           unsigned char) */

uint dLib_pathInfo(dPath **param_1,uint param_2)

{
  dStage_dPath_c *pPath;
  
  pPath = (dStage_dPath_c *)
          (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getPathInf)();
  if (pPath != (dStage_dPath_c *)0x0) {
    *param_1 = pPath->mpPath + (param_2 & 0xff);
  }
  return (uint)(pPath != (dStage_dPath_c *)0x0);
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80057cfc) */
/* __stdcall dLib_pathMove(cXyz *,
                           signed char *,
                           dPath *,
                           float,
                           int *(cXyz *,cXyz *,cXyz *,void *),
                           void *) */

void dLib_pathMove
               (cXyz *pDst,byte *pPointIdx,dPath *pPath,float speed,undefined *pCB,void *pUserData)

{
  uint uVar1;
  cXyz *pPos;
  int iVar2;
  byte pointIdxNext;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  float fVar7;
  cXyz local_80;
  cXyz local_74;
  cXyz local_68;
  cXyz local_5c;
  cXyz local_50;
  cXyz pointPosNext;
  cXyz pointPosThis;
  undefined auStack8 [8];
  byte pointIdxCurr;
  
  dVar6 = (double)speed;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  pointIdxCurr = *pPointIdx;
  uVar1 = pPath->mNum - 1;
  pointIdxNext = pointIdxCurr + 1 &
                 -(char)((int)uVar1 >> 0x1f) -
                 (((uint)(int)(char)pointIdxCurr < uVar1) - ((char)pointIdxCurr >> 7));
  pPos = &pPath->mpPnt[(char)pointIdxCurr].mPos;
  pointPosThis.x = pPos->x;
  pointPosThis.y = pPos->y;
  pointPosThis.z = pPos->z;
  pPos = &pPath->mpPnt[(char)pointIdxNext].mPos;
  pointPosNext.x = pPos->x;
  pointPosNext.y = pPos->y;
  pointPosNext.z = pPos->z;
  ::cXyz::operator__(&local_5c,&pointPosNext,&pointPosThis);
  ::cXyz::normZP(&local_68,&local_5c);
  local_50.x = local_68.x;
  local_50.y = local_68.y;
  local_50.z = local_68.z;
  if (pCB == (undefined *)0x0) {
    ::cXyz::operator_(&local_74,&local_50,(float)dVar6);
    ::cXyz::operator__(&local_80,pDst,&local_74);
    pDst->x = local_80.x;
    pDst->y = local_80.y;
    pDst->z = local_80.z;
    fVar7 = mtx::PSVECSquareDistance(&pointPosThis,pDst);
    dVar6 = (double)fVar7;
    if ((double)0_0 < dVar6) {
      dVar4 = 1.0 / SQRT(dVar6);
      dVar4 = _4340 * dVar4 * (_4341 - dVar6 * dVar4 * dVar4);
      dVar4 = _4340 * dVar4 * (_4341 - dVar6 * dVar4 * dVar4);
      dVar6 = (double)(float)(dVar6 * _4340 * dVar4 * (_4341 - dVar6 * dVar4 * dVar4));
    }
    fVar7 = mtx::PSVECSquareDistance(&pointPosThis,&pointPosNext);
    dVar4 = (double)fVar7;
    if ((double)0_0 < dVar4) {
      dVar5 = 1.0 / SQRT(dVar4);
      dVar5 = _4340 * dVar5 * (_4341 - dVar4 * dVar5 * dVar5);
      dVar5 = _4340 * dVar5 * (_4341 - dVar4 * dVar5 * dVar5);
      dVar4 = (double)(float)(dVar4 * _4340 * dVar5 * (_4341 - dVar4 * dVar5 * dVar5));
    }
    if (dVar4 < dVar6) {
      *pPointIdx = pointIdxNext;
      pDst->x = pointPosNext.x;
      pDst->y = pointPosNext.y;
      pDst->z = pointPosNext.z;
    }
  }
  else {
    iVar2 = (*(code *)pCB)(pDst,&pointPosThis,&pointPosNext,pUserData);
    if (iVar2 != 0) {
      *pPointIdx = pointIdxNext;
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dLib_setNextStageBySclsNum(unsigned char,
                                        signed char) */

void dLib_setNextStageBySclsNum(uint param_1,byte roomIdx)

{
  bool bVar1;
  int *piVar2;
  dStage_roomStatus_c *pdVar3;
  ulong uVar4;
  char *pStageName;
  int iVar5;
  
  if (roomIdx == 0xff) {
    piVar2 = (int *)(*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                              getSclsInfo)();
  }
  else {
    bVar1 = false;
    if ((-1 < (char)roomIdx) && ((char)roomIdx < '@')) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar4,"d_lib.cpp",0x1c4,"0 <= room_no && room_no < 64");
      m_Do_printf::OSPanic("d_lib.cpp",0x1c4,&DAT_8034f763);
    }
    pdVar3 = dStage_roomControl_c::getStatusRoomDt
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,(int)(char)roomIdx);
    piVar2 = (int *)(*(code *)((pdVar3->parent).parent.vtbl)->getSclsInfo)();
  }
  if (piVar2 != (int *)0x0) {
    iVar5 = piVar2[1];
    if (iVar5 == 0) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar4,"d_lib.cpp",0x1ce,"scls_data != 0");
      m_Do_printf::OSPanic("d_lib.cpp",0x1ce,&DAT_8034f763);
    }
    if (*piVar2 <= (int)(param_1 & 0xff)) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar4,"d_lib.cpp",0x1cf,"0 <= i_sclsnum && i_sclsnum < sclsinfo->num");
      m_Do_printf::OSPanic("d_lib.cpp",0x1cf,&DAT_8034f763);
    }
    pStageName = (char *)(iVar5 + (param_1 & 0xff) * 0xc);
    d_com_inf_game::dComIfGp_setNextStage
              (pStageName,(ushort)(byte)pStageName[8],pStageName[9],0xff,0_0,0,1,
               pStageName[10] & 0xfU & ~-((pStageName[10] & 0xfU) == 0xff));
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dLib_setFirstMsg(unsigned short,
                              unsigned long,
                              unsigned long) */

undefined4 dLib_setFirstMsg(ushort param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,param_1);
  if (iVar1 == 0) {
    dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,param_1);
    param_3 = param_2;
  }
  return param_3;
}


/* __stdcall dLib_checkPlayerInCircle(cXyz,
                                      float,
                                      float) */

void dLib_checkPlayerInCircle(undefined4 *param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = *param_1;
  local_14 = param_1[1];
  local_10 = param_1[2];
  dLib_checkActorInCircle(&local_18,d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80058070) */
/* WARNING: Removing unreachable block (ram,0x80058078) */
/* __stdcall dLib_checkActorInCircle(cXyz,
                                     fopAc_ac_c *,
                                     float,
                                     float) */

undefined4 dLib_checkActorInCircle(double param_1,double param_2,cXyz *param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f30;
  undefined8 in_f31;
  float fVar5;
  cXyz local_44;
  cXyz local_38;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  ::cXyz::operator__(&local_38,param_3,(cXyz *)(param_4 + 0x1f8));
  local_44.x = local_38.x;
  local_44.y = 0_0;
  local_44.z = local_38.z;
  fVar5 = mtx::PSVECSquareMag(&local_44);
  dVar4 = (double)fVar5;
  if ((double)0_0 < dVar4) {
    dVar3 = 1.0 / SQRT(dVar4);
    dVar3 = _4340 * dVar3 * (_4341 - dVar4 * dVar3 * dVar3);
    dVar3 = _4340 * dVar3 * (_4341 - dVar4 * dVar3 * dVar3);
    dVar4 = (double)(float)(dVar4 * _4340 * dVar3 * (_4341 - dVar4 * dVar3 * dVar3));
  }
  if ((param_1 <= dVar4) || (param_2 <= (double)ABS(param_3->y - *(float *)(param_4 + 0x1fc)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x800581e4) */
/* WARNING: Removing unreachable block (ram,0x800581d4) */
/* WARNING: Removing unreachable block (ram,0x800581dc) */
/* WARNING: Removing unreachable block (ram,0x800581ec) */
/* __stdcall dLib_checkActorInFan(cXyz,
                                  fopAc_ac_c *,
                                  short,
                                  short,
                                  float,
                                  float) */

undefined4
dLib_checkActorInFan
          (double param_1,double param_2,cXyz *param_3,int param_4,short param_5,short param_6)

{
  short sVar2;
  undefined4 uVar1;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar5;
  undefined8 in_f30;
  undefined8 in_f31;
  float fVar6;
  cXyz local_74;
  cXyz local_68 [2];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  ::cXyz::operator__(local_68,param_3,(cXyz *)(param_4 + 0x1f8));
  local_74.x = local_68[0].x;
  local_74.y = 0_0;
  local_74.z = local_68[0].z;
  fVar6 = mtx::PSVECSquareMag(&local_74);
  dVar5 = (double)fVar6;
  if ((double)0_0 < dVar5) {
    dVar4 = 1.0 / SQRT(dVar5);
    dVar4 = _4340 * dVar4 * (_4341 - dVar5 * dVar4 * dVar4);
    dVar4 = _4340 * dVar4 * (_4341 - dVar5 * dVar4 * dVar4);
    dVar5 = (double)(float)(dVar5 * _4340 * dVar4 * (_4341 - dVar5 * dVar4 * dVar4));
  }
  dVar4 = (double)ABS(param_3->y - *(float *)(param_4 + 0x1fc));
  sVar2 = SComponent::cLib_targetAngleY(param_3,(cXyz *)(param_4 + 0x1f8));
  sVar2 = SComponent::cLib_distanceAngleS(param_5,sVar2);
  if (((param_1 <= dVar5) || (param_2 <= dVar4)) || (param_6 <= sVar2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  __psq_l0(auStack56,uVar3);
  __psq_l1(auStack56,uVar3);
  return uVar1;
}

}

/* __thiscall STControl::STControl(short,
                                   short,
                                   short,
                                   short,
                                   float,
                                   float,
                                   short,
                                   short) */

void __thiscall
STControl::STControl
          (STControl *this,short param_1,short param_2,short param_3,short param_4,float param_5,
          float param_6,short param_7,short param_8)

{
  this->vtbl = (undefined *)&__vt;
  setWaitParm(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  init(this);
  return;
}


/* __thiscall STControl::setWaitParm(short,
                                     short,
                                     short,
                                     short,
                                     float,
                                     float,
                                     short,
                                     short) */

void __thiscall
STControl::setWaitParm
          (STControl *this,short param_1,short param_2,short param_3,short param_4,float param_5,
          float param_6,short param_7,short param_8)

{
  this->field_0x12 = param_1;
  this->field_0x14 = param_2;
  this->field_0x16 = param_3;
  this->field_0x1c = param_4;
  this->field_0x4 = param_5;
  this->field_0x8 = param_6;
  this->field_0x24 = param_7;
  this->field_0x26 = param_8;
  return;
}


/* __thiscall STControl::init(void) */

int __thiscall STControl::init(STControl *this)

{
  this->field_0xe = 0;
  this->field_0x10 = 0;
  this->field_0xd = 0;
  this->field_0xc = 0;
  this->field_0x22 = 0;
  this->field_0x18 = this->field_0x12;
  this->field_0x1a = this->field_0x12;
  this->field_0x1e = this->field_0x1c;
  this->field_0x20 = this->field_0x1c;
  return (int)this;
}


/* __thiscall STControl::Xinit(void) */

void __thiscall STControl::Xinit(STControl *this)

{
  this->field_0xe = 0;
  this->field_0xc = this->field_0xc & 0xfc;
  this->field_0x18 = this->field_0x12;
  this->field_0x1e = this->field_0x1c;
  return;
}


/* __thiscall STControl::Yinit(void) */

void __thiscall STControl::Yinit(STControl *this)

{
  this->field_0x10 = 0;
  this->field_0xc = this->field_0xc & 0xf3;
  this->field_0x1a = this->field_0x12;
  this->field_0x20 = this->field_0x1c;
  return;
}


/* __thiscall STControl::getValueStick(void) */

double __thiscall STControl::getValueStick(STControl *this)

{
  return (double)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainValue;
}


/* __thiscall STControl::getAngleStick(void) */

int __thiscall STControl::getAngleStick(STControl *this)

{
  return (int)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainAngle;
}


/* __thiscall CSTControl::getValueStick(void) */

double __thiscall CSTControl::getValueStick(CSTControl *this)

{
  return (double)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickCValue;
}


/* __thiscall CSTControl::getAngleStick(void) */

int __thiscall CSTControl::getAngleStick(CSTControl *this)

{
  return (int)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickCAngle;
}


/* WARNING: Removing unreachable block (ram,0x800585b4) */
/* __thiscall STControl::checkTrigger(void) */

byte __thiscall STControl::checkTrigger(STControl *this)

{
  short sVar2;
  int iVar1;
  int iVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  undefined4 uVar7;
  double dVar8;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  this->field_0xd = this->field_0xc;
  dVar8 = (double)(**(code **)(this->vtbl + 8))();
  sVar2 = (**(code **)(this->vtbl + 0xc))(this);
  iVar6 = (int)(short)(0x2000 - this->field_0x26 >> 1);
  if ((float)ABS(dVar8) < SComponent::G_CM3D_F_ABS_MIN) {
    this->field_0xc = 0;
    Xinit(this);
    Yinit(this);
  }
  else {
    uVar4 = SEXT24(sVar2);
    iVar3 = (int)(short)this->field_0x22;
    iVar1 = iVar3 + iVar6;
    if ((int)uVar4 < iVar1 + -0x7000) {
      bVar5 = 4;
    }
    else {
      if ((int)uVar4 < (iVar3 + -0x5000) - iVar6) {
        bVar5 = 5;
      }
      else {
        if ((int)uVar4 < iVar1 + -0x3000) {
          bVar5 = 1;
        }
        else {
          if ((int)uVar4 < (iVar3 + -0x1000) - iVar6) {
            bVar5 = 9;
          }
          else {
            if ((int)uVar4 < iVar1 + 0x1000) {
              bVar5 = 8;
            }
            else {
              if ((int)uVar4 < (iVar3 + 0x3000) - iVar6) {
                bVar5 = 10;
              }
              else {
                if ((int)uVar4 < iVar1 + 0x5000) {
                  bVar5 = 2;
                }
                else {
                  if ((int)uVar4 < (iVar3 + 0x7000) - iVar6) {
                    bVar5 = 6;
                  }
                  else {
                    bVar5 = 4;
                  }
                }
              }
            }
          }
        }
      }
    }
    if (dVar8 < (double)this->field_0x4) {
      if ((double)this->field_0x8 <= dVar8) {
        this->field_0xc = this->field_0xc & ~bVar5;
      }
      else {
        this->field_0xc = 0;
      }
    }
    else {
      this->field_0xc = bVar5;
    }
    if (this->field_0xc != this->field_0xd) {
      if (this->field_0xc == 0) {
        this->field_0x22 = 0;
      }
      else {
        if ((uVar4 & 0x1fff) < 0x1001) {
          this->field_0x22 = -this->field_0x24;
        }
        else {
          this->field_0x22 = this->field_0x24;
        }
      }
    }
    if ((this->field_0xc & 3) == 0) {
      Xinit(this);
    }
    if ((this->field_0xc & 0xc) == 0) {
      Yinit(this);
    }
  }
  if (((this->field_0xd & this->field_0xc & 3) != 0) && (0 < (short)this->field_0xe)) {
    this->field_0xe = this->field_0xe + -1;
  }
  if (((this->field_0xd & this->field_0xc & 0xc) != 0) && (0 < (short)this->field_0x10)) {
    this->field_0x10 = this->field_0x10 + -1;
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return this->field_0xc;
}


/* __thiscall STControl::checkLeftTrigger(void) */

undefined4 __thiscall STControl::checkLeftTrigger(STControl *this)

{
  if ((this->field_0xe == 0) && ((this->field_0xc & 1) != 0)) {
    this->field_0xe = this->field_0x18;
    if (this->field_0x1e == 0) {
      this->field_0x18 = this->field_0x18 - this->field_0x16;
      if ((short)this->field_0x18 < this->field_0x14) {
        this->field_0x18 = this->field_0x14;
      }
    }
    else {
      this->field_0x1e = this->field_0x1e + -1;
    }
    return 1;
  }
  return 0;
}


/* __thiscall STControl::checkRightTrigger(void) */

undefined4 __thiscall STControl::checkRightTrigger(STControl *this)

{
  if ((this->field_0xe == 0) && ((this->field_0xc & 2) != 0)) {
    this->field_0xe = this->field_0x18;
    if (this->field_0x1e == 0) {
      this->field_0x18 = this->field_0x18 - this->field_0x16;
      if ((short)this->field_0x18 < this->field_0x14) {
        this->field_0x18 = this->field_0x14;
      }
    }
    else {
      this->field_0x1e = this->field_0x1e + -1;
    }
    return 1;
  }
  return 0;
}


/* __thiscall STControl::checkUpTrigger(void) */

undefined4 __thiscall STControl::checkUpTrigger(STControl *this)

{
  if ((this->field_0x10 == 0) && ((this->field_0xc & 4) != 0)) {
    this->field_0x10 = this->field_0x1a;
    if (this->field_0x20 == 0) {
      this->field_0x1a = this->field_0x1a - this->field_0x16;
      if ((short)this->field_0x1a < this->field_0x14) {
        this->field_0x1a = this->field_0x14;
      }
    }
    else {
      this->field_0x20 = this->field_0x20 + -1;
    }
    return 1;
  }
  return 0;
}


/* __thiscall STControl::checkDownTrigger(void) */

undefined4 __thiscall STControl::checkDownTrigger(STControl *this)

{
  if ((this->field_0x10 == 0) && ((this->field_0xc & 8) != 0)) {
    this->field_0x10 = this->field_0x1a;
    if (this->field_0x20 == 0) {
      this->field_0x1a = this->field_0x1a - this->field_0x16;
      if ((short)this->field_0x1a < this->field_0x14) {
        this->field_0x1a = this->field_0x14;
      }
    }
    else {
      this->field_0x20 = this->field_0x20 + -1;
    }
    return 1;
  }
  return 0;
}


namespace d_lib {

/* __stdcall dLib_getIplDaysFromSaveTime(void) */

undefined4 dLib_getIplDaysFromSaveTime(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 extraout_r4;
  
  uVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB._4_4_;
  uVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB._0_4_;
  if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB._4_4_ |
      d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB._0_4_) == 0) {
    uVar4 = 0;
  }
  else {
    iVar5 = os::OSGetTime();
    uVar1 = DAT_800000f8 >> 2;
    Runtime.PPCEABI.H::__div2i
              (iVar5 - ((param_2 < uVar3) + uVar2),param_2 - uVar3,
               (int)((ulonglong)(uVar1 * 0xe10) * 0x18 >> 0x20) +
               ((int)((ulonglong)(uVar1 * 0x3c) * 0x3c >> 0x20) +
               (int)((ulonglong)uVar1 * 0x3c >> 0x20) * 0x3c) * 0x18,uVar1 * 0x15180);
    uVar4 = extraout_r4;
  }
  return uVar4;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dLib_get_QuatFromTriangle(cXyz *,
                                       cXyz *,
                                       cXyz *) */

void dLib_get_QuatFromTriangle(undefined4 *param_1,cXyz *param_2,cXyz *param_3,cXyz *param_4)

{
  cXyz *pcVar1;
  cXyz local_68;
  cXyz local_5c;
  cXyz local_50;
  undefined local_44 [16];
  float local_34;
  float local_30;
  cXyz local_2c;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  ::cXyz::operator__(&local_50,param_3,param_2);
  local_2c.x = local_50.x;
  local_2c.y = local_50.y;
  local_2c.z = local_50.z;
  ::cXyz::operator__(&local_5c,param_4,param_2);
  local_44._12_4_ = local_5c.x;
  local_34 = local_5c.y;
  local_30 = local_5c.z;
  pcVar1 = (cXyz *)(local_44 + 0xc);
  ::cXyz::outprod(&local_68,&local_2c,pcVar1);
  local_44._0_4_ = local_68.x;
  local_44._4_4_ = local_68.y;
  local_44._8_4_ = local_68.z;
  ::daObj::quat_rotBaseY2((daObj *)&local_20,(Quaternion *)local_44,pcVar1);
  *param_1 = local_20;
  param_1[1] = local_1c;
  param_1[2] = local_18;
  param_1[3] = local_14;
  return;
}


/* WARNING: Removing unreachable block (ram,0x8005898c) */
/* __stdcall dLib_calc_QuatFromTriangle(Quaternion *,
                                        float,
                                        cXyz *,
                                        cXyz *,
                                        cXyz *) */

void dLib_calc_QuatFromTriangle(double param_1,Quaternion *param_2)

{
  undefined4 uVar1;
  undefined8 in_f31;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  Quaternion local_38;
  Quaternion local_28;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dLib_get_QuatFromTriangle(&local_48);
  local_28.x = local_48;
  local_28.y = local_44;
  local_28.z = local_40;
  local_28.w = local_3c;
  mtx::C_QUATSlerp(param_1,param_2,&local_28,&local_38);
  param_2->x = local_38.x;
  param_2->y = local_38.y;
  param_2->z = local_38.z;
  param_2->w = local_38.w;
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}

