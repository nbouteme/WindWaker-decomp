#include <d_cc_uty.h>
#include <d_cc_d.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_cc_uty.h>
#include <d_com_inf_game.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_a_bomb_static.h>
#include <mtx/vec.h>
#include <SComponent/c_math.h>
#include <f_op_actor_mng.h>
#include <d_particle.h>


namespace d_cc_uty {

/* __stdcall cc_pl_cut_bit_get(void) */

undefined4 cc_pl_cut_bit_get(void)

{
  daPy_py_c__PlayerAttackState dVar1;
  
  dVar1 = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).mAttackState;
  if (dVar1 == SwordAttackingLockedOn) {
    return 1;
  }
  if (dVar1 == 2) {
    return 2;
  }
  if (dVar1 == 3) {
    return 4;
  }
  if (dVar1 == SwordAttackingNotLockedOn) {
    return 8;
  }
  if (dVar1 == JumpParrying) {
    return 0x10;
  }
  if (dVar1 == 6) {
    return 0x20;
  }
  if (dVar1 == 7) {
    return 0x40;
  }
  if ((dVar1 != SpinAttackingS) && (dVar1 != HurricaneSpinning)) {
    if (dVar1 != JumpAttacking) {
      return 0;
    }
    return 0x100;
  }
  return 0x80;
}


/* __stdcall at_se_get(cCcD_Obj *) */

undefined4 at_se_get(cCcD_Obj *param_1)

{
  byte bVar1;
  dCcD_GObjInf *pObjInf;
  undefined4 uVar2;
  
  pObjInf = d_cc_d::dCcD_GetGObjInf(param_1);
  if (((pObjInf->parent).parent.parent.mObjAt.mDamageTypes & (SkullHammer|StalfosMace)) == 0) {
    bVar1 = (pObjInf->mObjAt).mSeType;
    if (bVar1 == 4) {
      uVar2 = 0x2833;
    }
    else {
      if (bVar1 == 5) {
        uVar2 = 0x2834;
      }
      else {
        if (bVar1 == 7) {
          uVar2 = 0x2879;
        }
        else {
          uVar2 = 0x2803;
          if (bVar1 == 8) {
            uVar2 = 0x286f;
          }
        }
      }
    }
  }
  else {
    uVar2 = 0x2855;
  }
  return uVar2;
}


/* __stdcall at_se_getC(cCcD_Obj *) */

undefined4 at_se_getC(cCcD_Obj *param_1)

{
  byte bVar1;
  dCcD_GObjInf *pdVar2;
  undefined4 uVar3;
  
  pdVar2 = d_cc_d::dCcD_GetGObjInf(param_1);
  if (((pdVar2->parent).parent.parent.mObjAt.mDamageTypes & (SkullHammer|StalfosMace)) == 0) {
    bVar1 = (pdVar2->mObjAt).mSeType;
    if (bVar1 == 4) {
      uVar3 = 0x2835;
    }
    else {
      if (bVar1 == 5) {
        uVar3 = 0x2836;
      }
      else {
        if (bVar1 == 7) {
          uVar3 = 0x2879;
        }
        else {
          uVar3 = 0x2806;
          if (bVar1 == 8) {
            uVar3 = 0x286f;
          }
        }
      }
    }
  }
  else {
    uVar3 = 0x2855;
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall def_se_set(fopAc_ac_c *,
                        cCcD_Obj *,
                        unsigned long) */

void def_se_set(fopAc_ac_c *param_1,cCcD_Obj *param_2,ulong param_3)

{
  ulong soundId;
  sbyte sVar1;
  
  soundId = at_se_get(param_2);
  sVar1 = d_com_inf_game::dComIfGp_getReverb((int)(char)(param_1->mCurrent).mRoomNo);
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,soundId,&param_1->mEyePos,param_3,sVar1,1_0,1_0,_1_0,_1_0,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall def_se_set_p(fopAc_ac_c *,
                          cXyz *,
                          cCcD_Obj *,
                          unsigned long) */

void def_se_set_p(int param_1,cXyz *param_2,undefined4 param_3,ulong param_4)

{
  sbyte sVar1;
  ulong soundId;
  
  sVar1 = d_com_inf_game::dComIfGp_getReverb((int)*(char *)(param_1 + 0x20a));
  soundId = at_se_get(param_3);
  JAIZelBasic::seStart(JAIZelBasic::zel_basic,soundId,param_2,param_4,sVar1,1_0,1_0,_1_0,_1_0,0);
  return;
}


/* __stdcall at_power_check(CcAtInfo *) */

void at_power_check(CcAtInfo *pDst)

{
  byte bVar1;
  daPy_py_c__PlayerAttackState dVar2;
  daPy_lk_c *pdVar3;
  fopAc_ac_c *pfVar4;
  dCcD_Stts *pdVar5;
  daBomb_c *pActor;
  undefined2 uVar8;
  char cVar9;
  uint uVar6;
  dCcD_GObjInf *pdVar7;
  cCcD_Obj__DamageTypes damageType;
  short procName;
  
  pdVar3 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  if (pDst->mpObj != (cCcD_Obj *)0x0) {
    pdVar5 = pDst->mpObj->mpStts;
    if (pdVar5 == (dCcD_Stts *)0x0) {
      pfVar4 = (fopAc_ac_c *)0x0;
    }
    else {
      pfVar4 = (pdVar5->parent).mpActor;
    }
    pDst->mpActor = pfVar4;
    pDst->mResultingAttackType = 0xc;
    pDst->mDamage = 0;
    damageType = (pDst->mpObj->parent).mObjAt.mDamageTypes;
    if ((damageType & Water) == 0) {
      if ((damageType & DekuLeafWind) == 0) {
        if ((damageType & 0x20000) == 0) {
          if ((damageType & (Fire|FireArrows)) != 0) {
            pDst->mResultingAttackType = 5;
          }
          if (pDst->mpActor != (fopAc_ac_c *)0x0) {
            pDst->mDamage = (pDst->mpObj->parent).mObjAt.mDamage;
            pActor = (daBomb_c *)pDst->mpActor;
            procName = (pActor->parent).parent.parent.mProcName;
            if (procName == 0xa9) {
              if (((pDst->mpObj->parent).mObjAt.mDamageTypes & SkullHammer) == 0) {
                pDst->mResultingAttackType = 1;
                uVar8 = cc_pl_cut_bit_get();
                pDst->mPlCutBit = uVar8;
                bVar1 = (pdVar3->parent).field_0x291;
                if (bVar1 == 3) {
                  pDst->mHitSoundId = 1;
                }
                else {
                  if (bVar1 == 4) {
                    pDst->mHitSoundId = 4;
                  }
                  else {
                    dVar2 = (pdVar3->parent).mAttackState;
                    if (dVar2 == JumpAttacking) {
                      pDst->mHitSoundId = 2;
                    }
                    else {
                      if (((dVar2 == JumpParrying) || (dVar2 == RollParrying)) || (dVar2 == 0x10)) {
                        pDst->mHitSoundId = 3;
                      }
                      else {
                        pDst->mHitSoundId = 0;
                      }
                    }
                  }
                }
              }
              else {
                pDst->mResultingAttackType = 9;
              }
            }
            else {
              if (procName == 0x128) {
                cVar9 = daBomb_c::chk_state(pActor,8);
                if (cVar9 == '\0') {
                  pDst->mResultingAttackType = 2;
                }
                else {
                  pDst->mResultingAttackType = 0xd;
                }
                pDst->mPlCutBit = 0x200;
              }
              else {
                if (procName == 0x129) {
                  pDst->mResultingAttackType = 2;
                  pDst->mPlCutBit = 0x200;
                }
                else {
                  if (procName == 0x1c4) {
                    pDst->mResultingAttackType = 0xe;
                    pDst->mPlCutBit = 0x400;
                  }
                  else {
                    if (procName == 0x1b4) {
                      pDst->mResultingAttackType = 10;
                      pDst->mPlCutBit = 0x800;
                    }
                    else {
                      if (procName == 0x1de) {
                        pDst->mPlCutBit = 0x1000;
                      }
                      else {
                        if (procName == 0xf0) {
                          pDst->mResultingAttackType = 0xb;
                        }
                        else {
                          if (procName == 0x1cb) {
                            uVar6 = ::daObj::PrmAbstract((fopAc_ac_c *)pActor,4,0x18);
                            if (uVar6 == 2) {
                              pDst->mResultingAttackType = 4;
                            }
                            else {
                              pDst->mResultingAttackType = 3;
                            }
                          }
                          else {
                            if (procName == 0xbd) {
                              pDst->mResultingAttackType = 7;
                              if (2 < pDst->mDamage) {
                                pDst->mDamage = 2;
                              }
                            }
                            else {
                              if (procName == 0xd9) {
                                pDst->mResultingAttackType = 6;
                                pDst->mDamage = 4;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          pDst->mbDead = 0;
          if ((pDst->mpActor->parent).parent.mProcName == 0xa9) {
            pdVar7 = d_cc_d::dCcD_GetGObjInf(pDst->mpObj);
            if ((pdVar7->mObjAt).mSpl == 1) {
              pDst->mbDead = 1;
            }
          }
          else {
            if (1 < pDst->mDamage) {
              pDst->mbDead = 1;
            }
          }
        }
        else {
          pDst->mResultingAttackType = 5;
        }
      }
      else {
        pDst->mResultingAttackType = 8;
      }
    }
    else {
      pDst->mResultingAttackType = 4;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall cc_at_check(fopAc_ac_c *,
                         CcAtInfo *) */

fopAc_ac_c * cc_at_check(fopAc_ac_c *pActor,CcAtInfo *pDst)

{
  float fVar1;
  short sVar2;
  byte bVar3;
  fopAc_ac_c *pfVar4;
  int iVar5;
  sbyte sVar7;
  ulong uVar6;
  ulong uVar8;
  double dVar9;
  double dVar10;
  float fVar11;
  csXyz local_24;
  cXyz local_1c;
  
  pDst->mHitSoundId = 0;
  pfVar4 = (fopAc_ac_c *)pDst;
  at_power_check(pDst);
  pDst->mpActor = pfVar4;
  if (pDst->mpActor != (fopAc_ac_c *)0x0) {
    JAIZelBasic::onEnemyDamage(JAIZelBasic::zel_basic);
    fVar11 = mtx::PSVECSquareMag(&pDst->mpActor->mVelocity);
    dVar10 = (double)fVar11;
    if ((double)_4444 < dVar10) {
      dVar9 = 1.0 / SQRT(dVar10);
      dVar9 = _4445 * dVar9 * (_4446 - dVar10 * dVar9 * dVar9);
      dVar9 = _4445 * dVar9 * (_4446 - dVar10 * dVar9 * dVar9);
      dVar10 = (double)(float)(dVar10 * _4445 * dVar9 * (_4446 - dVar10 * dVar9 * dVar9));
    }
    if (dVar10 <= (double)50_0) {
      fVar11 = (pActor->mCurrent).mPos.x - (pDst->mpActor->mCurrent).mPos.x;
      fVar1 = (pActor->mCurrent).mPos.z - (pDst->mpActor->mCurrent).mPos.z;
    }
    else {
      fVar11 = (pDst->mpActor->mVelocity).x;
      fVar1 = (pDst->mpActor->mVelocity).z;
    }
    iVar5 = SComponent::cM_atan2s(-fVar11,-fVar1);
    pDst->field_0xe = (short)iVar5;
    if ((((pDst->mpObj->parent).mObjAt.mDamageTypes & 0x8000) != 0) &&
       ((pActor->mStatus & 0x380000) != 0)) {
      pDst->mDamage = 0;
    }
    if ((pDst->mpActor->parent).parent.mProcName == 0x1c4) {
      if (pActor->mItemStealLeft != 0) {
        pActor->mItemStealLeft = pActor->mItemStealLeft - 1;
        f_op_actor_mng::fopAcM_createStealItem
                  (&pActor->mCurrent,pActor->mItemTableIdx,(int)(char)(pActor->mCurrent).mRoomNo,0,
                   pActor->mItemStealNum);
        pActor->mItemStealNum = pActor->mItemStealNum + 1;
        pDst->mDamage = 0;
      }
    }
    if ('\0' < (char)pDst->mDamage) {
      pActor->mCurrHp = pActor->mCurrHp - pDst->mDamage;
    }
    if (pActor->mCurrHp < 1) {
      pDst->mbDead = 1;
      sVar7 = d_com_inf_game::dComIfGp_getReverb((int)(char)(pActor->mCurrent).mRoomNo);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x2828,&pActor->mEyePos,0,sVar7,1_0,1_0,_1_0,_1_0,0);
      bVar3 = (char)d_s_play::g_regHIO.mChild[0].mShorts[7] + 6;
      if (pDst->pParticlePos != (cXyz *)0x0) {
        dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x10,
                           pDst->pParticlePos,(csXyz *)0x0,(cXyz *)0x0,0xff,
                           (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0)
        ;
        local_1c.z = 2_0;
        local_1c.y = 2_0;
        local_1c.x = 2_0;
        local_24.z = 0;
        local_24.x = 0;
        local_24.y = f_op_actor_mng::fopAcM_searchActorAngleY
                               (pActor,(fopAc_ac_c *)
                                       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor);
        dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0xd,
                           pDst->pParticlePos,&local_24,&local_1c,0xff,(dPa_levelEcallBack *)0x0,-1,
                           (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
      }
    }
    else {
      sVar2 = (pActor->parent).parent.mProcName;
      uVar8 = 0x20;
      if (sVar2 == 0xbf) {
        uVar8 = 0x33;
      }
      if (pDst->mbDead == 0) {
        if (sVar2 == 0xd9) {
          if (*(char *)&pActor[1].mStatus == '\x02') {
            sVar7 = d_com_inf_game::dComIfGp_getReverb((int)(char)(pActor->mCurrent).mRoomNo);
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x693a,&pActor->mEyePos,0,sVar7,1_0,1_0,_1_0,_1_0,0);
          }
          else {
            uVar6 = at_se_get(pDst->mpObj);
            sVar7 = d_com_inf_game::dComIfGp_getReverb((int)(char)(pActor->mCurrent).mRoomNo);
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,uVar6,&pActor->mEyePos,uVar8,sVar7,1_0,1_0,_1_0,_1_0,0
                      );
          }
        }
        else {
          uVar6 = at_se_get(pDst->mpObj);
          sVar7 = d_com_inf_game::dComIfGp_getReverb((int)(char)(pActor->mCurrent).mRoomNo);
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,uVar6,&pActor->mEyePos,uVar8,sVar7,1_0,1_0,_1_0,_1_0,0);
        }
        bVar3 = (char)d_s_play::g_regHIO.mChild[0].mShorts[5] + 1;
      }
      else {
        uVar6 = at_se_getC(pDst->mpObj);
        sVar7 = d_com_inf_game::dComIfGp_getReverb((int)(char)(pActor->mCurrent).mRoomNo);
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,uVar6,&pActor->mEyePos,uVar8,sVar7,1_0,1_0,_1_0,_1_0,0);
        if (pDst->mResultingAttackType == 9) {
          bVar3 = 6;
        }
        else {
          bVar3 = (char)d_s_play::g_regHIO.mChild[0].mShorts[6] + 4;
        }
      }
    }
    if (pDst->mResultingAttackType == 1) {
      dScnPly_ply_c::nextPauseTimer = bVar3;
    }
    if (pDst->mDamage != 0) {
      JAIZelBasic::bgmHitSound(JAIZelBasic::zel_basic,pDst->mHitSoundId);
    }
  }
  return pDst->mpActor;
}

}

namespace daObj {

/* __thiscall PrmAbstract<daTsubo::Act_c::Prm_e>(fopAc_ac_c const *,
                                                        daTsubo::Act_c::Prm_e,
                                                        daTsubo::Act_c::Prm_e) */

uint PrmAbstract(fopAc_ac_c *param_1,Prm_e param_2,Prm_e param_3)

{
  return (1 << param_2) - 1U & (uint)(param_1->parent).parent.mParameters >> param_3;
}

