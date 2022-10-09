#pragma once

#include <SComponent.h>

namespace d_com_lib_game {
	int d_com_lib_game::dComLbG_PhaseHandler(request_of_phase_process_class *param_1, StepFunction<void> **param_2, void *param_3) {
		int iVar1;

		iVar1 = SComponent::cPhs_Handler(param_1, param_2, param_3);
		if (iVar1 == 2) {
			return d_com_lib_game::dComLbG_PhaseHandler(param_1, param_2, param_3);
		}
		return iVar1;
	}
}