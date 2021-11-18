#pragma once
#include <ctypes.h>



namespace f_op_scene_req {
//[Data] Expected size is 0x000010
extern pointer submethod$2248;

//[Data] Expected size is 0x000020
extern pointer noFadeFase$2249;

//[Data] Expected size is 0x000020
extern undefined * fadeFase$2250;

//[BSS] Expected size is 0x000004
extern undefined4 l_fopScnRq_IsUsingOfOverlap;
undefined4 fopScnRq_phase_ClearOverlap(void);
void fopScnRq_phase_Execute(node_create_request *param_1);
int fopScnRq_phase_IsDoingOverlap(scene_request_class *param_1);
int fopScnRq_phase_IsDoneOverlap(void);
undefined4 fopScnRq_phase_Done(scene_request_class *param_1);
void fopScnRq_Execute(void *param_1);
undefined4 fopScnRq_PostMethod(int param_1,int param_2);
undefined4 fopScnRq_Cancel(int param_1);
int fopScnRq_FadeRequest(short param_1,ushort param_2);
undefined *fopScnRq_Request(int param_1,scene_class *param_2,short procName,void *param_4,short fadeTime,ushort param_6);
void fopScnRq_ReRequest(void);
void fopScnRq_Handler(void);
}
