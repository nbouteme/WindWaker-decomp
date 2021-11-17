#include <JPALoader/JPADynamicsBlock.h>
#include <JKernel/JKRHeap.h>
#include <JPADynamicsBlockArc.h>
#include <JPADynamicsBlock.h>


/* __thiscall JPADynamicsBlockArc::JPADynamicsBlockArc(unsigned char const *) */

void __thiscall JPADynamicsBlockArc::JPADynamicsBlockArc(JPADynamicsBlockArc *this,uchar *param_1)

{
  this->vtbl = &JPADynamicsBlock::__vt;
  this->vtbl = &__vt;
  this->mpData = (JPADynamicsBlockArc__Data *)(param_1 + 0xc);
  return;
}


/* __thiscall JPADynamicsBlock::~JPADynamicsBlock(void) */

void __thiscall JPADynamicsBlock::_JPADynamicsBlock(JPADynamicsBlock *this)

{
  short in_r4;
  
  if ((this != (JPADynamicsBlock *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall JPADynamicsBlockArc::~JPADynamicsBlockArc(void) */

void __thiscall JPADynamicsBlockArc::_JPADynamicsBlockArc(JPADynamicsBlockArc *this)

{
  short in_r4;
  
  if (this != (JPADynamicsBlockArc *)0x0) {
    this->vtbl = &__vt;
    if (this != (JPADynamicsBlockArc *)0x0) {
      this->vtbl = &JPADynamicsBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADynamicsBlockArc::getDataFlag(void) */

uint __thiscall JPADynamicsBlockArc::getDataFlag(JPADynamicsBlockArc *this)

{
  return this->mpData->mFlags;
}


/* __thiscall JPADynamicsBlockArc::getUseKeyFlag(void) */

undefined4 __thiscall JPADynamicsBlockArc::getUseKeyFlag(JPADynamicsBlockArc *this)

{
  return 0;
}


/* __thiscall JPADynamicsBlockArc::getEmitterScl(JGeometry::TVec3<float><float>&) */

void __thiscall JPADynamicsBlockArc::getEmitterScl(JPADynamicsBlockArc *this,TVec3_float_ *param_1)

{
  float fVar1;
  float fVar2;
  JPADynamicsBlockArc__Data *pJVar3;
  
  pJVar3 = this->mpData;
  fVar1 = (pJVar3->mEmitterScl).z;
  fVar2 = (pJVar3->mEmitterScl).y;
  param_1->x = (pJVar3->mEmitterScl).x;
  param_1->y = fVar2;
  param_1->z = fVar1;
  return;
}


/* __thiscall JPADynamicsBlockArc::getEmitterRot(JGeometry::TVec3<short><short>&) */

void __thiscall JPADynamicsBlockArc::getEmitterRot(JPADynamicsBlockArc *this,TVec3_short_ *param_1)

{
  short sVar1;
  short sVar2;
  JPADynamicsBlockArc__Data *pJVar3;
  
  pJVar3 = this->mpData;
  sVar1 = (pJVar3->mEmitterRot).z;
  sVar2 = (pJVar3->mEmitterRot).y;
  param_1->x = (pJVar3->mEmitterRot).x;
  param_1->y = sVar2;
  param_1->z = sVar1;
  return;
}


/* __thiscall JPADynamicsBlockArc::getEmitterTrs(JGeometry::TVec3<float><float>&) */

void __thiscall JPADynamicsBlockArc::getEmitterTrs(JPADynamicsBlockArc *this,TVec3_float_ *param_1)

{
  float fVar1;
  float fVar2;
  JPADynamicsBlockArc__Data *pJVar3;
  
  pJVar3 = this->mpData;
  fVar1 = (pJVar3->mEmitterTrs).z;
  fVar2 = (pJVar3->mEmitterTrs).y;
  param_1->x = (pJVar3->mEmitterTrs).x;
  param_1->y = fVar2;
  param_1->z = fVar1;
  return;
}


/* __thiscall JPADynamicsBlockArc::getEmitterDir(JGeometry::TVec3<float><float>&) */

void __thiscall JPADynamicsBlockArc::getEmitterDir(JPADynamicsBlockArc *this,TVec3_float_ *param_1)

{
  float fVar1;
  float fVar2;
  JPADynamicsBlockArc__Data *pJVar3;
  
  pJVar3 = this->mpData;
  fVar1 = (pJVar3->mEmitterDir).z;
  fVar2 = (pJVar3->mEmitterDir).y;
  param_1->x = (pJVar3->mEmitterDir).x;
  param_1->y = fVar2;
  param_1->z = fVar1;
  return;
}


/* __thiscall JPADynamicsBlockArc::getVolumeType(void) */

uint __thiscall JPADynamicsBlockArc::getVolumeType(JPADynamicsBlockArc *this)

{
  return this->mpData->mFlags >> 8 & 7;
}


/* __thiscall JPADynamicsBlockArc::getVolumeSize(void) */

short __thiscall JPADynamicsBlockArc::getVolumeSize(JPADynamicsBlockArc *this)

{
  return this->mpData->mVolumeSize;
}


/* __thiscall JPADynamicsBlockArc::getVolumeSweep(void) */

double __thiscall JPADynamicsBlockArc::getVolumeSweep(JPADynamicsBlockArc *this)

{
  return (double)this->mpData->mVolumeSweep;
}


/* __thiscall JPADynamicsBlockArc::getVolumeMinRad(void) */

double __thiscall JPADynamicsBlockArc::getVolumeMinRad(JPADynamicsBlockArc *this)

{
  return (double)this->mpData->mVolumeMinRad;
}


/* __thiscall JPADynamicsBlockArc::getDivNumber(void) */

short __thiscall JPADynamicsBlockArc::getDivNumber(JPADynamicsBlockArc *this)

{
  return this->mpData->mDivNumber;
}


/* __thiscall JPADynamicsBlockArc::getRate(void) */

double __thiscall JPADynamicsBlockArc::getRate(JPADynamicsBlockArc *this)

{
  return (double)this->mpData->mRate;
}


/* __thiscall JPADynamicsBlockArc::getRateRndm(void) */

double __thiscall JPADynamicsBlockArc::getRateRndm(JPADynamicsBlockArc *this)

{
  return (double)this->mpData->mRateRndm;
}


/* __thiscall JPADynamicsBlockArc::getRateStep(void) */

byte __thiscall JPADynamicsBlockArc::getRateStep(JPADynamicsBlockArc *this)

{
  return this->mpData->mRateStep;
}


/* __thiscall JPADynamicsBlockArc::getMaxFrame(void) */

int __thiscall JPADynamicsBlockArc::getMaxFrame(JPADynamicsBlockArc *this)

{
  return (int)this->mpData->mMaxFrame;
}


/* __thiscall JPADynamicsBlockArc::getStartFrame(void) */

int __thiscall JPADynamicsBlockArc::getStartFrame(JPADynamicsBlockArc *this)

{
  return (int)this->mpData->mStartFlag;
}


/* __thiscall JPADynamicsBlockArc::getLifeTime(void) */

int __thiscall JPADynamicsBlockArc::getLifeTime(JPADynamicsBlockArc *this)

{
  return (int)this->mpData->mLifeTime;
}


/* __thiscall JPADynamicsBlockArc::getLifeTimeRndm(void) */

double __thiscall JPADynamicsBlockArc::getLifeTimeRndm(JPADynamicsBlockArc *this)

{
  return (double)this->mpData->mLifeTimeRndm;
}


/* __thiscall JPADynamicsBlockArc::getInitVelOmni(void) */

double __thiscall JPADynamicsBlockArc::getInitVelOmni(JPADynamicsBlockArc *this)

{
  return (double)this->mpData->mInitVelOmni;
}


/* __thiscall JPADynamicsBlockArc::getInitVelAxis(void) */

double __thiscall JPADynamicsBlockArc::getInitVelAxis(JPADynamicsBlockArc *this)

{
  return (double)this->mpData->mInitVelAxis;
}


/* __thiscall JPADynamicsBlockArc::getInitVelRndm(void) */

double __thiscall JPADynamicsBlockArc::getInitVelRndm(JPADynamicsBlockArc *this)

{
  return (double)this->mpData->mInitVelRndm;
}


/* __thiscall JPADynamicsBlockArc::getInitVelDir(void) */

double __thiscall JPADynamicsBlockArc::getInitVelDir(JPADynamicsBlockArc *this)

{
  return (double)this->mpData->mInitVelDir;
}


/* __thiscall JPADynamicsBlockArc::getSpread(void) */

double __thiscall JPADynamicsBlockArc::getSpread(JPADynamicsBlockArc *this)

{
  return (double)this->mpData->mSpread;
}


/* __thiscall JPADynamicsBlockArc::getInitVelRatio(void) */

double __thiscall JPADynamicsBlockArc::getInitVelRatio(JPADynamicsBlockArc *this)

{
  return (double)this->mpData->mInitVelRatio;
}


/* __thiscall JPADynamicsBlockArc::getAccel(void) */

double __thiscall JPADynamicsBlockArc::getAccel(JPADynamicsBlockArc *this)

{
  return (double)this->mpData->mAccel;
}


/* __thiscall JPADynamicsBlockArc::getAccelRndm(void) */

double __thiscall JPADynamicsBlockArc::getAccelRndm(JPADynamicsBlockArc *this)

{
  return (double)this->mpData->mAccelRndm;
}


/* __thiscall JPADynamicsBlockArc::getAirResist(void) */

double __thiscall JPADynamicsBlockArc::getAirResist(JPADynamicsBlockArc *this)

{
  return (double)this->mpData->mAirResist;
}


/* __thiscall JPADynamicsBlockArc::getAirResistRndm(void) */

double __thiscall JPADynamicsBlockArc::getAirResistRndm(JPADynamicsBlockArc *this)

{
  return (double)this->mpData->mAirResistRndm;
}


/* __thiscall JPADynamicsBlockArc::getMoment(void) */

double __thiscall JPADynamicsBlockArc::getMoment(JPADynamicsBlockArc *this)

{
  return (double)this->mpData->mMoment;
}


/* __thiscall JPADynamicsBlockArc::getMomentRndm(void) */

double __thiscall JPADynamicsBlockArc::getMomentRndm(JPADynamicsBlockArc *this)

{
  return (double)this->mpData->mMomentRndm;
}

