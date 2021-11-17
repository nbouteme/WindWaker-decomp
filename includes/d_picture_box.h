#pragma once
#include <ctypes.h>



namespace d_picture_box {
//Expected size is 0x000001
extern undefined1 init$4902;

void dPb_erasePicture(void);
}

namespace d_picture_box {
undefined4 dPb_Draw(int param_1);
undefined4 dPb_Execute(int param_1);
undefined4 dPb_IsDelete(void);
undefined4 dPb_Delete(int param_1);
undefined4 dPb_Create(int param_1);
}
