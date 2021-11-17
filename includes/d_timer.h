#pragma once
#include <ctypes.h>



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
