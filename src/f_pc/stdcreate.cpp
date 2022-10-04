#include "stdcreate.h"

#include "base.h"
#include "layer.h"
#include "load.h"
#include "node.h"

namespace f_pc_stdcreate_req {

	int fpcSCtRq_Handler(standard_create_request_class *param_1) {
		int PVar1;

		PVar1 = SComponent::cPhs_Do(&param_1->mPhase, param_1);
		if (PVar1 != 3) {
			if ((int)PVar1 < 3) {
				if ((PVar1 != 1) && (0 < (int)PVar1)) {
					PVar1 = f_pc_stdcreate_req::fpcSCtRq_Handler(param_1);
				}
			} else if ((PVar1 != cPhs_ERROR_e) && ((int)PVar1 < 5)) {
				PVar1 = cPhs_COMPLEATE_e;
			}
		}
		return PVar1;
	}

	int fpcSCtRq_Cancel(standard_create_request_class *) {
		return 1;
	}

	int fpcSCtRq_Delete(standard_create_request_class *) {
		return 1;
	}

	StepFunction<standard_create_request_class> *submethod$2223[] = {
		fpcSCtRq_Handler,
		fpcSCtRq_Cancel,
		fpcSCtRq_Delete,
	};

	int fpcSCtRq_phase_Load(standard_create_request_class *param_1) {
		int iVar1;
		undefined4 uVar2;

		iVar1 = f_pc_load::fpcLd_Load(param_1->mProcName);
		if (iVar1 == 4) {
			uVar2 = 2;
		} else if ((iVar1 < 4) && (iVar1 == 0)) {
			uVar2 = 0;
		} else {
			uVar2 = 5;
		}
		return uVar2;
	}

	int fpcSCtRq_phase_CreateProcess(standard_create_request_class *pReq) {
		base_process_class *pBs;
		base_process_class *pBs_;
		undefined4 uVar1;
		char *pcVar2;

		f_pc_layer::fpcLy_SetCurrentLayer(pReq->mpLayer);
		pcVar2 = (char *)pReq->mBsPcId;
		pBs = f_pc_base::fpcBs_Create(pReq->mProcName, (uint)pcVar2, pReq->mpUserData);
		pReq->mpRes = pBs;
		pBs_ = pReq->mpRes;
		if (pBs_ == (base_process_class *)0x0) {
			f_pc_load::fpcLd_Free(pReq->mProcName, pcVar2);
			uVar1 = 5;
		} else {
			pBs_->mpCtRq = pReq;
			uVar1 = 2;
		}
		return uVar1;
	}

	int fpcSCtRq_phase_SubCreateProcess(standard_create_request_class *param_1) {
		f_pc_layer::fpcLy_SetCurrentLayer(param_1->mpLayer);
		return f_pc_base::fpcBs_SubCreate(param_1->mpRes);
	}

	int fpcSCtRq_phase_IsComplete(standard_create_request_class *param_1) {
		bool bVar3;
		uint uVar1;
		int iVar2;
		base_process_class *pBs;

		pBs = param_1->mpRes;  // TODO: type seems  wrong
		bVar3 = f_pc_base::fpcBs_Is_JustOfType(f_pc_node::g_fpcNd_type, pBs->mSubType);
		if ((bVar3) &&
			(uVar1 = f_pc_layer::fpcLy_IsCreatingMesg((layer_class *)&pBs[1].mBsPcId), uVar1 == 1)) {
			iVar2 = 0;
		} else {
			iVar2 = 2;
		}
		return iVar2;
	}

	int fpcSCtRq_phase_PostMethod(standard_create_request_class *param_1) {
		int iVar1;
		undefined4 uVar2;
		using code = int(base_process_class *, void *);
		if (((code *)param_1->mpCallback == (code *)0x0) ||
			(iVar1 = (*(code *)param_1->mpCallback)(param_1->mpRes, param_1->mpCallbackUserData),
			 iVar1 != 0)) {
			uVar2 = 2;
		} else {
			uVar2 = 0;
		}
		return uVar2;
	}

	int fpcSCtRq_phase_Done(standard_create_request_class *) {
		return 2;
	}

	StepFunction<standard_create_request_class> *method$2224[] = {
		fpcSCtRq_phase_Load,
		fpcSCtRq_phase_CreateProcess,
		fpcSCtRq_phase_SubCreateProcess,
		fpcSCtRq_phase_IsComplete,
		fpcSCtRq_phase_PostMethod,
		fpcSCtRq_phase_Done,
		nullptr};

	int fpcSCtRq_Request(layer_class *param_1, short procname, undefined *param_3, void *param_4, void *param_5) {
		int iVar1;
		standard_create_request_class *pReq;

		if (procname < 0x7fff) {
			pReq = (standard_create_request_class *)
				f_pc_create_req::fpcCtRq_Create(param_1, 0x60, (create_request_method_class *)&submethod$2223);
			if (!pReq) {
				iVar1 = -1;
			} else {
				SComponent::cPhs_Set(&pReq->mPhase, &method$2224);
				pReq->mProcName = procname;
				pReq->mpCallback = param_3;
				pReq->mpCallbackUserData = (undefined *)param_4;
				pReq->mpUserData = param_5;
				iVar1 = pReq->mBsPcId;
			}
		} else {
			iVar1 = -1;
		}
		return iVar1;
	}
}