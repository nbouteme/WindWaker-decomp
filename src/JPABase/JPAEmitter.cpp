#include <JPABase/JPAEmitter.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <mtx/mtx.h>
#include <JPABase/JPAField.h>
#include <JPABase/JPAEmitter.h>
#include <JPABase/JPAMath.h>
#include <mtx/mtxvec.h>
#include <JPADraw/JPADraw.h>
#include <JSupport/JSUList.h>
#include <JPABase/JPAParticle.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <JMath/random.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JKernel/JKRHeap.h>
#include <Demangler/JPABaseEmitter.h>
#include <Demangler/JPAEmitterInfo.h>


namespace JPABaseEmitter {
struct JPAEmitterInfo emtrInfo;
}

/* __thiscall JPABaseEmitter::calcVolumePoint(void) */

void __thiscall JPABaseEmitter::calcVolumePoint(JPABaseEmitter *this)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  
  emtrInfo.mVelAxis.y = JPABase::0_0;
  emtrInfo.mVolumePos.z = JPABase::0_0;
  emtrInfo.mVolumePos.y = JPABase::0_0;
  emtrInfo.mVolumePos.x = JPABase::0_0;
  (this->mRandomSeed).v = (this->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
  fVar2 = JPABase::_2484;
  fVar1 = JPABase::1_0;
  uVar3 = (this->mRandomSeed).v;
  emtrInfo.mVelOmni.z = ((float)(uVar3 >> 9 | 0x3f800000) - JPABase::1_0) - JPABase::_2484;
  (this->mRandomSeed).v = uVar3 * 0x19660d + 0x3c6ef35f;
  uVar3 = (this->mRandomSeed).v;
  emtrInfo.mVelOmni.y = ((float)(uVar3 >> 9 | 0x3f800000) - fVar1) - fVar2;
  (this->mRandomSeed).v = uVar3 * 0x19660d + 0x3c6ef35f;
  uVar3 = (this->mRandomSeed).v;
  emtrInfo.mVelOmni.x = ((float)(uVar3 >> 9 | 0x3f800000) - fVar1) - fVar2;
  (this->mRandomSeed).v = uVar3 * 0x19660d + 0x3c6ef35f;
  uVar3 = (this->mRandomSeed).v;
  (this->mRandomSeed).v = uVar3 * 0x19660d + 0x3c6ef35f;
  emtrInfo.mVelAxis.x = ((float)((this->mRandomSeed).v >> 9 | 0x3f800000) - fVar1) - fVar2;
  emtrInfo.mVelAxis.z = ((float)(uVar3 >> 9 | 0x3f800000) - fVar1) - fVar2;
  return;
}


/* __thiscall JPABaseEmitter::calcVolumeLine(void) */

void __thiscall JPABaseEmitter::calcVolumeLine(JPABaseEmitter *this)

{
  if ((this->mDataFlag & 2U) == 0) {
    (this->mRandomSeed).v = (this->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
    emtrInfo.mVolumePos.z =
         emtrInfo.mVolumeSize *
         (((float)((this->mRandomSeed).v >> 9 | 0x3f800000) - JPABase::1_0) - JPABase::_2484);
  }
  else {
    emtrInfo.mVolumePos.z =
         emtrInfo.mVolumeSize *
         ((float)((double)CONCAT44(0x43300000,emtrInfo.mVolumeEmitIdx ^ 0x80000000) - JPABase::_2513
                 ) /
          ((float)((double)CONCAT44(0x43300000,emtrInfo.mVolumeEmitCount ^ 0x80000000) -
                  JPABase::_2513) - JPABase::1_0) - JPABase::_2484);
    emtrInfo.mVolumeEmitIdx = emtrInfo.mVolumeEmitIdx + 1;
  }
  emtrInfo.mVolumePos.x = JPABase::0_0;
  emtrInfo.mVolumePos.y = JPABase::0_0;
  emtrInfo.mVelOmni.x = JPABase::0_0 * emtrInfo.mEmitterGlobalScale.x;
  emtrInfo.mVelOmni.y = JPABase::0_0 * emtrInfo.mEmitterGlobalScale.y;
  emtrInfo.mVelOmni.z = emtrInfo.mVolumePos.z * emtrInfo.mEmitterGlobalScale.z;
  emtrInfo.mVelAxis.x = JPABase::0_0;
  emtrInfo.mVelAxis.y = JPABase::0_0;
  emtrInfo.mVelAxis.z = emtrInfo.mVolumePos.z;
  return;
}


/* __thiscall JPABaseEmitter::calcVolumeCircle(void) */

void __thiscall JPABaseEmitter::calcVolumeCircle(JPABaseEmitter *this)

{
  float fVar1;
  int iVar2;
  double local_10;
  double local_8;
  float angle;
  
  if ((this->mDataFlag & 2U) == 0) {
    (this->mRandomSeed).v = (this->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
    local_8 = (double)CONCAT44(0x43300000,(int)(short)((this->mRandomSeed).v >> 0x10) ^ 0x80000000);
    angle = this->mVolumeSweep * (float)(local_8 - JPABase::_2513);
  }
  else {
    local_10 = (double)CONCAT44(0x43300000,
                                (int)(short)((emtrInfo.mVolumeEmitIdx << 0x10) /
                                            emtrInfo.mVolumeEmitCount) ^ 0x80000000);
    angle = (float)(local_10 - JPABase::_2513) * this->mVolumeSweep;
    emtrInfo.mVolumeEmitIdx = emtrInfo.mVolumeEmitIdx + 1;
  }
  (this->mRandomSeed).v = (this->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
  fVar1 = (float)((this->mRandomSeed).v >> 9 | 0x3f800000) - JPABase::1_0;
  if ((this->mDataFlag & 1U) != 0) {
    fVar1 = JPABase::1_0 - fVar1 * fVar1;
  }
  fVar1 = emtrInfo.mVolumeSize *
          (this->mVolumeMinRad + fVar1 * (JPABase::1_0 - this->mVolumeMinRad));
  iVar2 = (int)((int)angle & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  emtrInfo.mVolumePos.z = fVar1 * JKernel::JMath::jmaCosTable[iVar2];
  emtrInfo.mVolumePos.x = fVar1 * JKernel::JMath::jmaSinTable[iVar2];
  emtrInfo.mVolumePos.y = JPABase::0_0;
  emtrInfo.mVelOmni.x = emtrInfo.mVolumePos.x * emtrInfo.mEmitterGlobalScale.x;
  emtrInfo.mVelOmni.y = JPABase::0_0 * emtrInfo.mEmitterGlobalScale.y;
  emtrInfo.mVelOmni.z = emtrInfo.mVolumePos.z * emtrInfo.mEmitterGlobalScale.z;
  emtrInfo.mVelAxis.x = emtrInfo.mVolumePos.x;
  emtrInfo.mVelAxis.y = JPABase::0_0;
  emtrInfo.mVelAxis.z = emtrInfo.mVolumePos.z;
  return;
}


/* __thiscall JPABaseEmitter::calcVolumeCube(void) */

void __thiscall JPABaseEmitter::calcVolumeCube(JPABaseEmitter *this)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  
  (this->mRandomSeed).v = (this->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
  fVar2 = JPABase::_2484;
  fVar1 = JPABase::1_0;
  uVar3 = (this->mRandomSeed).v;
  emtrInfo.mVolumePos.z =
       emtrInfo.mVolumeSize * (((float)(uVar3 >> 9 | 0x3f800000) - JPABase::1_0) - JPABase::_2484);
  (this->mRandomSeed).v = uVar3 * 0x19660d + 0x3c6ef35f;
  uVar3 = (this->mRandomSeed).v;
  emtrInfo.mVolumePos.y =
       emtrInfo.mVolumeSize * (((float)(uVar3 >> 9 | 0x3f800000) - fVar1) - fVar2);
  (this->mRandomSeed).v = uVar3 * 0x19660d + 0x3c6ef35f;
  emtrInfo.mVolumePos.x =
       emtrInfo.mVolumeSize * (((float)((this->mRandomSeed).v >> 9 | 0x3f800000) - fVar1) - fVar2);
  emtrInfo.mVelOmni.x = emtrInfo.mVolumePos.x * emtrInfo.mEmitterGlobalScale.x;
  emtrInfo.mVelOmni.y = emtrInfo.mVolumePos.y * emtrInfo.mEmitterGlobalScale.y;
  emtrInfo.mVelOmni.z = emtrInfo.mVolumePos.z * emtrInfo.mEmitterGlobalScale.z;
  emtrInfo.mVelAxis.x = emtrInfo.mVolumePos.x;
  emtrInfo.mVelAxis.y = JPABase::0_0;
  emtrInfo.mVelAxis.z = emtrInfo.mVolumePos.z;
  return;
}


/* __thiscall JPABaseEmitter::calcVolumeSphere(void) */

void __thiscall JPABaseEmitter::calcVolumeSphere(JPABaseEmitter *this)

{
  uint x;
  int xS;
  int angleS;
  ulong uVar1;
  uint uVar2;
  double local_10;
  double local_8;
  float size;
  float size_xS;
  
  if ((this->mDataFlag & 2U) == 0) {
    (this->mRandomSeed).v = (this->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
    uVar1 = (this->mRandomSeed).v;
    x = SEXT24((short)((int)uVar1 >> 0x11));
    (this->mRandomSeed).v = uVar1 * 0x19660d + 0x3c6ef35f;
    local_8 = (double)CONCAT44(0x43300000,(int)(short)((this->mRandomSeed).v >> 0x10) ^ 0x80000000);
    uVar2 = (uint)(this->mVolumeSweep * (float)(local_8 - JPABase::_2513));
  }
  else {
    x = SEXT24((short)((short)((emtrInfo.mVolumeEmitXCount << 0xf) / (emtrInfo.mDivNumber + -1)) +
                      0x4000));
    local_10 = (double)CONCAT44(0x43300000,
                                (emtrInfo.mVolumeEmitAngleCount << 0x10) /
                                emtrInfo.mVolumeEmitAngleMax & 0xffff);
    uVar2 = (uint)(JPABase::_2650 + (float)(local_10 - JPABase::_2652) * this->mVolumeSweep);
    emtrInfo.mVolumeEmitAngleCount = emtrInfo.mVolumeEmitAngleCount + 1;
    if (emtrInfo.mVolumeEmitAngleCount == emtrInfo.mVolumeEmitAngleMax) {
      emtrInfo.mVolumeEmitAngleCount = 0;
      emtrInfo.mVolumeEmitXCount = emtrInfo.mVolumeEmitXCount + 1;
      if (emtrInfo.mVolumeEmitXCount * 2 < emtrInfo.mDivNumber) {
        if (emtrInfo.mVolumeEmitAngleMax == 1) {
          emtrInfo.mVolumeEmitAngleMax = 4;
        }
        else {
          emtrInfo.mVolumeEmitAngleMax = emtrInfo.mVolumeEmitAngleMax + 4;
        }
      }
      else {
        if (emtrInfo.mVolumeEmitAngleMax == 4) {
          emtrInfo.mVolumeEmitAngleMax = 1;
        }
        else {
          emtrInfo.mVolumeEmitAngleMax = emtrInfo.mVolumeEmitAngleMax + -4;
        }
      }
    }
  }
  (this->mRandomSeed).v = (this->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
  size = (float)((this->mRandomSeed).v >> 9 | 0x3f800000) - JPABase::1_0;
  if ((this->mDataFlag & 1U) != 0) {
    size = JPABase::1_0 - size * size * size;
  }
  size = emtrInfo.mVolumeSize * (this->mVolumeMinRad + size * (JPABase::1_0 - this->mVolumeMinRad));
  xS = (int)(x & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
  size_xS = size * JKernel::JMath::jmaCosTable[xS];
  angleS = (int)(uVar2 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
  emtrInfo.mVolumePos.z = size_xS * JKernel::JMath::jmaCosTable[angleS];
  emtrInfo.mVolumePos.y = -size * JKernel::JMath::jmaSinTable[xS];
  emtrInfo.mVolumePos.x = size_xS * JKernel::JMath::jmaSinTable[angleS];
  emtrInfo.mVelOmni.x = emtrInfo.mVolumePos.x * emtrInfo.mEmitterGlobalScale.x;
  emtrInfo.mVelOmni.y = emtrInfo.mVolumePos.y * emtrInfo.mEmitterGlobalScale.y;
  emtrInfo.mVelOmni.z = emtrInfo.mVolumePos.z * emtrInfo.mEmitterGlobalScale.z;
  emtrInfo.mVelAxis.x = emtrInfo.mVolumePos.x;
  emtrInfo.mVelAxis.y = JPABase::0_0;
  emtrInfo.mVelAxis.z = emtrInfo.mVolumePos.z;
  return;
}


/* __thiscall JPABaseEmitter::calcVolumeCylinder(void) */

void __thiscall JPABaseEmitter::calcVolumeCylinder(JPABaseEmitter *this)

{
  double dVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  float fVar5;
  ulong uVar6;
  
  (this->mRandomSeed).v = (this->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
  uVar6 = (this->mRandomSeed).v;
  fVar2 = this->mVolumeSweep;
  dVar1 = (double)CONCAT44(0x43300000,(int)(short)(uVar6 >> 0x10) ^ 0x80000000) - JPABase::_2513;
  (this->mRandomSeed).v = uVar6 * 0x19660d + 0x3c6ef35f;
  fVar5 = JPABase::1_0;
  fVar3 = (float)((this->mRandomSeed).v >> 9 | 0x3f800000) - JPABase::1_0;
  if ((this->mDataFlag & 1U) != 0) {
    fVar3 = JPABase::1_0 - fVar3 * fVar3;
  }
  fVar3 = emtrInfo.mVolumeSize *
          (this->mVolumeMinRad + fVar3 * (JPABase::1_0 - this->mVolumeMinRad));
  uVar4 = (int)(fVar2 * (float)dVar1) & 0xffff;
  emtrInfo.mVolumePos.z =
       fVar3 * JKernel::JMath::jmaCosTable[(int)uVar4 >> (JKernel::JMath::jmaSinShift & 0x3f)];
  (this->mRandomSeed).v = (this->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
  fVar2 = (float)((this->mRandomSeed).v >> 9 | 0x3f800000) - fVar5;
  emtrInfo.mVolumePos.y = emtrInfo.mVolumeSize * ((fVar2 + fVar2) - fVar5);
  emtrInfo.mVolumePos.x =
       fVar3 * JKernel::JMath::jmaSinTable[(int)uVar4 >> (JKernel::JMath::jmaSinShift & 0x3f)];
  emtrInfo.mVelOmni.x = emtrInfo.mVolumePos.x * emtrInfo.mEmitterGlobalScale.x;
  emtrInfo.mVelOmni.y = emtrInfo.mVolumePos.y * emtrInfo.mEmitterGlobalScale.y;
  emtrInfo.mVelOmni.z = emtrInfo.mVolumePos.z * emtrInfo.mEmitterGlobalScale.z;
  emtrInfo.mVelAxis.x = emtrInfo.mVolumePos.x;
  emtrInfo.mVelAxis.y = JPABase::0_0;
  emtrInfo.mVelAxis.z = emtrInfo.mVolumePos.z;
  return;
}


/* __thiscall JPABaseEmitter::calcVolumeTorus(void) */

void __thiscall JPABaseEmitter::calcVolumeTorus(JPABaseEmitter *this)

{
  double dVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  
  (this->mRandomSeed).v = (this->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
  uVar6 = (this->mRandomSeed).v;
  fVar2 = this->mVolumeSweep;
  dVar1 = (double)CONCAT44(0x43300000,(int)(short)(uVar6 >> 0x10) ^ 0x80000000) - JPABase::_2513;
  (this->mRandomSeed).v = uVar6 * 0x19660d + 0x3c6ef35f;
  fVar3 = this->mVolumeMinRad * emtrInfo.mVolumeSize;
  iVar4 = (int)((int)(fVar2 * (float)dVar1) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  iVar5 = (int)((int)(short)((this->mRandomSeed).v >> 0x10) & 0xffffU) >>
          (JKernel::JMath::jmaSinShift & 0x3f);
  emtrInfo.mVelAxis.z =
       fVar3 * JKernel::JMath::jmaCosTable[iVar4] * JKernel::JMath::jmaCosTable[iVar5];
  emtrInfo.mVolumePos.y = fVar3 * JKernel::JMath::jmaSinTable[iVar5];
  emtrInfo.mVelAxis.x =
       fVar3 * JKernel::JMath::jmaSinTable[iVar4] * JKernel::JMath::jmaCosTable[iVar5];
  emtrInfo.mVolumePos.z =
       emtrInfo.mVelAxis.z + emtrInfo.mVolumeSize * JKernel::JMath::jmaCosTable[iVar4];
  emtrInfo.mVolumePos.x =
       emtrInfo.mVelAxis.x + emtrInfo.mVolumeSize * JKernel::JMath::jmaSinTable[iVar4];
  emtrInfo.mVelOmni.x = emtrInfo.mVolumePos.x * emtrInfo.mEmitterGlobalScale.x;
  emtrInfo.mVelOmni.y = emtrInfo.mVolumePos.y * emtrInfo.mEmitterGlobalScale.y;
  emtrInfo.mVelOmni.z = emtrInfo.mVolumePos.z * emtrInfo.mEmitterGlobalScale.z;
  emtrInfo.mVelAxis.y = emtrInfo.mVolumePos.y;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JPABaseEmitter::create(JPADataBlockLinkInfo *) */

void __thiscall JPABaseEmitter::create(JPABaseEmitter *this,JPADataBlockLinkInfo *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  byte bVar13;
  short sVar12;
  int iVar11;
  JPADynamicsBlockArc *pDynBlock;
  double dVar14;
  
  this->mpDataLinkInfo = param_1;
  pDynBlock = this->mpDataLinkInfo->mpDynamicsBlock;
  (**(code **)(pDynBlock->vtbl + 0x14))(pDynBlock,&this->mEmitterScale);
  (**(code **)(pDynBlock->vtbl + 0x1c))(pDynBlock,&this->mEmitterTranslation);
  (**(code **)(pDynBlock->vtbl + 0x18))(pDynBlock,&this->mEmitterRot);
  bVar13 = (**(code **)(pDynBlock->vtbl + 0x3c))(pDynBlock);
  this->mVolumeType = bVar13;
  bVar13 = (**(code **)(pDynBlock->vtbl + 0x58))(pDynBlock);
  this->mRateStep = bVar13;
  sVar12 = (**(code **)(pDynBlock->vtbl + 0x4c))(pDynBlock);
  this->mDivNumber = sVar12;
  dVar14 = (double)(**(code **)(pDynBlock->vtbl + 0x50))(pDynBlock);
  this->mRate = (float)dVar14;
  dVar14 = (double)(**(code **)(pDynBlock->vtbl + 0x54))(pDynBlock);
  this->mRateRndm = (float)dVar14;
  sVar12 = (**(code **)(pDynBlock->vtbl + 0x5c))(pDynBlock);
  this->mMaxFrame = (int)sVar12;
  sVar12 = (**(code **)(pDynBlock->vtbl + 0x60))(pDynBlock);
  this->mStartFrame = sVar12;
  sVar12 = (**(code **)(pDynBlock->vtbl + 0x40))(pDynBlock);
  this->mVolumeSize = sVar12;
  dVar14 = (double)(**(code **)(pDynBlock->vtbl + 0x44))(pDynBlock);
  this->mVolumeSweep = (float)dVar14;
  dVar14 = (double)(**(code **)(pDynBlock->vtbl + 0x48))(pDynBlock);
  this->mVolumeMinRad = (float)dVar14;
  sVar12 = (**(code **)(pDynBlock->vtbl + 100))(pDynBlock);
  this->mLifeTime = sVar12;
  dVar14 = (double)(**(code **)(pDynBlock->vtbl + 0x68))(pDynBlock);
  this->mLifeTimeRndm = (float)dVar14;
  dVar14 = (double)(**(code **)(pDynBlock->vtbl + 0x7c))(pDynBlock);
  this->mMoment = (float)dVar14;
  dVar14 = (double)(**(code **)(pDynBlock->vtbl + 0x80))(pDynBlock);
  this->mMomentRndm = (float)dVar14;
  dVar14 = (double)(**(code **)(pDynBlock->vtbl + 0x38))(pDynBlock);
  this->mInitialVelRatio = (float)dVar14;
  dVar14 = (double)(**(code **)(pDynBlock->vtbl + 0x70))(pDynBlock);
  this->mAccelRndm = (float)dVar14;
  dVar14 = (double)(**(code **)(pDynBlock->vtbl + 0x74))(pDynBlock);
  this->mAirResist = (float)dVar14;
  dVar14 = (double)(**(code **)(pDynBlock->vtbl + 0x78))(pDynBlock);
  this->mAirResistRndm = (float)dVar14;
  dVar14 = (double)(**(code **)(pDynBlock->vtbl + 0x24))(pDynBlock);
  this->mInitialVelOmni = (float)dVar14;
  dVar14 = (double)(**(code **)(pDynBlock->vtbl + 0x28))(pDynBlock);
  this->mInitialVelAxis = (float)dVar14;
  dVar14 = (double)(**(code **)(pDynBlock->vtbl + 0x2c))(pDynBlock);
  this->mInitialVelRndm = (float)dVar14;
  dVar14 = (double)(**(code **)(pDynBlock->vtbl + 0x30))(pDynBlock);
  this->mInitialVelDir = (float)dVar14;
  dVar14 = (double)(**(code **)(pDynBlock->vtbl + 0x6c))(pDynBlock);
  this->mAccel = (float)dVar14;
  (**(code **)(pDynBlock->vtbl + 0x20))(pDynBlock,&this->mEmitterDir);
  fVar1 = (this->mEmitterDir).z;
  fVar2 = (this->mEmitterDir).x;
  fVar3 = (this->mEmitterDir).y;
  fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  if (JPABase::_2806 < fVar1) {
    if (JPABase::0_0 < fVar1) {
      fVar2 = 1.0 / SQRT(fVar1);
      fVar1 = JPABase::_2484 * fVar2 * (JPABase::_2807 - fVar1 * fVar2 * fVar2);
    }
    (this->mEmitterDir).x = (this->mEmitterDir).x * fVar1;
    (this->mEmitterDir).y = (this->mEmitterDir).y * fVar1;
    (this->mEmitterDir).z = (this->mEmitterDir).z * fVar1;
  }
  dVar14 = (double)(**(code **)(pDynBlock->vtbl + 0x34))(pDynBlock);
  this->mSpread = (float)dVar14;
  iVar11 = (**(code **)(pDynBlock->vtbl + 0xc))(pDynBlock);
  this->mDataFlag = iVar11;
  iVar11 = (**(code **)(pDynBlock->vtbl + 0x10))(pDynBlock);
  this->mUseKeyFlag = iVar11;
  this->mFlags = 0x30;
  mtx::PSMTXIdentity(&this->mGlobalRotation);
  fVar2 = JPABase::1_0;
  (this->mGlobalScale).x = JPABase::1_0;
  (this->mGlobalScale).y = fVar2;
  (this->mGlobalScale).z = fVar2;
  fVar1 = JPABase::0_0;
  (this->mGlobalTranslation).z = JPABase::0_0;
  (this->mGlobalTranslation).y = fVar1;
  (this->mGlobalTranslation).x = fVar1;
  (this->mGlobalScale2D).x = fVar2;
  (this->mGlobalScale2D).y = fVar2;
  (this->mGlobalScale2D).z = fVar2;
  (this->mGlobalEnvColor).a = 0xff;
  (this->mGlobalEnvColor).b = 0xff;
  (this->mGlobalEnvColor).g = 0xff;
  (this->mGlobalEnvColor).r = 0xff;
  (this->mGlobalPrmColor).a = 0xff;
  (this->mGlobalPrmColor).b = 0xff;
  (this->mGlobalPrmColor).g = 0xff;
  (this->mGlobalPrmColor).r = 0xff;
  this->mEmitCount = fVar1;
  this->mRateStepTimer = fVar1;
  this->mTick = fVar1;
  this->mTime = fVar1;
  *(undefined4 *)&this->field_0x210 = 0;
  emtrInfo.mRandom = emtrInfo.mRandom * 0x19660d + 0x3c6ef35f;
  (this->mRandomSeed).v = emtrInfo.mRandom;
  JPAFieldManager::initField(&this->mFieldManager,param_1,&emtrInfo);
  iVar10 = DAT_803965d4;
  iVar9 = DAT_803965c8;
  iVar8 = DAT_803965bc;
  iVar7 = DAT_803965b0;
  iVar6 = DAT_803965a4;
  iVar5 = DAT_80396598;
  iVar4 = DAT_8039658c;
  iVar11 = DAT_80370fbc;
  switch(this->mVolumeType) {
  case 0:
    (this->mVolumeFunc).this_delta = JPABase::_2756;
    (this->mVolumeFunc).vtbl_offset = iVar7;
    (this->mVolumeFunc).func = PTR_calcVolumeCube_803965b4;
    break;
  case 1:
    (this->mVolumeFunc).this_delta = JPABase::_2758;
    (this->mVolumeFunc).vtbl_offset = iVar8;
    (this->mVolumeFunc).func = PTR_calcVolumeSphere_803965c0;
    break;
  case 2:
    (this->mVolumeFunc).this_delta = JPABase::_2760;
    (this->mVolumeFunc).vtbl_offset = iVar9;
    (this->mVolumeFunc).func = PTR_calcVolumeCylinder_803965cc;
    break;
  case 3:
    (this->mVolumeFunc).this_delta = JPABase::_2762;
    (this->mVolumeFunc).vtbl_offset = iVar10;
    (this->mVolumeFunc).func = PTR_calcVolumeTorus_803965d8;
    break;
  case 4:
    (this->mVolumeFunc).this_delta = JPABase::_2750;
    (this->mVolumeFunc).vtbl_offset = iVar4;
    (this->mVolumeFunc).func = PTR_calcVolumePoint_80396590;
    break;
  case 5:
    (this->mVolumeFunc).this_delta = JPABase::_2754;
    (this->mVolumeFunc).vtbl_offset = iVar6;
    (this->mVolumeFunc).func = PTR_calcVolumeCircle_803965a8;
    break;
  case 6:
    (this->mVolumeFunc).this_delta = JPABase::_2752;
    (this->mVolumeFunc).vtbl_offset = iVar5;
    (this->mVolumeFunc).func = PTR_calcVolumeLine_8039659c;
    break;
  default:
    (this->mVolumeFunc).this_delta = Runtime.PPCEABI.H::__ptmf_null;
    (this->mVolumeFunc).vtbl_offset = iVar11;
    (this->mVolumeFunc).func = DAT_80370fc0;
  }
  return;
}


/* __thiscall JPABaseEmitter::calcEmitterInfo(void) */

void __thiscall JPABaseEmitter::calcEmitterInfo(JPABaseEmitter *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  MTX34 mtx;
  MTX34 mtxEmitterRot;
  MTX34 mtxEmitterScale;
  
  emtrInfo.mVolumeEmitXCount = 0;
  emtrInfo.mVolumeEmitAngleCount = 0;
  emtrInfo.mVolumeEmitAngleMax = 1;
  emtrInfo.mDivNumber = (uint)(ushort)this->mDivNumber * 2 + 1;
  emtrInfo.mVolumeSize =
       (float)((double)CONCAT44(0x43300000,(uint)(ushort)this->mVolumeSize) - JPABase::_2652);
  emtrInfo.mpCurEmitter = this;
  ::mtx::PSMTXScale((double)(this->mEmitterScale).x,(double)(this->mEmitterScale).y,
                    (double)(this->mEmitterScale).z,&mtxEmitterScale);
  JPABase::JPAGetXYZRotateMtx
            ((int)(short)(((int)(this->mEmitterRot).x << 0xe) / 0x5a),
             (int)(short)(((int)(this->mEmitterRot).y << 0xe) / 0x5a),
             (int)(short)(((int)(this->mEmitterRot).z << 0xe) / 0x5a),&mtxEmitterRot);
  ::mtx::PSMTXScale((double)(this->mGlobalScale).x,(double)(this->mGlobalScale).y,
                    (double)(this->mGlobalScale).z,&mtx);
  ::mtx::PSMTXConcat(&this->mGlobalRotation,&mtx,&mtx);
  mtx.m[0][3] = (this->mGlobalTranslation).x;
  mtx.m[1][3] = (this->mGlobalTranslation).y;
  mtx.m[2][3] = (this->mGlobalTranslation).z;
  ::mtx::PSMTXCopy(&this->mGlobalRotation,&emtrInfo.mGlobalRotation);
  ::mtx::PSMTXConcat(&this->mGlobalRotation,&mtxEmitterRot,&emtrInfo.mEmitterGlobalRot);
  ::mtx::PSMTXConcat(&emtrInfo.mEmitterGlobalRot,&mtxEmitterScale,&emtrInfo.mEmitterGlobalSR);
  JPABase::JPAGetDirMtx(&this->mEmitterDir,&emtrInfo.mEmitterDirMtx);
  fVar1 = (this->mGlobalScale).x;
  emtrInfo.mEmitterGlobalScale.x = (this->mEmitterScale).x * fVar1;
  fVar2 = (this->mGlobalScale).y;
  emtrInfo.mEmitterGlobalScale.y = (this->mEmitterScale).y * fVar2;
  fVar3 = (this->mGlobalScale).z;
  emtrInfo.mEmitterGlobalScale.z = (this->mEmitterScale).z * fVar3;
  emtrInfo.mEmitterTranslation.x = (this->mEmitterTranslation).x;
  emtrInfo.mEmitterTranslation.y = (this->mEmitterTranslation).y;
  emtrInfo.mEmitterTranslation.z = (this->mEmitterTranslation).z;
  emtrInfo.mPublicScale.x = fVar1 * JPABase::1_0;
  emtrInfo.mPublicScale.y = fVar2 * JPABase::1_0;
  emtrInfo.mPublicScale.z = fVar3 * JPABase::1_0;
  ::mtx::PSMTXMultVec(&mtx,&this->mEmitterTranslation,&emtrInfo.mEmitterGlobalCenterPos);
  return;
}


/* __thiscall JPABaseEmitter::calc(void) */

void __thiscall JPABaseEmitter::calc(JPABaseEmitter *this)

{
  JPACallBackBase *pJVar1;
  
  emtrInfo.mVolumeEmitCount = 0;
  if ((this->mFlags & 2) == 0) {
    calcKey(this);
    pJVar1 = this->mpEmitterCallBack;
    if (pJVar1 != (JPACallBackBase *)0x0) {
      (**(code **)(pJVar1->vtbl + 0x10))(pJVar1,this);
    }
    calcEmitterInfo(this);
    JPADraw::calc(&this->mDraw);
    JPAFieldManager::preCalc(&this->mFieldManager);
    if ((this->mFlags & 8) == 0) {
      calcCreatePtcls(this);
    }
    pJVar1 = this->mpEmitterCallBack;
    if (pJVar1 != (JPACallBackBase *)0x0) {
      (**(code **)(pJVar1->vtbl + 0x14))(pJVar1,this);
    }
    calcParticle(this);
    calcChild(this);
    this->mTick = this->mTick + JPABase::1_0;
    if (this->mTick < JPABase::0_0) {
      this->mTick = JPABase::0_0;
    }
  }
  else {
    pJVar1 = this->mpEmitterCallBack;
    if (pJVar1 != (JPACallBackBase *)0x0) {
      (**(code **)(pJVar1->vtbl + 0x10))(pJVar1,this);
    }
    pJVar1 = this->mpEmitterCallBack;
    if (pJVar1 != (JPACallBackBase *)0x0) {
      (**(code **)(pJVar1->vtbl + 0x14))(pJVar1,this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JPABaseEmitter::calcCreatePtcls(void) */

void __thiscall JPABaseEmitter::calcCreatePtcls(JPABaseEmitter *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  if ((this->mFlags & 0x20) != 0) {
    emtrInfo.mVolumeEmitCount = 0;
    if ((this->mDataFlag & 2U) == 0) {
      (this->mRandomSeed).v = (this->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
      fVar3 = JPABase::1_0;
      fVar1 = (float)((this->mRandomSeed).v >> 9 | 0x3f800000) - JPABase::1_0;
      fVar1 = this->mRate * (JPABase::1_0 + this->mRateRndm * ((fVar1 + fVar1) - JPABase::1_0));
      fVar2 = this->mEmitCount + fVar1;
      this->mEmitCount = fVar2;
      if (fVar2 < fVar3) {
        if ((JPABase::0_0 < fVar1) && ((this->mFlags & 0x10) != 0)) {
          emtrInfo.mVolumeEmitCount = 1;
        }
      }
      else {
        emtrInfo.mVolumeEmitCount = (int)this->mEmitCount;
        this->mEmitCount =
             this->mEmitCount -
             (float)((double)CONCAT44(0x43300000,emtrInfo.mVolumeEmitCount ^ 0x80000000) -
                    JPABase::_2513);
      }
    }
    else {
      if (this->mVolumeType == 1) {
        emtrInfo.mVolumeEmitCount =
             ((ushort)this->mDivNumber + 1) * ((ushort)this->mDivNumber - 1) * 4 + 6;
      }
      else {
        emtrInfo.mVolumeEmitCount = ZEXT24((ushort)this->mDivNumber);
      }
      emtrInfo.mVolumeEmitIdx = 0;
    }
    uVar6 = emtrInfo.mVolumeEmitCount;
    if ((this->mFlags & 1) != 0) {
      uVar6 = 0;
    }
    iVar5 = 0;
    while ((iVar5 < (int)uVar6 && (iVar4 = createParticle(this), iVar4 != 0))) {
      iVar5 = iVar5 + 1;
    }
  }
  fVar1 = this->mRateStepTimer + JPABase::1_0;
  this->mRateStepTimer = fVar1;
  uVar6 = this->mRateStep + 1 ^ 0x80000000;
  if (fVar1 < (float)((double)CONCAT44(0x43300000,uVar6) - JPABase::_2513)) {
    this->mFlags = this->mFlags & 0xffffffdf;
  }
  else {
    this->mRateStepTimer =
         this->mRateStepTimer - (float)((double)CONCAT44(0x43300000,uVar6) - JPABase::_2513);
    this->mFlags = this->mFlags | 0x20;
  }
  this->mFlags = this->mFlags & 0xffffffef;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JPABaseEmitter::createChildren(JPABaseParticle *) */

void __thiscall JPABaseEmitter::createChildren(JPABaseEmitter *this,JPABaseParticle *param_1)

{
  short sVar1;
  JPABaseParticle *this_00;
  int iVar2;
  
  sVar1 = (**(code **)(*(int *)this->mpDataLinkInfo->mpSweepShapeBlock + 0x20))();
  iVar2 = 0;
  while ((iVar2 < sVar1 &&
         (this_00 = (JPABaseParticle *)getPtclFromVacList(this), this_00 != (JPABaseParticle *)0x0))
        ) {
    JSUPtrList::prepend(&this->mChildParticles,(JSUPtrLink *)this_00);
    JPABaseParticle::initChild(this_00,param_1);
    JPADraw::initChild(&this->mDraw,param_1,this_00);
    iVar2 = iVar2 + 1;
  }
  return;
}


/* __thiscall JPABaseEmitter::createParticle(void) */

JPABaseParticle * __thiscall JPABaseEmitter::createParticle(JPABaseEmitter *this)

{
  JPABaseParticle *this_00;
  void *extraout_r4;
  
  this_00 = (JPABaseParticle *)getPtclFromVacList(this);
  if (this_00 != (JPABaseParticle *)0x0) {
    JSUPtrList::prepend(&this->mActiveParticles,(JSUPtrLink *)this_00);
    Runtime.PPCEABI.H::__ptmf_scall(&this->mVolumeFunc,this,extraout_r4);
    JPABaseParticle::initParticle(this_00);
    JPADraw::initParticle(&this->mDraw,this_00);
  }
  return this_00;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JPABaseEmitter::calcParticle(void) */

void __thiscall JPABaseEmitter::calcParticle(JPABaseEmitter *this)

{
  JPACallBackBase2 *pJVar1;
  char cVar3;
  JSUPtrLink *pJVar2;
  JPABaseParticle *this_00;
  JSUPtrLink *pJVar4;
  
  pJVar2 = (this->mActiveParticles).mpHead;
  while (pJVar2 != (JSUPtrLink *)0x0) {
    pJVar4 = (JSUPtrLink *)(&pJVar2->mpData)[3];
    this_00 = (JPABaseParticle *)pJVar2->mpData;
    JPABaseParticle::incFrame(this_00);
    if ((this_00->mFlags & 0x80) == 0) {
      JPABaseParticle::calcVelocity(this_00);
      pJVar1 = this_00->mpCallBack2;
      if (pJVar1 != (JPACallBackBase2 *)0x0) {
        (**(code **)(pJVar1->vtbl + 0x10))(pJVar1,this,this_00);
      }
      if ((this_00->mFlags & 2) == 0) {
        JPADraw::calcParticle(&this->mDraw,this_00);
        if ((this->mpDataLinkInfo->mpSweepShapeBlock != (JPASweepShapeArc *)0x0) &&
           (cVar3 = JPABaseParticle::checkCreateChild(this_00), cVar3 != '\0')) {
          createChildren(this,this_00);
        }
        JPABaseParticle::calcPosition(this_00);
      }
    }
    else {
      this_00->mFlags = this_00->mFlags | 2;
    }
    pJVar2 = pJVar4;
    if ((this_00->mFlags & 2) != 0) {
      deleteParticle(this,this_00,&this->mActiveParticles);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JPABaseEmitter::calcChild(void) */

void __thiscall JPABaseEmitter::calcChild(JPABaseEmitter *this)

{
  JPACallBackBase2 *pJVar1;
  JSUPtrLink *pJVar2;
  JPABaseParticle *this_00;
  JSUPtrLink *pJVar3;
  
  pJVar2 = (this->mChildParticles).mpHead;
  while (pJVar2 != (JSUPtrLink *)0x0) {
    pJVar3 = (JSUPtrLink *)(&pJVar2->mpData)[3];
    this_00 = (JPABaseParticle *)pJVar2->mpData;
    JPABaseParticle::incFrame(this_00);
    if ((this_00->mFlags & 0x80) == 0) {
      if ((int)this_00->mCurFrame != 0) {
        JPABaseParticle::calcVelocity(this_00);
      }
      pJVar1 = this_00->mpCallBack2;
      if (pJVar1 != (JPACallBackBase2 *)0x0) {
        (**(code **)(pJVar1->vtbl + 0x10))(pJVar1,this,this_00);
      }
      if ((this_00->mFlags & 2) == 0) {
        JPADraw::calcChild(&this->mDraw,this_00);
        JPABaseParticle::calcPosition(this_00);
      }
    }
    else {
      this_00->mFlags = this_00->mFlags | 2;
    }
    pJVar2 = pJVar3;
    if ((this_00->mFlags & 2) != 0) {
      deleteParticle(this,this_00,&this->mChildParticles);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8025da70) */
/* __thiscall JPABaseEmitter::calcKey(void) */

void __thiscall JPABaseEmitter::calcKey(JPABaseEmitter *this)

{
  int iVar1;
  uint uVar2;
  char cVar4;
  int iVar3;
  undefined uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined8 in_f31;
  double dVar10;
  double local_38;
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar7 = 0;
  for (iVar8 = 0; iVar8 < (int)(uint)this->mpDataLinkInfo->mKeyNum; iVar8 = iVar8 + 1) {
    piVar6 = *(int **)((int)this->mpDataLinkInfo->mpKeyBlocks + iVar7);
    dVar10 = (double)this->mTick;
    iVar1 = (**(code **)(*piVar6 + 0x18))(piVar6);
    uVar2 = (**(code **)(*piVar6 + 0x14))(piVar6);
    cVar4 = (**(code **)(*piVar6 + 0x10))(piVar6);
    if (cVar4 != '\0') {
      iVar3 = (int)*(float *)(iVar1 + ((uVar2 & 0xff) - 1) * 0x10) + 1;
      local_38 = (double)CONCAT44(0x43300000,((int)dVar10 / iVar3) * iVar3 ^ 0x80000000);
      dVar10 = (double)(float)(dVar10 - (double)(float)(local_38 - JPABase::_2513));
    }
    dVar10 = (double)JPABase::JPAGetKeyFrameValue(dVar10,uVar2 & 0xff,iVar1);
    uVar5 = (**(code **)(*piVar6 + 0xc))(piVar6);
    switch(uVar5) {
    case 0:
      this->mRate = (float)dVar10;
      break;
    case 1:
      this->mVolumeSize = (short)(int)dVar10;
      break;
    case 2:
      this->mVolumeSweep = (float)dVar10;
      break;
    case 3:
      this->mVolumeMinRad = (float)dVar10;
      break;
    case 4:
      this->mLifeTime = (short)(int)dVar10;
      break;
    case 5:
      this->mMoment = (float)dVar10;
      break;
    case 6:
      this->mInitialVelOmni = (float)dVar10;
      break;
    case 7:
      this->mInitialVelAxis = (float)dVar10;
      break;
    case 8:
      this->mInitialVelDir = (float)dVar10;
      break;
    case 9:
      this->mSpread = (float)dVar10;
      break;
    case 10:
      (this->mDraw).mScaleOut = (float)dVar10;
    }
    iVar7 = iVar7 + 4;
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  return;
}


/* __thiscall JPABaseEmitter::deleteParticle(JPABaseParticle *,
                                             JSUList<JPABaseParticle> *) */

void __thiscall
JPABaseEmitter::deleteParticle(JPABaseEmitter *this,JPABaseParticle *param_1,JSUPtrList *param_2)

{
  JSUPtrList::remove(param_2,&param_1->mLink);
  JSUPtrList::prepend(this->mpPtclVacList,&param_1->mLink);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JPABaseEmitter::deleteAllParticle(void) */

void __thiscall JPABaseEmitter::deleteAllParticle(JPABaseEmitter *this)

{
  JSUPtrLink *pJVar1;
  JSUPtrLink *pJVar2;
  
  pJVar1 = (this->mActiveParticles).mpHead;
  while (pJVar1 != (JSUPtrLink *)0x0) {
    pJVar2 = pJVar1->mpNext;
    JSUPtrList::remove(&this->mActiveParticles,pJVar1);
    JSUPtrList::prepend(this->mpPtclVacList,pJVar1);
    pJVar1 = pJVar2;
  }
  pJVar1 = (this->mChildParticles).mpHead;
  while (pJVar1 != (JSUPtrLink *)0x0) {
    pJVar2 = pJVar1->mpNext;
    JSUPtrList::remove(&this->mChildParticles,pJVar1);
    JSUPtrList::prepend(this->mpPtclVacList,pJVar1);
    pJVar1 = pJVar2;
  }
  return;
}


/* __thiscall JPABaseEmitter::getPtclFromVacList(void) */

JSUPtrLink * __thiscall JPABaseEmitter::getPtclFromVacList(JPABaseEmitter *this)

{
  JSUPtrList *this_00;
  JSUPtrLink *pJVar1;
  
  pJVar1 = (JSUPtrLink *)0x0;
  this_00 = this->mpPtclVacList;
  if (this_00->mCount != 0) {
    pJVar1 = (JSUPtrLink *)this_00->mpHead->mpData;
    JSUPtrList::remove(this_00,pJVar1);
  }
  return pJVar1;
}


/* __thiscall JPABaseEmitter::doStartFrameProcess(void) */

undefined4 __thiscall JPABaseEmitter::doStartFrameProcess(JPABaseEmitter *this)

{
  undefined4 uVar1;
  
  if (this->mTime <
      (float)((double)CONCAT44(0x43300000,(int)this->mStartFrame ^ 0x80000000) - JPABase::_2513)) {
    if ((this->mFlags & 2) == 0) {
      this->mTime = this->mTime + JPABase::1_0;
      if (this->mTime < JPABase::0_0) {
        this->mTime = JPABase::0_0;
      }
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


/* __thiscall JPABaseEmitter::doTerminationProcess(void) */

uint __thiscall JPABaseEmitter::doTerminationProcess(JPABaseEmitter *this)

{
  uint uVar1;
  
  uVar1 = this->mMaxFrame;
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    if ((int)uVar1 < 0) {
      this->mFlags = this->mFlags | 8;
      uVar1 = countLeadingZeros((this->mActiveParticles).mCount + (this->mChildParticles).mCount);
      uVar1 = uVar1 >> 5;
    }
    else {
      if (this->mTick < (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - JPABase::_2513)) {
        uVar1 = 0;
      }
      else {
        this->mFlags = this->mFlags | 8;
        if ((this->mFlags & 0x40) == 0) {
          uVar1 = countLeadingZeros((this->mActiveParticles).mCount + (this->mChildParticles).mCount
                                   );
          uVar1 = uVar1 >> 5;
        }
        else {
          uVar1 = 0;
        }
      }
    }
  }
  return uVar1;
}


/* __thiscall JPABaseEmitter::calcEmitterGlobalPosition(JGeometry::TVec3<float><float>&) */

void __thiscall
JPABaseEmitter::calcEmitterGlobalPosition(JPABaseEmitter *this,TVec3_float_ *param_1)

{
  MTX34 MStack56;
  
  mtx::PSMTXScale((double)(this->mGlobalScale).x,(double)(this->mGlobalScale).y,
                  (double)(this->mGlobalScale).z,&MStack56);
  mtx::PSMTXConcat(&this->mGlobalRotation,&MStack56,&MStack56);
  MStack56.m[0][3] = (this->mGlobalTranslation).x;
  MStack56.m[1][3] = (this->mGlobalTranslation).y;
  MStack56.m[2][3] = (this->mGlobalTranslation).z;
  mtx::PSMTXMultVec(&MStack56,&this->mEmitterTranslation,(cXyz *)param_1);
  return;
}


/* __thiscall JPABaseEmitter::calcgReRDirection(void) */

void __thiscall JPABaseEmitter::calcgReRDirection(JPABaseEmitter *this)

{
  MTX34 MStack56;
  
  JPABase::JPAGetXYZRotateMtx
            ((int)(short)(((int)(this->mEmitterRot).x << 0xe) / 0x5a),
             (int)(short)(((int)(this->mEmitterRot).y << 0xe) / 0x5a),
             (int)(short)(((int)(this->mEmitterRot).z << 0xe) / 0x5a),&MStack56);
  mtx::PSMTXConcat(&this->mGlobalRotation,&MStack56,&MStack56);
  mtx::PSMTXMultVec(&MStack56,&this->mEmitterDir,(cXyz *)&emtrInfo.field_0xf8);
  return;
}


/* __thiscall JPABaseEmitter::getPivotX(void) */

undefined4 __thiscall JPABaseEmitter::getPivotX(JPABaseEmitter *this)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)this->mpDataLinkInfo->mpExtraShapeBlock;
  if (piVar1 == (int *)0x0) {
    uVar2 = 1;
  }
  else {
    uVar2 = (**(code **)(*piVar1 + 0x54))();
  }
  return uVar2;
}


/* __thiscall JPABaseEmitter::getPivotY(void) */

undefined4 __thiscall JPABaseEmitter::getPivotY(JPABaseEmitter *this)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)this->mpDataLinkInfo->mpExtraShapeBlock;
  if (piVar1 == (int *)0x0) {
    uVar2 = 1;
  }
  else {
    uVar2 = (**(code **)(*piVar1 + 0x58))();
  }
  return uVar2;
}


namespace JPABase {

void __sinit_JPAEmitter_cpp(void)

{
  JKernel::JMath::TRandom_fast_::TRandom_fast_(&::JPABaseEmitter::emtrInfo.mRandom,0);
  Runtime.PPCEABI.H::__register_global_object
            (&::JPABaseEmitter::emtrInfo,::JPAEmitterInfo::_JPAEmitterInfo,&_2439);
  return;
}

}

/* __thiscall JPAEmitterInfo::~JPAEmitterInfo(void) */

void __thiscall JPAEmitterInfo::_JPAEmitterInfo(JPAEmitterInfo *this)

{
  short in_r4;
  
  if ((this != (JPAEmitterInfo *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

