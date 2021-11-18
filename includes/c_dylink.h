#pragma once
#include <ctypes.h>



namespace c_dylink {
//[Data] Expected size is 0x00000c
extern pointer l_method$2679;

//[BSS] Expected size is 0x0007d8
extern struct DynamicModuleControl * DMC[501];
//[BSS] Expected size is 0x000001
extern undefined1 DMC_initialized;
//[BSS] Expected size is 0x000004
extern undefined4 cDyl_Initialized;
//[BSS] Expected size is 0x000004
extern undefined4 cDyl_DVD;
undefined4 cCc_Init(void);
bool cDyl_IsLinked(short param_1);
int cDyl_Unlink(ushort param_1,char *param_2);
undefined4 cDyl_LinkASync(ushort param_1);
undefined4 cDyl_InitCallback(void);
void cDyl_InitAsync(void);
undefined4 cDyl_InitAsyncIsDone(void);
}
