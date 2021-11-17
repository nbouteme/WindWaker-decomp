#include <J3DU/J3DUClipper.h>
#include <MSL_C.PPCEABI.bare.H/s_tan.h>
#include <mtx/vec.h>
#include <mtx/mtxvec.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <mtx/mtx.h>
#include <J3DU/J3DUClipper.h>
#include <J3DUClipper.h>


/* __thiscall J3DUClipper::init(void) */

int __thiscall J3DUClipper::init(J3DUClipper *this,EVP_PKEY_CTX *ctx)

{
  this->mNear = J3DU::_1520;
  this->mFar = J3DU::_1521;
  return (int)this;
}


/* __thiscall J3DUClipper::calcViewFrustum(void) */

void __thiscall J3DUClipper::calcViewFrustum(J3DUClipper *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  double dVar8;
  float n;
  
  dVar8 = MSL_C.PPCEABI.bare.H::tan((double)(J3DU::Deg2Rad * J3DU::0_5 * this->mFovY));
  n = this->mNear * (float)dVar8;
  fVar2 = this->mAspect * n;
  fVar5 = -fVar2;
  fVar3 = -n;
  fVar1 = -this->mNear;
  fVar4 = n * fVar1;
  fVar6 = fVar1 * fVar3;
  (this->field_0x4).x = fVar4 - fVar6;
  fVar7 = fVar1 * fVar5;
  (this->field_0x4).y = fVar7 - fVar7;
  (this->field_0x4).z = fVar5 * fVar3 - n * fVar5;
  (this->field_0x10).x = fVar4 - fVar4;
  fVar1 = fVar2 * fVar1;
  (this->field_0x10).y = fVar7 - fVar1;
  (this->field_0x10).z = fVar2 * n - n * fVar5;
  (this->field_0x1c).x = fVar6 - fVar4;
  (this->field_0x1c).y = fVar1 - fVar1;
  (this->field_0x1c).z = fVar2 * n - fVar3 * fVar2;
  (this->field_0x28).x = fVar6 - fVar6;
  (this->field_0x28).y = fVar1 - fVar7;
  (this->field_0x28).z = fVar5 * fVar3 - fVar3 * fVar2;
  mtx::PSVECNormalize(&this->field_0x4,&this->field_0x4);
  mtx::PSVECNormalize(&this->field_0x10,&this->field_0x10);
  mtx::PSVECNormalize(&this->field_0x1c,&this->field_0x1c);
  mtx::PSVECNormalize(&this->field_0x28,&this->field_0x28);
  return;
}


/* WARNING: Removing unreachable block (ram,0x802569b4) */
/* __thiscall J3DUClipper::clip(float const *[][][][],
                                Vec,
                                float) */

uint __thiscall J3DUClipper::clip(J3DUClipper *this,MTX34 *pMtx,cXyz *pPos,float rad)

{
  uint uVar1;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  cXyz local_28;
  undefined auStack8 [8];
  
  dVar3 = (double)rad;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  mtx::PSMTXMultVec(pMtx,pPos,&local_28);
  if ((float)((double)this->mNear - dVar3) <= -local_28.z) {
    if (-local_28.z <= (float)((double)this->mFar + dVar3)) {
      if ((double)(local_28.z * (this->field_0x4).z +
                  local_28.x * (this->field_0x4).x + local_28.y * (this->field_0x4).y) <= dVar3) {
        if ((double)(local_28.z * (this->field_0x10).z +
                    local_28.x * (this->field_0x10).x + local_28.y * (this->field_0x10).y) <= dVar3)
        {
          if ((double)(local_28.z * (this->field_0x1c).z +
                      local_28.x * (this->field_0x1c).x + local_28.y * (this->field_0x1c).y) <=
              dVar3) {
            uVar1 = ((uint)(byte)((dVar3 < (double)(local_28.z * (this->field_0x28).z +
                                                   local_28.x * (this->field_0x28).x +
                                                   local_28.y * (this->field_0x28).y)) << 2) << 0x1c
                    ) >> 0x1e;
          }
          else {
            uVar1 = 1;
          }
        }
        else {
          uVar1 = 1;
        }
      }
      else {
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 1;
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x80256c98) */
/* __thiscall J3DUClipper::clip(float const *[][][][],
                                Vec *,
                                Vec *) */

uint __thiscall J3DUClipper::clip(J3DUClipper *this,MTX34 *param_1,cXyz *param_2,cXyz *param_3)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  cXyz local_a8;
  int local_9c [6];
  TVec3_float_ local_84 [8];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar1 = 0;
  iVar4 = 6;
  do {
    *(undefined4 *)((int)local_9c + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  local_84[0].x = param_3->x;
  local_84[0].y = param_3->y;
  local_84[0].z = param_2->z;
  local_84[1].z = param_3->z;
  local_84[2].x = param_2->x;
  local_84[4].y = param_2->y;
  uVar2 = 0;
  iVar1 = 0;
  dVar6 = (double)J3DU::_1635;
  local_84[1].x = local_84[0].x;
  local_84[1].y = local_84[0].y;
  local_84[2].y = local_84[0].y;
  local_84[2].z = local_84[1].z;
  local_84[3].x = local_84[2].x;
  local_84[3].y = local_84[0].y;
  local_84[3].z = local_84[0].z;
  local_84[4].x = local_84[0].x;
  local_84[4].z = local_84[0].z;
  local_84[5].x = local_84[0].x;
  local_84[5].y = local_84[4].y;
  local_84[5].z = local_84[1].z;
  local_84[6].x = local_84[2].x;
  local_84[6].y = local_84[4].y;
  local_84[6].z = local_84[1].z;
  local_84[7].x = local_84[2].x;
  local_84[7].y = local_84[4].y;
  local_84[7].z = local_84[0].z;
  while( true ) {
    mtx::PSMTXMultVec(param_1,(cXyz *)((int)&local_84[0].x + iVar1),&local_a8);
    cVar3 = -local_a8.z < this->mNear;
    if ((bool)cVar3) {
      local_9c[4] = local_9c[4] + 1;
    }
    if (this->mFar < -local_a8.z) {
      local_9c[5] = local_9c[5] + 1;
      cVar3 = cVar3 + '\x01';
    }
    if (dVar6 < (double)(local_a8.z * (this->field_0x4).z +
                        local_a8.x * (this->field_0x4).x + local_a8.y * (this->field_0x4).y)) {
      local_9c[0] = local_9c[0] + 1;
      cVar3 = cVar3 + '\x01';
    }
    if (dVar6 < (double)(local_a8.z * (this->field_0x10).z +
                        local_a8.x * (this->field_0x10).x + local_a8.y * (this->field_0x10).y)) {
      local_9c[1] = local_9c[1] + 1;
      cVar3 = cVar3 + '\x01';
    }
    if (dVar6 < (double)(local_a8.z * (this->field_0x1c).z +
                        local_a8.x * (this->field_0x1c).x + local_a8.y * (this->field_0x1c).y)) {
      local_9c[2] = local_9c[2] + 1;
      cVar3 = cVar3 + '\x01';
    }
    if (dVar6 < (double)(local_a8.z * (this->field_0x28).z +
                        local_a8.x * (this->field_0x28).x + local_a8.y * (this->field_0x28).y)) {
      local_9c[3] = local_9c[3] + 1;
      cVar3 = cVar3 + '\x01';
    }
    if (cVar3 == '\0') break;
    uVar2 = uVar2 + 1;
    iVar1 = iVar1 + 0xc;
    if (7 < uVar2) {
      if (local_9c[0] == 8) {
        uVar2 = 1;
      }
      else {
        if (local_9c[2] == 8) {
          uVar2 = 1;
        }
        else {
          if (local_9c[1] == 8) {
            uVar2 = 1;
          }
          else {
            if (local_9c[3] == 8) {
              uVar2 = 1;
            }
            else {
              if (local_9c[4] == 8) {
                uVar2 = 1;
              }
              else {
                uVar2 = countLeadingZeros(8 - local_9c[5]);
                uVar2 = uVar2 >> 5;
              }
            }
          }
        }
      }
LAB_80256c98:
      __psq_l0(auStack8,uVar5);
      __psq_l1(auStack8,uVar5);
      return uVar2;
    }
  }
  uVar2 = 0;
  goto LAB_80256c98;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall J3DUClipper::clipByBox(J3DModel *) */

int __thiscall J3DUClipper::clipByBox(J3DUClipper *this,J3DModel *pModel)

{
  uint clipRes;
  J3DMaterial *pMat;
  J3DJoint *pJoint;
  ushort idx;
  int iVar1;
  J3DModelData *pModelData;
  MTX34 mtx;
  
  iVar1 = 0;
  pModelData = pModel->mpModelData;
  for (idx = 0; idx < (ushort)(pModelData->mJointTree).mJointCount; idx = idx + 1) {
    pJoint = (pModelData->mJointTree).mpJoints[idx];
    if ((pJoint->mMtxTypeFlags & 0xf) == 0) {
      ::mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,pModel->mpNodeMtx + idx,&mtx);
      clipRes = clip(this,&mtx,&pJoint->mBBoxMax,&pJoint->mBBoxMin);
      pMat = (pModelData->mJointTree).mpJoints[idx]->mpMaterial;
      if (clipRes == 0) {
        for (; pMat != (J3DMaterial *)0x0; pMat = pMat->mpNextMaterial) {
          pMat->mpShape->mVisFlags = pMat->mpShape->mVisFlags & 0xfffffffe;
        }
      }
      else {
        for (; pMat != (J3DMaterial *)0x0; pMat = pMat->mpNextMaterial) {
          pMat->mpShape->mVisFlags = pMat->mpShape->mVisFlags | 1;
          iVar1 = iVar1 + 1;
        }
      }
    }
  }
  return iVar1;
}

