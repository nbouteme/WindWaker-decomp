#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <f_pc_profile__Profile_Actor.h>


namespace d_a_nh {
//[Data] Expected size is 0x000044
extern undefined l_cyl_src;

//[Data] Expected size is 0x000020
extern struct profile_method_class l_daNh_Method;

//[Data] Expected size is 0x000030
extern struct f_pc_profile__Profile_Actor g_profile_NH;

}
//[Data] Expected size is 0x00000c
extern undefined daNh_HIO_c;


namespace d_a_nh {
//[BSS] Expected size is 0x000048
extern undefined l_HIO;
//[BSS] Expected size is 0x000004
extern undefined4 a_heap_size_tbl$4111;
//[BSS] Expected size is 0x000001
extern undefined1 init$4112;
}

namespace d_a_nh {
void checkCreateHeap(daNh_c *param_1);
}

namespace d_a_nh {
void daNh_Draw(daNh_c *param_1);
void daNh_Execute(daNh_c *param_1);
undefined4 daNh_IsDelete(void);
undefined4 daNh_Delete(daNh_c *param_1);
void daNh_Create(daNh_c *param_1);
}

namespace d_a_nh {
int cLib_calcTimer(int *param_1);
int cLib_getRndValue(uint param_1,uint param_2);
void __sinit_d_a_nh_cpp(void);
}
