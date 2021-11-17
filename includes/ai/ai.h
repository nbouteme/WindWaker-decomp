#pragma once
#include <ctypes.h>



namespace ai {
//Expected size is 0x000004
extern undefined4 __AIS_Callback;

//Expected size is 0x000004
extern undefined4 __AID_Callback;

//Expected size is 0x000004
extern undefined4 __CallbackStack;

//Expected size is 0x000004
extern undefined4 __OldStack;

//Expected size is 0x000004
extern undefined4 __AI_init_flag;

//Expected size is 0x000004
extern undefined4 __AID_Active;

//Expected size is 0x000008
extern undefined4 bound_32KHz;

//Expected size is 0x000008
extern undefined4 bound_48KHz;

//Expected size is 0x000008
extern undefined4 min_wait;

//Expected size is 0x000008
extern undefined4 max_wait;

//Expected size is 0x000008
extern undefined4 buffer;

undefined4 AIRegisterDMACallback(undefined4 param_1);
void AIInitDMA(undefined4 param_1,uint param_2);
void AIStartDMA(void);
void AIResetStreamSampleCount(void);
void AISetStreamPlayState(uint param_1);
uint AIGetStreamPlayState(void);
void AISetDSPSampleRate(int param_1);
uint AIGetDSPSampleRate(void);
void AISetStreamSampleRate(int param_1);
void __AI_set_stream_sample_rate(int param_1);
uint AIGetStreamSampleRate(void);
void AISetStreamVolLeft(uint param_1);
uint AIGetStreamVolLeft(void);
void AISetStreamVolRight(uint param_1);
uint AIGetStreamVolRight(void);
void AIInit(undefined4 param_1);
void __AISHandler(undefined4 param_1,undefined4 param_2);
void __AIDHandler(undefined4 param_1,undefined4 param_2);
void __AICallbackStackSwitch(code *param_1);
void __AI_SRC_INIT(void);
}
