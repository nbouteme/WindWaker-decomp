#include <SComponent/c_node_iter.h>
#include <Runtime.PPCEABI.H/runtime.h>


namespace SComponent {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall cNdIt_Method(node_class *,
                          int *(node_class *,void *),
                          void *) */

undefined4 cNdIt_Method(node_class *param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  node_class *pnVar2;
  undefined4 uVar3;
  
  uVar3 = 1;
  if (param_1 == (node_class *)0x0) {
    pnVar2 = (node_class *)0x0;
  }
  else {
    pnVar2 = param_1->mpNextNode;
  }
  while (param_1 != (node_class *)0x0) {
    iVar1 = (*param_2)(param_1,param_3);
    if (iVar1 == 0) {
      uVar3 = 0;
    }
    param_1 = pnVar2;
    if (pnVar2 == (node_class *)0x0) {
      pnVar2 = (node_class *)0x0;
    }
    else {
      pnVar2 = pnVar2->mpNextNode;
    }
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall cNdIt_Judge(node_class *,
                         void * *(node_class *,void *),
                         void *) */

int cNdIt_Judge(node_class *param_1,undefined *param_2,void *param_3)

{
  int iVar1;
  node_class *pnVar2;
  
  if (param_1 == (node_class *)0x0) {
    pnVar2 = (node_class *)0x0;
  }
  else {
    pnVar2 = param_1->mpNextNode;
  }
  while( true ) {
    if (param_1 == (node_class *)0x0) {
      return 0;
    }
    iVar1 = (*(code *)param_2)(param_1,param_3);
    if (iVar1 != 0) break;
    param_1 = pnVar2;
    if (pnVar2 == (node_class *)0x0) {
      pnVar2 = (node_class *)0x0;
    }
    else {
      pnVar2 = pnVar2->mpNextNode;
    }
  }
  return iVar1;
}

