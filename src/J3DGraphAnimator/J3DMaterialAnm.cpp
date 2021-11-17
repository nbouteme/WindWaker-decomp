#include <J3DGraphAnimator/J3DMaterialAnm.h>
#include <J3DGraphAnimator/J3DAnimation.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J3DGraphAnimator/J3DMaterialAnm.h>
#include <J3DTexNoAnm.h>
#include <J3DTexMtxAnm.h>
#include <J3DTevColorAnm.h>
#include <J3DMaterialAnm.h>
#include <J3DTevKColorAnm.h>
#include <J3DMatColorAnm.h>


/* __thiscall J3DMatColorAnm::calc(_GXColor *) const */

void __thiscall J3DMatColorAnm::calc(J3DMatColorAnm *this,_GXColor *param_1)

{
  (**(code **)(**(int **)(this + 4) + 0xc))(*(int **)(this + 4),*(undefined2 *)this,param_1);
  return;
}


/* __thiscall J3DTexMtxAnm::calc(J3DTextureSRTInfo *) const */

void __thiscall J3DTexMtxAnm::calc(J3DTexMtxAnm *this,J3DTextureSRTInfo *param_1)

{
  J3DAnmTextureSRTKey::calcTransform
            (this->mpAnm,(this->mpAnm->parent).mCurrentTime,this->mMatIndex,param_1);
  return;
}


/* __thiscall J3DTexNoAnm::calc(unsigned short *) const */

void __thiscall J3DTexNoAnm::calc(J3DTexNoAnm *this,ushort *param_1)

{
  J3DAnmTexPattern::getTexNo(*(J3DAnmTexPattern **)&this->field_0x8,this->field_0x4,param_1);
  return;
}


/* __thiscall J3DTevColorAnm::calc(_GXColorS10 *) const */

void __thiscall J3DTevColorAnm::calc(J3DTevColorAnm *this,_BAD__GXColorS10 *param_1)

{
  J3DAnmTevRegKey::getTevColorReg(this->mpAnm,this->mIdx,param_1);
  return;
}


/* __thiscall J3DTevKColorAnm::calc(_GXColor *) const */

void __thiscall J3DTevKColorAnm::calc(J3DTevKColorAnm *this,_GXColor *param_1)

{
  J3DAnmTevRegKey::getTevKonstReg(this->mpAnm,this->mIdx,param_1);
  return;
}


/* __thiscall J3DMaterialAnm::initialize(void) */

void __thiscall J3DMaterialAnm::initialize(J3DMaterialAnm *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 2;
  do {
    *(undefined4 *)((int)this->mpMatColorAnm + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar1 = 0;
  iVar2 = 8;
  do {
    *(undefined4 *)((int)this->mpTexNoAnm + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar1 = 0;
  iVar2 = 4;
  do {
    *(undefined4 *)((int)this->mpTevColorAnm + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar1 = 0;
  iVar2 = 4;
  do {
    *(undefined4 *)((int)this->mpTevKColorAnm + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar1 = 0;
  iVar2 = 8;
  do {
    *(undefined4 *)((int)this->mpTexMtxAnm + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DMaterialAnm::calc(J3DMaterial *) const */

void __thiscall J3DMaterialAnm::calc(J3DMaterialAnm *this,J3DMaterial *param_1)

{
  _GXColor *p_Var1;
  int *piVar2;
  _BAD__GXColorS10 *p_Var3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined2 local_28 [10];
  
  uVar5 = 0;
  iVar6 = 0;
  do {
    if (*(int *)((int)this->mpMatColorAnm + iVar6) != 0) {
      p_Var1 = (_GXColor *)
               (*(code *)param_1->mpColorBlock->vtbl->getMatColor)(param_1->mpColorBlock,uVar5);
      J3DMatColorAnm::calc(*(J3DMatColorAnm **)((int)this->mpMatColorAnm + iVar6),p_Var1);
    }
    uVar5 = uVar5 + 1;
    iVar6 = iVar6 + 4;
  } while (uVar5 < 2);
  uVar5 = 0;
  iVar6 = 0;
  do {
    piVar2 = *(int **)((int)this->mpTexNoAnm + iVar6);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,local_28);
      (*(code *)param_1->mpTevBlock->vtbl->setTexNo_1)(param_1->mpTevBlock,uVar5,local_28[0]);
    }
    uVar5 = uVar5 + 1;
    iVar6 = iVar6 + 4;
  } while (uVar5 < 8);
  uVar5 = 0;
  iVar6 = 0;
  do {
    if (*(int *)((int)this->mpTevColorAnm + iVar6) != 0) {
      p_Var3 = (_BAD__GXColorS10 *)
               (*(code *)param_1->mpTevBlock->vtbl->getTevColor)(param_1->mpTevBlock,uVar5);
      J3DTevColorAnm::calc(*(J3DTevColorAnm **)((int)this->mpTevColorAnm + iVar6),p_Var3);
    }
    uVar5 = uVar5 + 1;
    iVar6 = iVar6 + 4;
  } while (uVar5 < 3);
  uVar5 = 0;
  iVar6 = 0;
  do {
    if (*(int *)((int)this->mpTevKColorAnm + iVar6) != 0) {
      p_Var1 = (_GXColor *)
               (*(code *)param_1->mpTevBlock->vtbl->getTevKColor)(param_1->mpTevBlock,uVar5);
      J3DTevKColorAnm::calc(*(J3DTevKColorAnm **)((int)this->mpTevKColorAnm + iVar6),p_Var1);
    }
    uVar5 = uVar5 + 1;
    iVar6 = iVar6 + 4;
  } while (uVar5 < 4);
  uVar5 = 0;
  iVar6 = 0;
  do {
    if (*(int *)((int)this->mpTexMtxAnm + iVar6) != 0) {
      iVar4 = (*(code *)param_1->mpTexGenBlock->vtbl->getTexMtx)(param_1->mpTexGenBlock,uVar5);
      J3DTexMtxAnm::calc(*(J3DTexMtxAnm **)((int)this->mpTexMtxAnm + iVar6),
                         (J3DTextureSRTInfo *)(iVar4 + 0x10));
    }
    uVar5 = uVar5 + 1;
    iVar6 = iVar6 + 4;
  } while (uVar5 < 8);
  return;
}

