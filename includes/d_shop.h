#pragma once
#include <ctypes.h>



namespace d_shop {
int dShop_get_next_select(int param_1,short *param_2);
}

namespace d_shop {
int dShop_now_triggercheck(msg_class *param_1,STControl *param_2,short *param_3,undefined4 *param_4,code *param_5,undefined4 param_6);
undefined4 dShop_maxCheck(int param_1);
uint dShop_BoughtErrorStatus(short *param_1,int param_2,int param_3);
}

namespace d_shop {
ShopCursor_c *ShopCursor_create(J3DModelData *param_1,J3DAnmTevRegKey *brkData,float param_3);
}
