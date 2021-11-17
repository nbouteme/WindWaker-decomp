#pragma once
#include <ctypes.h>



namespace amcstubs {
void EXI2_Init(void);
void EXI2_EnableInterrupts(void);
undefined4 EXI2_Poll(void);
undefined4 EXI2_ReadN(void);
undefined4 EXI2_WriteN(void);
void EXI2_Reserve(void);
void EXI2_Unreserve(void);
undefined4 AMC_IsStub(void);
}
