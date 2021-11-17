#include <dvd/dvderror.h>
#include <dvd/dvderror.h>
#include <os/OSRtc.h>


namespace dvd {

char ErrorCode2Num(uint param_1)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = 2;
  puVar1 = &ErrorTable;
  cVar2 = '\0';
  while( true ) {
    if (param_1 == *puVar1) {
      return cVar2;
    }
    if (param_1 == puVar1[1]) {
      return cVar2 + '\x01';
    }
    if (param_1 == puVar1[2]) {
      return cVar2 + '\x02';
    }
    if (param_1 == puVar1[3]) {
      return cVar2 + '\x03';
    }
    if (param_1 == puVar1[4]) {
      return cVar2 + '\x04';
    }
    if (param_1 == puVar1[5]) {
      return cVar2 + '\x05';
    }
    if (param_1 == puVar1[6]) {
      return cVar2 + '\x06';
    }
    if (param_1 == puVar1[7]) break;
    if (param_1 == puVar1[8]) {
      return cVar2 + '\b';
    }
    puVar1 = puVar1 + 9;
    cVar2 = cVar2 + '\t';
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      if ((0xfffff < param_1) && (param_1 < 0x100009)) {
        return '\x11';
      }
      return '\x1d';
    }
  }
  return cVar2 + '\a';
}


void __DVDStoreErrorCode(undefined *param_1)

{
  char cVar2;
  int iVar1;
  char cVar3;
  
  if (param_1 == &DAT_01234567) {
    cVar2 = -1;
  }
  else {
    if (param_1 == (undefined *)0x1234568) {
      cVar2 = -2;
    }
    else {
      cVar3 = (char)((uint)param_1 >> 0x18);
      cVar2 = ErrorCode2Num((uint)param_1 & 0xffffff);
      if (5 < (uint)param_1 >> 0x18) {
        cVar3 = '\x06';
      }
      cVar2 = cVar2 + cVar3 * '\x1e';
    }
  }
  iVar1 = os::__OSLockSramEx();
  *(char *)(iVar1 + 0x24) = cVar2;
  os::__OSUnlockSramEx(1);
  return;
}

