#pragma once

#include <SComponent.h>

namespace f_pc_executor {
	undefined4 fpcEx_ToLineQ(process_node_class *param_1);
	void *fpcEx_Search(SComponent::Judge *param_1, void *param_2);
	void *fpcEx_SearchByID(int param_1);
	void *fpcEx_Execute(base_process_class *param_1);
	void fpcEx_Handler(SComponent::Method *param_1);
	bool fpcEx_ToExecuteQ(base_process_class *param_1);
	bool fpcEx_IsExist(int param_1);
	uint fpcEx_ExecuteQTo(base_process_class *param_1);

}