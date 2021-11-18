#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x000060
extern pointer JKRHeap;

//[Data] Expected size is 0x000001
extern undefined1 JKRHeap;

//[BSS] Expected size is 0x000004
extern struct JKRHeap * JKRHeap;
//[BSS] Expected size is 0x000004
extern struct JKRHeap * JKRHeap;
//[BSS] Expected size is 0x000004
extern struct JKRHeap * JKRHeap;
//[BSS] Expected size is 0x000004
extern pointer JKRHeap;
//[BSS] Expected size is 0x000004
extern void * JKRHeap;
//[BSS] Expected size is 0x000004
extern void * JKRHeap;
//[BSS] Expected size is 0x000004
extern int JKRHeap;
//[BSS] Expected size is 0x000004
extern void * JKRHeap;
//[BSS] Expected size is 0x000004
extern int JKRHeap;

namespace JKRHeap {
bool initArena(char **param_1,ulong *param_2,int param_3);
}

namespace JKRHeap {
void * alloc(ulong size,int param_2,JKRHeap *pHeap);
}

namespace JKRHeap {
void free(void *__ptr,JKRHeap *param_2);
}

namespace JKRHeap {
JKRHeap * findFromRoot(void *param_1);
}

namespace JKernel {
void JKRDefaultMemoryErrorRoutine(undefined4 param_1,undefined4 param_2,undefined4 param_3);
}

namespace JKRHeap {
undefined * setErrorHandler(FuncDef584 *param_1);
}

namespace JKernel {
void * operator_new(ulong size);
void * operator_new(ulong size,int param_2);
void * operator_new(ulong size,JKRHeap *heap,int align);
void operator_new[](ulong param_1);
void operator_new[](ulong param_1,int param_2);
void operator_new[](ulong param_1,JKRHeap *param_2,int param_3);
void operator_delete(JKRHeap *param_1);
void operator_delete[](void *param_1);
}
