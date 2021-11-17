#pragma once
#include <ctypes.h>



namespace SComponent {
int cTg_IsUse(create_tag_class *param_1);
bool cTg_SingleCutFromTree(create_tag_class *param_1);
int cTg_AdditionToTree(node_lists_tree_class *param_1,int param_2,create_tag_class *param_3);
int cTg_InsertToTree(node_lists_tree_class *param_1,int param_2,create_tag_class *param_3,int param_4);
create_tag_class * cTg_GetFirst(node_list_class *param_1);
int cTg_SingleCut(create_tag_class *param_1);
int cTg_Addition(node_list_class *param_1,create_tag_class *param_2);
void cTg_Create(create_tag_class *param_1,void *param_2);
}
