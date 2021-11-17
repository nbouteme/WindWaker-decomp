#include <JStudio/fvb.h>
#include <JKernel/JKRHeap.h>
#include <JStudio/fvb-data-parse.h>
#include <JStudio/fvb.h>
#include <JGadget/std-vector.h>
#include <JStudio/functionvalue.h>
#include <JGadget/linklist.h>
#include <JGadget/binary.h>
#include <MSL_C.PPCEABI.bare.H/mem.h>
#include <JStudio/object-id.h>
#include <JStudio/fvb/TObject_list_parameter.h>
#include <Demangler/JStudio/fvb/TControl.h>
#include <std.h>
#include <JStudio/fvb/TObject_composite.h>
#include <Demangler/JStudio/fvb/TParse.h>
#include <Demangler/JStudio/fvb/TFactory.h>
#include <JStudio/fvb/TObject_transition.h>
#include <JStudio/fvb/@unnamed@fvb_cpp@.h>
#include <Demangler/JStudio/fvb/TObject.h>
#include <JStudio/fvb/TObject_list.h>
#include <JStudio/fvb/TObject_hermite.h>
#include <JStudio/fvb/TObject_constant.h>


namespace JStudio {

namespace fvb {

/* __thiscall TObject::~TObject(void) */

void __thiscall TObject::_TObject(TObject *this)

{
  short in_r4;
  
  if ((this != (TObject *)0x0) && (this[2].vtbl = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __thiscall TObject::prepare(data::TParse_TBlock const &,
                                             TControl *) */

void __thiscall
TObject::prepare(TObject *this,TParse_TBlock *param_1,TControl *param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  float fVar6;
  float *pfVar7;
  float fVar8;
  void *local_58;
  void *local_54;
  uint local_50;
  TVector_pointer_void *local_4c;
  TFunctionValueAttribute_range *local_48;
  float *local_44;
  TData aTStack64 [4];
  undefined4 local_3c;
  float *local_38;
  uint local_34;
  
  (**(code **)(*(int *)this[5].vtbl + 0x10))(&local_4c);
  piVar5 = *(int **)param_1;
  iVar2 = *piVar5;
  uVar4 = (int)piVar5 + (*(ushort *)((int)piVar5 + 6) + 3 & 0xfffffffc) + 8;
  do {
    if ((uint)((int)piVar5 + iVar2) <= uVar4) goto switchD_80273a48_caseD_0;
    local_50 = uVar4;
    data::TParse_TParagraph::getData((TParse_TParagraph *)&local_50,aTStack64);
    uVar4 = local_34;
    switch(local_3c) {
    case 0:
switchD_80273a48_caseD_0:
      (**(code **)(*(int *)this[5].vtbl + 0x18))();
      return;
    case 1:
      (**(code **)(this[2].vtbl + 0xc))(this,aTStack64,param_2);
      uVar4 = local_34;
      break;
    case 0x10:
      if (local_4c != (TVector_pointer_void *)0x0) {
        pfVar7 = local_38;
        for (fVar8 = *local_38; uVar4 = local_34, fVar8 != 0.0; fVar8 = (float)((int)fVar8 + -1)) {
          fVar6 = pfVar7[1];
          iVar3 = TControl::getObject(param_2,pfVar7 + 2,(ulong)fVar6);
          if (iVar3 != 0) {
            local_54 = *(void **)(iVar3 + 0x14);
            ::JGadget::TVector_pointer_void::insert(local_4c,*(void ***)(local_4c + 8),&local_54);
          }
          pfVar7 = (float *)(((int)fVar6 + 3U & 0xfffffffc) + (int)(pfVar7 + 1));
        }
      }
      break;
    case 0x11:
      if (local_4c != (TVector_pointer_void *)0x0) {
        pfVar7 = local_38;
        for (fVar8 = *local_38; pfVar7 = pfVar7 + 1, uVar4 = local_34, fVar8 != 0.0;
            fVar8 = (float)((int)fVar8 + -1)) {
          iVar3 = TControl::getObject_index(param_2,(ulong)*pfVar7);
          if (iVar3 != 0) {
            local_58 = *(void **)(iVar3 + 0x14);
            ::JGadget::TVector_pointer_void::insert(local_4c,*(void ***)(local_4c + 8),&local_58);
          }
        }
      }
      break;
    case 0x12:
      if (local_48 != (TFunctionValueAttribute_range *)0x0) {
        TFunctionValueAttribute_range::range_set(local_48,(double)*local_38,(double)local_38[1]);
        uVar4 = local_34;
      }
      break;
    case 0x13:
      if (local_48 != (TFunctionValueAttribute_range *)0x0) {
        local_48[0x18] = SUB41(*local_38,0);
      }
      break;
    case 0x14:
      if (local_48 != (TFunctionValueAttribute_range *)0x0) {
        local_48[0x19] = SUB41(*local_38,0);
      }
      break;
    case 0x15:
      if (local_48 != (TFunctionValueAttribute_range *)0x0) {
        uVar1 = *(ushort *)((int)local_38 + 2);
        *(uint *)(local_48 + 0x30) = (uint)*(ushort *)local_38;
        *(uint *)(local_48 + 0x34) = (uint)uVar1;
      }
      break;
    case 0x16:
      if (local_44 != (float *)0x0) {
        *local_44 = *local_38;
      }
    }
  } while( true );
}


/* __thiscall @unnamed@fvb_cpp@::getCompositeData_raw_(void const *) */

void __thiscall
@unnamed@fvb_cpp@::getCompositeData_raw_(_unnamed_fvb_cpp_ *this,void *param_1)

{
                    /* WARNING: Load size is inaccurate */
  *(undefined4 *)this = *param_1;
  return;
}


/* __thiscall @unnamed@fvb_cpp@::getCompositeData_index_(void const *) */

void __thiscall
@unnamed@fvb_cpp@::getCompositeData_index_(_unnamed_fvb_cpp_ *this,void *param_1)

{
                    /* WARNING: Load size is inaccurate */
  *(undefined4 *)this = *param_1;
  return;
}


/* __thiscall @unnamed@fvb_cpp@::getCompositeData_parameter_(void const *) */

void __thiscall
@unnamed@fvb_cpp@::getCompositeData_parameter_(_unnamed_fvb_cpp_ *this,void *param_1)

{
                    /* WARNING: Load size is inaccurate */
  *(double *)this = (double)*param_1;
  return;
}


/* __thiscall @unnamed@fvb_cpp@::getCompositeData_add_(void const *) */

void __thiscall
@unnamed@fvb_cpp@::getCompositeData_add_(_unnamed_fvb_cpp_ *this,void *param_1)

{
                    /* WARNING: Load size is inaccurate */
  *(double *)this = (double)*param_1;
  return;
}


/* __thiscall @unnamed@fvb_cpp@::getCompositeData_subtract_(void const *) */

void __thiscall
@unnamed@fvb_cpp@::getCompositeData_subtract_(_unnamed_fvb_cpp_ *this,void *param_1)

{
                    /* WARNING: Load size is inaccurate */
  *(double *)this = (double)*param_1;
  return;
}


/* __thiscall @unnamed@fvb_cpp@::getCompositeData_multiply_(void const *) */

void __thiscall
@unnamed@fvb_cpp@::getCompositeData_multiply_(_unnamed_fvb_cpp_ *this,void *param_1)

{
                    /* WARNING: Load size is inaccurate */
  *(double *)this = (double)*param_1;
  return;
}


/* __thiscall @unnamed@fvb_cpp@::getCompositeData_divide_(void const *) */

void __thiscall
@unnamed@fvb_cpp@::getCompositeData_divide_(_unnamed_fvb_cpp_ *this,void *param_1)

{
                    /* WARNING: Load size is inaccurate */
  *(double *)this = (double)*param_1;
  return;
}


/* __thiscall
   @unnamed@fvb_cpp@::getCompositeOperation_(data::TEComposite) */

undefined1 * __thiscall
@unnamed@fvb_cpp@::getCompositeOperation_(_unnamed_fvb_cpp_ *this,TEComposite param_1)

{
  return &saCompositeOperation_ + (int)this * 8;
}


/* __thiscall TObject_composite::TObject_composite(data::TParse_TBlock
   const &) */

void __thiscall
TObject_composite::TObject_composite(TObject_composite *this,TParse_TBlock *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)*(ushort *)(*(int *)param_1 + 6);
  iVar2 = 0;
  if (uVar1 != 0) {
    iVar2 = *(int *)param_1 + 8;
  }
  *(int *)this = iVar2;
  *(uint *)(this + 4) = uVar1;
  *(undefined1 **)(this + 8) = &TObject::__vt;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(TFunctionValue_composite **)(this + 0x14) = (TFunctionValue_composite *)(this + 0x18);
  *(undefined1 **)(this + 8) = &__vt;
  TFunctionValue_composite::TFunctionValue_composite((TFunctionValue_composite *)(this + 0x18));
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall
   TObject_composite::prepare_data_(data::TParse_TParagraph::TData const
   &,
                                                             TControl *) */

void __thiscall
TObject_composite::prepare_data_
          (TObject_composite *this,TData *param_1,TControl *param_2)

{
  undefined4 *puVar1;
  _unnamed_fvb_cpp_ **pp_Var2;
  undefined8 local_18;
  
  pp_Var2 = *(_unnamed_fvb_cpp_ ***)(param_1 + 8);
  puVar1 = (undefined4 *)@unnamed@fvb_cpp@::getCompositeOperation_(*pp_Var2,(TEComposite)param_1);
  (*(code *)puVar1[1])(&local_18,pp_Var2 + 1);
  *(undefined4 *)(this + 0x30) = *puVar1;
  *(undefined8 *)(this + 0x38) = local_18;
  return;
}


/* __thiscall TObject_constant::TObject_constant(data::TParse_TBlock
   const &) */

void __thiscall
TObject_constant::TObject_constant(TObject_constant *this,TParse_TBlock *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)*(ushort *)(*(int *)param_1 + 6);
  iVar2 = 0;
  if (uVar1 != 0) {
    iVar2 = *(int *)param_1 + 8;
  }
  *(int *)this = iVar2;
  *(uint *)(this + 4) = uVar1;
  *(undefined1 **)(this + 8) = &TObject::__vt;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(TFunctionValue_constant **)(this + 0x14) = (TFunctionValue_constant *)(this + 0x18);
  *(undefined1 **)(this + 8) = &__vt;
  TFunctionValue_constant::TFunctionValue_constant((TFunctionValue_constant *)(this + 0x18));
  return;
}


/* __thiscall
   TObject_constant::prepare_data_(data::TParse_TParagraph::TData const
   &,
                                                            TControl *) */

void __thiscall
TObject_constant::prepare_data_
          (TObject_constant *this,TData *param_1,TControl *param_2)

{
  *(double *)(this + 0x20) = (double)**(float **)(param_1 + 8);
  return;
}


/* __thiscall TObject_transition::TObject_transition(data::TParse_TBlock
   const &) */

void __thiscall
TObject_transition::TObject_transition
          (TObject_transition *this,TParse_TBlock *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)*(ushort *)(*(int *)param_1 + 6);
  iVar2 = 0;
  if (uVar1 != 0) {
    iVar2 = *(int *)param_1 + 8;
  }
  *(int *)this = iVar2;
  *(uint *)(this + 4) = uVar1;
  *(undefined1 **)(this + 8) = &TObject::__vt;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(TFunctionValue_transition **)(this + 0x14) = (TFunctionValue_transition *)(this + 0x18);
  *(undefined1 **)(this + 8) = &__vt;
  TFunctionValue_transition::TFunctionValue_transition((TFunctionValue_transition *)(this + 0x18));
  return;
}


/* __thiscall
   TObject_transition::prepare_data_(data::TParse_TParagraph::TData
   const &,
                                                              TControl *) */

void __thiscall
TObject_transition::prepare_data_
          (TObject_transition *this,TData *param_1,TControl *param_2)

{
  float fVar1;
  
  fVar1 = (*(float **)(param_1 + 8))[1];
  *(double *)(this + 0x60) = (double)**(float **)(param_1 + 8);
  *(double *)(this + 0x68) = (double)fVar1;
  return;
}


/* __thiscall TObject_list::TObject_list(data::TParse_TBlock const &) */

void __thiscall TObject_list::TObject_list(TObject_list *this,TParse_TBlock *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)*(ushort *)(*(int *)param_1 + 6);
  iVar2 = 0;
  if (uVar1 != 0) {
    iVar2 = *(int *)param_1 + 8;
  }
  *(int *)this = iVar2;
  *(uint *)(this + 4) = uVar1;
  *(undefined1 **)(this + 8) = &TObject::__vt;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(TFunctionValue_list **)(this + 0x14) = (TFunctionValue_list *)(this + 0x18);
  *(undefined1 **)(this + 8) = &__vt;
  TFunctionValue_list::TFunctionValue_list((TFunctionValue_list *)(this + 0x18));
  return;
}


/* __thiscall TObject_list::prepare_data_(data::TParse_TParagraph::TData
   const &,
                                                        TControl *) */

void __thiscall
TObject_list::prepare_data_(TObject_list *this,TData *param_1,TControl *param_2)

{
  float fVar1;
  float *pfVar2;
  
  pfVar2 = *(float **)(param_1 + 8);
  *(double *)(this + 0x68) = (double)*pfVar2;
  fVar1 = pfVar2[1];
  *(float **)(this + 0x5c) = pfVar2 + 2;
  *(float *)(this + 0x60) = fVar1;
  return;
}


/* __thiscall
   TObject_list_parameter::TObject_list_parameter(data::TParse_TBlock
   const &) */

void __thiscall
TObject_list_parameter::TObject_list_parameter
          (TObject_list_parameter *this,TParse_TBlock *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)*(ushort *)(*(int *)param_1 + 6);
  iVar2 = 0;
  if (uVar1 != 0) {
    iVar2 = *(int *)param_1 + 8;
  }
  *(int *)this = iVar2;
  *(uint *)(this + 4) = uVar1;
  *(undefined1 **)(this + 8) = &TObject::__vt;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(TFunctionValue_list_parameter **)(this + 0x14) = (TFunctionValue_list_parameter *)(this + 0x18);
  *(undefined1 **)(this + 8) = &__vt;
  TFunctionValue_list_parameter::TFunctionValue_list_parameter
            ((TFunctionValue_list_parameter *)(this + 0x18));
  return;
}


/* __thiscall
   TObject_list_parameter::prepare_data_(data::TParse_TParagraph::TData
   const &,
                                                                  TControl *) */

void __thiscall
TObject_list_parameter::prepare_data_
          (TObject_list_parameter *this,TData *param_1,TControl *param_2)

{
  TFunctionValue_list_parameter::data_set
            ((TFunctionValue_list_parameter *)(this + 0x18),(float *)(*(ulong **)(param_1 + 8) + 1),
             **(ulong **)(param_1 + 8));
  return;
}


/* __thiscall TObject_hermite::TObject_hermite(data::TParse_TBlock const
   &) */

void __thiscall
TObject_hermite::TObject_hermite(TObject_hermite *this,TParse_TBlock *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)*(ushort *)(*(int *)param_1 + 6);
  iVar2 = 0;
  if (uVar1 != 0) {
    iVar2 = *(int *)param_1 + 8;
  }
  *(int *)this = iVar2;
  *(uint *)(this + 4) = uVar1;
  *(undefined1 **)(this + 8) = &TObject::__vt;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(TFunctionValue_hermite **)(this + 0x14) = (TFunctionValue_hermite *)(this + 0x18);
  *(undefined1 **)(this + 8) = &__vt;
  TFunctionValue_hermite::TFunctionValue_hermite((TFunctionValue_hermite *)(this + 0x18));
  return;
}


/* __thiscall
   TObject_hermite::prepare_data_(data::TParse_TParagraph::TData const
   &,
                                                           TControl *) */

void __thiscall
TObject_hermite::prepare_data_(TObject_hermite *this,TData *param_1,TControl *param_2)

{
  uint uVar1;
  
  uVar1 = **(uint **)(param_1 + 8);
  TFunctionValue_hermite::data_set
            ((TFunctionValue_hermite *)(this + 0x18),(float *)(*(uint **)(param_1 + 8) + 1),
             uVar1 & 0xfffffff,uVar1 >> 0x1c);
  return;
}


/* __thiscall TControl::TControl(void) */

void __thiscall TControl::TControl(TControl *this)

{
  *(undefined1 **)this = &__vt;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(TControl **)(this + 0xc) = this + 0xc;
  *(TControl **)(this + 0x10) = this + 0xc;
  return;
}


/* __thiscall TControl::~TControl(void) */

void __thiscall TControl::_TControl(TControl *this)

{
  short in_r4;
  
  if (this != (TControl *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (TControl *)&DAT_fffffff8) {
      ::JGadget::TNodeLinkList::_TNodeLinkList((TNodeLinkList *)(this + 8));
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TControl::appendObject(TObject *) */

void __thiscall TControl::appendObject(TControl *this,TObject *param_1)

{
  TNodeLinkList aTStack16 [4];
  TControl *local_c;
  TControl *local_8;
  TControl *local_4;
  
  local_c = this + 0xc;
  local_8 = local_c;
  local_4 = local_c;
  ::JGadget::TNodeLinkList::Insert(aTStack16,(iterator)(this + 8),(TLinkListNode *)&local_c);
  return;
}


/* __thiscall TControl::removeObject(TObject *) */

void __thiscall TControl::removeObject(TControl *this,TObject *param_1)

{
  TNodeLinkList aTStack8 [8];
  
  ::JGadget::TNodeLinkList::Erase(aTStack8,(TLinkListNode *)(this + 8));
  return;
}


/* __thiscall TControl::destroyObject(TObject *) */

void __thiscall TControl::destroyObject(TControl *this,TObject *param_1)

{
  removeObject(this,param_1);
  (**(code **)(**(int **)(this + 4) + 0x10))(*(int **)(this + 4),param_1);
  return;
}


/* __thiscall TControl::destroyObject_all(void) */

void __thiscall TControl::destroyObject_all(TControl *this)

{
  while (*(int *)(this + 8) != 0) {
    destroyObject(this,(TObject *)(*(int *)(this + 0x10) + -0xc));
  }
  return;
}


/* __thiscall TControl::getObject(void const *,
                                                unsigned long) */

int __thiscall TControl::getObject(TControl *this,void *param_1,ulong param_2)

{
  uint uVar1;
  TControl *local_28;
  undefined4 local_24;
  int local_20 [2];
  TControl *local_18;
  undefined4 local_14;
  void *local_10;
  ulong local_c;
  
  local_24 = *(undefined4 *)(this + 0xc);
  local_28 = this + 0xc;
  local_18 = local_28;
  local_14 = local_24;
  local_10 = param_1;
  local_c = param_2;
  ::std::find_if((std *)local_20,(iterator)&local_24,(iterator)&local_28,
                 (TPRObject_ID_equal)&local_10);
  uVar1 = countLeadingZeros((int)local_18 - local_20[0]);
  uVar1 = countLeadingZeros(uVar1 >> 5 & 0xff);
  if ((uVar1 >> 5 & 0xff) == 0) {
    local_20[0] = 0;
  }
  else {
    local_20[0] = local_20[0] + -0xc;
  }
  return local_20[0];
}


/* __thiscall TControl::getObject_index(unsigned long) */

undefined4 * __thiscall TControl::getObject_index(TControl *this,ulong param_1)

{
  undefined4 *puVar1;
  
  if (param_1 < *(uint *)(this + 8)) {
    puVar1 = *(undefined4 **)(this + 0xc);
    if (param_1 != 0) {
      do {
        puVar1 = (undefined4 *)*puVar1;
        param_1 = param_1 - 1;
      } while (param_1 != 0);
    }
    puVar1 = puVar1 + -3;
  }
  else {
    puVar1 = (undefined4 *)0x0;
  }
  return puVar1;
}


/* __thiscall TFactory::~TFactory(void) */

void __thiscall TFactory::_TFactory(TFactory *this)

{
  short in_r4;
  
  if ((this != (TFactory *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall TFactory::create(data::TParse_TBlock const &) */

TObject_composite * __thiscall TFactory::create(TFactory *this,TParse_TBlock *param_1)

{
  ushort uVar1;
  TObject_composite *this_00;
  TObject_constant *this_01;
  TObject_transition *this_02;
  TObject_list *this_03;
  TObject_list_parameter *this_04;
  TObject_hermite *this_05;
  
  uVar1 = *(ushort *)(*(int *)param_1 + 4);
  if (uVar1 == 4) {
    this_03 = (TObject_list *)JKernel::operator_new(0x78);
    if (this_03 == (TObject_list *)0x0) {
      return (TObject_composite *)0x0;
    }
    TObject_list::TObject_list(this_03,param_1);
    return (TObject_composite *)this_03;
  }
  if (uVar1 < 4) {
    if (uVar1 == 2) {
      this_01 = (TObject_constant *)JKernel::operator_new(0x28);
      if (this_01 == (TObject_constant *)0x0) {
        return (TObject_composite *)0x0;
      }
      TObject_constant::TObject_constant(this_01,param_1);
      return (TObject_composite *)this_01;
    }
    if (1 < uVar1) {
      this_02 = (TObject_transition *)JKernel::operator_new(0x70);
      if (this_02 == (TObject_transition *)0x0) {
        return (TObject_composite *)0x0;
      }
      TObject_transition::TObject_transition(this_02,param_1);
      return (TObject_composite *)this_02;
    }
    if (uVar1 != 0) {
      this_00 = (TObject_composite *)JKernel::operator_new(0x40);
      if (this_00 == (TObject_composite *)0x0) {
        return (TObject_composite *)0x0;
      }
      TObject_composite::TObject_composite(this_00,param_1);
      return this_00;
    }
  }
  else {
    if (uVar1 == 6) {
      this_05 = (TObject_hermite *)JKernel::operator_new(0x80);
      if (this_05 == (TObject_hermite *)0x0) {
        return (TObject_composite *)0x0;
      }
      TObject_hermite::TObject_hermite(this_05,param_1);
      return (TObject_composite *)this_05;
    }
    if (uVar1 < 6) {
      this_04 = (TObject_list_parameter *)JKernel::operator_new(0x78);
      if (this_04 == (TObject_list_parameter *)0x0) {
        return (TObject_composite *)0x0;
      }
      TObject_list_parameter::TObject_list_parameter(this_04,param_1);
      return (TObject_composite *)this_04;
    }
  }
  return (TObject_composite *)0x0;
}


/* __thiscall TFactory::destroy(TObject *) */

TFactory * __thiscall TFactory::destroy(TFactory *this,TObject *param_1)

{
  if (param_1 != (TObject *)0x0) {
    this = (TFactory *)(**(code **)(param_1[2].vtbl + 8))(param_1,1);
  }
  return this;
}


/* __thiscall TParse::TParse(TControl *) */

void __thiscall TParse::TParse(TParse *this,TControl *param_1)

{
  this->vtbl = &::JGadget::binary::TParse_header_block::__vt;
  this->vtbl = &__vt;
  this->mpControl = param_1;
  return;
}


/* __thiscall TParse::~TParse(void) */

void __thiscall TParse::_TParse(TParse *this)

{
  short in_r4;
  
  if (this != (TParse *)0x0) {
    this->vtbl = &__vt;
    ::JGadget::binary::TParse_header_block::_TParse_header_block((TParse_header_block *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TParse::parseHeader_next(void const * *,
                                                     unsigned long *,
                                                     unsigned long) */

int __thiscall
TParse::parseHeader_next(TParse *this,void **param_1,ulong *param_2,ulong param_3)

{
  int iVar1;
  void *__s1;
  
  __s1 = *param_1;
  *param_1 = (void *)((int)__s1 + 0x10);
  *param_2 = *(ulong *)((int)__s1 + 0xc);
  iVar1 = MSL_C.PPCEABI.bare.H::memcmp(__s1,&data::ga4cSignature,4);
  if (iVar1 == 0) {
    if (*(short *)((int)__s1 + 4) == -0x101) {
      if (*(ushort *)((int)__s1 + 6) < 2) {
        iVar1 = 0;
      }
      else {
        iVar1 = -((0x100 < *(ushort *)((int)__s1 + 6)) - 1);
      }
    }
    else {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TParse::parseBlock_next(void const * *,
                                                    unsigned long *,
                                                    unsigned long) */

uint __thiscall
TParse::parseBlock_next(TParse *this,void **param_1,ulong *param_2,ulong param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  TObject *this_00;
  ulong *puVar4;
  TControl *this_01;
  ulong *local_18 [3];
  
  local_18[0] = (ulong *)*param_1;
  *param_1 = (void *)((int)local_18[0] + *local_18[0]);
  *param_2 = *local_18[0];
  this_01 = this->mpControl;
  if ((param_3 & 0x10) != 0) {
    puVar4 = (ulong *)0x0;
    if (*(ushort *)((int)local_18[0] + 6) != 0) {
      puVar4 = local_18[0] + 2;
    }
    iVar1 = TControl::getObject(this_01,puVar4,(uint)*(ushort *)((int)local_18[0] + 6));
    if (iVar1 != 0) {
      return 1;
    }
  }
  if ((param_3 & 0x20) == 0) {
    piVar3 = *(int **)(this_01 + 4);
    if (piVar3 == (int *)0x0) {
      uVar2 = 0;
    }
    else {
      this_00 = (TObject *)(**(code **)(*piVar3 + 0xc))(piVar3,local_18);
      if (this_00 == (TObject *)0x0) {
        uVar2 = param_3 >> 6 & 1;
      }
      else {
        TObject::prepare(this_00,(TParse_TBlock *)local_18,this_01);
        TControl::appendObject(this_01,this_00);
        uVar2 = 1;
      }
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


/* __thiscall TObject_hermite::~TObject_hermite(void) */

void __thiscall TObject_hermite::_TObject_hermite(TObject_hermite *this)

{
  short in_r4;
  
  if (this != (TObject_hermite *)0x0) {
    *(undefined1 **)(this + 8) = &__vt;
    if (this != (TObject_hermite *)0xffffffe8) {
      *(undefined1 **)(this + 0x18) = &TFunctionValue_hermite::__vt;
      TFunctionValue::_TFunctionValue((TFunctionValue *)(this + 0x18));
    }
    TObject::_TObject((TObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TObject_list_parameter::~TObject_list_parameter(void) */

void __thiscall
TObject_list_parameter::_TObject_list_parameter(TObject_list_parameter *this)

{
  short in_r4;
  
  if (this != (TObject_list_parameter *)0x0) {
    *(undefined1 **)(this + 8) = &__vt;
    if (this != (TObject_list_parameter *)0xffffffe8) {
      *(undefined1 **)(this + 0x18) = &TFunctionValue_list_parameter::__vt;
      TFunctionValue::_TFunctionValue((TFunctionValue *)(this + 0x18));
    }
    TObject::_TObject((TObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TObject_list::~TObject_list(void) */

void __thiscall TObject_list::_TObject_list(TObject_list *this)

{
  short in_r4;
  
  if (this != (TObject_list *)0x0) {
    *(undefined1 **)(this + 8) = &__vt;
    if (this != (TObject_list *)0xffffffe8) {
      *(undefined1 **)(this + 0x18) = &TFunctionValue_list::__vt;
      TFunctionValue::_TFunctionValue((TFunctionValue *)(this + 0x18));
    }
    TObject::_TObject((TObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TObject_transition::~TObject_transition(void) */

void __thiscall TObject_transition::_TObject_transition(TObject_transition *this)

{
  short in_r4;
  
  if (this != (TObject_transition *)0x0) {
    *(undefined1 **)(this + 8) = &__vt;
    if (this != (TObject_transition *)0xffffffe8) {
      *(undefined1 **)(this + 0x18) = &TFunctionValue_transition::__vt;
      TFunctionValue::_TFunctionValue((TFunctionValue *)(this + 0x18));
    }
    TObject::_TObject((TObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TObject_constant::~TObject_constant(void) */

void __thiscall TObject_constant::_TObject_constant(TObject_constant *this)

{
  short in_r4;
  
  if (this != (TObject_constant *)0x0) {
    *(undefined1 **)(this + 8) = &__vt;
    if (this != (TObject_constant *)0xffffffe8) {
      *(undefined1 **)(this + 0x18) = &TFunctionValue_constant::__vt;
      TFunctionValue::_TFunctionValue((TFunctionValue *)(this + 0x18));
    }
    TObject::_TObject((TObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TObject_composite::~TObject_composite(void) */

void __thiscall TObject_composite::_TObject_composite(TObject_composite *this)

{
  short in_r4;
  
  if (this != (TObject_composite *)0x0) {
    *(undefined1 **)(this + 8) = &__vt;
    if (this != (TObject_composite *)0xffffffe8) {
      *(undefined1 **)(this + 0x18) = &TFunctionValue_composite::__vt;
      if ((this != (TObject_composite *)0xffffffe4) && (this != (TObject_composite *)0xffffffe4)) {
        ::JGadget::TVector_pointer_void::_TVector_pointer_void
                  ((TVector_pointer_void *)(this + 0x1c));
      }
      TFunctionValue::_TFunctionValue((TFunctionValue *)(this + 0x18));
    }
    TObject::_TObject((TObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

}
}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall
   std::find_if<JGadget::TLinkList<Q37JStudio3fvb7TObject,-12>::iterator,JStudio::object::TPRObject_ID_equal>(JGadget::TLinkList<Q37JStudio3fvb7TObject,-12>::iterator,
   
   JGadget::TLinkList<Q37JStudio3fvb7TObject,-12>::iterator,
   
   JStudio::object::TPRObject_ID_equal) */

void __thiscall std::find_if(std *this,iterator param_1,iterator param_2,TPRObject_ID_equal param_3)

{
  uint uVar1;
  char cVar2;
  TIDData *pTVar3;
  
  pTVar3 = (TIDData *)param_2;
  while( true ) {
    uVar1 = countLeadingZeros(*(int *)param_2 - *(int *)param_1);
    if ((uVar1 >> 5 & 0xff) != 0) break;
    cVar2 = JStudio::object::TIDData::isEqual
                      ((TIDData *)(*(int *)param_1 + -0xc),(TIDData *)param_3,pTVar3);
    if (cVar2 != '\0') break;
    *(undefined4 *)param_1 = **(undefined4 **)param_1;
  }
  *(undefined4 *)this = *(undefined4 *)param_1;
  return;
}

