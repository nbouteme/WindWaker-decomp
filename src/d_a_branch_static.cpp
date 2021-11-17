#include <d_a_branch_static.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JUtility/JUTNameTab.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <daBranch_c.h>


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall daBranch_c::getJointMtx(char const *) */

int __thiscall daBranch_c::getJointMtx(daBranch_c *this,char *param_1)

{
  ushort uVar1;
  ulong uVar2;
  char *__s1;
  int iVar3;
  ushort uVar4;
  JUTNameTab *this_00;
  
  if (*(int *)(this + 0x298) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_a_branch_static.cpp",0x16,"mModel[0] != 0");
    m_Do_printf::OSPanic("d_a_branch_static.cpp",0x16,&DAT_8034fcb5);
  }
  this_00 = *(JUTNameTab **)(*(int *)(*(int *)(this + 0x298) + 4) + 0x54);
  uVar1 = *(ushort *)(*(int *)(*(int *)(this + 0x298) + 4) + 0x28);
  if ((this_00 != (JUTNameTab *)0x0) && (uVar1 != 0)) {
    for (uVar4 = 0; uVar4 < uVar1; uVar4 = uVar4 + 1) {
      __s1 = (char *)JUTNameTab::getName(this_00,uVar4);
      iVar3 = MSL_C.PPCEABI.bare.H::strcmp(__s1,param_1);
      if (iVar3 == 0) {
        return *(int *)(*(int *)(this + 0x298) + 0x8c) + (uint)uVar4 * 0x30;
      }
    }
  }
  return 0;
}

