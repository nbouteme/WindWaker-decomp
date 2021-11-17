#pragma once
#include <ctypes.h>



namespace f_pc_deletor {
int fpcDt_IsComplete(void);
bool fpcDt_deleteMethod(base_process_class *param_1);
void fpcDt_Handler(void);
int fpcDt_ToQueue(base_process_class *param_1);
int fpcDt_ToDeleteQ(base_process_class *param_1);
int fpcDt_Delete(base_process_class *param_1);
}
