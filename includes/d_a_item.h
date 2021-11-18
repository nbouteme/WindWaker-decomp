#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <f_pc_profile__Profile_Actor.h>
#include <Demangler/dCcD_SrcCyl.h>
#include <daItemBase_c__vtbl.h>


namespace d_a_item {
//[Data] Expected size is 0x000024
extern pointer mode_proc$4609[9];

}
//[Data] Expected size is 0x000044
extern struct dCcD_SrcCyl daItem_c;


namespace d_a_item {
//[Data] Expected size is 0x000020
extern struct profile_method_class l_daItem_Method;

//[Data] Expected size is 0x000030
extern struct f_pc_profile__Profile_Actor g_profile_ITEM;

}
//[Data] Expected size is 0x000024
extern struct daItemBase_c__vtbl daItem_c;

//[Data] Expected size is 0x000004
extern int daItem_c;


namespace d_a_item {
//[BSS] Expected size is 0x000001
extern undefined1 init$4613;
}

namespace d_a_item {
cXyz * setArrowTrans(cXyz *__return_storage_ptr__,short param_1,cXyz *param_2);
}

namespace d_a_item {
void itemGetCallBack(daItem_c *param_1,dCcD_GObjInf *param_2,daPy_lk_c *param_3,dCcD_GObjInf *param_4);
}

namespace d_a_item {
uint Reflect(cXyz *param_1,cXyz *param_2,float param_3,float param_4);
}

namespace d_a_item {
void daItem_Draw(daItem_c *param_1);
void daItem_Execute(daItem_c *param_1);
void daItem_IsDelete(daItem_c *param_1);
void daItem_Delete(daItem_c *param_1);
void daItem_Create(daItem_c *this);
}
