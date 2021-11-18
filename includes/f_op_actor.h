#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <dEvt_info_c__vtbl.h>


namespace f_op_actor {
//[Data] Expected size is 0x000020
extern struct profile_method_class g_fopAc_Method;

}
//[Data] Expected size is 0x00000c
extern struct dEvt_info_c__vtbl dEvt_info_c;


namespace f_op_actor {
//[BSS] Expected size is 0x000004
extern undefined4 g_fopAc_type;
}
//[BSS] Expected size is 0x000004
extern int fopAc_ac_c;

namespace f_op_actor {
bool fopAc_IsActor(fopAc_ac_c *this);
void fopAc_Draw(fopAc_ac_c *this);
int fopAc_Execute(fopAc_ac_c *this);
int fopAc_IsDelete(fopAc_ac_c *this);
int fopAc_Delete(fopAc_ac_c *this);
int fopAc_Create(fopAc_ac_c *this);
}
