#pragma once
#include <ctypes.h>



namespace ar {
//[Data] Expected size is 0x000004
extern undefined4 __ARQVersion;

//[BSS] Expected size is 0x000004
extern undefined4 __ARQRequestQueueHi;
//[BSS] Expected size is 0x000004
extern undefined4 __ARQRequestTailHi;
//[BSS] Expected size is 0x000004
extern undefined4 __ARQRequestQueueLo;
//[BSS] Expected size is 0x000004
extern undefined4 __ARQRequestTailLo;
//[BSS] Expected size is 0x000004
extern undefined4 __ARQRequestPendingHi;
//[BSS] Expected size is 0x000004
extern undefined4 __ARQRequestPendingLo;
//[BSS] Expected size is 0x000004
extern undefined4 __ARQCallbackHi;
//[BSS] Expected size is 0x000004
extern undefined4 __ARQCallbackLo;
//[BSS] Expected size is 0x000004
extern undefined4 __ARQChunkSize;
//[BSS] Expected size is 0x000004
extern undefined4 __ARQ_init_flag;
void __ARQServiceQueueLo(void);
void __ARQCallbackHack(void);
void __ARQInterruptServiceRoutine(void);
void ARQInit(void);
void ARQPostRequest(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8);
}
