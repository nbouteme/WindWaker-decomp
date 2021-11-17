#include <JPALoader/JPAFieldBlock.h>
#include <JKernel/JKRHeap.h>
#include <JPAFieldBlockArc.h>
#include <JPAFieldBlock.h>


/* __thiscall JPAFieldBlockArc::JPAFieldBlockArc(unsigned char const *) */

void __thiscall JPAFieldBlockArc::JPAFieldBlockArc(JPAFieldBlockArc *this,uchar *param_1)

{
  *(undefined1 **)this = &JPAFieldBlock::__vt;
  *(undefined ***)this = &__vt;
  *(uchar **)(this + 4) = param_1 + 0xc;
  return;
}


/* __thiscall JPAFieldBlock::~JPAFieldBlock(void) */

void __thiscall JPAFieldBlock::_JPAFieldBlock(JPAFieldBlock *this)

{
  short in_r4;
  
  if ((this != (JPAFieldBlock *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall JPAFieldBlockArc::~JPAFieldBlockArc(void) */

void __thiscall JPAFieldBlockArc::_JPAFieldBlockArc(JPAFieldBlockArc *this)

{
  short in_r4;
  
  if (this != (JPAFieldBlockArc *)0x0) {
    *(undefined ***)this = &__vt;
    if (this != (JPAFieldBlockArc *)0x0) {
      *(undefined1 **)this = &JPAFieldBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPAFieldBlockArc::getType(void) */

uint __thiscall JPAFieldBlockArc::getType(JPAFieldBlockArc *this)

{
  return **(uint **)(this + 4) & 0xf;
}


/* __thiscall JPAFieldBlockArc::getVelType(void) */

uint __thiscall JPAFieldBlockArc::getVelType(JPAFieldBlockArc *this)

{
  return **(uint **)(this + 4) >> 8 & 3;
}


/* __thiscall JPAFieldBlockArc::getSttFlag(void) */

uint __thiscall JPAFieldBlockArc::getSttFlag(JPAFieldBlockArc *this)

{
  return **(uint **)(this + 4) >> 0x10;
}


/* __thiscall JPAFieldBlockArc::getCycle(void) */

undefined __thiscall JPAFieldBlockArc::getCycle(JPAFieldBlockArc *this)

{
  return *(undefined *)(*(int *)(this + 4) + 0x44);
}


/* __thiscall JPAFieldBlockArc::getID(void) */

undefined4 __thiscall JPAFieldBlockArc::getID(JPAFieldBlockArc *this)

{
  return 0;
}


/* __thiscall JPAFieldBlockArc::getPos(JGeometry::TVec3<float><float>&) */

void __thiscall JPAFieldBlockArc::getPos(JPAFieldBlockArc *this,TVec3_float_ *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = *(int *)(this + 4);
  fVar1 = *(float *)(iVar3 + 0x18);
  fVar2 = *(float *)(iVar3 + 0x14);
  param_1->x = *(float *)(iVar3 + 0x10);
  param_1->y = fVar2;
  param_1->z = fVar1;
  return;
}


/* __thiscall JPAFieldBlockArc::getDir(JGeometry::TVec3<float><float>&) */

void __thiscall JPAFieldBlockArc::getDir(JPAFieldBlockArc *this,TVec3_float_ *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = *(int *)(this + 4);
  fVar1 = *(float *)(iVar3 + 0x24);
  fVar2 = *(float *)(iVar3 + 0x20);
  param_1->x = *(float *)(iVar3 + 0x1c);
  param_1->y = fVar2;
  param_1->z = fVar1;
  return;
}


/* __thiscall JPAFieldBlockArc::getMag(void) */

double __thiscall JPAFieldBlockArc::getMag(JPAFieldBlockArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 4);
}


/* __thiscall JPAFieldBlockArc::getMagRndm(void) */

double __thiscall JPAFieldBlockArc::getMagRndm(JPAFieldBlockArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 8);
}


/* __thiscall JPAFieldBlockArc::getMaxDist(void) */

double __thiscall JPAFieldBlockArc::getMaxDist(JPAFieldBlockArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0xc);
}


/* __thiscall JPAFieldBlockArc::getVal1(void) */

double __thiscall JPAFieldBlockArc::getVal1(JPAFieldBlockArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x28);
}


/* __thiscall JPAFieldBlockArc::getVal2(void) */

double __thiscall JPAFieldBlockArc::getVal2(JPAFieldBlockArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x2c);
}


/* __thiscall JPAFieldBlockArc::getVal3(void) */

double __thiscall JPAFieldBlockArc::getVal3(JPAFieldBlockArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x30);
}


/* __thiscall JPAFieldBlockArc::getFadeIn(void) */

double __thiscall JPAFieldBlockArc::getFadeIn(JPAFieldBlockArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x34);
}


/* __thiscall JPAFieldBlockArc::getFadeOut(void) */

double __thiscall JPAFieldBlockArc::getFadeOut(JPAFieldBlockArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x38);
}


/* __thiscall JPAFieldBlockArc::getEnTime(void) */

double __thiscall JPAFieldBlockArc::getEnTime(JPAFieldBlockArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x3c);
}


/* __thiscall JPAFieldBlockArc::getDisTime(void) */

double __thiscall JPAFieldBlockArc::getDisTime(JPAFieldBlockArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x40);
}

