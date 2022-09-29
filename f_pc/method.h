#pragma once

#include <SComponent.h>

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

namespace f_pc_method {

	void f_pc_method::fpcMtd_Execute(profile_method_class *param_1, void *param_2) {
		f_pc_method::fpcMtd_Method(param_1->mpExecute, param_2);
	}

	int f_pc_method::fpcMtd_Delete(profile_leaf_method_class *param_1, void *param_2) {
		int iVar1;

		iVar1 = f_pc_method::fpcMtd_Method(param_1->mpDelete, param_2);
		return iVar1;
	}

	int f_pc_method::fpcMtd_IsDelete(profile_method_class *param_1, void *param_2) {
		return f_pc_method::fpcMtd_Method(param_1->mpIsDelete, param_2);
	}

	int fpcMtd_Method(StepFunction<void> *param_1, void *param_2) {
		if (!param_1) {
			return 1;
		}
		return param_1(param_2);
	}

}

namespace f_pc_method_iter {
	int fpcMtdIt_Method(node_list_class *param_1, SComponent::Method *param_2) {
		return SComponent::cLsIt_Method(param_1, param_2, 0);
	}
}