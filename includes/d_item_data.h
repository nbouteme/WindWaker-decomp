#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x0001c0
extern pointer dItem_data;

//[Data] Expected size is 0x0001d0
extern pointer dItem_data;

//[Data] Expected size is 0x002400
extern struct dItem_data_item_resource dItem_data[256];

//[Data] Expected size is 0x001c00
extern struct dItem_data_field_item_res dItem_data[256];

//[Data] Expected size is 0x000400
extern struct dItem_data_item_info dItem_data[256];

//[Data] Expected size is 0x000204
extern short dItem_data[260];


namespace dItem_data {
uint getAppearEffect(uchar param_1);
uint checkSpecialEffect(dItem_data__ItemNo param_1);
}

namespace d_item_data {
void __sinit_d_item_data_cpp(void);
}
