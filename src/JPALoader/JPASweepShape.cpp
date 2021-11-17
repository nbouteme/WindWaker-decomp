#include <JPALoader/JPASweepShape.h>
#include <JKernel/JKRHeap.h>
#include <JPASweepShapeArc.h>
#include <JPASweepShape.h>


/* __thiscall JPASweepShapeArc::JPASweepShapeArc(unsigned char const *) */

void __thiscall JPASweepShapeArc::JPASweepShapeArc(JPASweepShapeArc *this,uchar *param_1)

{
  *(undefined1 **)this = &JPASweepShape::__vt;
  *(undefined ***)this = &__vt;
  *(uchar **)(this + 4) = param_1 + 0xc;
  return;
}


/* __thiscall JPASweepShape::~JPASweepShape(void) */

void __thiscall JPASweepShape::_JPASweepShape(JPASweepShape *this)

{
  short in_r4;
  
  if ((this != (JPASweepShape *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall JPASweepShapeArc::~JPASweepShapeArc(void) */

void __thiscall JPASweepShapeArc::_JPASweepShapeArc(JPASweepShapeArc *this)

{
  short in_r4;
  
  if (this != (JPASweepShapeArc *)0x0) {
    *(undefined ***)this = &__vt;
    if (this != (JPASweepShapeArc *)0x0) {
      *(undefined1 **)this = &JPASweepShape::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPASweepShapeArc::getType(void) */

uint __thiscall JPASweepShapeArc::getType(JPASweepShapeArc *this)

{
  return **(uint **)(this + 4) & 0xf;
}


/* __thiscall JPASweepShapeArc::getDirType(void) */

uint __thiscall JPASweepShapeArc::getDirType(JPASweepShapeArc *this)

{
  return **(uint **)(this + 4) >> 4 & 7;
}


/* __thiscall JPASweepShapeArc::getRotType(void) */

uint __thiscall JPASweepShapeArc::getRotType(JPASweepShapeArc *this)

{
  return **(uint **)(this + 4) >> 7 & 7;
}


/* __thiscall JPASweepShapeArc::getBasePlaneType(void) */

uint __thiscall JPASweepShapeArc::getBasePlaneType(JPASweepShapeArc *this)

{
  return **(uint **)(this + 4) >> 10 & 1;
}


/* __thiscall JPASweepShapeArc::getLife(void) */

int __thiscall JPASweepShapeArc::getLife(JPASweepShapeArc *this)

{
  return (int)*(short *)(*(int *)(this + 4) + 0x1c);
}


/* __thiscall JPASweepShapeArc::getRate(void) */

int __thiscall JPASweepShapeArc::getRate(JPASweepShapeArc *this)

{
  return (int)*(short *)(*(int *)(this + 4) + 0x1e);
}


/* __thiscall JPASweepShapeArc::getTiming(void) */

double __thiscall JPASweepShapeArc::getTiming(JPASweepShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x18);
}


/* __thiscall JPASweepShapeArc::getStep(void) */

undefined __thiscall JPASweepShapeArc::getStep(JPASweepShapeArc *this)

{
  return *(undefined *)(*(int *)(this + 4) + 0x20);
}


/* __thiscall JPASweepShapeArc::getPosRndm(void) */

double __thiscall JPASweepShapeArc::getPosRndm(JPASweepShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 4);
}


/* __thiscall JPASweepShapeArc::getVelInfRate(void) */

double __thiscall JPASweepShapeArc::getVelInfRate(JPASweepShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x10);
}


/* __thiscall JPASweepShapeArc::getBaseVel(void) */

double __thiscall JPASweepShapeArc::getBaseVel(JPASweepShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 8);
}


/* __thiscall JPASweepShapeArc::getBaseVelRndm(void) */

double __thiscall JPASweepShapeArc::getBaseVelRndm(JPASweepShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0xc);
}


/* __thiscall JPASweepShapeArc::getGravity(void) */

double __thiscall JPASweepShapeArc::getGravity(JPASweepShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x14);
}


/* __thiscall JPASweepShapeArc::isEnableField(void) */

uint __thiscall JPASweepShapeArc::isEnableField(JPASweepShapeArc *this)

{
  return **(uint **)(this + 4) & 0x200000;
}


/* __thiscall JPASweepShapeArc::isEnableDrawParent(void) */

uint __thiscall JPASweepShapeArc::isEnableDrawParent(JPASweepShapeArc *this)

{
  return **(uint **)(this + 4) & 0x80000;
}


/* __thiscall JPASweepShapeArc::isClipOn(void) */

uint __thiscall JPASweepShapeArc::isClipOn(JPASweepShapeArc *this)

{
  return **(uint **)(this + 4) & 0x100000;
}


/* __thiscall JPASweepShapeArc::isEnableScaleOut(void) */

uint __thiscall JPASweepShapeArc::isEnableScaleOut(JPASweepShapeArc *this)

{
  return **(uint **)(this + 4) & 0x400000;
}


/* __thiscall JPASweepShapeArc::isEnableAlphaOut(void) */

uint __thiscall JPASweepShapeArc::isEnableAlphaOut(JPASweepShapeArc *this)

{
  return **(uint **)(this + 4) & 0x800000;
}


/* __thiscall JPASweepShapeArc::isEnableRotate(void) */

uint __thiscall JPASweepShapeArc::isEnableRotate(JPASweepShapeArc *this)

{
  return **(uint **)(this + 4) & 0x1000000;
}


/* __thiscall JPASweepShapeArc::isInheritedScale(void) */

uint __thiscall JPASweepShapeArc::isInheritedScale(JPASweepShapeArc *this)

{
  return **(uint **)(this + 4) & 0x10000;
}


/* __thiscall JPASweepShapeArc::isInheritedAlpha(void) */

uint __thiscall JPASweepShapeArc::isInheritedAlpha(JPASweepShapeArc *this)

{
  return **(uint **)(this + 4) & 0x20000;
}


/* __thiscall JPASweepShapeArc::isInheritedRGB(void) */

uint __thiscall JPASweepShapeArc::isInheritedRGB(JPASweepShapeArc *this)

{
  return **(uint **)(this + 4) & 0x40000;
}


/* __thiscall JPASweepShapeArc::getTextureIndex(void) */

undefined __thiscall JPASweepShapeArc::getTextureIndex(JPASweepShapeArc *this)

{
  return *(undefined *)(*(int *)(this + 4) + 0x44);
}


/* __thiscall JPASweepShapeArc::getScaleX(void) */

double __thiscall JPASweepShapeArc::getScaleX(JPASweepShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x24);
}


/* __thiscall JPASweepShapeArc::getScaleY(void) */

double __thiscall JPASweepShapeArc::getScaleY(JPASweepShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x28);
}


/* __thiscall JPASweepShapeArc::getPrm(void) */

undefined4 __thiscall JPASweepShapeArc::getPrm(JPASweepShapeArc *this)

{
  return *(undefined4 *)(*(int *)(this + 4) + 0x3c);
}


/* __thiscall JPASweepShapeArc::getEnv(void) */

undefined4 __thiscall JPASweepShapeArc::getEnv(JPASweepShapeArc *this)

{
  return *(undefined4 *)(*(int *)(this + 4) + 0x40);
}


/* __thiscall JPASweepShapeArc::getPrmAlpha(void) */

undefined __thiscall JPASweepShapeArc::getPrmAlpha(JPASweepShapeArc *this)

{
  return *(undefined *)(*(int *)(this + 4) + 0x3f);
}


/* __thiscall JPASweepShapeArc::getEnvAlpha(void) */

undefined __thiscall JPASweepShapeArc::getEnvAlpha(JPASweepShapeArc *this)

{
  return *(undefined *)(*(int *)(this + 4) + 0x43);
}


/* __thiscall JPASweepShapeArc::getRotateSpeed(void) */

double __thiscall JPASweepShapeArc::getRotateSpeed(JPASweepShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x2c);
}


/* __thiscall JPASweepShapeArc::getInheritScale(void) */

double __thiscall JPASweepShapeArc::getInheritScale(JPASweepShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x30);
}


/* __thiscall JPASweepShapeArc::getInheritAlpha(void) */

double __thiscall JPASweepShapeArc::getInheritAlpha(JPASweepShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x34);
}


/* __thiscall JPASweepShapeArc::getInheritRGB(void) */

double __thiscall JPASweepShapeArc::getInheritRGB(JPASweepShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x38);
}

