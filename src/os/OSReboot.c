#include <os/OSReboot.h>
#include <os/OSInterrupt.h>
#include <os/OSContext.h>
#include <dvd/dvd.h>
#include <os/OSReboot.h>
#include <os/OSReset.h>
#include <os/OSCache.h>


namespace os {
undefined Header;
undefined4 SaveStart;
undefined4 SaveEnd;
undefined4 Prepared;

void Run(void)

{
  sync(0);
  instructionSynchronize();
  return;
}


void Callback(void)

{
  Prepared = 1;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __OSReboot(void)

{
  uint uVar1;
  int iVar2;
  undefined auStack816 [12];
  int local_324;
  undefined auStack768 [12];
  int local_2f4;
  undefined auStack720 [712];
  
  OSDisableInterrupts();
  _DAT_817ffffc = 0;
  _DAT_817ffff8 = 0;
  DAT_800030e2 = 1;
  _DAT_812fdff0 = SaveStart;
  _DAT_812fdfec = SaveEnd;
  OSClearContext(auStack720);
  OSSetCurrentContext(auStack720);
  dvd::DVDInit();
  dvd::DVDSetAutoInvalidation(1);
  dvd::__DVDPrepareResetAsync(Callback);
  iVar2 = dvd::DVDCheckDisk();
  if (iVar2 == 0) {
    __OSDoHotReset(_DAT_817ffffc);
  }
  __OSMaskInterrupts(0xffffffe0);
  __OSUnmaskInterrupts(0x400);
  OSEnableInterrupts();
  do {
  } while (Prepared == 0);
  dvd::DVDReadAbsAsyncForBS(auStack768,&Header,0x20,0x2440,0);
  do {
    while( true ) {
      do {
      } while (local_2f4 == 1);
      if (local_2f4 < 1) break;
      if (local_2f4 < 0xc) {
LAB_80306544:
        __OSDoHotReset(_DAT_817ffffc);
      }
    }
    if (local_2f4 == -1) goto LAB_80306544;
  } while (local_2f4 < -1);
  uVar1 = DAT_803f0258 + 0x1fU & 0xffffffe0;
  do {
  } while (Prepared == 0);
  dvd::DVDReadAbsAsyncForBS(auStack816,0x81300000,uVar1,DAT_803f0254 + 0x2460,0);
  do {
    while( true ) {
      do {
      } while (local_324 == 1);
      if (0 < local_324) break;
      if (local_324 == -1) goto LAB_803065c8;
      if (-2 < local_324) {
        ICInvalidateRange(0x81300000,uVar1);
        OSDisableInterrupts();
        ICFlashInvalidate();
        Run(0x81300000);
        return;
      }
    }
    if (local_324 < 0xc) {
LAB_803065c8:
      __OSDoHotReset(_DAT_817ffffc);
    }
  } while( true );
}


void OSSetSaveRegion(undefined4 param_1,undefined4 param_2)

{
  SaveStart = param_1;
  SaveEnd = param_2;
  return;
}

