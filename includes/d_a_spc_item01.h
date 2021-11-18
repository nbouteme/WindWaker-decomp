#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <f_pc_profile__Profile_Actor.h>
#include <daItemBase_c__vtbl.h>


namespace d_a_spc_item01 {
//[Data] Expected size is 0x000044
extern undefined l_cyl_src;

//[Data] Expected size is 0x000020
extern struct profile_method_class l_daSpcItem01_Method;

//[Data] Expected size is 0x000030
extern struct f_pc_profile__Profile_Actor g_profile_SPC_ITEM01;

}
//[Data] Expected size is 0x000024
extern struct daItemBase_c__vtbl daSpcItem01_c;


namespace d_a_spc_item01 {
void daSpcItem01_Draw(daSpcItem01_c *param_1);
void daSpcItem01_Execute(daSpcItem01_c *param_1);
undefined4 daSpcItem01_IsDelete(void);
void daSpcItem01_Delete(daSpcItem01_c *param_1);
void daSpcItem01_Create(daSpcItem01_c *param_1);
}
