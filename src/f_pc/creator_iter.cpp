#include "creator.h"

namespace f_pc_create_iter {
	int fpcCtIt_Method(SComponent::Method param_1, void *param_2) {
		SComponent::method_filter arg = {param_1, param_2};
		return SComponent::cLsIt_Method(&f_pc_create_tag::g_fpcCtTg_Queue, (SComponent::Method *)SComponent::cTgIt_MethodCall, &arg);
	}

	void *fpcCtIt_Judge(SComponent::Judge *param_1, void *param_2) {
		SComponent::judge_filter arg = {param_1, param_2};
		return SComponent::cLsIt_Judge(&f_pc_create_tag::g_fpcCtTg_Queue, (SComponent::Judge *)SComponent::cTgIt_JudgeFilter, &arg);
	}
}