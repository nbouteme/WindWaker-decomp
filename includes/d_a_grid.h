#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <f_pc_profile__Profile_Actor.h>


namespace d_a_grid {
//[Data] Expected size is 0x0003fc
extern undefined4 l_pos;

//[Data] Expected size is 0x0002a8
extern undefined l_texCoord;

//[Data] Expected size is 0x000233
extern undefined l_DL;

//[Data] Expected size is 0x000034
extern undefined l_matDL;

//[Data] Expected size is 0x000034
extern undefined4 z_rate_tbl$4444;

//[Data] Expected size is 0x000034
extern undefined4 z_rate_tbl2$4445;

//[Data] Expected size is 0x000034
extern undefined4 x_rate_tbl$4446;

//[Data] Expected size is 0x000020
extern struct profile_method_class l_daGrid_Method;

//[Data] Expected size is 0x000030
extern struct f_pc_profile__Profile_Actor g_profile_GRID;

}
//[Data] Expected size is 0x000018
extern undefined daHo_packet_c;

//[Data] Expected size is 0x00000c
extern undefined1 daHo_HIO_c;


namespace d_a_grid {
//[BSS] Expected size is 0x0000a4
extern undefined4 l_HIO;
//[BSS] Expected size is 0x000004
extern undefined4 l_ship;
}

namespace d_a_grid {
undefined daGrid_Draw(daGrid_c *param_1);
void ho_move(int param_1);
undefined daGrid_Execute(daGrid_c *param_1);
undefined4 daGrid_IsDelete(void);
undefined daGrid_Delete(daGrid_c *param_1);
void daGrid_Create(daGrid_c *param_1);
}

namespace d_a_grid {
void __sinit_d_a_grid_cpp(void);
}
