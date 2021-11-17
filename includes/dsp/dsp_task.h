#pragma once
#include <ctypes.h>



namespace dsp {
//Expected size is 0x000004
extern undefined4 __DSP_tmp_task;

//Expected size is 0x000004
extern undefined4 __DSP_last_task;

//Expected size is 0x000004
extern undefined4 __DSP_first_task;

//Expected size is 0x000004
extern undefined4 __DSP_curr_task;

void __DSP_exec_task(int param_1,int *param_2);
void __DSP_boot_task(int param_1);
void __DSP_insert_task(int param_1);
void __DSP_remove_task(undefined4 *param_1);
}
