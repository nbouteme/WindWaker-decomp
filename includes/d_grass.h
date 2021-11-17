#pragma once
#include <ctypes.h>



namespace d_grass {
//Expected size is 0x000001
extern undefined1 l_CutSoundFlag;

//Expected size is 0x000001
extern undefined1 init$4375;

//Expected size is 0x000006
extern undefined ang$4373;

void setBatta(cXyz *param_1,_GXColor *param_2);
}

namespace d_grass {
double checkGroundY(cXyz *pPos);
}

namespace d_grass {
void __sinit_d_grass_cpp(void);
}
