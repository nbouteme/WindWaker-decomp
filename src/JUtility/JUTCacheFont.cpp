#include <JUtility/JUTCacheFont.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTResFont.h>
#include <JUtility/JUTCacheFont.h>
#include <JUtility/JUTFont.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTConsole.h>
#include <JKernel/JKRAramHeap.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JKernel/JKRAram.h>
#include <gx/GXTexture.h>
#include <JUTCacheFont.h>


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JUTCacheFont::JUTCacheFont(ResFONT const *,
                                         unsigned long,
                                         JKRHeap *) */

void __thiscall
JUTCacheFont::JUTCacheFont(JUTCacheFont *this,ResFONT *param_1,ulong param_2,JKRHeap *param_3)

{
  JUTResFont::JUTResFont(&this->parent);
  (this->parent).parent.vtbl = (JUTFont__vtbl *)&__vt;
  initialize_state(this);
  JUTResFont::initialize_state(&this->parent);
  JUTFont::initialize_state((JUTFont *)this);
  initiate(this,param_1,(void *)0x0,param_2,param_3);
  return;
}


/* __thiscall JUTCacheFont::~JUTCacheFont(void) */

void __thiscall JUTCacheFont::_JUTCacheFont(JUTCacheFont *this)

{
  short in_r4;
  
  if (this != (JUTCacheFont *)0x0) {
    (this->parent).parent.vtbl = (JUTFont__vtbl *)&__vt;
    if ((this->parent).parent.mValid != 0) {
      deleteMemBlocks_CacheFont(this);
      initialize_state(this);
      JUTResFont::deleteMemBlocks_ResFont(&this->parent);
      JUTResFont::initialize_state(&this->parent);
      JUTFont::initialize_state((JUTFont *)this);
    }
    JUTResFont::_JUTResFont(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JUTCacheFont::deleteMemBlocks_CacheFont(void) */

void __thiscall JUTCacheFont::deleteMemBlocks_CacheFont(JUTCacheFont *this)

{
  int *piVar1;
  
  if (*(char *)&(this->parent).field_0xb0 != '\0') {
    JKernel::operator_delete__(*(undefined4 *)&(this->parent).field_0x90);
  }
  piVar1 = *(int **)&(this->parent).field_0xac;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  JKernel::operator_delete((JKRHeap *)(this->parent).mpINF1);
  JKernel::operator_delete((JKRHeap *)(this->parent).mpMemBlock);
  JKernel::operator_delete(*(JKRHeap **)&(this->parent).field_0x7c);
  JKernel::operator_delete(*(JKRHeap **)&(this->parent).field_0x80);
  JKernel::operator_delete(*(JKRHeap **)&(this->parent).field_0x84);
  return;
}


/* __thiscall JUTCacheFont::initialize_state(void) */

void __thiscall JUTCacheFont::initialize_state(JUTCacheFont *this)

{
  *(undefined *)&(this->parent).field_0xb0 = 0;
  *(undefined4 *)&(this->parent).field_0x90 = 0;
  *(undefined4 *)&(this->parent).field_0xac = 0;
  (this->parent).mpINF1 = (ResFONT__INF1 *)0x0;
  *(undefined4 *)&(this->parent).field_0x7c = 0;
  *(undefined4 *)&(this->parent).field_0x80 = 0;
  *(undefined4 *)&(this->parent).field_0x84 = 0;
  (this->parent).mpMemBlock = (void *)0x0;
  *(undefined4 *)&(this->parent).field_0x8c = 0;
  *(undefined4 *)&(this->parent).field_0x88 = 0;
  *(undefined4 *)&(this->parent).field_0x90 = 0;
  *(undefined4 *)&(this->parent).field_0x9c = 0;
  *(undefined4 *)&(this->parent).field_0xa0 = 0;
  return;
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* __thiscall JUTCacheFont::getMemorySize(ResFONT const *,
                                          unsigned short *,
                                          unsigned long *,
                                          unsigned short *,
                                          unsigned long *,
                                          unsigned short *,
                                          unsigned long *,
                                          unsigned long *) */

undefined4 __thiscall
JUTCacheFont::getMemorySize
          (JUTCacheFont *this,ResFONT *param_1,ushort *param_2,ulong *param_3,ushort *param_4,
          ulong *param_5,ushort *param_6,ulong *param_7,ulong *param_8)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  ResFONT *pRVar4;
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  ushort uVar9;
  ushort uVar10;
  ushort uVar11;
  
  if (param_1 == (ResFONT *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar11 = 0;
    uVar10 = 0;
    uVar9 = 0;
    uVar8 = 0;
    uVar7 = 0;
    uVar6 = 0;
    uVar5 = 0;
    pRVar4 = param_1 + 1;
    for (uVar3 = 0; uVar3 < param_1->mBlockNum; uVar3 = uVar3 + 1) {
      iVar2 = *(int *)pRVar4->mMagic;
      if (iVar2 == 0x4d415031) {
        uVar6 = uVar6 + *(int *)&pRVar4->field_0x4;
        uVar9 = uVar9 + 1;
      }
      else {
        if (iVar2 < 0x4d415031) {
          if (iVar2 != 0x494e4631) {
            if ((0x494e4630 < iVar2) || (iVar2 != 0x474c5931)) goto LAB_802c06a4;
            uVar7 = uVar7 + *(int *)&pRVar4->field_0x4;
            uVar10 = uVar10 + 1;
            if (uVar5 < *(uint *)&pRVar4->field_0x10) {
              uVar5 = *(uint *)&pRVar4->field_0x10;
            }
          }
        }
        else {
          if (iVar2 == 0x57494431) {
            uVar8 = uVar8 + *(int *)&pRVar4->field_0x4;
            uVar11 = uVar11 + 1;
          }
          else {
LAB_802c06a4:
            JUtility::JUTReportConsole("JUTCacheFont: Unknown data block\n");
          }
        }
      }
      pRVar4 = (ResFONT *)(pRVar4->mMagic + *(int *)&pRVar4->field_0x4);
    }
    if (param_2 != (ushort *)0x0) {
      *param_2 = uVar11;
    }
    if (param_4 != (ushort *)0x0) {
      *param_4 = uVar10;
    }
    if (param_6 != (ushort *)0x0) {
      *param_6 = uVar9;
    }
    if (param_3 != (ulong *)0x0) {
      *param_3 = uVar8;
    }
    if (param_5 != (ulong *)0x0) {
      *param_5 = uVar7;
    }
    if (param_7 != (ulong *)0x0) {
      *param_7 = uVar6;
    }
    if (param_8 != (ulong *)0x0) {
      *param_8 = uVar5;
    }
    uVar1 = 1;
  }
  return uVar1;
}


/* __thiscall JUTCacheFont::initiate(ResFONT const *,
                                     void *,
                                     unsigned long,
                                     JKRHeap *) */

bool __thiscall
JUTCacheFont::initiate
          (JUTCacheFont *this,ResFONT *param_1,void *param_2,ulong param_3,JKRHeap *param_4)

{
  char cVar1;
  
  cVar1 = internal_initiate(this,param_1,param_2,param_3,param_4);
  if (cVar1 == '\0') {
    deleteMemBlocks_CacheFont(this);
    JUTResFont::deleteMemBlocks_ResFont(&this->parent);
    JUTFont::initialize_state((JUTFont *)this);
    (this->parent).parent.mValid = 0;
  }
  return cVar1 != '\0';
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JUTCacheFont::internal_initiate(ResFONT const *,
                                              void *,
                                              unsigned long,
                                              JKRHeap *) */

undefined4 __thiscall
JUTCacheFont::internal_initiate
          (JUTCacheFont *this,ResFONT *param_1,void *param_2,ulong param_3,JKRHeap *param_4)

{
  undefined4 uVar1;
  char cVar2;
  
  deleteMemBlocks_CacheFont(this);
  initialize_state(this);
  JUTResFont::deleteMemBlocks_ResFont(&this->parent);
  JUTResFont::initialize_state(&this->parent);
  JUTFont::initialize_state((JUTFont *)this);
  if (param_1 == (ResFONT *)0x0) {
    uVar1 = 0;
  }
  else {
    (this->parent).mpResFONT = param_1;
    (this->parent).parent.mValid = 1;
    getMemorySize(this,param_1,&(this->parent).mNumWidth,(ulong *)&(this->parent).field_0x70,
                  &(this->parent).mNumGlyph,(ulong *)&(this->parent).field_0x74,
                  &(this->parent).mNumMap,(ulong *)&(this->parent).field_0x78,
                  (ulong *)&(this->parent).field_0x88);
    cVar2 = allocArea(this,param_2,param_3,param_4);
    if (cVar2 == '\0') {
      uVar1 = 0;
    }
    else {
      cVar2 = allocArray(this,param_4);
      if (cVar2 == '\0') {
        uVar1 = 0;
      }
      else {
        (*(code *)((this->parent).parent.vtbl)->setBlock)(this);
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JUTCacheFont::allocArea(void *,
                                      unsigned long,
                                      JKRHeap *) */

undefined4 __thiscall
JUTCacheFont::allocArea(JUTCacheFont *this,void *param_1,ulong param_2,JKRHeap *param_3)

{
  uint uVar1;
  ResFONT__INF1 *pRVar2;
  int iVar3;
  undefined4 uVar4;
  ulong uVar5;
  
  pRVar2 = (ResFONT__INF1 *)JKernel::operator_new(0x20,param_3,0);
  (this->parent).mpINF1 = pRVar2;
  if ((this->parent).mpINF1 == (ResFONT__INF1 *)0x0) {
    return 0;
  }
  iVar3 = *(int *)&(this->parent).field_0x70;
  if (iVar3 != 0) {
    uVar4 = JKernel::operator_new__(iVar3,param_3,0);
    *(undefined4 *)&(this->parent).field_0x7c = uVar4;
    if (*(int *)&(this->parent).field_0x7c == 0) {
      return 0;
    }
  }
  uVar1 = (uint)(this->parent).mNumGlyph;
  if (uVar1 != 0) {
    uVar4 = JKernel::operator_new__(uVar1 << 5,param_3,0);
    *(undefined4 *)&(this->parent).field_0x80 = uVar4;
    if (*(int *)&(this->parent).field_0x80 == 0) {
      return 0;
    }
    uVar4 = JKRAramHeap::alloc(JKRAram::sAramObject->mpHeap,
                               *(int *)&(this->parent).field_0x74 +
                               (uint)(this->parent).mNumGlyph * -0x20,0);
    *(undefined4 *)&(this->parent).field_0xac = uVar4;
    if (*(int *)&(this->parent).field_0xac == 0) {
      return 0;
    }
  }
  iVar3 = *(int *)&(this->parent).field_0x78;
  if (iVar3 != 0) {
    uVar4 = JKernel::operator_new__(iVar3,param_3,0);
    *(undefined4 *)&(this->parent).field_0x84 = uVar4;
    if (*(int *)&(this->parent).field_0x84 == 0) {
      return 0;
    }
  }
  *(int *)&(this->parent).field_0x94 = *(int *)&(this->parent).field_0x88 + 0x40;
  *(uint *)&(this->parent).field_0x98 = param_2 / *(uint *)&(this->parent).field_0x94;
  iVar3 = *(int *)&(this->parent).field_0x98;
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    if (param_1 == (void *)0x0) {
      uVar4 = JKernel::operator_new__(*(int *)&(this->parent).field_0x94 * iVar3,param_3,0x20);
      *(undefined4 *)&(this->parent).field_0x90 = uVar4;
      if (*(int *)&(this->parent).field_0x90 == 0) {
        return 0;
      }
      *(undefined *)&(this->parent).field_0xb0 = 1;
    }
    else {
      if (((uint)param_1 & 0x1f) != 0) {
        uVar5 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar5,"JUTCacheFont.cpp",0x15f,"( (u32)cacheBuffer & 0x1f ) == 0");
        m_Do_printf::OSPanic("JUTCacheFont.cpp",0x15f,&DAT_8036bd9c);
      }
      *(void **)&(this->parent).field_0x90 = param_1;
      *(undefined *)&(this->parent).field_0xb0 = 0;
    }
    invalidiateAllCache(this);
    uVar4 = 1;
  }
  return uVar4;
}


/* __thiscall JUTCacheFont::allocArray(JKRHeap *) */

undefined4 __thiscall JUTCacheFont::allocArray(JUTCacheFont *this,JKRHeap *param_1)

{
  void *pvVar1;
  ResFONT__MAP1 *pRVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  pvVar1 = (void *)JKernel::operator_new__
                             (((uint)(this->parent).mNumWidth +
                              (uint)(this->parent).mNumGlyph + (uint)(this->parent).mNumMap) * 4,
                              param_1,0);
  (this->parent).mpMemBlock = pvVar1;
  pRVar2 = (ResFONT__MAP1 *)(this->parent).mpMemBlock;
  if (pRVar2 == (ResFONT__MAP1 *)0x0) {
    uVar3 = 0;
  }
  else {
    if ((this->parent).mNumWidth != 0) {
      (this->parent).mpWidth = pRVar2;
      pRVar2 = (ResFONT__MAP1 *)(pRVar2->mMagic + (uint)(this->parent).mNumWidth * 4);
    }
    if ((this->parent).mNumGlyph != 0) {
      (this->parent).mpGlyph = pRVar2;
      pRVar2 = (ResFONT__MAP1 *)(pRVar2->mMagic + (uint)(this->parent).mNumGlyph * 4);
      iVar4 = 0;
      for (iVar5 = 0; iVar5 < (int)(uint)(this->parent).mNumGlyph; iVar5 = iVar5 + 1) {
        *(int *)((int)(this->parent).mpGlyph + iVar4) =
             *(int *)&(this->parent).field_0x90 + *(int *)&(this->parent).field_0x94 * iVar5;
        iVar4 = iVar4 + 4;
      }
    }
    if ((this->parent).mNumMap != 0) {
      (this->parent).mpMAP1 = (ResFONT__MAP1 **)pRVar2;
    }
    uVar3 = 1;
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* __thiscall JUTCacheFont::setBlock(void) */

void __thiscall JUTCacheFont::setBlock(JUTCacheFont *this)

{
  ushort uVar1;
  ulong uVar2;
  int iVar3;
  int in_r10;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  ResFONT *src;
  uchar *puVar9;
  byte *dst;
  uchar **dst_00;
  byte *dst_01;
  
  iVar7 = 0;
  iVar6 = 0;
  iVar5 = 0;
  dst_01 = *(byte **)&(this->parent).field_0x7c;
  dst_00 = *(uchar ***)&(this->parent).field_0x80;
  dst = *(byte **)&(this->parent).field_0x84;
  puVar9 = *(uchar **)(*(int *)&(this->parent).field_0xac + 0x14);
  (this->parent).mMaxGlyph = -1;
  src = (this->parent).mpResFONT + 1;
  uVar8 = 0;
  do {
    if (((this->parent).mpResFONT)->mBlockNum <= uVar8) {
      return;
    }
    iVar3 = *(int *)src->mMagic;
    if (iVar3 == 0x4d415031) {
      copy_bytes(dst,(byte *)src,*(int *)&src->field_0x4);
      *(byte **)((int)(this->parent).mpMAP1 + iVar5) = dst;
      uVar1 = *(ushort *)(*(int *)((int)(this->parent).mpMAP1 + iVar5) + 10);
      if (uVar1 < (ushort)(this->parent).mMaxGlyph) {
        (this->parent).mMaxGlyph = uVar1;
      }
      dst = dst + *(int *)&src->field_0x4;
      iVar5 = iVar5 + 4;
    }
    else {
      if (iVar3 < 0x4d415031) {
        if (iVar3 == 0x494e4631) {
          copy_bytes((byte *)(this->parent).mpINF1,(byte *)src,0x20);
          uVar4 = (uint)(ushort)((this->parent).mpINF1)->mFontEncoding;
          if (2 < uVar4) {
            uVar2 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar2,"JUTCacheFont.cpp",0x1bf,"u < suAboutEncoding_");
            m_Do_printf::OSPanic("JUTCacheFont.cpp",0x1bf,&DAT_8036bd9c);
          }
          (this->parent).mpEncodingFunc = (undefined *)(&JUTResFont::saoAboutEncoding_ + uVar4);
        }
        else {
          if ((0x494e4630 < iVar3) || (iVar3 != 0x474c5931)) goto LAB_802c0d8c;
          copy_bytes((byte *)dst_00,(byte *)src,0x20);
          iVar3 = JKRAram::mainRamToAram
                            ((JKRAram *)(src + 1),puVar9,*(int *)&src->field_0x4 - 0x20,0,0,0,
                             (JKRHeap *)&DAT_ffffffff,in_r10);
          if (iVar3 == 0) {
            m_Do_printf::OSPanic("JUTCacheFont.cpp",0x1dc,"Cannot alloc ARAM area.");
          }
          *dst_00 = puVar9;
          if (*(uchar **)&(this->parent).field_0x88 < dst_00[4]) {
            *(uchar **)&(this->parent).field_0x88 = dst_00[4];
          }
          *(uchar ***)((int)(this->parent).mpGlyph + iVar6) = dst_00;
          puVar9 = puVar9 + *(int *)&src->field_0x4 + -0x20;
          iVar6 = iVar6 + 4;
          dst_00 = dst_00 + 8;
        }
      }
      else {
        if (iVar3 == 0x57494431) {
          copy_bytes(dst_01,(byte *)src,*(int *)&src->field_0x4);
          *(byte **)((int)(this->parent).mpWidth + iVar7) = dst_01;
          dst_01 = dst_01 + *(int *)&src->field_0x4;
          iVar7 = iVar7 + 4;
        }
        else {
LAB_802c0d8c:
          JUtility::JUTReportConsole("Unknown data block\n");
        }
      }
    }
    src = (ResFONT *)(src->mMagic + *(int *)&src->field_0x4);
    uVar8 = uVar8 + 1;
  } while( true );
}


/* __thiscall JUTCacheFont::determineBlankPage(void) */

undefined4 * __thiscall JUTCacheFont::determineBlankPage(JUTCacheFont *this)

{
  undefined4 *puVar1;
  undefined4 *__name;
  
  __name = *(undefined4 **)&(this->parent).field_0xa4;
  if (__name == (undefined4 *)0x0) {
    puVar1 = *(undefined4 **)&(this->parent).field_0xa0;
    do {
      __name = puVar1;
      if (__name == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
      puVar1 = (undefined4 *)*__name;
    } while (*(short *)((int)__name + 0x1e) != 0);
    unlink(this,(char *)__name);
    *(int *)&(this->parent).field_0xb4 = *(int *)&(this->parent).field_0xb4 + 1;
  }
  else {
    *(undefined4 *)&(this->parent).field_0xa4 = __name[1];
    if ((undefined4 *)__name[1] == (undefined4 *)0x0) {
      *(undefined4 *)&(this->parent).field_0xa8 = 0;
    }
    else {
      *(undefined4 *)__name[1] = 0;
    }
  }
  return __name;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JUTCacheFont::getGlyphFromAram(JUTCacheFont::TGlyphCacheInfo *,
                                             JUTCacheFont::TCachePage *,
                                             int *,
                                             int *) */

void __thiscall
JUTCacheFont::getGlyphFromAram
          (JUTCacheFont *this,TGlyphCacheInfo *param_1,TCachePage *param_2,int *param_3,int *param_4
          )

{
  uint uVar1;
  ushort uVar2;
  ulong uVar3;
  int iVar4;
  int iVar5;
  double dVar6;
  ulong *in_stack_ffffffe8;
  
  copy_bytes((byte *)param_2,(byte *)param_1,0x20);
  prepend(this,(TGlyphCacheInfo *)param_2);
  iVar4 = (uint)*(ushort *)(param_2 + 0x16) * (uint)*(ushort *)(param_2 + 0x18);
  iVar5 = *param_3 / iVar4;
  *(short *)(param_2 + 8) = *(short *)(param_2 + 8) + (short)(iVar5 * iVar4);
  uVar1 = (uint)*(ushort *)(param_2 + 8) + iVar4 + -1 & 0xffff;
  uVar2 = (ushort)uVar1;
  if (*(ushort *)(param_2 + 10) < uVar1) {
    uVar2 = *(ushort *)(param_2 + 10);
  }
  *(ushort *)(param_2 + 10) = uVar2;
  *param_4 = iVar5;
  *param_3 = *param_3 - iVar5 * iVar4;
  iVar4 = JKRAram::aramToMainRam
                    ((JKRAram *)(*(int *)param_1 + (int)*(uchar **)(param_2 + 0x10) * iVar5),
                     (ulong)(param_2 + 0x40),*(uchar **)(param_2 + 0x10),0,0,0,
                     (JKRHeap *)&DAT_ffffffff,0,in_stack_ffffffe8);
  if (iVar4 == 0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"JUTCacheFont.cpp",0x26f,"result");
    m_Do_printf::OSPanic("JUTCacheFont.cpp",0x26f,&DAT_8036bd9c);
  }
  gx::GXInitTexObj((GXTexObj *)(param_2 + 0x20),param_2 + 0x40,(uint)*(ushort *)(param_2 + 0x1a),
                   (uint)*(ushort *)(param_2 + 0x1c),(_GXTexFmt)*(undefined2 *)(param_2 + 0x14),
                   GX_CLAMP,GX_CLAMP,false);
  dVar6 = (double)JUtility::_688;
  gx::GXInitTexObjLOD(dVar6,dVar6,dVar6,param_2 + 0x20,1,1,0,0,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JUTCacheFont::loadImage(int,
                                      _GXTexMapID) */

void __thiscall JUTCacheFont::loadImage(JUTCacheFont *this,int param_1,_GXTexMapID param_2)

{
  TGlyphCacheInfo *__name;
  int local_18 [3];
  
  local_18[0] = param_1;
  __name = (TGlyphCacheInfo *)loadCache_char_subroutine(this,local_18,false);
  if (__name != (TGlyphCacheInfo *)0x0) {
    *(uint *)&(this->parent).field_0x1c =
         (uint)*(ushort *)(__name + 0xc) *
         (local_18[0] -
         (local_18[0] / (int)(uint)*(ushort *)(__name + 0x16)) * (uint)*(ushort *)(__name + 0x16));
    *(uint *)&(this->parent).field_0x20 =
         (uint)*(ushort *)(__name + 0xe) * (local_18[0] / (int)(uint)*(ushort *)(__name + 0x16));
    gx::GXLoadTexObj((GXTexObj *)(__name + 0x20),param_2);
    if (*(int *)&(this->parent).field_0x8c == 1) {
      unlink(this,(char *)__name);
      prepend(this,__name);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JUTCacheFont::loadCache_char_subroutine(int *,
                                                      bool) */

TCachePage * __thiscall
JUTCacheFont::loadCache_char_subroutine(JUTCacheFont *this,int *param_1,bool param_2)

{
  uint uVar1;
  int iVar2;
  TCachePage *pTVar3;
  int iVar4;
  int iVar5;
  TCachePage *pTVar6;
  uint uVar7;
  int iVar8;
  int local_28 [5];
  
  for (pTVar6 = *(TCachePage **)&(this->parent).field_0x9c; pTVar3 = (TCachePage *)0x0,
      pTVar6 != (TCachePage *)0x0; pTVar6 = *(TCachePage **)(pTVar6 + 4)) {
    iVar8 = *param_1;
    if (((int)(uint)*(ushort *)(pTVar6 + 8) <= iVar8) &&
       (iVar8 <= (int)(uint)*(ushort *)(pTVar6 + 10))) {
      *param_1 = iVar8 - (uint)*(ushort *)(pTVar6 + 8);
      pTVar3 = pTVar6;
      break;
    }
  }
  if (pTVar3 == (TCachePage *)0x0) {
    iVar8 = 0;
    iVar2 = 0;
    for (uVar1 = (uint)(this->parent).mNumGlyph; uVar1 != 0; uVar1 = uVar1 - 1) {
      iVar4 = *(int *)((int)(this->parent).mpGlyph + iVar2);
      uVar7 = (uint)*(ushort *)(iVar4 + 8);
      iVar5 = *param_1;
      if (((int)uVar7 <= iVar5) && (iVar5 <= (int)(uint)*(ushort *)(iVar4 + 10))) {
        *param_1 = iVar5 - uVar7;
        break;
      }
      iVar8 = iVar8 + 1;
      iVar2 = iVar2 + 4;
    }
    if ((int)(uint)(this->parent).mNumGlyph <= iVar8) {
      return (TCachePage *)0x0;
    }
    pTVar3 = (TCachePage *)determineBlankPage(this);
    if (pTVar3 == (TCachePage *)0x0) {
      return (TCachePage *)0x0;
    }
    getGlyphFromAram(this,*(TGlyphCacheInfo **)((int)(this->parent).mpGlyph + iVar8 * 4),pTVar3,
                     param_1,local_28);
    *(int *)&(this->parent).field_0x44 = local_28[0];
    *(short *)&(this->parent).field_0x66 = (short)iVar8;
  }
  if (param_2 != false) {
    *(undefined2 *)(pTVar3 + 0x1e) = 1;
  }
  return pTVar3;
}


/* __thiscall JUTCacheFont::invalidiateAllCache(void) */

void __thiscall JUTCacheFont::invalidiateAllCache(JUTCacheFont *this)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  piVar2 = *(int **)&(this->parent).field_0x90;
  for (uVar3 = 0; uVar3 < *(uint *)&(this->parent).field_0x98; uVar3 = uVar3 + 1) {
    if (uVar3 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (int)piVar2 - *(int *)&(this->parent).field_0x94;
    }
    *piVar2 = iVar1;
    if (uVar3 == *(int *)&(this->parent).field_0x98 - 1U) {
      iVar1 = 0;
    }
    else {
      iVar1 = (int)piVar2 + *(int *)&(this->parent).field_0x94;
    }
    piVar2[1] = iVar1;
    piVar2 = (int *)((int)piVar2 + *(int *)&(this->parent).field_0x94);
  }
  *(int *)&(this->parent).field_0xa8 = (int)piVar2 - *(int *)&(this->parent).field_0x94;
  *(undefined4 *)&(this->parent).field_0xa4 = *(undefined4 *)&(this->parent).field_0x90;
  *(undefined4 *)&(this->parent).field_0x9c = 0;
  *(undefined4 *)&(this->parent).field_0xa0 = 0;
  return;
}


/* __thiscall JUTCacheFont::unlink(JUTCacheFont::TGlyphCacheInfo *) */

int __thiscall JUTCacheFont::unlink(JUTCacheFont *this,char *__name)

{
  if (*(int *)__name == 0) {
    *(undefined4 *)&(this->parent).field_0x9c = *(undefined4 *)(__name + 4);
  }
  else {
    *(undefined4 *)(*(int *)__name + 4) = *(undefined4 *)(__name + 4);
  }
  if (*(undefined4 **)(__name + 4) == (undefined4 *)0x0) {
    *(undefined4 *)&(this->parent).field_0xa0 = *(undefined4 *)__name;
    return (int)this;
  }
  **(undefined4 **)(__name + 4) = *(undefined4 *)__name;
  return (int)this;
}


/* __thiscall JUTCacheFont::prepend(JUTCacheFont::TGlyphCacheInfo *) */

void __thiscall JUTCacheFont::prepend(JUTCacheFont *this,TGlyphCacheInfo *param_1)

{
  TGlyphCacheInfo **ppTVar1;
  
  ppTVar1 = *(TGlyphCacheInfo ***)&(this->parent).field_0x9c;
  *(TGlyphCacheInfo **)&(this->parent).field_0x9c = param_1;
  *(undefined4 *)param_1 = 0;
  *(TGlyphCacheInfo ***)(param_1 + 4) = ppTVar1;
  if (ppTVar1 == (TGlyphCacheInfo **)0x0) {
    *(TGlyphCacheInfo **)&(this->parent).field_0xa0 = param_1;
    return;
  }
  *ppTVar1 = param_1;
  return;
}

