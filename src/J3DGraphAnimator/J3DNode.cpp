#include <J3DGraphAnimator/J3DNode.h>
#include <JKernel/JKRHeap.h>
#include <Demangler/J3DNode.h>


/* __thiscall J3DNode::J3DNode(void) */

void __thiscall J3DNode::J3DNode(J3DNode *this)

{
  this->vtbl = &__vt;
  this->field_0x4 = (undefined *)0x0;
  this->mpCalcCallBack = (undefined *)0x0;
  this->mpFirstChild = (J3DNode *)0x0;
  this->mpNextSibling = (J3DNode *)0x0;
  return;
}


/* __thiscall J3DNode::~J3DNode(void) */

void __thiscall J3DNode::_J3DNode(J3DNode *this,short param_1)

{
  if ((this != (J3DNode *)0x0) && (this->vtbl = &__vt, 0 < param_1)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall J3DNode::appendChild(J3DNode *) */

void __thiscall J3DNode::appendChild(J3DNode *this,J3DNode *param_1)

{
  J3DNode *pJVar1;
  J3DNode *pJVar2;
  
  pJVar1 = this->mpFirstChild;
  if (this->mpFirstChild != (J3DNode *)0x0) {
    do {
      pJVar2 = pJVar1;
      pJVar1 = pJVar2->mpNextSibling;
    } while (pJVar1 != (J3DNode *)0x0);
    pJVar2->mpNextSibling = param_1;
    return;
  }
  this->mpFirstChild = param_1;
  return;
}


/* __thiscall J3DNode::entryIn(void) */

void __thiscall J3DNode::entryIn(J3DNode *this)

{
  return;
}

