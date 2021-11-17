#pragma once
#include <ctypes.h>



namespace f_pc_node {
//Expected size is 0x000004
extern undefined4 g_fpcNd_type;

void fpcNd_DrawMethod(int param_1,void *param_2);
undefined4 fpcNd_Draw(process_node_class *param_1);
profile_method_class * fpcNd_Execute(void *param_1);
void * fpcNd_IsCreatingFromUnder(void *param_1);
undefined4 fpcNd_IsDeleteTiming(void *param_1);
void fpcNd_IsDelete(process_node_class *param_1);
undefined4 fpcNd_Delete(void *param_1);
int fpcNd_Create(process_node_class *param_1);
}
