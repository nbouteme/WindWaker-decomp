#pragma once
#include <ctypes.h>



namespace TRK_MINNOW_DOLPHIN {
//[Data] Expected size is 0x00001c
extern undefined4 gDBCommTable;

//[BSS] Expected size is 0x000004
extern undefined4 gWritePos;
//[BSS] Expected size is 0x000004
extern undefined4 gReadPos;
//[BSS] Expected size is 0x000004
extern undefined4 gReadCount;
//[BSS] Expected size is 0x000004
extern undefined _MetroTRK_Has_Framing;
//[BSS] Expected size is 0x00110a
extern undefined1 gReadBuf;
//[BSS] Expected size is 0x00110a
extern undefined gWriteBuf;
void TRKLoadContext(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8);
void TRKUARTInterruptHandler(void);
void TRK_board_display(void);
void UnreserveEXI2Port(void);
void ReserveEXI2Port(void);
int TRKReadUARTPoll(undefined *param_1);
undefined4 WriteUART1(undefined param_1);
int WriteUARTFlush(void);
void EnableEXI2Interrupts(void);
undefined4 TRKInitializeIntDrivenUART(void);
void InitMetroTRKCommTable(int param_1);
void TRKEXICallBack(undefined4 param_1,undefined4 param_2);
}
