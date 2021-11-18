#pragma once
#include <ctypes.h>

#include <fapGm_HIO_c.h>

//[Data] Expected size is 0x00000c
extern pointer fapGm_HIO_c;


namespace f_ap_game {
//[BSS] Expected size is 0x000058
extern struct fapGm_HIO_c g_HIO;
}

namespace f_ap_game {
void fapGm_After(void);
void fapGm_Execute(void);
void fapGm_Create(void);
}

namespace f_ap_game {
void __sinit_f_ap_game_cpp(void);
}
