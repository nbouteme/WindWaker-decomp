#pragma once
#include <ctypes.h>



namespace JKernel {
//Expected size is 0x000004
extern undefined4 DBfoundSize;

//Expected size is 0x000004
extern undefined4 DBfoundOffset;

//Expected size is 0x000004
extern undefined4 DBfoundBlock;

//Expected size is 0x000004
extern undefined4 DBnewFreeBlock;

//Expected size is 0x000004
extern undefined4 DBnewUsedBlock;

}

namespace JKRExpHeap {
JKRExpHeap * create(ulong param_1,JKRHeap *param_2,bool param_3);
}

namespace JKRExpHeap {
}
