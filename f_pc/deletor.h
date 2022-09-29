#pragma once

#include <JFramework/JUtility/JUTAssert.h>
#include <SComponent.h>
#include <machine/dolphin/printf.h>

#include "base.h"
#include "creator.h"
#include "executor.h"
#include "load.h"
#include "node.h"
#include "priority.h"

namespace f_pc_delete_tag {
	node_list_class g_fpcDtTg_Queue;
	void f_pc_delete_tag::fpcDtTg_ToDeleteQ(delete_tag_class *param_1) {
		param_1->mTimer = 1;
		SComponent::cTg_Addition(&f_pc_delete_tag::g_fpcDtTg_Queue, param_1);
	}

	void f_pc_delete_tag::fpcDtTg_DeleteQTo(create_tag_class *param_1)

	{
		SComponent::cTg_SingleCut(param_1);
		return;
	}

	int f_pc_delete_tag::fpcDtTg_Do(delete_tag_class *param_1, int *(*param_2)(void *)) {
		int *iVar1;
		undefined4 uVar2;

		if (param_1->mTimer < 1) {
			f_pc_delete_tag::fpcDtTg_DeleteQTo(param_1);
			iVar1 = param_2(param_1->mpTagData);
			if (iVar1 == 0) {
				f_pc_delete_tag::fpcDtTg_ToDeleteQ(param_1);
				uVar2 = 0;
			} else {
				uVar2 = 1;
			}
		} else {
			param_1->mTimer = param_1->mTimer + -1;
			uVar2 = 0;
		}
		return uVar2;
	}
}

namespace f_pc_deletor {

	bool f_pc_deletor::fpcDt_deleteMethod(base_process_class *param_1) {
		ushort uVar1;
		int iVar2;
		char *extraout_r4;
		layer_class *plVar3;

		plVar3 = (param_1->mDtTg).mpLayer;
		uVar1 = param_1->mBsTypeId;
		f_pc_layer::fpcLy_SetCurrentLayer(plVar3);
		f_pc_line_tag::fpcLnTg_QueueTo(&param_1->mLnTg);
		iVar2 = f_pc_base::fpcBs_Delete(param_1);
		if (iVar2 == 1) {
			f_pc_layer::fpcLy_DeletedMesg(plVar3);
			f_pc_load::fpcLd_Free(uVar1, extraout_r4);
		}
		return iVar2 == 1;
	}

	void f_pc_deletor::fpcDt_Handler(void) {
		SComponent::cLsIt_Method(&f_pc_delete_tag::g_fpcDtTg_Queue,
								 (SComponent::Method *)f_pc_delete_tag::fpcDtTg_Do,
								 f_pc_deletor::fpcDt_deleteMethod);
	}

	int f_pc_deletor::fpcDt_ToQueue(base_process_class *param_1)

	{
		int iVar1;

		if ((param_1->field3_0xa == 1) || (iVar1 = f_pc_base::fpcBs_IsDelete(param_1), iVar1 != 1)) {
			iVar1 = 0;
		} else {
			iVar1 = f_pc_priority::fpcPi_IsInQueue(&param_1->mPi);
			if (iVar1 == 1) {
				f_pc_priority::fpcPi_Delete(&param_1->mPi);
			}
			(param_1->mDtTg).mpLayer = (param_1->mLyTg).mpLayer;
			f_pc_delete_tag::fpcDtTg_ToDeleteQ(&param_1->mDtTg);
			f_pc_layer::fpcLy_DeletingMesg((param_1->mLyTg).mpLayer);
			iVar1 = 1;
		}
		return iVar1;
	}

	int f_pc_deletor::fpcDt_ToDeleteQ(process_node_class *param_1)

	{
		int iVar1;
		bool bVar4;
		ulong uVar2;
		uint uVar3;

		if (param_1->field3_0xa == 1) {
			iVar1 = 0;
		} else {
			iVar1 = SComponent::cTg_IsUse(&param_1->mDtTg);
			if (iVar1 == 0) {
				bVar4 = f_pc_base::fpcBs_Is_JustOfType(f_pc_node::g_fpcNd_type, param_1->mSubType);
				if (bVar4) {
					iVar1 = f_pc_node::fpcNd_IsDeleteTiming(param_1);
					if (iVar1 == 0) {
						return 0;
					}
					iVar1 = f_pc_layer::fpcLy_Cancel(&param_1->mLayer);
					if (iVar1 == 0) {
						JUTAssertion::getSDevice()->showAssert("f_pc_deletor.cpp", 0xc4, "0");
						m_Do_printf::OSPanic("f_pc_deletor.cpp", 0xc4, "Halt");
					}
					auto iVar1 = f_pc_layer_iter::fpcLyIt_OnlyHereLY(&param_1->mLayer, (SComponent::Method*)f_pc_deletor::fpcDt_ToDeleteQ, 0);
					if (iVar1 == 0) {
						return 0;
					}
				}
				iVar1 = f_pc_deletor::fpcDt_ToQueue(param_1);
				if (iVar1 == 1) {
					iVar1 = f_pc_executor::fpcEx_IsExist(param_1->mBsPcId);
					if (iVar1 == 1) {
						uVar3 = f_pc_executor::fpcEx_ExecuteQTo(param_1);
						if (uVar3 == 0) {
							return 0;
						}
					} else {
						iVar1 = f_pc_creator::fpcCt_Abort(param_1);
						if (iVar1 == 0) {
							return 0;
						}
					}
					param_1->mInitState = 3;
					iVar1 = 1;
				} else {
					iVar1 = 0;
				}
			} else {
				iVar1 = 1;
			}
		}
		return iVar1;
	}

	int fpcDt_Delete(base_process_class *param_1) {
		int iVar1;

		if (param_1 == (base_process_class *)0x0) {
			iVar1 = 1;
		} else {
			iVar1 = f_pc_creator::fpcCt_IsDoing(param_1);
			if (iVar1 == 1) {
				iVar1 = 0;
			} else if (param_1->mInitState == 3) {
				iVar1 = 0;
			} else {
				iVar1 = f_pc_deletor::fpcDt_ToDeleteQ((process_node_class*)param_1);
			}
		}
		return iVar1;
	}

}