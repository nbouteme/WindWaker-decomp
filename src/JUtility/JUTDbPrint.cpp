#include <JUtility/JUTDbPrint.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTDbPrint.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <J2DGraph/J2DOrthoGraph.h>
#include <JUtility/JUTFont.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <JUTDbPrint.h>

struct JUTDbPrint * JUTDbPrint;

/* __thiscall JUTDbPrint::JUTDbPrint(JUTFont *,
                                     JKRHeap *) */

void __thiscall JUTDbPrint::JUTDbPrint(JUTDbPrint *this,JUTFont *param_1,JKRHeap *param_2)

{
  JKRHeap *pJVar1;
  
  *(undefined4 *)(this + 8) = 0xffffffff;
  *(JUTFont **)(this + 4) = param_1;
  *(undefined4 *)this = 0;
  pJVar1 = JKRHeap::sCurrentHeap;
  if (param_2 != (JKRHeap *)0x0) {
    pJVar1 = param_2;
  }
  *(JKRHeap **)(this + 0x10) = pJVar1;
  this[8] = (JUTDbPrint)0xff;
  this[9] = (JUTDbPrint)0xff;
  this[10] = (JUTDbPrint)0xff;
  this[0xb] = (JUTDbPrint)0xff;
  this[0xc] = (JUTDbPrint)0x1;
  return;
}


namespace JUTDbPrint {

/* __thiscall start(JUTFont *,
                                JKRHeap *) */

JUTDbPrint * start(JUTFont *param_1,JKRHeap *param_2)

{
  JUTDbPrint *this;
  
  this = sDebugPrint;
  if (sDebugPrint == (JUTDbPrint *)0x0) {
    if (param_2 == (JKRHeap *)0x0) {
      param_2 = JKRHeap::sCurrentHeap;
    }
    this = (JUTDbPrint *)JKernel::operator_new(0x14);
    if (this != (JUTDbPrint *)0x0) {
      JUTDbPrint(this,param_1,param_2);
    }
  }
  sDebugPrint = this;
  return sDebugPrint;
}

}

/* __thiscall JUTDbPrint::changeFont(JUTFont *) */

undefined4 __thiscall JUTDbPrint::changeFont(JUTDbPrint *this,JUTFont *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(this + 4);
  if (param_1 != (JUTFont *)0x0) {
    *(JUTFont **)(this + 4) = param_1;
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall JUTDbPrint::enter(int,
                                int,
                                int,
                                char const *,
                                int) */

void __thiscall
JUTDbPrint::enter(JUTDbPrint *this,int param_1,int param_2,int param_3,char *param_4,int param_5)

{
  undefined4 *puVar1;
  
  if ((0 < param_5) &&
     (puVar1 = (undefined4 *)JKRHeap::alloc(param_5 + 0x10,-4,*(JKRHeap **)(this + 0x10)),
     puVar1 != (undefined4 *)0x0)) {
    *(short *)(puVar1 + 1) = (short)param_1;
    *(short *)((int)puVar1 + 6) = (short)param_2;
    *(short *)(puVar1 + 2) = (short)param_3;
    *(short *)((int)puVar1 + 10) = (short)param_5;
    MSL_C.PPCEABI.bare.H::strcpy((char *)(puVar1 + 3),param_4);
    *puVar1 = *(undefined4 *)this;
    *(undefined4 **)this = puVar1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JUTDbPrint::flush(void) */

void __thiscall JUTDbPrint::flush(JUTDbPrint *this)

{
  short sVar1;
  JUTDbPrint **ppJVar2;
  JUTDbPrint **__ptr;
  JUTDbPrint **ppJVar3;
  _GXColor local_e8;
  J2DOrthoGraph local_e4;
  
  ppJVar2 = *(JUTDbPrint ***)this;
  if ((*(int *)(this + 4) != 0) && (ppJVar2 != (JUTDbPrint **)0x0)) {
    J2DOrthoGraph::J2DOrthoGraph
              (&local_e4,JUtility::_743,JUtility::_743,JUtility::_744,JUtility::_745,JUtility::_746,
               JUtility::_747);
    J2DOrthoGraph::setPort(&local_e4);
    (**(code **)(**(int **)(this + 4) + 0xc))();
    local_e8 = *(_GXColor *)(this + 8);
    JUTFont::setCharColor(*(JUTFont **)(this + 4),&local_e8);
    ppJVar3 = (JUTDbPrint **)this;
    while (__ptr = ppJVar2, __ptr != (JUTDbPrint **)0x0) {
      if (this[0xc] != (JUTDbPrint)0x0) {
        drawString(this,(int)*(short *)(__ptr + 1),(int)*(short *)((int)__ptr + 6),
                   (int)*(short *)((int)__ptr + 10),(uchar *)(__ptr + 3));
      }
      sVar1 = *(short *)(__ptr + 2);
      *(short *)(__ptr + 2) = sVar1 + -1;
      if ((short)(sVar1 + -1) < 1) {
        ppJVar2 = (JUTDbPrint **)*__ptr;
        JKRHeap::free(__ptr,*(JKRHeap **)(this + 0x10));
        *ppJVar3 = (JUTDbPrint *)ppJVar2;
      }
      else {
        ppJVar2 = (JUTDbPrint **)*__ptr;
        ppJVar3 = __ptr;
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x802c35d4) */
/* __thiscall JUTDbPrint::drawString(int,
                                     int,
                                     int,
                                     unsigned char const *) */

void __thiscall
JUTDbPrint::drawString(JUTDbPrint *this,int param_1,int param_2,int param_3,uchar *param_4)

{
  uint uVar1;
  JUTFont *this_00;
  undefined4 uVar2;
  undefined8 in_f31;
  double dVar3;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  this_00 = *(JUTFont **)(this + 4);
  uVar1 = (*(code *)this_00->vtbl->getHeight)(this_00);
  dVar3 = (double)(float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - JUtility::_760);
  uVar1 = (*(code *)this_00->vtbl->getWidth)(this_00);
  JUTFont::drawString_size_scale
            (this_00,(float)((double)CONCAT44(0x43300000,param_1 ^ 0x80000000) - JUtility::_760),
             (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - JUtility::_760),
             (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - JUtility::_760),(float)dVar3,
             (char *)param_4,param_3,true);
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


namespace JUtility {

/* __stdcall JUTReport(int,
                       int,
                       char const *,
                       ...) */

void JUTReport(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        ,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8
                        ,int param_9,int param_10,char *param_11,undefined4 param_12,
                        undefined4 param_13,undefined4 param_14,undefined4 param_15,
                        undefined4 param_16)

{
  int iVar1;
  int iVar2;
  byte in_cr1;
  int local_178;
  int local_174;
  char *local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined8 local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined4 local_118;
  undefined *local_114;
  int *local_110;
  char acStack268 [260];
  
  if ((bool)(in_cr1 >> 1 & 1)) {
    local_158 = param_1;
    local_150 = param_2;
    local_148 = param_3;
    local_140 = param_4;
    local_138 = param_5;
    local_130 = param_6;
    local_128 = param_7;
    local_120 = param_8;
  }
  local_118 = 0x3000000;
  local_114 = &stack0x00000008;
  local_110 = &local_178;
  local_178 = param_9;
  local_174 = param_10;
  local_170 = param_11;
  local_16c = param_12;
  local_168 = param_13;
  local_164 = param_14;
  local_160 = param_15;
  local_15c = param_16;
  iVar1 = MSL_C.PPCEABI.bare.H::vsnprintf(acStack268,0x100,param_11,&local_118);
  if (-1 < iVar1) {
    iVar2 = 0xff;
    if (iVar1 < 0x100) {
      iVar2 = iVar1;
    }
    ::JUTDbPrint::enter(::JUTDbPrint::sDebugPrint,param_9,param_10,1,acStack268,iVar2);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall JUTReport(int,
                       int,
                       int,
                       char const *,
                       ...) */

void JUTReport(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        ,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8
                        ,int param_9,int param_10,int param_11,char *param_12,undefined4 param_13,
                        undefined4 param_14,undefined4 param_15,undefined4 param_16)

{
  int iVar1;
  int iVar2;
  byte in_cr1;
  int local_188;
  int local_184;
  int local_180;
  char *local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined8 local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined4 local_128;
  undefined *local_124;
  int *local_120;
  char acStack284 [272];
  
  if ((bool)(in_cr1 >> 1 & 1)) {
    local_168 = param_1;
    local_160 = param_2;
    local_158 = param_3;
    local_150 = param_4;
    local_148 = param_5;
    local_140 = param_6;
    local_138 = param_7;
    local_130 = param_8;
  }
  local_128 = 0x4000000;
  local_124 = &stack0x00000008;
  local_120 = &local_188;
  local_188 = param_9;
  local_184 = param_10;
  local_180 = param_11;
  local_17c = param_12;
  local_178 = param_13;
  local_174 = param_14;
  local_170 = param_15;
  local_16c = param_16;
  iVar1 = MSL_C.PPCEABI.bare.H::vsnprintf(acStack284,0x100,param_12,&local_128);
  if (-1 < iVar1) {
    iVar2 = 0xff;
    if (iVar1 < 0x100) {
      iVar2 = iVar1;
    }
    ::JUTDbPrint::enter(::JUTDbPrint::sDebugPrint,param_9,param_10,param_11,acStack284,iVar2);
  }
  return;
}

