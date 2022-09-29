#pragma once

#include "leaf.h"

namespace f_op_camera_mng {
	int l_fopCamM_id[4];

	int f_op_camera_mng::fopCamM_GetParam(leafdraw_class *param_1) {
		return param_1->mParameters;
	}

	int f_op_camera_mng::fopCamM_Create(int idx, short param_2, void *param_3) {
		return l_fopCamM_id[idx] = f_pc_stdcreate_req::fpcSCtRq_Request(f_pc_layer::fpcLy_CurrentLayer(), param_2, (undefined *)0x0, (void *)0x0, param_3);
	}

	void fopCamM_Init() {
		// empty
	}

	void fopCamM_Management() {
		// empty
	}
}