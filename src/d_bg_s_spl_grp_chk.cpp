#include <d_bg_s_spl_grp_chk.h>
#include <dBgS_SplGrpChk.h>


/* __thiscall dBgS_SplGrpChk::dBgS_SplGrpChk(void) */

void __thiscall dBgS_SplGrpChk::dBgS_SplGrpChk(dBgS_SplGrpChk *this)

{
  float fVar1;
  cBgS_GrpPassChk *pGrpPassChk;
  
  (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  (this->mPolyInfo).mTriIdx = -1;
  (this->mPolyInfo).mBgIndex = 0x100;
  (this->mPolyInfo).mpBgW = (cBgW *)0x0;
  (this->mPolyInfo).mProcID = -1;
  (this->mChk).vtbl = &cBgS_Chk::__vt;
  (this->mChk).mpPolyPassChk = (cBgS_PolyPassChk *)0x0;
  (this->mChk).mpGrpPassChk = (cBgS_GrpPassChk *)0x0;
  (this->mChk).mbExcludeSameProcID = true;
  (this->mDChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
  (this->mDChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt;
  (this->mDChk).mPolyPassChk.parent.mbObjThrough = 0;
  (this->mDChk).mPolyPassChk.parent.mbCamThrough = 0;
  (this->mDChk).mPolyPassChk.parent.mbLinkThrough = 0;
  (this->mDChk).mPolyPassChk.parent.mbArrowsAndLightThrough = 0;
  (this->mDChk).mPolyPassChk.parent.mbBombThrough = 0;
  (this->mDChk).mPolyPassChk.parent.mbBoomerangThrough = 0;
  (this->mDChk).mPolyPassChk.parent.mbHookshotThrough = 0;
  (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
  (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt;
  (this->mDChk).mGrpPassChk.parent.mAttr = 1;
  (this->mDChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
  (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
  (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&__vt;
  (this->mChk).vtbl = (cBgS_Chk__vtbl *)&PTR_80372044;
  (this->mDChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80372050;
  (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_8037205c;
  (this->mChk).mpPolyPassChk = (cBgS_PolyPassChk *)&this->mDChk;
  pGrpPassChk = (cBgS_GrpPassChk *)&this->mDChk;
  if ((dBgS_Chk *)pGrpPassChk != (dBgS_Chk *)0x0) {
    pGrpPassChk = (cBgS_GrpPassChk *)&(this->mDChk).mGrpPassChk;
  }
  (this->mChk).mpGrpPassChk = pGrpPassChk;
  (this->mDChk).mGrpPassChk.parent.mAttr = (this->mDChk).mGrpPassChk.parent.mAttr & 0xfffffffe;
  fVar1 = d_bg_s_spl_grp_chk::0_0;
  (this->mStartPos).x = d_bg_s_spl_grp_chk::0_0;
  (this->mStartPos).y = fVar1;
  (this->mStartPos).z = fVar1;
  this->mEndPosY = d_bg_s_spl_grp_chk::1_0E9;
  this->mHeight = fVar1;
  return;
}


/* __thiscall dBgS_SplGrpChk::Init(void) */

void __thiscall dBgS_SplGrpChk::Init(dBgS_SplGrpChk *this)

{
  this->mFlags = this->mFlags & 0xfffffffd;
  this->mFlags = this->mFlags & 0xfffffffe;
  this->mHeight = (this->mStartPos).y;
  (this->mPolyInfo).mTriIdx = -1;
  (this->mPolyInfo).mBgIndex = 0x100;
  (this->mPolyInfo).mpBgW = (cBgW *)0x0;
  (this->mPolyInfo).mProcID = -1;
  return;
}

