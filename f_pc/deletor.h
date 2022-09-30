#pragma once

#include <SComponent.h>

namespace f_pc_delete_tag {
	extern node_list_class g_fpcDtTg_Queue;
	void fpcDtTg_ToDeleteQ(delete_tag_class *param_1);
	void fpcDtTg_DeleteQTo(create_tag_class *param_1);
	int fpcDtTg_Do(delete_tag_class *param_1, int *(*param_2)(void *));
}

namespace f_pc_deletor {
	bool fpcDt_deleteMethod(base_process_class *param_1);
	void fpcDt_Handler(void);
	int fpcDt_ToQueue(base_process_class *param_1);
	int fpcDt_ToDeleteQ(process_node_class *param_1);
	int fpcDt_Delete(base_process_class *param_1);
}