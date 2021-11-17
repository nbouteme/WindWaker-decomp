#include <JGadget/linklist.h>
#include <JKernel/JKRHeap.h>
#include <JGadget/linklist.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JGadget/TNodeLinkList.h>


namespace JGadget {

/* __thiscall TNodeLinkList::~TNodeLinkList(void) */

void __thiscall TNodeLinkList::_TNodeLinkList(TNodeLinkList *this)

{
  short in_r4;
  
  if ((this != (TNodeLinkList *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall TNodeLinkList::erase(TNodeLinkList::iterator) */

void __thiscall TNodeLinkList::erase(TNodeLinkList *this,iterator param_1)

{
  undefined4 *in_r5;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = *in_r5;
  local_c = local_10;
  erase(this,param_1,(iterator)&local_10);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall TNodeLinkList::erase(TNodeLinkList::iterator,
                                            TNodeLinkList::iterator) */

void __thiscall TNodeLinkList::erase(TNodeLinkList *this,iterator param_1,iterator param_2)

{
  int *piVar1;
  int *in_r6;
  int iVar2;
  TNodeLinkList aTStack40 [20];
  
  piVar1 = *(int **)param_2;
  iVar2 = *in_r6;
  while (piVar1 != (int *)iVar2) {
    piVar1 = (int *)*piVar1;
    Erase(aTStack40,(TLinkListNode *)param_1);
  }
  *(int *)this = *in_r6;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TNodeLinkList::splice(TNodeLinkList::iterator,
                                             TNodeLinkList &,
                                             TNodeLinkList::iterator) */

ssize_t __thiscall
TNodeLinkList::splice
          (TNodeLinkList *this,int __fdin,__off64_t *__offin,int __fdout,__off64_t *__offout,
          size_t __len,uint __flags)

{
  undefined4 local_30;
  TNodeLinkList aTStack44 [4];
  TNodeLinkList aTStack40 [4];
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  
  local_1c = *(int **)__fdout;
  local_24 = (int *)*local_1c;
  local_20 = *(int **)__fdin;
  if ((local_20 != local_1c) && (local_20 != local_24)) {
    local_18 = local_20;
    local_14 = local_1c;
    Erase(aTStack40,(TLinkListNode *)__offin);
    local_30 = *(undefined4 *)__fdin;
    local_24 = (int *)Insert(aTStack44,(iterator)this,(TLinkListNode *)&local_30);
  }
  return (ssize_t)local_24;
}


/* __thiscall TNodeLinkList::Find(TLinkListNode const *) */

void __thiscall TNodeLinkList::Find(TNodeLinkList *this,TLinkListNode *param_1)

{
  uint uVar1;
  undefined4 *in_r5;
  undefined4 *local_c;
  
  local_c = *(undefined4 **)(param_1 + 4);
  while( true ) {
    uVar1 = countLeadingZeros(param_1 + (4 - (int)local_c));
    if (((uVar1 >> 5 & 0xff) != 0) || (local_c == in_r5)) break;
    local_c = (undefined4 *)*local_c;
  }
  *(undefined4 **)this = local_c;
  return;
}


/* __thiscall TNodeLinkList::Insert(TNodeLinkList::iterator,
                                             TLinkListNode *) */

void __thiscall
TNodeLinkList::Insert(TNodeLinkList *this,iterator param_1,TLinkListNode *param_2)

{
  int iVar1;
  int *in_r6;
  int **ppiVar2;
  
  iVar1 = *(int *)param_2;
  ppiVar2 = *(int ***)(iVar1 + 4);
  *in_r6 = iVar1;
  in_r6[1] = (int)ppiVar2;
  *(int **)(iVar1 + 4) = in_r6;
  *ppiVar2 = in_r6;
  *(int *)param_1 = *(int *)param_1 + 1;
  *(int **)this = in_r6;
  return;
}


/* __thiscall TNodeLinkList::Erase(TLinkListNode *) */

void __thiscall TNodeLinkList::Erase(TNodeLinkList *this,TLinkListNode *param_1)

{
  int *in_r5;
  int *piVar1;
  int iVar2;
  
  iVar2 = *in_r5;
  piVar1 = (int *)in_r5[1];
  *(int **)(iVar2 + 4) = piVar1;
  *piVar1 = iVar2;
  *(int *)param_1 = *(int *)param_1 + -1;
  *(int *)this = iVar2;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall TNodeLinkList::Remove(TLinkListNode *) */

void __thiscall TNodeLinkList::Remove(TNodeLinkList *this,TLinkListNode *param_1)

{
  undefined4 *puVar1;
  __off64_t *in_r7;
  size_t in_r8;
  uint in_r9;
  undefined4 *local_48;
  undefined4 ***local_40;
  undefined4 ***local_3c;
  undefined4 *local_38;
  undefined4 *local_34;
  undefined4 *local_30;
  undefined4 *local_2c;
  TLinkListNode *local_28;
  TLinkListNode *local_24;
  undefined4 local_20;
  undefined4 ***local_1c;
  undefined4 ***local_18;
  
  local_20 = 0;
  local_48 = *(undefined4 **)(this + 4);
  local_28 = param_1;
  local_24 = param_1;
  local_1c = &local_1c;
  local_18 = &local_1c;
  while( true ) {
    local_34 = local_48;
    local_2c = local_48;
    local_30 = local_48;
    if (local_48 == (undefined4 *)(this + 4)) break;
    if (local_48 == (undefined4 *)param_1) {
      puVar1 = (undefined4 *)*local_48;
      local_38 = local_48;
      local_40 = &local_1c;
      local_3c = &local_1c;
      local_30 = local_34;
      local_2c = local_34;
      splice((TNodeLinkList *)&local_20,(int)&local_40,(__off64_t *)this,(int)&local_38,in_r7,in_r8,
             in_r9);
      local_48 = puVar1;
    }
    else {
      local_48 = (undefined4 *)*local_48;
    }
  }
  _TNodeLinkList((TNodeLinkList *)&local_20);
  return;
}

