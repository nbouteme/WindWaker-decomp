#pragma once
#include <ctypes.h>



namespace f_pc_load {
undefined4 fpcLd_Use(ushort param_1);
void fpcLd_IsLoaded(short param_1);
void fpcLd_Free(ushort param_1,char *param_2);
undefined4 fpcLd_Load(ushort param_1);
}
