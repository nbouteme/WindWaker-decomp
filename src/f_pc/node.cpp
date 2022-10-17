#include "node.h"

#include "base.h"
#include "layer.h"
#include "profile.h"

namespace f_pc_node {
	int g_fpcNd_type;

	int fpcNd_Delete(process_node_class *param_1) {
		int iVar1;
		undefined4 uVar2;

		iVar1 = f_pc_layer::fpcLy_IsDeletingMesg(&param_1->mLayer);
		if ((iVar1 == 0) &&
			(iVar1 = f_pc_method::fpcMtd_Delete(param_1->mpMtd, param_1), iVar1 == 1)) {
			param_1->mSubType = 0;
			uVar2 = f_pc_layer::fpcLy_Delete(&param_1->mLayer);
		} else {
			uVar2 = 0;
		}
		return uVar2;
	}

	int fpcNd_Execute(process_node_class *param_1) {
		layer_class *plVar1;
		int iVar2;

		plVar1 = f_pc_layer::fpcLy_CurrentLayer();
		f_pc_layer::fpcLy_SetCurrentLayer(&param_1->mLayer);
		iVar2 = f_pc_method::fpcMtd_Execute(param_1->mpMtd, param_1);
		f_pc_layer::fpcLy_SetCurrentLayer(plVar1);
		return iVar2;
	}

	int fpcNd_IsDelete(process_node_class *param_1) {
		return f_pc_method::fpcMtd_IsDelete(param_1->mpMtd, param_1);
	}

	int fpcNd_DrawMethod(profile_leaf_method_class *param_1, void *param_2) {
		return f_pc_method::fpcMtd_Method(param_1->mpDraw, param_2);
	}

	int fpcNd_Draw(process_node_class *param_1) {
		layer_class *plVar1;
		int uVar2;

		uVar2 = 0;
		if (param_1->field4_0x1a8 == 0) {
			plVar1 = f_pc_layer::fpcLy_CurrentLayer();
			f_pc_layer::fpcLy_SetCurrentLayer(&param_1->mLayer);
			//fpcNd_DrawMethod refers to param_1->mpMtd as a nodedraw_method_class* here
			uVar2 = fpcNd_DrawMethod(param_1->mpMtd, param_1);
			f_pc_layer::fpcLy_SetCurrentLayer(plVar1);
		}
		return uVar2;
	}

	int fpcNd_Create(process_node_class *param_1) {
		int iVar1;
		layer_class *plVar2;
		f_pc_profile__Profile_Base *pfVar3;

		if (param_1->mInitState == 0) {
			pfVar3 = param_1->mpProf;
			iVar1 = f_pc_base::fpcBs_MakeOfType(&g_fpcNd_type);
			param_1->mSubType = iVar1;
			param_1->mpMtd = pfVar3->mpMtd1;
			f_pc_layer::fpcLy_Create(&param_1->mLayer, param_1, param_1->mLayerNodeLists, 0x10);
			param_1->field4_0x1a8 = 0;
		}
		plVar2 = f_pc_layer::fpcLy_CurrentLayer();
		f_pc_layer::fpcLy_SetCurrentLayer(&param_1->mLayer);
		iVar1 = f_pc_method::fpcMtd_Create(param_1->mpMtd, param_1);
		f_pc_layer::fpcLy_SetCurrentLayer(plVar2);
		return iVar1;
	}
	profile_leaf_method_class g_fpcNd_Method = MAKE_PROFILE_METHODS(fpcNd);

	int g_fpcNd_IsCheckOfDeleteTiming = 1;

	process_node_class *fpcNd_IsCreatingFromUnder(process_node_class *param_1) {
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

	undefined4 fpcNd_IsDeleteTiming(process_node_class *param_1) {
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