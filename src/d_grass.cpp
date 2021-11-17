#include <d_grass.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_kankyo.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <SComponent/c_math.h>
#include <d_particle.h>
#include <mtx/vec.h>
#include <d_grass.h>
#include <d_cc_d.h>
#include <SComponent/c_sxyz.h>
#include <c_damagereaction.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <f_op_actor_mng.h>
#include <d_com_inf_game.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_cc_mass_s.h>
#include <SComponent/c_lib.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <J3DGraphBase/J3DSys.h>
#include <gx/GXBump.h>
#include <gf/GFGeometry.h>
#include <gx/GXDisplayList.h>
#include <gf/GFTev.h>
#include <gx/GXTransform.h>
#include <d_kankyo_wether.h>
#include <SComponent/c_m3d_g_cyl.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <SComponent/c_bg_s.h>
#include <SComponent/c_bg_s_chk.h>
#include <m_Do_mtx.h>
#include <mtx/mtx.h>
#include <J3DU/J3DUClipper.h>
#include <J3DGraphBase/J3DDrawBuffer.h>
#include <f_op_overlap_mng.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <Demangler/dCcMassS_HitInf.h>
#include <dGrass_packet_c.h>
#include <dGrass_data_c.h>
#include <dGrass_room_c.h>
#include <dGrass_anm_c.h>
#include <Demangler/cCcD_Obj.h>


namespace d_grass {
undefined1 l_CutSoundFlag;
undefined1 init$4375;
undefined ang$4373;

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall setBatta(cXyz *,
                      _GXColor *) */

void setBatta(cXyz *param_1,_GXColor *param_2)

{
  int iVar1;
  double extraout_f1;
  double dVar2;
  float fVar3;
  
  iVar1 = d_kankyo::dKy_rain_check();
  if ((((iVar1 == 0) && (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0)) &&
      (dVar2 = extraout_f1,
      iVar1 = MSL_C.PPCEABI.bare.H::strncmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"kin",3),
      iVar1 != 0)) &&
     ((iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                         (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss1"),
      iVar1 != 0 && (fVar3 = SComponent::cM_rnd((float)dVar2), 0_99 < fVar3)))) {
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x453,param_1,
                       (csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1,param_2,param_2,
                       (cXyz *)0x0);
  }
  return;
}

}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8007732c) */
/* __thiscall dGrass_data_c::WorkCo(fopAc_ac_c *,
                                    unsigned long,
                                    int) */

void __thiscall
dGrass_data_c::WorkCo(dGrass_data_c *this,fopAc_ac_c *param_1,ulong roomNo,int param_3)

{
  int iVar1;
  int iVar2;
  _GXColor *p_Var3;
  dGrass_anm_c *pdVar4;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  float fVar8;
  cXyz local_44;
  cXyz local_38;
  float local_2c;
  float local_28;
  float local_24;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  local_44.x = (this->mPos).x - (param_1->mCurrent).mPos.x;
  local_44.z = (this->mPos).z - (param_1->mCurrent).mPos.z;
  local_44.y = d_grass::0_0;
  local_2c = local_44.x;
  local_24 = local_44.z;
  fVar8 = mtx::PSVECSquareMag(&local_44);
  dVar7 = (double)fVar8;
  if (dVar7 <= (double)d_grass::1600_0) {
    local_28 = (this->mPos).y - (param_1->mCurrent).mPos.y;
    iVar1 = SComponent::cM_atan2s(local_2c,local_24);
    if ((double)d_grass::0_0 < dVar7) {
      dVar6 = 1.0 / SQRT(dVar7);
      dVar6 = d_grass::_4269 * dVar6 * (d_grass::_4270 - dVar7 * dVar6 * dVar6);
      dVar6 = d_grass::_4269 * dVar6 * (d_grass::_4270 - dVar7 * dVar6 * dVar6);
      dVar7 = (double)(float)(dVar7 * d_grass::_4269 * dVar6 *
                                      (d_grass::_4270 - dVar7 * dVar6 * dVar6));
    }
    if ((char)this->mAnimIdx < 8) {
      if (d_grass::16_0 < param_1->mVelocityFwd) {
        local_38.z = (this->mPos).z;
        local_38.y = d_grass::20_0 + (this->mPos).y;
        local_38.x = (this->mPos).x;
        p_Var3 = &dStage_roomControl_c::mStatus[param_3].mTevStr.mColorK0;
        dPa_control_c::setSimple
                  (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,
                   (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpGrassPacket)->mCoParticle,&local_38,
                   0xff,p_Var3,p_Var3,1);
        d_grass::setBatta(&this->mPos,param_3 * 0x114 + -0x7fc4229c);
      }
      iVar2 = dGrass_packet_c::newAnm(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpGrassPacket);
      if (iVar2 < 0) goto LAB_8007732c;
      this->mAnimIdx = (byte)iVar2;
      pdVar4 = (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpGrassPacket)->mGrassAnm +
               (char)this->mAnimIdx;
    }
    else {
      pdVar4 = (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpGrassPacket)->mGrassAnm +
               (char)this->mAnimIdx;
    }
    pdVar4->mRotY = (short)iVar1;
    iVar1 = SComponent::cM_atan2s((float)((double)d_grass::40_0 - dVar7),d_grass::40_0);
    pdVar4->mRotX = (short)iVar1;
    pdVar4->mState = 2;
  }
LAB_8007732c:
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x800775bc) */
/* WARNING: Removing unreachable block (ram,0x800775c4) */
/* __thiscall dGrass_data_c::WorkAt_NoCutAnim(fopAc_ac_c *,
                                              unsigned long,
                                              int,
                                              dCcMassS_HitInf *,
                                              cCcD_Obj *) */

void __thiscall
dGrass_data_c::WorkAt_NoCutAnim
          (dGrass_data_c *this,fopAc_ac_c *param_1,ulong param_2,int param_3,
          dCcMassS_HitInf *param_4,cCcD_Obj *param_5)

{
  dCcD_GObjInf *pdVar1;
  int iVar2;
  char cVar4;
  int iVar3;
  dGrass_anm_c *pdVar5;
  undefined4 uVar6;
  double dVar7;
  double extraout_f1;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  float fVar9;
  cXyz local_88;
  cXyz local_7c;
  cXyz local_70;
  cXyz local_64;
  undefined4 local_58;
  uint uStack84;
  longlong local_50;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  pdVar1 = d_cc_d::dCcD_GetGObjInf(param_5);
  local_70.x = (pdVar1->mObjAt).mVel.x;
  local_64.y = (pdVar1->mObjAt).mVel.y;
  local_70.z = (pdVar1->mObjAt).mVel.z;
  local_70.y = d_grass::0_0;
  local_64.x = local_70.x;
  local_64.z = local_70.z;
  fVar9 = mtx::PSVECSquareMag(&local_70);
  dVar7 = (double)fVar9;
  if ((float)ABS(dVar7) < SComponent::G_CM3D_F_ABS_MIN) {
    iVar2 = (*(code *)((param_5->parent).vtbl)->GetShapeAttr_1)(param_5);
    cVar4 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x50))(iVar2,&this->mPos,&local_64);
    if (cVar4 == '\0') {
      local_88.x = (this->mPos).x - (param_1->mCurrent).mPos.x;
      local_64.y = (this->mPos).y - (param_1->mCurrent).mPos.y;
      local_88.z = (this->mPos).z - (param_1->mCurrent).mPos.z;
      local_88.y = d_grass::0_0;
      local_64.x = local_88.x;
      local_64.z = local_88.z;
      fVar9 = mtx::PSVECSquareMag(&local_88);
      dVar7 = (double)fVar9;
    }
    else {
      mtx::PSVECScale(&local_64,&local_64,d_grass::_4350);
      local_7c.x = local_64.x;
      local_7c.y = d_grass::0_0;
      local_7c.z = local_64.z;
      fVar9 = mtx::PSVECSquareMag(&local_7c);
      dVar7 = (double)fVar9;
    }
  }
  if (SComponent::G_CM3D_F_ABS_MIN <= (float)ABS(dVar7)) {
    dVar8 = (double)local_64.x;
    iVar2 = SComponent::cM_atan2s(local_64.x,local_64.z);
    if ((char)this->mAnimIdx < 8) {
      iVar3 = dGrass_packet_c::newAnm(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpGrassPacket);
      if (iVar3 < 0) goto LAB_800775bc;
      this->mAnimIdx = (byte)iVar3;
      pdVar5 = (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpGrassPacket)->mGrassAnm +
               (char)this->mAnimIdx;
      dVar8 = extraout_f1;
    }
    else {
      pdVar5 = (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpGrassPacket)->mGrassAnm +
               (char)this->mAnimIdx;
    }
    fVar9 = SComponent::cM_rnd((float)dVar8);
    dVar8 = d_grass::_4354;
    uStack84 = (int)(short)iVar2 ^ 0x80000000;
    local_58 = 0x43300000;
    iVar2 = (int)((float)((double)CONCAT44(0x43300000,uStack84) - d_grass::_4354) *
                 (d_grass::0_9 + d_grass::0_2 * fVar9));
    local_50 = (longlong)iVar2;
    pdVar5->mRotY = (short)iVar2;
    fVar9 = SComponent::cM_rnd((float)dVar8);
    dVar8 = (double)(d_grass::0_9 + d_grass::0_2 * fVar9);
    iVar2 = SComponent::cM_atan2s((float)dVar7,d_grass::40_0);
    pdVar5->mRotX =
         (short)(int)((double)(float)((double)CONCAT44(0x43300000,(int)(short)iVar2 ^ 0x80000000) -
                                     d_grass::_4354) * dVar8);
    pdVar5->mState = 2;
  }
LAB_800775bc:
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  return;
}


/* __thiscall cCcD_Obj::GetShapeAttr(void) */

undefined4 __thiscall cCcD_Obj::GetShapeAttr(cCcD_Obj *this)

{
  return 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dGrass_data_c::WorkAt(fopAc_ac_c *,
                                    unsigned long,
                                    int,
                                    dCcMassS_HitInf *) */

void __thiscall
dGrass_data_c::WorkAt
          (dGrass_data_c *this,fopAc_ac_c *param_1,ulong param_2,int param_3,
          dCcMassS_HitInf *param_4)

{
  cCcD_Obj__DamageTypes cVar1;
  sbyte sVar2;
  _GXColor *p_Var3;
  cCcD_Obj *pcVar4;
  cXyz local_28 [2];
  
  pcVar4 = param_4->mpAtObj;
  if (pcVar4 == (cCcD_Obj *)0x0) {
LAB_80077658:
    if (7 < (char)this->mAnimIdx) {
      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpGrassPacket)->mGrassAnm[(char)this->mAnimIdx].
      mState = 0;
    }
    this->mAnimIdx = 0xff;
    if (d_grass::init_4375 == '\0') {
      ::csXyz::csXyz((csXyz *)&d_grass::ang_4373,0,0,0);
      Runtime.PPCEABI.H::__register_global_object();
      d_grass::init_4375 = '\x01';
    }
    local_28[0].z = (this->mPos).z;
    local_28[0].y = d_grass::_4407 + (this->mPos).y;
    local_28[0].x = (this->mPos).x;
    p_Var3 = &dStage_roomControl_c::mStatus[param_3].mTevStr.mColorK0;
    dPa_control_c::setSimple
              (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,
               (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpGrassPacket)->field_0x1a66a,local_28,0xff
               ,p_Var3,p_Var3,1);
    d_grass::setBatta(&this->mPos,param_3 * 0x114 + -0x7fc4229c);
    if (-1 < (char)this->mItemIdx) {
      f_op_actor_mng::fopAcM_createItemFromTable
                (&this->mPos,(int)(char)this->mItemIdx,0xffffffff,param_3,0,0,1,0);
    }
    if (d_grass::l_CutSoundFlag == '\0') {
      d_grass::l_CutSoundFlag = '\x01';
      sVar2 = d_com_inf_game::dComIfGp_getReverb(param_3);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x282c,&this->mPos,0,sVar2,d_grass::1_0,d_grass::1_0,
                 d_grass::_1_0,d_grass::_1_0,0);
    }
  }
  else {
    cVar1 = (pcVar4->parent).mObjAt.mDamageTypes;
    if ((cVar1 & DekuLeafWind) == 0) {
      if ((cVar1 & NormalArrow) == 0) {
        if ((cVar1 & FireArrows) == 0) {
          if ((cVar1 & IceArrows) == 0) {
            if (((cVar1 & LightArrow) == 0) && ((cVar1 & 0x8000) == 0)) goto LAB_80077658;
          }
        }
      }
    }
    WorkAt_NoCutAnim(this,param_1,param_2,param_3,param_4,pcVar4);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dGrass_data_c::hitCheck(int) */

void __thiscall dGrass_data_c::hitCheck(dGrass_data_c *this,int roomNo)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  dGrass_packet_c *pdVar5;
  uint roomNo_00;
  sbyte sVar8;
  short sVar7;
  int iVar6;
  dGrass_anm_c *pdVar9;
  fopAc_ac_c *pAct;
  dCcMassS_HitInf dStack52;
  
  dStack52.vtbl = (undefined *)&dCcMassS_HitInf::__vt;
  roomNo_00 = dCcMassS_Mng::Chk(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng,&this->mPos,
                                &pAct,&dStack52);
  pdVar5 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpGrassPacket;
  bVar4 = false;
  if ((roomNo_00 & 1) != 0) {
    bVar3 = false;
    bVar2 = false;
    if (pAct != (fopAc_ac_c *)0x0) {
      if ((pAct->parent).parent.mProcName != 0x1cb) {
        bVar2 = true;
      }
    }
    if (bVar2) {
      if ((pAct->parent).parent.mProcName != 0x1cc) {
        bVar3 = true;
      }
    }
    if (bVar3) {
      bVar4 = true;
    }
  }
  if (((roomNo_00 & 2) != 0) || (bVar4)) {
    if ((roomNo_00 & 2) != 0) {
      WorkCo(this,pAct,roomNo_00,roomNo);
    }
    if (bVar4) {
      WorkAt(this,pAct,roomNo_00,roomNo,&dStack52);
    }
  }
  else {
    if (7 < (char)this->mAnimIdx) {
      pdVar9 = (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpGrassPacket)->mGrassAnm +
               (char)this->mAnimIdx;
      uVar1 = pdVar9->mRotY;
      if (pdVar9->mState == 2) {
        sVar8 = d_com_inf_game::dComIfGp_getReverb(roomNo);
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x3814,&this->mPos,0,sVar8,d_grass::1_0,d_grass::1_0,
                   d_grass::_1_0,d_grass::_1_0,0);
        pdVar9->mState = 1;
      }
      sVar7 = SComponent::cLib_addCalcAngleS
                        (&pdVar9->mRotX,pdVar5->mGrassAnm[(uint)(int)(short)uVar1 >> 0xd & 7].mRotX,
                         0x10,4000,100);
      if ((sVar7 == 0) &&
         (iVar6 = SComponent::cLib_chaseAngleS(&pdVar9->mRotY,(int)(short)(uVar1 & 0xe000),800),
         iVar6 != 0)) {
        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpGrassPacket)->mGrassAnm[(char)this->mAnimIdx].
        mState = 0;
        this->mAnimIdx = (byte)((uint)(int)pdVar9->mRotY >> 0xd) & 7;
      }
    }
  }
  return;
}


/* __thiscall dCcMassS_HitInf::~dCcMassS_HitInf(void) */

void __thiscall dCcMassS_HitInf::_dCcMassS_HitInf(dCcMassS_HitInf *this)

{
  short in_r4;
  
  if ((this != (dCcMassS_HitInf *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dGrass_room_c::newData(dGrass_data_c *) */

void __thiscall dGrass_room_c::newData(dGrass_room_c *this,dGrass_data_c *param_1)

{
  param_1->mpNextData = this->mpData;
  this->mpData = param_1;
  return;
}


/* __thiscall dGrass_room_c::deleteData(void) */

void __thiscall dGrass_room_c::deleteData(dGrass_room_c *this)

{
  while (this->mpData != (dGrass_data_c *)0x0) {
    this->mpData->mState = 0;
    JAIZelBasic::seDeleteObject(JAIZelBasic::zel_basic,(Vec *)&this->mpData->mPos);
    this->mpData = this->mpData->mpNextData;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dGrass_packet_c::dGrass_packet_c(void) */

void __thiscall dGrass_packet_c::dGrass_packet_c(dGrass_packet_c *this)

{
  dGrass_data_c *pdVar1;
  dGrass_anm_c *pdVar2;
  short sVar3;
  int iVar4;
  
  (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
  (this->parent).mpNextSibling = (J3DPacket *)0x0;
  (this->parent).mpFirstChild = (J3DPacket *)0x0;
  (this->parent).field_0xc = (undefined *)0x0;
  (this->parent).vtbl = &__vt;
  Runtime.PPCEABI.H::__construct_array
            (this->mGrassData,dGrass_data_c::dGrass_data_c,dGrass_data_c::_dGrass_data_c,0x44,0x5dc)
  ;
  Runtime.PPCEABI.H::__construct_array
            (this->mGrassAnm,dGrass_anm_c::dGrass_anm_c,(undefined *)0x0,0x38,0x68);
  Runtime.PPCEABI.H::__construct_array
            (this->mGrassRoom,dGrass_room_c::dGrass_room_c,(undefined *)0x0,4,0x40);
  pdVar1 = this->mGrassData;
  iVar4 = 0x5dc;
  do {
    pdVar1->mState = 0;
    pdVar1 = pdVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  this->mRndm = 0;
  iVar4 = 0x68;
  pdVar2 = this->mGrassAnm;
  do {
    pdVar2->mState = 0;
    pdVar2 = pdVar2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  sVar3 = 0;
  iVar4 = 0;
  do {
    setAnm(this,iVar4,sVar3);
    iVar4 = iVar4 + 1;
    sVar3 = sVar3 + 0x2000;
  } while (iVar4 < 8);
  iVar4 = MSL_C.PPCEABI.bare.H::strncmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"kin",3);
  if ((iVar4 == 0) ||
     (iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss1"),
     iVar4 == 0)) {
    this->mpPosArr = d_grass::l_Vmori_pos;
    this->mpColorArr = d_grass::l_Vmori_color;
    this->mpTexCoordArr = d_grass::l_Vmori_texCoord;
    this->mpMatDL = &d_grass::l_Vmori_matDL;
    this->mMatDLSize = 0xa0;
    this->mpDL = &d_grass::l_Vmori_00DL;
    this->mDLSize = 0xa0;
    this->mpDLCut = &d_grass::l_Vmori_01DL;
    this->mDLCutSize = 0x80;
    this->mCoParticle = 0x8222;
    this->field_0x1a66a = 0x8221;
  }
  else {
    this->mpPosArr = d_grass::l_pos;
    this->mpColorArr = d_grass::l_color;
    this->mpTexCoordArr = d_grass::l_texCoord;
    this->mpMatDL = &d_grass::l_matDL;
    this->mMatDLSize = 0xa0;
    this->mpDL = &d_grass::l_Oba_kusa_aDL;
    this->mDLSize = 0xa0;
    this->mpDLCut = &d_grass::l_Oba_kusa_a_cutDL;
    this->mDLCutSize = 0x80;
    this->mCoParticle = 0x3db;
    this->field_0x1a66a = 0x3da;
  }
  return;
}


/* __thiscall dGrass_room_c::dGrass_room_c(void) */

void __thiscall dGrass_room_c::dGrass_room_c(dGrass_room_c *this)

{
  this->mpData = (dGrass_data_c *)0x0;
  return;
}


/* __thiscall dGrass_anm_c::dGrass_anm_c(void) */

void __thiscall dGrass_anm_c::dGrass_anm_c(dGrass_anm_c *this)

{
  this->mState = 0;
  return;
}


/* __thiscall dGrass_data_c::dGrass_data_c(void) */

void __thiscall dGrass_data_c::dGrass_data_c(dGrass_data_c *this)

{
  this->mState = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dGrass_packet_c::draw(void) */

void __thiscall dGrass_packet_c::draw(dGrass_packet_c *this)

{
  int iVar1;
  dGrass_room_c *pdVar2;
  dGrass_data_c *pdVar3;
  int iVar4;
  _GXColor local_38;
  _GXColorS10 local_34;
  
  J3DSys::reinitGX(&J3DGraphBase::j3dSys);
  gx::GXSetNumIndStages(0);
  gf::GFSetVtxDescv(&d_grass::l_vtxDescList_4528);
  gf::GFSetVtxAttrFmtv(0,&d_grass::l_vtxAttrFmtList_4529);
  gf::GFSetArray(GX_VA_POS,(int)this->mpPosArr,0xc);
  gf::GFSetArray(GX_VA_CLR0,(int)this->mpColorArr,4);
  gf::GFSetArray(GX_VA_TEX0,(int)this->mpTexCoordArr,8);
  gx::GXCallDisplayList(this->mpMatDL,this->mMatDLSize);
  iVar1 = 0;
  iVar4 = 0;
  pdVar2 = this->mGrassRoom;
  do {
    local_34._0_4_ =
         *(undefined4 *)((int)&dStage_roomControl_c::mStatus[0].mTevStr.mColorC0.r + iVar4);
    local_34._4_4_ =
         *(undefined4 *)((int)&dStage_roomControl_c::mStatus[0].mTevStr.mColorC0.b + iVar4);
    gf::GFSetTevColorS10(GX_TEVREG0,&local_34);
    local_38 = *(_GXColor *)(&dStage_roomControl_c::mStatus[0].mTevStr.mColorK0.r + iVar4);
    gf::GFSetTevColor(GX_TEVREG1,&local_38);
    d_kankyo::dKy_GfFog_tevstr_set
              ((dKy_tevstr_c *)
               ((int)&dStage_roomControl_c::mStatus[0].mTevStr.mLightObj.mPos.x + iVar4));
    pdVar3 = pdVar2->mpData;
    while( true ) {
      if (pdVar3 == (dGrass_data_c *)0x0) break;
      if ((pdVar3->mInitFlags & 2) == 0) {
        gx::GXLoadPosMtxImm(&pdVar3->mModelMtx,0);
        if ((char)pdVar3->mAnimIdx < '\0') {
          gx::GXCallDisplayList(this->mpDLCut,this->mDLCutSize);
        }
        else {
          gx::GXCallDisplayList(this->mpDL,this->mDLSize);
        }
      }
      pdVar3 = pdVar3->mpNextData;
    }
    iVar1 = iVar1 + 1;
    pdVar2 = pdVar2 + 1;
    iVar4 = iVar4 + 0x114;
  } while (iVar1 < 0x40);
  _sOldVcdVatCmd = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x80077fe8) */
/* __thiscall dGrass_packet_c::calc(void) */

void __thiscall dGrass_packet_c::calc(dGrass_packet_c *this)

{
  double dVar1;
  dGrass_data_c *this_00;
  int iVar2;
  dGrass_anm_c *pdVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar6 = (double)d_grass::0_0;
  pdVar3 = this->mGrassAnm;
  if ((mDoGph_gInf_c::mMonotone == 0) ||
     (iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Hyrule"),
     iVar2 != 0)) {
    dVar6 = d_kankyo_wether::dKyw_get_wind_pow();
    dVar6 = (double)(float)((double)d_grass::1000_0 +
                           (double)(float)((double)d_grass::1000_0 * dVar6));
    if ((double)d_grass::2000_0 < dVar6) {
      dVar6 = (double)d_grass::2000_0;
    }
  }
  dVar1 = d_grass::_4620;
  iVar2 = 0;
  iVar4 = 8;
  do {
    pdVar3->mRotX =
         (short)(int)(dVar6 + (double)(float)(dVar6 * (double)JKernel::JMath::jmaCosTable
                                                              [(int)((int)(dVar6 * (double)(float)((
                                                  double)CONCAT44(0x43300000,g__Timer + iVar2) -
                                                  dVar1)) & 0xffffU) >>
                                                  (JKernel::JMath::jmaSinShift & 0x3f)]));
    pdVar3 = pdVar3 + 1;
    iVar2 = iVar2 + 0xfa;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar2 = (int)(char)dStage_roomControl_c::mStayNo;
  this_00 = this->mGrassRoom[iVar2].mpData;
  if (this_00 != (dGrass_data_c *)0x0) {
    d_grass::l_CutSoundFlag = 0;
    ::cM3dGCyl::SetR(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mCylAttr.mCyl,
                     d_grass::40_0);
    ::cM3dGCyl::SetH(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mCylAttr.mCyl,
                     d_grass::80_0);
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mChkFlag = 0xb;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mResultCamBit = 0;
    do {
      if (((this_00->mInitFlags & 2) == 0) && (-1 < (char)this_00->mAnimIdx)) {
        dGrass_data_c::hitCheck(this_00,iVar2);
      }
      this_00 = this_00->mpNextData;
    } while (this_00 != (dGrass_data_c *)0x0);
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


namespace d_grass {

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x80078298) */
/* __stdcall checkGroundY(cXyz &) */

double checkGroundY(cXyz *pPos)

{
  cBgS_PolyPassChk *pcVar1;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  cBgS_GndChk gndChk;
  cBgS_PolyPassChk polyPassChk;
  undefined **local_3c;
  undefined4 local_38;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  ::cBgS_GndChk::cBgS_GndChk(&gndChk);
  pcVar1 = &polyPassChk;
  polyPassChk.mbObjThrough = 0;
  polyPassChk.mbCamThrough = 0;
  polyPassChk.mbLinkThrough = 0;
  polyPassChk.mbArrowsAndLightThrough = 0;
  polyPassChk.mbBombThrough = 0;
  polyPassChk.mbBoomerangThrough = 0;
  polyPassChk.mbHookshotThrough = 0;
  local_38 = 1;
  gndChk.parent.vtbl = &::dBgS_GndChk::__vt;
  gndChk.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371f08;
  polyPassChk.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_3c = &PTR_80371f20;
  gndChk.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar1;
  if (pcVar1 != (cBgS_PolyPassChk *)0x0) {
    gndChk.parent.mpGrpPassChk = (cBgS_GrpPassChk *)&local_3c;
  }
  pPos->y = pPos->y + 50_0;
  gndChk.mPos.x = pPos->x;
  gndChk.mPos.y = pPos->y;
  gndChk.mPos.z = pPos->z;
  gndChk.parent.mpPolyPassChk = pcVar1;
  dVar3 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&gndChk);
  pPos->y = pPos->y - 50_0;
  if ((double)_1_0E9 < dVar3) {
    polyPassChk.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
    local_3c = &PTR_80371f20;
    if (pcVar1 != (cBgS_PolyPassChk *)0x0) {
      polyPassChk.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      local_3c = &PTR_80371f68;
      if (((undefined *)register0x00000004 != &DAT_0000003c) &&
         (local_3c = &::dBgS_GrpPassChk::__vt, (undefined *)register0x00000004 != &DAT_0000003c)) {
        local_3c = &::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar1 != (cBgS_PolyPassChk *)0x0) &&
         (polyPassChk.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         pcVar1 != (cBgS_PolyPassChk *)0x0)) {
        polyPassChk.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    gndChk.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
    gndChk.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk(&gndChk.parent);
  }
  else {
    dVar3 = (double)pPos->y;
    polyPassChk.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
    local_3c = &PTR_80371f20;
    if (pcVar1 != (cBgS_PolyPassChk *)0x0) {
      polyPassChk.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      local_3c = &PTR_80371f68;
      if (((undefined *)register0x00000004 != &DAT_0000003c) &&
         (local_3c = &::dBgS_GrpPassChk::__vt, (undefined *)register0x00000004 != &DAT_0000003c)) {
        local_3c = &::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar1 != (cBgS_PolyPassChk *)0x0) &&
         (polyPassChk.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         pcVar1 != (cBgS_PolyPassChk *)0x0)) {
        polyPassChk.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    gndChk.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
    gndChk.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk(&gndChk.parent);
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return dVar3;
}

}

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dGrass_packet_c::update(void) */

void __thiscall dGrass_packet_c::update(dGrass_packet_c *this)

{
  uint uVar1;
  MTX34 *pAnimMtx;
  short sVar2;
  int iVar3;
  dGrass_anm_c *pdVar4;
  dGrass_data_c *pData;
  int iVar5;
  double dVar6;
  cXyz local_38;
  float local_2c;
  float local_28;
  float local_24;
  
  iVar5 = 0;
  pdVar4 = this->mGrassAnm;
  do {
    m_Do_mtx::mDoMtx_YrotS(&mDoMtx_stack_c::now,(int)pdVar4->mRotY);
    m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,pdVar4->mRotX);
    m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,-pdVar4->mRotY);
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,&pdVar4->mAnimMtx);
    iVar5 = iVar5 + 1;
    pdVar4 = pdVar4 + 1;
  } while (iVar5 < 0x68);
  pData = this->mGrassData;
  iVar3 = 0;
  mDoLib_clipper::mClipper.mFar = d_grass::_4822 * mDoLib_clipper::mSystemFar;
  J3DUClipper::calcViewFrustum(&mDoLib_clipper::mClipper);
  iVar5 = 0;
  sVar2 = 0;
  do {
    if (pData->mState != 0) {
      if ((pData->mState == 1) && (iVar3 < 0x1e)) {
        dVar6 = (double)d_grass::checkGroundY(&pData->mPos);
        (pData->mPos).y = (float)dVar6;
        pData->mState = 2;
        iVar3 = iVar3 + 1;
      }
      local_38.z = (pData->mPos).z;
      local_38.y = d_grass::260_0 + (pData->mPos).y;
      local_38.x = (pData->mPos).x;
      local_2c = local_38.x;
      local_28 = local_38.y;
      local_24 = local_38.z;
      uVar1 = J3DUClipper::clip(&mDoLib_clipper::mClipper,&J3DGraphBase::j3dSys.mCurViewMtx,
                                &local_38,d_grass::260_0);
      if (uVar1 == 0) {
        pData->mInitFlags = pData->mInitFlags & 0xfd;
        if ((char)pData->mAnimIdx < '\0') {
          mtx::PSMTXTrans((double)(pData->mPos).x,(double)(pData->mPos).y,(double)(pData->mPos).z,
                          &pData->mModelMtx);
          m_Do_mtx::mDoMtx_YrotM(&pData->mModelMtx,sVar2);
          mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,&pData->mModelMtx,&pData->mModelMtx);
        }
        else {
          pAnimMtx = &this->mGrassAnm[(char)pData->mAnimIdx].mAnimMtx;
          pAnimMtx->m[3] = (pData->mPos).x;
          pAnimMtx->m[1][3] = (pData->mPos).y;
          pAnimMtx->m[2][3] = (pData->mPos).z;
          mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,pAnimMtx,&pData->mModelMtx);
        }
      }
      else {
        pData->mInitFlags = pData->mInitFlags | 2;
      }
    }
    iVar5 = iVar5 + 1;
    pData = pData + 1;
    sVar2 = sVar2 + 0xdcf;
  } while (iVar5 < 0x5dc);
  mDoLib_clipper::mClipper.mFar = mDoLib_clipper::mSystemFar;
  J3DUClipper::calcViewFrustum(&mDoLib_clipper::mClipper);
  J3DDrawBuffer::entryImm(J3DGraphBase::j3dSys.mpCurDrawBuffers[0],&this->parent,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x800785a0) */
/* __thiscall dGrass_packet_c::setData(dGrass_data_c *,
                                       int,
                                       cXyz &,
                                       int,
                                       signed char) */

void __thiscall
dGrass_packet_c::setData
          (dGrass_packet_c *this,dGrass_data_c *param_1,int param_2,cXyz *param_3,int roomNo,
          byte param_5)

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
    dVar3 = (double)param_3->y;
    param_1->mState = 1;
  }
  else {
    dVar3 = (double)d_grass::checkGroundY(param_3);
    param_1->mState = 2;
  }
  param_1->mInitFlags = 2;
  fVar4 = SComponent::cM_rndF(d_grass::7_0);
  param_1->mAnimIdx = (byte)(int)fVar4;
  fVar4 = param_3->z;
  (param_1->mPos).x = param_3->x;
  (param_1->mPos).y = (float)dVar3;
  (param_1->mPos).z = fVar4;
  param_1->mItemIdx = param_5;
  dGrass_room_c::newData(this->mGrassRoom + roomNo,param_1);
  this->mRndm = (short)param_2;
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dGrass_packet_c::newData(cXyz &,
                                       int,
                                       signed char) */

dGrass_data_c * __thiscall
dGrass_packet_c::newData(dGrass_packet_c *this,cXyz *pPos,int roomNo,byte itemIdx)

{
  bool bVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  dGrass_data_c *pData;
  
  bVar1 = false;
  if ((-1 < roomNo) && (roomNo < 0x40)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_grass.cpp",0x600,"0 <= i_roomNo && i_roomNo < 64");
    m_Do_printf::OSPanic("d_grass.cpp",0x600,&DAT_80352a45);
  }
  uVar4 = (uint)(ushort)this->mRndm;
  pData = this->mGrassData + uVar4;
  iVar2 = 0x5dc - uVar4;
  uVar5 = uVar4;
  if (uVar4 < 0x5dc) {
    do {
      if (pData->mState == 0) {
        setData(this,pData,uVar5,pPos,roomNo,itemIdx);
        return pData;
      }
      pData = pData + 1;
      uVar5 = uVar5 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  pData = this->mGrassData;
  iVar2 = 0;
  while( true ) {
    if (uVar4 == 0) {
      return (dGrass_data_c *)0x0;
    }
    if (pData->mState == 0) break;
    pData = pData + 1;
    iVar2 = iVar2 + 1;
    uVar4 = uVar4 - 1;
  }
  setData(this,pData,iVar2,pPos,roomNo,itemIdx);
  return pData;
}


/* __thiscall dGrass_packet_c::newAnm(void) */

int __thiscall dGrass_packet_c::newAnm(dGrass_packet_c *this)

{
  int iVar1;
  dGrass_anm_c *pdVar2;
  int iVar3;
  
  iVar1 = 8;
  iVar3 = 0x60;
  pdVar2 = this->mGrassAnm + 8;
  do {
    if (pdVar2->mState == 0) {
      pdVar2->mState = 1;
      pdVar2->mRotY = 0;
      pdVar2->mRotX = 0;
      return iVar1;
    }
    pdVar2 = pdVar2 + 1;
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return -1;
}


/* __thiscall dGrass_packet_c::setAnm(int,
                                      short) */

void __thiscall dGrass_packet_c::setAnm(dGrass_packet_c *this,int param_1,short param_2)

{
  dGrass_anm_c *pdVar1;
  
  pdVar1 = this->mGrassAnm + param_1;
  pdVar1->mState = 1;
  pdVar1->mRotY = param_2;
  pdVar1->mRotX = 0;
  return;
}


namespace d_grass {

void __sinit_d_grass_cpp(void)

{
  DAT_80378f11 = 1;
  DAT_80378f12 = 0xbb;
  DAT_80378f13 = 0xe0;
  DAT_80379af1 = 1;
  DAT_80379af2 = 0xbc;
  DAT_80379af3 = 0x7e;
  return;
}

