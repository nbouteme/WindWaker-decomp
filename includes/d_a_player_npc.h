#pragma once
#include <ctypes.h>



namespace d_a_player_npc {
//[BSS] Expected size is 0x00000c
extern undefined4 l_offsetPos$4174;
//[BSS] Expected size is 0x000001
extern undefined1 init$4176;
}

namespace d_a_player_npc {
undefined4 daPy_npc_JudgeForPNameAndDistance(fopAc_ac_c *param_1,short *param_2);
fopAc_ac_c *daPy_npc_SearchAreaByName(daPy_npc_c *param_1,short procName,double dist,cXyz *param_4);
}
