#pragma once

#include <SComponent.h>

namespace f_pc_line {
	extern node_lists_tree_class g_fpcLn_Queue;
	extern node_list_class l_fpcLn_Line[16];

	void fpcLn_Create();
}

namespace f_pc_line_tag {
	void fpcLnTg_QueueTo(line_tag *param_1);
	uint fpcLnTg_Move(line_tag *param_1, int param_2);
	uint fpcLnTg_ToQueue(line_tag *param_1, int param_2);
}

namespace f_pc_line_iter {
	int fpcLnIt_MethodCall(create_tag_class *param_1, SComponent::method_filter *param_2);
	void fpcLnIt_Queue(SComponent::Method *param_1);
}
