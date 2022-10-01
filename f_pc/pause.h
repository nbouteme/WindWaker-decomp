#pragma once

#include <SComponent.h>
#include <doltypes.h>
#include <f_pc/base.h>
#include <f_pc/layer.h>
#include <f_pc/node.h>

namespace f_pc_pause {
	undefined4 fpcPause_Enable(process_node_class *pBase, byte param_2);

	// TODO: wrong type
	int fpcPause_Disable(base_process_class *pBs, byte param_2);
	uint fpcPause_IsEnable(base_process_class *param_1, byte param_2);

	void fpcPause_Init(base_process_class *pBs);
}