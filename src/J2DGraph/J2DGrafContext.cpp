#include <J2DGraph/J2DGrafContext.h>
#include <J2DGraph/J2DGrafContext.h>
#include <gx/GXTransform.h>
#include <gx/GXBump.h>
#include <gx/GXTev.h>
#include <gx/GXPixel.h>
#include <gx/GXLight.h>
#include <gx/GXAttr.h>
#include <gx/GXGeometry.h>
#include <mtx/mtx.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <J2DGrafContext.h>


/* __thiscall J2DGrafContext::J2DGrafContext(float,
                                             float,
                                             float,
                                             float) */

void __thiscall
J2DGrafContext::J2DGrafContext
          (J2DGrafContext *this,float param_1,float param_2,float param_3,float param_4)

{
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  this->vtbl = (J2DGrafContext__vtable *)&__vt;
  (this->mViewport).mTL.x = param_1;
  (this->mViewport).mTL.y = param_2;
  (this->mViewport).mBR.x = param_1 + param_3;
  (this->mViewport).mBR.y = param_2 + param_4;
  (this->mScissor).mTL.x = param_1;
  (this->mScissor).mTL.y = param_2;
  (this->mScissor).mBR.x = param_1 + param_3;
  (this->mScissor).mBR.y = param_2 + param_4;
  this->mColorTL = (_GXColor)0xffffffff;
  this->mColorTR = (_GXColor)0xffffffff;
  this->mColorBR = (_GXColor)0xffffffff;
  this->mColorBL = (_GXColor)0xffffffff;
  local_14 = 0xffffffff;
  local_18 = 0xffffffff;
  local_1c = 0xffffffff;
  local_20 = 0xffffffff;
  local_24 = 0xffffffff;
  setColor(this,(TColor)&local_24,(TColor)&local_20,(TColor)&local_1c,(TColor)&local_18);
  setLineWidth(this,'\x06');
  return;
}


/* __thiscall J2DGrafContext::setPort(void) */

void __thiscall J2DGrafContext::setPort(J2DGrafContext *this)

{
  double dVar1;
  double dVar2;
  
  (*(code *)this->vtbl->setScissor)();
  (*(code *)this->vtbl->setup2D)(this);
  dVar2 = (double)(this->mViewport).mTL.y;
  dVar1 = (double)(this->mViewport).mTL.x;
  gx::GXSetViewport(dVar1,dVar2,(double)(float)((double)(this->mViewport).mBR.x - dVar1),
                    (double)(float)((double)(this->mViewport).mBR.y - dVar2),(double)J2DGraph::0_0,
                    (double)J2DGraph::1_0);
  return;
}


/* __thiscall J2DGrafContext::setup2D(void) */

void __thiscall J2DGrafContext::setup2D(J2DGrafContext *this)

{
  int iVar1;
  MTX34 MStack56;
  
  gx::GXSetNumIndStages(0);
  iVar1 = 0;
  do {
    gx::GXSetTevDirect(iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_AND,GX_ALWAYS,0);
  gx::GXSetZMode(false,GX_LEQUAL,false);
  gx::GXSetTevOp(0,4);
  gx::GXSetNumChans(1);
  gx::GXSetNumTevStages(1);
  gx::GXSetNumTexGens(0);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
  gx::GXSetCullMode(0);
  gx::GXLoadPosMtxImm(&this->mMtx,0);
  mtx::PSMTXIdentity(&MStack56);
  gx::GXLoadTexMtxImm(&MStack56,GX_IDENTITY,0);
  gx::GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_VTX,0,GX_DF_NONE,GX_AF_NONE);
  gx::GXSetChanCtrl(GX_COLOR1A1,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  gx::GXSetCurrentMtx(0);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA8,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBX8,0xf);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX1,GX_CLR_RGBA,GX_RGBX8,0xf);
  gx::GXSetLineWidth(this->mLineWidth,0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_CLR0,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_NONE);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802cd568) */
/* WARNING: Removing unreachable block (ram,0x802cd560) */
/* WARNING: Removing unreachable block (ram,0x802cd570) */
/* __thiscall J2DGrafContext::setScissor(void) */

void __thiscall J2DGrafContext::setScissor(J2DGrafContext *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined8 in_f29;
  double dVar11;
  double dVar12;
  double dVar13;
  undefined8 in_f30;
  double dVar14;
  undefined8 in_f31;
  double dVar15;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  dVar15 = (double)(this->mScissor).mTL.x;
  fVar1 = (this->mScissor).mTL.y;
  dVar11 = (double)(this->mScissor).mBR.x;
  fVar2 = (this->mScissor).mBR.y;
  if (dVar15 <= (double)J2DGraph::0_0) {
    (this->mScissor).mTL.x = J2DGraph::0_0;
  }
  if ((this->mScissor).mTL.y <= J2DGraph::0_0) {
    (this->mScissor).mTL.y = J2DGraph::0_0;
  }
  if (J2DGraph::_648 <= (this->mScissor).mBR.x) {
    (this->mScissor).mBR.x = J2DGraph::_648;
  }
  if (J2DGraph::_649 <= (this->mScissor).mBR.y) {
    (this->mScissor).mBR.y = J2DGraph::_649;
  }
  bVar5 = false;
  if ((dVar15 <= dVar11) && (fVar1 <= fVar2)) {
    bVar5 = true;
  }
  dVar12 = dVar11;
  dVar14 = dVar15;
  fVar3 = fVar1;
  fVar4 = fVar2;
  if (!bVar5) {
    if (dVar11 <= dVar15) {
      dVar14 = dVar11;
    }
    if (fVar2 <= fVar1) {
      fVar3 = fVar2;
    }
    if (dVar11 <= dVar15) {
      dVar12 = dVar15;
    }
    if (fVar2 <= fVar1) {
      fVar4 = fVar1;
    }
    if (dVar12 <= dVar11) {
      dVar12 = dVar11;
    }
    if (fVar4 <= fVar2) {
      fVar4 = fVar2;
    }
  }
  dVar15 = (double)J2DGraph::0_0;
  dVar11 = (double)(float)(dVar14 + dVar15);
  if ((double)(float)(dVar14 + dVar15) <= dVar15) {
    dVar11 = dVar15;
  }
  dVar14 = (double)(fVar3 + J2DGraph::_650);
  if ((double)(fVar3 + J2DGraph::_650) <= (double)J2DGraph::0_0) {
    dVar14 = (double)J2DGraph::0_0;
  }
  dVar13 = (double)(float)(dVar12 + dVar15);
  if ((double)J2DGraph::_648 <= (double)(float)(dVar12 + dVar15)) {
    dVar13 = (double)J2DGraph::_648;
  }
  dVar15 = (double)(fVar4 + J2DGraph::_650);
  if ((double)J2DGraph::_649 <= (double)(fVar4 + J2DGraph::_650)) {
    dVar15 = (double)J2DGraph::_649;
  }
  bVar5 = false;
  if ((dVar11 <= dVar13) && (dVar14 <= dVar15)) {
    bVar5 = true;
  }
  if (bVar5) {
    uVar6 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)(float)(dVar15 - dVar14));
    uVar7 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)(float)(dVar13 - dVar11));
    uVar8 = Runtime.PPCEABI.H::__cvt_fp2unsigned(dVar14);
    uVar9 = Runtime.PPCEABI.H::__cvt_fp2unsigned(dVar11);
    gx::GXSetScissor(uVar9,uVar8,uVar7,uVar6);
  }
  else {
    gx::GXSetScissor(0,0,0,0);
  }
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  __psq_l0(auStack24,uVar10);
  __psq_l1(auStack24,uVar10);
  __psq_l0(auStack40,uVar10);
  __psq_l1(auStack40,uVar10);
  return;
}


/* __thiscall J2DGrafContext::scissor(JGeometry::TBox2<float><float> const &) */

void __thiscall J2DGrafContext::scissor(J2DGrafContext *this,TBox2_float_ *param_1)

{
  float fVar1;
  
  fVar1 = (param_1->mTL).y;
  (this->mScissor).mTL.x = (param_1->mTL).x;
  (this->mScissor).mTL.y = fVar1;
  fVar1 = (param_1->mBR).y;
  (this->mScissor).mBR.x = (param_1->mBR).x;
  (this->mScissor).mBR.y = fVar1;
  return;
}


/* __thiscall J2DGrafContext::place(JGeometry::TBox2<float><float> const &) */

void __thiscall J2DGrafContext::place(J2DGrafContext *this,TBox2_float_ *pPos)

{
  float fVar1;
  
  fVar1 = (pPos->mTL).y;
  (this->mViewport).mTL.x = (pPos->mTL).x;
  (this->mViewport).mTL.y = fVar1;
  fVar1 = (pPos->mBR).y;
  (this->mViewport).mBR.x = (pPos->mBR).x;
  (this->mViewport).mBR.y = fVar1;
  fVar1 = (pPos->mTL).y;
  (this->mScissor).mTL.x = (pPos->mTL).x;
  (this->mScissor).mTL.y = fVar1;
  fVar1 = (pPos->mBR).y;
  (this->mScissor).mBR.x = (pPos->mBR).x;
  (this->mScissor).mBR.y = fVar1;
  return;
}


/* __thiscall J2DGrafContext::setColor(JUtility::TColor,
                                       JUtility::TColor,
                                       JUtility::TColor,
                                       JUtility::TColor) */

void __thiscall
J2DGrafContext::setColor
          (J2DGrafContext *this,TColor param_1,TColor param_2,TColor param_3,TColor param_4)

{
  (this->mColorTL).r = *(u8 *)param_1;
  (this->mColorTL).g = *(u8 *)(param_1 + 1);
  (this->mColorTL).b = *(u8 *)(param_1 + 2);
  (this->mColorTL).a = *(u8 *)(param_1 + 3);
  (this->mColorTR).r = *(u8 *)param_2;
  (this->mColorTR).g = *(u8 *)(param_2 + 1);
  (this->mColorTR).b = *(u8 *)(param_2 + 2);
  (this->mColorTR).a = *(u8 *)(param_2 + 3);
  (this->mColorBR).r = *(u8 *)param_3;
  (this->mColorBR).g = *(u8 *)(param_3 + 1);
  (this->mColorBR).b = *(u8 *)(param_3 + 2);
  (this->mColorBR).a = *(u8 *)(param_3 + 3);
  (this->mColorBL).r = *(u8 *)param_4;
  (this->mColorBL).g = *(u8 *)(param_4 + 1);
  (this->mColorBL).b = *(u8 *)(param_4 + 2);
  (this->mColorBL).a = *(u8 *)(param_4 + 3);
  this->field_0xb0 = 1;
  this->field_0xb1 = 4;
  this->field_0xb2 = 5;
  this->mLineBlendMode = 1;
  this->mLineBlendSrc = 4;
  this->mLineBlendDst = 5;
  this->mBoxBlendMode = 1;
  this->mBoxBlendSrc = 4;
  this->mBoxBlendDst = 5;
  if (((uint)this->mColorTL & 0xff) != 0xff) {
    return;
  }
  this->field_0xb0 = 0;
  this->field_0xb1 = 1;
  this->field_0xb2 = 0;
  if (((uint)this->mColorBR & 0xff) != 0xff) {
    return;
  }
  this->mLineBlendMode = 0;
  this->mLineBlendSrc = 1;
  this->mLineBlendDst = 0;
  if (((uint)this->mColorTR & 0xff) != 0xff) {
    return;
  }
  if (((uint)this->mColorBL & 0xff) != 0xff) {
    return;
  }
  this->mBoxBlendMode = 0;
  this->mBoxBlendSrc = 1;
  this->mBoxBlendDst = 0;
  return;
}


/* __thiscall J2DGrafContext::setLineWidth(unsigned char) */

void __thiscall J2DGrafContext::setLineWidth(J2DGrafContext *this,uchar param_1)

{
  this->mLineWidth = param_1;
  gx::GXSetLineWidth(this->mLineWidth,0);
  return;
}


/* __thiscall J2DGrafContext::fillBox(JGeometry::TBox2<float><float> const &) */

void __thiscall J2DGrafContext::fillBox(J2DGrafContext *this,TBox2_float_ *param_1)

{
  gx::GXSetBlendMode((uint)this->mBoxBlendMode,(uint)this->mBoxBlendSrc,(uint)this->mBoxBlendDst,
                     GX_LO_SET);
  gx::GXLoadPosMtxImm(&this->mMtx,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXBegin(0x80,0,4);
  write_volatile_4(0xcc008000,(param_1->mTL).x);
  write_volatile_4(0xcc008000,(param_1->mTL).y);
  write_volatile_4(0xcc008000,J2DGraph::0_0);
  write_volatile_4(0xcc008000,this->mColorTL);
  write_volatile_4(0xcc008000,(param_1->mBR).x);
  write_volatile_4(0xcc008000,(param_1->mTL).y);
  write_volatile_4(0xcc008000,J2DGraph::0_0);
  write_volatile_4(0xcc008000,this->mColorTR);
  write_volatile_4(0xcc008000,(param_1->mBR).x);
  write_volatile_4(0xcc008000,(param_1->mBR).y);
  write_volatile_4(0xcc008000,J2DGraph::0_0);
  write_volatile_4(0xcc008000,this->mColorBL);
  write_volatile_4(0xcc008000,(param_1->mTL).x);
  write_volatile_4(0xcc008000,(param_1->mBR).y);
  write_volatile_4(0xcc008000,J2DGraph::0_0);
  write_volatile_4(0xcc008000,this->mColorBR);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
  return;
}


/* __thiscall J2DGrafContext::drawFrame(JGeometry::TBox2<float><float> const &) */

void __thiscall J2DGrafContext::drawFrame(J2DGrafContext *this,TBox2_float_ *param_1)

{
  gx::GXSetBlendMode((uint)this->mBoxBlendMode,(uint)this->mBoxBlendSrc,(uint)this->mBoxBlendDst,
                     GX_LO_SET);
  gx::GXLoadPosMtxImm(&this->mMtx,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXBegin(0xb0,0,5);
  write_volatile_4(0xcc008000,(param_1->mTL).x);
  write_volatile_4(0xcc008000,(param_1->mTL).y);
  write_volatile_4(0xcc008000,J2DGraph::0_0);
  write_volatile_4(0xcc008000,this->mColorTL);
  write_volatile_4(0xcc008000,(param_1->mBR).x);
  write_volatile_4(0xcc008000,(param_1->mTL).y);
  write_volatile_4(0xcc008000,J2DGraph::0_0);
  write_volatile_4(0xcc008000,this->mColorTR);
  write_volatile_4(0xcc008000,(param_1->mBR).x);
  write_volatile_4(0xcc008000,(param_1->mBR).y);
  write_volatile_4(0xcc008000,J2DGraph::0_0);
  write_volatile_4(0xcc008000,this->mColorBL);
  write_volatile_4(0xcc008000,(param_1->mTL).x);
  write_volatile_4(0xcc008000,(param_1->mBR).y);
  write_volatile_4(0xcc008000,J2DGraph::0_0);
  write_volatile_4(0xcc008000,this->mColorBR);
  write_volatile_4(0xcc008000,(param_1->mTL).x);
  write_volatile_4(0xcc008000,(param_1->mTL).y);
  write_volatile_4(0xcc008000,J2DGraph::0_0);
  write_volatile_4(0xcc008000,this->mColorTL);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J2DGrafContext::line(JGeometry::TVec2<float><float>,
                                   JGeometry::TVec2<float><float>) */

void __thiscall J2DGrafContext::line(J2DGrafContext *this,cXy *param_1,cXy *param_2)

{
  gx::GXSetBlendMode((uint)this->mLineBlendMode,(uint)this->mLineBlendSrc,(uint)this->mLineBlendDst,
                     GX_LO_SET);
  gx::GXLoadPosMtxImm(&this->mMtx,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXBegin(0xa8,0,2);
  write_volatile_4(0xcc008000,param_1->x);
  write_volatile_4(0xcc008000,param_1->y);
  write_volatile_4(0xcc008000,J2DGraph::0_0);
  write_volatile_4(0xcc008000,this->mColorTL);
  write_volatile_4(0xcc008000,param_2->x);
  write_volatile_4(0xcc008000,param_2->y);
  write_volatile_4(0xcc008000,J2DGraph::0_0);
  write_volatile_4(0xcc008000,this->mColorBR);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
  return;
}


/* __thiscall J2DGrafContext::lineTo(JGeometry::TVec2<float><float>) */

void __thiscall J2DGrafContext::lineTo(J2DGrafContext *this,cXy *param_1)

{
  cXy local_18;
  cXy local_10;
  
  local_18.x = param_1->x;
  local_18.y = param_1->y;
  local_10.x = (this->mLastPoint).x;
  local_10.y = (this->mLastPoint).y;
  line(this,&local_10,&local_18);
  (this->mLastPoint).x = param_1->x;
  (this->mLastPoint).y = param_1->y;
  return;
}


/* __thiscall J2DGrafContext::~J2DGrafContext(void) */

void __thiscall J2DGrafContext::_J2DGrafContext(J2DGrafContext *this,short flag)

{
  if ((this != (J2DGrafContext *)0x0) && (this->vtbl = (J2DGrafContext__vtable *)&__vt, 0 < flag)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall J2DGrafContext::place(float,
                                    float,
                                    float,
                                    float) */

void __thiscall
J2DGrafContext::place(J2DGrafContext *this,float param_1,float param_2,float param_3,float param_4)

{
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  
  local_10 = param_1 + param_3;
  local_c = param_2 + param_4;
  local_18 = param_1;
  local_14 = param_2;
  (*(code *)this->vtbl->place_private)(this,&local_18);
  return;
}


/* __thiscall J2DGrafContext::getGrafType(void) const */

J2DTypeID __thiscall J2DGrafContext::getGrafType(J2DGrafContext *this)

{
  return J2DGrafContext;
}


/* __thiscall J2DGrafContext::setLookat(void) */

void __thiscall J2DGrafContext::setLookat(J2DGrafContext *this)

{
  return;
}

