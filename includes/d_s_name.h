#pragma once
#include <ctypes.h>



namespace d_s_name {
//Expected size is 0x00001c
extern undefined g_snHIO;

}

namespace d_s_name {
undefined4 phase_1(char *param_1);
uint phase_2(char *param_1);
undefined4 phase_3(void);
undefined4 resLoad(request_of_phase_process_class *param_1,void *param_2);
}

namespace d_s_name {
void dScnName_Draw(dScnName_c *param_1);
void dScnName_Execute(dScnName_c *param_1);
undefined4 dScnName_IsDelete(void);
undefined4 dScnName_Delete(dScnName_c *param_1);
void dScnName_Create(dScnName_c *param_1);
}

namespace d_s_name {
void __sinit_d_s_name_cpp(void);
}
