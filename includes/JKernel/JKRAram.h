#pragma once
#include <ctypes.h>


//Expected size is 0x00000c
extern undefined1 JKRAram;


namespace JKernel {
//Expected size is 0x000018
extern undefined decompMutex;

}
//Expected size is 0x000004
extern struct JKRAram * JKRAram;


namespace JKernel {
//Expected size is 0x000004
extern struct JKRHeap * szpBuf;

//Expected size is 0x000004
extern undefined4 szpEnd;

//Expected size is 0x000004
extern undefined4 refBuf;

//Expected size is 0x000004
extern undefined4 refEnd;

//Expected size is 0x000004
extern undefined4 refCurrent;

//Expected size is 0x000004
extern undefined4 srcOffset;

//Expected size is 0x000004
extern undefined4 transLeft;

//Expected size is 0x000004
extern undefined4 srcLimit;

//Expected size is 0x000004
extern undefined4 srcAddress;

//Expected size is 0x000004
extern undefined4 fileOffset;

//Expected size is 0x000004
extern undefined4 readCount;

//Expected size is 0x000004
extern undefined4 maxDest;

//Expected size is 0x000001
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
