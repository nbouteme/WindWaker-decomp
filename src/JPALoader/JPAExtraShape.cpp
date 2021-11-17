#include <JPALoader/JPAExtraShape.h>
#include <JKernel/JKRHeap.h>
#include <JPAExtraShapeArc.h>
#include <JPAExtraShape.h>


/* __thiscall JPAExtraShapeArc::JPAExtraShapeArc(unsigned char const *) */

void __thiscall JPAExtraShapeArc::JPAExtraShapeArc(JPAExtraShapeArc *this,uchar *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  *(undefined1 **)this = &JPAExtraShape::__vt;
  *(undefined ***)this = &__vt;
  *(uchar **)(this + 4) = param_1 + 0xc;
  iVar3 = *(int *)(this + 4);
  fVar1 = JPALoader::_2179;
  if (JPALoader::_2180 != *(float *)(iVar3 + 8)) {
    fVar1 = (*(float *)(iVar3 + 0x14) - *(float *)(iVar3 + 0x10)) / *(float *)(iVar3 + 8);
  }
  *(float *)(this + 8) = fVar1;
  iVar3 = *(int *)(this + 4);
  fVar1 = JPALoader::_2179;
  if (JPALoader::_2179 != *(float *)(iVar3 + 0xc)) {
    fVar1 = (*(float *)(iVar3 + 0x18) - *(float *)(iVar3 + 0x14)) /
            (JPALoader::_2179 - *(float *)(iVar3 + 0xc));
  }
  *(float *)(this + 0xc) = fVar1;
  fVar2 = JPALoader::_2179;
  fVar1 = *(float *)(*(int *)(this + 4) + 0x2c);
  if (JPALoader::_2180 == fVar1) {
    *(float *)(this + 0x18) = JPALoader::_2179;
    *(float *)(this + 0x10) = fVar2;
  }
  else {
    *(float *)(this + 0x10) = (JPALoader::_2179 - *(float *)(*(int *)(this + 4) + 0x34)) / fVar1;
    *(float *)(this + 0x18) =
         (fVar2 - *(float *)(*(int *)(this + 4) + 0x3c)) / *(float *)(*(int *)(this + 4) + 0x2c);
  }
  fVar2 = JPALoader::_2179;
  fVar1 = *(float *)(*(int *)(this + 4) + 0x30);
  if (JPALoader::_2179 == fVar1) {
    *(float *)(this + 0x1c) = JPALoader::_2179;
    *(float *)(this + 0x14) = fVar2;
    return;
  }
  *(float *)(this + 0x14) =
       (*(float *)(*(int *)(this + 4) + 0x38) - JPALoader::_2179) / (JPALoader::_2179 - fVar1);
  *(float *)(this + 0x1c) =
       (*(float *)(*(int *)(this + 4) + 0x40) - fVar2) /
       (fVar2 - *(float *)(*(int *)(this + 4) + 0x30));
  return;
}


/* __thiscall JPAExtraShape::~JPAExtraShape(void) */

void __thiscall JPAExtraShape::_JPAExtraShape(JPAExtraShape *this)

{
  short in_r4;
  
  if ((this != (JPAExtraShape *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall JPAExtraShapeArc::~JPAExtraShapeArc(void) */

void __thiscall JPAExtraShapeArc::_JPAExtraShapeArc(JPAExtraShapeArc *this)

{
  short in_r4;
  
  if (this != (JPAExtraShapeArc *)0x0) {
    *(undefined ***)this = &__vt;
    if (this != (JPAExtraShapeArc *)0x0) {
      *(undefined1 **)this = &JPAExtraShape::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPAExtraShapeArc::isEnableScale(void) */

uint __thiscall JPAExtraShapeArc::isEnableScale(JPAExtraShapeArc *this)

{
  return **(uint **)(this + 4) & 0x100;
}


/* __thiscall JPAExtraShapeArc::isDiffXY(void) */

uint __thiscall JPAExtraShapeArc::isDiffXY(JPAExtraShapeArc *this)

{
  return **(uint **)(this + 4) & 0x200;
}


/* __thiscall JPAExtraShapeArc::isEnableScaleAnmX(void) */

uint __thiscall JPAExtraShapeArc::isEnableScaleAnmX(JPAExtraShapeArc *this)

{
  return **(uint **)(this + 4) & 0x800;
}


/* __thiscall JPAExtraShapeArc::isEnableScaleAnmY(void) */

uint __thiscall JPAExtraShapeArc::isEnableScaleAnmY(JPAExtraShapeArc *this)

{
  return **(uint **)(this + 4) & 0x400;
}


/* __thiscall JPAExtraShapeArc::isEnableScaleBySpeedX(void) */

uint __thiscall JPAExtraShapeArc::isEnableScaleBySpeedX(JPAExtraShapeArc *this)

{
  return **(uint **)(this + 4) & 0x2000;
}


/* __thiscall JPAExtraShapeArc::isEnableScaleBySpeedY(void) */

uint __thiscall JPAExtraShapeArc::isEnableScaleBySpeedY(JPAExtraShapeArc *this)

{
  return **(uint **)(this + 4) & 0x1000;
}


/* __thiscall JPAExtraShapeArc::getScaleInTiming(void) */

double __thiscall JPAExtraShapeArc::getScaleInTiming(JPAExtraShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x2c);
}


/* __thiscall JPAExtraShapeArc::getScaleOutTiming(void) */

double __thiscall JPAExtraShapeArc::getScaleOutTiming(JPAExtraShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x30);
}


/* __thiscall JPAExtraShapeArc::getScaleInValueX(void) */

double __thiscall JPAExtraShapeArc::getScaleInValueX(JPAExtraShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x34);
}


/* __thiscall JPAExtraShapeArc::getScaleInValueY(void) */

double __thiscall JPAExtraShapeArc::getScaleInValueY(JPAExtraShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x3c);
}


/* __thiscall JPAExtraShapeArc::getAnmTypeX(void) */

uint __thiscall JPAExtraShapeArc::getAnmTypeX(JPAExtraShapeArc *this)

{
  return **(uint **)(this + 4) >> 0x12 & 1;
}


/* __thiscall JPAExtraShapeArc::getAnmTypeY(void) */

uint __thiscall JPAExtraShapeArc::getAnmTypeY(JPAExtraShapeArc *this)

{
  return **(uint **)(this + 4) >> 0x13 & 1;
}


/* __thiscall JPAExtraShapeArc::getAnmCycleX(void) */

int __thiscall JPAExtraShapeArc::getAnmCycleX(JPAExtraShapeArc *this)

{
  return (int)*(short *)(*(int *)(this + 4) + 0x48);
}


/* __thiscall JPAExtraShapeArc::getAnmCycleY(void) */

int __thiscall JPAExtraShapeArc::getAnmCycleY(JPAExtraShapeArc *this)

{
  return (int)*(short *)(*(int *)(this + 4) + 0x4a);
}


/* __thiscall JPAExtraShapeArc::getIncreaseRateX(void) */

double __thiscall JPAExtraShapeArc::getIncreaseRateX(JPAExtraShapeArc *this)

{
  return (double)*(float *)(this + 0x10);
}


/* __thiscall JPAExtraShapeArc::getIncreaseRateY(void) */

double __thiscall JPAExtraShapeArc::getIncreaseRateY(JPAExtraShapeArc *this)

{
  return (double)*(float *)(this + 0x18);
}


/* __thiscall JPAExtraShapeArc::getDecreaseRateX(void) */

double __thiscall JPAExtraShapeArc::getDecreaseRateX(JPAExtraShapeArc *this)

{
  return (double)*(float *)(this + 0x14);
}


/* __thiscall JPAExtraShapeArc::getDecreaseRateY(void) */

double __thiscall JPAExtraShapeArc::getDecreaseRateY(JPAExtraShapeArc *this)

{
  return (double)*(float *)(this + 0x1c);
}


/* __thiscall JPAExtraShapeArc::getPivotX(void) */

uint __thiscall JPAExtraShapeArc::getPivotX(JPAExtraShapeArc *this)

{
  return **(uint **)(this + 4) >> 0xe & 3;
}


/* __thiscall JPAExtraShapeArc::getPivotY(void) */

uint __thiscall JPAExtraShapeArc::getPivotY(JPAExtraShapeArc *this)

{
  return **(uint **)(this + 4) >> 0x10 & 3;
}


/* __thiscall JPAExtraShapeArc::getRandomScale(void) */

double __thiscall JPAExtraShapeArc::getRandomScale(JPAExtraShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x44);
}


/* __thiscall JPAExtraShapeArc::isEnableAlpha(void) */

uint __thiscall JPAExtraShapeArc::isEnableAlpha(JPAExtraShapeArc *this)

{
  return **(uint **)(this + 4) & 1;
}


/* __thiscall JPAExtraShapeArc::isEnableSinWave(void) */

uint __thiscall JPAExtraShapeArc::isEnableSinWave(JPAExtraShapeArc *this)

{
  return **(uint **)(this + 4) & 2;
}


/* __thiscall JPAExtraShapeArc::getAlphaInTiming(void) */

double __thiscall JPAExtraShapeArc::getAlphaInTiming(JPAExtraShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 8);
}


/* __thiscall JPAExtraShapeArc::getAlphaOutTiming(void) */

double __thiscall JPAExtraShapeArc::getAlphaOutTiming(JPAExtraShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0xc);
}


/* __thiscall JPAExtraShapeArc::getAlphaInValue(void) */

double __thiscall JPAExtraShapeArc::getAlphaInValue(JPAExtraShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x10);
}


/* __thiscall JPAExtraShapeArc::getAlphaBaseValue(void) */

double __thiscall JPAExtraShapeArc::getAlphaBaseValue(JPAExtraShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x14);
}


/* __thiscall JPAExtraShapeArc::getAlphaWaveType(void) */

uint __thiscall JPAExtraShapeArc::getAlphaWaveType(JPAExtraShapeArc *this)

{
  return **(uint **)(this + 4) >> 2 & 3;
}


/* __thiscall JPAExtraShapeArc::getAlphaWaveParam1(void) */

double __thiscall JPAExtraShapeArc::getAlphaWaveParam1(JPAExtraShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x1c);
}


/* __thiscall JPAExtraShapeArc::getAlphaWaveParam2(void) */

double __thiscall JPAExtraShapeArc::getAlphaWaveParam2(JPAExtraShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x20);
}


/* __thiscall JPAExtraShapeArc::getAlphaWaveParam3(void) */

double __thiscall JPAExtraShapeArc::getAlphaWaveParam3(JPAExtraShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x24);
}


/* __thiscall JPAExtraShapeArc::getAlphaWaveRandom(void) */

double __thiscall JPAExtraShapeArc::getAlphaWaveRandom(JPAExtraShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x28);
}


/* __thiscall JPAExtraShapeArc::getAlphaIncreaseRate(void) */

double __thiscall JPAExtraShapeArc::getAlphaIncreaseRate(JPAExtraShapeArc *this)

{
  return (double)*(float *)(this + 8);
}


/* __thiscall JPAExtraShapeArc::getAlphaDecreaseRate(void) */

double __thiscall JPAExtraShapeArc::getAlphaDecreaseRate(JPAExtraShapeArc *this)

{
  return (double)*(float *)(this + 0xc);
}


/* __thiscall JPAExtraShapeArc::isEnableRotate(void) */

uint __thiscall JPAExtraShapeArc::isEnableRotate(JPAExtraShapeArc *this)

{
  return **(uint **)(this + 4) & 0x1000000;
}


/* __thiscall JPAExtraShapeArc::getRotateAngle(void) */

double __thiscall JPAExtraShapeArc::getRotateAngle(JPAExtraShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x4c);
}


/* __thiscall JPAExtraShapeArc::getRotateSpeed(void) */

double __thiscall JPAExtraShapeArc::getRotateSpeed(JPAExtraShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x50);
}


/* __thiscall JPAExtraShapeArc::getRotateRandomAngle(void) */

double __thiscall JPAExtraShapeArc::getRotateRandomAngle(JPAExtraShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x54);
}


/* __thiscall JPAExtraShapeArc::getRotateRandomSpeed(void) */

double __thiscall JPAExtraShapeArc::getRotateRandomSpeed(JPAExtraShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x58);
}


/* __thiscall JPAExtraShapeArc::getRotateDirection(void) */

double __thiscall JPAExtraShapeArc::getRotateDirection(JPAExtraShapeArc *this)

{
  return (double)*(float *)(*(int *)(this + 4) + 0x5c);
}

