#include <os/OSSync.h>
#include <os/OSSync.h>
#include <os/OSCache.h>


namespace os {

void SystemCallVector(void)

{
  undefined4 in_MSR;
  undefined4 in_SRR1;
  
  instructionSynchronize();
  sync(0);
  returnFromInterrupt(in_MSR,in_SRR1);
  return;
}


void __OSInitSystemCall(void)

{
  copy_bytes(&DAT_80000c00,(byte *)SystemCallVector,0x1c);
  DCFlushRangeNoSync(&DAT_80000c00,0x100);
  sync(0);
  ICInvalidateRange(&DAT_80000c00,0x100);
  return;
}

