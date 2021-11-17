#pragma once
#include <ctypes.h>



namespace os {
void OSInitMessageQueue(OSMessageQueue *param_1,OSMessage *param_2,int param_3);
undefined4 OSSendMessage(int param_1,undefined4 param_2,uint param_3);
undefined4 OSReceiveMessage(int param_1,undefined4 *param_2,uint param_3);
}
