#include <JPALoader/JPABaseShape.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JPALoader/JPABaseShape.h>
#include <JPABaseShape.h>
#include <JPABaseShapeArc.h>


namespace JPALoader {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall makeColorTable(JPAColorRegAnmKey *,
                            int,
                            int,
                            JKRHeap *) */

int makeColorTable(int param_1,int param_2,int param_3,JKRHeap *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  ulong uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  short *psVar15;
  undefined *puVar16;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  
  iVar9 = JKRHeap::alloc((param_3 + 1) * 4,4,param_4);
  if (iVar9 == 0) {
    uVar10 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar10,"JPABaseShape.cpp",0x5d,"colTbl");
    m_Do_printf::OSPanic("JPABaseShape.cpp",0x5d,&DAT_80366580);
  }
  fVar1 = (float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 2)) - _2186);
  local_30 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 3));
  fVar2 = (float)(local_30 - _2186);
  local_28 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 4));
  fVar3 = (float)(local_28 - _2186);
  local_20 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 5));
  fVar4 = (float)(local_20 - _2186);
  iVar11 = 0;
  iVar13 = 0;
  iVar12 = 0;
  iVar14 = 0;
  param_3 = param_3 + 1;
  fVar5 = _2183;
  fVar6 = _2183;
  fVar7 = _2183;
  fVar8 = _2183;
  if (0 < param_3) {
    do {
      psVar15 = (short *)(param_1 + iVar13);
      if (iVar12 == *psVar15) {
        puVar16 = (undefined *)(iVar9 + iVar14);
        *puVar16 = *(undefined *)(psVar15 + 1);
        puVar16[1] = *(undefined *)((int)psVar15 + 3);
        puVar16[2] = *(undefined *)(psVar15 + 2);
        puVar16[3] = *(undefined *)((int)psVar15 + 5);
        local_20 = (double)CONCAT44(0x43300000,(uint)*(byte *)(psVar15 + 1));
        fVar1 = (float)(local_20 - _2186);
        local_28 = (double)CONCAT44(0x43300000,(uint)*(byte *)((int)psVar15 + 3));
        fVar2 = (float)(local_28 - _2186);
        local_30 = (double)CONCAT44(0x43300000,(uint)*(byte *)(psVar15 + 2));
        fVar3 = (float)(local_30 - _2186);
        fVar4 = (float)((double)CONCAT44(0x43300000,(uint)*(byte *)((int)psVar15 + 5)) - _2186);
        iVar11 = iVar11 + 1;
        iVar13 = iVar13 + 6;
        fVar5 = _2183;
        fVar6 = _2183;
        fVar7 = _2183;
        fVar8 = _2183;
        if (iVar11 < param_2) {
          psVar15 = (short *)(param_1 + iVar13);
          local_20 = (double)CONCAT44(0x43300000,(int)*psVar15 - (int)psVar15[-3] ^ 0x80000000);
          fVar8 = _2184 / (float)(local_20 - _2190);
          local_28 = (double)CONCAT44(0x43300000,(uint)*(byte *)(psVar15 + 1));
          local_30 = (double)CONCAT44(0x43300000,(uint)*(byte *)((int)psVar15 + 3));
          local_18 = (double)CONCAT44(0x43300000,(uint)*(byte *)((int)psVar15 + 5));
          fVar5 = fVar8 * ((float)(local_18 - _2186) - fVar4);
          fVar6 = fVar8 * ((float)(local_28 - _2186) - fVar1);
          fVar7 = fVar8 * ((float)(local_30 - _2186) - fVar2);
          fVar8 = fVar8 * ((float)((double)CONCAT44(0x43300000,(uint)*(byte *)(psVar15 + 2)) - _2186
                                  ) - fVar3);
        }
      }
      else {
        fVar1 = fVar1 + fVar6;
        puVar16 = (undefined *)(iVar9 + iVar14);
        *puVar16 = (char)(int)fVar1;
        fVar2 = fVar2 + fVar7;
        puVar16[1] = (char)(int)fVar2;
        fVar3 = fVar3 + fVar8;
        puVar16[2] = (char)(int)fVar3;
        fVar4 = fVar4 + fVar5;
        puVar16[3] = (char)(int)fVar4;
      }
      iVar12 = iVar12 + 1;
      iVar14 = iVar14 + 4;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return iVar9;
}

}

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JPABaseShapeArc::JPABaseShapeArc(unsigned char const *,
                                               JKRHeap *) */

void __thiscall JPABaseShapeArc::JPABaseShapeArc(JPABaseShapeArc *this,void *pData,JKRHeap *param_2)

{
  bool bVar1;
  char cVar5;
  int iVar2;
  char cVar6;
  ulong uVar3;
  _GXColor *p_Var4;
  JPABaseShapeArc__Data *pJVar7;
  
  this->vtbl = (JPABaseShapeArc__vtbl *)&JPABaseShape::__vt;
  this->vtbl = &__vt;
  this->mpData = (JPABaseShapeArc__Data *)((int)pData + 0xc);
  this->mpColLoopOffset = -((ushort)(this->mpData->mFlags >> 0xb) & 1);
  this->mTexLoopOffset = -((ushort)(this->mpData->mFlags >> 0xd) & 1);
  cVar6 = '\0';
  if ((this->mpData->mFlags & 0x1000) == 0) {
    cVar5 = (*(code *)this->vtbl->getType)();
    if (cVar5 != '\x05') {
      cVar5 = (*(code *)this->vtbl->getType)(this);
      if (cVar5 != '\x06') goto LAB_80257314;
    }
  }
  cVar6 = '\x01';
LAB_80257314:
  bVar1 = false;
  if ((((this->mpData->mFlags & 0x4000) != 0) ||
      (cVar5 = (*(code *)this->vtbl->getType)(this), cVar5 == '\x05')) ||
     (cVar5 = (*(code *)this->vtbl->getType)(this), cVar5 == '\x06')) {
    bVar1 = true;
  }
  this->mGlobalAnmFlags = cVar6 * '\x02' | 1U - !bVar1;
  iVar2 = (*(code *)this->vtbl->isEnableTextureAnm)(this);
  if ((iVar2 == 0) || (cVar6 = (*(code *)this->vtbl->getTextureAnmKeyNum)(this), cVar6 == '\0')) {
    this->mpTexAnmIdxArr = (byte *)0x0;
  }
  else {
    this->mpTexAnmIdxArr = (byte *)((int)pData + 0x60);
  }
  iVar2 = (*(code *)this->vtbl->isEnablePrmAnm)(this);
  if (iVar2 == 0) {
    this->mpPrmColorArr = (_GXColor *)0x0;
  }
  else {
    if (this->mpData->mPrmAnmKeyNum == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"JPABaseShape.cpp",0x11f,"pBsd->prmAnmKeyNum != 0");
      m_Do_printf::OSPanic("JPABaseShape.cpp",0x11f,&DAT_80366580);
    }
    pJVar7 = this->mpData;
    p_Var4 = (_GXColor *)
             JPALoader::makeColorTable
                       ((int)pData + (int)pJVar7->mPrmAnimDataOffs,pJVar7->mPrmAnmKeyNum,
                        (int)pJVar7->mColorRegAnmMaxFrm,param_2);
    this->mpPrmColorArr = p_Var4;
  }
  iVar2 = (*(code *)this->vtbl->isEnableEnvAnm)(this);
  if (iVar2 == 0) {
    this->mpEnvColorArr = (_GXColor *)0x0;
  }
  else {
    if (this->mpData->mEnvAnmKeyNum == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"JPABaseShape.cpp",0x127,"pBsd->envAnmKeyNum != 0");
      m_Do_printf::OSPanic("JPABaseShape.cpp",0x127,&DAT_80366580);
    }
    pJVar7 = this->mpData;
    p_Var4 = (_GXColor *)
             JPALoader::makeColorTable
                       ((int)pData + (int)pJVar7->mEnvAnimDataOffs,pJVar7->mEnvAnmKeyNum,
                        (int)pJVar7->mColorRegAnmMaxFrm,param_2);
    this->mpEnvColorArr = p_Var4;
  }
  return;
}


/* __thiscall JPABaseShape::~JPABaseShape(void) */

void __thiscall JPABaseShape::_JPABaseShape(JPABaseShape *this)

{
  short in_r4;
  
  if ((this != (JPABaseShape *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall JPABaseShapeArc::isEnableEnvAnm(void) */

byte __thiscall JPABaseShapeArc::isEnableEnvAnm(JPABaseShapeArc *this)

{
  return this->mpData->mColorFlags & 8;
}


/* __thiscall JPABaseShapeArc::isEnablePrmAnm(void) */

byte __thiscall JPABaseShapeArc::isEnablePrmAnm(JPABaseShapeArc *this)

{
  return this->mpData->mColorFlags & 2;
}


/* __thiscall JPABaseShapeArc::getTextureAnmKeyNum(void) */

byte __thiscall JPABaseShapeArc::getTextureAnmKeyNum(JPABaseShapeArc *this)

{
  return this->mpData->mTextureAnmKeyNum;
}


/* __thiscall JPABaseShapeArc::isEnableTextureAnm(void) */

byte __thiscall JPABaseShapeArc::isEnableTextureAnm(JPABaseShapeArc *this)

{
  return this->mpData->mTextureFlags & 1;
}


/* __thiscall JPABaseShapeArc::getType(void) */

uint __thiscall JPABaseShapeArc::getType(JPABaseShapeArc *this)

{
  return this->mpData->mFlags & 0xf;
}


/* __thiscall JPABaseShapeArc::~JPABaseShapeArc(void) */

void __thiscall JPABaseShapeArc::_JPABaseShapeArc(JPABaseShapeArc *this)

{
  short in_r4;
  
  if (this != (JPABaseShapeArc *)0x0) {
    this->vtbl = &__vt;
    if (this != (JPABaseShapeArc *)0x0) {
      this->vtbl = (JPABaseShapeArc__vtbl *)&JPABaseShape::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPABaseShapeArc::getDirType(void) */

uint __thiscall JPABaseShapeArc::getDirType(JPABaseShapeArc *this)

{
  return this->mpData->mFlags >> 4 & 7;
}


/* __thiscall JPABaseShapeArc::getRotType(void) */

uint __thiscall JPABaseShapeArc::getRotType(JPABaseShapeArc *this)

{
  return this->mpData->mFlags >> 7 & 7;
}


/* __thiscall JPABaseShapeArc::getBasePlaneType(void) */

uint __thiscall JPABaseShapeArc::getBasePlaneType(JPABaseShapeArc *this)

{
  return this->mpData->mFlags >> 10 & 1;
}


/* __thiscall JPABaseShapeArc::getBaseSizeX(void) */

double __thiscall JPABaseShapeArc::getBaseSizeX(JPABaseShapeArc *this)

{
  return (double)this->mpData->mBaseSizeX;
}


/* __thiscall JPABaseShapeArc::getBaseSizeY(void) */

double __thiscall JPABaseShapeArc::getBaseSizeY(JPABaseShapeArc *this)

{
  return (double)this->mpData->mBaseSizeY;
}


/* __thiscall JPABaseShapeArc::getLoopOffset(void) */

int __thiscall JPABaseShapeArc::getLoopOffset(JPABaseShapeArc *this)

{
  return (int)this->mpData->mLoopOffset;
}


/* __thiscall JPABaseShapeArc::getColLoopOffset(void) */

int __thiscall JPABaseShapeArc::getColLoopOffset(JPABaseShapeArc *this)

{
  return (int)this->mpColLoopOffset;
}


/* __thiscall JPABaseShapeArc::getTexLoopOffset(void) */

int __thiscall JPABaseShapeArc::getTexLoopOffset(JPABaseShapeArc *this)

{
  return (int)this->mTexLoopOffset;
}


/* __thiscall JPABaseShapeArc::isEnableGlobalColAnm(void) */

byte __thiscall JPABaseShapeArc::isEnableGlobalColAnm(JPABaseShapeArc *this)

{
  return this->mGlobalAnmFlags & 2;
}


/* __thiscall JPABaseShapeArc::isEnableGlobalTexAnm(void) */

byte __thiscall JPABaseShapeArc::isEnableGlobalTexAnm(JPABaseShapeArc *this)

{
  return this->mGlobalAnmFlags & 1;
}


/* __thiscall JPABaseShapeArc::getListOrder(void) */

uint __thiscall JPABaseShapeArc::getListOrder(JPABaseShapeArc *this)

{
  return this->mpData->mFlags & 0x200000;
}


/* __thiscall JPABaseShapeArc::getChildOrder(void) */

uint __thiscall JPABaseShapeArc::getChildOrder(JPABaseShapeArc *this)

{
  return this->mpData->mFlags & 0x400000;
}


/* __thiscall JPABaseShapeArc::getTevColorArg(void) */

undefined1 * __thiscall JPABaseShapeArc::getTevColorArg(JPABaseShapeArc *this)

{
  return &stTevColorArg + (this->mpData->mFlags >> 0xb & 0x70);
}


/* __thiscall JPABaseShapeArc::getTevAlphaArg(void) */

undefined1 * __thiscall JPABaseShapeArc::getTevAlphaArg(JPABaseShapeArc *this)

{
  return &stTevAlphaArg + (this->mpData->mFlags >> 0xe & 0x10);
}


/* __thiscall JPABaseShapeArc::getBlendMode1(void) */

int __thiscall JPABaseShapeArc::getBlendMode1(JPABaseShapeArc *this)

{
  return JPABaseShape::stBlendMode[this->mpData->mBlendFlags & 3];
}


/* __thiscall JPABaseShapeArc::getSrcBlendFactor1(void) */

undefined4 __thiscall JPABaseShapeArc::getSrcBlendFactor1(JPABaseShapeArc *this)

{
  return *(undefined4 *)((int)JPABaseShape::stBlendFactor + (this->mpData->mBlendFlags & 0x3c));
}


/* __thiscall JPABaseShapeArc::getDstBlendFactor1(void) */

undefined4 __thiscall JPABaseShapeArc::getDstBlendFactor1(JPABaseShapeArc *this)

{
  return *(undefined4 *)((int)JPABaseShape::stBlendFactor + (this->mpData->mBlendFlags >> 4 & 0x3c))
  ;
}


/* __thiscall JPABaseShapeArc::getBlendOp1(void) */

undefined4 __thiscall JPABaseShapeArc::getBlendOp1(JPABaseShapeArc *this)

{
  return *(undefined4 *)((int)JPABaseShape::stLogicOp + (this->mpData->mBlendFlags >> 8 & 0x3c));
}


/* __thiscall JPABaseShapeArc::isEnableAlphaUpdate(void) */

ushort __thiscall JPABaseShapeArc::isEnableAlphaUpdate(JPABaseShapeArc *this)

{
  return this->mpData->mBlendFlags >> 0xe & 1;
}


/* __thiscall JPABaseShapeArc::isEnableZCmp(void) */

byte __thiscall JPABaseShapeArc::isEnableZCmp(JPABaseShapeArc *this)

{
  return this->mpData->mZFlags & 1;
}


/* __thiscall JPABaseShapeArc::getZCmpFunction(void) */

undefined4 __thiscall JPABaseShapeArc::getZCmpFunction(JPABaseShapeArc *this)

{
  return *(undefined4 *)((int)JPABaseShape::stCompare + (this->mpData->mZFlags & 0xe) * 2);
}


/* __thiscall JPABaseShapeArc::isEnableZCmpUpdate(void) */

byte __thiscall JPABaseShapeArc::isEnableZCmpUpdate(JPABaseShapeArc *this)

{
  return this->mpData->mZFlags >> 4 & 1;
}


/* __thiscall JPABaseShapeArc::getZCompLoc(void) */

byte __thiscall JPABaseShapeArc::getZCompLoc(JPABaseShapeArc *this)

{
  return this->mpData->mZFlags >> 5 & 1;
}


/* __thiscall JPABaseShapeArc::getAlphaCmpComp0(void) */

int __thiscall JPABaseShapeArc::getAlphaCmpComp0(JPABaseShapeArc *this)

{
  return JPABaseShape::stCompare[this->mpData->mAlphaFlags & 7];
}


/* __thiscall JPABaseShapeArc::getAlphaCmpComp1(void) */

undefined4 __thiscall JPABaseShapeArc::getAlphaCmpComp1(JPABaseShapeArc *this)

{
  return *(undefined4 *)((int)JPABaseShape::stCompare + (this->mpData->mAlphaFlags >> 3 & 0x1c));
}


/* __thiscall JPABaseShapeArc::getAlphaCmpOp(void) */

undefined4 __thiscall JPABaseShapeArc::getAlphaCmpOp(JPABaseShapeArc *this)

{
  return *(undefined4 *)((int)JPABaseShape::stAlphaOp + (this->mpData->mAlphaFlags >> 1 & 0xc));
}


/* __thiscall JPABaseShapeArc::getAlphaCmpRef0(void) */

byte __thiscall JPABaseShapeArc::getAlphaCmpRef0(JPABaseShapeArc *this)

{
  return this->mpData->mAlphaCmpRef0;
}


/* __thiscall JPABaseShapeArc::getAlphaCmpRef1(void) */

byte __thiscall JPABaseShapeArc::getAlphaCmpRef1(JPABaseShapeArc *this)

{
  return this->mpData->mAlphaCmpRef1;
}


/* __thiscall JPABaseShapeArc::isEnableAnmTone(void) */

uint __thiscall JPABaseShapeArc::isEnableAnmTone(JPABaseShapeArc *this)

{
  return this->mpData->mFlags & 0x80000;
}


/* __thiscall JPABaseShapeArc::isEnableProjection(void) */

uint __thiscall JPABaseShapeArc::isEnableProjection(JPABaseShapeArc *this)

{
  return this->mpData->mFlags & 0x100000;
}


/* __thiscall JPABaseShapeArc::isClipOn(void) */

uint __thiscall JPABaseShapeArc::isClipOn(JPABaseShapeArc *this)

{
  return this->mpData->mFlags & 0x800000;
}


/* __thiscall JPABaseShapeArc::textureIsEmpty(void) */

uint __thiscall JPABaseShapeArc::textureIsEmpty(JPABaseShapeArc *this)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(this->mpData->mTextureFlags & 2);
  return uVar1 >> 5 & 0xff;
}


/* __thiscall JPABaseShapeArc::getTextureAnmType(void) */

byte __thiscall JPABaseShapeArc::getTextureAnmType(JPABaseShapeArc *this)

{
  return this->mpData->mTextureFlags >> 2 & 7;
}


/* __thiscall JPABaseShapeArc::getTextureIndex(unsigned char) */

byte __thiscall JPABaseShapeArc::getTextureIndex(JPABaseShapeArc *this,uchar param_1)

{
  return this->mpTexAnmIdxArr[param_1];
}


/* __thiscall JPABaseShapeArc::getTextureIndex(void) */

byte __thiscall JPABaseShapeArc::getTextureIndex(JPABaseShapeArc *this)

{
  return this->mpData->mTextureIndex;
}


/* __thiscall JPABaseShapeArc::isEnablePrm(void) */

byte __thiscall JPABaseShapeArc::isEnablePrm(JPABaseShapeArc *this)

{
  return this->mpData->mColorFlags & 1;
}


/* __thiscall JPABaseShapeArc::isEnableEnv(void) */

byte __thiscall JPABaseShapeArc::isEnableEnv(JPABaseShapeArc *this)

{
  return this->mpData->mColorFlags & 4;
}


/* __thiscall JPABaseShapeArc::getPrmColor(short) */

_GXColor __thiscall JPABaseShapeArc::getPrmColor(JPABaseShapeArc *this,short param_1)

{
  return this->mpPrmColorArr[param_1];
}


/* __thiscall JPABaseShapeArc::getPrmColor(void) */

_GXColor __thiscall JPABaseShapeArc::getPrmColor(JPABaseShapeArc *this)

{
  return this->mpData->mPrmColor;
}


/* __thiscall JPABaseShapeArc::getEnvColor(short) */

_GXColor __thiscall JPABaseShapeArc::getEnvColor(JPABaseShapeArc *this,short param_1)

{
  return this->mpEnvColorArr[param_1];
}


/* __thiscall JPABaseShapeArc::getEnvColor(void) */

_GXColor __thiscall JPABaseShapeArc::getEnvColor(JPABaseShapeArc *this)

{
  return this->mpData->mEnvColor;
}


/* __thiscall JPABaseShapeArc::getColorRegAnmType(void) */

byte __thiscall JPABaseShapeArc::getColorRegAnmType(JPABaseShapeArc *this)

{
  return this->mpData->mColorFlags >> 4 & 7;
}


/* __thiscall JPABaseShapeArc::getColorRegAnmMaxFrm(void) */

int __thiscall JPABaseShapeArc::getColorRegAnmMaxFrm(JPABaseShapeArc *this)

{
  return (int)this->mpData->mColorRegAnmMaxFrm;
}


/* __thiscall JPABaseShapeArc::isEnableTexScrollAnm(void) */

uint __thiscall JPABaseShapeArc::isEnableTexScrollAnm(JPABaseShapeArc *this)

{
  return this->mpData->mFlags & 0x1000000;
}


/* __thiscall JPABaseShapeArc::getTilingX(void) */

double __thiscall JPABaseShapeArc::getTilingX(JPABaseShapeArc *this)

{
  return (double)this->mpData->mTilingX;
}


/* __thiscall JPABaseShapeArc::getTilingY(void) */

double __thiscall JPABaseShapeArc::getTilingY(JPABaseShapeArc *this)

{
  return (double)this->mpData->mTilingY;
}


/* __thiscall JPABaseShapeArc::getTexStaticTransX(void) */

double __thiscall JPABaseShapeArc::getTexStaticTransX(JPABaseShapeArc *this)

{
  return (double)this->mpData->mTexStaticTransX;
}


/* __thiscall JPABaseShapeArc::getTexStaticTransY(void) */

double __thiscall JPABaseShapeArc::getTexStaticTransY(JPABaseShapeArc *this)

{
  return (double)this->mpData->mTexStaticTransY;
}


/* __thiscall JPABaseShapeArc::getTexStaticScaleX(void) */

double __thiscall JPABaseShapeArc::getTexStaticScaleX(JPABaseShapeArc *this)

{
  return (double)this->mpData->mTexStaticScaleX;
}


/* __thiscall JPABaseShapeArc::getTexStaticScaleY(void) */

double __thiscall JPABaseShapeArc::getTexStaticScaleY(JPABaseShapeArc *this)

{
  return (double)this->mpData->mTexStaticScaleY;
}


/* __thiscall JPABaseShapeArc::getTexScrollTransX(void) */

double __thiscall JPABaseShapeArc::getTexScrollTransX(JPABaseShapeArc *this)

{
  return (double)this->mpData->mTexScrollTransX;
}


/* __thiscall JPABaseShapeArc::getTexScrollTransY(void) */

double __thiscall JPABaseShapeArc::getTexScrollTransY(JPABaseShapeArc *this)

{
  return (double)this->mpData->mTexScrollTransY;
}


/* __thiscall JPABaseShapeArc::getTexScrollScaleX(void) */

double __thiscall JPABaseShapeArc::getTexScrollScaleX(JPABaseShapeArc *this)

{
  return (double)this->mpData->mTexScrollScaleX;
}


/* __thiscall JPABaseShapeArc::getTexScrollScaleY(void) */

double __thiscall JPABaseShapeArc::getTexScrollScaleY(JPABaseShapeArc *this)

{
  return (double)this->mpData->mTexScrollScaleY;
}


/* __thiscall JPABaseShapeArc::getTexScrollRotate(void) */

double __thiscall JPABaseShapeArc::getTexScrollRotate(JPABaseShapeArc *this)

{
  return (double)this->mpData->mTexScrollRotate;
}

