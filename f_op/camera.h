#pragma once

#include "leaf.h"

namespace f_op_camera_mng {
	extern int l_fopCamM_id[4];

	int f_op_camera_mng::fopCamM_GetParam(leafdraw_class *param_1);

	int f_op_camera_mng::fopCamM_Create(int idx, short param_2, void *param_3);

	void fopCamM_Init();

	void fopCamM_Management();
}