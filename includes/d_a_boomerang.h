#pragma once
#include <ctypes.h>



namespace d_a_boomerang {
//Expected size is 0x00000c
extern undefined4 l_blur_top;

//Expected size is 0x00000c
extern undefined4 l_blur_root;

//Expected size is 0x000020
extern undefined texObj$4441;

//Expected size is 0x00000c
extern undefined at_offset$5155;

//Expected size is 0x000001
extern undefined1 init$5157;

}

namespace d_a_boomerang {
void daBoomerang_Draw(daBoomerang_c *param_1);
}

namespace d_a_boomerang {
void daBoomerang_rockLineCallback(daBoomerang_c *param_1,undefined4 param_2,fopAc_ac_c *param_3);
}

namespace d_a_boomerang {
void daBoomerang_Execute(daBoomerang_c *param_1);
undefined4 daBoomerang_IsDelete(void);
undefined4 daBoomerang_Delete(void);
}

namespace d_a_boomerang {
void daBoomerang_createHeap(daBoomerang_c *param_1);
}

namespace d_a_boomerang {
void daBoomerang_Create(daBoomerang_c *param_1);
void __sinit_d_a_boomerang_cpp(void);
}
