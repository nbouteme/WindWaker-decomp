#include <JFramework/JUtility/JUTAssert.h>
#include <machine/dolphin/printf.h>

#include "base.h"
#include "creator.h"
#include "executor.h"
#include "load.h"
#include "node.h"
#include "priority.h"

#include "deletor.h"

namespace f_pc_delete_tag {
	node_list_class g_fpcDtTg_Queue;
	void fpcDtTg_ToDeleteQ(delete_tag_class *param_1) {
		param_1->mTimer = 1;
		SComponent::cTg_Addition(&g_fpcDtTg_Queue, param_1);
	}

	void fpcDtTg_DeleteQTo(create_tag_class *param_1)

	{
		SComponent::cTg_SingleCut(param_1);
		return;
	}

	int fpcDtTg_Do(delete_tag_class *param_1, int *(*param_2)(void *)) {
		int *iVar1;
		undefined4 uVar2;

		if (param_1->mTimer < 1) {
			fpcDtTg_DeleteQTo(param_1);
			iVar1 = param_2(param_1->mpTagData);
			if (iVar1 == 0) {
				fpcDtTg_ToDeleteQ(param_1);
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
