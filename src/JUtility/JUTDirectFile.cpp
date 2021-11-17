#include <JUtility/JUTDirectFile.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <os/OSInterrupt.h>
#include <dvd/dvdfs.h>
#include <dvd/dvd.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTDirectFile.h>
#include <JUTDirectFile.h>


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JUTDirectFile::fetch32byte(void) */

undefined4 __thiscall JUTDirectFile::fetch32byte(JUTDirectFile *this)

{
  undefined4 uVar1;
  int iVar2;
  
  *(uint *)(this + 0x824) = *(int *)(this + 0x828) - (*(uint *)(this + 0x82c) & 0xffffffe0);
  if (0x800 < *(uint *)(this + 0x824)) {
    *(undefined4 *)(this + 0x824) = 0x800;
  }
  uVar1 = os::OSEnableInterrupts();
  iVar2 = dvd::DVDReadAsyncPrio
                    (this + 0x834,*(undefined4 *)(this + 0x820),
                     *(int *)(this + 0x824) + 0x1fU & 0xffffffe0,
                     *(uint *)(this + 0x82c) & 0xffffffe0,0,2);
  os::OSRestoreInterrupts(uVar1);
  if (iVar2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = os::OSEnableInterrupts();
    do {
      iVar2 = dvd::DVDGetCommandBlockStatus(this + 0x834);
    } while (iVar2 != 0);
    os::OSRestoreInterrupts(uVar1);
    uVar1 = *(undefined4 *)(this + 0x824);
  }
  return uVar1;
}


/* __thiscall JUTDirectFile::JUTDirectFile(void) */

void __thiscall JUTDirectFile::JUTDirectFile(JUTDirectFile *this)

{
  *(undefined4 *)(this + 0x828) = 0;
  *(undefined4 *)(this + 0x82c) = 0;
  *(undefined4 *)(this + 0x824) = 0;
  *(uint *)(this + 0x820) = (uint)(this + 0x1f) & 0xffffffe0;
  this[0x830] = (JUTDirectFile)0x0;
  return;
}


/* __thiscall JUTDirectFile::~JUTDirectFile(void) */

void __thiscall JUTDirectFile::_JUTDirectFile(JUTDirectFile *this)

{
  short in_r4;
  
  if ((this != (JUTDirectFile *)0x0) && (this[0x830] = (JUTDirectFile)0x0, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JUTDirectFile::fopen(char const *) */

FILE * __thiscall JUTDirectFile::fopen(JUTDirectFile *this,char *__filename,char *__modes)

{
  FILE *pFVar1;
  undefined4 uVar2;
  bool bVar3;
  
  if (__filename == (char *)0x0) {
    pFVar1 = (FILE *)0x0;
  }
  else {
    uVar2 = os::OSEnableInterrupts();
    bVar3 = dvd::DVDOpen(__filename,(int)(this + 0x834));
    os::OSRestoreInterrupts(uVar2);
    if (bVar3 == false) {
      this[0x830] = (JUTDirectFile)0x0;
      pFVar1 = (FILE *)0x0;
    }
    else {
      os::OSEnableInterrupts();
      *(undefined4 *)(this + 0x828) = *(undefined4 *)(this + 0x868);
      os::OSRestoreInterrupts();
      *(undefined4 *)(this + 0x82c) = 0;
      this[0x830] = (JUTDirectFile)0x1;
      pFVar1 = (FILE *)&DAT_00000001;
    }
  }
  return pFVar1;
}


/* __thiscall JUTDirectFile::fclose(void) */

int __thiscall JUTDirectFile::fclose(JUTDirectFile *this,FILE *__stream)

{
  undefined4 uVar1;
  JUTDirectFile *pJVar2;
  
  pJVar2 = this;
  if (this[0x830] != (JUTDirectFile)0x0) {
    uVar1 = os::OSEnableInterrupts();
    dvd::DVDClose(this + 0x834);
    pJVar2 = (JUTDirectFile *)os::OSRestoreInterrupts(uVar1);
    this[0x830] = (JUTDirectFile)0x0;
  }
  return (int)pJVar2;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JUTDirectFile::fgets(void *,
                                   int) */

char * __thiscall JUTDirectFile::fgets(JUTDirectFile *this,char *__s,int __n,FILE *__stream)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  if (this[0x830] == (JUTDirectFile)0x0) {
    pcVar3 = &DAT_ffffffff;
  }
  else {
    if (__n == 0) {
      pcVar3 = (char *)0x0;
    }
    else {
      if (__n == 1) {
        pcVar3 = &DAT_00000001;
      }
      else {
        if (__s == (char *)0x0) {
          pcVar3 = &DAT_ffffffff;
        }
        else {
          if (*(uint *)(this + 0x82c) < *(uint *)(this + 0x828)) {
            pcVar3 = (char *)0x0;
            do {
              if (*(uint *)(this + 0x828) <= *(uint *)(this + 0x82c)) goto LAB_802cbe7c;
              if ((*(int *)(this + 0x824) == 0) && (iVar4 = fetch32byte(this), iVar4 < 0)) {
                return &DAT_ffffffff;
              }
              uVar5 = *(uint *)(this + 0x82c) & 0x7ff;
              iVar4 = *(int *)(this + 0x824) - uVar5;
              if ((char *)(__n + -1) < pcVar3 + iVar4) {
                iVar4 = (__n - (int)pcVar3) + -1;
              }
              bVar2 = false;
              iVar6 = 0;
              for (iVar7 = iVar4; iVar7 != 0; iVar7 = iVar7 + -1) {
                cVar1 = *(char *)(*(int *)(this + 0x820) + uVar5);
                *__s = cVar1;
                uVar5 = uVar5 + 1;
                __s = __s + 1;
                if (cVar1 == '\n') {
                  bVar2 = true;
                  iVar4 = iVar6 + 1;
                  break;
                }
                iVar6 = iVar6 + 1;
              }
              if (0x7ff < uVar5) {
                *(undefined4 *)(this + 0x824) = 0;
              }
              if (bVar2) {
                *__s = '\0';
                *(int *)(this + 0x82c) = *(int *)(this + 0x82c) + iVar4;
                pcVar3 = pcVar3 + iVar4;
                goto LAB_802cbe7c;
              }
              *(int *)(this + 0x82c) = *(int *)(this + 0x82c) + iVar4;
              pcVar3 = pcVar3 + iVar4;
            } while ((int)pcVar3 < (int)(char *)(__n + -1));
            *__s = '\0';
LAB_802cbe7c:
            if (*(uint *)(this + 0x828) <= *(uint *)(this + 0x82c)) {
              *__s = '\0';
            }
          }
          else {
            pcVar3 = &DAT_ffffffff;
          }
        }
      }
    }
  }
  return pcVar3;
}

