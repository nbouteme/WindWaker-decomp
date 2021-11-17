#include <dvd/fstload.h>
#include <dvd/fstload.h>
#include <dvd/dvd.h>
#include <os/OSArena.h>
#include <m_Do_printf.h>


namespace dvd {
undefined bb2Buf;
undefined block$18;
undefined4 status;
undefined4 bb2;
undefined4 idTmp;

void cb(int param_1,undefined4 param_2)

{
  if (param_1 < 1) {
    if ((param_1 != -1) && (param_1 == -4)) {
      status = 0;
      DVDReset();
      DVDReadDiskID(param_2,idTmp,cb);
    }
  }
  else {
    if (status == 1) {
      status = 2;
      DVDReadAbsAsyncForBS
                (param_2,*(undefined4 *)(bb2 + 0x10),*(int *)(bb2 + 8) + 0x1fU & 0xffffffe0,
                 *(undefined4 *)(bb2 + 4),cb);
    }
    else {
      if ((status < 1) && (-1 < status)) {
        status = 1;
        DVDReadAbsAsyncForBS(param_2,bb2,0x20,0x420,cb);
      }
    }
  }
  return;
}


void __fstLoad(void)

{
  int iVar1;
  undefined *puVar2;
  byte abStack64 [52];
  
  os::OSGetArenaHi();
  idTmp = abStack64;
  bb2 = &DAT_803f1100;
  DVDReset();
  DVDReadDiskID(&block_18,idTmp,cb);
  do {
    iVar1 = DVDGetDriveStatus();
  } while (iVar1 != 0);
  DAT_80000038 = *(undefined4 *)(bb2 + 0x10);
  DAT_8000003c = *(undefined4 *)(bb2 + 0xc);
  copy_bytes((byte *)&DAT_80000000,idTmp,0x20);
  m_Do_printf::OSReport(&_37);
  m_Do_printf::OSReport(_38,(int)DAT_80000000,(int)DAT_80000001,(int)DAT_80000002,(int)DAT_80000003)
  ;
  m_Do_printf::OSReport(_39,(int)DAT_80000004,(int)DAT_80000005);
  m_Do_printf::OSReport(_40,DAT_80000006);
  m_Do_printf::OSReport(_41,DAT_80000007);
  if (DAT_80000008 == '\0') {
    puVar2 = &_42;
  }
  else {
    puVar2 = &_43;
  }
  m_Do_printf::OSReport(_44,puVar2);
  m_Do_printf::OSReport(&_37);
  os::OSSetArenaHi(*(undefined4 *)(bb2 + 0x10));
  return;
}

