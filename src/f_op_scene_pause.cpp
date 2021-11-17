#include <f_op_scene_pause.h>
#include <f_pc_manager.h>
#include <f_pc_executor.h>


namespace f_op_scene_pause {

/* __stdcall fopScnPause_Enable(scene_class *) */

bool fopScnPause_Enable(int param_1)

{
  if (param_1 != 0) {
    f_pc_manager::fpcM_PauseEnable(param_1,1);
    f_pc_manager::fpcM_PauseEnable(param_1,2);
  }
  return param_1 != 0;
}


/* __stdcall fopScnPause_Disable(scene_class *) */

undefined4 fopScnPause_Disable(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar3 = *(int *)(*(int *)(param_1 + 0x2c) + 0x18);
    if (iVar3 == 0) {
      f_pc_manager::fpcM_PauseDisable(param_1,1);
      f_pc_manager::fpcM_PauseDisable(param_1,2);
    }
    else {
      iVar1 = f_pc_executor::fpcEx_IsExist(*(undefined4 *)(iVar3 + 4));
      if (iVar1 == 1) {
        iVar1 = f_pc_manager::fpcM_IsPause(iVar3,1);
        if (iVar1 == 0) {
          f_pc_manager::fpcM_PauseDisable(param_1,1);
        }
        iVar3 = f_pc_manager::fpcM_IsPause(iVar3,2);
        if (iVar3 == 0) {
          f_pc_manager::fpcM_PauseDisable(param_1,2);
        }
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}

