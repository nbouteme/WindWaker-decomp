#pragma once
#include <ctypes.h>



namespace f_pc_creator {
void fpcCt_IsCreatingByID(int param_1);
int fpcCt_IsDoing(base_process_class *param_1);
void fpcCt_Abort(base_process_class *param_1);
void fpcCt_Handler(void);
}
