#include "base.h"
#include "layer.h"
#include "node.h"

#include "pause.h"

namespace f_pc_pause {

	// TODO: wrong type
	int f_pc_pause::fpcPause_Disable(base_process_class *pBs, byte param_2) {
		bool bVar1;

		pBs->mPauseFlag = pBs->mPauseFlag & -param_2 - 1;
		bVar1 = f_pc_base::fpcBs_Is_JustOfType(f_pc_node::g_fpcNd_type, pBs->mSubType);
		if (bVar1) {
			f_pc_layer_iter::fpcLyIt_OnlyHere((layer_class *)&pBs[1].mBsPcId, (SComponent::Method *)f_pc_pause::fpcPause_Disable, (void *)param_2);
		}
		return 1;
	}

	uint f_pc_pause::fpcPause_IsEnable(base_process_class *param_1, byte param_2) {
		uint uVar1;

		uVar1 = __builtin_clz((uint)((param_2 & param_1->mPauseFlag) != param_2));
		return uVar1 >> 5;
	}
}