#pragma once

namespace f_op_draw_tag {
	node_lists_tree_class g_fopDwTg_Queue;
	node_list_class lists$2178[1000];
    
	void fopDwTg_CreateQueue(void) {
		SComponent::cTr_Create(&g_fopDwTg_Queue, lists$2178, 1000);
	}
}