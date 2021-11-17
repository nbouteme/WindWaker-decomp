#include <JPALoader/JPAKeyBlock.h>
#include <JKernel/JKRHeap.h>
#include <JPAKeyBlock.h>
#include <JPAKeyBlockArc.h>


/* __thiscall JPAKeyBlockArc::JPAKeyBlockArc(unsigned char const *) */

void __thiscall JPAKeyBlockArc::JPAKeyBlockArc(JPAKeyBlockArc *this,uchar *param_1)

{
  *(undefined1 **)this = &JPAKeyBlock::__vt;
  *(undefined1 **)this = &__vt;
  *(uchar **)(this + 4) = param_1 + 0xc;
  *(uchar **)(this + 8) = param_1 + 0x20;
  return;
}


/* __thiscall JPAKeyBlock::~JPAKeyBlock(void) */

void __thiscall JPAKeyBlock::_JPAKeyBlock(JPAKeyBlock *this)

{
  short in_r4;
  
  if ((this != (JPAKeyBlock *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall JPAKeyBlockArc::~JPAKeyBlockArc(void) */

void __thiscall JPAKeyBlockArc::_JPAKeyBlockArc(JPAKeyBlockArc *this)

{
  short in_r4;
  
  if (this != (JPAKeyBlockArc *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPAKeyBlockArc *)0x0) {
      *(undefined1 **)this = &JPAKeyBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPAKeyBlockArc::getID(void) */

undefined __thiscall JPAKeyBlockArc::getID(JPAKeyBlockArc *this)

{
  return **(undefined **)(this + 4);
}


/* __thiscall JPAKeyBlockArc::isLoopEnable(void) */

bool __thiscall JPAKeyBlockArc::isLoopEnable(JPAKeyBlockArc *this)

{
  return *(char *)(*(int *)(this + 4) + 6) != '\0';
}


/* __thiscall JPAKeyBlockArc::getNumber(void) */

undefined __thiscall JPAKeyBlockArc::getNumber(JPAKeyBlockArc *this)

{
  return *(undefined *)(*(int *)(this + 4) + 4);
}


/* __thiscall JPAKeyBlockArc::getKeyDataPtr(void) */

undefined4 __thiscall JPAKeyBlockArc::getKeyDataPtr(JPAKeyBlockArc *this)

{
  return *(undefined4 *)(this + 8);
}

