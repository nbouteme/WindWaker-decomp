#include "scene.h"

#include <f_pc/manager.h>

namespace f_op_scene_pause {

	undefined4 fopScnPause_Disable(scene_class *param_1)

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