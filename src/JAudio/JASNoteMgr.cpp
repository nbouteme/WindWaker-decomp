#include <JAudio/JASNoteMgr.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JASystem/TTrack/TNoteMgr.h>


namespace JASystem {

namespace TTrack {

/* __thiscall TNoteMgr::init(void) */

int __thiscall TNoteMgr::init(TNoteMgr *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(undefined4 *)(this + 0x30) = 0;
  this[0x34] = (TNoteMgr)0x0;
  this[0x35] = (TNoteMgr)0x0;
  this[0x36] = (TNoteMgr)0x0;
  iVar1 = 0;
  iVar2 = 0;
  iVar3 = 8;
  do {
    *(undefined4 *)(this + iVar2) = 0;
    *(undefined2 *)(this + iVar1 + 0x20) = 0;
    iVar1 = iVar1 + 2;
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return (int)this;
}


/* __thiscall TNoteMgr::endProcess(void) */

void __thiscall TNoteMgr::endProcess(TNoteMgr *this)

{
  if (*(int *)(this + 0x30) == -1) {
    return;
  }
  if (this[0x34] != (TNoteMgr)0x0) {
    return;
  }
  *(undefined4 *)this = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TNoteMgr::setChannel(int,
                                                     JASystem::TChannel *) */

void __thiscall TNoteMgr::setChannel(TNoteMgr *this,int param_1,TChannel *param_2)

{
  ulong uVar1;
  
  if (param_1 < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASNoteMgr.cpp",0x2c,"index >= 0");
    m_Do_printf::OSPanic("JASNoteMgr.cpp",0x2c,&DAT_80367432);
  }
  if (7 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASNoteMgr.cpp",0x2d,"index < MULTI_MAX");
    m_Do_printf::OSPanic("JASNoteMgr.cpp",0x2d,&DAT_80367432);
  }
  *(TChannel **)(this + param_1 * 4) = param_2;
  *(undefined2 *)(this + param_1 * 2 + 0x20) = *(undefined2 *)(param_2 + 200);
  return;
}


/* __thiscall TNoteMgr::releaseChannel(int) */

void __thiscall TNoteMgr::releaseChannel(TNoteMgr *this,int param_1)

{
  ulong uVar1;
  
  if (param_1 < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASNoteMgr.cpp",0x35,"index >= 0");
    m_Do_printf::OSPanic("JASNoteMgr.cpp",0x35,&DAT_80367432);
  }
  if (7 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASNoteMgr.cpp",0x36,"index < MULTI_MAX");
    m_Do_printf::OSPanic("JASNoteMgr.cpp",0x36,&DAT_80367432);
  }
  *(undefined4 *)(this + param_1 * 4) = 0;
  return;
}


/* __thiscall TNoteMgr::getChannel(int) */

int __thiscall TNoteMgr::getChannel(TNoteMgr *this,int param_1)

{
  ulong uVar1;
  int iVar2;
  
  if (param_1 < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASNoteMgr.cpp",0x3d,"index >= 0");
    m_Do_printf::OSPanic("JASNoteMgr.cpp",0x3d,&DAT_80367432);
  }
  if (param_1 < 8) {
    iVar2 = *(int *)(this + param_1 * 4);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      if (*(short *)(this + param_1 * 2 + 0x20) != *(short *)(iVar2 + 200)) {
        *(undefined4 *)(this + param_1 * 4) = 0;
        iVar2 = 0;
      }
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}

