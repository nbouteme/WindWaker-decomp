#include <os/OSAudioSystem.h>
#include <os/OSArena.h>
#include <os/OSCache.h>
#include <os/OSTime.h>


namespace os {

/* WARNING: Removing unreachable block (ram,0x80302ed4) */
/* WARNING: Removing unreachable block (ram,0x80302e7c) */
/* WARNING: Removing unreachable block (ram,0x80302e88) */
/* WARNING: Removing unreachable block (ram,0x80302ea4) */
/* WARNING: Removing unreachable block (ram,0x80302ed8) */
/* WARNING: Removing unreachable block (ram,0x80302ee0) */
/* WARNING: Removing unreachable block (ram,0x80302eec) */
/* WARNING: Removing unreachable block (ram,0x80302efc) */
/* WARNING: Removing unreachable block (ram,0x80302f20) */
/* WARNING: Removing unreachable block (ram,0x80302f28) */
/* WARNING: Removing unreachable block (ram,0x80302f38) */
/* WARNING: Removing unreachable block (ram,0x80302f44) */
/* WARNING: Removing unreachable block (ram,0x80302f5c) */
/* WARNING: Removing unreachable block (ram,0x80302f68) */
/* WARNING: Removing unreachable block (ram,0x80302f8c) */
/* WARNING: Removing unreachable block (ram,0x80302f58) */
/* WARNING: Removing unreachable block (ram,0x80302f1c) */
/* WARNING: Removing unreachable block (ram,0x80302f98) */

void __OSInitAudioSystem(void)

{
  int iVar1;
  
  iVar1 = OSGetArenaHi();
  copy_bytes((byte *)(iVar1 + -0x80),(byte *)0x81000000,0x80);
  copy_bytes((byte *)0x81000000,&DSPInitCode,0x80);
  DCFlushRange(0x81000000,0x80);
  do {
  } while( true );
}


/* WARNING: Removing unreachable block (ram,0x80302ffc) */
/* WARNING: Removing unreachable block (ram,0x80303010) */
/* WARNING: Removing unreachable block (ram,0x80303080) */

void __OSStopAudioSystem(void)

{
  int iVar1;
  int iVar2;
  
  DAT_cc005036 = DAT_cc005036 & 0x7fff;
  DAT_cc00500a = 0x8ac;
  DAT_cc005000 = 0;
  do {
  } while ((DAT_cc005004 & 0x8000) != 0);
  iVar1 = OSGetTick();
  do {
    iVar2 = OSGetTick();
  } while (iVar2 - iVar1 < 0x2c);
  do {
  } while( true );
}

