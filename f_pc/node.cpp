#include "base.h"
#include "layer.h"

#include "node.h"

namespace f_pc_node {
	int g_fpcNd_type;

	int g_fpcNd_IsCheckOfDeleteTiming = 1;

	process_node_class *fpcNd_IsCreatingFromUnder(void *p1) {
		auto param_1 = (process_node_class *)p1;
		bool bVar2;
		uint uVar1;

		if ((param_1 == nullptr) ||
			(bVar2 = f_pc_base::fpcBs_Is_JustOfType(g_fpcNd_type, param_1->mSubType), bVar2)) {
			param_1 = nullptr;
		} else {
			uVar1 = f_pc_layer::fpcLy_IsCreatingMesg(&param_1->mLayer);
			if (uVar1 == 0) {
				param_1 = (process_node_class *)f_pc_layer_iter::fpcLyIt_Judge(&param_1->mLayer, (SComponent::Judge *)fpcNd_IsCreatingFromUnder, 0);
			}
		}
		return param_1;
	}

	undefined4 fpcNd_IsDeleteTiming(void *param_1) {
		int iVar1;
		undefined4 uVar2;

		if ((g_fpcNd_IsCheckOfDeleteTiming == 1) &&
			(fpcNd_IsCreatingFromUnder(param_1))) {
			uVar2 = 0;
		} else {
			uVar2 = 1;
		}
		return uVar2;
	}
}