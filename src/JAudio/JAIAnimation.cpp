#include <JAudio/JAIAnimation.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JAudio/JAISound.h>
#include <JAudio/JAIAnimation.h>
#include <m_Do_printf.h>
#include <JUtility/JUTAssert.h>
#include <JAudio/JAIBasic.h>
#include <JAIAnimeSound.h>


/* __thiscall JAIAnimeSound::JAIAnimeSound(void) */

void __thiscall JAIAnimeSound::JAIAnimeSound(JAIAnimeSound *this)

{
  JAIAnimeSound__Slot *pEntry;
  byte bVar1;
  
  this->vtbl = (undefined *)&__vt;
  this->field_0x60 = 0;
  this->field_0x64 = 0;
  this->field_0x68 = 0;
  this->field_0x6c = 0;
  for (bVar1 = 0; bVar1 < 8; bVar1 = bVar1 + 1) {
    pEntry = this->mSlots + bVar1;
    pEntry->mpSound = (JAISound *)0x0;
    pEntry->mbIsPlaying = 0;
  }
  for (bVar1 = 0; bVar1 < 2; bVar1 = bVar1 + 1) {
    this->field_0x70[bVar1] = (undefined *)0x0;
  }
  this->mDataCounter = 0;
  this->mLoopCount = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JAIAnimeSound::initActorAnimSound(void *,
                                                unsigned long,
                                                float) */

void __thiscall
JAIAnimeSound::initActorAnimSound(JAIAnimeSound *this,void *pData,ulong direction,float loopFrame)

{
  uint numEntries;
  int iVar1;
  ulong uVar2;
  JAISound *this_00;
  byte bVar3;
  JAIAnimeSound__Slot *pJVar5;
  
  uVar2 = 0;
  iVar1 = 0;
  this->mpData = (ushort *)pData;
  if (this->mpData != (ushort *)0x0) {
    this->mDataCounter = 0;
    this->mDataCounterInc = direction;
    numEntries = (uint)*this->mpData;
    for (; (numEntries != 0 && (*(float *)((int)this->mpData + iVar1 + 0xc) < loopFrame));
        iVar1 = iVar1 + 0x20) {
      uVar2 = uVar2 + 1;
      numEntries = numEntries - 1;
    }
    if (direction == 1) {
      this->mDataCounter = 0;
      this->mDataCounterLimit = uVar2;
      this->mCurrentTime = JAudio::_797;
      this->mLoopCount = 0;
    }
    else {
      this->mDataCounter = uVar2;
      this->mDataCounterLimit = 0;
      this->mCurrentTime = JAudio::_797;
      this->mLoopCount = -1;
    }
  }
  for (bVar3 = 0; bVar3 < 8; bVar3 = bVar3 + 1) {
    pJVar5 = this->mSlots + bVar3;
    this_00 = pJVar5->mpSound;
    if ((this_00 != (JAISound *)0x0) && ((*(uint *)(pJVar5->mpData + 0x10) & 4) != 0)) {
      JAISound::stop(this_00,1);
      pJVar5->mbIsPlaying = 0;
    }
    if (this_00 == (JAISound *)0x0) {
      pJVar5->mbIsPlaying = 0;
    }
    else {
      if ((this_00->field_0xc & 0xc00U) == 0) {
        JAISound::stop(this_00,0);
        pJVar5->mbIsPlaying = 0;
      }
      else {
        pJVar5->mbIsPlaying = 2;
      }
    }
  }
  return;
}


/* __thiscall JAIAnimeSound::setAnimSoundVec(JAIBasic *,
                                             Vec *,
                                             float,
                                             float,
                                             unsigned long,
                                             unsigned char) */

void __thiscall
JAIAnimeSound::setAnimSoundVec
          (JAIAnimeSound *this,JAIBasic *param_1,cXyz *param_2,float time,float speed,ulong param_5,
          uchar param_6)

{
  Actor local_18;
  
  local_18.field_0x0 = (undefined *)param_2;
  local_18.field_0x4 = (undefined *)param_2;
  local_18.field_0x8 = (undefined *)param_2;
  local_18.field_0xc = (undefined *)param_5;
  setAnimSoundActor(this,param_1,&local_18,time,speed,param_6);
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x8028f790) */
/* WARNING: Removing unreachable block (ram,0x8028f798) */
/* __thiscall JAIAnimeSound::setAnimSoundActor(JAIBasic *,
                                               JAInter::Actor *,
                                               float,
                                               float,
                                               unsigned char) */

void __thiscall
JAIAnimeSound::setAnimSoundActor
          (JAIAnimeSound *this,JAIBasic *pBasic,Actor *pActor,float time,float speed,uchar param_5)

{
  undefined3 in_register_00000018;
  undefined *_afsdata_;
  JAISound **pSound;
  byte bVar1;
  undefined *_afsdata;
  uint numEntries;
  ushort *pData;
  JAIAnimeSound__Slot *pSlot;
  undefined4 uVar2;
  double endTime;
  double dVar3;
  double startTime;
  double dVar4;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar4 = (double)speed;
  dVar3 = (double)time;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  pData = this->mpData;
  if (pData != (ushort *)0x0) {
    numEntries = (uint)*pData;
    if (this->mDataCounterInc == 1) {
      if (dVar3 < (double)this->mCurrentTime) {
        while ((this->mDataCounter < numEntries &&
               (*(float *)(pData + this->mDataCounter * 0x10 + 6) <=
                (float)((double)this->mCurrentTime + dVar4)))) {
          playActorAnimSound(this,pBasic,pActor,(float)dVar4,param_5);
        }
        this->mDataCounter = this->mDataCounterLimit;
        this->mCurrentTime = (float)dVar3;
        if ((uint)this->mLoopCount < 0x100) {
          this->mLoopCount = this->mLoopCount + 1;
        }
      }
      for (bVar1 = 0; bVar1 < 8; bVar1 = bVar1 + 1) {
        pSlot = this->mSlots + bVar1;
        pSound = &pSlot->mpSound;
        if (pSlot->mbIsPlaying == 1) {
          _afsdata_ = pSlot->mpData;
          if (_afsdata_ == (undefined *)0x0) {
            m_Do_printf::OSReport
                      (
                      "JAIAnimeSound::setAnimSoundActor 正方向再生中にafsDataがNULLに！！\n"
                      );
            JUTAssertion::showAssert(3,"JAIAnimation.cpp",0x9d,"_afsdata");
            m_Do_printf::OSPanic("JAIAnimation.cpp",0x9d,&DAT_80368a46);
          }
          if (((*(uint *)_afsdata_ & 0xc00) == 0) &&
             (((double)JAudio::_797 != dVar4 || ((*(uint *)(_afsdata_ + 0x10) & 0x20) == 0)))) {
            startTime = (double)*(float *)(_afsdata_ + 4);
            endTime = (double)*(float *)(_afsdata_ + 8);
            if ((startTime == endTime) ||
               ((((startTime < endTime && (dVar3 < endTime)) && (startTime <= dVar3)) ||
                ((endTime < startTime && ((dVar3 < endTime || (startTime < dVar3)))))))) {
              (**(code **)(this->vtbl + 8))
                        (this,pBasic,*(uint *)_afsdata_,pSound,pActor,
                         CONCAT31(in_register_00000018,param_5));
            }
            else {
              pSlot->mbIsPlaying = 0;
              if (*pSound != (JAISound *)0x0) {
                JAISound::stop(*pSound,0);
              }
            }
          }
          if (((*pSound != (JAISound *)0x0) &&
              ((**(code **)(this->vtbl + 0xc))(dVar4,this,*pSound,_afsdata_),
              (*(uint *)(_afsdata_ + 0x10) & 0x10) != 0)) &&
             ((double)*(float *)(_afsdata_ + 8) <= dVar3)) {
            JAISound::stop(*pSound,1);
          }
        }
      }
      while ((this->mDataCounter < numEntries &&
             ((double)*(float *)(pData + this->mDataCounter * 0x10 + 6) <= dVar3))) {
        playActorAnimSound(this,pBasic,pActor,(float)dVar4,param_5);
      }
    }
    else {
      if ((double)this->mCurrentTime < dVar3) {
        while ((this->mDataCounter < numEntries &&
               ((float)((double)this->mCurrentTime - dVar4) <=
                *(float *)(pData + this->mDataCounter * 0x10 + 6)))) {
          playActorAnimSound(this,pBasic,pActor,(float)dVar4,param_5);
        }
        this->mDataCounter = numEntries - 1;
        this->mCurrentTime = (float)dVar3;
        if ((this->mLoopCount == 0xffffffff) || ((uint)this->mLoopCount < 0x100)) {
          this->mLoopCount = this->mLoopCount + 1;
        }
      }
      for (bVar1 = 0; bVar1 < 8; bVar1 = bVar1 + 1) {
        pSlot = this->mSlots + bVar1;
        pSound = &pSlot->mpSound;
        if (pSlot->mbIsPlaying == 1) {
          _afsdata = pSlot->mpData;
          if (_afsdata == (undefined *)0x0) {
            m_Do_printf::OSReport
                      (
                      "JAIAnimeSound::setAnimSoundActor 逆方向再生中にafsDataがNULLに！！\n"
                      );
            JUTAssertion::showAssert(3,"JAIAnimation.cpp",0xe0,"_afsdata");
            m_Do_printf::OSPanic("JAIAnimation.cpp",0xe0,&DAT_80368a46);
          }
          if (((*(uint *)_afsdata & 0xc00) == 0) &&
             (((double)JAudio::_797 != dVar4 || ((*(uint *)(_afsdata + 0x10) & 0x20) == 0)))) {
            startTime = (double)*(float *)(_afsdata + 4);
            endTime = (double)*(float *)(_afsdata + 8);
            if (((startTime == endTime) ||
                (((endTime < startTime && (endTime < dVar3)) && (dVar3 < startTime)))) ||
               ((startTime < endTime && ((endTime < dVar3 || (dVar3 < startTime)))))) {
              (**(code **)(this->vtbl + 8))
                        (this,pBasic,*(uint *)_afsdata,pSound,pActor,
                         CONCAT31(in_register_00000018,param_5));
            }
            else {
              pSlot->mbIsPlaying = 0;
              if (*pSound != (JAISound *)0x0) {
                JAISound::stop(*pSound,0);
              }
            }
          }
          if (((*pSound != (JAISound *)0x0) &&
              ((**(code **)(this->vtbl + 0xc))(dVar4,this,*pSound,_afsdata),
              (*(uint *)(_afsdata + 0x10) & 0x10) != 0)) &&
             (dVar3 <= (double)*(float *)(_afsdata + 8))) {
            JAISound::stop(*pSound,1);
          }
        }
      }
      while ((this->mDataCounter < numEntries &&
             (dVar3 <= (double)*(float *)(pData + this->mDataCounter * 0x10 + 6)))) {
        playActorAnimSound(this,pBasic,pActor,(float)dVar4,param_5);
      }
    }
    this->mCurrentTime = (float)dVar3;
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x8028fa40) */
/* __thiscall JAIAnimeSound::playActorAnimSound(JAIBasic *,
                                                JAInter::Actor *,
                                                float,
                                                unsigned char) */

void __thiscall
JAIAnimeSound::playActorAnimSound
          (JAIAnimeSound *this,JAIBasic *pBasic,Actor *pActor,float speed,uchar param_4)

{
  JAISound *iVar1;
  uint flag;
  undefined3 in_register_00000018;
  JAISound **pSound;
  undefined *pDataEntry;
  undefined *pData;
  byte slot;
  JAIAnimeSound__Slot *pEntry;
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar2 = (double)speed;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  slot = 0;
  pData = (undefined *)this->mpData;
  if (((uint)*(ushort *)pData <= this->mDataCounter) &&
     (m_Do_printf::OSReport("JAIAnimeSound::playActorAnimSound  dataCounterが異常です。\n"),
     (uint)*(ushort *)pData <= this->mDataCounter)) {
    JUTAssertion::showAssert
              (3,"JAIAnimation.cpp",0x112,"(dataCounter>=0 && dataCounter<_asdata->datas)");
    m_Do_printf::OSPanic("JAIAnimation.cpp",0x112,&DAT_80368a46);
  }
  pDataEntry = pData + this->mDataCounter * 0x20 + 8;
  while( true ) {
    if ((7 < slot) || (this->mSlots[slot].mbIsPlaying == 0)) goto LAB_8028f8d8;
    iVar1 = this->mSlots[slot].mpSound;
    if ((iVar1 == (JAISound *)0x0) || (*(int *)pDataEntry == iVar1->field_0xc)) break;
    slot = slot + 1;
  }
  if ((*(uint *)pDataEntry & 0xc00) == 0) {
    this->mDataCounter = this->mDataCounter + this->mDataCounterInc;
    goto LAB_8028fa40;
  }
LAB_8028f8d8:
  if (((slot != 8) &&
      ((flag = *(uint *)(pDataEntry + 0x10), (flag & 8) == 0 ||
       (this->mLoopCount == (uint)(byte)pDataEntry[0x16])))) &&
     (((this->mDataCounterInc == 1 && ((flag & 2) == 0)) ||
      ((this->mDataCounterInc == -1 && ((flag & 1) == 0)))))) {
    pEntry = this->mSlots + slot;
    pSound = &pEntry->mpSound;
    (**(code **)(this->vtbl + 8))
              (this,pBasic,*(undefined4 *)pDataEntry,pSound,pActor,
               CONCAT31(in_register_00000018,param_4));
    if (*pSound != (JAISound *)0x0) {
      pEntry->mpData = pDataEntry;
      pEntry->mbIsPlaying = 1;
      JAISound::setVolume(*pSound,(float)((double)CONCAT44(0x43300000,(uint)(byte)pDataEntry[0x14])
                                         - JAudio::_979) / JAudio::_975,0,5);
      JAISound::setPitch(*pSound,*(float *)(pDataEntry + 0xc) +
                                 (float)((double)CONCAT44(0x43300000,
                                                          (int)(char)pDataEntry[0x15] ^ 0x80000000)
                                        - JAudio::_981) * (float)(dVar2 - (double)JAudio::_976) *
                                 JAudio::_977,0,'\x05');
      JAISound::setPan(*pSound,(float)((double)CONCAT44(0x43300000,(uint)(byte)pDataEntry[0x17]) -
                                      JAudio::_979) / JAudio::_975,0,'\x05');
    }
  }
  this->mDataCounter = this->mDataCounter + this->mDataCounterInc;
LAB_8028fa40:
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}


/* __thiscall JAIAnimeSound::startAnimSound(void *,
                                            unsigned long,
                                            JAISound * *,
                                            JAInter::Actor *,
                                            unsigned char) */

void __thiscall
JAIAnimeSound::startAnimSound
          (JAIAnimeSound *this,void *param_1,ulong param_2,JAISound **param_3,Actor *param_4,
          uchar param_5)

{
  JAIBasic::startSoundActor((JAIBasic *)param_1,param_2,param_3,param_4,0,param_5);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8028fbc0) */
/* __thiscall JAIAnimeSound::setSpeedModifySound(JAISound *,
                                                 JAIAnimeFrameSoundData *,
                                                 float) */

void __thiscall
JAIAnimeSound::setSpeedModifySound
          (JAIAnimeSound *this,JAISound *param_1,JAIAnimeFrameSoundData *param_2,float param_3)

{
  float fVar1;
  uint uVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  double local_20;
  undefined auStack8 [8];
  
  dVar4 = (double)param_3;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar1 = param_2->mBasePitch;
  if (param_2->mPitch != 0) {
    fVar1 = fVar1 + (float)((double)CONCAT44(0x43300000,(int)(char)param_2->mPitch ^ 0x80000000) -
                           JAudio::_981) * (float)(dVar4 - (double)JAudio::_976) * JAudio::_977;
  }
  JAISound::setPitch(param_1,fVar1,0,'\x05');
  uVar2 = (uint)param_2->mBaseVolume;
  if (param_2->mPitch != 0) {
    uVar2 = uVar2 + (int)(JAudio::_1002 *
                          (float)((double)CONCAT44(0x43300000,
                                                   (int)(char)param_2->mVolume ^ 0x80000000) -
                                 JAudio::_981) * (float)(dVar4 - (double)JAudio::_976));
    if ((short)uVar2 < 0x80) {
      if ((short)uVar2 < 0) {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0x7f;
    }
  }
  local_20 = (double)CONCAT44(0x43300000,uVar2 & 0xff);
  JAISound::setVolume(param_1,(float)(local_20 - JAudio::_979) / JAudio::_975,0,5);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __thiscall JAIAnimeSound::stop(void) */

void __thiscall JAIAnimeSound::stop(JAIAnimeSound *this)

{
  JAISound *this_00;
  byte bVar1;
  
  for (bVar1 = 0; bVar1 < 8; bVar1 = bVar1 + 1) {
    this_00 = this->mSlots[bVar1].mpSound;
    if (this_00 != (JAISound *)0x0) {
      JAISound::stop(this_00,0);
    }
  }
  return;
}

