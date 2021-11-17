#include <JStudio_JStage/object.h>
#include <JStudio_JStage/TAdaptor_object_.h>


namespace JStudio_JStage {

/* __thiscall TAdaptor_object_::adaptor_data_(JStage::TObject *,
                                                              void const *,
                                                              unsigned long,
                                                              void const *,
                                                              unsigned long) */

void __thiscall
TAdaptor_object_::adaptor_data_
          (TAdaptor_object_ *this,TObject *param_1,void *param_2,ulong param_3,void *param_4,
          ulong param_5)

{
  undefined *puVar1;
  
  if (param_2 == (void *)0x0) {
    puVar1 = (undefined *)0xffffffff;
  }
  else {
    puVar1 = param_1->vtbl;
  }
  (**(code **)(*(int *)this + 0x20))(this,puVar1,param_3,param_4);
  return;
}


/* __thiscall TAdaptor_object_::adaptor_ENABLE_(JStage::TObject *,
                                                                JStudio::data::TEOperationData,
                                                                void const *,
                                                                unsigned long) */

void __thiscall
TAdaptor_object_::adaptor_ENABLE_
          (TAdaptor_object_ *this,TObject *param_1,TEOperationData param_2,void *param_3,
          ulong param_4)

{
  uint uVar1;
  
  if (param_1 == (TObject *)&DAT_00000002) {
    if (*(int *)param_2 == 0) {
      uVar1 = (**(code **)(*(int *)this + 0x14))();
      (**(code **)(*(int *)this + 0x18))(this,uVar1 & 0xfffffffd);
    }
    else {
      uVar1 = (**(code **)(*(int *)this + 0x14))();
      (**(code **)(*(int *)this + 0x18))(this,uVar1 | 2);
    }
  }
  return;
}

