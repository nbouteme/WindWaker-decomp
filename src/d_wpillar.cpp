#include <d_wpillar.h>
#include <mtx/mtx.h>
#include <d_wpillar.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_kankyo.h>
#include <m_Do_ext.h>
#include <f_op_kankyo_mng.h>
#include <f_op_actor_mng.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_particle.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <SComponent/c_bg_s.h>
#include <d_bg_s.h>
#include <SComponent/c_bg_s_chk.h>
#include <dWpillar_c.h>


namespace d_wpillar {
}

/* __thiscall dWpillar_c::jointCallBack(int) */

undefined4 __thiscall dWpillar_c::jointCallBack(dWpillar_c *this,int param_1)

{
  float fVar1;
  MTX34 *pMVar2;
  
  pMVar2 = (MTX34 *)(*(int *)(*(int *)(this + 0xf8) + 0x8c) + param_1 * 0x30);
  fVar1 = *(float *)(this + 0xe0) +
          *(float *)(this + 0xe8) * *(float *)(&DAT_80363ad4 + param_1 * 4);
  pMVar2->m[1][3] = fVar1 + *(float *)(this + 0x1d4) * (pMVar2->m[1][3] - fVar1);
  mtx::PSMTXCopy(pMVar2,&J3DSys::mCurrentMtx);
  return 1;
}


namespace d_wpillar {

/* __stdcall dWpillar_jointCallBack(J3DNode *,
                                    int) */

undefined4 dWpillar_jointCallBack(int param_1,int param_2)

{
  if (param_2 == 0) {
    ::dWpillar_c::jointCallBack
              ((dWpillar_c *)(J3DGraphBase::j3dSys.mpCurModel)->mpUserData,
               (uint)*(ushort *)(param_1 + 0x18));
  }
  return 1;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dWpillar_c::draw(void) */

undefined4 __thiscall dWpillar_c::draw(dWpillar_c *this)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined local_88;
  undefined local_87;
  undefined local_86;
  ushort local_84;
  ushort local_82;
  ushort local_80;
  undefined4 local_78;
  uint uStack116;
  longlong local_70;
  undefined4 local_68;
  uint uStack100;
  longlong local_60;
  undefined4 local_58;
  uint uStack84;
  longlong local_50;
  undefined4 local_48;
  uint uStack68;
  longlong local_40;
  undefined4 local_38;
  uint uStack52;
  longlong local_30;
  undefined4 local_28;
  uint uStack36;
  longlong local_20;
  
  dScnKy_env_light_c::settingTevStruct
            (&d_kankyo::g_env_light,BG1,(cXyz *)(this + 0xdc),(dKy_tevstr_c *)(this + 0x124));
  dScnKy_env_light_c::setLightTevColorType
            (&d_kankyo::g_env_light,*(J3DModel **)(this + 0xf8),(dKy_tevstr_c *)(this + 0x124));
  ::mDoExt_bckAnm::entry
            ((mDoExt_bckAnm *)(this + 0xfc),*(J3DModelData **)(*(int *)(this + 0xf8) + 4),
             *(float *)(*(int *)(this + 0x100) + 0x10));
  if (*(int *)(this + 0xf4) == 1) {
    uVar1 = (uint)*(ushort *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x5c);
    while (uVar1 = uVar1 - 1, -1 < (int)uVar1) {
      piVar2 = *(int **)(*(int *)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x60) +
                                 (uVar1 * 4 & 0x3fffc)) + 0x2c);
      (**(code **)(*piVar2 + 0x60))(piVar2,2,&d_wpillar::calc_col_4179);
    }
    *(undefined4 *)((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->mpGwp00BrkData + 8) =
         *(undefined4 *)(*(int *)(this + 0x100) + 0x10);
    ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->mpGwp00BtkData->parent).mCurrentTime =
         *(float *)(*(int *)(this + 0x100) + 0x10);
  }
  else {
    uStack116 = (int)*(short *)(this + 0x1a4) ^ 0x80000000;
    local_78 = 0x43300000;
    iVar3 = (int)(d_wpillar::_4263 +
                 d_wpillar::_4264 *
                 (float)((double)CONCAT44(0x43300000,uStack116) - d_wpillar::_4268));
    local_70 = (longlong)iVar3;
    local_84 = (ushort)iVar3 & 0xff;
    uStack100 = (int)*(short *)(this + 0x1a6) ^ 0x80000000;
    local_68 = 0x43300000;
    iVar3 = (int)(d_wpillar::_4263 +
                 d_wpillar::_4264 *
                 (float)((double)CONCAT44(0x43300000,uStack100) - d_wpillar::_4268));
    local_60 = (longlong)iVar3;
    local_82 = (ushort)iVar3 & 0xff;
    uStack84 = (int)*(short *)(this + 0x1a8) ^ 0x80000000;
    local_58 = 0x43300000;
    iVar3 = (int)(d_wpillar::_4263 +
                 d_wpillar::_4264 *
                 (float)((double)CONCAT44(0x43300000,uStack84) - d_wpillar::_4268));
    local_50 = (longlong)iVar3;
    local_80 = (ushort)iVar3 & 0xff;
    uStack68 = (uint)(byte)this[0x1ac];
    local_48 = 0x43300000;
    iVar3 = (int)(d_wpillar::_4265 +
                 d_wpillar::_4266 *
                 (float)((double)CONCAT44(0x43300000,uStack68) - d_wpillar::_4275));
    local_40 = (longlong)iVar3;
    local_88 = (undefined)iVar3;
    uStack52 = (uint)(byte)this[0x1ad];
    local_38 = 0x43300000;
    iVar3 = (int)(d_wpillar::_4265 +
                 d_wpillar::_4266 *
                 (float)((double)CONCAT44(0x43300000,uStack52) - d_wpillar::_4275));
    local_30 = (longlong)iVar3;
    local_87 = (undefined)iVar3;
    uStack36 = (uint)(byte)this[0x1ae];
    local_28 = 0x43300000;
    iVar3 = (int)(d_wpillar::_4265 +
                 d_wpillar::_4266 *
                 (float)((double)CONCAT44(0x43300000,uStack36) - d_wpillar::_4275));
    local_20 = (longlong)iVar3;
    local_86 = (undefined)iVar3;
    ::mDoExt_btkAnm::entry
              ((mDoExt_btkAnm *)(this + 0x10c),*(J3DModelData **)(*(int *)(this + 0xf8) + 4),
               *(float *)(*(int *)(this + 0x100) + 0x10));
    uVar1 = (uint)*(ushort *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x5c);
    while (uVar1 = uVar1 - 1, -1 < (int)uVar1) {
      iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x60) + (uVar1 * 4 & 0x3fffc))
      ;
      piVar2 = *(int **)(iVar3 + 0x2c);
      (**(code **)(*piVar2 + 0x60))(piVar2,0,&local_84);
      piVar2 = *(int **)(iVar3 + 0x2c);
      (**(code **)(*piVar2 + 0x6c))(piVar2,0,&local_88);
    }
  }
  m_Do_ext::mDoExt_modelUpdateDL(*(J3DModel **)(this + 0xf8));
  return 1;
}


namespace d_wpillar {

/* __stdcall dWpillar_Draw(dWpillar_c *) */

void dWpillar_Draw(dWpillar_c *param_1)

{
  ::dWpillar_c::draw(param_1);
  return;
}

}

/* __thiscall dWpillar_c::execute(void) */

undefined4 __thiscall dWpillar_c::execute(dWpillar_c *this)

{
  bool bVar1;
  uint uVar2;
  float local_18 [5];
  
  ::mDoExt_baseAnm::play((mDoExt_baseAnm *)(this + 0xfc));
  bVar1 = true;
  if ((*(byte *)(*(int *)(this + 0x100) + 5) & 1) == 0) {
    if (d_wpillar::_4311 != *(float *)(*(int *)(this + 0x100) + 0xc)) {
      bVar1 = false;
    }
  }
  if (bVar1) {
    f_op_kankyo_mng::fopKyM_Delete(this);
  }
  else {
    uVar2 = f_op_actor_mng::fopAcM_getWaterY((cXyz *)(this + 0xdc),local_18);
    if (uVar2 != 0) {
      *(float *)(*(int *)(this + 0xf8) + 0x40) = local_18[0];
      *(float *)(this + 0xe0) = local_18[0];
    }
  }
  return 1;
}


namespace d_wpillar {

/* __stdcall dWpillar_Execute(dWpillar_c *) */

void dWpillar_Execute(dWpillar_c *param_1)

{
  ::dWpillar_c::execute(param_1);
  return;
}


/* __stdcall dWpillar_IsDelete(dWpillar_c *) */

undefined4 dWpillar_IsDelete(void)

{
  return 1;
}

}

/* __thiscall dWpillar_c::wp_delete(void) */

undefined4 __thiscall dWpillar_c::wp_delete(dWpillar_c *this)

{
  if (*(int *)(this + 0x120) != 0) {
    m_Do_ext::mDoExt_destroySolidHeap();
  }
  return 1;
}


namespace d_wpillar {

/* __stdcall dWpillar_Delete(dWpillar_c *) */

void dWpillar_Delete(dWpillar_c *param_1)

{
  ::dWpillar_c::wp_delete(param_1);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* __thiscall dWpillar_c::create(void) */

undefined4 __thiscall dWpillar_c::create(dWpillar_c *this)

{
  JKRSolidHeap *pJVar1;
  J3DModelData *pModel;
  ulong uVar2;
  J3DModel *pJVar3;
  J3DAnmTransform *pJVar4;
  uint uVar5;
  J3DAnmTextureSRTKey *pAnm;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  byte roomNo;
  uchar uVar9;
  ushort uVar10;
  cBgS_PolyPassChk *pcVar11;
  double dVar12;
  cBgS_GndChk local_98;
  cBgS_PolyPassChk local_58;
  undefined local_4c [24];
  
  if (this != (dWpillar_c *)0x0) {
    *(undefined ***)(this + 0xfc) = &::mDoExt_baseAnm::__vt;
    *(undefined4 *)(this + 0x100) = 0;
    *(undefined ***)(this + 0xfc) = &::mDoExt_bckAnm::__vt;
    *(undefined4 *)(this + 0x108) = 0;
    *(undefined ***)(this + 0x10c) = &::mDoExt_baseAnm::__vt;
    *(undefined4 *)(this + 0x110) = 0;
    *(undefined ***)(this + 0x10c) = &::mDoExt_btkAnm::__vt;
    *(undefined4 *)(this + 0x118) = 0;
    *(undefined4 *)(this + 0x124) = J3DGraphBase::j3dDefaultLightInfo;
    *(undefined4 *)(this + 0x128) = DAT_80370d1c;
    *(undefined4 *)(this + 300) = DAT_80370d20;
    *(undefined4 *)(this + 0x130) = DAT_80370d24;
    *(undefined4 *)(this + 0x134) = DAT_80370d28;
    *(undefined4 *)(this + 0x138) = DAT_80370d2c;
    this[0x13c] = DAT_80370d30;
    this[0x13d] = DAT_80370d31;
    this[0x13e] = DAT_80370d32;
    this[0x13f] = DAT_80370d33;
    *(undefined4 *)(this + 0x140) = DAT_80370d34;
    *(undefined4 *)(this + 0x144) = DAT_80370d38;
    *(undefined4 *)(this + 0x148) = DAT_80370d3c;
    *(undefined4 *)(this + 0x14c) = DAT_80370d40;
    *(undefined4 *)(this + 0x150) = DAT_80370d44;
    *(undefined4 *)(this + 0x154) = DAT_80370d48;
  }
  pJVar1 = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent(0x3440,0x20);
  *(JKRSolidHeap **)(this + 0x120) = pJVar1;
  if (*(int *)(this + 0x120) == 0) {
    uVar7 = 5;
  }
  else {
    if (*(int *)(this + 0xf4) == 0) {
      pModel = (J3DModelData *)
               dRes_control_c::getRes
                         ("Always",0x3b,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40
                         );
      if (pModel == (J3DModelData *)0x0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_wpillar.cpp",0x125,"modelData != 0");
        m_Do_printf::OSPanic("d_wpillar.cpp",0x125,&DAT_80363b08);
      }
      pJVar3 = m_Do_ext::mDoExt_J3DModel__create(pModel,0x80000,0x11000202);
      *(J3DModel **)(this + 0xf8) = pJVar3;
      pJVar4 = (J3DAnmTransform *)
               dRes_control_c::getRes
                         ("Always",0x16,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40
                         );
      uVar5 = ::mDoExt_bckAnm::init
                        ((mDoExt_bckAnm *)(this + 0xfc),pModel,pJVar4,true,Once,d_wpillar::_4516,0,
                         -1,false);
      pAnm = (J3DAnmTextureSRTKey *)
             dRes_control_c::getRes
                       ("Always",0x5e,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
      uVar6 = ::mDoExt_btkAnm::init
                        ((mDoExt_btkAnm *)(this + 0x10c),pModel,pAnm,false,Repeat,d_wpillar::_4516,0
                         ,-1,false,0);
      uVar5 = uVar5 & uVar6;
    }
    else {
      pModel = (J3DModelData *)
               dRes_control_c::getRes
                         ("Link",0x42,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
      if (pModel == (J3DModelData *)0x0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_wpillar.cpp",0x140,"modelData != 0");
        m_Do_printf::OSPanic("d_wpillar.cpp",0x140,&DAT_80363b08);
      }
      pJVar3 = m_Do_ext::mDoExt_J3DModel__create(pModel,0x80000,0x11000202);
      *(J3DModel **)(this + 0xf8) = pJVar3;
      pJVar4 = (J3DAnmTransform *)
               dRes_control_c::getRes
                         ("Link",0xe,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
      uVar5 = ::mDoExt_bckAnm::init
                        ((mDoExt_bckAnm *)(this + 0xfc),pModel,pJVar4,true,Once,d_wpillar::_4516,0,
                         -1,false);
    }
    m_Do_ext::mDoExt_restoreCurrentHeap();
    m_Do_ext::mDoExt_adjustSolidHeap(*(JKRSolidHeap **)(this + 0x120));
    if ((*(int *)(this + 0xf8) == 0) || (uVar5 == 0)) {
      uVar7 = 5;
    }
    else {
      *(undefined4 *)(this + 0x1d4) = *(undefined4 *)(this + 0xec);
      *(undefined4 *)(this + 0xec) = *(undefined4 *)(this + 0xe8);
      iVar8 = *(int *)(this + 0xf8);
      *(undefined4 *)(iVar8 + 0x18) = *(undefined4 *)(this + 0xe8);
      *(undefined4 *)(iVar8 + 0x1c) = *(undefined4 *)(this + 0xec);
      *(undefined4 *)(iVar8 + 0x20) = *(undefined4 *)(this + 0xf0);
      mtx::PSMTXTrans((double)*(float *)(this + 0xdc),(double)*(float *)(this + 0xe0),
                      (double)*(float *)(this + 0xe4),&mDoMtx_stack_c::now);
      mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)(this + 0xf8) + 0x24));
      if (*(int *)(this + 0xf4) == 0) {
        uVar10 = 1;
        while( true ) {
          if ((ushort)(pModel->mJointTree).mJointCount <= uVar10) break;
          ((pModel->mJointTree).mpJoints[uVar10]->parent).mpCalcCallBack =
               d_wpillar::dWpillar_jointCallBack;
          uVar10 = uVar10 + 1;
        }
        *(dWpillar_c **)(*(int *)(this + 0xf8) + 0x14) = this;
        dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,5,0x3d,
                           (cXyz *)(this + 0xdc),(csXyz *)0x0,(cXyz *)(this + 0xe8),0xff,
                           (dPa_levelEcallBack *)&dPa_control_c::mSingleRippleEcallBack,-1,
                           (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
        dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,5,0x3e,
                           (cXyz *)(this + 0xdc),(csXyz *)0x0,(cXyz *)(this + 0xe8),0xff,
                           (dPa_levelEcallBack *)&dPa_control_c::mSingleRippleEcallBack,-1,
                           (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
        dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,5,0x3f,
                           (cXyz *)(this + 0xdc),(csXyz *)0x0,(cXyz *)(this + 0xe8),0xff,
                           (dPa_levelEcallBack *)&dPa_control_c::mSingleRippleEcallBack,-1,
                           (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
        dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x40,
                           (cXyz *)(this + 0xdc),(csXyz *)0x0,(cXyz *)(this + 0xe8),0xff,
                           (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0)
        ;
      }
      else {
        dPa_control_c::setBombSmoke
                  (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0x200a,
                   (cXyz *)(this + 0xdc),(csXyz *)0x0,(cXyz *)0x0,0xff);
        dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,3,0x2041,
                           (cXyz *)(this + 0xdc),(csXyz *)0x0,(cXyz *)0x0,0xff,
                           (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0)
        ;
        dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,1,0x3c,
                           (cXyz *)(this + 0xdc),(csXyz *)0x0,(cXyz *)0x0,0xff,
                           (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0)
        ;
      }
      ::cBgS_GndChk::cBgS_GndChk(&local_98);
      pcVar11 = &local_58;
      local_58.mbCamThrough = 0;
      local_58.mbLinkThrough = 0;
      local_58.mbArrowsAndLightThrough = 0;
      local_58.mbBombThrough = 0;
      local_58.mbBoomerangThrough = 0;
      local_58.mbHookshotThrough = 0;
      local_4c._4_4_ = 1;
      local_98.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar11;
      if (pcVar11 != (cBgS_PolyPassChk *)0x0) {
        local_98.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_4c;
      }
      local_98.parent.vtbl = &::dBgS_ObjGndChk::__vt;
      local_98.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371ed8;
      local_58.vtbl = &cBgS_PolyPassChk__vtbl_80371ee4;
      local_4c._0_4_ = &cBgS_GrpPassChk__vtbl_80371ef0;
      local_58.mbObjThrough = 1;
      local_98.mPos.x = *(float *)(this + 0xdc);
      local_98.mPos.y = *(float *)(this + 0xe0);
      local_98.mPos.z = *(float *)(this + 0xe4);
      local_98.parent.mpPolyPassChk = pcVar11;
      dVar12 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_98
                                        );
      if ((double)d_wpillar::_4517 == dVar12) {
        uVar9 = 0xff;
        roomNo = dStage_roomControl_c::mStayNo;
      }
      else {
        roomNo = dBgS::GetRoomId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&local_98.mPolyInfo)
        ;
        uVar9 = dBgS::GetPolyColor(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                                   &local_98.mPolyInfo);
      }
      d_kankyo::dKy_tevstr_init((dKy_tevstr_c *)(this + 0x124),roomNo,uVar9);
      local_58.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
      local_4c._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
      if (pcVar11 != (cBgS_PolyPassChk *)0x0) {
        local_58.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
        local_4c._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
        if (((undefined *)register0x00000004 != &DAT_0000004c) &&
           (local_4c._0_4_ = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
           (undefined *)register0x00000004 != &DAT_0000004c)) {
          local_4c._0_4_ = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
        }
        if ((pcVar11 != (cBgS_PolyPassChk *)0x0) &&
           (local_58.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
           pcVar11 != (cBgS_PolyPassChk *)0x0)) {
          local_58.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
        }
      }
      local_98.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
      local_98.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
      cBgS_Chk::_cBgS_Chk(&local_98.parent);
      uVar7 = 4;
    }
  }
  return uVar7;
}


namespace d_wpillar {

/* __stdcall dWpillar_Create(kankyo_class *) */

void dWpillar_Create(dWpillar_c *param_1)

{
  ::dWpillar_c::create(param_1);
  return;
}

