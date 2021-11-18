#pragma once
#include <ctypes.h>



namespace d_auction_screen {
//[Data] Expected size is 0x000028
extern pointer number$4067;

//[Data] Expected size is 0x000014
extern undefined * l_dAuction_screen_Method;

//[Data] Expected size is 0x000028
extern undefined g_profile_AUCTION_SCREEN;

}
//[Data] Expected size is 0x000010
extern undefined1 dAuction_screen_c;

//[Data] Expected size is 0x00000c
extern undefined1 dAs_HIO_c;


namespace d_auction_screen {
//[BSS] Expected size is 0x000008
extern undefined g_asHIO;
//[BSS] Expected size is 0x000001
extern undefined1 talkmode;
//[BSS] Expected size is 0x000001
extern undefined1 talkFlag;
//[BSS] Expected size is 0x000001
extern undefined1 slotShow;
//[BSS] Expected size is 0x000001
extern undefined1 gaugeShow;
//[BSS] Expected size is 0x000001
extern undefined1 gaugeTrans;
//[BSS] Expected size is 0x000002
extern undefined2 gaugeTransTimer;
}

namespace d_auction_screen {
void dAs_Draw(dAs_c *param_1);
void dAs_Execute(dAs_c *param_1);
undefined4 dAs_IsDelete(void);
void dAs_Delete(dAs_c *param_1);
void dAs_Create(dAs_c *param_1);
undefined4 dAuction_screen_create(void);
bool dAuction_screen_delete(void);
undefined4 dAuction_screen_talkStart(void);
undefined4 dAuction_screen_talkEnd(void);
undefined4 dAuction_screen_slotShow(void);
undefined4 dAuction_screen_slotHide(void);
undefined4 dAuction_screen_gaugeShow(void);
undefined4 dAuction_screen_gaugeHide(void);
undefined4 dAuction_screen_gaugeUp(void);
undefined4 dAuction_screen_gaugeDown(void);
void dAs_timerCalc(void);
}

namespace d_auction_screen {
void __sinit_d_auction_screen_cpp(void);
}
