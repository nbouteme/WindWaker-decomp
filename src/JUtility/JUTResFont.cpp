#include <JUtility/JUTResFont.h>
#include <JUtility/JUTFont.h>
#include <JUtility/JUTResFont.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTConsole.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <gx/GXLight.h>
#include <gx/GXTev.h>
#include <gx/GXAttr.h>
#include <gx/GXPixel.h>
#include <gx/GXGeometry.h>
#include <gx/GXTexture.h>
#include <JUTResFont.h>


/* __thiscall JUTResFont::JUTResFont(void) */

void __thiscall JUTResFont::JUTResFont(JUTResFont *this)

{
  JUTFont::JUTFont(&this->parent);
  (this->parent).vtbl = (JUTFont__vtbl *)&__vt;
  initialize_state(this);
  JUTFont::initialize_state(&this->parent);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JUTResFont::JUTResFont(ResFONT const *,
                                     JKRHeap *) */

void __thiscall JUTResFont::JUTResFont(JUTResFont *this,ResFONT *param_1,JKRHeap *param_2)

{
  JUTFont::JUTFont(&this->parent);
  (this->parent).vtbl = (JUTFont__vtbl *)&__vt;
  initialize_state(this);
  initiate(this,param_1,param_2);
  return;
}


/* __thiscall JUTResFont::~JUTResFont(void) */

void __thiscall JUTResFont::_JUTResFont(JUTResFont *this)

{
  short in_r4;
  
  if (this != (JUTResFont *)0x0) {
    (this->parent).vtbl = (JUTFont__vtbl *)&__vt;
    if ((this->parent).mValid != 0) {
      deleteMemBlocks_ResFont(this);
      initialize_state(this);
      JUTFont::initialize_state(&this->parent);
    }
    if (this != (JUTResFont *)0x0) {
      (this->parent).vtbl = (JUTFont__vtbl *)&JUTFont::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JUTResFont::deleteMemBlocks_ResFont(void) */

void __thiscall JUTResFont::deleteMemBlocks_ResFont(JUTResFont *this)

{
  JKernel::operator_delete__(this->mpMemBlock);
  return;
}


/* __thiscall JUTResFont::initialize_state(void) */

void __thiscall JUTResFont::initialize_state(JUTResFont *this)

{
  this->mpResFONT = (ResFONT *)0x0;
  this->mpMemBlock = (void *)0x0;
  this->mpWidth = (void *)0x0;
  this->mpGlyph = (void *)0x0;
  this->mpMAP1 = (ResFONT__MAP1 **)0x0;
  *(undefined4 *)&this->field_0x1c = 0;
  *(undefined4 *)&this->field_0x20 = 0;
  *(undefined4 *)&this->field_0x44 = 0xffffffff;
  return;
}


/* __thiscall JUTResFont::initiate(ResFONT const *,
                                   JKRHeap *) */

bool __thiscall JUTResFont::initiate(JUTResFont *this,ResFONT *param_1,JKRHeap *param_2)

{
  char cVar1;
  
  cVar1 = protected_initiate(this,param_1,param_2);
  if (cVar1 == '\0') {
    deleteMemBlocks_ResFont(this);
    initialize_state(this);
    JUTFont::initialize_state(&this->parent);
    (this->parent).mValid = 0;
  }
  return cVar1 != '\0';
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JUTResFont::protected_initiate(ResFONT const *,
                                             JKRHeap *) */

undefined4 __thiscall
JUTResFont::protected_initiate(JUTResFont *this,ResFONT *param_1,JKRHeap *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  ResFONT__MAP1 *pRVar3;
  
  deleteMemBlocks_ResFont(this);
  initialize_state(this);
  JUTFont::initialize_state(&this->parent);
  if (param_1 == (ResFONT *)0x0) {
    uVar1 = 0;
  }
  else {
    this->mpResFONT = param_1;
    (this->parent).mValid = 1;
    countBlock(this);
    pvVar2 = (void *)JKernel::operator_new__
                               (((uint)this->mNumWidth + (uint)this->mNumGlyph + (uint)this->mNumMap
                                ) * 4,param_2,0);
    this->mpMemBlock = pvVar2;
    pRVar3 = (ResFONT__MAP1 *)this->mpMemBlock;
    if (pRVar3 == (ResFONT__MAP1 *)0x0) {
      uVar1 = 0;
    }
    else {
      if (this->mNumWidth != 0) {
        this->mpWidth = pRVar3;
        pRVar3 = (ResFONT__MAP1 *)(pRVar3->mMagic + (uint)this->mNumWidth * 4);
      }
      if (this->mNumGlyph != 0) {
        this->mpGlyph = pRVar3;
        pRVar3 = (ResFONT__MAP1 *)(pRVar3->mMagic + (uint)this->mNumGlyph * 4);
      }
      if (this->mNumMap != 0) {
        this->mpMAP1 = (ResFONT__MAP1 **)pRVar3;
      }
      (*(code *)((this->parent).vtbl)->setBlock)(this);
      uVar1 = 1;
    }
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JUTResFont::countBlock(void) */

void __thiscall JUTResFont::countBlock(JUTResFont *this)

{
  int iVar1;
  uint blockIdx;
  ResFONT *pRVar2;
  
  this->mNumWidth = 0;
  this->mNumGlyph = 0;
  this->mNumMap = 0;
  pRVar2 = this->mpResFONT + 1;
  blockIdx = 0;
  do {
    if (this->mpResFONT->mBlockNum <= blockIdx) {
      return;
    }
    iVar1 = *(int *)pRVar2->mMagic;
                    /* MAP1 */
    if (iVar1 == 0x4d415031) {
      this->mNumMap = this->mNumMap + 1;
    }
    else {
      if (iVar1 < 0x4d415031) {
                    /* INF1 */
        if (iVar1 != 0x494e4631) {
          if ((0x494e4630 < iVar1) || (iVar1 != 0x474c5931)) goto LAB_802c23f8;
          this->mNumGlyph = this->mNumGlyph + 1;
        }
      }
      else {
        if (iVar1 == 0x57494431) {
          this->mNumWidth = this->mNumWidth + 1;
        }
        else {
LAB_802c23f8:
          JUtility::JUTReportConsole("JUTResFont: Unknown data block\n");
        }
      }
    }
    pRVar2 = (ResFONT *)(pRVar2->mMagic + *(int *)&pRVar2->field_0x4);
    blockIdx = blockIdx + 1;
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall JUTResFont::setBlock(void) */

void __thiscall JUTResFont::setBlock(JUTResFont *this)

{
  ushort uVar1;
  ulong uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  ResFONT *pRVar9;
  
  iVar7 = 0;
  iVar6 = 0;
  iVar5 = 0;
  this->mMaxGlyph = -1;
  pRVar9 = this->mpResFONT + 1;
  uVar8 = 0;
  do {
    if (this->mpResFONT->mBlockNum <= uVar8) {
      return;
    }
    iVar3 = *(int *)pRVar9->mMagic;
    if (iVar3 == 0x4d415031) {
      *(ResFONT **)((int)this->mpMAP1 + iVar5) = pRVar9;
      uVar1 = *(ushort *)(*(int *)((int)this->mpMAP1 + iVar5) + 10);
      if (uVar1 < (ushort)this->mMaxGlyph) {
        this->mMaxGlyph = uVar1;
      }
      iVar5 = iVar5 + 4;
    }
    else {
      if (iVar3 < 0x4d415031) {
                    /* INF1 */
        if (iVar3 == 0x494e4631) {
          this->mpINF1 = (ResFONT__INF1 *)pRVar9;
          uVar4 = (uint)(ushort)this->mpINF1->mFontEncoding;
          if (2 < uVar4) {
            uVar2 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar2,"JUTResFont.cpp",0xf3,"u < suAboutEncoding_");
            m_Do_printf::OSPanic("JUTResFont.cpp",0xf3,&DAT_8036bf58);
          }
          this->mpEncodingFunc = (undefined *)(&saoAboutEncoding_ + uVar4);
        }
        else {
          if ((0x494e4630 < iVar3) || (iVar3 != 0x474c5931)) goto LAB_802c257c;
          *(ResFONT **)((int)this->mpGlyph + iVar6) = pRVar9;
          iVar6 = iVar6 + 4;
        }
      }
      else {
        if (iVar3 == 0x57494431) {
          *(ResFONT **)((int)this->mpWidth + iVar7) = pRVar9;
          iVar7 = iVar7 + 4;
        }
        else {
LAB_802c257c:
          JUtility::JUTReportConsole("Unknown data block\n");
        }
      }
    }
    pRVar9 = (ResFONT *)(pRVar9->mMagic + *(int *)&pRVar9->field_0x4);
    uVar8 = uVar8 + 1;
  } while( true );
}


/* __thiscall JUTResFont::setGX(void) */

void __thiscall JUTResFont::setGX(JUTResFont *this)

{
  gx::GXSetNumChans(1);
  gx::GXSetNumTevStages(1);
  gx::GXSetNumTexGens(1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR0A0);
  gx::GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_VTX,0,GX_DF_NONE,GX_AF_NONE);
  gx::GXSetTevOp(0,0);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA8,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBX8,0xf);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_CLR0,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
  return;
}


/* __thiscall JUTResFont::setGX(JUtility::TColor,
                                JUtility::TColor) */

void __thiscall JUTResFont::setGX(JUTResFont *this,TColor param_1,TColor param_2)

{
  _GXColor local_18;
  _GXColor local_14 [3];
  
  if ((*(int *)param_1 == 0) && (*(int *)param_2 == -1)) {
    (*(code *)((this->parent).vtbl)->setGX)();
  }
  else {
    gx::GXSetNumChans(1);
    gx::GXSetNumTevStages(2);
    gx::GXSetNumTexGens(1);
    gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
    gx::GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_VTX,0,GX_DF_NONE,GX_AF_NONE);
    local_14[0] = *(_GXColor *)param_1;
    gx::GXSetTevColor(GX_TEVREG0,local_14);
    local_18 = *(_GXColor *)param_2;
    gx::GXSetTevColor(GX_TEVREG1,&local_18);
    gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C0,GX_CC_C1,GX_CC_TEXC,GX_CC_ZERO);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_A0,GX_CA_A1,GX_CA_TEXA,GX_CA_ZERO);
    gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
    gx::GXSetTevColorIn(GX_TEVSTAGE1,GX_CC_ZERO,GX_CC_CPREV,GX_CC_RASC,GX_CC_ZERO);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE1,GX_CA_ZERO,GX_CA_APREV,GX_CA_RASA,GX_CA_ZERO);
    gx::GXSetTevColorOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA8,0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBX8,0xf);
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
    gx::GXSetVtxDesc(GX_VA_CLR0,GX_DIRECT);
    gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x802c2d44) */
/* WARNING: Removing unreachable block (ram,0x802c2d34) */
/* WARNING: Removing unreachable block (ram,0x802c2d24) */
/* WARNING: Removing unreachable block (ram,0x802c2d2c) */
/* WARNING: Removing unreachable block (ram,0x802c2d3c) */
/* WARNING: Removing unreachable block (ram,0x802c2d4c) */
/* __thiscall JUTResFont::drawChar_scale(float,
                                         float,
                                         float,
                                         float,
                                         int,
                                         bool) */

double __thiscall
JUTResFont::drawChar_scale
          (JUTResFont *this,float param_1,float param_2,float param_3,float param_4,int param_5,
          bool param_6)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ulong uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined4 uVar13;
  double dVar14;
  double dVar15;
  undefined8 in_f26;
  double dVar16;
  undefined8 in_f27;
  double dVar17;
  undefined8 in_f28;
  double dVar18;
  undefined8 in_f29;
  double dVar19;
  undefined8 in_f30;
  double dVar20;
  undefined8 in_f31;
  double dVar21;
  TWidth local_a8;
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar18 = (double)param_4;
  dVar16 = (double)param_3;
  dVar17 = (double)param_2;
  dVar21 = (double)param_1;
  uVar13 = 0;
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
  if ((this->parent).mValid == 0) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"JUTResFont.cpp",0x179,"mValid");
    m_Do_printf::OSPanic("JUTResFont.cpp",0x179,&DAT_8036bf58);
  }
  loadFont(this,param_5,0,&local_a8);
  if (((this->parent).field_0x5 == 0) && (param_6 != false)) {
    uVar6 = (*(code *)((this->parent).vtbl)->getCellWidth)(this);
    dVar21 = (double)(float)(dVar21 - (double)((float)((double)CONCAT44(0x43300000,
                                                                        (uint)local_a8.field_0x0) -
                                                      JUtility::_626) *
                                              (float)(dVar16 / (double)(float)((double)CONCAT44(
                                                  0x43300000,uVar6 ^ 0x80000000) - JUtility::_624)))
                            );
  }
  uVar6 = (*(code *)((this->parent).vtbl)->getCellWidth)(this);
  dVar14 = (double)(float)(dVar16 / (double)(float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000)
                                                   - JUtility::_624));
  dVar19 = (double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                            (this->parent).mWidth ^ 0x80000000) -
                                          JUtility::_624) * dVar14);
  dVar15 = JUtility::_624;
  if ((this->parent).field_0x5 == 0) {
    if (param_6 == false) {
      uVar6 = (*(code *)((this->parent).vtbl)->getCellWidth)(this);
      dVar14 = (double)(float)(dVar16 / (double)(float)((double)CONCAT44(0x43300000,
                                                                         uVar6 ^ 0x80000000) -
                                                       JUtility::_624));
      dVar19 = (double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                                (uint)local_a8.mAdvance +
                                                                (uint)local_a8.field_0x0 ^
                                                                0x80000000) - JUtility::_624) *
                              dVar14);
      dVar15 = JUtility::_624;
    }
    else {
      uVar6 = (*(code *)((this->parent).vtbl)->getCellWidth)(dVar14,this);
      dVar15 = (double)(float)(dVar16 / (double)(float)((double)CONCAT44(0x43300000,
                                                                         uVar6 ^ 0x80000000) -
                                                       JUtility::_624));
      dVar19 = (double)(float)((double)(float)((double)CONCAT44(0x43300000,(uint)local_a8.mAdvance)
                                              - JUtility::_626) * dVar15);
      dVar14 = JUtility::_626;
    }
  }
  dVar20 = (double)(float)(dVar21 + dVar16);
  uVar6 = (*(code *)((this->parent).vtbl)->getHeight)(dVar14,dVar15,this);
  dVar16 = (double)(float)(dVar18 / (double)(float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000)
                                                   - JUtility::_624));
  uVar6 = (*(code *)((this->parent).vtbl)->getAscent)(this);
  dVar16 = (double)(float)(dVar17 - (double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                                                     uVar6 ^ 
                                                  0x80000000) - JUtility::_624) * dVar16));
  uVar6 = (*(code *)((this->parent).vtbl)->getHeight)(this);
  dVar18 = (double)(float)(dVar18 / (double)(float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000)
                                                   - JUtility::_624));
  uVar6 = (*(code *)((this->parent).vtbl)->getDescent)(this);
  dVar17 = (double)(float)(dVar17 + (double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                                                     uVar6 ^ 
                                                  0x80000000) - JUtility::_624) * dVar18));
  iVar9 = *(int *)&this->field_0x1c;
  iVar7 = *(int *)((int)this->mpGlyph + (uint)*(ushort *)&this->field_0x66 * 4);
  uVar1 = *(ushort *)(iVar7 + 0x1a);
  iVar8 = *(int *)&this->field_0x20;
  uVar2 = *(ushort *)(iVar7 + 0x1c);
  uVar3 = *(ushort *)(iVar7 + 0xc);
  uVar4 = *(ushort *)(iVar7 + 0xe);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXBegin(0x80,0,4);
  write_volatile_4(0xcc008000,(float)dVar21);
  write_volatile_4(0xcc008000,(float)dVar16);
  write_volatile_4(0xcc008000,JUtility::_622);
  write_volatile_4(0xcc008000,(this->parent).field_0xc);
  uVar12 = (undefined2)((iVar9 << 0xf) / (int)(uint)uVar1);
  write_volatile_2(0xcc008000,uVar12);
  uVar11 = (undefined2)((iVar8 << 0xf) / (int)(uint)uVar2);
  write_volatile_2(0xcc008000,uVar11);
  write_volatile_4(0xcc008000,(float)dVar20);
  write_volatile_4(0xcc008000,(float)dVar16);
  write_volatile_4(0xcc008000,JUtility::_622);
  write_volatile_4(0xcc008000,(this->parent).field_0x10);
  uVar10 = (undefined2)((int)((iVar9 + (uint)uVar3) * 0x8000) / (int)(uint)uVar1);
  write_volatile_2(0xcc008000,uVar10);
  write_volatile_2(0xcc008000,uVar11);
  write_volatile_4(0xcc008000,(float)dVar20);
  write_volatile_4(0xcc008000,(float)dVar17);
  write_volatile_4(0xcc008000,JUtility::_622);
  write_volatile_4(0xcc008000,(this->parent).field_0x18);
  write_volatile_2(0xcc008000,uVar10);
  uVar10 = (undefined2)((int)((iVar8 + (uint)uVar4) * 0x8000) / (int)(uint)uVar2);
  write_volatile_2(0xcc008000,uVar10);
  write_volatile_4(0xcc008000,(float)dVar21);
  write_volatile_4(0xcc008000,(float)dVar17);
  write_volatile_4(0xcc008000,JUtility::_622);
  write_volatile_4(0xcc008000,(this->parent).field_0x14);
  write_volatile_2(0xcc008000,uVar12);
  write_volatile_2(0xcc008000,uVar10);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
  __psq_l0(auStack8,uVar13);
  __psq_l1(auStack8,uVar13);
  __psq_l0(auStack24,uVar13);
  __psq_l1(auStack24,uVar13);
  __psq_l0(auStack40,uVar13);
  __psq_l1(auStack40,uVar13);
  __psq_l0(auStack56,uVar13);
  __psq_l1(auStack56,uVar13);
  __psq_l0(auStack72,uVar13);
  __psq_l1(auStack72,uVar13);
  __psq_l0(auStack88,uVar13);
  __psq_l1(auStack88,uVar13);
  return dVar19;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JUTResFont::loadFont(int,
                                   _GXTexMapID,
                                   JUTFont::TWidth *) */

void __thiscall
JUTResFont::loadFont(JUTResFont *this,int code,_GXTexMapID texMapID,TWidth *pDstWidth)

{
  uint uVar1;
  
  if (pDstWidth != (TWidth *)0x0) {
    (*(code *)((this->parent).vtbl)->getWidthEntry)(this,code,pDstWidth);
  }
  uVar1 = getFontCode(this,code);
  (*(code *)((this->parent).vtbl)->loadImage)(this,uVar1,texMapID);
  return;
}


/* __thiscall JUTResFont::getWidthEntry(int,
                                        JUTFont::TWidth *) const */

void __thiscall JUTResFont::getWidthEntry(JUTResFont *this,int code,TWidth *pWidth)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = getFontCode(this,code);
  iVar5 = 0;
  pWidth->field_0x0 = 0;
  pWidth->mAdvance = (byte)this->mpINF1->mFallbackWidth;
  uVar1 = (uint)this->mNumWidth;
  while( true ) {
    if (uVar1 == 0) {
      return;
    }
    iVar4 = *(int *)((int)this->mpWidth + iVar5);
    if (((int)(uint)*(ushort *)(iVar4 + 8) <= (int)uVar2) &&
       ((int)uVar2 <= (int)(uint)*(ushort *)(iVar4 + 10))) break;
    iVar5 = iVar5 + 4;
    uVar1 = uVar1 - 1;
  }
  pbVar3 = (byte *)(iVar4 + (uVar2 - *(ushort *)(iVar4 + 8)) * 2 + 0xc);
  pWidth->field_0x0 = *pbVar3;
  pWidth->mAdvance = pbVar3[1];
  return;
}


/* __thiscall JUTResFont::getCellWidth(void) const */

uint __thiscall JUTResFont::getCellWidth(JUTResFont *this)

{
  uint uVar1;
  int iVar2;
  
                    /* WARNING: Load size is inaccurate */
  if (((int *)this->mpGlyph == (int *)0x0) || (iVar2 = *this->mpGlyph, iVar2 == 0)) {
    uVar1 = (*(code *)((this->parent).vtbl)->getWidth)();
  }
  else {
    uVar1 = (uint)*(ushort *)(iVar2 + 0xc);
  }
  return uVar1;
}


/* __thiscall JUTResFont::getCellHeight(void) const */

uint __thiscall JUTResFont::getCellHeight(JUTResFont *this)

{
  uint uVar1;
  int iVar2;
  
                    /* WARNING: Load size is inaccurate */
  if (((int *)this->mpGlyph == (int *)0x0) || (iVar2 = *this->mpGlyph, iVar2 == 0)) {
    uVar1 = (*(code *)((this->parent).vtbl)->getHeight)();
  }
  else {
    uVar1 = (uint)*(ushort *)(iVar2 + 0xe);
  }
  return uVar1;
}


/* __thiscall JUTResFont::isLeadByte(int) const */

void __thiscall JUTResFont::isLeadByte(JUTResFont *this,int param_1)

{
  (**(code **)this->mpEncodingFunc)(param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JUTResFont::getFontCode(int) const */

uint __thiscall JUTResFont::getFontCode(JUTResFont *this,int code)

{
  ushort uVar1;
  uint max;
  int encoding;
  int idx;
  ResFONT__MAP1 *pMAP1;
  uint uVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = (uint)this->mpINF1->mFallbackCode;
  encoding = (*(code *)((this->parent).vtbl)->getFontType)();
  if ((((encoding == 2) && (0x7fff < (ushort)this->mMaxGlyph)) && (0x1f < code)) &&
     ((uint)code < 0x7f)) {
    code = ZEXT24(*(ushort *)("JUTTexture: TLUT is NULL\n" + code * 2 + 0x15));
  }
  idx = 0;
  max = (uint)this->mNumMap;
  while( true ) {
    if (max == 0) {
      return uVar6;
    }
    pMAP1 = *(ResFONT__MAP1 **)((int)this->mpMAP1 + idx);
    uVar2 = (uint)pMAP1->mMinGlyph;
    if (((int)uVar2 <= code) && (code <= (int)(uint)pMAP1->mMaxGlyph)) break;
    idx = idx + 4;
    max = max - 1;
  }
  uVar1 = pMAP1->mType;
  if (uVar1 == 0) {
    return code - uVar2;
  }
  if (uVar1 == 2) {
    return (uint)*(ushort *)((int)pMAP1 + (code - uVar2) * 2 + 0x10);
  }
  if (uVar1 != 3) {
    if (uVar1 != 1) {
      return uVar6;
    }
    puVar3 = (ushort *)0x0;
    if (*(short *)pMAP1[1].mMagic == 1) {
      puVar3 = (ushort *)(pMAP1[1].mMagic + 2);
    }
    uVar6 = convertSjis(this,code,puVar3);
    return uVar6;
  }
  iVar4 = 0;
  encoding = *(ushort *)pMAP1[1].mMagic - 1;
  while( true ) {
    while( true ) {
      if (encoding < iVar4) {
        return uVar6;
      }
      max = encoding + iVar4;
      iVar5 = ((int)max >> 1) + (uint)((int)max < 0 && (max & 1) != 0);
      max = (uint)*(ushort *)(pMAP1[1].mMagic + 2 + iVar5 * 4);
      if ((int)max <= code) break;
      encoding = iVar5 + -1;
    }
    if (code <= (int)max) break;
    iVar4 = iVar5 + 1;
  }
  return (uint)*(ushort *)(pMAP1[1].mMagic + 2 + iVar5 * 4 + 2);
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JUTResFont::loadImage(int,
                                    _GXTexMapID) */

void __thiscall JUTResFont::loadImage(JUTResFont *this,int param_1,_GXTexMapID param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  double dVar9;
  
  uVar8 = 0;
  iVar1 = 0;
  uVar2 = (uint)this->mNumGlyph;
  do {
    if (uVar2 == 0) {
LAB_802c314c:
      if (uVar8 != this->mNumGlyph) {
        iVar1 = uVar8 * 4;
        iVar4 = *(int *)((int)this->mpGlyph + iVar1);
        uVar2 = (uint)*(ushort *)(iVar4 + 0x16);
        iVar3 = uVar2 * *(ushort *)(iVar4 + 0x18);
        iVar7 = param_1 / iVar3;
        iVar3 = param_1 - iVar7 * iVar3;
        iVar6 = iVar3 / (int)uVar2;
        *(uint *)&this->field_0x1c = (iVar3 - iVar6 * uVar2) * (uint)*(ushort *)(iVar4 + 0xc);
        *(uint *)&this->field_0x20 =
             iVar6 * (uint)*(ushort *)(*(int *)((int)this->mpGlyph + iVar1) + 0xe);
        if ((iVar7 != *(int *)&this->field_0x44) || (uVar8 != *(ushort *)&this->field_0x66)) {
          iVar1 = *(int *)((int)this->mpGlyph + iVar1);
          gx::GXInitTexObj(&this->mTexObj,(void *)(iVar1 + iVar7 * *(int *)(iVar1 + 0x10) + 0x20),
                           (uint)*(ushort *)(iVar1 + 0x1a),(uint)*(ushort *)(iVar1 + 0x1c),
                           (_GXTexFmt)*(undefined2 *)(iVar1 + 0x14),GX_CLAMP,GX_CLAMP,false);
          dVar9 = (double)JUtility::_622;
          gx::GXInitTexObjLOD(dVar9,dVar9,dVar9,&this->mTexObj,1,1,0,0,0);
          *(int *)&this->field_0x44 = iVar7;
          *(short *)&this->field_0x66 = (short)uVar8;
        }
        gx::GXLoadTexObj(&this->mTexObj,param_2);
      }
      return;
    }
    iVar3 = *(int *)((int)this->mpGlyph + iVar1);
    uVar5 = (uint)*(ushort *)(iVar3 + 8);
    if (((int)uVar5 <= param_1) && (param_1 <= (int)(uint)*(ushort *)(iVar3 + 10))) {
      param_1 = param_1 - uVar5;
      goto LAB_802c314c;
    }
    uVar8 = uVar8 + 1;
    iVar1 = iVar1 + 4;
    uVar2 = uVar2 - 1;
  } while( true );
}


/* __thiscall JUTResFont::convertSjis(int,
                                      unsigned short *) const */

int __thiscall JUTResFont::convertSjis(JUTResFont *this,int param_1,ushort *param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = (param_1 & 0xffU) - 0x40;
  if (0x3f < iVar2) {
    iVar2 = (param_1 & 0xffU) - 0x41;
  }
  uVar1 = 0x31c;
  if (param_2 != (ushort *)0x0) {
    uVar1 = (uint)*param_2;
  }
  return iVar2 + (((uint)param_1 >> 8 & 0xff) - 0x88) * 0xbc + -0x5e + uVar1;
}

