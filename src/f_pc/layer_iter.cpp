#include "layer.h"

namespace f_pc_layer_iter {

	void *fpcLyIt_Judge(layer_class *param_1, SComponent::Judge *param_2, void *param_3) {
		SComponent::judge_filter arg = {param_2, param_3};
		return SComponent::cTrIt_Judge(&param_1->mNodeListTree, (SComponent::Judge *)SComponent::cTgIt_JudgeFilter, &arg);
	}

	int fpcLyIt_OnlyHere(layer_class *param_1, SComponent::Method param_2, void *param_3) {
		SComponent::method_filter arg = {param_2, param_3};
		return SComponent::cTrIt_Method(&param_1->mNodeListTree, (SComponent::Method *)SComponent::cTgIt_MethodCall, &arg);
	}

	int fpcLyIt_OnlyHereLY(layer_class *param_1, SComponent::Method param_2, void *param_3) {
		layer_class *plVar1;

		plVar1 = f_pc_layer::fpcLy_CurrentLayer();
		f_pc_layer::fpcLy_SetCurrentLayer(param_1);
		int val = fpcLyIt_OnlyHere(param_1, param_2, param_3);
		f_pc_layer::fpcLy_SetCurrentLayer(plVar1);
		return val;
	}

	void *fpcLyIt_AllJudge(SComponent::Judge *param_1, void *param_2) {
		layer_class *plVar1;
		void *pvVar2;
		undefined *local_18;
		void *local_14;

		SComponent::judge_filter arg = {param_1, param_2};
		plVar1 = f_pc_layer::fpcLy_RootLayer();
		while (true) {
			if (plVar1 == (layer_class *)0x0) {
				return (void *)0x0;
			}
			pvVar2 = SComponent::cTrIt_Judge(&plVar1->mNodeListTree, (SComponent::Judge *)SComponent::cTgIt_JudgeFilter, &arg);
			if (pvVar2)
				break;
			plVar1 = (layer_class *)plVar1->mpNextNode;
		}
		return pvVar2;
	}

}