#include <d_bg_s_acch.h>
#include <d_bg_s_acch.h>
#include <SComponent/c_bg_s_chk.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <d_bg_s_wtr_chk.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <SComponent/c_bg_s.h>
#include <d_bg_s.h>
#include <SComponent/c_bg_s_lin_chk.h>
#include <mtx/vec.h>
#include <SComponent/c_bg_w.h>
#include <d_a_sea.h>
#include <SComponent/c_m3d_g_cyl.h>
#include <cM3dGCir.h>
#include <dBgS_AcchCir.h>
#include <cM2dGCir.h>
#include <dBgS_ObjAcch.h>
#include <Demangler/cM3dGPla.h>
#include <Demangler/dBgS_Acch.h>
#include <dStage_roomControl_c.h>


namespace dBgS_Acch {
}

namespace cM3dGPla {
}

/* __thiscall dBgS_AcchCir::dBgS_AcchCir(void) */

void __thiscall dBgS_AcchCir::dBgS_AcchCir(dBgS_AcchCir *this)

{
  float fVar1;
  
  (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  (this->mPolyInfo).mTriIdx = -1;
  (this->mPolyInfo).mBgIndex = 0x100;
  (this->mPolyInfo).mpBgW = (cBgW *)0x0;
  (this->mPolyInfo).mProcID = -1;
  (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&__vt;
  (this->mCir).parent.vtbl = (undefined *)&::cM2dGCir::__vt;
  (this->mCir).parent.vtbl = (undefined *)&::cM3dGCir::__vt;
  this->mFlags = 0;
  fVar1 = d_bg_s_acch::0_0;
  this->field_0x28 = d_bg_s_acch::0_0;
  this->field_0x2c = fVar1;
  this->mWallHalfHeight = fVar1;
  this->mWallRadius = fVar1;
  this->field_0x3c = 0;
  this->field_0x38 = fVar1;
  return;
}


/* __thiscall dBgS_AcchCir::SetWallR(float) */

void __thiscall dBgS_AcchCir::SetWallR(dBgS_AcchCir *this,float radius)

{
  this->mWallRadius = radius;
  return;
}


/* __thiscall dBgS_AcchCir::SetWall(float,
                                    float) */

void __thiscall dBgS_AcchCir::SetWall(dBgS_AcchCir *this,float halfHeight,float radius)

{
  this->mWallHalfHeight = halfHeight;
  SetWallR(this,radius);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dBgS_Acch::~dBgS_Acch(void) */

void __thiscall dBgS_Acch::_dBgS_Acch(dBgS_Acch *this)

{
  short in_r4;
  
  if (this != (dBgS_Acch *)0x0) {
    (this->mChk).vtbl = (cBgS_Chk__vtbl *)&__vt;
    (this->mDChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_8037ea08;
    (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_8037ea14;
    if (this != (dBgS_Acch *)0xfffffe8c) {
      (this->mWtrChk).parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&dBgS_WtrChk::__vt;
      (this->mWtrChk).parent.mChk.vtbl = (cBgS_Chk__vtbl *)&PTR_80372074;
      (this->mWtrChk).parent.mDChk.mPolyPassChk.parent.vtbl =
           (cBgS_PolyPassChk__vtbl *)&PTR_80372080;
      (this->mWtrChk).parent.mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_8037208c;
      if (this != (dBgS_Acch *)0xfffffe8c) {
        (this->mWtrChk).parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&dBgS_SplGrpChk::__vt;
        (this->mWtrChk).parent.mChk.vtbl = (cBgS_Chk__vtbl *)&PTR_80372044;
        (this->mWtrChk).parent.mDChk.mPolyPassChk.parent.vtbl =
             (cBgS_PolyPassChk__vtbl *)&PTR_80372050;
        (this->mWtrChk).parent.mDChk.mGrpPassChk.parent.vtbl =
             (cBgS_GrpPassChk__vtbl *)&PTR_8037205c;
        if (this != (dBgS_Acch *)0xfffffe68) {
          (this->mWtrChk).parent.mDChk.mPolyPassChk.parent.vtbl =
               (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
          (this->mWtrChk).parent.mDChk.mGrpPassChk.parent.vtbl =
               (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
          if (this != (dBgS_Acch *)0xfffffe5c) {
            (this->mWtrChk).parent.mDChk.mGrpPassChk.parent.vtbl =
                 (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt;
            if (this != (dBgS_Acch *)0xfffffe5c) {
              (this->mWtrChk).parent.mDChk.mGrpPassChk.parent.vtbl =
                   (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
            }
          }
          if (this != (dBgS_Acch *)0xfffffe68) {
            (this->mWtrChk).parent.mDChk.mPolyPassChk.parent.vtbl =
                 (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt;
            if (this != (dBgS_Acch *)0xfffffe68) {
              (this->mWtrChk).parent.mDChk.mPolyPassChk.parent.vtbl =
                   (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
            }
          }
        }
        cBgS_Chk::_cBgS_Chk(&(this->mWtrChk).parent.mChk);
        if (this != (dBgS_Acch *)0xfffffe8c) {
          (this->mWtrChk).parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
        }
      }
    }
    if (this != (dBgS_Acch *)0xfffffed8) {
      (this->mRoofChk).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&dBgS_RoofChk::__vt;
      (this->mRoofChk).mChk.vtbl = (cBgS_Chk__vtbl *)&PTR_8037d40c;
      (this->mRoofChk).mDChk.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_8037d418;
      (this->mRoofChk).mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_8037d424;
      if (this != (dBgS_Acch *)0xfffffeb4) {
        (this->mRoofChk).mDChk.mPolyPassChk.parent.vtbl =
             (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
        (this->mRoofChk).mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
        if (this != (dBgS_Acch *)0xfffffea8) {
          (this->mRoofChk).mDChk.mGrpPassChk.parent.vtbl =
               (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt;
          if (this != (dBgS_Acch *)0xfffffea8) {
            (this->mRoofChk).mDChk.mGrpPassChk.parent.vtbl =
                 (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
          }
        }
        if (this != (dBgS_Acch *)0xfffffeb4) {
          (this->mRoofChk).mDChk.mPolyPassChk.parent.vtbl =
               (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt;
          if (this != (dBgS_Acch *)0xfffffeb4) {
            (this->mRoofChk).mDChk.mPolyPassChk.parent.vtbl =
                 (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
          }
        }
      }
      cBgS_Chk::_cBgS_Chk(&(this->mRoofChk).mChk);
      if (this != (dBgS_Acch *)0xfffffed8) {
        (this->mRoofChk).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
      }
    }
    if (this != (dBgS_Acch *)0xffffff2c) {
      (this->mGndChk).parent.parent.vtbl = &::dBgS_GndChk::__vt;
      (this->mGndChk).parent.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371f08;
      (this->mGndChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
      (this->mGndChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
      if (this != (dBgS_Acch *)0xfffffeec) {
        (this->mGndChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
        (this->mGndChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
        if (this != (dBgS_Acch *)0xfffffee0) {
          (this->mGndChk).mGrpPassChk.parent.vtbl =
               (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt;
          if (this != (dBgS_Acch *)0xfffffee0) {
            (this->mGndChk).mGrpPassChk.parent.vtbl =
                 (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
          }
        }
        if (this != (dBgS_Acch *)0xfffffeec) {
          (this->mGndChk).mPolyPassChk.parent.vtbl =
               (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt;
          if (this != (dBgS_Acch *)0xfffffeec) {
            (this->mGndChk).mPolyPassChk.parent.vtbl =
                 (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
          }
        }
      }
      if (this != (dBgS_Acch *)0xffffff2c) {
        (this->mGndChk).parent.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
        (this->mGndChk).parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371e90;
        if (this != (dBgS_Acch *)0xffffff18) {
          (this->mGndChk).parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
        }
        cBgS_Chk::_cBgS_Chk((cBgS_Chk *)&this->mGndChk);
      }
    }
    if (this != (dBgS_Acch *)0xffffff64) {
      (this->mPla).vtbl = (undefined *)&cM3dGPla::__vt;
    }
    if (this != (dBgS_Acch *)0xffffffa4) {
      (this->mCyl).vtbl = (cCcD_CylAttr__vtbl *)&::cM3dGCyl::__vt;
    }
    if (this != (dBgS_Acch *)0xffffffc0) {
      (this->mLin).vtbl = (undefined *)&::cM3dGLin::__vt;
    }
    if (this != (dBgS_Acch *)0xffffffec) {
      (this->mDChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
      if (this != (dBgS_Acch *)0xffffffe0) {
        (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt;
        if (this != (dBgS_Acch *)0xffffffe0) {
          (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
        }
      }
      if (this != (dBgS_Acch *)0xffffffec) {
        (this->mDChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt
        ;
        if (this != (dBgS_Acch *)0xffffffec) {
          (this->mDChk).mPolyPassChk.parent.vtbl =
               (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
        }
      }
    }
    cBgS_Chk::_cBgS_Chk(&this->mChk);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dBgS_Acch::dBgS_Acch(void) */

void __thiscall dBgS_Acch::dBgS_Acch(dBgS_Acch *this)

{
  float fVar1;
  float fVar2;
  dBgS_PolyPassChk *pdVar3;
  dBgS_Chk *pdVar4;
  
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
  (this->mChk).vtbl = (cBgS_Chk__vtbl *)&__vt;
  (this->mDChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_8037ea08;
  (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_8037ea14;
  (this->mLin).vtbl = (undefined *)&::cM3dGLin::__vt;
  (this->mCyl).vtbl = (cCcD_CylAttr__vtbl *)&::cM3dGCyl::__vt;
  (this->mPla).vtbl = (undefined *)&cM3dGPla::__vt;
  ::cBgS_GndChk::cBgS_GndChk(&(this->mGndChk).parent);
  (this->mGndChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
  (this->mGndChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt;
  (this->mGndChk).mPolyPassChk.parent.mbObjThrough = 0;
  (this->mGndChk).mPolyPassChk.parent.mbCamThrough = 0;
  (this->mGndChk).mPolyPassChk.parent.mbLinkThrough = 0;
  (this->mGndChk).mPolyPassChk.parent.mbArrowsAndLightThrough = 0;
  (this->mGndChk).mPolyPassChk.parent.mbBombThrough = 0;
  (this->mGndChk).mPolyPassChk.parent.mbBoomerangThrough = 0;
  (this->mGndChk).mPolyPassChk.parent.mbHookshotThrough = 0;
  (this->mGndChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
  (this->mGndChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt;
  (this->mGndChk).mGrpPassChk.parent.mAttr = 1;
  (this->mGndChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
  (this->mGndChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
  (this->mGndChk).parent.parent.vtbl = &::dBgS_GndChk::__vt;
  (this->mGndChk).parent.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371f08;
  (this->mGndChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  (this->mGndChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
  (this->mGndChk).parent.parent.mpPolyPassChk = (cBgS_PolyPassChk *)&(this->mGndChk).mPolyPassChk;
  pdVar3 = &(this->mGndChk).mPolyPassChk;
  if (pdVar3 != (dBgS_PolyPassChk *)0x0) {
    pdVar3 = (dBgS_PolyPassChk *)&(this->mGndChk).mGrpPassChk;
  }
  (this->mGndChk).parent.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pdVar3;
  (this->mRoofChk).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  (this->mRoofChk).mPolyInfo.mTriIdx = -1;
  (this->mRoofChk).mPolyInfo.mBgIndex = 0x100;
  (this->mRoofChk).mPolyInfo.mpBgW = (cBgW *)0x0;
  (this->mRoofChk).mPolyInfo.mProcID = -1;
  (this->mRoofChk).mChk.vtbl = &cBgS_Chk::__vt;
  (this->mRoofChk).mChk.mpPolyPassChk = (cBgS_PolyPassChk *)0x0;
  (this->mRoofChk).mChk.mpGrpPassChk = (cBgS_GrpPassChk *)0x0;
  (this->mRoofChk).mChk.mbExcludeSameProcID = true;
  (this->mRoofChk).mDChk.mPolyPassChk.parent.vtbl =
       (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
  (this->mRoofChk).mDChk.mPolyPassChk.parent.vtbl =
       (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt;
  (this->mRoofChk).mDChk.mPolyPassChk.parent.mbObjThrough = 0;
  (this->mRoofChk).mDChk.mPolyPassChk.parent.mbCamThrough = 0;
  (this->mRoofChk).mDChk.mPolyPassChk.parent.mbLinkThrough = 0;
  (this->mRoofChk).mDChk.mPolyPassChk.parent.mbArrowsAndLightThrough = 0;
  (this->mRoofChk).mDChk.mPolyPassChk.parent.mbBombThrough = 0;
  (this->mRoofChk).mDChk.mPolyPassChk.parent.mbBoomerangThrough = 0;
  (this->mRoofChk).mDChk.mPolyPassChk.parent.mbHookshotThrough = 0;
  (this->mRoofChk).mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt
  ;
  (this->mRoofChk).mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt
  ;
  (this->mRoofChk).mDChk.mGrpPassChk.parent.mAttr = 1;
  (this->mRoofChk).mDChk.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
  (this->mRoofChk).mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
  (this->mRoofChk).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&dBgS_RoofChk::__vt;
  (this->mRoofChk).mChk.vtbl = (cBgS_Chk__vtbl *)&PTR_8037d40c;
  (this->mRoofChk).mDChk.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_8037d418;
  (this->mRoofChk).mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_8037d424;
  (this->mRoofChk).mChk.mpPolyPassChk = (cBgS_PolyPassChk *)&(this->mRoofChk).mDChk;
  pdVar4 = &(this->mRoofChk).mDChk;
  if (pdVar4 != (dBgS_Chk *)0x0) {
    pdVar4 = (dBgS_Chk *)&(this->mRoofChk).mDChk.mGrpPassChk;
  }
  (this->mRoofChk).mChk.mpGrpPassChk = (cBgS_GrpPassChk *)pdVar4;
  fVar1 = d_bg_s_acch::0_0;
  (this->mRoofChk).mPos.x = d_bg_s_acch::0_0;
  (this->mRoofChk).mPos.y = fVar1;
  (this->mRoofChk).mPos.z = fVar1;
  (this->mRoofChk).mChk.mProcID = -1;
  this->field_0x16c = 0;
  dBgS_WtrChk::dBgS_WtrChk(&this->mWtrChk);
  (this->mChk).mpPolyPassChk = (cBgS_PolyPassChk *)&this->mDChk;
  pdVar4 = &this->mDChk;
  if (pdVar4 != (dBgS_Chk *)0x0) {
    pdVar4 = (dBgS_Chk *)&(this->mDChk).mGrpPassChk;
  }
  (this->mChk).mpGrpPassChk = (cBgS_GrpPassChk *)pdVar4;
  this->mFlags = 0;
  this->mFlags = this->mFlags | 8;
  this->mpPos = (cXyz *)0x0;
  this->mpOldPos = (cXyz *)0x0;
  this->field_0x34 = (cXyz *)0x0;
  fVar2 = d_bg_s_acch::_1_0E9;
  this->field_0x94 = d_bg_s_acch::_1_0E9;
  fVar1 = d_bg_s_acch::0_0;
  this->mGroundUpY = d_bg_s_acch::0_0;
  this->field_0x98 = d_bg_s_acch::_4328;
  this->mGroundUpYDiff = fVar1;
  this->field_0xb0 = 0;
  this->field_0xb4 = fVar1;
  this->field_0xb8 = fVar1;
  this->mAcchCirCount = 0;
  this->mpAcchCir = (dBgS_AcchCir *)0x0;
  this->field_0xbc = fVar1;
  this->field_0xc0 = fVar1;
  this->field_0xc4 = fVar1;
  this->field_0xc8 = d_bg_s_acch::_4329;
  this->field_0x38 = (csXyz *)0x0;
  this->field_0x3c = (csXyz *)0x0;
  this->mpActor = (fopAc_ac_c *)0x0;
  this->mpOutPolyInfo = (cBgS_PolyInfo *)0x0;
  this->field_0xd0 = fVar2;
  return;
}


/* __thiscall dBgS_Acch::Init(void) */

void __thiscall dBgS_Acch::Init(dBgS_Acch *this)

{
  int iVar1;
  dBgS_AcchCir *pCir;
  int iVar2;
  
  this->mFlags = this->mFlags & 0xffffffef;
  iVar1 = 0;
  for (iVar2 = 0; iVar2 < this->mAcchCirCount; iVar2 = iVar2 + 1) {
    pCir = (dBgS_AcchCir *)((int)&(this->mpAcchCir->mPolyInfo).mTriIdx + iVar1);
    pCir->mFlags = pCir->mFlags & 0xfffffffd;
    (pCir->mPolyInfo).mTriIdx = -1;
    (pCir->mPolyInfo).mBgIndex = 0x100;
    (pCir->mPolyInfo).mpBgW = (cBgW *)0x0;
    (pCir->mPolyInfo).mProcID = -1;
    *(uint *)((int)&this->mpAcchCir->mFlags + iVar1) =
         *(uint *)((int)&this->mpAcchCir->mFlags + iVar1) & 0xfffffffb;
    iVar1 = iVar1 + 0x40;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dBgS_Acch::Set(cXyz *,
                             cXyz *,
                             fopAc_ac_c *,
                             int,
                             dBgS_AcchCir *,
                             cXyz *,
                             csXyz *,
                             csXyz *) */

void __thiscall
dBgS_Acch::Set(dBgS_Acch *this,cXyz *pPos,cXyz *pOldPos,fopAc_ac_c *pActor,int cirCount,
              dBgS_AcchCir *pCir,cXyz *param_6,csXyz *param_7,csXyz *param_8)

{
  uint uVar1;
  ulong uVar2;
  
  this->mpPos = pPos;
  this->mpOldPos = pOldPos;
  if (this->mpPos == (cXyz *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_bg_s_acch.cpp",0xdd,"pm_pos != 0");
    m_Do_printf::OSPanic("d_bg_s_acch.cpp",0xdd,"Halt");
  }
  if (this->mpOldPos == (cXyz *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_bg_s_acch.cpp",0xde,"pm_old_pos != 0");
    m_Do_printf::OSPanic("d_bg_s_acch.cpp",0xde,"Halt");
  }
  this->mpActor = pActor;
  if (pActor == (fopAc_ac_c *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (pActor->parent).parent.mBsPcId;
  }
  (this->mChk).mProcID = uVar1;
  this->field_0x34 = param_6;
  this->mAcchCirCount = cirCount;
  this->mpAcchCir = pCir;
  this->field_0x38 = param_7;
  this->field_0x3c = param_8;
  return;
}


/* __thiscall dBgS_Acch::GroundCheckInit(dBgS &) */

void __thiscall dBgS_Acch::GroundCheckInit(dBgS_Acch *this,dBgS *param_1)

{
  this->field_0x94 = d_bg_s_acch::_1_0E9;
  if ((this->mFlags & 2) != 0) {
    return;
  }
  (this->mGndChk).parent.parent.mpPolyPassChk = (this->mChk).mpPolyPassChk;
  (this->mGndChk).parent.parent.mpGrpPassChk = (this->mChk).mpGrpPassChk;
  (this->mGndChk).parent.parent.mProcID = (this->mChk).mProcID;
  (this->mGndChk).parent.parent.mbExcludeSameProcID = (this->mChk).mbExcludeSameProcID;
  this->field_0xb0 = (byte)(this->mFlags >> 5) & 1;
  this->mFlags = this->mFlags & 0xffffffdf;
  this->mFlags = this->mFlags & 0xffffff7f;
  this->mFlags = this->mFlags & 0xfffffeff;
  return;
}


/* __thiscall dBgS_Acch::GroundCheck(dBgS &) */

void __thiscall dBgS_Acch::GroundCheck(dBgS_Acch *this,dBgS *pBg)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  cXyz *pcVar7;
  cM3dGPla *pcVar8;
  double dVar9;
  
  if ((this->mFlags & 2) == 0) {
    pcVar7 = this->mpPos;
    fVar1 = pcVar7->x;
    fVar2 = pcVar7->y;
    fVar3 = pcVar7->z;
    fVar4 = this->mGroundUpYDiff;
    fVar5 = this->field_0x98;
    fVar6 = this->mGroundUpY;
    this->mGroundUpYDiff = d_bg_s_acch::0_0;
    (this->mGndChk).parent.mPos.x = fVar1;
    (this->mGndChk).parent.mPos.y = fVar2 + fVar4 + (fVar5 - fVar6);
    (this->mGndChk).parent.mPos.z = fVar3;
    dVar9 = (double)cBgS::GroundCross(&pBg->parent,&(this->mGndChk).parent);
    this->field_0x94 = (float)dVar9;
    if (d_bg_s_acch::_1_0E9 != this->field_0x94) {
      this->field_0xb8 = this->field_0x94 + this->mGroundUpY;
      if (this->field_0xb4 < this->field_0xb8) {
        this->mpPos->y = this->field_0xb8;
        if (this->field_0x34 != (cXyz *)0x0) {
          this->field_0x34->y = d_bg_s_acch::0_0;
        }
        pcVar8 = cBgS::GetTriPla(&pBg->parent,
                                 (uint)(ushort)(this->mGndChk).parent.mPolyInfo.mBgIndex,
                                 (uint)(ushort)(this->mGndChk).parent.mPolyInfo.mTriIdx);
        (this->mPla).mNorm.x = (pcVar8->mNorm).x;
        (this->mPla).mNorm.y = (pcVar8->mNorm).y;
        (this->mPla).mNorm.z = (pcVar8->mNorm).z;
        (this->mPla).mDist = pcVar8->mDist;
        this->mFlags = this->mFlags | 0x40;
        this->mFlags = this->mFlags | 0x20;
        dBgS::RideCallBack(pBg,&(this->mGndChk).parent.mPolyInfo,this->mpActor);
        if (this->field_0xb0 == 0) {
          this->mFlags = this->mFlags | 0x80;
        }
      }
    }
    if ((this->field_0xb0 != 0) && ((this->mFlags & 0x20) == 0)) {
      this->mFlags = this->mFlags | 0x100;
    }
  }
  return;
}


/* __thiscall dBgS_Acch::GroundRoofProc(dBgS &) */

void __thiscall dBgS_Acch::GroundRoofProc(dBgS_Acch *this,dBgS *param_1)

{
  float fVar1;
  float fVar2;
  cXyz *pcVar3;
  double dVar4;
  
  if (d_bg_s_acch::_1_0E9 != this->field_0x94) {
    fVar1 = this->field_0xc4;
    if (this->field_0xb8 < fVar1) {
      if (fVar1 < this->mpPos->y) {
        this->mpPos->y = fVar1;
      }
    }
    if (((this->mFlags & 8) == 0) && (this->field_0xbc <= this->field_0x94)) {
      (this->mRoofChk).mChk.mpPolyPassChk = (this->mChk).mpPolyPassChk;
      (this->mRoofChk).mChk.mpGrpPassChk = (this->mChk).mpGrpPassChk;
      (this->mRoofChk).mChk.mProcID = (this->mChk).mProcID;
      (this->mRoofChk).mChk.mbExcludeSameProcID = (this->mChk).mbExcludeSameProcID;
      this->mFlags = this->mFlags & 0xfffffdff;
      pcVar3 = this->mpPos;
      fVar1 = pcVar3->y;
      fVar2 = pcVar3->z;
      (this->mRoofChk).mPos.x = pcVar3->x;
      (this->mRoofChk).mPos.y = fVar1;
      (this->mRoofChk).mPos.z = fVar2;
      dVar4 = (double)dBgS::RoofChk(param_1,&this->mRoofChk);
      this->field_0xbc = (float)dVar4;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f14 */
/* WARNING: Inlined function: FUN_80328f60 */
/* __thiscall dBgS_Acch::LineCheck(dBgS &) */

void __thiscall dBgS_Acch::LineCheck(dBgS_Acch *this,dBgS *param_2)

{
  float fVar1;
  float fVar2;
  cXyz *pcVar3;
  cXyz *pcVar4;
  char cVar6;
  cBgS_PolyInfo *pDstPoly;
  cM3dGPla *pcVar5;
  dBgS_AcchCir *pAttrCir;
  int iVar7;
  int iVar8;
  double dVar9;
  double dVar10;
  cXyz local_b4;
  cXyz local_a8;
  cBgS_LinChk linChk;
  
  iVar8 = 0;
  iVar7 = 0;
  while( true ) {
    if (this->mAcchCirCount <= iVar8) break;
    linChk.parent.mpPolyPassChk = (cBgS_PolyPassChk *)0x0;
    linChk.parent.mpGrpPassChk = (cBgS_GrpPassChk *)0x0;
    linChk.parent.mbExcludeSameProcID = true;
    linChk.mPolyInfo.mTriIdx = -1;
    linChk.mPolyInfo.mBgIndex = 0x100;
    linChk.mPolyInfo.mpBgW = (cBgW *)0x0;
    linChk.mPolyInfo.mProcID = -1;
    linChk.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
    linChk.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371fbc;
    linChk.mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
    ::cBgS_LinChk::ct(&linChk);
    pcVar3 = this->mpOldPos;
    local_a8.x = pcVar3->x;
    local_a8.z = pcVar3->z;
    pcVar4 = this->mpPos;
    local_b4.x = pcVar4->x;
    local_b4.z = pcVar4->z;
    local_b4.y = *(float *)((int)&this->mpAcchCir->mWallHalfHeight + iVar7);
    local_a8.y = pcVar3->y + local_b4.y;
    local_b4.y = pcVar4->y + local_b4.y;
    ::cBgS_LinChk::Set2(&linChk,&local_a8,&local_b4,(this->mChk).mProcID);
    linChk.parent.mpPolyPassChk = (this->mChk).mpPolyPassChk;
    linChk.parent.mpGrpPassChk = (this->mChk).mpGrpPassChk;
    linChk.parent.mProcID = (this->mChk).mProcID;
    linChk.parent.mbExcludeSameProcID = (this->mChk).mbExcludeSameProcID;
    cVar6 = cBgS::LineCross(&param_2->parent,&linChk);
    if (cVar6 != '\0') {
      pcVar3 = this->mpPos;
      pcVar3->x = linChk.mLin.mP1.x;
      pcVar3->y = linChk.mLin.mP1.y;
      pcVar3->z = linChk.mLin.mP1.z;
      this->mFlags = this->mFlags | 0x10000;
      pDstPoly = this->mpOutPolyInfo;
      if (pDstPoly != (cBgS_PolyInfo *)0x0) {
        pDstPoly->mTriIdx = linChk.mPolyInfo.mTriIdx;
        pDstPoly->mBgIndex = linChk.mPolyInfo.mBgIndex;
        pDstPoly->mpBgW = linChk.mPolyInfo.mpBgW;
        pDstPoly->mProcID = linChk.mPolyInfo.mProcID;
      }
      pcVar5 = cBgS::GetTriPla(&param_2->parent,(uint)(ushort)linChk.mPolyInfo.mBgIndex,
                               (uint)(ushort)linChk.mPolyInfo.mTriIdx);
      if (d_bg_s_acch::_4583 <= (pcVar5->mNorm).y) {
        this->mpPos->y = this->mpPos->y - d_bg_s_acch::_4586;
        GroundCheck(this,param_2);
      }
      else {
        mtx::PSVECAdd(this->mpPos,(cXyz *)pcVar5,this->mpPos);
        fVar1 = (pcVar5->mNorm).x;
        fVar2 = (pcVar5->mNorm).z;
        dVar10 = (double)(fVar1 * fVar1 + fVar2 * fVar2);
        if ((double)d_bg_s_acch::0_0 < dVar10) {
          dVar9 = 1.0 / SQRT(dVar10);
          dVar9 = d_bg_s_acch::_4584 * dVar9 * (d_bg_s_acch::_4585 - dVar10 * dVar9 * dVar9);
          dVar9 = d_bg_s_acch::_4584 * dVar9 * (d_bg_s_acch::_4585 - dVar10 * dVar9 * dVar9);
          dVar10 = (double)(float)(dVar10 * d_bg_s_acch::_4584 * dVar9 *
                                            (d_bg_s_acch::_4585 - dVar10 * dVar9 * dVar9));
        }
        if (SComponent::G_CM3D_F_ABS_MIN <= (float)ABS(dVar10)) {
          fVar1 = this->mpPos->y;
          pAttrCir = (dBgS_AcchCir *)((int)&(this->mpAcchCir->mPolyInfo).mTriIdx + iVar7);
          pAttrCir->mFlags = pAttrCir->mFlags | 4;
          pAttrCir->field_0x38 = fVar1;
        }
        this->mpPos->y = this->mpPos->y - *(float *)((int)&this->mpAcchCir->mWallHalfHeight + iVar7)
        ;
      }
    }
    linChk.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
    linChk.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371fbc;
    if ((undefined *)register0x00000004 != (undefined *)0x78) {
      linChk.mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
    }
    if ((undefined *)register0x00000004 != (undefined *)0x88) {
      linChk.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    }
    cBgS_Chk::_cBgS_Chk(&linChk.parent);
    iVar8 = iVar8 + 1;
    iVar7 = iVar7 + 0x40;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x800a3f28) */
/* WARNING: Removing unreachable block (ram,0x800a3f20) */
/* WARNING: Removing unreachable block (ram,0x800a3f30) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dBgS_Acch::CrrPos(dBgS &) */

void __thiscall dBgS_Acch::CrrPos(dBgS_Acch *this,dBgS *param_1)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  ulong uVar4;
  cXyz *pcVar5;
  cBgW *this_00;
  char cVar7;
  uint uVar6;
  int extraout_r4;
  undefined4 uVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  undefined8 in_f29;
  double dVar12;
  undefined8 in_f30;
  undefined8 in_f31;
  longlong lVar13;
  float fVar14;
  float local_80;
  float top;
  cXyz local_78;
  cXyz local_6c;
  cXyz ground;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if ((this->mFlags & 1) == 0) {
    if (this->mpPos == (cXyz *)0x0) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar4,"d_bg_s_acch.cpp",0x1ee,"pm_pos != 0");
      m_Do_printf::OSPanic("d_bg_s_acch.cpp",0x1ee,"Halt");
    }
    if (this->mpOldPos == (cXyz *)0x0) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar4,"d_bg_s_acch.cpp",0x1ef,"pm_old_pos != 0");
      m_Do_printf::OSPanic("d_bg_s_acch.cpp",0x1ef,"Halt");
    }
    fVar14 = this->mpPos->x;
    uVar6 = (uint)fVar14 & 0x7f800000;
    if (uVar6 == 0x7f800000) {
      if (((uint)fVar14 & 0x7fffff) == 0) {
        iVar3 = 2;
      }
      else {
        iVar3 = 1;
      }
    }
    else {
      if ((uVar6 < 0x7f800000) && (uVar6 == 0)) {
        if (((uint)fVar14 & 0x7fffff) == 0) {
          iVar3 = 3;
        }
        else {
          iVar3 = 5;
        }
      }
      else {
        iVar3 = 4;
      }
    }
    if (iVar3 == 1) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar4,"d_bg_s_acch.cpp",0x217,
                 "!(((sizeof(pm_pos->x) == sizeof(float)) ? __fpclassifyf((float)(pm_pos->x)) : __fpclassifyd((double)(pm_pos->x)) ) == 1)"
                );
      m_Do_printf::OSPanic("d_bg_s_acch.cpp",0x217,"Halt");
    }
    fVar14 = this->mpPos->y;
    uVar6 = (uint)fVar14 & 0x7f800000;
    if (uVar6 == 0x7f800000) {
      if (((uint)fVar14 & 0x7fffff) == 0) {
        iVar3 = 2;
      }
      else {
        iVar3 = 1;
      }
    }
    else {
      if ((uVar6 < 0x7f800000) && (uVar6 == 0)) {
        if (((uint)fVar14 & 0x7fffff) == 0) {
          iVar3 = 3;
        }
        else {
          iVar3 = 5;
        }
      }
      else {
        iVar3 = 4;
      }
    }
    if (iVar3 == 1) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar4,"d_bg_s_acch.cpp",0x218,
                 "!(((sizeof(pm_pos->y) == sizeof(float)) ? __fpclassifyf((float)(pm_pos->y)) : __fpclassifyd((double)(pm_pos->y)) ) == 1)"
                );
      m_Do_printf::OSPanic("d_bg_s_acch.cpp",0x218,"Halt");
    }
    fVar14 = this->mpPos->z;
    uVar6 = (uint)fVar14 & 0x7f800000;
    if (uVar6 == 0x7f800000) {
      if (((uint)fVar14 & 0x7fffff) == 0) {
        iVar3 = 2;
      }
      else {
        iVar3 = 1;
      }
    }
    else {
      if ((uVar6 < 0x7f800000) && (uVar6 == 0)) {
        if (((uint)fVar14 & 0x7fffff) == 0) {
          iVar3 = 3;
        }
        else {
          iVar3 = 5;
        }
      }
      else {
        iVar3 = 4;
      }
    }
    if (iVar3 == 1) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar4,"d_bg_s_acch.cpp",0x219,
                 "!(((sizeof(pm_pos->z) == sizeof(float)) ? __fpclassifyf((float)(pm_pos->z)) : __fpclassifyd((double)(pm_pos->z)) ) == 1)"
                );
      m_Do_printf::OSPanic("d_bg_s_acch.cpp",0x219,"Halt");
    }
    bVar2 = false;
    pcVar5 = this->mpPos;
    if ((((d_bg_s_acch::_4828 < pcVar5->x) && (pcVar5->x < d_bg_s_acch::_4829)) &&
        (d_bg_s_acch::_4828 < pcVar5->y)) &&
       (((pcVar5->y < d_bg_s_acch::_4829 && (d_bg_s_acch::_4828 < pcVar5->z)) &&
        (pcVar5->z < d_bg_s_acch::_4829)))) {
      bVar2 = true;
    }
    if (!bVar2) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar4,"d_bg_s_acch.cpp",0x21d,
                 "-1.0e32f < pm_pos->x && pm_pos->x < 1.0e32f && -1.0e32f < pm_pos->y && pm_pos->y < 1.0e32f && -1.0e32f < pm_pos->z && pm_pos->z < 1.0e32f"
                );
      m_Do_printf::OSPanic("d_bg_s_acch.cpp",0x21d,"Halt");
    }
    dBgS::MoveBgCrrPos(param_1,&(this->mGndChk).parent.mPolyInfo,
                       (bool)((byte)(this->mFlags >> 5) & 1),this->mpPos,this->field_0x38,
                       this->field_0x3c);
    GroundCheckInit(this,param_1);
    Init(this);
    dVar9 = (double)GetWallAllLowH_R(this);
    local_78.z = this->mpOldPos->z;
    local_78.x = this->mpOldPos->x;
    local_78.y = d_bg_s_acch::0_0;
    local_6c.z = this->mpPos->z;
    local_6c.x = this->mpPos->x;
    local_6c.y = d_bg_s_acch::0_0;
    fVar14 = mtx::PSVECSquareDistance(&local_78,&local_6c);
    dVar10 = (double)fVar14;
    dVar12 = (double)(this->mpOldPos->y - this->mpPos->y);
    dVar11 = (double)GetWallAllLowH(this);
    this->field_0xb4 = this->mpPos->y;
    fVar14 = this->mpOldPos->y;
    fVar1 = this->mpPos->y;
    bVar2 = false;
    this->mFlags = this->mFlags & 0xfffeffff;
    if ((((this->mFlags & 0x4000) == 0) && (SComponent::G_CM3D_F_ABS_MIN <= (float)ABS(dVar9))) &&
       (((double)(float)(dVar9 * dVar9) < dVar10 ||
        (((this->field_0x98 + fVar1 < (float)(dVar11 + (double)fVar14) ||
          ((double)this->field_0x98 < dVar12)) || ((this->mFlags & 0x2000) != 0)))))) {
      bVar2 = true;
      LineCheck(this,param_1);
    }
    if ((this->mFlags & 4) == 0) {
      dBgS::WallCorrect(param_1,this);
    }
    if (((this->mFlags & 0x10) != 0) && (bVar2)) {
      LineCheck(this,param_1);
    }
    this->field_0xc4 = d_bg_s_acch::_4830;
    if ((this->mFlags & 8) == 0) {
      (this->mRoofChk).mChk.mpPolyPassChk = (this->mChk).mpPolyPassChk;
      (this->mRoofChk).mChk.mpGrpPassChk = (this->mChk).mpGrpPassChk;
      (this->mRoofChk).mChk.mProcID = (this->mChk).mProcID;
      (this->mRoofChk).mChk.mbExcludeSameProcID = (this->mChk).mbExcludeSameProcID;
      this->mFlags = this->mFlags & 0xfffffdff;
      pcVar5 = this->mpPos;
      fVar14 = pcVar5->y;
      fVar1 = pcVar5->z;
      (this->mRoofChk).mPos.x = pcVar5->x;
      (this->mRoofChk).mPos.y = fVar14;
      (this->mRoofChk).mPos.z = fVar1;
      dVar9 = (double)dBgS::RoofChk(param_1,&this->mRoofChk);
      this->field_0xbc = (float)dVar9;
      fVar14 = this->field_0xbc;
      if ((d_bg_s_acch::_4830 != fVar14) && (fVar14 < this->mpPos->y + this->field_0xc0)) {
        this->field_0xc4 = fVar14 - this->field_0xc0;
        this->mFlags = this->mFlags | 0x200;
      }
    }
    if ((this->mFlags & 2) == 0) {
      this->mFlags = this->mFlags & 0xffffffbf;
      GroundCheck(this,param_1);
      GroundRoofProc(this,param_1);
    }
    else {
      if (this->field_0xc4 < this->mpPos->y) {
        this->mpPos->y = this->field_0xc4;
      }
    }
    if ((this->mFlags & 0x400) == 0) {
      this->mFlags = this->mFlags & 0xfffff7ff;
      this->mFlags = this->mFlags & 0xffffefff;
      (this->mWtrChk).parent.mHeight = d_bg_s_acch::_1_0E9;
      lVar13 = dBgS::GetRoomId(param_1,&(this->mGndChk).parent.mPolyInfo);
      iVar3 = (int)lVar13;
      if (((d_bg_s_acch::_1_0E9 != this->field_0x94) && (-1 < lVar13)) && (lVar13 < 0x4000000000)) {
        bVar2 = false;
        if ((-1 < lVar13) && (lVar13 < 0x4000000000)) {
          bVar2 = true;
        }
        if (!bVar2) {
          uVar4 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar4,"d_bg_s_acch.cpp",0x2b5,"0 <= room_no && room_no < 64");
          m_Do_printf::OSPanic("d_bg_s_acch.cpp",0x2b5,"Halt");
          iVar3 = extraout_r4;
        }
        this_00 = (cBgW *)dStage_roomControl_c::getBgW
                                    ((dStage_roomControl_c *)((ulonglong)lVar13 >> 0x20),iVar3);
        if (this_00 != (cBgW *)0x0) {
          cBgW::GetTopUnder(this_00,&top,&local_80);
          ground.x = this->mpPos->x;
          ground.z = this->mpPos->z;
          ground.y = local_80;
          (this->mWtrChk).parent.mStartPos.x = ground.x;
          (this->mWtrChk).parent.mStartPos.y = local_80;
          (this->mWtrChk).parent.mStartPos.z = ground.z;
          (this->mWtrChk).parent.mEndPosY = top;
          (this->mWtrChk).parent.mDChk.mPolyPassChk.parent.mbObjThrough =
               (this->mDChk).mPolyPassChk.parent.mbObjThrough;
          (this->mWtrChk).parent.mDChk.mPolyPassChk.parent.mbCamThrough =
               (this->mDChk).mPolyPassChk.parent.mbCamThrough;
          (this->mWtrChk).parent.mDChk.mPolyPassChk.parent.mbLinkThrough =
               (this->mDChk).mPolyPassChk.parent.mbLinkThrough;
          (this->mWtrChk).parent.mDChk.mPolyPassChk.parent.mbArrowsAndLightThrough =
               (this->mDChk).mPolyPassChk.parent.mbArrowsAndLightThrough;
          (this->mWtrChk).parent.mDChk.mPolyPassChk.parent.mbBombThrough =
               (this->mDChk).mPolyPassChk.parent.mbBombThrough;
          (this->mWtrChk).parent.mDChk.mPolyPassChk.parent.mbBoomerangThrough =
               (this->mDChk).mPolyPassChk.parent.mbBoomerangThrough;
          (this->mWtrChk).parent.mDChk.mPolyPassChk.parent.mbHookshotThrough =
               (this->mDChk).mPolyPassChk.parent.mbHookshotThrough;
          cVar7 = dBgS::SplGrpChk(param_1,(dBgS_SplGrpChk *)&this->mWtrChk);
          if (cVar7 != '\0') {
            this->mFlags = this->mFlags | 0x800;
            if (this->mpPos->y < (this->mWtrChk).parent.mHeight) {
              this->mFlags = this->mFlags | 0x1000;
            }
            if ((this->mWtrChk).parent.mHeight < ground.y) {
              uVar4 = JUTAssertion::getSDevice();
              JUTAssertion::showAssert
                        (uVar4,"d_bg_s_acch.cpp",0x2ce,"m_wtr.GetHeight() >= ground.y");
              m_Do_printf::OSPanic("d_bg_s_acch.cpp",0x2ce,"Halt");
            }
            if (top < (this->mWtrChk).parent.mHeight) {
              uVar4 = JUTAssertion::getSDevice();
              JUTAssertion::showAssert(uVar4,"d_bg_s_acch.cpp",0x2cf,"m_wtr.GetHeight() <= top");
              m_Do_printf::OSPanic("d_bg_s_acch.cpp",0x2cf,"Halt");
            }
          }
        }
      }
    }
    if ((this->mFlags & 0x20000) != 0) {
      this->mFlags = this->mFlags & 0xfff7ffff;
      this->field_0xd0 = d_bg_s_acch::_1_0E9;
      uVar6 = d_a_sea::daSea_ChkArea(this->mpPos->x,this->mpPos->z);
      if ((uVar6 & 0xff) != 0) {
        dVar9 = (double)d_a_sea::daSea_calcWave((double)this->mpPos->x,(double)this->mpPos->z);
        this->field_0xd0 = (float)dVar9;
      }
      if (((this->mFlags & 0x40000) != 0) &&
         (fVar14 = (this->mWtrChk).parent.mHeight, this->field_0xd0 < fVar14)) {
        this->field_0xd0 = fVar14;
      }
      if (this->mpPos->y < this->field_0xd0) {
        this->mFlags = this->mFlags | 0x80000;
      }
    }
    fVar14 = this->mpPos->x;
    uVar6 = (uint)fVar14 & 0x7f800000;
    if (uVar6 == 0x7f800000) {
      if (((uint)fVar14 & 0x7fffff) == 0) {
        iVar3 = 2;
      }
      else {
        iVar3 = 1;
      }
    }
    else {
      if ((uVar6 < 0x7f800000) && (uVar6 == 0)) {
        if (((uint)fVar14 & 0x7fffff) == 0) {
          iVar3 = 3;
        }
        else {
          iVar3 = 5;
        }
      }
      else {
        iVar3 = 4;
      }
    }
    if (iVar3 == 1) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar4,"d_bg_s_acch.cpp",0x30c,
                 "!(((sizeof(pm_pos->x) == sizeof(float)) ? __fpclassifyf((float)(pm_pos->x)) : __fpclassifyd((double)(pm_pos->x)) ) == 1)"
                );
      m_Do_printf::OSPanic("d_bg_s_acch.cpp",0x30c,"Halt");
    }
    fVar14 = this->mpPos->y;
    uVar6 = (uint)fVar14 & 0x7f800000;
    if (uVar6 == 0x7f800000) {
      if (((uint)fVar14 & 0x7fffff) == 0) {
        iVar3 = 2;
      }
      else {
        iVar3 = 1;
      }
    }
    else {
      if ((uVar6 < 0x7f800000) && (uVar6 == 0)) {
        if (((uint)fVar14 & 0x7fffff) == 0) {
          iVar3 = 3;
        }
        else {
          iVar3 = 5;
        }
      }
      else {
        iVar3 = 4;
      }
    }
    if (iVar3 == 1) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar4,"d_bg_s_acch.cpp",0x30d,
                 "!(((sizeof(pm_pos->y) == sizeof(float)) ? __fpclassifyf((float)(pm_pos->y)) : __fpclassifyd((double)(pm_pos->y)) ) == 1)"
                );
      m_Do_printf::OSPanic("d_bg_s_acch.cpp",0x30d,"Halt");
    }
    fVar14 = this->mpPos->z;
    uVar6 = (uint)fVar14 & 0x7f800000;
    if (uVar6 == 0x7f800000) {
      if (((uint)fVar14 & 0x7fffff) == 0) {
        iVar3 = 2;
      }
      else {
        iVar3 = 1;
      }
    }
    else {
      if ((uVar6 < 0x7f800000) && (uVar6 == 0)) {
        if (((uint)fVar14 & 0x7fffff) == 0) {
          iVar3 = 3;
        }
        else {
          iVar3 = 5;
        }
      }
      else {
        iVar3 = 4;
      }
    }
    if (iVar3 == 1) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar4,"d_bg_s_acch.cpp",0x30e,
                 "!(((sizeof(pm_pos->z) == sizeof(float)) ? __fpclassifyf((float)(pm_pos->z)) : __fpclassifyd((double)(pm_pos->z)) ) == 1)"
                );
      m_Do_printf::OSPanic("d_bg_s_acch.cpp",0x30e,"Halt");
    }
    bVar2 = false;
    pcVar5 = this->mpPos;
    if (((((d_bg_s_acch::_4828 < pcVar5->x) && (pcVar5->x < d_bg_s_acch::_4829)) &&
         (d_bg_s_acch::_4828 < pcVar5->y)) &&
        ((pcVar5->y < d_bg_s_acch::_4829 && (d_bg_s_acch::_4828 < pcVar5->z)))) &&
       (pcVar5->z < d_bg_s_acch::_4829)) {
      bVar2 = true;
    }
    if (!bVar2) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar4,"d_bg_s_acch.cpp",0x312,
                 "-1.0e32f < pm_pos->x && pm_pos->x < 1.0e32f && -1.0e32f < pm_pos->y && pm_pos->y < 1.0e32f && -1.0e32f < pm_pos->z && pm_pos->z < 1.0e32f"
                );
      m_Do_printf::OSPanic("d_bg_s_acch.cpp",0x312,"Halt");
    }
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  __psq_l0(auStack40,uVar8);
  __psq_l1(auStack40,uVar8);
  return;
}


/* __thiscall dBgS_Acch::GetWallAllR(void) */

void __thiscall dBgS_Acch::GetWallAllR(dBgS_Acch *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = this->mAcchCirCount;
  fVar2 = d_bg_s_acch::0_0;
  if (iVar3 < 1) {
    return;
  }
  do {
    fVar1 = *(float *)((int)&this->mpAcchCir->mWallRadius + iVar4);
    if (fVar2 < fVar1) {
      fVar2 = fVar1;
    }
    iVar4 = iVar4 + 0x40;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


/* __thiscall dBgS_Acch::SetWallCir(void) */

void __thiscall dBgS_Acch::SetWallCir(dBgS_Acch *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  dBgS_AcchCir *pAcch;
  cXyz *pcVar6;
  int iVar7;
  
  iVar5 = 0;
  for (iVar7 = 0; iVar7 < this->mAcchCirCount; iVar7 = iVar7 + 1) {
    pcVar6 = this->mpPos;
    pAcch = (dBgS_AcchCir *)((int)&(this->mpAcchCir->mPolyInfo).mTriIdx + iVar5);
    fVar1 = pAcch->mWallRadius;
    fVar2 = pcVar6->y;
    fVar3 = pAcch->mWallHalfHeight;
    fVar4 = pcVar6->z;
    (pAcch->mCir).parent.x = pcVar6->x;
    (pAcch->mCir).parent.z = fVar4;
    (pAcch->mCir).parent.mRadius = fVar1;
    (pAcch->mCir).y = fVar2 + fVar3;
    iVar5 = iVar5 + 0x40;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x800a40f0) */
/* WARNING: Removing unreachable block (ram,0x800a40e8) */
/* WARNING: Removing unreachable block (ram,0x800a40f8) */
/* __thiscall dBgS_Acch::CalcWallBmdCyl(void) */

void __thiscall dBgS_Acch::CalcWallBmdCyl(dBgS_Acch *this)

{
  int iVar1;
  int iVar2;
  cXyz *pcVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  cXyz local_48;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if (this->mAcchCirCount < 1) {
    ::cM3dGCyl::SetC(&this->mCyl,this->mpPos);
    ::cM3dGCyl::SetR(&this->mCyl,d_bg_s_acch::0_0);
    ::cM3dGCyl::SetH(&this->mCyl,d_bg_s_acch::0_0);
  }
  else {
    dVar7 = (double)GetWallAllR(this);
    dVar5 = (double)this->mpAcchCir->mWallHalfHeight;
    iVar1 = this->mAcchCirCount;
    dVar8 = dVar5;
    if ((0 < iVar1) && (iVar2 = 0, 0 < iVar1)) {
      do {
        dVar6 = (double)*(float *)((int)&this->mpAcchCir->mWallHalfHeight + iVar2);
        if (dVar6 < dVar8) {
          dVar8 = dVar6;
        }
        if (dVar5 < dVar6) {
          dVar5 = dVar6;
        }
        iVar2 = iVar2 + 0x40;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    pcVar3 = this->mpPos;
    local_48.x = pcVar3->x;
    local_48.z = pcVar3->z;
    local_48.y = (float)((double)pcVar3->y + dVar8);
    ::cM3dGCyl::SetC(&this->mCyl,&local_48);
    ::cM3dGCyl::SetR(&this->mCyl,(float)dVar7);
    ::cM3dGCyl::SetH(&this->mCyl,(float)(dVar5 - dVar8));
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  return;
}


/* __thiscall dBgS_Acch::SetGroundUpY(float) */

void __thiscall dBgS_Acch::SetGroundUpY(dBgS_Acch *this,float param_1)

{
  this->mGroundUpYDiff = param_1 - this->mGroundUpY;
  this->mGroundUpY = param_1;
  return;
}


/* __thiscall dBgS_Acch::GetWallAllLowH(void) */

double __thiscall dBgS_Acch::GetWallAllLowH(dBgS_Acch *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  double dVar5;
  
  iVar3 = this->mAcchCirCount;
  if (iVar3 < 1) {
    return (double)d_bg_s_acch::0_0;
  }
  dVar5 = (double)this->mpAcchCir->mWallHalfHeight;
  iVar2 = 0x40;
  iVar1 = iVar3 + -1;
  if (iVar3 < 2) {
    return dVar5;
  }
  do {
    dVar4 = (double)*(float *)((int)&this->mpAcchCir->mWallHalfHeight + iVar2);
    if (dVar4 < dVar5) {
      dVar5 = dVar4;
    }
    iVar2 = iVar2 + 0x40;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return dVar5;
}


/* __thiscall dBgS_Acch::GetWallAllLowH_R(void) */

double __thiscall dBgS_Acch::GetWallAllLowH_R(dBgS_Acch *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  dBgS_AcchCir *pdVar6;
  int iVar7;
  int iVar8;
  
  iVar5 = this->mAcchCirCount;
  if (iVar5 < 1) {
    return (double)d_bg_s_acch::0_0;
  }
  iVar7 = 0;
  pdVar6 = this->mpAcchCir;
  fVar1 = pdVar6->mWallHalfHeight;
  iVar8 = 1;
  iVar4 = 0x40;
  iVar3 = iVar5 + -1;
  if (1 < iVar5) {
    do {
      fVar2 = *(float *)((int)&pdVar6->mWallHalfHeight + iVar4);
      if (fVar2 < fVar1) {
        iVar7 = iVar8;
        fVar1 = fVar2;
      }
      iVar8 = iVar8 + 1;
      iVar4 = iVar4 + 0x40;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return (double)pdVar6[iVar7].mWallRadius;
}


/* __thiscall dBgS_Acch::GetOnePolyInfo(cBgS_PolyInfo *) */

undefined4 __thiscall dBgS_Acch::GetOnePolyInfo(dBgS_Acch *this,cBgS_PolyInfo *pDst)

{
  uint uVar1;
  int iVar2;
  dBgS_AcchCir *pAcchCir;
  int iVar3;
  
  uVar1 = this->mFlags;
  if ((uVar1 & 0x20) != 0) {
    pDst->mTriIdx = (this->mGndChk).parent.mPolyInfo.mTriIdx;
    pDst->mBgIndex = (this->mGndChk).parent.mPolyInfo.mBgIndex;
    pDst->mpBgW = (this->mGndChk).parent.mPolyInfo.mpBgW;
    pDst->mProcID = (this->mGndChk).parent.mPolyInfo.mProcID;
    return 0;
  }
  if ((uVar1 & 0x10) != 0) {
    iVar3 = 0;
    iVar2 = 0;
    while( true ) {
      if (this->mAcchCirCount <= iVar3) break;
      pAcchCir = (dBgS_AcchCir *)((int)&(this->mpAcchCir->mPolyInfo).mTriIdx + iVar2);
      if ((pAcchCir->mFlags & 2) != 0) {
        pDst->mTriIdx = (pAcchCir->mPolyInfo).mTriIdx;
        pDst->mBgIndex = (pAcchCir->mPolyInfo).mBgIndex;
        pDst->mpBgW = (pAcchCir->mPolyInfo).mpBgW;
        pDst->mProcID = (pAcchCir->mPolyInfo).mProcID;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x40;
    }
    return 0;
  }
  if ((uVar1 & 0x200) != 0) {
    pDst->mTriIdx = (this->mRoofChk).mPolyInfo.mTriIdx;
    pDst->mBgIndex = (this->mRoofChk).mPolyInfo.mBgIndex;
    pDst->mpBgW = (this->mRoofChk).mPolyInfo.mpBgW;
    pDst->mProcID = (this->mRoofChk).mPolyInfo.mProcID;
    return 0;
  }
  return 1;
}


/* __thiscall dBgS_Acch::GetWallAddY(Vec &,
                                     int) */

double __thiscall dBgS_Acch::GetWallAddY(dBgS_Acch *this,cXyz *param_1,int param_2)

{
  float fVar1;
  double dVar2;
  
  if (((this->mFlags & 0x40) != 0) && (fVar1 = (this->mPla).mNorm.y, d_bg_s_acch::_4583 <= fVar1)) {
    if (ABS(fVar1) < SComponent::G_CM3D_F_ABS_MIN) {
      return (double)d_bg_s_acch::0_0;
    }
    dVar2 = (double)((-(this->mPla).mNorm.x * param_1->x - (this->mPla).mNorm.z * param_1->z) /
                    (this->mPla).mNorm.y);
    if ((double)d_bg_s_acch::0_0 < dVar2) {
      dVar2 = (double)d_bg_s_acch::0_0;
    }
    return -dVar2;
  }
  return (double)d_bg_s_acch::0_0;
}


/* __thiscall cM3dGCir::~cM3dGCir(void) */

void __thiscall cM3dGCir::_cM3dGCir(cM3dGCir *this)

{
  short in_r4;
  
  if (this != (cM3dGCir *)0x0) {
    (this->parent).vtbl = (undefined *)&__vt;
    if (this != (cM3dGCir *)0x0) {
      (this->parent).vtbl = (undefined *)&::cM2dGCir::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cM2dGCir::~cM2dGCir(void) */

void __thiscall cM2dGCir::_cM2dGCir(cM2dGCir *this)

{
  short in_r4;
  
  if ((this != (cM2dGCir *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall cM3dGPla::~cM3dGPla(void) */

void __thiscall cM3dGPla::_cM3dGPla(cM3dGPla *this)

{
  short in_r4;
  
  if ((this != (cM3dGPla *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dStage_roomControl_c::getBgW(int) */

dBgW * __thiscall dStage_roomControl_c::getBgW(dStage_roomControl_c *this,int param_1)

{
  return mStatus[(int)this].mpBgW;
}


/* __thiscall dBgS_ObjAcch::~dBgS_ObjAcch(void) */

void __thiscall dBgS_ObjAcch::_dBgS_ObjAcch(dBgS_ObjAcch *this)

{
  short in_r4;
  
  if (this != (dBgS_ObjAcch *)0x0) {
    (this->parent).mChk.vtbl = &__vt.mChk_vtbl;
    (this->parent).mDChk.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)0x8037e9e4;
    (this->parent).mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)0x8037e9f0;
    dBgS_Acch::_dBgS_Acch(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dBgS_AcchCir::~dBgS_AcchCir(void) */

void __thiscall dBgS_AcchCir::_dBgS_AcchCir(dBgS_AcchCir *this)

{
  short in_r4;
  
  if (this != (dBgS_AcchCir *)0x0) {
    (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&__vt;
    if ((this != (dBgS_AcchCir *)0xffffffec) &&
       ((this->mCir).parent.vtbl = (undefined *)&::cM3dGCir::__vt,
       this != (dBgS_AcchCir *)0xffffffec)) {
      (this->mCir).parent.vtbl = (undefined *)&::cM2dGCir::__vt;
    }
    if (this != (dBgS_AcchCir *)0x0) {
      (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* [thunk]:__thiscall dBgS_Acch::~dBgS_Acch(void) */

void __thiscall dBgS_Acch::_dBgS_Acch(dBgS_Acch *this)

{
  _dBgS_Acch((dBgS_Acch *)&this[-1].mWtrChk.parent.mDChk.mGrpPassChk);
  return;
}


/* [thunk]:__thiscall dBgS_Acch::~dBgS_Acch(void) */

void __thiscall dBgS_Acch::_dBgS_Acch(dBgS_Acch *this)

{
  _dBgS_Acch((dBgS_Acch *)&this[-1].mWtrChk.parent.mStartPos.y);
  return;
}


/* [thunk]:__thiscall dBgS_ObjAcch::~dBgS_ObjAcch(void) */

void __thiscall dBgS_ObjAcch::_dBgS_ObjAcch(dBgS_ObjAcch *this)

{
  _dBgS_ObjAcch((dBgS_ObjAcch *)&this[-1].parent.mWtrChk.parent.mDChk.mGrpPassChk);
  return;
}


/* [thunk]:__thiscall dBgS_ObjAcch::~dBgS_ObjAcch(void) */

void __thiscall dBgS_ObjAcch::_dBgS_ObjAcch(dBgS_ObjAcch *this)

{
  _dBgS_ObjAcch((dBgS_ObjAcch *)&this[-1].parent.mWtrChk.parent.mStartPos.y);
  return;
}

