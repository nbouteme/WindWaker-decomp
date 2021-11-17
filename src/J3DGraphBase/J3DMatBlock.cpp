#include <J3DGraphBase/J3DMatBlock.h>
#include <gd/GDBase.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J3DGraphBase/J3DTevs.h>
#include <os/OSCache.h>
#include <J3DGraphBase/J3DMatBlock.h>
#include <J3DGraphBase/J3DGD.h>
#include <m_Do_printf.h>
#include <mtx/mtx.h>
#include <JKernel/JKRHeap.h>
#include <m_Do_ext.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <J3DColorBlockAmbientOn.h>
#include <J3DTexGenBlockPatched.h>
#include <J3DPEBlockFogOff.h>
#include <J3DTevBlock.h>
#include <J3DPEBlockFull.h>
#include <J3DColorBlockLightOff.h>
#include <J3DTevBlock4.h>
#include <J3DTevBlock16.h>
#include <J3DPEBlockOpa.h>
#include <J3DPEBlockXlu.h>
#include <J3DTexGenBlockBasic.h>
#include <J3DColorBlockLightOn.h>
#include <J3DIndBlockFull.h>
#include <J3DTexMtx.h>
#include <J3DTevBlock1.h>
#include <J3DTevBlock2.h>
#include <J3DPEBlockTexEdge.h>
#include <J3DTexGenBlock4.h>
#include <J3DTevBlockNull.h>
#include <J3DTevBlockPatched.h>


namespace J3DGraphBase {
undefined4 SizeOfJ3DColorBlockLightOffLoad;
undefined4 SizeOfJ3DColorBlockAmbientOnLoad;
}

/* __thiscall J3DColorBlockLightOff::initialize(void) */

void __thiscall J3DColorBlockLightOff::initialize(J3DColorBlockLightOff *this)

{
  J3DColorBlockLightOff JVar1;
  J3DColorBlockLightOff JVar2;
  J3DColorBlockLightOff JVar3;
  J3DColorBlockLightOff JVar4;
  int iVar5;
  J3DColorBlockLightOff *pJVar6;
  int iVar7;
  
  iVar5 = 0;
  this[0xc] = (J3DColorBlockLightOff)0x0;
  JVar4 = J3DGraphBase::j3dDefaultColInfo._3_1_;
  JVar3 = J3DGraphBase::j3dDefaultColInfo._2_1_;
  JVar2 = J3DGraphBase::j3dDefaultColInfo._1_1_;
  JVar1 = J3DGraphBase::j3dDefaultColInfo._0_1_;
  iVar7 = 2;
  do {
    pJVar6 = this + iVar5;
    pJVar6[4] = JVar1;
    pJVar6[5] = JVar2;
    pJVar6[6] = JVar3;
    pJVar6[7] = JVar4;
    iVar5 = iVar5 + 4;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  return;
}


/* __thiscall J3DColorBlockAmbientOn::initialize(void) */

void __thiscall J3DColorBlockAmbientOn::initialize(J3DColorBlockAmbientOn *this)

{
  J3DColorBlockAmbientOn JVar1;
  J3DColorBlockAmbientOn JVar2;
  J3DColorBlockAmbientOn JVar3;
  J3DColorBlockAmbientOn JVar4;
  J3DColorBlockAmbientOn JVar5;
  J3DColorBlockAmbientOn JVar6;
  J3DColorBlockAmbientOn JVar7;
  J3DColorBlockAmbientOn JVar8;
  int iVar9;
  J3DColorBlockAmbientOn *pJVar10;
  int iVar11;
  
  iVar9 = 0;
  this[0xc] = (J3DColorBlockAmbientOn)0x0;
  JVar4 = J3DGraphBase::j3dDefaultColInfo._3_1_;
  JVar3 = J3DGraphBase::j3dDefaultColInfo._2_1_;
  JVar2 = J3DGraphBase::j3dDefaultColInfo._1_1_;
  JVar1 = J3DGraphBase::j3dDefaultColInfo._0_1_;
  iVar11 = 2;
  do {
    pJVar10 = this + iVar9;
    pJVar10[4] = JVar1;
    pJVar10[5] = JVar2;
    pJVar10[6] = JVar3;
    pJVar10[7] = JVar4;
    JVar8 = UNK_803fc937;
    JVar7 = UNK_803fc936;
    JVar6 = UNK_803fc935;
    JVar5 = J3DGraphBase::j3dDefaultAmbInfo;
    iVar9 = iVar9 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  iVar9 = 0;
  iVar11 = 2;
  do {
    pJVar10 = this + iVar9;
    pJVar10[0x20] = JVar5;
    pJVar10[0x21] = JVar6;
    pJVar10[0x22] = JVar7;
    pJVar10[0x23] = JVar8;
    iVar9 = iVar9 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  return;
}


/* __thiscall J3DColorBlockLightOn::initialize(void) */

void __thiscall J3DColorBlockLightOn::initialize(J3DColorBlockLightOn *this)

{
  undefined uVar1;
  undefined uVar2;
  undefined uVar3;
  undefined uVar4;
  undefined uVar5;
  undefined uVar6;
  undefined uVar7;
  undefined uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar9 = 0;
  *(undefined *)&this->field_0x14 = 0;
  uVar4 = (undefined)J3DGraphBase::j3dDefaultColInfo;
  uVar3 = J3DGraphBase::j3dDefaultColInfo._2_1_;
  uVar2 = J3DGraphBase::j3dDefaultColInfo._1_1_;
  uVar1 = J3DGraphBase::j3dDefaultColInfo._0_1_;
  iVar11 = 2;
  do {
    iVar10 = (int)this->mColors + iVar9 + -4;
    *(undefined *)(iVar10 + 4) = uVar1;
    *(undefined *)(iVar10 + 5) = uVar2;
    *(undefined *)(iVar10 + 6) = uVar3;
    *(undefined *)(iVar10 + 7) = uVar4;
    uVar8 = UNK_803fc937;
    uVar7 = UNK_803fc936;
    uVar6 = UNK_803fc935;
    uVar5 = J3DGraphBase::j3dDefaultAmbInfo;
    iVar9 = iVar9 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  iVar9 = 0;
  iVar11 = 2;
  do {
    iVar10 = (int)this->mColors + iVar9 + -4;
    *(undefined *)(iVar10 + 0xc) = uVar5;
    *(undefined *)(iVar10 + 0xd) = uVar6;
    *(undefined *)(iVar10 + 0xe) = uVar7;
    *(undefined *)(iVar10 + 0xf) = uVar8;
    iVar9 = iVar9 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  iVar9 = 0;
  iVar11 = 8;
  do {
    *(undefined4 *)((int)this->mpLights + iVar9) = 0;
    iVar9 = iVar9 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  this->mMatColorOffs = 0;
  this->mColorChanOffs = 0;
  return;
}


/* __thiscall J3DTexGenBlockPatched::initialize(void) */

void __thiscall J3DTexGenBlockPatched::initialize(J3DTexGenBlockPatched *this)

{
  int iVar1;
  int iVar2;
  
  this->field_0x4 = (undefined *)0x0;
  iVar1 = 0;
  iVar2 = 8;
  do {
    *(undefined4 *)((int)&this[5].vtbl + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this[9].vtbl = (J3DTexGenBlock__vtbl *)0x0;
  return;
}


/* __thiscall J3DTexGenBlock4::initialize(void) */

void __thiscall J3DTexGenBlock4::initialize(J3DTexGenBlock4 *this)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(this + 4) = 0;
  iVar1 = 0;
  iVar2 = 4;
  do {
    *(undefined4 *)(this + iVar1 + 0x28) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(this + 0x48) = 0;
  return;
}


/* __thiscall J3DTexGenBlockBasic::initialize(void) */

void __thiscall J3DTexGenBlockBasic::initialize(J3DTexGenBlockBasic *this)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(this + 4) = 0;
  iVar1 = 0;
  iVar2 = 8;
  do {
    *(undefined4 *)(this + iVar1 + 0x28) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(this + 0x48) = 0;
  return;
}


/* __thiscall J3DTevBlockNull::initialize(void) */

void __thiscall J3DTevBlockNull::initialize(J3DTevBlockNull *this)

{
  *(undefined4 *)(this + 4) = 0;
  return;
}


/* __thiscall J3DTevBlockPatched::initialize(void) */

void __thiscall J3DTevBlockPatched::initialize(J3DTevBlockPatched *this)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined uVar5;
  undefined uVar6;
  undefined uVar7;
  undefined uVar8;
  int iVar9;
  char cVar10;
  int iVar11;
  int iVar12;
  
  iVar9 = 0;
  iVar12 = 8;
  do {
    *(undefined2 *)((int)this->mTexNo + iVar9) = 0xffff;
    iVar9 = iVar9 + 2;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  iVar9 = 0;
  cVar10 = '\0';
  iVar12 = 8;
  do {
    iVar11 = (int)this->mTexNo + iVar9 + -8;
    *(char *)(iVar11 + 0x38) = cVar10 + -0x40;
    *(char *)(iVar11 + 0x3c) = cVar10 + -0x3f;
    uVar4 = DAT_803fc948._2_2_;
    uVar3 = DAT_803fc948._0_2_;
    uVar2 = J3DGraphBase::j3dDefaultTevColor._2_2_;
    uVar1 = J3DGraphBase::j3dDefaultTevColor._0_2_;
    iVar9 = iVar9 + 8;
    cVar10 = cVar10 + '\x02';
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  iVar9 = 0;
  iVar12 = 3;
  do {
    iVar11 = (int)this->mTexNo + iVar9 + -8;
    *(undefined2 *)(iVar11 + 0x98) = uVar1;
    *(undefined2 *)(iVar11 + 0x9a) = uVar2;
    *(undefined2 *)(iVar11 + 0x9c) = uVar3;
    *(undefined2 *)(iVar11 + 0x9e) = uVar4;
    uVar8 = (undefined)J3DGraphBase::j3dDefaultTevKColor;
    uVar7 = J3DGraphBase::j3dDefaultTevKColor._2_1_;
    uVar6 = J3DGraphBase::j3dDefaultTevKColor._1_1_;
    uVar5 = J3DGraphBase::j3dDefaultTevKColor._0_1_;
    iVar9 = iVar9 + 8;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  iVar9 = 0;
  iVar12 = 4;
  do {
    iVar11 = (int)this->mTexNo + iVar9 + -8;
    *(undefined *)(iVar11 + 0xb8) = uVar5;
    *(undefined *)(iVar11 + 0xb9) = uVar6;
    *(undefined *)(iVar11 + 0xba) = uVar7;
    *(undefined *)(iVar11 + 0xbb) = uVar8;
    iVar9 = iVar9 + 4;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  iVar9 = 0;
  iVar12 = 8;
  do {
    this->mKColorSel[iVar9] = 0xc;
    iVar9 = iVar9 + 1;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  this->mTevStageNum = 1;
  *(undefined4 *)&this->field_0x4 = 0;
  this->mTevRegOffs = 0;
  return;
}


/* __thiscall J3DTevBlock1::initialize(void) */

void __thiscall J3DTevBlock1::initialize(J3DTevBlock1 *this)

{
  *(undefined2 *)(this + 8) = 0xffff;
  this[0xe] = (J3DTevBlock1)0xc0;
  this[0x12] = (J3DTevBlock1)0xc1;
  *(undefined4 *)(this + 4) = 0;
  return;
}


/* __thiscall J3DTevBlock2::initialize(void) */

void __thiscall J3DTevBlock2::initialize(J3DTevBlock2 *this)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  J3DTevBlock2 JVar5;
  J3DTevBlock2 JVar6;
  J3DTevBlock2 JVar7;
  J3DTevBlock2 JVar8;
  int iVar9;
  J3DTevBlock2 *pJVar10;
  int iVar11;
  
  *(undefined2 *)(this + 8) = 0xffff;
  *(undefined2 *)(this + 10) = 0xffff;
  this[0x34] = (J3DTevBlock2)0x1;
  this[0x35] = (J3DTevBlock2)0xc0;
  this[0x39] = (J3DTevBlock2)0xc1;
  this[0x3d] = (J3DTevBlock2)0xc2;
  this[0x41] = (J3DTevBlock2)0xc3;
  this[0x55] = (J3DTevBlock2)0xc;
  this[0x56] = (J3DTevBlock2)0xc;
  this[0x57] = (J3DTevBlock2)0x1c;
  this[0x58] = (J3DTevBlock2)0x1c;
  uVar4 = DAT_803fc948._2_2_;
  uVar3 = DAT_803fc948._0_2_;
  uVar2 = J3DGraphBase::j3dDefaultTevColor._2_2_;
  uVar1 = J3DGraphBase::j3dDefaultTevColor._0_2_;
  iVar9 = 0;
  iVar11 = 3;
  do {
    pJVar10 = this + iVar9;
    *(undefined2 *)(pJVar10 + 0x14) = uVar1;
    *(undefined2 *)(pJVar10 + 0x16) = uVar2;
    *(undefined2 *)(pJVar10 + 0x18) = uVar3;
    *(undefined2 *)(pJVar10 + 0x1a) = uVar4;
    JVar8 = J3DGraphBase::j3dDefaultTevKColor._3_1_;
    JVar7 = J3DGraphBase::j3dDefaultTevKColor._2_1_;
    JVar6 = J3DGraphBase::j3dDefaultTevKColor._1_1_;
    JVar5 = J3DGraphBase::j3dDefaultTevKColor._0_1_;
    iVar9 = iVar9 + 8;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  iVar9 = 0;
  iVar11 = 4;
  do {
    pJVar10 = this + iVar9;
    pJVar10[0x45] = JVar5;
    pJVar10[0x46] = JVar6;
    pJVar10[0x47] = JVar7;
    pJVar10[0x48] = JVar8;
    iVar9 = iVar9 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  return;
}


/* __thiscall J3DTevBlock4::initialize(void) */

void __thiscall J3DTevBlock4::initialize(J3DTevBlock4 *this)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  J3DTevBlock4 JVar5;
  J3DTevBlock4 JVar6;
  J3DTevBlock4 JVar7;
  J3DTevBlock4 JVar8;
  int iVar9;
  J3DTevBlock4 *pJVar10;
  int iVar11;
  
  *(undefined2 *)(this + 8) = 0xffff;
  *(undefined2 *)(this + 10) = 0xffff;
  *(undefined2 *)(this + 0xc) = 0xffff;
  *(undefined2 *)(this + 0xe) = 0xffff;
  this[0x20] = (J3DTevBlock4)0x1;
  this[0x21] = (J3DTevBlock4)0xc0;
  this[0x25] = (J3DTevBlock4)0xc1;
  this[0x29] = (J3DTevBlock4)0xc2;
  this[0x2d] = (J3DTevBlock4)0xc3;
  this[0x31] = (J3DTevBlock4)0xc4;
  this[0x35] = (J3DTevBlock4)0xc5;
  this[0x39] = (J3DTevBlock4)0xc6;
  this[0x3d] = (J3DTevBlock4)0xc7;
  this[0x72] = (J3DTevBlock4)0xc;
  this[0x73] = (J3DTevBlock4)0xc;
  this[0x74] = (J3DTevBlock4)0xc;
  this[0x75] = (J3DTevBlock4)0xc;
  this[0x76] = (J3DTevBlock4)0x1c;
  this[0x77] = (J3DTevBlock4)0x1c;
  this[0x78] = (J3DTevBlock4)0x1c;
  this[0x79] = (J3DTevBlock4)0x1c;
  uVar4 = DAT_803fc948._2_2_;
  uVar3 = DAT_803fc948._0_2_;
  uVar2 = J3DGraphBase::j3dDefaultTevColor._2_2_;
  uVar1 = J3DGraphBase::j3dDefaultTevColor._0_2_;
  iVar9 = 0;
  iVar11 = 3;
  do {
    pJVar10 = this + iVar9;
    *(undefined2 *)(pJVar10 + 0x42) = uVar1;
    *(undefined2 *)(pJVar10 + 0x44) = uVar2;
    *(undefined2 *)(pJVar10 + 0x46) = uVar3;
    *(undefined2 *)(pJVar10 + 0x48) = uVar4;
    JVar8 = J3DGraphBase::j3dDefaultTevKColor._3_1_;
    JVar7 = J3DGraphBase::j3dDefaultTevKColor._2_1_;
    JVar6 = J3DGraphBase::j3dDefaultTevKColor._1_1_;
    JVar5 = J3DGraphBase::j3dDefaultTevKColor._0_1_;
    iVar9 = iVar9 + 8;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  iVar9 = 0;
  iVar11 = 4;
  do {
    pJVar10 = this + iVar9;
    pJVar10[0x62] = JVar5;
    pJVar10[99] = JVar6;
    pJVar10[100] = JVar7;
    pJVar10[0x65] = JVar8;
    iVar9 = iVar9 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x90) = 0;
  return;
}


/* __thiscall J3DTevBlock16::initialize(void) */

void __thiscall J3DTevBlock16::initialize(J3DTevBlock16 *this)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  J3DTevBlock16 JVar5;
  J3DTevBlock16 JVar6;
  J3DTevBlock16 JVar7;
  J3DTevBlock16 JVar8;
  int iVar9;
  char cVar10;
  J3DTevBlock16 *pJVar11;
  int iVar12;
  
  iVar9 = 0;
  iVar12 = 8;
  do {
    *(undefined2 *)(this + iVar9 + 8) = 0xffff;
    iVar9 = iVar9 + 2;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  this[0x58] = (J3DTevBlock16)0x1;
  uVar4 = DAT_803fc948._2_2_;
  uVar3 = DAT_803fc948._0_2_;
  uVar2 = J3DGraphBase::j3dDefaultTevColor._2_2_;
  uVar1 = J3DGraphBase::j3dDefaultTevColor._0_2_;
  iVar9 = 0;
  iVar12 = 3;
  do {
    pJVar11 = this + iVar9;
    *(undefined2 *)(pJVar11 + 0xda) = uVar1;
    *(undefined2 *)(pJVar11 + 0xdc) = uVar2;
    *(undefined2 *)(pJVar11 + 0xde) = uVar3;
    *(undefined2 *)(pJVar11 + 0xe0) = uVar4;
    JVar8 = J3DGraphBase::j3dDefaultTevKColor._3_1_;
    JVar7 = J3DGraphBase::j3dDefaultTevKColor._2_1_;
    JVar6 = J3DGraphBase::j3dDefaultTevKColor._1_1_;
    JVar5 = J3DGraphBase::j3dDefaultTevKColor._0_1_;
    iVar9 = iVar9 + 8;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  iVar9 = 0;
  iVar12 = 4;
  do {
    pJVar11 = this + iVar9;
    pJVar11[0xfa] = JVar5;
    pJVar11[0xfb] = JVar6;
    pJVar11[0xfc] = JVar7;
    pJVar11[0xfd] = JVar8;
    iVar9 = iVar9 + 4;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  iVar9 = 0;
  iVar12 = 0x10;
  do {
    this[iVar9 + 0x10a] = (J3DTevBlock16)0xc;
    iVar9 = iVar9 + 1;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  iVar9 = 0;
  iVar12 = 0x10;
  do {
    this[iVar9 + 0x11a] = (J3DTevBlock16)0x1c;
    iVar9 = iVar9 + 1;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  iVar9 = 0;
  cVar10 = '\0';
  iVar12 = 0x10;
  do {
    (this + iVar9)[0x59] = (J3DTevBlock16)(cVar10 + -0x40);
    (this + iVar9)[0x5d] = (J3DTevBlock16)(cVar10 + -0x3f);
    iVar9 = iVar9 + 8;
    cVar10 = cVar10 + '\x02';
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x170) = 0;
  return;
}


/* __thiscall J3DIndBlockFull::initialize(void) */

void __thiscall J3DIndBlockFull::initialize(J3DIndBlockFull *this)

{
  this[4] = (J3DIndBlockFull)0x0;
  return;
}


/* __thiscall J3DPEBlockFogOff::initialize(void) */

void __thiscall J3DPEBlockFogOff::initialize(J3DPEBlockFogOff *this)

{
  *(undefined2 *)(this + 4) = 0xffff;
  *(undefined2 *)(this + 0xc) = 0xffff;
  this[0xe] = (J3DPEBlockFogOff)0xff;
  this[0xf] = (J3DPEBlockFogOff)0x1;
  return;
}


/* __thiscall J3DPEBlockFull::initialize(void) */

void __thiscall J3DPEBlockFull::initialize(J3DPEBlockFull *this)

{
  this->mpFog = (J3DFog *)0x0;
  *(undefined2 *)&this->mAlphaComp = 0xffff;
  this->mZMode = -1;
  this->mZCompLoc = 0xff;
  this->mDither = 1;
  this[1].vtbl = (undefined *)0x0;
  return;
}


/* __thiscall J3DColorBlockLightOff::countDLSize(void) */

undefined4 __thiscall J3DColorBlockLightOff::countDLSize(J3DColorBlockLightOff *this)

{
  return 0x22;
}


/* __thiscall J3DColorBlockAmbientOn::countDLSize(void) */

undefined4 __thiscall J3DColorBlockAmbientOn::countDLSize(J3DColorBlockAmbientOn *this)

{
  return 0x2f;
}


/* __thiscall J3DColorBlockLightOn::countDLSize(void) */

undefined4 __thiscall J3DColorBlockLightOn::countDLSize(J3DColorBlockLightOn *this)

{
  return 0x26f;
}


/* __thiscall J3DTexGenBlockPatched::countDLSize(void) */

undefined4 __thiscall J3DTexGenBlockPatched::countDLSize(J3DTexGenBlockPatched *this)

{
  return 0x1a8;
}


/* __thiscall J3DTexGenBlock4::countDLSize(void) */

undefined4 __thiscall J3DTexGenBlock4::countDLSize(J3DTexGenBlock4 *this)

{
  return 0xfe;
}


/* __thiscall J3DTexGenBlockBasic::countDLSize(void) */

undefined4 __thiscall J3DTexGenBlockBasic::countDLSize(J3DTexGenBlockBasic *this)

{
  return 0x1f2;
}


/* __thiscall J3DTevBlockPatched::countDLSize(void) */

undefined4 __thiscall J3DTevBlockPatched::countDLSize(J3DTevBlockPatched *this)

{
  return 0x230;
}


/* __thiscall J3DTevBlock1::countDLSize(void) */

undefined4 __thiscall J3DTevBlock1::countDLSize(J3DTevBlock1 *this)

{
  return 0x69;
}


/* __thiscall J3DTevBlock2::countDLSize(void) */

undefined4 __thiscall J3DTevBlock2::countDLSize(J3DTevBlock2 *this)

{
  return 0x14f;
}


/* __thiscall J3DTevBlock4::countDLSize(void) */

undefined4 __thiscall J3DTevBlock4::countDLSize(J3DTevBlock4 *this)

{
  return 0x244;
}


/* __thiscall J3DTevBlock16::countDLSize(void) */

undefined4 __thiscall J3DTevBlock16::countDLSize(J3DTevBlock16 *this)

{
  return 1000;
}


/* __thiscall J3DIndBlockFull::countDLSize(void) */

undefined4 __thiscall J3DIndBlockFull::countDLSize(J3DIndBlockFull *this)

{
  return 0x8c;
}


/* __thiscall J3DPEBlockOpa::countDLSize(void) */

undefined4 __thiscall J3DPEBlockOpa::countDLSize(J3DPEBlockOpa *this)

{
  return 0x1e;
}


/* __thiscall J3DPEBlockTexEdge::countDLSize(void) */

undefined4 __thiscall J3DPEBlockTexEdge::countDLSize(J3DPEBlockTexEdge *this)

{
  return 0x1e;
}


/* __thiscall J3DPEBlockXlu::countDLSize(void) */

undefined4 __thiscall J3DPEBlockXlu::countDLSize(J3DPEBlockXlu *this)

{
  return 0x1e;
}


/* __thiscall J3DPEBlockFogOff::countDLSize(void) */

undefined4 __thiscall J3DPEBlockFogOff::countDLSize(J3DPEBlockFogOff *this)

{
  return 0x1e;
}


/* __thiscall J3DPEBlockFull::countDLSize(void) */

undefined4 __thiscall J3DPEBlockFull::countDLSize(J3DPEBlockFull *this)

{
  return 0x55;
}


/* __thiscall J3DColorBlockLightOff::load(void) */

void __thiscall J3DColorBlockLightOff::load(J3DColorBlockLightOff *this)

{
  ushort uVar1;
  uint uVar2;
  byte *pbVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if ((uint)gd::__GDCurrentDL[3] <
      (uint)(gd::__GDCurrentDL[2] + J3DGraphBase::SizeOfJ3DColorBlockLightOffLoad)) {
    gd::GDOverflowed();
  }
  *(int *)(this + 0x18) = gd::__GDCurrentDL[2] - *gd::__GDCurrentDL;
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = 0x10;
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = 0;
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = 1;
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = 0x10;
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = 0xc;
  uVar6 = *(undefined4 *)(this + 4);
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = (char)((uint)uVar6 >> 0x18);
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = (char)((uint)uVar6 >> 0x10);
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = (char)((uint)uVar6 >> 8);
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = (char)uVar6;
  uVar6 = *(undefined4 *)(this + 8);
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = (char)((uint)uVar6 >> 0x18);
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = (char)((uint)uVar6 >> 0x10);
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = (char)((uint)uVar6 >> 8);
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = (char)uVar6;
  *(int *)(this + 0x1c) = gd::__GDCurrentDL[2] - *gd::__GDCurrentDL;
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = 0x10;
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = 0;
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = 3;
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = 0x10;
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = 0xe;
  local_c = J3DGraphBase::_896;
  uVar1 = *(ushort *)(this + 0xe);
  uVar8 = (uint)*(byte *)((int)&local_c + (uVar1 >> 9 & 3));
  uVar7 = uVar1 >> 7 & 3;
  iVar5 = -uVar8 + 2;
  uVar2 = (iVar5 - ((uint)(iVar5 == 0) + -uVar8 + 1)) * 0x200 & 0x1fe00;
  if (uVar8 == 0) {
    uVar7 = 0;
  }
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = 0;
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = (char)(uVar2 >> 0x10);
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar8 != 0) * 0x400 >> 8) | (byte)(uVar2 >> 8) | (byte)((uVar7 << 7) >> 8)
  ;
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar7 << 7);
  local_10 = J3DGraphBase::_896;
  uVar1 = *(ushort *)(this + 0x12);
  uVar8 = (uint)*(byte *)((int)&local_10 + (uVar1 >> 9 & 3));
  uVar7 = uVar1 >> 7 & 3;
  iVar5 = -uVar8 + 2;
  uVar2 = (iVar5 - ((uint)(iVar5 == 0) + -uVar8 + 1)) * 0x200 & 0x1fe00;
  if (uVar8 == 0) {
    uVar7 = 0;
  }
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = 0;
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = (char)(uVar2 >> 0x10);
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar8 != 0) * 0x400 >> 8) | (byte)(uVar2 >> 8) | (byte)((uVar7 << 7) >> 8)
  ;
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar7 << 7);
  local_14 = J3DGraphBase::_896;
  uVar1 = *(ushort *)(this + 0x10);
  uVar8 = (uint)*(byte *)((int)&local_14 + (uVar1 >> 9 & 3));
  uVar7 = uVar1 >> 7 & 3;
  iVar5 = -uVar8 + 2;
  uVar2 = (iVar5 - ((uint)(iVar5 == 0) + -uVar8 + 1)) * 0x200 & 0x1fe00;
  if (uVar8 == 0) {
    uVar7 = 0;
  }
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = 0;
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = (char)(uVar2 >> 0x10);
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar8 != 0) * 0x400 >> 8) | (byte)(uVar2 >> 8) | (byte)((uVar7 << 7) >> 8)
  ;
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar7 << 7);
  local_18 = J3DGraphBase::_896;
  uVar1 = *(ushort *)(this + 0x14);
  uVar8 = (uint)*(byte *)((int)&local_18 + (uVar1 >> 9 & 3));
  uVar7 = uVar1 >> 7 & 3;
  iVar5 = -uVar8 + 2;
  uVar2 = (iVar5 - ((uint)(iVar5 == 0) + -uVar8 + 1)) * 0x200 & 0x1fe00;
  if (uVar8 == 0) {
    uVar7 = 0;
  }
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = 0;
  puVar4 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar4 + 1);
  *puVar4 = (char)(uVar2 >> 0x10);
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar8 != 0) * 0x400 >> 8) | (byte)(uVar2 >> 8) | (byte)((uVar7 << 7) >> 8)
  ;
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar7 << 7);
  return;
}


/* __thiscall J3DColorBlockAmbientOn::load(void) */

void __thiscall J3DColorBlockAmbientOn::load(J3DColorBlockAmbientOn *this)

{
  ushort uVar1;
  undefined *puVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if ((uint)gd::__GDCurrentDL[3] <
      (uint)(gd::__GDCurrentDL[2] + J3DGraphBase::SizeOfJ3DColorBlockAmbientOnLoad)) {
    gd::GDOverflowed();
  }
  *(int *)(this + 0x18) = gd::__GDCurrentDL[2] - *gd::__GDCurrentDL;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0x10;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 1;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0x10;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0xc;
  uVar6 = *(undefined4 *)(this + 4);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)((uint)uVar6 >> 0x18);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)((uint)uVar6 >> 0x10);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)((uint)uVar6 >> 8);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)uVar6;
  uVar6 = *(undefined4 *)(this + 8);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)((uint)uVar6 >> 0x18);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)((uint)uVar6 >> 0x10);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)((uint)uVar6 >> 8);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)uVar6;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0x10;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 1;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0x10;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 10;
  uVar6 = *(undefined4 *)(this + 0x20);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)((uint)uVar6 >> 0x18);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)((uint)uVar6 >> 0x10);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)((uint)uVar6 >> 8);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)uVar6;
  uVar6 = *(undefined4 *)(this + 0x24);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)((uint)uVar6 >> 0x18);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)((uint)uVar6 >> 0x10);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)((uint)uVar6 >> 8);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)uVar6;
  *(int *)(this + 0x1c) = gd::__GDCurrentDL[2] - *gd::__GDCurrentDL;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0x10;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 3;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0x10;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0xe;
  local_c = J3DGraphBase::_896;
  uVar1 = *(ushort *)(this + 0xe);
  uVar8 = (uint)*(byte *)((int)&local_c + (uVar1 >> 9 & 3));
  uVar7 = uVar1 >> 7 & 3;
  iVar4 = -uVar8 + 2;
  uVar5 = (iVar4 - ((uint)(iVar4 == 0) + -uVar8 + 1)) * 0x200 & 0x1fe00;
  if (uVar8 == 0) {
    uVar7 = 0;
  }
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(uVar5 >> 0x10);
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar8 != 0) * 0x400 >> 8) | (byte)(uVar5 >> 8) | (byte)((uVar7 << 7) >> 8)
  ;
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar7 << 7);
  local_10 = J3DGraphBase::_896;
  uVar1 = *(ushort *)(this + 0x12);
  uVar8 = (uint)*(byte *)((int)&local_10 + (uVar1 >> 9 & 3));
  uVar7 = uVar1 >> 7 & 3;
  iVar4 = -uVar8 + 2;
  uVar5 = (iVar4 - ((uint)(iVar4 == 0) + -uVar8 + 1)) * 0x200 & 0x1fe00;
  if (uVar8 == 0) {
    uVar7 = 0;
  }
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(uVar5 >> 0x10);
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar8 != 0) * 0x400 >> 8) | (byte)(uVar5 >> 8) | (byte)((uVar7 << 7) >> 8)
  ;
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar7 << 7);
  local_14 = J3DGraphBase::_896;
  uVar1 = *(ushort *)(this + 0x10);
  uVar8 = (uint)*(byte *)((int)&local_14 + (uVar1 >> 9 & 3));
  uVar7 = uVar1 >> 7 & 3;
  iVar4 = -uVar8 + 2;
  uVar5 = (iVar4 - ((uint)(iVar4 == 0) + -uVar8 + 1)) * 0x200 & 0x1fe00;
  if (uVar8 == 0) {
    uVar7 = 0;
  }
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(uVar5 >> 0x10);
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar8 != 0) * 0x400 >> 8) | (byte)(uVar5 >> 8) | (byte)((uVar7 << 7) >> 8)
  ;
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar7 << 7);
  local_18 = J3DGraphBase::_896;
  uVar1 = *(ushort *)(this + 0x14);
  uVar8 = (uint)*(byte *)((int)&local_18 + (uVar1 >> 9 & 3));
  uVar7 = uVar1 >> 7 & 3;
  iVar4 = -uVar8 + 2;
  uVar5 = (iVar4 - ((uint)(iVar4 == 0) + -uVar8 + 1)) * 0x200 & 0x1fe00;
  if (uVar8 == 0) {
    uVar7 = 0;
  }
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(uVar5 >> 0x10);
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar8 != 0) * 0x400 >> 8) | (byte)(uVar5 >> 8) | (byte)((uVar7 << 7) >> 8)
  ;
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar7 << 7);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DColorBlockLightOn::load(void) */

void __thiscall J3DColorBlockLightOn::load(J3DColorBlockLightOn *this)

{
  ushort uVar1;
  undefined *puVar2;
  byte *pbVar3;
  J3DLightObj *this_00;
  int iVar4;
  uint uVar5;
  J3DGXColor JVar6;
  uint uVar7;
  uint uVar8;
  ulong uVar9;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if ((uint)gd::__GDCurrentDL[3] <
      (uint)(gd::__GDCurrentDL[2] + J3DGraphBase::SizeOfJ3DColorBlockAmbientOnLoad)) {
    gd::GDOverflowed();
  }
  this->mMatColorOffs = gd::__GDCurrentDL[2] - *gd::__GDCurrentDL;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0x10;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 1;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0x10;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0xc;
  JVar6 = this->mColors[0];
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(JVar6 >> 0x18);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(JVar6 >> 0x10);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(JVar6 >> 8);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)JVar6;
  JVar6 = this->mColors[1];
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(JVar6 >> 0x18);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(JVar6 >> 0x10);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(JVar6 >> 8);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)JVar6;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0x10;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 1;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0x10;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 10;
  JVar6 = this->mColors[2];
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(JVar6 >> 0x18);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(JVar6 >> 0x10);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(JVar6 >> 8);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)JVar6;
  JVar6 = this->mColors[3];
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(JVar6 >> 0x18);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(JVar6 >> 0x10);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(JVar6 >> 8);
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)JVar6;
  this->mColorChanOffs = gd::__GDCurrentDL[2] - *gd::__GDCurrentDL;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0x10;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 3;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0x10;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0xe;
  local_1c = J3DGraphBase::_896;
  uVar1 = this->mColorChan[0].mChan;
  uVar8 = (uint)*(byte *)((int)&local_1c + (uVar1 >> 9 & 3));
  uVar7 = uVar1 >> 7 & 3;
  iVar4 = -uVar8 + 2;
  uVar5 = (iVar4 - ((uint)(iVar4 == 0) + -uVar8 + 1)) * 0x200 & 0x1fe00;
  if (uVar8 == 0) {
    uVar7 = 0;
  }
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(uVar5 >> 0x10);
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar8 != 0) * 0x400 >> 8) | (byte)(uVar5 >> 8) | (byte)((uVar7 << 7) >> 8)
  ;
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar7 << 7);
  local_20 = J3DGraphBase::_896;
  uVar1 = this->mColorChan[2].mChan;
  uVar8 = (uint)*(byte *)((int)&local_20 + (uVar1 >> 9 & 3));
  uVar7 = uVar1 >> 7 & 3;
  iVar4 = -uVar8 + 2;
  uVar5 = (iVar4 - ((uint)(iVar4 == 0) + -uVar8 + 1)) * 0x200 & 0x1fe00;
  if (uVar8 == 0) {
    uVar7 = 0;
  }
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(uVar5 >> 0x10);
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar8 != 0) * 0x400 >> 8) | (byte)(uVar5 >> 8) | (byte)((uVar7 << 7) >> 8)
  ;
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar7 << 7);
  local_24 = J3DGraphBase::_896;
  uVar1 = this->mColorChan[1].mChan;
  uVar8 = (uint)*(byte *)((int)&local_24 + (uVar1 >> 9 & 3));
  uVar7 = uVar1 >> 7 & 3;
  iVar4 = -uVar8 + 2;
  uVar5 = (iVar4 - ((uint)(iVar4 == 0) + -uVar8 + 1)) * 0x200 & 0x1fe00;
  if (uVar8 == 0) {
    uVar7 = 0;
  }
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(uVar5 >> 0x10);
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar8 != 0) * 0x400 >> 8) | (byte)(uVar5 >> 8) | (byte)((uVar7 << 7) >> 8)
  ;
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar7 << 7);
  local_28 = J3DGraphBase::_896;
  uVar1 = this->mColorChan[3].mChan;
  uVar8 = (uint)*(byte *)((int)&local_28 + (uVar1 >> 9 & 3));
  uVar7 = uVar1 >> 7 & 3;
  iVar4 = -uVar8 + 2;
  uVar5 = (iVar4 - ((uint)(iVar4 == 0) + -uVar8 + 1)) * 0x200 & 0x1fe00;
  if (uVar8 == 0) {
    uVar7 = 0;
  }
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(uVar5 >> 0x10);
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar8 != 0) * 0x400 >> 8) | (byte)(uVar5 >> 8) | (byte)((uVar7 << 7) >> 8)
  ;
  pbVar3 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar3 + 1);
  *pbVar3 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar7 << 7);
  uVar9 = 0;
  iVar4 = 0;
  do {
    this_00 = *(J3DLightObj **)((int)this->mpLights + iVar4);
    if (this_00 != (J3DLightObj *)0x0) {
      J3DLightObj::load(this_00,uVar9);
    }
    uVar9 = uVar9 + 1;
    iVar4 = iVar4 + 4;
  } while (uVar9 < 8);
  return;
}


/* __thiscall J3DColorBlockLightOff::patch(void) */

void __thiscall J3DColorBlockLightOff::patch(J3DColorBlockLightOff *this)

{
  (**(code **)(*(int *)this + 0x14))();
  (**(code **)(*(int *)this + 0x18))(this);
  return;
}


/* __thiscall J3DColorBlockLightOff::patchMatColor(void) */

void __thiscall J3DColorBlockLightOff::patchMatColor(J3DColorBlockLightOff *this)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + *(int *)(this + 0x18);
  iVar3 = gd::__GDCurrentDL[2];
  if ((uint)gd::__GDCurrentDL[3] < (uint)(iVar3 + J3DGraphBase::SizeOfLoadMatColors)) {
    gd::GDOverflowed();
  }
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = 0x10;
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = 0;
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = 1;
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = 0x10;
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = 0xc;
  uVar2 = *(undefined4 *)(this + 4);
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = (char)((uint)uVar2 >> 0x18);
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = (char)((uint)uVar2 >> 0x10);
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = (char)((uint)uVar2 >> 8);
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = (char)uVar2;
  uVar2 = *(undefined4 *)(this + 8);
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = (char)((uint)uVar2 >> 0x18);
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = (char)((uint)uVar2 >> 0x10);
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = (char)((uint)uVar2 >> 8);
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = (char)uVar2;
  os::DCFlushRange(iVar3,gd::__GDCurrentDL[2] - iVar3);
  return;
}


/* __thiscall J3DColorBlockLightOff::patchLight(void) */

void __thiscall J3DColorBlockLightOff::patchLight(J3DColorBlockLightOff *this)

{
  ushort uVar1;
  undefined *puVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + *(int *)(this + 0x1c);
  iVar8 = gd::__GDCurrentDL[2];
  if ((uint)gd::__GDCurrentDL[3] < (uint)(iVar8 + J3DGraphBase::SizeOfLoadColorChans)) {
    gd::GDOverflowed();
  }
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0x10;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 3;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0x10;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0xe;
  local_c = J3DGraphBase::_896;
  uVar1 = *(ushort *)(this + 0xe);
  uVar7 = (uint)*(byte *)((int)&local_c + (uVar1 >> 9 & 3));
  uVar6 = uVar1 >> 7 & 3;
  iVar5 = -uVar7 + 2;
  uVar3 = (iVar5 - ((uint)(iVar5 == 0) + -uVar7 + 1)) * 0x200 & 0x1fe00;
  if (uVar7 == 0) {
    uVar6 = 0;
  }
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(uVar3 >> 0x10);
  pbVar4 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar4 + 1);
  *pbVar4 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar7 != 0) * 0x400 >> 8) | (byte)(uVar3 >> 8) | (byte)((uVar6 << 7) >> 8)
  ;
  pbVar4 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar4 + 1);
  *pbVar4 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar6 << 7);
  local_10 = J3DGraphBase::_896;
  uVar1 = *(ushort *)(this + 0x12);
  uVar7 = (uint)*(byte *)((int)&local_10 + (uVar1 >> 9 & 3));
  uVar6 = uVar1 >> 7 & 3;
  iVar5 = -uVar7 + 2;
  uVar3 = (iVar5 - ((uint)(iVar5 == 0) + -uVar7 + 1)) * 0x200 & 0x1fe00;
  if (uVar7 == 0) {
    uVar6 = 0;
  }
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(uVar3 >> 0x10);
  pbVar4 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar4 + 1);
  *pbVar4 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar7 != 0) * 0x400 >> 8) | (byte)(uVar3 >> 8) | (byte)((uVar6 << 7) >> 8)
  ;
  pbVar4 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar4 + 1);
  *pbVar4 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar6 << 7);
  local_14 = J3DGraphBase::_896;
  uVar1 = *(ushort *)(this + 0x10);
  uVar7 = (uint)*(byte *)((int)&local_14 + (uVar1 >> 9 & 3));
  uVar6 = uVar1 >> 7 & 3;
  iVar5 = -uVar7 + 2;
  uVar3 = (iVar5 - ((uint)(iVar5 == 0) + -uVar7 + 1)) * 0x200 & 0x1fe00;
  if (uVar7 == 0) {
    uVar6 = 0;
  }
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(uVar3 >> 0x10);
  pbVar4 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar4 + 1);
  *pbVar4 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar7 != 0) * 0x400 >> 8) | (byte)(uVar3 >> 8) | (byte)((uVar6 << 7) >> 8)
  ;
  pbVar4 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar4 + 1);
  *pbVar4 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar6 << 7);
  local_18 = J3DGraphBase::_896;
  uVar1 = *(ushort *)(this + 0x14);
  uVar7 = (uint)*(byte *)((int)&local_18 + (uVar1 >> 9 & 3));
  uVar6 = uVar1 >> 7 & 3;
  iVar5 = -uVar7 + 2;
  uVar3 = (iVar5 - ((uint)(iVar5 == 0) + -uVar7 + 1)) * 0x200 & 0x1fe00;
  if (uVar7 == 0) {
    uVar6 = 0;
  }
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(uVar3 >> 0x10);
  pbVar4 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar4 + 1);
  *pbVar4 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar7 != 0) * 0x400 >> 8) | (byte)(uVar3 >> 8) | (byte)((uVar6 << 7) >> 8)
  ;
  pbVar4 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar4 + 1);
  *pbVar4 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar6 << 7);
  os::DCFlushRange(iVar8,gd::__GDCurrentDL[2] - iVar8);
  return;
}


/* __thiscall J3DColorBlockLightOn::patch(void) */

void __thiscall J3DColorBlockLightOn::patch(J3DColorBlockLightOn *this)

{
  (*(code *)((this->parent).vtbl)->patchMatColor)();
  (*(code *)((this->parent).vtbl)->patchLight)(this);
  return;
}


/* __thiscall J3DColorBlockLightOn::patchMatColor(void) */

void __thiscall J3DColorBlockLightOn::patchMatColor(J3DColorBlockLightOn *this)

{
  undefined *puVar1;
  J3DGXColor JVar2;
  int iVar3;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + this->mMatColorOffs;
  iVar3 = gd::__GDCurrentDL[2];
  if ((uint)gd::__GDCurrentDL[3] < (uint)(iVar3 + J3DGraphBase::SizeOfLoadMatColors)) {
    gd::GDOverflowed();
  }
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = 0x10;
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = 0;
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = 1;
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = 0x10;
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = 0xc;
  JVar2 = this->mColors[0];
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = (char)(JVar2 >> 0x18);
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = (char)(JVar2 >> 0x10);
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = (char)(JVar2 >> 8);
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = (char)JVar2;
  JVar2 = this->mColors[1];
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = (char)(JVar2 >> 0x18);
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = (char)(JVar2 >> 0x10);
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = (char)(JVar2 >> 8);
  puVar1 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar1 + 1);
  *puVar1 = (char)JVar2;
  os::DCFlushRange(iVar3,gd::__GDCurrentDL[2] - iVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DColorBlockLightOn::patchLight(void) */

void __thiscall J3DColorBlockLightOn::patchLight(J3DColorBlockLightOn *this)

{
  ushort uVar1;
  undefined *puVar2;
  uint uVar3;
  byte *pbVar4;
  J3DLightObj *this_00;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  int iVar9;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + this->mColorChanOffs;
  iVar9 = gd::__GDCurrentDL[2];
  if ((uint)gd::__GDCurrentDL[3] < (uint)(iVar9 + J3DGraphBase::SizeOfLoadColorChans)) {
    gd::GDOverflowed();
  }
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0x10;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 3;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0x10;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0xe;
  local_1c = J3DGraphBase::_896;
  uVar1 = this->mColorChan[0].mChan;
  uVar7 = (uint)*(byte *)((int)&local_1c + (uVar1 >> 9 & 3));
  uVar6 = uVar1 >> 7 & 3;
  iVar5 = -uVar7 + 2;
  uVar3 = (iVar5 - ((uint)(iVar5 == 0) + -uVar7 + 1)) * 0x200 & 0x1fe00;
  if (uVar7 == 0) {
    uVar6 = 0;
  }
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(uVar3 >> 0x10);
  pbVar4 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar4 + 1);
  *pbVar4 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar7 != 0) * 0x400 >> 8) | (byte)(uVar3 >> 8) | (byte)((uVar6 << 7) >> 8)
  ;
  pbVar4 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar4 + 1);
  *pbVar4 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar6 << 7);
  local_20 = J3DGraphBase::_896;
  uVar1 = this->mColorChan[2].mChan;
  uVar7 = (uint)*(byte *)((int)&local_20 + (uVar1 >> 9 & 3));
  uVar6 = uVar1 >> 7 & 3;
  iVar5 = -uVar7 + 2;
  uVar3 = (iVar5 - ((uint)(iVar5 == 0) + -uVar7 + 1)) * 0x200 & 0x1fe00;
  if (uVar7 == 0) {
    uVar6 = 0;
  }
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(uVar3 >> 0x10);
  pbVar4 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar4 + 1);
  *pbVar4 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar7 != 0) * 0x400 >> 8) | (byte)(uVar3 >> 8) | (byte)((uVar6 << 7) >> 8)
  ;
  pbVar4 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar4 + 1);
  *pbVar4 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar6 << 7);
  local_24 = J3DGraphBase::_896;
  uVar1 = this->mColorChan[1].mChan;
  uVar7 = (uint)*(byte *)((int)&local_24 + (uVar1 >> 9 & 3));
  uVar6 = uVar1 >> 7 & 3;
  iVar5 = -uVar7 + 2;
  uVar3 = (iVar5 - ((uint)(iVar5 == 0) + -uVar7 + 1)) * 0x200 & 0x1fe00;
  if (uVar7 == 0) {
    uVar6 = 0;
  }
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(uVar3 >> 0x10);
  pbVar4 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar4 + 1);
  *pbVar4 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar7 != 0) * 0x400 >> 8) | (byte)(uVar3 >> 8) | (byte)((uVar6 << 7) >> 8)
  ;
  pbVar4 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar4 + 1);
  *pbVar4 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar6 << 7);
  local_28 = J3DGraphBase::_896;
  uVar1 = this->mColorChan[3].mChan;
  uVar7 = (uint)*(byte *)((int)&local_28 + (uVar1 >> 9 & 3));
  uVar6 = uVar1 >> 7 & 3;
  iVar5 = -uVar7 + 2;
  uVar3 = (iVar5 - ((uint)(iVar5 == 0) + -uVar7 + 1)) * 0x200 & 0x1fe00;
  if (uVar7 == 0) {
    uVar6 = 0;
  }
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = 0;
  puVar2 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar2 + 1);
  *puVar2 = (char)(uVar3 >> 0x10);
  pbVar4 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar4 + 1);
  *pbVar4 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar7 != 0) * 0x400 >> 8) | (byte)(uVar3 >> 8) | (byte)((uVar6 << 7) >> 8)
  ;
  pbVar4 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar4 + 1);
  *pbVar4 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar6 << 7);
  uVar8 = 0;
  iVar5 = 0;
  do {
    this_00 = *(J3DLightObj **)((int)this->mpLights + iVar5);
    if (this_00 != (J3DLightObj *)0x0) {
      J3DLightObj::load(this_00,uVar8);
    }
    uVar8 = uVar8 + 1;
    iVar5 = iVar5 + 4;
  } while (uVar8 < 8);
  os::DCFlushRange(iVar9,gd::__GDCurrentDL[2] - iVar9);
  return;
}


/* __thiscall J3DColorBlockLightOff::diff(unsigned long) */

void __thiscall J3DColorBlockLightOff::diff(J3DColorBlockLightOff *this,ulong param_1)

{
  if ((param_1 & 1) != 0) {
    (**(code **)(*(int *)this + 0x20))();
  }
  if ((param_1 & 2) != 0) {
    (**(code **)(*(int *)this + 0x24))(this);
  }
  return;
}


/* __thiscall J3DColorBlockLightOff::diffMatColor(void) */

void __thiscall J3DColorBlockLightOff::diffMatColor(J3DColorBlockLightOff *this)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  if (*(uint *)(gd::__GDCurrentDL + 0xc) <
      (uint)(*(int *)(gd::__GDCurrentDL + 8) + J3DGraphBase::SizeOfLoadMatColors)) {
    gd::GDOverflowed();
  }
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x10;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 1;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x10;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0xc;
  uVar2 = *(undefined4 *)(this + 4);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)((uint)uVar2 >> 0x18);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)((uint)uVar2 >> 0x10);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)((uint)uVar2 >> 8);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)uVar2;
  uVar2 = *(undefined4 *)(this + 8);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)((uint)uVar2 >> 0x18);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)((uint)uVar2 >> 0x10);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)((uint)uVar2 >> 8);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)uVar2;
  return;
}


/* __thiscall J3DColorBlockLightOff::diffLight(void) */

void __thiscall J3DColorBlockLightOff::diffLight(J3DColorBlockLightOff *this)

{
  ushort uVar1;
  undefined *puVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (*(uint *)(gd::__GDCurrentDL + 0xc) <
      (uint)(*(int *)(gd::__GDCurrentDL + 8) + J3DGraphBase::SizeOfLoadColorChans)) {
    gd::GDOverflowed();
  }
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0x10;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 3;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0x10;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0xe;
  local_c = J3DGraphBase::_896;
  uVar1 = *(ushort *)(this + 0xe);
  uVar7 = (uint)*(byte *)((int)&local_c + (uVar1 >> 9 & 3));
  uVar6 = uVar1 >> 7 & 3;
  iVar5 = -uVar7 + 2;
  uVar3 = (iVar5 - ((uint)(iVar5 == 0) + -uVar7 + 1)) * 0x200 & 0x1fe00;
  if (uVar7 == 0) {
    uVar6 = 0;
  }
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)(uVar3 >> 0x10);
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar7 != 0) * 0x400 >> 8) | (byte)(uVar3 >> 8) | (byte)((uVar6 << 7) >> 8)
  ;
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar6 << 7);
  local_10 = J3DGraphBase::_896;
  uVar1 = *(ushort *)(this + 0x12);
  uVar7 = (uint)*(byte *)((int)&local_10 + (uVar1 >> 9 & 3));
  uVar6 = uVar1 >> 7 & 3;
  iVar5 = -uVar7 + 2;
  uVar3 = (iVar5 - ((uint)(iVar5 == 0) + -uVar7 + 1)) * 0x200 & 0x1fe00;
  if (uVar7 == 0) {
    uVar6 = 0;
  }
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)(uVar3 >> 0x10);
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar7 != 0) * 0x400 >> 8) | (byte)(uVar3 >> 8) | (byte)((uVar6 << 7) >> 8)
  ;
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar6 << 7);
  local_14 = J3DGraphBase::_896;
  uVar1 = *(ushort *)(this + 0x10);
  uVar7 = (uint)*(byte *)((int)&local_14 + (uVar1 >> 9 & 3));
  uVar6 = uVar1 >> 7 & 3;
  iVar5 = -uVar7 + 2;
  uVar3 = (iVar5 - ((uint)(iVar5 == 0) + -uVar7 + 1)) * 0x200 & 0x1fe00;
  if (uVar7 == 0) {
    uVar6 = 0;
  }
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)(uVar3 >> 0x10);
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar7 != 0) * 0x400 >> 8) | (byte)(uVar3 >> 8) | (byte)((uVar6 << 7) >> 8)
  ;
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar6 << 7);
  local_18 = J3DGraphBase::_896;
  uVar1 = *(ushort *)(this + 0x14);
  uVar7 = (uint)*(byte *)((int)&local_18 + (uVar1 >> 9 & 3));
  uVar6 = uVar1 >> 7 & 3;
  iVar5 = -uVar7 + 2;
  uVar3 = (iVar5 - ((uint)(iVar5 == 0) + -uVar7 + 1)) * 0x200 & 0x1fe00;
  if (uVar7 == 0) {
    uVar6 = 0;
  }
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)(uVar3 >> 0x10);
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar7 != 0) * 0x400 >> 8) | (byte)(uVar3 >> 8) | (byte)((uVar6 << 7) >> 8)
  ;
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar6 << 7);
  return;
}


/* __thiscall J3DColorBlockLightOn::diff(unsigned long) */

void __thiscall J3DColorBlockLightOn::diff(J3DColorBlockLightOn *this,ulong param_1)

{
  if ((param_1 & 1) != 0) {
    (*(code *)((this->parent).vtbl)->diffMatColor)();
  }
  if (((param_1 & 2) != 0) || ((param_1 >> 4 & 0xf) != 0)) {
    (*(code *)((this->parent).vtbl)->diffLight)(this);
  }
  return;
}


/* __thiscall J3DColorBlockLightOn::diffMatColor(void) */

void __thiscall J3DColorBlockLightOn::diffMatColor(J3DColorBlockLightOn *this)

{
  undefined *puVar1;
  J3DGXColor JVar2;
  
  if (*(uint *)(gd::__GDCurrentDL + 0xc) <
      (uint)(*(int *)(gd::__GDCurrentDL + 8) + J3DGraphBase::SizeOfLoadMatColors)) {
    gd::GDOverflowed();
  }
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x10;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 1;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x10;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0xc;
  JVar2 = this->mColors[0];
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)(JVar2 >> 0x18);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)(JVar2 >> 0x10);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)(JVar2 >> 8);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)JVar2;
  JVar2 = this->mColors[1];
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)(JVar2 >> 0x18);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)(JVar2 >> 0x10);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)(JVar2 >> 8);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)JVar2;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DColorBlockLightOn::diffLight(void) */

void __thiscall J3DColorBlockLightOn::diffLight(J3DColorBlockLightOn *this)

{
  ushort uVar1;
  undefined *puVar2;
  uint uVar3;
  byte *pbVar4;
  J3DLightObj *this_00;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (*(uint *)(gd::__GDCurrentDL + 0xc) <
      (uint)(*(int *)(gd::__GDCurrentDL + 8) + J3DGraphBase::SizeOfLoadColorChans)) {
    gd::GDOverflowed();
  }
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0x10;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 3;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0x10;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0xe;
  local_1c = J3DGraphBase::_896;
  uVar1 = this->mColorChan[0].mChan;
  uVar7 = (uint)*(byte *)((int)&local_1c + (uVar1 >> 9 & 3));
  uVar6 = uVar1 >> 7 & 3;
  iVar5 = -uVar7 + 2;
  uVar3 = (iVar5 - ((uint)(iVar5 == 0) + -uVar7 + 1)) * 0x200 & 0x1fe00;
  if (uVar7 == 0) {
    uVar6 = 0;
  }
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)(uVar3 >> 0x10);
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar7 != 0) * 0x400 >> 8) | (byte)(uVar3 >> 8) | (byte)((uVar6 << 7) >> 8)
  ;
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar6 << 7);
  local_20 = J3DGraphBase::_896;
  uVar1 = this->mColorChan[2].mChan;
  uVar7 = (uint)*(byte *)((int)&local_20 + (uVar1 >> 9 & 3));
  uVar6 = uVar1 >> 7 & 3;
  iVar5 = -uVar7 + 2;
  uVar3 = (iVar5 - ((uint)(iVar5 == 0) + -uVar7 + 1)) * 0x200 & 0x1fe00;
  if (uVar7 == 0) {
    uVar6 = 0;
  }
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)(uVar3 >> 0x10);
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar7 != 0) * 0x400 >> 8) | (byte)(uVar3 >> 8) | (byte)((uVar6 << 7) >> 8)
  ;
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar6 << 7);
  local_24 = J3DGraphBase::_896;
  uVar1 = this->mColorChan[1].mChan;
  uVar7 = (uint)*(byte *)((int)&local_24 + (uVar1 >> 9 & 3));
  uVar6 = uVar1 >> 7 & 3;
  iVar5 = -uVar7 + 2;
  uVar3 = (iVar5 - ((uint)(iVar5 == 0) + -uVar7 + 1)) * 0x200 & 0x1fe00;
  if (uVar7 == 0) {
    uVar6 = 0;
  }
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)(uVar3 >> 0x10);
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar7 != 0) * 0x400 >> 8) | (byte)(uVar3 >> 8) | (byte)((uVar6 << 7) >> 8)
  ;
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar6 << 7);
  local_28 = J3DGraphBase::_896;
  uVar1 = this->mColorChan[3].mChan;
  uVar7 = (uint)*(byte *)((int)&local_28 + (uVar1 >> 9 & 3));
  uVar6 = uVar1 >> 7 & 3;
  iVar5 = -uVar7 + 2;
  uVar3 = (iVar5 - ((uint)(iVar5 == 0) + -uVar7 + 1)) * 0x200 & 0x1fe00;
  if (uVar7 == 0) {
    uVar6 = 0;
  }
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)(uVar3 >> 0x10);
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)(((uVar1 >> 7 & 0xf0) << 7) >> 8) |
            (byte)((uint)(uVar7 != 0) * 0x400 >> 8) | (byte)(uVar3 >> 8) | (byte)((uVar6 << 7) >> 8)
  ;
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)uVar1 & 0x40 | (byte)((uVar1 >> 2 & 0xf) << 2) | (byte)uVar1 & 3 |
            (byte)(uVar6 << 7);
  uVar8 = 0;
  iVar5 = 0;
  do {
    this_00 = *(J3DLightObj **)((int)this->mpLights + iVar5);
    if (this_00 != (J3DLightObj *)0x0) {
      J3DLightObj::load(this_00,uVar8);
    }
    uVar8 = uVar8 + 1;
    iVar5 = iVar5 + 4;
  } while (uVar8 < 8);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DTexGenBlock4::load(void) */

void __thiscall J3DTexGenBlock4::load(J3DTexGenBlock4 *this)

{
  J3DTexMtx *this_00;
  ulong uVar1;
  int iVar2;
  
  *(int *)(this + 0x48) = gd::__GDCurrentDL[2] - *gd::__GDCurrentDL;
  uVar1 = 0;
  iVar2 = 0;
  do {
    this_00 = *(J3DTexMtx **)(this + iVar2 + 0x28);
    if ((this_00 != (J3DTexMtx *)0x0) && ((this + iVar2)[10] != (J3DTexGenBlock4)0x3c)) {
      J3DTexMtx::load(this_00,uVar1);
    }
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 4;
  } while (uVar1 < 4);
  if (*(int *)(this + 4) != 0) {
    J3DGraphBase::loadTexCoordGens(*(int *)(this + 4),this + 8);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DTexGenBlockBasic::load(void) */

void __thiscall J3DTexGenBlockBasic::load(J3DTexGenBlockBasic *this)

{
  J3DTexMtx *this_00;
  ulong uVar1;
  int iVar2;
  
  *(int *)(this + 0x48) = gd::__GDCurrentDL[2] - *gd::__GDCurrentDL;
  uVar1 = 0;
  iVar2 = 0;
  do {
    this_00 = *(J3DTexMtx **)(this + iVar2 + 0x28);
    if ((this_00 != (J3DTexMtx *)0x0) && ((this + iVar2)[10] != (J3DTexGenBlockBasic)0x3c)) {
      J3DTexMtx::load(this_00,uVar1);
    }
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 4;
  } while (uVar1 < 8);
  if (*(int *)(this + 4) != 0) {
    J3DGraphBase::loadTexCoordGens(*(int *)(this + 4),this + 8);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DTexGenBlockPatched::patch(void) */

void __thiscall J3DTexGenBlockPatched::patch(J3DTexGenBlockPatched *this)

{
  J3DTexMtx *this_00;
  ulong uVar1;
  int iVar2;
  int iVar3;
  
  gd::__GDCurrentDL[2] = (int)&(this[9].vtbl)->field_0x0 + *gd::__GDCurrentDL;
  iVar2 = gd::__GDCurrentDL[2];
  uVar1 = 0;
  iVar3 = 0;
  do {
    this_00 = *(J3DTexMtx **)((int)&this[5].vtbl + iVar3);
    if (this_00 != (J3DTexMtx *)0x0) {
      J3DTexMtx::load(this_00,uVar1);
    }
    uVar1 = uVar1 + 1;
    iVar3 = iVar3 + 4;
  } while (uVar1 < 8);
  os::DCFlushRange(iVar2,gd::__GDCurrentDL[2] - iVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DTexGenBlock4::patch(void) */

void __thiscall J3DTexGenBlock4::patch(J3DTexGenBlock4 *this)

{
  J3DTexMtx *this_00;
  ulong uVar1;
  int iVar2;
  int iVar3;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + *(int *)(this + 0x48);
  iVar2 = gd::__GDCurrentDL[2];
  uVar1 = 0;
  iVar3 = 0;
  do {
    this_00 = *(J3DTexMtx **)(this + iVar3 + 0x28);
    if ((this_00 != (J3DTexMtx *)0x0) && ((this + iVar3)[10] != (J3DTexGenBlock4)0x3c)) {
      J3DTexMtx::load(this_00,uVar1);
    }
    uVar1 = uVar1 + 1;
    iVar3 = iVar3 + 4;
  } while (uVar1 < 4);
  os::DCFlushRange(iVar2,gd::__GDCurrentDL[2] - iVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DTexGenBlockBasic::patch(void) */

void __thiscall J3DTexGenBlockBasic::patch(J3DTexGenBlockBasic *this)

{
  J3DTexMtx *this_00;
  ulong uVar1;
  int iVar2;
  int iVar3;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + *(int *)(this + 0x48);
  iVar2 = gd::__GDCurrentDL[2];
  uVar1 = 0;
  iVar3 = 0;
  do {
    this_00 = *(J3DTexMtx **)(this + iVar3 + 0x28);
    if ((this_00 != (J3DTexMtx *)0x0) && ((this + iVar3)[10] != (J3DTexGenBlockBasic)0x3c)) {
      J3DTexMtx::load(this_00,uVar1);
    }
    uVar1 = uVar1 + 1;
    iVar3 = iVar3 + 4;
  } while (uVar1 < 8);
  os::DCFlushRange(iVar2,gd::__GDCurrentDL[2] - iVar2);
  return;
}


/* __thiscall J3DTexGenBlockPatched::diff(unsigned long) */

void __thiscall J3DTexGenBlockPatched::diff(J3DTexGenBlockPatched *this,ulong param_1)

{
  if (((param_1 >> 8 & 0xf) != 0) && ((*(code *)this->vtbl->diffTexMtx)(), (param_1 & 0x1000) != 0))
  {
    (*(code *)this->vtbl->diffTexGen)(this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DTexGenBlockPatched::diffTexMtx(void) */

void __thiscall J3DTexGenBlockPatched::diffTexMtx(J3DTexGenBlockPatched *this)

{
  J3DTexMtx *this_00;
  ulong uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = 0;
  do {
    this_00 = *(J3DTexMtx **)((int)&this[5].vtbl + iVar2);
    if (this_00 != (J3DTexMtx *)0x0) {
      J3DTexMtx::load(this_00,uVar1);
    }
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 4;
  } while (uVar1 < 8);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DTexGenBlockPatched::diffTexGen(void) */

void __thiscall J3DTexGenBlockPatched::diffTexGen(J3DTexGenBlockPatched *this)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  
  puVar4 = this->field_0x4;
  if (puVar4 != (undefined *)0x0) {
    puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
    *puVar1 = 0x10;
    iVar3 = ((uint)puVar4 & 0xff) - 1;
    puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
    *puVar1 = (char)((uint)iVar3 >> 8);
    puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
    *puVar1 = (char)iVar3;
    puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
    *puVar1 = 0x10;
    puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
    *puVar1 = 0x40;
  }
  iVar3 = 0;
  for (puVar1 = (undefined *)0x0; puVar1 < puVar4; puVar1 = puVar1 + 1) {
    iVar2 = (int)&this->vtbl + iVar3;
    J3DGraphBase::J3DGDSetTexCoordGen(*(undefined *)(iVar2 + 8),*(undefined *)(iVar2 + 9));
    iVar3 = iVar3 + 4;
  }
  return;
}


/* __thiscall J3DTevBlock1::load(void) */

void __thiscall J3DTevBlock1::load(J3DTevBlock1 *this)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  undefined *puVar5;
  undefined4 uVar6;
  
  *(int *)(this + 4) = gd::__GDCurrentDL[2] - *gd::__GDCurrentDL;
  if ((uint)gd::__GDCurrentDL[3] < gd::__GDCurrentDL[2] + 0x69U) {
    gd::GDOverflowed();
  }
  if (*(short *)(this + 8) != -1) {
    J3DGraphBase::loadTexNo(0,this + 8);
  }
  J3DGraphBase::J3DGDSetTevOrder(0,this[10],this[0xb],this[0xc],0xff,0xff,0xff);
  uVar1 = (byte)this[0xb] & 7;
  uVar2 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar1 * 4]);
  uVar3 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar1 * 4]);
  J3DGraphBase::J3DGDSetTexCoordScale2
            (this[10],*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar1 * 8),uVar2 >> 5 & 0xff,0,
             (&DAT_803edbca)[uVar1 * 4],uVar3 >> 5 & 0xff,0);
  uVar6 = *(undefined4 *)(this + 0xe);
  puVar5 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar5 + 1);
  *puVar5 = 0x61;
  puVar5 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar5 + 1);
  *puVar5 = (char)((uint)uVar6 >> 0x18);
  puVar5 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar5 + 1);
  *puVar5 = (char)((uint)uVar6 >> 0x10);
  puVar5 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar5 + 1);
  *puVar5 = (char)((uint)uVar6 >> 8);
  puVar5 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar5 + 1);
  *puVar5 = (char)uVar6;
  uVar6 = *(undefined4 *)(this + 0x12);
  puVar5 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar5 + 1);
  *puVar5 = 0x61;
  puVar5 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar5 + 1);
  *puVar5 = (char)((uint)uVar6 >> 0x18);
  puVar5 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar5 + 1);
  *puVar5 = (char)((uint)uVar6 >> 0x10);
  puVar5 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar5 + 1);
  *puVar5 = (char)((uint)uVar6 >> 8);
  puVar5 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar5 + 1);
  *puVar5 = (char)uVar6;
  uVar6 = *(undefined4 *)(this + 0x18);
  puVar5 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar5 + 1);
  *puVar5 = 0x61;
  pbVar4 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar4 + 1);
  *pbVar4 = (byte)((uint)uVar6 >> 0x18) | 0x10;
  puVar5 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar5 + 1);
  *puVar5 = (char)((uint)uVar6 >> 0x10);
  puVar5 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar5 + 1);
  *puVar5 = (char)((uint)uVar6 >> 8);
  puVar5 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar5 + 1);
  *puVar5 = (char)uVar6;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DTevBlock2::load(void) */

void __thiscall J3DTevBlock2::load(J3DTevBlock2 *this)

{
  byte bVar1;
  byte bVar2;
  J3DTevBlock2 JVar3;
  J3DTevBlock2 JVar4;
  J3DTevBlock2 JVar5;
  J3DTevBlock2 JVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  int iVar10;
  byte *pbVar11;
  undefined *puVar12;
  undefined4 uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  uVar16 = (uint)(byte)this[0x34];
  *(int *)(this + 4) = gd::__GDCurrentDL[2] - *gd::__GDCurrentDL;
  uVar14 = 0;
  iVar15 = 0;
  do {
    if (*(short *)(this + iVar15 + 8) != -1) {
      J3DGraphBase::loadTexNo(uVar14);
    }
    uVar14 = uVar14 + 1;
    iVar15 = iVar15 + 2;
  } while (uVar14 < 2);
  J3DGraphBase::J3DGDSetTevOrder(0,this[0xc],this[0xd],this[0xe],this[0x10],this[0x11],this[0x12]);
  uVar14 = (byte)this[0xd] & 7;
  uVar7 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar14 * 4]);
  uVar8 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar14 * 4]);
  J3DGraphBase::J3DGDSetTexCoordScale2
            (this[0xc],*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar14 * 8),uVar7 >> 5 & 0xff,
             0,(&DAT_803edbca)[uVar14 * 4],uVar8 >> 5 & 0xff,0);
  uVar14 = (byte)this[0x11] & 7;
  uVar7 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar14 * 4]);
  uVar8 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar14 * 4]);
  J3DGraphBase::J3DGDSetTexCoordScale2
            ((byte)this[0x10] & 7,*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar14 * 8),
             uVar7 >> 5 & 0xff,0,(&DAT_803edbca)[uVar14 * 4],uVar8 >> 5 & 0xff,0);
  *(int *)(this + 0x68) = gd::__GDCurrentDL[2] - *gd::__GDCurrentDL;
  uVar14 = 0;
  iVar15 = 0;
  do {
    local_24 = *(undefined4 *)(this + iVar15 + 0x14);
    local_20 = *(undefined4 *)((int)(this + iVar15 + 0x14) + 4);
    J3DGraphBase::J3DGDSetTevColorS10(uVar14 + 1,&local_24);
    uVar14 = uVar14 + 1;
    iVar15 = iVar15 + 8;
  } while (uVar14 < 3);
  uVar14 = 0;
  iVar15 = 0;
  do {
    local_28 = *(undefined4 *)(this + iVar15 + 0x45);
    J3DGraphBase::J3DGDSetTevKColor(uVar14,&local_28);
    uVar14 = uVar14 + 1;
    iVar15 = iVar15 + 4;
  } while (uVar14 < 4);
  cVar9 = '\0';
  iVar15 = 0;
  iVar10 = 0;
  for (; uVar16 != 0; uVar16 = uVar16 - 1) {
    uVar13 = *(undefined4 *)(this + iVar10 + 0x35);
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = 0x61;
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = (char)((uint)uVar13 >> 0x18);
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = (char)((uint)uVar13 >> 0x10);
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = (char)((uint)uVar13 >> 8);
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = (char)uVar13;
    uVar13 = *(undefined4 *)((int)(this + iVar10 + 0x35) + 4);
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = 0x61;
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = (char)((uint)uVar13 >> 0x18);
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = (char)((uint)uVar13 >> 0x10);
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = (char)((uint)uVar13 >> 8);
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = (char)uVar13;
    uVar13 = *(undefined4 *)(this + iVar15 + 0x60);
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = 0x61;
    pbVar11 = (byte *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(pbVar11 + 1);
    *pbVar11 = (byte)((uint)uVar13 >> 0x18) | cVar9 + 0x10U;
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = (char)((uint)uVar13 >> 0x10);
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = (char)((uint)uVar13 >> 8);
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = (char)uVar13;
    cVar9 = cVar9 + '\x01';
    iVar15 = iVar15 + 4;
    iVar10 = iVar10 + 8;
  }
  uVar16 = 0;
  iVar15 = 4;
  do {
    iVar10 = (uVar16 >> 2) + 0x59;
    bVar1 = (&DAT_803ef9e1)[(uint)(byte)this[iVar10] * 4];
    bVar2 = (&J3DGraphBase::j3dTevSwapTableTable)[(uint)(byte)this[iVar10] * 4];
    JVar3 = this[0x58];
    JVar4 = this[0x56];
    JVar5 = this[0x57];
    JVar6 = this[0x55];
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = 0x61;
    uVar14 = (uint)(byte)JVar6 << 4 | (uint)bVar2 | (uint)bVar1 << 2;
    uVar7 = (uint)(byte)JVar4 << 0xe | (uint)(byte)JVar5 << 9 | uVar14;
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = (char)((uint)((((int)uVar16 >> 1) + 0xf6) * 0x1000000) >> 0x18);
    pbVar11 = (byte *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(pbVar11 + 1);
    *pbVar11 = (byte)((((byte)JVar3 & 0x1f) << 0x13) >> 0x10) | (byte)(uVar7 >> 0x10);
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = (char)(uVar7 >> 8);
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = (char)uVar14;
    bVar1 = (&DAT_803ef9e3)[(uint)(byte)this[iVar10] * 4];
    bVar2 = (&DAT_803ef9e2)[(uint)(byte)this[iVar10] * 4];
    JVar3 = this[0x58];
    JVar4 = this[0x56];
    JVar5 = this[0x57];
    JVar6 = this[0x55];
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = 0x61;
    uVar14 = (uint)(byte)JVar6 << 4 | (uint)bVar2 | (uint)bVar1 << 2;
    uVar7 = (uint)(byte)JVar4 << 0xe | (uint)(byte)JVar5 << 9 | uVar14;
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = (char)((uint)((((int)(uVar16 + 2) >> 1) + 0xf6) * 0x1000000) >> 0x18);
    pbVar11 = (byte *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(pbVar11 + 1);
    *pbVar11 = (byte)((((byte)JVar3 & 0x1f) << 0x13) >> 0x10) | (byte)(uVar7 >> 0x10);
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = (char)(uVar7 >> 8);
    puVar12 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar12 + 1);
    *puVar12 = (char)uVar14;
    uVar16 = uVar16 + 4;
    iVar15 = iVar15 + -1;
  } while (iVar15 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall J3DTevBlock4::load(void) */

void __thiscall J3DTevBlock4::load(J3DTevBlock4 *this)

{
  byte bVar1;
  byte bVar2;
  J3DTevBlock4 JVar3;
  J3DTevBlock4 JVar4;
  J3DTevBlock4 JVar5;
  J3DTevBlock4 JVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  int iVar10;
  byte *pbVar11;
  uint uVar12;
  undefined *puVar13;
  undefined4 uVar14;
  uint uVar15;
  J3DTevBlock4 *pJVar16;
  int iVar17;
  uint uVar18;
  J3DTevBlock4 *pJVar19;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  uVar18 = (uint)(byte)this[0x20];
  *(int *)(this + 4) = gd::__GDCurrentDL[2] - *gd::__GDCurrentDL;
  uVar15 = 0;
  iVar17 = 0;
  do {
    if (*(short *)(this + iVar17 + 8) != -1) {
      J3DGraphBase::loadTexNo(uVar15);
    }
    uVar15 = uVar15 + 1;
    iVar17 = iVar17 + 2;
  } while (uVar15 < 4);
  iVar17 = 0;
  for (uVar15 = 0; uVar15 < uVar18; uVar15 = uVar15 + 2) {
    pJVar19 = this + (uVar15 + 1) * 4;
    pJVar16 = this + iVar17;
    J3DGraphBase::J3DGDSetTevOrder
              (uVar15,pJVar16[0x10],pJVar16[0x11],pJVar16[0x12],pJVar19[0x10],pJVar19[0x11],
               pJVar19[0x12]);
    uVar12 = (byte)pJVar16[0x11] & 7;
    uVar7 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar12 * 4]);
    uVar8 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar12 * 4]);
    J3DGraphBase::J3DGDSetTexCoordScale2
              ((byte)pJVar16[0x10] & 7,*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar12 * 8),
               uVar7 >> 5 & 0xff,0,(&DAT_803edbca)[uVar12 * 4],uVar8 >> 5 & 0xff,0);
    uVar12 = (byte)pJVar19[0x11] & 7;
    uVar7 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar12 * 4]);
    uVar8 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar12 * 4]);
    J3DGraphBase::J3DGDSetTexCoordScale2
              ((byte)pJVar19[0x10] & 7,*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar12 * 8),
               uVar7 >> 5 & 0xff,0,(&DAT_803edbca)[uVar12 * 4],uVar8 >> 5 & 0xff,0);
    iVar17 = iVar17 + 8;
  }
  *(int *)(this + 0x90) = gd::__GDCurrentDL[2] - *gd::__GDCurrentDL;
  uVar15 = 0;
  iVar17 = 0;
  do {
    local_34 = *(undefined4 *)(this + iVar17 + 0x42);
    local_30 = *(undefined4 *)((int)(this + iVar17 + 0x42) + 4);
    J3DGraphBase::J3DGDSetTevColorS10(uVar15 + 1,&local_34);
    uVar15 = uVar15 + 1;
    iVar17 = iVar17 + 8;
  } while (uVar15 < 3);
  uVar15 = 0;
  iVar17 = 0;
  do {
    local_38 = *(undefined4 *)(this + iVar17 + 0x62);
    J3DGraphBase::J3DGDSetTevKColor(uVar15,&local_38);
    uVar15 = uVar15 + 1;
    iVar17 = iVar17 + 4;
  } while (uVar15 < 4);
  cVar9 = '\0';
  iVar17 = 0;
  iVar10 = 0;
  for (; uVar18 != 0; uVar18 = uVar18 - 1) {
    uVar14 = *(undefined4 *)(this + iVar10 + 0x21);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = 0x61;
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)((uint)uVar14 >> 0x18);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)((uint)uVar14 >> 0x10);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)((uint)uVar14 >> 8);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)uVar14;
    uVar14 = *(undefined4 *)((int)(this + iVar10 + 0x21) + 4);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = 0x61;
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)((uint)uVar14 >> 0x18);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)((uint)uVar14 >> 0x10);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)((uint)uVar14 >> 8);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)uVar14;
    uVar14 = *(undefined4 *)(this + iVar17 + 0x80);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = 0x61;
    pbVar11 = (byte *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(pbVar11 + 1);
    *pbVar11 = (byte)((uint)uVar14 >> 0x18) | cVar9 + 0x10U;
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)((uint)uVar14 >> 0x10);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)((uint)uVar14 >> 8);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)uVar14;
    cVar9 = cVar9 + '\x01';
    iVar17 = iVar17 + 4;
    iVar10 = iVar10 + 8;
  }
  uVar18 = 0;
  iVar17 = 4;
  do {
    iVar10 = (uVar18 >> 2) + 0x7a;
    bVar1 = (&DAT_803ef9e1)[(uint)(byte)this[iVar10] * 4];
    bVar2 = (&J3DGraphBase::j3dTevSwapTableTable)[(uint)(byte)this[iVar10] * 4];
    JVar3 = this[0x77];
    JVar4 = this[0x73];
    JVar5 = this[0x76];
    JVar6 = this[0x72];
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = 0x61;
    uVar15 = (uint)(byte)JVar6 << 4 | (uint)bVar2 | (uint)bVar1 << 2;
    uVar12 = (uint)(byte)JVar4 << 0xe | (uint)(byte)JVar5 << 9 | uVar15;
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)((uint)((((int)uVar18 >> 1) + 0xf6) * 0x1000000) >> 0x18);
    pbVar11 = (byte *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(pbVar11 + 1);
    *pbVar11 = (byte)((((byte)JVar3 & 0x1f) << 0x13) >> 0x10) | (byte)(uVar12 >> 0x10);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)(uVar12 >> 8);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)uVar15;
    bVar1 = (&DAT_803ef9e3)[(uint)(byte)this[iVar10] * 4];
    bVar2 = (&DAT_803ef9e2)[(uint)(byte)this[iVar10] * 4];
    JVar3 = this[0x79];
    JVar4 = this[0x75];
    JVar5 = this[0x78];
    JVar6 = this[0x74];
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = 0x61;
    uVar15 = (uint)(byte)JVar6 << 4 | (uint)bVar2 | (uint)bVar1 << 2;
    uVar12 = (uint)(byte)JVar4 << 0xe | (uint)(byte)JVar5 << 9 | uVar15;
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)((uint)((((int)(uVar18 + 2) >> 1) + 0xf6) * 0x1000000) >> 0x18);
    pbVar11 = (byte *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(pbVar11 + 1);
    *pbVar11 = (byte)((((byte)JVar3 & 0x1f) << 0x13) >> 0x10) | (byte)(uVar12 >> 0x10);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)(uVar12 >> 8);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)uVar15;
    uVar18 = uVar18 + 4;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall J3DTevBlock16::load(void) */

void __thiscall J3DTevBlock16::load(J3DTevBlock16 *this)

{
  byte bVar1;
  byte bVar2;
  J3DTevBlock16 JVar3;
  J3DTevBlock16 JVar4;
  J3DTevBlock16 JVar5;
  J3DTevBlock16 JVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  J3DTevBlock16 *pJVar10;
  int iVar11;
  byte *pbVar12;
  undefined *puVar13;
  uint uVar14;
  undefined4 uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  J3DTevBlock16 *pJVar19;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  uVar18 = (uint)(byte)this[0x58];
  *(int *)(this + 4) = gd::__GDCurrentDL[2] - *gd::__GDCurrentDL;
  uVar16 = 0;
  iVar17 = 0;
  do {
    if (*(short *)(this + iVar17 + 8) != -1) {
      J3DGraphBase::loadTexNo(uVar16);
    }
    uVar16 = uVar16 + 1;
    iVar17 = iVar17 + 2;
  } while (uVar16 < 8);
  iVar17 = 0;
  for (uVar16 = 0; uVar16 < uVar18; uVar16 = uVar16 + 2) {
    pJVar19 = this + (uVar16 + 1) * 4;
    pJVar10 = this + iVar17;
    J3DGraphBase::J3DGDSetTevOrder
              (uVar16,pJVar10[0x18],pJVar10[0x19],pJVar10[0x1a],pJVar19[0x18],pJVar19[0x19],
               pJVar19[0x1a]);
    uVar14 = (byte)pJVar10[0x19] & 7;
    uVar7 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar14 * 4]);
    uVar8 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar14 * 4]);
    J3DGraphBase::J3DGDSetTexCoordScale2
              ((byte)pJVar10[0x18] & 7,*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar14 * 8),
               uVar7 >> 5 & 0xff,0,(&DAT_803edbca)[uVar14 * 4],uVar8 >> 5 & 0xff,0);
    uVar14 = (byte)pJVar19[0x19] & 7;
    uVar7 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar14 * 4]);
    uVar8 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar14 * 4]);
    J3DGraphBase::J3DGDSetTexCoordScale2
              ((byte)pJVar19[0x18] & 7,*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar14 * 8),
               uVar7 >> 5 & 0xff,0,(&DAT_803edbca)[uVar14 * 4],uVar8 >> 5 & 0xff,0);
    iVar17 = iVar17 + 8;
  }
  *(int *)(this + 0x170) = gd::__GDCurrentDL[2] - *gd::__GDCurrentDL;
  uVar16 = 0;
  iVar17 = 0;
  do {
    local_34 = *(undefined4 *)(this + iVar17 + 0xda);
    local_30 = *(undefined4 *)((int)(this + iVar17 + 0xda) + 4);
    J3DGraphBase::J3DGDSetTevColorS10(uVar16 + 1,&local_34);
    uVar16 = uVar16 + 1;
    iVar17 = iVar17 + 8;
  } while (uVar16 < 3);
  uVar16 = 0;
  iVar17 = 0;
  do {
    local_38 = *(undefined4 *)(this + iVar17 + 0xfa);
    J3DGraphBase::J3DGDSetTevKColor(uVar16,&local_38);
    uVar16 = uVar16 + 1;
    iVar17 = iVar17 + 4;
  } while (uVar16 < 4);
  cVar9 = '\0';
  iVar17 = 0;
  iVar11 = 0;
  for (; uVar18 != 0; uVar18 = uVar18 - 1) {
    uVar15 = *(undefined4 *)(this + iVar11 + 0x59);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = 0x61;
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)((uint)uVar15 >> 0x18);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)((uint)uVar15 >> 0x10);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)((uint)uVar15 >> 8);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)uVar15;
    uVar15 = *(undefined4 *)((int)(this + iVar11 + 0x59) + 4);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = 0x61;
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)((uint)uVar15 >> 0x18);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)((uint)uVar15 >> 0x10);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)((uint)uVar15 >> 8);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)uVar15;
    uVar15 = *(undefined4 *)(this + iVar17 + 0x130);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = 0x61;
    pbVar12 = (byte *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(pbVar12 + 1);
    *pbVar12 = (byte)((uint)uVar15 >> 0x18) | cVar9 + 0x10U;
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)((uint)uVar15 >> 0x10);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)((uint)uVar15 >> 8);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)uVar15;
    cVar9 = cVar9 + '\x01';
    iVar17 = iVar17 + 4;
    iVar11 = iVar11 + 8;
  }
  uVar18 = 0;
  iVar17 = 4;
  do {
    iVar11 = (uVar18 >> 2) + 0x12a;
    bVar1 = (&DAT_803ef9e1)[(uint)(byte)this[iVar11] * 4];
    bVar2 = (&J3DGraphBase::j3dTevSwapTableTable)[(uint)(byte)this[iVar11] * 4];
    pJVar10 = this + uVar18;
    JVar3 = pJVar10[0x11b];
    JVar4 = pJVar10[0x10b];
    JVar5 = pJVar10[0x11a];
    JVar6 = pJVar10[0x10a];
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = 0x61;
    uVar16 = (uint)(byte)JVar6 << 4 | (uint)bVar2 | (uint)bVar1 << 2;
    uVar14 = (uint)(byte)JVar4 << 0xe | (uint)(byte)JVar5 << 9 | uVar16;
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)((uint)((((int)uVar18 >> 1) + 0xf6) * 0x1000000) >> 0x18);
    pbVar12 = (byte *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(pbVar12 + 1);
    *pbVar12 = (byte)((((byte)JVar3 & 0x1f) << 0x13) >> 0x10) | (byte)(uVar14 >> 0x10);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)(uVar14 >> 8);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)uVar16;
    bVar1 = (&DAT_803ef9e3)[(uint)(byte)this[iVar11] * 4];
    bVar2 = (&DAT_803ef9e2)[(uint)(byte)this[iVar11] * 4];
    JVar3 = pJVar10[0x11d];
    JVar4 = pJVar10[0x10d];
    JVar5 = pJVar10[0x11c];
    JVar6 = pJVar10[0x10c];
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = 0x61;
    uVar16 = (uint)(byte)JVar6 << 4 | (uint)bVar2 | (uint)bVar1 << 2;
    uVar14 = (uint)(byte)JVar4 << 0xe | (uint)(byte)JVar5 << 9 | uVar16;
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)((uint)((((int)(uVar18 + 2) >> 1) + 0xf6) * 0x1000000) >> 0x18);
    pbVar12 = (byte *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(pbVar12 + 1);
    *pbVar12 = (byte)((((byte)JVar3 & 0x1f) << 0x13) >> 0x10) | (byte)(uVar14 >> 0x10);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)(uVar14 >> 8);
    puVar13 = (undefined *)gd::__GDCurrentDL[2];
    gd::__GDCurrentDL[2] = (int)(puVar13 + 1);
    *puVar13 = (char)uVar16;
    uVar18 = uVar18 + 4;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DTevBlockPatched::patchTexNo(void) */

void __thiscall J3DTevBlockPatched::patchTexNo(J3DTevBlockPatched *this)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + *(int *)&this->field_0x4;
  iVar2 = gd::__GDCurrentDL[2];
  uVar1 = 0;
  iVar3 = 0;
  do {
    if (*(short *)((int)this->mTexNo + iVar3) != -1) {
      J3DGraphBase::loadTexNo(uVar1);
    }
    uVar1 = uVar1 + 1;
    iVar3 = iVar3 + 2;
  } while (uVar1 < 8);
  os::DCFlushRange(iVar2,gd::__GDCurrentDL[2] - iVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DTevBlockPatched::patchTevReg(void) */

void __thiscall J3DTevBlockPatched::patchTevReg(J3DTevBlockPatched *this)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + this->mTevRegOffs;
  iVar3 = gd::__GDCurrentDL[2];
  uVar2 = 0;
  iVar4 = 0;
  do {
    puVar1 = (undefined4 *)((int)&this->mTevColor[0].r + iVar4);
    local_24 = *puVar1;
    local_20 = puVar1[1];
    J3DGraphBase::J3DGDSetTevColorS10(uVar2 + 1,&local_24);
    uVar2 = uVar2 + 1;
    iVar4 = iVar4 + 8;
  } while (uVar2 < 3);
  uVar2 = 0;
  iVar4 = 0;
  do {
    local_28 = *(undefined4 *)(&this->mTevKColor[0].r + iVar4);
    J3DGraphBase::J3DGDSetTevKColor(uVar2,&local_28);
    uVar2 = uVar2 + 1;
    iVar4 = iVar4 + 4;
  } while (uVar2 < 4);
  os::DCFlushRange(iVar3,gd::__GDCurrentDL[2] - iVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall J3DTevBlockPatched::patchTexNoAndTexCoordScale(void) */

void __thiscall J3DTevBlockPatched::patchTexNoAndTexCoordScale(J3DTevBlockPatched *this)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  ushort *puVar8;
  int iVar9;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + *(int *)&this->field_0x4;
  iVar9 = gd::__GDCurrentDL[2];
  bVar1 = this->mTevStageNum;
  uVar5 = 0;
  iVar7 = 0;
  do {
    if (*(short *)((int)this->mTexNo + iVar7) != -1) {
      J3DGraphBase::loadTexNo(uVar5);
    }
    uVar5 = uVar5 + 1;
    iVar7 = iVar7 + 2;
  } while (uVar5 < 8);
  iVar7 = 0;
  for (uVar5 = 0; uVar5 < bVar1; uVar5 = uVar5 + 2) {
    puVar8 = this->mTexNo + uVar5 * 2 + -2;
    iVar6 = (int)this->mTexNo + iVar7 + -8;
    J3DGraphBase::J3DGDSetTevOrder
              (uVar5,*(undefined *)(iVar6 + 0x18),*(undefined *)(iVar6 + 0x19),
               *(undefined *)(iVar6 + 0x1a),*(undefined *)(puVar8 + 0xc),
               *(undefined *)((int)puVar8 + 0x19),*(undefined *)(puVar8 + 0xd));
    uVar2 = *(byte *)(iVar6 + 0x19) & 7;
    uVar3 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar2 * 4]);
    uVar4 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar2 * 4]);
    J3DGraphBase::J3DGDSetTexCoordScale2
              (*(byte *)(iVar6 + 0x18) & 7,*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar2 * 8)
               ,uVar3 >> 5 & 0xff,0,(&DAT_803edbca)[uVar2 * 4],uVar4 >> 5 & 0xff,0);
    uVar2 = *(byte *)((int)puVar8 + 0x19) & 7;
    uVar3 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar2 * 4]);
    uVar4 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar2 * 4]);
    J3DGraphBase::J3DGDSetTexCoordScale2
              (*(byte *)(puVar8 + 0xc) & 7,*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar2 * 8)
               ,uVar3 >> 5 & 0xff,0,(&DAT_803edbca)[uVar2 * 4],uVar4 >> 5 & 0xff,0);
    iVar7 = iVar7 + 8;
  }
  os::DCFlushRange(iVar9,gd::__GDCurrentDL[2] - iVar9);
  return;
}


/* __thiscall J3DTevBlockPatched::patch(void) */

void __thiscall J3DTevBlockPatched::patch(J3DTevBlockPatched *this)

{
  (**(code **)(*(int *)this + 0x2c))();
  (**(code **)(*(int *)this + 0x30))(this);
  return;
}


/* __thiscall J3DTevBlock1::patchTexNo(void) */

void __thiscall J3DTevBlock1::patchTexNo(J3DTevBlock1 *this)

{
  int iVar1;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + *(int *)(this + 4);
  iVar1 = gd::__GDCurrentDL[2];
  if (*(short *)(this + 8) != -1) {
    J3DGraphBase::loadTexNo(0,this + 8);
  }
  os::DCFlushRange(iVar1,gd::__GDCurrentDL[2] - iVar1);
  return;
}


/* __thiscall J3DTevBlock1::patchTevReg(void) */

void __thiscall J3DTevBlock1::patchTevReg(J3DTevBlock1 *this)

{
  return;
}


/* __thiscall J3DTevBlock1::patchTexNoAndTexCoordScale(void) */

void __thiscall J3DTevBlock1::patchTexNoAndTexCoordScale(J3DTevBlock1 *this)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + *(int *)(this + 4);
  iVar4 = gd::__GDCurrentDL[2];
  if (*(short *)(this + 8) != -1) {
    J3DGraphBase::loadTexNo(0,this + 8);
  }
  J3DGraphBase::J3DGDSetTevOrder(0,this[10],this[0xb],this[0xc],0xff,0xff,0xff);
  uVar1 = (byte)this[0xb] & 7;
  uVar2 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar1 * 4]);
  uVar3 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar1 * 4]);
  J3DGraphBase::J3DGDSetTexCoordScale2
            (this[10],*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar1 * 8),uVar2 >> 5 & 0xff,0,
             (&DAT_803edbca)[uVar1 * 4],uVar3 >> 5 & 0xff,0);
  os::DCFlushRange(iVar4,gd::__GDCurrentDL[2] - iVar4);
  return;
}


/* __thiscall J3DTevBlock1::patch(void) */

void __thiscall J3DTevBlock1::patch(J3DTevBlock1 *this)

{
  (**(code **)(*(int *)this + 0x2c))();
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DTevBlock2::patchTexNo(void) */

void __thiscall J3DTevBlock2::patchTexNo(J3DTevBlock2 *this)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + *(int *)(this + 4);
  iVar2 = gd::__GDCurrentDL[2];
  uVar1 = 0;
  iVar3 = 0;
  do {
    if (*(short *)(this + iVar3 + 8) != -1) {
      J3DGraphBase::loadTexNo(uVar1);
    }
    uVar1 = uVar1 + 1;
    iVar3 = iVar3 + 2;
  } while (uVar1 < 2);
  os::DCFlushRange(iVar2,gd::__GDCurrentDL[2] - iVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DTevBlock2::patchTevReg(void) */

void __thiscall J3DTevBlock2::patchTevReg(J3DTevBlock2 *this)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + *(int *)(this + 0x68);
  iVar2 = gd::__GDCurrentDL[2];
  uVar1 = 0;
  iVar3 = 0;
  do {
    local_24 = *(undefined4 *)(this + iVar3 + 0x14);
    local_20 = *(undefined4 *)((int)(this + iVar3 + 0x14) + 4);
    J3DGraphBase::J3DGDSetTevColorS10(uVar1 + 1,&local_24);
    uVar1 = uVar1 + 1;
    iVar3 = iVar3 + 8;
  } while (uVar1 < 3);
  uVar1 = 0;
  iVar3 = 0;
  do {
    local_28 = *(undefined4 *)(this + iVar3 + 0x45);
    J3DGraphBase::J3DGDSetTevKColor(uVar1,&local_28);
    uVar1 = uVar1 + 1;
    iVar3 = iVar3 + 4;
  } while (uVar1 < 4);
  os::DCFlushRange(iVar2,gd::__GDCurrentDL[2] - iVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DTevBlock2::patchTexNoAndTexCoordScale(void) */

void __thiscall J3DTevBlock2::patchTexNoAndTexCoordScale(J3DTevBlock2 *this)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + *(int *)(this + 4);
  iVar5 = gd::__GDCurrentDL[2];
  uVar3 = 0;
  iVar4 = 0;
  do {
    if (*(short *)(this + iVar4 + 8) != -1) {
      J3DGraphBase::loadTexNo(uVar3);
    }
    uVar3 = uVar3 + 1;
    iVar4 = iVar4 + 2;
  } while (uVar3 < 2);
  J3DGraphBase::J3DGDSetTevOrder(0,this[0xc],this[0xd],this[0xe],this[0x10],this[0x11],this[0x12]);
  uVar3 = (byte)this[0xd] & 7;
  uVar1 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar3 * 4]);
  uVar2 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar3 * 4]);
  J3DGraphBase::J3DGDSetTexCoordScale2
            (this[0xc],*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar3 * 8),uVar1 >> 5 & 0xff,0
             ,(&DAT_803edbca)[uVar3 * 4],uVar2 >> 5 & 0xff,0);
  uVar3 = (byte)this[0x11] & 7;
  uVar1 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar3 * 4]);
  uVar2 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar3 * 4]);
  J3DGraphBase::J3DGDSetTexCoordScale2
            ((byte)this[0x10] & 7,*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar3 * 8),
             uVar1 >> 5 & 0xff,0,(&DAT_803edbca)[uVar3 * 4],uVar2 >> 5 & 0xff,0);
  os::DCFlushRange(iVar5,gd::__GDCurrentDL[2] - iVar5);
  return;
}


/* __thiscall J3DTevBlock2::patch(void) */

void __thiscall J3DTevBlock2::patch(J3DTevBlock2 *this)

{
  (**(code **)(*(int *)this + 0x2c))();
  (**(code **)(*(int *)this + 0x30))(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DTevBlock4::patchTexNo(void) */

void __thiscall J3DTevBlock4::patchTexNo(J3DTevBlock4 *this)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + *(int *)(this + 4);
  iVar2 = gd::__GDCurrentDL[2];
  uVar1 = 0;
  iVar3 = 0;
  do {
    if (*(short *)(this + iVar3 + 8) != -1) {
      J3DGraphBase::loadTexNo(uVar1);
    }
    uVar1 = uVar1 + 1;
    iVar3 = iVar3 + 2;
  } while (uVar1 < 4);
  os::DCFlushRange(iVar2,gd::__GDCurrentDL[2] - iVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DTevBlock4::patchTevReg(void) */

void __thiscall J3DTevBlock4::patchTevReg(J3DTevBlock4 *this)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + *(int *)(this + 0x90);
  iVar2 = gd::__GDCurrentDL[2];
  uVar1 = 0;
  iVar3 = 0;
  do {
    local_24 = *(undefined4 *)(this + iVar3 + 0x42);
    local_20 = *(undefined4 *)((int)(this + iVar3 + 0x42) + 4);
    J3DGraphBase::J3DGDSetTevColorS10(uVar1 + 1,&local_24);
    uVar1 = uVar1 + 1;
    iVar3 = iVar3 + 8;
  } while (uVar1 < 3);
  uVar1 = 0;
  iVar3 = 0;
  do {
    local_28 = *(undefined4 *)(this + iVar3 + 0x62);
    J3DGraphBase::J3DGDSetTevKColor(uVar1,&local_28);
    uVar1 = uVar1 + 1;
    iVar3 = iVar3 + 4;
  } while (uVar1 < 4);
  os::DCFlushRange(iVar2,gd::__GDCurrentDL[2] - iVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall J3DTevBlock4::patchTexNoAndTexCoordScale(void) */

void __thiscall J3DTevBlock4::patchTexNoAndTexCoordScale(J3DTevBlock4 *this)

{
  J3DTevBlock4 JVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  J3DTevBlock4 *pJVar6;
  int iVar7;
  J3DTevBlock4 *pJVar8;
  int iVar9;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + *(int *)(this + 4);
  iVar9 = gd::__GDCurrentDL[2];
  JVar1 = this[0x20];
  uVar5 = 0;
  iVar7 = 0;
  do {
    if (*(short *)(this + iVar7 + 8) != -1) {
      J3DGraphBase::loadTexNo(uVar5);
    }
    uVar5 = uVar5 + 1;
    iVar7 = iVar7 + 2;
  } while (uVar5 < 8);
  iVar7 = 0;
  for (uVar5 = 0; uVar5 < (byte)JVar1; uVar5 = uVar5 + 2) {
    pJVar8 = this + (uVar5 + 1) * 4;
    pJVar6 = this + iVar7;
    J3DGraphBase::J3DGDSetTevOrder
              (uVar5,pJVar6[0x10],pJVar6[0x11],pJVar6[0x12],pJVar8[0x10],pJVar8[0x11],pJVar8[0x12]);
    uVar2 = (byte)pJVar6[0x11] & 7;
    uVar3 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar2 * 4]);
    uVar4 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar2 * 4]);
    J3DGraphBase::J3DGDSetTexCoordScale2
              ((byte)pJVar6[0x10] & 7,*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar2 * 8),
               uVar3 >> 5 & 0xff,0,(&DAT_803edbca)[uVar2 * 4],uVar4 >> 5 & 0xff,0);
    uVar2 = (byte)pJVar8[0x11] & 7;
    uVar3 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar2 * 4]);
    uVar4 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar2 * 4]);
    J3DGraphBase::J3DGDSetTexCoordScale2
              ((byte)pJVar8[0x10] & 7,*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar2 * 8),
               uVar3 >> 5 & 0xff,0,(&DAT_803edbca)[uVar2 * 4],uVar4 >> 5 & 0xff,0);
    iVar7 = iVar7 + 8;
  }
  os::DCFlushRange(iVar9,gd::__GDCurrentDL[2] - iVar9);
  return;
}


/* __thiscall J3DTevBlock4::patch(void) */

void __thiscall J3DTevBlock4::patch(J3DTevBlock4 *this)

{
  (**(code **)(*(int *)this + 0x2c))();
  (**(code **)(*(int *)this + 0x30))(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DTevBlock16::patchTexNo(void) */

void __thiscall J3DTevBlock16::patchTexNo(J3DTevBlock16 *this)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + *(int *)(this + 4);
  iVar2 = gd::__GDCurrentDL[2];
  uVar1 = 0;
  iVar3 = 0;
  do {
    if (*(short *)(this + iVar3 + 8) != -1) {
      J3DGraphBase::loadTexNo(uVar1);
    }
    uVar1 = uVar1 + 1;
    iVar3 = iVar3 + 2;
  } while (uVar1 < 8);
  os::DCFlushRange(iVar2,gd::__GDCurrentDL[2] - iVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DTevBlock16::patchTevReg(void) */

void __thiscall J3DTevBlock16::patchTevReg(J3DTevBlock16 *this)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + *(int *)(this + 0x170);
  iVar2 = gd::__GDCurrentDL[2];
  uVar1 = 0;
  iVar3 = 0;
  do {
    local_24 = *(undefined4 *)(this + iVar3 + 0xda);
    local_20 = *(undefined4 *)((int)(this + iVar3 + 0xda) + 4);
    J3DGraphBase::J3DGDSetTevColorS10(uVar1 + 1,&local_24);
    uVar1 = uVar1 + 1;
    iVar3 = iVar3 + 8;
  } while (uVar1 < 3);
  uVar1 = 0;
  iVar3 = 0;
  do {
    local_28 = *(undefined4 *)(this + iVar3 + 0xfa);
    J3DGraphBase::J3DGDSetTevKColor(uVar1,&local_28);
    uVar1 = uVar1 + 1;
    iVar3 = iVar3 + 4;
  } while (uVar1 < 4);
  os::DCFlushRange(iVar2,gd::__GDCurrentDL[2] - iVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall J3DTevBlock16::patchTexNoAndTexCoordScale(void) */

void __thiscall J3DTevBlock16::patchTexNoAndTexCoordScale(J3DTevBlock16 *this)

{
  J3DTevBlock16 JVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  J3DTevBlock16 *pJVar6;
  int iVar7;
  J3DTevBlock16 *pJVar8;
  int iVar9;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + *(int *)(this + 4);
  iVar9 = gd::__GDCurrentDL[2];
  JVar1 = this[0x58];
  uVar5 = 0;
  iVar7 = 0;
  do {
    if (*(short *)(this + iVar7 + 8) != -1) {
      J3DGraphBase::loadTexNo(uVar5);
    }
    uVar5 = uVar5 + 1;
    iVar7 = iVar7 + 2;
  } while (uVar5 < 8);
  iVar7 = 0;
  for (uVar5 = 0; uVar5 < (byte)JVar1; uVar5 = uVar5 + 2) {
    pJVar8 = this + (uVar5 + 1) * 4;
    pJVar6 = this + iVar7;
    J3DGraphBase::J3DGDSetTevOrder
              (uVar5,pJVar6[0x18],pJVar6[0x19],pJVar6[0x1a],pJVar8[0x18],pJVar8[0x19],pJVar8[0x1a]);
    uVar2 = (byte)pJVar6[0x19] & 7;
    uVar3 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar2 * 4]);
    uVar4 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar2 * 4]);
    J3DGraphBase::J3DGDSetTexCoordScale2
              ((byte)pJVar6[0x18] & 7,*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar2 * 8),
               uVar3 >> 5 & 0xff,0,(&DAT_803edbca)[uVar2 * 4],uVar4 >> 5 & 0xff,0);
    uVar2 = (byte)pJVar8[0x19] & 7;
    uVar3 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar2 * 4]);
    uVar4 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar2 * 4]);
    J3DGraphBase::J3DGDSetTexCoordScale2
              ((byte)pJVar8[0x18] & 7,*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar2 * 8),
               uVar3 >> 5 & 0xff,0,(&DAT_803edbca)[uVar2 * 4],uVar4 >> 5 & 0xff,0);
    iVar7 = iVar7 + 8;
  }
  os::DCFlushRange(iVar9,gd::__GDCurrentDL[2] - iVar9);
  return;
}


/* __thiscall J3DTevBlock16::patch(void) */

void __thiscall J3DTevBlock16::patch(J3DTevBlock16 *this)

{
  (**(code **)(*(int *)this + 0x2c))();
  (**(code **)(*(int *)this + 0x30))(this);
  return;
}


/* __thiscall J3DTevBlock::diff(unsigned long) */

void __thiscall J3DTevBlock::diff(J3DTevBlock *this,ulong param_1)

{
  if ((param_1 >> 0x10 & 0xf) != 0) {
    (*(code *)this->vtbl->diffTexNo)();
  }
  if ((param_1 & 0x4000000) != 0) {
    (*(code *)this->vtbl->diffTexCoordScale)(this);
  }
  if ((param_1 >> 0x14 & 0xf) != 0) {
    (*(code *)this->vtbl->diffTevStage)(this);
    if ((param_1 & 0x8000000) != 0) {
      (*(code *)this->vtbl->diffTevStageIndirect)(this);
    }
  }
  if ((param_1 & 0x1000000) != 0) {
    (*(code *)this->vtbl->diffTevReg)(this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DTevBlockPatched::diffTexNo(void) */

void __thiscall J3DTevBlockPatched::diffTexNo(J3DTevBlockPatched *this)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = 0;
  do {
    if (*(short *)((int)this->mTexNo + iVar2) != -1) {
      J3DGraphBase::loadTexNo(uVar1);
    }
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 2;
  } while (uVar1 < 8);
  return;
}


/* __thiscall J3DTevBlockPatched::diffTevStage(void) */

void __thiscall J3DTevBlockPatched::diffTevStage(J3DTevBlockPatched *this)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  uVar1 = (uint)this->mTevStageNum;
  iVar2 = 0;
  if (uVar1 == 0) {
    return;
  }
  do {
    puVar5 = (undefined4 *)(&this->mTevStages[0].mTevStageIdx + iVar2);
    uVar4 = *puVar5;
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = 0x61;
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 0x18);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 0x10);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 8);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)uVar4;
    uVar4 = puVar5[1];
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = 0x61;
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 0x18);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 0x10);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 8);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)uVar4;
    iVar2 = iVar2 + 8;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return;
}


/* __thiscall J3DTevBlockPatched::diffTevStageIndirect(void) */

void __thiscall J3DTevBlockPatched::diffTevStageIndirect(J3DTevBlockPatched *this)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  byte *pbVar5;
  char cVar6;
  
  uVar1 = (uint)this->mTevStageNum;
  cVar6 = '\0';
  iVar2 = 0;
  if (uVar1 == 0) {
    return;
  }
  do {
    uVar3 = *(undefined4 *)((int)this->mIndStages + iVar2);
    puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
    *puVar4 = 0x61;
    pbVar5 = *(byte **)(gd::__GDCurrentDL + 8);
    *(byte **)(gd::__GDCurrentDL + 8) = pbVar5 + 1;
    *pbVar5 = (byte)((uint)uVar3 >> 0x18) | cVar6 + 0x10U;
    puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
    *puVar4 = (char)((uint)uVar3 >> 0x10);
    puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
    *puVar4 = (char)((uint)uVar3 >> 8);
    puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
    *puVar4 = (char)uVar3;
    cVar6 = cVar6 + '\x01';
    iVar2 = iVar2 + 4;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DTevBlockPatched::diffTevReg(void) */

void __thiscall J3DTevBlockPatched::diffTevReg(J3DTevBlockPatched *this)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  uVar2 = 0;
  iVar3 = 0;
  do {
    puVar1 = (undefined4 *)((int)&this->mTevColor[0].r + iVar3);
    local_24 = *puVar1;
    local_20 = puVar1[1];
    J3DGraphBase::J3DGDSetTevColorS10(uVar2 + 1,&local_24);
    uVar2 = uVar2 + 1;
    iVar3 = iVar3 + 8;
  } while (uVar2 < 3);
  uVar2 = 0;
  iVar3 = 0;
  do {
    local_28 = *(undefined4 *)(&this->mTevKColor[0].r + iVar3);
    J3DGraphBase::J3DGDSetTevKColor(uVar2,&local_28);
    uVar2 = uVar2 + 1;
    iVar3 = iVar3 + 4;
  } while (uVar2 < 4);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DTevBlockPatched::diffTexCoordScale(void) */

void __thiscall J3DTevBlockPatched::diffTexCoordScale(J3DTevBlockPatched *this)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  bVar1 = this->mTevStageNum;
  iVar6 = 0;
  for (uVar7 = 0; uVar7 < bVar1; uVar7 = uVar7 + 2) {
    iVar5 = (int)this->mTexNo + iVar6 + -8;
    uVar2 = *(byte *)(iVar5 + 0x19) & 7;
    uVar3 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar2 * 4]);
    uVar4 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar2 * 4]);
    J3DGraphBase::J3DGDSetTexCoordScale2
              (*(byte *)(iVar5 + 0x18) & 7,*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar2 * 8)
               ,uVar3 >> 5 & 0xff,0,(&DAT_803edbca)[uVar2 * 4],uVar4 >> 5 & 0xff,0);
    uVar2 = *(byte *)((int)(this->mTexNo + uVar7 * 2 + -2) + 0x19) & 7;
    uVar3 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar2 * 4]);
    uVar4 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar2 * 4]);
    J3DGraphBase::J3DGDSetTexCoordScale2
              (*(byte *)(this->mTexNo + uVar7 * 2 + -2 + 0xc) & 7,
               *(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar2 * 8),uVar3 >> 5 & 0xff,0,
               (&DAT_803edbca)[uVar2 * 4],uVar4 >> 5 & 0xff,0);
    iVar6 = iVar6 + 8;
  }
  return;
}


/* __thiscall J3DTevBlock1::diffTexNo(void) */

void __thiscall J3DTevBlock1::diffTexNo(J3DTevBlock1 *this)

{
  if (*(short *)(this + 8) != -1) {
    J3DGraphBase::loadTexNo(0,this + 8);
  }
  return;
}


/* __thiscall J3DTevBlock1::diffTevReg(void) */

void __thiscall J3DTevBlock1::diffTevReg(J3DTevBlock1 *this)

{
  return;
}


/* __thiscall J3DTevBlock1::diffTevStage(void) */

void __thiscall J3DTevBlock1::diffTevStage(J3DTevBlock1 *this)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(this + 0xe);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)((uint)uVar2 >> 0x18);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)((uint)uVar2 >> 0x10);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)((uint)uVar2 >> 8);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)uVar2;
  uVar2 = *(undefined4 *)(this + 0x12);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)((uint)uVar2 >> 0x18);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)((uint)uVar2 >> 0x10);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)((uint)uVar2 >> 8);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)uVar2;
  return;
}


/* __thiscall J3DTevBlock1::diffTevStageIndirect(void) */

void __thiscall J3DTevBlock1::diffTevStageIndirect(J3DTevBlock1 *this)

{
  undefined4 uVar1;
  undefined *puVar2;
  byte *pbVar3;
  
  uVar1 = *(undefined4 *)(this + 0x18);
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0x61;
  pbVar3 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar3 + 1;
  *pbVar3 = (byte)((uint)uVar1 >> 0x18) | 0x10;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)((uint)uVar1 >> 0x10);
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)((uint)uVar1 >> 8);
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)uVar1;
  return;
}


/* __thiscall J3DTevBlock1::diffTexCoordScale(void) */

void __thiscall J3DTevBlock1::diffTexCoordScale(J3DTevBlock1 *this)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = (byte)this[0xb] & 7;
  uVar2 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar1 * 4]);
  uVar3 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar1 * 4]);
  J3DGraphBase::J3DGDSetTexCoordScale2
            (this[10],*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar1 * 8),uVar2 >> 5 & 0xff,0,
             (&DAT_803edbca)[uVar1 * 4],uVar3 >> 5 & 0xff,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DTevBlock2::diffTexNo(void) */

void __thiscall J3DTevBlock2::diffTexNo(J3DTevBlock2 *this)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = 0;
  do {
    if (*(short *)(this + iVar2 + 8) != -1) {
      J3DGraphBase::loadTexNo(uVar1);
    }
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 2;
  } while (uVar1 < 2);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DTevBlock2::diffTevReg(void) */

void __thiscall J3DTevBlock2::diffTevReg(J3DTevBlock2 *this)

{
  uint uVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  uVar1 = 0;
  iVar2 = 0;
  do {
    local_24 = *(undefined4 *)(this + iVar2 + 0x14);
    local_20 = *(undefined4 *)((int)(this + iVar2 + 0x14) + 4);
    J3DGraphBase::J3DGDSetTevColorS10(uVar1 + 1,&local_24);
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 8;
  } while (uVar1 < 3);
  uVar1 = 0;
  iVar2 = 0;
  do {
    local_28 = *(undefined4 *)(this + iVar2 + 0x45);
    J3DGraphBase::J3DGDSetTevKColor(uVar1,&local_28);
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 4;
  } while (uVar1 < 4);
  return;
}


/* __thiscall J3DTevBlock2::diffTevStage(void) */

void __thiscall J3DTevBlock2::diffTevStage(J3DTevBlock2 *this)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  
  uVar1 = (uint)(byte)this[0x34];
  iVar2 = 0;
  if (uVar1 == 0) {
    return;
  }
  do {
    uVar4 = *(undefined4 *)(this + iVar2 + 0x35);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = 0x61;
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 0x18);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 0x10);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 8);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)uVar4;
    uVar4 = *(undefined4 *)((int)(this + iVar2 + 0x35) + 4);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = 0x61;
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 0x18);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 0x10);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 8);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)uVar4;
    iVar2 = iVar2 + 8;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return;
}


/* __thiscall J3DTevBlock2::diffTevStageIndirect(void) */

void __thiscall J3DTevBlock2::diffTevStageIndirect(J3DTevBlock2 *this)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  byte *pbVar5;
  char cVar6;
  
  uVar1 = (uint)(byte)this[0x34];
  cVar6 = '\0';
  iVar2 = 0;
  if (uVar1 == 0) {
    return;
  }
  do {
    uVar3 = *(undefined4 *)(this + iVar2 + 0x60);
    puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
    *puVar4 = 0x61;
    pbVar5 = *(byte **)(gd::__GDCurrentDL + 8);
    *(byte **)(gd::__GDCurrentDL + 8) = pbVar5 + 1;
    *pbVar5 = (byte)((uint)uVar3 >> 0x18) | cVar6 + 0x10U;
    puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
    *puVar4 = (char)((uint)uVar3 >> 0x10);
    puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
    *puVar4 = (char)((uint)uVar3 >> 8);
    puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
    *puVar4 = (char)uVar3;
    cVar6 = cVar6 + '\x01';
    iVar2 = iVar2 + 4;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return;
}


/* __thiscall J3DTevBlock2::diffTexCoordScale(void) */

void __thiscall J3DTevBlock2::diffTexCoordScale(J3DTevBlock2 *this)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = (byte)this[0xd] & 7;
  uVar2 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar1 * 4]);
  uVar3 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar1 * 4]);
  J3DGraphBase::J3DGDSetTexCoordScale2
            (this[0xc],*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar1 * 8),uVar2 >> 5 & 0xff,0
             ,(&DAT_803edbca)[uVar1 * 4],uVar3 >> 5 & 0xff,0);
  uVar1 = (byte)this[0x11] & 7;
  uVar2 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar1 * 4]);
  uVar3 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar1 * 4]);
  J3DGraphBase::J3DGDSetTexCoordScale2
            ((byte)this[0x10] & 7,*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar1 * 8),
             uVar2 >> 5 & 0xff,0,(&DAT_803edbca)[uVar1 * 4],uVar3 >> 5 & 0xff,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DTevBlock4::diffTexNo(void) */

void __thiscall J3DTevBlock4::diffTexNo(J3DTevBlock4 *this)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = 0;
  do {
    if (*(short *)(this + iVar2 + 8) != -1) {
      J3DGraphBase::loadTexNo(uVar1);
    }
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 2;
  } while (uVar1 < 4);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DTevBlock4::diffTevReg(void) */

void __thiscall J3DTevBlock4::diffTevReg(J3DTevBlock4 *this)

{
  uint uVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  uVar1 = 0;
  iVar2 = 0;
  do {
    local_24 = *(undefined4 *)(this + iVar2 + 0x42);
    local_20 = *(undefined4 *)((int)(this + iVar2 + 0x42) + 4);
    J3DGraphBase::J3DGDSetTevColorS10(uVar1 + 1,&local_24);
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 8;
  } while (uVar1 < 3);
  uVar1 = 0;
  iVar2 = 0;
  do {
    local_28 = *(undefined4 *)(this + iVar2 + 0x62);
    J3DGraphBase::J3DGDSetTevKColor(uVar1,&local_28);
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 4;
  } while (uVar1 < 4);
  return;
}


/* __thiscall J3DTevBlock4::diffTevStage(void) */

void __thiscall J3DTevBlock4::diffTevStage(J3DTevBlock4 *this)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  
  uVar1 = (uint)(byte)this[0x20];
  iVar2 = 0;
  if (uVar1 == 0) {
    return;
  }
  do {
    uVar4 = *(undefined4 *)(this + iVar2 + 0x21);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = 0x61;
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 0x18);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 0x10);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 8);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)uVar4;
    uVar4 = *(undefined4 *)((int)(this + iVar2 + 0x21) + 4);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = 0x61;
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 0x18);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 0x10);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 8);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)uVar4;
    iVar2 = iVar2 + 8;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return;
}


/* __thiscall J3DTevBlock4::diffTevStageIndirect(void) */

void __thiscall J3DTevBlock4::diffTevStageIndirect(J3DTevBlock4 *this)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  byte *pbVar5;
  char cVar6;
  
  uVar1 = (uint)(byte)this[0x20];
  cVar6 = '\0';
  iVar2 = 0;
  if (uVar1 == 0) {
    return;
  }
  do {
    uVar3 = *(undefined4 *)(this + iVar2 + 0x80);
    puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
    *puVar4 = 0x61;
    pbVar5 = *(byte **)(gd::__GDCurrentDL + 8);
    *(byte **)(gd::__GDCurrentDL + 8) = pbVar5 + 1;
    *pbVar5 = (byte)((uint)uVar3 >> 0x18) | cVar6 + 0x10U;
    puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
    *puVar4 = (char)((uint)uVar3 >> 0x10);
    puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
    *puVar4 = (char)((uint)uVar3 >> 8);
    puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
    *puVar4 = (char)uVar3;
    cVar6 = cVar6 + '\x01';
    iVar2 = iVar2 + 4;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DTevBlock4::diffTexCoordScale(void) */

void __thiscall J3DTevBlock4::diffTexCoordScale(J3DTevBlock4 *this)

{
  J3DTevBlock4 JVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  JVar1 = this[0x20];
  iVar5 = 0;
  for (uVar6 = 0; uVar6 < (byte)JVar1; uVar6 = uVar6 + 2) {
    uVar2 = (byte)(this + iVar5)[0x11] & 7;
    uVar3 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar2 * 4]);
    uVar4 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar2 * 4]);
    J3DGraphBase::J3DGDSetTexCoordScale2
              ((byte)(this + iVar5)[0x10] & 7,
               *(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar2 * 8),uVar3 >> 5 & 0xff,0,
               (&DAT_803edbca)[uVar2 * 4],uVar4 >> 5 & 0xff,0);
    uVar2 = (byte)(this + (uVar6 + 1) * 4)[0x11] & 7;
    uVar3 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar2 * 4]);
    uVar4 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar2 * 4]);
    J3DGraphBase::J3DGDSetTexCoordScale2
              ((byte)(this + (uVar6 + 1) * 4)[0x10] & 7,
               *(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar2 * 8),uVar3 >> 5 & 0xff,0,
               (&DAT_803edbca)[uVar2 * 4],uVar4 >> 5 & 0xff,0);
    iVar5 = iVar5 + 8;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DTevBlock16::diffTexNo(void) */

void __thiscall J3DTevBlock16::diffTexNo(J3DTevBlock16 *this)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = 0;
  do {
    if (*(short *)(this + iVar2 + 8) != -1) {
      J3DGraphBase::loadTexNo(uVar1);
    }
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 2;
  } while (uVar1 < 8);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DTevBlock16::diffTevReg(void) */

void __thiscall J3DTevBlock16::diffTevReg(J3DTevBlock16 *this)

{
  uint uVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  uVar1 = 0;
  iVar2 = 0;
  do {
    local_24 = *(undefined4 *)(this + iVar2 + 0xda);
    local_20 = *(undefined4 *)((int)(this + iVar2 + 0xda) + 4);
    J3DGraphBase::J3DGDSetTevColorS10(uVar1 + 1,&local_24);
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 8;
  } while (uVar1 < 3);
  uVar1 = 0;
  iVar2 = 0;
  do {
    local_28 = *(undefined4 *)(this + iVar2 + 0xfa);
    J3DGraphBase::J3DGDSetTevKColor(uVar1,&local_28);
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 4;
  } while (uVar1 < 4);
  return;
}


/* __thiscall J3DTevBlock16::diffTevStage(void) */

void __thiscall J3DTevBlock16::diffTevStage(J3DTevBlock16 *this)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  
  uVar1 = (uint)(byte)this[0x58];
  iVar2 = 0;
  if (uVar1 == 0) {
    return;
  }
  do {
    uVar4 = *(undefined4 *)(this + iVar2 + 0x59);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = 0x61;
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 0x18);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 0x10);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 8);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)uVar4;
    uVar4 = *(undefined4 *)((int)(this + iVar2 + 0x59) + 4);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = 0x61;
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 0x18);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 0x10);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar4 >> 8);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)uVar4;
    iVar2 = iVar2 + 8;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return;
}


/* __thiscall J3DTevBlock16::diffTevStageIndirect(void) */

void __thiscall J3DTevBlock16::diffTevStageIndirect(J3DTevBlock16 *this)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  byte *pbVar5;
  char cVar6;
  
  uVar1 = (uint)(byte)this[0x58];
  cVar6 = '\0';
  iVar2 = 0;
  if (uVar1 == 0) {
    return;
  }
  do {
    uVar3 = *(undefined4 *)(this + iVar2 + 0x130);
    puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
    *puVar4 = 0x61;
    pbVar5 = *(byte **)(gd::__GDCurrentDL + 8);
    *(byte **)(gd::__GDCurrentDL + 8) = pbVar5 + 1;
    *pbVar5 = (byte)((uint)uVar3 >> 0x18) | cVar6 + 0x10U;
    puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
    *puVar4 = (char)((uint)uVar3 >> 0x10);
    puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
    *puVar4 = (char)((uint)uVar3 >> 8);
    puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
    *puVar4 = (char)uVar3;
    cVar6 = cVar6 + '\x01';
    iVar2 = iVar2 + 4;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DTevBlock16::diffTexCoordScale(void) */

void __thiscall J3DTevBlock16::diffTexCoordScale(J3DTevBlock16 *this)

{
  J3DTevBlock16 JVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  JVar1 = this[0x58];
  iVar5 = 0;
  for (uVar6 = 0; uVar6 < (byte)JVar1; uVar6 = uVar6 + 2) {
    uVar2 = (byte)(this + iVar5)[0x19] & 7;
    uVar3 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar2 * 4]);
    uVar4 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar2 * 4]);
    J3DGraphBase::J3DGDSetTexCoordScale2
              ((byte)(this + iVar5)[0x18] & 7,
               *(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar2 * 8),uVar3 >> 5 & 0xff,0,
               (&DAT_803edbca)[uVar2 * 4],uVar4 >> 5 & 0xff,0);
    uVar2 = (byte)(this + (uVar6 + 1) * 4)[0x19] & 7;
    uVar3 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar2 * 4]);
    uVar4 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar2 * 4]);
    J3DGraphBase::J3DGDSetTexCoordScale2
              ((byte)(this + (uVar6 + 1) * 4)[0x18] & 7,
               *(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar2 * 8),uVar3 >> 5 & 0xff,0,
               (&DAT_803edbca)[uVar2 * 4],uVar4 >> 5 & 0xff,0);
    iVar5 = iVar5 + 8;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall J3DTevBlock16::ptrToIndex(void) */

void __thiscall J3DTevBlock16::ptrToIndex(J3DTevBlock16 *this)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + *(int *)(this + 4);
  iVar2 = gd::__GDCurrentDL[2];
  uVar4 = 0;
  iVar3 = 0;
  iVar5 = 0;
  do {
    puVar1 = (ushort *)(this + iVar3 + 8);
    iVar6 = iVar5;
    if (*puVar1 != 0xffff) {
      gd::__GDCurrentDL[2] = *(int *)(this + 4) + iVar5 + *gd::__GDCurrentDL;
      J3DGraphBase::patchTexNo_PtrToIdx(uVar4,puVar1);
      iVar6 = iVar5 + 0x14;
      if ((J3DGraphBase::j3dSys.mpCurTex)->mpTexData[*puVar1].mbHasTlut == 1) {
        iVar6 = iVar5 + 0x37;
      }
    }
    uVar4 = uVar4 + 1;
    iVar3 = iVar3 + 2;
    iVar5 = iVar6;
  } while (uVar4 < 8);
  os::DCFlushRange(iVar2,gd::__GDCurrentDL[2] - iVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall J3DTevBlockPatched::ptrToIndex(void) */

void __thiscall J3DTevBlockPatched::ptrToIndex(J3DTevBlockPatched *this)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + *(int *)&this->field_0x4;
  iVar2 = gd::__GDCurrentDL[2];
  uVar4 = 0;
  iVar3 = 0;
  iVar5 = 0;
  do {
    puVar1 = (ushort *)((int)this->mTexNo + iVar3);
    iVar6 = iVar5;
    if (*puVar1 != 0xffff) {
      gd::__GDCurrentDL[2] = *(int *)&this->field_0x4 + iVar5 + *gd::__GDCurrentDL;
      J3DGraphBase::patchTexNo_PtrToIdx(uVar4,puVar1);
      iVar6 = iVar5 + 0x14;
      if ((J3DGraphBase::j3dSys.mpCurTex)->mpTexData[*puVar1].mbHasTlut == 1) {
        iVar6 = iVar5 + 0x37;
      }
    }
    uVar4 = uVar4 + 1;
    iVar3 = iVar3 + 2;
    iVar5 = iVar6;
  } while (uVar4 < 8);
  os::DCFlushRange(iVar2,gd::__GDCurrentDL[2] - iVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DTevBlock::indexToPtr_private(unsigned long) */

void __thiscall J3DTevBlock::indexToPtr_private(J3DTevBlock *this,ulong param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 local_18 [6];
  
  gd::__GDCurrentDL[2] = *gd::__GDCurrentDL + param_1;
  iVar4 = gd::__GDCurrentDL[2];
  iVar2 = 0;
  while( true ) {
    iVar3 = gd::__GDCurrentDL[2];
    cVar1 = J3DGraphBase::isTexNoReg(iVar3);
    if (cVar1 == '\0') break;
    local_18[0] = J3DGraphBase::getTexNoReg(iVar3);
    J3DGraphBase::loadTexNo(iVar2,local_18);
    iVar2 = iVar2 + 1;
  }
  os::DCFlushRange(iVar4,gd::__GDCurrentDL[2] - iVar4);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DIndBlockFull::load(void) */

void __thiscall J3DIndBlockFull::load(J3DIndBlockFull *this)

{
  uint uVar1;
  uint uVar2;
  J3DIndBlockFull *pJVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = (uint)(byte)this[4];
  iVar5 = 0;
  for (uVar4 = 0; uVar4 < uVar6; uVar4 = uVar4 + 1) {
    J3DGraphBase::J3DGDSetIndTexMtx(uVar4 + 1,this + iVar5 + 0x18,(int)(char)(this + iVar5)[0x30]);
    iVar5 = iVar5 + 0x1c;
  }
  iVar5 = 0;
  for (uVar4 = 0; uVar4 < uVar6; uVar4 = uVar4 + 2) {
    pJVar3 = this + iVar5;
    J3DGraphBase::J3DGDSetIndTexCoordScale
              (uVar4,pJVar3[0x6c],pJVar3[0x6d],pJVar3[0x70],pJVar3[0x71]);
    iVar5 = iVar5 + 8;
  }
  uVar4 = (byte)this[6] & 7;
  uVar1 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar4 * 4]);
  uVar2 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar4 * 4]);
  J3DGraphBase::J3DGDSetTexCoordScale2
            (this[5],*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar4 * 8),uVar1 >> 5 & 0xff,0,
             (&DAT_803edbca)[uVar4 * 4],uVar2 >> 5 & 0xff,0);
  uVar4 = (byte)this[10] & 7;
  uVar1 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar4 * 4]);
  uVar2 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar4 * 4]);
  J3DGraphBase::J3DGDSetTexCoordScale2
            (this[9],*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar4 * 8),uVar1 >> 5 & 0xff,0,
             (&DAT_803edbca)[uVar4 * 4],uVar2 >> 5 & 0xff,0);
  uVar4 = (byte)this[0xe] & 7;
  uVar1 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar4 * 4]);
  uVar2 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar4 * 4]);
  J3DGraphBase::J3DGDSetTexCoordScale2
            (this[0xd],*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar4 * 8),uVar1 >> 5 & 0xff,0
             ,(&DAT_803edbca)[uVar4 * 4],uVar2 >> 5 & 0xff,0);
  uVar4 = (byte)this[0x12] & 7;
  uVar1 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar4 * 4]);
  uVar2 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar4 * 4]);
  J3DGraphBase::J3DGDSetTexCoordScale2
            (this[0x11],*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar4 * 8),uVar1 >> 5 & 0xff,
             0,(&DAT_803edbca)[uVar4 * 4],uVar2 >> 5 & 0xff,0);
  J3DGraphBase::J3DGDSetIndTexOrder
            (uVar6,this[5],this[6],this[9],this[10],this[0xd],this[0xe],this[0x11],this[0x12]);
  return;
}


/* __thiscall J3DIndBlockFull::diff(unsigned long) */

void __thiscall J3DIndBlockFull::diff(J3DIndBlockFull *this,ulong param_1)

{
  J3DIndBlockFull JVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_1 & 0x8000000) != 0) {
    JVar1 = this[4];
    J3DGraphBase::J3DGDSetIndTexStageNum();
    J3DGraphBase::J3DGDSetIndTexMtx(1,this + 0x18,(int)(char)this[0x30]);
    J3DGraphBase::J3DGDSetIndTexCoordScale(0,this[0x6c],this[0x6d],this[0x70],this[0x71]);
    uVar2 = (byte)this[6] & 7;
    uVar3 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbcc)[uVar2 * 4]);
    uVar4 = countLeadingZeros(1 - (uint)(ushort)(&DAT_803edbce)[uVar2 * 4]);
    J3DGraphBase::J3DGDSetTexCoordScale2
              (this[5],*(undefined2 *)(&J3DSys::sTexCoordScaleTable + uVar2 * 8),uVar3 >> 5 & 0xff,0
               ,(&DAT_803edbca)[uVar2 * 4],uVar4 >> 5 & 0xff,0);
    J3DGraphBase::J3DGDSetIndTexOrder
              (JVar1,this[5],this[6],this[9],this[10],this[0xd],this[0xe],this[0x11],this[0x12]);
  }
  return;
}


/* __thiscall J3DPEBlockOpa::load(void) */

void __thiscall J3DPEBlockOpa::load(J3DPEBlockOpa *this)

{
  undefined *puVar1;
  
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 0x1eU) {
    gd::GDOverflowed();
  }
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0xf3;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x3f;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0xfe;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x1f;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0xe3;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x41;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x31;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x40;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x17;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0xfe;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x40;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x43;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x40;
  return;
}


/* __thiscall J3DPEBlockTexEdge::load(void) */

void __thiscall J3DPEBlockTexEdge::load(J3DPEBlockTexEdge *this)

{
  undefined *puVar1;
  
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 0x1eU) {
    gd::GDOverflowed();
  }
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0xf3;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x1e;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0xff;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x80;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0xfe;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x1f;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0xe3;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x41;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x31;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x40;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x17;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0xfe;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x40;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x43;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  return;
}


/* __thiscall J3DPEBlockXlu::load(void) */

void __thiscall J3DPEBlockXlu::load(J3DPEBlockXlu *this)

{
  undefined *puVar1;
  
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 0x1eU) {
    gd::GDOverflowed();
  }
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0xf3;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x3f;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0xfe;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x1f;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0xe3;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x41;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x34;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0xa1;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x40;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 7;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0xfe;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x40;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x43;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x40;
  return;
}


/* __thiscall J3DPEBlockFogOff::load(void) */

void __thiscall J3DPEBlockFogOff::load(J3DPEBlockFogOff *this)

{
  J3DPEBlockFogOff JVar1;
  byte bVar2;
  J3DPEBlockFogOff JVar3;
  J3DPEBlockFogOff JVar4;
  J3DPEBlockFogOff JVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  undefined *puVar10;
  byte *pbVar11;
  J3DPEBlockFogOff *pJVar12;
  uint uVar13;
  
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 0x1eU) {
    gd::GDOverflowed();
  }
  JVar1 = this[7];
  iVar7 = (uint)*(ushort *)(this + 4) * 3;
  bVar9 = (&DAT_803efde2)[iVar7];
  bVar2 = (&DAT_803efde1)[iVar7];
  JVar3 = this[6];
  bVar6 = (&J3DGraphBase::j3dAlphaCmpTable)[iVar7];
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x61;
  uVar8 = (uint)bVar2 << 0x16 | (uint)bVar9 << 0x13 | (uint)bVar6 << 0x10;
  pbVar11 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar11 + 1;
  *pbVar11 = (byte)(uVar8 >> 0x18) | 0xf3;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = (char)(uVar8 >> 0x10);
  pJVar12 = *(J3DPEBlockFogOff **)(gd::__GDCurrentDL + 8);
  *(J3DPEBlockFogOff **)(gd::__GDCurrentDL + 8) = pJVar12 + 1;
  *pJVar12 = JVar1;
  pJVar12 = *(J3DPEBlockFogOff **)(gd::__GDCurrentDL + 8);
  *(J3DPEBlockFogOff **)(gd::__GDCurrentDL + 8) = pJVar12 + 1;
  *pJVar12 = JVar3;
  JVar1 = this[0xf];
  JVar3 = this[0xb];
  JVar4 = this[10];
  JVar5 = this[9];
  uVar13 = (uint)(byte)this[8];
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x61;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0xfe;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x1f;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0xe7;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x61;
  uVar8 = countLeadingZeros(3 - uVar13);
  iVar7 = (uVar8 & 0x1fe0) << 6;
  uVar8 = countLeadingZeros(2 - uVar13);
  uVar8 = uVar8 >> 4 & 0x1fe;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x41;
  pbVar11 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar11 + 1;
  *pbVar11 = (byte)(((uint)(byte)JVar3 << 0xc) >> 0x10) | (byte)((uint)iVar7 >> 0x10);
  pbVar11 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar11 + 1;
  *pbVar11 = (byte)(((uint)(byte)JVar3 << 0xc) >> 8) |
             (byte)((uint)iVar7 >> 8) |
             (byte)JVar5 |
             (byte)(((uint)(byte)JVar4 << 5) >> 8) |
             (byte)(((uint)(byte)JVar1 << 2) >> 8) | (byte)(uVar8 >> 8);
  bVar9 = 0;
  if ((uVar13 == 1) || (uVar13 == 3)) {
    bVar9 = 1;
  }
  pbVar11 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar11 + 1;
  *pbVar11 = (byte)((uint)(byte)JVar4 << 5) | (byte)((uint)(byte)JVar1 << 2) | (byte)uVar8 | bVar9;
  iVar7 = (uint)*(ushort *)(this + 0xc) * 3;
  bVar9 = (&DAT_803f00e2)[iVar7];
  bVar2 = (&DAT_803f00e1)[iVar7];
  bVar6 = (&J3DGraphBase::j3dZModeTable)[iVar7];
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x61;
  uVar8 = (uint)bVar9 << 4 | (uint)bVar6 | (uint)bVar2 << 1;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x40;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = (char)(uVar8 >> 8);
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = (char)uVar8;
  JVar1 = this[0xe];
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x61;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0xfe;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x40;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x61;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x43;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = (char)(((uint)(byte)JVar1 << 6) >> 8);
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = (char)((uint)(byte)JVar1 << 6);
  return;
}


/* __thiscall J3DPEBlockFogOff::diffBlend(void) */

void __thiscall J3DPEBlockFogOff::diffBlend(J3DPEBlockFogOff *this)

{
  J3DPEBlockFogOff JVar1;
  J3DPEBlockFogOff JVar2;
  J3DPEBlockFogOff JVar3;
  J3DPEBlockFogOff JVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  undefined *puVar10;
  int iVar11;
  byte *pbVar12;
  
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 0xfU) {
    gd::GDOverflowed();
  }
  JVar1 = this[0xf];
  JVar2 = this[0xb];
  JVar3 = this[10];
  JVar4 = this[9];
  uVar8 = (uint)(byte)this[8];
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x61;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0xfe;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x1f;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0xe7;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x61;
  uVar9 = countLeadingZeros(3 - uVar8);
  iVar11 = (uVar9 & 0x1fe0) << 6;
  uVar9 = countLeadingZeros(2 - uVar8);
  uVar9 = uVar9 >> 4 & 0x1fe;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x41;
  pbVar12 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar12 + 1;
  *pbVar12 = (byte)(((uint)(byte)JVar2 << 0xc) >> 0x10) | (byte)((uint)iVar11 >> 0x10);
  pbVar12 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar12 + 1;
  *pbVar12 = (byte)(((uint)(byte)JVar2 << 0xc) >> 8) |
             (byte)((uint)iVar11 >> 8) |
             (byte)JVar4 |
             (byte)(((uint)(byte)JVar3 << 5) >> 8) |
             (byte)(((uint)(byte)JVar1 << 2) >> 8) | (byte)(uVar9 >> 8);
  bVar7 = 0;
  if ((uVar8 == 1) || (uVar8 == 3)) {
    bVar7 = 1;
  }
  pbVar12 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar12 + 1;
  *pbVar12 = (byte)((uint)(byte)JVar3 << 5) | (byte)((uint)(byte)JVar1 << 2) | (byte)uVar9 | bVar7;
  iVar11 = (uint)*(ushort *)(this + 0xc) * 3;
  bVar7 = (&DAT_803f00e2)[iVar11];
  bVar5 = (&DAT_803f00e1)[iVar11];
  bVar6 = (&J3DGraphBase::j3dZModeTable)[iVar11];
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x61;
  uVar9 = (uint)bVar7 << 4 | (uint)bVar6 | (uint)bVar5 << 1;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x40;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = (char)(uVar9 >> 8);
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = (char)uVar9;
  return;
}


/* __thiscall J3DPEBlockFull::load(void) */

void __thiscall J3DPEBlockFull::load(J3DPEBlockFull *this)

{
  undefined uVar1;
  byte bVar2;
  undefined uVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  byte bVar10;
  undefined *puVar11;
  byte *pbVar12;
  uint uVar13;
  int iVar14;
  J3DFog *pFog;
  _GXColor local_18;
  
  this[1].vtbl = (undefined *)(gd::__GDCurrentDL[2] - *gd::__GDCurrentDL);
  if ((uint)gd::__GDCurrentDL[3] < gd::__GDCurrentDL[2] + 0x55U) {
    gd::GDOverflowed();
  }
  pFog = this->mpFog;
  if (pFog != (J3DFog *)0x0) {
    local_18 = pFog->mColor;
    J3DGraphBase::J3DGDSetFog
              ((double)pFog->mStartZ,(double)pFog->mEndZ,(double)pFog->mNearZ,(double)pFog->mFarZ,
               pFog->mType,&local_18);
    J3DGraphBase::J3DGDSetFogRangeAdj(pFog->mAdjEnable,pFog->mCenter,pFog->mFogAdjTable);
  }
  uVar1 = *(undefined *)((int)&this->mAlphaComp + 3);
  iVar8 = (uint)*(ushort *)&this->mAlphaComp * 3;
  bVar10 = (&DAT_803efde2)[iVar8];
  bVar2 = (&DAT_803efde1)[iVar8];
  uVar3 = *(undefined *)((int)&this->mAlphaComp + 2);
  bVar5 = (&J3DGraphBase::j3dAlphaCmpTable)[iVar8];
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = 0x61;
  uVar9 = (uint)bVar2 << 0x16 | (uint)bVar10 << 0x13 | (uint)bVar5 << 0x10;
  pbVar12 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar12 + 1);
  *pbVar12 = (byte)(uVar9 >> 0x18) | 0xf3;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = (char)(uVar9 >> 0x10);
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = uVar1;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = uVar3;
  bVar10 = this->mDither;
  bVar2 = (this->mBlend).field_0x3;
  bVar5 = (this->mBlend).field_0x2;
  bVar4 = (this->mBlend).field_0x1;
  uVar13 = (uint)(this->mBlend).field_0x0;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = 0x61;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = 0xfe;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = 0;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = 0x1f;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = 0xe7;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = 0x61;
  iVar8 = (uint)bVar2 << 0xc;
  uVar9 = countLeadingZeros(3 - uVar13);
  iVar14 = (uVar9 & 0x1fe0) << 6;
  iVar6 = (uint)bVar5 << 5;
  iVar7 = (uint)bVar10 << 2;
  uVar9 = countLeadingZeros(2 - uVar13);
  uVar9 = uVar9 >> 4 & 0x1fe;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = 0x41;
  pbVar12 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar12 + 1);
  *pbVar12 = (byte)((uint)iVar8 >> 0x10) | (byte)((uint)iVar14 >> 0x10);
  pbVar12 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar12 + 1);
  *pbVar12 = (byte)((uint)iVar8 >> 8) |
             (byte)((uint)iVar14 >> 8) |
             bVar4 | (byte)((uint)iVar6 >> 8) | (byte)((uint)iVar7 >> 8) | (byte)(uVar9 >> 8);
  bVar10 = 0;
  if ((uVar13 == 1) || (uVar13 == 3)) {
    bVar10 = 1;
  }
  pbVar12 = (byte *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(pbVar12 + 1);
  *pbVar12 = (byte)iVar6 | (byte)iVar7 | (byte)uVar9 | bVar10;
  iVar8 = (uint)(ushort)this->mZMode * 3;
  bVar10 = (&DAT_803f00e2)[iVar8];
  bVar2 = (&DAT_803f00e1)[iVar8];
  bVar5 = (&J3DGraphBase::j3dZModeTable)[iVar8];
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = 0x61;
  uVar9 = (uint)bVar10 << 4 | (uint)bVar5 | (uint)bVar2 << 1;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = 0x40;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = 0;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = (char)(uVar9 >> 8);
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = (char)uVar9;
  bVar10 = this->mZCompLoc;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = 0x61;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = 0xfe;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = 0;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = 0;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = 0x40;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = 0x61;
  iVar8 = (uint)bVar10 << 6;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = 0x43;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = 0;
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = (char)((uint)iVar8 >> 8);
  puVar11 = (undefined *)gd::__GDCurrentDL[2];
  gd::__GDCurrentDL[2] = (int)(puVar11 + 1);
  *puVar11 = (char)iVar8;
  return;
}


/* __thiscall J3DPEBlockFull::patch(void) */

void __thiscall J3DPEBlockFull::patch(J3DPEBlockFull *this)

{
  J3DFog *pJVar1;
  int iVar2;
  _GXColor local_18 [4];
  
  gd::__GDCurrentDL[2] = (int)(this[1].vtbl + *gd::__GDCurrentDL);
  if ((uint)gd::__GDCurrentDL[3] < gd::__GDCurrentDL[2] + 0x37U) {
    gd::GDOverflowed();
  }
  iVar2 = gd::__GDCurrentDL[2];
  pJVar1 = this->mpFog;
  if (pJVar1 != (J3DFog *)0x0) {
    local_18[0] = pJVar1->mColor;
    J3DGraphBase::J3DGDSetFog
              ((double)pJVar1->mStartZ,(double)pJVar1->mEndZ,(double)pJVar1->mNearZ,
               (double)pJVar1->mFarZ,pJVar1->mType,local_18);
    J3DGraphBase::J3DGDSetFogRangeAdj(pJVar1->mAdjEnable,pJVar1->mCenter,pJVar1->mFogAdjTable);
  }
  os::DCFlushRange(iVar2,gd::__GDCurrentDL[2] - iVar2);
  return;
}


/* __thiscall J3DPEBlockFull::diffFog(void) */

void __thiscall J3DPEBlockFull::diffFog(J3DPEBlockFull *this)

{
  J3DFog *pJVar1;
  _GXColor local_18 [5];
  
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 0x37U) {
    gd::GDOverflowed();
  }
  pJVar1 = this->mpFog;
  if (pJVar1 != (J3DFog *)0x0) {
    local_18[0] = pJVar1->mColor;
    J3DGraphBase::J3DGDSetFog
              ((double)pJVar1->mStartZ,(double)pJVar1->mEndZ,(double)pJVar1->mNearZ,
               (double)pJVar1->mFarZ,pJVar1->mType,local_18);
    J3DGraphBase::J3DGDSetFogRangeAdj(pJVar1->mAdjEnable,pJVar1->mCenter,pJVar1->mFogAdjTable);
  }
  return;
}


/* __thiscall J3DPEBlockFull::diffBlend(void) */

void __thiscall J3DPEBlockFull::diffBlend(J3DPEBlockFull *this)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  byte bVar7;
  int iVar6;
  uint uVar8;
  uint uVar9;
  undefined *puVar10;
  int iVar11;
  byte *pbVar12;
  
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 0xfU) {
    gd::GDOverflowed();
  }
  bVar7 = this->mDither;
  bVar1 = (this->mBlend).field_0x3;
  bVar2 = (this->mBlend).field_0x2;
  bVar3 = (this->mBlend).field_0x1;
  uVar8 = (uint)(this->mBlend).field_0x0;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x61;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0xfe;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x1f;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0xe7;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x61;
  iVar6 = (uint)bVar1 << 0xc;
  uVar9 = countLeadingZeros(3 - uVar8);
  iVar11 = (uVar9 & 0x1fe0) << 6;
  iVar4 = (uint)bVar2 << 5;
  iVar5 = (uint)bVar7 << 2;
  uVar9 = countLeadingZeros(2 - uVar8);
  uVar9 = uVar9 >> 4 & 0x1fe;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x41;
  pbVar12 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar12 + 1;
  *pbVar12 = (byte)((uint)iVar6 >> 0x10) | (byte)((uint)iVar11 >> 0x10);
  pbVar12 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar12 + 1;
  *pbVar12 = (byte)((uint)iVar6 >> 8) |
             (byte)((uint)iVar11 >> 8) |
             bVar3 | (byte)((uint)iVar4 >> 8) | (byte)((uint)iVar5 >> 8) | (byte)(uVar9 >> 8);
  bVar7 = 0;
  if ((uVar8 == 1) || (uVar8 == 3)) {
    bVar7 = 1;
  }
  pbVar12 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar12 + 1;
  *pbVar12 = (byte)iVar4 | (byte)iVar5 | (byte)uVar9 | bVar7;
  iVar6 = (uint)(ushort)this->mZMode * 3;
  bVar7 = (&DAT_803f00e2)[iVar6];
  bVar1 = (&DAT_803f00e1)[iVar6];
  bVar2 = (&J3DGraphBase::j3dZModeTable)[iVar6];
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x61;
  uVar9 = (uint)bVar7 << 4 | (uint)bVar2 | (uint)bVar1 << 1;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0x40;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = 0;
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = (char)(uVar9 >> 8);
  puVar10 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar10 + 1;
  *puVar10 = (char)uVar9;
  return;
}


/* __thiscall J3DPEBlockFull::diff(unsigned long) */

void __thiscall J3DPEBlockFull::diff(J3DPEBlockFull *this,ulong param_1)

{
  if ((param_1 & 0x10000000) != 0) {
    (**(code **)(this->vtbl + 0x18))();
  }
  if ((param_1 & 0x20000000) != 0) {
    (**(code **)(this->vtbl + 0x1c))(this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DColorBlockLightOff::reset(J3DColorBlock *) */

void __thiscall J3DColorBlockLightOff::reset(J3DColorBlockLightOff *this,J3DColorBlock *param_1)

{
  J3DColorBlockLightOff JVar3;
  J3DColorBlockLightOff *pJVar1;
  undefined2 *puVar2;
  J3DColorBlockLightOff *pJVar4;
  uint uVar5;
  int iVar6;
  
  JVar3 = (J3DColorBlockLightOff)(*(code *)param_1->vtbl->getColorChanNum)(param_1);
  this[0xc] = JVar3;
  uVar5 = 0;
  iVar6 = 0;
  do {
    pJVar1 = (J3DColorBlockLightOff *)(*(code *)param_1->vtbl->getMatColor)(param_1,uVar5);
    pJVar4 = this + iVar6;
    pJVar4[4] = *pJVar1;
    pJVar4[5] = pJVar1[1];
    pJVar4[6] = pJVar1[2];
    pJVar4[7] = pJVar1[3];
    uVar5 = uVar5 + 1;
    iVar6 = iVar6 + 4;
  } while (uVar5 < 2);
  uVar5 = 0;
  iVar6 = 0;
  do {
    puVar2 = (undefined2 *)(*(code *)param_1->vtbl->getColorChan)(param_1,uVar5);
    *(undefined2 *)(this + iVar6 + 0xe) = *puVar2;
    uVar5 = uVar5 + 1;
    iVar6 = iVar6 + 2;
  } while (uVar5 < 4);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DColorBlockAmbientOn::reset(J3DColorBlock *) */

void __thiscall J3DColorBlockAmbientOn::reset(J3DColorBlockAmbientOn *this,J3DColorBlock *param_1)

{
  J3DColorBlockAmbientOn JVar4;
  J3DColorBlockAmbientOn *pJVar1;
  undefined2 *puVar2;
  int iVar3;
  J3DColorBlockAmbientOn *pJVar5;
  uint uVar6;
  int iVar7;
  
  JVar4 = (J3DColorBlockAmbientOn)(*(code *)param_1->vtbl->getColorChanNum)(param_1);
  this[0xc] = JVar4;
  uVar6 = 0;
  iVar7 = 0;
  do {
    pJVar1 = (J3DColorBlockAmbientOn *)(*(code *)param_1->vtbl->getMatColor)(param_1,uVar6);
    pJVar5 = this + iVar7;
    pJVar5[4] = *pJVar1;
    pJVar5[5] = pJVar1[1];
    pJVar5[6] = pJVar1[2];
    pJVar5[7] = pJVar1[3];
    uVar6 = uVar6 + 1;
    iVar7 = iVar7 + 4;
  } while (uVar6 < 2);
  uVar6 = 0;
  iVar7 = 0;
  do {
    puVar2 = (undefined2 *)(*(code *)param_1->vtbl->getColorChan)(param_1,uVar6);
    *(undefined2 *)(this + iVar7 + 0xe) = *puVar2;
    uVar6 = uVar6 + 1;
    iVar7 = iVar7 + 2;
  } while (uVar6 < 4);
  uVar6 = 0;
  iVar7 = 0;
  do {
    iVar3 = (*(code *)param_1->vtbl->getAmbColor)(param_1,uVar6);
    if (iVar3 != 0) {
      pJVar1 = (J3DColorBlockAmbientOn *)(*(code *)param_1->vtbl->getAmbColor)(param_1,uVar6);
      pJVar5 = this + iVar7;
      pJVar5[0x20] = *pJVar1;
      pJVar5[0x21] = pJVar1[1];
      pJVar5[0x22] = pJVar1[2];
      pJVar5[0x23] = pJVar1[3];
    }
    uVar6 = uVar6 + 1;
    iVar7 = iVar7 + 4;
  } while (uVar6 < 2);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DColorBlockLightOn::reset(J3DColorBlock *) */

void __thiscall J3DColorBlockLightOn::reset(J3DColorBlockLightOn *this,J3DColorBlock *param_1)

{
  undefined uVar4;
  undefined *puVar1;
  undefined2 *puVar2;
  int iVar3;
  uint uVar5;
  int iVar6;
  
  uVar4 = (*(code *)param_1->vtbl->getColorChanNum)(param_1);
  *(undefined *)&this->field_0x14 = uVar4;
  uVar5 = 0;
  iVar6 = 0;
  do {
    puVar1 = (undefined *)(*(code *)param_1->vtbl->getMatColor)(param_1,uVar5);
    iVar3 = (int)this->mColors + iVar6 + -4;
    *(undefined *)(iVar3 + 4) = *puVar1;
    *(undefined *)(iVar3 + 5) = puVar1[1];
    *(undefined *)(iVar3 + 6) = puVar1[2];
    *(undefined *)(iVar3 + 7) = puVar1[3];
    uVar5 = uVar5 + 1;
    iVar6 = iVar6 + 4;
  } while (uVar5 < 2);
  uVar5 = 0;
  iVar6 = 0;
  do {
    puVar2 = (undefined2 *)(*(code *)param_1->vtbl->getColorChan)(param_1,uVar5);
    *(undefined2 *)((int)&this->mColorChan[0].mChan + iVar6) = *puVar2;
    uVar5 = uVar5 + 1;
    iVar6 = iVar6 + 2;
  } while (uVar5 < 4);
  uVar5 = 0;
  iVar6 = 0;
  do {
    iVar3 = (*(code *)param_1->vtbl->getAmbColor)(param_1,uVar5);
    if (iVar3 != 0) {
      puVar1 = (undefined *)(*(code *)param_1->vtbl->getAmbColor)(param_1,uVar5);
      iVar3 = (int)this->mColors + iVar6 + -4;
      *(undefined *)(iVar3 + 0xc) = *puVar1;
      *(undefined *)(iVar3 + 0xd) = puVar1[1];
      *(undefined *)(iVar3 + 0xe) = puVar1[2];
      *(undefined *)(iVar3 + 0xf) = puVar1[3];
    }
    uVar5 = uVar5 + 1;
    iVar6 = iVar6 + 4;
  } while (uVar5 < 2);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DTexGenBlockPatched::reset(J3DTexGenBlock *) */

void __thiscall J3DTexGenBlockPatched::reset(J3DTexGenBlockPatched *this,J3DTexGenBlock *param_1)

{
  undefined *puVar1;
  int iVar2;
  byte *src;
  uint uVar3;
  int iVar4;
  
  puVar1 = (undefined *)(**(code **)(*(int *)param_1 + 0x34))(param_1);
  this->field_0x4 = puVar1;
  uVar3 = 0;
  iVar4 = 0;
  do {
    puVar1 = (undefined *)(**(code **)(*(int *)param_1 + 0x3c))(param_1,uVar3);
    iVar2 = (int)&this->vtbl + iVar4;
    *(undefined *)(iVar2 + 8) = *puVar1;
    *(undefined *)(iVar2 + 9) = puVar1[1];
    *(undefined *)(iVar2 + 10) = puVar1[2];
    uVar3 = uVar3 + 1;
    iVar4 = iVar4 + 4;
  } while (uVar3 < 8);
  uVar3 = 0;
  iVar4 = 0;
  do {
    iVar2 = (**(code **)(*(int *)param_1 + 0x44))(param_1,uVar3);
    if (iVar2 != 0) {
      if (*(int *)((int)&this[5].vtbl + iVar4) == 0) {
        m_Do_printf::OSReport("Error : TexMtx[%d] is Null.\n",uVar3);
      }
      else {
        src = (byte *)(**(code **)(*(int *)param_1 + 0x44))(param_1,uVar3);
        copy_bytes(*(byte **)((int)&this[5].vtbl + iVar4),src,0xc4);
        os::DCStoreRange(*(undefined4 *)((int)&this[5].vtbl + iVar4),0xc4);
      }
    }
    uVar3 = uVar3 + 1;
    iVar4 = iVar4 + 4;
  } while (uVar3 < 8);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DTexGenBlock4::reset(J3DTexGenBlock *) */

void __thiscall J3DTexGenBlock4::reset(J3DTexGenBlock4 *this,J3DTexGenBlock *param_1)

{
  undefined4 uVar1;
  J3DTexGenBlock4 *pJVar2;
  int iVar3;
  byte *src;
  J3DTexGenBlock4 *pJVar4;
  uint uVar5;
  int iVar6;
  
  uVar1 = (**(code **)(*(int *)param_1 + 0x34))(param_1);
  *(undefined4 *)(this + 4) = uVar1;
  uVar5 = 0;
  iVar6 = 0;
  do {
    pJVar2 = (J3DTexGenBlock4 *)(**(code **)(*(int *)param_1 + 0x3c))(param_1,uVar5);
    pJVar4 = this + iVar6;
    pJVar4[8] = *pJVar2;
    pJVar4[9] = pJVar2[1];
    pJVar4[10] = pJVar2[2];
    uVar5 = uVar5 + 1;
    iVar6 = iVar6 + 4;
  } while (uVar5 < 4);
  uVar5 = 0;
  iVar6 = 0;
  do {
    iVar3 = (**(code **)(*(int *)param_1 + 0x44))(param_1,uVar5);
    if (iVar3 != 0) {
      iVar3 = iVar6 + 0x28;
      if (*(int *)(this + iVar3) == 0) {
        m_Do_printf::OSReport("Error : TexMtx[%d] is Null.\n",uVar5);
      }
      else {
        src = (byte *)(**(code **)(*(int *)param_1 + 0x44))(param_1,uVar5);
        copy_bytes(*(byte **)(this + iVar3),src,0xc4);
        os::DCStoreRange(*(undefined4 *)(this + iVar3),0xc4);
      }
    }
    uVar5 = uVar5 + 1;
    iVar6 = iVar6 + 4;
  } while (uVar5 < 4);
  pJVar2 = (J3DTexGenBlock4 *)(**(code **)(*(int *)param_1 + 0x50))(param_1);
  this[0x4c] = *pJVar2;
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(pJVar2 + 4);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(pJVar2 + 8);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(pJVar2 + 0xc);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DTexGenBlockBasic::reset(J3DTexGenBlock *) */

void __thiscall J3DTexGenBlockBasic::reset(J3DTexGenBlockBasic *this,J3DTexGenBlock *param_1)

{
  undefined4 uVar1;
  J3DTexGenBlockBasic *pJVar2;
  int iVar3;
  byte *src;
  J3DTexGenBlockBasic *pJVar4;
  uint uVar5;
  int iVar6;
  
  uVar1 = (**(code **)(*(int *)param_1 + 0x34))(param_1);
  *(undefined4 *)(this + 4) = uVar1;
  uVar5 = 0;
  iVar6 = 0;
  do {
    pJVar2 = (J3DTexGenBlockBasic *)(**(code **)(*(int *)param_1 + 0x3c))(param_1,uVar5);
    pJVar4 = this + iVar6;
    pJVar4[8] = *pJVar2;
    pJVar4[9] = pJVar2[1];
    pJVar4[10] = pJVar2[2];
    uVar5 = uVar5 + 1;
    iVar6 = iVar6 + 4;
  } while (uVar5 < 8);
  uVar5 = 0;
  iVar6 = 0;
  do {
    iVar3 = (**(code **)(*(int *)param_1 + 0x44))(param_1,uVar5);
    if (iVar3 != 0) {
      iVar3 = iVar6 + 0x28;
      if (*(int *)(this + iVar3) == 0) {
        m_Do_printf::OSReport("Error : TexMtx[%d] is Null.\n",uVar5);
      }
      else {
        src = (byte *)(**(code **)(*(int *)param_1 + 0x44))(param_1,uVar5);
        copy_bytes(*(byte **)(this + iVar3),src,0xc4);
        os::DCStoreRange(*(undefined4 *)(this + iVar3),0xc4);
      }
    }
    uVar5 = uVar5 + 1;
    iVar6 = iVar6 + 4;
  } while (uVar5 < 8);
  pJVar2 = (J3DTexGenBlockBasic *)(**(code **)(*(int *)param_1 + 0x50))(param_1);
  this[0x4c] = *pJVar2;
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(pJVar2 + 4);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(pJVar2 + 8);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(pJVar2 + 0xc);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DTevBlockPatched::reset(J3DTevBlock *) */

void __thiscall J3DTevBlockPatched::reset(J3DTevBlockPatched *this,J3DTevBlock *param_1)

{
  byte bVar6;
  undefined2 uVar5;
  undefined2 *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  bVar6 = (*(code *)param_1->vtbl->getTevStageNum)(param_1);
  this->mTevStageNum = bVar6;
  uVar9 = 0;
  iVar8 = 0;
  do {
    uVar5 = (*(code *)param_1->vtbl->getTexNo)(param_1,uVar9);
    *(undefined2 *)((int)this->mTexNo + iVar8) = uVar5;
    uVar9 = uVar9 + 1;
    iVar8 = iVar8 + 2;
  } while (uVar9 < 8);
  uVar9 = 0;
  iVar8 = 0;
  do {
    puVar1 = (undefined2 *)(*(code *)param_1->vtbl->getTevColor)(param_1,uVar9);
    iVar10 = (int)this->mTexNo + iVar8 + -8;
    *(undefined2 *)(iVar10 + 0x98) = *puVar1;
    *(undefined2 *)(iVar10 + 0x9a) = puVar1[1];
    *(undefined2 *)(iVar10 + 0x9c) = puVar1[2];
    *(undefined2 *)(iVar10 + 0x9e) = puVar1[3];
    uVar9 = uVar9 + 1;
    iVar8 = iVar8 + 8;
  } while (uVar9 < 4);
  uVar9 = 0;
  iVar8 = 0;
  do {
    puVar2 = (undefined *)(*(code *)param_1->vtbl->getTevKColor)(param_1,uVar9);
    iVar10 = (int)this->mTexNo + iVar8 + -8;
    *(undefined *)(iVar10 + 0xb8) = *puVar2;
    *(undefined *)(iVar10 + 0xb9) = puVar2[1];
    *(undefined *)(iVar10 + 0xba) = puVar2[2];
    *(undefined *)(iVar10 + 0xbb) = puVar2[3];
    uVar9 = uVar9 + 1;
    iVar8 = iVar8 + 4;
  } while (uVar9 < 4);
  uVar9 = 0;
  iVar10 = 0;
  iVar8 = 0;
  do {
    iVar3 = (*(code *)param_1->vtbl->getTevStage)(param_1,uVar9);
    iVar7 = (int)this->mTexNo + iVar8 + -8;
    *(undefined *)(iVar7 + 0x39) = *(undefined *)(iVar3 + 1);
    *(undefined *)(iVar7 + 0x3a) = *(undefined *)(iVar3 + 2);
    *(undefined *)(iVar7 + 0x3b) = *(undefined *)(iVar3 + 3);
    *(undefined *)(iVar7 + 0x3d) = *(undefined *)(iVar3 + 5);
    *(undefined *)(iVar7 + 0x3e) = *(undefined *)(iVar3 + 6);
    *(undefined *)(iVar7 + 0x3f) = *(undefined *)(iVar3 + 7);
    puVar4 = (undefined4 *)(*(code *)param_1->vtbl->getIndTevStage)(param_1,uVar9);
    *(undefined4 *)((int)this->mIndStages + iVar10) = *puVar4;
    uVar9 = uVar9 + 1;
    iVar10 = iVar10 + 4;
    iVar8 = iVar8 + 8;
  } while (uVar9 < 8);
  return;
}


/* __thiscall J3DTevBlock1::reset(J3DTevBlock *) */

void __thiscall J3DTevBlock1::reset(J3DTevBlock1 *this,J3DTevBlock *param_1)

{
  undefined2 uVar4;
  J3DTevBlock1 *pJVar1;
  int iVar2;
  undefined4 *puVar3;
  
  uVar4 = (*(code *)param_1->vtbl->getTexNo)(param_1,0);
  *(undefined2 *)(this + 8) = uVar4;
  pJVar1 = (J3DTevBlock1 *)(*(code *)param_1->vtbl->getTevOrder)(param_1,0);
  this[10] = *pJVar1;
  this[0xb] = pJVar1[1];
  this[0xc] = pJVar1[2];
  iVar2 = (*(code *)param_1->vtbl->getTevStage)(param_1,0);
  this[0xf] = *(J3DTevBlock1 *)(iVar2 + 1);
  this[0x10] = *(J3DTevBlock1 *)(iVar2 + 2);
  this[0x11] = *(J3DTevBlock1 *)(iVar2 + 3);
  this[0x13] = *(J3DTevBlock1 *)(iVar2 + 5);
  this[0x14] = *(J3DTevBlock1 *)(iVar2 + 6);
  this[0x15] = *(J3DTevBlock1 *)(iVar2 + 7);
  puVar3 = (undefined4 *)(*(code *)param_1->vtbl->getIndTevStage)(param_1,0);
  *(undefined4 *)(this + 0x18) = *puVar3;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DTevBlock2::reset(J3DTevBlock *) */

void __thiscall J3DTevBlock2::reset(J3DTevBlock2 *this,J3DTevBlock *param_1)

{
  J3DTevBlock2 JVar6;
  undefined2 uVar5;
  int iVar1;
  undefined4 *puVar2;
  J3DTevBlock2 *pJVar3;
  undefined2 *puVar4;
  J3DTevBlock2 *pJVar7;
  uint uVar8;
  
  JVar6 = (J3DTevBlock2)(*(code *)param_1->vtbl->getTevStageNum)(param_1);
  this[0x34] = JVar6;
  uVar5 = (*(code *)param_1->vtbl->getTexNo)(param_1,0);
  *(undefined2 *)(this + 8) = uVar5;
  uVar5 = (*(code *)param_1->vtbl->getTexNo)(param_1,1);
  *(undefined2 *)(this + 10) = uVar5;
  iVar1 = (*(code *)param_1->vtbl->getTevStage)(param_1,0);
  this[0x36] = *(J3DTevBlock2 *)(iVar1 + 1);
  this[0x37] = *(J3DTevBlock2 *)(iVar1 + 2);
  this[0x38] = *(J3DTevBlock2 *)(iVar1 + 3);
  this[0x3a] = *(J3DTevBlock2 *)(iVar1 + 5);
  this[0x3b] = *(J3DTevBlock2 *)(iVar1 + 6);
  this[0x3c] = *(J3DTevBlock2 *)(iVar1 + 7);
  iVar1 = (*(code *)param_1->vtbl->getTevStage)(param_1,1);
  this[0x3e] = *(J3DTevBlock2 *)(iVar1 + 1);
  this[0x3f] = *(J3DTevBlock2 *)(iVar1 + 2);
  this[0x40] = *(J3DTevBlock2 *)(iVar1 + 3);
  this[0x42] = *(J3DTevBlock2 *)(iVar1 + 5);
  this[0x43] = *(J3DTevBlock2 *)(iVar1 + 6);
  this[0x44] = *(J3DTevBlock2 *)(iVar1 + 7);
  puVar2 = (undefined4 *)(*(code *)param_1->vtbl->getIndTevStage)(param_1,0);
  *(undefined4 *)(this + 0x60) = *puVar2;
  puVar2 = (undefined4 *)(*(code *)param_1->vtbl->getIndTevStage)(param_1,1);
  *(undefined4 *)(this + 100) = *puVar2;
  pJVar3 = (J3DTevBlock2 *)(*(code *)param_1->vtbl->getTevOrder)(param_1,0);
  this[0xc] = *pJVar3;
  this[0xd] = pJVar3[1];
  this[0xe] = pJVar3[2];
  pJVar3 = (J3DTevBlock2 *)(*(code *)param_1->vtbl->getTevOrder)(param_1,1);
  this[0x10] = *pJVar3;
  this[0x11] = pJVar3[1];
  this[0x12] = pJVar3[2];
  JVar6 = (J3DTevBlock2)(*(code *)param_1->vtbl->getTevKColorSel)(param_1,0);
  this[0x55] = JVar6;
  JVar6 = (J3DTevBlock2)(*(code *)param_1->vtbl->getTevKColorSel)(param_1,1);
  this[0x56] = JVar6;
  JVar6 = (J3DTevBlock2)(*(code *)param_1->vtbl->getTevKAlphaSel)(param_1,0);
  this[0x57] = JVar6;
  JVar6 = (J3DTevBlock2)(*(code *)param_1->vtbl->getTevKAlphaSel)(param_1,1);
  this[0x58] = JVar6;
  uVar8 = 0;
  iVar1 = 0;
  do {
    puVar4 = (undefined2 *)(*(code *)param_1->vtbl->getTevColor)(param_1,uVar8);
    pJVar3 = this + iVar1;
    *(undefined2 *)(pJVar3 + 0x14) = *puVar4;
    *(undefined2 *)(pJVar3 + 0x16) = puVar4[1];
    *(undefined2 *)(pJVar3 + 0x18) = puVar4[2];
    *(undefined2 *)(pJVar3 + 0x1a) = puVar4[3];
    uVar8 = uVar8 + 1;
    iVar1 = iVar1 + 8;
  } while (uVar8 < 4);
  uVar8 = 0;
  iVar1 = 0;
  do {
    pJVar3 = (J3DTevBlock2 *)(*(code *)param_1->vtbl->getTevKColor)(param_1,uVar8);
    pJVar7 = this + iVar1;
    pJVar7[0x45] = *pJVar3;
    pJVar7[0x46] = pJVar3[1];
    pJVar7[0x47] = pJVar3[2];
    pJVar7[0x48] = pJVar3[3];
    uVar8 = uVar8 + 1;
    iVar1 = iVar1 + 4;
  } while (uVar8 < 4);
  uVar8 = 0;
  do {
    pJVar3 = (J3DTevBlock2 *)(*(code *)param_1->vtbl->getTevSwapModeTable)(param_1,uVar8);
    this[uVar8 + 0x59] = *pJVar3;
    uVar8 = uVar8 + 1;
  } while (uVar8 < 4);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DTevBlock4::reset(J3DTevBlock *) */

void __thiscall J3DTevBlock4::reset(J3DTevBlock4 *this,J3DTevBlock *param_1)

{
  J3DTevBlock4 JVar6;
  undefined2 uVar5;
  int iVar1;
  undefined4 *puVar2;
  J3DTevBlock4 *pJVar3;
  undefined2 *puVar4;
  J3DTevBlock4 *pJVar7;
  uint uVar8;
  
  JVar6 = (J3DTevBlock4)(*(code *)param_1->vtbl->getTevStageNum)(param_1);
  this[0x20] = JVar6;
  uVar5 = (*(code *)param_1->vtbl->getTexNo)(param_1,0);
  *(undefined2 *)(this + 8) = uVar5;
  uVar5 = (*(code *)param_1->vtbl->getTexNo)(param_1,1);
  *(undefined2 *)(this + 10) = uVar5;
  uVar5 = (*(code *)param_1->vtbl->getTexNo)(param_1,2);
  *(undefined2 *)(this + 0xc) = uVar5;
  uVar5 = (*(code *)param_1->vtbl->getTexNo)(param_1,3);
  *(undefined2 *)(this + 0xe) = uVar5;
  iVar1 = (*(code *)param_1->vtbl->getTevStage)(param_1,0);
  this[0x22] = *(J3DTevBlock4 *)(iVar1 + 1);
  this[0x23] = *(J3DTevBlock4 *)(iVar1 + 2);
  this[0x24] = *(J3DTevBlock4 *)(iVar1 + 3);
  this[0x26] = *(J3DTevBlock4 *)(iVar1 + 5);
  this[0x27] = *(J3DTevBlock4 *)(iVar1 + 6);
  this[0x28] = *(J3DTevBlock4 *)(iVar1 + 7);
  iVar1 = (*(code *)param_1->vtbl->getTevStage)(param_1,1);
  this[0x2a] = *(J3DTevBlock4 *)(iVar1 + 1);
  this[0x2b] = *(J3DTevBlock4 *)(iVar1 + 2);
  this[0x2c] = *(J3DTevBlock4 *)(iVar1 + 3);
  this[0x2e] = *(J3DTevBlock4 *)(iVar1 + 5);
  this[0x2f] = *(J3DTevBlock4 *)(iVar1 + 6);
  this[0x30] = *(J3DTevBlock4 *)(iVar1 + 7);
  iVar1 = (*(code *)param_1->vtbl->getTevStage)(param_1,2);
  this[0x32] = *(J3DTevBlock4 *)(iVar1 + 1);
  this[0x33] = *(J3DTevBlock4 *)(iVar1 + 2);
  this[0x34] = *(J3DTevBlock4 *)(iVar1 + 3);
  this[0x36] = *(J3DTevBlock4 *)(iVar1 + 5);
  this[0x37] = *(J3DTevBlock4 *)(iVar1 + 6);
  this[0x38] = *(J3DTevBlock4 *)(iVar1 + 7);
  iVar1 = (*(code *)param_1->vtbl->getTevStage)(param_1,3);
  this[0x3a] = *(J3DTevBlock4 *)(iVar1 + 1);
  this[0x3b] = *(J3DTevBlock4 *)(iVar1 + 2);
  this[0x3c] = *(J3DTevBlock4 *)(iVar1 + 3);
  this[0x3e] = *(J3DTevBlock4 *)(iVar1 + 5);
  this[0x3f] = *(J3DTevBlock4 *)(iVar1 + 6);
  this[0x40] = *(J3DTevBlock4 *)(iVar1 + 7);
  puVar2 = (undefined4 *)(*(code *)param_1->vtbl->getIndTevStage)(param_1,0);
  *(undefined4 *)(this + 0x80) = *puVar2;
  puVar2 = (undefined4 *)(*(code *)param_1->vtbl->getIndTevStage)(param_1,1);
  *(undefined4 *)(this + 0x84) = *puVar2;
  puVar2 = (undefined4 *)(*(code *)param_1->vtbl->getIndTevStage)(param_1,2);
  *(undefined4 *)(this + 0x88) = *puVar2;
  puVar2 = (undefined4 *)(*(code *)param_1->vtbl->getIndTevStage)(param_1,3);
  *(undefined4 *)(this + 0x8c) = *puVar2;
  pJVar3 = (J3DTevBlock4 *)(*(code *)param_1->vtbl->getTevOrder)(param_1,0);
  this[0x10] = *pJVar3;
  this[0x11] = pJVar3[1];
  this[0x12] = pJVar3[2];
  pJVar3 = (J3DTevBlock4 *)(*(code *)param_1->vtbl->getTevOrder)(param_1,1);
  this[0x14] = *pJVar3;
  this[0x15] = pJVar3[1];
  this[0x16] = pJVar3[2];
  pJVar3 = (J3DTevBlock4 *)(*(code *)param_1->vtbl->getTevOrder)(param_1,2);
  this[0x18] = *pJVar3;
  this[0x19] = pJVar3[1];
  this[0x1a] = pJVar3[2];
  pJVar3 = (J3DTevBlock4 *)(*(code *)param_1->vtbl->getTevOrder)(param_1,3);
  this[0x1c] = *pJVar3;
  this[0x1d] = pJVar3[1];
  this[0x1e] = pJVar3[2];
  JVar6 = (J3DTevBlock4)(*(code *)param_1->vtbl->getTevKColorSel)(param_1,0);
  this[0x72] = JVar6;
  JVar6 = (J3DTevBlock4)(*(code *)param_1->vtbl->getTevKColorSel)(param_1,1);
  this[0x73] = JVar6;
  JVar6 = (J3DTevBlock4)(*(code *)param_1->vtbl->getTevKColorSel)(param_1,2);
  this[0x74] = JVar6;
  JVar6 = (J3DTevBlock4)(*(code *)param_1->vtbl->getTevKColorSel)(param_1,3);
  this[0x75] = JVar6;
  JVar6 = (J3DTevBlock4)(*(code *)param_1->vtbl->getTevKAlphaSel)(param_1,0);
  this[0x76] = JVar6;
  JVar6 = (J3DTevBlock4)(*(code *)param_1->vtbl->getTevKAlphaSel)(param_1,1);
  this[0x77] = JVar6;
  JVar6 = (J3DTevBlock4)(*(code *)param_1->vtbl->getTevKAlphaSel)(param_1,2);
  this[0x78] = JVar6;
  JVar6 = (J3DTevBlock4)(*(code *)param_1->vtbl->getTevKAlphaSel)(param_1,3);
  this[0x79] = JVar6;
  uVar8 = 0;
  iVar1 = 0;
  do {
    puVar4 = (undefined2 *)(*(code *)param_1->vtbl->getTevColor)(param_1,uVar8);
    pJVar3 = this + iVar1;
    *(undefined2 *)(pJVar3 + 0x42) = *puVar4;
    *(undefined2 *)(pJVar3 + 0x44) = puVar4[1];
    *(undefined2 *)(pJVar3 + 0x46) = puVar4[2];
    *(undefined2 *)(pJVar3 + 0x48) = puVar4[3];
    uVar8 = uVar8 + 1;
    iVar1 = iVar1 + 8;
  } while (uVar8 < 4);
  uVar8 = 0;
  iVar1 = 0;
  do {
    pJVar3 = (J3DTevBlock4 *)(*(code *)param_1->vtbl->getTevKColor)(param_1,uVar8);
    pJVar7 = this + iVar1;
    pJVar7[0x62] = *pJVar3;
    pJVar7[99] = pJVar3[1];
    pJVar7[100] = pJVar3[2];
    pJVar7[0x65] = pJVar3[3];
    uVar8 = uVar8 + 1;
    iVar1 = iVar1 + 4;
  } while (uVar8 < 4);
  uVar8 = 0;
  do {
    pJVar3 = (J3DTevBlock4 *)(*(code *)param_1->vtbl->getTevSwapModeTable)(param_1,uVar8);
    this[uVar8 + 0x7a] = *pJVar3;
    uVar8 = uVar8 + 1;
  } while (uVar8 < 4);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DTevBlock16::reset(J3DTevBlock *) */

void __thiscall J3DTevBlock16::reset(J3DTevBlock16 *this,J3DTevBlock *param_1)

{
  J3DTevBlock16 JVar6;
  undefined2 uVar5;
  J3DTevBlock16 *pJVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  J3DTevBlock16 *pJVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  JVar6 = (J3DTevBlock16)(*(code *)param_1->vtbl->getTevStageNum)(param_1);
  this[0x58] = JVar6;
  uVar9 = 0;
  iVar8 = 0;
  do {
    uVar5 = (*(code *)param_1->vtbl->getTexNo)(param_1,uVar9);
    *(undefined2 *)(this + iVar8 + 8) = uVar5;
    uVar9 = uVar9 + 1;
    iVar8 = iVar8 + 2;
  } while (uVar9 < 8);
  uVar9 = 0;
  iVar8 = 0;
  do {
    pJVar1 = (J3DTevBlock16 *)(*(code *)param_1->vtbl->getTevOrder)(param_1,uVar9);
    pJVar7 = this + iVar8;
    pJVar7[0x18] = *pJVar1;
    pJVar7[0x19] = pJVar1[1];
    pJVar7[0x1a] = pJVar1[2];
    uVar9 = uVar9 + 1;
    iVar8 = iVar8 + 4;
  } while (uVar9 < 0x10);
  uVar9 = 0;
  iVar10 = 0;
  iVar8 = 0;
  do {
    iVar2 = (*(code *)param_1->vtbl->getTevStage)(param_1,uVar9);
    pJVar1 = this + iVar8;
    pJVar1[0x5a] = *(J3DTevBlock16 *)(iVar2 + 1);
    pJVar1[0x5b] = *(J3DTevBlock16 *)(iVar2 + 2);
    pJVar1[0x5c] = *(J3DTevBlock16 *)(iVar2 + 3);
    pJVar1[0x5e] = *(J3DTevBlock16 *)(iVar2 + 5);
    pJVar1[0x5f] = *(J3DTevBlock16 *)(iVar2 + 6);
    pJVar1[0x60] = *(J3DTevBlock16 *)(iVar2 + 7);
    puVar3 = (undefined4 *)(*(code *)param_1->vtbl->getIndTevStage)(param_1,uVar9);
    *(undefined4 *)(this + iVar10 + 0x130) = *puVar3;
    uVar9 = uVar9 + 1;
    iVar10 = iVar10 + 4;
    iVar8 = iVar8 + 8;
  } while (uVar9 < 0x10);
  uVar9 = 0;
  iVar8 = 0;
  do {
    puVar4 = (undefined2 *)(*(code *)param_1->vtbl->getTevColor)(param_1,uVar9);
    pJVar1 = this + iVar8;
    *(undefined2 *)(pJVar1 + 0xda) = *puVar4;
    *(undefined2 *)(pJVar1 + 0xdc) = puVar4[1];
    *(undefined2 *)(pJVar1 + 0xde) = puVar4[2];
    *(undefined2 *)(pJVar1 + 0xe0) = puVar4[3];
    uVar9 = uVar9 + 1;
    iVar8 = iVar8 + 8;
  } while (uVar9 < 4);
  uVar9 = 0;
  iVar8 = 0;
  do {
    pJVar1 = (J3DTevBlock16 *)(*(code *)param_1->vtbl->getTevKColor)(param_1,uVar9);
    pJVar7 = this + iVar8;
    pJVar7[0xfa] = *pJVar1;
    pJVar7[0xfb] = pJVar1[1];
    pJVar7[0xfc] = pJVar1[2];
    pJVar7[0xfd] = pJVar1[3];
    uVar9 = uVar9 + 1;
    iVar8 = iVar8 + 4;
  } while (uVar9 < 4);
  uVar9 = 0;
  do {
    JVar6 = (J3DTevBlock16)(*(code *)param_1->vtbl->getTevKColorSel)(param_1,uVar9);
    this[uVar9 + 0x10a] = JVar6;
    uVar9 = uVar9 + 1;
  } while (uVar9 < 0x10);
  uVar9 = 0;
  do {
    JVar6 = (J3DTevBlock16)(*(code *)param_1->vtbl->getTevKAlphaSel)(param_1,uVar9);
    this[uVar9 + 0x11a] = JVar6;
    uVar9 = uVar9 + 1;
  } while (uVar9 < 0x10);
  uVar9 = 0;
  do {
    pJVar1 = (J3DTevBlock16 *)(*(code *)param_1->vtbl->getTevSwapModeTable)(param_1,uVar9);
    this[uVar9 + 0x12a] = *pJVar1;
    uVar9 = uVar9 + 1;
  } while (uVar9 < 4);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DIndBlockFull::reset(J3DIndBlock *) */

void __thiscall J3DIndBlockFull::reset(J3DIndBlockFull *this,J3DIndBlock *param_1)

{
  J3DIndBlockFull JVar3;
  J3DIndBlockFull *pJVar1;
  int iVar2;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  JVar3 = (J3DIndBlockFull)(**(code **)(*(int *)param_1 + 0x20))(param_1);
  this[4] = JVar3;
  uVar7 = 0;
  iVar8 = 0;
  do {
    pJVar1 = (J3DIndBlockFull *)(**(code **)(*(int *)param_1 + 0x2c))(param_1,uVar7);
    (this + iVar8)[5] = *pJVar1;
    (this + iVar8)[6] = pJVar1[1];
    uVar7 = uVar7 + 1;
    iVar8 = iVar8 + 4;
  } while (uVar7 < 4);
  uVar7 = 0;
  iVar8 = 0;
  do {
    iVar2 = (**(code **)(*(int *)param_1 + 0x38))(param_1,uVar7);
    iVar6 = 0;
    iVar4 = 0;
    do {
      iVar5 = 0;
      iVar9 = 3;
      do {
        *(undefined4 *)(this + iVar8 + iVar5 + 0x18 + iVar4) =
             *(undefined4 *)(iVar2 + iVar4 + iVar5);
        iVar5 = iVar5 + 4;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      iVar6 = iVar6 + 1;
      iVar4 = iVar4 + 0xc;
    } while (iVar6 < 2);
    (this + iVar8)[0x30] = *(J3DIndBlockFull *)(iVar2 + 0x18);
    uVar7 = uVar7 + 1;
    iVar8 = iVar8 + 0x1c;
  } while (uVar7 < 3);
  uVar7 = 0;
  iVar8 = 0;
  do {
    pJVar1 = (J3DIndBlockFull *)(**(code **)(*(int *)param_1 + 0x44))(param_1,uVar7);
    (this + iVar8)[0x6c] = *pJVar1;
    (this + iVar8)[0x6d] = pJVar1[1];
    uVar7 = uVar7 + 1;
    iVar8 = iVar8 + 4;
  } while (uVar7 < 4);
  return;
}


/* __thiscall J3DPEBlockFogOff::reset(J3DPEBlock *) */

void __thiscall J3DPEBlockFogOff::reset(J3DPEBlockFogOff *this,J3DPEBlock *param_1)

{
  int iVar1;
  undefined2 *puVar2;
  J3DPEBlockFogOff *pJVar3;
  J3DPEBlockFogOff JVar4;
  
  iVar1 = (**(code **)(*(int *)param_1 + 0x24))(param_1);
  if ((iVar1 == 0x5045464c) || ((iVar1 < 0x5045464c && (iVar1 == 0x50454647)))) {
    puVar2 = (undefined2 *)(**(code **)(*(int *)param_1 + 0x38))(param_1);
    *(undefined2 *)(this + 4) = *puVar2;
    this[6] = *(J3DPEBlockFogOff *)(puVar2 + 1);
    this[7] = *(J3DPEBlockFogOff *)((int)puVar2 + 3);
    pJVar3 = (J3DPEBlockFogOff *)(**(code **)(*(int *)param_1 + 0x44))(param_1);
    this[8] = *pJVar3;
    this[9] = pJVar3[1];
    this[10] = pJVar3[2];
    this[0xb] = pJVar3[3];
    puVar2 = (undefined2 *)(**(code **)(*(int *)param_1 + 0x50))(param_1);
    *(undefined2 *)(this + 0xc) = *puVar2;
    JVar4 = (J3DPEBlockFogOff)(**(code **)(*(int *)param_1 + 0x5c))(param_1);
    this[0xe] = JVar4;
  }
  return;
}


/* __thiscall J3DPEBlockFull::reset(J3DPEBlock *) */

void __thiscall J3DPEBlockFull::reset(J3DPEBlockFull *this,J3DPEBlock *param_1)

{
  int iVar1;
  byte *pbVar2;
  undefined2 *puVar3;
  short *psVar4;
  byte bVar5;
  
  iVar1 = (**(code **)(*(int *)param_1 + 0x2c))(param_1);
  if (iVar1 != 0) {
    pbVar2 = (byte *)(**(code **)(*(int *)param_1 + 0x2c))(param_1);
    copy_bytes(&this->mpFog->mType,pbVar2,0x2c);
    os::DCStoreRange(this->mpFog,0x2c);
  }
  iVar1 = (**(code **)(*(int *)param_1 + 0x24))(param_1);
  if ((iVar1 == 0x5045464c) || ((iVar1 < 0x5045464c && (iVar1 == 0x50454647)))) {
    puVar3 = (undefined2 *)(**(code **)(*(int *)param_1 + 0x38))(param_1);
    *(undefined2 *)&this->mAlphaComp = *puVar3;
    *(undefined *)((int)&this->mAlphaComp + 2) = *(undefined *)(puVar3 + 1);
    *(undefined *)((int)&this->mAlphaComp + 3) = *(undefined *)((int)puVar3 + 3);
    pbVar2 = (byte *)(**(code **)(*(int *)param_1 + 0x44))(param_1);
    (this->mBlend).field_0x0 = *pbVar2;
    (this->mBlend).field_0x1 = pbVar2[1];
    (this->mBlend).field_0x2 = pbVar2[2];
    (this->mBlend).field_0x3 = pbVar2[3];
    psVar4 = (short *)(**(code **)(*(int *)param_1 + 0x50))(param_1);
    this->mZMode = *psVar4;
    bVar5 = (**(code **)(*(int *)param_1 + 0x5c))(param_1);
    this->mZCompLoc = bVar5;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DTexGenBlockPatched::calc(float const *[][][][]) */

void __thiscall J3DTexGenBlockPatched::calc(J3DTexGenBlockPatched *this,float *param_1)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  MTX34 MStack168;
  MTX34 MStack120;
  MTX34 MStack72;
  
  if (((J3DGraphBase::j3dSys.mCurFlags >> 2 & 1) == 0) ||
     ((J3DGraphBase::j3dSys.mCurFlags & 8) == 0)) {
    iVar5 = 0;
    iVar4 = 0;
    do {
      iVar3 = *(int *)((int)&this[5].vtbl + iVar4);
      if (iVar3 != 0) {
        uVar2 = *(byte *)(iVar3 + 1) & 0x7f;
        if ((uVar2 - 6 < 2) || (uVar2 == 1)) {
          mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,(MTX34 *)param_1,&MStack72);
          MStack72.m[0][3] = J3DGraphBase::_5880;
          MStack72.m[1][3] = J3DGraphBase::_5880;
          MStack72.m[2][3] = J3DGraphBase::_5880;
          mtx::PSMTXCopy(&MStack72,(MTX34 *)(*(int *)((int)&this[5].vtbl + iVar4) + 0x94));
        }
        else {
          if ((uVar2 == 8) || (uVar2 == 2)) {
            mtx::PSMTXCopy((MTX34 *)param_1,(MTX34 *)(iVar3 + 0x94));
          }
          else {
            if ((uVar2 == 9) || (uVar2 == 3)) {
              mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,(MTX34 *)param_1,&MStack120);
              mtx::PSMTXCopy(&MStack120,(MTX34 *)(*(int *)((int)&this[5].vtbl + iVar4) + 0x94));
            }
            else {
              if ((uVar2 - 10 < 2) || (uVar2 == 5)) {
                mtx::PSMTXCopy((MTX34 *)param_1,(MTX34 *)(iVar3 + 0x94));
                fVar1 = J3DGraphBase::_5880;
                *(float *)(*(int *)((int)&this[5].vtbl + iVar4) + 0xa0) = J3DGraphBase::_5880;
                *(float *)(*(int *)((int)&this[5].vtbl + iVar4) + 0xb0) = fVar1;
                *(float *)(*(int *)((int)&this[5].vtbl + iVar4) + 0xc0) = fVar1;
              }
            }
          }
        }
        J3DTexMtx::calc(*(J3DTexMtx **)((int)&this[5].vtbl + iVar4));
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar5 < 8);
  }
  else {
    iVar5 = 0;
    iVar4 = 0;
    do {
      iVar3 = *(int *)((int)&this[5].vtbl + iVar4);
      if (iVar3 != 0) {
        uVar2 = *(byte *)(iVar3 + 1) & 0x7f;
        if ((uVar2 - 6 < 2) || (uVar2 == 1)) {
          mtx::PSMTXCopy(&J3DGraphBase::j3dSys.mCurViewMtx,&MStack168);
          MStack168.m[0][3] = J3DGraphBase::_5880;
          MStack168.m[1][3] = J3DGraphBase::_5880;
          MStack168.m[2][3] = J3DGraphBase::_5880;
          mtx::PSMTXCopy(&MStack168,(MTX34 *)(*(int *)((int)&this[5].vtbl + iVar4) + 0x94));
        }
        else {
          if ((uVar2 == 8) || (uVar2 == 2)) {
            mtx::PSMTXCopy((MTX34 *)&J3DGraphBase::j3dDefaultMtx,(MTX34 *)(iVar3 + 0x94));
          }
          else {
            if ((uVar2 == 9) || (uVar2 == 3)) {
              mtx::PSMTXCopy(&J3DGraphBase::j3dSys.mCurViewMtx,(MTX34 *)(iVar3 + 0x94));
            }
            else {
              if ((uVar2 - 10 < 2) || (uVar2 == 5)) {
                mtx::PSMTXCopy((MTX34 *)&J3DGraphBase::j3dDefaultMtx,(MTX34 *)(iVar3 + 0x94));
              }
            }
          }
        }
        J3DTexMtx::calc(*(J3DTexMtx **)((int)&this[5].vtbl + iVar4));
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar5 < 8);
  }
  return;
}


/* __thiscall J3DTexMtx::load(unsigned long) const */

void __thiscall J3DTexMtx::load(J3DTexMtx *this,ulong param_1)

{
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 0x35U) {
    gd::GDOverflowed();
  }
  J3DGraphBase::J3DGDLoadTexMtxImm
            (&this->mOutputMatrix,param_1 * 3 + 0x1e,(this->mInfo).mProjection);
  return;
}


namespace J3DGraphBase {

/* __stdcall J3DGDLoadTexMtxImm(float *[][][][],
                                unsigned long,
                                _GXTexMtxType) */

void J3DGDLoadTexMtxImm(undefined4 *param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  
  iVar4 = (param_2 & 0x3fff) << 2;
  iVar2 = 0xc;
  if (param_3 == 1) {
    iVar2 = 8;
  }
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0x10;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)(iVar2 + -1) >> 8);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)(iVar2 + -1);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)iVar4 >> 8);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)iVar4;
  uVar1 = *param_1;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 0x18);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 0x10);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 8);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)uVar1;
  uVar1 = param_1[1];
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 0x18);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 0x10);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 8);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)uVar1;
  uVar1 = param_1[2];
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 0x18);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 0x10);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 8);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)uVar1;
  uVar1 = param_1[3];
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 0x18);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 0x10);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 8);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)uVar1;
  uVar1 = param_1[4];
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 0x18);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 0x10);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 8);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)uVar1;
  uVar1 = param_1[5];
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 0x18);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 0x10);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 8);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)uVar1;
  uVar1 = param_1[6];
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 0x18);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 0x10);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 8);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)uVar1;
  uVar1 = param_1[7];
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 0x18);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 0x10);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)((uint)uVar1 >> 8);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)uVar1;
  if (param_3 == 0) {
    uVar1 = param_1[8];
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar1 >> 0x18);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar1 >> 0x10);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar1 >> 8);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)uVar1;
    uVar1 = param_1[9];
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar1 >> 0x18);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar1 >> 0x10);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar1 >> 8);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)uVar1;
    uVar1 = param_1[10];
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar1 >> 0x18);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar1 >> 0x10);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar1 >> 8);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)uVar1;
    uVar1 = param_1[0xb];
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar1 >> 0x18);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar1 >> 0x10);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)((uint)uVar1 >> 8);
    puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
    *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
    *puVar3 = (char)uVar1;
  }
  return;
}

}

/* __thiscall J3DTevBlock::diffTevReg(void) */

void __thiscall J3DTevBlock::diffTevReg(J3DTevBlock *this)

{
  return;
}


/* __thiscall J3DTevBlock::diffTevStageIndirect(void) */

void __thiscall J3DTevBlock::diffTevStageIndirect(J3DTevBlock *this)

{
  return;
}


/* __thiscall J3DTevBlock::diffTevStage(void) */

void __thiscall J3DTevBlock::diffTevStage(J3DTevBlock *this)

{
  return;
}


/* __thiscall J3DTevBlock::diffTexCoordScale(void) */

void __thiscall J3DTevBlock::diffTexCoordScale(J3DTevBlock *this)

{
  return;
}


/* __thiscall J3DTevBlock::diffTexNo(void) */

void __thiscall J3DTevBlock::diffTexNo(J3DTevBlock *this)

{
  return;
}


/* __thiscall J3DPEBlockFull::getType(void) */

undefined4 __thiscall J3DPEBlockFull::getType(J3DPEBlockFull *this)

{
  return 0x5045464c;
}


/* __thiscall J3DPEBlockFull::setFog(J3DFog *) */

void __thiscall J3DPEBlockFull::setFog(J3DPEBlockFull *this,J3DFog *param_1)

{
  this->mpFog = param_1;
  return;
}


/* __thiscall J3DPEBlockFull::getFog(void) */

J3DFog * __thiscall J3DPEBlockFull::getFog(J3DPEBlockFull *this)

{
  return this->mpFog;
}


/* __thiscall J3DPEBlockFull::setAlphaComp(J3DAlphaComp) */

void __thiscall J3DPEBlockFull::setAlphaComp(J3DPEBlockFull *this,J3DAlphaComp param_1)

{
  *(undefined2 *)&this->mAlphaComp = *(undefined2 *)param_1;
  *(undefined *)((int)&this->mAlphaComp + 2) = *(undefined *)(param_1 + 2);
  *(undefined *)((int)&this->mAlphaComp + 3) = *(undefined *)(param_1 + 3);
  return;
}


/* __thiscall J3DPEBlockFull::setAlphaComp(J3DAlphaComp const *) */

void __thiscall J3DPEBlockFull::setAlphaComp(J3DPEBlockFull *this,J3DAlphaComp *param_1)

{
  *(undefined2 *)&this->mAlphaComp = *(undefined2 *)param_1;
  *(undefined *)((int)&this->mAlphaComp + 2) = *(undefined *)((int)param_1 + 2);
  *(undefined *)((int)&this->mAlphaComp + 3) = *(undefined *)((int)param_1 + 3);
  return;
}


/* __thiscall J3DPEBlockFull::getAlphaComp(void) */

J3DAlphaComp * __thiscall J3DPEBlockFull::getAlphaComp(J3DPEBlockFull *this)

{
  return &this->mAlphaComp;
}


/* __thiscall J3DPEBlockFull::setBlend(J3DBlend) */

void __thiscall J3DPEBlockFull::setBlend(J3DPEBlockFull *this,J3DBlend *param_1)

{
  (this->mBlend).field_0x0 = param_1->field_0x0;
  (this->mBlend).field_0x1 = param_1->field_0x1;
  (this->mBlend).field_0x2 = param_1->field_0x2;
  (this->mBlend).field_0x3 = param_1->field_0x3;
  return;
}


/* __thiscall J3DPEBlockFull::setBlend(J3DBlend const *) */

void __thiscall J3DPEBlockFull::setBlend(J3DPEBlockFull *this,J3DBlend *param_1)

{
  (this->mBlend).field_0x0 = *(byte *)param_1;
  (this->mBlend).field_0x1 = *(byte *)((int)param_1 + 1);
  (this->mBlend).field_0x2 = *(byte *)((int)param_1 + 2);
  (this->mBlend).field_0x3 = *(byte *)((int)param_1 + 3);
  return;
}


/* __thiscall J3DPEBlockFull::getBlend(void) */

J3DBlend * __thiscall J3DPEBlockFull::getBlend(J3DPEBlockFull *this)

{
  return &this->mBlend;
}


/* __thiscall J3DPEBlockFull::setZMode(J3DZMode) */

void __thiscall J3DPEBlockFull::setZMode(J3DPEBlockFull *this,J3DZMode param_1)

{
  this->mZMode = *(short *)param_1;
  return;
}


/* __thiscall J3DPEBlockFull::setZMode(J3DZMode const *) */

void __thiscall J3DPEBlockFull::setZMode(J3DPEBlockFull *this,J3DZMode *param_1)

{
  this->mZMode = *(short *)param_1;
  return;
}


/* __thiscall J3DPEBlockFull::getZMode(void) */

short * __thiscall J3DPEBlockFull::getZMode(J3DPEBlockFull *this)

{
  return &this->mZMode;
}


/* __thiscall J3DPEBlockFull::setZCompLoc(unsigned char) */

void __thiscall J3DPEBlockFull::setZCompLoc(J3DPEBlockFull *this,uchar param_1)

{
  this->mZCompLoc = param_1;
  return;
}


/* __thiscall J3DPEBlockFull::setZCompLoc(unsigned char const *) */

void __thiscall J3DPEBlockFull::setZCompLoc(J3DPEBlockFull *this,uchar *param_1)

{
  this->mZCompLoc = *param_1;
  return;
}


/* __thiscall J3DPEBlockFull::getZCompLoc(void) const */

byte __thiscall J3DPEBlockFull::getZCompLoc(J3DPEBlockFull *this)

{
  return this->mZCompLoc;
}


/* __thiscall J3DPEBlockFull::setDither(unsigned char) */

void __thiscall J3DPEBlockFull::setDither(J3DPEBlockFull *this,uchar param_1)

{
  this->mDither = param_1;
  return;
}


/* __thiscall J3DPEBlockFull::setDither(unsigned char const *) */

void __thiscall J3DPEBlockFull::setDither(J3DPEBlockFull *this,uchar *param_1)

{
  this->mDither = *param_1;
  return;
}


/* __thiscall J3DPEBlockFull::getDither(void) const */

byte __thiscall J3DPEBlockFull::getDither(J3DPEBlockFull *this)

{
  return this->mDither;
}


/* __thiscall J3DPEBlockFull::getFogOffset(void) const */

undefined * __thiscall J3DPEBlockFull::getFogOffset(J3DPEBlockFull *this)

{
  return this[1].vtbl;
}


/* __thiscall J3DPEBlockFull::setFogOffset(unsigned long) */

void __thiscall J3DPEBlockFull::setFogOffset(J3DPEBlockFull *this,ulong param_1)

{
  this[1].vtbl = (undefined *)param_1;
  return;
}


/* __thiscall J3DPEBlockFull::~J3DPEBlockFull(void) */

void __thiscall J3DPEBlockFull::_J3DPEBlockFull(J3DPEBlockFull *this)

{
  short in_r4;
  
  if (this != (J3DPEBlockFull *)0x0) {
    this->vtbl = &__vt;
    if (this != (J3DPEBlockFull *)0x0) {
      this->vtbl = &J3DPEBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DPEBlockFogOff::diff(unsigned long) */

void __thiscall J3DPEBlockFogOff::diff(J3DPEBlockFogOff *this,ulong param_1)

{
  if ((param_1 & 0x20000000) != 0) {
    (**(code **)(*(int *)this + 0x1c))();
  }
  return;
}


/* __thiscall J3DPEBlockFogOff::getType(void) */

undefined4 __thiscall J3DPEBlockFogOff::getType(J3DPEBlockFogOff *this)

{
  return 0x50454647;
}


/* __thiscall J3DPEBlockFogOff::setAlphaComp(J3DAlphaComp) */

void __thiscall J3DPEBlockFogOff::setAlphaComp(J3DPEBlockFogOff *this,J3DAlphaComp param_1)

{
  *(undefined2 *)(this + 4) = *(undefined2 *)param_1;
  this[6] = *(J3DPEBlockFogOff *)(param_1 + 2);
  this[7] = *(J3DPEBlockFogOff *)(param_1 + 3);
  return;
}


/* __thiscall J3DPEBlockFogOff::setAlphaComp(J3DAlphaComp const *) */

void __thiscall J3DPEBlockFogOff::setAlphaComp(J3DPEBlockFogOff *this,J3DAlphaComp *param_1)

{
  *(undefined2 *)(this + 4) = *(undefined2 *)param_1;
  this[6] = *(J3DPEBlockFogOff *)((int)param_1 + 2);
  this[7] = *(J3DPEBlockFogOff *)((int)param_1 + 3);
  return;
}


/* __thiscall J3DPEBlockFogOff::getAlphaComp(void) */

J3DPEBlockFogOff * __thiscall J3DPEBlockFogOff::getAlphaComp(J3DPEBlockFogOff *this)

{
  return this + 4;
}


/* __thiscall J3DPEBlockFogOff::setBlend(J3DBlend) */

void __thiscall J3DPEBlockFogOff::setBlend(J3DPEBlockFogOff *this,J3DBlend param_1)

{
  this[8] = *(J3DPEBlockFogOff *)param_1;
  this[9] = *(J3DPEBlockFogOff *)(param_1 + 1);
  this[10] = *(J3DPEBlockFogOff *)(param_1 + 2);
  this[0xb] = *(J3DPEBlockFogOff *)(param_1 + 3);
  return;
}


/* __thiscall J3DPEBlockFogOff::setBlend(J3DBlend const *) */

void __thiscall J3DPEBlockFogOff::setBlend(J3DPEBlockFogOff *this,J3DBlend *param_1)

{
  this[8] = *(J3DPEBlockFogOff *)param_1;
  this[9] = *(J3DPEBlockFogOff *)((int)param_1 + 1);
  this[10] = *(J3DPEBlockFogOff *)((int)param_1 + 2);
  this[0xb] = *(J3DPEBlockFogOff *)((int)param_1 + 3);
  return;
}


/* __thiscall J3DPEBlockFogOff::getBlend(void) */

J3DPEBlockFogOff * __thiscall J3DPEBlockFogOff::getBlend(J3DPEBlockFogOff *this)

{
  return this + 8;
}


/* __thiscall J3DPEBlockFogOff::setZMode(J3DZMode) */

void __thiscall J3DPEBlockFogOff::setZMode(J3DPEBlockFogOff *this,J3DZMode param_1)

{
  *(undefined2 *)(this + 0xc) = *(undefined2 *)param_1;
  return;
}


/* __thiscall J3DPEBlockFogOff::setZMode(J3DZMode const *) */

void __thiscall J3DPEBlockFogOff::setZMode(J3DPEBlockFogOff *this,J3DZMode *param_1)

{
  *(undefined2 *)(this + 0xc) = *(undefined2 *)param_1;
  return;
}


/* __thiscall J3DPEBlockFogOff::getZMode(void) */

J3DPEBlockFogOff * __thiscall J3DPEBlockFogOff::getZMode(J3DPEBlockFogOff *this)

{
  return this + 0xc;
}


/* __thiscall J3DPEBlockFogOff::setZCompLoc(unsigned char) */

void __thiscall J3DPEBlockFogOff::setZCompLoc(J3DPEBlockFogOff *this,uchar param_1)

{
  this[0xe] = (J3DPEBlockFogOff)param_1;
  return;
}


/* __thiscall J3DPEBlockFogOff::setZCompLoc(unsigned char const *) */

void __thiscall J3DPEBlockFogOff::setZCompLoc(J3DPEBlockFogOff *this,uchar *param_1)

{
  this[0xe] = (J3DPEBlockFogOff)*param_1;
  return;
}


/* __thiscall J3DPEBlockFogOff::getZCompLoc(void) const */

J3DPEBlockFogOff __thiscall J3DPEBlockFogOff::getZCompLoc(J3DPEBlockFogOff *this)

{
  return this[0xe];
}


/* __thiscall J3DPEBlockFogOff::setDither(unsigned char) */

void __thiscall J3DPEBlockFogOff::setDither(J3DPEBlockFogOff *this,uchar param_1)

{
  this[0xf] = (J3DPEBlockFogOff)param_1;
  return;
}


/* __thiscall J3DPEBlockFogOff::setDither(unsigned char const *) */

void __thiscall J3DPEBlockFogOff::setDither(J3DPEBlockFogOff *this,uchar *param_1)

{
  this[0xf] = (J3DPEBlockFogOff)*param_1;
  return;
}


/* __thiscall J3DPEBlockFogOff::getDither(void) const */

J3DPEBlockFogOff __thiscall J3DPEBlockFogOff::getDither(J3DPEBlockFogOff *this)

{
  return this[0xf];
}


/* __thiscall J3DPEBlockFogOff::~J3DPEBlockFogOff(void) */

void __thiscall J3DPEBlockFogOff::_J3DPEBlockFogOff(J3DPEBlockFogOff *this)

{
  short in_r4;
  
  if (this != (J3DPEBlockFogOff *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DPEBlockFogOff *)0x0) {
      *(undefined1 **)this = &J3DPEBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DTevBlock16::indexToPtr(void) */

void __thiscall J3DTevBlock16::indexToPtr(J3DTevBlock16 *this)

{
  J3DTevBlock::indexToPtr_private((J3DTevBlock *)this,*(ulong *)(this + 4));
  return;
}


/* __thiscall J3DTevBlock16::getType(void) */

undefined4 __thiscall J3DTevBlock16::getType(J3DTevBlock16 *this)

{
  return 0x54563136;
}


/* __thiscall J3DTevBlock16::setTexNo(unsigned long,
                                      unsigned short) */

void __thiscall J3DTevBlock16::setTexNo(J3DTevBlock16 *this,ulong param_1,ushort param_2)

{
  *(ushort *)(this + param_1 * 2 + 8) = param_2;
  return;
}


/* __thiscall J3DTevBlock16::setTexNo(unsigned long,
                                      unsigned short const *) */

void __thiscall J3DTevBlock16::setTexNo(J3DTevBlock16 *this,ulong param_1,ushort *param_2)

{
  *(ushort *)(this + param_1 * 2 + 8) = *param_2;
  return;
}


/* __thiscall J3DTevBlock16::getTexNo(unsigned long) const */

undefined2 __thiscall J3DTevBlock16::getTexNo(J3DTevBlock16 *this,ulong param_1)

{
  return *(undefined2 *)(this + param_1 * 2 + 8);
}


/* __thiscall J3DTevBlock16::setTevOrder(unsigned long,
                                         J3DTevOrder) */

void __thiscall J3DTevBlock16::setTevOrder(J3DTevBlock16 *this,ulong param_1,J3DTevOrder param_2)

{
  J3DTevBlock16 *pJVar1;
  undefined3 in_register_00000014;
  J3DTevBlock16 *pJVar2;
  
  pJVar2 = (J3DTevBlock16 *)CONCAT31(in_register_00000014,param_2);
  pJVar1 = this + param_1 * 4;
  pJVar1[0x18] = *pJVar2;
  pJVar1[0x19] = pJVar2[1];
  pJVar1[0x1a] = pJVar2[2];
  return;
}


/* __thiscall J3DTevBlock16::setTevOrder(unsigned long,
                                         J3DTevOrder const *) */

void __thiscall J3DTevBlock16::setTevOrder(J3DTevBlock16 *this,ulong param_1,J3DTevOrder *param_2)

{
  J3DTevBlock16 *pJVar1;
  
  pJVar1 = this + param_1 * 4;
  pJVar1[0x18] = *(J3DTevBlock16 *)param_2;
  pJVar1[0x19] = *(J3DTevBlock16 *)(param_2 + 1);
  pJVar1[0x1a] = *(J3DTevBlock16 *)(param_2 + 2);
  return;
}


/* __thiscall J3DTevBlock16::getTevOrder(unsigned long) */

J3DTevBlock16 * __thiscall J3DTevBlock16::getTevOrder(J3DTevBlock16 *this,ulong param_1)

{
  return this + param_1 * 4 + 0x18;
}


/* __thiscall J3DTevBlock16::setTevColor(unsigned long,
                                         J3DGXColorS10) */

void __thiscall J3DTevBlock16::setTevColor(J3DTevBlock16 *this,ulong param_1,J3DGXColorS10 param_2)

{
  J3DTevBlock16 *pJVar1;
  undefined3 in_register_00000014;
  undefined2 *puVar2;
  
  puVar2 = (undefined2 *)CONCAT31(in_register_00000014,param_2);
  pJVar1 = this + param_1 * 8;
  *(undefined2 *)(pJVar1 + 0xda) = *puVar2;
  *(undefined2 *)(pJVar1 + 0xdc) = puVar2[1];
  *(undefined2 *)(pJVar1 + 0xde) = puVar2[2];
  *(undefined2 *)(pJVar1 + 0xe0) = puVar2[3];
  return;
}


/* __thiscall J3DTevBlock16::setTevColor(unsigned long,
                                         J3DGXColorS10 const *) */

void __thiscall J3DTevBlock16::setTevColor(J3DTevBlock16 *this,ulong param_1,J3DGXColorS10 *param_2)

{
  J3DTevBlock16 *pJVar1;
  
  pJVar1 = this + param_1 * 8;
  *(undefined2 *)(pJVar1 + 0xda) = *(undefined2 *)param_2;
  *(undefined2 *)(pJVar1 + 0xdc) = *(undefined2 *)(param_2 + 2);
  *(undefined2 *)(pJVar1 + 0xde) = *(undefined2 *)(param_2 + 4);
  *(undefined2 *)(pJVar1 + 0xe0) = *(undefined2 *)(param_2 + 6);
  return;
}


/* __thiscall J3DTevBlock16::getTevColor(unsigned long) */

J3DTevBlock16 * __thiscall J3DTevBlock16::getTevColor(J3DTevBlock16 *this,ulong param_1)

{
  return this + param_1 * 8 + 0xda;
}


/* __thiscall J3DTevBlock16::setTevKColor(unsigned long,
                                          J3DGXColor) */

void __thiscall J3DTevBlock16::setTevKColor(J3DTevBlock16 *this,ulong param_1,J3DGXColor param_2)

{
  J3DTevBlock16 *pJVar1;
  
  pJVar1 = this + param_1 * 4;
  pJVar1[0xfa] = *param_2;
  pJVar1[0xfb] = param_2[1];
  pJVar1[0xfc] = param_2[2];
  pJVar1[0xfd] = param_2[3];
  return;
}


/* __thiscall J3DTevBlock16::setTevKColor(unsigned long,
                                          J3DGXColor const *) */

void __thiscall J3DTevBlock16::setTevKColor(J3DTevBlock16 *this,ulong param_1,J3DGXColor *param_2)

{
  J3DTevBlock16 *pJVar1;
  
  pJVar1 = this + param_1 * 4;
  pJVar1[0xfa] = *(J3DTevBlock16 *)&(param_2->v).r;
  pJVar1[0xfb] = *(J3DTevBlock16 *)&(param_2->v).g;
  pJVar1[0xfc] = *(J3DTevBlock16 *)&(param_2->v).b;
  pJVar1[0xfd] = *(J3DTevBlock16 *)&(param_2->v).a;
  return;
}


/* __thiscall J3DTevBlock16::getTevKColor(unsigned long) */

J3DTevBlock16 * __thiscall J3DTevBlock16::getTevKColor(J3DTevBlock16 *this,ulong param_1)

{
  return this + param_1 * 4 + 0xfa;
}


/* __thiscall J3DTevBlock16::setTevKColorSel(unsigned long,
                                             unsigned char) */

void __thiscall J3DTevBlock16::setTevKColorSel(J3DTevBlock16 *this,ulong param_1,uchar param_2)

{
  this[param_1 + 0x10a] = (J3DTevBlock16)param_2;
  return;
}


/* __thiscall J3DTevBlock16::setTevKColorSel(unsigned long,
                                             unsigned char const *) */

void __thiscall J3DTevBlock16::setTevKColorSel(J3DTevBlock16 *this,ulong param_1,uchar *param_2)

{
  this[param_1 + 0x10a] = (J3DTevBlock16)*param_2;
  return;
}


/* __thiscall J3DTevBlock16::getTevKColorSel(unsigned long) */

J3DTevBlock16 __thiscall J3DTevBlock16::getTevKColorSel(J3DTevBlock16 *this,ulong param_1)

{
  return this[param_1 + 0x10a];
}


/* __thiscall J3DTevBlock16::setTevKAlphaSel(unsigned long,
                                             unsigned char) */

void __thiscall J3DTevBlock16::setTevKAlphaSel(J3DTevBlock16 *this,ulong param_1,uchar param_2)

{
  this[param_1 + 0x11a] = (J3DTevBlock16)param_2;
  return;
}


/* __thiscall J3DTevBlock16::setTevKAlphaSel(unsigned long,
                                             unsigned char const *) */

void __thiscall J3DTevBlock16::setTevKAlphaSel(J3DTevBlock16 *this,ulong param_1,uchar *param_2)

{
  this[param_1 + 0x11a] = (J3DTevBlock16)*param_2;
  return;
}


/* __thiscall J3DTevBlock16::getTevKAlphaSel(unsigned long) */

J3DTevBlock16 __thiscall J3DTevBlock16::getTevKAlphaSel(J3DTevBlock16 *this,ulong param_1)

{
  return this[param_1 + 0x11a];
}


/* __thiscall J3DTevBlock16::setTevStageNum(unsigned char) */

void __thiscall J3DTevBlock16::setTevStageNum(J3DTevBlock16 *this,uchar param_1)

{
  this[0x58] = (J3DTevBlock16)param_1;
  return;
}


/* __thiscall J3DTevBlock16::setTevStageNum(unsigned char const *) */

void __thiscall J3DTevBlock16::setTevStageNum(J3DTevBlock16 *this,uchar *param_1)

{
  this[0x58] = (J3DTevBlock16)*param_1;
  return;
}


/* __thiscall J3DTevBlock16::getTevStageNum(void) const */

J3DTevBlock16 __thiscall J3DTevBlock16::getTevStageNum(J3DTevBlock16 *this)

{
  return this[0x58];
}


/* __thiscall J3DTevBlock16::setTevStage(unsigned long,
                                         J3DTevStage) */

void __thiscall J3DTevBlock16::setTevStage(J3DTevBlock16 *this,ulong param_1,undefined param_2)

{
  J3DTevBlock16 *pJVar1;
  undefined3 in_register_00000014;
  int iVar2;
  
  iVar2 = CONCAT31(in_register_00000014,param_2);
  pJVar1 = this + param_1 * 8;
  pJVar1[0x5a] = *(J3DTevBlock16 *)(iVar2 + 1);
  pJVar1[0x5b] = *(J3DTevBlock16 *)(iVar2 + 2);
  pJVar1[0x5c] = *(J3DTevBlock16 *)(iVar2 + 3);
  pJVar1[0x5e] = *(J3DTevBlock16 *)(iVar2 + 5);
  pJVar1[0x5f] = *(J3DTevBlock16 *)(iVar2 + 6);
  pJVar1[0x60] = *(J3DTevBlock16 *)(iVar2 + 7);
  return;
}


/* __thiscall J3DTevBlock16::setTevStage(unsigned long,
                                         J3DTevStage const *) */

void __thiscall J3DTevBlock16::setTevStage(J3DTevBlock16 *this,ulong param_1,undefined param_2)

{
  J3DTevBlock16 *pJVar1;
  undefined3 in_register_00000014;
  int iVar2;
  
  iVar2 = CONCAT31(in_register_00000014,param_2);
  pJVar1 = this + param_1 * 8;
  pJVar1[0x5a] = *(J3DTevBlock16 *)(iVar2 + 1);
  pJVar1[0x5b] = *(J3DTevBlock16 *)(iVar2 + 2);
  pJVar1[0x5c] = *(J3DTevBlock16 *)(iVar2 + 3);
  pJVar1[0x5e] = *(J3DTevBlock16 *)(iVar2 + 5);
  pJVar1[0x5f] = *(J3DTevBlock16 *)(iVar2 + 6);
  pJVar1[0x60] = *(J3DTevBlock16 *)(iVar2 + 7);
  return;
}


/* __thiscall J3DTevBlock16::getTevStage(unsigned long) */

J3DTevBlock16 * __thiscall J3DTevBlock16::getTevStage(J3DTevBlock16 *this,ulong param_1)

{
  return this + param_1 * 8 + 0x59;
}


/* __thiscall J3DTevBlock16::setTevSwapModeInfo(unsigned long,
                                                J3DTevSwapModeInfo) */

void __thiscall
J3DTevBlock16::setTevSwapModeInfo(J3DTevBlock16 *this,ulong param_1,J3DTevSwapModeInfo param_2)

{
  J3DTevBlock16 *pJVar1;
  
  pJVar1 = this + param_1 * 8;
  pJVar1[0x60] = (J3DTevBlock16)((byte)pJVar1[0x60] & 0xf3 | *(char *)(param_2 + 1) << 2);
  pJVar1[0x60] = (J3DTevBlock16)((byte)pJVar1[0x60] & 0xfc | *(byte *)param_2);
  return;
}


/* __thiscall J3DTevBlock16::setTevSwapModeInfo(unsigned long,
                                                J3DTevSwapModeInfo const *) */

void __thiscall
J3DTevBlock16::setTevSwapModeInfo(J3DTevBlock16 *this,ulong param_1,J3DTevSwapModeInfo *param_2)

{
  J3DTevBlock16 *pJVar1;
  
  pJVar1 = this + param_1 * 8;
  pJVar1[0x60] = (J3DTevBlock16)((byte)pJVar1[0x60] & 0xf3 | *(char *)((int)param_2 + 1) << 2);
  pJVar1[0x60] = (J3DTevBlock16)((byte)pJVar1[0x60] & 0xfc | *(byte *)param_2);
  return;
}


/* __thiscall J3DTevBlock16::setTevSwapModeTable(unsigned long,
                                                 J3DTevSwapModeTable) */

void __thiscall
J3DTevBlock16::setTevSwapModeTable(J3DTevBlock16 *this,ulong param_1,J3DTevSwapModeTable param_2)

{
  undefined3 in_register_00000014;
  
  this[param_1 + 0x12a] = *(J3DTevBlock16 *)CONCAT31(in_register_00000014,param_2);
  return;
}


/* __thiscall J3DTevBlock16::setTevSwapModeTable(unsigned long,
                                                 J3DTevSwapModeTable const *) */

void __thiscall
J3DTevBlock16::setTevSwapModeTable(J3DTevBlock16 *this,ulong param_1,J3DTevSwapModeTable *param_2)

{
  this[param_1 + 0x12a] = *(J3DTevBlock16 *)param_2;
  return;
}


/* __thiscall J3DTevBlock16::getTevSwapModeTable(unsigned long) */

J3DTevBlock16 * __thiscall J3DTevBlock16::getTevSwapModeTable(J3DTevBlock16 *this,ulong param_1)

{
  return this + param_1 + 0x12a;
}


/* __thiscall J3DTevBlock16::setIndTevStage(unsigned long,
                                            J3DIndTevStage) */

void __thiscall
J3DTevBlock16::setIndTevStage(J3DTevBlock16 *this,ulong param_1,J3DIndTevStage param_2)

{
  undefined3 in_register_00000014;
  
  *(undefined4 *)(this + param_1 * 4 + 0x130) =
       *(undefined4 *)CONCAT31(in_register_00000014,param_2);
  return;
}


/* __thiscall J3DTevBlock16::setIndTevStage(unsigned long,
                                            J3DIndTevStage const *) */

void __thiscall
J3DTevBlock16::setIndTevStage(J3DTevBlock16 *this,ulong param_1,J3DIndTevStage *param_2)

{
  *(undefined4 *)(this + param_1 * 4 + 0x130) = *(undefined4 *)param_2;
  return;
}


/* __thiscall J3DTevBlock16::getIndTevStage(unsigned long) */

J3DTevBlock16 * __thiscall J3DTevBlock16::getIndTevStage(J3DTevBlock16 *this,ulong param_1)

{
  return this + param_1 * 4 + 0x130;
}


/* __thiscall J3DTevBlock16::getTexNoOffset(void) const */

undefined4 __thiscall J3DTevBlock16::getTexNoOffset(J3DTevBlock16 *this)

{
  return *(undefined4 *)(this + 4);
}


/* __thiscall J3DTevBlock16::getTevRegOffset(void) const */

undefined4 __thiscall J3DTevBlock16::getTevRegOffset(J3DTevBlock16 *this)

{
  return *(undefined4 *)(this + 0x170);
}


/* __thiscall J3DTevBlock16::setTevRegOffset(unsigned long) */

void __thiscall J3DTevBlock16::setTevRegOffset(J3DTevBlock16 *this,ulong param_1)

{
  *(ulong *)(this + 0x170) = param_1;
  return;
}


/* __thiscall J3DTevBlock16::~J3DTevBlock16(void) */

void __thiscall J3DTevBlock16::_J3DTevBlock16(J3DTevBlock16 *this)

{
  short in_r4;
  
  if (this != (J3DTevBlock16 *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DTevBlock16 *)0x0) {
      *(undefined ***)this = &J3DTevBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DTevBlock::setTexNoOffset(unsigned long) */

void __thiscall J3DTevBlock::setTexNoOffset(J3DTevBlock *this,ulong param_1)

{
  this[1].vtbl = (J3DTevBlock__vtbl *)param_1;
  return;
}


/* __thiscall J3DTevBlock4::ptrToIndex(void) */

void __thiscall J3DTevBlock4::ptrToIndex(J3DTevBlock4 *this)

{
  return;
}


/* __thiscall J3DTevBlock4::indexToPtr(void) */

void __thiscall J3DTevBlock4::indexToPtr(J3DTevBlock4 *this)

{
  J3DTevBlock::indexToPtr_private((J3DTevBlock *)this,*(ulong *)(this + 4));
  return;
}


/* __thiscall J3DTevBlock4::getType(void) */

undefined4 __thiscall J3DTevBlock4::getType(J3DTevBlock4 *this)

{
  return 0x54564234;
}


/* __thiscall J3DTevBlock4::setTexNo(unsigned long,
                                     unsigned short) */

void __thiscall J3DTevBlock4::setTexNo(J3DTevBlock4 *this,ulong param_1,ushort param_2)

{
  *(ushort *)(this + param_1 * 2 + 8) = param_2;
  return;
}


/* __thiscall J3DTevBlock4::setTexNo(unsigned long,
                                     unsigned short const *) */

void __thiscall J3DTevBlock4::setTexNo(J3DTevBlock4 *this,ulong param_1,ushort *param_2)

{
  *(ushort *)(this + param_1 * 2 + 8) = *param_2;
  return;
}


/* __thiscall J3DTevBlock4::getTexNo(unsigned long) const */

undefined2 __thiscall J3DTevBlock4::getTexNo(J3DTevBlock4 *this,ulong param_1)

{
  return *(undefined2 *)(this + param_1 * 2 + 8);
}


/* __thiscall J3DTevBlock4::setTevOrder(unsigned long,
                                        J3DTevOrder) */

void __thiscall J3DTevBlock4::setTevOrder(J3DTevBlock4 *this,ulong param_1,J3DTevOrder param_2)

{
  J3DTevBlock4 *pJVar1;
  undefined3 in_register_00000014;
  J3DTevBlock4 *pJVar2;
  
  pJVar2 = (J3DTevBlock4 *)CONCAT31(in_register_00000014,param_2);
  pJVar1 = this + param_1 * 4;
  pJVar1[0x10] = *pJVar2;
  pJVar1[0x11] = pJVar2[1];
  pJVar1[0x12] = pJVar2[2];
  return;
}


/* __thiscall J3DTevBlock4::setTevOrder(unsigned long,
                                        J3DTevOrder const *) */

void __thiscall J3DTevBlock4::setTevOrder(J3DTevBlock4 *this,ulong param_1,J3DTevOrder *param_2)

{
  J3DTevBlock4 *pJVar1;
  
  pJVar1 = this + param_1 * 4;
  pJVar1[0x10] = *(J3DTevBlock4 *)param_2;
  pJVar1[0x11] = *(J3DTevBlock4 *)(param_2 + 1);
  pJVar1[0x12] = *(J3DTevBlock4 *)(param_2 + 2);
  return;
}


/* __thiscall J3DTevBlock4::getTevOrder(unsigned long) */

J3DTevBlock4 * __thiscall J3DTevBlock4::getTevOrder(J3DTevBlock4 *this,ulong param_1)

{
  return this + param_1 * 4 + 0x10;
}


/* __thiscall J3DTevBlock4::setTevColor(unsigned long,
                                        J3DGXColorS10) */

void __thiscall J3DTevBlock4::setTevColor(J3DTevBlock4 *this,ulong param_1,J3DGXColorS10 param_2)

{
  J3DTevBlock4 *pJVar1;
  undefined3 in_register_00000014;
  undefined2 *puVar2;
  
  puVar2 = (undefined2 *)CONCAT31(in_register_00000014,param_2);
  pJVar1 = this + param_1 * 8;
  *(undefined2 *)(pJVar1 + 0x42) = *puVar2;
  *(undefined2 *)(pJVar1 + 0x44) = puVar2[1];
  *(undefined2 *)(pJVar1 + 0x46) = puVar2[2];
  *(undefined2 *)(pJVar1 + 0x48) = puVar2[3];
  return;
}


/* __thiscall J3DTevBlock4::setTevColor(unsigned long,
                                        J3DGXColorS10 const *) */

void __thiscall J3DTevBlock4::setTevColor(J3DTevBlock4 *this,ulong param_1,J3DGXColorS10 *param_2)

{
  J3DTevBlock4 *pJVar1;
  
  pJVar1 = this + param_1 * 8;
  *(undefined2 *)(pJVar1 + 0x42) = *(undefined2 *)param_2;
  *(undefined2 *)(pJVar1 + 0x44) = *(undefined2 *)(param_2 + 2);
  *(undefined2 *)(pJVar1 + 0x46) = *(undefined2 *)(param_2 + 4);
  *(undefined2 *)(pJVar1 + 0x48) = *(undefined2 *)(param_2 + 6);
  return;
}


/* __thiscall J3DTevBlock4::getTevColor(unsigned long) */

J3DTevBlock4 * __thiscall J3DTevBlock4::getTevColor(J3DTevBlock4 *this,ulong param_1)

{
  return this + param_1 * 8 + 0x42;
}


/* __thiscall J3DTevBlock4::setTevKColor(unsigned long,
                                         J3DGXColor) */

void __thiscall J3DTevBlock4::setTevKColor(J3DTevBlock4 *this,ulong param_1,J3DGXColor param_2)

{
  J3DTevBlock4 *pJVar1;
  
  pJVar1 = this + param_1 * 4;
  pJVar1[0x62] = *param_2;
  pJVar1[99] = param_2[1];
  pJVar1[100] = param_2[2];
  pJVar1[0x65] = param_2[3];
  return;
}


/* __thiscall J3DTevBlock4::setTevKColor(unsigned long,
                                         J3DGXColor const *) */

void __thiscall J3DTevBlock4::setTevKColor(J3DTevBlock4 *this,ulong param_1,J3DGXColor *param_2)

{
  J3DTevBlock4 *pJVar1;
  
  pJVar1 = this + param_1 * 4;
  pJVar1[0x62] = *(J3DTevBlock4 *)&(param_2->v).r;
  pJVar1[99] = *(J3DTevBlock4 *)&(param_2->v).g;
  pJVar1[100] = *(J3DTevBlock4 *)&(param_2->v).b;
  pJVar1[0x65] = *(J3DTevBlock4 *)&(param_2->v).a;
  return;
}


/* __thiscall J3DTevBlock4::getTevKColor(unsigned long) */

J3DTevBlock4 * __thiscall J3DTevBlock4::getTevKColor(J3DTevBlock4 *this,ulong param_1)

{
  return this + param_1 * 4 + 0x62;
}


/* __thiscall J3DTevBlock4::setTevKColorSel(unsigned long,
                                            unsigned char) */

void __thiscall J3DTevBlock4::setTevKColorSel(J3DTevBlock4 *this,ulong param_1,uchar param_2)

{
  this[param_1 + 0x72] = (J3DTevBlock4)param_2;
  return;
}


/* __thiscall J3DTevBlock4::setTevKColorSel(unsigned long,
                                            unsigned char const *) */

void __thiscall J3DTevBlock4::setTevKColorSel(J3DTevBlock4 *this,ulong param_1,uchar *param_2)

{
  this[param_1 + 0x72] = (J3DTevBlock4)*param_2;
  return;
}


/* __thiscall J3DTevBlock4::getTevKColorSel(unsigned long) */

J3DTevBlock4 __thiscall J3DTevBlock4::getTevKColorSel(J3DTevBlock4 *this,ulong param_1)

{
  return this[param_1 + 0x72];
}


/* __thiscall J3DTevBlock4::setTevKAlphaSel(unsigned long,
                                            unsigned char) */

void __thiscall J3DTevBlock4::setTevKAlphaSel(J3DTevBlock4 *this,ulong param_1,uchar param_2)

{
  this[param_1 + 0x76] = (J3DTevBlock4)param_2;
  return;
}


/* __thiscall J3DTevBlock4::setTevKAlphaSel(unsigned long,
                                            unsigned char const *) */

void __thiscall J3DTevBlock4::setTevKAlphaSel(J3DTevBlock4 *this,ulong param_1,uchar *param_2)

{
  this[param_1 + 0x76] = (J3DTevBlock4)*param_2;
  return;
}


/* __thiscall J3DTevBlock4::getTevKAlphaSel(unsigned long) */

J3DTevBlock4 __thiscall J3DTevBlock4::getTevKAlphaSel(J3DTevBlock4 *this,ulong param_1)

{
  return this[param_1 + 0x76];
}


/* __thiscall J3DTevBlock4::setTevStageNum(unsigned char) */

void __thiscall J3DTevBlock4::setTevStageNum(J3DTevBlock4 *this,uchar param_1)

{
  this[0x20] = (J3DTevBlock4)param_1;
  return;
}


/* __thiscall J3DTevBlock4::setTevStageNum(unsigned char const *) */

void __thiscall J3DTevBlock4::setTevStageNum(J3DTevBlock4 *this,uchar *param_1)

{
  this[0x20] = (J3DTevBlock4)*param_1;
  return;
}


/* __thiscall J3DTevBlock4::getTevStageNum(void) const */

J3DTevBlock4 __thiscall J3DTevBlock4::getTevStageNum(J3DTevBlock4 *this)

{
  return this[0x20];
}


/* __thiscall J3DTevBlock4::setTevStage(unsigned long,
                                        J3DTevStage) */

void __thiscall J3DTevBlock4::setTevStage(J3DTevBlock4 *this,ulong param_1,undefined param_2)

{
  J3DTevBlock4 *pJVar1;
  undefined3 in_register_00000014;
  int iVar2;
  
  iVar2 = CONCAT31(in_register_00000014,param_2);
  pJVar1 = this + param_1 * 8;
  pJVar1[0x22] = *(J3DTevBlock4 *)(iVar2 + 1);
  pJVar1[0x23] = *(J3DTevBlock4 *)(iVar2 + 2);
  pJVar1[0x24] = *(J3DTevBlock4 *)(iVar2 + 3);
  pJVar1[0x26] = *(J3DTevBlock4 *)(iVar2 + 5);
  pJVar1[0x27] = *(J3DTevBlock4 *)(iVar2 + 6);
  pJVar1[0x28] = *(J3DTevBlock4 *)(iVar2 + 7);
  return;
}


/* __thiscall J3DTevBlock4::setTevStage(unsigned long,
                                        J3DTevStage const *) */

void __thiscall J3DTevBlock4::setTevStage(J3DTevBlock4 *this,ulong param_1,undefined param_2)

{
  J3DTevBlock4 *pJVar1;
  undefined3 in_register_00000014;
  int iVar2;
  
  iVar2 = CONCAT31(in_register_00000014,param_2);
  pJVar1 = this + param_1 * 8;
  pJVar1[0x22] = *(J3DTevBlock4 *)(iVar2 + 1);
  pJVar1[0x23] = *(J3DTevBlock4 *)(iVar2 + 2);
  pJVar1[0x24] = *(J3DTevBlock4 *)(iVar2 + 3);
  pJVar1[0x26] = *(J3DTevBlock4 *)(iVar2 + 5);
  pJVar1[0x27] = *(J3DTevBlock4 *)(iVar2 + 6);
  pJVar1[0x28] = *(J3DTevBlock4 *)(iVar2 + 7);
  return;
}


/* __thiscall J3DTevBlock4::getTevStage(unsigned long) */

J3DTevBlock4 * __thiscall J3DTevBlock4::getTevStage(J3DTevBlock4 *this,ulong param_1)

{
  return this + param_1 * 8 + 0x21;
}


/* __thiscall J3DTevBlock4::setTevSwapModeInfo(unsigned long,
                                               J3DTevSwapModeInfo) */

void __thiscall
J3DTevBlock4::setTevSwapModeInfo(J3DTevBlock4 *this,ulong param_1,J3DTevSwapModeInfo param_2)

{
  J3DTevBlock4 *pJVar1;
  
  pJVar1 = this + param_1 * 8;
  pJVar1[0x28] = (J3DTevBlock4)((byte)pJVar1[0x28] & 0xf3 | *(char *)(param_2 + 1) << 2);
  pJVar1[0x28] = (J3DTevBlock4)((byte)pJVar1[0x28] & 0xfc | *(byte *)param_2);
  return;
}


/* __thiscall J3DTevBlock4::setTevSwapModeInfo(unsigned long,
                                               J3DTevSwapModeInfo const *) */

void __thiscall
J3DTevBlock4::setTevSwapModeInfo(J3DTevBlock4 *this,ulong param_1,J3DTevSwapModeInfo *param_2)

{
  J3DTevBlock4 *pJVar1;
  
  pJVar1 = this + param_1 * 8;
  pJVar1[0x28] = (J3DTevBlock4)((byte)pJVar1[0x28] & 0xf3 | *(char *)((int)param_2 + 1) << 2);
  pJVar1[0x28] = (J3DTevBlock4)((byte)pJVar1[0x28] & 0xfc | *(byte *)param_2);
  return;
}


/* __thiscall J3DTevBlock4::setTevSwapModeTable(unsigned long,
                                                J3DTevSwapModeTable) */

void __thiscall
J3DTevBlock4::setTevSwapModeTable(J3DTevBlock4 *this,ulong param_1,J3DTevSwapModeTable param_2)

{
  undefined3 in_register_00000014;
  
  this[param_1 + 0x7a] = *(J3DTevBlock4 *)CONCAT31(in_register_00000014,param_2);
  return;
}


/* __thiscall J3DTevBlock4::setTevSwapModeTable(unsigned long,
                                                J3DTevSwapModeTable const *) */

void __thiscall
J3DTevBlock4::setTevSwapModeTable(J3DTevBlock4 *this,ulong param_1,J3DTevSwapModeTable *param_2)

{
  this[param_1 + 0x7a] = *(J3DTevBlock4 *)param_2;
  return;
}


/* __thiscall J3DTevBlock4::getTevSwapModeTable(unsigned long) */

J3DTevBlock4 * __thiscall J3DTevBlock4::getTevSwapModeTable(J3DTevBlock4 *this,ulong param_1)

{
  return this + param_1 + 0x7a;
}


/* __thiscall J3DTevBlock4::setIndTevStage(unsigned long,
                                           J3DIndTevStage) */

void __thiscall
J3DTevBlock4::setIndTevStage(J3DTevBlock4 *this,ulong param_1,J3DIndTevStage param_2)

{
  undefined3 in_register_00000014;
  
  *(undefined4 *)(this + param_1 * 4 + 0x80) = *(undefined4 *)CONCAT31(in_register_00000014,param_2)
  ;
  return;
}


/* __thiscall J3DTevBlock4::setIndTevStage(unsigned long,
                                           J3DIndTevStage const *) */

void __thiscall
J3DTevBlock4::setIndTevStage(J3DTevBlock4 *this,ulong param_1,J3DIndTevStage *param_2)

{
  *(undefined4 *)(this + param_1 * 4 + 0x80) = *(undefined4 *)param_2;
  return;
}


/* __thiscall J3DTevBlock4::getIndTevStage(unsigned long) */

J3DTevBlock4 * __thiscall J3DTevBlock4::getIndTevStage(J3DTevBlock4 *this,ulong param_1)

{
  return this + param_1 * 4 + 0x80;
}


/* __thiscall J3DTevBlock4::getTexNoOffset(void) const */

undefined4 __thiscall J3DTevBlock4::getTexNoOffset(J3DTevBlock4 *this)

{
  return *(undefined4 *)(this + 4);
}


/* __thiscall J3DTevBlock4::getTevRegOffset(void) const */

undefined4 __thiscall J3DTevBlock4::getTevRegOffset(J3DTevBlock4 *this)

{
  return *(undefined4 *)(this + 0x90);
}


/* __thiscall J3DTevBlock4::setTevRegOffset(unsigned long) */

void __thiscall J3DTevBlock4::setTevRegOffset(J3DTevBlock4 *this,ulong param_1)

{
  *(ulong *)(this + 0x90) = param_1;
  return;
}


/* __thiscall J3DTevBlock4::~J3DTevBlock4(void) */

void __thiscall J3DTevBlock4::_J3DTevBlock4(J3DTevBlock4 *this)

{
  short in_r4;
  
  if (this != (J3DTevBlock4 *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DTevBlock4 *)0x0) {
      *(undefined ***)this = &J3DTevBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DTevBlock2::ptrToIndex(void) */

void __thiscall J3DTevBlock2::ptrToIndex(J3DTevBlock2 *this)

{
  return;
}


/* __thiscall J3DTevBlock2::indexToPtr(void) */

void __thiscall J3DTevBlock2::indexToPtr(J3DTevBlock2 *this)

{
  J3DTevBlock::indexToPtr_private((J3DTevBlock *)this,*(ulong *)(this + 4));
  return;
}


/* __thiscall J3DTevBlock2::getType(void) */

undefined4 __thiscall J3DTevBlock2::getType(J3DTevBlock2 *this)

{
  return 0x54564232;
}


/* __thiscall J3DTevBlock2::setTexNo(unsigned long,
                                     unsigned short) */

void __thiscall J3DTevBlock2::setTexNo(J3DTevBlock2 *this,ulong param_1,ushort param_2)

{
  *(ushort *)(this + param_1 * 2 + 8) = param_2;
  return;
}


/* __thiscall J3DTevBlock2::setTexNo(unsigned long,
                                     unsigned short const *) */

void __thiscall J3DTevBlock2::setTexNo(J3DTevBlock2 *this,ulong param_1,ushort *param_2)

{
  *(ushort *)(this + param_1 * 2 + 8) = *param_2;
  return;
}


/* __thiscall J3DTevBlock2::getTexNo(unsigned long) const */

undefined2 __thiscall J3DTevBlock2::getTexNo(J3DTevBlock2 *this,ulong param_1)

{
  return *(undefined2 *)(this + param_1 * 2 + 8);
}


/* __thiscall J3DTevBlock2::setTevOrder(unsigned long,
                                        J3DTevOrder) */

void __thiscall J3DTevBlock2::setTevOrder(J3DTevBlock2 *this,ulong param_1,J3DTevOrder param_2)

{
  J3DTevBlock2 *pJVar1;
  undefined3 in_register_00000014;
  J3DTevBlock2 *pJVar2;
  
  pJVar2 = (J3DTevBlock2 *)CONCAT31(in_register_00000014,param_2);
  pJVar1 = this + param_1 * 4;
  pJVar1[0xc] = *pJVar2;
  pJVar1[0xd] = pJVar2[1];
  pJVar1[0xe] = pJVar2[2];
  return;
}


/* __thiscall J3DTevBlock2::setTevOrder(unsigned long,
                                        J3DTevOrder const *) */

void __thiscall J3DTevBlock2::setTevOrder(J3DTevBlock2 *this,ulong param_1,J3DTevOrder *param_2)

{
  J3DTevBlock2 *pJVar1;
  
  pJVar1 = this + param_1 * 4;
  pJVar1[0xc] = *(J3DTevBlock2 *)param_2;
  pJVar1[0xd] = *(J3DTevBlock2 *)(param_2 + 1);
  pJVar1[0xe] = *(J3DTevBlock2 *)(param_2 + 2);
  return;
}


/* __thiscall J3DTevBlock2::getTevOrder(unsigned long) */

J3DTevBlock2 * __thiscall J3DTevBlock2::getTevOrder(J3DTevBlock2 *this,ulong param_1)

{
  return this + param_1 * 4 + 0xc;
}


/* __thiscall J3DTevBlock2::setTevColor(unsigned long,
                                        J3DGXColorS10) */

void __thiscall J3DTevBlock2::setTevColor(J3DTevBlock2 *this,ulong param_1,J3DGXColorS10 param_2)

{
  J3DTevBlock2 *pJVar1;
  undefined3 in_register_00000014;
  undefined2 *puVar2;
  
  puVar2 = (undefined2 *)CONCAT31(in_register_00000014,param_2);
  pJVar1 = this + param_1 * 8;
  *(undefined2 *)(pJVar1 + 0x14) = *puVar2;
  *(undefined2 *)(pJVar1 + 0x16) = puVar2[1];
  *(undefined2 *)(pJVar1 + 0x18) = puVar2[2];
  *(undefined2 *)(pJVar1 + 0x1a) = puVar2[3];
  return;
}


/* __thiscall J3DTevBlock2::setTevColor(unsigned long,
                                        J3DGXColorS10 const *) */

void __thiscall J3DTevBlock2::setTevColor(J3DTevBlock2 *this,ulong param_1,J3DGXColorS10 *param_2)

{
  J3DTevBlock2 *pJVar1;
  
  pJVar1 = this + param_1 * 8;
  *(undefined2 *)(pJVar1 + 0x14) = *(undefined2 *)param_2;
  *(undefined2 *)(pJVar1 + 0x16) = *(undefined2 *)(param_2 + 2);
  *(undefined2 *)(pJVar1 + 0x18) = *(undefined2 *)(param_2 + 4);
  *(undefined2 *)(pJVar1 + 0x1a) = *(undefined2 *)(param_2 + 6);
  return;
}


/* __thiscall J3DTevBlock2::getTevColor(unsigned long) */

J3DTevBlock2 * __thiscall J3DTevBlock2::getTevColor(J3DTevBlock2 *this,ulong param_1)

{
  return this + param_1 * 8 + 0x14;
}


/* __thiscall J3DTevBlock2::setTevKColor(unsigned long,
                                         J3DGXColor) */

void __thiscall J3DTevBlock2::setTevKColor(J3DTevBlock2 *this,ulong param_1,J3DGXColor param_2)

{
  J3DTevBlock2 *pJVar1;
  
  pJVar1 = this + param_1 * 4;
  pJVar1[0x45] = *param_2;
  pJVar1[0x46] = param_2[1];
  pJVar1[0x47] = param_2[2];
  pJVar1[0x48] = param_2[3];
  return;
}


/* __thiscall J3DTevBlock2::setTevKColor(unsigned long,
                                         J3DGXColor const *) */

void __thiscall J3DTevBlock2::setTevKColor(J3DTevBlock2 *this,ulong param_1,J3DGXColor *param_2)

{
  J3DTevBlock2 *pJVar1;
  
  pJVar1 = this + param_1 * 4;
  pJVar1[0x45] = *(J3DTevBlock2 *)&(param_2->v).r;
  pJVar1[0x46] = *(J3DTevBlock2 *)&(param_2->v).g;
  pJVar1[0x47] = *(J3DTevBlock2 *)&(param_2->v).b;
  pJVar1[0x48] = *(J3DTevBlock2 *)&(param_2->v).a;
  return;
}


/* __thiscall J3DTevBlock2::getTevKColor(unsigned long) */

J3DTevBlock2 * __thiscall J3DTevBlock2::getTevKColor(J3DTevBlock2 *this,ulong param_1)

{
  return this + param_1 * 4 + 0x45;
}


/* __thiscall J3DTevBlock2::setTevKColorSel(unsigned long,
                                            unsigned char) */

void __thiscall J3DTevBlock2::setTevKColorSel(J3DTevBlock2 *this,ulong param_1,uchar param_2)

{
  this[param_1 + 0x55] = (J3DTevBlock2)param_2;
  return;
}


/* __thiscall J3DTevBlock2::setTevKColorSel(unsigned long,
                                            unsigned char const *) */

void __thiscall J3DTevBlock2::setTevKColorSel(J3DTevBlock2 *this,ulong param_1,uchar *param_2)

{
  this[param_1 + 0x55] = (J3DTevBlock2)*param_2;
  return;
}


/* __thiscall J3DTevBlock2::getTevKColorSel(unsigned long) */

J3DTevBlock2 __thiscall J3DTevBlock2::getTevKColorSel(J3DTevBlock2 *this,ulong param_1)

{
  return this[param_1 + 0x55];
}


/* __thiscall J3DTevBlock2::setTevKAlphaSel(unsigned long,
                                            unsigned char) */

void __thiscall J3DTevBlock2::setTevKAlphaSel(J3DTevBlock2 *this,ulong param_1,uchar param_2)

{
  this[param_1 + 0x57] = (J3DTevBlock2)param_2;
  return;
}


/* __thiscall J3DTevBlock2::setTevKAlphaSel(unsigned long,
                                            unsigned char const *) */

void __thiscall J3DTevBlock2::setTevKAlphaSel(J3DTevBlock2 *this,ulong param_1,uchar *param_2)

{
  this[param_1 + 0x57] = (J3DTevBlock2)*param_2;
  return;
}


/* __thiscall J3DTevBlock2::getTevKAlphaSel(unsigned long) */

J3DTevBlock2 __thiscall J3DTevBlock2::getTevKAlphaSel(J3DTevBlock2 *this,ulong param_1)

{
  return this[param_1 + 0x57];
}


/* __thiscall J3DTevBlock2::setTevStageNum(unsigned char) */

void __thiscall J3DTevBlock2::setTevStageNum(J3DTevBlock2 *this,uchar param_1)

{
  this[0x34] = (J3DTevBlock2)param_1;
  return;
}


/* __thiscall J3DTevBlock2::setTevStageNum(unsigned char const *) */

void __thiscall J3DTevBlock2::setTevStageNum(J3DTevBlock2 *this,uchar *param_1)

{
  this[0x34] = (J3DTevBlock2)*param_1;
  return;
}


/* __thiscall J3DTevBlock2::getTevStageNum(void) const */

J3DTevBlock2 __thiscall J3DTevBlock2::getTevStageNum(J3DTevBlock2 *this)

{
  return this[0x34];
}


/* __thiscall J3DTevBlock2::setTevStage(unsigned long,
                                        J3DTevStage) */

void __thiscall J3DTevBlock2::setTevStage(J3DTevBlock2 *this,ulong param_1,undefined param_2)

{
  J3DTevBlock2 *pJVar1;
  undefined3 in_register_00000014;
  int iVar2;
  
  iVar2 = CONCAT31(in_register_00000014,param_2);
  pJVar1 = this + param_1 * 8;
  pJVar1[0x36] = *(J3DTevBlock2 *)(iVar2 + 1);
  pJVar1[0x37] = *(J3DTevBlock2 *)(iVar2 + 2);
  pJVar1[0x38] = *(J3DTevBlock2 *)(iVar2 + 3);
  pJVar1[0x3a] = *(J3DTevBlock2 *)(iVar2 + 5);
  pJVar1[0x3b] = *(J3DTevBlock2 *)(iVar2 + 6);
  pJVar1[0x3c] = *(J3DTevBlock2 *)(iVar2 + 7);
  return;
}


/* __thiscall J3DTevBlock2::setTevStage(unsigned long,
                                        J3DTevStage const *) */

void __thiscall J3DTevBlock2::setTevStage(J3DTevBlock2 *this,ulong param_1,undefined param_2)

{
  J3DTevBlock2 *pJVar1;
  undefined3 in_register_00000014;
  int iVar2;
  
  iVar2 = CONCAT31(in_register_00000014,param_2);
  pJVar1 = this + param_1 * 8;
  pJVar1[0x36] = *(J3DTevBlock2 *)(iVar2 + 1);
  pJVar1[0x37] = *(J3DTevBlock2 *)(iVar2 + 2);
  pJVar1[0x38] = *(J3DTevBlock2 *)(iVar2 + 3);
  pJVar1[0x3a] = *(J3DTevBlock2 *)(iVar2 + 5);
  pJVar1[0x3b] = *(J3DTevBlock2 *)(iVar2 + 6);
  pJVar1[0x3c] = *(J3DTevBlock2 *)(iVar2 + 7);
  return;
}


/* __thiscall J3DTevBlock2::getTevStage(unsigned long) */

J3DTevBlock2 * __thiscall J3DTevBlock2::getTevStage(J3DTevBlock2 *this,ulong param_1)

{
  return this + param_1 * 8 + 0x35;
}


/* __thiscall J3DTevBlock2::setTevSwapModeInfo(unsigned long,
                                               J3DTevSwapModeInfo) */

void __thiscall
J3DTevBlock2::setTevSwapModeInfo(J3DTevBlock2 *this,ulong param_1,J3DTevSwapModeInfo param_2)

{
  J3DTevBlock2 *pJVar1;
  
  pJVar1 = this + param_1 * 8;
  pJVar1[0x3c] = (J3DTevBlock2)((byte)pJVar1[0x3c] & 0xf3 | *(char *)(param_2 + 1) << 2);
  pJVar1[0x3c] = (J3DTevBlock2)((byte)pJVar1[0x3c] & 0xfc | *(byte *)param_2);
  return;
}


/* __thiscall J3DTevBlock2::setTevSwapModeInfo(unsigned long,
                                               J3DTevSwapModeInfo const *) */

void __thiscall
J3DTevBlock2::setTevSwapModeInfo(J3DTevBlock2 *this,ulong param_1,J3DTevSwapModeInfo *param_2)

{
  J3DTevBlock2 *pJVar1;
  
  pJVar1 = this + param_1 * 8;
  pJVar1[0x3c] = (J3DTevBlock2)((byte)pJVar1[0x3c] & 0xf3 | *(char *)((int)param_2 + 1) << 2);
  pJVar1[0x3c] = (J3DTevBlock2)((byte)pJVar1[0x3c] & 0xfc | *(byte *)param_2);
  return;
}


/* __thiscall J3DTevBlock2::setTevSwapModeTable(unsigned long,
                                                J3DTevSwapModeTable) */

void __thiscall
J3DTevBlock2::setTevSwapModeTable(J3DTevBlock2 *this,ulong param_1,J3DTevSwapModeTable param_2)

{
  undefined3 in_register_00000014;
  
  this[param_1 + 0x59] = *(J3DTevBlock2 *)CONCAT31(in_register_00000014,param_2);
  return;
}


/* __thiscall J3DTevBlock2::setTevSwapModeTable(unsigned long,
                                                J3DTevSwapModeTable const *) */

void __thiscall
J3DTevBlock2::setTevSwapModeTable(J3DTevBlock2 *this,ulong param_1,J3DTevSwapModeTable *param_2)

{
  this[param_1 + 0x59] = *(J3DTevBlock2 *)param_2;
  return;
}


/* __thiscall J3DTevBlock2::getTevSwapModeTable(unsigned long) */

J3DTevBlock2 * __thiscall J3DTevBlock2::getTevSwapModeTable(J3DTevBlock2 *this,ulong param_1)

{
  return this + param_1 + 0x59;
}


/* __thiscall J3DTevBlock2::setIndTevStage(unsigned long,
                                           J3DIndTevStage) */

void __thiscall
J3DTevBlock2::setIndTevStage(J3DTevBlock2 *this,ulong param_1,J3DIndTevStage param_2)

{
  undefined3 in_register_00000014;
  
  *(undefined4 *)(this + param_1 * 4 + 0x60) = *(undefined4 *)CONCAT31(in_register_00000014,param_2)
  ;
  return;
}


/* __thiscall J3DTevBlock2::setIndTevStage(unsigned long,
                                           J3DIndTevStage const *) */

void __thiscall
J3DTevBlock2::setIndTevStage(J3DTevBlock2 *this,ulong param_1,J3DIndTevStage *param_2)

{
  *(undefined4 *)(this + param_1 * 4 + 0x60) = *(undefined4 *)param_2;
  return;
}


/* __thiscall J3DTevBlock2::getIndTevStage(unsigned long) */

J3DTevBlock2 * __thiscall J3DTevBlock2::getIndTevStage(J3DTevBlock2 *this,ulong param_1)

{
  return this + param_1 * 4 + 0x60;
}


/* __thiscall J3DTevBlock2::getTexNoOffset(void) const */

undefined4 __thiscall J3DTevBlock2::getTexNoOffset(J3DTevBlock2 *this)

{
  return *(undefined4 *)(this + 4);
}


/* __thiscall J3DTevBlock2::getTevRegOffset(void) const */

undefined4 __thiscall J3DTevBlock2::getTevRegOffset(J3DTevBlock2 *this)

{
  return *(undefined4 *)(this + 0x68);
}


/* __thiscall J3DTevBlock2::setTevRegOffset(unsigned long) */

void __thiscall J3DTevBlock2::setTevRegOffset(J3DTevBlock2 *this,ulong param_1)

{
  *(ulong *)(this + 0x68) = param_1;
  return;
}


/* __thiscall J3DTevBlock2::~J3DTevBlock2(void) */

void __thiscall J3DTevBlock2::_J3DTevBlock2(J3DTevBlock2 *this)

{
  short in_r4;
  
  if (this != (J3DTevBlock2 *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DTevBlock2 *)0x0) {
      *(undefined ***)this = &J3DTevBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DTevBlock1::ptrToIndex(void) */

void __thiscall J3DTevBlock1::ptrToIndex(J3DTevBlock1 *this)

{
  return;
}


/* __thiscall J3DTevBlock1::indexToPtr(void) */

void __thiscall J3DTevBlock1::indexToPtr(J3DTevBlock1 *this)

{
  J3DTevBlock::indexToPtr_private((J3DTevBlock *)this,*(ulong *)(this + 4));
  return;
}


/* __thiscall J3DTevBlock1::getType(void) */

undefined4 __thiscall J3DTevBlock1::getType(J3DTevBlock1 *this)

{
  return 0x54564231;
}


/* __thiscall J3DTevBlock1::setTexNo(unsigned long,
                                     unsigned short) */

void __thiscall J3DTevBlock1::setTexNo(J3DTevBlock1 *this,ulong param_1,ushort param_2)

{
  *(ushort *)(this + param_1 * 2 + 8) = param_2;
  return;
}


/* __thiscall J3DTevBlock1::setTexNo(unsigned long,
                                     unsigned short const *) */

void __thiscall J3DTevBlock1::setTexNo(J3DTevBlock1 *this,ulong param_1,ushort *param_2)

{
  *(ushort *)(this + param_1 * 2 + 8) = *param_2;
  return;
}


/* __thiscall J3DTevBlock1::getTexNo(unsigned long) const */

undefined2 __thiscall J3DTevBlock1::getTexNo(J3DTevBlock1 *this,ulong param_1)

{
  return *(undefined2 *)(this + param_1 * 2 + 8);
}


/* __thiscall J3DTevBlock1::setTevOrder(unsigned long,
                                        J3DTevOrder) */

void __thiscall J3DTevBlock1::setTevOrder(J3DTevBlock1 *this,ulong param_1,J3DTevOrder param_2)

{
  J3DTevBlock1 *pJVar1;
  undefined3 in_register_00000014;
  J3DTevBlock1 *pJVar2;
  
  pJVar2 = (J3DTevBlock1 *)CONCAT31(in_register_00000014,param_2);
  pJVar1 = this + param_1 * 4;
  pJVar1[10] = *pJVar2;
  pJVar1[0xb] = pJVar2[1];
  pJVar1[0xc] = pJVar2[2];
  return;
}


/* __thiscall J3DTevBlock1::setTevOrder(unsigned long,
                                        J3DTevOrder const *) */

void __thiscall J3DTevBlock1::setTevOrder(J3DTevBlock1 *this,ulong param_1,J3DTevOrder *param_2)

{
  J3DTevBlock1 *pJVar1;
  
  pJVar1 = this + param_1 * 4;
  pJVar1[10] = *(J3DTevBlock1 *)param_2;
  pJVar1[0xb] = *(J3DTevBlock1 *)(param_2 + 1);
  pJVar1[0xc] = *(J3DTevBlock1 *)(param_2 + 2);
  return;
}


/* __thiscall J3DTevBlock1::getTevOrder(unsigned long) */

J3DTevBlock1 * __thiscall J3DTevBlock1::getTevOrder(J3DTevBlock1 *this,ulong param_1)

{
  return this + param_1 * 4 + 10;
}


/* __thiscall J3DTevBlock1::setTevStageNum(unsigned char) */

void __thiscall J3DTevBlock1::setTevStageNum(J3DTevBlock1 *this,uchar param_1)

{
  return;
}


/* __thiscall J3DTevBlock1::setTevStageNum(unsigned char const *) */

void __thiscall J3DTevBlock1::setTevStageNum(J3DTevBlock1 *this,uchar *param_1)

{
  return;
}


/* __thiscall J3DTevBlock1::getTevStageNum(void) const */

undefined4 __thiscall J3DTevBlock1::getTevStageNum(J3DTevBlock1 *this)

{
  return 1;
}


/* __thiscall J3DTevBlock1::setTevStage(unsigned long,
                                        J3DTevStage) */

void __thiscall J3DTevBlock1::setTevStage(J3DTevBlock1 *this,ulong param_1,undefined param_2)

{
  J3DTevBlock1 *pJVar1;
  undefined3 in_register_00000014;
  int iVar2;
  
  iVar2 = CONCAT31(in_register_00000014,param_2);
  pJVar1 = this + param_1 * 8;
  pJVar1[0xf] = *(J3DTevBlock1 *)(iVar2 + 1);
  pJVar1[0x10] = *(J3DTevBlock1 *)(iVar2 + 2);
  pJVar1[0x11] = *(J3DTevBlock1 *)(iVar2 + 3);
  pJVar1[0x13] = *(J3DTevBlock1 *)(iVar2 + 5);
  pJVar1[0x14] = *(J3DTevBlock1 *)(iVar2 + 6);
  pJVar1[0x15] = *(J3DTevBlock1 *)(iVar2 + 7);
  return;
}


/* __thiscall J3DTevBlock1::setTevStage(unsigned long,
                                        J3DTevStage const *) */

void __thiscall J3DTevBlock1::setTevStage(J3DTevBlock1 *this,ulong param_1,undefined param_2)

{
  J3DTevBlock1 *pJVar1;
  undefined3 in_register_00000014;
  int iVar2;
  
  iVar2 = CONCAT31(in_register_00000014,param_2);
  pJVar1 = this + param_1 * 8;
  pJVar1[0xf] = *(J3DTevBlock1 *)(iVar2 + 1);
  pJVar1[0x10] = *(J3DTevBlock1 *)(iVar2 + 2);
  pJVar1[0x11] = *(J3DTevBlock1 *)(iVar2 + 3);
  pJVar1[0x13] = *(J3DTevBlock1 *)(iVar2 + 5);
  pJVar1[0x14] = *(J3DTevBlock1 *)(iVar2 + 6);
  pJVar1[0x15] = *(J3DTevBlock1 *)(iVar2 + 7);
  return;
}


/* __thiscall J3DTevBlock1::getTevStage(unsigned long) */

J3DTevBlock1 * __thiscall J3DTevBlock1::getTevStage(J3DTevBlock1 *this,ulong param_1)

{
  return this + param_1 * 8 + 0xe;
}


/* __thiscall J3DTevBlock1::setIndTevStage(unsigned long,
                                           J3DIndTevStage) */

void __thiscall
J3DTevBlock1::setIndTevStage(J3DTevBlock1 *this,ulong param_1,J3DIndTevStage param_2)

{
  undefined3 in_register_00000014;
  
  *(undefined4 *)(this + param_1 * 4 + 0x18) = *(undefined4 *)CONCAT31(in_register_00000014,param_2)
  ;
  return;
}


/* __thiscall J3DTevBlock1::setIndTevStage(unsigned long,
                                           J3DIndTevStage const *) */

void __thiscall
J3DTevBlock1::setIndTevStage(J3DTevBlock1 *this,ulong param_1,J3DIndTevStage *param_2)

{
  *(undefined4 *)(this + param_1 * 4 + 0x18) = *(undefined4 *)param_2;
  return;
}


/* __thiscall J3DTevBlock1::getIndTevStage(unsigned long) */

J3DTevBlock1 * __thiscall J3DTevBlock1::getIndTevStage(J3DTevBlock1 *this,ulong param_1)

{
  return this + param_1 * 4 + 0x18;
}


/* __thiscall J3DTevBlock1::getTexNoOffset(void) const */

undefined4 __thiscall J3DTevBlock1::getTexNoOffset(J3DTevBlock1 *this)

{
  return *(undefined4 *)(this + 4);
}


/* __thiscall J3DTevBlock1::~J3DTevBlock1(void) */

void __thiscall J3DTevBlock1::_J3DTevBlock1(J3DTevBlock1 *this)

{
  short in_r4;
  
  if (this != (J3DTevBlock1 *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DTevBlock1 *)0x0) {
      *(undefined ***)this = &J3DTevBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DTevBlock::setTevKColorSel(unsigned long,
                                           unsigned char const *) */

void __thiscall J3DTevBlock::setTevKColorSel(J3DTevBlock *this,ulong param_1,uchar *param_2)

{
  return;
}


/* __thiscall J3DTevBlock::setTevKAlphaSel(unsigned long,
                                           unsigned char const *) */

void __thiscall J3DTevBlock::setTevKAlphaSel(J3DTevBlock *this,ulong param_1,uchar *param_2)

{
  return;
}


/* __thiscall J3DTevBlock::setTevSwapModeInfo(unsigned long,
                                              J3DTevSwapModeInfo) */

void __thiscall
J3DTevBlock::setTevSwapModeInfo(J3DTevBlock *this,ulong param_1,J3DTevSwapModeInfo param_2)

{
  return;
}


/* __thiscall J3DTevBlock::setTevSwapModeInfo(unsigned long,
                                              J3DTevSwapModeInfo const *) */

void __thiscall
J3DTevBlock::setTevSwapModeInfo(J3DTevBlock *this,ulong param_1,J3DTevSwapModeInfo *param_2)

{
  return;
}


/* __thiscall J3DTevBlock::setTevSwapModeTable(unsigned long,
                                               J3DTevSwapModeTable const *) */

void __thiscall
J3DTevBlock::setTevSwapModeTable(J3DTevBlock *this,ulong param_1,J3DTevSwapModeTable *param_2)

{
  return;
}


/* __thiscall J3DTevBlock::getTevRegOffset(void) const */

undefined4 __thiscall J3DTevBlock::getTevRegOffset(J3DTevBlock *this)

{
  return 0;
}


/* __thiscall J3DTevBlock::setTevRegOffset(unsigned long) */

void __thiscall J3DTevBlock::setTevRegOffset(J3DTevBlock *this,ulong param_1)

{
  return;
}


/* __thiscall J3DTevBlockPatched::load(void) */

void __thiscall J3DTevBlockPatched::load(J3DTevBlockPatched *this)

{
  return;
}


/* __thiscall J3DTevBlockPatched::indexToPtr(void) */

void __thiscall J3DTevBlockPatched::indexToPtr(J3DTevBlockPatched *this)

{
  J3DTevBlock::indexToPtr_private((J3DTevBlock *)this,*(ulong *)&this->field_0x4);
  return;
}


/* __thiscall J3DTevBlockPatched::getType(void) */

undefined4 __thiscall J3DTevBlockPatched::getType(J3DTevBlockPatched *this)

{
  return 0x54565054;
}


/* __thiscall J3DTevBlockPatched::setTevStageNum(unsigned char) */

void __thiscall J3DTevBlockPatched::setTevStageNum(J3DTevBlockPatched *this,uchar param_1)

{
  this->mTevStageNum = param_1;
  return;
}


/* __thiscall J3DTevBlockPatched::setTevStageNum(unsigned char const *) */

void __thiscall J3DTevBlockPatched::setTevStageNum(J3DTevBlockPatched *this,uchar *param_1)

{
  this->mTevStageNum = *param_1;
  return;
}


/* __thiscall J3DTevBlockPatched::getTevStageNum(void) const */

byte __thiscall J3DTevBlockPatched::getTevStageNum(J3DTevBlockPatched *this)

{
  return this->mTevStageNum;
}


/* __thiscall J3DTevBlockPatched::setTexNo(unsigned long,
                                           unsigned short) */

void __thiscall J3DTevBlockPatched::setTexNo(J3DTevBlockPatched *this,ulong param_1,ushort param_2)

{
  this->mTexNo[param_1] = param_2;
  return;
}


/* __thiscall J3DTevBlockPatched::setTexNo(unsigned long,
                                           unsigned short const *) */

void __thiscall J3DTevBlockPatched::setTexNo(J3DTevBlockPatched *this,ulong param_1,ushort *param_2)

{
  this->mTexNo[param_1] = *param_2;
  return;
}


/* __thiscall J3DTevBlockPatched::getTexNo(unsigned long) const */

ushort __thiscall J3DTevBlockPatched::getTexNo(J3DTevBlockPatched *this,ulong param_1)

{
  return this->mTexNo[param_1];
}


/* __thiscall J3DTevBlockPatched::setTevOrder(unsigned long,
                                              J3DTevOrder) */

void __thiscall
J3DTevBlockPatched::setTevOrder(J3DTevBlockPatched *this,ulong param_1,J3DTevOrder param_2)

{
  ushort *puVar1;
  undefined3 in_register_00000014;
  undefined *puVar2;
  
  puVar2 = (undefined *)CONCAT31(in_register_00000014,param_2);
  puVar1 = this->mTexNo + param_1 * 2 + -4;
  *(undefined *)(puVar1 + 0xc) = *puVar2;
  *(undefined *)((int)puVar1 + 0x19) = puVar2[1];
  *(undefined *)(puVar1 + 0xd) = puVar2[2];
  return;
}


/* __thiscall J3DTevBlockPatched::setTevOrder(unsigned long,
                                              J3DTevOrder const *) */

void __thiscall
J3DTevBlockPatched::setTevOrder(J3DTevBlockPatched *this,ulong param_1,J3DTevOrder *param_2)

{
  ushort *puVar1;
  
  puVar1 = this->mTexNo + param_1 * 2 + -4;
  *(J3DTevOrder *)(puVar1 + 0xc) = *param_2;
  *(J3DTevOrder *)((int)puVar1 + 0x19) = param_2[1];
  *(J3DTevOrder *)(puVar1 + 0xd) = param_2[2];
  return;
}


/* __thiscall J3DTevBlockPatched::getTevOrder(unsigned long) */

J3DTevOrder * __thiscall J3DTevBlockPatched::getTevOrder(J3DTevBlockPatched *this,ulong param_1)

{
  return this->mTevOrder + param_1;
}


/* __thiscall J3DTevBlockPatched::setTevStage(unsigned long,
                                              J3DTevStage) */

void __thiscall
J3DTevBlockPatched::setTevStage(J3DTevBlockPatched *this,ulong param_1,J3DTevStage *param_2)

{
  ushort *puVar1;
  
  puVar1 = this->mTexNo + param_1 * 4 + -4;
  *(byte *)((int)puVar1 + 0x39) = param_2->field_0x1;
  *(byte *)(puVar1 + 0x1d) = param_2->field_0x2;
  *(byte *)((int)puVar1 + 0x3b) = param_2->field_0x3;
  *(byte *)((int)puVar1 + 0x3d) = param_2->field_0x5;
  *(byte *)(puVar1 + 0x1f) = param_2->field_0x6;
  *(byte *)((int)puVar1 + 0x3f) = param_2->field_0x7;
  return;
}


/* __thiscall J3DTevBlockPatched::setTevStage(unsigned long,
                                              J3DTevStage const *) */

void __thiscall
J3DTevBlockPatched::setTevStage(J3DTevBlockPatched *this,ulong param_1,J3DTevStage *param_2)

{
  ushort *puVar1;
  
  puVar1 = this->mTexNo + param_1 * 4 + -4;
  *(byte *)((int)puVar1 + 0x39) = param_2->field_0x1;
  *(byte *)(puVar1 + 0x1d) = param_2->field_0x2;
  *(byte *)((int)puVar1 + 0x3b) = param_2->field_0x3;
  *(byte *)((int)puVar1 + 0x3d) = param_2->field_0x5;
  *(byte *)(puVar1 + 0x1f) = param_2->field_0x6;
  *(byte *)((int)puVar1 + 0x3f) = param_2->field_0x7;
  return;
}


/* __thiscall J3DTevBlockPatched::getTevStage(unsigned long) */

J3DTevStage * __thiscall J3DTevBlockPatched::getTevStage(J3DTevBlockPatched *this,ulong param_1)

{
  return this->mTevStages + param_1;
}


/* __thiscall J3DTevBlockPatched::setIndTevStage(unsigned long,
                                                 J3DIndTevStage) */

void __thiscall
J3DTevBlockPatched::setIndTevStage(J3DTevBlockPatched *this,ulong param_1,J3DIndTevStage param_2)

{
  undefined3 in_register_00000014;
  
  this->mIndStages[param_1] = *(int *)CONCAT31(in_register_00000014,param_2);
  return;
}


/* __thiscall J3DTevBlockPatched::setIndTevStage(unsigned long,
                                                 J3DIndTevStage const *) */

void __thiscall
J3DTevBlockPatched::setIndTevStage(J3DTevBlockPatched *this,ulong param_1,J3DIndTevStage *param_2)

{
  this->mIndStages[param_1] = *(int *)param_2;
  return;
}


/* __thiscall J3DTevBlockPatched::getIndTevStage(unsigned long) */

int * __thiscall J3DTevBlockPatched::getIndTevStage(J3DTevBlockPatched *this,ulong param_1)

{
  return this->mIndStages + param_1;
}


/* __thiscall J3DTevBlockPatched::setTevColor(unsigned long,
                                              J3DGXColorS10) */

void __thiscall
J3DTevBlockPatched::setTevColor(J3DTevBlockPatched *this,ulong param_1,J3DGXColorS10 param_2)

{
  ushort *puVar1;
  undefined3 in_register_00000014;
  ushort *puVar2;
  
  puVar2 = (ushort *)CONCAT31(in_register_00000014,param_2);
  puVar1 = this->mTexNo + param_1 * 4 + -4;
  puVar1[0x4c] = *puVar2;
  puVar1[0x4d] = puVar2[1];
  puVar1[0x4e] = puVar2[2];
  puVar1[0x4f] = puVar2[3];
  return;
}


/* __thiscall J3DTevBlockPatched::setTevColor(unsigned long,
                                              J3DGXColorS10 const *) */

void __thiscall
J3DTevBlockPatched::setTevColor(J3DTevBlockPatched *this,ulong param_1,J3DGXColorS10 *param_2)

{
  ushort *puVar1;
  
  puVar1 = this->mTexNo + param_1 * 4 + -4;
  puVar1[0x4c] = *(ushort *)param_2;
  puVar1[0x4d] = *(ushort *)(param_2 + 2);
  puVar1[0x4e] = *(ushort *)(param_2 + 4);
  puVar1[0x4f] = *(ushort *)(param_2 + 6);
  return;
}


/* __thiscall J3DTevBlockPatched::getTevColor(unsigned long) */

_GXColorS10 * __thiscall J3DTevBlockPatched::getTevColor(J3DTevBlockPatched *this,ulong param_1)

{
  return this->mTevColor + param_1;
}


/* __thiscall J3DTevBlockPatched::setTevKColor(unsigned long,
                                               J3DGXColor) */

void __thiscall
J3DTevBlockPatched::setTevKColor(J3DTevBlockPatched *this,ulong param_1,J3DGXColor param_2)

{
  ushort *puVar1;
  
  puVar1 = this->mTexNo + param_1 * 2 + -4;
  *(undefined *)(puVar1 + 0x5c) = *param_2;
  *(undefined *)((int)puVar1 + 0xb9) = param_2[1];
  *(undefined *)(puVar1 + 0x5d) = param_2[2];
  *(undefined *)((int)puVar1 + 0xbb) = param_2[3];
  return;
}


/* __thiscall J3DTevBlockPatched::setTevKColor(unsigned long,
                                               J3DGXColor const *) */

void __thiscall
J3DTevBlockPatched::setTevKColor(J3DTevBlockPatched *this,ulong param_1,J3DGXColor *param_2)

{
  ushort *puVar1;
  
  puVar1 = this->mTexNo + param_1 * 2 + -4;
  *(u8 *)(puVar1 + 0x5c) = (param_2->v).r;
  *(u8 *)((int)puVar1 + 0xb9) = (param_2->v).g;
  *(u8 *)(puVar1 + 0x5d) = (param_2->v).b;
  *(u8 *)((int)puVar1 + 0xbb) = (param_2->v).a;
  return;
}


/* __thiscall J3DTevBlockPatched::getTevKColor(unsigned long) */

_GXColor * __thiscall J3DTevBlockPatched::getTevKColor(J3DTevBlockPatched *this,ulong param_1)

{
  return this->mTevKColor + param_1;
}


/* __thiscall J3DTevBlockPatched::setTevKColorSel(unsigned long,
                                                  unsigned char) */

void __thiscall
J3DTevBlockPatched::setTevKColorSel(J3DTevBlockPatched *this,ulong param_1,uchar param_2)

{
  this->mKColorSel[param_1] = param_2;
  return;
}


/* __thiscall J3DTevBlockPatched::setTevKColorSel(unsigned long,
                                                  unsigned char const *) */

void __thiscall
J3DTevBlockPatched::setTevKColorSel(J3DTevBlockPatched *this,ulong param_1,uchar *param_2)

{
  this->mKColorSel[param_1] = *param_2;
  return;
}


/* __thiscall J3DTevBlockPatched::getTevKColorSel(unsigned long) */

byte __thiscall J3DTevBlockPatched::getTevKColorSel(J3DTevBlockPatched *this,ulong param_1)

{
  return this->mKColorSel[param_1];
}


/* __thiscall J3DTevBlockPatched::getTexNoOffset(void) const */

undefined4 __thiscall J3DTevBlockPatched::getTexNoOffset(J3DTevBlockPatched *this)

{
  return *(undefined4 *)&this->field_0x4;
}


/* __thiscall J3DTevBlockPatched::getTevRegOffset(void) const */

int __thiscall J3DTevBlockPatched::getTevRegOffset(J3DTevBlockPatched *this)

{
  return this->mTevRegOffs;
}


/* __thiscall J3DTevBlockPatched::setTevRegOffset(unsigned long) */

void __thiscall J3DTevBlockPatched::setTevRegOffset(J3DTevBlockPatched *this,ulong param_1)

{
  this->mTevRegOffs = param_1;
  return;
}


/* __thiscall J3DTevBlockPatched::~J3DTevBlockPatched(void) */

void __thiscall J3DTevBlockPatched::_J3DTevBlockPatched(J3DTevBlockPatched *this)

{
  short in_r4;
  
  if (this != (J3DTevBlockPatched *)0x0) {
    *(undefined ***)this = &__vt;
    if (this != (J3DTevBlockPatched *)0x0) {
      *(undefined ***)this = &J3DTevBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DTexGenBlockBasic::getType(void) */

undefined4 __thiscall J3DTexGenBlockBasic::getType(J3DTexGenBlockBasic *this)

{
  return 0x54474243;
}


/* __thiscall J3DTexGenBlockBasic::setNBTScale(J3DNBTScale) */

void __thiscall J3DTexGenBlockBasic::setNBTScale(J3DTexGenBlockBasic *this,J3DNBTScale param_1)

{
  this[0x4c] = *(J3DTexGenBlockBasic *)param_1;
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0xc);
  return;
}


/* __thiscall J3DTexGenBlockBasic::setNBTScale(J3DNBTScale const *) */

void __thiscall J3DTexGenBlockBasic::setNBTScale(J3DTexGenBlockBasic *this,J3DNBTScale *param_1)

{
  this[0x4c] = *(J3DTexGenBlockBasic *)param_1;
  *(J3DNBTScale *)(this + 0x50) = param_1[1];
  *(J3DNBTScale *)(this + 0x54) = param_1[2];
  *(J3DNBTScale *)(this + 0x58) = param_1[3];
  return;
}


/* __thiscall J3DTexGenBlockBasic::getNBTScale(void) */

J3DTexGenBlockBasic * __thiscall J3DTexGenBlockBasic::getNBTScale(J3DTexGenBlockBasic *this)

{
  return this + 0x4c;
}


/* __thiscall J3DTexGenBlockBasic::~J3DTexGenBlockBasic(void) */

void __thiscall J3DTexGenBlockBasic::_J3DTexGenBlockBasic(J3DTexGenBlockBasic *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (J3DTexGenBlockBasic *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined ***)this = &J3DTexGenBlockPatched::__vt, bVar1)) {
      *(undefined1 **)this = &J3DTexGenBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DTexGenBlockPatched::setTexGenNum(unsigned long) */

void __thiscall J3DTexGenBlockPatched::setTexGenNum(J3DTexGenBlockPatched *this,ulong param_1)

{
  this->field_0x4 = (undefined *)param_1;
  return;
}


/* __thiscall J3DTexGenBlockPatched::setTexGenNum(unsigned long const *) */

void __thiscall J3DTexGenBlockPatched::setTexGenNum(J3DTexGenBlockPatched *this,ulong *param_1)

{
  this->field_0x4 = (undefined *)*param_1;
  return;
}


/* __thiscall J3DTexGenBlockPatched::getTexGenNum(void) const */

undefined * __thiscall J3DTexGenBlockPatched::getTexGenNum(J3DTexGenBlockPatched *this)

{
  return this->field_0x4;
}


/* __thiscall J3DTexGenBlockPatched::setTexCoord(unsigned long,
                                                 J3DTexCoord const *) */

void __thiscall
J3DTexGenBlockPatched::setTexCoord(J3DTexGenBlockPatched *this,ulong param_1,J3DTexCoord *param_2)

{
  J3DTexGenBlock__vtbl **ppJVar1;
  
  ppJVar1 = &this->vtbl + param_1;
  *(J3DTexCoord *)(ppJVar1 + 2) = *param_2;
  *(J3DTexCoord *)((int)ppJVar1 + 9) = param_2[1];
  *(J3DTexCoord *)((int)ppJVar1 + 10) = param_2[2];
  return;
}


/* __thiscall J3DTexGenBlockPatched::getTexCoord(unsigned long) */

J3DTexGenBlock__vtbl ** __thiscall
J3DTexGenBlockPatched::getTexCoord(J3DTexGenBlockPatched *this,ulong param_1)

{
  return &this[1].vtbl + param_1;
}


/* __thiscall J3DTexGenBlockPatched::setTexMtx(unsigned long,
                                               J3DTexMtx *) */

void __thiscall
J3DTexGenBlockPatched::setTexMtx(J3DTexGenBlockPatched *this,ulong param_1,J3DTexMtx *param_2)

{
  (&this[5].vtbl)[param_1] = (J3DTexGenBlock__vtbl *)param_2;
  return;
}


/* __thiscall J3DTexGenBlockPatched::getTexMtx(unsigned long) */

J3DTexGenBlock__vtbl * __thiscall
J3DTexGenBlockPatched::getTexMtx(J3DTexGenBlockPatched *this,ulong param_1)

{
  return (&this[5].vtbl)[param_1];
}


/* __thiscall J3DTexGenBlockPatched::getTexMtxOffset(void) const */

J3DTexGenBlock__vtbl * __thiscall
J3DTexGenBlockPatched::getTexMtxOffset(J3DTexGenBlockPatched *this)

{
  return this[9].vtbl;
}


/* __thiscall J3DTexGenBlockPatched::setTexMtxOffset(unsigned long) */

void __thiscall J3DTexGenBlockPatched::setTexMtxOffset(J3DTexGenBlockPatched *this,ulong param_1)

{
  this[9].vtbl = (J3DTexGenBlock__vtbl *)param_1;
  return;
}


/* __thiscall J3DTexGenBlock4::getType(void) */

undefined4 __thiscall J3DTexGenBlock4::getType(J3DTexGenBlock4 *this)

{
  return 0x54474234;
}


/* __thiscall J3DTexGenBlock4::setNBTScale(J3DNBTScale) */

void __thiscall J3DTexGenBlock4::setNBTScale(J3DTexGenBlock4 *this,J3DNBTScale param_1)

{
  this[0x4c] = *(J3DTexGenBlock4 *)param_1;
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0xc);
  return;
}


/* __thiscall J3DTexGenBlock4::setNBTScale(J3DNBTScale const *) */

void __thiscall J3DTexGenBlock4::setNBTScale(J3DTexGenBlock4 *this,J3DNBTScale *param_1)

{
  this[0x4c] = *(J3DTexGenBlock4 *)param_1;
  *(J3DNBTScale *)(this + 0x50) = param_1[1];
  *(J3DNBTScale *)(this + 0x54) = param_1[2];
  *(J3DNBTScale *)(this + 0x58) = param_1[3];
  return;
}


/* __thiscall J3DTexGenBlock4::getNBTScale(void) */

J3DTexGenBlock4 * __thiscall J3DTexGenBlock4::getNBTScale(J3DTexGenBlock4 *this)

{
  return this + 0x4c;
}


/* __thiscall J3DTexGenBlock4::~J3DTexGenBlock4(void) */

void __thiscall J3DTexGenBlock4::_J3DTexGenBlock4(J3DTexGenBlock4 *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (J3DTexGenBlock4 *)0x0;
  if (bVar1) {
    *(undefined ***)this = &__vt;
    if ((bVar1) && (*(undefined ***)this = &J3DTexGenBlockPatched::__vt, bVar1)) {
      *(undefined1 **)this = &J3DTexGenBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DTexGenBlockPatched::load(void) */

void __thiscall J3DTexGenBlockPatched::load(J3DTexGenBlockPatched *this)

{
  return;
}


/* __thiscall J3DTexGenBlockPatched::getType(void) */

undefined4 __thiscall J3DTexGenBlockPatched::getType(J3DTexGenBlockPatched *this)

{
  return 0x54475054;
}


/* __thiscall J3DColorBlockLightOn::getType(void) */

undefined4 __thiscall J3DColorBlockLightOn::getType(J3DColorBlockLightOn *this)

{
  return 0x434c4f4e;
}


/* __thiscall J3DColorBlockLightOn::setMatColor(unsigned long,
                                                J3DGXColor) */

void __thiscall
J3DColorBlockLightOn::setMatColor(J3DColorBlockLightOn *this,ulong param_1,J3DGXColor param_2)

{
  J3DGXColor *pJVar1;
  
  pJVar1 = this->mColors + (param_1 - 1);
  *(undefined *)(pJVar1 + 1) = *param_2;
  *(undefined *)((int)pJVar1 + 5) = param_2[1];
  *(undefined *)((int)pJVar1 + 6) = param_2[2];
  *(undefined *)((int)pJVar1 + 7) = param_2[3];
  return;
}


/* __thiscall J3DColorBlockLightOn::setMatColor(unsigned long,
                                                J3DGXColor const *) */

void __thiscall
J3DColorBlockLightOn::setMatColor(J3DColorBlockLightOn *this,ulong param_1,J3DGXColor *param_2)

{
  J3DGXColor *pJVar1;
  
  pJVar1 = this->mColors + (param_1 - 1);
  *(u8 *)(pJVar1 + 1) = (param_2->v).r;
  *(u8 *)((int)pJVar1 + 5) = (param_2->v).g;
  *(u8 *)((int)pJVar1 + 6) = (param_2->v).b;
  *(u8 *)((int)pJVar1 + 7) = (param_2->v).a;
  return;
}


/* __thiscall J3DColorBlockLightOn::getMatColor(unsigned long) */

J3DGXColor * __thiscall J3DColorBlockLightOn::getMatColor(J3DColorBlockLightOn *this,ulong param_1)

{
  return this->mColors + param_1;
}


/* __thiscall J3DColorBlockLightOn::setAmbColor(unsigned long,
                                                J3DGXColor) */

void __thiscall
J3DColorBlockLightOn::setAmbColor(J3DColorBlockLightOn *this,ulong param_1,J3DGXColor param_2)

{
  J3DGXColor *pJVar1;
  
  pJVar1 = this->mColors + (param_1 - 1);
  *(undefined *)(pJVar1 + 3) = *param_2;
  *(undefined *)((int)pJVar1 + 0xd) = param_2[1];
  *(undefined *)((int)pJVar1 + 0xe) = param_2[2];
  *(undefined *)((int)pJVar1 + 0xf) = param_2[3];
  return;
}


/* __thiscall J3DColorBlockLightOn::setAmbColor(unsigned long,
                                                J3DGXColor const *) */

void __thiscall
J3DColorBlockLightOn::setAmbColor(J3DColorBlockLightOn *this,ulong param_1,J3DGXColor *param_2)

{
  J3DGXColor *pJVar1;
  
  pJVar1 = this->mColors + (param_1 - 1);
  *(u8 *)(pJVar1 + 3) = (param_2->v).r;
  *(u8 *)((int)pJVar1 + 0xd) = (param_2->v).g;
  *(u8 *)((int)pJVar1 + 0xe) = (param_2->v).b;
  *(u8 *)((int)pJVar1 + 0xf) = (param_2->v).a;
  return;
}


/* __thiscall J3DColorBlockLightOn::getAmbColor(unsigned long) */

J3DGXColor * __thiscall J3DColorBlockLightOn::getAmbColor(J3DColorBlockLightOn *this,ulong param_1)

{
  return this->mColors + param_1 + 2;
}


/* __thiscall J3DColorBlockLightOn::setColorChanNum(unsigned char const *) */

void __thiscall J3DColorBlockLightOn::setColorChanNum(J3DColorBlockLightOn *this,uchar *param_1)

{
  *(uchar *)&this->field_0x14 = *param_1;
  return;
}


/* __thiscall J3DColorBlockLightOn::setColorChanNum(unsigned char) */

void __thiscall J3DColorBlockLightOn::setColorChanNum(J3DColorBlockLightOn *this,uchar param_1)

{
  *(uchar *)&this->field_0x14 = param_1;
  return;
}


/* __thiscall J3DColorBlockLightOn::getColorChanNum(void) const */

undefined __thiscall J3DColorBlockLightOn::getColorChanNum(J3DColorBlockLightOn *this)

{
  return *(undefined *)&this->field_0x14;
}


/* __thiscall J3DColorBlockLightOn::setColorChan(unsigned long,
                                                 J3DColorChan const *) */

void __thiscall
J3DColorBlockLightOn::setColorChan(J3DColorBlockLightOn *this,ulong param_1,J3DColorChan *param_2)

{
  this->mColorChan[param_1].mChan = param_2->mChan;
  return;
}


/* __thiscall J3DColorBlockLightOn::setColorChan(unsigned long,
                                                 J3DColorChan const &) */

void __thiscall
J3DColorBlockLightOn::setColorChan(J3DColorBlockLightOn *this,ulong param_1,J3DColorChan *param_2)

{
  this->mColorChan[param_1].mChan = param_2->mChan;
  return;
}


/* __thiscall J3DColorBlockLightOn::getColorChan(unsigned long) */

J3DColorChan * __thiscall
J3DColorBlockLightOn::getColorChan(J3DColorBlockLightOn *this,ulong param_1)

{
  return this->mColorChan + param_1;
}


/* __thiscall J3DColorBlockLightOn::setLight(unsigned long,
                                             J3DLightObj *) */

void __thiscall
J3DColorBlockLightOn::setLight(J3DColorBlockLightOn *this,ulong param_1,J3DLightObj *param_2)

{
  this->mpLights[param_1] = param_2;
  return;
}


/* __thiscall J3DColorBlockLightOn::getLight(unsigned long) */

J3DLightObj * __thiscall J3DColorBlockLightOn::getLight(J3DColorBlockLightOn *this,ulong param_1)

{
  return this->mpLights[param_1];
}


/* __thiscall J3DColorBlockLightOn::setCullMode(unsigned char) */

void __thiscall J3DColorBlockLightOn::setCullMode(J3DColorBlockLightOn *this,uchar param_1)

{
  this->mCullMode = param_1;
  return;
}


/* __thiscall J3DColorBlockLightOn::setCullMode(unsigned char const *) */

void __thiscall J3DColorBlockLightOn::setCullMode(J3DColorBlockLightOn *this,uchar *param_1)

{
  this->mCullMode = *param_1;
  return;
}


/* __thiscall J3DColorBlockLightOn::getCullMode(void) const */

byte __thiscall J3DColorBlockLightOn::getCullMode(J3DColorBlockLightOn *this)

{
  return this->mCullMode;
}


/* __thiscall J3DColorBlockLightOn::getMatColorOffset(void) const */

ulong __thiscall J3DColorBlockLightOn::getMatColorOffset(J3DColorBlockLightOn *this)

{
  return this->mMatColorOffs;
}


/* __thiscall J3DColorBlockLightOn::getColorChanOffset(void) const */

ulong __thiscall J3DColorBlockLightOn::getColorChanOffset(J3DColorBlockLightOn *this)

{
  return this->mColorChanOffs;
}


/* __thiscall J3DColorBlockLightOn::setMatColorOffset(unsigned long) */

void __thiscall J3DColorBlockLightOn::setMatColorOffset(J3DColorBlockLightOn *this,ulong param_1)

{
  this->mMatColorOffs = param_1;
  return;
}


/* __thiscall J3DColorBlockLightOn::setColorChanOffset(unsigned long) */

void __thiscall J3DColorBlockLightOn::setColorChanOffset(J3DColorBlockLightOn *this,ulong param_1)

{
  this->mColorChanOffs = param_1;
  return;
}


/* __thiscall J3DColorBlockLightOn::~J3DColorBlockLightOn(void) */

void __thiscall J3DColorBlockLightOn::_J3DColorBlockLightOn(J3DColorBlockLightOn *this)

{
  short in_r4;
  
  if (this != (J3DColorBlockLightOn *)0x0) {
    (this->parent).vtbl = (J3DColorBlock__vtbl *)&__vt;
    if (this != (J3DColorBlockLightOn *)0x0) {
      (this->parent).vtbl = (J3DColorBlock__vtbl *)&J3DColorBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DColorBlockAmbientOn::getType(void) */

undefined4 __thiscall J3DColorBlockAmbientOn::getType(J3DColorBlockAmbientOn *this)

{
  return 0x434c4142;
}


/* __thiscall J3DColorBlockAmbientOn::setAmbColor(unsigned long,
                                                  J3DGXColor) */

void __thiscall
J3DColorBlockAmbientOn::setAmbColor(J3DColorBlockAmbientOn *this,ulong param_1,J3DGXColor param_2)

{
  J3DColorBlockAmbientOn *pJVar1;
  
  pJVar1 = this + param_1 * 4;
  pJVar1[0x20] = *param_2;
  pJVar1[0x21] = param_2[1];
  pJVar1[0x22] = param_2[2];
  pJVar1[0x23] = param_2[3];
  return;
}


/* __thiscall J3DColorBlockAmbientOn::setAmbColor(unsigned long,
                                                  J3DGXColor const *) */

void __thiscall
J3DColorBlockAmbientOn::setAmbColor(J3DColorBlockAmbientOn *this,ulong param_1,J3DGXColor *param_2)

{
  J3DColorBlockAmbientOn *pJVar1;
  
  pJVar1 = this + param_1 * 4;
  pJVar1[0x20] = *(J3DColorBlockAmbientOn *)&(param_2->v).r;
  pJVar1[0x21] = *(J3DColorBlockAmbientOn *)&(param_2->v).g;
  pJVar1[0x22] = *(J3DColorBlockAmbientOn *)&(param_2->v).b;
  pJVar1[0x23] = *(J3DColorBlockAmbientOn *)&(param_2->v).a;
  return;
}


/* __thiscall J3DColorBlockAmbientOn::getAmbColor(unsigned long) */

J3DColorBlockAmbientOn * __thiscall
J3DColorBlockAmbientOn::getAmbColor(J3DColorBlockAmbientOn *this,ulong param_1)

{
  return this + param_1 * 4 + 0x20;
}


/* __thiscall J3DColorBlockAmbientOn::~J3DColorBlockAmbientOn(void) */

void __thiscall J3DColorBlockAmbientOn::_J3DColorBlockAmbientOn(J3DColorBlockAmbientOn *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (J3DColorBlockAmbientOn *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined1 **)this = &J3DColorBlockLightOff::__vt, bVar1)) {
      *(undefined ***)this = &J3DColorBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DColorBlockLightOff::setMatColor(unsigned long,
                                                 J3DGXColor) */

void __thiscall
J3DColorBlockLightOff::setMatColor(J3DColorBlockLightOff *this,ulong param_1,J3DGXColor param_2)

{
  J3DColorBlockLightOff *pJVar1;
  
  pJVar1 = this + param_1 * 4;
  pJVar1[4] = *param_2;
  pJVar1[5] = param_2[1];
  pJVar1[6] = param_2[2];
  pJVar1[7] = param_2[3];
  return;
}


/* __thiscall J3DColorBlockLightOff::setMatColor(unsigned long,
                                                 J3DGXColor const *) */

void __thiscall
J3DColorBlockLightOff::setMatColor(J3DColorBlockLightOff *this,ulong param_1,J3DGXColor *param_2)

{
  J3DColorBlockLightOff *pJVar1;
  
  pJVar1 = this + param_1 * 4;
  pJVar1[4] = *(J3DColorBlockLightOff *)&(param_2->v).r;
  pJVar1[5] = *(J3DColorBlockLightOff *)&(param_2->v).g;
  pJVar1[6] = *(J3DColorBlockLightOff *)&(param_2->v).b;
  pJVar1[7] = *(J3DColorBlockLightOff *)&(param_2->v).a;
  return;
}


/* __thiscall J3DColorBlockLightOff::getMatColor(unsigned long) */

J3DColorBlockLightOff * __thiscall
J3DColorBlockLightOff::getMatColor(J3DColorBlockLightOff *this,ulong param_1)

{
  return this + param_1 * 4 + 4;
}


/* __thiscall J3DColorBlockLightOff::setColorChanNum(unsigned char const *) */

void __thiscall J3DColorBlockLightOff::setColorChanNum(J3DColorBlockLightOff *this,uchar *param_1)

{
  this[0xc] = (J3DColorBlockLightOff)*param_1;
  return;
}


/* __thiscall J3DColorBlockLightOff::setColorChanNum(unsigned char) */

void __thiscall J3DColorBlockLightOff::setColorChanNum(J3DColorBlockLightOff *this,uchar param_1)

{
  this[0xc] = (J3DColorBlockLightOff)param_1;
  return;
}


/* __thiscall J3DColorBlockLightOff::getColorChanNum(void) const */

J3DColorBlockLightOff __thiscall J3DColorBlockLightOff::getColorChanNum(J3DColorBlockLightOff *this)

{
  return this[0xc];
}


/* __thiscall J3DColorBlockLightOff::setColorChan(unsigned long,
                                                  J3DColorChan const *) */

void __thiscall
J3DColorBlockLightOff::setColorChan(J3DColorBlockLightOff *this,ulong param_1,J3DColorChan *param_2)

{
  *(short *)&this[param_1 * 2 + 0xe].field_0x0 = param_2->mChan;
  return;
}


/* __thiscall J3DColorBlockLightOff::setColorChan(unsigned long,
                                                  J3DColorChan const &) */

void __thiscall
J3DColorBlockLightOff::setColorChan(J3DColorBlockLightOff *this,ulong param_1,J3DColorChan *param_2)

{
  *(short *)&this[param_1 * 2 + 0xe].field_0x0 = param_2->mChan;
  return;
}


/* __thiscall J3DColorBlockLightOff::getColorChan(unsigned long) */

J3DColorBlockLightOff * __thiscall
J3DColorBlockLightOff::getColorChan(J3DColorBlockLightOff *this,ulong param_1)

{
  return this + param_1 * 2 + 0xe;
}


/* __thiscall J3DColorBlockLightOff::setCullMode(unsigned char) */

void __thiscall J3DColorBlockLightOff::setCullMode(J3DColorBlockLightOff *this,uchar param_1)

{
  this[0x16] = (J3DColorBlockLightOff)param_1;
  return;
}


/* __thiscall J3DColorBlockLightOff::setCullMode(unsigned char const *) */

void __thiscall J3DColorBlockLightOff::setCullMode(J3DColorBlockLightOff *this,uchar *param_1)

{
  this[0x16] = (J3DColorBlockLightOff)*param_1;
  return;
}


/* __thiscall J3DColorBlockLightOff::getCullMode(void) const */

J3DColorBlockLightOff __thiscall J3DColorBlockLightOff::getCullMode(J3DColorBlockLightOff *this)

{
  return this[0x16];
}


/* __thiscall J3DColorBlockLightOff::getMatColorOffset(void) const */

undefined4 __thiscall J3DColorBlockLightOff::getMatColorOffset(J3DColorBlockLightOff *this)

{
  return *(undefined4 *)(this + 0x18);
}


/* __thiscall J3DColorBlockLightOff::getColorChanOffset(void) const */

undefined4 __thiscall J3DColorBlockLightOff::getColorChanOffset(J3DColorBlockLightOff *this)

{
  return *(undefined4 *)(this + 0x1c);
}


/* __thiscall J3DColorBlockLightOff::setMatColorOffset(unsigned long) */

void __thiscall J3DColorBlockLightOff::setMatColorOffset(J3DColorBlockLightOff *this,ulong param_1)

{
  *(ulong *)(this + 0x18) = param_1;
  return;
}


/* __thiscall J3DColorBlockLightOff::setColorChanOffset(unsigned long) */

void __thiscall J3DColorBlockLightOff::setColorChanOffset(J3DColorBlockLightOff *this,ulong param_1)

{
  *(ulong *)(this + 0x1c) = param_1;
  return;
}


/* __thiscall J3DPEBlockXlu::getType(void) */

undefined4 __thiscall J3DPEBlockXlu::getType(J3DPEBlockXlu *this)

{
  return 0x5045584c;
}


/* __thiscall J3DPEBlockXlu::~J3DPEBlockXlu(void) */

void __thiscall J3DPEBlockXlu::_J3DPEBlockXlu(J3DPEBlockXlu *this)

{
  short in_r4;
  
  if (this != (J3DPEBlockXlu *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DPEBlockXlu *)0x0) {
      *(undefined1 **)this = &J3DPEBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DPEBlockTexEdge::getType(void) */

undefined4 __thiscall J3DPEBlockTexEdge::getType(J3DPEBlockTexEdge *this)

{
  return 0x50454544;
}


/* __thiscall J3DPEBlockTexEdge::~J3DPEBlockTexEdge(void) */

void __thiscall J3DPEBlockTexEdge::_J3DPEBlockTexEdge(J3DPEBlockTexEdge *this)

{
  short in_r4;
  
  if (this != (J3DPEBlockTexEdge *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DPEBlockTexEdge *)0x0) {
      *(undefined1 **)this = &J3DPEBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DPEBlockOpa::getType(void) */

undefined4 __thiscall J3DPEBlockOpa::getType(J3DPEBlockOpa *this)

{
  return 0x50454f50;
}


/* __thiscall J3DPEBlockOpa::~J3DPEBlockOpa(void) */

void __thiscall J3DPEBlockOpa::_J3DPEBlockOpa(J3DPEBlockOpa *this)

{
  short in_r4;
  
  if (this != (J3DPEBlockOpa *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DPEBlockOpa *)0x0) {
      *(undefined1 **)this = &J3DPEBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DIndBlockFull::getType(void) */

undefined4 __thiscall J3DIndBlockFull::getType(J3DIndBlockFull *this)

{
  return 0x49424c46;
}


/* __thiscall J3DIndBlockFull::setIndTexStageNum(unsigned char) */

void __thiscall J3DIndBlockFull::setIndTexStageNum(J3DIndBlockFull *this,uchar param_1)

{
  this[4] = (J3DIndBlockFull)param_1;
  return;
}


/* __thiscall J3DIndBlockFull::getIndTexStageNum(void) const */

J3DIndBlockFull __thiscall J3DIndBlockFull::getIndTexStageNum(J3DIndBlockFull *this)

{
  return this[4];
}


/* __thiscall J3DIndBlockFull::setIndTexOrder(unsigned long,
                                              J3DIndTexOrder) */

void __thiscall
J3DIndBlockFull::setIndTexOrder(J3DIndBlockFull *this,ulong param_1,J3DIndTexOrder param_2)

{
  undefined3 in_register_00000014;
  
  (this + param_1 * 4)[5] = *(J3DIndBlockFull *)CONCAT31(in_register_00000014,param_2);
  (this + param_1 * 4)[6] = ((J3DIndBlockFull *)CONCAT31(in_register_00000014,param_2))[1];
  return;
}


/* __thiscall J3DIndBlockFull::setIndTexOrder(unsigned long,
                                              J3DIndTexOrder const *) */

void __thiscall
J3DIndBlockFull::setIndTexOrder(J3DIndBlockFull *this,ulong param_1,J3DIndTexOrder *param_2)

{
  (this + param_1 * 4)[5] = *(J3DIndBlockFull *)param_2;
  (this + param_1 * 4)[6] = *(J3DIndBlockFull *)(param_2 + 1);
  return;
}


/* __thiscall J3DIndBlockFull::getIndTexOrder(unsigned long) */

J3DIndBlockFull * __thiscall J3DIndBlockFull::getIndTexOrder(J3DIndBlockFull *this,ulong param_1)

{
  return this + param_1 * 4 + 5;
}


/* __thiscall J3DIndBlockFull::setIndTexMtx(unsigned long,
                                            J3DIndTexMtx) */

void __thiscall
J3DIndBlockFull::setIndTexMtx(J3DIndBlockFull *this,ulong param_1,J3DIndTexMtx param_2)

{
  int iVar1;
  undefined3 in_register_00000014;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    iVar1 = 0;
    iVar4 = 3;
    do {
      *(undefined4 *)(this + iVar1 + 0x18 + iVar2 + param_1 * 0x1c) =
           *(undefined4 *)(CONCAT31(in_register_00000014,param_2) + iVar2 + iVar1);
      iVar1 = iVar1 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 0xc;
  } while (iVar3 < 2);
  this[param_1 * 0x1c + 0x30] = *(J3DIndBlockFull *)(CONCAT31(in_register_00000014,param_2) + 0x18);
  return;
}


/* __thiscall J3DIndBlockFull::setIndTexMtx(unsigned long,
                                            J3DIndTexMtx const *) */

void __thiscall
J3DIndBlockFull::setIndTexMtx(J3DIndBlockFull *this,ulong param_1,J3DIndTexMtx *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    iVar1 = 0;
    iVar4 = 3;
    do {
      *(undefined4 *)(this + iVar1 + 0x18 + iVar2 + param_1 * 0x1c) =
           *(undefined4 *)(param_2 + iVar1 + iVar2);
      iVar1 = iVar1 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 0xc;
  } while (iVar3 < 2);
  this[param_1 * 0x1c + 0x30] = *(J3DIndBlockFull *)(param_2 + 0x18);
  return;
}


/* __thiscall J3DIndBlockFull::getIndTexMtx(unsigned long) */

J3DIndBlockFull * __thiscall J3DIndBlockFull::getIndTexMtx(J3DIndBlockFull *this,ulong param_1)

{
  return this + param_1 * 0x1c + 0x18;
}


/* __thiscall J3DIndBlockFull::setIndTexCoordScale(unsigned long,
                                                   J3DIndTexCoordScale) */

void __thiscall
J3DIndBlockFull::setIndTexCoordScale
          (J3DIndBlockFull *this,ulong param_1,J3DIndTexCoordScale param_2)

{
  undefined3 in_register_00000014;
  
  (this + param_1 * 4)[0x6c] = *(J3DIndBlockFull *)CONCAT31(in_register_00000014,param_2);
  (this + param_1 * 4)[0x6d] = ((J3DIndBlockFull *)CONCAT31(in_register_00000014,param_2))[1];
  return;
}


/* __thiscall J3DIndBlockFull::setIndTexCoordScale(unsigned long,
                                                   J3DIndTexCoordScale const *) */

void __thiscall
J3DIndBlockFull::setIndTexCoordScale
          (J3DIndBlockFull *this,ulong param_1,J3DIndTexCoordScale *param_2)

{
  (this + param_1 * 4)[0x6c] = *(J3DIndBlockFull *)param_2;
  (this + param_1 * 4)[0x6d] = *(J3DIndBlockFull *)(param_2 + 1);
  return;
}


/* __thiscall J3DIndBlockFull::getIndTexCoordScale(unsigned long) */

J3DIndBlockFull * __thiscall
J3DIndBlockFull::getIndTexCoordScale(J3DIndBlockFull *this,ulong param_1)

{
  return this + param_1 * 4 + 0x6c;
}


/* __thiscall J3DIndBlockFull::~J3DIndBlockFull(void) */

void __thiscall J3DIndBlockFull::_J3DIndBlockFull(J3DIndBlockFull *this)

{
  short in_r4;
  
  if (this != (J3DIndBlockFull *)0x0) {
    *(undefined1 **)this = &__vt;
    Runtime.PPCEABI.H::__destroy_arr(this + 0x6c,J3DIndTexCoordScale::_J3DIndTexCoordScale,4,4);
    Runtime.PPCEABI.H::__destroy_arr(this + 0x18,J3DIndTexMtx::_J3DIndTexMtx,0x1c,3);
    if (this != (J3DIndBlockFull *)0x0) {
      *(undefined1 **)this = &J3DIndBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DTevBlock::patchTexNo(void) */

void __thiscall J3DTevBlock::patchTexNo(J3DTevBlock *this)

{
  return;
}


/* __thiscall J3DTevBlock::patchTevReg(void) */

void __thiscall J3DTevBlock::patchTevReg(J3DTevBlock *this)

{
  return;
}


/* __thiscall J3DTevBlock::setTexNo(unsigned long,
                                    unsigned short const *) */

void __thiscall J3DTevBlock::setTexNo(J3DTevBlock *this,ulong param_1,ushort *param_2)

{
  return;
}


/* __thiscall J3DTevBlock::setTevOrder(unsigned long,
                                       J3DTevOrder const *) */

void __thiscall J3DTevBlock::setTevOrder(J3DTevBlock *this,ulong param_1,J3DTevOrder *param_2)

{
  return;
}


/* __thiscall J3DTevBlock::setTevStageNum(unsigned char const *) */

void __thiscall J3DTevBlock::setTevStageNum(J3DTevBlock *this,uchar *param_1)

{
  return;
}


/* __thiscall J3DTevBlock::setTevStage(unsigned long,
                                       J3DTevStage const *) */

void __thiscall J3DTevBlock::setTevStage(J3DTevBlock *this,ulong param_1,undefined param_2)

{
  return;
}


/* __thiscall J3DTevBlock::setIndTevStage(unsigned long,
                                          J3DIndTevStage const *) */

void __thiscall J3DTevBlock::setIndTevStage(J3DTevBlock *this,ulong param_1,J3DIndTevStage *param_2)

{
  return;
}


/* __thiscall J3DTevBlock::getTexNoOffset(void) const */

undefined4 __thiscall J3DTevBlock::getTexNoOffset(J3DTevBlock *this)

{
  return 0;
}


/* __thiscall J3DColorBlockLightOff::getType(void) */

undefined4 __thiscall J3DColorBlockLightOff::getType(J3DColorBlockLightOff *this)

{
  return 0x434c4f46;
}


namespace J3DGraphBase {

void __sinit_J3DMatBlock_cpp(void)

{
  SizeOfJ3DColorBlockLightOffLoad = SizeOfLoadMatColors + SizeOfLoadColorChans;
  SizeOfJ3DColorBlockAmbientOnLoad =
       SizeOfLoadMatColors + SizeOfLoadAmbColors + SizeOfLoadColorChans;
  return;
}

