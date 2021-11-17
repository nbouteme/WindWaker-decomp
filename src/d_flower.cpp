#include <d_flower.h>
#include <mtx/vec.h>
#include <SComponent/c_math.h>
#include <d_particle.h>
#include <d_flower.h>
#include <d_cc_d.h>
#include <SComponent/c_sxyz.h>
#include <c_damagereaction.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <f_op_actor_mng.h>
#include <d_com_inf_game.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_cc_mass_s.h>
#include <SComponent/c_lib.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <J3DGraphBase/J3DSys.h>
#include <gx/GXBump.h>
#include <gx/GXAttr.h>
#include <gx/GXDisplayList.h>
#include <gx/GXTev.h>
#include <d_kankyo.h>
#include <gx/GXTransform.h>
#include <d_tree.h>
#include <SComponent/c_xyz.h>
#include <SComponent/c_m3d_g_cyl.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <SComponent/c_bg_s.h>
#include <SComponent/c_bg_s_chk.h>
#include <m_Do_mtx.h>
#include <mtx/mtx.h>
#include <m_Do_audio.h>
#include <J3DU/J3DUClipper.h>
#include <J3DGraphBase/J3DDrawBuffer.h>
#include <f_op_overlap_mng.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <dFlower_room_c.h>
#include <dFlower_packet_c.h>
#include <dFlower_anm_c.h>
#include <dFlower_data_c.h>


namespace d_flower {
undefined1 l_CutSoundFlag;
undefined1 init$4230;
undefined ang$4228;
}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x800bfd08) */
/* __thiscall dFlower_data_c::WorkCo(fopAc_ac_c *,
                                     unsigned long,
                                     int) */

void __thiscall
dFlower_data_c::WorkCo(dFlower_data_c *this,fopAc_ac_c *param_1,ulong param_2,int param_3)

{
  dFlower_data_c dVar1;
  _GXColor *pPrmColor;
  dFlower_packet_c *pdVar2;
  int iVar3;
  JPABaseEmitter *pJVar4;
  int iVar5;
  ushort userID;
  undefined4 uVar6;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  float fVar9;
  cXyz local_44;
  cXyz local_38;
  float local_2c;
  float local_28;
  float local_24;
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  local_44.x = *(float *)(this + 4) - (param_1->mCurrent).mPos.x;
  local_44.z = *(float *)(this + 0xc) - (param_1->mCurrent).mPos.z;
  local_44.y = d_flower::_4094;
  local_2c = local_44.x;
  local_24 = local_44.z;
  fVar9 = mtx::PSVECSquareMag(&local_44);
  dVar8 = (double)fVar9;
  if (dVar8 <= (double)d_flower::_4095) {
    local_28 = *(float *)(this + 8) - (param_1->mCurrent).mPos.y;
    iVar3 = SComponent::cM_atan2s(local_2c,local_24);
    if ((double)d_flower::_4094 < dVar8) {
      dVar7 = 1.0 / SQRT(dVar8);
      dVar7 = d_flower::_4096 * dVar7 * (d_flower::_4097 - dVar8 * dVar7 * dVar7);
      dVar7 = d_flower::_4096 * dVar7 * (d_flower::_4097 - dVar8 * dVar7 * dVar7);
      dVar8 = (double)(float)(dVar8 * d_flower::_4096 * dVar7 *
                                      (d_flower::_4097 - dVar8 * dVar7 * dVar7));
    }
    if ((char)this[1] < 8) {
      if (((this[3] == (dFlower_data_c)0x0) && (dVar1 = *this, ((byte)dVar1 & 8) == 0)) &&
         (d_flower::_4098 < param_1->mVelocityFwd)) {
        local_38.z = *(float *)(this + 0xc);
        local_38.y = d_flower::_4099 + *(float *)(this + 8);
        local_38.x = *(float *)(this + 4);
        if (((byte)dVar1 & 0x20) == 0) {
          userID = 0x3de;
        }
        else {
          if (((byte)dVar1 & 0x40) == 0) {
            userID = 0x3dd;
          }
          else {
            userID = 0x82c6;
          }
        }
        pPrmColor = &dStage_roomControl_c::mStatus[param_3].mTevStr.mColorK0;
        pJVar4 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,userID,
                                    &local_38,(csXyz *)0x0,(cXyz *)0x0,0xff,
                                    (dPa_levelEcallBack *)0x0,(char)param_3,pPrmColor,pPrmColor,
                                    (cXyz *)0x0);
        if (pJVar4 != (JPABaseEmitter *)0x0) {
          fVar9 = d_flower::_4101;
          if (userID == 0x82c6) {
            fVar9 = d_flower::_4100;
          }
          pJVar4->mRate = fVar9;
          this[3] = (dFlower_data_c)0x10;
        }
      }
      iVar5 = dFlower_packet_c::newAnm(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFlowerPacket);
      if (iVar5 < 0) goto LAB_800bfd08;
      this[1] = SUB41(iVar5,0);
      pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFlowerPacket +
               (char)this[1] * 0x38 + 0x3534;
    }
    else {
      pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFlowerPacket +
               (char)this[1] * 0x38 + 0x3534;
    }
    *(short *)(pdVar2 + 2) = (short)iVar3;
    iVar3 = SComponent::cM_atan2s((float)((double)d_flower::_4102 - dVar8),d_flower::_4103);
    *(short *)(pdVar2 + 4) = (short)iVar3;
  }
LAB_800bfd08:
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x800bfff8) */
/* __thiscall dFlower_data_c::WorkAt_NoCutAnim(fopAc_ac_c *,
                                               unsigned long,
                                               int,
                                               dCcMassS_HitInf *,
                                               cCcD_Obj *) */

void __thiscall
dFlower_data_c::WorkAt_NoCutAnim
          (dFlower_data_c *this,fopAc_ac_c *param_1,ulong param_2,int param_3,
          dCcMassS_HitInf *param_4,cCcD_Obj *param_5)

{
  dFlower_data_c dVar1;
  _GXColor *pPrmColor;
  dFlower_packet_c *pdVar2;
  dCcD_GObjInf *pdVar3;
  int iVar4;
  JPABaseEmitter *pJVar5;
  int iVar6;
  ushort userID;
  undefined4 uVar7;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  float fVar10;
  cXyz local_64;
  cXyz local_58;
  cXyz local_4c;
  cXyz local_40;
  float local_34;
  float local_30;
  float local_2c;
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  pdVar3 = d_cc_d::dCcD_GetGObjInf(param_5);
  local_4c.x = (pdVar3->mObjAt).mVel.x;
  local_30 = (pdVar3->mObjAt).mVel.y;
  local_4c.z = (pdVar3->mObjAt).mVel.z;
  local_4c.y = d_flower::_4094;
  local_34 = local_4c.x;
  local_2c = local_4c.z;
  fVar10 = mtx::PSVECSquareMag(&local_4c);
  if ((ABS(fVar10) < SComponent::G_CM3D_F_ABS_MIN) && ((param_1->parent).parent.mProcName == 0xa9))
  {
    local_58.x = *(float *)(this + 4) - (param_1->mCurrent).mPos.x;
    local_30 = *(float *)(this + 8) - (param_1->mCurrent).mPos.y;
    local_58.z = *(float *)(this + 0xc) - (param_1->mCurrent).mPos.z;
    local_58.y = d_flower::_4094;
    local_34 = local_58.x;
    local_2c = local_58.z;
    mtx::PSVECSquareMag(&local_58);
  }
  local_64.x = local_34;
  local_64.y = d_flower::_4094;
  local_64.z = local_2c;
  fVar10 = mtx::PSVECSquareMag(&local_64);
  dVar9 = (double)fVar10;
  iVar4 = SComponent::cM_atan2s(local_34,local_2c);
  if ((double)d_flower::_4094 < dVar9) {
    dVar8 = 1.0 / SQRT(dVar9);
    dVar8 = d_flower::_4096 * dVar8 * (d_flower::_4097 - dVar9 * dVar8 * dVar8);
    dVar8 = d_flower::_4096 * dVar8 * (d_flower::_4097 - dVar9 * dVar8 * dVar8);
    dVar9 = (double)(float)(dVar9 * d_flower::_4096 * dVar8 *
                                    (d_flower::_4097 - dVar9 * dVar8 * dVar8));
  }
  if ((char)this[1] < 8) {
    if (((this[3] == (dFlower_data_c)0x0) && (dVar1 = *this, ((byte)dVar1 & 8) == 0)) &&
       ((double)d_flower::_4098 < dVar9)) {
      local_40.z = *(float *)(this + 0xc);
      local_40.y = d_flower::_4099 + *(float *)(this + 8);
      local_40.x = *(float *)(this + 4);
      if (((byte)dVar1 & 0x20) == 0) {
        userID = 0x3de;
      }
      else {
        if (((byte)dVar1 & 0x40) == 0) {
          userID = 0x3dd;
        }
        else {
          userID = 0x82c6;
        }
      }
      pPrmColor = &dStage_roomControl_c::mStatus[param_3].mTevStr.mColorK0;
      pJVar5 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,userID,
                                  &local_40,(csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,
                                  (char)param_3,pPrmColor,pPrmColor,(cXyz *)0x0);
      if (pJVar5 != (JPABaseEmitter *)0x0) {
        fVar10 = d_flower::_4101;
        if (userID == 0x82c6) {
          fVar10 = d_flower::_4100;
        }
        pJVar5->mRate = fVar10;
        this[3] = (dFlower_data_c)0x10;
      }
    }
    iVar6 = dFlower_packet_c::newAnm(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFlowerPacket);
    if (iVar6 < 0) goto LAB_800bfff8;
    this[1] = SUB41(iVar6,0);
    pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFlowerPacket + (char)this[1] * 0x38 + 0x3534
    ;
  }
  else {
    pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFlowerPacket + (char)this[1] * 0x38 + 0x3534
    ;
  }
  *(short *)(pdVar2 + 2) = (short)iVar4;
  iVar4 = SComponent::cM_atan2s((float)dVar9,d_flower::_4103);
  *(short *)(pdVar2 + 4) = (short)iVar4;
LAB_800bfff8:
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dFlower_data_c::WorkAt(fopAc_ac_c *,
                                     unsigned long,
                                     int,
                                     dCcMassS_HitInf *) */

void __thiscall
dFlower_data_c::WorkAt
          (dFlower_data_c *this,fopAc_ac_c *param_1,ulong param_2,int param_3,
          dCcMassS_HitInf *param_4)

{
  _GXColor *p_Var1;
  cCcD_Obj__DamageTypes cVar2;
  sbyte sVar3;
  ushort userID;
  cCcD_Obj *pcVar4;
  cXyz local_28 [2];
  
  pcVar4 = param_4->mpAtObj;
  if (pcVar4 == (cCcD_Obj *)0x0) {
LAB_800c0084:
    if (7 < (char)this[1]) {
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFlowerPacket[(char)this[1] * 0x38 + 0x3534] =
           (dFlower_packet_c)0x0;
    }
    *this = (dFlower_data_c)((byte)*this | 8);
    if (d_flower::init_4230 == '\0') {
      ::csXyz::csXyz((csXyz *)&d_flower::ang_4228,0,0,0);
      Runtime.PPCEABI.H::__register_global_object();
      d_flower::init_4230 = '\x01';
    }
    local_28[0].z = *(float *)(this + 0xc);
    local_28[0].y = *(float *)(this + 8);
    local_28[0].x = *(float *)(this + 4);
    if (((byte)*this & 0x20) == 0) {
      userID = 0x3de;
    }
    else {
      if (((byte)*this & 0x40) == 0) {
        userID = 0x3dd;
      }
      else {
        p_Var1 = &dStage_roomControl_c::mStatus[param_3].mTevStr.mColorK0;
        dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x82c7,local_28,
                           (csXyz *)&d_flower::ang_4228,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,
                           (char)param_3,p_Var1,p_Var1,(cXyz *)0x0);
        userID = 0x82c6;
      }
    }
    p_Var1 = &dStage_roomControl_c::mStatus[param_3].mTevStr.mColorK0;
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,userID,local_28,
                       (csXyz *)&d_flower::ang_4228,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,
                       (char)param_3,p_Var1,p_Var1,(cXyz *)0x0);
    if (-1 < (char)this[2]) {
      f_op_actor_mng::fopAcM_createItemFromTable
                (this + 4,(int)(char)this[2],0xffffffff,param_3,0,0,1,0);
    }
    if (d_flower::l_CutSoundFlag == '\0') {
      d_flower::l_CutSoundFlag = '\x01';
      sVar3 = d_com_inf_game::dComIfGp_getReverb(param_3);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x282c,(cXyz *)(this + 4),0,sVar3,d_flower::_4101,
                 d_flower::_4101,d_flower::_4274,d_flower::_4274,0);
    }
  }
  else {
    cVar2 = (pcVar4->parent).mObjAt.mDamageTypes;
    if ((cVar2 & DekuLeafWind) == 0) {
      if ((cVar2 & NormalArrow) == 0) {
        if ((cVar2 & FireArrows) == 0) {
          if ((cVar2 & IceArrows) == 0) {
            if (((cVar2 & LightArrow) == 0) && ((cVar2 & 0x8000) == 0)) goto LAB_800c0084;
          }
        }
      }
    }
    WorkAt_NoCutAnim(this,param_1,param_2,param_3,param_4,pcVar4);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dFlower_data_c::hitCheck(fopAc_ac_c *,
                                       int) */

void __thiscall dFlower_data_c::hitCheck(dFlower_data_c *this,fopAc_ac_c *param_1,int param_2)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  short sVar7;
  int iVar6;
  dFlower_packet_c *pdVar8;
  fopAc_ac_c *local_28;
  dCcMassS_HitInf dStack36;
  
  dStack36.vtbl = (undefined *)&dCcMassS_HitInf::__vt;
  uVar5 = dCcMassS_Mng::Chk(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng,
                            (cXyz *)(this + 4),&local_28,&dStack36);
  bVar4 = false;
  if ((uVar5 & 1) != 0) {
    bVar3 = false;
    bVar2 = false;
    if (local_28 != (fopAc_ac_c *)0x0) {
      if ((local_28->parent).parent.mProcName != 0x1cb) {
        bVar2 = true;
      }
    }
    if (bVar2) {
      if ((local_28->parent).parent.mProcName != 0x1cc) {
        bVar3 = true;
      }
    }
    if (bVar3) {
      bVar4 = true;
    }
  }
  if (((uVar5 & 2) != 0) || (bVar4)) {
    if ((uVar5 & 2) != 0) {
      WorkCo(this,local_28,uVar5,param_2);
    }
    if ((((byte)*this & 8) == 0) && (bVar4)) {
      WorkAt(this,local_28,uVar5,param_2,&dStack36);
    }
  }
  else {
    if (7 < (char)this[1]) {
      pdVar8 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFlowerPacket +
               (char)this[1] * 0x38 + 0x3534;
      uVar1 = *(ushort *)(pdVar8 + 2);
      sVar7 = SComponent::cLib_addCalcAngleS
                        ((short *)(pdVar8 + 4),
                         *(short *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFlowerPacket +
                                   ((uint)(int)(short)uVar1 >> 0xd & 7) * 0x38 + 0x3538),0x10,4000,
                         100);
      if ((sVar7 == 0) &&
         (iVar6 = SComponent::cLib_chaseAngleS(pdVar8 + 2,(int)(short)(uVar1 & 0xe000),800),
         iVar6 != 0)) {
        d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFlowerPacket[(char)this[1] * 0x38 + 0x3534] =
             (dFlower_packet_c)0x0;
        this[1] = (dFlower_data_c)((byte)((uint)(int)*(short *)(pdVar8 + 2) >> 0xd) & 7);
      }
    }
  }
  return;
}


/* __thiscall dFlower_room_c::newData(dFlower_data_c *) */

void __thiscall dFlower_room_c::newData(dFlower_room_c *this,dFlower_data_c *param_1)

{
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)this;
  *(dFlower_data_c **)this = param_1;
  return;
}


/* __thiscall dFlower_room_c::deleteData(void) */

void __thiscall dFlower_room_c::deleteData(dFlower_room_c *this)

{
  while (*(undefined **)this != (undefined *)0x0) {
    **(undefined **)this = 0;
    JAIZelBasic::seDeleteObject(JAIZelBasic::zel_basic,(Vec *)(*(int *)this + 4));
    *(undefined4 *)this = *(undefined4 *)(*(int *)this + 0x40);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dFlower_packet_c::dFlower_packet_c(void) */

void __thiscall dFlower_packet_c::dFlower_packet_c(dFlower_packet_c *this)

{
  dFlower_packet_c *pdVar1;
  short sVar2;
  int iVar3;
  
  *(undefined ***)this = &J3DPacket::__vt;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined1 **)this = &__vt;
  Runtime.PPCEABI.H::__construct_array
            (this + 0x14,dFlower_data_c::dFlower_data_c,dFlower_data_c::_dFlower_data_c,0x44,200);
  Runtime.PPCEABI.H::__construct_array
            (this + 0x3534,dFlower_anm_c::dFlower_anm_c,(undefined *)0x0,0x38,0x48);
  Runtime.PPCEABI.H::__construct_array
            (this + 0x44f4,dFlower_room_c::dFlower_room_c,(undefined *)0x0,4,0x40);
  pdVar1 = this + 0x14;
  iVar3 = 200;
  do {
    *pdVar1 = (dFlower_packet_c)0x0;
    pdVar1 = pdVar1 + 0x44;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pdVar1 = this + 0x3534;
  iVar3 = 0x48;
  do {
    *pdVar1 = (dFlower_packet_c)0x0;
    pdVar1 = pdVar1 + 0x38;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  sVar2 = 0;
  iVar3 = 0;
  do {
    setAnm(this,iVar3,sVar2);
    iVar3 = iVar3 + 1;
    sVar2 = sVar2 + 0x2000;
  } while (iVar3 < 8);
  return;
}


/* __thiscall dFlower_room_c::dFlower_room_c(void) */

void __thiscall dFlower_room_c::dFlower_room_c(dFlower_room_c *this)

{
  *(undefined4 *)this = 0;
  return;
}


/* __thiscall dFlower_anm_c::dFlower_anm_c(void) */

void __thiscall dFlower_anm_c::dFlower_anm_c(dFlower_anm_c *this)

{
  *this = (dFlower_anm_c)0x0;
  return;
}


/* __thiscall dFlower_data_c::dFlower_data_c(void) */

void __thiscall dFlower_data_c::dFlower_data_c(dFlower_data_c *this)

{
  *this = (dFlower_data_c)0x0;
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dFlower_packet_c::draw(void) */

void __thiscall dFlower_packet_c::draw(dFlower_packet_c *this)

{
  int iVar1;
  byte **ppbVar2;
  byte *pbVar3;
  int iVar4;
  _GXColor local_38;
  _GXColor local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  J3DSys::reinitGX(&J3DGraphBase::j3dSys);
  gx::GXSetNumIndStages(0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX8);
  gx::GXSetVtxDesc(GX_VA_CLR0,GX_INDEX8);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_INDEX8);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA8,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,0);
  gx::GXSetArray(GX_VA_POS,&d_flower::l_pos,0xc);
  gx::GXSetArray(GX_VA_CLR0,&d_flower::l_color,4);
  gx::GXSetArray(GX_VA_TEX0,&d_flower::l_texCoord,8);
  gx::GXCallDisplayList(&d_flower::l_matDL,0xa0);
  ppbVar2 = (byte **)(this + 0x44f4);
  iVar1 = 0;
  iVar4 = 0;
  do {
    local_28 = *(undefined4 *)((int)&dStage_roomControl_c::mStatus[0].mTevStr.mColorC0.r + iVar4);
    local_24 = *(undefined4 *)((int)&dStage_roomControl_c::mStatus[0].mTevStr.mColorC0.b + iVar4);
    gx::GXSetTevColorS10(GX_TEVREG0,(_GXColorS10 *)&local_28);
    local_34 = *(_GXColor *)(&dStage_roomControl_c::mStatus[0].mTevStr.mColorK0.r + iVar4);
    gx::GXSetTevColor(GX_TEVREG1,&local_34);
    d_kankyo::dKy_GxFog_tevstr_set
              ((dKy_tevstr_c *)
               ((int)&dStage_roomControl_c::mStatus[0].mTevStr.mLightObj.mPos.x + iVar4));
    pbVar3 = *ppbVar2;
    while( true ) {
      if (pbVar3 == (byte *)0x0) break;
      if (((*pbVar3 & 4) == 0) && ((*pbVar3 & 0x20) == 0)) {
        gx::GXLoadPosMtxImm((MTX34 *)(pbVar3 + 0x10),0);
        if ((*pbVar3 & 8) == 0) {
          gx::GXCallDisplayList(&d_flower::l_OhanaDL,0x100);
        }
        else {
          gx::GXCallDisplayList(&d_flower::l_Ohana_gutDL,0xa0);
        }
      }
      pbVar3 = *(byte **)(pbVar3 + 0x40);
    }
    iVar1 = iVar1 + 1;
    ppbVar2 = ppbVar2 + 1;
    iVar4 = iVar4 + 0x114;
  } while (iVar1 < 0x40);
  gx::GXSetArray(GX_VA_POS,*(undefined4 *)(this + 0x4608),0xc);
  gx::GXSetArray(GX_VA_CLR0,*(undefined4 *)(this + 0x460c),4);
  gx::GXSetArray(GX_VA_TEX0,*(undefined4 *)(this + 0x4610),8);
  gx::GXCallDisplayList(*(undefined4 *)(this + 0x4614),*(undefined4 *)(this + 0x4618));
  ppbVar2 = (byte **)(this + 0x44f4);
  iVar1 = 0;
  iVar4 = 0;
  do {
    local_30 = *(undefined4 *)((int)&dStage_roomControl_c::mStatus[0].mTevStr.mColorC0.r + iVar4);
    local_2c = *(undefined4 *)((int)&dStage_roomControl_c::mStatus[0].mTevStr.mColorC0.b + iVar4);
    gx::GXSetTevColorS10(GX_TEVREG0,(_GXColorS10 *)&local_30);
    local_38 = *(_GXColor *)(&dStage_roomControl_c::mStatus[0].mTevStr.mColorK0.r + iVar4);
    gx::GXSetTevColor(GX_TEVREG1,&local_38);
    pbVar3 = *ppbVar2;
    while( true ) {
      if (pbVar3 == (byte *)0x0) break;
      if (((*pbVar3 & 4) == 0) && ((*pbVar3 & 0x20) != 0)) {
        gx::GXLoadPosMtxImm((MTX34 *)(pbVar3 + 0x10),0);
        if ((*pbVar3 & 8) == 0) {
          gx::GXCallDisplayList(*(undefined4 *)(this + 0x461c),*(undefined4 *)(this + 0x4620));
        }
        else {
          gx::GXCallDisplayList(*(undefined4 *)(this + 0x4624),*(undefined4 *)(this + 0x4628));
        }
      }
      pbVar3 = *(byte **)(pbVar3 + 0x40);
    }
    iVar1 = iVar1 + 1;
    ppbVar2 = ppbVar2 + 1;
    iVar4 = iVar4 + 0x114;
  } while (iVar1 < 0x40);
  _sOldVcdVatCmd = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dFlower_packet_c::calc(void) */

void __thiscall dFlower_packet_c::calc(dFlower_packet_c *this)

{
  uint uVar1;
  int iVar2;
  daPy_lk_c *this_00;
  float fVar3;
  double dVar4;
  dFlower_data_c *this_01;
  int iVar5;
  dFlower_packet_c *pdVar6;
  int iVar7;
  cXyz local_78;
  cXyz local_6c;
  cXyz local_60;
  float local_54;
  float local_50;
  float local_4c;
  cXyz local_48;
  undefined4 local_38;
  int iStack52;
  longlong local_30;
  longlong local_28;
  
  dVar4 = d_flower::_4522;
  fVar3 = d_flower::_4519;
  pdVar6 = this + 0x3534;
  iVar5 = 0;
  iVar7 = 8;
  do {
    iStack52 = g__Timer + iVar5;
    local_38 = 0x43300000;
    uVar1 = (uint)(fVar3 * (float)((double)CONCAT44(0x43300000,iStack52) - dVar4));
    local_30 = (longlong)(int)uVar1;
    iVar2 = (int)(fVar3 + fVar3 * JKernel::JMath::jmaCosTable
                                  [(int)(uVar1 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)]);
    local_28 = (longlong)iVar2;
    *(short *)(pdVar6 + 4) = (short)iVar2;
    this_00 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
    pdVar6 = pdVar6 + 0x38;
    iVar5 = iVar5 + 0xfa;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar5 = (int)(char)dStage_roomControl_c::mStayNo;
  this_01 = *(dFlower_data_c **)(this + iVar5 * 4 + 0x44f4);
  if (this_01 != (dFlower_data_c *)0x0) {
    this[0x45f4] = (dFlower_packet_c)
                   ((byte)(((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).
                           field_0x29c >> 6) & 1);
    ::daPy_py_c::getSwordTopPos(&local_60,&this_00->parent);
    local_48.x = local_60.x;
    local_48.y = local_60.y;
    local_48.z = local_60.z;
    ::cXyz::operator__(&local_6c,&local_48,&(this_00->parent).parent.mCurrent.mPos);
    local_54 = local_6c.x;
    local_50 = local_6c.y;
    local_4c = local_6c.z;
    iVar7 = SComponent::cM_atan2s(local_6c.x,local_6c.z);
    *(short *)(this + 0x45f6) = (short)iVar7;
    ::cXyz::operator__(&local_78,(cXyz *)(this + 0x45fc),&local_48);
    local_54 = local_78.x;
    local_50 = local_78.y;
    local_4c = local_78.z;
    iVar7 = SComponent::cM_atan2s(local_78.x,local_78.z);
    *(short *)(this + 0x45f8) = (short)iVar7;
    *(float *)(this + 0x45fc) = local_48.x;
    *(float *)(this + 0x4600) = local_48.y;
    *(float *)(this + 0x4604) = local_48.z;
    d_flower::l_CutSoundFlag = 0;
    ::cM3dGCyl::SetR(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mCylAttr.mCyl,
                     d_flower::_4102);
    ::cM3dGCyl::SetH(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mCylAttr.mCyl,
                     d_flower::_4520);
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mChkFlag = 0xb;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mResultCamBit = 2;
    do {
      if (((byte)*this_01 & 4) == 0) {
        dFlower_data_c::hitCheck(this_01,(fopAc_ac_c *)this_00,iVar5);
      }
      this_01 = *(dFlower_data_c **)(this_01 + 0x40);
    } while (this_01 != (dFlower_data_c *)0x0);
  }
  return;
}


namespace d_flower {

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x800c0d18) */
/* __stdcall checkGroundY(cXyz &) */

double checkGroundY(float *param_1)

{
  cBgS_PolyPassChk *pcVar1;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  cBgS_GndChk local_88;
  cBgS_PolyPassChk local_48;
  undefined local_3c [16];
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  ::cBgS_GndChk::cBgS_GndChk(&local_88);
  pcVar1 = &local_48;
  local_48.mbObjThrough = 0;
  local_48.mbCamThrough = 0;
  local_48.mbLinkThrough = 0;
  local_48.mbArrowsAndLightThrough = 0;
  local_48.mbBombThrough = 0;
  local_48.mbBoomerangThrough = 0;
  local_48.mbHookshotThrough = 0;
  local_3c._4_4_ = 1;
  local_88.parent.vtbl = &::dBgS_GndChk::__vt;
  local_88.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371f08;
  local_48.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_3c._0_4_ = &PTR_80371f20;
  local_88.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar1;
  if (pcVar1 != (cBgS_PolyPassChk *)0x0) {
    local_88.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_3c;
  }
  param_1[1] = param_1[1] + _4520;
  local_88.mPos.x = *param_1;
  local_88.mPos.y = param_1[1];
  local_88.mPos.z = param_1[2];
  local_88.parent.mpPolyPassChk = pcVar1;
  dVar3 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_88);
  param_1[1] = param_1[1] - _4520;
  if ((double)_4603 < dVar3) {
    local_48.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
    local_3c._0_4_ = &PTR_80371f20;
    if (pcVar1 != (cBgS_PolyPassChk *)0x0) {
      local_48.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      local_3c._0_4_ = &PTR_80371f68;
      if (((undefined *)register0x00000004 != &DAT_0000003c) &&
         (local_3c._0_4_ = &::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != &DAT_0000003c)) {
        local_3c._0_4_ = &::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar1 != (cBgS_PolyPassChk *)0x0) &&
         (local_48.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         pcVar1 != (cBgS_PolyPassChk *)0x0)) {
        local_48.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    local_88.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
    local_88.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk(&local_88.parent);
  }
  else {
    dVar3 = (double)param_1[1];
    local_48.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
    local_3c._0_4_ = &PTR_80371f20;
    if (pcVar1 != (cBgS_PolyPassChk *)0x0) {
      local_48.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      local_3c._0_4_ = &PTR_80371f68;
      if (((undefined *)register0x00000004 != &DAT_0000003c) &&
         (local_3c._0_4_ = &::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != &DAT_0000003c)) {
        local_3c._0_4_ = &::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar1 != (cBgS_PolyPassChk *)0x0) &&
         (local_48.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         pcVar1 != (cBgS_PolyPassChk *)0x0)) {
        local_48.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    local_88.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
    local_88.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk(&local_88.parent);
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return dVar3;
}

}

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dFlower_packet_c::update(void) */

void __thiscall dFlower_packet_c::update(dFlower_packet_c *this)

{
  uint uVar1;
  MTX34 *pMVar2;
  int iVar3;
  int iVar4;
  dFlower_packet_c *pdVar5;
  double dVar6;
  cXyz local_38;
  float local_2c;
  float local_28;
  float local_24;
  
  pdVar5 = this + 0x3534;
  iVar3 = 0;
  do {
    m_Do_mtx::mDoMtx_YrotS(&mDoMtx_stack_c::now,(int)*(short *)(pdVar5 + 2));
    m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,*(short *)(pdVar5 + 4));
    m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,-*(short *)(pdVar5 + 2));
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(pdVar5 + 8));
    iVar3 = iVar3 + 1;
    pdVar5 = pdVar5 + 0x38;
  } while (iVar3 < 0x48);
  pdVar5 = this + 0x14;
  iVar4 = 0;
  iVar3 = 0;
  do {
    if (((byte)*pdVar5 & 2) != 0) {
      m_Do_audio::cLib_calcTimer(pdVar5 + 3);
      if ((((byte)*pdVar5 & 0x10) != 0) && (iVar4 < 8)) {
        dVar6 = (double)d_flower::checkGroundY(pdVar5 + 4);
        *(float *)(pdVar5 + 8) = (float)dVar6;
        *pdVar5 = (dFlower_packet_c)((byte)*pdVar5 & 0xef);
        iVar4 = iVar4 + 1;
      }
      local_38.z = *(float *)(pdVar5 + 0xc);
      local_38.y = d_flower::_4708 + *(float *)(pdVar5 + 8);
      local_38.x = *(float *)(pdVar5 + 4);
      local_2c = local_38.x;
      local_28 = local_38.y;
      local_24 = local_38.z;
      uVar1 = J3DUClipper::clip(&mDoLib_clipper::mClipper,&J3DGraphBase::j3dSys.mCurViewMtx,
                                &local_38,d_flower::_4708);
      if (uVar1 == 0) {
        *pdVar5 = (dFlower_packet_c)((byte)*pdVar5 & 0xfb);
        pMVar2 = (MTX34 *)(this + (char)pdVar5[1] * 0x38 + 0x353c);
        pMVar2->m[3] = *(float *)(pdVar5 + 4);
        pMVar2->m[1][3] = *(float *)(pdVar5 + 8);
        pMVar2->m[2][3] = *(float *)(pdVar5 + 0xc);
        mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,pMVar2,(MTX34 *)(pdVar5 + 0x10));
      }
      else {
        *pdVar5 = (dFlower_packet_c)((byte)*pdVar5 | 4);
      }
    }
    iVar3 = iVar3 + 1;
    pdVar5 = pdVar5 + 0x44;
  } while (iVar3 < 200);
  J3DDrawBuffer::entryImm(J3DGraphBase::j3dSys.mpCurDrawBuffers[0],(J3DPacket *)this,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x800c10b4) */
/* __thiscall dFlower_packet_c::setData(dFlower_data_c *,
                                        int,
                                        signed char,
                                        cXyz &,
                                        int,
                                        signed char) */

void __thiscall
dFlower_packet_c::setData
          (dFlower_packet_c *this,dFlower_data_c *param_1,int param_2,char param_3,cXyz *param_4,
          int param_5,char param_6)

{
  int iVar1;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  float fVar4;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar1 = f_op_overlap_mng::fopOvlpM_IsPeek();
  if (iVar1 == 0) {
    dVar3 = (double)param_4->y;
    *param_1 = (dFlower_data_c)0x16;
  }
  else {
    dVar3 = (double)d_flower::checkGroundY(param_4);
    *param_1 = (dFlower_data_c)0x6;
  }
  if (param_3 == '\x02') {
    *param_1 = (dFlower_data_c)((byte)*param_1 | 0x20);
  }
  fVar4 = SComponent::cM_rndF(d_flower::_4736);
  param_1[1] = SUB41((int)fVar4,0);
  fVar4 = param_4->z;
  *(float *)(param_1 + 4) = param_4->x;
  *(float *)(param_1 + 8) = (float)dVar3;
  *(float *)(param_1 + 0xc) = fVar4;
  param_1[2] = (dFlower_data_c)param_6;
  param_1[3] = (dFlower_data_c)0x0;
  if (*(int *)(this + param_5 * 4 + 0x44f4) == 0) {
    iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"sea");
    if ((iVar1 == 0) && (param_5 == 0x21)) {
      *(undefined **)(this + 0x4608) = &d_flower::l_pos3;
      *(undefined **)(this + 0x460c) = &d_flower::l_color3;
      *(undefined **)(this + 0x4610) = &d_flower::l_texCoord3;
      *(undefined **)(this + 0x4614) = &d_flower::l_matDL3;
      *(undefined4 *)(this + 0x4618) = 0xa0;
      *(undefined **)(this + 0x461c) = &d_flower::l_QbsfwDL;
      *(undefined4 *)(this + 0x4620) = 0x660;
      *(undefined **)(this + 0x4624) = &d_flower::l_QbsafDL;
      *(undefined4 *)(this + 0x4628) = 0x80;
    }
    else {
      *(undefined **)(this + 0x4608) = &d_flower::l_pos2;
      *(undefined **)(this + 0x460c) = &d_flower::l_color2;
      *(undefined **)(this + 0x4610) = &d_flower::l_texCoord2;
      *(undefined **)(this + 0x4614) = &d_flower::l_matDL2;
      *(undefined4 *)(this + 0x4618) = 0xa0;
      *(undefined **)(this + 0x461c) = &d_flower::l_Ohana_highDL;
      *(undefined4 *)(this + 0x4620) = 0x120;
      *(undefined **)(this + 0x4624) = &d_flower::l_Ohana_high_gutDL;
      *(undefined4 *)(this + 0x4628) = 0x80;
    }
  }
  if (*(undefined **)(this + 0x461c) == &d_flower::l_QbsfwDL) {
    *param_1 = (dFlower_data_c)((byte)*param_1 | 0x40);
  }
  dFlower_room_c::newData((dFlower_room_c *)(this + param_5 * 4 + 0x44f4),param_1);
  *(short *)(this + 0x10) = (short)param_2;
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dFlower_packet_c::newData(signed char,
                                        cXyz &,
                                        int,
                                        signed char) */

dFlower_data_c * __thiscall
dFlower_packet_c::newData
          (dFlower_packet_c *this,char param_1,cXyz *param_2,int param_3,char param_4)

{
  bool bVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  dFlower_data_c *pdVar6;
  
  bVar1 = false;
  if ((-1 < param_3) && (param_3 < 0x40)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_flower.cpp",0xb76,"0 <= i_roomNo && i_roomNo < 64");
    m_Do_printf::OSPanic("d_flower.cpp",0xb76,&DAT_8035a0a0);
  }
  uVar4 = (uint)*(ushort *)(this + 0x10);
  pdVar6 = (dFlower_data_c *)(this + uVar4 * 0x44 + 0x14);
  iVar2 = 200 - uVar4;
  uVar5 = uVar4;
  if (uVar4 < 200) {
    do {
      if (((byte)*pdVar6 & 2) == 0) {
        setData(this,pdVar6,uVar5,param_1,param_2,param_3,param_4);
        return pdVar6;
      }
      pdVar6 = pdVar6 + 0x44;
      uVar5 = uVar5 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  pdVar6 = (dFlower_data_c *)(this + 0x14);
  iVar2 = 0;
  while( true ) {
    if (uVar4 == 0) {
      return (dFlower_data_c *)0x0;
    }
    if (((byte)*pdVar6 & 2) == 0) break;
    pdVar6 = pdVar6 + 0x44;
    iVar2 = iVar2 + 1;
    uVar4 = uVar4 - 1;
  }
  setData(this,pdVar6,iVar2,param_1,param_2,param_3,param_4);
  return pdVar6;
}


/* __thiscall dFlower_packet_c::newAnm(void) */

int __thiscall dFlower_packet_c::newAnm(dFlower_packet_c *this)

{
  int iVar1;
  dFlower_packet_c *pdVar2;
  int iVar3;
  
  pdVar2 = this + 0x36f4;
  iVar1 = 8;
  iVar3 = 0x40;
  do {
    if (*pdVar2 == (dFlower_packet_c)0x0) {
      *pdVar2 = (dFlower_packet_c)0x1;
      *(undefined2 *)(pdVar2 + 2) = 0;
      *(undefined2 *)(pdVar2 + 4) = 0;
      return iVar1;
    }
    pdVar2 = pdVar2 + 0x38;
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return -1;
}


/* __thiscall dFlower_packet_c::setAnm(int,
                                       short) */

void __thiscall dFlower_packet_c::setAnm(dFlower_packet_c *this,int param_1,short param_2)

{
  dFlower_packet_c *pdVar1;
  
  pdVar1 = this + param_1 * 0x38 + 0x3534;
  *pdVar1 = (dFlower_packet_c)0x1;
  *(short *)(pdVar1 + 2) = param_2;
  *(undefined2 *)(pdVar1 + 4) = 0;
  return;
}


namespace d_flower {

void __sinit_d_flower_cpp(void)

{
  DAT_80383c31 = 1;
  DAT_80383c32 = 0xbf;
  DAT_80383c33 = 0xf5;
  DAT_80383cf1 = 1;
  DAT_80383cf2 = 0xc1;
  DAT_80383cf3 = 0x15;
  DAT_80383db1 = 1;
  DAT_80383db2 = 0xc1;
  DAT_80383db3 = 0x7d;
  return;
}

