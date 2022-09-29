#pragma once

#include <SComponent.h>

namespace f_pc_priority {
	node_list_class l_fpcPi_Queue;

	process_priority_class *f_pc_priority::fpcPi_GetFromQueue(void) {
		process_priority_class *pPrio;
		base_process_class *pcVar1;
		process_priority_class *ppVar2;

		pPrio = (process_priority_class *)SComponent::cTg_GetFirst(&f_pc_priority::l_fpcPi_Queue);
		if (pPrio == (process_priority_class *)0x0) {
			ppVar2 = (process_priority_class *)0x0;
		} else {
			pcVar1 = (base_process_class *)pPrio->mpTagData;
			ppVar2 = &pcVar1->mPi;
			f_pc_layer::fpcLy_CancelQTo(&(pcVar1->mPi).mMtdTg);
		}
		return ppVar2;
	}

	int f_pc_priority::fpcPi_Handler(void) {
		base_process_class *pProc;
		int iVar1;
		process_priority_class *ppVar2;

		while (true) {
			ppVar2 = f_pc_priority::fpcPi_GetFromQueue();
			if (ppVar2 == (process_priority_class *)0x0) {
				return 1;
			}
			pProc = (base_process_class *)ppVar2->mpTagData;
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

	undefined4 f_pc_priority::fpcPi_QueueTo(process_priority_class *param_1) {
		SComponent::cTg_SingleCut(param_1);
		f_pc_layer::fpcLy_CancelQTo(&param_1->mMtdTg);
		return 1;
	}

	undefined4 f_pc_priority::fpcPi_Delete(process_priority_class *param_1) {
		f_pc_priority::fpcPi_QueueTo(param_1);
		param_1->mLayerQ = f_pc_priority::crear$2186;
		param_1->mListIDQ = ~0;
		param_1->mListPrioQ = ~0;
		return 1;
	}
}