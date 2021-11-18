#pragma once
#include <ctypes.h>



namespace d_wpillar {
//[Data] Expected size is 0x000014
extern undefined * l_dWpillar_Method;

//[Data] Expected size is 0x000028
extern undefined g_profile_WPILLAR;

}

namespace d_wpillar {
undefined4 dWpillar_jointCallBack(int param_1,int param_2);
}

namespace d_wpillar {
void dWpillar_Draw(dWpillar_c *param_1);
}

namespace d_wpillar {
void dWpillar_Execute(dWpillar_c *param_1);
undefined4 dWpillar_IsDelete(void);
}

namespace d_wpillar {
void dWpillar_Delete(dWpillar_c *param_1);
}

namespace d_wpillar {
void dWpillar_Create(dWpillar_c *param_1);
}
