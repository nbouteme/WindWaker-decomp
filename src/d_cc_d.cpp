#include <d_cc_d.h>
#include <f_pc_searcher.h>
#include <f_op_actor_iter.h>
#include <SComponent/c_cc_d.h>
#include <d_cc_d.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <SComponent/c_m3d_g_cyl.h>
#include <SComponent/c_xyz.h>
#include <SComponent/c_m3d_g_sph.h>
#include <dCcD_GObjAt.h>
#include <dCcD_GObjTg.h>
#include <Demangler/dCcD_GObjInf.h>
#include <cCcD_ObjCommonBase.h>
#include <dCcD_GStts.h>
#include <dCcD_Stts.h>
#include <cCcD_GStts.h>
#include <dCcD_GAtTgCoCommonBase.h>
#include <dCcD_Cps.h>
#include <cCcD_ObjTg.h>
#include <cCcD_ObjAt.h>
#include <cCcD_ObjCo.h>
#include <dCcD_Tri.h>
#include <dCcD_Sph.h>
#include <Demangler/dCcD_Cyl.h>
#include <Demangler/cCcD_Obj.h>
#include <cCcD_GObjInf.h>
#include <cCcD_ObjHitInf.h>
#include <dCcD_GObjCo.h>


/* __thiscall dCcD_GAtTgCoCommonBase::GetAc(void) */

fopAc_ac_c * __thiscall dCcD_GAtTgCoCommonBase::GetAc(dCcD_GAtTgCoCommonBase *this)

{
  fopAc_ac_c *pActor;
  int procID;
  
  procID = this->mActorProcID;
  if (procID == -1) {
    pActor = (fopAc_ac_c *)0x0;
  }
  else {
    if (this->mpActor == (fopAc_ac_c *)0x0) {
      pActor = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&procID);
      this->mpActor = pActor;
      if (this->mpActor == (fopAc_ac_c *)0x0) {
        this->mActorProcID = -1;
      }
    }
    pActor = this->mpActor;
  }
  return pActor;
}


/* __thiscall dCcD_GAtTgCoCommonBase::SetEffCounterTimer(void) */

void __thiscall dCcD_GAtTgCoCommonBase::SetEffCounterTimer(dCcD_GAtTgCoCommonBase *this)

{
  this->mEffCounterTimer = 5;
  return;
}


/* __thiscall dCcD_GStts::dCcD_GStts(void) */

void __thiscall dCcD_GStts::dCcD_GStts(dCcD_GStts *this)

{
  (this->parent).vtbl = (cCcD_GStts__vtbl *)&::cCcD_GStts::__vt;
  (this->parent).vtbl = (cCcD_GStts__vtbl *)&__vt;
  this->mAtSpl = 0;
  this->mTgSpl = 0;
  this->mRoomNo = 0;
  this->field_0x8 = 0xffff;
  this->mTgProcID = 0xffffffff;
  this->mOldTgProcID = 0xffffffff;
  this->mAtProcID = 0xffffffff;
  this->mOldAtProcID = 0xffffffff;
  this->mFlags = 0;
  return;
}


/* __thiscall dCcD_GStts::Ct(void) */

void __thiscall dCcD_GStts::Ct(dCcD_GStts *this)

{
  this->mAtSpl = 0;
  this->mTgSpl = 0;
  this->mRoomNo = 0;
  this->field_0x8 = 0xffff;
  this->mTgProcID = 0xffffffff;
  this->mOldTgProcID = 0xffffffff;
  this->mAtProcID = 0xffffffff;
  this->mOldAtProcID = 0xffffffff;
  this->mFlags = 0;
  return;
}


/* __thiscall dCcD_GStts::Move(void) */

void __thiscall dCcD_GStts::Move(dCcD_GStts *this)

{
  this->mOldTgProcID = this->mTgProcID;
  this->mTgProcID = 0;
  this->mOldAtProcID = this->mAtProcID;
  this->mAtProcID = 0;
  return;
}


/* __thiscall dCcD_Stts::Init(int,
                              int,
                              fopAc_ac_c *) */

void __thiscall dCcD_Stts::Init(dCcD_Stts *this,int param_1,int param_2,fopAc_ac_c *pActor)

{
  byte bVar1;
  uint pProcID;
  
  if (pActor == (fopAc_ac_c *)0x0) {
    pProcID = 0xffffffff;
  }
  else {
    if (pActor == (fopAc_ac_c *)0x0) {
      pProcID = 0xffffffff;
    }
    else {
      pProcID = (pActor->parent).parent.mBsPcId;
    }
  }
  cCcD_Stts::Init(&this->parent,param_1,param_2,pActor,pProcID);
  if (pActor == (fopAc_ac_c *)0x0) {
    bVar1 = 0;
    (this->mGStts).mFlags = (this->mGStts).mFlags | 1;
  }
  else {
    bVar1 = (pActor->mCurrent).mRoomNo;
  }
  if (bVar1 == 0xff) {
    (this->mGStts).mRoomNo = 0;
  }
  else {
    (this->mGStts).mRoomNo = bVar1;
  }
  return;
}


/* __thiscall dCcD_Stts::Ct(void) */

void __thiscall dCcD_Stts::Ct(dCcD_Stts *this)

{
  cCcD_Stts::Ct(&this->parent);
  ::dCcD_GStts::Ct(&this->mGStts);
  return;
}


/* __thiscall dCcD_GObjAt::Set(dCcD_SrcGObjAt const &) */

void __thiscall dCcD_GObjAt::Set(dCcD_GObjAt *this,dCcD_SrcGObjAt *pSrc)

{
  (this->parent).mGFlag = pSrc->mGFlag;
  (this->parent).mEffCounterTimer = 0;
  this->mSeType = pSrc->mSe;
  this->field_0x1d = 0;
  this->mHitmarkType = pSrc->mHitmarkType;
  this->mSpl = pSrc->mSpl;
  return;
}


/* __thiscall dCcD_GObjTg::Set(dCcD_SrcGObjTg const &) */

void __thiscall dCcD_GObjTg::Set(dCcD_GObjTg *this,dCcD_SrcGObjTg *pSrc)

{
  (this->parent).mGFlag = pSrc->mGFlag;
  (this->parent).mEffCounterTimer = 0;
  this->field_0x1c = pSrc->field_0x0;
  this->field_0x1d = 0;
  this->mHitmarkType = pSrc->mHitmarkType;
  this->mSpl = pSrc->mSpl;
  (this->mHitPos).x = ::cXyz::Zero.x;
  (this->mHitPos).y = ::cXyz::Zero.y;
  (this->mHitPos).z = ::cXyz::Zero.z;
  this->mpRotY = (short *)0x0;
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCcD_GObjInf::dCcD_GObjInf(void) */

void __thiscall dCcD_GObjInf::dCcD_GObjInf(dCcD_GObjInf *this)

{
  (this->parent).parent.parent.vtbl = (cCcD_GObjInf__vtbl *)&cCcD_ObjHitInf::__vt;
  (this->parent).parent.parent.mObjAt.parent.vtbl = (undefined *)&cCcD_ObjCommonBase::__vt;
  (this->parent).parent.parent.mObjAt.parent.mCommonFlag = 0;
  (this->parent).parent.parent.mObjAt.parent.mbHasPair = 0;
  (this->parent).parent.parent.mObjAt.parent.mpHitObj = (cCcD_Obj *)0x0;
  (this->parent).parent.parent.mObjAt.parent.vtbl = (undefined *)&cCcD_ObjAt::__vt;
  (this->parent).parent.parent.mObjAt.mDamageTypes = 0;
  (this->parent).parent.parent.mObjTg.parent.vtbl = (undefined *)&cCcD_ObjCommonBase::__vt;
  (this->parent).parent.parent.mObjTg.parent.mCommonFlag = 0;
  (this->parent).parent.parent.mObjTg.parent.mbHasPair = 0;
  (this->parent).parent.parent.mObjTg.parent.mpHitObj = (cCcD_Obj *)0x0;
  (this->parent).parent.parent.mObjTg.parent.vtbl = (undefined *)&cCcD_ObjTg::__vt;
  (this->parent).parent.parent.mObjTg.parent.mCommonFlag = 0;
  (this->parent).parent.parent.mObjTg.parent.mbHasPair = 0;
  (this->parent).parent.parent.mObjTg.parent.mpHitObj = (cCcD_Obj *)0x0;
  (this->parent).parent.parent.mObjCo.parent.vtbl = (undefined *)&cCcD_ObjCommonBase::__vt;
  (this->parent).parent.parent.mObjCo.parent.mCommonFlag = 0;
  (this->parent).parent.parent.mObjCo.parent.mbHasPair = 0;
  (this->parent).parent.parent.mObjCo.parent.mpHitObj = (cCcD_Obj *)0x0;
  (this->parent).parent.parent.mObjCo.parent.vtbl = (undefined *)&cCcD_ObjCo::__vt;
  (this->parent).parent.parent.vtbl = (cCcD_GObjInf__vtbl *)&::cCcD_Obj::__vt;
  (this->parent).parent.mDivideInfo.vtbl = (undefined *)&cCcD_DivideInfo::__vt;
  (this->parent).parent.mAreaFlag = 0;
  (this->parent).parent.parent.vtbl = (cCcD_GObjInf__vtbl *)&::cCcD_GObjInf::__vt;
  (this->parent).parent.parent.vtbl = (cCcD_GObjInf__vtbl *)&__vt;
  (this->mObjAt).parent.vtbl = (undefined *)&dCcD_GAtTgCoCommonBase::__vt;
  (this->mObjAt).parent.mGFlag = 0;
  (this->mObjAt).parent.mStatus = 0;
  (this->mObjAt).parent.mpCallback = (undefined *)0x0;
  (this->mObjAt).parent.mEffCounterTimer = 0;
  (this->mObjAt).parent.vtbl = (undefined *)&dCcD_GObjAt::__vt;
  (this->mObjTg).parent.vtbl = (undefined *)&dCcD_GAtTgCoCommonBase::__vt;
  (this->mObjTg).parent.mGFlag = 0;
  (this->mObjTg).parent.mStatus = 0;
  (this->mObjTg).parent.mpCallback = (undefined *)0x0;
  (this->mObjTg).parent.mEffCounterTimer = 0;
  (this->mObjTg).parent.vtbl = (undefined *)&dCcD_GObjTg::__vt;
  (this->mObjCo).parent.vtbl = (undefined *)&dCcD_GAtTgCoCommonBase::__vt;
  (this->mObjCo).parent.mGFlag = 0;
  (this->mObjCo).parent.mStatus = 0;
  (this->mObjCo).parent.mpCallback = (undefined *)0x0;
  (this->mObjCo).parent.mEffCounterTimer = 0;
  (this->mObjCo).parent.vtbl = (undefined *)&dCcD_GObjCo::__vt;
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCcD_GObjInf::~dCcD_GObjInf(void) */

void __thiscall dCcD_GObjInf::_dCcD_GObjInf(dCcD_GObjInf *this)

{
  short in_r4;
  
  if (this != (dCcD_GObjInf *)0x0) {
    (this->parent).parent.parent.vtbl = (cCcD_GObjInf__vtbl *)&__vt;
    if (this != (dCcD_GObjInf *)0xffffff24) {
      (this->mObjCo).parent.vtbl = (undefined *)&dCcD_GObjCo::__vt;
      if (this != (dCcD_GObjInf *)0xffffff24) {
        (this->mObjCo).parent.vtbl = (undefined *)&dCcD_GAtTgCoCommonBase::__vt;
      }
    }
    if (this != (dCcD_GObjInf *)0xffffff6c) {
      (this->mObjTg).parent.vtbl = (undefined *)&dCcD_GObjTg::__vt;
      if (this != (dCcD_GObjInf *)0xffffff6c) {
        (this->mObjTg).parent.vtbl = (undefined *)&dCcD_GAtTgCoCommonBase::__vt;
      }
    }
    if ((this != (dCcD_GObjInf *)0xffffffb0) &&
       ((this->mObjAt).parent.vtbl = (undefined *)&dCcD_GObjAt::__vt,
       this != (dCcD_GObjInf *)0xffffffb0)) {
      (this->mObjAt).parent.vtbl = (undefined *)&dCcD_GAtTgCoCommonBase::__vt;
    }
    if ((this != (dCcD_GObjInf *)0x0) &&
       ((this->parent).parent.parent.vtbl = (cCcD_GObjInf__vtbl *)&::cCcD_GObjInf::__vt,
       this != (dCcD_GObjInf *)0x0)) {
      (this->parent).parent.parent.vtbl = (cCcD_GObjInf__vtbl *)&::cCcD_Obj::__vt;
      if (this != (dCcD_GObjInf *)0xffffffb8) {
        (this->parent).parent.mDivideInfo.vtbl = (undefined *)&cCcD_DivideInfo::__vt;
      }
      if (this != (dCcD_GObjInf *)0x0) {
        (this->parent).parent.parent.vtbl = (cCcD_GObjInf__vtbl *)&cCcD_ObjHitInf::__vt;
        if (this != (dCcD_GObjInf *)0xffffffd4) {
          (this->parent).parent.parent.mObjCo.parent.vtbl = (undefined *)&cCcD_ObjCo::__vt;
          if (this != (dCcD_GObjInf *)0xffffffd4) {
            (this->parent).parent.parent.mObjCo.parent.vtbl = (undefined *)&cCcD_ObjCommonBase::__vt
            ;
          }
        }
        if ((this != (dCcD_GObjInf *)0xffffffe8) &&
           ((this->parent).parent.parent.mObjTg.parent.vtbl = (undefined *)&cCcD_ObjTg::__vt,
           this != (dCcD_GObjInf *)0xffffffe8)) {
          (this->parent).parent.parent.mObjTg.parent.vtbl = (undefined *)&cCcD_ObjCommonBase::__vt;
        }
        if ((this != (dCcD_GObjInf *)0x0) &&
           ((this->parent).parent.parent.mObjAt.parent.vtbl = (undefined *)&cCcD_ObjAt::__vt,
           this != (dCcD_GObjInf *)0x0)) {
          (this->parent).parent.parent.mObjAt.parent.vtbl = (undefined *)&cCcD_ObjCommonBase::__vt;
        }
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dCcD_GObjInf::GetGObjInf(void) */

void * __thiscall dCcD_GObjInf::GetGObjInf(dCcD_GObjInf *this)

{
  return this;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCcD_GObjInf::ClrAtHit(void) */

void __thiscall dCcD_GObjInf::ClrAtHit(dCcD_GObjInf *this)

{
  (this->parent).parent.parent.mObjAt.parent.mbHasPair =
       (this->parent).parent.parent.mObjAt.parent.mbHasPair & 0xfffffffe;
  (this->parent).parent.parent.mObjAt.parent.mpHitObj = (cCcD_Obj *)0x0;
  (this->mObjAt).parent.mActorProcID = -1;
  (this->mObjAt).parent.mpActor = (fopAc_ac_c *)0x0;
  (this->mObjAt).parent.mStatus = (this->mObjAt).parent.mStatus & ~Hit;
  (this->mObjAt).parent.mStatus = (this->mObjAt).parent.mStatus & ~AtHit;
  (this->mObjAt).parent.mEffCounterTimer = (this->mObjAt).parent.mEffCounterTimer - 1;
  if (-1 < (char)(this->mObjAt).parent.mEffCounterTimer) {
    return;
  }
  (this->mObjAt).parent.mEffCounterTimer = 0;
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCcD_GObjInf::ChkAtHit(void) */

undefined4 __thiscall dCcD_GObjInf::ChkAtHit(dCcD_GObjInf *this)

{
  undefined4 uVar1;
  fopAc_ac_c *pfVar2;
  
  if (((this->parent).parent.parent.mObjAt.parent.mbHasPair & 1) == 0) {
    uVar1 = 0;
  }
  else {
    if ((((this->mObjAt).parent.mStatus & AtHit) == 0) &&
       (pfVar2 = dCcD_GAtTgCoCommonBase::GetAc(&(this->mObjAt).parent), pfVar2 == (fopAc_ac_c *)0x0)
       ) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}


/* __thiscall dCcD_GObjInf::ResetAtHit(void) */

void __thiscall dCcD_GObjInf::ResetAtHit(dCcD_GObjInf *this)

{
  (*(code *)((this->parent).parent.parent.vtbl)->ClrAtHit)();
  (this->mObjAt).parent.mEffCounterTimer = 0;
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCcD_GObjInf::GetAtHitObj(void) */

cCcD_Obj * __thiscall dCcD_GObjInf::GetAtHitObj(dCcD_GObjInf *this)

{
  fopAc_ac_c *pfVar1;
  cCcD_Obj *pcVar2;
  
  if ((((this->mObjAt).parent.mStatus & AtHit) == 0) &&
     (pfVar1 = dCcD_GAtTgCoCommonBase::GetAc(&(this->mObjAt).parent), pfVar1 == (fopAc_ac_c *)0x0))
  {
    pcVar2 = (cCcD_Obj *)0x0;
  }
  else {
    pcVar2 = (this->parent).parent.parent.mObjAt.parent.mpHitObj;
  }
  return pcVar2;
}


/* __thiscall dCcD_GObjInf::GetAtHitGObj(void) */

dCcD_GObjInf * __thiscall dCcD_GObjInf::GetAtHitGObj(dCcD_GObjInf *this)

{
  cCcD_Obj *pObj;
  dCcD_GObjInf *pdVar1;
  
  pObj = (cCcD_Obj *)GetAtHitObj(this);
  if (pObj == (cCcD_Obj *)0x0) {
    pdVar1 = (dCcD_GObjInf *)0x0;
  }
  else {
    pdVar1 = d_cc_d::dCcD_GetGObjInf(pObj);
  }
  return pdVar1;
}


/* __thiscall dCcD_GObjInf::ChkAtNoGuard(void) */

bool __thiscall dCcD_GObjInf::ChkAtNoGuard(dCcD_GObjInf *this)

{
  return 7 < (this->mObjAt).mSpl;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCcD_GObjInf::ClrTgHit(void) */

void __thiscall dCcD_GObjInf::ClrTgHit(dCcD_GObjInf *this)

{
  (this->parent).parent.parent.mObjTg.parent.mbHasPair =
       (this->parent).parent.parent.mObjTg.parent.mbHasPair & 0xfffffffe;
  (this->parent).parent.parent.mObjTg.parent.mpHitObj = (cCcD_Obj *)0x0;
  (this->mObjTg).parent.mActorProcID = -1;
  (this->mObjTg).parent.mpActor = (fopAc_ac_c *)0x0;
  (this->mObjTg).parent.mStatus = (this->mObjTg).parent.mStatus & ~Hit;
  (this->mObjTg).parent.mStatus = (this->mObjTg).parent.mStatus & ~AtHit;
  (this->mObjTg).parent.mEffCounterTimer = (this->mObjTg).parent.mEffCounterTimer - 1;
  if (-1 < (char)(this->mObjTg).parent.mEffCounterTimer) {
    return;
  }
  (this->mObjTg).parent.mEffCounterTimer = 0;
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCcD_GObjInf::ChkTgHit(void) */

int __thiscall dCcD_GObjInf::ChkTgHit(dCcD_GObjInf *this)

{
  int ret;
  fopAc_ac_c *pfVar1;
  
  if (((this->parent).parent.parent.mObjTg.parent.mbHasPair & 1) == 0) {
    ret = 0;
  }
  else {
    if ((((this->mObjTg).parent.mStatus & Hit) == 0) &&
       (pfVar1 = dCcD_GAtTgCoCommonBase::GetAc(&(this->mObjTg).parent), pfVar1 == (fopAc_ac_c *)0x0)
       ) {
      ret = 0;
    }
    else {
      ret = 1;
    }
  }
  return ret;
}


/* __thiscall dCcD_GObjInf::ResetTgHit(void) */

void __thiscall dCcD_GObjInf::ResetTgHit(dCcD_GObjInf *this)

{
  (*(code *)((this->parent).parent.parent.vtbl)->ClrTgHit)();
  (this->mObjTg).parent.mEffCounterTimer = 0;
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCcD_GObjInf::GetTgHitObj(void) */

cCcD_Obj * __thiscall dCcD_GObjInf::GetTgHitObj(dCcD_GObjInf *this)

{
  fopAc_ac_c *pfVar1;
  cCcD_Obj *pcVar2;
  
  if ((((this->mObjTg).parent.mStatus & Hit) == 0) &&
     (pfVar1 = dCcD_GAtTgCoCommonBase::GetAc(&(this->mObjTg).parent), pfVar1 == (fopAc_ac_c *)0x0))
  {
    pcVar2 = (cCcD_Obj *)0x0;
  }
  else {
    pcVar2 = (this->parent).parent.parent.mObjTg.parent.mpHitObj;
  }
  return pcVar2;
}


/* __thiscall dCcD_GObjInf::GetTgHitGObj(void) */

dCcD_GObjInf * __thiscall dCcD_GObjInf::GetTgHitGObj(dCcD_GObjInf *this)

{
  cCcD_Obj *pObj;
  dCcD_GObjInf *pInf;
  
  pObj = GetTgHitObj(this);
  if (pObj == (cCcD_Obj *)0x0) {
    pInf = (dCcD_GObjInf *)0x0;
  }
  else {
    pInf = d_cc_d::dCcD_GetGObjInf(pObj);
  }
  return pInf;
}


/* __thiscall dCcD_GObjInf::GetTgHitObjSe(void) */

byte __thiscall dCcD_GObjInf::GetTgHitObjSe(dCcD_GObjInf *this)

{
  dCcD_GObjInf *pdVar1;
  byte bVar2;
  
  pdVar1 = GetTgHitGObj(this);
  if (pdVar1 == (dCcD_GObjInf *)0x0) {
    bVar2 = 0;
  }
  else {
    bVar2 = (pdVar1->mObjAt).mSeType;
  }
  return bVar2;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCcD_GObjInf::ClrCoHit(void) */

void __thiscall dCcD_GObjInf::ClrCoHit(dCcD_GObjInf *this)

{
  (this->parent).parent.parent.mObjCo.parent.mbHasPair =
       (this->parent).parent.parent.mObjCo.parent.mbHasPair & 0xfffffffe;
  (this->parent).parent.parent.mObjCo.parent.mpHitObj = (cCcD_Obj *)0x0;
  (this->mObjCo).parent.mActorProcID = -1;
  (this->mObjCo).parent.mpActor = (fopAc_ac_c *)0x0;
  (this->mObjCo).parent.mStatus = (this->mObjCo).parent.mStatus & ~Hit;
  (this->mObjCo).parent.mEffCounterTimer = (this->mObjCo).parent.mEffCounterTimer - 1;
  if (-1 < (char)(this->mObjCo).parent.mEffCounterTimer) {
    return;
  }
  (this->mObjCo).parent.mEffCounterTimer = 0;
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCcD_GObjInf::ChkCoHit(void) */

undefined4 __thiscall dCcD_GObjInf::ChkCoHit(dCcD_GObjInf *this)

{
  undefined4 uVar1;
  fopAc_ac_c *pfVar2;
  
  if (((this->parent).parent.parent.mObjCo.parent.mbHasPair & 1) == 0) {
    uVar1 = 0;
  }
  else {
    if ((((this->mObjCo).parent.mStatus & Hit) == 0) &&
       (pfVar2 = dCcD_GAtTgCoCommonBase::GetAc((dCcD_GAtTgCoCommonBase *)&this->mObjCo),
       pfVar2 == (fopAc_ac_c *)0x0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCcD_GObjInf::GetCoHitObj(void) */

cCcD_Obj * __thiscall dCcD_GObjInf::GetCoHitObj(dCcD_GObjInf *this)

{
  fopAc_ac_c *pfVar1;
  cCcD_Obj *pcVar2;
  
  if ((((this->mObjCo).parent.mStatus & Hit) == 0) &&
     (pfVar1 = dCcD_GAtTgCoCommonBase::GetAc((dCcD_GAtTgCoCommonBase *)&this->mObjCo),
     pfVar1 == (fopAc_ac_c *)0x0)) {
    pcVar2 = (cCcD_Obj *)0x0;
  }
  else {
    pcVar2 = (this->parent).parent.parent.mObjCo.parent.mpHitObj;
  }
  return pcVar2;
}


/* __thiscall dCcD_GObjInf::Set(dCcD_SrcGObjInf const &) */

void __thiscall dCcD_GObjInf::Set(dCcD_GObjInf *this,dCcD_SrcGObjInf *param_1)

{
  ::cCcD_Obj::Set((cCcD_Obj *)this,&param_1->parent);
  dCcD_GObjAt::Set(&this->mObjAt,&param_1->mAt);
  dCcD_GObjTg::Set(&this->mObjTg,&param_1->mTg);
  (this->mObjCo).parent.mGFlag = (param_1->mCo).mGFlag;
  (this->mObjCo).parent.mEffCounterTimer = 0;
  return;
}


namespace d_cc_d {

/* __stdcall dCcD_GetGObjInf(cCcD_Obj *) */

dCcD_GObjInf * dCcD_GetGObjInf(cCcD_Obj *pObj)

{
  ulong uVar1;
  dCcD_GObjInf *pdVar2;
  
  if (pObj == (cCcD_Obj *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_cc_d.cpp",0x213,"pobj != 0");
    m_Do_printf::OSPanic("d_cc_d.cpp",0x213,"Halt");
  }
  pdVar2 = (dCcD_GObjInf *)(*(code *)((pObj->parent).vtbl)->GetGObjInf_1)(pObj);
  return pdVar2;
}

}

/* __thiscall dCcD_Cps::Set(dCcD_SrcCps const &) */

void __thiscall dCcD_Cps::Set(dCcD_Cps *this,dCcD_SrcCps *param_1)

{
  dCcD_GObjInf::Set(&this->parent,&param_1->parent);
  (this->mAttr).mCps.parent.mP0.x = (param_1->mP0).x;
  (this->mAttr).mCps.parent.mP0.y = (param_1->mP0).y;
  (this->mAttr).mCps.parent.mP0.z = (param_1->mP0).z;
  (this->mAttr).mCps.parent.mP1.x = (param_1->mP1).x;
  (this->mAttr).mCps.parent.mP1.y = (param_1->mP1).y;
  (this->mAttr).mCps.parent.mP1.z = (param_1->mP1).z;
  (this->mAttr).mCps.mRadius = param_1->mRadius;
  return;
}


/* __thiscall dCcD_Tri::Set(dCcD_SrcTri const &) */

void __thiscall dCcD_Tri::Set(dCcD_Tri *this,dCcD_SrcTri *param_1)

{
  dCcD_GObjInf::Set((dCcD_GObjInf *)this,&param_1->parent);
  return;
}


/* __thiscall dCcD_Cyl::Set(dCcD_SrcCyl const &) */

void __thiscall dCcD_Cyl::Set(dCcD_Cyl *this,dCcD_SrcCyl *param_1)

{
  cM3dGCyl *this_00;
  cXyz local_18;
  
  dCcD_GObjInf::Set(&this->parent,&param_1->parent);
  local_18.x = (param_1->mCenter).x;
  local_18.y = (param_1->mCenter).y;
  local_18.z = (param_1->mCenter).z;
  this_00 = &(this->mCylAttr).mCyl;
  ::cM3dGCyl::SetC(this_00,&local_18);
  ::cM3dGCyl::SetR(this_00,param_1->mRadius);
  ::cM3dGCyl::SetH(this_00,param_1->mHeight);
  return;
}


/* __thiscall dCcD_Cyl::StartCAt(cXyz &) */

void __thiscall dCcD_Cyl::StartCAt(dCcD_Cyl *this,cXyz *param_1)

{
  float fVar1;
  float fVar2;
  
  fVar2 = ::cXyz::Zero.z;
  fVar1 = ::cXyz::Zero.y;
  (this->parent).mObjAt.mVel.x = ::cXyz::Zero.x;
  (this->parent).mObjAt.mVel.y = fVar1;
  (this->parent).mObjAt.mVel.z = fVar2;
  ::cM3dGCyl::SetC(&(this->mCylAttr).mCyl,param_1);
  return;
}


/* __thiscall dCcD_Cyl::StartCTg(cXyz &) */

void __thiscall dCcD_Cyl::StartCTg(dCcD_Cyl *this,cXyz *param_1)

{
  float fVar1;
  float fVar2;
  
  fVar2 = ::cXyz::Zero.z;
  fVar1 = ::cXyz::Zero.y;
  (this->parent).mObjTg.mVel.x = ::cXyz::Zero.x;
  (this->parent).mObjTg.mVel.y = fVar1;
  (this->parent).mObjTg.mVel.z = fVar2;
  ::cM3dGCyl::SetC(&(this->mCylAttr).mCyl,param_1);
  return;
}


/* __thiscall dCcD_Cyl::MoveCAtTg(cXyz &) */

void __thiscall dCcD_Cyl::MoveCAtTg(dCcD_Cyl *this,cXyz *param_1)

{
  cXyz local_28;
  float local_1c;
  float local_18;
  float local_14;
  
  ::cXyz::operator__(&local_28,param_1,&(this->mCylAttr).mCyl.mCenter);
  local_1c = local_28.x;
  local_18 = local_28.y;
  local_14 = local_28.z;
  (this->parent).mObjAt.mVel.x = local_28.x;
  (this->parent).mObjAt.mVel.y = local_28.y;
  (this->parent).mObjAt.mVel.z = local_28.z;
  (this->parent).mObjTg.mVel.x = local_28.x;
  (this->parent).mObjTg.mVel.y = local_28.y;
  (this->parent).mObjTg.mVel.z = local_28.z;
  ::cM3dGCyl::SetC(&(this->mCylAttr).mCyl,param_1);
  return;
}


/* __thiscall dCcD_Cyl::MoveCAt(cXyz &) */

void __thiscall dCcD_Cyl::MoveCAt(dCcD_Cyl *this,cXyz *param_1)

{
  cXyz local_28;
  float local_1c;
  float local_18;
  float local_14;
  
  ::cXyz::operator__(&local_28,param_1,&(this->mCylAttr).mCyl.mCenter);
  local_1c = local_28.x;
  local_18 = local_28.y;
  local_14 = local_28.z;
  (this->parent).mObjAt.mVel.x = local_28.x;
  (this->parent).mObjAt.mVel.y = local_28.y;
  (this->parent).mObjAt.mVel.z = local_28.z;
  ::cM3dGCyl::SetC(&(this->mCylAttr).mCyl,param_1);
  return;
}


/* __thiscall dCcD_Cyl::MoveCTg(cXyz &) */

void __thiscall dCcD_Cyl::MoveCTg(dCcD_Cyl *this,cXyz *param_1)

{
  cXyz local_28;
  float local_1c;
  float local_18;
  float local_14;
  
  ::cXyz::operator__(&local_28,param_1,&(this->mCylAttr).mCyl.mCenter);
  local_1c = local_28.x;
  local_18 = local_28.y;
  local_14 = local_28.z;
  (this->parent).mObjTg.mVel.x = local_28.x;
  (this->parent).mObjTg.mVel.y = local_28.y;
  (this->parent).mObjTg.mVel.z = local_28.z;
  ::cM3dGCyl::SetC(&(this->mCylAttr).mCyl,param_1);
  return;
}


/* __thiscall dCcD_Sph::Set(dCcD_SrcSph const &) */

void __thiscall dCcD_Sph::Set(dCcD_Sph *this,dCcD_SrcSph *param_1)

{
  cM3dGSph *this_00;
  cXyz local_18;
  
  dCcD_GObjInf::Set(&this->parent,&param_1->parent);
  local_18.x = (param_1->mCenter).x;
  local_18.y = (param_1->mCenter).y;
  local_18.z = (param_1->mCenter).z;
  this_00 = &(this->mSphAttr).mSph;
  ::cM3dGSph::SetC(this_00,&local_18);
  ::cM3dGSph::SetR(this_00,param_1->mRadius);
  return;
}


/* __thiscall dCcD_Sph::StartCAt(cXyz &) */

void __thiscall dCcD_Sph::StartCAt(dCcD_Sph *this,cXyz *param_1)

{
  float fVar1;
  float fVar2;
  
  fVar2 = ::cXyz::Zero.z;
  fVar1 = ::cXyz::Zero.y;
  (this->parent).mObjAt.mVel.x = ::cXyz::Zero.x;
  (this->parent).mObjAt.mVel.y = fVar1;
  (this->parent).mObjAt.mVel.z = fVar2;
  ::cM3dGSph::SetC(&(this->mSphAttr).mSph,param_1);
  return;
}


/* __thiscall dCcD_Sph::MoveCAt(cXyz &) */

void __thiscall dCcD_Sph::MoveCAt(dCcD_Sph *this,cXyz *param_1)

{
  cXyz local_28;
  float local_1c;
  float local_18;
  float local_14;
  
  ::cXyz::operator__(&local_28,param_1,&(this->mSphAttr).mSph.mCenter);
  local_1c = local_28.x;
  local_18 = local_28.y;
  local_14 = local_28.z;
  (this->parent).mObjAt.mVel.x = local_28.x;
  (this->parent).mObjAt.mVel.y = local_28.y;
  (this->parent).mObjAt.mVel.z = local_28.z;
  ::cM3dGSph::SetC(&(this->mSphAttr).mSph,param_1);
  return;
}


/* __thiscall cCcD_GStts::~cCcD_GStts(void) */

void __thiscall cCcD_GStts::_cCcD_GStts(cCcD_GStts *this)

{
  short in_r4;
  
  if ((this != (cCcD_GStts *)0x0) && (this->vtbl = (cCcD_GStts__vtbl *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall cCcD_GObjInf::~cCcD_GObjInf(void) */

void __thiscall cCcD_GObjInf::_cCcD_GObjInf(cCcD_GObjInf *this)

{
  short in_r4;
  
  if (this != (cCcD_GObjInf *)0x0) {
    (this->parent).parent.vtbl = (cCcD_GObjInf__vtbl *)&__vt;
    if (this != (cCcD_GObjInf *)0x0) {
      (this->parent).parent.vtbl = (cCcD_GObjInf__vtbl *)&::cCcD_Obj::__vt;
      if (this != (cCcD_GObjInf *)0xffffffb8) {
        (this->parent).mDivideInfo.vtbl = (undefined *)&cCcD_DivideInfo::__vt;
      }
      if (this != (cCcD_GObjInf *)0x0) {
        (this->parent).parent.vtbl = (cCcD_GObjInf__vtbl *)&cCcD_ObjHitInf::__vt;
        if (this != (cCcD_GObjInf *)0xffffffd4) {
          (this->parent).parent.mObjCo.parent.vtbl = (undefined *)&cCcD_ObjCo::__vt;
          if (this != (cCcD_GObjInf *)0xffffffd4) {
            (this->parent).parent.mObjCo.parent.vtbl = (undefined *)&cCcD_ObjCommonBase::__vt;
          }
        }
        if ((this != (cCcD_GObjInf *)0xffffffe8) &&
           ((this->parent).parent.mObjTg.parent.vtbl = (undefined *)&cCcD_ObjTg::__vt,
           this != (cCcD_GObjInf *)0xffffffe8)) {
          (this->parent).parent.mObjTg.parent.vtbl = (undefined *)&cCcD_ObjCommonBase::__vt;
        }
        if ((this != (cCcD_GObjInf *)0x0) &&
           ((this->parent).parent.mObjAt.parent.vtbl = (undefined *)&cCcD_ObjAt::__vt,
           this != (cCcD_GObjInf *)0x0)) {
          (this->parent).parent.mObjAt.parent.vtbl = (undefined *)&cCcD_ObjCommonBase::__vt;
        }
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cCcD_Obj::~cCcD_Obj(void) */

void __thiscall cCcD_Obj::_cCcD_Obj(cCcD_Obj *this)

{
  short in_r4;
  
  if (this != (cCcD_Obj *)0x0) {
    (this->parent).vtbl = (cCcD_GObjInf__vtbl *)&__vt;
    if (this != (cCcD_Obj *)0xffffffb8) {
      (this->mDivideInfo).vtbl = (undefined *)&cCcD_DivideInfo::__vt;
    }
    if (this != (cCcD_Obj *)0x0) {
      (this->parent).vtbl = (cCcD_GObjInf__vtbl *)&cCcD_ObjHitInf::__vt;
      if (this != (cCcD_Obj *)0xffffffd4) {
        (this->parent).mObjCo.parent.vtbl = (undefined *)&cCcD_ObjCo::__vt;
        if (this != (cCcD_Obj *)0xffffffd4) {
          (this->parent).mObjCo.parent.vtbl = (undefined *)&cCcD_ObjCommonBase::__vt;
        }
      }
      if ((this != (cCcD_Obj *)0xffffffe8) &&
         ((this->parent).mObjTg.parent.vtbl = (undefined *)&cCcD_ObjTg::__vt,
         this != (cCcD_Obj *)0xffffffe8)) {
        (this->parent).mObjTg.parent.vtbl = (undefined *)&cCcD_ObjCommonBase::__vt;
      }
      if ((this != (cCcD_Obj *)0x0) &&
         ((this->parent).mObjAt.parent.vtbl = (undefined *)&cCcD_ObjAt::__vt,
         this != (cCcD_Obj *)0x0)) {
        (this->parent).mObjAt.parent.vtbl = (undefined *)&cCcD_ObjCommonBase::__vt;
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cCcD_ObjHitInf::~cCcD_ObjHitInf(void) */

void __thiscall cCcD_ObjHitInf::_cCcD_ObjHitInf(cCcD_ObjHitInf *this)

{
  short in_r4;
  
  if (this != (cCcD_ObjHitInf *)0x0) {
    this->vtbl = (cCcD_GObjInf__vtbl *)&__vt;
    if (this != (cCcD_ObjHitInf *)0xffffffd4) {
      (this->mObjCo).parent.vtbl = (undefined *)&cCcD_ObjCo::__vt;
      if (this != (cCcD_ObjHitInf *)0xffffffd4) {
        (this->mObjCo).parent.vtbl = (undefined *)&cCcD_ObjCommonBase::__vt;
      }
    }
    if ((this != (cCcD_ObjHitInf *)0xffffffe8) &&
       ((this->mObjTg).parent.vtbl = (undefined *)&cCcD_ObjTg::__vt,
       this != (cCcD_ObjHitInf *)0xffffffe8)) {
      (this->mObjTg).parent.vtbl = (undefined *)&cCcD_ObjCommonBase::__vt;
    }
    if ((this != (cCcD_ObjHitInf *)0x0) &&
       ((this->mObjAt).parent.vtbl = (undefined *)&cCcD_ObjAt::__vt, this != (cCcD_ObjHitInf *)0x0))
    {
      (this->mObjAt).parent.vtbl = (undefined *)&cCcD_ObjCommonBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cCcD_ObjCo::~cCcD_ObjCo(void) */

void __thiscall cCcD_ObjCo::_cCcD_ObjCo(cCcD_ObjCo *this)

{
  short in_r4;
  
  if (this != (cCcD_ObjCo *)0x0) {
    (this->parent).vtbl = (undefined *)&__vt;
    if (this != (cCcD_ObjCo *)0x0) {
      (this->parent).vtbl = (undefined *)&cCcD_ObjCommonBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cCcD_ObjTg::~cCcD_ObjTg(void) */

void __thiscall cCcD_ObjTg::_cCcD_ObjTg(cCcD_ObjTg *this)

{
  short in_r4;
  
  if (this != (cCcD_ObjTg *)0x0) {
    (this->parent).vtbl = (undefined *)&__vt;
    if (this != (cCcD_ObjTg *)0x0) {
      (this->parent).vtbl = (undefined *)&cCcD_ObjCommonBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cCcD_ObjAt::~cCcD_ObjAt(void) */

void __thiscall cCcD_ObjAt::_cCcD_ObjAt(cCcD_ObjAt *this)

{
  short in_r4;
  
  if (this != (cCcD_ObjAt *)0x0) {
    (this->parent).vtbl = (undefined *)&__vt;
    if (this != (cCcD_ObjAt *)0x0) {
      (this->parent).vtbl = (undefined *)&cCcD_ObjCommonBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cCcD_ObjCommonBase::~cCcD_ObjCommonBase(void) */

void __thiscall cCcD_ObjCommonBase::_cCcD_ObjCommonBase(cCcD_ObjCommonBase *this)

{
  short in_r4;
  
  if ((this != (cCcD_ObjCommonBase *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall cCcD_Obj::GetGObjInf(void) */

undefined4 __thiscall cCcD_Obj::GetGObjInf(cCcD_Obj *this)

{
  return 0;
}


/* __thiscall cCcD_GObjInf::GetGObjInf(void) const */

void * __thiscall cCcD_GObjInf::GetGObjInf(cCcD_GObjInf *this)

{
  return this;
}


/* __thiscall cCcD_Obj::GetShapeAttr(void) const */

undefined4 __thiscall cCcD_Obj::GetShapeAttr(cCcD_Obj *this)

{
  return 0;
}


/* __thiscall cCcD_GObjInf::ClrAtHit(void) */

void __thiscall cCcD_GObjInf::ClrAtHit(cCcD_GObjInf *this)

{
  (this->parent).parent.mObjAt.parent.mbHasPair =
       (this->parent).parent.mObjAt.parent.mbHasPair & 0xfffffffe;
  (this->parent).parent.mObjAt.parent.mpHitObj = (cCcD_Obj *)0x0;
  return;
}


/* __thiscall cCcD_GObjInf::ClrTgHit(void) */

void __thiscall cCcD_GObjInf::ClrTgHit(cCcD_GObjInf *this)

{
  (this->parent).parent.mObjTg.parent.mbHasPair =
       (this->parent).parent.mObjTg.parent.mbHasPair & 0xfffffffe;
  (this->parent).parent.mObjTg.parent.mpHitObj = (cCcD_Obj *)0x0;
  return;
}


/* __thiscall cCcD_GObjInf::ClrCoHit(void) */

void __thiscall cCcD_GObjInf::ClrCoHit(cCcD_GObjInf *this)

{
  (this->parent).parent.mObjCo.parent.mbHasPair =
       (this->parent).parent.mObjCo.parent.mbHasPair & 0xfffffffe;
  (this->parent).parent.mObjCo.parent.mpHitObj = (cCcD_Obj *)0x0;
  return;
}


/* __thiscall cCcD_GObjInf::GetGObjInf(void) */

void __thiscall cCcD_GObjInf::GetGObjInf(cCcD_GObjInf *this)

{
  return;
}


/* __thiscall cCcD_Obj::GetGObjInf(void) const */

undefined4 __thiscall cCcD_Obj::GetGObjInf(cCcD_Obj *this)

{
  return 0;
}


/* __thiscall dCcD_GObjCo::~dCcD_GObjCo(void) */

void __thiscall dCcD_GObjCo::_dCcD_GObjCo(dCcD_GObjCo *this)

{
  short in_r4;
  
  if (this != (dCcD_GObjCo *)0x0) {
    (this->parent).vtbl = (undefined *)&__vt;
    if (this != (dCcD_GObjCo *)0x0) {
      (this->parent).vtbl = (undefined *)&dCcD_GAtTgCoCommonBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dCcD_GObjTg::~dCcD_GObjTg(void) */

void __thiscall dCcD_GObjTg::_dCcD_GObjTg(dCcD_GObjTg *this)

{
  short in_r4;
  
  if (this != (dCcD_GObjTg *)0x0) {
    (this->parent).vtbl = (undefined *)&__vt;
    if (this != (dCcD_GObjTg *)0x0) {
      (this->parent).vtbl = (undefined *)&dCcD_GAtTgCoCommonBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dCcD_GObjAt::~dCcD_GObjAt(void) */

void __thiscall dCcD_GObjAt::_dCcD_GObjAt(dCcD_GObjAt *this)

{
  short in_r4;
  
  if (this != (dCcD_GObjAt *)0x0) {
    (this->parent).vtbl = (undefined *)&__vt;
    if (this != (dCcD_GObjAt *)0x0) {
      (this->parent).vtbl = (undefined *)&dCcD_GAtTgCoCommonBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dCcD_GAtTgCoCommonBase::~dCcD_GAtTgCoCommonBase(void) */

void __thiscall dCcD_GAtTgCoCommonBase::_dCcD_GAtTgCoCommonBase(dCcD_GAtTgCoCommonBase *this)

{
  short in_r4;
  
  if ((this != (dCcD_GAtTgCoCommonBase *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dCcD_Stts::GetGStts(void) */

dCcD_GStts * __thiscall dCcD_Stts::GetGStts(dCcD_Stts *this)

{
  if (this == (dCcD_Stts *)0x0) {
    return (dCcD_GStts *)0x0;
  }
  return &this->mGStts;
}


/* __thiscall dCcD_Stts::ClrAt(void) */

void __thiscall dCcD_Stts::ClrAt(dCcD_Stts *this)

{
  (this->mGStts).mAtSpl = 0;
  return;
}


/* __thiscall dCcD_Stts::ClrTg(void) */

void __thiscall dCcD_Stts::ClrTg(dCcD_Stts *this)

{
  (this->parent).mReceiveDamageAmount = 0;
  (this->mGStts).mTgSpl = 0;
  return;
}


/* __thiscall dCcD_Stts::~dCcD_Stts(void) */

void __thiscall dCcD_Stts::_dCcD_Stts(dCcD_Stts *this)

{
  short in_r4;
  
  if (this != (dCcD_Stts *)0x0) {
    (this->parent).vtbl = &__vt.parent;
    (this->mGStts).parent.vtbl = (cCcD_GStts__vtbl *)0x8037ec40;
    if ((this != (dCcD_Stts *)0xffffffe4) &&
       ((this->mGStts).parent.vtbl = (cCcD_GStts__vtbl *)&::dCcD_GStts::__vt,
       this != (dCcD_Stts *)0xffffffe4)) {
      (this->mGStts).parent.vtbl = (cCcD_GStts__vtbl *)&::cCcD_GStts::__vt;
    }
    if (this != (dCcD_Stts *)0x0) {
      (this->parent).vtbl = &cCcD_Stts::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dCcD_GStts::~dCcD_GStts(void) */

void __thiscall dCcD_GStts::_dCcD_GStts(dCcD_GStts *this)

{
  short in_r4;
  
  if (this != (dCcD_GStts *)0x0) {
    (this->parent).vtbl = (cCcD_GStts__vtbl *)&__vt;
    if (this != (dCcD_GStts *)0x0) {
      (this->parent).vtbl = (cCcD_GStts__vtbl *)&::cCcD_GStts::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* [thunk]:__thiscall dCcD_Stts::~dCcD_Stts(void) */

void __thiscall dCcD_Stts::_dCcD_Stts(dCcD_Stts *this)

{
  _dCcD_Stts((dCcD_Stts *)&this[-1].mGStts.mAtSpl);
  return;
}

