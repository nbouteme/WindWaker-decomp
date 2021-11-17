#pragma once
#include <ctypes.h>


//Expected size is 0x00000c
extern undefined1 JKRDvdAramRipper;


namespace JKernel {
//Expected size is 0x000018
extern undefined decompMutex;

//Expected size is 0x000004
extern undefined4 szpBuf;

//Expected size is 0x000004
extern undefined4 szpEnd;

//Expected size is 0x000004
extern undefined4 refBuf;

//Expected size is 0x000004
extern undefined4 refEnd;

//Expected size is 0x000004
extern undefined4 refCurrent;

//Expected size is 0x000004
extern undefined4 dmaBuf;

//Expected size is 0x000004
extern undefined4 dmaEnd;

//Expected size is 0x000004
extern undefined4 dmaCurrent;

//Expected size is 0x000004
extern undefined4 srcOffset;

//Expected size is 0x000004
extern undefined4 transLeft;

//Expected size is 0x000004
extern undefined4 srcLimit;

//Expected size is 0x000004
extern undefined4 srcFile;

//Expected size is 0x000004
extern undefined4 fileOffset;

//Expected size is 0x000004
extern undefined4 readCount;

//Expected size is 0x000004
extern undefined4 maxDest;

//Expected size is 0x000001
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
