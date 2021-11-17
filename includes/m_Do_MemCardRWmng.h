#pragma once
#include <ctypes.h>

#include <card_savebuffer.h>


namespace m_Do_MemCardRWmng {
//Expected size is 0x002000
extern struct card_savebuffer sTmpBuf;

//Expected size is 0x002000
extern struct card_savebuffer sTmpBuf2;

//Expected size is 0x000004
extern undefined4 sSaveCount;

card_errors mDoMemCdRWm_Store(CARDFileInfo *pInf,byte *data,int size);
card_errors mDoMemCdRWm_Restore(CARDFileInfo *file,byte *dest,int data_length);
void mDoMemCdRWm_BuildHeader(card_savebuffer *param_1);
void mDoMemCdRWm_SetCardStat(int param_1);
undefined4 mDoMemCdRWm_CheckCardStat(CARDFileInfo *file);
uint mDoMemCdRWm_CalcCheckSum(ushort *pBuf,uint size);
int mDoMemCdRWm_CalcCheckSumPictData(byte *param_1,int param_2);
uint mDoMemCdRWm_TestCheckSumPictData(int param_1);
void mDoMemCdRWm_SetCheckSumPictData(int param_1);
undefined8 mDoMemCdRWm_CalcCheckSumGameData(byte *pData,int size);
uint mDoMemCdRWm_TestCheckSumGameData(card_savedata *pData);
void mDoMemCdRWm_SetCheckSumGameData(int param_1,uint param_2);
}
