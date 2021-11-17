#include <SComponent/c_bg_s_lin_chk.h>
#include <cBgS_LinChk.h>


/* __thiscall cBgS_LinChk::ct(void) */

void __thiscall cBgS_LinChk::ct(cBgS_LinChk *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = ::cXyz::Zero.z;
  fVar2 = ::cXyz::Zero.y;
  fVar1 = ::cXyz::Zero.x;
  (this->mLin).mP0.x = ::cXyz::Zero.x;
  (this->mLin).mP0.y = fVar2;
  (this->mLin).mP0.z = fVar3;
  (this->mLin).mP1.x = fVar1;
  (this->mLin).mP1.y = fVar2;
  (this->mLin).mP1.z = fVar3;
  (this->field_0x40).x = fVar1;
  (this->field_0x40).y = fVar2;
  (this->field_0x40).z = fVar3;
  (this->parent).mProcID = -1;
  this->mFlags = 0;
  this->field_0x53 = 1;
  this->field_0x54 = 0;
  return;
}


/* __thiscall cBgS_LinChk::Set2(cXyz *,
                                cXyz *,
                                unsigned int) */

void __thiscall cBgS_LinChk::Set2(cBgS_LinChk *this,cXyz *pP0,cXyz *pP1,uint procID)

{
  (this->mLin).mP0.x = pP0->x;
  (this->mLin).mP0.y = pP0->y;
  (this->mLin).mP0.z = pP0->z;
  (this->mLin).mP1.x = pP1->x;
  (this->mLin).mP1.y = pP1->y;
  (this->mLin).mP1.z = pP1->z;
  (this->field_0x40).x = pP1->x;
  (this->field_0x40).y = pP1->y;
  (this->field_0x40).z = pP1->z;
  (this->parent).mProcID = procID;
  this->mFlags = this->mFlags & 0xffffffef;
  (this->mPolyInfo).mTriIdx = -1;
  (this->mPolyInfo).mBgIndex = 0x100;
  (this->mPolyInfo).mpBgW = (cBgW *)0x0;
  (this->mPolyInfo).mProcID = -1;
  return;
}

