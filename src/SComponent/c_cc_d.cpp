#include <SComponent/c_cc_d.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <SComponent/c_m3d.h>
#include <SComponent/c_m3d_g_tri.h>
#include <SComponent/c_m3d_g_aab.h>
#include <mtx/vec.h>
#include <SComponent/c_m3d_g_cyl.h>
#include <SComponent/c_m3d_g_sph.h>
#include <JKernel/JKRHeap.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <SComponent/c_cc_d.h>
#include <d_cc_mass_s.h>
#include <d_a_arrow.h>
#include <Demangler/cCcD_TriAttr.h>
#include <Demangler/cCcD_Stts.h>
#include <cCcD_SphAttr.h>
#include <cCcD_DivideArea.h>
#include <cCcD_CylAttr.h>
#include <cCcD_CpsAttr.h>
#include <cCcD_DivideInfo.h>
#include <Demangler/cCcD_Obj.h>

struct cXyz cCcD_ShapeAttr;

/* __thiscall cCcD_DivideInfo::Chk(cCcD_DivideInfo const &) const */

bool __thiscall cCcD_DivideInfo::Chk(cCcD_DivideInfo *this,cCcD_DivideInfo *pOther)

{
  uint uVar1;
  
  uVar1 = this->mRangeBits & pOther->mRangeBits;
  if ((uVar1 & 0x7ff) == 0) {
    return false;
  }
  if ((uVar1 & 0xffe00000) == 0) {
    return false;
  }
  return (uVar1 & 0x1ff800) != 0;
}


/* __thiscall cCcD_DivideArea::SetArea(cM3dGAab const &) */

void __thiscall cCcD_DivideArea::SetArea(cCcD_DivideArea *this,cM3dGAab *pAABB)

{
  (this->mAab).mMin.x = (pAABB->mMin).x;
  (this->mAab).mMin.y = (pAABB->mMin).y;
  (this->mAab).mMin.z = (pAABB->mMin).z;
  (this->mAab).mMax.x = (pAABB->mMax).x;
  (this->mAab).mMax.y = (pAABB->mMax).y;
  (this->mAab).mMax.z = (pAABB->mMax).z;
  this->mRangeX = SComponent::_2321 * ((this->mAab).mMax.x - (this->mAab).mMin.x);
  this->mbNoRangeX = ABS(this->mRangeX) < SComponent::G_CM3D_F_ABS_MIN;
  if (this->mbNoRangeX == false) {
    this->mRangeXInv = SComponent::_2322 / this->mRangeX;
  }
  this->mRangeY = SComponent::_2323 * ((this->mAab).mMax.y - (this->mAab).mMin.y);
  this->mbNoRangeY = ABS(this->mRangeY) < SComponent::G_CM3D_F_ABS_MIN;
  if (this->mbNoRangeY == false) {
    this->mRangeYInv = SComponent::_2322 / this->mRangeY;
  }
  this->mRangeZ = SComponent::_2321 * ((this->mAab).mMax.z - (this->mAab).mMin.z);
  this->mbNoRangeZ = ABS(this->mRangeZ) < SComponent::G_CM3D_F_ABS_MIN;
  if (this->mbNoRangeZ != false) {
    return;
  }
  this->mRangeZInv = SComponent::_2322 / this->mRangeZ;
  return;
}


/* __thiscall cCcD_DivideArea::CalcDivideInfo(cCcD_DivideInfo *,
                                              cM3dGAab const &,
                                              unsigned long) */

void __thiscall
cCcD_DivideArea::CalcDivideInfo
          (cCcD_DivideArea *this,cCcD_DivideInfo *pDst,cM3dGAab *pAABB,ulong bDisable)

{
  int iVar1;
  float fVar2;
  int iVar3;
  uint z;
  uint x;
  uint y;
  
  if (bDisable == 0) {
    if (this->mbNoRangeX == false) {
      fVar2 = (this->mAab).mMin.x;
      iVar1 = (int)(this->mRangeXInv * ((pAABB->mMin).x - fVar2));
      iVar3 = (int)(this->mRangeXInv * ((pAABB->mMax).x - fVar2));
      if (10 < iVar3) {
        iVar3 = 10;
      }
      x = (1 << iVar3 + 1) - 1;
      if (0 < iVar1) {
        x = x & ~((1 << iVar1 + -1) - 1U);
      }
    }
    else {
      x = 0x7ff;
    }
    if (this->mbNoRangeY == false) {
      fVar2 = (this->mAab).mMin.y;
      iVar1 = (int)(this->mRangeYInv * ((pAABB->mMin).y - fVar2));
      iVar3 = (int)(this->mRangeYInv * ((pAABB->mMax).y - fVar2));
      if (9 < iVar3) {
        iVar3 = 9;
      }
      y = (1 << iVar3 + 1) - 1;
      if (0 < iVar1) {
        y = y & ~((1 << iVar1 + -1) - 1U);
      }
    }
    else {
      y = 0x3ff;
    }
    if (this->mbNoRangeZ == false) {
      fVar2 = (this->mAab).mMin.z;
      iVar1 = (int)(this->mRangeZInv * ((pAABB->mMin).z - fVar2));
      iVar3 = (int)(this->mRangeZInv * ((pAABB->mMax).z - fVar2));
      if (10 < iVar3) {
        iVar3 = 10;
      }
      z = (1 << iVar3 + 1) - 1;
      if (0 < iVar1) {
        z = z & ~((1 << iVar1 + -1) - 1U);
      }
    }
    else {
      z = 0x7ff;
    }
    pDst->mRangeBits = x | y << 0xb | z << 0x15;
  }
  else {
    pDst->mRangeBits = 0xffffffff;
  }
  return;
}


/* __thiscall cCcD_DivideArea::CalcDivideInfoOverArea(cCcD_DivideInfo *,
                                                      cM3dGAab const &) */

void __thiscall
cCcD_DivideArea::CalcDivideInfoOverArea
          (cCcD_DivideArea *this,cCcD_DivideInfo *pDstInfo,cM3dGAab *pAABB)

{
  int iVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (this->mbNoRangeX == false) {
    fVar2 = (this->mAab).mMin.x;
    iVar1 = (int)(this->mRangeXInv * ((pAABB->mMin).x - fVar2));
    iVar3 = (int)(this->mRangeXInv * ((pAABB->mMax).x - fVar2));
    if (((iVar1 < 0) && (iVar3 < 0)) || ((10 < iVar1 && (10 < iVar3)))) {
      uVar5 = 0;
    }
    else {
      if (10 < iVar3) {
        iVar3 = 10;
      }
      uVar5 = (1 << iVar3 + 1) - 1;
      if (0 < iVar1) {
        uVar5 = uVar5 & ~((1 << iVar1 + -1) - 1U);
      }
    }
  }
  else {
    uVar5 = 0x7ff;
  }
  if (this->mbNoRangeY == false) {
    fVar2 = (this->mAab).mMin.y;
    iVar1 = (int)(this->mRangeYInv * ((pAABB->mMin).y - fVar2));
    iVar3 = (int)(this->mRangeYInv * ((pAABB->mMax).y - fVar2));
    if (((iVar1 < 0) && (iVar3 < 0)) || ((9 < iVar1 && (9 < iVar3)))) {
      uVar6 = 0;
    }
    else {
      if (9 < iVar3) {
        iVar3 = 9;
      }
      uVar6 = (1 << iVar3 + 1) - 1;
      if (0 < iVar1) {
        uVar6 = uVar6 & ~((1 << iVar1 + -1) - 1U);
      }
    }
  }
  else {
    uVar6 = 0x3ff;
  }
  if (this->mbNoRangeZ == false) {
    fVar2 = (this->mAab).mMin.z;
    iVar1 = (int)(this->mRangeZInv * ((pAABB->mMin).z - fVar2));
    iVar3 = (int)(this->mRangeZInv * ((pAABB->mMax).z - fVar2));
    if (((iVar1 < 0) && (iVar3 < 0)) || ((10 < iVar1 && (10 < iVar3)))) {
      uVar4 = 0;
    }
    else {
      if (10 < iVar3) {
        iVar3 = 10;
      }
      uVar4 = (1 << iVar3 + 1) - 1;
      if (0 < iVar1) {
        uVar4 = uVar4 & ~((1 << iVar1 + -1) - 1U);
      }
    }
  }
  else {
    uVar4 = 0x7ff;
  }
  pDstInfo->mRangeBits = uVar5 | uVar6 << 0xb | uVar4 << 0x15;
  return;
}


/* __thiscall cCcD_Stts::GetGStts(void) const */

undefined4 __thiscall cCcD_Stts::GetGStts(cCcD_Stts *this)

{
  return 0;
}


/* __thiscall cCcD_Stts::GetGStts(void) */

undefined4 __thiscall cCcD_Stts::GetGStts(cCcD_Stts *this)

{
  return 0;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall cCcD_Stts::Init(int,
                              int,
                              void *,
                              unsigned int) */

void __thiscall cCcD_Stts::Init(cCcD_Stts *this,int param_1,int param_2,void *pActor,uint pProcID)

{
  (*(code *)this->vtbl->Ct)();
  this->mCoRank = (byte)param_1;
  this->unk15 = (byte)param_2;
  this->mpActor = (fopAc_ac_c *)pActor;
  this->mActorProcID = pProcID;
  return;
}


/* __thiscall cCcD_Stts::Ct(void) */

void __thiscall cCcD_Stts::Ct(cCcD_Stts *this)

{
  float fVar1;
  
  fVar1 = SComponent::_2457;
  (this->mCcMove).x = SComponent::_2457;
  (this->mCcMove).y = fVar1;
  (this->mCcMove).z = fVar1;
  this->mpActor = (fopAc_ac_c *)0x0;
  this->mActorProcID = 0xffffffff;
  this->mCoRank = 0;
  this->unk15 = 0;
  this->mReceiveDamageAmount = 0;
  return;
}


/* __thiscall cCcD_Stts::PlusCcMove(float,
                                    float,
                                    float) */

void __thiscall cCcD_Stts::PlusCcMove(cCcD_Stts *this,float x,float y,float z)

{
  float fVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  ulong uVar5;
  
  (this->mCcMove).x = (this->mCcMove).x + x;
  (this->mCcMove).y = (this->mCcMove).y + y;
  (this->mCcMove).z = (this->mCcMove).z + z;
  fVar1 = (this->mCcMove).x;
  uVar2 = (uint)fVar1 & 0x7f800000;
  if (uVar2 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar2 < 0x7f800000) && (uVar2 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_cc_d.cpp",0x1bb,
               "!(((sizeof(m_cc_move.x) == sizeof(float)) ? __fpclassifyf((float)(m_cc_move.x)) : __fpclassifyd((double)(m_cc_move.x)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_cc_d.cpp",0x1bb,&DAT_80364002);
  }
  fVar1 = (this->mCcMove).y;
  uVar2 = (uint)fVar1 & 0x7f800000;
  if (uVar2 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar2 < 0x7f800000) && (uVar2 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_cc_d.cpp",0x1bc,
               "!(((sizeof(m_cc_move.y) == sizeof(float)) ? __fpclassifyf((float)(m_cc_move.y)) : __fpclassifyd((double)(m_cc_move.y)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_cc_d.cpp",0x1bc,&DAT_80364002);
  }
  fVar1 = (this->mCcMove).z;
  uVar2 = (uint)fVar1 & 0x7f800000;
  if (uVar2 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar2 < 0x7f800000) && (uVar2 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_cc_d.cpp",0x1bd,
               "!(((sizeof(m_cc_move.z) == sizeof(float)) ? __fpclassifyf((float)(m_cc_move.z)) : __fpclassifyd((double)(m_cc_move.z)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_cc_d.cpp",0x1bd,&DAT_80364002);
  }
  bVar3 = false;
  fVar1 = (this->mCcMove).x;
  if ((((SComponent::_2509 < fVar1) && (fVar1 < SComponent::_2510)) &&
      (fVar1 = (this->mCcMove).y, SComponent::_2509 < fVar1)) &&
     (((fVar1 < SComponent::_2510 && (fVar1 = (this->mCcMove).z, SComponent::_2509 < fVar1)) &&
      (fVar1 < SComponent::_2510)))) {
    bVar3 = true;
  }
  if (!bVar3) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_cc_d.cpp",0x1c1,
               "-1.0e32f < m_cc_move.x && m_cc_move.x < 1.0e32f && -1.0e32f < m_cc_move.y && m_cc_move.y < 1.0e32f && -1.0e32f < m_cc_move.z && m_cc_move.z < 1.0e32f"
              );
    m_Do_printf::OSPanic("c_cc_d.cpp",0x1c1,&DAT_80364002);
  }
  return;
}


/* __thiscall cCcD_Obj::Set(cCcD_SrcObj const &) */

void __thiscall cCcD_Obj::Set(cCcD_Obj *this,cCcD_SrcObj *pSrc)

{
  this->mAreaFlag = pSrc->mAreaFlag;
  (this->parent).mObjAt.parent.mCommonFlag = pSrc->mAtCommonFlag;
  (this->parent).mObjAt.mDamageTypes = pSrc->mAtDamageTypes;
  (this->parent).mObjAt.mDamage = pSrc->mAtDamage;
  (this->parent).mObjTg.parent.mCommonFlag = pSrc->mTgCommonFlag;
  (this->parent).mObjTg.mDamageTypes = pSrc->mTgDamageTypes;
  (this->parent).mObjCo.parent.mCommonFlag = pSrc->mCoCommonFlag;
  return;
}


/* __thiscall cCcD_TriAttr::CrossAtTg(cCcD_CpsAttr const &,
                                      cXyz *) const */

bool __thiscall cCcD_TriAttr::CrossAtTg(cCcD_TriAttr *this,cCcD_CpsAttr *param_1,cXyz *param_2)

{
  char cVar1;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined **local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_38 = (this->mTri).parent.mNorm.x;
  local_34 = (this->mTri).parent.mNorm.y;
  local_30 = (this->mTri).parent.mNorm.z;
  local_2c = (this->mTri).parent.mDist;
  local_28 = &cM3dGTri::__vt;
  local_24 = (this->mTri).mP0.x;
  local_20 = (this->mTri).mP0.y;
  local_1c = (this->mTri).mP0.z;
  local_18 = (this->mTri).mP1.x;
  local_14 = (this->mTri).mP1.y;
  local_10 = (this->mTri).mP1.z;
  local_c = (this->mTri).mP2.x;
  local_8 = (this->mTri).mP2.y;
  local_4 = (this->mTri).mP2.z;
  cVar1 = SComponent::cM3d_Cross_CpsTri(&param_1->mCps,&local_38);
  return cVar1 != '\0';
}


/* __thiscall cCcD_TriAttr::CrossAtTg(cCcD_CylAttr const &,
                                      cXyz *) const */

bool __thiscall cCcD_TriAttr::CrossAtTg(cCcD_TriAttr *this,cCcD_CylAttr *param_1,cXyz *param_2)

{
  char cVar1;
  
  cVar1 = cM3dGTri::cross(&this->mTri,&param_1->mCyl,(Vec *)param_2);
  return cVar1 != '\0';
}


/* __thiscall cCcD_TriAttr::CrossAtTg(cCcD_SphAttr const &,
                                      cXyz *) const */

bool __thiscall cCcD_TriAttr::CrossAtTg(cCcD_TriAttr *this,cCcD_SphAttr *param_1,cXyz *param_2)

{
  char cVar1;
  
  cVar1 = SComponent::cM3d_Cross_SphTri(&param_1->mSph,&this->mTri);
  return cVar1 != '\0';
}


/* __thiscall cCcD_TriAttr::CrossAtTg(cCcD_TriAttr const &,
                                      cXyz *) const */

bool __thiscall cCcD_TriAttr::CrossAtTg(cCcD_TriAttr *this,cCcD_TriAttr *param_1,cXyz *param_2)

{
  char cVar1;
  
  cVar1 = SComponent::cM3d_Cross_TriTri(&this->mTri,&param_1->mTri);
  return cVar1 != '\0';
}


/* __thiscall cCcD_TriAttr::CalcAabBox(void) */

void __thiscall cCcD_TriAttr::CalcAabBox(cCcD_TriAttr *this)

{
  float fVar1;
  cXyz local_38;
  cXyz local_2c;
  cXyz local_20;
  
  fVar1 = SComponent::_2675;
  (this->parent).mAab.mMin.z = SComponent::_2675;
  (this->parent).mAab.mMin.y = fVar1;
  (this->parent).mAab.mMin.x = fVar1;
  fVar1 = SComponent::_2676;
  (this->parent).mAab.mMax.z = SComponent::_2676;
  (this->parent).mAab.mMax.y = fVar1;
  (this->parent).mAab.mMax.x = fVar1;
  local_20.x = (this->mTri).mP0.x;
  local_20.y = (this->mTri).mP0.y;
  local_20.z = (this->mTri).mP0.z;
  ::cM3dGAab::SetMinMax((cM3dGAab *)this,&local_20);
  local_2c.x = (this->mTri).mP1.x;
  local_2c.y = (this->mTri).mP1.y;
  local_2c.z = (this->mTri).mP1.z;
  ::cM3dGAab::SetMinMax((cM3dGAab *)this,&local_2c);
  local_38.x = (this->mTri).mP2.x;
  local_38.y = (this->mTri).mP2.y;
  local_38.z = (this->mTri).mP2.z;
  ::cM3dGAab::SetMinMax((cM3dGAab *)this,&local_38);
  return;
}


/* __thiscall cCcD_TriAttr::GetNVec(cXyz const &,
                                    cXyz *) const */

undefined4 __thiscall cCcD_TriAttr::GetNVec(cCcD_TriAttr *this,cXyz *param_1,cXyz *param_2)

{
  double dVar1;
  
  dVar1 = (double)mtx::PSVECDotProduct(&this->mTri);
  if ((float)((double)(this->mTri).parent.mDist + dVar1) < SComponent::_2457) {
    param_2->x = (this->mTri).parent.mNorm.x;
    param_2->y = (this->mTri).parent.mNorm.y;
    param_2->z = (this->mTri).parent.mNorm.z;
    mtx::PSVECScale(param_2,param_2,SComponent::_2693);
  }
  else {
    param_2->x = (this->mTri).parent.mNorm.x;
    param_2->y = (this->mTri).parent.mNorm.y;
    param_2->z = (this->mTri).parent.mNorm.z;
  }
  return 1;
}


/* __thiscall cCcD_CpsAttr::CrossAtTg(cCcD_CpsAttr const &,
                                      cXyz *) const */

bool __thiscall cCcD_CpsAttr::CrossAtTg(cCcD_CpsAttr *this,cCcD_CpsAttr *param_1,cXyz *param_2)

{
  char cVar1;
  
  if (param_1 != (cCcD_CpsAttr *)0x0) {
    param_1 = (cCcD_CpsAttr *)&param_1->mCps;
  }
  cVar1 = SComponent::cM3d_Cross_CpsCps(&this->mCps,param_1);
  return cVar1 != '\0';
}


/* __thiscall cCcD_CpsAttr::CrossAtTg(cCcD_CylAttr const &,
                                      cXyz *) const */

bool __thiscall cCcD_CpsAttr::CrossAtTg(cCcD_CpsAttr *this,cCcD_CylAttr *param_1,cXyz *param_2)

{
  char cVar1;
  
  if (param_1 != (cCcD_CylAttr *)0x0) {
    param_1 = (cCcD_CylAttr *)&param_1->mCyl;
  }
  cVar1 = SComponent::cM3d_Cross_CpsCyl(&this->mCps,param_1);
  return cVar1 != '\0';
}


/* __thiscall cCcD_CpsAttr::CrossAtTg(cCcD_SphAttr const &,
                                      cXyz *) const */

bool __thiscall cCcD_CpsAttr::CrossAtTg(cCcD_CpsAttr *this,cCcD_SphAttr *param_1,cXyz *param_2)

{
  uint uVar1;
  
  if (param_1 != (cCcD_SphAttr *)0x0) {
    param_1 = (cCcD_SphAttr *)&param_1->mSph;
  }
  uVar1 = SComponent::cM3d_Cross_CpsSph(&this->mCps,(cM3dGSph *)param_1,param_2);
  return (uVar1 & 0xff) != 0;
}


/* __thiscall cCcD_CpsAttr::CrossAtTg(cCcD_TriAttr const &,
                                      cXyz *) const */

bool __thiscall cCcD_CpsAttr::CrossAtTg(cCcD_CpsAttr *this,cCcD_TriAttr *param_1,cXyz *param_2)

{
  char cVar1;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined **local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_38 = (param_1->mTri).parent.mNorm.x;
  local_34 = (param_1->mTri).parent.mNorm.y;
  local_30 = (param_1->mTri).parent.mNorm.z;
  local_2c = (param_1->mTri).parent.mDist;
  local_28 = &cM3dGTri::__vt;
  local_24 = (param_1->mTri).mP0.x;
  local_20 = (param_1->mTri).mP0.y;
  local_1c = (param_1->mTri).mP0.z;
  local_18 = (param_1->mTri).mP1.x;
  local_14 = (param_1->mTri).mP1.y;
  local_10 = (param_1->mTri).mP1.z;
  local_c = (param_1->mTri).mP2.x;
  local_8 = (param_1->mTri).mP2.y;
  local_4 = (param_1->mTri).mP2.z;
  cVar1 = SComponent::cM3d_Cross_CpsTri(&this->mCps,&local_38);
  return cVar1 != '\0';
}


/* __thiscall cCcD_CpsAttr::CrossCo(cCcD_CpsAttr const &,
                                    float *) const */

bool __thiscall cCcD_CpsAttr::CrossCo(cCcD_CpsAttr *this,cCcD_CpsAttr *param_1,float *param_2)

{
  char cVar1;
  undefined auStack24 [24];
  
  *param_2 = SComponent::_2457;
  if (param_1 != (cCcD_CpsAttr *)0x0) {
    param_1 = (cCcD_CpsAttr *)&param_1->mCps;
  }
  cVar1 = SComponent::cM3d_Cross_CpsCps(&this->mCps,param_1,auStack24);
  return cVar1 != '\0';
}


/* __thiscall cCcD_CpsAttr::CrossCo(cCcD_CylAttr const &,
                                    float *) const */

bool __thiscall cCcD_CpsAttr::CrossCo(cCcD_CpsAttr *this,cCcD_CylAttr *param_1,float *param_2)

{
  char cVar1;
  undefined auStack24 [24];
  
  *param_2 = SComponent::_2457;
  if (param_1 != (cCcD_CylAttr *)0x0) {
    param_1 = (cCcD_CylAttr *)&param_1->mCyl;
  }
  cVar1 = SComponent::cM3d_Cross_CpsCyl(&this->mCps,param_1,auStack24);
  return cVar1 != '\0';
}


/* __thiscall cCcD_CpsAttr::CrossCo(cCcD_SphAttr const &,
                                    float *) const */

bool __thiscall cCcD_CpsAttr::CrossCo(cCcD_CpsAttr *this,cCcD_SphAttr *param_1,float *param_2)

{
  uint uVar1;
  cXyz acStack24 [2];
  
  *param_2 = SComponent::_2457;
  if (param_1 != (cCcD_SphAttr *)0x0) {
    param_1 = (cCcD_SphAttr *)&param_1->mSph;
  }
  uVar1 = SComponent::cM3d_Cross_CpsSph(&this->mCps,(cM3dGSph *)param_1,acStack24);
  return (uVar1 & 0xff) != 0;
}


/* __thiscall cCcD_CpsAttr::CalcAabBox(void) */

void __thiscall cCcD_CpsAttr::CalcAabBox(cCcD_CpsAttr *this)

{
  float fVar1;
  
  fVar1 = SComponent::_2675;
  (this->parent).mAab.mMin.z = SComponent::_2675;
  (this->parent).mAab.mMin.y = fVar1;
  (this->parent).mAab.mMin.x = fVar1;
  fVar1 = SComponent::_2676;
  (this->parent).mAab.mMax.z = SComponent::_2676;
  (this->parent).mAab.mMax.y = fVar1;
  (this->parent).mAab.mMax.x = fVar1;
  ::cM3dGAab::SetMinMax((cM3dGAab *)this,(cXyz *)&this->mCps);
  ::cM3dGAab::SetMinMax((cM3dGAab *)this,&(this->mCps).parent.mP1);
  fVar1 = (this->mCps).mRadius;
  (this->parent).mAab.mMin.x = (this->parent).mAab.mMin.x - fVar1;
  (this->parent).mAab.mMin.y = (this->parent).mAab.mMin.y - fVar1;
  (this->parent).mAab.mMin.z = (this->parent).mAab.mMin.z - fVar1;
  (this->parent).mAab.mMax.x = (this->parent).mAab.mMax.x + fVar1;
  (this->parent).mAab.mMax.y = (this->parent).mAab.mMax.y + fVar1;
  (this->parent).mAab.mMax.z = (this->parent).mAab.mMax.z + fVar1;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x802423dc) */
/* __thiscall cCcD_CpsAttr::GetNVec(cXyz const &,
                                    cXyz *) const */

undefined4 __thiscall cCcD_CpsAttr::GetNVec(cCcD_CpsAttr *this,cXyz *param_1,cXyz *param_2)

{
  float fVar1;
  undefined4 uVar2;
  cXyz *pcVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f31;
  float fVar7;
  cXyz local_48;
  cXyz cStack60;
  cXyz cStack48;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  pcVar3 = &(this->mCps).parent.mP1;
  mtx::PSVECSubtract(pcVar3,(cXyz *)&this->mCps,&cStack48);
  dVar5 = (double)mtx::PSVECDotProduct(&cStack48,&cStack48);
  if (SComponent::G_CM3D_F_ABS_MIN <= (float)ABS(dVar5)) {
    mtx::PSVECSubtract(param_1,(cXyz *)&this->mCps,&cStack60);
    dVar6 = (double)mtx::PSVECDotProduct(&cStack60,&cStack48);
    fVar1 = (float)(dVar6 / dVar5);
    if (SComponent::_2457 <= fVar1) {
      if (fVar1 <= SComponent::_2322) {
        mtx::PSVECScale(&cStack48,&cStack48,fVar1);
        mtx::PSVECAdd(&cStack48,(cXyz *)&this->mCps,&local_48);
      }
      else {
        local_48.x = pcVar3->x;
        local_48.y = (this->mCps).parent.mP1.y;
        local_48.z = (this->mCps).parent.mP1.z;
      }
    }
    else {
      local_48.x = (this->mCps).parent.mP0.x;
      local_48.y = (this->mCps).parent.mP0.y;
      local_48.z = (this->mCps).parent.mP0.z;
    }
    mtx::PSVECSubtract(param_1,&local_48,param_2);
    fVar7 = mtx::PSVECMag(param_2);
    fVar1 = SComponent::_2457;
    if (SComponent::G_CM3D_F_ABS_MIN <= ABS(fVar7)) {
      mtx::PSVECNormalize(param_2,param_2);
      uVar2 = 1;
    }
    else {
      param_2->x = SComponent::_2457;
      param_2->y = fVar1;
      param_2->z = fVar1;
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return uVar2;
}


/* __thiscall cCcD_CylAttr::CrossAtTg(cCcD_CpsAttr const &,
                                      cXyz *) const */

bool __thiscall cCcD_CylAttr::CrossAtTg(cCcD_CylAttr *this,cCcD_CpsAttr *param_1,cXyz *param_2)

{
  char cVar1;
  
  if (param_1 != (cCcD_CpsAttr *)0x0) {
    param_1 = (cCcD_CpsAttr *)&param_1->mCps;
  }
  cVar1 = SComponent::cM3d_Cross_CpsCyl(param_1,&this->mCyl);
  return cVar1 != '\0';
}


/* __thiscall cCcD_CylAttr::CrossAtTg(cCcD_CylAttr const &,
                                      cXyz *) const */

bool __thiscall cCcD_CylAttr::CrossAtTg(cCcD_CylAttr *this,cCcD_CylAttr *param_1,cXyz *param_2)

{
  char cVar1;
  
  if (param_1 != (cCcD_CylAttr *)0x0) {
    param_1 = (cCcD_CylAttr *)&param_1->mCyl;
  }
  cVar1 = ::cM3dGCyl::cross(&this->mCyl,(cM3dGCyl *)param_1,param_2);
  return cVar1 != '\0';
}


/* __thiscall cCcD_CylAttr::CrossAtTg(cCcD_SphAttr const &,
                                      cXyz *) const */

bool __thiscall cCcD_CylAttr::CrossAtTg(cCcD_CylAttr *this,cCcD_SphAttr *param_1,cXyz *param_2)

{
  char cVar1;
  
  if (param_1 != (cCcD_SphAttr *)0x0) {
    param_1 = (cCcD_SphAttr *)&param_1->mSph;
  }
  cVar1 = ::cM3dGCyl::cross(&this->mCyl,(cM3dGSph *)param_1,param_2);
  return cVar1 != '\0';
}


/* __thiscall cCcD_CylAttr::CrossAtTg(cCcD_TriAttr const &,
                                      cXyz *) const */

bool __thiscall cCcD_CylAttr::CrossAtTg(cCcD_CylAttr *this,cCcD_TriAttr *param_1,cXyz *param_2)

{
  char cVar1;
  
  cVar1 = SComponent::cM3d_Cross_CylTri(&this->mCyl,&param_1->mTri);
  return cVar1 != '\0';
}


/* __thiscall cCcD_CylAttr::CrossCo(cCcD_CylAttr const &,
                                    float *) const */

bool __thiscall cCcD_CylAttr::CrossCo(cCcD_CylAttr *this,cCcD_CylAttr *param_1,float *param_2)

{
  uint uVar1;
  
  if (param_1 != (cCcD_CylAttr *)0x0) {
    param_1 = (cCcD_CylAttr *)&param_1->mCyl;
  }
  uVar1 = ::cM3dGCyl::cross(&this->mCyl,(cM3dGCyl *)param_1,param_2);
  return (uVar1 & 0xff) != 0;
}


/* __thiscall cCcD_CylAttr::CrossCo(cCcD_SphAttr const &,
                                    float *) const */

bool __thiscall cCcD_CylAttr::CrossCo(cCcD_CylAttr *this,cCcD_SphAttr *param_1,float *param_2)

{
  char cVar1;
  
  if (param_1 != (cCcD_SphAttr *)0x0) {
    param_1 = (cCcD_SphAttr *)&param_1->mSph;
  }
  cVar1 = ::cM3dGCyl::cross(&this->mCyl,(cM3dGSph *)param_1,param_2);
  return cVar1 != '\0';
}


/* __thiscall cCcD_CylAttr::CrossCo(cCcD_CpsAttr const &,
                                    float *) const */

bool __thiscall cCcD_CylAttr::CrossCo(cCcD_CylAttr *this,cCcD_CpsAttr *param_1,float *param_2)

{
  char cVar1;
  undefined auStack24 [24];
  
  *param_2 = SComponent::_2457;
  if (param_1 != (cCcD_CpsAttr *)0x0) {
    param_1 = (cCcD_CpsAttr *)&param_1->mCps;
  }
  cVar1 = SComponent::cM3d_Cross_CpsCyl(param_1,&this->mCyl,auStack24);
  return cVar1 != '\0';
}


/* __thiscall cCcD_CylAttr::CalcAabBox(void) */

void __thiscall cCcD_CylAttr::CalcAabBox(cCcD_CylAttr *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar1 = (this->mCyl).mCenter.x;
  fVar2 = (this->mCyl).mRadius;
  fVar3 = (this->mCyl).mCenter.y;
  fVar4 = (this->mCyl).mCenter.z;
  fVar5 = (this->mCyl).mHeight;
  (this->parent).mAab.mMin.x = fVar1 - fVar2;
  (this->parent).mAab.mMin.y = fVar3;
  (this->parent).mAab.mMin.z = fVar4 - fVar2;
  (this->parent).mAab.mMax.x = fVar1 + fVar2;
  (this->parent).mAab.mMax.y = fVar3 + fVar5;
  (this->parent).mAab.mMax.z = fVar4 + fVar2;
  return;
}


/* __thiscall cCcD_CylAttr::GetNVec(cXyz const &,
                                    cXyz *) const */

bool __thiscall cCcD_CylAttr::GetNVec(cCcD_CylAttr *this,cXyz *param_1,cXyz *param_2)

{
  float fVar1;
  bool bVar2;
  float fVar3;
  cXyz local_18;
  
  fVar1 = (this->mCyl).mCenter.y;
  local_18.y = param_1->y;
  if (fVar1 <= local_18.y) {
    fVar1 = fVar1 + (this->mCyl).mHeight;
    if (local_18.y <= fVar1) {
      local_18.x = (this->mCyl).mCenter.x;
      local_18.z = (this->mCyl).mCenter.z;
    }
    else {
      local_18.x = (this->mCyl).mCenter.x;
      local_18.z = (this->mCyl).mCenter.z;
      local_18.y = fVar1;
    }
  }
  else {
    local_18.x = (this->mCyl).mCenter.x;
    local_18.z = (this->mCyl).mCenter.z;
    local_18.y = fVar1;
  }
  mtx::PSVECSubtract(param_1,&local_18,param_2);
  fVar3 = mtx::PSVECMag(param_2);
  fVar1 = SComponent::_2457;
  bVar2 = SComponent::G_CM3D_F_ABS_MIN <= ABS(fVar3);
  if (bVar2) {
    mtx::PSVECNormalize(param_2,param_2);
  }
  else {
    param_2->x = SComponent::_2457;
    param_2->y = fVar1;
    param_2->z = fVar1;
  }
  return bVar2;
}


/* __thiscall cCcD_SphAttr::CrossAtTg(cCcD_CpsAttr const &,
                                      cXyz *) const */

bool __thiscall cCcD_SphAttr::CrossAtTg(cCcD_SphAttr *this,cCcD_CpsAttr *param_1,cXyz *param_2)

{
  uint uVar1;
  
  if (param_1 != (cCcD_CpsAttr *)0x0) {
    param_1 = (cCcD_CpsAttr *)&param_1->mCps;
  }
  uVar1 = SComponent::cM3d_Cross_CpsSph((cM3dGCps *)param_1,&this->mSph,param_2);
  return (uVar1 & 0xff) != 0;
}


/* __thiscall cCcD_SphAttr::CrossAtTg(cCcD_CylAttr const &,
                                      cXyz *) const */

bool __thiscall cCcD_SphAttr::CrossAtTg(cCcD_SphAttr *this,cCcD_CylAttr *param_1,cXyz *param_2)

{
  char cVar1;
  
  if (param_1 != (cCcD_CylAttr *)0x0) {
    param_1 = (cCcD_CylAttr *)&param_1->mCyl;
  }
  cVar1 = ::cM3dGSph::cross(&this->mSph,(cM3dGCyl *)param_1,param_2);
  return cVar1 != '\0';
}


/* __thiscall cCcD_SphAttr::CrossAtTg(cCcD_SphAttr const &,
                                      cXyz *) const */

bool __thiscall cCcD_SphAttr::CrossAtTg(cCcD_SphAttr *this,cCcD_SphAttr *param_1,cXyz *param_2)

{
  char cVar1;
  
  if (param_1 != (cCcD_SphAttr *)0x0) {
    param_1 = (cCcD_SphAttr *)&param_1->mSph;
  }
  cVar1 = ::cM3dGSph::cross(&this->mSph,(cM3dGSph *)param_1,param_2);
  return cVar1 != '\0';
}


/* __thiscall cCcD_SphAttr::CrossAtTg(cCcD_TriAttr const &,
                                      cXyz *) const */

bool __thiscall cCcD_SphAttr::CrossAtTg(cCcD_SphAttr *this,cCcD_TriAttr *param_1,cXyz *param_2)

{
  char cVar1;
  
  cVar1 = SComponent::cM3d_Cross_SphTri(&this->mSph,&param_1->mTri);
  return cVar1 != '\0';
}


/* __thiscall cCcD_SphAttr::CrossCo(cCcD_CylAttr const &,
                                    float *) const */

bool __thiscall cCcD_SphAttr::CrossCo(cCcD_SphAttr *this,cCcD_CylAttr *param_1,float *param_2)

{
  char cVar1;
  undefined auStack24 [24];
  
  if (param_1 != (cCcD_CylAttr *)0x0) {
    param_1 = (cCcD_CylAttr *)&param_1->mCyl;
  }
  cVar1 = SComponent::cM3d_Cross_CylSph(param_1,&this->mSph,auStack24,param_2);
  return cVar1 != '\0';
}


/* __thiscall cCcD_SphAttr::CrossCo(cCcD_SphAttr const &,
                                    float *) const */

bool __thiscall cCcD_SphAttr::CrossCo(cCcD_SphAttr *this,cCcD_SphAttr *param_1,float *param_2)

{
  char cVar1;
  
  if (param_1 != (cCcD_SphAttr *)0x0) {
    param_1 = (cCcD_SphAttr *)&param_1->mSph;
  }
  cVar1 = ::cM3dGSph::cross(&this->mSph,(cM3dGSph *)param_1,param_2);
  return cVar1 != '\0';
}


/* __thiscall cCcD_SphAttr::CrossCo(cCcD_CpsAttr const &,
                                    float *) const */

bool __thiscall cCcD_SphAttr::CrossCo(cCcD_SphAttr *this,cCcD_CpsAttr *param_1,float *param_2)

{
  uint uVar1;
  cXyz acStack24 [2];
  
  *param_2 = SComponent::_2457;
  if (param_1 != (cCcD_CpsAttr *)0x0) {
    param_1 = (cCcD_CpsAttr *)&param_1->mCps;
  }
  uVar1 = SComponent::cM3d_Cross_CpsSph((cM3dGCps *)param_1,&this->mSph,acStack24);
  return (uVar1 & 0xff) != 0;
}


/* __thiscall cCcD_SphAttr::CalcAabBox(void) */

void __thiscall cCcD_SphAttr::CalcAabBox(cCcD_SphAttr *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = (this->mSph).mCenter.x;
  fVar2 = (this->mSph).mCenter.y;
  fVar3 = (this->mSph).mCenter.z;
  fVar4 = (this->mSph).mRadius;
  (this->parent).mAab.mMin.x = fVar1 - fVar4;
  (this->parent).mAab.mMin.y = fVar2 - fVar4;
  (this->parent).mAab.mMin.z = fVar3 - fVar4;
  (this->parent).mAab.mMax.x = fVar1 + fVar4;
  (this->parent).mAab.mMax.y = fVar2 + fVar4;
  (this->parent).mAab.mMax.z = fVar3 + fVar4;
  return;
}


/* __thiscall cCcD_SphAttr::GetNVec(cXyz const &,
                                    cXyz *) const */

bool __thiscall cCcD_SphAttr::GetNVec(cCcD_SphAttr *this,cXyz *param_1,cXyz *param_2)

{
  float fVar1;
  bool bVar2;
  float fVar3;
  
  param_2->x = param_1->x - (this->mSph).mCenter.x;
  param_2->y = param_1->y - (this->mSph).mCenter.y;
  param_2->z = param_1->z - (this->mSph).mCenter.z;
  fVar3 = mtx::PSVECMag(param_2);
  fVar1 = SComponent::_2457;
  bVar2 = SComponent::G_CM3D_F_ABS_MIN <= ABS(fVar3);
  if (bVar2) {
    mtx::PSVECNormalize(param_2,param_2);
  }
  else {
    param_2->x = SComponent::_2457;
    param_2->y = fVar1;
    param_2->z = fVar1;
  }
  return bVar2;
}


/* __thiscall cCcD_TriAttr::CrossAtTg(cCcD_AabAttr const &,
                                      cXyz *) const */

undefined4 __thiscall
cCcD_TriAttr::CrossAtTg(cCcD_TriAttr *this,cCcD_AabAttr *param_1,cXyz *param_2)

{
  return 0;
}


/* __thiscall cCcD_TriAttr::CrossAtTg(cCcD_PntAttr const &,
                                      cXyz *) const */

undefined4 __thiscall
cCcD_TriAttr::CrossAtTg(cCcD_TriAttr *this,cCcD_PntAttr *param_1,cXyz *param_2)

{
  return 0;
}


/* __thiscall cCcD_TriAttr::CrossAtTg(cCcD_ShapeAttr const &,
                                      cXyz *) const */

void __thiscall cCcD_TriAttr::CrossAtTg(cCcD_TriAttr *this,cCcD_ShapeAttr *param_1,cXyz *param_2)

{
  (*(code *)param_1->vtbl->CrossAtTg_Tri)(param_1,this);
  return;
}


/* __thiscall cCcD_TriAttr::CrossCo(cCcD_SphAttr const &,
                                    float *) const */

undefined4 __thiscall cCcD_TriAttr::CrossCo(cCcD_TriAttr *this,cCcD_SphAttr *param_1,float *param_2)

{
  return 0;
}


/* __thiscall cCcD_TriAttr::CrossCo(cCcD_CylAttr const &,
                                    float *) const */

undefined4 __thiscall cCcD_TriAttr::CrossCo(cCcD_TriAttr *this,cCcD_CylAttr *param_1,float *param_2)

{
  return 0;
}


/* __thiscall cCcD_TriAttr::CrossCo(cCcD_AabAttr const &,
                                    float *) const */

undefined4 __thiscall cCcD_TriAttr::CrossCo(cCcD_TriAttr *this,cCcD_AabAttr *param_1,float *param_2)

{
  return 0;
}


/* __thiscall cCcD_TriAttr::CrossCo(cCcD_TriAttr const &,
                                    float *) const */

undefined4 __thiscall cCcD_TriAttr::CrossCo(cCcD_TriAttr *this,cCcD_TriAttr *param_1,float *param_2)

{
  return 0;
}


/* __thiscall cCcD_TriAttr::CrossCo(cCcD_CpsAttr const &,
                                    float *) const */

undefined4 __thiscall cCcD_TriAttr::CrossCo(cCcD_TriAttr *this,cCcD_CpsAttr *param_1,float *param_2)

{
  return 0;
}


/* __thiscall cCcD_TriAttr::CrossCo(cCcD_PntAttr const &,
                                    float *) const */

undefined4 __thiscall cCcD_TriAttr::CrossCo(cCcD_TriAttr *this,cCcD_PntAttr *param_1,float *param_2)

{
  return 0;
}


/* __thiscall cCcD_TriAttr::CrossCo(cCcD_ShapeAttr const &,
                                    float *) const */

void __thiscall cCcD_TriAttr::CrossCo(cCcD_TriAttr *this,cCcD_ShapeAttr *param_1,float *param_2)

{
  (*(code *)param_1->vtbl->CrossCo_Tri)(param_1,this);
  return;
}


/* __thiscall cCcD_TriAttr::~cCcD_TriAttr(void) */

void __thiscall cCcD_TriAttr::_cCcD_TriAttr(cCcD_TriAttr *this)

{
  short in_r4;
  
  if (this != (cCcD_TriAttr *)0x0) {
    (this->parent).vtbl = (cCcD_ShapeAttr__vtbl *)&__vt;
    (this->mTri).parent.vtbl = &DAT_8039526c;
    if ((this != (cCcD_TriAttr *)0xffffffe0) &&
       ((this->mTri).parent.vtbl = (undefined *)&cM3dGTri::__vt, this != (cCcD_TriAttr *)0xffffffe0)
       ) {
      (this->mTri).parent.vtbl = (undefined *)&cM3dGPla::__vt;
    }
    if ((this != (cCcD_TriAttr *)0x0) &&
       ((this->parent).vtbl = (cCcD_ShapeAttr__vtbl *)&::cCcD_ShapeAttr::__vt,
       this != (cCcD_TriAttr *)0x0)) {
      (this->parent).mAab.vtbl = &::cM3dGAab::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cCcD_Stts::ClrAt(void) */

void __thiscall cCcD_Stts::ClrAt(cCcD_Stts *this)

{
  return;
}


/* __thiscall cCcD_Stts::ClrTg(void) */

void __thiscall cCcD_Stts::ClrTg(cCcD_Stts *this)

{
  this->mReceiveDamageAmount = 0;
  return;
}


namespace SComponent {

void __sinit_c_cc_d_cpp(void)

{
  ::cCcD_ShapeAttr::m_virtual_center.x = ::cXyz::Zero.x;
  ::cCcD_ShapeAttr::m_virtual_center.y = ::cXyz::Zero.y;
  ::cCcD_ShapeAttr::m_virtual_center.z = ::cXyz::Zero.z;
  Runtime.PPCEABI.H::__register_global_object
            (&::cCcD_ShapeAttr::m_virtual_center,::cXyz::_cXyz,&_2440);
  return;
}

}

/* [thunk]:__thiscall cCcD_TriAttr::~cCcD_TriAttr(void) */

void __thiscall cCcD_TriAttr::_cCcD_TriAttr(cCcD_TriAttr *this)

{
  _cCcD_TriAttr((cCcD_TriAttr *)&this[-1].mTri.mP0.y);
  return;
}


/* [thunk]:__thiscall cCcD_CpsAttr::~cCcD_CpsAttr(void) */

void __thiscall cCcD_CpsAttr::_cCcD_CpsAttr(cCcD_CpsAttr *this)

{
  _cCcD_CpsAttr((cCcD_CpsAttr *)&this[-1].mCps);
  return;
}


/* [thunk]:__thiscall cCcD_CylAttr::~cCcD_CylAttr(void) */

void __thiscall cCcD_CylAttr::_cCcD_CylAttr(cCcD_CylAttr *this)

{
  _cCcD_CylAttr((cCcD_CylAttr *)&this[-1].parent.mAab.vtbl);
  return;
}


/* [thunk]:__thiscall cCcD_SphAttr::~cCcD_SphAttr(void) */

void __thiscall cCcD_SphAttr::_cCcD_SphAttr(cCcD_SphAttr *this)

{
  _cCcD_SphAttr((cCcD_SphAttr *)&this[-1].parent.mAab.mMax.z);
  return;
}

