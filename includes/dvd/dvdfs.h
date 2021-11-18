#pragma once
#include <ctypes.h>



namespace dvd {
//[BSS] Expected size is 0x000004
extern undefined4 BootInfo;
//[BSS] Expected size is 0x000004
extern undefined4 FstStart;
//[BSS] Expected size is 0x000004
extern undefined4 FstStringStart;
//[BSS] Expected size is 0x000004
extern undefined4 MaxEntryNum;
//[BSS] Expected size is 0x000004
extern undefined4 currentDirectory;
//[BSS] Expected size is 0x000004
extern undefined4 __DVDLongFileNameFlag;
//[BSS] Expected size is 0x000008
extern undefined __DVDThreadQueue;
void __DVDFSInit(void);
int DVDConvertPathToEntrynum(char *filePath);
undefined4 DVDFastOpen(uint param_1,int param_2);
bool DVDOpen(char *param_1,int param_2);
undefined4 DVDClose(void);
int entryToPath(int param_1,int param_2,int param_3);
undefined4 DVDConvertEntrynumToPath(int param_1,int param_2,int param_3);
undefined4 DVDGetCurrentDir(int param_1,int param_2);
undefined4 DVDChangeDir(char *param_1);
undefined4 DVDReadAsyncPrio(int param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5,undefined4 param_6);
void cbForReadAsync(undefined4 param_1,int param_2);
undefined4 DVDReadPrio(int param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5);
void cbForReadSync(void);
bool DVDOpenDir(char *param_1,int *param_2);
undefined4 DVDReadDir(uint *param_1,uint *param_2);
undefined4 DVDCloseDir(void);
void DVDPrepareStreamAsync(int param_1,uint param_2,uint param_3,undefined4 param_4);
void cbForPrepareStreamAsync(undefined4 param_1,int param_2);
}
