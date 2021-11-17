#include <JSupport/JSUInputStream.h>
#include <m_Do_printf.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JSupport/JSUInputStream.h>
#include <JSUInputStream.h>
#include <Demangler/JSURandomInputStream.h>


/* __thiscall JSUInputStream::~JSUInputStream(void) */

void __thiscall JSUInputStream::_JSUInputStream(JSUInputStream *this)

{
  short in_r4;
  
  if (this != (JSUInputStream *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this[4] != (JSUInputStream)0x0) {
      m_Do_printf::OSReport("JSUInputStream: occur error.\n");
    }
    if (this != (JSUInputStream *)0x0) {
      *(undefined1 **)this = &JSUIosBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JSUInputStream::read(void *,
                                   long) */

ssize_t __thiscall JSUInputStream::read(JSUInputStream *this,void *__buf,size_t __nbytes)

{
  size_t sVar1;
  
  sVar1 = (**(code **)(*(int *)this + 0x14))();
  if (sVar1 != __nbytes) {
    this[4] = (JSUInputStream)((byte)this[4] | 1);
  }
  return sVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JSUInputStream::skip(long) */

int __thiscall JSUInputStream::skip(JSUInputStream *this,long param_1)

{
  int iVar1;
  int iVar2;
  undefined auStack24 [12];
  
  iVar2 = 0;
  while( true ) {
    if (param_1 <= iVar2) {
      return iVar2;
    }
    iVar1 = (**(code **)(*(int *)this + 0x14))(this,auStack24,1);
    if (iVar1 != 1) break;
    iVar2 = iVar2 + 1;
  }
  this[4] = (JSUInputStream)((byte)this[4] | 1);
  return iVar2;
}


/* __thiscall JSURandomInputStream::align(long) */

int __thiscall JSURandomInputStream::align(JSURandomInputStream *this,long param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = (**(code **)(*(int *)this + 0x1c))();
  uVar3 = (param_1 + iVar1) - 1U & ~(param_1 - 1U);
  iVar1 = uVar3 - iVar1;
  if ((iVar1 != 0) && (iVar2 = (**(code **)(*(int *)this + 0x20))(this,uVar3,0), iVar2 != iVar1)) {
    this[4] = (JSURandomInputStream)((byte)this[4] | 1);
  }
  return iVar1;
}


/* __thiscall JSURandomInputStream::skip(long) */

void __thiscall JSURandomInputStream::skip(JSURandomInputStream *this,long param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)this + 0x20))(this,param_1,1);
  if (iVar1 != param_1) {
    this[4] = (JSURandomInputStream)((byte)this[4] | 1);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JSURandomInputStream::peek(void *,
                                         long) */

ssize_t __thiscall JSURandomInputStream::peek(JSURandomInputStream *this,void *param_1,long param_2)

{
  undefined4 uVar1;
  ssize_t sVar2;
  
  uVar1 = (**(code **)(*(int *)this + 0x1c))();
  sVar2 = JSUInputStream::read((JSUInputStream *)this,param_1,param_2);
  if (sVar2 != 0) {
    (**(code **)(*(int *)this + 0x20))(this,uVar1,0);
  }
  return sVar2;
}


/* __thiscall JSURandomInputStream::seek(long,
                                         JSUStreamSeekFrom) */

void __thiscall
JSURandomInputStream::seek(JSURandomInputStream *this,long param_1,JSUStreamSeekFrom param_2)

{
  (**(code **)(*(int *)this + 0x20))();
  this[4] = (JSURandomInputStream)((byte)this[4] & 0xfe);
  return;
}

