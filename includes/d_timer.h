#pragma once
#include <ctypes.h>

#include <f_pc_profile__Profile_Base.h>


namespace d_timer {
//[Data] Expected size is 0x000068
extern undefined ShipRaceSeTable;

//[Data] Expected size is 0x000068
extern undefined VolcanoSeTable;

//[Data] Expected size is 0x000028
extern undefined * number$4344;

//[Data] Expected size is 0x000014
extern undefined * l_dTimer_Method;

//[Data] Expected size is 0x000028
extern struct f_pc_profile__Profile_Base g_profile_TIMER;

}
//[Data] Expected size is 0x000010
extern undefined1 dDlst_TimerScrnDraw_c;


namespace d_timer {
void dTm_parentPaneScale(fopMsgM_pane_class *param_1,fopMsgM_pane_class *param_2,double param_3);
}

namespace d_timer {
void dTimer_Draw(dTimer_c *param_1);
void dTimer_Execute(dTimer_c *param_1);
undefined4 dTimer_IsDelete(void);
void dTimer_Delete(dTimer_c *param_1);
void dTimer_Create(dTimer_c *param_1);
undefined4 dTimer_createTimer(undefined param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
undefined4 dTimer_createStockTimer(void);
}
