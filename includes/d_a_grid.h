#pragma once
#include <ctypes.h>



namespace d_a_grid {
//Expected size is 0x0000a4
extern undefined4 l_HIO;

//Expected size is 0x000004
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
