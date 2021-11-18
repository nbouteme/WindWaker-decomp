#pragma once
#include <ctypes.h>



namespace d_gameover {
//[Data] Expected size is 0x000014
extern undefined * l_dGameover_Method;

//[Data] Expected size is 0x000028
extern undefined g_profile_GAMEOVER;

}
//[Data] Expected size is 0x000010
extern undefined1 dDlst_GameOverScrnDraw_c;

//[Data] Expected size is 0x00000c
extern undefined1 dMenu_save_c;

//[Data] Expected size is 0x000010
extern undefined1 dDlst_Gameover_CAPTURE_c;


namespace d_gameover {
//[Data] Expected size is 0x000002
extern undefined2 dGover_tex_number;

}

namespace d_gameover {
void dGameover_Draw(dGameover_c *param_1);
void dGameover_Execute(dGameover_c *param_1);
undefined4 dGameover_IsDelete(void);
void dGameover_Delete(dGameover_c *param_1);
void dGameover_Create(dGameover_c *param_1);
}
