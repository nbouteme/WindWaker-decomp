#pragma once
#include <ctypes.h>



namespace d_a_bg {
//Expected size is 0x000020
extern undefined arcName$4148;

}

namespace d_a_bg {
undefined4 createMatAnm(int param_1,ushort param_2);
}

namespace d_a_bg {
void checkCreateHeap(daBg_c *param_1);
}

namespace d_a_bg {
undefined4 daBg_Draw(daBg_c *param_1);
undefined4 daBg_Execute(daBg_c *param_1);
uint daBg_IsDelete(int param_1);
undefined4 daBg_Delete(daBg_c *param_1);
void daBg_Create(daBg_c *param_1);
}
