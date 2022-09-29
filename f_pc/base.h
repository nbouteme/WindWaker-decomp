#pragma once

namespace f_pc_base {

	char init$2179;
	int process_id$2178;

	void f_pc_base::fpcBs_Execute(base_process_class *param_1) {
		layer_class *plVar1;

		plVar1 = f_pc_layer::fpcLy_CurrentLayer();
		f_pc_layer::fpcLy_SetCurrentLayer((param_1->mLyTg).mpLayer);
		f_pc_method::fpcMtd_Execute(param_1->mpPcMtd, param_1);
		f_pc_layer::fpcLy_SetCurrentLayer(plVar1);
		return;
	}

	int f_pc_base::fpcBs_MakeOfId(void) {
		int iVar1;

		if (f_pc_base::init$2179 == '\0') {
			f_pc_base::process_id$2178 = 1;
			f_pc_base::init$2179 = '\x01';
		}
		iVar1 = f_pc_base::process_id$2178;
		f_pc_base::process_id$2178 = f_pc_base::process_id$2178 + 1;
		return iVar1;
	}

	void f_pc_base::fpcBs_DeleteAppend(base_process_class *param_1) {
		if (param_1->mpUserData != (undefined *)0x0) {
			cMl::free(param_1->mpUserData);
			param_1->mpUserData = (undefined *)0x0;
		}
		return;
	}

	int f_pc_base::fpcBs_Delete(base_process_class *param_1) {
		int iVar1;

		iVar1 = f_pc_method::fpcMtd_Delete(param_1->mpPcMtd, param_1);
		if (iVar1 == 1) {
			f_pc_base::fpcBs_DeleteAppend(param_1);
			param_1->mBsType = 0;
			cMl::free(param_1);
		}
		return iVar1;
	}

	bool f_pc_base::fpcBs_Is_JustOfType(int param_1, int param_2) {
		return (param_1 == param_2);
	}

	int f_pc_base::fpcBs_IsDelete(base_process_class *param_1) {
		layer_class *plVar1;
		int iVar2;

		plVar1 = f_pc_layer::fpcLy_CurrentLayer();
		f_pc_layer::fpcLy_SetCurrentLayer((param_1->mLyTg).mpLayer);
		iVar2 = f_pc_method::fpcMtd_IsDelete(param_1->mpPcMtd, param_1);
		f_pc_layer::fpcLy_SetCurrentLayer(plVar1);
		return iVar2;
	}
}