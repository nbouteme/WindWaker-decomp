#include <JKernel/JKRFile.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <vi/vi.h>
#include <JKRFile.h>


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRFile::read(void *,
                            long,
                            long) */

ssize_t __thiscall JKRFile::read(JKRFile *this,int __fd,void *__buf,size_t __nbytes)

{
  ulong uVar1;
  void *pvVar2;
  
  if (((uint)__buf & 0x1f) != 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRFile.cpp",0x22,"( length & 0x1f ) == 0");
    m_Do_printf::OSPanic("JKRFile.cpp",0x22,&DAT_8036bc03);
  }
  while (pvVar2 = (void *)(**(code **)(*(int *)this + 0x14))(this,__fd,__buf,__nbytes),
        __buf != pvVar2) {
    vi::VIWaitForRetrace();
  }
  return (ssize_t)pvVar2;
}

