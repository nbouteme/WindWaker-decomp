#include <d_cam_param.h>
#include <d_cam_param.h>
#include <SComponent/c_angle.h>
#include <SComponent/c_math.h>
#include <m_Do_mtx.h>
#include <mtx/mtxvec.h>
#include <SComponent/c_xyz.h>
#include <JKernel/JKRHeap.h>
#include <d_kankyo_wether.h>
#include <dCamParam_c.h>
#include <dCamMath.h>
#include <dCamBGChk_c.h>
#include <dCamSetup_c.h>
#include <dCstick_c.h>


namespace dCamMath {

/* __thiscall rationalBezierRatio(float,
                                            float) */

double rationalBezierRatio(float param_1,float param_2)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  
  dVar2 = (double)param_2;
  dVar1 = (double)param_1;
  dVar3 = d_cam_param::_4104;
  if (dVar1 < (double)d_cam_param::_4103) {
    dVar1 = -dVar1;
    dVar3 = d_cam_param::_4105;
  }
  dVar5 = (d_cam_param::_4106 * dVar1 * dVar2 - d_cam_param::_4106 * dVar1) -
          d_cam_param::_4106 * dVar2;
  dVar4 = -dVar5 - d_cam_param::_4104;
  dVar6 = dVar5 * dVar5 - d_cam_param::_4107 * dVar4 * dVar1;
  dVar1 = d_cam_param::_4108;
  if (dVar6 > d_cam_param::_4108) {
    if (dVar6 <= d_cam_param::_4108) {
      if (d_cam_param::_4108 != dVar6) {
        if (dVar6 == d_cam_param::_4108) {
          dVar1 = (double)MSL_C.PPCEABI.bare.H::__float_huge;
        }
        else {
          dVar1 = (double)MSL_C.PPCEABI.bare.H::__float_nan;
        }
      }
    }
    else {
      dVar1 = 1.0 / SQRT(dVar6);
      dVar1 = d_cam_param::_4109 * dVar1 * (d_cam_param::_4110 - dVar6 * dVar1 * dVar1);
      dVar1 = d_cam_param::_4109 * dVar1 * (d_cam_param::_4110 - dVar6 * dVar1 * dVar1);
      dVar1 = d_cam_param::_4109 * dVar1 * (d_cam_param::_4110 - dVar6 * dVar1 * dVar1);
      dVar1 = dVar6 * d_cam_param::_4109 * dVar1 * (d_cam_param::_4110 - dVar6 * dVar1 * dVar1);
    }
  }
  dVar4 = d_cam_param::_4106 * dVar4;
  if ((dVar4 <= d_cam_param::_4111) && (d_cam_param::_4112 <= dVar4)) {
    return (double)d_cam_param::_4103;
  }
  dVar4 = (-dVar5 - dVar1) / dVar4;
  dVar1 = d_cam_param::_4104 - dVar4;
  dVar1 = dVar4 * dVar4 + dVar1 * dVar1 + dVar2 * d_cam_param::_4106 * dVar1 * dVar4;
  if (dVar1 <= d_cam_param::_4113) {
    return (double)d_cam_param::_4103;
  }
  return (double)(float)(dVar3 * ((dVar4 * dVar4) / dVar1));
}


/* __thiscall customRBRatio(float,
                                      float) */

float customRBRatio(float param_1,float param_2)

{
  double dVar1;
  
  if (param_1 <= d_cam_param::_4125) {
    dVar1 = (double)rationalBezierRatio(d_cam_param::_4128 * param_1,param_2);
  }
  else {
    if (d_cam_param::_4103 <= param_1) {
      dVar1 = (double)d_cam_param::_4127;
    }
    else {
      dVar1 = (double)d_cam_param::_4126;
    }
  }
  return (float)dVar1;
}

}

/* WARNING: Removing unreachable block (ram,0x800af588) */
/* __thiscall dCamMath::zoomFovy(float,
                                 float) */

double __thiscall dCamMath::zoomFovy(dCamMath *this,float param_1,float param_2)

{
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f31;
  double dVar3;
  cDegree acStack24 [16];
  undefined auStack8 [8];
  
  dVar3 = (double)param_2;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  cDegree::cDegree(acStack24,param_1);
  dVar2 = (double)cDegree::Cos(acStack24);
  dVar3 = (double)(float)(dVar3 * dVar2);
  dVar2 = (double)cDegree::Sin(acStack24);
  dVar2 = SComponent::cM_atan2f(dVar2,dVar3);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return (double)(float)((double)d_cam_param::_4143 * dVar2);
}


/* __thiscall dCamMath::xyzRotateX(cXyz &,
                                   cSAngle) */

void __thiscall dCamMath::xyzRotateX(dCamMath *this,cXyz *param_1,cSAngle param_2)

{
  undefined2 in_register_00000014;
  cXyz local_48;
  MTX34 MStack60;
  
  m_Do_mtx::mDoMtx_XrotS(&MStack60,(int)*(short *)CONCAT22(in_register_00000014,param_2));
  mtx::PSMTXMultVec(&MStack60,param_1,&local_48);
  *(float *)this = local_48.x;
  *(float *)(this + 4) = local_48.y;
  *(float *)(this + 8) = local_48.z;
  return;
}


namespace dCamMath {

/* __thiscall xyzRotateY(cXyz &,
                                   cSAngle) */

void xyzRotateY(cXyz *param_1,cSAngle param_2)

{
  undefined2 in_register_00000010;
  short *in_r5;
  cXyz local_48;
  MTX34 MStack60;
  
  m_Do_mtx::mDoMtx_YrotS(&MStack60,(int)*in_r5);
  mtx::PSMTXMultVec(&MStack60,(cXyz *)CONCAT22(in_register_00000010,param_2),&local_48);
  param_1->x = local_48.x;
  param_1->y = local_48.y;
  param_1->z = local_48.z;
  return;
}


/* __thiscall xyzHorizontalDistance(cXyz &,
                                              cXyz &) */

double xyzHorizontalDistance(cXyz *param_1,cXyz *param_2)

{
  double dVar1;
  double dVar2;
  
  dVar2 = (double)(param_1->x - param_2->x);
  dVar1 = (double)(param_1->z - param_2->z);
  dVar1 = dVar2 * dVar2 + dVar1 * dVar1;
  if (dVar1 <= d_cam_param::_4108) {
    dVar2 = d_cam_param::_4108;
    if (d_cam_param::_4108 != dVar1) {
      if (dVar1 == d_cam_param::_4108) {
        dVar2 = (double)MSL_C.PPCEABI.bare.H::__float_huge;
      }
      else {
        dVar2 = (double)MSL_C.PPCEABI.bare.H::__float_nan;
      }
    }
  }
  else {
    dVar2 = 1.0 / SQRT(dVar1);
    dVar2 = d_cam_param::_4109 * dVar2 * (d_cam_param::_4110 - dVar1 * dVar2 * dVar2);
    dVar2 = d_cam_param::_4109 * dVar2 * (d_cam_param::_4110 - dVar1 * dVar2 * dVar2);
    dVar2 = d_cam_param::_4109 * dVar2 * (d_cam_param::_4110 - dVar1 * dVar2 * dVar2);
    dVar2 = dVar1 * d_cam_param::_4109 * dVar2 * (d_cam_param::_4110 - dVar1 * dVar2 * dVar2);
  }
  return (double)(float)dVar2;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dCamMath::xyzProjPosOnYZ(cSAngle,
                                       cXyz &,
                                       cXyz &) */

void __thiscall dCamMath::xyzProjPosOnYZ(dCamMath *this,cSAngle param_1,cXyz *param_2,cXyz *param_3)

{
  undefined2 in_register_00000010;
  cSAngle acStack88 [2];
  cSAngle acStack84 [2];
  cXyz local_50;
  cXyz local_44;
  cXyz local_38;
  float local_2c;
  float local_28;
  float local_24;
  cXyz local_20;
  
  ::cXyz::operator__(&local_38,param_3,param_2);
  local_20.x = local_38.x;
  local_20.y = local_38.y;
  local_20.z = local_38.z;
  cSAngle::operator__(acStack84);
  xyzRotateY(&local_44,(cSAngle)((short)register0x00000004 + -0x20));
  local_28 = local_44.y;
  local_24 = local_44.z;
  local_2c = d_cam_param::_4103;
  cSAngle::cSAngle(acStack88,(cSAngle *)CONCAT22(in_register_00000010,param_1));
  xyzRotateY(&local_50,(cSAngle)((short)register0x00000004 + -0x2c));
  local_20.x = local_50.x;
  local_20.y = local_50.y;
  local_20.z = local_50.z;
  ::cXyz::operator__((cXyz *)this,param_2,&local_20);
  return;
}


/* __thiscall dCstick_c::dCstick_c(void) */

void __thiscall dCstick_c::dCstick_c(dCstick_c *this)

{
  this->vtbl = (undefined *)&__vt;
  this->field_0x0 = d_cam_param::_4348;
  this->field_0x4 = d_cam_param::_4349;
  this->field_0x8 = 6;
  return;
}


/* __thiscall dCstick_c::Shift(unsigned long) */

undefined4 __thiscall dCstick_c::Shift(dCstick_c *this,ulong param_1)

{
  return 0;
}


/* __thiscall dCamBGChk_c::dCamBGChk_c(void) */

void __thiscall dCamBGChk_c::dCamBGChk_c(dCamBGChk_c *this)

{
  float fVar1;
  float fVar2;
  
  this->field_0x0 = d_cam_param::_4358;
  this->field_0x4 = d_cam_param::_4127;
  this->field_0x8 = d_cam_param::_4359;
  this->field_0xc = d_cam_param::_4360;
  this->field_0x10 = d_cam_param::_4361;
  this->field_0x14 = d_cam_param::_4362;
  this->field_0x18 = d_cam_param::_4363;
  this->field_0x1c = d_cam_param::_4364;
  this->field_0x20 = d_cam_param::_4365;
  fVar1 = d_cam_param::_4366;
  this->field_0x24 = d_cam_param::_4366;
  this->field_0x28 = d_cam_param::_4367;
  this->field_0x2c = d_cam_param::_4348;
  this->field_0x30 = fVar1;
  this->field_0x34 = d_cam_param::_4368;
  fVar1 = d_cam_param::_4369;
  this->field_0x38 = d_cam_param::_4369;
  fVar2 = d_cam_param::_4370;
  this->field_0x3c = d_cam_param::_4370;
  this->field_0x40 = d_cam_param::_4371;
  this->field_0x44 = d_cam_param::_4372;
  this->field_0x48 = d_cam_param::_4373;
  this->field_0x4c = fVar2;
  this->field_0x50 = fVar1;
  this->field_0x54 = fVar1;
  this->field_0x5c = d_cam_param::_4374;
  this->field_0x58 = d_cam_param::_4375;
  return;
}


/* __thiscall dCamParam_c::dCamParam_c(long) */

void __thiscall dCamParam_c::dCamParam_c(dCamParam_c *this,long param_1)

{
  this->vtbl = (undefined *)&__vt;
  Change(this,param_1);
  return;
}


/* __thiscall dCamParam_c::~dCamParam_c(void) */

void __thiscall dCamParam_c::_dCamParam_c(dCamParam_c *this)

{
  short in_r4;
  
  if ((this != (dCamParam_c *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dCamParam_c::Change(long) */

undefined4 __thiscall dCamParam_c::Change(dCamParam_c *this,long param_1)

{
  this->mStyleIdx = param_1;
  if (param_1 < style_num) {
    this->mpStyle = styles + this->mStyleIdx;
    return 1;
  }
  this->mpStyle = styles;
  return 0;
}


/* __thiscall dCamParam_c::SearchStyle(unsigned long) */

int __thiscall dCamParam_c::SearchStyle(dCamParam_c *this,ulong magic)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar1 = 0;
  iVar3 = style_num;
  if (style_num < 1) {
    return -1;
  }
  do {
    if (magic == *(ulong *)(styles[0].mMagic + iVar1)) {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0x84;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return -1;
}


/* WARNING: Removing unreachable block (ram,0x800afa84) */
/* WARNING: Removing unreachable block (ram,0x800afa7c) */
/* WARNING: Removing unreachable block (ram,0x800afa8c) */
/* __thiscall dCamParam_c::ratiof(float,
                                  float,
                                  float,
                                  float) */

double __thiscall dCamParam_c::ratiof(dCamParam_c *this,float t,float upper,float lower,float base)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  float fVar5;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar4 = (double)lower;
  dVar2 = (double)base;
  dVar3 = (double)upper;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if (d_cam_param::_4103 != t) {
    if (d_cam_param::_4103 <= t) {
      fVar5 = dCamMath::customRBRatio(t,d_cam_param::_4369);
      dVar2 = (double)(float)(dVar2 + (double)((float)(dVar3 - dVar2) * fVar5));
    }
    else {
      fVar5 = dCamMath::customRBRatio(t,d_cam_param::_4369);
      dVar2 = (double)(float)(dVar2 + (double)((float)(dVar2 - dVar4) * fVar5));
    }
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  __psq_l0(auStack40,uVar1);
  __psq_l1(auStack40,uVar1);
  return dVar2;
}


/* __thiscall dCamParam_c::DefaultRadius(float *) */

undefined4 __thiscall dCamParam_c::DefaultRadius(dCamParam_c *this,float *pR)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = this->mpStyle->field_0x3c;
  fVar2 = this->mpStyle->field_0x40;
  fVar3 = fVar2;
  if (fVar1 < fVar2) {
    fVar3 = fVar1;
    fVar1 = fVar2;
  }
  if (*pR <= fVar1) {
    if (fVar3 <= *pR) {
      return 1;
    }
    *pR = fVar3;
    return 0;
  }
  *pR = fVar1;
  return 0;
}


/* __thiscall dCamParam_c::RadiusRatio(float) */

double __thiscall dCamParam_c::RadiusRatio(dCamParam_c *this,float r)

{
  float fVar1;
  float fVar2;
  dCamera__Style *pdVar3;
  
  pdVar3 = this->mpStyle;
  fVar1 = pdVar3->field_0x30;
  if (fVar1 <= r) {
    if (fVar1 < r) {
      fVar2 = pdVar3->field_0x38 - fVar1;
      if (fVar2 <= r - fVar1) {
        return (double)d_cam_param::_4127;
      }
      if (d_cam_param::_4589 < fVar2) {
        return (double)((r - fVar1) / fVar2);
      }
    }
  }
  else {
    fVar2 = fVar1 - pdVar3->field_0x34;
    if (fVar2 <= fVar1 - r) {
      return (double)d_cam_param::_4126;
    }
    if (d_cam_param::_4589 < fVar2) {
      return (double)(-(fVar1 - r) / fVar2);
    }
  }
  return (double)d_cam_param::_4103;
}


/* __thiscall dCamParam_c::CenterHeight(float) */

float __thiscall dCamParam_c::CenterHeight(dCamParam_c *this,float param_1)

{
  dCamera__Style *pdVar1;
  double dVar2;
  
  pdVar1 = this->mpStyle;
  dVar2 = (double)ratiof(this,param_1,pdVar1->mCenterHeightUpper,pdVar1->mCenterHeightLower,
                         pdVar1->mCenterHeightBase);
  return (float)dVar2;
}


/* __thiscall dCamParam_c::Fovy(float) */

void __thiscall dCamParam_c::Fovy(dCamParam_c *this,float param_1)

{
  dCamera__Style *pdVar1;
  
  pdVar1 = this->mpStyle;
  ratiof(this,param_1,pdVar1->mFovyUpper,pdVar1->mFovyLower,pdVar1->mFovyBase);
  return;
}


/* WARNING: Removing unreachable block (ram,0x800afc58) */
/* __thiscall dCamParam_c::LockonLongitude(float) */

int __thiscall dCamParam_c::LockonLongitude(dCamParam_c *this,float param_1)

{
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f31;
  cSAngle acStack40 [2];
  cSAngle acStack36 [2];
  cSAngle acStack32 [2];
  cSAngle local_1c [4];
  undefined auStack8 [8];
  
  dVar2 = (double)param_1;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  cSAngle::cSAngle(local_1c,this->mpStyle->mLockonLongitudeMin);
  cSAngle::cSAngle(acStack32,this->mpStyle->mLockonLongitudeMax);
  cSAngle::operator__(acStack36,acStack32);
  cSAngle::operator_(acStack40,(float)dVar2);
  cSAngle::operator___(local_1c,acStack40);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return (int)local_1c[0];
}


/* WARNING: Removing unreachable block (ram,0x800afce4) */
/* __thiscall dCamParam_c::LockonLatitude(float) */

int __thiscall dCamParam_c::LockonLatitude(dCamParam_c *this,float param_1)

{
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f31;
  cSAngle local_28;
  cSAngle local_24;
  cSAngle local_20;
  cSAngle local_1c;
  undefined auStack8 [8];
  
  dVar2 = (double)param_1;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  cSAngle::cSAngle(&local_1c,this->mpStyle->mLockonLatitudeMin);
  cSAngle::cSAngle(&local_20,this->mpStyle->mLockonLatitudeMax);
  cSAngle::operator__(&local_24,&local_20);
  cSAngle::operator_(&local_28,(float)dVar2);
  cSAngle::operator___(&local_1c,&local_28);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return (int)local_1c;
}


/* __thiscall dCamParam_c::LockonFovy(float) */

double __thiscall dCamParam_c::LockonFovy(dCamParam_c *this,float param_1)

{
  float fVar1;
  
  fVar1 = this->mpStyle->mLockonFovyMin;
  return (double)(fVar1 + param_1 * (this->mpStyle->mLockonFovyMax - fVar1));
}


/* __thiscall dCamParam_c::LockonCenterHeight(float) */

double __thiscall dCamParam_c::LockonCenterHeight(dCamParam_c *this,float param_1)

{
  float fVar1;
  
  fVar1 = this->mpStyle->mLockonCenterHeightMin;
  return (double)(fVar1 + param_1 * (this->mpStyle->mLockonCenterHeightMax - fVar1));
}


/* __thiscall dCamSetup_c::dCamSetup_c(void) */

void __thiscall dCamSetup_c::dCamSetup_c(dCamSetup_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  this->vtbl = (undefined *)&__vt;
  dCstick_c::dCstick_c(&this->mCstick);
  dCamBGChk_c::dCamBGChk_c(&this->mBGChk);
  fVar1 = d_cam_param::_4127;
  this->field_0x0 = d_cam_param::_4127;
  this->field_0x4 = d_cam_param::_4673;
  this->field_0xc = 1;
  this->field_0x10 = -1;
  this->field_0x1c = -1;
  fVar2 = d_cam_param::_4348;
  this->field_0x20 = d_cam_param::_4348;
  this->field_0x24 = d_cam_param::_4674;
  this->field_0x60 = d_cam_param::_4370;
  this->field_0x5c = d_cam_param::_4675;
  this->field_0x28 = d_cam_param::_4676;
  this->field_0x2c = d_cam_param::_4677;
  fVar3 = d_cam_param::_4678;
  this->field_0x50 = d_cam_param::_4678;
  this->field_0x30 = d_cam_param::_4368;
  this->field_0x38 = d_cam_param::_4679;
  this->field_0x3c = fVar1;
  fVar4 = d_cam_param::_4680;
  this->field_0x58 = d_cam_param::_4680;
  this->field_0x44 = d_cam_param::_4681;
  this->field_0x54 = d_cam_param::_4682;
  this->field_0x4c = fVar1;
  this->field_0x34 = d_cam_param::_4359;
  this->field_0x48 = d_cam_param::_4374;
  fVar1 = d_cam_param::_4683;
  this->field_0x40 = d_cam_param::_4683;
  this->field_0x64 = d_cam_param::_4684;
  this->field_0x68 = d_cam_param::_4685;
  this->field_0x94 = 0x96;
  this->field_0x98 = fVar1;
  this->field_0x9c = d_cam_param::_4365;
  this->field_0xa0 = fVar2;
  this->field_0x88 = d_cam_param::_4367;
  this->field_0x8c = d_cam_param::_4686;
  this->field_0x8 = 1;
  this->field_0xa4 = d_cam_param::_4687;
  this->field_0xa8 = 0x14;
  this->field_0xac = d_cam_param::_4688;
  this->field_0xb0 = 0x3c;
  this->field_0xb4 = fVar4;
  this->field_0xb8 = d_cam_param::_4689;
  this->field_0xbc = d_cam_param::_4103;
  this->field_0x6c = d_cam_param::_4690;
  this->field_0x70 = d_cam_param::_4691;
  this->field_0x74 = 0x78;
  this->field_0x78 = d_cam_param::_4364;
  this->field_0x7c = d_cam_param::_4360;
  this->field_0x80 = d_cam_param::_4366;
  this->field_0x84 = d_cam_param::_4692;
  this->field_0xc0 = fVar1;
  this->field_0xc4 = fVar3;
  this->field_0xc8 = 0xffffffff;
  return;
}


/* __thiscall dCamSetup_c::~dCamSetup_c(void) */

void __thiscall dCamSetup_c::_dCamSetup_c(dCamSetup_c *this)

{
  short in_r4;
  
  if (this != (dCamSetup_c *)0x0) {
    this->vtbl = (undefined *)&__vt;
    if (this != (dCamSetup_c *)0xffffff30) {
      (this->mCstick).vtbl = (undefined *)&dCstick_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dCamSetup_c::CheckLatitudeRange(short *) */

undefined4 __thiscall dCamSetup_c::CheckLatitudeRange(dCamSetup_c *this,short *param_1)

{
  undefined4 uVar1;
  short sVar2;
  
  sVar2 = (short)(int)(d_cam_param::_4517 * this->field_0x60);
  if (sVar2 < *param_1) {
    *param_1 = sVar2;
    uVar1 = 0;
  }
  else {
    sVar2 = (short)(int)(d_cam_param::_4517 * this->field_0x5c);
    if (*param_1 < sVar2) {
      *param_1 = sVar2;
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}


/* WARNING: Removing unreachable block (ram,0x800affe8) */
/* __thiscall dCamSetup_c::FanBank(void) */

double __thiscall dCamSetup_c::FanBank(dCamSetup_c *this)

{
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f31;
  float fVar3;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar2 = d_kankyo_wether::dKyw_get_wind_pow();
  fVar3 = SComponent::cM_rndFX(this->field_0x84);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return (double)(this->field_0x80 + (float)((double)fVar3 * dVar2));
}


/* __thiscall dCstick_c::~dCstick_c(void) */

void __thiscall dCstick_c::_dCstick_c(dCstick_c *this)

{
  short in_r4;
  
  if ((this != (dCstick_c *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

