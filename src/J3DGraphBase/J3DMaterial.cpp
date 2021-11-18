#include <J3DGraphBase/J3DMaterial.h>
#include <JKernel/JKRHeap.h>
#include <m_Do_ext.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <J3DGraphBase/J3DMatBlock.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J3DGraphBase/J3DPacket.h>
#include <J3DGraphBase/J3DGD.h>
#include <J3DGraphBase/J3DMaterial.h>
#include <J3DGraphBase/J3DTevs.h>
#include <J3DTexGenBlockPatched.h>
#include <J3DTexGenBlock.h>
#include <J3DPatchedMaterial.h>
#include <J3DPEBlock.h>
#include <J3DTevBlock.h>
#include <Demangler/J3DMaterial.h>
#include <J3DColorBlockLightOff.h>
#include <J3DLockedMaterial.h>
#include <J3DColorBlock.h>
#include <J3DIndBlock.h>
#include <J3DIndBlockNull.h>


namespace J3DMaterial {
}

namespace J3DMaterial {

/* __thiscall createColorBlock(unsigned long) */

J3DColorBlockLightOn * createColorBlock(ulong param_1)

{
  J3DColorBlockLightOn *this;
  
  this = (J3DColorBlockLightOn *)0x0;
  if (param_1 == 0) {
    this = (J3DColorBlockLightOn *)JKernel::operator_new(0x20);
    if (this != (J3DColorBlockLightOn *)0x0) {
      (this->parent).vtbl = (J3DColorBlock__vtbl *)&J3DColorBlock::__vt;
      (this->parent).vtbl = (J3DColorBlock__vtbl *)&J3DColorBlockLightOff::__vt;
      Runtime.PPCEABI.H::__construct_array
                (this->mColors,J3DGXColor::J3DGXColor,(undefined *)0x0,4,2);
      Runtime.PPCEABI.H::__construct_array
                ((void *)((int)this->mColors + 10),J3DColorChan::J3DColorChan,(undefined *)0x0,2,4);
      J3DColorBlockLightOff::initialize((J3DColorBlockLightOff *)this);
    }
  }
  else {
    if ((int)param_1 < 0) {
      if (((int)param_1 < -0x7fffffff) &&
         (this = (J3DColorBlockLightOn *)JKernel::operator_new(0x28),
         this != (J3DColorBlockLightOn *)0x0)) {
        (this->parent).vtbl = (J3DColorBlock__vtbl *)&J3DColorBlock::__vt;
        (this->parent).vtbl = (J3DColorBlock__vtbl *)&J3DColorBlockLightOff::__vt;
        Runtime.PPCEABI.H::__construct_array
                  (this->mColors,J3DGXColor::J3DGXColor,(undefined *)0x0,4,2);
        Runtime.PPCEABI.H::__construct_array
                  ((void *)((int)this->mColors + 10),J3DColorChan::J3DColorChan,(undefined *)0x0,2,4
                  );
        J3DColorBlockLightOff::initialize((J3DColorBlockLightOff *)this);
        (this->parent).vtbl = (J3DColorBlock__vtbl *)&J3DColorBlockAmbientOn::__vt;
        Runtime.PPCEABI.H::__construct_array
                  (this->mpLights,J3DGXColor::J3DGXColor,(undefined *)0x0,4,2);
        J3DColorBlockAmbientOn::initialize((J3DColorBlockAmbientOn *)this);
      }
    }
    else {
      if ((param_1 == 0x40000000) &&
         (this = (J3DColorBlockLightOn *)JKernel::operator_new(0x4c),
         this != (J3DColorBlockLightOn *)0x0)) {
        (this->parent).vtbl = (J3DColorBlock__vtbl *)&J3DColorBlock::__vt;
        (this->parent).vtbl = (J3DColorBlock__vtbl *)&J3DColorBlockLightOn::__vt;
        Runtime.PPCEABI.H::__construct_array
                  (this->mColors,J3DGXColor::J3DGXColor,(undefined *)0x0,4,2);
        Runtime.PPCEABI.H::__construct_array
                  (this->mColors + 2,J3DGXColor::J3DGXColor,(undefined *)0x0,4,2);
        Runtime.PPCEABI.H::__construct_array
                  (this->mColorChan,J3DColorChan::J3DColorChan,(undefined *)0x0,2,4);
        J3DColorBlockLightOn::initialize(this);
      }
    }
  }
  return this;
}

}

/* __thiscall J3DMaterial::createTexGenBlock(unsigned long) */

J3DTexGenBlockPatched * __thiscall J3DMaterial::createTexGenBlock(J3DMaterial *this,ulong param_1)

{
  J3DTexGenBlockPatched *this_00;
  
  if (this == (J3DMaterial *)0x8000000) {
    this_00 = (J3DTexGenBlockPatched *)JKernel::operator_new(0x5c);
    if (this_00 != (J3DTexGenBlockPatched *)0x0) {
      this_00->vtbl = (J3DTexGenBlock__vtbl *)&J3DTexGenBlock::__vt;
      this_00->vtbl = (J3DTexGenBlock__vtbl *)&J3DTexGenBlockPatched::__vt;
      Runtime.PPCEABI.H::__construct_array
                (this_00 + 1,J3DTexCoord::J3DTexCoord,(undefined *)0x0,4,8);
      J3DTexGenBlockPatched::initialize(this_00);
      this_00->vtbl = (J3DTexGenBlock__vtbl *)&J3DTexGenBlock4::__vt;
      *(undefined *)&this_00[9].field_0x4 = J3DGraphBase::j3dDefaultNBTScaleInfo;
      this_00[10].vtbl = DAT_80370e3c;
      this_00[10].field_0x4 = DAT_80370e40;
      this_00[0xb].vtbl = DAT_80370e44;
      J3DTexGenBlock4::initialize((J3DTexGenBlock4 *)this_00);
    }
  }
  else {
    this_00 = (J3DTexGenBlockPatched *)JKernel::operator_new(0x5c);
    if (this_00 != (J3DTexGenBlockPatched *)0x0) {
      this_00->vtbl = (J3DTexGenBlock__vtbl *)&J3DTexGenBlock::__vt;
      this_00->vtbl = (J3DTexGenBlock__vtbl *)&J3DTexGenBlockPatched::__vt;
      Runtime.PPCEABI.H::__construct_array
                (this_00 + 1,J3DTexCoord::J3DTexCoord,(undefined *)0x0,4,8);
      J3DTexGenBlockPatched::initialize(this_00);
      this_00->vtbl = (J3DTexGenBlock__vtbl *)&J3DTexGenBlockBasic::__vt;
      *(undefined *)&this_00[9].field_0x4 = J3DGraphBase::j3dDefaultNBTScaleInfo;
      this_00[10].vtbl = DAT_80370e3c;
      this_00[10].field_0x4 = DAT_80370e40;
      this_00[0xb].vtbl = DAT_80370e44;
      J3DTexGenBlockBasic::initialize((J3DTexGenBlockBasic *)this_00);
    }
  }
  return this_00;
}


/* __thiscall J3DMaterial::createTevBlock(int) */

undefined ** __thiscall J3DMaterial::createTevBlock(J3DMaterial *this,int param_1)

{
  undefined **this_00;
  
  this_00 = (undefined **)0x0;
  if ((int)this < 2) {
    this_00 = (undefined **)JKernel::operator_new(0x1c);
    if (this_00 != (undefined **)0x0) {
      *this_00 = (undefined *)&J3DTevBlock::__vt;
      *this_00 = &J3DTevBlock1::__vt;
      Runtime.PPCEABI.H::__construct_array
                ((void *)((int)this_00 + 10),J3DTevOrder::J3DTevOrder,(undefined *)0x0,4,1);
      Runtime.PPCEABI.H::__construct_array
                ((void *)((int)this_00 + 0xe),J3DTevStage::J3DTevStage,(undefined *)0x0,8,1);
      Runtime.PPCEABI.H::__construct_array
                (this_00 + 6,J3DIndTevStage::J3DIndTevStage,(undefined *)0x0,4,1);
      J3DTevBlock1::initialize((J3DTevBlock1 *)this_00);
    }
  }
  else {
    if (this == (J3DMaterial *)&DAT_00000002) {
      this_00 = (undefined **)JKernel::operator_new(0x6c);
      if (this_00 != (undefined **)0x0) {
        *this_00 = (undefined *)&J3DTevBlock::__vt;
        *this_00 = &J3DTevBlock2::__vt;
        Runtime.PPCEABI.H::__construct_array
                  (this_00 + 3,J3DTevOrder::J3DTevOrder,(undefined *)0x0,4,2);
        Runtime.PPCEABI.H::__construct_array
                  (this_00 + 5,J3DGXColorS10::J3DGXColorS10,(undefined *)0x0,8,4);
        Runtime.PPCEABI.H::__construct_array
                  ((void *)((int)this_00 + 0x35),J3DTevStage::J3DTevStage,(undefined *)0x0,8,2);
        Runtime.PPCEABI.H::__construct_array
                  ((void *)((int)this_00 + 0x45),J3DGXColor::J3DGXColor,(undefined *)0x0,4,4);
        Runtime.PPCEABI.H::__construct_array
                  ((void *)((int)this_00 + 0x59),J3DTevSwapModeTable::J3DTevSwapModeTable,
                   (undefined *)0x0,1,4);
        Runtime.PPCEABI.H::__construct_array
                  (this_00 + 0x18,J3DIndTevStage::J3DIndTevStage,(undefined *)0x0,4,2);
        J3DTevBlock2::initialize((J3DTevBlock2 *)this_00);
      }
    }
    else {
      if ((int)this < 5) {
        this_00 = (undefined **)JKernel::operator_new(0x94);
        if (this_00 != (undefined **)0x0) {
          *this_00 = (undefined *)&J3DTevBlock::__vt;
          *this_00 = &J3DTevBlock4::__vt;
          Runtime.PPCEABI.H::__construct_array
                    (this_00 + 4,J3DTevOrder::J3DTevOrder,(undefined *)0x0,4,4);
          Runtime.PPCEABI.H::__construct_array
                    ((void *)((int)this_00 + 0x21),J3DTevStage::J3DTevStage,(undefined *)0x0,8,4);
          Runtime.PPCEABI.H::__construct_array
                    ((void *)((int)this_00 + 0x42),J3DGXColorS10::J3DGXColorS10,(undefined *)0x0,8,4
                    );
          Runtime.PPCEABI.H::__construct_array
                    ((void *)((int)this_00 + 0x62),J3DGXColor::J3DGXColor,(undefined *)0x0,4,4);
          Runtime.PPCEABI.H::__construct_array
                    ((void *)((int)this_00 + 0x7a),J3DTevSwapModeTable::J3DTevSwapModeTable,
                     (undefined *)0x0,1,4);
          Runtime.PPCEABI.H::__construct_array
                    (this_00 + 0x20,J3DIndTevStage::J3DIndTevStage,(undefined *)0x0,4,4);
          J3DTevBlock4::initialize((J3DTevBlock4 *)this_00);
        }
      }
      else {
        if (((int)this < 0x11) &&
           (this_00 = (undefined **)JKernel::operator_new(0x174), this_00 != (undefined **)0x0)) {
          *this_00 = (undefined *)&J3DTevBlock::__vt;
          *this_00 = &J3DTevBlock16::__vt;
          Runtime.PPCEABI.H::__construct_array
                    (this_00 + 6,J3DTevOrder::J3DTevOrder,(undefined *)0x0,4,0x10);
          Runtime.PPCEABI.H::__construct_array
                    ((void *)((int)this_00 + 0x59),J3DTevStage::J3DTevStage,(undefined *)0x0,8,0x10)
          ;
          Runtime.PPCEABI.H::__construct_array
                    ((void *)((int)this_00 + 0xda),J3DGXColorS10::J3DGXColorS10,(undefined *)0x0,8,4
                    );
          Runtime.PPCEABI.H::__construct_array
                    ((void *)((int)this_00 + 0xfa),J3DGXColor::J3DGXColor,(undefined *)0x0,4,4);
          Runtime.PPCEABI.H::__construct_array
                    ((void *)((int)this_00 + 0x12a),J3DTevSwapModeTable::J3DTevSwapModeTable,
                     (undefined *)0x0,1,4);
          Runtime.PPCEABI.H::__construct_array
                    (this_00 + 0x4c,J3DIndTevStage::J3DIndTevStage,(undefined *)0x0,4,0x10);
          J3DTevBlock16::initialize((J3DTevBlock16 *)this_00);
        }
      }
    }
  }
  return this_00;
}


/* __thiscall J3DMaterial::createIndBlock(int) */

undefined4 * __thiscall J3DMaterial::createIndBlock(J3DMaterial *this,int param_1)

{
  undefined4 *this_00;
  
  if (this == (J3DMaterial *)0x0) {
    this_00 = (undefined4 *)JKernel::operator_new(4);
    if (this_00 != (undefined4 *)0x0) {
      *this_00 = &J3DIndBlock::__vt;
      *this_00 = &J3DIndBlockNull::__vt;
    }
  }
  else {
    this_00 = (undefined4 *)JKernel::operator_new(0x7c);
    if (this_00 != (undefined4 *)0x0) {
      *this_00 = &J3DIndBlock::__vt;
      *this_00 = &J3DIndBlockFull::__vt;
      Runtime.PPCEABI.H::__construct_array
                ((void *)((int)this_00 + 5),J3DIndTexOrder::J3DIndTexOrder,(undefined *)0x0,4,4);
      Runtime.PPCEABI.H::__construct_array
                (this_00 + 6,J3DIndTexMtx::J3DIndTexMtx,J3DIndTexMtx::_J3DIndTexMtx,0x1c,3);
      Runtime.PPCEABI.H::__construct_array
                (this_00 + 0x1b,J3DIndTexCoordScale::J3DIndTexCoordScale,
                 J3DIndTexCoordScale::_J3DIndTexCoordScale,4,4);
      J3DIndBlockFull::initialize((J3DIndBlockFull *)this_00);
    }
  }
  return this_00;
}


namespace J3DMaterial {

/* __thiscall createPEBlock(unsigned long,
                                         unsigned long) */

J3DPEBlockFull * createPEBlock(ulong param_1,ulong param_2)

{
  J3DPEBlockFull *pJVar1;
  
  pJVar1 = (J3DPEBlockFull *)0x0;
  if (param_1 == 0) {
    if ((param_2 & 1) != 0) {
      pJVar1 = (J3DPEBlockFull *)JKernel::operator_new(4);
      if (pJVar1 == (J3DPEBlockFull *)0x0) {
        return (J3DPEBlockFull *)0x0;
      }
      pJVar1->vtbl = &J3DPEBlock::__vt;
      pJVar1->vtbl = &J3DPEBlockOpa::__vt;
      return pJVar1;
    }
    if ((param_2 & 2) != 0) {
      pJVar1 = (J3DPEBlockFull *)JKernel::operator_new(4);
      if (pJVar1 == (J3DPEBlockFull *)0x0) {
        return (J3DPEBlockFull *)0x0;
      }
      pJVar1->vtbl = &J3DPEBlock::__vt;
      pJVar1->vtbl = &J3DPEBlockTexEdge::__vt;
      return pJVar1;
    }
    if ((param_2 & 4) != 0) {
      pJVar1 = (J3DPEBlockFull *)JKernel::operator_new(4);
      if (pJVar1 == (J3DPEBlockFull *)0x0) {
        return (J3DPEBlockFull *)0x0;
      }
      pJVar1->vtbl = &J3DPEBlock::__vt;
      pJVar1->vtbl = &J3DPEBlockXlu::__vt;
      return pJVar1;
    }
  }
  if (param_1 == 0x10000000) {
    pJVar1 = (J3DPEBlockFull *)JKernel::operator_new(0x18);
    if (pJVar1 != (J3DPEBlockFull *)0x0) {
      pJVar1->vtbl = &J3DPEBlock::__vt;
      pJVar1->vtbl = &J3DPEBlockFull::__vt;
      *(undefined2 *)&pJVar1->mAlphaComp = J3DGraphBase::j3dDefaultAlphaCmpID;
      *(undefined *)((int)&pJVar1->mAlphaComp + 2) = 0;
      *(undefined *)((int)&pJVar1->mAlphaComp + 3) = 0;
      (pJVar1->mBlend).field_0x0 = J3DGraphBase::j3dDefaultBlendInfo;
      (pJVar1->mBlend).field_0x1 = UNK_803fc95d;
      (pJVar1->mBlend).field_0x2 = UNK_803fc95e;
      (pJVar1->mBlend).field_0x3 = UNK_803fc95f;
      pJVar1->mZMode = J3DGraphBase::j3dDefaultZModeID;
      J3DPEBlockFull::initialize(pJVar1);
    }
  }
  else {
    if ((param_1 == 0x20000000) &&
       (pJVar1 = (J3DPEBlockFull *)JKernel::operator_new(0x10), pJVar1 != (J3DPEBlockFull *)0x0)) {
      pJVar1->vtbl = &J3DPEBlock::__vt;
      pJVar1->vtbl = &J3DPEBlockFogOff::__vt;
      *(undefined2 *)&pJVar1->mpFog = J3DGraphBase::j3dDefaultAlphaCmpID;
      *(undefined *)((int)&pJVar1->mpFog + 2) = 0;
      *(undefined *)((int)&pJVar1->mpFog + 3) = 0;
      *(byte *)&pJVar1->mAlphaComp = J3DGraphBase::j3dDefaultBlendInfo;
      *(byte *)((int)&pJVar1->mAlphaComp + 1) = UNK_803fc95d;
      *(byte *)((int)&pJVar1->mAlphaComp + 2) = UNK_803fc95e;
      *(byte *)((int)&pJVar1->mAlphaComp + 3) = UNK_803fc95f;
      *(short *)&pJVar1->mBlend = J3DGraphBase::j3dDefaultZModeID;
      J3DPEBlockFogOff::initialize((J3DPEBlockFogOff *)pJVar1);
    }
  }
  return pJVar1;
}

}

/* __thiscall J3DMaterial::calcSizeColorBlock(unsigned long) */

undefined8 __thiscall J3DMaterial::calcSizeColorBlock(J3DMaterial *this,ulong param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (this == (J3DMaterial *)0x0) {
    uVar1 = 0x20;
  }
  else {
    if ((int)this < 0) {
      param_1 = 0x80000000;
      if ((int)this < -0x7fffffff) {
        uVar1 = 0x28;
      }
    }
    else {
      if (this == (J3DMaterial *)0x40000000) {
        uVar1 = 0x4c;
      }
    }
  }
  return CONCAT44(uVar1,param_1);
}


/* __thiscall J3DMaterial::calcSizeTexGenBlock(unsigned long) */

undefined4 __thiscall J3DMaterial::calcSizeTexGenBlock(J3DMaterial *this,ulong param_1)

{
  if (this == (J3DMaterial *)0x8000000) {
    return 0x5c;
  }
  return 0x5c;
}


/* __thiscall J3DMaterial::calcSizeTevBlock(int) */

undefined4 __thiscall J3DMaterial::calcSizeTevBlock(J3DMaterial *this,int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((int)this < 2) {
    uVar1 = 0x1c;
  }
  else {
    if (this == (J3DMaterial *)&DAT_00000002) {
      uVar1 = 0x6c;
    }
    else {
      if ((int)this < 5) {
        uVar1 = 0x94;
      }
      else {
        if ((int)this < 0x11) {
          uVar1 = 0x174;
        }
      }
    }
  }
  return uVar1;
}


/* __thiscall J3DMaterial::calcSizeIndBlock(int) */

undefined4 __thiscall J3DMaterial::calcSizeIndBlock(J3DMaterial *this,int param_1)

{
  if (this == (J3DMaterial *)0x0) {
    return 4;
  }
  return 0x7c;
}


/* __thiscall J3DMaterial::calcSizePEBlock(unsigned long,
                                           unsigned long) */

undefined4 __thiscall J3DMaterial::calcSizePEBlock(J3DMaterial *this,ulong param_1,ulong param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (this == (J3DMaterial *)0x0) {
    if ((param_1 & 1) == 0) {
      if ((param_1 & 2) == 0) {
        if ((param_1 & 4) != 0) {
          uVar1 = 4;
        }
      }
      else {
        uVar1 = 4;
      }
    }
    else {
      uVar1 = 4;
    }
  }
  else {
    if (this == (J3DMaterial *)0x10000000) {
      uVar1 = 0x18;
    }
    else {
      if (this == (J3DMaterial *)0x20000000) {
        uVar1 = 0x10;
      }
    }
  }
  return uVar1;
}


/* __thiscall J3DMaterial::initialize(void) */

void __thiscall J3DMaterial::initialize(J3DMaterial *this)

{
  this->mpShape = (J3DShape *)0x0;
  this->mpNextMaterial = (J3DMaterial *)0x0;
  this->mpJoint = (J3DJoint *)0x0;
  this->mMaterialMode = 1;
  this->mIdx = -1;
  this->field_0x18 = (undefined *)0x0;
  this->field_0x20 = 0;
  this->mpColorBlock = (J3DColorBlock *)0x0;
  this->mpTexGenBlock = (J3DTexGenBlockPatched *)0x0;
  this->mpTevBlock = (J3DTevBlock *)0x0;
  this->mpIndBlock = (undefined *)0x0;
  this->mpPEBlock = (J3DPEBlockFull *)0x0;
  this->field_0x38 = (undefined *)0x0;
  this->mpMaterialAnm = (J3DMaterialAnm *)0x0;
  this->mpDLObj = (J3DDisplayListObj *)0x0;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DMaterial::countDLSize(void) */

uint __thiscall J3DMaterial::countDLSize(J3DMaterial *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = (*(code *)this->mpTexGenBlock->vtbl->countDLSize)();
  iVar2 = (*(code *)this->mpColorBlock->vtbl->countDLSize)();
  iVar3 = (*(code *)this->mpTevBlock->vtbl->countDLSize)();
  iVar4 = (**(code **)(*(int *)this->mpIndBlock + 0x14))();
  iVar5 = (**(code **)(this->mpPEBlock->vtbl + 0x20))();
  return iVar2 + iVar1 + iVar3 + iVar4 + iVar5 + 0x1f & 0xffffffe0;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall J3DMaterial::makeDisplayList_private(J3DDisplayListObj *) */

void __thiscall J3DMaterial::makeDisplayList_private(J3DMaterial *this,J3DDisplayListObj *param_1)

{
  undefined uVar4;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined uVar5;
  undefined *puVar6;
  
  J3DDisplayListObj::beginDL(param_1);
  (*(code *)this->mpTevBlock->vtbl->load)();
  (**(code **)(*(int *)this->mpIndBlock + 0x10))();
  (**(code **)(this->mpPEBlock->vtbl + 0xc))();
  uVar4 = (*(code *)this->mpColorBlock->vtbl->getCullMode)();
  uVar1 = (**(code **)(*(int *)this->mpIndBlock + 0x20))();
  uVar2 = (*(code *)this->mpTevBlock->vtbl->getTevStageNum)();
  uVar3 = (*(code *)this->mpColorBlock->vtbl->getColorChanNum)();
  uVar5 = (*(code *)this->mpTexGenBlock->vtbl->getTexGenNum)();
  J3DGraphBase::J3DGDSetGenMode(uVar5,uVar3,uVar2,uVar1,uVar4);
  (*(code *)this->mpTexGenBlock->vtbl->load)();
  (*(code *)this->mpColorBlock->vtbl->load)();
  uVar4 = (*(code *)this->mpColorBlock->vtbl->getColorChanNum)();
  puVar6 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar6 + 1;
  *puVar6 = 0x10;
  puVar6 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar6 + 1;
  *puVar6 = 0;
  puVar6 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar6 + 1;
  *puVar6 = 0;
  puVar6 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar6 + 1;
  *puVar6 = 0x10;
  puVar6 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar6 + 1;
  *puVar6 = 9;
  puVar6 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar6 + 1;
  *puVar6 = 0;
  puVar6 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar6 + 1;
  *puVar6 = 0;
  puVar6 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar6 + 1;
  *puVar6 = 0;
  puVar6 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar6 + 1;
  *puVar6 = uVar4;
  uVar4 = (*(code *)this->mpTexGenBlock->vtbl->getTexGenNum)();
  puVar6 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar6 + 1;
  *puVar6 = 0x10;
  puVar6 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar6 + 1;
  *puVar6 = 0;
  puVar6 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar6 + 1;
  *puVar6 = 0;
  puVar6 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar6 + 1;
  *puVar6 = 0x10;
  puVar6 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar6 + 1;
  *puVar6 = 0x3f;
  puVar6 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar6 + 1;
  *puVar6 = 0;
  puVar6 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar6 + 1;
  *puVar6 = 0;
  puVar6 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar6 + 1;
  *puVar6 = 0;
  puVar6 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar6 + 1;
  *puVar6 = uVar4;
  J3DDisplayListObj::endDL(param_1);
  return;
}


/* __thiscall J3DMaterial::makeDisplayList(void) */

void __thiscall J3DMaterial::makeDisplayList(J3DMaterial *this)

{
  if ((((J3DGraphBase::j3dSys.mpCurMatPacket)->parent).mFlags & 1U) == 0) {
    (J3DGraphBase::j3dSys.mpCurMatPacket)->mSortFlags = this->field_0x20;
    makeDisplayList_private(this,((J3DGraphBase::j3dSys.mpCurMatPacket)->parent).mpDLObj);
  }
  return;
}


/* __thiscall J3DMaterial::makeSharedDisplayList(void) */

void __thiscall J3DMaterial::makeSharedDisplayList(J3DMaterial *this)

{
  makeDisplayList_private(this,this->mpDLObj);
  return;
}


/* __thiscall J3DMaterial::load(void) */

void __thiscall J3DMaterial::load(J3DMaterial *this)

{
  J3DGraphBase::j3dSys.mCurMaterialMode = this->mMaterialMode;
  if ((J3DGraphBase::j3dSys.mCurFlags & 2) == 0) {
    J3DDisplayListObj::callDL(((J3DGraphBase::j3dSys.mpCurMatPacket)->parent).mpDLObj);
    (*(code *)this->mpTexGenBlock->vtbl->getNBTScale)();
    J3DGraphBase::loadNBTScale();
  }
  return;
}


/* __thiscall J3DMaterial::loadSharedDL(void) */

void __thiscall J3DMaterial::loadSharedDL(J3DMaterial *this)

{
  J3DGraphBase::j3dSys.mCurMaterialMode = this->mMaterialMode;
  if ((J3DGraphBase::j3dSys.mCurFlags & 2) == 0) {
    J3DDisplayListObj::callDL(this->mpDLObj);
    (*(code *)this->mpTexGenBlock->vtbl->getNBTScale)();
    J3DGraphBase::loadNBTScale();
  }
  return;
}


/* __thiscall J3DMaterial::patch(void) */

void __thiscall J3DMaterial::patch(J3DMaterial *this)

{
  (J3DGraphBase::j3dSys.mpCurMatPacket)->mSortFlags = this->field_0x20;
  J3DDisplayListObj::beginPatch(((J3DGraphBase::j3dSys.mpCurMatPacket)->parent).mpDLObj);
  (*(code *)this->mpTevBlock->vtbl->patch)();
  (*(code *)this->mpColorBlock->vtbl->patch)();
  (*(code *)this->mpTexGenBlock->vtbl->patch)();
  J3DDisplayListObj::endPatch(((J3DGraphBase::j3dSys.mpCurMatPacket)->parent).mpDLObj);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DMaterial::diff(unsigned long) */

void __thiscall J3DMaterial::diff(J3DMaterial *this,ulong param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined uVar3;
  undefined *puVar4;
  
  if (((J3DGraphBase::j3dSys.mpCurMatPacket)->mpShapePacket->parent).mpDLObj !=
      (J3DDisplayListObj *)0x0) {
    J3DMatPacket::beginDiff(J3DGraphBase::j3dSys.mpCurMatPacket);
    (*(code *)this->mpTevBlock->vtbl->diff)(this->mpTevBlock,param_1);
    (**(code **)(*(int *)this->mpIndBlock + 0xc))(this->mpIndBlock,param_1);
    (**(code **)(this->mpPEBlock->vtbl + 0x14))(this->mpPEBlock,param_1);
    if ((param_1 & 0x2000000) != 0) {
      uVar1 = (**(code **)(*(int *)this->mpIndBlock + 0x20))();
      uVar2 = (*(code *)this->mpTevBlock->vtbl->getTevStageNum)();
      uVar3 = (*(code *)this->mpTexGenBlock->vtbl->getTexGenNum)();
      J3DGraphBase::J3DGDSetGenMode_3Param(uVar3,uVar2,uVar1);
      uVar3 = (*(code *)this->mpTexGenBlock->vtbl->getTexGenNum)();
      puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
      *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
      *puVar4 = 0x10;
      puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
      *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
      *puVar4 = 0;
      puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
      *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
      *puVar4 = 0;
      puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
      *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
      *puVar4 = 0x10;
      puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
      *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
      *puVar4 = 0x3f;
      puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
      *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
      *puVar4 = 0;
      puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
      *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
      *puVar4 = 0;
      puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
      *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
      *puVar4 = 0;
      puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
      *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
      *puVar4 = uVar3;
    }
    (*(code *)this->mpTexGenBlock->vtbl->diff)(this->mpTexGenBlock,param_1);
    (*(code *)this->mpColorBlock->vtbl->diff)(this->mpColorBlock,param_1);
    J3DMatPacket::endDiff(J3DGraphBase::j3dSys.mpCurMatPacket);
  }
  return;
}


/* __thiscall J3DMaterial::calc(float const *[][][][]) */

void __thiscall J3DMaterial::calc(J3DMaterial *this,float *param_1)

{
  (*(code *)this->mpTexGenBlock->vtbl->calc)();
  calcCurrentMtx(this);
  setCurrentMtx(this);
  return;
}


/* __thiscall J3DMaterial::setCurrentMtx(void) */

void __thiscall J3DMaterial::setCurrentMtx(J3DMaterial *this)

{
  J3DShape *pJVar1;
  
  pJVar1 = this->mpShape;
  pJVar1->field_0x40 = this->field_0x40;
  pJVar1->field_0x44 = this->field_0x44;
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall J3DMaterial::calcCurrentMtx(void) */

void __thiscall J3DMaterial::calcCurrentMtx(J3DMaterial *this)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  int iVar8;
  
  iVar8 = (*(code *)this->mpTexGenBlock->vtbl->getTexCoord)(this->mpTexGenBlock,7);
  bVar1 = *(byte *)(iVar8 + 2);
  iVar8 = (*(code *)this->mpTexGenBlock->vtbl->getTexCoord)(this->mpTexGenBlock,6);
  bVar2 = *(byte *)(iVar8 + 2);
  iVar8 = (*(code *)this->mpTexGenBlock->vtbl->getTexCoord)(this->mpTexGenBlock,5);
  bVar3 = *(byte *)(iVar8 + 2);
  iVar8 = (*(code *)this->mpTexGenBlock->vtbl->getTexCoord)(this->mpTexGenBlock,4);
  bVar4 = *(byte *)(iVar8 + 2);
  iVar8 = (*(code *)this->mpTexGenBlock->vtbl->getTexCoord)(this->mpTexGenBlock,3);
  bVar5 = *(byte *)(iVar8 + 2);
  iVar8 = (*(code *)this->mpTexGenBlock->vtbl->getTexCoord)(this->mpTexGenBlock,2);
  bVar6 = *(byte *)(iVar8 + 2);
  iVar8 = (*(code *)this->mpTexGenBlock->vtbl->getTexCoord)(this->mpTexGenBlock,1);
  bVar7 = *(byte *)(iVar8 + 2);
  iVar8 = (*(code *)this->mpTexGenBlock->vtbl->getTexCoord)(this->mpTexGenBlock,0);
  this->field_0x40 =
       (undefined *)
       ((uint)bVar5 << 0x18 |
       (uint)bVar6 << 0x12 | (uint)*(byte *)(iVar8 + 2) << 6 | (uint)bVar7 << 0xc);
  this->field_0x44 =
       (undefined *)((uint)bVar1 << 0x12 | (uint)bVar2 << 0xc | (uint)bVar4 | (uint)bVar3 << 6);
  return;
}


/* __thiscall J3DMaterial::copy(J3DMaterial *) */

int __thiscall J3DMaterial::copy(J3DMaterial *this,J3DMaterial *src)

{
  int iVar1;
  
  (*(code *)this->mpColorBlock->vtbl->reset)(this->mpColorBlock,src->mpColorBlock);
  (*(code *)this->mpTexGenBlock->vtbl->reset)(this->mpTexGenBlock,src->mpTexGenBlock);
  (*(code *)this->mpTevBlock->vtbl->reset)(this->mpTevBlock,src->mpTevBlock);
  (**(code **)(*(int *)this->mpIndBlock + 8))(this->mpIndBlock,src->mpIndBlock);
  iVar1 = (**(code **)(this->mpPEBlock->vtbl + 8))(this->mpPEBlock,src->mpPEBlock);
  return iVar1;
}


/* __thiscall J3DMaterial::reset(void) */

void __thiscall J3DMaterial::reset(J3DMaterial *this)

{
  if ((~this->field_0x20 & 0x80000000) == 0) {
    this->field_0x20 = this->field_0x20 & 0x7fffffff;
    this->mMaterialMode = *(uint *)(this->field_0x38 + 0x10);
    this->field_0x18 = *(undefined **)(this->field_0x38 + 0x18);
    this->mpMaterialAnm = (J3DMaterialAnm *)0x0;
    copy(this,(J3DMaterial *)this->field_0x38);
  }
  return;
}


/* __thiscall J3DMaterial::change(void) */

void __thiscall J3DMaterial::change(J3DMaterial *this)

{
  if ((this->field_0x20 & 0xc0000000) != 0) {
    return;
  }
  this->field_0x20 = this->field_0x20 | 0x80000000;
  this->mpMaterialAnm = (J3DMaterialAnm *)0x0;
  return;
}


/* __thiscall J3DMaterial::newSharedDisplayList(unsigned long) */

int __thiscall J3DMaterial::newSharedDisplayList(J3DMaterial *this,ulong param_1)

{
  J3DDisplayListObj *pJVar1;
  int iVar2;
  
  if (this->mpDLObj == (J3DDisplayListObj *)0x0) {
    pJVar1 = (J3DDisplayListObj *)JKernel::operator_new(0x10);
    if (pJVar1 != (J3DDisplayListObj *)0x0) {
      pJVar1->mpData[0] = (void *)0x0;
      pJVar1->mpData[1] = (void *)0x0;
      pJVar1->mSize = 0;
      pJVar1->mCapacity = 0;
    }
    this->mpDLObj = pJVar1;
    if (this->mpDLObj == (J3DDisplayListObj *)0x0) {
      return 4;
    }
    iVar2 = J3DDisplayListObj::newDisplayList(this->mpDLObj,param_1);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  return 0;
}


/* __thiscall J3DMaterial::newSingleSharedDisplayList(unsigned long) */

int __thiscall J3DMaterial::newSingleSharedDisplayList(J3DMaterial *this,ulong param_1)

{
  J3DDisplayListObj *pJVar1;
  int iVar2;
  
  if (this->mpDLObj == (J3DDisplayListObj *)0x0) {
    pJVar1 = (J3DDisplayListObj *)JKernel::operator_new(0x10);
    if (pJVar1 != (J3DDisplayListObj *)0x0) {
      pJVar1->mpData[0] = (void *)0x0;
      pJVar1->mpData[1] = (void *)0x0;
      pJVar1->mSize = 0;
      pJVar1->mCapacity = 0;
    }
    this->mpDLObj = pJVar1;
    if (this->mpDLObj == (J3DDisplayListObj *)0x0) {
      return 4;
    }
    iVar2 = J3DDisplayListObj::newSingleDisplayList(this->mpDLObj,param_1);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  return 0;
}


/* __thiscall J3DPatchedMaterial::initialize(void) */

void __thiscall J3DPatchedMaterial::initialize(J3DPatchedMaterial *this)

{
  J3DMaterial::initialize((J3DMaterial *)this);
  return;
}


/* __thiscall J3DPatchedMaterial::makeDisplayList(void) */

void __thiscall J3DPatchedMaterial::makeDisplayList(J3DPatchedMaterial *this)

{
  return;
}


/* __thiscall J3DPatchedMaterial::makeSharedDisplayList(void) */

void __thiscall J3DPatchedMaterial::makeSharedDisplayList(J3DPatchedMaterial *this)

{
  return;
}


/* __thiscall J3DPatchedMaterial::load(void) */

void __thiscall J3DPatchedMaterial::load(J3DPatchedMaterial *this)

{
  J3DGraphBase::j3dSys.mCurMaterialMode = *(uint *)(this + 0x10);
  if ((J3DGraphBase::j3dSys.mCurFlags & 2) == 0) {
    J3DDisplayListObj::callDL(((J3DGraphBase::j3dSys.mpCurMatPacket)->parent).mpDLObj);
  }
  return;
}


/* __thiscall J3DPatchedMaterial::loadSharedDL(void) */

void __thiscall J3DPatchedMaterial::loadSharedDL(J3DPatchedMaterial *this)

{
  J3DGraphBase::j3dSys.mCurMaterialMode = *(uint *)(this + 0x10);
  if ((J3DGraphBase::j3dSys.mCurFlags & 2) == 0) {
    J3DDisplayListObj::callDL(*(J3DDisplayListObj **)(this + 0x48));
  }
  return;
}


/* __thiscall J3DPatchedMaterial::calc(float const *[][][][]) */

void __thiscall J3DPatchedMaterial::calc(J3DPatchedMaterial *this,float *param_1)

{
  (**(code **)(**(int **)(this + 0x28) + 0xc))();
  J3DMaterial::calcCurrentMtx((J3DMaterial *)this);
  J3DMaterial::setCurrentMtx((J3DMaterial *)this);
  return;
}


/* __thiscall J3DPatchedMaterial::reset(void) */

void __thiscall J3DPatchedMaterial::reset(J3DPatchedMaterial *this)

{
  return;
}


/* __thiscall J3DPatchedMaterial::change(void) */

void __thiscall J3DPatchedMaterial::change(J3DPatchedMaterial *this)

{
  return;
}


/* __thiscall J3DLockedMaterial::initialize(void) */

void __thiscall J3DLockedMaterial::initialize(J3DLockedMaterial *this)

{
  J3DMaterial::initialize((J3DMaterial *)this);
  return;
}


/* __thiscall J3DLockedMaterial::makeDisplayList(void) */

void __thiscall J3DLockedMaterial::makeDisplayList(J3DLockedMaterial *this)

{
  return;
}


/* __thiscall J3DLockedMaterial::makeSharedDisplayList(void) */

void __thiscall J3DLockedMaterial::makeSharedDisplayList(J3DLockedMaterial *this)

{
  return;
}


/* __thiscall J3DLockedMaterial::load(void) */

void __thiscall J3DLockedMaterial::load(J3DLockedMaterial *this)

{
  J3DGraphBase::j3dSys.mCurMaterialMode = *(uint *)(this + 0x10);
  if ((J3DGraphBase::j3dSys.mCurFlags & 2) == 0) {
    J3DDisplayListObj::callDL(((J3DGraphBase::j3dSys.mpCurMatPacket)->parent).mpDLObj);
  }
  return;
}


/* __thiscall J3DLockedMaterial::loadSharedDL(void) */

void __thiscall J3DLockedMaterial::loadSharedDL(J3DLockedMaterial *this)

{
  J3DGraphBase::j3dSys.mCurMaterialMode = *(uint *)(this + 0x10);
  if ((J3DGraphBase::j3dSys.mCurFlags & 2) == 0) {
    J3DDisplayListObj::callDL(*(J3DDisplayListObj **)(this + 0x48));
  }
  return;
}


/* __thiscall J3DLockedMaterial::patch(void) */

void __thiscall J3DLockedMaterial::patch(J3DLockedMaterial *this)

{
  return;
}


/* __thiscall J3DLockedMaterial::diff(unsigned long) */

void __thiscall J3DLockedMaterial::diff(J3DLockedMaterial *this,ulong param_1)

{
  return;
}


/* __thiscall J3DLockedMaterial::calc(float const *[][][][]) */

void __thiscall J3DLockedMaterial::calc(J3DLockedMaterial *this,float *param_1)

{
  return;
}


/* __thiscall J3DLockedMaterial::reset(void) */

void __thiscall J3DLockedMaterial::reset(J3DLockedMaterial *this)

{
  return;
}


/* __thiscall J3DLockedMaterial::change(void) */

void __thiscall J3DLockedMaterial::change(J3DLockedMaterial *this)

{
  return;
}


/* __thiscall J3DColorBlockLightOff::~J3DColorBlockLightOff(void) */

void __thiscall J3DColorBlockLightOff::_J3DColorBlockLightOff(J3DColorBlockLightOff *this)

{
  short in_r4;
  
  if (this != (J3DColorBlockLightOff *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DColorBlockLightOff *)0x0) {
      *(undefined ***)this = &J3DColorBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DColorBlock::~J3DColorBlock(void) */

void __thiscall J3DColorBlock::_J3DColorBlock(J3DColorBlock *this)

{
  short in_r4;
  
  if ((this != (J3DColorBlock *)0x0) && (this->vtbl = (J3DColorBlock__vtbl *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall J3DTexGenBlockPatched::~J3DTexGenBlockPatched(void) */

void __thiscall J3DTexGenBlockPatched::_J3DTexGenBlockPatched(J3DTexGenBlockPatched *this)

{
  short in_r4;
  
  if (this != (J3DTexGenBlockPatched *)0x0) {
    this->vtbl = (J3DTexGenBlock__vtbl *)&__vt;
    if (this != (J3DTexGenBlockPatched *)0x0) {
      this->vtbl = (J3DTexGenBlock__vtbl *)&J3DTexGenBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DTexGenBlock::~J3DTexGenBlock(void) */

void __thiscall J3DTexGenBlock::_J3DTexGenBlock(J3DTexGenBlock *this)

{
  short in_r4;
  
  if ((this != (J3DTexGenBlock *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall J3DTevBlock::~J3DTevBlock(void) */

void __thiscall J3DTevBlock::_J3DTevBlock(J3DTevBlock *this)

{
  short in_r4;
  
  if ((this != (J3DTevBlock *)0x0) && (this->vtbl = (J3DTevBlock__vtbl *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall J3DIndBlock::~J3DIndBlock(void) */

void __thiscall J3DIndBlock::_J3DIndBlock(J3DIndBlock *this)

{
  short in_r4;
  
  if ((this != (J3DIndBlock *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall J3DPEBlock::~J3DPEBlock(void) */

void __thiscall J3DPEBlock::_J3DPEBlock(J3DPEBlock *this)

{
  short in_r4;
  
  if ((this != (J3DPEBlock *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall J3DTexGenBlock::countDLSize(void) */

undefined4 __thiscall J3DTexGenBlock::countDLSize(J3DTexGenBlock *this)

{
  return 0;
}


/* __thiscall J3DColorBlock::countDLSize(void) */

undefined4 __thiscall J3DColorBlock::countDLSize(J3DColorBlock *this)

{
  return 0;
}


/* __thiscall J3DTevBlock::countDLSize(void) */

undefined4 __thiscall J3DTevBlock::countDLSize(J3DTevBlock *this)

{
  return 0;
}


/* __thiscall J3DIndBlock::countDLSize(void) */

undefined4 __thiscall J3DIndBlock::countDLSize(J3DIndBlock *this)

{
  return 0;
}


/* __thiscall J3DPEBlock::countDLSize(void) */

undefined4 __thiscall J3DPEBlock::countDLSize(J3DPEBlock *this)

{
  return 0;
}


/* __thiscall J3DColorBlock::load(void) */

void __thiscall J3DColorBlock::load(J3DColorBlock *this)

{
  return;
}


/* __thiscall J3DColorBlock::getCullMode(void) const */

undefined4 __thiscall J3DColorBlock::getCullMode(J3DColorBlock *this)

{
  return 2;
}


/* __thiscall J3DTevBlock::load(void) */

void __thiscall J3DTevBlock::load(J3DTevBlock *this)

{
  return;
}


/* __thiscall J3DTexGenBlock::getNBTScale(void) */

undefined4 __thiscall J3DTexGenBlock::getNBTScale(J3DTexGenBlock *this)

{
  return 0;
}


/* __thiscall J3DColorBlock::patch(void) */

void __thiscall J3DColorBlock::patch(J3DColorBlock *this)

{
  return;
}


/* __thiscall J3DColorBlock::diff(unsigned long) */

void __thiscall J3DColorBlock::diff(J3DColorBlock *this,ulong param_1)

{
  return;
}


/* __thiscall J3DPEBlock::diff(unsigned long) */

void __thiscall J3DPEBlock::diff(J3DPEBlock *this,ulong param_1)

{
  return;
}


/* __thiscall J3DPEBlock::reset(J3DPEBlock *) */

void __thiscall J3DPEBlock::reset(J3DPEBlock *this,J3DPEBlock *param_1)

{
  return;
}


/* __thiscall J3DIndBlock::reset(J3DIndBlock *) */

void __thiscall J3DIndBlock::reset(J3DIndBlock *this,J3DIndBlock *param_1)

{
  return;
}


/* __thiscall J3DTevBlock::reset(J3DTevBlock *) */

void __thiscall J3DTevBlock::reset(J3DTevBlock *this,J3DTevBlock *param_1)

{
  return;
}


/* __thiscall J3DTexGenBlock::reset(J3DTexGenBlock *) */

void __thiscall J3DTexGenBlock::reset(J3DTexGenBlock *this,J3DTexGenBlock *param_1)

{
  return;
}


/* __thiscall J3DColorBlock::reset(J3DColorBlock *) */

void __thiscall J3DColorBlock::reset(J3DColorBlock *this,J3DColorBlock *param_1)

{
  return;
}


/* __thiscall J3DPEBlock::diffFog(void) */

void __thiscall J3DPEBlock::diffFog(J3DPEBlock *this)

{
  return;
}


/* __thiscall J3DPEBlock::diffBlend(void) */

void __thiscall J3DPEBlock::diffBlend(J3DPEBlock *this)

{
  return;
}


/* __thiscall J3DPEBlock::setFog(J3DFog *) */

void __thiscall J3DPEBlock::setFog(J3DPEBlock *this,J3DFog *param_1)

{
  return;
}


/* __thiscall J3DPEBlock::setAlphaComp(J3DAlphaComp const *) */

void __thiscall J3DPEBlock::setAlphaComp(J3DPEBlock *this,J3DAlphaComp *param_1)

{
  return;
}


/* __thiscall J3DPEBlock::setBlend(J3DBlend const *) */

void __thiscall J3DPEBlock::setBlend(J3DPEBlock *this,J3DBlend *param_1)

{
  return;
}


/* __thiscall J3DPEBlock::setZMode(J3DZMode const *) */

void __thiscall J3DPEBlock::setZMode(J3DPEBlock *this,J3DZMode *param_1)

{
  return;
}


/* __thiscall J3DPEBlock::setZCompLoc(unsigned char const *) */

void __thiscall J3DPEBlock::setZCompLoc(J3DPEBlock *this,uchar *param_1)

{
  return;
}


/* __thiscall J3DPEBlock::setDither(unsigned char) */

void __thiscall J3DPEBlock::setDither(J3DPEBlock *this,uchar param_1)

{
  return;
}


/* __thiscall J3DPEBlock::setDither(unsigned char const *) */

void __thiscall J3DPEBlock::setDither(J3DPEBlock *this,uchar *param_1)

{
  return;
}


/* __thiscall J3DPEBlock::getDither(void) const */

undefined4 __thiscall J3DPEBlock::getDither(J3DPEBlock *this)

{
  return 0;
}


/* __thiscall J3DPEBlock::getFogOffset(void) const */

undefined4 __thiscall J3DPEBlock::getFogOffset(J3DPEBlock *this)

{
  return 0;
}


/* __thiscall J3DPEBlock::setFogOffset(unsigned long) */

void __thiscall J3DPEBlock::setFogOffset(J3DPEBlock *this,ulong param_1)

{
  return;
}


/* __thiscall J3DIndBlockNull::diff(unsigned long) */

void __thiscall J3DIndBlockNull::diff(J3DIndBlockNull *this,ulong param_1)

{
  return;
}


/* __thiscall J3DIndBlockNull::load(void) */

void __thiscall J3DIndBlockNull::load(J3DIndBlockNull *this)

{
  return;
}


/* __thiscall J3DIndBlockNull::reset(J3DIndBlock *) */

void __thiscall J3DIndBlockNull::reset(J3DIndBlockNull *this,J3DIndBlock *param_1)

{
  return;
}


/* __thiscall J3DIndBlockNull::getType(void) */

undefined4 __thiscall J3DIndBlockNull::getType(J3DIndBlockNull *this)

{
  return 0x49424c4e;
}


/* __thiscall J3DIndBlockNull::~J3DIndBlockNull(void) */

void __thiscall J3DIndBlockNull::_J3DIndBlockNull(J3DIndBlockNull *this)

{
  short in_r4;
  
  if (this != (J3DIndBlockNull *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DIndBlockNull *)0x0) {
      *(undefined1 **)this = &J3DIndBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DIndBlock::setIndTexOrder(unsigned long,
                                          J3DIndTexOrder const *) */

void __thiscall J3DIndBlock::setIndTexOrder(J3DIndBlock *this,ulong param_1,J3DIndTexOrder *param_2)

{
  return;
}


/* __thiscall J3DIndBlock::setIndTexOrder(unsigned long,
                                          J3DIndTexOrder) */

void __thiscall J3DIndBlock::setIndTexOrder(J3DIndBlock *this,ulong param_1,J3DIndTexOrder param_2)

{
  return;
}


/* __thiscall J3DIndBlock::setIndTexMtx(unsigned long,
                                        J3DIndTexMtx const *) */

void __thiscall J3DIndBlock::setIndTexMtx(J3DIndBlock *this,ulong param_1,J3DIndTexMtx *param_2)

{
  return;
}


/* __thiscall J3DIndBlock::setIndTexCoordScale(unsigned long,
                                               J3DIndTexCoordScale const *) */

void __thiscall
J3DIndBlock::setIndTexCoordScale(J3DIndBlock *this,ulong param_1,J3DIndTexCoordScale *param_2)

{
  return;
}


/* __thiscall J3DTexGenBlock::setTexGenNum(unsigned long const *) */

void __thiscall J3DTexGenBlock::setTexGenNum(J3DTexGenBlock *this,ulong *param_1)

{
  return;
}


/* __thiscall J3DTexGenBlock::setNBTScale(J3DNBTScale) */

void __thiscall J3DTexGenBlock::setNBTScale(J3DTexGenBlock *this,J3DNBTScale param_1)

{
  return;
}


/* __thiscall J3DTexGenBlock::setNBTScale(J3DNBTScale const *) */

void __thiscall J3DTexGenBlock::setNBTScale(J3DTexGenBlock *this,J3DNBTScale *param_1)

{
  return;
}


/* __thiscall J3DTexGenBlock::getTexMtxOffset(void) const */

undefined4 __thiscall J3DTexGenBlock::getTexMtxOffset(J3DTexGenBlock *this)

{
  return 0;
}


/* __thiscall J3DTexGenBlock::setTexMtxOffset(unsigned long) */

void __thiscall J3DTexGenBlock::setTexMtxOffset(J3DTexGenBlock *this,ulong param_1)

{
  return;
}


/* __thiscall J3DColorBlock::patchMatColor(void) */

void __thiscall J3DColorBlock::patchMatColor(J3DColorBlock *this)

{
  return;
}


/* __thiscall J3DColorBlock::diffMatColor(void) */

void __thiscall J3DColorBlock::diffMatColor(J3DColorBlock *this)

{
  return;
}


/* __thiscall J3DColorBlock::diffLight(void) */

void __thiscall J3DColorBlock::diffLight(J3DColorBlock *this)

{
  return;
}


/* __thiscall J3DColorBlock::setMatColor(unsigned long,
                                         J3DGXColor const *) */

void __thiscall J3DColorBlock::setMatColor(J3DColorBlock *this,ulong param_1,J3DGXColor *param_2)

{
  return;
}


/* __thiscall J3DColorBlock::setAmbColor(unsigned long,
                                         J3DGXColor const *) */

void __thiscall J3DColorBlock::setAmbColor(J3DColorBlock *this,ulong param_1,J3DGXColor *param_2)

{
  return;
}


/* __thiscall J3DColorBlock::setColorChanNum(unsigned char const *) */

void __thiscall J3DColorBlock::setColorChanNum(J3DColorBlock *this,uchar *param_1)

{
  return;
}


/* __thiscall J3DColorBlock::setColorChan(unsigned long,
                                          J3DColorChan const *) */

void __thiscall J3DColorBlock::setColorChan(J3DColorBlock *this,ulong param_1,J3DColorChan *param_2)

{
  return;
}


/* __thiscall J3DColorBlock::getLight(unsigned long) */

undefined4 __thiscall J3DColorBlock::getLight(J3DColorBlock *this,ulong param_1)

{
  return 0;
}


/* __thiscall J3DColorBlock::setCullMode(unsigned char const *) */

void __thiscall J3DColorBlock::setCullMode(J3DColorBlock *this,uchar *param_1)

{
  return;
}


/* __thiscall J3DColorBlock::getMatColorOffset(void) const */

undefined4 __thiscall J3DColorBlock::getMatColorOffset(J3DColorBlock *this)

{
  return 0;
}


/* __thiscall J3DColorBlock::getColorChanOffset(void) const */

undefined4 __thiscall J3DColorBlock::getColorChanOffset(J3DColorBlock *this)

{
  return 0;
}


/* __thiscall J3DColorBlock::setMatColorOffset(unsigned long) */

void __thiscall J3DColorBlock::setMatColorOffset(J3DColorBlock *this,ulong param_1)

{
  return;
}


/* __thiscall J3DColorBlock::setColorChanOffset(unsigned long) */

void __thiscall J3DColorBlock::setColorChanOffset(J3DColorBlock *this,ulong param_1)

{
  return;
}

