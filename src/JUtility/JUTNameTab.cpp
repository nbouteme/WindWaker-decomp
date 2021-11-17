#include <JUtility/JUTNameTab.h>
#include <JUtility/JUTNameTab.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JUTNameTab.h>


/* __thiscall JUTNameTab::JUTNameTab(void) */

void __thiscall JUTNameTab::JUTNameTab(JUTNameTab *this)

{
  this->vtbl = &__vt;
  setResource(this,(ResNTAB *)0x0);
  return;
}


/* __thiscall JUTNameTab::JUTNameTab(ResNTAB const *) */

void __thiscall JUTNameTab::JUTNameTab(JUTNameTab *this,ResNTAB *param_1)

{
  this->vtbl = &__vt;
  setResource(this,param_1);
  return;
}


/* __thiscall JUTNameTab::setResource(ResNTAB const *) */

void __thiscall JUTNameTab::setResource(JUTNameTab *this,ResNTAB *param_1)

{
  this->mpRes = param_1;
  if (param_1 != (ResNTAB *)0x0) {
    this->mCount = param_1->mCount;
    this->mpStrData = (uchar *)(param_1->mEntries + (uint)(ushort)this->mCount * 2);
    return;
  }
  this->mCount = 0;
  this->mpStrData = (uchar *)0x0;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JUTNameTab::getIndex(char const *) const */

uint __thiscall JUTNameTab::getIndex(JUTNameTab *this,char *param_1)

{
  ulong uVar1;
  ResNTAB *pRVar2;
  short sVar4;
  int iVar3;
  ushort uVar5;
  
  if (this->mpRes == (ResNTAB *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JUTNameTab.cpp",0x65,"mNameTable != 0");
    m_Do_printf::OSPanic("JUTNameTab.cpp",0x65,&DAT_8036be3f);
  }
  pRVar2 = this->mpRes;
  sVar4 = calcKeyCode(this,param_1);
  uVar5 = 0;
  while( true ) {
    pRVar2 = (ResNTAB *)pRVar2->mEntries;
    if ((ushort)this->mCount <= uVar5) {
      return 0xffffffff;
    }
    if ((pRVar2->mCount == sVar4) &&
       (iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                          ((char *)((int)this->mpRes->mEntries +
                                   ((ushort)this->mpRes->mEntries[(uint)uVar5 * 2 + 1] - 4)),param_1
                          ), iVar3 == 0)) break;
    uVar5 = uVar5 + 1;
  }
  return (uint)uVar5;
}


/* __thiscall JUTNameTab::getName(unsigned short) const */

int __thiscall JUTNameTab::getName(JUTNameTab *this,ushort param_1)

{
  ulong uVar1;
  int iVar2;
  
  if (this->mpRes == (ResNTAB *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JUTNameTab.cpp",0x8a,"mNameTable != 0");
    m_Do_printf::OSPanic("JUTNameTab.cpp",0x8a,&DAT_8036be3f);
  }
  if (param_1 < (ushort)this->mCount) {
    iVar2 = (int)this->mpRes->mEntries + ((ushort)this->mpRes->mEntries[(uint)param_1 * 2 + 1] - 4);
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


/* __thiscall JUTNameTab::calcKeyCode(char const *) const */

short __thiscall JUTNameTab::calcKeyCode(JUTNameTab *this,char *param_1)

{
  short sVar1;
  
  sVar1 = 0;
  while( true ) {
    if (*param_1 == '\0') break;
    sVar1 = (short)*param_1 + sVar1 * 3;
    param_1 = param_1 + 1;
  }
  return sVar1;
}

