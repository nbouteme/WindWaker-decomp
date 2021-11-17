#include <JAudio/JASKernelDebug.h>
#include <JASystem/Kernel.h>


namespace JASystem {

/* __thiscall Kernel::stackInit(unsigned long long *,
                                          unsigned long) */

void __thiscall Kernel::stackInit(Kernel *this,long_long *param_1,ulong param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 8;
  iVar1 = (int)param_1 + -1;
  if (param_1 < &DAT_00000002) {
    return;
  }
  do {
    *(undefined4 *)((int)(this + iVar2) + 4) = 0x12345678;
    *(undefined4 *)(this + iVar2) = 0xfadebabe;
    iVar2 = iVar2 + 8;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

