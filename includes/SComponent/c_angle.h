#pragma once
#include <ctypes.h>

#include <cSAngle.h>

//[BSS] Expected size is 0x000002
extern struct cSAngle cSAngle;
//[BSS] Expected size is 0x000002
extern undefined1 cSAngle;
//[BSS] Expected size is 0x000002
extern undefined1 cSAngle;
//[BSS] Expected size is 0x000002
extern undefined1 cSAngle;
//[BSS] Expected size is 0x000002
extern undefined1 cSAngle;

namespace SComponent {
void operator_+(cSAngle *param_1,short param_2,short *param_3);
void operator_-(cSAngle *param_1,short param_2,short *param_3);
}

namespace SComponent {
void __sinit_c_angle_cpp(void);
}
