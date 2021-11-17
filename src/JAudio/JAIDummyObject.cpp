#include <JAudio/JAIDummyObject.h>
#include <m_Do_printf.h>
#include <JUtility/JUTAssert.h>
#include <JAudio/JAIGlobalParameter.h>
#include <JKernel/JKRHeap.h>
#include <JAudio/JAIBasic.h>
#include <JAudio/JAISound.h>
#include <JAudio/JAIDummyObject.h>
#include <JAInter/DummyObjectMgr.h>


namespace JAInter {
undefined1 DummyObjectMgr;
undefined1 DummyObjectMgr;
undefined1 DummyObjectMgr;

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall DummyObjectMgr::init(void) */

int __thiscall DummyObjectMgr::init(DummyObjectMgr *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  
  if ((_msCurrentHeap == 0) &&
     (this = (DummyObjectMgr *)
             m_Do_printf::OSReport
                       (
                       "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                       ), _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    this = (DummyObjectMgr *)m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80368fc5);
  }
  iVar4 = _msCurrentHeap;
  iVar1 = JAIGlobalParameter::getParamDummyObjectMax((JAIGlobalParameter *)this);
  _deadObjectObject = (undefined4 *)JKernel::operator_new__(iVar1 << 5,iVar4,0x20);
  if ((_deadObjectObject == (undefined4 *)0x0) &&
     (m_Do_printf::OSReport("JAIDummyObjectMgr::init Cannot Alloc Heap!!\n"),
     _deadObjectObject == (undefined4 *)0x0)) {
    JUTAssertion::showAssert(3,"JAIDummyObject.cpp",0x25,"deadObjectObject");
    m_Do_printf::OSPanic("JAIDummyObject.cpp",0x25,&DAT_80368fc5);
  }
  _deadObjectFreePointer = _deadObjectObject;
  _deadObjectUsedPointer = 0;
  *_deadObjectObject = 0;
  puVar2 = _deadObjectObject;
  _deadObjectObject[1] = _deadObjectObject + 8;
  iVar4 = 0x20;
  for (uVar3 = 1; iVar1 = JAIGlobalParameter::getParamDummyObjectMax((JAIGlobalParameter *)puVar2),
      uVar3 < iVar1 - 1U; uVar3 = uVar3 + 1) {
    *(undefined4 **)((int)_deadObjectObject + iVar4) = _deadObjectObject + (uVar3 - 1) * 8;
    puVar2 = _deadObjectObject + (uVar3 + 1) * 8;
    *(undefined4 **)((int)_deadObjectObject + iVar4 + 4) = puVar2;
    iVar4 = iVar4 + 0x20;
  }
  _deadObjectObject[uVar3 * 8] = _deadObjectObject + (uVar3 - 1) * 8;
  puVar2 = _deadObjectObject + uVar3 * 8;
  puVar2[1] = 0;
  return (int)puVar2;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall DummyObjectMgr::getPointer(unsigned long,
                                                  bool) */

undefined4 * __thiscall
DummyObjectMgr::getPointer(DummyObjectMgr *this,ulong param_1,bool param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = _deadObjectFreePointer;
  if (_deadObjectFreePointer == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    if (_deadObjectUsedPointer == (undefined4 *)0x0) {
      puVar1 = _deadObjectFreePointer + 1;
      _deadObjectFreePointer = (undefined4 *)_deadObjectFreePointer[1];
      *puVar1 = 0;
    }
    else {
      puVar1 = _deadObjectFreePointer + 1;
      _deadObjectFreePointer = (undefined4 *)_deadObjectFreePointer[1];
      *puVar1 = _deadObjectUsedPointer;
      *_deadObjectUsedPointer = puVar2;
    }
    *puVar2 = 0;
    _deadObjectUsedPointer = puVar2;
    puVar2[6] = this;
    *(char *)(puVar2 + 7) = (char)param_1;
    puVar2[2] = 0;
  }
  return puVar2;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall DummyObjectMgr::releasePointer(DummyVec *) */

void __thiscall DummyObjectMgr::releasePointer(DummyObjectMgr *this,DummyVec *param_1)

{
  if (_deadObjectUsedPointer == this) {
    _deadObjectUsedPointer = *(DummyObjectMgr **)(this + 4);
    if (*(undefined4 **)(this + 4) != (undefined4 *)0x0) {
      **(undefined4 **)(this + 4) = 0;
    }
  }
  else {
    *(undefined4 *)(*(int *)this + 4) = *(undefined4 *)(this + 4);
    if (*(undefined4 **)(this + 4) != (undefined4 *)0x0) {
      **(undefined4 **)(this + 4) = *(undefined4 *)this;
    }
  }
  *(DummyObjectMgr **)(this + 4) = _deadObjectFreePointer;
  if (*(DummyObjectMgr ***)(this + 4) != (DummyObjectMgr **)0x0) {
    **(DummyObjectMgr ***)(this + 4) = this;
  }
  _deadObjectFreePointer = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall DummyObjectMgr::check(void) */

undefined4 __thiscall DummyObjectMgr::check(DummyObjectMgr *this)

{
  ulonglong uVar1;
  uint uVar2;
  undefined4 in_r4;
  DummyVec *extraout_r4;
  DummyVec *extraout_r4_00;
  DummyVec *pDVar3;
  DummyObjectMgr *pDVar4;
  DummyObjectMgr *this_00;
  ulonglong uVar5;
  
  pDVar4 = _deadObjectUsedPointer;
  uVar5 = CONCAT44(this,in_r4);
  while( true ) {
    this_00 = pDVar4;
    pDVar3 = (DummyVec *)uVar5;
    if (this_00 == (DummyObjectMgr *)0x0) break;
    pDVar4 = *(DummyObjectMgr **)(this_00 + 4);
    uVar2 = *(uint *)(this_00 + 0x18);
    uVar1 = uVar5 & 0xffffffff;
    *(uint *)(this_00 + 0x18) = uVar2 - 1;
    if ((*(int *)(this_00 + 0x18) == 0) ||
       ((uVar5 = uVar5 & 0xffffffff | (ulonglong)uVar2 << 0x20, this_00[0x1c] == (DummyObjectMgr)0x0
        && (uVar5 = uVar1 | (ulonglong)uVar2 << 0x20, *(int *)(this_00 + 8) == 0)))) {
      if (this_00[0x1c] == (DummyObjectMgr)0x1) {
        JAIBasic::stopAllSound(_msBasic,this_00 + 0xc);
        pDVar3 = extraout_r4;
      }
      else {
        if (*(JAISound **)(this_00 + 8) != (JAISound *)0x0) {
          JAISound::stop(*(JAISound **)(this_00 + 8),0);
          pDVar3 = extraout_r4_00;
        }
      }
      uVar5 = releasePointer(this_00,pDVar3);
    }
  }
  return (int)(uVar5 >> 0x20);
}

