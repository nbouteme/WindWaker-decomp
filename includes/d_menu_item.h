#pragma once
#include <ctypes.h>

#include <dMi_HIO_c.h>


namespace d_menu_item {
//[Data] Expected size is 0x000028
extern undefined * number$7119;

}
//[Data] Expected size is 0x000028
extern undefined1 dMenu_Item_c;

//[Data] Expected size is 0x00000c
extern undefined1 dMi_HIO_c;


namespace d_menu_item {
//[BSS] Expected size is 0x000060
extern struct dMi_HIO_c g_miHIO;
}

namespace d_menu_item {
void __sinit_d_menu_item_cpp(void);
}
