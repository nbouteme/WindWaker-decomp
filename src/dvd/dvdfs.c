#include <dvd/dvdfs.h>
#include <m_Do_printf.h>
#include <MSL_C.PPCEABI.bare.H/ctype.h>
#include <dvd/dvdfs.h>
#include <dvd/dvd.h>
#include <os/OSInterrupt.h>
#include <os/OSThread.h>


namespace dvd {
undefined4 BootInfo;
undefined4 FstStart;
undefined4 FstStringStart;
undefined4 MaxEntryNum;
undefined4 currentDirectory;
undefined4 __DVDLongFileNameFlag;
undefined __DVDThreadQueue;

void __DVDFSInit(void)

{
  if (DAT_80000038 == 0) {
    BootInfo = 0x80000000;
    FstStart = DAT_80000038;
    return;
  }
  BootInfo = 0x80000000;
  FstStart = DAT_80000038;
  FstStringStart = DAT_80000038 + *(int *)(DAT_80000038 + 8) * 0xc;
  MaxEntryNum = *(int *)(DAT_80000038 + 8);
  return;
}


int DVDConvertPathToEntrynum(char *filePath)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char *unaff_r24;
  uint uVar12;
  char *pcVar13;
  int iVar14;
  
  pcVar11 = filePath;
  uVar12 = currentDirectory;
LAB_8030f2d4:
  while( true ) {
    while( true ) {
      cVar1 = *pcVar11;
      if (cVar1 == '\0') {
        return uVar12;
      }
      if (cVar1 != '/') break;
      uVar12 = 0;
      pcVar11 = pcVar11 + 1;
    }
    if (cVar1 != '.') break;
    cVar1 = pcVar11[1];
    if (cVar1 == '.') {
      if (pcVar11[2] != '/') {
        if (pcVar11[2] == '\0') {
          return *(uint *)(FstStart + uVar12 * 0xc + 4);
        }
        break;
      }
      uVar12 = *(uint *)(FstStart + uVar12 * 0xc + 4);
      pcVar11 = pcVar11 + 3;
    }
    else {
      if (cVar1 != '/') {
        if (cVar1 == '\0') {
          return uVar12;
        }
        break;
      }
      pcVar11 = pcVar11 + 2;
    }
  }
  pcVar13 = pcVar11;
  if (__DVDLongFileNameFlag == 0) {
    bVar3 = false;
    bVar4 = false;
LAB_8030f3d8:
    cVar1 = *pcVar13;
    if ((cVar1 == '\0') || (cVar1 == '/')) goto LAB_8030f3f0;
    if (cVar1 == '.') {
      if ((8 < (int)pcVar13 - (int)pcVar11) || (bVar3)) {
        bVar4 = true;
LAB_8030f3f0:
        if ((bVar3) && (3 < (int)pcVar13 - (int)unaff_r24)) {
          bVar4 = true;
        }
        if (bVar4) {
          m_Do_printf::OSPanic(&_118,0x17b,_119,filePath);
        }
        goto LAB_8030f450;
      }
      unaff_r24 = pcVar13 + 1;
      bVar3 = true;
    }
    else {
      if (cVar1 == ' ') {
        bVar4 = true;
      }
    }
    pcVar13 = pcVar13 + 1;
    goto LAB_8030f3d8;
  }
  for (; (*pcVar13 != '\0' && (*pcVar13 != '/')); pcVar13 = pcVar13 + 1) {
  }
LAB_8030f450:
  cVar1 = *pcVar13;
  iVar14 = uVar12 * 0xc;
  uVar12 = uVar12 + 1;
LAB_8030f558:
  if (*(uint *)(iVar14 + FstStart + 8) <= uVar12) {
    return 0xffffffff;
  }
  uVar8 = *(uint *)(FstStart + uVar12 * 0xc);
  if (((uVar8 & 0xff000000) != 0) || (cVar1 == '\0')) {
    pcVar9 = (char *)(FstStringStart + (uVar8 & 0xffffff));
    pcVar10 = pcVar11;
    do {
      if (*pcVar9 == '\0') {
        if ((*pcVar10 == '/') || (*pcVar10 == '\0')) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
        goto LAB_8030f518;
      }
      cVar2 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      iVar5 = MSL_C.PPCEABI.bare.H::tolower((int)cVar2);
      cVar2 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      iVar6 = MSL_C.PPCEABI.bare.H::tolower((int)cVar2);
    } while (iVar6 == iVar5);
    bVar3 = false;
LAB_8030f518:
    if (bVar3) goto LAB_8030f574;
  }
  puVar7 = (uint *)(FstStart + uVar12 * 0xc);
  if ((*puVar7 & 0xff000000) == 0) {
    uVar12 = uVar12 + 1;
  }
  else {
    uVar12 = puVar7[2];
  }
  goto LAB_8030f558;
LAB_8030f574:
  if (cVar1 == '\0') {
    return uVar12;
  }
  pcVar11 = pcVar13 + 1;
  goto LAB_8030f2d4;
}


undefined4 DVDFastOpen(uint param_1,int param_2)

{
  int iVar1;
  
  if (((-1 < (int)param_1) && (param_1 < MaxEntryNum)) &&
     (iVar1 = param_1 * 0xc, (*(uint *)(FstStart + iVar1) & 0xff000000) == 0)) {
    *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(FstStart + iVar1 + 4);
    *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(FstStart + iVar1 + 8);
    *(undefined4 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0xc) = 0;
    return 1;
  }
  return 0;
}


bool DVDOpen(char *param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  undefined auStack136 [128];
  
  iVar1 = DVDConvertPathToEntrynum(param_1);
  if (iVar1 < 0) {
    DVDGetCurrentDir(auStack136,0x80);
    m_Do_printf::OSReport(_140,param_1,auStack136);
    bVar2 = false;
  }
  else {
    iVar1 = iVar1 * 0xc;
    if ((*(uint *)(FstStart + iVar1) & 0xff000000) == 0) {
      bVar2 = true;
      *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(FstStart + iVar1 + 4);
      *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(FstStart + iVar1 + 8);
      *(undefined4 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0xc) = 0;
    }
    else {
      bVar2 = false;
    }
  }
  return bVar2;
}


undefined4 DVDClose(void)

{
  DVDCancel();
  return 1;
}


int entryToPath(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(FstStart + 4 + param_1 * 0xc);
    pcVar5 = (char *)(FstStringStart + (*(uint *)(FstStart + param_1 * 0xc) & 0xffffff));
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = iVar1 * 0xc;
      pcVar4 = (char *)(FstStringStart + (*(uint *)(FstStart + iVar1) & 0xffffff));
      iVar1 = entryToPath(*(undefined4 *)(FstStart + 4 + iVar1),param_2,param_3);
      if (iVar1 != param_3) {
        iVar2 = iVar1 + 1;
        *(undefined *)(param_2 + iVar1) = 0x2f;
        pcVar3 = (char *)(param_2 + iVar2);
        iVar1 = param_3 - iVar2;
        for (; (iVar1 != 0 && (*pcVar4 != '\0')); pcVar4 = pcVar4 + 1) {
          iVar1 = iVar1 + -1;
          *pcVar3 = *pcVar4;
          pcVar3 = pcVar3 + 1;
        }
        iVar1 = iVar2 + ((param_3 - iVar2) - iVar1);
      }
    }
    if (iVar1 != param_3) {
      iVar2 = iVar1 + 1;
      *(undefined *)(param_2 + iVar1) = 0x2f;
      pcVar4 = (char *)(param_2 + iVar2);
      iVar1 = param_3 - iVar2;
      for (; (iVar1 != 0 && (*pcVar5 != '\0')); pcVar5 = pcVar5 + 1) {
        iVar1 = iVar1 + -1;
        *pcVar4 = *pcVar5;
        pcVar4 = pcVar4 + 1;
      }
      iVar1 = iVar2 + ((param_3 - iVar2) - iVar1);
    }
  }
  return iVar1;
}


undefined4 DVDConvertEntrynumToPath(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    pcVar5 = (char *)(FstStringStart + (*(uint *)(FstStart + param_1 * 0xc) & 0xffffff));
    iVar1 = entryToPath(*(undefined4 *)(FstStart + param_1 * 0xc + 4),param_2,param_3);
    if (iVar1 != param_3) {
      iVar2 = iVar1 + 1;
      *(undefined *)(param_2 + iVar1) = 0x2f;
      pcVar4 = (char *)(param_2 + iVar2);
      iVar1 = param_3 - iVar2;
      for (; (iVar1 != 0 && (*pcVar5 != '\0')); pcVar5 = pcVar5 + 1) {
        iVar1 = iVar1 + -1;
        *pcVar4 = *pcVar5;
        pcVar4 = pcVar4 + 1;
      }
      iVar1 = iVar2 + ((param_3 - iVar2) - iVar1);
    }
  }
  if (iVar1 == param_3) {
    *(undefined *)(param_2 + param_3 + -1) = 0;
    uVar3 = 0;
  }
  else {
    if ((*(uint *)(FstStart + param_1 * 0xc) & 0xff000000) != 0) {
      if (iVar1 == param_3 + -1) {
        *(undefined *)(param_2 + iVar1) = 0;
        return 0;
      }
      *(undefined *)(param_2 + iVar1) = 0x2f;
      iVar1 = iVar1 + 1;
    }
    *(undefined *)(param_2 + iVar1) = 0;
    uVar3 = 1;
  }
  return uVar3;
}


undefined4 DVDGetCurrentDir(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = currentDirectory;
  iVar3 = entryToPath(currentDirectory,param_1,param_2);
  if (iVar3 == param_2) {
    uVar2 = 0;
    *(undefined *)(param_1 + param_2 + -1) = 0;
  }
  else {
    if ((*(uint *)(FstStart + iVar1 * 0xc) & 0xff000000) != 0) {
      if (iVar3 == param_2 + -1) {
        *(undefined *)(param_1 + iVar3) = 0;
        return 0;
      }
      *(undefined *)(param_1 + iVar3) = 0x2f;
      iVar3 = iVar3 + 1;
    }
    *(undefined *)(param_1 + iVar3) = 0;
    uVar2 = 1;
  }
  return uVar2;
}


undefined4 DVDChangeDir(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DVDConvertPathToEntrynum(param_1);
  if ((iVar1 < 0) || ((*(uint *)(FstStart + iVar1 * 0xc) & 0xff000000) == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    currentDirectory = iVar1;
  }
  return uVar2;
}


undefined4
DVDReadAsyncPrio
          (int param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5,
          undefined4 param_6)

{
  if (-1 < (int)param_4) {
    if (param_4 < *(uint *)(param_1 + 0x34)) goto LAB_8030fb2c;
  }
  m_Do_printf::OSPanic(&_118,0x2e6,_239);
LAB_8030fb2c:
  if (((int)(param_4 + param_3) < 0) || (*(int *)(param_1 + 0x34) + 0x20U <= param_4 + param_3)) {
    m_Do_printf::OSPanic(&_118,0x2ec,_239);
  }
  *(undefined4 *)(param_1 + 0x38) = param_5;
  DVDReadAbsAsyncPrio(param_1,param_2,param_3,*(int *)(param_1 + 0x30) + param_4,cbForReadAsync,
                      param_6);
  return 1;
}


void cbForReadAsync(undefined4 param_1,int param_2)

{
  if (*(code **)(param_2 + 0x38) != (code *)0x0) {
    (**(code **)(param_2 + 0x38))();
  }
  return;
}


undefined4
DVDReadPrio(int param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (-1 < (int)param_4) {
    if (param_4 < *(uint *)(param_1 + 0x34)) goto LAB_8030fc18;
  }
  m_Do_printf::OSPanic(&_118,0x32c,_265);
LAB_8030fc18:
  if (((int)(param_4 + param_3) < 0) || (*(int *)(param_1 + 0x34) + 0x20U <= param_4 + param_3)) {
    m_Do_printf::OSPanic(&_118,0x332,_265);
  }
  iVar1 = DVDReadAbsAsyncPrio(param_1,param_2,param_3,*(int *)(param_1 + 0x30) + param_4,
                              cbForReadSync,param_5);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar3 = os::OSDisableInterrupts();
    while (iVar1 = *(int *)(param_1 + 0xc), iVar1 != 0) {
      if (iVar1 == -1) {
        uVar2 = 0xffffffff;
        goto LAB_8030fcc4;
      }
      if (iVar1 == 10) {
        uVar2 = 0xfffffffd;
        goto LAB_8030fcc4;
      }
      os::OSSleepThread(&__DVDThreadQueue);
    }
    uVar2 = *(undefined4 *)(param_1 + 0x20);
LAB_8030fcc4:
    os::OSRestoreInterrupts(uVar3);
  }
  return uVar2;
}


void cbForReadSync(void)

{
  os::OSWakeupThread(&__DVDThreadQueue);
  return;
}


bool DVDOpenDir(char *param_1,int *param_2)

{
  int iVar1;
  bool bVar2;
  undefined auStack136 [128];
  
  iVar1 = DVDConvertPathToEntrynum(param_1);
  if (iVar1 < 0) {
    DVDConvertEntrynumToPath(currentDirectory,auStack136,0x80);
    m_Do_printf::OSReport(_311,param_1,auStack136);
    bVar2 = false;
  }
  else {
    if ((*(uint *)(FstStart + iVar1 * 0xc) & 0xff000000) == 0) {
      bVar2 = false;
    }
    else {
      *param_2 = iVar1;
      bVar2 = true;
      param_2[1] = iVar1 + 1;
      param_2[2] = *(int *)(FstStart + iVar1 * 0xc + 8);
    }
  }
  return bVar2;
}


undefined4 DVDReadDir(uint *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1[1];
  if ((*param_1 < uVar1) && (uVar1 < param_1[2])) {
    *param_2 = uVar1;
    iVar2 = uVar1 * 0xc;
    param_2[1] = (uint)((*(uint *)(FstStart + iVar2) & 0xff000000) != 0);
    param_2[2] = FstStringStart + (*(uint *)(FstStart + iVar2) & 0xffffff);
    if ((*(uint *)(FstStart + iVar2) & 0xff000000) == 0) {
      uVar1 = uVar1 + 1;
    }
    else {
      uVar1 = *(uint *)(FstStart + iVar2 + 8);
    }
    param_1[1] = uVar1;
    return 1;
  }
  return 0;
}


undefined4 DVDCloseDir(void)

{
  return 1;
}


void DVDPrepareStreamAsync(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  if ((*(int *)(param_1 + 0x30) + param_3 & 0x7fff) != 0) {
    m_Do_printf::OSPanic(&_118,0x4a5,_342,*(int *)(param_1 + 0x30),param_3);
  }
  if (param_2 == 0) {
    param_2 = *(int *)(param_1 + 0x34) - param_3;
  }
  if ((param_2 & 0x7fff) != 0) {
    m_Do_printf::OSPanic(&_118,0x4af,_343,param_2);
  }
  if ((*(uint *)(param_1 + 0x34) <= param_3) || (*(uint *)(param_1 + 0x34) < param_3 + param_2)) {
    m_Do_printf::OSPanic(&_118,0x4b7,_344,param_3,param_2);
  }
  *(undefined4 *)(param_1 + 0x38) = param_4;
  DVDPrepareStreamAbsAsync
            (param_1,param_2,*(int *)(param_1 + 0x30) + param_3,cbForPrepareStreamAsync);
  return;
}


void cbForPrepareStreamAsync(undefined4 param_1,int param_2)

{
  if (*(code **)(param_2 + 0x38) != (code *)0x0) {
    (**(code **)(param_2 + 0x38))();
  }
  return;
}

