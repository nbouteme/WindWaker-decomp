#include <J2DGraph/J2DTextBox.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J2DGraph/J2DPane.h>
#include <JKernel/JKRFileLoader.h>
#include <J2DGraph/J2DTextBox.h>
#include <JSupport/JSUInputStream.h>
#include <JUtility/JUTResource.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTResFont.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <J2DGraph/J2DPrint.h>
#include <gx/GXTransform.h>
#include <mtx/mtx.h>
#include <J2DTextBox.h>


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J2DTextBox::J2DTextBox(char const *,
                                     char const *) */

void __thiscall J2DTextBox::J2DTextBox(J2DTextBox *this,char *param_1,char *param_2)

{
  ResFONT *pRVar1;
  
  J2DPane::J2DPane(&this->parent);
  (this->parent).vtbl = (J2DPane__vtable *)&__vt;
  this->mpFont = (JUTResFont *)0x0;
  this->mColorGradient[0] = (_GXColor)0xffffffff;
  this->mColorGradient[1] = (_GXColor)0xffffffff;
  this->mpStringPtr = (char *)0x0;
  this->mTextColor = (_GXColor)0xffffffff;
  this->mTextBgColor = (_GXColor)0xffffffff;
  pRVar1 = (ResFONT *)JKRFileLoader::getGlbResource(param_1,(JKRFileLoader *)0x0);
  initiate(this,pRVar1,param_2,2,2);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J2DTextBox::J2DTextBox(J2DPane *,
                                     JSURandomInputStream *) */

void __thiscall
J2DTextBox::J2DTextBox(J2DTextBox *this,J2DPane *param_1,JSURandomInputStream *param_2)

{
  float fVar1;
  int iVar2;
  ResFONT *pRVar3;
  JUTResFont *this_00;
  char *pcVar4;
  size_t __nbytes;
  char cVar5;
  char local_178;
  byte local_177;
  char local_176 [2];
  short local_174;
  ushort local_172;
  ushort local_170;
  short local_16e;
  short local_16c [2];
  _GXColor local_168;
  _GXColor local_164;
  _GXColor local_160;
  _GXColor local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  int local_14c;
  JUTResReference local_148 [264];
  undefined4 local_40;
  uint uStack60;
  undefined4 local_38;
  uint uStack52;
  undefined4 local_30;
  uint uStack44;
  undefined4 local_28;
  uint uStack36;
  
  J2DPane::J2DPane(&this->parent);
  (this->parent).vtbl = (J2DPane__vtable *)&__vt;
  this->mpFont = (JUTResFont *)0x0;
  this->mColorGradient[0] = (_GXColor)0xffffffff;
  this->mColorGradient[1] = (_GXColor)0xffffffff;
  this->mpStringPtr = (char *)0x0;
  this->mTextColor = (_GXColor)0xffffffff;
  this->mTextBgColor = (_GXColor)0xffffffff;
  iVar2 = (**(code **)(*(int *)param_2 + 0x1c))(param_2);
  JSUInputStream::read((JSUInputStream *)param_2,&local_150,8);
  *(undefined4 *)(this->parent).mMagic = local_150;
  J2DPane::makePaneStream(&this->parent,param_1,param_2);
  local_148[0] = (JUTResReference)0x0;
  JSUInputStream::read((JSUInputStream *)param_2,local_176,1);
  pRVar3 = (ResFONT *)
           JUTResReference::getResource
                     (local_148,(JSUInputStream *)param_2,0x464f4e54,(JKRArchive *)0x0);
  if (pRVar3 != (ResFONT *)0x0) {
    this_00 = (JUTResFont *)JKernel::operator_new(0x70);
    if (this_00 != (JUTResFont *)0x0) {
      JUTResFont::JUTResFont(this_00,pRVar3,(JKRHeap *)0x0);
    }
    this->mpFont = this_00;
  }
  JSUInputStream::read((JSUInputStream *)param_2,&local_15c,4);
  this->mColorGradient[0] = local_15c;
  JSUInputStream::read((JSUInputStream *)param_2,&local_160,4);
  this->mColorGradient[1] = local_160;
  JSUInputStream::read((JSUInputStream *)param_2,&local_177,1);
  this->field_0xfc = local_177 >> 2 & 3;
  this->field_0xfd = local_177 & 3;
  JSUInputStream::read((JSUInputStream *)param_2,local_16c,2);
  uStack60 = (int)local_16c[0] ^ 0x80000000;
  local_40 = 0x43300000;
  this->field_0xe0 = (float)((double)CONCAT44(0x43300000,uStack60) - J2DGraph::_583);
  JSUInputStream::read((JSUInputStream *)param_2,&local_16e,2);
  uStack52 = (int)local_16e ^ 0x80000000;
  local_38 = 0x43300000;
  this->mFontLeading = (float)((double)CONCAT44(0x43300000,uStack52) - J2DGraph::_583);
  JSUInputStream::read((JSUInputStream *)param_2,&local_170,2);
  uStack44 = (uint)local_170;
  local_30 = 0x43300000;
  this->mFontWidth = (float)((double)CONCAT44(0x43300000,uStack44) - J2DGraph::_586);
  JSUInputStream::read((JSUInputStream *)param_2,&local_172,2);
  uStack36 = (uint)local_172;
  local_28 = 0x43300000;
  this->mFontHeight = (float)((double)CONCAT44(0x43300000,uStack36) - J2DGraph::_586);
  JSUInputStream::read((JSUInputStream *)param_2,&local_174,2);
  __nbytes = SEXT24(local_174);
  pcVar4 = (char *)JKernel::operator_new__(__nbytes + 1);
  this->mpStringPtr = pcVar4;
  JSUInputStream::read((JSUInputStream *)param_2,this->mpStringPtr,__nbytes);
  this->mpStringPtr[__nbytes] = '\0';
  cVar5 = local_176[0] + -10;
  if (local_176[0] != '\n') {
    JSUInputStream::read((JSUInputStream *)param_2,&local_178,1);
    if (local_178 != '\0') {
      (*(code *)((this->parent).vtbl)->setConnectParent)(this,1);
    }
    cVar5 = local_176[0] + -0xb;
  }
  local_154 = 0;
  (this->mTextBgColor).r = 0;
  (this->mTextBgColor).g = 0;
  (this->mTextBgColor).b = 0;
  (this->mTextBgColor).a = 0;
  local_158 = 0xffffffff;
  (this->mTextColor).r = 0xff;
  (this->mTextColor).g = 0xff;
  (this->mTextColor).b = 0xff;
  (this->mTextColor).a = 0xff;
  if (cVar5 != '\0') {
    JSUInputStream::read((JSUInputStream *)param_2,&local_164,4);
    this->mTextBgColor = local_164;
    cVar5 = cVar5 + -1;
  }
  if (cVar5 != '\0') {
    JSUInputStream::read((JSUInputStream *)param_2,&local_168,4);
    this->mTextColor = local_168;
  }
  fVar1 = J2DGraph::0_0;
  this->field_0xd8 = J2DGraph::0_0;
  this->field_0xdc = fVar1;
  JSURandomInputStream::seek(param_2,iVar2 + local_14c,0);
  this->field_0xfe = 1;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J2DTextBox::J2DTextBox(unsigned long,
                                     JGeometry::TBox2<float><float> const &,
                                     ResFONT const *,
                                     char const *,
                                     J2DTextBoxHBinding,
                                     J2DTextBoxVBinding) */

void __thiscall
J2DTextBox::J2DTextBox
          (J2DTextBox *this,ulong param_1,TBox2_float_ *param_2,ResFONT *param_3,char *param_4,
          J2DTextBoxHBinding param_5,J2DTextBoxVBinding param_6)

{
  J2DPane::J2DPane(&this->parent,param_1,param_2);
  (this->parent).vtbl = (J2DPane__vtable *)&__vt;
  this->mpFont = (JUTResFont *)0x0;
  this->mColorGradient[0] = (_GXColor)0xffffffff;
  this->mColorGradient[1] = (_GXColor)0xffffffff;
  this->mpStringPtr = (char *)0x0;
  this->mTextColor = (_GXColor)0xffffffff;
  this->mTextBgColor = (_GXColor)0xffffffff;
  initiate(this,param_3,param_4,param_5,param_6);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J2DTextBox::initiate(ResFONT const *,
                                   char const *,
                                   J2DTextBoxHBinding,
                                   J2DTextBoxVBinding) */

void __thiscall
J2DTextBox::initiate
          (J2DTextBox *this,ResFONT *param_1,char *param_2,J2DTextBoxHBinding param_3,
          J2DTextBoxVBinding param_4)

{
  float fVar1;
  JUTResFont *this_00;
  size_t sVar2;
  char *pcVar3;
  uint uVar4;
  
  if (param_1 != (ResFONT *)0x0) {
    this_00 = (JUTResFont *)JKernel::operator_new(0x70);
    if (this_00 != (JUTResFont *)0x0) {
      JUTResFont::JUTResFont(this_00,param_1,(JKRHeap *)0x0);
    }
    this->mpFont = this_00;
  }
  this->mColorGradient[0] = (_GXColor)0xffffffff;
  this->mColorGradient[1] = (_GXColor)0xffffffff;
  (this->mTextBgColor).r = 0;
  (this->mTextBgColor).g = 0;
  (this->mTextBgColor).b = 0;
  (this->mTextBgColor).a = 0;
  (this->mTextColor).r = 0xff;
  (this->mTextColor).g = 0xff;
  (this->mTextColor).b = 0xff;
  (this->mTextColor).a = 0xff;
  this->field_0xfc = (byte)param_3;
  this->field_0xfd = (byte)param_4;
  sVar2 = MSL_C.PPCEABI.bare.H::strlen(param_2);
  pcVar3 = (char *)JKernel::operator_new__(sVar2 + 1);
  this->mpStringPtr = pcVar3;
  MSL_C.PPCEABI.bare.H::strcpy(this->mpStringPtr,param_2);
  fVar1 = J2DGraph::0_0;
  this->field_0xd8 = J2DGraph::0_0;
  this->field_0xdc = fVar1;
  this->field_0xe0 = fVar1;
  if (this->mpFont == (JUTResFont *)0x0) {
    this->mFontLeading = fVar1;
    this->mFontWidth = fVar1;
    this->mFontHeight = fVar1;
  }
  else {
    uVar4 = (*(code *)((this->mpFont->parent).vtbl)->getLeading)();
    this->mFontLeading = (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - J2DGraph::_583);
    uVar4 = (*(code *)((this->mpFont->parent).vtbl)->getWidth)();
    this->mFontWidth = (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - J2DGraph::_583);
    uVar4 = (*(code *)((this->mpFont->parent).vtbl)->getHeight)();
    this->mFontHeight = (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - J2DGraph::_583);
  }
  *(undefined4 *)(this->parent).mMagic = 0x54425831;
  this->field_0xfe = 1;
  return;
}


/* __thiscall J2DTextBox::~J2DTextBox(void) */

void __thiscall J2DTextBox::_J2DTextBox(J2DTextBox *this,short flag)

{
  JUTResFont *pJVar1;
  
  if (this != (J2DTextBox *)0x0) {
    (this->parent).vtbl = (J2DPane__vtable *)&__vt;
    if (this->field_0xfe != 0) {
      pJVar1 = this->mpFont;
      if (pJVar1 != (JUTResFont *)0x0) {
        (*(code *)((pJVar1->parent).vtbl)->_)(pJVar1,1);
      }
    }
    JKernel::operator_delete__(this->mpStringPtr);
    J2DPane::_J2DPane(&this->parent,0);
    if (0 < flag) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J2DTextBox::setFont(JUTFont *) */

void __thiscall J2DTextBox::setFont(J2DTextBox *this,JUTFont *param_1)

{
  JUTResFont *pJVar1;
  
  if (param_1 != (JUTFont *)0x0) {
    if ((this->field_0xfe != 0) && (pJVar1 = this->mpFont, pJVar1 != (JUTResFont *)0x0)) {
      (*(code *)((pJVar1->parent).vtbl)->_)(pJVar1,1);
    }
    this->mpFont = (JUTResFont *)param_1;
    this->field_0xfe = 0;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x802d5a7c) */
/* WARNING: Removing unreachable block (ram,0x802d5a74) */
/* WARNING: Removing unreachable block (ram,0x802d5a84) */
/* __thiscall J2DTextBox::draw(float,
                               float,
                               float,
                               J2DTextBoxHBinding) */

void __thiscall
J2DTextBox::draw(J2DTextBox *this,float param_1,float param_2,float param_3,
                J2DTextBoxHBinding param_4)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  _GXColor local_d8;
  _GXColor local_d4;
  _GXColor local_d0;
  _GXColor local_cc;
  MTX34 MStack200;
  J2DPrint local_98;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar4 = (double)param_3;
  dVar3 = (double)param_2;
  dVar2 = (double)param_1;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if ((this->parent).mbDraw != 0) {
    local_d8 = this->mTextColor;
    local_d4 = this->mTextBgColor;
    local_d0 = this->mColorGradient[1];
    local_cc = this->mColorGradient[0];
    J2DPrint::J2DPrint(&local_98,&this->mpFont->parent,this->field_0xe0,this->mFontLeading,&local_cc
                       ,&local_d0,&local_d4,&local_d8);
    local_98.mWidth = J2DGraph::0_0;
    if (J2DGraph::0_0 < this->mFontWidth) {
      local_98.mWidth = this->mFontWidth;
    }
    local_98.mHeight = J2DGraph::0_0;
    if (J2DGraph::0_0 < this->mFontHeight) {
      local_98.mHeight = this->mFontHeight;
    }
    (*(code *)((this->parent).vtbl)->makeMatrix)(dVar2,dVar3,this);
    gx::GXLoadPosMtxImm(&(this->parent).mMtx,0);
    gx::GXSetCurrentMtx(0);
    J2DPrint::printReturn
              (&local_98,this->mpStringPtr,(float)dVar4,J2DGraph::0_0,param_4,VBindingTop,
               J2DGraph::0_0,-this->mFontHeight,(this->parent).mDrawAlpha);
    mtx::PSMTXIdentity(&MStack200);
    gx::GXLoadPosMtxImm(&MStack200,0);
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  __psq_l0(auStack40,uVar1);
  __psq_l1(auStack40,uVar1);
  return;
}


/* __thiscall J2DTextBox::getStringPtr(void) const */

char * __thiscall J2DTextBox::getStringPtr(J2DTextBox *this)

{
  return this->mpStringPtr;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J2DTextBox::setString(char const *,
                                    ...) */

size_t __thiscall J2DTextBox::setString(J2DTextBox *this,char *param_1,___ param_2)

{
  size_t sVar1;
  char *pcVar2;
  J2DTextBox *local_88;
  char *local_84;
  ___ local_80;
  undefined4 local_28;
  undefined *local_24;
  J2DTextBox **local_20;
  
  local_28 = 0x2000000;
  local_24 = &stack0x00000008;
  local_20 = &local_88;
  local_88 = this;
  local_84 = param_1;
  local_80 = param_2;
  JKernel::operator_delete__(this->mpStringPtr);
  sVar1 = MSL_C.PPCEABI.bare.H::strlen(param_1);
  pcVar2 = (char *)JKernel::operator_new__(sVar1 + 1);
  this->mpStringPtr = pcVar2;
  MSL_C.PPCEABI.bare.H::strcpy(this->mpStringPtr,param_1);
  return sVar1;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall J2DTextBox::setConnectParent(bool) */

undefined4 __thiscall J2DTextBox::setConnectParent(J2DTextBox *this,bool param_1)

{
  JSUPtrList *pJVar1;
  undefined4 uVar2;
  short sVar3;
  undefined3 in_register_00000010;
  
  uVar2 = CONCAT31(in_register_00000010,param_1);
  pJVar1 = (this->parent).mParentLink.mpList;
  if (pJVar1 == (JSUPtrList *)0x0) {
    uVar2 = 0;
  }
  else {
    sVar3 = (**(code **)((pJVar1[1].mpHead)->mpData + 0xc))();
    if (sVar3 == J2DWindow) {
      (this->parent).field_0xaf = param_1;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


/* __thiscall J2DTextBox::drawSelf(float,
                                   float) */

void __thiscall J2DTextBox::drawSelf(J2DTextBox *this,float param_1,float param_2)

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


/* WARNING: Removing unreachable block (ram,0x802d5d7c) */
/* WARNING: Removing unreachable block (ram,0x802d5d84) */
/* __thiscall J2DTextBox::drawSelf(float,
                                   float,
                                   float *[][][]) */

void __thiscall J2DTextBox::drawSelf(J2DTextBox *this,float param_1,float param_2,MTX34 *param_3)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f30;
  undefined8 in_f31;
  _GXColor local_c8;
  _GXColor local_c4;
  _GXColor local_c0;
  _GXColor local_bc;
  MTX34 local_b8;
  J2DPrint local_88;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar3 = (double)param_2;
  dVar2 = (double)param_1;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  local_c8 = this->mTextColor;
  local_c4 = this->mTextBgColor;
  local_c0 = this->mColorGradient[1];
  local_bc = this->mColorGradient[0];
  J2DPrint::J2DPrint(&local_88,&this->mpFont->parent,this->field_0xe0,this->mFontLeading,&local_bc,
                     &local_c0,&local_c4,&local_c8);
  local_88.mWidth = J2DGraph::0_0;
  if (J2DGraph::0_0 < this->mFontWidth) {
    local_88.mWidth = this->mFontWidth;
  }
  local_88.mHeight = J2DGraph::0_0;
  if (J2DGraph::0_0 < this->mFontHeight) {
    local_88.mHeight = this->mFontHeight;
  }
  mtx::PSMTXConcat(param_3,&(this->parent).mDrawMtx,&local_b8);
  gx::GXLoadPosMtxImm(&local_b8,0);
  J2DPrint::locate(&local_88,(float)dVar2,(float)dVar3);
  J2DPrint::printReturn
            (&local_88,this->mpStringPtr,
             J2DGraph::_821 + ((this->parent).mPosBR.x - (this->parent).mPosTL.x),
             (this->parent).mPosBR.y - (this->parent).mPosTL.y,(uint)this->field_0xfc,
             (uint)this->field_0xfd,this->field_0xd8,this->field_0xdc,(this->parent).mDrawAlpha);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x802d5e88) */
/* WARNING: Removing unreachable block (ram,0x802d5e90) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall J2DTextBox::resize(float,
                                 float) */

void __thiscall J2DTextBox::resize(J2DTextBox *this,float newX,float newY)

{
  JSUPtrList *pJVar1;
  short sVar2;
  JSUPtrLink *pJVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar6 = (double)newY;
  dVar5 = (double)newX;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if ((((this->parent).field_0xaf != 0) && (this != (J2DTextBox *)0xffffff50)) &&
     (pJVar1 = (this->parent).mParentLink.mpList, pJVar1 != (JSUPtrList *)0x0)) {
    pJVar3 = pJVar1[1].mpHead;
    sVar2 = (**(code **)(pJVar3->mpData + 0xc))(pJVar3);
    if (sVar2 == 0x11) {
      (**(code **)(pJVar3->mpData + 0x18))
                ((double)(((float)pJVar3[1].mpList - (float)pJVar3->mpNext) +
                         (float)(dVar5 - (double)((this->parent).mPosBR.x - (this->parent).mPosTL.x)
                                )),
                 (double)(((float)pJVar3[1].mpPrev - (float)pJVar3[1].mpData) +
                         (float)(dVar6 - (double)((this->parent).mPosBR.y - (this->parent).mPosTL.y)
                                )),pJVar3);
      goto LAB_802d5e88;
    }
  }
  (this->parent).mPosBR.x = (float)((double)(this->parent).mPosTL.x + dVar5);
  (this->parent).mPosBR.y = (float)((double)(this->parent).mPosTL.y + dVar6);
LAB_802d5e88:
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return;
}


/* __thiscall J2DTextBox::getTypeID(void) */

J2DTypeID __thiscall J2DTextBox::getTypeID(J2DTextBox *this)

{
  return J2DTextBox;
}

