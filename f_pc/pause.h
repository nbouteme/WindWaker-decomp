#pragma once

#include <SComponent.h>
#include <doltypes.h>

namespace f_pc_pause {
	// TODO: wrong type
	int fpcPause_Disable(base_process_class *pBs, byte param_2);
	uint fpcPause_IsEnable(base_process_class *param_1, byte param_2);
}