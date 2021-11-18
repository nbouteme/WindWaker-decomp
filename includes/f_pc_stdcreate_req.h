#pragma once
#include <ctypes.h>

#include <create_request_method_class.h>


namespace f_pc_stdcreate_req {
//[Data] Expected size is 0x00000c
extern struct create_request_method_class submethod$2223;

//[Data] Expected size is 0x00001c
extern undefined * method$2224;

undefined4 fpcSCtRq_phase_Load(standard_create_request_class *param_1);
undefined4 fpcSCtRq_phase_CreateProcess(standard_create_request_class *pReq);
void fpcSCtRq_phase_SubCreateProcess(standard_create_request_class *param_1);
int fpcSCtRq_phase_IsComplete(standard_create_request_class *param_1);
undefined4 fpcSCtRq_phase_PostMethod(standard_create_request_class *param_1);
undefined4 fpcSCtRq_phase_Done(void);
void fpcSCtRq_Handler(standard_create_request_class *param_1);
undefined4 fpcSCtRq_Delete(void);
undefined4 fpcSCtRq_Cancel(void);
int fpcSCtRq_Request(layer_class *param_1,short param_2,undefined *param_3,void *param_4,void *param_5);
}
