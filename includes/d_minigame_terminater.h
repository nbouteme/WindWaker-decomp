#pragma once
#include <ctypes.h>



namespace d_minigame_terminater {
//[Data] Expected size is 0x000028
extern undefined * number$4258;

//[Data] Expected size is 0x000014
extern undefined * l_dMinigame_Terminater_Method;

//[Data] Expected size is 0x000028
extern undefined g_profile_MINIGAME_TERMINATER;

}
//[Data] Expected size is 0x000010
extern undefined1 dDlst_TerminaterScrnDraw_c;


namespace d_minigame_terminater {
//[Data] Expected size is 0x000002
extern undefined2 dMgtem_perfect_tex;

//[Data] Expected size is 0x000002
extern undefined2 dMgtem_failed_tex;

//[Data] Expected size is 0x000002
extern undefined2 dMgtem_yougot_tex;

//[Data] Expected size is 0x000002
extern undefined2 dMgtem_remain_tex;

}

namespace d_minigame_terminater {
void dMinigame_Terminater_Draw(dMinigame_Terminater_c *param_1);
void dMinigame_Terminater_Execute(dMinigame_Terminater_c *param_1);
undefined4 dMinigame_Terminater_IsDelete(void);
void dMinigame_Terminater_Delete(dMinigame_Terminater_c *param_1);
void dMinigame_Terminater_Create(dMinigame_Terminater_c *param_1);
}
