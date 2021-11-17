#pragma once
#include <ctypes.h>

#include <daCLOTH_HIO_c.h>


namespace d_menu_cloth {
//Expected size is 0x000110
extern struct daCLOTH_HIO_c l_HIO;

}
//Expected size is 0x000002
extern undefined1 dMCloth_c;


namespace d_menu_cloth {
undefined4 dMenu_ClothCreate(void);
undefined4 dMenu_ClothDelete(void);
undefined4 dMenu_ClothExecute(void);
undefined4 dMenu_ClothDraw(void);
undefined4 dMenu_ClothIsDelete(void);
}

namespace d_menu_cloth {
void __sinit_d_menu_cloth_cpp(void);
}
