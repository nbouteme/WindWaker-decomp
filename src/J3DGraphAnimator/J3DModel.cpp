#include <J3DGraphAnimator/J3DModel.h>
#include <J3DGraphBase/J3DVertex.h>
#include <J3DGraphAnimator/J3DModel.h>
#include <JKernel/JKRHeap.h>
#include <mtx/mtx.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J3DGraphBase/J3DPacket.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <J3DGraphBase/J3DMaterial.h>
#include <J3DGraphBase/J3DShape.h>
#include <J3DGraphAnimator/J3DCluster.h>
#include <J3DGraphBase/J3DTransform.h>
#include <os/OSCache.h>
#include <Demangler/J3DModel.h>


namespace J3DModel {
}

namespace J3DGraphAnimator {
}

namespace J3DModel {
undefined1 sNoUseDrawMtx;
undefined1 sNoUseNrmMtx;
}

/* __thiscall J3DModel::J3DModel(void) */

void __thiscall J3DModel::J3DModel(J3DModel *this)

{
  EVP_PKEY_CTX *in_r4;
  
  this->vtbl = (J3DModel__vtbl *)&__vt;
  J3DVertexBuffer::init(&this->mVertexBuffer,in_r4);
  initialize(this);
  return;
}


/* __thiscall J3DModel::~J3DModel(void) */

void __thiscall J3DModel::_J3DModel(J3DModel *this)

{
  short in_r4;
  
  if (this != (J3DModel *)0x0) {
    this->vtbl = (J3DModel__vtbl *)&__vt;
    J3DVertexBuffer::_J3DVertexBuffer(&this->mVertexBuffer);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DModel::initialize(void) */

void __thiscall J3DModel::initialize(J3DModel *this)

{
  float fVar1;
  
  this->mpModelData = (J3DModelData *)0x0;
  this->mFlags = 0;
  this->field_0xc = 0;
  this->field_0x10 = (undefined *)0x0;
  this->mpUserData = (void *)0x0;
  fVar1 = J3DGraphAnimator::_1516;
  (this->mBaseScale).x = J3DGraphAnimator::_1516;
  (this->mBaseScale).y = fVar1;
  (this->mBaseScale).z = fVar1;
  mtx::PSMTXIdentity(&this->mBaseMtx);
  mtx::PSMTXIdentity(&this->mInternalView);
  this->field_0x84 = (byte *)0x0;
  this->field_0x88 = (undefined *)0x0;
  this->mpNodeMtx = (MTX34 *)0x0;
  this->mpWeightEnvMtx = (MTX34 *)0x0;
  this->field_0x94 = (undefined *)0x0;
  this->mpDrawMtxBuf = (undefined *)0x0;
  this->field_0x9c = (undefined *)0x0;
  this->mpNrmMtxBuf = (undefined *)0x0;
  *(undefined4 *)&this->field_0xa4 = 0;
  *(undefined4 *)&this->field_0xa8 = 0;
  this->mMtxBufferFlags = 1;
  this->mDrawIdxStart = 0;
  this->mpMatPackets = (J3DMatPacket *)0x0;
  this->mpShapePackets = (J3DShapePacket *)0x0;
  this->mpDeformData = (J3DDeformData *)0x0;
  this->mpSkinDeform = (J3DSkinDeform *)0x0;
  *(undefined4 *)&this->field_0xc4 = 0;
  *(undefined4 *)&this->field_0xc8 = 0;
  this->mpVisibilityManager = (J3DVisibilityManager *)0x0;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DModel::entryModelData(J3DModelData *,
                                       unsigned long,
                                       unsigned long) */

int __thiscall
J3DModel::entryModelData(J3DModel *this,J3DModelData *param_1,ulong param_2,ulong param_3)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  byte *pbVar4;
  undefined *puVar5;
  MTX34 *pMVar6;
  int iVar7;
  
  iVar7 = 0;
  this->mpModelData = param_1;
  this->mMtxBufferFlags = param_3;
  sVar1 = (param_1->mJointTree).mJointCount;
  if (sVar1 != 0) {
    pbVar4 = (byte *)JKernel::operator_new__(sVar1);
    this->field_0x84 = pbVar4;
    sVar1 = (param_1->mJointTree).mEnvelopeCount;
    if (sVar1 != 0) {
      puVar5 = (undefined *)JKernel::operator_new__(sVar1);
      this->field_0x88 = puVar5;
    }
    pMVar6 = (MTX34 *)JKernel::operator_new__
                                ((uint)(ushort)(param_1->mJointTree).mJointCount * 0x30);
    this->mpNodeMtx = pMVar6;
  }
  uVar2 = (param_1->mJointTree).mEnvelopeCount;
  if (uVar2 != 0) {
    pMVar6 = (MTX34 *)JKernel::operator_new__((uint)uVar2 * 0x30);
    this->mpWeightEnvMtx = pMVar6;
  }
  if (this->field_0x84 == (byte *)0x0) {
    iVar7 = 4;
  }
  else {
    sVar1 = (param_1->mJointTree).mEnvelopeCount;
    if ((sVar1 == 0) || (this->field_0x88 != (undefined *)0x0)) {
      if (this->mpNodeMtx == (MTX34 *)0x0) {
        iVar7 = 4;
      }
      else {
        if ((sVar1 == 0) || (this->mpWeightEnvMtx != (MTX34 *)0x0)) {
          if (((uint)param_1->mLoadArgs >> 8 & 1) == 0) {
            uVar3 = param_1->mLoadArgs & 0xf0;
            if (uVar3 == 0x10) {
              iVar7 = createSingleDrawMtx(this,param_1);
            }
            else {
              if ((uVar3 < 0x10) || (uVar3 != 0x20)) {
                iVar7 = createDoubleDrawMtx(this,param_1,param_3);
              }
              else {
                iVar7 = setNoUseDrawMtx(this);
              }
            }
          }
          else {
            setNoUseDrawMtx(this);
          }
          if (((iVar7 == 0) && (iVar7 = createShapePacket(this,param_1), iVar7 == 0)) &&
             (iVar7 = createMatPacket(this,param_1,param_2), iVar7 == 0)) {
            if ((param_1->mLoadArgs & 0x10U) == 0) {
              iVar7 = createBumpMtxArray(this,param_1,param_3);
              if (iVar7 != 0) {
                return iVar7;
              }
            }
            else {
              this->mpModelData->field_0xc = 0;
            }
            J3DVertexBuffer::setVertexData(&this->mVertexBuffer,&param_1->mVertexData);
            prepareShapePackets(this);
            iVar7 = 0;
          }
        }
        else {
          iVar7 = 4;
        }
      }
    }
    else {
      iVar7 = 4;
    }
  }
  return iVar7;
}


/* __thiscall J3DModel::setNoUseDrawMtx(void) */

undefined4 __thiscall J3DModel::setNoUseDrawMtx(J3DModel *this)

{
  this->mpDrawMtxBuf = (undefined *)&sNoUseDrawMtxPtr;
  this->field_0x94 = (undefined *)&sNoUseDrawMtxPtr;
  this->mpNrmMtxBuf = (undefined *)&sNoUseNrmMtxPtr;
  this->field_0x9c = (undefined *)&sNoUseNrmMtxPtr;
  *(undefined4 *)&this->field_0xa8 = 0;
  *(undefined4 *)&this->field_0xa4 = 0;
  return 0;
}


/* __thiscall J3DModel::createSingleDrawMtx(J3DModelData *) */

undefined4 __thiscall J3DModel::createSingleDrawMtx(J3DModel *this,J3DModelData *param_1)

{
  ushort uVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  puVar2 = (undefined *)JKernel::operator_new__(4);
  this->field_0x94 = puVar2;
  this->mpDrawMtxBuf = this->field_0x94;
  puVar2 = (undefined *)JKernel::operator_new__(4);
  this->field_0x9c = puVar2;
  this->mpNrmMtxBuf = this->field_0x9c;
  *(undefined4 *)&this->field_0xa4 = 0;
  *(undefined4 *)&this->field_0xa8 = 0;
  if (this->field_0x94 == (undefined *)0x0) {
    uVar3 = 4;
  }
  else {
    if (this->field_0x9c == (undefined *)0x0) {
      uVar3 = 4;
    }
    else {
      uVar1 = (param_1->mJointTree).mDrawMtxData.mDrawMtxCount;
      if (uVar1 != 0) {
        uVar3 = JKernel::operator_new__((uint)uVar1 * 0x30,0x20);
        *(undefined4 *)this->field_0x94 = uVar3;
        *(undefined4 *)this->mpDrawMtxBuf = *(undefined4 *)this->field_0x94;
        uVar3 = JKernel::operator_new__(0x24,0x20);
        *(undefined4 *)this->field_0x9c = uVar3;
        *(undefined4 *)this->mpNrmMtxBuf = *(undefined4 *)this->field_0x9c;
      }
      if (((param_1->mJointTree).mDrawMtxData.mDrawMtxCount == 0) || (*(int *)this->field_0x94 != 0)
         ) {
        uVar3 = 0;
      }
      else {
        uVar3 = 4;
      }
    }
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall J3DModel::createDoubleDrawMtx(J3DModelData *,
                                            unsigned long) */

undefined4 __thiscall
J3DModel::createDoubleDrawMtx(J3DModel *this,J3DModelData *param_1,ulong param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  ulong uVar8;
  
  if (param_2 != 0) {
    iVar4 = 0;
    iVar6 = 0;
    do {
      uVar2 = JKernel::operator_new__(param_2 << 2);
      iVar3 = (int)&this->vtbl + iVar6;
      *(undefined4 *)(iVar3 + 0x94) = uVar2;
      uVar2 = JKernel::operator_new__(param_2 << 2);
      *(undefined4 *)(iVar3 + 0x9c) = uVar2;
      *(undefined4 *)(iVar3 + 0xa4) = 0;
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + 4;
    } while (iVar4 < 2);
  }
  if (param_2 != 0) {
    iVar4 = 0;
    iVar6 = 2;
    do {
      iVar3 = (int)&this->vtbl + iVar4;
      if (*(int *)(iVar3 + 0x94) == 0) {
        return 4;
      }
      if (*(int *)(iVar3 + 0x9c) == 0) {
        return 4;
      }
      iVar4 = iVar4 + 4;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  iVar4 = 0;
  iVar6 = 0;
  do {
    iVar7 = 0;
    iVar3 = (int)&this->vtbl + iVar6;
    for (uVar5 = 0; uVar5 < param_2; uVar5 = uVar5 + 1) {
      uVar1 = (param_1->mJointTree).mDrawMtxData.mDrawMtxCount;
      if (uVar1 != 0) {
        uVar2 = JKernel::operator_new__((uint)uVar1 * 0x30,0x20);
        *(undefined4 *)(*(int *)(iVar3 + 0x94) + iVar7) = uVar2;
        uVar2 = JKernel::operator_new__
                          ((uint)(ushort)(param_1->mJointTree).mDrawMtxData.mDrawMtxCount * 0x24,
                           0x20);
        *(undefined4 *)(*(int *)(iVar3 + 0x9c) + iVar7) = uVar2;
      }
      iVar7 = iVar7 + 4;
    }
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 4;
  } while (iVar4 < 2);
  iVar6 = 0;
  iVar4 = 0;
  do {
    iVar3 = 0;
    iVar7 = (int)&this->vtbl + iVar4;
    uVar8 = param_2;
    if (param_2 != 0) {
      do {
        if ((param_1->mJointTree).mDrawMtxData.mDrawMtxCount != 0) {
          if (*(int *)(*(int *)(iVar7 + 0x94) + iVar3) == 0) {
            return 4;
          }
          if (*(int *)(*(int *)(iVar7 + 0x9c) + iVar3) == 0) {
            return 4;
          }
        }
        iVar3 = iVar3 + 4;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
    iVar6 = iVar6 + 1;
    iVar4 = iVar4 + 4;
    if (1 < iVar6) {
      return 0;
    }
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DModel::createShapePacket(J3DModelData *) */

undefined4 __thiscall J3DModel::createShapePacket(J3DModel *this,J3DModelData *param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  J3DShapePacket *pJVar3;
  int iVar4;
  uint idx;
  
  uVar1 = (param_1->mShapeTable).mShapeCount;
  if (uVar1 != 0) {
    uVar2 = JKernel::operator_new__((uint)uVar1 * 0x44 + 0x10);
    pJVar3 = (J3DShapePacket *)
             Runtime.PPCEABI.H::__construct_new_array
                       (uVar2,J3DShapePacket::J3DShapePacket,J3DShapePacket::_J3DShapePacket,0x44,
                        (uint)uVar1);
    this->mpShapePackets = pJVar3;
    if (this->mpShapePackets == (J3DShapePacket *)0x0) {
      return 4;
    }
    iVar4 = 0;
    for (idx = 0; (int)idx < (int)(uint)(param_1->mShapeTable).mShapeCount; idx = idx + 1) {
      *(J3DShape **)((int)&this->mpShapePackets->mpShape + iVar4) =
           (param_1->mShapeTable).mpShapes[idx & 0xffff];
      *(J3DModel **)((int)&this->mpShapePackets->mpModel + iVar4) = this;
      iVar4 = iVar4 + 0x44;
    }
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __thiscall J3DModel::createMatPacket(J3DModelData *,
                                        unsigned long) */

int __thiscall J3DModel::createMatPacket(J3DModel *this,J3DModelData *param_1,ulong param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  J3DMatPacket *pJVar5;
  J3DShapePacket *pJVar6;
  int iVar7;
  ulong uVar8;
  J3DMaterial *pJVar9;
  int iVar10;
  uint uVar11;
  J3DDisplayListObj *pJVar12;
  
  uVar1 = (param_1->mMaterialTable).mMaterialCount;
  if (uVar1 != 0) {
    uVar4 = JKernel::operator_new__((uint)uVar1 * 0x3c + 0x10);
    pJVar5 = (J3DMatPacket *)
             Runtime.PPCEABI.H::__construct_new_array
                       (uVar4,J3DMatPacket::J3DMatPacket,J3DMatPacket::_J3DMatPacket,0x3c,
                        (uint)uVar1);
    this->mpMatPackets = pJVar5;
    if (this->mpMatPackets == (J3DMatPacket *)0x0) {
      return 4;
    }
  }
  uVar11 = 0;
  iVar10 = 0;
  uVar2 = param_2 & 0x40000;
  do {
    if ((int)(uint)(param_1->mMaterialTable).mMaterialCount <= (int)uVar11) {
      return 0;
    }
    uVar3 = uVar11 & 0xffff;
    *(J3DMaterial **)((int)&this->mpMatPackets->mpMaterial + iVar10) =
         (param_1->mMaterialTable).mpMaterials[uVar3];
    uVar1 = (param_1->mMaterialTable).mpMaterials[uVar3]->mpShape->mShapeIdx;
    pJVar6 = this->mpShapePackets;
    *(J3DShapePacket **)((int)&this->mpMatPackets->mpShapePacket + iVar10) = pJVar6 + uVar1;
    J3DMatPacket::addShapePacket
              ((J3DMatPacket *)((int)&(this->mpMatPackets->parent).parent.vtbl + iVar10),
               pJVar6 + uVar1);
    *(J3DTexture **)((int)&this->mpMatPackets->mpTexture + iVar10) =
         (param_1->mMaterialTable).mpTexture;
    *(uint *)((int)&this->mpMatPackets->mSortFlags + iVar10) =
         (param_1->mMaterialTable).mpMaterials[uVar3]->field_0x20;
    if ((param_1->mJointTree).mbIsBDL == 1) {
      *(uint *)((int)&(this->mpMatPackets->parent).mFlags + iVar10) =
           *(uint *)((int)&(this->mpMatPackets->parent).mFlags + iVar10) | 1;
    }
    if ((param_2 & 0x80000) == 0) {
      if ((param_1->mJointTree).mbIsBDL == 1) {
        if (uVar2 == 0) {
          pJVar12 = (param_1->mMaterialTable).mpMaterials[uVar3]->mpDLObj;
          iVar7 = J3DDisplayListObj::single_To_Double(pJVar12);
          if (iVar7 != 0) {
            return iVar7;
          }
          *(J3DDisplayListObj **)((int)&(this->mpMatPackets->parent).mpDLObj + iVar10) = pJVar12;
        }
        else {
          *(J3DDisplayListObj **)((int)&(this->mpMatPackets->parent).mpDLObj + iVar10) =
               (param_1->mMaterialTable).mpMaterials[uVar3]->mpDLObj;
        }
      }
      else {
        if ((param_2 & 0x20000) == 0) {
          if (uVar2 == 0) {
            uVar8 = J3DMaterial::countDLSize((param_1->mMaterialTable).mpMaterials[uVar3]);
            iVar7 = J3DDrawPacket::newDisplayList
                              ((J3DDrawPacket *)
                               ((int)&(this->mpMatPackets->parent).parent.vtbl + iVar10),uVar8);
          }
          else {
            uVar8 = J3DMaterial::countDLSize((param_1->mMaterialTable).mpMaterials[uVar3]);
            iVar7 = J3DDrawPacket::newSingleDisplayList
                              ((J3DDrawPacket *)
                               ((int)&(this->mpMatPackets->parent).parent.vtbl + iVar10),uVar8);
          }
          if (iVar7 != 0) {
            return iVar7;
          }
        }
        else {
          if (uVar2 == 0) {
            pJVar9 = (param_1->mMaterialTable).mpMaterials[uVar3];
            uVar8 = J3DMaterial::countDLSize(pJVar9);
            iVar7 = J3DMaterial::newSharedDisplayList(pJVar9,uVar8);
            if (iVar7 != 0) {
              return iVar7;
            }
            pJVar12 = (param_1->mMaterialTable).mpMaterials[uVar3]->mpDLObj;
            iVar7 = J3DDisplayListObj::single_To_Double(pJVar12);
            if (iVar7 != 0) {
              return iVar7;
            }
            *(J3DDisplayListObj **)((int)&(this->mpMatPackets->parent).mpDLObj + iVar10) = pJVar12;
          }
          else {
            pJVar9 = (param_1->mMaterialTable).mpMaterials[uVar3];
            uVar8 = J3DMaterial::countDLSize(pJVar9);
            iVar7 = J3DMaterial::newSingleSharedDisplayList(pJVar9,uVar8);
            if (iVar7 != 0) {
              return iVar7;
            }
            *(J3DDisplayListObj **)((int)&(this->mpMatPackets->parent).mpDLObj + iVar10) =
                 (param_1->mMaterialTable).mpMaterials[uVar3]->mpDLObj;
          }
        }
      }
    }
    else {
      *(J3DDisplayListObj **)((int)&(this->mpMatPackets->parent).mpDLObj + iVar10) =
           (param_1->mMaterialTable).mpMaterials[uVar3]->mpDLObj;
    }
    uVar11 = uVar11 + 1;
    iVar10 = iVar10 + 0x3c;
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* __thiscall J3DModel::createBumpMtxArray(J3DModelData *,
                                           unsigned long) */

undefined4 __thiscall
J3DModel::createBumpMtxArray(J3DModel *this,J3DModelData *param_1,ulong param_2)

{
  short sVar3;
  undefined4 uVar1;
  char *pcVar2;
  short sVar6;
  J3DMaterial *pJVar4;
  uint uVar5;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined *puVar12;
  ushort uVar13;
  
  if ((param_1->mJointTree).mbIsBDL == 0) {
    sVar6 = 0;
    uVar13 = 0;
    for (uVar9 = 0; (int)uVar9 < (int)(uint)(param_1->mMaterialTable).mMaterialCount;
        uVar9 = uVar9 + 1) {
      pJVar4 = (this->mpModelData->mMaterialTable).mpMaterials[uVar9 & 0xffff];
      pcVar2 = (char *)(*(code *)pJVar4->mpTexGenBlock->vtbl->getNBTScale)();
      if (*pcVar2 == '\x01') {
        sVar3 = J3DShape::countBumpMtxNum(pJVar4->mpShape);
        sVar6 = sVar6 + sVar3;
        uVar13 = uVar13 + 1;
      }
    }
    if ((sVar6 != 0) && (param_2 != 0)) {
      iVar10 = 0;
      iVar7 = 0;
      do {
        uVar1 = JKernel::operator_new__((uint)uVar13 << 2);
        *(undefined4 *)((int)(this->mVertexBuffer).mpTransformedVtxPos + iVar7 + -0x44) = uVar1;
        if (*(int *)((int)(this->mVertexBuffer).mpTransformedVtxPos + iVar7 + -0x44) == 0) {
          return 4;
        }
        iVar10 = iVar10 + 1;
        iVar7 = iVar7 + 4;
      } while (iVar10 < 2);
    }
    iVar10 = 0;
    iVar7 = 0;
    do {
      puVar12 = (undefined *)0x0;
      iVar8 = 0;
      for (uVar9 = 0; (int)uVar9 < (int)(uint)(param_1->mMaterialTable).mMaterialCount;
          uVar9 = uVar9 + 1) {
        pJVar4 = (this->mpModelData->mMaterialTable).mpMaterials[uVar9 & 0xffff];
        pcVar2 = (char *)(*(code *)pJVar4->mpTexGenBlock->vtbl->getNBTScale)();
        if (*pcVar2 == '\x01') {
          uVar1 = JKernel::operator_new__(param_2 << 2);
          *(undefined4 *)
           (*(int *)((int)(this->mVertexBuffer).mpTransformedVtxPos + iVar7 + -0x44) + iVar8) =
               uVar1;
          if (*(int *)(*(int *)((int)(this->mVertexBuffer).mpTransformedVtxPos + iVar7 + -0x44) +
                      iVar8) == 0) {
            return 4;
          }
          pJVar4->mpShape->field_0x64 = puVar12;
          puVar12 = puVar12 + 1;
          iVar8 = iVar8 + 4;
        }
      }
      iVar10 = iVar10 + 1;
      iVar7 = iVar7 + 4;
    } while (iVar10 < 2);
    iVar7 = 0;
    iVar10 = 0;
    do {
      iVar8 = 0;
      for (uVar9 = 0; (int)uVar9 < (int)(uint)(param_1->mMaterialTable).mMaterialCount;
          uVar9 = uVar9 + 1) {
        pcVar2 = (char *)(*(code *)(this->mpModelData->mMaterialTable).mpMaterials[uVar9 & 0xffff]->
                                   mpTexGenBlock->vtbl->getNBTScale)();
        if (*pcVar2 == '\x01') {
          iVar11 = 0;
          for (uVar5 = 0; uVar5 < param_2; uVar5 = uVar5 + 1) {
            uVar1 = JKernel::operator_new__
                              ((uint)(ushort)(param_1->mJointTree).mDrawMtxData.mDrawMtxCount * 0x24
                               ,0x20);
            *(undefined4 *)
             (*(int *)(iVar8 + *(int *)((int)(this->mVertexBuffer).mpTransformedVtxPos +
                                       iVar10 + -0x44)) + iVar11) = uVar1;
            if (*(int *)(*(int *)(iVar8 + *(int *)((int)(this->mVertexBuffer).mpTransformedVtxPos +
                                                  iVar10 + -0x44)) + iVar11) == 0) {
              return 4;
            }
            iVar11 = iVar11 + 4;
          }
          iVar8 = iVar8 + 4;
        }
      }
      iVar7 = iVar7 + 1;
      iVar10 = iVar10 + 4;
    } while (iVar7 < 2);
    if (uVar13 != 0) {
      this->mpModelData->field_0xc = 1;
    }
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DModel::newDifferedDisplayList(unsigned long) */

int __thiscall J3DModel::newDifferedDisplayList(J3DModel *this,ulong param_1)

{
  int iVar1;
  ushort uVar2;
  
  this->field_0xc = param_1;
  uVar2 = 0;
  while( true ) {
    if ((this->mpModelData->mShapeTable).mShapeCount <= uVar2) {
      return 0;
    }
    iVar1 = J3DShapePacket::newDifferedDisplayList(this->mpShapePackets + uVar2,param_1);
    if (iVar1 != 0) break;
    uVar2 = uVar2 + 1;
  }
  return iVar1;
}


/* __thiscall J3DModel::lock(void) */

void __thiscall J3DModel::lock(J3DModel *this)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)(this->mpModelData->mMaterialTable).mMaterialCount;
  iVar2 = 0;
  if (uVar1 == 0) {
    return;
  }
  do {
    *(uint *)((int)&(this->mpMatPackets->parent).mFlags + iVar2) =
         *(uint *)((int)&(this->mpMatPackets->parent).mFlags + iVar2) | 1;
    iVar2 = iVar2 + 0x3c;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return;
}


/* __thiscall J3DModel::unlock(void) */

void __thiscall J3DModel::unlock(J3DModel *this)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)(this->mpModelData->mMaterialTable).mMaterialCount;
  iVar2 = 0;
  if (uVar1 == 0) {
    return;
  }
  do {
    *(uint *)((int)&(this->mpMatPackets->parent).mFlags + iVar2) =
         *(uint *)((int)&(this->mpMatPackets->parent).mFlags + iVar2) & 0xfffffffe;
    iVar2 = iVar2 + 0x3c;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DModel::calcMaterial(void) */

void __thiscall J3DModel::calcMaterial(J3DModel *this)

{
  J3DMaterialAnm *pJVar1;
  J3DMaterialAnm *pJVar2;
  J3DMaterial *pJVar3;
  ushort uVar4;
  
  J3DGraphBase::j3dSys.mpCurTex = (this->mpModelData->mMaterialTable).mpTexture;
  if ((this->mFlags & 4) == 0) {
    J3DGraphBase::j3dSys.mCurFlags = J3DGraphBase::j3dSys.mCurFlags & 0xfffffffb;
  }
  else {
    J3DGraphBase::j3dSys.mCurFlags = J3DGraphBase::j3dSys.mCurFlags | 4;
  }
  if ((this->mFlags & 8) == 0) {
    J3DGraphBase::j3dSys.mCurFlags = J3DGraphBase::j3dSys.mCurFlags & 0xfffffff7;
  }
  else {
    J3DGraphBase::j3dSys.mCurFlags = J3DGraphBase::j3dSys.mCurFlags | 8;
  }
  J3DGraphBase::j3dSys.mpCurModel = this;
  for (uVar4 = 0; uVar4 < (this->mpModelData->mMaterialTable).mMaterialCount; uVar4 = uVar4 + 1) {
    J3DGraphBase::j3dSys.mpCurMatPacket = this->mpMatPackets + uVar4;
    pJVar3 = (this->mpModelData->mMaterialTable).mpMaterials[uVar4];
    pJVar2 = pJVar3->mpMaterialAnm;
    pJVar1 = pJVar2;
    if ((J3DMaterialAnm *)0xbfffffff < pJVar2) {
      pJVar1 = (J3DMaterialAnm *)0x0;
    }
    if (pJVar1 != (J3DMaterialAnm *)0x0) {
      if ((J3DMaterialAnm *)0xbfffffff < pJVar2) {
        pJVar2 = (J3DMaterialAnm *)0x0;
      }
      (**(code **)(pJVar2->vtbl + 0xc))(pJVar2,pJVar3);
    }
    (**(code **)(pJVar3->vtbl + 8))
              (pJVar3,this->mpNodeMtx + (ushort)(pJVar3->mpJoint->parent).mAnmMatrixIdx);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DModel::diff(void) */

void __thiscall J3DModel::diff(J3DModel *this)

{
  J3DMaterial *pJVar1;
  ushort uVar2;
  
  for (uVar2 = 0; uVar2 < (this->mpModelData->mMaterialTable).mMaterialCount; uVar2 = uVar2 + 1) {
    J3DGraphBase::j3dSys.mpCurMatPacket = this->mpMatPackets + uVar2;
    pJVar1 = (this->mpModelData->mMaterialTable).mpMaterials[uVar2];
    (**(code **)(pJVar1->vtbl + 0x20))(pJVar1,this->field_0xc);
  }
  return;
}


/* __thiscall J3DModel::setSkinDeform(J3DSkinDeform *,
                                      unsigned long) */

int __thiscall J3DModel::setSkinDeform(J3DModel *this,J3DSkinDeform *param_1,ulong param_2)

{
  int iVar1;
  
  this->mpSkinDeform = param_1;
  if (param_1 == (J3DSkinDeform *)0x0) {
    this->mFlags = this->mFlags & 0xfffffffb;
    this->mFlags = this->mFlags & 0xfffffff7;
    iVar1 = 5;
  }
  else {
    J3DSkinDeform::initMtxIndexArray(this->mpSkinDeform,this->mpModelData);
    if (((uint)this->mpModelData->mLoadArgs >> 8 & 1) != 0) {
      J3DSkinDeform::changeFastSkinDL(this->mpSkinDeform,this->mpModelData);
      param_2 = 0;
    }
    iVar1 = 0;
    if ((~param_2 & 2) == 0) {
      this->mFlags = this->mFlags & 0xfffffffb;
    }
    else {
      iVar1 = J3DVertexBuffer::allocTransformedVtxPosArray(&this->mVertexBuffer);
      if (iVar1 != 0) {
        this->mFlags = this->mFlags & 0xfffffffb;
        return iVar1;
      }
      this->mFlags = this->mFlags | 4;
    }
    if ((~param_2 & 4) == 0) {
      this->mFlags = this->mFlags & 0xfffffff7;
    }
    else {
      iVar1 = J3DVertexBuffer::allocTransformedVtxNrmArray(&this->mVertexBuffer);
      if (iVar1 == 0) {
        this->mFlags = this->mFlags | 8;
      }
      else {
        this->mFlags = this->mFlags & 0xfffffff7;
      }
    }
  }
  return iVar1;
}


/* __thiscall J3DModel::calcAnmMtx(void) */

void __thiscall J3DModel::calcAnmMtx(J3DModel *this)

{
  int *piVar1;
  
  J3DGraphBase::j3dSys.mpCurMtxCalc = (J3DMtxCalc *)(this->mpModelData->mJointTree).mpMtxCalc;
  J3DGraphBase::j3dSys.mpCurModel = this;
  if ((this->mFlags & 2) == 0) {
    (**(code **)((J3DGraphBase::j3dSys.mpCurMtxCalc)->vtbl + 8))
              (J3DGraphBase::j3dSys.mpCurMtxCalc,&this->mBaseScale,&this->mBaseMtx);
  }
  else {
    (**(code **)((J3DGraphBase::j3dSys.mpCurMtxCalc)->vtbl + 8))
              (J3DGraphBase::j3dSys.mpCurMtxCalc,&J3DGraphBase::j3dDefaultScale,
               &J3DGraphBase::j3dDefaultMtx);
  }
  piVar1 = (int *)(this->mpModelData->mJointTree).mpMtxCalc;
  (**(code **)(*piVar1 + 0xc))(piVar1,(this->mpModelData->mJointTree).mpRootJoint);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802ee84c) */
/* WARNING: Removing unreachable block (ram,0x802ee83c) */
/* WARNING: Removing unreachable block (ram,0x802ee748) */
/* WARNING: Removing unreachable block (ram,0x802ee778) */
/* WARNING: Removing unreachable block (ram,0x802ee754) */
/* WARNING: Removing unreachable block (ram,0x802ee740) */
/* WARNING: Removing unreachable block (ram,0x802ee6dc) */
/* WARNING: Removing unreachable block (ram,0x802ee744) */
/* WARNING: Removing unreachable block (ram,0x802ee760) */
/* WARNING: Removing unreachable block (ram,0x802ee78c) */
/* WARNING: Removing unreachable block (ram,0x802ee74c) */
/* WARNING: Removing unreachable block (ram,0x802ee834) */
/* WARNING: Removing unreachable block (ram,0x802ee844) */
/* WARNING: Removing unreachable block (ram,0x802ee854) */
/* WARNING: Removing unreachable block (ram,0x802ee79c) */
/* WARNING: Removing unreachable block (ram,0x802ee768) */
/* WARNING: Removing unreachable block (ram,0x802ee770) */
/* WARNING: Removing unreachable block (ram,0x802ee7ac) */
/* __thiscall J3DModel::calcWeightEnvelopeMtx(void) */

void __thiscall J3DModel::calcWeightEnvelopeMtx(J3DModel *this)

{
  float *pfVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  MTX34 *pMVar5;
  J3DModelData *pJVar6;
  MTX34 *pMVar7;
  undefined *puVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  float *pfVar12;
  ushort *puVar13;
  uint uVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  float fVar42;
  float fVar43;
  float fVar44;
  float fVar45;
  float fVar46;
  undefined8 in_f27;
  float fVar47;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  float fVar48;
  undefined8 in_f31;
  float fVar49;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
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
  uVar14 = 0xffffffff;
  pJVar6 = this->mpModelData;
  uVar3 = (pJVar6->mJointTree).mEnvelopeCount;
  puVar13 = (pJVar6->mJointTree).mpEnvJointIndexTable + -1;
  pfVar12 = (pJVar6->mJointTree).mpEnvWeightTable + -1;
  fVar46 = (float)__psq_l0(0x803f66a8,0);
  fVar47 = (float)__psq_l1(0x803f66a8,0);
  iVar4 = -0x30;
  while( true ) {
    uVar14 = uVar14 + 1;
    if ((int)(uint)uVar3 <= (int)uVar14) break;
    puVar8 = this->field_0x88;
    puVar8[uVar14] = 1;
    iVar9 = (int)this->mpWeightEnvMtx[1].m + iVar4;
    iVar11 = 0;
    bVar2 = (this->mpModelData->mJointTree).mpEnvJointCountTable[uVar14 & 0xffff];
    fVar36 = fVar46;
    fVar37 = fVar46;
    fVar38 = fVar46;
    fVar39 = fVar46;
    fVar40 = fVar46;
    fVar41 = fVar46;
    fVar42 = fVar46;
    fVar43 = fVar46;
    fVar44 = fVar46;
    fVar45 = fVar46;
    fVar49 = fVar46;
    fVar48 = fVar46;
    do {
      puVar13 = puVar13 + 1;
      uVar10 = (uint)*puVar13;
      pMVar7 = (this->mpModelData->mJointTree).mpEnvInvBindPoseTable + uVar10;
      pMVar5 = this->mpNodeMtx + uVar10;
      fVar18 = (float)__psq_l0(pMVar7,0);
      fVar20 = (float)__psq_l1(pMVar7,0);
      fVar16 = (float)__psq_l0(pMVar5,0);
      fVar17 = (float)__psq_l1(pMVar5,0);
      fVar22 = (float)__psq_l0(pMVar5->m[1],0);
      fVar23 = (float)__psq_l1(pMVar5->m[1],0);
      fVar26 = (float)__psq_l0(pMVar5->m[2],0);
      fVar27 = (float)__psq_l1(pMVar5->m[2],0);
      fVar28 = (float)__psq_l0(pMVar7->m[1],0);
      fVar30 = (float)__psq_l1(pMVar7->m[1],0);
      fVar32 = (float)__psq_l0(pMVar7->m[2],0);
      fVar34 = (float)__psq_l1(pMVar7->m[2],0);
      pfVar1 = pMVar5->m + 2;
      fVar19 = (float)__psq_l0(pfVar1,0);
      fVar21 = (float)__psq_l1(pfVar1,0);
      pfVar1 = pMVar5->m[1] + 2;
      fVar24 = (float)__psq_l0(pfVar1,0);
      fVar25 = (float)__psq_l1(pfVar1,0);
      pfVar1 = pMVar5->m[2] + 2;
      fVar29 = (float)__psq_l0(pfVar1,0);
      fVar31 = (float)__psq_l1(pfVar1,0);
      pfVar12 = pfVar12 + 1;
      pfVar1 = pMVar7->m + 2;
      fVar33 = (float)__psq_l0(pfVar1,0);
      fVar35 = (float)__psq_l1(pfVar1,0);
      fVar15 = (float)((ulonglong)(double)*pfVar12 >> 0x20);
      fVar36 = (fVar32 * fVar19 + fVar28 * fVar17 + fVar18 * fVar16) * fVar15 + fVar36;
      fVar37 = (fVar34 * fVar19 + fVar30 * fVar17 + fVar20 * fVar16) * fVar15 + fVar37;
      fVar40 = (fVar32 * fVar24 + fVar28 * fVar23 + fVar18 * fVar22) * fVar15 + fVar40;
      fVar41 = (fVar34 * fVar24 + fVar30 * fVar23 + fVar20 * fVar22) * fVar15 + fVar41;
      fVar44 = (fVar32 * fVar29 + fVar28 * fVar27 + fVar18 * fVar26) * fVar15 + fVar44;
      fVar45 = (fVar34 * fVar29 + fVar30 * fVar27 + fVar20 * fVar26) * fVar15 + fVar45;
      pfVar1 = pMVar7->m[1] + 2;
      fVar28 = (float)__psq_l0(pfVar1,0);
      fVar30 = (float)__psq_l1(pfVar1,0);
      pfVar1 = pMVar7->m[2] + 2;
      fVar18 = (float)__psq_l0(pfVar1,0);
      fVar20 = (float)__psq_l1(pfVar1,0);
      __psq_st0(iVar9,fVar36,0);
      __psq_st1(iVar9,fVar37,0);
      __psq_st0(iVar9 + 0x10,fVar40,0);
      __psq_st1(iVar9 + 0x10,fVar41,0);
      __psq_st0(iVar9 + 0x20,fVar44,0);
      __psq_st1(iVar9 + 0x20,fVar45,0);
      fVar38 = (fVar46 * fVar19 + fVar18 * fVar19 + fVar28 * fVar17 + fVar33 * fVar16) * fVar15 +
               fVar38;
      fVar39 = (fVar47 * fVar21 + fVar20 * fVar19 + fVar30 * fVar17 + fVar35 * fVar16) * fVar15 +
               fVar39;
      fVar42 = (fVar46 * fVar24 + fVar18 * fVar24 + fVar28 * fVar23 + fVar33 * fVar22) * fVar15 +
               fVar42;
      fVar43 = (fVar47 * fVar25 + fVar20 * fVar24 + fVar30 * fVar23 + fVar35 * fVar22) * fVar15 +
               fVar43;
      fVar48 = (fVar46 * fVar29 + fVar18 * fVar29 + fVar28 * fVar27 + fVar33 * fVar26) * fVar15 +
               fVar48;
      fVar49 = (fVar47 * fVar31 + fVar20 * fVar29 + fVar30 * fVar27 + fVar35 * fVar26) * fVar15 +
               fVar49;
      puVar8[uVar14] = puVar8[uVar14] & this->field_0x84[uVar10];
      iVar11 = iVar11 + 1;
    } while (iVar11 < (int)(uint)bVar2);
    __psq_st0(iVar9 + 8,fVar38,0);
    __psq_st1(iVar9 + 8,fVar39,0);
    __psq_st0(iVar9 + 0x18,fVar42,0);
    __psq_st1(iVar9 + 0x18,fVar43,0);
    __psq_st0(iVar9 + 0x28,fVar48,0);
    __psq_st1(iVar9 + 0x28,fVar49,0);
    iVar4 = iVar4 + 0x30;
  }
  __psq_l0(auStack8,0);
  __psq_l1(auStack8,0);
  __psq_l0(auStack24,0);
  __psq_l1(auStack24,0);
  __psq_l0(auStack40,0);
  __psq_l1(auStack40,0);
  __psq_l0(auStack56,0);
  __psq_l1(auStack56,0);
  __psq_l0(auStack72,0);
  __psq_l1(auStack72,0);
  return;
}


/* __thiscall J3DModel::update(void) */

void __thiscall J3DModel::update(J3DModel *this)

{
  (*(code *)this->vtbl->calc)();
  (*(code *)this->vtbl->entry)(this);
  return;
}


/* __thiscall J3DModel::calc(void) */

void __thiscall J3DModel::calc(J3DModel *this)

{
  J3DVisibilityManager *pJVar1;
  int *piVar2;
  J3DSkinDeform *pJVar3;
  
  if ((this->mFlags & 4) == 0) {
    J3DGraphBase::j3dSys.mCurFlags = J3DGraphBase::j3dSys.mCurFlags & 0xfffffffb;
  }
  else {
    J3DGraphBase::j3dSys.mCurFlags = J3DGraphBase::j3dSys.mCurFlags | 4;
  }
  if ((this->mFlags & 8) == 0) {
    J3DGraphBase::j3dSys.mCurFlags = J3DGraphBase::j3dSys.mCurFlags & 0xfffffff7;
  }
  else {
    J3DGraphBase::j3dSys.mCurFlags = J3DGraphBase::j3dSys.mCurFlags | 8;
  }
  J3DGraphBase::j3dSys.mpCurModel = this;
  (this->mVertexBuffer).mpCurrentVtxPos = (this->mVertexBuffer).mpVertexArr_Pos;
  (this->mVertexBuffer).mpCurrentVtxNrm = (this->mVertexBuffer).mpVertexArr_Nrm;
  (this->mVertexBuffer).mpCurrentVtxClr = (this->mVertexBuffer).mpVertexArr_Clr;
  pJVar1 = this->mpVisibilityManager;
  if (pJVar1 != (J3DVisibilityManager *)0x0) {
    (**(code **)(pJVar1->vtbl + 0xc))(pJVar1,this->mpModelData);
  }
  if (this->mpDeformData != (J3DDeformData *)0x0) {
    J3DDeformData::deform(this->mpDeformData,this);
  }
  piVar2 = *(int **)&this->field_0xc4;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2,this);
  }
  piVar2 = *(int **)&this->field_0xc8;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2,this);
  }
  calcAnmMtx(this);
  calcWeightEnvelopeMtx(this);
  pJVar3 = this->mpSkinDeform;
  if (pJVar3 != (J3DSkinDeform *)0x0) {
    (**(code **)(*(int *)pJVar3 + 8))(pJVar3,this);
  }
  if ((code *)this->field_0x10 != (code *)0x0) {
    (*(code *)this->field_0x10)(this,0);
  }
  return;
}


/* __thiscall J3DModel::entry(void) */

void __thiscall J3DModel::entry(J3DModel *this)

{
  J3DJoint *pJVar1;
  ushort uVar2;
  
  if ((this->mFlags & 4) == 0) {
    J3DGraphBase::j3dSys.mCurFlags = J3DGraphBase::j3dSys.mCurFlags & 0xfffffffb;
  }
  else {
    J3DGraphBase::j3dSys.mCurFlags = J3DGraphBase::j3dSys.mCurFlags | 4;
  }
  if ((this->mFlags & 8) == 0) {
    J3DGraphBase::j3dSys.mCurFlags = J3DGraphBase::j3dSys.mCurFlags & 0xfffffff7;
  }
  else {
    J3DGraphBase::j3dSys.mCurFlags = J3DGraphBase::j3dSys.mCurFlags | 8;
  }
  J3DGraphBase::j3dSys.mpCurTex = (this->mpModelData->mMaterialTable).mpTexture;
  J3DGraphBase::j3dSys.mpCurModel = this;
  for (uVar2 = 0; uVar2 < (ushort)(this->mpModelData->mJointTree).mJointCount; uVar2 = uVar2 + 1) {
    pJVar1 = (this->mpModelData->mJointTree).mpJoints[uVar2];
    if (pJVar1->mpMaterial != (J3DMaterial *)0x0) {
      (*(code *)((pJVar1->parent).vtbl)->entryIn)();
    }
  }
  return;
}


namespace J3DGraphAnimator {

/* __stdcall calcViewBaseMtx(float *[][][][],
                             Vec const &,
                             float const &[][][],
                             float *[][][][]) */

void calcViewBaseMtx(MTX34 *param_1,float *param_2,float *param_3,MTX34 *param_4)

{
  MTX34 local_38;
  
  local_38.m[2][0] = *param_2;
  local_38.m[0][0] = *param_3 * local_38.m[2][0];
  local_38.m[2][1] = param_2[1];
  local_38.m[0][1] = param_3[1] * local_38.m[2][1];
  local_38.m[2][2] = param_2[2];
  local_38.m[0][2] = param_3[2] * local_38.m[2][2];
  local_38.m[0][3] = param_3[3];
  local_38.m[1][0] = param_3[4] * local_38.m[2][0];
  local_38.m[1][1] = param_3[5] * local_38.m[2][1];
  local_38.m[1][2] = param_3[6] * local_38.m[2][2];
  local_38.m[1][3] = param_3[7];
  local_38.m[2][0] = param_3[8] * local_38.m[2][0];
  local_38.m[2][1] = param_3[9] * local_38.m[2][1];
  local_38.m[2][2] = param_3[10] * local_38.m[2][2];
  local_38.m[2][3] = param_3[0xb];
  mtx::PSMTXConcat(param_1,&local_38,param_4);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802eec10) */
/* __thiscall J3DModel::calcDrawMtx(void) */

void __thiscall J3DModel::calcDrawMtx(J3DModel *this)

{
  uint uVar1;
  J3DModelData *pJVar2;
  uint uVar3;
  ushort uVar4;
  
  uVar3 = this->mFlags & 3;
  if (uVar3 == 1) {
    for (uVar4 = 0; uVar4 < (ushort)(this->mpModelData->mJointTree).mDrawMtxData.mRigidMtxCount;
        uVar4 = uVar4 + 1) {
      mtx::PSMTXCopy(this->mpNodeMtx +
                     (ushort)(this->mpModelData->mJointTree).mDrawMtxData.mpDataArray[uVar4],
                     (MTX34 *)(*(int *)(this->mpDrawMtxBuf + this->mDrawIdxStart * 4) +
                              (uint)uVar4 * 0x30));
    }
    for (uVar4 = 0; uVar4 < (ushort)(this->mpModelData->mJointTree).mEnvelopeCount;
        uVar4 = uVar4 + 1) {
      mtx::PSMTXCopy(this->mpWeightEnvMtx + uVar4,
                     (MTX34 *)(*(int *)(this->mpDrawMtxBuf + this->mDrawIdxStart * 4) +
                              ((uint)uVar4 +
                              (uint)(ushort)(this->mpModelData->mJointTree).mDrawMtxData.
                                            mRigidMtxCount) * 0x30));
    }
  }
  else {
    if (uVar3 == 0) {
      uVar3 = 0;
      while( true ) {
        pJVar2 = this->mpModelData;
        uVar1 = (uint)(ushort)(pJVar2->mJointTree).mDrawMtxData.mRigidMtxCount;
        if (uVar1 <= (uVar3 & 0xffff)) break;
        mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,
                         this->mpNodeMtx +
                         (ushort)(pJVar2->mJointTree).mDrawMtxData.mpDataArray[uVar3 & 0xffff],
                         (MTX34 *)(*(int *)(this->mpDrawMtxBuf + this->mDrawIdxStart * 4) +
                                  (uVar3 & 0xffff) * 0x30));
        uVar3 = uVar3 + 1;
      }
      if (uVar1 < (ushort)(pJVar2->mJointTree).mDrawMtxData.mDrawMtxCount) {
        J3DGraphBase::J3DPSMtxArrayConcat
                  (&J3DGraphBase::j3dSys,this->mpWeightEnvMtx,
                   *(int *)(this->mpDrawMtxBuf + this->mDrawIdxStart * 4) + uVar1 * 0x30,
                   (pJVar2->mJointTree).mEnvelopeCount);
      }
    }
    else {
      if (uVar3 < 3) {
        J3DGraphAnimator::calcViewBaseMtx
                  (&J3DGraphBase::j3dSys,&this->mBaseScale,&this->mBaseMtx,&this->mInternalView);
        uVar3 = 0;
        while( true ) {
          pJVar2 = this->mpModelData;
          uVar1 = (uint)(ushort)(pJVar2->mJointTree).mDrawMtxData.mRigidMtxCount;
          if (uVar1 <= (uVar3 & 0xffff)) break;
          mtx::PSMTXConcat(&this->mInternalView,
                           this->mpNodeMtx +
                           (ushort)(pJVar2->mJointTree).mDrawMtxData.mpDataArray[uVar3 & 0xffff],
                           (MTX34 *)(*(int *)(this->mpDrawMtxBuf + this->mDrawIdxStart * 4) +
                                    (uVar3 & 0xffff) * 0x30));
          uVar3 = uVar3 + 1;
        }
        if (uVar1 < (ushort)(pJVar2->mJointTree).mDrawMtxData.mDrawMtxCount) {
          J3DGraphBase::J3DPSMtxArrayConcat
                    (&this->mInternalView,this->mpWeightEnvMtx,
                     *(int *)(this->mpDrawMtxBuf + this->mDrawIdxStart * 4) + uVar1 * 0x30,
                     (pJVar2->mJointTree).mEnvelopeCount);
        }
      }
    }
  }
  return;
}


/* __thiscall J3DModel::viewCalc(void) */

void __thiscall J3DModel::viewCalc(J3DModel *this)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar1 = this->mDrawIdxStart * 4;
  uVar4 = *(undefined4 *)(this->field_0x94 + iVar1);
  *(undefined4 *)(this->field_0x94 + iVar1) = *(undefined4 *)(this->mpDrawMtxBuf + iVar1);
  *(undefined4 *)(this->mpDrawMtxBuf + this->mDrawIdxStart * 4) = uVar4;
  iVar1 = this->mDrawIdxStart * 4;
  uVar4 = *(undefined4 *)(this->field_0x9c + iVar1);
  *(undefined4 *)(this->field_0x9c + iVar1) = *(undefined4 *)(this->mpNrmMtxBuf + iVar1);
  *(undefined4 *)(this->mpNrmMtxBuf + this->mDrawIdxStart * 4) = uVar4;
  if ((this->mpModelData->mLoadArgs & 0x20U) == 0) {
    bVar2 = false;
    uVar3 = this->mFlags;
    if (((uVar3 & 4) != 0) && ((uVar3 & 8) != 0)) {
      bVar2 = true;
    }
    if (bVar2) {
      if ((uVar3 & 3) == 2) {
        J3DGraphAnimator::calcViewBaseMtx
                  (&J3DGraphBase::j3dSys,&this->mBaseScale,&this->mBaseMtx,&this->mInternalView);
      }
      prepareShapePackets(this);
    }
    else {
      if ((uVar3 & 4) == 0) {
        if ((uVar3 & 8) == 0) {
          calcDrawMtx(this);
          calcNrmMtx(this);
          calcBBoard(this);
          calcBumpMtx(this);
          os::DCStoreRange(*(undefined4 *)(this->mpDrawMtxBuf + this->mDrawIdxStart * 4),
                           (uint)(ushort)(this->mpModelData->mJointTree).mDrawMtxData.mDrawMtxCount
                           * 0x30);
          os::DCStoreRange(*(undefined4 *)(this->mpNrmMtxBuf + this->mDrawIdxStart * 4),
                           (uint)(ushort)(this->mpModelData->mJointTree).mDrawMtxData.mDrawMtxCount
                           * 0x24);
        }
        else {
          calcDrawMtx(this);
          calcBBoard(this);
          os::DCStoreRange(*(undefined4 *)(this->mpDrawMtxBuf + this->mDrawIdxStart * 4),
                           (uint)(ushort)(this->mpModelData->mJointTree).mDrawMtxData.mDrawMtxCount
                           * 0x30);
        }
      }
      else {
        calcDrawMtx(this);
        calcNrmMtx(this);
        calcBumpMtx(this);
        os::DCStoreRange(*(undefined4 *)(this->mpDrawMtxBuf + this->mDrawIdxStart * 4),
                         (uint)(ushort)(this->mpModelData->mJointTree).mDrawMtxData.mDrawMtxCount *
                         0x30);
        os::DCStoreRange(*(undefined4 *)(this->mpNrmMtxBuf + this->mDrawIdxStart * 4),
                         (uint)(ushort)(this->mpModelData->mJointTree).mDrawMtxData.mDrawMtxCount *
                         0x24);
      }
      prepareShapePackets(this);
    }
  }
  else {
    if ((this->mFlags & 3) == 2) {
      J3DGraphAnimator::calcViewBaseMtx
                (&J3DGraphBase::j3dSys,&this->mBaseScale,&this->mBaseMtx,&this->mInternalView);
    }
    prepareShapePackets(this);
  }
  return;
}


/* __thiscall J3DModel::calcNrmMtx(void) */

void __thiscall J3DModel::calcNrmMtx(J3DModel *this)

{
  int iVar1;
  uint uVar2;
  J3DModelData *pJVar3;
  ushort uVar4;
  
  if ((this->mpModelData->mLoadArgs & 0x10U) == 0) {
    for (uVar4 = 0; pJVar3 = this->mpModelData,
        uVar4 < (ushort)(pJVar3->mJointTree).mDrawMtxData.mDrawMtxCount; uVar4 = uVar4 + 1) {
      uVar2 = (uint)uVar4;
      if ((pJVar3->mJointTree).mDrawMtxData.mpMtxTypeArray[uVar2] == 0) {
        if (this->field_0x84[(ushort)(pJVar3->mJointTree).mDrawMtxData.mpDataArray[uVar2]] == 1) {
          iVar1 = this->mDrawIdxStart * 4;
          J3DGraphBase::J3DPSMtx33CopyFrom34
                    (*(int *)(this->mpDrawMtxBuf + iVar1) + uVar2 * 0x30,
                     *(int *)(this->mpNrmMtxBuf + iVar1) + uVar2 * 0x24);
        }
        else {
          iVar1 = this->mDrawIdxStart * 4;
          J3DGraphBase::J3DPSCalcInverseTranspose
                    (*(int *)(this->mpDrawMtxBuf + iVar1) + uVar2 * 0x30,
                     *(int *)(this->mpNrmMtxBuf + iVar1) + uVar2 * 0x24);
        }
      }
      else {
        if (this->field_0x88[(ushort)(pJVar3->mJointTree).mDrawMtxData.mpDataArray[uVar2]] == '\x01'
           ) {
          iVar1 = this->mDrawIdxStart * 4;
          J3DGraphBase::J3DPSMtx33CopyFrom34
                    (*(int *)(this->mpDrawMtxBuf + iVar1) + uVar2 * 0x30,
                     *(int *)(this->mpNrmMtxBuf + iVar1) + uVar2 * 0x24);
        }
        else {
          iVar1 = this->mDrawIdxStart * 4;
          J3DGraphBase::J3DPSCalcInverseTranspose
                    (*(int *)(this->mpDrawMtxBuf + iVar1) + uVar2 * 0x30,
                     *(int *)(this->mpNrmMtxBuf + iVar1) + uVar2 * 0x24);
        }
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall J3DModel::calcBumpMtx(void) */

void __thiscall J3DModel::calcBumpMtx(J3DModel *this)

{
  char *pcVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  J3DMaterial *pJVar5;
  int iVar6;
  uint uVar7;
  
  if (this->mpModelData->field_0xc == 1) {
    iVar6 = 0;
    for (uVar7 = 0; (int)uVar7 < (int)(uint)(this->mpModelData->mMaterialTable).mMaterialCount;
        uVar7 = uVar7 + 1) {
      pJVar5 = (this->mpModelData->mMaterialTable).mpMaterials[uVar7 & 0xffff];
      pcVar1 = (char *)(*(code *)pJVar5->mpTexGenBlock->vtbl->getNBTScale)();
      if (*pcVar1 == '\x01') {
        iVar2 = this->mDrawIdxStart * 4;
        pfVar4 = *(float **)(*(int *)(*(int *)&this->field_0xa8 + iVar6) + iVar2);
        pfVar3 = *(float **)(this->mpNrmMtxBuf + iVar2);
        iVar2 = (*(code *)pJVar5->mpTexGenBlock->vtbl->getNBTScale)();
        J3DShape::calcNBTScale(pJVar5->mpShape,(Vec *)(iVar2 + 4),pfVar3,pfVar4);
        os::DCStoreRange(*(undefined4 *)
                          (*(int *)(*(int *)&this->field_0xa8 + iVar6) + this->mDrawIdxStart * 4),
                         (uint)(ushort)(this->mpModelData->mJointTree).mDrawMtxData.mDrawMtxCount *
                         0x24);
        iVar6 = iVar6 + 4;
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DModel::calcBBoard(void) */

void __thiscall J3DModel::calcBBoard(J3DModel *this)

{
  byte bVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  MTX34 *pNrm;
  J3DModelData *pJVar5;
  MTX34 *pDrw;
  int iVar6;
  ushort uVar7;
  
  if (this->mpModelData->field_0xe == 1) {
    for (uVar7 = 0; pJVar5 = this->mpModelData,
        uVar7 < (ushort)(pJVar5->mJointTree).mDrawMtxData.mDrawMtxCount; uVar7 = uVar7 + 1) {
      uVar2 = (uint)uVar7;
      if ((pJVar5->mJointTree).mDrawMtxData.mpMtxTypeArray[uVar2] == 0) {
        bVar1 = (pJVar5->mJointTree).mpJoints
                [(ushort)(pJVar5->mJointTree).mDrawMtxData.mpDataArray[uVar2]]->mMtxTypeFlags >> 4;
        if (bVar1 == 1) {
          pDrw = (MTX34 *)(*(int *)(this->mpDrawMtxBuf + this->mDrawIdxStart * 4) + uVar2 * 0x30);
          J3DGraphBase::J3DCalcBBoardMtx(pDrw);
          fVar3 = J3DGraphAnimator::_1516;
          pNrm = (MTX34 *)(*(int *)(this->mpNrmMtxBuf + this->mDrawIdxStart * 4) + uVar2 * 0x24);
          pNrm->m[0] = J3DGraphAnimator::_1516 / pDrw->m[0];
          fVar4 = J3DGraphAnimator::_2632;
          pNrm->m[1] = J3DGraphAnimator::_2632;
          pNrm->m[2] = fVar4;
          pNrm->m[3] = fVar4;
          pNrm->m[1][0] = fVar3 / pDrw->m[1][1];
          pNrm->m[1][1] = fVar4;
          pNrm->m[1][2] = fVar4;
          pNrm->m[1][3] = fVar4;
          pNrm->m[2][0] = fVar3 / pDrw->m[2][2];
        }
        else {
          if (bVar1 == 2) {
            iVar6 = *(int *)(this->mpDrawMtxBuf + this->mDrawIdxStart * 4) + uVar2 * 0x30;
            J3DGraphBase::J3DCalcYBBoardMtx(iVar6);
            J3DGraphBase::J3DPSCalcInverseTranspose
                      (iVar6,*(int *)(this->mpNrmMtxBuf + this->mDrawIdxStart * 4) + uVar2 * 0x24);
          }
        }
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DModel::prepareShapePackets(void) */

void __thiscall J3DModel::prepareShapePackets(J3DModel *this)

{
  ushort uVar1;
  char *pcVar2;
  J3DShape *pJVar3;
  J3DShapePacket *pJVar4;
  ushort uVar5;
  uint uVar6;
  J3DMaterial *pJVar7;
  
  uVar1 = (this->mpModelData->mShapeTable).mShapeCount;
  for (uVar5 = 0; uVar5 < uVar1; uVar5 = uVar5 + 1) {
    pJVar4 = this->mpShapePackets + uVar5;
    pJVar4->field_0x3c = this->field_0x84;
    *(undefined **)&pJVar4->mpMtxBuffer = this->mpDrawMtxBuf;
    *(undefined **)&pJVar4->field_0x2c = this->mpNrmMtxBuf;
    pJVar4->mpDrawIdxStart = &this->mDrawIdxStart;
  }
  uVar5 = 0;
  while( true ) {
    if (uVar1 <= uVar5) break;
    pJVar3 = (this->mpModelData->mShapeTable).mpShapes[uVar5];
    pJVar4 = this->mpShapePackets;
    if ((this->mFlags & 4) == 0) {
      pJVar3->mVisFlags = pJVar3->mVisFlags & 0xfffffffb;
    }
    else {
      pJVar3->mVisFlags = pJVar3->mVisFlags | 4;
    }
    if (((this->mFlags & 8) == 0) || ((pJVar3->mVisFlags & 0x100U) != 0)) {
      pJVar3->mVisFlags = pJVar3->mVisFlags & 0xfffffff7;
    }
    else {
      pJVar3->mVisFlags = pJVar3->mVisFlags | 8;
    }
    if ((this->mFlags & 3) == 2) {
      pJVar4[uVar5].mpViewMtx = &this->mInternalView;
    }
    else {
      pJVar4[uVar5].mpViewMtx = &J3DGraphBase::j3dSys.mCurViewMtx;
    }
    uVar5 = uVar5 + 1;
  }
  if (this->mpModelData->field_0xc == 1) {
    for (uVar6 = 0; (int)uVar6 < (int)(uint)(this->mpModelData->mMaterialTable).mMaterialCount;
        uVar6 = uVar6 + 1) {
      pJVar7 = (this->mpModelData->mMaterialTable).mpMaterials[uVar6 & 0xffff];
      pcVar2 = (char *)(*(code *)pJVar7->mpTexGenBlock->vtbl->getNBTScale)();
      if (*pcVar2 == '\x01') {
        pJVar3 = pJVar7->mpShape;
        *(undefined4 *)&this->mpShapePackets[(ushort)pJVar3->mShapeIdx].field_0x2c =
             *(undefined4 *)(*(int *)&this->field_0xa8 + (int)pJVar3->field_0x64 * 4);
      }
    }
  }
  return;
}

