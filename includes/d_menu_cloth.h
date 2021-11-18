#pragma once
#include <ctypes.h>

#include <daCLOTH_HIO_c.h>


namespace d_menu_cloth {
//[Data] Expected size is 0x000034
extern undefined l_matDL;

//[Data] Expected size is 0x000014
extern undefined * dMenu_ClothMethodTable;

//[Data] Expected size is 0x000028
extern undefined g_profile_Menu_Cloth;

}
//[Data] Expected size is 0x00000c
extern undefined1 dMCloth_c;

//[Data] Expected size is 0x00000c
extern undefined1 daCLOTH_ChildHIO_c;

//[Data] Expected size is 0x00000c
extern undefined1 daCLOTH_HIO_c;


namespace d_menu_cloth {
//[BSS] Expected size is 0x000110
extern struct daCLOTH_HIO_c l_HIO;
}
//[BSS] Expected size is 0x000002
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
