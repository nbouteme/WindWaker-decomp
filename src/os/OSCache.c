#include <os/OSCache.h>
#include <os/OSInterrupt.h>
#include <os/OSCache.h>
#include <base/PPCArch.h>
#include <db/db.h>
#include <m_Do_printf.h>
#include <os/OSContext.h>
#include <os/OSError.h>


namespace os {

uint DCEnable(void)

{
  uint in_HID0;
  
  sync(0);
  return in_HID0 | 0x4000;
}


uint DCInvalidateRange(uint param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    return param_1;
  }
  uVar1 = param_2 + (param_1 & 0x1f) + 0x1f >> 5;
  do {
    dataCacheBlockInvalidate(param_1);
    param_1 = param_1 + 0x20;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return param_1;
}


uint DCFlushRange(uint param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    return param_1;
  }
  uVar1 = param_2 + (param_1 & 0x1f) + 0x1f >> 5;
  do {
    dataCacheBlockFlush(param_1);
    param_1 = param_1 + 0x20;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  syscall();
  return param_1;
}


uint DCStoreRange(uint param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    return param_1;
  }
  uVar1 = param_2 + (param_1 & 0x1f) + 0x1f >> 5;
  do {
    dataCacheBlockStore(param_1);
    param_1 = param_1 + 0x20;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  syscall();
  return param_1;
}


uint DCFlushRangeNoSync(uint param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    return param_1;
  }
  uVar1 = param_2 + (param_1 & 0x1f) + 0x1f >> 5;
  do {
    dataCacheBlockFlush(param_1);
    param_1 = param_1 + 0x20;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return param_1;
}


uint DCStoreRangeNoSync(uint param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    return param_1;
  }
  uVar1 = param_2 + (param_1 & 0x1f) + 0x1f >> 5;
  do {
    dataCacheBlockStore(param_1);
    param_1 = param_1 + 0x20;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return param_1;
}


uint DCZeroRange(uint param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    return param_1;
  }
  uVar1 = param_2 + (param_1 & 0x1f) + 0x1f >> 5;
  do {
    dataCacheBlockClearToZero(param_1);
    param_1 = param_1 + 0x20;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return param_1;
}


uint ICInvalidateRange(uint param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    return param_1;
  }
  uVar1 = param_2 + (param_1 & 0x1f) + 0x1f >> 5;
  do {
    instructionCacheBlockInvalidate(param_1);
    param_1 = param_1 + 0x20;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  sync(0);
  instructionSynchronize();
  return param_1;
}


uint ICFlashInvalidate(void)

{
  uint in_HID0;
  
  return in_HID0 | 0x800;
}


uint ICEnable(void)

{
  uint in_HID0;
  
  instructionSynchronize();
  return in_HID0 | 0x8000;
}


ulonglong __LCEnable(void)

{
  int iVar1;
  int iVar2;
  undefined4 in_HID2;
  
  iVar1 = -0x80000000;
  iVar2 = 0x400;
  do {
    dataCacheBlockTouch(iVar1);
    dataCacheBlockStore(iVar1);
    iVar1 = iVar1 + 0x20;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  instructionSynchronize();
  iVar1 = -0x20000000;
  iVar2 = 0x200;
  do {
    dataCacheBlockSetToZeroLocked(iVar1);
    iVar1 = iVar1 + 0x20;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT44(iVar1,in_HID2) | 0x100f0000;
}


void LCEnable(void)

{
  undefined4 uVar1;
  
  uVar1 = OSDisableInterrupts();
  __LCEnable();
  OSRestoreInterrupts(uVar1);
  return;
}


ulonglong LCDisable(void)

{
  int iVar1;
  int iVar2;
  undefined4 in_HID2;
  
  iVar1 = -0x20000000;
  iVar2 = 0x200;
  do {
    dataCacheBlockInvalidate(iVar1);
    iVar1 = iVar1 + 0x20;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT44(iVar1,in_HID2) & 0xffffffffefffffff;
}


uint LCStoreBlocks(uint param_1)

{
  return param_1 & 0xfffffff;
}


uint LCStoreData(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_3 + 0x1fU >> 5;
  uVar1 = uVar2 + 0x7f;
  while (uVar2 != 0) {
    if (uVar2 < 0x80) {
      LCStoreBlocks(param_1,param_2,uVar2);
      uVar2 = 0;
    }
    else {
      LCStoreBlocks(param_1,param_2,0);
      uVar2 = uVar2 - 0x80;
      param_1 = param_1 + 0x1000;
      param_2 = param_2 + 0x1000;
    }
  }
  return uVar1 >> 7;
}


void LCQueueWait(int param_1)

{
  uint in_HID2;
  
  do {
  } while (param_1 + 1 <= (int)(in_HID2 >> 0x18 & 0xf));
  return;
}


void L2GlobalInvalidate(void)

{
  uint uVar1;
  
  sync(0);
  uVar1 = base::PPCMfl2cr();
  base::PPCMtl2cr(uVar1 & 0x7fffffff);
  sync(0);
  uVar1 = base::PPCMfl2cr();
  base::PPCMtl2cr(uVar1 | 0x200000);
  do {
    uVar1 = base::PPCMfl2cr();
  } while ((uVar1 & 1) != 0);
  uVar1 = base::PPCMfl2cr();
  base::PPCMtl2cr(uVar1 & 0xffdfffff);
  while (uVar1 = base::PPCMfl2cr(), (uVar1 & 1) != 0) {
    db::DBPrintf(_63);
  }
  return;
}


void DMAErrorHandler(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = base::PPCMfhid2();
  m_Do_printf::OSReport(_84);
  m_Do_printf::OSReport(_85,uVar1,*(undefined4 *)(param_2 + 0x19c));
  if (((uVar1 & 0xf00000) == 0) || ((*(uint *)(param_2 + 0x19c) & 0x200000) == 0)) {
    m_Do_printf::OSReport(_86);
    OSDumpContext(param_2);
    base::PPCHalt();
  }
  m_Do_printf::OSReport(_87);
  m_Do_printf::OSReport(_88);
  if ((uVar1 & 0x800000) != 0) {
    m_Do_printf::OSReport(_89);
  }
  if ((uVar1 & 0x400000) != 0) {
    m_Do_printf::OSReport(_90);
  }
  if ((uVar1 & 0x200000) != 0) {
    m_Do_printf::OSReport(_91);
  }
  if ((uVar1 & 0x100000) != 0) {
    m_Do_printf::OSReport(_92);
  }
  base::PPCMthid2(uVar1);
  return;
}


void __OSCacheInit(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = base::PPCMfhid0();
  if ((uVar1 & 0x8000) == 0) {
    ICEnable();
    db::DBPrintf(_104);
  }
  uVar1 = base::PPCMfhid0();
  if ((uVar1 & 0x4000) == 0) {
    DCEnable();
    db::DBPrintf(_105);
  }
  uVar1 = base::PPCMfl2cr();
  if ((uVar1 & 0x80000000) == 0) {
    uVar2 = base::PPCMfmsr();
    sync(0);
    base::PPCMtmsr(0x30);
    sync(0);
    sync(0);
    uVar1 = base::PPCMfl2cr();
    base::PPCMtl2cr(uVar1 & 0x7fffffff);
    sync(0);
    L2GlobalInvalidate();
    base::PPCMtmsr(uVar2);
    uVar1 = base::PPCMfl2cr();
    base::PPCMtl2cr(uVar1 & 0xffdfffff | 0x80000000);
    db::DBPrintf(_106);
  }
  OSSetErrorHandler(1,DMAErrorHandler);
  db::DBPrintf(_107);
  return;
}

