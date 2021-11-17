#include <SComponent/c_node.h>
#include <SComponent/c_node.h>
#include <Runtime.PPCEABI.H/runtime.h>


namespace SComponent {

/* __stdcall cNd_Join(node_class *,
                      node_class *) */

void cNd_Join(node_class *param_1,node_class *param_2)

{
  param_1->mpNextNode = param_2;
  param_2->mpPrevNode = param_1;
  return;
}


/* __stdcall cNd_LengthOf(node_class *) */

int cNd_LengthOf(node_class *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while (param_1 != (node_class *)0x0) {
    iVar1 = iVar1 + 1;
    if (param_1 == (node_class *)0x0) {
      param_1 = (node_class *)0x0;
    }
    else {
      param_1 = param_1->mpNextNode;
    }
  }
  return iVar1;
}


/* __stdcall cNd_First(node_class *) */

node_class * cNd_First(node_class *param_1)

{
  node_class *pnVar1;
  
  pnVar1 = (node_class *)0x0;
  while (param_1 != (node_class *)0x0) {
    pnVar1 = param_1;
    if (param_1 == (node_class *)0x0) {
      param_1 = (node_class *)0x0;
    }
    else {
      param_1 = param_1->mpPrevNode;
    }
  }
  return pnVar1;
}


/* __stdcall cNd_Last(node_class *) */

node_class * cNd_Last(node_class *param_1)

{
  node_class *pnVar1;
  
  pnVar1 = (node_class *)0x0;
  while (param_1 != (node_class *)0x0) {
    pnVar1 = param_1;
    if (param_1 == (node_class *)0x0) {
      param_1 = (node_class *)0x0;
    }
    else {
      param_1 = param_1->mpNextNode;
    }
  }
  return pnVar1;
}


/* __stdcall cNd_Order(node_class *,
                       int) */

node_class * cNd_Order(node_class *param_1,int param_2)

{
  node_class *pnVar1;
  int iVar2;
  
  iVar2 = 0;
  pnVar1 = (node_class *)0x0;
  while ((iVar2 < param_2 && (param_1 != (node_class *)0x0))) {
    iVar2 = iVar2 + 1;
    pnVar1 = param_1;
    if (param_1 == (node_class *)0x0) {
      param_1 = (node_class *)0x0;
    }
    else {
      param_1 = param_1->mpNextNode;
    }
  }
  if (iVar2 < param_2) {
    return pnVar1;
  }
  return (node_class *)0x0;
}


/* __stdcall cNd_SingleCut(node_class *) */

void cNd_SingleCut(node_class *param_1)

{
  node_class *pnVar1;
  
  pnVar1 = param_1->mpNextNode;
  if (param_1->mpPrevNode != (node_class *)0x0) {
    param_1->mpPrevNode->mpNextNode = pnVar1;
  }
  if (pnVar1 != (node_class *)0x0) {
    pnVar1->mpPrevNode = param_1->mpPrevNode;
  }
  param_1->mpPrevNode = (node_class *)0x0;
  param_1->mpNextNode = (node_class *)0x0;
  return;
}


/* __stdcall cNd_Cut(node_class *) */

void cNd_Cut(node_class *param_1)

{
  if (param_1->mpPrevNode != (node_class *)0x0) {
    param_1->mpPrevNode->mpNextNode = (node_class *)0x0;
  }
  param_1->mpPrevNode = (node_class *)0x0;
  return;
}


/* __stdcall cNd_Addition(node_class *,
                          node_class *) */

void cNd_Addition(node_class *param_1,node_class *param_2)

{
  node_class *pnVar1;
  
  pnVar1 = cNd_Last(param_1);
  cNd_Join(pnVar1,param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall cNd_Insert(node_class *,
                        node_class *) */

void cNd_Insert(node_class *param_1,node_class *param_2)

{
  node_class *pnVar1;
  
  pnVar1 = param_1->mpPrevNode;
  if (pnVar1 == (node_class *)0x0) {
    cNd_Addition(param_2,param_1);
  }
  else {
    cNd_Cut(param_1);
    cNd_Addition(pnVar1,param_2);
    cNd_Addition(param_2,param_1);
  }
  return;
}


/* __stdcall cNd_SetObject(node_class *,
                           void *) */

void cNd_SetObject(node_class *param_1,void *param_2)

{
  while (param_1 != (node_class *)0x0) {
    param_1->mpData = (undefined *)param_2;
    if (param_1 == (node_class *)0x0) {
      param_1 = (node_class *)0x0;
    }
    else {
      param_1 = param_1->mpNextNode;
    }
  }
  return;
}


/* __stdcall cNd_ClearObject(node_class *) */

void cNd_ClearObject(node_class *param_1)

{
  cNd_SetObject(param_1,(void *)0x0);
  return;
}


/* __stdcall cNd_ForcedClear(node_class *) */

void cNd_ForcedClear(node_class *param_1)

{
  param_1->mpPrevNode = (node_class *)0x0;
  param_1->mpNextNode = (node_class *)0x0;
  param_1->mpData = (undefined *)0x0;
  return;
}


/* __stdcall cNd_Create(node_class *,
                        void *) */

void cNd_Create(node_class *param_1,void *param_2)

{
  param_1->mpPrevNode = (node_class *)0x0;
  param_1->mpNextNode = (node_class *)0x0;
  param_1->mpData = (undefined *)param_2;
  return;
}

