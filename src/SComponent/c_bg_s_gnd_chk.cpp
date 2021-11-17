#include <SComponent/c_bg_s_gnd_chk.h>
#include <cBgS_GndChk.h>


/* __thiscall cBgS_GndChk::cBgS_GndChk(void) */

void __thiscall cBgS_GndChk::cBgS_GndChk(cBgS_GndChk *this)

{
  (this->parent).vtbl = &cBgS_Chk::__vt;
  (this->parent).mpPolyPassChk = (cBgS_PolyPassChk *)0x0;
  (this->parent).mpGrpPassChk = (cBgS_GrpPassChk *)0x0;
  (this->parent).mbExcludeSameProcID = true;
  (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  (this->mPolyInfo).mTriIdx = -1;
  (this->mPolyInfo).mBgIndex = 0x100;
  (this->mPolyInfo).mpBgW = (cBgW *)0x0;
  (this->mPolyInfo).mProcID = -1;
  (this->parent).vtbl = (cBgS_Chk__vtbl *)&__vt;
  (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371e90;
  (this->mPos).x = ::cXyz::Zero.x;
  (this->mPos).y = ::cXyz::Zero.y;
  (this->mPos).z = ::cXyz::Zero.z;
  (this->parent).mProcID = -1;
  this->mFlagIn = 3;
  return;
}

