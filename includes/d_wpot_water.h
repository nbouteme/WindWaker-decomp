#pragma once
#include <ctypes.h>



namespace d_wpot_water {
//[Data] Expected size is 0x000014
extern undefined * l_dWpotWater_Method;

//[Data] Expected size is 0x000028
extern undefined g_profile_WPOT_WATER;

}
//[Data] Expected size is 0x000020
extern undefined1 dWpotWater_EcallBack;


namespace dWpotWater_c {
//[BSS] Expected size is 0x000004
extern undefined1 mEcallback;
}

namespace d_wpot_water {
undefined4 dWpotWater_Draw(int param_1);
undefined4 dWpotWater_Execute(int param_1);
undefined4 dWpotWater_IsDelete(void);
undefined4 dWpotWater_Delete(void);
undefined4 dWpotWater_Create(int param_1);
}

namespace d_wpot_water {
void __sinit_d_wpot_water_cpp(void);
}
