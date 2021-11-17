#include <J3DGraphAnimator/J3DJoint.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J3DGraphAnimator/J3DJoint.h>
#include <mtx/mtx.h>
#include <J3DGraphBase/J3DTransform.h>
#include <J3DGraphBase/J3DMaterial.h>
#include <J3DGraphAnimator/J3DNode.h>
#include <JKernel/JKRHeap.h>
#include <J3DU/J3DUMotion.h>
#include <m_Do_ext.h>
#include <Demangler/J3DNode.h>
#include <J3DMtxCalcSoftimage.h>
#include <J3DJoint.h>
#include <J3DMtxCalcAnm.h>
#include <J3DMtxCalcMaya.h>
#include <J3DMtxCalcBasic.h>


/* __thiscall J3DMtxCalcAnm::calc(unsigned short) */

void __thiscall J3DMtxCalcAnm::calc(J3DMtxCalcAnm *this,ushort param_1)

{
  int *piVar1;
  J3DJoint *pJVar2;
  undefined2 in_register_00000010;
  float local_28;
  float local_24;
  float local_20;
  short local_1c;
  short local_1a;
  short local_18;
  float local_14;
  float local_10;
  float local_c;
  
  J3DGraphBase::j3dSys.mpCurMtxCalc = (J3DMtxCalc *)this;
  if (this != (J3DMtxCalcAnm *)0x0) {
    J3DGraphBase::j3dSys.mpCurMtxCalc = (J3DMtxCalc *)this->field_0x0;
  }
  piVar1 = *(int **)(this->field_0x0 + 4);
  if (piVar1 == (int *)0x0) {
    pJVar2 = ((J3DGraphBase::j3dSys.mpCurModel)->mpModelData->mJointTree).mpJoints[param_1];
    local_28 = (pJVar2->mTransformInfo).mScale.x;
    local_24 = (pJVar2->mTransformInfo).mScale.y;
    local_20 = (pJVar2->mTransformInfo).mScale.z;
    local_1c = (pJVar2->mTransformInfo).mRot.x;
    local_1a = (pJVar2->mTransformInfo).mRot.y;
    local_18 = (pJVar2->mTransformInfo).mRot.z;
    local_14 = (pJVar2->mTransformInfo).mTranslation.x;
    local_10 = (pJVar2->mTransformInfo).mTranslation.y;
    local_c = (pJVar2->mTransformInfo).mTranslation.z;
  }
  else {
    (**(code **)(*piVar1 + 0xc))(piVar1,CONCAT22(in_register_00000010,param_1),&local_28);
  }
  (**(code **)(*(int *)this->field_0x0 + 0x10))
            (this->field_0x0,CONCAT22(in_register_00000010,param_1),&local_28);
  return;
}


/* __thiscall J3DMtxCalcBasic::J3DMtxCalcBasic(void) */

J3DMtxCalcBasic * __thiscall J3DMtxCalcBasic::J3DMtxCalcBasic(J3DMtxCalcBasic *this)

{
  short in_r4;
  
  if (in_r4 != 0) {
    this->vderiv = (J3DMtxCalc *)(this + 1);
    this[1].vderiv = (J3DMtxCalc *)&J3DMtxCalc::__vt;
  }
  this->vtbl = (undefined *)&__vt;
  this->vderiv->vtbl = (undefined *)&PTR_8039ec0c;
  this->vderiv[9].vtbl = (undefined *)((int)this + (0x50 - (int)this->vderiv));
  return this;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DMtxCalcBasic::recursiveCalc(J3DNode *) */

void __thiscall J3DMtxCalcBasic::recursiveCalc(J3DMtxCalcBasic *this,J3DNode *param_1)

{
  J3DMtxCalcBasic local_98;
  undefined auStack72 [52];
  
  if (param_1 != (J3DNode *)0x0) {
    J3DMtxCalcBasic(&local_98);
    mtx::PSMTXCopy(&J3DSys::mCurrentMtx,&local_98.mCurrentMtx);
    local_98.mCurrentS.x = J3DSys::mCurrentS.x;
    local_98.mCurrentS.y = J3DSys::mCurrentS.y;
    local_98.mCurrentS.z = J3DSys::mCurrentS.z;
    local_98.mParentS.x = J3DSys::mParentS.x;
    local_98.mParentS.y = J3DSys::mParentS.y;
    local_98.mParentS.z = J3DSys::mParentS.z;
    (*(code *)param_1->vtbl->calcIn)(param_1);
    if ((code *)param_1->mpCalcCallBack != (code *)0x0) {
      (*(code *)param_1->mpCalcCallBack)(param_1,0);
    }
    (**(code **)(this->vtbl + 0x10))(this,param_1->mpFirstChild);
    mtx::PSMTXCopy(&local_98.mCurrentMtx,&J3DSys::mCurrentMtx);
    J3DSys::mCurrentS.x = local_98.mCurrentS.x;
    J3DSys::mCurrentS.y = local_98.mCurrentS.y;
    J3DSys::mCurrentS.z = local_98.mCurrentS.z;
    J3DSys::mParentS.x = local_98.mParentS.x;
    J3DSys::mParentS.y = local_98.mParentS.y;
    J3DSys::mParentS.z = local_98.mParentS.z;
    (*(code *)param_1->vtbl->calcOut)(param_1);
    if ((code *)param_1->mpCalcCallBack != (code *)0x0) {
      (*(code *)param_1->mpCalcCallBack)(param_1,1);
    }
    (**(code **)(this->vtbl + 0x10))(this,param_1->mpNextSibling);
    (local_98.vderiv)->vtbl = (undefined *)&PTR_8039ec0c;
    local_98.vderiv[9].vtbl = auStack72 + -(int)local_98.vderiv;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DMtxCalcBasic::calcTransform(unsigned short,
                                             J3DTransformInfo const &) */

void __thiscall
J3DMtxCalcBasic::calcTransform(J3DMtxCalcBasic *this,ushort param_1,J3DTransformInfo *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  MTX34 local_4c;
  
  J3DSys::mCurrentS.x = J3DSys::mCurrentS.x * (param_2->mScale).x;
  J3DSys::mCurrentS.y = J3DSys::mCurrentS.y * (param_2->mScale).y;
  J3DSys::mCurrentS.z = J3DSys::mCurrentS.z * (param_2->mScale).z;
  if (((J3DGraphAnimator::_1594 == J3DSys::mCurrentS.x) &&
      (J3DGraphAnimator::_1594 == J3DSys::mCurrentS.y)) &&
     (J3DGraphAnimator::_1594 == J3DSys::mCurrentS.z)) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  if (!bVar4) {
    (J3DGraphBase::j3dSys.mpCurModel)->field_0x84[param_1] = 0;
  }
  else {
    (J3DGraphBase::j3dSys.mpCurModel)->field_0x84[param_1] = 1;
  }
  J3DGraphBase::J3DGetTranslateRotateMtx(param_2,&local_4c);
  if (!bVar4) {
    fVar1 = (param_2->mScale).x;
    local_4c.m[0][0] = local_4c.m[0][0] * fVar1;
    fVar2 = (param_2->mScale).y;
    local_4c.m[0][1] = local_4c.m[0][1] * fVar2;
    fVar3 = (param_2->mScale).z;
    local_4c.m[0][2] = local_4c.m[0][2] * fVar3;
    local_4c.m[1][0] = local_4c.m[1][0] * fVar1;
    local_4c.m[1][1] = local_4c.m[1][1] * fVar2;
    local_4c.m[1][2] = local_4c.m[1][2] * fVar3;
    local_4c.m[2][0] = local_4c.m[2][0] * fVar1;
    local_4c.m[2][1] = local_4c.m[2][1] * fVar2;
    local_4c.m[2][2] = local_4c.m[2][2] * fVar3;
  }
  mtx::PSMTXConcat(&J3DSys::mCurrentMtx,&local_4c,&J3DSys::mCurrentMtx);
  mtx::PSMTXCopy(&J3DSys::mCurrentMtx,(J3DGraphBase::j3dSys.mpCurModel)->mpNodeMtx + param_1);
  return;
}


/* __thiscall J3DMtxCalcBasic::calc(unsigned short) */

void __thiscall J3DMtxCalcBasic::calc(J3DMtxCalcBasic *this,ushort param_1)

{
  undefined2 in_register_00000010;
  
  J3DGraphBase::j3dSys.mpCurMtxCalc = (J3DMtxCalc *)this;
  if (this != (J3DMtxCalcBasic *)0x0) {
    J3DGraphBase::j3dSys.mpCurMtxCalc = this->vderiv;
  }
  (**(code **)(this->vtbl + 0x14))
            (this,CONCAT22(in_register_00000010,param_1),
             &((J3DGraphBase::j3dSys.mpCurModel)->mpModelData->mJointTree).mpJoints[param_1]->
              mTransformInfo);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DMtxCalcSoftimage::calcTransform(unsigned short,
                                                 J3DTransformInfo const &) */

void __thiscall
J3DMtxCalcSoftimage::calcTransform
          (J3DMtxCalcSoftimage *this,ushort param_1,J3DTransformInfo *param_2)

{
  bool bVar1;
  MTX34 local_4c;
  
  J3DGraphBase::J3DGetTranslateRotateMtx
            ((double)((param_2->mTranslation).x * J3DSys::mCurrentS.x),
             (double)((param_2->mTranslation).y * J3DSys::mCurrentS.y),
             (double)((param_2->mTranslation).z * J3DSys::mCurrentS.z),(int)(param_2->mRot).x,
             (int)(param_2->mRot).y,(int)(param_2->mRot).z,&local_4c);
  mtx::PSMTXConcat(&J3DSys::mCurrentMtx,&local_4c,&J3DSys::mCurrentMtx);
  J3DSys::mCurrentS.x = J3DSys::mCurrentS.x * (param_2->mScale).x;
  J3DSys::mCurrentS.y = J3DSys::mCurrentS.y * (param_2->mScale).y;
  J3DSys::mCurrentS.z = J3DSys::mCurrentS.z * (param_2->mScale).z;
  if (((J3DGraphAnimator::_1594 == J3DSys::mCurrentS.x) &&
      (J3DGraphAnimator::_1594 == J3DSys::mCurrentS.y)) &&
     (J3DGraphAnimator::_1594 == J3DSys::mCurrentS.z)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    (J3DGraphBase::j3dSys.mpCurModel)->field_0x84[param_1] = 1;
    mtx::PSMTXCopy(&J3DSys::mCurrentMtx,(J3DGraphBase::j3dSys.mpCurModel)->mpNodeMtx + param_1);
  }
  else {
    (J3DGraphBase::j3dSys.mpCurModel)->field_0x84[param_1] = 0;
    local_4c.m[0][0] = J3DSys::mCurrentMtx.m[0][0] * J3DSys::mCurrentS.x;
    local_4c.m[0][1] = J3DSys::mCurrentMtx.m[0][1] * J3DSys::mCurrentS.y;
    local_4c.m[0][2] = J3DSys::mCurrentMtx.m[0][2] * J3DSys::mCurrentS.z;
    local_4c.m[0][3] = J3DSys::mCurrentMtx.m[0][3];
    local_4c.m[1][0] = J3DSys::mCurrentMtx.m[1][0] * J3DSys::mCurrentS.x;
    local_4c.m[1][1] = J3DSys::mCurrentMtx.m[1][1] * J3DSys::mCurrentS.y;
    local_4c.m[1][2] = J3DSys::mCurrentMtx.m[1][2] * J3DSys::mCurrentS.z;
    local_4c.m[1][3] = J3DSys::mCurrentMtx.m[1][3];
    local_4c.m[2][0] = J3DSys::mCurrentMtx.m[2][0] * J3DSys::mCurrentS.x;
    local_4c.m[2][1] = J3DSys::mCurrentMtx.m[2][1] * J3DSys::mCurrentS.y;
    local_4c.m[2][2] = J3DSys::mCurrentMtx.m[2][2] * J3DSys::mCurrentS.z;
    local_4c.m[2][3] = J3DSys::mCurrentMtx.m[2][3];
    mtx::PSMTXCopy(&local_4c,(J3DGraphBase::j3dSys.mpCurModel)->mpNodeMtx + param_1);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DMtxCalcMaya::calcTransform(unsigned short,
                                            J3DTransformInfo const &) */

void __thiscall
J3DMtxCalcMaya::calcTransform(J3DMtxCalcMaya *this,ushort param_1,J3DTransformInfo *param_2)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  MTX34 local_48;
  
  bVar1 = ((J3DGraphBase::j3dSys.mpCurModel)->mpModelData->mJointTree).mpJoints[param_1]->
          mbIgnoreParentScale;
  if (((J3DGraphAnimator::_1594 == (param_2->mScale).x) &&
      (J3DGraphAnimator::_1594 == (param_2->mScale).y)) &&
     (J3DGraphAnimator::_1594 == (param_2->mScale).z)) {
    (J3DGraphBase::j3dSys.mpCurModel)->field_0x84[param_1] = 1;
    bVar5 = true;
  }
  else {
    (J3DGraphBase::j3dSys.mpCurModel)->field_0x84[param_1] = 0;
    bVar5 = false;
  }
  J3DGraphBase::J3DGetTranslateRotateMtx(param_2,&local_48);
  if (!bVar5) {
    fVar2 = (param_2->mScale).x;
    local_48.m[0][0] = local_48.m[0][0] * fVar2;
    fVar3 = (param_2->mScale).y;
    local_48.m[0][1] = local_48.m[0][1] * fVar3;
    fVar4 = (param_2->mScale).z;
    local_48.m[0][2] = local_48.m[0][2] * fVar4;
    local_48.m[1][0] = local_48.m[1][0] * fVar2;
    local_48.m[1][1] = local_48.m[1][1] * fVar3;
    local_48.m[1][2] = local_48.m[1][2] * fVar4;
    local_48.m[2][0] = local_48.m[2][0] * fVar2;
    local_48.m[2][1] = local_48.m[2][1] * fVar3;
    local_48.m[2][2] = local_48.m[2][2] * fVar4;
  }
  if (bVar1 == 1) {
    fVar2 = J3DGraphAnimator::_1594 / J3DSys::mParentS.x;
    fVar3 = J3DGraphAnimator::_1594 / J3DSys::mParentS.y;
    fVar4 = J3DGraphAnimator::_1594 / J3DSys::mParentS.z;
    local_48.m[0][0] = local_48.m[0][0] * fVar2;
    local_48.m[0][1] = local_48.m[0][1] * fVar2;
    local_48.m[0][2] = local_48.m[0][2] * fVar2;
    local_48.m[1][0] = local_48.m[1][0] * fVar3;
    local_48.m[1][1] = local_48.m[1][1] * fVar3;
    local_48.m[1][2] = local_48.m[1][2] * fVar3;
    local_48.m[2][0] = local_48.m[2][0] * fVar4;
    local_48.m[2][1] = local_48.m[2][1] * fVar4;
    local_48.m[2][2] = local_48.m[2][2] * fVar4;
  }
  mtx::PSMTXConcat(&J3DSys::mCurrentMtx,&local_48,&J3DSys::mCurrentMtx);
  mtx::PSMTXCopy(&J3DSys::mCurrentMtx,(J3DGraphBase::j3dSys.mpCurModel)->mpNodeMtx + param_1);
  J3DSys::mParentS.x = (param_2->mScale).x;
  J3DSys::mParentS.y = (param_2->mScale).y;
  J3DSys::mParentS.z = (param_2->mScale).z;
  return;
}


/* __thiscall J3DJoint::initialize(void) */

void __thiscall J3DJoint::initialize(J3DJoint *this)

{
  float fVar1;
  float fVar2;
  
  (this->parent).mAnmMatrixIdx = 0;
  this->mMtxTypeFlags = 1;
  this->mbIgnoreParentScale = 0;
  (this->mTransformInfo).mScale.x = J3DGraphBase::j3dDefaultTransformInfo;
  (this->mTransformInfo).mScale.y = DAT_80370c3c;
  (this->mTransformInfo).mScale.z = DAT_80370c40;
  (this->mTransformInfo).mRot.x = DAT_80370c44;
  (this->mTransformInfo).mRot.y = DAT_80370c46;
  (this->mTransformInfo).mRot.z = DAT_80370c48;
  (this->mTransformInfo).mTranslation.x = DAT_80370c4c;
  (this->mTransformInfo).mTranslation.y = DAT_80370c50;
  (this->mTransformInfo).mTranslation.z = DAT_80370c54;
  this->mBoundingSphereRadius = J3DGraphAnimator::_1768;
  fVar2 = DAT_80370ec0;
  fVar1 = DAT_80370ebc;
  (this->mBBoxMin).x = J3DGraphAnimator::_1791;
  (this->mBBoxMin).y = fVar1;
  (this->mBBoxMin).z = fVar2;
  fVar2 = DAT_80370ecc;
  fVar1 = DAT_80370ec8;
  (this->mBBoxMax).x = J3DGraphAnimator::_1793;
  (this->mBBoxMax).y = fVar1;
  (this->mBBoxMax).z = fVar2;
  this->mpMtxCalc = (J3DMtxCalc *)0x0;
  this->mpOldMtxCalc = (J3DMtxCalc *)0x0;
  this->mpMaterial = (J3DMaterial *)0x0;
  return;
}


/* __thiscall J3DJoint::addMesh(J3DMaterial *) */

void __thiscall J3DJoint::addMesh(J3DJoint *this,J3DMaterial *param_1)

{
  if (this->mpMaterial == (J3DMaterial *)0x0) {
    this->mpMaterial = param_1;
    return;
  }
  param_1->mpNextMaterial = this->mpMaterial;
  this->mpMaterial = param_1;
  return;
}


/* __thiscall J3DJoint::calcIn(void) */

void __thiscall J3DJoint::calcIn(J3DJoint *this)

{
  if (this->mpMtxCalc == (J3DMtxCalc *)0x0) {
    if (J3DGraphBase::j3dSys.mpCurMtxCalc != (J3DMtxCalc *)0x0) {
      (**(code **)((J3DGraphBase::j3dSys.mpCurMtxCalc)->vtbl + 0x14))
                (J3DGraphBase::j3dSys.mpCurMtxCalc,(this->parent).mAnmMatrixIdx);
    }
  }
  else {
    this->mpOldMtxCalc = J3DGraphBase::j3dSys.mpCurMtxCalc;
    (**(code **)(this->mpMtxCalc->vtbl + 0x14))(this->mpMtxCalc,(this->parent).mAnmMatrixIdx);
  }
  return;
}


/* __thiscall J3DJoint::calcOut(void) */

void __thiscall J3DJoint::calcOut(J3DJoint *this)

{
  if (this->mpOldMtxCalc == (J3DMtxCalc *)0x0) {
    return;
  }
  J3DGraphBase::j3dSys.mpCurMtxCalc = this->mpOldMtxCalc;
  this->mpOldMtxCalc = (J3DMtxCalc *)0x0;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall J3DJoint::entryIn(void) */

void __thiscall J3DJoint::entryIn(J3DJoint *this)

{
  ushort uVar1;
  uint uVar2;
  J3DShapePacket *pJVar3;
  J3DMaterialAnm *pJVar4;
  J3DMaterialAnm *pJVar5;
  char cVar6;
  J3DMaterial *this_00;
  J3DMatPacket *pMatPacket;
  MTX34 *pMtx;
  
  pMtx = (J3DGraphBase::j3dSys.mpCurModel)->mpNodeMtx + (ushort)(this->parent).mAnmMatrixIdx;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0]->mpNodeMtx = pMtx;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1]->mpNodeMtx = pMtx;
  this_00 = this->mpMaterial;
  while (this_00 != (J3DMaterial *)0x0) {
    if ((this_00->mpShape->mVisFlags & 1U) == 0) {
      pMatPacket = (J3DGraphBase::j3dSys.mpCurModel)->mpMatPackets + (ushort)this_00->mIdx;
      uVar1 = this_00->mpShape->mShapeIdx;
      pJVar3 = (J3DGraphBase::j3dSys.mpCurModel)->mpShapePackets;
      if (((pMatPacket->parent).mFlags & 1U) == 0) {
        pJVar4 = this_00->mpMaterialAnm;
        pJVar5 = pJVar4;
        if ((J3DMaterialAnm *)0xbfffffff < pJVar4) {
          pJVar5 = (J3DMaterialAnm *)0x0;
        }
        if (pJVar5 != (J3DMaterialAnm *)0x0) {
          if ((J3DMaterialAnm *)0xbfffffff < pJVar4) {
            pJVar4 = (J3DMaterialAnm *)0x0;
          }
          (**(code **)(pJVar4->vtbl + 0xc))(pJVar4,this_00);
        }
        (**(code **)(this_00->vtbl + 8))(this_00,pMtx);
      }
      J3DMaterial::setCurrentMtx(this_00);
      pJVar5 = this_00->mpMaterialAnm;
      if ((J3DMaterialAnm *)0xbfffffff < pJVar5) {
        pJVar5 = (J3DMaterialAnm *)0x0;
      }
      pMatPacket->mpMaterialAnm = pJVar5;
      pMatPacket->mpFirstShapePacket = pJVar3 + uVar1;
      uVar2 = countLeadingZeros(this_00->mMaterialMode & 3);
      cVar6 = (**(code **)((pMatPacket->parent).parent.vtbl + 0xc))
                        (pMatPacket,
                         *(undefined4 *)
                          ((int)J3DGraphBase::j3dSys.mpCurDrawBuffers + (uVar2 >> 3 & 0x3fc)));
      if (cVar6 != '\0') {
        _entryNum = _entryNum + 1;
        J3DGraphBase::j3dSys.mpCurMatPacket = pMatPacket;
        (**(code **)(this_00->vtbl + 0xc))(this_00);
      }
      this_00 = this_00->mpNextMaterial;
    }
    else {
      this_00 = this_00->mpNextMaterial;
    }
  }
  return;
}


/* __thiscall J3DJoint::getType(void) const */

undefined4 __thiscall J3DJoint::getType(J3DJoint *this)

{
  return 0x4e4a4e54;
}


/* __thiscall J3DJoint::~J3DJoint(void) */

void __thiscall J3DJoint::_J3DJoint(J3DJoint *this,short param_1)

{
  if (this != (J3DJoint *)0x0) {
    (this->parent).vtbl = &__vt;
    J3DNode::_J3DNode(&this->parent,0);
    if (0 < param_1) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* [thunk]:__thiscall J3DMtxCalcAnm::calc(unsigned short) */

void __thiscall J3DMtxCalcAnm::calc(J3DMtxCalcAnm *this,ushort param_1)

{
  calc((J3DMtxCalcAnm *)(this[4].field_0x4 + (int)&this->field_0x0 + -8),param_1);
  return;
}


/* [thunk]:__thiscall J3DMtxCalcBasic::calcTransform(unsigned short,
                                                     J3DTransformInfo const &) */

void __thiscall
J3DMtxCalcBasic::calcTransform(J3DMtxCalcBasic *this,ushort param_1,J3DTransformInfo *param_2)

{
  calcTransform((J3DMtxCalcBasic *)((int)&this[-1].vderiv + (int)(this->mCurrentMtx).m[2][0]),
                param_1,param_2);
  return;
}


/* [thunk]:__thiscall J3DMtxCalcBasic::init(Vec const &,
                                            float const &[][][]) */

int __thiscall J3DMtxCalcBasic::init(J3DMtxCalcBasic *this,TVec3_float_ *param_1,MTX34 *param_2)

{
  int iVar1;
  
  iVar1 = init((J3DMtxCalcBasic *)((int)&this[-1].vderiv + (int)(this->mCurrentMtx).m[2][0]),param_1
               ,param_2);
  return iVar1;
}


/* [thunk]:__thiscall J3DMtxCalcSoftimage::calcTransform(unsigned short,
                                                         J3DTransformInfo const &) */

void __thiscall
J3DMtxCalcSoftimage::calcTransform
          (J3DMtxCalcSoftimage *this,ushort param_1,J3DTransformInfo *param_2)

{
  calcTransform(this + *(int *)(this + 0x24) + -0x50,param_1,param_2);
  return;
}


/* [thunk]:__thiscall J3DMtxCalcSoftimage::init(Vec const &,
                                                float const &[][][]) */

int __thiscall J3DMtxCalcSoftimage::init(J3DMtxCalcSoftimage *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = init(this + *(int *)(this + 0x24) + -0x50,ctx);
  return iVar1;
}


/* [thunk]:__thiscall J3DMtxCalcBasic::calc(unsigned short) */

void __thiscall J3DMtxCalcBasic::calc(J3DMtxCalcBasic *this,ushort param_1)

{
  calc((J3DMtxCalcBasic *)((int)&this[-1].vderiv + (int)(this->mCurrentMtx).m[2][0]),param_1);
  return;
}


/* [thunk]:__thiscall J3DMtxCalcMaya::calcTransform(unsigned short,
                                                    J3DTransformInfo const &) */

void __thiscall
J3DMtxCalcMaya::calcTransform(J3DMtxCalcMaya *this,ushort param_1,J3DTransformInfo *param_2)

{
  calcTransform(this + *(int *)(this + 0x24) + -0x50,param_1,param_2);
  return;
}


/* [thunk]:__thiscall J3DMtxCalcBasic::recursiveCalc(J3DNode *) */

void __thiscall J3DMtxCalcBasic::recursiveCalc(J3DMtxCalcBasic *this,J3DNode *param_1)

{
  recursiveCalc((J3DMtxCalcBasic *)((int)&this[-1].vderiv + (int)(this->mCurrentMtx).m[2][0]),
                param_1);
  return;
}


/* [thunk]:__thiscall J3DMtxCalcMaya::init(Vec const &,
                                           float const &[][][]) */

int __thiscall J3DMtxCalcMaya::init(J3DMtxCalcMaya *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = init(this + *(int *)(this + 0x24) + -0x50,ctx);
  return iVar1;
}


/* __thiscall J3DNode::calcOut(void) */

void __thiscall J3DNode::calcOut(J3DNode *this)

{
  return;
}


/* __thiscall J3DNode::calcIn(void) */

void __thiscall J3DNode::calcIn(J3DNode *this)

{
  return;
}


/* __thiscall J3DNode::init(J3DModelData *) */

int __thiscall J3DNode::init(J3DNode *this,EVP_PKEY_CTX *ctx)

{
  return (int)this;
}

