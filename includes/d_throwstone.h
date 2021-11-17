#pragma once
#include <ctypes.h>



namespace d_throwstone {
void CheckCreateHeap(daThrowstone_c *param_1);
}

namespace d_throwstone {
PhaseState daThrowstoneCreate(fopAc_ac_c *param_1);
undefined4 daThrowstoneDelete(int param_1);
undefined4 daThrowstoneExecute(fopAc_ac_c *param_1);
undefined4 daThrowstoneDraw(int param_1);
undefined4 daThrowstoneIsDelete(void);
}
