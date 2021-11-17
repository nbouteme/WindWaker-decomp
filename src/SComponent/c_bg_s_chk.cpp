#include <SComponent/c_bg_s_chk.h>
#include <JKernel/JKRHeap.h>
#include <cBgS_Chk.h>


/* __thiscall cBgS_Chk::~cBgS_Chk(void) */

void __thiscall cBgS_Chk::_cBgS_Chk(cBgS_Chk *this)

{
  short in_r4;
  
  if ((this != (cBgS_Chk *)0x0) && (this->vtbl = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall cBgS_Chk::ChkSameActorPid(unsigned int) const */

bool __thiscall cBgS_Chk::ChkSameActorPid(cBgS_Chk *this,uint param_1)

{
  uint uVar1;
  
  if (((this->mProcID != -1) && (param_1 != 0xffffffff)) && (this->mbExcludeSameProcID != false)) {
    uVar1 = countLeadingZeros(param_1 - this->mProcID);
    return (bool)(char)(uVar1 >> 5);
  }
  return false;
}

