#pragma once
#include <ctypes.h>



namespace JKRExpHeap {
//[Data] Expected size is 0x000060
extern pointer __vt;

}

namespace JKernel {
//[BSS] Expected size is 0x000004
extern undefined4 DBfoundSize;
//[BSS] Expected size is 0x000004
extern undefined4 DBfoundOffset;
//[BSS] Expected size is 0x000004
extern undefined4 DBfoundBlock;
//[BSS] Expected size is 0x000004
extern undefined4 DBnewFreeBlock;
//[BSS] Expected size is 0x000004
extern undefined4 DBnewUsedBlock;
}

namespace JKRExpHeap {
JKRExpHeap * create(ulong param_1,JKRHeap *param_2,bool param_3);
}

namespace JKRExpHeap {
}
