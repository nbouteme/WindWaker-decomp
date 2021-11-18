#pragma once
#include <ctypes.h>



namespace d_menu_save {
//[Data] Expected size is 0x0001d4
extern undefined4 MenuSaveProc;

}
//[Data] Expected size is 0x000010
extern undefined1 dDlst_MenuSave_c;

//[Data] Expected size is 0x00000c
extern undefined1 dFile_error_c;

//[Data] Expected size is 0x00000c
extern undefined1 dMs_HIO_c;


namespace d_menu_save {
//[BSS] Expected size is 0x000030
extern undefined g_msHIO;
}

namespace d_menu_save {
void __sinit_d_menu_save_cpp(void);
}
