#pragma once
#include <ctypes.h>



namespace d_a_item {
//Expected size is 0x000001
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
