#pragma once
#include <ctypes.h>



namespace exi {
//Expected size is 0x000004
extern undefined4 Chan;

//Expected size is 0x000004
extern undefined4 Dev;

//Expected size is 0x000004
extern undefined4 Enabled;

//Expected size is 0x000004
extern undefined4 BarnacleEnabled;

undefined4 InitializeUART(void);
undefined4 WriteUARTN(char *param_1,uint param_2);
}
