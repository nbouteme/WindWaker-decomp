#include <JAudio/JASCalc.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <MSL_C.PPCEABI.bare.H/s_sin.h>
#include <JAudio/JASCalc.h>
#include <os/OSCache.h>
#include <JASystem/Calc.h>


namespace JASystem {
undefined1 Calc;
undefined1 Calc;

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8027a9a0) */
/* WARNING: Removing unreachable block (ram,0x8027a990) */
/* WARNING: Removing unreachable block (ram,0x8027a988) */
/* WARNING: Removing unreachable block (ram,0x8027a998) */
/* WARNING: Removing unreachable block (ram,0x8027a9a8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Calc::initSinfT(void) */

void __thiscall Calc::initSinfT(Calc *this)

{
  ulong uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f27;
  double dVar7;
  undefined8 in_f28;
  double dVar8;
  undefined8 in_f29;
  double dVar9;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar10;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
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
  _JASC_SINTABLE = JKernel::operator_new__(0x404,JAudio::JASDram,0);
  if (_JASC_SINTABLE == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASCalc.cpp",0x31,"JASC_SINTABLE != 0");
    m_Do_printf::OSPanic("JASCalc.cpp",0x31,&DAT_80366cd7);
  }
  _JASC_DOL2TABLE = JKernel::operator_new__(0x404,JAudio::JASDram,0);
  if (_JASC_DOL2TABLE == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASCalc.cpp",0x33,"JASC_DOL2TABLE != 0");
    m_Do_printf::OSPanic("JASCalc.cpp",0x33,&DAT_80366cd7);
  }
  uVar2 = 0;
  iVar3 = 0;
  dVar9 = (double)JAudio::_796;
  dVar7 = (double)JAudio::_797;
  dVar8 = JAudio::_801;
  do {
    dVar5 = MSL_C.PPCEABI.bare.H::sin
                      ((double)(float)((double)(float)(dVar9 * (double)(float)((double)CONCAT44(
                                                  0x43300000,uVar2) - dVar8)) * dVar7));
    *(float *)(_JASC_SINTABLE + iVar3) = (float)dVar5;
    uVar2 = uVar2 + 1;
    iVar3 = iVar3 + 4;
  } while (uVar2 < 0x101);
  uVar2 = 0;
  iVar3 = 0;
  dVar7 = (double)JAudio::_796;
  dVar9 = (double)JAudio::_798;
  dVar5 = (double)JAudio::_799;
  dVar10 = (double)JAudio::_797;
  dVar8 = JAudio::_801;
  do {
    dVar6 = MSL_C.PPCEABI.bare.H::sin
                      ((double)(float)(dVar7 * (double)(float)(dVar9 + (double)(float)((double)(
                                                  float)(dVar5 * (double)(float)((double)CONCAT44(
                                                  0x43300000,uVar2) - dVar8)) * dVar10))));
    *(float *)(_JASC_DOL2TABLE + iVar3) = (float)dVar6;
    uVar2 = uVar2 + 1;
    iVar3 = iVar3 + 4;
  } while (uVar2 < 0x101);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  __psq_l0(auStack72,uVar4);
  __psq_l1(auStack72,uVar4);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Calc::sinfT(float) */

double __thiscall Calc::sinfT(Calc *this,float param_1)

{
  return (double)*(float *)(_JASC_SINTABLE + (int)(JAudio::_806 * param_1) * 4);
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Calc::sinfDolby2(float) */

double __thiscall Calc::sinfDolby2(Calc *this,float param_1)

{
  return (double)*(float *)(_JASC_DOL2TABLE + (int)(JAudio::_806 * param_1) * 4);
}


/* __thiscall Calc::imixcopy(short const *,
                                       short const *,
                                       short *,
                                       long) */

void __thiscall
Calc::imixcopy(Calc *this,short *param_1,short *param_2,short *param_3,long param_4)

{
  if ((int)param_3 < 1) {
    return;
  }
  do {
    *param_2 = *(short *)this;
    param_2[1] = *param_1;
    param_2 = param_2 + 2;
    this = (Calc *)((int)this + 2);
    param_1 = param_1 + 1;
    param_3 = (short *)((int)param_3 + -1);
  } while (param_3 != (short *)0x0);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall Calc::bcopyfast(unsigned long const *,
                                        unsigned long *,
                                        unsigned long) */

void __thiscall Calc::bcopyfast(Calc *this,ulong *param_1,ulong *param_2,ulong param_3)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  uint uVar4;
  
  if (((uint)this & 3) != 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASCalc.cpp",0x118,"(reinterpret_cast<u32>(src) & 0x03) == 0");
    m_Do_printf::OSPanic("JASCalc.cpp",0x118,&DAT_80366cd7);
  }
  if (((uint)param_1 & 3) != 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASCalc.cpp",0x119,"(reinterpret_cast<u32>(dest) & 0x03) == 0");
    m_Do_printf::OSPanic("JASCalc.cpp",0x119,&DAT_80366cd7);
  }
  if (((uint)param_2 & 0xf) != 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASCalc.cpp",0x11a,"(size & 0x0f) == 0");
    m_Do_printf::OSPanic("JASCalc.cpp",0x11a,&DAT_80366cd7);
  }
  for (uVar4 = (uint)param_2 >> 4; uVar4 != 0; uVar4 = uVar4 - 1) {
    uVar1 = *(ulong *)((int)this + 4);
    uVar2 = *(ulong *)((int)this + 8);
    uVar3 = *(ulong *)((int)this + 0xc);
    *param_1 = *(ulong *)this;
    param_1[1] = uVar1;
    param_1[2] = uVar2;
    param_1[3] = uVar3;
    param_1 = param_1 + 4;
    this = (Calc *)((int)this + 0x10);
  }
  return;
}


/* __thiscall Calc::bcopy(void const *,
                                    void *,
                                    unsigned long) */

void __thiscall Calc::bcopy(Calc *this,void *__src,void *__dest,size_t __n)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)this & 3;
  uVar2 = (uint)__src & 3;
  if ((uVar3 == uVar2) && (((uint)__dest & 0xf) == 0)) {
    bcopyfast(this,(ulong *)__src,(ulong *)__dest,uVar2);
  }
  else {
    if ((uVar3 == uVar2) && (&DAT_00000010 <= __dest)) {
      if (uVar3 != 0) {
        for (uVar3 = 4 - uVar3 & 0xff; (uVar3 & 0xff) != 0; uVar3 = uVar3 - 1) {
          *(Calc *)__src = *this;
          __src = (void *)((int)__src + 1);
          __dest = (void *)((int)__dest + -1);
          this = (Calc *)((int)this + 1);
        }
      }
      uVar3 = (uint)__dest >> 2;
      if (&DAT_00000003 < __dest) {
        do {
          *(undefined4 *)__src = *(undefined4 *)this;
          __src = (void *)((int)__src + 4);
          __dest = (void *)((int)__dest + -4);
          this = (Calc *)((int)this + 4);
          uVar3 = uVar3 - 1;
        } while (uVar3 != 0);
      }
      bVar1 = (undefined *)__dest != (undefined *)0x0;
      if (bVar1) {
        while (bVar1) {
          *(Calc *)__src = *this;
          __src = (void *)((int)__src + 1);
          this = (Calc *)((int)this + 1);
          __dest = (void *)((int)__dest + -1);
          bVar1 = (undefined *)__dest != (undefined *)0x0;
        }
      }
    }
    else {
      if (__dest != (void *)0x0) {
        do {
          *(Calc *)__src = *this;
          __src = (void *)((int)__src + 1);
          this = this + 1;
          __dest = (void *)((int)__dest + -1);
        } while (__dest != (void *)0x0);
      }
    }
  }
  return;
}


/* __thiscall Calc::bzerofast(void *,
                                        unsigned long) */

void __thiscall Calc::bzerofast(Calc *this,void *param_1,ulong param_2)

{
  ulong uVar1;
  uint uVar2;
  
  if (((uint)this & 3) != 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASCalc.cpp",0x183,"(reinterpret_cast<u32>(dest) & 0x03) == 0");
    m_Do_printf::OSPanic("JASCalc.cpp",0x183,&DAT_80366cd7);
  }
  if (((uint)param_1 & 0xf) != 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASCalc.cpp",0x184,"(size & 0x0f) == 0");
    m_Do_printf::OSPanic("JASCalc.cpp",0x184,&DAT_80366cd7);
  }
  for (uVar2 = (uint)param_1 >> 4; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined4 *)this = 0;
    *(undefined4 *)((int)this + 4) = 0;
    *(undefined4 *)((int)this + 8) = 0;
    *(undefined4 *)((int)this + 0xc) = 0;
    this = (Calc *)((int)this + 0x10);
  }
  return;
}


/* __thiscall Calc::bzero(void *,
                                    unsigned long) */

void __thiscall Calc::bzero(Calc *this,void *__s,size_t __n)

{
  bool bVar1;
  uint uVar2;
  
  if ((((uint)__s & 0x1f) == 0) && (((uint)this & 0x1f) == 0)) {
    os::DCZeroRange();
  }
  else {
    uVar2 = (uint)this & 3;
    if ((((uint)__s & 0xf) == 0) && (uVar2 == 0)) {
      bzerofast(this,__s,0);
    }
    else {
      if (__s < &DAT_00000010) {
        if (__s != (void *)0x0) {
          do {
            *this = (Calc)0x0;
            this = this + 1;
            __s = (void *)((int)__s + -1);
          } while (__s != (void *)0x0);
        }
      }
      else {
        if (uVar2 != 0) {
          for (uVar2 = 4 - uVar2 & 0xff; (uVar2 & 0xff) != 0; uVar2 = uVar2 - 1) {
            *this = (Calc)0x0;
            this = (Calc *)((int)this + 1);
            __s = (void *)((int)__s + -1);
          }
        }
        uVar2 = (uint)__s >> 2;
        if (&DAT_00000003 < __s) {
          do {
            *(undefined4 *)this = 0;
            this = (Calc *)((int)this + 4);
            __s = (void *)((int)__s + -4);
            uVar2 = uVar2 - 1;
          } while (uVar2 != 0);
        }
        bVar1 = (undefined *)__s != (undefined *)0x0;
        if (bVar1) {
          while (bVar1) {
            *this = (Calc)0x0;
            this = (Calc *)((int)this + 1);
            __s = (void *)((int)__s + -1);
            bVar1 = (undefined *)__s != (undefined *)0x0;
          }
        }
      }
    }
  }
  return;
}

