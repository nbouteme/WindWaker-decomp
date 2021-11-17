#pragma once
#include <ctypes.h>



namespace f_pc_node_req {
//Expected size is 0x000004
extern undefined4 request_id$2322;

//Expected size is 0x000001
extern undefined1 init$2323;

void fpcNdRq_RequestQTo(create_tag_class *param_1);
void fpcNdRq_ToRequestQ(node_create_request *param_1);
int fpcNdRq_phase_IsCreated(int param_1);
int fpcNdRq_phase_Create(node_create_request *param_1);
undefined4 fpcNdRq_phase_IsDeleteTiming(void);
byte fpcNdRq_phase_IsDeleted(void);
undefined4 fpcNdRq_phase_Delete(int param_1);
void fpcNdRq_DoPhase(node_create_request *param_1);
int fpcNdRq_Execute(node_create_request *param_1);
undefined4 fpcNdRq_Delete(node_create_request *param_1);
undefined4 fpcNdRq_Cancel(node_create_request *param_1);
undefined4 fpcNdRq_Handler(void);
undefined4 fpcNdRq_IsPossibleTarget(process_node_class *param_1);
undefined4 fpcNdRq_IsIng(process_node_class *param_1);
node_create_request * fpcNdRq_Create(int param_1);
node_create_request *fpcNdRq_ChangeNode(ulong param_1,process_node_class *param_2,short param_3,void *param_4);
node_create_request * fpcNdRq_DeleteNode(int param_1,process_node_class *param_2);
node_create_request * fpcNdRq_CreateNode(ulong param_1,short param_2,void *param_3);
node_create_request *fpcNdRq_Request(ulong size,int mode,process_node_class *param_3,short procName,void *param_5,undefined *param_6);
undefined4 fpcNdRq_ReChangeNode(node_class *param_1,undefined2 param_2,node_class *param_3);
void fpcNdRq_ReRequest(void);
}
