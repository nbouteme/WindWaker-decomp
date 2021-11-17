#include <JPALoader/JPAExTexShape.h>
#include <JKernel/JKRHeap.h>
#include <JPAExTexShapeArc.h>
#include <JPAExTexShape.h>


/* __thiscall JPAExTexShapeArc::JPAExTexShapeArc(unsigned char const *) */

void __thiscall JPAExTexShapeArc::JPAExTexShapeArc(JPAExTexShapeArc *this,uchar *param_1)

{
  *(undefined1 **)this = &JPAExTexShape::__vt;
  *(undefined1 **)this = &__vt;
  *(uchar **)(this + 4) = param_1 + 0xc;
  return;
}


/* __thiscall JPAExTexShape::~JPAExTexShape(void) */

void __thiscall JPAExTexShape::_JPAExTexShape(JPAExTexShape *this)

{
  short in_r4;
  
  if ((this != (JPAExTexShape *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall JPAExTexShapeArc::~JPAExTexShapeArc(void) */

void __thiscall JPAExTexShapeArc::_JPAExTexShapeArc(JPAExTexShapeArc *this)

{
  short in_r4;
  
  if (this != (JPAExTexShapeArc *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPAExTexShapeArc *)0x0) {
      *(undefined1 **)this = &JPAExTexShape::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPAExTexShapeArc::getIndTexMode(void) */

uint __thiscall JPAExTexShapeArc::getIndTexMode(JPAExTexShapeArc *this)

{
  return **(uint **)(this + 4) & 3;
}


/* __thiscall JPAExTexShapeArc::getIndTexMtxID(void) */

undefined4 __thiscall JPAExTexShapeArc::getIndTexMtxID(JPAExTexShapeArc *this)

{
  return *(undefined4 *)(&indMtxID + (**(uint **)(this + 4) & 0xc));
}


/* __thiscall JPAExTexShapeArc::getIndTexMtx(void) */

int __thiscall JPAExTexShapeArc::getIndTexMtx(JPAExTexShapeArc *this)

{
  return *(int *)(this + 4) + 4;
}


/* __thiscall JPAExTexShapeArc::getExpScale(void) */

int __thiscall JPAExTexShapeArc::getExpScale(JPAExTexShapeArc *this)

{
  return (int)*(char *)(*(int *)(this + 4) + 0x1c);
}


/* __thiscall JPAExTexShapeArc::getIndTextureID(void) */

undefined __thiscall JPAExTexShapeArc::getIndTextureID(JPAExTexShapeArc *this)

{
  return *(undefined *)(*(int *)(this + 4) + 0x20);
}


/* __thiscall JPAExTexShapeArc::getSubTextureID(void) */

undefined __thiscall JPAExTexShapeArc::getSubTextureID(JPAExTexShapeArc *this)

{
  return *(undefined *)(*(int *)(this + 4) + 0x21);
}


/* __thiscall JPAExTexShapeArc::isEnableSecondTex(void) */

uint __thiscall JPAExTexShapeArc::isEnableSecondTex(JPAExTexShapeArc *this)

{
  return **(uint **)(this + 4) & 0x100;
}


/* __thiscall JPAExTexShapeArc::getSecondTexIndex(void) */

undefined __thiscall JPAExTexShapeArc::getSecondTexIndex(JPAExTexShapeArc *this)

{
  return *(undefined *)(*(int *)(this + 4) + 0x22);
}

