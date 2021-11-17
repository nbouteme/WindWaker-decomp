#include <d_a_vrbox.h>
#include <d_a_vrbox.h>
#include <d_stage.h>
#include <mtx/mtx.h>
#include <m_Do_ext.h>
#include <d_kankyo.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <d_kankyo_wether.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <f_op_actor.h>
#include <f_op_actor_mng.h>
#include <J3DTevBlock.h>
#include <J3DColorBlock.h>


namespace d_a_vrbox {

/* WARNING: Removing unreachable block (ram,0x8015e510) */
/* __stdcall daVrbox_Draw(vrbox_class *) */

undefined4 daVrbox_Draw(vrbox_class *param_1)

{
  float fVar1;
  dStage_roomStatus_c *pdVar2;
  dStage_FileList_dt_c *pFili;
  J3DModel *pJVar3;
  undefined4 uVar4;
  undefined8 in_f31;
  double dVar5;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  pJVar3 = param_1->mpModel;
  dVar5 = (double)0_0;
  pFili = (dStage_FileList_dt_c *)0x0;
  daVrbox_color_set(param_1);
  if (d_kankyo::g_env_light.mbVrboxInvisible == 0) {
    if (-1 < (char)dStage_roomControl_c::mStayNo) {
      pdVar2 = dStage_roomControl_c::getStatusRoomDt
                         (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,
                          (int)(char)dStage_roomControl_c::mStayNo);
      pFili = (dStage_FileList_dt_c *)(*(code *)((pdVar2->parent).parent.vtbl)->getFileListInfo)();
    }
    if (pFili != (dStage_FileList_dt_c *)0x0) {
      dVar5 = (double)pFili->mSkyboxY;
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
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,&pJVar3->mBaseMtx);
    J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufSkyOpa;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufSkyXlu;
    m_Do_ext::mDoExt_modelUpdateDL(pJVar3);
    J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall daVrbox_color_set(vrbox_class *) */

undefined4 daVrbox_color_set(vrbox_class *param_1)

{
  J3DMaterial *pJVar1;
  J3DModelData *pJVar2;
  _GXColor local_18;
  
  if ((int)d_kankyo::g_env_light.mVrKasumiMaeColor.r +
      (int)d_kankyo::g_env_light.mVrKasumiMaeColor.g +
      (int)d_kankyo::g_env_light.mVrKasumiMaeColor.b + (int)d_kankyo::g_env_light.mVrSkyColor.r +
      (int)d_kankyo::g_env_light.mVrSkyColor.g + (int)d_kankyo::g_env_light.mVrSkyColor.b +
      (int)d_kankyo::g_env_light.mVrkumoColor.r + (int)d_kankyo::g_env_light.mVrkumoColor.g +
      (int)d_kankyo::g_env_light.mVrkumoColor.b == 0) {
    d_kankyo::g_env_light.mbVrboxInvisible = 1;
  }
  else {
    d_kankyo::g_env_light.mbVrboxInvisible = 0;
    pJVar2 = param_1->mpModel->mpModelData;
    pJVar1 = *(pJVar2->mMaterialTable).mpMaterials;
    (*(code *)pJVar1->mpColorBlock->vtbl->setCullMode_1)(pJVar1->mpColorBlock,0);
    (**(code **)(pJVar1->vtbl + 0x28))(pJVar1);
    local_18.r = (u8)d_kankyo::g_env_light.mVrKasumiMaeColor.r;
    local_18.g = (u8)d_kankyo::g_env_light.mVrKasumiMaeColor.g;
    local_18.b = (u8)d_kankyo::g_env_light.mVrKasumiMaeColor.b;
    local_18.a = 0xff;
    (*(code *)pJVar1->mpTevBlock->vtbl->setTevKColor_0)(pJVar1->mpTevBlock,0,&local_18);
    pJVar1 = (pJVar2->mMaterialTable).mpMaterials[1];
    (*(code *)pJVar1->mpColorBlock->vtbl->setCullMode_1)(pJVar1->mpColorBlock,0);
    (**(code **)(pJVar1->vtbl + 0x28))(pJVar1);
    local_18.r = (u8)d_kankyo::g_env_light.mVrSkyColor.r;
    local_18.g = (u8)d_kankyo::g_env_light.mVrSkyColor.g;
    local_18.b = (u8)d_kankyo::g_env_light.mVrSkyColor.b;
    local_18.a = 0xff;
    (*(code *)pJVar1->mpTevBlock->vtbl->setTevKColor_0)(pJVar1->mpTevBlock,0,&local_18);
  }
  return 1;
}

}

/* __thiscall J3DTevBlock::setTevKColor(unsigned long,
                                        J3DGXColor const *) */

void __thiscall J3DTevBlock::setTevKColor(J3DTevBlock *this,ulong param_1,J3DGXColor *param_2)

{
  return;
}


/* __thiscall J3DColorBlock::setCullMode(unsigned char) */

void __thiscall J3DColorBlock::setCullMode(J3DColorBlock *this,uchar param_1)

{
  return;
}


namespace d_a_vrbox {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dungeon_rain_proc(void) */

void dungeon_rain_proc(void)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  
  bVar2 = dStage_roomControl_c::mStayNo;
  iVar4 = 0;
  iVar3 = d_kankyo::dKy_checkEventNightStop();
  if (iVar3 != 0) {
    bVar1 = true;
    iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"M_NewD2");
    if (iVar3 == 0) {
      if (bVar2 == 3) {
        iVar4 = 1;
      }
    }
    else {
      iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"M_Dra09");
      if (iVar3 == 0) {
        iVar4 = 1;
      }
      else {
        iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"kinMB");
        if (iVar3 == 0) {
          iVar4 = 1;
        }
        else {
          iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"kindan")
          ;
          if (iVar3 == 0) {
            if ((bVar2 == 2) || (bVar2 == 0xd)) {
              iVar4 = 1;
            }
            else {
              if (bVar2 == 4) {
                iVar4 = 2;
              }
            }
          }
          else {
            bVar1 = false;
          }
        }
      }
    }
    if (bVar1) {
      if (iVar4 == 1) {
        if (d_kankyo::g_env_light.mRainCountOrig != 0xfa) {
          d_kankyo::dKy_change_colpat(1);
          d_kankyo_wether::dKyw_rain_set(0xfa);
          d_kankyo::g_env_light.mThunderMode = 1;
        }
      }
      else {
        if (iVar4 == 2) {
          if (d_kankyo::g_env_light.mThunderMode == 0) {
            d_kankyo::dKy_change_colpat(1);
            d_kankyo::g_env_light.mThunderMode = 10;
          }
        }
        else {
          if (d_kankyo::g_env_light.mThunderMode != 0) {
            d_kankyo_wether::dKyw_rain_set(0);
            d_kankyo::g_env_light.mThunderMode = 0;
          }
        }
      }
    }
  }
  return;
}


/* __stdcall daVrbox_Execute(vrbox_class *) */

undefined4 daVrbox_Execute(void)

{
  dungeon_rain_proc();
  return 1;
}


/* __stdcall daVrbox_IsDelete(vrbox_class *) */

undefined4 daVrbox_IsDelete(void)

{
  return 1;
}


/* __stdcall daVrbox_Delete(vrbox_class *) */

undefined4 daVrbox_Delete(void)

{
  return 1;
}


/* __stdcall daVrbox_solidHeapCB(fopAc_ac_c *) */

undefined4 daVrbox_solidHeapCB(vrbox_class *param_1)

{
  J3DModelData *pModel;
  ulong uVar1;
  J3DModel *pJVar2;
  undefined4 uVar3;
  
  pModel = (J3DModelData *)
           dRes_control_c::getRes
                     ("Stage","vr_sky.bdl",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,
                      0x40);
  if (pModel == (J3DModelData *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_a_vrbox.cpp",0x1d5,"modelData != 0");
    m_Do_printf::OSPanic("d_a_vrbox.cpp",0x1d5,"Halt");
  }
  pJVar2 = m_Do_ext::mDoExt_J3DModel__create(pModel,0x80000,0x11020202);
  param_1->mpModel = pJVar2;
  uVar3 = 0;
  if ((pModel != (J3DModelData *)0x0) && (param_1->mpModel != (J3DModel *)0x0)) {
    uVar3 = 1;
  }
  return uVar3;
}


/* __stdcall daVrbox_Create(fopAc_ac_c *) */

undefined4 daVrbox_Create(vrbox_class *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (((param_1->parent).mCondition & Constructed) == 0) {
    if (param_1 != (vrbox_class *)0x0) {
      fopAc_ac_c::fopAc_ac_c(&param_1->parent);
    }
    (param_1->parent).mCondition = (param_1->parent).mCondition | Constructed;
  }
  param_1->field_0x29c = 0;
  uVar2 = 4;
  uVar1 = f_op_actor_mng::fopAcM_entrySolidHeap(&param_1->parent,daVrbox_solidHeapCB,0xc60);
  if ((uVar1 & 0xff) == 0) {
    uVar2 = 5;
  }
  else {
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVrboxFlags =
         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVrboxFlags | 1;
    d_kankyo::g_env_light.mbVrboxInvisible = 0;
  }
  return uVar2;
}

