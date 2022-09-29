#pragma once

#include <SComponent.h>

namespace f_pc_line {
	node_lists_tree_class g_fpcLn_Queue;
	node_list_class l_fpcLn_Line[16];

	void fpcLn_Create() {
		for (int i = 0; i < 16; ++i) {
			SComponent::cLs_Create(l_fpcLn_Line + i);
		}
	}
}

namespace f_pc_line_tag {

	void f_pc_line_tag::fpcLnTg_QueueTo(line_tag *param_1) {
		SComponent::cTg_SingleCutFromTree(param_1);
		param_1->mLineListID = -1;
	}

	uint f_pc_line_tag::fpcLnTg_Move(line_tag *param_1, int param_2)

	{
		uint uVar1;

		if (param_1->mLineListID == param_2) {
			uVar1 = 1;
		} else {
			f_pc_line_tag::fpcLnTg_QueueTo(param_1);
			uVar1 = f_pc_line_tag::fpcLnTg_ToQueue(param_1, param_2);
		}
		return uVar1;
	}

	uint f_pc_line_tag::fpcLnTg_ToQueue(line_tag *param_1, int param_2)

	{
		int iVar1;

		iVar1 = SComponent::cTg_AdditionToTree(&f_pc_line::g_fpcLn_Queue, param_2, param_1);
		if (iVar1 != 0) {
			param_1->mLineListID = param_2;
		}
		return (uint)(iVar1 != 0);
	}

}

namespace f_pc_line_iter {

	int f_pc_line_iter::fpcLnIt_MethodCall(create_tag_class *param_1, SComponent::method_filter *param_2)

	{
		layer_class *plVar1;
		int iVar2;
		layer_class *plVar3;

		plVar3 = (layer_class *)(param_1->mpTagData->mMtdTg).mpFunc;
		plVar1 = f_pc_layer::fpcLy_CurrentLayer();
		f_pc_layer::fpcLy_SetCurrentLayer(plVar3);
		iVar2 = SComponent::cTgIt_MethodCall(param_1, param_2);
		f_pc_layer::fpcLy_SetCurrentLayer(plVar1);
		return iVar2;
	}

	void f_pc_line_iter::fpcLnIt_Queue(SComponent::Method *param_1) {
		SComponent::method_filter local_8{
			param_1, 0};
		SComponent::cTrIt_Method(&f_pc_line::g_fpcLn_Queue, (SComponent::Method *)f_pc_line_iter::fpcLnIt_MethodCall, &local_8);
		return;
	}
}
