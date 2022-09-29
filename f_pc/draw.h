#pragma once

#include <SComponent.h>
#include <doltypes.h>

#include "base.h"
#include "layer.h"
#include "leaf.h"
#include "pause.h"

namespace f_pc_draw {
	using DrawArg = int *(void *, void *);
	using DrawFunc = int *(DrawArg *);

	int *f_pc_draw::fpcDw_Handler(DrawFunc *param_1, DrawArg *param_2) {
		int *uVar1;

		SComponent::cAPIGph_BeforeOfDraw();
		uVar1 = (*param_1)(param_2);
		SComponent::cAPIGph_AfterOfDraw();
		return uVar1;
	}

	int f_pc_draw::fpcDw_Execute(base_process_class *param_1)

	{
		int iVar1;
		layer_class *plVar2;
		bool bVar3;
		fpcMtd__Method *pfVar4;

		iVar1 = f_pc_pause::fpcPause_IsEnable(param_1, 2);
		if (iVar1 == 0) {
			plVar2 = f_pc_layer::fpcLy_CurrentLayer();
			bVar3 = f_pc_base::fpcBs_Is_JustOfType(f_pc_leaf::g_fpcLf_type, param_1->mSubType);
			if (bVar3) {
				pfVar4 = param_1->mpPcMtd->mpDraw;
			} else {
				pfVar4 = param_1->mpPcMtd->mpDraw;
			}
			f_pc_layer::fpcLy_SetCurrentLayer((param_1->mLyTg).mpLayer);
			iVar1 = (*pfVar4)(param_1);
			f_pc_layer::fpcLy_SetCurrentLayer(plVar2);
		} else {
			iVar1 = 0;
		}
		return iVar1;
	}
}