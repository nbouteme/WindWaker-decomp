#include <d_a_esa.h>
#include <d_kankyo.h>
#include <m_Do_ext.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <SComponent/c_bg_s.h>
#include <d_a_sea.h>
#include <d_bg_s_func.h>
#include <SComponent/c_bg_s_lin_chk.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <d_bg_s_lin_chk.h>
#include <m_Do_mtx.h>
#include <SComponent/c_lib.h>
#include <SComponent/c_bg_s_chk.h>
#include <SComponent/c_math.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <d_particle.h>
#include <d_a_esa.h>
#include <f_op_actor_mng.h>
#include <d_event_manager.h>
#include <mtx/mtx.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <f_op_actor.h>
#include <f_pc_layer.h>
#include <f_pc_stdcreate_req.h>
#include <cXyz.h>
#include <daPy_py_c.h>


namespace d_a_esa {
undefined4 ripple_scale$4426;
undefined4 ripple_scale$4449;
undefined1 init$4428;
undefined1 init$4451;

/* __stdcall daEsa_Draw(esa_class *) */

undefined4 daEsa_Draw(fopAc_daEsa *param_1)

{
  dScnKy_env_light_c::setLightTevColorType
            (&d_kankyo::g_env_light,param_1->mpModel,&(param_1->parent).mTevStr);
  m_Do_ext::mDoExt_modelUpdateDL(param_1->mpModel);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f14 */
/* WARNING: Inlined function: FUN_80328f60 */
/* __stdcall bg_check(esa_class *) */

void bg_check(fopAc_daEsa *param_1)

{
  uint uVar1;
  char cVar2;
  daEsa_State dVar3;
  cBgS_PolyPassChk *pcVar4;
  cBgS_PolyPassChk *pcVar5;
  double dVar6;
  double dVar7;
  float fVar8;
  cXyz local_164;
  cXyz local_158;
  cXyz cStack332;
  cXyz cStack320;
  cXyz local_134;
  cXyz local_128;
  float local_11c;
  float local_118;
  float local_114;
  cXyz local_110;
  cXyz local_104;
  undefined local_f8 [104];
  uint local_90;
  cBgS_GndChk local_8c;
  cBgS_PolyPassChk local_4c;
  undefined **local_40;
  undefined4 local_3c;
  
  ::cBgS_GndChk::cBgS_GndChk(&local_8c);
  pcVar5 = &local_4c;
  local_4c.mbObjThrough = 0;
  local_4c.mbCamThrough = 0;
  local_4c.mbLinkThrough = 0;
  local_4c.mbArrowsAndLightThrough = 0;
  local_4c.mbBombThrough = 0;
  local_4c.mbBoomerangThrough = 0;
  local_4c.mbHookshotThrough = 0;
  local_3c = 1;
  local_8c.parent.vtbl = &::dBgS_GndChk::__vt;
  local_8c.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371f08;
  local_4c.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_40 = &PTR_80371f20;
  local_8c.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar5;
  if (pcVar5 != (cBgS_PolyPassChk *)0x0) {
    local_8c.parent.mpGrpPassChk = (cBgS_GrpPassChk *)&local_40;
  }
  local_8c.mPos.z = (param_1->parent).mCurrent.mPos.z;
  local_8c.mPos.y = (param_1->parent).mCurrent.mPos.y + _4313;
  local_8c.mPos.x = (param_1->parent).mCurrent.mPos.x;
  local_8c.parent.mpPolyPassChk = pcVar5;
  dVar7 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_8c);
  param_1->mGroundHeight = (float)((double)_4314 + dVar7);
  dVar3 = BaitOnGround;
  uVar1 = d_a_sea::daSea_ChkArea
                    ((param_1->parent).mCurrent.mPos.x,(param_1->parent).mCurrent.mPos.z);
  if (((uVar1 & 0xff) != 0) &&
     (dVar7 = (double)d_a_sea::daSea_calcWave
                                ((double)(param_1->parent).mCurrent.mPos.x,
                                 (double)(param_1->parent).mCurrent.mPos.z),
     (double)param_1->mGroundHeight <= dVar7)) {
    param_1->mGroundHeight = (float)dVar7;
    dVar3 = BaitOnWater;
  }
  local_11c = (param_1->parent).mCurrent.mPos.x;
  local_114 = (param_1->parent).mCurrent.mPos.z;
  local_118 = (param_1->parent).mCurrent.mPos.y + _4313;
  dVar7 = (double)d_bg_s_func::dBgS_GetWaterHeight(&local_11c);
  if (((double)_4315 != dVar7) && ((double)param_1->mGroundHeight <= dVar7)) {
    param_1->mGroundHeight = (float)dVar7;
    dVar3 = BaitOnWater;
  }
  if ((param_1->parent).mVelocity.y <= _4316) {
    if ((param_1->parent).mCurrent.mPos.y <= param_1->mGroundHeight) {
      (param_1->parent).mCurrent.mPos.y = param_1->mGroundHeight;
      param_1->mState = dVar3;
      goto LAB_800e8084;
    }
  }
  param_1->mState = BaitInAir;
LAB_800e8084:
  local_f8._0_4_ = (cBgS_PolyPassChk *)0x0;
  local_f8._4_4_ = (cBgS_PolyPassChk *)0x0;
  local_f8[12] = true;
  local_f8._20_2_ = -1;
  local_f8._22_2_ = 0x100;
  local_f8._24_4_ = (cBgW *)0x0;
  local_f8._28_4_ = -1;
  local_f8._16_4_ = &::cBgS_LinChk::__vt;
  local_f8._32_4_ = &PTR_80371fbc;
  local_f8._60_4_ = &::cM3dGLin::__vt;
  ::cBgS_LinChk::ct((cBgS_LinChk *)local_f8);
  pcVar4 = (cBgS_PolyPassChk *)(local_f8 + 0x58);
  local_f8[92] = 0;
  local_f8[93] = 0;
  local_f8[94] = 0;
  local_f8[95] = 0;
  local_f8[96] = 0;
  local_f8[97] = 0;
  local_f8[98] = 0;
  local_90 = 1;
  local_f8._16_4_ = &::dBgS_LinChk::__vt;
  local_f8._32_4_ = (undefined **)&DAT_80371f38;
  local_f8._88_4_ = &PTR_80371f44;
  local_f8._100_4_ = &PTR_80371f50;
  local_f8._4_4_ = pcVar4;
  if (pcVar4 != (cBgS_PolyPassChk *)0x0) {
    local_f8._4_4_ = (cBgS_PolyPassChk *)(local_f8 + 100);
  }
  local_f8._0_4_ = pcVar4;
  ::cXyz::operator__(&cStack320,&(param_1->parent).mCurrent.mPos,&(param_1->parent).mNext.mPos);
  ::cXyz::operator_(&cStack332,&cStack320,_4317);
  ::cXyz::operator__(&local_158,&(param_1->parent).mNext.mPos,&cStack332);
  local_128.x = local_158.x;
  local_128.z = local_158.z;
  local_128.y = (param_1->parent).mNext.mPos.y;
  ::cXyz::operator__(&local_164,&(param_1->parent).mNext.mPos,&local_128);
  local_134.x = local_164.x;
  local_134.y = local_164.y;
  local_134.z = local_164.z;
  fVar8 = mtx::PSVECSquareMag(&local_134);
  dVar7 = (double)fVar8;
  if ((double)_4316 < dVar7) {
    dVar6 = 1.0 / SQRT(dVar7);
    dVar6 = _4318 * dVar6 * (_4319 - dVar7 * dVar6 * dVar6);
    dVar6 = _4318 * dVar6 * (_4319 - dVar7 * dVar6 * dVar6);
    dVar7 = (double)(float)(dVar7 * _4318 * dVar6 * (_4319 - dVar7 * dVar6 * dVar6));
  }
  if (dVar7 <= (double)_4320) {
    (param_1->parent).mStatus = (param_1->parent).mStatus & 0xffffbfff;
  }
  else {
    ::dBgS_LinChk::Set((dBgS_LinChk *)local_f8,&(param_1->parent).mNext.mPos,&local_128,
                       &param_1->parent);
    cVar2 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                            (cBgS_LinChk *)local_f8);
    if (cVar2 != '\0') {
      (param_1->parent).mCurrent.mPos.x = (param_1->parent).mNext.mPos.x;
      (param_1->parent).mCurrent.mPos.z = (param_1->parent).mNext.mPos.z;
      (param_1->parent).mVelocityFwd = (param_1->parent).mVelocityFwd * _4321;
      (param_1->parent).mCurrent.mRot.y = (param_1->parent).mCurrent.mRot.y + -0x8000;
      local_104.x = _4316;
      local_104.y = _4316;
      local_104.z = (param_1->parent).mVelocityFwd;
      m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)(param_1->parent).mCurrent.mRot.y);
      SComponent::MtxPosition(&local_104,&local_110);
      (param_1->parent).mVelocity.x = local_110.x;
      (param_1->parent).mVelocity.z = local_110.z;
    }
  }
  local_f8._88_4_ = &PTR_80371f44;
  local_f8._100_4_ = &PTR_80371f50;
  if (pcVar4 != (cBgS_PolyPassChk *)0x0) {
    local_f8._88_4_ = &::dBgS_Chk::__vt;
    local_f8._100_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x94) &&
       (local_f8._100_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x94)) {
      local_f8._100_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar4 != (cBgS_PolyPassChk *)0x0) &&
       (local_f8._88_4_ = &::dBgS_PolyPassChk::__vt, pcVar4 != (cBgS_PolyPassChk *)0x0)) {
      local_f8._88_4_ = &::cBgS_PolyPassChk::__vt;
    }
  }
  local_f8._16_4_ = &::cBgS_LinChk::__vt;
  local_f8._60_4_ = &::cM3dGLin::__vt;
  local_f8._32_4_ = &::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk((cBgS_Chk *)local_f8);
  local_4c.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_40 = &PTR_80371f20;
  if (pcVar5 != (cBgS_PolyPassChk *)0x0) {
    local_4c.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_40 = &PTR_80371f68;
    if (((undefined *)register0x00000004 != &DAT_00000040) &&
       (local_40 = &::dBgS_GrpPassChk::__vt, (undefined *)register0x00000004 != &DAT_00000040)) {
      local_40 = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar5 != (cBgS_PolyPassChk *)0x0) &&
       (local_4c.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar5 != (cBgS_PolyPassChk *)0x0)) {
      local_4c.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_8c.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_8c.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_8c.parent);
  return;
}


/* __stdcall esa_1_move(esa_class *) */

void esa_1_move(fopAc_daEsa *param_1)

{
  daEsa_ActionState dVar1;
  int startCheckStatus;
  double dVar2;
  float fVar3;
  cXyz local_38;
  cXyz local_2c;
  longlong local_20;
  longlong local_18;
  
  dVar1 = param_1->mActionState;
  if (dVar1 == ActionState_OnGround) {
    if (param_1->mEventTimer[0] == 0) {
      f_op_actor_mng::fopAcM_delete((base_process_class *)param_1);
    }
  }
  else {
    if ((char)dVar1 < '\x02') {
      if (dVar1 == ActionState_InitialState) {
        fVar3 = SComponent::cM_rndFX(_4485);
        local_20 = (longlong)(int)fVar3;
        (param_1->parent).mCurrent.mRot.y = (param_1->parent).mCurrent.mRot.y + (short)(int)fVar3;
        fVar3 = SComponent::cM_rndFX(_4486);
        local_18 = (longlong)(int)fVar3;
        (param_1->parent).mCurrent.mRot.z = (short)(int)fVar3;
        local_2c.x = _4316;
        local_2c.y = SComponent::cM_rndF(_4488);
        local_2c.y = _4487 + local_2c.y;
        local_2c.z = SComponent::cM_rndF(_4314);
        local_2c.z = _4489 + local_2c.z;
        (param_1->parent).mVelocityFwd = local_2c.z;
        m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)(param_1->parent).mCurrent.mRot.y);
        SComponent::MtxPosition(&local_2c,&(param_1->parent).mVelocity);
        param_1->mActionState = ActionState_InAir;
      }
      else {
        if ((char)dVar1 < '\0') {
          return;
        }
      }
      if (param_1->mState != BaitInAir) {
        if (param_1->mState == BaitOnWater) {
          fVar3 = SComponent::cM_rndF(_4491);
          local_18 = (longlong)(int)(_4490 + fVar3);
          param_1->mEventTimer[0] = (short)(int)(_4490 + fVar3);
          param_1->mActionState = ActionState_OnWater;
          if (param_1->field_0x2a8 == 0) {
            if (init_4428 == '\0') {
              ripple_scale_4426 = _4492;
              DAT_803e4134 = _4492;
              DAT_803e4138 = _4492;
              Runtime.PPCEABI.H::__register_global_object(&ripple_scale_4426,::cXyz::_cXyz,&_4427);
              init_4428 = '\x01';
            }
            dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,5,0x33,
                               &(param_1->parent).mCurrent.mPos,(csXyz *)0x0,
                               (cXyz *)&ripple_scale_4426,0xff,&param_1->mdPa_levelEcallBack,-1,
                               (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
            if (param_1->field_0x2a8 != 0) {
              param_1->field_0x2b4 = _4493;
            }
          }
        }
        else {
          if ((param_1->parent).mVelocity.y < _4314) {
            fVar3 = SComponent::cM_rndF(_4495);
            (param_1->parent).mVelocity.y = (param_1->parent).mVelocity.y * -(_4494 + fVar3);
            fVar3 = SComponent::cM_rndFX(_4486);
            local_18 = (longlong)(int)fVar3;
            (param_1->parent).mCurrent.mRot.z = (short)(int)fVar3;
          }
          fVar3 = SComponent::cM_rndFX(_4496);
          local_18 = (longlong)(int)fVar3;
          (param_1->parent).mCurrent.mRot.y = (param_1->parent).mCurrent.mRot.y + (short)(int)fVar3;
          fVar3 = SComponent::cM_rndF(_4497);
          (param_1->parent).mVelocityFwd = (param_1->parent).mVelocityFwd * (_4497 + fVar3);
          local_2c.x = _4316;
          local_2c.y = _4316;
          local_2c.z = (param_1->parent).mVelocityFwd;
          m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)(param_1->parent).mCurrent.mRot.y);
          SComponent::MtxPosition(&local_2c,&local_38);
          (param_1->parent).mVelocity.x = local_38.x;
          (param_1->parent).mVelocity.z = local_38.z;
          if ((param_1->parent).mVelocityFwd < _4498) {
            param_1->mActionState = ActionState_OnGround;
            fVar3 = SComponent::cM_rndF(_4491);
            param_1->mEventTimer[0] = (short)(int)(_4490 + fVar3);
            return;
          }
        }
      }
      (param_1->parent).mCurrent.mPos.x =
           (param_1->parent).mCurrent.mPos.x + (param_1->parent).mVelocity.x;
      (param_1->parent).mCurrent.mPos.y =
           (param_1->parent).mCurrent.mPos.y + (param_1->parent).mVelocity.y;
      (param_1->parent).mCurrent.mPos.z =
           (param_1->parent).mCurrent.mPos.z + (param_1->parent).mVelocity.z;
      (param_1->parent).mVelocity.y = (param_1->parent).mVelocity.y - _4499;
      bg_check(param_1);
    }
    else {
      if (dVar1 == ActionState_Destroy) {
        if (param_1->mEventTimer[0] == 0) {
          f_op_actor_mng::fopAcM_delete((base_process_class *)param_1);
        }
      }
      else {
        if ((char)dVar1 < '\x04') {
          startCheckStatus =
               dEvent_manager_c::startCheckOld
                         (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"SO_ESA_XY");
          if (startCheckStatus != 0) {
            param_1->mEventTimer[0] = 10000;
          }
          dPa_rippleEcallBack::end((dPa_rippleEcallBack *)&param_1->mdPa_levelEcallBack);
          dVar2 = (double)d_a_sea::daSea_calcWave
                                    ((double)(param_1->parent).mCurrent.mPos.x,
                                     (double)(param_1->parent).mCurrent.mPos.z);
          (param_1->parent).mCurrent.mPos.y = (float)dVar2;
          if (param_1->mEventTimer[0] == 0) {
            param_1->mEventTimer[0] = 10;
            param_1->mActionState = ActionState_Destroy;
          }
          if (param_1->field_0x298 != '\0') {
            param_1->mEventTimer[0] = 10;
            param_1->mActionState = ActionState_Destroy;
            if (param_1->field_0x2a8 == 0) {
              if (init_4451 == '\0') {
                ripple_scale_4449 = _4492;
                DAT_803e414c = _4492;
                DAT_803e4150 = _4492;
                Runtime.PPCEABI.H::__register_global_object(&ripple_scale_4449,::cXyz::_cXyz,&_4450)
                ;
                init_4451 = '\x01';
              }
              dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,5,0x33,
                                 &(param_1->parent).mCurrent.mPos,(csXyz *)0x0,
                                 (cXyz *)&ripple_scale_4449,0xff,&param_1->mdPa_levelEcallBack,-1,
                                 (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
              if (param_1->field_0x2a8 != 0) {
                param_1->field_0x2b4 = _4493;
              }
            }
          }
        }
      }
    }
  }
  return;
}


/* __stdcall daEsa_Execute(esa_class *) */

undefined4 daEsa_Execute(fopAc_daEsa *param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 2;
  do {
    sVar1 = *(short *)((int)param_1->mEventTimer + iVar2);
    if (sVar1 != 0) {
      *(short *)((int)param_1->mEventTimer + iVar2) = sVar1 + -1;
    }
    iVar2 = iVar2 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  esa_1_move(param_1);
  SComponent::MtxTrans
            ((double)(param_1->parent).mCurrent.mPos.x,(double)(param_1->parent).mCurrent.mPos.y,
             (double)(param_1->parent).mCurrent.mPos.z,false);
  m_Do_mtx::mDoMtx_YrotM(SComponent::calc_mtx,(param_1->parent).mCurrent.mRot.y);
  m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,(param_1->parent).mCurrent.mRot.x);
  m_Do_mtx::mDoMtx_ZrotM(SComponent::calc_mtx,(param_1->parent).mCurrent.mRot.z);
  mtx::PSMTXCopy(SComponent::calc_mtx,&param_1->mpModel->mBaseMtx);
  dScnKy_env_light_c::settingTevStruct
            (&d_kankyo::g_env_light,Actor,&(param_1->parent).mCurrent.mPos,
             &(param_1->parent).mTevStr);
  return 1;
}


/* __stdcall daEsa_IsDelete(esa_class *) */

undefined4 daEsa_IsDelete(void)

{
  return 1;
}


/* __stdcall daEsa_Delete(esa_class *) */

undefined4 daEsa_Delete(fopAc_daEsa *param_1)

{
  dPa_rippleEcallBack::end((dPa_rippleEcallBack *)&param_1->mdPa_levelEcallBack);
  return 1;
}


/* __stdcall daEsa_CreateHeap(fopAc_ac_c *) */

bool daEsa_CreateHeap(fopAc_daEsa *param_1)

{
  J3DModelData *pModel;
  ulong uVar1;
  J3DModel *pJVar2;
  
  pModel = (J3DModelData *)
           dRes_control_c::getRes
                     ("Link",0x2c,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pModel == (J3DModelData *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_a_esa.cpp",0x1e8,"modelData != 0");
    m_Do_printf::OSPanic("d_a_esa.cpp",0x1e8,&DAT_8035be12);
  }
  pJVar2 = m_Do_ext::mDoExt_J3DModel__create(pModel,0x80000,0x11000022);
  param_1->mpModel = pJVar2;
  return param_1->mpModel != (J3DModel *)0x0;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x800e8c84) */
/* __stdcall daEsa_Create(fopAc_ac_c *) */

undefined4 daEsa_Create(fopAc_daEsa *param_1)

{
  char cVar1;
  daPy_lk_c *this;
  uint uVar2;
  undefined4 uVar3;
  fopAcM_prm_class *pfVar4;
  layer_class *plVar5;
  J3DModel *pJVar6;
  int iVar7;
  undefined4 uVar8;
  undefined8 in_f31;
  double dVar9;
  float fVar10;
  cXyz local_58 [2];
  float local_40;
  float local_3c;
  float local_38;
  longlong local_30;
  undefined auStack8 [8];
  
  this = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (((param_1->parent).mCondition & Constructed) == 0) {
    if (param_1 != (fopAc_daEsa *)0x0) {
      fopAc_ac_c::fopAc_ac_c(&param_1->parent);
      (param_1->mdPa_levelEcallBack).vtbl =
           (dPa_levelEcallBack__vtbl *)&::JPACallBackBase<JPABaseEmitter*>::__vt;
      (param_1->mdPa_levelEcallBack).vtbl = (dPa_levelEcallBack__vtbl *)&::dPa_levelEcallBack::__vt;
      (param_1->mdPa_levelEcallBack).vtbl = (dPa_levelEcallBack__vtbl *)&dPa_rippleEcallBack::__vt;
      param_1->field_0x2a8 = 0;
    }
    (param_1->parent).mCondition = (param_1->parent).mCondition | Constructed;
  }
  param_1->field_0x2b9 = (char)(param_1->parent).parent.parent.mParameters;
  param_1->field_0x2ba = (char)((uint)(param_1->parent).parent.parent.mParameters >> 8);
  if (d_s_play::g_regHIO.mChild[0].mShorts[0] != 0) {
    param_1->field_0x2ba = '\x01';
  }
  uVar2 = f_op_actor_mng::fopAcM_entrySolidHeap(&param_1->parent,daEsa_CreateHeap,0x4c0);
  if ((uVar2 & 0xff) == 0) {
    uVar3 = 5;
  }
  else {
    if ((param_1->field_0x2ba == '\0') && (cVar1 = param_1->field_0x2b9, 0 < cVar1)) {
      for (iVar7 = 0; iVar7 < cVar1; iVar7 = iVar7 + 1) {
        pfVar4 = f_op_actor_mng::fopAcM_CreateAppend();
        ::daPy_py_c::getLeftHandPos(local_58,&this->parent);
        local_40 = local_58[0].x;
        local_3c = local_58[0].y;
        local_38 = local_58[0].z;
        (pfVar4->mPos).x = local_58[0].x;
        (pfVar4->mPos).y = local_58[0].y;
        (pfVar4->mPos).z = local_58[0].z;
        (pfVar4->mRot).x = 0;
        (pfVar4->mRot).y = (param_1->parent).mCurrent.mRot.y;
        fVar10 = SComponent::cM_rndF(_4627);
        local_30 = (longlong)(int)fVar10;
        (pfVar4->mRot).z = (short)(int)fVar10;
        pfVar4->mParameters = 0xff;
        plVar5 = f_pc_layer::fpcLy_CurrentLayer();
        f_pc_stdcreate_req::fpcSCtRq_Request(plVar5,0xde,(undefined *)0x0,(void *)0x0,pfVar4);
      }
    }
    dVar9 = (double)(_4628 + d_s_play::g_regHIO.mChild[0].mFloats[6]);
    fVar10 = SComponent::cM_rndF((float)((double)(_4320 + d_s_play::g_regHIO.mChild[0].mFloats[5]) -
                                        dVar9));
    fVar10 = (float)(dVar9 + (double)fVar10);
    pJVar6 = param_1->mpModel;
    (pJVar6->mBaseScale).x = fVar10;
    (pJVar6->mBaseScale).y = fVar10;
    (pJVar6->mBaseScale).z = fVar10;
    (param_1->parent).mpCullMtx = &param_1->mpModel->mBaseMtx;
    uVar3 = 4;
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  return uVar3;
}

}

/* __thiscall daPy_py_c::getLeftHandPos(void) const */

cXyz * __thiscall daPy_py_c::getLeftHandPos(cXyz *__return_storage_ptr__,daPy_py_c *this)

{
  __return_storage_ptr__->x = (this->field_0x2d4).x;
  __return_storage_ptr__->y = (this->field_0x2d4).y;
  __return_storage_ptr__->z = (this->field_0x2d4).z;
  return __return_storage_ptr__;
}

