#include <JMath/random.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JMath/TRandom_enough_.h>
#include <JMath/TRandom_fast_.h>


namespace JKernel {

namespace JMath {

/* __thiscall JMath::TRandom_fast_::TRandom_fast_(unsigned long) */

void __thiscall TRandom_fast_::TRandom_fast_(TRandom_fast_ *this,ulong param_1)

{
  this->v = param_1;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JMath::TRandom_enough_::setSeed(unsigned long) */

void __thiscall TRandom_enough_::setSeed(TRandom_enough_ *this,ulong param_1)

{
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(this + 4) = 0;
  *(ulong *)this = param_1 + 1;
  if (*(int *)this == 0) {
    *(undefined4 *)this = 1;
  }
  iVar1 = 8;
  do {
    Runtime.PPCEABI.H::__mod2u
              ((int)((ulonglong)*(uint *)this * 0x41a7 >> 0x20),*(uint *)this * 0x41a7,0,0x7fffffff)
    ;
    *(undefined4 *)this = extraout_r4;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar2 = 0x20;
  iVar1 = 0x80;
  do {
    iVar2 = iVar2 + -1;
    Runtime.PPCEABI.H::__mod2u
              ((int)((ulonglong)*(uint *)this * 0x41a7 >> 0x20),*(uint *)this * 0x41a7,0,0x7fffffff)
    ;
    *(undefined4 *)this = extraout_r4_00;
    *(undefined4 *)(this + iVar1 + 4) = *(undefined4 *)this;
    iVar1 = iVar1 + -4;
  } while (iVar2 != 0);
  return;
}


/* __thiscall JMath::TRandom_enough_::get(void) */

double __thiscall TRandom_enough_::get(TRandom_enough_ *this)

{
  uint uVar1;
  undefined4 extraout_r4;
  double dVar2;
  double dVar3;
  
  Runtime.PPCEABI.H::__mod2u
            ((int)((ulonglong)*(uint *)this * 0x41a7 >> 0x20),*(uint *)this * 0x41a7,0,0x7fffffff);
  *(undefined4 *)this = extraout_r4;
  uVar1 = *(uint *)(this + 4);
  *(undefined4 *)(this + 4) = *(undefined4 *)(this + (uVar1 >> 0x18 & 0xfc) + 8);
  *(undefined4 *)(this + (uVar1 >> 0x18 & 0xfc) + 8) = *(undefined4 *)this;
  dVar3 = (double)(_336 * (float)((double)CONCAT44(0x43300000,*(undefined4 *)(this + 4)) - _339));
  dVar2 = (double)_337;
  if (dVar3 < dVar2) {
    dVar2 = dVar3;
  }
  return dVar2;
}

