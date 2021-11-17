#include <JAZelAudio/JAIZelAtmos.h>
#include <m_Do_printf.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JAZelAudio/JAIZelAtmos.h>
#include <mtx/mtxvec.h>
#include <JAudio/JAIBasic.h>
#include <JAudio/JAISound.h>
#include <JAudio/JAIGlobalParameter.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <JAIZelBasic.h>


/* __thiscall JAIZelBasic::initSeaEnvPos(void) */

void __thiscall JAIZelBasic::initSeaEnvPos(JAIZelBasic *this)

{
  *(undefined4 *)&this->field_0x1b80 = 0;
  return;
}


/* __thiscall JAIZelBasic::registSeaEnvPos(Vec *) */

int __thiscall JAIZelBasic::registSeaEnvPos(JAIZelBasic *this,Vec *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 == (Vec *)0x0) {
    iVar1 = -1;
  }
  else {
    puVar2 = (undefined4 *)(&this->field_0x1580 + *(int *)&this->field_0x1b80 * 0xc);
    *puVar2 = *(undefined4 *)param_1;
    puVar2[1] = *(undefined4 *)(param_1 + 4);
    puVar2[2] = *(undefined4 *)(param_1 + 8);
    *(int *)&this->field_0x1b80 = *(int *)&this->field_0x1b80 + 1;
    iVar1 = *(int *)&this->field_0x1b80;
    if (0x3f < iVar1) {
      m_Do_printf::OSReport
                ("[JAIZelBasic::registSeaEnvPos] !! WARNING : num of sea rail is over range!\n");
      *(undefined4 *)&this->field_0x1b80 = 0x3f;
      iVar1 = -1;
    }
  }
  return iVar1;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x802ad524) */
/* WARNING: Removing unreachable block (ram,0x802ad514) */
/* WARNING: Removing unreachable block (ram,0x802ad504) */
/* WARNING: Removing unreachable block (ram,0x802ad50c) */
/* WARNING: Removing unreachable block (ram,0x802ad51c) */
/* WARNING: Removing unreachable block (ram,0x802ad52c) */
/* __thiscall JAIZelBasic::seaEnvSePlay(unsigned long,
                                        signed char) */

void __thiscall JAIZelBasic::seaEnvSePlay(JAIZelBasic *this,ulong param_1,char param_2)

{
  JAISoundInfoID JVar1;
  int iVar2;
  int iVar3;
  JAISoundInfoID JVar4;
  MTX34 *pMtx;
  JAISoundInfoID JVar5;
  cXyz *pDst;
  int iVar6;
  undefined4 uVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double in_f26;
  undefined8 in_f27;
  undefined8 in_f28;
  double dVar11;
  undefined8 in_f29;
  double dVar12;
  double dVar13;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar14;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,SUB84(in_f26,0),0);
  if ((((*(char *)&this->field_0x1f8 == '\0') && (*(char *)&this->field_0x204 != '\x01')) &&
      (this->field_0x201 != 1)) && (*(char *)&this->field_0x206 != '\x01')) {
    if ((*(uint *)&this->field_0x218 & 0xff) == 0x14) {
      local_b8 = ***(float ***)&this->field_0x4;
      local_b0 = (**(float ***)&this->field_0x4)[2];
      local_a0 = local_b8 - JAZelAudio::_850;
      local_90 = JAZelAudio::_851;
      local_a4 = local_b0 - JAZelAudio::_850;
      local_9c = JAZelAudio::_851;
      local_b0 = JAZelAudio::_850 + local_b0;
      local_b8 = JAZelAudio::_850 + local_b8;
      local_a8 = JAZelAudio::_851;
      local_b4 = JAZelAudio::_851;
      local_ac = local_b8;
      local_98 = local_b0;
      local_94 = local_a0;
      local_8c = local_a4;
      registSeaEnvPos(this,(Vec *)&local_94);
      registSeaEnvPos(this,(Vec *)&local_a0);
      registSeaEnvPos(this,(Vec *)&local_ac);
      registSeaEnvPos(this,(Vec *)&local_b8);
    }
    dVar12 = (double)JAZelAudio::_851;
    if (*(int *)&this->field_0x1b80 != 0) {
      pMtx = *(MTX34 **)(*(int *)&this->field_0x4 + 8);
      iVar6 = 0;
      dVar14 = (double)JAZelAudio::_852;
      dVar11 = dVar12;
      dVar13 = dVar12;
      for (iVar3 = 0; iVar3 < *(int *)&this->field_0x1b80; iVar3 = iVar3 + 1) {
        iVar2 = (int)&this->vtbl + iVar6;
        pDst = (cXyz *)(iVar2 + 0x1880);
        mtx::PSMTXMultVec(pMtx,(cXyz *)(iVar2 + 0x1580),pDst);
        if (param_1 < 8) {
          dVar9 = (double)calcPosVolume(this,(Vec *)pDst,JAZelAudio::_853);
        }
        else {
          dVar9 = (double)calcPosVolume(this,(Vec *)pDst,JAZelAudio::_852);
          in_f26 = (double)calcPosPanSR(this,(Vec *)pDst,JAZelAudio::_852);
        }
        dVar10 = (double)calcPosPanLR(this,(Vec *)pDst);
        dVar8 = (double)(float)((double)(float)(dVar14 - dVar10) * dVar9);
        if (dVar13 < dVar8) {
          dVar13 = dVar8;
        }
        if (dVar11 < (double)(float)(dVar10 * dVar9)) {
          dVar11 = (double)(float)(dVar10 * dVar9);
        }
        if (dVar12 < (double)(float)(in_f26 * dVar9)) {
          dVar12 = (double)(float)(in_f26 * dVar9);
        }
        iVar6 = iVar6 + 0xc;
      }
      if ((double)JAZelAudio::_852 < dVar13) {
        dVar13 = (double)JAZelAudio::_852;
      }
      if ((double)JAZelAudio::_852 < dVar11) {
        dVar11 = (double)JAZelAudio::_852;
      }
      if ((double)JAZelAudio::_852 < dVar12) {
        dVar12 = (double)JAZelAudio::_852;
      }
      if (this->field_0x20 != 0) {
        dVar14 = (double)JAZelAudio::_854;
        dVar13 = (double)(float)(dVar13 * dVar14);
        dVar11 = (double)(float)(dVar11 * dVar14);
        dVar12 = (double)(float)(dVar12 * dVar14);
      }
      if (param_1 == 8) {
        JVar1 = JA_SE_MAGMA_L;
        JVar4 = JA_SE_MAGMA_R;
        JVar5 = JA_SE_MAGMA_SR;
      }
      else {
        JVar1 = JA_SE_SEA_ALL_NORM_L;
        JVar4 = JA_SE_SEA_ALL_NORM_R;
        JVar5 = JA_SE_SEA_ALL_NORM_SR;
      }
      if ((double)JAZelAudio::_851 != dVar13) {
        JAIBasic::startSoundVec
                  ((JAIBasic *)this,JVar1,(JAISound **)&this->field_0x1ec4,(Vec *)0x0,0,0,'\x04');
        if (*(JAISound **)&this->field_0x1ec4 != (JAISound *)0x0) {
          JAISound::setPortData(*(JAISound **)&this->field_0x1ec4,'\t',(short)param_2);
          JAISound::setPan(*(JAISound **)&this->field_0x1ec4,JAZelAudio::_852,0,'\0');
          JAISound::setDolby(*(JAISound **)&this->field_0x1ec4,JAZelAudio::_851,0,'\0');
          JAISound::setVolume(*(JAISound **)&this->field_0x1ec4,(float)dVar13,0,0);
        }
      }
      if ((double)JAZelAudio::_851 != dVar11) {
        JAIBasic::startSoundVec
                  ((JAIBasic *)this,JVar4,(JAISound **)&this->field_0x1ec8,(Vec *)0x0,0,0,'\x04');
        if (*(JAISound **)&this->field_0x1ec8 != (JAISound *)0x0) {
          JAISound::setPortData(*(JAISound **)&this->field_0x1ec8,'\t',(short)param_2);
          JAISound::setPan(*(JAISound **)&this->field_0x1ec8,JAZelAudio::_851,0,'\0');
          JAISound::setDolby(*(JAISound **)&this->field_0x1ec8,JAZelAudio::_851,0,'\0');
          JAISound::setVolume(*(JAISound **)&this->field_0x1ec8,(float)dVar11,0,0);
        }
      }
      if ((double)JAZelAudio::_851 != dVar12) {
        JAIBasic::startSoundVec
                  ((JAIBasic *)this,JVar5,(JAISound **)&this->field_0x1ecc,(Vec *)0x0,0,0,'\x04');
        if (*(JAISound **)&this->field_0x1ecc != (JAISound *)0x0) {
          JAISound::setPortData(*(JAISound **)&this->field_0x1ecc,'\t',(short)param_2);
          JAISound::setPan(*(JAISound **)&this->field_0x1ecc,JAZelAudio::_855,0,'\0');
          JAISound::setDolby(*(JAISound **)&this->field_0x1ecc,JAZelAudio::_852,0,'\0');
          JAISound::setVolume(*(JAISound **)&this->field_0x1ecc,(float)dVar12,0,0);
        }
      }
    }
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  __psq_l0(auStack40,uVar7);
  __psq_l1(auStack40,uVar7);
  __psq_l0(auStack56,uVar7);
  __psq_l1(auStack56,uVar7);
  __psq_l0(auStack72,uVar7);
  __psq_l1(auStack72,uVar7);
  __psq_l0(auStack88,uVar7);
  __psq_l1(auStack88,uVar7);
  return;
}


/* __thiscall JAIZelBasic::calcPosPanLR(Vec *) */

double __thiscall JAIZelBasic::calcPosPanLR(JAIZelBasic *this,Vec *param_1)

{
  float fVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  dVar3 = (double)JAZelAudio::_851;
  dVar2 = (double)*(float *)param_1;
  if (dVar3 == dVar2) {
    return (double)JAZelAudio::_855;
  }
  dVar4 = (double)*(float *)(param_1 + 8);
  if (dVar3 == dVar4) {
    if (dVar3 < dVar2) {
      return (double)JAZelAudio::_852;
    }
    if (dVar2 < dVar3) {
      return dVar3;
    }
  }
  dVar2 = (double)((float)(dVar2 * dVar2) + (float)(dVar4 * dVar4));
  if ((double)JAZelAudio::_851 < dVar2) {
    dVar3 = 1.0 / SQRT(dVar2);
    dVar3 = JAZelAudio::_884 * dVar3 * (JAZelAudio::_885 - dVar2 * dVar3 * dVar3);
    dVar3 = JAZelAudio::_884 * dVar3 * (JAZelAudio::_885 - dVar2 * dVar3 * dVar3);
    dVar2 = (double)(float)(dVar2 * JAZelAudio::_884 * dVar3 *
                                    (JAZelAudio::_885 - dVar2 * dVar3 * dVar3));
  }
  fVar1 = (float)((double)*(float *)param_1 / dVar2);
  if (JAZelAudio::_852 < (float)((double)*(float *)param_1 / dVar2)) {
    fVar1 = JAZelAudio::_852;
  }
  if (fVar1 < JAZelAudio::_886) {
    fVar1 = JAZelAudio::_886;
  }
  return (double)((JAZelAudio::_852 + fVar1) * JAZelAudio::_855);
}


/* WARNING: Removing unreachable block (ram,0x802ad704) */
/* WARNING: Removing unreachable block (ram,0x802ad6fc) */
/* WARNING: Removing unreachable block (ram,0x802ad70c) */
/* __thiscall JAIZelBasic::calcPosPanSR(Vec *,
                                        float) */

double __thiscall JAIZelBasic::calcPosPanSR(JAIZelBasic *this,Vec *param_1,float param_2)

{
  JAIGlobalParameter *pJVar1;
  undefined4 uVar2;
  double extraout_f1;
  double extraout_f1_00;
  double dVar3;
  double extraout_f1_01;
  double extraout_f1_02;
  double dVar4;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar3 = (double)param_2;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  pJVar1 = (JAIGlobalParameter *)
           JAIGlobalParameter::getParamSeDolbyCenterValue((JAIGlobalParameter *)this);
  dVar5 = (double)(float)(extraout_f1 / (double)JAZelAudio::_901);
  dVar6 = (double)(float)((double)JAZelAudio::_852 - dVar5);
  pJVar1 = (JAIGlobalParameter *)JAIGlobalParameter::getParamSeDolbyFrontDistanceMax(pJVar1);
  if ((float)(dVar3 * extraout_f1_00) <= *(float *)(param_1 + 8)) {
    if (JAZelAudio::_851 <= *(float *)(param_1 + 8)) {
      pJVar1 = (JAIGlobalParameter *)JAIGlobalParameter::getParamSeDolbyBehindDistanceMax(pJVar1);
      if ((float)(dVar3 * extraout_f1_02) <= *(float *)(param_1 + 8)) {
        dVar3 = (double)JAZelAudio::_852;
      }
      else {
        dVar4 = (double)JAIGlobalParameter::getParamSeDolbyBehindDistanceMax(pJVar1);
        dVar3 = (double)(float)(dVar5 + (double)(float)(dVar6 * (double)(*(float *)(param_1 + 8) /
                                                                        (float)(dVar3 * dVar4))));
      }
    }
    else {
      pJVar1 = (JAIGlobalParameter *)JAIGlobalParameter::getParamSeDolbyFrontDistanceMax(pJVar1);
      dVar3 = extraout_f1_01;
      dVar6 = (double)JAIGlobalParameter::getParamSeDolbyFrontDistanceMax(pJVar1);
      dVar3 = (double)(float)((double)(float)(dVar5 * (double)(float)(dVar6 - (double)*(float *)(
                                                  param_1 + 8))) / dVar3);
    }
  }
  else {
    dVar3 = (double)JAZelAudio::_851;
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  return dVar3;
}


/* WARNING: Removing unreachable block (ram,0x802ad858) */
/* WARNING: Removing unreachable block (ram,0x802ad850) */
/* WARNING: Removing unreachable block (ram,0x802ad860) */
/* __thiscall JAIZelBasic::calcPosVolume(Vec *,
                                         float) */

double __thiscall JAIZelBasic::calcPosVolume(JAIZelBasic *this,Vec *param_1,float param_2)

{
  JAIGlobalParameter *pJVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  double extraout_f1_03;
  double dVar5;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar4 = (double)param_2;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if (param_1 == (Vec *)0x0) {
    dVar4 = (double)JAZelAudio::_851;
  }
  else {
    dVar5 = (double)(*(float *)(param_1 + 8) * *(float *)(param_1 + 8) +
                    *(float *)param_1 * *(float *)param_1 +
                    *(float *)(param_1 + 4) * *(float *)(param_1 + 4));
    if ((double)JAZelAudio::_851 < dVar5) {
      dVar3 = 1.0 / SQRT(dVar5);
      dVar3 = JAZelAudio::_884 * dVar3 * (JAZelAudio::_885 - dVar5 * dVar3 * dVar3);
      dVar3 = JAZelAudio::_884 * dVar3 * (JAZelAudio::_885 - dVar5 * dVar3 * dVar3);
      dVar5 = (double)(float)(dVar5 * JAZelAudio::_884 * dVar3 *
                                      (JAZelAudio::_885 - dVar5 * dVar3 * dVar3));
    }
    pJVar1 = (JAIGlobalParameter *)
             JAIGlobalParameter::getParamMaxVolumeDistance((JAIGlobalParameter *)this);
    if (extraout_f1 <= dVar5) {
      pJVar1 = (JAIGlobalParameter *)JAIGlobalParameter::getParamMaxVolumeDistance(pJVar1);
      dVar3 = (double)(float)(dVar5 - extraout_f1_00);
      pJVar1 = (JAIGlobalParameter *)JAIGlobalParameter::getParamMaxVolumeDistance(pJVar1);
      dVar5 = extraout_f1_01;
      pJVar1 = (JAIGlobalParameter *)JAIGlobalParameter::getParamDistanceMax(pJVar1);
      dVar4 = (double)(float)((double)(float)(extraout_f1_02 - dVar5) * dVar4);
      if (dVar3 < dVar4) {
        pJVar1 = (JAIGlobalParameter *)JAIGlobalParameter::getParamMinDistanceVolume(pJVar1);
        dVar5 = (double)((float)((double)JAZelAudio::_852 - (double)(float)(dVar3 / dVar4)) *
                        (float)((double)JAZelAudio::_852 - extraout_f1_03));
        dVar4 = (double)JAIGlobalParameter::getParamMinDistanceVolume(pJVar1);
        dVar4 = (double)(float)(dVar4 + dVar5);
      }
      else {
        dVar4 = (double)JAZelAudio::_851;
      }
    }
    else {
      dVar4 = (double)JAZelAudio::_852;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  return dVar4;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JAIZelBasic::seaShoreSE(unsigned long,
                                      Vec *,
                                      unsigned long,
                                      signed char) */

void __thiscall
JAIZelBasic::seaShoreSE(JAIZelBasic *this,ulong param_1,Vec *param_2,ulong param_3,char param_4)

{
  JAISoundInfoID JVar1;
  
  if ((this->field_0x201 != 1) && (*(char *)&this->field_0x206 != '\x01')) {
    if (param_1 == 1) {
      JVar1 = JA_SE_SEASHORE_QUAY;
    }
    else {
      if (((int)param_1 < 1) || (2 < (int)param_1)) {
        JVar1 = JA_SE_SEASHORE_NORM;
      }
      else {
        JVar1 = JA_SE_SEASHORE_CLIFF;
      }
    }
    if (this->field_0x22d != 0) {
      *(undefined4 *)&this->field_0x1b84 = *(undefined4 *)param_2;
      *(undefined4 *)&this->field_0x1b88 = *(undefined4 *)(param_2 + 4);
      *(undefined4 *)&this->field_0x1b8c = *(undefined4 *)(param_2 + 8);
      if ((param_3 == 0) && (*(JAISound **)&this->field_0x1ed0 != (JAISound *)0x0)) {
        JAISound::stop(*(JAISound **)&this->field_0x1ed0,1);
      }
      JAIBasic::startSoundVec
                ((JAIBasic *)this,JVar1,(JAISound **)&this->field_0x1ed0,(Vec *)&this->field_0x1b84,
                 0,0,'\x04');
      if (*(JAISound **)&this->field_0x1ed0 != (JAISound *)0x0) {
        JAISound::setPortData(*(JAISound **)&this->field_0x1ed0,'\t',(short)param_4);
      }
      if (this->field_0x20 != 0) {
        JAISound::setVolume(*(JAISound **)&this->field_0x1ed0,JAZelAudio::_854,0,0);
      }
    }
  }
  return;
}


/* __thiscall JAIZelBasic::initRiverPos(void) */

void __thiscall JAIZelBasic::initRiverPos(JAIZelBasic *this)

{
  *(undefined4 *)&this->field_0x1dd0 = 0;
  return;
}


/* WARNING: Removing unreachable block (ram,0x802adb18) */
/* __thiscall JAIZelBasic::registRiverPos(Vec *) */

int __thiscall JAIZelBasic::registRiverPos(JAIZelBasic *this,Vec *param_1)

{
  int iVar1;
  MTX34 *pMtx;
  undefined4 *puVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f31;
  cXyz local_24;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 == (Vec *)0x0) {
    m_Do_printf::OSReport("[JAIZelBasic::registRiverPos] WARNING : wpos = NULL\n");
    iVar1 = -1;
  }
  else {
    pMtx = *(MTX34 **)(*(int *)&this->field_0x4 + 8);
    local_24.x = *(float *)param_1;
    local_24.y = *(float *)(param_1 + 4);
    local_24.z = *(float *)(param_1 + 8);
    if (pMtx != (MTX34 *)0x0) {
      mtx::PSMTXMultVec(pMtx,&local_24,&local_24);
    }
    dVar5 = (double)(local_24.z * local_24.z + local_24.x * local_24.x + local_24.y * local_24.y);
    if ((double)JAZelAudio::_851 < dVar5) {
      dVar4 = 1.0 / SQRT(dVar5);
      dVar4 = JAZelAudio::_884 * dVar4 * (JAZelAudio::_885 - dVar5 * dVar4 * dVar4);
      dVar4 = JAZelAudio::_884 * dVar4 * (JAZelAudio::_885 - dVar5 * dVar4 * dVar4);
      dVar5 = (double)(float)(dVar5 * JAZelAudio::_884 * dVar4 *
                                      (JAZelAudio::_885 - dVar5 * dVar4 * dVar4));
    }
    dVar4 = (double)JAIGlobalParameter::getParamDistanceMax((JAIGlobalParameter *)pMtx);
    if (dVar5 <= (double)(float)((double)JAZelAudio::_853 * dVar4)) {
      puVar2 = (undefined4 *)(&this->field_0x1b90 + *(int *)&this->field_0x1dd0 * 0xc);
      *puVar2 = *(undefined4 *)param_1;
      puVar2[1] = *(undefined4 *)(param_1 + 4);
      puVar2[2] = *(undefined4 *)(param_1 + 8);
      *(int *)&this->field_0x1dd0 = *(int *)&this->field_0x1dd0 + 1;
      iVar1 = *(int *)&this->field_0x1dd0;
      if (0x3f < iVar1) {
        m_Do_printf::OSReport
                  ("[JAIZelBasic::registRiverPos] !! WARNING : num of river rail is over range!\n");
        *(undefined4 *)&this->field_0x1dd0 = 0x2f;
        iVar1 = -1;
      }
    }
    else {
      iVar1 = *(int *)&this->field_0x1dd0;
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return iVar1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JAIZelBasic::riverSePlay(unsigned char,
                                       signed char) */

void __thiscall JAIZelBasic::riverSePlay(JAIZelBasic *this,uchar param_1,char param_2)

{
  int iVar1;
  ulong soundId;
  int iVar2;
  
  if ((((*(int *)&this->field_0x1dd0 != 0) && (*(char *)&this->field_0x1f8 == '\0')) &&
      (this->field_0x201 != 1)) && (*(char *)&this->field_0x206 != '\x01')) {
    if (*(int *)&this->field_0x218 == 0x18) {
      registRiverPos(this,(Vec *)&this->field_0x54);
    }
    switch(param_1) {
    case '\0':
      soundId = 0x3033;
      break;
    case '\x01':
      soundId = 0x3034;
      break;
    case '\x02':
      if (*(char *)&this->field_0x1dd4 == '\0') {
        return;
      }
      soundId = 0x7035;
      break;
    case '\x03':
    case '\x05':
      return;
    case '\x04':
    case '\x06':
      soundId = 0x303a;
      break;
    default:
      goto switchD_802adbbc_caseD_7;
    }
    iVar2 = 0;
    for (iVar1 = 0; iVar1 < *(int *)&this->field_0x1dd0; iVar1 = iVar1 + 1) {
      seStart(this,soundId,(cXyz *)(&this->field_0x1b90 + iVar2),0,param_2,JAZelAudio::_852,
              JAZelAudio::_852,JAZelAudio::_886,JAZelAudio::_886,0);
      iVar2 = iVar2 + 0xc;
    }
  }
switchD_802adbbc_caseD_7:
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x802ade48) */
/* __thiscall JAIZelBasic::waterfallSePlay(unsigned char,
                                           Vec *,
                                           signed char) */

void __thiscall
JAIZelBasic::waterfallSePlay(JAIZelBasic *this,uchar param_1,Vec *param_2,char param_3)

{
  MTX34 *pMtx;
  undefined4 *puVar1;
  int iVar2;
  ulong soundId;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f31;
  cXyz local_34;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 == '\x02') {
LAB_802adcb0:
    soundId = 0x107c;
  }
  else {
    if (param_1 < 2) {
      if (param_1 == '\0') {
        soundId = 0x1067;
        goto LAB_802adcbc;
      }
    }
    else {
      if (param_1 == '\x04') goto LAB_802adcb0;
    }
    soundId = 0x1066;
  }
LAB_802adcbc:
  pMtx = *(MTX34 **)(*(int *)&this->field_0x4 + 8);
  local_34.x = *(float *)param_2;
  local_34.y = *(float *)(param_2 + 4);
  local_34.z = *(float *)(param_2 + 8);
  if (pMtx != (MTX34 *)0x0) {
    mtx::PSMTXMultVec(pMtx,&local_34,&local_34);
  }
  dVar5 = (double)(local_34.z * local_34.z + local_34.x * local_34.x + local_34.y * local_34.y);
  if ((double)JAZelAudio::_851 < dVar5) {
    dVar4 = 1.0 / SQRT(dVar5);
    dVar4 = JAZelAudio::_884 * dVar4 * (JAZelAudio::_885 - dVar5 * dVar4 * dVar4);
    dVar4 = JAZelAudio::_884 * dVar4 * (JAZelAudio::_885 - dVar5 * dVar4 * dVar4);
    dVar5 = (double)(float)(dVar5 * JAZelAudio::_884 * dVar4 *
                                    (JAZelAudio::_885 - dVar5 * dVar4 * dVar4));
  }
  dVar4 = (double)JAIGlobalParameter::getParamDistanceMax((JAIGlobalParameter *)pMtx);
  if (dVar5 <= (double)(float)((double)JAZelAudio::_1050 * dVar4)) {
    puVar1 = (undefined4 *)(&this->field_0x1dd8 + *(int *)&this->field_0x1e98 * 0xc);
    *puVar1 = *(undefined4 *)param_2;
    puVar1[1] = *(undefined4 *)(param_2 + 4);
    puVar1[2] = *(undefined4 *)(param_2 + 8);
    if (*(char *)&this->field_0x207 == '\0') {
      iVar2 = checkPlayingStreamBgmFlag(this);
      if ((iVar2 != -0x3fffffc4) && (*(char *)&this->field_0x207 == '\0')) {
        seStart(this,soundId,(cXyz *)(&this->field_0x1dd8 + *(int *)&this->field_0x1e98 * 0xc),0,
                param_3,JAZelAudio::_852,JAZelAudio::_852,JAZelAudio::_886,JAZelAudio::_886,0);
      }
      if (*(int *)&this->field_0x1e98 < 0xf) {
        *(int *)&this->field_0x1e98 = *(int *)&this->field_0x1e98 + 1;
      }
    }
    else {
      if (*(int *)&this->field_0x1e98 < 0xf) {
        *(int *)&this->field_0x1e98 = *(int *)&this->field_0x1e98 + 1;
      }
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __thiscall JAIZelBasic::initWindowPos(void) */

void __thiscall JAIZelBasic::initWindowPos(JAIZelBasic *this)

{
  *(undefined4 *)&this->field_0x1ec0 = 0;
  return;
}


/* __thiscall JAIZelBasic::registWindowPos(Vec *) */

int __thiscall JAIZelBasic::registWindowPos(JAIZelBasic *this,Vec *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 == (Vec *)0x0) {
    m_Do_printf::OSReport("[JAIZelBasic::setWindowPos] WARNING : wpos = NULL\n");
    iVar1 = -1;
  }
  else {
    puVar2 = (undefined4 *)(&this->field_0x1e9c + *(int *)&this->field_0x1ec0 * 0xc);
    *puVar2 = *(undefined4 *)param_1;
    puVar2[1] = *(undefined4 *)(param_1 + 4);
    puVar2[2] = *(undefined4 *)(param_1 + 8);
    *(int *)&this->field_0x1ec0 = *(int *)&this->field_0x1ec0 + 1;
    iVar1 = *(int *)&this->field_0x1ec0;
    if (2 < iVar1) {
      m_Do_printf::OSReport
                ("[JAIZelBasic::registWindowPos] !! WARNING : num of window rail is over range!\n");
      *(undefined4 *)&this->field_0x1ec0 = 2;
      iVar1 = -1;
    }
  }
  return iVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JAIZelBasic::rainPlay(long) */

void __thiscall JAIZelBasic::rainPlay(JAIZelBasic *this,long param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)&this->field_0x1ec0 == 0) {
    if (param_1 == 1) {
      seStart(this,0x1085,(cXyz *)0x0,0,0,JAZelAudio::_852,JAZelAudio::_852,JAZelAudio::_886,
              JAZelAudio::_886,0);
    }
    else {
      seStart(this,0x105b,(cXyz *)0x0,0,0,JAZelAudio::_852,JAZelAudio::_852,JAZelAudio::_886,
              JAZelAudio::_886,0);
    }
  }
  else {
    iVar2 = 0;
    for (iVar1 = 0; iVar1 < *(int *)&this->field_0x1ec0; iVar1 = iVar1 + 1) {
      if (param_1 == 1) {
        seStart(this,0x1086,(cXyz *)(&this->field_0x1e9c + iVar2),0,0,JAZelAudio::_852,
                JAZelAudio::_852,JAZelAudio::_886,JAZelAudio::_886,0);
      }
      else {
        seStart(this,0x1084,(cXyz *)(&this->field_0x1e9c + iVar2),0,0,JAZelAudio::_852,
                JAZelAudio::_852,JAZelAudio::_886,JAZelAudio::_886,0);
      }
      iVar2 = iVar2 + 0xc;
    }
  }
  return;
}

