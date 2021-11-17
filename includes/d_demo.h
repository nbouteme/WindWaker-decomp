#pragma once
#include <ctypes.h>



namespace d_demo {
void * dDemo_getJaiPointer(char *param_1,short param_2,int param_3,int param_4);
undefined4 dDemo_setDemoData(fopAc_ac_c *pActor,ushort flags,mDoExt_McaMorf *pMorf,char *pArcName,undefined4 param_5,undefined4 param_6,ulong param_7,char param_8);
}

namespace d_demo {
camera_class * getView(void);
}
