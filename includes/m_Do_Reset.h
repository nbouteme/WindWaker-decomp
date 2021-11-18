#pragma once
#include <ctypes.h>


//[BSS] Expected size is 0x000004
extern undefined4 mDoRst;

namespace m_Do_Reset {
void my_OSCancelAlarmAll(void);
void destroyVideo(JUTVideo *param_1);
void mDoRst_reset(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void mDoRst_resetCallBack(JUTGamePad *param_1);
}
