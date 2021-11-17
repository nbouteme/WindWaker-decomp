#include <JAudio/JAISequenceHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <m_Do_printf.h>
#include <JUtility/JUTAssert.h>
#include <JKernel/JKRHeap.h>
#include <JAudio/JAISequenceHeap.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JAudio/JAIGlobalParameter.h>
#include <JAInter/HeapBlock.h>
#include <JAInter/HeapMgr.h>


namespace JAInter {
undefined1 HeapMgr;
undefined1 HeapMgr;
undefined1 HeapMgr;
undefined1 HeapMgr;

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall HeapMgr::init(unsigned char,
                                     unsigned long,
                                     unsigned char,
                                     unsigned long) */

int __thiscall HeapMgr::init(HeapMgr *this,EVP_PKEY_CTX *ctx)

{
  undefined4 uVar1;
  uint in_r5;
  undefined4 in_r6;
  int iVar2;
  uint uVar3;
  
  if ((_msCurrentHeap == 0) &&
     (m_Do_printf::OSReport
                ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
     _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_803693ed);
  }
  uVar1 = JKernel::operator_new__((in_r5 & 0xff) * 0x14 + 0x10,_msCurrentHeap,0x20);
  _sAutoHeap = Runtime.PPCEABI.H::__construct_new_array
                         (uVar1,HeapBlock::HeapBlock,0,0x14,in_r5 & 0xff);
  if ((_sAutoHeap == 0) &&
     (m_Do_printf::OSReport("JAIHeapMgr::initHeap Cannot Alloc Heap!!\n"), _sAutoHeap == 0)) {
    JUTAssertion::showAssert(3,"JAISequenceHeap.cpp",0x26,"sAutoHeap");
    m_Do_printf::OSPanic("JAISequenceHeap.cpp",0x26,&DAT_803693ed);
  }
  iVar2 = 0;
  for (uVar3 = 0; uVar3 < (in_r5 & 0xff); uVar3 = uVar3 + 1) {
    *(undefined *)(_sAutoHeap + iVar2) = 0;
    *(undefined4 *)(_sAutoHeap + iVar2 + 0xc) = 0;
    *(undefined4 *)(_sAutoHeap + iVar2 + 8) = 0xffffffff;
    *(undefined4 *)(_sAutoHeap + iVar2 + 0x10) = 0xffffffff;
    if ((_msCurrentHeap == 0) &&
       (m_Do_printf::OSReport
                  ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
       _msCurrentHeap == 0)) {
      JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
      m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_803693ed);
    }
    uVar1 = JKernel::operator_new__(in_r6,_msCurrentHeap,0x20);
    *(undefined4 *)(_sAutoHeap + iVar2 + 4) = uVar1;
    iVar2 = iVar2 + 0x14;
  }
  if ((_msCurrentHeap == 0) &&
     (m_Do_printf::OSReport
                ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
     _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_803693ed);
  }
  uVar1 = JKernel::operator_new__(((uint)this & 0xff) * 0x14 + 0x10,_msCurrentHeap,0x20);
  _sStayHeap = Runtime.PPCEABI.H::__construct_new_array
                         (uVar1,HeapBlock::HeapBlock,0,0x14,(uint)this & 0xff);
  if ((_sStayHeap == 0) &&
     (m_Do_printf::OSReport("JAIHeapMgr::initHeap Cannot Alloc Heap!!\n"), _sStayHeap == 0)) {
    JUTAssertion::showAssert(3,"JAISequenceHeap.cpp",0x30,"sStayHeap");
    m_Do_printf::OSPanic("JAISequenceHeap.cpp",0x30,&DAT_803693ed);
  }
  if ((_msCurrentHeap == 0) &&
     (m_Do_printf::OSReport
                ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
     _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_803693ed);
  }
  uVar1 = JKernel::operator_new__(ctx,_msCurrentHeap,0x20);
  *(undefined4 *)(_sStayHeap + 4) = uVar1;
  iVar2 = 0;
  for (uVar3 = (uint)this & 0xff; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined *)(_sStayHeap + iVar2) = 0;
    *(undefined4 *)(_sStayHeap + iVar2 + 0xc) = 0;
    *(undefined4 *)(_sStayHeap + iVar2 + 8) = 0xffffffff;
    *(undefined4 *)(_sStayHeap + iVar2 + 0x10) = 0xffffffff;
    iVar2 = iVar2 + 0x14;
  }
  return iVar2;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall HeapMgr::getAutoHeapPointer(void) */

undefined4 __thiscall HeapMgr::getAutoHeapPointer(HeapMgr *this)

{
  return _sAutoHeap;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall HeapMgr::checkOnMemory(unsigned long,
                                              unsigned char *) */

undefined4 __thiscall HeapMgr::checkOnMemory(HeapMgr *this,ulong param_1,uchar *param_2)

{
  HeapMgr *this_00;
  uint uVar1;
  int iVar2;
  byte bVar3;
  
  this_00 = this;
  for (bVar3 = 0; uVar1 = JAIGlobalParameter::getParamAutoHeapMax((JAIGlobalParameter *)this_00),
      bVar3 < uVar1; bVar3 = bVar3 + 1) {
    this_00 = (HeapMgr *)(_sAutoHeap + (uint)bVar3 * 0x14);
    if (this == *(HeapMgr **)((JAIGlobalParameter *)this_00 + 8)) {
      if (*(JAIGlobalParameter *)this_00 == (JAIGlobalParameter)0x1) {
        return 0xffffffff;
      }
      if (param_1 != 0) {
        *(byte *)param_1 = bVar3;
      }
      return *(undefined4 *)(_sAutoHeap + (uint)bVar3 * 0x14 + 4);
    }
  }
  uVar1 = 0;
  while( true ) {
    if (_sStayHeapCount <= (uVar1 & 0xff)) {
      return 0;
    }
    iVar2 = (uVar1 & 0xff) * 0x14;
    if (this == *(HeapMgr **)(_sStayHeap + iVar2 + 8)) break;
    uVar1 = uVar1 + 1;
  }
  if (param_1 != 0) {
    *(undefined *)param_1 = 0xff;
  }
  return *(undefined4 *)(_sStayHeap + iVar2 + 4);
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall HeapMgr::releaseAutoHeapPointer(unsigned char) */

void __thiscall HeapMgr::releaseAutoHeapPointer(HeapMgr *this,uchar param_1)

{
  if (((uint)this & 0xff) == 0xff) {
    return;
  }
  *(undefined4 *)(_sAutoHeap + ((uint)this & 0xff) * 0x14 + 0x10) = 0xffffffff;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall HeapMgr::checkUsefulAutoHeapPosition(void) */

uint __thiscall HeapMgr::checkUsefulAutoHeapPosition(HeapMgr *this)

{
  uint *puVar1;
  JAIGlobalParameter *pJVar2;
  JAIGlobalParameter *pJVar3;
  uint uVar4;
  JAIGlobalParameter *pJVar5;
  int iVar6;
  
  pJVar5 = (JAIGlobalParameter *)0x0;
  uVar4 = 0xffffffff;
  pJVar3 = (JAIGlobalParameter *)0x0;
  for (iVar6 = 0;
      (this = (HeapMgr *)JAIGlobalParameter::getParamAutoHeapMax((JAIGlobalParameter *)this),
      pJVar5 < this &&
      (this = *(HeapMgr **)(_sAutoHeap + iVar6 + 8), this != (HeapMgr *)&DAT_ffffffff));
      iVar6 = iVar6 + 0x14) {
    pJVar5 = pJVar5 + 1;
  }
  pJVar2 = (JAIGlobalParameter *)JAIGlobalParameter::getParamAutoHeapMax((JAIGlobalParameter *)this)
  ;
  if (pJVar5 == pJVar2) {
    iVar6 = 0;
    for (pJVar5 = (JAIGlobalParameter *)0x0;
        pJVar2 = (JAIGlobalParameter *)JAIGlobalParameter::getParamAutoHeapMax(pJVar2),
        pJVar5 < pJVar2; pJVar5 = pJVar5 + 1) {
      pJVar2 = (JAIGlobalParameter *)(_sAutoHeap + iVar6);
      puVar1 = (uint *)(pJVar2 + 0xc);
      if ((*puVar1 < uVar4) &&
         (pJVar2 = *(JAIGlobalParameter **)(pJVar2 + 0x10),
         pJVar2 == (JAIGlobalParameter *)&DAT_ffffffff)) {
        pJVar3 = pJVar5;
        uVar4 = *puVar1;
      }
      iVar6 = iVar6 + 0x14;
    }
    if (uVar4 != 0xffffffff) {
      pJVar5 = pJVar3;
    }
  }
  return (uint)pJVar5 & 0xff;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall HeapMgr::getFreeAutoHeapPointer(unsigned char,
                                                       unsigned long) */

undefined4 __thiscall
HeapMgr::getFreeAutoHeapPointer(HeapMgr *this,uchar param_1,ulong param_2)

{
  undefined4 uVar1;
  undefined3 in_register_00000010;
  int iVar2;
  
  iVar2 = ((uint)this & 0xff) * 0x14;
  *(uint *)(_sAutoHeap + iVar2 + 8) = CONCAT31(in_register_00000010,param_1);
  uVar1 = *(undefined4 *)(_sAutoHeap + iVar2 + 4);
  *(int *)(_sAutoHeap + iVar2 + 0x10) = _sAutoHeapCount;
  *(int *)(_sAutoHeap + iVar2 + 0xc) = _sAutoHeapCount;
  _sAutoHeapCount = _sAutoHeapCount + 1;
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall HeapMgr::getFreeStayHeapPointer(unsigned long,
                                                       unsigned long) */

undefined4 __thiscall
HeapMgr::getFreeStayHeapPointer(HeapMgr *this,ulong param_1,ulong param_2)

{
  JAIGlobalParameter *pJVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  pJVar1 = (JAIGlobalParameter *)JAIGlobalParameter::getParamStayHeapMax((JAIGlobalParameter *)this)
  ;
  if (_sStayHeapCount < pJVar1) {
    iVar5 = *(int *)(_sStayHeap + 4);
    iVar4 = *(int *)((JAIGlobalParameter *)((int)_sStayHeapCount * 0x14) + _sStayHeap + 4);
    iVar3 = JAIGlobalParameter::getParamStayHeapSize
                      ((JAIGlobalParameter *)((int)_sStayHeapCount * 0x14));
    pJVar1 = (JAIGlobalParameter *)(iVar5 + iVar3);
    if ((this + iVar4 < pJVar1) &&
       (pJVar1 = (JAIGlobalParameter *)JAIGlobalParameter::getParamStayHeapMax(pJVar1),
       _sStayHeapCount < pJVar1)) {
      iVar3 = _sStayHeap + (int)_sStayHeapCount * 0x14;
      uVar2 = *(undefined4 *)(iVar3 + 4);
      *(ulong *)(iVar3 + 8) = param_1;
      pJVar1 = _sStayHeapCount;
      iVar3 = ((uint)this & 0xffffffe0) + *(int *)(_sStayHeap + (int)_sStayHeapCount * 0x14 + 4);
      if (((uint)this & 0x1f) != 0) {
        iVar3 = iVar3 + 0x20;
      }
      _sStayHeapCount = _sStayHeapCount + 1;
      pJVar1 = (JAIGlobalParameter *)JAIGlobalParameter::getParamStayHeapMax(pJVar1);
      if (_sStayHeapCount < pJVar1) {
        *(int *)(_sStayHeap + (int)_sStayHeapCount * 0x14 + 4) = iVar3;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall HeapMgr::setAutoHeapLoadedFlag(unsigned char,
                                                      unsigned char) */

void __thiscall HeapMgr::setAutoHeapLoadedFlag(HeapMgr *this,uchar param_1,uchar param_2)

{
  *(uchar *)(_sAutoHeap + ((uint)this & 0xff) * 0x14) = param_1;
  return;
}


/* __thiscall HeapBlock::HeapBlock(void) */

void __thiscall HeapBlock::HeapBlock(HeapBlock *this)

{
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 8) = 0xffffffff;
  *(undefined4 *)(this + 0x10) = 0xffffffff;
  return;
}

