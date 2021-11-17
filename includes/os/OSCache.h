#pragma once
#include <ctypes.h>



namespace os {
uint DCEnable(void);
uint DCInvalidateRange(uint param_1,int param_2);
uint DCFlushRange(uint param_1,int param_2);
uint DCStoreRange(uint param_1,int param_2);
uint DCFlushRangeNoSync(uint param_1,int param_2);
uint DCStoreRangeNoSync(uint param_1,int param_2);
uint DCZeroRange(uint param_1,int param_2);
uint ICInvalidateRange(uint param_1,int param_2);
uint ICFlashInvalidate(void);
uint ICEnable(void);
ulonglong __LCEnable(void);
void LCEnable(void);
ulonglong LCDisable(void);
uint LCStoreBlocks(uint param_1);
uint LCStoreData(int param_1,int param_2,int param_3);
void LCQueueWait(int param_1);
void L2GlobalInvalidate(void);
void DMAErrorHandler(undefined4 param_1,int param_2);
void __OSCacheInit(void);
}
