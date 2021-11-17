#pragma once
#include <ctypes.h>



namespace J3DModel {
//Expected size is 0x000030
extern undefined1 sNoUseDrawMtx;

//Expected size is 0x000024
extern undefined1 sNoUseNrmMtx;

}

namespace J3DGraphAnimator {
void calcViewBaseMtx(MTX34 *param_1,float *param_2,float *param_3,MTX34 *param_4);
}
