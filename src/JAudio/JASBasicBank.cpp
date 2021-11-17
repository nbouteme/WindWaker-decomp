#include <JAudio/JASBasicBank.h>
#include <JKernel/JKRHeap.h>
#include <JAudio/JASBank.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JAudio/JASCalc.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JASystem/TBasicBank.h>
#include <JASystem/TBank.h>


namespace JASystem {

/* __thiscall TBasicBank::TBasicBank(void) */

void __thiscall TBasicBank::TBasicBank(TBasicBank *this)

{
  *(undefined1 **)this = &TBank::__vt;
  *(undefined4 *)(this + 4) = 0;
  *(undefined1 **)this = &__vt;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  return;
}


/* __thiscall TBasicBank::~TBasicBank(void) */

void __thiscall TBasicBank::_TBasicBank(TBasicBank *this)

{
  short in_r4;
  
  if (this != (TBasicBank *)0x0) {
    *(undefined1 **)this = &__vt;
    JKernel::operator_delete__(*(undefined4 *)(this + 8));
    if (this != (TBasicBank *)0x0) {
      *(undefined1 **)this = &TBank::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TBasicBank::setInstCount(unsigned long) */

void __thiscall TBasicBank::setInstCount(TBasicBank *this,ulong param_1)

{
  TBank *this_00;
  undefined4 uVar1;
  ulong uVar2;
  undefined *__n;
  
  this_00 = (TBank *)JKernel::operator_delete__(*(undefined4 *)(this + 8));
  uVar1 = TBank::getCurrentHeap(this_00);
  __n = (undefined *)0x0;
  uVar1 = JKernel::operator_new__(param_1 << 2,uVar1);
  *(undefined4 *)(this + 8) = uVar1;
  if (*(int *)(this + 8) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASBasicBank.cpp",0x24,"mInstTable != 0");
    __n = &DAT_80367b09;
    m_Do_printf::OSPanic("JASBasicBank.cpp",0x24);
  }
  Calc::bzero(*(Calc **)(this + 8),(void *)(param_1 << 2),(size_t)__n);
  *(ulong *)(this + 0xc) = param_1;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TBasicBank::setInst(int,
                                            TInst *) */

void __thiscall TBasicBank::setInst(TBasicBank *this,int param_1,TInst *param_2)

{
  ulong uVar1;
  
  if (*(uint *)(this + 0xc) <= (uint)param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASBasicBank.cpp",0x2d,"prg_no < mInstCount");
    m_Do_printf::OSPanic("JASBasicBank.cpp",0x2d,&DAT_80367b09);
  }
  if (param_1 < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASBasicBank.cpp",0x2e,"prg_no >= 0");
    m_Do_printf::OSPanic("JASBasicBank.cpp",0x2e,&DAT_80367b09);
  }
  *(TInst **)(*(int *)(this + 8) + param_1 * 4) = param_2;
  return;
}


/* __thiscall TBasicBank::getInst(int) const */

undefined4 __thiscall TBasicBank::getInst(TBasicBank *this,int param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  
  if (param_1 < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASBasicBank.cpp",0x35,"prg_no >= 0");
    m_Do_printf::OSPanic("JASBasicBank.cpp",0x35,&DAT_80367b09);
  }
  if ((uint)param_1 < *(uint *)(this + 0xc)) {
    uVar2 = *(undefined4 *)(*(int *)(this + 8) + param_1 * 4);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __thiscall TBank::~TBank(void) */

void __thiscall TBank::_TBank(TBank *this)

{
  short in_r4;
  
  if ((this != (TBank *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall TBasicBank::getType(void) const */

undefined4 __thiscall TBasicBank::getType(TBasicBank *this)

{
  return 0x42534943;
}

