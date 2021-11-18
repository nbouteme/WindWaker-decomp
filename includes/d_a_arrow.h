#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <f_pc_profile__Profile_Actor.h>


namespace d_a_arrow {
//[Data] Expected size is 0x000020
extern struct profile_method_class daArrowMethodTable;

//[Data] Expected size is 0x000030
extern struct f_pc_profile__Profile_Actor g_profile_ARROW;

}
//[Data] Expected size is 0x000088
extern undefined1 dCcD_Sph;

//[Data] Expected size is 0x00000c
extern pointer cM3dGSph;

//[Data] Expected size is 0x000088
extern undefined1 dCcD_Cps;

//[Data] Expected size is 0x000030
extern pointer dBgS_ArrowLinChk;


namespace d_a_arrow {
//[BSS] Expected size is 0x00000c
extern undefined4 offset_arrow_pos$5149;
}
//[BSS] Expected size is 0x000002
extern undefined1 daArrow_c;

namespace d_a_arrow {
//[BSS] Expected size is 0x000001
extern undefined1 init$5151;
void createHeap_CB(daArrow_c *param_1);
}

namespace d_a_arrow {
void atHit_CB(daArrow_c *param_1,dCcD_GObjInf *param_2,fopAc_ac_c *param_3,dCcD_GObjInf *param_4);
}

namespace d_a_arrow {
void daArrowCreate(daArrow_c *param_1);
void daArrowDelete(daArrow_c *param_1);
void daArrowExecute(daArrow_c *param_1);
void daArrowDraw(daArrow_c *param_1);
undefined4 daArrowIsDelete(void);
}

namespace d_a_arrow {
int cLib_calcTimer(short *param_1);
}
