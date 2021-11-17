#include <JAudio/JASInstEffect.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <Demangler/JASystem/TInstEffect.h>


namespace JASystem {

/* __thiscall TInstEffect::setTarget(int) */

void __thiscall TInstEffect::setTarget(TInstEffect *this,int param_1)

{
  ulong uVar1;
  
  if (param_1 < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASInstEffect.cpp",0x10,"target >= 0");
    m_Do_printf::OSPanic("JASInstEffect.cpp",0x10,&DAT_80367d5e);
  }
  if (0xff < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASInstEffect.cpp",0x11,"target < 256");
    m_Do_printf::OSPanic("JASInstEffect.cpp",0x11,&DAT_80367d5e);
  }
  this[4] = SUB41(param_1,0);
  return;
}

