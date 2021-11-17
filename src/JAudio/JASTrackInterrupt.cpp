#include <JAudio/JASTrackInterrupt.h>
#include <JAudio/JASTrackInterrupt.h>
#include <JASystem/TIntrMgr.h>


namespace JASystem {

/* __thiscall TIntrMgr::init(void) */

int __thiscall TIntrMgr::init(TIntrMgr *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  int iVar2;
  
  *this = (TIntrMgr)0x1;
  this[1] = (TIntrMgr)0x0;
  this[2] = (TIntrMgr)0x0;
  this[3] = (TIntrMgr)0x0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  iVar1 = 0;
  iVar2 = 8;
  do {
    *(undefined4 *)(this + iVar1 + 0xc) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return (int)this;
}


/* __thiscall TIntrMgr::request(unsigned long) */

void __thiscall TIntrMgr::request(TIntrMgr *this,ulong param_1)

{
  if (((uint)(byte)this[2] & 1 << param_1) == 0) {
    return;
  }
  this[1] = (TIntrMgr)((byte)this[1] | (byte)(1 << param_1));
  return;
}


/* __thiscall TIntrMgr::setIntr(unsigned long,
                                          void *) */

void __thiscall TIntrMgr::setIntr(TIntrMgr *this,ulong param_1,void *param_2)

{
  this[2] = (TIntrMgr)((byte)this[2] | (byte)(1 << param_1));
  *(void **)(this + param_1 * 4 + 0xc) = param_2;
  return;
}


/* __thiscall TIntrMgr::resetInter(unsigned long) */

void __thiscall TIntrMgr::resetInter(TIntrMgr *this,ulong param_1)

{
  this[2] = (TIntrMgr)((byte)this[2] & ~(byte)(1 << param_1));
  return;
}


/* __thiscall TIntrMgr::checkIntr(void) */

undefined4 __thiscall TIntrMgr::checkIntr(TIntrMgr *this)

{
  uint uVar1;
  int iVar2;
  
  if (*this == (TIntrMgr)0x0) {
    return 0;
  }
  uVar1 = (uint)((byte)this[2] & (byte)this[1]);
  iVar2 = 0;
  while( true ) {
    if (uVar1 == 0) {
      return 0;
    }
    if ((uVar1 & 1) != 0) break;
    uVar1 = uVar1 >> 1;
    iVar2 = iVar2 + 1;
  }
  this[1] = (TIntrMgr)((byte)this[1] & ~(byte)(1 << iVar2));
  return *(undefined4 *)(this + iVar2 * 4 + 0xc);
}


/* __thiscall TIntrMgr::timerProcess(void) */

void __thiscall TIntrMgr::timerProcess(TIntrMgr *this)

{
  if ((*(int *)(this + 4) != 0) &&
     (*(int *)(this + 4) = *(int *)(this + 4) + -1, *(int *)(this + 4) == 0)) {
    request(this,6);
    if (this[3] == (TIntrMgr)0x0) {
      *(undefined4 *)(this + 4) = *(undefined4 *)(this + 8);
    }
    else {
      this[3] = (TIntrMgr)((char)this[3] + -1);
      if (this[3] != (TIntrMgr)0x0) {
        *(undefined4 *)(this + 4) = *(undefined4 *)(this + 8);
      }
    }
  }
  return;
}

