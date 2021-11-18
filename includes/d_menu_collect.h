#pragma once
#include <ctypes.h>



namespace d_menu_collect {
//[Data] Expected size is 0x000020
extern pointer triTex$4147;

//[Data] Expected size is 0x00000c
extern pointer symTex$4153;

//[Data] Expected size is 0x000014
extern pointer wepTex$4159;

}
//[Data] Expected size is 0x00000c
extern undefined1 dMenu_Option_c;

//[Data] Expected size is 0x000028
extern undefined1 dMenu_Collect_c;

//[Data] Expected size is 0x000028
extern undefined1 dMenu_base_c;

//[Data] Expected size is 0x00000c
extern undefined1 dMc_HIO_c;


namespace d_menu_collect {
//[BSS] Expected size is 0x000060
extern undefined g_mcHIO;
}

namespace d_menu_collect {
void __sinit_d_menu_collect_cpp(void);
}
