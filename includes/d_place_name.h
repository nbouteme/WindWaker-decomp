#pragma once
#include <ctypes.h>



namespace d_place_name {
//[Data] Expected size is 0x00004c
extern undefined * name_texture;

//[Data] Expected size is 0x000014
extern undefined * l_dPlace_name_Method;

//[Data] Expected size is 0x000028
extern undefined g_profile_PLACE_NAME;

}
//[Data] Expected size is 0x000010
extern undefined1 dPlace_name_c;


namespace d_place_name {
void dPn_Draw(dPn_c *param_1);
void dPn_Execute(dPn_c *param_1);
undefined4 dPn_IsDelete(void);
void dPn_Delete(dPn_c *param_1);
void dPn_Create(dPn_c *param_1);
}
