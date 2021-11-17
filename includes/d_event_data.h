#pragma once
#include <ctypes.h>



namespace d_event_data {
//Expected size is 0x000004
extern undefined4 l_msgId$4247;

//Expected size is 0x000004
extern undefined4 l_msg$4248;

//Expected size is 0x000004
extern undefined4 l_msgNo$4249;

undefined4 dEvDt_Next_Stage(int staffIdx,byte wipeType);
}
