#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <SComponent/c_xyz.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <cXyz.h>

struct cXyz cXyz;
struct cXyz cXyz;
struct cXyz cXyz;
struct cXyz cXyz;
undefined1 cXyz;
undefined1 cXyz;
undefined1 cXyz;
struct cXyz cXyz;

/* __thiscall cXyz::operator +(Vec const &) const */

cXyz * __thiscall cXyz::operator__(cXyz *__return_storage_ptr__,cXyz *this,cXyz *param_1)

{
  cXyz local_18;
  
  mtx::PSVECAdd(this,param_1,&local_18);
  __return_storage_ptr__->x = local_18.x;
  __return_storage_ptr__->y = local_18.y;
  __return_storage_ptr__->z = local_18.z;
  return this;
}


/* __thiscall cXyz::operator -(Vec const &) const */

cXyz * __thiscall cXyz::operator__(cXyz *__return_storage_ptr__,cXyz *this,cXyz *param_1)

{
  cXyz local_18;
  
  mtx::PSVECSubtract(this,param_1,&local_18);
  __return_storage_ptr__->x = local_18.x;
  __return_storage_ptr__->y = local_18.y;
  __return_storage_ptr__->z = local_18.z;
  return this;
}


/* __thiscall cXyz::operator *(float) const */

cXyz * __thiscall cXyz::operator_(cXyz *this,cXyz *param_1,float param_2)

{
  TVec3_float_ local_18;
  
  mtx::PSVECScale(param_1,(cXyz *)&local_18,param_2);
  this->x = local_18.x;
  this->y = local_18.y;
  this->z = local_18.z;
  return param_1;
}


/* __thiscall cXyz::operator *(Vec const &) const */

void __thiscall cXyz::operator_(cXyz *this,Vec *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *in_r5;
  
  fVar1 = *(float *)(param_1 + 4);
  fVar2 = in_r5[1];
  fVar3 = *(float *)(param_1 + 8);
  fVar4 = in_r5[2];
  this->x = *(float *)param_1 * *in_r5;
  this->y = fVar1 * fVar2;
  this->z = fVar3 * fVar4;
  return;
}


/* __thiscall cXyz::operator /(float) const */

void __thiscall cXyz::operator__(cXyz *this,float param_1)

{
  cXyz *in_r4;
  cXyz local_18;
  
  mtx::PSVECScale(in_r4,&local_18,SComponent::1_0 / param_1);
  this->x = local_18.x;
  this->y = local_18.y;
  this->z = local_18.z;
  return;
}


/* __thiscall cXyz::getCrossProduct(Vec const &) const */

cXyz * __thiscall cXyz::getCrossProduct(cXyz *__return_storage_ptr__,cXyz *this,cXyz *param_1)

{
  TVec3_float_ local_18;
  
  mtx::PSVECCrossProduct((TVec3_float_ *)this,(TVec3_float_ *)param_1,&local_18);
  __return_storage_ptr__->x = local_18.x;
  __return_storage_ptr__->y = local_18.y;
  __return_storage_ptr__->z = local_18.z;
  return this;
}


/* __thiscall cXyz::outprod(Vec const &) const */

cXyz * __thiscall cXyz::outprod(cXyz *__return_storage_ptr__,cXyz *this,cXyz *param_1)

{
  cXyz *pcVar1;
  
  pcVar1 = getCrossProduct(__return_storage_ptr__,this,param_1);
  return pcVar1;
}


/* WARNING: Removing unreachable block (ram,0x802458f8) */
/* __thiscall cXyz::norm(void) const */

void __thiscall cXyz::norm(cXyz *this)

{
  uint uVar1;
  JUTAssertion *this_00;
  cXyz *in_r4;
  char *in_r8;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  float fVar4;
  float local_28;
  float local_24;
  float local_20;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar4 = mtx::PSVECSquareMag(in_r4);
  dVar3 = (double)fVar4;
  this_00 = (JUTAssertion *)JUTAssertion::getSDevice();
  uVar1 = countLeadingZeros(((uint)(byte)((dVar3 < (double)SComponent::8_0E_11) << 3) << 0x1c) >>
                            0x1f);
  JUTAssertion::setConfirmMessage(this_00,(ulong)"c_xyz.cpp",(char *)0xe9,uVar1 >> 5,true,in_r8);
  mtx::PSVECNormalize(in_r4,&local_28);
  this->x = local_28;
  this->y = local_24;
  this->z = local_20;
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


/* __thiscall cXyz::normZP(void) const */

cXyz * __thiscall cXyz::normZP(cXyz *__return_storage_ptr__,cXyz *this)

{
  cXyz *pcVar1;
  float fVar2;
  cXyz local_18;
  
  fVar2 = mtx::PSVECSquareMag(this);
  if (fVar2 < SComponent::8_0E_11) {
    pcVar1 = &Zero;
    local_18.x = Zero.x;
    local_18.y = Zero.y;
    local_18.z = Zero.z;
  }
  else {
    pcVar1 = (cXyz *)mtx::PSVECNormalize(this,&local_18);
  }
  __return_storage_ptr__->x = local_18.x;
  __return_storage_ptr__->y = local_18.y;
  __return_storage_ptr__->z = local_18.z;
  return pcVar1;
}


/* __thiscall cXyz::normZC(void) const */

cXyz * __thiscall cXyz::normZC(cXyz *__return_storage_ptr__,cXyz *this)

{
  cXyz *pcVar1;
  float fVar2;
  cXyz local_4c;
  cXyz local_40;
  cXyz cStack52;
  cXyz cStack40;
  cXyz *local_1c;
  float local_18;
  float local_14;
  
  fVar2 = mtx::PSVECSquareMag(this);
  if (fVar2 < SComponent::8_0E_11) {
    operator_(&cStack40,this,SComponent::1_25);
    operator_(&cStack52,&cStack40,SComponent::1000000_0);
    normZP(&local_40,&cStack52);
    local_1c = (cXyz *)local_40.x;
    local_18 = local_40.y;
    local_14 = local_40.z;
    local_4c.x = local_40.x;
    local_4c.y = local_40.y;
    local_4c.z = local_40.z;
    pcVar1 = &local_4c;
    fVar2 = mtx::PSVECSquareMag(pcVar1);
    if (fVar2 < SComponent::8_0E_11) {
      local_1c = SComponent::_2247;
      local_18 = DAT_803649bc;
      local_14 = DAT_803649c0;
      pcVar1 = SComponent::_2247;
    }
  }
  else {
    pcVar1 = (cXyz *)mtx::PSVECNormalize(this,&local_1c);
  }
  __return_storage_ptr__->x = (float)local_1c;
  __return_storage_ptr__->y = local_18;
  __return_storage_ptr__->z = local_14;
  return pcVar1;
}


/* __thiscall cXyz::normalize(void) */

void __thiscall cXyz::normalize(cXyz *this)

{
  ulong uVar1;
  cXyz *in_r4;
  float fVar2;
  
  fVar2 = mtx::PSVECSquareMag(in_r4);
  if (fVar2 < SComponent::8_0E_11) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"c_xyz.cpp",0x10b,"isNearZeroSquare() == 0");
    m_Do_printf::OSPanic("c_xyz.cpp",0x10b,"Halt");
  }
  mtx::PSVECNormalize(in_r4,in_r4);
  this->x = in_r4->x;
  this->y = in_r4->y;
  this->z = in_r4->z;
  return;
}


/* __thiscall cXyz::normalizeZP(void) */

void __thiscall cXyz::normalizeZP(cXyz *this)

{
  cXyz *in_r4;
  float fVar1;
  
  fVar1 = mtx::PSVECSquareMag(in_r4);
  if (fVar1 < SComponent::8_0E_11) {
    in_r4->x = Zero.x;
    in_r4->y = Zero.y;
    in_r4->z = Zero.z;
  }
  else {
    mtx::PSVECNormalize(in_r4,in_r4);
  }
  this->x = in_r4->x;
  this->y = in_r4->y;
  this->z = in_r4->z;
  return;
}


/* __thiscall cXyz::normalizeRS(void) */

bool __thiscall cXyz::normalizeRS(cXyz *this)

{
  bool bVar1;
  float fVar2;
  
  fVar2 = mtx::PSVECSquareMag(this);
  bVar1 = SComponent::8_0E_11 <= fVar2;
  if (bVar1) {
    mtx::PSVECNormalize(this,this);
  }
  return bVar1;
}


/* __thiscall cXyz::operator ==(Vec const &) const */

undefined4 __thiscall cXyz::operator___(cXyz *this,Vec *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((this->x == *(float *)param_1) && (this->y == *(float *)(param_1 + 4))) &&
     (this->z == *(float *)(param_1 + 8))) {
    uVar1 = 1;
  }
  return uVar1;
}


/* __thiscall cXyz::operator !=(Vec const &) const */

undefined4 __thiscall cXyz::operator___(cXyz *this,cXyz *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((this->x != param_1->x) || (this->y != param_1->y)) || (this->z != param_1->z)) {
    uVar1 = 1;
  }
  return uVar1;
}


/* __thiscall cXyz::isZero(void) const */

undefined4 __thiscall cXyz::isZero(cXyz *this)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  bVar1 = false;
  if (ABS(this->x) < SComponent::_2357) {
    if (ABS(this->y) < SComponent::_2357) {
      bVar1 = true;
    }
  }
  if ((bVar1) && (ABS(this->z) < SComponent::_2357)) {
    uVar2 = 1;
  }
  return uVar2;
}


namespace SComponent {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __sinit_c_xyz_cpp(void)

{
  ::cXyz::Zero.x = 0_0;
  ::cXyz::Zero.y = 0_0;
  ::cXyz::Zero.z = 0_0;
  Runtime.PPCEABI.H::__register_global_object(&::cXyz::Zero,::cXyz::_cXyz,&_2359);
  ::cXyz::BaseX.x = 1_0;
  ::cXyz::BaseX.y = 0_0;
  ::cXyz::BaseX.z = 0_0;
  Runtime.PPCEABI.H::__register_global_object(&::cXyz::BaseX,::cXyz::_cXyz,&_2360);
  ::cXyz::BaseY.x = 0_0;
  ::cXyz::BaseY.y = 1_0;
  ::cXyz::BaseY.z = 0_0;
  Runtime.PPCEABI.H::__register_global_object(&::cXyz::BaseY,::cXyz::_cXyz,&_2361);
  ::cXyz::BaseZ.x = 0_0;
  ::cXyz::BaseZ.y = 0_0;
  ::cXyz::BaseZ.z = 1_0;
  Runtime.PPCEABI.H::__register_global_object(&::cXyz::BaseZ,::cXyz::_cXyz,&_2362);
  _BaseXY = 1_0;
  DAT_803e81c0 = 1_0;
  DAT_803e81c4 = 0_0;
  Runtime.PPCEABI.H::__register_global_object(&::cXyz::BaseXY,::cXyz::_cXyz,&_2363);
  _BaseXZ = 1_0;
  DAT_803e81d8 = 0_0;
  DAT_803e81dc = 1_0;
  Runtime.PPCEABI.H::__register_global_object(&::cXyz::BaseXZ,::cXyz::_cXyz,&_2364);
  _BaseYZ = 0_0;
  DAT_803e81f0 = 1_0;
  DAT_803e81f4 = 1_0;
  Runtime.PPCEABI.H::__register_global_object(&::cXyz::BaseYZ,::cXyz::_cXyz,&_2365);
  ::cXyz::BaseXYZ.x = 1_0;
  ::cXyz::BaseXYZ.y = 1_0;
  ::cXyz::BaseXYZ.z = 1_0;
  Runtime.PPCEABI.H::__register_global_object(&::cXyz::BaseXYZ,::cXyz::_cXyz,&_2366);
  return;
}

