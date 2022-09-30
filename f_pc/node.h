#pragma once

#include <SComponent.h>

namespace f_pc_node_req {
	extern node_list_class l_fpcNdRq_Queue;
	extern byte init$2323;
	extern int request_id$2322;
	extern byte clear$2321[];
	extern StepFunction<void> *methods$2338[];
	extern StepFunction<void> *methods$2348[];
	extern StepFunction<void> *methods$2359[];

	void fpcNdRq_ToRequestQ(node_create_request *param_1);
	int fpcNdRq_DoPhase(node_create_request *param_1);
	int fpcNdRq_Execute(node_create_request *param_1);
	undefined4 fpcNdRq_Handler(void);
	undefined4 fpcNdRq_IsPossibleTarget(process_node_class *param_1);
	undefined4 fpcNdRq_IsIng(process_node_class *param_1);
	int fpcNdRq_Cancel(node_create_request *param_1);
	node_create_request *fpcNdRq_Create(int param_1);
	node_create_request *fpcNdRq_ChangeNode(ulong param_1, process_node_class *param_2, short param_3, void *param_4);
	node_create_request *fpcNdRq_DeleteNode(int param_1, process_node_class *param_2);
	node_create_request *fpcNdRq_CreateNode(ulong size, short procname, void *param_3);
	node_create_request *fpcNdRq_Request(ulong size, int mode, process_node_class *param_3, short procName, void *param_5, undefined *param_6);
	void fpcNdRq_RequestQTo(node_create_request *param_1);
	int fpcNdRq_Delete(node_create_request *param_1);

}

namespace f_pc_node {
	extern int g_fpcNd_type;
	extern int g_fpcNd_IsCheckOfDeleteTiming;

	process_node_class *fpcNd_IsCreatingFromUnder(void *p1);
	undefined4 fpcNd_IsDeleteTiming(void *param_1);
}