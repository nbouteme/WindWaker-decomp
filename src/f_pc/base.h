#pragma once

#include <SComponent.h>

namespace f_pc_base {
	extern char init$2179;
	extern int process_id$2178;
	extern int g_fpcBs_type;

	void fpcBs_Execute(base_process_class *param_1);
	int fpcBs_MakeOfId(void);
	void fpcBs_DeleteAppend(base_process_class *param_1);
	int fpcBs_Delete(base_process_class *param_1);
	bool fpcBs_Is_JustOfType(int param_1, int param_2);
	int fpcBs_IsDelete(base_process_class *param_1);
	base_process_class *fpcBs_Create(short param_1, uint param_2, void *param_3);
	int fpcBs_SubCreate(base_process_class *param_1);
	int fpcBs_MakeOfType(int*);
}