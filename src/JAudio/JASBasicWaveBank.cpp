#include <JAudio/JASBasicWaveBank.h>
#include <os/OSMutex.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <JAudio/JASBasicWaveBank.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JAudio/JASWaveBank.h>
#include <JAudio/JASCalc.h>
#include <JAudio/JASWaveArcLoader.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JSupport/JSUList.h>
#include <JASystem/TBasicWaveBank/TWaveInfo.h>
#include <JASystem/TWaveBank.h>
#include <Demangler/JASystem/TBasicWaveBank/TWaveGroup.h>
#include <Demangler/JASystem/TBasicWaveBank/TWaveHandle.h>
#include <JASystem/TBasicWaveBank.h>
#include <JASystem/TWaveHandle.h>


namespace JASystem {

/* __thiscall TBasicWaveBank::TBasicWaveBank(void) */

void __thiscall TBasicWaveBank::TBasicWaveBank(TBasicWaveBank *this)

{
  *(undefined1 **)this = &TWaveBank::__vt;
  *(undefined1 **)this = &__vt;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  os::OSInitMutex((OSMutex *)(this + 4));
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall TBasicWaveBank::~TBasicWaveBank(void) */

void __thiscall TBasicWaveBank::_TBasicWaveBank(TBasicWaveBank *this)

{
  short in_r4;
  uint uVar1;
  int iVar2;
  
  if (this != (TBasicWaveBank *)0x0) {
    *(undefined1 **)this = &__vt;
    JKernel::operator_delete__(*(undefined4 *)(this + 0x1c));
    iVar2 = 0;
    for (uVar1 = 0; uVar1 < *(uint *)(this + 0x28); uVar1 = uVar1 + 1) {
      TWaveGroup::_TWaveGroup(*(TWaveGroup **)(*(int *)(this + 0x24) + iVar2));
      iVar2 = iVar2 + 4;
    }
    JKernel::operator_delete__(*(undefined4 *)(this + 0x24));
    if (this != (TBasicWaveBank *)0x0) {
      *(undefined1 **)this = &TWaveBank::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TBasicWaveBank::getWaveGroup(int) */

undefined4 __thiscall TBasicWaveBank::getWaveGroup(TBasicWaveBank *this,int param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  
  if (param_1 < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASBasicWaveBank.cpp",0x29,"group_no >= 0");
    m_Do_printf::OSPanic("JASBasicWaveBank.cpp",0x29,&DAT_80367c93);
  }
  if ((uint)param_1 < *(uint *)(this + 0x28)) {
    uVar2 = *(undefined4 *)(*(int *)(this + 0x24) + param_1 * 4);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall TBasicWaveBank::setGroupCount(unsigned long) */

void __thiscall TBasicWaveBank::setGroupCount(TBasicWaveBank *this,ulong param_1)

{
  TWaveBank *pTVar1;
  undefined4 uVar2;
  ulong uVar3;
  JKRHeap *heap;
  TWaveGroup *this_00;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  for (uVar4 = 0; uVar4 < *(uint *)(this + 0x28); uVar4 = uVar4 + 1) {
    TWaveGroup::_TWaveGroup(*(TWaveGroup **)(*(int *)(this + 0x24) + iVar5));
    iVar5 = iVar5 + 4;
  }
  pTVar1 = (TWaveBank *)JKernel::operator_delete__(*(undefined4 *)(this + 0x24));
  *(ulong *)(this + 0x28) = param_1;
  uVar2 = TWaveBank::getCurrentHeap(pTVar1);
  pTVar1 = (TWaveBank *)JKernel::operator_new__(param_1 << 2,uVar2,0);
  *(TWaveBank **)(this + 0x24) = pTVar1;
  if (*(int *)(this + 0x24) == 0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"JASBasicWaveBank.cpp",0x3a,"mWaveGroupArray != 0");
    pTVar1 = (TWaveBank *)m_Do_printf::OSPanic("JASBasicWaveBank.cpp",0x3a,&DAT_80367c93);
  }
  uVar4 = 0;
  iVar5 = 0;
  while( true ) {
    if (*(uint *)(this + 0x28) <= uVar4) break;
    heap = (JKRHeap *)TWaveBank::getCurrentHeap(pTVar1);
    this_00 = (TWaveGroup *)JKernel::operator_new(0x84,heap,0);
    if (this_00 != (TWaveGroup *)0x0) {
      TWaveGroup::TWaveGroup(this_00,this);
    }
    pTVar1 = *(TWaveBank **)(this + 0x24);
    *(TWaveGroup **)(pTVar1 + iVar5) = this_00;
    uVar4 = uVar4 + 1;
    iVar5 = iVar5 + 4;
  }
  return;
}


/* __thiscall TBasicWaveBank::setWaveTableSize(unsigned long) */

void __thiscall TBasicWaveBank::setWaveTableSize(TBasicWaveBank *this,ulong param_1)

{
  TWaveBank *this_00;
  undefined4 uVar1;
  ulong uVar2;
  undefined *__n;
  
  this_00 = (TWaveBank *)JKernel::operator_delete__(*(undefined4 *)(this + 0x1c));
  uVar1 = TWaveBank::getCurrentHeap(this_00);
  __n = (undefined *)0x0;
  uVar1 = JKernel::operator_new__(param_1 << 2,uVar1);
  *(undefined4 *)(this + 0x1c) = uVar1;
  if (*(int *)(this + 0x1c) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASBasicWaveBank.cpp",0x46,"mWaveTable != 0");
    __n = &DAT_80367c93;
    m_Do_printf::OSPanic("JASBasicWaveBank.cpp",0x46);
  }
  Calc::bzero(*(Calc **)(this + 0x1c),(void *)(param_1 << 2),(size_t)__n);
  *(ulong *)(this + 0x20) = param_1;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall TBasicWaveBank::incWaveTable(TBasicWaveBank::TWaveGroup const *)
    */

void __thiscall TBasicWaveBank::incWaveTable(TBasicWaveBank *this,TWaveGroup *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  os::OSLockMutex((OSMutex *)(this + 4));
  iVar5 = 0;
  for (uVar4 = 0; uVar4 < *(uint *)(param_1 + 0x80); uVar4 = uVar4 + 1) {
    iVar1 = TWaveGroup::getWaveID(param_1,uVar4);
    iVar1 = iVar1 * 4;
    iVar2 = *(int *)(this + 0x1c);
    iVar3 = *(int *)(param_1 + 0x7c) + iVar5;
    *(undefined4 *)(iVar3 + 0x3c) = 0;
    *(undefined4 *)(iVar3 + 0x38) = *(undefined4 *)(iVar2 + iVar1);
    if (*(int *)(iVar2 + iVar1) != 0) {
      *(int *)(*(int *)(iVar2 + iVar1) + 0x3c) = iVar3;
    }
    *(int *)(iVar2 + iVar1) = iVar3;
    iVar5 = iVar5 + 0x40;
  }
  os::OSUnlockMutex(this + 4);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall TBasicWaveBank::decWaveTable(TBasicWaveBank::TWaveGroup const *)
    */

void __thiscall TBasicWaveBank::decWaveTable(TBasicWaveBank *this,TWaveGroup *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  os::OSLockMutex((OSMutex *)(this + 4));
  uVar3 = 0;
  iVar4 = 0;
  do {
    if (*(uint *)(param_1 + 0x80) <= uVar3) {
      os::OSUnlockMutex(this + 4);
      return;
    }
    iVar1 = TWaveGroup::getWaveID(param_1,uVar3);
    for (iVar2 = *(int *)(*(int *)(this + 0x1c) + iVar1 * 4); iVar2 != 0;
        iVar2 = *(int *)(iVar2 + 0x38)) {
      if (iVar2 == *(int *)(param_1 + 0x7c) + iVar4) {
        if (*(int *)(iVar2 + 0x3c) == 0) {
          *(undefined4 *)(*(int *)(this + 0x1c) + iVar1 * 4) = *(undefined4 *)(iVar2 + 0x38);
        }
        else {
          *(undefined4 *)(*(int *)(iVar2 + 0x3c) + 0x38) = *(undefined4 *)(iVar2 + 0x38);
        }
        if (*(int *)(iVar2 + 0x38) != 0) {
          *(undefined4 *)(*(int *)(iVar2 + 0x38) + 0x3c) = *(undefined4 *)(iVar2 + 0x3c);
        }
        break;
      }
    }
    uVar3 = uVar3 + 1;
    iVar4 = iVar4 + 0x40;
  } while( true );
}


/* __thiscall TBasicWaveBank::getWaveHandle(unsigned long) const */

int __thiscall TBasicWaveBank::getWaveHandle(TBasicWaveBank *this,ulong param_1)

{
  int iVar1;
  
  if (*(uint *)(this + 0x20) <= param_1) {
    return 0;
  }
  iVar1 = *(int *)(*(int *)(this + 0x1c) + param_1 * 4);
  if (iVar1 != 0) {
    return iVar1;
  }
  return 0;
}


namespace TBasicWaveBank {

/* __thiscall TWaveGroup::TWaveGroup(JASystem::TBasicWaveBank *) */

void __thiscall
TWaveGroup::TWaveGroup(TWaveGroup *this,TBasicWaveBank *param_1)

{
  TWaveArc::TWaveArc((TWaveArc *)this);
  *(undefined1 **)this = &__vt;
  *(TBasicWaveBank **)(this + 0x78) = param_1;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  return;
}


/* __thiscall TWaveGroup::~TWaveGroup(void) */

void __thiscall TWaveGroup::_TWaveGroup(TWaveGroup *this)

{
  short in_r4;
  
  if (this != (TWaveGroup *)0x0) {
    *(undefined1 **)this = &__vt;
    Runtime.PPCEABI.H::__destroy_new_array(*(undefined4 *)(this + 0x7c),TWaveInfo::_TWaveInfo);
    if (this != (TWaveGroup *)0x0) {
      *(undefined1 **)this = &TWaveArc::__vt;
      if (this != (TWaveGroup *)0xfffffffc) {
        if (this != (TWaveGroup *)0xfffffffc) {
          if (this != (TWaveGroup *)0xfffffff0) {
            JSUPtrLink::_JSUPtrLink((JSUPtrLink *)(this + 0x10));
          }
          if (this != (TWaveGroup *)0xfffffffc) {
            JSUPtrList::_JSUPtrList((JSUPtrList *)(this + 4));
          }
        }
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TWaveInfo::~TWaveInfo(void) */

void __thiscall TWaveInfo::_TWaveInfo(TWaveInfo *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (TWaveInfo *)0x0;
  if (bVar1) {
    if ((bVar1) && (*(undefined1 **)this = &TWaveHandle::__vt, bVar1)) {
      *(undefined1 **)this = &JASystem::TWaveHandle::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TWaveGroup::setWaveCount(unsigned long) */

void __thiscall TWaveGroup::setWaveCount(TWaveGroup *this,ulong param_1)

{
  TWaveBank *this_00;
  undefined4 uVar1;
  ulong uVar2;
  int iVar3;
  
  this_00 = (TWaveBank *)
            Runtime.PPCEABI.H::__destroy_new_array
                      (*(undefined4 *)(this + 0x7c),TWaveInfo::_TWaveInfo);
  *(ulong *)(this + 0x80) = param_1;
  uVar1 = TWaveBank::getCurrentHeap(this_00);
  uVar1 = JKernel::operator_new__(param_1 * 0x40 + 0x10,uVar1,0);
  uVar1 = Runtime.PPCEABI.H::__construct_new_array
                    (uVar1,TWaveInfo::TWaveInfo,TWaveInfo::_TWaveInfo,0x40,param_1);
  *(undefined4 *)(this + 0x7c) = uVar1;
  if (*(int *)(this + 0x7c) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASBasicWaveBank.cpp",0xb4,"mCtrlWaveArray != 0");
    m_Do_printf::OSPanic("JASBasicWaveBank.cpp",0xb4,&DAT_80367c93);
  }
  iVar3 = 0;
  if (param_1 != 0) {
    do {
      *(TWaveGroup **)(*(int *)(this + 0x7c) + iVar3 + 0x30) = this + 4;
      *(TWaveGroup **)(*(int *)(this + 0x7c) + iVar3 + 0x28) = this + 0x4c;
      iVar3 = iVar3 + 0x40;
      param_1 = param_1 - 1;
    } while (param_1 != 0);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall TWaveGroup::setWaveInfo(int,
                                                                unsigned long,
                                                                JASystem::TWaveInfo const &) */

void __thiscall
TWaveGroup::setWaveInfo
          (TWaveGroup *this,int param_1,ulong param_2,TWaveInfo *param_3)

{
  int iVar1;
  ulong uVar2;
  TWaveInfo *pTVar3;
  
  if (*(uint *)(this + 0x80) <= (uint)param_1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASBasicWaveBank.cpp",0xbe,"index < mWaveCount");
    m_Do_printf::OSPanic("JASBasicWaveBank.cpp",0xbe,&DAT_80367c93);
  }
  if (param_1 < 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASBasicWaveBank.cpp",0xbf,"index >= 0");
    m_Do_printf::OSPanic("JASBasicWaveBank.cpp",0xbf,&DAT_80367c93);
  }
  iVar1 = param_1 * 0x40;
  *(ulong *)(*(int *)(this + 0x7c) + iVar1 + 0x34) = param_2;
  pTVar3 = (TWaveInfo *)(*(int *)(this + 0x7c) + iVar1 + 4);
  *pTVar3 = *param_3;
  pTVar3[1] = param_3[1];
  pTVar3[2] = param_3[2];
  *(undefined4 *)(pTVar3 + 4) = *(undefined4 *)(param_3 + 4);
  *(undefined4 *)(pTVar3 + 8) = *(undefined4 *)(param_3 + 8);
  *(undefined4 *)(pTVar3 + 0xc) = *(undefined4 *)(param_3 + 0xc);
  *(undefined4 *)(pTVar3 + 0x10) = *(undefined4 *)(param_3 + 0x10);
  *(undefined4 *)(pTVar3 + 0x14) = *(undefined4 *)(param_3 + 0x14);
  *(undefined4 *)(pTVar3 + 0x18) = *(undefined4 *)(param_3 + 0x18);
  *(undefined4 *)(pTVar3 + 0x1c) = *(undefined4 *)(param_3 + 0x1c);
  *(undefined2 *)(pTVar3 + 0x20) = *(undefined2 *)(param_3 + 0x20);
  *(undefined2 *)(pTVar3 + 0x22) = *(undefined2 *)(param_3 + 0x22);
  *(undefined4 *)(pTVar3 + 0x24) = *(undefined4 *)(param_3 + 0x24);
  *(undefined4 *)(pTVar3 + 0x28) = *(undefined4 *)(param_3 + 0x28);
  *(TWaveGroup **)(*(int *)(this + 0x7c) + iVar1 + 0x28) = this + 0x4c;
  return;
}


/* __thiscall TWaveGroup::onLoadDone(void) */

void __thiscall TWaveGroup::onLoadDone(TWaveGroup *this)

{
  ulong uVar1;
  
  if (*(int *)(this + 0x78) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASBasicWaveBank.cpp",0xc9,"mBank");
    m_Do_printf::OSPanic("JASBasicWaveBank.cpp",0xc9,&DAT_80367c93);
  }
  incWaveTable(*(TBasicWaveBank **)(this + 0x78),this);
  return;
}


/* __thiscall TWaveGroup::onEraseDone(void) */

void __thiscall TWaveGroup::onEraseDone(TWaveGroup *this)

{
  ulong uVar1;
  
  if (*(int *)(this + 0x78) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASBasicWaveBank.cpp",0xcf,"mBank");
    m_Do_printf::OSPanic("JASBasicWaveBank.cpp",0xcf,&DAT_80367c93);
  }
  decWaveTable(*(TBasicWaveBank **)(this + 0x78),this);
  return;
}


/* __thiscall TWaveGroup::getWaveID(int) const */

undefined4 __thiscall TWaveGroup::getWaveID(TWaveGroup *this,int param_1)

{
  return *(undefined4 *)(*(int *)(this + 0x7c) + param_1 * 0x40 + 0x34);
}

}

/* __thiscall TWaveBank::~TWaveBank(void) */

void __thiscall TWaveBank::_TWaveBank(TWaveBank *this)

{
  short in_r4;
  
  if ((this != (TWaveBank *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall TWaveHandle::~TWaveHandle(void) */

void __thiscall TWaveHandle::_TWaveHandle(TWaveHandle *this)

{
  short in_r4;
  
  if ((this != (TWaveHandle *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace TBasicWaveBank {

/* __thiscall TWaveInfo::TWaveInfo(void) */

void __thiscall TWaveInfo::TWaveInfo(TWaveInfo *this)

{
  *(undefined1 **)this = &JASystem::TWaveHandle::__vt;
  *(undefined1 **)this = &TWaveHandle::__vt;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  return;
}


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


/* __thiscall TWaveHandle::getWaveInfo(void) const */

TWaveHandle * __thiscall TWaveHandle::getWaveInfo(TWaveHandle *this)

{
  return this + 4;
}


/* __thiscall TWaveHandle::getWavePtr(void) const */

int __thiscall TWaveHandle::getWavePtr(TWaveHandle *this)

{
  ulong uVar1;
  int iVar2;
  
  if (*(int *)(this + 0x30) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASBasicWaveBank.h",0x4d,"mHeap");
    m_Do_printf::OSPanic("JASBasicWaveBank.h",0x4d,&DAT_80367c93);
  }
  if (*(int *)(*(int *)(this + 0x30) + 0x3c) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*(int *)(this + 0x30) + 0x3c) + *(int *)(this + 0xc);
  }
  return iVar2;
}

}

/* __thiscall TBasicWaveBank::getWaveArc(int) */

void __thiscall TBasicWaveBank::getWaveArc(TBasicWaveBank *this,int param_1)

{
  getWaveGroup(this,param_1);
  return;
}

