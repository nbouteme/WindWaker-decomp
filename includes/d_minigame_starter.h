#pragma once
#include <ctypes.h>



namespace d_minigame_starter {
//[Data] Expected size is 0x00000c
extern undefined4 label_t$4075;

//[Data] Expected size is 0x000014
extern undefined * l_dMinigame_Starter_Method;

//[Data] Expected size is 0x000028
extern undefined g_profile_MINIGAME_STARTER;

}
//[Data] Expected size is 0x000010
extern undefined1 dDlst_StarterScrnDraw_c;


namespace d_minigame_starter {
//[Data] Expected size is 0x000002
extern undefined2 cdFrame0;

//[Data] Expected size is 0x000002
extern undefined2 cdFrame1;

//[Data] Expected size is 0x000002
extern undefined2 tmFrame;

//[Data] Expected size is 0x000002
extern undefined2 cdFrame2;

//[Data] Expected size is 0x000002
extern undefined2 cdFrame3;

//[Data] Expected size is 0x000002
extern undefined2 cdFrame4;

//[Data] Expected size is 0x000002
extern undefined2 cdFrame5;

//[Data] Expected size is 0x000002
extern undefined2 cdFrame6;

//[Data] Expected size is 0x000002
extern undefined2 cdFrame7;

//[Data] Expected size is 0x000002
extern undefined2 cdFrame8;

//[Data] Expected size is 0x000002
extern undefined2 dMinigame_Starter_tex_number;

}

namespace d_minigame_starter {
void dMinigame_Starter_Draw(dMinigame_Starter_c *param_1);
void dMinigame_Starter_Execute(dMinigame_Starter_c *param_1);
undefined4 dMinigame_Starter_IsDelete(void);
void dMinigame_Starter_Delete(dMinigame_Starter_c *param_1);
void dMinigame_Starter_Create(dMinigame_Starter_c *param_1);
}
