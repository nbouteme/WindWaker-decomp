#pragma once
#include <ctypes.h>



namespace d_ovlp_fade4 {
undefined4 dDlst_setResTimgObj(_GXTexFmt *param_1,GXTexObj *param_2,void *param_3,uint param_4,uint param_5);
void cnvAddress(double param_1,double param_2,float *param_3,float *param_4);
}

namespace d_ovlp_fade4 {
undefined4 dOvlpFd4_Draw(void *param_1,void *param_2);
undefined4 dOvlpFd4_Execute(void *param_1,void *param_2);
undefined4 dOvlpFd4_IsDelete(void);
undefined4 dOvlpFd4_Delete(void);
undefined4 dOvlpFd4_Create(dOvlpFd4_c *param_1);
}
