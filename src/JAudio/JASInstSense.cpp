#include <JAudio/JASInstSense.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JASystem/TInstSense.h>


namespace JASystem {

/* __thiscall TInstSense::getY(int,
                                         int) const */

double __thiscall TInstSense::getY(TInstSense *this,int param_1,int param_2)

{
  TInstSense TVar1;
  uint uVar2;
  double dVar3;
  
  TVar1 = this[8];
  if (((TVar1 != (TInstSense)0x2) && (param_1 = 0, (byte)TVar1 < 2)) &&
     (param_1 = param_2, TVar1 == (TInstSense)0x0)) {
    param_1 = 0;
  }
  uVar2 = (uint)(byte)this[9];
  if ((uVar2 == 0x7f) || (uVar2 == 0)) {
    dVar3 = (double)(*(float *)(this + 0xc) +
                    ((float)((double)CONCAT44(0x43300000,param_1 ^ 0x80000000) - JAudio::_600) *
                    (*(float *)(this + 0x10) - *(float *)(this + 0xc))) / JAudio::_596);
  }
  else {
    if (param_1 < (int)uVar2) {
      dVar3 = (double)(*(float *)(this + 0xc) +
                      (JAudio::_597 - *(float *)(this + 0xc)) *
                      ((float)((double)CONCAT44(0x43300000,param_1 ^ 0x80000000) - JAudio::_600) /
                      (float)((double)CONCAT44(0x43300000,uVar2) - JAudio::_602)));
    }
    else {
      dVar3 = (double)(JAudio::_597 +
                      (*(float *)(this + 0x10) - JAudio::_597) *
                      ((float)((double)CONCAT44(0x43300000,param_1 - uVar2 ^ 0x80000000) -
                              JAudio::_600) /
                      (float)((double)CONCAT44(0x43300000,0x7f - uVar2 ^ 0x80000000) - JAudio::_600)
                      ));
    }
  }
  return dVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TInstSense::setParams(int,
                                              int,
                                              float,
                                              float) */

void __thiscall
TInstSense::setParams
          (TInstSense *this,int param_1,int param_2,float param_3,float param_4)

{
  ulong uVar1;
  double dVar2;
  double dVar3;
  
  dVar3 = (double)param_4;
  dVar2 = (double)param_3;
  if (param_1 < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASInstSense.cpp",0x2b,"trigger >= 0");
    m_Do_printf::OSPanic("JASInstSense.cpp",0x2b,&DAT_80367d8e);
  }
  if (0xff < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASInstSense.cpp",0x2c,"trigger < 256");
    m_Do_printf::OSPanic("JASInstSense.cpp",0x2c,&DAT_80367d8e);
  }
  this[8] = SUB41(param_1,0);
  if (param_2 < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASInstSense.cpp",0x2f,"centerkey >= 0");
    m_Do_printf::OSPanic("JASInstSense.cpp",0x2f,&DAT_80367d8e);
  }
  if (0xff < param_2) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASInstSense.cpp",0x30,"centerkey < 256");
    m_Do_printf::OSPanic("JASInstSense.cpp",0x30,&DAT_80367d8e);
  }
  this[9] = SUB41(param_2,0);
  *(float *)(this + 0xc) = (float)dVar2;
  *(float *)(this + 0x10) = (float)dVar3;
  return;
}

