#include <d_bg_s_wtr_chk.h>
#include <d_bg_s_spl_grp_chk.h>
#include <dBgS_WtrChk.h>


/* __thiscall dBgS_WtrChk::dBgS_WtrChk(void) */

void __thiscall dBgS_WtrChk::dBgS_WtrChk(dBgS_WtrChk *this)

{
  dBgS_SplGrpChk::dBgS_SplGrpChk(&this->parent);
  (this->parent).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&__vt;
  (this->parent).mChk.vtbl = (cBgS_Chk__vtbl *)&PTR_80372074;
  (this->parent).mDChk.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80372080;
  (this->parent).mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_8037208c;
  (this->parent).mDChk.mGrpPassChk.parent.mAttr = (this->parent).mDChk.mGrpPassChk.parent.mAttr | 2;
  return;
}

