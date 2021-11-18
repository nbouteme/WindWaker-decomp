#include <JAudio/JASDrumSet.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JKernel/JKRHeap.h>
#include <JAudio/JASBank.h>
#include <JAudio/JASCalc.h>
#include <JAudio/JASDrumSet.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JASystem/TDrumSet.h>
#include <JASystem/TDrumSet/TPerc.h>


namespace JASystem {
}

namespace JAudio {
undefined1 osc$650;
undefined4 oscp$651;
undefined1 init$652;
}

namespace JASystem {

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x80285340) */
/* __thiscall TDrumSet::getParam(int,
                                           int,
                                           TInstParam *) const */

undefined4 __thiscall
TDrumSet::getParam(TDrumSet *this,int param_1,int param_2,TInstParam *param_3)

{
  byte bVar1;
  ulong uVar2;
  int *piVar3;
  float fVar4;
  int iVar5;
  float *pfVar6;
  double dVar7;
  
  if (param_1 < 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASDrumSet.cpp",0x18,"key >= 0");
    m_Do_printf::OSPanic("JASDrumSet.cpp",0x18,&DAT_80367bc8);
  }
  if ((uint)param_1 < 0x80) {
    pfVar6 = (float *)(this + param_1 * 0x20 + 4);
    *param_3 = (TInstParam)0x0;
    param_3[0x38] = (TInstParam)0x1;
    *(float *)(param_3 + 0x10) = *(float *)(param_3 + 0x10) * *pfVar6;
    *(float *)(param_3 + 0x14) = *(float *)(param_3 + 0x14) * pfVar6[1];
    *(float *)(param_3 + 0x20) = pfVar6[2];
    *(undefined2 *)(param_3 + 0x3a) = *(undefined2 *)(pfVar6 + 3);
    JAudio::osc_650 = 0;
    DAT_803e91f4 = JAudio::_679;
    DAT_803e91f8 = 0;
    DAT_803e91fc = 0;
    DAT_803e9200 = JAudio::_679;
    DAT_803e9204 = JAudio::_680;
    if (JAudio::init_652 == '\0') {
      JAudio::oscp_651 = &JAudio::osc_650;
      JAudio::init_652 = '\x01';
    }
    *(undefined1 ***)(param_3 + 8) = &JAudio::oscp_651;
    *(undefined4 *)(param_3 + 0xc) = 1;
    iVar5 = 0;
    for (fVar4 = 0.0; (uint)fVar4 < (uint)pfVar6[5]; fVar4 = (float)((int)fVar4 + 1)) {
      piVar3 = *(int **)((int)pfVar6[4] + iVar5);
      if (piVar3 != (int *)0x0) {
        dVar7 = (double)(**(code **)(*piVar3 + 8))(piVar3,param_1,param_2);
        bVar1 = *(byte *)(piVar3 + 1);
        if (bVar1 == 2) {
          *(float *)(param_3 + 0x2c) =
               (float)((double)*(float *)(param_3 + 0x2c) + (dVar7 - JAudio::_681));
        }
        else {
          if (bVar1 < 2) {
            if (bVar1 == 0) {
              *(float *)(param_3 + 0x18) = (float)((double)*(float *)(param_3 + 0x18) * dVar7);
            }
            else {
              *(float *)(param_3 + 0x1c) = (float)((double)*(float *)(param_3 + 0x1c) * dVar7);
            }
          }
          else {
            if (bVar1 == 4) {
              *(float *)(param_3 + 0x34) = (float)((double)*(float *)(param_3 + 0x34) + dVar7);
            }
            else {
              if (bVar1 < 4) {
                *(float *)(param_3 + 0x30) = (float)((double)*(float *)(param_3 + 0x30) + dVar7);
              }
              else {
                uVar2 = JUTAssertion::getSDevice();
                JUTAssertion::showAssert(uVar2,"JASDrumSet.cpp",0x4d,"0");
                m_Do_printf::OSPanic("JASDrumSet.cpp",0x4d,&DAT_80367bc8);
              }
            }
          }
        }
      }
      iVar5 = iVar5 + 4;
    }
    iVar5 = 0;
    for (fVar4 = pfVar6[6]; fVar4 != 0.0; fVar4 = (float)((int)fVar4 + -1)) {
      piVar3 = (int *)((int)pfVar6[7] + iVar5);
      if (param_2 <= *piVar3) {
        *(float *)(param_3 + 0x10) = *(float *)(param_3 + 0x10) * (float)piVar3[2];
        *(float *)(param_3 + 0x14) = *(float *)(param_3 + 0x14) * (float)piVar3[3];
        *(int *)(param_3 + 4) = piVar3[1];
        return 1;
      }
      iVar5 = iVar5 + 0x10;
    }
  }
  else {
    m_Do_printf::OSReport("JASDrumSet: key %d >= sPercCount %d\n",param_1,0x80);
  }
  return 0;
}


/* __thiscall TDrumSet::getPerc(int) */

TDrumSet * __thiscall TDrumSet::getPerc(TDrumSet *this,int param_1)

{
  ulong uVar1;
  
  if (0x7f < (uint)param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASDrumSet.cpp",0x65,"index < sPercCount");
    m_Do_printf::OSPanic("JASDrumSet.cpp",0x65,&DAT_80367bc8);
  }
  if (param_1 < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASDrumSet.cpp",0x66,"index >= 0");
    m_Do_printf::OSPanic("JASDrumSet.cpp",0x66,&DAT_80367bc8);
  }
  return this + param_1 * 0x20 + 4;
}


namespace TDrumSet {

/* __thiscall TPerc::TPerc(void) */

void __thiscall TPerc::TPerc(TPerc *this)

{
  float fVar1;
  
  fVar1 = JAudio::_679;
  *(float *)this = JAudio::_679;
  *(float *)(this + 4) = fVar1;
  *(float *)(this + 8) = JAudio::_704;
  *(undefined2 *)(this + 0xc) = 1000;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  return;
}


/* __thiscall TPerc::~TPerc(void) */

void __thiscall TPerc::_TPerc(TPerc *this)

{
  short in_r4;
  
  if (this != (TPerc *)0x0) {
    JKernel::operator_delete__(*(undefined4 *)(this + 0x10));
    JKernel::operator_delete__(*(undefined4 *)(this + 0x1c));
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TPerc::setEffectCount(unsigned long) */

void __thiscall TPerc::setEffectCount(TPerc *this,ulong param_1)

{
  TBank *this_00;
  undefined4 uVar1;
  ulong uVar2;
  undefined *__n;
  
  this_00 = (TBank *)JKernel::operator_delete__(*(undefined4 *)(this + 0x10));
  *(ulong *)(this + 0x14) = param_1;
  if (param_1 == 0) {
    *(undefined4 *)(this + 0x10) = 0;
  }
  else {
    uVar1 = TBank::getCurrentHeap(this_00);
    __n = (undefined *)0x0;
    uVar1 = JKernel::operator_new__(param_1 << 2,uVar1);
    *(undefined4 *)(this + 0x10) = uVar1;
    if (*(int *)(this + 0x10) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"JASDrumSet.cpp",0x92,"mEffect != 0");
      __n = &DAT_80367bc8;
      m_Do_printf::OSPanic("JASDrumSet.cpp",0x92);
    }
    Calc::bzero(*(Calc **)(this + 0x10),(void *)(param_1 << 2),(size_t)__n);
  }
  return;
}


/* __thiscall TPerc::setVeloRegionCount(unsigned long) */

void __thiscall TPerc::setVeloRegionCount(TPerc *this,ulong param_1)

{
  TBank *this_00;
  undefined4 uVar1;
  ulong uVar2;
  
  this_00 = (TBank *)JKernel::operator_delete__(*(undefined4 *)(this + 0x1c));
  uVar1 = TBank::getCurrentHeap(this_00);
  uVar1 = JKernel::operator_new__(param_1 << 4,uVar1,0);
  *(undefined4 *)(this + 0x1c) = uVar1;
  if (*(int *)(this + 0x1c) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASDrumSet.cpp",0x9b,"mVelomap != 0");
    m_Do_printf::OSPanic("JASDrumSet.cpp",0x9b,&DAT_80367bc8);
  }
  *(ulong *)(this + 0x18) = param_1;
  return;
}


/* __thiscall TPerc::getVeloRegion(int) */

int __thiscall TPerc::getVeloRegion(TPerc *this,int param_1)

{
  ulong uVar1;
  
  if (*(uint *)(this + 0x18) <= (uint)param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASDrumSet.cpp",0xa1,"index < mVelomapCount");
    m_Do_printf::OSPanic("JASDrumSet.cpp",0xa1,&DAT_80367bc8);
  }
  if (param_1 < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASDrumSet.cpp",0xa2,"index >= 0");
    m_Do_printf::OSPanic("JASDrumSet.cpp",0xa2,&DAT_80367bc8);
  }
  return *(int *)(this + 0x1c) + param_1 * 0x10;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TPerc::setEffect(int,
                                                   JASystem::TInstEffect *) */

void __thiscall TPerc::setEffect(TPerc *this,int param_1,TInstEffect *param_2)

{
  ulong uVar1;
  
  if (*(uint *)(this + 0x14) <= (uint)param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASDrumSet.cpp",0xb1,"index < mEffectCount");
    m_Do_printf::OSPanic("JASDrumSet.cpp",0xb1,&DAT_80367bc8);
  }
  if (param_1 < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASDrumSet.cpp",0xb2,"index >= 0");
    m_Do_printf::OSPanic("JASDrumSet.cpp",0xb2,&DAT_80367bc8);
  }
  *(TInstEffect **)(*(int *)(this + 0x10) + param_1 * 4) = param_2;
  return;
}


/* __thiscall TPerc::setRelease(unsigned long) */

void __thiscall TPerc::setRelease(TPerc *this,ulong param_1)

{
  ulong uVar1;
  
  if (0xffff < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASDrumSet.cpp",0xc3,"release < 0x10000");
    m_Do_printf::OSPanic("JASDrumSet.cpp",0xc3,&DAT_80367bc8);
  }
  *(short *)(this + 0xc) = (short)param_1;
  return;
}

}

/* __thiscall TDrumSet::~TDrumSet(void) */

void __thiscall TDrumSet::_TDrumSet(TDrumSet *this)

{
  short in_r4;
  
  if (this != (TDrumSet *)0x0) {
    *(undefined1 **)this = &__vt;
    Runtime.PPCEABI.H::__destroy_arr(this + 4,TPerc::_TPerc,0x20,0x80);
    if (this != (TDrumSet *)0x0) {
      *(undefined1 **)this = &TInst::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TDrumSet::getType(void) const */

undefined4 __thiscall TDrumSet::getType(TDrumSet *this)

{
  return 0x50455243;
}

