#include <JKernel/JKRAramBlock.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JSupport/JSUList.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRAramBlock.h>
#include <Demangler/JKRAramBlock.h>


namespace JKRAramBlock {
}

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall JKRAramBlock::JKRAramBlock(unsigned long,
                                         unsigned long,
                                         unsigned long,
                                         unsigned char,
                                         bool) */

void __thiscall
JKRAramBlock::JKRAramBlock
          (JKRAramBlock *this,ulong param_1,ulong param_2,ulong param_3,uchar param_4,bool param_5)

{
  *(undefined1 **)this = &__vt;
  JSUPtrLink::JSUPtrLink(&this->field_0x4,this);
  this->field_0x14 = param_1;
  this->field_0x18 = param_2;
  this->field_0x1c = param_3;
  *(uchar *)&this->field_0x20 = param_4;
  *(bool *)&this->field_0x21 = param_5;
  return;
}


/* __thiscall JKRAramBlock::~JKRAramBlock(void) */

void __thiscall JKRAramBlock::_JKRAramBlock(JKRAramBlock *this)

{
  JSUPtrList *this_00;
  short in_r4;
  JSUPtrLink *pJVar1;
  undefined *puVar2;
  
  if (this != (JKRAramBlock *)0x0) {
    *(undefined1 **)this = &__vt;
    this_00 = (this->field_0x4).mpList;
    pJVar1 = (this->field_0x4).mpPrev;
    if (pJVar1 == (JSUPtrLink *)0x0) {
      this->field_0x1c = this->field_0x1c + this->field_0x18;
      this->field_0x18 = 0;
    }
    else {
      puVar2 = pJVar1->mpData;
      *(int *)(puVar2 + 0x1c) = this->field_0x18 + this->field_0x1c + *(int *)(puVar2 + 0x1c);
      JSUPtrList::remove(this_00,&this->field_0x4);
    }
    if (this != (JKRAramBlock *)0xfffffffc) {
      JSUPtrLink::_JSUPtrLink(&this->field_0x4);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall JKRAramBlock::allocHead(unsigned long,
                                      unsigned char,
                                      JKRAramHeap *) */

JKRAramBlock * __thiscall
JKRAramBlock::allocHead(JKRAramBlock *this,ulong param_1,uchar param_2,JKRAramHeap *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  JKRAramBlock *newBlock;
  
  iVar3 = this->field_0x14;
  iVar1 = this->field_0x18;
  iVar2 = this->field_0x1c;
  newBlock = (JKRAramBlock *)JKernel::operator_new(0x24,param_3->field_0x30,0);
  if (newBlock != (JKRAramBlock *)0x0) {
    JKRAramBlock(newBlock,iVar3 + iVar1,param_1,iVar2 - param_1,param_2,false);
  }
  this->field_0x1c = 0;
  JSUPtrList::insert((this->field_0x4).mpList,(this->field_0x4).mpNext,&newBlock->field_0x4);
  return newBlock;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JKRAramBlock::allocTail(unsigned long,
                                      unsigned char,
                                      JKRAramHeap *) */

JKRAramBlock * __thiscall
JKRAramBlock::allocTail(JKRAramBlock *this,ulong param_1,uchar param_2,JKRAramHeap *param_3)

{
  int iVar1;
  int iVar2;
  JKRAramBlock *this_00;
  int iVar3;
  
  iVar3 = this->field_0x1c;
  iVar2 = this->field_0x14;
  iVar1 = this->field_0x18;
  this_00 = (JKRAramBlock *)JKernel::operator_new(0x24,param_3->field_0x30,0);
  if (this_00 != (JKRAramBlock *)0x0) {
    JKRAramBlock(this_00,(iVar2 + iVar1 + iVar3) - param_1,param_1,0,param_2,true);
  }
  this->field_0x1c = this->field_0x1c - param_1;
  JSUPtrList::insert((this->field_0x4).mpList,(this->field_0x4).mpNext,&this_00->field_0x4);
  return this_00;
}

