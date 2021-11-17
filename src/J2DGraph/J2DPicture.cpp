#include <J2DGraph/J2DPicture.h>
#include <J2DGraph/J2DPane.h>
#include <d_file_select.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <J2DGraph/J2DPicture.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JSupport/JSUInputStream.h>
#include <JUtility/JUTResource.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTTexture.h>
#include <JUtility/JUTPalette.h>
#include <JKernel/JKRFileLoader.h>
#include <mtx/mtx.h>
#include <gx/GXAttr.h>
#include <gx/GXTransform.h>
#include <gx/GXGeometry.h>
#include <gx/GXTev.h>
#include <gx/GXPixel.h>
#include <gx/GXLight.h>
#include <Demangler/J2DPicture.h>


/* __thiscall J2DPicture::J2DPicture(void) */

void __thiscall J2DPicture::J2DPicture(J2DPicture *this)

{
  J2DPane::J2DPane(&this->parent);
  (this->parent).vtbl = (J2DPane__vtable *)&__vt;
  this->mColorBase = (_GXColor)0xffffffff;
  this->mBgColor = (_GXColor)0xffffffff;
  Runtime.PPCEABI.H::__construct_array
            (this->mNewColor,JUtility::TColor::TColor,(undefined *)0x0,4,4);
  this->mBlendKonstColor = (_GXColor)0xffffffff;
  this->mBlendKonstAlpha = (_GXColor)0xffffffff;
  this->mpTexture[0] = (JUTTexture *)0x0;
  this->mNumTexture = 0;
  this->mpPalette = (JUTPalette *)0x0;
  initinfo(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall J2DPicture::J2DPicture(J2DPane *,
                                     JSURandomInputStream *) */

void __thiscall
J2DPicture::J2DPicture(J2DPicture *this,J2DPane *param_1,JSURandomInputStream *param_2)

{
  float fVar1;
  int iVar2;
  ResTIMG *pRVar3;
  ResTLUT *pRVar4;
  JUTTexture *this_00;
  JUTPalette *this_01;
  int iVar5;
  int iVar6;
  char cVar7;
  undefined uStack376;
  byte local_177;
  byte local_176;
  char local_175;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  int local_130;
  JUTResReference local_12c [268];
  
  J2DPane::J2DPane(&this->parent);
  (this->parent).vtbl = (J2DPane__vtable *)&__vt;
  this->mpPalette = (JUTPalette *)0x0;
  this->mColorBase = (_GXColor)0xffffffff;
  this->mBgColor = (_GXColor)0xffffffff;
  Runtime.PPCEABI.H::__construct_array
            (this->mNewColor,JUtility::TColor::TColor,(undefined *)0x0,4,4);
  this->mBlendKonstColor = (_GXColor)0xffffffff;
  this->mBlendKonstAlpha = (_GXColor)0xffffffff;
  iVar2 = (**(code **)(*(int *)param_2 + 0x1c))(param_2);
  JSUInputStream::read((JSUInputStream *)param_2,&local_134,8);
  *(undefined4 *)(this->parent).mMagic = local_134;
  J2DPane::makePaneStream(&this->parent,param_1,param_2);
  local_12c[0] = (JUTResReference)0x0;
  JSUInputStream::read((JSUInputStream *)param_2,&local_175,1);
  pRVar3 = (ResTIMG *)
           JUTResReference::getResource
                     (local_12c,(JSUInputStream *)param_2,0x54494d47,(JKRArchive *)0x0);
  pRVar4 = (ResTLUT *)
           JUTResReference::getResource
                     (local_12c,(JSUInputStream *)param_2,0x544c5554,(JKRArchive *)0x0);
  JSUInputStream::read((JSUInputStream *)param_2,&local_176,1);
  this->field_0xde = local_176;
  cVar7 = local_175 + -3;
  if (local_175 == '\x03') {
    this->field_0xdf = 0;
  }
  else {
    JSUInputStream::read((JSUInputStream *)param_2,&local_177,1);
    this->field_0xdf = local_177;
    cVar7 = local_175 + -4;
  }
  if (cVar7 != '\0') {
    JSUInputStream::read((JSUInputStream *)param_2,&uStack376,1);
    cVar7 = cVar7 + -1;
  }
  local_138 = 0;
  (this->mBgColor).r = 0;
  (this->mBgColor).g = 0;
  (this->mBgColor).b = 0;
  (this->mBgColor).a = 0;
  local_13c = 0xffffffff;
  (this->mColorBase).r = 0xff;
  (this->mColorBase).g = 0xff;
  (this->mColorBase).b = 0xff;
  (this->mColorBase).a = 0xff;
  if (cVar7 != '\0') {
    JSUInputStream::read((JSUInputStream *)param_2,&local_16c,4);
    local_140 = local_16c;
    local_140._0_1_ = (u8)((uint)local_16c >> 0x18);
    (this->mBgColor).r = local_140._0_1_;
    local_140._1_1_ = (u8)((uint)local_16c >> 0x10);
    (this->mBgColor).g = local_140._1_1_;
    local_140._2_1_ = (u8)((uint)local_16c >> 8);
    (this->mBgColor).b = local_140._2_1_;
    local_140._3_1_ = (u8)local_16c;
    (this->mBgColor).a = (u8)local_140;
    cVar7 = cVar7 + -1;
  }
  if (cVar7 != '\0') {
    JSUInputStream::read((JSUInputStream *)param_2,&local_170,4);
    local_144 = local_170;
    local_144._0_1_ = (u8)((uint)local_170 >> 0x18);
    (this->mColorBase).r = local_144._0_1_;
    local_144._1_1_ = (u8)((uint)local_170 >> 0x10);
    (this->mColorBase).g = local_144._1_1_;
    local_144._2_1_ = (u8)((uint)local_170 >> 8);
    (this->mColorBase).b = local_144._2_1_;
    local_144._3_1_ = (u8)local_170;
    (this->mColorBase).a = (u8)local_144;
    cVar7 = cVar7 + -1;
  }
  local_164 = 0xffffffff;
  local_160 = 0xffffffff;
  local_15c = 0xffffffff;
  local_158 = 0xffffffff;
  local_154 = 0xffffffff;
  local_150 = 0xffffffff;
  local_14c = 0xffffffff;
  local_148 = 0xffffffff;
  this->mNewColor[0].r = 0xff;
  this->mNewColor[0].g = 0xff;
  this->mNewColor[0].b = 0xff;
  this->mNewColor[0].a = 0xff;
  this->mNewColor[1].r = 0xff;
  this->mNewColor[1].g = 0xff;
  this->mNewColor[1].b = 0xff;
  this->mNewColor[1].a = 0xff;
  this->mNewColor[2].r = 0xff;
  this->mNewColor[2].g = 0xff;
  this->mNewColor[2].b = 0xff;
  this->mNewColor[2].a = 0xff;
  this->mNewColor[3].r = 0xff;
  this->mNewColor[3].g = 0xff;
  this->mNewColor[3].b = 0xff;
  this->mNewColor[3].a = 0xff;
  iVar5 = 0;
  for (iVar6 = 0; (cVar7 != '\0' && (iVar6 < 4)); iVar6 = iVar6 + 1) {
    JSUInputStream::read((JSUInputStream *)param_2,&local_174,4);
    local_168 = local_174;
    local_168._0_1_ = (u8)((uint)local_174 >> 0x18);
    (&this->mNewColor[0].r)[iVar5] = local_168._0_1_;
    local_168._1_1_ = (u8)((uint)local_174 >> 0x10);
    (&this->mNewColor[0].g)[iVar5] = local_168._1_1_;
    local_168._2_1_ = (u8)((uint)local_174 >> 8);
    (&this->mNewColor[0].b)[iVar5] = local_168._2_1_;
    local_168._3_1_ = (u8)local_174;
    (&this->mNewColor[0].a)[iVar5] = (u8)local_168;
    cVar7 = cVar7 + -1;
    iVar5 = iVar5 + 4;
  }
  JSURandomInputStream::seek(param_2,iVar2 + local_130,0);
  this->mpTexture[0] = (JUTTexture *)0x0;
  this->mNumTexture = 0;
  this->field_0xdd = 1;
  if (pRVar3 != (ResTIMG *)0x0) {
    this_00 = (JUTTexture *)JKernel::operator_new(0x40);
    if (this_00 != (JUTTexture *)0x0) {
      this_00->mpPalette = (JUTPalette *)0x0;
      JUTTexture::storeTIMG(this_00,pRVar3,'\0');
      this_00->field_0x3b = this_00->field_0x3b & 2;
    }
    this->mpTexture[0] = this_00;
    this->mNumTexture = this->mNumTexture + 1;
  }
  if (pRVar4 != (ResTLUT *)0x0) {
    this_01 = (JUTPalette *)JKernel::operator_new(0x18);
    if (this_01 != (JUTPalette *)0x0) {
      JUTPalette::storeTLUT(this_01,0,pRVar4);
    }
    this->mpPalette = this_01;
    JUTTexture::attachPalette(this->mpTexture[0],this->mpPalette);
  }
  fVar1 = J2DGraph::1_0;
  this->mBlendKonstColorF[0] = J2DGraph::1_0;
  this->mBlendKonstColorF[1] = fVar1;
  this->mBlendKonstColorF[2] = fVar1;
  this->mBlendKonstColorF[3] = fVar1;
  setBlendKonstColor(this);
  fVar1 = J2DGraph::1_0;
  this->mBlendKonstAlphaF[0] = J2DGraph::1_0;
  this->mBlendKonstAlphaF[1] = fVar1;
  this->mBlendKonstAlphaF[2] = fVar1;
  this->mBlendKonstAlphaF[3] = fVar1;
  setBlendKonstAlpha(this);
  return;
}


/* __thiscall J2DPicture::J2DPicture(ResTIMG const *) */

void __thiscall J2DPicture::J2DPicture(J2DPicture *this,ResTIMG *param_1)

{
  J2DPane::J2DPane(&this->parent);
  (this->parent).vtbl = (J2DPane__vtable *)&__vt;
  this->mColorBase = (_GXColor)0xffffffff;
  this->mBgColor = (_GXColor)0xffffffff;
  Runtime.PPCEABI.H::__construct_array
            (this->mNewColor,JUtility::TColor::TColor,(undefined *)0x0,4,4);
  this->mBlendKonstColor = (_GXColor)0xffffffff;
  this->mBlendKonstAlpha = (_GXColor)0xffffffff;
  this->mpTexture[0] = (JUTTexture *)0x0;
  this->mNumTexture = 0;
  if (param_1 != (ResTIMG *)0x0) {
    insert(this,param_1,this->mNumTexture,J2DGraph::1_0);
  }
  this->mpPalette = (JUTPalette *)0x0;
  initinfo(this);
  return;
}


/* __thiscall J2DPicture::J2DPicture(char const *) */

void __thiscall J2DPicture::J2DPicture(J2DPicture *this,char *param_1)

{
  J2DPane::J2DPane(&this->parent);
  (this->parent).vtbl = (J2DPane__vtable *)&__vt;
  this->mColorBase = (_GXColor)0xffffffff;
  this->mBgColor = (_GXColor)0xffffffff;
  Runtime.PPCEABI.H::__construct_array
            (this->mNewColor,JUtility::TColor::TColor,(undefined *)0x0,4,4);
  this->mBlendKonstColor = (_GXColor)0xffffffff;
  this->mBlendKonstAlpha = (_GXColor)0xffffffff;
  this->mpTexture[0] = (JUTTexture *)0x0;
  this->mNumTexture = 0;
  if (param_1 != (char *)0x0) {
    insert(this,param_1,this->mNumTexture,J2DGraph::1_0);
  }
  this->mpPalette = (JUTPalette *)0x0;
  initinfo(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J2DPicture::J2DPicture(unsigned long,
                                     JGeometry::TBox2<float><float> const &,
                                     ResTIMG const *,
                                     ResTLUT const *) */

void __thiscall
J2DPicture::J2DPicture
          (J2DPicture *this,ulong param_1,TBox2_float_ *param_2,ResTIMG *param_3,ResTLUT *param_4)

{
  J2DPane::J2DPane(&this->parent,param_1,param_2);
  (this->parent).vtbl = (J2DPane__vtable *)&__vt;
  this->mpPalette = (JUTPalette *)0x0;
  this->mColorBase = (_GXColor)0xffffffff;
  this->mBgColor = (_GXColor)0xffffffff;
  Runtime.PPCEABI.H::__construct_array
            (this->mNewColor,JUtility::TColor::TColor,(undefined *)0x0,4,4);
  this->mBlendKonstColor = (_GXColor)0xffffffff;
  this->mBlendKonstAlpha = (_GXColor)0xffffffff;
  private_initiate(this,param_3,param_4);
  initinfo(this);
  return;
}


/* __thiscall J2DPicture::initiate(ResTIMG const *,
                                   ResTLUT const *) */

void __thiscall J2DPicture::initiate(J2DPicture *this,ResTIMG *param_1,ResTLUT *param_2)

{
  double dVar1;
  double dVar2;
  float fVar3;
  ResTIMG *pRVar4;
  
  private_initiate(this,param_1,param_2);
  fVar3 = J2DGraph::_729;
  if (this->mpTexture[0] != (JUTTexture *)0x0) {
    pRVar4 = this->mpTexture[0]->mpTIMG;
    dVar1 = (double)CONCAT44(0x43300000,pRVar4->mWidth ^ 0x80000000) - J2DGraph::_733;
    dVar2 = (double)CONCAT44(0x43300000,pRVar4->mHeight ^ 0x80000000) - J2DGraph::_733;
    (this->parent).mPosTL.x = J2DGraph::_729;
    (this->parent).mPosTL.y = fVar3;
    (this->parent).mPosBR.x = (float)dVar1;
    (this->parent).mPosBR.y = (float)dVar2;
    (*(code *)((this->parent).vtbl)->calcMtx)(this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J2DPicture::private_initiate(ResTIMG const *,
                                           ResTLUT const *) */

void __thiscall J2DPicture::private_initiate(J2DPicture *this,ResTIMG *param_1,ResTLUT *param_2)

{
  JUTTexture *this_00;
  JUTPalette *this_01;
  
  this->mpTexture[0] = (JUTTexture *)0x0;
  this->field_0xdd = 1;
  this->mNumTexture = 0;
  if (param_1 != (ResTIMG *)0x0) {
    this_00 = (JUTTexture *)JKernel::operator_new(0x40);
    if (this_00 != (JUTTexture *)0x0) {
      this_00->mpPalette = (JUTPalette *)0x0;
      JUTTexture::storeTIMG(this_00,param_1,'\0');
      this_00->field_0x3b = this_00->field_0x3b & 2;
    }
    this->mpTexture[0] = this_00;
    this->mNumTexture = this->mNumTexture + 1;
  }
  this->mpPalette = (JUTPalette *)0x0;
  if (param_2 != (ResTLUT *)0x0) {
    this_01 = (JUTPalette *)JKernel::operator_new(0x18);
    if (this_01 != (JUTPalette *)0x0) {
      JUTPalette::storeTLUT(this_01,0,param_2);
    }
    this->mpPalette = this_01;
    JUTTexture::attachPalette(this->mpTexture[0],this->mpPalette);
  }
  return;
}


/* __thiscall J2DPicture::initinfo(void) */

void __thiscall J2DPicture::initinfo(J2DPicture *this)

{
  float fVar1;
  
  *(undefined4 *)(this->parent).mMagic = 0x50494331;
  this->field_0xde = 0xf;
  this->field_0xdf = this->field_0xdf & 4;
  this->field_0xdf = this->field_0xdf & 3;
  fVar1 = J2DGraph::1_0;
  this->mBlendKonstColorF[0] = J2DGraph::1_0;
  this->mBlendKonstColorF[1] = fVar1;
  this->mBlendKonstColorF[2] = fVar1;
  this->mBlendKonstColorF[3] = fVar1;
  setBlendKonstColor(this);
  fVar1 = J2DGraph::1_0;
  this->mBlendKonstAlphaF[0] = J2DGraph::1_0;
  this->mBlendKonstAlphaF[1] = fVar1;
  this->mBlendKonstAlphaF[2] = fVar1;
  this->mBlendKonstAlphaF[3] = fVar1;
  setBlendKonstAlpha(this);
  (this->mBgColor).r = 0;
  (this->mBgColor).g = 0;
  (this->mBgColor).b = 0;
  (this->mBgColor).a = 0;
  (this->mColorBase).r = 0xff;
  (this->mColorBase).g = 0xff;
  (this->mColorBase).b = 0xff;
  (this->mColorBase).a = 0xff;
  this->mNewColor[0].r = 0xff;
  this->mNewColor[0].g = 0xff;
  this->mNewColor[0].b = 0xff;
  this->mNewColor[0].a = 0xff;
  this->mNewColor[1].r = 0xff;
  this->mNewColor[1].g = 0xff;
  this->mNewColor[1].b = 0xff;
  this->mNewColor[1].a = 0xff;
  this->mNewColor[2].r = 0xff;
  this->mNewColor[2].g = 0xff;
  this->mNewColor[2].b = 0xff;
  this->mNewColor[2].a = 0xff;
  this->mNewColor[3].r = 0xff;
  this->mNewColor[3].g = 0xff;
  this->mNewColor[3].b = 0xff;
  this->mNewColor[3].a = 0xff;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J2DPicture::~J2DPicture(void) */

void __thiscall J2DPicture::_J2DPicture(J2DPicture *this,short flag)

{
  int iVar1;
  int iVar2;
  
  if (this != (J2DPicture *)0x0) {
    (this->parent).vtbl = (J2DPane__vtable *)&__vt;
    iVar1 = 0;
    iVar2 = 0;
    while( true ) {
      if ((int)(uint)this->mNumTexture <= iVar1) break;
      if (((uint)this->field_0xdd & 1 << iVar1) != 0) {
        JUTTexture::_JUTTexture(*(JUTTexture **)((int)this->mpTexture + iVar2),1);
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 4;
    }
    JKernel::operator_delete((JKRHeap *)this->mpPalette);
    J2DPane::_J2DPane(&this->parent,0);
    if (0 < flag) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x802d39e8) */
/* __thiscall J2DPicture::insert(ResTIMG const *,
                                 unsigned char,
                                 float) */

undefined4 __thiscall
J2DPicture::insert(J2DPicture *this,ResTIMG *param_1,uchar param_2,float param_3)

{
  double dVar1;
  float fVar2;
  undefined4 uVar3;
  JUTTexture *this_00;
  ResTIMG *pRVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  double dVar9;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar9 = (double)param_3;
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if ((((param_1 == (ResTIMG *)0x0) || (3 < this->mNumTexture)) || (3 < param_2)) ||
     (this->mNumTexture < param_2)) {
    uVar3 = 0;
  }
  else {
    this_00 = (JUTTexture *)JKernel::operator_new(0x40);
    if (this_00 != (JUTTexture *)0x0) {
      this_00->mpPalette = (JUTPalette *)0x0;
      JUTTexture::storeTIMG(this_00,param_1,'\0');
      this_00->field_0x3b = this_00->field_0x3b & 2;
    }
    for (uVar6 = 3; (uint)param_2 < (uVar6 & 0xff); uVar6 = uVar6 - 1) {
      pcVar5 = (this->parent).mMagic + (uVar6 & 0xff) * 4 + -4;
      *(undefined4 *)(pcVar5 + 0xcc) = *(undefined4 *)(pcVar5 + 200);
      *(undefined4 *)(pcVar5 + 0xe0) = *(undefined4 *)(pcVar5 + 0xdc);
      *(undefined4 *)(pcVar5 + 0xf0) = *(undefined4 *)(pcVar5 + 0xec);
    }
    iVar7 = 1 << (uint)param_2;
    uVar6 = iVar7 - 1;
    this->field_0xdd =
         this->field_0xdd & (byte)uVar6 | (byte)(((uint)this->field_0xdd & ~uVar6) << 1);
    pcVar5 = (this->parent).mMagic + (uint)param_2 * 4 + -4;
    *(JUTTexture **)(pcVar5 + 0xcc) = this_00;
    this->field_0xdd = this->field_0xdd | (byte)iVar7;
    *(float *)(pcVar5 + 0xe0) = (float)dVar9;
    *(float *)(pcVar5 + 0xf0) = (float)dVar9;
    fVar2 = J2DGraph::_729;
    if ((this->mNumTexture == 0) && (this->mpTexture[0] != (JUTTexture *)0x0)) {
      pRVar4 = this->mpTexture[0]->mpTIMG;
      dVar9 = (double)CONCAT44(0x43300000,pRVar4->mWidth ^ 0x80000000) - J2DGraph::_733;
      dVar1 = (double)CONCAT44(0x43300000,pRVar4->mHeight ^ 0x80000000) - J2DGraph::_733;
      (this->parent).mPosTL.x = J2DGraph::_729;
      (this->parent).mPosTL.y = fVar2;
      (this->parent).mPosBR.x = (float)dVar9;
      (this->parent).mPosBR.y = (float)dVar1;
      (*(code *)((this->parent).vtbl)->calcMtx)(this);
    }
    this->mNumTexture = this->mNumTexture + 1;
    setBlendKonstColor(this);
    setBlendKonstAlpha(this);
    uVar3 = 1;
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  return uVar3;
}


/* __thiscall J2DPicture::insert(char const *,
                                 unsigned char,
                                 float) */

void __thiscall J2DPicture::insert(J2DPicture *this,char *param_1,uchar param_2,float param_3)

{
  ResTIMG *pRVar1;
  double dVar2;
  
  dVar2 = (double)param_3;
  pRVar1 = (ResTIMG *)JKRFileLoader::getGlbResource(param_1,(JKRFileLoader *)0x0);
  insert(this,pRVar1,param_2,(float)dVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J2DPicture::remove(unsigned char) */

int __thiscall J2DPicture::remove(J2DPicture *this,char *__filename)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  uVar1 = (uint)__filename & 0xff;
  if ((uVar1 < this->mNumTexture) && (this->mNumTexture != 1)) {
    if (((uint)this->field_0xdd & 1 << uVar1) != 0) {
      JUTTexture::_JUTTexture(this->mpTexture[(uint)__filename & 0xff],1);
    }
    for (; (int)((uint)__filename & 0xff) < (int)(this->mNumTexture - 1);
        __filename = __filename + 1) {
      pcVar3 = (this->parent).mMagic + ((uint)__filename & 0xff) * 4 + -4;
      pcVar4 = (this->parent).mMagic + ((uint)__filename & 0xff) * 4 + -4;
      *(undefined4 *)(pcVar4 + 0xcc) = *(undefined4 *)(pcVar3 + 0xd0);
      *(undefined4 *)(pcVar4 + 0xe0) = *(undefined4 *)(pcVar3 + 0xe4);
      *(undefined4 *)(pcVar4 + 0xf0) = *(undefined4 *)(pcVar3 + 0xf4);
    }
    this->field_0xdd =
         this->field_0xdd & (char)(1 << uVar1) - 1U |
         (byte)((int)((uint)this->field_0xdd & ~((1 << uVar1 + 1) - 1U)) >> 1);
    this->mNumTexture = this->mNumTexture - 1;
    setBlendKonstColor(this);
    setBlendKonstAlpha(this);
    iVar2 = 1;
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


/* __thiscall J2DPicture::changeTexture(ResTIMG const *,
                                        unsigned char) */

ResTIMG * __thiscall J2DPicture::changeTexture(J2DPicture *this,ResTIMG *param_1,uchar param_2)

{
  byte bVar1;
  JUTTexture *pJVar2;
  ResTIMG *pRVar3;
  
  bVar1 = this->mNumTexture;
  if (param_2 < bVar1) {
    if (param_2 < bVar1) {
      pJVar2 = this->mpTexture[param_2];
    }
    else {
      pJVar2 = (JUTTexture *)0x0;
    }
    if ((pJVar2 == (JUTTexture *)0x0) || (param_1 == (ResTIMG *)0x0)) {
      pRVar3 = (ResTIMG *)0x0;
    }
    else {
      if (param_2 < bVar1) {
        pJVar2 = this->mpTexture[param_2];
      }
      else {
        pJVar2 = (JUTTexture *)0x0;
      }
      pRVar3 = pJVar2->mpTIMG;
      if (param_2 < bVar1) {
        pJVar2 = this->mpTexture[param_2];
      }
      else {
        pJVar2 = (JUTTexture *)0x0;
      }
      JUTTexture::storeTIMG(pJVar2,param_1,'\0');
    }
  }
  else {
    pRVar3 = (ResTIMG *)0x0;
  }
  return pRVar3;
}


/* __thiscall J2DPicture::changeTexture(char const *,
                                        unsigned char) */

void __thiscall J2DPicture::changeTexture(J2DPicture *this,char *param_1,byte param_2)

{
  ResTIMG *pRVar1;
  
  pRVar1 = (ResTIMG *)JKRFileLoader::getGlbResource(param_1,(JKRFileLoader *)0x0);
  changeTexture(this,pRVar1,param_2);
  return;
}


/* __thiscall J2DPicture::drawSelf(float,
                                   float) */

void __thiscall J2DPicture::drawSelf(J2DPicture *this,float param_1,float param_2)

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


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x802d404c) */
/* WARNING: Removing unreachable block (ram,0x802d4054) */
/* __thiscall J2DPicture::drawFullSet(float,
                                      float,
                                      float,
                                      float,
                                      J2DBinding,
                                      J2DMirror,
                                      bool,
                                      float *[][][]) */

void __thiscall
J2DPicture::drawFullSet
          (J2DPicture *this,float param_1,J2DBinding binding,J2DMirror mirror,bool param_4,
          MTX34 *pMtx)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  J2DWrapModeType uVar4;
  uint uVar5;
  ResTIMG *pRVar6;
  undefined4 uVar7;
  double dVar8;
  double in_f3;
  double in_f4;
  double dVar9;
  double dVar10;
  undefined8 in_f30;
  undefined8 in_f31;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  undefined4 local_48;
  uint uStack68;
  undefined4 local_40;
  uint uStack60;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (param_4 == false) {
    if ((mirror & 2) == 0) {
      uVar1 = binding >> 3;
    }
    else {
      uVar1 = binding >> 2;
    }
    uVar1 = uVar1 & 1;
    if ((mirror & 2) == 0) {
      uVar2 = binding >> 2;
    }
    else {
      uVar2 = binding >> 3;
    }
    uVar2 = uVar2 & 1;
    uVar5 = binding;
    if ((mirror & 1) == 0) {
      uVar5 = binding >> 1;
    }
    uVar5 = uVar5 & 1;
    if ((mirror & 1) == 0) {
      uVar3 = binding & 1;
    }
    else {
      uVar3 = binding >> 1 & 1;
    }
  }
  else {
    uVar1 = binding;
    if ((mirror & 2) == 0) {
      uVar1 = binding >> 1;
    }
    uVar1 = uVar1 & 1;
    uVar2 = binding;
    if ((mirror & 2) != 0) {
      uVar2 = binding >> 1;
    }
    uVar2 = uVar2 & 1;
    if ((mirror & 1) == 0) {
      uVar5 = binding >> 2;
    }
    else {
      uVar5 = binding >> 3;
    }
    uVar5 = uVar5 & 1;
    if ((mirror & 1) == 0) {
      uVar3 = binding >> 3 & 1;
    }
    else {
      uVar3 = binding >> 2 & 1;
    }
  }
  pRVar6 = this->mpTexture[0]->mpTIMG;
  uStack68 = pRVar6->mWidth ^ 0x80000000;
  local_48 = 0x43300000;
  dVar9 = (double)(float)((double)CONCAT44(0x43300000,uStack68) - J2DGraph::_733);
  uStack60 = pRVar6->mHeight ^ 0x80000000;
  local_40 = 0x43300000;
  dVar10 = (double)(float)((double)CONCAT44(0x43300000,uStack60) - J2DGraph::_733);
  uVar4 = countLeadingZeros((uint)param_4);
  dVar8 = in_f4;
  if ((uVar4 >> 5 & 0xff) != 0) {
    dVar8 = in_f3;
  }
  if ((uVar4 >> 5 & 0xff) != 0) {
    in_f3 = in_f4;
  }
  if (uVar1 == 0) {
    if (uVar2 == 0) {
      local_54 = (float)(dVar8 / dVar9) * J2DGraph::_1093;
      local_4c = J2DGraph::_1093 - local_54;
      local_54 = J2DGraph::_1093 + local_54;
    }
    else {
      local_4c = J2DGraph::1_0 - (float)(dVar8 / dVar9);
      local_54 = J2DGraph::1_0;
    }
  }
  else {
    local_4c = J2DGraph::_729;
    local_54 = J2DGraph::1_0;
    if (uVar2 == 0) {
      local_54 = (float)(dVar8 / dVar9);
    }
  }
  if (uVar5 == 0) {
    if (uVar3 == 0) {
      local_58 = (float)(in_f3 / dVar10) * J2DGraph::_1093;
      local_50 = J2DGraph::_1093 - local_58;
      local_58 = J2DGraph::_1093 + local_58;
    }
    else {
      local_50 = J2DGraph::1_0 - (float)(in_f3 / dVar10);
      local_58 = J2DGraph::1_0;
    }
  }
  else {
    local_50 = J2DGraph::_729;
    local_58 = J2DGraph::1_0;
    if (uVar3 == 0) {
      local_58 = (float)(in_f3 / dVar10);
    }
  }
  if ((mirror & 2) != 0) {
    swap(this,&local_4c,&local_54);
  }
  if ((mirror & 1) != 0) {
    swap(this,&local_50,&local_58);
  }
  if (param_4 == false) {
    drawTexCoord(this,pMtx);
  }
  else {
    drawTexCoord(this,pMtx);
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x802d4468) */
/* WARNING: Removing unreachable block (ram,0x802d4458) */
/* WARNING: Removing unreachable block (ram,0x802d4460) */
/* WARNING: Removing unreachable block (ram,0x802d4470) */
/* __thiscall J2DPicture::draw(float,
                               float,
                               float,
                               float,
                               bool,
                               bool,
                               bool) */

void __thiscall
J2DPicture::draw(J2DPicture *this,float param_1,float param_2,float param_3,float param_4,
                bool param_5,bool param_6,bool param_7)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  _GXColor local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  MTX34 MStack136;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar7 = (double)param_4;
  dVar6 = (double)param_3;
  dVar5 = (double)param_2;
  dVar4 = (double)param_1;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  if ((this->parent).mbDraw != 0) {
    for (uVar2 = 0; uVar1 = (uint)this->mNumTexture, (uVar2 & 0xff) < uVar1; uVar2 = uVar2 + 1) {
      if ((uVar2 & 0xff) < uVar1) {
        JUTTexture::load(this->mpTexture[uVar2 & 0xff],uVar2 & 0xff);
      }
    }
    gx::GXSetNumTexGens(uVar1);
    (this->parent).mDrawAlpha = (this->parent).mAlpha;
    local_98 = (_GXColor)0xffffffff;
    local_94 = 0xffffffff;
    local_90 = 0xffffffff;
    local_8c = 0xffffffff;
    getNewColor(this,&local_98);
    setTevMode(this);
    (*(code *)((this->parent).vtbl)->makeMatrix)(dVar4,dVar5,this);
    gx::GXLoadPosMtxImm(&(this->parent).mMtx,0);
    gx::GXSetCurrentMtx(0);
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
    gx::GXSetVtxDesc(GX_VA_CLR0,GX_DIRECT);
    gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
    gx::GXBegin(0x80,0,4);
    write_volatile_4(0xcc008000,J2DGraph::_729);
    write_volatile_4(0xcc008000,J2DGraph::_729);
    write_volatile_4(0xcc008000,J2DGraph::_729);
    write_volatile_4(0xcc008000,local_98);
    if (param_7 == false) {
      write_volatile_2(0xcc008000,-(ushort)(param_5 != false) & 0x8000);
      write_volatile_2(0xcc008000,-(ushort)(param_6 != false) & 0x8000);
    }
    else {
      write_volatile_2(0xcc008000,-(ushort)(param_5 != false) & 0x8000);
      write_volatile_2(0xcc008000,~-(ushort)(param_6 != false) & 0x8000);
    }
    write_volatile_4(0xcc008000,(float)dVar6);
    write_volatile_4(0xcc008000,J2DGraph::_729);
    write_volatile_4(0xcc008000,J2DGraph::_729);
    write_volatile_4(0xcc008000,local_94);
    if (param_7 == false) {
      write_volatile_2(0xcc008000,~-(ushort)(param_5 != false) & 0x8000);
      write_volatile_2(0xcc008000,-(ushort)(param_6 != false) & 0x8000);
    }
    else {
      write_volatile_2(0xcc008000,-(ushort)(param_5 != false) & 0x8000);
      write_volatile_2(0xcc008000,-(ushort)(param_6 != false) & 0x8000);
    }
    write_volatile_4(0xcc008000,(float)dVar6);
    write_volatile_4(0xcc008000,(float)dVar7);
    write_volatile_4(0xcc008000,J2DGraph::_729);
    write_volatile_4(0xcc008000,local_8c);
    if (param_7 == false) {
      write_volatile_2(0xcc008000,~-(ushort)(param_5 != false) & 0x8000);
      write_volatile_2(0xcc008000,~-(ushort)(param_6 != false) & 0x8000);
    }
    else {
      write_volatile_2(0xcc008000,~-(ushort)(param_5 != false) & 0x8000);
      write_volatile_2(0xcc008000,-(ushort)(param_6 != false) & 0x8000);
    }
    write_volatile_4(0xcc008000,J2DGraph::_729);
    write_volatile_4(0xcc008000,(float)dVar7);
    write_volatile_4(0xcc008000,J2DGraph::_729);
    write_volatile_4(0xcc008000,local_90);
    if (param_7 == false) {
      write_volatile_2(0xcc008000,-(ushort)(param_5 != false) & 0x8000);
      write_volatile_2(0xcc008000,~-(ushort)(param_6 != false) & 0x8000);
    }
    else {
      write_volatile_2(0xcc008000,~-(ushort)(param_5 != false) & 0x8000);
      write_volatile_2(0xcc008000,~-(ushort)(param_6 != false) & 0x8000);
    }
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBX8,0xf);
    gx::GXSetNumTexGens(0);
    gx::GXSetNumTevStages(1);
    gx::GXSetTevOp(0,4);
    gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
    mtx::PSMTXIdentity(&MStack136);
    gx::GXLoadPosMtxImm(&MStack136,0);
    gx::GXSetVtxDesc(GX_VA_TEX0,GX_NONE);
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  __psq_l0(auStack56,uVar3);
  __psq_l1(auStack56,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x802d484c) */
/* WARNING: Removing unreachable block (ram,0x802d483c) */
/* WARNING: Removing unreachable block (ram,0x802d4844) */
/* WARNING: Removing unreachable block (ram,0x802d4854) */
/* __thiscall J2DPicture::drawOut(JGeometry::TBox2<float><float> const &,
                                  JGeometry::TBox2<float><float> const &) */

void __thiscall J2DPicture::drawOut(J2DPicture *this,TBox2_float_ *param_1,TBox2_float_ *param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined8 in_f28;
  double dVar8;
  undefined8 in_f29;
  double dVar9;
  undefined8 in_f30;
  double dVar10;
  undefined8 in_f31;
  double dVar11;
  _GXColor local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  longlong local_d8;
  undefined4 local_d0;
  uint uStack204;
  longlong local_c8;
  undefined4 local_c0;
  uint uStack188;
  longlong local_b8;
  undefined4 local_b0;
  uint uStack172;
  longlong local_a8;
  undefined4 local_a0;
  uint uStack156;
  longlong local_98;
  undefined4 local_90;
  uint uStack140;
  longlong local_88;
  undefined4 local_80;
  uint uStack124;
  longlong local_78;
  undefined4 local_70;
  uint uStack108;
  longlong local_68;
  undefined4 local_60;
  uint uStack92;
  undefined auStack56 [16];
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
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  if ((this->parent).mbDraw != 0) {
    for (uVar6 = 0; uVar5 = (uint)this->mNumTexture, (uVar6 & 0xff) < uVar5; uVar6 = uVar6 + 1) {
      if ((uVar6 & 0xff) < uVar5) {
        JUTTexture::load(this->mpTexture[uVar6 & 0xff],uVar6 & 0xff);
      }
    }
    gx::GXSetNumTexGens(uVar5);
    fVar2 = (param_2->mTL).x;
    fVar3 = (param_2->mBR).x;
    fVar4 = fVar3 - fVar2;
    dVar11 = (double)(((param_1->mTL).x - fVar2) / fVar4);
    dVar10 = (double)(J2DGraph::1_0 + ((param_1->mBR).x - fVar3) / fVar4);
    fVar2 = (param_2->mTL).y;
    fVar3 = (param_2->mBR).y;
    fVar4 = fVar3 - fVar2;
    dVar9 = (double)(((param_1->mTL).y - fVar2) / fVar4);
    dVar8 = (double)(J2DGraph::1_0 + ((param_1->mBR).y - fVar3) / fVar4);
    (this->parent).mDrawAlpha = (this->parent).mAlpha;
    local_e8 = (_GXColor)0xffffffff;
    local_e4 = 0xffffffff;
    local_e0 = 0xffffffff;
    local_dc = 0xffffffff;
    getNewColor(this,&local_e8);
    setTevMode(this);
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
    gx::GXSetVtxDesc(GX_VA_CLR0,GX_DIRECT);
    gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
    gx::GXBegin(0x80,0,4);
    iVar1 = (int)(param_1->mTL).y;
    local_d8 = (longlong)iVar1;
    uStack204 = (int)(short)iVar1 ^ 0x80000000;
    local_d0 = 0x43300000;
    iVar1 = (int)(param_1->mTL).x;
    local_c8 = (longlong)iVar1;
    uStack188 = (int)(short)iVar1 ^ 0x80000000;
    local_c0 = 0x43300000;
    write_volatile_4(0xcc008000,(float)((double)CONCAT44(0x43300000,uStack188) - J2DGraph::_733));
    write_volatile_4(0xcc008000,(float)((double)CONCAT44(0x43300000,uStack204) - J2DGraph::_733));
    write_volatile_4(0xcc008000,J2DGraph::_729);
    write_volatile_4(0xcc008000,local_e8);
    write_volatile_4(0xcc008000,(float)dVar11);
    write_volatile_4(0xcc008000,(float)dVar9);
    iVar1 = (int)(param_1->mTL).y;
    local_b8 = (longlong)iVar1;
    uStack172 = (int)(short)iVar1 ^ 0x80000000;
    local_b0 = 0x43300000;
    iVar1 = (int)(param_1->mBR).x;
    local_a8 = (longlong)iVar1;
    uStack156 = (int)(short)iVar1 ^ 0x80000000;
    local_a0 = 0x43300000;
    write_volatile_4(0xcc008000,(float)((double)CONCAT44(0x43300000,uStack156) - J2DGraph::_733));
    write_volatile_4(0xcc008000,(float)((double)CONCAT44(0x43300000,uStack172) - J2DGraph::_733));
    write_volatile_4(0xcc008000,J2DGraph::_729);
    write_volatile_4(0xcc008000,local_e4);
    write_volatile_4(0xcc008000,(float)dVar10);
    write_volatile_4(0xcc008000,(float)dVar9);
    iVar1 = (int)(param_1->mBR).y;
    local_98 = (longlong)iVar1;
    uStack140 = (int)(short)iVar1 ^ 0x80000000;
    local_90 = 0x43300000;
    iVar1 = (int)(param_1->mBR).x;
    local_88 = (longlong)iVar1;
    uStack124 = (int)(short)iVar1 ^ 0x80000000;
    local_80 = 0x43300000;
    write_volatile_4(0xcc008000,(float)((double)CONCAT44(0x43300000,uStack124) - J2DGraph::_733));
    write_volatile_4(0xcc008000,(float)((double)CONCAT44(0x43300000,uStack140) - J2DGraph::_733));
    write_volatile_4(0xcc008000,J2DGraph::_729);
    write_volatile_4(0xcc008000,local_dc);
    write_volatile_4(0xcc008000,(float)dVar10);
    write_volatile_4(0xcc008000,(float)dVar8);
    iVar1 = (int)(param_1->mBR).y;
    local_78 = (longlong)iVar1;
    uStack108 = (int)(short)iVar1 ^ 0x80000000;
    local_70 = 0x43300000;
    iVar1 = (int)(param_1->mTL).x;
    local_68 = (longlong)iVar1;
    uStack92 = (int)(short)iVar1 ^ 0x80000000;
    local_60 = 0x43300000;
    write_volatile_4(0xcc008000,(float)((double)CONCAT44(0x43300000,uStack92) - J2DGraph::_733));
    write_volatile_4(0xcc008000,(float)((double)CONCAT44(0x43300000,uStack108) - J2DGraph::_733));
    write_volatile_4(0xcc008000,J2DGraph::_729);
    write_volatile_4(0xcc008000,local_e0);
    write_volatile_4(0xcc008000,(float)dVar11);
    write_volatile_4(0xcc008000,(float)dVar8);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBX8,0xf);
    gx::GXSetNumTexGens(0);
    gx::GXSetNumTevStages(1);
    gx::GXSetTevOp(0,4);
    gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
    gx::GXSetVtxDesc(GX_VA_TEX0,GX_NONE);
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  __psq_l0(auStack40,uVar7);
  __psq_l1(auStack40,uVar7);
  __psq_l0(auStack56,uVar7);
  __psq_l1(auStack56,uVar7);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802d4b14) */
/* WARNING: Removing unreachable block (ram,0x802d4b04) */
/* WARNING: Removing unreachable block (ram,0x802d4af4) */
/* WARNING: Removing unreachable block (ram,0x802d4ae4) */
/* WARNING: Removing unreachable block (ram,0x802d4ad4) */
/* WARNING: Removing unreachable block (ram,0x802d4ac4) */
/* WARNING: Removing unreachable block (ram,0x802d4acc) */
/* WARNING: Removing unreachable block (ram,0x802d4adc) */
/* WARNING: Removing unreachable block (ram,0x802d4aec) */
/* WARNING: Removing unreachable block (ram,0x802d4afc) */
/* WARNING: Removing unreachable block (ram,0x802d4b0c) */
/* WARNING: Removing unreachable block (ram,0x802d4b1c) */
/* __thiscall J2DPicture::drawTexCoord(float,
                                       float,
                                       float,
                                       float,
                                       float,
                                       float,
                                       float,
                                       float,
                                       float,
                                       float,
                                       float,
                                       float,
                                       float *[][][]) */

void __thiscall J2DPicture::drawTexCoord(J2DPicture *this,MTX34 *param_1)

{
  uint numTexGen;
  uint uVar1;
  undefined4 uVar2;
  double in_f1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  undefined8 in_f20;
  undefined8 in_f21;
  undefined8 in_f22;
  undefined8 in_f23;
  undefined8 in_f24;
  undefined8 in_f25;
  undefined8 in_f26;
  double dVar3;
  undefined8 in_f27;
  double dVar4;
  undefined8 in_f28;
  double dVar5;
  undefined8 in_f29;
  double dVar6;
  undefined8 in_f30;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  float in_stack_00000008;
  float in_stack_0000000c;
  float in_stack_00000010;
  float in_stack_00000014;
  _GXColor local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  MTX34 MStack264;
  undefined auStack184 [16];
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
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  __psq_st0(auStack184,(int)((ulonglong)in_f20 >> 0x20),0);
  __psq_st1(auStack184,(int)in_f20,0);
  dVar3 = (double)in_stack_00000008;
  dVar4 = (double)in_stack_0000000c;
  dVar5 = (double)in_stack_00000010;
  dVar6 = (double)in_stack_00000014;
  for (uVar1 = 0; numTexGen = (uint)this->mNumTexture, (uVar1 & 0xff) < numTexGen; uVar1 = uVar1 + 1
      ) {
    if ((uVar1 & 0xff) < numTexGen) {
      JUTTexture::load(this->mpTexture[uVar1 & 0xff],uVar1 & 0xff);
    }
  }
  dVar8 = (double)(float)(in_f1 + in_f3);
  dVar7 = (double)(float)(in_f2 + in_f4);
  gx::GXSetNumTexGens(numTexGen);
  local_118 = (_GXColor)0xffffffff;
  local_114 = 0xffffffff;
  local_110 = 0xffffffff;
  local_10c = 0xffffffff;
  getNewColor(this,&local_118);
  setTevMode(this);
  mtx::PSMTXConcat(param_1,&(this->parent).mDrawMtx,&MStack264);
  gx::GXLoadPosMtxImm(&MStack264,0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_CLR0,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXBegin(0x80,0,4);
  write_volatile_4(0xcc008000,(float)in_f1);
  write_volatile_4(0xcc008000,(float)in_f2);
  write_volatile_4(0xcc008000,J2DGraph::_729);
  write_volatile_4(0xcc008000,local_118);
  write_volatile_4(0xcc008000,(float)in_f5);
  write_volatile_4(0xcc008000,(float)in_f6);
  write_volatile_4(0xcc008000,(float)dVar8);
  write_volatile_4(0xcc008000,(float)in_f2);
  write_volatile_4(0xcc008000,J2DGraph::_729);
  write_volatile_4(0xcc008000,local_114);
  write_volatile_4(0xcc008000,(float)in_f7);
  write_volatile_4(0xcc008000,(float)in_f8);
  write_volatile_4(0xcc008000,(float)dVar8);
  write_volatile_4(0xcc008000,(float)dVar7);
  write_volatile_4(0xcc008000,J2DGraph::_729);
  write_volatile_4(0xcc008000,local_10c);
  write_volatile_4(0xcc008000,(float)dVar5);
  write_volatile_4(0xcc008000,(float)dVar6);
  write_volatile_4(0xcc008000,(float)in_f1);
  write_volatile_4(0xcc008000,(float)dVar7);
  write_volatile_4(0xcc008000,J2DGraph::_729);
  write_volatile_4(0xcc008000,local_110);
  write_volatile_4(0xcc008000,(float)dVar3);
  write_volatile_4(0xcc008000,(float)dVar4);
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
  __psq_l0(auStack136,uVar2);
  __psq_l1(auStack136,uVar2);
  __psq_l0(auStack152,uVar2);
  __psq_l1(auStack152,uVar2);
  __psq_l0(auStack168,uVar2);
  __psq_l1(auStack168,uVar2);
  __psq_l0(auStack184,uVar2);
  __psq_l1(auStack184,uVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J2DPicture::setTevMode(void) */

void __thiscall J2DPicture::setTevMode(J2DPicture *this)

{
  GXTevStageID GVar1;
  uint uVar2;
  byte bVar3;
  _GXColor local_28;
  _GXColor local_24;
  _GXColor local_20;
  _GXColor local_1c;
  undefined4 local_18;
  _GXColor local_14;
  
  for (bVar3 = 0; bVar3 < this->mNumTexture; bVar3 = bVar3 + 1) {
    GVar1 = (GXTevStageID)bVar3;
    gx::GXSetTevOrder(GVar1,GVar1,GVar1,GX_COLOR_NULL);
  }
  local_18 = 0xffffffff;
  local_14 = (_GXColor)0xffffffff;
  gx::GXSetTevColor(GX_TEVREG2,&local_14);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_TEXC,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO);
  if (this->mpTexture[0]->mpTIMG->mTranslucency == 0) {
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_A2,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
  }
  else {
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_TEXA,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
  }
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  local_1c = this->mBlendKonstColor;
  gx::GXSetTevKColor(0,&local_1c);
  local_20 = this->mBlendKonstAlpha;
  gx::GXSetTevKColor(2,&local_20);
  for (bVar3 = 1; bVar3 < this->mNumTexture; bVar3 = bVar3 + 1) {
    GVar1 = (GXTevStageID)bVar3;
    uVar2 = (uint)bVar3;
    gx::GXSetTevKColorSel(GVar1,uVar2 * -4 + 0x20);
    gx::GXSetTevKAlphaSel(GVar1,uVar2 * -4 + 0x22);
    gx::GXSetTevColorIn(GVar1,GX_CC_CPREV,GX_CC_TEXC,GX_CC_KONST,GX_CC_ZERO);
    if (this->mpTexture[uVar2]->mpTIMG->mTranslucency == 0) {
      gx::GXSetTevAlphaIn(GVar1,GX_CA_APREV,GX_CA_A2,GX_CA_KONST,GX_CA_ZERO);
    }
    else {
      gx::GXSetTevAlphaIn(GVar1,GX_CA_APREV,GX_CA_TEXA,GX_CA_KONST,GX_CA_ZERO);
    }
    gx::GXSetTevColorOp(GVar1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaOp(GVar1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  }
  if ((this->mBgColor != (_GXColor)0x0) || (this->mColorBase != (_GXColor)0xffffffff)) {
    GVar1 = (GXTevStageID)bVar3;
    gx::GXSetTevOrder(GVar1,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
    local_24 = this->mBgColor;
    gx::GXSetTevColor(GX_TEVREG0,&local_24);
    local_28 = this->mColorBase;
    gx::GXSetTevColor(GX_TEVREG1,&local_28);
    gx::GXSetTevColorIn(GVar1,GX_CC_C0,GX_CC_C1,GX_CC_CPREV,GX_CC_ZERO);
    gx::GXSetTevAlphaIn(GVar1,GX_CA_A0,GX_CA_A1,GX_CA_APREV,GX_CA_ZERO);
    gx::GXSetTevColorOp(GVar1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaOp(GVar1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    bVar3 = bVar3 + 1;
  }
  if (((((this->parent).mDrawAlpha != 0xff) || (this->mNewColor[0] != (_GXColor)0xffffffff)) ||
      (this->mNewColor[1] != (_GXColor)0xffffffff)) ||
     ((this->mNewColor[2] != (_GXColor)0xffffffff || (this->mNewColor[3] != (_GXColor)0xffffffff))))
  {
    GVar1 = (GXTevStageID)bVar3;
    gx::GXSetTevOrder(GVar1,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
    gx::GXSetTevColorIn(GVar1,GX_CC_ZERO,GX_CC_CPREV,GX_CC_RASC,GX_CC_ZERO);
    gx::GXSetTevAlphaIn(GVar1,GX_CA_ZERO,GX_CA_APREV,GX_CA_RASA,GX_CA_ZERO);
    gx::GXSetTevColorOp(GVar1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaOp(GVar1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    bVar3 = bVar3 + 1;
  }
  gx::GXSetNumTevStages(bVar3);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
  for (bVar3 = 0; bVar3 < this->mNumTexture; bVar3 = bVar3 + 1) {
    gx::GXSetTexCoordGen2((uint)bVar3,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  }
  gx::GXSetNumChans(1);
  return;
}


/* __thiscall J2DPicture::swap(float &,
                               float &) */

void __thiscall J2DPicture::swap(J2DPicture *this,float *param_1,float *param_2)

{
  float fVar1;
  
  fVar1 = *param_1;
  *param_1 = *param_2;
  *param_2 = fVar1;
  return;
}


/* __thiscall J2DPicture::setBlendKonstColor(void) */

void __thiscall J2DPicture::setBlendKonstColor(J2DPicture *this)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  u8 local_18;
  u8 uStack23;
  u8 uStack22;
  u8 uStack21;
  
  uVar3 = 0;
  for (bVar4 = 1; bVar4 < this->mNumTexture; bVar4 = bVar4 + 1) {
    fVar1 = J2DGraph::_729;
    for (uVar5 = 0; (uVar5 & 0xff) < (uint)bVar4; uVar5 = uVar5 + 1) {
      fVar1 = fVar1 + this->mBlendKonstColorF[uVar5 & 0xff];
    }
    fVar2 = fVar1 + this->mBlendKonstColorF[bVar4];
    if (J2DGraph::_729 != fVar2) {
      uVar3 = uVar3 | ((int)(J2DGraph::255_0 * (J2DGraph::1_0 - fVar1 / fVar2)) & 0xffU) <<
                      (bVar4 - 1) * 8;
    }
  }
  local_18 = (u8)(uVar3 >> 0x18);
  (this->mBlendKonstColor).r = local_18;
  uStack23 = (u8)(uVar3 >> 0x10);
  (this->mBlendKonstColor).g = uStack23;
  uStack22 = (u8)(uVar3 >> 8);
  (this->mBlendKonstColor).b = uStack22;
  uStack21 = (u8)uVar3;
  (this->mBlendKonstColor).a = uStack21;
  return;
}


/* __thiscall J2DPicture::setBlendKonstAlpha(void) */

void __thiscall J2DPicture::setBlendKonstAlpha(J2DPicture *this)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  u8 local_18;
  u8 uStack23;
  u8 uStack22;
  u8 uStack21;
  
  uVar3 = 0;
  for (bVar4 = 1; bVar4 < this->mNumTexture; bVar4 = bVar4 + 1) {
    fVar1 = J2DGraph::_729;
    for (uVar5 = 0; (uVar5 & 0xff) < (uint)bVar4; uVar5 = uVar5 + 1) {
      fVar1 = fVar1 + this->mBlendKonstAlphaF[uVar5 & 0xff];
    }
    fVar2 = fVar1 + this->mBlendKonstAlphaF[bVar4];
    if (J2DGraph::_729 != fVar2) {
      uVar3 = uVar3 | ((int)(J2DGraph::255_0 * (J2DGraph::1_0 - fVar1 / fVar2)) & 0xffU) <<
                      (bVar4 - 1) * 8;
    }
  }
  local_18 = (u8)(uVar3 >> 0x18);
  (this->mBlendKonstAlpha).r = local_18;
  uStack23 = (u8)(uVar3 >> 0x10);
  (this->mBlendKonstAlpha).g = uStack23;
  uStack22 = (u8)(uVar3 >> 8);
  (this->mBlendKonstAlpha).b = uStack22;
  uStack21 = (u8)uVar3;
  (this->mBlendKonstAlpha).a = uStack21;
  return;
}


/* __thiscall J2DPicture::getNewColor(JUtility::TColor *) */

void __thiscall J2DPicture::getNewColor(J2DPicture *this,_GXColor *param_1)

{
  uint uVar1;
  
  param_1->r = this->mNewColor[0].r;
  param_1->g = this->mNewColor[0].g;
  param_1->b = this->mNewColor[0].b;
  param_1->a = this->mNewColor[0].a;
  param_1[1].r = this->mNewColor[1].r;
  param_1[1].g = this->mNewColor[1].g;
  param_1[1].b = this->mNewColor[1].b;
  param_1[1].a = this->mNewColor[1].a;
  param_1[2].r = this->mNewColor[2].r;
  param_1[2].g = this->mNewColor[2].g;
  param_1[2].b = this->mNewColor[2].b;
  param_1[2].a = this->mNewColor[2].a;
  param_1[3].r = this->mNewColor[3].r;
  param_1[3].g = this->mNewColor[3].g;
  param_1[3].b = this->mNewColor[3].b;
  param_1[3].a = this->mNewColor[3].a;
  uVar1 = (uint)(this->parent).mDrawAlpha;
  if (uVar1 == 0xff) {
    return;
  }
  param_1->a = (u8)((param_1->a * uVar1) / 0xff);
  param_1[1].a = (u8)(((uint)param_1[1].a * (uint)(this->parent).mDrawAlpha) / 0xff);
  param_1[2].a = (u8)(((uint)param_1[2].a * (uint)(this->parent).mDrawAlpha) / 0xff);
  param_1[3].a = (u8)(((uint)param_1[3].a * (uint)(this->parent).mDrawAlpha) / 0xff);
  return;
}

