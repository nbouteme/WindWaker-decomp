#pragma once
#include <ctypes.h>


//Expected size is 0x000054
extern undefined1 dWaterMark_c;

//Expected size is 0x000002
extern undefined1 dWaterMark_c;

//Expected size is 0x000002
extern undefined1 dWaterMark_c;


namespace d_water_mark {
undefined4 dWaterMark_Draw(int param_1);
}

namespace d_water_mark {
undefined4 dWaterMark_Execute(dWaterMark_c *param_1);
undefined4 dWaterMark_IsDelete(void);
undefined4 dWaterMark_Delete(int param_1);
void dWaterMark_Create(dWaterMark_c *param_1);
}
