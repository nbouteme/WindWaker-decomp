#include <J2DGraph/J2DWindow.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J2DGraph/J2DPane.h>
#include <JSupport/JSUInputStream.h>
#include <JUtility/JUTResource.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTTexture.h>
#include <JUtility/JUTPalette.h>
#include <J2DGraph/J2DWindow.h>
#include <gx/GXAttr.h>
#include <gx/GXTev.h>
#include <mtx/mtx.h>
#include <gx/GXTransform.h>
#include <gx/GXLight.h>
#include <gx/GXPixel.h>
#include <gx/GXGeometry.h>
#include <J2DWindow.h>


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x802d17f8) */
/* WARNING: Removing unreachable block (ram,0x802d17f0) */
/* WARNING: Removing unreachable block (ram,0x802d1800) */
/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall J2DWindow::J2DWindow(J2DPane *,
                                   JSURandomInputStream *) */

void __thiscall J2DWindow::J2DWindow(J2DWindow *this,J2DPane *param_1,JSURandomInputStream *param_2)

{
  double dVar1;
  int iVar2;
  ResTIMG *pRVar3;
  JUTTexture *pJVar4;
  ResTLUT *pRVar5;
  JUTPalette *this_00;
  char cVar6;
  undefined4 uVar7;
  undefined8 in_f29;
  double dVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  undefined local_1a8;
  char local_1a7;
  ushort local_1a6;
  ushort local_1a4;
  ushort local_1a2;
  ushort local_1a0 [2];
  undefined4 local_19c;
  undefined4 local_198;
  _GXColor local_194;
  _GXColor local_190;
  _GXColor local_18c;
  _GXColor local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  int local_170;
  JUTResReference local_16c [260];
  undefined4 local_68;
  uint uStack100;
  undefined4 local_60;
  uint uStack92;
  undefined4 local_58;
  uint uStack84;
  undefined4 local_50;
  uint uStack76;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  J2DPane::J2DPane(&this->parent);
  (this->parent).vtbl = (J2DPane__vtable *)&__vt;
  this->mpTexture[0] = (JUTTexture *)0x0;
  this->mpTexture[1] = (JUTTexture *)0x0;
  this->mpTexture[2] = (JUTTexture *)0x0;
  this->mpTexture[3] = (JUTTexture *)0x0;
  this->mpTexture[4] = (JUTTexture *)0x0;
  this->mpPallete = (JUTPalette *)0x0;
  this->field_0xf4 = (_GXColor)0xffffffff;
  this->field_0xf8 = (_GXColor)0xffffffff;
  this->field_0xfc = (_GXColor)0xffffffff;
  this->field_0x100 = (_GXColor)0xffffffff;
  *(undefined4 *)&this->field_0x104 = 0xffffffff;
  *(undefined4 *)&this->field_0x108 = 0xffffffff;
  iVar2 = (**(code **)(*(int *)param_2 + 0x1c))(param_2);
  JSUInputStream::read((JSUInputStream *)param_2,&local_174,8);
  *(undefined4 *)(this->parent).mMagic = local_174;
  J2DPane::makePaneStream(&this->parent,param_1,param_2);
  local_16c[0] = (JUTResReference)0x0;
  JSUInputStream::read((JSUInputStream *)param_2,&local_1a7,1);
  JSUInputStream::read((JSUInputStream *)param_2,local_1a0,2);
  uStack100 = (uint)local_1a0[0];
  local_68 = 0x43300000;
  dVar10 = (double)(float)((double)CONCAT44(0x43300000,uStack100) - J2DGraph::_845);
  JSUInputStream::read((JSUInputStream *)param_2,&local_1a2,2);
  uStack92 = (uint)local_1a2;
  local_60 = 0x43300000;
  dVar9 = (double)(float)((double)CONCAT44(0x43300000,uStack92) - J2DGraph::_845);
  JSUInputStream::read((JSUInputStream *)param_2,&local_1a4,2);
  uStack84 = (uint)local_1a4;
  local_58 = 0x43300000;
  dVar8 = (double)(float)(dVar10 + (double)(float)((double)CONCAT44(0x43300000,uStack84) -
                                                  J2DGraph::_845));
  JSUInputStream::read((JSUInputStream *)param_2,&local_1a6,2);
  uStack76 = (uint)local_1a6;
  local_50 = 0x43300000;
  dVar1 = (double)CONCAT44(0x43300000,uStack76) - J2DGraph::_845;
  (this->mWindowBox).mTL.x = (float)dVar10;
  (this->mWindowBox).mTL.y = (float)dVar9;
  (this->mWindowBox).mBR.x = (float)dVar8;
  (this->mWindowBox).mBR.y = (float)(dVar9 + (double)(float)dVar1);
  pRVar3 = (ResTIMG *)
           JUTResReference::getResource
                     (local_16c,(JSUInputStream *)param_2,0x54494d47,(JKRArchive *)0x0);
  if (pRVar3 != (ResTIMG *)0x0) {
    pJVar4 = (JUTTexture *)JKernel::operator_new(0x40);
    if (pJVar4 != (JUTTexture *)0x0) {
      pJVar4->mpPalette = (JUTPalette *)0x0;
      JUTTexture::storeTIMG(pJVar4,pRVar3,'\0');
      pJVar4->field_0x3b = pJVar4->field_0x3b & 2;
    }
    this->mpTexture[0] = pJVar4;
  }
  pRVar3 = (ResTIMG *)
           JUTResReference::getResource
                     (local_16c,(JSUInputStream *)param_2,0x54494d47,(JKRArchive *)0x0);
  if (pRVar3 != (ResTIMG *)0x0) {
    pJVar4 = (JUTTexture *)JKernel::operator_new(0x40);
    if (pJVar4 != (JUTTexture *)0x0) {
      pJVar4->mpPalette = (JUTPalette *)0x0;
      JUTTexture::storeTIMG(pJVar4,pRVar3,'\0');
      pJVar4->field_0x3b = pJVar4->field_0x3b & 2;
    }
    this->mpTexture[1] = pJVar4;
  }
  pRVar3 = (ResTIMG *)
           JUTResReference::getResource
                     (local_16c,(JSUInputStream *)param_2,0x54494d47,(JKRArchive *)0x0);
  if (pRVar3 != (ResTIMG *)0x0) {
    pJVar4 = (JUTTexture *)JKernel::operator_new(0x40);
    if (pJVar4 != (JUTTexture *)0x0) {
      pJVar4->mpPalette = (JUTPalette *)0x0;
      JUTTexture::storeTIMG(pJVar4,pRVar3,'\0');
      pJVar4->field_0x3b = pJVar4->field_0x3b & 2;
    }
    this->mpTexture[2] = pJVar4;
  }
  pRVar3 = (ResTIMG *)
           JUTResReference::getResource
                     (local_16c,(JSUInputStream *)param_2,0x54494d47,(JKRArchive *)0x0);
  if (pRVar3 != (ResTIMG *)0x0) {
    pJVar4 = (JUTTexture *)JKernel::operator_new(0x40);
    if (pJVar4 != (JUTTexture *)0x0) {
      pJVar4->mpPalette = (JUTPalette *)0x0;
      JUTTexture::storeTIMG(pJVar4,pRVar3,'\0');
      pJVar4->field_0x3b = pJVar4->field_0x3b & 2;
    }
    this->mpTexture[3] = pJVar4;
  }
  pRVar5 = (ResTLUT *)
           JUTResReference::getResource
                     (local_16c,(JSUInputStream *)param_2,0x544c5554,(JKRArchive *)0x0);
  if (pRVar5 != (ResTLUT *)0x0) {
    this_00 = (JUTPalette *)JKernel::operator_new(0x18);
    if (this_00 != (JUTPalette *)0x0) {
      JUTPalette::storeTLUT(this_00,0,pRVar5);
    }
    this->mpPallete = this_00;
  }
  JSUInputStream::read((JSUInputStream *)param_2,&local_1a8,1);
  *(undefined *)&this->field_0x110 = local_1a8;
  JSUInputStream::read((JSUInputStream *)param_2,&local_188,4);
  this->field_0xf4 = local_188;
  JSUInputStream::read((JSUInputStream *)param_2,&local_18c,4);
  this->field_0xf8 = local_18c;
  JSUInputStream::read((JSUInputStream *)param_2,&local_190,4);
  this->field_0xfc = local_190;
  JSUInputStream::read((JSUInputStream *)param_2,&local_194,4);
  this->field_0x100 = local_194;
  this->mpTexture[4] = (JUTTexture *)0x0;
  cVar6 = local_1a7 + -0xe;
  if (local_1a7 != '\x0e') {
    pRVar3 = (ResTIMG *)
             JUTResReference::getResource
                       (local_16c,(JSUInputStream *)param_2,0x54494d47,(JKRArchive *)0x0);
    if (pRVar3 != (ResTIMG *)0x0) {
      pJVar4 = (JUTTexture *)JKernel::operator_new(0x40);
      if (pJVar4 != (JUTTexture *)0x0) {
        pJVar4->mpPalette = (JUTPalette *)0x0;
        JUTTexture::storeTIMG(pJVar4,pRVar3,'\0');
        pJVar4->field_0x3b = pJVar4->field_0x3b & 2;
      }
      this->mpTexture[4] = pJVar4;
    }
    cVar6 = local_1a7 + -0xf;
  }
  local_178 = 0;
  *(undefined *)&this->field_0x108 = 0;
  *(undefined *)&this->field_0x109 = 0;
  *(undefined *)&this->field_0x10a = 0;
  *(undefined *)&this->field_0x10b = 0;
  local_17c = 0xffffffff;
  *(undefined *)&this->field_0x104 = 0xff;
  *(undefined *)&this->field_0x105 = 0xff;
  *(undefined *)&this->field_0x106 = 0xff;
  *(undefined *)&this->field_0x107 = 0xff;
  if (cVar6 != '\0') {
    JSUInputStream::read((JSUInputStream *)param_2,&local_198,4);
    local_180 = local_198;
    local_180._0_1_ = (undefined)((uint)local_198 >> 0x18);
    *(undefined *)&this->field_0x108 = local_180._0_1_;
    local_180._1_1_ = (undefined)((uint)local_198 >> 0x10);
    *(undefined *)&this->field_0x109 = local_180._1_1_;
    local_180._2_1_ = (undefined)((uint)local_198 >> 8);
    *(undefined *)&this->field_0x10a = local_180._2_1_;
    local_180._3_1_ = (undefined)local_198;
    *(undefined *)&this->field_0x10b = (undefined)local_180;
    cVar6 = cVar6 + -1;
  }
  if (cVar6 != '\0') {
    JSUInputStream::read((JSUInputStream *)param_2,&local_19c,4);
    local_184 = local_19c;
    local_184._0_1_ = (undefined)((uint)local_19c >> 0x18);
    *(undefined *)&this->field_0x104 = local_184._0_1_;
    local_184._1_1_ = (undefined)((uint)local_19c >> 0x10);
    *(undefined *)&this->field_0x105 = local_184._1_1_;
    local_184._2_1_ = (undefined)((uint)local_19c >> 8);
    *(undefined *)&this->field_0x106 = local_184._2_1_;
    local_184._3_1_ = (undefined)local_19c;
    *(undefined *)&this->field_0x107 = (undefined)local_184;
  }
  JSURandomInputStream::seek(param_2,iVar2 + local_170,0);
  initinfo2(this);
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  __psq_l0(auStack40,uVar7);
  __psq_l1(auStack40,uVar7);
  return;
}


/* __thiscall J2DWindow::initinfo2(void) */

void __thiscall J2DWindow::initinfo2(J2DWindow *this)

{
  bool bVar1;
  bool bVar2;
  JUTTexture *pJVar3;
  JUTTexture *pJVar4;
  
  if ((((this->mpTexture[0] == (JUTTexture *)0x0) || (this->mpTexture[1] == (JUTTexture *)0x0)) ||
      (this->mpTexture[2] == (JUTTexture *)0x0)) || (this->mpTexture[3] == (JUTTexture *)0x0)) {
    this->mTextureWidth = 1;
    this->mTextureHeight = 1;
    return;
  }
  this->mTextureWidth = this->mpTexture[0]->mpTIMG->mWidth + this->mpTexture[1]->mpTIMG->mWidth;
  this->mTextureHeight = this->mpTexture[0]->mpTIMG->mHeight + this->mpTexture[2]->mpTIMG->mHeight;
  bVar2 = false;
  *(undefined *)&this->field_0x111 = 0;
  pJVar3 = this->mpTexture[0];
  pJVar4 = this->mpTexture[1];
  if (pJVar4->mpTIMG == pJVar3->mpTIMG) {
    if (pJVar4->mpAttachedPalette == pJVar3->mpAttachedPalette) {
      if (pJVar4->mWrapS == pJVar3->mWrapS) {
        if (pJVar4->mWrapT == pJVar3->mWrapT) {
          if (pJVar4->mMinFilter == pJVar3->mMinFilter) {
            if (pJVar4->mMagFilter == pJVar3->mMagFilter) {
              bVar1 = pJVar4->mMinLOD == pJVar3->mMinLOD;
              if ((bVar1) && (bVar1)) {
                if (pJVar4->mLODBias == pJVar3->mLODBias) {
                  bVar2 = true;
                }
              }
            }
          }
        }
      }
    }
  }
  if (!bVar2) {
    *(byte *)&this->field_0x111 = *(byte *)&this->field_0x111 | 1;
    pJVar3 = this->mpTexture[1];
  }
  pJVar4 = this->mpTexture[3];
  bVar2 = false;
  if (pJVar4->mpTIMG == pJVar3->mpTIMG) {
    if (pJVar4->mpAttachedPalette == pJVar3->mpAttachedPalette) {
      if (pJVar4->mWrapS == pJVar3->mWrapS) {
        if (pJVar4->mWrapT == pJVar3->mWrapT) {
          if (pJVar4->mMinFilter == pJVar3->mMinFilter) {
            if (pJVar4->mMagFilter == pJVar3->mMagFilter) {
              bVar1 = pJVar4->mMinLOD == pJVar3->mMinLOD;
              if ((bVar1) && (bVar1)) {
                if (pJVar4->mLODBias == pJVar3->mLODBias) {
                  bVar2 = true;
                }
              }
            }
          }
        }
      }
    }
  }
  if (!bVar2) {
    *(byte *)&this->field_0x111 = *(byte *)&this->field_0x111 | 2;
    pJVar3 = this->mpTexture[3];
  }
  pJVar4 = this->mpTexture[2];
  bVar2 = false;
  if (pJVar4->mpTIMG == pJVar3->mpTIMG) {
    if (pJVar4->mpAttachedPalette == pJVar3->mpAttachedPalette) {
      if (pJVar4->mWrapS == pJVar3->mWrapS) {
        if (pJVar4->mWrapT == pJVar3->mWrapT) {
          if (pJVar4->mMinFilter == pJVar3->mMinFilter) {
            if (pJVar4->mMagFilter == pJVar3->mMagFilter) {
              bVar1 = pJVar4->mMinLOD == pJVar3->mMinLOD;
              if ((bVar1) && (bVar1)) {
                if (pJVar4->mLODBias == pJVar3->mLODBias) {
                  bVar2 = true;
                }
              }
            }
          }
        }
      }
    }
  }
  if (bVar2) {
    return;
  }
  *(byte *)&this->field_0x111 = *(byte *)&this->field_0x111 | 4;
  return;
}


/* __thiscall J2DWindow::~J2DWindow(void) */

void __thiscall J2DWindow::_J2DWindow(J2DWindow *this,short flag)

{
  if (this != (J2DWindow *)0x0) {
    (this->parent).vtbl = (J2DPane__vtable *)&__vt;
    JUTTexture::_JUTTexture(this->mpTexture[0],1);
    JUTTexture::_JUTTexture(this->mpTexture[1],1);
    JUTTexture::_JUTTexture(this->mpTexture[2],1);
    JUTTexture::_JUTTexture(this->mpTexture[3],1);
    JKernel::operator_delete((JKRHeap *)this->mpPallete);
    JUTTexture::_JUTTexture(this->mpTexture[4],1);
    J2DPane::_J2DPane(&this->parent,0);
    if (0 < flag) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x802d1f34) */
/* WARNING: Removing unreachable block (ram,0x802d1f24) */
/* WARNING: Removing unreachable block (ram,0x802d1f1c) */
/* WARNING: Removing unreachable block (ram,0x802d1f2c) */
/* WARNING: Removing unreachable block (ram,0x802d1f3c) */
/* __thiscall J2DWindow::draw_private(JGeometry::TBox2<float><float> const &,
                                      JGeometry::TBox2<float><float> const &) */

void __thiscall J2DWindow::draw_private(J2DWindow *this,TBox2_float_ *param_1,TBox2_float_ *param_2)

{
  ushort uVar1;
  JUTTexture *pJVar2;
  ResTIMG *pRVar3;
  ushort uVar4;
  undefined4 uVar5;
  undefined8 in_f27;
  double dVar6;
  undefined8 in_f28;
  double dVar7;
  undefined8 in_f29;
  double dVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar5 = 0;
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
  drawContents(this,param_2);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_CLR0,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
  gx::GXSetNumTexGens(1);
  pJVar2 = this->mpTexture[0];
  if ((((pJVar2 != (JUTTexture *)0x0) && (this->mpTexture[1] != (JUTTexture *)0x0)) &&
      (this->mpTexture[2] != (JUTTexture *)0x0)) && (this->mpTexture[3] != (JUTTexture *)0x0)) {
    pRVar3 = this->mpTexture[3]->mpTIMG;
    dVar9 = (double)(((param_1->mBR).x - (param_1->mTL).x) -
                    (float)((double)CONCAT44(0x43300000,pRVar3->mWidth ^ 0x80000000) -
                           J2DGraph::_1042));
    dVar8 = (double)(((param_1->mBR).y - (param_1->mTL).y) -
                    (float)((double)CONCAT44(0x43300000,pRVar3->mHeight ^ 0x80000000) -
                           J2DGraph::_1042));
    dVar7 = (double)(J2DGraph::_1034 +
                    (float)((double)CONCAT44(0x43300000,pJVar2->mpTIMG->mWidth ^ 0x80000000) -
                           J2DGraph::_1042));
    dVar6 = (double)(J2DGraph::_1034 +
                    (float)((double)CONCAT44(0x43300000,pJVar2->mpTIMG->mHeight ^ 0x80000000) -
                           J2DGraph::_1042));
    drawFrameTexture(this,pJVar2,J2DGraph::_1034,J2DGraph::_1034,
                     (bool)(*(byte *)&this->field_0x110 >> 7),
                     (bool)(*(byte *)&this->field_0x110 >> 6 & 1),true);
    drawFrameTexture(this,this->mpTexture[1],(float)dVar9,J2DGraph::_1034,
                     (bool)(*(byte *)&this->field_0x110 >> 5 & 1),
                     (bool)(*(byte *)&this->field_0x110 >> 4 & 1),
                     (bool)(*(byte *)&this->field_0x111 & 1));
    uVar4 = -(*(byte *)&this->field_0x110 >> 5 & 1) & 0x8000;
    uVar1 = ~-(*(byte *)&this->field_0x110 >> 4 & 1) & 0x8000;
    dVar10 = (double)(float)(dVar9 - dVar7);
    drawFrameTexture(this,this->mpTexture[1],(float)dVar7,J2DGraph::_1034,(float)(dVar9 - dVar7),
                     (float)((double)CONCAT44(0x43300000,
                                              this->mpTexture[1]->mpTIMG->mHeight ^ 0x80000000) -
                            J2DGraph::_1042),uVar4,uVar1,uVar4,uVar1 ^ 0x8000,false);
    drawFrameTexture(this,this->mpTexture[3],(float)dVar9,(float)dVar8,
                     (bool)(*(byte *)&this->field_0x110 >> 1 & 1),
                     (bool)(*(byte *)&this->field_0x110 & 1),
                     (bool)(*(byte *)&this->field_0x111 >> 1 & 1));
    uVar4 = -(*(byte *)&this->field_0x110 >> 1 & 1) & 0x8000;
    uVar1 = ~-(*(byte *)&this->field_0x110 & 1) & 0x8000;
    drawFrameTexture(this,this->mpTexture[3],(float)dVar7,(float)dVar8,(float)dVar10,
                     (float)((double)CONCAT44(0x43300000,
                                              this->mpTexture[3]->mpTIMG->mHeight ^ 0x80000000) -
                            J2DGraph::_1042),uVar4,uVar1,uVar4,uVar1 ^ 0x8000,false);
    uVar1 = ~-(*(byte *)&this->field_0x110 >> 1 & 1) & 0x8000;
    uVar4 = -(*(byte *)&this->field_0x110 & 1) & 0x8000;
    dVar7 = (double)(float)(dVar8 - dVar6);
    drawFrameTexture(this,this->mpTexture[3],(float)dVar9,(float)dVar6,
                     (float)((double)CONCAT44(0x43300000,
                                              this->mpTexture[3]->mpTIMG->mWidth ^ 0x80000000) -
                            J2DGraph::_1042),(float)(dVar8 - dVar6),uVar1,uVar4,uVar1 ^ 0x8000,uVar4
                     ,false);
    drawFrameTexture(this,this->mpTexture[2],J2DGraph::_1034,(float)dVar8,
                     (bool)(*(byte *)&this->field_0x110 >> 3 & 1),
                     (bool)(*(byte *)&this->field_0x110 >> 2 & 1),
                     (bool)(*(byte *)&this->field_0x111 >> 2 & 1));
    uVar1 = ~-(*(byte *)&this->field_0x110 >> 3 & 1) & 0x8000;
    uVar4 = -(*(byte *)&this->field_0x110 >> 2 & 1) & 0x8000;
    drawFrameTexture(this,this->mpTexture[2],J2DGraph::_1034,(float)dVar6,
                     (float)((double)CONCAT44(0x43300000,
                                              this->mpTexture[2]->mpTIMG->mWidth ^ 0x80000000) -
                            J2DGraph::_1042),(float)dVar7,uVar1,uVar4,uVar1 ^ 0x8000,uVar4,false);
  }
  gx::GXSetTevOp(0,4);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
  gx::GXSetNumTexGens(0);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_NONE);
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  __psq_l0(auStack56,uVar5);
  __psq_l1(auStack56,uVar5);
  __psq_l0(auStack72,uVar5);
  __psq_l1(auStack72,uVar5);
  return;
}


/* WARNING: Removing unreachable block (ram,0x802d2058) */
/* WARNING: Removing unreachable block (ram,0x802d2060) */
/* __thiscall J2DWindow::resize(float,
                                float) */

void __thiscall J2DWindow::resize(J2DWindow *this,float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  short sVar6;
  JSUPtrLink *pJVar5;
  JSUPtrLink *pJVar7;
  undefined4 uVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  fVar1 = (this->parent).mPosBR.x;
  fVar2 = (this->parent).mPosTL.x;
  fVar3 = (this->parent).mPosBR.y;
  fVar4 = (this->parent).mPosTL.y;
  (this->parent).mPosBR.x = fVar2 + param_1;
  (this->parent).mPosBR.y = (this->parent).mPosTL.y + param_2;
  dVar10 = (double)(param_1 - (fVar1 - fVar2));
  (this->mWindowBox).mBR.x = (float)((double)(this->mWindowBox).mBR.x + dVar10);
  dVar9 = (double)(param_2 - (fVar3 - fVar4));
  (this->mWindowBox).mBR.y = (float)((double)(this->mWindowBox).mBR.y + dVar9);
  pJVar7 = (this->parent).mChildList.mpHead;
  if (pJVar7 != (JSUPtrLink *)0x0) {
    pJVar7 = (JSUPtrLink *)&pJVar7[-1].mpList;
  }
  while (pJVar7 != (JSUPtrLink *)0x0) {
    sVar6 = (**(code **)(pJVar7->mpNext->mpData + 0xc))();
    if ((sVar6 == 0x13) && (pJVar5 = pJVar7->mpNext, *(char *)((int)&pJVar5[10].mpNext + 3) != '\0')
       ) {
      pJVar5[1].mpList =
           (JSUPtrList *)
           ((float)pJVar5->mpNext +
           (float)(dVar10 + (double)((float)pJVar5[1].mpList - (float)pJVar5->mpNext)));
      pJVar5[1].mpPrev =
           (JSUPtrLink *)
           ((float)pJVar5[1].mpData +
           (float)(dVar9 + (double)((float)pJVar5[1].mpPrev - (float)pJVar5[1].mpData)));
    }
    pJVar7 = pJVar7[1].mpPrev;
    if (pJVar7 != (JSUPtrLink *)0x0) {
      pJVar7 = (JSUPtrLink *)&pJVar7[-1].mpList;
    }
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  return;
}


/* __thiscall J2DWindow::setContentsColor(JUtility::TColor,
                                          JUtility::TColor,
                                          JUtility::TColor,
                                          JUtility::TColor) */

void __thiscall
J2DWindow::setContentsColor
          (J2DWindow *this,TColor param_1,TColor param_2,TColor param_3,TColor param_4)

{
  undefined4 uVar1;
  u8 local_18;
  u8 uStack23;
  u8 uStack22;
  u8 uStack21;
  u8 local_14;
  u8 uStack19;
  u8 uStack18;
  u8 uStack17;
  u8 local_10;
  u8 uStack15;
  u8 uStack14;
  u8 uStack13;
  u8 local_c;
  u8 uStack11;
  u8 uStack10;
  u8 uStack9;
  
  uVar1 = *(undefined4 *)param_1;
  local_c = (u8)((uint)uVar1 >> 0x18);
  (this->field_0xf4).r = local_c;
  uStack11 = (u8)((uint)uVar1 >> 0x10);
  (this->field_0xf4).g = uStack11;
  uStack10 = (u8)((uint)uVar1 >> 8);
  (this->field_0xf4).b = uStack10;
  uStack9 = (u8)uVar1;
  (this->field_0xf4).a = uStack9;
  uVar1 = *(undefined4 *)param_2;
  local_10 = (u8)((uint)uVar1 >> 0x18);
  (this->field_0xf8).r = local_10;
  uStack15 = (u8)((uint)uVar1 >> 0x10);
  (this->field_0xf8).g = uStack15;
  uStack14 = (u8)((uint)uVar1 >> 8);
  (this->field_0xf8).b = uStack14;
  uStack13 = (u8)uVar1;
  (this->field_0xf8).a = uStack13;
  uVar1 = *(undefined4 *)param_3;
  local_14 = (u8)((uint)uVar1 >> 0x18);
  (this->field_0xfc).r = local_14;
  uStack19 = (u8)((uint)uVar1 >> 0x10);
  (this->field_0xfc).g = uStack19;
  uStack18 = (u8)((uint)uVar1 >> 8);
  (this->field_0xfc).b = uStack18;
  uStack17 = (u8)uVar1;
  (this->field_0xfc).a = uStack17;
  uVar1 = *(undefined4 *)param_4;
  local_18 = (u8)((uint)uVar1 >> 0x18);
  (this->field_0x100).r = local_18;
  uStack23 = (u8)((uint)uVar1 >> 0x10);
  (this->field_0x100).g = uStack23;
  uStack22 = (u8)((uint)uVar1 >> 8);
  (this->field_0x100).b = uStack22;
  uStack21 = (u8)uVar1;
  (this->field_0x100).a = uStack21;
  return;
}


/* __thiscall J2DWindow::drawSelf(float,
                                  float) */

void __thiscall J2DWindow::drawSelf(J2DWindow *this,float param_1,float param_2)

{
  double dVar1;
  double dVar2;
  MTX34 MStack72;
  
  dVar2 = (double)param_2;
  dVar1 = (double)param_1;
  mtx::PSMTXIdentity(&MStack72);
  (*(code *)((this->parent).vtbl)->drawSelf2)(dVar1,dVar2,this,&MStack72);
  return;
}


/* __thiscall J2DWindow::drawSelf(float,
                                  float,
                                  float *[][][]) */

void __thiscall J2DWindow::drawSelf(J2DWindow *this,float param_1,float param_2,float *param_3)

{
  TBox2_float_ local_58;
  MTX34 MStack72;
  undefined4 local_18;
  uint uStack20;
  
  local_58.mTL.x = (this->parent).mScreenPos.mTL.x + param_1;
  local_58.mTL.y = (this->parent).mScreenPos.mTL.y + param_2;
  local_58.mBR.x = (this->parent).mScreenPos.mBR.x + param_1;
  local_58.mBR.y = (this->parent).mScreenPos.mBR.y + param_2;
  uStack20 = (int)(short)this->mTextureWidth ^ 0x80000000;
  local_18 = 0x43300000;
  if ((float)((double)CONCAT44(0x43300000,uStack20) - J2DGraph::_1042) <=
      local_58.mBR.x - local_58.mTL.x) {
    uStack20 = (int)(short)this->mTextureHeight ^ 0x80000000;
    local_18 = 0x43300000;
    if ((float)((double)CONCAT44(0x43300000,uStack20) - J2DGraph::_1042) <=
        local_58.mBR.y - local_58.mTL.y) {
      mtx::PSMTXConcat((MTX34 *)param_3,&(this->parent).mDrawMtx,&MStack72);
      gx::GXLoadPosMtxImm(&MStack72,0);
      draw_private(this,&local_58,&this->mWindowBox);
    }
  }
  J2DPane::clip(&this->parent,&this->mWindowBox);
  return;
}


/* __thiscall J2DWindow::drawContents(JGeometry::TBox2<float><float> const &) */

void __thiscall J2DWindow::drawContents(J2DWindow *this,TBox2_float_ *param_1)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  uint uVar4;
  _GXColor local_18;
  _GXColor local_14;
  _GXColor local_10;
  _GXColor local_c;
  
  bVar3 = false;
  if ((param_1->mTL).x <= (param_1->mBR).x) {
    if ((param_1->mTL).y <= (param_1->mBR).y) {
      bVar3 = true;
    }
  }
  if (bVar3) {
    gx::GXSetNumChans(1);
    gx::GXSetNumTexGens(0);
    gx::GXSetNumTevStages(1);
    gx::GXSetTevOp(0,4);
    gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
    if ((((((uint)this->field_0xf4 & 0xff) == 0xff) && (((uint)this->field_0xf8 & 0xff) == 0xff)) &&
        (((uint)this->field_0xfc & 0xff) == 0xff)) &&
       ((((uint)this->field_0x100 & 0xff) == 0xff && ((this->parent).mDrawAlpha == 0xff)))) {
      gx::GXSetBlendMode(GX_BM_NONE,GX_BL_ONE,GX_BL_ZERO,GX_LO_SET);
    }
    else {
      gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
    }
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
    gx::GXSetVtxDesc(GX_VA_CLR0,GX_DIRECT);
    local_c = this->field_0xf4;
    local_10 = this->field_0xfc;
    local_14 = this->field_0xf8;
    local_18 = this->field_0x100;
    uVar4 = (uint)(this->parent).mDrawAlpha;
    if (uVar4 != 0xff) {
      local_c = (_GXColor)
                ((uint)local_c & 0xffffff00 | (((uint)local_c & 0xff) * uVar4) / 0xff & 0xff);
      local_10 = (_GXColor)
                 ((uint)local_10 & 0xffffff00 | (((uint)local_10 & 0xff) * uVar4) / 0xff & 0xff);
      local_14 = (_GXColor)
                 ((uint)local_14 & 0xffffff00 | (((uint)local_14 & 0xff) * uVar4) / 0xff & 0xff);
      local_18 = (_GXColor)
                 ((uint)local_18 & 0xffffff00 | (((uint)local_18 & 0xff) * uVar4) / 0xff & 0xff);
    }
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
    gx::GXBegin(0x80,0,4);
    write_volatile_4(0xcc008000,(param_1->mTL).x);
    write_volatile_4(0xcc008000,(param_1->mTL).y);
    write_volatile_4(0xcc008000,J2DGraph::_1034);
    write_volatile_4(0xcc008000,local_c);
    write_volatile_4(0xcc008000,(param_1->mBR).x);
    write_volatile_4(0xcc008000,(param_1->mTL).y);
    write_volatile_4(0xcc008000,J2DGraph::_1034);
    write_volatile_4(0xcc008000,local_14);
    write_volatile_4(0xcc008000,(param_1->mBR).x);
    write_volatile_4(0xcc008000,(param_1->mBR).y);
    write_volatile_4(0xcc008000,J2DGraph::_1034);
    write_volatile_4(0xcc008000,local_18);
    write_volatile_4(0xcc008000,(param_1->mTL).x);
    write_volatile_4(0xcc008000,(param_1->mBR).y);
    write_volatile_4(0xcc008000,J2DGraph::_1034);
    write_volatile_4(0xcc008000,local_10);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
    if (this->mpTexture[4] != (JUTTexture *)0x0) {
      gx::GXClearVtxDesc();
      gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
      gx::GXSetVtxDesc(GX_VA_CLR0,GX_DIRECT);
      gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
      gx::GXSetNumTexGens(1);
      fVar1 = (param_1->mTL).y;
      fVar2 = (param_1->mTL).x;
      drawContentsTexture(this,fVar2,fVar1,(param_1->mBR).x - fVar2,(param_1->mBR).y - fVar1);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x802d26bc) */
/* WARNING: Removing unreachable block (ram,0x802d26ac) */
/* WARNING: Removing unreachable block (ram,0x802d26b4) */
/* WARNING: Removing unreachable block (ram,0x802d26c4) */
/* __thiscall J2DWindow::drawFrameTexture(JUTTexture *,
                                          float,
                                          float,
                                          float,
                                          float,
                                          unsigned short,
                                          unsigned short,
                                          unsigned short,
                                          unsigned short,
                                          bool) */

void __thiscall
J2DWindow::drawFrameTexture
          (J2DWindow *this,JUTTexture *param_1,float param_2,float param_3,float param_4,
          float param_5,ushort param_6,ushort param_7,ushort param_8,ushort param_9,bool param_10)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar4;
  undefined8 in_f31;
  double dVar5;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar3 = (double)param_3;
  dVar2 = (double)param_2;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  dVar5 = (double)(float)(dVar2 + (double)param_4);
  dVar4 = (double)(float)(dVar3 + (double)param_5);
  if (param_10 != false) {
    JUTTexture::load(param_1,0);
    local_68 = *(undefined4 *)&this->field_0x104;
    local_64 = *(undefined4 *)&this->field_0x108;
    setTevMode(this,param_1,(TColor)&local_64,(TColor)&local_68);
  }
  local_60 = (this->parent).mDrawAlpha | 0xffffff00;
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXBegin(0x80,0,4);
  write_volatile_4(0xcc008000,(float)dVar2);
  write_volatile_4(0xcc008000,(float)dVar3);
  write_volatile_4(0xcc008000,J2DGraph::_1034);
  write_volatile_4(0xcc008000,local_60);
  write_volatile_2(0xcc008000,param_8);
  write_volatile_2(0xcc008000,param_9);
  write_volatile_4(0xcc008000,(float)dVar5);
  write_volatile_4(0xcc008000,(float)dVar3);
  write_volatile_4(0xcc008000,J2DGraph::_1034);
  write_volatile_4(0xcc008000,local_60);
  write_volatile_2(0xcc008000,param_6);
  write_volatile_2(0xcc008000,param_9);
  write_volatile_4(0xcc008000,(float)dVar5);
  write_volatile_4(0xcc008000,(float)dVar4);
  write_volatile_4(0xcc008000,J2DGraph::_1034);
  write_volatile_4(0xcc008000,local_60);
  write_volatile_2(0xcc008000,param_6);
  write_volatile_2(0xcc008000,param_7);
  write_volatile_4(0xcc008000,(float)dVar2);
  write_volatile_4(0xcc008000,(float)dVar4);
  write_volatile_4(0xcc008000,J2DGraph::_1034);
  write_volatile_4(0xcc008000,local_60);
  write_volatile_2(0xcc008000,param_8);
  write_volatile_2(0xcc008000,param_7);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
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


/* __thiscall J2DWindow::drawFrameTexture(JUTTexture *,
                                          float,
                                          float,
                                          bool,
                                          bool,
                                          bool) */

void __thiscall
J2DWindow::drawFrameTexture
          (J2DWindow *this,JUTTexture *param_1,float param_2,float param_3,bool param_4,bool param_5
          ,bool param_6)

{
  drawFrameTexture(this,param_1,param_2,param_3,
                   (float)((double)CONCAT44(0x43300000,param_1->mpTIMG->mWidth ^ 0x80000000) -
                          J2DGraph::_1042),
                   (float)((double)CONCAT44(0x43300000,param_1->mpTIMG->mHeight ^ 0x80000000) -
                          J2DGraph::_1042),~-(ushort)(param_4 != false) & 0x8000,
                   ~-(ushort)(param_5 != false) & 0x8000,-(ushort)(param_4 != false) & 0x8000,
                   -(ushort)(param_5 != false) & 0x8000,param_6);
  return;
}


/* WARNING: Removing unreachable block (ram,0x802d29d0) */
/* WARNING: Removing unreachable block (ram,0x802d29c0) */
/* WARNING: Removing unreachable block (ram,0x802d29b0) */
/* WARNING: Removing unreachable block (ram,0x802d29a0) */
/* WARNING: Removing unreachable block (ram,0x802d29a8) */
/* WARNING: Removing unreachable block (ram,0x802d29b8) */
/* WARNING: Removing unreachable block (ram,0x802d29c8) */
/* WARNING: Removing unreachable block (ram,0x802d29d8) */
/* __thiscall J2DWindow::drawContentsTexture(float,
                                             float,
                                             float,
                                             float) */

void __thiscall
J2DWindow::drawContentsTexture
          (J2DWindow *this,float param_1,float param_2,float param_3,float param_4)

{
  ResTIMG *pRVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f24;
  undefined8 in_f25;
  double dVar7;
  undefined8 in_f26;
  double dVar8;
  undefined8 in_f27;
  double dVar9;
  undefined8 in_f28;
  double dVar10;
  undefined8 in_f29;
  double dVar11;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  uint uStack148;
  undefined4 local_90;
  uint uStack140;
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar4 = (double)param_2;
  dVar3 = (double)param_1;
  uVar2 = 0;
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
  dVar11 = (double)(float)(dVar3 + (double)param_3);
  dVar10 = (double)(float)(dVar4 + (double)param_4);
  pRVar1 = this->mpTexture[4]->mpTIMG;
  uStack148 = pRVar1->mWidth ^ 0x80000000;
  local_98 = 0x43300000;
  uStack140 = pRVar1->mHeight ^ 0x80000000;
  local_90 = 0x43300000;
  dVar5 = (double)(float)((double)param_3 /
                         (double)(float)((double)CONCAT44(0x43300000,uStack148) - J2DGraph::_1042));
  dVar9 = (double)(-(float)(dVar5 - (double)J2DGraph::_1673) * J2DGraph::_1674);
  dVar6 = (double)(float)((double)param_4 /
                         (double)(float)((double)CONCAT44(0x43300000,uStack140) - J2DGraph::_1042));
  dVar8 = (double)(-(float)(dVar6 - (double)J2DGraph::_1673) * J2DGraph::_1674);
  dVar7 = (double)(float)(dVar9 + dVar5);
  dVar5 = (double)(float)(dVar8 + dVar6);
  JUTTexture::load(this->mpTexture[4],0);
  local_a4 = 0xffffffff;
  local_a0 = 0;
  local_9c = 0;
  setTevMode(this,this->mpTexture[4],(TColor)&local_9c,(TColor)&local_a4);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXBegin(0x80,0,4);
  write_volatile_4(0xcc008000,(float)dVar3);
  write_volatile_4(0xcc008000,(float)dVar4);
  write_volatile_4(0xcc008000,J2DGraph::_1034);
  write_volatile_4(0xcc008000,(this->parent).mDrawAlpha | 0xffffff00);
  write_volatile_4(0xcc008000,(float)dVar9);
  write_volatile_4(0xcc008000,(float)dVar8);
  write_volatile_4(0xcc008000,(float)dVar11);
  write_volatile_4(0xcc008000,(float)dVar4);
  write_volatile_4(0xcc008000,J2DGraph::_1034);
  write_volatile_4(0xcc008000,(this->parent).mDrawAlpha | 0xffffff00);
  write_volatile_4(0xcc008000,(float)dVar7);
  write_volatile_4(0xcc008000,(float)dVar8);
  write_volatile_4(0xcc008000,(float)dVar11);
  write_volatile_4(0xcc008000,(float)dVar10);
  write_volatile_4(0xcc008000,J2DGraph::_1034);
  write_volatile_4(0xcc008000,(this->parent).mDrawAlpha | 0xffffff00);
  write_volatile_4(0xcc008000,(float)dVar7);
  write_volatile_4(0xcc008000,(float)dVar5);
  write_volatile_4(0xcc008000,(float)dVar3);
  write_volatile_4(0xcc008000,(float)dVar10);
  write_volatile_4(0xcc008000,J2DGraph::_1034);
  write_volatile_4(0xcc008000,(this->parent).mDrawAlpha | 0xffffff00);
  write_volatile_4(0xcc008000,(float)dVar9);
  write_volatile_4(0xcc008000,(float)dVar5);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBX8,0xf);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  __psq_l0(auStack56,uVar2);
  __psq_l1(auStack56,uVar2);
  __psq_l0(auStack72,uVar2);
  __psq_l1(auStack72,uVar2);
  __psq_l0(auStack88,uVar2);
  __psq_l1(auStack88,uVar2);
  __psq_l0(auStack104,uVar2);
  __psq_l1(auStack104,uVar2);
  __psq_l0(auStack120,uVar2);
  __psq_l1(auStack120,uVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J2DWindow::setTevMode(JUTTexture *,
                                    JUtility::TColor,
                                    JUtility::TColor) */

void __thiscall
J2DWindow::setTevMode(J2DWindow *this,JUTTexture *param_1,TColor param_2,TColor param_3)

{
  byte bVar1;
  GXTevStageID GVar2;
  _GXColor local_38;
  _GXColor local_34;
  undefined4 local_30;
  _GXColor local_2c;
  undefined4 local_28;
  _GXColor local_24 [4];
  
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR0A0);
  if ((((this->parent).mDrawAlpha == 0xff) && (*(int *)param_2 == 0)) && (*(int *)param_3 == -1)) {
    bVar1 = param_1->mpTIMG->mTranslucency;
    gx::GXSetNumTevStages(1);
    if (this->mpPallete != (JUTPalette *)0x0) {
      bVar1 = this->mpPallete->mTransparency;
    }
    if (bVar1 == 0) {
      local_28 = 0xffffffff;
      local_24[0] = (_GXColor)0xffffffff;
      gx::GXSetTevColor(GX_TEVREG2,local_24);
      gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_TEXC,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO);
      gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_A2,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
      gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetBlendMode(GX_BM_NONE,GX_BL_ONE,GX_BL_ZERO,GX_LO_SET);
    }
    else {
      gx::GXSetTevOp(0,3);
      gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
    }
  }
  else {
    GVar2 = GX_TEVSTAGE1;
    local_30 = 0xffffffff;
    local_2c = (_GXColor)0xffffffff;
    gx::GXSetTevColor(GX_TEVREG2,&local_2c);
    gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_TEXC,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO);
    if (param_1->mpTIMG->mTranslucency == 0) {
      gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_A2,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
    }
    else {
      gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_TEXA,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
    }
    gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    if ((*(int *)param_2 != 0) || (*(int *)param_3 != -1)) {
      gx::GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
      local_34 = *(_GXColor *)param_2;
      gx::GXSetTevColor(GX_TEVREG0,&local_34);
      local_38 = *(_GXColor *)param_3;
      gx::GXSetTevColor(GX_TEVREG1,&local_38);
      gx::GXSetTevColorIn(GX_TEVSTAGE1,GX_CC_C0,GX_CC_C1,GX_CC_CPREV,GX_CC_ZERO);
      gx::GXSetTevAlphaIn(GX_TEVSTAGE1,GX_CA_A0,GX_CA_A1,GX_CA_APREV,GX_CA_ZERO);
      gx::GXSetTevColorOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetTevAlphaOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      GVar2 = GX_TEVSTAGE2;
    }
    if ((this->parent).mDrawAlpha != 0xff) {
      gx::GXSetTevOrder(GVar2,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
      gx::GXSetTevColorIn(GVar2,GX_CC_CPREV,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO);
      gx::GXSetTevAlphaIn(GVar2,GX_CA_ZERO,GX_CA_APREV,GX_CA_RASA,GX_CA_ZERO);
      gx::GXSetTevColorOp(GVar2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetTevAlphaOp(GVar2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      GVar2 = GVar2 + GX_TEVSTAGE1;
    }
    gx::GXSetNumTevStages(GVar2);
    gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
  }
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  return;
}


/* __thiscall J2DWindow::getTypeID(void) */

J2DTypeID __thiscall J2DWindow::getTypeID(J2DWindow *this)

{
  return J2DWindow;
}

