#include "method.h"

namespace f_pc_method_tag {
	void fpcMtdTg_MethodQTo(create_tag_class *param_1) {
		SComponent::cTg_SingleCut(param_1);
	}

	int fpcMtdTg_Init(process_method_tag_class *param_1, void *param_2, void *param_3) {
		SComponent::cTg_Create(param_1, param_1);
		param_1->mpFunc = (int (*)(void *, process_method_tag_class *))param_2;
		param_1->mpUserData = (undefined *)param_3;
		return 1;
	}

	int fpcMtdTg_ToMethodQ(node_list_class *param_1, create_tag_class *param_2) {
		return SComponent::cTg_Addition(param_1, param_2);
	}

	int fpcMtdTg_Do(process_method_tag_class *param_1) {
		return param_1->mpFunc(param_1->mpUserData, param_1);
	}
}