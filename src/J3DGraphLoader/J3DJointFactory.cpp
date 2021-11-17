#include <J3DGraphLoader/J3DJointFactory.h>
#include <J3DGraphLoader/J3DJointFactory.h>
#include <J3DGraphLoader/J3DModelLoader.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <J3DGraphAnimator/J3DNode.h>
#include <J3DGraphAnimator/J3DJoint.h>
#include <J3DJointFactory.h>


/* __thiscall J3DJointFactory::J3DJointFactory(J3DJointBlock const &) */

void __thiscall J3DJointFactory::J3DJointFactory(J3DJointFactory *this,J3DJointBlock *param_1)

{
  int iVar1;
  
  iVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,param_1->field_0xc);
  this->field_0x0 = iVar1;
  iVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,param_1->field_0x10);
  this->field_0x4 = iVar1;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DJointFactory::create(int) */

J3DJoint * __thiscall J3DJointFactory::create(J3DJointFactory *this,int param_1)

{
  int iVar1;
  J3DJoint *joint;
  float *pfVar2;
  
  joint = (J3DJoint *)JKernel::operator_new(100);
  if (joint != (J3DJoint *)0x0) {
    J3DNode::J3DNode((J3DNode *)joint);
    (joint->parent).vtbl = &J3DJoint::__vt;
    J3DJoint::initialize(joint);
  }
  (joint->parent).mAnmMatrixIdx = (short)param_1;
  iVar1 = param_1 * 2;
  joint->mMtxTypeFlags =
       (byte)*(undefined2 *)(this->field_0x0 + (uint)*(ushort *)(this->field_0x4 + iVar1) * 0x40);
  joint->mbIgnoreParentScale =
       *(byte *)(this->field_0x0 + (uint)*(ushort *)(this->field_0x4 + iVar1) * 0x40 + 2);
  pfVar2 = (float *)(this->field_0x0 + (uint)*(ushort *)(this->field_0x4 + iVar1) * 0x40 + 4);
  (joint->mTransformInfo).mScale.x = *pfVar2;
  (joint->mTransformInfo).mScale.y = pfVar2[1];
  (joint->mTransformInfo).mScale.z = pfVar2[2];
  (joint->mTransformInfo).mRot.x = *(short *)(pfVar2 + 3);
  (joint->mTransformInfo).mRot.y = *(short *)((int)pfVar2 + 0xe);
  (joint->mTransformInfo).mRot.z = *(short *)(pfVar2 + 4);
  (joint->mTransformInfo).mTranslation.x = pfVar2[5];
  (joint->mTransformInfo).mTranslation.y = pfVar2[6];
  (joint->mTransformInfo).mTranslation.z = pfVar2[7];
  joint->mBoundingSphereRadius =
       *(float *)(this->field_0x0 + (uint)*(ushort *)(this->field_0x4 + iVar1) * 0x40 + 0x24);
  pfVar2 = (float *)(this->field_0x0 + (uint)*(ushort *)(this->field_0x4 + iVar1) * 0x40 + 0x28);
  (joint->mBBoxMin).x = *pfVar2;
  (joint->mBBoxMin).y = pfVar2[1];
  (joint->mBBoxMin).z = pfVar2[2];
  pfVar2 = (float *)(this->field_0x0 + (uint)*(ushort *)(this->field_0x4 + iVar1) * 0x40 + 0x34);
  (joint->mBBoxMax).x = *pfVar2;
  (joint->mBBoxMax).y = pfVar2[1];
  (joint->mBBoxMax).z = pfVar2[2];
  joint->mpMtxCalc = (J3DMtxCalc *)0x0;
  joint->mpOldMtxCalc = (J3DMtxCalc *)0x0;
  if (joint->mbIgnoreParentScale == 0xff) {
    joint->mbIgnoreParentScale = 0;
  }
  return joint;
}


namespace J3DGraphLoader {

/* __stdcall JSUConvertOffsetToPtr<J3DJointInitData>(void const *,
                                                     unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}

