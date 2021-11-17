#include <SComponent/c_list.h>
#include <SComponent/c_node.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <SComponent/c_list.h>


namespace SComponent {

/* __stdcall cLs_Init(node_list_class *) */

void cLs_Init(node_list_class *param_1)

{
  param_1->mpHead = (node_class *)0x0;
  param_1->mpTail = (node_class *)0x0;
  param_1->mSize = 0;
  return;
}


/* __stdcall cLs_SingleCut(node_class *) */

void * cLs_SingleCut(node_class *param_1)

{
  uint uVar1;
  node_list_class *pnVar2;
  
  pnVar2 = (node_list_class *)param_1->mpData;
  if (param_1 == pnVar2->mpHead) {
    pnVar2->mpHead = param_1->mpNextNode;
  }
  if (param_1 == pnVar2->mpTail) {
    pnVar2->mpTail = param_1->mpPrevNode;
  }
  cNd_SingleCut(param_1);
  cNd_ClearObject(param_1);
  uVar1 = pnVar2->mSize - 1;
  pnVar2->mSize = uVar1;
  return (void *)((-uVar1 & ~uVar1) >> 0x1f);
}


/* __stdcall cLs_Addition(node_list_class *,
                          node_class *) */

int cLs_Addition(node_list_class *param_1,node_class *param_2)

{
  node_class *pnVar1;
  int iVar2;
  
  if (param_1->mpTail == (node_class *)0x0) {
    param_1->mpHead = param_2;
  }
  else {
    cNd_Addition(param_1->mpTail,param_2);
  }
  pnVar1 = cNd_Last(param_2);
  param_1->mpTail = pnVar1;
  cNd_SetObject(param_2,param_1);
  iVar2 = cNd_LengthOf(param_1->mpHead);
  param_1->mSize = iVar2;
  return param_1->mSize;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall cLs_Insert(node_list_class *,
                        int,
                        node_class *) */

int cLs_Insert(node_list_class *param_1,int param_2,node_class *param_3)

{
  node_class *pnVar1;
  int iVar2;
  
  pnVar1 = cNd_Order(param_1->mpHead,param_2);
  if (pnVar1 == (node_class *)0x0) {
    iVar2 = cLs_Addition(param_1,param_3);
  }
  else {
    cNd_SetObject(param_3,param_1);
    cNd_Insert(pnVar1,param_3);
    pnVar1 = cNd_First(param_3);
    param_1->mpHead = pnVar1;
    iVar2 = cNd_LengthOf(param_1->mpHead);
    param_1->mSize = iVar2;
    iVar2 = param_1->mSize;
  }
  return iVar2;
}


/* __stdcall cLs_GetFirst(node_list_class *) */

node_class * cLs_GetFirst(node_list_class *pList)

{
  node_class *pnVar1;
  
  if (pList->mSize == 0) {
    pnVar1 = (node_class *)0x0;
  }
  else {
    pnVar1 = pList->mpHead;
    cLs_SingleCut(pnVar1);
  }
  return pnVar1;
}


/* __stdcall cLs_Create(node_list_class *) */

void * cLs_Create(node_list_class *param_1)

{
  cLs_Init(param_1);
  return param_1;
}

