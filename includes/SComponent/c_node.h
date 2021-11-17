#pragma once
#include <ctypes.h>



namespace SComponent {
void cNd_Join(node_class *param_1,node_class *param_2);
int cNd_LengthOf(node_class *param_1);
node_class * cNd_First(node_class *param_1);
node_class * cNd_Last(node_class *param_1);
node_class * cNd_Order(node_class *param_1,int param_2);
void cNd_SingleCut(node_class *param_1);
void cNd_Cut(node_class *param_1);
void cNd_Addition(node_class *param_1,node_class *param_2);
void cNd_Insert(node_class *param_1,node_class *param_2);
void cNd_SetObject(node_class *param_1,void *param_2);
void cNd_ClearObject(node_class *param_1);
void cNd_ForcedClear(node_class *param_1);
void cNd_Create(node_class *param_1,void *param_2);
}
