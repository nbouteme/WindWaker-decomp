#pragma once

#include <SComponent.h>

namespace f_pc_method_tag {
	void fpcMtdTg_MethodQTo(create_tag_class *param_1);
	int fpcMtdTg_Init(process_method_tag_class *param_1, void *param_2, void *param_3);
	int fpcMtdTg_ToMethodQ(node_list_class *param_1, create_tag_class *param_2);
	int fpcMtdTg_Do(process_method_tag_class *param_1);
}

namespace f_pc_method {
	void fpcMtd_Execute(profile_method_class *param_1, void *param_2);
	int fpcMtd_Delete(profile_leaf_method_class *param_1, void *param_2);
	int fpcMtd_IsDelete(profile_method_class *param_1, void *param_2);
	int fpcMtd_Method(StepFunction<void> *param_1, void *param_2);
}

namespace f_pc_method_iter {
	int fpcMtdIt_Method(node_list_class *param_1, SComponent::Method *param_2);
}