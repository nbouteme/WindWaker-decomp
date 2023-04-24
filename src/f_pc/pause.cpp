#include "pause.h"

#include "base.h"
#include "layer.h"
#include "node.h"

#include <unistd.h>

namespace f_pc_pause {
	void fpcPause_Init(base_process_class *pBs) {
		pBs->mPauseFlag = 0;
	}

	undefined4 fpcPause_Enable(process_node_class *pBase, byte param_2) {
		bool bVar1;

		pBase->mPauseFlag = pBase->mPauseFlag | param_2;
		bVar1 = f_pc_base::fpcBs_Is_JustOfType(f_pc_node::g_fpcNd_type, pBase->mSubType);
		if (bVar1) {
			f_pc_layer_iter::fpcLyIt_OnlyHere(&pBase->mLayer, (SComponent::Method *)(void*)f_pc_pause::fpcPause_Enable, (void *)(intptr_t)param_2);
		}
		return 1;
	}
	// TODO: wrong type
	int fpcPause_Disable(base_process_class *pBs, byte param_2) {
		bool bVar1;

		pBs->mPauseFlag = pBs->mPauseFlag & -param_2 - 1;
		bVar1 = f_pc_base::fpcBs_Is_JustOfType(f_pc_node::g_fpcNd_type, pBs->mSubType);
		if (bVar1) {
			f_pc_layer_iter::fpcLyIt_OnlyHere((layer_class *)&pBs[1].mBsPcId, (SComponent::Method *)(void*)f_pc_pause::fpcPause_Disable, (void *)(intptr_t)param_2);
		}
		return 1;
	}

	uint fpcPause_IsEnable(base_process_class *param_1, byte param_2) {
		uint uVar1;

		uVar1 = __builtin_clz((uint)((param_2 & param_1->mPauseFlag) != param_2));
		return uVar1 >> 5;
	}
}