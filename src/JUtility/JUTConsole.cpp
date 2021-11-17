#include <JUtility/JUTConsole.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JUtility/JUTConsole.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRDisposer.h>
#include <J2DGraph/J2DOrthoGraph.h>
#include <JUtility/JUTFont.h>
#include <JUtility/JUTDirectPrint.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <JGadget/linklist.h>
#include <os/OSInterrupt.h>
#include <vi/vi.h>
#include <JUTConsoleManager.h>
#include <JUTConsole.h>

struct JUTConsoleManager * JUTConsoleManager;

namespace JUtility {
undefined4 sReportConsole;
undefined4 sWarningConsole;
}

namespace JUTConsole {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall create(unsigned int,
                                 unsigned int,
                                 JKRHeap *) */

JUTConsole * create(uint param_1,uint param_2,JKRHeap *param_3)

{
  JUTConsoleManager *this;
  ulong uVar1;
  JUTConsole *this_00;
  JUTConsole *this_01;
  char *pcVar2;
  
  this = JUTConsoleManager::sManager;
  pcVar2 = (char *)param_3;
  if (JUTConsoleManager::sManager == (JUTConsoleManager *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JUTConsole.cpp",0x21,"pManager != 0");
    pcVar2 = "Halt";
    m_Do_printf::OSPanic("JUTConsole.cpp",0x21);
  }
  uVar1 = getObjectSizeFromBufferSize((JUTConsole *)param_1,param_2,(uint)pcVar2);
  this_00 = (JUTConsole *)JKRHeap::alloc(uVar1,0,param_3);
  this_01 = this_00;
  if (this_00 != (JUTConsole *)0x0) {
    JUTConsole(this_00,param_1,param_2,true);
  }
  *(JUTConsole **)(this_01 + 0x28) = this_00 + 0x68;
  clear(this_01);
  JUTConsoleManager::appendConsole(this,this_01);
  return this_01;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall create(unsigned int,
                                 void *,
                                 unsigned long) */

JUTConsole * create(uint param_1,void *buffer,ulong param_3)

{
  ulong uVar1;
  uint uVar2;
  JUTConsole *this;
  char *pcVar3;
  JUTConsoleManager *pManager;
  
  pManager = JUTConsoleManager::sManager;
  pcVar3 = (char *)param_3;
  if (JUTConsoleManager::sManager == (JUTConsoleManager *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JUTConsole.cpp",0x3b,"pManager != 0");
    pcVar3 = "Halt";
    m_Do_printf::OSPanic("JUTConsole.cpp",0x3b);
  }
  if (((uint)buffer & 3) != 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JUTConsole.cpp",0x3e,"( (u32)buffer & 0x3 ) == 0");
    pcVar3 = "Halt";
    m_Do_printf::OSPanic("JUTConsole.cpp",0x3e);
  }
  uVar2 = getLineFromObjectSize((JUTConsole *)param_3,param_1,(uint)pcVar3);
  this = (JUTConsole *)buffer;
  if (buffer != (void *)0x0) {
    JUTConsole((JUTConsole *)buffer,param_1,uVar2,false);
  }
  *(int *)(this + 0x28) = (int)buffer + 0x68;
  clear(this);
  JUTConsoleManager::appendConsole(pManager,this);
  return this;
}

}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JUTConsole::JUTConsole(unsigned int,
                                     unsigned int,
                                     bool) */

void __thiscall JUTConsole::JUTConsole(JUTConsole *this,uint param_1,uint param_2,bool param_3)

{
  JKRDisposer::JKRDisposer((JKRDisposer *)this);
  *(undefined1 **)this = &__vt;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x5c) = 0xffffffff;
  *(undefined4 *)(this + 0x60) = 0xffffffff;
  this[0x2c] = (JUTConsole)param_3;
  *(uint *)(this + 0x20) = param_1;
  *(uint *)(this + 0x24) = param_2;
  *(undefined4 *)(this + 0x40) = 0x1e;
  *(undefined4 *)(this + 0x44) = 0x32;
  *(undefined4 *)(this + 0x48) = 0x14;
  if (*(uint *)(this + 0x24) < *(uint *)(this + 0x48)) {
    *(uint *)(this + 0x48) = *(uint *)(this + 0x24);
  }
  *(undefined4 *)(this + 0x4c) = 0;
  this[100] = (JUTConsole)0x1;
  this[0x65] = (JUTConsole)0x0;
  this[0x66] = (JUTConsole)0x0;
  *(undefined4 *)(this + 0x58) = 1;
  this[0x5c] = (JUTConsole)0x0;
  this[0x5d] = (JUTConsole)0x0;
  this[0x5e] = (JUTConsole)0x0;
  this[0x5f] = (JUTConsole)0x64;
  this[0x60] = (JUTConsole)0x0;
  this[0x61] = (JUTConsole)0x0;
  this[0x62] = (JUTConsole)0x0;
  this[99] = (JUTConsole)0xe6;
  return;
}


/* __thiscall JUTConsole::~JUTConsole(void) */

void __thiscall JUTConsole::_JUTConsole(JUTConsole *this)

{
  ulong uVar1;
  short in_r4;
  
  if (this != (JUTConsole *)0x0) {
    *(undefined1 **)this = &__vt;
    if (JUTConsoleManager::sManager == (JUTConsoleManager *)0x0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"JUTConsole.cpp",0x96,"JUTConsoleManager::getManager()");
      m_Do_printf::OSPanic("JUTConsole.cpp",0x96,"Halt");
    }
    JUTConsoleManager::removeConsole(JUTConsoleManager::sManager,this);
    JKRDisposer::_JKRDisposer((JKRDisposer *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JUTConsole::getObjectSizeFromBufferSize(unsigned int,
                                                      unsigned int) */

int __thiscall JUTConsole::getObjectSizeFromBufferSize(JUTConsole *this,uint param_1,uint param_2)

{
  return (int)(this + 2) * param_1 + 0x68;
}


/* __thiscall JUTConsole::getLineFromObjectSize(unsigned long,
                                                unsigned int) */

uint __thiscall JUTConsole::getLineFromObjectSize(JUTConsole *this,ulong param_1,uint param_2)

{
  return (uint)(this + -0x68) / (param_1 + 2);
}


/* __thiscall JUTConsole::clear(void) */

void __thiscall JUTConsole::clear(JUTConsole *this)

{
  uint uVar1;
  
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  for (uVar1 = 0; uVar1 < *(uint *)(this + 0x24); uVar1 = uVar1 + 1) {
    *(undefined *)(*(int *)(this + 0x28) + (*(int *)(this + 0x20) + 2) * uVar1) = 0;
  }
  **(undefined **)(this + 0x28) = 0xff;
  *(undefined *)(*(int *)(this + 0x28) + 1) = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x802cabf4) */
/* WARNING: Removing unreachable block (ram,0x802cabe4) */
/* WARNING: Removing unreachable block (ram,0x802cabdc) */
/* WARNING: Removing unreachable block (ram,0x802cabec) */
/* WARNING: Removing unreachable block (ram,0x802cabfc) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTConsole::doDraw(JUTConsole::EConsoleType) const */

void __thiscall JUTConsole::doDraw(JUTConsole *this,EConsoleType param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  size_t sVar3;
  int iVar4;
  JUTFont *this_00;
  uint uVar5;
  char *__s;
  undefined4 uVar6;
  undefined8 in_f27;
  double dVar7;
  undefined8 in_f28;
  double dVar8;
  undefined8 in_f29;
  double dVar9;
  undefined8 in_f30;
  double dVar10;
  undefined8 in_f31;
  double dVar11;
  _GXColor local_284;
  undefined4 local_280;
  _GXColor local_27c;
  undefined4 local_278;
  _GXColor local_274;
  undefined4 local_270;
  _GXColor local_26c;
  undefined4 local_268;
  J2DOrthoGraph local_264;
  J2DOrthoGraph local_190;
  undefined4 local_b8;
  uint uStack180;
  undefined4 local_b0;
  uint uStack172;
  longlong local_a8;
  undefined4 local_a0;
  uint uStack156;
  undefined4 local_98;
  undefined4 uStack148;
  longlong local_90;
  undefined4 local_88;
  uint uStack132;
  double local_80;
  double local_78;
  undefined4 local_70;
  uint uStack108;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar6 = 0;
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
  if ((this[100] != (JUTConsole)0x0) &&
     (((*(int *)(this + 0x4c) != 0 || (param_1 == 2)) &&
      (uStack108 = *(uint *)(this + 0x48), uStack108 != 0)))) {
    uVar1 = countLeadingZeros(param_1);
    dVar11 = (double)(JUtility::_2427 + *(float *)(this + 0x54));
    if (param_1 == 2) {
      local_70 = 0x43300000;
      iVar4 = (int)(dVar11 * (double)(float)((double)CONCAT44(0x43300000,uStack108) -
                                            JUtility::_2436));
      local_78 = (double)(longlong)iVar4;
      JUTDirectPrint::erase
                (_sDirectPrint,*(int *)(this + 0x40) + -3,*(int *)(this + 0x44) + -2,
                 *(int *)(this + 0x20) * 6 + 6,iVar4 + 4);
    }
    else {
      if (JUTVideo::sManager == (JUTVideo *)0x0) {
        J2DOrthoGraph::J2DOrthoGraph
                  (&local_190,JUtility::_2428,JUtility::_2428,JUtility::_2429,JUtility::_2430,
                   JUtility::_2431,JUtility::_2432);
        J2DOrthoGraph::setPort(&local_190);
        local_190.parent.vtbl = (J2DGrafContext__vtable *)&J2DGrafContext::__vt;
      }
      else {
        uStack180 = (uint)(ushort)JUTVideo::sManager->mpRenderMode->field_0x4;
        local_b8 = 0x43300000;
        uStack172 = (uint)(ushort)JUTVideo::sManager->mpRenderMode->field_0x6;
        local_b0 = 0x43300000;
        J2DOrthoGraph::J2DOrthoGraph
                  (&local_264,JUtility::_2428,JUtility::_2428,
                   (float)((double)CONCAT44(0x43300000,uStack180) - JUtility::_2436),
                   (float)((double)CONCAT44(0x43300000,uStack172) - JUtility::_2436),JUtility::_2431
                   ,JUtility::_2432);
        J2DOrthoGraph::setPort(&local_264);
        local_264.parent.vtbl = (J2DGrafContext__vtable *)&J2DGrafContext::__vt;
      }
      if ((uVar1 >> 5 & 0xff) == 0) {
        puVar2 = (undefined4 *)(this + 0x5c);
      }
      else {
        puVar2 = (undefined4 *)(this + 0x60);
      }
      local_268 = *puVar2;
      uStack172 = *(int *)(this + 0x40) - 2U ^ 0x80000000;
      local_b0 = 0x43300000;
      uStack180 = *(uint *)(this + 0x44) ^ 0x80000000;
      local_b8 = 0x43300000;
      uStack156 = (uint)((double)(float)((double)CONCAT44(0x43300000,uStack180) - JUtility::_2438) -
                        dVar11);
      local_a8 = (longlong)(int)uStack156;
      uStack156 = uStack156 ^ 0x80000000;
      local_a0 = 0x43300000;
      uStack148 = *(undefined4 *)(this + 0x20);
      local_98 = 0x43300000;
      uStack132 = (uint)(JUtility::_2433 +
                        *(float *)(this + 0x50) *
                        (float)((double)CONCAT44(0x43300000,uStack148) - JUtility::_2436));
      local_90 = (longlong)(int)uStack132;
      uStack132 = uStack132 ^ 0x80000000;
      local_88 = 0x43300000;
      local_80 = (double)CONCAT44(0x43300000,*(undefined4 *)(this + 0x48));
      uStack108 = (uint)(dVar11 * (double)(float)(local_80 - JUtility::_2436));
      local_78 = (double)(longlong)(int)uStack108;
      uStack108 = uStack108 ^ 0x80000000;
      local_70 = 0x43300000;
      J2DGraph::J2DFillBox
                ((double)(float)((double)CONCAT44(0x43300000,uStack172) - JUtility::_2438),
                 (double)(float)((double)CONCAT44(0x43300000,uStack156) - JUtility::_2438),
                 (double)(float)((double)CONCAT44(0x43300000,uStack132) - JUtility::_2438),
                 (double)(float)((double)CONCAT44(0x43300000,uStack108) - JUtility::_2438),
                 &local_268);
      (**(code **)(**(int **)(this + 0x4c) + 0xc))();
      if ((uVar1 >> 5 & 0xff) == 0) {
        local_284 = (_GXColor)0xe6e6e6ff;
        JUTFont::setCharColor(*(JUTFont **)(this + 0x4c),&local_284);
      }
      else {
        iVar4 = *(int *)(this + 0x38) - *(int *)(this + 0x30);
        if (iVar4 < 0) {
          iVar4 = iVar4 + *(int *)(this + 0x24);
        }
        if ((iVar4 - *(int *)(this + 0x48)) + 1 < 1) {
          local_270 = 0xffffffff;
          local_26c = (_GXColor)0xffffffff;
          JUTFont::setCharColor(*(JUTFont **)(this + 0x4c),&local_26c);
        }
        else {
          if (*(int *)(this + 0x30) == *(int *)(this + 0x34)) {
            local_278 = 0xffe6e6ff;
            local_274 = (_GXColor)0xffe6e6ff;
            JUTFont::setCharColor(*(JUTFont **)(this + 0x4c),&local_274);
          }
          else {
            local_280 = 0xe6e6ffff;
            local_27c = (_GXColor)0xe6e6ffff;
            JUTFont::setCharColor(*(JUTFont **)(this + 0x4c),&local_27c);
          }
        }
      }
    }
    uVar1 = *(uint *)(this + 0x30);
    uVar5 = 0;
    while (__s = (char *)(*(int *)(this + 0x28) + (*(int *)(this + 0x20) + 2) * uVar1 + 1),
          __s[-1] != '\0') {
      if (param_1 == 2) {
        uStack108 = *(uint *)(this + 0x44) ^ 0x80000000;
        local_70 = 0x43300000;
        local_78 = (double)CONCAT44(0x43300000,uVar5 ^ 0x80000000);
        iVar4 = (int)((float)((double)CONCAT44(0x43300000,uStack108) - JUtility::_2438) +
                     (float)((double)(float)(local_78 - JUtility::_2438) * dVar11));
        local_80 = (double)(longlong)iVar4;
        JUTDirectPrint::drawString
                  (_sDirectPrint,(ushort)*(undefined4 *)(this + 0x40),(ushort)iVar4,__s);
      }
      else {
        dVar7 = (double)*(float *)(this + 0x54);
        dVar8 = (double)*(float *)(this + 0x50);
        uStack108 = *(uint *)(this + 0x44) ^ 0x80000000;
        local_70 = 0x43300000;
        local_78 = (double)CONCAT44(0x43300000,uVar5 ^ 0x80000000);
        dVar9 = (double)((float)((double)CONCAT44(0x43300000,uStack108) - JUtility::_2438) +
                        (float)((double)(float)(local_78 - JUtility::_2438) * dVar11));
        local_80 = (double)CONCAT44(0x43300000,*(uint *)(this + 0x40) ^ 0x80000000);
        dVar10 = (double)(float)(local_80 - JUtility::_2438);
        this_00 = *(JUTFont **)(this + 0x4c);
        sVar3 = MSL_C.PPCEABI.bare.H::strlen(__s);
        JUTFont::drawString_size_scale
                  (this_00,(float)dVar10,(float)dVar9,(float)dVar8,(float)dVar7,__s,sVar3,true);
      }
      uVar1 = uVar1 + 1 &
              ~-(uint)!CARRY4((uVar1 + 1) - *(uint *)(this + 0x24),
                              *(uint *)(this + 0x24) ^ 0x80000000);
      uVar5 = uVar5 + 1;
      if ((*(uint *)(this + 0x48) <= uVar5) || (uVar1 == *(uint *)(this + 0x34))) break;
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  __psq_l0(auStack40,uVar6);
  __psq_l1(auStack40,uVar6);
  __psq_l0(auStack56,uVar6);
  __psq_l1(auStack56,uVar6);
  __psq_l0(auStack72,uVar6);
  __psq_l1(auStack72,uVar6);
  return;
}


/* __thiscall JUTConsole::print_f(char const *,
                                  ...) */

void __thiscall JUTConsole::print_f(JUTConsole *this,char *param_1,___ param_2)

{
  JUTConsole *local_78;
  char *local_74;
  ___ local_70;
  undefined4 local_18;
  undefined *local_14;
  JUTConsole **local_10;
  
  local_18 = 0x2000000;
  local_14 = &stack0x00000008;
  local_10 = &local_78;
  local_78 = this;
  local_74 = param_1;
  local_70 = param_2;
  JUtility::JUTConsole_print_f_va_(this,param_1,&local_18);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JUTConsole::print(char const *) */

void __thiscall JUTConsole::print(JUTConsole *this,char *param_1)

{
  char cVar2;
  int iVar1;
  uint uVar3;
  char *pcVar4;
  
  if ((*(uint *)(this + 0x58) & 2) != 0) {
    m_Do_printf::OSReport(&DAT_8036c7ea);
  }
  if ((*(uint *)(this + 0x58) & 1) != 0) {
    pcVar4 = (char *)(*(int *)(this + 0x28) +
                      (*(int *)(this + 0x20) + 2) * *(int *)(this + 0x38) + 1 +
                     *(int *)(this + 0x3c));
    while ((cVar2 = *param_1, cVar2 != '\0' &&
           ((this[0x66] == (JUTConsole)0x0 ||
            (*(uint *)(this + 0x34) !=
             (*(int *)(this + 0x38) + 1U &
             ~-(uint)!CARRY4((*(int *)(this + 0x38) + 1U) - *(uint *)(this + 0x24),
                             *(uint *)(this + 0x24) ^ 0x80000000))))))) {
      if (cVar2 == '\n') {
        *(undefined4 *)(this + 0x3c) = *(undefined4 *)(this + 0x20);
        param_1 = param_1 + 1;
      }
      else {
        if (cVar2 == '\t') {
          param_1 = param_1 + 1;
          do {
            if (*(uint *)(this + 0x20) <= *(uint *)(this + 0x3c)) break;
            *pcVar4 = ' ';
            *(int *)(this + 0x3c) = *(int *)(this + 0x3c) + 1;
            uVar3 = *(int *)(this + 0x3c) >> 0x1f;
            pcVar4 = pcVar4 + 1;
          } while ((uVar3 * 8 | *(int *)(this + 0x3c) * 0x20000000 + uVar3 >> 0x1d) != uVar3);
        }
        else {
          if ((*(int **)(this + 0x4c) == (int *)0x0) ||
             (cVar2 = (**(code **)(**(int **)(this + 0x4c) + 0x40))(), cVar2 == '\0')) {
            *pcVar4 = *param_1;
            *(int *)(this + 0x3c) = *(int *)(this + 0x3c) + 1;
            param_1 = param_1 + 1;
            pcVar4 = pcVar4 + 1;
          }
          else {
            if (*(int *)(this + 0x3c) + 1U < *(uint *)(this + 0x20)) {
              *pcVar4 = *param_1;
              pcVar4[1] = param_1[1];
              *(int *)(this + 0x3c) = *(int *)(this + 0x3c) + 1;
              *(int *)(this + 0x3c) = *(int *)(this + 0x3c) + 1;
              param_1 = param_1 + 2;
              pcVar4 = pcVar4 + 2;
            }
            else {
              *pcVar4 = '\0';
              *(int *)(this + 0x3c) = *(int *)(this + 0x3c) + 1;
              pcVar4 = pcVar4 + 1;
            }
          }
        }
      }
      if (*(uint *)(this + 0x20) <= *(uint *)(this + 0x3c)) {
        *pcVar4 = '\0';
        *(uint *)(this + 0x38) =
             *(int *)(this + 0x38) + 1U &
             ~-(uint)!CARRY4((*(int *)(this + 0x38) + 1U) - *(uint *)(this + 0x24),
                             *(uint *)(this + 0x24) ^ 0x80000000);
        *(undefined4 *)(this + 0x3c) = 0;
        *(undefined *)(*(int *)(this + 0x28) + (*(int *)(this + 0x20) + 2) * *(int *)(this + 0x38))
             = 0xff;
        pcVar4 = (char *)(*(int *)(this + 0x28) +
                         (*(int *)(this + 0x20) + 2) * *(int *)(this + 0x38) + 1);
        *pcVar4 = '\0';
        iVar1 = *(int *)(this + 0x38) - *(int *)(this + 0x30);
        if (iVar1 < 0) {
          iVar1 = iVar1 + *(int *)(this + 0x24);
        }
        if (iVar1 == *(int *)(this + 0x48)) {
          uVar3 = *(int *)(this + 0x30) + 1;
          *(uint *)(this + 0x30) =
               uVar3 & ~-(uint)!CARRY4(uVar3 - *(uint *)(this + 0x24),
                                       *(uint *)(this + 0x24) ^ 0x80000000);
        }
        if (*(int *)(this + 0x38) == *(int *)(this + 0x34)) {
          uVar3 = *(int *)(this + 0x34) + 1;
          *(uint *)(this + 0x34) =
               uVar3 & ~-(uint)!CARRY4(uVar3 - *(uint *)(this + 0x24),
                                       *(uint *)(this + 0x24) ^ 0x80000000);
        }
        if (*(int *)(this + 0x38) == *(int *)(this + 0x30)) {
          uVar3 = *(int *)(this + 0x30) + 1;
          *(uint *)(this + 0x30) =
               uVar3 & ~-(uint)!CARRY4(uVar3 - *(uint *)(this + 0x24),
                                       *(uint *)(this + 0x24) ^ 0x80000000);
        }
      }
    }
    *pcVar4 = '\0';
  }
  return;
}


namespace JUtility {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */

void JUTConsole_print_f_va_(JUTConsole *param_1,char *param_2,__gnuc_va_list param_3)

{
  ulong uVar1;
  char acStack1048 [1036];
  
  if (param_1 == (JUTConsole *)0x0) {
    uVar1 = ::JUTAssertion::getSDevice();
    ::JUTAssertion::showAssert(uVar1,"JUTConsole.cpp",0x231,"console!=0");
    m_Do_printf::OSPanic("JUTConsole.cpp",0x231,"Halt");
  }
  MSL_C.PPCEABI.bare.H::vsnprintf(acStack1048,0x400,param_2,param_3);
  ::JUTConsole::print(param_1,acStack1048);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JUTConsole::dumpToTerminal(unsigned int) */

void __thiscall JUTConsole::dumpToTerminal(JUTConsole *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != 0) {
    uVar1 = *(uint *)(this + 0x34);
    if (param_1 != 0xffffffff) {
      uVar1 = *(uint *)(this + 0x38);
      if (param_1 != 0) {
        do {
          uVar2 = uVar1 - 1;
          if ((int)uVar2 < 0) {
            uVar2 = *(int *)(this + 0x24) - 1;
          }
        } while (((*(char *)(*(int *)(this + 0x28) + (*(int *)(this + 0x20) + 2) * uVar2) != '\0')
                 && (uVar1 = uVar2, uVar2 != *(uint *)(this + 0x34))) &&
                (param_1 = param_1 - 1, param_1 != 0));
      }
    }
    iVar4 = 0;
    m_Do_printf::OSReport("\n:::dump of console[%x]--------------------------------\n",this);
    do {
      iVar3 = *(int *)(this + 0x28) + (*(int *)(this + 0x20) + 2) * uVar1 + 1;
      if (*(char *)(iVar3 + -1) == '\0') break;
      if (this[0x65] == (JUTConsole)0x0) {
        m_Do_printf::OSReport(&DAT_8036c83c,iVar3);
      }
      else {
        m_Do_printf::OSReport("[%03d] %s\n",iVar4);
      }
      uVar1 = uVar1 + 1 &
              ~-(uint)!CARRY4((uVar1 + 1) - *(uint *)(this + 0x24),
                              *(uint *)(this + 0x24) ^ 0x80000000);
      iVar4 = iVar4 + 1;
    } while (uVar1 != *(uint *)(this + 0x34));
    m_Do_printf::OSReport(":::dump of console[%x] END----------------------------\n",this);
  }
  return;
}


/* __thiscall JUTConsole::scroll(int) */

void __thiscall JUTConsole::scroll(JUTConsole *this,int param_1)

{
  int iVar1;
  
  if (param_1 < 0) {
    iVar1 = *(int *)(this + 0x30) - *(int *)(this + 0x34);
    if (iVar1 < 0) {
      iVar1 = iVar1 + *(int *)(this + 0x24);
    }
    if (param_1 < -iVar1) {
      param_1 = -iVar1;
    }
  }
  else {
    if (0 < param_1) {
      iVar1 = *(int *)(this + 0x38) - *(int *)(this + 0x34);
      if (iVar1 < 0) {
        iVar1 = iVar1 + *(int *)(this + 0x24);
      }
      if (*(uint *)(this + 0x48) < iVar1 + 1U) {
        iVar1 = *(int *)(this + 0x38) - *(int *)(this + 0x30);
        if (iVar1 < 0) {
          iVar1 = iVar1 + *(int *)(this + 0x24);
        }
        iVar1 = (iVar1 - *(uint *)(this + 0x48)) + 1;
        if (iVar1 < param_1) {
          param_1 = iVar1;
        }
      }
      else {
        param_1 = 0;
      }
    }
  }
  *(int *)(this + 0x30) = *(int *)(this + 0x30) + param_1;
  if (*(int *)(this + 0x30) < 0) {
    *(int *)(this + 0x30) = *(int *)(this + 0x30) + *(int *)(this + 0x24);
  }
  if (*(uint *)(this + 0x24) <= *(uint *)(this + 0x30)) {
    *(uint *)(this + 0x30) = *(uint *)(this + 0x30) - *(uint *)(this + 0x24);
    return;
  }
  return;
}


/* __thiscall JUTConsole::getUsedLine(void) const */

int __thiscall JUTConsole::getUsedLine(JUTConsole *this)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x38) - *(int *)(this + 0x34);
  if (-1 < iVar1) {
    return iVar1;
  }
  return iVar1 + *(int *)(this + 0x24);
}


/* __thiscall JUTConsole::getLineOffset(void) const */

int __thiscall JUTConsole::getLineOffset(JUTConsole *this)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x30) - *(int *)(this + 0x34);
  if (-1 < iVar1) {
    return iVar1;
  }
  return iVar1 + *(int *)(this + 0x24);
}


/* __thiscall JUTConsoleManager::JUTConsoleManager(void) */

void __thiscall JUTConsoleManager::JUTConsoleManager(JUTConsoleManager *this)

{
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)this = 0;
  *(JUTConsoleManager **)(this + 4) = this + 4;
  *(JUTConsoleManager **)(this + 8) = this + 4;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  return;
}


namespace JUTConsoleManager {

/* __thiscall createManager(JKRHeap *) */

JUTConsoleManager * createManager(JKRHeap *param_1)

{
  ulong uVar1;
  JUTConsoleManager *this;
  
  if (sManager != (JUTConsoleManager *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JUTConsole.cpp",0x39a,"sManager == 0");
    m_Do_printf::OSPanic("JUTConsole.cpp",0x39a,"Halt");
  }
  if (param_1 == (JKRHeap *)0x0) {
    param_1 = JKRHeap::sCurrentHeap;
  }
  this = (JUTConsoleManager *)JKernel::operator_new(0x14,param_1,0);
  if (this != (JUTConsoleManager *)0x0) {
    JUTConsoleManager(this);
  }
  sManager = this;
  return this;
}

}

/* __thiscall JUTConsoleManager::appendConsole(JUTConsole *) */

void __thiscall JUTConsoleManager::appendConsole(JUTConsoleManager *this,JUTConsole *param_1)

{
  bool bVar1;
  uint uVar2;
  ulong uVar3;
  TNodeLinkList aTStack64 [4];
  JUTConsoleManager *local_3c;
  JUTConsoleManager *local_38;
  JUTConsoleManager *local_34;
  int local_30;
  JUTConsoleManager *local_2c;
  JUTConsoleManager *local_28;
  JUTConsoleManager *local_24;
  int local_20;
  int local_1c;
  JUTConsoleManager *local_18;
  JUTConsoleManager *local_14;
  int local_10;
  int local_c;
  
  bVar1 = false;
  if ((sManager != (JUTConsoleManager *)0x0) && (param_1 != (JUTConsole *)0x0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"JUTConsole.cpp",0x3bf,"sManager != 0 && console != 0");
    m_Do_printf::OSPanic("JUTConsole.cpp",0x3bf,"Halt");
  }
  local_28 = this + 4;
  local_24 = local_28;
  local_18 = local_28;
  local_14 = local_28;
  JGadget::TNodeLinkList::Find((TNodeLinkList *)&local_1c,(TLinkListNode *)this);
  local_20 = local_1c;
  local_10 = local_1c;
  local_c = local_1c;
  local_2c = local_14;
  local_30 = local_1c;
  uVar2 = countLeadingZeros((int)local_14 - local_1c);
  if ((uVar2 >> 5 & 0xff) == 0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar3,"JUTConsole.cpp",0x3c2,"soLink_.Find( console ) == soLink_.end()");
    m_Do_printf::OSPanic("JUTConsole.cpp",0x3c2,"Halt");
  }
  local_3c = this + 4;
  local_38 = local_3c;
  local_34 = local_3c;
  JGadget::TNodeLinkList::Insert(aTStack64,(iterator)this,(TLinkListNode *)&local_3c);
  if (*(int *)(this + 0xc) == 0) {
    *(JUTConsole **)(this + 0xc) = param_1;
  }
  return;
}


/* __thiscall JUTConsoleManager::removeConsole(JUTConsole *) */

void __thiscall JUTConsoleManager::removeConsole(JUTConsoleManager *this,JUTConsole *param_1)

{
  bool bVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  JUTConsole *pJVar5;
  int local_20;
  JUTConsoleManager *local_1c;
  int local_18;
  
  bVar1 = false;
  if ((sManager != (JUTConsoleManager *)0x0) && (param_1 != (JUTConsole *)0x0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"JUTConsole.cpp",0x3d6,"sManager != 0 && console != 0");
    m_Do_printf::OSPanic("JUTConsole.cpp",0x3d6,"Halt");
  }
  local_1c = this + 4;
  JGadget::TNodeLinkList::Find((TNodeLinkList *)&local_20,(TLinkListNode *)this);
  local_18 = local_20;
  uVar2 = countLeadingZeros((int)local_1c - local_20);
  uVar2 = countLeadingZeros(uVar2 >> 5 & 0xff);
  if ((uVar2 >> 5 & 0xff) == 0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar3,"JUTConsole.cpp",0x3d9,"soLink_.Find( console ) != soLink_.end()");
    m_Do_printf::OSPanic("JUTConsole.cpp",0x3d9,"Halt");
  }
  if (*(JUTConsole **)(this + 0xc) == param_1) {
    if (*(uint *)this < 2) {
      *(undefined4 *)(this + 0xc) = 0;
    }
    else {
      if (param_1 == (JUTConsole *)(*(int *)(this + 8) + -0x18)) {
        iVar4 = *(int *)(this + 4);
      }
      else {
        iVar4 = *(int *)(param_1 + 0x18);
      }
      *(int *)(this + 0xc) = iVar4 + -0x18;
    }
  }
  pJVar5 = (JUTConsole *)JUtility::JUTGetWarningConsole();
  if (pJVar5 == param_1) {
    JUtility::JUTSetWarningConsole(0);
  }
  pJVar5 = (JUTConsole *)JUtility::JUTGetReportConsole();
  if (pJVar5 == param_1) {
    JUtility::JUTSetReportConsole(0);
  }
  JGadget::TNodeLinkList::Remove((TNodeLinkList *)this,(TLinkListNode *)(param_1 + 0x18));
  return;
}


/* __thiscall JUTConsoleManager::draw(void) const */

void __thiscall JUTConsoleManager::draw(JUTConsoleManager *this)

{
  uint uVar1;
  undefined4 *local_c;
  
  local_c = *(undefined4 **)(this + 4);
  while( true ) {
    uVar1 = countLeadingZeros(this + (4 - (int)local_c));
    if ((uVar1 >> 5 & 0xff) != 0) break;
    if (local_c + -6 != *(undefined4 **)(this + 0xc)) {
      JUTConsole::doDraw((JUTConsole *)(local_c + -6),1);
    }
    local_c = (undefined4 *)*local_c;
  }
  if (*(JUTConsole **)(this + 0xc) != (JUTConsole *)0x0) {
    JUTConsole::doDraw(*(JUTConsole **)(this + 0xc),0);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JUTConsoleManager::drawDirect(bool) const */

void __thiscall JUTConsoleManager::drawDirect(JUTConsoleManager *this,bool param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(this + 0x10) != 0) {
    if (param_1 != false) {
      uVar1 = os::OSEnableInterrupts();
      iVar2 = vi::VIGetRetraceCount();
      do {
        iVar3 = vi::VIGetRetraceCount();
      } while (iVar2 == iVar3);
      os::OSRestoreInterrupts(uVar1);
    }
    JUTConsole::doDraw(*(JUTConsole **)(this + 0x10),2);
  }
  return;
}


/* __thiscall JUTConsoleManager::setDirectConsole(JUTConsole *) */

void __thiscall JUTConsoleManager::setDirectConsole(JUTConsoleManager *this,JUTConsole *param_1)

{
  if (*(JUTConsole **)(this + 0x10) != (JUTConsole *)0x0) {
    appendConsole(this,*(JUTConsole **)(this + 0x10));
  }
  if (param_1 != (JUTConsole *)0x0) {
    removeConsole(this,param_1);
  }
  *(JUTConsole **)(this + 0x10) = param_1;
  return;
}


namespace JUtility {

void JUTSetReportConsole(undefined4 param_1)

{
  sReportConsole = param_1;
  return;
}


undefined4 JUTGetReportConsole(void)

{
  return sReportConsole;
}


void JUTSetWarningConsole(undefined4 param_1)

{
  sWarningConsole = param_1;
  return;
}


undefined4 JUTGetWarningConsole(void)

{
  return sWarningConsole;
}


void JUTReportConsole_f_va(char *param_1,__gnuc_va_list param_2)

{
  int iVar1;
  JUTConsole *this;
  char acStack264 [256];
  
  iVar1 = JUTGetReportConsole();
  if (iVar1 == 0) {
    MSL_C.PPCEABI.bare.H::vsnprintf(acStack264,0x100,param_1,param_2);
    m_Do_printf::OSReport(&DAT_8036c7ea,acStack264);
  }
  else {
    iVar1 = JUTGetReportConsole();
    if ((*(uint *)(iVar1 + 0x58) & 3) != 0) {
      MSL_C.PPCEABI.bare.H::vsnprintf(acStack264,0x100,param_1,param_2);
      this = (JUTConsole *)JUTGetReportConsole();
      ::JUTConsole::print(this,acStack264);
    }
  }
  return;
}


void JUTReportConsole_f
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
               undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16)

{
  byte in_cr1;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  undefined *local_14;
  undefined4 *local_10;
  
  if ((bool)(in_cr1 >> 1 & 1)) {
    local_58 = param_1;
    local_50 = param_2;
    local_48 = param_3;
    local_40 = param_4;
    local_38 = param_5;
    local_30 = param_6;
    local_28 = param_7;
    local_20 = param_8;
  }
  local_18 = 0x1000000;
  local_14 = &stack0x00000008;
  local_10 = &local_78;
  local_78 = param_9;
  local_74 = param_10;
  local_70 = param_11;
  local_6c = param_12;
  local_68 = param_13;
  local_64 = param_14;
  local_60 = param_15;
  local_5c = param_16;
  JUTReportConsole_f_va(param_9,&local_18);
  return;
}


void JUTReportConsole(undefined4 param_1)

{
  JUTReportConsole_f(&DAT_8036c7ea,param_1);
  return;
}


void JUTWarningConsole_f_va(char *param_1,__gnuc_va_list param_2)

{
  int iVar1;
  JUTConsole *this;
  char acStack264 [256];
  
  iVar1 = JUTGetWarningConsole();
  if (iVar1 == 0) {
    MSL_C.PPCEABI.bare.H::vsnprintf(acStack264,0x100,param_1,param_2);
    m_Do_printf::OSReport(&DAT_8036c7ea,acStack264);
  }
  else {
    iVar1 = JUTGetWarningConsole();
    if ((*(uint *)(iVar1 + 0x58) & 3) != 0) {
      MSL_C.PPCEABI.bare.H::vsnprintf(acStack264,0x100,param_1,param_2);
      this = (JUTConsole *)JUTGetWarningConsole();
      ::JUTConsole::print(this,acStack264);
    }
  }
  return;
}


void JUTWarningConsole_f
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
               undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16)

{
  byte in_cr1;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  undefined *local_14;
  undefined4 *local_10;
  
  if ((bool)(in_cr1 >> 1 & 1)) {
    local_58 = param_1;
    local_50 = param_2;
    local_48 = param_3;
    local_40 = param_4;
    local_38 = param_5;
    local_30 = param_6;
    local_28 = param_7;
    local_20 = param_8;
  }
  local_18 = 0x1000000;
  local_14 = &stack0x00000008;
  local_10 = &local_78;
  local_78 = param_9;
  local_74 = param_10;
  local_70 = param_11;
  local_6c = param_12;
  local_68 = param_13;
  local_64 = param_14;
  local_60 = param_15;
  local_5c = param_16;
  JUTReportConsole_f_va(param_9,&local_18);
  return;
}


void JUTWarningConsole(undefined4 param_1)

{
  JUTReportConsole_f(&DAT_8036c7ea,param_1);
  return;
}

