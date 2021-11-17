#pragma once
#include <ctypes.h>



namespace J3DGraphAnimator {
double J3DHermiteInterpolationS(double param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7);
double J3DGetKeyFrameInterpolationS(double param_1,ushort *param_2,short *param_3);
}

namespace J3DGraphAnimator {
double J3DGetKeyFrameInterpolation(double param_1,J3DAnmKeyTableBase *animationTrack,short *trackData);
double J3DGetKeyFrameInterpolation(double param_1,ushort *param_2,float *param_3);
}
