#include <JAZelAudio/JAIZelAnime.h>
#include <JAudio/JAIAnimation.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <mtx/mtxvec.h>
#include <JAudio/JAIGlobalParameter.h>
#include <JAudio/JAISound.h>
#include <JAudio/JAIBasic.h>
#include <JAIZelAnime.h>


/* __thiscall JAIZelAnime::setAnimSound(Vec *,
                                        float,
                                        float,
                                        unsigned long,
                                        signed char) */

void __thiscall
JAIZelAnime::setAnimSound
          (JAIZelAnime *this,cXyz *pPos,float time,float speed,ulong param_4,char param_5)

{
  if (JAZelAudio::_774 != speed) {
    if (speed < JAZelAudio::_774) {
      speed = speed * JAZelAudio::_775;
    }
    JAIAnimeSound::setAnimSoundVec
              (&this->parent,(JAIBasic *)JAIZelBasic::zel_basic,pPos,time,speed,
               (param_4 & 0xffffff) + (uint)(byte)param_5 * 0x1000000,'\0');
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x802acd14) */
/* __thiscall JAIZelAnime::startAnimSound(void *,
                                          unsigned long,
                                          JAISound * *,
                                          JAInter::Actor *,
                                          unsigned char) */

JAIZelAnime * __thiscall
JAIZelAnime::startAnimSound
          (JAIZelAnime *this,void *param_1,ulong param_2,JAISound **param_3,Actor *param_4,
          uchar param_5)

{
  undefined *puVar1;
  MTX34 *pMtx;
  float *pfVar2;
  undefined *puVar3;
  sbyte sVar4;
  undefined4 uVar5;
  double dVar6;
  double extraout_f1;
  double extraout_f1_00;
  double dVar7;
  undefined8 in_f31;
  cXyz local_34;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if ((*(char *)((int)param_1 + 0x207) != '\0') ||
     ((((*(int *)((int)param_1 + 0x224) == 0x12 && (*(char *)((int)param_1 + 0x238) == ',')) &&
       (*(char *)((int)param_1 + 0x239) == '\t')) && (*(uint *)((int)param_1 + 0x28) < 0x1e))))
  goto LAB_802acd14;
  if ((int)param_2 < 0x48d3) {
    if (param_2 == 0x383c) {
      this = (JAIZelAnime *)
             JAIZelBasic::seStart
                       (JAIZelBasic::zel_basic,0x383c,(cXyz *)param_4->field_0x4,0,0,
                        JAZelAudio::_883,JAZelAudio::_883,JAZelAudio::_775,JAZelAudio::_775,0);
      goto LAB_802acd14;
    }
    if ((0x383b < (int)param_2) && (0x48cf < (int)param_2)) goto LAB_802ac91c;
  }
  else {
    if (param_2 == 0x58f3) {
LAB_802ac91c:
      this = (JAIZelAnime *)
             JAIZelBasic::seStart
                       (JAIZelBasic::zel_basic,param_2,(cXyz *)param_4->field_0x4,0,0,
                        JAZelAudio::_883,JAZelAudio::_883,JAZelAudio::_775,JAZelAudio::_775,0);
      goto LAB_802acd14;
    }
  }
  if (((*(char *)((int)param_1 + 0x201) == '\x01') || (*(char *)((int)param_1 + 0x206) == '\x01'))
     || (((this = (JAIZelAnime *)JAIZelBasic::checkStreamPlaying((JAIZelBasic *)param_1,0xc0000003),
          this != (JAIZelAnime *)0x0 ||
          (((this = (JAIZelAnime *)
                    JAIZelBasic::checkStreamPlaying((JAIZelBasic *)param_1,0xc0000019),
            this != (JAIZelAnime *)0x0 ||
            (this = (JAIZelAnime *)
                    JAIZelBasic::checkStreamPlaying((JAIZelBasic *)param_1,0xc000001a),
            this != (JAIZelAnime *)0x0)) ||
           (this = (JAIZelAnime *)JAIZelBasic::checkStreamPlaying((JAIZelBasic *)param_1,0xc000001b)
           , this != (JAIZelAnime *)0x0)))) && ((param_2 == 0x3800 || (param_2 == 0x3801))))))
  goto LAB_802acd14;
  if (*(char *)((int)param_1 + 0x46) == '\x01') {
    if (param_2 == 0x3815) {
LAB_802aca44:
      param_2 = JA_SE_LK_WALK_HEAVY;
    }
    else {
      if ((int)param_2 < 0x3815) {
        if (param_2 == 0x3801) {
          param_2 = JA_SE_LK_JUMP_HEAVY;
        }
        else {
          if (((int)param_2 < 0x3801) && (0x37ff < (int)param_2)) goto LAB_802aca44;
        }
      }
      else {
        if (param_2 == 0x3818) goto LAB_802aca44;
      }
    }
  }
  else {
    if (param_2 == 0x382f) {
      param_2 = JA_SE_LK_FT_WALK;
    }
  }
  this = (JAIZelAnime *)JAIZelBasic::checkStreamPlaying((JAIZelBasic *)param_1,0xc0000014);
  if (this != (JAIZelAnime *)0x0) {
    puVar1 = param_4->field_0xc;
    if (puVar1 == (undefined *)0x16) goto LAB_802acd14;
    if ((int)puVar1 < 0x16) {
      if (((int)puVar1 < 0x15) && (0x12 < (int)puVar1)) goto LAB_802acd14;
    }
    else {
      if (puVar1 == &DAT_00000018) goto LAB_802acd14;
    }
  }
  puVar1 = param_4->field_0xc;
  param_4->field_0xc = (undefined *)((uint)puVar1 & 0xffffff);
  pfVar2 = (float *)param_4->field_0x4;
  if (pfVar2 != (float *)0x0) {
    pMtx = *(MTX34 **)(*(int *)((int)param_1 + 4) + 8);
    local_34.x = *pfVar2;
    local_34.y = pfVar2[1];
    local_34.z = pfVar2[2];
    mtx::PSMTXMultVec(pMtx,&local_34,&local_34);
    dVar7 = (double)(local_34.z * local_34.z + local_34.x * local_34.x + local_34.y * local_34.y);
    if ((double)JAZelAudio::_774 < dVar7) {
      dVar6 = 1.0 / SQRT(dVar7);
      dVar6 = JAZelAudio::_884 * dVar6 * (JAZelAudio::_885 - dVar7 * dVar6 * dVar6);
      dVar6 = JAZelAudio::_884 * dVar6 * (JAZelAudio::_885 - dVar7 * dVar6 * dVar6);
      dVar7 = (double)(float)(dVar7 * JAZelAudio::_884 * dVar6 *
                                      (JAZelAudio::_885 - dVar7 * dVar6 * dVar6));
    }
    if ((int)param_2 < 0x586c) {
      if (param_2 == JA_SE_CM_KAMOME_WING) {
        this = (JAIZelAnime *)JAIGlobalParameter::getParamDistanceMax((JAIGlobalParameter *)pMtx);
        if (extraout_f1 < dVar7) goto LAB_802acd14;
      }
      else {
        if ((0x57ff < (int)param_2) || (param_2 != JA_SE_CV_KAMOME)) goto LAB_802acbcc;
      }
    }
    else {
      if ((param_2 != JA_SE_CM_DK_FOOTNOTE) && ((0x586f < (int)param_2 || (0x586e < (int)param_2))))
      {
LAB_802acbcc:
        this = (JAIZelAnime *)JAIGlobalParameter::getParamDistanceMax((JAIGlobalParameter *)pMtx);
        if (extraout_f1_00 < dVar7) goto LAB_802acd14;
      }
    }
  }
  puVar3 = param_4->field_0xc;
  sVar4 = (sbyte)((uint)puVar1 >> 0x18);
  if (puVar3 == &DAT_00000010) {
    JAIZelBasic::seStart
              ((JAIZelBasic *)param_1,0x3812,(cXyz *)param_4->field_0x4,0x10,sVar4,JAZelAudio::_883,
               JAZelAudio::_883,JAZelAudio::_775,JAZelAudio::_775,0);
  }
  else {
    if (((int)puVar3 < 0x10) && (0xe < (int)puVar3)) {
      JAIZelBasic::seStart
                ((JAIZelBasic *)param_1,0x3813,(cXyz *)param_4->field_0x4,(ulong)puVar3,sVar4,
                 JAZelAudio::_883,JAZelAudio::_883,JAZelAudio::_775,JAZelAudio::_775,0);
    }
  }
  if (*(char *)((int)param_1 + 0x45) != '\x01') goto LAB_802acccc;
  if (param_2 == JA_SE_FT_LADDER_CLIMB) goto LAB_802acca0;
  if ((int)param_2 < 0x3815) {
    if (param_2 != JA_SE_LK_FT_BOUND) {
      if ((int)param_2 < 0x3802) {
        if (0x37ff < (int)param_2) goto LAB_802acca0;
      }
      else {
        if ((int)param_2 < 0x3804) goto LAB_802acca0;
      }
    }
  }
  else {
    if ((int)param_2 < 0x382f) {
      if (param_2 == JA_SE_FT_LADDER_CLIMB_D) {
LAB_802acca0:
        JAIZelBasic::seStart
                  ((JAIZelBasic *)param_1,0x3831,(cXyz *)param_4->field_0x4,0,sVar4,JAZelAudio::_883
                   ,JAZelAudio::_883,JAZelAudio::_775,JAZelAudio::_775,0);
      }
    }
    else {
      if ((int)param_2 < 0x3831) goto LAB_802acca0;
    }
  }
LAB_802acccc:
  if (*param_3 != (JAISound *)0x0) {
    JAISound::stop(*param_3,0);
  }
  JAIBasic::startSoundActor((JAIBasic *)param_1,param_2,param_3,param_4,0,'\0');
  this = (JAIZelAnime *)*param_3;
  if (this != (JAIZelAnime *)0x0) {
    this = (JAIZelAnime *)
           JAISound::setPortData((JAISound *)this,'\t',(ushort)((uint)puVar1 >> 0x18));
  }
LAB_802acd14:
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return this;
}


/* WARNING: Removing unreachable block (ram,0x802acf80) */
/* __thiscall JAIZelAnime::setSpeedModifySound(JAISound *,
                                               JAIAnimeFrameSoundData *,
                                               float) */

void __thiscall
JAIZelAnime::setSpeedModifySound
          (JAIZelAnime *this,JAISound *param_1,JAIAnimeFrameSoundData *param_2,float param_3)

{
  byte bVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  double local_28;
  double local_20;
  undefined auStack8 [8];
  
  dVar6 = (double)param_3;
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar2 = param_2->mBasePitch;
  if (param_2->mPitch != 0) {
    iVar3 = param_1->field_0x1c;
    if (iVar3 < 0x12) {
      if (iVar3 == 6) goto LAB_802acdc8;
    }
    else {
      if (iVar3 < 0x17) goto LAB_802acdc8;
    }
    local_28 = (double)CONCAT44(0x43300000,(int)(char)param_2->mPitch ^ 0x80000000);
    fVar2 = fVar2 + (float)(local_28 - JAZelAudio::_939) * (float)(dVar6 - (double)JAZelAudio::_883)
                    * JAZelAudio::_933;
  }
LAB_802acdc8:
  JAISound::setPitch(param_1,fVar2,0,'\x05');
  uVar4 = (uint)param_2->mBaseVolume;
  if ((double)JAZelAudio::_774 == dVar6) {
    uVar4 = 0;
  }
  bVar1 = param_2->mVolume;
  if (bVar1 != 0) {
    if (param_1->field_0xc == 0x283e) {
      if (dVar6 < (double)JAZelAudio::_774) {
        dVar6 = (double)(float)(dVar6 * (double)JAZelAudio::_775);
      }
      if ((double)JAZelAudio::_934 <= dVar6) {
        uVar4 = (uint)(JAZelAudio::_935 * (float)(dVar6 - (double)JAZelAudio::_934));
      }
      else {
        uVar4 = 0;
      }
    }
    else {
      if (param_1->field_0x1c == 0x13) {
        local_28 = (double)CONCAT44(0x43300000,(int)(char)bVar1 ^ 0x80000000);
        uVar4 = uVar4 + (int)((float)(local_28 - JAZelAudio::_939) *
                             (float)(dVar6 - (double)JAZelAudio::_883));
      }
      else {
        local_20 = (double)CONCAT44(0x43300000,(int)(char)bVar1 ^ 0x80000000);
        uVar4 = uVar4 + (int)(JAZelAudio::_936 * (float)(local_20 - JAZelAudio::_939) *
                             (float)(dVar6 - (double)JAZelAudio::_883));
      }
    }
    if ((short)uVar4 < 0x80) {
      if ((short)uVar4 < 0) {
        uVar4 = 0;
      }
    }
    else {
      uVar4 = 0x7f;
    }
  }
  if (param_1->field_0xc == 0x283e) {
    if (param_1->field_0x18 < 2) {
      local_20 = (double)CONCAT44(0x43300000,uVar4 & 0xff);
      JAISound::setVolume(param_1,(float)(local_20 - JAZelAudio::_941) / JAZelAudio::_937,0,5);
    }
  }
  else {
    local_20 = (double)CONCAT44(0x43300000,uVar4 & 0xff);
    JAISound::setVolume(param_1,(float)(local_20 - JAZelAudio::_941) / JAZelAudio::_937,0,5);
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* __thiscall JAIZelAnime::setPlayPosition(float) */

void __thiscall JAIZelAnime::setPlayPosition(JAIZelAnime *this,float param_1)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  ulong uVar4;
  
  puVar3 = (this->parent).mpData;
  if (puVar3 == (ushort *)0x0) {
    return;
  }
  uVar1 = (uint)*puVar3;
  uVar4 = 0;
  for (iVar2 = 0; (uVar1 != 0 && (*(float *)((int)puVar3 + iVar2 + 0xc) < param_1));
      iVar2 = iVar2 + 0x20) {
    uVar4 = uVar4 + 1;
    uVar1 = uVar1 - 1;
  }
  if ((this->parent).mDataCounterInc != 1) {
    (this->parent).mDataCounter = uVar4;
    (this->parent).mCurrentTime = param_1;
    return;
  }
  (this->parent).mDataCounter = uVar4;
  (this->parent).mCurrentTime = param_1;
  return;
}

