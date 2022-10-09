#include "method.h"

namespace f_pc_method {
	int fpcMtd_Create(profile_leaf_method_class *param_1, void *param_2) {
		return fpcMtd_Method(param_1->mpCreate, param_2);
	}

	int fpcMtd_Execute(profile_leaf_method_class *param_1, void *param_2) {
		return fpcMtd_Method(param_1->mpExecute, param_2);
	}

	int fpcMtd_Delete(profile_leaf_method_class *param_1, void *param_2) {
		return fpcMtd_Method(param_1->mpDelete, param_2);
	}

	int fpcMtd_IsDelete(profile_leaf_method_class *param_1, void *param_2) {
		return fpcMtd_Method(param_1->mpIsDelete, param_2);
	}

	int fpcMtd_Method(StepFunction<void> *param_1, void *param_2) {
		return param_1 ? param_1(param_2) : 1;
	}

}