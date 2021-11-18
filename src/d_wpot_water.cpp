#include <d_wpot_water.h>
#include <gx/GXTev.h>
#include <gx/GXPixel.h>
#include <J3DGraphBase/J3DDrawBuffer.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <f_op_kankyo_mng.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <SComponent/c_bg_s.h>
#include <d_bg_s.h>
#include <f_op_actor_mng.h>
#include <d_particle.h>
#include <SComponent/c_bg_s_chk.h>
#include <JKernel/JKRHeap.h>
#include <d_wpot_water.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dWpotWater_EcallBack.h>


namespace d_wpot_water {
}

namespace dWpotWater_c {
undefined1 mEcallback;
}

/* __thiscall dWpotWater_EcallBack::draw(JPABaseEmitter *) */

dWpotWater_EcallBack * __thiscall
dWpotWater_EcallBack::draw(dWpotWater_EcallBack *this,JPABaseEmitter *param_1)

{
  if (((param_1->mDraw).field_0xc2 & 1) != 0) {
    gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_AND,GX_ALWAYS,0);
    gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_DSTALPHA,GX_BL_INVDSTALPHA,GX_LO_CLEAR);
    gx::GXSetZMode(false,GX_LEQUAL,false);
    gx::GXSetZCompLoc(0);
    gx::GXSetColorUpdate(false);
    this = (dWpotWater_EcallBack *)gx::GXSetAlphaUpdate(1);
  }
  return this;
}


namespace d_wpot_water {

/* __stdcall dWpotWater_Draw(dWpotWater_c *) */

undefined4 dWpotWater_Draw(int param_1)

{
  J3DDrawBuffer::entryImm
            (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu,
             (J3DPacket *)(param_1 + 0xfc),0);
  return 1;
}


/* __stdcall dWpotWater_Execute(dWpotWater_c *) */

undefined4 dWpotWater_Execute(int param_1)

{
  bool bVar1;
  int iVar2;
  
  mtx::PSMTXTrans((double)*(float *)(param_1 + 0xdc),(double)(_4143 + *(float *)(param_1 + 0xe0)),
                  (double)*(float *)(param_1 + 0xe4),&mDoMtx_stack_c::now);
  mDoMtx_stack_c::scaleM(_4144,_4145,_4144);
  mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,&mDoMtx_stack_c::now,(MTX34 *)(param_1 + 0x10c)
                  );
  iVar2 = *(int *)(param_1 + 0xf8);
  bVar1 = false;
  if ((*(uint *)(iVar2 + 0x20c) & 8) != 0) {
    if (*(int *)(iVar2 + 0x184) + *(int *)(iVar2 + 400) == 0) {
      bVar1 = true;
    }
  }
  if (bVar1) {
    *(uint *)(iVar2 + 0x20c) = *(uint *)(iVar2 + 0x20c) & 0xffffffbf;
    f_op_kankyo_mng::fopKyM_Delete(param_1);
  }
  return 1;
}


/* __stdcall dWpotWater_IsDelete(dWpotWater_c *) */

undefined4 dWpotWater_IsDelete(void)

{
  return 1;
}


/* __stdcall dWpotWater_Delete(dWpotWater_c *) */

undefined4 dWpotWater_Delete(void)

{
  return 1;
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* WARNING: Removing unreachable block (ram,0x8023ffa4) */
/* WARNING: Removing unreachable block (ram,0x8023ff94) */
/* WARNING: Removing unreachable block (ram,0x8023ff84) */
/* WARNING: Removing unreachable block (ram,0x8023ff8c) */
/* WARNING: Removing unreachable block (ram,0x8023ff9c) */
/* WARNING: Removing unreachable block (ram,0x8023ffac) */
/* __stdcall dWpotWater_Create(kankyo_class *) */

undefined4 dWpotWater_Create(int param_1)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  JPABaseEmitter *pJVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  cBgS_PolyInfo *pcVar8;
  cBgS_PolyPassChk *pcVar9;
  cBgS_PolyPassChk *pcVar10;
  undefined4 uVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  undefined8 in_f26;
  double dVar15;
  undefined8 in_f27;
  undefined8 in_f28;
  double dVar16;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar17;
  undefined8 in_f31;
  cXyz local_188;
  cXyz local_17c;
  float local_170;
  float local_16c;
  float local_168;
  cBgS_GndChk local_164;
  cBgS_PolyPassChk local_124;
  undefined local_118 [8];
  cBgS_GndChk local_110;
  cBgS_PolyPassChk local_d0;
  undefined local_c4 [12];
  undefined4 local_b8;
  uint uStack180;
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  ::cBgS_GndChk::cBgS_GndChk(&local_110);
  pcVar10 = &local_d0;
  local_d0.mbObjThrough = 0;
  local_d0.mbCamThrough = 0;
  local_d0.mbLinkThrough = 0;
  local_d0.mbArrowsAndLightThrough = 0;
  local_d0.mbBombThrough = 0;
  local_d0.mbBoomerangThrough = 0;
  local_d0.mbHookshotThrough = 0;
  local_c4._4_4_ = 1;
  local_110.parent.vtbl = &::dBgS_GndChk::__vt;
  local_110.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371f08;
  local_d0.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_c4._0_4_ = &PTR_80371f20;
  local_110.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar10;
  if (pcVar10 != (cBgS_PolyPassChk *)0x0) {
    local_110.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_c4;
  }
  local_110.parent.mpPolyPassChk = pcVar10;
  ::cBgS_GndChk::cBgS_GndChk(&local_164);
  pcVar9 = &local_124;
  local_124.mbCamThrough = 0;
  local_124.mbLinkThrough = 0;
  local_124.mbArrowsAndLightThrough = 0;
  local_124.mbBombThrough = 0;
  local_124.mbBoomerangThrough = 0;
  local_124.mbHookshotThrough = 0;
  local_164.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar9;
  if (pcVar9 != (cBgS_PolyPassChk *)0x0) {
    local_164.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_118;
  }
  local_124.mbObjThrough = 1;
  local_164.parent.vtbl = (cBgS_Chk__vtbl *)&dBgS_ObjGndChk_Yogan::__vt;
  local_164.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_80371e60;
  local_124.vtbl = (cBgS_PolyPassChk__vtbl *)&DAT_80371e6c;
  local_118._0_4_ = (undefined **)&DAT_80371e78;
  local_118._4_4_ = 4;
  uVar7 = 0;
  uVar6 = 0;
  pcVar8 = &local_164.mPolyInfo;
  dVar17 = (double)_4474;
  dVar15 = (double)_4145;
  dVar16 = (double)_4475;
  dVar14 = _4478;
  local_164.parent.mpPolyPassChk = pcVar9;
  do {
    uStack180 = uVar6 ^ 0x80000000;
    local_b8 = 0x43300000;
    fVar1 = (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack180) - dVar14));
    iVar3 = (int)(uVar7 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
    local_168 = *(float *)(param_1 + 0xe4) + fVar1 * JKernel::JMath::jmaSinTable[iVar3];
    local_16c = (float)(dVar15 + (double)*(float *)(param_1 + 0xe0));
    local_170 = *(float *)(param_1 + 0xdc) + fVar1 * JKernel::JMath::jmaCosTable[iVar3];
    local_164.mPos.x = local_170;
    local_164.mPos.y = local_16c;
    local_164.mPos.z = local_168;
    dVar12 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_164)
    ;
    if (dVar16 != dVar12) {
      local_110.mPos.x = local_170;
      local_110.mPos.y = local_16c;
      local_110.mPos.z = local_168;
      dVar13 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                         &local_110);
      if ((local_164.mPolyInfo.mTriIdx == -1) || (local_164.mPolyInfo.mBgIndex == 0x100)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (((bVar2) &&
          (iVar3 = dBgS::GetAttributeCode(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,pcVar8),
          iVar3 == 6)) && (dVar13 < dVar12)) {
        local_17c.x = local_170;
        local_17c.y = (float)((double)_4476 + dVar12);
        local_17c.z = local_168;
        f_op_actor_mng::fopAcM_create
                  (0x2c,0,&local_17c,*(int *)(param_1 + 0xf4),(csXyz *)0x0,(cXyz *)0x0,0xff,
                   (undefined *)0x0);
        goto LAB_8023fad4;
      }
    }
    uVar6 = uVar6 + 1;
    uVar7 = uVar7 + 10000;
    if (0x31 < (int)uVar6) {
LAB_8023fad4:
      local_168 = *(float *)(param_1 + 0xe4);
      local_16c = _4145 + *(float *)(param_1 + 0xe0);
      local_170 = *(float *)(param_1 + 0xdc);
      local_110.mPos.x = local_170;
      local_110.mPos.y = local_16c;
      local_110.mPos.z = local_168;
      dVar14 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                         &local_110);
      *(float *)(param_1 + 0xe0) = (float)dVar14;
      if ((double)_4475 == dVar14) {
        local_124.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
        local_118._0_4_ = &PTR_80371f20;
        if (pcVar9 != (cBgS_PolyPassChk *)0x0) {
          local_124.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
          local_118._0_4_ = &PTR_80371f68;
          if (((undefined *)register0x00000004 != (undefined *)0x118) &&
             (local_118._0_4_ = &::dBgS_GrpPassChk::__vt,
             (undefined *)register0x00000004 != (undefined *)0x118)) {
            local_118._0_4_ = &::cBgS_GrpPassChk::__vt;
          }
          if ((pcVar9 != (cBgS_PolyPassChk *)0x0) &&
             (local_124.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
             pcVar9 != (cBgS_PolyPassChk *)0x0)) {
            local_124.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
          }
        }
        local_164.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
        local_164.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371e90;
        if (pcVar8 != (cBgS_PolyInfo *)0x0) {
          local_164.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
        }
        cBgS_Chk::_cBgS_Chk(&local_164.parent);
        local_d0.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
        local_c4._0_4_ = &PTR_80371f20;
        if (pcVar10 != (cBgS_PolyPassChk *)0x0) {
          local_d0.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
          local_c4._0_4_ = &PTR_80371f68;
          if (((undefined *)register0x00000004 != (undefined *)0xc4) &&
             (local_c4._0_4_ = &::dBgS_GrpPassChk::__vt,
             (undefined *)register0x00000004 != (undefined *)0xc4)) {
            local_c4._0_4_ = &::cBgS_GrpPassChk::__vt;
          }
          if ((pcVar10 != (cBgS_PolyPassChk *)0x0) &&
             (local_d0.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
             pcVar10 != (cBgS_PolyPassChk *)0x0)) {
            local_d0.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
          }
        }
        local_110.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
        local_110.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
        cBgS_Chk::_cBgS_Chk(&local_110.parent);
        uVar5 = 5;
      }
      else {
        local_188.z = *(float *)(param_1 + 0xe4);
        local_188.y = *(float *)(param_1 + 0xe0);
        local_188.x = *(float *)(param_1 + 0xdc);
        f_op_actor_mng::fopAcM_create
                  (0xb8,0,&local_188,*(int *)(param_1 + 0xf4),(csXyz *)0x0,(cXyz *)0x0,0xff,
                   (undefined *)0x0);
        if (param_1 != 0) {
          *(undefined ***)(param_1 + 0xfc) = &J3DPacket::__vt;
          *(undefined4 *)(param_1 + 0x100) = 0;
          *(undefined4 *)(param_1 + 0x104) = 0;
          *(undefined4 *)(param_1 + 0x108) = 0;
          *(undefined1 **)(param_1 + 0xfc) = &dDlst_alphaVolPacket::__vt;
        }
        dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x8083,
                           (cXyz *)(param_1 + 0xdc),(csXyz *)0x0,(cXyz *)0x0,0xff,
                           (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0)
        ;
        dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x8084,
                           (cXyz *)(param_1 + 0xdc),(csXyz *)0x0,(cXyz *)0x0,0xff,
                           (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0)
        ;
        pJVar4 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x8086,
                                    (cXyz *)(param_1 + 0xdc),(csXyz *)0x0,(cXyz *)0x0,0xaa,
                                    (dPa_levelEcallBack *)&::dWpotWater_c::mEcallback,-1,
                                    (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
        *(JPABaseEmitter **)(param_1 + 0xf8) = pJVar4;
        iVar3 = *(int *)(param_1 + 0xf8);
        if (iVar3 == 0) {
          uVar5 = 5;
        }
        else {
          *(uint *)(iVar3 + 0x20c) = *(uint *)(iVar3 + 0x20c) | 0x40;
          uVar5 = 4;
        }
        local_124.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
        local_118._0_4_ = &PTR_80371f20;
        if (pcVar9 != (cBgS_PolyPassChk *)0x0) {
          local_124.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
          local_118._0_4_ = &PTR_80371f68;
          if (((undefined *)register0x00000004 != (undefined *)0x118) &&
             (local_118._0_4_ = &::dBgS_GrpPassChk::__vt,
             (undefined *)register0x00000004 != (undefined *)0x118)) {
            local_118._0_4_ = &::cBgS_GrpPassChk::__vt;
          }
          if ((pcVar9 != (cBgS_PolyPassChk *)0x0) &&
             (local_124.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
             pcVar9 != (cBgS_PolyPassChk *)0x0)) {
            local_124.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
          }
        }
        local_164.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
        local_164.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371e90;
        if (pcVar8 != (cBgS_PolyInfo *)0x0) {
          local_164.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
        }
        cBgS_Chk::_cBgS_Chk(&local_164.parent);
        local_d0.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
        local_c4._0_4_ = &PTR_80371f20;
        if (pcVar10 != (cBgS_PolyPassChk *)0x0) {
          local_d0.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
          local_c4._0_4_ = &PTR_80371f68;
          if (((undefined *)register0x00000004 != (undefined *)0xc4) &&
             (local_c4._0_4_ = &::dBgS_GrpPassChk::__vt,
             (undefined *)register0x00000004 != (undefined *)0xc4)) {
            local_c4._0_4_ = &::cBgS_GrpPassChk::__vt;
          }
          if ((pcVar10 != (cBgS_PolyPassChk *)0x0) &&
             (local_d0.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
             pcVar10 != (cBgS_PolyPassChk *)0x0)) {
            local_d0.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
          }
        }
        local_110.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
        local_110.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
        cBgS_Chk::_cBgS_Chk(&local_110.parent);
      }
      __psq_l0(auStack8,uVar11);
      __psq_l1(auStack8,uVar11);
      __psq_l0(auStack24,uVar11);
      __psq_l1(auStack24,uVar11);
      __psq_l0(auStack40,uVar11);
      __psq_l1(auStack40,uVar11);
      __psq_l0(auStack56,uVar11);
      __psq_l1(auStack56,uVar11);
      __psq_l0(auStack72,uVar11);
      __psq_l1(auStack72,uVar11);
      __psq_l0(auStack88,uVar11);
      __psq_l1(auStack88,uVar11);
      return uVar5;
    }
  } while( true );
}

}

/* __thiscall dWpotWater_EcallBack::~dWpotWater_EcallBack(void) */

void __thiscall dWpotWater_EcallBack::_dWpotWater_EcallBack(dWpotWater_EcallBack *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dWpotWater_EcallBack *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined1 **)this = &::dPa_levelEcallBack::__vt, bVar1)) {
      *(undefined1 **)this = &::JPACallBackBase<JPABaseEmitter*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dWpotWater_EcallBack::execute(JPABaseEmitter *) */

void __thiscall dWpotWater_EcallBack::execute(dWpotWater_EcallBack *this,JPABaseEmitter *param_1)

{
  return;
}


/* __thiscall dWpotWater_EcallBack::setup(JPABaseEmitter *,
                                          cXyz const *,
                                          csXyz const *,
                                          signed char) */

void __thiscall
dWpotWater_EcallBack::setup
          (dWpotWater_EcallBack *this,JPABaseEmitter *param_1,cXyz *param_2,csXyz *param_3,
          char param_4)

{
  return;
}


namespace d_wpot_water {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __sinit_d_wpot_water_cpp(void)

{
  _mEcallback = &::dWpotWater_EcallBack::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&::dWpotWater_c::mEcallback,::dWpotWater_EcallBack::_dWpotWater_EcallBack,&_4091);
  return;
}

