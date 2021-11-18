#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x000001
extern undefined1 JKRDvdRipper;

//[Data] Expected size is 0x000004
extern int JKRDvdRipper;

//[BSS] Expected size is 0x00000c
extern undefined1 JKRDvdRipper;

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

namespace JKRDvdRipper {
undefined4 loadToMainRAM(char *param_1,uchar *param_2,JKRExpandSwitch param_3,ulong param_4,JKRHeap *param_5,EAllocDirection param_6,ulong param_7,int *param_8);
JKRArchive__Header *loadToMainRAM(long param_1,uchar *param_2,JKRExpandSwitch param_3,ulong param_4,JKRHeap *param_5,EAllocDirection param_6,ulong param_7,int *param_8);
uchar * loadToMainRAM(JKRDvdFile *param_1,uchar *param_2,JKRExpandSwitch param_3,ulong param_4,JKRHeap *param_5,EAllocDirection param_6,ulong param_7,int *outCompType);
}

namespace JKernel {
undefined4 JKRDecompressFromDVD(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,int param_6);
undefined4 decompSZS_subroutine(char *param_1,byte *param_2);
int firstSrcData(void);
byte * nextSrcData(byte *param_1);
}

namespace JKernel {
void __sinit_JKRDvdRipper_cpp(void);
}
