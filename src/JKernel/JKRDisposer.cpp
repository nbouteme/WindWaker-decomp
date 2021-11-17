#include <JKernel/JKRDisposer.h>
#include <JSupport/JSUList.h>
#include <JKernel/JKRHeap.h>
#include <JKRDisposer.h>


/* __thiscall JKRDisposer::JKRDisposer(void) */

void __thiscall JKRDisposer::JKRDisposer(JKRDisposer *this)

{
  JKRHeap *pJVar1;
  
  this->vtbl = (JKRArchive__vtbl *)&__vt;
  JSUPtrLink::JSUPtrLink(&this->mHeapLink,this);
  pJVar1 = JKRHeap::findFromRoot(this);
  this->mpHeap = pJVar1;
  if (this->mpHeap != (JKRHeap *)0x0) {
    JSUPtrList::append(&this->mpHeap->mList,&this->mHeapLink);
  }
  return;
}


/* __thiscall JKRDisposer::~JKRDisposer(void) */

void __thiscall JKRDisposer::_JKRDisposer(JKRDisposer *this)

{
  short in_r4;
  
  if (this != (JKRDisposer *)0x0) {
    this->vtbl = (JKRArchive__vtbl *)&__vt;
    if (this->mpHeap != (JKRHeap *)0x0) {
      JSUPtrList::remove(&this->mpHeap->mList,&this->mHeapLink);
    }
    if (this != (JKRDisposer *)&DAT_fffffff8) {
      JSUPtrLink::_JSUPtrLink(&this->mHeapLink);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

