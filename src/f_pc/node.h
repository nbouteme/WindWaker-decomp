#pragma once

#include <SComponent.h>

struct node_create_request;
struct process_node_class;
struct profile_leaf_method_class;

namespace f_pc_node_req {
	extern node_list_class l_fpcNdRq_Queue;
	extern int g_fpcNd_type;
	extern byte init$2323;
	extern int request_id$2322;
	extern byte clear$2321[];
	extern StepFunction<node_create_request> *methods$2338[];
	extern StepFunction<node_create_request> *methods$2348[];
	extern StepFunction<node_create_request> *methods$2359[];

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

	int fpcNdRq_ReChangeNode(uint param_1, short param_2, void *param_3) {
		create_tag_class *pnVar1;
		node_create_request *pcVar1;

		pnVar1 = (create_tag_class *)f_pc_node_req::l_fpcNdRq_Queue.mpHead;
		while (true) {
			if (pnVar1 == (create_tag_class *)0x0) {
				return 0;
			}
			pcVar1 = pnVar1->mpTagData;
			if ((pcVar1->mArg == 2) && (pcVar1->requestid == param_1))
				break;
			if (pnVar1 == (create_tag_class *)0x0) {
				pnVar1 = (create_tag_class *)0x0;
			} else {
				pnVar1 = (create_tag_class *)pnVar1->mpNextNode;
			}
		}
		if (pcVar1->mRqId == -2) {
			pcVar1->mProcName = param_2;
			pcVar1->mpUserData = (undefined *)param_3;
			return 1;
		}
		return 0;
	}

	int fpcNdRq_ReRequest(uint param_1, short param_2, void *param_3) {
		return fpcNdRq_ReChangeNode(param_1, param_2, param_3);
	}

}

namespace f_pc_node {
	extern int g_fpcNd_type;
	extern int g_fpcNd_IsCheckOfDeleteTiming;
	extern profile_leaf_method_class g_fpcNd_Method;

	process_node_class *fpcNd_IsCreatingFromUnder(process_node_class *p1);
	undefined4 fpcNd_IsDeleteTiming(process_node_class *param_1);
	int fpcNd_DrawMethod(profile_leaf_method_class *, void *);
}