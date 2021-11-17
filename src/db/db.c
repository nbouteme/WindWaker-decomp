#include <db/db.h>
#include <db/db.h>
#include <m_Do_printf.h>
#include <os/OSContext.h>
#include <base/PPCArch.h>


namespace db {
undefined4 __DBInterface;
undefined4 DBVerbose;

void DBInit(void)

{
  DAT_80000048 = 0x30d020;
  __DBInterface = &DAT_80000040;
  DBVerbose = 1;
  return;
}


void __DBExceptionDestinationAux(void)

{
  int iVar1;
  
  iVar1 = iRam000000c0 + -0x80000000;
  m_Do_printf::OSReport(_9);
  os::OSDumpContext(iVar1);
  base::PPCHalt();
  return;
}


void __DBExceptionDestination(void)

{
  uint in_MSR;
  
  __DBExceptionDestinationAux(in_MSR | 0x30);
  return;
}


uint __DBIsExceptionMarked(uint param_1)

{
  return *(uint *)(__DBInterface + 4) & 1 << (param_1 & 0xff);
}


void DBPrintf(void)

{
  return;
}

