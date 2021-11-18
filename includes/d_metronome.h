#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x00000c
extern undefined1 dMn_HIO_c;


namespace d_metronome {
//[BSS] Expected size is 0x000020
extern undefined g_mnHIO;
}

namespace d_metronome {
void __sinit_d_metronome_cpp(void);
}
