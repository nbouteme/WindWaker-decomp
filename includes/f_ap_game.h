#pragma once
#include <ctypes.h>

#include <fapGm_HIO_c.h>


namespace f_ap_game {
//Expected size is 0x000058
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
