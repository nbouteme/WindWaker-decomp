#include "line.h"

namespace f_pc_line_tag {

	void fpcLnTg_QueueTo(line_tag *param_1) {
		SComponent::cTg_SingleCutFromTree(param_1);
		param_1->mLineListID = -1;
	}

	uint fpcLnTg_Move(line_tag *param_1, int param_2)

	{
		uint uVar1;

		if (param_1->mLineListID == param_2) {
			uVar1 = 1;
		} else {
			fpcLnTg_QueueTo(param_1);
			uVar1 = fpcLnTg_ToQueue(param_1, param_2);
		}
		return uVar1;
	}

	uint fpcLnTg_ToQueue(line_tag *param_1, int param_2)

	{
		int iVar1;

		iVar1 = SComponent::cTg_AdditionToTree(&f_pc_line::g_fpcLn_Queue, param_2, param_1);
		if (iVar1 != 0) {
			param_1->mLineListID = param_2;
		}
		return (uint)(iVar1 != 0);
	}

}