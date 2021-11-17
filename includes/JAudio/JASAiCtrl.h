#pragma once
#include <ctypes.h>



namespace JASystem {
//Expected size is 0x00000c
extern undefined1 Kernel;

//Expected size is 0x000004
extern undefined1 Kernel;

//Expected size is 0x000004
extern undefined1 Kernel;

//Expected size is 0x000004
extern undefined1 Kernel;

//Expected size is 0x000004
extern undefined1 Kernel;

//Expected size is 0x000004
extern undefined1 Kernel;

//Expected size is 0x000004
extern undefined1 Kernel;

//Expected size is 0x000004
extern pointer Kernel;

//Expected size is 0x000001
extern undefined1 Kernel;

}

namespace JAudio {
//Expected size is 0x000004
extern undefined4 dacp$389;

//Expected size is 0x000001
extern undefined1 init$390;

}

namespace JASystem {

namespace Kernel {
void registerMixCallback(FuncDef562 *param_1,uchar param_2);
}

namespace Kernel {
void mixMonoTrack(short *param_1,long param_2,FuncDef563 *param_3);
void mixMonoTrackWide(short *param_1,long param_2,FuncDef564 *param_3);
void mixExtraTrack(short *param_1,long param_2,FuncDef565 *param_3);
void mixInterleaveTrack(short *param_1,long param_2,FuncDef566 *param_3);
}
}
