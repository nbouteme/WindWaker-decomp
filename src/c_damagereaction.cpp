#include <c_damagereaction.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_bg_s_acch.h>
#include <d_a_sea.h>
#include <d_particle.h>
#include <d_com_inf_game.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <SComponent/c_lib.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <f_op_actor_mng.h>
#include <d_save.h>
#include <d_cc_d.h>
#include <SComponent/c_m3d_g_cyl.h>
#include <SComponent/c_math.h>
#include <mtx/vec.h>
#include <c_damagereaction.h>
#include <SComponent/c_cc_s.h>
#include <d_cc_uty.h>
#include <SComponent/c_sxyz.h>
#include <JKernel/JKRHeap.h>
#include <d_kankyo.h>
#include <SComponent/c_xyz.h>
#include <SComponent/c_m3d_g_sph.h>
#include <SComponent/c_bg_s_lin_chk.h>
#include <d_bg_s_lin_chk.h>
#include <SComponent/c_bg_s.h>
#include <SComponent/c_bg_s_chk.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <d_bg_s.h>
#include <f_op_kankyo_mng.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dBgS_GrpPassChk.h>
#include <dBgS_Chk.h>
#include <dBgS_ObjGndChk.h>
#include <csXyz.h>
#include <cBgS_PolyPassChk.h>
#include <cBgS_GrpPassChk.h>
#include <cBgS_PolyInfo.h>
#include <dBgS_GndChk.h>
#include <dBgS_ObjGndChk_Spl.h>
#include <cBgS_GndChk.h>
#include <dBgS_ObjGndChk_Yogan.h>
#include <cBgS_LinChk.h>
#include <cM3dGLin.h>
#include <dBgS_LinChk.h>
#include <dBgS_PolyPassChk.h>


namespace c_damagereaction {
}

namespace c_damagereaction {
struct cXyz non_pos;
undefined1 test_sw;

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8001c094) */
/* __stdcall ice_bg_check(enemyice *) */

undefined4 ice_bg_check(enemyice *pIce)

{
  uint uVar1;
  fopAc_ac_c *pfVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  pfVar2 = pIce->mpActor;
  uVar3 = 0;
  dVar6 = (double)(pIce->field_0x18).y;
  dBgS_Acch::CrrPos(&pIce->mBgAcch,&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS);
  uVar1 = (pIce->mBgAcch).mFlags;
  if ((uVar1 & 0x800) == 0) {
    if ((uVar1 & 0x20) == 0) {
      uVar1 = d_a_sea::daSea_ChkArea((pfVar2->mCurrent).mPos.x,(pfVar2->mCurrent).mPos.z);
      if (((uVar1 & 0xff) != 0) &&
         (dVar5 = (double)d_a_sea::daSea_calcWave
                                    ((double)(pfVar2->mCurrent).mPos.x,
                                     (double)(pfVar2->mCurrent).mPos.z),
         (pfVar2->mCurrent).mPos.y < (float)((double)_4080 + dVar5))) {
        if ((double)_4081 <= dVar6) {
          (pIce->field_0x18).y = 0_0;
        }
        else {
          (pIce->field_0x18).y = 0_0;
        }
        if (pfVar2->mCurrHp < 1) {
          uVar3 = 1;
        }
      }
    }
    else {
      pIce->field_0x24 = pIce->field_0x24 * _4083;
      if ((pfVar2->mCurrHp < 1) ||
         (dVar6 < (double)(_4084 + d_s_play::g_regHIO.mChild[0].mFloats[14]))) {
        uVar3 = 1;
      }
      if ((double)_4081 <= dVar6) {
        (pIce->field_0x18).y = 0_0;
      }
      else {
        (pIce->field_0x18).y = 10_0;
      }
      pIce->field_0x14 = 0;
    }
  }
  else {
    if ((pfVar2->mCurrent).mPos.y < _4080 + (pIce->mBgAcch).mWtrChk.parent.mHeight) {
      if ((double)_4081 <= dVar6) {
        (pIce->field_0x18).y = 0_0;
      }
      else {
        (pIce->field_0x18).y = 0_0;
      }
      if (pfVar2->mCurrHp < 1) {
        uVar3 = 1;
      }
    }
  }
  if (((pIce->mBgAcch).mFlags & 0x10) != 0) {
    if (10_0 < ABS(pIce->field_0x24)) {
      uVar3 = 1;
    }
    pIce->field_0x24 = pIce->field_0x24 * _4083;
    pIce->field_0x12 = pIce->field_0x12 + -0x8000;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8001cd54) */
/* WARNING: Removing unreachable block (ram,0x8001cd5c) */
/* WARNING: Type propagation algorithm not settling */
/* __stdcall enemy_ice(enemyice *)
   
   This function handles the ice arrows frozen effect and the light arrows exploding into light
   effect on enemies.
   It also handles deleting the enemy actor when it's shattered/finishes exploding into light, and
   setting the appropriate flags for the enemy's death. */

int enemy_ice(enemyice *this)

{
  bool bVar1;
  byte bVar3;
  sbyte sVar7;
  int iVar4;
  int iVar5;
  short sVar6;
  cCcD_Obj__DamageTypes cVar8;
  uint uVar9;
  fopAc_ac_c *actor;
  undefined4 uVar10;
  double in_f30;
  double in_f31;
  float fVar11;
  csXyz cStack168;
  cXyz pos;
  cXyz particleScale;
  cXyz local_88;
  cXyz local_7c;
  cCcD_Obj *local_70;
  double local_50;
  undefined4 local_48;
  uint uStack68;
  undefined auStack24 [16];
  undefined auStack8 [8];
  bool bVar2;
  byte state;
  daPy_lk_c *player;
  
  player = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,SUB84(in_f31,0),0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,SUB84(in_f30,0),0);
  actor = this->mpActor;
  bVar1 = false;
  bVar3 = this->mNumFramesDyingToLightArrowsSoFar;
  if (bVar3 != 0) {
    particleScale.x = this->field_0x1ac;
    pos.x = (actor->mCurrent).mPos.x;
    pos.z = (actor->mCurrent).mPos.z;
    pos.y = (actor->mCurrent).mPos.y + this->mYOffset;
    particleScale.y = particleScale.x;
    particleScale.z = particleScale.x;
    if (bVar3 == 1) {
      this->mNumFramesDyingToLightArrowsSoFar = 2;
      dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x272,&pos,
                         (csXyz *)0x0,&particleScale,0xff,(dPa_levelEcallBack *)0x0,-1,
                         (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
      (actor->mTevStr).mFogColor.b = 0xff;
      (actor->mTevStr).mFogColor.g = 0xff;
      (actor->mTevStr).mFogColor.r = 0xff;
      (actor->mTevStr).mFogStartZ = 0_0;
      (actor->mTevStr).mFogEndZ = _4518;
      sVar7 = d_com_inf_game::dComIfGp_getReverb((int)(char)(actor->mCurrent).mRoomNo);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x5904,&actor->mEyePos,0,sVar7,1_0,1_0,_1_0,_1_0,0);
      actor->mAttentionFlags = actor->mAttentionFlags & ~LockOn_Enemy;
    }
    else {
      this->mNumFramesDyingToLightArrowsSoFar = bVar3 + 1;
      SComponent::cLib_addCalc2(&(actor->mTevStr).mFogEndZ,10_0,1_0,80_0);
      mtx::PSMTXTrans((double)(actor->mCurrent).mPos.x,(double)(actor->mCurrent).mPos.y,
                      (double)(actor->mCurrent).mPos.z,&mDoMtx_stack_c::now);
      mDoMtx_stack_c::transM(0_0,this->mYOffset,0_0);
      mDoMtx_stack_c::scaleM(this->mScaleXZ,this->mScaleY,this->mScaleXZ);
      mDoMtx_stack_c::transM(0_0,-this->mYOffset,0_0);
      m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,(actor->mCollisionRot).y);
      m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,(actor->mCollisionRot).x);
      m_Do_mtx::mDoMtx_ZrotM(&mDoMtx_stack_c::now,(actor->mCollisionRot).z);
      mDoMtx_stack_c::scaleM((actor->mScale).x,(actor->mScale).y,(actor->mScale).z);
      bVar3 = (char)d_s_play::g_regHIO.mChild[14].mShorts[1] + 0x46;
      if ((char)this->mNumFramesDyingToLightArrowsSoFar < (char)bVar3) {
        SComponent::cLib_addCalc0
                  (&this->mScaleXZ,0_1,0_01 + d_s_play::g_regHIO.mChild[14].mFloats[0]);
        SComponent::cLib_addCalc0
                  (&this->mScaleY,0_1,0_01 + d_s_play::g_regHIO.mChild[14].mFloats[0]);
      }
      else {
        if (this->mNumFramesDyingToLightArrowsSoFar == bVar3) {
          sVar7 = d_com_inf_game::dComIfGp_getReverb((int)(char)(actor->mCurrent).mRoomNo);
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x5905,&actor->mEyePos,0,sVar7,1_0,1_0,_1_0,_1_0,0);
        }
        SComponent::cLib_addCalc2
                  (&this->mScaleY,5_0 + d_s_play::g_regHIO.mChild[14].mFloats[1],0_1,
                   1_0 + d_s_play::g_regHIO.mChild[14].mFloats[2]);
        SComponent::cLib_addCalc0
                  (&this->mScaleXZ,0_1 + d_s_play::g_regHIO.mChild[14].mFloats[3],
                   0_05 + d_s_play::g_regHIO.mChild[14].mFloats[4]);
        if ((char)((char)d_s_play::g_regHIO.mChild[14].mShorts[2] + 'Z') <
            (char)this->mNumFramesDyingToLightArrowsSoFar) {
          f_op_actor_mng::fopAcM_delete((base_process_class *)actor);
          dSv_info_c::onActor(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,
                              (uint)(ushort)actor->mSetID,(int)(char)(actor->mOrig).mRoomNo);
          if ((actor->parent).parent.mProcName != 0xd3) {
            f_op_actor_mng::fopAcM_createIball
                      (&pos,actor->mItemTableIdx,(int)(char)(actor->mCurrent).mRoomNo,
                       &(actor->mCurrent).mRot,(uint)actor->mItemStealNum);
          }
          if (this->mDeathSwitch != 0) {
            dSv_info_c::onSwitch
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,(uint)this->mDeathSwitch,
                       (int)(char)(actor->mCurrent).mRoomNo);
          }
          actor->mCurrHp = -0x80;
        }
      }
    }
    iVar4 = 1;
    goto LAB_8001cd54;
  }
  iVar4 = 0;
  bVar2 = false;
  state = this->mState;
  if (state == 2) {
LAB_8001c658:
    iVar4 = 1;
    bVar2 = true;
    if (this->field_0xc != 1) {
      actor->mAttentionFlags = actor->mAttentionFlags | Action_Carry;
      actor->mAttentionDistances[4] = 0x12;
      if ((actor->mStatus & IsBeingCarried) != 0) {
        actor->mAttentionFlags = actor->mAttentionFlags & ~Action_Carry;
        this->mState = 3;
        if (this->field_0xc == 2) {
          this->field_0xc = 0;
        }
      }
    }
  }
  else {
    if ((char)state < '\x02') {
      if (state == 0) {
        ::dCcD_Stts::Init(&this->mStts,0xfa,0xff,actor);
        ::dCcD_Cyl::Set(&this->mCyl,&cc_cyl_src);
        (this->mCyl).parent.parent.parent.mpStts = &this->mStts;
        ::cM3dGCyl::SetR(&(this->mCyl).mCylAttr.mCyl,this->mWallRadius);
        ::cM3dGCyl::SetH(&(this->mCyl).mCylAttr.mCyl,this->mCylHeight);
        dBgS_Acch::Set(&this->mBgAcch,&(actor->mCurrent).mPos,&(actor->mNext).mPos,actor,1,
                       &this->mBgAcchCir,&this->field_0x18,(csXyz *)0x0,(csXyz *)0x0);
        ::dBgS_AcchCir::SetWall(&this->mBgAcchCir,40_0,this->mWallRadius);
        if (this->field_0x1ac < 0_1) {
          this->field_0x1ac = 1_0;
        }
        if (ABS(this->mYOffset) < 0_1) {
          this->mYOffset = 80_0;
        }
        this->mState = 1;
        fVar11 = 1_0;
        this->mScaleY = 1_0;
        this->mScaleXZ = fVar11;
        actor->mStatus = actor->mStatus | 0x8000000;
      }
      else {
        if (-1 < (char)state) {
          if (this->mTotalNumFramesToRemainFrozen == 0) {
            iVar4 = 0;
            goto LAB_8001cd54;
          }
          this->mNumFramesLeftToRemainFrozen = this->mTotalNumFramesToRemainFrozen;
          this->mTotalNumFramesToRemainFrozen = 0;
          this->mState = 2;
          if (this->field_0xc == 0) {
            (this->field_0x18).y = 30_0;
            fVar11 = SComponent::cM_rndFX(3000_0);
            local_50 = (double)(longlong)(int)fVar11;
            this->field_0x14 = (short)(int)fVar11;
          }
          actor->mCurrHp = actor->mCurrHp + -4;
          if (actor->mCurrHp < 1) {
            this->field_0x10 = 0x28;
            (this->field_0x18).y = 0_0;
          }
          sVar7 = d_com_inf_game::dComIfGp_getReverb((int)(char)(actor->mCurrent).mRoomNo);
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x58fa,&actor->mEyePos,0,sVar7,1_0,1_0,_1_0,_1_0,0);
          particleScale.x = this->field_0x1ac;
          pos.x = (actor->mCurrent).mPos.x;
          pos.z = (actor->mCurrent).mPos.z;
          pos.y = (actor->mCurrent).mPos.y + this->mYOffset;
          particleScale.y = particleScale.x;
          particleScale.z = particleScale.x;
          dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x274,&pos,
                             (csXyz *)0x0,&particleScale,0xff,(dPa_levelEcallBack *)0x0,-1,
                             (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
          goto LAB_8001c658;
        }
      }
    }
    else {
      if (((char)state < '\x04') && (iVar4 = 1, (actor->mStatus & IsBeingCarried) == 0)) {
        if (actor->mVelocityFwd <= 0_0) {
          this->field_0x24 = 5_0;
          (this->field_0x18).y = _15_0;
        }
        else {
          this->field_0x24 = 25_0 + d_s_play::g_regHIO.mChild[0].mFloats[5];
          (this->field_0x18).y = 20_0 + d_s_play::g_regHIO.mChild[0].mFloats[6];
        }
        this->field_0x12 = (player->parent).parent.mCollisionRot.y;
        this->mState = 2;
      }
    }
  }
  if (bVar2) {
    if (this->field_0x10 == 0) {
      m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)this->field_0x12);
      local_7c.x = 0_0;
      local_7c.y = 0_0;
      local_7c.z = this->field_0x24;
      SComponent::MtxPosition(&local_7c,&local_88);
      (this->field_0x18).x = local_88.x;
      (this->field_0x18).z = local_88.z;
      if (this->field_0xc == 2) {
        (this->field_0x18).y = 0_0;
      }
      else {
        mtx::PSVECAdd(&(actor->mCurrent).mPos,&this->field_0x18,&(actor->mCurrent).mPos);
        (this->field_0x18).y = (this->field_0x18).y - 5_0;
      }
      (actor->mCollisionRot).y = (actor->mCollisionRot).y + this->field_0x14;
      iVar5 = ice_bg_check(this);
      if (iVar5 != 0) {
        this->mNumFramesLeftToRemainFrozen = -1;
      }
    }
    else {
      this->field_0x10 = this->field_0x10 + -1;
    }
    if (&this->mStts != (dCcD_Stts *)0x0) {
      mtx::PSVECAdd(&(actor->mCurrent).mPos,(cXyz *)&this->mStts,&(actor->mCurrent).mPos);
    }
    if (ABS(this->field_0x24) <= 5_0) {
      (this->mCyl).parent.parent.parent.parent.mObjAt.parent.mCommonFlag =
           (this->mCyl).parent.parent.parent.parent.mObjAt.parent.mCommonFlag & 0xfffffffe;
    }
    else {
      (this->mCyl).parent.parent.parent.parent.mObjAt.parent.mCommonFlag =
           (this->mCyl).parent.parent.parent.parent.mObjAt.parent.mCommonFlag | 1;
    }
    ::cM3dGCyl::SetC(&(this->mCyl).mCylAttr.mCyl,&(actor->mCurrent).mPos);
    cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)&this->mCyl);
    if ((0x16 < this->mNumFramesLeftToRemainFrozen) &&
       (iVar5 = dCcD_GObjInf::ChkTgHit(&(this->mCyl).parent), iVar5 != 0)) {
      local_70 = dCcD_GObjInf::GetTgHitObj(&(this->mCyl).parent);
      cVar8 = (local_70->parent).mObjAt.mDamageTypes;
      if ((cVar8 & LightArrow) == 0) {
        if ((cVar8 & Fire) == 0) {
          if ((cVar8 & (Bomb|SkullHammer|FireArrows)) == 0) {
            d_cc_uty::def_se_set(actor,local_70,0x42);
          }
          else {
            if ((cVar8 & SkullHammer) == 0) {
              this->mNumFramesLeftToRemainFrozen = -1;
            }
            else {
              this->mNumFramesLeftToRemainFrozen = -2;
            }
          }
        }
        else {
          this->mNumFramesLeftToRemainFrozen = 1;
        }
      }
      else {
        this->mNumFramesLeftToRemainFrozen = 1;
        this->mNumFramesDyingToLightArrowsSoFar = 1;
      }
    }
  }
  if (iVar4 == 0) {
    actor->mStatus = actor->mStatus & ~Frozen;
    SComponent::cLib_addCalc0(&this->field_0x28,1_0,_4533);
  }
  else {
    sVar6 = this->mNumFramesLeftToRemainFrozen;
    if (sVar6 != 0) {
      if (sVar6 < 0) {
        particleScale.x = this->field_0x1ac;
        pos.x = (actor->mCurrent).mPos.x;
        pos.z = (actor->mCurrent).mPos.z;
        pos.y = (actor->mCurrent).mPos.y + this->mYOffset;
        particleScale.y = particleScale.x;
        particleScale.z = particleScale.x;
        dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x273,&pos,
                           (csXyz *)0x0,&particleScale,0xff,(dPa_levelEcallBack *)0x0,-1,
                           (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
        dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x274,&pos,
                           (csXyz *)0x0,&particleScale,0xff,(dPa_levelEcallBack *)0x0,-1,
                           (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
        if (this->mNumFramesLeftToRemainFrozen == -2) {
          dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x10,&pos,
                             (csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1,
                             (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
          sVar6 = f_op_actor_mng::fopAcM_searchActorAngleY
                            (actor,(fopAc_ac_c *)
                                   d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor);
          ::csXyz::csXyz(&cStack168,0,sVar6,0);
          particleScale.x = _4532;
          particleScale.y = _4532;
          particleScale.z = _4532;
          dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0xd,&pos,
                             &cStack168,&particleScale,0xff,(dPa_levelEcallBack *)0x0,-1,
                             (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
          dScnPly_ply_c::nextPauseTimer = 8;
        }
        sVar7 = d_com_inf_game::dComIfGp_getReverb((int)(char)(actor->mCurrent).mRoomNo);
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x5902,&actor->mEyePos,0,sVar7,1_0,1_0,_1_0,_1_0,0);
        f_op_actor_mng::fopAcM_createIball
                  (&pos,actor->mItemTableIdx,(int)(char)(actor->mCurrent).mRoomNo,
                   &(actor->mCurrent).mRot,(uint)actor->mItemStealNum);
        this->mNumFramesLeftToRemainFrozen = 0;
        if (this->mDeathSwitch != 0) {
          dSv_info_c::onSwitch
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,(uint)this->mDeathSwitch,
                     (int)(char)(actor->mCurrent).mRoomNo);
        }
        bVar1 = true;
      }
      else {
        this->mNumFramesLeftToRemainFrozen = sVar6 + -1;
      }
      if (this->mNumFramesLeftToRemainFrozen == 0) {
        this->mState = 1;
        ::cM3dGCyl::SetC(&(this->mCyl).mCylAttr.mCyl,&non_pos);
        cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)&this->mCyl);
        if ((actor->mStatus & IsBeingCarried) != 0) {
          f_op_actor_mng::fopAcM_cancelCarryNow(actor);
        }
        if (bVar1) {
          f_op_actor_mng::fopAcM_delete((base_process_class *)actor);
          dSv_info_c::onActor(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,
                              (uint)(ushort)actor->mSetID,(int)(char)(actor->mOrig).mRoomNo);
          actor->mCurrHp = -0x80;
        }
        else {
          iVar4 = 0;
        }
      }
      uVar9 = SEXT24(this->mNumFramesLeftToRemainFrozen);
      if ((int)uVar9 < 0x32) {
        local_50 = (double)CONCAT44(0x43300000,(uVar9 & 1) * 2 - 1 ^ 0x80000000);
        uStack68 = ((uVar9 + 1) * 2 & 2) - 1 ^ 0x80000000;
        local_48 = 0x43300000;
        in_f30 = (double)(float)((double)CONCAT44(0x43300000,uStack68) - _4535);
        in_f31 = (double)(float)(local_50 - _4535);
      }
      else {
        in_f30 = (double)0_0;
        in_f31 = in_f30;
      }
      if (uVar9 == 0x14) {
        particleScale.x = this->field_0x1ac;
        pos.x = (actor->mCurrent).mPos.x;
        pos.z = (actor->mCurrent).mPos.z;
        pos.y = (actor->mCurrent).mPos.y + this->mYOffset;
        particleScale.y = particleScale.x;
        particleScale.z = particleScale.x;
        dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x277,&pos,
                           (csXyz *)0x0,&particleScale,0xff,(dPa_levelEcallBack *)0x0,-1,
                           (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
        sVar7 = d_com_inf_game::dComIfGp_getReverb((int)(char)(actor->mCurrent).mRoomNo);
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x5903,&actor->mEyePos,0,sVar7,1_0,1_0,_1_0,_1_0,0);
      }
    }
    (actor->mCurrent).mRot.x = (actor->mCollisionRot).x;
    (actor->mCurrent).mRot.y = (actor->mCollisionRot).y;
    (actor->mCurrent).mRot.z = (actor->mCollisionRot).z;
    SComponent::cLib_addCalc2(&this->field_0x28,this->field_0x2c,1_0,_4533);
    mtx::PSMTXTrans((double)(float)((double)(actor->mCurrent).mPos.x + in_f31),
                    (double)((actor->mCurrent).mPos.y + this->field_0x2c),
                    (double)(float)((double)(actor->mCurrent).mPos.z + in_f30),&mDoMtx_stack_c::now)
    ;
    m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,(actor->mCollisionRot).y);
    m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,(actor->mCollisionRot).x);
    m_Do_mtx::mDoMtx_ZrotM(&mDoMtx_stack_c::now,(actor->mCollisionRot).z);
    mDoMtx_stack_c::scaleM((actor->mScale).x,(actor->mScale).y,(actor->mScale).z);
    actor->mStatus = actor->mStatus | Frozen;
  }
LAB_8001cd54:
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  __psq_l0(auStack24,uVar10);
  __psq_l1(auStack24,uVar10);
  return iVar4;
}

}

/* __thiscall csXyz::~csXyz(void) */

void __thiscall csXyz::_csXyz(csXyz *this)

{
  short in_r4;
  
  if ((this != (csXyz *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace c_damagereaction {

/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x8001d388) */
/* WARNING: Removing unreachable block (ram,0x8001d378) */
/* WARNING: Removing unreachable block (ram,0x8001d380) */
/* WARNING: Removing unreachable block (ram,0x8001d390) */
/* __stdcall enemy_fire(enemyfire *) */

void enemy_fire(enemyfire *this)

{
  float fVar1;
  short sVar2;
  JPABaseEmitter *pJVar3;
  sbyte sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  byte bVar9;
  fopAc_ac_c *pActor;
  int iVar10;
  undefined4 uVar11;
  double dVar12;
  undefined8 in_f28;
  double dVar13;
  undefined8 in_f29;
  double dVar14;
  undefined8 in_f30;
  double dVar15;
  undefined8 in_f31;
  double dVar16;
  float fVar17;
  cXyz local_a4;
  cXyz local_98;
  cXyz local_8c;
  cXyz local_80;
  longlong local_70;
  undefined4 local_68;
  uint uStack100;
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
  pActor = this->mpActor;
  local_80.x = 0_0;
  local_80.y = 0_0;
  local_80.z = 0_0;
  bVar9 = this->field_0x6;
  if (bVar9 == 1) {
    (this->mLight).mPos.x = (pActor->mCurrent).mPos.x;
    (this->mLight).mPos.y = (pActor->mCurrent).mPos.y;
    (this->mLight).mPos.z = (pActor->mCurrent).mPos.z;
    (this->mLight).mColor.r = 600;
    (this->mLight).mColor.g = 400;
    (this->mLight).mColor.b = 0x78;
    iVar6 = (int)(_4748 * this->field_0x98);
    local_70 = (longlong)iVar6;
    uStack100 = (int)(short)iVar6 ^ 0x80000000;
    local_68 = 0x43300000;
    (this->mLight).mPower = (float)((double)CONCAT44(0x43300000,uStack100) - _4535);
    (this->mLight).mFluctuation = _4749;
    ::cXyz::operator__(&local_a4,&(pActor->mCurrent).mPos,&this->field_0x80);
    dVar16 = (double)local_a4.x;
    dVar15 = (double)local_a4.y;
    dVar14 = (double)local_a4.z;
    (this->field_0x80).x = (pActor->mCurrent).mPos.x;
    (this->field_0x80).y = (pActor->mCurrent).mPos.y;
    (this->field_0x80).z = (pActor->mCurrent).mPos.z;
    fVar17 = (float)(dVar16 * (double)(_4750 + d_s_play::g_regHIO.mChild[0].mFloats[4]));
    fVar1 = 1_0;
    if ((fVar17 <= 1_0) && (fVar1 = fVar17, fVar17 < _1_0)) {
      fVar1 = _1_0;
    }
    dVar13 = (double)(float)(dVar14 * (double)(_4750 + d_s_play::g_regHIO.mChild[0].mFloats[4]));
    dVar12 = (double)1_0;
    if ((dVar13 <= dVar12) && (dVar12 = dVar13, dVar13 < (double)_1_0)) {
      dVar12 = (double)_1_0;
    }
    SComponent::cLib_addCalc2(&this->field_0x8c,fVar1,_4083,0_05);
    SComponent::cLib_addCalc2(&this->field_0x94,(float)dVar12,_4083,0_05);
    this->field_0x90 = _4751 + d_s_play::g_regHIO.mChild[0].mFloats[11];
    dVar14 = (double)((float)(dVar14 * dVar14) + (float)(dVar16 * dVar16) + (float)(dVar15 * dVar15)
                     );
    if ((double)0_0 < dVar14) {
      dVar15 = 1.0 / SQRT(dVar14);
      dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
      dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
      dVar14 = (double)(float)(dVar14 * _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15));
    }
    fVar17 = 1_0 + (float)((double)(_4754 + d_s_play::g_regHIO.mChild[0].mFloats[12]) * dVar14);
    if (_4755 + d_s_play::g_regHIO.mChild[0].mFloats[13] < fVar17) {
      fVar17 = _4755 + d_s_play::g_regHIO.mChild[0].mFloats[13];
    }
    SComponent::cLib_addCalc2(&this->field_0x98,fVar17,_4083,0_05);
    bVar9 = 0;
    iVar10 = 0;
    iVar7 = 0;
    iVar6 = 0;
    do {
      if (-1 < (char)this->field_0x10[iVar10]) {
        pbVar8 = this->field_0x10 + iVar6 + -0x10;
        iVar5 = *(int *)(pbVar8 + 0x58);
        if (iVar5 != 0) {
          sVar2 = *(short *)((int)this->field_0x1c + iVar7 + 0x28);
          if (sVar2 == 0) {
            *(undefined4 *)(iVar5 + 0x60) = 0xffffffff;
            *(uint *)(iVar5 + 0x20c) = *(uint *)(iVar5 + 0x20c) | 1;
            *(undefined4 *)(pbVar8 + 0x58) = 0;
          }
          else {
            *(short *)((int)this->field_0x1c + iVar7 + 0x28) = sVar2 + -1;
            mtx::PSMTXCopy(this->mpMcaMorf->mpModel->mpNodeMtx + (char)this->field_0x10[iVar10],
                           SComponent::calc_mtx);
            SComponent::MtxPosition(&local_80,&local_8c);
            iVar5 = *(int *)(pbVar8 + 0x58);
            *(float *)(iVar5 + 0x1e4) = local_8c.x;
            *(float *)(iVar5 + 0x1e8) = local_8c.y;
            *(float *)(iVar5 + 0x1ec) = local_8c.z;
            iVar5 = *(int *)(pbVar8 + 0x58);
            *(float *)(iVar5 + 0x2c) = this->field_0x8c;
            *(float *)(iVar5 + 0x30) = this->field_0x90;
            *(float *)(iVar5 + 0x34) = this->field_0x94;
            fVar17 = *(float *)(pbVar8 + 0x1c);
            fVar1 = this->field_0x98;
            iVar5 = *(int *)(pbVar8 + 0x58);
            *(float *)(iVar5 + 0x1f0) = fVar17;
            *(float *)(iVar5 + 500) = fVar1 * fVar17;
            *(float *)(iVar5 + 0x1f8) = fVar17;
            if (this->field_0x9d == bVar9) {
              ::cM3dGSph::SetC(&(this->mSph).mSphAttr.mSph,&local_8c);
              cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,
                        (cCcD_Obj *)&this->mSph);
            }
            bVar9 = bVar9 + 1;
          }
        }
      }
      iVar10 = iVar10 + 1;
      iVar7 = iVar7 + 2;
      iVar6 = iVar6 + 4;
    } while (iVar10 < 10);
    this->field_0x9d = this->field_0x9d + '\x01';
    if (bVar9 <= (byte)this->field_0x9d) {
      this->field_0x9d = '\0';
    }
    sVar4 = d_com_inf_game::dComIfGp_getReverb((int)(char)(pActor->mCurrent).mRoomNo);
    JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x6103,&pActor->mEyePos,0,sVar4,1_0,1_0,_1_0,_1_0,0)
    ;
    if (this->field_0x8 == 0) {
      this->field_0x6 = 0;
      d_kankyo::dKy_plight_cut(&this->mLight);
      ::cM3dGSph::SetC(&(this->mSph).mSphAttr.mSph,&non_pos);
      cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)&this->mSph);
    }
    else {
      sVar4 = d_com_inf_game::dComIfGp_getReverb((int)(char)(pActor->mCurrent).mRoomNo);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x5101,&pActor->mEyePos,0,sVar4,1_0,1_0,_1_0,_1_0,0);
    }
    if (this->field_0x8 != 0) {
      this->field_0x8 = this->field_0x8 + -1;
    }
  }
  else {
    if ((((char)bVar9 < '\x01') && (-1 < (char)bVar9)) && (this->field_0x4 != 0)) {
      this->field_0x8 = this->field_0x4;
      this->field_0x4 = 0;
      this->field_0x6 = 1;
      d_kankyo::dKy_plight_set(&this->mLight);
      iVar10 = 0;
      iVar6 = 0;
      iVar7 = 0;
      do {
        if ((-1 < (char)this->field_0x10[iVar10]) &&
           (pbVar8 = this->field_0x10 + iVar7 + -0x10, *(int *)(pbVar8 + 0x58) == 0)) {
          local_98.x = *(float *)(pbVar8 + 0x1c);
          local_98.y = local_98.x;
          local_98.z = local_98.x;
          pJVar3 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x3f1
                                      ,&(pActor->mCurrent).mPos,(csXyz *)0x0,&local_98,0xff,
                                      (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                                      (cXyz *)0x0);
          *(JPABaseEmitter **)(pbVar8 + 0x58) = pJVar3;
          fVar17 = SComponent::cM_rndF(_4747);
          local_70 = (longlong)(int)fVar17;
          *(short *)((int)this->field_0x1c + iVar6 + 0x28) = this->field_0x8 - (short)(int)fVar17;
          if (*(short *)((int)this->field_0x1c + iVar6 + 0x28) < 10) {
            *(undefined2 *)((int)this->field_0x1c + iVar6 + 0x28) = 10;
          }
          this->field_0x98 = _4532;
        }
        iVar10 = iVar10 + 1;
        iVar6 = iVar6 + 2;
        iVar7 = iVar7 + 4;
      } while (iVar10 < 10);
      ::dCcD_Stts::Init(&this->mStts,0xfa,0xff,pActor);
      ::dCcD_Sph::Set(&this->mSph,&fire_at_sph_src);
      (this->mSph).parent.parent.parent.mpStts = &this->mStts;
    }
  }
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  __psq_l0(auStack24,uVar11);
  __psq_l1(auStack24,uVar11);
  __psq_l0(auStack40,uVar11);
  __psq_l1(auStack40,uVar11);
  __psq_l0(auStack56,uVar11);
  __psq_l1(auStack56,uVar11);
  return;
}


/* __stdcall enemy_fire_remove(enemyfire *) */

void enemy_fire_remove(enemyfire *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  this->field_0x6 = 0;
  d_kankyo::dKy_plight_cut(&this->mLight);
  iVar1 = 0;
  iVar3 = 10;
  do {
    iVar2 = *(int *)((int)this->field_0x1c + iVar1 + 0x3c);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x60) = 0xffffffff;
      *(uint *)(iVar2 + 0x20c) = *(uint *)(iVar2 + 0x20c) | 1;
      *(undefined4 *)((int)this->field_0x1c + iVar1 + 0x3c) = 0;
    }
    iVar1 = iVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


/* __stdcall enemy_piyo_set(fopAc_ac_c *) */

void enemy_piyo_set(fopAc_ac_c *pActor)

{
  dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x27a,
                     &pActor->mAttentionPos,(csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,
                     -1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
  return;
}


/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* WARNING: Removing unreachable block (ram,0x8001d870) */
/* __stdcall wall_angle_get(fopAc_ac_c *,
                            short) */

int wall_angle_get(fopAc_ac_c *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  cXyz *pDst;
  int iVar3;
  cBgS_PolyPassChk *pcVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  cXyz local_f8;
  cXyz cStack236;
  cXyz local_e0;
  cXyz local_d4 [2];
  undefined auStack188 [104];
  uint local_54;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  auStack188._0_4_ = (cBgS_PolyPassChk *)0x0;
  auStack188._4_4_ = (cBgS_PolyPassChk *)0x0;
  auStack188[12] = true;
  auStack188._20_2_ = -1;
  auStack188._22_2_ = 0x100;
  auStack188._24_4_ = (cBgW *)0x0;
  auStack188._28_4_ = -1;
  auStack188._16_4_ = &::cBgS_LinChk::__vt;
  auStack188._32_4_ = &PTR_80371fbc;
  auStack188._60_4_ = &::cM3dGLin::__vt;
  ::cBgS_LinChk::ct((cBgS_LinChk *)auStack188);
  pcVar4 = (cBgS_PolyPassChk *)(auStack188 + 0x58);
  auStack188[92] = 0;
  auStack188[93] = 0;
  auStack188[94] = 0;
  auStack188[95] = 0;
  auStack188[96] = 0;
  auStack188[97] = 0;
  auStack188[98] = 0;
  local_54 = 1;
  auStack188._16_4_ = &::dBgS_LinChk::__vt;
  auStack188._32_4_ = (undefined **)&DAT_80371f38;
  auStack188._88_4_ = &PTR_80371f44;
  auStack188._100_4_ = &PTR_80371f50;
  auStack188._4_4_ = pcVar4;
  if (pcVar4 != (cBgS_PolyPassChk *)0x0) {
    auStack188._4_4_ = (cBgS_PolyPassChk *)(auStack188 + 100);
  }
  auStack188._0_4_ = pcVar4;
  m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,param_2);
  local_e0.x = 0_0;
  local_e0.y = 0_0;
  local_e0.z = _4080;
  SComponent::MtxPosition(&local_e0,&cStack236);
  mtx::PSVECAdd(&cStack236,&(param_1->mCurrent).mPos,&cStack236);
  local_e0.x = 10_0;
  local_e0.y = 0_0;
  local_e0.z = _4922;
  iVar2 = 0;
  iVar3 = 0;
  dVar6 = (double)_1_0;
  do {
    pDst = (cXyz *)((int)&local_d4[0].x + iVar3);
    SComponent::MtxPosition(&local_e0,pDst);
    local_e0.x = (float)((double)local_e0.x * dVar6);
    mtx::PSVECAdd(pDst,&cStack236,pDst);
    ::dBgS_LinChk::Set((dBgS_LinChk *)auStack188,&cStack236,pDst,param_1);
    cVar1 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                            (cBgS_LinChk *)auStack188);
    if (cVar1 == '\0') {
      auStack188._88_4_ = &PTR_80371f44;
      auStack188._100_4_ = &PTR_80371f50;
      if (pcVar4 != (cBgS_PolyPassChk *)0x0) {
        auStack188._88_4_ = &::dBgS_Chk::__vt;
        auStack188._100_4_ = &PTR_80371f68;
        if (((undefined *)register0x00000004 != (undefined *)0x58) &&
           (auStack188._100_4_ = &::dBgS_GrpPassChk::__vt,
           (undefined *)register0x00000004 != (undefined *)0x58)) {
          auStack188._100_4_ = &::cBgS_GrpPassChk::__vt;
        }
        if ((pcVar4 != (cBgS_PolyPassChk *)0x0) &&
           (auStack188._88_4_ = &::dBgS_PolyPassChk::__vt, pcVar4 != (cBgS_PolyPassChk *)0x0)) {
          auStack188._88_4_ = &::cBgS_PolyPassChk::__vt;
        }
      }
      auStack188._16_4_ = &::cBgS_LinChk::__vt;
      if ((undefined *)register0x00000004 != (undefined *)0x98) {
        auStack188._60_4_ = &::cM3dGLin::__vt;
      }
      auStack188._32_4_ = &::cBgS_PolyInfo::__vt;
      cBgS_Chk::_cBgS_Chk((cBgS_Chk *)auStack188);
      iVar2 = 1;
      goto LAB_8001d870;
    }
    pDst->x = auStack188._48_4_;
    *(float *)((int)&local_d4[0].y + iVar3) = auStack188._52_4_;
    *(float *)((int)&local_d4[0].z + iVar3) = auStack188._56_4_;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0xc;
  } while (iVar2 < 2);
  ::cXyz::operator__(&local_f8,local_d4 + 1,local_d4);
  local_e0.x = local_f8.x;
  local_e0.y = local_f8.y;
  local_e0.z = local_f8.z;
  iVar2 = SComponent::cM_atan2s(local_f8.x,local_f8.z);
  iVar2 = (int)(short)((short)iVar2 + 0x4000);
  auStack188._88_4_ = &PTR_80371f44;
  auStack188._100_4_ = &PTR_80371f50;
  if (pcVar4 != (cBgS_PolyPassChk *)0x0) {
    auStack188._88_4_ = &::dBgS_Chk::__vt;
    auStack188._100_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x58) &&
       (auStack188._100_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x58)) {
      auStack188._100_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar4 != (cBgS_PolyPassChk *)0x0) &&
       (auStack188._88_4_ = &::dBgS_PolyPassChk::__vt, pcVar4 != (cBgS_PolyPassChk *)0x0)) {
      auStack188._88_4_ = &::cBgS_PolyPassChk::__vt;
    }
  }
  auStack188._16_4_ = &::cBgS_LinChk::__vt;
  if ((undefined *)register0x00000004 != (undefined *)0x98) {
    auStack188._60_4_ = &::cM3dGLin::__vt;
  }
  auStack188._32_4_ = &::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk((cBgS_Chk *)auStack188);
LAB_8001d870:
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return iVar2;
}

}

/* __thiscall dBgS_LinChk::~dBgS_LinChk(void) */

void __thiscall dBgS_LinChk::_dBgS_LinChk(dBgS_LinChk *this)

{
  short in_r4;
  
  if (this != (dBgS_LinChk *)0x0) {
    (this->parent).parent.vtbl = (cBgS_Chk__vtbl *)&__vt;
    (this->parent).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_80371f38;
    (this->mPolyPassChk).parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f44;
    (this->mGrpPassChk).parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f50;
    if (this != (dBgS_LinChk *)0xffffffa8) {
      (this->mPolyPassChk).parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      (this->mGrpPassChk).parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
      if (this != (dBgS_LinChk *)0xffffff9c) {
        (this->mGrpPassChk).parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt;
        if (this != (dBgS_LinChk *)0xffffff9c) {
          (this->mGrpPassChk).parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
        }
      }
      if ((this != (dBgS_LinChk *)0xffffffa8) &&
         ((this->mPolyPassChk).parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         this != (dBgS_LinChk *)0xffffffa8)) {
        (this->mPolyPassChk).parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    if (this != (dBgS_LinChk *)0x0) {
      (this->parent).parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
      (this->parent).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371fbc;
      if (this != (dBgS_LinChk *)0xffffffdc) {
        (this->parent).mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
      }
      if (this != (dBgS_LinChk *)0xffffffec) {
        (this->parent).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
      }
      cBgS_Chk::_cBgS_Chk((cBgS_Chk *)this);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dBgS_Chk::~dBgS_Chk(void) */

void __thiscall dBgS_Chk::_dBgS_Chk(dBgS_Chk *this)

{
  short in_r4;
  
  if (this != (dBgS_Chk *)0x0) {
    (this->mPolyPassChk).parent.vtbl = (cBgS_PolyPassChk__vtbl *)&__vt;
    (this->mGrpPassChk).parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
    if ((this != (dBgS_Chk *)0xfffffff4) &&
       ((this->mGrpPassChk).parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
       this != (dBgS_Chk *)0xfffffff4)) {
      (this->mGrpPassChk).parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
    }
    if ((this != (dBgS_Chk *)0x0) &&
       ((this->mPolyPassChk).parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       this != (dBgS_Chk *)0x0)) {
      (this->mPolyPassChk).parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dBgS_GrpPassChk::~dBgS_GrpPassChk(void) */

void __thiscall dBgS_GrpPassChk::_dBgS_GrpPassChk(dBgS_GrpPassChk *this)

{
  short in_r4;
  
  if (this != (dBgS_GrpPassChk *)0x0) {
    (this->parent).vtbl = (cBgS_GrpPassChk__vtbl *)&__vt;
    if (this != (dBgS_GrpPassChk *)0x0) {
      (this->parent).vtbl = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cBgS_GrpPassChk::~cBgS_GrpPassChk(void) */

void __thiscall cBgS_GrpPassChk::_cBgS_GrpPassChk(cBgS_GrpPassChk *this)

{
  short in_r4;
  
  if ((this != (cBgS_GrpPassChk *)0x0) && (this->vtbl = (cBgS_GrpPassChk__vtbl *)&__vt, 0 < in_r4))
  {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dBgS_PolyPassChk::~dBgS_PolyPassChk(void) */

void __thiscall dBgS_PolyPassChk::_dBgS_PolyPassChk(dBgS_PolyPassChk *this)

{
  short in_r4;
  
  if (this != (dBgS_PolyPassChk *)0x0) {
    (this->parent).vtbl = (cBgS_PolyPassChk__vtbl *)&__vt;
    if (this != (dBgS_PolyPassChk *)0x0) {
      (this->parent).vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cBgS_PolyPassChk::~cBgS_PolyPassChk(void) */

void __thiscall cBgS_PolyPassChk::_cBgS_PolyPassChk(cBgS_PolyPassChk *this)

{
  short in_r4;
  
  if ((this != (cBgS_PolyPassChk *)0x0) && (this->vtbl = (cBgS_PolyPassChk__vtbl *)&__vt, 0 < in_r4)
     ) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall cBgS_LinChk::~cBgS_LinChk(void) */

void __thiscall cBgS_LinChk::_cBgS_LinChk(cBgS_LinChk *this)

{
  short in_r4;
  
  if (this != (cBgS_LinChk *)0x0) {
    (this->parent).vtbl = (cBgS_Chk__vtbl *)&__vt;
    (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371fbc;
    if (this != (cBgS_LinChk *)0xffffffdc) {
      (this->mLin).vtbl = (undefined *)&::cM3dGLin::__vt;
    }
    if (this != (cBgS_LinChk *)0xffffffec) {
      (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    }
    cBgS_Chk::_cBgS_Chk(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cM3dGLin::~cM3dGLin(void) */

void __thiscall cM3dGLin::_cM3dGLin(cM3dGLin *this)

{
  short in_r4;
  
  if ((this != (cM3dGLin *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall cBgS_PolyInfo::~cBgS_PolyInfo(void) */

void __thiscall cBgS_PolyInfo::_cBgS_PolyInfo(cBgS_PolyInfo *this)

{
  short in_r4;
  
  if ((this != (cBgS_PolyInfo *)0x0) && (this->vtbl = (cBgS_PolyInfo__vtbl *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace c_damagereaction {

/* WARNING: Inlined function: FUN_80328f14 */
/* WARNING: Inlined function: FUN_80328f60 */
/* WARNING: Removing unreachable block (ram,0x8001e21c) */
/* WARNING: Removing unreachable block (ram,0x8001e214) */
/* WARNING: Removing unreachable block (ram,0x8001e224) */
/* __stdcall dr_body_bg_check(damagereaction *) */

void dr_body_bg_check(damagereaction *this)

{
  float fVar1;
  fopEn_enemy_c *pfVar2;
  int iVar3;
  uint uVar4;
  sbyte sVar5;
  cBgS_PolyPassChk *pcVar6;
  undefined4 uVar7;
  undefined8 in_f29;
  double dVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  cBgS_GndChk local_c4;
  cBgS_PolyPassChk local_84;
  undefined local_78 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  fVar1 = 0_0;
  if (this->field_0x488 == 1) {
    fVar1 = _5126;
  }
  dVar10 = (double)fVar1;
  if (this->field_0x71e == 0) {
    (this->mpEnemy->parent).mCurrent.mPos.y =
         (this->mpEnemy->parent).mCurrent.mPos.y - (float)((double)(this->field_0x44c).y + dVar10);
    (this->mpEnemy->parent).mNext.mPos.y =
         (this->mpEnemy->parent).mNext.mPos.y - (float)((double)(this->field_0x44c).y + dVar10);
    (this->mpEnemy->parent).mVelocity.y = (this->mpEnemy->parent).mVelocity.y * _5127;
    dBgS_Acch::CrrPos(&this->mAcch,&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS);
    (this->mpEnemy->parent).mVelocity.y = (this->mpEnemy->parent).mVelocity.y * _5128;
    (this->mpEnemy->parent).mCurrent.mPos.y =
         (this->mpEnemy->parent).mCurrent.mPos.y + (float)((double)(this->field_0x44c).y + dVar10);
    (this->mpEnemy->parent).mNext.mPos.y =
         (this->mpEnemy->parent).mNext.mPos.y + (float)((double)(this->field_0x44c).y + dVar10);
    pfVar2 = this->mpEnemy;
    (this->field_0x6e8).x = (pfVar2->parent).mNext.mPos.x;
    (this->field_0x6e8).y = (pfVar2->parent).mNext.mPos.y;
    (this->field_0x6e8).z = (pfVar2->parent).mNext.mPos.z;
    (this->field_0x6e8).y = this->mSpawnY;
    this->mSpawnY = (this->mAcch).field_0x94;
  }
  else {
    this->field_0x71e = this->field_0x71e + -1;
  }
  if ((this->field_0x6 != 0x15) && (this->field_0x6 != 0x16)) {
    ::cBgS_GndChk::cBgS_GndChk(&local_c4);
    pcVar6 = &local_84;
    local_84.mbCamThrough = 0;
    local_84.mbLinkThrough = 0;
    local_84.mbArrowsAndLightThrough = 0;
    local_84.mbBombThrough = 0;
    local_84.mbBoomerangThrough = 0;
    local_84.mbHookshotThrough = 0;
    local_c4.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar6;
    if (pcVar6 != (cBgS_PolyPassChk *)0x0) {
      local_c4.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_78;
    }
    local_84.mbObjThrough = 1;
    local_c4.parent.vtbl = (cBgS_Chk__vtbl *)&::dBgS_ObjGndChk_Spl::__vt;
    local_c4.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371ea8;
    local_84.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371eb4;
    local_78._0_4_ = &PTR_80371ec0;
    local_78._4_4_ = 0xe;
    pfVar2 = this->mpEnemy;
    local_c4.mPos.x = (pfVar2->parent).mCurrent.mPos.x;
    dVar9 = (double)local_c4.mPos.x;
    local_c4.mPos.z = (pfVar2->parent).mCurrent.mPos.z;
    dVar8 = (double)local_c4.mPos.z;
    local_c4.mPos.y = (pfVar2->parent).mCurrent.mPos.y + _5129;
    local_c4.parent.mpPolyPassChk = pcVar6;
    dVar10 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_c4);
    if (((double)_5130 != dVar10) && ((double)(this->mpEnemy->parent).mCurrent.mPos.y <= dVar10)) {
      (this->mpEnemy->parent).mCurrent.mPos.y =
           (float)(dVar10 + (double)d_s_play::g_regHIO.mChild[0].mFloats[13]);
      this->field_0x4 = 0;
      this->field_0x47c = 0;
      iVar3 = dBgS::ChkGrpInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&local_c4.mPolyInfo,
                              0x100);
      if (iVar3 == 0) {
        this->field_0x6 = 0x15;
        local_e8 = (float)dVar9;
        local_e4 = (float)dVar10;
        local_e0 = (float)dVar8;
        f_op_kankyo_mng::fopKyM_createMpillar
                  ((double)(_4083 + d_s_play::g_regHIO.mChild[0].mFloats[14]),&local_e8);
      }
      else {
        this->field_0x6 = 0x16;
        local_dc = (float)dVar9;
        local_d8 = (float)dVar10;
        local_d4 = (float)dVar8;
        f_op_kankyo_mng::fopKyM_createWpillar
                  ((double)(1_0 + d_s_play::g_regHIO.mChild[0].mFloats[9]),
                   (double)(1_0 + d_s_play::g_regHIO.mChild[0].mFloats[10]),&local_dc,0);
      }
    }
    local_84.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
    local_78._0_4_ = &PTR_80371f20;
    if (pcVar6 != (cBgS_PolyPassChk *)0x0) {
      local_84.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      local_78._0_4_ = &PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0x78) &&
         (local_78._0_4_ = &::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0x78)) {
        local_78._0_4_ = &::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar6 != (cBgS_PolyPassChk *)0x0) &&
         (local_84.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         pcVar6 != (cBgS_PolyPassChk *)0x0)) {
        local_84.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    local_c4.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
    local_c4.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk(&local_c4.parent);
  }
  if ((this->mEnemyType == 2) &&
     (uVar4 = d_a_sea::daSea_ChkArea
                        ((this->mpEnemy->parent).mCurrent.mPos.x,
                         (this->mpEnemy->parent).mCurrent.mPos.z), (uVar4 & 0xff) != 0)) {
    dVar10 = (double)d_a_sea::daSea_calcWave
                               ((double)(this->mpEnemy->parent).mCurrent.mPos.x,
                                (double)(this->mpEnemy->parent).mCurrent.mPos.z);
    local_cc = (this->field_0x44c).y +
               d_s_play::g_regHIO.mChild[0].mFloats[13] + (float)(dVar10 - (double)40_0);
    if ((this->mpEnemy->parent).mCurrent.mPos.y <= local_cc) {
      (this->mpEnemy->parent).mCurrent.mPos.y = local_cc;
      local_d0 = (this->mpEnemy->parent).mCurrent.mPos.x;
      local_c8 = (this->mpEnemy->parent).mCurrent.mPos.z;
      f_op_kankyo_mng::fopKyM_createWpillar
                ((double)(1_0 + d_s_play::g_regHIO.mChild[0].mFloats[9]),
                 (double)(1_0 + d_s_play::g_regHIO.mChild[0].mFloats[10]),&local_d0,0);
      pfVar2 = this->mpEnemy;
      sVar5 = d_com_inf_game::dComIfGp_getReverb((int)(char)(pfVar2->parent).mCurrent.mRoomNo);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x6918,&(pfVar2->parent).mEyePos,0,sVar5,1_0,1_0,_1_0,_1_0,0
                );
      f_op_actor_mng::fopAcM_delete((base_process_class *)this->mpEnemy);
      uVar4 = (uint)this->mpEnemy[1].parent.parent.parent.mInitState;
      if (uVar4 != 0) {
        dSv_info_c::onSwitch
                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,uVar4,
                   (int)(char)(this->mpEnemy->parent).mCurrent.mRoomNo);
      }
    }
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  __psq_l0(auStack40,uVar7);
  __psq_l1(auStack40,uVar7);
  return;
}

}

/* __thiscall dBgS_GndChk::~dBgS_GndChk(void) */

void __thiscall dBgS_GndChk::_dBgS_GndChk(dBgS_GndChk *this)

{
  short in_r4;
  
  if (this != (dBgS_GndChk *)0x0) {
    (this->parent).parent.vtbl = &__vt;
    (this->parent).mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371f08;
    (this->mPolyPassChk).parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
    (this->mGrpPassChk).parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
    if (this != (dBgS_GndChk *)0xffffffc0) {
      (this->mPolyPassChk).parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      (this->mGrpPassChk).parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
      if (this != (dBgS_GndChk *)0xffffffb4) {
        (this->mGrpPassChk).parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt;
        if (this != (dBgS_GndChk *)0xffffffb4) {
          (this->mGrpPassChk).parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
        }
      }
      if ((this != (dBgS_GndChk *)0xffffffc0) &&
         ((this->mPolyPassChk).parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         this != (dBgS_GndChk *)0xffffffc0)) {
        (this->mPolyPassChk).parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    if (this != (dBgS_GndChk *)0x0) {
      (this->parent).parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
      (this->parent).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371e90;
      if (this != (dBgS_GndChk *)0xffffffec) {
        (this->parent).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
      }
      cBgS_Chk::_cBgS_Chk((cBgS_Chk *)this);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cBgS_GndChk::~cBgS_GndChk(void) */

void __thiscall cBgS_GndChk::_cBgS_GndChk(cBgS_GndChk *this)

{
  short in_r4;
  
  if (this != (cBgS_GndChk *)0x0) {
    (this->parent).vtbl = (cBgS_Chk__vtbl *)&__vt;
    (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371e90;
    if (this != (cBgS_GndChk *)0xffffffec) {
      (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    }
    cBgS_Chk::_cBgS_Chk(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace c_damagereaction {

/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* WARNING: Removing unreachable block (ram,0x8001f678) */
/* WARNING: Removing unreachable block (ram,0x8001f670) */
/* WARNING: Removing unreachable block (ram,0x8001f680) */
/* __stdcall dr_joint_bg_check(damagereaction *) */

undefined4 dr_joint_bg_check(damagereaction *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  uint uVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  cBgS_PolyPassChk *pcVar10;
  cBgS_PolyPassChk *pcVar11;
  undefined4 uVar12;
  double dVar13;
  undefined8 in_f29;
  double dVar14;
  undefined8 in_f30;
  double dVar15;
  undefined8 in_f31;
  double dVar16;
  cXyz local_160;
  cXyz local_154;
  undefined local_148 [104];
  uint local_e0;
  cBgS_GndChk local_dc;
  cBgS_PolyPassChk local_9c;
  undefined local_90 [8];
  undefined4 local_88;
  undefined *local_84;
  undefined *local_80;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar12 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  local_88 = 0;
  ::cBgS_GndChk::cBgS_GndChk(&local_dc);
  pcVar11 = &local_9c;
  local_9c.mbCamThrough = 0;
  local_9c.mbLinkThrough = 0;
  local_9c.mbArrowsAndLightThrough = 0;
  local_9c.mbBombThrough = 0;
  local_9c.mbBoomerangThrough = 0;
  local_9c.mbHookshotThrough = 0;
  local_dc.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar11;
  if (pcVar11 != (cBgS_PolyPassChk *)0x0) {
    local_dc.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_90;
  }
  local_9c.mbObjThrough = 1;
  local_dc.parent.vtbl = (cBgS_Chk__vtbl *)&::dBgS_ObjGndChk_Yogan::__vt;
  local_80 = &DAT_80371e60;
  local_dc.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_80371e60;
  local_84 = &DAT_80371e6c;
  local_9c.vtbl = (cBgS_PolyPassChk__vtbl *)&DAT_80371e6c;
  local_90._0_4_ = (undefined **)&DAT_80371e78;
  local_90._4_4_ = 4;
  local_dc.parent.mpPolyPassChk = pcVar11;
  if (this->field_0x420 != 0) {
    this->field_0x420 = this->field_0x420 + -1;
    if ((this->field_0x420 == 0) && (this->field_0x70d == 1)) {
      local_88 = 2;
    }
    uVar5 = 0;
    iVar7 = 0;
    iVar8 = 0;
    dVar15 = (double)_5610;
    dVar16 = (double)10_0;
    dVar14 = (double)_5130;
    do {
      iVar9 = (int)this->field_0x10 + iVar8 + -0x10;
      *(undefined4 *)(iVar9 + 0x1f0) = *(undefined4 *)(iVar9 + 0x100);
      *(undefined4 *)(iVar9 + 500) = *(undefined4 *)(iVar9 + 0x104);
      *(undefined4 *)(iVar9 + 0x1f8) = *(undefined4 *)(iVar9 + 0x108);
      *(float *)(iVar9 + 500) =
           *(float *)(iVar9 + 500) +
           (float)(dVar15 + (double)(float)(dVar16 * (double)d_s_play::g_regHIO.mChild[0].mFloats[7]
                                           ));
      local_dc.mPos.x = *(float *)(iVar9 + 0x1f0);
      local_dc.mPos.y = *(float *)(iVar9 + 500);
      local_dc.mPos.z = *(float *)(iVar9 + 0x1f8);
      dVar13 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_dc
                                        );
      *(float *)(iVar9 + 500) = (float)dVar13;
      if (dVar14 == (double)*(float *)(iVar9 + 500)) {
        *(float *)(iVar9 + 500) = _5611;
      }
      if ((uVar5 < 3) || (uVar5 == 3)) {
        if (_5611 == *(float *)(iVar9 + 500)) {
          *(undefined4 *)(&this->field_0x3d0 + iVar7) = 2;
        }
        else {
          if (*(float *)(iVar9 + 0x104) - *(float *)(iVar9 + 500) <=
              _5610 + 10_0 * d_s_play::g_regHIO.mChild[0].mFloats[8]) {
            *(undefined4 *)(&this->field_0x3d0 + iVar7) = 1;
          }
          else {
            *(undefined4 *)(&this->field_0x3d0 + iVar7) = 0;
          }
        }
      }
      uVar5 = uVar5 + 1;
      iVar7 = iVar7 + 4;
      iVar8 = iVar8 + 0xc;
    } while ((int)uVar5 < 0xe);
    local_148._0_4_ = (cBgS_PolyPassChk *)0x0;
    local_148._4_4_ = (cBgS_PolyPassChk *)0x0;
    local_148[12] = true;
    local_148._20_2_ = -1;
    local_148._22_2_ = 0x100;
    local_148._24_4_ = (cBgW *)0x0;
    local_148._28_4_ = -1;
    local_148._16_4_ = &::cBgS_LinChk::__vt;
    local_148._32_4_ = &PTR_80371fbc;
    local_148._60_4_ = &::cM3dGLin::__vt;
    ::cBgS_LinChk::ct((cBgS_LinChk *)local_148);
    pcVar10 = (cBgS_PolyPassChk *)(local_148 + 0x58);
    local_148[92] = 0;
    local_148[93] = 0;
    local_148[94] = 0;
    local_148[95] = 0;
    local_148[96] = 0;
    local_148[97] = 0;
    local_148[98] = 0;
    local_e0 = 1;
    local_148._16_4_ = &::dBgS_LinChk::__vt;
    local_148._32_4_ = (undefined **)&DAT_80371f38;
    local_148._88_4_ = &PTR_80371f44;
    local_148._100_4_ = &PTR_80371f50;
    local_148._4_4_ = pcVar10;
    if (pcVar10 != (cBgS_PolyPassChk *)0x0) {
      local_148._4_4_ = (cBgS_PolyPassChk *)(local_148 + 100);
    }
    local_154.x = 0_0;
    local_154.y = 0_0;
    fVar1 = this->field_0x100[0xe].x - this->field_0x100[10].x;
    fVar2 = this->field_0x100[0xe].y - this->field_0x100[10].y;
    fVar3 = this->field_0x100[0xe].z - this->field_0x100[10].z;
    dVar14 = (double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2);
    if ((double)0_0 < dVar14) {
      dVar15 = 1.0 / SQRT(dVar14);
      dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
      dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
      dVar14 = (double)(float)(dVar14 * _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15));
    }
    local_154.z = (float)dVar14;
    local_148._0_4_ = pcVar10;
    iVar7 = SComponent::cM_atan2s(fVar1,fVar3);
    for (sVar6 = 0; -0x4001 < sVar6; sVar6 = sVar6 + -0x400) {
      m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,iVar7);
      m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,sVar6);
      SComponent::MtxPosition(&local_154,&local_160);
      local_160.x = local_160.x + this->field_0x100[10].x;
      local_160.y = local_160.y + this->field_0x100[10].y;
      local_160.z = local_160.z + this->field_0x100[10].z;
      ::dBgS_LinChk::Set((dBgS_LinChk *)local_148,this->field_0x100 + 10,&local_160,
                         &this->mpEnemy->parent);
      cVar4 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                              (cBgS_LinChk *)local_148);
      if (cVar4 == '\0') break;
    }
    if (sVar6 == 0) {
      fVar1 = this->field_0x1f0[6].x - this->field_0x1f0[10].x;
      fVar2 = this->field_0x1f0[6].z - this->field_0x1f0[10].z;
      dVar14 = (double)(fVar1 * fVar1 + fVar2 * fVar2);
      if ((double)0_0 < dVar14) {
        dVar15 = 1.0 / SQRT(dVar14);
        dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
        dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
        dVar14 = (double)(float)(dVar14 * _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15));
      }
      iVar7 = SComponent::cM_atan2s(this->field_0x1f0[6].y - this->field_0x1f0[10].y,(float)dVar14);
      this->field_0x440 = -(short)iVar7;
      *(undefined4 *)&this->field_0x408 = 0;
      if (this->field_0x70d == 1) {
        this->field_0x4b4 = 0;
        this->field_0x4b0 = 0;
      }
    }
    else {
      this->field_0x440 = sVar6 + 0x400;
      *(undefined4 *)&this->field_0x408 = 2;
    }
    if (this->field_0x440 < 0x1b59) {
      if (this->field_0x440 < -10000) {
        this->field_0x440 = -10000;
      }
    }
    else {
      this->field_0x440 = 7000;
    }
    fVar1 = this->field_0x100[0xf].x - this->field_0x100[0xb].x;
    fVar2 = this->field_0x100[0xf].y - this->field_0x100[0xb].y;
    fVar3 = this->field_0x100[0xf].z - this->field_0x100[0xb].z;
    dVar14 = (double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2);
    if ((double)0_0 < dVar14) {
      dVar15 = 1.0 / SQRT(dVar14);
      dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
      dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
      dVar14 = (double)(float)(dVar14 * _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15));
    }
    local_154.z = (float)dVar14;
    iVar7 = SComponent::cM_atan2s(fVar1,fVar3);
    for (sVar6 = 0; -0x4001 < sVar6; sVar6 = sVar6 + -0x400) {
      m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,iVar7);
      m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,sVar6);
      SComponent::MtxPosition(&local_154,&local_160);
      local_160.x = local_160.x + this->field_0x100[0xb].x;
      local_160.y = local_160.y + this->field_0x100[0xb].y;
      local_160.z = local_160.z + this->field_0x100[0xb].z;
      ::dBgS_LinChk::Set((dBgS_LinChk *)local_148,this->field_0x100 + 0xb,&local_160,
                         &this->mpEnemy->parent);
      cVar4 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                              (cBgS_LinChk *)local_148);
      if (cVar4 == '\0') break;
    }
    if (sVar6 == 0) {
      fVar1 = this->field_0x1f0[7].x - this->field_0x1f0[0xb].x;
      fVar2 = this->field_0x1f0[7].z - this->field_0x1f0[0xb].z;
      dVar14 = (double)(fVar1 * fVar1 + fVar2 * fVar2);
      if ((double)0_0 < dVar14) {
        dVar15 = 1.0 / SQRT(dVar14);
        dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
        dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
        dVar14 = (double)(float)(dVar14 * _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15));
      }
      iVar7 = SComponent::cM_atan2s(this->field_0x1f0[7].y - this->field_0x1f0[0xb].y,(float)dVar14)
      ;
      this->field_0x442 = -(short)iVar7;
      *(undefined4 *)&this->field_0x40c = 0;
      if (this->field_0x70d == 1) {
        this->field_0x4b6 = 0;
        this->field_0x4b2 = 0;
      }
    }
    else {
      this->field_0x442 = sVar6 + 0x400;
      *(undefined4 *)&this->field_0x40c = 2;
    }
    fVar1 = this->field_0x100[0x10].x - this->field_0x100[8].x;
    fVar2 = this->field_0x100[0x10].y - this->field_0x100[8].y;
    fVar3 = this->field_0x100[0x10].z - this->field_0x100[8].z;
    dVar14 = (double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2);
    if ((double)0_0 < dVar14) {
      dVar15 = 1.0 / SQRT(dVar14);
      dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
      dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
      dVar14 = (double)(float)(dVar14 * _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15));
    }
    local_154.z = (float)dVar14;
    iVar7 = SComponent::cM_atan2s(fVar1,fVar3);
    for (sVar6 = 0; -0x4001 < sVar6; sVar6 = sVar6 + -0x400) {
      m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,iVar7);
      m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,sVar6);
      SComponent::MtxPosition(&local_154,&local_160);
      local_160.x = local_160.x + this->field_0x100[8].x;
      local_160.y = local_160.y + this->field_0x100[8].y;
      local_160.z = local_160.z + this->field_0x100[8].z;
      ::dBgS_LinChk::Set((dBgS_LinChk *)local_148,this->field_0x100 + 8,&local_160,
                         &this->mpEnemy->parent);
      cVar4 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                              (cBgS_LinChk *)local_148);
      if (cVar4 == '\0') break;
    }
    if (sVar6 == 0) {
      fVar1 = this->field_0x1f0[4].x - this->field_0x1f0[8].x;
      fVar2 = this->field_0x1f0[4].z - this->field_0x1f0[8].z;
      dVar14 = (double)(fVar1 * fVar1 + fVar2 * fVar2);
      if ((double)0_0 < dVar14) {
        dVar15 = 1.0 / SQRT(dVar14);
        dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
        dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
        dVar14 = (double)(float)(dVar14 * _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15));
      }
      iVar7 = SComponent::cM_atan2s(this->field_0x1f0[4].y - this->field_0x1f0[8].y,(float)dVar14);
      this->field_0x444 = -(short)iVar7;
      this->field_0x410 = 0;
    }
    else {
      this->field_0x444 = sVar6 + 0x400;
      this->field_0x410 = 2;
    }
    fVar1 = this->field_0x100[0x11].x - this->field_0x100[9].x;
    fVar2 = this->field_0x100[0x11].y - this->field_0x100[9].y;
    fVar3 = this->field_0x100[0x11].z - this->field_0x100[9].z;
    dVar14 = (double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2);
    if ((double)0_0 < dVar14) {
      dVar15 = 1.0 / SQRT(dVar14);
      dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
      dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
      dVar14 = (double)(float)(dVar14 * _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15));
    }
    local_154.z = (float)dVar14;
    iVar7 = SComponent::cM_atan2s(fVar1,fVar3);
    for (sVar6 = 0; -0x4001 < sVar6; sVar6 = sVar6 + -0x400) {
      m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,iVar7);
      m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,sVar6);
      SComponent::MtxPosition(&local_154,&local_160);
      local_160.x = local_160.x + this->field_0x100[9].x;
      local_160.y = local_160.y + this->field_0x100[9].y;
      local_160.z = local_160.z + this->field_0x100[9].z;
      ::dBgS_LinChk::Set((dBgS_LinChk *)local_148,this->field_0x100 + 9,&local_160,
                         &this->mpEnemy->parent);
      cVar4 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                              (cBgS_LinChk *)local_148);
      if (cVar4 == '\0') break;
    }
    if (sVar6 == 0) {
      fVar1 = this->field_0x1f0[5].x - this->field_0x1f0[9].x;
      fVar2 = this->field_0x1f0[5].z - this->field_0x1f0[9].z;
      dVar14 = (double)(fVar1 * fVar1 + fVar2 * fVar2);
      if ((double)0_0 < dVar14) {
        dVar15 = 1.0 / SQRT(dVar14);
        dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
        dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
        dVar14 = (double)(float)(dVar14 * _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15));
      }
      iVar7 = SComponent::cM_atan2s(this->field_0x1f0[5].y - this->field_0x1f0[9].y,(float)dVar14);
      *(short *)&this->field_0x446 = -(short)iVar7;
      *(undefined4 *)&this->field_0x414 = 0;
    }
    else {
      *(short *)&this->field_0x446 = sVar6 + 0x400;
      *(undefined4 *)&this->field_0x414 = 2;
    }
    fVar1 = this->field_0x100[0x12].x - this->field_0x100[0xc].x;
    fVar2 = this->field_0x100[0x12].y - this->field_0x100[0xc].y;
    fVar3 = this->field_0x100[0x12].z - this->field_0x100[0xc].z;
    dVar14 = (double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2);
    if ((double)0_0 < dVar14) {
      dVar15 = 1.0 / SQRT(dVar14);
      dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
      dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
      dVar14 = (double)(float)(dVar14 * _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15));
    }
    local_154.z = (float)dVar14;
    iVar7 = SComponent::cM_atan2s(fVar1,fVar3);
    if (d_s_play::g_regHIO.mChild[0].mShorts[4] == 0) {
      for (sVar6 = 0; -0x4001 < sVar6; sVar6 = sVar6 + -0x400) {
        m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,iVar7);
        m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,sVar6);
        SComponent::MtxPosition(&local_154,&local_160);
        local_160.x = local_160.x + this->field_0x100[0xc].x;
        local_160.y = local_160.y + this->field_0x100[0xc].y;
        local_160.z = local_160.z + this->field_0x100[0xc].z;
        ::dBgS_LinChk::Set((dBgS_LinChk *)local_148,this->field_0x100 + 0xc,&local_160,
                           &this->mpEnemy->parent);
        cVar4 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                (cBgS_LinChk *)local_148);
        if (cVar4 == '\0') break;
      }
      if (sVar6 == 0) {
        fVar1 = this->field_0x1f0[0xd].x - this->field_0x1f0[0xc].x;
        fVar2 = this->field_0x1f0[0xd].z - this->field_0x1f0[0xc].z;
        dVar14 = (double)(fVar1 * fVar1 + fVar2 * fVar2);
        if ((double)0_0 < dVar14) {
          dVar15 = 1.0 / SQRT(dVar14);
          dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
          dVar15 = _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15);
          dVar14 = (double)(float)(dVar14 * _4752 * dVar15 * (_4753 - dVar14 * dVar15 * dVar15));
        }
        iVar7 = SComponent::cM_atan2s
                          (this->field_0x1f0[0xd].y - this->field_0x1f0[0xc].y,(float)dVar14);
        this->field_0x448 = -(short)iVar7;
        this->field_0x418 = 0;
      }
      else {
        this->field_0x448 = sVar6 + 0x400;
        this->field_0x418 = 2;
      }
      if (this->field_0x448 < 0x32c9) {
        if (this->field_0x448 < -13000) {
          this->field_0x448 = -13000;
        }
      }
      else {
        this->field_0x448 = 13000;
      }
    }
    local_148._88_4_ = &PTR_80371f44;
    local_148._100_4_ = &PTR_80371f50;
    if (pcVar10 != (cBgS_PolyPassChk *)0x0) {
      local_148._88_4_ = &::dBgS_Chk::__vt;
      local_148._100_4_ = &PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0xe4) &&
         (local_148._100_4_ = &::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0xe4)) {
        local_148._100_4_ = &::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar10 != (cBgS_PolyPassChk *)0x0) &&
         (local_148._88_4_ = &::dBgS_PolyPassChk::__vt, pcVar10 != (cBgS_PolyPassChk *)0x0)) {
        local_148._88_4_ = &::cBgS_PolyPassChk::__vt;
      }
    }
    local_148._16_4_ = &::cBgS_LinChk::__vt;
    local_148._60_4_ = &::cM3dGLin::__vt;
    local_148._32_4_ = &::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk((cBgS_Chk *)local_148);
  }
  local_9c.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_90._0_4_ = &PTR_80371f20;
  if (pcVar11 != (cBgS_PolyPassChk *)0x0) {
    local_9c.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_90._0_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x90) &&
       (local_90._0_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x90)) {
      local_90._0_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar11 != (cBgS_PolyPassChk *)0x0) &&
       (local_9c.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar11 != (cBgS_PolyPassChk *)0x0)) {
      local_9c.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_dc.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_dc.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_dc.parent);
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  __psq_l0(auStack24,uVar12);
  __psq_l1(auStack24,uVar12);
  __psq_l0(auStack40,uVar12);
  __psq_l1(auStack40,uVar12);
  return local_88;
}

}

/* __thiscall dBgS_ObjGndChk_Yogan::~dBgS_ObjGndChk_Yogan(void) */

void __thiscall dBgS_ObjGndChk_Yogan::_dBgS_ObjGndChk_Yogan(dBgS_ObjGndChk_Yogan *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dBgS_ObjGndChk_Yogan *)0x0;
  if (bVar1) {
    *(undefined1 **)(this + 0x10) = &__vt;
    *(undefined **)(this + 0x20) = &DAT_80371e60;
    *(undefined **)(this + 0x40) = &DAT_80371e6c;
    *(undefined **)(this + 0x4c) = &DAT_80371e78;
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
        if (this != (dBgS_ObjGndChk_Yogan *)0xffffffc0) {
          *(undefined ***)(this + 0x40) = &::dBgS_Chk::__vt;
          *(undefined ***)(this + 0x4c) = &PTR_80371f68;
          if (this != (dBgS_ObjGndChk_Yogan *)0xffffffb4) {
            *(undefined ***)(this + 0x4c) = &::dBgS_GrpPassChk::__vt;
            if (this != (dBgS_ObjGndChk_Yogan *)0xffffffb4) {
              *(undefined ***)(this + 0x4c) = &::cBgS_GrpPassChk::__vt;
            }
          }
          if ((this != (dBgS_ObjGndChk_Yogan *)0xffffffc0) &&
             (*(undefined ***)(this + 0x40) = &::dBgS_PolyPassChk::__vt,
             this != (dBgS_ObjGndChk_Yogan *)0xffffffc0)) {
            *(undefined ***)(this + 0x40) = &::cBgS_PolyPassChk::__vt;
          }
        }
        if (this != (dBgS_ObjGndChk_Yogan *)0x0) {
          *(undefined1 **)(this + 0x10) = &::cBgS_GndChk::__vt;
          *(undefined ***)(this + 0x20) = &PTR_80371e90;
          if (this != (dBgS_ObjGndChk_Yogan *)0xffffffec) {
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


namespace c_damagereaction {

/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* WARNING: Removing unreachable block (ram,0x8001fb80) */
/* WARNING: Removing unreachable block (ram,0x8001fb70) */
/* WARNING: Removing unreachable block (ram,0x8001fb68) */
/* WARNING: Removing unreachable block (ram,0x8001fb78) */
/* WARNING: Removing unreachable block (ram,0x8001fb88) */
/* __stdcall kado_check(damagereaction *) */

uint kado_check(damagereaction *this)

{
  fopEn_enemy_c *pfVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  cBgS_PolyPassChk *pcVar6;
  undefined4 uVar7;
  undefined8 in_f27;
  double dVar8;
  undefined8 in_f28;
  double dVar9;
  undefined8 in_f29;
  double dVar10;
  undefined8 in_f30;
  double dVar11;
  undefined8 in_f31;
  double dVar12;
  cXyz cStack280;
  cXyz local_10c;
  cXyz local_100;
  undefined local_f4 [104];
  uint local_8c;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar7 = 0;
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
  local_f4._0_4_ = (cBgS_PolyPassChk *)0x0;
  local_f4._4_4_ = (cBgS_PolyPassChk *)0x0;
  local_f4[12] = true;
  local_f4._20_2_ = -1;
  local_f4._22_2_ = 0x100;
  local_f4._24_4_ = (cBgW *)0x0;
  local_f4._28_4_ = -1;
  local_f4._16_4_ = &::cBgS_LinChk::__vt;
  local_f4._32_4_ = &PTR_80371fbc;
  local_f4._60_4_ = &::cM3dGLin::__vt;
  ::cBgS_LinChk::ct((cBgS_LinChk *)local_f4);
  pcVar6 = (cBgS_PolyPassChk *)(local_f4 + 0x58);
  local_f4[92] = 0;
  local_f4[93] = 0;
  local_f4[94] = 0;
  local_f4[95] = 0;
  local_f4[96] = 0;
  local_f4[97] = 0;
  local_f4[98] = 0;
  local_8c = 1;
  local_f4._16_4_ = &::dBgS_LinChk::__vt;
  local_f4._32_4_ = (undefined **)&DAT_80371f38;
  local_f4._88_4_ = &PTR_80371f44;
  local_f4._100_4_ = &PTR_80371f50;
  local_f4._4_4_ = pcVar6;
  if (pcVar6 != (cBgS_PolyPassChk *)0x0) {
    local_f4._4_4_ = (cBgS_PolyPassChk *)(local_f4 + 100);
  }
  uVar5 = 0;
  local_f4._0_4_ = pcVar6;
  m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)this->field_0x482);
  m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,this->field_0x480);
  iVar4 = 0;
  iVar3 = 0;
  dVar12 = (double)_4080;
  dVar8 = (double)_5745;
  dVar9 = (double)_5746;
  dVar10 = (double)_4748;
  dVar11 = (double)1_0;
  do {
    pfVar1 = this->mpEnemy;
    local_10c.x = (pfVar1->parent).mCurrent.mPos.x;
    local_10c.z = (pfVar1->parent).mCurrent.mPos.z;
    local_10c.y = (pfVar1->parent).mCurrent.mPos.y +
                  (float)(dVar12 + (double)d_s_play::g_regHIO.mChild[14].mFloats[0]);
    local_100.x = d_s_play::g_regHIO.mChild[14].mFloats[1];
    local_100.y = d_s_play::g_regHIO.mChild[14].mFloats[2];
    local_100.z = (float)(dVar8 + (double)d_s_play::g_regHIO.mChild[14].mFloats[3]);
    SComponent::MtxPosition(&local_100,&cStack280);
    mtx::PSVECAdd(&local_10c,&cStack280,&local_10c);
    local_100.y = (float)(dVar9 + (double)d_s_play::g_regHIO.mChild[14].mFloats[4]);
    local_100.z = (float)(dVar10 + (double)d_s_play::g_regHIO.mChild[14].mFloats[5]);
    local_100.x = (float)(dVar11 + (double)d_s_play::g_regHIO.mChild[14].mFloats[6]) *
                  *(float *)((int)kado_check_x_5638 + iVar3);
    SComponent::MtxPosition(&local_100,&cStack280);
    mtx::PSVECAdd(&cStack280,&local_10c,&cStack280);
    ::dBgS_LinChk::Set((dBgS_LinChk *)local_f4,&local_10c,&cStack280,&this->mpEnemy->parent);
    cVar2 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                            (cBgS_LinChk *)local_f4);
    if (cVar2 != '\0') {
      uVar5 = uVar5 | *(uint *)((int)kado_bit_5637 + iVar3);
    }
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + 4;
  } while (iVar4 < 2);
  if (uVar5 == 3) {
    uVar5 = 0;
  }
  local_f4._88_4_ = &PTR_80371f44;
  local_f4._100_4_ = &PTR_80371f50;
  if (pcVar6 != (cBgS_PolyPassChk *)0x0) {
    local_f4._88_4_ = &::dBgS_Chk::__vt;
    local_f4._100_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x90) &&
       (local_f4._100_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x90)) {
      local_f4._100_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar6 != (cBgS_PolyPassChk *)0x0) &&
       (local_f4._88_4_ = &::dBgS_PolyPassChk::__vt, pcVar6 != (cBgS_PolyPassChk *)0x0)) {
      local_f4._88_4_ = &::cBgS_PolyPassChk::__vt;
    }
  }
  local_f4._16_4_ = &::cBgS_LinChk::__vt;
  local_f4._60_4_ = &::cM3dGLin::__vt;
  local_f4._32_4_ = &::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk((cBgS_Chk *)local_f4);
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  __psq_l0(auStack40,uVar7);
  __psq_l1(auStack40,uVar7);
  __psq_l0(auStack56,uVar7);
  __psq_l1(auStack56,uVar7);
  __psq_l0(auStack72,uVar7);
  __psq_l1(auStack72,uVar7);
  return uVar5;
}


/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* WARNING: Removing unreachable block (ram,0x8001ffcc) */
/* __stdcall hang_ang_get(damagereaction *) */

int hang_ang_get(damagereaction *this)

{
  int iVar1;
  char cVar2;
  cXyz *pDst;
  int iVar3;
  cBgS_PolyPassChk *pcVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  cXyz local_108;
  cXyz local_fc;
  cXyz cStack240;
  cXyz local_e4;
  cXyz local_d8 [2];
  undefined local_c0 [104];
  uint local_58;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  local_c0._0_4_ = (cBgS_PolyPassChk *)0x0;
  local_c0._4_4_ = (cBgS_PolyPassChk *)0x0;
  local_c0[12] = true;
  local_c0._20_2_ = -1;
  local_c0._22_2_ = 0x100;
  local_c0._24_4_ = (cBgW *)0x0;
  local_c0._28_4_ = -1;
  local_c0._16_4_ = &::cBgS_LinChk::__vt;
  local_c0._32_4_ = &PTR_80371fbc;
  local_c0._60_4_ = &::cM3dGLin::__vt;
  ::cBgS_LinChk::ct((cBgS_LinChk *)local_c0);
  pcVar4 = (cBgS_PolyPassChk *)(local_c0 + 0x58);
  local_c0[92] = 0;
  local_c0[93] = 0;
  local_c0[94] = 0;
  local_c0[95] = 0;
  local_c0[96] = 0;
  local_c0[97] = 0;
  local_c0[98] = 0;
  local_58 = 1;
  local_c0._16_4_ = &::dBgS_LinChk::__vt;
  local_c0._32_4_ = (undefined **)&DAT_80371f38;
  local_c0._88_4_ = &PTR_80371f44;
  local_c0._100_4_ = &PTR_80371f50;
  local_c0._4_4_ = pcVar4;
  if (pcVar4 != (cBgS_PolyPassChk *)0x0) {
    local_c0._4_4_ = (cBgS_PolyPassChk *)(local_c0 + 100);
  }
  local_c0._0_4_ = pcVar4;
  ::cXyz::operator__(&local_fc,&this->field_0x7a0,&(this->mpEnemy->parent).mCurrent.mPos);
  local_e4.x = local_fc.x;
  local_e4.y = local_fc.y;
  local_e4.z = local_fc.z;
  iVar1 = SComponent::cM_atan2s(local_fc.x,local_fc.z);
  m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,iVar1);
  local_e4.x = 0_0;
  local_e4.y = 0_0;
  local_e4.z = _5892;
  SComponent::MtxPosition(&local_e4,&cStack240);
  mtx::PSVECAdd(&cStack240,&(this->mpEnemy->parent).mCurrent.mPos,&cStack240);
  cStack240.y = (this->field_0x7a0).y - 5_0;
  local_e4.x = 10_0;
  local_e4.y = 0_0;
  local_e4.z = _4749;
  iVar1 = 0;
  iVar3 = 0;
  dVar6 = (double)_1_0;
  do {
    pDst = (cXyz *)((int)&local_d8[0].x + iVar3);
    SComponent::MtxPosition(&local_e4,pDst);
    local_e4.x = (float)((double)local_e4.x * dVar6);
    mtx::PSVECAdd(pDst,&cStack240,pDst);
    ::dBgS_LinChk::Set((dBgS_LinChk *)local_c0,&cStack240,pDst,&this->mpEnemy->parent);
    cVar2 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                            (cBgS_LinChk *)local_c0);
    if (cVar2 == '\0') {
      local_c0._88_4_ = &PTR_80371f44;
      local_c0._100_4_ = &PTR_80371f50;
      if (pcVar4 != (cBgS_PolyPassChk *)0x0) {
        local_c0._88_4_ = &::dBgS_Chk::__vt;
        local_c0._100_4_ = &PTR_80371f68;
        if (((undefined *)register0x00000004 != (undefined *)0x5c) &&
           (local_c0._100_4_ = &::dBgS_GrpPassChk::__vt,
           (undefined *)register0x00000004 != (undefined *)0x5c)) {
          local_c0._100_4_ = &::cBgS_GrpPassChk::__vt;
        }
        if ((pcVar4 != (cBgS_PolyPassChk *)0x0) &&
           (local_c0._88_4_ = &::dBgS_PolyPassChk::__vt, pcVar4 != (cBgS_PolyPassChk *)0x0)) {
          local_c0._88_4_ = &::cBgS_PolyPassChk::__vt;
        }
      }
      local_c0._16_4_ = &::cBgS_LinChk::__vt;
      if ((undefined *)register0x00000004 != (undefined *)0x9c) {
        local_c0._60_4_ = &::cM3dGLin::__vt;
      }
      local_c0._32_4_ = &::cBgS_PolyInfo::__vt;
      cBgS_Chk::_cBgS_Chk((cBgS_Chk *)local_c0);
      iVar1 = 0xdcf;
      goto LAB_8001ffcc;
    }
    pDst->x = local_c0._48_4_;
    *(float *)((int)&local_d8[0].y + iVar3) = local_c0._52_4_;
    *(float *)((int)&local_d8[0].z + iVar3) = local_c0._56_4_;
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0xc;
  } while (iVar1 < 2);
  ::cXyz::operator__(&local_108,local_d8 + 1,local_d8);
  local_e4.x = local_108.x;
  local_e4.y = local_108.y;
  local_e4.z = local_108.z;
  iVar1 = SComponent::cM_atan2s(local_108.x,local_108.z);
  iVar1 = (int)(short)((short)iVar1 + 0x4000);
  local_c0._88_4_ = &PTR_80371f44;
  local_c0._100_4_ = &PTR_80371f50;
  if (pcVar4 != (cBgS_PolyPassChk *)0x0) {
    local_c0._88_4_ = &::dBgS_Chk::__vt;
    local_c0._100_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x5c) &&
       (local_c0._100_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x5c)) {
      local_c0._100_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar4 != (cBgS_PolyPassChk *)0x0) &&
       (local_c0._88_4_ = &::dBgS_PolyPassChk::__vt, pcVar4 != (cBgS_PolyPassChk *)0x0)) {
      local_c0._88_4_ = &::cBgS_PolyPassChk::__vt;
    }
  }
  local_c0._16_4_ = &::cBgS_LinChk::__vt;
  if ((undefined *)register0x00000004 != (undefined *)0x9c) {
    local_c0._60_4_ = &::cM3dGLin::__vt;
  }
  local_c0._32_4_ = &::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk((cBgS_Chk *)local_c0);
LAB_8001ffcc:
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return iVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Type propagation algorithm not settling */
/* __stdcall dr_damage_set(damagereaction *) */

int dr_damage_set(damagereaction *this)

{
  ushort uVar1;
  bool bVar2;
  float fVar3;
  short sVar4;
  int iVar5;
  fopEn_enemy_c *pfVar6;
  short sVar8;
  JPABaseEmitter *pJVar7;
  sbyte sVar9;
  int iVar10;
  int react;
  float fVar11;
  cXyz local_58;
  cXyz local_4c;
  cXyz local_40;
  longlong local_30;
  longlong local_28;
  longlong local_20;
  longlong local_18;
  
  react = 0;
  bVar2 = false;
  if ((this->mEnemyType == 2) && (this->field_0x488 == 0)) {
    if (this->field_0x6 < 0x13) {
      if (this->mMaxFallDistance < (this->mpEnemy->parent).mCurrent.mPos.y - this->mSpawnY) {
        if ((this->field_0x7b2 == 0) || (this->field_0x4 < -99)) {
          if ((this->field_0x6e8).y - this->mSpawnY <= _6149) {
            bVar2 = true;
            (this->mpEnemy->parent).mCurrHp = 0;
          }
          else {
            (this->field_0x7a0).x = (this->field_0x6e8).x;
            (this->field_0x7a0).y = (this->field_0x6e8).y;
            (this->field_0x7a0).z = (this->field_0x6e8).z;
            sVar8 = hang_ang_get(this);
            this->field_0x7ae = sVar8;
            if (this->field_0x7ae == 0xdcf) {
              bVar2 = true;
              (this->mpEnemy->parent).mCurrHp = 0;
            }
            else {
              this->field_0x6 = 0x13;
              this->field_0x4 = 0;
              this->field_0x71e = 2;
              *(undefined4 *)&this[1].field_0x4 = 0xffffffff;
            }
          }
        }
        else {
          this->field_0x6 = 0x13;
          this->field_0x4 = 0;
          this->field_0x71e = 2;
        }
      }
    }
  }
  else {
    if (this->mMaxFallDistance < (this->mpEnemy->parent).mCurrent.mPos.y - this->mSpawnY) {
      bVar2 = true;
      (this->mpEnemy->parent).mCurrHp = 0;
    }
  }
  fVar11 = _6163;
  sVar8 = this->field_0x488;
  if (sVar8 == 1) {
    sVar8 = 0x800;
    if (0 < this->field_0x486) {
      sVar8 = 0x350;
    }
    if (test_sw != '\0') {
      this->field_0x486 = 0;
    }
    SComponent::cLib_addCalcAngleS2(&this->field_0x480,this->field_0x486,3,sVar8);
    if ((((this->field_0x70c != 0) && (this->field_0x474 <= 0_01)) && (this->field_0x4c8[2] == 0))
       && (test_sw == '\0')) {
      if ((this->mpEnemy->parent).mCurrHp < 1) {
        this->field_0x6 = 0x14;
        this->field_0x4 = 0;
        this->field_0x4c8[2] = 10000;
      }
      else {
        this->field_0x4be = 0;
        this->field_0x4bc = 0;
        this->field_0x4ba = 0;
        this->field_0x4b8 = 0;
        this->field_0x49c = 0;
        this->field_0x49a = 0;
        this->field_0x4b2 = 0;
        this->field_0x4b6 = 0;
        this->field_0x4b0 = 0;
        this->field_0x4b4 = 0;
        if (this->field_0x70d == 0) {
          this->field_0x4 = 10;
        }
        else {
          this->field_0x4 = 0xc;
        }
        this->field_0x6 = 0xb;
        this->field_0x48a = 0;
        this->field_0x488 = 2;
        (this->mpEnemy->parent).mCurrent.mRot.y =
             (this->mpEnemy->parent).mCurrent.mRot.y + this->field_0x484;
        (this->mpEnemy->parent).mCollisionRot.y =
             (this->mpEnemy->parent).mCollisionRot.y + this->field_0x484;
        this->field_0x4c0 = this->field_0x4c0 + this->field_0x484;
        *(undefined *)((int)&this[1].mpEnemy + 2) = 1;
        this->field_0x484 = 0;
        this->field_0x6e0 = 0;
      }
    }
  }
  else {
    if (sVar8 < 1) {
      if (-1 < sVar8) {
        if ((bVar2) || ((this->field_0x424 != 0 && (25_0 < this->field_0x428)))) {
          this->field_0x4 = -100;
          this->field_0x488 = 1;
          this->field_0x713 = 0;
          (this->field_0x44c).y = _6150;
          this->field_0x486 = 0x4000;
          local_40.x = (this->field_0x42c).x;
          local_40.y = (this->field_0x42c).y;
          local_40.z = (this->field_0x42c).z;
          if (bVar2) {
            this->field_0x482 = (this->mpEnemy->parent).mCollisionRot.y;
            fVar11 = 0_0;
            this->field_0x478 = 0_0;
            (this->mpEnemy->parent).mVelocity.y = fVar11;
            this->field_0x71e = 10;
          }
          else {
            if ((this->field_0x424 & 0x40U) == 0) {
              iVar5 = SComponent::cM_atan2s(local_40.x,local_40.z);
              this->field_0x482 = (short)iVar5;
              this->field_0x478 = this->field_0x428;
              if (((this->mEnemyType == 2) &&
                  (((this->mpEnemy->parent).parent.parent.mParameters & 0xfU) == 10)) ||
                 (d_s_play::g_regHIO.mChild[0].mShorts[5] != 0)) {
                (this->mpEnemy->parent).mVelocity.y =
                     _6154 * this->field_0x478 * (_6154 + d_s_play::g_regHIO.mChild[0].mFloats[7]);
              }
              else {
                (this->mpEnemy->parent).mVelocity.y = _6155 * _6156 * this->field_0x478;
              }
            }
            else {
              if (this->field_0x712 == 0) {
                this->field_0x478 = _4081;
                (this->mpEnemy->parent).mVelocity.y = _6153;
              }
              else {
                this->field_0x478 = _6151;
                (this->mpEnemy->parent).mVelocity.y = _6152;
              }
              iVar5 = SComponent::cM_atan2s(local_40.x,local_40.z);
              this->field_0x482 = (short)iVar5 + -0x8000;
            }
          }
          local_40.x = 0_0;
          local_40.y = 0_0;
          local_40.z = this->field_0x478;
          m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)this->field_0x482);
          SComponent::MtxPosition(&local_40,&local_4c);
          (this->mpEnemy->parent).mVelocity.x = local_4c.x;
          (this->mpEnemy->parent).mVelocity.z = local_4c.z;
          this->field_0x47c = 1;
          fVar11 = SComponent::cM_rndF(_6157);
          local_30 = (longlong)(int)fVar11;
          this->field_0x4ae = (short)(int)fVar11;
          fVar11 = SComponent::cM_rndF(_6157);
          local_28 = (longlong)(int)fVar11;
          this->field_0x4ac = (short)(int)fVar11;
          fVar11 = SComponent::cM_rndF(_6158);
          local_20 = (longlong)(int)fVar11;
          this->field_0x4aa = (short)(int)fVar11;
          fVar11 = SComponent::cM_rndF(_6158);
          local_18 = (longlong)(int)fVar11;
          this->field_0x4a8 = (short)(int)fVar11;
          this->field_0x70c = 0;
          this->field_0x474 = _4518;
          this->field_0x70e = 0xff;
          if (this->mEnemyType == 3) {
            fVar11 = SComponent::cM_rndF(_6159);
            local_18 = (longlong)(int)-fVar11;
            this->field_0x4bc = (short)(int)-fVar11;
            fVar11 = SComponent::cM_rndF(_6159);
            local_20 = (longlong)(int)fVar11;
            this->field_0x4be = (short)(int)fVar11;
          }
          else {
            fVar11 = SComponent::cM_rndF(_6160);
            local_18 = (longlong)(int)(_5129 + fVar11);
            this->field_0x4b8 = (short)(int)(_5129 + fVar11);
            fVar11 = SComponent::cM_rndF(_6160);
            local_20 = (longlong)(int)(_5129 + fVar11);
            this->field_0x4ba = (short)(int)(_5129 + fVar11);
            fVar11 = SComponent::cM_rndF(_6162);
            local_28 = (longlong)(int)(_6161 + fVar11);
            this->field_0x4bc = (short)(int)(_6161 + fVar11);
            fVar11 = SComponent::cM_rndF(_6162);
            local_30 = (longlong)(int)(_6161 + fVar11);
            this->field_0x4be = (short)(int)(_6161 + fVar11);
          }
          react = 1;
          if (bVar2) {
            react = 0x1e;
          }
          this->field_0x48a = 0;
        }
        else {
          if ((this->field_0x424 & 0x10U) != 0) {
            this->field_0x470 = _6163 + d_s_play::g_regHIO.mChild[0].mFloats[13];
            this->field_0x474 = fVar11 + d_s_play::g_regHIO.mChild[0].mFloats[14];
            this->field_0x70e = 7;
            react = 5;
          }
        }
      }
    }
    else {
      if (sVar8 < 3) {
        this->field_0x484 = 0;
        this->field_0x6e0 = 0;
      }
    }
  }
  if ((*(char *)((int)&this[1].mpEnemy + 2) == '\0') && (test_sw == '\0')) {
    if (this->field_0x4c8[0] == 0) {
      iVar5 = SComponent::cM_atan2s(-(this->field_0x42c).x,-(this->field_0x42c).z);
      m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,iVar5);
      local_40.x = 0_0;
      local_40.y = 0_0;
      local_40.z = this->field_0x4d4;
      SComponent::MtxPosition(&local_40,&local_58);
      fVar11 = _5127;
      pfVar6 = this->mpEnemy;
      (pfVar6->parent).mCurrent.mPos.x =
           (pfVar6->parent).mCurrent.mPos.x + _5127 * (pfVar6->parent).mVelocity.x + local_58.x;
      pfVar6 = this->mpEnemy;
      (pfVar6->parent).mCurrent.mPos.y =
           (pfVar6->parent).mCurrent.mPos.y + fVar11 * (pfVar6->parent).mVelocity.y + local_58.y;
      pfVar6 = this->mpEnemy;
      (pfVar6->parent).mCurrent.mPos.z =
           (pfVar6->parent).mCurrent.mPos.z + fVar11 * (pfVar6->parent).mVelocity.z + local_58.z;
      if ((this->field_0x6 != 0xf) && (&this->mStts != (dCcD_Stts *)0x0)) {
        (this->mpEnemy->parent).mCurrent.mPos.x =
             (this->mpEnemy->parent).mCurrent.mPos.x + (this->mStts).parent.mCcMove.x;
        (this->mpEnemy->parent).mCurrent.mPos.y =
             (this->mpEnemy->parent).mCurrent.mPos.y + (this->mStts).parent.mCcMove.y;
        (this->mpEnemy->parent).mCurrent.mPos.z =
             (this->mpEnemy->parent).mCurrent.mPos.z + (this->mStts).parent.mCcMove.z;
      }
      if (this->mInvincibleTimer == 0) {
        (this->mpEnemy->parent).mVelocity.y = (this->mpEnemy->parent).mVelocity.y - _6164;
        if ((this->mpEnemy->parent).mVelocity.y < _6165) {
          (this->mpEnemy->parent).mVelocity.y = _6165;
        }
      }
      SComponent::cLib_addCalc0(&this->field_0x4d4,1_0,10_0);
    }
    else {
      if ((this->field_0x4c8[0] == 1) && (this->field_0x486 == 0)) {
        this->field_0x486 = -0x4000;
        fVar11 = SComponent::cM_rndF(_6157);
        local_18 = (longlong)(int)fVar11;
        this->field_0x4ae = (short)(int)fVar11;
        fVar11 = SComponent::cM_rndF(_6157);
        local_20 = (longlong)(int)fVar11;
        this->field_0x4ac = (short)(int)fVar11;
        fVar11 = SComponent::cM_rndF(_6158);
        local_28 = (longlong)(int)fVar11;
        this->field_0x4aa = (short)(int)fVar11;
        fVar11 = SComponent::cM_rndF(_6158);
        local_30 = (longlong)(int)fVar11;
        this->field_0x4a8 = (short)(int)fVar11;
      }
    }
    dr_body_bg_check(this);
    iVar5 = dr_joint_bg_check(this);
    if (iVar5 == 2) {
      react = 2;
    }
  }
  else {
    *(undefined *)((int)&this[1].mpEnemy + 2) = 0;
  }
  fVar11 = 0_0;
  if (((0_0 != this->field_0x478) && (react == 0)) && (((this->mAcch).mFlags & 0x10) != 0)) {
    react = 0x15;
    this->field_0x47c = 0;
    (this->mpEnemy->parent).mVelocity.y = fVar11;
    fVar3 = _6166;
    (this->mpEnemy->parent).mVelocity.x = (this->mpEnemy->parent).mVelocity.x * _6166;
    (this->mpEnemy->parent).mVelocity.z = (this->mpEnemy->parent).mVelocity.z * fVar3;
    if ((this->field_0x70c == 0) && (30_0 < ABS(this->field_0x478))) {
      this->field_0x474 = _6160;
      this->field_0x70e = 0xff;
      if ((this->mpEnemy->parent).mCurrent.mPos.y - this->mSpawnY <=
          _5746 + d_s_play::g_regHIO.mChild[14].mFloats[6]) {
        (this->mpEnemy->parent).mVelocity.z = fVar11;
        (this->mpEnemy->parent).mVelocity.x = fVar11;
        this->field_0x486 = 0x4000;
      }
      else {
        this->field_0x4c8[0] = 10;
        this->field_0x486 = 0;
      }
      iVar5 = kado_check(this);
      if (iVar5 != 0) {
        this->field_0x4c8[0] = 0;
        this->field_0x486 = 0x4000;
        if ((this->mpEnemy->parent).mCurrent.mPos.y - this->mSpawnY <=
            _6167 + d_s_play::g_regHIO.mChild[0].mFloats[6]) {
          iVar10 = 0x8000;
        }
        else {
          iVar10 = 0x10000;
        }
        if (iVar5 == 2) {
          this->field_0x6e0 = this->field_0x6e0 + iVar10;
          local_40.x = _4083 * this->field_0x478;
        }
        else {
          this->field_0x6e0 = this->field_0x6e0 - iVar10;
          local_40.x = _6168 * this->field_0x478;
        }
        local_40.y = 0_0;
        local_40.z = _4083 * this->field_0x478;
        m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)this->field_0x482);
        SComponent::MtxPosition(&local_40,&local_4c);
        (this->mpEnemy->parent).mVelocity.x = local_4c.x;
        (this->mpEnemy->parent).mVelocity.z = local_4c.z;
      }
    }
    this->field_0x478 = 0_0;
    this->field_0x4a8 = 0;
    this->field_0x4aa = 0;
    this->field_0x4ac = 0;
    this->field_0x4ae = 0;
    (this->mParticlePos).x = this->field_0x100[0xc].x;
    (this->mParticlePos).y = this->field_0x100[0xc].y;
    (this->mParticlePos).z = this->field_0x100[0xc].z;
    (this->mParticleAngle).z = 0;
    iVar5 = SComponent::cM_atan2s(-(this->field_0x42c).x,-(this->field_0x42c).z);
    sVar8 = wall_angle_get(this->mpEnemy,iVar5);
    (this->mParticleAngle).y = sVar8;
    (this->mParticleAngle).x = 0x4000;
    (*(code *)((this->mParticleCallBack).vtbl)->end)(&this->mParticleCallBack);
    pJVar7 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,2,0x2022,
                                &this->mParticlePos,&this->mParticleAngle,(cXyz *)0x0,0xb9,
                                &this->mParticleCallBack,(this->mpEnemy->parent).mCurrent.mRoomNo,
                                (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
    if (pJVar7 != (JPABaseEmitter *)0x0) {
      fVar11 = _6155;
      if (this->mEnemyType == 2) {
        fVar11 = 1_0;
      }
      pJVar7->mRate = _4533;
      pJVar7->mSpread = 1_0;
      (pJVar7->mGlobalScale).x = fVar11;
      (pJVar7->mGlobalScale).y = fVar11;
      (pJVar7->mGlobalScale).z = fVar11;
      (pJVar7->mGlobalScale2D).x = fVar11;
      (pJVar7->mGlobalScale2D).y = fVar11;
      (pJVar7->mGlobalScale2D).z = fVar11;
      fVar11 = _4532 * fVar11;
      (pJVar7->mGlobalScale2D).x = fVar11;
      (pJVar7->mGlobalScale2D).y = fVar11;
      (pJVar7->mGlobalScale2D).z = fVar11;
      this->field_0x794 = 6;
    }
  }
  fVar11 = _6169;
  if (((this->mAcch).mFlags & 0x20) != 0) {
    if (((this->field_0x488 == 0) || (react != 0)) ||
       ((this->field_0x70c != 0 && (_5892 < (this->mpEnemy->parent).mVelocity.y)))) {
      if (0_0 != this->field_0x478) {
        this->field_0x420 = 1;
      }
      fVar11 = 0_0;
      this->field_0x478 = 0_0;
      if (this->field_0x6e0 == 0) {
        (this->mpEnemy->parent).mVelocity.z = fVar11;
        (this->mpEnemy->parent).mVelocity.x = fVar11;
      }
      else {
        SComponent::cLib_addCalc0(&(this->mpEnemy->parent).mVelocity.x,1_0,_5128);
        SComponent::cLib_addCalc0(&(this->mpEnemy->parent).mVelocity.z,1_0,_5128);
      }
      (this->mpEnemy->parent).mVelocity.y = _1_0;
      this->field_0x4a8 = 0;
      this->field_0x4aa = 0;
      this->field_0x4ac = 0;
      this->field_0x4ae = 0;
      if (this->field_0x70d != 0) {
        this->field_0x4a8 = 0;
        this->field_0x4aa = 0;
        this->field_0x4ac = 0;
        this->field_0x4ae = 0;
        this->field_0x4a0 = 0;
        this->field_0x4a2 = 0;
        this->field_0x4a4 = 0;
        this->field_0x4a6 = 0;
      }
    }
    else {
      react = 0x14;
      (this->mpEnemy->parent).mVelocity.x = (this->mpEnemy->parent).mVelocity.x * _6169;
      (this->mpEnemy->parent).mVelocity.z = (this->mpEnemy->parent).mVelocity.z * fVar11;
      this->field_0x70e = 0xff;
      if (this->field_0x712 == 0) {
        (this->mpEnemy->parent).mVelocity.y = _4747;
        this->field_0x474 = _6170;
      }
      else {
        (this->mpEnemy->parent).mVelocity.y = _4747;
        this->field_0x474 = _6159 + _4080 * d_s_play::g_regHIO.mChild[0].mFloats[12];
      }
      this->field_0x70c = this->field_0x70c + 1;
      this->field_0x47c = 0;
      this->field_0x420 = d_s_play::g_regHIO.mChild[0].mShorts[3] + 1;
      sVar8 = this->field_0x482;
      sVar4 = (this->mpEnemy->parent).mCurrent.mRot.y - sVar8;
      if (sVar4 < 0) {
        sVar4 = -sVar4;
      }
      if (sVar4 < 0x4000) {
        this->field_0x4c0 = sVar8;
      }
      else {
        this->field_0x4c0 = sVar8 + -0x8000;
      }
      fVar11 = SComponent::cM_rndFX(_6171);
      local_18 = (longlong)(int)fVar11;
      this->field_0x49a = (short)(int)fVar11;
      fVar11 = SComponent::cM_rndFX(_6162);
      local_20 = (longlong)(int)fVar11;
      this->field_0x49c = (short)(int)fVar11;
      fVar11 = SComponent::cM_rndF(_6157);
      local_28 = (longlong)(int)fVar11;
      this->field_0x4b0 = (short)(int)fVar11;
      uVar1 = this->field_0x4b0;
      this->field_0x4b4 = ((short)uVar1 >> 1) + (ushort)((short)uVar1 < 0 && (uVar1 & 1) != 0);
      fVar11 = SComponent::cM_rndF(_6157);
      local_30 = (longlong)(int)fVar11;
      this->field_0x4b2 = (short)(int)fVar11;
      uVar1 = this->field_0x4b2;
      this->field_0x4b6 = ((short)uVar1 >> 1) + (ushort)((short)uVar1 < 0 && (uVar1 & 1) != 0);
      pfVar6 = this->mpEnemy;
      if ((pfVar6->parent).mCurrHp < 1) {
        sVar9 = d_com_inf_game::dComIfGp_getReverb((int)(char)(pfVar6->parent).mCurrent.mRoomNo);
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x580c,&(pfVar6->parent).mEyePos,0,sVar9,1_0,1_0,_1_0,_1_0
                   ,0);
      }
      else {
        if (this->mEnemyType == 3) {
          if ((*(byte *)&pfVar6[1].parent.parent.parent.mLyTg.parent.mpTagData & 1) == 0) {
            sVar9 = d_com_inf_game::dComIfGp_getReverb((int)(char)(pfVar6->parent).mCurrent.mRoomNo)
            ;
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x58ec,&(pfVar6->parent).mEyePos,0,sVar9,1_0,1_0,_1_0,
                       _1_0,0);
          }
          else {
            sVar9 = d_com_inf_game::dComIfGp_getReverb((int)(char)(pfVar6->parent).mCurrent.mRoomNo)
            ;
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x58ee,&(pfVar6->parent).mEyePos,0,sVar9,1_0,1_0,_1_0,
                       _1_0,0);
          }
        }
        else {
          sVar9 = d_com_inf_game::dComIfGp_getReverb((int)(char)(pfVar6->parent).mCurrent.mRoomNo);
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x580b,&(pfVar6->parent).mEyePos,0,sVar9,1_0,1_0,_1_0,
                     _1_0,0);
        }
      }
      iVar5 = kado_check(this);
      if (iVar5 != 0) {
        if (iVar5 == 2) {
          this->field_0x6e0 = this->field_0x6e0 + 0x8000;
          local_40.x = _6172 * this->field_0x478;
        }
        else {
          this->field_0x6e0 = this->field_0x6e0 + -0x8000;
          local_40.x = _6173 * this->field_0x478;
        }
        local_40.y = 0_0;
        local_40.z = _6169 * this->field_0x478;
        m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)this->field_0x482);
        SComponent::MtxPosition(&local_40,&local_4c);
        (this->mpEnemy->parent).mVelocity.x = local_4c.x;
        (this->mpEnemy->parent).mVelocity.z = local_4c.z;
      }
    }
  }
  iVar5 = this->field_0x6e0;
  if (iVar5 != 0) {
    if (iVar5 < 1) {
      this->field_0x6e0 = iVar5 + 0x1000;
      this->field_0x484 = this->field_0x484 + 0x1000;
    }
    else {
      this->field_0x6e0 = iVar5 + -0x1000;
      this->field_0x484 = this->field_0x484 + -0x1000;
    }
  }
  if (this->field_0x70c != 0) {
    if (this->field_0x488 != 0) {
      SComponent::cLib_addCalcAngleS2
                (&(this->mpEnemy->parent).mCurrent.mRot.y,this->field_0x4c0,1,0x500);
    }
    SComponent::cLib_addCalc0
              (&this->field_0x474,1_0,_6149 + 10_0 * d_s_play::g_regHIO.mChild[0].mFloats[5]);
  }
  return react;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x80022440) */
/* __stdcall dr_damage_anime(damagereaction *) */

void dr_damage_anime(damagereaction *this)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  ushort uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  fopEn_enemy_c *pfVar9;
  short sVar10;
  int iVar11;
  int iVar12;
  short unaff_r29;
  int iVar13;
  short unaff_r30;
  int iVar14;
  short maxSpeed;
  int iVar15;
  undefined4 uVar16;
  double dVar17;
  undefined8 in_f31;
  double dVar18;
  csXyz local_104;
  undefined2 local_fc;
  undefined2 local_fa;
  undefined2 local_f8;
  cXyz local_f4;
  cXyz local_e8;
  undefined4 local_d8;
  uint uStack212;
  longlong local_d0;
  longlong local_c8;
  longlong local_c0;
  longlong local_b8;
  longlong local_b0;
  longlong local_a8;
  longlong local_a0;
  double local_98;
  double local_90;
  double local_88;
  double local_80;
  double local_78;
  double local_70;
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  undefined auStack8 [8];
  
  uVar16 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar8 = 0;
  iVar15 = 0x14;
  do {
    iVar13 = (int)this->field_0x10 + iVar8 + -0x10;
    *(undefined2 *)(iVar13 + 0x14) = 0;
    *(undefined2 *)(iVar13 + 0x12) = 0;
    *(undefined2 *)(iVar13 + 0x10) = 0;
    fVar7 = _6449;
    fVar2 = _6448;
    iVar8 = iVar8 + 6;
    iVar15 = iVar15 + -1;
  } while (iVar15 != 0);
  if ((this->field_0x47c == 0) && (test_sw == '\0')) {
    this->field_0x10[6].y = this->field_0x10[6].y + this->field_0x4b8;
    this->field_0x10[7].y = this->field_0x10[7].y - this->field_0x4ba;
    this->field_0x10[4].y = this->field_0x10[4].y + this->field_0x4bc;
    this->field_0x10[5].y = this->field_0x10[5].y - this->field_0x4be;
    maxSpeed = 0x400;
  }
  else {
    maxSpeed = 0x3000;
    uStack212 = (int)(short)((this->field_0x482 + -0x8000) - (this->mpEnemy->parent).mCurrent.mRot.y
                            ) ^ 0x80000000;
    local_d8 = 0x43300000;
    fVar1 = (float)((double)CONCAT44(0x43300000,uStack212) - _4535);
    fVar6 = fVar1;
    if (_6161 < fVar1) {
      fVar6 = _6161;
    }
    if (fVar6 < _6447) {
      fVar6 = _6447;
    }
    iVar8 = (int)(_6448 + _6449 * fVar6);
    local_d0 = (longlong)iVar8;
    this->field_0x10[8].y = (short)iVar8;
    iVar8 = (int)(fVar7 * -fVar6 - fVar2);
    local_c8 = (longlong)iVar8;
    this->field_0x10[4].z = (short)iVar8;
    iVar8 = (int)fVar2;
    local_c0 = (longlong)iVar8;
    sVar10 = (short)iVar8;
    this->field_0x10[8].z = sVar10;
    this->field_0x10[4].y = sVar10;
    fVar6 = _6449;
    fVar7 = _6448;
    fVar2 = fVar1;
    if (_6450 < fVar1) {
      fVar2 = _6450;
    }
    if (fVar2 < _6451) {
      fVar2 = _6451;
    }
    iVar8 = (int)(_6449 * fVar2 - _6448);
    local_b0 = (longlong)iVar8;
    sVar10 = (short)iVar8;
    this->field_0x10[9].y = sVar10;
    this->field_0x10[5].z = sVar10;
    iVar8 = (int)fVar7;
    local_a0 = (longlong)iVar8;
    this->field_0x10[9].z = (short)iVar8;
    fVar5 = -0_0;
    iVar8 = (int)(fVar6 * fVar5 - fVar7);
    local_98 = (double)(longlong)iVar8;
    this->field_0x10[5].y = (short)iVar8;
    fVar7 = _4751;
    fVar2 = fVar1;
    if (_6157 < fVar1) {
      fVar2 = _6157;
    }
    if (fVar2 < _6158) {
      fVar2 = _6158;
    }
    local_90 = (double)(longlong)(int)(_4751 * fVar2);
    sVar10 = (short)(int)(_4751 * fVar2);
    this->field_0x10[0xc].x = sVar10;
    this->field_0x10[0x13].x = sVar10;
    local_80 = (double)(longlong)(int)(fVar7 * fVar5);
    sVar10 = (short)(int)(fVar7 * fVar5);
    this->field_0x10[0xc].z = sVar10;
    this->field_0x10[0x13].z = sVar10;
    dVar18 = _4535;
    fVar2 = fVar1;
    if (_6452 < fVar1) {
      fVar2 = _6452;
    }
    if (fVar2 < _6453) {
      fVar2 = _6453;
    }
    local_70 = (double)CONCAT44(0x43300000,(int)d_s_play::g_regHIO.mChild[0].mShorts[0] ^ 0x80000000
                               );
    iVar8 = (int)((3000_0 - fVar2) + (float)(local_70 - _4535));
    local_68 = (double)(longlong)iVar8;
    this->field_0x10[6].x = (short)iVar8;
    fVar5 = fVar5 - _6454;
    local_60 = (double)CONCAT44(0x43300000,(int)d_s_play::g_regHIO.mChild[0].mShorts[1] ^ 0x80000000
                               );
    iVar8 = (int)(fVar5 + (float)(local_60 - dVar18));
    local_58 = (double)(longlong)iVar8;
    this->field_0x10[6].z = (short)iVar8;
    if (_6162 < fVar1) {
      fVar1 = _6162;
    }
    if (fVar1 < _6455) {
      fVar1 = _6455;
    }
    local_50 = (double)(longlong)(int)(-fVar1 - 3000_0);
    this->field_0x10[7].x = (short)(int)(-fVar1 - 3000_0);
    iVar8 = (int)fVar5;
    local_48 = (double)(longlong)iVar8;
    this->field_0x10[7].z = (short)iVar8;
    local_b8 = local_c0;
    local_a8 = local_b0;
    local_88 = local_90;
    local_78 = local_80;
  }
  SComponent::cLib_addCalcAngleS2(&this->field_0x4a6,this->field_0x4ae,1,0x800);
  SComponent::cLib_addCalcAngleS2(&this->field_0x4a4,this->field_0x4ac,1,0x800);
  SComponent::cLib_addCalcAngleS2(&this->field_0x4a2,this->field_0x4aa,1,0x800);
  SComponent::cLib_addCalcAngleS2(&this->field_0x4a0,this->field_0x4a8,1,0x800);
  SComponent::cLib_addCalcAngleS2(&this->field_0x496,this->field_0x49a,2,0x200);
  SComponent::cLib_addCalcAngleS2(&this->field_0x498,this->field_0x49c,2,0x400);
  uVar4 = this->field_0x4a4;
  this->field_0x10[6].z =
       (this->field_0x10[6].z -
       (((short)uVar4 >> 1) + (ushort)((short)uVar4 < 0 && (uVar4 & 1) != 0))) - this->field_0x4b4;
  this->field_0x10[2].z = this->field_0x10[2].z + this->field_0x4a4 + this->field_0x4b0;
  uVar4 = this->field_0x4a6;
  this->field_0x10[7].z =
       (this->field_0x10[7].z -
       (((short)uVar4 >> 1) + (ushort)((short)uVar4 < 0 && (uVar4 & 1) != 0))) - this->field_0x4b6;
  this->field_0x10[3].z = this->field_0x10[3].z + this->field_0x4a6 + this->field_0x4b2;
  this->field_0x10[0].z = this->field_0x10[0].z + this->field_0x4a0;
  this->field_0x10[1].z = this->field_0x10[1].z + this->field_0x4a2;
  this->field_0x10[0x12].y = this->field_0x10[0x12].y + this->field_0x496;
  this->field_0x10[0xd].y = this->field_0x10[0xd].y + this->field_0x498;
  if (this->field_0x70d != 0) {
    this->field_0x10[0x13].z = this->field_0x10[0x13].z + -0x960;
  }
  if ((this->field_0x70c != 0) && (0_0 < (this->mpEnemy->parent).mVelocity.y)) {
    this->field_0x10[0xc].z = this->field_0x10[0xc].z + -3000;
    this->field_0x10[0x13].z = this->field_0x10[0x13].z + -3000;
  }
  if (this->field_0x470 <= _5610) {
    bVar3 = this->field_0x710;
    if ((bVar3 != 0) || (this->field_0x49e != 0)) {
      maxSpeed = 0x800;
      if ((bVar3 == 1) || ((bVar3 == 5 || (this->field_0x49e != 0)))) {
        if ((bVar3 == 1) || (this->field_0x49e != 0)) {
          if (this->field_0x49e == 0) {
            iVar8 = *(int *)&this->field_0x714;
            pfVar9 = this->mpEnemy;
            local_e8.x = *(float *)(iVar8 + 0x260) - (pfVar9->parent).mCurrent.mPos.x;
            local_e8.y = *(float *)(iVar8 + 0x264) - (_4080 + (pfVar9->parent).mCurrent.mPos.y);
            local_e8.z = *(float *)(iVar8 + 0x268) - (pfVar9->parent).mCurrent.mPos.z;
            iVar8 = SComponent::cM_atan2s(local_e8.x,local_e8.z);
            iVar8 = (int)(short)((short)iVar8 - (this->mpEnemy->parent).mCurrent.mRot.y);
            dVar18 = (double)(local_e8.x * local_e8.x + local_e8.z * local_e8.z);
            if ((double)0_0 < dVar18) {
              dVar17 = 1.0 / SQRT(dVar18);
              dVar17 = _4752 * dVar17 * (_4753 - dVar18 * dVar17 * dVar17);
              dVar17 = _4752 * dVar17 * (_4753 - dVar18 * dVar17 * dVar17);
              dVar18 = (double)(float)(dVar18 * _4752 * dVar17 * (_4753 - dVar18 * dVar17 * dVar17))
              ;
            }
            iVar15 = SComponent::cM_atan2s(local_e8.y,(float)dVar18);
            unaff_r30 = -(short)iVar15;
          }
          else {
            this->field_0x49e = this->field_0x49e + -1;
            maxSpeed = 0x2000;
            iVar8 = (int)((_5129 + d_s_play::g_regHIO.mChild[0].mFloats[6]) *
                         JKernel::JMath::jmaSinTable
                         [(int)((int)this->field_0x49e *
                                (d_s_play::g_regHIO.mChild[0].mShorts[5] + 16000) & 0xffffU) >>
                          (JKernel::JMath::jmaSinShift & 0x3f)]);
            local_48 = (double)(longlong)iVar8;
            unaff_r30 = 0;
          }
        }
        else {
          unaff_r30 = *(short *)&this->field_0x718;
          iVar8 = (int)*(short *)&this->field_0x71a;
        }
        unaff_r29 = (short)iVar8;
        if (unaff_r29 < 0x2001) {
          if (unaff_r29 < -0x2000) {
            unaff_r29 = -0x2000;
          }
        }
        else {
          unaff_r29 = 0x2000;
        }
        if (unaff_r30 < 0x2001) {
          if (unaff_r30 < -0x2000) {
            unaff_r30 = -0x2000;
          }
        }
        else {
          unaff_r30 = 0x2000;
        }
        sVar10 = unaff_r29 >> 2;
        if (this->mEnemyType == 3) {
          this->field_0x10[0xd].x = this->field_0x10[0xd].x + sVar10;
          this->field_0x10[0xd].y = this->field_0x10[0xd].y - (unaff_r30 >> 2);
          this->field_0x10[0x12].x = this->field_0x10[0x12].x + sVar10;
          this->field_0x10[0x12].y = this->field_0x10[0x12].y - (unaff_r30 >> 2);
        }
        else {
          if (this->field_0x710 == 1) {
            if (this->mEnemyType == 2) {
              this->field_0x10[0xd].x = this->field_0x10[0xd].x + unaff_r29;
              this->field_0x10[0xd].y = this->field_0x10[0xd].y - sVar10;
              this->field_0x10[0xd].z = this->field_0x10[0xd].z + unaff_r30;
            }
            else {
              this->field_0x10[0xd].y = this->field_0x10[0xd].y - unaff_r29;
              dVar18 = _4535;
              local_48 = (double)CONCAT44(0x43300000,(int)this->field_0x10[0xc].y ^ 0x80000000);
              local_50 = (double)CONCAT44(0x43300000,(int)unaff_r29 ^ 0x80000000);
              fVar2 = (float)(local_50 - _4535) * _4083;
              iVar8 = (int)((float)(local_48 - _4535) - fVar2);
              local_58 = (double)(longlong)iVar8;
              this->field_0x10[0xc].y = (short)iVar8;
              local_60 = (double)CONCAT44(0x43300000,(int)this->field_0x10[0xc].y ^ 0x80000000);
              iVar8 = (int)((float)(local_60 - dVar18) + fVar2);
              local_68 = (double)(longlong)iVar8;
              this->field_0x10[0xc].x = (short)iVar8;
              this->field_0x10[0xd].z = this->field_0x10[0xd].z + unaff_r30;
            }
          }
          else {
            this->field_0x10[0xd].y = this->field_0x10[0xd].y - unaff_r29;
            this->field_0x10[0xc].x = this->field_0x10[0xc].y + unaff_r29;
            this->field_0x10[0xd].z = this->field_0x10[0xd].z + unaff_r30;
          }
        }
      }
      else {
        if (bVar3 == 3) {
          unaff_r30 = -6000;
          unaff_r29 = -10000;
        }
        else {
          if (bVar3 == 4) {
            unaff_r30 = 6000;
            unaff_r29 = 10000;
          }
          else {
            if (bVar3 == 6) {
              this->field_0x10[0x12].y = this->field_0x10[0x12].y + *(short *)&this->field_0x71a;
              this->field_0x10[0x12].x =
                   this->field_0x10[0x12].x + d_s_play::g_regHIO.mChild[0].mShorts[6];
              this->field_0x10[0x12].z = this->field_0x10[0x12].z + *(short *)&this->field_0x718;
              maxSpeed = 0x300;
            }
          }
        }
      }
      if ((this->field_0x710 == 3) || (this->field_0x710 == 4)) {
        maxSpeed = 0x800;
        this->field_0x10[0xc].x = this->field_0x10[0xc].x - unaff_r30;
        this->field_0x10[0xc].y = this->field_0x10[0xc].y + unaff_r30;
        this->field_0x10[0xd].y = this->field_0x10[0xd].y + unaff_r29;
      }
    }
  }
  else {
    iVar8 = SComponent::cM_atan2s(-(this->field_0x42c).x,-(this->field_0x42c).z);
    local_e8.x = 0_0;
    local_e8.y = 0_0;
    local_e8.z = this->field_0x470;
    m_Do_mtx::mDoMtx_YrotS
              (SComponent::calc_mtx,
               (int)(short)((short)iVar8 - (this->mpEnemy->parent).mCurrent.mRot.y));
    SComponent::MtxPosition(&local_e8,&local_f4);
    fVar7 = _5128;
    dVar18 = _4535;
    fVar2 = _4532;
    if (this->mEnemyType == 2) {
      local_48 = (double)CONCAT44(0x43300000,(int)this->field_0x10[0xc].z ^ 0x80000000);
      iVar8 = (int)((float)(local_48 - _4535) - _5128 * local_f4.z);
      local_50 = (double)(longlong)iVar8;
      this->field_0x10[0xc].z = (short)iVar8;
      local_58 = (double)CONCAT44(0x43300000,(int)this->field_0x10[0xc].y ^ 0x80000000);
      iVar8 = (int)((float)(local_58 - dVar18) + fVar7 * local_f4.x);
      local_60 = (double)(longlong)iVar8;
      this->field_0x10[0xc].y = (short)iVar8;
      fVar2 = _6456;
      local_68 = (double)CONCAT44(0x43300000,(int)this->field_0x10[0xd].y ^ 0x80000000);
      iVar8 = (int)((float)(local_68 - dVar18) + _6456 * local_f4.x);
      local_70 = (double)(longlong)iVar8;
      this->field_0x10[0xd].y = (short)iVar8;
      local_78 = (double)CONCAT44(0x43300000,(int)this->field_0x10[0xd].z ^ 0x80000000);
      iVar8 = (int)((float)(local_78 - dVar18) - fVar2 * local_f4.z);
      local_80 = (double)(longlong)iVar8;
      this->field_0x10[0xd].z = (short)iVar8;
    }
    else {
      if (this->mEnemyType == 3) {
        iVar8 = (int)(local_f4.z * (_4532 + d_s_play::g_regHIO.mChild[8].mFloats[5]));
        local_48 = (double)(longlong)iVar8;
        this->field_0x10[0xd].y = this->field_0x10[0xd].y + (short)iVar8;
        iVar8 = (int)(local_f4.z * (fVar2 + d_s_play::g_regHIO.mChild[8].mFloats[5]));
        local_50 = (double)(longlong)iVar8;
        this->field_0x10[0x12].y = this->field_0x10[0x12].y + (short)iVar8;
        iVar8 = (int)(local_f4.z * (fVar2 + d_s_play::g_regHIO.mChild[8].mFloats[5]));
        local_58 = (double)(longlong)iVar8;
        this->field_0x10[0xc].y = this->field_0x10[0xc].y + (short)iVar8;
        fVar2 = _6457;
        iVar8 = (int)(local_f4.x * (_6457 + d_s_play::g_regHIO.mChild[8].mFloats[6]));
        local_60 = (double)(longlong)iVar8;
        this->field_0x10[0xd].x = this->field_0x10[0xd].x + (short)iVar8;
        iVar8 = (int)(local_f4.x * (fVar2 + d_s_play::g_regHIO.mChild[8].mFloats[6]));
        local_68 = (double)(longlong)iVar8;
        this->field_0x10[0x12].x = this->field_0x10[0x12].x + (short)iVar8;
        iVar8 = (int)(local_f4.x * (fVar2 + d_s_play::g_regHIO.mChild[8].mFloats[6]));
        local_70 = (double)(longlong)iVar8;
        this->field_0x10[0xc].x = this->field_0x10[0xc].x + (short)iVar8;
      }
      else {
        local_48 = (double)CONCAT44(0x43300000,(int)this->field_0x10[0x13].z ^ 0x80000000);
        iVar8 = (int)((float)(local_48 - _4535) - local_f4.z);
        local_50 = (double)(longlong)iVar8;
        this->field_0x10[0x13].z = (short)iVar8;
        local_58 = (double)CONCAT44(0x43300000,(int)this->field_0x10[0x13].y ^ 0x80000000);
        iVar8 = (int)((float)(local_58 - dVar18) + local_f4.x);
        local_60 = (double)(longlong)iVar8;
        this->field_0x10[0x13].y = (short)iVar8;
        local_68 = (double)CONCAT44(0x43300000,(int)this->field_0x10[0xc].z ^ 0x80000000);
        iVar8 = (int)((float)(local_68 - dVar18) - local_f4.z);
        local_70 = (double)(longlong)iVar8;
        this->field_0x10[0xc].z = (short)iVar8;
        local_78 = (double)CONCAT44(0x43300000,(int)this->field_0x10[0xc].y ^ 0x80000000);
        iVar8 = (int)((float)(local_78 - dVar18) + local_f4.x);
        local_80 = (double)(longlong)iVar8;
        this->field_0x10[0xc].y = (short)iVar8;
        fVar2 = _5128;
        local_88 = (double)CONCAT44(0x43300000,(int)this->field_0x10[0xd].y ^ 0x80000000);
        iVar8 = (int)((float)(local_88 - dVar18) + _5128 * local_f4.x);
        local_90 = (double)(longlong)iVar8;
        this->field_0x10[0xd].y = (short)iVar8;
        local_98 = (double)CONCAT44(0x43300000,(int)this->field_0x10[0xd].z ^ 0x80000000);
        iVar8 = (int)((float)(local_98 - dVar18) - fVar2 * local_f4.z);
        local_a0 = (longlong)iVar8;
        this->field_0x10[0xd].z = (short)iVar8;
      }
    }
    maxSpeed = 0x3000;
  }
  if (*(char *)&this->field_0x711 != '\0') {
    this->field_0x10[8].x = 8000;
    this->field_0x10[9].x = -8000;
    maxSpeed = 0x3000;
  }
  if ((this->field_0x6 == 5) || (this->field_0x488 == 1)) {
    SComponent::cLib_addCalcAngleS2((short *)&this->field_0x492,0,4,0x100);
    SComponent::cLib_addCalcAngleS2((short *)&this->field_0x494,0,4,0x100);
  }
  else {
    local_48 = (double)CONCAT44(0x43300000,(int)(this->field_0x48c).z ^ 0x80000000);
    local_e8.x = (float)(local_48 - _4535);
    local_e8.y = 0_0;
    local_50 = (double)CONCAT44(0x43300000,(int)(this->field_0x48c).x ^ 0x80000000);
    local_e8.z = (float)(local_50 - _4535);
    m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)(this->mpEnemy->parent).mCurrent.mRot.y);
    SComponent::MtxPosition(&local_e8,&local_f4);
    local_58 = (double)(longlong)(int)local_f4.x;
    SComponent::cLib_addCalcAngleS2((short *)&this->field_0x492,(short)(int)local_f4.x,4,0x100);
    local_60 = (double)(longlong)(int)local_f4.z;
    SComponent::cLib_addCalcAngleS2((short *)&this->field_0x494,(short)(int)local_f4.z,4,0x100);
  }
  dVar18 = _4535;
  local_48 = (double)CONCAT44(0x43300000,(int)this->field_0x10[0xc].y ^ 0x80000000);
  local_50 = (double)CONCAT44(0x43300000,(int)*(short *)&this->field_0x492 ^ 0x80000000);
  iVar8 = (int)((float)(local_48 - _4535) - (float)(local_50 - _4535));
  local_58 = (double)(longlong)iVar8;
  this->field_0x10[0xc].y = (short)iVar8;
  local_60 = (double)CONCAT44(0x43300000,(int)this->field_0x10[0xc].z ^ 0x80000000);
  local_68 = (double)CONCAT44(0x43300000,(int)*(short *)&this->field_0x494 ^ 0x80000000);
  iVar8 = (int)((float)(local_60 - dVar18) - (float)(local_68 - dVar18));
  local_70 = (double)(longlong)iVar8;
  this->field_0x10[0xc].z = (short)iVar8;
  SComponent::cLib_addCalc0(&this->field_0x470,_4083,_5610);
  if ((0_0 == this->field_0x478) && (this->field_0x488 == 1)) {
    if (this->field_0x70d == 0) {
      if ((*(int *)&this->field_0x3d8 == 0) && (*(int *)&this->field_0x408 == 0)) {
        this->field_0x10[6].z = this->field_0x10[6].z + this->field_0x4b4;
        this->field_0x10[2].z = (this->field_0x10[2].z - this->field_0x4b0) + 13000;
        if (2000 < this->field_0x440) {
          this->field_0x10[2].z = this->field_0x10[2].z + -7000;
        }
      }
      if ((*(int *)&this->field_0x3dc == 0) && (*(int *)&this->field_0x40c == 0)) {
        this->field_0x10[7].z = this->field_0x10[7].z + this->field_0x4b6;
        this->field_0x10[3].z = (this->field_0x10[3].z - this->field_0x4b2) + 13000;
        if (2000 < this->field_0x442) {
          this->field_0x10[3].z = this->field_0x10[3].z + -7000;
        }
      }
    }
    else {
      if (*(int *)&this->field_0x3d0 == 0) {
        this->field_0x10[0].z = this->field_0x10[0].z + -10000;
      }
      if (*(int *)&this->field_0x3d4 == 0) {
        this->field_0x10[1].z = this->field_0x10[1].z + -10000;
      }
    }
  }
  if ((0_0 == this->field_0x478) && (this->field_0x488 == 1)) {
    sVar10 = 1;
    if (this->field_0x70d == 0) {
      sVar10 = -1;
    }
    this->field_0x10[6].z = this->field_0x10[6].z - this->field_0x440 * sVar10;
    this->field_0x10[7].z = this->field_0x10[7].z - this->field_0x442 * sVar10;
    this->field_0x10[4].z = this->field_0x10[4].z - this->field_0x444 * sVar10;
    this->field_0x10[5].z = this->field_0x10[5].z - *(short *)&this->field_0x446 * sVar10;
    uVar4 = this->field_0x448;
    this->field_0x10[0xc].z =
         this->field_0x10[0xc].z +
         sVar10 * (((short)uVar4 >> 1) + (ushort)((short)uVar4 < 0 && (uVar4 & 1) != 0));
    uVar4 = this->field_0x448;
    this->field_0x10[0x13].z =
         this->field_0x10[0x13].z +
         sVar10 * (((short)uVar4 >> 1) + (ushort)((short)uVar4 < 0 && (uVar4 & 1) != 0));
    if (this->field_0x418 == 2) {
      uVar4 = this->field_0x448;
      this->field_0x10[0xd].z =
           this->field_0x10[0xd].z +
           sVar10 * (((short)uVar4 >> 1) + (ushort)((short)uVar4 < 0 && (uVar4 & 1) != 0));
      uVar4 = this->field_0x448;
      this->field_0x10[0x12].z =
           this->field_0x10[0x12].z +
           sVar10 * (((short)uVar4 >> 1) + (ushort)((short)uVar4 < 0 && (uVar4 & 1) != 0));
    }
  }
  sVar10 = this->mEnemyType;
  if (sVar10 == 3) {
    iVar8 = 0;
    iVar15 = 0;
    do {
      if ((iVar8 != 0xd) && (iVar8 != 0x12)) {
        ::csXyz::csXyz(&local_104,0,0,0);
        iVar13 = (int)this->field_0x10 + iVar15 + -0x10;
        *(short *)(iVar13 + 0x10) = local_104.x;
        *(short *)(iVar13 + 0x12) = local_104.y;
        *(short *)(iVar13 + 0x14) = local_104.z;
      }
      iVar8 = iVar8 + 1;
      iVar15 = iVar15 + 6;
    } while (iVar8 < 0x14);
    this->field_0x10[8].z = this->field_0x4bc;
    this->field_0x10[9].z = this->field_0x4be;
    if (this->field_0x47c != 0) {
      if (test_sw != '\0') {
        sVar10 = f_op_actor_mng::fopAcM_searchActorAngleY
                           (&this->mpEnemy->parent,
                            (fopAc_ac_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)
        ;
        this->field_0x482 = sVar10 + d_s_play::g_regHIO.mChild[0].mShorts[3] + -0x8000;
      }
      local_48 = (double)CONCAT44(0x43300000,
                                  -(int)(short)((this->field_0x482 + -0x8000) -
                                               (this->mpEnemy->parent).mCurrent.mRot.y) ^ 0x80000000
                                 );
      fVar2 = (float)(local_48 - _4535);
      fVar7 = fVar2;
      if (_6157 < fVar2) {
        fVar7 = _6157;
      }
      if (fVar7 < _6458) {
        fVar7 = _6458;
      }
      local_50 = (double)(longlong)(int)fVar7;
      this->field_0x10[4].x = (short)(int)fVar7;
      this->field_0x10[8].y = -5000;
      this->field_0x10[8].z = -5000;
      this->field_0x10[0].y = -10000;
      this->field_0x10[4].z = -15000;
      fVar7 = fVar2;
      if (_6159 < fVar2) {
        fVar7 = _6159;
      }
      if (fVar7 < _6158) {
        fVar7 = _6158;
      }
      local_58 = (double)(longlong)(int)fVar7;
      this->field_0x10[5].x = (short)(int)fVar7;
      this->field_0x10[9].y = -5000;
      this->field_0x10[9].z = 5000;
      this->field_0x10[1].y = -10000;
      this->field_0x10[5].z = 15000;
      this->field_0x10[10].y = -15000;
      this->field_0x10[0xb].y = -15000;
      fVar7 = fVar2;
      if (_6162 < fVar2) {
        fVar7 = _6162;
      }
      if (fVar7 < _6453) {
        fVar7 = _6453;
      }
      local_68 = (double)(longlong)(int)fVar7;
      sVar10 = (short)(int)fVar7;
      this->field_0x10[10].z = sVar10;
      this->field_0x10[0xb].z = sVar10;
      this->field_0x10[0xc].y = 5000;
      if (_6170 < fVar2) {
        fVar2 = _6170;
      }
      if (fVar2 < _6459) {
        fVar2 = _6459;
      }
      local_70 = (double)(longlong)(int)fVar2;
      this->field_0x10[0xc].z = (short)(int)fVar2;
      local_60 = local_68;
    }
  }
  else {
    if ((sVar10 < 3) && (0 < sVar10)) {
      this->field_0x10[0].y = -this->field_0x10[0].z;
      this->field_0x10[0].z = 0;
      this->field_0x10[1].y = this->field_0x10[1].z;
      this->field_0x10[1].z = 0;
      if (this->mEnemyType == 2) {
        this->field_0x10[0].y = -this->field_0x10[0].y;
        this->field_0x10[0].x = -this->field_0x10[0].x;
      }
      sVar10 = this->field_0x10[4].z;
      this->field_0x10[4].z = this->field_0x10[4].y;
      this->field_0x10[4].y = -sVar10;
      sVar10 = this->field_0x10[5].z;
      this->field_0x10[5].z = -this->field_0x10[5].y;
      this->field_0x10[5].y = sVar10;
    }
  }
  local_fc = 0;
  local_fa = 0;
  local_f8 = 0;
  iVar13 = 0;
  iVar14 = 0;
  iVar15 = 0;
  iVar8 = 0;
  dVar18 = (double)0_1;
  do {
    dVar17 = _4535;
    if ((((dVar18 < (double)this->field_0x474) &&
         ((((iVar13 == 2 || (iVar13 - 6U < 2)) || (iVar13 == 3)) && ((this->field_0x70e & 8) != 0)))
         ) || ((((iVar13 == 0 || (iVar13 - 4U < 2)) || (iVar13 == 1)) &&
               ((this->field_0x70e & 4) != 0)))) ||
       (((iVar13 == 0x13 && ((this->field_0x70e & 2) != 0)) ||
        ((iVar13 == 0xd && ((this->field_0x70e & 1) != 0)))))) {
      iVar11 = (int)this->field_0x10 + iVar15 + -0x10;
      local_48 = (double)CONCAT44(0x43300000,(int)*(short *)(iVar11 + 0x12) ^ 0x80000000);
      iVar12 = (int)((float)(local_48 - _4535) +
                    (float)((double)this->field_0x474 *
                           (double)JKernel::JMath::jmaSinTable
                                   [(int)(this->mTimer * 5000 + iVar8 & 0xffffU) >>
                                    (JKernel::JMath::jmaSinShift & 0x3f)]));
      local_50 = (double)(longlong)iVar12;
      *(short *)(iVar11 + 0x12) = (short)iVar12;
      local_58 = (double)CONCAT44(0x43300000,(int)*(short *)(iVar11 + 0x14) ^ 0x80000000);
      iVar12 = (int)((float)(local_58 - dVar17) +
                    this->field_0x474 *
                    JKernel::JMath::jmaCosTable
                    [(int)(this->mTimer * 4000 + iVar14 & 0xffffU) >>
                     (JKernel::JMath::jmaSinShift & 0x3f)]);
      local_60 = (double)(longlong)iVar12;
      *(short *)(iVar11 + 0x14) = (short)iVar12;
    }
    iVar12 = (int)this->field_0x10 + iVar15 + -0x10;
    SComponent::cLib_addCalcAngleS2((short *)(iVar12 + 0x88),*(short *)(iVar12 + 0x10),2,maxSpeed);
    SComponent::cLib_addCalcAngleS2((short *)(iVar12 + 0x8a),*(short *)(iVar12 + 0x12),2,maxSpeed);
    SComponent::cLib_addCalcAngleS2((short *)(iVar12 + 0x8c),*(short *)(iVar12 + 0x14),2,maxSpeed);
    iVar13 = iVar13 + 1;
    iVar14 = iVar14 + 0xc80;
    iVar15 = iVar15 + 6;
    iVar8 = iVar8 + 0xed8;
  } while (iVar13 < 0x14);
  __psq_l0(auStack8,uVar16);
  __psq_l1(auStack8,uVar16);
  return;
}


/* __stdcall dr_matrix_set(damagereaction *) */

void dr_matrix_set(damagereaction *this)

{
  fopEn_enemy_c *pEnemy;
  cXyz cStack40;
  cXyz local_1c [2];
  
  pEnemy = this->mpEnemy;
  SComponent::MtxTrans
            ((double)((pEnemy->parent).mCurrent.mPos.x + (this->field_0x458).x),
             (double)((pEnemy->parent).mCurrent.mPos.y + (this->field_0x458).y),
             (double)((pEnemy->parent).mCurrent.mPos.z + (this->field_0x458).z),false);
  m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,(this->field_0x48c).x);
  m_Do_mtx::mDoMtx_ZrotM(SComponent::calc_mtx,(this->field_0x48c).z);
  SComponent::MtxTrans
            (-(double)(this->field_0x44c).x,-(double)(this->field_0x44c).y,
             -(double)(this->field_0x44c).z,true);
  m_Do_mtx::mDoMtx_YrotM(SComponent::calc_mtx,this->field_0x482);
  m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,this->field_0x480);
  m_Do_mtx::mDoMtx_YrotM(SComponent::calc_mtx,this->field_0x484);
  m_Do_mtx::mDoMtx_YrotM(SComponent::calc_mtx,-this->field_0x482);
  SComponent::MtxTrans
            ((double)(this->field_0x44c).x,(double)(this->field_0x44c).y,
             (double)(this->field_0x44c).z,true);
  m_Do_mtx::mDoMtx_YrotM(SComponent::calc_mtx,(this->mpEnemy->parent).mCollisionRot.y);
  m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,(this->mpEnemy->parent).mCollisionRot.x);
  m_Do_mtx::mDoMtx_ZrotM(SComponent::calc_mtx,(this->mpEnemy->parent).mCollisionRot.z);
  SComponent::MtxTrans((double)0_0,(double)this->field_0x468,(double)this->field_0x46c,true);
  local_1c[0].x = 0_0;
  local_1c[0].y = 0_0;
  local_1c[0].z = _6162;
  SComponent::MtxPosition(local_1c,&cStack40);
  if ((this->mpEnemy->parent).mCurrent.mPos.y <= cStack40.y) {
    this->field_0x70d = 0;
  }
  else {
    this->field_0x70d = 1;
  }
  this->field_0x424 = 0;
  return;
}


/* __stdcall damage_reaction(damagereaction *) */

undefined4 damage_reaction(damagereaction *this)

{
  short sVar1;
  int iVar2;
  undefined4 react;
  int iVar3;
  
  this->mTimer = this->mTimer + 1;
  iVar2 = 0;
  iVar3 = 3;
  do {
    sVar1 = *(short *)((int)this->field_0x4c8 + iVar2);
    if (sVar1 != 0) {
      *(short *)((int)this->field_0x4c8 + iVar2) = sVar1 + -1;
    }
    iVar2 = iVar2 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (this->mInvincibleTimer == 0) {
    react = dr_damage_set(this);
  }
  else {
    this->mInvincibleTimer = this->mInvincibleTimer + -1;
    this->mSpawnY = (this->mpEnemy->parent).mCurrent.mPos.y;
    react = 0;
  }
  dr_damage_anime(this);
  dr_matrix_set(this);
  if ((this->field_0x794 != 0) &&
     (this->field_0x794 = this->field_0x794 + -1, this->field_0x794 == 0)) {
    (*(code *)((this->mParticleCallBack).vtbl)->end)(&this->mParticleCallBack);
  }
  if (this->field_0x7b2 != 0) {
    this->field_0x7b2 = this->field_0x7b2 + -1;
  }
  return react;
}


void __sinit_c_damagereaction_cpp(void)

{
  non_pos.x = _6158;
  non_pos.y = _6158;
  non_pos.z = _6157;
  Runtime.PPCEABI.H::__register_global_object(&non_pos,::cXyz::_cXyz,&_4036);
  return;
}

}

/* [thunk]:__thiscall cBgS_LinChk::~cBgS_LinChk(void) */

void __thiscall cBgS_LinChk::_cBgS_LinChk(cBgS_LinChk *this)

{
  _cBgS_LinChk((cBgS_LinChk *)&this[-1].field_0x40.y);
  return;
}


/* [thunk]:__thiscall dBgS_Chk::~dBgS_Chk(void) */

void __thiscall dBgS_Chk::_dBgS_Chk(dBgS_Chk *this)

{
  _dBgS_Chk((dBgS_Chk *)&this[-1].mPolyPassChk.parent.mbBombThrough);
  return;
}


/* [thunk]:__thiscall dBgS_LinChk::~dBgS_LinChk(void) */

void __thiscall dBgS_LinChk::_dBgS_LinChk(dBgS_LinChk *this)

{
  _dBgS_LinChk((dBgS_LinChk *)&this[-1].mPolyPassChk);
  return;
}


/* [thunk]:__thiscall dBgS_LinChk::~dBgS_LinChk(void) */

void __thiscall dBgS_LinChk::_dBgS_LinChk(dBgS_LinChk *this)

{
  _dBgS_LinChk((dBgS_LinChk *)&this[-1].parent.parent.mProcID);
  return;
}


/* [thunk]:__thiscall dBgS_LinChk::~dBgS_LinChk(void) */

void __thiscall dBgS_LinChk::_dBgS_LinChk(dBgS_LinChk *this)

{
  _dBgS_LinChk((dBgS_LinChk *)&this[-1].parent.mPolyInfo);
  return;
}


/* [thunk]:__thiscall dBgS_GndChk::~dBgS_GndChk(void) */

void __thiscall dBgS_GndChk::_dBgS_GndChk(dBgS_GndChk *this)

{
  _dBgS_GndChk((dBgS_GndChk *)&this[-1].mPolyPassChk);
  return;
}


/* [thunk]:__thiscall dBgS_GndChk::~dBgS_GndChk(void) */

void __thiscall dBgS_GndChk::_dBgS_GndChk(dBgS_GndChk *this)

{
  _dBgS_GndChk((dBgS_GndChk *)&this[-1].parent.parent.mProcID);
  return;
}


/* [thunk]:__thiscall dBgS_GndChk::~dBgS_GndChk(void) */

void __thiscall dBgS_GndChk::_dBgS_GndChk(dBgS_GndChk *this)

{
  _dBgS_GndChk((dBgS_GndChk *)&this[-1].parent.mPolyInfo);
  return;
}


/* [thunk]:__thiscall cBgS_GndChk::~cBgS_GndChk(void) */

void __thiscall cBgS_GndChk::_cBgS_GndChk(cBgS_GndChk *this)

{
  _cBgS_GndChk((cBgS_GndChk *)&this[-1].mPos.z);
  return;
}


/* [thunk]:__thiscall dBgS_ObjGndChk_Yogan::~dBgS_ObjGndChk_Yogan(void) */

void __thiscall dBgS_ObjGndChk_Yogan::_dBgS_ObjGndChk_Yogan(dBgS_ObjGndChk_Yogan *this)

{
  _dBgS_ObjGndChk_Yogan(this + -0x14);
  return;
}


/* [thunk]:__thiscall dBgS_ObjGndChk_Yogan::~dBgS_ObjGndChk_Yogan(void) */

void __thiscall dBgS_ObjGndChk_Yogan::_dBgS_ObjGndChk_Yogan(dBgS_ObjGndChk_Yogan *this)

{
  _dBgS_ObjGndChk_Yogan(this + -0x4c);
  return;
}


/* [thunk]:__thiscall dBgS_ObjGndChk_Yogan::~dBgS_ObjGndChk_Yogan(void) */

void __thiscall dBgS_ObjGndChk_Yogan::_dBgS_ObjGndChk_Yogan(dBgS_ObjGndChk_Yogan *this)

{
  _dBgS_ObjGndChk_Yogan(this + -0x40);
  return;
}

