#include "method.h"

namespace f_pc_method {

	void fpcMtd_Execute(profile_method_class *param_1, void *param_2) {
		fpcMtd_Method(param_1->mpExecute, param_2);
	}

	int fpcMtd_Delete(profile_leaf_method_class *param_1, void *param_2) {
		int iVar1;

		iVar1 = fpcMtd_Method(param_1->mpDelete, param_2);
		return iVar1;
	}

	int fpcMtd_IsDelete(profile_method_class *param_1, void *param_2) {
		return fpcMtd_Method(param_1->mpIsDelete, param_2);
	}

	int fpcMtd_Method(StepFunction<void> *param_1, void *param_2) {
		if (!param_1) {
			return 1;
		}
		return param_1(param_2);
	}

}