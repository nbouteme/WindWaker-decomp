#include <d_a_vrbox2.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_a_vrbox2.h>
#include <d_stage.h>
#include <mtx/mtx.h>
#include <m_Do_ext.h>
#include <m_Do_mtx.h>
#include <d_kankyo_wether.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <d_kankyo_rain.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <f_op_actor.h>
#include <f_op_actor_mng.h>


namespace d_a_vrbox2 {

/* __stdcall texScrollCheck(float &) */

void texScrollCheck(float *param_1)

{
  float fVar1;
  float 0_0;
  float 1_0;
  
  0_0 = 0_0;
  1_0 = 1_0;
  while (fVar1 = 1_0, *param_1 < 0_0) {
    *param_1 = *param_1 + 1_0;
  }
  while (fVar1 < *param_1) {
    *param_1 = *param_1 - fVar1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8015ec10) */
/* __stdcall daVrbox2_Draw(vrbox2_class *) */

undefined4 daVrbox2_Draw(vrbox2_class *param_1)

{
  float fVar1;
  dStage_roomStatus_c *pdVar2;
  int iVar3;
  J3DModel *pUsoUmi;
  J3DModel *pKasumiMae;
  J3DModel *pBackCloud;
  undefined4 uVar4;
  undefined8 in_f31;
  double dVar5;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  pBackCloud = param_1->mpBackCloud;
  pKasumiMae = param_1->mpKasumiMae;
  pUsoUmi = param_1->mpUsoUmi;
  dVar5 = (double)0_0;
  iVar3 = 0;
  daVrbox2_color_set(param_1);
  if ((int)d_kankyo::g_env_light.mVrKasumiMaeColor.r +
      (int)d_kankyo::g_env_light.mVrKasumiMaeColor.g +
      (int)d_kankyo::g_env_light.mVrKasumiMaeColor.b + (int)d_kankyo::g_env_light.mVrSkyColor.r +
      (int)d_kankyo::g_env_light.mVrSkyColor.g + (int)d_kankyo::g_env_light.mVrSkyColor.b +
      (int)d_kankyo::g_env_light.mVrkumoColor.r + (int)d_kankyo::g_env_light.mVrkumoColor.g +
      (int)d_kankyo::g_env_light.mVrkumoColor.b != 0) {
    if (-1 < (char)dStage_roomControl_c::mStayNo) {
      pdVar2 = dStage_roomControl_c::getStatusRoomDt
                         (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,
                          (int)(char)dStage_roomControl_c::mStayNo);
      iVar3 = (*(code *)((pdVar2->parent).parent.vtbl)->getFileListInfo)();
    }
    if (iVar3 != 0) {
      dVar5 = (double)*(float *)(iVar3 + 4);
    }
    fVar1 = 0_0;
    if (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0) {
      fVar1 = 0_09 * (float)((double)((d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->
                                     mInvViewMtx).m[1][3] - dVar5);
    }
    mtx::PSMTXTrans((double)((d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mInvViewMtx).m
                            [3],
                    (double)(((d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mInvViewMtx).
                             m[1][3] - fVar1),
                    (double)((d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mInvViewMtx).m
                            [2][3],&mDoMtx_stack_c::now);
    J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufSkyOpa;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufSkyXlu;
    if (pUsoUmi != (J3DModel *)0x0) {
      mtx::PSMTXCopy(&mDoMtx_stack_c::now,&pUsoUmi->mBaseMtx);
      m_Do_ext::mDoExt_modelUpdateDL(pUsoUmi);
    }
    if (pKasumiMae != (J3DModel *)0x0) {
      mtx::PSMTXCopy(&mDoMtx_stack_c::now,&pKasumiMae->mBaseMtx);
      m_Do_ext::mDoExt_modelUpdateDL(pKasumiMae);
    }
    mDoMtx_stack_c::transM(0_0,100_0,0_0);
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,&pBackCloud->mBaseMtx);
    m_Do_ext::mDoExt_modelUpdateDL(pBackCloud);
    J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8015f340) */
/* WARNING: Removing unreachable block (ram,0x8015f348) */
/* __stdcall daVrbox2_color_set(vrbox2_class *) */

undefined4 daVrbox2_color_set(vrbox2_class *param_1)

{
  float *pfVar1;
  camera_class *pcVar2;
  short sVar3;
  cXyz *windVec;
  int iVar4;
  short *psVar5;
  MTX34 *pM0_TexMtx0;
  MTX34 *pM0_TexMtx1;
  MTX34 *pM1_TexMtx0;
  MTX34 *pM1_TexMtx1;
  MTX34 *pM2_TexMtx0;
  MTX34 *pM2_TexMtx1;
  uint uVar6;
  short sVar7;
  J3DMaterial *pMat0;
  J3DModelData *pJVar8;
  undefined4 uVar9;
  undefined8 in_f30;
  double scrollSpeed;
  undefined8 in_f31;
  double scrollSpeed1;
  _GXColor color;
  _GXColorS10 kasumiMae;
  float windX;
  float windZ;
  cXyz camFwdXZ;
  cXyz local_54;
  cXyz local_48;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  pcVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if ((int)d_kankyo::g_env_light.mVrKasumiMaeColor.r +
      (int)d_kankyo::g_env_light.mVrKasumiMaeColor.g +
      (int)d_kankyo::g_env_light.mVrKasumiMaeColor.b + (int)d_kankyo::g_env_light.mVrSkyColor.r +
      (int)d_kankyo::g_env_light.mVrSkyColor.g + (int)d_kankyo::g_env_light.mVrSkyColor.b +
      (int)d_kankyo::g_env_light.mVrkumoColor.r + (int)d_kankyo::g_env_light.mVrkumoColor.g +
      (int)d_kankyo::g_env_light.mVrkumoColor.b != 0) {
    windVec = d_kankyo_wether::dKyw_get_wind_vec();
    scrollSpeed = d_kankyo_wether::dKyw_get_wind_pow();
    windX = windVec->x;
    windZ = windVec->z;
    iVar4 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                      (0x803c9d58);
    if ((*(uint *)(iVar4 + 0xc) >> 0x10 & 7) == 2) {
      sVar7 = 0;
      iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"LinkRM");
      if (iVar4 == 0) {
        sVar7 = 0x4000;
      }
      else {
        iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Orichh");
        if (iVar4 == 0) {
          sVar7 = -0x4000;
        }
        else {
          iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Ojhous2"
                            );
          if (iVar4 == 0) {
            sVar7 = 0x7fff;
          }
          else {
            iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                              (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                               "Omasao");
            if (iVar4 == 0) {
              sVar7 = -0x4000;
            }
            else {
              iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                                (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                 "Onobuta");
              if (iVar4 == 0) {
                sVar7 = 0x4000;
              }
            }
          }
        }
      }
      if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mTactWindAngleX == -1)
         && (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mTactWindAngleY == -1
            )) {
        uVar6 = 0;
        sVar3 = 0;
      }
      else {
        uVar6 = SEXT24(d_kankyo::g_env_light.mTactWindAngleX);
        sVar3 = d_kankyo::g_env_light.mTactWindAngleY;
      }
      iVar4 = (int)((int)(short)(sVar3 + sVar7) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
      windX = JKernel::JMath::jmaCosTable
              [(int)(uVar6 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)] *
              JKernel::JMath::jmaCosTable[iVar4];
      windZ = JKernel::JMath::jmaCosTable
              [(int)(uVar6 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)] *
              JKernel::JMath::jmaSinTable[iVar4];
      scrollSpeed = (double)0_6;
    }
    local_48.x = (pcVar2->mEyePos).x;
    local_48.z = (pcVar2->mEyePos).z;
    local_54.x = (pcVar2->mCenterPos).x;
    local_54.z = (pcVar2->mCenterPos).z;
    local_48.y = 0_0;
    local_54.y = 0_0;
    d_kankyo_rain::dKyr_get_vectle_calc(&local_48,&local_54,&camFwdXZ);
    scrollSpeed = (double)(float)((double)(0_0004 * ((-windX - 0_0) * (camFwdXZ.z - 0_0) -
                                                    (-windZ - 0_0) * (camFwdXZ.x - 0_0))) *
                                 scrollSpeed);
    iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"M_DragB");
    if (iVar4 == 0) {
      scrollSpeed = (double)_4_0E4;
    }
    pJVar8 = param_1->mpBackCloud->mpModelData;
    pMat0 = *(pJVar8->mMaterialTable).mpMaterials;
    (*(code *)pMat0->mpColorBlock->vtbl->setCullMode_1)(pMat0->mpColorBlock,0);
    psVar5 = (short *)(**(code **)(pMat0->mpPEBlock->vtbl + 0x50))();
    *psVar5 = (ushort)bRam803f62c9 * 2 + (ushort)l_zmodeInfo * 0x10 + (ushort)bRam803f62ca;
    (**(code **)(pMat0->vtbl + 0x28))(pMat0);
    pM0_TexMtx0 = (MTX34 *)(*(code *)pMat0->mpTexGenBlock->vtbl->getTexMtx)(pMat0->mpTexGenBlock,0);
    pfVar1 = pM0_TexMtx0->m[1] + 3;
    *pfVar1 = (float)((double)pM0_TexMtx0->m[1][3] + scrollSpeed);
    texScrollCheck(pfVar1);
    pM0_TexMtx1 = (MTX34 *)(*(code *)pMat0->mpTexGenBlock->vtbl->getTexMtx)(pMat0->mpTexGenBlock,1);
    pfVar1 = pM0_TexMtx1->m[1] + 3;
    *pfVar1 = (float)((double)pM0_TexMtx1->m[1][3] + scrollSpeed);
    texScrollCheck(pfVar1);
    color.r = (u8)d_kankyo::g_env_light.mVrkumoColor.r;
    color.g = (u8)d_kankyo::g_env_light.mVrkumoColor.g;
    color.b = (u8)d_kankyo::g_env_light.mVrkumoColor.b;
    color.a = 0xff;
    (*(code *)pMat0->mpTevBlock->vtbl->setTevKColor_0)(pMat0->mpTevBlock,0,&color);
    pMat0 = (pJVar8->mMaterialTable).mpMaterials[1];
    (*(code *)pMat0->mpColorBlock->vtbl->setCullMode_1)(pMat0->mpColorBlock,0);
    psVar5 = (short *)(**(code **)(pMat0->mpPEBlock->vtbl + 0x50))();
    *psVar5 = (ushort)bRam803f62c9 * 2 + (ushort)l_zmodeInfo * 0x10 + (ushort)bRam803f62ca;
    (**(code **)(pMat0->vtbl + 0x28))(pMat0);
    pM1_TexMtx0 = (MTX34 *)(*(code *)pMat0->mpTexGenBlock->vtbl->getTexMtx)(pMat0->mpTexGenBlock,0);
    scrollSpeed1 = (double)(float)((double)0_8 * scrollSpeed);
    pfVar1 = pM1_TexMtx0->m[1] + 3;
    *pfVar1 = (float)((double)pM1_TexMtx0->m[1][3] + scrollSpeed1);
    texScrollCheck(pfVar1);
    pM1_TexMtx1 = (MTX34 *)(*(code *)pMat0->mpTexGenBlock->vtbl->getTexMtx)(pMat0->mpTexGenBlock,1);
    pfVar1 = pM1_TexMtx1->m[1] + 3;
    *pfVar1 = (float)((double)pM1_TexMtx1->m[1][3] + scrollSpeed1);
    texScrollCheck(pfVar1);
    (*(code *)pMat0->mpTevBlock->vtbl->setTevKColor_0)(pMat0->mpTevBlock,0,&color);
    pMat0 = (pJVar8->mMaterialTable).mpMaterials[2];
    (*(code *)pMat0->mpColorBlock->vtbl->setCullMode_1)(pMat0->mpColorBlock,0);
    psVar5 = (short *)(**(code **)(pMat0->mpPEBlock->vtbl + 0x50))();
    *psVar5 = (ushort)bRam803f62c9 * 2 + (ushort)l_zmodeInfo * 0x10 + (ushort)bRam803f62ca;
    (**(code **)(pMat0->vtbl + 0x28))(pMat0);
    pM2_TexMtx0 = (MTX34 *)(*(code *)pMat0->mpTexGenBlock->vtbl->getTexMtx)(pMat0->mpTexGenBlock,0);
    scrollSpeed1 = (double)(float)((double)0_6 * scrollSpeed);
    pfVar1 = pM2_TexMtx0->m[1] + 3;
    *pfVar1 = (float)((double)pM2_TexMtx0->m[1][3] + scrollSpeed1);
    texScrollCheck(pfVar1);
    pM2_TexMtx1 = (MTX34 *)(*(code *)pMat0->mpTexGenBlock->vtbl->getTexMtx)(pMat0->mpTexGenBlock,1);
    pM2_TexMtx1->m[1][3] = (float)((double)pM2_TexMtx1->m[1][3] + scrollSpeed);
    pfVar1 = pM2_TexMtx1->m[1] + 3;
    *pfVar1 = (float)((double)pM2_TexMtx1->m[1][3] + scrollSpeed1);
    texScrollCheck(pfVar1);
    (*(code *)pMat0->mpTevBlock->vtbl->setTevKColor_0)(pMat0->mpTevBlock,0,&color);
    if (param_1->mpKasumiMae != (J3DModel *)0x0) {
      pMat0 = *(param_1->mpKasumiMae->mpModelData->mMaterialTable).mpMaterials;
      psVar5 = (short *)(**(code **)(pMat0->mpPEBlock->vtbl + 0x50))();
      *psVar5 = (ushort)bRam803f62c9 * 2 + (ushort)l_zmodeInfo * 0x10 + (ushort)bRam803f62ca;
      (**(code **)(pMat0->vtbl + 0x28))(pMat0);
      kasumiMae.r = d_kankyo::g_env_light.mVrKasumiMaeColor.r;
      kasumiMae.g = d_kankyo::g_env_light.mVrKasumiMaeColor.g;
      kasumiMae.b = d_kankyo::g_env_light.mVrKasumiMaeColor.b;
      color.r = (u8)d_kankyo::g_env_light.mVrkumoColor.a;
      color.g = 0;
      color.b = 0;
      color.a = 0;
      (*(code *)pMat0->mpTevBlock->vtbl->setTevColor_0)(pMat0->mpTevBlock,0,&kasumiMae);
      (*(code *)pMat0->mpTevBlock->vtbl->setTevKColor_0)(pMat0->mpTevBlock,0,&color);
    }
    if (param_1->mpUsoUmi != (J3DModel *)0x0) {
      pMat0 = *(param_1->mpUsoUmi->mpModelData->mMaterialTable).mpMaterials;
      psVar5 = (short *)(**(code **)(pMat0->mpPEBlock->vtbl + 0x50))();
      *psVar5 = (ushort)bRam803f62c9 * 2 + (ushort)l_zmodeInfo * 0x10 + (ushort)bRam803f62ca;
      (**(code **)(pMat0->vtbl + 0x28))(pMat0);
      color.r = (u8)d_kankyo::g_env_light.mVrUsoUmiColor.r;
      color.g = (u8)d_kankyo::g_env_light.mVrUsoUmiColor.g;
      color.b = (u8)d_kankyo::g_env_light.mVrUsoUmiColor.b;
      color.a = 0xff;
      (*(code *)pMat0->mpTevBlock->vtbl->setTevKColor_0)(pMat0->mpTevBlock,0,&color);
    }
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  return 1;
}


/* __stdcall daVrbox2_Execute(vrbox2_class *) */

undefined4 daVrbox2_Execute(void)

{
  return 1;
}


/* __stdcall daVrbox2_IsDelete(vrbox2_class *) */

undefined4 daVrbox2_IsDelete(void)

{
  return 1;
}


/* __stdcall daVrbox2_Delete(vrbox2_class *) */

undefined4 daVrbox2_Delete(void)

{
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall daVrbox2_solidHeapCB(fopAc_ac_c *) */

undefined4 daVrbox2_solidHeapCB(vrbox2_class *param_1)

{
  J3DModelData *pJVar1;
  ulong uVar2;
  J3DModel *pJVar3;
  undefined4 uVar4;
  
  pJVar1 = (J3DModelData *)
           dRes_control_c::getRes
                     ("Stage","vr_back_cloud.bdl",
                      d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
  if (pJVar1 == (J3DModelData *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_a_vrbox2.cpp",0x211,"modelData != 0");
    m_Do_printf::OSPanic("d_a_vrbox2.cpp",0x211,"Halt");
  }
  pJVar3 = m_Do_ext::mDoExt_J3DModel__create(pJVar1,0x80000,0x11020202);
  param_1->mpBackCloud = pJVar3;
  pJVar1 = (J3DModelData *)
           dRes_control_c::getRes
                     ("Stage","vr_kasumi_mae.bdl",
                      d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
  if (pJVar1 != (J3DModelData *)0x0) {
    pJVar3 = m_Do_ext::mDoExt_J3DModel__create(pJVar1,0x80000,0x11020202);
    param_1->mpKasumiMae = pJVar3;
  }
  pJVar1 = (J3DModelData *)
           dRes_control_c::getRes
                     ("Stage","vr_uso_umi.bdl",
                      d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
  if (pJVar1 != (J3DModelData *)0x0) {
    pJVar3 = m_Do_ext::mDoExt_J3DModel__create(pJVar1,0x80000,0x11020202);
    param_1->mpUsoUmi = pJVar3;
  }
  uVar4 = 0;
  if (((param_1->mpBackCloud != (J3DModel *)0x0) && (param_1->mpKasumiMae != (J3DModel *)0x0)) &&
     (param_1->mpUsoUmi != (J3DModel *)0x0)) {
    uVar4 = 1;
  }
  return uVar4;
}


/* __stdcall daVrbox2_Create(fopAc_ac_c *) */

undefined4 daVrbox2_Create(fopAc_ac_c *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  if ((param_1->mCondition & Constructed) == 0) {
    if (param_1 != (fopAc_ac_c *)0x0) {
      fopAc_ac_c::fopAc_ac_c(param_1);
    }
    param_1->mCondition = param_1->mCondition | Constructed;
  }
  uVar2 = 4;
  uVar1 = f_op_actor_mng::fopAcM_entrySolidHeap(param_1,daVrbox2_solidHeapCB,0x21a0);
  if ((uVar1 & 0xff) == 0) {
    uVar2 = 5;
  }
  return uVar2;
}

