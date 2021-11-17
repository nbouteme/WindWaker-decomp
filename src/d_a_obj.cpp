#include <d_a_obj.h>
#include <d_bg_s.h>
#include <d_particle.h>
#include <mtx/vec.h>
#include <f_op_actor_mng.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <d_kankyo_wether.h>
#include <SComponent/c_xyz.h>
#include <d_path.h>
#include <d_a_obj.h>
#include <SComponent/c_m3d.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <SComponent/c_math.h>
#include <MSL_C.PPCEABI.bare.H/w_acos.h>
#include <mtx/quat.h>
#include <d_cc_d.h>
#include <d_com_inf_game.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <daObj.h>
#include <cCcD_SphAttr.h>
#include <daObj/@unnamed@d_a_obj_cpp@.h>
#include <cCcD_CylAttr.h>


namespace d_a_obj {
undefined4 total_spd$4082;
undefined4 path_spd$4114;
undefined1 init$4084;
undefined1 init$4116;
}

/* WARNING: Removing unreachable block (ram,0x800668a0) */
/* __thiscall daObj::make_land_effect(fopAc_ac_c *,
                                      dBgS_GndChk *,
                                      float) */

void __thiscall
daObj::make_land_effect(daObj *this,fopAc_ac_c *param_1,dBgS_GndChk *param_2,float param_3)

{
  float fVar1;
  undefined4 uVar2;
  JPABaseEmitter *pJVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  cXyz local_38;
  cXyz local_2c [2];
  undefined auStack8 [8];
  
  dVar5 = (double)param_3;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar2 = dBgS::GetAttributeCode
                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                     (cBgS_PolyInfo *)&(param_1->parent).parent.mpCtRq);
  switch(uVar2) {
  case 4:
    local_2c[0].x = (float)dVar5;
    local_2c[0].y = (float)dVar5;
    local_2c[0].z = (float)dVar5;
    pJVar3 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x24,
                                (cXyz *)(this + 0x1f8),(csXyz *)0x0,local_2c,0xff,
                                (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                                (cXyz *)0x0);
    if (pJVar3 != (JPABaseEmitter *)0x0) {
      pJVar3->mLifeTime = 0x14;
      pJVar3->mRate = d_a_obj::_4072;
      pJVar3->mMaxFrame = 1;
      pJVar3->mSpread = d_a_obj::_4070;
      pJVar3->mInitialVelDir = d_a_obj::_4069;
      fVar1 = d_a_obj::_4073;
      (pJVar3->mEmitterTranslation).x = d_a_obj::_4073;
      (pJVar3->mEmitterTranslation).y = d_a_obj::_4074;
      (pJVar3->mEmitterTranslation).z = fVar1;
    }
    break;
  case 5:
  case 10:
  case 0xf:
  case 0x1b:
    break;
  default:
    local_38.x = (float)dVar5;
    local_38.y = (float)dVar5;
    local_38.z = (float)dVar5;
    mtx::PSVECScale(&local_38,&local_38,d_a_obj::_4075);
    f_op_actor_mng::fopAcM_create
              (0x1d9,3,(cXyz *)(this + 0x1f8),-1,(csXyz *)0x0,&local_38,0xff,(undefined *)0x0);
    break;
  case 0x13:
    local_2c[0].x = (float)((double)d_a_obj::_4068 * dVar5);
    local_2c[0].y = local_2c[0].x;
    local_2c[0].z = local_2c[0].x;
    pJVar3 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x23,
                                (cXyz *)(this + 0x1f8),(csXyz *)0x0,local_2c,0xff,
                                (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                                (cXyz *)0x0);
    if (pJVar3 != (JPABaseEmitter *)0x0) {
      pJVar3->mRate = d_a_obj::_4069;
      pJVar3->mMaxFrame = 1;
      pJVar3->mSpread = d_a_obj::_4070;
      pJVar3->mInitialVelDir = d_a_obj::_4071;
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* WARNING: Removing unreachable block (ram,0x800669c4) */
/* WARNING: Removing unreachable block (ram,0x800669cc) */
/* __thiscall daObj::get_wind_spd(fopAc_ac_c *,
                                  float) */

void __thiscall daObj::get_wind_spd(daObj *this,fopAc_ac_c *param_1,float param_2)

{
  cXyz *pcVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f30;
  undefined8 in_f31;
  float local_68;
  cXyz local_64;
  cXyz cStack88;
  cXyz local_4c;
  cXyz cStack64;
  cXyz local_34;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar3 = (double)param_2;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (d_a_obj::init_4084 == '\0') {
    d_a_obj::total_spd_4082 = ::cXyz::Zero.x;
    DAT_803e1f10 = ::cXyz::Zero.y;
    DAT_803e1f14 = ::cXyz::Zero.z;
    Runtime.PPCEABI.H::__register_global_object
              (&d_a_obj::total_spd_4082,::cXyz::_cXyz,&d_a_obj::_4083);
    d_a_obj::init_4084 = '\x01';
  }
  dVar4 = d_kankyo_wether::dKyw_get_wind_pow();
  pcVar1 = d_kankyo_wether::dKyw_get_wind_vec();
  ::cXyz::operator_(&local_4c,pcVar1,(float)dVar4);
  local_34.x = local_4c.x;
  local_34.y = local_4c.y;
  local_34.z = local_4c.z;
  d_kankyo_wether::dKyw_pntwind_get_info((cXyz *)(this + 0x1f8),&cStack64,&local_68);
  mtx::PSVECScale(&cStack64,&cStack64,local_68);
  ::cXyz::operator__(&cStack88,&local_34,&cStack64);
  ::cXyz::operator_(&local_64,&cStack88,(float)((double)d_a_obj::_4110 * dVar3));
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  d_a_obj::total_spd_4082 = local_64.x;
  DAT_803e1f10 = local_64.y;
  DAT_803e1f14 = local_64.z;
  return;
}


namespace daObj {

/* WARNING: Removing unreachable block (ram,0x80066af0) */
/* __thiscall get_path_spd(cBgS_PolyInfo &,
                                  float) */

undefined4 * get_path_spd(cBgS_PolyInfo *param_1,float param_2)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  uint local_28 [2];
  undefined4 local_20;
  uint uStack28;
  undefined auStack8 [8];
  
  dVar4 = (double)param_2;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (d_a_obj::init_4116 == '\0') {
    d_a_obj::path_spd_4114 = ::cXyz::Zero.x;
    DAT_803e1f28 = ::cXyz::Zero.y;
    DAT_803e1f2c = ::cXyz::Zero.z;
    Runtime.PPCEABI.H::__register_global_object
              (&d_a_obj::path_spd_4114,::cXyz::_cXyz,&d_a_obj::_4115);
    d_a_obj::init_4116 = '\x01';
  }
  uVar1 = d_path::dPath_GetPolyRoomPathVec(param_1,(cXyz *)&d_a_obj::path_spd_4114,local_28);
  if ((uVar1 & 0xff) != 0) {
    cVar2 = ::cXyz::normalizeRS((cXyz *)&d_a_obj::path_spd_4114);
    if (cVar2 == '\0') {
      d_a_obj::path_spd_4114 = ::cXyz::Zero.x;
      DAT_803e1f28 = ::cXyz::Zero.y;
      DAT_803e1f2c = ::cXyz::Zero.z;
    }
    else {
      uStack28 = local_28[0] ^ 0x80000000;
      local_20 = 0x43300000;
      mtx::PSVECScale((cXyz *)&d_a_obj::path_spd_4114,(cXyz *)&d_a_obj::path_spd_4114,
                      d_a_obj::_4128 *
                      (float)(dVar4 * (double)(float)((double)CONCAT44(0x43300000,uStack28) -
                                                     d_a_obj::_4130)));
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return &d_a_obj::path_spd_4114;
}

}

/* __thiscall daObj::posMoveF_stream(fopAc_ac_c *,
                                     cXyz const *,
                                     cXyz const *,
                                     float,
                                     float) */

void __thiscall
daObj::posMoveF_stream
          (daObj *this,fopAc_ac_c *param_1,cXyz *param_2,cXyz *param_3,float param_4,float param_5)

{
  posMoveF_grade((fopAc_ac_c *)this,(cXyz *)param_1,param_2,param_4,param_5,(cXyz *)0x0,
                 d_a_obj::_4073,d_a_obj::_4073,(cXyz *)0x0);
  return;
}


namespace daObj {

/* WARNING: Removing unreachable block (ram,0x80066c14) */
/* WARNING: Removing unreachable block (ram,0x80066c1c) */
/* __thiscall @unnamed@d_a_obj_cpp@::posMoveF_resist_acc(cXyz *,
                                                                fopAc_ac_c const *,
                                                                cXyz const *,
                                                                float,
                                                                float) */

void __thiscall
@unnamed@d_a_obj_cpp@::posMoveF_resist_acc
          (_unnamed_d_a_obj_cpp_ *this,cXyz *param_1,fopAc_ac_c *param_2,cXyz *param_3,float param_4
          ,float param_5)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f30;
  undefined8 in_f31;
  cXyz local_58;
  cXyz local_4c;
  float local_40;
  float local_3c;
  float local_38;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar3 = (double)param_5;
  dVar2 = (double)param_4;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  ::cXyz::operator__(&local_58,(cXyz *)&param_1[0x2d].y,(cXyz *)param_2);
  dVar6 = (double)local_58.x;
  local_40 = local_58.x;
  dVar5 = (double)local_58.y;
  local_3c = local_58.y;
  dVar4 = (double)local_58.z;
  local_38 = local_58.z;
  local_4c.x = (float)(dVar6 * dVar2) +
               (float)(dVar3 * (double)(float)(dVar6 * (double)(float)ABS(dVar6)));
  local_4c.y = (float)(dVar5 * dVar2) +
               (float)(dVar3 * (double)(float)(dVar5 * (double)(float)ABS(dVar5)));
  local_4c.z = (float)(dVar4 * dVar2) +
               (float)(dVar3 * (double)(float)(dVar4 * (double)(float)ABS(dVar4)));
  mtx::PSVECScale(&local_4c,&local_4c,d_a_obj::_4169);
  *(float *)this = local_4c.x;
  *(float *)(this + 4) = local_4c.y;
  *(float *)(this + 8) = local_4c.z;
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80066d44) */
/* WARNING: Removing unreachable block (ram,0x80066d4c) */
/* __thiscall @unnamed@d_a_obj_cpp@::posMoveF_grade_acc(cXyz *,
                                                               fopAc_ac_c const *,
                                                               cXyz const *,
                                                               float,
                                                               float,
                                                               cXyz const *,
                                                               cXyz const *) */

void __thiscall
@unnamed@d_a_obj_cpp@::posMoveF_grade_acc
          (_unnamed_d_a_obj_cpp_ *this,cXyz *param_1,fopAc_ac_c *param_2,cXyz *param_3,float param_4
          ,float param_5,cXyz *param_6,cXyz *param_7)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f30;
  undefined8 in_f31;
  cXyz cStack104;
  cXyz cStack92;
  cXyz cStack80;
  cXyz local_44 [2];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar4 = (double)param_5;
  dVar2 = (double)param_4;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  *(float *)this = ::cXyz::Zero.x;
  *(float *)(this + 4) = ::cXyz::Zero.y;
  *(float *)(this + 8) = ::cXyz::Zero.z;
  if (param_2 != (fopAc_ac_c *)0x0) {
    local_44[0].x = param_3->x;
    local_44[0].z = param_3->z;
    local_44[0].y = param_3->y + param_1[0x32].x;
    if (param_6 != (cXyz *)0x0) {
      mtx::PSVECAdd(local_44,param_6,local_44);
    }
    dVar3 = (double)mtx::PSVECDotProduct(local_44,param_2);
    if (dVar3 < (double)d_a_obj::_4073) {
      if ((double)(float)(param_2->parent).parent.mBsPcId <= dVar4) {
        SComponent::cM3d_CrawVec(param_2,local_44,&cStack80);
        mtx::PSVECAdd((cXyz *)this,&cStack80,(cXyz *)this);
      }
      SComponent::cM3d_CrawVec(param_2,&param_1[0x2d].y,&cStack92);
      ::cXyz::operator_(&cStack104,&cStack92,(float)dVar2);
      mtx::PSVECSubtract((cXyz *)this,&cStack104,(cXyz *)this);
    }
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80066fe4) */
/* WARNING: Removing unreachable block (ram,0x80066fd4) */
/* WARNING: Removing unreachable block (ram,0x80066fdc) */
/* WARNING: Removing unreachable block (ram,0x80066fec) */
/* __thiscall posMoveF_grade(fopAc_ac_c *,
                                    cXyz const *,
                                    cXyz const *,
                                    float,
                                    float,
                                    cXyz const *,
                                    float,
                                    float,
                                    cXyz const *) */

void posMoveF_grade
               (fopAc_ac_c *param_1,cXyz *param_2,cXyz *param_3,float param_4,float param_5,
               cXyz *param_6,float param_7,float param_8,cXyz *param_9)

{
  bool bVar1;
  int iVar2;
  ulong uVar3;
  char *pcVar4;
  cXyz *in_r8;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  float local_74;
  float local_70;
  float local_6c;
  cXyz local_68;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar7 = (double)param_7;
  dVar8 = (double)param_8;
  dVar6 = (double)param_5;
  dVar9 = (double)param_4;
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  pcVar4 = (char *)param_6;
  if (param_3 == (cXyz *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    pcVar4 = "stream_spd != 0";
    JUTAssertion::showAssert(uVar3,"d_a_obj.cpp",0x118,"stream_spd != 0");
    m_Do_printf::OSPanic("d_a_obj.cpp",0x118,&DAT_8034fbf4);
  }
  @unnamed@d_a_obj_cpp@::posMoveF_resist_acc
            ((_unnamed_d_a_obj_cpp_ *)&local_68,(cXyz *)param_1,(fopAc_ac_c *)param_3,(cXyz *)pcVar4
             ,(float)dVar9,(float)dVar6);
  bVar1 = false;
  if (((((double)d_a_obj::_4073 <= dVar7) && (dVar7 < (double)d_a_obj::_4070)) &&
      ((double)d_a_obj::_4073 <= dVar8)) && (dVar8 <= (double)d_a_obj::_4070)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar3,"d_a_obj.cpp",0x121,
               "(friction >= 0.0f) && (friction < 1.0f) && (no_grade_cos >= 0.0f) && (no_grade_cos <= 1.0f)"
              );
    m_Do_printf::OSPanic("d_a_obj.cpp",0x121,&DAT_8034fbf4);
  }
  @unnamed@d_a_obj_cpp@::posMoveF_grade_acc
            ((_unnamed_d_a_obj_cpp_ *)&local_74,(cXyz *)param_1,(fopAc_ac_c *)param_6,&local_68,
             (float)dVar7,(float)dVar8,param_9,in_r8);
  iVar2 = (int)((int)(param_1->mCurrent).mRot.y & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  local_74 = local_74 + local_68.x + param_1->mVelocityFwd * JKernel::JMath::jmaSinTable[iVar2];
  local_70 = local_70 + local_68.y + (param_1->mVelocity).y + param_1->mAccelerationY;
  local_6c = local_6c + local_68.z + param_1->mVelocityFwd * JKernel::JMath::jmaCosTable[iVar2];
  if (param_9 != (cXyz *)0x0) {
    local_74 = local_74 + param_9->x;
    local_70 = local_70 + param_9->y;
    local_6c = local_6c + param_9->z;
  }
  if (local_70 < param_1->mVelocityYMin) {
    local_70 = param_1->mVelocityYMin;
  }
  (param_1->mVelocity).x = local_74;
  (param_1->mVelocity).y = local_70;
  (param_1->mVelocity).z = local_6c;
  dVar9 = (double)(local_74 * local_74 + local_6c * local_6c);
  if ((double)d_a_obj::_4073 < dVar9) {
    dVar6 = 1.0 / SQRT(dVar9);
    dVar6 = d_a_obj::_4256 * dVar6 * (d_a_obj::_4257 - dVar9 * dVar6 * dVar6);
    dVar6 = d_a_obj::_4256 * dVar6 * (d_a_obj::_4257 - dVar9 * dVar6 * dVar6);
    dVar9 = (double)(float)(dVar9 * d_a_obj::_4256 * dVar6 *
                                    (d_a_obj::_4257 - dVar9 * dVar6 * dVar6));
  }
  param_1->mVelocityFwd = (float)dVar9;
  iVar2 = SComponent::cM_atan2s(local_74,local_6c);
  (param_1->mCurrent).mRot.y = (short)iVar2;
  f_op_actor_mng::fopAcM_posMove(param_1,param_2);
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  __psq_l0(auStack56,uVar5);
  __psq_l1(auStack56,uVar5);
  return;
}

}

/* WARNING: Removing unreachable block (ram,0x800671ac) */
/* WARNING: Removing unreachable block (ram,0x800671b4) */
/* __thiscall daObj::quat_rotBaseY(Quaternion *,
                                   cXyz const &) */

void __thiscall daObj::quat_rotBaseY(daObj *this,Quaternion *param_1,cXyz *param_2)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar4;
  float fVar5;
  cXyz local_64;
  cXyz local_58;
  float local_4c;
  float local_48;
  float local_44;
  cXyz local_40 [2];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  fVar5 = mtx::PSVECSquareMag((cXyz *)param_1);
  dVar3 = (double)fVar5;
  if (dVar3 <= (double)d_a_obj::_4304) {
    *(undefined4 *)this = d_a_obj::zero_quat_4265;
    *(undefined4 *)(this + 4) = DAT_8034fbbc;
    *(undefined4 *)(this + 8) = DAT_8034fbc0;
    *(undefined4 *)(this + 0xc) = DAT_8034fbc4;
  }
  else {
    ::cXyz::outprod(&local_58,&::cXyz::BaseY,(cXyz *)param_1);
    local_40[0].x = local_58.x;
    local_40[0].y = local_58.y;
    local_40[0].z = local_58.z;
    fVar5 = mtx::PSVECSquareMag(local_40);
    dVar4 = (double)fVar5;
    if (dVar4 <= (double)d_a_obj::_4304) {
      *(undefined4 *)this = d_a_obj::zero_quat_4265;
      *(undefined4 *)(this + 4) = DAT_8034fbbc;
      *(undefined4 *)(this + 8) = DAT_8034fbc0;
      *(undefined4 *)(this + 0xc) = DAT_8034fbc4;
    }
    else {
      ::cXyz::operator__(&local_64,(float)dVar3);
      local_4c = local_64.x;
      local_48 = local_64.y;
      local_44 = local_64.z;
      dVar3 = (double)mtx::PSVECDotProduct(&::cXyz::BaseY,&local_4c);
      dVar3 = MSL_C.PPCEABI.bare.H::acos(dVar3);
      dVar3 = (double)(float)dVar3;
      if ((double)d_a_obj::_4073 < dVar4) {
        dVar2 = 1.0 / SQRT(dVar4);
        dVar2 = d_a_obj::_4256 * dVar2 * (d_a_obj::_4257 - dVar4 * dVar2 * dVar2);
        dVar2 = d_a_obj::_4256 * dVar2 * (d_a_obj::_4257 - dVar4 * dVar2 * dVar2);
        dVar4 = (double)(float)(dVar4 * d_a_obj::_4256 * dVar2 *
                                        (d_a_obj::_4257 - dVar4 * dVar2 * dVar2));
      }
      mtx::PSVECScale(local_40,local_40,(float)((double)d_a_obj::_4070 / dVar4));
      mtx::C_QUATRotAxisRad(dVar3,this,local_40);
    }
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80067360) */
/* __thiscall daObj::quat_rotBaseY2(Quaternion *,
                                    cXyz const &) */

void __thiscall daObj::quat_rotBaseY2(daObj *this,Quaternion *param_1,cXyz *param_2)

{
  float fVar1;
  char cVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f31;
  cXyz local_34;
  cXyz local_28;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  local_28.x = param_1->x;
  local_28.y = param_1->y;
  local_28.z = param_1->z;
  cVar2 = ::cXyz::normalizeRS(&local_28);
  if (cVar2 == '\0') {
    *(undefined4 *)this = d_a_obj::zero_quat_4309;
    *(undefined4 *)(this + 4) = DAT_8034fbcc;
    *(undefined4 *)(this + 8) = DAT_8034fbd0;
    *(undefined4 *)(this + 0xc) = DAT_8034fbd4;
  }
  else {
    dVar5 = (double)mtx::PSVECDotProduct(&::cXyz::BaseY,&local_28);
    dVar5 = (double)(d_a_obj::_4341 * (float)((double)d_a_obj::_4070 + dVar5));
    if ((double)d_a_obj::_4073 < dVar5) {
      dVar4 = 1.0 / SQRT(dVar5);
      dVar4 = d_a_obj::_4256 * dVar4 * (d_a_obj::_4257 - dVar5 * dVar4 * dVar4);
      dVar4 = d_a_obj::_4256 * dVar4 * (d_a_obj::_4257 - dVar5 * dVar4 * dVar4);
      dVar5 = (double)(float)(dVar5 * d_a_obj::_4256 * dVar4 *
                                      (d_a_obj::_4257 - dVar5 * dVar4 * dVar4));
    }
    ::cXyz::outprod(&local_34,&::cXyz::BaseY,&local_28);
    if ((float)ABS(dVar5) <= d_a_obj::_4342) {
      *(undefined4 *)this = d_a_obj::zero_quat_4309;
      *(undefined4 *)(this + 4) = DAT_8034fbcc;
      *(undefined4 *)(this + 8) = DAT_8034fbd0;
      *(undefined4 *)(this + 0xc) = DAT_8034fbd4;
    }
    else {
      fVar1 = (float)((double)d_a_obj::_4070 / dVar5);
      *(float *)this = local_34.x * fVar1;
      *(float *)(this + 4) = local_34.y * fVar1;
      *(float *)(this + 8) = local_34.z * fVar1;
      *(float *)(this + 0xc) = (float)((double)d_a_obj::_4110 * dVar5);
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80067508) */
/* __thiscall daObj::quat_rotBaseZ(Quaternion *,
                                   cXyz const &) */

void __thiscall daObj::quat_rotBaseZ(daObj *this,Quaternion *param_1,cXyz *param_2)

{
  float fVar1;
  char cVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f31;
  cXyz local_34;
  cXyz local_28;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  local_28.x = param_1->x;
  local_28.y = param_1->y;
  local_28.z = param_1->z;
  cVar2 = ::cXyz::normalizeRS(&local_28);
  if (cVar2 == '\0') {
    *(float *)this = d_lib::ZeroQuat.x;
    *(float *)(this + 4) = d_lib::ZeroQuat.y;
    *(float *)(this + 8) = d_lib::ZeroQuat.z;
    *(float *)(this + 0xc) = d_lib::ZeroQuat.w;
  }
  else {
    dVar5 = (double)mtx::PSVECDotProduct(&::cXyz::BaseZ,&local_28);
    dVar5 = (double)(d_a_obj::_4341 * (float)((double)d_a_obj::_4070 + dVar5));
    if ((double)d_a_obj::_4073 < dVar5) {
      dVar4 = 1.0 / SQRT(dVar5);
      dVar4 = d_a_obj::_4256 * dVar4 * (d_a_obj::_4257 - dVar5 * dVar4 * dVar4);
      dVar4 = d_a_obj::_4256 * dVar4 * (d_a_obj::_4257 - dVar5 * dVar4 * dVar4);
      dVar5 = (double)(float)(dVar5 * d_a_obj::_4256 * dVar4 *
                                      (d_a_obj::_4257 - dVar5 * dVar4 * dVar4));
    }
    ::cXyz::outprod(&local_34,&::cXyz::BaseZ,&local_28);
    if ((float)ABS(dVar5) <= d_a_obj::_4342) {
      *(float *)this = d_lib::ZeroQuat.x;
      *(float *)(this + 4) = d_lib::ZeroQuat.y;
      *(float *)(this + 8) = d_lib::ZeroQuat.z;
      *(float *)(this + 0xc) = d_lib::ZeroQuat.w;
    }
    else {
      fVar1 = (float)((double)d_a_obj::_4070 / dVar5);
      *(float *)this = local_34.x * fVar1;
      *(float *)(this + 4) = local_34.y * fVar1;
      *(float *)(this + 8) = local_34.z * fVar1;
      *(float *)(this + 0xc) = (float)((double)d_a_obj::_4110 * dVar5);
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Removing unreachable block (ram,0x800676d0) */
/* __thiscall daObj::quat_rotVec(Quaternion *,
                                 cXyz const &,
                                 cXyz const &) */

void __thiscall daObj::quat_rotVec(daObj *this,Quaternion *param_1,cXyz *param_2,cXyz *param_3)

{
  float fVar1;
  char cVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f31;
  cXyz local_44;
  cXyz local_38;
  cXyz local_2c [2];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  local_2c[0].x = param_2->x;
  local_2c[0].y = param_2->y;
  local_2c[0].z = param_2->z;
  local_38.x = param_1->x;
  local_38.y = param_1->y;
  local_38.z = param_1->z;
  cVar2 = ::cXyz::normalizeRS(local_2c);
  if ((cVar2 == '\0') || (cVar2 = ::cXyz::normalizeRS(&local_38), cVar2 == '\0')) {
    *(float *)this = d_lib::ZeroQuat.x;
    *(float *)(this + 4) = d_lib::ZeroQuat.y;
    *(float *)(this + 8) = d_lib::ZeroQuat.z;
    *(float *)(this + 0xc) = d_lib::ZeroQuat.w;
  }
  else {
    dVar5 = (double)mtx::PSVECDotProduct(&local_38,local_2c);
    dVar5 = (double)(d_a_obj::_4341 * (float)((double)d_a_obj::_4070 + dVar5));
    if ((double)d_a_obj::_4073 < dVar5) {
      dVar4 = 1.0 / SQRT(dVar5);
      dVar4 = d_a_obj::_4256 * dVar4 * (d_a_obj::_4257 - dVar5 * dVar4 * dVar4);
      dVar4 = d_a_obj::_4256 * dVar4 * (d_a_obj::_4257 - dVar5 * dVar4 * dVar4);
      dVar5 = (double)(float)(dVar5 * d_a_obj::_4256 * dVar4 *
                                      (d_a_obj::_4257 - dVar5 * dVar4 * dVar4));
    }
    ::cXyz::outprod(&local_44,&local_38,local_2c);
    if ((float)ABS(dVar5) <= d_a_obj::_4342) {
      *(float *)this = d_lib::ZeroQuat.x;
      *(float *)(this + 4) = d_lib::ZeroQuat.y;
      *(float *)(this + 8) = d_lib::ZeroQuat.z;
      *(float *)(this + 0xc) = d_lib::ZeroQuat.w;
    }
    else {
      fVar1 = (float)((double)d_a_obj::_4070 / dVar5);
      *(float *)this = local_44.x * fVar1;
      *(float *)(this + 4) = local_44.y * fVar1;
      *(float *)(this + 8) = local_44.z * fVar1;
      *(float *)(this + 0xc) = (float)((double)d_a_obj::_4110 * dVar5);
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __thiscall daObj::SetCurrentRoomNo(fopAc_ac_c *,
                                      dBgS_GndChk *) */

void __thiscall daObj::SetCurrentRoomNo(daObj *this,fopAc_ac_c *param_1,dBgS_GndChk *param_2)

{
  int iVar1;
  
  iVar1 = dBgS::GetRoomId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                          (cBgS_PolyInfo *)&(param_1->parent).parent.mpCtRq);
  if (-1 < iVar1) {
    this[0x20a] = SUB41(iVar1,0);
  }
  return;
}


namespace daObj {

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall HitSeStart(cXyz const *,
                                int,
                                dCcD_GObjInf const *,
                                unsigned long) */

void HitSeStart(cXyz *param_1,int param_2,dCcD_GObjInf *param_3,ulong param_4)

{
  bool bVar1;
  bool bVar2;
  char cVar5;
  fopAc_ac_c *pfVar3;
  cCcD_Obj *pcVar4;
  sbyte sVar6;
  cCcD_Obj__DamageTypes cVar7;
  bool bVar8;
  ulong unaff_r26;
  
  cVar5 = dCcD_GObjInf::GetTgHitObjSe(param_3);
  pfVar3 = dCcD_GAtTgCoCommonBase::GetAc(&(param_3->mObjTg).parent);
  pcVar4 = dCcD_GObjInf::GetTgHitObj(param_3);
  bVar8 = false;
  if (cVar5 != '\0') {
    if (pfVar3 != (fopAc_ac_c *)0x0) {
      if (pcVar4 != (cCcD_Obj *)0x0) {
        cVar7 = (pcVar4->parent).mObjAt.mDamageTypes;
        if ((cVar7 & SkullHammer) == 0) {
          if ((cVar7 & (NormalArrow|FireArrows|IceArrows|LightArrow)) == 0) {
            if ((cVar7 & 0x8000) == 0) {
              if ((pfVar3->parent).parent.mBsTypeId == 0xa9) {
                bVar2 = true;
                bVar1 = true;
                if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                     mEquippedSword != MasterSwordPowerless) &&
                   (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedSword
                    != MasterSwordHalfPower)) {
                  bVar1 = false;
                }
                if ((!bVar1) &&
                   (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedSword
                    != MasterSwordFullPower)) {
                  bVar2 = false;
                }
                if (bVar2) {
                  bVar8 = true;
                }
              }
              if (cVar5 == '\x04') {
                unaff_r26 = 0x2833;
              }
              else {
                if (cVar5 == '\x05') {
                  unaff_r26 = 0x2834;
                }
                else {
                  if (bVar8) {
                    unaff_r26 = 0x2805;
                  }
                  else {
                    unaff_r26 = 0x2803;
                  }
                }
              }
            }
            else {
              unaff_r26 = 0x287b;
            }
          }
          else {
            unaff_r26 = 0x287a;
          }
        }
        else {
          unaff_r26 = 0x2855;
        }
      }
    }
    sVar6 = d_com_inf_game::dComIfGp_getReverb(param_2);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,unaff_r26,param_1,param_4 & 0xff,sVar6,d_a_obj::_4070,
               d_a_obj::_4070,d_a_obj::_4169,d_a_obj::_4169,0);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall HitEff_sub_kikuzu(cXyz const *,
                                       cXyz const *,
                                       dKy_tevstr_c const *) */

void HitEff_sub_kikuzu(cXyz *param_1,cXyz *param_2,dKy_tevstr_c *param_3)

{
  int iVar1;
  JPABaseEmitter *pJVar2;
  double dVar3;
  double dVar4;
  float fVar5;
  csXyz local_24;
  cXyz local_1c;
  
  local_1c.z = param_2->z;
  local_1c.x = param_2->x;
  local_1c.y = d_a_obj::_4073;
  fVar5 = mtx::PSVECSquareMag(&local_1c);
  dVar4 = (double)fVar5;
  if ((double)d_a_obj::_4073 < dVar4) {
    dVar3 = 1.0 / SQRT(dVar4);
    dVar3 = d_a_obj::_4256 * dVar3 * (d_a_obj::_4257 - dVar4 * dVar3 * dVar3);
    dVar3 = d_a_obj::_4256 * dVar3 * (d_a_obj::_4257 - dVar4 * dVar3 * dVar3);
    dVar4 = (double)(float)(dVar4 * d_a_obj::_4256 * dVar3 *
                                    (d_a_obj::_4257 - dVar4 * dVar3 * dVar3));
  }
  iVar1 = SComponent::cM_atan2s(param_2->y,(float)dVar4);
  local_24.x = (short)iVar1;
  iVar1 = SComponent::cM_atan2s(param_2->x,param_2->z);
  local_24.y = (short)iVar1;
  local_24.z = 0;
  pJVar2 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x2b,param_1,
                              &local_24,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1,
                              &param_3->mColorK0,&param_3->mColorK0,(cXyz *)0x0);
  if (pJVar2 != (JPABaseEmitter *)0x0) {
    pJVar2->mRate = d_a_obj::_4531;
    pJVar2->mMaxFrame = 1;
    pJVar2->mSpread = d_a_obj::_4532;
    pJVar2->mVolumeSweep = d_a_obj::_4533;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall HitEff_kikuzu(fopAc_ac_c const *,
                                   dCcD_Cyl const *) */

void HitEff_kikuzu(fopAc_ac_c *param_1,dCcD_Cyl *param_2)

{
  char cVar3;
  float *pfVar1;
  int iVar2;
  cXyz *pcVar4;
  float fVar5;
  cXyz local_28;
  cXyz local_1c;
  
  cVar3 = dCcD_GObjInf::GetTgHitObjSe(&param_2->parent);
  if (cVar3 != '\0') {
    pcVar4 = &(param_2->parent).mObjTg.mHitPos;
    ::cXyz::operator_(&local_28,&(param_2->parent).mObjTg.mAtVel,d_a_obj::_4169);
    local_1c.x = local_28.x;
    local_1c.y = local_28.y;
    local_1c.z = local_28.z;
    fVar5 = mtx::PSVECSquareMag(&local_1c);
    if (fVar5 < d_a_obj::_4558) {
      pfVar1 = (float *)(*(code *)((param_2->mCylAttr).parent.vtbl)->GetCoCP)(&param_2->mCylAttr);
      local_1c.x = pcVar4->x - *pfVar1;
      local_1c.y = d_a_obj::_4073;
      iVar2 = (*(code *)((param_2->mCylAttr).parent.vtbl)->GetCoCP)(&param_2->mCylAttr);
      local_1c.z = (param_2->parent).mObjTg.mHitPos.z - *(float *)(iVar2 + 8);
    }
    HitEff_sub_kikuzu(pcVar4,&local_1c,&param_1->mTevStr);
  }
  return;
}

}

/* __thiscall cCcD_CylAttr::GetCoCP(void) */

cM3dGCyl * __thiscall cCcD_CylAttr::GetCoCP(cCcD_CylAttr *this)

{
  return &this->mCyl;
}


/* __thiscall cCcD_SphAttr::GetCoCP(void) */

cM3dGSph * __thiscall cCcD_SphAttr::GetCoCP(cCcD_SphAttr *this)

{
  return &this->mSph;
}


/* __thiscall daObj::HitEff_hibana(cXyz const *,
                                   cXyz const *) */

void __thiscall daObj::HitEff_hibana(daObj *this,cXyz *param_1,cXyz *param_2)

{
  int iVar1;
  JPABaseEmitter *pJVar2;
  double dVar3;
  double dVar4;
  float fVar5;
  csXyz local_24;
  cXyz local_1c;
  
  local_1c.z = param_1->z;
  local_1c.x = param_1->x;
  local_1c.y = d_a_obj::_4073;
  fVar5 = mtx::PSVECSquareMag(&local_1c);
  dVar4 = (double)fVar5;
  if ((double)d_a_obj::_4073 < dVar4) {
    dVar3 = 1.0 / SQRT(dVar4);
    dVar3 = d_a_obj::_4256 * dVar3 * (d_a_obj::_4257 - dVar4 * dVar3 * dVar3);
    dVar3 = d_a_obj::_4256 * dVar3 * (d_a_obj::_4257 - dVar4 * dVar3 * dVar3);
    dVar4 = (double)(float)(dVar4 * d_a_obj::_4256 * dVar3 *
                                    (d_a_obj::_4257 - dVar4 * dVar3 * dVar3));
  }
  iVar1 = SComponent::cM_atan2s(param_1->y,(float)dVar4);
  local_24.x = (short)iVar1 + 0x4000;
  iVar1 = SComponent::cM_atan2s(param_1->x,param_1->z);
  local_24.y = (short)iVar1;
  local_24.z = 0;
  pJVar2 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x2c,
                              (cXyz *)this,&local_24,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1,
                              (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
  fVar5 = d_a_obj::_4069;
  if (pJVar2 != (JPABaseEmitter *)0x0) {
    pJVar2->mRate = d_a_obj::_4069;
    pJVar2->mMaxFrame = 1;
    pJVar2->mInitialVelAxis = fVar5;
    pJVar2->mInitialVelDir = fVar5;
  }
  return;
}


namespace daObj {

/* __thiscall HitEff_hibana(fopAc_ac_c const *,
                                   dCcD_Cyl const *) */

void HitEff_hibana(fopAc_ac_c *param_1,dCcD_Cyl *param_2)

{
  char cVar3;
  float *pfVar1;
  int iVar2;
  cXyz *in_r5;
  cXyz *this;
  float fVar4;
  cXyz local_28;
  cXyz local_1c;
  
  cVar3 = dCcD_GObjInf::GetTgHitObjSe(&param_2->parent);
  if (cVar3 != '\0') {
    this = &(param_2->parent).mObjTg.mHitPos;
    ::cXyz::operator_(&local_28,&(param_2->parent).mObjTg.mAtVel,d_a_obj::_4169);
    local_1c.x = local_28.x;
    local_1c.y = local_28.y;
    local_1c.z = local_28.z;
    fVar4 = mtx::PSVECSquareMag(&local_1c);
    if (fVar4 < d_a_obj::_4558) {
      pfVar1 = (float *)(*(code *)((param_2->mCylAttr).parent.vtbl)->GetCoCP)(&param_2->mCylAttr);
      local_1c.x = this->x - *pfVar1;
      local_1c.y = d_a_obj::_4073;
      iVar2 = (*(code *)((param_2->mCylAttr).parent.vtbl)->GetCoCP)(&param_2->mCylAttr);
      local_1c.z = (param_2->parent).mObjTg.mHitPos.z - *(float *)(iVar2 + 8);
    }
    HitEff_hibana((daObj *)this,&local_1c,in_r5);
  }
  return;
}

