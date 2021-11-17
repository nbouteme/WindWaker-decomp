#pragma once
#include <ctypes.h>

#include <dMi_HIO_c.h>


namespace d_menu_item {
//Expected size is 0x000060
extern struct dMi_HIO_c g_miHIO;

}

namespace d_menu_item {
void __sinit_d_menu_item_cpp(void);
}
