#include <JPADraw/JPADraw.h>
#include <JPADraw/JPADraw.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <gx/GXAttr.h>
#include <gx/GXTransform.h>
#include <gx/GXLight.h>
#include <gx/GXBump.h>
#include <gx/GXGeometry.h>
#include <gx/GXPixel.h>
#include <JPADraw/JPADrawSetupTev.h>
#include <gx/GXTev.h>
#include <mtx/mtx.h>
#include <JPADraw/JPADrawVisitor.h>
#include <gx/GXMisc.h>
#include <gx/GXTexture.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JKernel/JKRHeap.h>
#include <JGeometry/TVec2<float><float>.h>
#include <JPADrawVisitorContainer.h>
#include <JPADraw.h>
#include <JPADrawClipBoard.h>

struct JPADrawVisitorContainer JPADraw;
struct JPADrawSetupTev JPADraw;

/* __thiscall JPADraw::initialize(JPABaseEmitter *,
                                  JPATextureResource *) */

undefined4 __thiscall
JPADraw::initialize(JPADraw *this,JPABaseEmitter *pEmitter,JPATextureResource *pTexRes)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  _GXColor uVar4;
  _GXColor uVar3;
  int *piVar4;
  byte cVar6;
  byte cVar7;
  byte cVar8;
  byte cVar9;
  ulong uVar5;
  int iVar6;
  u8 local_38;
  u8 uStack55;
  u8 uStack54;
  u8 uStack53;
  u8 local_34;
  u8 uStack51;
  u8 uStack50;
  u8 uStack49;
  u8 local_30;
  u8 uStack47;
  u8 uStack46;
  u8 uStack45;
  JPADrawVisitorDefFlags flags;
  
  ::JPADrawContext::pcb = &cb;
  (this->mDrawContext).mpBaseEmitter = pEmitter;
  (this->mDrawContext).mpBaseArc =
       ((this->mDrawContext).mpBaseEmitter)->mpDataLinkInfo->mpBaseShapeBlock;
  (this->mDrawContext).mpExtraArc =
       ((this->mDrawContext).mpBaseEmitter)->mpDataLinkInfo->mpExtraShapeBlock;
  (this->mDrawContext).mpSweepArc =
       ((this->mDrawContext).mpBaseEmitter)->mpDataLinkInfo->mpSweepShapeBlock;
  (this->mDrawContext).mpExTexShape =
       ((this->mDrawContext).mpBaseEmitter)->mpDataLinkInfo->mpExTexShapeBlock;
  (this->mDrawContext).mpDraw = this;
  (this->mDrawContext).mpTextureResource = pTexRes;
  *(int **)&this->field_0xb0 = ((this->mDrawContext).mpBaseEmitter)->mpDataLinkInfo->mpTDB1;
  (this->mDrawContext).mpActiveParticles = &((this->mDrawContext).mpBaseEmitter)->mActiveParticles;
  this->field_0xc2 = 0;
  this->mScaleOut = _2605;
  uVar2 = _2472;
  iVar3 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnablePrm)();
  uStack45 = (u8)uVar2;
  uStack46 = (u8)((uint)uVar2 >> 8);
  uStack47 = (u8)((uint)uVar2 >> 0x10);
  local_30 = (u8)((uint)uVar2 >> 0x18);
  if (iVar3 == 0) {
    (this->mPrmColor).r = local_30;
    (this->mPrmColor).g = uStack47;
    (this->mPrmColor).b = uStack46;
    (this->mPrmColor).a = uStack45;
  }
  else {
    iVar3 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnablePrmAnm)();
    if (iVar3 == 0) {
      uVar4 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getPrmColor)();
      local_34 = (u8)((uint)uVar4 >> 0x18);
      (this->mPrmColor).r = local_34;
      uStack51 = (u8)((uint)uVar4 >> 0x10);
      (this->mPrmColor).g = uStack51;
      uStack50 = (u8)((uint)uVar4 >> 8);
      (this->mPrmColor).b = uStack50;
      uStack49 = (u8)uVar4;
      (this->mPrmColor).a = uStack49;
    }
  }
  iVar3 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableEnv)();
  if (iVar3 == 0) {
    (this->mEnvColor).r = local_30;
    (this->mEnvColor).g = uStack47;
    (this->mEnvColor).b = uStack46;
    (this->mEnvColor).a = uStack45;
  }
  else {
    iVar3 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableEnvAnm)();
    if (iVar3 == 0) {
      uVar3 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getEnvColor)();
      local_38 = (u8)((uint)uVar3 >> 0x18);
      (this->mEnvColor).r = local_38;
      uStack55 = (u8)((uint)uVar3 >> 0x10);
      (this->mEnvColor).g = uStack55;
      uStack54 = (u8)((uint)uVar3 >> 8);
      (this->mEnvColor).b = uStack54;
      uStack53 = (u8)uVar3;
      (this->mEnvColor).a = uStack53;
    }
  }
  this->mCalcChldVisNum = 0;
  this->mCalcPtclVisNum = 0;
  this->mExecChldVisNum = 0;
  this->mExecPtclVisNum = 0;
  this->mCalcEmtrVisNum = 0;
  this->mExecEmtrCVisNum = 0;
  this->mExecEmtrPVisNum = 0;
  this->mExecEmtrVisNum = 0;
  this->mpExecEmtrVis[0] = (JPADrawExecEmitterVisitor *)0x0;
  iVar3 = 0;
  iVar6 = 5;
  do {
    *(undefined4 *)((int)this->mpExecEmtrPVis + iVar3) = 0;
    iVar3 = iVar3 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar3 = 0;
  iVar6 = 3;
  do {
    *(undefined4 *)((int)this->mpExecEmtrCVis + iVar3) = 0;
    iVar3 = iVar3 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar3 = 0;
  iVar6 = 4;
  do {
    *(undefined4 *)((int)this->mpCalcEmtrVis + iVar3) = 0;
    iVar3 = iVar3 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar3 = 0;
  iVar6 = 5;
  do {
    *(undefined4 *)((int)this->mpExecPtclVis + iVar3) = 0;
    iVar3 = iVar3 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar3 = 0;
  iVar6 = 4;
  do {
    *(undefined4 *)((int)this->mpExecChldVis + iVar3) = 0;
    iVar3 = iVar3 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar3 = 0;
  iVar6 = 10;
  do {
    *(undefined4 *)((int)this->mpCalcPtclVis + iVar3) = 0;
    iVar3 = iVar3 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar3 = 0;
  iVar6 = 2;
  do {
    *(undefined4 *)((int)this->mpCalcChldVis + iVar3) = 0;
    iVar3 = iVar3 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  flags.mbIsEnableDrawParent = 0;
  piVar4 = (int *)(this->mDrawContext).mpSweepArc;
  if ((piVar4 == (int *)0x0) || (iVar3 = (**(code **)(*piVar4 + 0x44))(), iVar3 != 0)) {
    flags.mbIsEnableDrawParent = 1;
  }
  flags.mbHasEnvPrm = 0;
  iVar3 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnablePrm)();
  if ((iVar3 != 0) &&
     (iVar3 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnablePrmAnm)(), iVar3 != 0)) {
    flags.mbHasEnvPrm = 1;
  }
  flags.mbHasEnvAnm = 0;
  iVar3 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableEnv)();
  if ((iVar3 != 0) &&
     (iVar3 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableEnvAnm)(), iVar3 != 0)) {
    flags.mbHasEnvAnm = 1;
  }
  flags.mbIsStripe = 0;
  cVar6 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)();
  if (cVar6 != 5) {
    cVar7 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)();
    if (cVar7 != 6) goto LAB_8026831c;
  }
  flags.mbIsStripe = 1;
LAB_8026831c:
  flags.mbIsPointOrLine = 0;
  cVar8 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)();
  if ((cVar8 == 0) ||
     (cVar9 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)(), cVar9 == 1)) {
    flags.mbIsPointOrLine = 1;
  }
  flags.mbIsEnableAlpha = 0;
  piVar4 = (int *)(this->mDrawContext).mpExtraArc;
  if ((piVar4 != (int *)0x0) && (iVar3 = (**(code **)(*piVar4 + 0x60))(), iVar3 != 0)) {
    flags.mbIsEnableAlpha = 1;
  }
  setDrawExecVisitorsBeforeCB(this,&flags);
  bVar1 = this->mExecEmtrPVisNum;
  this->mExecEmtrPVisNum = bVar1 + 1;
  this->mpExecEmtrPVis[bVar1] = (JPADrawExecEmitterVisitor *)0x803e8684;
  bVar1 = this->mExecEmtrCVisNum;
  this->mExecEmtrCVisNum = bVar1 + 1;
  this->mpExecEmtrCVis[bVar1] = (JPADrawExecEmitterVisitor *)0x803e8684;
  bVar1 = this->mExecPtclVisNum;
  this->mExecPtclVisNum = bVar1 + 1;
  this->mpExecPtclVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8688;
  bVar1 = this->mExecChldVisNum;
  this->mExecChldVisNum = bVar1 + 1;
  this->mpExecChldVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8688;
  setDrawExecVisitorsAfterCB(this,&flags);
  setDrawCalcVisitors(this,&flags);
  if (1 < this->mExecEmtrVisNum) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"JPADraw.cpp",0x65,"execEmtrVisNum <= 1");
    m_Do_printf::OSPanic("JPADraw.cpp",0x65,&DAT_80366a48);
  }
  if (5 < this->mExecEmtrPVisNum) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"JPADraw.cpp",0x66,"execEmtrPVisNum <= 5");
    m_Do_printf::OSPanic("JPADraw.cpp",0x66,&DAT_80366a48);
  }
  if (3 < this->mExecEmtrCVisNum) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"JPADraw.cpp",0x67,"execEmtrCVisNum <= 3");
    m_Do_printf::OSPanic("JPADraw.cpp",0x67,&DAT_80366a48);
  }
  if (4 < this->mCalcEmtrVisNum) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"JPADraw.cpp",0x68,"calcEmtrVisNum <= 4");
    m_Do_printf::OSPanic("JPADraw.cpp",0x68,&DAT_80366a48);
  }
  if (5 < this->mExecPtclVisNum) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"JPADraw.cpp",0x69,"execPtclVisNum <= 5");
    m_Do_printf::OSPanic("JPADraw.cpp",0x69,&DAT_80366a48);
  }
  if (4 < this->mExecChldVisNum) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"JPADraw.cpp",0x6a,"execChldVisNum <= 4");
    m_Do_printf::OSPanic("JPADraw.cpp",0x6a,&DAT_80366a48);
  }
  if (10 < this->mCalcPtclVisNum) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"JPADraw.cpp",0x6b,"calcPtclVisNum <= 10");
    m_Do_printf::OSPanic("JPADraw.cpp",0x6b,&DAT_80366a48);
  }
  if (2 < this->mCalcChldVisNum) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"JPADraw.cpp",0x6c,"calcChldVisNum <= 2");
    m_Do_printf::OSPanic("JPADraw.cpp",0x6c,&DAT_80366a48);
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JPADraw::draw(float *[][][][]) */

void __thiscall JPADraw::draw(JPADraw *this,MTX34 *pMtx)

{
  GXLogicOp GVar1;
  GXBlendFactor GVar2;
  GXBlendFactor GVar3;
  GXBlendMode GVar4;
  int *piVar5;
  JPABaseEmitter *pJVar6;
  int iVar7;
  int iVar8;
  
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,0);
  gx::GXSetCurrentMtx(0);
  gx::GXSetNumChans(0);
  gx::GXSetTevDirect(0);
  gx::GXSetTevDirect(1);
  gx::GXSetTevDirect(2);
  gx::GXSetCoPlanar(0);
  gx::GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  gx::GXSetChanCtrl(GX_COLOR1A1,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  GVar1 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getBlendOp1)();
  GVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getDstBlendFactor1)();
  GVar3 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getSrcBlendFactor1)();
  GVar4 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getBlendMode1)();
  gx::GXSetBlendMode(GVar4,GVar3,GVar2,GVar1);
  pJVar6 = (this->mDrawContext).mpBaseEmitter;
  cb.mGlobalPrmColor.r = (pJVar6->mGlobalPrmColor).r;
  cb.mGlobalPrmColor.g = (pJVar6->mGlobalPrmColor).g;
  cb.mGlobalPrmColor.b = (pJVar6->mGlobalPrmColor).b;
  cb.mGlobalPrmColor.a = (pJVar6->mGlobalPrmColor).a;
  cb.mGlobalEnvColor.r = (pJVar6->mGlobalEnvColor).r;
  cb.mGlobalEnvColor.g = (pJVar6->mGlobalEnvColor).g;
  cb.mGlobalEnvColor.b = (pJVar6->mGlobalEnvColor).b;
  cb.mGlobalEnvColor.a = (pJVar6->mGlobalEnvColor).a;
  cb.mpViewMtx = pMtx;
  ::JPADrawSetupTev::setupTev(&cb,(this->mDrawContext).mpBaseArc,(this->mDrawContext).mpExTexShape);
  iVar8 = 0;
  for (iVar7 = 0; iVar7 < (int)(uint)this->mExecEmtrVisNum; iVar7 = iVar7 + 1) {
    piVar5 = *(int **)((int)this->mpExecEmtrVis + iVar8);
    (**(code **)(*piVar5 + 0xc))(piVar5,&this->mDrawContext);
    iVar8 = iVar8 + 4;
  }
  iVar7 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableAnmTone)();
  if (iVar7 != 0) {
    zDraw(this);
  }
  this->field_0xc2 = this->field_0xc2 & 0xfe;
  iVar7 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getChildOrder)();
  if ((iVar7 != 0) && ((this->mDrawContext).mpSweepArc != (JPASweepShapeArc *)0x0)) {
    drawChild(this);
  }
  drawParticle(this);
  iVar7 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getChildOrder)();
  if ((iVar7 == 0) && ((this->mDrawContext).mpSweepArc != (JPASweepShapeArc *)0x0)) {
    drawChild(this);
  }
  gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_AND,GX_ALWAYS,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JPADraw::calc(void) */

void __thiscall JPADraw::calc(JPADraw *this)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  for (iVar2 = 0; iVar2 < (int)(uint)this->mCalcEmtrVisNum; iVar2 = iVar2 + 1) {
    piVar1 = *(int **)((int)this->mpCalcEmtrVis + iVar3);
    (**(code **)(*piVar1 + 0xc))(piVar1,&this->mDrawContext);
    iVar3 = iVar3 + 4;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JPADraw::calcParticle(JPABaseParticle *) */

void __thiscall JPADraw::calcParticle(JPADraw *this,JPABaseParticle *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  param_1->mRotateAngle = param_1->mRotateAngle + param_1->mRotateSpeed;
  iVar3 = 0;
  for (iVar2 = 0; iVar2 < (int)(uint)this->mCalcPtclVisNum; iVar2 = iVar2 + 1) {
    piVar1 = *(int **)((int)this->mpCalcPtclVis + iVar3);
    (**(code **)(*piVar1 + 0xc))(piVar1,&this->mDrawContext,param_1);
    iVar3 = iVar3 + 4;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JPADraw::calcChild(JPABaseParticle *) */

void __thiscall JPADraw::calcChild(JPADraw *this,JPABaseParticle *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  param_1->mRotateAngle = param_1->mRotateAngle + param_1->mRotateSpeed;
  iVar3 = 0;
  for (iVar2 = 0; iVar2 < (int)(uint)this->mCalcChldVisNum; iVar2 = iVar2 + 1) {
    piVar1 = *(int **)((int)this->mpCalcChldVis + iVar3);
    (**(code **)(*piVar1 + 0xc))(piVar1,&this->mDrawContext,param_1);
    iVar3 = iVar3 + 4;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x80268f08) */
/* __thiscall JPADraw::initParticle(JPABaseParticle *) */

void __thiscall JPADraw::initParticle(JPADraw *this,JPABaseParticle *pPtcl)

{
  float fVar1;
  float fVar2;
  short sVar5;
  int *piVar3;
  int iVar4;
  JPABaseEmitter *pJVar6;
  undefined4 uVar7;
  undefined8 in_f31;
  double dVar8;
  double dVar9;
  undefined auStack8 [8];
  
  fVar2 = JPABaseEmitter::emtrInfo.mEmitterGlobalRot.m[2][1];
  fVar1 = JPABaseEmitter::emtrInfo.mEmitterGlobalRot.m[1][1];
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  (pPtcl->mAxis).x = JPABaseEmitter::emtrInfo.mEmitterGlobalRot.m[0][1];
  (pPtcl->mAxis).y = fVar1;
  (pPtcl->mAxis).z = fVar2;
  (pPtcl->mPrmColor).r = (this->mPrmColor).r;
  (pPtcl->mPrmColor).g = (this->mPrmColor).g;
  (pPtcl->mPrmColor).b = (this->mPrmColor).b;
  (pPtcl->mPrmColor).a = (this->mPrmColor).a;
  (pPtcl->mEnvColor).r = (this->mEnvColor).r;
  (pPtcl->mEnvColor).g = (this->mEnvColor).g;
  (pPtcl->mEnvColor).b = (this->mEnvColor).b;
  (pPtcl->mEnvColor).a = (this->mEnvColor).a;
  fVar1 = _2605;
  pPtcl->mAlphaOut = _2605;
  pJVar6 = (this->mDrawContext).mpBaseEmitter;
  (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
  dVar8 = (double)((float)((pJVar6->mRandomSeed).v >> 9 | 0x3f800000) - fVar1);
  sVar5 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getLoopOffset)();
  pPtcl->mLoopOffset =
       (int)(dVar8 * (double)(float)((double)CONCAT44(0x43300000,(int)sVar5 ^ 0x80000000) - _2752));
  piVar3 = (int *)(this->mDrawContext).mpExtraArc;
  if (piVar3 == (int *)0x0) {
    pPtcl->mRotateAngle = 0;
    pPtcl->mRotateSpeed = 0;
    fVar1 = this->mScaleOut;
    pPtcl->mScaleY = fVar1;
    pPtcl->mScaleX = fVar1;
    pPtcl->mScaleOut = fVar1;
    pPtcl->mAlphaWaveRandom = _2605;
  }
  else {
    iVar4 = (**(code **)(*piVar3 + 0x94))();
    if (iVar4 == 0) {
      pPtcl->mRotateAngle = 0;
      pPtcl->mRotateSpeed = 0;
    }
    else {
      pJVar6 = (this->mDrawContext).mpBaseEmitter;
      (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
      dVar9 = (double)(((float)((pJVar6->mRandomSeed).v >> 9 | 0x3f800000) - _2605) - _2748);
      dVar8 = (double)(**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0xa0))();
      dVar9 = (double)(_2750 * (float)(dVar9 * dVar8));
      dVar8 = (double)(**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0x98))();
      pPtcl->mRotateAngle = (short)(int)((double)(float)((double)_2749 * dVar8) + dVar9);
      pJVar6 = (this->mDrawContext).mpBaseEmitter;
      (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
      fVar1 = (float)((pJVar6->mRandomSeed).v >> 9 | 0x3f800000) - _2605;
      dVar9 = (double)((fVar1 + fVar1) - _2605);
      dVar8 = (double)(**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0xa8))();
      if (dVar8 <= dVar9) {
        pJVar6 = (this->mDrawContext).mpBaseEmitter;
        (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
        fVar1 = (float)((pJVar6->mRandomSeed).v >> 9 | 0x3f800000) - _2605;
        dVar9 = (double)((fVar1 + fVar1) - _2605);
        dVar8 = (double)(**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0xa4))();
        dVar9 = (double)(_2605 + (float)(dVar8 * dVar9));
        dVar8 = (double)(**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0x9c))();
        sVar5 = (short)(int)(_2749 * (float)(-dVar8 * dVar9));
      }
      else {
        pJVar6 = (this->mDrawContext).mpBaseEmitter;
        (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
        fVar1 = (float)((pJVar6->mRandomSeed).v >> 9 | 0x3f800000) - _2605;
        dVar9 = (double)((fVar1 + fVar1) - _2605);
        dVar8 = (double)(**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0xa4))();
        dVar9 = (double)(_2605 + (float)(dVar8 * dVar9));
        dVar8 = (double)(**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0x9c))();
        sVar5 = (short)(int)(_2749 * (float)(dVar8 * dVar9));
      }
      pPtcl->mRotateSpeed = sVar5;
    }
    iVar4 = (**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0xc))();
    if (iVar4 == 0) {
      fVar1 = this->mScaleOut;
      pPtcl->mScaleOut = fVar1;
      pPtcl->mScaleY = fVar1;
      pPtcl->mScaleX = fVar1;
    }
    else {
      pJVar6 = (this->mDrawContext).mpBaseEmitter;
      (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
      fVar1 = (float)((pJVar6->mRandomSeed).v >> 9 | 0x3f800000) - _2605;
      dVar9 = (double)((fVar1 + fVar1) - _2605);
      dVar8 = (double)(**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0x5c))();
      fVar1 = this->mScaleOut * (_2605 + (float)(dVar9 * dVar8));
      pPtcl->mScaleOut = fVar1;
      pPtcl->mScaleY = fVar1;
      pPtcl->mScaleX = fVar1;
    }
    iVar4 = (**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0x60))();
    if (iVar4 == 0) {
      pPtcl->mAlphaWaveRandom = _2605;
    }
    else {
      pJVar6 = (this->mDrawContext).mpBaseEmitter;
      (pJVar6->mRandomSeed).v = (pJVar6->mRandomSeed).v * 0x19660d + 0x3c6ef35f;
      fVar1 = (float)((pJVar6->mRandomSeed).v >> 9 | 0x3f800000) - _2605;
      dVar9 = (double)((fVar1 + fVar1) - _2605);
      dVar8 = (double)(**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0x88))();
      pPtcl->mAlphaWaveRandom = _2605 + (float)(dVar9 * dVar8);
    }
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JPADraw::initChild(JPABaseParticle *,
                                 JPABaseParticle *) */

void __thiscall JPADraw::initChild(JPADraw *this,JPABaseParticle *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  u8 uVar4;
  double dVar5;
  double dVar6;
  u8 local_78;
  u8 uStack119;
  u8 uStack118;
  u8 uStack117;
  u8 local_74;
  u8 uStack115;
  u8 uStack114;
  u8 uStack113;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  
  (param_2->mAxis).x = (param_1->mAxis).x;
  (param_2->mAxis).y = (param_1->mAxis).y;
  (param_2->mAxis).z = (param_1->mAxis).z;
  param_2->mAlphaOut = _2605;
  iVar2 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x60))();
  if (iVar2 == 0) {
    uVar3 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x70))();
    local_74 = (u8)((uint)uVar3 >> 0x18);
    (param_2->mPrmColor).r = local_74;
    uStack115 = (u8)((uint)uVar3 >> 0x10);
    (param_2->mPrmColor).g = uStack115;
    uStack114 = (u8)((uint)uVar3 >> 8);
    (param_2->mPrmColor).b = uStack114;
    uStack113 = (u8)uVar3;
    (param_2->mPrmColor).a = uStack113;
    uVar3 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x74))();
    local_78 = (u8)((uint)uVar3 >> 0x18);
    (param_2->mEnvColor).r = local_78;
    uStack119 = (u8)((uint)uVar3 >> 0x10);
    (param_2->mEnvColor).g = uStack119;
    uStack118 = (u8)((uint)uVar3 >> 8);
    (param_2->mEnvColor).b = uStack118;
    uStack117 = (u8)uVar3;
    (param_2->mEnvColor).a = uStack117;
  }
  else {
    dVar5 = (double)(**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x8c))();
    dVar6 = _2796;
    (param_2->mPrmColor).r =
         (u8)(int)((double)(float)((double)CONCAT44(0x43300000,(uint)(param_1->mPrmColor).r) - _2796
                                  ) * dVar5);
    (param_2->mPrmColor).g =
         (u8)(int)((double)(float)((double)CONCAT44(0x43300000,(uint)(param_1->mPrmColor).g) - dVar6
                                  ) * dVar5);
    (param_2->mPrmColor).b =
         (u8)(int)((double)(float)((double)CONCAT44(0x43300000,(uint)(param_1->mPrmColor).b) - dVar6
                                  ) * dVar5);
    (param_2->mEnvColor).r =
         (u8)(int)((double)(float)((double)CONCAT44(0x43300000,(uint)(param_1->mEnvColor).r) - dVar6
                                  ) * dVar5);
    local_30 = (double)CONCAT44(0x43300000,(uint)(param_1->mEnvColor).g);
    (param_2->mEnvColor).g = (u8)(int)((double)(float)(local_30 - dVar6) * dVar5);
    local_20 = (double)CONCAT44(0x43300000,(uint)(param_1->mEnvColor).b);
    (param_2->mEnvColor).b = (u8)(int)((double)(float)(local_20 - dVar6) * dVar5);
  }
  iVar2 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x5c))();
  if (iVar2 == 0) {
    uVar4 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x78))();
    (param_2->mPrmColor).a = uVar4;
    uVar4 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x7c))();
    (param_2->mEnvColor).a = uVar4;
  }
  else {
    dVar5 = (double)(**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x88))();
    dVar6 = _2796;
    fVar1 = (float)((double)param_1->mAlphaOut * dVar5);
    local_18 = (double)CONCAT44(0x43300000,(uint)(param_1->mPrmColor).a);
    (param_2->mPrmColor).a = (u8)(int)((float)(local_18 - _2796) * fVar1);
    local_28 = (double)CONCAT44(0x43300000,(uint)(param_1->mEnvColor).a);
    (param_2->mEnvColor).a = (u8)(int)((float)(local_28 - dVar6) * fVar1);
  }
  iVar2 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x58))();
  fVar1 = _2605;
  if (iVar2 == 0) {
    param_2->mAlphaWaveRandom = _2605;
    param_2->mScaleY = fVar1;
    param_2->mScaleOut = fVar1;
    param_2->mScaleX = fVar1;
  }
  else {
    dVar6 = (double)(**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x84))();
    fVar1 = (float)(dVar6 * (double)param_1->mScaleX);
    param_2->mScaleOut = fVar1;
    param_2->mScaleX = fVar1;
    fVar1 = (float)(dVar6 * (double)param_1->mScaleY);
    param_2->mAlphaWaveRandom = fVar1;
    param_2->mScaleY = fVar1;
  }
  param_2->mRotateAngle = param_1->mRotateAngle;
  iVar2 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x54))();
  if (iVar2 == 0) {
    param_2->mRotateSpeed = 0;
  }
  else {
    dVar6 = (double)(**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x80))();
    param_2->mRotateSpeed = (short)(int)((double)_2749 * dVar6);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JPADraw::loadTexture(unsigned char,
                                   _GXTexMapID) */

undefined4 __thiscall JPADraw::loadTexture(JPADraw *this,byte tex_no,_GXTexMapID slot)

{
  ulong uVar1;
  JPATexture *pJVar2;
  
  if (((this->mDrawContext).mpBaseEmitter)->mpDataLinkInfo->mTextureNum <= tex_no) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar1,"JPADraw.cpp",0x17e,
               "dc.pbe->getEmitterDataBlockInfoPtr()->getTextureNum() > tex_no");
    m_Do_printf::OSPanic("JPADraw.cpp",0x17e,&DAT_80366a48);
  }
  pJVar2 = ((this->mDrawContext).mpTextureResource)->mpTexArray
           [*(ushort *)(*(int *)&this->field_0xb0 + (uint)tex_no * 2)];
  (**(code **)(pJVar2->vtbl + 0x10))(pJVar2,slot);
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x802699e8) */
/* WARNING: Removing unreachable block (ram,0x80269ba0) */
/* __thiscall JPADraw::setDrawExecVisitorsBeforeCB(JPADraw::JPADrawVisitorDefFlags const &) */

void __thiscall JPADraw::setDrawExecVisitorsBeforeCB(JPADraw *this,JPADrawVisitorDefFlags *pFlags)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  byte bVar4;
  char cVar5;
  
  if ((this->mDrawContext).mpExTexShape != (JPAExTexShapeArc *)0x0) {
    bVar4 = this->mExecEmtrVisNum;
    this->mExecEmtrVisNum = bVar4 + 1;
    this->mpExecEmtrVis[bVar4] = (JPADrawExecEmitterVisitor *)0x803e8644;
  }
  if (pFlags->mbIsPointOrLine == 0) {
    iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableProjection)();
    if (iVar2 == 0) {
      iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableTexScrollAnm)();
      if (iVar2 == 0) {
        bVar4 = this->mExecEmtrPVisNum;
        this->mExecEmtrPVisNum = bVar4 + 1;
        this->mpExecEmtrPVis[bVar4] = (JPADrawExecEmitterVisitor *)0x803e8600;
      }
      else {
        if (pFlags->mbIsStripe == 0) {
          bVar4 = this->mExecEmtrPVisNum;
          this->mExecEmtrPVisNum = bVar4 + 1;
          this->mpExecEmtrPVis[bVar4] = (JPADrawExecEmitterVisitor *)0x803e85fc;
        }
        else {
          bVar4 = this->mExecEmtrPVisNum;
          this->mExecEmtrPVisNum = bVar4 + 1;
          this->mpExecEmtrPVis[bVar4] = (JPADrawExecEmitterVisitor *)0x803e8604;
        }
      }
    }
    else {
      iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableTexScrollAnm)();
      if (iVar2 == 0) {
        bVar4 = this->mExecEmtrPVisNum;
        this->mExecEmtrPVisNum = bVar4 + 1;
        this->mpExecEmtrPVis[bVar4] = (JPADrawExecEmitterVisitor *)&vc;
      }
      else {
        bVar4 = this->mExecEmtrPVisNum;
        this->mExecEmtrPVisNum = bVar4 + 1;
        this->mpExecEmtrPVis[bVar4] = (JPADrawExecEmitterVisitor *)0x803e85f8;
      }
    }
  }
  else {
    bVar4 = this->mExecEmtrPVisNum;
    this->mExecEmtrPVisNum = bVar4 + 1;
    this->mpExecEmtrPVis[bVar4] = (JPADrawExecEmitterVisitor *)0x803e8600;
  }
  iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableGlobalColAnm)();
  if (iVar2 == 0) {
    iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnablePrm)();
    if (((iVar2 == 0) ||
        (iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnablePrmAnm)(), iVar2 == 0))
       && (pFlags->mbIsEnableAlpha == 0)) {
      iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableEnv)();
      if ((iVar2 == 0) ||
         (iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableEnvAnm)(), iVar2 == 0))
      {
        bVar4 = this->mExecEmtrPVisNum;
        this->mExecEmtrPVisNum = bVar4 + 1;
        this->mpExecEmtrPVis[bVar4] = (JPADrawExecEmitterVisitor *)0x803e8614;
      }
      else {
        bVar4 = this->mExecEmtrPVisNum;
        this->mExecEmtrPVisNum = bVar4 + 1;
        this->mpExecEmtrPVis[bVar4] = (JPADrawExecEmitterVisitor *)0x803e8618;
      }
    }
    else {
      iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableEnv)();
      if ((iVar2 == 0) ||
         (iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableEnvAnm)(), iVar2 == 0))
      {
        bVar4 = this->mExecEmtrPVisNum;
        this->mExecEmtrPVisNum = bVar4 + 1;
        this->mpExecEmtrPVis[bVar4] = (JPADrawExecEmitterVisitor *)0x803e861c;
      }
    }
  }
  else {
    if ((pFlags->mbIsStripe != 0) || (bVar1 = pFlags->mbIsEnableAlpha == 0, bVar1)) {
      bVar4 = this->mExecEmtrPVisNum;
      this->mExecEmtrPVisNum = bVar4 + 1;
      this->mpExecEmtrPVis[bVar4] = (JPADrawExecEmitterVisitor *)0x803e8614;
    }
    else {
      if (!bVar1) {
        bVar4 = this->mExecEmtrPVisNum;
        this->mExecEmtrPVisNum = bVar4 + 1;
        this->mpExecEmtrPVis[bVar4] = (JPADrawExecEmitterVisitor *)0x803e861c;
      }
    }
  }
  iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->textureIsEmpty)();
  if ((iVar2 == 0) &&
     ((iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableTextureAnm)(), iVar2 == 0
      || (iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableGlobalTexAnm)(),
         iVar2 != 0)))) {
    bVar4 = this->mExecEmtrPVisNum;
    this->mExecEmtrPVisNum = bVar4 + 1;
    this->mpExecEmtrPVis[bVar4] = (JPADrawExecEmitterVisitor *)0x803e863c;
  }
  else {
    iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->textureIsEmpty)();
    if (iVar2 != 0) {
      bVar4 = this->mExecEmtrPVisNum;
      this->mExecEmtrPVisNum = bVar4 + 1;
      this->mpExecEmtrPVis[bVar4] = (JPADrawExecEmitterVisitor *)0x803e8638;
    }
  }
  piVar3 = (int *)(this->mDrawContext).mpSweepArc;
  if ((((piVar3 != (int *)0x0) && (iVar2 = (**(code **)(*piVar3 + 0x50))(), iVar2 == 0)) &&
      (iVar2 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x5c))(), iVar2 == 0)) &&
     (iVar2 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x60))(), iVar2 == 0)) {
    bVar4 = this->mExecEmtrCVisNum;
    this->mExecEmtrCVisNum = bVar4 + 1;
    this->mpExecEmtrCVis[bVar4] = (JPADrawExecEmitterVisitor *)0x803e8620;
  }
  iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableGlobalColAnm)();
  if (iVar2 == 0) {
    if (pFlags->mbHasEnvPrm == 0) {
      if (pFlags->mbIsEnableAlpha == 0) {
        if (pFlags->mbHasEnvAnm != 0) {
          bVar4 = this->mExecPtclVisNum;
          this->mExecPtclVisNum = bVar4 + 1;
          this->mpExecPtclVis[bVar4] = (JPADrawExecParticleVisitor *)0x803e862c;
        }
      }
      else {
        if (pFlags->mbHasEnvAnm == 0) {
          bVar4 = this->mExecPtclVisNum;
          this->mExecPtclVisNum = bVar4 + 1;
          this->mpExecPtclVis[bVar4] = (JPADrawExecParticleVisitor *)0x803e8628;
        }
        else {
          bVar4 = this->mExecPtclVisNum;
          this->mExecPtclVisNum = bVar4 + 1;
          this->mpExecPtclVis[bVar4] = (JPADrawExecParticleVisitor *)0x803e8634;
        }
      }
    }
    else {
      if (pFlags->mbHasEnvAnm == 0) {
        bVar4 = this->mExecPtclVisNum;
        this->mExecPtclVisNum = bVar4 + 1;
        this->mpExecPtclVis[bVar4] = (JPADrawExecParticleVisitor *)0x803e8624;
      }
      else {
        bVar4 = this->mExecPtclVisNum;
        this->mExecPtclVisNum = bVar4 + 1;
        this->mpExecPtclVis[bVar4] = (JPADrawExecParticleVisitor *)0x803e8630;
      }
    }
  }
  else {
    if ((pFlags->mbIsEnableAlpha != 0) && (pFlags->mbIsStripe == 0)) {
      bVar4 = this->mExecPtclVisNum;
      this->mExecPtclVisNum = bVar4 + 1;
      this->mpExecPtclVis[bVar4] = (JPADrawExecParticleVisitor *)0x803e8628;
    }
  }
  iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->textureIsEmpty)();
  if (((iVar2 == 0) &&
      (iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableTextureAnm)(), iVar2 != 0))
     && (iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableGlobalTexAnm)(),
        iVar2 == 0)) {
    bVar4 = this->mExecPtclVisNum;
    this->mExecPtclVisNum = bVar4 + 1;
    this->mpExecPtclVis[bVar4] = (JPADrawExecParticleVisitor *)0x803e8640;
  }
  bVar4 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)();
  if (bVar4 < 5) {
    if (bVar4 == 1) {
      piVar3 = (int *)(this->mDrawContext).mpExtraArc;
      if ((piVar3 != (int *)0x0) && (iVar2 = (**(code **)(*piVar3 + 0xc))(), iVar2 != 0)) {
        bVar4 = this->mExecPtclVisNum;
        this->mExecPtclVisNum = bVar4 + 1;
        this->mpExecPtclVis[bVar4] = (JPADrawExecParticleVisitor *)0x803e8610;
      }
      goto LAB_80269af4;
    }
    if (bVar4 == 0) {
      piVar3 = (int *)(this->mDrawContext).mpExtraArc;
      if ((piVar3 != (int *)0x0) && (iVar2 = (**(code **)(*piVar3 + 0xc))(), iVar2 != 0)) {
        bVar4 = this->mExecPtclVisNum;
        this->mExecPtclVisNum = bVar4 + 1;
        this->mpExecPtclVis[bVar4] = (JPADrawExecParticleVisitor *)0x803e860c;
      }
      goto LAB_80269af4;
    }
  }
  else {
    if ((10 < bVar4) || (bVar4 < 7)) goto LAB_80269af4;
  }
  iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableTexScrollAnm)();
  if ((iVar2 != 0) &&
     (iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableProjection)(), iVar2 == 0))
  {
    bVar4 = this->mExecPtclVisNum;
    this->mExecPtclVisNum = bVar4 + 1;
    this->mpExecPtclVis[bVar4] = (JPADrawExecParticleVisitor *)0x803e8608;
  }
LAB_80269af4:
  piVar3 = (int *)(this->mDrawContext).mpSweepArc;
  if (piVar3 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar3 + 0x50))();
    if (((iVar2 != 0) ||
        (iVar2 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x5c))(), iVar2 != 0)) ||
       (iVar2 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x60))(), iVar2 != 0)) {
      bVar4 = this->mExecChldVisNum;
      this->mExecChldVisNum = bVar4 + 1;
      this->mpExecChldVis[bVar4] = (JPADrawExecParticleVisitor *)0x803e8630;
    }
    cVar5 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0xc))();
    if (cVar5 == '\x01') {
      bVar4 = this->mExecChldVisNum;
      this->mExecChldVisNum = bVar4 + 1;
      this->mpExecChldVis[bVar4] = (JPADrawExecParticleVisitor *)0x803e8610;
    }
    else {
      if (cVar5 == '\0') {
        bVar4 = this->mExecChldVisNum;
        this->mExecChldVisNum = bVar4 + 1;
        this->mpExecChldVis[bVar4] = (JPADrawExecParticleVisitor *)0x803e860c;
      }
    }
  }
  return;
}


/* __thiscall JPADraw::setDrawExecVisitorsAfterCB(JPADraw::JPADrawVisitorDefFlags const &) */

void __thiscall JPADraw::setDrawExecVisitorsAfterCB(JPADraw *this,JPADrawVisitorDefFlags *param_1)

{
  byte bVar1;
  undefined uVar4;
  int *piVar2;
  int iVar3;
  
  if (param_1->mbIsEnableDrawParent != 0) {
    uVar4 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)();
    switch(uVar4) {
    case 0:
      bVar1 = this->mExecPtclVisNum;
      this->mExecPtclVisNum = bVar1 + 1;
      this->mpExecPtclVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8674;
      break;
    case 1:
      bVar1 = this->mExecPtclVisNum;
      this->mExecPtclVisNum = bVar1 + 1;
      this->mpExecPtclVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8678;
      break;
    case 2:
      piVar2 = (int *)(this->mDrawContext).mpExtraArc;
      if ((piVar2 == (int *)0x0) || (iVar3 = (**(code **)(*piVar2 + 0x94))(), iVar3 == 0)) {
        bVar1 = this->mExecPtclVisNum;
        this->mExecPtclVisNum = bVar1 + 1;
        this->mpExecPtclVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8648;
      }
      else {
        bVar1 = this->mExecPtclVisNum;
        this->mExecPtclVisNum = bVar1 + 1;
        this->mpExecPtclVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e864c;
      }
      break;
    case 3:
      piVar2 = (int *)(this->mDrawContext).mpExtraArc;
      if ((piVar2 == (int *)0x0) || (iVar3 = (**(code **)(*piVar2 + 0x94))(), iVar3 == 0)) {
        bVar1 = this->mExecPtclVisNum;
        this->mExecPtclVisNum = bVar1 + 1;
        this->mpExecPtclVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8658;
      }
      else {
        bVar1 = this->mExecPtclVisNum;
        this->mExecPtclVisNum = bVar1 + 1;
        this->mpExecPtclVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e865c;
      }
      break;
    case 4:
      piVar2 = (int *)(this->mDrawContext).mpExtraArc;
      if ((piVar2 == (int *)0x0) || (iVar3 = (**(code **)(*piVar2 + 0x94))(), iVar3 == 0)) {
        bVar1 = this->mExecPtclVisNum;
        this->mExecPtclVisNum = bVar1 + 1;
        this->mpExecPtclVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8660;
      }
      else {
        bVar1 = this->mExecPtclVisNum;
        this->mExecPtclVisNum = bVar1 + 1;
        this->mpExecPtclVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8664;
      }
      break;
    case 5:
      bVar1 = this->mExecEmtrPVisNum;
      this->mExecEmtrPVisNum = bVar1 + 1;
      this->mpExecEmtrPVis[bVar1] = (JPADrawExecEmitterVisitor *)0x803e867c;
      break;
    case 6:
      bVar1 = this->mExecEmtrPVisNum;
      this->mExecEmtrPVisNum = bVar1 + 1;
      this->mpExecEmtrPVis[bVar1] = (JPADrawExecEmitterVisitor *)0x803e8680;
      break;
    case 7:
      bVar1 = this->mExecPtclVisNum;
      this->mExecPtclVisNum = bVar1 + 1;
      this->mpExecPtclVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e866c;
      break;
    case 8:
      bVar1 = this->mExecPtclVisNum;
      this->mExecPtclVisNum = bVar1 + 1;
      this->mpExecPtclVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8670;
      break;
    case 9:
      bVar1 = this->mExecPtclVisNum;
      this->mExecPtclVisNum = bVar1 + 1;
      this->mpExecPtclVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8668;
      break;
    case 10:
      piVar2 = (int *)(this->mDrawContext).mpExtraArc;
      if ((piVar2 == (int *)0x0) || (iVar3 = (**(code **)(*piVar2 + 0x94))(), iVar3 == 0)) {
        bVar1 = this->mExecPtclVisNum;
        this->mExecPtclVisNum = bVar1 + 1;
        this->mpExecPtclVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8650;
      }
      else {
        bVar1 = this->mExecPtclVisNum;
        this->mExecPtclVisNum = bVar1 + 1;
        this->mpExecPtclVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8654;
      }
    }
  }
  piVar2 = (int *)(this->mDrawContext).mpSweepArc;
  if (piVar2 != (int *)0x0) {
    uVar4 = (**(code **)(*piVar2 + 0xc))();
    switch(uVar4) {
    case 0:
      bVar1 = this->mExecChldVisNum;
      this->mExecChldVisNum = bVar1 + 1;
      this->mpExecChldVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8674;
      break;
    case 1:
      bVar1 = this->mExecChldVisNum;
      this->mExecChldVisNum = bVar1 + 1;
      this->mpExecChldVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8678;
      break;
    case 2:
      piVar2 = (int *)(this->mDrawContext).mpExtraArc;
      if (((piVar2 == (int *)0x0) || (iVar3 = (**(code **)(*piVar2 + 0x94))(), iVar3 == 0)) &&
         (iVar3 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x54))(), iVar3 == 0)) {
        bVar1 = this->mExecChldVisNum;
        this->mExecChldVisNum = bVar1 + 1;
        this->mpExecChldVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8648;
      }
      else {
        bVar1 = this->mExecChldVisNum;
        this->mExecChldVisNum = bVar1 + 1;
        this->mpExecChldVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e864c;
      }
      break;
    case 3:
      piVar2 = (int *)(this->mDrawContext).mpExtraArc;
      if (((piVar2 == (int *)0x0) || (iVar3 = (**(code **)(*piVar2 + 0x94))(), iVar3 == 0)) &&
         (iVar3 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x54))(), iVar3 == 0)) {
        bVar1 = this->mExecChldVisNum;
        this->mExecChldVisNum = bVar1 + 1;
        this->mpExecChldVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8658;
      }
      else {
        bVar1 = this->mExecChldVisNum;
        this->mExecChldVisNum = bVar1 + 1;
        this->mpExecChldVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e865c;
      }
      break;
    case 4:
      piVar2 = (int *)(this->mDrawContext).mpExtraArc;
      if (((piVar2 == (int *)0x0) || (iVar3 = (**(code **)(*piVar2 + 0x94))(), iVar3 == 0)) &&
         (iVar3 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x54))(), iVar3 == 0)) {
        bVar1 = this->mExecChldVisNum;
        this->mExecChldVisNum = bVar1 + 1;
        this->mpExecChldVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8660;
      }
      else {
        bVar1 = this->mExecChldVisNum;
        this->mExecChldVisNum = bVar1 + 1;
        this->mpExecChldVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8664;
      }
      break;
    case 5:
      bVar1 = this->mExecEmtrCVisNum;
      this->mExecEmtrCVisNum = bVar1 + 1;
      this->mpExecEmtrCVis[bVar1] = (JPADrawExecEmitterVisitor *)0x803e867c;
      break;
    case 6:
      bVar1 = this->mExecEmtrCVisNum;
      this->mExecEmtrCVisNum = bVar1 + 1;
      this->mpExecEmtrCVis[bVar1] = (JPADrawExecEmitterVisitor *)0x803e8680;
      break;
    case 7:
      bVar1 = this->mExecChldVisNum;
      this->mExecChldVisNum = bVar1 + 1;
      this->mpExecChldVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e866c;
      break;
    case 8:
      bVar1 = this->mExecChldVisNum;
      this->mExecChldVisNum = bVar1 + 1;
      this->mpExecChldVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8670;
      break;
    case 9:
      bVar1 = this->mExecChldVisNum;
      this->mExecChldVisNum = bVar1 + 1;
      this->mpExecChldVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8668;
      break;
    case 10:
      piVar2 = (int *)(this->mDrawContext).mpExtraArc;
      if (((piVar2 == (int *)0x0) || (iVar3 = (**(code **)(*piVar2 + 0x94))(), iVar3 == 0)) &&
         (iVar3 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x54))(), iVar3 == 0)) {
        bVar1 = this->mExecChldVisNum;
        this->mExecChldVisNum = bVar1 + 1;
        this->mpExecChldVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8650;
      }
      else {
        bVar1 = this->mExecChldVisNum;
        this->mExecChldVisNum = bVar1 + 1;
        this->mpExecChldVis[bVar1] = (JPADrawExecParticleVisitor *)0x803e8654;
      }
    }
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x8026ab30) */
/* WARNING: Removing unreachable block (ram,0x8026a528) */
/* WARNING: Removing unreachable block (ram,0x8026a36c) */
/* WARNING: Removing unreachable block (ram,0x8026a94c) */
/* WARNING: Removing unreachable block (ram,0x8026ac38) */
/* __thiscall JPADraw::setDrawCalcVisitors(JPADraw::JPADrawVisitorDefFlags const &) */

void __thiscall JPADraw::setDrawCalcVisitors(JPADraw *this,JPADrawVisitorDefFlags *pFlags)

{
  int iVar1;
  byte bVar3;
  int *piVar2;
  char cVar4;
  
  iVar1 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableGlobalColAnm)();
  if ((iVar1 != 0) && ((pFlags->mbHasEnvPrm != 0 || (pFlags->mbHasEnvAnm != 0)))) {
    bVar3 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getColorRegAnmType)();
    if (bVar3 == 2) {
      bVar3 = this->mCalcEmtrVisNum;
      this->mCalcEmtrVisNum = bVar3 + 1;
      this->mpCalcEmtrVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86d8;
    }
    else {
      if (bVar3 < 2) {
        if (bVar3 == 0) {
          bVar3 = this->mCalcEmtrVisNum;
          this->mCalcEmtrVisNum = bVar3 + 1;
          this->mpCalcEmtrVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86c8;
        }
        else {
          bVar3 = this->mCalcEmtrVisNum;
          this->mCalcEmtrVisNum = bVar3 + 1;
          this->mpCalcEmtrVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86d0;
        }
      }
      else {
        if (bVar3 == 4) {
          bVar3 = this->mCalcEmtrVisNum;
          this->mCalcEmtrVisNum = bVar3 + 1;
          this->mpCalcEmtrVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86e8;
        }
        else {
          if (bVar3 < 4) {
            bVar3 = this->mCalcEmtrVisNum;
            this->mCalcEmtrVisNum = bVar3 + 1;
            this->mpCalcEmtrVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86e0;
          }
        }
      }
    }
    if (pFlags->mbHasEnvPrm != 0) {
      bVar3 = this->mCalcEmtrVisNum;
      this->mCalcEmtrVisNum = bVar3 + 1;
      this->mpCalcEmtrVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86b4;
    }
    if (pFlags->mbHasEnvAnm != 0) {
      bVar3 = this->mCalcEmtrVisNum;
      this->mCalcEmtrVisNum = bVar3 + 1;
      this->mpCalcEmtrVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86bc;
    }
  }
  iVar1 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->textureIsEmpty)();
  if (((iVar1 == 0) &&
      (iVar1 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableTextureAnm)(), iVar1 != 0))
     && (iVar1 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableGlobalTexAnm)(),
        iVar1 != 0)) {
    bVar3 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getTextureAnmType)();
    if (bVar3 == 2) {
      bVar3 = this->mCalcEmtrVisNum;
      this->mCalcEmtrVisNum = bVar3 + 1;
      this->mpCalcEmtrVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e8710;
    }
    else {
      if (bVar3 < 2) {
        if (bVar3 == 0) {
          bVar3 = this->mCalcEmtrVisNum;
          this->mCalcEmtrVisNum = bVar3 + 1;
          this->mpCalcEmtrVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e8700;
        }
        else {
          bVar3 = this->mCalcEmtrVisNum;
          this->mCalcEmtrVisNum = bVar3 + 1;
          this->mpCalcEmtrVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e8708;
        }
      }
      else {
        if (bVar3 == 4) {
          bVar3 = this->mCalcEmtrVisNum;
          this->mCalcEmtrVisNum = bVar3 + 1;
          this->mpCalcEmtrVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e8720;
        }
        else {
          if (bVar3 < 4) {
            bVar3 = this->mCalcEmtrVisNum;
            this->mCalcEmtrVisNum = bVar3 + 1;
            this->mpCalcEmtrVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e8718;
          }
        }
      }
    }
  }
  piVar2 = (int *)(this->mDrawContext).mpExtraArc;
  if ((piVar2 != (int *)0x0) && (iVar1 = (**(code **)(*piVar2 + 0xc))(), iVar1 != 0)) {
    iVar1 = (**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0x14))();
    if (iVar1 == 0) {
      bVar3 = this->mCalcPtclVisNum;
      this->mCalcPtclVisNum = bVar3 + 1;
      this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86a0;
    }
    else {
      cVar4 = (**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0x34))();
      if (cVar4 == '\0') {
        bVar3 = this->mCalcPtclVisNum;
        this->mCalcPtclVisNum = bVar3 + 1;
        this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86a4;
      }
      else {
        bVar3 = this->mCalcPtclVisNum;
        this->mCalcPtclVisNum = bVar3 + 1;
        this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86ac;
      }
    }
    iVar1 = (**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0x1c))();
    if ((iVar1 == 0) ||
       (cVar4 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)(), cVar4 == '\x01')) {
      bVar3 = this->mCalcPtclVisNum;
      this->mCalcPtclVisNum = bVar3 + 1;
      this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e868c;
    }
    else {
      bVar3 = this->mCalcPtclVisNum;
      this->mCalcPtclVisNum = bVar3 + 1;
      this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e8690;
    }
    cVar4 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)();
    if (cVar4 != '\0') {
      iVar1 = (**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0x10))();
      if (iVar1 == 0) {
        bVar3 = this->mCalcPtclVisNum;
        this->mCalcPtclVisNum = bVar3 + 1;
        this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e869c;
      }
      else {
        iVar1 = (**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0x18))();
        if (iVar1 == 0) {
          iVar1 = (**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0x14))();
          if (iVar1 != 0) {
            bVar3 = this->mCalcPtclVisNum;
            this->mCalcPtclVisNum = bVar3 + 1;
            this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86a0;
          }
        }
        else {
          cVar4 = (**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0x38))();
          if (cVar4 == '\0') {
            bVar3 = this->mCalcPtclVisNum;
            this->mCalcPtclVisNum = bVar3 + 1;
            this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86a8;
          }
          else {
            bVar3 = this->mCalcPtclVisNum;
            this->mCalcPtclVisNum = bVar3 + 1;
            this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86b0;
          }
        }
        iVar1 = (**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0x20))();
        if (iVar1 == 0) {
          bVar3 = this->mCalcPtclVisNum;
          this->mCalcPtclVisNum = bVar3 + 1;
          this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e8694;
        }
        else {
          bVar3 = this->mCalcPtclVisNum;
          this->mCalcPtclVisNum = bVar3 + 1;
          this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e8698;
        }
      }
    }
  }
  iVar1 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableGlobalColAnm)();
  if (iVar1 == 0) {
    if ((pFlags->mbHasEnvPrm != 0) || (pFlags->mbHasEnvAnm != 0)) {
      bVar3 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getColorRegAnmType)();
      if (bVar3 == 2) {
        bVar3 = this->mCalcPtclVisNum;
        this->mCalcPtclVisNum = bVar3 + 1;
        this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86dc;
      }
      else {
        if (bVar3 < 2) {
          if (bVar3 == 0) {
            bVar3 = this->mCalcPtclVisNum;
            this->mCalcPtclVisNum = bVar3 + 1;
            this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86cc;
          }
          else {
            bVar3 = this->mCalcPtclVisNum;
            this->mCalcPtclVisNum = bVar3 + 1;
            this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86d4;
          }
        }
        else {
          if (bVar3 == 4) {
            bVar3 = this->mCalcPtclVisNum;
            this->mCalcPtclVisNum = bVar3 + 1;
            this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86ec;
          }
          else {
            if (bVar3 < 4) {
              bVar3 = this->mCalcPtclVisNum;
              this->mCalcPtclVisNum = bVar3 + 1;
              this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86e4;
            }
          }
        }
      }
      if (pFlags->mbHasEnvPrm != 0) {
        bVar3 = this->mCalcPtclVisNum;
        this->mCalcPtclVisNum = bVar3 + 1;
        this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86b8;
      }
      if (pFlags->mbHasEnvAnm != 0) {
        bVar3 = this->mCalcPtclVisNum;
        this->mCalcPtclVisNum = bVar3 + 1;
        this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86c0;
      }
    }
  }
  else {
    bVar3 = this->mCalcPtclVisNum;
    this->mCalcPtclVisNum = bVar3 + 1;
    this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86c4;
  }
  if ((pFlags->mbIsEnableAlpha != 0) && (pFlags->mbIsStripe == 0)) {
    bVar3 = this->mCalcPtclVisNum;
    this->mCalcPtclVisNum = bVar3 + 1;
    this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86f0;
    iVar1 = (**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 100))();
    if (iVar1 != 0) {
      bVar3 = (**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0x78))();
      if (bVar3 == 1) {
        bVar3 = this->mCalcPtclVisNum;
        this->mCalcPtclVisNum = bVar3 + 1;
        this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86f8;
      }
      else {
        if (bVar3 == 0) {
          bVar3 = this->mCalcPtclVisNum;
          this->mCalcPtclVisNum = bVar3 + 1;
          this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86f4;
        }
        else {
          if (bVar3 < 3) {
            bVar3 = this->mCalcPtclVisNum;
            this->mCalcPtclVisNum = bVar3 + 1;
            this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e86fc;
          }
        }
      }
    }
  }
  iVar1 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->textureIsEmpty)();
  if (((iVar1 == 0) &&
      (iVar1 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableTextureAnm)(), iVar1 != 0))
     && (iVar1 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableGlobalTexAnm)(),
        iVar1 == 0)) {
    bVar3 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getTextureAnmType)();
    if (bVar3 == 2) {
      bVar3 = this->mCalcPtclVisNum;
      this->mCalcPtclVisNum = bVar3 + 1;
      this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e8714;
    }
    else {
      if (bVar3 < 2) {
        if (bVar3 == 0) {
          bVar3 = this->mCalcPtclVisNum;
          this->mCalcPtclVisNum = bVar3 + 1;
          this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e8704;
        }
        else {
          bVar3 = this->mCalcPtclVisNum;
          this->mCalcPtclVisNum = bVar3 + 1;
          this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e870c;
        }
      }
      else {
        if (bVar3 == 4) {
          bVar3 = this->mCalcPtclVisNum;
          this->mCalcPtclVisNum = bVar3 + 1;
          this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e8724;
        }
        else {
          if (bVar3 < 4) {
            bVar3 = this->mCalcPtclVisNum;
            this->mCalcPtclVisNum = bVar3 + 1;
            this->mpCalcPtclVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e871c;
          }
        }
      }
    }
  }
  piVar2 = (int *)(this->mDrawContext).mpSweepArc;
  if (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 0x50))();
    if (iVar1 != 0) {
      bVar3 = this->mCalcChldVisNum;
      this->mCalcChldVisNum = bVar3 + 1;
      this->mpCalcChldVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e8728;
    }
    iVar1 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x4c))();
    if (iVar1 != 0) {
      bVar3 = this->mCalcChldVisNum;
      this->mCalcChldVisNum = bVar3 + 1;
      this->mpCalcChldVis[bVar3] = (JPADrawExecParticleVisitor *)0x803e872c;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8026b3b4) */
/* WARNING: Removing unreachable block (ram,0x8026b2c8) */
/* WARNING: Removing unreachable block (ram,0x8026b1b8) */
/* WARNING: Removing unreachable block (ram,0x8026b394) */
/* WARNING: Removing unreachable block (ram,0x8026b3bc) */
/* __thiscall JPADraw::setParticleClipBoard(void) */

void __thiscall JPADraw::setParticleClipBoard(JPADraw *this)

{
  byte bVar5;
  JPABaseEmitter *pJVar1;
  char cVar6;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar7;
  double baseSizeX;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  bVar5 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)();
  if (bVar5 == 9) {
LAB_8026ae14:
    mtx::PSMTXIdentity(&cb.mViewMtx);
  }
  else {
    if (bVar5 < 9) {
      if (bVar5 == 2) goto LAB_8026ae14;
    }
    else {
      if (bVar5 < 0xb) {
        loadYBBMtx(this,cb.mpViewMtx);
        goto LAB_8026ae54;
      }
    }
    mtx::PSMTXCopy(cb.mpViewMtx,&cb.mViewMtx);
  }
LAB_8026ae54:
  gx::GXLoadPosMtxImm(&cb.mViewMtx,0);
  pJVar1 = (this->mDrawContext).mpBaseEmitter;
  dVar9 = (double)(pJVar1->mGlobalScale2D).x;
  dVar8 = (double)(pJVar1->mGlobalScale2D).y;
  baseSizeX = (double)(*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getBaseSizeX)();
  cb.mGlobalScale2D[0] = (float)(dVar9 * (double)(float)((double)_3193 * baseSizeX));
  baseSizeX = (double)(*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getBaseSizeY)();
  cb.mGlobalScale2D[1] = (float)(dVar8 * (double)(float)((double)_3193 * baseSizeX));
  cVar6 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)();
  if (cVar6 == '\0') {
    cb.mGlobalScale2D[0] = cb.mGlobalScale2D[0] * _3194;
    cb.mGlobalScale2D[1] = cb.mGlobalScale2D[1] * _3194;
  }
  else {
    cVar6 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)();
    if (cVar6 == '\x01') {
      cb.mGlobalScale2D[0] = cb.mGlobalScale2D[0] * _3194;
      cb.mGlobalScale2D[1] = cb.mGlobalScale2D[1] * _3195;
    }
  }
  piVar2 = (int *)(this->mDrawContext).mpExtraArc;
  if ((piVar2 == (int *)0x0) || (iVar3 = (**(code **)(*piVar2 + 0xc))(), iVar3 == 0)) {
    cb.mPivotY = _3196;
    cb.mPivotX = _3196;
  }
  else {
    uVar4 = (**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0x54))();
    cb.mPivotX = cb.mGlobalScale2D[0] *
                 ((float)((double)CONCAT44(0x43300000,uVar4 & 0xff) - _2796) - _2605);
    uVar4 = (**(code **)(*(int *)(this->mDrawContext).mpExtraArc + 0x58))();
    cb.mPivotY = cb.mGlobalScale2D[1] *
                 ((float)((double)CONCAT44(0x43300000,uVar4 & 0xff) - _2796) - _2605);
  }
  baseSizeX = (double)(*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getTilingX)();
  dVar8 = (double)(*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getTilingY)();
  cb.mTexCoordPoints[0].x = _3196;
  cb.mTexCoordPoints[0].y = _3196;
  cb.mTexCoordPoints[1].x = (float)baseSizeX;
  cb.mTexCoordPoints[1].y = _3196;
  cb.mTexCoordPoints[2].x = (float)baseSizeX;
  cb.mTexCoordPoints[2].y = (float)dVar8;
  cb.mTexCoordPoints[3].x = _3196;
  cb.mTexCoordPoints[3].y = (float)dVar8;
  iVar3 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->textureIsEmpty)();
  if ((iVar3 == 0) &&
     (iVar3 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableTextureAnm)(), iVar3 == 0))
  {
    uVar4 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getTextureIndex)();
    this->mTexIdx = *(short *)(*(int *)&this->field_0xb0 + (uVar4 & 0xff) * 2);
  }
  cb.mpDirTypeFunc = (undefined *)0x0;
  cb.mpRotTypeFunc = (undefined *)0x0;
  cb.mpBasePlaneTypeFunc = (undefined *)0x0;
  cVar6 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)();
  if ((((cVar6 == '\x03') ||
       (cVar6 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)(), cVar6 == '\x04')) ||
      (cVar6 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)(), cVar6 == '\t')) ||
     ((cVar6 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)(), cVar6 == '\x05' ||
      (cVar6 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)(), cVar6 == '\x06')))) {
    bVar5 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getDirType)();
    if (bVar5 == 2) {
      cb.mpDirTypeFunc = dirTypePosInv;
    }
    else {
      if (bVar5 < 2) {
        if (bVar5 == 0) {
          cb.mpDirTypeFunc = dirTypeVel;
        }
        else {
          cb.mpDirTypeFunc = dirTypePos;
        }
      }
      else {
        if (bVar5 == 4) {
          cb.mpDirTypeFunc = dirTypePrevPtcl;
        }
        else {
          if (bVar5 < 4) {
            cb.mpDirTypeFunc = dirTypeEmtrDir;
          }
        }
      }
    }
  }
  cVar6 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)();
  if (((cVar6 == '\x03') ||
      (cVar6 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)(), cVar6 == '\x04')) ||
     ((cVar6 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)(), cVar6 == '\a' ||
      (cVar6 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)(), cVar6 == '\b')))) {
    bVar5 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getRotType)();
    if (bVar5 == 2) {
      cb.mpRotTypeFunc = rotTypeZ;
    }
    else {
      if (bVar5 < 2) {
        if (bVar5 == 0) {
          cb.mpRotTypeFunc = rotTypeY;
        }
        else {
          cb.mpRotTypeFunc = rotTypeX;
        }
      }
      else {
        if (bVar5 == 4) {
          cb.mpRotTypeFunc = rotTypeYJiggle;
        }
        else {
          if (bVar5 < 4) {
            cb.mpRotTypeFunc = rotTypeXYZ;
          }
        }
      }
    }
  }
  cVar6 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)();
  if ((cVar6 == '\x03') ||
     (cVar6 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getType)(), cVar6 == '\a')) {
    cVar6 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getBasePlaneType)();
    if (cVar6 == '\x01') {
      cb.mpBasePlaneTypeFunc = basePlaneTypeXZ;
    }
    else {
      if (cVar6 == '\0') {
        cb.mpBasePlaneTypeFunc = basePlaneTypeXY;
      }
    }
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8026b910) */
/* WARNING: Removing unreachable block (ram,0x8026b824) */
/* WARNING: Removing unreachable block (ram,0x8026b714) */
/* WARNING: Removing unreachable block (ram,0x8026b8f0) */
/* WARNING: Removing unreachable block (ram,0x8026b918) */
/* __thiscall JPADraw::setChildClipBoard(void) */

void __thiscall JPADraw::setChildClipBoard(JPADraw *this)

{
  byte bVar3;
  JPABaseEmitter *pJVar1;
  int iVar2;
  char cVar4;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f30;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  bVar3 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0xc))();
  if (bVar3 == 9) {
LAB_8026b440:
    mtx::PSMTXIdentity(&cb.mViewMtx);
  }
  else {
    if (bVar3 < 9) {
      if (bVar3 == 2) goto LAB_8026b440;
    }
    else {
      if (bVar3 < 0xb) {
        loadYBBMtx(this,cb.mpViewMtx);
        goto LAB_8026b480;
      }
    }
    mtx::PSMTXCopy(cb.mpViewMtx,&cb.mViewMtx);
  }
LAB_8026b480:
  gx::GXLoadPosMtxImm(&cb.mViewMtx,0);
  pJVar1 = (this->mDrawContext).mpBaseEmitter;
  dVar8 = (double)(pJVar1->mGlobalScale2D).x;
  dVar7 = (double)(pJVar1->mGlobalScale2D).y;
  iVar2 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x58))();
  if (iVar2 == 0) {
    dVar6 = (double)(**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x68))();
    cb.mGlobalScale2D[0] = (float)(dVar8 * (double)(float)((double)_3193 * dVar6));
    dVar8 = (double)(**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x6c))();
    dVar7 = dVar7 * (double)(float)((double)_3193 * dVar8);
  }
  else {
    dVar6 = (double)(*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getBaseSizeX)();
    cb.mGlobalScale2D[0] = (float)(dVar8 * (double)(float)((double)_3193 * dVar6));
    dVar8 = (double)(*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getBaseSizeY)();
    dVar7 = dVar7 * (double)(float)((double)_3193 * dVar8);
  }
  cb.mGlobalScale2D[1] = (float)dVar7;
  cVar4 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0xc))();
  if (cVar4 == '\0') {
    cb.mGlobalScale2D[0] = cb.mGlobalScale2D[0] * _3194;
    cb.mGlobalScale2D[1] = cb.mGlobalScale2D[1] * _3194;
  }
  else {
    cVar4 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0xc))();
    if (cVar4 == '\x01') {
      cb.mGlobalScale2D[0] = cb.mGlobalScale2D[0] * _3194;
      cb.mGlobalScale2D[1] = cb.mGlobalScale2D[1] * _3195;
    }
  }
  cb.mPivotY = _3196;
  cb.mPivotX = _3196;
  cb.mTexCoordPoints[1].y = _3196;
  cb.mTexCoordPoints[0].y = _3196;
  cb.mTexCoordPoints[3].x = _3196;
  cb.mTexCoordPoints[0].x = _3196;
  cb.mTexCoordPoints[3].y = _2605;
  cb.mTexCoordPoints[2].y = _2605;
  cb.mTexCoordPoints[2].x = _2605;
  cb.mTexCoordPoints[1].x = _2605;
  cb.mpDirTypeFunc = (undefined *)0x0;
  cb.mpRotTypeFunc = (undefined *)0x0;
  cb.mpBasePlaneTypeFunc = (undefined *)0x0;
  cVar4 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0xc))();
  if ((((cVar4 == '\x03') ||
       (cVar4 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0xc))(), cVar4 == '\x04')) ||
      (cVar4 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0xc))(), cVar4 == '\t')) ||
     ((cVar4 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0xc))(), cVar4 == '\x05' ||
      (cVar4 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0xc))(), cVar4 == '\x06')))) {
    bVar3 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x10))();
    if (bVar3 == 2) {
      cb.mpDirTypeFunc = dirTypePosInv;
    }
    else {
      if (bVar3 < 2) {
        if (bVar3 == 0) {
          cb.mpDirTypeFunc = dirTypeVel;
        }
        else {
          cb.mpDirTypeFunc = dirTypePos;
        }
      }
      else {
        if (bVar3 == 4) {
          cb.mpDirTypeFunc = dirTypePrevPtcl;
        }
        else {
          if (bVar3 < 4) {
            cb.mpDirTypeFunc = dirTypeEmtrDir;
          }
        }
      }
    }
  }
  cVar4 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0xc))();
  if (((cVar4 == '\x03') ||
      (cVar4 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0xc))(), cVar4 == '\x04')) ||
     ((cVar4 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0xc))(), cVar4 == '\a' ||
      (cVar4 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0xc))(), cVar4 == '\b')))) {
    bVar3 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x14))();
    if (bVar3 == 2) {
      cb.mpRotTypeFunc = rotTypeZ;
    }
    else {
      if (bVar3 < 2) {
        if (bVar3 == 0) {
          cb.mpRotTypeFunc = rotTypeY;
        }
        else {
          cb.mpRotTypeFunc = rotTypeX;
        }
      }
      else {
        if (bVar3 == 4) {
          cb.mpRotTypeFunc = rotTypeYJiggle;
        }
        else {
          if (bVar3 < 4) {
            cb.mpRotTypeFunc = rotTypeXYZ;
          }
        }
      }
    }
  }
  cVar4 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0xc))();
  if ((cVar4 == '\x03') ||
     (cVar4 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0xc))(), cVar4 == '\a')) {
    cVar4 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x18))();
    if (cVar4 == '\x01') {
      cb.mpBasePlaneTypeFunc = basePlaneTypeXZ;
    }
    else {
      if (cVar4 == '\0') {
        cb.mpBasePlaneTypeFunc = basePlaneTypeXY;
      }
    }
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JPADraw::drawParticle(void) */

void __thiscall JPADraw::drawParticle(JPADraw *this)

{
  bool bVar6;
  GXCompare GVar1;
  bool bVar7;
  byte bVar8;
  GXAlphaOp GVar2;
  byte bVar9;
  GXCompare GVar3;
  int iVar4;
  int *piVar5;
  JSUPtrLink *pJVar10;
  JPABaseParticle *pParticle;
  JPABaseParticle *pParticle_;
  int iVar11;
  JPABaseEmitter *pJVar12;
  
  this->field_0xc2 = this->field_0xc2 & 0xfd;
  setParticleClipBoard(this);
  (this->mDrawContext).mpActiveParticles = &((this->mDrawContext).mpBaseEmitter)->mActiveParticles;
  gx::GXSetPointSize((int)cb.mGlobalScale2D[0],5);
  gx::GXSetLineWidth((int)cb.mGlobalScale2D[0],5);
  bVar6 = (bool)(*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableZCmpUpdate)();
  GVar1 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getZCmpFunction)();
  bVar7 = (bool)(*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableZCmp)();
  gx::GXSetZMode(bVar7,GVar1,bVar6);
  (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getZCompLoc)();
  gx::GXSetZCompLoc();
  bVar8 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getAlphaCmpRef1)();
  GVar1 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getAlphaCmpComp1)();
  GVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getAlphaCmpOp)();
  bVar9 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getAlphaCmpRef0)();
  GVar3 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getAlphaCmpComp0)();
  gx::GXSetAlphaCompare(GVar3,bVar9,GVar2,GVar1,bVar8);
  (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableAlphaUpdate)();
  gx::GXSetAlphaUpdate();
  gx::GXSetColorUpdate(true);
  gx::GXSetCullMode(0);
  iVar4 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isClipOn)();
  if (iVar4 == 0) {
    gx::GXSetClipMode(true);
  }
  else {
    gx::GXSetClipMode(false);
    gx::GXSetMisc(1,8);
  }
  iVar11 = 0;
  for (iVar4 = 0; iVar4 < (int)(uint)this->mExecEmtrPVisNum; iVar4 = iVar4 + 1) {
    piVar5 = *(int **)((int)this->mpExecEmtrPVis + iVar11);
    (**(code **)(*piVar5 + 0xc))(piVar5,&this->mDrawContext);
    iVar11 = iVar11 + 4;
  }
  pJVar12 = (this->mDrawContext).mpBaseEmitter;
  iVar4 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getListOrder)();
  if (iVar4 == 0) {
    for (pJVar10 = (pJVar12->mActiveParticles).mpHead; pJVar10 != (JSUPtrLink *)0x0;
        pJVar10 = pJVar10->mpNext) {
      pParticle = (JPABaseParticle *)pJVar10->mpData;
      iVar11 = 0;
      for (iVar4 = 0; iVar4 < (int)(uint)this->mExecPtclVisNum; iVar4 = iVar4 + 1) {
        piVar5 = *(int **)((int)this->mpExecPtclVis + iVar11);
        (**(code **)(*piVar5 + 0xc))(piVar5,&this->mDrawContext,pParticle);
        iVar11 = iVar11 + 4;
      }
    }
  }
  else {
    for (pJVar10 = (pJVar12->mActiveParticles).mpTail; pJVar10 != (JSUPtrLink *)0x0;
        pJVar10 = pJVar10->mpPrev) {
      pParticle_ = (JPABaseParticle *)pJVar10->mpData;
      iVar11 = 0;
      for (iVar4 = 0; iVar4 < (int)(uint)this->mExecPtclVisNum; iVar4 = iVar4 + 1) {
        piVar5 = *(int **)((int)this->mpExecPtclVis + iVar11);
        (**(code **)(*piVar5 + 0xc))(piVar5,&this->mDrawContext,pParticle_);
        iVar11 = iVar11 + 4;
      }
    }
  }
  gx::GXSetMisc(1,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JPADraw::drawChild(void) */

void __thiscall JPADraw::drawChild(JPADraw *this)

{
  int iVar1;
  uint uVar2;
  JPATexture *pJVar3;
  bool bVar8;
  GXCompare GVar4;
  bool bVar9;
  byte bVar10;
  GXAlphaOp GVar5;
  byte bVar11;
  GXCompare GVar6;
  int *piVar7;
  JSUPtrLink *pJVar12;
  undefined *puVar13;
  int iVar14;
  JPABaseEmitter *pJVar15;
  
  this->field_0xc2 = this->field_0xc2 | 2;
  setChildClipBoard(this);
  (this->mDrawContext).mpActiveParticles = &((this->mDrawContext).mpBaseEmitter)->mChildParticles;
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXEnableTexOffsets(0,1,1);
  iVar1 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->textureIsEmpty)();
  if (iVar1 == 0) {
    uVar2 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 100))();
    pJVar3 = ((this->mDrawContext).mpTextureResource)->mpTexArray
             [*(ushort *)(*(int *)&this->field_0xb0 + (uVar2 & 0xff) * 2)];
    (**(code **)(pJVar3->vtbl + 0x10))(pJVar3,0);
  }
  else {
    gx::GXLoadTexObj((GXTexObj *)
                     &(((this->mDrawContext).mpTextureResource)->mDefaultTexture).mTexObj,0);
  }
  bVar8 = (bool)(*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableZCmpUpdate)();
  GVar4 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getZCmpFunction)();
  bVar9 = (bool)(*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableZCmp)();
  gx::GXSetZMode(bVar9,GVar4,bVar8);
  (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getZCompLoc)();
  gx::GXSetZCompLoc();
  bVar10 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getAlphaCmpRef1)();
  GVar4 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getAlphaCmpComp1)();
  GVar5 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getAlphaCmpOp)();
  bVar11 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getAlphaCmpRef0)();
  GVar6 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getAlphaCmpComp0)();
  gx::GXSetAlphaCompare(GVar6,bVar11,GVar5,GVar4,bVar10);
  (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isEnableAlphaUpdate)();
  gx::GXSetAlphaUpdate();
  gx::GXSetColorUpdate(true);
  gx::GXSetCullMode(0);
  iVar1 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x48))();
  if (iVar1 == 0) {
    gx::GXSetClipMode(true);
  }
  else {
    gx::GXSetClipMode(false);
    gx::GXSetMisc(1,8);
  }
  iVar14 = 0;
  for (iVar1 = 0; iVar1 < (int)(uint)this->mExecEmtrCVisNum; iVar1 = iVar1 + 1) {
    piVar7 = *(int **)((int)this->mpExecEmtrCVis + iVar14);
    (**(code **)(*piVar7 + 0xc))(piVar7,&this->mDrawContext);
    iVar14 = iVar14 + 4;
  }
  pJVar15 = (this->mDrawContext).mpBaseEmitter;
  iVar1 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getListOrder)();
  if (iVar1 == 0) {
    for (pJVar12 = (pJVar15->mChildParticles).mpHead; pJVar12 != (JSUPtrLink *)0x0;
        pJVar12 = pJVar12->mpNext) {
      puVar13 = pJVar12->mpData;
      iVar14 = 0;
      for (iVar1 = 0; iVar1 < (int)(uint)this->mExecChldVisNum; iVar1 = iVar1 + 1) {
        piVar7 = *(int **)((int)this->mpExecChldVis + iVar14);
        (**(code **)(*piVar7 + 0xc))(piVar7,&this->mDrawContext,puVar13);
        iVar14 = iVar14 + 4;
      }
    }
  }
  else {
    for (pJVar12 = (pJVar15->mChildParticles).mpTail; pJVar12 != (JSUPtrLink *)0x0;
        pJVar12 = pJVar12->mpPrev) {
      puVar13 = pJVar12->mpData;
      iVar14 = 0;
      for (iVar1 = 0; iVar1 < (int)(uint)this->mExecChldVisNum; iVar1 = iVar1 + 1) {
        piVar7 = *(int **)((int)this->mpExecChldVis + iVar14);
        (**(code **)(*piVar7 + 0xc))(piVar7,&this->mDrawContext,puVar13);
        iVar14 = iVar14 + 4;
      }
    }
  }
  gx::GXSetMisc(1,0);
  return;
}


/* __thiscall JPADraw::zDraw(void) */

void __thiscall JPADraw::zDraw(JPADraw *this)

{
  int iVar1;
  
  this->field_0xc2 = this->field_0xc2 | 1;
  iVar1 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getChildOrder)();
  if ((iVar1 != 0) && ((this->mDrawContext).mpSweepArc != (JPASweepShapeArc *)0x0)) {
    zDrawChild(this);
  }
  zDrawParticle(this);
  iVar1 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getChildOrder)();
  if ((iVar1 == 0) && ((this->mDrawContext).mpSweepArc != (JPASweepShapeArc *)0x0)) {
    zDrawChild(this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JPADraw::zDrawParticle(void) */

void __thiscall JPADraw::zDrawParticle(JPADraw *this)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  undefined *puVar4;
  JSUPtrLink *pJVar5;
  int iVar6;
  JPABaseEmitter *pJVar7;
  
  this->field_0xc2 = this->field_0xc2 & 0xfd;
  setParticleClipBoard(this);
  (this->mDrawContext).mpActiveParticles = &((this->mDrawContext).mpBaseEmitter)->mActiveParticles;
  gx::GXSetPointSize((int)cb.mGlobalScale2D[0],5);
  gx::GXSetLineWidth((int)cb.mGlobalScale2D[0],5);
  gx::GXSetZMode(true,GX_LEQUAL,true);
  gx::GXSetZCompLoc(0);
  bVar1 = (((this->mDrawContext).mpBaseEmitter)->mGlobalPrmColor).a;
  gx::GXSetAlphaCompare(GX_GEQUAL,bVar1,GX_AOP_OR,GX_GEQUAL,bVar1);
  gx::GXSetAlphaUpdate(0);
  gx::GXSetColorUpdate(false);
  gx::GXSetCullMode(0);
  iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->isClipOn)();
  if (iVar2 == 0) {
    gx::GXSetClipMode(true);
  }
  else {
    gx::GXSetClipMode(false);
    gx::GXSetMisc(1,8);
  }
  iVar6 = 0;
  for (iVar2 = 0; iVar2 < (int)(uint)this->mExecEmtrPVisNum; iVar2 = iVar2 + 1) {
    piVar3 = *(int **)((int)this->mpExecEmtrPVis + iVar6);
    (**(code **)(*piVar3 + 0xc))(piVar3,&this->mDrawContext);
    iVar6 = iVar6 + 4;
  }
  pJVar7 = (this->mDrawContext).mpBaseEmitter;
  iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getListOrder)();
  if (iVar2 == 0) {
    for (pJVar5 = (pJVar7->mActiveParticles).mpHead; pJVar5 != (JSUPtrLink *)0x0;
        pJVar5 = pJVar5->mpNext) {
      puVar4 = pJVar5->mpData;
      iVar6 = 0;
      for (iVar2 = 0; iVar2 < (int)(uint)this->mExecPtclVisNum; iVar2 = iVar2 + 1) {
        piVar3 = *(int **)((int)this->mpExecPtclVis + iVar6);
        (**(code **)(*piVar3 + 0xc))(piVar3,&this->mDrawContext,puVar4);
        iVar6 = iVar6 + 4;
      }
    }
  }
  else {
    for (pJVar5 = (pJVar7->mActiveParticles).mpTail; pJVar5 != (JSUPtrLink *)0x0;
        pJVar5 = pJVar5->mpPrev) {
      puVar4 = pJVar5->mpData;
      iVar6 = 0;
      for (iVar2 = 0; iVar2 < (int)(uint)this->mExecPtclVisNum; iVar2 = iVar2 + 1) {
        piVar3 = *(int **)((int)this->mpExecPtclVis + iVar6);
        (**(code **)(*piVar3 + 0xc))(piVar3,&this->mDrawContext,puVar4);
        iVar6 = iVar6 + 4;
      }
    }
  }
  gx::GXSetMisc(1,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JPADraw::zDrawChild(void) */

void __thiscall JPADraw::zDrawChild(JPADraw *this)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  JPATexture *pJVar4;
  int *piVar5;
  undefined *puVar6;
  JSUPtrLink *pJVar7;
  int iVar8;
  JPABaseEmitter *pJVar9;
  
  this->field_0xc2 = this->field_0xc2 | 2;
  setChildClipBoard(this);
  (this->mDrawContext).mpActiveParticles = &((this->mDrawContext).mpBaseEmitter)->mChildParticles;
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXEnableTexOffsets(0,1,1);
  iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->textureIsEmpty)();
  if (iVar2 == 0) {
    uVar3 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 100))();
    pJVar4 = ((this->mDrawContext).mpTextureResource)->mpTexArray
             [*(ushort *)(*(int *)&this->field_0xb0 + (uVar3 & 0xff) * 2)];
    (**(code **)(pJVar4->vtbl + 0x10))(pJVar4,0);
  }
  else {
    gx::GXLoadTexObj((GXTexObj *)
                     &(((this->mDrawContext).mpTextureResource)->mDefaultTexture).mTexObj,0);
  }
  gx::GXSetZMode(true,GX_LEQUAL,true);
  gx::GXSetZCompLoc(0);
  bVar1 = (((this->mDrawContext).mpBaseEmitter)->mGlobalPrmColor).a;
  gx::GXSetAlphaCompare(GX_GEQUAL,bVar1,GX_AOP_OR,GX_GEQUAL,bVar1);
  gx::GXSetAlphaUpdate(0);
  gx::GXSetColorUpdate(false);
  gx::GXSetCullMode(0);
  iVar2 = (**(code **)(*(int *)(this->mDrawContext).mpSweepArc + 0x48))();
  if (iVar2 == 0) {
    gx::GXSetClipMode(true);
  }
  else {
    gx::GXSetClipMode(false);
    gx::GXSetMisc(1,8);
  }
  iVar8 = 0;
  for (iVar2 = 0; iVar2 < (int)(uint)this->mExecEmtrCVisNum; iVar2 = iVar2 + 1) {
    piVar5 = *(int **)((int)this->mpExecEmtrCVis + iVar8);
    (**(code **)(*piVar5 + 0xc))(piVar5,&this->mDrawContext);
    iVar8 = iVar8 + 4;
  }
  pJVar9 = (this->mDrawContext).mpBaseEmitter;
  iVar2 = (*(code *)((this->mDrawContext).mpBaseArc)->vtbl->getListOrder)();
  if (iVar2 == 0) {
    for (pJVar7 = (pJVar9->mChildParticles).mpHead; pJVar7 != (JSUPtrLink *)0x0;
        pJVar7 = pJVar7->mpNext) {
      puVar6 = pJVar7->mpData;
      iVar8 = 0;
      for (iVar2 = 0; iVar2 < (int)(uint)this->mExecChldVisNum; iVar2 = iVar2 + 1) {
        piVar5 = *(int **)((int)this->mpExecChldVis + iVar8);
        (**(code **)(*piVar5 + 0xc))(piVar5,&this->mDrawContext,puVar6);
        iVar8 = iVar8 + 4;
      }
    }
  }
  else {
    for (pJVar7 = (pJVar9->mChildParticles).mpTail; pJVar7 != (JSUPtrLink *)0x0;
        pJVar7 = pJVar7->mpPrev) {
      puVar6 = pJVar7->mpData;
      iVar8 = 0;
      for (iVar2 = 0; iVar2 < (int)(uint)this->mExecChldVisNum; iVar2 = iVar2 + 1) {
        piVar5 = *(int **)((int)this->mpExecChldVis + iVar8);
        (**(code **)(*piVar5 + 0xc))(piVar5,&this->mDrawContext,puVar6);
        iVar8 = iVar8 + 4;
      }
    }
  }
  gx::GXSetMisc(1,0);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8026c61c) */
/* WARNING: Removing unreachable block (ram,0x8026c614) */
/* WARNING: Removing unreachable block (ram,0x8026c624) */
/* __thiscall JPADraw::loadYBBMtx(float *[][][][]) */

void __thiscall JPADraw::loadYBBMtx(JPADraw *this,MTX34 *param_1)

{
  float fVar1;
  ulong uVar2;
  undefined4 uVar3;
  undefined8 in_f29;
  double dVar4;
  undefined8 in_f30;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  dVar6 = (double)param_1->m[1][1];
  dVar5 = (double)param_1->m[2][1];
  dVar4 = (double)((float)(dVar5 * dVar5) + _3196 + (float)(dVar6 * dVar6));
  if (dVar4 <= (double)_3601) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JPADraw.cpp",0x596,"!v.isZero()");
    m_Do_printf::OSPanic("JPADraw.cpp",0x596,&DAT_80366a48);
  }
  if ((double)_3601 < dVar4) {
    if ((double)_3196 < dVar4) {
      fVar1 = (float)(1.0 / SQRT(dVar4));
      dVar4 = (double)(_2748 * fVar1 * (_3602 - (float)(dVar4 * (double)(fVar1 * fVar1))));
    }
    dVar6 = (double)(float)(dVar6 * dVar4);
    dVar5 = (double)(float)(dVar5 * dVar4);
  }
  cb._56_4_ = _2605;
  cb._60_4_ = _3196;
  cb._64_4_ = _3196;
  cb._68_4_ = param_1->m[3];
  cb._72_4_ = _3196;
  cb._76_4_ = (float)dVar6;
  cb._80_4_ = (float)-dVar5;
  cb._84_4_ = param_1->m[1][3];
  cb._88_4_ = _3196;
  cb._92_4_ = (float)dVar5;
  cb._96_4_ = (float)dVar6;
  cb._100_4_ = param_1->m[2][3];
  mtx::PSMTXIdentity(&cb.mViewMtx);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  return;
}


namespace JPADraw {

void __sinit_JPADraw_cpp(void)

{
  ::JPADrawVisitorContainer::JPADrawVisitorContainer(&vc);
  Runtime.PPCEABI.H::__register_global_object();
  Runtime.PPCEABI.H::__construct_array
            (cb.mTexCoordPoints,JGeometry::TVec2<float><float>::TVec2,(undefined *)0x0,8,4);
  Runtime.PPCEABI.H::__register_global_object(&cb,::JPADrawClipBoard::_JPADrawClipBoard,&_2468);
  return;
}

}

/* __thiscall JPADrawClipBoard::~JPADrawClipBoard(void) */

void __thiscall JPADrawClipBoard::_JPADrawClipBoard(JPADrawClipBoard *this)

{
  short in_r4;
  
  if ((this != (JPADrawClipBoard *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace JGeometry {

/* __thiscall TVec2<float><float>::TVec2<float,undefined,undefined>(void) */

void __thiscall TVec2<float><float>::TVec2(TVec2_float__float_ *this)

{
  return;
}

}

/* __thiscall JPADrawVisitorContainer::~JPADrawVisitorContainer(void) */

void __thiscall JPADrawVisitorContainer::_JPADrawVisitorContainer(JPADrawVisitorContainer *this)

{
  short in_r4;
  
  if (this != (JPADrawVisitorContainer *)0x0) {
    if (this != (JPADrawVisitorContainer *)0xfffffec8) {
      (this->mpCalcChildScaleOut).vtbl = &JPADrawCalcChildScaleOut::__vt;
      if (this != (JPADrawVisitorContainer *)0xfffffec8) {
        (this->mpCalcChildScaleOut).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xfffffecc) {
      (this->mpCalcChildAlphaOut).vtbl = &JPADrawCalcChildAlphaOut::__vt;
      if (this != (JPADrawVisitorContainer *)0xfffffecc) {
        (this->mpCalcChildAlphaOut).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xfffffed4) {
      (this->mpCalcTextureAnmIndexRandom).vtbl = &JPADrawCalcTextureAnmIndexRandom::__vt;
      (this->mpCalcTextureAnmIndexRandomP).vtbl = &DAT_803967ac;
      if (this != (JPADrawVisitorContainer *)0xfffffed0) {
        (this->mpCalcTextureAnmIndexRandomP).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
      if (this != (JPADrawVisitorContainer *)0xfffffed4) {
        (this->mpCalcTextureAnmIndexRandom).vtbl = &JPADrawCalcEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xfffffedc) {
      (this->mpCalcTextureAnmIndexMerge).vtbl = &JPADrawCalcTextureAnmIndexMerge::__vt;
      (this->mpCalcTextureAnmIndexMergeP).vtbl = &DAT_803967e0;
      if (this != (JPADrawVisitorContainer *)0xfffffed8) {
        (this->mpCalcTextureAnmIndexMergeP).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
      if (this != (JPADrawVisitorContainer *)0xfffffedc) {
        (this->mpCalcTextureAnmIndexMerge).vtbl = &JPADrawCalcEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xfffffee4) {
      (this->mpCalcTextureAnmIndexReverse).vtbl = &JPADrawCalcTextureAnmIndexReverse::__vt;
      (this->mpCalcTextureAnmIndexReverseP).vtbl = &DAT_80396804;
      if (this != (JPADrawVisitorContainer *)0xfffffee0) {
        (this->mpCalcTextureAnmIndexReverseP).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
      if (this != (JPADrawVisitorContainer *)0xfffffee4) {
        (this->mpCalcTextureAnmIndexReverse).vtbl = &JPADrawCalcEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xfffffeec) {
      (this->mpCalcTextureAnmIndexRepeat).vtbl = &JPADrawCalcTextureAnmIndexRepeat::__vt;
      (this->mpCalcTextureAnmIndexRepeatP).vtbl = &DAT_80396828;
      if (this != (JPADrawVisitorContainer *)0xfffffee8) {
        (this->mpCalcTextureAnmIndexRepeatP).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
      if (this != (JPADrawVisitorContainer *)0xfffffeec) {
        (this->mpCalcTextureAnmIndexRepeat).vtbl = &JPADrawCalcEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xfffffef4) {
      (this->mpCalcTextureAnmIndexNormal).vtbl = &JPADrawCalcTextureAnmIndexNormal::__vt;
      (this->mpCalcTextureAnmIndexNormalP).vtbl = &DAT_8039684c;
      if (this != (JPADrawVisitorContainer *)0xfffffef0) {
        (this->mpCalcTextureAnmIndexNormalP).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
      if (this != (JPADrawVisitorContainer *)0xfffffef4) {
        (this->mpCalcTextureAnmIndexNormal).vtbl = &JPADrawCalcEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xfffffef8) {
      (this->mpCalcAlphaFlickMultSin).vtbl = &JPADrawCalcAlphaFlickMultSin::__vt;
      if (this != (JPADrawVisitorContainer *)0xfffffef8) {
        (this->mpCalcAlphaFlickMultSin).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xfffffefc) {
      (this->mpCalcAlphaFlickAddSin).vtbl = &JPADrawCalcAlphaFlickAddSin::__vt;
      if (this != (JPADrawVisitorContainer *)0xfffffefc) {
        (this->mpCalcAlphaFlickAddSin).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff00) {
      (this->mpCalcAlphaFlickNrmSin).vtbl = &JPADrawCalcAlphaFlickNrmSin::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff00) {
        (this->mpCalcAlphaFlickNrmSin).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff04) {
      (this->mpCalcAlpha).vtbl = &JPADrawCalcAlpha::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff04) {
        (this->mpCalcAlpha).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff0c) {
      (this->mpCalcColorAnmFrameRandom).vtbl = &JPADrawCalcColorAnmFrameRandom::__vt;
      (this->mpCalcColorAnmFrameRandomP).vtbl = &DAT_80396870;
      if (this != (JPADrawVisitorContainer *)0xffffff08) {
        (this->mpCalcColorAnmFrameRandomP).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
      if (this != (JPADrawVisitorContainer *)0xffffff0c) {
        (this->mpCalcColorAnmFrameRandom).vtbl = &JPADrawCalcEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff14) {
      (this->mpCalcColorAnmFrameMerge).vtbl = &JPADrawCalcColorAnmFrameMerge::__vt;
      (this->mpCalcColorAnmFrameMergeP).vtbl = &DAT_80396894;
      if (this != (JPADrawVisitorContainer *)0xffffff10) {
        (this->mpCalcColorAnmFrameMergeP).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
      if (this != (JPADrawVisitorContainer *)0xffffff14) {
        (this->mpCalcColorAnmFrameMerge).vtbl = &JPADrawCalcEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff1c) {
      (this->mpCalcColorAnmFrameReverse).vtbl = &JPADrawCalcColorAnmFrameReverse::__vt;
      (this->mpCalcColorAnmFrameReverseP).vtbl = &DAT_803968b8;
      if (this != (JPADrawVisitorContainer *)0xffffff18) {
        (this->mpCalcColorAnmFrameReverseP).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
      if (this != (JPADrawVisitorContainer *)0xffffff1c) {
        (this->mpCalcColorAnmFrameReverse).vtbl = &JPADrawCalcEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff24) {
      (this->mpCalcColorAnmFrameRepeat).vtbl = &JPADrawCalcColorAnmFrameRepeat::__vt;
      (this->mpCalcColorAnmFrameRepeatP).vtbl = &DAT_803968dc;
      if (this != (JPADrawVisitorContainer *)0xffffff20) {
        (this->mpCalcColorAnmFrameRepeatP).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
      if (this != (JPADrawVisitorContainer *)0xffffff24) {
        (this->mpCalcColorAnmFrameRepeat).vtbl = &JPADrawCalcEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff2c) {
      (this->mpCalcColorAnmFrameNormal).vtbl = &JPADrawCalcColorAnmFrameNormal::__vt;
      (this->mpCalcColorAnmFrameNormalP).vtbl = &DAT_80396900;
      if (this != (JPADrawVisitorContainer *)0xffffff28) {
        (this->mpCalcColorAnmFrameNormalP).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
      if (this != (JPADrawVisitorContainer *)0xffffff2c) {
        (this->mpCalcColorAnmFrameNormal).vtbl = &JPADrawCalcEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff30) {
      (this->mpCalcColorCopyFromEmitter).vtbl = &JPADrawCalcColorCopyFromEmitter::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff30) {
        (this->mpCalcColorCopyFromEmitter).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff38) {
      (this->mpCalcColorEnv).vtbl = &JPADrawCalcColorEnv::__vt;
      (this->mpCalcColorEnvP).vtbl = &DAT_80396924;
      if (this != (JPADrawVisitorContainer *)0xffffff34) {
        (this->mpCalcColorEnvP).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
      if (this != (JPADrawVisitorContainer *)0xffffff38) {
        (this->mpCalcColorEnv).vtbl = &JPADrawCalcEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff40) {
      (this->mpCalcColorPrm).vtbl = (undefined *)&JPADrawCalcColorPrm::__vt;
      (this->mpCalcColorPrmP).vtbl = (undefined *)&PTR_80396948;
      if (this != (JPADrawVisitorContainer *)0xffffff3c) {
        (this->mpCalcColorPrmP).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
      if (this != (JPADrawVisitorContainer *)0xffffff40) {
        (this->mpCalcColorPrm).vtbl = &JPADrawCalcEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff44) {
      (this->mpCalcScaleAnmTimingReverseY).vtbl = &JPADrawCalcScaleAnmTimingReverseY::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff44) {
        (this->mpCalcScaleAnmTimingReverseY).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff48) {
      (this->mpCalcScaleAnmTimingReverseX).vtbl = &JPADrawCalcScaleAnmTimingReverseX::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff48) {
        (this->mpCalcScaleAnmTimingReverseX).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff4c) {
      (this->mpCalcScaleAnmTimingRepeatY).vtbl = &JPADrawCalcScaleAnmTimingRepeatY::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff4c) {
        (this->mpCalcScaleAnmTimingRepeatY).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff50) {
      (this->mpCalcScaleAnmTimingRepeatX).vtbl = &JPADrawCalcScaleAnmTimingRepeatX::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff50) {
        (this->mpCalcScaleAnmTimingRepeatX).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff54) {
      (this->mpCalcScaleAnmTimingNormal).vtbl = &JPADrawCalcScaleAnmTimingNormal::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff54) {
        (this->mpCalcScaleAnmTimingNormal).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff58) {
      (this->mpCalcScaleCopyX2Y).vtbl = &JPADrawCalcScaleCopyX2Y::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff58) {
        (this->mpCalcScaleCopyX2Y).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff5c) {
      (this->mpCalcScaleYBySpeed).vtbl = &JPADrawCalcScaleYBySpeed::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff5c) {
        (this->mpCalcScaleYBySpeed).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff60) {
      (this->mpCalcScaleY).vtbl = &JPADrawCalcScaleY::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff60) {
        (this->mpCalcScaleY).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff64) {
      (this->mpCalcScaleXBySpeed).vtbl = &JPADrawCalcScaleXBySpeed::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff64) {
        (this->mpCalcScaleXBySpeed).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff68) {
      (this->mpCalcScaleX).vtbl = &JPADrawCalcScaleX::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff68) {
        (this->mpCalcScaleX).vtbl = &JPADrawCalcParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff70) {
      (this->mpDrawExecEmtr).vtbl = (undefined *)&JPADrawExecCallBack::__vt;
      (this->mpDrawExecPtcl).vtbl = (undefined *)&PTR_80396768;
      if (this != (JPADrawVisitorContainer *)0xffffff6c) {
        (this->mpDrawExecPtcl).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
      if (this != (JPADrawVisitorContainer *)0xffffff70) {
        (this->mpDrawExecEmtr).vtbl = &JPADrawExecEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff74) {
      (this->mpExecStripeCross).vtbl = &JPADrawExecStripeCross::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff74) {
        (this->mpExecStripeCross).vtbl = &JPADrawExecEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff78) {
      (this->mpExecStripe).vtbl = &JPADrawExecStripe::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff78) {
        (this->mpExecStripe).vtbl = &JPADrawExecEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff7c) {
      (this->mpExecLine).vtbl = &JPADrawExecLine::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff7c) {
        (this->mpExecLine).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff80) {
      (this->mpExecPoint).vtbl = &JPADrawExecPoint::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff80) {
        (this->mpExecPoint).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff84) {
      (this->mpExecRotationCross).vtbl = &JPADrawExecRotationCross::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff84) {
        (this->mpExecRotationCross).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff88) {
      (this->mpExecRotation).vtbl = &JPADrawExecRotation::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff88) {
        (this->mpExecRotation).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff8c) {
      (this->mpExecDirBillBoard).vtbl = &JPADrawExecDirBillBoard::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff8c) {
        (this->mpExecDirBillBoard).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff90) {
      (this->mpExecRotDirectionalCross).vtbl = &JPADrawExecRotDirectionalCross::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff90) {
        (this->mpExecRotDirectionalCross).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff94) {
      (this->mpExecDirectionalCross).vtbl = &JPADrawExecDirectionalCross::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff94) {
        (this->mpExecDirectionalCross).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff98) {
      (this->mpExecRotDirectional).vtbl = &JPADrawExecRotDirectional::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff98) {
        (this->mpExecRotDirectional).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffff9c) {
      (this->mpExecDirectional).vtbl = &JPADrawExecDirectional::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffff9c) {
        (this->mpExecDirectional).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffffa0) {
      (this->mpExecRotYBillBoard).vtbl = &JPADrawExecRotYBillBoard::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffffa0) {
        (this->mpExecRotYBillBoard).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffffa4) {
      (this->mpExecYBillBoard).vtbl = &JPADrawExecYBillBoard::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffffa4) {
        (this->mpExecYBillBoard).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffffa8) {
      (this->mpExecRotBillBoard).vtbl = &JPADrawExecRotBillBoard::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffffa8) {
        (this->mpExecRotBillBoard).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffffac) {
      (this->mpExecBillBoard).vtbl = &JPADrawExecBillBoard::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffffac) {
        (this->mpExecBillBoard).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffffb0) {
      (this->mpExecLoadExTex).vtbl = &JPADrawExecLoadExTex::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffffb0) {
        (this->mpExecLoadExTex).vtbl = &JPADrawExecEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffffb8) {
      (this->mpExecLoadTexture).vtbl = (undefined *)&JPADrawExecLoadTexture::__vt;
      (this->mpExecLoadTextureP).vtbl = (undefined *)&PTR_80396b0c;
      if (this != (JPADrawVisitorContainer *)0xffffffb4) {
        (this->mpExecLoadTextureP).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
      if (this != (JPADrawVisitorContainer *)0xffffffb8) {
        (this->mpExecLoadTexture).vtbl = &JPADrawExecEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffffbc) {
      (this->mpExecLoadDefaultTexture).vtbl = &JPADrawExecLoadDefaultTexture::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffffbc) {
        (this->mpExecLoadDefaultTexture).vtbl = &JPADrawExecEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffffc0) {
      (this->mpExecRegisterPrmAEnv).vtbl = &JPADrawExecRegisterPrmAEnv::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffffc0) {
        (this->mpExecRegisterPrmAEnv).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffffc4) {
      (this->mpExecRegisterPrmCEnv).vtbl = &JPADrawExecRegisterPrmCEnv::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffffc4) {
        (this->mpExecRegisterPrmCEnv).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffffc8) {
      (this->mpExecRegisterEnvColorAnm).vtbl = &JPADrawExecRegisterEnvColorAnm::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffffc8) {
        (this->mpExecRegisterEnvColorAnm).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffffcc) {
      (this->mpExecRegisterPrmAlphaAnm).vtbl = &JPADrawExecRegisterPrmAlphaAnm::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffffcc) {
        (this->mpExecRegisterPrmAlphaAnm).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffffd0) {
      (this->mpExecRegisterPrmColorAnm).vtbl = &JPADrawExecRegisterPrmColorAnm::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffffd0) {
        (this->mpExecRegisterPrmColorAnm).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffffd4) {
      (this->mpExecRegisterColorChildPE).vtbl = &JPADrawExecRegisterColorChildPE::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffffd4) {
        (this->mpExecRegisterColorChildPE).vtbl = &JPADrawExecEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffffd8) {
      (this->mpExecRegisterColorEmitterE).vtbl = &JPADrawExecRegisterColorEmitterE::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffffd8) {
        (this->mpExecRegisterColorEmitterE).vtbl = &JPADrawExecEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffffdc) {
      (this->mpExecRegisterColorEmitterP).vtbl = &JPADrawExecRegisterColorEmitterP::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffffdc) {
        (this->mpExecRegisterColorEmitterP).vtbl = &JPADrawExecEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffffe0) {
      (this->mpExecRegisterColorEmitterPE).vtbl = &JPADrawExecRegisterColorEmitterPE::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffffe0) {
        (this->mpExecRegisterColorEmitterPE).vtbl = &JPADrawExecEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffffe4) {
      (this->mpExecSetLineWidth).vtbl = &JPADrawExecSetLineWidth::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffffe4) {
        (this->mpExecSetLineWidth).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xffffffe8) {
      (this->mpExecSetPointSize).vtbl = &JPADrawExecSetPointSize::__vt;
      if (this != (JPADrawVisitorContainer *)0xffffffe8) {
        (this->mpExecSetPointSize).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xfffffff0) {
      (this->mpExecSetTexMtx).vtbl = &JPADrawExecSetTexMtx::__vt;
      (this->mpExecSetTexMtxP).vtbl = &DAT_80396b40;
      if (this != (JPADrawVisitorContainer *)0xffffffec) {
        (this->mpExecSetTexMtxP).vtbl = &JPADrawExecParticleVisitor::__vt;
      }
      if (this != (JPADrawVisitorContainer *)0xfffffff0) {
        (this->mpExecSetTexMtx).vtbl = &JPADrawExecEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)0xfffffff4) {
      (this->mpExecGenIdtMtx).vtbl = &JPADrawExecGenIdtMtx::__vt;
      if (this != (JPADrawVisitorContainer *)0xfffffff4) {
        (this->mpExecGenIdtMtx).vtbl = &JPADrawExecEmitterVisitor::__vt;
      }
    }
    if (this != (JPADrawVisitorContainer *)&DAT_fffffff8) {
      (this->mpExecGenTexMtx0).vtbl = &JPADrawExecGenTexMtx0::__vt;
      if (this != (JPADrawVisitorContainer *)&DAT_fffffff8) {
        (this->mpExecGenTexMtx0).vtbl = &JPADrawExecEmitterVisitor::__vt;
      }
    }
    if ((this != (JPADrawVisitorContainer *)0xfffffffc) &&
       ((this->mpExecGenPrjTexMtx).vtbl = &JPADrawExecGenPrjTexMtx::__vt,
       this != (JPADrawVisitorContainer *)0xfffffffc)) {
      (this->mpExecGenPrjTexMtx).vtbl = &JPADrawExecEmitterVisitor::__vt;
    }
    if ((this != (JPADrawVisitorContainer *)0x0) &&
       ((this->mpExecGenPrjMtx).vtbl = &JPADrawExecGenPrjMtx::__vt,
       this != (JPADrawVisitorContainer *)0x0)) {
      (this->mpExecGenPrjMtx).vtbl = &JPADrawExecEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawVisitorContainer::JPADrawVisitorContainer(void) */

void __thiscall JPADrawVisitorContainer::JPADrawVisitorContainer(JPADrawVisitorContainer *this)

{
  (this->mpExecGenPrjMtx).vtbl = &JPADrawExecEmitterVisitor::__vt;
  (this->mpExecGenPrjMtx).vtbl = &JPADrawExecGenPrjMtx::__vt;
  (this->mpExecGenPrjTexMtx).vtbl = &JPADrawExecEmitterVisitor::__vt;
  (this->mpExecGenPrjTexMtx).vtbl = &JPADrawExecGenPrjTexMtx::__vt;
  (this->mpExecGenTexMtx0).vtbl = &JPADrawExecEmitterVisitor::__vt;
  (this->mpExecGenTexMtx0).vtbl = &JPADrawExecGenTexMtx0::__vt;
  (this->mpExecGenIdtMtx).vtbl = &JPADrawExecEmitterVisitor::__vt;
  (this->mpExecGenIdtMtx).vtbl = &JPADrawExecGenIdtMtx::__vt;
  (this->mpExecSetTexMtx).vtbl = &JPADrawExecEmitterVisitor::__vt;
  (this->mpExecSetTexMtxP).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecSetTexMtx).vtbl = &JPADrawExecSetTexMtx::__vt;
  (this->mpExecSetTexMtxP).vtbl = &DAT_80396b40;
  (this->mpExecSetPointSize).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecSetPointSize).vtbl = &JPADrawExecSetPointSize::__vt;
  (this->mpExecSetLineWidth).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecSetLineWidth).vtbl = &JPADrawExecSetLineWidth::__vt;
  (this->mpExecRegisterColorEmitterPE).vtbl = &JPADrawExecEmitterVisitor::__vt;
  (this->mpExecRegisterColorEmitterPE).vtbl = &JPADrawExecRegisterColorEmitterPE::__vt;
  (this->mpExecRegisterColorEmitterP).vtbl = &JPADrawExecEmitterVisitor::__vt;
  (this->mpExecRegisterColorEmitterP).vtbl = &JPADrawExecRegisterColorEmitterP::__vt;
  (this->mpExecRegisterColorEmitterE).vtbl = &JPADrawExecEmitterVisitor::__vt;
  (this->mpExecRegisterColorEmitterE).vtbl = &JPADrawExecRegisterColorEmitterE::__vt;
  (this->mpExecRegisterColorChildPE).vtbl = &JPADrawExecEmitterVisitor::__vt;
  (this->mpExecRegisterColorChildPE).vtbl = &JPADrawExecRegisterColorChildPE::__vt;
  (this->mpExecRegisterPrmColorAnm).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecRegisterPrmColorAnm).vtbl = &JPADrawExecRegisterPrmColorAnm::__vt;
  (this->mpExecRegisterPrmAlphaAnm).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecRegisterPrmAlphaAnm).vtbl = &JPADrawExecRegisterPrmAlphaAnm::__vt;
  (this->mpExecRegisterEnvColorAnm).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecRegisterEnvColorAnm).vtbl = &JPADrawExecRegisterEnvColorAnm::__vt;
  (this->mpExecRegisterPrmCEnv).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecRegisterPrmCEnv).vtbl = &JPADrawExecRegisterPrmCEnv::__vt;
  (this->mpExecRegisterPrmAEnv).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecRegisterPrmAEnv).vtbl = &JPADrawExecRegisterPrmAEnv::__vt;
  (this->mpExecLoadDefaultTexture).vtbl = &JPADrawExecEmitterVisitor::__vt;
  (this->mpExecLoadDefaultTexture).vtbl = &JPADrawExecLoadDefaultTexture::__vt;
  (this->mpExecLoadTexture).vtbl = &JPADrawExecEmitterVisitor::__vt;
  (this->mpExecLoadTextureP).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecLoadTexture).vtbl = (undefined *)&JPADrawExecLoadTexture::__vt;
  (this->mpExecLoadTextureP).vtbl = (undefined *)&PTR_80396b0c;
  (this->mpExecLoadExTex).vtbl = &JPADrawExecEmitterVisitor::__vt;
  (this->mpExecLoadExTex).vtbl = &JPADrawExecLoadExTex::__vt;
  (this->mpExecBillBoard).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecBillBoard).vtbl = &JPADrawExecBillBoard::__vt;
  (this->mpExecRotBillBoard).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecRotBillBoard).vtbl = &JPADrawExecRotBillBoard::__vt;
  (this->mpExecYBillBoard).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecYBillBoard).vtbl = &JPADrawExecYBillBoard::__vt;
  (this->mpExecRotYBillBoard).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecRotYBillBoard).vtbl = &JPADrawExecRotYBillBoard::__vt;
  (this->mpExecDirectional).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecDirectional).vtbl = &JPADrawExecDirectional::__vt;
  (this->mpExecRotDirectional).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecRotDirectional).vtbl = &JPADrawExecRotDirectional::__vt;
  (this->mpExecDirectionalCross).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecDirectionalCross).vtbl = &JPADrawExecDirectionalCross::__vt;
  (this->mpExecRotDirectionalCross).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecRotDirectionalCross).vtbl = &JPADrawExecRotDirectionalCross::__vt;
  (this->mpExecDirBillBoard).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecDirBillBoard).vtbl = &JPADrawExecDirBillBoard::__vt;
  (this->mpExecRotation).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecRotation).vtbl = &JPADrawExecRotation::__vt;
  (this->mpExecRotationCross).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecRotationCross).vtbl = &JPADrawExecRotationCross::__vt;
  (this->mpExecPoint).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecPoint).vtbl = &JPADrawExecPoint::__vt;
  (this->mpExecLine).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpExecLine).vtbl = &JPADrawExecLine::__vt;
  (this->mpExecStripe).vtbl = &JPADrawExecEmitterVisitor::__vt;
  (this->mpExecStripe).vtbl = &JPADrawExecStripe::__vt;
  (this->mpExecStripeCross).vtbl = &JPADrawExecEmitterVisitor::__vt;
  (this->mpExecStripeCross).vtbl = &JPADrawExecStripeCross::__vt;
  (this->mpDrawExecEmtr).vtbl = &JPADrawExecEmitterVisitor::__vt;
  (this->mpDrawExecPtcl).vtbl = &JPADrawExecParticleVisitor::__vt;
  (this->mpDrawExecEmtr).vtbl = (undefined *)&JPADrawExecCallBack::__vt;
  (this->mpDrawExecPtcl).vtbl = (undefined *)&PTR_80396768;
  (this->mpCalcScaleX).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcScaleX).vtbl = &JPADrawCalcScaleX::__vt;
  (this->mpCalcScaleXBySpeed).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcScaleXBySpeed).vtbl = &JPADrawCalcScaleXBySpeed::__vt;
  (this->mpCalcScaleY).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcScaleY).vtbl = &JPADrawCalcScaleY::__vt;
  (this->mpCalcScaleYBySpeed).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcScaleYBySpeed).vtbl = &JPADrawCalcScaleYBySpeed::__vt;
  (this->mpCalcScaleCopyX2Y).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcScaleCopyX2Y).vtbl = &JPADrawCalcScaleCopyX2Y::__vt;
  (this->mpCalcScaleAnmTimingNormal).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcScaleAnmTimingNormal).vtbl = &JPADrawCalcScaleAnmTimingNormal::__vt;
  (this->mpCalcScaleAnmTimingRepeatX).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcScaleAnmTimingRepeatX).vtbl = &JPADrawCalcScaleAnmTimingRepeatX::__vt;
  (this->mpCalcScaleAnmTimingRepeatY).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcScaleAnmTimingRepeatY).vtbl = &JPADrawCalcScaleAnmTimingRepeatY::__vt;
  (this->mpCalcScaleAnmTimingReverseX).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcScaleAnmTimingReverseX).vtbl = &JPADrawCalcScaleAnmTimingReverseX::__vt;
  (this->mpCalcScaleAnmTimingReverseY).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcScaleAnmTimingReverseY).vtbl = &JPADrawCalcScaleAnmTimingReverseY::__vt;
  (this->mpCalcColorPrm).vtbl = &JPADrawCalcEmitterVisitor::__vt;
  (this->mpCalcColorPrmP).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcColorPrm).vtbl = (undefined *)&JPADrawCalcColorPrm::__vt;
  (this->mpCalcColorPrmP).vtbl = (undefined *)&PTR_80396948;
  (this->mpCalcColorEnv).vtbl = &JPADrawCalcEmitterVisitor::__vt;
  (this->mpCalcColorEnvP).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcColorEnv).vtbl = &JPADrawCalcColorEnv::__vt;
  (this->mpCalcColorEnvP).vtbl = &DAT_80396924;
  (this->mpCalcColorCopyFromEmitter).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcColorCopyFromEmitter).vtbl = &JPADrawCalcColorCopyFromEmitter::__vt;
  (this->mpCalcColorAnmFrameNormal).vtbl = &JPADrawCalcEmitterVisitor::__vt;
  (this->mpCalcColorAnmFrameNormalP).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcColorAnmFrameNormal).vtbl = &JPADrawCalcColorAnmFrameNormal::__vt;
  (this->mpCalcColorAnmFrameNormalP).vtbl = &DAT_80396900;
  (this->mpCalcColorAnmFrameRepeat).vtbl = &JPADrawCalcEmitterVisitor::__vt;
  (this->mpCalcColorAnmFrameRepeatP).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcColorAnmFrameRepeat).vtbl = &JPADrawCalcColorAnmFrameRepeat::__vt;
  (this->mpCalcColorAnmFrameRepeatP).vtbl = &DAT_803968dc;
  (this->mpCalcColorAnmFrameReverse).vtbl = &JPADrawCalcEmitterVisitor::__vt;
  (this->mpCalcColorAnmFrameReverseP).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcColorAnmFrameReverse).vtbl = &JPADrawCalcColorAnmFrameReverse::__vt;
  (this->mpCalcColorAnmFrameReverseP).vtbl = &DAT_803968b8;
  (this->mpCalcColorAnmFrameMerge).vtbl = &JPADrawCalcEmitterVisitor::__vt;
  (this->mpCalcColorAnmFrameMergeP).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcColorAnmFrameMerge).vtbl = &JPADrawCalcColorAnmFrameMerge::__vt;
  (this->mpCalcColorAnmFrameMergeP).vtbl = &DAT_80396894;
  (this->mpCalcColorAnmFrameRandom).vtbl = &JPADrawCalcEmitterVisitor::__vt;
  (this->mpCalcColorAnmFrameRandomP).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcColorAnmFrameRandom).vtbl = &JPADrawCalcColorAnmFrameRandom::__vt;
  (this->mpCalcColorAnmFrameRandomP).vtbl = &DAT_80396870;
  (this->mpCalcAlpha).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcAlpha).vtbl = &JPADrawCalcAlpha::__vt;
  (this->mpCalcAlphaFlickNrmSin).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcAlphaFlickNrmSin).vtbl = &JPADrawCalcAlphaFlickNrmSin::__vt;
  (this->mpCalcAlphaFlickAddSin).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcAlphaFlickAddSin).vtbl = &JPADrawCalcAlphaFlickAddSin::__vt;
  (this->mpCalcAlphaFlickMultSin).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcAlphaFlickMultSin).vtbl = &JPADrawCalcAlphaFlickMultSin::__vt;
  (this->mpCalcTextureAnmIndexNormal).vtbl = &JPADrawCalcEmitterVisitor::__vt;
  (this->mpCalcTextureAnmIndexNormalP).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcTextureAnmIndexNormal).vtbl = &JPADrawCalcTextureAnmIndexNormal::__vt;
  (this->mpCalcTextureAnmIndexNormalP).vtbl = &DAT_8039684c;
  (this->mpCalcTextureAnmIndexRepeat).vtbl = &JPADrawCalcEmitterVisitor::__vt;
  (this->mpCalcTextureAnmIndexRepeatP).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcTextureAnmIndexRepeat).vtbl = &JPADrawCalcTextureAnmIndexRepeat::__vt;
  (this->mpCalcTextureAnmIndexRepeatP).vtbl = &DAT_80396828;
  (this->mpCalcTextureAnmIndexReverse).vtbl = &JPADrawCalcEmitterVisitor::__vt;
  (this->mpCalcTextureAnmIndexReverseP).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcTextureAnmIndexReverse).vtbl = &JPADrawCalcTextureAnmIndexReverse::__vt;
  (this->mpCalcTextureAnmIndexReverseP).vtbl = &DAT_80396804;
  (this->mpCalcTextureAnmIndexMerge).vtbl = &JPADrawCalcEmitterVisitor::__vt;
  (this->mpCalcTextureAnmIndexMergeP).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcTextureAnmIndexMerge).vtbl = &JPADrawCalcTextureAnmIndexMerge::__vt;
  (this->mpCalcTextureAnmIndexMergeP).vtbl = &DAT_803967e0;
  (this->mpCalcTextureAnmIndexRandom).vtbl = &JPADrawCalcEmitterVisitor::__vt;
  (this->mpCalcTextureAnmIndexRandomP).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcTextureAnmIndexRandom).vtbl = &JPADrawCalcTextureAnmIndexRandom::__vt;
  (this->mpCalcTextureAnmIndexRandomP).vtbl = &DAT_803967ac;
  (this->mpCalcChildAlphaOut).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcChildAlphaOut).vtbl = &JPADrawCalcChildAlphaOut::__vt;
  (this->mpCalcChildScaleOut).vtbl = &JPADrawCalcParticleVisitor::__vt;
  (this->mpCalcChildScaleOut).vtbl = &JPADrawCalcChildScaleOut::__vt;
  return;
}

