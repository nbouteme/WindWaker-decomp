#include <d_save_init.h>
#include <d_save.h>


namespace d_save_init {

/* __stdcall setInitEventBit(void) */

void setInitEventBit(void)

{
  dSv_event_c::setEventReg
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xbeff,
             daNpc_Kg1_c::m_highscore);
  dSv_event_c::setEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x7eff,0xe);
  return;
}

