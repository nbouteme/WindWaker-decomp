#pragma once
#include <ctypes.h>



namespace d_cc_uty {
undefined4 cc_pl_cut_bit_get(void);
undefined4 at_se_get(cCcD_Obj *param_1);
undefined4 at_se_getC(cCcD_Obj *param_1);
void def_se_set(fopAc_ac_c *param_1,cCcD_Obj *param_2,ulong param_3);
void def_se_set_p(int param_1,cXyz *param_2,undefined4 param_3,ulong param_4);
void at_power_check(CcAtInfo *pDst);
fopAc_ac_c * cc_at_check(fopAc_ac_c *pActor,CcAtInfo *pDst);
}

namespace daObj {
uint PrmAbstract(fopAc_ac_c *param_1,Prm_e param_2,Prm_e param_3);
}
