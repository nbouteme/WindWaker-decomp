#include <d_cc_s.h>
#include <SComponent/c_cc_s.h>
#include <d_cc_mass_s.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <mtx/vec.h>
#include <SComponent/c_math.h>
#include <SComponent/c_lib.h>
#include <d_cc_d.h>
#include <d_cc_s.h>
#include <SComponent/c_cc_d.h>
#include <SComponent/c_m3d.h>
#include <d_particle.h>
#include <d_kankyo.h>
#include <dCcS.h>
#include <cCcS.h>


/* __thiscall dCcS::Ct(void) */

void __thiscall dCcS::Ct(dCcS *this)

{
  cCcS::Ct(&this->parent);
  dCcMassS_Mng::Ct(&this->mMassMng);
  return;
}


/* __thiscall dCcS::Dt(void) */

void __thiscall dCcS::Dt(dCcS *this)

{
  cCcS::Dt(&this->parent);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dCcS::ChkShieldFrontRange(cCcD_Obj *,
                                        cCcD_Obj *) */

undefined4 __thiscall dCcS::ChkShieldFrontRange(dCcS *this,cCcD_Obj *pAt,cCcD_Obj *pTg)

{
  dCcD_GObjInf *pAtInf;
  undefined4 uVar1;
  dCcD_Stts *pdVar2;
  dCcD_GObjInf *pTgInf;
  int iVar3;
  short sVar4;
  short *psVar5;
  fopAc_ac_c *pTgAc;
  fopAc_ac_c *pAtAc;
  float fVar6;
  cXyz delta;
  
  pAtInf = (dCcD_GObjInf *)(*(code *)((pAt->parent).vtbl)->GetGObjInf_1)(pAt);
  if (pAtInf == (dCcD_GObjInf *)0x0) {
    uVar1 = 0;
  }
  else {
    pdVar2 = (pAtInf->parent).parent.mpStts;
    if (pdVar2 == (dCcD_Stts *)0x0) {
      pAtAc = (fopAc_ac_c *)0x0;
    }
    else {
      pAtAc = (pdVar2->parent).mpActor;
    }
    if (pAtAc == (fopAc_ac_c *)0x0) {
      uVar1 = 0;
    }
    else {
      pTgInf = (dCcD_GObjInf *)(*(code *)((pTg->parent).vtbl)->GetGObjInf_1)(pTg);
      if (pTgInf == (dCcD_GObjInf *)0x0) {
        uVar1 = 0;
      }
      else {
        pdVar2 = (pTgInf->parent).parent.mpStts;
        if (pdVar2 == (dCcD_Stts *)0x0) {
          pTgAc = (fopAc_ac_c *)0x0;
        }
        else {
          pTgAc = (pdVar2->parent).mpActor;
        }
        if (pTgAc == (fopAc_ac_c *)0x0) {
          uVar1 = 0;
        }
        else {
          mtx::PSVECSubtract(&pAtAc->mEyePos,&pTgAc->mEyePos,&delta);
          fVar6 = mtx::PSVECMag(&delta);
          if (SComponent::G_CM3D_F_ABS_MIN <= ABS(fVar6)) {
            mtx::PSVECNormalize(&delta,&delta);
            iVar3 = SComponent::cM_atan2s(delta.x,delta.z);
            psVar5 = (pTgInf->mObjTg).mpRotY;
            if (psVar5 == (short *)0x0) {
              sVar4 = (pTgAc->mCollisionRot).y;
            }
            else {
              sVar4 = *psVar5;
            }
            sVar4 = SComponent::cLib_distanceAngleS((short)iVar3,sVar4);
            if (sVar4 < 0x4001) {
              uVar1 = 1;
            }
            else {
              uVar1 = 0;
            }
          }
          else {
            uVar1 = 0;
          }
        }
      }
    }
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dCcS::ChkShield(cCcD_Obj *,
                              cCcD_Obj *,
                              dCcD_GObjInf *,
                              dCcD_GObjInf *) */

int __thiscall
dCcS::ChkShield(dCcS *this,cCcD_Obj *pAt,cCcD_Obj *pTg,dCcD_GObjInf *pAtInf,dCcD_GObjInf *pTgInf)

{
  char cVar1;
  int ret;
  uint tgFlag;
  
  cVar1 = dCcD_GObjInf::ChkAtNoGuard(pAtInf);
  if (cVar1 == '\0') {
    tgFlag = (pTgInf->mObjTg).parent.mGFlag;
    if ((tgFlag & 1) == 0) {
      ret = 0;
    }
    else {
      if ((tgFlag & 8) == 0) {
        ret = 1;
      }
      else {
        ret = ChkShieldFrontRange(this,pAt,pTg);
      }
    }
  }
  else {
    ret = 0;
  }
  return ret;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dCcS::CalcTgPlusDmg(cCcD_Obj *,
                                  cCcD_Obj *,
                                  cCcD_Stts *,
                                  cCcD_Stts *) */

void __thiscall
dCcS::CalcTgPlusDmg(dCcS *this,cCcD_Obj *pAt,cCcD_Obj *pTg,cCcD_Stts *pAtStts,cCcD_Stts *pTgStts)

{
  dCcD_GObjInf *pAtObj;
  dCcD_GObjInf *pTgObj;
  uint uVar1;
  byte dmg;
  
  pAtObj = (dCcD_GObjInf *)(*(code *)((pAt->parent).vtbl)->GetGObjInf_1)(pAt);
  pTgObj = (dCcD_GObjInf *)(*(code *)((pTg->parent).vtbl)->GetGObjInf_1)(pTg);
  uVar1 = ChkShield(this,pAt,pTg,pAtObj,pTgObj);
  if (((uVar1 & 0xff) == 0) &&
     (dmg = (pAt->parent).mObjAt.mDamage, pTgStts->mReceiveDamageAmount < dmg)) {
    pTgStts->mReceiveDamageAmount = dmg;
  }
  return;
}


/* __thiscall dCcS::ChkAtTgHitAfterCross(bool,
                                         bool,
                                         cCcD_GObjInf const *,
                                         cCcD_GObjInf const *,
                                         cCcD_Stts *,
                                         cCcD_Stts *,
                                         cCcD_GStts *,
                                         cCcD_GStts *) */

undefined4 __thiscall
dCcS::ChkAtTgHitAfterCross
          (dCcS *this,bool bAt,bool bTg,dCcD_GObjInf *pAtInf,dCcD_GObjInf *pTgInf,dCcD_Stts *pAtStts
          ,dCcD_Stts *pTgStts,dCcD_GStts *pAtGStts,dCcD_GStts *pTgGStts)

{
  uint uVar1;
  
  uVar1 = (pAtStts->parent).mActorProcID;
  if (bAt != false) {
    pAtGStts->mTgProcID = (pTgStts->parent).mActorProcID;
    if (((pAtInf->mObjAt).parent.mGFlag & 1) != 0) {
      if (pAtGStts->mOldTgProcID == (pTgStts->parent).mActorProcID) {
        return 1;
      }
    }
  }
  if (bTg != false) {
    pTgGStts->mAtProcID = uVar1;
    if (((((pTgInf->mObjTg).parent.mGFlag & 2) != 0) && (((pAtInf->mObjAt).parent.mGFlag & 4) == 0))
       && (pTgGStts->mOldAtProcID == (pAtStts->parent).mActorProcID)) {
      return 1;
    }
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dCcS::SetCoGObjInf(bool,
                                 bool,
                                 cCcD_GObjInf *,
                                 cCcD_GObjInf *,
                                 cCcD_Stts *,
                                 cCcD_Stts *,
                                 cCcD_GStts *,
                                 cCcD_GStts *) */

void __thiscall
dCcS::SetCoGObjInf(dCcS *this,bool bCo1,bool bCo2,dCcD_GObjInf *pCo1,dCcD_GObjInf *pCo2,
                  dCcD_Stts *pStts1,dCcD_Stts *pStts2,dCcD_GStts *pGStts1,dCcD_GStts *pGStts2)

{
  dCcD_Stts *pdVar1;
  fopAc_ac_c *pfVar2;
  fopAc_ac_c *pfVar3;
  code *pcVar4;
  
  if (bCo1 != false) {
    (pCo1->mObjCo).parent.mActorProcID = (pStts2->parent).mActorProcID;
    (pCo1->mObjCo).parent.mpActor = (fopAc_ac_c *)0x0;
    if ((pGStts2->mFlags & 1) != 0) {
      (pCo1->mObjCo).parent.mStatus = (pCo1->mObjCo).parent.mStatus | Hit;
    }
  }
  if (bCo2 != false) {
    (pCo2->mObjCo).parent.mActorProcID = (pStts1->parent).mActorProcID;
    (pCo2->mObjCo).parent.mpActor = (fopAc_ac_c *)0x0;
    if ((pGStts1->mFlags & 1) != 0) {
      (pCo2->mObjCo).parent.mStatus = (pCo2->mObjCo).parent.mStatus | Hit;
    }
  }
  if (bCo1 != false) {
    pcVar4 = (code *)(pCo1->mObjCo).parent.mpCallback;
    if (pcVar4 != (code *)0x0) {
      pdVar1 = (pCo1->parent).parent.mpStts;
      if (pdVar1 == (dCcD_Stts *)0x0) {
        pfVar2 = (fopAc_ac_c *)0x0;
      }
      else {
        pfVar2 = (pdVar1->parent).mpActor;
      }
      pdVar1 = (pCo2->parent).parent.mpStts;
      if (pdVar1 == (dCcD_Stts *)0x0) {
        pfVar3 = (fopAc_ac_c *)0x0;
      }
      else {
        pfVar3 = (pdVar1->parent).mpActor;
      }
      (*pcVar4)(pfVar2,pCo1,pfVar3,pCo2);
    }
  }
  if ((bCo2 != false) && (pcVar4 = (code *)(pCo2->mObjCo).parent.mpCallback, pcVar4 != (code *)0x0))
  {
    pdVar1 = (pCo2->parent).parent.mpStts;
    if (pdVar1 == (dCcD_Stts *)0x0) {
      pfVar2 = (fopAc_ac_c *)0x0;
    }
    else {
      pfVar2 = (pdVar1->parent).mpActor;
    }
    pdVar1 = (pCo1->parent).parent.mpStts;
    if (pdVar1 == (dCcD_Stts *)0x0) {
      pfVar3 = (fopAc_ac_c *)0x0;
    }
    else {
      pfVar3 = (pdVar1->parent).mpActor;
    }
    (*pcVar4)(pfVar2,pCo2,pfVar3,pCo1);
  }
  return;
}


/* __thiscall dCcS::GetRank(unsigned char) */

uint __thiscall dCcS::GetRank(dCcS *this,uchar param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (uVar1 == 0xff) {
    return 10;
  }
  if (uVar1 == 0xfe) {
    return 9;
  }
  if (0xd8 < uVar1) {
    return 8;
  }
  if (0xb4 < uVar1) {
    return 7;
  }
  if (0x90 < uVar1) {
    return 6;
  }
  if (0x6c < uVar1) {
    return 5;
  }
  if (0x48 < uVar1) {
    return 4;
  }
  if (0x24 < uVar1) {
    return 3;
  }
  if (1 < uVar1) {
    return 2;
  }
  uVar1 = countLeadingZeros(1 - uVar1);
  return uVar1 >> 5;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x800aded0) */
/* __thiscall dCcS::SetPosCorrect(cCcD_Obj *,
                                  cXyz *,
                                  cCcD_Obj *,
                                  cXyz *,
                                  float) */

void __thiscall
dCcS::SetPosCorrect(dCcS *this,cCcD_Obj *pCo1,cXyz *param_2,cCcD_Obj *pCo2,cXyz *param_4,
                   float param_5)

{
  bool bVar1;
  fopAc_ac_c *pfVar2;
  int iVar3;
  int iVar4;
  dCcD_Stts *pdVar5;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  undefined8 in_f31;
  cXyz m2;
  cXyz m1;
  undefined4 local_48;
  uint uStack68;
  undefined4 local_40;
  uint uStack60;
  undefined auStack8 [8];
  
  dVar13 = (double)param_5;
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (((((((pCo1->parent).mObjCo.parent.mCommonFlag & 0x100) == 0) &&
        (((pCo2->parent).mObjCo.parent.mCommonFlag & 0x100) == 0)) &&
       (pCo1->mpStts != (dCcD_Stts *)0x0)) && (pCo2->mpStts != (dCcD_Stts *)0x0)) &&
     (((pfVar2 = (pCo1->mpStts->parent).mpActor, pfVar2 == (fopAc_ac_c *)0x0 ||
       (pfVar2 != (pCo2->mpStts->parent).mpActor)) &&
      (SComponent::G_CM3D_F_ABS_MIN <= (float)ABS(dVar13))))) {
    (*(code *)((this->parent).vtbl)->dCcS__SetCoGCorrectProc)(this,pCo1,pCo2);
    bVar1 = false;
    if ((((pCo1->parent).mObjCo.parent.mCommonFlag & 0x80) != 0) &&
       (((pCo2->parent).mObjCo.parent.mCommonFlag & 0x80) != 0)) {
      bVar1 = true;
    }
    pdVar5 = pCo1->mpStts;
    if ((((pdVar5->parent).mCoRank != 0) || ((pCo2->mpStts->parent).mCoRank != 0)) &&
       (((pdVar5->parent).mCoRank != 0xff || ((pCo2->mpStts->parent).mCoRank != 0xff)))) {
      iVar3 = GetRank(this,(pdVar5->parent).mCoRank);
      iVar4 = GetRank(this,(pCo2->mpStts->parent).mCoRank);
      uStack68 = (uint)(byte)(&d_cc_s::rank_tbl)[iVar4 + iVar3 * 0xb];
      local_48 = 0x43300000;
      dVar10 = (double)(d_cc_s::_4286 *
                       (float)((double)CONCAT44(0x43300000,uStack68) - d_cc_s::_4291));
      uStack60 = 100 - uStack68 & 0xff;
      local_40 = 0x43300000;
      m2.x = d_cc_s::_4286 * (float)((double)CONCAT44(0x43300000,uStack60) - d_cc_s::_4291);
      dVar11 = (double)m2.x;
      if (bVar1) {
        dVar7 = (double)(param_4->x - param_2->x);
        dVar8 = (double)(param_4->y - param_2->y);
        dVar9 = (double)(param_4->z - param_2->z);
        dVar14 = (double)((float)(dVar9 * dVar9) + (float)(dVar7 * dVar7) + (float)(dVar8 * dVar8));
        if ((double)d_cc_s::_4287 < dVar14) {
          dVar12 = 1.0 / SQRT(dVar14);
          dVar12 = d_cc_s::_4288 * dVar12 * (d_cc_s::_4289 - dVar14 * dVar12 * dVar12);
          dVar12 = d_cc_s::_4288 * dVar12 * (d_cc_s::_4289 - dVar14 * dVar12 * dVar12);
          dVar14 = (double)(float)(dVar14 * d_cc_s::_4288 * dVar12 *
                                            (d_cc_s::_4289 - dVar14 * dVar12 * dVar12));
        }
      }
      else {
        dVar7 = (double)(param_4->x - param_2->x);
        dVar8 = (double)d_cc_s::_4287;
        dVar9 = (double)(param_4->z - param_2->z);
        dVar14 = (double)((float)(dVar7 * dVar7) + (float)(dVar9 * dVar9));
        if (dVar8 < dVar14) {
          dVar12 = 1.0 / SQRT(dVar14);
          dVar12 = d_cc_s::_4288 * dVar12 * (d_cc_s::_4289 - dVar14 * dVar12 * dVar12);
          dVar12 = d_cc_s::_4288 * dVar12 * (d_cc_s::_4289 - dVar14 * dVar12 * dVar12);
          dVar14 = (double)(float)(dVar14 * d_cc_s::_4288 * dVar12 *
                                            (d_cc_s::_4289 - dVar14 * dVar12 * dVar12));
        }
      }
      if ((float)ABS(dVar14) < SComponent::G_CM3D_F_ABS_MIN) {
        m1.y = d_cc_s::_4287;
        m1.z = d_cc_s::_4287;
        m2.y = d_cc_s::_4287;
        m2.z = d_cc_s::_4287;
        if ((float)ABS(dVar13) < SComponent::G_CM3D_F_ABS_MIN) {
          m1.x = (float)-dVar10;
        }
        else {
          m1.x = (float)(-dVar13 * dVar10);
          m2.x = (float)(dVar13 * dVar11);
        }
      }
      else {
        if (bVar1) {
          dVar13 = (double)(float)(dVar13 / dVar14);
          m1.x = (float)(-(double)(float)(dVar7 * dVar13) * dVar10);
          m1.y = (float)(-(double)(float)(dVar8 * dVar13) * dVar10);
          m1.z = (float)(-(double)(float)(dVar9 * dVar13) * dVar10);
          m2.x = (float)((double)(float)(dVar7 * dVar13) * dVar11);
          m2.y = (float)((double)(float)(dVar8 * dVar13) * dVar11);
          m2.z = (float)((double)(float)(dVar9 * dVar13) * dVar11);
        }
        else {
          dVar7 = (double)(float)(dVar7 * (double)(float)(dVar13 / dVar14));
          dVar13 = (double)(float)(dVar9 * (double)(float)(dVar13 / dVar14));
          m1.x = (float)(-dVar7 * dVar10);
          m1.y = d_cc_s::_4287;
          m1.z = (float)(-dVar13 * dVar10);
          m2.x = (float)(dVar7 * dVar11);
          m2.y = d_cc_s::_4287;
          m2.z = (float)(dVar13 * dVar11);
        }
      }
      cCcD_Stts::PlusCcMove(&pCo1->mpStts->parent,m1.x,m1.y,m1.z);
      cCcD_Stts::PlusCcMove(&pCo2->mpStts->parent,m2.x,m2.y,m2.z);
      mtx::PSVECAdd(param_2,&m1,param_2);
      mtx::PSVECAdd(param_4,&m2,param_4);
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dCcS::CalcParticleAngle(dCcD_GObjInf *,
                                      cCcD_Stts *,
                                      cCcD_Stts *,
                                      csXyz *) */

void __thiscall
dCcS::CalcParticleAngle
          (dCcS *this,dCcD_GObjInf *param_1,cCcD_Stts *param_2,cCcD_Stts *param_3,csXyz *param_4)

{
  float fVar1;
  TVec3_float_ local_28;
  
  local_28.x = (param_1->mObjAt).mVel.x;
  local_28.y = (param_1->mObjAt).mVel.y;
  local_28.z = (param_1->mObjAt).mVel.z;
  fVar1 = mtx::PSVECMag((cXyz *)&local_28);
  if (SComponent::G_CM3D_F_ABS_MIN <= ABS(fVar1)) {
    mtx::PSVECNormalize(&local_28,&local_28);
  }
  else {
    if ((param_2->mpActor == (fopAc_ac_c *)0x0) || (param_3->mpActor == (fopAc_ac_c *)0x0)) {
      local_28.z = d_cc_s::_4287;
      local_28.x = d_cc_s::_4287;
      local_28.y = d_cc_s::_4322;
    }
    else {
      mtx::PSVECSubtract(&(param_3->mpActor->mCurrent).mPos,&(param_2->mpActor->mCurrent).mPos,
                         (cXyz *)&local_28);
      fVar1 = mtx::PSVECMag((cXyz *)&local_28);
      if (SComponent::G_CM3D_F_ABS_MIN <= ABS(fVar1)) {
        mtx::PSVECNormalize(&local_28,&local_28);
      }
      else {
        local_28.z = d_cc_s::_4287;
        local_28.x = d_cc_s::_4287;
        local_28.y = d_cc_s::_4322;
      }
    }
  }
  SComponent::cM3d_CalcVecZAngle(&local_28,param_4);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dCcS::ProcAtTgHitmark(bool,
                                    bool,
                                    cCcD_Obj *,
                                    cCcD_Obj *,
                                    dCcD_GObjInf *,
                                    dCcD_GObjInf *,
                                    cCcD_Stts *,
                                    cCcD_Stts *,
                                    dCcD_GStts *,
                                    dCcD_GStts *,
                                    cXyz *) */

void __thiscall
dCcS::ProcAtTgHitmark
          (dCcS *this,bool bAt,bool bTg,cCcD_Obj *pAt,cCcD_Obj *pTg,dCcD_GObjInf *pAtInf,
          dCcD_GObjInf *pTgInf,cCcD_Stts *pAtStts,cCcD_Stts *pTgStts,dCcD_GStts *pAtGStts,
          dCcD_GStts *pTgGStts,cXyz *pCrossPos)

{
  byte bVar1;
  uint uVar2;
  csXyz cStack88;
  csXyz cStack80;
  cXyz local_48;
  cXyz local_3c;
  cXyz local_30;
  
  if (((((pAtInf->mObjAt).parent.mGFlag & 2) == 0) && (((pTgInf->mObjTg).parent.mGFlag & 4) == 0))
     && ((pTgInf->mObjTg).mHitmarkType != 0xff)) {
    if (pTgGStts->field_0x8 == -1) {
      uVar2 = ChkShield(this,pAt,pTg,pAtInf,pTgInf);
      if ((uVar2 & 0xff) == 0) {
        bVar1 = (pAtInf->mObjAt).mHitmarkType;
        if (bVar1 != 0) {
          if ((bVar1 == 1) && ((pTgInf->mObjTg).mHitmarkType == 1)) {
            dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x27b,
                               pCrossPos,(csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1,
                               (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
          }
          else {
            (*(code *)((this->parent).vtbl)->dCcS__CalcParticleAngle)
                      (this,pAtInf,pAtStts,pTgStts,&cStack80);
            bVar1 = (pAtInf->mObjAt).mHitmarkType;
            if (bVar1 == 0xf) {
              dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x10,
                                 pCrossPos,(csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,
                                 -1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
              local_30.z = d_cc_s::_4409;
              local_30.y = d_cc_s::_4409;
              local_30.x = d_cc_s::_4409;
              dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0xd,
                                 pCrossPos,&cStack80,&local_30,0xff,(dPa_levelEcallBack *)0x0,-1,
                                 (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
            }
            else {
              if (bVar1 == 1) {
                dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0xd,
                                   pCrossPos,&cStack80,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1
                                   ,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
              }
              else {
                dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,
                                   (ushort)bVar1,pCrossPos,&cStack80,(cXyz *)0x0,0xff,
                                   (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                                   (cXyz *)0x0);
              }
            }
            local_3c.x = pCrossPos->x;
            local_3c.y = pCrossPos->y;
            local_3c.z = pCrossPos->z;
            d_kankyo::dKy_SordFlush_set(&local_3c,1);
          }
        }
      }
      else {
        if ((pTgInf->mObjTg).mHitmarkType != 0) {
          local_48.x = pCrossPos->x;
          local_48.y = pCrossPos->y;
          local_48.z = pCrossPos->z;
          d_kankyo::dKy_SordFlush_set(&local_48,0);
          (*(code *)((this->parent).vtbl)->dCcS__CalcParticleAngle)
                    (this,pAtInf,pAtStts,pTgStts,&cStack88);
          dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,
                             (ushort)(pTgInf->mObjTg).mHitmarkType,pCrossPos,&cStack88,(cXyz *)0x0,
                             0xff,(dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                             (cXyz *)0x0);
        }
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* __thiscall dCcS::SetAtTgGObjInf(bool,
                                   bool,
                                   cCcD_Obj *,
                                   cCcD_Obj *,
                                   cCcD_GObjInf *,
                                   cCcD_GObjInf *,
                                   cCcD_Stts *,
                                   cCcD_Stts *,
                                   cCcD_GStts *,
                                   cCcD_GStts *,
                                   cXyz *) */

void __thiscall
dCcS::SetAtTgGObjInf
          (dCcS *this,bool bAt,bool bTg,cCcD_Obj *pAt,cCcD_Obj *pTg,dCcD_GObjInf *pAtInf,
          dCcD_GObjInf *pTgInf,dCcD_Stts *pAtStts,dCcD_Stts *pTgStts,dCcD_GStts *pAtGStts,
          dCcD_GStts *pTgGStts,cXyz *pCrossPos)

{
  uint bHit;
  dCcD_Stts *pdVar1;
  fopAc_ac_c *pfVar2;
  fopAc_ac_c *pfVar3;
  code *pcVar4;
  
  bHit = ChkShield(this,pAt,pTg,pAtInf,pTgInf);
  if (bAt != false) {
    (pAtInf->mObjAt).mHitPos.x = pCrossPos->x;
    (pAtInf->mObjAt).mHitPos.y = pCrossPos->y;
    (pAtInf->mObjAt).mHitPos.z = pCrossPos->z;
    (pAtInf->mObjAt).mTgVel.x = (pTgInf->mObjTg).mVel.x;
    (pAtInf->mObjAt).mTgVel.y = (pTgInf->mObjTg).mVel.y;
    (pAtInf->mObjAt).mTgVel.z = (pTgInf->mObjTg).mVel.z;
    if ((pAtGStts != (dCcD_GStts *)0x0) && (pAtGStts->mTgSpl == 0)) {
      pAtGStts->mTgSpl = (pTgInf->mObjTg).mSpl;
    }
    (pAtInf->mObjAt).parent.mActorProcID = (pTgStts->parent).mActorProcID;
    (pAtInf->mObjAt).parent.mpActor = (fopAc_ac_c *)0x0;
    if ((bHit & 0xff) != 0) {
      (pAtInf->mObjAt).parent.mStatus = (pAtInf->mObjAt).parent.mStatus | Hit;
    }
    if ((pTgGStts->mFlags & 1) != 0) {
      (pAtInf->mObjAt).parent.mStatus = (pAtInf->mObjAt).parent.mStatus | AtHit;
    }
  }
  if (bTg != false) {
    (pTgInf->mObjTg).mHitPos.x = pCrossPos->x;
    (pTgInf->mObjTg).mHitPos.y = pCrossPos->y;
    (pTgInf->mObjTg).mHitPos.z = pCrossPos->z;
    (pTgInf->mObjTg).mAtVel.x = (pAtInf->mObjAt).mVel.x;
    (pTgInf->mObjTg).mAtVel.y = (pAtInf->mObjAt).mVel.y;
    (pTgInf->mObjTg).mAtVel.z = (pAtInf->mObjAt).mVel.z;
    if ((pTgGStts != (dCcD_GStts *)0x0) && (pAtGStts->mAtSpl == 0)) {
      pTgGStts->mAtSpl = (pAtInf->mObjAt).mSpl;
    }
    (pTgInf->mObjTg).parent.mActorProcID = (pAtStts->parent).mActorProcID;
    (pTgInf->mObjTg).parent.mpActor = (fopAc_ac_c *)0x0;
    if ((bHit & 0xff) != 0) {
      (pTgInf->mObjTg).parent.mStatus = (pTgInf->mObjTg).parent.mStatus | AtHit;
    }
    if ((pAtGStts->mFlags & 1) != 0) {
      (pTgInf->mObjTg).parent.mStatus = (pTgInf->mObjTg).parent.mStatus | Hit;
    }
  }
  if (bAt != false) {
    pcVar4 = (code *)(pAtInf->mObjAt).parent.mpCallback;
    if (pcVar4 != (code *)0x0) {
      pdVar1 = (pAtInf->parent).parent.mpStts;
      if (pdVar1 == (dCcD_Stts *)0x0) {
        pfVar2 = (fopAc_ac_c *)0x0;
      }
      else {
        pfVar2 = (pdVar1->parent).mpActor;
      }
      pdVar1 = (pTgInf->parent).parent.mpStts;
      if (pdVar1 == (dCcD_Stts *)0x0) {
        pfVar3 = (fopAc_ac_c *)0x0;
      }
      else {
        pfVar3 = (pdVar1->parent).mpActor;
      }
      (*pcVar4)(pfVar2,pAtInf,pfVar3,pTgInf);
    }
  }
  if (bTg != false) {
    pcVar4 = (code *)(pTgInf->mObjTg).parent.mpCallback;
    if (pcVar4 != (code *)0x0) {
      pdVar1 = (pTgInf->parent).parent.mpStts;
      if (pdVar1 == (dCcD_Stts *)0x0) {
        pfVar2 = (fopAc_ac_c *)0x0;
      }
      else {
        pfVar2 = (pdVar1->parent).mpActor;
      }
      pdVar1 = (pAtInf->parent).parent.mpStts;
      if (pdVar1 == (dCcD_Stts *)0x0) {
        pfVar3 = (fopAc_ac_c *)0x0;
      }
      else {
        pfVar3 = (pdVar1->parent).mpActor;
      }
      (*pcVar4)(pfVar2,pTgInf,pfVar3,pAtInf);
    }
  }
  if (bAt != false) {
    if (bTg != false) {
      if (((char)(pAtInf->mObjAt).parent.mEffCounterTimer < '\x01') ||
         ((char)(pTgInf->mObjTg).parent.mEffCounterTimer < '\x01')) {
        dCcD_GAtTgCoCommonBase::SetEffCounterTimer(&(pAtInf->mObjAt).parent);
        dCcD_GAtTgCoCommonBase::SetEffCounterTimer(&(pTgInf->mObjTg).parent);
        ProcAtTgHitmark(this,bAt,bTg,pAt,pTg,pAtInf,pTgInf,&pAtStts->parent,&pTgStts->parent,
                        pAtGStts,pTgGStts,pCrossPos);
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dCcS::ChkCamera(cXyz &,
                              cXyz &,
                              float,
                              fopAc_ac_c *,
                              fopAc_ac_c *) */

undefined4 __thiscall
dCcS::ChkCamera(dCcS *this,cXyz *pP0,cXyz *pP1,float r,fopAc_ac_c *pCoActor,fopAc_ac_c *pFilterActor
               )

{
  int iVar1;
  fopAc_ac_c *pActor;
  cCcD_Obj *pCo;
  char cVar2;
  cCcD_ShapeAttr *pShapeAttr;
  cCcD_Obj **pCoIt;
  undefined auStack104 [4];
  cCcD_DivideInfo div;
  cCcD_CpsAttr cps;
  
  iVar1 = (this->parent).mObjCoCount;
  if (0 < iVar1) {
    cps.parent.mAab.vtbl = &::cM3dGAab::__vt;
    cps.parent.vtbl = &::cCcD_CpsAttr::__vt;
    cps.mCps.parent.vtbl = &DAT_8039520c;
    cps.mCps.parent.mP0.x = pP0->x;
    cps.mCps.parent.mP0.y = pP0->y;
    cps.mCps.parent.mP0.z = pP0->z;
    cps.mCps.parent.mP1.x = pP1->x;
    cps.mCps.parent.mP1.y = pP1->y;
    cps.mCps.parent.mP1.z = pP1->z;
    cps.mCps.mRadius = r;
    ::cCcD_CpsAttr::CalcAabBox(&cps);
    div.vtbl = (undefined *)&cCcD_DivideInfo::__vt;
    cCcD_DivideArea::CalcDivideInfoOverArea(&(this->parent).mDivideArea,&div,(cM3dGAab *)&cps);
    for (pCoIt = (this->parent).mpObjCo; pCoIt < (this->parent).mpObjCo + iVar1; pCoIt = pCoIt + 1)
    {
      pCo = *pCoIt;
      if (((pCo->parent).mObjCo.parent.mCommonFlag & EnableCheck) != 0) {
        if (pCo->mpStts == (dCcD_Stts *)0x0) {
          pActor = (fopAc_ac_c *)0x0;
        }
        else {
          pActor = (pCo->mpStts->parent).mpActor;
        }
        if (pActor != pCoActor) {
          if (pCo->mpStts == (dCcD_Stts *)0x0) {
            pActor = (fopAc_ac_c *)0x0;
          }
          else {
            pActor = (pCo->mpStts->parent).mpActor;
          }
          if ((((pActor != pFilterActor) &&
               (cVar2 = cCcD_DivideInfo::Chk(&pCo->mDivideInfo,&div), cVar2 != '\0')) &&
              (pShapeAttr = (cCcD_ShapeAttr *)(*(code *)(((*pCoIt)->parent).vtbl)->GetShapeAttr_1)()
              , pShapeAttr != (cCcD_ShapeAttr *)0x0)) &&
             (cVar2 = (*(code *)pShapeAttr->vtbl->CrossCo_Cps)(pShapeAttr,&cps,auStack104),
             cVar2 != '\0')) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}


/* __thiscall dCcS::MoveAfterCheck(void) */

void __thiscall dCcS::MoveAfterCheck(dCcS *this)

{
  return;
}


/* __thiscall dCcS::DrawAfter(void) */

void __thiscall dCcS::DrawAfter(dCcS *this)

{
  return;
}


/* __thiscall dCcS::Move(void) */

void __thiscall dCcS::Move(dCcS *this)

{
  cCcS::Move(&this->parent);
  return;
}


/* __thiscall dCcS::Draw(void) */

void __thiscall dCcS::Draw(dCcS *this)

{
  DrawAfter(this);
  cCcS::DrawClear(&this->parent);
  dCcMassS_Mng::Clear(&this->mMassMng);
  return;
}


/* __thiscall dCcS::MassClear(void) */

void __thiscall dCcS::MassClear(dCcS *this)

{
  dCcMassS_Mng::Clear(&this->mMassMng);
  return;
}


/* __thiscall dCcS::ChkNoHitGCo(cCcD_Obj *,
                                cCcD_Obj *) */

undefined4 __thiscall dCcS::ChkNoHitGCo(dCcS *this,cCcD_Obj *pObj1,cCcD_Obj *pObj2)

{
  dCcD_GObjInf *pInf1;
  dCcD_GObjInf *pInf2;
  uint uVar1;
  
  pInf1 = (dCcD_GObjInf *)(*(code *)((pObj1->parent).vtbl)->GetGObjInf_1)(pObj1);
  pInf2 = (dCcD_GObjInf *)(*(code *)((pObj2->parent).vtbl)->GetGObjInf_1)(pObj2);
  uVar1 = (pInf1->mObjCo).parent.mGFlag;
  if ((((uVar1 & 1) == 0) || (((pInf2->mObjCo).parent.mGFlag & 2) != 0)) &&
     ((((pInf2->mObjCo).parent.mGFlag & 1) == 0 || ((uVar1 & 2) != 0)))) {
    return 0;
  }
  return 1;
}


/* __thiscall cCcS::ChkNoHitGAtTg(cCcD_GObjInf const *,
                                  cCcD_GObjInf const *,
                                  cCcD_GStts *,
                                  cCcD_GStts *) */

undefined4 __thiscall
cCcS::ChkNoHitGAtTg(cCcS *this,cCcD_GObjInf *param_1,cCcD_GObjInf *param_2,cCcD_GStts *param_3,
                   cCcD_GStts *param_4)

{
  return 0;
}

