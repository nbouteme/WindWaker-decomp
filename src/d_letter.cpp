#include <d_letter.h>
#include <d_save.h>
#include <d_letter.h>


namespace d_letter {

/* __stdcall dLetter_isNoSend(unsigned short) */

uint dLetter_isNoSend(ushort param_1)

{
  uint uVar1;
  ushort uVar2;
  
  uVar2 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,param_1)
  ;
  uVar1 = countLeadingZeros(uVar2 & 0xff);
  return uVar1 >> 5;
}


/* __stdcall dLetter_send(unsigned short) */

void dLetter_send(ushort param_1)

{
  dSv_event_c::setEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,param_1,1);
  return;
}


/* __stdcall dLetter_isSend(unsigned short) */

uint dLetter_isSend(ushort param_1)

{
  uint uVar1;
  ushort uVar2;
  
  uVar2 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,param_1)
  ;
  uVar1 = countLeadingZeros(1 - (uVar2 & 0xff));
  return uVar1 >> 5;
}


/* __stdcall dLetter_stock(unsigned short) */

void dLetter_stock(ushort param_1)

{
  dSv_event_c::setEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,param_1,2);
  return;
}


/* __stdcall dLetter_isStock(unsigned short) */

uint dLetter_isStock(ushort param_1)

{
  uint uVar1;
  ushort uVar2;
  
  uVar2 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,param_1)
  ;
  uVar1 = countLeadingZeros(2 - (uVar2 & 0xff));
  return uVar1 >> 5;
}


/* __stdcall dLetter_read(unsigned short) */

void dLetter_read(ushort param_1)

{
  dSv_event_c::setEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,param_1,3);
  return;
}


/* __stdcall dLetter_isRead(unsigned short) */

uint dLetter_isRead(ushort param_1)

{
  uint uVar1;
  ushort uVar2;
  
  uVar2 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,param_1)
  ;
  uVar1 = countLeadingZeros(3 - (uVar2 & 0xff));
  return uVar1 >> 5;
}


/* __stdcall dLetter_delivery(unsigned short) */

void dLetter_delivery(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = dLetter_isSend();
  if (cVar1 != '\0') {
    dLetter_stock(param_1);
  }
  return;
}


/* __stdcall dLetter_autoStock(unsigned short) */

void dLetter_autoStock(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = dLetter_isNoSend();
  if (cVar1 != '\0') {
    dLetter_stock(param_1);
  }
  return;
}


/* __stdcall dLetter_isDelivery(unsigned short) */

uint dLetter_isDelivery(void)

{
  uint uVar1;
  
  uVar1 = dLetter_isNoSend();
  uVar1 = countLeadingZeros(uVar1 & 0xff);
  return uVar1 >> 5;
}

