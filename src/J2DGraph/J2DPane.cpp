#include <J2DGraph/J2DPane.h>
#include <JSupport/JSUList.h>
#include <J2DGraph/J2DPane.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JSupport/JSUInputStream.h>
#include <JKernel/JKRHeap.h>
#include <mtx/mtx.h>
#include <J2DGraph/J2DOrthoGraph.h>
#include <J2DGraph/J2DGrafContext.h>
#include <gx/GXGeometry.h>
#include <J2DPane.h>


/* __thiscall J2DPane::J2DPane(void) */

void __thiscall J2DPane::J2DPane(J2DPane *this)

{
  float fVar1;
  
  this->vtbl = (J2DPane__vtable *)&__vt;
  JSUPtrList::initiate(&this->mChildList);
  JSUPtrLink::JSUPtrLink(&this->mParentLink,this);
  *(undefined4 *)this->mMagic = 0x50414e31;
  this->mbDraw = 1;
  this->mName = 0;
  fVar1 = J2DGraph::0_0;
  (this->mPosTL).x = J2DGraph::0_0;
  (this->mPosTL).y = fVar1;
  (this->mPosBR).x = fVar1;
  (this->mPosBR).y = fVar1;
  initiate(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall J2DPane::J2DPane(J2DPane *,
                               bool,
                               unsigned long,
                               JGeometry::TBox2<float><float> const &) */

void __thiscall
J2DPane::J2DPane(J2DPane *this,J2DPane *param_1,bool param_2,ulong param_3,TBox2_float_ *param_4)

{
  JSUPtrLink *pLink;
  
  this->vtbl = (J2DPane__vtable *)&__vt;
  JSUPtrList::initiate(&this->mChildList);
  JSUPtrLink::JSUPtrLink(&this->mParentLink,this);
  *(undefined4 *)this->mMagic = 0x50414e31;
  this->mbDraw = param_2;
  this->mName = param_3;
  (this->mPosTL).x = (param_4->mTL).x;
  (this->mPosTL).y = (param_4->mTL).y;
  (this->mPosBR).x = (param_4->mBR).x;
  (this->mPosBR).y = (param_4->mBR).y;
  if (param_1 != (J2DPane *)0x0) {
    pLink = (JSUPtrLink *)&this->mChildList;
    if (pLink != (JSUPtrLink *)0x0) {
      pLink = &this->mParentLink;
    }
    JSUPtrList::append(&param_1->mChildList,pLink);
  }
  initiate(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J2DPane::J2DPane(unsigned long,
                               JGeometry::TBox2<float><float> const &) */

void __thiscall J2DPane::J2DPane(J2DPane *this,ulong param_1,TBox2_float_ *param_2)

{
  this->vtbl = (J2DPane__vtable *)&__vt;
  JSUPtrList::initiate(&this->mChildList);
  JSUPtrLink::JSUPtrLink(&this->mParentLink,this);
  *(undefined4 *)this->mMagic = 0x50414e31;
  this->mbDraw = 1;
  this->mName = param_1;
  (this->mPosTL).x = (param_2->mTL).x;
  (this->mPosTL).y = (param_2->mTL).y;
  (this->mPosBR).x = (param_2->mBR).x;
  (this->mPosBR).y = (param_2->mBR).y;
  initiate(this);
  return;
}


/* __thiscall J2DPane::initiate(void) */

void __thiscall J2DPane::initiate(J2DPane *this)

{
  float fVar1;
  
  fVar1 = J2DGraph::0_0;
  (this->mBasePosition).x = J2DGraph::0_0;
  (this->mBasePosition).y = fVar1;
  this->mRotationAxis = 'z';
  this->mRotation = fVar1;
  this->mCullMode = 0;
  this->mAlpha = 0xff;
  this->field_0xae = 1;
  this->mDrawAlpha = 0xff;
  this->field_0xaf = 0;
  (*(code *)this->vtbl->calcMtx)();
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J2DPane::J2DPane(J2DPane *,
                               JSURandomInputStream *) */

void __thiscall J2DPane::J2DPane(J2DPane *this,J2DPane *pParentPane,JSURandomInputStream *pStream)

{
  int iVar1;
  undefined4 local_18;
  int local_14;
  
  this->vtbl = (J2DPane__vtable *)&__vt;
  JSUPtrList::initiate(&this->mChildList);
  JSUPtrLink::JSUPtrLink(&this->mParentLink,this);
  iVar1 = (**(code **)(*(int *)pStream + 0x1c))(pStream);
  JSUInputStream::read((JSUInputStream *)pStream,&local_18,8);
  *(undefined4 *)this->mMagic = local_18;
  makePaneStream(this,pParentPane,pStream);
  JSURandomInputStream::seek(pStream,iVar1 + local_14,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802cfed0) */
/* WARNING: Removing unreachable block (ram,0x802cfec8) */
/* WARNING: Removing unreachable block (ram,0x802cfed8) */
/* __thiscall J2DPane::makePaneStream(J2DPane *,
                                      JSURandomInputStream *) */

void __thiscall
J2DPane::makePaneStream(J2DPane *this,J2DPane *pParentPane,JSURandomInputStream *pStream)

{
  JSUPtrLink *pLink;
  undefined4 uVar1;
  undefined8 in_f29;
  double x2;
  undefined8 in_f30;
  double y;
  undefined8 in_f31;
  double x;
  char local_78;
  byte alpha;
  byte basePos;
  char local_75;
  ushort local_74;
  short hs;
  short ws;
  short ys;
  short xs;
  short local_6a;
  int local_68;
  undefined4 local_60;
  uint uStack92;
  undefined4 local_58;
  uint uStack84;
  undefined4 local_50;
  uint uStack76;
  undefined4 local_48;
  uint uStack68;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  double y2;
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  JSUInputStream::read((JSUInputStream *)pStream,&local_75,1);
  JSUInputStream::read((JSUInputStream *)pStream,&this->mbDraw,1);
  (**(code **)(*(int *)pStream + 0x10))(pStream,2);
  JSUInputStream::read((JSUInputStream *)pStream,&local_68,4);
  this->mName = local_68;
  JSUInputStream::read((JSUInputStream *)pStream,&xs,2);
  uStack92 = (int)xs ^ 0x80000000;
  local_60 = 0x43300000;
  x = (double)(float)((double)CONCAT44(0x43300000,uStack92) - J2DGraph::_649);
  JSUInputStream::read((JSUInputStream *)pStream,&ys,2);
  uStack84 = (int)ys ^ 0x80000000;
  local_58 = 0x43300000;
  y = (double)(float)((double)CONCAT44(0x43300000,uStack84) - J2DGraph::_649);
  JSUInputStream::read((JSUInputStream *)pStream,&ws,2);
  uStack76 = (int)ws ^ 0x80000000;
  local_50 = 0x43300000;
  x2 = (double)(float)(x + (double)(float)((double)CONCAT44(0x43300000,uStack76) - J2DGraph::_649));
  JSUInputStream::read((JSUInputStream *)pStream,&hs,2);
  uStack68 = (int)hs ^ 0x80000000;
  local_48 = 0x43300000;
  y2 = (double)CONCAT44(0x43300000,uStack68) - J2DGraph::_649;
  (this->mPosTL).x = (float)x;
  (this->mPosTL).y = (float)y;
  (this->mPosBR).x = (float)x2;
  (this->mPosBR).y = (float)(y + (double)(float)y2);
  local_75 = local_75 + -6;
  this->mRotation = J2DGraph::0_0;
  if (local_75 != '\0') {
    JSUInputStream::read((JSUInputStream *)pStream,&local_74,2);
    uStack68 = (uint)local_74;
    this->mRotation = (float)((double)CONCAT44(0x43300000,uStack68) - J2DGraph::_653);
    local_75 = local_75 + -1;
  }
  local_48 = 0x43300000;
  if (local_75 == '\0') {
    setBasePosition(this,0);
  }
  else {
    JSUInputStream::read((JSUInputStream *)pStream,&basePos,1);
    setBasePosition(this,(uint)basePos);
    local_75 = local_75 + -1;
  }
  this->mAlpha = 0xff;
  if (local_75 != '\0') {
    JSUInputStream::read((JSUInputStream *)pStream,&alpha,1);
    this->mAlpha = alpha;
    local_75 = local_75 + -1;
  }
  this->field_0xae = 1;
  if (local_75 != '\0') {
    JSUInputStream::read((JSUInputStream *)pStream,&local_78,1);
    this->field_0xae = 1 - (local_78 == '\0');
    local_75 = local_75 + -1;
  }
  JSURandomInputStream::align(pStream,4);
  if (pParentPane != (J2DPane *)0x0) {
    pLink = (JSUPtrLink *)&this->mChildList;
    if (pLink != (JSUPtrLink *)0x0) {
      pLink = &this->mParentLink;
    }
    JSUPtrList::append(&pParentPane->mChildList,pLink);
  }
  this->mCullMode = 0;
  this->mDrawAlpha = 0xff;
  this->field_0xaf = 0;
  (*(code *)this->vtbl->calcMtx)(this);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  __psq_l0(auStack40,uVar1);
  __psq_l1(auStack40,uVar1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J2DPane::~J2DPane(void) */

void __thiscall J2DPane::_J2DPane(J2DPane *this,short flag)

{
  JSUPtrLink *pJVar1;
  JSUPtrLink *pJVar2;
  JSUPtrLink *pJVar3;
  
  if (this != (J2DPane *)0x0) {
    this->vtbl = (J2DPane__vtable *)&__vt;
    pJVar2 = (this->mChildList).mpHead;
    if (pJVar2 != (JSUPtrLink *)0x0) {
      pJVar2 = (JSUPtrLink *)&pJVar2[-1].mpList;
    }
    while( true ) {
      if (pJVar2 == (JSUPtrLink *)0x0) break;
      pJVar3 = pJVar2[1].mpPrev;
      if (pJVar3 != (JSUPtrLink *)0x0) {
        pJVar3 = (JSUPtrLink *)&pJVar3[-1].mpList;
      }
      pJVar1 = pJVar2->mpNext;
      pJVar2 = pJVar3;
      if (pJVar1 != (JSUPtrLink *)0x0) {
        (**(code **)(pJVar1->mpData + 8))(pJVar1,1);
      }
    }
    if (this != (J2DPane *)0xffffff50) {
      if (this != (J2DPane *)0xffffff44) {
        JSUPtrLink::_JSUPtrLink(&this->mParentLink);
      }
      if (this != (J2DPane *)0xffffff50) {
        JSUPtrList::_JSUPtrList(&this->mChildList);
      }
    }
    if (0 < flag) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J2DPane::insertChild(J2DPane *,
                                   J2DPane *) */

uint __thiscall J2DPane::insertChild(J2DPane *this,J2DPane *param_1,J2DPane *param_2)

{
  uint uVar1;
  JSUPtrLink *pJVar2;
  JSUPtrLink *pJVar3;
  
  if ((param_1 == (J2DPane *)0x0) || (param_2 == (J2DPane *)0x0)) {
    uVar1 = 0;
  }
  else {
    pJVar3 = (JSUPtrLink *)&param_2->mChildList;
    if (pJVar3 != (JSUPtrLink *)0x0) {
      pJVar3 = &param_2->mParentLink;
    }
    if (param_1 == (J2DPane *)0x0) {
      pJVar2 = (JSUPtrLink *)0x0;
    }
    else {
      pJVar2 = (JSUPtrLink *)&param_1->mChildList;
    }
    if (pJVar2 != (JSUPtrLink *)0x0) {
      pJVar2 = (JSUPtrLink *)&pJVar2->mpNext;
    }
    uVar1 = JSUPtrList::insert(&this->mChildList,pJVar2,pJVar3);
    if ((uVar1 & 0xff) != 0) {
      (*(code *)param_2->vtbl->calcMtx)(param_2);
    }
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x802d0524) */
/* WARNING: Removing unreachable block (ram,0x802d052c) */
/* __thiscall J2DPane::draw(float,
                            float,
                            J2DGrafContext const *,
                            bool) */

void __thiscall
J2DPane::draw(J2DPane *this,float param_1,float param_2,J2DGrafContext *pCtx,bool bClip)

{
  float *pfVar1;
  float fVar2;
  bool bVar3;
  float fVar4;
  JSUPtrList *pJVar5;
  float *pfVar6;
  float *pfVar7;
  JSUPtrLink *pJVar8;
  J2DPane *pParentPane;
  int iVar9;
  undefined4 uVar10;
  double dVar11;
  double dVar12;
  undefined8 in_f30;
  undefined8 in_f31;
  TBox2_float_ local_108;
  J2DGrafContext ctx;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar12 = (double)param_2;
  dVar11 = (double)param_1;
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  ctx.vtbl = (J2DGrafContext__vtable *)&J2DGrafContext::__vt;
  ctx.mViewport.mTL.x = (pCtx->mViewport).mTL.x;
  ctx.mViewport.mTL.y = (pCtx->mViewport).mTL.y;
  ctx.mViewport.mBR.x = (pCtx->mViewport).mBR.x;
  ctx.mViewport.mBR.y = (pCtx->mViewport).mBR.y;
  ctx.mScissor.mTL.x = (pCtx->mScissor).mTL.x;
  ctx.mScissor.mTL.y = (pCtx->mScissor).mTL.y;
  ctx.mScissor.mBR.x = (pCtx->mScissor).mBR.x;
  ctx.mScissor.mBR.y = (pCtx->mScissor).mBR.y;
  ctx.mColorTL = pCtx->mColorTL;
  ctx.mColorTR = pCtx->mColorTR;
  ctx.mColorBR = pCtx->mColorBR;
  ctx.mColorBL = pCtx->mColorBL;
  ctx.mLineWidth = pCtx->mLineWidth;
  ctx.mLastPoint.x = (pCtx->mLastPoint).x;
  ctx.mLastPoint.y = (pCtx->mLastPoint).y;
  pfVar7 = &ctx.mLastPoint.y;
  pfVar6 = &(pCtx->mLastPoint).y;
  iVar9 = 8;
  do {
    pfVar1 = pfVar6 + 1;
    pfVar6 = pfVar6 + 2;
    fVar4 = *pfVar6;
    pfVar7[1] = *pfVar1;
    pfVar7 = pfVar7 + 2;
    *pfVar7 = fVar4;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  pfVar7 = ctx.mProj.m[3] + 3;
  pfVar6 = (pCtx->mProj).m[3] + 3;
  iVar9 = 6;
  do {
    pfVar1 = pfVar6 + 1;
    pfVar6 = pfVar6 + 2;
    fVar4 = *pfVar6;
    pfVar7[1] = *pfVar1;
    pfVar7 = pfVar7 + 2;
    *pfVar7 = fVar4;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  ctx._176_2_ = *(undefined2 *)&pCtx->field_0xb0;
  ctx.field_0xb2 = pCtx->field_0xb2;
  ctx._179_2_ = *(undefined2 *)&pCtx->mLineBlendMode;
  ctx.mLineBlendDst = pCtx->mLineBlendDst;
  ctx._182_2_ = *(undefined2 *)&pCtx->mBoxBlendMode;
  ctx.mBoxBlendDst = pCtx->mBoxBlendDst;
  iVar9 = (*(code *)pCtx->vtbl->getGrafType)(pCtx);
  if (iVar9 != 1) {
    bClip = false;
  }
  pJVar5 = (this->mParentLink).mpList;
  pParentPane = (J2DPane *)0x0;
  if (pJVar5 != (JSUPtrList *)0x0) {
    pParentPane = (J2DPane *)pJVar5[1].mpHead;
  }
  if (this->mbDraw != 0) {
    bVar3 = false;
    if (((this->mPosTL).x <= (this->mPosBR).x) && ((this->mPosTL).y <= (this->mPosBR).y)) {
      bVar3 = true;
    }
    if (bVar3) {
      fVar4 = (this->mPosTL).y;
      (this->mScreenPos).mTL.x = (this->mPosTL).x;
      (this->mScreenPos).mTL.y = fVar4;
      fVar4 = (this->mPosBR).y;
      (this->mScreenPos).mBR.x = (this->mPosBR).x;
      (this->mScreenPos).mBR.y = fVar4;
      fVar4 = (this->mPosTL).y;
      (this->mBox).mTL.x = (this->mPosTL).x;
      (this->mBox).mTL.y = fVar4;
      fVar4 = (this->mPosBR).y;
      (this->mBox).mBR.x = (this->mPosBR).x;
      (this->mBox).mBR.y = fVar4;
      if (pParentPane == (J2DPane *)0x0) {
        (this->mScreenPos).mTL.x = (float)((double)(this->mScreenPos).mTL.x + dVar11);
        (this->mScreenPos).mTL.y = (float)((double)(this->mScreenPos).mTL.y + dVar12);
        (this->mScreenPos).mBR.x = (float)((double)(this->mScreenPos).mBR.x + dVar11);
        (this->mScreenPos).mBR.y = (float)((double)(this->mScreenPos).mBR.y + dVar12);
        (*(code *)this->vtbl->makeMatrix)
                  ((double)(float)((double)(this->mPosTL).x + dVar11),
                   (double)(float)((double)(this->mPosTL).y + dVar12),this);
        mtx::PSMTXCopy(&this->mMtx,&this->mDrawMtx);
        (this->mBox).mTL.x = (this->mScreenPos).mTL.x;
        (this->mBox).mTL.y = (this->mScreenPos).mTL.y;
        (this->mBox).mBR.x = (this->mScreenPos).mBR.x;
        (this->mBox).mBR.y = (this->mScreenPos).mBR.y;
        this->mDrawAlpha = this->mAlpha;
      }
      else {
        fVar4 = (pParentPane->mScreenPos).mTL.x;
        fVar2 = (pParentPane->mScreenPos).mTL.y;
        (this->mScreenPos).mTL.x = (this->mScreenPos).mTL.x + fVar4;
        (this->mScreenPos).mTL.y = (this->mScreenPos).mTL.y + fVar2;
        (this->mScreenPos).mBR.x = (this->mScreenPos).mBR.x + fVar4;
        (this->mScreenPos).mBR.y = (this->mScreenPos).mBR.y + fVar2;
        mtx::PSMTXConcat(&pParentPane->mDrawMtx,&this->mMtx,&this->mDrawMtx);
        if (bClip != false) {
          fVar4 = (pParentPane->mScreenPos).mTL.x;
          fVar2 = (pParentPane->mScreenPos).mTL.y;
          (this->mBox).mTL.x = (this->mBox).mTL.x + fVar4;
          (this->mBox).mTL.y = (this->mBox).mTL.y + fVar2;
          (this->mBox).mBR.x = (this->mBox).mBR.x + fVar4;
          (this->mBox).mBR.y = (this->mBox).mBR.y + fVar2;
          fVar4 = (pParentPane->mBox).mTL.x;
          if ((this->mBox).mTL.x <= fVar4) {
            (this->mBox).mTL.x = fVar4;
          }
          fVar4 = (pParentPane->mBox).mTL.y;
          if ((this->mBox).mTL.y <= fVar4) {
            (this->mBox).mTL.y = fVar4;
          }
          fVar4 = (pParentPane->mBox).mBR.x;
          if (fVar4 <= (this->mBox).mBR.x) {
            (this->mBox).mBR.x = fVar4;
          }
          fVar4 = (pParentPane->mBox).mBR.y;
          if (fVar4 <= (this->mBox).mBR.y) {
            (this->mBox).mBR.y = fVar4;
          }
        }
        this->mDrawAlpha = this->mAlpha;
        if (this->field_0xae != 0) {
          this->mDrawAlpha = (byte)(((uint)this->mAlpha * (uint)pParentPane->mDrawAlpha) / 0xff);
        }
      }
      local_108.mTL.x = J2DGraph::0_0;
      local_108.mTL.y = J2DGraph::0_0;
      local_108.mBR.x = J2DGraph::0_0;
      local_108.mBR.y = J2DGraph::0_0;
      if (bClip != false) {
        J2DOrthoGraph::scissorBounds((J2DOrthoGraph *)pCtx,&local_108,&this->mBox);
      }
      bVar3 = false;
      if (((this->mBox).mTL.x <= (this->mBox).mBR.x) && ((this->mBox).mTL.y <= (this->mBox).mBR.y))
      {
        bVar3 = true;
      }
      if ((bVar3) || (bClip == false)) {
        J2DGrafContext::place(&ctx,&this->mScreenPos);
        if (bClip != false) {
          J2DGrafContext::scissor(&ctx,&local_108);
          J2DGrafContext::setScissor(&ctx);
        }
        gx::GXSetCullMode(this->mCullMode);
        (*(code *)this->vtbl->drawSelf2)(dVar11,dVar12,this,&ctx.mMtx);
        pJVar8 = (this->mChildList).mpHead;
        if (pJVar8 != (JSUPtrLink *)0x0) {
          pJVar8 = (JSUPtrLink *)&pJVar8[-1].mpList;
        }
        while (pJVar8 != (JSUPtrLink *)0x0) {
          draw((J2DPane *)pJVar8->mpNext,J2DGraph::0_0,J2DGraph::0_0,pCtx,bClip);
          pJVar8 = pJVar8[1].mpPrev;
          if (pJVar8 != (JSUPtrLink *)0x0) {
            pJVar8 = (JSUPtrLink *)&pJVar8[-1].mpList;
          }
        }
      }
    }
  }
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  __psq_l0(auStack24,uVar10);
  __psq_l1(auStack24,uVar10);
  return;
}


/* __thiscall J2DPane::move(float,
                            float) */

void __thiscall J2DPane::move(J2DPane *this,float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = (this->mPosBR).x;
  fVar2 = (this->mPosTL).x;
  fVar3 = (this->mPosBR).y;
  fVar4 = (this->mPosTL).y;
  (this->mPosTL).x = param_1;
  (this->mPosTL).y = param_2;
  (this->mPosBR).x = param_1 + (fVar1 - fVar2);
  (this->mPosBR).y = param_2 + (fVar3 - fVar4);
  (*(code *)this->vtbl->calcMtx)();
  return;
}


/* __thiscall J2DPane::add(float,
                           float) */

void __thiscall J2DPane::add(J2DPane *this,float param_1,float param_2)

{
  (*(code *)this->vtbl->move)
            ((double)((this->mPosTL).x + param_1),(double)((this->mPosTL).y + param_2));
  return;
}


/* __thiscall J2DPane::clip(JGeometry::TBox2<float><float> const &) */

void __thiscall J2DPane::clip(J2DPane *this,TBox2_float_ *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = (this->mScreenPos).mTL.x;
  fVar2 = (this->mScreenPos).mTL.y;
  fVar3 = (param_1->mTL).x + fVar1;
  fVar4 = (param_1->mTL).y + fVar2;
  fVar1 = (param_1->mBR).x + fVar1;
  fVar2 = (param_1->mBR).y + fVar2;
  if ((this->mBox).mTL.x <= fVar3) {
    (this->mBox).mTL.x = fVar3;
  }
  if ((this->mBox).mTL.y <= fVar4) {
    (this->mBox).mTL.y = fVar4;
  }
  if (fVar1 <= (this->mBox).mBR.x) {
    (this->mBox).mBR.x = fVar1;
  }
  if ((this->mBox).mBR.y < fVar2) {
    return;
  }
  (this->mBox).mBR.y = fVar2;
  return;
}


/* __thiscall J2DPane::search(unsigned long) */

J2DPane * __thiscall J2DPane::search(J2DPane *this,ulong param_1)

{
  J2DPane *pJVar1;
  JSUPtrLink *pJVar2;
  
  if (param_1 != this->mName) {
    pJVar2 = (this->mChildList).mpHead;
    if (pJVar2 != (JSUPtrLink *)0x0) {
      pJVar2 = (JSUPtrLink *)&pJVar2[-1].mpList;
    }
    while (pJVar2 != (JSUPtrLink *)0x0) {
      pJVar1 = (J2DPane *)(**(code **)(pJVar2->mpNext->mpData + 0x30))(pJVar2->mpNext,param_1);
      if (pJVar1 != (J2DPane *)0x0) {
        return pJVar1;
      }
      pJVar2 = pJVar2[1].mpPrev;
      if (pJVar2 != (JSUPtrLink *)0x0) {
        pJVar2 = (JSUPtrLink *)&pJVar2[-1].mpList;
      }
    }
    this = (J2DPane *)0x0;
  }
  return this;
}


/* WARNING: Removing unreachable block (ram,0x802d07dc) */
/* WARNING: Removing unreachable block (ram,0x802d07e4) */
/* __thiscall J2DPane::makeMatrix(float,
                                  float) */

void __thiscall J2DPane::makeMatrix(J2DPane *this,float x,float y)

{
  float fVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f30;
  undefined8 in_f31;
  MTX34 MStack184;
  MTX34 MStack136;
  MTX34 MStack88;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar4 = (double)y;
  dVar3 = (double)x;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar5 = (double)J2DGraph::0_0;
  if (dVar5 == (double)this->mRotation) {
    mtx::PSMTXTrans(dVar3,dVar4,dVar5,&this->mMtx);
  }
  else {
    mtx::PSMTXTrans(-(double)(this->mBasePosition).x,-(double)(this->mBasePosition).y,dVar5,
                    &MStack88);
    if (this->mRotationAxis == 'z') {
      fVar1 = -this->mRotation;
    }
    else {
      fVar1 = this->mRotation;
    }
    mtx::PSMTXRotRad(&MStack136,this->mRotationAxis,J2DGraph::_1092 * fVar1);
    mtx::PSMTXTrans((double)(float)((double)(this->mBasePosition).x + dVar3),
                    (double)(float)((double)(this->mBasePosition).y + dVar4),(double)J2DGraph::0_0,
                    &MStack184);
    mtx::PSMTXConcat(&MStack136,&MStack88,&this->mMtx);
    mtx::PSMTXConcat(&MStack184,&this->mMtx,&this->mMtx);
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  return;
}


/* __thiscall J2DPane::setBasePosition(J2DBasePosition) */

void __thiscall J2DPane::setBasePosition(J2DPane *this,J2DBasePosition param_1)

{
  this->m2DBasePosition = (byte)param_1;
  if ((int)param_1 % 3 == 0) {
    (this->mBasePosition).x = J2DGraph::0_0;
  }
  else {
    if ((int)param_1 % 3 == 1) {
      (this->mBasePosition).x = ((this->mPosBR).x - (this->mPosTL).x) * J2DGraph::0_5;
    }
    else {
      (this->mBasePosition).x = (this->mPosBR).x - (this->mPosTL).x;
    }
  }
  if ((int)param_1 / 3 == 0) {
    (this->mBasePosition).y = J2DGraph::0_0;
  }
  else {
    if ((int)param_1 / 3 == 1) {
      (this->mBasePosition).y = ((this->mPosBR).y - (this->mPosTL).y) * J2DGraph::0_5;
    }
    else {
      (this->mBasePosition).y = (this->mPosBR).y - (this->mPosTL).y;
    }
  }
  this->mRotationAxis = 'z';
  (*(code *)this->vtbl->calcMtx)();
  return;
}


/* __thiscall J2DPane::getTypeID(void) */

J2DTypeID __thiscall J2DPane::getTypeID(J2DPane *this)

{
  return J2DPane;
}

