#include <JUtility/JUTGraphFifo.h>
#include <JKernel/JKRHeap.h>
#include <gx/GXFifo.h>
#include <gx/GXInit.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUTGraphFifo.h>

undefined1 JUTGraphFifo;
undefined1 JUTGraphFifo;
undefined1 JUTGraphFifo;

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGraphFifo::JUTGraphFifo(unsigned long) */

void __thiscall JUTGraphFifo::JUTGraphFifo(JUTGraphFifo *this,ulong param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  *(undefined1 **)this = &__vt;
  *(ulong *)(this + 0xc) = param_1 + 0x1f & 0xffffffe0;
  if (sInitiated == '\0') {
    pvVar1 = JKRHeap::alloc(JKRHeap::sSystemHeap,*(int *)(this + 0xc) + 0xa0,0x20);
    *(void **)(this + 8) = pvVar1;
    *(uint *)(this + 8) = *(int *)(this + 8) + 0x1fU & 0xffffffe0;
    uVar2 = gx::GXInit(*(undefined4 *)(this + 8),*(undefined4 *)(this + 0xc));
    *(undefined4 *)(this + 4) = uVar2;
    sInitiated = '\x01';
    _sCurrentFifo = this;
  }
  else {
    pvVar1 = JKRHeap::alloc(JKRHeap::sSystemHeap,*(int *)(this + 0xc) + 0x80,0x20);
    *(void **)(this + 4) = pvVar1;
    *(int *)(this + 8) = *(int *)(this + 4) + 0x80;
    gx::GXInitFifoBase(*(undefined4 *)(this + 4),*(undefined4 *)(this + 8),
                       *(undefined4 *)(this + 0xc));
    gx::GXInitFifoPtrs(*(undefined4 *)(this + 4),*(undefined4 *)(this + 8),*(undefined4 *)(this + 8)
                      );
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGraphFifo::~JUTGraphFifo(void) */

void __thiscall JUTGraphFifo::_JUTGraphFifo(JUTGraphFifo *this)

{
  short in_r4;
  
  if (this != (JUTGraphFifo *)0x0) {
    *(undefined1 **)this = &__vt;
    gx::GXSaveCPUFifo(*(undefined4 *)(_sCurrentFifo + 4));
    do {
      gx::GXGetGPStatus(&mGpStatus,0x803f7859,0x803f785a,0x803f785b,0x803f785c);
    } while (cRam803f785a == '\0');
    if (_sCurrentFifo == this) {
      _sCurrentFifo = (JUTGraphFifo *)0x0;
    }
    JKRHeap::free(JKRHeap::sSystemHeap,*(void **)(this + 8));
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

