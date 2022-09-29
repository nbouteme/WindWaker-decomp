#pragma once

#include <SComponent.h>
#include <f_pc/stdcreate.h>

#include "leaf.h"

struct overlap1_class : public leafdraw_class {
	profile_method_class *methods;
	request_base_class request;
	int state, fadeinframesleft, fadeoutframesleft;
};

struct overlap_request_class : public request_base_class {
	short mbIsDoingReq;
	short mPeektime;
	int mbIsPeek;
	void *field4_0xc;	//
	short field5_0x10;	//
	int ovl_std_create_request;
	//
	request_of_phase_process_class mOvlPhs;
	overlap1_class *overlapactor;  //
	layer_class *mpLayer;
};

namespace f_op_overlap_req {

	uint f_op_overlap_req::fopOvlpReq_Is_PeektimeLimit(overlap_request_class *param_1) {
		return !param_1->mPeektime;
	}

	undefined4 f_op_overlap_req::fopOvlpReq_OverlapClr(overlap_request_class *param_1)

	{
		uint uVar1;
		undefined4 uVar2;

		if (((char)param_1->mFlags < '\0') ||
			(uVar1 = f_op_overlap_req::fopOvlpReq_Is_PeektimeLimit(param_1), uVar1 == 0)) {
			uVar2 = 0;
		} else {
			SComponent::cReq_Create(param_1, 2);
			uVar2 = 1;
		}
		return uVar2;
	}

	undefined4 f_op_overlap_req::fopOvlpReq_Handler(overlap_request_class *param_1) {
		int PVar1;
		undefined4 uVar2;

		PVar1 = SComponent::cPhs_Do(&param_1->mOvlPhs, param_1);
		if (PVar1 != 3) {
			if (PVar1 < 3) {
				if (PVar1 == 1) {
					return 0;
				}
				if (0 < PVar1) {
					uVar2 = f_op_overlap_req::fopOvlpReq_Handler(param_1);
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

	uint f_op_overlap_req::fopOvlpReq_Cancel(overlap_request_class *param_1) {
		uint uVar1;
		int iVar2;

		return f_op_overlap_req::fopOvlpReq_phase_Done(param_1) == 2;
	}

	void f_op_overlap_req::fopOvlpReq_SetPeektime(overlap_request_class *param_1, ushort param_2) {
		if (0x7fff < param_2) {
			return;
		}
		param_1->mPeektime = param_2;
		return;
	}

	int f_op_overlap_req::fopOvlpReq_phase_Create(overlap_request_class *param_1) {
		layer_class *plVar1;
		undefined *puVar2;

		f_pc_layer::fpcLy_SetCurrentLayer(param_1->mpLayer);
		plVar1 = f_pc_layer::fpcLy_CurrentLayer();
		param_1->ovl_std_create_request = f_pc_stdcreate_req::fpcSCtRq_Request(plVar1, param_1->field5_0x10, (undefined *)0x0, (void *)0x0, (void *)0x0);
		return 2;
	}

	int f_op_overlap_req::fopOvlpReq_phase_IsCreated(overlap_request_class *param_1) {
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

	int f_op_overlap_req::fopOvlpReq_phase_IsComplete(overlap_request_class *param_1) {
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

	int f_op_overlap_req::fopOvlpReq_phase_WaitOfFadeout(overlap_request_class *param_1) {
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

	int f_op_overlap_req::fopOvlpReq_phase_IsWaitOfFadeout(overlap_request_class *param_1) {
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

	int f_op_overlap_req::fopOvlpReq_phase_IsDone(overlap_request_class *param_1) {
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
			SComponent::cPhs_Set(&param_1->mOvlPhs, &f_op_overlap_req::phaseMethod$2234);
			f_op_overlap_req::fopOvlpReq_SetPeektime(param_1, param_3);
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

namespace f_op_overlap_mng {
	void fopOvlpM_Init() {}

	overlap_request_class *l_fopOvlpM_overlap;
	overlap_request_class l_fopOvlpM_Request;

	int f_op_overlap_mng::fopOvlpM_ClearOfReq(void)

	{
		int uVar1;

		if (f_op_overlap_mng::l_fopOvlpM_overlap == (overlap_request_class *)0x0) {
			uVar1 = 0;
		} else {
			uVar1 = f_op_overlap_req::fopOvlpReq_OverlapClr(f_op_overlap_mng::l_fopOvlpM_overlap);
		}
		return uVar1;
	}

	int f_op_overlap_mng::fopOvlpM_IsDone(void)

	{
		int uVar1;

		if (f_op_overlap_mng::l_fopOvlpM_overlap == (overlap_request_class *)0x0) {
			uVar1 = 0;
		} else {
			uVar1 = SComponent::cReq_Is_Done(f_op_overlap_mng::l_fopOvlpM_overlap);
		}
		return uVar1;
	}

	int f_op_overlap_mng::fopOvlpM_IsDoingReq(void)

	{
		if ((f_op_overlap_mng::l_fopOvlpM_overlap != (overlap_request_class *)0x0) &&
			(f_op_overlap_mng::l_fopOvlpM_overlap->mbIsDoingReq == 1)) {
			return 1;
		}
		return 0;
	}

	overlap_request_class *fopOvlpM_Request(short param_1, ushort param_2) {
		overlap_request_class *poVar1;

		if (f_op_overlap_mng::l_fopOvlpM_overlap == (overlap_request_class *)0x0) {
			poVar1 = &f_op_overlap_mng::l_fopOvlpM_Request;
			f_op_overlap_req::fopOvlpReq_Request(&f_op_overlap_mng::l_fopOvlpM_Request, param_1, param_2);
			f_op_overlap_mng::l_fopOvlpM_overlap = poVar1;
		} else {
			poVar1 = (overlap_request_class *)0x0;
		}
		return poVar1;
	}

	void f_op_overlap_mng::fopOvlpM_Management(void) {
		int iVar1;

		if (((f_op_overlap_mng::l_fopOvlpM_overlap != (overlap_request_class *)0x0) &&
			 (iVar1 = f_op_overlap_req::fopOvlpReq_Handler(f_op_overlap_mng::l_fopOvlpM_overlap), iVar1 < 6)) &&
			(2 < iVar1)) {
			f_op_overlap_mng::l_fopOvlpM_overlap = (overlap_request_class *)0x0;
		}
		return;
	}

	uint fopOvlpReq_Cancel(overlap_request_class *param_1) {
		uint uVar1;
		int iVar2;

		// TODO: check
		return f_op_overlap_req::fopOvlpReq_phase_Done(param_1) == 2;
	}

	undefined4 fopOvlpM_Cancel(void) {
		undefined4 uVar1;
		int iVar2;
		ulong uVar3;

		if (f_op_overlap_mng::l_fopOvlpM_overlap == (overlap_request_class *)0x0) {
			uVar1 = 1;
		} else {
			iVar2 = f_op_overlap_req::fopOvlpReq_Cancel(f_op_overlap_mng::l_fopOvlpM_overlap);
			if (iVar2 == 1) {
				f_op_overlap_mng::l_fopOvlpM_overlap = (overlap_request_class *)0x0;
				JUTAssertion::getSDevice()->setWarningMessage_f("f_op_overlap_mng.cpp", 0x14b, "%s", "fopOvlpM_Cancel SUCCESSED");
				uVar1 = 1;
			} else {
				uVar1 = 0;
			}
		}
		return uVar1;
	}

}