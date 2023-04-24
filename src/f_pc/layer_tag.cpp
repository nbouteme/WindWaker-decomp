#include "layer.h"

namespace f_pc_layer_tag {
	int fpcLyTg_Init(layer_management_tag_class *param_1, uint layerID, void *param_3) {
		static layer_management_tag_class crear = {0, 0, 0, 0, 0, nullptr, ~0, ~0};
		*param_1 = crear;
		SComponent::cTg_Create(param_1, param_3);
		auto plVar4 = f_pc_layer::fpcLy_Layer(layerID);
		if (plVar4 != (layer_class *)0x0) {
			param_1->mpLayer = plVar4;
		}
		return !!plVar4;
	}

	undefined4 fpcLyTg_ToQueue(layer_management_tag_class *param_1, int layerID, ushort param_3, ushort param_4) {
		layer_class *plVar1;
		if ((param_1->mpLayer != (layer_class *)0x0) || (layerID != -1)) {
			if ((layerID != -1) && ((layerID != -3 && (param_1->mpLayer->mLayerID != (u32)layerID)))) {
				plVar1 = f_pc_layer::fpcLy_Layer(layerID);
				param_1->mpLayer = plVar1;
			}
			if ((layerID == -1) || (layerID == -3)) {
				plVar1 = param_1->mpLayer;
				int qid = f_pc_layer::fpcLy_ToQueue(plVar1, (uint)param_3, param_1);
				if (plVar1) {
					param_1->mNodeListID = param_3;
					param_1->mNodeListIdx = qid - 1;
					return 1;
				}
			} else {
				plVar1 = param_1->mpLayer;
				f_pc_layer::fpcLy_IntoQueue(plVar1, (uint)param_3, param_1, (uint)param_4);
				if (plVar1 != (layer_class *)0x0) {
					param_1->mNodeListID = param_3;
					param_1->mNodeListIdx = param_4;
					return 1;
				}
			}
		}
		return 0;
	}

	bool fpcLyTg_QueueTo(layer_management_tag_class *param_1) {
		layer_class *plVar1;
		plVar1 = param_1->mpLayer;
		f_pc_layer::fpcLy_QueueTo(plVar1, param_1);
		if (plVar1 == (layer_class *)1) {
			param_1->mpLayer = (layer_class *)0x0;
			param_1->mNodeListID = -1;
			param_1->mNodeListIdx = -1;
		}
		return plVar1 == (layer_class *)1;
	}

	undefined4 fpcLyTg_Move(layer_management_tag_class *param_1, uint param_2, ushort param_3, ushort param_4) {
		layer_class *plVar1;
		undefined4 uVar2;
		int iVar3;
		plVar1 = f_pc_layer::fpcLy_Layer(param_2);
		if (plVar1 == (layer_class *)0x0) {
			uVar2 = 0;
		} else {
			iVar3 = fpcLyTg_QueueTo(param_1);
			if (iVar3 == 1) {
				param_1->mpLayer = plVar1;
				uVar2 = fpcLyTg_ToQueue(param_1, param_2, param_3, param_4);
			} else {
				uVar2 = 0;
			}
		}
		return uVar2;
	}
}