#pragma once
#include <ctypes.h>



namespace d_a_hookshot {
void daHookshot_Draw(daHookshot_c *param_1);
void daHookshot_rockLineCallback(int param_1,int param_2,int param_3);
}

namespace d_a_hookshot {
void daHookshot_Execute(daHookshot_c *param_1);
undefined4 daHookshot_IsDelete(void);
}

namespace d_a_hookshot {
undefined4 daHookshot_Delete(daHookshot_c *param_1);
}

namespace d_a_hookshot {
void daHookshot_Create(daHookshot_c *param_1);
void __sinit_d_a_hookshot_cpp(void);
}
