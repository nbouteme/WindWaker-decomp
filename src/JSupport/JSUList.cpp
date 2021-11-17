#include <JSupport/JSUList.h>
#include <JSupport/JSUList.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JSUPtrLink.h>
#include <JSUPtrList.h>


/* __thiscall JSUPtrLink::JSUPtrLink(void *) */

void __thiscall JSUPtrLink::JSUPtrLink(JSUPtrLink *this,void *param_1)

{
  this->mpList = (JSUPtrList *)0x0;
  this->mpData = (undefined *)param_1;
  this->mpPrev = (JSUPtrLink *)0x0;
  this->mpNext = (JSUPtrLink *)0x0;
  return;
}


/* __thiscall JSUPtrLink::~JSUPtrLink(void) */

void __thiscall JSUPtrLink::_JSUPtrLink(JSUPtrLink *this)

{
  short in_r4;
  
  if (this != (JSUPtrLink *)0x0) {
    if (this->mpList != (JSUPtrList *)0x0) {
      JSUPtrList::remove(this->mpList,this);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JSUPtrList::JSUPtrList(bool) */

void __thiscall JSUPtrList::JSUPtrList(JSUPtrList *this,bool param_1)

{
  if (param_1 != false) {
    initiate(this);
  }
  return;
}


/* __thiscall JSUPtrList::~JSUPtrList(void) */

void __thiscall JSUPtrList::_JSUPtrList(JSUPtrList *this)

{
  short in_r4;
  JSUPtrLink *pJVar1;
  uint uVar2;
  
  if (this != (JSUPtrList *)0x0) {
    pJVar1 = this->mpHead;
    uVar2 = 0;
    while( true ) {
      if ((uint)this->mCount <= uVar2) break;
      pJVar1->mpList = (JSUPtrList *)0x0;
      pJVar1 = pJVar1->mpNext;
      uVar2 = uVar2 + 1;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JSUPtrList::initiate(void) */

void __thiscall JSUPtrList::initiate(JSUPtrList *this)

{
  this->mpHead = (JSUPtrLink *)0x0;
  this->mpTail = (JSUPtrLink *)0x0;
  this->mCount = 0;
  return;
}


/* __thiscall JSUPtrList::setFirst(JSUPtrLink *) */

void __thiscall JSUPtrList::setFirst(JSUPtrList *this,JSUPtrLink *param_1)

{
  param_1->mpList = this;
  param_1->mpPrev = (JSUPtrLink *)0x0;
  param_1->mpNext = (JSUPtrLink *)0x0;
  this->mpTail = param_1;
  this->mpHead = param_1;
  this->mCount = 1;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JSUPtrList::append(JSUPtrLink *) */

uint __thiscall JSUPtrList::append(JSUPtrList *this,JSUPtrLink *pLink)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = countLeadingZeros(pLink->mpList);
  uVar2 = uVar1 >> 5;
  if ((uVar1 >> 5 & 0xff) == 0) {
    uVar2 = remove(pLink->mpList,pLink);
  }
  if ((uVar2 & 0xff) != 0) {
    if (this->mCount == 0) {
      setFirst(this,pLink);
    }
    else {
      pLink->mpList = this;
      pLink->mpPrev = this->mpTail;
      pLink->mpNext = (JSUPtrLink *)0x0;
      this->mpTail->mpNext = pLink;
      this->mpTail = pLink;
      this->mCount = this->mCount + 1;
    }
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JSUPtrList::prepend(JSUPtrLink *) */

uint __thiscall JSUPtrList::prepend(JSUPtrList *this,JSUPtrLink *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = countLeadingZeros(param_1->mpList);
  uVar2 = uVar1 >> 5;
  if ((uVar1 >> 5 & 0xff) == 0) {
    uVar2 = remove(param_1->mpList,param_1);
  }
  if ((uVar2 & 0xff) != 0) {
    if (this->mCount == 0) {
      setFirst(this,param_1);
    }
    else {
      param_1->mpList = this;
      param_1->mpPrev = (JSUPtrLink *)0x0;
      param_1->mpNext = this->mpHead;
      this->mpHead->mpPrev = param_1;
      this->mpHead = param_1;
      this->mCount = this->mCount + 1;
    }
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JSUPtrList::insert(JSUPtrLink *,
                                 JSUPtrLink *) */

uint __thiscall JSUPtrList::insert(JSUPtrList *this,JSUPtrLink *param_1,JSUPtrLink *param_2)

{
  uint uVar1;
  uint uVar2;
  JSUPtrLink *pJVar3;
  
  if (param_1 == this->mpHead) {
    uVar2 = prepend(this,param_2);
  }
  else {
    if (param_1 == (JSUPtrLink *)0x0) {
      uVar2 = append(this,param_2);
    }
    else {
      if (param_1->mpList == this) {
        uVar1 = countLeadingZeros(param_2->mpList);
        uVar2 = uVar1 >> 5;
        if ((uVar1 >> 5 & 0xff) == 0) {
          uVar2 = remove(param_2->mpList,param_2);
        }
        if ((uVar2 & 0xff) != 0) {
          pJVar3 = param_1->mpPrev;
          param_2->mpList = this;
          param_2->mpPrev = pJVar3;
          param_2->mpNext = param_1;
          pJVar3->mpNext = param_2;
          param_1->mpPrev = param_2;
          this->mCount = this->mCount + 1;
        }
      }
      else {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}


/* __thiscall JSUPtrList::remove(JSUPtrLink *) */

int __thiscall JSUPtrList::remove(JSUPtrList *this,JSUPtrLink *param_1)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros((int)this - (int)param_1->mpList);
  if ((uVar1 >> 5 & 0xff) != 0) {
    if (this->mCount == 1) {
      this->mpHead = (JSUPtrLink *)0x0;
      this->mpTail = (JSUPtrLink *)0x0;
    }
    else {
      if (param_1 == this->mpHead) {
        param_1->mpNext->mpPrev = (JSUPtrLink *)0x0;
        this->mpHead = param_1->mpNext;
      }
      else {
        if (param_1 == this->mpTail) {
          param_1->mpPrev->mpNext = (JSUPtrLink *)0x0;
          this->mpTail = param_1->mpPrev;
        }
        else {
          param_1->mpPrev->mpNext = param_1->mpNext;
          param_1->mpNext->mpPrev = param_1->mpPrev;
        }
      }
    }
    param_1->mpList = (JSUPtrList *)0x0;
    this->mCount = this->mCount + -1;
  }
  return uVar1 >> 5;
}

