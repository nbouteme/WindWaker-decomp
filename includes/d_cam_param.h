#pragma once
#include <ctypes.h>



namespace dCamMath {
double rationalBezierRatio(float param_1,float param_2);
float customRBRatio(float param_1,float param_2);
}

namespace dCamMath {
void xyzRotateY(cXyz *param_1,cSAngle param_2);
double xyzHorizontalDistance(cXyz *param_1,cXyz *param_2);
}
