#pragma once
#include <ctypes.h>



namespace d_letter {
uint dLetter_isNoSend(ushort param_1);
void dLetter_send(ushort param_1);
uint dLetter_isSend(ushort param_1);
void dLetter_stock(ushort param_1);
uint dLetter_isStock(ushort param_1);
void dLetter_read(ushort param_1);
uint dLetter_isRead(ushort param_1);
void dLetter_delivery(undefined4 param_1);
void dLetter_autoStock(undefined4 param_1);
uint dLetter_isDelivery(void);
}
