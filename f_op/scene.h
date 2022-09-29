#pragma once

#include <SComponent.h>
#include <doltypes.h>

#include "../f_pc/node.h"
#include "overlap.h"

struct scene_tag_class : public create_tag_class {
};

struct scene_class : public process_node_class {
	profile_method_class *mpSceneMtd;
	scene_tag_class mScTg;
};

struct scene_request_class : public node_create_request {
	int field1_0x64;
	request_of_phase_process_class mScenePhs;
	//
};

using SceneStepFunction = StepFunction<scene_request_class>;

namespace f_op_scene_pause {

	undefined4 f_op_scene_pause::fopScnPause_Disable(scene_class *param_1)

	{
		int iVar1;
		undefined4 uVar2;
		process_node_class *ppVar3;

		if (param_1 == (scene_class *)0x0) {
			uVar2 = 0;
		} else {
			ppVar3 = (param_1->mLyTg.mpLayer)->mpPcNode;
			if (ppVar3 == (process_node_class *)0x0) {
				f_pc_manager::fpcM_PauseDisable(param_1, 1);
				f_pc_manager::fpcM_PauseDisable(param_1, 2);
			} else {
				iVar1 = f_pc_executor::fpcEx_IsExist(ppVar3->mBsPcId);
				if (iVar1 == 1) {
					iVar1 = f_pc_manager::fpcM_IsPause(ppVar3, 1);
					if (iVar1 == 0) {
						f_pc_manager::fpcM_PauseDisable(param_1, 1);
					}
					iVar1 = f_pc_manager::fpcM_IsPause(ppVar3, 2);
					if (iVar1 == 0) {
						f_pc_manager::fpcM_PauseDisable(param_1, 2);
					}
				}
			}
			uVar2 = 1;
		}
		return uVar2;
	}
}

namespace f_op_scene_req {

	int f_op_scene_req::fopScnRq_Handler(void) {
		return f_pc_node_req::fpcNdRq_Handler();
	}

	int fopScnRq_Execute(scene_request_class *param_1) {
		int PVar1;

		PVar1 = SComponent::cPhs_Do(&param_1->mScenePhs, param_1);
		if (PVar1 == 2) {
			PVar1 = f_op_scene_req::fopScnRq_Execute(param_1);
		}
		return PVar1;
	}

	int f_op_scene_req::fopScnRq_Cancel(scene_request_class *param_1) {
		int iVar1;

		if ((param_1->field1_0x64 == 0) || (iVar1 = f_op_overlap_mng::fopOvlpM_Cancel(), iVar1 != 0)) {
			iVar1 = 1;
		} else {
			iVar1 = 0;
		}
		return iVar1;
	}

	SceneStepFunction *submethod$2248[] = {
		fopScnRq_Execute,
		fopScnRq_Cancel,
		nullptr,
		fopScnRq_PostMethod};

	int f_op_scene_req::fopScnRq_phase_Execute(scene_request_class *param_1) {
		return f_pc_node_req::fpcNdRq_Execute(param_1);
	}

	int f_op_scene_req::fopScnRq_phase_Done(scene_request_class *param_1)

	{
		if (param_1->mArg != 1) {
			void *a = f_pc_executor::fpcEx_SearchByID(param_1->mRqId);
			f_op_scene_pause::fopScnPause_Disable((scene_class *)a);
		}
		f_op_scene_req::l_fopScnRq_IsUsingOfOverlap = 0;
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

	int f_op_scene_req::fopScnRq_phase_IsDoingOverlap(scene_request_class *param_1)

	{
		int iVar1;
		int iVar2;

		iVar1 = f_op_overlap_mng::fopOvlpM_IsDoingReq();
		iVar2 = 0;
		if (iVar1 == 1) {
			iVar2 = 2;
		}
		return iVar2;
	}

	int f_op_scene_req::fopScnRq_phase_IsDoneOverlap(scene_request_class *) {
		int iVar1;
		int iVar2;

		iVar1 = f_op_overlap_mng::fopOvlpM_IsDone();
		iVar2 = 0;
		if (iVar1 == 1) {
			iVar2 = 2;
		}
		return iVar2;
	}

	int f_op_scene_req::fopScnRq_phase_ClearOverlap(scene_request_class *)

	{
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

	overlap_request_class *f_op_scene_req::fopScnRq_FadeRequest(short param_1, ushort param_2) {
		overlap_request_class *poVar1;

		poVar1 = nullptr;
		if ((f_op_scene_req::l_fopScnRq_IsUsingOfOverlap == 0) &&
			(poVar1 = f_op_overlap_mng::fopOvlpM_Request(param_1, param_2),
			 poVar1)) {
			f_op_scene_req::l_fopScnRq_IsUsingOfOverlap = 1;
		}
		return poVar1;
	}

	int fopScnRq_Request(int mode, scene_class *param_2, short procName, void *param_4, short fadeTime, ushort param_6) {
		scene_request_class *pReq;
		SceneStepFunction **ppuVar1;
		int iVar2;

		iVar2 = 0;
		ppuVar1 = &f_op_scene_req::noFadeFase$2249[0];
		pReq = (scene_request_class *)
			f_pc_node_req::fpcNdRq_Request(0x74, mode, param_2, procName, param_4, &f_op_scene_req::submethod$2248);
		if (pReq == (scene_request_class *)0x0) {
			iVar2 = -1;
		} else {
			if (fadeTime != 0x7fff) {
				ppuVar1 = &f_op_scene_req::fadeFase$2250[0];
				auto iVar2 = f_op_scene_req::fopScnRq_FadeRequest(fadeTime, param_6);
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
}

namespace f_op_scene_mng {
	void fopScnM_Init() {}

	int fopScnM_CreateReq(short procname, short fadeTime, ushort param_3, void *param_4) {
		return f_op_scene_req::fopScnRq_Request(0, (scene_class *)0x0, procname, param_4, fadeTime, param_3);
	}

	void f_op_scene_mng::fopScnM_Management(void) {
		int iVar1;
		ulong uVar2;

		iVar1 = f_op_scene_req::fopScnRq_Handler();
		if (iVar1 == 0) {
			JUTAssertion::getSDevice()->showAssert("f_op_scene_mng.cpp", 0x146, "0");
			m_Do_printf::OSPanic("f_op_scene_mng.cpp", 0x146, "Halt");
		}
	}

}