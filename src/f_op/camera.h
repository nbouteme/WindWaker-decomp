#pragma once

#include <f_pc/leaf.h>

namespace f_op_camera_mng {
	extern int l_fopCamM_id[4];

	int fopCamM_GetParam(leafdraw_class *param_1);

	int fopCamM_Create(int idx, short param_2, void *param_3);

	void fopCamM_Init();

	void fopCamM_Management();
}