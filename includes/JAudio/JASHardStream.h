#pragma once
#include <ctypes.h>



namespace JASystem {
//[Data] Expected size is 0x000020
extern undefined1 HardStream;

//[Data] Expected size is 0x000004
extern undefined1 HardStream;

//[BSS] Expected size is 0x000050
extern undefined1 HardStream;
}

namespace JAudio {
//[BSS] Expected size is 0x0000b4
extern undefined finfo$822;
//[BSS] Expected size is 0x000300
extern undefined get_addr_cmd$826;
//[BSS] Expected size is 0x000030
extern undefined stop_cmd$827;
//[BSS] Expected size is 0x000030
extern undefined finish_cmd$828;
}

namespace JASystem {
//[BSS] Expected size is 0x000001
extern undefined1 HardStream;
//[BSS] Expected size is 0x000004
extern undefined1 HardStream;
//[BSS] Expected size is 0x000004
extern undefined1 HardStream;
}

namespace JAudio {
//[BSS] Expected size is 0x000004
extern undefined4 cur_finfo$823;
//[BSS] Expected size is 0x000001
extern undefined1 init$824;
//[BSS] Expected size is 0x000001
extern undefined1 cur_addr_cmd$829;
//[BSS] Expected size is 0x000001
extern undefined1 init$830;
//[BSS] Expected size is 0x000004
extern undefined4 last_frame$988;
//[BSS] Expected size is 0x000001
extern undefined1 init$989;
}

namespace JASystem {

namespace HardStream {
}
void __sinit_JASHardStream_cpp(void);

namespace HardStream {
}
}
