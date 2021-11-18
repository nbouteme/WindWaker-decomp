#pragma once
#include <ctypes.h>



namespace JASystem {
//[Data] Expected size is 0x000028
extern undefined1 history;

//[Data] Expected size is 0x000004
extern undefined1 TDSPChannel;

//[Data] Expected size is 0x000004
extern undefined1 DSP_LIMIT_RATIO;

//[BSS] Expected size is 0x000004
extern undefined1 TDSPChannel;
//[BSS] Expected size is 0x000004
extern undefined1 TDSPChannel;
}

namespace JAudio {
//[BSS] Expected size is 0x000004
extern undefined4 first$417;
//[BSS] Expected size is 0x000001
extern undefined1 init$418;
}

namespace JASystem {
//[BSS] Expected size is 0x000004
extern undefined1 old_time;
}
