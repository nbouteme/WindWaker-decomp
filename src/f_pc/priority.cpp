#include "priority.h"

#include "layer.h"
#include "line.h"

namespace f_pc_priority {
	node_list_class l_fpcPi_Queue;

	bool fpcPi_IsNormal(uint param_1, ushort param_2, ushort param_3) {
		if (((param_1 < 0xfffffffe) && (param_2 < 0xfffe)) && (param_3 < 0xfffe)) {
			return true;
		}
		return false;
	}

	uint fpcPi_Init(process_priority_class *param_1, void *param_2, uint param_3, ushort param_4, ushort param_5) {
		bool bVar1;

		bVar1 = f_pc_priority::fpcPi_IsNormal(param_3, param_4, param_5);
		if (bVar1) {
			param_1->mLayerQ = param_3;
			param_1->mListIDQ = param_4;
			param_1->mListPrioQ = param_5;
			param_1->mLayerCurr = param_1->mLayerQ;
			param_1->mListIDCurr = param_1->mListIDQ;
			param_1->mListPrioCurr = param_1->mListPrioQ;
			SComponent::cTg_Create(param_1, param_2);
			f_pc_method_tag::fpcMtdTg_Init(&param_1->mMtdTg, (void*)f_pc_priority::fpcPi_Delete, (void*)param_1);
		}
		return (uint)bVar1;
	}

	process_priority_class *fpcPi_GetFromQueue(void) {
		process_priority_class *pPrio;
		base_process_class *pcVar1;
		process_priority_class *ppVar2;

		pPrio = (process_priority_class *)SComponent::cTg_GetFirst(&l_fpcPi_Queue);
		if (pPrio == (process_priority_class *)0x0) {
			ppVar2 = (process_priority_class *)0x0;
		} else {
			pcVar1 = pPrio->mpTagData.bproc;
			ppVar2 = &pcVar1->mPi;
			f_pc_layer::fpcLy_CancelQTo(&(pcVar1->mPi).mMtdTg);
		}
		return ppVar2;
	}

	int fpcPi_Handler(void) {
		base_process_class *pProc;
		int iVar1;
		process_priority_class *ppVar2;

		while (true) {
			ppVar2 = fpcPi_GetFromQueue();
			if (ppVar2 == (process_priority_class *)0x0) {
				return 1;
			}
			pProc = ppVar2->mpTagData.bproc;
			iVar1 = f_pc_layer_tag::fpcLyTg_Move(&pProc->mLyTg, ppVar2->mLayerQ, ppVar2->mListIDQ, ppVar2->mListPrioQ);
			if (iVar1 != 1)
				break;
			f_pc_line_tag::fpcLnTg_Move(&pProc->mLnTg, ppVar2->mListIDCurr);
			ppVar2->mLayerCurr = ppVar2->mLayerQ;
			ppVar2->mListIDCurr = ppVar2->mListIDQ;
			ppVar2->mListPrioCurr = ppVar2->mListPrioQ;
		}
		return 0;
	}

	int fpcPi_IsInQueue(create_tag_class *param_1) {
		return SComponent::cTg_IsUse(param_1);
	}

	uint crear$2186 = ~0;

	undefined4 fpcPi_QueueTo(process_priority_class *param_1) {
		SComponent::cTg_SingleCut(param_1);
		f_pc_layer::fpcLy_CancelQTo(&param_1->mMtdTg);
		return 1;
	}

	undefined4 fpcPi_Delete(process_priority_class *param_1) {
		fpcPi_QueueTo(param_1);
		param_1->mLayerQ = crear$2186;
		param_1->mListIDQ = ~0;
		param_1->mListPrioQ = ~0;
		return 1;
	}
}