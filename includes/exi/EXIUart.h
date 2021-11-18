#pragma once
#include <ctypes.h>



namespace exi {
//[BSS] Expected size is 0x000004
extern undefined4 Chan;
//[BSS] Expected size is 0x000004
extern undefined4 Dev;
//[BSS] Expected size is 0x000004
extern undefined4 Enabled;
//[BSS] Expected size is 0x000004
extern undefined4 BarnacleEnabled;
undefined4 InitializeUART(void);
undefined4 WriteUARTN(char *param_1,uint param_2);
}
