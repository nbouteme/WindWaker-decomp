#include <JPABase/JPAField.h>
#include <JPABase/JPAField.h>
#include <mtx/mtxvec.h>
#include <mtx/mtx.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JSupport/JSUList.h>
#include <JUtility/JUTAssert.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JPAConvectionField.h>
#include <JPASpinField.h>
#include <JPAVortexField.h>
#include <JPAAirField.h>
#include <JPAFieldManager.h>
#include <JPAMagnetField.h>
#include <JPARandomField.h>
#include <JPAGravityField.h>
#include <JPABaseField.h>
#include <JPAFieldContainer.h>
#include <JPANewtonField.h>
#include <JPADragField.h>

struct JPAFieldContainer JPAFieldManager;

namespace JPAFieldData {
struct JPAEmitterInfo * pEmtrInfo;
}

/* __thiscall JPABaseField::loadFieldData(JPAFieldData *,
                                          JPAFieldBlock *) */

void __thiscall
JPABaseField::loadFieldData(JPABaseField *this,JPAFieldData *pData,JPAFieldBlock *pBlk)

{
  float fVar1;
  byte bVar3;
  ushort uVar2;
  double dVar4;
  
  bVar3 = (**(code **)(*(int *)pBlk + 0xc))(pBlk);
  pData->mType = bVar3;
  bVar3 = (**(code **)(*(int *)pBlk + 0x10))(pBlk);
  pData->mID = bVar3;
  bVar3 = (**(code **)(*(int *)pBlk + 0x14))(pBlk);
  pData->mVelType = bVar3;
  bVar3 = (**(code **)(*(int *)pBlk + 0x18))(pBlk);
  pData->mCycle = bVar3;
  uVar2 = (**(code **)(*(int *)pBlk + 0x1c))(pBlk);
  pData->mSttFlag = uVar2;
  dVar4 = (double)(**(code **)(*(int *)pBlk + 0x28))(pBlk);
  pData->mMag = (float)dVar4;
  dVar4 = (double)(**(code **)(*(int *)pBlk + 0x2c))(pBlk);
  pData->mMagRndm = (float)dVar4;
  dVar4 = (double)(**(code **)(*(int *)pBlk + 0x30))(pBlk);
  pData->mMaxDist = (float)dVar4;
  (**(code **)(*(int *)pBlk + 0x20))(pBlk,&pData->mPos);
  (**(code **)(*(int *)pBlk + 0x24))(pBlk,&pData->mDir);
  dVar4 = (double)(**(code **)(*(int *)pBlk + 0x34))(pBlk);
  pData->mVal1 = (float)dVar4;
  dVar4 = (double)(**(code **)(*(int *)pBlk + 0x38))(pBlk);
  pData->mVal2 = (float)dVar4;
  dVar4 = (double)(**(code **)(*(int *)pBlk + 0x3c))(pBlk);
  pData->mVal3 = (float)dVar4;
  dVar4 = (double)(**(code **)(*(int *)pBlk + 0x40))(pBlk);
  pData->mFadeIn = (float)dVar4;
  dVar4 = (double)(**(code **)(*(int *)pBlk + 0x44))(pBlk);
  pData->mFadeOut = (float)dVar4;
  dVar4 = (double)(**(code **)(*(int *)pBlk + 0x48))(pBlk);
  pData->mEnTime = (float)dVar4;
  dVar4 = (double)(**(code **)(*(int *)pBlk + 0x4c))(pBlk);
  pData->mDisTime = (float)dVar4;
  if ((pData->mSttFlag & 0x10) == 0) {
    pData->mDisTime = JPABase::_2449;
  }
  fVar1 = JPABase::_2450;
  (pData->mVel).z = JPABase::_2450;
  (pData->mVel).y = fVar1;
  (pData->mVel).x = fVar1;
  return;
}


/* WARNING: Removing unreachable block (ram,0x8025a15c) */
/* __thiscall JPABaseField::calcVel(JPAFieldData *,
                                    JPABaseParticle *) */

void __thiscall
JPABaseField::calcVel(JPABaseField *this,JPAFieldData *pFieldData,JPABaseParticle *pPtcl)

{
  byte bVar1;
  double dVar2;
  cXyz ret;
  
  ret.x = (pFieldData->mVel).x;
  ret.y = (pFieldData->mVel).y;
  ret.z = (pFieldData->mVel).z;
  if ((pPtcl->mFlags & 4) == 0) {
    dVar2 = (double)calcFadeAffect(this,pFieldData,pPtcl->mCurNormTime);
    ret.x = (float)((double)ret.x * dVar2);
    ret.y = (float)((double)ret.y * dVar2);
    ret.z = (float)((double)ret.z * dVar2);
  }
  bVar1 = pFieldData->mVelType;
  if (bVar1 == 1) {
    (pPtcl->mBaseVel).x = (pPtcl->mBaseVel).x + ret.x;
    (pPtcl->mBaseVel).y = (pPtcl->mBaseVel).y + ret.y;
    (pPtcl->mBaseVel).z = (pPtcl->mBaseVel).z + ret.z;
  }
  else {
    if (bVar1 == 0) {
      (pPtcl->mFieldAccel).x = (pPtcl->mFieldAccel).x + ret.x;
      (pPtcl->mFieldAccel).y = (pPtcl->mFieldAccel).y + ret.y;
      (pPtcl->mFieldAccel).z = (pPtcl->mFieldAccel).z + ret.z;
    }
    else {
      if (bVar1 < 3) {
        (pPtcl->mFieldVel).x = (pPtcl->mFieldVel).x + ret.x;
        (pPtcl->mFieldVel).y = (pPtcl->mFieldVel).y + ret.y;
        (pPtcl->mFieldVel).z = (pPtcl->mFieldVel).z + ret.z;
      }
    }
  }
  return;
}


/* __thiscall JPABaseField::calcFadeAffect(JPAFieldData *,
                                           float) */

double __thiscall JPABaseField::calcFadeAffect(JPABaseField *this,JPAFieldData *pData,float time)

{
  ushort uVar1;
  double dVar2;
  
  dVar2 = (double)JPABase::_2449;
  uVar1 = pData->mSttFlag;
  if ((((uVar1 & 8) != 0) && (time < pData->mEnTime)) ||
     (((uVar1 & 0x10) != 0 && (pData->mDisTime <= time)))) {
    dVar2 = (double)JPABase::_2450;
  }
  else {
    if (((uVar1 & 0x40) != 0) && (pData->mFadeOut <= time)) {
      return (double)(pData->mFadeOutRate * (pData->mDisTime - time));
    }
    if (((uVar1 & 0x20) != 0) && (time < pData->mFadeIn)) {
      dVar2 = (double)(pData->mFadeInRate * (time - pData->mEnTime));
    }
  }
  return dVar2;
}


/* __thiscall JPABaseField::preCalc(JPAFieldData *) */

void __thiscall JPABaseField::preCalc(JPABaseField *this,JPAFieldData *param_1)

{
  *(float *)&param_1->field_0x48 = param_1->mMaxDist * param_1->mMaxDist;
  param_1->mFadeOutRate = param_1->mDisTime - param_1->mFadeOut;
  if (JPABase::_2450 == param_1->mFadeOutRate) {
    param_1->mFadeOutRate = JPABase::_2449;
  }
  else {
    param_1->mFadeOutRate = JPABase::_2449 / param_1->mFadeOutRate;
  }
  param_1->mFadeInRate = param_1->mFadeIn - param_1->mEnTime;
  if (JPABase::_2450 == param_1->mFadeInRate) {
    param_1->mFadeInRate = JPABase::_2449;
    return;
  }
  param_1->mFadeInRate = JPABase::_2449 / param_1->mFadeInRate;
  return;
}


/* __thiscall JPABaseField::isItinRange(JPAFieldData *,
                                        float) */

uint __thiscall JPABaseField::isItinRange(JPABaseField *this,JPAFieldData *param_1,float param_2)

{
  return ((uint)(byte)((param_2 < *(float *)&param_1->field_0x48) << 3) << 0x1c) >> 0x1f;
}


/* __thiscall JPAGravityField::preCalc(JPAFieldData *) */

void __thiscall JPAGravityField::preCalc(JPAGravityField *this,JPAFieldData *param_1)

{
  float fVar1;
  cXyz local_18;
  
  JPABaseField::preCalc((JPABaseField *)this,param_1);
  if ((param_1->mSttFlag & 2) == 0) {
    mtx::PSMTXMultVec(&JPAFieldData::pEmtrInfo->mGlobalRotation,&param_1->mDir,&local_18);
    fVar1 = param_1->mMag;
    (param_1->mVel).x = local_18.x * fVar1;
    (param_1->mVel).y = local_18.y * fVar1;
    (param_1->mVel).z = local_18.z * fVar1;
  }
  else {
    fVar1 = param_1->mMag;
    (param_1->mVel).x = (param_1->mDir).x * fVar1;
    (param_1->mVel).y = (param_1->mDir).y * fVar1;
    (param_1->mVel).z = (param_1->mDir).z * fVar1;
  }
  return;
}


/* __thiscall JPAGravityField::calc(JPAFieldData *,
                                    JPABaseParticle *) */

void __thiscall
JPAGravityField::calc(JPAGravityField *this,JPAFieldData *param_1,JPABaseParticle *param_2)

{
  JPABaseField::calcVel((JPABaseField *)this,param_1,param_2);
  return;
}


/* __thiscall JPAAirField::preCalc(JPAFieldData *) */

void __thiscall JPAAirField::preCalc(JPAAirField *this,JPAFieldData *param_1)

{
  float fVar1;
  
  JPABaseField::preCalc((JPABaseField *)this,param_1);
  if ((param_1->mSttFlag & 2) == 0) {
    mtx::PSMTXMultVec(&JPAFieldData::pEmtrInfo->mGlobalRotation,&param_1->mDir,&param_1->mAirDir);
  }
  else {
    (param_1->mAirDir).x = (param_1->mDir).x;
    (param_1->mAirDir).y = (param_1->mDir).y;
    (param_1->mAirDir).z = (param_1->mDir).z;
  }
  fVar1 = param_1->mMag;
  (param_1->mVel).x = (param_1->mAirDir).x * fVar1;
  (param_1->mVel).y = (param_1->mAirDir).y * fVar1;
  (param_1->mVel).z = (param_1->mAirDir).z * fVar1;
  if ((param_1->mSttFlag & 1) != 0) {
    param_1->mAirMinDist =
         JKernel::JMath::jmaCosTable
         [(int)((int)(JPABase::_2556 * param_1->mVal1) & 0xffffU) >>
          (JKernel::JMath::jmaSinShift & 0x3f)];
    if ((param_1->mSttFlag & 2) == 0) {
      mtx::PSMTXMultVec(&JPAFieldData::pEmtrInfo->mGlobalRotation,&param_1->mAirPos,&param_1->mPos);
    }
    else {
      (param_1->mAirPos).x = (param_1->mPos).x;
      (param_1->mAirPos).y = (param_1->mPos).y;
      (param_1->mAirPos).z = (param_1->mPos).z;
    }
  }
  return;
}


/* __thiscall JPAAirField::calc(JPAFieldData *,
                                JPABaseParticle *) */

void __thiscall JPAAirField::calc(JPAAirField *this,JPAFieldData *pData,JPABaseParticle *pPtcl)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  if ((pData->mSttFlag & 1) == 0) {
    JPABaseField::calcVel((JPABaseField *)this,pData,pPtcl);
  }
  else {
    if ((pData->mSttFlag & 2) == 0) {
      fVar1 = (pPtcl->mLocalPosition).x - (pData->mAirPos).x;
      fVar2 = (pPtcl->mLocalPosition).y - (pData->mAirPos).y;
      fVar3 = (pPtcl->mLocalPosition).z - (pData->mAirPos).z;
    }
    else {
      fVar1 = (pPtcl->mPosition).x - (pData->mAirPos).x;
      fVar2 = (pPtcl->mPosition).y - (pData->mAirPos).y;
      fVar3 = (pPtcl->mPosition).z - (pData->mAirPos).z;
    }
    fVar4 = fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2;
    if (JPABase::_2623 < fVar4) {
      if (JPABase::_2450 < fVar4) {
        fVar5 = 1.0 / SQRT(fVar4);
        fVar4 = JPABase::_2624 * fVar5 * (JPABase::_2625 - fVar4 * fVar5 * fVar5);
      }
      fVar1 = fVar1 * fVar4;
      fVar2 = fVar2 * fVar4;
      fVar3 = fVar3 * fVar4;
    }
    if (pData->mAirMinDist <=
        (pData->mAirDir).z * fVar3 + (pData->mAirDir).x * fVar1 + (pData->mAirDir).y * fVar2) {
      JPABaseField::calcVel((JPABaseField *)this,pData,pPtcl);
    }
  }
  if ((pData->mSttFlag & 4) != 0) {
    fVar1 = (pPtcl->mBaseVel).z;
    fVar2 = (pPtcl->mBaseVel).x;
    fVar3 = (pPtcl->mBaseVel).y;
    fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
    if (JPABase::_2450 < fVar1) {
      fVar2 = 1.0 / SQRT(fVar1);
      fVar1 = fVar1 * JPABase::_2624 * fVar2 * (JPABase::_2625 - fVar1 * fVar2 * fVar2);
    }
    if (pData->mMagRndm < fVar1) {
      fVar1 = pData->mMagRndm / fVar1;
      (pPtcl->mBaseVel).x = (pPtcl->mBaseVel).x * fVar1;
      (pPtcl->mBaseVel).y = (pPtcl->mBaseVel).y * fVar1;
      (pPtcl->mBaseVel).z = (pPtcl->mBaseVel).z * fVar1;
    }
  }
  return;
}


/* __thiscall JPAMagnetField::preCalc(JPAFieldData *) */

void __thiscall JPAMagnetField::preCalc(JPAMagnetField *this,JPAFieldData *param_1)

{
  JPAEmitterInfo *pJVar1;
  
  JPABaseField::preCalc((JPABaseField *)this,param_1);
  pJVar1 = JPAFieldData::pEmtrInfo;
  if ((param_1->mSttFlag & 2) == 0) {
    (param_1->mAirPos).x = (param_1->mPos).x - (JPAFieldData::pEmtrInfo->mEmitterTranslation).x;
    (param_1->mAirPos).y = (param_1->mPos).y - (pJVar1->mEmitterTranslation).y;
    (param_1->mAirPos).z = (param_1->mPos).z - (pJVar1->mEmitterTranslation).z;
    mtx::PSMTXMultVec(&JPAFieldData::pEmtrInfo->mGlobalRotation,&param_1->mAirPos,&param_1->mAirPos)
    ;
  }
  else {
    (param_1->mAirPos).x = (param_1->mPos).x;
    (param_1->mAirPos).y = (param_1->mPos).y;
    (param_1->mAirPos).z = (param_1->mPos).z;
  }
  return;
}


/* __thiscall JPAMagnetField::calc(JPAFieldData *,
                                   JPABaseParticle *) */

void __thiscall
JPAMagnetField::calc(JPAMagnetField *this,JPAFieldData *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  if ((param_1->mSttFlag & 2) == 0) {
    (param_1->mVel).x = (param_1->mAirPos).x - (param_2->mLocalPosition).x;
    (param_1->mVel).y = (param_1->mAirPos).y - (param_2->mLocalPosition).y;
    (param_1->mVel).z = (param_1->mAirPos).z - (param_2->mLocalPosition).z;
  }
  else {
    (param_1->mVel).x = (param_1->mAirPos).x - (param_2->mPosition).x;
    (param_1->mVel).y = (param_1->mAirPos).y - (param_2->mPosition).y;
    (param_1->mVel).z = (param_1->mAirPos).z - (param_2->mPosition).z;
  }
  fVar1 = (param_1->mVel).z;
  fVar2 = (param_1->mVel).x;
  fVar3 = (param_1->mVel).y;
  fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  if (JPABase::_2623 < fVar1) {
    if (JPABase::_2450 < fVar1) {
      fVar2 = 1.0 / SQRT(fVar1);
      fVar1 = JPABase::_2624 * fVar2 * (JPABase::_2625 - fVar1 * fVar2 * fVar2);
    }
    fVar1 = fVar1 * param_1->mMag;
    (param_1->mVel).x = (param_1->mVel).x * fVar1;
    (param_1->mVel).y = (param_1->mVel).y * fVar1;
    (param_1->mVel).z = (param_1->mVel).z * fVar1;
  }
  JPABaseField::calcVel((JPABaseField *)this,param_1,param_2);
  return;
}


/* __thiscall JPANewtonField::preCalc(JPAFieldData *) */

void __thiscall JPANewtonField::preCalc(JPANewtonField *this,JPAFieldData *param_1)

{
  JPAEmitterInfo *pJVar1;
  
  JPABaseField::preCalc((JPABaseField *)this,param_1);
  pJVar1 = JPAFieldData::pEmtrInfo;
  if ((param_1->mSttFlag & 2) == 0) {
    (param_1->mAirPos).x = (param_1->mPos).x - (JPAFieldData::pEmtrInfo->mEmitterTranslation).x;
    (param_1->mAirPos).y = (param_1->mPos).y - (pJVar1->mEmitterTranslation).y;
    (param_1->mAirPos).z = (param_1->mPos).z - (pJVar1->mEmitterTranslation).z;
    mtx::PSMTXMultVec(&JPAFieldData::pEmtrInfo->mGlobalRotation,&param_1->mAirPos,&param_1->mAirPos)
    ;
  }
  else {
    (param_1->mAirPos).x = (param_1->mPos).x;
    (param_1->mAirPos).y = (param_1->mPos).y;
    (param_1->mAirPos).z = (param_1->mPos).z;
  }
  param_1->mVal2 = param_1->mVal1 * param_1->mVal1;
  return;
}


/* __thiscall JPANewtonField::calc(JPAFieldData *,
                                   JPABaseParticle *) */

void __thiscall
JPANewtonField::calc(JPANewtonField *this,JPAFieldData *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  if ((param_1->mSttFlag & 2) == 0) {
    (param_1->mVel).x = (param_1->mAirPos).x - (param_2->mLocalPosition).x;
    (param_1->mVel).y = (param_1->mAirPos).y - (param_2->mLocalPosition).y;
    (param_1->mVel).z = (param_1->mAirPos).z - (param_2->mLocalPosition).z;
  }
  else {
    (param_1->mVel).x = (param_1->mAirPos).x - (param_2->mPosition).x;
    (param_1->mVel).y = (param_1->mAirPos).y - (param_2->mPosition).y;
    (param_1->mVel).z = (param_1->mAirPos).z - (param_2->mPosition).z;
  }
  if ((param_1->mSttFlag & 0x100) == 0) {
    fVar1 = (param_1->mVel).z;
    fVar2 = (param_1->mVel).x;
    fVar3 = (param_1->mVel).y;
    fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
    if (fVar1 <= param_1->mVal2) {
      if (JPABase::_2623 < fVar1) {
        if (JPABase::_2450 < fVar1) {
          fVar2 = 1.0 / SQRT(fVar1);
          fVar1 = JPABase::_2624 * fVar2 * (JPABase::_2625 - fVar1 * fVar2 * fVar2);
        }
        fVar1 = fVar1 * JPABase::_2750 * param_1->mMag;
        (param_1->mVel).x = (param_1->mVel).x * fVar1;
        (param_1->mVel).y = (param_1->mVel).y * fVar1;
        (param_1->mVel).z = (param_1->mVel).z * fVar1;
      }
    }
    else {
      fVar2 = (JPABase::_2750 * param_1->mMag * param_1->mVal2) / fVar1;
      if (JPABase::_2623 < fVar1) {
        if (JPABase::_2450 < fVar1) {
          fVar3 = 1.0 / SQRT(fVar1);
          fVar1 = JPABase::_2624 * fVar3 * (JPABase::_2625 - fVar1 * fVar3 * fVar3);
        }
        fVar1 = fVar1 * fVar2;
        (param_1->mVel).x = (param_1->mVel).x * fVar1;
        (param_1->mVel).y = (param_1->mVel).y * fVar1;
        (param_1->mVel).z = (param_1->mVel).z * fVar1;
      }
    }
  }
  else {
    fVar1 = (param_1->mVel).z;
    fVar2 = (param_1->mVel).x;
    fVar3 = (param_1->mVel).y;
    fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
    if (JPABase::_2623 < fVar1) {
      if (JPABase::_2450 < fVar1) {
        fVar2 = 1.0 / SQRT(fVar1);
        fVar1 = JPABase::_2624 * fVar2 * (JPABase::_2625 - fVar1 * fVar2 * fVar2);
      }
      fVar1 = fVar1 * param_1->mMag;
      (param_1->mVel).x = (param_1->mVel).x * fVar1;
      (param_1->mVel).y = (param_1->mVel).y * fVar1;
      (param_1->mVel).z = (param_1->mVel).z * fVar1;
    }
  }
  JPABaseField::calcVel((JPABaseField *)this,param_1,param_2);
  return;
}


/* __thiscall JPAVortexField::preCalc(JPAFieldData *) */

void __thiscall JPAVortexField::preCalc(JPAVortexField *this,JPAFieldData *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  JPABaseField::preCalc((JPABaseField *)this,param_1);
  mtx::PSMTXMultVec(&JPAFieldData::pEmtrInfo->mEmitterGlobalRot,&param_1->mDir,&param_1->mAirPos);
  fVar1 = (param_1->mAirPos).z;
  fVar2 = (param_1->mAirPos).x;
  fVar3 = (param_1->mAirPos).y;
  fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  if (JPABase::_2623 < fVar1) {
    if (JPABase::_2450 < fVar1) {
      fVar2 = 1.0 / SQRT(fVar1);
      fVar1 = JPABase::_2624 * fVar2 * (JPABase::_2625 - fVar1 * fVar2 * fVar2);
    }
    (param_1->mAirPos).x = (param_1->mAirPos).x * fVar1;
    (param_1->mAirPos).y = (param_1->mAirPos).y * fVar1;
    (param_1->mAirPos).z = (param_1->mAirPos).z * fVar1;
  }
  fVar1 = (param_1->mPos).z;
  param_1->mVal1 = fVar1 * fVar1;
  param_1->mVal2 = JPABase::_2449 / param_1->mVal1;
  return;
}


/* __thiscall JPAVortexField::calc(JPAFieldData *,
                                   JPABaseParticle *) */

void __thiscall
JPAVortexField::calc(JPAVortexField *this,JPAFieldData *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar1 = (param_1->mAirPos).z;
  fVar2 = (param_2->mLocalPosition).z;
  fVar3 = (param_1->mAirPos).x;
  fVar4 = (param_2->mLocalPosition).x;
  fVar5 = (param_1->mAirPos).y;
  fVar6 = (param_2->mLocalPosition).y;
  fVar7 = fVar1 * fVar2 + fVar3 * fVar4 + fVar5 * fVar6;
  fVar4 = fVar4 - fVar3 * fVar7;
  fVar6 = fVar6 - fVar5 * fVar7;
  fVar2 = fVar2 - fVar1 * fVar7;
  fVar1 = fVar2 * fVar2 + fVar4 * fVar4 + fVar6 * fVar6;
  fVar3 = fVar1;
  if (param_1->mVal1 < fVar1) {
    fVar3 = param_1->mVal1;
  }
  fVar3 = fVar3 * param_1->mVal2;
  fVar3 = (JPABase::_2449 - fVar3) * param_1->mMag + fVar3 * param_1->mMagRndm;
  if (JPABase::_2623 < fVar1) {
    if (JPABase::_2450 < fVar1) {
      fVar5 = 1.0 / SQRT(fVar1);
      fVar1 = JPABase::_2624 * fVar5 * (JPABase::_2625 - fVar1 * fVar5 * fVar5);
    }
    fVar4 = fVar4 * fVar1;
    fVar6 = fVar6 * fVar1;
    fVar2 = fVar2 * fVar1;
  }
  fVar1 = (param_1->mAirPos).y;
  fVar5 = (param_1->mAirPos).x;
  fVar7 = (param_1->mAirPos).z;
  (param_1->mVel).x = fVar6 * fVar7 - fVar2 * fVar1;
  (param_1->mVel).y = fVar2 * fVar5 - fVar4 * fVar7;
  (param_1->mVel).z = fVar4 * fVar1 - fVar6 * fVar5;
  (param_1->mVel).x = (param_1->mVel).x * fVar3;
  (param_1->mVel).y = (param_1->mVel).y * fVar3;
  (param_1->mVel).z = (param_1->mVel).z * fVar3;
  JPABaseField::calcVel((JPABaseField *)this,param_1,param_2);
  return;
}


/* __thiscall JPAConvectionField::preCalc(JPAFieldData *) */

void __thiscall JPAConvectionField::preCalc(JPAConvectionField *this,JPAFieldData *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  cXyz local_18;
  
  JPABaseField::preCalc((JPABaseField *)this,param_1);
  fVar1 = (param_1->mPos).x;
  fVar2 = (param_1->mDir).y;
  fVar3 = (param_1->mPos).y;
  fVar4 = (param_1->mDir).x;
  local_18.z = fVar1 * fVar2 - fVar3 * fVar4;
  fVar5 = (param_1->mPos).z;
  fVar6 = (param_1->mDir).z;
  local_18.y = fVar5 * fVar4 - fVar1 * fVar6;
  local_18.x = fVar3 * fVar6 - fVar5 * fVar2;
  (param_1->mPos).x = local_18.y * fVar6 - local_18.z * fVar2;
  (param_1->mPos).y = local_18.z * fVar4 - local_18.x * fVar6;
  (param_1->mPos).z = local_18.x * fVar2 - local_18.y * fVar4;
  fVar1 = (param_1->mPos).z;
  fVar2 = (param_1->mPos).x;
  fVar3 = (param_1->mPos).y;
  fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  if (JPABase::_2623 < fVar1) {
    if (JPABase::_2450 < fVar1) {
      fVar2 = 1.0 / SQRT(fVar1);
      fVar1 = JPABase::_2624 * fVar2 * (JPABase::_2625 - fVar1 * fVar2 * fVar2);
    }
    (param_1->mPos).x = (param_1->mPos).x * fVar1;
    (param_1->mPos).y = (param_1->mPos).y * fVar1;
    (param_1->mPos).z = (param_1->mPos).z * fVar1;
  }
  mtx::PSMTXMultVec(&JPAFieldData::pEmtrInfo->mEmitterGlobalRot,&param_1->mPos,&param_1->mAirPos);
  mtx::PSMTXMultVec(&JPAFieldData::pEmtrInfo->mEmitterGlobalRot,&param_1->mDir,
                    (cXyz *)&param_1->mAirMinDist);
  mtx::PSMTXMultVec(&JPAFieldData::pEmtrInfo->mEmitterGlobalRot,&local_18,&param_1->mAirDir);
  fVar1 = (param_1->mAirPos).z;
  fVar2 = (param_1->mAirPos).x;
  fVar3 = (param_1->mAirPos).y;
  fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  if (JPABase::_2623 < fVar1) {
    if (JPABase::_2450 < fVar1) {
      fVar2 = 1.0 / SQRT(fVar1);
      fVar1 = JPABase::_2624 * fVar2 * (JPABase::_2625 - fVar1 * fVar2 * fVar2);
    }
    (param_1->mAirPos).x = (param_1->mAirPos).x * fVar1;
    (param_1->mAirPos).y = (param_1->mAirPos).y * fVar1;
    (param_1->mAirPos).z = (param_1->mAirPos).z * fVar1;
  }
  fVar1 = *(float *)&param_1->field_0x38 * *(float *)&param_1->field_0x38 +
          param_1->mAirMinDist * param_1->mAirMinDist +
          *(float *)&param_1->field_0x34 * *(float *)&param_1->field_0x34;
  if (JPABase::_2623 < fVar1) {
    if (JPABase::_2450 < fVar1) {
      fVar2 = 1.0 / SQRT(fVar1);
      fVar1 = JPABase::_2624 * fVar2 * (JPABase::_2625 - fVar1 * fVar2 * fVar2);
    }
    param_1->mAirMinDist = param_1->mAirMinDist * fVar1;
    *(float *)&param_1->field_0x34 = *(float *)&param_1->field_0x34 * fVar1;
    *(float *)&param_1->field_0x38 = *(float *)&param_1->field_0x38 * fVar1;
  }
  fVar1 = (param_1->mAirDir).z;
  fVar2 = (param_1->mAirDir).x;
  fVar3 = (param_1->mAirDir).y;
  fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  if (JPABase::_2623 < fVar1) {
    if (JPABase::_2450 < fVar1) {
      fVar2 = 1.0 / SQRT(fVar1);
      fVar1 = JPABase::_2624 * fVar2 * (JPABase::_2625 - fVar1 * fVar2 * fVar2);
    }
    (param_1->mAirDir).x = (param_1->mAirDir).x * fVar1;
    (param_1->mAirDir).y = (param_1->mAirDir).y * fVar1;
    (param_1->mAirDir).z = (param_1->mAirDir).z * fVar1;
  }
  return;
}


/* __thiscall JPAConvectionField::calc(JPAFieldData *,
                                       JPABaseParticle *) */

void __thiscall
JPAConvectionField::calc(JPAConvectionField *this,JPAFieldData *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  fVar1 = (param_1->mAirPos).z;
  fVar2 = (param_2->mLocalPosition).z;
  fVar3 = (param_1->mAirPos).x;
  fVar4 = (param_2->mLocalPosition).x;
  fVar5 = (param_1->mAirPos).y;
  fVar6 = (param_2->mLocalPosition).y;
  fVar10 = fVar1 * fVar2 + fVar3 * fVar4 + fVar5 * fVar6;
  fVar7 = (param_1->mAirDir).z;
  fVar8 = (param_1->mAirDir).x;
  fVar9 = (param_1->mAirDir).y;
  fVar4 = fVar7 * fVar2 + fVar8 * fVar4 + fVar9 * fVar6;
  fVar2 = fVar3 * fVar10 + fVar8 * fVar4;
  fVar3 = fVar5 * fVar10 + fVar9 * fVar4;
  fVar1 = fVar1 * fVar10 + fVar7 * fVar4;
  fVar4 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  fVar5 = JPABase::_2450;
  fVar6 = JPABase::_2450;
  fVar7 = JPABase::_2450;
  if (JPABase::_2623 < fVar4) {
    if (JPABase::_2450 < fVar4) {
      fVar5 = 1.0 / SQRT(fVar4);
      fVar4 = JPABase::_2624 * fVar5 * (JPABase::_2625 - fVar4 * fVar5 * fVar5);
    }
    fVar4 = fVar4 * param_1->mVal1;
    fVar5 = fVar1 * fVar4;
    fVar6 = fVar3 * fVar4;
    fVar7 = fVar2 * fVar4;
  }
  fVar9 = (param_2->mLocalPosition).x - fVar7;
  fVar8 = (param_2->mLocalPosition).y - fVar6;
  fVar4 = (param_2->mLocalPosition).z - fVar5;
  fVar1 = *(float *)&param_1->field_0x34 * fVar5 - *(float *)&param_1->field_0x38 * fVar6;
  fVar2 = *(float *)&param_1->field_0x38 * fVar7 - param_1->mAirMinDist * fVar5;
  fVar3 = param_1->mAirMinDist * fVar6 - *(float *)&param_1->field_0x34 * fVar7;
  (param_1->mVel).x = fVar2 * fVar4 - fVar3 * fVar8;
  (param_1->mVel).y = fVar3 * fVar9 - fVar1 * fVar4;
  (param_1->mVel).z = fVar1 * fVar8 - fVar2 * fVar9;
  fVar1 = (param_1->mVel).z;
  fVar2 = (param_1->mVel).x;
  fVar3 = (param_1->mVel).y;
  fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  if (JPABase::_2623 < fVar1) {
    if (JPABase::_2450 < fVar1) {
      fVar2 = 1.0 / SQRT(fVar1);
      fVar1 = JPABase::_2624 * fVar2 * (JPABase::_2625 - fVar1 * fVar2 * fVar2);
    }
    fVar1 = fVar1 * param_1->mMag;
    (param_1->mVel).x = (param_1->mVel).x * fVar1;
    (param_1->mVel).y = (param_1->mVel).y * fVar1;
    (param_1->mVel).z = (param_1->mVel).z * fVar1;
  }
  if (JPABase::_2450 != param_1->mVal2) {
    fVar1 = fVar4 * fVar4 + fVar9 * fVar9 + fVar8 * fVar8;
    if (JPABase::_2623 < fVar1) {
      if (JPABase::_2450 < fVar1) {
        fVar2 = 1.0 / SQRT(fVar1);
        fVar1 = JPABase::_2624 * fVar2 * (JPABase::_2625 - fVar1 * fVar2 * fVar2);
      }
      fVar1 = fVar1 * param_1->mVal2;
      fVar9 = fVar9 * fVar1;
      fVar8 = fVar8 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    (param_1->mVel).x = (param_1->mVel).x + fVar9;
    (param_1->mVel).y = (param_1->mVel).y + fVar8;
    (param_1->mVel).z = (param_1->mVel).z + fVar4;
  }
  JPABaseField::calcVel((JPABaseField *)this,param_1,param_2);
  return;
}


/* __thiscall JPARandomField::calc(JPAFieldData *,
                                   JPABaseParticle *) */

void __thiscall
JPARandomField::calc(JPARandomField *this,JPAFieldData *param_1,JPABaseParticle *param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  JPABaseEmitter *pJVar6;
  
  iVar1 = (int)param_2->mCurFrame;
  if (iVar1 != 0) {
    uVar5 = (uint)param_1->mCycle;
    if (uVar5 == 0) {
      return;
    }
    if (iVar1 != (iVar1 / (int)uVar5) * uVar5) {
      return;
    }
  }
  pJVar6 = JPAFieldData::pEmtrInfo->mpCurEmitter;
  (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
  fVar4 = JPABase::_2624;
  fVar3 = JPABase::_2449;
  fVar2 = ((float)((pJVar6->mRandomSeed).v >> 9 | 0x3f800000) - JPABase::_2449) - JPABase::_2624;
  pJVar6 = JPAFieldData::pEmtrInfo->mpCurEmitter;
  (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
  uVar5 = (pJVar6->mRandomSeed).v;
  pJVar6 = JPAFieldData::pEmtrInfo->mpCurEmitter;
  (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
  (param_1->mVel).x = ((float)((pJVar6->mRandomSeed).v >> 9 | 0x3f800000) - fVar3) - fVar4;
  (param_1->mVel).y = ((float)(uVar5 >> 9 | 0x3f800000) - fVar3) - fVar4;
  (param_1->mVel).z = fVar2;
  fVar2 = param_1->mMag;
  (param_1->mVel).x = (param_1->mVel).x * fVar2;
  (param_1->mVel).y = (param_1->mVel).y * fVar2;
  (param_1->mVel).z = (param_1->mVel).z * fVar2;
  JPABaseField::calcVel((JPABaseField *)this,param_1,param_2);
  return;
}


/* __thiscall JPADragField::init(JPAFieldData *,
                                 JPABaseParticle *) */

int __thiscall JPADragField::init(JPADragField *this,EVP_PKEY_CTX *ctx)

{
  float fVar1;
  int iVar2;
  int in_r5;
  JPABaseEmitter *pJVar3;
  
  pJVar3 = JPAFieldData::pEmtrInfo->mpCurEmitter;
  iVar2 = (pJVar3->mRandomSeed).v * 0x19660d;
  (pJVar3->mRandomSeed).v = iVar2 + 0x3c6ef35f;
  fVar1 = JPABase::_2449;
  *(float *)(in_r5 + 0x84) =
       *(float *)(ctx + 0x6c) +
       *(float *)(ctx + 0x70) *
       (((float)((pJVar3->mRandomSeed).v >> 9 | 0x3f800000) - JPABase::_2449) - JPABase::_2624);
  if (fVar1 < *(float *)(in_r5 + 0x84)) {
    *(float *)(in_r5 + 0x84) = fVar1;
  }
  return iVar2 + 0x3c6f0000;
}


/* __thiscall JPADragField::calc(JPAFieldData *,
                                 JPABaseParticle *) */

void __thiscall
JPADragField::calc(JPADragField *this,JPAFieldData *param_1,JPABaseParticle *param_2)

{
  double dVar1;
  
  if ((param_2->mFlags & 4) == 0) {
    dVar1 = (double)JPABaseField::calcFadeAffect((JPABaseField *)this,param_1,param_2->mCurNormTime)
    ;
    param_2->mDrag =
         param_2->mDrag *
         (JPABase::_2449 - (float)(dVar1 * (double)(JPABase::_2449 - param_2->mFieldDrag)));
  }
  else {
    param_2->mDrag = param_2->mDrag * param_2->mFieldDrag;
  }
  return;
}


/* __thiscall JPASpinField::preCalc(JPAFieldData *) */

void __thiscall JPASpinField::preCalc(JPASpinField *this,JPAFieldData *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float local_38;
  float local_34;
  float local_30;
  float local_28;
  undefined4 local_24;
  float local_20;
  float local_18;
  undefined4 local_14;
  float local_10;
  
  JPABaseField::preCalc((JPABaseField *)this,param_1);
  mtx::PSMTXMultVec(&JPAFieldData::pEmtrInfo->mEmitterGlobalRot,&param_1->mDir,&param_1->mPos);
  fVar1 = (param_1->mPos).z;
  fVar2 = (param_1->mPos).x;
  fVar3 = (param_1->mPos).y;
  fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  if (JPABase::_2623 < fVar1) {
    if (JPABase::_2450 < fVar1) {
      fVar2 = 1.0 / SQRT(fVar1);
      fVar1 = JPABase::_2624 * fVar2 * (JPABase::_2625 - fVar1 * fVar2 * fVar2);
    }
    (param_1->mPos).x = (param_1->mPos).x * fVar1;
    (param_1->mPos).y = (param_1->mPos).y * fVar1;
    (param_1->mPos).z = (param_1->mPos).z * fVar1;
  }
  mtx::PSMTXRotAxisRad((double)param_1->mMag,&local_38,&param_1->mPos);
  (param_1->mAirPos).x = local_38;
  (param_1->mAirPos).y = local_28;
  (param_1->mAirPos).z = local_18;
  param_1->mAirMinDist = local_34;
  *(undefined4 *)&param_1->field_0x34 = local_24;
  *(undefined4 *)&param_1->field_0x38 = local_14;
  (param_1->mAirDir).x = local_30;
  (param_1->mAirDir).y = local_20;
  (param_1->mAirDir).z = local_10;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JPASpinField::calc(JPAFieldData *,
                                 JPABaseParticle *) */

void __thiscall
JPASpinField::calc(JPASpinField *this,JPAFieldData *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  float fVar2;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  undefined4 local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined4 local_28;
  float local_24;
  float local_20;
  
  local_4c = (param_1->mAirPos).x;
  local_3c = (param_1->mAirPos).y;
  local_2c = (param_1->mAirPos).z;
  local_48 = param_1->mAirMinDist;
  local_38 = *(undefined4 *)&param_1->field_0x34;
  local_28 = *(undefined4 *)&param_1->field_0x38;
  local_44 = (param_1->mAirDir).x;
  local_34 = (param_1->mAirDir).y;
  local_24 = (param_1->mAirDir).z;
  local_20 = JPABase::_2450;
  local_30 = JPABase::_2450;
  local_40 = JPABase::_2450;
  mtx::PSMTXMultVecSR(&local_4c,&param_2->mLocalPosition,&local_58);
  fVar1 = (param_2->mLocalPosition).z;
  fVar2 = (param_2->mLocalPosition).y;
  (param_1->mVel).x = local_58 - (param_2->mLocalPosition).x;
  (param_1->mVel).y = local_54 - fVar2;
  (param_1->mVel).z = local_50 - fVar1;
  JPABaseField::calcVel((JPABaseField *)this,param_1,param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f10 */
/* WARNING: Inlined function: FUN_80328f5c */
/* __thiscall JPAFieldManager::initField(JPADataBlockLinkInfo *,
                                         JPAEmitterInfo *) */

void __thiscall
JPAFieldManager::initField
          (JPAFieldManager *this,JPADataBlockLinkInfo *param_1,JPAEmitterInfo *param_2)

{
  byte bVar1;
  JSUPtrList *this_00;
  undefined uVar3;
  ulong uVar2;
  JPAFieldData *pData;
  JPAFieldBlockArc **ppJVar4;
  byte bVar5;
  
  bVar1 = param_1->mFldNum;
  ppJVar4 = param_1->mpFldBlocks;
  for (bVar5 = 0; bVar5 < bVar1; bVar5 = bVar5 + 1) {
    this_00 = this->field_0xc;
    if (this_00->mCount == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::setWarningMessage_f
                (uVar2,"JPAField.cpp",0x25c,"%s",(___)"JPariticle::Entry Over!!! (Field Number)");
    }
    else {
      pData = (JPAFieldData *)this_00->mpHead->mpData;
      JSUPtrList::remove(this_00,&pData->mLink);
      JSUPtrList::append(&this->mList,&pData->mLink);
      uVar3 = (**(code **)(*(int *)ppJVar4[bVar5] + 0xc))();
      switch(uVar3) {
      case 0:
        pData->mpBaseField = (JPABaseField *)&fc;
        break;
      case 1:
        pData->mpBaseField = (JPABaseField *)&fc.mpAirField;
        break;
      case 2:
        pData->mpBaseField = (JPABaseField *)&fc.mpMagnetField;
        break;
      case 3:
        pData->mpBaseField = (JPABaseField *)&fc.mpNewtonField;
        break;
      case 4:
        pData->mpBaseField = (JPABaseField *)&fc.mpVortex;
        break;
      case 5:
        pData->mpBaseField = (JPABaseField *)&fc.mpRandomField;
        break;
      case 6:
        pData->mpBaseField = (JPABaseField *)&fc.mpDragField;
        break;
      case 7:
        pData->mpBaseField = (JPABaseField *)&fc.mpConvectionField;
        break;
      case 8:
        pData->mpBaseField = (JPABaseField *)&fc.mpSpinField;
      }
      JPAFieldData::pEmtrInfo = param_2;
      JPABaseField::loadFieldData(pData->mpBaseField,pData,(JPAFieldBlock *)ppJVar4[bVar5]);
    }
  }
  return;
}


/* __thiscall JPAFieldManager::init(JPABaseParticle *) */

int __thiscall JPAFieldManager::init(JPAFieldManager *this,JPABaseParticle *pParticle)

{
  int *piVar1;
  JSUPtrLink *pJVar2;
  
  for (pJVar2 = (this->mList).mpHead; pJVar2 != (JSUPtrLink *)0x0; pJVar2 = pJVar2->mpNext) {
    piVar1 = *(int **)(pJVar2->mpData + 4);
    this = (JPAFieldManager *)(**(code **)(*piVar1 + 0xc))(piVar1,pJVar2->mpData,pParticle);
  }
  return (int)this;
}


/* __thiscall JPAFieldManager::preCalc(void) */

void __thiscall JPAFieldManager::preCalc(JPAFieldManager *this)

{
  JSUPtrLink *pJVar1;
  
  for (pJVar1 = (this->mList).mpHead; pJVar1 != (JSUPtrLink *)0x0; pJVar1 = pJVar1->mpNext) {
    (**(code **)(**(int **)(pJVar1->mpData + 4) + 0x10))();
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JPAFieldManager::calc(JPABaseParticle *) */

void __thiscall JPAFieldManager::calc(JPAFieldManager *this,JPABaseParticle *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  JSUPtrLink *pJVar5;
  undefined *puVar6;
  
  pJVar5 = (this->mList).mpHead;
  while( true ) {
    if (pJVar5 == (JSUPtrLink *)0x0) break;
    puVar6 = pJVar5->mpData;
    if (((*(ushort *)(puVar6 + 0x94) & 0x80) == 0) ||
       (fVar1 = (param_1->mPosition).z - *(float *)(puVar6 + 0x5c),
       fVar2 = (param_1->mPosition).x - *(float *)(puVar6 + 0x54),
       fVar3 = (param_1->mPosition).y - *(float *)(puVar6 + 0x58),
       cVar4 = (**(code **)(**(int **)(puVar6 + 4) + 0x18))
                         ((double)(fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3),
                          *(int **)(puVar6 + 4),puVar6), cVar4 != '\0')) {
      (**(code **)(**(int **)(puVar6 + 4) + 0x14))(*(int **)(puVar6 + 4),puVar6,param_1);
    }
    pJVar5 = pJVar5->mpNext;
  }
  return;
}


/* __thiscall JPAFieldManager::deleteField(JPAFieldData *) */

void __thiscall JPAFieldManager::deleteField(JPAFieldManager *this,JPAFieldData *param_1)

{
  JSUPtrList::remove(&this->mList,&param_1->mLink);
  JSUPtrList::prepend(this->field_0xc,&param_1->mLink);
  return;
}


/* __thiscall JPAFieldManager::deleteAllField(void) */

void __thiscall JPAFieldManager::deleteAllField(JPAFieldManager *this)

{
  JSUPtrLink *pJVar1;
  JSUPtrLink *pJVar2;
  
  pJVar1 = (this->mList).mpHead;
  while (pJVar1 != (JSUPtrLink *)0x0) {
    pJVar2 = pJVar1->mpNext;
    deleteField(this,(JPAFieldData *)pJVar1->mpData);
    pJVar1 = pJVar2;
  }
  return;
}


/* __thiscall JPABaseField::init(JPAFieldData *,
                                 JPABaseParticle *) */

int __thiscall JPABaseField::init(JPABaseField *this,EVP_PKEY_CTX *ctx)

{
  return (int)this;
}


/* __thiscall JPABaseField::calc(JPAFieldData *,
                                 JPABaseParticle *) */

void __thiscall
JPABaseField::calc(JPABaseField *this,JPAFieldData *param_1,JPABaseParticle *param_2)

{
  return;
}


/* __thiscall JPASpinField::~JPASpinField(void) */

void __thiscall JPASpinField::_JPASpinField(JPASpinField *this)

{
  short in_r4;
  
  if (this != (JPASpinField *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPASpinField *)0x0) {
      *(undefined1 **)this = &JPABaseField::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPASpinField::isItinRange(JPAFieldData *,
                                        float) */

undefined4 __thiscall
JPASpinField::isItinRange(JPASpinField *this,JPAFieldData *param_1,float param_2)

{
  return 1;
}


/* __thiscall JPADragField::~JPADragField(void) */

void __thiscall JPADragField::_JPADragField(JPADragField *this)

{
  short in_r4;
  
  if (this != (JPADragField *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADragField *)0x0) {
      *(undefined1 **)this = &JPABaseField::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPARandomField::~JPARandomField(void) */

void __thiscall JPARandomField::_JPARandomField(JPARandomField *this)

{
  short in_r4;
  
  if (this != (JPARandomField *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPARandomField *)0x0) {
      *(undefined1 **)this = &JPABaseField::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPAConvectionField::~JPAConvectionField(void) */

void __thiscall JPAConvectionField::_JPAConvectionField(JPAConvectionField *this)

{
  short in_r4;
  
  if (this != (JPAConvectionField *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPAConvectionField *)0x0) {
      *(undefined1 **)this = &JPABaseField::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPAConvectionField::isItinRange(JPAFieldData *,
                                              float) */

undefined4 __thiscall
JPAConvectionField::isItinRange(JPAConvectionField *this,JPAFieldData *param_1,float param_2)

{
  return 1;
}


/* __thiscall JPAVortexField::~JPAVortexField(void) */

void __thiscall JPAVortexField::_JPAVortexField(JPAVortexField *this)

{
  short in_r4;
  
  if (this != (JPAVortexField *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPAVortexField *)0x0) {
      *(undefined1 **)this = &JPABaseField::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPAVortexField::isItinRange(JPAFieldData *,
                                          float) */

undefined4 __thiscall
JPAVortexField::isItinRange(JPAVortexField *this,JPAFieldData *param_1,float param_2)

{
  return 1;
}


/* __thiscall JPANewtonField::~JPANewtonField(void) */

void __thiscall JPANewtonField::_JPANewtonField(JPANewtonField *this)

{
  short in_r4;
  
  if (this != (JPANewtonField *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPANewtonField *)0x0) {
      *(undefined1 **)this = &JPABaseField::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPAMagnetField::~JPAMagnetField(void) */

void __thiscall JPAMagnetField::_JPAMagnetField(JPAMagnetField *this)

{
  short in_r4;
  
  if (this != (JPAMagnetField *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPAMagnetField *)0x0) {
      *(undefined1 **)this = &JPABaseField::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPAAirField::~JPAAirField(void) */

void __thiscall JPAAirField::_JPAAirField(JPAAirField *this)

{
  short in_r4;
  
  if (this != (JPAAirField *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPAAirField *)0x0) {
      *(undefined1 **)this = &JPABaseField::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPAGravityField::~JPAGravityField(void) */

void __thiscall JPAGravityField::_JPAGravityField(JPAGravityField *this)

{
  short in_r4;
  
  if (this != (JPAGravityField *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPAGravityField *)0x0) {
      *(undefined1 **)this = &JPABaseField::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPABaseField::~JPABaseField(void) */

void __thiscall JPABaseField::_JPABaseField(JPABaseField *this)

{
  short in_r4;
  
  if ((this != (JPABaseField *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace JPABase {

void __sinit_JPAField_cpp(void)

{
  ::JPAFieldManager::fc.mpGravityField = &::JPAGravityField::__vt;
  ::JPAFieldManager::fc.mpAirField = &::JPAAirField::__vt;
  ::JPAFieldManager::fc.mpMagnetField = &::JPAMagnetField::__vt;
  ::JPAFieldManager::fc.mpNewtonField = &::JPANewtonField::__vt;
  ::JPAFieldManager::fc.mpVortex = &::JPAVortexField::__vt;
  ::JPAFieldManager::fc.mpRandomField = &::JPARandomField::__vt;
  ::JPAFieldManager::fc.mpDragField = &::JPADragField::__vt;
  ::JPAFieldManager::fc.mpConvectionField = &::JPAConvectionField::__vt;
  ::JPAFieldManager::fc.mpSpinField = &::JPASpinField::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&::JPAFieldManager::fc,::JPAFieldContainer::_JPAFieldContainer,&_3144);
  return;
}

}

/* __thiscall JPAFieldContainer::~JPAFieldContainer(void) */

void __thiscall JPAFieldContainer::_JPAFieldContainer(JPAFieldContainer *this)

{
  short in_r4;
  
  if (this != (JPAFieldContainer *)0x0) {
    if (this != (JPAFieldContainer *)0xffffffe0) {
      this->mpSpinField = &JPASpinField::__vt;
      if (this != (JPAFieldContainer *)0xffffffe0) {
        this->mpSpinField = &JPABaseField::__vt;
      }
    }
    if (this != (JPAFieldContainer *)0xffffffe4) {
      this->mpConvectionField = &JPAConvectionField::__vt;
      if (this != (JPAFieldContainer *)0xffffffe4) {
        this->mpConvectionField = &JPABaseField::__vt;
      }
    }
    if (this != (JPAFieldContainer *)0xffffffe8) {
      this->mpDragField = &JPADragField::__vt;
      if (this != (JPAFieldContainer *)0xffffffe8) {
        this->mpDragField = &JPABaseField::__vt;
      }
    }
    if (this != (JPAFieldContainer *)0xffffffec) {
      this->mpRandomField = &JPARandomField::__vt;
      if (this != (JPAFieldContainer *)0xffffffec) {
        this->mpRandomField = &JPABaseField::__vt;
      }
    }
    if (this != (JPAFieldContainer *)0xfffffff0) {
      this->mpVortex = &JPAVortexField::__vt;
      if (this != (JPAFieldContainer *)0xfffffff0) {
        this->mpVortex = &JPABaseField::__vt;
      }
    }
    if (this != (JPAFieldContainer *)0xfffffff4) {
      this->mpNewtonField = &JPANewtonField::__vt;
      if (this != (JPAFieldContainer *)0xfffffff4) {
        this->mpNewtonField = &JPABaseField::__vt;
      }
    }
    if (this != (JPAFieldContainer *)&DAT_fffffff8) {
      this->mpMagnetField = &JPAMagnetField::__vt;
      if (this != (JPAFieldContainer *)&DAT_fffffff8) {
        this->mpMagnetField = &JPABaseField::__vt;
      }
    }
    if ((this != (JPAFieldContainer *)0xfffffffc) &&
       (this->mpAirField = &JPAAirField::__vt, this != (JPAFieldContainer *)0xfffffffc)) {
      this->mpAirField = &JPABaseField::__vt;
    }
    if ((this != (JPAFieldContainer *)0x0) &&
       (this->mpGravityField = &JPAGravityField::__vt, this != (JPAFieldContainer *)0x0)) {
      this->mpGravityField = &JPABaseField::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

