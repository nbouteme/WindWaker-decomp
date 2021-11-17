#pragma once
#include <ctypes.h>



namespace f_pc_pause {
uint fpcPause_IsEnable(base_process_class *param_1,byte param_2);
undefined4 fpcPause_Enable(process_node_class *pBase,byte param_2);
undefined4 fpcPause_Disable(base_process_class *pBs,byte param_2);
void fpcPause_Init(base_process_class *pBs);
}
