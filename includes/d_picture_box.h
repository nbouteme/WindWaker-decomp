#pragma once
#include <ctypes.h>



namespace d_picture_box {
//[Data] Expected size is 0x00001c
extern undefined photo_data;

//[Data] Expected size is 0x000024
extern undefined * number$4535;

//[Data] Expected size is 0x000014
extern undefined * l_dPb_Method;

//[Data] Expected size is 0x000028
extern undefined g_profile_PB;

}
//[Data] Expected size is 0x000010
extern undefined1 dJle_Pb_c;


namespace d_picture_box {
//[Data] Expected size is 0x000004
extern undefined4 mCaptureMonoColor1$4901;

//[BSS] Expected size is 0x000001
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
