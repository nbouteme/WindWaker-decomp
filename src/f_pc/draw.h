#pragma once

#include <SComponent.h>
#include <doltypes.h>

namespace f_pc_draw {
	using DrawArg = int *(void *, void *);
	using DrawFunc = int *(DrawArg *);

	int *fpcDw_Handler(DrawFunc *param_1, DrawArg *param_2);
	int fpcDw_Execute(base_process_class *param_1);
}