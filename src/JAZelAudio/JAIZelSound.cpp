#include <JAZelAudio/JAIZelSound.h>
#include <JAudio/JAISound.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JAudio/JAIGlobalParameter.h>
#include <JAIZelSound.h>


/* __thiscall JAIZelSound::JAIZelSound(void) */

void __thiscall JAIZelSound::JAIZelSound(JAIZelSound *this)

{
  JAISound::JAISound((JAISound *)this);
  *(undefined1 **)this = &__vt;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802af174) */
/* WARNING: Removing unreachable block (ram,0x802af17c) */
/* __thiscall JAIZelSound::setDistanceVolumeCommon(float,
                                                   unsigned char) */

double __thiscall
JAIZelSound::setDistanceVolumeCommon(JAIZelSound *this,float param_1,uchar param_2)

{
  JAIGlobalParameter *pJVar1;
  uint uVar2;
  undefined4 uVar3;
  double extraout_f1;
  double dVar4;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar5;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar4 = (double)param_1;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if ((byte)this[8] == 4) {
    pJVar1 = *(JAIGlobalParameter **)(this + 0x20);
    dVar5 = (double)*(float *)(pJVar1 + 0x18);
    for (uVar2 = 1;
        pJVar1 = (JAIGlobalParameter *)JAIGlobalParameter::getParamAudioCameraMax(pJVar1),
        (JAIGlobalParameter *)(uVar2 & 0xff) < pJVar1; uVar2 = uVar2 + 1) {
      pJVar1 = (JAIGlobalParameter *)((uVar2 & 0xff) * 0x1c);
      if ((double)*(float *)(pJVar1 + *(int *)(this + 0x20) + 0x18) < dVar5) {
        dVar5 = (double)*(float *)(pJVar1 + *(int *)(this + 0x20) + 0x18);
      }
    }
  }
  else {
    pJVar1 = (JAIGlobalParameter *)(*(int *)(this + 0x20) + (uint)(byte)this[8] * 0x1c);
    dVar5 = (double)*(float *)(pJVar1 + 0x18);
  }
  pJVar1 = (JAIGlobalParameter *)JAIGlobalParameter::getParamMaxVolumeDistance(pJVar1);
  if (extraout_f1 <= dVar5) {
    pJVar1 = (JAIGlobalParameter *)JAIGlobalParameter::getParamMaxVolumeDistance(pJVar1);
    dVar5 = (double)(float)(dVar5 - extraout_f1_00);
    pJVar1 = (JAIGlobalParameter *)JAIGlobalParameter::getParamMaxVolumeDistance(pJVar1);
    dVar4 = (double)(float)(dVar4 - extraout_f1_01);
    uVar2 = (uint)param_2;
    if (uVar2 < 8) {
      if (uVar2 < 4) {
        if (param_2 != '\0') {
          pJVar1 = (JAIGlobalParameter *)&DAT_00000001;
          dVar4 = (double)(float)(dVar4 * (double)(float)((double)CONCAT44(0x43300000,
                                                                           1 << (param_2 & 3) ^
                                                                           0x80000000) -
                                                         JAZelAudio::_810));
        }
      }
      else {
        pJVar1 = (JAIGlobalParameter *)(param_2 & 3);
        dVar4 = (double)(float)(dVar4 / (double)(float)((double)CONCAT44(0x43300000,
                                                                         1 << (int)(pJVar1 + 1) ^
                                                                         0x80000000) -
                                                       JAZelAudio::_810));
      }
    }
    else {
      pJVar1 = (JAIGlobalParameter *)&DAT_00000001;
      dVar4 = (double)(float)(dVar4 * (double)(float)((double)CONCAT44(0x43300000,
                                                                       1 << uVar2 - 4 ^ 0x80000000)
                                                     - JAZelAudio::_810));
    }
    if (dVar4 <= dVar5) {
      if ((param_2 < 4) || (7 < param_2)) {
        dVar4 = (double)JAIGlobalParameter::getParamMinDistanceVolume(pJVar1);
      }
      else {
        dVar4 = (double)JAZelAudio::_808;
      }
    }
    else {
      if ((param_2 < 4) || (7 < param_2)) {
        pJVar1 = (JAIGlobalParameter *)JAIGlobalParameter::getParamMinDistanceVolume(pJVar1);
        dVar5 = (double)((float)((double)JAZelAudio::_807 - (double)(float)(dVar5 / dVar4)) *
                        (float)((double)JAZelAudio::_807 - extraout_f1_02));
        dVar4 = (double)JAIGlobalParameter::getParamMinDistanceVolume(pJVar1);
        dVar4 = (double)(float)(dVar4 + dVar5);
      }
      else {
        dVar4 = (double)(JAZelAudio::_807 - (float)(dVar5 / dVar4));
      }
    }
  }
  else {
    dVar4 = (double)JAZelAudio::_807;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return dVar4;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802af280) */
/* __thiscall JAIZelSound::setSeDistanceVolume(unsigned char) */

void __thiscall JAIZelSound::setSeDistanceVolume(JAIZelSound *this,uchar param_1)

{
  JAIGlobalParameter *pJVar1;
  uint uVar2;
  JAIGlobalParameter *this_00;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar2 = JAISound::getSwBit((JAISound *)this);
  if (((uVar2 & 0x400000) == 0) || (*(uint *)(this + 0x18) < 2)) {
    uVar2 = JAISound::getSwBit((JAISound *)this);
    if ((uVar2 & 2) == 0) {
      uVar2 = JAISound::getSwBit((JAISound *)this);
      if ((uVar2 & 0x300000) == 0) {
        this_00 = (JAIGlobalParameter *)JAISound::getSwBit((JAISound *)this);
        pJVar1 = (JAIGlobalParameter *)((uint)this_00 >> 0x10 & 7);
      }
      else {
        uVar2 = JAISound::getSwBit((JAISound *)this);
        this_00 = (JAIGlobalParameter *)(uVar2 >> 0x14 & 3);
        pJVar1 = this_00 + 7;
      }
      JAIGlobalParameter::getParamDistanceMax(this_00);
      dVar4 = (double)(**(code **)(*(int *)this + 0xc))(this,pJVar1);
      uVar2 = JAISound::getSwBit((JAISound *)this);
      if (((uVar2 & 0x1000000) != 0) && (dVar4 <= (double)JAZelAudio::_830)) {
        dVar4 = (double)JAZelAudio::_830;
      }
    }
    else {
      dVar4 = (double)JAZelAudio::_807;
    }
    JAISound::setSeInterVolume((JAISound *)this,'\x04',(float)dVar4,(uint)param_1,'\0');
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __thiscall JAIZelSound::setSeDistancePan(unsigned char) */

void __thiscall JAIZelSound::setSeDistancePan(JAIZelSound *this,uchar param_1)

{
  uint uVar1;
  double dVar2;
  
  uVar1 = JAISound::getSwBit((JAISound *)this);
  if (((uVar1 & 0x800000) == 0) || (*(uint *)(this + 0x18) < 2)) {
    dVar2 = (double)(**(code **)(*(int *)this + 0x10))(this);
    JAISound::setSeInterPan((JAISound *)this,'\x04',(float)dVar2,(uint)param_1,'\0');
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802af430) */
/* WARNING: Removing unreachable block (ram,0x802af438) */
/* __thiscall JAIZelSound::setSeDistanceDolby(unsigned char) */

void __thiscall JAIZelSound::setSeDistanceDolby(JAIZelSound *this,uchar param_1)

{
  float fVar1;
  JAIGlobalParameter *pJVar2;
  int iVar3;
  undefined4 uVar4;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double dVar5;
  double extraout_f1_02;
  double extraout_f1_03;
  double extraout_f1_04;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar6;
  double dVar7;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  pJVar2 = (JAIGlobalParameter *)JAISound::getSwBit((JAISound *)this);
  if ((((uint)pJVar2 & 0x800000) == 0) || (*(uint *)(this + 0x18) < 2)) {
    iVar3 = *(int *)(this + 0x20);
    fVar1 = JAZelAudio::_808;
    if (*(int *)(this + 0x28) != 0) {
      pJVar2 = (JAIGlobalParameter *)JAIGlobalParameter::getParamSeDolbyFrontDistanceMax(pJVar2);
      fVar1 = JAZelAudio::_808;
      if (extraout_f1 <= (double)*(float *)(iVar3 + 8)) {
        if ((double)JAZelAudio::_808 <= (double)*(float *)(iVar3 + 8)) {
          pJVar2 = (JAIGlobalParameter *)
                   JAIGlobalParameter::getParamSeDolbyBehindDistanceMax(pJVar2);
          fVar1 = JAZelAudio::_861;
          if ((double)*(float *)(iVar3 + 8) < extraout_f1_02) {
            pJVar2 = (JAIGlobalParameter *)
                     JAIGlobalParameter::getParamSeDolbyBehindDistanceMax(pJVar2);
            dVar7 = (double)(float)((double)*(float *)(iVar3 + 8) / extraout_f1_03);
            pJVar2 = (JAIGlobalParameter *)JAIGlobalParameter::getParamSeDolbyCenterValue(pJVar2);
            dVar5 = (double)(float)((double)(float)((double)JAZelAudio::_861 - extraout_f1_04) *
                                   dVar7);
            dVar7 = (double)JAIGlobalParameter::getParamSeDolbyCenterValue(pJVar2);
            fVar1 = (float)(dVar7 + dVar5);
          }
        }
        else {
          pJVar2 = (JAIGlobalParameter *)JAIGlobalParameter::getParamSeDolbyFrontDistanceMax(pJVar2)
          ;
          dVar7 = extraout_f1_00;
          pJVar2 = (JAIGlobalParameter *)JAIGlobalParameter::getParamSeDolbyFrontDistanceMax(pJVar2)
          ;
          dVar6 = (double)(float)(extraout_f1_01 - (double)*(float *)(iVar3 + 8));
          dVar5 = (double)JAIGlobalParameter::getParamSeDolbyCenterValue(pJVar2);
          fVar1 = (float)((double)(float)(dVar5 * dVar6) / dVar7);
        }
      }
    }
    JAISound::setSeInterDolby
              ((JAISound *)this,'\x04',
               (float)((double)CONCAT44(0x43300000,(int)fVar1 & 0xff) - JAZelAudio::_864) /
               JAZelAudio::_861,(uint)param_1,'\0');
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return;
}

