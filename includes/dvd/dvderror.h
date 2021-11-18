#pragma once
#include <ctypes.h>



namespace dvd {
//[Data] Expected size is 0x000048
extern undefined4 ErrorTable;

char ErrorCode2Num(uint param_1);
void __DVDStoreErrorCode(undefined *param_1);
}
