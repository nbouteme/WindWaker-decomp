#include <JUtility/JUTDirectPrint.h>
#include <JUtility/JUTDirectPrint.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <os/OSCache.h>
#include <Demangler/JUTDirectPrint.h>


namespace JUTDirectPrint {
undefined1 sDirectPrint;
}

/* __thiscall JUTDirectPrint::JUTDirectPrint(void) */

void __thiscall JUTDirectPrint::JUTDirectPrint(JUTDirectPrint *this)

{
  changeFrameBuffer(this,(void *)0x0,0,0);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTDirectPrint::start(void) */

void __thiscall JUTDirectPrint::start(JUTDirectPrint *this)

{
  JUTDirectPrint *this_00;
  
  this_00 = _sDirectPrint;
  if ((_sDirectPrint == (JUTDirectPrint *)0x0) &&
     (this_00 = (JUTDirectPrint *)JKernel::operator_new(0x18), this_00 != (JUTDirectPrint *)0x0)) {
    JUTDirectPrint(this_00);
  }
  _sDirectPrint = this_00;
  return;
}


/* __thiscall JUTDirectPrint::erase(int,
                                    int,
                                    int,
                                    int) */

void __thiscall
JUTDirectPrint::erase(JUTDirectPrint *this,int param_1,int param_2,int param_3,int param_4)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)this == 0) {
    return;
  }
  if (400 < *(ushort *)(this + 4)) {
    param_1 = param_1 << 1;
    param_3 = param_3 << 1;
  }
  if (300 < *(ushort *)(this + 6)) {
    param_2 = param_2 << 1;
    param_4 = param_4 << 1;
  }
  puVar1 = (undefined2 *)
           (*(int *)(this + 0x14) + (uint)*(ushort *)(this + 8) * param_2 * 2 + param_1 * 2);
  for (iVar2 = 0; iVar2 < param_4; iVar2 = iVar2 + 1) {
    iVar3 = param_3;
    if (0 < param_3) {
      do {
        *puVar1 = 0x1080;
        puVar1 = puVar1 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    puVar1 = puVar1 + ((uint)*(ushort *)(this + 8) - param_3);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JUTDirectPrint::drawChar(int,
                                       int,
                                       int) */

void __thiscall JUTDirectPrint::drawChar(JUTDirectPrint *this,int param_1,int param_2,int param_3)

{
  ushort uVar1;
  undefined2 uVar3;
  int iVar2;
  undefined1 *puVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  
  iVar6 = param_3;
  if (99 < param_3) {
    iVar6 = param_3 + -100;
  }
  puVar4 = &sFontData2;
  if (param_3 < 100) {
    puVar4 = &sFontData;
  }
  piVar5 = (int *)(puVar4 + (iVar6 / 5) * 0x1c);
  iVar8 = 2 - (uint)(*(ushort *)(this + 4) < 400);
  iVar7 = 2 - (uint)(*(ushort *)(this + 6) < 300);
  iVar9 = *(int *)(this + 0x14) +
          iVar7 * (uint)*(ushort *)(this + 8) * param_2 * 2 + param_1 * iVar8 * 2;
  iVar10 = 0;
  do {
    uVar13 = *piVar5 << (iVar6 % 5) * 6;
    iVar12 = 0;
    piVar5 = piVar5 + 1;
    do {
      uVar3 = 0x80;
      if ((uVar13 & 0x80000000) != 0) {
        uVar3 = 0xeb80;
      }
      for (iVar11 = 0; iVar11 < iVar7; iVar11 = iVar11 + 1) {
        uVar1 = *(ushort *)(this + 8);
        iVar2 = 0;
        iVar14 = iVar8;
        if (0 < iVar8) {
          do {
            *(undefined2 *)(iVar9 + (uint)uVar1 * iVar11 * 2 + iVar2) = uVar3;
            iVar2 = iVar2 + 2;
            iVar14 = iVar14 + -1;
          } while (iVar14 != 0);
        }
      }
      uVar13 = uVar13 << 1;
      iVar9 = iVar9 + iVar8 * 2;
      iVar12 = iVar12 + 1;
    } while (iVar12 < 6);
    iVar9 = iVar9 + ((uint)*(ushort *)(this + 8) * iVar7 + iVar8 * -6) * 2;
    iVar10 = iVar10 + 1;
  } while (iVar10 < 7);
  return;
}


/* __thiscall JUTDirectPrint::changeFrameBuffer(void *,
                                                unsigned short,
                                                unsigned short) */

void __thiscall
JUTDirectPrint::changeFrameBuffer(JUTDirectPrint *this,void *param_1,ushort param_2,ushort param_3)

{
  *(void **)this = param_1;
  *(void **)(this + 0x14) = param_1;
  *(ushort *)(this + 4) = param_2;
  *(ushort *)(this + 6) = param_3;
  *(ushort *)(this + 8) = param_2 + 0xf & 0xfff0;
  *(uint *)(this + 0xc) = (uint)*(ushort *)(this + 8) * (uint)*(ushort *)(this + 6) * 2;
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall JUTDirectPrint::printSub(unsigned short,
                                       unsigned short,
                                       char const *,
                                       std::__tag_va_List *,
                                       bool) */

void __thiscall
JUTDirectPrint::printSub
          (JUTDirectPrint *this,ushort param_1,ushort param_2,char *param_3,__tag_va_List *param_4,
          bool param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  byte local_128 [264];
  
  uVar4 = (uint)param_2;
  if (*(int *)(this + 0x14) != 0) {
    iVar1 = MSL_C.PPCEABI.bare.H::vsnprintf((char *)local_128,0x100,param_3,param_4);
    if (0 < iVar1) {
      if (param_5 != false) {
        erase(this,param_1 - 6,param_2 - 3,(iVar1 + 2) * 6,0xd);
      }
      pbVar5 = local_128;
      uVar3 = (uint)param_1;
      for (; 0 < iVar1; iVar1 = iVar1 + -1) {
        uVar2 = (uint)(byte)(&sAsciiTable)[*pbVar5 & 0x7f];
        if (uVar2 == 0xfe) {
          uVar4 = uVar4 + 7;
          uVar3 = (uint)param_1;
        }
        else {
          if (uVar2 == 0xfd) {
            uVar3 = ((uVar3 & 0xffff) + 0x30) -
                    (int)(((uVar3 & 0xffff) - (uint)param_1) + 0x2f) % 0x30 & 0xffff;
          }
          else {
            if (uVar2 != 0xff) {
              drawChar(this,uVar3 & 0xffff,uVar4 & 0xffff,uVar2);
            }
            uVar3 = uVar3 + 6;
          }
        }
        pbVar5 = pbVar5 + 1;
      }
    }
    os::DCFlushRange(*(undefined4 *)(this + 0x14),*(undefined4 *)(this + 0xc));
  }
  return;
}


/* __thiscall JUTDirectPrint::drawString(unsigned short,
                                         unsigned short,
                                         char *) */

void __thiscall
JUTDirectPrint::drawString(JUTDirectPrint *this,ushort param_1,ushort param_2,char *param_3)

{
  drawString_f(this,param_1,param_2,"%s",(___)param_3);
  return;
}


/* __thiscall JUTDirectPrint::drawString_f(unsigned short,
                                           unsigned short,
                                           char const *,
                                           ...) */

void __thiscall
JUTDirectPrint::drawString_f
          (JUTDirectPrint *this,ushort param_1,ushort param_2,char *param_3,___ param_4)

{
  undefined2 in_register_00000010;
  undefined2 in_register_00000014;
  JUTDirectPrint *local_78;
  undefined4 local_74;
  undefined4 local_70;
  char *local_6c;
  ___ local_68;
  undefined4 local_18;
  undefined *local_14;
  JUTDirectPrint **local_10;
  
  local_70 = CONCAT22(in_register_00000014,param_2);
  local_74 = CONCAT22(in_register_00000010,param_1);
  if (*(int *)(this + 0x14) != 0) {
    local_18 = 0x4000000;
    local_14 = &stack0x00000008;
    local_10 = &local_78;
    local_78 = this;
    local_6c = param_3;
    local_68 = param_4;
    printSub(this,param_1,param_2,param_3,(__tag_va_List *)&local_18,false);
  }
  return;
}

