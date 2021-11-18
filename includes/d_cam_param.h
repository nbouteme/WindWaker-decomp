#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x00000c
extern pointer dCamSetup_c;

//[Data] Expected size is 0x00000c
extern pointer dCamParam_c;

//[Data] Expected size is 0x00000c
extern pointer dCstick_c;


namespace dCamMath {
double rationalBezierRatio(float param_1,float param_2);
float customRBRatio(float param_1,float param_2);
}

namespace dCamMath {
void xyzRotateY(cXyz *param_1,cSAngle param_2);
double xyzHorizontalDistance(cXyz *param_1,cXyz *param_2);
}
