#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <f_pc_profile__Profile_Actor.h>


namespace d_throwstone {
//[Data] Expected size is 0x000020
extern struct profile_method_class daThrowstoneMethodTable;

//[Data] Expected size is 0x000030
extern struct f_pc_profile__Profile_Actor g_profile_THROWSTONE;

void CheckCreateHeap(daThrowstone_c *param_1);
}

namespace d_throwstone {
PhaseState daThrowstoneCreate(fopAc_ac_c *param_1);
undefined4 daThrowstoneDelete(int param_1);
undefined4 daThrowstoneExecute(fopAc_ac_c *param_1);
undefined4 daThrowstoneDraw(int param_1);
undefined4 daThrowstoneIsDelete(void);
}
