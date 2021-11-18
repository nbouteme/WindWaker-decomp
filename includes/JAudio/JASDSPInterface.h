#pragma once
#include <ctypes.h>



namespace JASystem {
//[Data] Expected size is 0x000018
extern undefined1 DSPInterface;

//[Data] Expected size is 0x000002
extern undefined1 DSPInterface;

}

namespace JAudio {
//[Data] Expected size is 0x000008
extern undefined COMP_BLOCKSAMPLES$485;

//[Data] Expected size is 0x000008
extern undefined COMP_BLOCKBYTES$486;

}

namespace JASystem {
//[BSS] Expected size is 0x000960
extern undefined1 DSPInterface;
//[BSS] Expected size is 0x000004
extern undefined1 DSPInterface;
//[BSS] Expected size is 0x000004
extern undefined1 DSPInterface;
//[BSS] Expected size is 0x000004
extern undefined1 DSPInterface;

namespace DSPInterface {
}
uint DSP_CreateMap2(int param_1);
}
