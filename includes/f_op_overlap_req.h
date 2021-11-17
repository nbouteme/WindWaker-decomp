#pragma once
#include <ctypes.h>



namespace f_op_overlap_req {
undefined4 fopOvlpReq_phase_Done(int param_1);
uint fopOvlpReq_phase_IsDone(request_base_class *param_1);
undefined4 fopOvlpReq_phase_IsWaitOfFadeout(int param_1);
undefined4 fopOvlpReq_phase_WaitOfFadeout(byte *param_1);
undefined4 fopOvlpReq_phase_IsComplete(request_base_class *param_1);
undefined4 fopOvlpReq_phase_IsCreated(int param_1);
undefined4 fopOvlpReq_phase_Create(int param_1);
void fopOvlpReq_Request(overlap_request_class *param_1,short param_2,ushort param_3);
undefined4 fopOvlpReq_Handler(void *param_1);
uint fopOvlpReq_Cancel(void);
uint fopOvlpReq_Is_PeektimeLimit(overlap_request_class *param_1);
void fopOvlpReq_SetPeektime(overlap_request_class *param_1,ushort param_2);
undefined4 fopOvlpReq_OverlapClr(overlap_request_class *param_1);
}
