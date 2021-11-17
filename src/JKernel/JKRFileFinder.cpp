#include <JKernel/JKRFileFinder.h>
#include <JKernel/JKRArchivePub.h>
#include <dvd/dvdfs.h>
#include <JKernel/JKRHeap.h>
#include <JKRDvdFinder.h>
#include <JKRArcFinder.h>


/* __thiscall JKRArcFinder::JKRArcFinder(JKRArchive *,
                                         long,
                                         long) */

void __thiscall
JKRArcFinder::JKRArcFinder(JKRArcFinder *this,JKRArchive *param_1,long param_2,long param_3)

{
  *(char **)(this + 0xc) = d_resorce::l_readResType_4166 + 0x74;
  this[0x10] = (JKRArcFinder)0x0;
  this[0x11] = (JKRArcFinder)0x0;
  *(undefined1 **)(this + 0xc) = &__vt;
  *(JKRArchive **)(this + 0x14) = param_1;
  this[0x10] = (JKRArcFinder)
               ((byte)((byte)((uint)-param_3 >> 0x18) & ~(byte)((uint)param_3 >> 0x18)) >> 7);
  *(long *)(this + 0x18) = param_2;
  *(long *)(this + 0x1c) = param_2 + param_3 + -1;
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(this + 0x18);
  (**(code **)(*(int *)(this + 0xc) + 0xc))();
  return;
}


/* __thiscall JKRArcFinder::findNextFile(void) */

JKRArcFinder __thiscall JKRArcFinder::findNextFile(JKRArcFinder *this)

{
  JKRArcFinder JVar1;
  SDirEntry local_18 [2];
  undefined2 local_16;
  undefined4 local_14;
  
  if (this[0x10] != (JKRArcFinder)0x0) {
    this[0x10] = (JKRArcFinder)
                 ((char)((int)*(uint *)(this + 0x1c) >> 0x1f) +
                 ((*(uint *)(this + 0x20) <= *(uint *)(this + 0x1c)) -
                 (char)((int)*(uint *)(this + 0x20) >> 0x1f)));
    if (this[0x10] != (JKRArcFinder)0x0) {
      JVar1 = (JKRArcFinder)
              JKRArchive::getDirEntry
                        (*(JKRArchive **)(this + 0x14),local_18,*(ulong *)(this + 0x20));
      this[0x10] = JVar1;
      *(undefined4 *)this = local_14;
      *(undefined4 *)(this + 4) = *(undefined4 *)(this + 0x20);
      *(undefined2 *)(this + 8) = local_16;
      *(ushort *)(this + 10) = (ushort)(byte)local_18[0];
      this[0x11] = (JKRArcFinder)((byte)(*(ushort *)(this + 10) >> 1) & 1);
      *(int *)(this + 0x20) = *(int *)(this + 0x20) + 1;
    }
  }
  return this[0x10];
}


/* __thiscall JKRDvdFinder::JKRDvdFinder(char const *) */

void __thiscall JKRDvdFinder::JKRDvdFinder(JKRDvdFinder *this,char *param_1)

{
  bool bVar1;
  
  *(char **)(this + 0xc) = d_resorce::l_readResType_4166 + 0x74;
  this[0x10] = (JKRDvdFinder)0x0;
  this[0x11] = (JKRDvdFinder)0x0;
  *(undefined1 **)(this + 0xc) = &__vt;
  bVar1 = dvd::DVDOpenDir(param_1,(int *)(this + 0x14));
  this[0x20] = (JKRDvdFinder)('\x01' - (bVar1 == false));
  this[0x10] = this[0x20];
  (**(code **)(*(int *)(this + 0xc) + 0xc))(this);
  return;
}


/* __thiscall JKRDvdFinder::~JKRDvdFinder(void) */

void __thiscall JKRDvdFinder::_JKRDvdFinder(JKRDvdFinder *this)

{
  short in_r4;
  
  if (this != (JKRDvdFinder *)0x0) {
    *(undefined1 **)(this + 0xc) = &__vt;
    if (this[0x20] != (JKRDvdFinder)0x0) {
      dvd::DVDCloseDir(this + 0x14);
    }
    if (this != (JKRDvdFinder *)0x0) {
      *(char **)(this + 0xc) = d_resorce::l_readResType_4166 + 0x74;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JKRDvdFinder::findNextFile(void) */

JKRDvdFinder __thiscall JKRDvdFinder::findNextFile(JKRDvdFinder *this)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  
  if (this[0x10] != (JKRDvdFinder)0x0) {
    iVar2 = dvd::DVDReadDir(this + 0x14,&local_18);
    this[0x10] = (JKRDvdFinder)('\x01' - (iVar2 == 0));
    if (this[0x10] != (JKRDvdFinder)0x0) {
      this[0x11] = (JKRDvdFinder)('\x01' - (local_14 == 0));
      *(undefined4 *)this = local_10;
      *(undefined4 *)(this + 4) = local_18;
      *(undefined2 *)(this + 8) = 0;
      uVar1 = 1;
      if (this[0x11] != (JKRDvdFinder)0x0) {
        uVar1 = 2;
      }
      *(undefined2 *)(this + 10) = uVar1;
    }
  }
  return this[0x10];
}


/* __thiscall JKRArcFinder::~JKRArcFinder(void) */

void __thiscall JKRArcFinder::_JKRArcFinder(JKRArcFinder *this)

{
  short in_r4;
  
  if (this != (JKRArcFinder *)0x0) {
    *(undefined1 **)(this + 0xc) = &__vt;
    if (this != (JKRArcFinder *)0x0) {
      *(char **)(this + 0xc) = d_resorce::l_readResType_4166 + 0x74;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

