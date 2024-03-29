#include <f_op/overlap.h>
#include <f_pc/executor.h>
#include <f_pc/pause.h>

#include "scene.h"

#include <cstdio>

namespace f_op_scene_req {

	int fopScnRq_Handler(void) {
		return f_pc_node_req::fpcNdRq_Handler();
	}

	int fopScnRq_Execute(scene_request_class *param_1) {
		int PVar1;

		PVar1 = SComponent::cPhs_Do(&param_1->mScenePhs, param_1);
		if (PVar1 == 2) {
			PVar1 = fopScnRq_Execute(param_1);
		}
		return PVar1;
	}

	int fopScnRq_Cancel(scene_request_class *param_1) {
		int iVar1;

		if ((param_1->field1_0x64 == 0) || (iVar1 = f_op_overlap_mng::fopOvlpM_Cancel(), iVar1 != 0)) {
			iVar1 = 1;
		} else {
			iVar1 = 0;
		}
		return iVar1;
	}

	int fopScnRq_PostMethod(scene_class *param_1, scene_request_class *param_2) {
		printf("Handling for %p\n", param_1);
		f_op_scene_pause::fopScnPause_Enable(param_1);
		if (param_2->field1_0x64 != 0) {
			f_op_overlap_mng::fopOvlpM_ToldAboutID(param_1->mBsPcId);
		}
		return 1;
	}

	SceneStepFunction *submethod$2248[] = {
		fopScnRq_Execute,
		fopScnRq_Cancel,
		nullptr,
		// TODO: Fix - the structure wasn't an array as originally thought?
		(SceneStepFunction *)(void*)fopScnRq_PostMethod};

	int fopScnRq_phase_Execute(scene_request_class *param_1) {
		return f_pc_node_req::fpcNdRq_Execute(param_1);
	}

	int fopScnRq_phase_Done(scene_request_class *param_1) {
		if (param_1->mArg != 1) {
			void *a = f_pc_executor::fpcEx_SearchByID(param_1->mRqId);
			f_op_scene_pause::fopScnPause_Disable((scene_class *)a);
		}
		l_fopScnRq_IsUsingOfOverlap = 0;
		return 2;
	}

	SceneStepFunction *noFadeFase$2249[] = {
		fopScnRq_phase_Execute,
		fopScnRq_phase_Done,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
	};

	int fopScnRq_phase_IsDoingOverlap(scene_request_class *param_1) {
		int iVar1;
		int iVar2;

		iVar1 = f_op_overlap_mng::fopOvlpM_IsDoingReq();
		iVar2 = 0;
		if (iVar1 == 1) {
			iVar2 = 2;
		}
		return iVar2;
	}

	int fopScnRq_phase_IsDoneOverlap(scene_request_class *) {
		int iVar1;
		int iVar2;

		iVar1 = f_op_overlap_mng::fopOvlpM_IsDone();
		iVar2 = 0;
		if (iVar1 == 1) {
			iVar2 = 2;
		}
		return iVar2;
	}

	int fopScnRq_phase_ClearOverlap(scene_request_class *) {
		int iVar1;
		int uVar2;

		iVar1 = f_op_overlap_mng::fopOvlpM_ClearOfReq();
		uVar2 = 0;
		if (iVar1 == 1) {
			uVar2 = 2;
		}
		return uVar2;
	}

	SceneStepFunction *fadeFase$2250[] = {
		fopScnRq_phase_IsDoingOverlap,
		fopScnRq_phase_IsDoneOverlap,
		fopScnRq_phase_Execute,
		fopScnRq_phase_ClearOverlap,
		fopScnRq_phase_IsDoneOverlap,
		fopScnRq_phase_Done,
		nullptr,
		nullptr,
	};

	int l_fopScnRq_IsUsingOfOverlap;

	overlap_request_class *fopScnRq_FadeRequest(short param_1, ushort param_2) {
		overlap_request_class *poVar1;

		poVar1 = nullptr;
		if ((l_fopScnRq_IsUsingOfOverlap == 0) &&
			(poVar1 = f_op_overlap_mng::fopOvlpM_Request(param_1, param_2),
			 poVar1)) {
			l_fopScnRq_IsUsingOfOverlap = 1;
		}
		return poVar1;
	}

	int fopScnRq_Request(int mode, scene_class *param_2, short procName, void *param_4, short fadeTime, ushort param_6) {
		scene_request_class *pReq;
		SceneStepFunction **ppuVar1;
		int iVar2;

		iVar2 = 0;
		ppuVar1 = &noFadeFase$2249[0];
		pReq = (scene_request_class *)
			f_pc_node_req::fpcNdRq_Request(sizeof(scene_request_class), mode, param_2, procName, param_4, (undefined *)&submethod$2248);
		if (pReq == (scene_request_class *)0x0) {
			iVar2 = -1;
		} else {
			if (fadeTime != 0x7fff) {
				ppuVar1 = &fadeFase$2250[0];
				auto iVar2 = fopScnRq_FadeRequest(fadeTime, param_6);
				if (iVar2 == nullptr) {
					f_pc_node_req::fpcNdRq_Delete(pReq);
					return -1;
				}
			}
			pReq->field1_0x64 = iVar2;
			SComponent::cPhs_Set(&pReq->mScenePhs, ppuVar1);
			iVar2 = pReq->requestid;
		}
		return iVar2;
	}

	int fopScnRq_ReRequest(uint param_1, short param_2, void *param_3) {
		return f_pc_node_req::fpcNdRq_ReRequest(param_1, param_2, param_3);
	}
}
