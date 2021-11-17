#include <JAudio/JASWaveArcLoader.h>
#include <JAudio/JASSystemHeap.h>
#include <JAudio/JASHeapCtrl.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <os/OSMutex.h>
#include <JKernel/JKRDvdAramRipper.h>
#include <JAudio/JASWaveArcLoader.h>
#include <JAudio/JASDvdThread.h>
#include <dvd/dvdfs.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <JSupport/JSUList.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JASystem/WaveArcLoader.h>
#include <JASystem/Kernel/THeap.h>
#include <JASystem/TWaveArc.h>


namespace JASystem {
undefined1 WaveArcLoader;

/* __thiscall WaveArcLoader::init(void) */

int __thiscall WaveArcLoader::init(WaveArcLoader *this,EVP_PKEY_CTX *ctx)

{
  void *pvVar1;
  ulong local_8 [2];
  
  pvVar1 = (void *)Kernel::allocFromSysAramFull((Kernel *)local_8,(ulong *)ctx);
  if (pvVar1 != (void *)0x0) {
    Kernel::THeap::initRootHeap((THeap *)&sAramHeap,pvVar1,local_8[0],0);
  }
  return (uint)(pvVar1 != (void *)0x0);
}


/* __thiscall WaveArcLoader::getRootHeap(void) */

undefined1 * __thiscall WaveArcLoader::getRootHeap(WaveArcLoader *this)

{
  return &sAramHeap;
}


/* __thiscall WaveArcLoader::setCurrentDir(char const *) */

void __thiscall WaveArcLoader::setCurrentDir(WaveArcLoader *this,char *param_1)

{
  size_t sVar1;
  ulong uVar2;
  
  sVar1 = MSL_C.PPCEABI.bare.H::strlen((char *)this);
  if (0x3f < sVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASWaveArcLoader.cpp",0x3c,"std::strlen(dir) < DIR_MAX");
    m_Do_printf::OSPanic("JASWaveArcLoader.cpp",0x3c,&DAT_80367e60);
  }
  MSL_C.PPCEABI.bare.H::strcpy(&sCurrentDir,(char *)this);
  sVar1 = MSL_C.PPCEABI.bare.H::strlen(&sCurrentDir);
  if ((&DAT_80398b5f)[sVar1] != '/') {
    if (0x3f < sVar1 + 1) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"JASWaveArcLoader.cpp",0x41,"len+1 < DIR_MAX");
      m_Do_printf::OSPanic("JASWaveArcLoader.cpp",0x41,&DAT_80367e60);
    }
    (&sCurrentDir)[sVar1] = 0x2f;
    s_Banks__80398b61[sVar1] = '\0';
  }
  return;
}


/* __thiscall WaveArcLoader::getCurrentDir(void) */

undefined1 * __thiscall WaveArcLoader::getCurrentDir(WaveArcLoader *this)

{
  return &sCurrentDir;
}


/* __thiscall TWaveArc::TWaveArc(void) */

void __thiscall TWaveArc::TWaveArc(TWaveArc *this)

{
  *(undefined1 **)this = &Kernel::TDisposer::__vt;
  *(undefined1 **)this = &__vt;
  Kernel::THeap::THeap((THeap *)(this + 4),(TDisposer *)this);
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x6c) = 0xffffffff;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  os::OSInitMutex((OSMutex *)(this + 0x50));
  return;
}


/* __thiscall TWaveArc::loadSetup(unsigned long) */

undefined4 __thiscall TWaveArc::loadSetup(TWaveArc *this,ulong param_1)

{
  undefined4 uVar1;
  
  os::OSLockMutex((OSMutex *)(this + 0x50));
  if (*(ulong *)(this + 0x74) == param_1) {
    if (*(int *)(this + 0x68) == 1) {
      *(undefined4 *)(this + 0x4c) = 1;
      *(undefined4 *)(this + 0x68) = 2;
      os::OSUnlockMutex(this + 0x50);
      uVar1 = 1;
    }
    else {
      os::OSUnlockMutex(this + 0x50);
      uVar1 = 0;
    }
  }
  else {
    os::OSUnlockMutex(this + 0x50);
    uVar1 = 0;
  }
  return uVar1;
}


/* __thiscall TWaveArc::eraseSetup(void) */

undefined4 __thiscall TWaveArc::eraseSetup(TWaveArc *this)

{
  undefined4 uVar1;
  
  os::OSLockMutex((OSMutex *)(this + 0x50));
  if (*(int *)(this + 0x68) == 0) {
    os::OSUnlockMutex(this + 0x50);
    uVar1 = 0;
  }
  else {
    if (*(int *)(this + 0x68) == 1) {
      *(undefined4 *)(this + 0x68) = 0;
      os::OSUnlockMutex(this + 0x50);
      uVar1 = 0;
    }
    else {
      *(undefined4 *)(this + 0x4c) = 0;
      *(undefined4 *)(this + 0x68) = 0;
      os::OSUnlockMutex(this + 0x50);
      uVar1 = 1;
    }
  }
  return uVar1;
}


/* __thiscall TWaveArc::loadToAramCallback(void *) */

undefined4 __thiscall TWaveArc::loadToAramCallback(TWaveArc *this,void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  ulong in_r8;
  int *this_00;
  
  iVar1 = JKRDvdAramRipper::loadToAram
                    (*(JKRDvdAramRipper **)(this + 4),*(long *)(this + 8),0,0,0,in_r8);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    this_00 = *(int **)this;
    cVar3 = loadSetup((TWaveArc *)this_00,*(ulong *)(this + 0xc));
    if (cVar3 == '\0') {
      uVar2 = 0;
    }
    else {
      (**(code **)(*this_00 + 0xc))(this_00);
      uVar2 = 0;
    }
  }
  return uVar2;
}


/* __thiscall TWaveArc::sendLoadCmd(void) */

bool __thiscall TWaveArc::sendLoadCmd(TWaveArc *this)

{
  bool bVar1;
  ulong in_r6;
  undefined8 uVar2;
  TWaveArc *local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  os::OSLockMutex((OSMutex *)(this + 0x50));
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x68) = 1;
  local_14 = *(undefined4 *)(this + 0x6c);
  local_10 = *(undefined4 *)(this + 0x40);
  local_c = *(int *)(this + 0x74) + 1;
  *(int *)(this + 0x74) = local_c;
  local_18 = this;
  os::OSUnlockMutex(this + 0x50);
  uVar2 = Dvd::sendCmdMsg((Dvd *)loadToAramCallback,(FuncDef568 *)&local_18,&DAT_00000010,in_r6);
  bVar1 = (int)((ulonglong)uVar2 >> 0x20) != 0;
  if (!bVar1) {
    Kernel::THeap::free((THeap *)(this + 4),(void *)uVar2);
  }
  return bVar1;
}


/* __thiscall TWaveArc::load(Kernel::THeap *) */

undefined4 __thiscall TWaveArc::load(TWaveArc *this,THeap *param_1)

{
  undefined4 uVar1;
  WaveArcLoader *this_00;
  char cVar2;
  
  if (*(int *)(this + 0x6c) < 0) {
    uVar1 = 0;
  }
  else {
    this_00 = (WaveArcLoader *)os::OSLockMutex((OSMutex *)(this + 0x50));
    if (*(int *)(this + 0x68) == 0) {
      if (param_1 == (THeap *)0x0) {
        param_1 = (THeap *)WaveArcLoader::getRootHeap(this_00);
      }
      cVar2 = Kernel::THeap::alloc((THeap *)(this + 4),param_1,*(ulong *)(this + 0x70));
      if (cVar2 == '\0') {
        os::OSUnlockMutex(this + 0x50);
        uVar1 = 0;
      }
      else {
        uVar1 = sendLoadCmd(this);
        os::OSUnlockMutex(this + 0x50);
      }
    }
    else {
      os::OSUnlockMutex(this + 0x50);
      uVar1 = 0;
    }
  }
  return uVar1;
}


/* __thiscall TWaveArc::erase(void) */

void __thiscall TWaveArc::erase(TWaveArc *this)

{
  void *in_r4;
  
  Kernel::THeap::free((THeap *)(this + 4),in_r4);
  return;
}


/* __thiscall TWaveArc::onDispose(void) */

void __thiscall TWaveArc::onDispose(TWaveArc *this)

{
  char cVar1;
  
  cVar1 = eraseSetup(this);
  if (cVar1 != '\0') {
    (**(code **)(*(int *)this + 0x10))(this);
  }
  return;
}


/* __thiscall TWaveArc::setEntryNum(long) */

void __thiscall TWaveArc::setEntryNum(TWaveArc *this,long param_1)

{
  int iVar1;
  undefined auStack72 [52];
  undefined4 local_14;
  
  if ((-1 < param_1) && (iVar1 = dvd::DVDFastOpen(param_1,auStack72), iVar1 != 0)) {
    *(undefined4 *)(this + 0x70) = local_14;
    dvd::DVDClose(auStack72);
    *(long *)(this + 0x6c) = param_1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall TWaveArc::setFileName(char const *) */

void __thiscall TWaveArc::setFileName(TWaveArc *this,char *param_1)

{
  char *__s;
  size_t sVar1;
  size_t sVar2;
  char *__dest;
  int iVar3;
  
  __s = (char *)WaveArcLoader::getCurrentDir((WaveArcLoader *)this);
  sVar1 = MSL_C.PPCEABI.bare.H::strlen(__s);
  sVar2 = MSL_C.PPCEABI.bare.H::strlen(param_1);
  __dest = (char *)JKernel::operator_new__(sVar1 + sVar2 + 1,JKRHeap::sSystemHeap,0xfffffffc);
  MSL_C.PPCEABI.bare.H::strcpy(__dest,__s);
  MSL_C.PPCEABI.bare.H::strcat(__dest,param_1);
  __dest[sVar1 + sVar2] = '\0';
  iVar3 = dvd::DVDConvertPathToEntrynum(__dest);
  JKernel::operator_delete__(__dest);
  if (-1 < iVar3) {
    setEntryNum(this,iVar3);
  }
  return;
}


namespace Kernel {

/* __thiscall THeap::~THeap(void) */

void __thiscall THeap::_THeap(THeap *this)

{
  short in_r4;
  
  if (this != (THeap *)0x0) {
    if (this != (THeap *)0x0) {
      if (this != (THeap *)0xfffffff4) {
        JSUPtrLink::_JSUPtrLink((JSUPtrLink *)(this + 0xc));
      }
      if (this != (THeap *)0x0) {
        JSUPtrList::_JSUPtrList((JSUPtrList *)this);
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

}

void __sinit_JASWaveArcLoader_cpp(void)

{
  ::JASystem::Kernel::THeap::THeap((THeap *)&::JASystem::WaveArcLoader::sAramHeap,(TDisposer *)0x0);
  Runtime.PPCEABI.H::__register_global_object();
  return;
}

