#pragma once
#include <ctypes.h>



namespace SComponent {
void cLs_Init(node_list_class *param_1);
void * cLs_SingleCut(node_class *param_1);
int cLs_Addition(node_list_class *param_1,node_class *param_2);
int cLs_Insert(node_list_class *param_1,int param_2,node_class *param_3);
node_class * cLs_GetFirst(node_list_class *pList);
void * cLs_Create(node_list_class *param_1);
}
