#include <d_tree.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_tree.h>
#include <mtx/vec.h>
#include <SComponent/c_math.h>
#include <d_cc_d.h>
#include <mtx/mtx.h>
#include <d_com_inf_game.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_vibration.h>
#include <d_cc_mass_s.h>
#include <SComponent/c_lib.h>
#include <d_particle.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <mtx/mtxvec.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <J3DGraphBase/J3DSys.h>
#include <gx/GXBump.h>
#include <gf/GFGeometry.h>
#include <gx/GXDisplayList.h>
#include <gf/GFTev.h>
#include <d_kankyo.h>
#include <gf/GFTransform.h>
#include <SComponent/c_xyz.h>
#include <SComponent/c_m3d_g_cyl.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <SComponent/c_bg_s.h>
#include <SComponent/c_bg_s_chk.h>
#include <J3DU/J3DUClipper.h>
#include <J3DGraphBase/J3DDrawBuffer.h>
#include <f_op_overlap_mng.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_com_static.h>
#include <dTree_anm_c.h>
#include <cXyz.h>
#include <dTree_data_c.h>
#include <daPy_py_c.h>
#include <dTree_packet_c.h>
#include <dTree_room_c.h>


namespace d_tree {
undefined4 l_particleOffset$4492;
undefined4 l_scale$4496;
}
undefined1 dTree_data_c;

namespace d_tree {
undefined1 l_CutSoundFlag;
undefined1 init$4494;
undefined1 init$4498;
}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80078940) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dTree_data_c::WorkCo(fopAc_ac_c *,
                                   unsigned long,
                                   int) */

void __thiscall
dTree_data_c::WorkCo(dTree_data_c *this,fopAc_ac_c *param_1,ulong param_2,int param_3)

{
  int iVar1;
  dTree_anm_c *pdVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  double dVar5;
  cXyz local_38;
  float local_2c;
  float local_28;
  float local_24;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (this->field_0x1 == 0) {
    if ((char)this->mAnimIdx < 8) {
      iVar1 = dTree_packet_c::newAnm
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTreePacket,
                         (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTreePacket)->mAnm
                         [(char)this->mAnimIdx].field_0x2);
      if (iVar1 < 0) goto LAB_80078940;
      this->mAnimIdx = (byte)iVar1;
    }
    local_38.x = (this->mPos).x - (param_1->mCurrent).mPos.x;
    local_28 = (this->mPos).y - (param_1->mCurrent).mPos.y;
    local_38.z = (this->mPos).z - (param_1->mCurrent).mPos.z;
    local_38.y = d_tree::0_0;
    local_2c = local_38.x;
    local_24 = local_38.z;
    mtx::PSVECSquareMag(&local_38);
    pdVar2 = (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTreePacket)->mAnm + (char)this->mAnimIdx;
    iVar1 = SComponent::cM_atan2s(local_2c,local_24);
    dVar5 = (double)JKernel::JMath::jmaCosTable
                    [(int)((param_1->mCurrent).mRot.y - iVar1 & 0xffffU) >>
                     (JKernel::JMath::jmaSinShift & 0x3f)];
    if (((double)d_tree::0_9 < dVar5) && ((param_1->parent).parent.mProcName == 0xa9)) {
      (**(code **)(*(int *)&param_1[1].parent.parent.mPi.mMtdTg.parent.mbAdded + 0x74))(param_1,7);
    }
    dVar4 = (double)ABS(d_tree::50_0 * param_1->mVelocityFwd);
    if ((double)d_tree::4000_0 < dVar4) {
      dVar4 = (double)d_tree::4000_0;
    }
    if (ABS(pdVar2->mAnimTimer) < ABS((float)(dVar4 * dVar5))) {
      pdVar2->mAnimTimer = (float)(dVar4 * dVar5);
      pdVar2->field_0xa = (short)iVar1;
    }
  }
LAB_80078940:
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80078ca0) */
/* __thiscall dTree_data_c::WorkAt_NoCutAnim(fopAc_ac_c *,
                                             unsigned long,
                                             int,
                                             dCcMassS_HitInf *,
                                             cCcD_Obj *) */

void __thiscall
dTree_data_c::WorkAt_NoCutAnim
          (dTree_data_c *this,fopAc_ac_c *param_1,ulong param_2,int param_3,dCcMassS_HitInf *param_4
          ,cCcD_Obj *param_5)

{
  short sVar1;
  int iVar2;
  dCcD_GObjInf *pdVar3;
  dTree_anm_c *pdVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f31;
  float fVar8;
  cXyz local_5c;
  cXyz local_50;
  cXyz local_44;
  cXyz local_38 [2];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (this->field_0x1 == 0) {
    if ((char)this->mAnimIdx < 8) {
      iVar2 = dTree_packet_c::newAnm
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTreePacket,
                         (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTreePacket)->mAnm
                         [(char)this->mAnimIdx].field_0x2);
      if (iVar2 < 0) goto LAB_80078ca0;
      this->mAnimIdx = (byte)iVar2;
    }
    pdVar3 = d_cc_d::dCcD_GetGObjInf(param_5);
    local_44.x = (pdVar3->mObjAt).mVel.x;
    local_38[0].y = (pdVar3->mObjAt).mVel.y;
    local_44.z = (pdVar3->mObjAt).mVel.z;
    local_44.y = d_tree::0_0;
    local_38[0].x = local_44.x;
    local_38[0].z = local_44.z;
    fVar8 = mtx::PSVECSquareMag(&local_44);
    dVar7 = (double)fVar8;
    if ((double)d_tree::0_0 < dVar7) {
      dVar6 = 1.0 / SQRT(dVar7);
      dVar6 = d_tree::_4366 * dVar6 * (d_tree::_4367 - dVar7 * dVar6 * dVar6);
      dVar6 = d_tree::_4366 * dVar6 * (d_tree::_4367 - dVar7 * dVar6 * dVar6);
      dVar7 = (double)(float)(dVar7 * d_tree::_4366 * dVar6 *
                                      (d_tree::_4367 - dVar7 * dVar6 * dVar6));
    }
    if ((float)ABS(dVar7) < SComponent::G_CM3D_F_ABS_MIN) {
      sVar1 = (param_1->parent).parent.mProcName;
      if (sVar1 == 0xa9) {
        local_50.x = (this->mPos).x - (param_1->mCurrent).mPos.x;
        local_38[0].y = (this->mPos).y - (param_1->mCurrent).mPos.y;
        local_50.z = (this->mPos).z - (param_1->mCurrent).mPos.z;
        local_50.y = d_tree::0_0;
        local_38[0].x = local_50.x;
        local_38[0].z = local_50.z;
        fVar8 = mtx::PSVECSquareMag(&local_50);
        dVar7 = (double)fVar8;
        if ((double)d_tree::0_0 < dVar7) {
          dVar6 = 1.0 / SQRT(dVar7);
          dVar6 = d_tree::_4366 * dVar6 * (d_tree::_4367 - dVar7 * dVar6 * dVar6);
          dVar6 = d_tree::_4366 * dVar6 * (d_tree::_4367 - dVar7 * dVar6 * dVar6);
          dVar7 = (double)(float)(dVar7 * d_tree::_4366 * dVar6 *
                                          (d_tree::_4367 - dVar7 * dVar6 * dVar6));
        }
      }
      else {
        if ((sVar1 == 0x128) || (sVar1 == 0x129)) {
          local_5c.x = (this->mPos).x - (param_1->mCurrent).mPos.x;
          local_38[0].y = (this->mPos).y - (param_1->mCurrent).mPos.y;
          local_5c.z = (this->mPos).z - (param_1->mCurrent).mPos.z;
          local_5c.y = d_tree::0_0;
          local_38[0].x = local_5c.x;
          local_38[0].z = local_5c.z;
          fVar8 = mtx::PSVECSquareMag(&local_5c);
          dVar6 = (double)fVar8;
          if ((double)d_tree::0_0 < dVar6) {
            dVar7 = 1.0 / SQRT(dVar6);
            dVar7 = d_tree::_4366 * dVar7 * (d_tree::_4367 - dVar6 * dVar7 * dVar7);
            dVar7 = d_tree::_4366 * dVar7 * (d_tree::_4367 - dVar6 * dVar7 * dVar7);
            dVar6 = (double)(float)(dVar6 * d_tree::_4366 * dVar7 *
                                            (d_tree::_4367 - dVar6 * dVar7 * dVar7));
          }
          dVar7 = (double)(float)((double)d_tree::200_0 - dVar6);
          if ((double)(float)((double)d_tree::200_0 - dVar6) < (double)d_tree::0_0) {
            dVar7 = (double)d_tree::0_0;
          }
          mtx::PSVECNormalize(local_38,local_38);
          mtx::PSVECScale(local_38,local_38,(float)dVar7);
        }
      }
    }
    pdVar4 = (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTreePacket)->mAnm + (char)this->mAnimIdx;
    iVar2 = SComponent::cM_atan2s(local_38[0].x,local_38[0].z);
    fVar8 = (float)((double)d_tree::50_0 * dVar7);
    if (d_tree::4000_0 < fVar8) {
      fVar8 = d_tree::4000_0;
    }
    if (ABS(pdVar4->mAnimTimer) < ABS(fVar8)) {
      pdVar4->mAnimTimer = fVar8;
      pdVar4->field_0xa = (short)iVar2;
    }
  }
LAB_80078ca0:
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* __thiscall dTree_data_c::WorkAt(fopAc_ac_c *,
                                   unsigned long,
                                   int,
                                   dCcMassS_HitInf *) */

void __thiscall
dTree_data_c::WorkAt
          (dTree_data_c *this,fopAc_ac_c *param_1,ulong param_2,int param_3,dCcMassS_HitInf *param_4
          )

{
  cCcD_Obj__DamageTypes cVar1;
  int iVar2;
  dTree_anm_c *pdVar3;
  sbyte sVar4;
  cCcD_Obj *pcVar5;
  cXyz local_68;
  cXyz local_5c;
  float local_50;
  float local_4c;
  float local_48;
  MTX34 MStack68;
  
  pcVar5 = param_4->mpAtObj;
  if ((pcVar5 == (cCcD_Obj *)0x0) ||
     (((((cVar1 = (pcVar5->parent).mObjAt.mDamageTypes, (cVar1 & DekuLeafWind) == 0 &&
         ((cVar1 & Bomb) == 0)) && ((cVar1 & Fire) == 0)) &&
       (((cVar1 & NormalArrow) == 0 && ((cVar1 & FireArrows) == 0)))) &&
      (((cVar1 & IceArrows) == 0 && (((cVar1 & LightArrow) == 0 && ((cVar1 & 0x8000) == 0)))))))) {
    local_68.x = (this->mPos).x - (param_1->mCurrent).mPos.x;
    local_4c = (this->mPos).y - (param_1->mCurrent).mPos.y;
    local_68.z = (this->mPos).z - (param_1->mCurrent).mPos.z;
    local_68.y = d_tree::0_0;
    local_50 = local_68.x;
    local_48 = local_68.z;
    mtx::PSVECSquareMag(&local_68);
    SComponent::cM_atan2s(local_50,local_48);
    if (this->field_0x1 == 0) {
      if ((char)this->mAnimIdx < 8) {
        iVar2 = dTree_packet_c::newAnm
                          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTreePacket,
                           (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTreePacket)->mAnm
                           [(char)this->mAnimIdx].field_0x2);
        if (iVar2 < 0) {
          return;
        }
        this->mAnimIdx = (byte)iVar2;
      }
      this->field_0x1 = 1;
      pdVar3 = (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTreePacket)->mAnm + (char)this->mAnimIdx;
      pdVar3->field_0xa = (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTreePacket)->field_0x6738;
      pdVar3->mAnimTimer = d_tree::0_0;
      pdVar3->field_0x10 = d_tree::_2_0;
      pdVar3->field_0x14 = d_tree::_4441;
      mtx::PSMTXScale((double)d_tree::_4442,(double)d_tree::1_0,(double)d_tree::_4442,&MStack68);
      mtx::PSMTXConcat(&this->mShadowMtx,&MStack68,&this->mShadowMtx);
      if (d_tree::l_CutSoundFlag == '\0') {
        d_tree::l_CutSoundFlag = '\x01';
        sVar4 = d_com_inf_game::dComIfGp_getReverb(param_3);
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x6917,&this->mPos,0,sVar4,d_tree::1_0,d_tree::1_0,
                   d_tree::_4444,d_tree::_4444,0);
      }
      local_5c.x = d_tree::0_0;
      local_5c.y = d_tree::1_0;
      local_5c.z = d_tree::0_0;
      dVibration_c::StartShock
                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,4,-0x21,&local_5c);
    }
  }
  else {
    WorkAt_NoCutAnim(this,param_1,param_2,param_3,param_4,pcVar5);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dTree_data_c::hitCheck(fopAc_ac_c *,
                                     int) */

undefined4 __thiscall dTree_data_c::hitCheck(dTree_data_c *this,fopAc_ac_c *param_1,int param_2)

{
  uint uVar1;
  fopAc_ac_c *pActor;
  dCcMassS_HitInf hitInf;
  
  pActor = (fopAc_ac_c *)0x0;
  hitInf.vtbl = (undefined *)&dCcMassS_HitInf::__vt;
  uVar1 = dCcMassS_Mng::Chk(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng,&this->mPos,
                            &pActor,&hitInf);
  if ((uVar1 != 0) && (pActor != (fopAc_ac_c *)0x0)) {
    if ((uVar1 & 2) != 0) {
      WorkCo(this,pActor,uVar1,param_2);
    }
    if ((uVar1 & 1) != 0) {
      WorkAt(this,pActor,uVar1,param_2,&hitInf);
    }
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dTree_data_c::animation(int) */

void __thiscall dTree_data_c::animation(dTree_data_c *this,int param_1)

{
  float fVar1;
  float fVar2;
  dTree_anm_c *pdVar3;
  double dVar4;
  int iVar5;
  sbyte sVar7;
  JPABaseEmitter *pJVar6;
  dTree_anm_c *pdVar8;
  uint uVar9;
  cXyz cStack72;
  cXyz local_3c;
  undefined4 local_30;
  uint uStack44;
  longlong local_28;
  double local_20;
  
  dVar4 = d_tree::_4583;
  pdVar8 = (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTreePacket)->mAnm + (char)this->mAnimIdx;
  if (this->field_0x1 == 0) {
    uStack44 = (int)pdVar8->field_0x8 ^ 0x80000000;
    local_30 = 0x43300000;
    fVar1 = d_tree::_4444 * (float)((double)CONCAT44(0x43300000,uStack44) - d_tree::_4583);
    pdVar8->mAnimTimer = pdVar8->mAnimTimer + fVar1;
    pdVar8->mAnimTimer = pdVar8->mAnimTimer * d_tree::0_9;
    local_28 = (longlong)(int)pdVar8->mAnimTimer;
    pdVar8->field_0x8 = pdVar8->field_0x8 + (short)(int)pdVar8->mAnimTimer;
    fVar2 = d_tree::0_0;
    local_20 = (double)CONCAT44(0x43300000,(int)pdVar8->field_0x8 ^ 0x80000000);
    if (d_tree::0_0 <= (float)(local_20 - dVar4) * fVar1) {
      if (d_tree::40_0 <= ABS(pdVar8->mAnimTimer)) {
        if (d_tree::400_0 < ABS(pdVar8->mAnimTimer)) {
          local_3c.z = (this->mPos).z;
          local_3c.y = d_tree::_4574 + (this->mPos).y;
          local_3c.x = (this->mPos).x;
          dPa_control_c::setSimple
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0x3dc,&local_3c,0xff,
                     &d_com_inf_game::g_whiteColor,&d_com_inf_game::g_whiteColor,0);
          sVar7 = d_com_inf_game::dComIfGp_getReverb(param_1);
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x6932,&this->mPos,0,sVar7,d_tree::1_0,d_tree::1_0,
                     d_tree::_4444,d_tree::_4444,0);
        }
      }
      else {
        pdVar8->field_0x8 = 0;
        pdVar8->mAnimTimer = fVar2;
        uVar9 = (uint)(int)pdVar8->field_0x2 >> 0xd & 7;
        pdVar3 = (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTreePacket)->mAnm;
        iVar5 = SComponent::cLib_chaseAngleS(&pdVar8->field_0x4,(int)pdVar3[uVar9].field_0x4,800);
        if ((iVar5 != 0) &&
           (iVar5 = SComponent::cLib_chaseAngleS
                              (&pdVar8->field_0x6,(int)*(short *)&pdVar3[uVar9].field_0x6,800),
           iVar5 != 0)) {
          *(undefined *)
           ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTreePacket)->mAnm + (char)this->mAnimIdx) =
               0;
          this->mAnimIdx = (byte)uVar9;
        }
      }
    }
    pdVar8->field_0x4 = pdVar8->field_0x8;
  }
  else {
    iVar5 = (int)((int)pdVar8->field_0xa & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
    fVar1 = JKernel::JMath::jmaSinTable[iVar5];
    fVar2 = JKernel::JMath::jmaCosTable[iVar5];
    pdVar8->field_0x14 = pdVar8->field_0x14 + d_tree::_2_0;
    if (pdVar8->field_0x14 < d_tree::_40_0) {
      pdVar8->field_0x14 = d_tree::_40_0;
    }
    pdVar8->field_0x18 = pdVar8->field_0x18 + pdVar8->field_0x10 * fVar1;
    pdVar8->field_0x20 = pdVar8->field_0x20 + pdVar8->field_0x10 * fVar2;
    pdVar8->field_0x1c = pdVar8->field_0x1c + pdVar8->field_0x14;
    if (pdVar8->field_0x1c < d_tree::_5_0) {
      pdVar8->field_0x1c = d_tree::_5_0;
      pdVar8->field_0x10 = d_tree::0_0;
    }
    SComponent::cLib_chaseF(&pdVar8->mAnimTimer,d_tree::_4577,d_tree::40_0);
    if (pdVar8->field_0x4 == 0x3520) {
      if (d_tree::0_0 == pdVar8->field_0x10) {
        this->field_0x0 = this->field_0x0 | 8;
        mtx::PSMTXCopy(&pdVar8->field_0x24,&this->field_0x70);
        (this->field_0x70).m[3] = (this->mPos).x + pdVar8->field_0x18;
        (this->field_0x70).m[1][3] = (this->mPos).y + pdVar8->field_0x1c;
        (this->field_0x70).m[2][3] = (this->mPos).z + pdVar8->field_0x20;
        *(undefined *)
         ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTreePacket)->mAnm + (char)this->mAnimIdx) = 0;
        this->mAnimIdx = (byte)((uint)(int)pdVar8->field_0x2 >> 0xd) & 7;
      }
    }
    else {
      local_20 = (double)(longlong)(int)pdVar8->mAnimTimer;
      iVar5 = SComponent::cLib_chaseAngleS(&pdVar8->field_0x4,0x3520,(int)pdVar8->mAnimTimer);
      if (iVar5 != 0) {
        if (d_tree::init_4494 == '\0') {
          d_tree::l_particleOffset_4492 = d_tree::0_0;
          DAT_803e20c4 = d_tree::_4578;
          DAT_803e20c8 = d_tree::0_0;
          Runtime.PPCEABI.H::__register_global_object
                    (&d_tree::l_particleOffset_4492,::cXyz::_cXyz,&d_tree::_4493);
          d_tree::init_4494 = '\x01';
        }
        if (d_tree::init_4498 == '\0') {
          d_tree::l_scale_4496 = d_tree::_4579;
          DAT_803e20dc = d_tree::_4579;
          DAT_803e20e0 = d_tree::_4579;
          Runtime.PPCEABI.H::__register_global_object
                    (&d_tree::l_scale_4496,::cXyz::_cXyz,&d_tree::_4497);
          d_tree::init_4498 = '\x01';
        }
        mtx::PSMTXMultVec(&pdVar8->field_0x24,(cXyz *)&d_tree::l_particleOffset_4492,&cStack72);
        pJVar6 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,2,0x2022,
                                    &cStack72,(csXyz *)0x0,(cXyz *)&d_tree::l_scale_4496,0xaa,
                                    (dPa_levelEcallBack *)&mSmokeEcallback,(char)param_1,
                                    (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
        if (pJVar6 != (JPABaseEmitter *)0x0) {
          pJVar6->mRate = d_tree::_4580;
          pJVar6->mSpread = d_tree::1_0;
          pJVar6->mInitialVelDir = d_tree::_4581;
          pJVar6->mLifeTime = 0x3c;
          pJVar6->mMaxFrame = 1;
        }
        cStack72.y = cStack72.y - d_tree::50_0;
        dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x3df,&cStack72,
                           (csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1,
                           (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
      }
    }
  }
  return;
}


/* __thiscall dTree_room_c::newData(dTree_data_c *) */

void __thiscall dTree_room_c::newData(dTree_room_c *this,dTree_data_c *param_1)

{
  param_1->mpNext = this->mpHead;
  this->mpHead = param_1;
  return;
}


/* __thiscall dTree_room_c::deleteData(void) */

void __thiscall dTree_room_c::deleteData(dTree_room_c *this)

{
  while (this->mpHead != (dTree_data_c *)0x0) {
    this->mpHead->field_0x0 = 0;
    JAIZelBasic::seDeleteObject(JAIZelBasic::zel_basic,(Vec *)&this->mpHead->mPos);
    this->mpHead = this->mpHead->mpNext;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dTree_packet_c::dTree_packet_c(void) */

void __thiscall dTree_packet_c::dTree_packet_c(dTree_packet_c *this)

{
  dTree_data_c *pdVar1;
  dTree_anm_c *pdVar2;
  short sVar3;
  int iVar4;
  
  this->vtbl = (undefined *)&J3DPacket::__vt;
  this->field_0x4 = (undefined *)0x0;
  this->field_0x8 = (undefined *)0x0;
  this->field_0xc = (undefined *)0x0;
  this->vtbl = &__vt;
  Runtime.PPCEABI.H::__construct_array
            (this->mData,dTree_data_c::dTree_data_c,dTree_data_c::_dTree_data_c,0x104,0x40);
  Runtime.PPCEABI.H::__construct_array
            (this->mAnm,dTree_anm_c::dTree_anm_c,dTree_anm_c::_dTree_anm_c,0x84,0x48);
  Runtime.PPCEABI.H::__construct_array
            (this->mRoom,dTree_room_c::dTree_room_c,(undefined *)0x0,4,0x40);
  pdVar1 = this->mData;
  iVar4 = 0x40;
  do {
    pdVar1->field_0x0 = 0;
    pdVar1 = pdVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  pdVar2 = this->mAnm;
  iVar4 = 0x48;
  do {
    *(undefined *)pdVar2 = 0;
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
  return;
}


/* __thiscall dTree_room_c::dTree_room_c(void) */

void __thiscall dTree_room_c::dTree_room_c(dTree_room_c *this)

{
  this->mpHead = (dTree_data_c *)0x0;
  return;
}


/* __thiscall dTree_anm_c::dTree_anm_c(void) */

void __thiscall dTree_anm_c::dTree_anm_c(dTree_anm_c *this)

{
  *(undefined *)this = 0;
  return;
}


/* __thiscall dTree_data_c::dTree_data_c(void) */

void __thiscall dTree_data_c::dTree_data_c(dTree_data_c *this)

{
  this->field_0x0 = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dTree_packet_c::draw(void) */

void __thiscall dTree_packet_c::draw(dTree_packet_c *this)

{
  int iVar1;
  int iVar2;
  dTree_data_c *pTree;
  dTree_room_c *pdVar3;
  int iVar4;
  _GXColor local_38;
  _GXColor local_34;
  _GXColor local_30;
  _GXColor local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  J3DSys::reinitGX(&J3DGraphBase::j3dSys);
  gx::GXSetNumIndStages(0);
  gf::GFSetVtxDescv(&d_tree::l_shadowVtxDescList_4654);
  gf::GFSetVtxAttrFmtv(0,&d_tree::l_shadowVtxAttrFmtList_4655);
  gf::GFSetArray(GX_VA_POS,(int)&d_tree::g_dTree_shadowPos,3);
  gf::GFSetArray(GX_VA_TEX0,(int)&d_tree::g_dTree_shadowTexCoord,2);
  gx::GXCallDisplayList(&d_tree::g_dTree_shadowMatDL,0x80);
  local_30 = d_tree::l_shadowColor_4656;
  gf::GFSetTevColor(GX_TEVREG0,&local_30);
  pdVar3 = this->mRoom;
  iVar4 = 0;
  iVar2 = 0;
  do {
    d_kankyo::dKy_GfFog_tevstr_set
              ((dKy_tevstr_c *)
               ((int)&dStage_roomControl_c::mStatus[0].mTevStr.mLightObj.mPos.x + iVar2));
    pTree = pdVar3->mpHead;
    while( true ) {
      if (pTree == (dTree_data_c *)0x0) break;
      if ((pTree->field_0x0 & 4) == 0) {
        gf::GFLoadPosMtxImm((MTX34 *)&pTree->field_0xd0,0);
        gx::GXCallDisplayList(&d_tree::g_dTree_Oba_kage_32DL,0x20);
      }
      pTree = pTree->mpNext;
    }
    iVar4 = iVar4 + 1;
    pdVar3 = pdVar3 + 1;
    iVar2 = iVar2 + 0x114;
  } while (iVar4 < 0x40);
  gf::GFSetVtxDescv(&d_tree::l_vtxDescList_4669);
  gf::GFSetVtxAttrFmtv(0,&d_tree::l_vtxAttrFmtList_4670);
  gf::GFSetArray(GX_VA_POS,(int)&d_tree::l_pos,0xc);
  gf::GFSetArray(GX_VA_CLR0,(int)&d_tree::l_color,4);
  gf::GFSetArray(GX_VA_TEX0,(int)&d_tree::l_texCoord,8);
  gx::GXCallDisplayList(&d_tree::l_matDL,0xa0);
  pdVar3 = this->mRoom;
  iVar4 = 0;
  iVar2 = 0;
  do {
    local_28 = *(undefined4 *)((int)&dStage_roomControl_c::mStatus[0].mTevStr.mColorC0.r + iVar2);
    local_24 = *(undefined4 *)((int)&dStage_roomControl_c::mStatus[0].mTevStr.mColorC0.b + iVar2);
    gf::GFSetTevColorS10(GX_TEVREG0,(_GXColorS10 *)&local_28);
    local_34 = *(_GXColor *)(&dStage_roomControl_c::mStatus[0].mTevStr.mColorK0.r + iVar2);
    gf::GFSetTevColor(GX_TEVREG1,&local_34);
    d_kankyo::dKy_GfFog_tevstr_set
              ((dKy_tevstr_c *)
               ((int)&dStage_roomControl_c::mStatus[0].mTevStr.mLightObj.mPos.x + iVar2));
    pTree = pdVar3->mpHead;
    while( true ) {
      if (pTree == (dTree_data_c *)0x0) break;
      if ((pTree->field_0x0 & 4) == 0) {
        iVar1 = (uint)pTree->field_0x1 * 3;
        if (pTree->field_0x3 != 0) {
          local_2c = (_GXColor)((uint)local_2c & 0xffffff00 | (uint)(byte)pTree->field_0x3);
          local_38 = local_2c;
          gf::GFSetTevColor(GX_TEVREG2,&local_38);
          gf::GFLoadPosMtxImm(&pTree->field_0x10,0);
          gx::GXCallDisplayList
                    ((&d_tree::l_modelDataStatus_4682)
                     [(uint)(byte)(&d_tree::l_modelStatus_4683)[iVar1] * 2],
                     *(undefined4 *)
                      (&DAT_8037b19c + (uint)(byte)(&d_tree::l_modelStatus_4683)[iVar1] * 8));
          gx::GXCallDisplayList
                    ((&d_tree::l_modelDataStatus_4682)[(uint)*(byte *)(iVar1 + -0x7fc09deb) * 2],
                     *(undefined4 *)(&DAT_8037b19c + (uint)*(byte *)(iVar1 + -0x7fc09deb) * 8));
        }
        gf::GFLoadPosMtxImm(&pTree->field_0x40,0);
        gx::GXCallDisplayList
                  ((&d_tree::l_modelDataStatus_4682)[(uint)*(byte *)(iVar1 + -0x7fc09dea) * 2],
                   *(undefined4 *)(&DAT_8037b19c + (uint)*(byte *)(iVar1 + -0x7fc09dea) * 8));
      }
      pTree = pTree->mpNext;
    }
    iVar4 = iVar4 + 1;
    pdVar3 = pdVar3 + 1;
    iVar2 = iVar2 + 0x114;
  } while (iVar4 < 0x40);
  _sOldVcdVatCmd = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dTree_packet_c::calc(void) */

void __thiscall dTree_packet_c::calc(dTree_packet_c *this)

{
  uint uVar1;
  int iVar2;
  daPy_lk_c *this_00;
  float fVar3;
  double dVar4;
  float fVar5;
  float fVar6;
  double dVar7;
  dTree_data_c *this_01;
  int iVar8;
  dTree_anm_c *pdVar9;
  int iVar10;
  cXyz local_98;
  cXyz local_8c;
  cXyz local_80;
  float local_74;
  float local_70;
  float local_6c;
  cXyz local_68;
  undefined4 local_58;
  int iStack84;
  longlong local_50;
  undefined4 local_48;
  uint uStack68;
  longlong local_40;
  undefined4 local_38;
  int iStack52;
  longlong local_30;
  longlong local_28;
  
  dVar7 = d_tree::_4788;
  fVar6 = d_tree::_4786;
  fVar5 = d_tree::_4785;
  dVar4 = d_tree::_4583;
  fVar3 = d_tree::4000_0;
  pdVar9 = this->mAnm;
  iVar8 = 0;
  iVar10 = 8;
  do {
    iStack84 = g__Timer + iVar8;
    local_58 = 0x43300000;
    uVar1 = (uint)(fVar3 * (float)((double)CONCAT44(0x43300000,iStack84) - dVar7));
    local_50 = (longlong)(int)uVar1;
    uStack68 = (int)pdVar9->field_0x2 ^ 0x80000000;
    local_48 = 0x43300000;
    iVar2 = (int)(fVar5 + (float)((double)CONCAT44(0x43300000,uStack68) - dVar4) +
                 fVar5 * JKernel::JMath::jmaCosTable
                         [(int)(uVar1 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)]);
    local_40 = (longlong)iVar2;
    *(short *)&pdVar9->field_0x6 = (short)iVar2;
    iStack52 = g__Timer + iVar8;
    local_38 = 0x43300000;
    uVar1 = (uint)(fVar6 * (float)((double)CONCAT44(0x43300000,iStack52) - dVar7));
    local_30 = (longlong)(int)uVar1;
    iVar2 = (int)(fVar5 + fVar5 * JKernel::JMath::jmaCosTable
                                  [(int)(uVar1 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)]);
    local_28 = (longlong)iVar2;
    pdVar9->field_0x4 = (short)iVar2;
    this_00 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
    pdVar9 = pdVar9 + 1;
    iVar8 = iVar8 + 0xfa;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  iVar8 = (int)(char)dStage_roomControl_c::mStayNo;
  this_01 = this->mRoom[iVar8].mpHead;
  if (this_01 != (dTree_data_c *)0x0) {
    this->field_0x6734 =
         (byte)(((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x29c >>
               6) & 1;
    ::daPy_py_c::getSwordTopPos(&local_80,&this_00->parent);
    local_68.x = local_80.x;
    local_68.y = local_80.y;
    local_68.z = local_80.z;
    ::cXyz::operator__(&local_8c,&local_68,&(this_00->parent).parent.mCurrent.mPos);
    local_74 = local_8c.x;
    local_70 = local_8c.y;
    local_6c = local_8c.z;
    iVar10 = SComponent::cM_atan2s(local_8c.x,local_8c.z);
    this->field_0x6736 = (short)iVar10;
    ::cXyz::operator__(&local_98,&this->field_0x673c,&local_68);
    local_74 = local_98.x;
    local_70 = local_98.y;
    local_6c = local_98.z;
    iVar10 = SComponent::cM_atan2s(local_98.x,local_98.z);
    this->field_0x6738 = (short)iVar10;
    (this->field_0x673c).x = local_68.x;
    (this->field_0x673c).y = local_68.y;
    (this->field_0x673c).z = local_68.z;
    d_tree::l_CutSoundFlag = 0;
    ::cM3dGCyl::SetR(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mCylAttr.mCyl,
                     d_tree::40_0);
    ::cM3dGCyl::SetH(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mCylAttr.mCyl,
                     d_tree::200_0);
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mChkFlag = 0x13;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mResultCamBit = 1;
    do {
      if ((this_01->field_0x0 & 8) == 0) {
        dTree_data_c::hitCheck(this_01,(fopAc_ac_c *)this_00,iVar8);
      }
      if ('\a' < (char)this_01->mAnimIdx) {
        dTree_data_c::animation(this_01,iVar8);
      }
      this_01 = this_01->mpNext;
    } while (this_01 != (dTree_data_c *)0x0);
  }
  return;
}


namespace d_tree {

/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x80079e4c) */
/* __stdcall checkGroundY(dTree_data_c *,
                          cXyz &) */

double checkGroundY(dTree_data_c *param_1,cXyz *param_2)

{
  cM3dGPla *pTri;
  cBgS_PolyPassChk *pcVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f31;
  cXyz norm;
  cBgS_GndChk local_98;
  cBgS_PolyPassChk local_58;
  undefined local_4c [24];
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  ::cBgS_GndChk::cBgS_GndChk(&local_98);
  pcVar1 = &local_58;
  local_58.mbObjThrough = 0;
  local_58.mbCamThrough = 0;
  local_58.mbLinkThrough = 0;
  local_58.mbArrowsAndLightThrough = 0;
  local_58.mbBombThrough = 0;
  local_58.mbBoomerangThrough = 0;
  local_58.mbHookshotThrough = 0;
  local_4c._4_4_ = 1;
  local_98.parent.vtbl = &::dBgS_GndChk::__vt;
  local_98.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371f08;
  local_58.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_4c._0_4_ = &PTR_80371f20;
  local_98.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar1;
  if (pcVar1 != (cBgS_PolyPassChk *)0x0) {
    local_98.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_4c;
  }
  param_2->y = param_2->y + 50_0;
  local_98.mPos.x = param_2->x;
  local_98.mPos.y = param_2->y;
  local_98.mPos.z = param_2->z;
  local_98.parent.mpPolyPassChk = pcVar1;
  dVar5 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_98);
  param_2->y = param_2->y - 50_0;
  if ((double)_1_0E9 < dVar5) {
    pTri = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                           (uint)(ushort)local_98.mPolyInfo.mBgIndex,
                           (uint)(ushort)local_98.mPolyInfo.mTriIdx);
    norm.x = (pTri->mNorm).x;
    norm.y = (pTri->mNorm).y;
    norm.z = (pTri->mNorm).z;
  }
  else {
    dVar5 = (double)param_2->y;
    norm.x = 0_0;
    norm.y = 1_0;
    norm.z = 0_0;
  }
  dVar6 = (double)(1_0 - norm.x * norm.x);
  if ((double)0_0 < dVar6) {
    dVar3 = 1.0 / SQRT(dVar6);
    dVar3 = _4366 * dVar3 * (_4367 - dVar6 * dVar3 * dVar3);
    dVar3 = _4366 * dVar3 * (_4367 - dVar6 * dVar3 * dVar3);
    dVar6 = (double)(float)(dVar6 * _4366 * dVar3 * (_4367 - dVar6 * dVar3 * dVar3));
  }
  dVar4 = (double)0_0;
  dVar3 = dVar4;
  if (dVar4 != dVar6) {
    dVar4 = (double)(float)((double)norm.y * dVar6);
    dVar3 = (double)(float)(-(double)norm.z * dVar6);
  }
  (param_1->mShadowMtx).m[0] = (float)dVar6;
  (param_1->mShadowMtx).m[1] = norm.x;
  (param_1->mShadowMtx).m[2] = 0_0;
  (param_1->mShadowMtx).m[3] = param_2->x;
  (param_1->mShadowMtx).m[1][0] = (float)(-(double)norm.x * dVar4);
  (param_1->mShadowMtx).m[1][1] = norm.y;
  (param_1->mShadowMtx).m[1][2] = (float)dVar3;
  (param_1->mShadowMtx).m[1][3] = (float)((double)1_0 + dVar5);
  (param_1->mShadowMtx).m[2][0] = (float)((double)norm.x * dVar3);
  (param_1->mShadowMtx).m[2][1] = norm.z;
  (param_1->mShadowMtx).m[2][2] = (float)dVar4;
  (param_1->mShadowMtx).m[2][3] = param_2->z;
  local_58.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_4c._0_4_ = &PTR_80371f20;
  if (pcVar1 != (cBgS_PolyPassChk *)0x0) {
    local_58.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_4c._0_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != &DAT_0000004c) &&
       (local_4c._0_4_ = &::dBgS_GrpPassChk::__vt, (undefined *)register0x00000004 != &DAT_0000004c)
       ) {
      local_4c._0_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar1 != (cBgS_PolyPassChk *)0x0) &&
       (local_58.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar1 != (cBgS_PolyPassChk *)0x0)) {
      local_58.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_98.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_98.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_98.parent);
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return dVar5;
}

}

/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dTree_packet_c::update(void) */

void __thiscall dTree_packet_c::update(dTree_packet_c *this)

{
  uint uVar1;
  int iVar2;
  dTree_data_c *pdVar3;
  dTree_anm_c *pdVar4;
  int iVar5;
  double dVar6;
  cXyz local_48;
  float local_3c;
  float local_38;
  float local_34;
  
  pdVar4 = this->mAnm;
  iVar5 = 0;
  do {
    m_Do_mtx::mDoMtx_YrotS(&mDoMtx_stack_c::now,(int)pdVar4->field_0xa);
    m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,pdVar4->field_0x4);
    m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,*(short *)&pdVar4->field_0x6 - pdVar4->field_0xa);
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,&pdVar4->field_0x24);
    m_Do_mtx::mDoMtx_YrotS(&mDoMtx_stack_c::now,(int)pdVar4->field_0xa);
    m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,pdVar4->field_0x8);
    m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,pdVar4->field_0x2 - pdVar4->field_0xa);
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)&pdVar4->field_0x54);
    iVar5 = iVar5 + 1;
    pdVar4 = pdVar4 + 1;
  } while (iVar5 < 0x48);
  pdVar3 = this->mData;
  iVar2 = 0;
  mDoLib_clipper::mClipper.mFar = d_tree::_5026 * mDoLib_clipper::mSystemFar;
  J3DUClipper::calcViewFrustum(&mDoLib_clipper::mClipper);
  iVar5 = 0;
  do {
    if ((pdVar3->field_0x0 & 2) != 0) {
      if (((pdVar3->field_0x0 & 0x10) != 0) && (iVar2 < 4)) {
        dVar6 = d_tree::checkGroundY(pdVar3,&pdVar3->mPos);
        (pdVar3->mPos).y = (float)dVar6;
        pdVar3->field_0x0 = pdVar3->field_0x0 & 0xef;
        iVar2 = iVar2 + 1;
      }
      local_48.z = (pdVar3->mPos).z;
      local_48.y = d_tree::_5027 + (pdVar3->mPos).y;
      local_48.x = (pdVar3->mPos).x;
      local_3c = local_48.x;
      local_38 = local_48.y;
      local_34 = local_48.z;
      uVar1 = J3DUClipper::clip(&mDoLib_clipper::mClipper,&J3DGraphBase::j3dSys.mCurViewMtx,
                                &local_48,d_tree::_5027);
      if (uVar1 == 0) {
        pdVar3->field_0x0 = pdVar3->field_0x0 & 0xfb;
        pdVar4 = this->mAnm + (char)pdVar3->mAnimIdx;
        if ((pdVar3->field_0x0 & 8) == 0) {
          (pdVar4->field_0x24).m[3] = (pdVar3->mPos).x + pdVar4->field_0x18;
          (pdVar4->field_0x24).m[1][3] = (pdVar3->mPos).y + pdVar4->field_0x1c;
          (pdVar4->field_0x24).m[2][3] = (pdVar3->mPos).z + pdVar4->field_0x20;
          mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,&pdVar4->field_0x24,&pdVar3->field_0x10
                          );
        }
        else {
          mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,&pdVar3->field_0x70,&pdVar3->field_0x10
                          );
          SComponent::cLib_chaseUC(&pdVar3->field_0x3,0,8);
        }
        *(float *)&pdVar4->field_0x60 = (pdVar3->mPos).x;
        *(float *)&pdVar4->field_0x70 = (pdVar3->mPos).y;
        *(float *)&pdVar4->field_0x80 = (pdVar3->mPos).z;
        mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,(MTX34 *)&pdVar4->field_0x54,
                         &pdVar3->field_0x40);
        mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,&pdVar3->mShadowMtx,
                         (MTX34 *)&pdVar3->field_0xd0);
      }
      else {
        pdVar3->field_0x0 = pdVar3->field_0x0 | 4;
      }
    }
    iVar5 = iVar5 + 1;
    pdVar3 = pdVar3 + 1;
  } while (iVar5 < 0x40);
  mDoLib_clipper::mClipper.mFar = mDoLib_clipper::mSystemFar;
  J3DUClipper::calcViewFrustum(&mDoLib_clipper::mClipper);
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufWorldXlu;
  J3DDrawBuffer::entryImm
            (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufWorldXlu,(J3DPacket *)this,0);
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8007a218) */
/* __thiscall dTree_packet_c::setData(dTree_data_c *,
                                      int,
                                      cXyz &,
                                      unsigned char,
                                      int) */

void __thiscall
dTree_packet_c::setData
          (dTree_packet_c *this,dTree_data_c *param_1,int param_2,cXyz *param_3,byte param_4,
          int param_5)

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
    param_1->field_0x0 = 0x16;
  }
  else {
    dVar3 = d_tree::checkGroundY(param_1,param_3);
    param_1->field_0x0 = 6;
  }
  param_1->field_0x1 = param_4;
  param_1->field_0x3 = ~-(param_4 == 1);
  fVar4 = SComponent::cM_rndF(d_tree::7_0);
  param_1->mAnimIdx = (byte)(int)fVar4;
  fVar4 = param_3->z;
  (param_1->mPos).x = param_3->x;
  (param_1->mPos).y = (float)dVar3;
  (param_1->mPos).z = fVar4;
  dTree_room_c::newData(this->mRoom + param_5,param_1);
  this->field_0x10 = (short)param_2;
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dTree_packet_c::newData(cXyz &,
                                      unsigned char,
                                      int) */

dTree_data_c * __thiscall
dTree_packet_c::newData(dTree_packet_c *this,cXyz *param_1,uchar param_2,int i_roomNo)

{
  bool bVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  dTree_data_c *pdVar6;
  
  bVar1 = false;
  if ((-1 < i_roomNo) && (i_roomNo < 0x40)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_tree.cpp",0x648,"0 <= i_roomNo && i_roomNo < 64");
    m_Do_printf::OSPanic("d_tree.cpp",0x648,&DAT_80352a7a);
  }
  uVar4 = (uint)(ushort)this->field_0x10;
  pdVar6 = this->mData + uVar4;
  iVar2 = 0x40 - uVar4;
  uVar5 = uVar4;
  if (uVar4 < 0x40) {
    do {
      if ((pdVar6->field_0x0 & 2) == 0) {
        setData(this,pdVar6,uVar5,param_1,param_2,i_roomNo);
        return pdVar6;
      }
      pdVar6 = pdVar6 + 1;
      uVar5 = uVar5 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  pdVar6 = this->mData;
  iVar2 = 0;
  while( true ) {
    if (uVar4 == 0) {
      return (dTree_data_c *)0x0;
    }
    if ((pdVar6->field_0x0 & 2) == 0) break;
    pdVar6 = pdVar6 + 1;
    iVar2 = iVar2 + 1;
    uVar4 = uVar4 - 1;
  }
  setData(this,pdVar6,iVar2,param_1,param_2,i_roomNo);
  return pdVar6;
}


/* __thiscall dTree_packet_c::newAnm(short) */

int __thiscall dTree_packet_c::newAnm(dTree_packet_c *this,short param_1)

{
  float fVar1;
  int iVar2;
  dTree_anm_c *pdVar3;
  int iVar4;
  
  pdVar3 = this->mAnm + 8;
  iVar2 = 8;
  iVar4 = 0x40;
  do {
    if (*(char *)pdVar3 == '\0') {
      *(char *)pdVar3 = '\x01';
      pdVar3->field_0x2 = param_1;
      *(short *)&pdVar3->field_0x6 = param_1;
      pdVar3->field_0x4 = 0;
      pdVar3->field_0x8 = 0;
      pdVar3->field_0xa = 0;
      fVar1 = d_tree::0_0;
      pdVar3->mAnimTimer = d_tree::0_0;
      pdVar3->field_0x10 = fVar1;
      pdVar3->field_0x14 = fVar1;
      pdVar3->field_0x18 = fVar1;
      pdVar3->field_0x1c = fVar1;
      pdVar3->field_0x20 = fVar1;
      return iVar2;
    }
    pdVar3 = pdVar3 + 1;
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return -1;
}


/* __thiscall dTree_packet_c::setAnm(int,
                                     short) */

void __thiscall dTree_packet_c::setAnm(dTree_packet_c *this,int param_1,short param_2)

{
  float fVar1;
  dTree_anm_c *pdVar2;
  
  pdVar2 = this->mAnm + param_1;
  *(undefined *)pdVar2 = 1;
  pdVar2->field_0x2 = param_2;
  *(short *)&pdVar2->field_0x6 = param_2;
  pdVar2->field_0x4 = 0;
  pdVar2->field_0x8 = 0;
  pdVar2->field_0xa = 0;
  fVar1 = d_tree::0_0;
  pdVar2->mAnimTimer = d_tree::0_0;
  pdVar2->field_0x10 = fVar1;
  pdVar2->field_0x14 = fVar1;
  pdVar2->field_0x18 = fVar1;
  pdVar2->field_0x1c = fVar1;
  pdVar2->field_0x20 = fVar1;
  return;
}


namespace d_tree {

void __sinit_d_tree_cpp(void)

{
  DAT_8037ad51 = 1;
  DAT_8037ad52 = 0xbc;
  DAT_8037ad53 = 0xe7;
  DAT_8037b071 = 1;
  DAT_8037b072 = 0xbd;
  DAT_8037b073 = 0x70;
  ::dPa_smokeEcallBack::dPa_smokeEcallBack
            ((dPa_smokeEcallBack *)&::dTree_data_c::mSmokeEcallback,'\x01','\x01','\0','\x01');
  Runtime.PPCEABI.H::__register_global_object();
  return;
}

}

/* __thiscall daPy_py_c::getSwordTopPos(void) const */

cXyz * __thiscall daPy_py_c::getSwordTopPos(cXyz *__return_storage_ptr__,daPy_py_c *this)

{
  __return_storage_ptr__->x = (this->mSwordTopPos).x;
  __return_storage_ptr__->y = (this->mSwordTopPos).y;
  __return_storage_ptr__->z = (this->mSwordTopPos).z;
  return __return_storage_ptr__;
}

