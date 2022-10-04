#pragma once

#include <SComponent.h>

namespace f_pc_priority {
	extern node_list_class l_fpcPi_Queue;
	extern uint crear$2186;

	process_priority_class *fpcPi_GetFromQueue(void);
	int fpcPi_Handler(void);
	int fpcPi_IsInQueue(create_tag_class *param_1);
	undefined4 fpcPi_QueueTo(process_priority_class *param_1);
	undefined4 fpcPi_Delete(process_priority_class *param_1);
	uint fpcPi_Init(process_priority_class *param_1, void *param_2, uint param_3, ushort param_4, ushort param_5);
	bool fpcPi_IsNormal(uint param_1, ushort param_2, ushort param_3);
}