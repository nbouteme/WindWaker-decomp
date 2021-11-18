#pragma once
#include <ctypes.h>



namespace d_menu_dmap {
//[Data] Expected size is 0x000050
extern undefined * floor_name$4096;

//[Data] Expected size is 0x00000c
extern pointer itmTex$4114;

}
//[Data] Expected size is 0x000028
extern undefined1 dMenu_Dmap_c;

//[Data] Expected size is 0x00000c
extern undefined1 dMd_HIO_c;


namespace d_menu_dmap {
//[BSS] Expected size is 0x00004c
extern undefined g_mdHIO;
}

namespace d_menu_dmap {
undefined4 dMap_isBossDoor(char *param_1);
}

namespace d_menu_dmap {
void __sinit_d_menu_dmap_cpp(void);
}
