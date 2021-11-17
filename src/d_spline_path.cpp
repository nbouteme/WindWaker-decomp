#include <d_spline_path.h>
#include <cXyz.h>
#include <d2DBSplinePath.h>


/* __thiscall d2DBSplinePath::Init(long,
                                   long) */

void __thiscall d2DBSplinePath::Init(d2DBSplinePath *this,long timer,long keyframeNum)

{
  uint uVar1;
  uint uVar2;
  
  this->mKeyframeCur = 0;
  this->mTimer = timer;
  uVar2 = 1;
  this->mState = 1;
  this->field_0x10 = 0;
  this->mKeyframeLast = keyframeNum;
  this->mKeyframeNum = keyframeNum;
  if (this->mKeyframeLast != 0) {
    uVar2 = this->mKeyframeLast - 1;
  }
  if (this->mTimer < 2) {
    uVar1 = 1;
  }
  else {
    uVar1 = this->mTimer - 2;
  }
  this->mTime = (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - d_spline_path::_2194) /
                (float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - d_spline_path::_2194);
  *(undefined4 *)&this->field_0x3c = 0;
  return;
}


/* __thiscall d2DBSplinePath::Step(void) */

undefined4 __thiscall d2DBSplinePath::Step(d2DBSplinePath *this)

{
  float fVar1;
  float fVar2;
  double dVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  if (this->mKeyframeNum <= this->mKeyframeCur) {
    this->mState = 0;
  }
  if (this->mState == 1) {
    this->mState = 2;
  }
  dVar3 = d_spline_path::_2194;
  if (this->mState == 2) {
    if (this->mKeyframeLast + -1 < this->mKeyframeCur) {
      this->mState = 0;
    }
    else {
      fVar1 = this->mTime *
              (float)((double)CONCAT44(0x43300000,this->mKeyframeCur ^ 0x80000000) -
                     d_spline_path::_2194);
      this->field_0x10 = (int)fVar1;
      if (this->mKeyframeCur == this->mKeyframeNum + -1) {
        this->mState = 3;
      }
      fVar1 = fVar1 - (float)((double)CONCAT44(0x43300000,this->field_0x10 ^ 0x80000000) - dVar3);
      if (this->mKeyframeCur == this->mKeyframeLast + -1) {
        this->mState = 3;
        fVar1 = d_spline_path::1_0;
      }
      iVar7 = this->mTimer + -1;
      if (this->field_0x10 < iVar7) {
        iVar7 = this->field_0x10;
      }
      this->mFrameIdx[0] = iVar7;
      iVar5 = this->field_0x10 + 1;
      iVar7 = this->mTimer + -1;
      if (iVar5 < iVar7) {
        iVar7 = iVar5;
      }
      this->mFrameIdx[1] = iVar7;
      iVar5 = this->field_0x10 + 2;
      iVar7 = this->mTimer + -1;
      if (iVar5 < iVar7) {
        iVar7 = iVar5;
      }
      this->mFrameIdx[2] = iVar7;
      fVar4 = d_spline_path::0_5;
      fVar2 = d_spline_path::1_0 - fVar1;
      this->mFrameWeight[0] = d_spline_path::0_5 * fVar2 * fVar2;
      this->mFrameWeight[1] = fVar4 + fVar1 * fVar2;
      this->mFrameWeight[2] = fVar4 * fVar1 * fVar1;
      this->mKeyframeCur = this->mKeyframeCur + 1;
    }
  }
  uVar6 = 0;
  if ((this->mState == 2) || (this->mState == 3)) {
    uVar6 = 1;
  }
  return uVar6;
}


/* __thiscall d2DBSplinePath::Calc(cXyz *) */

cXyz * __thiscall
d2DBSplinePath::Calc(cXyz *__return_storage_ptr__,d2DBSplinePath *this,cXyz *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  fVar1 = this->mFrameWeight[2];
  fVar2 = this->mFrameWeight[0];
  fVar3 = this->mFrameWeight[1];
  fVar4 = param_1[this->mFrameIdx[2]].y;
  fVar5 = param_1[this->mFrameIdx[0]].y;
  fVar6 = param_1[this->mFrameIdx[1]].y;
  fVar7 = param_1[this->mFrameIdx[2]].z;
  fVar8 = param_1[this->mFrameIdx[0]].z;
  fVar9 = param_1[this->mFrameIdx[1]].z;
  __return_storage_ptr__->x =
       fVar1 * param_1[this->mFrameIdx[2]].x +
       fVar2 * param_1[this->mFrameIdx[0]].x + fVar3 * param_1[this->mFrameIdx[1]].x;
  __return_storage_ptr__->y = fVar1 * fVar4 + fVar2 * fVar5 + fVar3 * fVar6;
  __return_storage_ptr__->z = fVar1 * fVar7 + fVar2 * fVar8 + fVar3 * fVar9;
  return __return_storage_ptr__;
}


/* __thiscall d2DBSplinePath::Calc(float *) */

double __thiscall d2DBSplinePath::Calc(d2DBSplinePath *this,float *param_1)

{
  return (double)(this->mFrameWeight[2] * param_1[this->mFrameIdx[2]] +
                 this->mFrameWeight[0] * param_1[this->mFrameIdx[0]] +
                 this->mFrameWeight[1] * param_1[this->mFrameIdx[1]]);
}

