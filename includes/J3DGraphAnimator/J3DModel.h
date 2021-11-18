#pragma once
#include <ctypes.h>



namespace J3DModel {
//[Data] Expected size is 0x000020
extern pointer __vt;

//[Data] Expected size is 0x000004
extern pointer sNoUseDrawMtxPtr;

//[Data] Expected size is 0x000004
extern pointer sNoUseNrmMtxPtr;

}

namespace J3DGraphAnimator {
//[Data] Expected size is 0x000008
extern float J3DUnit01;

}

namespace J3DModel {
//[BSS] Expected size is 0x000030
extern undefined1 sNoUseDrawMtx;
//[BSS] Expected size is 0x000024
extern undefined1 sNoUseNrmMtx;
}

namespace J3DGraphAnimator {
void calcViewBaseMtx(MTX34 *param_1,float *param_2,float *param_3,MTX34 *param_4);
}
