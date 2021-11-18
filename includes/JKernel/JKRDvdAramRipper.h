#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x000001
extern undefined1 JKRDvdAramRipper;

//[Data] Expected size is 0x000004
extern int JKRDvdAramRipper;

//[BSS] Expected size is 0x00000c
extern undefined1 JKRDvdAramRipper;

namespace JKernel {
//[BSS] Expected size is 0x000018
extern undefined decompMutex;
//[BSS] Expected size is 0x000004
extern undefined4 szpBuf;
//[BSS] Expected size is 0x000004
extern undefined4 szpEnd;
//[BSS] Expected size is 0x000004
extern undefined4 refBuf;
//[BSS] Expected size is 0x000004
extern undefined4 refEnd;
//[BSS] Expected size is 0x000004
extern undefined4 refCurrent;
//[BSS] Expected size is 0x000004
extern undefined4 dmaBuf;
//[BSS] Expected size is 0x000004
extern undefined4 dmaEnd;
//[BSS] Expected size is 0x000004
extern undefined4 dmaCurrent;
//[BSS] Expected size is 0x000004
extern undefined4 srcOffset;
//[BSS] Expected size is 0x000004
extern undefined4 transLeft;
//[BSS] Expected size is 0x000004
extern undefined4 srcLimit;
//[BSS] Expected size is 0x000004
extern undefined4 srcFile;
//[BSS] Expected size is 0x000004
extern undefined4 fileOffset;
//[BSS] Expected size is 0x000004
extern undefined4 readCount;
//[BSS] Expected size is 0x000004
extern undefined4 maxDest;
//[BSS] Expected size is 0x000001
extern undefined1 isInitMutex;
}

namespace JKernel {
undefined4 JKRDecompressFromDVDToAram(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,int param_6);
undefined4 decompSZS_subroutine(char *param_1,uint param_2);
int firstSrcData(void);
byte * nextSrcData(byte *param_1);
uint dmaBufferFlush(ulong param_1);
void __sinit_JKRDvdAramRipper_cpp(void);
}
