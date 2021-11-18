#pragma once
#include <ctypes.h>



namespace OdemuExi2 {
//[Data] Expected size is 0x000001
extern undefined1 SendCount;

//[BSS] Expected size is 0x000004
extern undefined4 MTRCallback;
//[BSS] Expected size is 0x000004
extern undefined4 DBGCallback;
//[BSS] Expected size is 0x000004
extern undefined4 SendMailData;
//[BSS] Expected size is 0x000004
extern undefined4 RecvDataLeng;
//[BSS] Expected size is 0x000004
extern undefined4 pEXIInputFlag;
//[BSS] Expected size is 0x000001
extern undefined1 EXIInputFlag;
void DBClose(void);
void DBOpen(void);
undefined4 DBWrite(undefined4 param_1,uint param_2);
undefined4 DBRead(undefined4 param_1,int param_2);
uint DBQueryData(void);
void DBInitInterrupts(void);
void DBInitComm(undefined4 *param_1,undefined4 param_2);
void DBGHandler(short param_1);
void MWCallback(void);
uint DBGReadStatus(undefined4 param_1);
uint DBGWrite(uint param_1,undefined4 *param_2,int param_3);
uint DBGRead(uint param_1,undefined4 *param_2,int param_3);
uint DBGReadMailbox(undefined4 param_1);
void DBGEXIImm(undefined4 param_1,int param_2,int param_3);
}
