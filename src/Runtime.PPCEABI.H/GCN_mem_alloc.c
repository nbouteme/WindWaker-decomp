#include <Runtime.PPCEABI.H/GCN_mem_alloc.h>
#include <m_Do_printf.h>
#include <os/OSArena.h>
#include <os/OSAlloc.h>


namespace Runtime.PPCEABI.H {

void __sys_free(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if (os::__OSCurrHeap == -1) {
    m_Do_printf::OSReport("GCN_Mem_Alloc.c : InitDefaultHeap. No Heap Available\n");
    m_Do_printf::OSReport("Metrowerks CW runtime library initializing default heap\n");
    uVar1 = os::OSGetArenaLo();
    uVar2 = os::OSGetArenaHi();
    iVar3 = os::OSInitAlloc(uVar1,uVar2,1);
    os::OSSetArenaLo();
    os::OSCreateHeap(iVar3 + 0x1fU & 0xffffffe0,uVar2 & 0xffffffe0);
    os::OSSetCurrentHeap();
    os::OSSetArenaLo(uVar2 & 0xffffffe0);
  }
  os::OSFreeToHeap(os::__OSCurrHeap,param_1);
  return;
}

