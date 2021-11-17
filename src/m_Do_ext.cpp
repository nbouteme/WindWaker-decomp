#include <m_Do_ext.h>
#include <mtx/mtx.h>
#include <m_Do_printf.h>
#include <m_Do_ext.h>
#include <JUtility/JUTAssert.h>
#include <JKernel/JKRHeap.h>
#include <J3DGraphAnimator/J3DAnimation.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <J3DGraphAnimator/J3DMaterialAttach.h>
#include <J3DGraphAnimator/J3DJoint.h>
#include <os/OSInterrupt.h>
#include <gd/GDBase.h>
#include <J3DGraphAnimator/J3DModel.h>
#include <os/OSCache.h>
#include <d_drawlist.h>
#include <JKernel/JKRExpHeap.h>
#include <JKernel/JKRSolidHeap.h>
#include <os/OSThread.h>
#include <JKernel/JKRArchivePri.h>
#include <JMath/JMath.h>
#include <JAudio/JAIAnimation.h>
#include <SComponent/c_lib.h>
#include <JAZelAudio/JAIZelAnime.h>
#include <J3DGraphAnimator/J3DModelData.h>
#include <gf/GFPixel.h>
#include <gx/GXDisplayList.h>
#include <J3DGraphBase/J3DShape.h>
#include <J3DGraphBase/J3DPacket.h>
#include <m_Do_mtx.h>
#include <J3DGraphBase/J3DSys.h>
#include <gx/GXBump.h>
#include <d_kankyo.h>
#include <gx/GXAttr.h>
#include <gx/GXTransform.h>
#include <gx/GXTev.h>
#include <gx/GXGeometry.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <gx/GXTexture.h>
#include <J3DGraphBase/J3DDrawBuffer.h>
#include <JKernel/JKRArchivePub.h>
#include <JUtility/JUTCacheFont.h>
#include <JKernel/JKRFileLoader.h>
#include <JUtility/JUTResFont.h>
#include <J3DTexGenBlock.h>
#include <mDoExt_bvaAnm.h>
#include <mDoExt_bpkAnm.h>
#include <J3DPacket.h>
#include <J3DTexMtxAnm.h>
#include <J3DIndTevStage.h>
#include <mDoExt_MtxCalcOldFrame.h>
#include <J3DMatColorAnm.h>
#include <mDoExt_onCupOffAupPacket.h>
#include <J3DIndBlock.h>
#include <Demangler/J3DColorChan.h>
#include <cXyz.h>
#include <J3DIndTexOrder.h>
#include <mDoExt_invisibleModel.h>
#include <mDoExt_3Dline_c.h>
#include <mDoExt_brkAnm.h>
#include <Demangler/J3DTexCoord.h>
#include <mDoExt_offCupOnAupPacket.h>
#include <mDoExt_3DlineMat1_c.h>
#include <Demangler/mDoExt_McaMorf.h>
#include <mDoExt_btpAnm.h>
#include <mDoExt_bckAnm.h>
#include <mDoExt_MtxCalcAnmBlendTbl.h>
#include <J3DTexMtx.h>
#include <J3DIndTexMtx.h>
#include <J3DMtxCalcMayaAnm.h>
#include <J3DMtxCalcBasic.h>
#include <J3DAnmTransform.h>
#include <J3DTexNoAnm.h>
#include <J3DPEBlock.h>
#include <J3DTevBlock.h>
#include <mDoExt_MtxCalcAnmBlendTblOld.h>
#include <J3DTevStage.h>
#include <J3DTevSwapModeTable.h>
#include <mDoExt_btkAnm.h>
#include <J3DMtxCalc.h>
#include <J3DFrameCtrl.h>
#include <mDoExt_McaMorf2.h>
#include <J3DGXColorS10.h>
#include <J3DTevKColorAnm.h>
#include <J3DGXColor.h>
#include <J3DTevOrder.h>
#include <J3DIndTexCoordScale.h>
#include <J3DTevColorAnm.h>
#include <mDoExt_3DlineMat0_c.h>
#include <J3DMtxCalcAnm.h>
#include <mDoExt_baseAnm.h>
#include <J3DMtxCalcMaya.h>
#include <mDoExt_backupMaterial_c.h>
#include <JUTFont.h>
#include <J3DColorBlock.h>
#include <mDoExt_backupMatBlock_c.h>
#include <mDoExt_3DlineMatSortPacket.h>
#include <mDoExt_invJntPacket.h>


namespace m_Do_ext {
struct JKRHeap * gameHeap;
undefined4 safeGameHeapSize;
struct JKRHeap * zeldaHeap;
undefined4 safeZeldaHeapSize;
undefined4 commandHeap;
undefined4 safeCommandHeapSize;
struct JKRHeap * archiveHeap;
undefined4 safeArchiveHeapSize;
undefined4 mDoExt_SaveCurrentHeap;
undefined4 mDoExt_font0;
undefined4 mDoExt_font0_getCount;
undefined4 mDoExt_resfont0;
undefined4 mDoExt_font1;
undefined4 mDoExt_font1_getCount;
undefined4 mDoExt_resfont1;

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall mDoExt_setJ3DData(float *[][][][],
                               J3DTransformInfo const *,
                               unsigned short) */

void mDoExt_setJ3DData(MTX34 *pDst,J3DTransformInfo *pInfo,uint param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  
  if (ABS((pInfo->mScale).x - 1_0) < SComponent::G_CM3D_F_ABS_MIN) {
    if (ABS((pInfo->mScale).y - 1_0) < SComponent::G_CM3D_F_ABS_MIN) {
      if (ABS((pInfo->mScale).z - 1_0) < SComponent::G_CM3D_F_ABS_MIN) {
        (J3DGraphBase::j3dSys.mpCurModel)->field_0x84[param_3 & 0xffff] = 1;
        bVar4 = true;
        goto LAB_8000db24;
      }
    }
  }
  (J3DGraphBase::j3dSys.mpCurModel)->field_0x84[param_3 & 0xffff] = 0;
  bVar4 = false;
LAB_8000db24:
  pDst->m[3] = (pInfo->mTranslation).x;
  pDst->m[1][3] = (pInfo->mTranslation).y;
  pDst->m[2][3] = (pInfo->mTranslation).z;
  if (!bVar4) {
    pDst->m[0] = pDst->m[0] * (pInfo->mScale).x;
    pDst->m[1] = pDst->m[1] * (pInfo->mScale).y;
    pDst->m[2] = pDst->m[2] * (pInfo->mScale).z;
    pDst->m[1][0] = pDst->m[1][0] * (pInfo->mScale).x;
    pDst->m[1][1] = pDst->m[1][1] * (pInfo->mScale).y;
    pDst->m[1][2] = pDst->m[1][2] * (pInfo->mScale).z;
    pDst->m[2][0] = pDst->m[2][0] * (pInfo->mScale).x;
    pDst->m[2][1] = pDst->m[2][1] * (pInfo->mScale).y;
    pDst->m[2][2] = pDst->m[2][2] * (pInfo->mScale).z;
  }
  if (((J3DGraphBase::j3dSys.mpCurModel)->mpModelData->mJointTree).mpJoints[param_3 & 0xffff]->
      mbIgnoreParentScale == 1) {
    fVar1 = 1_0 / J3DSys::mParentS.x;
    fVar2 = 1_0 / J3DSys::mParentS.y;
    fVar3 = 1_0 / J3DSys::mParentS.z;
    pDst->m[0] = pDst->m[0] * fVar1;
    pDst->m[1] = pDst->m[1] * fVar1;
    pDst->m[2] = pDst->m[2] * fVar1;
    pDst->m[1][0] = pDst->m[1][0] * fVar2;
    pDst->m[1][1] = pDst->m[1][1] * fVar2;
    pDst->m[1][2] = pDst->m[1][2] * fVar2;
    pDst->m[2][0] = pDst->m[2][0] * fVar3;
    pDst->m[2][1] = pDst->m[2][1] * fVar3;
    pDst->m[2][2] = pDst->m[2][2] * fVar3;
  }
  mtx::PSMTXConcat(&J3DSys::mCurrentMtx,pDst,&J3DSys::mCurrentMtx);
  mtx::PSMTXCopy(&J3DSys::mCurrentMtx,
                 (J3DGraphBase::j3dSys.mpCurModel)->mpNodeMtx + (param_3 & 0xffff));
  J3DSys::mParentS.x = (pInfo->mScale).x;
  J3DSys::mParentS.y = (pInfo->mScale).y;
  J3DSys::mParentS.z = (pInfo->mScale).z;
  return;
}

}

/* __thiscall J3DAnmTransform::getTransform(unsigned short,
                                            J3DTransformInfo *) const */

void __thiscall
J3DAnmTransform::getTransform(J3DAnmTransform *this,ushort param_1,J3DTransformInfo *param_2)

{
  return;
}


namespace m_Do_ext {

/* __stdcall isCurrentSolidHeap(void) */

bool isCurrentSolidHeap(void)

{
  int iVar1;
  
  iVar1 = (*(code *)JKRHeap::sCurrentHeap->vtbl->getHeapType)();
  if (iVar1 != 0x534c4944) {
    m_Do_printf::OSReport_Error("ソリッドヒープちゃうがな！\n");
  }
  return iVar1 == 0x534c4944;
}

}

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x8000df04) */
/* __thiscall mDoExt_baseAnm::initPlay(short,
                                       int,
                                       float,
                                       short,
                                       short,
                                       bool) */

undefined4 __thiscall
mDoExt_baseAnm::initPlay
          (mDoExt_baseAnm *this,short duration,J3DFrameCtrl__LoopMode loopMode,float speed,
          short startFrame,short endFrame,bool i_modify)

{
  bool bVar1;
  char cVar5;
  ulong uVar2;
  J3DFrameCtrl *pJVar3;
  undefined4 uVar4;
  undefined4 uVar6;
  double dVar7;
  undefined8 in_f31;
  double local_38;
  undefined auStack8 [8];
  
  dVar7 = (double)speed;
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  bVar1 = false;
  if ((i_modify != false) || (cVar5 = m_Do_ext::isCurrentSolidHeap(), cVar5 != '\0')) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"m_Do_ext.cpp",0x1a5,"i_modify || isCurrentSolidHeap()");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x1a5,"Halt");
  }
  if (i_modify == false) {
    pJVar3 = (J3DFrameCtrl *)JKernel::operator_new(0x14);
    if (pJVar3 != (J3DFrameCtrl *)0x0) {
      pJVar3->vtbl = (undefined *)&J3DFrameCtrl::__vt;
      J3DFrameCtrl::init(pJVar3,0);
    }
    this->mpFrameCtrl = pJVar3;
    if (this->mpFrameCtrl == (J3DFrameCtrl *)0x0) {
      uVar4 = 0;
      goto LAB_8000df04;
    }
  }
  pJVar3 = this->mpFrameCtrl;
  pJVar3->mStartFrame = startFrame;
  local_38 = (double)CONCAT44(0x43300000,(int)startFrame ^ 0x80000000);
  pJVar3->mCurrentTime = (float)(local_38 - m_Do_ext::_4289);
  if (endFrame < 0) {
    J3DFrameCtrl::init(this->mpFrameCtrl,duration);
  }
  else {
    J3DFrameCtrl::init(this->mpFrameCtrl,endFrame);
  }
  this->mpFrameCtrl->mLoopMode = loopMode;
  this->mpFrameCtrl->mSpeed = (float)dVar7;
  if (dVar7 < (double)m_Do_ext::0_0) {
    local_38 = (double)CONCAT44(0x43300000,(int)this->mpFrameCtrl->mEndFrame ^ 0x80000000);
    this->mpFrameCtrl->mCurrentTime = (float)(local_38 - m_Do_ext::_4289);
  }
  else {
    local_38 = (double)CONCAT44(0x43300000,(int)startFrame ^ 0x80000000);
    this->mpFrameCtrl->mCurrentTime = (float)(local_38 - m_Do_ext::_4289);
  }
  this->mpFrameCtrl->mLoopFrame = (short)(int)this->mpFrameCtrl->mCurrentTime;
  uVar4 = 1;
LAB_8000df04:
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return uVar4;
}


/* __thiscall mDoExt_baseAnm::play(void) */

undefined4 __thiscall mDoExt_baseAnm::play(mDoExt_baseAnm *this)

{
  ulong uVar1;
  undefined4 uVar2;
  
  if (this->mpFrameCtrl == (J3DFrameCtrl *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"m_Do_ext.cpp",0x1ce,"mFrameCtrl != 0");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x1ce,"Halt");
  }
  J3DFrameCtrl::update(this->mpFrameCtrl);
  uVar2 = 1;
  if (((this->mpFrameCtrl->mFlags & 1) == 0) && (m_Do_ext::0_0 != this->mpFrameCtrl->mSpeed)) {
    uVar2 = 0;
  }
  return uVar2;
}


/* __thiscall mDoExt_bpkAnm::init(J3DModelData *,
                                  J3DAnmColor *,
                                  int,
                                  int,
                                  float,
                                  short,
                                  short,
                                  bool,
                                  int) */

int __thiscall mDoExt_bpkAnm::init(mDoExt_bpkAnm *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = init(this,ctx + 0x58);
  return iVar1;
}


/* __thiscall mDoExt_bpkAnm::entry(J3DModelData *,
                                   float) */

void __thiscall mDoExt_bpkAnm::entry(mDoExt_bpkAnm *this,J3DModelData *param_1,float param_2)

{
  entry(this,&param_1->mMaterialTable,param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* __thiscall mDoExt_bpkAnm::init(J3DMaterialTable *,
                                  J3DAnmColor *,
                                  int,
                                  int,
                                  float,
                                  short,
                                  short,
                                  bool,
                                  int) */

int __thiscall mDoExt_bpkAnm::init(mDoExt_bpkAnm *this,EVP_PKEY_CTX *ctx)

{
  ushort uVar1;
  bool bVar2;
  char cVar6;
  ulong uVar3;
  undefined4 uVar4;
  int iVar5;
  ushort *puVar7;
  int in_r5;
  ushort uVar8;
  int in_r6;
  J3DFrameCtrl__LoopMode in_r7;
  short in_r8;
  short in_r9;
  bool in_r10;
  double in_f1;
  int in_stack_00000008;
  
  bVar2 = false;
  if ((in_r10 != false) || (cVar6 = m_Do_ext::isCurrentSolidHeap(), cVar6 != '\0')) {
    bVar2 = true;
  }
  if (!bVar2) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"m_Do_ext.cpp",0x213,"i_modify || isCurrentSolidHeap()");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x213,"Halt");
  }
  bVar2 = false;
  if ((ctx != (EVP_PKEY_CTX *)0x0) && (in_r5 != 0)) {
    bVar2 = true;
  }
  if (!bVar2) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"m_Do_ext.cpp",0x215,"i_matTable != 0 && i_bpk != 0");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x215,"Halt");
  }
  *(int *)(this + 8) = in_r5;
  J3DAnmColor::searchUpdateMaterialID(*(J3DAnmColor **)(this + 8),(J3DMaterialTable *)ctx);
  uVar1 = *(ushort *)(*(int *)(this + 8) + 0x18);
  if (in_r10 == false) {
    *(ushort *)(this + 0x10) = uVar1;
    if (*(short *)(this + 0x10) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"m_Do_ext.cpp",0x21d,"mUpdateMaterialNum");
      m_Do_printf::OSPanic("m_Do_ext.cpp",0x21d,"Halt");
    }
    uVar8 = *(ushort *)(this + 0x10);
    uVar4 = JKernel::operator_new__((uint)uVar8 * 8 + 0x10);
    uVar4 = Runtime.PPCEABI.H::__construct_new_array
                      (uVar4,J3DMatColorAnm::J3DMatColorAnm,J3DMatColorAnm::_J3DMatColorAnm,8,
                       (uint)uVar8);
    *(undefined4 *)(this + 0xc) = uVar4;
    if (*(int *)(this + 0xc) == 0) {
      return 0;
    }
  }
  if (*(ushort *)(this + 0x10) < uVar1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"m_Do_ext.cpp",0x224,"updateMaterialNum <= mUpdateMaterialNum");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x224,"Halt");
  }
  puVar7 = *(ushort **)(this + 0xc);
  for (uVar8 = 0; uVar8 < uVar1; uVar8 = uVar8 + 1) {
    *(undefined4 *)(puVar7 + 2) = *(undefined4 *)(this + 8);
    *puVar7 = uVar8;
    puVar7 = puVar7 + 4;
  }
  if ((in_r10 == false) && (in_stack_00000008 != 0)) {
    J3DMaterialTable::setMatColorAnimator
              ((J3DMaterialTable *)ctx,*(J3DAnmColor **)(this + 8),*(J3DMatColorAnm **)(this + 0xc))
    ;
  }
  if ((in_r6 == 0) ||
     (iVar5 = ::mDoExt_baseAnm::initPlay
                        ((mDoExt_baseAnm *)this,*(short *)(*(int *)(this + 8) + 6),in_r7,
                         (float)in_f1,in_r8,in_r9,in_r10), iVar5 != 0)) {
    iVar5 = 1;
  }
  else {
    iVar5 = 0;
  }
  return iVar5;
}


/* __thiscall J3DMatColorAnm::~J3DMatColorAnm(void) */

void __thiscall J3DMatColorAnm::_J3DMatColorAnm(J3DMatColorAnm *this)

{
  short in_r4;
  
  if ((this != (J3DMatColorAnm *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall J3DMatColorAnm::J3DMatColorAnm(void) */

void __thiscall J3DMatColorAnm::J3DMatColorAnm(J3DMatColorAnm *this)

{
  *(undefined4 *)(this + 4) = 0;
  *(undefined2 *)this = 0;
  return;
}


/* __thiscall mDoExt_bpkAnm::entry(J3DMaterialTable *,
                                   float) */

void __thiscall mDoExt_bpkAnm::entry(mDoExt_bpkAnm *this,J3DMaterialTable *param_1,float param_2)

{
  *(float *)(*(int *)(this + 8) + 8) = param_2;
  J3DMaterialTable::setMatColorAnimator
            (param_1,*(J3DAnmColor **)(this + 8),*(J3DMatColorAnm **)(this + 0xc));
  return;
}


/* __thiscall mDoExt_btpAnm::init(J3DModelData *,
                                  J3DAnmTexPattern *,
                                  int,
                                  int,
                                  float,
                                  short,
                                  short,
                                  bool,
                                  int) */

int __thiscall
mDoExt_btpAnm::init(mDoExt_btpAnm *this,J3DModelData *param_1,J3DAnmTexPattern *param_2,int param_3,
                   int param_4,float param_5,short param_6,short param_7,bool param_8,int param_9)

{
  int iVar1;
  
  iVar1 = init(this,(EVP_PKEY_CTX *)&param_1->mMaterialTable);
  return iVar1;
}


/* __thiscall mDoExt_btpAnm::entry(J3DModelData *,
                                   short) */

void __thiscall mDoExt_btpAnm::entry(mDoExt_btpAnm *this,J3DModelData *param_1,short param_2)

{
  entry(this,&param_1->mMaterialTable,param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* __thiscall mDoExt_btpAnm::init(J3DMaterialTable *,
                                  J3DAnmTexPattern *,
                                  int,
                                  int,
                                  float,
                                  short,
                                  short,
                                  bool,
                                  int) */

int __thiscall mDoExt_btpAnm::init(mDoExt_btpAnm *this,EVP_PKEY_CTX *ctx)

{
  ushort uVar1;
  bool bVar2;
  char cVar7;
  ulong uVar3;
  undefined4 uVar4;
  J3DTexNoAnm *pJVar5;
  int iVar6;
  J3DAnmTexPattern *in_r5;
  ushort uVar8;
  int in_r6;
  J3DFrameCtrl__LoopMode in_r7;
  short in_r8;
  short in_r9;
  bool in_r10;
  double in_f1;
  int in_stack_00000008;
  
  bVar2 = false;
  if ((in_r10 != false) || (cVar7 = m_Do_ext::isCurrentSolidHeap(), cVar7 != '\0')) {
    bVar2 = true;
  }
  if (!bVar2) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"m_Do_ext.cpp",0x288,"i_modify || isCurrentSolidHeap()");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x288,"Halt");
  }
  bVar2 = false;
  if ((ctx != (EVP_PKEY_CTX *)0x0) && (in_r5 != (J3DAnmTexPattern *)0x0)) {
    bVar2 = true;
  }
  if (!bVar2) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"m_Do_ext.cpp",0x28a,"i_matTable != 0 && i_btp != 0");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x28a,"Halt");
  }
  this->mpAnmPattern = in_r5;
  J3DAnmTexPattern::searchUpdateMaterialID(this->mpAnmPattern,(J3DMaterialTable *)ctx);
  uVar1 = *(ushort *)&this->mpAnmPattern[1].field_0x2;
  if (in_r10 == false) {
    this->mUpdateMaterialAnm = uVar1;
    if (this->mUpdateMaterialAnm == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"m_Do_ext.cpp",0x292,"mUpdateMaterialNum");
      m_Do_printf::OSPanic("m_Do_ext.cpp",0x292,"Halt");
    }
    uVar8 = this->mUpdateMaterialAnm;
    uVar4 = JKernel::operator_new__((uint)uVar8 * 0xc + 0x10);
    pJVar5 = (J3DTexNoAnm *)
             Runtime.PPCEABI.H::__construct_new_array
                       (uVar4,J3DTexNoAnm::J3DTexNoAnm,J3DTexNoAnm::_J3DTexNoAnm,0xc,(uint)uVar8);
    this->mpTexNoAnm = pJVar5;
    if (this->mpTexNoAnm == (J3DTexNoAnm *)0x0) {
      return 0;
    }
  }
  if ((ushort)this->mUpdateMaterialAnm < uVar1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"m_Do_ext.cpp",0x299,"updateMaterialNum <= mUpdateMaterialNum");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x299,"Halt");
  }
  pJVar5 = this->mpTexNoAnm;
  for (uVar8 = 0; uVar8 < uVar1; uVar8 = uVar8 + 1) {
    *(J3DAnmTexPattern **)&pJVar5->field_0x8 = this->mpAnmPattern;
    pJVar5->field_0x4 = uVar8;
    pJVar5 = pJVar5 + 1;
  }
  if ((in_r10 == false) && (in_stack_00000008 != 0)) {
    J3DMaterialTable::setTexNoAnimator((J3DMaterialTable *)ctx,this->mpAnmPattern,this->mpTexNoAnm);
  }
  if ((in_r6 == 0) ||
     (iVar6 = ::mDoExt_baseAnm::initPlay
                        (&this->parent,this->mpAnmPattern->field_0x6,in_r7,(float)in_f1,in_r8,in_r9,
                         in_r10), iVar6 != 0)) {
    iVar6 = 1;
  }
  else {
    iVar6 = 0;
  }
  return iVar6;
}


/* __thiscall J3DTexNoAnm::~J3DTexNoAnm(void) */

void __thiscall J3DTexNoAnm::_J3DTexNoAnm(J3DTexNoAnm *this)

{
  short in_r4;
  
  if ((this != (J3DTexNoAnm *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall J3DTexNoAnm::J3DTexNoAnm(void) */

void __thiscall J3DTexNoAnm::J3DTexNoAnm(J3DTexNoAnm *this)

{
  this->vtbl = (undefined *)&__vt;
  *(undefined4 *)&this->field_0x8 = 0;
  this->field_0x4 = 0;
  return;
}


/* __thiscall mDoExt_btpAnm::entry(J3DMaterialTable *,
                                   short) */

void __thiscall mDoExt_btpAnm::entry(mDoExt_btpAnm *this,J3DMaterialTable *param_1,short param_2)

{
  this->mpAnmPattern->field_0x8 =
       (float)((double)CONCAT44(0x43300000,(int)param_2 ^ 0x80000000) - m_Do_ext::_4289);
  J3DMaterialTable::setTexNoAnimator(param_1,this->mpAnmPattern,this->mpTexNoAnm);
  return;
}


/* __thiscall mDoExt_btkAnm::init(J3DModelData *,
                                  J3DAnmTextureSRTKey *,
                                  int,
                                  int,
                                  float,
                                  short,
                                  short,
                                  bool,
                                  int) */

int __thiscall
mDoExt_btkAnm::init(mDoExt_btkAnm *this,J3DModelData *pModelData,J3DAnmTextureSRTKey *pAnm,
                   bool bDoInit,J3DFrameCtrl__LoopMode loopMode,float speed,short start,short end,
                   bool i_modify,int sound)

{
  int iVar1;
  
  iVar1 = init(this,&pModelData->mMaterialTable,pAnm,bDoInit,loopMode,speed,start,end,i_modify,sound
              );
  return iVar1;
}


/* __thiscall mDoExt_btkAnm::entry(J3DModelData *,
                                   float) */

void __thiscall mDoExt_btkAnm::entry(mDoExt_btkAnm *this,J3DModelData *param_1,float param_2)

{
  entry(this,&param_1->mMaterialTable,param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* WARNING: Removing unreachable block (ram,0x8000eac4) */
/* __thiscall mDoExt_btkAnm::init(J3DMaterialTable *,
                                  J3DAnmTextureSRTKey *,
                                  int,
                                  int,
                                  float,
                                  short,
                                  short,
                                  bool,
                                  int) */

int __thiscall
mDoExt_btkAnm::init(mDoExt_btkAnm *this,J3DMaterialTable *i_matTbl,J3DAnmTextureSRTKey *i_btk,
                   bool bStartPlaying,J3DFrameCtrl__LoopMode loopMode,float param_5,short param_6,
                   short param_7,bool i_modify,int param_9)

{
  bool bVar1;
  uint uVar2;
  char cVar9;
  ulong uVar3;
  J3DTexGenBlockPatched *pJVar4;
  undefined *puVar5;
  undefined4 uVar6;
  J3DTexMtxAnm *pJVar7;
  int iVar8;
  ushort uVar10;
  int iVar11;
  undefined3 in_register_00000018;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  undefined4 uVar16;
  double dVar17;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar17 = (double)param_5;
  uVar16 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  bVar1 = false;
  if ((i_modify != false) || (cVar9 = m_Do_ext::isCurrentSolidHeap(), cVar9 != '\0')) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"m_Do_ext.cpp",0x30d,"i_modify || isCurrentSolidHeap()");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x30d,"Halt");
  }
  bVar1 = false;
  if ((i_matTbl != (J3DMaterialTable *)0x0) && (i_btk != (J3DAnmTextureSRTKey *)0x0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"m_Do_ext.cpp",0x30f,"i_matTable != 0 && i_btk != 0");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x30f,"Halt");
  }
  this->mpAnmSRT = i_btk;
  J3DAnmTextureSRTKey::searchUpdateMaterialID(this->mpAnmSRT,i_matTbl);
  uVar2 = (ushort)this->mpAnmSRT->mTrackCount / 3;
  if (i_modify == false) {
    this->mUpdateMaterialNum = (short)uVar2;
    if (this->mUpdateMaterialNum == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"m_Do_ext.cpp",0x317,"mUpdateMaterialNum");
      m_Do_printf::OSPanic("m_Do_ext.cpp",0x317,"Halt");
    }
    for (uVar14 = 0; uVar13 = (uint)(ushort)this->mUpdateMaterialNum, (uVar14 & 0xffff) < uVar13;
        uVar14 = uVar14 + 1) {
      uVar13 = (uint)(ushort)((this->mpAnmSRT->mMaterialNameTable).mpRes)->mEntries
                             [(uVar14 & 0xffff) - 2];
      if (uVar13 != 0xffff) {
        cVar9 = (this->mpAnmSRT->mMaterialNameTable).vtbl[uVar14 & 0xffff];
        if (((cVar9 != -1) &&
            (pJVar4 = i_matTbl->mpMaterials[uVar13]->mpTexGenBlock,
            iVar8 = (*(code *)pJVar4->vtbl->getTexMtx)(pJVar4,cVar9), iVar8 == 0)) &&
           (puVar5 = (undefined *)JKernel::operator_new(0xc4), puVar5 != (undefined *)0x0)) {
          iVar12 = 0;
          iVar8 = 0;
          do {
            iVar11 = 0;
            iVar15 = 4;
            do {
              *(undefined4 *)(puVar5 + iVar11 + 0x24 + iVar8) =
                   *(undefined4 *)(&J3DGraphBase::j3dDefaultTexMtxInfo + iVar11 + 0x24 + iVar8);
              iVar11 = iVar11 + 4;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            iVar12 = iVar12 + 1;
            iVar8 = iVar8 + 0x10;
          } while (iVar12 < 4);
          *(undefined4 *)(puVar5 + 4) = DAT_80370d70;
          *(undefined4 *)(puVar5 + 8) = DAT_80370d74;
          *(undefined4 *)(puVar5 + 0xc) = DAT_80370d78;
          *puVar5 = J3DGraphBase::j3dDefaultTexMtxInfo;
          puVar5[1] = DAT_80370d6d;
          *(undefined4 *)(puVar5 + 0x10) = DAT_80370d7c;
          *(undefined4 *)(puVar5 + 0x14) = DAT_80370d80;
          *(undefined2 *)(puVar5 + 0x18) = DAT_80370d84;
          *(undefined4 *)(puVar5 + 0x1c) = DAT_80370d88;
          *(undefined4 *)(puVar5 + 0x20) = DAT_80370d8c;
        }
      }
    }
    uVar6 = JKernel::operator_new__(uVar13 * 8 + 0x10);
    pJVar7 = (J3DTexMtxAnm *)
             Runtime.PPCEABI.H::__construct_new_array
                       (uVar6,J3DTexMtxAnm::J3DTexMtxAnm,J3DTexMtxAnm::_J3DTexMtxAnm,8,uVar13);
    this->mpTexMtxAnm = pJVar7;
    if (this->mpTexMtxAnm == (J3DTexMtxAnm *)0x0) {
      iVar8 = 0;
      goto LAB_8000eac4;
    }
  }
  if ((ushort)this->mUpdateMaterialNum < uVar2) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"m_Do_ext.cpp",0x32b,"updateMaterialNum <= mUpdateMaterialNum");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x32b,"Halt");
  }
  pJVar7 = this->mpTexMtxAnm;
  for (uVar10 = 0; uVar10 < uVar2; uVar10 = uVar10 + 1) {
    pJVar7->mpAnm = this->mpAnmSRT;
    pJVar7->mMatIndex = uVar10;
    pJVar7 = pJVar7 + 1;
  }
  if ((i_modify == false) && (param_9 != 0)) {
    J3DMaterialTable::setTexMtxAnimator
              (i_matTbl,this->mpAnmSRT,this->mpTexMtxAnm,(J3DTexMtxAnm *)0x0);
  }
  if ((CONCAT31(in_register_00000018,bStartPlaying) == 0) ||
     (iVar8 = ::mDoExt_baseAnm::initPlay
                        (&this->parent,(this->mpAnmSRT->parent).mDuration,loopMode,(float)dVar17,
                         param_6,param_7,i_modify), iVar8 != 0)) {
    iVar8 = 1;
  }
  else {
    iVar8 = 0;
  }
LAB_8000eac4:
  __psq_l0(auStack8,uVar16);
  __psq_l1(auStack8,uVar16);
  return iVar8;
}


/* __thiscall J3DTexMtxAnm::~J3DTexMtxAnm(void) */

void __thiscall J3DTexMtxAnm::_J3DTexMtxAnm(J3DTexMtxAnm *this)

{
  short in_r4;
  
  if ((this != (J3DTexMtxAnm *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall J3DTexMtxAnm::J3DTexMtxAnm(void) */

void __thiscall J3DTexMtxAnm::J3DTexMtxAnm(J3DTexMtxAnm *this)

{
  this->mMatIndex = 0;
  this->mpAnm = (J3DAnmTextureSRTKey *)0x0;
  return;
}


/* __thiscall J3DTexGenBlock::getTexMtx(unsigned long) */

undefined4 __thiscall J3DTexGenBlock::getTexMtx(J3DTexGenBlock *this,ulong param_1)

{
  return 0;
}


/* __thiscall mDoExt_btkAnm::entry(J3DMaterialTable *,
                                   float) */

void __thiscall mDoExt_btkAnm::entry(mDoExt_btkAnm *this,J3DMaterialTable *param_1,float param_2)

{
  (this->mpAnmSRT->parent).mCurrentTime = param_2;
  J3DMaterialTable::setTexMtxAnimator(param_1,this->mpAnmSRT,this->mpTexMtxAnm,(J3DTexMtxAnm *)0x0);
  return;
}


/* __thiscall mDoExt_brkAnm::init(J3DModelData *,
                                  J3DAnmTevRegKey *,
                                  int,
                                  int,
                                  float,
                                  short,
                                  short,
                                  bool,
                                  int) */

int __thiscall
mDoExt_brkAnm::init(mDoExt_brkAnm *this,J3DModelData *param_1,J3DAnmTevRegKey *param_2,bool param_3,
                   J3DFrameCtrl__LoopMode param_4,float param_5,short param_6,short param_7,
                   bool param_8,int param_9)

{
  int iVar1;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  iVar1 = init(this,&param_1->mMaterialTable,param_2,CONCAT31(in_register_00000018,param_3),
               CONCAT31(in_register_0000001c,param_4),param_5,param_6,param_7,param_8,param_9);
  return iVar1;
}


/* __thiscall mDoExt_brkAnm::entry(J3DModelData *,
                                   float) */

void __thiscall mDoExt_brkAnm::entry(mDoExt_brkAnm *this,J3DModelData *param_1,float param_2)

{
  entry(this,&param_1->mMaterialTable,param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* __thiscall mDoExt_brkAnm::init(J3DMaterialTable *,
                                  J3DAnmTevRegKey *,
                                  int,
                                  int,
                                  float,
                                  short,
                                  short,
                                  bool,
                                  int) */

int __thiscall
mDoExt_brkAnm::init(mDoExt_brkAnm *this,J3DMaterialTable *pMatTbl,J3DAnmTevRegKey *pRegKey,
                   int param_3,int param_4,float param_5,short param_6,short param_7,bool i_modify,
                   int param_9)

{
  ushort uVar1;
  bool bVar2;
  char cVar8;
  ulong uVar3;
  undefined4 uVar4;
  J3DTevColorAnm *pJVar5;
  J3DTevKColorAnm *pJVar6;
  int iVar7;
  ushort uVar9;
  ushort uVar10;
  double dVar11;
  
  dVar11 = (double)param_5;
  bVar2 = false;
  if ((i_modify != false) || (cVar8 = m_Do_ext::isCurrentSolidHeap(), cVar8 != '\0')) {
    bVar2 = true;
  }
  if (!bVar2) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"m_Do_ext.cpp",0x38e,"i_modify || isCurrentSolidHeap()");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x38e,"Halt");
  }
  bVar2 = false;
  if ((pMatTbl != (J3DMaterialTable *)0x0) && (pRegKey != (J3DAnmTevRegKey *)0x0)) {
    bVar2 = true;
  }
  if (!bVar2) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"m_Do_ext.cpp",0x390,"i_matTable != 0 && i_brk != 0");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x390,"Halt");
  }
  this->mpAnm = pRegKey;
  J3DAnmTevRegKey::searchUpdateMaterialID(this->mpAnm,pMatTbl);
  uVar10 = *(ushort *)(this->mpAnm + 0x10);
  if (i_modify == false) {
    this->mCRegUpdateMaterialNum = uVar10;
    uVar1 = this->mCRegUpdateMaterialNum;
    uVar4 = JKernel::operator_new__((uint)uVar1 * 8 + 0x10);
    pJVar5 = (J3DTevColorAnm *)
             Runtime.PPCEABI.H::__construct_new_array
                       (uVar4,J3DTevColorAnm::J3DTevColorAnm,J3DTevColorAnm::_J3DTevColorAnm,8,
                        (uint)uVar1);
    this->mpCRegAnm = pJVar5;
    if (this->mpCRegAnm == (J3DTevColorAnm *)0x0) {
      return 0;
    }
  }
  if (this->mCRegUpdateMaterialNum < uVar10) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar3,"m_Do_ext.cpp",0x39e,"CRegUpdateMaterialNum <= mCRegUpdateMaterialNum");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x39e,"Halt");
  }
  uVar1 = *(ushort *)(this->mpAnm + 0x12);
  if (i_modify == false) {
    this->mKRegUpdateMaterialNum = uVar1;
    uVar9 = this->mKRegUpdateMaterialNum;
    uVar4 = JKernel::operator_new__((uint)uVar9 * 8 + 0x10);
    pJVar6 = (J3DTevKColorAnm *)
             Runtime.PPCEABI.H::__construct_new_array
                       (uVar4,J3DTevKColorAnm::J3DTevKColorAnm,J3DTevKColorAnm::_J3DTevKColorAnm,8,
                        (uint)uVar9);
    this->mpKRegAnm = pJVar6;
    if (this->mpKRegAnm == (J3DTevKColorAnm *)0x0) {
      return 0;
    }
  }
  if (this->mKRegUpdateMaterialNum < uVar1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar3,"m_Do_ext.cpp",0x3a9,"KRegUpdateMaterialNum <= mKRegUpdateMaterialNum");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x3a9,"Halt");
  }
  pJVar5 = this->mpCRegAnm;
  for (uVar9 = 0; uVar9 < uVar10; uVar9 = uVar9 + 1) {
    pJVar5->mIdx = uVar9;
    pJVar5->mpAnm = this->mpAnm;
    pJVar5 = pJVar5 + 1;
  }
  pJVar6 = this->mpKRegAnm;
  for (uVar10 = 0; uVar10 < uVar1; uVar10 = uVar10 + 1) {
    pJVar6->mIdx = uVar10;
    pJVar6->mpAnm = this->mpAnm;
    pJVar6 = pJVar6 + 1;
  }
  if ((i_modify == false) && (param_9 != 0)) {
    J3DMaterialTable::setTevRegAnimator(pMatTbl,this->mpAnm,this->mpCRegAnm,this->mpKRegAnm);
  }
  if ((param_3 == 0) ||
     (iVar7 = ::mDoExt_baseAnm::initPlay
                        (&this->parent,*(short *)(this->mpAnm + 6),(J3DFrameCtrl__LoopMode)param_4,
                         (float)dVar11,param_6,param_7,i_modify), iVar7 != 0)) {
    iVar7 = 1;
  }
  else {
    iVar7 = 0;
  }
  return iVar7;
}


/* __thiscall J3DTevKColorAnm::~J3DTevKColorAnm(void) */

void __thiscall J3DTevKColorAnm::_J3DTevKColorAnm(J3DTevKColorAnm *this)

{
  short in_r4;
  
  if ((this != (J3DTevKColorAnm *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall J3DTevKColorAnm::J3DTevKColorAnm(void) */

void __thiscall J3DTevKColorAnm::J3DTevKColorAnm(J3DTevKColorAnm *this)

{
  this->mpAnm = (J3DAnmTevRegKey *)0x0;
  this->mIdx = 0;
  return;
}


/* __thiscall J3DTevColorAnm::~J3DTevColorAnm(void) */

void __thiscall J3DTevColorAnm::_J3DTevColorAnm(J3DTevColorAnm *this)

{
  short in_r4;
  
  if ((this != (J3DTevColorAnm *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall J3DTevColorAnm::J3DTevColorAnm(void) */

void __thiscall J3DTevColorAnm::J3DTevColorAnm(J3DTevColorAnm *this)

{
  this->mpAnm = (J3DAnmTevRegKey *)0x0;
  this->mIdx = 0;
  return;
}


/* __thiscall mDoExt_brkAnm::entry(J3DMaterialTable *,
                                   float) */

void __thiscall mDoExt_brkAnm::entry(mDoExt_brkAnm *this,J3DMaterialTable *param_1,float param_2)

{
  *(float *)(this->mpAnm + 8) = param_2;
  J3DMaterialTable::setTevRegAnimator(param_1,this->mpAnm,this->mpCRegAnm,this->mpKRegAnm);
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* __thiscall mDoExt_bvaAnm::init(J3DModel *,
                                  J3DAnmVisibilityFull *,
                                  int,
                                  int,
                                  float,
                                  short,
                                  short,
                                  bool,
                                  int) */

int __thiscall
mDoExt_bvaAnm::init(mDoExt_bvaAnm *this,J3DModel *ctx,J3DAnmVisibilityFull *param_2,int param_3,
                   int param_4,float param_5,short param_6,short param_7,bool param_8,int param_9)

{
  bool bVar1;
  char cVar4;
  ulong uVar2;
  J3DVisibilityManager *local_r3_260;
  int iVar3;
  J3DAnmVisibilityFull *pJVar5;
  double dVar6;
  
  dVar6 = (double)param_5;
  bVar1 = false;
  if ((param_8 != false) || (cVar4 = m_Do_ext::isCurrentSolidHeap(), cVar4 != '\0')) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"m_Do_ext.cpp",0x3ea,"i_modify || isCurrentSolidHeap()");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x3ea,"Halt");
  }
  bVar1 = false;
  if ((ctx != (J3DModel *)0x0) && (param_2 != (J3DAnmVisibilityFull *)0x0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"m_Do_ext.cpp",0x3ec,"i_model != 0 && i_bva != 0");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x3ec,"Halt");
  }
  this->mpAnm = param_2;
  if (param_8 == false) {
    local_r3_260 = (J3DVisibilityManager *)JKernel::operator_new(0xc);
    if (local_r3_260 != (J3DVisibilityManager *)0x0) {
      pJVar5 = this->mpAnm;
      local_r3_260->vtbl = (undefined *)&J3DVisibilityManager::__vt;
      local_r3_260->mpAnm = pJVar5;
      local_r3_260->mbActive = 1;
    }
    this->mpVisibilityManager = local_r3_260;
    if (this->mpVisibilityManager == (J3DVisibilityManager *)0x0) {
      return 0;
    }
    if (param_9 != 0) {
      ctx->mpVisibilityManager = this->mpVisibilityManager;
    }
  }
  else {
    this->mpVisibilityManager->mpAnm = this->mpAnm;
  }
  if ((param_3 == 0) ||
     (iVar3 = ::mDoExt_baseAnm::initPlay
                        (&this->parent,*(short *)(this->mpAnm + 6),(J3DFrameCtrl__LoopMode)param_4,
                         (float)dVar6,param_6,param_7,param_8), iVar3 != 0)) {
    iVar3 = 1;
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}


/* __thiscall mDoExt_bvaAnm::entry(J3DModel *,
                                   short) */

void __thiscall mDoExt_bvaAnm::entry(mDoExt_bvaAnm *this,J3DModel *param_1,short param_2)

{
  *(float *)(this->mpAnm + 8) =
       (float)((double)CONCAT44(0x43300000,(int)param_2 ^ 0x80000000) - m_Do_ext::_4289);
  param_1->mpVisibilityManager = this->mpVisibilityManager;
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x8000f3e8) */
/* __thiscall mDoExt_bckAnm::init(J3DModelData *,
                                  J3DAnmTransform *,
                                  int,
                                  int,
                                  float,
                                  short,
                                  short,
                                  bool) */

int __thiscall
mDoExt_bckAnm::init(mDoExt_bckAnm *this,J3DModelData *ctx,J3DAnmTransform *param_2,bool param_3,
                   J3DFrameCtrl__LoopMode param_4,float param_5,short param_6,short param_7,
                   bool param_8)

{
  bool bVar1;
  float fVar2;
  char cVar5;
  ulong uVar3;
  J3DMtxCalcBasic *pMtxCalc;
  int iVar4;
  J3DMtxCalc *pJVar6;
  undefined3 in_register_00000018;
  int iVar7;
  J3DAnmTransform *pJVar8;
  int iVar9;
  undefined4 uVar10;
  double dVar11;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar11 = (double)param_5;
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  bVar1 = false;
  if ((param_8 != false) || (cVar5 = m_Do_ext::isCurrentSolidHeap(), cVar5 != '\0')) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"m_Do_ext.cpp",0x429,"i_modify || isCurrentSolidHeap()");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x429,"Halt");
  }
  if (param_2 == (J3DAnmTransform *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"m_Do_ext.cpp",0x42b,"i_bck != 0");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x42b,"Halt");
  }
  this->mpAnmTransform = param_2;
  if (param_8 == false) {
    pMtxCalc = (J3DMtxCalcBasic *)JKernel::operator_new(0x80);
    if (pMtxCalc != (J3DMtxCalcBasic *)0x0) {
      pJVar8 = this->mpAnmTransform;
      pJVar6 = (J3DMtxCalc *)(pMtxCalc[1].mCurrentMtx.m + 1);
      pMtxCalc->vderiv = pJVar6;
      pMtxCalc[1].vderiv = pJVar6;
      pMtxCalc[1].mCurrentMtx.m[1] = (float)&J3DMtxCalc::__vt;
      J3DMtxCalcBasic::J3DMtxCalcBasic(pMtxCalc);
      pMtxCalc->vtbl = &J3DMtxCalcMaya::__vt;
      pMtxCalc->vderiv->vtbl = &DAT_8039eba4;
      pMtxCalc->vderiv[9].vtbl = (undefined *)((int)pMtxCalc + (0x50 - (int)pMtxCalc->vderiv));
      pMtxCalc[1].mCurrentMtx.m[0] = (float)&J3DMtxCalcAnm::__vt;
      (pMtxCalc[1].vderiv)->vtbl = &DAT_8039ec34;
      pMtxCalc[1].vderiv[9].vtbl = (undefined *)((int)pMtxCalc + (0x58 - (int)pMtxCalc[1].vderiv));
      fVar2 = m_Do_ext::0_0;
      pJVar6 = pMtxCalc[1].vderiv;
      iVar4 = 0;
      iVar9 = 4;
      do {
        iVar7 = (int)&pJVar6->vtbl + iVar4;
        *(undefined4 *)(iVar7 + 4) = 0;
        *(float *)(iVar7 + 0x14) = fVar2;
        iVar4 = iVar4 + 4;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      pMtxCalc[1].vderiv[1].vtbl = (undefined *)pJVar8;
      pMtxCalc->vtbl = &J3DMtxCalcMayaAnm::__vt;
      pMtxCalc->vderiv->vtbl = &DAT_80371cc0;
      pMtxCalc[1].mCurrentMtx.m[0] = (float)&PTR_80371cb0;
      pMtxCalc->vderiv[9].vtbl = (undefined *)((int)pMtxCalc + (0x58 - (int)pMtxCalc->vderiv));
    }
    this->mpMtxCalc = (J3DMtxCalc *)pMtxCalc;
    if (this->mpMtxCalc == (J3DMtxCalc *)0x0) {
      iVar4 = 0;
      goto LAB_8000f3e8;
    }
  }
  else {
    *(J3DAnmTransform **)(this->mpMtxCalc->vtbl + 4) = this->mpAnmTransform;
  }
  if ((CONCAT31(in_register_00000018,param_3) == 0) ||
     (iVar4 = ::mDoExt_baseAnm::initPlay
                        (&this->parent,(this->mpAnmTransform->parent).mDuration,param_4,
                         (float)dVar11,param_6,param_7,param_8), iVar4 != 0)) {
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
  }
LAB_8000f3e8:
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  return iVar4;
}


/* __thiscall J3DMtxCalcAnm::~J3DMtxCalcAnm(void) */

void __thiscall J3DMtxCalcAnm::_J3DMtxCalcAnm(J3DMtxCalcAnm *this)

{
  float fVar1;
  int iVar2;
  short in_r4;
  undefined *puVar3;
  int iVar4;
  
  if (this != (J3DMtxCalcAnm *)0x0) {
    this->field_0x4 = (undefined *)&__vt;
    *(undefined **)this->field_0x0 = &DAT_8039ec34;
    *(int *)(this->field_0x0 + 0x24) = (int)this + (8 - (int)this->field_0x0);
    fVar1 = m_Do_ext::0_0;
    puVar3 = this->field_0x0;
    iVar2 = 0;
    iVar4 = 4;
    do {
      *(undefined4 *)(puVar3 + iVar2 + 4) = 0;
      *(float *)(puVar3 + iVar2 + 0x14) = fVar1;
      iVar2 = iVar2 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DMtxCalcMaya::~J3DMtxCalcMaya(void) */

void __thiscall J3DMtxCalcMaya::_J3DMtxCalcMaya(J3DMtxCalcMaya *this)

{
  short in_r4;
  
  if (this != (J3DMtxCalcMaya *)0x0) {
    *(undefined1 **)(this + 0x4c) = &__vt;
    **(undefined4 **)this = &DAT_8039eba4;
    *(int *)(*(int *)this + 0x24) = (int)(this + 0x50) - *(int *)this;
    if (this != (J3DMtxCalcMaya *)0x0) {
      *(J3DMtxCalcBasic__vtbl **)(this + 0x4c) = &J3DMtxCalcBasic::__vt;
      **(undefined ***)this = (undefined *)&PTR_8039ec0c;
      *(int *)(*(int *)this + 0x24) = (int)(this + 0x50) - *(int *)this;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DMtxCalcBasic::~J3DMtxCalcBasic(void) */

void __thiscall J3DMtxCalcBasic::_J3DMtxCalcBasic(J3DMtxCalcBasic *this)

{
  short in_r4;
  
  if (this != (J3DMtxCalcBasic *)0x0) {
    this->vtbl = (undefined *)&__vt;
    this->vderiv->vtbl = (undefined *)&PTR_8039ec0c;
    this->vderiv[9].vtbl = (undefined *)((int)this + (0x50 - (int)this->vderiv));
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall mDoExt_bckAnm::changeBckOnly(J3DAnmTransform *) */

void __thiscall mDoExt_bckAnm::changeBckOnly(mDoExt_bckAnm *this,J3DAnmTransform *param_1)

{
  ulong uVar1;
  
  this->mpAnmTransform = param_1;
  if (this->mpMtxCalc == (J3DMtxCalc *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"m_Do_ext.cpp",0x450,"mAnm != 0");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x450,"Halt");
  }
  *(J3DAnmTransform **)(this->mpMtxCalc->vtbl + 4) = this->mpAnmTransform;
  return;
}


/* __thiscall mDoExt_bckAnm::entry(J3DModelData *,
                                   float) */

void __thiscall mDoExt_bckAnm::entry(mDoExt_bckAnm *this,J3DModelData *param_1,float param_2)

{
  J3DMtxCalc *pMtxCalc;
  
  (this->mpAnmTransform->parent).mCurrentTime = param_2;
  pMtxCalc = this->mpMtxCalc;
  if (pMtxCalc != (J3DMtxCalc *)0x0) {
    pMtxCalc = (J3DMtxCalc *)pMtxCalc->vtbl;
  }
  (*(param_1->mJointTree).mpJoints)->mpMtxCalc = pMtxCalc;
  return;
}


namespace m_Do_ext {

/* __stdcall mDoExt_changeMaterial(J3DModel *) */

void mDoExt_changeMaterial(J3DModel *param_1)

{
  ushort uVar1;
  J3DModelData *pJVar2;
  
  pJVar2 = param_1->mpModelData;
  for (uVar1 = 0; uVar1 < (pJVar2->mMaterialTable).mMaterialCount; uVar1 = uVar1 + 1) {
    (**(code **)((pJVar2->mMaterialTable).mpMaterials[uVar1]->vtbl + 0x28))();
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall mDoExt_modelTexturePatch(J3DModelData *) */

void mDoExt_modelTexturePatch(J3DModelData *param_1)

{
  J3DMaterial *pJVar1;
  undefined4 uVar2;
  ushort uVar3;
  J3DDisplayListObj *pJVar4;
  J3DTevBlock *pJVar5;
  
  J3DGraphBase::j3dSys.mpCurTex = (param_1->mMaterialTable).mpTexture;
  for (uVar3 = 0; uVar3 < (param_1->mMaterialTable).mMaterialCount; uVar3 = uVar3 + 1) {
    pJVar1 = (param_1->mMaterialTable).mpMaterials[uVar3];
    pJVar5 = pJVar1->mpTevBlock;
    pJVar4 = pJVar1->mpDLObj;
    uVar2 = os::OSDisableInterrupts();
    gd::GDInitGDLObj(&J3DDisplayListObj::sGDLObj,pJVar4->mpData[0],pJVar4->mSize);
    gd::__GDCurrentDL = &J3DDisplayListObj::sGDLObj;
    (*(code *)pJVar5->vtbl->patchTexNoAndTexCoordScale)(pJVar5);
    os::OSRestoreInterrupts(uVar2);
    gd::__GDCurrentDL = (undefined1 *)0x0;
  }
  return;
}

}

/* __thiscall J3DTevBlock::patchTexNoAndTexCoordScale(void) */

void __thiscall J3DTevBlock::patchTexNoAndTexCoordScale(J3DTevBlock *this)

{
  return;
}


/* __thiscall J3DPEBlock::patch(void) */

void __thiscall J3DPEBlock::patch(J3DPEBlock *this)

{
  return;
}


/* __thiscall J3DColorBlock::patchLight(void) */

void __thiscall J3DColorBlock::patchLight(J3DColorBlock *this)

{
  return;
}


/* __thiscall J3DTevBlock::patch(void) */

void __thiscall J3DTevBlock::patch(J3DTevBlock *this)

{
  return;
}


namespace m_Do_ext {

/* __stdcall mDoExt_modelDiff(J3DModel *) */

void mDoExt_modelDiff(J3DModel *param_1)

{
  (*(code *)param_1->vtbl->calcMaterial)();
  J3DModel::diff(param_1);
  (*(code *)param_1->vtbl->entry)(param_1);
  return;
}


/* __stdcall mDoExt_modelUpdate(J3DModel *) */

void mDoExt_modelUpdate(J3DModel *param_1)

{
  if (((param_1->mpModelData->mJointTree).mbIsBDL == 1) &&
     ((param_1->mpModelData->mShapeTable).field_0x0 != 1)) {
    (*(code *)param_1->vtbl->calc)();
    mDoExt_modelDiff(param_1);
  }
  else {
    (*(code *)param_1->vtbl->update)(param_1);
    J3DModel::lock(param_1);
  }
  (*(code *)param_1->vtbl->viewCalc)(param_1);
  return;
}


/* __stdcall mDoExt_modelUpdateDL(J3DModel *) */

void mDoExt_modelUpdateDL(J3DModel *param_1)

{
  if (((param_1->mpModelData->mJointTree).mbIsBDL == 1) &&
     ((param_1->mpModelData->mShapeTable).field_0x0 != 1)) {
    (*(code *)param_1->vtbl->calc)();
    mDoExt_modelDiff(param_1);
  }
  else {
    if (d_s_play::g_regHIO.mChild[2].mShorts[9] == 0) {
      J3DModel::unlock(param_1);
    }
    (*(code *)param_1->vtbl->update)(param_1);
    J3DModel::lock(param_1);
  }
  (*(code *)param_1->vtbl->viewCalc)(param_1);
  return;
}


/* __stdcall mDoExt_modelEntry(J3DModel *) */

void mDoExt_modelEntry(J3DModel *param_1)

{
  if (((param_1->mpModelData->mJointTree).mbIsBDL == 1) &&
     ((param_1->mpModelData->mShapeTable).field_0x0 != 1)) {
    mDoExt_modelDiff();
  }
  else {
    (*(code *)param_1->vtbl->entry)(param_1);
    J3DModel::lock(param_1);
  }
  (*(code *)param_1->vtbl->viewCalc)(param_1);
  return;
}


/* __stdcall mDoExt_modelEntryDL(J3DModel *) */

void mDoExt_modelEntryDL(J3DModel *model)

{
  if (((model->mpModelData->mJointTree).mbIsBDL == 1) &&
     ((model->mpModelData->mShapeTable).field_0x0 != 1)) {
    mDoExt_modelDiff();
  }
  else {
    if (d_s_play::g_regHIO.mChild[2].mShorts[9] == 0) {
      J3DModel::unlock(model);
    }
    (*(code *)model->vtbl->entry)(model);
    J3DModel::lock(model);
  }
  (*(code *)model->vtbl->viewCalc)(model);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall mDoExt_backupMatBlock_c::store(J3DMaterial *) */

void __thiscall mDoExt_backupMatBlock_c::store(mDoExt_backupMatBlock_c *this,J3DMaterial *param_1)

{
  mDoExt_backupMatBlock_c mVar8;
  mDoExt_backupMatBlock_c *pmVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  undefined2 uVar7;
  undefined4 *puVar4;
  byte *pbVar5;
  J3DMaterialAnm *pJVar6;
  mDoExt_backupMatBlock_c *pmVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  J3DPEBlockFull *pJVar15;
  J3DColorBlock *pJVar16;
  J3DTexGenBlockPatched *pJVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  J3DTevBlock *pJVar21;
  int iVar22;
  
  pJVar16 = param_1->mpColorBlock;
  mVar8 = (mDoExt_backupMatBlock_c)(*(code *)pJVar16->vtbl->getColorChanNum)(pJVar16);
  this[8] = mVar8;
  uVar19 = 0;
  iVar13 = 0;
  do {
    pmVar1 = (mDoExt_backupMatBlock_c *)(*(code *)pJVar16->vtbl->getMatColor)(pJVar16,uVar19);
    pmVar9 = this + iVar13;
    *pmVar9 = *pmVar1;
    pmVar9[1] = pmVar1[1];
    pmVar9[2] = pmVar1[2];
    pmVar9[3] = pmVar1[3];
    uVar19 = uVar19 + 1;
    iVar13 = iVar13 + 4;
  } while (uVar19 < 2);
  uVar19 = 0;
  iVar13 = 0;
  do {
    puVar2 = (undefined2 *)(*(code *)pJVar16->vtbl->getColorChan)(pJVar16,uVar19);
    *(undefined2 *)(this + iVar13 + 10) = *puVar2;
    uVar19 = uVar19 + 1;
    iVar13 = iVar13 + 2;
  } while (uVar19 < 4);
  uVar19 = 0;
  iVar13 = 0;
  do {
    pmVar1 = (mDoExt_backupMatBlock_c *)(*(code *)pJVar16->vtbl->getAmbColor)(pJVar16,uVar19);
    pmVar9 = this + iVar13;
    pmVar9[0x12] = *pmVar1;
    pmVar9[0x13] = pmVar1[1];
    pmVar9[0x14] = pmVar1[2];
    pmVar9[0x15] = pmVar1[3];
    uVar19 = uVar19 + 1;
    iVar13 = iVar13 + 4;
  } while (uVar19 < 2);
  pJVar17 = param_1->mpTexGenBlock;
  uVar3 = (*(code *)pJVar17->vtbl->getTexGenNum)(pJVar17);
  *(undefined4 *)(this + 0x1c) = uVar3;
  uVar19 = 8;
  iVar13 = (*(code *)pJVar17->vtbl->getType)(pJVar17);
  if (iVar13 == 0x54474234) {
    uVar19 = 4;
  }
  iVar13 = 0;
  for (uVar20 = 0; uVar20 < uVar19; uVar20 = uVar20 + 1) {
    pmVar1 = (mDoExt_backupMatBlock_c *)(*(code *)pJVar17->vtbl->getTexCoord)(pJVar17,uVar20);
    pmVar9 = this + iVar13;
    pmVar9[0x20] = *pmVar1;
    pmVar9[0x21] = pmVar1[1];
    pmVar9[0x22] = pmVar1[2];
    iVar13 = iVar13 + 4;
  }
  iVar13 = 0;
  for (uVar20 = 0; uVar20 < uVar19; uVar20 = uVar20 + 1) {
    iVar18 = (*(code *)pJVar17->vtbl->getTexMtx)(pJVar17,uVar20);
    if (iVar18 != 0) {
      pbVar5 = (byte *)(*(code *)pJVar17->vtbl->getTexMtx)(pJVar17,uVar20);
      copy_bytes((byte *)(this + iVar13 + 0x40),pbVar5,0xc4);
      os::DCStoreRange(this + iVar13 + 0x40,0xc4);
    }
    iVar13 = iVar13 + 0xc4;
  }
  pJVar21 = param_1->mpTevBlock;
  mVar8 = (mDoExt_backupMatBlock_c)(*(code *)pJVar21->vtbl->getTevStageNum)(pJVar21);
  this[0x660] = mVar8;
  uVar19 = 0;
  iVar13 = 0;
  do {
    puVar2 = (undefined2 *)(*(code *)pJVar21->vtbl->getTevColor)(pJVar21,uVar19);
    pmVar1 = this + iVar13;
    *(undefined2 *)(pmVar1 + 0x672) = *puVar2;
    *(undefined2 *)(pmVar1 + 0x674) = puVar2[1];
    *(undefined2 *)(pmVar1 + 0x676) = puVar2[2];
    *(undefined2 *)(pmVar1 + 0x678) = puVar2[3];
    uVar19 = uVar19 + 1;
    iVar13 = iVar13 + 8;
  } while (uVar19 < 4);
  uVar19 = 0;
  iVar13 = 0;
  do {
    pmVar1 = (mDoExt_backupMatBlock_c *)(*(code *)pJVar21->vtbl->getTevKColor)(pJVar21,uVar19);
    pmVar9 = this + iVar13;
    pmVar9[0x692] = *pmVar1;
    pmVar9[0x693] = pmVar1[1];
    pmVar9[0x694] = pmVar1[2];
    pmVar9[0x695] = pmVar1[3];
    uVar19 = uVar19 + 1;
    iVar13 = iVar13 + 4;
  } while (uVar19 < 4);
  uVar19 = 8;
  iVar13 = (*(code *)pJVar21->vtbl->field_0x40)(pJVar21);
  if (iVar13 == 0x54564234) {
    uVar19 = 4;
    uVar20 = 0;
    iVar13 = 0;
    do {
      pmVar1 = (mDoExt_backupMatBlock_c *)(*(code *)pJVar21->vtbl->getTevOrder)(pJVar21,uVar20);
      pmVar9 = this + iVar13;
      pmVar9[0x704] = *pmVar1;
      pmVar9[0x705] = pmVar1[1];
      pmVar9[0x706] = pmVar1[2];
      mVar8 = (mDoExt_backupMatBlock_c)(*(code *)pJVar21->vtbl->getTevKColorSel)(pJVar21,uVar20);
      (this + uVar20)[0x714] = mVar8;
      mVar8 = (mDoExt_backupMatBlock_c)(*(code *)pJVar21->vtbl->getTevKAlphaSel)(pJVar21,uVar20);
      (this + uVar20)[0x718] = mVar8;
      uVar20 = uVar20 + 1;
      iVar13 = iVar13 + 4;
    } while (uVar20 < 4);
    uVar20 = 0;
    do {
      pmVar1 = (mDoExt_backupMatBlock_c *)
               (*(code *)pJVar21->vtbl->getTevSwapModeTable)(pJVar21,uVar20);
      this[uVar20 + 0x71c] = *pmVar1;
      uVar20 = uVar20 + 1;
    } while (uVar20 < 4);
  }
  iVar13 = 0;
  for (uVar20 = 0; uVar20 < uVar19; uVar20 = uVar20 + 1) {
    uVar7 = (*(code *)pJVar21->vtbl->getTexNo)(pJVar21,uVar20);
    *(undefined2 *)(this + iVar13 + 0x662) = uVar7;
    iVar13 = iVar13 + 2;
  }
  iVar18 = 0;
  iVar13 = 0;
  for (uVar20 = 0; uVar20 < uVar19; uVar20 = uVar20 + 1) {
    iVar10 = (*(code *)pJVar21->vtbl->getTevStage)(pJVar21,uVar20);
    pmVar1 = this + iVar13;
    pmVar1[0x6a3] = *(mDoExt_backupMatBlock_c *)(iVar10 + 1);
    pmVar1[0x6a4] = *(mDoExt_backupMatBlock_c *)(iVar10 + 2);
    pmVar1[0x6a5] = *(mDoExt_backupMatBlock_c *)(iVar10 + 3);
    pmVar1[0x6a7] = *(mDoExt_backupMatBlock_c *)(iVar10 + 5);
    pmVar1[0x6a8] = *(mDoExt_backupMatBlock_c *)(iVar10 + 6);
    pmVar1[0x6a9] = *(mDoExt_backupMatBlock_c *)(iVar10 + 7);
    puVar4 = (undefined4 *)(*(code *)pJVar21->vtbl->getIndTevStage)(pJVar21,uVar20);
    *(undefined4 *)(this + iVar18 + 0x6e4) = *puVar4;
    iVar18 = iVar18 + 4;
    iVar13 = iVar13 + 8;
  }
  piVar14 = (int *)param_1->mpIndBlock;
  iVar13 = (**(code **)(*piVar14 + 0x18))(piVar14);
  if (iVar13 == 0x49424c46) {
    mVar8 = (mDoExt_backupMatBlock_c)(**(code **)(*piVar14 + 0x20))(piVar14);
    this[0x720] = mVar8;
    uVar19 = 0;
    iVar13 = 0;
    do {
      pmVar1 = (mDoExt_backupMatBlock_c *)(**(code **)(*piVar14 + 0x2c))(piVar14,uVar19);
      (this + iVar13)[0x721] = *pmVar1;
      (this + iVar13)[0x722] = pmVar1[1];
      uVar19 = uVar19 + 1;
      iVar13 = iVar13 + 4;
    } while (uVar19 < 4);
    uVar19 = 0;
    iVar13 = 0;
    do {
      iVar18 = (**(code **)(*piVar14 + 0x38))(piVar14,uVar19);
      iVar12 = 0;
      iVar10 = 0;
      do {
        iVar11 = 0;
        iVar22 = 3;
        do {
          *(undefined4 *)(this + iVar13 + iVar11 + 0x734 + iVar10) =
               *(undefined4 *)(iVar18 + iVar10 + iVar11);
          iVar11 = iVar11 + 4;
          iVar22 = iVar22 + -1;
        } while (iVar22 != 0);
        iVar12 = iVar12 + 1;
        iVar10 = iVar10 + 0xc;
      } while (iVar12 < 2);
      (this + iVar13)[0x74c] = *(mDoExt_backupMatBlock_c *)(iVar18 + 0x18);
      uVar19 = uVar19 + 1;
      iVar13 = iVar13 + 0x1c;
    } while (uVar19 < 3);
    uVar19 = 0;
    iVar13 = 0;
    do {
      pmVar1 = (mDoExt_backupMatBlock_c *)(**(code **)(*piVar14 + 0x44))(piVar14,uVar19);
      (this + iVar13)[0x788] = *pmVar1;
      (this + iVar13)[0x789] = pmVar1[1];
      uVar19 = uVar19 + 1;
      iVar13 = iVar13 + 4;
    } while (uVar19 < 4);
  }
  pJVar15 = param_1->mpPEBlock;
  pbVar5 = (byte *)(**(code **)(pJVar15->vtbl + 0x2c))(pJVar15);
  copy_bytes((byte *)(this + 0x798),pbVar5,0x2c);
  os::DCStoreRange(this + 0x798,0x2c);
  puVar2 = (undefined2 *)(**(code **)(pJVar15->vtbl + 0x38))(pJVar15);
  *(undefined2 *)(this + 0x7c4) = *puVar2;
  this[0x7c6] = *(mDoExt_backupMatBlock_c *)(puVar2 + 1);
  this[0x7c7] = *(mDoExt_backupMatBlock_c *)((int)puVar2 + 3);
  pmVar1 = (mDoExt_backupMatBlock_c *)(**(code **)(pJVar15->vtbl + 0x44))(pJVar15);
  this[0x7c8] = *pmVar1;
  this[0x7c9] = pmVar1[1];
  this[0x7ca] = pmVar1[2];
  this[0x7cb] = pmVar1[3];
  puVar2 = (undefined2 *)(**(code **)(pJVar15->vtbl + 0x50))(pJVar15);
  *(undefined2 *)(this + 0x7cc) = *puVar2;
  mVar8 = (mDoExt_backupMatBlock_c)(**(code **)(pJVar15->vtbl + 0x5c))(pJVar15);
  this[0x7ce] = mVar8;
  pJVar6 = param_1->mpMaterialAnm;
  if ((J3DMaterialAnm *)0xbfffffff < pJVar6) {
    pJVar6 = (J3DMaterialAnm *)0x0;
  }
  *(J3DMaterialAnm **)(this + 2000) = pJVar6;
  *(uint *)(this + 0x7d4) = param_1->mMaterialMode;
  return;
}


/* __thiscall J3DPEBlock::getZCompLoc(void) const */

undefined4 __thiscall J3DPEBlock::getZCompLoc(J3DPEBlock *this)

{
  return 0;
}


/* __thiscall J3DPEBlock::getZMode(void) */

undefined4 __thiscall J3DPEBlock::getZMode(J3DPEBlock *this)

{
  return 0;
}


/* __thiscall J3DPEBlock::getBlend(void) */

undefined4 __thiscall J3DPEBlock::getBlend(J3DPEBlock *this)

{
  return 0;
}


/* __thiscall J3DPEBlock::getAlphaComp(void) */

undefined4 __thiscall J3DPEBlock::getAlphaComp(J3DPEBlock *this)

{
  return 0;
}


/* __thiscall J3DPEBlock::getFog(void) */

undefined4 __thiscall J3DPEBlock::getFog(J3DPEBlock *this)

{
  return 0;
}


/* __thiscall J3DIndBlock::getIndTexCoordScale(unsigned long) */

undefined4 __thiscall J3DIndBlock::getIndTexCoordScale(J3DIndBlock *this,ulong param_1)

{
  return 0;
}


/* __thiscall J3DIndBlock::getIndTexMtx(unsigned long) */

undefined4 __thiscall J3DIndBlock::getIndTexMtx(J3DIndBlock *this,ulong param_1)

{
  return 0;
}


/* __thiscall J3DIndBlock::getIndTexOrder(unsigned long) */

undefined4 __thiscall J3DIndBlock::getIndTexOrder(J3DIndBlock *this,ulong param_1)

{
  return 0;
}


/* __thiscall J3DIndBlock::getIndTexStageNum(void) const */

undefined4 __thiscall J3DIndBlock::getIndTexStageNum(J3DIndBlock *this)

{
  return 0;
}


/* __thiscall J3DTevBlock::getIndTevStage(unsigned long) */

undefined4 __thiscall J3DTevBlock::getIndTevStage(J3DTevBlock *this,ulong param_1)

{
  return 0;
}


/* __thiscall J3DTevBlock::getTevStage(unsigned long) */

undefined4 __thiscall J3DTevBlock::getTevStage(J3DTevBlock *this,ulong param_1)

{
  return 0;
}


/* __thiscall J3DTevBlock::getTexNo(unsigned long) const */

undefined4 __thiscall J3DTevBlock::getTexNo(J3DTevBlock *this,ulong param_1)

{
  return 0xffff;
}


/* __thiscall J3DTevBlock::getTevSwapModeTable(unsigned long) */

undefined4 __thiscall J3DTevBlock::getTevSwapModeTable(J3DTevBlock *this,ulong param_1)

{
  return 0;
}


/* __thiscall J3DTevBlock::getTevKAlphaSel(unsigned long) */

undefined4 __thiscall J3DTevBlock::getTevKAlphaSel(J3DTevBlock *this,ulong param_1)

{
  return 0;
}


/* __thiscall J3DTevBlock::getTevKColorSel(unsigned long) */

undefined4 __thiscall J3DTevBlock::getTevKColorSel(J3DTevBlock *this,ulong param_1)

{
  return 0;
}


/* __thiscall J3DTevBlock::getTevOrder(unsigned long) */

undefined4 __thiscall J3DTevBlock::getTevOrder(J3DTevBlock *this,ulong param_1)

{
  return 0;
}


/* __thiscall J3DTevBlock::getTevKColor(unsigned long) */

undefined4 __thiscall J3DTevBlock::getTevKColor(J3DTevBlock *this,ulong param_1)

{
  return 0;
}


/* __thiscall J3DTevBlock::getTevColor(unsigned long) */

undefined4 __thiscall J3DTevBlock::getTevColor(J3DTevBlock *this,ulong param_1)

{
  return 0;
}


/* __thiscall J3DTevBlock::getTevStageNum(void) const */

undefined4 __thiscall J3DTevBlock::getTevStageNum(J3DTevBlock *this)

{
  return 1;
}


/* __thiscall J3DTexGenBlock::getTexCoord(unsigned long) */

undefined4 __thiscall J3DTexGenBlock::getTexCoord(J3DTexGenBlock *this,ulong param_1)

{
  return 0;
}


/* __thiscall J3DTexGenBlock::getTexGenNum(void) const */

undefined4 __thiscall J3DTexGenBlock::getTexGenNum(J3DTexGenBlock *this)

{
  return 0;
}


/* __thiscall J3DColorBlock::getAmbColor(unsigned long) */

undefined4 __thiscall J3DColorBlock::getAmbColor(J3DColorBlock *this,ulong param_1)

{
  return 0;
}


/* __thiscall J3DColorBlock::getColorChan(unsigned long) */

undefined4 __thiscall J3DColorBlock::getColorChan(J3DColorBlock *this,ulong param_1)

{
  return 0;
}


/* __thiscall J3DColorBlock::getMatColor(unsigned long) */

undefined4 __thiscall J3DColorBlock::getMatColor(J3DColorBlock *this,ulong param_1)

{
  return 0;
}


/* __thiscall J3DColorBlock::getColorChanNum(void) const */

undefined4 __thiscall J3DColorBlock::getColorChanNum(J3DColorBlock *this)

{
  return 0;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall mDoExt_backupMatBlock_c::restore(J3DMaterial *) */

void __thiscall mDoExt_backupMatBlock_c::restore(mDoExt_backupMatBlock_c *this,J3DMaterial *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  mDoExt_backupMatBlock_c *pmVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  J3DPEBlockFull *pJVar9;
  J3DColorBlock *pJVar10;
  J3DTexGenBlockPatched *pJVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  uint uVar15;
  J3DTevBlock *pJVar16;
  mDoExt_backupMatBlock_c local_78 [4];
  undefined2 local_74 [2];
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  mDoExt_backupMatBlock_c local_5c;
  mDoExt_backupMatBlock_c local_5b;
  mDoExt_backupMatBlock_c local_5a;
  mDoExt_backupMatBlock_c local_59;
  mDoExt_backupMatBlock_c local_58;
  mDoExt_backupMatBlock_c local_57;
  mDoExt_backupMatBlock_c local_56;
  mDoExt_backupMatBlock_c local_55;
  mDoExt_backupMatBlock_c local_54;
  mDoExt_backupMatBlock_c local_53;
  mDoExt_backupMatBlock_c local_52;
  mDoExt_backupMatBlock_c local_51;
  undefined4 local_50;
  undefined4 local_4c;
  undefined2 local_48;
  undefined2 local_46;
  undefined2 local_44;
  undefined2 local_42;
  undefined4 local_40 [9];
  
  pJVar10 = param_1->mpColorBlock;
  (*(code *)pJVar10->vtbl->setColorChanNum_0)(pJVar10,this[8]);
  uVar14 = 0;
  iVar8 = 0;
  do {
    pmVar4 = this + iVar8;
    local_54 = *pmVar4;
    local_53 = pmVar4[1];
    local_52 = pmVar4[2];
    local_51 = pmVar4[3];
    (*(code *)pJVar10->vtbl->setMatColor_1)(pJVar10,uVar14,&local_54);
    uVar14 = uVar14 + 1;
    iVar8 = iVar8 + 4;
  } while (uVar14 < 2);
  uVar14 = 0;
  iVar8 = 0;
  do {
    (*(code *)pJVar10->vtbl->setColorChan_0)(pJVar10,uVar14,this + iVar8 + 10);
    uVar14 = uVar14 + 1;
    iVar8 = iVar8 + 2;
  } while (uVar14 < 4);
  uVar14 = 0;
  iVar8 = 0;
  do {
    pmVar4 = this + iVar8;
    local_58 = pmVar4[0x12];
    local_57 = pmVar4[0x13];
    local_56 = pmVar4[0x14];
    local_55 = pmVar4[0x15];
    (*(code *)pJVar10->vtbl->setAmbColor_1)(pJVar10,uVar14,&local_58);
    uVar14 = uVar14 + 1;
    iVar8 = iVar8 + 4;
  } while (uVar14 < 2);
  pJVar11 = param_1->mpTexGenBlock;
  (*(code *)pJVar11->vtbl->setTexGenNum_1)(pJVar11,*(undefined4 *)(this + 0x1c));
  uVar14 = 8;
  iVar8 = (*(code *)pJVar11->vtbl->getType)(pJVar11);
  if (iVar8 == 0x54474234) {
    uVar14 = 4;
  }
  iVar8 = 0;
  for (uVar15 = 0; uVar15 < uVar14; uVar15 = uVar15 + 1) {
    (*(code *)pJVar11->vtbl->setTexCoord)(pJVar11,uVar15,this + iVar8 + 0x20);
    iVar8 = iVar8 + 4;
  }
  iVar8 = 0;
  for (uVar15 = 0; uVar15 < uVar14; uVar15 = uVar15 + 1) {
    iVar12 = (*(code *)pJVar11->vtbl->getTexMtx)(pJVar11,uVar15);
    if (iVar12 != 0) {
      pbVar5 = (byte *)(*(code *)pJVar11->vtbl->getTexMtx)(pJVar11,uVar15);
      copy_bytes(pbVar5,(byte *)(this + iVar8 + 0x40),0xc4);
      uVar3 = (*(code *)pJVar11->vtbl->getTexMtx)(pJVar11,uVar15);
      os::DCStoreRange(uVar3,0xc4);
    }
    iVar8 = iVar8 + 0xc4;
  }
  pJVar16 = param_1->mpTevBlock;
  (*(code *)pJVar16->vtbl->setTevStageNum_1)(pJVar16,this[0x660]);
  uVar14 = 0;
  iVar8 = 0;
  do {
    pmVar4 = this + iVar8;
    local_48 = *(undefined2 *)(pmVar4 + 0x672);
    local_46 = *(undefined2 *)(pmVar4 + 0x674);
    local_44 = *(undefined2 *)(pmVar4 + 0x676);
    local_42 = *(undefined2 *)(pmVar4 + 0x678);
    (*(code *)pJVar16->vtbl->setTevColor_1)(pJVar16,uVar14,&local_48);
    uVar14 = uVar14 + 1;
    iVar8 = iVar8 + 8;
  } while (uVar14 < 4);
  uVar14 = 0;
  iVar8 = 0;
  do {
    pmVar4 = this + iVar8;
    local_5c = pmVar4[0x692];
    local_5b = pmVar4[0x693];
    local_5a = pmVar4[0x694];
    local_59 = pmVar4[0x695];
    (*(code *)pJVar16->vtbl->setTevKColor_1)(pJVar16,uVar14,&local_5c);
    uVar14 = uVar14 + 1;
    iVar8 = iVar8 + 4;
  } while (uVar14 < 4);
  uVar14 = 8;
  iVar8 = (*(code *)pJVar16->vtbl->field_0x40)(pJVar16);
  if (iVar8 == 0x54564234) {
    uVar14 = 4;
    uVar15 = 0;
    iVar8 = 0;
    do {
      local_60 = *(undefined4 *)(this + iVar8 + 0x704);
      (*(code *)pJVar16->vtbl->setTevOrder_1)(pJVar16,uVar15,&local_60);
      (*(code *)pJVar16->vtbl->setTevKColorSel_1)(pJVar16,uVar15,(this + uVar15)[0x714]);
      (*(code *)pJVar16->vtbl->setTevKAlphaSel_1)(pJVar16,uVar15,(this + uVar15)[0x718]);
      uVar15 = uVar15 + 1;
      iVar8 = iVar8 + 4;
    } while (uVar15 < 4);
    uVar15 = 0;
    do {
      local_78[0] = this[uVar15 + 0x71c];
      (*(code *)pJVar16->vtbl->setTevSwapModeTable_1)(pJVar16,uVar15,local_78);
      uVar15 = uVar15 + 1;
    } while (uVar15 < 4);
  }
  iVar8 = 0;
  for (uVar15 = 0; uVar15 < uVar14; uVar15 = uVar15 + 1) {
    (*(code *)pJVar16->vtbl->setTexNo_1)(pJVar16,uVar15,*(undefined2 *)(this + iVar8 + 0x662));
    iVar8 = iVar8 + 2;
  }
  iVar12 = 0;
  iVar8 = 0;
  for (uVar15 = 0; uVar15 < uVar14; uVar15 = uVar15 + 1) {
    local_50 = *(undefined4 *)(this + iVar8 + 0x6a2);
    local_4c = *(undefined4 *)((int)(this + iVar8 + 0x6a2) + 4);
    (*(code *)pJVar16->vtbl->setTevStage_1)(pJVar16,uVar15,&local_50);
    local_64 = *(undefined4 *)(this + iVar12 + 0x6e4);
    (*(code *)pJVar16->vtbl->setIndTevStage_1)(pJVar16,uVar15,&local_64);
    iVar12 = iVar12 + 4;
    iVar8 = iVar8 + 8;
  }
  piVar13 = (int *)param_1->mpIndBlock;
  iVar8 = (**(code **)(*piVar13 + 0x18))(piVar13);
  if (iVar8 == 0x49424c46) {
    (**(code **)(*piVar13 + 0x1c))(piVar13,this[0x720]);
    uVar14 = 0;
    iVar8 = 0;
    do {
      pmVar4 = (mDoExt_backupMatBlock_c *)(**(code **)(*piVar13 + 0x2c))(piVar13,uVar14);
      *pmVar4 = (this + iVar8)[0x721];
      pmVar4[1] = (this + iVar8)[0x722];
      uVar14 = uVar14 + 1;
      iVar8 = iVar8 + 4;
    } while (uVar14 < 4);
    uVar14 = 0;
    iVar8 = 0;
    do {
      iVar12 = 3;
      puVar1 = (undefined4 *)(this + iVar8 + 0x730);
      puVar2 = (undefined4 *)&local_44;
      do {
        puVar7 = puVar2;
        puVar6 = puVar1;
        uVar3 = puVar6[2];
        puVar7[1] = puVar6[1];
        puVar7[2] = uVar3;
        iVar12 = iVar12 + -1;
        puVar1 = puVar6 + 2;
        puVar2 = puVar7 + 2;
      } while (iVar12 != 0);
      puVar7[3] = puVar6[3];
      (**(code **)(*piVar13 + 0x34))(piVar13,uVar14,local_40);
      uVar14 = uVar14 + 1;
      iVar8 = iVar8 + 0x1c;
    } while (uVar14 < 3);
    uVar14 = 0;
    iVar8 = 0;
    do {
      local_68 = *(undefined4 *)(this + iVar8 + 0x788);
      (**(code **)(*piVar13 + 0x40))(piVar13,uVar14,&local_68);
      uVar14 = uVar14 + 1;
      iVar8 = iVar8 + 4;
    } while (uVar14 < 4);
  }
  pJVar9 = param_1->mpPEBlock;
  pbVar5 = (byte *)(**(code **)(pJVar9->vtbl + 0x2c))(pJVar9);
  copy_bytes(pbVar5,(byte *)(this + 0x798),0x2c);
  uVar3 = (**(code **)(pJVar9->vtbl + 0x2c))(pJVar9);
  os::DCStoreRange(uVar3,0x2c);
  local_6c = *(undefined4 *)(this + 0x7c4);
  (**(code **)(pJVar9->vtbl + 0x34))(pJVar9,&local_6c);
  local_70 = *(undefined4 *)(this + 0x7c8);
  (**(code **)(pJVar9->vtbl + 0x40))(pJVar9,&local_70);
  local_74[0] = *(undefined2 *)(this + 0x7cc);
  (**(code **)(pJVar9->vtbl + 0x4c))(pJVar9,local_74);
  (**(code **)(pJVar9->vtbl + 0x58))(pJVar9,this[0x7ce]);
  param_1->mpMaterialAnm = *(J3DMaterialAnm **)(this + 2000);
  param_1->mMaterialMode = *(uint *)(this + 0x7d4);
  return;
}


/* __thiscall J3DPEBlock::setZCompLoc(unsigned char) */

void __thiscall J3DPEBlock::setZCompLoc(J3DPEBlock *this,uchar param_1)

{
  return;
}


/* __thiscall J3DPEBlock::setZMode(J3DZMode) */

void __thiscall J3DPEBlock::setZMode(J3DPEBlock *this,J3DZMode param_1)

{
  return;
}


/* __thiscall J3DPEBlock::setBlend(J3DBlend) */

void __thiscall J3DPEBlock::setBlend(J3DPEBlock *this,J3DBlend param_1)

{
  return;
}


/* __thiscall J3DPEBlock::setAlphaComp(J3DAlphaComp) */

void __thiscall J3DPEBlock::setAlphaComp(J3DPEBlock *this,J3DAlphaComp param_1)

{
  return;
}


/* __thiscall J3DIndBlock::setIndTexCoordScale(unsigned long,
                                               J3DIndTexCoordScale) */

void __thiscall
J3DIndBlock::setIndTexCoordScale(J3DIndBlock *this,ulong param_1,J3DIndTexCoordScale param_2)

{
  return;
}


/* __thiscall J3DIndTexCoordScale::~J3DIndTexCoordScale(void) */

void __thiscall J3DIndTexCoordScale::_J3DIndTexCoordScale(J3DIndTexCoordScale *this)

{
  short in_r4;
  
  if ((this != (J3DIndTexCoordScale *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall J3DIndBlock::setIndTexMtx(unsigned long,
                                        J3DIndTexMtx) */

void __thiscall J3DIndBlock::setIndTexMtx(J3DIndBlock *this,ulong param_1,J3DIndTexMtx param_2)

{
  return;
}


/* __thiscall J3DIndTexMtx::~J3DIndTexMtx(void) */

void __thiscall J3DIndTexMtx::_J3DIndTexMtx(J3DIndTexMtx *this)

{
  short in_r4;
  
  if ((this != (J3DIndTexMtx *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall J3DIndBlock::setIndTexStageNum(unsigned char) */

void __thiscall J3DIndBlock::setIndTexStageNum(J3DIndBlock *this,uchar param_1)

{
  return;
}


/* __thiscall J3DTevBlock::setIndTevStage(unsigned long,
                                          J3DIndTevStage) */

void __thiscall J3DTevBlock::setIndTevStage(J3DTevBlock *this,ulong param_1,J3DIndTevStage param_2)

{
  return;
}


/* __thiscall J3DTevBlock::setTevStage(unsigned long,
                                       J3DTevStage) */

void __thiscall J3DTevBlock::setTevStage(J3DTevBlock *this,ulong param_1,undefined param_2)

{
  return;
}


/* __thiscall J3DTevBlock::setTexNo(unsigned long,
                                    unsigned short) */

void __thiscall J3DTevBlock::setTexNo(J3DTevBlock *this,ulong param_1,ushort param_2)

{
  return;
}


/* __thiscall J3DTevBlock::setTevSwapModeTable(unsigned long,
                                               J3DTevSwapModeTable) */

void __thiscall
J3DTevBlock::setTevSwapModeTable(J3DTevBlock *this,ulong param_1,J3DTevSwapModeTable param_2)

{
  return;
}


/* __thiscall J3DTevBlock::setTevKAlphaSel(unsigned long,
                                           unsigned char) */

void __thiscall J3DTevBlock::setTevKAlphaSel(J3DTevBlock *this,ulong param_1,uchar param_2)

{
  return;
}


/* __thiscall J3DTevBlock::setTevKColorSel(unsigned long,
                                           unsigned char) */

void __thiscall J3DTevBlock::setTevKColorSel(J3DTevBlock *this,ulong param_1,uchar param_2)

{
  return;
}


/* __thiscall J3DTevBlock::setTevOrder(unsigned long,
                                       J3DTevOrder) */

void __thiscall J3DTevBlock::setTevOrder(J3DTevBlock *this,ulong param_1,J3DTevOrder param_2)

{
  return;
}


/* __thiscall J3DTevBlock::setTevKColor(unsigned long,
                                        J3DGXColor) */

void __thiscall J3DTevBlock::setTevKColor(J3DTevBlock *this,ulong param_1,J3DGXColor param_2)

{
  return;
}


/* __thiscall J3DTevBlock::setTevColor(unsigned long,
                                       J3DGXColorS10) */

void __thiscall J3DTevBlock::setTevColor(J3DTevBlock *this,ulong param_1,J3DGXColorS10 param_2)

{
  return;
}


/* __thiscall J3DTevBlock::setTevStageNum(unsigned char) */

void __thiscall J3DTevBlock::setTevStageNum(J3DTevBlock *this,uchar param_1)

{
  return;
}


/* __thiscall J3DTexGenBlock::setTexCoord(unsigned long,
                                          J3DTexCoord const *) */

void __thiscall J3DTexGenBlock::setTexCoord(J3DTexGenBlock *this,ulong param_1,J3DTexCoord *param_2)

{
  return;
}


/* __thiscall J3DTexGenBlock::setTexGenNum(unsigned long) */

void __thiscall J3DTexGenBlock::setTexGenNum(J3DTexGenBlock *this,ulong param_1)

{
  return;
}


/* __thiscall J3DColorBlock::setAmbColor(unsigned long,
                                         J3DGXColor) */

void __thiscall J3DColorBlock::setAmbColor(J3DColorBlock *this,ulong param_1,J3DGXColor param_2)

{
  return;
}


/* __thiscall J3DColorBlock::setColorChan(unsigned long,
                                          J3DColorChan const &) */

void __thiscall J3DColorBlock::setColorChan(J3DColorBlock *this,ulong param_1,J3DColorChan *param_2)

{
  return;
}


/* __thiscall J3DColorBlock::setMatColor(unsigned long,
                                         J3DGXColor) */

void __thiscall J3DColorBlock::setMatColor(J3DColorBlock *this,ulong param_1,J3DGXColor param_2)

{
  return;
}


/* __thiscall J3DColorBlock::setColorChanNum(unsigned char) */

void __thiscall J3DColorBlock::setColorChanNum(J3DColorBlock *this,uchar param_1)

{
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall mDoExt_backupMaterial_c::create(J3DModelData *) */

undefined4 __thiscall
mDoExt_backupMaterial_c::create(mDoExt_backupMaterial_c *this,J3DModelData *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  ushort uVar3;
  
  if (*(int *)this == 0) {
    uVar2 = (uint)(param_1->mMaterialTable).mMaterialCount;
    uVar1 = JKernel::operator_new__(uVar2 * 0x7d8 + 0x10);
    uVar1 = Runtime.PPCEABI.H::__construct_new_array
                      (uVar1,mDoExt_backupMatBlock_c::mDoExt_backupMatBlock_c,
                       mDoExt_backupMatBlock_c::_mDoExt_backupMatBlock_c,0x7d8,uVar2);
    *(undefined4 *)this = uVar1;
    if (*(int *)this == 0) {
      return 0;
    }
  }
  for (uVar3 = 0; uVar3 < (param_1->mMaterialTable).mMaterialCount; uVar3 = uVar3 + 1) {
    mDoExt_backupMatBlock_c::store
              ((mDoExt_backupMatBlock_c *)(*(int *)this + (uint)uVar3 * 0x7d8),
               (param_1->mMaterialTable).mpMaterials[uVar3]);
  }
  *(J3DTexture **)(this + 4) = (param_1->mMaterialTable).mpTexture;
  *(JUTNameTab **)(this + 8) = (param_1->mMaterialTable).mpTexNameTab;
  return 1;
}


/* __thiscall mDoExt_backupMatBlock_c::~mDoExt_backupMatBlock_c(void) */

void __thiscall mDoExt_backupMatBlock_c::_mDoExt_backupMatBlock_c(mDoExt_backupMatBlock_c *this)

{
  short in_r4;
  
  if (this != (mDoExt_backupMatBlock_c *)0x0) {
    Runtime.PPCEABI.H::__destroy_arr(this + 0x788,J3DIndTexCoordScale::_J3DIndTexCoordScale,4,4);
    Runtime.PPCEABI.H::__destroy_arr(this + 0x734,J3DIndTexMtx::_J3DIndTexMtx,0x1c,3);
    Runtime.PPCEABI.H::__destroy_arr(this + 0x40,J3DTexMtx::_J3DTexMtx,0xc4,8);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DTexMtx::~J3DTexMtx(void) */

void __thiscall J3DTexMtx::_J3DTexMtx(J3DTexMtx *this)

{
  short in_r4;
  
  if ((this != (J3DTexMtx *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall mDoExt_backupMatBlock_c::mDoExt_backupMatBlock_c(void) */

void __thiscall mDoExt_backupMatBlock_c::mDoExt_backupMatBlock_c(mDoExt_backupMatBlock_c *this)

{
  int iVar1;
  int iVar2;
  
  Runtime.PPCEABI.H::__construct_array(this,J3DGXColor::J3DGXColor,(undefined *)0x0,4,2);
  Runtime.PPCEABI.H::__construct_array(this + 10,J3DColorChan::J3DColorChan,(undefined *)0x0,2,4);
  Runtime.PPCEABI.H::__construct_array(this + 0x12,J3DGXColor::J3DGXColor,(undefined *)0x0,4,2);
  Runtime.PPCEABI.H::__construct_array(this + 0x20,J3DTexCoord::J3DTexCoord,(undefined *)0x0,4,8);
  Runtime.PPCEABI.H::__construct_array
            (this + 0x40,J3DTexMtx::J3DTexMtx,J3DTexMtx::_J3DTexMtx,0xc4,8);
  Runtime.PPCEABI.H::__construct_array
            (this + 0x672,J3DGXColorS10::J3DGXColorS10,(undefined *)0x0,8,4);
  Runtime.PPCEABI.H::__construct_array(this + 0x692,J3DGXColor::J3DGXColor,(undefined *)0x0,4,4);
  Runtime.PPCEABI.H::__construct_array(this + 0x6a2,J3DTevStage::J3DTevStage,(undefined *)0x0,8,8);
  Runtime.PPCEABI.H::__construct_array
            (this + 0x6e4,J3DIndTevStage::J3DIndTevStage,(undefined *)0x0,4,8);
  Runtime.PPCEABI.H::__construct_array(this + 0x704,J3DTevOrder::J3DTevOrder,(undefined *)0x0,4,4);
  Runtime.PPCEABI.H::__construct_array
            (this + 0x71c,J3DTevSwapModeTable::J3DTevSwapModeTable,(undefined *)0x0,1,4);
  Runtime.PPCEABI.H::__construct_array
            (this + 0x721,J3DIndTexOrder::J3DIndTexOrder,(undefined *)0x0,4,4);
  Runtime.PPCEABI.H::__construct_array
            (this + 0x734,J3DIndTexMtx::J3DIndTexMtx,J3DIndTexMtx::_J3DIndTexMtx,0x1c,3);
  Runtime.PPCEABI.H::__construct_array
            (this + 0x788,J3DIndTexCoordScale::J3DIndTexCoordScale,
             J3DIndTexCoordScale::_J3DIndTexCoordScale,4,4);
  this[0x798] = J3DGraphBase::j3dDefaultFogInfo;
  this[0x799] = DAT_80370e0d;
  *(undefined2 *)(this + 0x79a) = DAT_80370e0e;
  *(undefined4 *)(this + 0x79c) = DAT_80370e10;
  *(undefined4 *)(this + 0x7a0) = DAT_80370e14;
  *(undefined4 *)(this + 0x7a4) = DAT_80370e18;
  *(undefined4 *)(this + 0x7a8) = DAT_80370e1c;
  this[0x7ac] = DAT_80370e20;
  this[0x7ad] = DAT_80370e21;
  this[0x7ae] = DAT_80370e22;
  this[0x7af] = DAT_80370e23;
  iVar1 = 0;
  iVar2 = 10;
  do {
    *(undefined2 *)(this + iVar1 + 0x7b0) = *(undefined2 *)((int)&DAT_80370e24 + iVar1);
    iVar1 = iVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined2 *)(this + 0x7c4) = J3DGraphBase::j3dDefaultAlphaCmpID;
  this[0x7c6] = (mDoExt_backupMatBlock_c)0x0;
  this[0x7c7] = (mDoExt_backupMatBlock_c)0x0;
  this[0x7c8] = J3DGraphBase::j3dDefaultBlendInfo;
  this[0x7c9] = UNK_803fc95d;
  this[0x7ca] = UNK_803fc95e;
  this[0x7cb] = UNK_803fc95f;
  *(undefined2 *)(this + 0x7cc) = J3DGraphBase::j3dDefaultZModeID;
  return;
}


/* __thiscall J3DIndTexCoordScale::J3DIndTexCoordScale(void) */

void __thiscall J3DIndTexCoordScale::J3DIndTexCoordScale(J3DIndTexCoordScale *this)

{
  *this = J3DGraphBase::j3dDefaultIndTexCoordScaleInfo;
  this[1] = UNK_803fc94d;
  return;
}


/* __thiscall J3DIndTexMtx::J3DIndTexMtx(void) */

void __thiscall J3DIndTexMtx::J3DIndTexMtx(J3DIndTexMtx *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar1 = 0;
  do {
    iVar2 = 0;
    iVar4 = 3;
    do {
      *(undefined4 *)(this + iVar2 + iVar1) =
           *(undefined4 *)((int)&J3DGraphBase::j3dDefaultIndTexMtxInfo + iVar2 + iVar1);
      iVar2 = iVar2 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar3 = iVar3 + 1;
    iVar1 = iVar1 + 0xc;
  } while (iVar3 < 2);
  this[0x18] = DAT_80370de8;
  return;
}


/* __thiscall J3DIndTexOrder::J3DIndTexOrder(void) */

void __thiscall J3DIndTexOrder::J3DIndTexOrder(J3DIndTexOrder *this)

{
  *this = J3DGraphBase::j3dDefaultIndTexOrderNull;
  this[1] = UNK_803fc941;
  return;
}


/* __thiscall J3DTevSwapModeTable::J3DTevSwapModeTable(void) */

void __thiscall J3DTevSwapModeTable::J3DTevSwapModeTable(J3DTevSwapModeTable *this)

{
  *this = J3DGraphBase::j3dDefaultTevSwapTableID;
  return;
}


/* __thiscall J3DTevOrder::J3DTevOrder(void) */

void __thiscall J3DTevOrder::J3DTevOrder(J3DTevOrder *this)

{
  *this = J3DGraphBase::j3dDefaultTevOrderInfoNull;
  this[1] = UNK_803fc93d;
  this[2] = UNK_803fc93e;
  return;
}


/* __thiscall J3DIndTevStage::J3DIndTevStage(void) */

void __thiscall J3DIndTevStage::J3DIndTevStage(J3DIndTevStage *this)

{
  *(undefined4 *)this = 0;
  *(uint *)this = *(uint *)this & 0xfffffffc | (uint)J3DGraphBase::j3dDefaultIndTevStageInfo;
  *(uint *)this = *(uint *)this & 0xfffffff3 | (uint)DAT_80370e01 << 2;
  *(uint *)this = *(uint *)this & 0xffffff8f | (uint)DAT_80370e02 << 4;
  *(uint *)this = *(uint *)this & 0xffffe1ff | (uint)DAT_80370e03 << 9;
  *(uint *)this = *(uint *)this & 0xffff1fff | (uint)DAT_80370e04 << 0xd;
  *(uint *)this = *(uint *)this & 0xfff8ffff | (uint)DAT_80370e05 << 0x10;
  *(uint *)this = *(uint *)this & 0xffefffff | (uint)DAT_80370e06 << 0x14;
  *(uint *)this = *(uint *)this & 0xfff7ffff | (uint)DAT_80370e07 << 0x13;
  *(uint *)this = *(uint *)this & 0xfffffe7f | (uint)DAT_80370e08 << 7;
  return;
}


/* __thiscall J3DTevStage::J3DTevStage(void) */

void __thiscall J3DTevStage::J3DTevStage(J3DTevStage *this)

{
  setTevStageInfo(this,(J3DTevStageInfo *)&J3DGraphBase::j3dDefaultTevStageInfo);
  this->field_0x7 = this->field_0x7 & 0xf3 | UNK_803fc955 << 2;
  this->field_0x7 = this->field_0x7 & 0xfc | J3DGraphBase::j3dDefaultTevSwapMode;
  return;
}


/* __thiscall J3DTevStage::setTevStageInfo(J3DTevStageInfo const &) */

void __thiscall J3DTevStage::setTevStageInfo(J3DTevStage *this,J3DTevStageInfo *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  
  bVar1 = param_1->field_0x9;
  bVar2 = param_1->field_0x8;
  bVar3 = param_1->field_0x7;
  bVar4 = param_1->field_0x6;
  bVar5 = param_1->field_0x5;
  this->field_0x1 = this->field_0x1 & 0xfb | bVar5 << 2;
  if (bVar5 < 2) {
    this->field_0x1 = this->field_0x1 & 0xcf | bVar3 << 4;
    this->field_0x1 = this->field_0x1 & 0xfc | bVar4;
  }
  else {
    this->field_0x1 = (bVar5 & 6) << 3 | this->field_0x1 & 0xcf;
    this->field_0x1 = this->field_0x1 & 0xfc | 3;
  }
  this->field_0x1 = this->field_0x1 & 0xf7 | bVar2 << 3;
  this->field_0x1 = this->field_0x1 & 0x3f | bVar1 << 6;
  this->field_0x2 = param_1->field_0x1 << 4 | param_1->field_0x2;
  this->field_0x3 = param_1->field_0x3 << 4 | param_1->field_0x4;
  bVar1 = param_1->field_0xd;
  bVar2 = param_1->field_0xc;
  bVar3 = param_1->field_0xb;
  this->field_0x6 = this->field_0x6 & 0x1f | param_1->field_0xa << 5;
  this->field_0x6 = this->field_0x6 & 0xe3 | bVar3 << 2;
  this->field_0x6 = this->field_0x6 & 0xfc | (byte)((int)(uint)bVar2 >> 1);
  this->field_0x7 = this->field_0x7 & 0x7f | bVar2 << 7;
  this->field_0x7 = this->field_0x7 & 0x8f | bVar1 << 4;
  bVar1 = param_1->field_0x12;
  bVar2 = param_1->field_0x11;
  bVar3 = param_1->field_0x10;
  bVar4 = param_1->field_0xf;
  bVar5 = param_1->field_0xe;
  this->field_0x5 = this->field_0x5 & 0xfb | bVar5 << 2;
  if (bVar5 < 2) {
    this->field_0x5 = this->field_0x5 & 0xfc | bVar4;
    this->field_0x5 = this->field_0x5 & 0xcf | bVar3 << 4;
  }
  else {
    this->field_0x5 = (bVar5 & 6) << 3 | this->field_0x5 & 0xcf;
    this->field_0x5 = this->field_0x5 & 0xfc | 3;
  }
  this->field_0x5 = this->field_0x5 & 0xf7 | bVar2 << 3;
  this->field_0x5 = this->field_0x5 & 0x3f | bVar1 << 6;
  return;
}


/* __thiscall J3DGXColorS10::J3DGXColorS10(void) */

void __thiscall J3DGXColorS10::J3DGXColorS10(J3DGXColorS10 *this)

{
  return;
}


/* __thiscall J3DTexMtx::J3DTexMtx(void) */

void __thiscall J3DTexMtx::J3DTexMtx(J3DTexMtx *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar1 = 0;
  do {
    iVar2 = 0;
    iVar4 = 4;
    do {
      *(undefined4 *)((int)(this->mInfo).mEffectMtx.m + iVar2 + 0x24 + iVar1 + -0x24) =
           *(undefined4 *)(&J3DGraphBase::j3dDefaultTexMtxInfo + iVar2 + 0x24 + iVar1);
      iVar2 = iVar2 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar3 = iVar3 + 1;
    iVar1 = iVar1 + 0x10;
  } while (iVar3 < 4);
  (this->mInfo).mCenter.x = DAT_80370d70;
  (this->mInfo).mCenter.y = DAT_80370d74;
  (this->mInfo).mCenter.z = DAT_80370d78;
  (this->mInfo).mProjection = J3DGraphBase::j3dDefaultTexMtxInfo;
  (this->mInfo).mInfo = DAT_80370d6d;
  (this->mInfo).mSRTInfo.mScaleX = DAT_80370d7c;
  (this->mInfo).mSRTInfo.mScaleY = DAT_80370d80;
  (this->mInfo).mSRTInfo.mRotation = DAT_80370d84;
  (this->mInfo).mSRTInfo.mTransX = DAT_80370d88;
  (this->mInfo).mSRTInfo.mTransY = DAT_80370d8c;
  return;
}


/* __thiscall J3DTexCoord::J3DTexCoord(void) */

void __thiscall J3DTexCoord::J3DTexCoord(J3DTexCoord *this)

{
  *this = J3DGraphBase::j3dDefaultTexCoordInfo;
  this[1] = DAT_80370d4d;
  this[2] = DAT_80370d4e;
  return;
}


/* __thiscall J3DColorChan::J3DColorChan(void) */

void __thiscall J3DColorChan::J3DColorChan(J3DColorChan *this)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)UNK_803fc964;
  uVar2 = (uint)UNK_803fc962;
  iVar1 = -uVar3 + 2;
  this->mChan = (((ushort)((uVar2 & 0x20) << 7) |
                  (ushort)((uVar2 & 0x10) << 7) |
                  (ushort)((uVar2 & 8) << 2) |
                  (ushort)((uVar2 & 4) << 2) |
                  (ushort)((uVar2 & 2) << 2) |
                  (ushort)((uVar2 & 1) << 2) |
                  (((ushort)J3DGraphBase::j3dDefaultColorChanInfo << 1 | (ushort)UNK_803fc961) &
                   0xff83 | (ushort)(((uint)UNK_803fc965 & ~-(uint)(UNK_803fc965 == 0xffff)) << 6))
                  & 0x67f | (ushort)((uVar2 & 0x40) << 7) | (UNK_803fc962 & 0x80) << 7 |
                 (ushort)(((uint)UNK_803fc963 & ~-(uint)(uVar3 == 0)) << 7)) & 0xfdff |
                ((short)iVar1 - ((ushort)(iVar1 == 0) + (short)-uVar3 + 1)) * 0x200) & 0xfbff |
                (ushort)(uVar3 != 0) * 0x400;
  return;
}


/* __thiscall J3DGXColor::J3DGXColor(void) */

void __thiscall J3DGXColor::J3DGXColor(J3DGXColor *this)

{
  return;
}


/* __thiscall mDoExt_backupMaterial_c::create(unsigned short) */

bool __thiscall mDoExt_backupMaterial_c::create(mDoExt_backupMaterial_c *this,ushort param_1)

{
  undefined4 uVar1;
  
  uVar1 = JKernel::operator_new__((uint)param_1 * 0x7d8 + 0x10);
  uVar1 = Runtime.PPCEABI.H::__construct_new_array
                    (uVar1,mDoExt_backupMatBlock_c::mDoExt_backupMatBlock_c,
                     mDoExt_backupMatBlock_c::_mDoExt_backupMatBlock_c,0x7d8,(uint)param_1);
  *(undefined4 *)this = uVar1;
  return *(int *)this != 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall mDoExt_backupMaterial_c::restore(J3DModelData *) */

void __thiscall
mDoExt_backupMaterial_c::restore(mDoExt_backupMaterial_c *this,J3DModelData *param_1)

{
  ushort uVar1;
  
  for (uVar1 = 0; uVar1 < (param_1->mMaterialTable).mMaterialCount; uVar1 = uVar1 + 1) {
    mDoExt_backupMatBlock_c::restore
              ((mDoExt_backupMatBlock_c *)(*(int *)this + (uint)uVar1 * 0x7d8),
               (param_1->mMaterialTable).mpMaterials[uVar1]);
  }
  (param_1->mMaterialTable).mpTexture = *(J3DTexture **)(this + 4);
  (param_1->mMaterialTable).mpTexNameTab = *(JUTNameTab **)(this + 8);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall mDoExt_invisibleModel::create(J3DModel *) */

undefined4 __thiscall mDoExt_invisibleModel::create(mDoExt_invisibleModel *this,J3DModel *param_1)

{
  undefined4 uVar1;
  mDoExt_invJntPacket *pmVar2;
  ushort uVar3;
  J3DModelData *pJVar4;
  uint uVar5;
  
  pJVar4 = param_1->mpModelData;
  uVar5 = (uint)(ushort)(pJVar4->mJointTree).mJointCount;
  uVar1 = JKernel::operator_new__(uVar5 * 0x18 + 0x10);
  pmVar2 = (mDoExt_invJntPacket *)
           Runtime.PPCEABI.H::__construct_new_array
                     (uVar1,mDoExt_invJntPacket::mDoExt_invJntPacket,
                      mDoExt_invJntPacket::_mDoExt_invJntPacket,0x18,uVar5);
  this->mpPackets = pmVar2;
  if (this->mpPackets == (mDoExt_invJntPacket *)0x0) {
    uVar1 = 0;
  }
  else {
    this->mpModel = param_1;
    pmVar2 = this->mpPackets;
    for (uVar3 = 0; uVar3 < (ushort)(pJVar4->mJointTree).mJointCount; uVar3 = uVar3 + 1) {
      pmVar2->mpModel = this->mpModel;
      pmVar2->mIndex = uVar3;
      pmVar2 = pmVar2 + 1;
    }
    uVar1 = 1;
  }
  return uVar1;
}


/* __thiscall mDoExt_invJntPacket::~mDoExt_invJntPacket(void) */

void __thiscall mDoExt_invJntPacket::_mDoExt_invJntPacket(mDoExt_invJntPacket *this)

{
  short in_r4;
  
  if (this != (mDoExt_invJntPacket *)0x0) {
    (this->parent).vtbl = &__vt;
    if (this != (mDoExt_invJntPacket *)0x0) {
      (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall mDoExt_invJntPacket::mDoExt_invJntPacket(void) */

void __thiscall mDoExt_invJntPacket::mDoExt_invJntPacket(mDoExt_invJntPacket *this)

{
  (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
  (this->parent).mpNextSibling = (J3DPacket *)0x0;
  (this->parent).mpFirstChild = (J3DPacket *)0x0;
  (this->parent).field_0xc = (undefined *)0x0;
  (this->parent).vtbl = &__vt;
  return;
}


/* __thiscall J3DPacket::~J3DPacket(void) */

void __thiscall J3DPacket::_J3DPacket(J3DPacket *this)

{
  short in_r4;
  
  if ((this != (J3DPacket *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall mDoExt_invisibleModel::entry(void) */

void __thiscall mDoExt_invisibleModel::entry(mDoExt_invisibleModel *this)

{
  MTX34 *pMVar1;
  ushort uVar2;
  mDoExt_invJntPacket *pPacket;
  J3DModelData *pJVar3;
  cXyz local_28;
  
  pJVar3 = this->mpModel->mpModelData;
  pPacket = this->mpPackets;
  for (uVar2 = 0; uVar2 < (ushort)(pJVar3->mJointTree).mJointCount; uVar2 = uVar2 + 1) {
    pMVar1 = this->mpModel->mpNodeMtx + uVar2;
    local_28.z = pMVar1->m[2][3];
    local_28.y = pMVar1->m[1][3];
    local_28.x = pMVar1->m[3];
    dDlst_list_c::entryZSortXluDrawList
              (&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
               d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu,&pPacket->parent,
               &local_28);
    pPacket = pPacket + 1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall mDoExt_invisibleModel::entryMaskOff(void) */

void __thiscall mDoExt_invisibleModel::entryMaskOff(mDoExt_invisibleModel *this)

{
  MTX34 *pMVar1;
  ushort uVar2;
  mDoExt_invJntPacket *pPacket;
  J3DModelData *pJVar3;
  cXyz local_28;
  
  pJVar3 = this->mpModel->mpModelData;
  pPacket = this->mpPackets;
  for (uVar2 = 0; uVar2 < (ushort)(pJVar3->mJointTree).mJointCount; uVar2 = uVar2 + 1) {
    pMVar1 = this->mpModel->mpNodeMtx + uVar2;
    local_28.z = pMVar1->m[2][3];
    local_28.y = pMVar1->m[1][3];
    local_28.x = pMVar1->m[3];
    dDlst_list_c::entryZSortXluDrawList
              (&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
               d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelMaskOffXlu,
               &pPacket->parent,&local_28);
    pPacket = pPacket + 1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall mDoExt_invisibleModel::updateDL(J3DModel *) */

void __thiscall mDoExt_invisibleModel::updateDL(mDoExt_invisibleModel *this,J3DModel *param_1)

{
  J3DDrawBuffer *pJVar1;
  J3DDrawBuffer *pJVar2;
  
  pJVar2 = J3DGraphBase::j3dSys.mpCurDrawBuffers[1];
  pJVar1 = J3DGraphBase::j3dSys.mpCurDrawBuffers[0];
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  m_Do_ext::mDoExt_modelUpdateDL(param_1);
  entry(this);
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] = pJVar1;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] = pJVar2;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall mDoExt_invisibleModel::updateDL(mDoExt_McaMorf *) */

void __thiscall mDoExt_invisibleModel::updateDL(mDoExt_invisibleModel *this,mDoExt_McaMorf *param_1)

{
  J3DDrawBuffer *pJVar1;
  J3DDrawBuffer *pJVar2;
  
  pJVar2 = J3DGraphBase::j3dSys.mpCurDrawBuffers[1];
  pJVar1 = J3DGraphBase::j3dSys.mpCurDrawBuffers[0];
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  mDoExt_McaMorf::updateDL(param_1);
  entry(this);
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] = pJVar1;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] = pJVar2;
  return;
}


namespace m_Do_ext {

/* __stdcall mDoExt_createGameHeap(unsigned long,
                                   JKRHeap *) */

JKRHeap * mDoExt_createGameHeap(ulong param_1,JKRHeap *param_2)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((gameHeap == (JKRHeap *)0x0) || (param_1 == 0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"m_Do_ext.cpp",0x802,"gameHeap == 0 || heapSize == 0");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x802,"Halt");
  }
  gameHeap = (JKRHeap *)JKRExpHeap::create(param_1,param_2,true);
  *(byte *)((int)gameHeap + 0x6c) = 1;
  return gameHeap;
}


/* WARNING: Unknown calling convention yet parameter storage is locked */
/* __stdcall mDoExt_getGameHeap(void) */

JKRExpHeap * mDoExt_getGameHeap(void)

{
  return (JKRExpHeap *)gameHeap;
}


/* __stdcall mDoExt_setSafeGameHeapSize(void) */

void mDoExt_setSafeGameHeapSize(void)

{
  JKRExpHeap *this;
  
  this = mDoExt_getGameHeap();
  safeGameHeapSize = JKRHeap::getTotalFreeSize(&this->parent);
  return;
}


/* __stdcall mDoExt_getSafeGameHeapSize(void) */

undefined4 mDoExt_getSafeGameHeapSize(void)

{
  return safeGameHeapSize;
}


/* __stdcall mDoExt_createZeldaHeap(unsigned long,
                                    JKRHeap *) */

JKRHeap * mDoExt_createZeldaHeap(ulong param_1,JKRHeap *param_2)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((zeldaHeap == (JKRHeap *)0x0) || (param_1 == 0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"m_Do_ext.cpp",0x840,"zeldaHeap == 0 || heapSize == 0");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x840,"Halt");
  }
  zeldaHeap = (JKRHeap *)JKRExpHeap::create(param_1,param_2,true);
  return zeldaHeap;
}


/* WARNING: Unknown calling convention yet parameter storage is locked */
/* __stdcall mDoExt_getZeldaHeap(void) */

JKRHeap * mDoExt_getZeldaHeap(void)

{
  return zeldaHeap;
}


/* __stdcall mDoExt_setSafeZeldaHeapSize(void) */

void mDoExt_setSafeZeldaHeapSize(void)

{
  JKRHeap *this;
  
  this = mDoExt_getZeldaHeap();
  safeZeldaHeapSize = JKRHeap::getTotalFreeSize(this);
  return;
}


/* __stdcall mDoExt_getSafeZeldaHeapSize(void) */

undefined4 mDoExt_getSafeZeldaHeapSize(void)

{
  return safeZeldaHeapSize;
}


/* __stdcall mDoExt_createCommandHeap(unsigned long,
                                      JKRHeap *) */

void mDoExt_createCommandHeap(ulong param_1,JKRHeap *param_2)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((commandHeap == (JKRExpHeap *)0x0) || (param_1 == 0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"m_Do_ext.cpp",0x87d,"commandHeap == 0 || heapSize == 0");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x87d,"Halt");
  }
  commandHeap = JKRExpHeap::create(param_1,param_2,true);
  return;
}


/* WARNING: Unknown calling convention yet parameter storage is locked */
/* __stdcall mDoExt_getCommandHeap(void) */

JKRHeap * mDoExt_getCommandHeap(void)

{
  return commandHeap;
}


/* __stdcall mDoExt_setSafeCommandHeapSize(void) */

void mDoExt_setSafeCommandHeapSize(void)

{
  JKRHeap *this;
  
  this = mDoExt_getCommandHeap();
  safeCommandHeapSize = JKRHeap::getTotalFreeSize(this);
  return;
}


/* __stdcall mDoExt_getSafeCommandHeapSize(void) */

undefined4 mDoExt_getSafeCommandHeapSize(void)

{
  return safeCommandHeapSize;
}


/* __stdcall mDoExt_createArchiveHeap(unsigned long,
                                      JKRHeap *) */

JKRHeap * mDoExt_createArchiveHeap(ulong param_1,JKRHeap *param_2)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((archiveHeap == (JKRHeap *)0x0) || (param_1 == 0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"m_Do_ext.cpp",0x8bd,"archiveHeap == 0 || heapSize == 0");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x8bd,"Halt");
  }
  archiveHeap = (JKRHeap *)JKRExpHeap::create(param_1,param_2,true);
  *(byte *)((int)archiveHeap + 0x6c) = 1;
  return archiveHeap;
}


/* __stdcall mDoExt_setSafeArchiveHeapSize(void) */

void mDoExt_setSafeArchiveHeapSize(void)

{
  JKRHeap *this;
  
  this = mDoExt_getArchiveHeap();
  safeArchiveHeapSize = JKRHeap::getTotalFreeSize(this);
  return;
}


/* __stdcall mDoExt_getSafeArchiveHeapSize(void) */

undefined4 mDoExt_getSafeArchiveHeapSize(void)

{
  return safeArchiveHeapSize;
}


/* __stdcall mDoExt_getArchiveHeap(void) */

JKRHeap * mDoExt_getArchiveHeap(void)

{
  return archiveHeap;
}


/* __stdcall mDoExt_createSolidHeap(unsigned long,
                                    JKRHeap *,
                                    unsigned long) */

JKRSolidHeap *
mDoExt_createSolidHeap(int maxHeapSize,JKRHeap *param_2,uint param_3,bool param_4)

{
  JKRSolidHeap *this;
  ulong maxSize;
  
  if (param_2 == (JKRHeap *)0x0) {
    param_2 = JKRHeap::sCurrentHeap;
  }
  if ((maxHeapSize == 0) || (maxHeapSize == -1)) {
    this = JKRSolidHeap::create(0xffffffff,param_2,false);
  }
  else {
    maxSize = (maxHeapSize + 0xfU & 0xfffffff0) + 0x80;
    if (0x10 < param_3) {
      maxSize = (param_3 + maxSize) - 0x10;
    }
    this = JKRSolidHeap::create(maxSize,param_2,false);
  }
  if (this != (JKRSolidHeap *)0x0) {
    JKRHeap::setErrorFlag(&this->parent,true);
  }
  return this;
}


/* __stdcall mDoExt_createSolidHeapFromGame(unsigned long,
                                            unsigned long) */

void mDoExt_createSolidHeapFromGame
               (int param_1,uint param_2,undefined4 param_3,undefined param_4)

{
  JKRExpHeap *pJVar1;
  
  pJVar1 = mDoExt_getGameHeap();
  mDoExt_createSolidHeap(param_1,&pJVar1->parent,param_2,(bool)param_4);
  return;
}


/* __stdcall mDoExt_createSolidHeapFromSystem(unsigned long,
                                              unsigned long) */

JKRHeap * mDoExt_createSolidHeapFromSystem
                    (int param_1,uint param_2,undefined4 param_3,bool param_4)

{
  JKRHeap *pJVar1;
  JKRSolidHeap *pJVar2;
  
  pJVar1 = mDoExt_getZeldaHeap();
  pJVar2 = mDoExt_createSolidHeap(param_1,pJVar1,param_2,param_4);
  return &pJVar2->parent;
}


/* __stdcall mDoExt_createSolidHeapToCurrent(unsigned long,
                                             JKRHeap *,
                                             unsigned long) */

JKRSolidHeap *
mDoExt_createSolidHeapToCurrent
          (int maxHeapSize,JKRHeap *param_2,uint param_3,bool param_4)

{
  JKRHeap *pHeap;
  OSThread *pOVar1;
  ulong uVar2;
  
  pHeap = (JKRHeap *)mDoExt_createSolidHeap(maxHeapSize,param_2,param_3,param_4);
  if (pHeap == (JKRHeap *)0x0) {
    pHeap = (JKRHeap *)0x0;
  }
  else {
    pOVar1 = (OSThread *)os::OSGetCurrentThread();
    if (pOVar1 != &m_Do_main::mainThread) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"m_Do_ext.cpp",0x9f1,"OSGetCurrentThread() == &mainThread");
      m_Do_printf::OSPanic("m_Do_ext.cpp",0x9f1,"Halt");
    }
    if (mDoExt_SaveCurrentHeap != (JKRHeap *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"m_Do_ext.cpp",0x9f2,"mDoExt_SaveCurrentHeap == 0");
      m_Do_printf::OSPanic("m_Do_ext.cpp",0x9f2,"Halt");
    }
    mDoExt_SaveCurrentHeap = JKRHeap::sCurrentHeap;
    mDoExt_setCurrentHeap(pHeap);
  }
  return (JKRSolidHeap *)pHeap;
}


/* __stdcall mDoExt_createSolidHeapFromGameToCurrent(unsigned long,
                                                     unsigned long) */

JKRSolidHeap * mDoExt_createSolidHeapFromGameToCurrent(int maxHeapSize,int param_2)

{
  JKRExpHeap *pGameHeap;
  JKRSolidHeap *pJVar1;
  undefined in_r6;
  
  mDoExt_getGameHeap();
  pGameHeap = mDoExt_getGameHeap();
  pJVar1 = mDoExt_createSolidHeapToCurrent(maxHeapSize,&pGameHeap->parent,param_2,in_r6);
  return pJVar1;
}


/* __stdcall mDoExt_adjustSolidHeap(JKRSolidHeap *) */

uint mDoExt_adjustSolidHeap(JKRSolidHeap *param_1)

{
  uint uVar1;
  
  if (param_1 == (JKRSolidHeap *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = JKRSolidHeap::adjustSize(param_1);
    if (0x7f < uVar1) {
      uVar1 = uVar1 - 0x80;
    }
  }
  return uVar1;
}


/* __stdcall mDoExt_destroySolidHeap(JKRSolidHeap *) */

void mDoExt_destroySolidHeap(JKRHeap *param_1)

{
  JKRHeap::destroy(param_1);
  return;
}


/* __stdcall mDoExt_setCurrentHeap(JKRHeap *) */

void mDoExt_setCurrentHeap(JKRHeap *param_1)

{
  ulong uVar1;
  
  if (param_1 == (JKRHeap *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"m_Do_ext.cpp",0xa7c,"heap != 0");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0xa7c,"Halt");
  }
  JKRHeap::becomeCurrentHeap(param_1);
  return;
}


/* __stdcall mDoExt_getCurrentHeap(void) */

JKRHeap * mDoExt_getCurrentHeap(void)

{
  return JKRHeap::sCurrentHeap;
}


/* __stdcall mDoExt_restoreCurrentHeap(void) */

void mDoExt_restoreCurrentHeap(void)

{
  OSThread *pOVar1;
  ulong uVar2;
  
  pOVar1 = (OSThread *)os::OSGetCurrentThread();
  if (pOVar1 != &m_Do_main::mainThread) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"m_Do_ext.cpp",0xac2,"OSGetCurrentThread() == &mainThread");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0xac2,"Halt");
  }
  if (mDoExt_SaveCurrentHeap == (JKRHeap *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"m_Do_ext.cpp",0xac3,"mDoExt_SaveCurrentHeap != 0");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0xac3,"Halt");
  }
  JKRHeap::becomeCurrentHeap(mDoExt_SaveCurrentHeap);
  mDoExt_SaveCurrentHeap = (JKRHeap *)0x0;
  return;
}


/* __stdcall mDoExt_resIDToIndex(JKRArchive *,
                                 unsigned short) */

int mDoExt_resIDToIndex(JKRArchive *param_1,ushort param_2)

{
  int iVar1;
  
  iVar1 = JKRArchive::findIdResource(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = (iVar1 - (int)param_1->mpFileEntries) / 0x14;
  }
  return iVar1;
}

}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x80012118) */
/* WARNING: Removing unreachable block (ram,0x80012120) */
/* __thiscall mDoExt_MtxCalcAnmBlendTbl::calc(unsigned short) */

void __thiscall mDoExt_MtxCalcAnmBlendTbl::calc(mDoExt_MtxCalcAnmBlendTbl *this,ushort param_1)

{
  int *piVar1;
  undefined2 in_register_00000010;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 in_f30;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  Quaternion QStack232;
  Quaternion local_d8;
  float local_c8;
  float local_c4;
  float local_c0;
  short local_bc;
  short local_ba;
  short local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  J3DTransformInfo local_a8;
  undefined auStack136 [32];
  MTX34 MStack104;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar2 = CONCAT22(in_register_00000010,param_1);
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  J3DGraphBase::j3dSys.mpCurMtxCalc = (J3DMtxCalc *)this;
  if (this != (mDoExt_MtxCalcAnmBlendTbl *)0x0) {
    J3DGraphBase::j3dSys.mpCurMtxCalc = *(J3DMtxCalc **)this;
  }
  if (*(int *)(this + 0x50) == 1) {
    (**(code **)(**(int **)(*(int *)(this + 0x54) + 4) + 0xc))
              (*(int **)(*(int *)(this + 0x54) + 4),uVar2,auStack136);
    (**(code **)(*(int *)(this + 0x4c) + 0x14))(this,uVar2,auStack136);
  }
  else {
    (**(code **)(**(int **)(*(int *)(this + 0x54) + 4) + 0xc))
              (*(int **)(*(int *)(this + 0x54) + 4),uVar2,&local_a8);
    JKernel::JMath::JMAEulerToQuat
              ((int)local_a8.mRot.x,(int)local_a8.mRot.y,(int)local_a8.mRot.z,&local_d8);
    local_f8 = local_d8.x;
    local_f4 = local_d8.y;
    local_f0 = local_d8.z;
    local_ec = local_d8.w;
    iVar4 = 8;
    for (iVar3 = 1; iVar3 < *(int *)(this + 0x50); iVar3 = iVar3 + 1) {
      piVar1 = *(int **)(*(int *)(this + 0x54) + iVar4 + 4);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0xc))(piVar1,uVar2,&local_c8);
        dVar7 = (double)*(float *)(*(int *)(this + 0x54) + iVar4);
        dVar6 = (double)(float)((double)m_Do_ext::1_0 - dVar7);
        JKernel::JMath::JMAEulerToQuat((int)local_bc,(int)local_ba,(int)local_b8,&QStack232);
        JKernel::JMath::JMAQuatLerp(dVar7,&local_d8,&QStack232,&local_f8);
        local_d8.x = local_f8;
        local_d8.y = local_f4;
        local_d8.z = local_f0;
        local_d8.w = local_ec;
        local_a8.mTranslation.x =
             (float)((double)local_a8.mTranslation.x * dVar6) + (float)((double)local_b4 * dVar7);
        local_a8.mTranslation.y =
             (float)((double)local_a8.mTranslation.y * dVar6) + (float)((double)local_b0 * dVar7);
        local_a8.mTranslation.z =
             (float)((double)local_a8.mTranslation.z * dVar6) + (float)((double)local_ac * dVar7);
        local_a8.mScale.x =
             (float)((double)local_a8.mScale.x * dVar6) + (float)((double)local_c8 * dVar7);
        local_a8.mScale.y =
             (float)((double)local_a8.mScale.y * dVar6) + (float)((double)local_c4 * dVar7);
        local_a8.mScale.z =
             (float)((double)local_a8.mScale.z * dVar6) + (float)((double)local_c0 * dVar7);
      }
      iVar4 = iVar4 + 8;
    }
    mtx::PSMTXQuat(&MStack104,&local_f8);
    m_Do_ext::mDoExt_setJ3DData(&MStack104,&local_a8,uVar2);
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x80012520) */
/* WARNING: Removing unreachable block (ram,0x80012528) */
/* __thiscall mDoExt_MtxCalcAnmBlendTblOld::calc(unsigned short) */

void __thiscall
mDoExt_MtxCalcAnmBlendTblOld::calc(mDoExt_MtxCalcAnmBlendTblOld *this,ushort param_1)

{
  uint uVar1;
  J3DModel *pJVar2;
  int *piVar3;
  undefined2 in_register_00000010;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  float *pfVar7;
  float *pfVar8;
  int iVar9;
  undefined4 uVar10;
  undefined8 in_f30;
  double dVar11;
  undefined8 in_f31;
  double dVar12;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  Quaternion QStack200;
  Quaternion local_b8;
  float local_a8;
  float local_a4;
  float local_a0;
  short local_9c;
  short local_9a;
  short local_98;
  float local_94;
  float local_90;
  float local_8c;
  J3DTransformInfo local_88;
  MTX34 MStack104;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = CONCAT22(in_register_00000010,param_1);
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  J3DGraphBase::j3dSys.mpCurMtxCalc = (J3DMtxCalc *)this;
  if (this != (mDoExt_MtxCalcAnmBlendTblOld *)0x0) {
    J3DGraphBase::j3dSys.mpCurMtxCalc = *(J3DMtxCalc **)this;
  }
  (**(code **)(**(int **)(*(int *)(this + 0x54) + 4) + 0xc))
            (*(int **)(*(int *)(this + 0x54) + 4),uVar4,&local_88);
  JKernel::JMath::JMAEulerToQuat
            ((int)local_88.mRot.x,(int)local_88.mRot.y,(int)local_88.mRot.z,&local_b8);
  local_d8 = local_b8.x;
  local_d4 = local_b8.y;
  local_d0 = local_b8.z;
  local_cc = local_b8.w;
  iVar9 = 8;
  for (iVar6 = 1; pJVar2 = J3DGraphBase::j3dSys.mpCurModel, iVar6 < *(int *)(this + 0x50);
      iVar6 = iVar6 + 1) {
    piVar3 = *(int **)(*(int *)(this + 0x54) + iVar9 + 4);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0xc))(piVar3,uVar4,&local_a8);
      dVar11 = (double)*(float *)(*(int *)(this + 0x54) + iVar9);
      dVar12 = (double)(float)((double)m_Do_ext::1_0 - dVar11);
      JKernel::JMath::JMAEulerToQuat((int)local_9c,(int)local_9a,(int)local_98,&QStack200);
      JKernel::JMath::JMAQuatLerp(dVar11,&local_b8,&QStack200,&local_d8);
      local_b8.x = local_d8;
      local_b8.y = local_d4;
      local_b8.z = local_d0;
      local_b8.w = local_cc;
      local_88.mTranslation.x =
           (float)((double)local_88.mTranslation.x * dVar12) + (float)((double)local_94 * dVar11);
      local_88.mTranslation.y =
           (float)((double)local_88.mTranslation.y * dVar12) + (float)((double)local_90 * dVar11);
      local_88.mTranslation.z =
           (float)((double)local_88.mTranslation.z * dVar12) + (float)((double)local_8c * dVar11);
      local_88.mScale.x =
           (float)((double)local_88.mScale.x * dVar12) + (float)((double)local_a8 * dVar11);
      local_88.mScale.y =
           (float)((double)local_88.mScale.y * dVar12) + (float)((double)local_a4 * dVar11);
      local_88.mScale.z =
           (float)((double)local_88.mScale.z * dVar12) + (float)((double)local_a0 * dVar11);
    }
    iVar9 = iVar9 + 8;
  }
  pcVar5 = *(char **)(this + 0x5c);
  uVar1 = (uint)param_1;
  pfVar8 = (float *)(*(int *)(pcVar5 + 0x1c) + (uint)param_1 * 0x20);
  pfVar7 = (float *)(*(int *)(pcVar5 + 0x20) + (uint)param_1 * 0x10);
  if (*pcVar5 == '\0') {
    if (uVar1 == (ushort)((J3DGraphBase::j3dSys.mpCurModel)->mpModelData->mJointTree).mJointCount -
                 1) {
      *pcVar5 = '\x01';
    }
  }
  else {
    dVar12 = (double)*(float *)(pcVar5 + 0xc);
    if ((((double)m_Do_ext::0_0 < dVar12) && (*(ushort *)(pcVar5 + 0x18) <= uVar1)) &&
       (uVar1 < *(ushort *)(pcVar5 + 0x1a))) {
      dVar11 = (double)(float)((double)m_Do_ext::1_0 - dVar12);
      JKernel::JMath::JMAQuatLerp(dVar11,pfVar7,&local_b8,&local_d8);
      local_88.mTranslation.x =
           (float)((double)local_88.mTranslation.x * dVar11) + (float)((double)pfVar8[5] * dVar12);
      local_88.mTranslation.y =
           (float)((double)local_88.mTranslation.y * dVar11) + (float)((double)pfVar8[6] * dVar12);
      local_88.mTranslation.z =
           (float)((double)local_88.mTranslation.z * dVar11) + (float)((double)pfVar8[7] * dVar12);
      local_88.mScale.x =
           (float)((double)local_88.mScale.x * dVar11) + (float)((double)*pfVar8 * dVar12);
      local_88.mScale.y =
           (float)((double)local_88.mScale.y * dVar11) + (float)((double)pfVar8[1] * dVar12);
      local_88.mScale.z =
           (float)((double)local_88.mScale.z * dVar11) + (float)((double)pfVar8[2] * dVar12);
    }
  }
  if (*(code **)(this + 0x60) != (code *)0x0) {
    (**(code **)(this + 0x60))(*(undefined4 *)(this + 0x58),uVar4,&local_88,&local_d8);
  }
  mtx::PSMTXQuat(&MStack104,&local_d8);
  m_Do_ext::mDoExt_setJ3DData(&MStack104,&local_88,uVar4);
  if (*(code **)(this + 100) != (code *)0x0) {
    (**(code **)(this + 100))(*(undefined4 *)(this + 0x58),uVar4,&local_88,&local_d8);
  }
  *pfVar7 = local_d8;
  pfVar7[1] = local_d4;
  pfVar7[2] = local_d0;
  pfVar7[3] = local_cc;
  *pfVar8 = local_88.mScale.x;
  pfVar8[1] = local_88.mScale.y;
  pfVar8[2] = local_88.mScale.z;
  *(short *)(pfVar8 + 3) = local_88.mRot.x;
  *(short *)((int)pfVar8 + 0xe) = local_88.mRot.y;
  *(short *)(pfVar8 + 4) = local_88.mRot.z;
  pfVar8[5] = local_88.mTranslation.x;
  pfVar8[6] = local_88.mTranslation.y;
  pfVar8[7] = local_88.mTranslation.z;
  if (uVar1 == (ushort)(pJVar2->mpModelData->mJointTree).mJointCount - 1) {
    mDoExt_MtxCalcOldFrame::decOldFrameMorfCounter(*(mDoExt_MtxCalcOldFrame **)(this + 0x5c));
  }
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  __psq_l0(auStack24,uVar10);
  __psq_l1(auStack24,uVar10);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall mDoExt_MtxCalcOldFrame::initOldFrameMorf(float,
                                                       unsigned short,
                                                       unsigned short) */

void __thiscall
mDoExt_MtxCalcOldFrame::initOldFrameMorf
          (mDoExt_MtxCalcOldFrame *this,float param_1,ushort param_2,ushort param_3)

{
  float fVar1;
  
  fVar1 = m_Do_ext::0_0;
  if (param_1 <= m_Do_ext::0_0) {
    *(float *)(this + 4) = m_Do_ext::0_0;
    *(float *)(this + 8) = fVar1;
    *(float *)(this + 0xc) = fVar1;
    *(float *)(this + 0x10) = fVar1;
    *(float *)(this + 0x14) = fVar1;
  }
  else {
    *(float *)(this + 4) = param_1;
    fVar1 = m_Do_ext::1_0;
    *(float *)(this + 8) = m_Do_ext::1_0 / param_1;
    *(float *)(this + 0xc) = fVar1;
    *(float *)(this + 0x10) = fVar1;
    *(float *)(this + 0x14) = fVar1;
    decOldFrameMorfCounter(this);
  }
  *(ushort *)(this + 0x18) = param_2;
  *(ushort *)(this + 0x1a) = param_3;
  return;
}


/* __thiscall mDoExt_MtxCalcOldFrame::decOldFrameMorfCounter(void) */

void __thiscall mDoExt_MtxCalcOldFrame::decOldFrameMorfCounter(mDoExt_MtxCalcOldFrame *this)

{
  float fVar1;
  
  fVar1 = m_Do_ext::0_0;
  if (*(float *)(this + 4) <= m_Do_ext::0_0) {
    return;
  }
  *(float *)(this + 4) = *(float *)(this + 4) - m_Do_ext::1_0;
  if (*(float *)(this + 4) <= fVar1) {
    *(float *)(this + 4) = fVar1;
    *(float *)(this + 8) = fVar1;
    *(float *)(this + 0xc) = fVar1;
  }
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(this + 0x10);
  *(float *)(this + 0x10) = *(float *)(this + 4) * *(float *)(this + 8);
  fVar1 = *(float *)(this + 0x14);
  if (m_Do_ext::0_0 < fVar1) {
    *(float *)(this + 0xc) = m_Do_ext::1_0 - (fVar1 - *(float *)(this + 0x10)) / fVar1;
    return;
  }
  *(float *)(this + 0xc) = m_Do_ext::0_0;
  return;
}


/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* WARNING: Removing unreachable block (ram,0x800129c4) */
/* __thiscall mDoExt_McaMorf::mDoExt_McaMorf(J3DModelData *,
                                             mDoExt_McaMorfCallBack1_c *,
                                             mDoExt_McaMorfCallBack2_c *,
                                             J3DAnmTransform *,
                                             int,
                                             float,
                                             int,
                                             int,
                                             int,
                                             void *,
                                             unsigned long,
                                             unsigned long) */

mDoExt_McaMorf * __thiscall
mDoExt_McaMorf::mDoExt_McaMorf
          (mDoExt_McaMorf *this,ushort param_1,J3DModelData *pModelData,
          mDoExt_McaMorfCallBack1_c *param_3,mDoExt_McaMorfCallBack2_c *param_4,
          J3DAnmTransformKey *pAnmRes,J3DFrameCtrl__LoopMode loopMode,float speed,int startFrame,
          int duration,int bUseSound,void *pSoundRes,ulong param_12,ulong param_13)

{
  ushort uVar1;
  J3DMtxCalc *pJVar2;
  J3DModel *model;
  JAIAnimeSound *this_00;
  undefined4 uVar3;
  J3DTransformInfo *pJVar4;
  Quaternion *pQVar5;
  J3DJoint *pJVar6;
  undefined3 in_register_00000024;
  uint uVar7;
  J3DModelData *pJVar8;
  undefined4 uVar9;
  double dVar10;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar10 = (double)speed;
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 != 0) {
    (this->parent).vderiv = (J3DMtxCalc *)&this->vderiv;
    this->vderiv = (undefined *)&J3DMtxCalc::__vt;
  }
  J3DMtxCalcBasic::J3DMtxCalcBasic(&this->parent);
  (this->parent).vtbl = &J3DMtxCalcMaya::__vt;
  ((this->parent).vderiv)->vtbl = &DAT_8039eba4;
  pJVar2 = (this->parent).vderiv;
  pJVar2[9].vtbl = (undefined *)((int)this + (0x50 - (int)pJVar2));
  (this->parent).vtbl = (undefined *)&__vt;
  ((this->parent).vderiv)->vtbl = &DAT_80371c04;
  pJVar2 = (this->parent).vderiv;
  pJVar2[9].vtbl = (undefined *)((int)this + (0x8c - (int)pJVar2));
  (this->mFrameCtrl).vtbl = (undefined *)&J3DFrameCtrl::__vt;
  J3DFrameCtrl::init(&this->mFrameCtrl,0);
  this->mpModel = (J3DModel *)0x0;
  this->mpSound = (JAIAnimeSound *)0x0;
  this->mpTransformInfos = (J3DTransformInfo *)0x0;
  this->mpQuats = (Quaternion *)0x0;
  if (pModelData == (J3DModelData *)0x0) goto LAB_800129c4;
  if (((pModelData->mJointTree).mbIsBDL == 1) && (param_12 == 0)) {
    if ((pModelData->mShapeTable).field_0x0 == 1) {
      param_12 = 0x20000;
    }
    else {
      param_12 = 0x80000;
    }
  }
  model = m_Do_ext::mDoExt_J3DModel__create(pModelData,param_12,param_13);
  this->mpModel = model;
  if (this->mpModel == (J3DModel *)0x0) goto LAB_800129c4;
  if (param_12 != 0x80000) {
    m_Do_ext::mDoExt_changeMaterial(this->mpModel);
  }
  if (((pSoundRes == (void *)0x0) && (pAnmRes != (J3DAnmTransformKey *)0x0)) &&
     (pSoundRes = pAnmRes->field_0x2c, pSoundRes != (void *)0x0)) {
    bUseSound = 1;
  }
  if (bUseSound == 0) {
LAB_80012820:
    setAnm(this,&pAnmRes->parent,CONCAT31(in_register_00000024,loopMode),m_Do_ext::0_0,(float)dVar10
           ,(float)((double)CONCAT44(0x43300000,startFrame ^ 0x80000000) - m_Do_ext::_4289),
           (float)((double)CONCAT44(0x43300000,duration ^ 0x80000000) - m_Do_ext::_4289),pSoundRes);
    this->mPrevMorf = m_Do_ext::_6503;
    uVar7 = (uint)(ushort)(pModelData->mJointTree).mJointCount;
    uVar3 = JKernel::operator_new__(uVar7 * 0x20 + 0x10);
    pJVar4 = (J3DTransformInfo *)Runtime.PPCEABI.H::__construct_new_array(uVar3,0,0,0x20,uVar7);
    this->mpTransformInfos = pJVar4;
    if (this->mpTransformInfos != (J3DTransformInfo *)0x0) {
      pQVar5 = (Quaternion *)
               JKernel::operator_new__((uint)(ushort)(pModelData->mJointTree).mJointCount << 4);
      this->mpQuats = pQVar5;
      pQVar5 = this->mpQuats;
      if (pQVar5 != (Quaternion *)0x0) {
        pJVar4 = this->mpTransformInfos;
        pJVar8 = this->mpModel->mpModelData;
        uVar1 = (pJVar8->mJointTree).mJointCount;
        for (uVar7 = 0; (int)uVar7 < (int)(uint)uVar1; uVar7 = uVar7 + 1) {
          pJVar6 = (pJVar8->mJointTree).mpJoints[uVar7 & 0xffff];
          (pJVar4->mScale).x = (pJVar6->mTransformInfo).mScale.x;
          (pJVar4->mScale).y = (pJVar6->mTransformInfo).mScale.y;
          (pJVar4->mScale).z = (pJVar6->mTransformInfo).mScale.z;
          (pJVar4->mRot).x = (pJVar6->mTransformInfo).mRot.x;
          (pJVar4->mRot).y = (pJVar6->mTransformInfo).mRot.y;
          (pJVar4->mRot).z = (pJVar6->mTransformInfo).mRot.z;
          (pJVar4->mTranslation).x = (pJVar6->mTransformInfo).mTranslation.x;
          (pJVar4->mTranslation).y = (pJVar6->mTransformInfo).mTranslation.y;
          (pJVar4->mTranslation).z = (pJVar6->mTransformInfo).mTranslation.z;
          JKernel::JMath::JMAEulerToQuat
                    ((int)(pJVar4->mRot).x,(int)(pJVar4->mRot).y,(int)(pJVar4->mRot).z,pQVar5);
          pJVar4 = pJVar4 + 1;
          pQVar5 = pQVar5 + 1;
        }
        this->mpCallBack1 = param_3;
        this->mpCallBack2 = param_4;
        goto LAB_800129c4;
      }
    }
  }
  else {
    this_00 = (JAIAnimeSound *)JKernel::operator_new(0x9c);
    if (this_00 != (JAIAnimeSound *)0x0) {
      JAIAnimeSound::JAIAnimeSound(this_00);
      this_00->vtbl = &JAIZelAnime::__vt;
      this_00->vtbl = &mDoExt_zelAnime::__vt;
    }
    this->mpSound = this_00;
    if (this->mpSound != (JAIAnimeSound *)0x0) goto LAB_80012820;
  }
  if (this->mpSound != (JAIAnimeSound *)0x0) {
    JAIAnimeSound::stop(this->mpSound);
    this->mpSound = (JAIAnimeSound *)0x0;
  }
  if (this->mpTransformInfos != (J3DTransformInfo *)0x0) {
    this->mpTransformInfos = (J3DTransformInfo *)0x0;
  }
  if (this->mpQuats != (Quaternion *)0x0) {
    this->mpQuats = (Quaternion *)0x0;
  }
  if (this->mpModel != (J3DModel *)0x0) {
    this->mpModel = (J3DModel *)0x0;
  }
LAB_800129c4:
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  return this;
}


/* __thiscall J3DFrameCtrl::~J3DFrameCtrl(void) */

void __thiscall J3DFrameCtrl::_J3DFrameCtrl(J3DFrameCtrl *this)

{
  short in_r4;
  
  if ((this != (J3DFrameCtrl *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x80012d50) */
/* WARNING: Removing unreachable block (ram,0x80012d58) */
/* __thiscall mDoExt_McaMorf::calc(unsigned short) */

void __thiscall mDoExt_McaMorf::calc(mDoExt_McaMorf *this,ushort idx)

{
  J3DAnmTransform *pJVar1;
  J3DJoint *pJoint;
  mDoExt_McaMorfCallBack1_c *pmVar2;
  mDoExt_McaMorfCallBack2_c *pmVar3;
  undefined2 in_register_00000010;
  undefined4 uVar4;
  J3DTransformInfo *pJVar5;
  Quaternion *pQVar6;
  Quaternion *pQuat;
  J3DTransformInfo *pInf;
  undefined4 uVar7;
  double dVar8;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar9;
  Quaternion local_c8;
  Quaternion local_b8;
  cXyz local_a8;
  short local_9c;
  short local_9a;
  short local_98;
  cXyz local_94;
  J3DTransformInfo local_88;
  MTX34 local_68;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = CONCAT22(in_register_00000010,idx);
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (this->mpModel != (J3DModel *)0x0) {
    J3DGraphBase::j3dSys.mpCurMtxCalc = (J3DMtxCalc *)this;
    if (this != (mDoExt_McaMorf *)0x0) {
      J3DGraphBase::j3dSys.mpCurMtxCalc = (this->parent).vderiv;
    }
    pJVar5 = this->mpTransformInfos;
    if (pJVar5 == (J3DTransformInfo *)0x0) {
      pInf = &local_88;
    }
    else {
      pInf = pJVar5 + idx;
    }
    pQVar6 = this->mpQuats;
    if (pQVar6 == (Quaternion *)0x0) {
      pQuat = &local_b8;
    }
    else {
      pQuat = pQVar6 + idx;
    }
    pJVar1 = this->mpAnm;
    if (pJVar1 == (J3DAnmTransform *)0x0) {
      pJoint = (this->mpModel->mpModelData->mJointTree).mpJoints[idx];
      (pInf->mScale).x = (pJoint->mTransformInfo).mScale.x;
      (pInf->mScale).y = (pJoint->mTransformInfo).mScale.y;
      (pInf->mScale).z = (pJoint->mTransformInfo).mScale.z;
      (pInf->mRot).x = (pJoint->mTransformInfo).mRot.x;
      (pInf->mRot).y = (pJoint->mTransformInfo).mRot.y;
      (pInf->mRot).z = (pJoint->mTransformInfo).mRot.z;
      (pInf->mTranslation).x = (pJoint->mTransformInfo).mTranslation.x;
      (pInf->mTranslation).y = (pJoint->mTransformInfo).mTranslation.y;
      (pInf->mTranslation).z = (pJoint->mTransformInfo).mTranslation.z;
      pmVar2 = this->mpCallBack1;
      if (pmVar2 != (mDoExt_McaMorfCallBack1_c *)0x0) {
        (*(code *)pmVar2->vtbl->field_0xc)(pmVar2,uVar4,pInf);
      }
      JKernel::JMath::JMAEulerToQuat
                ((int)(pInf->mRot).x,(int)(pInf->mRot).y,(int)(pInf->mRot).z,pQuat);
      (**(code **)((this->parent).vtbl + 0x14))(this,uVar4,pInf);
    }
    else {
      dVar8 = (double)m_Do_ext::1_0;
      if (((dVar8 <= (double)this->mCurMorf) || (pJVar5 == (J3DTransformInfo *)0x0)) ||
         (pQVar6 == (Quaternion *)0x0)) {
        (**(code **)((pJVar1->parent).vtbl + 0xc))(pJVar1,uVar4,pInf);
        pmVar2 = this->mpCallBack1;
        if (pmVar2 != (mDoExt_McaMorfCallBack1_c *)0x0) {
          (*(code *)pmVar2->vtbl->field_0xc)(pmVar2,uVar4,pInf);
        }
        JKernel::JMath::JMAEulerToQuat
                  ((int)(pInf->mRot).x,(int)(pInf->mRot).y,(int)(pInf->mRot).z,pQuat);
        (**(code **)((this->parent).vtbl + 0x14))(this,uVar4,pInf);
      }
      else {
        dVar9 = (double)((float)((double)this->mCurMorf - (double)this->mPrevMorf) /
                        (float)(dVar8 - (double)this->mPrevMorf));
        dVar8 = (double)(float)(dVar8 - dVar9);
        (**(code **)((pJVar1->parent).vtbl + 0xc))(pJVar1,uVar4,&local_a8);
        pmVar2 = this->mpCallBack1;
        if (pmVar2 != (mDoExt_McaMorfCallBack1_c *)0x0) {
          (*(code *)pmVar2->vtbl->field_0xc)(pmVar2,uVar4,&local_a8);
        }
        JKernel::JMath::JMAEulerToQuat((int)local_9c,(int)local_9a,(int)local_98,&local_c8);
        JKernel::JMath::JMAQuatLerp(dVar9,pQuat,&local_c8,pQuat);
        mtx::PSMTXQuat(&local_68,pQuat);
        (pInf->mTranslation).x =
             (float)((double)(pInf->mTranslation).x * dVar8) + (float)((double)local_94.x * dVar9);
        (pInf->mTranslation).y =
             (float)((double)(pInf->mTranslation).y * dVar8) + (float)((double)local_94.y * dVar9);
        (pInf->mTranslation).z =
             (float)((double)(pInf->mTranslation).z * dVar8) + (float)((double)local_94.z * dVar9);
        (pInf->mScale).x =
             (float)((double)(pInf->mScale).x * dVar8) + (float)((double)local_a8.x * dVar9);
        (pInf->mScale).y =
             (float)((double)(pInf->mScale).y * dVar8) + (float)((double)local_a8.y * dVar9);
        (pInf->mScale).z =
             (float)((double)(pInf->mScale).z * dVar8) + (float)((double)local_a8.z * dVar9);
        m_Do_ext::mDoExt_setJ3DData(&local_68,pInf,uVar4);
      }
    }
    pmVar3 = this->mpCallBack2;
    if (pmVar3 != (mDoExt_McaMorfCallBack2_c *)0x0) {
      (*(code *)pmVar3->vtbl->field_0xc)(pmVar3,uVar4);
    }
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x80012fa0) */
/* WARNING: Removing unreachable block (ram,0x80012f98) */
/* WARNING: Removing unreachable block (ram,0x80012fa8) */
/* __thiscall mDoExt_McaMorf::setAnm(J3DAnmTransform *,
                                     int,
                                     float,
                                     float,
                                     float,
                                     float,
                                     void *) */

void __thiscall
mDoExt_McaMorf::setAnm
          (mDoExt_McaMorf *this,J3DAnmTransform *pAnimRes,int loopMode,float morf,float speed,
          float startFrame,float duration,void *pSoundAnimRes)

{
  JAIAnimeSound *this_00;
  int uVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  double local_58;
  double local_50;
  double local_48;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar5 = (double)startFrame;
  dVar4 = (double)speed;
  dVar3 = (double)morf;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  this->mpAnm = pAnimRes;
  (this->mFrameCtrl).mStartFrame = (short)(int)startFrame;
  local_48 = (double)CONCAT44(0x43300000,(int)(short)(int)startFrame ^ 0x80000000);
  (this->mFrameCtrl).mCurrentTime = (float)(local_48 - m_Do_ext::_4289);
  if (m_Do_ext::0_0 <= duration) {
    J3DFrameCtrl::init(&this->mFrameCtrl,(short)(int)duration);
  }
  else {
    if (this->mpAnm == (J3DAnmTransform *)0x0) {
      J3DFrameCtrl::init(&this->mFrameCtrl,0);
    }
    else {
      J3DFrameCtrl::init(&this->mFrameCtrl,(this->mpAnm->parent).mDuration);
    }
  }
  if ((pAnimRes != (J3DAnmTransform *)0x0) && (loopMode < 0)) {
    loopMode = ZEXT14((pAnimRes->parent).mLoopMode);
  }
  (this->mFrameCtrl).mLoopMode = (J3DFrameCtrl__LoopMode)loopMode;
  (this->mFrameCtrl).mSpeed = (float)dVar4;
  if (dVar4 < (double)m_Do_ext::0_0) {
    local_48 = (double)CONCAT44(0x43300000,(int)(this->mFrameCtrl).mEndFrame ^ 0x80000000);
    local_58 = (double)CONCAT44(0x43300000,
                                (int)(short)(int)(local_48 - m_Do_ext::_4289) ^ 0x80000000);
    (this->mFrameCtrl).mCurrentTime = (float)(local_58 - m_Do_ext::_4289);
  }
  else {
    local_50 = (double)CONCAT44(0x43300000,(int)(short)(int)dVar5 ^ 0x80000000);
    (this->mFrameCtrl).mCurrentTime = (float)(local_50 - m_Do_ext::_4289);
  }
  (this->mFrameCtrl).mLoopFrame = (short)(int)(this->mFrameCtrl).mCurrentTime;
  setMorf(this,(float)dVar3);
  if (this->mpSound != (JAIAnimeSound *)0x0) {
    if ((pSoundAnimRes == (void *)0x0) && (pAnimRes != (J3DAnmTransform *)0x0)) {
      pSoundAnimRes = *(void **)&pAnimRes[1].field_0x10;
    }
    *(void **)this->mpSound[1].mSlots = pSoundAnimRes;
    this_00 = this->mpSound;
    if (*(int *)this_00[1].mSlots == 0) {
      JAIAnimeSound::stop(this_00);
    }
    else {
      local_48 = (double)CONCAT44(0x43300000,(int)(this->mFrameCtrl).mLoopFrame ^ 0x80000000);
      if ((this->mFrameCtrl).mSpeed < m_Do_ext::0_0) {
        uVar1 = 0xffffffff;
      }
      else {
        uVar1 = 1;
      }
      JAIAnimeSound::initActorAnimSound
                (this_00,pSoundAnimRes,uVar1,(float)(local_48 - m_Do_ext::_4289));
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  return;
}


/* __thiscall mDoExt_McaMorf::setMorf(float) */

void __thiscall mDoExt_McaMorf::setMorf(mDoExt_McaMorf *this,float param_1)

{
  if ((this->mPrevMorf < m_Do_ext::0_0) || (param_1 <= m_Do_ext::0_0)) {
    this->mCurMorf = m_Do_ext::1_0;
  }
  else {
    this->mCurMorf = m_Do_ext::0_0;
    this->mMorfStepPerFrame = m_Do_ext::1_0 / param_1;
  }
  this->mPrevMorf = this->mCurMorf;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall mDoExt_McaMorf::play(Vec *,
                                   unsigned long,
                                   signed char) */

undefined4 __thiscall
mDoExt_McaMorf::play(mDoExt_McaMorf *this,cXyz *pPos,ulong param_2,sbyte param_3)

{
  float target;
  JAIAnimeSound *this_00;
  undefined4 uVar1;
  
  target = m_Do_ext::1_0;
  if (this->mCurMorf < m_Do_ext::1_0) {
    this->mPrevMorf = this->mCurMorf;
    SComponent::cLib_chaseF(&this->mCurMorf,target,this->mMorfStepPerFrame);
  }
  J3DFrameCtrl::update(&this->mFrameCtrl);
  this_00 = this->mpSound;
  if (((this_00 != (JAIAnimeSound *)0x0) && (*(int *)this_00[1].mSlots != 0)) &&
     (pPos != (cXyz *)0x0)) {
    JAIZelAnime::setAnimSound
              ((JAIZelAnime *)this_00,pPos,(this->mFrameCtrl).mCurrentTime,(this->mFrameCtrl).mSpeed
               ,param_2,param_3);
  }
  uVar1 = 1;
  if ((((this->mFrameCtrl).mFlags & 1) == 0) && (m_Do_ext::0_0 != (this->mFrameCtrl).mSpeed)) {
    uVar1 = 0;
  }
  return uVar1;
}


/* __thiscall mDoExt_McaMorf::update(void) */

void __thiscall mDoExt_McaMorf::update(mDoExt_McaMorf *this)

{
  mDoExt_McaMorf *pmVar1;
  
  if (this->mpModel != (J3DModel *)0x0) {
    if (this->mpAnm != (J3DAnmTransform *)0x0) {
      (this->mpAnm->parent).mCurrentTime = (this->mFrameCtrl).mCurrentTime;
    }
    pmVar1 = this;
    if (this != (mDoExt_McaMorf *)0x0) {
      pmVar1 = (mDoExt_McaMorf *)(this->parent).vderiv;
    }
    (*(this->mpModel->mpModelData->mJointTree).mpJoints)->mpMtxCalc = (J3DMtxCalc *)pmVar1;
    m_Do_ext::mDoExt_modelUpdate(this->mpModel);
    this->mPrevMorf = this->mCurMorf;
  }
  return;
}


/* __thiscall mDoExt_McaMorf::updateDL(void) */

void __thiscall mDoExt_McaMorf::updateDL(mDoExt_McaMorf *this)

{
  mDoExt_McaMorf *pmVar1;
  
  if (this->mpModel != (J3DModel *)0x0) {
    if (this->mpAnm != (J3DAnmTransform *)0x0) {
      (this->mpAnm->parent).mCurrentTime = (this->mFrameCtrl).mCurrentTime;
    }
    pmVar1 = this;
    if (this != (mDoExt_McaMorf *)0x0) {
      pmVar1 = (mDoExt_McaMorf *)(this->parent).vderiv;
    }
    (*(this->mpModel->mpModelData->mJointTree).mpJoints)->mpMtxCalc = (J3DMtxCalc *)pmVar1;
    m_Do_ext::mDoExt_modelUpdateDL(this->mpModel);
    this->mPrevMorf = this->mCurMorf;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall mDoExt_McaMorf::updateDL(J3DMaterialTable *) */

void __thiscall mDoExt_McaMorf::updateDL(mDoExt_McaMorf *this,J3DMaterialTable *param_1)

{
  JUTNameTab *pJVar1;
  J3DTexture *pJVar2;
  J3DModelData *this_00;
  
  if (this->mpModel != (J3DModel *)0x0) {
    this_00 = this->mpModel->mpModelData;
    pJVar2 = (this_00->mMaterialTable).mpTexture;
    pJVar1 = (this_00->mMaterialTable).mpTexNameTab;
    J3DModelData::setMaterialTable(this_00,param_1,2);
    updateDL(this);
    (this_00->mMaterialTable).mpTexture = pJVar2;
    (this_00->mMaterialTable).mpTexNameTab = pJVar1;
  }
  return;
}


/* __thiscall mDoExt_McaMorf::entry(void) */

void __thiscall mDoExt_McaMorf::entry(mDoExt_McaMorf *this)

{
  if (this->mpModel != (J3DModel *)0x0) {
    m_Do_ext::mDoExt_modelEntry();
  }
  return;
}


/* __thiscall mDoExt_McaMorf::entryDL(void) */

void __thiscall mDoExt_McaMorf::entryDL(mDoExt_McaMorf *this)

{
  if (this->mpModel != (J3DModel *)0x0) {
    m_Do_ext::mDoExt_modelEntryDL(this->mpModel);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall mDoExt_McaMorf::entryDL(J3DMaterialTable *) */

void __thiscall mDoExt_McaMorf::entryDL(mDoExt_McaMorf *this,J3DMaterialTable *param_1)

{
  JUTNameTab *pJVar1;
  J3DTexture *pJVar2;
  J3DModelData *this_00;
  
  if (this->mpModel != (J3DModel *)0x0) {
    this_00 = this->mpModel->mpModelData;
    pJVar2 = (this_00->mMaterialTable).mpTexture;
    pJVar1 = (this_00->mMaterialTable).mpTexNameTab;
    J3DModelData::setMaterialTable(this_00,param_1,2);
    entryDL(this);
    (this_00->mMaterialTable).mpTexture = pJVar2;
    (this_00->mMaterialTable).mpTexNameTab = pJVar1;
  }
  return;
}


/* __thiscall mDoExt_McaMorf::calc(void) */

void __thiscall mDoExt_McaMorf::calc(mDoExt_McaMorf *this)

{
  mDoExt_McaMorf *pmVar1;
  
  if (this->mpModel != (J3DModel *)0x0) {
    if (this->mpAnm != (J3DAnmTransform *)0x0) {
      (this->mpAnm->parent).mCurrentTime = (this->mFrameCtrl).mCurrentTime;
    }
    pmVar1 = this;
    if (this != (mDoExt_McaMorf *)0x0) {
      pmVar1 = (mDoExt_McaMorf *)(this->parent).vderiv;
    }
    (*(this->mpModel->mpModelData->mJointTree).mpJoints)->mpMtxCalc = (J3DMtxCalc *)pmVar1;
    (*(code *)this->mpModel->vtbl->calc)();
  }
  return;
}


/* __thiscall mDoExt_McaMorf::stopZelAnime(void) */

void __thiscall mDoExt_McaMorf::stopZelAnime(mDoExt_McaMorf *this)

{
  if (this->mpSound != (JAIAnimeSound *)0x0) {
    JAIAnimeSound::stop(this->mpSound);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* WARNING: Removing unreachable block (ram,0x800136d4) */
/* __thiscall mDoExt_McaMorf2::mDoExt_McaMorf2(J3DModelData *,
                                               mDoExt_McaMorfCallBack1_c *,
                                               mDoExt_McaMorfCallBack2_c *,
                                               J3DAnmTransform *,
                                               J3DAnmTransform *,
                                               int,
                                               float,
                                               int,
                                               int,
                                               int,
                                               void *,
                                               unsigned long,
                                               unsigned long) */

void __thiscall
mDoExt_McaMorf2::mDoExt_McaMorf2
          (mDoExt_McaMorf2 *this,int param_1,J3DModelData *pModelData,
          mDoExt_McaMorfCallBack1_c *pCB1,mDoExt_McaMorfCallBack2_c *pCB2,J3DAnmTransform *pAnm1,
          J3DAnmTransform *pAnm2,int param_7,float param_8,int param_9,int param_10,int param_11,
          void *param_12,ulong param_13,ulong param_14)

{
  ushort uVar1;
  J3DMtxCalc *pJVar2;
  J3DModel *pJVar3;
  JAIAnimeSound *this_00;
  undefined4 uVar4;
  J3DTransformInfo *pJVar5;
  Quaternion *pQVar6;
  J3DJoint *pJVar7;
  uint uVar8;
  J3DModelData *pJVar9;
  undefined4 uVar10;
  double dVar11;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar11 = (double)param_8;
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if ((short)param_1 != 0) {
    (this->parent).vderiv = &this->vderiv2;
    (this->vderiv2).vtbl = (undefined *)&J3DMtxCalc::__vt;
  }
  J3DMtxCalcBasic::J3DMtxCalcBasic(&this->parent);
  (this->parent).vtbl = &J3DMtxCalcMaya::__vt;
  ((this->parent).vderiv)->vtbl = &DAT_8039eba4;
  pJVar2 = (this->parent).vderiv;
  pJVar2[9].vtbl = (undefined *)((int)this + (0x50 - (int)pJVar2));
  (this->parent).vtbl = &__vt;
  ((this->parent).vderiv)->vtbl = &DAT_80371bd0;
  pJVar2 = (this->parent).vderiv;
  pJVar2[9].vtbl = (undefined *)((int)this + (0x94 - (int)pJVar2));
  (this->mFrameCtrl).vtbl = (undefined *)&J3DFrameCtrl::__vt;
  J3DFrameCtrl::init(&this->mFrameCtrl,0);
  this->mpModel = (J3DModel *)0x0;
  this->mpAnimeSound = (JAIAnimeSound *)0x0;
  this->mpTransformInfo = (J3DTransformInfo *)0x0;
  this->mpQuaternion = (Quaternion *)0x0;
  if (pModelData != (J3DModelData *)0x0) {
    if (((pModelData->mJointTree).mbIsBDL == 1) && (param_13 == 0)) {
      if ((pModelData->mShapeTable).field_0x0 == 1) {
        param_13 = 0x20000;
      }
      else {
        param_13 = 0x80000;
      }
    }
    pJVar3 = m_Do_ext::mDoExt_J3DModel__create(pModelData,param_13,param_14);
    this->mpModel = pJVar3;
    if (this->mpModel != (J3DModel *)0x0) {
      if (param_13 != 0x80000) {
        m_Do_ext::mDoExt_changeMaterial(this->mpModel);
      }
      if (((param_12 == (void *)0x0) && (pAnm1 != (J3DAnmTransform *)0x0)) &&
         (param_12 = *(void **)&pAnm1[1].field_0x10, param_12 != (void *)0x0)) {
        param_11 = 1;
      }
      if (param_11 != 0) {
        this_00 = (JAIAnimeSound *)JKernel::operator_new(0x9c);
        if (this_00 != (JAIAnimeSound *)0x0) {
          JAIAnimeSound::JAIAnimeSound(this_00);
          this_00->vtbl = &JAIZelAnime::__vt;
          this_00->vtbl = &mDoExt_zelAnime::__vt;
        }
        this->mpAnimeSound = this_00;
        if (this->mpAnimeSound == (JAIAnimeSound *)0x0) {
          ERROR_EXIT(this);
          goto LAB_800136d4;
        }
      }
      setAnm(this,pAnm1,pAnm2,m_Do_ext::0_0,param_7,m_Do_ext::0_0,(float)dVar11,
             (float)((double)CONCAT44(0x43300000,param_9 ^ 0x80000000) - m_Do_ext::_4289),
             (float)((double)CONCAT44(0x43300000,param_10 ^ 0x80000000) - m_Do_ext::_4289),param_12)
      ;
      uVar8 = (uint)(ushort)(pModelData->mJointTree).mJointCount;
      uVar4 = JKernel::operator_new__(uVar8 * 0x20 + 0x10);
      pJVar5 = (J3DTransformInfo *)Runtime.PPCEABI.H::__construct_new_array(uVar4,0,0,0x20,uVar8);
      this->mpTransformInfo = pJVar5;
      if (this->mpTransformInfo == (J3DTransformInfo *)0x0) {
        ERROR_EXIT(this);
      }
      else {
        pQVar6 = (Quaternion *)
                 JKernel::operator_new__((uint)(ushort)(pModelData->mJointTree).mJointCount << 4);
        this->mpQuaternion = pQVar6;
        pQVar6 = this->mpQuaternion;
        if (pQVar6 == (Quaternion *)0x0) {
          ERROR_EXIT(this);
        }
        else {
          pJVar5 = this->mpTransformInfo;
          pJVar9 = this->mpModel->mpModelData;
          uVar1 = (pJVar9->mJointTree).mJointCount;
          for (uVar8 = 0; (int)uVar8 < (int)(uint)uVar1; uVar8 = uVar8 + 1) {
            pJVar7 = (pJVar9->mJointTree).mpJoints[uVar8 & 0xffff];
            (pJVar5->mScale).x = (pJVar7->mTransformInfo).mScale.x;
            (pJVar5->mScale).y = (pJVar7->mTransformInfo).mScale.y;
            (pJVar5->mScale).z = (pJVar7->mTransformInfo).mScale.z;
            (pJVar5->mRot).x = (pJVar7->mTransformInfo).mRot.x;
            (pJVar5->mRot).y = (pJVar7->mTransformInfo).mRot.y;
            (pJVar5->mRot).z = (pJVar7->mTransformInfo).mRot.z;
            (pJVar5->mTranslation).x = (pJVar7->mTransformInfo).mTranslation.x;
            (pJVar5->mTranslation).y = (pJVar7->mTransformInfo).mTranslation.y;
            (pJVar5->mTranslation).z = (pJVar7->mTransformInfo).mTranslation.z;
            JKernel::JMath::JMAEulerToQuat
                      ((int)(pJVar5->mRot).x,(int)(pJVar5->mRot).y,(int)(pJVar5->mRot).z,pQVar6);
            pJVar5 = pJVar5 + 1;
            pQVar6 = pQVar6 + 1;
          }
          this->mpCB1 = pCB1;
          this->mpCB2 = pCB2;
        }
      }
    }
  }
LAB_800136d4:
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  return;
}


/* __thiscall mDoExt_McaMorf2::ERROR_EXIT(void) */

void __thiscall mDoExt_McaMorf2::ERROR_EXIT(mDoExt_McaMorf2 *this)

{
  if (this->mpAnimeSound != (JAIAnimeSound *)0x0) {
    JAIAnimeSound::stop(this->mpAnimeSound);
    this->mpAnimeSound = (JAIAnimeSound *)0x0;
  }
  if (this->mpTransformInfo != (J3DTransformInfo *)0x0) {
    this->mpTransformInfo = (J3DTransformInfo *)0x0;
  }
  if (this->mpQuaternion != (Quaternion *)0x0) {
    this->mpQuaternion = (Quaternion *)0x0;
  }
  if (this->mpModel != (J3DModel *)0x0) {
    this->mpModel = (J3DModel *)0x0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x80013e28) */
/* WARNING: Removing unreachable block (ram,0x80013e30) */
/* __thiscall mDoExt_McaMorf2::calc(unsigned short) */

void __thiscall mDoExt_McaMorf2::calc(mDoExt_McaMorf2 *this,ushort param_1)

{
  int *piVar1;
  J3DJoint *pJVar2;
  mDoExt_McaMorfCallBack1_c *pmVar3;
  mDoExt_McaMorfCallBack2_c *pmVar4;
  undefined2 in_register_00000010;
  undefined4 uVar5;
  J3DTransformInfo *pJVar6;
  Quaternion *pQVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  Quaternion *pDst;
  J3DTransformInfo *pInfo;
  undefined4 uVar11;
  double dVar12;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar13;
  Quaternion QStack344;
  Quaternion QStack328;
  Quaternion QStack312;
  undefined auStack296 [16];
  Quaternion QStack280;
  undefined auStack264 [16];
  float local_f8;
  float local_f4;
  float local_f0;
  short local_ec;
  short local_ea;
  short local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  J3DTransformInfo local_d8;
  MTX34 MStack184;
  float local_88;
  float local_84;
  float local_80;
  short local_7c [4];
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_54;
  float local_50;
  float local_4c;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar5 = CONCAT22(in_register_00000010,param_1);
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (this->mpModel != (J3DModel *)0x0) {
    J3DGraphBase::j3dSys.mpCurMtxCalc = (J3DMtxCalc *)this;
    if (this != (mDoExt_McaMorf2 *)0x0) {
      J3DGraphBase::j3dSys.mpCurMtxCalc = (this->parent).vderiv;
    }
    pJVar6 = this->mpTransformInfo;
    if (pJVar6 == (J3DTransformInfo *)0x0) {
      pInfo = &local_d8;
    }
    else {
      pInfo = pJVar6 + param_1;
    }
    pQVar7 = this->mpQuaternion;
    if (pQVar7 == (Quaternion *)0x0) {
      pDst = &QStack328;
    }
    else {
      pDst = pQVar7 + param_1;
    }
    piVar1 = *(int **)&this->field_0x54;
    if (piVar1 == (int *)0x0) {
      pJVar2 = (this->mpModel->mpModelData->mJointTree).mpJoints[param_1];
      (pInfo->mScale).x = (pJVar2->mTransformInfo).mScale.x;
      (pInfo->mScale).y = (pJVar2->mTransformInfo).mScale.y;
      (pInfo->mScale).z = (pJVar2->mTransformInfo).mScale.z;
      (pInfo->mRot).x = (pJVar2->mTransformInfo).mRot.x;
      (pInfo->mRot).y = (pJVar2->mTransformInfo).mRot.y;
      (pInfo->mRot).z = (pJVar2->mTransformInfo).mRot.z;
      (pInfo->mTranslation).x = (pJVar2->mTransformInfo).mTranslation.x;
      (pInfo->mTranslation).y = (pJVar2->mTransformInfo).mTranslation.y;
      (pInfo->mTranslation).z = (pJVar2->mTransformInfo).mTranslation.z;
      pmVar3 = this->mpCB1;
      if (pmVar3 != (mDoExt_McaMorfCallBack1_c *)0x0) {
        (*(code *)pmVar3->vtbl->field_0xc)(pmVar3,uVar5,pInfo);
      }
      JKernel::JMath::JMAEulerToQuat
                ((int)(pInfo->mRot).x,(int)(pInfo->mRot).y,(int)(pInfo->mRot).z,pDst);
      (**(code **)((this->parent).vtbl + 0x14))(this,uVar5,pInfo);
    }
    else {
      dVar12 = (double)m_Do_ext::1_0;
      if (((dVar12 <= (double)*(float *)&this->field_0x78) || (pJVar6 == (J3DTransformInfo *)0x0))
         || (pQVar7 == (Quaternion *)0x0)) {
        (**(code **)(*piVar1 + 0xc))(piVar1,uVar5,&local_88);
        piVar1 = *(int **)&this->field_0x58;
        if (piVar1 == (int *)0x0) {
          pmVar3 = this->mpCB1;
          if (pmVar3 != (mDoExt_McaMorfCallBack1_c *)0x0) {
            (*(code *)pmVar3->vtbl->field_0xc)(pmVar3,uVar5,&local_88);
          }
          JKernel::JMath::JMAEulerToQuat((int)local_7c[0],(int)local_7c[1],(int)local_7c[2],pDst);
          (**(code **)((this->parent).vtbl + 0x14))(this,uVar5,&local_88);
          (pInfo->mScale).x = local_88;
          (pInfo->mScale).y = local_84;
          (pInfo->mScale).z = local_80;
          (pInfo->mRot).x = local_7c[0];
          (pInfo->mRot).y = local_7c[1];
          (pInfo->mRot).z = local_7c[2];
          (pInfo->mTranslation).x = local_74;
          (pInfo->mTranslation).y = local_70;
          (pInfo->mTranslation).z = local_6c;
        }
        else {
          (**(code **)(*piVar1 + 0xc))(piVar1,uVar5,&local_68);
          dVar12 = (double)*(float *)&this->field_0x84;
          dVar13 = (double)(float)((double)m_Do_ext::1_0 - dVar12);
          (pInfo->mScale).x =
               (float)((double)local_88 * dVar13) + (float)((double)local_68 * dVar12);
          (pInfo->mScale).y =
               (float)((double)local_84 * dVar13) + (float)((double)local_64 * dVar12);
          (pInfo->mScale).z =
               (float)((double)local_80 * dVar13) + (float)((double)local_60 * dVar12);
          (pInfo->mTranslation).x =
               (float)((double)local_74 * dVar13) + (float)((double)local_54 * dVar12);
          (pInfo->mTranslation).y =
               (float)((double)local_70 * dVar13) + (float)((double)local_50 * dVar12);
          (pInfo->mTranslation).z =
               (float)((double)local_6c * dVar13) + (float)((double)local_4c * dVar12);
          iVar8 = 0;
          iVar9 = 0;
          iVar10 = 0;
          do {
            JKernel::JMath::JMAEulerToQuat
                      ((int)*(short *)((int)local_7c + iVar10),
                       (int)*(short *)((int)local_7c + iVar10 + 2),
                       (int)*(short *)((int)local_7c + iVar10 + 4),
                       (Quaternion *)((int)&QStack280.x + iVar9));
            iVar8 = iVar8 + 1;
            iVar9 = iVar9 + 0x10;
            iVar10 = iVar10 + 0x20;
          } while (iVar8 < 2);
          JKernel::JMath::JMAQuatLerp
                    ((double)(float)(dVar12 / (double)(float)(dVar13 + dVar12)),&QStack280,
                     auStack264,pDst);
          mtx::PSMTXQuat(&MStack184,pDst);
          m_Do_ext::mDoExt_setJ3DData(&MStack184,pInfo,uVar5);
        }
      }
      else {
        if (*(int *)&this->field_0x58 == 0) {
          dVar13 = (double)((float)((double)*(float *)&this->field_0x78 -
                                   (double)*(float *)&this->field_0x7c) /
                           (float)(dVar12 - (double)*(float *)&this->field_0x7c));
          dVar12 = (double)(float)(dVar12 - dVar13);
          (**(code **)(*piVar1 + 0xc))(piVar1,uVar5,&local_f8);
          pmVar3 = this->mpCB1;
          if (pmVar3 != (mDoExt_McaMorfCallBack1_c *)0x0) {
            (*(code *)pmVar3->vtbl->field_0xc)(pmVar3,uVar5,&local_f8);
          }
          JKernel::JMath::JMAEulerToQuat((int)local_ec,(int)local_ea,(int)local_e8,&QStack344);
          JKernel::JMath::JMAQuatLerp(dVar13,pDst,&QStack344,pDst);
          mtx::PSMTXQuat(&MStack184,pDst);
          (pInfo->mTranslation).x =
               (float)((double)(pInfo->mTranslation).x * dVar12) +
               (float)((double)local_e4 * dVar13);
          (pInfo->mTranslation).y =
               (float)((double)(pInfo->mTranslation).y * dVar12) +
               (float)((double)local_e0 * dVar13);
          (pInfo->mTranslation).z =
               (float)((double)(pInfo->mTranslation).z * dVar12) +
               (float)((double)local_dc * dVar13);
          (pInfo->mScale).x =
               (float)((double)(pInfo->mScale).x * dVar12) + (float)((double)local_f8 * dVar13);
          (pInfo->mScale).y =
               (float)((double)(pInfo->mScale).y * dVar12) + (float)((double)local_f4 * dVar13);
          (pInfo->mScale).z =
               (float)((double)(pInfo->mScale).z * dVar12) + (float)((double)local_f0 * dVar13);
          m_Do_ext::mDoExt_setJ3DData(&MStack184,pInfo,uVar5);
        }
        else {
          (**(code **)(*piVar1 + 0xc))(piVar1,uVar5,&local_88);
          (**(code **)(**(int **)&this->field_0x58 + 0xc))
                    (*(int **)&this->field_0x58,uVar5,&local_68);
          dVar12 = (double)*(float *)&this->field_0x84;
          dVar13 = (double)(float)((double)m_Do_ext::1_0 - dVar12);
          local_f8 = (float)((double)local_88 * dVar13) + (float)((double)local_68 * dVar12);
          local_f4 = (float)((double)local_84 * dVar13) + (float)((double)local_64 * dVar12);
          local_f0 = (float)((double)local_80 * dVar13) + (float)((double)local_60 * dVar12);
          local_e4 = (float)((double)local_74 * dVar13) + (float)((double)local_54 * dVar12);
          local_e0 = (float)((double)local_70 * dVar13) + (float)((double)local_50 * dVar12);
          local_dc = (float)((double)local_6c * dVar13) + (float)((double)local_4c * dVar12);
          iVar8 = 0;
          iVar10 = 0;
          iVar9 = 0;
          do {
            JKernel::JMath::JMAEulerToQuat
                      ((int)*(short *)((int)local_7c + iVar9),
                       (int)*(short *)((int)local_7c + iVar9 + 2),
                       (int)*(short *)((int)local_7c + iVar9 + 4),
                       (Quaternion *)((int)&QStack312.x + iVar10));
            iVar8 = iVar8 + 1;
            iVar10 = iVar10 + 0x10;
            iVar9 = iVar9 + 0x20;
          } while (iVar8 < 2);
          JKernel::JMath::JMAQuatLerp
                    ((double)(float)(dVar12 / (double)(float)(dVar13 + dVar12)),&QStack312,
                     auStack296,&QStack344);
          dVar12 = (double)((float)((double)*(float *)&this->field_0x78 -
                                   (double)*(float *)&this->field_0x7c) /
                           (float)((double)m_Do_ext::1_0 - (double)*(float *)&this->field_0x7c));
          dVar13 = (double)(float)((double)m_Do_ext::1_0 - dVar12);
          JKernel::JMath::JMAQuatLerp(dVar12,pDst,&QStack344,pDst);
          (pInfo->mTranslation).x =
               (float)((double)(pInfo->mTranslation).x * dVar13) +
               (float)((double)local_e4 * dVar12);
          (pInfo->mTranslation).y =
               (float)((double)(pInfo->mTranslation).y * dVar13) +
               (float)((double)local_e0 * dVar12);
          (pInfo->mTranslation).z =
               (float)((double)(pInfo->mTranslation).z * dVar13) +
               (float)((double)local_dc * dVar12);
          (pInfo->mScale).x =
               (float)((double)(pInfo->mScale).x * dVar13) + (float)((double)local_f8 * dVar12);
          (pInfo->mScale).y =
               (float)((double)(pInfo->mScale).y * dVar13) + (float)((double)local_f4 * dVar12);
          (pInfo->mScale).z =
               (float)((double)(pInfo->mScale).z * dVar13) + (float)((double)local_f0 * dVar12);
          mtx::PSMTXQuat(&MStack184,pDst);
          m_Do_ext::mDoExt_setJ3DData(&MStack184,pInfo,uVar5);
        }
      }
    }
    pmVar4 = this->mpCB2;
    if (pmVar4 != (mDoExt_McaMorfCallBack2_c *)0x0) {
      (*(code *)pmVar4->vtbl->field_0xc)(pmVar4,uVar5);
    }
  }
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  __psq_l0(auStack24,uVar11);
  __psq_l1(auStack24,uVar11);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x80014078) */
/* WARNING: Removing unreachable block (ram,0x80014070) */
/* WARNING: Removing unreachable block (ram,0x80014080) */
/* __thiscall mDoExt_McaMorf2::setAnm(J3DAnmTransform *,
                                      J3DAnmTransform *,
                                      float,
                                      int,
                                      float,
                                      float,
                                      float,
                                      float,
                                      void *) */

void __thiscall
mDoExt_McaMorf2::setAnm
          (mDoExt_McaMorf2 *this,J3DAnmTransform *param_1,J3DAnmTransform *param_2,float param_3,
          int param_4,float param_5,float param_6,float param_7,float param_8,void *param_9)

{
  JAIAnimeSound *this_00;
  ulong direction;
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  double local_58;
  double local_50;
  double local_48;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar3 = (double)param_6;
  dVar4 = (double)param_7;
  dVar2 = (double)param_5;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  *(J3DAnmTransform **)&this->field_0x54 = param_1;
  *(J3DAnmTransform **)&this->field_0x58 = param_2;
  *(float *)&this->field_0x84 = param_3;
  (this->mFrameCtrl).mStartFrame = (short)(int)param_7;
  local_48 = (double)CONCAT44(0x43300000,(int)(short)(int)param_7 ^ 0x80000000);
  (this->mFrameCtrl).mCurrentTime = (float)(local_48 - m_Do_ext::_4289);
  if (m_Do_ext::0_0 <= param_8) {
    J3DFrameCtrl::init(&this->mFrameCtrl,(short)(int)param_8);
  }
  else {
    if (*(int *)&this->field_0x54 == 0) {
      J3DFrameCtrl::init(&this->mFrameCtrl,0);
    }
    else {
      J3DFrameCtrl::init(&this->mFrameCtrl,*(short *)(*(int *)&this->field_0x54 + 6));
    }
  }
  if (param_4 < 0) {
    param_4 = ZEXT14((param_1->parent).mLoopMode);
  }
  (this->mFrameCtrl).mLoopMode = (J3DFrameCtrl__LoopMode)param_4;
  (this->mFrameCtrl).mSpeed = (float)dVar3;
  if (dVar3 < (double)m_Do_ext::0_0) {
    local_48 = (double)CONCAT44(0x43300000,(int)(this->mFrameCtrl).mEndFrame ^ 0x80000000);
    local_58 = (double)CONCAT44(0x43300000,
                                (int)(short)(int)(local_48 - m_Do_ext::_4289) ^ 0x80000000);
    (this->mFrameCtrl).mCurrentTime = (float)(local_58 - m_Do_ext::_4289);
  }
  else {
    local_50 = (double)CONCAT44(0x43300000,(int)(short)(int)dVar4 ^ 0x80000000);
    (this->mFrameCtrl).mCurrentTime = (float)(local_50 - m_Do_ext::_4289);
  }
  (this->mFrameCtrl).mLoopFrame = (short)(int)(this->mFrameCtrl).mCurrentTime;
  setMorf(this,(float)dVar2);
  if (this->mpAnimeSound != (JAIAnimeSound *)0x0) {
    if ((param_9 == (void *)0x0) && (param_1 != (J3DAnmTransform *)0x0)) {
      param_9 = *(void **)&param_1[1].field_0x10;
    }
    *(void **)this->mpAnimeSound[1].mSlots = param_9;
    this_00 = this->mpAnimeSound;
    if (*(int *)this_00[1].mSlots == 0) {
      JAIAnimeSound::stop(this_00);
    }
    else {
      local_48 = (double)CONCAT44(0x43300000,(int)(this->mFrameCtrl).mLoopFrame ^ 0x80000000);
      if ((this->mFrameCtrl).mSpeed < m_Do_ext::0_0) {
        direction = 0xffffffff;
      }
      else {
        direction = 1;
      }
      JAIAnimeSound::initActorAnimSound
                (this_00,param_9,direction,(float)(local_48 - m_Do_ext::_4289));
    }
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  __psq_l0(auStack40,uVar1);
  __psq_l1(auStack40,uVar1);
  return;
}


/* __thiscall mDoExt_McaMorf2::setMorf(float) */

void __thiscall mDoExt_McaMorf2::setMorf(mDoExt_McaMorf2 *this,float param_1)

{
  if (m_Do_ext::0_0 < param_1) {
    *(float *)&this->field_0x78 = m_Do_ext::0_0;
    *(float *)&this->field_0x80 = m_Do_ext::1_0 / param_1;
  }
  else {
    *(float *)&this->field_0x78 = m_Do_ext::1_0;
  }
  *(undefined4 *)&this->field_0x7c = *(undefined4 *)&this->field_0x78;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall mDoExt_McaMorf2::play(Vec *,
                                    unsigned long,
                                    signed char) */

undefined4 __thiscall
mDoExt_McaMorf2::play(mDoExt_McaMorf2 *this,Vec *param_1,ulong param_2,char param_3)

{
  float target;
  JAIAnimeSound *this_00;
  undefined4 uVar1;
  
  target = m_Do_ext::1_0;
  if (*(float *)&this->field_0x78 < m_Do_ext::1_0) {
    *(float *)&this->field_0x7c = *(float *)&this->field_0x78;
    SComponent::cLib_chaseF((float *)&this->field_0x78,target,*(float *)&this->field_0x80);
  }
  J3DFrameCtrl::update(&this->mFrameCtrl);
  this_00 = this->mpAnimeSound;
  if (((this_00 != (JAIAnimeSound *)0x0) && (*(int *)this_00[1].mSlots != 0)) &&
     (param_1 != (Vec *)0x0)) {
    JAIZelAnime::setAnimSound
              ((JAIZelAnime *)this_00,(cXyz *)param_1,(this->mFrameCtrl).mCurrentTime,
               (this->mFrameCtrl).mSpeed,param_2,param_3);
  }
  uVar1 = 1;
  if ((((this->mFrameCtrl).mFlags & 1) == 0) && (m_Do_ext::0_0 != (this->mFrameCtrl).mSpeed)) {
    uVar1 = 0;
  }
  return uVar1;
}


/* __thiscall mDoExt_McaMorf2::entryDL(void) */

void __thiscall mDoExt_McaMorf2::entryDL(mDoExt_McaMorf2 *this)

{
  if (this->mpModel != (J3DModel *)0x0) {
    m_Do_ext::mDoExt_modelEntryDL(this->mpModel);
  }
  return;
}


/* __thiscall mDoExt_McaMorf2::calc(void) */

void __thiscall mDoExt_McaMorf2::calc(mDoExt_McaMorf2 *this)

{
  mDoExt_McaMorf2 *pmVar1;
  
  if (this->mpModel != (J3DModel *)0x0) {
    if (*(int *)&this->field_0x54 != 0) {
      *(float *)(*(int *)&this->field_0x54 + 8) = (this->mFrameCtrl).mCurrentTime;
    }
    if (*(int *)&this->field_0x58 != 0) {
      *(float *)(*(int *)&this->field_0x58 + 8) = (this->mFrameCtrl).mCurrentTime;
    }
    pmVar1 = this;
    if (this != (mDoExt_McaMorf2 *)0x0) {
      pmVar1 = (mDoExt_McaMorf2 *)(this->parent).vderiv;
    }
    (*(this->mpModel->mpModelData->mJointTree).mpJoints)->mpMtxCalc = (J3DMtxCalc *)pmVar1;
    (*(code *)this->mpModel->vtbl->calc)();
  }
  return;
}


/* __thiscall mDoExt_McaMorf2::stopZelAnime(void) */

void __thiscall mDoExt_McaMorf2::stopZelAnime(mDoExt_McaMorf2 *this)

{
  if (this->mpAnimeSound != (JAIAnimeSound *)0x0) {
    JAIAnimeSound::stop(this->mpAnimeSound);
  }
  return;
}


/* __thiscall mDoExt_offCupOnAupPacket::draw(void) */

void __thiscall mDoExt_offCupOnAupPacket::draw(mDoExt_offCupOnAupPacket *this)

{
  gf::GFSetBlendModeEtc(0,0,0,0,0,1,1);
  return;
}


/* __thiscall mDoExt_onCupOffAupPacket::draw(void) */

void __thiscall mDoExt_onCupOffAupPacket::draw(mDoExt_onCupOffAupPacket *this)

{
  gf::GFSetBlendModeEtc(0,0,0,0,1,0,1);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mDoExt_invJntPacket::draw(void) */

void __thiscall mDoExt_invJntPacket::draw(mDoExt_invJntPacket *this)

{
  J3DModelData *pJVar1;
  J3DMaterial *pJVar2;
  
  gx::GXCallDisplayList(&m_Do_ext::l_invisibleMat_7212,0x80);
  pJVar1 = this->mpModel->mpModelData;
  pJVar2 = (pJVar1->mJointTree).mpJoints[this->mIndex]->mpMaterial;
  _sOldVcdVatCmd = 0;
  J3DShape::loadPreDrawSetting(*(pJVar1->mShapeTable).mpShapes);
  for (; pJVar2 != (J3DMaterial *)0x0; pJVar2 = pJVar2->mpNextMaterial) {
    J3DShapePacket::drawFast(this->mpModel->mpShapePackets + (ushort)pJVar2->mpShape->mShapeIdx);
  }
  _sOldVcdVatCmd = 0;
  gf::GFSetBlendModeEtc(0,0,0,0,1,0,1);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall mDoExt_3Dline_c::init(unsigned short,
                                    int,
                                    int) */

int __thiscall
mDoExt_3Dline_c::init(mDoExt_3Dline_c *this,short numSegments,int param_2,int param_3)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  cXyz *local_r3_48;
  cXyz *pcVar4;
  int iVar5;
  undefined4 uVar6;
  cXy *pcVar7;
  cXy *pcVar8;
  uint uVar9;
  
  uVar9 = (uint)(ushort)numSegments;
  local_r3_48 = (cXyz *)JKernel::operator_new__(uVar9 * 0xc + 0x10);
  pcVar4 = (cXyz *)Runtime.PPCEABI.H::__construct_new_array
                             (local_r3_48,::cXyz::cXyz,::cXyz::_cXyz,0xc,uVar9);
  this->mpSegments = pcVar4;
  if (this->mpSegments == (cXyz *)0x0) {
    iVar5 = 0;
  }
  else {
    if (param_2 == 0) {
      *(undefined4 *)&this->field_0x4 = 0;
    }
    else {
      uVar6 = JKernel::operator_new__(uVar9);
      *(undefined4 *)&this->field_0x4 = uVar6;
      if (*(int *)&this->field_0x4 == 0) {
        return 0;
      }
    }
    uVar9 = (uint)(ushort)numSegments;
    uVar1 = (uint)(ushort)numSegments;
    uVar6 = JKernel::operator_new__(uVar1 * 0x18 + 0x10);
    pcVar4 = (cXyz *)Runtime.PPCEABI.H::__construct_new_array
                               (uVar6,::cXyz::cXyz,::cXyz::_cXyz,0xc,uVar1 * 2);
    this->mPosArr[0] = pcVar4;
    if (this->mPosArr[0] == (cXyz *)0x0) {
      iVar5 = 0;
    }
    else {
      uVar6 = JKernel::operator_new__(uVar1 * 0x18 + 0x10);
      pcVar4 = (cXyz *)Runtime.PPCEABI.H::__construct_new_array
                                 (uVar6,::cXyz::cXyz,::cXyz::_cXyz,0xc,uVar1 * 2);
      this->mPosArr[1] = pcVar4;
      if (this->mPosArr[1] == (cXyz *)0x0) {
        iVar5 = 0;
      }
      else {
        if (param_3 != 0) {
          pcVar7 = (cXy *)JKernel::operator_new__(uVar1 << 4);
          this->mTexArr[0] = pcVar7;
          if (this->mTexArr[0] == (cXy *)0x0) {
            return 0;
          }
          pcVar7 = (cXy *)JKernel::operator_new__(uVar1 << 4);
          this->mTexArr[1] = pcVar7;
          fVar3 = m_Do_ext::0_0;
          fVar2 = m_Do_ext::1_0;
          pcVar7 = this->mTexArr[1];
          if (pcVar7 == (cXy *)0x0) {
            return 0;
          }
          pcVar8 = this->mTexArr[0];
          if (numSegments != 0) {
            do {
              pcVar8->x = fVar3;
              pcVar7->x = fVar3;
              pcVar8[1].x = fVar2;
              pcVar7[1].x = fVar2;
              pcVar8 = pcVar8 + 2;
              pcVar7 = pcVar7 + 2;
              uVar9 = uVar9 - 1;
            } while (uVar9 != 0);
          }
        }
        iVar5 = 1;
      }
    }
  }
  return iVar5;
}


/* __thiscall cXyz::cXyz(void) */

void __thiscall cXyz::cXyz(cXyz *this)

{
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall mDoExt_3DlineMat0_c::init(unsigned short,
                                        unsigned short,
                                        int) */

int __thiscall
mDoExt_3DlineMat0_c::init
          (mDoExt_3DlineMat0_c *this,ushort numLines,ushort numSegmentsPerLine,int param_3)

{
  undefined4 uVar1;
  mDoExt_3Dline_c *lines;
  int iVar2;
  int iVar3;
  int iVar4;
  
  this->mNumLines = numLines;
  this->mNumSegmentsPerLine = numSegmentsPerLine;
  uVar1 = JKernel::operator_new__((uint)numLines * 0x18 + 0x10);
  lines = (mDoExt_3Dline_c *)
          Runtime.PPCEABI.H::__construct_new_array
                    (uVar1,mDoExt_3Dline_c::mDoExt_3Dline_c,mDoExt_3Dline_c::_mDoExt_3Dline_c,0x18,
                     (uint)numLines);
  this->mpLines = lines;
  if (this->mpLines == (mDoExt_3Dline_c *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar4 = 0;
    for (iVar2 = 0; iVar2 < (int)(uint)numLines; iVar2 = iVar2 + 1) {
      iVar3 = mDoExt_3Dline_c::init
                        ((mDoExt_3Dline_c *)((int)this->mpLines->mPosArr + iVar4 + -8),
                         numSegmentsPerLine,param_3,0);
      if (iVar3 == 0) {
        return 0;
      }
      iVar4 = iVar4 + 0x18;
    }
    *(undefined4 *)&(this->parent).field_0x4 = 0;
    this->field_0x16 = 0;
    iVar2 = 1;
  }
  return iVar2;
}


/* __thiscall mDoExt_3Dline_c::~mDoExt_3Dline_c(void) */

void __thiscall mDoExt_3Dline_c::_mDoExt_3Dline_c(mDoExt_3Dline_c *this)

{
  short in_r4;
  
  if ((this != (mDoExt_3Dline_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall mDoExt_3Dline_c::mDoExt_3Dline_c(void) */

void __thiscall mDoExt_3Dline_c::mDoExt_3Dline_c(mDoExt_3Dline_c *this)

{
  return;
}


/* __thiscall mDoExt_3DlineMat0_c::setMaterial(void) */

void __thiscall mDoExt_3DlineMat0_c::setMaterial(mDoExt_3DlineMat0_c *this)

{
  J3DSys::reinitGX(&J3DGraphBase::j3dSys);
  gx::GXSetNumIndStages(0);
  d_kankyo::dKy_setLight_again();
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX16);
  gx::GXSetVtxDesc(GX_VA_NRM,GX_INDEX8);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_NRM,GX_CLR_RGB,GX_RGB8,6);
  gx::GXSetArray(GX_VA_NRM,&m_Do_ext::l_normal_7302,3);
  if (this->field_0xc == (dKy_tevstr_c *)0x0) {
    d_kankyo::dKy_GxFog_set();
    gx::GXCallDisplayList(&m_Do_ext::l_matDL,0x80);
  }
  else {
    d_kankyo::dKy_GxFog_tevstr_set(this->field_0xc);
    gx::GXCallDisplayList(&m_Do_ext::l_toonMatDL,0x80);
  }
  gx::GXLoadPosMtxImm(&J3DGraphBase::j3dSys.mCurViewMtx,0);
  gx::GXLoadNrmMtxImm(&m_Do_mtx::g_mDoMtx_identity,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall mDoExt_3DlineMat0_c::draw(void) */

void __thiscall mDoExt_3DlineMat0_c::draw(mDoExt_3DlineMat0_c *this)

{
  uint uVar1;
  dKy_tevstr_c *pdVar2;
  ushort uVar3;
  int lineIndex;
  mDoExt_3Dline_c *line;
  _GXColor local_28;
  _GXColor local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_24 = this->mColor;
  gx::GXSetTevColor(GX_TEVREG2,&local_24);
  pdVar2 = this->field_0xc;
  if (pdVar2 != (dKy_tevstr_c *)0x0) {
    local_20 = *(undefined4 *)&pdVar2->mColorC0;
    local_1c = *(undefined4 *)&(pdVar2->mColorC0).b;
    gx::GXSetTevColorS10(GX_TEVREG0,(_GXColorS10 *)&local_20);
    local_28 = this->field_0xc->mColorK0;
    gx::GXSetTevColor(GX_TEVREG1,&local_28);
  }
  line = this->mpLines;
  uVar1 = (this->field_0x14 & 0x7fff) << 1;
  for (lineIndex = 0; lineIndex < (int)(uint)(ushort)this->mNumLines; lineIndex = lineIndex + 1) {
    gx::GXSetArray(GX_VA_POS,line->mPosArr[this->field_0x16],0xc);
    gx::GXBegin(0x98,0,uVar1);
    for (uVar3 = 0; uVar3 < uVar1; uVar3 = uVar3 + 2) {
      write_volatile_2(0xcc008000,uVar3);
      write_volatile_1(DAT_cc008000,0);
      write_volatile_2(0xcc008000,uVar3 + 1);
      write_volatile_1(DAT_cc008000,1);
    }
    line = line + 1;
  }
  this->field_0x16 = this->field_0x16 ^ 1;
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x80014ddc) */
/* WARNING: Removing unreachable block (ram,0x80014dcc) */
/* WARNING: Removing unreachable block (ram,0x80014dd4) */
/* WARNING: Removing unreachable block (ram,0x80014de4) */
/* __thiscall mDoExt_3DlineMat0_c::update(unsigned short,
                                          float,
                                          _GXColor &,
                                          unsigned short,
                                          dKy_tevstr_c *) */

void __thiscall
mDoExt_3DlineMat0_c::update
          (mDoExt_3DlineMat0_c *this,ushort param_1,float param_2,_GXColor *color,ushort param_4,
          dKy_tevstr_c *param_5)

{
  ushort uVar1;
  cXyz *pcVar2;
  int iVar3;
  int lineIndex;
  cXyz *pcVar4;
  cXyz *pcVar5;
  cXyz *segment;
  mDoExt_3Dline_c *line;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar10;
  undefined8 in_f30;
  double dVar11;
  undefined8 in_f31;
  double dVar12;
  float fVar13;
  cXyz local_160;
  cXyz local_154;
  cXyz local_148;
  cXyz local_13c;
  cXyz cStack304;
  cXyz cStack292;
  cXyz local_118;
  cXyz local_10c;
  cXyz local_100;
  cXyz local_f4;
  cXyz local_e8;
  cXyz local_dc;
  cXyz local_d0;
  cXyz local_c4;
  cXyz local_b8;
  cXyz local_ac;
  cXyz local_a0;
  cXyz local_94;
  cXyz local_88;
  cXyz local_7c;
  undefined4 local_70;
  uint uStack108;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  camera_class *camera;
  
  dVar8 = (double)param_2;
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  (this->mColor).r = color->r;
  (this->mColor).g = color->g;
  (this->mColor).b = color->b;
  (this->mColor).a = color->a;
  this->field_0xc = param_5;
  this->field_0x14 = param_1;
  if ((ushort)this->mNumSegmentsPerLine < this->field_0x14) {
    this->field_0x14 = this->mNumSegmentsPerLine;
  }
  camera = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera;
  line = this->mpLines;
  fVar13 = m_Do_ext::0_0;
  if (param_4 != 0) {
    local_70 = 0x43300000;
    fVar13 = (float)(dVar8 / (double)(float)((double)CONCAT44(0x43300000,(uint)param_4) -
                                            m_Do_ext::_7564));
    uStack108 = (uint)param_4;
  }
  dVar11 = (double)fVar13;
  uVar1 = this->field_0x14;
  dVar12 = (double)m_Do_ext::0_0;
  for (lineIndex = 0; lineIndex < (int)(uint)(ushort)this->mNumLines; lineIndex = lineIndex + 1) {
    segment = line->mpSegments;
    pcVar4 = line->mPosArr[this->field_0x16];
    dVar10 = dVar8;
    ::cXyz::operator__(&local_ac,segment + 1,segment);
    local_88.x = local_ac.x;
    local_88.y = local_ac.y;
    local_88.z = local_ac.z;
    ::cXyz::operator__(&local_b8,segment,&camera->mEyePos);
    local_7c.x = local_b8.x;
    local_7c.y = local_b8.y;
    local_7c.z = local_b8.z;
    ::cXyz::outprod(&local_c4,&local_88,&local_7c);
    local_88.x = local_c4.x;
    local_88.y = local_c4.y;
    local_88.z = local_c4.z;
    fVar13 = mtx::PSVECSquareMag(&local_88);
    dVar9 = (double)fVar13;
    if (dVar12 < dVar9) {
      dVar7 = 1.0 / SQRT(dVar9);
      dVar7 = m_Do_ext::_7560 * dVar7 * (m_Do_ext::_7561 - dVar9 * dVar7 * dVar7);
      dVar7 = m_Do_ext::_7560 * dVar7 * (m_Do_ext::_7561 - dVar9 * dVar7 * dVar7);
      dVar9 = (double)(float)(dVar9 * m_Do_ext::_7560 * dVar7 *
                                      (m_Do_ext::_7561 - dVar9 * dVar7 * dVar7));
    }
    if (dVar12 != dVar9) {
      mtx::PSVECScale(&local_88,&local_88,(float)(dVar8 / dVar9));
    }
    ::cXyz::operator__(&local_d0,segment,&local_88);
    pcVar4->x = local_d0.x;
    pcVar4->y = local_d0.y;
    pcVar4->z = local_d0.z;
    ::cXyz::operator__(&local_dc,segment,&local_88);
    pcVar4[1].x = local_dc.x;
    pcVar4[1].y = local_dc.y;
    pcVar4[1].z = local_dc.z;
    segment = segment + 1;
    ::cXyz::operator__(&local_e8,segment,&local_88);
    local_94.x = local_e8.x;
    local_94.y = local_e8.y;
    local_94.z = local_e8.z;
    ::cXyz::operator__(&local_f4,segment,&local_88);
    local_a0.x = local_f4.x;
    local_a0.y = local_f4.y;
    local_a0.z = local_f4.z;
    pcVar2 = pcVar4;
    for (iVar3 = this->field_0x14 - 2; pcVar5 = pcVar2 + 2, 0 < iVar3; iVar3 = iVar3 + -1) {
      if (iVar3 < (int)(uint)param_4) {
        dVar10 = (double)(float)(dVar10 - dVar11);
      }
      ::cXyz::operator__(&local_100,segment + 1,segment);
      local_88.x = local_100.x;
      local_88.y = local_100.y;
      local_88.z = local_100.z;
      ::cXyz::operator__(&local_10c,segment,&camera->mEyePos);
      local_7c.x = local_10c.x;
      local_7c.y = local_10c.y;
      local_7c.z = local_10c.z;
      ::cXyz::outprod(&local_118,&local_88,&local_7c);
      local_88.x = local_118.x;
      local_88.y = local_118.y;
      local_88.z = local_118.z;
      fVar13 = mtx::PSVECSquareMag(&local_88);
      dVar9 = (double)fVar13;
      if (dVar12 < dVar9) {
        dVar7 = 1.0 / SQRT(dVar9);
        dVar7 = m_Do_ext::_7560 * dVar7 * (m_Do_ext::_7561 - dVar9 * dVar7 * dVar7);
        dVar7 = m_Do_ext::_7560 * dVar7 * (m_Do_ext::_7561 - dVar9 * dVar7 * dVar7);
        dVar9 = (double)(float)(dVar9 * m_Do_ext::_7560 * dVar7 *
                                        (m_Do_ext::_7561 - dVar9 * dVar7 * dVar7));
      }
      if (dVar12 != dVar9) {
        dVar9 = (double)(float)(dVar10 / dVar9);
      }
      mtx::PSVECScale(&local_88,&local_88,(float)dVar9);
      ::cXyz::operator__(&cStack292,segment,&local_88);
      mtx::PSVECAdd(&local_94,&cStack292,&local_94);
      ::cXyz::operator__(&cStack304,segment,&local_88);
      mtx::PSVECAdd(&local_a0,&cStack304,&local_a0);
      ::cXyz::operator_(&local_13c,&local_94,m_Do_ext::_7562);
      pcVar5->x = local_13c.x;
      pcVar2[2].y = local_13c.y;
      pcVar2[2].z = local_13c.z;
      ::cXyz::operator_(&local_148,&local_a0,m_Do_ext::_7562);
      pcVar2[3].x = local_148.x;
      pcVar2[3].y = local_148.y;
      pcVar2[3].z = local_148.z;
      segment = segment + 1;
      ::cXyz::operator__(&local_154,segment,&local_88);
      local_94.x = local_154.x;
      local_94.y = local_154.y;
      local_94.z = local_154.z;
      ::cXyz::operator__(&local_160,segment,&local_88);
      local_a0.x = local_160.x;
      local_a0.y = local_160.y;
      local_a0.z = local_160.z;
      pcVar2 = pcVar5;
    }
    if (param_4 == 0) {
      pcVar5->x = local_94.x;
      pcVar2[2].y = local_94.y;
      pcVar2[2].z = local_94.z;
      pcVar2[3].x = local_a0.x;
      pcVar2[3].y = local_a0.y;
      pcVar2[3].z = local_a0.z;
    }
    else {
      pcVar5->x = segment->x;
      pcVar2[2].y = segment->y;
      pcVar2[2].z = segment->z;
      pcVar2[3].x = segment->x;
      pcVar2[3].y = segment->y;
      pcVar2[3].z = segment->z;
    }
    os::DCStoreRangeNoSync(pcVar4,(uint)uVar1 * 0x18);
    line = line + 1;
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  __psq_l0(auStack40,uVar6);
  __psq_l1(auStack40,uVar6);
  __psq_l0(auStack56,uVar6);
  __psq_l1(auStack56,uVar6);
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x80015308) */
/* __thiscall mDoExt_3DlineMat0_c::update(unsigned short,
                                          _GXColor &,
                                          dKy_tevstr_c *) */

void __thiscall
mDoExt_3DlineMat0_c::update
          (mDoExt_3DlineMat0_c *this,ushort param_1,_GXColor *param_2,dKy_tevstr_c *param_3)

{
  ushort uVar1;
  cXyz *pcVar2;
  camera_class *pcVar3;
  ulong uVar4;
  int iVar5;
  cXyz *pcVar6;
  cXyz *pcVar7;
  int iVar8;
  byte *pbVar9;
  cXyz *pcVar10;
  mDoExt_3Dline_c *pmVar11;
  undefined4 uVar12;
  double dVar13;
  double dVar14;
  undefined8 in_f31;
  double dVar15;
  float fVar16;
  cXyz local_130;
  cXyz local_124;
  cXyz local_118;
  cXyz local_10c;
  cXyz cStack256;
  cXyz cStack244;
  cXyz local_e8;
  cXyz local_dc;
  cXyz local_d0;
  cXyz local_c4;
  cXyz local_b8;
  cXyz local_ac;
  cXyz local_a0;
  cXyz local_94;
  cXyz local_88;
  cXyz local_7c;
  cXyz local_70;
  cXyz local_64;
  cXyz local_58;
  cXyz local_4c;
  undefined4 local_40;
  uint uStack60;
  undefined auStack8 [8];
  
  uVar12 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  (this->mColor).r = param_2->r;
  (this->mColor).g = param_2->g;
  (this->mColor).b = param_2->b;
  (this->mColor).a = param_2->a;
  this->field_0xc = param_3;
  this->field_0x14 = param_1;
  if ((ushort)this->mNumSegmentsPerLine < this->field_0x14) {
    this->field_0x14 = this->mNumSegmentsPerLine;
  }
  pcVar3 = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera;
  pmVar11 = this->mpLines;
  uVar1 = this->field_0x14;
  dVar15 = (double)m_Do_ext::0_0;
  for (iVar8 = 0; iVar8 < (int)(uint)(ushort)this->mNumLines; iVar8 = iVar8 + 1) {
    pcVar10 = pmVar11->mpSegments;
    pbVar9 = *(byte **)&pmVar11->field_0x4;
    if (pbVar9 == (byte *)0x0) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar4,"m_Do_ext.cpp",0x1282,"size_p != 0");
      m_Do_printf::OSPanic("m_Do_ext.cpp",0x1282,"Halt");
    }
    pcVar6 = pmVar11->mPosArr[this->field_0x16];
    ::cXyz::operator__(&local_7c,pcVar10 + 1,pcVar10);
    local_58.x = local_7c.x;
    local_58.y = local_7c.y;
    local_58.z = local_7c.z;
    ::cXyz::operator__(&local_88,pcVar10,&pcVar3->mEyePos);
    local_4c.x = local_88.x;
    local_4c.y = local_88.y;
    local_4c.z = local_88.z;
    ::cXyz::outprod(&local_94,&local_58,&local_4c);
    local_58.x = local_94.x;
    local_58.y = local_94.y;
    local_58.z = local_94.z;
    fVar16 = mtx::PSVECSquareMag(&local_58);
    dVar14 = (double)fVar16;
    if (dVar15 < dVar14) {
      dVar13 = 1.0 / SQRT(dVar14);
      dVar13 = m_Do_ext::_7560 * dVar13 * (m_Do_ext::_7561 - dVar14 * dVar13 * dVar13);
      dVar13 = m_Do_ext::_7560 * dVar13 * (m_Do_ext::_7561 - dVar14 * dVar13 * dVar13);
      dVar14 = (double)(float)(dVar14 * m_Do_ext::_7560 * dVar13 *
                                        (m_Do_ext::_7561 - dVar14 * dVar13 * dVar13));
    }
    if (dVar15 != dVar14) {
      uStack60 = (uint)*pbVar9;
      local_40 = 0x43300000;
      mtx::PSVECScale(&local_58,&local_58,
                      (float)((double)(float)((double)CONCAT44(0x43300000,uStack60) -
                                             m_Do_ext::_7564) / dVar14));
    }
    ::cXyz::operator__(&local_a0,pcVar10,&local_58);
    pcVar6->x = local_a0.x;
    pcVar6->y = local_a0.y;
    pcVar6->z = local_a0.z;
    ::cXyz::operator__(&local_ac,pcVar10,&local_58);
    pcVar6[1].x = local_ac.x;
    pcVar6[1].y = local_ac.y;
    pcVar6[1].z = local_ac.z;
    pcVar10 = pcVar10 + 1;
    ::cXyz::operator__(&local_b8,pcVar10,&local_58);
    local_64.x = local_b8.x;
    local_64.y = local_b8.y;
    local_64.z = local_b8.z;
    ::cXyz::operator__(&local_c4,pcVar10,&local_58);
    local_70.x = local_c4.x;
    local_70.y = local_c4.y;
    local_70.z = local_c4.z;
    iVar5 = this->field_0x14 - 2;
    pcVar2 = pcVar6;
    while( true ) {
      pbVar9 = pbVar9 + 1;
      pcVar7 = pcVar2 + 2;
      if (iVar5 < 1) break;
      ::cXyz::operator__(&local_d0,pcVar10 + 1,pcVar10);
      local_58.x = local_d0.x;
      local_58.y = local_d0.y;
      local_58.z = local_d0.z;
      ::cXyz::operator__(&local_dc,pcVar10,&pcVar3->mEyePos);
      local_4c.x = local_dc.x;
      local_4c.y = local_dc.y;
      local_4c.z = local_dc.z;
      ::cXyz::outprod(&local_e8,&local_58,&local_4c);
      local_58.x = local_e8.x;
      local_58.y = local_e8.y;
      local_58.z = local_e8.z;
      fVar16 = mtx::PSVECSquareMag(&local_58);
      dVar14 = (double)fVar16;
      if (dVar15 < dVar14) {
        dVar13 = 1.0 / SQRT(dVar14);
        dVar13 = m_Do_ext::_7560 * dVar13 * (m_Do_ext::_7561 - dVar14 * dVar13 * dVar13);
        dVar13 = m_Do_ext::_7560 * dVar13 * (m_Do_ext::_7561 - dVar14 * dVar13 * dVar13);
        dVar14 = (double)(float)(dVar14 * m_Do_ext::_7560 * dVar13 *
                                          (m_Do_ext::_7561 - dVar14 * dVar13 * dVar13));
      }
      if (dVar15 != dVar14) {
        uStack60 = (uint)*pbVar9;
        local_40 = 0x43300000;
        dVar14 = (double)(float)((double)(float)((double)CONCAT44(0x43300000,uStack60) -
                                                m_Do_ext::_7564) / dVar14);
      }
      mtx::PSVECScale(&local_58,&local_58,(float)dVar14);
      ::cXyz::operator__(&cStack244,pcVar10,&local_58);
      mtx::PSVECAdd(&local_64,&cStack244,&local_64);
      ::cXyz::operator__(&cStack256,pcVar10,&local_58);
      mtx::PSVECAdd(&local_70,&cStack256,&local_70);
      ::cXyz::operator_(&local_10c,&local_64,m_Do_ext::_7562);
      pcVar7->x = local_10c.x;
      pcVar2[2].y = local_10c.y;
      pcVar2[2].z = local_10c.z;
      ::cXyz::operator_(&local_118,&local_70,m_Do_ext::_7562);
      pcVar2[3].x = local_118.x;
      pcVar2[3].y = local_118.y;
      pcVar2[3].z = local_118.z;
      pcVar10 = pcVar10 + 1;
      ::cXyz::operator__(&local_124,pcVar10,&local_58);
      local_64.x = local_124.x;
      local_64.y = local_124.y;
      local_64.z = local_124.z;
      ::cXyz::operator__(&local_130,pcVar10,&local_58);
      local_70.x = local_130.x;
      local_70.y = local_130.y;
      local_70.z = local_130.z;
      iVar5 = iVar5 + -1;
      pcVar2 = pcVar7;
    }
    pcVar7->x = local_64.x;
    pcVar2[2].y = local_64.y;
    pcVar2[2].z = local_64.z;
    pcVar2[3].x = local_70.x;
    pcVar2[3].y = local_70.y;
    pcVar2[3].z = local_70.z;
    os::DCStoreRangeNoSync(pcVar6,(uint)uVar1 * 0x18);
    pmVar11 = pmVar11 + 1;
  }
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall mDoExt_3DlineMat1_c::init(unsigned short,
                                        unsigned short,
                                        ResTIMG *,
                                        int) */

int __thiscall
mDoExt_3DlineMat1_c::init
          (mDoExt_3DlineMat1_c *this,ushort numLines,ushort numSegments,ResTIMG *pImg,int param_4)

{
  undefined4 uVar1;
  mDoExt_3Dline_c *pmVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  this->mNumLines = numLines;
  this->field_0x32 = numSegments;
  uVar1 = JKernel::operator_new__((uint)numLines * 0x18 + 0x10);
  pmVar2 = (mDoExt_3Dline_c *)
           Runtime.PPCEABI.H::__construct_new_array
                     (uVar1,mDoExt_3Dline_c::mDoExt_3Dline_c,mDoExt_3Dline_c::_mDoExt_3Dline_c,0x18,
                      (uint)numLines);
  this->mpLines = pmVar2;
  if (this->mpLines == (mDoExt_3Dline_c *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar5 = 0;
    for (iVar3 = 0; iVar3 < (int)(uint)numLines; iVar3 = iVar3 + 1) {
      iVar4 = mDoExt_3Dline_c::init
                        ((mDoExt_3Dline_c *)((int)this->mpLines->mPosArr + iVar5 + -8),numSegments,
                         param_4,1);
      if (iVar4 == 0) {
        return 0;
      }
      iVar5 = iVar5 + 0x18;
    }
    *(undefined4 *)&(this->parent).field_0x4 = 0;
    this->mCurArr = 0;
    gx::GXInitTexObj((GXTexObj *)&this->mTexObj,&pImg->mTexFmt + pImg->mTexDataOffs,
                     (uint)pImg->mWidth,(uint)pImg->mHeight,pImg->mTexFmt,pImg->mWrapS,pImg->mWrapT,
                     SUB41(1 - (uint)pImg->mMipmapCount >> 0x1f,0));
    gx::GXInitTexObjLOD((double)(m_Do_ext::0_125 *
                                (float)((double)CONCAT44(0x43300000,
                                                         (int)(char)pImg->mMinLOD ^ 0x80000000) -
                                       m_Do_ext::_4289)),
                        (double)(m_Do_ext::0_125 *
                                (float)((double)CONCAT44(0x43300000,
                                                         (int)(char)pImg->mMaxLOD ^ 0x80000000) -
                                       m_Do_ext::_4289)),
                        (double)(m_Do_ext::0_01 *
                                (float)((double)CONCAT44(0x43300000,(int)pImg->mLODBias ^ 0x80000000
                                                        ) - m_Do_ext::_4289)),&this->mTexObj,
                        pImg->mMinFilter,pImg->mMagFilter,pImg->mbBiasClamp,pImg->mbDoEdgeLOD,
                        pImg->mMaxAniso);
    iVar3 = 1;
  }
  return iVar3;
}


/* __thiscall mDoExt_3DlineMat1_c::setMaterial(void) */

void __thiscall mDoExt_3DlineMat1_c::setMaterial(mDoExt_3DlineMat1_c *this)

{
  J3DSys::reinitGX(&J3DGraphBase::j3dSys);
  gx::GXSetNumIndStages(0);
  d_kankyo::dKy_setLight_again();
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX16);
  gx::GXSetVtxDesc(GX_VA_NRM,GX_INDEX8);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_INDEX16);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_NRM,GX_CLR_RGB,GX_RGB8,6);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,0);
  gx::GXSetArray(GX_VA_NRM,m_Do_ext::l_normal_7801,3);
  if (this->mpTevStr == (dKy_tevstr_c *)0x0) {
    d_kankyo::dKy_GxFog_set();
    gx::GXCallDisplayList(&m_Do_ext::l_mat1DL,0x80);
  }
  else {
    d_kankyo::dKy_GxFog_tevstr_set(this->mpTevStr);
    gx::GXCallDisplayList(&m_Do_ext::l_toonMat1DL,0xa0);
  }
  gx::GXLoadPosMtxImm(&J3DGraphBase::j3dSys.mCurViewMtx,0);
  gx::GXLoadNrmMtxImm(&m_Do_mtx::g_mDoMtx_identity,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall mDoExt_3DlineMat1_c::draw(void) */

void __thiscall mDoExt_3DlineMat1_c::draw(mDoExt_3DlineMat1_c *this)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  dKy_tevstr_c *pdVar4;
  ushort uVar5;
  int iVar6;
  mDoExt_3Dline_c *pmVar7;
  _GXColor local_28;
  _GXColor local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  gx::GXLoadTexObj((GXTexObj *)&this->mTexObj,0);
  uVar2 = gx::GXGetTexObjHeight(&this->mTexObj);
  uVar3 = gx::GXGetTexObjWidth(&this->mTexObj);
  gx::GXSetTexCoordScaleManually(0,1,uVar3,uVar2);
  local_24 = this->mColor;
  gx::GXSetTevColor(GX_TEVREG2,&local_24);
  pdVar4 = this->mpTevStr;
  if (pdVar4 != (dKy_tevstr_c *)0x0) {
    local_20 = *(undefined4 *)&pdVar4->mColorC0;
    local_1c = *(undefined4 *)&(pdVar4->mColorC0).b;
    gx::GXSetTevColorS10(GX_TEVREG0,(_GXColorS10 *)&local_20);
    local_28 = this->mpTevStr->mColorK0;
    gx::GXSetTevColor(GX_TEVREG1,&local_28);
  }
  pmVar7 = this->mpLines;
  uVar1 = (this->field_0x34 & 0x7fff) << 1;
  for (iVar6 = 0; iVar6 < (int)(uint)this->mNumLines; iVar6 = iVar6 + 1) {
    gx::GXSetArray(GX_VA_POS,pmVar7->mPosArr[this->mCurArr],0xc);
    gx::GXSetArray(GX_VA_TEX0,pmVar7->mTexArr[this->mCurArr],8);
    gx::GXBegin(0x98,0,uVar1);
    for (uVar5 = 0; uVar5 < uVar1; uVar5 = uVar5 + 2) {
      write_volatile_2(0xcc008000,uVar5);
      write_volatile_1(DAT_cc008000,0);
      write_volatile_2(0xcc008000,uVar5);
      write_volatile_2(0xcc008000,uVar5 + 1);
      write_volatile_1(DAT_cc008000,1);
      write_volatile_2(0xcc008000,uVar5 + 1);
    }
    pmVar7 = pmVar7 + 1;
  }
  gx::GXSetTexCoordScaleManually(0,0,0,0);
  this->mCurArr = this->mCurArr ^ 1;
  return;
}


/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* WARNING: Removing unreachable block (ram,0x80015e2c) */
/* WARNING: Removing unreachable block (ram,0x80015e1c) */
/* WARNING: Removing unreachable block (ram,0x80015e0c) */
/* WARNING: Removing unreachable block (ram,0x80015dfc) */
/* WARNING: Removing unreachable block (ram,0x80015dec) */
/* WARNING: Removing unreachable block (ram,0x80015de4) */
/* WARNING: Removing unreachable block (ram,0x80015df4) */
/* WARNING: Removing unreachable block (ram,0x80015e04) */
/* WARNING: Removing unreachable block (ram,0x80015e14) */
/* WARNING: Removing unreachable block (ram,0x80015e24) */
/* WARNING: Removing unreachable block (ram,0x80015e34) */
/* __thiscall mDoExt_3DlineMat1_c::update(unsigned short,
                                          float,
                                          _GXColor &,
                                          unsigned short,
                                          dKy_tevstr_c *) */

void __thiscall
mDoExt_3DlineMat1_c::update
          (mDoExt_3DlineMat1_c *this,ushort param_1,float param_2,_GXColor *param_3,ushort param_4,
          dKy_tevstr_c *param_5)

{
  ushort uVar1;
  cXyz *pcVar2;
  cXyz *pcVar3;
  camera_class *pcVar4;
  int iVar5;
  int iVar6;
  cXyz *pcVar7;
  cXyz *pcVar8;
  cXyz *pcVar9;
  mDoExt_3Dline_c *local_r25_296;
  cXyz *this_00;
  mDoExt_3Dline_c *pmVar10;
  undefined4 uVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  undefined8 in_f21;
  undefined8 in_f22;
  double dVar15;
  undefined8 in_f23;
  double dVar16;
  undefined8 in_f24;
  double dVar17;
  undefined8 in_f25;
  double dVar18;
  undefined8 in_f26;
  double dVar19;
  undefined8 in_f27;
  double dVar20;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar21;
  double dVar22;
  undefined8 in_f30;
  double dVar23;
  undefined8 in_f31;
  double dVar24;
  float fVar25;
  cXyz local_1e8;
  cXyz local_1dc;
  cXyz local_1d0;
  cXyz local_1c4;
  cXyz cStack440;
  cXyz cStack428;
  cXyz local_1a0;
  cXyz local_194;
  cXyz local_188;
  cXyz local_17c;
  cXyz local_170;
  cXyz local_164;
  cXyz local_158;
  cXyz local_14c;
  cXyz local_140;
  cXyz local_134;
  cXyz local_128;
  cXyz local_11c;
  cXyz local_110;
  cXyz local_104;
  undefined4 local_f8;
  uint uStack244;
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar13 = (double)param_2;
  uVar11 = 0;
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
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  (this->mColor).r = param_3->r;
  (this->mColor).g = param_3->g;
  (this->mColor).b = param_3->b;
  (this->mColor).a = param_3->a;
  this->mpTevStr = param_5;
  this->field_0x34 = param_1;
  if (this->field_0x32 < this->field_0x34) {
    this->field_0x34 = this->field_0x32;
  }
  pcVar4 = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera;
  pmVar10 = this->mpLines;
  fVar25 = m_Do_ext::0_0;
  if (param_4 != 0) {
    local_f8 = 0x43300000;
    fVar25 = (float)(dVar13 / (double)(float)((double)CONCAT44(0x43300000,(uint)param_4) -
                                             m_Do_ext::_7564));
    uStack244 = (uint)param_4;
  }
  dVar24 = (double)fVar25;
  uVar1 = this->field_0x34;
  dVar21 = (double)m_Do_ext::0_0;
  dVar20 = (double)m_Do_ext::0_1;
  dVar15 = dVar21;
  dVar16 = dVar21;
  dVar17 = dVar21;
  dVar18 = dVar21;
  dVar19 = dVar21;
  dVar22 = dVar21;
  for (iVar6 = 0; iVar6 < (int)(uint)this->mNumLines; iVar6 = iVar6 + 1) {
    local_r25_296 = (mDoExt_3Dline_c *)pmVar10->mpSegments;
    pcVar8 = (pmVar10->mPosArr + (this->mCurArr - 2))[2];
    pcVar7 = (pmVar10->mPosArr + (this->mCurArr - 2))[4];
    pcVar7->y = (float)dVar22;
    pcVar7[1].x = (float)dVar22;
    dVar23 = dVar13;
    ::cXyz::operator__(&local_134,(cXyz *)(local_r25_296->mPosArr + 1),(cXyz *)local_r25_296);
    local_110.x = local_134.x;
    local_110.y = local_134.y;
    local_110.z = local_134.z;
    fVar25 = mtx::PSVECSquareMag(&local_110);
    dVar14 = (double)fVar25;
    if (dVar19 < dVar14) {
      dVar12 = 1.0 / SQRT(dVar14);
      dVar12 = m_Do_ext::_7560 * dVar12 * (m_Do_ext::_7561 - dVar14 * dVar12 * dVar12);
      dVar12 = m_Do_ext::_7560 * dVar12 * (m_Do_ext::_7561 - dVar14 * dVar12 * dVar12);
      dVar14 = (double)(float)(dVar14 * m_Do_ext::_7560 * dVar12 *
                                        (m_Do_ext::_7561 - dVar14 * dVar12 * dVar12));
    }
    dVar22 = (double)(float)(dVar22 + (double)(float)(dVar20 * dVar14));
    ::cXyz::operator__(&local_140,(cXyz *)local_r25_296,&pcVar4->mEyePos);
    local_104.x = local_140.x;
    local_104.y = local_140.y;
    local_104.z = local_140.z;
    ::cXyz::outprod(&local_14c,&local_110,&local_104);
    local_110.x = local_14c.x;
    local_110.y = local_14c.y;
    local_110.z = local_14c.z;
    fVar25 = mtx::PSVECSquareMag(&local_110);
    dVar14 = (double)fVar25;
    if (dVar18 < dVar14) {
      dVar12 = 1.0 / SQRT(dVar14);
      dVar12 = m_Do_ext::_7560 * dVar12 * (m_Do_ext::_7561 - dVar14 * dVar12 * dVar12);
      dVar12 = m_Do_ext::_7560 * dVar12 * (m_Do_ext::_7561 - dVar14 * dVar12 * dVar12);
      dVar14 = (double)(float)(dVar14 * m_Do_ext::_7560 * dVar12 *
                                        (m_Do_ext::_7561 - dVar14 * dVar12 * dVar12));
    }
    if (dVar17 != dVar14) {
      mtx::PSVECScale(&local_110,&local_110,(float)(dVar13 / dVar14));
    }
    ::cXyz::operator__(&local_158,(cXyz *)local_r25_296,&local_110);
    pcVar8->x = local_158.x;
    pcVar8->y = local_158.y;
    pcVar8->z = local_158.z;
    ::cXyz::operator__(&local_164,(cXyz *)local_r25_296,&local_110);
    pcVar8[1].x = local_164.x;
    pcVar8[1].y = local_164.y;
    pcVar8[1].z = local_164.z;
    this_00 = (cXyz *)(local_r25_296->mPosArr + 1);
    ::cXyz::operator__(&local_170,this_00,&local_110);
    local_11c.x = local_170.x;
    local_11c.y = local_170.y;
    local_11c.z = local_170.z;
    ::cXyz::operator__(&local_17c,this_00,&local_110);
    local_128.x = local_17c.x;
    local_128.y = local_17c.y;
    local_128.z = local_17c.z;
    iVar5 = this->field_0x34 - 2;
    pcVar2 = pcVar7;
    pcVar3 = pcVar8;
    while( true ) {
      pcVar9 = pcVar3 + 2;
      if (iVar5 < 1) break;
      if (iVar5 < (int)(uint)param_4) {
        dVar23 = (double)(float)(dVar23 - dVar24);
      }
      pcVar2[1].z = (float)dVar22;
      pcVar2[2].y = (float)dVar22;
      ::cXyz::operator__(&local_188,this_00 + 1,this_00);
      local_110.x = local_188.x;
      local_110.y = local_188.y;
      local_110.z = local_188.z;
      fVar25 = mtx::PSVECSquareMag(&local_110);
      dVar14 = (double)fVar25;
      if (dVar16 < dVar14) {
        dVar12 = 1.0 / SQRT(dVar14);
        dVar12 = m_Do_ext::_7560 * dVar12 * (m_Do_ext::_7561 - dVar14 * dVar12 * dVar12);
        dVar12 = m_Do_ext::_7560 * dVar12 * (m_Do_ext::_7561 - dVar14 * dVar12 * dVar12);
        dVar14 = (double)(float)(dVar14 * m_Do_ext::_7560 * dVar12 *
                                          (m_Do_ext::_7561 - dVar14 * dVar12 * dVar12));
      }
      dVar22 = (double)(float)(dVar22 + (double)(float)(dVar20 * dVar14));
      ::cXyz::operator__(&local_194,this_00,&pcVar4->mEyePos);
      local_104.x = local_194.x;
      local_104.y = local_194.y;
      local_104.z = local_194.z;
      ::cXyz::outprod(&local_1a0,&local_110,&local_104);
      local_110.x = local_1a0.x;
      local_110.y = local_1a0.y;
      local_110.z = local_1a0.z;
      fVar25 = mtx::PSVECSquareMag(&local_110);
      dVar14 = (double)fVar25;
      if (dVar15 < dVar14) {
        dVar12 = 1.0 / SQRT(dVar14);
        dVar12 = m_Do_ext::_7560 * dVar12 * (m_Do_ext::_7561 - dVar14 * dVar12 * dVar12);
        dVar12 = m_Do_ext::_7560 * dVar12 * (m_Do_ext::_7561 - dVar14 * dVar12 * dVar12);
        dVar14 = (double)(float)(dVar14 * m_Do_ext::_7560 * dVar12 *
                                          (m_Do_ext::_7561 - dVar14 * dVar12 * dVar12));
      }
      if (dVar21 != dVar14) {
        dVar14 = (double)(float)(dVar23 / dVar14);
      }
      mtx::PSVECScale(&local_110,&local_110,(float)dVar14);
      ::cXyz::operator__(&cStack428,this_00,&local_110);
      mtx::PSVECAdd(&local_11c,&cStack428,&local_11c);
      ::cXyz::operator__(&cStack440,this_00,&local_110);
      mtx::PSVECAdd(&local_128,&cStack440,&local_128);
      ::cXyz::operator_(&local_1c4,&local_11c,m_Do_ext::_7562);
      pcVar9->x = local_1c4.x;
      pcVar3[2].y = local_1c4.y;
      pcVar3[2].z = local_1c4.z;
      ::cXyz::operator_(&local_1d0,&local_128,m_Do_ext::_7562);
      pcVar3[3].x = local_1d0.x;
      pcVar3[3].y = local_1d0.y;
      pcVar3[3].z = local_1d0.z;
      this_00 = this_00 + 1;
      ::cXyz::operator__(&local_1dc,this_00,&local_110);
      local_11c.x = local_1dc.x;
      local_11c.y = local_1dc.y;
      local_11c.z = local_1dc.z;
      ::cXyz::operator__(&local_1e8,this_00,&local_110);
      local_128.x = local_1e8.x;
      local_128.y = local_1e8.y;
      local_128.z = local_1e8.z;
      iVar5 = iVar5 + -1;
      pcVar2 = (cXyz *)&pcVar2[1].y;
      pcVar3 = pcVar9;
    }
    pcVar2[1].z = (float)dVar22;
    pcVar2[2].y = (float)dVar22;
    if (param_4 == 0) {
      pcVar9->x = local_11c.x;
      pcVar3[2].y = local_11c.y;
      pcVar3[2].z = local_11c.z;
      pcVar3[3].x = local_128.x;
      pcVar3[3].y = local_128.y;
      pcVar3[3].z = local_128.z;
    }
    else {
      pcVar9->x = this_00->x;
      pcVar3[2].y = this_00->y;
      pcVar3[2].z = this_00->z;
      pcVar3[3].x = this_00->x;
      pcVar3[3].y = this_00->y;
      pcVar3[3].z = this_00->z;
    }
    os::DCStoreRangeNoSync(pcVar8,(uint)uVar1 * 0x18);
    os::DCStoreRangeNoSync(pcVar7,(uint)uVar1 << 4);
    pmVar10 = pmVar10 + 1;
  }
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  __psq_l0(auStack24,uVar11);
  __psq_l1(auStack24,uVar11);
  __psq_l0(auStack40,uVar11);
  __psq_l1(auStack40,uVar11);
  __psq_l0(auStack56,uVar11);
  __psq_l1(auStack56,uVar11);
  __psq_l0(auStack72,uVar11);
  __psq_l1(auStack72,uVar11);
  __psq_l0(auStack88,uVar11);
  __psq_l1(auStack88,uVar11);
  __psq_l0(auStack104,uVar11);
  __psq_l1(auStack104,uVar11);
  __psq_l0(auStack120,uVar11);
  __psq_l1(auStack120,uVar11);
  __psq_l0(auStack136,uVar11);
  __psq_l1(auStack136,uVar11);
  __psq_l0(auStack152,uVar11);
  __psq_l1(auStack152,uVar11);
  __psq_l0(auStack168,uVar11);
  __psq_l1(auStack168,uVar11);
  return;
}


/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* WARNING: Removing unreachable block (ram,0x800164f0) */
/* WARNING: Removing unreachable block (ram,0x800164e0) */
/* WARNING: Removing unreachable block (ram,0x800164d0) */
/* WARNING: Removing unreachable block (ram,0x800164c0) */
/* WARNING: Removing unreachable block (ram,0x800164c8) */
/* WARNING: Removing unreachable block (ram,0x800164d8) */
/* WARNING: Removing unreachable block (ram,0x800164e8) */
/* WARNING: Removing unreachable block (ram,0x800164f8) */
/* __thiscall mDoExt_3DlineMat1_c::update(unsigned short,
                                          _GXColor &,
                                          dKy_tevstr_c *) */

void __thiscall
mDoExt_3DlineMat1_c::update
          (mDoExt_3DlineMat1_c *this,ushort param_1,_GXColor *param_2,dKy_tevstr_c *param_3)

{
  ushort uVar1;
  cXyz *pcVar2;
  cXyz *pcVar3;
  camera_class *pcVar4;
  ulong uVar5;
  int iVar6;
  cXyz *pcVar7;
  cXyz *pcVar8;
  cXyz *pcVar9;
  int iVar10;
  byte *pbVar11;
  cXyz *pcVar12;
  mDoExt_3Dline_c *pmVar13;
  undefined4 uVar14;
  double dVar15;
  double dVar16;
  undefined8 in_f24;
  undefined8 in_f25;
  double dVar17;
  undefined8 in_f26;
  double dVar18;
  undefined8 in_f27;
  double dVar19;
  undefined8 in_f28;
  double dVar20;
  double dVar21;
  undefined8 in_f29;
  double dVar22;
  undefined8 in_f30;
  double dVar23;
  undefined8 in_f31;
  double dVar24;
  float fVar25;
  cXyz local_1b8;
  cXyz local_1ac;
  cXyz local_1a0;
  cXyz local_194;
  cXyz cStack392;
  cXyz cStack380;
  cXyz local_170;
  cXyz local_164;
  cXyz local_158;
  cXyz local_14c;
  cXyz local_140;
  cXyz local_134;
  cXyz local_128;
  cXyz local_11c;
  cXyz local_110;
  cXyz local_104;
  cXyz local_f8;
  cXyz local_ec;
  cXyz local_e0;
  cXyz local_d4;
  undefined4 local_c8;
  uint uStack196;
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar14 = 0;
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
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  (this->mColor).r = param_2->r;
  (this->mColor).g = param_2->g;
  (this->mColor).b = param_2->b;
  (this->mColor).a = param_2->a;
  this->mpTevStr = param_3;
  this->field_0x34 = param_1;
  if (this->field_0x32 < this->field_0x34) {
    this->field_0x34 = this->field_0x32;
  }
  pcVar4 = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera;
  pmVar13 = this->mpLines;
  uVar1 = this->field_0x34;
  dVar20 = (double)m_Do_ext::0_0;
  dVar24 = (double)m_Do_ext::0_1;
  dVar17 = dVar20;
  dVar18 = dVar20;
  dVar19 = dVar20;
  dVar21 = dVar20;
  dVar22 = dVar20;
  dVar23 = dVar20;
  for (iVar10 = 0; iVar10 < (int)(uint)this->mNumLines; iVar10 = iVar10 + 1) {
    pcVar12 = pmVar13->mpSegments;
    pbVar11 = *(byte **)&pmVar13->field_0x4;
    if (pbVar11 == (byte *)0x0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"m_Do_ext.cpp",0x147b,"size_p != 0");
      m_Do_printf::OSPanic("m_Do_ext.cpp",0x147b,"Halt");
    }
    pcVar8 = (pmVar13->mPosArr + (this->mCurArr - 2))[2];
    pcVar7 = (pmVar13->mPosArr + (this->mCurArr - 2))[4];
    pcVar7->y = (float)dVar21;
    pcVar7[1].x = (float)dVar21;
    ::cXyz::operator__(&local_104,pcVar12 + 1,pcVar12);
    local_e0.x = local_104.x;
    local_e0.y = local_104.y;
    local_e0.z = local_104.z;
    fVar25 = mtx::PSVECSquareMag(&local_e0);
    dVar16 = (double)fVar25;
    if (dVar22 < dVar16) {
      dVar15 = 1.0 / SQRT(dVar16);
      dVar15 = m_Do_ext::_7560 * dVar15 * (m_Do_ext::_7561 - dVar16 * dVar15 * dVar15);
      dVar15 = m_Do_ext::_7560 * dVar15 * (m_Do_ext::_7561 - dVar16 * dVar15 * dVar15);
      dVar16 = (double)(float)(dVar16 * m_Do_ext::_7560 * dVar15 *
                                        (m_Do_ext::_7561 - dVar16 * dVar15 * dVar15));
    }
    dVar21 = (double)(float)(dVar21 + (double)(float)(dVar24 * dVar16));
    ::cXyz::operator__(&local_110,pcVar12,&pcVar4->mEyePos);
    local_d4.x = local_110.x;
    local_d4.y = local_110.y;
    local_d4.z = local_110.z;
    ::cXyz::outprod(&local_11c,&local_e0,&local_d4);
    local_e0.x = local_11c.x;
    local_e0.y = local_11c.y;
    local_e0.z = local_11c.z;
    fVar25 = mtx::PSVECSquareMag(&local_e0);
    dVar16 = (double)fVar25;
    if (dVar23 < dVar16) {
      dVar15 = 1.0 / SQRT(dVar16);
      dVar15 = m_Do_ext::_7560 * dVar15 * (m_Do_ext::_7561 - dVar16 * dVar15 * dVar15);
      dVar15 = m_Do_ext::_7560 * dVar15 * (m_Do_ext::_7561 - dVar16 * dVar15 * dVar15);
      dVar16 = (double)(float)(dVar16 * m_Do_ext::_7560 * dVar15 *
                                        (m_Do_ext::_7561 - dVar16 * dVar15 * dVar15));
    }
    if (dVar19 != dVar16) {
      uStack196 = (uint)*pbVar11;
      local_c8 = 0x43300000;
      mtx::PSVECScale(&local_e0,&local_e0,
                      (float)((double)(float)((double)CONCAT44(0x43300000,uStack196) -
                                             m_Do_ext::_7564) / dVar16));
    }
    ::cXyz::operator__(&local_128,pcVar12,&local_e0);
    pcVar8->x = local_128.x;
    pcVar8->y = local_128.y;
    pcVar8->z = local_128.z;
    ::cXyz::operator__(&local_134,pcVar12,&local_e0);
    pcVar8[1].x = local_134.x;
    pcVar8[1].y = local_134.y;
    pcVar8[1].z = local_134.z;
    pcVar12 = pcVar12 + 1;
    ::cXyz::operator__(&local_140,pcVar12,&local_e0);
    local_ec.x = local_140.x;
    local_ec.y = local_140.y;
    local_ec.z = local_140.z;
    ::cXyz::operator__(&local_14c,pcVar12,&local_e0);
    local_f8.x = local_14c.x;
    local_f8.y = local_14c.y;
    local_f8.z = local_14c.z;
    iVar6 = this->field_0x34 - 2;
    pcVar2 = pcVar7;
    pcVar3 = pcVar8;
    while( true ) {
      pbVar11 = pbVar11 + 1;
      pcVar9 = pcVar3 + 2;
      if (iVar6 < 1) break;
      pcVar2[1].z = (float)dVar21;
      pcVar2[2].y = (float)dVar21;
      ::cXyz::operator__(&local_158,pcVar12 + 1,pcVar12);
      local_e0.x = local_158.x;
      local_e0.y = local_158.y;
      local_e0.z = local_158.z;
      fVar25 = mtx::PSVECSquareMag(&local_e0);
      dVar16 = (double)fVar25;
      if (dVar18 < dVar16) {
        dVar15 = 1.0 / SQRT(dVar16);
        dVar15 = m_Do_ext::_7560 * dVar15 * (m_Do_ext::_7561 - dVar16 * dVar15 * dVar15);
        dVar15 = m_Do_ext::_7560 * dVar15 * (m_Do_ext::_7561 - dVar16 * dVar15 * dVar15);
        dVar16 = (double)(float)(dVar16 * m_Do_ext::_7560 * dVar15 *
                                          (m_Do_ext::_7561 - dVar16 * dVar15 * dVar15));
      }
      dVar21 = (double)(float)(dVar21 + (double)(float)(dVar24 * dVar16));
      ::cXyz::operator__(&local_164,pcVar12,&pcVar4->mEyePos);
      local_d4.x = local_164.x;
      local_d4.y = local_164.y;
      local_d4.z = local_164.z;
      ::cXyz::outprod(&local_170,&local_e0,&local_d4);
      local_e0.x = local_170.x;
      local_e0.y = local_170.y;
      local_e0.z = local_170.z;
      fVar25 = mtx::PSVECSquareMag(&local_e0);
      dVar16 = (double)fVar25;
      if (dVar17 < dVar16) {
        dVar15 = 1.0 / SQRT(dVar16);
        dVar15 = m_Do_ext::_7560 * dVar15 * (m_Do_ext::_7561 - dVar16 * dVar15 * dVar15);
        dVar15 = m_Do_ext::_7560 * dVar15 * (m_Do_ext::_7561 - dVar16 * dVar15 * dVar15);
        dVar16 = (double)(float)(dVar16 * m_Do_ext::_7560 * dVar15 *
                                          (m_Do_ext::_7561 - dVar16 * dVar15 * dVar15));
      }
      if (dVar20 != dVar16) {
        uStack196 = (uint)*pbVar11;
        local_c8 = 0x43300000;
        dVar16 = (double)(float)((double)(float)((double)CONCAT44(0x43300000,uStack196) -
                                                m_Do_ext::_7564) / dVar16);
      }
      mtx::PSVECScale(&local_e0,&local_e0,(float)dVar16);
      ::cXyz::operator__(&cStack380,pcVar12,&local_e0);
      mtx::PSVECAdd(&local_ec,&cStack380,&local_ec);
      ::cXyz::operator__(&cStack392,pcVar12,&local_e0);
      mtx::PSVECAdd(&local_f8,&cStack392,&local_f8);
      ::cXyz::operator_(&local_194,&local_ec,m_Do_ext::_7562);
      pcVar9->x = local_194.x;
      pcVar3[2].y = local_194.y;
      pcVar3[2].z = local_194.z;
      ::cXyz::operator_(&local_1a0,&local_f8,m_Do_ext::_7562);
      pcVar3[3].x = local_1a0.x;
      pcVar3[3].y = local_1a0.y;
      pcVar3[3].z = local_1a0.z;
      pcVar12 = pcVar12 + 1;
      ::cXyz::operator__(&local_1ac,pcVar12,&local_e0);
      local_ec.x = local_1ac.x;
      local_ec.y = local_1ac.y;
      local_ec.z = local_1ac.z;
      ::cXyz::operator__(&local_1b8,pcVar12,&local_e0);
      local_f8.x = local_1b8.x;
      local_f8.y = local_1b8.y;
      local_f8.z = local_1b8.z;
      iVar6 = iVar6 + -1;
      pcVar2 = (cXyz *)&pcVar2[1].y;
      pcVar3 = pcVar9;
    }
    pcVar2[1].z = (float)dVar21;
    pcVar2[2].y = (float)dVar21;
    pcVar9->x = local_ec.x;
    pcVar3[2].y = local_ec.y;
    pcVar3[2].z = local_ec.z;
    pcVar3[3].x = local_f8.x;
    pcVar3[3].y = local_f8.y;
    pcVar3[3].z = local_f8.z;
    os::DCStoreRangeNoSync(pcVar8,(uint)uVar1 * 0x18);
    os::DCStoreRangeNoSync(pcVar7,(uint)uVar1 << 4);
    pmVar13 = pmVar13 + 1;
  }
  __psq_l0(auStack8,uVar14);
  __psq_l1(auStack8,uVar14);
  __psq_l0(auStack24,uVar14);
  __psq_l1(auStack24,uVar14);
  __psq_l0(auStack40,uVar14);
  __psq_l1(auStack40,uVar14);
  __psq_l0(auStack56,uVar14);
  __psq_l1(auStack56,uVar14);
  __psq_l0(auStack72,uVar14);
  __psq_l1(auStack72,uVar14);
  __psq_l0(auStack88,uVar14);
  __psq_l1(auStack88,uVar14);
  __psq_l0(auStack104,uVar14);
  __psq_l1(auStack104,uVar14);
  __psq_l0(auStack120,uVar14);
  __psq_l1(auStack120,uVar14);
  return;
}


/* __thiscall mDoExt_3DlineMatSortPacket::setMat(mDoExt_3DlineMat_c *) */

void __thiscall
mDoExt_3DlineMatSortPacket::setMat(mDoExt_3DlineMatSortPacket *this,mDoExt_3DlineMat_c *param_1)

{
  if (this->mp3DlineMat == (mDoExt_3DlineMat_c *)0x0) {
    J3DDrawBuffer::entryImm(J3DGraphBase::j3dSys.mpCurDrawBuffers[0],(J3DPacket *)this,0);
  }
  *(mDoExt_3DlineMat_c **)&param_1->field_0x4 = this->mp3DlineMat;
  this->mp3DlineMat = param_1;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mDoExt_3DlineMatSortPacket::draw(void) */

void __thiscall mDoExt_3DlineMatSortPacket::draw(mDoExt_3DlineMatSortPacket *this)

{
  mDoExt_3DlineMat_c *pmVar1;
  
  (*(code *)this->mp3DlineMat->vtbl->field_0xc)();
  pmVar1 = this->mp3DlineMat;
  do {
    (*(code *)pmVar1->vtbl->draw)(pmVar1);
    pmVar1 = *(mDoExt_3DlineMat_c **)&pmVar1->field_0x4;
  } while (pmVar1 != (mDoExt_3DlineMat_c *)0x0);
  _sOldVcdVatCmd = 0;
  return;
}


namespace m_Do_ext {

/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __stdcall mDoExt_initFontCommon(JUTFont * *,
                                   ResFONT * *,
                                   JKRHeap *,
                                   char const *,
                                   JKRArchive *,
                                   unsigned char,
                                   unsigned long,
                                   unsigned long) */

void mDoExt_initFontCommon
               (JUTResFont **param_1,ResFONT **param_2,JKRHeap *param_3,char *param_4,
               JKRArchive *param_5,char param_6,int param_7,int param_8)

{
  ulong uVar1;
  ResFONT *pRVar2;
  JUTResFont *pJVar3;
  
  if (*param_1 != (JUTResFont *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"m_Do_ext.cpp",0x19f8,"mDoExt_font == 0");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x19f8,"Halt");
  }
  if (*param_2 != (ResFONT *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"m_Do_ext.cpp",0x19f9,"mDoExt_resfont == 0");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x19f9,"Halt");
  }
  pRVar2 = (ResFONT *)JKRArchive::getGlbResource(0x524f4f54,param_4,param_5);
  *param_2 = pRVar2;
  if (*param_2 == (ResFONT *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"m_Do_ext.cpp",0x19fb,"mDoExt_resfont != 0");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x19fb,"Halt");
  }
  if (param_6 == '\0') {
    pJVar3 = (JUTResFont *)JKernel::operator_new(0xb8,param_3,0);
    if (pJVar3 != (JUTResFont *)0x0) {
      JUTCacheFont::JUTCacheFont
                ((JUTCacheFont *)pJVar3,*param_2,((param_8 + 0x1fU & 0xffffffe0) + 0x40) * param_7,
                 param_3);
    }
    if ((((JUTResFont *)&pJVar3->parent)->parent).mValid != 0) {
      *param_1 = pJVar3;
    }
    JKRFileLoader::removeResource(*param_2,(JKRFileLoader *)0x0);
    *param_2 = (ResFONT *)0x0;
  }
  else {
    pJVar3 = (JUTResFont *)JKernel::operator_new(0x70);
    if (pJVar3 != (JUTResFont *)0x0) {
      JUTResFont::JUTResFont(pJVar3,*param_2,param_3);
    }
    *param_1 = pJVar3;
  }
  if ((*param_1 != (JUTResFont *)0x0) && ((((JUTResFont *)&(*param_1)->parent)->parent).mValid == 0)
     ) {
    m_Do_printf::OSReport_FatalError
              ("\nキャッシュフォントクラス作成に失敗しました\n");
    pJVar3 = *param_1;
    if (pJVar3 != (JUTResFont *)0x0) {
      (*(code *)((((JUTResFont *)&pJVar3->parent)->parent).vtbl)->_)(pJVar3,1);
    }
    *param_1 = (JUTResFont *)0x0;
  }
  if (*param_1 == (JUTResFont *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"m_Do_ext.cpp",0x1a1d,"mDoExt_font != 0");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x1a1d,"Halt");
  }
  return;
}

}

/* __thiscall JUTFont::~JUTFont(void) */

void __thiscall JUTFont::_JUTFont(JUTFont *this)

{
  short in_r4;
  
  if ((this != (JUTFont *)0x0) && (this->vtbl = (JUTFont__vtbl *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace m_Do_ext {

/* __stdcall mDoExt_initFont0(void) */

void mDoExt_initFont0(void)

{
  JKRArchive *pJVar1;
  JKRHeap *pJVar2;
  
  pJVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFontArchive;
  pJVar2 = mDoExt_getZeldaHeap();
  mDoExt_initFontCommon(&mDoExt_font0,&mDoExt_resfont0,pJVar2,"rock_24_20_4i_usa.bfn",pJVar1,1,0,0);
  return;
}


/* WARNING: Unknown calling convention yet parameter storage is locked */
/* __stdcall mDoExt_getMesgFont(void) */

JUTFont * mDoExt_getMesgFont(void)

{
  if (mDoExt_font0 == (JUTFont *)0x0) {
    mDoExt_initFont0();
  }
  mDoExt_font0_getCount = mDoExt_font0_getCount + 1;
  return mDoExt_font0;
}


/* __stdcall mDoExt_removeMesgFont(void) */

void mDoExt_removeMesgFont(void)

{
  ulong uVar1;
  
  if (mDoExt_font0_getCount < 1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"m_Do_ext.cpp",0x1a50,"mDoExt_font0_getCount > 0");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x1a50,"Halt");
  }
  if (0 < mDoExt_font0_getCount) {
    mDoExt_font0_getCount = mDoExt_font0_getCount + -1;
    if (mDoExt_font0_getCount < 1) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"m_Do_ext.cpp",0x1a53,"mDoExt_font0_getCount > 0");
      m_Do_printf::OSPanic("m_Do_ext.cpp",0x1a53,"Halt");
    }
    if (mDoExt_font0_getCount == 0) {
      if (mDoExt_font0 != (int *)0x0) {
        (**(code **)(*mDoExt_font0 + 8))(mDoExt_font0,1);
      }
      mDoExt_font0 = (int *)0x0;
      if (mDoExt_resfont0 != (void *)0x0) {
        JKRHeap::free(mDoExt_resfont0,(JKRHeap *)0x0);
        mDoExt_resfont0 = (void *)0x0;
      }
    }
  }
  return;
}


/* __stdcall mDoExt_initFont1(void) */

void mDoExt_initFont1(void)

{
  undefined4 uVar1;
  JKRHeap *pJVar2;
  
  uVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay._18348_4_;
  pJVar2 = mDoExt_getZeldaHeap();
  mDoExt_initFontCommon(&mDoExt_font1,&mDoExt_resfont1,pJVar2,"hyrule.bfn",uVar1,1,1,0x8000);
  return;
}


/* WARNING: Unknown calling convention yet parameter storage is locked */
/* __stdcall mDoExt_getRubyFont(void) */

JUTFont * mDoExt_getRubyFont(void)

{
  if (mDoExt_font1 == (JUTFont *)0x0) {
    mDoExt_initFont1();
  }
  mDoExt_font1_getCount = mDoExt_font1_getCount + 1;
  return mDoExt_font1;
}


/* __stdcall mDoExt_removeRubyFont(void) */

void mDoExt_removeRubyFont(void)

{
  ulong uVar1;
  
  if (mDoExt_font1_getCount < 1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"m_Do_ext.cpp",0x1a86,"mDoExt_font1_getCount > 0");
    m_Do_printf::OSPanic("m_Do_ext.cpp",0x1a86,"Halt");
  }
  if (0 < mDoExt_font1_getCount) {
    mDoExt_font1_getCount = mDoExt_font1_getCount + -1;
    if (mDoExt_font1_getCount < 1) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"m_Do_ext.cpp",0x1a89,"mDoExt_font1_getCount > 0");
      m_Do_printf::OSPanic("m_Do_ext.cpp",0x1a89,"Halt");
    }
    if (mDoExt_font1_getCount == 0) {
      if (mDoExt_font1 != (int *)0x0) {
        (**(code **)(*mDoExt_font1 + 8))(mDoExt_font1,1);
      }
      mDoExt_font1 = (int *)0x0;
      if (mDoExt_resfont1 != (void *)0x0) {
        JKRHeap::free(mDoExt_resfont1,(JKRHeap *)0x0);
        mDoExt_resfont1 = (void *)0x0;
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */

J3DModel * mDoExt_J3DModel__create(J3DModelData *pModel,ulong param_2,ulong param_3)

{
  J3DModel *this;
  int iVar1;
  
  this = (J3DModel *)JKernel::operator_new(0x108);
  if (this != (J3DModel *)0x0) {
    J3DModel::J3DModel(this);
  }
  if (this != (J3DModel *)0x0) {
    if (((pModel->mJointTree).mbIsBDL == 1) && (param_2 == 0)) {
      if ((pModel->mShapeTable).field_0x0 == 1) {
        param_2 = 0x20000;
      }
      else {
        param_2 = 0x80000;
      }
    }
    iVar1 = J3DModel::entryModelData(this,pModel,param_2,1);
    if (iVar1 == 0) {
      if (param_2 != 0x80000) {
        return this;
      }
      if ((param_3 & 2) != 0) {
        param_3 = param_3 | 0x20;
      }
      iVar1 = J3DModel::newDifferedDisplayList(this,param_3);
      if (iVar1 == 0) {
        return this;
      }
      return (J3DModel *)0x0;
    }
  }
  return (J3DModel *)0x0;
}

}

/* __thiscall JUTFont::setGX(JUtility::TColor,
                             JUtility::TColor) */

void __thiscall JUTFont::setGX(JUTFont *this,TColor param_1,TColor param_2)

{
  (*(code *)this->vtbl->setGX)();
  return;
}


/* __thiscall JUTFont::getCellWidth(void) const */

void __thiscall JUTFont::getCellWidth(JUTFont *this)

{
  (*(code *)this->vtbl->getWidth)();
  return;
}


/* __thiscall JUTFont::getCellHeight(void) const */

void __thiscall JUTFont::getCellHeight(JUTFont *this)

{
  (*(code *)this->vtbl->getHeight)();
  return;
}


/* __thiscall mDoExt_3DlineMatSortPacket::~mDoExt_3DlineMatSortPacket(void) */

void __thiscall
mDoExt_3DlineMatSortPacket::_mDoExt_3DlineMatSortPacket(mDoExt_3DlineMatSortPacket *this)

{
  short in_r4;
  
  if (this != (mDoExt_3DlineMatSortPacket *)0x0) {
    this->field_0x0 = &__vt;
    if (this != (mDoExt_3DlineMatSortPacket *)0x0) {
      this->field_0x0 = &J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall mDoExt_3DlineMat1_c::getMaterialID(void) */

undefined4 __thiscall mDoExt_3DlineMat1_c::getMaterialID(mDoExt_3DlineMat1_c *this)

{
  return 1;
}


/* __thiscall mDoExt_3DlineMat0_c::getMaterialID(void) */

undefined4 __thiscall mDoExt_3DlineMat0_c::getMaterialID(mDoExt_3DlineMat0_c *this)

{
  return 0;
}


/* __thiscall mDoExt_onCupOffAupPacket::~mDoExt_onCupOffAupPacket(void) */

void __thiscall mDoExt_onCupOffAupPacket::_mDoExt_onCupOffAupPacket(mDoExt_onCupOffAupPacket *this)

{
  short in_r4;
  
  if (this != (mDoExt_onCupOffAupPacket *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (mDoExt_onCupOffAupPacket *)0x0) {
      *(undefined ***)this = &J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall mDoExt_offCupOnAupPacket::~mDoExt_offCupOnAupPacket(void) */

void __thiscall mDoExt_offCupOnAupPacket::_mDoExt_offCupOnAupPacket(mDoExt_offCupOnAupPacket *this)

{
  short in_r4;
  
  if (this != (mDoExt_offCupOnAupPacket *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (mDoExt_offCupOnAupPacket *)0x0) {
      *(undefined ***)this = &J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall mDoExt_McaMorf2::~mDoExt_McaMorf2(void) */

void __thiscall mDoExt_McaMorf2::_mDoExt_McaMorf2(mDoExt_McaMorf2 *this)

{
  J3DMtxCalc *pJVar1;
  short in_r4;
  
  if (this != (mDoExt_McaMorf2 *)0x0) {
    (this->parent).vtbl = &__vt;
    ((this->parent).vderiv)->vtbl = &DAT_80371bd0;
    pJVar1 = (this->parent).vderiv;
    pJVar1[9].vtbl = (undefined *)((int)this + (0x94 - (int)pJVar1));
    if (this != (mDoExt_McaMorf2 *)0xffffff9c) {
      (this->mFrameCtrl).vtbl = (undefined *)&J3DFrameCtrl::__vt;
    }
    if (this != (mDoExt_McaMorf2 *)0x0) {
      (this->parent).vtbl = &J3DMtxCalcMaya::__vt;
      ((this->parent).vderiv)->vtbl = &DAT_8039eba4;
      pJVar1 = (this->parent).vderiv;
      pJVar1[9].vtbl = (undefined *)((int)&this->mpModel - (int)pJVar1);
      if (this != (mDoExt_McaMorf2 *)0x0) {
        (this->parent).vtbl = (undefined *)&J3DMtxCalcBasic::__vt;
        ((this->parent).vderiv)->vtbl = (undefined *)&PTR_8039ec0c;
        pJVar1 = (this->parent).vderiv;
        pJVar1[9].vtbl = (undefined *)((int)&this->mpModel - (int)pJVar1);
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DMtxCalcMaya::init(Vec const &,
                                   float const &[][][]) */

int __thiscall J3DMtxCalcMaya::init(J3DMtxCalcMaya *this,EVP_PKEY_CTX *ctx)

{
  float *in_r5;
  
  J3DSys::mCurrentS.x = *(float *)ctx;
  J3DSys::mCurrentS.y = *(float *)(ctx + 4);
  J3DSys::mCurrentS.z = *(float *)(ctx + 8);
  J3DSys::mCurrentMtx.m[0][0] = *in_r5 * J3DSys::mCurrentS.x;
  J3DSys::mCurrentMtx.m[0][1] = in_r5[1] * J3DSys::mCurrentS.y;
  J3DSys::mCurrentMtx.m[0][2] = in_r5[2] * J3DSys::mCurrentS.z;
  J3DSys::mCurrentMtx.m[0][3] = in_r5[3];
  J3DSys::mCurrentMtx.m[1][0] = in_r5[4] * J3DSys::mCurrentS.x;
  J3DSys::mCurrentMtx.m[1][1] = in_r5[5] * J3DSys::mCurrentS.y;
  J3DSys::mCurrentMtx.m[1][2] = in_r5[6] * J3DSys::mCurrentS.z;
  J3DSys::mCurrentMtx.m[1][3] = in_r5[7];
  J3DSys::mCurrentMtx.m[2][0] = in_r5[8] * J3DSys::mCurrentS.x;
  J3DSys::mCurrentMtx.m[2][1] = in_r5[9] * J3DSys::mCurrentS.y;
  J3DSys::mCurrentMtx.m[2][2] = in_r5[10] * J3DSys::mCurrentS.z;
  J3DSys::mCurrentMtx.m[2][3] = in_r5[0xb];
  J3DSys::mParentS.x = m_Do_ext::_2100;
  J3DSys::mParentS.y = DAT_803717a4;
  J3DSys::mParentS.z = DAT_803717a8;
  return (int)&J3DSys::mCurrentMtx;
}


/* __thiscall mDoExt_McaMorf::~mDoExt_McaMorf(void) */

void __thiscall mDoExt_McaMorf::_mDoExt_McaMorf(mDoExt_McaMorf *this)

{
  J3DMtxCalc *pJVar1;
  short in_r4;
  
  if (this != (mDoExt_McaMorf *)0x0) {
    (this->parent).vtbl = (undefined *)&__vt;
    ((this->parent).vderiv)->vtbl = &DAT_80371c04;
    pJVar1 = (this->parent).vderiv;
    pJVar1[9].vtbl = (undefined *)((int)this + (0x8c - (int)pJVar1));
    if (this != (mDoExt_McaMorf *)0xffffffa8) {
      (this->mFrameCtrl).vtbl = (undefined *)&J3DFrameCtrl::__vt;
    }
    if (this != (mDoExt_McaMorf *)0x0) {
      (this->parent).vtbl = &J3DMtxCalcMaya::__vt;
      ((this->parent).vderiv)->vtbl = &DAT_8039eba4;
      pJVar1 = (this->parent).vderiv;
      pJVar1[9].vtbl = (undefined *)((int)&this->mpModel - (int)pJVar1);
      if (this != (mDoExt_McaMorf *)0x0) {
        (this->parent).vtbl = (undefined *)&J3DMtxCalcBasic::__vt;
        ((this->parent).vderiv)->vtbl = (undefined *)&PTR_8039ec0c;
        pJVar1 = (this->parent).vderiv;
        pJVar1[9].vtbl = (undefined *)((int)&this->mpModel - (int)pJVar1);
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall mDoExt_MtxCalcAnmBlendTblOld::~mDoExt_MtxCalcAnmBlendTblOld(void) */

void __thiscall
mDoExt_MtxCalcAnmBlendTblOld::_mDoExt_MtxCalcAnmBlendTblOld(mDoExt_MtxCalcAnmBlendTblOld *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (mDoExt_MtxCalcAnmBlendTblOld *)0x0;
  if (bVar1) {
    *(undefined1 **)(this + 0x4c) = &__vt;
    **(undefined4 **)this = &DAT_80371c48;
    *(mDoExt_MtxCalcAnmBlendTblOld **)(*(int *)this + 0x24) = this + (0x68 - *(int *)this);
    if (bVar1) {
      *(undefined1 **)(this + 0x4c) = &mDoExt_MtxCalcAnmBlendTbl::__vt;
      **(undefined4 **)this = &DAT_80371c7c;
      *(mDoExt_MtxCalcAnmBlendTblOld **)(*(int *)this + 0x24) = this + (0x58 - *(int *)this);
      if (bVar1) {
        *(undefined1 **)(this + 0x4c) = &J3DMtxCalcMaya::__vt;
        **(undefined4 **)this = &DAT_8039eba4;
        *(int *)(*(int *)this + 0x24) = (int)(this + 0x50) - *(int *)this;
        if (bVar1) {
          *(J3DMtxCalcBasic__vtbl **)(this + 0x4c) = &J3DMtxCalcBasic::__vt;
          **(undefined ***)this = (undefined *)&PTR_8039ec0c;
          *(int *)(*(int *)this + 0x24) = (int)(this + 0x50) - *(int *)this;
        }
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall mDoExt_MtxCalcAnmBlendTbl::~mDoExt_MtxCalcAnmBlendTbl(void) */

void __thiscall
mDoExt_MtxCalcAnmBlendTbl::_mDoExt_MtxCalcAnmBlendTbl(mDoExt_MtxCalcAnmBlendTbl *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (mDoExt_MtxCalcAnmBlendTbl *)0x0;
  if (bVar1) {
    *(undefined1 **)(this + 0x4c) = &__vt;
    **(undefined4 **)this = &DAT_80371c7c;
    *(mDoExt_MtxCalcAnmBlendTbl **)(*(int *)this + 0x24) = this + (0x58 - *(int *)this);
    if (bVar1) {
      *(undefined1 **)(this + 0x4c) = &J3DMtxCalcMaya::__vt;
      **(undefined4 **)this = &DAT_8039eba4;
      *(int *)(*(int *)this + 0x24) = (int)(this + 0x50) - *(int *)this;
      if (bVar1) {
        *(J3DMtxCalcBasic__vtbl **)(this + 0x4c) = &J3DMtxCalcBasic::__vt;
        **(undefined ***)this = (undefined *)&PTR_8039ec0c;
        *(int *)(*(int *)this + 0x24) = (int)(this + 0x50) - *(int *)this;
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DMtxCalcMayaAnm::~J3DMtxCalcMayaAnm(void) */

void __thiscall J3DMtxCalcMayaAnm::_J3DMtxCalcMayaAnm(J3DMtxCalcMayaAnm *this)

{
  float fVar1;
  int iVar2;
  short in_r4;
  int iVar3;
  int iVar4;
  
  if (this != (J3DMtxCalcMayaAnm *)0x0) {
    *(undefined1 **)(this + 0x4c) = &__vt;
    **(undefined4 **)this = &DAT_80371cc0;
    *(undefined ***)(this + 0x54) = &PTR_80371cb0;
    *(int *)(*(int *)this + 0x24) = (int)(this + 0x58) - *(int *)this;
    if (this != (J3DMtxCalcMayaAnm *)0xffffffb0) {
      *(undefined ***)(this + 0x54) = &J3DMtxCalcAnm::__vt;
      **(undefined4 **)(this + 0x50) = &DAT_8039ec34;
      *(int *)(*(int *)(this + 0x50) + 0x24) = (int)(this + 0x58) - *(int *)(this + 0x50);
      fVar1 = m_Do_ext::0_0;
      iVar3 = *(int *)(this + 0x50);
      iVar2 = 0;
      iVar4 = 4;
      do {
        *(undefined4 *)(iVar3 + iVar2 + 4) = 0;
        *(float *)(iVar3 + iVar2 + 0x14) = fVar1;
        iVar2 = iVar2 + 4;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    if (this != (J3DMtxCalcMayaAnm *)0x0) {
      *(undefined1 **)(this + 0x4c) = &J3DMtxCalcMaya::__vt;
      **(undefined4 **)this = &DAT_8039eba4;
      *(int *)(*(int *)this + 0x24) = (int)(this + 0x50) - *(int *)this;
      if (this != (J3DMtxCalcMayaAnm *)0x0) {
        *(J3DMtxCalcBasic__vtbl **)(this + 0x4c) = &J3DMtxCalcBasic::__vt;
        **(undefined ***)this = (undefined *)&PTR_8039ec0c;
        *(int *)(*(int *)this + 0x24) = (int)(this + 0x50) - *(int *)this;
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DMtxCalcMayaAnm::calc(unsigned short) */

void __thiscall J3DMtxCalcMayaAnm::calc(J3DMtxCalcMayaAnm *this,ushort param_1)

{
  J3DMtxCalcAnm::calc((J3DMtxCalcAnm *)(this + 0x50),param_1);
  return;
}


/* __thiscall J3DMtxCalc::init(Vec const &,
                               float const &[][][]) */

int __thiscall J3DMtxCalc::init(J3DMtxCalc *this,EVP_PKEY_CTX *ctx)

{
  return (int)this;
}


/* __thiscall J3DMtxCalc::recursiveCalc(J3DNode *) */

void __thiscall J3DMtxCalc::recursiveCalc(J3DMtxCalc *this,J3DNode *param_1)

{
  return;
}


/* __thiscall J3DMtxCalc::calcTransform(unsigned short,
                                        J3DTransformInfo const &) */

void __thiscall J3DMtxCalc::calcTransform(J3DMtxCalc *this,ushort param_1,J3DTransformInfo *param_2)

{
  return;
}


/* __thiscall J3DMtxCalc::calc(unsigned short) */

void __thiscall J3DMtxCalc::calc(J3DMtxCalc *this,ushort param_1)

{
  return;
}


/* [thunk]:__thiscall J3DMtxCalcMayaAnm::calc(unsigned short) */

void __thiscall J3DMtxCalcMayaAnm::calc(J3DMtxCalcMayaAnm *this,ushort param_1)

{
  calc(this + *(int *)(this + 0x24) + -0x58,param_1);
  return;
}


/* [thunk]:__thiscall J3DMtxCalcMayaAnm::calc(unsigned short) */

void __thiscall J3DMtxCalcMayaAnm::calc(J3DMtxCalcMayaAnm *this,ushort param_1)

{
  calc(this + -0x50,param_1);
  return;
}


/* [thunk]:__thiscall J3DMtxCalcMayaAnm::~J3DMtxCalcMayaAnm(void) */

void __thiscall J3DMtxCalcMayaAnm::_J3DMtxCalcMayaAnm(J3DMtxCalcMayaAnm *this)

{
  _J3DMtxCalcMayaAnm(this + -0x50);
  return;
}


/* [thunk]:__thiscall mDoExt_MtxCalcAnmBlendTbl::calc(unsigned short) */

void __thiscall mDoExt_MtxCalcAnmBlendTbl::calc(mDoExt_MtxCalcAnmBlendTbl *this,ushort param_1)

{
  calc(this + *(int *)(this + 0x24) + -0x58,param_1);
  return;
}


/* [thunk]:__thiscall J3DMtxCalcMaya::calcTransform(unsigned short,
                                                    J3DTransformInfo const &) */

void __thiscall
J3DMtxCalcMaya::calcTransform(J3DMtxCalcMaya *this,ushort param_1,J3DTransformInfo *param_2)

{
  calcTransform(this + *(int *)(this + 0x24) + -0x58,param_1,param_2);
  return;
}


/* [thunk]:__thiscall J3DMtxCalcBasic::recursiveCalc(J3DNode *) */

void __thiscall J3DMtxCalcBasic::recursiveCalc(J3DMtxCalcBasic *this,J3DNode *param_1)

{
  recursiveCalc((J3DMtxCalcBasic *)((int)this + (int)(this->mCurrentMtx).m[2][0] + -0x58),param_1);
  return;
}


/* [thunk]:__thiscall J3DMtxCalcMaya::init(Vec const &,
                                           float const &[][][]) */

int __thiscall J3DMtxCalcMaya::init(J3DMtxCalcMaya *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = init(this + *(int *)(this + 0x24) + -0x58,ctx);
  return iVar1;
}


/* [thunk]:__thiscall mDoExt_MtxCalcAnmBlendTblOld::calc(unsigned short) */

void __thiscall
mDoExt_MtxCalcAnmBlendTblOld::calc(mDoExt_MtxCalcAnmBlendTblOld *this,ushort param_1)

{
  calc(this + *(int *)(this + 0x24) + -0x68,param_1);
  return;
}


/* [thunk]:__thiscall J3DMtxCalcMaya::calcTransform(unsigned short,
                                                    J3DTransformInfo const &) */

void __thiscall
J3DMtxCalcMaya::calcTransform(J3DMtxCalcMaya *this,ushort param_1,J3DTransformInfo *param_2)

{
  calcTransform(this + *(int *)(this + 0x24) + -0x68,param_1,param_2);
  return;
}


/* [thunk]:__thiscall J3DMtxCalcBasic::recursiveCalc(J3DNode *) */

void __thiscall J3DMtxCalcBasic::recursiveCalc(J3DMtxCalcBasic *this,J3DNode *param_1)

{
  recursiveCalc((J3DMtxCalcBasic *)((int)this + (int)(this->mCurrentMtx).m[2][0] + -0x68),param_1);
  return;
}


/* [thunk]:__thiscall J3DMtxCalcMaya::init(Vec const &,
                                           float const &[][][]) */

int __thiscall J3DMtxCalcMaya::init(J3DMtxCalcMaya *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = init(this + *(int *)(this + 0x24) + -0x68,ctx);
  return iVar1;
}


/* [thunk]:__thiscall mDoExt_McaMorf::calc(unsigned short) */

void __thiscall mDoExt_McaMorf::calc(mDoExt_McaMorf *this,ushort param_1)

{
  calc((mDoExt_McaMorf *)((int)this + (int)(this->parent).mCurrentMtx.m[2][0] + -0x8c),param_1);
  return;
}


/* [thunk]:__thiscall J3DMtxCalcMaya::calcTransform(unsigned short,
                                                    J3DTransformInfo const &) */

void __thiscall
J3DMtxCalcMaya::calcTransform(J3DMtxCalcMaya *this,ushort param_1,J3DTransformInfo *param_2)

{
  calcTransform(this + *(int *)(this + 0x24) + -0x8c,param_1,param_2);
  return;
}


/* [thunk]:__thiscall J3DMtxCalcBasic::recursiveCalc(J3DNode *) */

void __thiscall J3DMtxCalcBasic::recursiveCalc(J3DMtxCalcBasic *this,J3DNode *param_1)

{
  recursiveCalc((J3DMtxCalcBasic *)((int)this + (int)(this->mCurrentMtx).m[2][0] + -0x8c),param_1);
  return;
}


/* [thunk]:__thiscall J3DMtxCalcMaya::init(Vec const &,
                                           float const &[][][]) */

int __thiscall J3DMtxCalcMaya::init(J3DMtxCalcMaya *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = init(this + *(int *)(this + 0x24) + -0x8c,ctx);
  return iVar1;
}


/* [thunk]:__thiscall mDoExt_McaMorf2::calc(unsigned short) */

void __thiscall mDoExt_McaMorf2::calc(mDoExt_McaMorf2 *this,ushort param_1)

{
  calc((mDoExt_McaMorf2 *)((int)this + (int)(this->parent).mCurrentMtx.m[2][0] + -0x94),param_1);
  return;
}


/* [thunk]:__thiscall J3DMtxCalcMaya::calcTransform(unsigned short,
                                                    J3DTransformInfo const &) */

void __thiscall
J3DMtxCalcMaya::calcTransform(J3DMtxCalcMaya *this,ushort param_1,J3DTransformInfo *param_2)

{
  calcTransform(this + *(int *)(this + 0x24) + -0x94,param_1,param_2);
  return;
}


/* [thunk]:__thiscall J3DMtxCalcBasic::recursiveCalc(J3DNode *) */

void __thiscall J3DMtxCalcBasic::recursiveCalc(J3DMtxCalcBasic *this,J3DNode *param_1)

{
  recursiveCalc((J3DMtxCalcBasic *)((int)this + (int)(this->mCurrentMtx).m[2][0] + -0x94),param_1);
  return;
}


/* [thunk]:__thiscall J3DMtxCalcMaya::init(Vec const &,
                                           float const &[][][]) */

int __thiscall J3DMtxCalcMaya::init(J3DMtxCalcMaya *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = init(this + *(int *)(this + 0x24) + -0x94,ctx);
  return iVar1;
}

