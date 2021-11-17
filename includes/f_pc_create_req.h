#pragma once
#include <ctypes.h>



namespace f_pc_create_req {
uint fpcCtRq_isCreatingByID(create_tag *param_1,int *param_2);
int fpcCtRq_IsCreatingByID(int param_1);
void fpcCtRq_CreateQTo(create_request *param_1);
void fpcCtRq_ToCreateQ(create_request *param_1);
undefined4 fpcCtRq_Delete(create_request *param_1);
undefined4 fpcCtRq_Cancel(create_request *param_1);
int fpcCtRq_IsDoing(create_request *param_1);
undefined4 fpcCtRq_Do(create_request *param_1);
void fpcCtRq_Handler(void);
create_request *fpcCtRq_Create(layer_class *param_1,ulong size,create_request_method_class *param_3);
}
