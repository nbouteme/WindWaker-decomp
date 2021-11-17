#include <SComponent/c_cc_s.h>
#include <SComponent/c_cc_s.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <SComponent/c_cc_d.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <mtx/vec.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <SComponent/c_m3d_g_aab.h>
#include <cCcS.h>


namespace SComponent {
struct cXyz cross$2530;
undefined1 init$2532;
}

/* __thiscall cCcS::cCcS(void) */

void __thiscall cCcS::cCcS(cCcS *this)

{
  this->vtbl = (cCcS__vtbl *)&__vt;
  (this->mDivideArea).mAab.vtbl = &::cM3dGAab::__vt;
  (this->mDivideArea).mAab.vtbl = (cM3dGAab__vtbl *)&cCcD_DivideArea::__vt;
  return;
}


/* __thiscall cCcS::Ct(void) */

void __thiscall cCcS::Ct(cCcS *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0x100;
  do {
    *(undefined4 *)((int)this->mpObjAt + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar1 = 0;
  iVar2 = 0x300;
  do {
    *(undefined4 *)((int)this->mpObjTg + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar1 = 0;
  iVar2 = 0x100;
  do {
    *(undefined4 *)((int)this->mpObjCo + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar1 = 0;
  iVar2 = 0x500;
  do {
    *(undefined4 *)((int)this->mpObj + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this->mObjAtCount = 0;
  this->mObjTgCount = 0;
  this->mObjCoCount = 0;
  this->mObjCount = 0;
  return;
}


/* __thiscall cCcS::Dt(void) */

void __thiscall cCcS::Dt(cCcS *this)

{
  Ct(this);
  return;
}


/* __thiscall cCcS::Set(cCcD_Obj *) */

void __thiscall cCcS::Set(cCcS *this,cCcD_Obj *pObj)

{
  if (((pObj->parent).mObjAt.parent.mCommonFlag & EnableCheck) != 0) {
    if (this->mObjAtCount < 0x100) {
      this->mpObjAt[this->mObjAtCount] = pObj;
      this->mObjAtCount = this->mObjAtCount + 1;
    }
  }
  if (((pObj->parent).mObjTg.parent.mCommonFlag & EnableCheck) != 0) {
    if (this->mObjTgCount < 0x300) {
      this->mpObjTg[this->mObjTgCount] = pObj;
      this->mObjTgCount = this->mObjTgCount + 1;
    }
  }
  if ((((pObj->parent).mObjCo.parent.mCommonFlag & EnableCheck) != 0) && (this->mObjCoCount < 0x100)
     ) {
    this->mpObjCo[this->mObjCoCount] = pObj;
    this->mObjCoCount = this->mObjCoCount + 1;
  }
  if (0x4ff < this->mObjCount) {
    return;
  }
  this->mpObj[this->mObjCount] = pObj;
  this->mObjCount = this->mObjCount + 1;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall cCcS::ClrCoHitInf(void) */

void __thiscall cCcS::ClrCoHitInf(cCcS *this)

{
  float fVar1;
  cCcD_Obj *pObj;
  dCcD_GObjInf *pInf;
  float *pfVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  for (iVar3 = 0; iVar3 < this->mObjCoCount; iVar3 = iVar3 + 1) {
    pObj = *(cCcD_Obj **)((int)this->mpObjCo + iVar4);
    if (pObj != (cCcD_Obj *)0x0) {
      pInf = (dCcD_GObjInf *)(*(code *)((pObj->parent).vtbl)->GetGObjInf_1)();
      (*(code *)((pInf->parent).parent.parent.vtbl)->ClrCoHit)();
      fVar1 = SComponent::_2413;
      pfVar2 = *(float **)(*(int *)((int)this->mpObjCo + iVar4) + 0x44);
      if (pfVar2 != (float *)0x0) {
        pfVar2[2] = SComponent::_2413;
        pfVar2[1] = fVar1;
        *pfVar2 = fVar1;
      }
    }
    iVar4 = iVar4 + 4;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall cCcS::ClrTgHitInf(void) */

void __thiscall cCcS::ClrTgHitInf(cCcS *this)

{
  dCcD_GObjTg *pTg;
  dCcD_GObjInf *pInf;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  for (iVar2 = 0; iVar2 < this->mObjTgCount; iVar2 = iVar2 + 1) {
    pTg = *(dCcD_GObjTg **)((int)this->mpObjTg + iVar3);
    if (pTg != (dCcD_GObjTg *)0x0) {
      pInf = (dCcD_GObjInf *)(**(code **)((int)(pTg->mHitPos).y + 0x10))();
      (*(code *)((pInf->parent).parent.parent.vtbl)->ClrTgHit)();
      iVar1 = *(int *)(*(int *)((int)this->mpObjTg + iVar3) + 0x44);
      if (iVar1 != 0) {
        (**(code **)(*(int *)(iVar1 + 0x18) + 0x1c))();
      }
    }
    iVar3 = iVar3 + 4;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall cCcS::ClrAtHitInf(void) */

void __thiscall cCcS::ClrAtHitInf(cCcS *this)

{
  cCcD_Obj *pObj;
  dCcD_GObjInf *pInf;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  for (iVar2 = 0; iVar2 < this->mObjAtCount; iVar2 = iVar2 + 1) {
    pObj = *(cCcD_Obj **)((int)this->mpObjAt + iVar3);
    if (pObj != (cCcD_Obj *)0x0) {
      pInf = (dCcD_GObjInf *)(*(code *)((pObj->parent).vtbl)->GetGObjInf_1)();
      (*(code *)((pInf->parent).parent.parent.vtbl)->ClrAtHit)();
      iVar1 = *(int *)(*(int *)((int)this->mpObjAt + iVar3) + 0x44);
      if (iVar1 != 0) {
        (**(code **)(*(int *)(iVar1 + 0x18) + 0x18))();
      }
    }
    iVar3 = iVar3 + 4;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall cCcS::ChkNoHitAtTg(cCcD_Obj *,
                                 cCcD_Obj *) */

int __thiscall cCcS::ChkNoHitAtTg(cCcS *this,cCcD_Obj *pAt,cCcD_Obj *pTg)

{
  fopAc_ac_c *pAtAc;
  dCcD_Stts *pTgStts;
  cCcD_GStts *pTgGStts;
  cCcD_GStts *pAtGStts;
  undefined4 pTgGObj;
  undefined4 pAcGObj;
  int iVar1;
  fopAc_ac_c *pTgAc;
  dCcD_Stts *pAtStts;
  
  pAtStts = pAt->mpStts;
  if (pAtStts == (dCcD_Stts *)0x0) {
    pAtAc = (fopAc_ac_c *)0x0;
  }
  else {
    pAtAc = (pAtStts->parent).mpActor;
  }
  pTgStts = pTg->mpStts;
  if (pTgStts == (dCcD_Stts *)0x0) {
    pTgAc = (fopAc_ac_c *)0x0;
  }
  else {
    pTgAc = (pTgStts->parent).mpActor;
  }
  if ((((pAtAc == (fopAc_ac_c *)0x0) || (pTgAc == (fopAc_ac_c *)0x0)) || (pAtAc != pTgAc)) &&
     ((((pAt->parent).mObjAt.parent.mCommonFlag & (CategoryBit1|CategoryBit2|CategoryBit3) &
       (pTg->parent).mObjTg.parent.mCommonFlag) != 0 &&
      (((pAt->parent).mObjAt.mDamageTypes & (pTg->parent).mObjTg.mDamageTypes) != 0)))) {
    pTgGStts = (cCcD_GStts *)(*(code *)((pTgStts->parent).vtbl)->GetGStts_1)();
    pAtGStts = (cCcD_GStts *)(*(code *)((pAtStts->parent).vtbl)->GetGStts_1)(pAtStts);
    pTgGObj = (*(code *)((pTg->parent).vtbl)->GetGObjInf_1)(pTg);
    pAcGObj = (*(code *)((pAt->parent).vtbl)->GetGObjInf_1)(pAt);
    iVar1 = (*(code *)this->vtbl->ChkNoHitGAtTg)(this,pAcGObj,pTgGObj,pAtGStts,pTgGStts);
    return iVar1;
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall cCcS::ChkAtTg(void) */

void __thiscall cCcS::ChkAtTg(cCcS *this)

{
  int iVar1;
  cCcD_Obj *pAt;
  cCcD_ShapeAttr *pAtShape;
  char bDivChk;
  uint bNoHit;
  cCcD_ShapeAttr *pTgShape;
  byte bCross;
  cCcD_ShapeAttr *pShapeAttr;
  bool bEverywhere;
  cCcD_Obj **ppTg;
  cCcS *ppAt;
  
  iVar1 = this->mObjTgCount;
  ClrAtHitInf(this);
  ClrTgHitInf(this);
  for (ppAt = this; ppAt < (cCcS *)(this->mpObjAt + this->mObjAtCount);
      ppAt = (cCcS *)(ppAt->mpObjAt + 1)) {
    pAt = ppAt->mpObjAt[0];
    if (((pAt != (cCcD_Obj *)0x0) && (((pAt->parent).mObjAt.parent.mCommonFlag & EnableCheck) != 0))
       && (pAtShape = (cCcD_ShapeAttr *)(*(code *)((pAt->parent).vtbl)->GetShapeAttr_1)(),
          pAtShape != (cCcD_ShapeAttr *)0x0)) {
      for (ppTg = this->mpObjTg; ppTg < this->mpObjTg + iVar1; ppTg = ppTg + 1) {
        pAt = *ppTg;
        if ((pAt != (cCcD_Obj *)0x0) &&
           (((pAt->parent).mObjTg.parent.mCommonFlag & EnableCheck) != 0)) {
          bDivChk = cCcD_DivideInfo::Chk(&ppAt->mpObjAt[0]->mDivideInfo,&pAt->mDivideInfo);
          if (bDivChk != '\0') {
            bNoHit = ChkNoHitAtTg(this,ppAt->mpObjAt[0],*ppTg);
            if ((bNoHit & 0xff) == 0) {
              pTgShape = (cCcD_ShapeAttr *)(*(code *)(((*ppTg)->parent).vtbl)->GetShapeAttr_1)();
              if (pTgShape != (cCcD_ShapeAttr *)0x0) {
                if (SComponent::init_2532 == '\0') {
                  Runtime.PPCEABI.H::__register_global_object
                            (&SComponent::cross_2530,::cXyz::_cXyz,&SComponent::_2531);
                  SComponent::init_2532 = '\x01';
                }
                bCross = (*(code *)pAtShape->vtbl->CrossAtTg_Shape)
                                   (pAtShape,pTgShape,&SComponent::cross_2530);
                bEverywhere = true;
                pAt = ppAt->mpObjAt[0];
                if (((pAt->mAreaFlag & 2) == 0) && (((*ppTg)->mAreaFlag & 2) == 0)) {
                  bEverywhere = false;
                }
                if ((bEverywhere) || (bCross == 0)) {
                  if ((bEverywhere) && (bCross == 0)) {
                    pShapeAttr = (cCcD_ShapeAttr *)
                                 (*(code *)((pAt->parent).vtbl)->GetShapeAttr_1)(pAt);
                    if (pShapeAttr == (cCcD_ShapeAttr *)0x0) {
                      SComponent::cross_2530.x = SComponent::_2413;
                      SComponent::cross_2530.y = SComponent::_2413;
                      SComponent::cross_2530.z = SComponent::_2413;
                    }
                    else {
                      mtx::PSVECAdd((cXyz *)pShapeAttr,&(pShapeAttr->mAab).mMax,
                                    &SComponent::cross_2530);
                      mtx::PSVECScale(&SComponent::cross_2530,&SComponent::cross_2530,
                                      SComponent::_2572);
                    }
                    SetAtTgCommonHitInf(this,ppAt->mpObjAt[0],*ppTg,&SComponent::cross_2530);
                  }
                }
                else {
                  SetAtTgCommonHitInf(this,pAt,*ppTg,&SComponent::cross_2530);
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}


/* __thiscall cCcS::ChkNoHitCo(cCcD_Obj *,
                               cCcD_Obj *) */

undefined4 __thiscall cCcS::ChkNoHitCo(cCcS *this,cCcD_Obj *pObj1,cCcD_Obj *pObj2)

{
  fopAc_ac_c *pAct1;
  char cVar1;
  fopAc_ac_c *pAct2;
  cCcD__CommonFlag mask2;
  cCcD__CommonFlag mask1;
  
  if (pObj1->mpStts == (dCcD_Stts *)0x0) {
    pAct1 = (fopAc_ac_c *)0x0;
  }
  else {
    pAct1 = (pObj1->mpStts->parent).mpActor;
  }
  if (pObj2->mpStts == (dCcD_Stts *)0x0) {
    pAct2 = (fopAc_ac_c *)0x0;
  }
  else {
    pAct2 = (pObj2->mpStts->parent).mpActor;
  }
  if (((pAct1 == (fopAc_ac_c *)0x0) || (pAct2 == (fopAc_ac_c *)0x0)) || (pAct1 != pAct2)) {
    mask1 = (pObj1->parent).mObjCo.parent.mCommonFlag;
    mask2 = (pObj2->parent).mObjCo.parent.mCommonFlag;
    if ((((mask1 & (CategoryBit1|CategoryBit2|CategoryBit3) &
          mask2 >> 3 & (CategoryBit1|CategoryBit2|CategoryBit3)) != 0) &&
        ((mask2 & (CategoryBit1|CategoryBit2|CategoryBit3) &
         mask1 >> 3 & (CategoryBit1|CategoryBit2|CategoryBit3)) != 0)) &&
       (cVar1 = (*(code *)this->vtbl->ChkNoHitGCo)(), cVar1 == '\0')) {
      return 0;
    }
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall cCcS::ChkCo(void) */

void __thiscall cCcS::ChkCo(cCcS *this)

{
  int iVar1;
  cCcD_Obj *pcVar2;
  int iVar3;
  char cVar7;
  int iVar4;
  cXyz *pcVar5;
  cXyz *pcVar6;
  cCcD_Obj **ppcVar8;
  cCcD_Obj **ppcVar9;
  float local_28 [3];
  
  ClrCoHitInf(this);
  iVar1 = this->mObjCoCount;
  if (1 < iVar1) {
    for (ppcVar9 = this->mpObjCo; ppcVar9 < this->mpObjCo + iVar1 + -1; ppcVar9 = ppcVar9 + 1) {
      pcVar2 = *ppcVar9;
      if (((pcVar2 != (cCcD_Obj *)0x0) &&
          (((pcVar2->parent).mObjCo.parent.mCommonFlag & EnableCheck) != 0)) &&
         (iVar3 = (*(code *)((pcVar2->parent).vtbl)->GetShapeAttr_1)(), ppcVar8 = ppcVar9,
         iVar3 != 0)) {
        while (ppcVar8 = ppcVar8 + 1, ppcVar8 < this->mpObjCo + iVar1) {
          pcVar2 = *ppcVar8;
          if (((pcVar2 != (cCcD_Obj *)0x0) &&
              (((pcVar2->parent).mObjCo.parent.mCommonFlag & EnableCheck) != 0)) &&
             ((cVar7 = cCcD_DivideInfo::Chk(&(*ppcVar9)->mDivideInfo,&pcVar2->mDivideInfo),
              cVar7 != '\0' &&
              ((cVar7 = ChkNoHitCo(this,*ppcVar9,*ppcVar8), cVar7 == '\0' &&
               (iVar4 = (*(code *)(((*ppcVar8)->parent).vtbl)->GetShapeAttr_1)(),
               ppcVar8 != (cCcD_Obj **)0x0)))))) {
            local_28[0] = SComponent::_2413;
            cVar7 = (**(code **)(*(int *)(iVar3 + 0x1c) + 0x28))(iVar3,iVar4,local_28);
            if (cVar7 != '\0') {
              pcVar5 = (cXyz *)(**(code **)(*(int *)(iVar4 + 0x1c) + 0x48))(iVar4);
              pcVar6 = (cXyz *)(**(code **)(*(int *)(iVar3 + 0x1c) + 0x48))(iVar3);
              SetCoCommonHitInf(this,*ppcVar9,pcVar6,*ppcVar8,pcVar5,local_28[0]);
            }
          }
        }
      }
    }
  }
  return;
}


/* __thiscall cCcS::CalcTgPlusDmg(cCcD_Obj *,
                                  cCcD_Obj *,
                                  cCcD_Stts *,
                                  cCcD_Stts *) */

void __thiscall
cCcS::CalcTgPlusDmg(cCcS *this,cCcD_Obj *pAt,cCcD_Obj *pTg,cCcD_Stts *pAtStts,cCcD_Stts *pTgStts)

{
  byte bVar1;
  
  bVar1 = (pAt->parent).mObjAt.mDamage;
  if (bVar1 <= pTgStts->mReceiveDamageAmount) {
    return;
  }
  pTgStts->mReceiveDamageAmount = bVar1;
  return;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* __thiscall cCcS::SetAtTgCommonHitInf(cCcD_Obj *,
                                        cCcD_Obj *,
                                        cXyz *) */

void __thiscall cCcS::SetAtTgCommonHitInf(cCcS *this,cCcD_Obj *pAt,cCcD_Obj *pTg,cXyz *pCrossPos)

{
  cCcD__CommonFlag atCommon;
  cCcD__CommonFlag tgCommon;
  uint bAt;
  uint bTg;
  uint uVar1;
  uint uVar2;
  dCcD_Stts *pTgGStts;
  dCcD_Stts *pAtGStts;
  undefined4 uVar3;
  undefined4 uVar4;
  bool bNoHit;
  undefined4 uVar5;
  undefined4 uVar6;
  dCcD_Stts *pTgStts;
  dCcD_Stts *pAtStts;
  
  pAtStts = pAt->mpStts;
  pTgStts = pTg->mpStts;
  atCommon = (pAt->parent).mObjAt.parent.mCommonFlag;
  tgCommon = (pTg->parent).mObjTg.parent.mCommonFlag;
  pTgGStts = (dCcD_Stts *)(*(code *)((pTgStts->parent).vtbl)->GetGStts_1)(pTgStts);
  pAtGStts = (dCcD_Stts *)(*(code *)((pAtStts->parent).vtbl)->GetGStts_1)(pAtStts);
  uVar3 = (*(code *)((pTg->parent).vtbl)->GetGObjInf_1)(pTg);
  uVar4 = (*(code *)((pAt->parent).vtbl)->GetGObjInf_1)(pAt);
  bAt = countLeadingZeros(tgCommon & EnableSendAtTg);
  bTg = countLeadingZeros(atCommon & EnableSendAtTg);
  bNoHit = (bool)(*(code *)this->vtbl->ChkAtTgHitAfterCross)
                           (this,bAt >> 5,bTg >> 5,uVar4,uVar3,pAtStts,pTgStts,pAtGStts,pTgGStts);
  if (bNoHit == false) {
    if (((pTg->parent).mObjTg.parent.mCommonFlag & EnableSendAtTg) == 0) {
      (pAt->parent).mObjAt.parent.mbHasPair = 1;
      (pAt->parent).mObjAt.parent.mpHitObj = pTg;
    }
    if (((pAt->parent).mObjAt.parent.mCommonFlag & EnableSendAtTg) == 0) {
      (pTg->parent).mObjTg.parent.mbHasPair = 1;
      (pTg->parent).mObjTg.parent.mpHitObj = pAt;
      (*(code *)this->vtbl->CalcTgPlusDmg)(this,pAt,pTg,pAtStts,pTgStts);
    }
    atCommon = (pAt->parent).mObjAt.parent.mCommonFlag;
    tgCommon = (pTg->parent).mObjTg.parent.mCommonFlag;
    uVar3 = (*(code *)((pTgStts->parent).vtbl)->GetGStts_1)(pTgStts);
    uVar4 = (*(code *)((pAtStts->parent).vtbl)->GetGStts_1)(pAtStts);
    uVar5 = (*(code *)((pTg->parent).vtbl)->GetGObjInf_1)(pTg);
    uVar6 = (*(code *)((pAt->parent).vtbl)->GetGObjInf_1)(pAt);
    uVar1 = countLeadingZeros(tgCommon & EnableSendAtTg);
    uVar2 = countLeadingZeros(atCommon & EnableSendAtTg);
    (*(code *)this->vtbl->SetAtTgGObjInf)
              (this,uVar1 >> 5,uVar2 >> 5,pAt,pTg,uVar6,uVar5,pAtStts,pTgStts,uVar4,uVar3,pCrossPos)
    ;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __thiscall cCcS::SetCoCommonHitInf(cCcD_Obj *,
                                      cXyz *,
                                      cCcD_Obj *,
                                      cXyz *,
                                      float) */

void __thiscall
cCcS::SetCoCommonHitInf
          (cCcS *this,cCcD_Obj *pObj1,cXyz *param_2,cCcD_Obj *pObj2,cXyz *param_4,float param_5)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  dCcD_Stts *pdVar7;
  dCcD_Stts *pdVar8;
  
  uVar2 = countLeadingZeros((pObj2->parent).mObjCo.parent.mCommonFlag & EnableSendCo);
  uVar1 = countLeadingZeros((pObj1->parent).mObjCo.parent.mCommonFlag & EnableSendCo);
  uVar1 = uVar1 >> 5;
  if ((uVar2 >> 5 & 0xff) != 0) {
    (pObj1->parent).mObjCo.parent.mbHasPair = 1;
    (pObj1->parent).mObjCo.parent.mpHitObj = pObj2;
  }
  if ((uVar1 & 0xff) != 0) {
    (pObj2->parent).mObjCo.parent.mbHasPair = 1;
    (pObj2->parent).mObjCo.parent.mpHitObj = pObj1;
  }
  if (((uVar2 >> 5 & 0xff) != 0) && ((uVar1 & 0xff) != 0)) {
    (*(code *)this->vtbl->SetPosCorrect)((double)param_5,this,pObj1,param_2,pObj2);
  }
  pdVar8 = pObj1->mpStts;
  pdVar7 = pObj2->mpStts;
  uVar3 = (*(code *)((pdVar7->parent).vtbl)->GetGStts_1)(pdVar7);
  uVar4 = (*(code *)((pdVar8->parent).vtbl)->GetGStts_1)(pdVar8);
  uVar5 = (*(code *)((pObj2->parent).vtbl)->GetGObjInf_1)(pObj2);
  uVar6 = (*(code *)((pObj1->parent).vtbl)->GetGObjInf_1)(pObj1);
  (*(code *)this->vtbl->SetCoGObjInf)(this,uVar2 >> 5,uVar1,uVar6,uVar5,pdVar8,pdVar7,uVar4,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80244730) */
/* __thiscall cCcS::SetPosCorrect(cCcD_Obj *,
                                  cXyz *,
                                  cCcD_Obj *,
                                  cXyz *,
                                  float) */

void __thiscall
cCcS::SetPosCorrect(cCcS *this,cCcD_Obj *param_1,cXyz *param_2,cCcD_Obj *param_3,cXyz *param_4,
                   float param_5)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  uint uVar4;
  bool bVar5;
  int iVar6;
  fopAc_ac_c *pfVar7;
  ulong uVar8;
  int iVar9;
  undefined4 uVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  undefined8 in_f31;
  cXyz local_5c;
  cXyz local_50;
  undefined4 local_40;
  uint uStack60;
  undefined4 local_38;
  uint uStack52;
  undefined auStack8 [8];
  
  dVar17 = (double)param_5;
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar4 = (uint)param_5 & 0x7f800000;
  if (uVar4 == 0x7f800000) {
    if (((uint)param_5 & 0x7fffff) == 0) {
      iVar6 = 2;
    }
    else {
      iVar6 = 1;
    }
  }
  else {
    if ((uVar4 < 0x7f800000) && (uVar4 == 0)) {
      if (((uint)param_5 & 0x7fffff) == 0) {
        iVar6 = 3;
      }
      else {
        iVar6 = 5;
      }
    }
    else {
      iVar6 = 4;
    }
  }
  if (iVar6 == 1) {
    uVar8 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar8,"c_cc_s.cpp",0x25c,
               "!(((sizeof(cross_len) == sizeof(float)) ? __fpclassifyf((float)(cross_len)) : __fpclassifyd((double)(cross_len)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_cc_s.cpp",0x25c,&DAT_80364224);
  }
  bVar5 = false;
  if (((double)SComponent::_3043 < dVar17) && (dVar17 < (double)SComponent::_3044)) {
    bVar5 = true;
  }
  if (!bVar5) {
    uVar8 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar8,"c_cc_s.cpp",0x25d,"-1.0e32f < cross_len && cross_len < 1.0e32f")
    ;
    m_Do_printf::OSPanic("c_cc_s.cpp",0x25d,&DAT_80364224);
  }
  if ((((((param_1->parent).mObjCo.parent.mCommonFlag & 0x100) == 0) &&
       (((param_3->parent).mObjCo.parent.mCommonFlag & 0x100) == 0)) &&
      (param_1->mpStts != (dCcD_Stts *)0x0)) &&
     (((param_3->mpStts != (dCcD_Stts *)0x0 &&
       ((pfVar7 = (param_1->mpStts->parent).mpActor, pfVar7 == (fopAc_ac_c *)0x0 ||
        (pfVar7 != (param_3->mpStts->parent).mpActor)))) &&
      (SComponent::_3045 <= (float)ABS(dVar17))))) {
    (*(code *)this->vtbl->dCcS__SetCoGCorrectProc)(this,param_1,param_3);
    bVar5 = false;
    if ((((param_1->parent).mObjCo.parent.mCommonFlag & 0x80) != 0) &&
       (((param_3->parent).mObjCo.parent.mCommonFlag & 0x80) != 0)) {
      bVar5 = true;
    }
    bVar3 = (param_1->mpStts->parent).mCoRank;
    if (bVar3 == 0xff) {
      iVar6 = 0;
    }
    else {
      if (bVar3 == 0xfe) {
        iVar6 = 1;
      }
      else {
        iVar6 = 2;
      }
    }
    bVar3 = (param_3->mpStts->parent).mCoRank;
    if (bVar3 == 0xff) {
      iVar9 = 0;
    }
    else {
      if (bVar3 == 0xfe) {
        iVar9 = 1;
      }
      else {
        iVar9 = 2;
      }
    }
    uStack60 = (param_1->mpStts->parent).mCoRank ^ 0x80000000;
    local_40 = 0x43300000;
    fVar1 = (float)((double)CONCAT44(0x43300000,uStack60) - SComponent::_3051);
    uStack52 = (param_3->mpStts->parent).mCoRank ^ 0x80000000;
    local_38 = 0x43300000;
    fVar2 = (float)((double)CONCAT44(0x43300000,uStack52) - SComponent::_3051);
    dVar14 = (double)(fVar1 + fVar2);
    if ((float)ABS(dVar14) < SComponent::G_CM3D_F_ABS_MIN) {
      dVar14 = (double)SComponent::_3047;
      fVar1 = SComponent::_3046;
      fVar2 = SComponent::_3046;
    }
    dVar11 = (double)SComponent::_3046;
    dVar15 = dVar11;
    if (iVar6 == 0) {
      if (iVar9 == 0) goto LAB_80244730;
      dVar11 = (double)SComponent::_2413;
    }
    else {
      if (iVar6 == 1) {
        if (iVar9 == 0) {
          dVar15 = (double)SComponent::_2413;
        }
        else {
          if (iVar9 == 1) {
            dVar11 = (double)SComponent::_2572;
            dVar15 = (double)SComponent::_2572;
          }
          else {
            dVar11 = (double)SComponent::_2413;
          }
        }
      }
      else {
        if (iVar9 == 2) {
          dVar15 = (double)(fVar1 * (float)(dVar11 / dVar14));
          dVar11 = (double)(fVar2 * (float)(dVar11 / dVar14));
        }
        else {
          dVar15 = (double)SComponent::_2413;
        }
      }
    }
    if (bVar5) {
      dVar14 = (double)(param_4->x - param_2->x);
      dVar12 = (double)(param_4->y - param_2->y);
      dVar13 = (double)(param_4->z - param_2->z);
      dVar18 = (double)((float)(dVar13 * dVar13) +
                       (float)(dVar14 * dVar14) + (float)(dVar12 * dVar12));
      if ((double)SComponent::_2413 < dVar18) {
        dVar16 = 1.0 / SQRT(dVar18);
        dVar16 = SComponent::_3048 * dVar16 * (SComponent::_3049 - dVar18 * dVar16 * dVar16);
        dVar16 = SComponent::_3048 * dVar16 * (SComponent::_3049 - dVar18 * dVar16 * dVar16);
        dVar18 = (double)(float)(dVar18 * SComponent::_3048 * dVar16 *
                                          (SComponent::_3049 - dVar18 * dVar16 * dVar16));
      }
    }
    else {
      dVar14 = (double)(param_4->x - param_2->x);
      dVar12 = (double)SComponent::_2413;
      dVar13 = (double)(param_4->z - param_2->z);
      dVar18 = (double)((float)(dVar14 * dVar14) + (float)(dVar13 * dVar13));
      if (dVar12 < dVar18) {
        dVar16 = 1.0 / SQRT(dVar18);
        dVar16 = SComponent::_3048 * dVar16 * (SComponent::_3049 - dVar18 * dVar16 * dVar16);
        dVar16 = SComponent::_3048 * dVar16 * (SComponent::_3049 - dVar18 * dVar16 * dVar16);
        dVar18 = (double)(float)(dVar18 * SComponent::_3048 * dVar16 *
                                          (SComponent::_3049 - dVar18 * dVar16 * dVar16));
      }
    }
    if ((float)ABS(dVar18) < SComponent::G_CM3D_F_ABS_MIN) {
      local_50.y = SComponent::_2413;
      local_50.z = SComponent::_2413;
      local_5c.y = SComponent::_2413;
      local_5c.z = SComponent::_2413;
      if ((float)ABS(dVar17) < SComponent::G_CM3D_F_ABS_MIN) {
        local_50.x = (float)-dVar11;
        local_5c.x = (float)dVar15;
      }
      else {
        local_50.x = (float)(-dVar17 * dVar11);
        local_5c.x = (float)(dVar17 * dVar15);
      }
    }
    else {
      if (bVar5) {
        dVar17 = (double)(float)(dVar17 / dVar18);
        local_50.x = (float)(-(double)(float)(dVar14 * dVar17) * dVar11);
        local_50.y = (float)(-(double)(float)(dVar12 * dVar17) * dVar11);
        local_50.z = (float)(-(double)(float)(dVar13 * dVar17) * dVar11);
        local_5c.x = (float)((double)(float)(dVar14 * dVar17) * dVar15);
        local_5c.y = (float)((double)(float)(dVar12 * dVar17) * dVar15);
        local_5c.z = (float)((double)(float)(dVar13 * dVar17) * dVar15);
      }
      else {
        dVar14 = (double)(float)(dVar14 * (double)(float)(dVar17 / dVar18));
        dVar17 = (double)(float)(dVar13 * (double)(float)(dVar17 / dVar18));
        local_50.x = (float)(-dVar14 * dVar11);
        local_50.y = SComponent::_2413;
        local_50.z = (float)(-dVar17 * dVar11);
        local_5c.x = (float)(dVar14 * dVar15);
        local_5c.y = SComponent::_2413;
        local_5c.z = (float)(dVar17 * dVar15);
      }
    }
    uVar4 = (uint)local_50.x & 0x7f800000;
    if (uVar4 == 0x7f800000) {
      if (((uint)local_50.x & 0x7fffff) == 0) {
        iVar6 = 2;
      }
      else {
        iVar6 = 1;
      }
    }
    else {
      if ((uVar4 < 0x7f800000) && (uVar4 == 0)) {
        if (((uint)local_50.x & 0x7fffff) == 0) {
          iVar6 = 3;
        }
        else {
          iVar6 = 5;
        }
      }
      else {
        iVar6 = 4;
      }
    }
    if (iVar6 == 1) {
      uVar8 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar8,"c_cc_s.cpp",0x31a,
                 "!(((sizeof(vec1.x) == sizeof(float)) ? __fpclassifyf((float)(vec1.x)) : __fpclassifyd((double)(vec1.x)) ) == 1)"
                );
      m_Do_printf::OSPanic("c_cc_s.cpp",0x31a,&DAT_80364224);
    }
    uVar4 = (uint)local_50.y & 0x7f800000;
    if (uVar4 == 0x7f800000) {
      if (((uint)local_50.y & 0x7fffff) == 0) {
        iVar6 = 2;
      }
      else {
        iVar6 = 1;
      }
    }
    else {
      if ((uVar4 < 0x7f800000) && (uVar4 == 0)) {
        if (((uint)local_50.y & 0x7fffff) == 0) {
          iVar6 = 3;
        }
        else {
          iVar6 = 5;
        }
      }
      else {
        iVar6 = 4;
      }
    }
    if (iVar6 == 1) {
      uVar8 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar8,"c_cc_s.cpp",0x31b,
                 "!(((sizeof(vec1.y) == sizeof(float)) ? __fpclassifyf((float)(vec1.y)) : __fpclassifyd((double)(vec1.y)) ) == 1)"
                );
      m_Do_printf::OSPanic("c_cc_s.cpp",0x31b,&DAT_80364224);
    }
    uVar4 = (uint)local_50.z & 0x7f800000;
    if (uVar4 == 0x7f800000) {
      if (((uint)local_50.z & 0x7fffff) == 0) {
        iVar6 = 2;
      }
      else {
        iVar6 = 1;
      }
    }
    else {
      if ((uVar4 < 0x7f800000) && (uVar4 == 0)) {
        if (((uint)local_50.z & 0x7fffff) == 0) {
          iVar6 = 3;
        }
        else {
          iVar6 = 5;
        }
      }
      else {
        iVar6 = 4;
      }
    }
    if (iVar6 == 1) {
      uVar8 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar8,"c_cc_s.cpp",0x31c,
                 "!(((sizeof(vec1.z) == sizeof(float)) ? __fpclassifyf((float)(vec1.z)) : __fpclassifyd((double)(vec1.z)) ) == 1)"
                );
      m_Do_printf::OSPanic("c_cc_s.cpp",0x31c,&DAT_80364224);
    }
    uVar4 = (uint)local_5c.x & 0x7f800000;
    if (uVar4 == 0x7f800000) {
      if (((uint)local_5c.x & 0x7fffff) == 0) {
        iVar6 = 2;
      }
      else {
        iVar6 = 1;
      }
    }
    else {
      if ((uVar4 < 0x7f800000) && (uVar4 == 0)) {
        if (((uint)local_5c.x & 0x7fffff) == 0) {
          iVar6 = 3;
        }
        else {
          iVar6 = 5;
        }
      }
      else {
        iVar6 = 4;
      }
    }
    if (iVar6 == 1) {
      uVar8 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar8,"c_cc_s.cpp",0x31e,
                 "!(((sizeof(vec2.x) == sizeof(float)) ? __fpclassifyf((float)(vec2.x)) : __fpclassifyd((double)(vec2.x)) ) == 1)"
                );
      m_Do_printf::OSPanic("c_cc_s.cpp",0x31e,&DAT_80364224);
    }
    uVar4 = (uint)local_5c.y & 0x7f800000;
    if (uVar4 == 0x7f800000) {
      if (((uint)local_5c.y & 0x7fffff) == 0) {
        iVar6 = 2;
      }
      else {
        iVar6 = 1;
      }
    }
    else {
      if ((uVar4 < 0x7f800000) && (uVar4 == 0)) {
        if (((uint)local_5c.y & 0x7fffff) == 0) {
          iVar6 = 3;
        }
        else {
          iVar6 = 5;
        }
      }
      else {
        iVar6 = 4;
      }
    }
    if (iVar6 == 1) {
      uVar8 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar8,"c_cc_s.cpp",799,
                 "!(((sizeof(vec2.y) == sizeof(float)) ? __fpclassifyf((float)(vec2.y)) : __fpclassifyd((double)(vec2.y)) ) == 1)"
                );
      m_Do_printf::OSPanic("c_cc_s.cpp",799,&DAT_80364224);
    }
    uVar4 = (uint)local_5c.z & 0x7f800000;
    if (uVar4 == 0x7f800000) {
      if (((uint)local_5c.z & 0x7fffff) == 0) {
        iVar6 = 2;
      }
      else {
        iVar6 = 1;
      }
    }
    else {
      if ((uVar4 < 0x7f800000) && (uVar4 == 0)) {
        if (((uint)local_5c.z & 0x7fffff) == 0) {
          iVar6 = 3;
        }
        else {
          iVar6 = 5;
        }
      }
      else {
        iVar6 = 4;
      }
    }
    if (iVar6 == 1) {
      uVar8 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar8,"c_cc_s.cpp",800,
                 "!(((sizeof(vec2.z) == sizeof(float)) ? __fpclassifyf((float)(vec2.z)) : __fpclassifyd((double)(vec2.z)) ) == 1)"
                );
      m_Do_printf::OSPanic("c_cc_s.cpp",800,&DAT_80364224);
    }
    bVar5 = false;
    if ((((SComponent::_3043 < local_50.x) && (local_50.x < SComponent::_3044)) &&
        (SComponent::_3043 < local_50.y)) &&
       (((local_50.y < SComponent::_3044 && (SComponent::_3043 < local_50.z)) &&
        (local_50.z < SComponent::_3044)))) {
      bVar5 = true;
    }
    if (!bVar5) {
      uVar8 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar8,"c_cc_s.cpp",0x324,
                 "-1.0e32f < vec1.x && vec1.x < 1.0e32f && -1.0e32f < vec1.y && vec1.y < 1.0e32f && -1.0e32f < vec1.z && vec1.z < 1.0e32f"
                );
      m_Do_printf::OSPanic("c_cc_s.cpp",0x324,&DAT_80364224);
    }
    bVar5 = false;
    if (((SComponent::_3043 < local_5c.x) && (local_5c.x < SComponent::_3044)) &&
       ((SComponent::_3043 < local_5c.y &&
        (((local_5c.y < SComponent::_3044 && (SComponent::_3043 < local_5c.z)) &&
         (local_5c.z < SComponent::_3044)))))) {
      bVar5 = true;
    }
    if (!bVar5) {
      uVar8 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar8,"c_cc_s.cpp",0x328,
                 "-1.0e32f < vec2.x && vec2.x < 1.0e32f && -1.0e32f < vec2.y && vec2.y < 1.0e32f && -1.0e32f < vec2.z && vec2.z < 1.0e32f"
                );
      m_Do_printf::OSPanic("c_cc_s.cpp",0x328,&DAT_80364224);
    }
    cCcD_Stts::PlusCcMove(&param_1->mpStts->parent,local_50.x,local_50.y,local_50.z);
    cCcD_Stts::PlusCcMove(&param_3->mpStts->parent,local_5c.x,local_5c.y,local_5c.z);
    mtx::PSVECAdd(param_2,&local_50,param_2);
    mtx::PSVECAdd(param_4,&local_5c,param_4);
    fVar1 = param_2->x;
    uVar4 = (uint)fVar1 & 0x7f800000;
    if (uVar4 == 0x7f800000) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar6 = 2;
      }
      else {
        iVar6 = 1;
      }
    }
    else {
      if ((uVar4 < 0x7f800000) && (uVar4 == 0)) {
        if (((uint)fVar1 & 0x7fffff) == 0) {
          iVar6 = 3;
        }
        else {
          iVar6 = 5;
        }
      }
      else {
        iVar6 = 4;
      }
    }
    if (iVar6 == 1) {
      uVar8 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar8,"c_cc_s.cpp",0x331,
                 "!(((sizeof(ppos1->x) == sizeof(float)) ? __fpclassifyf((float)(ppos1->x)) : __fpclassifyd((double)(ppos1->x)) ) == 1)"
                );
      m_Do_printf::OSPanic("c_cc_s.cpp",0x331,&DAT_80364224);
    }
    fVar1 = param_2->y;
    uVar4 = (uint)fVar1 & 0x7f800000;
    if (uVar4 == 0x7f800000) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar6 = 2;
      }
      else {
        iVar6 = 1;
      }
    }
    else {
      if ((uVar4 < 0x7f800000) && (uVar4 == 0)) {
        if (((uint)fVar1 & 0x7fffff) == 0) {
          iVar6 = 3;
        }
        else {
          iVar6 = 5;
        }
      }
      else {
        iVar6 = 4;
      }
    }
    if (iVar6 == 1) {
      uVar8 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar8,"c_cc_s.cpp",0x332,
                 "!(((sizeof(ppos1->y) == sizeof(float)) ? __fpclassifyf((float)(ppos1->y)) : __fpclassifyd((double)(ppos1->y)) ) == 1)"
                );
      m_Do_printf::OSPanic("c_cc_s.cpp",0x332,&DAT_80364224);
    }
    fVar1 = param_2->z;
    uVar4 = (uint)fVar1 & 0x7f800000;
    if (uVar4 == 0x7f800000) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar6 = 2;
      }
      else {
        iVar6 = 1;
      }
    }
    else {
      if ((uVar4 < 0x7f800000) && (uVar4 == 0)) {
        if (((uint)fVar1 & 0x7fffff) == 0) {
          iVar6 = 3;
        }
        else {
          iVar6 = 5;
        }
      }
      else {
        iVar6 = 4;
      }
    }
    if (iVar6 == 1) {
      uVar8 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar8,"c_cc_s.cpp",0x333,
                 "!(((sizeof(ppos1->z) == sizeof(float)) ? __fpclassifyf((float)(ppos1->z)) : __fpclassifyd((double)(ppos1->z)) ) == 1)"
                );
      m_Do_printf::OSPanic("c_cc_s.cpp",0x333,&DAT_80364224);
    }
    fVar1 = param_4->x;
    uVar4 = (uint)fVar1 & 0x7f800000;
    if (uVar4 == 0x7f800000) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar6 = 2;
      }
      else {
        iVar6 = 1;
      }
    }
    else {
      if ((uVar4 < 0x7f800000) && (uVar4 == 0)) {
        if (((uint)fVar1 & 0x7fffff) == 0) {
          iVar6 = 3;
        }
        else {
          iVar6 = 5;
        }
      }
      else {
        iVar6 = 4;
      }
    }
    if (iVar6 == 1) {
      uVar8 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar8,"c_cc_s.cpp",0x335,
                 "!(((sizeof(ppos2->x) == sizeof(float)) ? __fpclassifyf((float)(ppos2->x)) : __fpclassifyd((double)(ppos2->x)) ) == 1)"
                );
      m_Do_printf::OSPanic("c_cc_s.cpp",0x335,&DAT_80364224);
    }
    fVar1 = param_4->y;
    uVar4 = (uint)fVar1 & 0x7f800000;
    if (uVar4 == 0x7f800000) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar6 = 2;
      }
      else {
        iVar6 = 1;
      }
    }
    else {
      if ((uVar4 < 0x7f800000) && (uVar4 == 0)) {
        if (((uint)fVar1 & 0x7fffff) == 0) {
          iVar6 = 3;
        }
        else {
          iVar6 = 5;
        }
      }
      else {
        iVar6 = 4;
      }
    }
    if (iVar6 == 1) {
      uVar8 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar8,"c_cc_s.cpp",0x336,
                 "!(((sizeof(ppos2->y) == sizeof(float)) ? __fpclassifyf((float)(ppos2->y)) : __fpclassifyd((double)(ppos2->y)) ) == 1)"
                );
      m_Do_printf::OSPanic("c_cc_s.cpp",0x336,&DAT_80364224);
    }
    fVar1 = param_4->z;
    uVar4 = (uint)fVar1 & 0x7f800000;
    if (uVar4 == 0x7f800000) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar6 = 2;
      }
      else {
        iVar6 = 1;
      }
    }
    else {
      if ((uVar4 < 0x7f800000) && (uVar4 == 0)) {
        if (((uint)fVar1 & 0x7fffff) == 0) {
          iVar6 = 3;
        }
        else {
          iVar6 = 5;
        }
      }
      else {
        iVar6 = 4;
      }
    }
    if (iVar6 == 1) {
      uVar8 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar8,"c_cc_s.cpp",0x337,
                 "!(((sizeof(ppos2->z) == sizeof(float)) ? __fpclassifyf((float)(ppos2->z)) : __fpclassifyd((double)(ppos2->z)) ) == 1)"
                );
      m_Do_printf::OSPanic("c_cc_s.cpp",0x337,&DAT_80364224);
    }
    bVar5 = false;
    if (((((SComponent::_3043 < param_2->x) && (param_2->x < SComponent::_3044)) &&
         (SComponent::_3043 < param_2->y)) &&
        ((param_2->y < SComponent::_3044 && (SComponent::_3043 < param_2->z)))) &&
       (param_2->z < SComponent::_3044)) {
      bVar5 = true;
    }
    if (!bVar5) {
      uVar8 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar8,"c_cc_s.cpp",0x33b,
                 "-1.0e32f < ppos1->x && ppos1->x < 1.0e32f && -1.0e32f < ppos1->y && ppos1->y < 1.0e32f && -1.0e32f < ppos1->z && ppos1->z < 1.0e32f"
                );
      m_Do_printf::OSPanic("c_cc_s.cpp",0x33b,&DAT_80364224);
    }
    bVar5 = false;
    if (((SComponent::_3043 < param_4->x) && (param_4->x < SComponent::_3044)) &&
       ((SComponent::_3043 < param_4->y &&
        (((param_4->y < SComponent::_3044 && (SComponent::_3043 < param_4->z)) &&
         (param_4->z < SComponent::_3044)))))) {
      bVar5 = true;
    }
    if (!bVar5) {
      uVar8 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar8,"c_cc_s.cpp",0x33f,
                 "-1.0e32f < ppos2->x && ppos2->x < 1.0e32f && -1.0e32f < ppos2->y && ppos2->y < 1.0e32f && -1.0e32f < ppos2->z && ppos2->z < 1.0e32f"
                );
      m_Do_printf::OSPanic("c_cc_s.cpp",0x33f,&DAT_80364224);
    }
  }
LAB_80244730:
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall cCcS::CalcArea(void) */

void __thiscall cCcS::CalcArea(cCcS *this)

{
  cCcD_ShapeAttr *pShapeAttr;
  cCcD_ShapeAttr *pShapeAttr_;
  cCcD_Obj **pObj;
  cM3dGAab local_38;
  
  local_38.vtbl = &::cM3dGAab::__vt;
  local_38.mMin.z = SComponent::_3100;
  local_38.mMin.y = SComponent::_3100;
  local_38.mMin.x = SComponent::_3100;
  local_38.mMax.z = SComponent::_3101;
  local_38.mMax.y = SComponent::_3101;
  local_38.mMax.x = SComponent::_3101;
  for (pObj = this->mpObj; pObj < this->mpObj + this->mObjCount; pObj = pObj + 1) {
    if ((*pObj != (cCcD_Obj *)0x0) &&
       (pShapeAttr = (cCcD_ShapeAttr *)(*(code *)(((*pObj)->parent).vtbl)->GetShapeAttr_1)(),
       pShapeAttr != (cCcD_ShapeAttr *)0x0)) {
      (*(code *)pShapeAttr->vtbl->CalcAabBox)();
      ::cM3dGAab::SetMinMax(&local_38,(cXyz *)pShapeAttr);
      ::cM3dGAab::SetMinMax(&local_38,&(pShapeAttr->mAab).mMax);
    }
  }
  cCcD_DivideArea::SetArea(&this->mDivideArea,&local_38);
  for (pObj = this->mpObj; pObj < this->mpObj + this->mObjCount; pObj = pObj + 1) {
    if ((*pObj != (cCcD_Obj *)0x0) &&
       (pShapeAttr_ = (cCcD_ShapeAttr *)(*(code *)(((*pObj)->parent).vtbl)->GetShapeAttr_1)(),
       pShapeAttr_ != (cCcD_ShapeAttr *)0x0)) {
      cCcD_DivideArea::CalcDivideInfo
                (&this->mDivideArea,&(*pObj)->mDivideInfo,(cM3dGAab *)pShapeAttr_,
                 (*pObj)->mAreaFlag & 2);
    }
  }
  return;
}


/* __thiscall cCcS::Move(void) */

void __thiscall cCcS::Move(cCcS *this)

{
  CalcArea(this);
  ChkAtTg(this);
  ChkCo(this);
  (*(code *)this->vtbl->dCcS__MoveAfterCheck)(this);
  this->mObjAtCount = 0;
  this->mObjTgCount = 0;
  this->mObjCoCount = 0;
  this->mObjCount = 0;
  return;
}


/* __thiscall cCcS::DrawClear(void) */

void __thiscall cCcS::DrawClear(cCcS *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0x100;
  do {
    *(undefined4 *)((int)this->mpObjAt + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this->mObjAtCount = 0;
  iVar1 = 0;
  iVar2 = 0x300;
  do {
    *(undefined4 *)((int)this->mpObjTg + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this->mObjTgCount = 0;
  iVar1 = 0;
  iVar2 = 0x100;
  do {
    *(undefined4 *)((int)this->mpObjCo + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this->mObjCoCount = 0;
  iVar1 = 0;
  iVar2 = 0x500;
  do {
    *(undefined4 *)((int)this->mpObj + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this->mObjCount = 0;
  return;
}


/* __thiscall cCcS::SetCoGCorrectProc(cCcD_Obj *,
                                      cCcD_Obj *) */

void __thiscall cCcS::SetCoGCorrectProc(cCcS *this,cCcD_Obj *param_1,cCcD_Obj *param_2)

{
  return;
}


/* __thiscall cCcS::ChkNoHitGCo(cCcD_Obj *,
                                cCcD_Obj *) */

undefined4 __thiscall cCcS::ChkNoHitGCo(cCcS *this,cCcD_Obj *param_1,cCcD_Obj *param_2)

{
  return 0;
}


/* __thiscall cCcS::SetAtTgGObjInf(bool,
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
cCcS::SetAtTgGObjInf
          (cCcS *this,bool param_1,bool param_2,cCcD_Obj *param_3,cCcD_Obj *param_4,
          cCcD_GObjInf *param_5,cCcD_GObjInf *param_6,cCcD_Stts *param_7,cCcD_Stts *param_8,
          cCcD_GStts *param_9,cCcD_GStts *param_10,cXyz *param_11)

{
  return;
}


/* __thiscall cCcS::ChkAtTgHitAfterCross(bool,
                                         bool,
                                         cCcD_GObjInf const *,
                                         cCcD_GObjInf const *,
                                         cCcD_Stts *,
                                         cCcD_Stts *,
                                         cCcD_GStts *,
                                         cCcD_GStts *) */

undefined4 __thiscall
cCcS::ChkAtTgHitAfterCross
          (cCcS *this,bool param_1,bool param_2,cCcD_GObjInf *param_3,cCcD_GObjInf *param_4,
          cCcD_Stts *param_5,cCcD_Stts *param_6,cCcD_GStts *param_7,cCcD_GStts *param_8)

{
  return 0;
}


/* __thiscall cCcS::SetCoGObjInf(bool,
                                 bool,
                                 cCcD_GObjInf *,
                                 cCcD_GObjInf *,
                                 cCcD_Stts *,
                                 cCcD_Stts *,
                                 cCcD_GStts *,
                                 cCcD_GStts *) */

void __thiscall
cCcS::SetCoGObjInf(cCcS *this,bool param_1,bool param_2,cCcD_GObjInf *param_3,cCcD_GObjInf *param_4,
                  cCcD_Stts *param_5,cCcD_Stts *param_6,cCcD_GStts *param_7,cCcD_GStts *param_8)

{
  return;
}


/* __thiscall cCcS::MoveAfterCheck(void) */

void __thiscall cCcS::MoveAfterCheck(cCcS *this)

{
  return;
}

