#include <SComponent/c_tag.h>
#include <SComponent/c_tree.h>
#include <SComponent/c_list.h>
#include <SComponent/c_node.h>


namespace SComponent {

/* __stdcall cTg_IsUse(create_tag_class *) */

int cTg_IsUse(create_tag_class *param_1)

{
  return (int)(char)param_1->mbAdded;
}


/* __stdcall cTg_SingleCutFromTree(create_tag_class *) */

bool cTg_SingleCutFromTree(create_tag_class *param_1)

{
  bool bVar1;
  
  bVar1 = param_1->mbAdded == 1;
  if (bVar1) {
    param_1->mbAdded = 0;
    cTr_SingleCut(&param_1->parent);
  }
  return bVar1;
}


/* __stdcall cTg_AdditionToTree(node_lists_tree_class *,
                                int,
                                create_tag_class *) */

int cTg_AdditionToTree
              (node_lists_tree_class *param_1,int param_2,create_tag_class *param_3)

{
  int iVar1;
  
  if ((param_3->mbAdded == 0) &&
     (iVar1 = cTr_Addition(param_1,param_2,&param_3->parent), iVar1 != 0)) {
    param_3->mbAdded = 1;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


/* __stdcall cTg_InsertToTree(node_lists_tree_class *,
                              int,
                              create_tag_class *,
                              int) */

int cTg_InsertToTree
              (node_lists_tree_class *param_1,int param_2,create_tag_class *param_3,int param_4)

{
  int iVar1;
  
  if ((param_3->mbAdded == 0) &&
     (iVar1 = cTr_Insert(param_1,param_2,&param_3->parent,param_4), iVar1 != 0)) {
    param_3->mbAdded = 1;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


/* __stdcall cTg_GetFirst(node_list_class *) */

create_tag_class * cTg_GetFirst(node_list_class *param_1)

{
  create_tag_class *pTag;
  
  pTag = (create_tag_class *)cLs_GetFirst(param_1);
  if (pTag == (create_tag_class *)0x0) {
    pTag = (create_tag_class *)0x0;
  }
  else {
    pTag->mbAdded = 0;
  }
  return pTag;
}


/* __stdcall cTg_SingleCut(create_tag_class *) */

int cTg_SingleCut(create_tag_class *param_1)

{
  bool bVar1;
  
  bVar1 = param_1->mbAdded == 1;
  if (bVar1) {
    param_1->mbAdded = 0;
    cLs_SingleCut(&param_1->parent);
  }
  return (uint)bVar1;
}


/* __stdcall cTg_Addition(node_list_class *,
                          create_tag_class *) */

int cTg_Addition(node_list_class *param_1,create_tag_class *param_2)

{
  int iVar1;
  
  if ((param_2->mbAdded == 0) && (iVar1 = cLs_Addition(param_1,&param_2->parent), iVar1 != 0)) {
    param_2->mbAdded = 1;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


/* __stdcall cTg_Create(create_tag_class *,
                        void *) */

void cTg_Create(create_tag_class *param_1,void *param_2)

{
  cNd_Create(&param_1->parent,(void *)0x0);
  param_1->mpTagData = (create_request *)param_2;
  param_1->mbAdded = 0;
  return;
}

