#include <SComponent/c_tree.h>
#include <SComponent/c_list.h>


namespace SComponent {

/* __stdcall cTr_SingleCut(node_class *) */

void cTr_SingleCut(node_class *param_1)

{
  cLs_SingleCut(param_1);
  return;
}


/* __stdcall cTr_Addition(node_lists_tree_class *,
                          int,
                          node_class *) */

int cTr_Addition(node_lists_tree_class *param_1,int param_2,node_class *param_3)

{
  int iVar1;
  
  if (param_2 < param_1->mNumLists) {
    iVar1 = cLs_Addition(param_1->mpLists + param_2,param_3);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


/* __stdcall cTr_Insert(node_lists_tree_class *,
                        int,
                        node_class *,
                        int) */

int cTr_Insert
              (node_lists_tree_class *param_1,int param_2,node_class *param_3,int param_4)

{
  int iVar1;
  
  if (param_2 < param_1->mNumLists) {
    iVar1 = cLs_Insert(param_1->mpLists + param_2,param_4,param_3);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


/* __stdcall cTr_Create(node_lists_tree_class *,
                        node_list_class *,
                        int) */

void cTr_Create(node_lists_tree_class *param_1,node_list_class *param_2,int param_3)

{
  bool bVar1;
  
  param_1->mpLists = param_2;
  param_1->mNumLists = param_3;
  while (bVar1 = 0 < param_3, param_3 = param_3 + -1, bVar1) {
    cLs_Create(param_2);
    param_2 = param_2 + 1;
  }
  return;
}

