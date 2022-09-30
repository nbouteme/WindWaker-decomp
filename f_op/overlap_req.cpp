#include "overlap.h"
#include <f_pc/manager.h>

namespace f_op_overlap_req {

	uint fopOvlpReq_Is_PeektimeLimit(overlap_request_class *param_1) {
		return !param_1->mPeektime;
	}

	undefined4 fopOvlpReq_OverlapClr(overlap_request_class *param_1)

	{
		uint uVar1;
		undefined4 uVar2;

		if (((char)param_1->mFlags < '\0') ||
			(uVar1 = fopOvlpReq_Is_PeektimeLimit(param_1), uVar1 == 0)) {
			uVar2 = 0;
		} else {
			SComponent::cReq_Create(param_1, 2);
			uVar2 = 1;
		}
		return uVar2;
	}

	undefined4 fopOvlpReq_Handler(overlap_request_class *param_1) {
		int PVar1;
		undefined4 uVar2;

		PVar1 = SComponent::cPhs_Do(&param_1->mOvlPhs, param_1);
		if (PVar1 != 3) {
			if (PVar1 < 3) {
				if (PVar1 == 1) {
					return 0;
				}
				if (0 < PVar1) {
					uVar2 = fopOvlpReq_Handler(param_1);
					return uVar2;
				}
				if (-1 < PVar1) {
					return 0;
				}
			} else if ((PVar1 != cPhs_ERROR_e) && (PVar1 < 5)) {
				return 4;
			}
		}
		return 5;
	}

	uint fopOvlpReq_Cancel(overlap_request_class *param_1) {
		uint uVar1;
		int iVar2;

		return fopOvlpReq_phase_Done(param_1) == 2;
	}

	void fopOvlpReq_SetPeektime(overlap_request_class *param_1, ushort param_2) {
		if (0x7fff < param_2) {
			return;
		}
		param_1->mPeektime = param_2;
		return;
	}

	int fopOvlpReq_phase_Create(overlap_request_class *param_1) {
		layer_class *plVar1;
		undefined *puVar2;

		f_pc_layer::fpcLy_SetCurrentLayer(param_1->mpLayer);
		plVar1 = f_pc_layer::fpcLy_CurrentLayer();
		param_1->ovl_std_create_request = f_pc_stdcreate_req::fpcSCtRq_Request(plVar1, param_1->field5_0x10, (undefined *)0x0, (void *)0x0, (void *)0x0);
		return 2;
	}

	int fopOvlpReq_phase_IsCreated(overlap_request_class *param_1) {
		int iVar1;
		overlap1_class *pvVar2;
		int uVar3;

		iVar1 = f_pc_manager::fpcM_IsCreating(param_1->ovl_std_create_request);
		if (iVar1 == 0) {
			pvVar2 = (overlap1_class *)f_pc_executor::fpcEx_SearchByID((int)param_1->ovl_std_create_request);
			if (pvVar2 == (void *)0x0) {
				uVar3 = 5;
			} else {
				param_1->overlapactor = pvVar2;
				uVar3 = 2;
			}
		} else {
			uVar3 = 0;
		}
		return uVar3;
	}

	int fopOvlpReq_phase_IsComplete(overlap_request_class *param_1) {
		int iVar1;
		int uVar2;

		iVar1 = SComponent::cReq_Is_Done(&param_1->overlapactor->request);
		if (iVar1 == 0) {
			uVar2 = 0;
		} else {
			SComponent::cReq_Done(param_1);
			uVar2 = 2;
		}
		return uVar2;
	}

	int fopOvlpReq_phase_WaitOfFadeout(overlap_request_class *param_1) {
		int uVar1;

		if (param_1->mPeektime != 0) {
			param_1->mPeektime = param_1->mPeektime + -1;
		}
		if (((param_1->mFlags & 0x3f) == 2) && (param_1->mPeektime == 0)) {
			SComponent::cReq_Command(&param_1->overlapactor->request, 2);
			uVar1 = 2;
		} else {
			param_1->mbIsPeek = 1;
			uVar1 = 0;
		}
		return uVar1;
	}

	int fopOvlpReq_phase_IsWaitOfFadeout(overlap_request_class *param_1) {
		int iVar1;
		int uVar2;

		iVar1 = SComponent::cReq_Is_Done(&param_1->overlapactor->request);
		if (iVar1 == 0) {
			uVar2 = 0;
		} else {
			param_1->mbIsPeek = 0;
			uVar2 = 2;
		}
		return uVar2;
	}

	int fopOvlpReq_phase_IsDone(overlap_request_class *param_1) {
		SComponent::cReq_Done(param_1);
		param_1->field2_0x2--;
		return param_1->field2_0x2 != 0;
	}

	StepFunction<overlap_request_class> *phaseMethod$2234[] = {
		fopOvlpReq_phase_Create,
		fopOvlpReq_phase_IsCreated,
		fopOvlpReq_phase_IsComplete,
		fopOvlpReq_phase_WaitOfFadeout,
		fopOvlpReq_phase_IsWaitOfFadeout,
		fopOvlpReq_phase_IsDone,
		fopOvlpReq_phase_Done,
		nullptr};

	void fopOvlpReq_Request(overlap_request_class *param_1, short param_2, ushort param_3) {
		layer_class *plVar1;

		if (param_1->mbIsDoingReq != 1) {
			SComponent::cReq_Command(param_1, 1);
			param_1->field5_0x10 = param_2;
			SComponent::cPhs_Set(&param_1->mOvlPhs, &phaseMethod$2234);
			fopOvlpReq_SetPeektime(param_1, param_3);
			param_1->mbIsDoingReq = 1;
			param_1->field2_0x2 = 1;
			param_1->overlapactor = 0;
			param_1->mbIsPeek = 0;
			param_1->field4_0xc = (undefined *)0x0;
			plVar1 = f_pc_layer::fpcLy_RootLayer();
			param_1->mpLayer = plVar1;
		}
	}

	int fopOvlpReq_phase_Done(overlap_request_class *param_1) {
		int iVar1;
		int uVar2;

		iVar1 = f_pc_manager::fpcM_Delete((base_process_class *)param_1->overlapactor);
		if (iVar1 == 1) {
			param_1->overlapactor = 0;
			param_1->mbIsDoingReq = 0;
			param_1->mPeektime = 0;
			param_1->mbIsPeek = 0;
			param_1->field4_0xc = (undefined *)0x0;
			uVar2 = 2;
		} else {
			uVar2 = 0;
		}
		return uVar2;
	}
}
