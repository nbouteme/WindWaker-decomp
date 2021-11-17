#include <JAudio/JASBasicInst.h>
#include <JAudio/JASBasicInst.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JAudio/JASBank.h>
#include <JAudio/JASCalc.h>
#include <Demangler/JASystem/TInst.h>
#include <JASystem/TBasicInst.h>
#include <JASystem/TBasicInst/TKeymap.h>


namespace JASystem {

/* __thiscall TBasicInst::TBasicInst(void) */

void __thiscall TBasicInst::TBasicInst(TBasicInst *this)

{
  float fVar1;
  
  *(undefined1 **)this = &TInst::__vt;
  *(undefined1 **)this = &__vt;
  fVar1 = JAudio::_650;
  *(float *)(this + 4) = JAudio::_650;
  *(float *)(this + 8) = fVar1;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  return;
}


/* __thiscall TBasicInst::~TBasicInst(void) */

void __thiscall TBasicInst::_TBasicInst(TBasicInst *this)

{
  short in_r4;
  
  if (this != (TBasicInst *)0x0) {
    *(undefined1 **)this = &__vt;
    Runtime.PPCEABI.H::__destroy_new_array(*(undefined4 *)(this + 0x20),TKeymap::_TKeymap);
    JKernel::operator_delete__(*(undefined4 *)(this + 0xc));
    JKernel::operator_delete__(*(undefined4 *)(this + 0x14));
    if (this != (TBasicInst *)0x0) {
      *(undefined1 **)this = &TInst::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x802849c4) */
/* __thiscall TBasicInst::getParam(int,
                                             int,
                                             TInstParam *) const */

undefined4 __thiscall
TBasicInst::getParam(TBasicInst *this,int param_1,int param_2,TInstParam *param_3)

{
  byte bVar1;
  int iVar2;
  ulong uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  double dVar9;
  
  iVar8 = 0;
  *param_3 = (TInstParam)0x0;
  param_3[0x38] = (TInstParam)0x0;
  *(undefined4 *)(param_3 + 8) = *(undefined4 *)(this + 0x14);
  *(undefined4 *)(param_3 + 0xc) = *(undefined4 *)(this + 0x18);
  *(float *)(param_3 + 0x10) = *(float *)(param_3 + 0x10) * *(float *)(this + 4);
  *(float *)(param_3 + 0x14) = *(float *)(param_3 + 0x14) * *(float *)(this + 8);
  for (uVar7 = 0; uVar7 < *(uint *)(this + 0x10); uVar7 = uVar7 + 1) {
    piVar6 = *(int **)(*(int *)(this + 0xc) + iVar8);
    if (piVar6 != (int *)0x0) {
      dVar9 = (double)(**(code **)(*piVar6 + 8))(piVar6,param_1,param_2);
      bVar1 = *(byte *)(piVar6 + 1);
      if (bVar1 == 2) {
        *(float *)(param_3 + 0x2c) =
             (float)((double)*(float *)(param_3 + 0x2c) + (dVar9 - JAudio::_711));
      }
      else {
        if (bVar1 < 2) {
          if (bVar1 == 0) {
            *(float *)(param_3 + 0x18) = (float)((double)*(float *)(param_3 + 0x18) * dVar9);
          }
          else {
            *(float *)(param_3 + 0x1c) = (float)((double)*(float *)(param_3 + 0x1c) * dVar9);
          }
        }
        else {
          if (bVar1 == 4) {
            *(float *)(param_3 + 0x34) = (float)((double)*(float *)(param_3 + 0x34) + dVar9);
          }
          else {
            if (bVar1 < 4) {
              *(float *)(param_3 + 0x30) = (float)((double)*(float *)(param_3 + 0x30) + dVar9);
            }
            else {
              uVar3 = JUTAssertion::getSDevice();
              JUTAssertion::showAssert(uVar3,"JASBasicInst.cpp",0x5d,"0");
              m_Do_printf::OSPanic("JASBasicInst.cpp",0x5d,&DAT_80367b43);
            }
          }
        }
      }
    }
    iVar8 = iVar8 + 4;
  }
  iVar8 = 0;
  iVar4 = 0;
  iVar2 = *(int *)(this + 0x1c);
  do {
    piVar6 = (int *)0x0;
    if (iVar2 == 0) {
LAB_80284ac0:
      if (piVar6 != (int *)0x0) {
        for (uVar7 = 0; uVar7 < (uint)piVar6[1]; uVar7 = uVar7 + 1) {
          piVar5 = (int *)TKeymap::getVeloRegion((TKeymap *)piVar6,uVar7);
          if (param_2 <= *piVar5) {
            *(float *)(param_3 + 0x10) = *(float *)(param_3 + 0x10) * (float)piVar5[2];
            *(float *)(param_3 + 0x14) = *(float *)(param_3 + 0x14) * (float)piVar5[3];
            *(int *)(param_3 + 4) = piVar5[1];
            return 1;
          }
        }
      }
      return 0;
    }
    piVar6 = (int *)(*(int *)(this + 0x20) + iVar4);
    if (param_1 <= *piVar6) {
      *(int *)(param_3 + 0x3c) = iVar8;
      goto LAB_80284ac0;
    }
    iVar8 = iVar8 + 1;
    iVar4 = iVar4 + 0xc;
    iVar2 = iVar2 + -1;
  } while( true );
}


/* __thiscall TBasicInst::getKeymapIndex(int) const */

int __thiscall TBasicInst::getKeymapIndex(TBasicInst *this,int param_1)

{
  return param_1;
}


/* __thiscall TBasicInst::setKeyRegionCount(unsigned long) */

void __thiscall TBasicInst::setKeyRegionCount(TBasicInst *this,ulong param_1)

{
  TBank *this_00;
  undefined4 uVar1;
  ulong uVar2;
  
  this_00 = (TBank *)Runtime.PPCEABI.H::__destroy_new_array
                               (*(undefined4 *)(this + 0x20),TKeymap::_TKeymap);
  uVar1 = TBank::getCurrentHeap(this_00);
  uVar1 = JKernel::operator_new__(param_1 * 0xc + 0x10,uVar1,0);
  uVar1 = Runtime.PPCEABI.H::__construct_new_array
                    (uVar1,TKeymap::TKeymap,TKeymap::_TKeymap,0xc,param_1);
  *(undefined4 *)(this + 0x20) = uVar1;
  if (*(int *)(this + 0x20) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASBasicInst.cpp",0x8c,"mKeymap != 0");
    m_Do_printf::OSPanic("JASBasicInst.cpp",0x8c,&DAT_80367b43);
  }
  *(ulong *)(this + 0x1c) = param_1;
  return;
}


/* __thiscall TBasicInst::setEffectCount(unsigned long) */

void __thiscall TBasicInst::setEffectCount(TBasicInst *this,ulong param_1)

{
  TBank *this_00;
  undefined4 uVar1;
  ulong uVar2;
  undefined *__n;
  
  this_00 = (TBank *)JKernel::operator_delete__(*(undefined4 *)(this + 0xc));
  *(ulong *)(this + 0x10) = param_1;
  if (param_1 == 0) {
    *(undefined4 *)(this + 0xc) = 0;
  }
  else {
    uVar1 = TBank::getCurrentHeap(this_00);
    __n = (undefined *)0x0;
    uVar1 = JKernel::operator_new__(param_1 << 2,uVar1);
    *(undefined4 *)(this + 0xc) = uVar1;
    if (*(int *)(this + 0xc) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"JASBasicInst.cpp",0x9d,"mEffect != 0");
      __n = &DAT_80367b43;
      m_Do_printf::OSPanic("JASBasicInst.cpp",0x9d);
    }
    Calc::bzero(*(Calc **)(this + 0xc),(void *)(param_1 << 2),(size_t)__n);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TBasicInst::setEffect(int,
                                              TInstEffect *) */

void __thiscall TBasicInst::setEffect(TBasicInst *this,int param_1,TInstEffect *param_2)

{
  ulong uVar1;
  
  if (*(uint *)(this + 0x10) <= (uint)param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASBasicInst.cpp",0xa4,"index < mEffectCount");
    m_Do_printf::OSPanic("JASBasicInst.cpp",0xa4,&DAT_80367b43);
  }
  if (param_1 < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASBasicInst.cpp",0xa5,"index >= 0");
    m_Do_printf::OSPanic("JASBasicInst.cpp",0xa5,&DAT_80367b43);
  }
  *(TInstEffect **)(*(int *)(this + 0xc) + param_1 * 4) = param_2;
  return;
}


/* __thiscall TBasicInst::setOscCount(unsigned long) */

void __thiscall TBasicInst::setOscCount(TBasicInst *this,ulong param_1)

{
  TBank *this_00;
  undefined4 uVar1;
  ulong uVar2;
  undefined *__n;
  
  this_00 = (TBank *)JKernel::operator_delete__(*(undefined4 *)(this + 0x14));
  *(ulong *)(this + 0x18) = param_1;
  if (param_1 == 0) {
    *(undefined4 *)(this + 0x14) = 0;
  }
  else {
    uVar1 = TBank::getCurrentHeap(this_00);
    __n = (undefined *)0x0;
    uVar1 = JKernel::operator_new__(param_1 << 2,uVar1);
    *(undefined4 *)(this + 0x14) = uVar1;
    if (*(int *)(this + 0x14) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"JASBasicInst.cpp",0xc1,"mOsc != 0");
      __n = &DAT_80367b43;
      m_Do_printf::OSPanic("JASBasicInst.cpp",0xc1);
    }
    Calc::bzero(*(Calc **)(this + 0x14),(void *)(param_1 << 2),(size_t)__n);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TBasicInst::setOsc(int,
                                           TOscillator::Osc_ *) */

void __thiscall TBasicInst::setOsc(TBasicInst *this,int param_1,Osc_ *param_2)

{
  ulong uVar1;
  
  if (*(uint *)(this + 0x18) <= (uint)param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASBasicInst.cpp",199,"index < mOscCount");
    m_Do_printf::OSPanic("JASBasicInst.cpp",199,&DAT_80367b43);
  }
  if (param_1 < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASBasicInst.cpp",200,"index >= 0");
    m_Do_printf::OSPanic("JASBasicInst.cpp",200,&DAT_80367b43);
  }
  *(Osc_ **)(*(int *)(this + 0x14) + param_1 * 4) = param_2;
  return;
}


/* __thiscall TBasicInst::getKeyRegion(int) */

int __thiscall TBasicInst::getKeyRegion(TBasicInst *this,int param_1)

{
  ulong uVar1;
  int iVar2;
  
  if (param_1 < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASBasicInst.cpp",0xd9,"index >= 0");
    m_Do_printf::OSPanic("JASBasicInst.cpp",0xd9,&DAT_80367b43);
  }
  if ((uint)param_1 < *(uint *)(this + 0x1c)) {
    iVar2 = *(int *)(this + 0x20) + param_1 * 0xc;
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


namespace TBasicInst {

/* __thiscall TKeymap::~TKeymap(void) */

void __thiscall TKeymap::_TKeymap(TKeymap *this)

{
  short in_r4;
  
  if (this != (TKeymap *)0x0) {
    JKernel::operator_delete__(*(undefined4 *)(this + 8));
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TKeymap::setVeloRegionCount(unsigned long) */

void __thiscall TKeymap::setVeloRegionCount(TKeymap *this,ulong param_1)

{
  TBank *this_00;
  undefined4 uVar1;
  ulong uVar2;
  
  this_00 = (TBank *)JKernel::operator_delete__(*(undefined4 *)(this + 8));
  uVar1 = TBank::getCurrentHeap(this_00);
  uVar1 = JKernel::operator_new__(param_1 << 4,uVar1,0);
  *(undefined4 *)(this + 8) = uVar1;
  if (*(int *)(this + 8) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASBasicInst.cpp",0xf4,"mVelomap != 0");
    m_Do_printf::OSPanic("JASBasicInst.cpp",0xf4,&DAT_80367b43);
  }
  *(ulong *)(this + 4) = param_1;
  return;
}


/* __thiscall TKeymap::getVeloRegion(int) */

int __thiscall TKeymap::getVeloRegion(TKeymap *this,int param_1)

{
  ulong uVar1;
  int iVar2;
  
  if (param_1 < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASBasicInst.cpp",0xfc,"index >= 0");
    m_Do_printf::OSPanic("JASBasicInst.cpp",0xfc,&DAT_80367b43);
  }
  if ((uint)param_1 < *(uint *)(this + 4)) {
    iVar2 = *(int *)(this + 8) + param_1 * 0x10;
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


/* __thiscall TKeymap::getVeloRegion(int) const */

int __thiscall TKeymap::getVeloRegion(TKeymap *this,int param_1)

{
  ulong uVar1;
  int iVar2;
  
  if (param_1 < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASBasicInst.cpp",0x105,"index >= 0");
    m_Do_printf::OSPanic("JASBasicInst.cpp",0x105,&DAT_80367b43);
  }
  if ((uint)param_1 < *(uint *)(this + 4)) {
    iVar2 = *(int *)(this + 8) + param_1 * 0x10;
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}

}

/* __thiscall TInst::~TInst(void) */

void __thiscall TInst::_TInst(TInst *this)

{
  short in_r4;
  
  if ((this != (TInst *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace TBasicInst {

/* __thiscall TKeymap::TKeymap(void) */

void __thiscall TKeymap::TKeymap(TKeymap *this)

{
  *(undefined4 *)this = 0xffffffff;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}

}

/* __thiscall TBasicInst::getType(void) const */

undefined4 __thiscall TBasicInst::getType(TBasicInst *this)

{
  return 0x42534943;
}

