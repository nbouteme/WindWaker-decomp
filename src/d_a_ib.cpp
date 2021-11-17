#include <d_a_ib.h>
#include <SComponent/c_math.h>
#include <SComponent/c_lib.h>
#include <d_particle.h>
#include <d_com_inf_game.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_item.h>
#include <SComponent/c_data_tbl.h>
#include <d_save.h>
#include <d_a_ib.h>
#include <f_op_actor_mng.h>
#include <d_bg_s_acch.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <SComponent/c_bg_s.h>
#include <SComponent/c_bg_s_chk.h>
#include <m_Do_ext.h>
#include <d_cc_d.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <d_kankyo.h>
#include <d_com_static.h>
#include <SComponent/c_m3d_g_cyl.h>
#include <SComponent/c_cc_s.h>
#include <f_op_actor.h>
#include <d_shop.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <mDoExt_brkAnm.h>
#include <daIball_c.h>


namespace d_a_ib {
undefined1 init$4234;
}

/* __thiscall daIball_c::setPointLight(void) */

void __thiscall daIball_c::setPointLight(daIball_c *this)

{
  int unaff_r31;
  float fVar1;
  
  fVar1 = *(float *)(*(int *)(this + 0x61c) + 0x10);
  if ((fVar1 < d_a_ib::_4036) || (d_a_ib::_4037 <= fVar1)) {
    if ((fVar1 < d_a_ib::_4037) || (d_a_ib::_4038 <= fVar1)) {
      if ((d_a_ib::_4038 <= fVar1) && (fVar1 <= d_a_ib::_4039)) {
        unaff_r31 = 2;
      }
    }
    else {
      unaff_r31 = 1;
    }
  }
  else {
    unaff_r31 = 0;
  }
  fVar1 = SComponent::cM_rndF(d_a_ib::_4041);
  SComponent::cLib_addCalc2
            ((float *)(this + 0x6a4),d_a_ib::_4040 + fVar1,d_a_ib::_4042,d_a_ib::_4043);
  *(undefined4 *)(this + 0x684) = *(undefined4 *)(this + 0x1f8);
  *(undefined4 *)(this + 0x688) = *(undefined4 *)(this + 0x1fc);
  *(undefined4 *)(this + 0x68c) = *(undefined4 *)(this + 0x200);
  *(undefined2 *)(this + 0x690) = (&d_a_ib::light_color_4027)[unaff_r31 * 3];
  *(undefined2 *)(this + 0x692) = (&DAT_8035beb6)[unaff_r31 * 3];
  *(undefined2 *)(this + 0x694) = (&DAT_8035beb8)[unaff_r31 * 3];
  *(float *)(this + 0x698) =
       (float)((double)CONCAT44(0x43300000,
                                (int)(short)(int)((d_a_ib::_4044 +
                                                  d_s_play::g_regHIO.mChild[12].mFloats[0]) *
                                                 *(float *)(this + 0x6a4)) ^ 0x80000000) -
              d_a_ib::_4048);
  *(float *)(this + 0x69c) = d_a_ib::_4045;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daIball_c::createDisappearEffect(int,
                                               int) */

void __thiscall daIball_c::createDisappearEffect(daIball_c *this,int param_1,int param_2)

{
  sbyte sVar1;
  cXyz local_28;
  cXyz local_1c;
  
  local_1c.x = d_a_ib::_4040;
  local_1c.y = d_a_ib::_4040;
  local_1c.z = d_a_ib::_4040;
  local_28.x = *(float *)(this + 0x1f8);
  local_28.z = *(float *)(this + 0x200);
  local_28.y = *(float *)(this + 0x1fc) + DAT_8035be94;
  if (param_1 == 1) {
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x19,&local_28,
                       (csXyz *)0x0,&local_1c,0xff,(dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,
                       (_GXColor *)0x0,(cXyz *)0x0);
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x1a,&local_28,
                       (csXyz *)0x0,&local_1c,0xff,(dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,
                       (_GXColor *)0x0,(cXyz *)0x0);
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x1b,&local_28,
                       (csXyz *)0x0,&local_1c,0xff,(dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,
                       (_GXColor *)0x0,(cXyz *)0x0);
    sVar1 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x580d,(cXyz *)(this + 0x1f8),0,sVar1,d_a_ib::_4040,
               d_a_ib::_4040,d_a_ib::_4103,d_a_ib::_4103,0);
  }
  else {
    if ((param_1 < 1) && (-1 < param_1)) {
      dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x1c,&local_28,
                         (csXyz *)0x0,&local_1c,0xff,
                         (dPa_levelEcallBack *)(&dPa_control_c::mLifeBall + param_2 * 8),-1,
                         (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
      dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x1d,&local_28,
                         (csXyz *)0x0,&local_1c,0xff,(dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,
                         (_GXColor *)0x0,(cXyz *)0x0);
      if (param_2 == 2) {
        dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x47,&local_28,
                           (csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1,
                           (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
      }
      sVar1 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x5816,(cXyz *)(this + 0x1f8),0,sVar1,d_a_ib::_4040,
                 d_a_ib::_4040,d_a_ib::_4103,d_a_ib::_4103,0);
    }
  }
  return;
}


namespace d_a_ib {

/* __stdcall itemParamSet_CB(void *) */

undefined4 itemParamSet_CB(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) &&
     (iVar1 = d_item::isEmono(*(dItem_data__ItemNo *)(param_1 + 0x63a)), iVar1 == 0)) {
    *(undefined2 *)(param_1 + 0x658) = 0x5a;
    *(undefined2 *)(param_1 + 0x65a) = 0x3c;
  }
  return 1;
}

}

/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x800f396c) */
/* WARNING: Removing unreachable block (ram,0x800f395c) */
/* WARNING: Removing unreachable block (ram,0x800f3964) */
/* WARNING: Removing unreachable block (ram,0x800f3974) */
/* __thiscall daIball_c::createItem(void) */

undefined4 __thiscall daIball_c::createItem(daIball_c *this)

{
  daIball_c dVar1;
  dItem_data__ItemNo dVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint itemPickupFlag;
  undefined4 uVar8;
  undefined8 in_f28;
  double dVar9;
  undefined8 in_f29;
  double dVar10;
  undefined8 in_f30;
  double dVar11;
  undefined8 in_f31;
  double dVar12;
  float fVar13;
  uint local_a8;
  short local_a4;
  cXyz local_a0;
  uint local_94 [4];
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  longlong local_70;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  uVar3 = *(uint *)(this + 0xb0) & 0xffff;
  local_94[0] = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                            d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_ITEM0,
                            uVar3);
  local_94[0] = local_94[0] & 0xff;
  local_94[1] = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                            d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_ITEM1,
                            uVar3);
  local_94[1] = local_94[1] & 0xff;
  local_94[2] = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                            d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_ITEM2,
                            uVar3);
  local_94[2] = local_94[2] & 0xff;
  local_94[3] = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                            d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_ITEM3,
                            uVar3);
  local_94[3] = local_94[3] & 0xff;
  local_84 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_ITEM4,uVar3);
  local_84 = local_84 & 0xff;
  local_80 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_ITEM5,uVar3);
  local_80 = local_80 & 0xff;
  local_7c = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_ITEM6,uVar3);
  local_7c = local_7c & 0xff;
  uVar3 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_ITEM7,uVar3);
  local_78 = uVar3 & 0xff;
  iVar7 = 0;
  iVar6 = 0;
  dVar10 = (double)d_a_ib::_4036;
  dVar11 = (double)DAT_8035bea4;
  dVar12 = (double)DAT_8035bea8;
  do {
    itemPickupFlag = 0xffffffff;
    uVar5 = *(uint *)((int)local_94 + iVar6);
    dVar2 = (dItem_data__ItemNo)uVar5;
    uVar3 = d_item::isLimitedItem(dVar2);
    if (uVar3 == 0) {
      iVar4 = d_item::isNonSavedEmono(dVar2);
      if (iVar4 != 0) {
        if ((char)((uint)*(undefined4 *)(this + 0xb0) >> 0x10) != '\0') {
          *(undefined4 *)((int)local_94 + iVar6) = 3;
        }
        itemPickupFlag = 0xffffffff;
      }
    }
    else {
      itemPickupFlag = SEXT14((char)((uint)*(undefined4 *)(this + 0xb0) >> 0x10));
      if (((itemPickupFlag != 0x1f) && (itemPickupFlag != 0xff)) && (itemPickupFlag != 0xffffffff))
      {
        if ((uVar5 & 0xff) == 0x4b) {
          iVar4 = dSv_memBit_c::isSwitch
                            ((dSv_memBit_c *)
                             (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mMemory + 0xe),
                             itemPickupFlag);
        }
        else {
          iVar4 = dSv_info_c::isItem(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,itemPickupFlag,
                                     (int)(char)this[0x20a]);
        }
        if (iVar4 == 0) goto LAB_800f388c;
      }
      itemPickupFlag = 0xffffffff;
      *(undefined4 *)((int)local_94 + iVar6) = 3;
    }
LAB_800f388c:
    local_a0.x = ::cXyz::Zero.x;
    local_a0.y = ::cXyz::Zero.y;
    local_a0.z = ::cXyz::Zero.z;
    local_a8 = ::csXyz::Zero._0_4_;
    local_a4 = ::csXyz::Zero.z;
    dVar9 = (double)d_a_ib::_4040;
    fVar13 = SComponent::cM_rndFX(d_a_ib::_4040);
    if ((double)fVar13 < dVar10) {
      dVar9 = (double)d_a_ib::_4103;
    }
    fVar13 = SComponent::cM_rndFX(DAT_8035beac);
    dVar9 = (double)((float)(dVar9 * dVar11) + fVar13);
    fVar13 = SComponent::cM_rndF(d_a_ib::_4203);
    local_70 = (longlong)(int)fVar13;
    local_a8 = local_a8 & 0xffff0000 | (int)fVar13 & 0xffffU;
    uVar3 = d_item::getItemNoByLife((dItem_data__ItemNo)*(undefined4 *)((int)local_94 + iVar6));
    *(uint *)((int)local_94 + iVar6) = uVar3 & 0xff;
    dVar1 = this[0x20a];
    fVar13 = SComponent::cM_rndF(d_a_ib::_4204);
    f_op_actor_mng::fopAcM_fastCreateItem
              ((cXyz *)(this + 0x1f8),*(uint *)((int)local_94 + iVar6),(int)(char)dVar1,
               (csXyz *)&local_a8,&local_a0,dVar9,(double)(float)(dVar12 + (double)fVar13),
               (double)d_a_ib::_4205,itemPickupFlag,d_a_ib::itemParamSet_CB);
    iVar7 = iVar7 + 1;
    iVar6 = iVar6 + 4;
    if (7 < iVar7) {
      dead(this);
      __psq_l0(auStack8,uVar8);
      __psq_l1(auStack8,uVar8);
      __psq_l0(auStack24,uVar8);
      __psq_l1(auStack24,uVar8);
      __psq_l0(auStack40,uVar8);
      __psq_l1(auStack40,uVar8);
      __psq_l0(auStack56,uVar8);
      __psq_l1(auStack56,uVar8);
      return 1;
    }
  } while( true );
}


/* __thiscall daIball_c::dead(void) */

undefined4 __thiscall daIball_c::dead(daIball_c *this)

{
  float fVar1;
  int in_r5;
  
  fVar1 = *(float *)(*(int *)(this + 0x61c) + 0x10);
  if ((fVar1 < d_a_ib::_4036) || (d_a_ib::_4037 <= fVar1)) {
    if ((fVar1 < d_a_ib::_4037) || (d_a_ib::_4038 <= fVar1)) {
      if ((d_a_ib::_4038 <= fVar1) && (fVar1 <= d_a_ib::_4039)) {
        in_r5 = 2;
      }
    }
    else {
      in_r5 = 1;
    }
  }
  else {
    in_r5 = 0;
  }
  createDisappearEffect(this,0,in_r5);
  f_op_actor_mng::fopAcM_delete((base_process_class *)this);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f14 */
/* WARNING: Inlined function: FUN_80328f60 */
/* WARNING: Removing unreachable block (ram,0x800f3e58) */
/* __thiscall daIball_c::checkGeo(void) */

void __thiscall daIball_c::checkGeo(daIball_c *this)

{
  sbyte sVar1;
  void *extraout_r4;
  cBgS_PolyPassChk *pcVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  cXyz local_c8;
  cXyz local_bc;
  float local_b0;
  float local_ac;
  float local_a8;
  cBgS_GndChk local_a4;
  cBgS_PolyPassChk local_64;
  undefined local_58 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (d_a_ib::init_4234 == '\0') {
    d_a_ib::mode_proc_4231 = d_a_ib::_4232;
    DAT_8038c534 = DAT_8038c51c;
    DAT_8038c538 = PTR_mode_wait_8038c520;
    DAT_8038c53c = d_a_ib::_4233;
    DAT_8038c540 = DAT_8038c528;
    DAT_8038c544 = PTR_mode_water_8038c52c;
    d_a_ib::init_4234 = '\x01';
  }
  *(undefined4 *)(this + 0x67c) = *(undefined4 *)(this + 0x224);
  if ((int)DAT_8035bea0 < *(int *)(this + 0x66c)) {
    f_op_actor_mng::fopAcM_posMoveF((fopAc_ac_c *)this,(cXyz *)(this + 0x494));
  }
  dBgS_Acch::CrrPos((dBgS_Acch *)(this + 0x290),&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS);
  Runtime.PPCEABI.H::__ptmf_scall
            ((PTMF *)(&d_a_ib::mode_proc_4231 + (uint)(byte)this[0x680] * 3),this,extraout_r4);
  ::cBgS_GndChk::cBgS_GndChk(&local_a4);
  pcVar2 = &local_64;
  local_64.mbCamThrough = 0;
  local_64.mbLinkThrough = 0;
  local_64.mbArrowsAndLightThrough = 0;
  local_64.mbBombThrough = 0;
  local_64.mbBoomerangThrough = 0;
  local_64.mbHookshotThrough = 0;
  local_a4.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar2;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    local_a4.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_58;
  }
  local_64.mbObjThrough = 1;
  local_a4.parent.vtbl = (cBgS_Chk__vtbl *)&dBgS_ObjGndChk_Yogan::__vt;
  local_a4.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_80371e60;
  local_64.vtbl = (cBgS_PolyPassChk__vtbl *)&DAT_80371e6c;
  local_58._0_4_ = (undefined **)&DAT_80371e78;
  local_58._4_4_ = 4;
  local_a8 = *(float *)(this + 0x200);
  local_ac = d_a_ib::_4340 + *(float *)(this + 0x1e8) + DAT_8035be94;
  local_b0 = *(float *)(this + 0x1f8);
  local_a4.parent.mpPolyPassChk = pcVar2;
  local_a4.mPos.x = local_b0;
  local_a4.mPos.y = local_ac;
  local_a4.mPos.z = local_a8;
  dVar4 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_a4);
  if (((double)d_a_ib::_4341 != dVar4) &&
     ((((float)(dVar4 - (double)*(float *)(this + 0x324)) < d_a_ib::_4342 &&
       ((double)*(float *)(this + 0x1fc) < dVar4)) ||
      ((d_a_ib::_4342 <= (float)(dVar4 - (double)*(float *)(this + 0x324)) &&
       ((double)(d_a_ib::_4342 + *(float *)(this + 0x1fc)) < dVar4)))))) {
    sVar1 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x691b,(cXyz *)(this + 0x1f8),0,sVar1,d_a_ib::_4040,
               d_a_ib::_4040,d_a_ib::_4103,d_a_ib::_4103,0);
    local_bc.x = d_a_ib::_4343;
    local_bc.y = d_a_ib::_4343;
    local_bc.z = d_a_ib::_4343;
    local_c8.x = *(float *)(this + 0x1f8);
    local_c8.z = *(float *)(this + 0x200);
    local_c8.y = (float)dVar4;
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x80d5,&local_c8,
                       (csXyz *)0x0,&local_bc,0xff,(dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,
                       (_GXColor *)0x0,(cXyz *)0x0);
    f_op_actor_mng::fopAcM_delete((base_process_class *)this);
  }
  local_64.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_58._0_4_ = &PTR_80371f20;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    local_64.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_58._0_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x58) &&
       (local_58._0_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x58)) {
      local_58._0_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar2 != (cBgS_PolyPassChk *)0x0) &&
       (local_64.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar2 != (cBgS_PolyPassChk *)0x0)) {
      local_64.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_a4.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_a4.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_a4.parent);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __thiscall daIball_c::mode_wait_init(void) */

void __thiscall daIball_c::mode_wait_init(daIball_c *this)

{
  dPa_rippleEcallBack::end((dPa_rippleEcallBack *)(this + 0x658));
  this[0x680] = (daIball_c)0x0;
  return;
}


/* WARNING: Removing unreachable block (ram,0x800f3f50) */
/* __thiscall daIball_c::mode_wait(void) */

void __thiscall daIball_c::mode_wait(daIball_c *this)

{
  float fVar1;
  undefined4 uVar2;
  undefined8 in_f31;
  double dVar3;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if ((*(uint *)(this + 0x2b8) & 0x80) != 0) {
    *(float *)(this + 0x67c) = *(float *)(this + 0x67c) * DAT_8035be8c;
    fVar1 = d_a_ib::_4036;
    if (*(float *)(this + 0x67c) <= *(float *)(this + 600) - d_a_ib::_4042) {
      *(float *)(this + 0x220) = d_a_ib::_4036;
      *(float *)(this + 0x224) = -*(float *)(this + 0x67c);
      *(float *)(this + 0x228) = fVar1;
    }
    else {
      *(float *)(this + 0x254) = d_a_ib::_4036;
    }
  }
  dVar3 = (double)*(float *)(this + 0x360);
  if (((double)*(float *)(this + 0x1fc) < dVar3) && ((double)d_a_ib::_4341 != dVar3)) {
    mode_water_init(this);
    *(float *)(this + 0x1fc) = (float)dVar3;
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


/* __thiscall daIball_c::mode_water_init(void) */

void __thiscall daIball_c::mode_water_init(daIball_c *this)

{
  dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,5,0x33,
                     (cXyz *)(this + 0x1f8),(csXyz *)0x0,(cXyz *)(this + 0x214),0xff,
                     (dPa_levelEcallBack *)(this + 0x658),-1,(_GXColor *)0x0,(_GXColor *)0x0,
                     (cXyz *)0x0);
  *(float *)(this + 0x668) = d_a_ib::_4036;
  this[0x680] = (daIball_c)0x1;
  return;
}


/* WARNING: Removing unreachable block (ram,0x800f4038) */
/* __thiscall daIball_c::mode_water(void) */

void __thiscall daIball_c::mode_water(daIball_c *this)

{
  undefined4 uVar1;
  undefined8 in_f31;
  double dVar2;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar2 = (double)*(float *)(this + 0x360);
  if (((double)d_a_ib::_4341 == dVar2) || (dVar2 < (double)*(float *)(this + 0x1fc))) {
    mode_wait_init(this);
  }
  if ((double)d_a_ib::_4341 != dVar2) {
    *(float *)(this + 0x1fc) = (float)dVar2;
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daIball_c::animControl(void) */

void __thiscall daIball_c::animControl(daIball_c *this)

{
  bool bVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  sbyte sVar5;
  
  bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0;
  *(undefined4 *)(*(int *)(this + 0x61c) + 0xc) =
       *(undefined4 *)(&DAT_8035be7c + *(int *)(this + 0x674) * 4);
  ::mDoExt_baseAnm::play((mDoExt_baseAnm *)(this + 0x618));
  bVar2 = *(byte *)(*(int *)(this + 0x61c) + 5);
  *(float *)(*(int *)(this + 0x634) + 0xc) = d_a_ib::_4040;
  ::mDoExt_baseAnm::play((mDoExt_baseAnm *)(this + 0x630));
  *(float *)(*(int *)(this + 0x608) + 0xc) = d_a_ib::_4040;
  ::mDoExt_baseAnm::play((mDoExt_baseAnm *)(this + 0x604));
  ::mDoExt_baseAnm::play((mDoExt_baseAnm *)(this + 0x648));
  if (bVar1) {
    fVar3 = *(float *)(*(int *)(this + 0x61c) + 0x10);
    fVar4 = fVar3 - *(float *)(*(int *)(this + 0x61c) + 0xc);
    if ((((bVar2 >> 1 & 1) != 0) || ((d_a_ib::_4037 <= fVar3 && (fVar4 < d_a_ib::_4037)))) ||
       ((d_a_ib::_4038 <= fVar3 && (fVar4 < d_a_ib::_4038)))) {
      sVar5 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x580e,(cXyz *)(this + 0x1f8),0,sVar5,d_a_ib::_4040,
                 d_a_ib::_4040,d_a_ib::_4103,d_a_ib::_4103,0);
    }
  }
  return;
}


/* __thiscall daIball_c::damage(void) */

void __thiscall daIball_c::damage(daIball_c *this)

{
  int iVar1;
  cCcD_Obj *pcVar2;
  cCcD_Obj__DamageTypes cVar3;
  
  iVar1 = dCcD_GObjInf::ChkTgHit((dCcD_GObjInf *)(this + 0x4d0));
  if ((iVar1 != 0) &&
     (pcVar2 = dCcD_GObjInf::GetTgHitObj((dCcD_GObjInf *)(this + 0x4d0)), pcVar2 != (cCcD_Obj *)0x0)
     ) {
    cVar3 = (pcVar2->parent).mObjAt.mDamageTypes;
    if ((((cVar3 & Sword) == 0) &&
        ((((cVar3 & BokoStick) == 0 && ((cVar3 & BokoblinScimitar) == 0)) &&
         ((cVar3 & SkullHammer) == 0)))) &&
       (((((cVar3 & 0x2000000) == 0 && ((cVar3 & StalfosMace) == 0)) &&
         ((cVar3 & DarknutSword) == 0)) &&
        ((((cVar3 & 0x8000) == 0 && ((cVar3 & Boomerang) == 0)) &&
         ((((cVar3 & NormalArrow) == 0 &&
           ((((cVar3 & FireArrows) == 0 && ((cVar3 & IceArrows) == 0)) &&
            ((cVar3 & LightArrow) == 0)))) && ((cVar3 & MoblinSpear) == 0)))))))) {
      return;
    }
    createItem(this);
  }
  return;
}


/* __thiscall daIball_c::set_mtx(void) */

void __thiscall daIball_c::set_mtx(daIball_c *this)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x600);
  *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(this + 0x214);
  *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(this + 0x218);
  *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(this + 0x21c);
  mtx::PSMTXTrans((double)*(float *)(this + 0x1f8),(double)(*(float *)(this + 0x1fc) + DAT_8035be94)
                  ,(double)*(float *)(this + 0x200),&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_XYZrotM
            (&mDoMtx_stack_c::now,(int)*(short *)(this + 0x204),(int)*(short *)(this + 0x206),
             (int)*(short *)(this + 0x208));
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)(this + 0x600) + 0x24));
  return;
}


/* __thiscall daIball_c::CreateInit(void) */

void __thiscall daIball_c::CreateInit(daIball_c *this)

{
  fopAc_ac_c *extraout_r4;
  
  *(int *)(this + 0x22c) = *(int *)(this + 0x600) + 0x24;
  ::dCcD_Stts::Init((dCcD_Stts *)(this + 0x494),0xff,0xff,(fopAc_ac_c *)this);
  ::dCcD_Cyl::Set((dCcD_Cyl *)(this + 0x4d0),(dCcD_SrcCyl *)&m_cyl_src);
  *(daIball_c **)(this + 0x514) = this + 0x494;
  ::dBgS_AcchCir::SetWall((dBgS_AcchCir *)(this + 0x454),d_a_ib::_4340,d_a_ib::_4340);
  dBgS_Acch::Set((dBgS_Acch *)(this + 0x290),(cXyz *)(this + 0x1f8),(cXyz *)(this + 0x1e4),
                 (fopAc_ac_c *)this,1,(dBgS_AcchCir *)(this + 0x454),(cXyz *)(this + 0x220),
                 (csXyz *)0x0,(csXyz *)0x0);
  *(uint *)(this + 0x2b8) = *(uint *)(this + 0x2b8) | 0x20000;
  *(uint *)(this + 0x2b8) = *(uint *)(this + 0x2b8) | 0x40000;
  this[0x681] = (daIball_c)0x0;
  *(undefined4 *)(this + 600) = DAT_8035be90;
  this[0x680] = (daIball_c)0x0;
  *(float *)(this + 0x1fc) = *(float *)(this + 0x1fc) - DAT_8035be94;
  ::mDoExt_bckAnm::entry
            ((mDoExt_bckAnm *)(this + 0x648),*(J3DModelData **)(*(int *)(this + 0x600) + 4),
             *(float *)(*(int *)(this + 0x64c) + 0x10));
  set_mtx(this);
  (**(code **)(**(int **)(this + 0x600) + 0x10))();
  d_kankyo::dKy_plight_set((LIGHT_INFLUENCE *)(this + 0x684));
  setPointLight(this);
  *(float *)(this + 0x6a4) = d_a_ib::_4040;
  regist(this,extraout_r4);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daIball_c::_daIball_draw(void) */

undefined4 __thiscall daIball_c::_daIball_draw(daIball_c *this)

{
  int iVar1;
  int iVar2;
  
  dScnKy_env_light_c::settingTevStruct
            (&d_kankyo::g_env_light,Actor,(cXyz *)(this + 0x1f8),(dKy_tevstr_c *)(this + 0x10c));
  dScnKy_env_light_c::setLightTevColorType
            (&d_kankyo::g_env_light,*(J3DModel **)(this + 0x600),(dKy_tevstr_c *)(this + 0x10c));
  iVar1 = 0;
  iVar2 = 0;
  do {
    ::mDoExt_brkAnm::entry
              ((mDoExt_brkAnm *)(this + iVar2 + 0x618),
               *(J3DModelData **)(*(int *)(this + 0x600) + 4),
               *(float *)(*(int *)(this + iVar2 + 0x61c) + 0x10));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x18;
  } while (iVar1 < 2);
  ::mDoExt_btkAnm::entry
            ((mDoExt_btkAnm *)(this + 0x604),*(J3DModelData **)(*(int *)(this + 0x600) + 4),
             *(float *)(*(int *)(this + 0x608) + 0x10));
  ::mDoExt_bckAnm::entry
            ((mDoExt_bckAnm *)(this + 0x648),*(J3DModelData **)(*(int *)(this + 0x600) + 4),
             *(float *)(*(int *)(this + 0x64c) + 0x10));
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelMaskOffOpa;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelMaskOffXlu;
  m_Do_ext::mDoExt_modelUpdateDL(*(J3DModel **)(this + 0x600));
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  d_com_inf_game::dComIfGd_setSimpleShadow2
            ((cXyz *)(this + 0x1f8),*(float *)(this + 0x324),d_a_ib::_4340,
             (cBgS_PolyInfo *)(this + 0x378),0,d_a_ib::_4040,&dDlst_shadowControl_c::mSimpleTexObj);
  return 1;
}


/* __thiscall daIball_c::_daIball_execute(void) */

undefined4 __thiscall daIball_c::_daIball_execute(daIball_c *this)

{
  sbyte sVar1;
  
  *(undefined4 *)(this + 0x260) = *(undefined4 *)(this + 0x1f8);
  *(undefined4 *)(this + 0x264) = *(undefined4 *)(this + 0x1fc);
  *(undefined4 *)(this + 0x268) = *(undefined4 *)(this + 0x200);
  *(float *)(this + 0x264) = d_a_ib::_4037 + *(float *)(this + 0x1fc);
  *(int *)(this + 0x66c) = *(int *)(this + 0x66c) + 1;
  setPointLight(this);
  if (this[0x681] == (daIball_c)0x0) {
    sVar1 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x5802,(cXyz *)(this + 0x1f8),0,sVar1,d_a_ib::_4040,
               d_a_ib::_4040,d_a_ib::_4103,d_a_ib::_4103,0);
    this[0x681] = (daIball_c)0x1;
  }
  checkGeo(this);
  animControl(this);
  damage(this);
  set_mtx(this);
  ::cM3dGCyl::SetC((cM3dGCyl *)(this + 0x5e8),(cXyz *)(this + 0x1f8));
  cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)(this + 0x4d0));
  return 1;
}


/* __thiscall daIball_c::_daIball_delete(void) */

undefined4 __thiscall daIball_c::_daIball_delete(daIball_c *this)

{
  char *__filename;
  
  dPa_rippleEcallBack::end((dPa_rippleEcallBack *)(this + 0x658));
  d_kankyo::dKy_plight_cut((LIGHT_INFLUENCE *)(this + 0x684));
  remove(this,__filename);
  return 1;
}


namespace d_a_ib {

/* __stdcall CheckCreateHeap(fopAc_ac_c *) */

void CheckCreateHeap(daIball_c *param_1)

{
  ::daIball_c::CreateHeap(param_1);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daIball_c::_daIball_create(void) */

undefined4 __thiscall daIball_c::_daIball_create(daIball_c *this)

{
  uint uVar1;
  undefined4 uVar2;
  
  if ((*(uint *)(this + 0x1c8) & 8) == 0) {
    if (this != (daIball_c *)0x0) {
      fopAc_ac_c::fopAc_ac_c((fopAc_ac_c *)this);
      dBgS_Acch::dBgS_Acch((dBgS_Acch *)(this + 0x290));
      *(dBgS_ObjAcch__vtbl **)(this + 0x2a0) = &::dBgS_ObjAcch::__vt;
      *(undefined4 *)(this + 0x2a4) = 0x8037e9e4;
      *(undefined4 *)(this + 0x2b0) = 0x8037e9f0;
      this[0x2a8] = (daIball_c)0x1;
      ::dBgS_AcchCir::dBgS_AcchCir((dBgS_AcchCir *)(this + 0x454));
      *(cCcD_Stts__vtbl **)(this + 0x4ac) = &cCcD_Stts::__vt;
      ::dCcD_GStts::dCcD_GStts((dCcD_GStts *)(this + 0x4b0));
      *(dCcD_Stts__vtbl **)(this + 0x4ac) = &::dCcD_Stts::__vt;
      *(undefined4 *)(this + 0x4b0) = 0x8037ec40;
      dCcD_GObjInf::dCcD_GObjInf((dCcD_GObjInf *)(this + 0x4d0));
      *(undefined ***)(this + 0x5e4) = &::cCcD_ShapeAttr::__vt;
      *(cM3dGAab__vtbl **)(this + 0x5e0) = &::cM3dGAab::__vt;
      *(undefined ***)(this + 0x5fc) = &::cM3dGCyl::__vt;
      *(cCcD_ShapeAttr__vtbl **)(this + 0x5e4) = &::cCcD_CylAttr::__vt;
      *(cCcD_CylAttr__vtbl **)(this + 0x5fc) = &cCcD_CylAttr__vtbl_803951ac;
      *(dCcD_Cyl__vtbl **)(this + 0x50c) = &::dCcD_Cyl::__vt;
      *(undefined4 *)(this + 0x5e4) = 0x8038af30;
      *(undefined4 *)(this + 0x5fc) = 0x8038af84;
      *(undefined ***)(this + 0x604) = &::mDoExt_baseAnm::__vt;
      *(undefined4 *)(this + 0x608) = 0;
      *(undefined ***)(this + 0x604) = &::mDoExt_btkAnm::__vt;
      *(undefined4 *)(this + 0x610) = 0;
      Runtime.PPCEABI.H::__construct_array
                (this + 0x618,::mDoExt_brkAnm::mDoExt_brkAnm,::mDoExt_brkAnm::_mDoExt_brkAnm,0x18,2)
      ;
      *(undefined ***)(this + 0x648) = &::mDoExt_baseAnm::__vt;
      *(undefined4 *)(this + 0x64c) = 0;
      *(undefined ***)(this + 0x648) = &::mDoExt_bckAnm::__vt;
      *(undefined4 *)(this + 0x654) = 0;
      *(undefined1 **)(this + 0x658) = &::JPACallBackBase<JPABaseEmitter*>::__vt;
      *(undefined1 **)(this + 0x658) = &::dPa_levelEcallBack::__vt;
      *(undefined1 **)(this + 0x658) = &dPa_rippleEcallBack::__vt;
      *(undefined4 *)(this + 0x65c) = 0;
    }
    *(uint *)(this + 0x1c8) = *(uint *)(this + 0x1c8) | 8;
  }
  uVar1 = f_op_actor_mng::fopAcM_entrySolidHeap((fopAc_ac_c *)this,d_a_ib::CheckCreateHeap,0x3500);
  if ((uVar1 & 0xff) == 0) {
    uVar2 = 5;
  }
  else {
    CreateInit(this);
    uVar2 = 4;
  }
  return uVar2;
}


/* __thiscall mDoExt_brkAnm::mDoExt_brkAnm(void) */

void __thiscall mDoExt_brkAnm::mDoExt_brkAnm(mDoExt_brkAnm *this)

{
  (this->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_baseAnm::__vt;
  (this->parent).mpFrameCtrl = (J3DFrameCtrl *)0x0;
  (this->parent).vtbl = (mDoExt_baseAnm__vtbl *)&__vt;
  this->mpCRegAnm = (J3DTevColorAnm *)0x0;
  this->mpKRegAnm = (J3DTevKColorAnm *)0x0;
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __thiscall daIball_c::CreateHeap(void) */

undefined4 __thiscall daIball_c::CreateHeap(daIball_c *this)

{
  J3DModelData *pModel;
  ulong uVar1;
  J3DModel *pJVar2;
  undefined4 uVar3;
  J3DAnmTransform *pJVar4;
  int iVar5;
  J3DAnmTextureSRTKey *pAnm;
  J3DAnmTevRegKey *pJVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  long local_30 [3];
  
  pModel = (J3DModelData *)
           dRes_control_c::getRes
                     (m_arcname,0x2e,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pModel == (J3DModelData *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_a_ib.cpp",0x46f,"modelData != 0");
    m_Do_printf::OSPanic("d_a_ib.cpp",0x46f,&DAT_8035bee2);
  }
  pJVar2 = m_Do_ext::mDoExt_J3DModel__create(pModel,0x80000,0x11000222);
  *(J3DModel **)(this + 0x600) = pJVar2;
  if (*(int *)(this + 0x600) == 0) {
    uVar3 = 0;
  }
  else {
    pJVar4 = (J3DAnmTransform *)
             dRes_control_c::getRes
                       (m_arcname,0xe,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pJVar4 == (J3DAnmTransform *)0x0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"d_a_ib.cpp",0x480,"pbck != 0");
      m_Do_printf::OSPanic("d_a_ib.cpp",0x480,&DAT_8035bee2);
    }
    iVar5 = ::mDoExt_bckAnm::init
                      ((mDoExt_bckAnm *)(this + 0x648),pModel,pJVar4,true,Once,d_a_ib::_4040,0,-1,
                       false);
    if (iVar5 == 0) {
      uVar3 = 0;
    }
    else {
      pAnm = (J3DAnmTextureSRTKey *)
             dRes_control_c::getRes
                       (m_arcname,0x56,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40)
      ;
      if (pAnm == (J3DAnmTextureSRTKey *)0x0) {
        uVar1 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar1,"d_a_ib.cpp",0x48c,"pbtk != 0");
        m_Do_printf::OSPanic("d_a_ib.cpp",0x48c,&DAT_8035bee2);
      }
      iVar5 = ::mDoExt_btkAnm::init
                        ((mDoExt_btkAnm *)(this + 0x604),pModel,pAnm,true,Repeat,d_a_ib::_4040,0,-1,
                         false,0);
      if (iVar5 == 0) {
        uVar3 = 0;
      }
      else {
        local_30[0] = d_a_ib::_4848;
        local_30[1] = DAT_803f9e7c;
        iVar9 = 0;
        iVar8 = 0;
        iVar5 = 0;
        do {
          pJVar6 = (J3DAnmTevRegKey *)
                   dRes_control_c::getRes
                             (m_arcname,*(long *)((int)local_30 + iVar5),
                              d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
          if (pJVar6 == (J3DAnmTevRegKey *)0x0) {
            uVar1 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar1,"d_a_ib.cpp",0x49e,"pbrk != 0");
            m_Do_printf::OSPanic("d_a_ib.cpp",0x49e,&DAT_8035bee2);
          }
          iVar7 = ::mDoExt_brkAnm::init
                            ((mDoExt_brkAnm *)(this + iVar8 + 0x618),pModel,pJVar6,true,Repeat,
                             d_a_ib::_4040,0,-1,false,0);
          if (iVar7 == 0) {
            return 0;
          }
          iVar9 = iVar9 + 1;
          iVar8 = iVar8 + 0x18;
          iVar5 = iVar5 + 4;
        } while (iVar9 < 2);
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}


namespace d_a_ib {

/* __stdcall daIball_Create(fopAc_ac_c *) */

void daIball_Create(daIball_c *param_1)

{
  ::daIball_c::_daIball_create(param_1);
  return;
}


/* __stdcall daIball_Draw(daIball_c *) */

void daIball_Draw(daIball_c *param_1)

{
  ::daIball_c::_daIball_draw(param_1);
  return;
}


/* __stdcall daIball_Delete(daIball_c *) */

void daIball_Delete(daIball_c *param_1)

{
  ::daIball_c::_daIball_delete(param_1);
  return;
}


/* __stdcall daIball_IsDelete(daIball_c *) */

undefined4 daIball_IsDelete(void)

{
  return 1;
}


/* __stdcall daIball_Execute(daIball_c *) */

void daIball_Execute(daIball_c *param_1)

{
  ::daIball_c::_daIball_execute(param_1);
  return;
}

