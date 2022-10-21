#include <SComponent/c_malloc.h>

#include "base.h"
#include "creator.h"
#include "deletor.h"
#include "executor.h"
#include "layer.h"

namespace f_pc_create_req {

	uint fpcCtRq_isCreatingByID(create_tag *param_1, int *param_2) {
		return *param_2 == param_1->mpTagData.crreq->mBsPcId;
	}

	int fpcCtRq_IsCreatingByID(int param_1) {
		int iVar1;
		int local_8[2];

		local_8[0] = param_1;
		iVar1 = f_pc_create_iter::fpcCtIt_Judge((SComponent::Judge *)fpcCtRq_isCreatingByID, local_8);
		return (uint)(iVar1 != 0);
	}

	void fpcCtRq_ToCreateQ(create_request *param_1) {
		f_pc_layer::fpcLy_CreatingMesg(param_1->mpLayer);
		f_pc_layer::fpcLy_ToCancelQ(param_1->mpLayer, &param_1->mMtdTg);
		f_pc_create_tag::fpcCtTg_ToCreateQ(param_1);
	}

	undefined4 fpcCtRq_Do(create_request *param_1) {
		bool bVar2;
		undefined4 uVar1;
		int iVar3;
		StepFunction<void> *pcVar4;

		iVar3 = 4;
		if ((param_1->mpCtRqMtd) &&
			(pcVar4 = param_1->mpCtRqMtd->mpHandler, pcVar4)) {
			param_1->mbIsCreating = 1;
			iVar3 = (*pcVar4)((void *)param_1);
			param_1->mbIsCreating = 0;
		}
		if (iVar3 == 4) {
			bVar2 = f_pc_executor::fpcEx_ToExecuteQ(param_1->mpRes);
			if (!bVar2) {
				uVar1 = fpcCtRq_Cancel(param_1);
				return uVar1;
			}
			uVar1 = fpcCtRq_Delete(param_1);
			return uVar1;
		}
		if (iVar3 < 4) {
			if (2 < iVar3) {
			LAB_8003cfa0:
				uVar1 = fpcCtRq_Cancel(param_1);
				return uVar1;
			}
		} else if (iVar3 < 6)
			goto LAB_8003cfa0;
		return 1;
	}

	int fpcCtRq_IsDoing(create_request *param_1) {
		if (param_1) {
			return (int)(char)param_1->mbIsCreating;
		}
		return 0;
	}

	void fpcCtRq_CreateQTo(create_request *param_1) {
		f_pc_create_tag::fpcCtTg_CreateQTo(param_1);
		f_pc_layer::fpcLy_CreatedMesg(param_1->mpLayer);
		f_pc_layer::fpcLy_CancelQTo(&param_1->mMtdTg);
	}

	undefined4 fpcCtRq_Delete(create_request *param_1) {
		int iVar1;
		undefined4 uVar2;

		fpcCtRq_CreateQTo(param_1);
		if ((param_1->mpCtRqMtd == (create_request_method_class *)0x0) ||
			(iVar1 = f_pc_method::fpcMtd_Method(param_1->mpCtRqMtd->mpDelete, param_1), iVar1 != 0)) {
			if (param_1->mpRes != (base_process_class *)0x0) {
				param_1->mpRes->mpCtRq = (create_request *)0x0;
			}
			cMl::free(param_1);
			uVar2 = 1;
		} else {
			uVar2 = 0;
		}
		return uVar2;
	}

	create_request *
	fpcCtRq_Create(layer_class *param_1, ulong size, create_request_method_class *param_3) {
		create_request *pReq;
		int iVar1;

		pReq = (create_request *)cMl::memalignB(-4, size);
		if (pReq != (create_request *)0x0) {
			f_pc_create_tag::fpcCtTg_Init((create_tag *)pReq, pReq);
			f_pc_method_tag::fpcMtdTg_Init(&pReq->mMtdTg, fpcCtRq_Cancel, pReq);
			pReq->mpLayer = param_1;
			pReq->mpCtRqMtd = param_3;
			iVar1 = f_pc_base::fpcBs_MakeOfId();
			pReq->mBsPcId = iVar1;
			pReq->mpRes = (base_process_class *)0x0;
			pReq->field2_0x15 = 0;
			fpcCtRq_ToCreateQ(pReq);
		}
		return pReq;
	}

	int fpcCtRq_Handler(void) {
		return f_pc_create_iter::fpcCtIt_Method((SComponent::Method *)fpcCtRq_Do, (void *)0x0);
	}

	undefined4 fpcCtRq_Cancel(create_request *param_1) {
		int iVar1;
		undefined4 uVar2;

		if ((param_1 == (create_request *)0x0) || (param_1->field2_0x15 != 0)) {
			uVar2 = 1;
		} else {
			param_1->field2_0x15 = 1;
			if ((param_1->mpRes == (base_process_class *)0x0) ||
				(iVar1 = f_pc_deletor::fpcDt_Delete(param_1->mpRes), iVar1 != 0)) {
				if ((param_1->mpCtRqMtd == (create_request_method_class *)0x0) ||
					(iVar1 = f_pc_method::fpcMtd_Method(param_1->mpCtRqMtd->mpCancel, param_1), iVar1 != 0)) {
					uVar2 = fpcCtRq_Delete(param_1);
				} else {
					uVar2 = 0;
				}
			} else {
				uVar2 = 0;
			}
		}
		return uVar2;
	}
}
