#include <d_bg_s_func.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <SComponent/c_bg_s.h>
#include <SComponent/c_bg_s_chk.h>
#include <d_bg_s.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_bg_s_acch.h>
#include <SComponent/c_bg_w.h>
#include <d_a_sea.h>
#include <JKernel/JKRHeap.h>
#include <d_bg_s_func.h>
#include <dBgS_ObjGndChk_Wtr.h>


namespace d_bg_s_func {

/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x800a4758) */
/* __stdcall dBgS_ObjGndChk_Func(cXyz &) */

undefined8 dBgS_ObjGndChk_Func(cXyz *param_1)

{
  cBgS_GndChk *this;
  undefined4 uVar1;
  cBgS_PolyPassChk *pcVar2;
  undefined4 uVar3;
  undefined8 in_f31;
  cBgS_GndChk gndChk;
  cBgS_PolyPassChk local_58;
  undefined local_4c [20];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  ::cBgS_GndChk::cBgS_GndChk(&gndChk);
  pcVar2 = &local_58;
  local_58.mbCamThrough = 0;
  local_58.mbLinkThrough = 0;
  local_58.mbArrowsAndLightThrough = 0;
  local_58.mbBombThrough = 0;
  local_58.mbBoomerangThrough = 0;
  local_58.mbHookshotThrough = 0;
  local_4c._4_4_ = 1;
  gndChk.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar2;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    gndChk.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_4c;
  }
  gndChk.parent.vtbl = &::dBgS_ObjGndChk::__vt;
  gndChk.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371ed8;
  local_58.vtbl = &cBgS_PolyPassChk__vtbl_80371ee4;
  local_4c._0_4_ = &cBgS_GrpPassChk__vtbl_80371ef0;
  local_58.mbObjThrough = 1;
  gndChk.mPos.x = param_1->x;
  gndChk.mPos.y = param_1->y;
  gndChk.mPos.z = param_1->z;
  gndChk.parent.mpPolyPassChk = pcVar2;
  cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&gndChk);
  local_58.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_4c._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    local_58.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_4c._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
    if (((undefined *)register0x00000004 != &DAT_0000004c) &&
       (local_4c._0_4_ = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != &DAT_0000004c)) {
      local_4c._0_4_ = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar2 != (cBgS_PolyPassChk *)0x0) &&
       (local_58.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar2 != (cBgS_PolyPassChk *)0x0)) {
      local_58.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  gndChk.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  gndChk.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  this = &gndChk;
  uVar1 = 0;
  cBgS_Chk::_cBgS_Chk(&this->parent);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return CONCAT44(this,uVar1);
}


/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* WARNING: Removing unreachable block (ram,0x800a49c0) */
/* __stdcall dBgS_ObjGndChk_Wtr_Func(cXyz &) */

undefined8 dBgS_ObjGndChk_Wtr_Func(float *param_1)

{
  cBgS_PolyPassChk *pcVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined8 in_f31;
  cBgS_GndChk local_a8;
  cBgS_PolyPassChk local_68;
  undefined local_5c [24];
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  ::cBgS_GndChk::cBgS_GndChk(&local_a8);
  pcVar1 = &local_68;
  local_68.mbCamThrough = 0;
  local_68.mbLinkThrough = 0;
  local_68.mbArrowsAndLightThrough = 0;
  local_68.mbBombThrough = 0;
  local_68.mbBoomerangThrough = 0;
  local_68.mbHookshotThrough = 0;
  local_a8.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar1;
  if (pcVar1 != (cBgS_PolyPassChk *)0x0) {
    local_a8.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_5c;
  }
  local_68.mbObjThrough = 1;
  local_a8.parent.vtbl = (cBgS_Chk__vtbl *)&::dBgS_ObjGndChk_Wtr::__vt;
  local_a8.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_8037ea5c;
  local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&DAT_8037ea68;
  local_5c._0_4_ = (undefined **)&DAT_8037ea74;
  local_5c._4_4_ = 2;
  local_a8.mPos.x = *param_1;
  local_a8.mPos.y = param_1[1];
  local_a8.mPos.z = param_1[2];
  local_a8.parent.mpPolyPassChk = pcVar1;
  uVar3 = cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_a8);
  local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_5c._0_4_ = &PTR_80371f20;
  if (pcVar1 != (cBgS_PolyPassChk *)0x0) {
    local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_5c._0_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x5c) &&
       (local_5c._0_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x5c)) {
      local_5c._0_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar1 != (cBgS_PolyPassChk *)0x0) &&
       (local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar1 != (cBgS_PolyPassChk *)0x0)) {
      local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_a8.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_a8.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_a8.parent);
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f14 */
/* WARNING: Inlined function: FUN_80328f60 */
/* WARNING: Removing unreachable block (ram,0x800a4f48) */
/* __stdcall dBgS_SplGrpChk_In_ObjGnd(cXyz &,
                                      dBgS_SplGrpChk *,
                                      float) */

undefined4
dBgS_SplGrpChk_In_ObjGnd(double param_1,float *param_2,dBgS_SplGrpChk *param_3)

{
  bool bVar1;
  undefined4 uVar2;
  ulong uVar3;
  cBgW *this;
  char cVar4;
  int extraout_r4;
  int iVar5;
  cBgS_PolyInfo *pcVar6;
  cBgS_PolyPassChk *pcVar7;
  undefined4 uVar8;
  double dVar9;
  undefined8 in_f31;
  longlong lVar10;
  float fStack200;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  cBgS_GndChk local_a8;
  cBgS_PolyPassChk local_68;
  undefined local_5c [20];
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  ::cBgS_GndChk::cBgS_GndChk(&local_a8);
  pcVar7 = &local_68;
  local_68.mbCamThrough = 0;
  local_68.mbLinkThrough = 0;
  local_68.mbArrowsAndLightThrough = 0;
  local_68.mbBombThrough = 0;
  local_68.mbBoomerangThrough = 0;
  local_68.mbHookshotThrough = 0;
  local_5c._4_4_ = 1;
  local_a8.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar7;
  if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
    local_a8.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_5c;
  }
  local_a8.parent.vtbl = &::dBgS_ObjGndChk::__vt;
  local_a8.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371ed8;
  local_68.vtbl = &cBgS_PolyPassChk__vtbl_80371ee4;
  local_5c._0_4_ = &cBgS_GrpPassChk__vtbl_80371ef0;
  local_68.mbObjThrough = 1;
  local_b4 = *param_2;
  local_ac = param_2[2];
  local_b0 = (float)((double)param_2[1] + param_1);
  local_a8.parent.mpPolyPassChk = pcVar7;
  local_a8.mPos.x = local_b4;
  local_a8.mPos.y = local_b0;
  local_a8.mPos.z = local_ac;
  dVar9 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_a8);
  param_3->mHeight = (float)dVar9;
  if ((double)_4350 == dVar9) {
    local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
    local_5c._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
    if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
      local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      local_5c._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0x5c) &&
         (local_5c._0_4_ = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0x5c)) {
        local_5c._0_4_ = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar7 != (cBgS_PolyPassChk *)0x0) &&
         (local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         pcVar7 != (cBgS_PolyPassChk *)0x0)) {
        local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    local_a8.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
    local_a8.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk(&local_a8.parent);
    uVar2 = 0;
  }
  else {
    pcVar6 = &local_a8.mPolyInfo;
    lVar10 = dBgS::GetRoomId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,pcVar6);
    iVar5 = (int)lVar10;
    bVar1 = false;
    if ((-1 < lVar10) && (lVar10 < 0x4000000000)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_bg_s_func.cpp",0x5d,"0 <= room_no && room_no < 64");
      m_Do_printf::OSPanic("d_bg_s_func.cpp",0x5d,"Halt");
      iVar5 = extraout_r4;
    }
    this = (cBgW *)dStage_roomControl_c::getBgW
                             ((dStage_roomControl_c *)((ulonglong)lVar10 >> 0x20),iVar5);
    if (this == (cBgW *)0x0) {
      local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
      local_5c._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
      if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
        local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
        local_5c._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
        if (((undefined *)register0x00000004 != (undefined *)0x5c) &&
           (local_5c._0_4_ = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
           (undefined *)register0x00000004 != (undefined *)0x5c)) {
          local_5c._0_4_ = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
        }
        if ((pcVar7 != (cBgS_PolyPassChk *)0x0) &&
           (local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
           pcVar7 != (cBgS_PolyPassChk *)0x0)) {
          local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
        }
      }
      local_a8.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
      local_a8.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371e90;
      if (pcVar6 != (cBgS_PolyInfo *)0x0) {
        local_a8.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
      }
      cBgS_Chk::_cBgS_Chk(&local_a8.parent);
      uVar2 = 0;
    }
    else {
      cBgW::GetTopUnder(this,&local_c4,&fStack200);
      local_c0 = *param_2;
      local_b8 = param_2[2];
      local_bc = (float)dVar9;
      (param_3->mStartPos).x = local_c0;
      (param_3->mStartPos).y = (float)dVar9;
      (param_3->mStartPos).z = local_b8;
      param_3->mEndPosY = local_c4;
      cVar4 = dBgS::SplGrpChk(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,param_3);
      if (cVar4 == '\0') {
        local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
        local_5c._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
        if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
          local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
          local_5c._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
          if (((undefined *)register0x00000004 != (undefined *)0x5c) &&
             (local_5c._0_4_ = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
             (undefined *)register0x00000004 != (undefined *)0x5c)) {
            local_5c._0_4_ = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
          }
          if ((pcVar7 != (cBgS_PolyPassChk *)0x0) &&
             (local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
             pcVar7 != (cBgS_PolyPassChk *)0x0)) {
            local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
          }
        }
        local_a8.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
        local_a8.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371e90;
        if (pcVar6 != (cBgS_PolyInfo *)0x0) {
          local_a8.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
        }
        cBgS_Chk::_cBgS_Chk(&local_a8.parent);
        uVar2 = 0;
      }
      else {
        if (param_2[1] < param_3->mHeight) {
          param_3->mFlags = param_3->mFlags | 2;
        }
        local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
        local_5c._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
        if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
          local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
          local_5c._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
          if (((undefined *)register0x00000004 != (undefined *)0x5c) &&
             (local_5c._0_4_ = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
             (undefined *)register0x00000004 != (undefined *)0x5c)) {
            local_5c._0_4_ = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
          }
          if ((pcVar7 != (cBgS_PolyPassChk *)0x0) &&
             (local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
             pcVar7 != (cBgS_PolyPassChk *)0x0)) {
            local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
          }
        }
        local_a8.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
        local_a8.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371e90;
        if (pcVar6 != (cBgS_PolyInfo *)0x0) {
          local_a8.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
        }
        cBgS_Chk::_cBgS_Chk(&local_a8.parent);
        uVar2 = 1;
      }
    }
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* WARNING: Removing unreachable block (ram,0x800a51dc) */
/* __stdcall dBgS_GetWaterHeight(cXyz &) */

double dBgS_GetWaterHeight(float *param_1)

{
  uint uVar1;
  cBgS_PolyPassChk *pcVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f31;
  cBgS_GndChk local_a8;
  cBgS_PolyPassChk local_68;
  undefined local_5c [24];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  ::cBgS_GndChk::cBgS_GndChk(&local_a8);
  pcVar2 = &local_68;
  local_68.mbCamThrough = 0;
  local_68.mbLinkThrough = 0;
  local_68.mbArrowsAndLightThrough = 0;
  local_68.mbBombThrough = 0;
  local_68.mbBoomerangThrough = 0;
  local_68.mbHookshotThrough = 0;
  local_a8.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar2;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    local_a8.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_5c;
  }
  local_68.mbObjThrough = 1;
  local_a8.parent.vtbl = (cBgS_Chk__vtbl *)&::dBgS_ObjGndChk_Wtr::__vt;
  local_a8.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_8037ea5c;
  local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&DAT_8037ea68;
  local_5c._0_4_ = (undefined **)&DAT_8037ea74;
  local_5c._4_4_ = 2;
  local_a8.mPos.x = *param_1;
  local_a8.mPos.y = param_1[1];
  local_a8.mPos.z = param_1[2];
  local_a8.parent.mpPolyPassChk = pcVar2;
  dVar4 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_a8);
  uVar1 = d_a_sea::daSea_ChkArea(*param_1,param_1[2]);
  if (((uVar1 & 0xff) != 0) &&
     (dVar5 = (double)d_a_sea::daSea_calcWave((double)*param_1,(double)param_1[2]), dVar4 < dVar5))
  {
    dVar4 = dVar5;
  }
  local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_5c._0_4_ = &PTR_80371f20;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_5c._0_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x5c) &&
       (local_5c._0_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x5c)) {
      local_5c._0_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar2 != (cBgS_PolyPassChk *)0x0) &&
       (local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar2 != (cBgS_PolyPassChk *)0x0)) {
      local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_a8.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_a8.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_a8.parent);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return dVar4;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* __stdcall dBgS_GetGndMtrlSndId_Func(cXyz,
                                       float) */

undefined4 dBgS_GetGndMtrlSndId_Func(double param_1,float *param_2)

{
  undefined4 uVar1;
  cBgS_PolyPassChk *pcVar2;
  double dVar3;
  cBgS_GndChk local_88;
  cBgS_PolyPassChk local_48;
  undefined local_3c [16];
  
  param_2[1] = (float)((double)param_2[1] + param_1);
  ::cBgS_GndChk::cBgS_GndChk(&local_88);
  pcVar2 = &local_48;
  local_48.mbCamThrough = 0;
  local_48.mbLinkThrough = 0;
  local_48.mbArrowsAndLightThrough = 0;
  local_48.mbBombThrough = 0;
  local_48.mbBoomerangThrough = 0;
  local_48.mbHookshotThrough = 0;
  local_3c._4_4_ = 1;
  local_88.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar2;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    local_88.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_3c;
  }
  local_88.parent.vtbl = &::dBgS_ObjGndChk::__vt;
  local_88.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371ed8;
  local_48.vtbl = &cBgS_PolyPassChk__vtbl_80371ee4;
  local_3c._0_4_ = &cBgS_GrpPassChk__vtbl_80371ef0;
  local_48.mbObjThrough = 1;
  local_88.mPos.x = *param_2;
  local_88.mPos.y = param_2[1];
  local_88.mPos.z = param_2[2];
  local_88.parent.mpPolyPassChk = pcVar2;
  dVar3 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_88);
  if ((double)_4350 == dVar3) {
    local_48.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
    local_3c._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
    if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
      local_48.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      local_3c._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
      if (((undefined *)register0x00000004 != &DAT_0000003c) &&
         (local_3c._0_4_ = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != &DAT_0000003c)) {
        local_3c._0_4_ = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar2 != (cBgS_PolyPassChk *)0x0) &&
         (local_48.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         pcVar2 != (cBgS_PolyPassChk *)0x0)) {
        local_48.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    local_88.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
    local_88.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk(&local_88.parent);
    uVar1 = 0;
  }
  else {
    uVar1 = dBgS::GetMtrlSndId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&local_88.mPolyInfo);
    local_48.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
    local_3c._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
    if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
      local_48.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      local_3c._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
      if (((undefined *)register0x00000004 != &DAT_0000003c) &&
         (local_3c._0_4_ = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != &DAT_0000003c)) {
        local_3c._0_4_ = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar2 != (cBgS_PolyPassChk *)0x0) &&
         (local_48.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         pcVar2 != (cBgS_PolyPassChk *)0x0)) {
        local_48.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    local_88.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
    local_88.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371e90;
    if (&local_88.mPolyInfo != (cBgS_PolyInfo *)0x0) {
      local_88.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    }
    cBgS_Chk::_cBgS_Chk(&local_88.parent);
  }
  return uVar1;
}

}

/* __thiscall dBgS_ObjGndChk_Wtr::~dBgS_ObjGndChk_Wtr(void) */

void __thiscall dBgS_ObjGndChk_Wtr::_dBgS_ObjGndChk_Wtr(dBgS_ObjGndChk_Wtr *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dBgS_ObjGndChk_Wtr *)0x0;
  if (bVar1) {
    *(undefined ***)(this + 0x10) = &__vt;
    *(undefined ***)(this + 0x20) = &PTR_8037ea5c;
    *(undefined **)(this + 0x40) = &DAT_8037ea68;
    *(undefined **)(this + 0x4c) = &DAT_8037ea74;
    if (bVar1) {
      *(cBgS_Chk__vtbl **)(this + 0x10) = &::dBgS_ObjGndChk::__vt;
      *(cBgS_PolyInfo__vtbl **)(this + 0x20) = &cBgS_PolyInfo__vtbl_80371ed8;
      *(cBgS_PolyPassChk__vtbl **)(this + 0x40) = &cBgS_PolyPassChk__vtbl_80371ee4;
      *(cBgS_GrpPassChk__vtbl **)(this + 0x4c) = &cBgS_GrpPassChk__vtbl_80371ef0;
      if (bVar1) {
        *(cBgS_Chk__vtbl **)(this + 0x10) = &::dBgS_GndChk::__vt;
        *(cBgS_PolyInfo__vtbl **)(this + 0x20) = &cBgS_PolyInfo__vtbl_80371f08;
        *(undefined ***)(this + 0x40) = &PTR_80371f14;
        *(undefined ***)(this + 0x4c) = &PTR_80371f20;
        if (this != (dBgS_ObjGndChk_Wtr *)0xffffffc0) {
          *(undefined ***)(this + 0x40) = &::dBgS_Chk::__vt;
          *(undefined ***)(this + 0x4c) = &PTR_80371f68;
          if (this != (dBgS_ObjGndChk_Wtr *)0xffffffb4) {
            *(undefined ***)(this + 0x4c) = &::dBgS_GrpPassChk::__vt;
            if (this != (dBgS_ObjGndChk_Wtr *)0xffffffb4) {
              *(undefined ***)(this + 0x4c) = &::cBgS_GrpPassChk::__vt;
            }
          }
          if ((this != (dBgS_ObjGndChk_Wtr *)0xffffffc0) &&
             (*(undefined ***)(this + 0x40) = &::dBgS_PolyPassChk::__vt,
             this != (dBgS_ObjGndChk_Wtr *)0xffffffc0)) {
            *(undefined ***)(this + 0x40) = &::cBgS_PolyPassChk::__vt;
          }
        }
        if (this != (dBgS_ObjGndChk_Wtr *)0x0) {
          *(undefined1 **)(this + 0x10) = &::cBgS_GndChk::__vt;
          *(undefined ***)(this + 0x20) = &PTR_80371e90;
          if (this != (dBgS_ObjGndChk_Wtr *)0xffffffec) {
            *(undefined ***)(this + 0x20) = &::cBgS_PolyInfo::__vt;
          }
          cBgS_Chk::_cBgS_Chk((cBgS_Chk *)this);
        }
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* [thunk]:__thiscall dBgS_ObjGndChk_Wtr::~dBgS_ObjGndChk_Wtr(void) */

void __thiscall dBgS_ObjGndChk_Wtr::_dBgS_ObjGndChk_Wtr(dBgS_ObjGndChk_Wtr *this)

{
  _dBgS_ObjGndChk_Wtr(this + -0x14);
  return;
}


/* [thunk]:__thiscall dBgS_ObjGndChk_Wtr::~dBgS_ObjGndChk_Wtr(void) */

void __thiscall dBgS_ObjGndChk_Wtr::_dBgS_ObjGndChk_Wtr(dBgS_ObjGndChk_Wtr *this)

{
  _dBgS_ObjGndChk_Wtr(this + -0x4c);
  return;
}


/* [thunk]:__thiscall dBgS_ObjGndChk_Wtr::~dBgS_ObjGndChk_Wtr(void) */

void __thiscall dBgS_ObjGndChk_Wtr::_dBgS_ObjGndChk_Wtr(dBgS_ObjGndChk_Wtr *this)

{
  _dBgS_ObjGndChk_Wtr(this + -0x40);
  return;
}

