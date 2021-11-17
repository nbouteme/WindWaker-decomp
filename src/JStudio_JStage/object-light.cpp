#include <JStudio_JStage/object-light.h>
#include <JStudio_JStage/object-actor.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JStudio/jstudio-object.h>
#include <JKernel/JKRHeap.h>
#include <mtx/mtxvec.h>
#include <MSL_C.PPCEABI.bare.H/w_atan2.h>
#include <mtx/vec.h>
#include <MSL_C.PPCEABI.bare.H/s_cos.h>
#include <MSL_C.PPCEABI.bare.H/s_sin.h>
#include <JStudio_JStage/object.h>
#include <JStudio_JStage/object-light.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JStudio_JStage/TAdaptor_light/TVVOutput_direction_.h>
#include <Demangler/JStudio_JStage/TAdaptor_light.h>


namespace JStudio_JStage {

namespace TAdaptor_light {
undefined1 saoVVOutput_direction_;
}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TAdaptor_light::TAdaptor_light(JStage::TSystem const *,
                                                             JStage::TLight *) */

void __thiscall
TAdaptor_light::TAdaptor_light
          (TAdaptor_light *this,TSystem *param_1,TLight *param_2)

{
  *(undefined1 **)this = &JStudio::TAdaptor::__vt;
  *(TAdaptor_light **)(this + 4) = this + 0xc;
  *(undefined4 *)(this + 8) = 0xd;
  *(undefined1 **)this = &JStudio::TAdaptor_light::__vt;
  Runtime.PPCEABI.H::__construct_array
            (this + 0xc,JStudio::TVariableValue::TVariableValue,(undefined *)0x0,0x14,0xd);
  *(undefined1 **)this = &__vt;
  *(TSystem **)(this + 0x110) = param_1;
  *(TLight **)(this + 0x114) = param_2;
  *(undefined4 *)(this + 0x118) = 0;
  return;
}


/* __thiscall TAdaptor_light::~TAdaptor_light(void) */

void __thiscall TAdaptor_light::_TAdaptor_light(TAdaptor_light *this)

{
  short in_r4;
  
  if (this != (TAdaptor_light *)0x0) {
    *(undefined1 **)this = &__vt;
    (**(code **)(*(int *)this + 0x14))(this,0);
    JStudio::TAdaptor_light::_TAdaptor_light((TAdaptor_light *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TAdaptor_light::adaptor_do_prepare(JStudio::TObject const *) */

void __thiscall
TAdaptor_light::adaptor_do_prepare(TAdaptor_light *this,TObject *param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  for (puVar1 = &saoVVOutput_direction_; *(int *)(puVar1 + 4) != -1; puVar1 = puVar1 + 0xc) {
    puVar2 = puVar1;
    if (puVar1 == (undefined1 *)0x0) {
      puVar2 = &JStudio::TVariableValue::soOutput_none_;
    }
    *(undefined1 **)(*(int *)(this + 4) + *(int *)(puVar1 + 4) * 0x14 + 0x10) = puVar2;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80278594) */
/* WARNING: Removing unreachable block (ram,0x8027858c) */
/* WARNING: Removing unreachable block (ram,0x8027859c) */
/* __thiscall TAdaptor_light::adaptor_do_begin(JStudio::TObject const *) */

void __thiscall
TAdaptor_light::adaptor_do_begin(TAdaptor_light *this,TObject *param_1)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  int *piVar4;
  cXyz *pcVar5;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f29;
  undefined8 in_f30;
  double __y;
  undefined8 in_f31;
  double __x;
  _GXColor local_84;
  cXyz cStack128;
  cXyz cStack116;
  undefined auStack104 [12];
  cXyz cStack92;
  undefined local_50 [20];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  piVar4 = *(int **)(this + 0x114);
  uVar1 = (**(code **)(*piVar4 + 0x14))(piVar4);
  (**(code **)(*piVar4 + 0x18))(piVar4,uVar1 | 1);
  puVar3 = param_1[5].vtbl;
  local_84 = (_GXColor)(**(code **)(**(int **)(this + 0x114) + 0x48))();
  JStudio::TAdaptor::adaptor_setVariableValue_GXColor
            ((TAdaptor *)this,(ulong *)&JStudio::TAdaptor_light::sauVariableValue_4_COLOR_RGBA,
             &local_84);
  (**(code **)(**(int **)(this + 0x114) + 0x40))(*(int **)(this + 0x114),&cStack92);
  (**(code **)(**(int **)(this + 0x114) + 0x60))(*(int **)(this + 0x114),local_50);
  if (puVar3[0x75] == '\0') {
    pcVar5 = &cStack92;
  }
  else {
    mtx::PSMTXMultVec((MTX34 *)(puVar3 + 200),&cStack92,&cStack116);
    mtx::PSMTXMultVecSR(puVar3 + 200,local_50,auStack104);
    pcVar5 = &cStack116;
  }
  JStudio::TAdaptor::adaptor_setVariableValue_Vec
            ((TAdaptor *)this,(ulong *)&JStudio::TAdaptor_light::sauVariableValue_3_POSITION_XYZ,
             (Vec *)pcVar5);
  dVar8 = (double)pcVar5[1].x;
  __y = (double)pcVar5[1].y;
  dVar9 = (double)pcVar5[1].z;
  __x = (double)((float)(dVar8 * dVar8) + (float)(dVar9 * dVar9));
  if ((double)_807 < __x) {
    dVar7 = 1.0 / SQRT(__x);
    dVar7 = _808 * dVar7 * (_809 - __x * dVar7 * dVar7);
    dVar7 = _808 * dVar7 * (_809 - __x * dVar7 * dVar7);
    __x = (double)(float)(__x * _808 * dVar7 * (_809 - __x * dVar7 * dVar7));
  }
  dVar8 = MSL_C.PPCEABI.bare.H::atan2(dVar8,dVar9);
  dVar7 = (double)(float)dVar8;
  dVar8 = MSL_C.PPCEABI.bare.H::atan2(__y,__x);
  iVar2 = *(int *)(this + 4);
  *(code **)(iVar2 + 0xd0) = JStudio::TVariableValue::update_immediate_;
  *(undefined4 *)(iVar2 + 0xcc) = 0;
  dVar9 = (double)_810;
  *(float *)(iVar2 + 0xd4) = (float)(dVar9 * dVar7);
  iVar2 = *(int *)(this + 4);
  *(code **)(iVar2 + 0xe4) = JStudio::TVariableValue::update_immediate_;
  *(undefined4 *)(iVar2 + 0xe0) = 0;
  *(float *)(iVar2 + 0xe8) = (float)(dVar9 * (double)(float)dVar8);
  mtx::PSVECAdd(pcVar5,pcVar5 + 1,&cStack128);
  JStudio::TAdaptor::adaptor_setVariableValue_Vec
            ((TAdaptor *)this,
             (ulong *)&JStudio::TAdaptor_light::sauVariableValue_3_TARGET_POSITION_XYZ,
             (Vec *)&cStack128);
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  __psq_l0(auStack40,uVar6);
  __psq_l1(auStack40,uVar6);
  return;
}


/* __thiscall TAdaptor_light::adaptor_do_end(JStudio::TObject const *) */

void __thiscall
TAdaptor_light::adaptor_do_end(TAdaptor_light *this,TObject *param_1)

{
  uint uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(this + 0x114);
  uVar1 = (**(code **)(*piVar2 + 0x14))(piVar2);
  (**(code **)(*piVar2 + 0x18))(piVar2,uVar1 & 0xfffffffe);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8027879c) */
/* WARNING: Removing unreachable block (ram,0x80278794) */
/* WARNING: Removing unreachable block (ram,0x802787a4) */
/* __thiscall TAdaptor_light::adaptor_do_update(JStudio::TObject const *,
                                                                unsigned long) */

void __thiscall
TAdaptor_light::adaptor_do_update
          (TAdaptor_light *this,TObject *param_1,ulong param_2)

{
  int iVar1;
  undefined *puVar2;
  cXyz *pcVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f29;
  double dVar6;
  undefined8 in_f30;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  _GXColor local_88;
  _GXColor local_84;
  cXyz cStack128;
  cXyz cStack116;
  undefined auStack104 [12];
  cXyz cStack92;
  cXyz local_50 [2];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  puVar2 = param_1[5].vtbl;
  JStudio::TAdaptor::adaptor_getVariableValue_GXColor
            ((TAdaptor *)this,&local_84,
             (ulong *)&JStudio::TAdaptor_light::sauVariableValue_4_COLOR_RGBA);
  local_88 = local_84;
  (**(code **)(**(int **)(this + 0x114) + 0x4c))(*(int **)(this + 0x114),&local_88);
  JStudio::TAdaptor::adaptor_getVariableValue_Vec
            ((TAdaptor *)this,(Vec *)&cStack92,
             (ulong *)&JStudio::TAdaptor_light::sauVariableValue_3_POSITION_XYZ);
  iVar1 = *(int *)(this + 0x118);
  if (iVar1 == 2) {
    JStudio::TAdaptor::adaptor_getVariableValue_Vec
              ((TAdaptor *)this,(Vec *)&cStack128,
               (ulong *)&JStudio::TAdaptor_light::sauVariableValue_3_TARGET_POSITION_XYZ);
    mtx::PSVECSubtract(&cStack128,&cStack92,local_50);
  }
  else {
    if ((iVar1 < 2) && (0 < iVar1)) {
      dVar8 = (double)*(float *)(*(int *)(this + 4) + 200);
      dVar6 = (double)(_857 * *(float *)(*(int *)(this + 4) + 0xdc));
      dVar5 = MSL_C.PPCEABI.bare.H::cos(dVar6);
      dVar7 = (double)(float)dVar5;
      dVar5 = MSL_C.PPCEABI.bare.H::sin(dVar6);
      dVar6 = (double)(float)dVar5;
      dVar8 = (double)(float)((double)_857 * dVar8);
      dVar5 = MSL_C.PPCEABI.bare.H::sin(dVar8);
      local_50[0].x = (float)(dVar7 * (double)(float)dVar5);
      local_50[0].y = (float)dVar6;
      dVar5 = MSL_C.PPCEABI.bare.H::cos(dVar8);
      local_50[0].z = (float)(dVar7 * (double)(float)dVar5);
    }
  }
  if (puVar2[0x74] == '\0') {
    pcVar3 = &cStack92;
  }
  else {
    mtx::PSMTXMultVec((MTX34 *)(puVar2 + 0x98),&cStack92,&cStack116);
    mtx::PSMTXMultVecSR(puVar2 + 0x98,local_50,auStack104);
    pcVar3 = &cStack116;
  }
  (**(code **)(**(int **)(this + 0x114) + 0x44))(*(int **)(this + 0x114),pcVar3);
  (**(code **)(**(int **)(this + 0x114) + 100))(*(int **)(this + 0x114),pcVar3 + 1);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  return;
}


/* __thiscall TAdaptor_light::adaptor_do_data(JStudio::TObject const *,
                                                              void const *,
                                                              unsigned long,
                                                              void const *,
                                                              unsigned long) */

void __thiscall
TAdaptor_light::adaptor_do_data
          (TAdaptor_light *this,TObject *param_1,void *param_2,ulong param_3,void *param_4,
          ulong param_5)

{
  TAdaptor_object_::adaptor_data_
            (*(TAdaptor_object_ **)(this + 0x114),(TObject *)param_2,(void *)param_3,(ulong)param_4,
             (void *)param_5,param_5);
  return;
}


/* __thiscall TAdaptor_light::adaptor_do_FACULTY(JStudio::data::TEOperationData,
                                                                 void const *,
                                                                 unsigned long) */

void __thiscall
TAdaptor_light::adaptor_do_FACULTY
          (TAdaptor_light *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 != 2) {
    return;
  }
                    /* WARNING: Load size is inaccurate */
  iVar1 = *param_2;
  if (iVar1 == 0x302) {
    uVar2 = 2;
  }
  else {
    if (iVar1 < 0x302) {
      if (iVar1 < 0x301) {
        return;
      }
      uVar2 = 1;
    }
    else {
      if (0x303 < iVar1) {
        return;
      }
      uVar2 = 3;
    }
  }
  (**(code **)(**(int **)(this + 0x114) + 0x3c))(*(int **)(this + 0x114),uVar2);
  return;
}


/* __thiscall TAdaptor_light::adaptor_do_ENABLE(JStudio::data::TEOperationData,
                                                                void const *,
                                                                unsigned long) */

void __thiscall
TAdaptor_light::adaptor_do_ENABLE
          (TAdaptor_light *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  ulong in_r7;
  
  TAdaptor_object_::adaptor_ENABLE_
            (*(TAdaptor_object_ **)(this + 0x114),(TObject *)param_1,(TEOperationData)param_2,
             (void *)param_3,in_r7);
  return;
}


namespace TAdaptor_light {

/* __thiscall TVVOutput_direction_::operator ()(float,
                                                                                JStudio::TAdaptor *)
   const */

double __thiscall
TVVOutput_direction_::operator___
          (TVVOutput_direction_ *this,float param_1,TAdaptor *param_2)

{
  *(undefined4 *)(param_2 + 0x118) = *(undefined4 *)(this + 8);
  return (double)param_1;
}


/* __thiscall TVVOutput_direction_::~TVVOutput_direction_(void) */

void __thiscall
TVVOutput_direction_::_TVVOutput_direction_
          (TVVOutput_direction_ *this)

{
  short in_r4;
  
  if (this != (TVVOutput_direction_ *)0x0) {
    *(undefined1 **)this = &__vt;
    JStudio::TVariableValue::TOutput::_TOutput((TOutput *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __sinit_object_light_cpp(void)

{
  undefined1 *local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined1 *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_1c = &TAdaptor_light::TVVOutput_direction_::__vt;
  local_18 = 10;
  local_14 = 1;
  _saoVVOutput_direction_ = &TAdaptor_light::TVVOutput_direction_::__vt;
  DAT_803e8b6c = 10;
  DAT_803e8b70 = 1;
  Runtime.PPCEABI.H::__register_global_object
            (&TAdaptor_light::saoVVOutput_direction_,
             TAdaptor_light::TVVOutput_direction_::_TVVOutput_direction_,&_889);
  local_1c = &TAdaptor_light::TVVOutput_direction_::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_1c);
  local_28 = &TAdaptor_light::TVVOutput_direction_::__vt;
  local_24 = 0xb;
  local_20 = 1;
  DAT_803e8b74 = &TAdaptor_light::TVVOutput_direction_::__vt;
  DAT_803e8b78 = 0xb;
  DAT_803e8b7c = 1;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e8b74,TAdaptor_light::TVVOutput_direction_::_TVVOutput_direction_,&_890);
  local_28 = &TAdaptor_light::TVVOutput_direction_::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_28);
  local_34 = &TAdaptor_light::TVVOutput_direction_::__vt;
  local_30 = 7;
  local_2c = 2;
  DAT_803e8b80 = &TAdaptor_light::TVVOutput_direction_::__vt;
  DAT_803e8b84 = 7;
  DAT_803e8b88 = 2;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e8b80,TAdaptor_light::TVVOutput_direction_::_TVVOutput_direction_,&_891);
  local_34 = &TAdaptor_light::TVVOutput_direction_::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_34);
  local_40 = &TAdaptor_light::TVVOutput_direction_::__vt;
  local_3c = 8;
  local_38 = 2;
  DAT_803e8b8c = &TAdaptor_light::TVVOutput_direction_::__vt;
  DAT_803e8b90 = 8;
  DAT_803e8b94 = 2;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e8b8c,TAdaptor_light::TVVOutput_direction_::_TVVOutput_direction_,&_892);
  local_40 = &TAdaptor_light::TVVOutput_direction_::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_40);
  local_4c = &TAdaptor_light::TVVOutput_direction_::__vt;
  local_48 = 9;
  local_44 = 2;
  DAT_803e8b98 = &TAdaptor_light::TVVOutput_direction_::__vt;
  DAT_803e8b9c = 9;
  DAT_803e8ba0 = 2;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e8b98,TAdaptor_light::TVVOutput_direction_::_TVVOutput_direction_,&_893);
  local_4c = &TAdaptor_light::TVVOutput_direction_::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_4c);
  local_58 = &TAdaptor_light::TVVOutput_direction_::__vt;
  local_54 = 0xffffffff;
  local_50 = 0;
  DAT_803e8ba4 = &TAdaptor_light::TVVOutput_direction_::__vt;
  DAT_803e8ba8 = 0xffffffff;
  DAT_803e8bac = 0;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e8ba4,TAdaptor_light::TVVOutput_direction_::_TVVOutput_direction_,&_894);
  local_58 = &TAdaptor_light::TVVOutput_direction_::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_58);
  return;
}

