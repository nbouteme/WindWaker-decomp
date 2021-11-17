#pragma once
#include <ctypes.h>



namespace card {
void __CARDCheckSum(ushort *param_1,uint param_2,short *param_3,short *param_4);
card_errors VerifyID(int param_1);
int VerifyDir(int param_1,uint *param_2);
int VerifyFAT(int param_1,uint *param_2);
card_errors __CARDVerify(int param_1);
card_errors CARDCheckExAsync(int param_1,undefined4 *param_2,code *param_3);
card_errors CARDCheck(int card_slot);
}
