#include <JKernel/JKRAramHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRDisposer.h>
#include <os/OSMutex.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRAramBlock.h>
#include <JSupport/JSUList.h>
#include <JKernel/JKRAramHeap.h>
#include <m_Do_printf.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JKRAramHeap.h>
#include <JSUList<JKRAramBlock>.h>

undefined1 JKRAramHeap;

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRAramHeap::JKRAramHeap(unsigned long,
                                       unsigned long) */

void __thiscall JKRAramHeap::JKRAramHeap(JKRAramHeap *this,ulong param_1,ulong param_2)

{
  JKRHeap *pJVar1;
  JKRAramBlock *this_00;
  
  JKRDisposer::JKRDisposer((JKRDisposer *)this);
  this->vtbl = &__vt;
  os::OSInitMutex((OSMutex *)&this->field_0x18);
  pJVar1 = JKRHeap::findFromRoot(this);
  this->field_0x30 = pJVar1;
  *(ulong *)&this->field_0x3c = param_2 & 0xffffffe0;
  *(ulong *)&this->field_0x34 = param_1 + 0x1f & 0xffffffe0;
  *(int *)&this->field_0x38 = *(int *)&this->field_0x34 + *(int *)&this->field_0x3c;
  this->field_0x40 = 0xff;
  this_00 = (JKRAramBlock *)JKernel::operator_new(0x24,this->field_0x30,0);
  if (this_00 != (JKRAramBlock *)0x0) {
    JKRAramBlock::JKRAramBlock
              (this_00,*(ulong *)&this->field_0x34,0,*(ulong *)&this->field_0x3c,0xff,false);
  }
  JSUPtrList::append((JSUPtrList *)&sAramList,&this_00->field_0x4);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JKRAramHeap::~JKRAramHeap(void) */

void __thiscall JKRAramHeap::_JKRAramHeap(JKRAramHeap *this)

{
  int *piVar1;
  short in_r4;
  int **ppiVar2;
  int **ppiVar3;
  
  if (this != (JKRAramHeap *)0x0) {
    this->vtbl = &__vt;
    ppiVar3 = _sAramList;
    while (ppiVar3 != (int **)0x0) {
      ppiVar2 = (int **)ppiVar3[3];
      piVar1 = *ppiVar3;
      ppiVar3 = ppiVar2;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1,1);
      }
    }
    JKRDisposer::_JKRDisposer((JKRDisposer *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRAramHeap::alloc(unsigned long,
                                 JKRAramHeap::EAllocMode) */

undefined4 __thiscall JKRAramHeap::alloc(JKRAramHeap *this,ulong size,EAllocMode mode)

{
  undefined4 uVar1;
  
  os::OSLockMutex((OSMutex *)&this->field_0x18);
  if (mode == 0) {
    uVar1 = allocFromHead(this,size);
  }
  else {
    uVar1 = allocFromTail(this,size);
  }
  os::OSUnlockMutex(&this->field_0x18);
  return uVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JKRAramHeap::allocFromHead(unsigned long) */

undefined4 __thiscall JKRAramHeap::allocFromHead(JKRAramHeap *this,ulong size)

{
  uint uVar1;
  uint uVar2;
  JKRAramBlock *pJVar3;
  undefined4 uVar4;
  JKRAramBlock *this_00;
  JKRAramBlock *pJVar5;
  uint uVar6;
  
  uVar1 = size + 0x1f & 0xffffffe0;
  uVar6 = 0xffffffff;
  pJVar3 = (JKRAramBlock *)0x0;
  for (pJVar5 = _sAramList; this_00 = pJVar3, pJVar5 != (JKRAramBlock *)0x0;
      pJVar5 = (JKRAramBlock *)(pJVar5->field_0x4).mpPrev) {
    this_00 = *(JKRAramBlock **)pJVar5;
    uVar2 = this_00->field_0x1c;
    if (((uVar1 <= uVar2) && (uVar2 < uVar6)) && (pJVar3 = this_00, uVar6 = uVar2, uVar2 == uVar1))
    break;
  }
  if (this_00 == (JKRAramBlock *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = JKRAramBlock::allocHead(this_00,uVar1,this->field_0x40,this);
  }
  return uVar4;
}


/* __thiscall JKRAramHeap::allocFromTail(unsigned long) */

undefined4 __thiscall JKRAramHeap::allocFromTail(JKRAramHeap *this,ulong param_1)

{
  uint uVar1;
  undefined4 uVar2;
  JKRAramBlock *this_00;
  JKRAramBlock *pJVar3;
  
  uVar1 = param_1 + 0x1f & 0xffffffe0;
  for (pJVar3 = DAT_803ed738;
      (this_00 = (JKRAramBlock *)0x0, pJVar3 != (JKRAramBlock *)0x0 &&
      (this_00 = *(JKRAramBlock **)pJVar3, (uint)this_00->field_0x1c < uVar1));
      pJVar3 = (JKRAramBlock *)(pJVar3->field_0x4).mpList) {
  }
  if (this_00 == (JKRAramBlock *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = JKRAramBlock::allocTail(this_00,uVar1,this->field_0x40,this);
  }
  return uVar2;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JKRAramHeap::getFreeSize(void) */

uint __thiscall JKRAramHeap::getFreeSize(JKRAramHeap *this)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  os::OSLockMutex((OSMutex *)&this->field_0x18);
  for (piVar1 = _sAramList; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[3]) {
    if (uVar2 < *(uint *)(*piVar1 + 0x1c)) {
      uVar2 = *(uint *)(*piVar1 + 0x1c);
    }
  }
  os::OSUnlockMutex(&this->field_0x18);
  return uVar2;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JKRAramHeap::getTotalFreeSize(void) */

int __thiscall JKRAramHeap::getTotalFreeSize(JKRAramHeap *this)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  os::OSLockMutex((OSMutex *)&this->field_0x18);
  for (piVar1 = _sAramList; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[3]) {
    iVar2 = iVar2 + *(int *)(*piVar1 + 0x1c);
  }
  os::OSUnlockMutex(&this->field_0x18);
  return iVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JKRAramHeap::dump(void) */

void __thiscall JKRAramHeap::dump(JKRAramHeap *this)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  os::OSLockMutex((OSMutex *)&this->field_0x18);
  m_Do_printf::OSReport("\nJKRAramHeap dump\n");
  m_Do_printf::OSReport(" attr  address:   size    gid\n");
  iVar4 = 0;
  for (piVar3 = _sAramList; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[3]) {
    iVar2 = *piVar3;
    if (*(int *)(iVar2 + 0x18) != 0) {
      pcVar1 = "alloc";
      if (*(char *)(iVar2 + 0x21) != '\0') {
        pcVar1 = " temp";
      }
      m_Do_printf::OSReport
                ("%s %08x: %08x  %3d\n",pcVar1,*(undefined4 *)(iVar2 + 0x14),
                 *(undefined4 *)(iVar2 + 0x18),*(undefined *)(iVar2 + 0x20));
    }
    iVar2 = *piVar3;
    if (*(int *)(iVar2 + 0x1c) != 0) {
      m_Do_printf::OSReport
                (" free %08x: %08x    0\n",*(int *)(iVar2 + 0x14) + *(int *)(iVar2 + 0x18));
    }
    iVar4 = iVar4 + *(int *)(*piVar3 + 0x18);
  }
  m_Do_printf::OSReport
            ((double)(JKernel::_777 *
                     ((float)((double)CONCAT44(0x43300000,iVar4) - JKernel::_779) /
                     (float)((double)CONCAT44(0x43300000,*(undefined4 *)&this->field_0x3c) -
                            JKernel::_779))),"%d / %d bytes (%6.2f%%) used\n",iVar4);
  os::OSUnlockMutex(&this->field_0x18);
  return;
}


namespace JKernel {

void __sinit_JKRAramHeap_cpp(void)

{
  JSUPtrList::initiate((JSUPtrList *)&::JKRAramHeap::sAramList);
  Runtime.PPCEABI.H::__register_global_object
            (&::JKRAramHeap::sAramList,::JSUList<JKRAramBlock>::_JSUList,&_283);
  return;
}

}

/* __thiscall JSUList<JKRAramBlock>::~JSUList(void) */

JSUList_JKRAramBlock_ * __thiscall JSUList<JKRAramBlock>::_JSUList(JSUList_JKRAramBlock_ *this)

{
  short in_r4;
  
  if ((this != (JSUList_JKRAramBlock_ *)0x0) &&
     (JSUPtrList::_JSUPtrList((JSUPtrList *)this), 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return this;
}

