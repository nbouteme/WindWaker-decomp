#pragma once
#include <ctypes.h>



namespace d_event_manager {
//[Data] Expected size is 0x000034
extern undefined * soecial_table$4019;

//[Data] Expected size is 0x00000c
extern pointer action_table$4789;

//[Data] Expected size is 0x00000a
extern undefined dance_table$4855;

//[Data] Expected size is 0x000005
extern undefined daNpc_Tt_tact_table;

}

namespace d_event_manager {
int findObjectCallBack(fopAc_ac_c *pAct,dEv_seach_prm *pSearch);
undefined4 extraOnObjectCallBack(fopAc_ac_c *param_1,dEv_seach_prm *param_2);
undefined4 extraOffObjectCallBack(fopAc_ac_c *param_1,char *param_2);
undefined4 allOffObjectCallBack(int param_1);
}

namespace d_event_manager {
undefined4 dEvmng_strcmp(char *param_1,char *param_2);
}

namespace d_event_manager {
fopAc_ac_c * findShutterCallBack(fopAc_ac_c *pAct,dEvt__FindShutterData *pData);
}

namespace d_event_manager {
undefined4 dEv_extra_createCB(int param_1);
int dEv_talkman_get_action(int param_1);
}

namespace d_event_manager {
uint dEvmng_daNpc_Tt_Conv(byte param_1);
undefined2 dEvmng_daNpc_Tt_GetEvFlag(int param_1);
}
