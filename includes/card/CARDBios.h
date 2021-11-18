#pragma once
#include <ctypes.h>



namespace card {
//[Data] Expected size is 0x000010
extern pointer ResetFunctionInfo;

//[Data] Expected size is 0x000004
extern undefined4 __CARDVersion;

//[BSS] Expected size is 0x000220
extern struct CardBlockData __CARDBlock[2];
//[BSS] Expected size is 0x000020
extern undefined __CARDDiskNone;
//[BSS] Expected size is 0x000002
extern undefined2 __CARDEncode;
void __CARDDefaultApiCallback(void);
void __CARDSyncCallback(int param_1);
void __CARDExtHandler(int card_slot);
void __CARDExiHandler(int param_1);
void __CARDTxHandler(int param_1);
void __CARDUnlockedHandler(int param_1);
card_errors __CARDEnableInterrupt(undefined4 param_1,int param_2);
card_errors __CARDReadStatus(undefined4 param_1,undefined4 param_2);
card_errors __CARDClearStatus(undefined4 param_1);
void TimeoutHandler(int param_1);
undefined4 Retry(int param_1);
void UnlockedCallback(int param_1,int param_2);
card_errors __CARDStart(int card_slot,void *read_callback,void *ext_handler);
card_errors __CARDReadSegment(int card_slot,void *read_callback);
card_errors __CARDWritePage(int card_slot,undefined4 param_2);
card_errors __CARDEraseSector(int card_slot,uint len,void *ext_handler);
card_errors CARDInit(void);
undefined2 __CARDGetFontEncode(void);
void __CARDSetDiskID(char *param_1);
card_errors __CARDGetControlBlock(int card_slot,CardBlockData **param_2);
card_errors __CARDPutControlBlock(CardBlockData *param_1,card_errors param_2);
card_errors CARDFreeBlocks(int card_slot,CARDFileInfo *param_2,int *out__card_block_count);
card_errors __CARDSync(int card_slot);
card_errors OnReset(int param_1);
}
