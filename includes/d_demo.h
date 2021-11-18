#pragma once
#include <ctypes.h>



namespace JStudio {
//[Data] Expected size is 0x000010
extern undefined1 TCreateObject;

}
//[Data] Expected size is 0x00004c
extern undefined1 dDemo_system_c;

//[Data] Expected size is 0x000058
extern undefined1 dDemo_fog_c;

//[Data] Expected size is 0x000068
extern undefined1 dDemo_light_c;

//[Data] Expected size is 0x000040
extern undefined1 dDemo_ambient_c;

//[Data] Expected size is 0x000090
extern undefined1 dDemo_camera_c;

//[Data] Expected size is 0x000088
extern undefined1 dDemo_actor_c;


namespace d_demo {
void * dDemo_getJaiPointer(char *param_1,short param_2,int param_3,int param_4);
undefined4 dDemo_setDemoData(fopAc_ac_c *pActor,ushort flags,mDoExt_McaMorf *pMorf,char *pArcName,undefined4 param_5,undefined4 param_6,ulong param_7,char param_8);
}

namespace d_demo {
camera_class * getView(void);
}
