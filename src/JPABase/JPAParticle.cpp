#include <JPABase/JPAParticle.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <mtx/mtxvec.h>
#include <JPABase/JPAMath.h>
#include <mtx/mtx.h>
#include <JPABase/JPAField.h>
#include <Demangler/JPABaseParticle.h>


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8025e604) */
/* WARNING: Removing unreachable block (ram,0x8025e5f4) */
/* WARNING: Removing unreachable block (ram,0x8025e5e4) */
/* WARNING: Removing unreachable block (ram,0x8025e5ec) */
/* WARNING: Removing unreachable block (ram,0x8025e5fc) */
/* WARNING: Removing unreachable block (ram,0x8025e60c) */
/* __thiscall JPABaseParticle::initParticle(void) */

void __thiscall JPABaseParticle::initParticle(JPABaseParticle *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  JPABaseEmitter *pJVar6;
  float fVar7;
  uint uVar8;
  ulong uVar9;
  undefined4 uVar10;
  double dVar11;
  double dVar12;
  undefined8 in_f26;
  undefined8 in_f27;
  undefined8 in_f28;
  double dVar13;
  double dVar14;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar15;
  undefined8 in_f31;
  double dVar16;
  double dVar17;
  MTX34 mtx;
  double local_80;
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  float velDirZ;
  float velDirY;
  float velDirX;
  
  pJVar6 = JPABaseEmitter::emtrInfo.mpCurEmitter;
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  this->mFlags = 1;
  fVar3 = JPABase::_2648;
  (this->mFieldAccel).z = JPABase::_2648;
  (this->mFieldAccel).y = fVar3;
  (this->mFieldAccel).x = fVar3;
  fVar3 = JPABase::_2649;
  this->mFieldDrag = JPABase::_2649;
  this->mDrag = fVar3;
  ::mtx::PSMTXMultVec(&JPABaseEmitter::emtrInfo.mEmitterGlobalSR,
                      &JPABaseEmitter::emtrInfo.mVolumePos,&this->mLocalPosition);
  if ((pJVar6->mDataFlag & 8U) != 0) {
    this->mFlags = this->mFlags | 0x20;
  }
  (this->mGlobalPosition).x = JPABaseEmitter::emtrInfo.mEmitterGlobalCenterPos.x;
  (this->mGlobalPosition).y = JPABaseEmitter::emtrInfo.mEmitterGlobalCenterPos.y;
  (this->mGlobalPosition).z = JPABaseEmitter::emtrInfo.mEmitterGlobalCenterPos.z;
  dVar16 = (double)JPABase::_2648;
  dVar15 = dVar16;
  dVar17 = dVar16;
  if (((double)pJVar6->mInitialVelOmni != dVar16) &&
     (dVar11 = (double)(JPABaseEmitter::emtrInfo.mVelOmni.z * JPABaseEmitter::emtrInfo.mVelOmni.z +
                       JPABaseEmitter::emtrInfo.mVelOmni.x * JPABaseEmitter::emtrInfo.mVelOmni.x +
                       JPABaseEmitter::emtrInfo.mVelOmni.y * JPABaseEmitter::emtrInfo.mVelOmni.y),
     (double)JPABase::_2650 < dVar11)) {
    if (dVar16 < dVar11) {
      fVar3 = (float)(1.0 / SQRT(dVar11));
      dVar11 = (double)(JPABase::_2651 * fVar3 *
                       (JPABase::_2652 - (float)(dVar11 * (double)(fVar3 * fVar3))));
    }
    fVar3 = (float)(dVar11 * (double)pJVar6->mInitialVelOmni);
    dVar16 = (double)(JPABaseEmitter::emtrInfo.mVelOmni.x * fVar3);
    dVar15 = (double)(JPABaseEmitter::emtrInfo.mVelOmni.y * fVar3);
    dVar17 = (double)(JPABaseEmitter::emtrInfo.mVelOmni.z * fVar3);
  }
  dVar13 = (double)JPABase::_2648;
  dVar11 = dVar13;
  dVar14 = dVar13;
  if (((double)pJVar6->mInitialVelAxis != dVar13) &&
     (dVar12 = (double)(JPABaseEmitter::emtrInfo.mVelAxis.z * JPABaseEmitter::emtrInfo.mVelAxis.z +
                       JPABaseEmitter::emtrInfo.mVelAxis.x * JPABaseEmitter::emtrInfo.mVelAxis.x +
                       JPABaseEmitter::emtrInfo.mVelAxis.y * JPABaseEmitter::emtrInfo.mVelAxis.y),
     (double)JPABase::_2650 < dVar12)) {
    if (dVar13 < dVar12) {
      fVar3 = (float)(1.0 / SQRT(dVar12));
      dVar12 = (double)(JPABase::_2651 * fVar3 *
                       (JPABase::_2652 - (float)(dVar12 * (double)(fVar3 * fVar3))));
    }
    fVar3 = (float)(dVar12 * (double)pJVar6->mInitialVelAxis);
    dVar13 = (double)(JPABaseEmitter::emtrInfo.mVelAxis.x * fVar3);
    dVar11 = (double)(JPABaseEmitter::emtrInfo.mVelAxis.y * fVar3);
    dVar14 = (double)(JPABaseEmitter::emtrInfo.mVelAxis.z * fVar3);
  }
  fVar3 = JPABase::_2648;
  velDirX = JPABase::_2648;
  velDirY = JPABase::_2648;
  if (pJVar6->mInitialVelDir != JPABase::_2648) {
    (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
    uVar9 = (pJVar6->mRandomSeed).v;
    (pJVar6->mRandomSeed).v = uVar9 * 0x19660d + 0x3c6ef35f;
    fVar3 = (float)((pJVar6->mRandomSeed).v >> 9 | 0x3f800000) - JPABase::_2649;
    JPABase::JPAGetYZRotateMtx
              ((int)(pJVar6->mSpread * JPABase::_2653 * ((fVar3 + fVar3) - JPABase::_2649)),
               (int)(short)(uVar9 >> 0x10),&mtx);
    ::mtx::PSMTXConcat(&JPABaseEmitter::emtrInfo.mEmitterDirMtx,&mtx,&mtx);
    fVar1 = pJVar6->mInitialVelDir;
    fVar3 = mtx.m[2][2] * fVar1;
    velDirX = mtx.m[0][2] * fVar1;
    velDirY = mtx.m[1][2] * fVar1;
  }
  fVar1 = JPABase::_2648;
  fVar4 = JPABase::_2648;
  fVar2 = JPABase::_2648;
  if (pJVar6->mInitialVelRndm != JPABase::_2648) {
    (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
    fVar7 = JPABase::_2651;
    fVar5 = JPABase::_2649;
    uVar8 = (pJVar6->mRandomSeed).v;
    fVar1 = pJVar6->mInitialVelRndm;
    fVar4 = ((float)(uVar8 >> 9 | 0x3f800000) - JPABase::_2649) - JPABase::_2651;
    (pJVar6->mRandomSeed).v = uVar8 * 0x19660d + 0x3c6ef35f;
    uVar8 = (pJVar6->mRandomSeed).v;
    fVar2 = pJVar6->mInitialVelRndm;
    (pJVar6->mRandomSeed).v = uVar8 * 0x19660d + 0x3c6ef35f;
    fVar1 = fVar1 * fVar4;
    fVar4 = pJVar6->mInitialVelRndm *
            (((float)((pJVar6->mRandomSeed).v >> 9 | 0x3f800000) - fVar5) - fVar7);
    fVar2 = fVar2 * (((float)(uVar8 >> 9 | 0x3f800000) - fVar5) - fVar7);
  }
  (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
  fVar5 = (float)((pJVar6->mRandomSeed).v >> 9 | 0x3f800000) - JPABase::_2649;
  fVar5 = JPABase::_2649 + pJVar6->mInitialVelRatio * ((fVar5 + fVar5) - JPABase::_2649);
  (this->mBaseVel).x = fVar5 * (fVar4 + velDirX + (float)(dVar16 + dVar13));
  (this->mBaseVel).y = fVar5 * (fVar2 + velDirY + (float)(dVar15 + dVar11));
  (this->mBaseVel).z = fVar5 * (fVar1 + fVar3 + (float)(dVar17 + dVar14));
  if ((pJVar6->mDataFlag & 4U) != 0) {
    (this->mBaseVel).x = (this->mBaseVel).x * (pJVar6->mEmitterScale).x;
    (this->mBaseVel).y = (this->mBaseVel).y * (pJVar6->mEmitterScale).y;
    (this->mBaseVel).z = (this->mBaseVel).z * (pJVar6->mEmitterScale).z;
  }
  ::mtx::PSMTXMultVec(&JPABaseEmitter::emtrInfo.mEmitterGlobalRot,&this->mBaseVel,&this->mBaseVel);
  (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
  fVar5 = JPABase::_2648;
  fVar2 = (float)((pJVar6->mRandomSeed).v >> 9 | 0x3f800000) - JPABase::_2649;
  fVar3 = (this->mBaseVel).z;
  fVar1 = (this->mBaseVel).x;
  fVar4 = (this->mBaseVel).y;
  fVar3 = fVar3 * fVar3 + fVar1 * fVar1 + fVar4 * fVar4;
  if (JPABase::_2650 < fVar3) {
    if (JPABase::_2648 < fVar3) {
      fVar1 = 1.0 / SQRT(fVar3);
      fVar3 = JPABase::_2651 * fVar1 * (JPABase::_2652 - fVar3 * fVar1 * fVar1);
    }
    fVar3 = fVar3 * pJVar6->mAccel *
                    (JPABase::_2649 + pJVar6->mAccelRndm * ((fVar2 + fVar2) - JPABase::_2649));
    (this->mAccel).x = (this->mBaseVel).x * fVar3;
    (this->mAccel).y = (this->mBaseVel).y * fVar3;
    (this->mAccel).z = (this->mBaseVel).z * fVar3;
  }
  else {
    (this->mAccel).z = JPABase::_2648;
    (this->mAccel).y = fVar5;
    (this->mAccel).x = fVar5;
  }
  (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
  fVar3 = JPABase::_2649;
  this->mAirResist =
       pJVar6->mAirResist +
       pJVar6->mAirResistRndm *
       (((float)((pJVar6->mRandomSeed).v >> 9 | 0x3f800000) - JPABase::_2649) - JPABase::_2651);
  if (fVar3 < this->mAirResist) {
    this->mAirResist = fVar3;
  }
  (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
  fVar3 = JPABase::_2649;
  this->mMoment =
       pJVar6->mMoment *
       (JPABase::_2649 -
       pJVar6->mMomentRndm * ((float)((pJVar6->mRandomSeed).v >> 9 | 0x3f800000) - JPABase::_2649));
  this->mCurFrame = JPABase::_2654;
  (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
  local_80 = (double)CONCAT44(0x43300000,(int)pJVar6->mLifeTime ^ 0x80000000);
  this->mLifeTime =
       (float)(local_80 - JPABase::_2656) *
       (fVar3 - pJVar6->mLifeTimeRndm * ((float)((pJVar6->mRandomSeed).v >> 9 | 0x3f800000) - fVar3)
       );
  this->mCurNormTime = JPABase::_2648;
  fVar3 = (this->mGlobalPosition).z;
  fVar4 = (this->mLocalPosition).z * JPABaseEmitter::emtrInfo.mPublicScale.z;
  fVar1 = (this->mGlobalPosition).y;
  fVar2 = (this->mLocalPosition).y * JPABaseEmitter::emtrInfo.mPublicScale.y;
  (this->mPosition).x =
       (this->mGlobalPosition).x +
       (this->mLocalPosition).x * JPABaseEmitter::emtrInfo.mPublicScale.x;
  (this->mPosition).y = fVar1 + fVar2;
  (this->mPosition).z = fVar3 + fVar4;
  this->mpCallBack2 = pJVar6->mpParticleCallBack;
  JPAFieldManager::init(&pJVar6->mFieldManager,this);
  *(undefined4 *)&this->field_0xd0 = 0;
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  __psq_l0(auStack24,uVar10);
  __psq_l1(auStack24,uVar10);
  __psq_l0(auStack40,uVar10);
  __psq_l1(auStack40,uVar10);
  __psq_l0(auStack56,uVar10);
  __psq_l1(auStack56,uVar10);
  __psq_l0(auStack72,uVar10);
  __psq_l1(auStack72,uVar10);
  __psq_l0(auStack88,uVar10);
  __psq_l1(auStack88,uVar10);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8025eb00) */
/* WARNING: Removing unreachable block (ram,0x8025eaf8) */
/* WARNING: Removing unreachable block (ram,0x8025eb08) */
/* __thiscall JPABaseParticle::initChild(JPABaseParticle *) */

void __thiscall JPABaseParticle::initChild(JPABaseParticle *this,JPABaseParticle *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  JPABaseEmitter *pJVar6;
  int iVar7;
  uint uVar8;
  short sVar9;
  ulong uVar10;
  int *piVar11;
  undefined4 uVar12;
  double dVar13;
  undefined8 in_f29;
  double dVar14;
  double dVar15;
  undefined8 in_f30;
  double dVar16;
  undefined8 in_f31;
  double dVar17;
  float local_54;
  float local_50;
  float local_4c;
  undefined4 local_48;
  uint uStack68;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  pJVar6 = JPABaseEmitter::emtrInfo.mpCurEmitter;
  uVar12 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  piVar11 = (int *)(JPABaseEmitter::emtrInfo.mpCurEmitter)->mpDataLinkInfo->mpSweepShapeBlock;
  this->mFlags = 5;
  iVar7 = (**(code **)(*piVar11 + 0x40))(piVar11);
  if (iVar7 == 0) {
    this->mFlags = this->mFlags | 0x40;
    fVar1 = JPABase::_2649;
    this->mFieldDrag = JPABase::_2649;
    this->mDrag = fVar1;
  }
  else {
    this->mDrag = param_1->mDrag;
    this->mFieldDrag = param_1->mFieldDrag;
  }
  (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
  fVar1 = (float)((pJVar6->mRandomSeed).v >> 9 | 0x3f800000) - JPABase::_2649;
  dVar14 = (double)((fVar1 + fVar1) - JPABase::_2649);
  dVar13 = (double)(**(code **)(*piVar11 + 0x38))(piVar11);
  dVar14 = (double)(JPABase::_2649 + (float)(dVar13 * dVar14));
  dVar13 = (double)(**(code **)(*piVar11 + 0x34))(piVar11);
  (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
  fVar2 = JPABase::_2649;
  uVar8 = (pJVar6->mRandomSeed).v;
  fVar1 = (float)(uVar8 >> 9 | 0x3f800000) - JPABase::_2649;
  dVar15 = (double)((fVar1 + fVar1) - JPABase::_2649);
  (pJVar6->mRandomSeed).v = uVar8 * 0x19660d + 0x3c6ef35f;
  uVar8 = (pJVar6->mRandomSeed).v;
  fVar1 = (float)(uVar8 >> 9 | 0x3f800000) - fVar2;
  dVar16 = (double)((fVar1 + fVar1) - fVar2);
  (pJVar6->mRandomSeed).v = uVar8 * 0x19660d + 0x3c6ef35f;
  fVar1 = (float)((pJVar6->mRandomSeed).v >> 9 | 0x3f800000) - fVar2;
  dVar17 = (double)((fVar1 + fVar1) - fVar2);
  fVar1 = (float)(dVar15 * dVar15) + (float)(dVar17 * dVar17) + (float)(dVar16 * dVar16);
  if (JPABase::_2650 < fVar1) {
    if (JPABase::_2648 < fVar1) {
      fVar2 = 1.0 / SQRT(fVar1);
      fVar1 = JPABase::_2651 * fVar2 * (JPABase::_2652 - fVar1 * fVar2 * fVar2);
    }
    dVar13 = (double)(fVar1 * (float)(dVar13 * dVar14));
    dVar17 = (double)(float)(dVar17 * dVar13);
    dVar16 = (double)(float)(dVar16 * dVar13);
    dVar15 = (double)(float)(dVar15 * dVar13);
  }
  dVar13 = (double)(**(code **)(*piVar11 + 0x30))(piVar11);
  (this->mBaseVel).x = (float)(dVar17 + (double)(float)((double)(param_1->mBaseVel).x * dVar13));
  (this->mBaseVel).y = (float)(dVar16 + (double)(float)((double)(param_1->mBaseVel).y * dVar13));
  (this->mBaseVel).z = (float)(dVar15 + (double)(float)((double)(param_1->mBaseVel).z * dVar13));
  dVar13 = (double)(**(code **)(*piVar11 + 0x30))(piVar11);
  (this->mFieldAccel).x = (float)((double)(param_1->mFieldVel).x * dVar13);
  (this->mFieldAccel).y = (float)((double)(param_1->mFieldVel).y * dVar13);
  (this->mFieldAccel).z = (float)((double)(param_1->mFieldVel).z * dVar13);
  dVar13 = (double)(**(code **)(*piVar11 + 0x3c))(piVar11);
  fVar1 = JPABase::_2648;
  (this->mAccel).x = JPABase::_2648;
  (this->mAccel).y = (float)-dVar13;
  (this->mAccel).z = fVar1;
  this->mAirResist = param_1->mAirResist;
  this->mMoment = param_1->mMoment;
  this->mCurFrame = JPABase::_2654;
  sVar9 = (**(code **)(*piVar11 + 0x1c))(piVar11);
  uStack68 = (int)sVar9 ^ 0x80000000;
  local_48 = 0x43300000;
  this->mLifeTime = (float)((double)CONCAT44(0x43300000,uStack68) - JPABase::_2656);
  this->mCurNormTime = JPABase::_2648;
  (this->mFieldVel).x = (this->mFieldAccel).x;
  (this->mFieldVel).y = (this->mFieldAccel).y;
  (this->mFieldVel).z = (this->mFieldAccel).z;
  fVar5 = this->mMoment * this->mDrag;
  fVar1 = (this->mBaseVel).z;
  fVar2 = (this->mFieldVel).z;
  fVar3 = (this->mBaseVel).y;
  fVar4 = (this->mFieldVel).y;
  (this->mVelocity).x = fVar5 * ((this->mBaseVel).x + (this->mFieldVel).x);
  (this->mVelocity).y = fVar5 * (fVar3 + fVar4);
  (this->mVelocity).z = fVar5 * (fVar1 + fVar2);
  if ((pJVar6->mDataFlag & 0x10U) != 0) {
    this->mFlags = this->mFlags | 0x20;
  }
  (this->mGlobalPosition).x = (param_1->mGlobalPosition).x;
  (this->mGlobalPosition).y = (param_1->mGlobalPosition).y;
  (this->mGlobalPosition).z = (param_1->mGlobalPosition).z;
  (this->mLocalPosition).x = (param_1->mLocalPosition).x;
  (this->mLocalPosition).y = (param_1->mLocalPosition).y;
  (this->mLocalPosition).z = (param_1->mLocalPosition).z;
  dVar13 = (double)(**(code **)(*piVar11 + 0x2c))(piVar11);
  if ((double)JPABase::_2648 != dVar13) {
    (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
    uVar10 = (pJVar6->mRandomSeed).v;
    (pJVar6->mRandomSeed).v = uVar10 * 0x19660d + 0x3c6ef35f;
    JPABase::JPAGetUnitVec
              ((int)(short)((pJVar6->mRandomSeed).v >> 0x10),(int)(short)(uVar10 >> 0x10),&local_54)
    ;
    (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
    fVar1 = (float)(dVar13 * (double)((float)((pJVar6->mRandomSeed).v >> 9 | 0x3f800000) -
                                     JPABase::_2649));
    (this->mLocalPosition).x = (this->mLocalPosition).x + local_54 * fVar1;
    (this->mLocalPosition).y = (this->mLocalPosition).y + local_50 * fVar1;
    (this->mLocalPosition).z = (this->mLocalPosition).z + local_4c * fVar1;
  }
  this->mpCallBack2 = pJVar6->mpParticleCallBack;
  *(undefined4 *)&this->field_0xd0 = *(undefined4 *)&param_1->field_0xd0;
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  __psq_l0(auStack24,uVar12);
  __psq_l1(auStack24,uVar12);
  __psq_l0(auStack40,uVar12);
  __psq_l1(auStack40,uVar12);
  return;
}


/* __thiscall JPABaseParticle::incFrame(void) */

void __thiscall JPABaseParticle::incFrame(JPABaseParticle *this)

{
  this->mCurFrame = this->mCurFrame + JPABase::_2649;
  if (this->mCurFrame < JPABase::_2648) {
    this->mCurFrame = JPABase::_2648;
  }
  this->mFlags = this->mFlags & 0xfffffffe;
  if (this->mLifeTime <= this->mCurFrame) {
    this->mCurNormTime = JPABase::_2649;
    this->mFlags = this->mFlags | 2;
    return;
  }
  this->mCurNormTime = this->mCurFrame / this->mLifeTime;
  return;
}


/* __thiscall JPABaseParticle::calcVelocity(void) */

void __thiscall JPABaseParticle::calcVelocity(JPABaseParticle *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar1 = JPABase::_2648;
  (this->mFieldVel).z = JPABase::_2648;
  (this->mFieldVel).y = fVar1;
  (this->mFieldVel).x = fVar1;
  if ((this->mFlags & 0x20) != 0) {
    (this->mGlobalPosition).x = JPABaseEmitter::emtrInfo.mEmitterGlobalCenterPos.x;
    (this->mGlobalPosition).y = JPABaseEmitter::emtrInfo.mEmitterGlobalCenterPos.y;
    (this->mGlobalPosition).z = JPABaseEmitter::emtrInfo.mEmitterGlobalCenterPos.z;
  }
  (this->mBaseVel).x = (this->mBaseVel).x + (this->mAccel).x;
  (this->mBaseVel).y = (this->mBaseVel).y + (this->mAccel).y;
  (this->mBaseVel).z = (this->mBaseVel).z + (this->mAccel).z;
  if ((this->mFlags & 0x40) == 0) {
    JPAFieldManager::calc(&(JPABaseEmitter::emtrInfo.mpCurEmitter)->mFieldManager,this);
  }
  (this->mFieldVel).x = (this->mFieldVel).x + (this->mFieldAccel).x;
  (this->mFieldVel).y = (this->mFieldVel).y + (this->mFieldAccel).y;
  (this->mFieldVel).z = (this->mFieldVel).z + (this->mFieldAccel).z;
  fVar1 = this->mAirResist;
  (this->mBaseVel).x = (this->mBaseVel).x * fVar1;
  (this->mBaseVel).y = (this->mBaseVel).y * fVar1;
  (this->mBaseVel).z = (this->mBaseVel).z * fVar1;
  fVar5 = this->mMoment * this->mDrag;
  fVar1 = (this->mBaseVel).z;
  fVar2 = (this->mFieldVel).z;
  fVar3 = (this->mBaseVel).y;
  fVar4 = (this->mFieldVel).y;
  (this->mVelocity).x = fVar5 * ((this->mBaseVel).x + (this->mFieldVel).x);
  (this->mVelocity).y = fVar5 * (fVar3 + fVar4);
  (this->mVelocity).z = fVar5 * (fVar1 + fVar2);
  return;
}


/* __thiscall JPABaseParticle::calcPosition(void) */

void __thiscall JPABaseParticle::calcPosition(JPABaseParticle *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  (this->mLocalPosition).x = (this->mLocalPosition).x + (this->mVelocity).x;
  (this->mLocalPosition).y = (this->mLocalPosition).y + (this->mVelocity).y;
  (this->mLocalPosition).z = (this->mLocalPosition).z + (this->mVelocity).z;
  fVar1 = (this->mGlobalPosition).z;
  fVar3 = (this->mLocalPosition).z * JPABaseEmitter::emtrInfo.mPublicScale.z;
  fVar2 = (this->mGlobalPosition).y;
  fVar4 = (this->mLocalPosition).y * JPABaseEmitter::emtrInfo.mPublicScale.y;
  (this->mPosition).x =
       (this->mGlobalPosition).x +
       (this->mLocalPosition).x * JPABaseEmitter::emtrInfo.mPublicScale.x;
  (this->mPosition).y = fVar2 + fVar4;
  (this->mPosition).z = fVar1 + fVar3;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8025ee24) */
/* __thiscall JPABaseParticle::checkCreateChild(void) */

undefined4 __thiscall JPABaseParticle::checkCreateChild(JPABaseParticle *this)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  piVar4 = (int *)(JPABaseEmitter::emtrInfo.mpCurEmitter)->mpDataLinkInfo->mpSweepShapeBlock;
  uVar3 = 0;
  dVar7 = (double)JPABase::_2649;
  if (dVar7 < (double)this->mLifeTime) {
    dVar7 = (double)(this->mCurFrame / (float)((double)this->mLifeTime - dVar7));
  }
  dVar6 = (double)(**(code **)(*piVar4 + 0x24))(piVar4);
  if (dVar6 <= dVar7) {
    dVar7 = (double)this->mCurFrame;
    uVar1 = (**(code **)(*piVar4 + 0x28))(piVar4);
    iVar2 = (uVar1 & 0xff) + 1;
    if ((int)dVar7 == ((int)dVar7 / iVar2) * iVar2) {
      uVar3 = 1;
    }
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return uVar3;
}

