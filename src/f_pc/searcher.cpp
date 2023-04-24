#include "searcher.h"

namespace f_pc_searcher {
	intptr_t fpcSch_JudgeByID(base_process_class *param_1, int *param_2) {
		if (param_1->mBsPcId == (u32)*param_2) {
			return (intptr_t)param_1;
		}
		return 0;
	}
}