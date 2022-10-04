#pragma once

#include <SComponent.h>

#include "draw.h"

namespace f_pc_manager {
	extern layer_class rootlayer$4264;
	extern node_list_class queue$4265[10];
	extern byte init$4231;
	extern byte l_dvdError$4230;

	using code = void *(void);

	int fpcM_IsPause(base_process_class *param_1, undefined1 param_2);
	void fpcM_PauseDisable(base_process_class *param_1, byte param_2);
	int fpcM_IsCreating(uint p);
	void fpcM_Draw(void *param_1);
	void fpcM_Init();
	int *fpcM_DrawIterater(f_pc_draw::DrawFunc *param_1);
	int fpcM_Delete(base_process_class *param_1);
	void *fpcM_Execute(void *param_1);
	void messageSet(int idx);
	void drawDvdCondition(long param_1);
	int checkDvdCondition(void);
	void fpcM_Management(code *param_1, code *param_2);
	void fpcM_PauseEnable(process_node_class *param_1, byte param_2);
}