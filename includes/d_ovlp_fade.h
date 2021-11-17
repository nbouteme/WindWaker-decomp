#pragma once
#include <ctypes.h>



namespace d_ovlp_fade {
//Expected size is 0x000004
extern undefined4 dOvlpFd_execute_f;

undefined4 dOvlpFd_Draw(void);
undefined4 dOvlpFd_FadeOut(int param_1);
undefined4 dOvlpFd_Wait(void);
undefined4 dOvlpFd_FadeIn(int param_1);
undefined4 dOvlpFd_Execute(void);
undefined4 dOvlpFd_IsDelete(void);
undefined4 dOvlpFd_Delete(void);
undefined4 dOvlpFd_Create(void);
}
