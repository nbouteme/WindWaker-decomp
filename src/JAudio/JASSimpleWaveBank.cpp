#include <JAudio/JASSimpleWaveBank.h>
#include <JAudio/JASWaveArcLoader.h>
#include <JAudio/JASSimpleWaveBank.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JSupport/JSUList.h>
#include <JKernel/JKRHeap.h>
#include <JAudio/JASWaveBank.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JASystem/TSimpleWaveBank.h>
#include <Demangler/JASystem/TSimpleWaveBank/TWaveHandle.h>
#include <JASystem/TWaveArc.h>


namespace JASystem {

/* __thiscall TSimpleWaveBank::TSimpleWaveBank(void) */

void __thiscall TSimpleWaveBank::TSimpleWaveBank(TSimpleWaveBank *this)

{
  *(undefined1 **)this = &TWaveBank::__vt;
  TWaveArc::TWaveArc((TWaveArc *)(this + 4));
  *(undefined1 **)this = &__vt;
  *(undefined **)(this + 4) = &DAT_80398b18;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TSimpleWaveBank::~TSimpleWaveBank(void) */

void __thiscall TSimpleWaveBank::_TSimpleWaveBank(TSimpleWaveBank *this)

{
  short in_r4;
  JSUPtrList *this_00;
  
  if (this != (TSimpleWaveBank *)0x0) {
    *(undefined1 **)this = &__vt;
    *(undefined **)(this + 4) = &DAT_80398b18;
    Runtime.PPCEABI.H::__destroy_new_array(*(undefined4 *)(this + 0x7c),TWaveHandle::_TWaveHandle);
    if (this != (TSimpleWaveBank *)0xfffffffc) {
      *(undefined1 **)(this + 4) = &TWaveArc::__vt;
      this_00 = (JSUPtrList *)(this + 8);
      if (this_00 != (JSUPtrList *)0x0) {
        if (this_00 != (JSUPtrList *)0x0) {
          if ((JSUPtrLink *)(this + 0x14) != (JSUPtrLink *)0x0) {
            JSUPtrLink::_JSUPtrLink((JSUPtrLink *)(this + 0x14));
          }
          if (this_00 != (JSUPtrList *)0x0) {
            JSUPtrList::_JSUPtrList(this_00);
          }
        }
      }
    }
    if (this != (TSimpleWaveBank *)0x0) {
      *(undefined1 **)this = &TWaveBank::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace TSimpleWaveBank {

/* __thiscall TWaveHandle::~TWaveHandle(void) */

void __thiscall TWaveHandle::_TWaveHandle(TWaveHandle *this)

{
  short in_r4;
  
  if (this != (TWaveHandle *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (TWaveHandle *)0x0) {
      *(undefined1 **)this = &JASystem::TWaveHandle::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

}

/* __thiscall TSimpleWaveBank::setWaveTableSize(unsigned long) */

void __thiscall TSimpleWaveBank::setWaveTableSize(TSimpleWaveBank *this,ulong param_1)

{
  TWaveBank *this_00;
  undefined4 uVar1;
  ulong uVar2;
  
  this_00 = (TWaveBank *)
            Runtime.PPCEABI.H::__destroy_new_array
                      (*(undefined4 *)(this + 0x7c),TWaveHandle::_TWaveHandle);
  uVar1 = TWaveBank::getCurrentHeap(this_00);
  uVar1 = JKernel::operator_new__(param_1 * 0x34 + 0x10,uVar1,0);
  uVar1 = Runtime.PPCEABI.H::__construct_new_array
                    (uVar1,TWaveHandle::TWaveHandle,TWaveHandle::_TWaveHandle,0x34,param_1);
  *(undefined4 *)(this + 0x7c) = uVar1;
  if (*(int *)(this + 0x7c) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASSimpleWaveBank.cpp",0x22,"mWaveTable != 0");
    m_Do_printf::OSPanic("JASSimpleWaveBank.cpp",0x22,&DAT_80367d36);
  }
  *(ulong *)(this + 0x80) = param_1;
  return;
}


/* __thiscall TSimpleWaveBank::getWaveHandle(unsigned long) const */

int __thiscall TSimpleWaveBank::getWaveHandle(TSimpleWaveBank *this,ulong param_1)

{
  if (*(uint *)(this + 0x80) <= param_1) {
    return 0;
  }
  return *(int *)(this + 0x7c) + param_1 * 0x34;
}


/* __thiscall TSimpleWaveBank::setWaveInfo(unsigned long,
                                                     TWaveInfo const &) */

void __thiscall
TSimpleWaveBank::setWaveInfo(TSimpleWaveBank *this,ulong param_1,TWaveInfo *param_2)

{
  TWaveInfo *pTVar1;
  int iVar2;
  
  iVar2 = param_1 * 0x34;
  pTVar1 = (TWaveInfo *)(*(int *)(this + 0x7c) + iVar2 + 4);
  *pTVar1 = *param_2;
  pTVar1[1] = param_2[1];
  pTVar1[2] = param_2[2];
  *(undefined4 *)(pTVar1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(pTVar1 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(pTVar1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(pTVar1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(pTVar1 + 0x14) = *(undefined4 *)(param_2 + 0x14);
  *(undefined4 *)(pTVar1 + 0x18) = *(undefined4 *)(param_2 + 0x18);
  *(undefined4 *)(pTVar1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
  *(undefined2 *)(pTVar1 + 0x20) = *(undefined2 *)(param_2 + 0x20);
  *(undefined2 *)(pTVar1 + 0x22) = *(undefined2 *)(param_2 + 0x22);
  *(undefined4 *)(pTVar1 + 0x24) = *(undefined4 *)(param_2 + 0x24);
  *(undefined4 *)(pTVar1 + 0x28) = *(undefined4 *)(param_2 + 0x28);
  *(TSimpleWaveBank **)(*(int *)(this + 0x7c) + iVar2 + 0x28) = this + 0x50;
  *(TSimpleWaveBank **)(*(int *)(this + 0x7c) + iVar2 + 0x30) = this + 8;
  return;
}


/* __thiscall TSimpleWaveBank::getWaveArc(int) */

TSimpleWaveBank * __thiscall
TSimpleWaveBank::getWaveArc(TSimpleWaveBank *this,int param_1)

{
  if (param_1 != 0) {
    return (TSimpleWaveBank *)0x0;
  }
  if (this == (TSimpleWaveBank *)0x0) {
    return (TSimpleWaveBank *)0x0;
  }
  return this + 4;
}


namespace TSimpleWaveBank {

/* __thiscall TWaveHandle::TWaveHandle(void) */

void __thiscall TWaveHandle::TWaveHandle(TWaveHandle *this)

{
  *(undefined1 **)this = &JASystem::TWaveHandle::__vt;
  *(undefined1 **)this = &__vt;
  *(undefined4 *)(this + 0x30) = 0;
  return;
}


/* __thiscall TWaveHandle::getWaveInfo(void) const */

TWaveHandle * __thiscall TWaveHandle::getWaveInfo(TWaveHandle *this)

{
  return this + 4;
}


/* __thiscall TWaveHandle::getWavePtr(void) const */

int __thiscall TWaveHandle::getWavePtr(TWaveHandle *this)

{
  if (*(int *)(*(int *)(this + 0x30) + 0x3c) == 0) {
    return 0;
  }
  return *(int *)(*(int *)(this + 0x30) + 0x3c) + *(int *)(this + 0xc);
}

}

/* __thiscall TWaveArc::onLoadDone(void) */

void __thiscall TWaveArc::onLoadDone(TWaveArc *this)

{
  return;
}


/* __thiscall TWaveArc::onEraseDone(void) */

void __thiscall TWaveArc::onEraseDone(TWaveArc *this)

{
  return;
}

