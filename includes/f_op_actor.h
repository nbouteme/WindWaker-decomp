#pragma once
#include <ctypes.h>



namespace f_op_actor {
//Expected size is 0x000004
extern undefined4 g_fopAc_type;

}
//Expected size is 0x000004
extern int fopAc_ac_c;


namespace f_op_actor {
bool fopAc_IsActor(fopAc_ac_c *this);
void fopAc_Draw(fopAc_ac_c *this);
int fopAc_Execute(fopAc_ac_c *this);
int fopAc_IsDelete(fopAc_ac_c *this);
int fopAc_Delete(fopAc_ac_c *this);
int fopAc_Create(fopAc_ac_c *this);
}
