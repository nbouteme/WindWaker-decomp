#pragma once

#include <SComponent.h>

#include "creator.h"

struct standard_create_request_class : public create_request {
	request_of_phase_process_class mPhase;
	short mProcName;
	void *mpUserData;
	void *mpCallback;
	void *mpCallbackUserData;
};

namespace f_pc_stdcreate_req {

	StepFunction<standard_create_request_class> *submethod$2223[] = {
		fpcSCtRq_Handler,
		fpcSCtRq_Cancel,
		fpcSCtRq_Delete,
	};

	StepFunction<standard_create_request_class> *method$2224[] = {
		fpcSCtRq_phase_Load,
		fpcSCtRq_phase_CreateProcess,
		fpcSCtRq_phase_SubCreateProcess,
		fpcSCtRq_phase_IsComplete,
		fpcSCtRq_phase_PostMethod,
		fpcSCtRq_phase_Done,
		nullptr};

	int f_pc_stdcreate_req::fpcSCtRq_Request(layer_class *param_1, short procname, undefined *param_3, void *param_4, void *param_5) {
		int iVar1;
		standard_create_request_class *pReq;

		if (procname < 0x7fff) {
			pReq = (standard_create_request_class *)
				f_pc_create_req::fpcCtRq_Create(param_1, 0x60, &f_pc_stdcreate_req::submethod$2223);
			if (!pReq) {
				iVar1 = -1;
			} else {
				SComponent::cPhs_Set(&pReq->mPhase, &f_pc_stdcreate_req::method$2224);
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