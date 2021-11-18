#pragma once
#include <ctypes.h>



namespace m_Do_controller_pad {
//[BSS] Expected size is 0x000010
extern struct JUTGamePad * g_mDoCPd_gamePad[4];
//[BSS] Expected size is 0x0000f0
extern struct interface_of_controller_pad g_mDoCPd_cpadInfo[4];
undefined4 mDoCPd_Convert(interface_of_controller_pad *pDst,JUTGamePad *pJUT);
undefined4 mDoCPd_Read(JUTGamePad *param_1);
undefined4 mDoCPd_Create(void);
}
