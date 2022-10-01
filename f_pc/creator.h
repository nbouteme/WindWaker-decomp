#pragma once

#include <SComponent.h>

namespace f_pc_create_iter {
	int fpcCtIt_Method(SComponent::Method param_1, void *param_2);
	int fpcCtIt_Judge(SComponent::Judge *param_1, void *param_2);
}

namespace f_pc_create_tag {
	extern node_list_class g_fpcCtTg_Queue;
	void fpcCtTg_CreateQTo(create_tag *param_1);
	undefined4 fpcCtTg_Init(create_tag *param_1, void *param_2);
	void fpcCtTg_ToCreateQ(create_tag *param_1);
}

namespace f_pc_create_req {
	int fpcCtRq_IsDoing(create_request *param_1);
	int fpcCtRq_Handler(void);
	int fpcCtRq_IsCreatingByID(int param_1);
	uint fpcCtRq_isCreatingByID(create_tag *param_1, int *param_2);
	void fpcCtRq_ToCreateQ(create_request *param_1);
	void fpcCtRq_CreateQTo(create_request *param_1);
	undefined4 fpcCtRq_Do(create_request *param_1);
	undefined4 fpcCtRq_Delete(create_request *param_1);
	undefined4 fpcCtRq_Cancel(create_request *param_1);
	create_request *fpcCtRq_Create(layer_class *param_1, ulong size, create_request_method_class *param_3);
}

namespace f_pc_creator {
	int fpcCt_Handler(void);
	int fpcCt_IsCreatingByID(int param_1);
	int fpcCt_IsDoing(base_process_class *param_1);
	int fpcCt_Abort(base_process_class *param_1);
}
