#include <JStudioToolLibrary/console.h>
#include <JSupport/JSUInputStream.h>
#include <JKernel/JKRHeap.h>
#include <JSUMemoryInputStream.h>
#include <JSUIosBase.h>
#include <Demangler/JSURandomInputStream.h>


/* __thiscall JSUMemoryInputStream::~JSUMemoryInputStream(void) */

void __thiscall JSUMemoryInputStream::_JSUMemoryInputStream(JSUMemoryInputStream *this)

{
  short in_r4;
  
  if (this != (JSUMemoryInputStream *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JSUMemoryInputStream *)0x0) {
      *(undefined1 **)this = &JSURandomInputStream::__vt;
      JSUInputStream::_JSUInputStream((JSUInputStream *)this);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JSURandomInputStream::~JSURandomInputStream(void) */

void __thiscall JSURandomInputStream::_JSURandomInputStream(JSURandomInputStream *this)

{
  short in_r4;
  
  if (this != (JSURandomInputStream *)0x0) {
    *(undefined1 **)this = &__vt;
    JSUInputStream::_JSUInputStream((JSUInputStream *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JSUIosBase::~JSUIosBase(void) */

void __thiscall JSUIosBase::_JSUIosBase(JSUIosBase *this)

{
  short in_r4;
  
  if ((this != (JSUIosBase *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

