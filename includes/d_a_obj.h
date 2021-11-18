#pragma once
#include <ctypes.h>



namespace d_a_obj {
//[BSS] Expected size is 0x00000c
extern undefined4 total_spd$4082;
//[BSS] Expected size is 0x00000c
extern undefined4 path_spd$4114;
//[BSS] Expected size is 0x000001
extern undefined1 init$4084;
//[BSS] Expected size is 0x000001
extern undefined1 init$4116;
}

namespace daObj {
undefined4 * get_path_spd(cBgS_PolyInfo *param_1,float param_2);
}

namespace daObj {
void posMoveF_grade(fopAc_ac_c *param_1,cXyz *param_2,cXyz *param_3,float param_4,float param_5,cXyz *param_6,float param_7,float param_8,cXyz *param_9);
}

namespace daObj {
void HitSeStart(cXyz *param_1,int param_2,dCcD_GObjInf *param_3,ulong param_4);
void HitEff_sub_kikuzu(cXyz *param_1,cXyz *param_2,dKy_tevstr_c *param_3);
void HitEff_kikuzu(fopAc_ac_c *param_1,dCcD_Cyl *param_2);
}

namespace daObj {
void HitEff_hibana(fopAc_ac_c *param_1,dCcD_Cyl *param_2);
}
