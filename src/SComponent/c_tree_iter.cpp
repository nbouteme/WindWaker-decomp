#include <SComponent/c_tree_iter.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <SComponent/c_list_iter.h>


namespace SComponent {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall cTrIt_Method(node_lists_tree_class *,
                          int *(node_class *,void *),
                          void *) */

undefined4
cTrIt_Method(node_lists_tree_class *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  node_list_class *pnVar5;
  node_list_class *pnVar6;
  
  iVar4 = param_1->mNumLists;
  uVar3 = 1;
  pnVar6 = param_1->mpLists;
  while (bVar1 = 0 < iVar4, iVar4 = iVar4 + -1, bVar1) {
    pnVar5 = pnVar6 + 1;
    iVar2 = cLsIt_Method(pnVar6,param_2,param_3);
    pnVar6 = pnVar5;
    if (iVar2 == 0) {
      uVar3 = 0;
    }
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall cTrIt_Judge(node_lists_tree_class *,
                         void * *(node_class *,void *),
                         void *) */

void * cTrIt_Judge(node_lists_tree_class *pTree,undefined *param_2,void *param_3)

{
  bool bVar1;
  void *pvVar2;
  int iVar3;
  node_list_class *pnVar4;
  
  iVar3 = pTree->mNumLists;
  pnVar4 = pTree->mpLists;
  do {
    bVar1 = iVar3 < 1;
    iVar3 = iVar3 + -1;
    if (bVar1) {
      return (void *)0x0;
    }
    pvVar2 = cLsIt_Judge(pnVar4,param_2,param_3);
    pnVar4 = pnVar4 + 1;
  } while (pvVar2 == (void *)0x0);
  return pvVar2;
}

