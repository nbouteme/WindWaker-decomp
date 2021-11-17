#include <d_cc_mass_s.h>
#include <d_cc_mass_s.h>
#include <d_com_inf_game.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <SComponent/c_m3d_g_aab.h>
#include <SComponent/c_cc_d.h>
#include <SComponent/c_m3d_g_cyl.h>
#include <mtx/vec.h>
#include <SComponent/c_math.h>
#include <JKernel/JKRHeap.h>
#include <dCcMassS_Obj.h>
#include <dCcMassS_Mng.h>
#include <cCcD_CylAttr.h>
#include <cCcD_CpsAttr.h>


/* __thiscall dCcMassS_Mng::dCcMassS_Mng(void) */

void __thiscall dCcMassS_Mng::dCcMassS_Mng(dCcMassS_Mng *this)

{
  this->vtbl = (undefined *)&__vt;
  (this->mDivideArea).mAab.vtbl = &::cM3dGAab::__vt;
  (this->mDivideArea).mAab.vtbl = (cM3dGAab__vtbl *)&cCcD_DivideArea::__vt;
  Runtime.PPCEABI.H::__construct_array
            (this->mMassObjs,dCcMassS_Obj::dCcMassS_Obj,dCcMassS_Obj::_dCcMassS_Obj,0x18,5);
  Runtime.PPCEABI.H::__construct_array
            (this->mMassAreas,dCcMassS_Obj::dCcMassS_Obj,dCcMassS_Obj::_dCcMassS_Obj,0x18,2);
  (this->mCylAttr).parent.vtbl = (cCcD_ShapeAttr__vtbl *)&::cCcD_ShapeAttr::__vt;
  (this->mCylAttr).parent.mAab.vtbl = &::cM3dGAab::__vt;
  (this->mCylAttr).mCyl.vtbl = (cCcD_CylAttr__vtbl *)&::cM3dGCyl::__vt;
  (this->mCylAttr).parent.vtbl = &::cCcD_CylAttr::__vt;
  (this->mCylAttr).mCyl.vtbl = &cCcD_CylAttr__vtbl_803951ac;
  (this->mCpsAttr).parent.vtbl = (cCcD_ShapeAttr__vtbl *)&::cCcD_ShapeAttr::__vt;
  (this->mCpsAttr).parent.mAab.vtbl = &::cM3dGAab::__vt;
  (this->mCpsAttr).mCps.parent.vtbl = (undefined *)&::cM3dGLin::__vt;
  (this->mCpsAttr).mCps.parent.vtbl = (undefined *)&::cM3dGCps::__vt;
  (this->mCpsAttr).parent.vtbl = &::cCcD_CpsAttr::__vt;
  (this->mCpsAttr).mCps.parent.vtbl = &DAT_8039520c;
  (this->mDivideInfo).vtbl = (undefined *)&cCcD_DivideInfo::__vt;
  Ct(this);
  return;
}


/* __thiscall dCcMassS_Mng::Ct(void) */

void __thiscall dCcMassS_Mng::Ct(dCcMassS_Mng *this)

{
  float fVar1;
  float fVar2;
  
  this->mFlag = 0;
  this->mResultCam = 0;
  fVar1 = d_cc_mass_s::0_0;
  (this->mCamTopPos).x = d_cc_mass_s::0_0;
  fVar2 = d_cc_mass_s::_1_0E9;
  (this->mCamTopPos).y = d_cc_mass_s::_1_0E9;
  (this->mCamTopPos).z = fVar1;
  (this->mCamBottomPos).x = fVar1;
  (this->mCamBottomPos).y = fVar2;
  (this->mCamBottomPos).z = fVar1;
  Clear(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dCcMassS_Mng::Prepare(void) */

void __thiscall dCcMassS_Mng::Prepare(dCcMassS_Mng *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  cXyz *pcVar4;
  ulong uVar5;
  cM3dGAab *pcVar6;
  dCcMassS_Obj *pdVar7;
  cCcD_Obj *pcVar8;
  cM3dGAab local_38;
  
  local_38.vtbl = &::cM3dGAab::__vt;
  local_38.mMin.z = d_cc_mass_s::_2562;
  local_38.mMin.y = d_cc_mass_s::_2562;
  local_38.mMin.x = d_cc_mass_s::_2562;
  local_38.mMax.z = d_cc_mass_s::_1_0E9;
  local_38.mMax.y = d_cc_mass_s::_1_0E9;
  local_38.mMax.x = d_cc_mass_s::_1_0E9;
  for (pdVar7 = this->mMassObjs; pdVar7 < this->mMassObjs + this->mMassObjCount; pdVar7 = pdVar7 + 1
      ) {
    pcVar8 = pdVar7->mpObj;
    if (pcVar8 == (cCcD_Obj *)0x0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_cc_mass_s.cpp",0x3d,"pobj != 0");
      m_Do_printf::OSPanic("d_cc_mass_s.cpp",0x3d,"Halt");
    }
    pcVar4 = (cXyz *)(*(code *)((pcVar8->parent).vtbl)->GetShapeAttr_1)(pcVar8);
    (**(code **)((int)pcVar4[2].y + 0x4c))();
    ::cM3dGAab::SetMinMax(&local_38,pcVar4);
    ::cM3dGAab::SetMinMax(&local_38,pcVar4 + 1);
  }
  pdVar7 = this->mMassAreas;
  while( true ) {
    if (this->mMassAreas + this->mMassAreaCount <= pdVar7) break;
    pcVar8 = pdVar7->mpObj;
    if (pcVar8 == (cCcD_Obj *)0x0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_cc_mass_s.cpp",0x49,"parea != 0");
      m_Do_printf::OSPanic("d_cc_mass_s.cpp",0x49,"Halt");
    }
    pcVar4 = (cXyz *)(*(code *)((pcVar8->parent).vtbl)->GetShapeAttr_1)(pcVar8);
    (**(code **)((int)pcVar4[2].y + 0x4c))();
    ::cM3dGAab::SetMinMax(&local_38,pcVar4);
    ::cM3dGAab::SetMinMax(&local_38,pcVar4 + 1);
    pdVar7 = pdVar7 + 1;
  }
  if ((this->mFlag & 1) != 0) {
    (*(code *)((this->mCpsAttr).parent.vtbl)->CalcAabBox)(&this->mCpsAttr);
    ::cM3dGAab::SetMinMax(&local_38,(cXyz *)&this->mCpsAttr);
    ::cM3dGAab::SetMinMax(&local_38,&(this->mCpsAttr).parent.mAab.mMax);
  }
  cCcD_DivideArea::SetArea(&this->mDivideArea,&local_38);
  for (pdVar7 = this->mMassObjs; pdVar7 < this->mMassObjs + this->mMassObjCount; pdVar7 = pdVar7 + 1
      ) {
    pcVar8 = pdVar7->mpObj;
    if (pcVar8 == (cCcD_Obj *)0x0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_cc_mass_s.cpp",0x5d,"pobj != 0");
      m_Do_printf::OSPanic("d_cc_mass_s.cpp",0x5d,"Halt");
    }
    pcVar6 = (cM3dGAab *)(*(code *)((pcVar8->parent).vtbl)->GetShapeAttr_1)(pcVar8);
    cCcD_DivideArea::CalcDivideInfo(&this->mDivideArea,&pdVar7->mDivideInfo,pcVar6,0);
  }
  pdVar7 = this->mMassAreas;
  while( true ) {
    if (this->mMassAreas + this->mMassAreaCount <= pdVar7) break;
    pcVar8 = pdVar7->mpObj;
    if (pcVar8 == (cCcD_Obj *)0x0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_cc_mass_s.cpp",0x68,"parea != 0");
      m_Do_printf::OSPanic("d_cc_mass_s.cpp",0x68,"Halt");
    }
    pcVar6 = (cM3dGAab *)(*(code *)((pcVar8->parent).vtbl)->GetShapeAttr_1)(pcVar8);
    cCcD_DivideArea::CalcDivideInfo(&this->mDivideArea,&pdVar7->mDivideInfo,pcVar6,0);
    pdVar7 = pdVar7 + 1;
  }
  if ((this->mFlag & 1) != 0) {
    cCcD_DivideArea::CalcDivideInfo
              (&this->mDivideArea,&this->mDivideInfo,(cM3dGAab *)&this->mCpsAttr,0);
  }
  fVar1 = d_cc_mass_s::0_0;
  (this->mCamTopPos).x = d_cc_mass_s::0_0;
  fVar2 = d_cc_mass_s::_1_0E9;
  (this->mCamTopPos).y = d_cc_mass_s::_1_0E9;
  (this->mCamTopPos).z = fVar1;
  fVar3 = d_cc_mass_s::_2562;
  this->mCamTopDist = d_cc_mass_s::_2562;
  (this->mCamBottomPos).x = fVar1;
  (this->mCamBottomPos).y = fVar2;
  (this->mCamBottomPos).z = fVar1;
  this->mCamBottomDist = fVar3;
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x800ad15c) */
/* __thiscall dCcMassS_Mng::Chk(cXyz *,
                                fopAc_ac_c * *,
                                dCcMassS_HitInf *) */

uint __thiscall
dCcMassS_Mng::Chk(dCcMassS_Mng *this,cXyz *pPos,fopAc_ac_c **pDstAct,dCcMassS_HitInf *pDstHitInf)

{
  undefined4 uVar1;
  dCcD_GObjInf *pInf;
  ulong uVar2;
  cCcD_ShapeAttr *pShape;
  char cVar3;
  dCcMassS_Obj *pdVar4;
  uint res;
  cCcD_Obj *pObj;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  float fVar7;
  undefined auStack120 [4];
  float local_74;
  undefined auStack112 [4];
  cCcD_DivideInfo cStack108;
  cXyz local_64;
  cXyz local_58;
  undefined auStack76 [24];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  cStack108.vtbl = (undefined *)&cCcD_DivideInfo::__vt;
  res = 0;
  *pDstAct = (fopAc_ac_c *)0x0;
  ::cM3dGCyl::SetC(&(this->mCylAttr).mCyl,pPos);
  (*(code *)((this->mCylAttr).parent.vtbl)->CalcAabBox)(&this->mCylAttr);
  cCcD_DivideArea::CalcDivideInfoOverArea(&this->mDivideArea,&cStack108,(cM3dGAab *)&this->mCylAttr)
  ;
  pDstHitInf->mpArea = (cCcD_Obj *)0x0;
  pDstHitInf->mpAtObj = (cCcD_Obj *)0x0;
  pDstHitInf->mpCoObj = (cCcD_Obj *)0x0;
  pDstHitInf->field_0xc = d_cc_mass_s::0_0;
  if ((this->mChkFlag & 8) != 0) {
    for (pdVar4 = this->mMassAreas; pdVar4 < this->mMassAreas + this->mMassAreaCount;
        pdVar4 = pdVar4 + 1) {
      cVar3 = cCcD_DivideInfo::Chk(&pdVar4->mDivideInfo,&cStack108);
      if (cVar3 != '\0') {
        pObj = pdVar4->mpObj;
        if (pObj == (cCcD_Obj *)0x0) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_cc_mass_s.cpp",0xae,"pobj != 0");
          m_Do_printf::OSPanic("d_cc_mass_s.cpp",0xae,"Halt");
        }
        uVar1 = (*(code *)((pObj->parent).vtbl)->GetShapeAttr_1)(pObj);
        if ((((pObj->parent).mObjCo.parent.mCommonFlag & EnableCheck) != 0) &&
           (cVar3 = (*(code *)((this->mCylAttr).parent.vtbl)->CrossCo_Shape)
                              (&this->mCylAttr,uVar1,auStack112), cVar3 != '\0')) {
          res = 4;
          *pDstAct = (pObj->mpStts->parent).mpActor;
          if (pDstHitInf != (dCcMassS_HitInf *)0x0) {
            pDstHitInf->mpArea = pObj;
          }
          if (pdVar4->mpCallback != (FuncDef551 *)0x0) {
            (*pdVar4->mpCallback)((pObj->mpStts->parent).mpActor,pPos,(ulong)this->mResultCamBit);
          }
        }
      }
    }
  }
  for (pdVar4 = this->mMassObjs; pdVar4 < this->mMassObjs + this->mMassObjCount; pdVar4 = pdVar4 + 1
      ) {
    cVar3 = cCcD_DivideInfo::Chk(&pdVar4->mDivideInfo,&cStack108);
    if (cVar3 != '\0') {
      pObj = pdVar4->mpObj;
      pInf = (dCcD_GObjInf *)(*(code *)((pObj->parent).vtbl)->GetGObjInf_1)(pObj);
      if (pObj == (cCcD_Obj *)0x0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_cc_mass_s.cpp",0xd6,"pobj != 0");
        m_Do_printf::OSPanic("d_cc_mass_s.cpp",0xd6,"Halt");
      }
      pShape = (cCcD_ShapeAttr *)(*(code *)((pObj->parent).vtbl)->GetShapeAttr_1)(pObj);
      if ((((((pObj->parent).mObjAt.parent.mCommonFlag & EnableCheck) != 0) &&
           (((pInf->mObjAt).parent.mGFlag & 8) == 0)) &&
          (cVar3 = (*(code *)((this->mCylAttr).parent.vtbl)->CrossAtTg_Shape)
                             (&this->mCylAttr,pShape,auStack76), cVar3 != '\0')) &&
         ((this->mChkFlag & 1) != 0)) {
        res = res | 1;
        *pDstAct = (pObj->mpStts->parent).mpActor;
        if (pDstHitInf != (dCcMassS_HitInf *)0x0) {
          pDstHitInf->mpAtObj = pObj;
        }
      }
      if (((((pObj->parent).mObjCo.parent.mCommonFlag & EnableCheck) != 0) &&
          (cVar3 = (*(code *)((this->mCylAttr).parent.vtbl)->CrossCo_Shape)
                             (&this->mCylAttr,pShape,&local_74), cVar3 != '\0')) &&
         ((this->mChkFlag & 2) != 0)) {
        res = res | 2;
        *pDstAct = (pObj->mpStts->parent).mpActor;
        if ((this->mChkFlag & 0x10) != 0) {
          mtx::PSVECSubtract(&((*pDstAct)->mCurrent).mPos,pPos,&local_58);
          local_58.y = d_cc_mass_s::0_0;
          fVar7 = mtx::PSVECMag(&local_58);
          if (SComponent::G_CM3D_F_ABS_MIN <= ABS(fVar7)) {
            mtx::PSVECScale(&local_58,&local_58,local_74 / fVar7);
          }
          else {
            local_58.x = d_cc_mass_s::1_0;
          }
          cCcD_Stts::PlusCcMove(&pObj->mpStts->parent,local_58.x,local_58.y,local_58.z);
        }
        if (pDstHitInf != (dCcMassS_HitInf *)0x0) {
          pDstHitInf->mpCoObj = pObj;
          pDstHitInf->field_0xc = local_74;
        }
      }
    }
  }
  if ((((this->mFlag & 1) != 0) &&
      (cVar3 = cCcD_DivideInfo::Chk(&this->mDivideInfo,&cStack108), cVar3 != '\0')) &&
     (cVar3 = (*(code *)((this->mCylAttr).parent.vtbl)->CrossCo_Cps)
                        (&this->mCylAttr,&this->mCpsAttr,auStack120), cVar3 != '\0')) {
    this->mResultCam = this->mResultCam | 1;
    this->mResultCam = this->mResultCam | 1 << this->mResultCamBit + 1;
    if (((this->mResultCam & 2) != 0) || ((this->mResultCam & 8) != 0)) {
      local_64.y = pPos->y + (this->mCylAttr).mCyl.mHeight;
      local_64.x = pPos->x;
      local_64.z = pPos->z;
      dVar6 = (double)(d_cc_mass_s::20_0 + local_64.y);
      if (((double)(this->mCamTopPos).y < dVar6) &&
         (fVar7 = mtx::PSVECSquareDistance(&local_64,(cXyz *)&(this->mCpsAttr).mCps),
         fVar7 < this->mCamTopDist)) {
        this->mCamTopDist = fVar7;
        (this->mCamTopPos).x = local_64.x;
        (this->mCamTopPos).y = local_64.y;
        (this->mCamTopPos).z = local_64.z;
      }
      if (((double)(this->mCamBottomPos).y < dVar6) &&
         (fVar7 = mtx::PSVECSquareDistance(&local_64,&(this->mCpsAttr).mCps.parent.mP1),
         fVar7 < this->mCamBottomDist)) {
        this->mCamBottomDist = fVar7;
        (this->mCamBottomPos).x = local_64.x;
        (this->mCamBottomPos).y = local_64.y;
        (this->mCamBottomPos).z = local_64.z;
      }
    }
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return res;
}


/* __thiscall dCcMassS_Mng::Clear(void) */

void __thiscall dCcMassS_Mng::Clear(dCcMassS_Mng *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  this->mMassObjCount = 0;
  this->mMassAreaCount = 0;
  iVar1 = 0;
  iVar3 = 5;
  do {
    iVar2 = (int)this->mMassObjs + iVar1 + -0x44;
    *(undefined4 *)(iVar2 + 0x44) = 0;
    *(undefined *)(iVar2 + 0x48) = 5;
    *(undefined4 *)(iVar2 + 0x4c) = 0;
    *(undefined4 *)(iVar2 + 0x50) = 0;
    iVar1 = iVar1 + 0x18;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar1 = 0;
  iVar3 = 2;
  do {
    iVar2 = (int)this->mMassObjs + iVar1 + -0x44;
    *(undefined4 *)(iVar2 + 0xc0) = 0;
    *(undefined *)(iVar2 + 0xc4) = 5;
    *(undefined4 *)(iVar2 + 200) = 0;
    *(undefined4 *)(iVar2 + 0xcc) = 0;
    iVar1 = iVar1 + 0x18;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  ::cM3dGCyl::SetR(&(this->mCylAttr).mCyl,d_cc_mass_s::0_0);
  ::cM3dGCyl::SetH(&(this->mCylAttr).mCyl,d_cc_mass_s::0_0);
  this->mChkFlag = 0;
  this->mResultCamBit = 4;
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x800ad2f0) */
/* __thiscall dCcMassS_Mng::Set(cCcD_Obj *,
                                unsigned char) */

void __thiscall dCcMassS_Mng::Set(dCcMassS_Mng *this,cCcD_Obj *param_1,byte param_2)

{
  byte bVar1;
  dCcMassS_Mng *pMassObj;
  dCcMassS_Obj *pdVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  float fVar7;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (this->mMassObjCount < 5) {
    pdVar2 = this->mMassObjs + this->mMassObjCount;
    pdVar2->mpObj = param_1;
    pdVar2->mPriority = param_2;
    pdVar2->mpCallback = (FuncDef551 *)0x0;
    this->mMassObjCount = this->mMassObjCount + 1;
  }
  else {
    iVar3 = 0;
    iVar4 = 0;
    dVar6 = (double)d_cc_mass_s::0_5;
    do {
      bVar1 = (&this->mMassObjs[0].mPriority)[iVar4];
      if ((param_2 < bVar1) ||
         ((bVar1 == param_2 &&
          (fVar7 = SComponent::cM_rndF(d_cc_mass_s::1_0), (double)fVar7 < dVar6)))) {
                    /* This is indexing into the mMassObj0 array in a weird way */
        pMassObj = (dCcMassS_Mng *)((int)this->mMassObjs + iVar4 + -0x44);
        pMassObj->mMassObjs[0].mpObj = param_1;
        pMassObj->mMassObjs[0].mPriority = param_2;
        pMassObj->mMassObjs[0].mpCallback = (FuncDef551 *)0x0;
        break;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x18;
    } while (iVar3 < 5);
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* __thiscall dCcMassS_Mng::SetAreaChk(cCcD_Obj *,
                                       unsigned char,
                                       void *(fopAc_ac_c *,cXyz *,unsigned long)) */

void __thiscall
dCcMassS_Mng::SetAreaChk(dCcMassS_Mng *this,cCcD_Obj *param_1,uchar param_2,FuncDef551 *param_3)

{
  dCcMassS_Mng *pMng;
  int iVar1;
  dCcMassS_Obj *pdVar2;
  int iVar3;
  
  if (this->mMassAreaCount < 2) {
    pdVar2 = this->mMassAreas + this->mMassAreaCount;
    pdVar2->mpObj = param_1;
    pdVar2->mPriority = param_2;
    pdVar2->mpCallback = param_3;
    this->mMassAreaCount = this->mMassAreaCount + 1;
    return;
  }
  iVar1 = 0;
  iVar3 = 2;
  do {
    if (param_2 < (&this->mMassAreas[0].mPriority)[iVar1]) {
      pMng = (dCcMassS_Mng *)((int)this->mMassObjs + iVar1 + -0x44);
      pMng->mMassAreas[0].mpObj = param_1;
      pMng->mMassAreas[0].mPriority = param_2;
      pMng->mMassAreas[0].mpCallback = param_3;
      return;
    }
    iVar1 = iVar1 + 0x18;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


/* __thiscall dCcMassS_Mng::SetCam(cM3dGCps const &) */

void __thiscall dCcMassS_Mng::SetCam(dCcMassS_Mng *this,cM3dGCps *param_1)

{
  float fVar1;
  
  fVar1 = param_1->mRadius;
  (this->mCpsAttr).mCps.parent.mP0.x = (param_1->parent).mP0.x;
  (this->mCpsAttr).mCps.parent.mP0.y = (param_1->parent).mP0.y;
  (this->mCpsAttr).mCps.parent.mP0.z = (param_1->parent).mP0.z;
  (this->mCpsAttr).mCps.parent.mP1.x = (param_1->parent).mP1.x;
  (this->mCpsAttr).mCps.parent.mP1.y = (param_1->parent).mP1.y;
  (this->mCpsAttr).mCps.parent.mP1.z = (param_1->parent).mP1.z;
  (this->mCpsAttr).mCps.mRadius = fVar1;
  this->mFlag = this->mFlag | 1;
  this->mResultCam = 0;
  return;
}


/* __thiscall dCcMassS_Mng::GetResultCam(void) const */

uint __thiscall dCcMassS_Mng::GetResultCam(dCcMassS_Mng *this)

{
  return this->mResultCam;
}


/* __thiscall dCcMassS_Mng::GetCamTopPos(Vec *) */

void __thiscall dCcMassS_Mng::GetCamTopPos(dCcMassS_Mng *this,cXyz *param_1)

{
  param_1->x = (this->mCamTopPos).x;
  param_1->y = (this->mCamTopPos).y;
  param_1->z = (this->mCamTopPos).z;
  return;
}


/* __thiscall cCcD_CpsAttr::~cCcD_CpsAttr(void) */

void __thiscall cCcD_CpsAttr::_cCcD_CpsAttr(cCcD_CpsAttr *this)

{
  short in_r4;
  
  if (this != (cCcD_CpsAttr *)0x0) {
    (this->parent).vtbl = &__vt;
    (this->mCps).parent.vtbl = &DAT_8039520c;
    if ((this != (cCcD_CpsAttr *)0xffffffe0) &&
       ((this->mCps).parent.vtbl = (undefined *)&::cM3dGCps::__vt,
       this != (cCcD_CpsAttr *)0xffffffe0)) {
      (this->mCps).parent.vtbl = (undefined *)&::cM3dGLin::__vt;
    }
    if ((this != (cCcD_CpsAttr *)0x0) &&
       ((this->parent).vtbl = (cCcD_ShapeAttr__vtbl *)&::cCcD_ShapeAttr::__vt,
       this != (cCcD_CpsAttr *)0x0)) {
      (this->parent).mAab.vtbl = &::cM3dGAab::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cCcD_CylAttr::~cCcD_CylAttr(void) */

void __thiscall cCcD_CylAttr::_cCcD_CylAttr(cCcD_CylAttr *this)

{
  short in_r4;
  
  if (this != (cCcD_CylAttr *)0x0) {
    (this->parent).vtbl = &__vt;
    (this->mCyl).vtbl = &cCcD_CylAttr__vtbl_803951ac;
    if (this != (cCcD_CylAttr *)0xffffffe0) {
      (this->mCyl).vtbl = (cCcD_CylAttr__vtbl *)&::cM3dGCyl::__vt;
    }
    if ((this != (cCcD_CylAttr *)0x0) &&
       ((this->parent).vtbl = (cCcD_ShapeAttr__vtbl *)&::cCcD_ShapeAttr::__vt,
       this != (cCcD_CylAttr *)0x0)) {
      (this->parent).mAab.vtbl = &::cM3dGAab::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cCcD_CylAttr::CrossAtTg(cCcD_ShapeAttr const &,
                                      cXyz *) const */

void __thiscall cCcD_CylAttr::CrossAtTg(cCcD_CylAttr *this,cCcD_ShapeAttr *param_1,cXyz *param_2)

{
  (*(code *)param_1->vtbl->CrossAtTg_Cyl)(param_1,this);
  return;
}


/* __thiscall cCcD_CylAttr::CrossCo(cCcD_ShapeAttr const &,
                                    float *) const */

void __thiscall cCcD_CylAttr::CrossCo(cCcD_CylAttr *this,cCcD_ShapeAttr *param_1,float *param_2)

{
  (*(code *)param_1->vtbl->CrossCo_Cyl)(param_1,this);
  return;
}


/* __thiscall dCcMassS_Obj::dCcMassS_Obj(void) */

void __thiscall dCcMassS_Obj::dCcMassS_Obj(dCcMassS_Obj *this)

{
  this->vtbl = (undefined *)&__vt;
  (this->mDivideInfo).vtbl = (undefined *)&cCcD_DivideInfo::__vt;
  return;
}

