#include <JStudio_JAudio/object-sound.h>
#include <JStudio_JStage/object-actor.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JAudio/JAISound.h>
#include <JStudio/jstudio-object.h>
#include <JKernel/JKRHeap.h>
#include <mtx/mtxvec.h>
#include <JAudio/JAIBasic.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <JStudio_JAudio/object-sound.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JStudio_JAudio/TAdaptor_sound/TVVOOn_END_FADE_OUT_.h>
#include <JStudio_JAudio/TAdaptor_sound/TVVOSetValue_.h>
#include <JAISound.h>
#include <Demangler/JStudio_JAudio/TAdaptor_sound.h>
#include <JStudio_JAudio/TAdaptor_sound/TVVOOn_BEGIN_FADE_IN_.h>


namespace JStudio_JAudio {
undefined4 aoData$1089;

namespace TAdaptor_sound {
undefined1 saoVVOSetValue_;
}
undefined1 init$1090;

namespace TAdaptor_sound {
undefined1 soVVOOn_BEGIN_FADE_IN_;
undefined1 soVVOOn_END_FADE_OUT_;
}

/* __thiscall TAdaptor_sound::TAdaptor_sound(JAIBasic *) */

void __thiscall
TAdaptor_sound::TAdaptor_sound(TAdaptor_sound *this,JAIBasic *param_1)

{
  *(undefined1 **)this = &JStudio::TAdaptor::__vt;
  *(TAdaptor_sound **)(this + 4) = this + 0xc;
  *(undefined4 *)(this + 8) = 0xb;
  *(undefined1 **)this = &JStudio::TAdaptor_sound::__vt;
  Runtime.PPCEABI.H::__construct_array
            (this + 0xc,JStudio::TVariableValue::TVariableValue,(undefined *)0x0,0x14,0xb);
  *(undefined1 **)this = &__vt;
  *(JAIBasic **)(this + 0xe8) = param_1;
  *(undefined4 *)(this + 0xec) = 0;
  *(undefined4 *)(this + 0xf0) = 0xffffffff;
  *(undefined4 *)(this + 0xf4) = 0;
  return;
}


/* __thiscall TAdaptor_sound::~TAdaptor_sound(void) */

void __thiscall TAdaptor_sound::_TAdaptor_sound(TAdaptor_sound *this)

{
  short in_r4;
  
  if (this != (TAdaptor_sound *)0x0) {
    *(undefined1 **)this = &__vt;
    if (*(JAISound **)(this + 0xec) != (JAISound *)0x0) {
      ::JAISound::stop(*(JAISound **)(this + 0xec),0);
    }
    JStudio::TAdaptor_sound::_TAdaptor_sound((TAdaptor_sound *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TAdaptor_sound::adaptor_do_prepare(JStudio::TObject const *) */

void __thiscall
TAdaptor_sound::adaptor_do_prepare(TAdaptor_sound *this,TObject *param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  if (init_1090 == '\0') {
    aoData_1089 = 0;
    DAT_803e8bb4 = _1147;
    DAT_803e8bb8 = 1;
    DAT_803e8bbc = _1147;
    DAT_803e8bc0 = 2;
    DAT_803e8bc4 = _1147;
    DAT_803e8bc8 = 0xffffffff;
    DAT_803e8bcc = MSL_C.PPCEABI.bare.H::__float_nan;
    init_1090 = '\x01';
  }
  JStudio::TAdaptor::adaptor_setVariableValue_immediate
            ((TAdaptor *)this,(TSetVariableValue_immediate *)&aoData_1089);
  *(undefined1 **)(*(int *)(this + 4) + 0x4c) = &soVVOOn_BEGIN_FADE_IN_;
  *(undefined1 **)(*(int *)(this + 4) + 0x60) = &soVVOOn_END_FADE_OUT_;
  for (puVar1 = &saoVVOSetValue_; *(int *)(puVar1 + 4) != -1; puVar1 = puVar1 + 0x14) {
    puVar2 = puVar1;
    if (puVar1 == (undefined1 *)0x0) {
      puVar2 = &JStudio::TVariableValue::soOutput_none_;
    }
    *(undefined1 **)(*(int *)(this + 4) + *(int *)(puVar1 + 4) * 0x14 + 0x10) = puVar2;
  }
  return;
}


/* __thiscall TAdaptor_sound::adaptor_do_update(JStudio::TObject const *,
                                                                unsigned long) */

void __thiscall
TAdaptor_sound::adaptor_do_update
          (TAdaptor_sound *this,TObject *param_1,ulong param_2)

{
  cXyz *pSrc;
  undefined *puVar1;
  cXyz local_18;
  
  puVar1 = param_1[5].vtbl;
  pSrc = (cXyz *)(this + 0xf8);
  JStudio::TAdaptor::adaptor_getVariableValue_Vec
            ((TAdaptor *)this,(Vec *)pSrc,
             (ulong *)&JStudio::TAdaptor_sound::sauVariableValue_3_POSITION_XYZ);
  if (puVar1[0x74] != '\0') {
    mtx::PSMTXMultVec((MTX34 *)(puVar1 + 0x98),pSrc,&local_18);
    pSrc->x = local_18.x;
    *(float *)(this + 0xfc) = local_18.y;
    *(float *)(this + 0x100) = local_18.z;
  }
  return;
}


/* __thiscall TAdaptor_sound::adaptor_do_SOUND(JStudio::data::TEOperationData,
                                                               void const *,
                                                               unsigned long) */

void __thiscall
TAdaptor_sound::adaptor_do_SOUND
          (TAdaptor_sound *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  JAISoundInfoID JVar1;
  
  if (param_1 == 0x19) {
                    /* WARNING: Load size is inaccurate */
    JVar1 = *param_2;
    if ((JVar1 & 0xc0000000) == 0) {
      *(JAISoundInfoID *)(this + 0xf0) = JVar1;
    }
    else {
      if (*(JAISound **)(this + 0xec) != (JAISound *)0x0) {
        ::JAISound::stop(*(JAISound **)(this + 0xec),0);
      }
      *(JAISoundInfoID *)(this + 0xf0) = JVar1;
      JAIBasic::startSoundVec
                (*(JAIBasic **)(this + 0xe8),JVar1,(JAISound **)(this + 0xec),*(Vec **)(this + 0xf4)
                 ,0,0,'\x04');
      if (*(JAISound **)(this + 0xec) != (JAISound *)0x0) {
        ::JAISound::setPrepareFlag(*(JAISound **)(this + 0xec),'\x01');
      }
    }
  }
  return;
}


/* __thiscall TAdaptor_sound::adaptor_do_LOCATED(JStudio::data::TEOperationData,
                                                                 void const *,
                                                                 unsigned long) */

void __thiscall
TAdaptor_sound::adaptor_do_LOCATED
          (TAdaptor_sound *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  int iVar1;
  
  if (param_1 != 2) {
    return;
  }
                    /* WARNING: Load size is inaccurate */
  iVar1 = *param_2;
  *(undefined4 *)(this + 0xf4) = 0;
  if (iVar1 == 0) {
    return;
  }
  *(TAdaptor_sound **)(this + 0xf4) = this + 0xf8;
  return;
}


namespace TAdaptor_sound {

/* __thiscall TVVOOn_BEGIN_FADE_IN_::operator ()(float,
                                                                                 JStudio::TAdaptor
   *) const */

void __thiscall
TVVOOn_BEGIN_FADE_IN_::operator___
          (TVVOOn_BEGIN_FADE_IN_ *this,float param_1,TAdaptor *param_2)

{
  ulong uVar1;
  JAISoundInfoID JVar2;
  JAISound *this_00;
  double dVar3;
  
  dVar3 = (double)param_1;
  JVar2 = *(JAISoundInfoID *)(param_2 + 0xf0);
  if ((JVar2 & 0xc0000000) == 0) {
    if ((*(JAISound **)(param_2 + 0xec) != (JAISound *)0x0) && ((JVar2 & 0xc00) != 0)) {
      ::JAISound::stop(*(JAISound **)(param_2 + 0xec),0);
    }
    uVar1 = Runtime.PPCEABI.H::__cvt_fp2unsigned(dVar3);
    JAIBasic::startSoundVec
              (*(JAIBasic **)(param_2 + 0xe8),JVar2,(JAISound **)(param_2 + 0xec),
               *(Vec **)(param_2 + 0xf4),uVar1,0,'\x04');
  }
  else {
    this_00 = *(JAISound **)(param_2 + 0xec);
    if (this_00 != (JAISound *)0x0) {
      uVar1 = Runtime.PPCEABI.H::__cvt_fp2unsigned(dVar3);
      ::JAISound::start(this_00,uVar1);
    }
  }
  return;
}


/* __thiscall TVVOOn_END_FADE_OUT_::operator ()(float,
                                                                                JStudio::TAdaptor *)
   const */

TVVOOn_END_FADE_OUT_ * __thiscall
TVVOOn_END_FADE_OUT_::operator___
          (TVVOOn_END_FADE_OUT_ *this,float param_1,TAdaptor *param_2)

{
  ulong uVar1;
  JAISound *this_00;
  
  this_00 = *(JAISound **)(param_2 + 0xec);
  if (this_00 != (JAISound *)0x0) {
    uVar1 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)param_1);
    this = (TVVOOn_END_FADE_OUT_ *)::JAISound::stop(this_00,uVar1);
  }
  return this;
}


/* __thiscall TVVOSetValue_::operator ()(float,
                                                                         JStudio::TAdaptor *) const
    */

void __thiscall
TVVOSetValue_::operator___
          (TVVOSetValue_ *this,float param_1,TAdaptor *param_2)

{
  if (*(void **)(param_2 + 0xec) != (void *)0x0) {
    Runtime.PPCEABI.H::__ptmf_scall((PTMF *)(this + 8),*(void **)(param_2 + 0xec),(void *)0x0);
  }
  return;
}

}
}

/* __thiscall JAISound::setDemoFxmix(float,
                                     unsigned long) */

void __thiscall JAISound::setDemoFxmix(JAISound *this,float param_1,ulong param_2)

{
  setFxmix(this,param_1,param_2,'\x03');
  return;
}


/* __thiscall JAISound::setDemoPitch(float,
                                     unsigned long) */

void __thiscall JAISound::setDemoPitch(JAISound *this,float param_1,ulong param_2)

{
  setPitch(this,param_1,param_2,'\x03');
  return;
}


/* __thiscall JAISound::setDemoPan(float,
                                   unsigned long) */

void __thiscall JAISound::setDemoPan(JAISound *this,float param_1,ulong param_2)

{
  setPan(this,param_1,param_2,'\x03');
  return;
}


/* __thiscall JAISound::setDemoVolume(float,
                                      unsigned long) */

void __thiscall JAISound::setDemoVolume(JAISound *this,float param_1,ulong param_2)

{
  setVolume(this,param_1,param_2,3);
  return;
}


namespace JStudio_JAudio {

namespace TAdaptor_sound {

/* __thiscall TVVOSetValue_::~TVVOSetValue_(void) */

void __thiscall TVVOSetValue_::_TVVOSetValue_(TVVOSetValue_ *this)

{
  short in_r4;
  
  if (this != (TVVOSetValue_ *)0x0) {
    *(undefined1 **)this = &__vt;
    JStudio::TVariableValue::TOutput::_TOutput((TOutput *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TVVOOn_END_FADE_OUT_::~TVVOOn_END_FADE_OUT_(void) */

void __thiscall
TVVOOn_END_FADE_OUT_::_TVVOOn_END_FADE_OUT_
          (TVVOOn_END_FADE_OUT_ *this)

{
  short in_r4;
  
  if (this != (TVVOOn_END_FADE_OUT_ *)0x0) {
    *(undefined1 **)this = &__vt;
    JStudio::TVariableValue::TOutput::_TOutput((TOutput *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TVVOOn_BEGIN_FADE_IN_::~TVVOOn_BEGIN_FADE_IN_(void) */

void __thiscall
TVVOOn_BEGIN_FADE_IN_::_TVVOOn_BEGIN_FADE_IN_
          (TVVOOn_BEGIN_FADE_IN_ *this)

{
  short in_r4;
  
  if (this != (TVVOOn_BEGIN_FADE_IN_ *)0x0) {
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

void __sinit_object_sound_cpp(void)

{
  undefined1 *local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined1 *local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined *local_64;
  undefined1 *local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined *local_50;
  undefined1 *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined *local_3c;
  undefined1 *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined *local_28;
  undefined1 *local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined *local_14;
  
  _soVVOOn_BEGIN_FADE_IN_ = &TAdaptor_sound::TVVOOn_BEGIN_FADE_IN_::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&TAdaptor_sound::soVVOOn_BEGIN_FADE_IN_,
             TAdaptor_sound::TVVOOn_BEGIN_FADE_IN_::_TVVOOn_BEGIN_FADE_IN_,&_1226);
  _soVVOOn_END_FADE_OUT_ = &TAdaptor_sound::TVVOOn_END_FADE_OUT_::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&TAdaptor_sound::soVVOOn_END_FADE_OUT_,
             TAdaptor_sound::TVVOOn_END_FADE_OUT_::_TVVOOn_END_FADE_OUT_,&_1227);
  local_24 = &TAdaptor_sound::TVVOSetValue_::__vt;
  local_20 = 6;
  local_1c = _1228;
  local_18 = DAT_80397d74;
  local_14 = PTR_setDemoVolume_80397d78;
  _saoVVOSetValue_ = &TAdaptor_sound::TVVOSetValue_::__vt;
  DAT_803e8c34 = 6;
  DAT_803e8c38 = _1228;
  DAT_803e8c3c = DAT_80397d74;
  DAT_803e8c40 = PTR_setDemoVolume_80397d78;
  Runtime.PPCEABI.H::__register_global_object
            (&TAdaptor_sound::saoVVOSetValue_,TAdaptor_sound::TVVOSetValue_::_TVVOSetValue_,&_1230);
  local_24 = &TAdaptor_sound::TVVOSetValue_::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_24);
  local_38 = &TAdaptor_sound::TVVOSetValue_::__vt;
  local_34 = 7;
  local_30 = _1231;
  local_2c = DAT_80397d80;
  local_28 = PTR_setDemoPan_80397d84;
  DAT_803e8c44 = &TAdaptor_sound::TVVOSetValue_::__vt;
  DAT_803e8c48 = 7;
  DAT_803e8c4c = _1231;
  DAT_803e8c50 = DAT_80397d80;
  DAT_803e8c54 = PTR_setDemoPan_80397d84;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e8c44,TAdaptor_sound::TVVOSetValue_::_TVVOSetValue_,&_1233);
  local_38 = &TAdaptor_sound::TVVOSetValue_::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_38);
  local_4c = &TAdaptor_sound::TVVOSetValue_::__vt;
  local_48 = 8;
  local_44 = _1234;
  local_40 = DAT_80397d8c;
  local_3c = PTR_setDemoPitch_80397d90;
  DAT_803e8c58 = &TAdaptor_sound::TVVOSetValue_::__vt;
  DAT_803e8c5c = 8;
  DAT_803e8c60 = _1234;
  DAT_803e8c64 = DAT_80397d8c;
  DAT_803e8c68 = PTR_setDemoPitch_80397d90;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e8c58,TAdaptor_sound::TVVOSetValue_::_TVVOSetValue_,&_1236);
  local_4c = &TAdaptor_sound::TVVOSetValue_::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_4c);
  local_60 = &TAdaptor_sound::TVVOSetValue_::__vt;
  local_5c = 9;
  local_58 = _1237;
  local_54 = DAT_80397d98;
  local_50 = PTR_setTempoProportion_80397d9c;
  DAT_803e8c6c = &TAdaptor_sound::TVVOSetValue_::__vt;
  DAT_803e8c70 = 9;
  DAT_803e8c74 = _1237;
  DAT_803e8c78 = DAT_80397d98;
  DAT_803e8c7c = PTR_setTempoProportion_80397d9c;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e8c6c,TAdaptor_sound::TVVOSetValue_::_TVVOSetValue_,&_1239);
  local_60 = &TAdaptor_sound::TVVOSetValue_::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_60);
  local_74 = &TAdaptor_sound::TVVOSetValue_::__vt;
  local_70 = 10;
  local_6c = _1240;
  local_68 = DAT_80397da4;
  local_64 = PTR_setDemoFxmix_80397da8;
  DAT_803e8c80 = &TAdaptor_sound::TVVOSetValue_::__vt;
  DAT_803e8c84 = 10;
  DAT_803e8c88 = _1240;
  DAT_803e8c8c = DAT_80397da4;
  DAT_803e8c90 = PTR_setDemoFxmix_80397da8;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e8c80,TAdaptor_sound::TVVOSetValue_::_TVVOSetValue_,&_1242);
  local_74 = &TAdaptor_sound::TVVOSetValue_::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_74);
  local_88 = &TAdaptor_sound::TVVOSetValue_::__vt;
  local_84 = 0xffffffff;
  local_80 = Runtime.PPCEABI.H::__ptmf_null;
  local_7c = DAT_80370fbc;
  local_78 = DAT_80370fc0;
  DAT_803e8c94 = &TAdaptor_sound::TVVOSetValue_::__vt;
  DAT_803e8c98 = 0xffffffff;
  DAT_803e8c9c = Runtime.PPCEABI.H::__ptmf_null;
  DAT_803e8ca0 = DAT_80370fbc;
  DAT_803e8ca4 = DAT_80370fc0;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e8c94,TAdaptor_sound::TVVOSetValue_::_TVVOSetValue_,&_1244);
  local_88 = &TAdaptor_sound::TVVOSetValue_::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_88);
  return;
}

