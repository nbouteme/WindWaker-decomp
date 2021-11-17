#include <SComponent/c_angle.h>
#include <SComponent/c_angle.h>
#include <MSL_C.PPCEABI.bare.H/s_sin.h>
#include <MSL_C.PPCEABI.bare.H/s_cos.h>
#include <MSL_C.PPCEABI.bare.H/s_tan.h>
#include <SComponent/c_math.h>
#include <d_door.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <cXyz.h>
#include <cSPolar.h>
#include <cAngle.h>
#include <cDegree.h>
#include <cSGlobe.h>
#include <cSAngle.h>

struct cSAngle cSAngle;
undefined1 cSAngle;
undefined1 cSAngle;
undefined1 cSAngle;
undefined1 cSAngle;

/* __thiscall cSAngle::cSAngle(cSAngle const &) */

void __thiscall cSAngle::cSAngle(cSAngle *this,cSAngle *param_1)

{
  Val(this,param_1);
  return;
}


/* __thiscall cSAngle::cSAngle(short) */

void __thiscall cSAngle::cSAngle(cSAngle *this,short param_1)

{
  Val(this,param_1);
  return;
}


/* __thiscall cSAngle::cSAngle(float) */

void __thiscall cSAngle::cSAngle(cSAngle *this,float param_1)

{
  Val(this,param_1);
  return;
}


/* __thiscall cSAngle::Val(cSAngle const &) */

void __thiscall cSAngle::Val(cSAngle *this,cSAngle *param_1)

{
  this->v = param_1->v;
  return;
}


/* __thiscall cSAngle::Val(short) */

void __thiscall cSAngle::Val(cSAngle *this,short param_1)

{
  this->v = param_1;
  return;
}


/* __thiscall cSAngle::Val(float) */

void __thiscall cSAngle::Val(cSAngle *this,float param_1)

{
  this->v = (short)(int)(SComponent::_2211 * param_1);
  return;
}


/* __thiscall cSAngle::Degree(void) const */

double __thiscall cSAngle::Degree(cSAngle *this)

{
  return (double)(SComponent::_2223 *
                 (float)((double)CONCAT44(0x43300000,(int)this->v ^ 0x80000000) - SComponent::_2226)
                 );
}


/* __thiscall cSAngle::Radian(void) const */

double __thiscall cSAngle::Radian(cSAngle *this)

{
  return (double)(SComponent::_2232 *
                 (float)((double)CONCAT44(0x43300000,(int)this->v ^ 0x80000000) - SComponent::_2226)
                 );
}


/* __thiscall cSAngle::Norm(void) const */

double __thiscall cSAngle::Norm(cSAngle *this)

{
  return (double)(SComponent::_2240 *
                 (float)((double)CONCAT44(0x43300000,(int)this->v ^ 0x80000000) - SComponent::_2226)
                 );
}


/* __thiscall cSAngle::Abs(void) const */

int __thiscall cSAngle::Abs(cSAngle *this)

{
  short sVar1;
  short sVar2;
  
  sVar1 = this->v;
  sVar2 = -sVar1;
  if (-1 < sVar1) {
    sVar2 = sVar1;
  }
  return (int)sVar2;
}


/* __thiscall cSAngle::Inv(void) const */

int __thiscall cSAngle::Inv(cSAngle *this)

{
  return (int)(short)(this->v + -0x8000);
}


/* __thiscall cSAngle::Sin(void) const */

double __thiscall cSAngle::Sin(cSAngle *this)

{
  double dVar1;
  
  dVar1 = (double)Radian(this);
  dVar1 = MSL_C.PPCEABI.bare.H::sin(dVar1);
  return (double)(float)dVar1;
}


/* __thiscall cSAngle::Cos(void) const */

double __thiscall cSAngle::Cos(cSAngle *this)

{
  double dVar1;
  
  dVar1 = (double)Radian(this);
  dVar1 = MSL_C.PPCEABI.bare.H::cos(dVar1);
  return (double)(float)dVar1;
}


/* __thiscall cSAngle::Tan(void) const */

double __thiscall cSAngle::Tan(cSAngle *this)

{
  double dVar1;
  
  dVar1 = (double)Radian(this);
  dVar1 = MSL_C.PPCEABI.bare.H::tan(dVar1);
  return (double)(float)dVar1;
}


/* __thiscall cSAngle::operator -(void) const */

void __thiscall cSAngle::operator__(cSAngle *this)

{
  short *in_r4;
  
  cSAngle(this,-*in_r4);
  return;
}


/* __thiscall cSAngle::operator +(cSAngle const &) const */

void __thiscall cSAngle::operator__(cSAngle *this,cSAngle *param_1)

{
  short *in_r5;
  
  cSAngle(this,param_1->v + *in_r5);
  return;
}


/* __thiscall cSAngle::operator -(cSAngle const &) const */

void __thiscall cSAngle::operator__(cSAngle *this,cSAngle *param_1)

{
  short *in_r5;
  
  cSAngle(this,param_1->v - *in_r5);
  return;
}


/* __thiscall cSAngle::operator +=(cSAngle const &) */

void __thiscall cSAngle::operator___(cSAngle *this,cSAngle *param_1)

{
  this->v = this->v + param_1->v;
  return;
}


/* __thiscall cSAngle::operator -=(cSAngle const &) */

void __thiscall cSAngle::operator___(cSAngle *this,cSAngle *param_1)

{
  this->v = this->v - param_1->v;
  return;
}


/* __thiscall cSAngle::operator +(short) const */

void __thiscall cSAngle::operator__(cSAngle *this,short param_1)

{
  undefined2 in_register_00000010;
  short in_r5;
  
  cSAngle(this,*(short *)CONCAT22(in_register_00000010,param_1) + in_r5);
  return;
}


/* __thiscall cSAngle::operator -(short) const */

cSAngle * __thiscall cSAngle::operator__(cSAngle *this,cSAngle *param_1,short param_2)

{
  cSAngle(this,param_1->v - param_2);
  return this;
}


/* __thiscall cSAngle::operator +=(short) */

void __thiscall cSAngle::operator___(cSAngle *this,short param_1)

{
  this->v = this->v + param_1;
  return;
}


/* __thiscall cSAngle::operator -=(short) */

void __thiscall cSAngle::operator___(cSAngle *this,short param_1)

{
  this->v = this->v - param_1;
  return;
}


/* __thiscall cSAngle::operator *(float) const */

void __thiscall cSAngle::operator_(cSAngle *this,float param_1)

{
  short *in_r4;
  
  cSAngle(this,(short)(int)((float)((double)CONCAT44(0x43300000,(int)*in_r4 ^ 0x80000000) -
                                   SComponent::_2226) * param_1));
  return;
}


/* __thiscall cSAngle::operator *=(float) */

void __thiscall cSAngle::operator__(cSAngle *this,float param_1)

{
  this->v = (short)(int)((float)((double)CONCAT44(0x43300000,(int)this->v ^ 0x80000000) -
                                SComponent::_2226) * param_1);
  return;
}


namespace SComponent {

/* __stdcall operator +(short,
                        cSAngle const &) */

void operator__(cSAngle *param_1,short param_2,short *param_3)

{
  ::cSAngle::cSAngle(param_1,param_2 + *param_3);
  return;
}


/* __stdcall operator -(short,
                        cSAngle const &) */

void operator__(cSAngle *param_1,short param_2,short *param_3)

{
  ::cSAngle::cSAngle(param_1,param_2 - *param_3);
  return;
}

}

/* __thiscall cDegree::cDegree(float) */

void __thiscall cDegree::cDegree(cDegree *this,float param_1)

{
  Val(this,param_1);
  return;
}


/* __thiscall cDegree::Formal(void) */

cDegree * __thiscall cDegree::Formal(cDegree *this)

{
  double dVar1;
  
  dVar1 = (double)cAngle::Adjust((cAngle *)this,*(float *)this,SComponent::_2403,SComponent::_2404);
  *(float *)this = (float)dVar1;
  return this;
}


/* __thiscall cDegree::Val(float) */

void __thiscall cDegree::Val(cDegree *this,float param_1)

{
  *(float *)this = param_1;
  Formal(this);
  return;
}


/* __thiscall cDegree::Radian(void) const */

double __thiscall cDegree::Radian(cDegree *this)

{
  return (double)(SComponent::_2437 * *(float *)this);
}


/* __thiscall cDegree::Sin(void) const */

double __thiscall cDegree::Sin(cDegree *this)

{
  double dVar1;
  
  dVar1 = (double)Radian(this);
  dVar1 = MSL_C.PPCEABI.bare.H::sin(dVar1);
  return (double)(float)dVar1;
}


/* __thiscall cDegree::Cos(void) const */

double __thiscall cDegree::Cos(cDegree *this)

{
  double dVar1;
  
  dVar1 = (double)Radian(this);
  dVar1 = MSL_C.PPCEABI.bare.H::cos(dVar1);
  return (double)(float)dVar1;
}


/* __thiscall cSPolar::cSPolar(cXyz const &) */

void __thiscall cSPolar::cSPolar(cSPolar *this,cXyz *param_1)

{
  Val(this,param_1);
  return;
}


/* __thiscall cSPolar::Formal(void) */

cSPolar * __thiscall cSPolar::Formal(cSPolar *this)

{
  short sVar1;
  cSAngle acStack24 [2];
  cSAngle acStack20 [2];
  cSAngle acStack16 [6];
  
  if (this->mDistance < SComponent::0_0) {
    this->mDistance = -this->mDistance;
    cSAngle::cSAngle(acStack16,-0x8000);
    cSAngle::operator__(acStack20,acStack16);
    cSAngle::Val(&this->mAngleX,acStack20);
    sVar1 = cSAngle::Inv(&this->mAngleY);
    cSAngle::Val(&this->mAngleY,sVar1);
  }
  sVar1 = (this->mAngleX).v;
  if ((sVar1 < 0) && (sVar1 != -0x8000)) {
    cSAngle::operator__(acStack24);
    cSAngle::Val(&this->mAngleX,acStack24);
    sVar1 = cSAngle::Inv(&this->mAngleY);
    cSAngle::Val(&this->mAngleY,sVar1);
  }
  return this;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall cSPolar::Val(float,
                           short,
                           short) */

void __thiscall cSPolar::Val(cSPolar *this,float param_1,short param_2,short param_3)

{
  cSAngle local_18 [2];
  cSAngle local_14 [6];
  
  this->mDistance = param_1;
  cSAngle::cSAngle(local_14,param_2);
  (this->mAngleX).v = local_14[0];
  cSAngle::cSAngle(local_18,param_3);
  (this->mAngleY).v = local_18[0];
  Formal(this);
  return;
}


/* WARNING: Removing unreachable block (ram,0x802543fc) */
/* WARNING: Removing unreachable block (ram,0x80254404) */
/* __thiscall cSPolar::Val(cXyz const &) */

void __thiscall cSPolar::Val(cSPolar *this,cXyz *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar9 = (double)param_1->x;
  dVar6 = (double)param_1->y;
  dVar8 = (double)param_1->z;
  dVar7 = (double)(float)(dVar8 * dVar8) + (double)(float)(dVar9 * dVar9);
  dVar4 = dVar7 + (double)(float)(dVar6 * dVar6);
  fVar1 = SComponent::0_0;
  if (dVar7 > SComponent::0_0) {
    if (dVar7 <= SComponent::0_0) {
      dVar5 = SComponent::0_0;
      if (SComponent::0_0 != dVar7) {
        if (dVar7 == SComponent::0_0) {
          dVar5 = (double)MSL_C.PPCEABI.bare.H::__float_huge;
        }
        else {
          dVar5 = (double)MSL_C.PPCEABI.bare.H::__float_nan;
        }
      }
    }
    else {
      dVar5 = 1.0 / SQRT(dVar7);
      dVar5 = SComponent::0_5 * dVar5 * (SComponent::3_0 - dVar7 * dVar5 * dVar5);
      dVar5 = SComponent::0_5 * dVar5 * (SComponent::3_0 - dVar7 * dVar5 * dVar5);
      dVar5 = SComponent::0_5 * dVar5 * (SComponent::3_0 - dVar7 * dVar5 * dVar5);
      dVar5 = dVar7 * SComponent::0_5 * dVar5 * (SComponent::3_0 - dVar7 * dVar5 * dVar5);
    }
    fVar1 = (float)dVar5;
  }
  fVar2 = SComponent::0_0;
  if (dVar4 > SComponent::0_0) {
    if (dVar4 <= SComponent::0_0) {
      dVar7 = SComponent::0_0;
      if (SComponent::0_0 != dVar4) {
        if (dVar4 == SComponent::0_0) {
          dVar7 = (double)MSL_C.PPCEABI.bare.H::__float_huge;
        }
        else {
          dVar7 = (double)MSL_C.PPCEABI.bare.H::__float_nan;
        }
      }
    }
    else {
      dVar7 = 1.0 / SQRT(dVar4);
      dVar7 = SComponent::0_5 * dVar7 * (SComponent::3_0 - dVar4 * dVar7 * dVar7);
      dVar7 = SComponent::0_5 * dVar7 * (SComponent::3_0 - dVar4 * dVar7 * dVar7);
      dVar7 = SComponent::0_5 * dVar7 * (SComponent::3_0 - dVar4 * dVar7 * dVar7);
      dVar7 = dVar4 * SComponent::0_5 * dVar7 * (SComponent::3_0 - dVar4 * dVar7 * dVar7);
    }
    fVar2 = (float)dVar7;
  }
  this->mDistance = fVar2;
  dVar4 = SComponent::cM_atan2f((double)fVar1,dVar6);
  cSAngle::Val(&this->mAngleX,(short)(int)((double)SComponent::_2657 * dVar4));
  dVar4 = SComponent::cM_atan2f(dVar9,dVar8);
  cSAngle::Val(&this->mAngleY,(short)(int)((double)SComponent::_2657 * dVar4));
  Formal(this);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return;
}


/* WARNING: Removing unreachable block (ram,0x802544c0) */
/* WARNING: Removing unreachable block (ram,0x802544b8) */
/* WARNING: Removing unreachable block (ram,0x802544c8) */
/* __thiscall cSPolar::Xyz(void) const */

void __thiscall cSPolar::Xyz(cSPolar *this)

{
  float *in_r4;
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f29;
  double dVar3;
  undefined8 in_f30;
  double dVar4;
  undefined8 in_f31;
  double dVar5;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  dVar2 = (double)cSAngle::Radian((cSAngle *)(in_r4 + 1));
  dVar2 = MSL_C.PPCEABI.bare.H::sin(dVar2);
  dVar3 = (double)(*in_r4 * (float)dVar2);
  dVar2 = (double)cSAngle::Radian((cSAngle *)((int)in_r4 + 6));
  dVar2 = MSL_C.PPCEABI.bare.H::cos(dVar2);
  dVar4 = (double)(float)dVar2;
  dVar2 = (double)cSAngle::Radian((cSAngle *)(in_r4 + 1));
  dVar2 = MSL_C.PPCEABI.bare.H::cos(dVar2);
  dVar5 = (double)(*in_r4 * (float)dVar2);
  dVar2 = (double)cSAngle::Radian((cSAngle *)((int)in_r4 + 6));
  dVar2 = MSL_C.PPCEABI.bare.H::sin(dVar2);
  this->mDistance = (float)(dVar3 * (double)(float)dVar2);
  *(float *)&this->mAngleX = (float)dVar5;
  this[1].mDistance = (float)(dVar3 * dVar4);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  __psq_l0(auStack40,uVar1);
  __psq_l1(auStack40,uVar1);
  return;
}


/* __thiscall cSPolar::Globe(cSGlobe *) const */

void __thiscall cSPolar::Globe(cSPolar *this,cSGlobe *param_1)

{
  cSGlobe::Val(param_1,this->mDistance,0x4000 - (this->mAngleX).v,(this->mAngleY).v);
  return;
}


/* __thiscall cSGlobe::cSGlobe(cSGlobe const &) */

void __thiscall cSGlobe::cSGlobe(cSGlobe *this,cSGlobe *param_1)

{
  Val(this,param_1);
  return;
}


/* __thiscall cSGlobe::cSGlobe(float,
                               short,
                               short) */

void __thiscall cSGlobe::cSGlobe(cSGlobe *this,float param_1,short param_2,short param_3)

{
  Val(this,param_1,param_2,param_3);
  return;
}


/* __thiscall cSGlobe::cSGlobe(float,
                               cSAngle const &,
                               cSAngle const &) */

void __thiscall cSGlobe::cSGlobe(cSGlobe *this,float param_1,cSAngle *param_2,cSAngle *param_3)

{
  Val(this,param_1,param_2,param_3);
  return;
}


/* __thiscall cSGlobe::cSGlobe(cXyz const &) */

void __thiscall cSGlobe::cSGlobe(cSGlobe *this,cXyz *param_1)

{
  Val(this,param_1);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall cSGlobe::Formal(void) */

cSGlobe * __thiscall cSGlobe::Formal(cSGlobe *this)

{
  short sVar1;
  cSAngle local_18;
  cSAngle acStack20 [2];
  cSAngle local_10;
  
  if (this->mDistance < SComponent::0_0) {
    this->mDistance = -this->mDistance;
    cSAngle::operator__(&local_10);
    (this->mAngleX).v = local_10;
    sVar1 = cSAngle::Inv(&this->mAngleY);
    cSAngle::Val(&this->mAngleY,sVar1);
  }
  sVar1 = (this->mAngleX).v;
  if ((sVar1 < -0x4000) || (0x4000 < sVar1)) {
    cSAngle::cSAngle(acStack20,-0x8000);
    cSAngle::operator__(&local_18,acStack20);
    (this->mAngleX).v = local_18;
    sVar1 = cSAngle::Inv(&this->mAngleY);
    cSAngle::Val(&this->mAngleY,sVar1);
  }
  return this;
}


/* __thiscall cSGlobe::Val(cSGlobe const &) */

void __thiscall cSGlobe::Val(cSGlobe *this,cSGlobe *param_1)

{
  this->mDistance = param_1->mDistance;
  (this->mAngleX).v = (param_1->mAngleX).v;
  (this->mAngleY).v = (param_1->mAngleY).v;
  Formal(this);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall cSGlobe::Val(float,
                           short,
                           short) */

void __thiscall cSGlobe::Val(cSGlobe *this,float param_1,short param_2,short param_3)

{
  cSAngle local_18 [2];
  cSAngle local_14 [6];
  
  this->mDistance = param_1;
  cSAngle::cSAngle(local_14,param_2);
  (this->mAngleX).v = local_14[0];
  cSAngle::cSAngle(local_18,param_3);
  (this->mAngleY).v = local_18[0];
  Formal(this);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall cSGlobe::Val(float,
                           cSAngle const &,
                           cSAngle const &) */

void __thiscall cSGlobe::Val(cSGlobe *this,float param_1,cSAngle *param_2,cSAngle *param_3)

{
  cSAngle local_18 [2];
  cSAngle local_14 [6];
  
  this->mDistance = param_1;
  cSAngle::cSAngle(local_14,param_2->v);
  (this->mAngleX).v = local_14[0];
  cSAngle::cSAngle(local_18,param_3->v);
  (this->mAngleY).v = local_18[0];
  Formal(this);
  return;
}


/* __thiscall cSGlobe::Val(cXyz const &) */

void __thiscall cSGlobe::Val(cSGlobe *this,cXyz *param_1)

{
  cSPolar acStack24 [2];
  
  cSPolar::cSPolar(acStack24,param_1);
  cSPolar::Globe(acStack24,this);
  Formal(this);
  return;
}


/* __thiscall cSGlobe::Xyz(void) const */

cXyz * __thiscall cSGlobe::Xyz(cXyz *__return_storage_ptr__,cSGlobe *this)

{
  cXyz *pcVar1;
  cSPolar acStack24 [2];
  
  Polar(this,acStack24);
  pcVar1 = (cXyz *)cSPolar::Xyz((cSPolar *)__return_storage_ptr__);
  return pcVar1;
}


/* __thiscall cSGlobe::Polar(cSPolar *) const */

void __thiscall cSGlobe::Polar(cSGlobe *this,cSPolar *param_1)

{
  cSPolar::Val(param_1,this->mDistance,0x4000 - (this->mAngleX).v,(this->mAngleY).v);
  return;
}


/* __thiscall cSGlobe::Invert(void) */

void __thiscall cSGlobe::Invert(cSGlobe *this)

{
  this->mDistance = -this->mDistance;
  Formal(this);
  return;
}


/* __thiscall cAngle::Adjust<float>(float,
                                    float,
                                    float) */

void __thiscall cAngle::Adjust(cAngle *this,float param_1,float param_2,float param_3)

{
  for (; param_3 <= param_1; param_1 = param_1 - (param_3 - param_2)) {
  }
  for (; param_1 < param_2; param_1 = param_1 + (param_3 - param_2)) {
  }
  return;
}


namespace SComponent {

void __sinit_c_angle_cpp(void)

{
  ::cSAngle::cSAngle(&::cSAngle::_0,0);
  Runtime.PPCEABI.H::__register_global_object();
  ::cSAngle::cSAngle((cSAngle *)&::cSAngle::_1,0xb6);
  Runtime.PPCEABI.H::__register_global_object();
  ::cSAngle::cSAngle((cSAngle *)&::cSAngle::_90,0x4000);
  Runtime.PPCEABI.H::__register_global_object();
  ::cSAngle::cSAngle((cSAngle *)&::cSAngle::_180,-0x8000);
  Runtime.PPCEABI.H::__register_global_object();
  ::cSAngle::cSAngle((cSAngle *)&::cSAngle::_270,-0x4000);
  Runtime.PPCEABI.H::__register_global_object();
  return;
}

