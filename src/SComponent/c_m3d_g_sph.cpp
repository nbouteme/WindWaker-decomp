#include <SComponent/c_m3d_g_sph.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <SComponent/c_m3d.h>
#include <cM3dGSph.h>


/* __thiscall cM3dGSph::SetC(cXyz const &) */

void __thiscall cM3dGSph::SetC(cM3dGSph *this,cXyz *param_1)

{
  float fVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  ulong uVar5;
  
  fVar1 = param_1->x;
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
              (uVar5,"c_m3d_g_sph.cpp",0x12,
               "!(((sizeof(p.x) == sizeof(float)) ? __fpclassifyf((float)(p.x)) : __fpclassifyd((double)(p.x)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d_g_sph.cpp",0x12,&DAT_80366137);
  }
  fVar1 = param_1->y;
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
              (uVar5,"c_m3d_g_sph.cpp",0x13,
               "!(((sizeof(p.y) == sizeof(float)) ? __fpclassifyf((float)(p.y)) : __fpclassifyd((double)(p.y)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d_g_sph.cpp",0x13,&DAT_80366137);
  }
  fVar1 = param_1->z;
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
              (uVar5,"c_m3d_g_sph.cpp",0x14,
               "!(((sizeof(p.z) == sizeof(float)) ? __fpclassifyf((float)(p.z)) : __fpclassifyd((double)(p.z)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d_g_sph.cpp",0x14,&DAT_80366137);
  }
  bVar3 = false;
  if ((((SComponent::_349 < param_1->x) && (param_1->x < SComponent::_350)) &&
      (SComponent::_349 < param_1->y)) &&
     (((param_1->y < SComponent::_350 && (SComponent::_349 < param_1->z)) &&
      (param_1->z < SComponent::_350)))) {
    bVar3 = true;
  }
  if (!bVar3) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_m3d_g_sph.cpp",0x17,
               "-1.0e32f < p.x && p.x < 1.0e32f && -1.0e32f < p.y && p.y < 1.0e32f && -1.0e32f < p.z && p.z < 1.0e32f"
              );
    m_Do_printf::OSPanic("c_m3d_g_sph.cpp",0x17,&DAT_80366137);
  }
  (this->mCenter).x = param_1->x;
  (this->mCenter).y = param_1->y;
  (this->mCenter).z = param_1->z;
  return;
}


/* WARNING: Removing unreachable block (ram,0x80252734) */
/* __thiscall cM3dGSph::SetR(float) */

void __thiscall cM3dGSph::SetR(cM3dGSph *this,float param_1)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  ulong uVar4;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar6 = (double)param_1;
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar1 = (uint)param_1 & 0x7f800000;
  if (uVar1 == 0x7f800000) {
    if (((uint)param_1 & 0x7fffff) == 0) {
      iVar3 = 2;
    }
    else {
      iVar3 = 1;
    }
  }
  else {
    if ((uVar1 < 0x7f800000) && (uVar1 == 0)) {
      if (((uint)param_1 & 0x7fffff) == 0) {
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
              (uVar4,"c_m3d_g_sph.cpp",0x20,
               "!(((sizeof(r) == sizeof(float)) ? __fpclassifyf((float)(r)) : __fpclassifyd((double)(r)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d_g_sph.cpp",0x20,&DAT_80366137);
  }
  bVar2 = false;
  if (((double)SComponent::_349 < dVar6) && (dVar6 < (double)SComponent::_350)) {
    bVar2 = true;
  }
  if (!bVar2) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"c_m3d_g_sph.cpp",0x21,"-1.0e32f < r && r < 1.0e32f");
    m_Do_printf::OSPanic("c_m3d_g_sph.cpp",0x21,&DAT_80366137);
  }
  this->mRadius = (float)dVar6;
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* __thiscall cM3dGSph::cross(cM3dGSph const *,
                              cXyz *) const */

void __thiscall cM3dGSph::cross(cM3dGSph *this,cM3dGSph *param_1,cXyz *param_2)

{
  SComponent::cM3d_Cross_SphSph(param_1,this);
  return;
}


/* __thiscall cM3dGSph::cross(cM3dGCyl const *,
                              cXyz *) const */

void __thiscall cM3dGSph::cross(cM3dGSph *this,cM3dGCyl *param_1,cXyz *param_2)

{
  undefined auStack8 [8];
  
  SComponent::cM3d_Cross_CylSph(param_1,this,param_2,auStack8);
  return;
}


/* __thiscall cM3dGSph::cross(cM3dGSph const *,
                              float *) const */

void __thiscall cM3dGSph::cross(cM3dGSph *this,cM3dGSph *param_1,float *param_2)

{
  undefined auStack8 [8];
  
  SComponent::cM3d_Cross_SphSph(this,param_1,auStack8,param_2);
  return;
}

