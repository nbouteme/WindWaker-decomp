#pragma once
#include <ctypes.h>



namespace card {
//[Data] Expected size is 0x000002
extern undefined2 __CARDVendorID;

card_errors CARDGetSerialNo(int card_slot,uint *param_2);
}
