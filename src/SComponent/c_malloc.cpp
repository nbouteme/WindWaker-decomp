#include <SComponent/c_malloc.h>
#include <JKernel/JKRHeap.h>

undefined1 cMl;

namespace cMl {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall init(JKRHeap *) */

int init(JKRHeap *ctx)

{
  _Heap = ctx;
  return (int)ctx;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall memalignB(int,
                             unsigned long) */

void * memalignB(int param_1,ulong param_2)

{
  void *pvVar1;
  
  if (param_2 == 0) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = JKRHeap::alloc(_Heap,param_2,param_1);
  }
  return pvVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall free(void *) */

void free(void *__ptr)

{
  if (__ptr != (void *)0x0) {
    JKRHeap::free(_Heap,__ptr);
  }
  return;
}

