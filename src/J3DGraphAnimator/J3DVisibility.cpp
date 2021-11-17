#include <J3DGraphAnimator/J3DVisibility.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J3DGraphAnimator/J3DAnimation.h>
#include <JKernel/JKRHeap.h>
#include <J3DVisibilityManager.h>


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DVisibilityManager::setVisibility(J3DModelData *) */

void __thiscall J3DVisibilityManager::setVisibility(J3DVisibilityManager *this,J3DModelData *pModel)

{
  J3DShape *pShape;
  ushort uVar1;
  uchar vis;
  uchar local_15;
  
  if (((this->mbActive & 1) != 0) && (this->mpAnm != (J3DAnmVisibilityFull *)0x0)) {
    for (uVar1 = 0; uVar1 < (pModel->mShapeTable).mShapeCount; uVar1 = uVar1 + 1) {
      vis = '\0';
      J3DAnmVisibilityFull::getVisibility(this->mpAnm,uVar1,&vis);
      if (vis == '\0') {
        pShape = (pModel->mShapeTable).mpShapes[uVar1];
        pShape->mVisFlags = pShape->mVisFlags | 1;
      }
      else {
        pShape = (pModel->mShapeTable).mpShapes[uVar1];
        pShape->mVisFlags = pShape->mVisFlags & 0xfffffffe;
      }
    }
  }
  return;
}


/* __thiscall J3DVisibilityManager::~J3DVisibilityManager(void) */

void __thiscall J3DVisibilityManager::_J3DVisibilityManager(J3DVisibilityManager *this)

{
  short in_r4;
  
  if ((this != (J3DVisibilityManager *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

