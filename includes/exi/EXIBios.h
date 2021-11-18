#pragma once
#include <ctypes.h>



namespace exi {
//[Data] Expected size is 0x000004
extern undefined4 __EXIVersion;

//[BSS] Expected size is 0x0000c0
extern undefined Ecb;
void SetExiInterruptMask(int param_1,int *param_2);
undefined4 EXIImm(int param_1,byte *param_2,int param_3,int param_4,undefined4 param_5);
undefined4 EXIImmEx(int card_slot,int param_2,int param_3,undefined4 param_4);
undefined4 EXIDma(int param_1,uint param_2,undefined4 param_3,int param_4,undefined4 param_5);
undefined4 EXISync(int param_1);
uint EXIClearInterrupts(int param_1,int param_2,int param_3,int param_4);
undefined4 EXISetExiCallback(int param_1,undefined4 param_2);
undefined4 __EXIProbe(int param_1);
int EXIProbe(int param_1);
undefined4 EXIProbeEx(int card_slot);
undefined4 EXIAttach(int param_1,undefined4 param_2);
undefined4 EXIDetach(int param_1);
undefined4 EXISelect(int param_1,int param_2,int param_3);
undefined4 EXIDeselect(int param_1);
void EXIIntrruptHandler(short param_1,undefined4 param_2);
void TCIntrruptHandler(short param_1,undefined4 param_2);
void EXTIntrruptHandler(short param_1,undefined4 param_2);
void EXIInit(void);
undefined4 EXILock(int param_1,int param_2,int param_3);
undefined4 EXIUnlock(int param_1);
undefined4 EXIGetState(int param_1);
void UnlockedHandler(undefined4 param_1);
undefined4 EXIGetID(int param_1,int param_2,undefined4 *param_3);
}
