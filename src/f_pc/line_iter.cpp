#include "layer.h"
#include "line.h"

namespace f_pc_line_iter {

	int fpcLnIt_MethodCall(create_tag_class *param_1, SComponent::method_filter *param_2)

	{
		layer_class *plVar1;
		int iVar2;
		layer_class *plVar3;

		plVar3 = (layer_class *)(param_1->mpTagData.ndcrreq->mpMtdTag).mpUserData;
		plVar1 = f_pc_layer::fpcLy_CurrentLayer();
		f_pc_layer::fpcLy_SetCurrentLayer(plVar3);
		iVar2 = SComponent::cTgIt_MethodCall(param_1, param_2);
		f_pc_layer::fpcLy_SetCurrentLayer(plVar1);
		return iVar2;
	}

	void fpcLnIt_Queue(SComponent::Method *param_1) {
		SComponent::method_filter local_8{
			param_1, 0};
		SComponent::cTrIt_Method(&f_pc_line::g_fpcLn_Queue, (SComponent::Method *)fpcLnIt_MethodCall, &local_8);
		return;
	}
}
