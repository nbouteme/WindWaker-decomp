#pragma once

#include <SComponent.h>
#include <doltypes.h>

#include "method.h"

namespace f_pc_layer_tag {
	undefined4 fpcLyTg_ToQueue(layer_management_tag_class *param_1, int layerID, ushort param_3, ushort param_4);
	bool fpcLyTg_QueueTo(layer_management_tag_class *param_1);
	undefined4 fpcLyTg_Move(layer_management_tag_class *param_1, uint param_2, ushort param_3, ushort param_4);
}

namespace f_pc_layer {
	extern byte init$2271, init$2274;
	extern byte IsInitOfLayerList$2270;
	extern int layer_id$2273;
	extern layer_class l_fpcLy_Crear;
	extern node_list_class l_fpcLy_LayerList;
	extern layer_class *l_fpcLy_CurrLayer_p;

	void fpcLy_IntoQueue(layer_class *param_1, int param_2, create_tag_class *param_3, int param_4);
	void fpcLy_QueueTo(layer_class *param_1, create_tag_class *param_2);
	void fpcLy_ToQueue(layer_class *param_1, int param_2, create_tag_class *param_3);
	void fpcLy_DeletedMesg(layer_class *param_1);
	uint fpcLy_CancelMethod(process_method_tag_class *param_1);
	void fpcLy_DeletingMesg(layer_class *param_1);
	uint fpcLy_IsCreatingMesg(layer_class *param_1);
	layer_class *fpcLy_Layer(uint param_1);
	layer_class *fpcLy_Search(uint param_1);
	layer_class *fpcLy_RootLayer(void);
	layer_class *fpcLy_CurrentLayer(void);
	void fpcLy_SetCurrentLayer(layer_class *param_1);
	void fpcLy_Regist(node_class *param_1);
	int fpcLy_ToCancelQ(layer_class *param_1, process_method_tag_class *param_2);
	void fpcLy_CreatingMesg(layer_class *param_1);
	void fpcLy_CreatedMesg(layer_class *param_1);
	void fpcLy_CancelQTo(create_tag_class *param_1);
	void fpcLy_Create(layer_class *pLayer, void *param_2, node_list_class *param_3, int param_4);
	int fpcLy_Cancel(layer_class *param_1);
}

namespace f_pc_layer_iter {
	void *fpcLyIt_Judge(layer_class *param_1, SComponent::Judge *param_2, void *param_3);
	int fpcLyIt_OnlyHere(layer_class *param_1, SComponent::Method param_2, void *param_3);
	int fpcLyIt_OnlyHereLY(layer_class *param_1, SComponent::Method param_2, void *param_3);
	void *fpcLyIt_AllJudge(SComponent::Judge *param_1, void *param_2);
}