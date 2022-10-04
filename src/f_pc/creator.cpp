#include "creator.h"

namespace f_pc_creator {

	int fpcCt_Handler(void) {
		return f_pc_create_req::fpcCtRq_Handler();
	}

	int fpcCt_IsCreatingByID(int param_1) {
		return f_pc_create_req::fpcCtRq_IsCreatingByID(param_1);
	}

	int fpcCt_IsDoing(base_process_class *param_1) {
		return f_pc_create_req::fpcCtRq_IsDoing(param_1->mpCtRq);
	}

	int fpcCt_Abort(base_process_class *param_1) {
		return f_pc_create_req::fpcCtRq_Cancel(param_1->mpCtRq);
	}

}