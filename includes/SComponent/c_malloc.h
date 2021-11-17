#pragma once
#include <ctypes.h>


//Expected size is 0x000004
extern undefined1 cMl;


namespace cMl {
int init(JKRHeap *ctx);
void * memalignB(int param_1,ulong param_2);
void free(void *__ptr);
}
