#include <JStudio_JMessage/object-message.h>
#include <JStudio/jstudio-object.h>
#include <JKernel/JKRHeap.h>
#include <JMessage/control.h>
#include <Demangler/JStudio_JMessage/TAdaptor_message.h>


namespace JStudio_JMessage {

/* __thiscall TAdaptor_message::TAdaptor_message(JMessage::TControl *) */

void __thiscall
TAdaptor_message::TAdaptor_message(TAdaptor_message *this,TControl *param_1)

{
  *(undefined1 **)this = &JStudio::TAdaptor::__vt;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined1 **)this = &JStudio::TAdaptor_message::__vt;
  *(undefined1 **)this = &__vt;
  *(TControl **)(this + 0xc) = param_1;
  return;
}


/* __thiscall TAdaptor_message::~TAdaptor_message(void) */

void __thiscall TAdaptor_message::_TAdaptor_message(TAdaptor_message *this)

{
  short in_r4;
  
  if (this != (TAdaptor_message *)0x0) {
    *(undefined1 **)this = &__vt;
    JStudio::TAdaptor_message::_TAdaptor_message((TAdaptor_message *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TAdaptor_message::adaptor_do_MESSAGE(JStudio::data::TEOperationData,
                                                                     void const *,
                                                                     unsigned long) */

void __thiscall
TAdaptor_message::adaptor_do_MESSAGE
          (TAdaptor_message *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  TControl *this_00;
  undefined4 uVar1;
  
  if (param_1 == 0x19) {
                    /* WARNING: Load size is inaccurate */
    uVar1 = *param_2;
    this_00 = *(TControl **)(this + 0xc);
    *(short *)(this_00 + 0x14) = (short)((uint)uVar1 >> 0x10);
    *(short *)(this_00 + 0x16) = (short)uVar1;
    JMessage::TControl::setMessageCode_flush_(this_00);
  }
  return;
}

