#include "creator.h"

namespace f_pc_create_tag {
	node_list_class g_fpcCtTg_Queue;
	void f_pc_create_tag::fpcCtTg_CreateQTo(create_tag *param_1) {
		SComponent::cTg_SingleCut(param_1);
	}

	undefined4 f_pc_create_tag::fpcCtTg_Init(create_tag *param_1, void *param_2) {
		SComponent::cTg_Create(param_1, param_2);
		return 1;
	}

	void f_pc_create_tag::fpcCtTg_ToCreateQ(create_tag *param_1) {
		SComponent::cTg_Addition(&f_pc_create_tag::g_fpcCtTg_Queue, param_1);
		return;
	}
}