#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x000030
extern pointer dBgW;


namespace cM3dGTri {
//[Data] Expected size is 0x00000c
extern pointer __vt;

}

namespace d_bg_w {
dBgW * dBgW_NewSet(cBgD_t *param_1,cBgW__Flag param_2,MTX34 *param_3);
}
