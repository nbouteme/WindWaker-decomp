#pragma once

#include "base.h"
#include "layer.h"
#include "line.h"
#include "searcher.h"

namespace f_pc_executor {

	undefined4 f_pc_executor::fpcEx_ToLineQ(process_node_class *param_1)

	{
		layer_class *plVar1;
		int iVar2;
		uint uVar3;
		undefined4 uVar4;
		bool bVar5;

		plVar1 = param_1->mLyTg.mpLayer;
		if ((plVar1->mLayerID == 0) ||
			(iVar2 = SComponent::cTg_IsUse(&plVar1->mpPcNode->mLnTg), iVar2 == 1)) {
			uVar3 = f_pc_line_tag::fpcLnTg_ToQueue(&param_1->mLnTg, (uint)param_1->mPi.mListIDCurr);
			if (uVar3 == 0) {
				f_pc_layer_tag::fpcLyTg_QueueTo(&param_1->mLyTg);
				uVar4 = 0;
			} else {
				param_1->mInitState = 2;
				bVar5 = f_pc_base::fpcBs_Is_JustOfType(f_pc_node::g_fpcNd_type, param_1->mSubType);
				if (bVar5) {
					f_pc_layer_iter::fpcLyIt_OnlyHere(&param_1->mLayer, (SComponent::Method*)f_pc_executor::fpcEx_ToLineQ, param_1);
				}
				uVar4 = 1;
			}
		} else {
			uVar4 = 0;
		}
		return uVar4;
	}

	void *f_pc_executor::fpcEx_Search(SComponent::Judge *param_1, void *param_2)

	{
		void *pvVar1;

		pvVar1 = f_pc_layer_iter::fpcLyIt_AllJudge(param_1, param_2);
		return pvVar1;
	}

	void *f_pc_executor::fpcEx_SearchByID(int param_1) {
		void *pvVar1;
		int local_8[2];

		if (param_1 + 2U < 2) {
			pvVar1 = (void *)0x0;
		} else {
			local_8[0] = param_1;
			pvVar1 = f_pc_executor::fpcEx_Search((SComponent::Judge *)f_pc_searcher::fpcSch_JudgeByID, local_8);
		}
		return pvVar1;
	}

	void *f_pc_executor::fpcEx_Execute(base_process_class *param_1) {
		int iVar1;

		if ((param_1->mInitState == 2) && (iVar1 = f_pc_pause::fpcPause_IsEnable(param_1, 1), iVar1 != 1)) {
			f_pc_base::fpcBs_Execute(param_1);
		} else {
			param_1 = (base_process_class *)0x0;
		}
		return param_1;
	}

	void f_pc_executor::fpcEx_Handler(SComponent::Method *param_1) {
		f_pc_line_iter::fpcLnIt_Queue(param_1);
		return;
	}

	bool f_pc_executor::fpcEx_ToExecuteQ(base_process_class *param_1) {
		int iVar1;

		iVar1 = f_pc_layer_tag::fpcLyTg_ToQueue(&param_1->mLyTg, (param_1->mPi).mLayerCurr, (param_1->mPi).mListIDCurr,
												(param_1->mPi).mListPrioCurr);
		if (iVar1 == 1) {
			f_pc_executor::fpcEx_ToLineQ((process_node_class *)param_1);
		}
		return iVar1 == 1;
	}

	bool f_pc_executor::fpcEx_IsExist(int param_1) {
		return f_pc_executor::fpcEx_SearchByID(param_1) != nullptr;
	}

	uint f_pc_executor::fpcEx_ExecuteQTo(base_process_class *param_1) {
		int iVar1;

		iVar1 = f_pc_layer_tag::fpcLyTg_QueueTo(&param_1->mLyTg);
		if (iVar1 == 1) {
			param_1->mInitState = 3;
		}
		return (uint)(iVar1 == 1);
	}

}