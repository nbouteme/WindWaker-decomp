#pragma once

#include <SComponent.h>
#include <doltypes.h>

#include "method.h"

namespace f_pc_layer_tag {

	undefined4 f_pc_layer_tag::fpcLyTg_ToQueue(layer_management_tag_class *param_1, int layerID, ushort param_3, ushort param_4) {
		layer_class *plVar1;

		if ((param_1->mpLayer != (layer_class *)0x0) || (layerID != -1)) {
			if ((layerID != -1) && ((layerID != -3 && (param_1->mpLayer->mLayerID != layerID)))) {
				plVar1 = f_pc_layer::fpcLy_Layer(layerID);
				param_1->mpLayer = plVar1;
			}
			if ((layerID == -1) || (layerID == -3)) {
				plVar1 = param_1->mpLayer;
				f_pc_layer::fpcLy_ToQueue(plVar1, (uint)param_3, param_1);
				if (plVar1 != (layer_class *)0x0) {
					param_1->mNodeListID = param_3;
					param_1->mNodeListIdx = (short)plVar1 + -1;
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

	bool f_pc_layer_tag::fpcLyTg_QueueTo(layer_management_tag_class *param_1) {
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
			iVar3 = f_pc_layer_tag::fpcLyTg_QueueTo(param_1);
			if (iVar3 == 1) {
				param_1->mpLayer = plVar1;
				uVar2 = f_pc_layer_tag::fpcLyTg_ToQueue(param_1, param_2, param_3, param_4);
			} else {
				uVar2 = 0;
			}
		}
		return uVar2;
	}
}

namespace f_pc_layer {

	byte init$2271, init$2274;
	byte IsInitOfLayerList$2270;
	int layer_id$2273;
	layer_class l_fpcLy_Crear;
	node_list_class l_fpcLy_LayerList;

	layer_class *l_fpcLy_CurrLayer_p;

	void f_pc_layer::fpcLy_IntoQueue(layer_class *param_1, int param_2, create_tag_class *param_3, int param_4) {
		SComponent::cTg_InsertToTree(&param_1->mNodeListTree, param_2, param_3, param_4);
	}

	void f_pc_layer::fpcLy_QueueTo(layer_class *param_1, create_tag_class *param_2) {
		SComponent::cTg_SingleCutFromTree(param_2);
	}

	void f_pc_layer::fpcLy_ToQueue(layer_class *param_1, int param_2, create_tag_class *param_3) {
		SComponent::cTg_AdditionToTree(&param_1->mNodeListTree, param_2, param_3);
	}

	layer_class *f_pc_layer::fpcLy_Search(uint param_1) {
		layer_class *plVar1;

		plVar1 = f_pc_layer::fpcLy_RootLayer();
		while (true) {
			if (plVar1 == (layer_class *)0x0) {
				return (layer_class *)0x0;
			}
			if (plVar1->mLayerID == param_1)
				break;
			plVar1 = (layer_class *)plVar1->mpNextNode;
		}
		return plVar1;
	}

	layer_class *f_pc_layer::fpcLy_Layer(uint param_1) {
		layer_class *plVar1;

		if ((param_1 == 0) || (plVar1 = f_pc_layer::fpcLy_RootLayer(), param_1 == plVar1->mLayerID)) {
			plVar1 = f_pc_layer::fpcLy_RootLayer();
		} else if ((param_1 == 0xfffffffd) ||
				   (plVar1 = f_pc_layer::fpcLy_CurrentLayer(), param_1 == plVar1->mLayerID)) {
			plVar1 = f_pc_layer::fpcLy_CurrentLayer();
		} else {
			plVar1 = f_pc_layer::fpcLy_Search(param_1);
		}
		return plVar1;
	}

	void f_pc_layer::fpcLy_DeletedMesg(layer_class *param_1) {
		if (param_1->mDeletingCount < 1) {
			return;
		}
		param_1->mDeletingCount = param_1->mDeletingCount + -1;
		return;
	}

	layer_class *f_pc_layer::fpcLy_RootLayer(void) {
		return (layer_class *)f_pc_layer::l_fpcLy_LayerList.mpHead;
	}

	uint f_pc_layer::fpcLy_CancelMethod(process_method_tag_class *param_1) {
		uint uVar1;

		return f_pc_method_tag::fpcMtdTg_Do(param_1);
	}

	void fpcLy_SetCurrentLayer(layer_class *param_1) {
		l_fpcLy_CurrLayer_p = param_1;
	}

	void f_pc_layer::fpcLy_DeletingMesg(layer_class *param_1) {
		param_1->mDeletingCount = param_1->mDeletingCount + 1;
	}

	void fpcLy_Regist(node_class *param_1) {
		SComponent::cLs_Addition(&l_fpcLy_LayerList, param_1);
	}

	int fpcLy_ToCancelQ(layer_class *param_1, process_method_tag_class *param_2) {
		return f_pc_method_tag::fpcMtdTg_ToMethodQ(&param_1->mCancelList, param_2);
	}

	void fpcLy_CreatingMesg(layer_class *param_1) {
		param_1->mCreatingCount = param_1->mCreatingCount + 1;
	}

	void fpcLy_CreatedMesg(layer_class *param_1) {
		if (param_1->mCreatingCount < 1) {
			return;
		}
		param_1->mCreatingCount = param_1->mCreatingCount + -1;
	}

	void fpcLy_CancelQTo(create_tag_class *param_1) {
		f_pc_method_tag::fpcMtdTg_MethodQTo(param_1);
	}

	layer_class *f_pc_layer::fpcLy_CurrentLayer(void) {
		return f_pc_layer::l_fpcLy_CurrLayer_p;
	}

	uint f_pc_layer::fpcLy_IsCreatingMesg(layer_class *param_1) {
		return param_1->mCreatingCount != 0;
	}

	void fpcLy_Create(layer_class *pLayer, void *param_2, node_list_class *param_3, int param_4) {
		undefined *puVar1;
		node_class *pnVar2;
		int iVar3;

		if (init$2271 == 0) {
			IsInitOfLayerList$2270 = 1;
			init$2271 = 1;
		}
		if (init$2274 == 0) {
			layer_id$2273 = 0;
			init$2274 = 1;
		}
		*pLayer = l_fpcLy_Crear;

		SComponent::cNd_Create(pLayer, (void *)0x0);
		pLayer->mLayerID = layer_id$2273++;
		pLayer->mpPcNode = (process_node_class *)param_2;
		if (IsInitOfLayerList$2270 == 1) {
			IsInitOfLayerList$2270 = 0;
			SComponent::cLs_Create(&l_fpcLy_LayerList);
			fpcLy_SetCurrentLayer(pLayer);
		}
		(pLayer->mNodeListTree).mpLists = param_3;
		(pLayer->mNodeListTree).mNumLists = param_4;
		SComponent::cTr_Create(&pLayer->mNodeListTree, (pLayer->mNodeListTree).mpLists, (pLayer->mNodeListTree).mNumLists);
		fpcLy_Regist(pLayer);
	}

	int fpcLy_Cancel(layer_class *param_1) {
		return f_pc_method_iter::fpcMtdIt_Method(&param_1->mCancelList, (SComponent::Method *)f_pc_layer::fpcLy_CancelMethod);
	}

}

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

		f_pc_layer::fpcLy_CurrentLayer();
		f_pc_layer::fpcLy_SetCurrentLayer(param_1);
		int val = f_pc_layer_iter::fpcLyIt_OnlyHere(param_1, param_2, param_3);
		f_pc_layer::fpcLy_SetCurrentLayer(plVar1);
		return val;
	}

	void *f_pc_layer_iter::fpcLyIt_AllJudge(SComponent::Judge *param_1, void *param_2) {
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