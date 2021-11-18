#pragma once
#include <ctypes.h>



namespace JASystem {
//[Data] Expected size is 0x000040
extern undefined1 WaveArcLoader;

//[Data] Expected size is 0x000014
extern undefined1 TWaveArc;


namespace Kernel {

namespace TDisposer {
//[Data] Expected size is 0x00000c
extern undefined1 __vt;

}
}
//[BSS] Expected size is 0x000048
extern undefined1 WaveArcLoader;

namespace Kernel {
}
void __sinit_JASWaveArcLoader_cpp(void);
}
