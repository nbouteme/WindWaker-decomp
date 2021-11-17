#pragma once
#include <ctypes.h>



namespace ar {
//Expected size is 0x000004
extern undefined4 __ARQRequestQueueHi;

//Expected size is 0x000004
extern undefined4 __ARQRequestTailHi;

//Expected size is 0x000004
extern undefined4 __ARQRequestQueueLo;

//Expected size is 0x000004
extern undefined4 __ARQRequestTailLo;

//Expected size is 0x000004
extern undefined4 __ARQRequestPendingHi;

//Expected size is 0x000004
extern undefined4 __ARQRequestPendingLo;

//Expected size is 0x000004
extern undefined4 __ARQCallbackHi;

//Expected size is 0x000004
extern undefined4 __ARQCallbackLo;

//Expected size is 0x000004
extern undefined4 __ARQChunkSize;

//Expected size is 0x000004
extern undefined4 __ARQ_init_flag;

void __ARQServiceQueueLo(void);
void __ARQCallbackHack(void);
void __ARQInterruptServiceRoutine(void);
void ARQInit(void);
void ARQPostRequest(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8);
}
