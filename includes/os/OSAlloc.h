#pragma once
#include <ctypes.h>



namespace os {
//[Data] Expected size is 0x000004
extern undefined4 __OSCurrHeap;

//[BSS] Expected size is 0x000004
extern undefined4 HeapArray;
//[BSS] Expected size is 0x000004
extern undefined4 NumHeaps;
//[BSS] Expected size is 0x000004
extern undefined4 ArenaStart;
//[BSS] Expected size is 0x000004
extern undefined4 ArenaEnd;
uint ** DLInsert(uint **param_1,uint **param_2);
int * OSAllocFromHeap(int param_1,int param_2);
void OSFreeToHeap(int param_1,int param_2);
undefined4 OSSetCurrentHeap(undefined4 param_1);
void OSInitAlloc(int param_1,uint param_2,int param_3);
int OSCreateHeap(int param_1,uint param_2);
void OSDestroyHeap(int param_1);
undefined * OSCheckHeap(int param_1);
int OSReferentSize(int param_1);
void OSDumpHeap(int param_1);
}
