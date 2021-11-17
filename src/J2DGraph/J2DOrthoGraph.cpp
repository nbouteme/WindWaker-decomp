#include <J2DGraph/J2DOrthoGraph.h>
#include <J2DGraph/J2DGrafContext.h>
#include <mtx/mtx44.h>
#include <gx/GXTransform.h>
#include <mtx/mtx.h>
#include <J2DGraph/J2DOrthoGraph.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J2DOrthoGraph.h>


/* __thiscall J2DOrthoGraph::J2DOrthoGraph(void) */

void __thiscall J2DOrthoGraph::J2DOrthoGraph(J2DOrthoGraph *this)

{
  J2DGrafContext::J2DGrafContext
            (&this->parent,J2DGraph::_448,J2DGraph::_448,J2DGraph::_448,J2DGraph::_448);
  (this->parent).vtbl = (J2DGrafContext__vtable *)&__vt;
  (*(code *)((this->parent).vtbl)->setLookat)(this);
  return;
}


/* WARNING: Removing unreachable block (ram,0x802cdc90) */
/* WARNING: Removing unreachable block (ram,0x802cdc80) */
/* WARNING: Removing unreachable block (ram,0x802cdc88) */
/* WARNING: Removing unreachable block (ram,0x802cdc98) */
/* __thiscall J2DOrthoGraph::J2DOrthoGraph(float,
                                           float,
                                           float,
                                           float,
                                           float,
                                           float) */

void __thiscall
J2DOrthoGraph::J2DOrthoGraph
          (J2DOrthoGraph *this,float param_1,float param_2,float param_3,float param_4,float param_5
          ,float param_6)

{
  float fVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar5 = (double)param_5;
  dVar6 = (double)param_6;
  dVar3 = (double)param_3;
  dVar4 = (double)param_4;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  J2DGrafContext::J2DGrafContext(&this->parent,param_1,param_2,param_3,param_4);
  (this->parent).vtbl = (J2DGrafContext__vtable *)&__vt;
  fVar1 = J2DGraph::_448;
  (this->mOrtho).mTL.x = J2DGraph::_448;
  (this->mOrtho).mTL.y = fVar1;
  (this->mOrtho).mBR.x = (float)dVar3;
  (this->mOrtho).mBR.y = (float)dVar4;
  this->mNearZ = (float)dVar5;
  this->mFarZ = (float)dVar6;
  (*(code *)((this->parent).vtbl)->setLookat)(this);
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  __psq_l0(auStack56,uVar2);
  __psq_l1(auStack56,uVar2);
  return;
}


/* __thiscall J2DOrthoGraph::setPort(void) */

void __thiscall J2DOrthoGraph::setPort(J2DOrthoGraph *this)

{
  J2DGrafContext::setPort(&this->parent);
  mtx::C_MTXOrtho((this->mOrtho).mTL.y,J2DGraph::_498 + (this->mOrtho).mBR.y,(this->mOrtho).mTL.x,
                  (this->mOrtho).mBR.x,this->mNearZ,this->mFarZ,&(this->parent).mProj);
  gx::GXSetProjection(&(this->parent).mProj,GX_ORTHOGRAPHIC);
  return;
}


/* __thiscall J2DOrthoGraph::setOrtho(JGeometry::TBox2<float><float> const &,
                                      float,
                                      float) */

void __thiscall
J2DOrthoGraph::setOrtho(J2DOrthoGraph *this,TBox2_float_ *param_1,float param_2,float param_3)

{
  float fVar1;
  
  fVar1 = (param_1->mTL).y;
  (this->mOrtho).mTL.x = (param_1->mTL).x;
  (this->mOrtho).mTL.y = fVar1;
  fVar1 = (param_1->mBR).y;
  (this->mOrtho).mBR.x = (param_1->mBR).x;
  (this->mOrtho).mBR.y = fVar1;
  this->mNearZ = -param_3;
  this->mFarZ = -param_2;
  return;
}


/* __thiscall J2DOrthoGraph::setLookat(void) */

void __thiscall J2DOrthoGraph::setLookat(J2DOrthoGraph *this)

{
  mtx::PSMTXIdentity(&(this->parent).mMtx);
  gx::GXLoadPosMtxImm(&(this->parent).mMtx,0);
  return;
}


/* __thiscall J2DOrthoGraph::scissorBounds(JGeometry::TBox2<float><float> *,
                                           JGeometry::TBox2<float><float> const *) */

void __thiscall
J2DOrthoGraph::scissorBounds(J2DOrthoGraph *this,TBox2_float_ *param_1,TBox2_float_ *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  fVar1 = (this->parent).mViewport.mTL.x;
  fVar2 = (this->mOrtho).mTL.x;
  fVar8 = ((this->parent).mViewport.mBR.x - fVar1) / ((this->mOrtho).mBR.x - fVar2);
  fVar3 = (this->parent).mViewport.mTL.y;
  fVar4 = (this->mOrtho).mTL.y;
  fVar9 = ((this->parent).mViewport.mBR.y - fVar3) / ((this->mOrtho).mBR.y - fVar4);
  fVar5 = (param_2->mBR).x;
  fVar6 = (param_2->mTL).y;
  fVar7 = (param_2->mBR).y;
  (param_1->mTL).x = fVar1 + fVar8 * ((param_2->mTL).x - fVar2);
  (param_1->mTL).y = fVar3 + fVar9 * (fVar6 - fVar4);
  (param_1->mBR).x = fVar1 + fVar8 * (fVar5 - fVar2);
  (param_1->mBR).y = fVar3 + fVar9 * (fVar7 - fVar4);
  return;
}


namespace J2DGraph {

/* WARNING: Removing unreachable block (ram,0x802cdf14) */
/* WARNING: Removing unreachable block (ram,0x802cdf04) */
/* WARNING: Removing unreachable block (ram,0x802cdf0c) */
/* WARNING: Removing unreachable block (ram,0x802cdf1c) */
/* __stdcall J2DDrawLine(float,
                         float,
                         float,
                         float,
                         JUtility::TColor,
                         int) */

void J2DDrawLine
               (double param_1,double param_2,double param_3,double param_4,undefined4 *param_5,
               uchar param_6)

{
  undefined4 uVar1;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  cXy local_144;
  float local_13c;
  float local_138;
  float local_134;
  float local_130;
  float local_12c;
  float local_128;
  J2DOrthoGraph local_124;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  ::J2DOrthoGraph::J2DOrthoGraph(&local_124);
  ::J2DGrafContext::setLineWidth(&local_124.parent,param_6);
  local_158 = *param_5;
  local_154 = local_158;
  local_150 = local_158;
  local_14c = local_158;
  local_148 = local_158;
  ::J2DGrafContext::setColor
            (&local_124.parent,(TColor)&local_158,(TColor)&local_154,(TColor)&local_150,
             (TColor)&local_14c);
  local_134 = (float)param_1;
  local_130 = (float)param_2;
  local_144.x = (float)param_3;
  local_144.y = (float)param_4;
  local_13c = local_144.x;
  local_138 = local_144.y;
  local_12c = local_134;
  local_128 = local_130;
  local_124.parent.mLastPoint.x = local_134;
  local_124.parent.mLastPoint.y = local_130;
  ::J2DGrafContext::lineTo(&local_124.parent,&local_144);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  __psq_l0(auStack40,uVar1);
  __psq_l1(auStack40,uVar1);
  __psq_l0(auStack56,uVar1);
  __psq_l1(auStack56,uVar1);
  return;
}


/* __stdcall J2DFillBox(float,
                        float,
                        float,
                        float,
                        JUtility::TColor) */

void J2DFillBox
               (double param_1,double param_2,double param_3,double param_4,undefined4 *param_5)

{
  undefined4 local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_18 = *param_5;
  local_14 = (float)param_1;
  local_10 = (float)param_2;
  local_c = (float)(param_1 + param_3);
  local_8 = (float)(param_2 + param_4);
  J2DFillBox(&local_14,&local_18);
  return;
}


/* __stdcall J2DFillBox(JGeometry::TBox2<float><float> const &,
                        JUtility::TColor) */

void J2DFillBox(TBox2_float_ *param_1,undefined4 *param_2)

{
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  J2DOrthoGraph local_e4;
  
  ::J2DOrthoGraph::J2DOrthoGraph(&local_e4);
  local_f8 = *param_2;
  local_f4 = local_f8;
  local_f0 = local_f8;
  local_ec = local_f8;
  local_e8 = local_f8;
  ::J2DGrafContext::setColor
            (&local_e4.parent,(TColor)&local_f8,(TColor)&local_f4,(TColor)&local_f0,
             (TColor)&local_ec);
  ::J2DGrafContext::fillBox(&local_e4.parent,param_1);
  return;
}


/* __stdcall J2DDrawFrame(float,
                          float,
                          float,
                          float,
                          JUtility::TColor,
                          unsigned char) */

void J2DDrawFrame
               (double param_1,double param_2,double param_3,double param_4,undefined4 *param_5,
               undefined4 param_6)

{
  undefined4 local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_18 = *param_5;
  local_14 = (float)param_1;
  local_10 = (float)param_2;
  local_c = (float)(param_1 + param_3);
  local_8 = (float)(param_2 + param_4);
  J2DDrawFrame(&local_14,&local_18,param_6);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall J2DDrawFrame(JGeometry::TBox2<float><float> const &,
                          JUtility::TColor,
                          unsigned char) */

void J2DDrawFrame(TBox2_float_ *param_1,undefined4 *param_2,uchar param_3)

{
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  J2DOrthoGraph local_e4;
  
  ::J2DOrthoGraph::J2DOrthoGraph(&local_e4);
  local_f8 = *param_2;
  local_f4 = local_f8;
  local_f0 = local_f8;
  local_ec = local_f8;
  local_e8 = local_f8;
  ::J2DGrafContext::setColor
            (&local_e4.parent,(TColor)&local_f8,(TColor)&local_f4,(TColor)&local_f0,
             (TColor)&local_ec);
  ::J2DGrafContext::setLineWidth(&local_e4.parent,param_3);
  ::J2DGrafContext::drawFrame(&local_e4.parent,param_1);
  return;
}

}

/* __thiscall J2DOrthoGraph::getGrafType(void) const */

J2DTypeID __thiscall J2DOrthoGraph::getGrafType(J2DOrthoGraph *this)

{
  return J2DOrthoGraph;
}

