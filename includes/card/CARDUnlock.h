#pragma once
#include <ctypes.h>



namespace card {
//[Data] Expected size is 0x000160
extern undefined CardData;

//[Data] Expected size is 0x000004
extern undefined4 next;

uint bitrev(uint param_1);
card_errors ReadArrayUnlock(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5);
uint DummyLen(void);
undefined4 __CARDUnlock(int param_1,uint *param_2);
void InitCallback(int param_1);
void DoneCallback(int param_1);
}
