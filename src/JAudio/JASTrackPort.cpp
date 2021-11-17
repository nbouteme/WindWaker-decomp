#include <JAudio/JASTrackPort.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JASystem/TTrackPort.h>


namespace JASystem {

/* __thiscall TTrackPort::init(void) */

int __thiscall TTrackPort::init(TTrackPort *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar1 = 0;
  iVar3 = 0x10;
  do {
    this[iVar2] = (TTrackPort)0x0;
    (this + iVar2)[0x10] = (TTrackPort)0x0;
    *(undefined2 *)(this + iVar1 + 0x20) = 0;
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return (int)this;
}


/* __thiscall TTrackPort::readImport(int) */

undefined2 __thiscall TTrackPort::readImport(TTrackPort *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && ((uint)param_1 < 0x10)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASTrackPort.cpp",0x1f,"port_num >= 0 && port_num < MAX_PORTS");
    m_Do_printf::OSPanic("JASTrackPort.cpp",0x1f,&DAT_80367adf);
  }
  this[param_1] = (TTrackPort)0x0;
  return *(undefined2 *)(this + param_1 * 2 + 0x20);
}


/* __thiscall TTrackPort::readExport(int) */

undefined2 __thiscall TTrackPort::readExport(TTrackPort *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && ((uint)param_1 < 0x10)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASTrackPort.cpp",0x26,"port_num >= 0 && port_num < MAX_PORTS");
    m_Do_printf::OSPanic("JASTrackPort.cpp",0x26,&DAT_80367adf);
  }
  this[param_1 + 0x10] = (TTrackPort)0x0;
  return *(undefined2 *)(this + param_1 * 2 + 0x20);
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TTrackPort::writeImport(int,
                                                unsigned short) */

void __thiscall TTrackPort::writeImport(TTrackPort *this,int param_1,ushort param_2)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && ((uint)param_1 < 0x10)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASTrackPort.cpp",0x2d,"port_num >= 0 && port_num < MAX_PORTS");
    m_Do_printf::OSPanic("JASTrackPort.cpp",0x2d,&DAT_80367adf);
  }
  this[param_1] = (TTrackPort)0x1;
  *(ushort *)(this + param_1 * 2 + 0x20) = param_2;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TTrackPort::writeExport(int,
                                                unsigned short) */

void __thiscall TTrackPort::writeExport(TTrackPort *this,int param_1,ushort param_2)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && ((uint)param_1 < 0x10)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASTrackPort.cpp",0x33,"port_num >= 0 && port_num < MAX_PORTS");
    m_Do_printf::OSPanic("JASTrackPort.cpp",0x33,&DAT_80367adf);
  }
  this[param_1 + 0x10] = (TTrackPort)0x1;
  *(ushort *)(this + param_1 * 2 + 0x20) = param_2;
  return;
}

