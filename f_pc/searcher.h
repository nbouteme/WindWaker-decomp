#pragma once
#include <SComponent.h>

namespace f_pc_searcher {
	int f_pc_searcher::fpcSch_JudgeByID(base_process_class *param_1, int *param_2) {
		if (param_1->mBsPcId == *param_2) {
			return (int)param_1;
		}
		return 0;
	}
}