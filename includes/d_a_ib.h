#pragma once
#include <ctypes.h>



namespace d_a_ib {
//Expected size is 0x000001
extern undefined1 init$4234;

}

namespace d_a_ib {
undefined4 itemParamSet_CB(int param_1);
}

namespace d_a_ib {
void CheckCreateHeap(daIball_c *param_1);
}

namespace d_a_ib {
void daIball_Create(daIball_c *param_1);
void daIball_Draw(daIball_c *param_1);
void daIball_Delete(daIball_c *param_1);
undefined4 daIball_IsDelete(void);
void daIball_Execute(daIball_c *param_1);
}
