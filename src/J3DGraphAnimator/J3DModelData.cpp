#include <J3DGraphAnimator/J3DModelData.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J3DGraphAnimator/J3DModelData.h>
#include <J3DGraphAnimator/J3DNode.h>
#include <J3DGraphAnimator/J3DJoint.h>
#include <J3DGraphBase/J3DVertex.h>
#include <J3DGraphAnimator/J3DMaterialAttach.h>
#include <JKernel/JKRHeap.h>
#include <J3DGraphBase/J3DShape.h>
#include <gd/GDBase.h>
#include <JUtility/JUTNameTab.h>
#include <J3DGraphBase/J3DMaterial.h>
#include <Demangler/J3DNode.h>
#include <Demangler/J3DModelData.h>
#include <J3DJointTree.h>


namespace J3DModelData {
}

/* __thiscall J3DJointTree::clear(void) */

void __thiscall J3DJointTree::clear(J3DJointTree *this)

{
  this->mpHierarchy = (J3DModelHierarchy *)0x0;
  this->mMatrixCalcFlags = 0;
  this->mbIsBDL = 0;
  this->mpRootJoint = (J3DJoint *)0x0;
  this->mpMtxCalc = (undefined *)0x0;
  this->mJointCount = 0;
  this->mpJoints = (J3DJoint **)0x0;
  this->mpImportantMtxForDraw = (ushort *)0x0;
  this->mEnvelopeCount = 0;
  this->mpEnvJointCountTable = (char *)0x0;
  this->mpEnvJointIndexTable = (ushort *)0x0;
  this->mpEnvWeightTable = (float *)0x0;
  this->mpEnvInvBindPoseTable = (MTX34 *)0x0;
  this->mpNameTable = (JUTNameTab *)0x0;
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __thiscall J3DJointTree::makeHierarchy(J3DNode *,
                                          J3DModelHierarchy const * *,
                                          J3DMaterialTable *,
                                          J3DShape * *) */

void __thiscall
J3DJointTree::makeHierarchy
          (J3DJointTree *this,J3DJoint *param_1,J3DModelHierarchy **param_2,
          J3DMaterialTable *param_3,J3DShape **param_4)

{
  J3DJoint **pJoints;
  int iVar1;
  J3DModelHierarchy *pInf;
  J3DShape *pJVar2;
  J3DMaterial *pJVar3;
  J3DJoint *pJVar4;
  J3DJoint *pJVar5;
  
  pJVar5 = param_1;
  do {
    pJVar4 = (J3DJoint *)0x0;
    pJVar3 = (J3DMaterial *)0x0;
    pJVar2 = (J3DShape *)0x0;
    pInf = *param_2;
    switch(pInf->mHierarchyType) {
    case 0:
      return;
    case 1:
      *param_2 = pInf + 1;
      makeHierarchy(this,pJVar5,param_2,param_3,param_4);
      break;
    case 2:
      *param_2 = pInf + 1;
      return;
    case 0x10:
      pJoints = this->mpJoints;
      *param_2 = pInf + 1;
      pJVar4 = pJoints[(ushort)pInf->mHierarchyValue];
      break;
    case 0x11:
      *param_2 = pInf + 1;
      pJVar3 = param_3->mpMaterials[(ushort)pInf->mHierarchyValue];
      break;
    case 0x12:
      *param_2 = pInf + 1;
      pJVar2 = param_4[(ushort)pInf->mHierarchyValue];
    }
    if (pJVar4 == (J3DJoint *)0x0) {
      if ((pJVar3 == (J3DMaterial *)0x0) ||
         (iVar1 = (*(code *)((param_1->parent).vtbl)->getType)(param_1), iVar1 != 0x4e4a4e54)) {
        if ((pJVar2 != (J3DShape *)0x0) &&
           (iVar1 = (*(code *)((param_1->parent).vtbl)->getType)(param_1), iVar1 == 0x4e4a4e54)) {
          pJVar3 = param_1->mpMaterial;
          pJVar3->mpShape = pJVar2;
          pJVar2->mpMaterial = pJVar3;
        }
      }
      else {
        J3DJoint::addMesh(param_1,pJVar3);
        pJVar3->mpJoint = param_1;
      }
    }
    else {
      pJVar5 = pJVar4;
      if (param_1 == (J3DJoint *)0x0) {
        this->mpRootJoint = pJVar4;
      }
      else {
        J3DNode::appendChild(&param_1->parent,&pJVar4->parent);
      }
    }
  } while( true );
}


/* __thiscall J3DModelData::clear(void) */

void __thiscall J3DModelData::clear(J3DModelData *this)

{
  this->mpData = (void *)0x0;
  this->mLoadArgs = 0;
  this->field_0xc = 0;
  this->field_0xe = 0;
  (this->mShapeTable).mShapeCount = 0;
  (this->mShapeTable).mpShapes = (J3DShape **)0x0;
  this->mpNameTab = (JUTNameTab *)0x0;
  *(undefined4 *)&(this->mVertexData).field_0x58 = 0;
  return;
}


/* __thiscall J3DModelData::J3DModelData(void) */

void __thiscall J3DModelData::J3DModelData(J3DModelData *this)

{
  this->vtbl = &__vt;
  (this->mJointTree).vtbl = &J3DJointTree::__vt;
  J3DDrawMtxData::J3DDrawMtxData(&(this->mJointTree).mDrawMtxData);
  J3DJointTree::clear(&this->mJointTree);
  J3DMaterialTable::J3DMaterialTable(&this->mMaterialTable);
  J3DVertexData::J3DVertexData(&this->mVertexData);
  clear(this);
  return;
}


/* __thiscall J3DModelData::~J3DModelData(void) */

void __thiscall J3DModelData::_J3DModelData(J3DModelData *this)

{
  short in_r4;
  
  if (this != (J3DModelData *)0x0) {
    this->vtbl = &__vt;
    J3DVertexData::_J3DVertexData(&this->mVertexData);
    J3DMaterialTable::_J3DMaterialTable(&this->mMaterialTable);
    if (this != (J3DModelData *)0xfffffff0) {
      (this->mJointTree).vtbl = &J3DJointTree::__vt;
      J3DDrawMtxData::_J3DDrawMtxData(&(this->mJointTree).mDrawMtxData);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DModelData::initShapeNodes(void) */

void __thiscall J3DModelData::initShapeNodes(J3DModelData *this)

{
  J3DShape *this_00;
  ushort uVar1;
  
  for (uVar1 = 0; uVar1 < (this->mShapeTable).mShapeCount; uVar1 = uVar1 + 1) {
    this_00 = (this->mShapeTable).mpShapes[uVar1];
    this_00->mpDrawMtxData = &(this->mJointTree).mDrawMtxData;
    this_00->mpVertexData = &this->mVertexData;
    J3DShape::makeVcdVatCmd(this_00);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall J3DModelData::sortVcdVatCmd(void) */

void __thiscall J3DModelData::sortVcdVatCmd(J3DModelData *this)

{
  char cVar1;
  J3DShape **ppJVar2;
  ushort uVar3;
  ushort uVar4;
  
  for (uVar4 = 0; uVar4 < (this->mShapeTable).mShapeCount; uVar4 = uVar4 + 1) {
    uVar3 = 0;
    while( true ) {
      if (uVar4 <= uVar3) break;
      ppJVar2 = (this->mShapeTable).mpShapes;
      cVar1 = J3DShape::isSameVcdVatCmd(ppJVar2[uVar4],ppJVar2[uVar3]);
      if (cVar1 != '\0') {
        ppJVar2 = (this->mShapeTable).mpShapes;
        ppJVar2[uVar4]->mpVatVcdCmd = ppJVar2[uVar3]->mpVatVcdCmd;
      }
      uVar3 = uVar3 + 1;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DModelData::indexToPtr(void) */

void __thiscall J3DModelData::indexToPtr(J3DModelData *this)

{
  J3DDisplayListObj *pJVar1;
  ushort uVar2;
  undefined auStack40 [24];
  
  J3DGraphBase::j3dSys.mpCurTex = (this->mMaterialTable).mpTexture;
  for (uVar2 = 0; uVar2 < (this->mMaterialTable).mMaterialCount; uVar2 = uVar2 + 1) {
    pJVar1 = (this->mMaterialTable).mpMaterials[uVar2]->mpDLObj;
    gd::GDInitGDLObj(auStack40,pJVar1->mpData[0],pJVar1->mSize);
    gd::__GDCurrentDL = auStack40;
    (*(code *)(this->mMaterialTable).mpMaterials[uVar2]->mpTevBlock->vtbl->field_0x3c)();
  }
  gd::__GDCurrentDL = (undefined *)0x0;
  return;
}


/* __thiscall J3DModelData::isDeformablePositionFormat(void) const */

undefined4 __thiscall J3DModelData::isDeformablePositionFormat(J3DModelData *this)

{
  int *piVar1;
  
  piVar1 = (int *)(this->mVertexData).mpAttribFormats;
  while( true ) {
    if (*piVar1 == 0xff) {
      return 0;
    }
    if (((*piVar1 == 9) && (piVar1[2] == 4)) && (piVar1[1] == 1)) break;
    piVar1 = piVar1 + 4;
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DModelData::setMaterialTable(J3DMaterialTable *,
                                             J3DMaterialCopyFlag) */

void __thiscall
J3DModelData::setMaterialTable
          (J3DModelData *this,J3DMaterialTable *param_1,J3DMaterialCopyFlag param_2)

{
  char *pcVar1;
  uint uVar2;
  ushort uVar3;
  JUTNameTab *this_00;
  
  if ((param_2 & 1) != 0) {
    uVar3 = 0;
    while( true ) {
      if (param_1->mMaterialCount <= uVar3) break;
      this_00 = (this->mMaterialTable).mpNameTab;
      pcVar1 = (char *)JUTNameTab::getName(param_1->mpNameTab,uVar3);
      uVar2 = JUTNameTab::getIndex(this_00,pcVar1);
      if (uVar2 != 0xffffffff) {
        J3DMaterial::copy((this->mMaterialTable).mpMaterials[uVar2 & 0xffff],
                          param_1->mpMaterials[uVar3]);
      }
      uVar3 = uVar3 + 1;
    }
  }
  if (((param_2 & 2) != 0) && (param_1->mpTexture->mCount != 0)) {
    (this->mMaterialTable).mpTexture = param_1->mpTexture;
    (this->mMaterialTable).mpTexNameTab = param_1->mpTexNameTab;
  }
  return;
}


/* __thiscall J3DNode::getType(void) const */

undefined4 __thiscall J3DNode::getType(J3DNode *this)

{
  return 0x4e4e4f4e;
}


/* __thiscall J3DJointTree::~J3DJointTree(void) */

void __thiscall J3DJointTree::_J3DJointTree(J3DJointTree *this)

{
  short in_r4;
  
  if (this != (J3DJointTree *)0x0) {
    this->vtbl = &__vt;
    J3DDrawMtxData::_J3DDrawMtxData(&this->mDrawMtxData);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

