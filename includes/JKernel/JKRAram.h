#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x000010
extern undefined1 JKRAram;

//[Data] Expected size is 0x000020
extern undefined1 JKRAram;

//[Data] Expected size is 0x000010
extern undefined1 JKRAram;

//[Data] Expected size is 0x000004
extern uint JKRAram;

//[BSS] Expected size is 0x00000c
extern undefined1 JKRAram;

namespace JKernel {
//[BSS] Expected size is 0x000018
extern undefined decompMutex;
}
//[BSS] Expected size is 0x000004
extern struct JKRAram * JKRAram;

namespace JKernel {
//[BSS] Expected size is 0x000004
extern struct JKRHeap * szpBuf;
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
extern undefined4 srcAddress;
//[BSS] Expected size is 0x000004
extern undefined4 fileOffset;
//[BSS] Expected size is 0x000004
extern undefined4 readCount;
//[BSS] Expected size is 0x000004
extern undefined4 maxDest;
//[BSS] Expected size is 0x000001
extern undefined1 isInitMutex;
}

namespace JKRAram {
JKRAram * create(ulong param_1,ulong param_2,long param_3,long param_4,long param_5);
}

namespace JKRAram {
undefined4 aramToMainRam(JKRAramBlock *param_1,uchar *param_2,ulong param_3,ulong param_4,JKRExpandSwitch param_5,ulong param_6,JKRHeap *param_7,int param_8,ulong *param_9);
}

namespace JKernel {
undefined4 JKRDecompressFromAramToMainRam(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5);
undefined4 decompSZS_subroutine(char *param_1,byte *param_2);
JKRHeap * firstSrcData(void);
JKRHeap * nextSrcData(byte *param_1);
void __sinit_JKRAram_cpp(void);
}
