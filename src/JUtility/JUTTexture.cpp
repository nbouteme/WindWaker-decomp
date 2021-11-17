#include <JUtility/JUTTexture.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTTexture.h>
#include <JUtility/JUTPalette.h>
#include <gx/GXTexture.h>
#include <JUTTexture.h>


/* __thiscall JUTTexture::~JUTTexture(void) */

void __thiscall JUTTexture::_JUTTexture(JUTTexture *this,short flag)

{
  if (this != (JUTTexture *)0x0) {
    if ((this->field_0x3b & 1) != 0) {
      JKernel::operator_delete__(*(undefined4 *)&this->field_0x3c);
    }
    if ((this->field_0x3b & 2) != 0) {
      JKernel::operator_delete((JKRHeap *)this->mpPalette);
    }
    if (0 < flag) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JUTTexture::storeTIMG(ResTIMG const *,
                                    unsigned char) */

void __thiscall JUTTexture::storeTIMG(JUTTexture *this,ResTIMG *param_1,uchar param_2)

{
  ushort uVar1;
  JUTPalette *this_00;
  ResTIMG *pRVar2;
  uint uVar3;
  
  if ((param_1 != (ResTIMG *)0x0) && (param_2 < 0x10)) {
    this->mpTIMG = param_1;
    this->mpData = &this->mpTIMG->mTexFmt + this->mpTIMG->mTexDataOffs;
    if (this->mpTIMG->mTexDataOffs == 0) {
      this->mpData = &this->mpTIMG[1].mTexFmt;
    }
    if ((this->field_0x3b & 2) != 0) {
      JKernel::operator_delete((JKRHeap *)this->mpPalette);
    }
    this->mpPalette = (JUTPalette *)0x0;
    this->mpAttachedPalette = (JUTPalette *)0x0;
    this->mTlut = 0;
    this->mWrapS = this->mpTIMG->mWrapS;
    this->mWrapT = this->mpTIMG->mWrapT;
    this->mMinFilter = this->mpTIMG->mMinFilter;
    this->mMagFilter = this->mpTIMG->mMagFilter;
    this->mMinLOD = (short)(char)this->mpTIMG->mMinLOD;
    this->mMaxLOD = (short)(char)this->mpTIMG->mMaxLOD;
    this->mLODBias = this->mpTIMG->mLODBias;
    uVar1 = this->mpTIMG->mTlutCount;
    if (uVar1 == 0) {
      initTexObj(this);
    }
    else {
      if (uVar1 < 0x101) {
        uVar3 = (uint)param_2;
      }
      else {
        uVar3 = (param_2 & 3) + 0x10;
      }
      this_00 = (JUTPalette *)JKernel::operator_new(0x18);
      if (this_00 != (JUTPalette *)0x0) {
        pRVar2 = this->mpTIMG;
        JUTPalette::storeTLUT
                  (this_00,uVar3,(uint)pRVar2->mTlutFmt,(uint)pRVar2->mTranslucency,
                   pRVar2->mTlutCount,&pRVar2->mTexFmt + pRVar2->mTlutDataOffs);
      }
      this->mpPalette = this_00;
      this->field_0x3b = this->field_0x3b & 1 | 2;
      attachPalette(this,this->mpPalette);
    }
  }
  return;
}


/* __thiscall JUTTexture::attachPalette(JUTPalette *) */

void __thiscall JUTTexture::attachPalette(JUTTexture *this,JUTPalette *param_1)

{
  if (this->mpTIMG->mbHasTlut != 0) {
    if ((param_1 == (JUTPalette *)0x0) && (this->mpPalette != (JUTPalette *)0x0)) {
      this->mpAttachedPalette = this->mpPalette;
    }
    else {
      this->mpAttachedPalette = param_1;
    }
    initTexObj(this,(uint)this->mpAttachedPalette->mTlut);
  }
  return;
}


/* __thiscall JUTTexture::initTexObj(void) */

void __thiscall JUTTexture::initTexObj(JUTTexture *this)

{
  int iVar1;
  ResTIMG *pRVar2;
  
  pRVar2 = this->mpTIMG;
  iVar1 = 0x20;
  if (pRVar2->mTexDataOffs != 0) {
    iVar1 = pRVar2->mTexDataOffs;
  }
  gx::GXInitTexObj((GXTexObj *)this,&pRVar2->mTexFmt + iVar1,(uint)pRVar2->mWidth,
                   (uint)pRVar2->mHeight,pRVar2->mTexFmt,this->mWrapS,this->mWrapT,
                   (bool)('\x01' - (pRVar2->mbMipmapEnabled == 0)));
  pRVar2 = this->mpTIMG;
  gx::GXInitTexObjLOD((double)((float)((double)CONCAT44(0x43300000,(uint)(ushort)this->mMinLOD) -
                                      JUtility::_435) * JUtility::1_8_0),
                      (double)((float)((double)CONCAT44(0x43300000,(uint)(ushort)this->mMaxLOD) -
                                      JUtility::_435) * JUtility::1_8_0),
                      (double)((float)((double)CONCAT44(0x43300000,(int)this->mLODBias ^ 0x80000000)
                                      - JUtility::_438) / JUtility::_433),this,this->mMinFilter,
                      this->mMagFilter,pRVar2->mbBiasClamp,pRVar2->mbDoEdgeLOD,pRVar2->mMaxAniso);
  return;
}


/* __thiscall JUTTexture::initTexObj(_GXTlut) */

void __thiscall JUTTexture::initTexObj(JUTTexture *this,_GXTlut param_1)

{
  byte bVar1;
  int iVar2;
  ResTIMG *pRVar3;
  
  bVar1 = this->mpTIMG->mbMipmapEnabled;
  this->mTlut = (byte)param_1;
  pRVar3 = this->mpTIMG;
  iVar2 = 0x20;
  if (pRVar3->mTexDataOffs != 0) {
    iVar2 = pRVar3->mTexDataOffs;
  }
  gx::GXInitTexObjCI(this,&pRVar3->mTexFmt + iVar2,pRVar3->mWidth,pRVar3->mHeight,pRVar3->mTexFmt,
                     this->mWrapS,this->mWrapT,bVar1 != 0,param_1);
  pRVar3 = this->mpTIMG;
  gx::GXInitTexObjLOD((double)((float)((double)CONCAT44(0x43300000,(uint)(ushort)this->mMinLOD) -
                                      JUtility::_435) * JUtility::1_8_0),
                      (double)((float)((double)CONCAT44(0x43300000,(uint)(ushort)this->mMaxLOD) -
                                      JUtility::_435) * JUtility::1_8_0),
                      (double)((float)((double)CONCAT44(0x43300000,(int)this->mLODBias ^ 0x80000000)
                                      - JUtility::_438) / JUtility::_433),this,this->mMinFilter,
                      this->mMagFilter,pRVar3->mbBiasClamp,pRVar3->mbDoEdgeLOD,pRVar3->mMaxAniso);
  return;
}


/* __thiscall JUTTexture::load(_GXTexMapID) */

void __thiscall JUTTexture::load(JUTTexture *this,_GXTexMapID param_1)

{
  if (this->mpAttachedPalette != (JUTPalette *)0x0) {
    JUTPalette::load(this->mpAttachedPalette);
  }
  gx::GXLoadTexObj((GXTexObj *)this,param_1);
  return;
}

