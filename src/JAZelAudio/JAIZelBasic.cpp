#include <JAZelAudio/JAIZelBasic.h>
#include <JAudio/JAIBasic.h>
#include <JMath/random.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <JAudio/JAISound.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <m_Do_printf.h>
#include <JAudio/JAISequenceMgr.h>
#include <JAudio/JAIGlobalParameter.h>
#include <JAudio/JASTrack.h>
#include <mtx/mtxvec.h>
#include <JAZelAudio/JAIZelAtmos.h>
#include <d_save.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JAudio/JASWaveBankMgr.h>
#include <JAudio/JAIBankWave.h>
#include <JAudio/JAIStreamMgr.h>
#include <JKernel/JKRHeap.h>
#include <JAZelAudio/JAIZelSound.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JAIZelSound.h>
#include <JAIZelBasic.h>

struct JAIZelBasic * JAIZelBasic;

/* __thiscall JAIZelBasic::JAIZelBasic(void) */

void __thiscall JAIZelBasic::JAIZelBasic(JAIZelBasic *this)

{
  float fVar1;
  
  JAIBasic::JAIBasic((JAIBasic *)this);
  this->vtbl = &__vt;
  JKernel::JMath::TRandom_enough_::setSeed((TRandom_enough_ *)&this->field_0x2068,0);
  zel_basic = this;
  this->field_0x21 = 0;
  this->field_0x24 = 0;
  this->mpSound = (JAISound *)0x0;
  this->field_0x20 = 0;
  this->field_0x74 = -1;
  this->field_0x78 = 0xffffffff;
  this->field_0x7c = 0xffffffff;
  fVar1 = JAZelAudio::1_0;
  this->field_0x80 = JAZelAudio::1_0;
  this->field_0x84 = fVar1;
  this->field_0x88 = fVar1;
  this->field_0x8c = fVar1;
  this->field_0x90 = fVar1;
  this->field_0x94 = fVar1;
  this->field_0x98 = fVar1;
  this->field_0x9c = fVar1;
  this->field_0xa0 = fVar1;
  this->field_0xa4 = fVar1;
  this->field_0xac = fVar1;
  this->field_0xa8 = fVar1;
  this->field_0x2c = 0;
  this->field_0x2d = 0;
  this->field_0x2e = 0;
  this->field_0x2f = 0;
  this->field_0x30 = 0xc00;
  this->field_0x32 = 0;
  this->field_0x34 = 0;
  this->field_0x38 = 0;
  this->field_0x3c = fVar1;
  this->field_0x41 = 0;
  this->field_0x42 = 0;
  this->field_0x43 = 0;
  this->field_0x44 = 0;
  this->field_0x45 = 0;
  this->field_0x46 = 0;
  this->field_0x47 = 0;
  fVar1 = JAZelAudio::_4003;
  this->field_0x48 = JAZelAudio::_4003;
  this->field_0x4c = fVar1;
  this->field_0x50 = fVar1;
  this->field_0x54 = fVar1;
  this->field_0x58 = fVar1;
  this->field_0x5c = fVar1;
  *(undefined4 *)&this->field_0xd0 = 0;
  this->field_0x63 = 0;
  this->field_0xb0 = -1;
  this->mSomeSpecialBGMFlag = 0;
  this->mLastMinibossSubBGMType = 0;
  *(undefined *)&this->field_0x1f3c = 0;
  *(undefined *)&this->field_0x1f8 = 0;
  this->field_0x201 = 0;
  *(undefined *)&this->field_0x204 = 0;
  *(undefined *)&this->field_0x64 = 0;
  *(undefined *)&this->field_0x65 = 0;
  *(undefined *)&this->field_0xb8 = 0;
  *(undefined *)&this->field_0xba = 0;
  *(undefined *)&this->field_0xbb = 0;
  *(undefined *)&this->field_0x206 = 0;
  this->field_0x1f9 = 0;
  *(undefined *)&this->field_0x1fa = 0;
  *(undefined *)&this->field_0x202 = 0;
  *(undefined *)&this->field_0x203 = 0;
  *(undefined *)&this->field_0x1fb = 0;
  *(undefined *)&this->field_0x1fc = 0;
  *(undefined *)&this->field_0x23a = 0;
  *(undefined4 *)&this->field_0x220 = 0xffffffff;
  this->field_0x224 = -1;
  this->mNextSceneBgmId = 0;
  this->field_0x22e = 0;
  this->field_0x22f = 0;
  this->field_0x230 = 0;
  this->field_0x231 = 0;
  this->mFirstDynamicSceneWaveIndex = 0;
  this->field_0x233 = 0;
  this->mSetNum = 0;
  this->mSecondDynamicSceneWaveIndex = 0;
  this->field_0x236 = 0;
  this->field_0x237 = 0;
  *(undefined *)&this->field_0x22c = 0;
  this->field_0x22d = 0;
  *(undefined *)&this->field_0xb4 = 0;
  this->field_0xbc = 0;
  *(undefined *)&this->field_0xc0 = 0;
  *(undefined *)&this->field_0xc1 = 0;
  *(undefined4 *)&this->field_0xc4 = 0;
  *(undefined *)&this->field_0xc8 = 0;
  *(undefined *)&this->field_0xc9 = 0;
  this->field_0xca = 0;
  this->mCameraSeaFloorGroupInfo = 0;
  this->mIslandRoomNo = 0;
  this->mLinkSeaFloorGroupInfo = 0;
  this->field_0x21e = 0;
  *(undefined *)&this->field_0xcb = 0xff;
  *(undefined *)&this->field_0xcc = 0;
  *(undefined *)&this->field_0x1dd4 = 0;
  *(undefined *)&this->field_0xb9 = 0;
  *(undefined *)&this->field_0xcd = 0;
  *(undefined *)&this->field_0x33 = 0;
  this->mIsSailing = 0;
  this->field_0x1f40 = JAZelAudio::_4004;
  *(undefined *)&this->field_0xb7 = 0;
  *(undefined *)&this->field_0x40 = 0;
  *(undefined *)&this->field_0x207 = 0;
  this->mbLandingDemoStarted = 0;
  *(undefined *)&this->field_0x239 = 0;
  *(undefined *)&this->field_0x208 = 0;
  *(undefined4 *)&this->field_0x1ec0 = 0;
  *(undefined *)&this->field_0xce = 0;
  *(undefined *)&this->field_0xbd = 0;
  this->field_0xbe = 0;
  *(undefined *)&this->field_0x61 = 0;
  *(undefined *)&this->field_0x1fd = 0;
  *(undefined *)&this->field_0x1fe = 0;
  *(undefined *)&this->field_0x1ff = 0;
  *(undefined *)&this->field_0x200 = 0;
  *(undefined *)&this->field_0x205 = 0;
  this->field_0x66 = 0;
  *(undefined *)&this->field_0xbf = 0;
  *(undefined4 *)&this->field_0x28 = 0;
  *(undefined *)&this->field_0x62 = 0;
  return;
}


/* WARNING: Removing unreachable block (ram,0x802a2f20) */
/* WARNING: Removing unreachable block (ram,0x802a2f28) */
/* __thiscall JAIZelBasic::zeldaGFrameWork(void) */

void __thiscall JAIZelBasic::zeldaGFrameWork(JAIZelBasic *this)

{
  byte bVar1;
  char cVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  uint bgmId;
  undefined1 *puVar6;
  undefined *puVar7;
  undefined4 uVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (this->field_0x22d == 0) {
    *(undefined4 *)&this->field_0x28 = 0;
  }
  else {
    if (*(int *)&this->field_0x28 == -1) {
      *(undefined4 *)&this->field_0x28 = 0xffffffff;
    }
    else {
      *(int *)&this->field_0x28 = *(int *)&this->field_0x28 + 1;
    }
  }
  processLevObjSE(this);
  cbPracticeProcess(this);
  *(undefined4 *)&this->field_0x1f34 = 0;
  this->field_0x1f9 = 0;
  *(undefined *)&this->field_0x1fb = 0;
  *(undefined *)&this->field_0x1fc = 0;
  if (*(char *)&this->field_0x1fa == '\0') {
    *(undefined *)&this->field_0x1fa = 0;
  }
  else {
    *(char *)&this->field_0x1fa = *(char *)&this->field_0x1fa + -1;
  }
  if (*(char *)&this->field_0x202 == '\0') {
    *(undefined *)&this->field_0x202 = 0;
  }
  else {
    *(char *)&this->field_0x202 = *(char *)&this->field_0x202 + -1;
  }
  if (*(char *)&this->field_0x203 == '\0') {
    *(undefined *)&this->field_0x203 = 0;
  }
  else {
    *(char *)&this->field_0x203 = *(char *)&this->field_0x203 + -1;
  }
  if (*(char *)&this->field_0x207 == '\0') {
    *(undefined *)&this->field_0x207 = 0;
  }
  else {
    *(char *)&this->field_0x207 = *(char *)&this->field_0x207 + -1;
  }
  if (*(char *)&this->field_0x1fd == '\0') {
    *(undefined *)&this->field_0x1fd = 0;
  }
  else {
    *(char *)&this->field_0x1fd = *(char *)&this->field_0x1fd + -1;
  }
  if (*(char *)&this->field_0x1fe == '\0') {
    *(undefined *)&this->field_0x1fe = 0;
  }
  else {
    *(char *)&this->field_0x1fe = *(char *)&this->field_0x1fe + -1;
  }
  if (*(char *)&this->field_0x1ff == '\0') {
    *(undefined *)&this->field_0x1ff = 0;
  }
  else {
    *(char *)&this->field_0x1ff = *(char *)&this->field_0x1ff + -1;
  }
  if (*(char *)&this->field_0x200 == '\0') {
    *(undefined *)&this->field_0x200 = 0;
  }
  else {
    *(char *)&this->field_0x200 = *(char *)&this->field_0x200 + -1;
  }
  *(undefined *)&this->field_0x203c = 0;
  *(undefined *)&this->field_0x203d = 0;
  *(undefined4 *)&this->field_0x1e98 = 0;
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
    if (*(char *)&this->field_0x61 == '\0') {
      *(undefined *)&this->field_0x61 = 0;
    }
    else {
      *(char *)&this->field_0x61 = *(char *)&this->field_0x61 + -1;
    }
  }
  else {
    *(undefined *)&this->field_0x61 = 5;
  }
  if (*(char *)&this->field_0xce == '\0') {
    *(undefined *)&this->field_0xce = 0;
  }
  else {
    *(char *)&this->field_0xce = *(char *)&this->field_0xce + -1;
  }
  processDemoFanfareMute(this);
  if ((this->field_0x78 == 0x8000000f) && (iVar5 = checkBgmPlaying(this), iVar5 == 0)) {
    bgmStop(this,0,0);
    bgmStart(this,0x80000007,0,0);
  }
  puVar6 = (undefined1 *)this->field_0x74;
  if ((int)puVar6 < -0x7fffffd0) {
    if (puVar6 == (undefined1 *)0x80000026) goto LAB_802a2224;
    if ((int)puVar6 < -0x7fffffda) {
      if ((puVar6 != &DAT_80000002) && (((int)puVar6 < -0x7ffffffe || ((int)puVar6 < -0x7fffffdc))))
      goto LAB_802a2224;
    }
    else {
      if (-0x7fffffd9 < (int)puVar6) goto LAB_802a2224;
    }
  }
  else {
    if (puVar6 != &DAT_8000004f) {
      if ((int)puVar6 < -0x7fffffb1) {
        if (-0x7fffffce < (int)puVar6) goto LAB_802a2224;
      }
      else {
        if (puVar6 != &DAT_8000005d) goto LAB_802a2224;
      }
    }
  }
  iVar5 = checkSubBgmPlaying(this);
  if (iVar5 == 0) {
    *(undefined *)&this->field_0x206 = 0;
    if (*(char *)&this->field_0xbb == '\0') {
      *(undefined *)&this->field_0xbb = 0;
    }
    else {
      if (*(char *)&this->field_0xbb == '\x01') {
        bVar1 = this->mLastMinibossSubBGMType;
        if (bVar1 == 1) {
          subBgmStart(this,(ulong)&DAT_8000001a);
        }
        else {
          if (bVar1 == 2) {
            subBgmStart(this,0x80000046);
          }
          else {
            if (bVar1 == 3) {
              subBgmStart(this,0x80000047);
            }
            else {
              this->field_0xb0 = -2;
              subBgmStopInner(this);
            }
          }
        }
      }
      *(char *)&this->field_0xbb = *(char *)&this->field_0xbb + -1;
    }
  }
LAB_802a2224:
  puVar7 = (undefined *)this->field_0x78;
  if (puVar7 == (undefined *)0x80000045) {
    iVar5 = checkBgmPlaying(this);
    if (iVar5 == 0) {
      bgmStart(this,0x8000003f,0,1);
    }
  }
  else {
    if ((((int)puVar7 < -0x7fffffbb) && (puVar7 == &DAT_80000013)) &&
       (iVar5 = checkBgmPlaying(this), iVar5 == 0)) {
      bgmStart(this,(uint)&DAT_80000017,0,1);
    }
  }
  iVar5 = this->field_0xb0;
  if (iVar5 != -1) {
    if (iVar5 < 1) {
      subBgmStopInner(this);
      this->field_0xb0 = -1;
    }
    else {
      this->field_0xb0 = iVar5 + -1;
    }
  }
  if ((undefined1 *)this->field_0x78 == &DAT_80000006) {
    if (*(char *)&this->field_0x65 == '\x01') {
      this->field_0x90 = JAZelAudio::_4004;
      if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
        JAISound::setVolume(*(JAISound **)&this->field_0x68,
                            this->field_0xac *
                            this->field_0x9c *
                            this->field_0x98 *
                            this->field_0x94 *
                            this->field_0x90 *
                            this->field_0x8c *
                            this->field_0x88 * this->field_0x80 * this->field_0x84,0x1e,0);
      }
      *(undefined *)&this->field_0x65 = 0;
    }
    else {
      if (JAZelAudio::_4004 == this->field_0x90) {
        this->field_0x90 = JAZelAudio::1_0;
        if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
          JAISound::setVolume(*(JAISound **)&this->field_0x68,
                              this->field_0xac *
                              this->field_0x9c *
                              this->field_0x98 *
                              this->field_0x94 *
                              this->field_0x90 *
                              this->field_0x8c *
                              this->field_0x88 * this->field_0x80 * this->field_0x84,0x1e,0);
        }
      }
    }
  }
  iVar5 = isDemo(this);
  if ((iVar5 == 1) && (iVar5 = checkSeqIDDemoPlaying(this,(ulong)&DAT_80000044), iVar5 != 0)) {
    bgmStart(this,(uint)&DAT_80000044,0,0);
  }
  if ((this->field_0x224 == 0x21) && (this->field_0x22d == 1)) {
    fVar3 = JAZelAudio::_4004;
    if (**(int **)&this->field_0x4 != 0) {
      fVar3 = *(float *)(**(int **)&this->field_0x4 + 4);
    }
    if (JAZelAudio::_4339 <= fVar3) {
      if (JAZelAudio::_4340 <= fVar3) {
        dVar10 = (double)JAZelAudio::1_0;
      }
      else {
        dVar10 = (double)((fVar3 - JAZelAudio::_4339) / JAZelAudio::_4341);
      }
    }
    else {
      dVar10 = (double)JAZelAudio::_4004;
    }
    if ((double)JAZelAudio::_4004 != dVar10) {
      JAIBasic::startSoundVec
                ((JAIBasic *)this,JA_SE_ATM_WIND_I_LINK,(JAISound **)&this->field_0x1f38,(Vec *)0x0,
                 0,0,'\x04');
      if (*(JAISound **)&this->field_0x1f38 != (JAISound *)0x0) {
        JAISound::setVolume(*(JAISound **)&this->field_0x1f38,(float)dVar10,0,0);
      }
    }
  }
  iVar5 = this->field_0x224;
  if (((iVar5 == 0x12) || (iVar5 == 0x55)) || (iVar5 == 0x13)) {
    dVar10 = (double)JAZelAudio::_4004;
    if (this->field_0x22d == 1) {
      if (**(int **)&this->field_0x4 != 0) {
        dVar10 = (double)*(float *)(**(int **)&this->field_0x4 + 4);
      }
      if ((double)JAZelAudio::_4339 <= dVar10) {
        if ((double)JAZelAudio::_4340 <= dVar10) {
          dVar9 = (double)JAZelAudio::1_0;
        }
        else {
          dVar9 = (double)((float)(dVar10 - (double)JAZelAudio::_4339) / JAZelAudio::_4341);
        }
      }
      else {
        dVar9 = (double)JAZelAudio::_4004;
      }
      if ((this->mIslandRoomNo == 0xb) && (iVar5 = isDemo(this), iVar5 == 1)) {
        dVar9 = (double)JAZelAudio::_4004;
      }
      if (((double)JAZelAudio::_4004 != dVar9) &&
         (iVar5 = checkPlayingStreamBgmFlag(this), iVar5 != -0x3fffffca)) {
        JAIBasic::startSoundVec
                  ((JAIBasic *)this,JA_SE_ATM_WIND_I_LINK,(JAISound **)&this->field_0x1f38,
                   (Vec *)0x0,0,0,'\x04');
        if (*(JAISound **)&this->field_0x1f38 != (JAISound *)0x0) {
          JAISound::setVolume(*(JAISound **)&this->field_0x1f38,(float)dVar9,0,0);
        }
      }
    }
    if ((this->mIslandRoomNo == 0x2c) && (iVar5 = checkEventBit(this,1), iVar5 == 1)) {
      fVar3 = JAZelAudio::1_0;
      if ((((undefined *)this->field_0x78 != &DAT_8000000a) && ((double)JAZelAudio::_4342 <= dVar10)
          ) && (fVar3 = JAZelAudio::_4004, dVar10 < (double)JAZelAudio::_4343)) {
        fVar3 = JAZelAudio::1_0 - (float)(dVar10 - (double)JAZelAudio::_4342) / JAZelAudio::_4344;
      }
      this->field_0xac = fVar3;
      if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
        JAISound::setVolume(*(JAISound **)&this->field_0x68,
                            this->field_0xac *
                            this->field_0x9c *
                            this->field_0x98 *
                            this->field_0x94 *
                            this->field_0x90 *
                            this->field_0x8c *
                            this->field_0x88 * this->field_0x80 * this->field_0x84,0,0);
      }
    }
    else {
      if (this->mIslandRoomNo == 0xd) {
        fVar3 = JAZelAudio::1_0;
        if ((((undefined *)this->field_0x78 != &DAT_8000000a) && (this->mbLandingDemoStarted != 2))
           && (((double)JAZelAudio::_4342 <= dVar10 &&
               (fVar3 = JAZelAudio::_4345, dVar10 < (double)JAZelAudio::_4343)))) {
          fVar3 = JAZelAudio::_4345 +
                  JAZelAudio::_4346 *
                  (JAZelAudio::1_0 - (float)(dVar10 - (double)JAZelAudio::_4342) / JAZelAudio::_4344
                  );
        }
        this->field_0xac = fVar3;
        if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
          JAISound::setVolume(*(JAISound **)&this->field_0x68,
                              this->field_0xac *
                              this->field_0x9c *
                              this->field_0x98 *
                              this->field_0x94 *
                              this->field_0x90 *
                              this->field_0x8c *
                              this->field_0x88 * this->field_0x80 * this->field_0x84,0,0);
        }
      }
      else {
        if (((this->mIslandRoomNo == 0x29) && (this->mbLandingDemoStarted != 3)) &&
           (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0)) {
          fVar3 = ***(float ***)&this->field_0x4 - JAZelAudio::_4347;
          fVar4 = (**(float ***)&this->field_0x4)[2] - JAZelAudio::_4348;
          dVar10 = (double)(fVar3 * fVar3 + fVar4 * fVar4);
          if ((double)JAZelAudio::_4004 < dVar10) {
            dVar9 = 1.0 / SQRT(dVar10);
            dVar9 = JAZelAudio::_4349 * dVar9 * (JAZelAudio::_4350 - dVar10 * dVar9 * dVar9);
            dVar9 = JAZelAudio::_4349 * dVar9 * (JAZelAudio::_4350 - dVar10 * dVar9 * dVar9);
            dVar10 = (double)(float)(dVar10 * JAZelAudio::_4349 * dVar9 *
                                              (JAZelAudio::_4350 - dVar10 * dVar9 * dVar9));
          }
          fVar3 = JAZelAudio::1_0;
          if ((dVar10 <= (double)JAZelAudio::_4351) &&
             (fVar3 = JAZelAudio::_4004, (double)JAZelAudio::_4352 < dVar10)) {
            fVar3 = (float)(dVar10 - (double)JAZelAudio::_4352) / JAZelAudio::_4343;
          }
          if ((undefined *)this->field_0x78 == &DAT_8000000a) {
            fVar3 = JAZelAudio::1_0;
          }
          if (*(char *)&this->field_0x205 == '\0') {
            this->field_0x90 = fVar3;
          }
          if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
            JAISound::setVolume(*(JAISound **)&this->field_0x68,
                                this->field_0xac *
                                this->field_0x9c *
                                this->field_0x98 *
                                this->field_0x94 *
                                this->field_0x90 *
                                this->field_0x8c *
                                this->field_0x88 * this->field_0x80 * this->field_0x84,0,0);
          }
        }
      }
    }
  }
  if (this->field_0x224 == 0x19) {
    fVar3 = JAZelAudio::_4004;
    if (**(int **)&this->field_0x4 != 0) {
      fVar3 = *(float *)(**(int **)&this->field_0x4 + 4);
    }
    fVar4 = JAZelAudio::1_0;
    if ((((undefined *)this->field_0x78 != &DAT_8000000a) && (JAZelAudio::_4353 <= fVar3)) &&
       (fVar4 = JAZelAudio::_4004, fVar3 < JAZelAudio::_4352)) {
      fVar4 = JAZelAudio::1_0 - (fVar3 - JAZelAudio::_4353) / JAZelAudio::_4353;
    }
    this->field_0xac = fVar4;
    if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
      JAISound::setVolume(*(JAISound **)&this->field_0x68,
                          this->field_0xac *
                          this->field_0x9c *
                          this->field_0x98 *
                          this->field_0x94 *
                          this->field_0x90 *
                          this->field_0x8c * this->field_0x88 * this->field_0x80 * this->field_0x84,
                          0,0);
    }
  }
  if (this->field_0x224 == 0x35) {
    fVar3 = ***(float ***)&this->field_0x4;
    fVar4 = (**(float ***)&this->field_0x4)[2];
    dVar10 = (double)(fVar3 * fVar3 + fVar4 * fVar4);
    if ((double)JAZelAudio::_4004 < dVar10) {
      dVar9 = 1.0 / SQRT(dVar10);
      dVar9 = JAZelAudio::_4349 * dVar9 * (JAZelAudio::_4350 - dVar10 * dVar9 * dVar9);
      dVar9 = JAZelAudio::_4349 * dVar9 * (JAZelAudio::_4350 - dVar10 * dVar9 * dVar9);
      dVar10 = (double)(float)(dVar10 * JAZelAudio::_4349 * dVar9 *
                                        (JAZelAudio::_4350 - dVar10 * dVar9 * dVar9));
    }
    fVar3 = JAZelAudio::1_0;
    if ((dVar10 <= (double)JAZelAudio::_4354) &&
       (fVar3 = JAZelAudio::_4004, (double)JAZelAudio::_4355 < dVar10)) {
      fVar3 = (float)(dVar10 - (double)JAZelAudio::_4355) / JAZelAudio::_4356;
    }
    if ((undefined *)this->field_0x78 == &DAT_8000000a) {
      fVar3 = JAZelAudio::1_0;
    }
    this->field_0x90 = fVar3;
    if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
      JAISound::setVolume(*(JAISound **)&this->field_0x68,
                          this->field_0xac *
                          this->field_0x9c *
                          this->field_0x98 *
                          this->field_0x94 *
                          this->field_0x90 *
                          this->field_0x8c * this->field_0x88 * this->field_0x80 * this->field_0x84,
                          0,0);
    }
  }
  if ((undefined *)this->field_0x78 == &DAT_8000001e) {
    iVar5 = this->field_0x224;
    if ((iVar5 != 0x5d) && (((0x5c < iVar5 || (0x52 < iVar5)) || (iVar5 < 0x4e)))) {
      seStart(this,0x703b,(cXyz *)0x0,0,0,JAZelAudio::1_0,JAZelAudio::1_0,JAZelAudio::_4357,
              JAZelAudio::_4357,0);
    }
  }
  if ((this->field_0xbc != 0) && (iVar5 = checkBgmPlaying(this), iVar5 == 0)) {
    bVar1 = this->field_0xbc;
    if (bVar1 == 1) {
      if ((*(int *)&this->field_0x68 == 0) ||
         (((undefined4 *)this->field_0x78 != (undefined4 *)&DAT_8000002e &&
          ((undefined4 *)this->field_0x78 != &DAT_8000003c)))) {
        bgmId = checkSeaBgmID(this);
        bgmStart(this,bgmId,0x5a,0);
      }
      this->field_0x21e = 0;
    }
    else {
      if (bVar1 == 2) {
        sceneBgmStart(this);
        this->field_0x21e = 0;
      }
      else {
        if (bVar1 == 3) {
          if ((this->mIslandRoomNo == 0x2c) && (iVar5 = checkEventBit(this,0xe20), iVar5 == 1)) {
            puVar7 = &DAT_80000055;
          }
          else {
            puVar7 = (undefined *)
                     expandSceneBgmNum(this,(uint)*(ushort *)
                                                   (&m_isle_info + (uint)this->mIslandRoomNo * 4));
          }
          bgmStart(this,(uint)puVar7,0,0);
        }
      }
    }
    this->field_0xbc = 0;
  }
  processTime(this);
  changeSeaBgm(this);
  bgmBattleGFrame(this);
  mbossBgmMuteProcess(this);
  enemyNearByGFrame(this);
  stSkyCloistersProcess(this);
  if (this->field_0x22d == 1) {
    switch(this->field_0x224) {
    case 7:
      seStart(this,0x1065,(cXyz *)0x0,0,0,JAZelAudio::1_0,JAZelAudio::1_0,JAZelAudio::_4357,
              JAZelAudio::_4357,0);
      break;
    case 9:
    case 0x40:
      iVar5 = checkStreamPlaying(this,0xc0000004);
      if (iVar5 == 0) {
        fVar3 = JAZelAudio::_4004;
        if (**(int **)&this->field_0x4 != 0) {
          fVar3 = *(float *)(**(int **)&this->field_0x4 + 4);
        }
        if (JAZelAudio::_4358 <= fVar3) {
          if (JAZelAudio::_4359 <= fVar3) {
            dVar10 = (double)JAZelAudio::1_0;
          }
          else {
            dVar10 = (double)((fVar3 - JAZelAudio::_4358) / JAZelAudio::_4356);
          }
        }
        else {
          dVar10 = (double)JAZelAudio::_4004;
        }
        if ((double)JAZelAudio::_4004 != dVar10) {
          JAIBasic::startSoundVec
                    ((JAIBasic *)this,JA_SE_ATM_WIND_MJT,(JAISound **)&this->field_0x1f38,(Vec *)0x0
                     ,0,0,'\x04');
          JAISound::setVolume(*(JAISound **)&this->field_0x1f38,(float)dVar10,0,0);
        }
      }
      break;
    case 0xc:
    case 0x54:
    case 0x58:
      seStart(this,0x7019,(cXyz *)0x0,0,0,JAZelAudio::1_0,JAZelAudio::1_0,JAZelAudio::_4357,
              JAZelAudio::_4357,0);
      break;
    case 0x11:
      seStart(this,0x701a,(cXyz *)0x0,0,0,JAZelAudio::1_0,JAZelAudio::1_0,JAZelAudio::_4357,
              JAZelAudio::_4357,0);
      break;
    case 0x18:
      seStart(this,0x1075,(cXyz *)0x0,0,0,JAZelAudio::1_0,JAZelAudio::1_0,JAZelAudio::_4357,
              JAZelAudio::_4357,0);
      break;
    case 0x21:
      seStart(this,0x10a5,(cXyz *)0x0,0,0,JAZelAudio::1_0,JAZelAudio::1_0,JAZelAudio::_4357,
              JAZelAudio::_4357,0);
      break;
    case 0x23:
      seStart(this,0x105a,(cXyz *)0x0,0,0,JAZelAudio::1_0,JAZelAudio::1_0,JAZelAudio::_4357,
              JAZelAudio::_4357,0);
      break;
    case 0x29:
      seStart(this,0x1087,(cXyz *)0x0,0,0,JAZelAudio::1_0,JAZelAudio::1_0,JAZelAudio::_4357,
              JAZelAudio::_4357,0);
      break;
    case 0x5a:
      seStart(this,0x10a6,(cXyz *)0x0,0,0,JAZelAudio::1_0,JAZelAudio::1_0,JAZelAudio::_4357,
              JAZelAudio::_4357,0);
      break;
    case 0x5c:
      cVar2 = *(char *)&this->field_0x239;
      if ((((cVar2 != '\b') && (cVar2 != '\t')) && (cVar2 != '\n')) && (cVar2 != '\v')) {
        seStart(this,0x706c,(cXyz *)0x0,0,0,JAZelAudio::1_0,JAZelAudio::1_0,JAZelAudio::_4357,
                JAZelAudio::_4357,0);
      }
    }
  }
  processHeartGaugeSound(this);
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  return;
}


/* __thiscall JAIZelBasic::heartGaugeOn(void) */

void __thiscall JAIZelBasic::heartGaugeOn(JAIZelBasic *this)

{
  *(undefined *)&this->field_0x40 = 2;
  return;
}


/* __thiscall JAIZelBasic::processHeartGaugeSound(void) */

void __thiscall JAIZelBasic::processHeartGaugeSound(JAIZelBasic *this)

{
  int iVar1;
  
  if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) &&
     (*(char *)&this->field_0x40 != '\0')) {
    iVar1 = this->field_0x34;
    if ((iVar1 != 0) && (*(char *)&this->field_0x206 == '\0')) {
      if (iVar1 < 3) {
        seStart(this,0xd2,(cXyz *)0x0,0,0,JAZelAudio::1_0,JAZelAudio::1_0,JAZelAudio::_4357,
                JAZelAudio::_4357,0);
      }
      else {
        if (iVar1 < 5) {
          seStart(this,0xd1,(cXyz *)0x0,0,0,JAZelAudio::1_0,JAZelAudio::1_0,JAZelAudio::_4357,
                  JAZelAudio::_4357,0);
        }
        else {
          if (iVar1 < 7) {
            seStart(this,0xd0,(cXyz *)0x0,0,0,JAZelAudio::1_0,JAZelAudio::1_0,JAZelAudio::_4357,
                    JAZelAudio::_4357,0);
          }
        }
      }
    }
    *(char *)&this->field_0x40 = *(char *)&this->field_0x40 + -1;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::gframeProcess(void) */

void __thiscall JAIZelBasic::gframeProcess(JAIZelBasic *this)

{
  if (_seHandle != 0) {
    if (3 < *(byte *)(_seHandle + 5)) {
      zeldaGFrameWork(this);
    }
    JAIBasic::processFrameWork((JAIBasic *)this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::resetProcess(void) */

void __thiscall JAIZelBasic::resetProcess(JAIZelBasic *this)

{
  JAISound *this_00;
  int iVar1;
  SequenceMgr *this_01;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  m_Do_printf::OSReport("[JAIZelBasic::resetProcess]\n");
  iVar1 = 0;
  iVar3 = 0;
  do {
    iVar2 = (int)&this->vtbl + iVar3;
    if (*(JAISound **)(iVar2 + 0xd4) != (JAISound *)0x0) {
      JAISound::stop(*(JAISound **)(iVar2 + 0xd4),1);
      *(undefined4 *)(iVar2 + 0xd4) = 0;
      *(undefined4 *)(iVar2 + 0x134) = 0;
      *(undefined4 *)(iVar2 + 0x194) = 0;
    }
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 4;
  } while (iVar1 < 0x18);
  this_00 = (JAISound *)menuOut(this);
  for (this_01 = (SequenceMgr *)0x0;
      uVar4 = JAIGlobalParameter::getParamSeqPlayTrackMax((JAIGlobalParameter *)this_00),
      this_01 < (SequenceMgr *)((ulonglong)uVar4 >> 0x20); this_01 = this_01 + 1) {
    this_00 = (JAISound *)JAInter::SequenceMgr::getPlayTrackInfo(this_01,(ulong)uVar4);
    if ((this_00 != (JAISound *)0x0) &&
       (this_00 = *(JAISound **)&this_00[2].field_0x8, this_00 != (JAISound *)0x0)) {
      this_00 = (JAISound *)JAISound::setSeqInterVolume(this_00,'\x06',JAZelAudio::_4004,1);
    }
  }
  if (*(JAISound **)(_streamUpdate + 0x14) != (JAISound *)0x0) {
    JAISound::stop(*(JAISound **)(_streamUpdate + 0x14),1);
  }
  if (_seHandle != (JAISound *)0x0) {
    JAISound::setSeqInterVolume(_seHandle,'\x06',JAZelAudio::_4004,1);
  }
  this->mNextSceneBgmId = 0;
  this->field_0x22e = 0;
  this->field_0x22d = 0;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::resetRecover(void) */

void __thiscall JAIZelBasic::resetRecover(JAIZelBasic *this)

{
  float fVar1;
  JAISound *this_00;
  SequenceMgr *this_01;
  undefined8 uVar2;
  
  this_00 = _seHandle;
  if (_seHandle != (JAISound *)0x0) {
    this_00 = (JAISound *)JAISound::setSeqInterVolume(_seHandle,'\x06',JAZelAudio::1_0,0);
  }
  for (this_01 = (SequenceMgr *)0x0;
      uVar2 = JAIGlobalParameter::getParamSeqPlayTrackMax((JAIGlobalParameter *)this_00),
      this_01 < (SequenceMgr *)((ulonglong)uVar2 >> 0x20); this_01 = this_01 + 1) {
    this_00 = (JAISound *)JAInter::SequenceMgr::getPlayTrackInfo(this_01,(ulong)uVar2);
    if (((this_00 != (JAISound *)0x0) &&
        (this_00 = *(JAISound **)&this_00[2].field_0x8, this_00 != (JAISound *)0x0)) &&
       (this_00 != _seHandle)) {
      this_00 = (JAISound *)JAISound::stop(this_00,0);
    }
  }
  setScene(this,0,0,0,-1);
  load1stDynamicWave(this);
  sceneBgmStart(this);
  load2ndDynamicWave(this);
  fVar1 = JAZelAudio::1_0;
  this->field_0x80 = JAZelAudio::1_0;
  this->field_0x84 = fVar1;
  this->field_0x88 = fVar1;
  this->field_0x8c = fVar1;
  this->field_0x90 = fVar1;
  this->field_0x94 = fVar1;
  this->field_0x98 = fVar1;
  this->field_0x9c = fVar1;
  this->field_0xac = fVar1;
  this->field_0xa0 = fVar1;
  this->field_0xa4 = fVar1;
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\0',JAIZelParam::VOL_SE_SYSTEM_DEFAULT);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x01',JAIZelParam::VOL_SE_LINK_VOICE_DEFAULT);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x02',JAIZelParam::VOL_SE_LINK_MOTION_DEFAULT);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x03',JAIZelParam::VOL_SE_LINK_FOOTNOTE_DEFAULT);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x04',JAIZelParam::VOL_SE_CHAR_VOICE_DEFAULT);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x05',JAIZelParam::VOL_SE_CHAR_MOVE_DEFAULT);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x06',JAIZelParam::VOL_SE_OBJECT_DEFAULT);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\a',JAIZelParam::VOL_SE_ATMOSPHERE_DEFAULT);
  *(undefined *)&this->field_0x206 = 0;
  *(undefined *)&this->field_0x207 = 0;
  this->field_0x201 = 0;
  *(undefined *)&this->field_0xbf = 0;
  return;
}


/* __thiscall JAIZelBasic::bgmStreamPrepare(unsigned long) */

void __thiscall JAIZelBasic::bgmStreamPrepare(JAIZelBasic *this,ulong param_1)

{
  if (this->field_0x63 == 0) {
    JAIBasic::startSoundVec((JAIBasic *)this,param_1,&this->mpSound,(Vec *)0x0,0,0,'\x04');
    if (this->mpSound != (JAISound *)0x0) {
      JAISound::setPrepareFlag(this->mpSound,'\x01');
    }
    if (param_1 == 0xc0000009) {
      this->field_0xbe = 1;
    }
    this->field_0x7c = param_1;
  }
  return;
}


/* __thiscall JAIZelBasic::bgmStreamPlay(void) */

void __thiscall JAIZelBasic::bgmStreamPlay(JAIZelBasic *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("[JAIZelBasic::bgmStreamPlay] \n");
  if (this->field_0x63 == 0) {
    if (this->mpSound != (JAISound *)0x0) {
      JAISound::start(this->mpSound,0);
    }
    uVar1 = this->field_0x7c;
    if (uVar1 == 0xc0000001) {
      *(undefined *)&this->field_0xba = 1;
      if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
        JAISound::stop(*(JAISound **)&this->field_0x68,0x1e);
      }
      *(undefined *)&this->field_0x1f3c = 0;
      this->field_0x201 = 1;
    }
    else {
      if (((int)uVar1 < -0x3fffffff) && (-0x40000001 < (int)uVar1)) {
        if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
          JAISound::stop(*(JAISound **)&this->field_0x68,0x1e);
        }
        *(undefined *)&this->field_0x1f3c = 0;
      }
    }
    *(undefined *)&this->field_0xb8 = 1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JAIZelBasic::bgmStart(unsigned long,
                                    unsigned long,
                                    long) */

void __thiscall JAIZelBasic::bgmStart(JAIZelBasic *this,uint bgmId,ulong param_2,long param_3)

{
  float fVar1;
  undefined4 *puVar2;
  float *pfVar3;
  undefined4 *puVar4;
  double dVar5;
  double dVar6;
  
  this->field_0xbe = 0;
  if (this->field_0x63 != 0) {
    return;
  }
  if ((this->field_0x66 != 0) && ((undefined *)bgmId != &DAT_8000001e)) {
    return;
  }
  if ((undefined *)bgmId == &DAT_80000800) {
    return;
  }
  if (bgmId == 0) {
    return;
  }
  if (bgmId == 0xffffffff) {
    return;
  }
  if (bgmId == 0xc0000000) {
    return;
  }
  if ((this->field_0x78 == 0x8000000f) && (bgmId == 0x80000007)) {
    return;
  }
  if (bgmId == 0x8000004a) {
LAB_802a3780:
    this->mSomeSpecialBGMFlag = 1;
    puVar4 = (undefined4 *)0x8000004a;
    goto LAB_802a37fc;
  }
  puVar4 = (undefined4 *)bgmId;
  if ((int)bgmId < -0x7fffffb6) {
    if ((undefined *)bgmId == &DAT_80000014) {
LAB_802a371c:
      this->mSomeSpecialBGMFlag = 1;
      puVar4 = (undefined4 *)&DAT_80000014;
      goto LAB_802a37fc;
    }
    if ((int)bgmId < -0x7fffffec) {
      if (bgmId == 0x80000007) {
        this->mNextSceneBgmId = 0x80000007;
        goto LAB_802a37fc;
      }
      if ((int)bgmId < -0x7ffffff9) {
        if ((undefined1 *)bgmId != &DAT_80000004) {
          if ((int)bgmId < -0x7ffffffc) {
            if (-0x7ffffffe < (int)bgmId) goto LAB_802a36fc;
          }
          else {
            if ((int)bgmId < -0x7ffffffa) goto LAB_802a3708;
          }
        }
      }
      else {
        if ((undefined *)bgmId == &DAT_80000010) {
LAB_802a36fc:
          this->mSomeSpecialBGMFlag = 1;
          goto LAB_802a37fc;
        }
        if (((int)bgmId < -0x7ffffff0) && ((undefined *)bgmId == &DAT_8000000a)) {
          this->field_0xca = 1;
          goto LAB_802a37fc;
        }
      }
    }
    else {
      if (bgmId == 0x80000029) {
LAB_802a3758:
        this->mSomeSpecialBGMFlag = 1;
        puVar4 = (undefined4 *)0x80000029;
        goto LAB_802a37fc;
      }
      if ((int)bgmId < -0x7fffffd7) {
        if ((undefined *)bgmId == &DAT_80000023) goto LAB_802a3744;
        if ((int)bgmId < -0x7fffffdd) {
          if ((int)bgmId < -0x7fffffea) goto LAB_802a3730;
        }
        else {
          if (-0x7fffffd9 < (int)bgmId) goto LAB_802a37bc;
        }
      }
      else {
        if ((undefined4 *)bgmId == &DAT_80000048) goto LAB_802a37a8;
        if (-0x7fffffb9 < (int)bgmId) goto LAB_802a376c;
        if (bgmId == 0x80000042) goto LAB_802a37c8;
      }
    }
  }
  else {
    if ((int)bgmId < -0x7ffffed9) {
      if ((int)bgmId < -0x7ffffeed) {
        if ((undefined *)bgmId == &DAT_80000105) {
LAB_802a3708:
          this->mSomeSpecialBGMFlag = 1;
          puVar4 = (undefined4 *)&DAT_80000005;
          goto LAB_802a37fc;
        }
        if ((int)bgmId < -0x7ffffefb) {
          if ((undefined *)bgmId == &DAT_8000004c) {
LAB_802a3794:
            this->mSomeSpecialBGMFlag = 1;
            puVar4 = (undefined4 *)&DAT_8000004c;
            goto LAB_802a37fc;
          }
        }
        else {
          if (-0x7ffffef1 < (int)bgmId) goto LAB_802a371c;
        }
      }
      else {
        if (-0x7ffffee1 < (int)bgmId) {
          if ((undefined *)bgmId != &DAT_80000124) {
            if (-0x7ffffedd < (int)bgmId) {
LAB_802a37bc:
              puVar4 = &DAT_80000028;
              goto LAB_802a37fc;
            }
LAB_802a3744:
            this->mSomeSpecialBGMFlag = 1;
            puVar4 = (undefined4 *)&DAT_80000023;
            goto LAB_802a37fc;
          }
          goto LAB_802a3758;
        }
        if ((undefined *)bgmId == &DAT_80000115) {
LAB_802a3730:
          this->mSomeSpecialBGMFlag = 1;
          puVar4 = (undefined4 *)&DAT_80000015;
          goto LAB_802a37fc;
        }
      }
    }
    else {
      if ((undefined *)bgmId == &DAT_80000150) {
LAB_802a376c:
        this->mSomeSpecialBGMFlag = 1;
        puVar4 = (undefined4 *)0x80000049;
        goto LAB_802a37fc;
      }
      if ((int)bgmId < -0x7ffffeb0) {
        if ((undefined *)bgmId == &DAT_80000140) {
LAB_802a37a8:
          this->mSomeSpecialBGMFlag = 1;
          puVar4 = &DAT_80000048;
          goto LAB_802a37fc;
        }
        if ((((int)bgmId < -0x7ffffec0) && ((int)bgmId < -0x7ffffecc)) && (-0x7ffffed1 < (int)bgmId)
           ) {
LAB_802a37c8:
          puVar4 = (undefined4 *)0x80000042;
          goto LAB_802a37fc;
        }
      }
      else {
        if (bgmId == 0xc0000006) {
          *(undefined *)&this->field_0x64 = 1;
          goto LAB_802a37fc;
        }
        if ((int)bgmId < -0x3ffffffa) {
          if ((undefined *)bgmId == &DAT_80000152) goto LAB_802a3794;
          if ((int)bgmId < -0x7ffffeae) goto LAB_802a3780;
        }
      }
    }
  }
  this->mSomeSpecialBGMFlag = 0;
LAB_802a37fc:
  if (*(int *)&this->field_0x68 != 0) {
    puVar2 = (undefined4 *)this->field_0x78;
    if ((puVar4 == puVar2) && (puVar4 == (undefined4 *)&DAT_80000005)) {
      if ((undefined *)bgmId == &DAT_80000105) {
        bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_80000005,1,5);
        return;
      }
      if (-0x7ffffefc < (int)bgmId) {
        return;
      }
      if ((undefined1 *)bgmId != &DAT_80000005) {
        return;
      }
      bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_80000005,0,5);
      return;
    }
    if ((puVar4 == puVar2) && (puVar4 == (undefined4 *)&DAT_80000014)) {
      if ((undefined *)bgmId == &DAT_80000110) {
        bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_80000014,1,5);
        return;
      }
      if ((int)bgmId < -0x7ffffef0) {
        if ((undefined *)bgmId != &DAT_80000014) {
          return;
        }
        bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_80000014,0,5);
        return;
      }
      if ((undefined *)bgmId == &DAT_80000112) {
        bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_80000014,3,5);
        return;
      }
      if (-0x7ffffeef < (int)bgmId) {
        return;
      }
      bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_80000014,2,5);
      return;
    }
    if ((puVar4 == puVar2) && (puVar4 == (undefined4 *)&DAT_80000015)) {
      if ((undefined *)bgmId == &DAT_80000115) {
        bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_80000015,1,5);
        return;
      }
      if (-0x7ffffeec < (int)bgmId) {
        return;
      }
      if ((undefined *)bgmId != &DAT_80000015) {
        return;
      }
      bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_80000015,0,5);
      return;
    }
    if ((puVar4 == puVar2) && (puVar4 == (undefined4 *)&DAT_80000023)) {
      if ((undefined *)bgmId == &DAT_80000121) {
        bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_80000023,2,5);
        return;
      }
      if (-0x7ffffee0 < (int)bgmId) {
        if ((undefined *)bgmId == &DAT_80000123) {
          bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_80000022,3,5);
          return;
        }
        if (-0x7ffffede < (int)bgmId) {
          return;
        }
        bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_80000023,3,5);
        return;
      }
      if ((undefined *)bgmId == &DAT_80000023) {
        bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_80000023,0,5);
        return;
      }
      if ((int)bgmId < -0x7fffffdd) {
        return;
      }
      if ((int)bgmId < -0x7ffffee0) {
        return;
      }
      bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_80000023,1,5);
      return;
    }
    if ((puVar4 == puVar2) && (puVar4 == (undefined4 *)0x80000042)) {
      if (bgmId == 0x80000131) {
        bgmMute(this,(JAISound **)&this->field_0x68,0x80000042,2,0x3c);
        return;
      }
      if (-0x7ffffed0 < (int)bgmId) {
        if (bgmId == 0x80000133) {
          bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_80000043,3,0x3c);
          return;
        }
        if (-0x7ffffece < (int)bgmId) {
          return;
        }
        bgmMute(this,(JAISound **)&this->field_0x68,0x80000042,3,0x3c);
        return;
      }
      if (bgmId == 0x80000042) {
        bgmMute(this,(JAISound **)&this->field_0x68,0x80000042,0,0x3c);
        return;
      }
      if ((int)bgmId < -0x7fffffbe) {
        return;
      }
      if ((int)bgmId < -0x7ffffed0) {
        return;
      }
      bgmMute(this,(JAISound **)&this->field_0x68,0x80000042,1,0x3c);
      return;
    }
    if ((puVar4 == puVar2) && (puVar4 == (undefined4 *)0x80000029)) {
      if ((undefined *)bgmId == &DAT_80000124) {
        bgmMute(this,(JAISound **)&this->field_0x68,0x80000029,1,5);
        return;
      }
      if (-0x7ffffedd < (int)bgmId) {
        return;
      }
      if (bgmId != 0x80000029) {
        return;
      }
      bgmMute(this,(JAISound **)&this->field_0x68,0x80000029,0,5);
      return;
    }
    if ((puVar4 == puVar2) && (puVar4 == &DAT_80000048)) {
      if ((undefined *)bgmId == &DAT_80000140) {
        bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_80000048,1,5);
        return;
      }
      if (-0x7ffffec1 < (int)bgmId) {
        return;
      }
      if ((undefined4 *)bgmId != &DAT_80000048) {
        return;
      }
      bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_80000048,0,5);
      return;
    }
    if ((puVar4 == puVar2) && (puVar4 == (undefined4 *)0x80000049)) {
      if ((undefined *)bgmId == &DAT_80000150) {
        bgmMute(this,(JAISound **)&this->field_0x68,0x80000049,1,5);
        return;
      }
      if (-0x7ffffeb1 < (int)bgmId) {
        return;
      }
      if (bgmId != 0x80000049) {
        return;
      }
      bgmMute(this,(JAISound **)&this->field_0x68,0x80000049,0,5);
      return;
    }
    if ((puVar4 == puVar2) && (puVar4 == (undefined4 *)0x8000004a)) {
      if ((undefined *)bgmId == &DAT_80000151) {
        bgmMute(this,(JAISound **)&this->field_0x68,0x8000004a,1,5);
        return;
      }
      if (-0x7ffffeb0 < (int)bgmId) {
        return;
      }
      if (bgmId != 0x8000004a) {
        return;
      }
      bgmMute(this,(JAISound **)&this->field_0x68,0x8000004a,0,5);
      return;
    }
    if ((puVar4 == puVar2) && (puVar4 == (undefined4 *)&DAT_8000004c)) {
      if ((undefined *)bgmId == &DAT_80000152) {
        bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_8000004c,1,5);
        return;
      }
      if (-0x7ffffeaf < (int)bgmId) {
        return;
      }
      if ((undefined *)bgmId != &DAT_8000004c) {
        return;
      }
      bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_8000004c,0,5);
      return;
    }
    if ((puVar4 == puVar2) && (puVar4 == &DAT_80000028)) {
      if ((undefined *)bgmId == &DAT_80000125) {
        bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_80000028,1,0x3c);
        JAISound::setTempoProportion(*(JAISound **)&this->field_0x68,JAZelAudio::_4731,0x3c);
        return;
      }
      if ((int)bgmId < -0x7ffffedb) {
        if ((undefined4 *)bgmId != &DAT_80000028) {
          return;
        }
        bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_80000028,0,0x3c);
        JAISound::setTempoProportion(*(JAISound **)&this->field_0x68,JAZelAudio::1_0,0x3c);
        return;
      }
      if (-0x7ffffeda < (int)bgmId) {
        return;
      }
      bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_80000028,2,0x3c);
      JAISound::setTempoProportion(*(JAISound **)&this->field_0x68,JAZelAudio::1_0,0x3c);
      return;
    }
  }
  bgmStop(this,0,param_3);
  JAIBasic::startSoundVec
            ((JAIBasic *)this,(JAISoundInfoID)puVar4,(JAISound **)&this->field_0x68,(Vec *)0x0,
             param_2,0,'\x04');
  if (((this->field_0x224 == 0x12) && (this->mIslandRoomNo == 0x29)) &&
     (pfVar3 = **(float ***)&this->field_0x4, pfVar3 != (float *)0x0)) {
    dVar6 = (double)((*pfVar3 - JAZelAudio::_4347) * (*pfVar3 - JAZelAudio::_4347) +
                    (pfVar3[2] - JAZelAudio::_4348) * (pfVar3[2] - JAZelAudio::_4348));
    if ((double)JAZelAudio::_4004 < dVar6) {
      dVar5 = 1.0 / SQRT(dVar6);
      dVar5 = JAZelAudio::_4349 * dVar5 * (JAZelAudio::_4350 - dVar6 * dVar5 * dVar5);
      dVar5 = JAZelAudio::_4349 * dVar5 * (JAZelAudio::_4350 - dVar6 * dVar5 * dVar5);
      dVar6 = (double)(float)(dVar6 * JAZelAudio::_4349 * dVar5 *
                                      (JAZelAudio::_4350 - dVar6 * dVar5 * dVar5));
    }
    fVar1 = JAZelAudio::1_0;
    if ((dVar6 <= (double)JAZelAudio::_4351) &&
       (fVar1 = JAZelAudio::_4004, (double)JAZelAudio::_4352 < dVar6)) {
      fVar1 = (float)(dVar6 - (double)JAZelAudio::_4352) / JAZelAudio::_4343;
    }
    if ((undefined *)this->field_0x78 == &DAT_8000000a) {
      fVar1 = JAZelAudio::1_0;
    }
    this->field_0x90 = fVar1;
  }
  if (puVar4 == (undefined4 *)&DAT_8000000a) {
    this->field_0x8c = JAZelAudio::1_0;
  }
  else {
    fVar1 = this->field_0xac *
            this->field_0x9c *
            this->field_0x98 *
            this->field_0x94 *
            this->field_0x90 *
            this->field_0x8c * this->field_0x88 * this->field_0x80 * this->field_0x84;
    if (((JAZelAudio::1_0 != fVar1) && (puVar4 != (undefined4 *)&DAT_80000051)) &&
       ((puVar4 != (undefined4 *)&DAT_80000052 &&
        (*(JAISound **)&this->field_0x68 != (JAISound *)0x0)))) {
      JAISound::setVolume(*(JAISound **)&this->field_0x68,fVar1,0,0);
    }
  }
  if ((undefined *)bgmId == &DAT_80000110) {
    bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,1,0);
  }
  else {
    if ((int)bgmId < -0x7ffffef0) {
      if ((undefined4 *)bgmId == &DAT_8000003c) {
        if ((this->mIsSailing != 0) || (JAZelAudio::_4732 <= this->field_0x1f40)) {
          bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_8000003c,0,0);
        }
        else {
          bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_8000003c,1,0);
        }
      }
      else {
        if ((int)bgmId < -0x7fffffc4) {
          if ((undefined *)bgmId == &DAT_80000023) {
            bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,0,0);
          }
          else {
            if ((int)bgmId < -0x7fffffdd) {
              if ((undefined *)bgmId == &DAT_80000014) {
                bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,0,0);
              }
              else {
                if ((int)bgmId < -0x7fffffec) {
                  if ((undefined1 *)bgmId == &DAT_80000005) {
                    bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,0,0);
                  }
                }
                else {
                  if ((int)bgmId < -0x7fffffea) {
                    bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,0,0);
                  }
                }
              }
            }
            else {
              if (bgmId == 0x80000029) {
                bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,0,0);
              }
              else {
                if ((int)bgmId < -0x7fffffd7) {
                  if (-0x7fffffd9 < (int)bgmId) {
                    bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,0,0);
                  }
                }
                else {
                  if ((undefined *)bgmId == &DAT_8000002e) {
                    if ((this->mIsSailing != 0) || (JAZelAudio::_4732 <= this->field_0x1f40)) {
                      bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_8000002e,0,0);
                    }
                    else {
                      bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_8000002e,1,0);
                    }
                  }
                }
              }
            }
          }
        }
        else {
          if (bgmId == 0x8000004a) {
            bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,0,0);
          }
          else {
            if ((int)bgmId < -0x7fffffb6) {
              if ((undefined4 *)bgmId == &DAT_80000048) {
                bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,0,0);
              }
              else {
                if ((int)bgmId < -0x7fffffb8) {
                  if (bgmId == 0x80000042) {
                    bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,0,0);
                  }
                }
                else {
                  bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,0,0);
                }
              }
            }
            else {
              if ((undefined *)bgmId == &DAT_80000105) {
                bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,1,0);
              }
              else {
                if (((int)bgmId < -0x7ffffefb) && ((undefined *)bgmId == &DAT_8000004c)) {
                  bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,0,0);
                }
              }
            }
          }
        }
      }
    }
    else {
      if ((undefined *)bgmId == &DAT_80000126) {
        bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,2,0);
      }
      else {
        if ((int)bgmId < -0x7ffffeda) {
          if ((undefined *)bgmId == &DAT_80000120) {
            bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,1,0);
          }
          else {
            if ((int)bgmId < -0x7ffffee0) {
              if ((undefined *)bgmId == &DAT_80000115) {
                bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,1,0);
              }
              else {
                if ((int)bgmId < -0x7ffffeeb) {
                  if ((undefined *)bgmId == &DAT_80000112) {
                    bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,3,0);
                  }
                  else {
                    if ((int)bgmId < -0x7ffffeee) {
                      bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,2,0);
                    }
                  }
                }
              }
            }
            else {
              if ((undefined *)bgmId == &DAT_80000123) {
                bgmMute(this,(JAISound **)&this->field_0x68,(ulong)((int)puVar4 + -1),3,0);
              }
              else {
                if ((int)bgmId < -0x7ffffedd) {
                  if ((int)bgmId < -0x7ffffede) {
                    bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,2,0);
                  }
                  else {
                    bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,3,0);
                  }
                }
                else {
                  if ((int)bgmId < -0x7ffffedb) {
                    bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,1,0);
                  }
                  else {
                    bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,1,0);
                    JAISound::setTempoProportion
                              (*(JAISound **)&this->field_0x68,JAZelAudio::_4731,0);
                  }
                }
              }
            }
          }
        }
        else {
          if ((undefined *)bgmId == &DAT_80000140) {
            bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,1,0);
          }
          else {
            if ((int)bgmId < -0x7ffffec0) {
              if (bgmId == 0x80000132) {
                bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,3,0);
              }
              else {
                if ((int)bgmId < -0x7ffffece) {
                  if ((undefined *)bgmId == &DAT_80000130) {
                    bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,1,0);
                  }
                  else {
                    if (-0x7ffffed1 < (int)bgmId) {
                      bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,2,0);
                    }
                  }
                }
                else {
                  if ((int)bgmId < -0x7ffffecc) {
                    bgmMute(this,(JAISound **)&this->field_0x68,(ulong)((int)puVar4 + 1),3,0);
                  }
                }
              }
            }
            else {
              if ((undefined *)bgmId == &DAT_80000151) {
                bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,1,0);
              }
              else {
                if ((int)bgmId < -0x7ffffeaf) {
                  if (-0x7ffffeb1 < (int)bgmId) {
                    bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,1,0);
                  }
                }
                else {
                  if ((int)bgmId < -0x7ffffead) {
                    bgmMute(this,(JAISound **)&this->field_0x68,(ulong)puVar4,1,0);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  this->field_0x78 = (uint)puVar4;
  if (((puVar4 == &DAT_80000038) || (puVar4 == (undefined4 *)0x80000001)) ||
     (puVar4 == (undefined4 *)&DAT_8000000e)) {
    *(undefined *)&this->field_0x1f3c = 1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JAIZelBasic::bgmStop(unsigned long,
                                   long) */

void __thiscall JAIZelBasic::bgmStop(JAIZelBasic *this,ulong param_1,long param_2)

{
  if (((undefined *)this->field_0x78 != (undefined *)0x80000003) &&
     ((undefined *)this->field_0x78 != &DAT_80000010)) {
    this->mSomeSpecialBGMFlag = 0;
  }
  if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
    JAISound::stop(*(JAISound **)&this->field_0x68,param_1);
  }
  *(undefined4 *)&this->field_0x68 = 0;
  this->field_0x78 = 0xffffffff;
  if (this->mpSound != (JAISound *)0x0) {
    JAISound::stop(this->mpSound,param_1);
  }
  this->mpSound = (JAISound *)0x0;
  this->field_0x7c = 0xffffffff;
  if (param_2 == 0) {
    if (*(JAISound **)&this->field_0x6c != (JAISound *)0x0) {
      JAISound::stop(*(JAISound **)&this->field_0x6c,param_1);
      *(undefined4 *)&this->field_0x6c = 0;
    }
    this->field_0x74 = -1;
    this->field_0x8c = JAZelAudio::1_0;
    *(undefined *)&this->field_0xbb = 0;
    *(undefined *)&this->field_0x206 = 0;
  }
  demoBgmStop(this,param_1);
  *(undefined *)&this->field_0x1f3c = 0;
  this->field_0x201 = 0;
  this->mLastMinibossSubBGMType = 0;
  *(undefined *)&this->field_0x64 = 0;
  *(undefined *)&this->field_0x65 = 0;
  *(undefined *)&this->field_0xb8 = 0;
  *(undefined *)&this->field_0xcb = 0xff;
  *(undefined *)&this->field_0xcc = 0;
  this->field_0x32 = 0;
  return;
}


/* __thiscall JAIZelBasic::mainBgmStopOnly(unsigned long) */

void __thiscall JAIZelBasic::mainBgmStopOnly(JAIZelBasic *this,ulong param_1)

{
  if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
    JAISound::stop(*(JAISound **)&this->field_0x68,param_1);
  }
  *(undefined4 *)&this->field_0x68 = 0;
  this->field_0x78 = 0xffffffff;
  return;
}


/* __thiscall JAIZelBasic::subBgmStart(unsigned long) */

void __thiscall JAIZelBasic::subBgmStart(JAIZelBasic *this,ulong bgmId)

{
  undefined1 *puVar1;
  undefined *puVar2;
  JAISound *this_00;
  
  this->field_0xbe = 0;
  if (this->field_0x63 != 0) {
    return;
  }
  if (bgmId == 0xffffffff) {
    return;
  }
  if (this->mSomeSpecialBGMFlag == 1) {
    return;
  }
  if (bgmId == 0x8000002b) {
LAB_802a491c:
    this->mLastMinibossSubBGMType = 2;
  }
  else {
    if ((int)bgmId < -0x7fffffd5) {
      if ((int)bgmId < -0x7fffffe5) {
        if ((undefined *)bgmId == &DAT_80000009) {
          *(undefined *)&this->field_0x206 = 1;
        }
        else {
          if ((int)bgmId < -0x7ffffff7) {
            puVar1 = &DAT_80000002;
joined_r0x802a48e4:
            if ((undefined1 *)bgmId == puVar1) goto LAB_802a48f8;
          }
          else {
            if (-0x7fffffe8 < (int)bgmId) {
              this->mLastMinibossSubBGMType = 1;
            }
          }
        }
      }
      else {
        if (bgmId != 0x80000026) {
          if ((int)bgmId < -0x7fffffda) {
            if (-0x7fffffdd < (int)bgmId) {
LAB_802a48f8:
              *(undefined *)&this->field_0x64 = 1;
              *(undefined *)&this->field_0x206 = 1;
              *(undefined *)&this->field_0xbb = 5;
            }
          }
          else {
            if ((int)bgmId < -0x7fffffd8) goto LAB_802a48f8;
          }
        }
      }
    }
    else {
      if (bgmId == 0x80000047) {
LAB_802a4928:
        this->mLastMinibossSubBGMType = 3;
      }
      else {
        if ((int)bgmId < -0x7fffffb9) {
          if ((undefined *)bgmId == &DAT_80000041) goto LAB_802a4928;
          if ((int)bgmId < -0x7fffffbf) {
            if (((int)bgmId < -0x7fffffcd) && (-0x7fffffd1 < (int)bgmId)) goto LAB_802a48f8;
          }
          else {
            if (-0x7fffffbb < (int)bgmId) goto LAB_802a491c;
          }
        }
        else {
          if ((undefined *)bgmId == &DAT_8000005d) goto LAB_802a48f8;
          if ((int)bgmId < -0x7fffffa3) {
            puVar1 = &DAT_8000004f;
            goto joined_r0x802a48e4;
          }
        }
      }
    }
  }
  if ((*(int *)&this->field_0x6c != 0) && (bgmId == this->field_0x74)) {
    this->field_0xb0 = -1;
    return;
  }
  if (bgmId == 0x8000002b) {
LAB_802a4a14:
    JAIBasic::startSoundVec
              ((JAIBasic *)this,bgmId,(JAISound **)&this->field_0x6c,(Vec *)0x0,0,0,'\x04');
  }
  else {
    if ((int)bgmId < -0x7fffffd5) {
      if ((undefined *)bgmId != &DAT_80000019) {
        if ((int)bgmId < -0x7fffffe7) {
          if ((undefined *)bgmId == &DAT_80000009) goto LAB_802a4a14;
          if ((int)bgmId < -0x7ffffff7) {
            puVar1 = &DAT_80000002;
            goto joined_r0x802a4a0c;
          }
        }
        else {
          if (bgmId != 0x80000026) {
            if ((int)bgmId < -0x7fffffda) {
              if (-0x7fffffdd < (int)bgmId) goto LAB_802a4a14;
            }
            else {
              if ((int)bgmId < -0x7fffffd8) goto LAB_802a4a14;
            }
          }
        }
        goto LAB_802a4a38;
      }
      goto LAB_802a4a14;
    }
    if ((undefined *)bgmId == &DAT_8000004f) goto LAB_802a4a14;
    if ((int)bgmId < -0x7fffffb1) {
      if (((undefined *)bgmId == &DAT_80000041) ||
         ((((int)bgmId < -0x7fffffbf && ((int)bgmId < -0x7fffffcd)) && (-0x7fffffd1 < (int)bgmId))))
      goto LAB_802a4a14;
    }
    else {
      puVar1 = &DAT_8000005d;
joined_r0x802a4a0c:
      if ((undefined1 *)bgmId == puVar1) goto LAB_802a4a14;
    }
LAB_802a4a38:
    JAIBasic::startSoundVec
              ((JAIBasic *)this,bgmId,(JAISound **)&this->field_0x6c,(Vec *)0x0,0x3c,0,'\x04');
  }
  if ((*(JAISound **)&this->field_0x6c != (JAISound *)0x0) && ((undefined *)bgmId != &DAT_8000005d))
  {
    JAISound::setSeqInterVolume(*(JAISound **)&this->field_0x6c,'\0',this->field_0xa0,0);
  }
  if ((*(int *)&this->field_0x6c != 0) && (bgmId != 0x8000001b)) {
    if ((int)bgmId < -0x7fffffe5) {
      if ((-0x7fffffe8 < (int)bgmId) &&
         (bgmMute(this,(JAISound **)&this->field_0x6c,bgmId,0,0), *(char *)&this->field_0xc9 != '\0'
         )) {
        JAISound::setTrackVolume
                  (*(JAISound **)&this->field_0x6c,JAIZelParam::MBOSS_SWORD_USING_TRACK,
                   JAZelAudio::1_0,0);
      }
    }
    else {
      if ((int)bgmId < -0x7fffffe3) {
        if (this->field_0x47 == 1) {
          bgmMute(this,(JAISound **)&this->field_0x6c,bgmId,0,0);
        }
        else {
          bgmMute(this,(JAISound **)&this->field_0x6c,bgmId,1,0);
        }
      }
    }
  }
  this->field_0x8c = JAZelAudio::_4004;
  this_00 = *(JAISound **)&this->field_0x68;
  if (this_00 == (JAISound *)0x0) goto LAB_802a4cb8;
  if (bgmId != 0x8000002b) {
    if ((int)bgmId < -0x7fffffd5) {
      if ((undefined *)bgmId != &DAT_80000019) {
        if ((int)bgmId < -0x7fffffe7) {
          if (((undefined *)bgmId != &DAT_80000009) &&
             ((-0x7ffffff8 < (int)bgmId || ((undefined1 *)bgmId != &DAT_80000002)))) {
LAB_802a4c68:
            JAISound::setVolume(this_00,this->field_0xac *
                                        this->field_0x9c *
                                        this->field_0x98 *
                                        this->field_0x94 *
                                        this->field_0x90 *
                                        this->field_0x8c *
                                        this->field_0x88 * this->field_0x80 * this->field_0x84,0x3c,
                                0);
            goto LAB_802a4cb8;
          }
        }
        else {
          if (bgmId == 0x80000026) goto LAB_802a4c68;
          if ((int)bgmId < -0x7fffffda) {
            if ((int)bgmId < -0x7fffffdc) goto LAB_802a4c68;
          }
          else {
            if (-0x7fffffd9 < (int)bgmId) goto LAB_802a4c68;
          }
        }
      }
    }
    else {
      if ((undefined *)bgmId != &DAT_80000041) {
        if ((int)bgmId < -0x7fffffbf) {
          if (bgmId != 0x80000036) {
            if ((int)bgmId < -0x7fffffca) {
              puVar2 = &DAT_80000030;
joined_r0x802a4c0c:
              if ((undefined *)bgmId == puVar2) goto LAB_802a4c14;
            }
            goto LAB_802a4c68;
          }
        }
        else {
          if ((undefined *)bgmId != &DAT_8000005d) {
            if ((int)bgmId < -0x7fffffa3) {
              puVar2 = &DAT_8000004f;
              goto joined_r0x802a4c0c;
            }
            goto LAB_802a4c68;
          }
        }
      }
    }
  }
LAB_802a4c14:
  JAISound::setVolume(this_00,this->field_0xac *
                              this->field_0x9c *
                              this->field_0x98 *
                              this->field_0x94 *
                              this->field_0x90 *
                              this->field_0x8c *
                              this->field_0x88 * this->field_0x80 * this->field_0x84,1,0);
LAB_802a4cb8:
  this->field_0x74 = bgmId;
  this->field_0xb0 = -1;
  return;
}


/* __thiscall JAIZelBasic::subBgmStop(void) */

void __thiscall JAIZelBasic::subBgmStop(JAIZelBasic *this)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)this->field_0x74;
  if (puVar1 == &DAT_80000027) {
    return;
  }
  if ((int)puVar1 < -0x7fffffd9) {
    if (puVar1 == &DAT_80000009) {
      return;
    }
    if ((int)puVar1 < -0x7ffffff7) {
      if (puVar1 == &DAT_80000002) {
        return;
      }
    }
    else {
      if (((int)puVar1 < -0x7fffffda) && (-0x7fffffdd < (int)puVar1)) {
        return;
      }
    }
  }
  else {
    if (puVar1 == &DAT_8000004f) {
      return;
    }
    if ((int)puVar1 < -0x7fffffb1) {
      if (((int)puVar1 < -0x7fffffcd) && (-0x7fffffd1 < (int)puVar1)) {
        return;
      }
    }
    else {
      if (puVar1 == &DAT_8000005d) {
        return;
      }
    }
  }
  this->field_0xb0 = 0xf;
  this->mLastMinibossSubBGMType = 0;
  if (((undefined *)this->field_0x74 != &DAT_80000019) &&
     ((undefined *)this->field_0x74 != &DAT_8000001a)) {
    return;
  }
  *(undefined *)&this->field_0xce = 0x14;
  return;
}


/* __thiscall JAIZelBasic::subBgmStopInner(void) */

void __thiscall JAIZelBasic::subBgmStopInner(JAIZelBasic *this)

{
  float fVar1;
  
  if (this->field_0xb0 != -1) {
    if (((undefined *)this->field_0x74 == &DAT_80000019) ||
       ((undefined *)this->field_0x74 == &DAT_8000001a)) {
      *(undefined *)&this->field_0xce = 0x14;
    }
    this->mLastMinibossSubBGMType = 0;
    *(undefined *)&this->field_0x64 = 0;
    if (*(JAISound **)&this->field_0x6c == (JAISound *)0x0) {
      if (this->field_0x74 == -1) {
        return;
      }
    }
    else {
      JAISound::stop(*(JAISound **)&this->field_0x6c,0x2d);
    }
    *(undefined4 *)&this->field_0x6c = 0;
    this->field_0x74 = -1;
    fVar1 = JAZelAudio::1_0;
    this->field_0x8c = JAZelAudio::1_0;
    this->field_0x80 = fVar1;
    if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
      JAISound::setVolume(*(JAISound **)&this->field_0x68,
                          this->field_0xac *
                          this->field_0x9c *
                          this->field_0x98 *
                          this->field_0x94 *
                          this->field_0x90 *
                          this->field_0x8c * this->field_0x88 * this->field_0x80 * this->field_0x84,
                          0x2d,0);
    }
    this->field_0xb0 = -1;
    *(undefined *)&this->field_0xc1 = 0;
    *(undefined4 *)&this->field_0xc4 = 0;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x802a5398) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::bgmNowBattle(float) */

void __thiscall JAIZelBasic::bgmNowBattle(JAIZelBasic *this,float param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar4 = (double)param_1;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if ((((this->field_0x63 != 0) || (this->field_0xca == 1)) ||
      (JAZelAudio::_4004 == this->field_0x98)) || (this->field_0x22d == 0)) goto LAB_802a5398;
  iVar1 = this->field_0x224;
  if (iVar1 == 0x2d) goto LAB_802a5398;
  if (iVar1 < 0x2d) {
    if (iVar1 == 0x18) goto LAB_802a5398;
    if (iVar1 < 0x18) {
      if (iVar1 == 7) goto LAB_802a5398;
      if (iVar1 < 7) {
        if (iVar1 == 2) goto LAB_802a5398;
      }
      else {
        if (iVar1 == 9) goto LAB_802a4fbc;
      }
    }
    else {
      if ((iVar1 == 0x28) || (((iVar1 < 0x28 && (iVar1 < 0x26)) && (0x23 < iVar1))))
      goto LAB_802a5398;
    }
  }
  else {
    if (iVar1 == 0x40) {
LAB_802a4fbc:
      enemyNearBy(this);
      goto LAB_802a5398;
    }
    if (iVar1 < 0x40) {
      if (iVar1 < 0x3a) {
        if (iVar1 == 0x37) goto LAB_802a5398;
      }
      else {
        if (iVar1 < 0x3c) goto LAB_802a5398;
      }
    }
    else {
      if ((iVar1 == 0x69) || (((iVar1 < 0x69 && (iVar1 < 0x5d)) && (0x5a < iVar1))))
      goto LAB_802a5398;
    }
  }
  if ((this->mSomeSpecialBGMFlag != 1) && (*(char *)&this->field_0x206 != '\x01')) {
    puVar2 = (undefined1 *)this->field_0x78;
    if (puVar2 != &DAT_8000000a) {
      if ((int)puVar2 < -0x7ffffff6) {
        if (puVar2 != &DAT_80000004) {
          if ((int)puVar2 < -0x7ffffffc) {
            if (-0x7ffffffe < (int)puVar2) goto LAB_802a5398;
          }
          else {
            if ((int)puVar2 < -0x7ffffffa) goto LAB_802a5398;
          }
        }
      }
      else {
        if ((puVar2 == &DAT_80000105) || (((int)puVar2 < -0x7ffffefb && (puVar2 == &DAT_80000010))))
        goto LAB_802a5398;
      }
      if (((*(char *)&this->field_0x207 == '\0') &&
          ((((*(int *)&this->field_0x6c == 0 ||
             ((this->field_0x74 != -0x7fffffd5 && (this->field_0x74 != -0x7fffffba)))) &&
            ((undefined *)this->field_0x78 != &DAT_80000021)) &&
           ((undefined *)this->field_0x78 != &DAT_80000022)))) &&
         (((*(int *)&this->field_0x6c == 0 ||
           (((undefined *)this->field_0x74 != &DAT_80000041 &&
            ((undefined *)this->field_0x74 != (undefined *)0x80000047)))) &&
          (*(char *)&this->field_0xce == '\0')))) {
        if (((undefined *)this->field_0x74 == &DAT_80000019) ||
           ((undefined *)this->field_0x74 == &DAT_8000001a)) {
          mbossBgmNearByProcess(this,param_1);
        }
        else {
          if ((*(char *)&this->field_0xbb == '\0') && (this->mLastMinibossSubBGMType == 0)) {
            *(undefined *)&this->field_0xc0 = JAIZelParam::COMMON_BATTLE_FO_DELAY;
            if ((*(int *)&this->field_0x6c == 0) ||
               (((undefined1 *)this->field_0x74 != &DAT_80000004 &&
                ((undefined1 *)this->field_0x74 != &DAT_8000001c)))) {
              iVar1 = checkLinkOnSea(this);
              if (iVar1 == 1) {
                JAIBasic::startSoundVec
                          ((JAIBasic *)this,(JAISoundInfoID)&DAT_8000001c,
                           (JAISound **)&this->field_0x6c,(Vec *)0x0,0x3c,0,'\x04');
                this->field_0x74 = (int)&DAT_8000001c;
              }
              else {
                JAIBasic::startSoundVec
                          ((JAIBasic *)this,(JAISoundInfoID)&DAT_80000004,
                           (JAISound **)&this->field_0x6c,(Vec *)0x0,0x3c,0,'\x04');
                this->field_0x74 = (int)&DAT_80000004;
              }
              if (*(JAISound **)&this->field_0x6c != (JAISound *)0x0) {
                JAISound::setSeqInterVolume(*(JAISound **)&this->field_0x6c,'\0',this->field_0xa0,0)
                ;
              }
              this->field_0x8c = JAZelAudio::_4004;
              if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
                JAISound::setVolume(*(JAISound **)&this->field_0x68,
                                    this->field_0xac *
                                    this->field_0x9c *
                                    this->field_0x98 *
                                    this->field_0x94 *
                                    this->field_0x90 *
                                    this->field_0x8c *
                                    this->field_0x88 * this->field_0x80 * this->field_0x84,0x3c,0);
              }
              iVar1 = checkLinkOnSea(this);
              if (iVar1 == 1) {
                iVar1 = checkLinkOnBoardSea(this);
                if (iVar1 == 1) {
                  bgmMute(this,(JAISound **)&this->field_0x6c,(ulong)&DAT_8000001c,0,0);
                }
                else {
                  bgmMute(this,(JAISound **)&this->field_0x6c,(ulong)&DAT_8000001c,1,0);
                }
              }
              else {
                bgmMute(this,(JAISound **)&this->field_0x6c,(ulong)&DAT_80000004,0,0);
              }
            }
            if ((*(int *)&this->field_0x6c != 0) && ((undefined *)this->field_0x74 != &DAT_8000001c)
               ) {
              if ((double)_ENEMY_NEARBY_DIST < dVar4) {
                if (*(char *)&this->field_0xc1 == '\x01') {
                  *(undefined4 *)&this->field_0xc4 = _ENEMY_NEARBY_FADEOUT_TIME;
                  *(undefined *)&this->field_0xc1 = 0;
                }
              }
              else {
                *(undefined4 *)&this->field_0xc4 = 0;
                if (*(char *)&this->field_0xc1 == '\0') {
                  JAISound::setTrackVolume
                            (*(JAISound **)&this->field_0x6c,JAIZelParam::ENEMY_NEARBY_TRACK,
                             JAZelAudio::1_0,_ENEMY_NEARBY_FADEIN_TIME);
                  JAISound::setTrackVolume
                            (*(JAISound **)&this->field_0x6c,JAIZelParam::ENEMY_NEARBY_TRACK_2,
                             JAZelAudio::1_0,_ENEMY_NEARBY_FADEIN_TIME);
                  *(undefined *)&this->field_0xc1 = 1;
                }
              }
              if (*(char *)&this->field_0xc9 == '\0') {
                JAISound::setTrackVolume
                          (*(JAISound **)&this->field_0x6c,JAIZelParam::SWORD_NOT_USING_TRACK,
                           JAZelAudio::1_0,_BTL_SWORD_USING_FADE_TIME);
                JAISound::setTrackVolume
                          (*(JAISound **)&this->field_0x6c,JAIZelParam::SWORD_USING_TRACK,
                           JAZelAudio::_4004,_BTL_SWORD_USING_FADE_TIME);
              }
              else {
                JAISound::setTrackVolume
                          (*(JAISound **)&this->field_0x6c,JAIZelParam::SWORD_USING_TRACK,
                           JAZelAudio::1_0,_BTL_SWORD_USING_FADE_TIME);
                JAISound::setTrackVolume
                          (*(JAISound **)&this->field_0x6c,JAIZelParam::SWORD_NOT_USING_TRACK,
                           JAZelAudio::_4004,_BTL_SWORD_USING_FADE_TIME);
              }
            }
          }
        }
      }
    }
  }
LAB_802a5398:
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::bgmBattleGFrame(void) */

void __thiscall JAIZelBasic::bgmBattleGFrame(JAIZelBasic *this)

{
  undefined1 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined1 *)this->field_0x74;
  if ((puVar1 == &DAT_80000004) || (puVar1 == &DAT_8000001c)) {
    if ((*(char *)&this->field_0xc0 == JAIZelParam::COMMON_BATTLE_FO_DELAY) ||
       (*(char *)&this->field_0xc0 != '\0')) {
      if (puVar1 == &DAT_80000004) {
        uVar2 = *(uint *)&this->field_0xc4;
        if (uVar2 < 2) {
          if (uVar2 == 1) {
            if (*(JAISound **)&this->field_0x6c != (JAISound *)0x0) {
              JAISound::setTrackVolume
                        (*(JAISound **)&this->field_0x6c,JAIZelParam::ENEMY_NEARBY_TRACK,
                         JAZelAudio::_4004,_ENEMY_NEARBY_FADEOUT_TIME);
              JAISound::setTrackVolume
                        (*(JAISound **)&this->field_0x6c,JAIZelParam::ENEMY_NEARBY_TRACK_2,
                         JAZelAudio::_4004,_ENEMY_NEARBY_FADEOUT_TIME);
            }
            *(undefined4 *)&this->field_0xc4 = 0;
          }
        }
        else {
          *(uint *)&this->field_0xc4 = uVar2 - 1;
        }
        if (*(char *)&this->field_0xc8 == '\0') {
          if ((*(JAISound **)&this->field_0x6c != (JAISound *)0x0) &&
             ((undefined1 *)this->field_0x74 == &DAT_80000004)) {
            JAISound::setTrackVolume
                      (*(JAISound **)&this->field_0x6c,JAIZelParam::BTL_KAITENGIRI_TRACK,
                       JAZelAudio::_4004,_BTL_KAITENGIRI_FADEOUT_TIME);
          }
        }
        else {
          *(char *)&this->field_0xc8 = *(char *)&this->field_0xc8 + -1;
        }
      }
      if (*(char *)&this->field_0xc0 != '\0') {
        *(char *)&this->field_0xc0 = *(char *)&this->field_0xc0 + -1;
      }
    }
    else {
      this->field_0x8c = JAZelAudio::1_0;
      if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
        JAISound::setVolume(*(JAISound **)&this->field_0x68,
                            this->field_0xac *
                            this->field_0x9c *
                            this->field_0x98 *
                            this->field_0x94 *
                            this->field_0x90 *
                            this->field_0x8c *
                            this->field_0x88 * this->field_0x80 * this->field_0x84,0x2d,0);
      }
      stopBattleBgm(this);
      *(undefined *)&this->field_0xc1 = 0;
      *(undefined4 *)&this->field_0xc4 = 0;
    }
  }
  return;
}


/* __thiscall JAIZelBasic::stopBattleBgm(void) */

void __thiscall JAIZelBasic::stopBattleBgm(JAIZelBasic *this)

{
  if ((*(JAISound **)&this->field_0x6c != (JAISound *)0x0) &&
     (((undefined1 *)this->field_0x74 == &DAT_80000004 ||
      ((undefined1 *)this->field_0x74 == &DAT_8000001c)))) {
    JAISound::stop(*(JAISound **)&this->field_0x6c,0x2d);
    *(undefined4 *)&this->field_0x6c = 0;
    this->field_0x74 = -1;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::bgmNowKaitengiri(void) */

void __thiscall JAIZelBasic::bgmNowKaitengiri(JAIZelBasic *this)

{
  JAISound *this_00;
  undefined1 *puVar1;
  
  if ((*(char *)&this->field_0xc8 == '\0') &&
     (this_00 = *(JAISound **)&this->field_0x6c, this_00 != (JAISound *)0x0)) {
    puVar1 = (undefined1 *)this->field_0x74;
    if ((int)puVar1 < -0x7fffffe7) {
      if (puVar1 == &DAT_80000004) {
        JAISound::setTrackVolume
                  (this_00,JAIZelParam::BTL_KAITENGIRI_TRACK,JAZelAudio::1_0,
                   _BTL_KAITENGIRI_FADEIN_TIME);
      }
    }
    else {
      if ((int)puVar1 < -0x7fffffe5) {
        JAISound::setTrackVolume
                  (this_00,JAIZelParam::MBOSS_BTL_KAITENGIRI_TRACK,JAZelAudio::1_0,
                   _BTL_KAITENGIRI_FADEIN_TIME);
      }
    }
  }
  *(undefined *)&this->field_0xc8 = 2;
  return;
}


/* __thiscall JAIZelBasic::bgmHitSound(long) */

void __thiscall JAIZelBasic::bgmHitSound(JAIZelBasic *this,long param_1)

{
  short sVar2;
  int iVar1;
  undefined1 *puVar3;
  TTrack *this_00;
  ushort local_18 [8];
  
  puVar3 = (undefined1 *)this->field_0x74;
  if ((int)puVar3 < -0x7fffffe7) {
    if (puVar3 != &DAT_80000004) {
      return;
    }
  }
  else {
    if (-0x7fffffe6 < (int)puVar3) {
      return;
    }
  }
  if (*(char *)&this->field_0xc9 == '\0') {
    return;
  }
  if (param_1 == 2) {
    sVar2 = 8;
    goto LAB_802a5734;
  }
  if (param_1 < 2) {
    if ((param_1 != 0) && (-1 < param_1)) {
      sVar2 = getRandomU32(this,2);
      sVar2 = sVar2 + 4;
      goto LAB_802a5734;
    }
  }
  else {
    if (param_1 == 4) {
      sVar2 = getRandomU32(this,2);
      sVar2 = sVar2 + 6;
      goto LAB_802a5734;
    }
    if (param_1 < 4) {
      sVar2 = getRandomU32(this,2);
      sVar2 = sVar2 + 9;
      goto LAB_802a5734;
    }
  }
  sVar2 = getRandomU32(this,4);
LAB_802a5734:
  if (*(JAISound **)&this->field_0x6c != (JAISound *)0x0) {
    iVar1 = JAISound::getSeqParameter(*(JAISound **)&this->field_0x6c);
    this_00 = (TTrack *)(iVar1 + 0x1360);
    local_18[0] = 0;
    JASystem::TTrack::readPortApp(this_00,0x100a0001,local_18);
    JASystem::TTrack::writePortApp(this_00,0x90000,sVar2 + 1);
    JASystem::TTrack::writePortApp(this_00,0xa0000,local_18[0]);
  }
  return;
}


/* __thiscall JAIZelBasic::bgmSetSwordUsing(long) */

void __thiscall JAIZelBasic::bgmSetSwordUsing(JAIZelBasic *this,long param_1)

{
  *(char *)&this->field_0xc9 = (char)param_1;
  return;
}


/* __thiscall JAIZelBasic::onEnemyDamage(void) */

void __thiscall JAIZelBasic::onEnemyDamage(JAIZelBasic *this)

{
  int iVar1;
  
  if ((undefined1 *)this->field_0x74 == &DAT_8000001c) {
    if (*(JAISound **)&this->field_0x6c != (JAISound *)0x0) {
      JAISound::setPortData(*(JAISound **)&this->field_0x6c,'\t',1);
    }
  }
  else {
    if ((undefined1 *)this->field_0x74 == &DAT_80000004) {
      if (*(JAISound **)&this->field_0x6c != (JAISound *)0x0) {
        iVar1 = JAISound::getSeqParameter(*(JAISound **)&this->field_0x6c);
        if ((TTrack *)(iVar1 + 0x1360) != (TTrack *)0x0) {
          JASystem::TTrack::writePortApp((TTrack *)(iVar1 + 0x1360),0xb0000,1);
        }
      }
    }
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::mbossBgmMuteProcess(void) */

void __thiscall JAIZelBasic::mbossBgmMuteProcess(JAIZelBasic *this)

{
  uint uVar1;
  JAISound *this_00;
  undefined *puVar2;
  
  puVar2 = (undefined *)this->field_0x74;
  if ((puVar2 == &DAT_80000019) || (puVar2 == &DAT_8000001a)) {
    uVar1 = *(uint *)&this->field_0xc4;
    if (uVar1 < 2) {
      if (uVar1 == 1) {
        if ((*(JAISound **)&this->field_0x6c != (JAISound *)0x0) &&
           ((puVar2 == &DAT_80000019 || (puVar2 == &DAT_8000001a)))) {
          JAISound::setTrackVolume
                    (*(JAISound **)&this->field_0x6c,JAIZelParam::MBOSS_ENEMY_NEARBY_TRACK,
                     JAZelAudio::_4004,_ENEMY_NEARBY_FADEOUT_TIME);
        }
        *(undefined4 *)&this->field_0xc4 = 0;
      }
    }
    else {
      *(uint *)&this->field_0xc4 = uVar1 - 1;
    }
    this_00 = *(JAISound **)&this->field_0x6c;
    if (this_00 != (JAISound *)0x0) {
      if (*(char *)&this->field_0xc9 == '\0') {
        JAISound::setTrackVolume
                  (this_00,JAIZelParam::MBOSS_SWORD_USING_TRACK,JAZelAudio::_4004,
                   _BTL_SWORD_USING_FADE_TIME);
      }
      else {
        JAISound::setTrackVolume
                  (this_00,JAIZelParam::MBOSS_SWORD_USING_TRACK,JAZelAudio::1_0,
                   _BTL_SWORD_USING_FADE_TIME);
      }
    }
    if (*(char *)&this->field_0xc8 == '\0') {
      if (*(JAISound **)&this->field_0x6c != (JAISound *)0x0) {
        JAISound::setTrackVolume
                  (*(JAISound **)&this->field_0x6c,JAIZelParam::MBOSS_BTL_KAITENGIRI_TRACK,
                   JAZelAudio::_4004,_BTL_KAITENGIRI_FADEOUT_TIME);
      }
    }
    else {
      *(char *)&this->field_0xc8 = *(char *)&this->field_0xc8 + -1;
    }
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::mbossBgmNearByProcess(float) */

void __thiscall JAIZelBasic::mbossBgmNearByProcess(JAIZelBasic *this,float param_1)

{
  if (*(int *)&this->field_0x6c != 0) {
    if (_ENEMY_NEARBY_DIST < param_1) {
      if (*(char *)&this->field_0xc1 == '\x01') {
        *(undefined4 *)&this->field_0xc4 = _ENEMY_NEARBY_FADEOUT_TIME;
        *(undefined *)&this->field_0xc1 = 0;
      }
    }
    else {
      *(undefined4 *)&this->field_0xc4 = 0;
      if (*(char *)&this->field_0xc1 == '\0') {
        JAISound::setTrackVolume
                  (*(JAISound **)&this->field_0x6c,JAIZelParam::MBOSS_ENEMY_NEARBY_TRACK,
                   JAZelAudio::1_0,_ENEMY_NEARBY_FADEIN_TIME);
        *(undefined *)&this->field_0xc1 = 1;
      }
    }
  }
  return;
}


/* __thiscall JAIZelBasic::checkBgmPlaying(void) */

undefined4 __thiscall JAIZelBasic::checkBgmPlaying(JAIZelBasic *this)

{
  if ((*(int *)&this->field_0x68 == 0) && (this->mpSound == (JAISound *)0x0)) {
    return 0;
  }
  return 1;
}


/* __thiscall JAIZelBasic::checkPlayingMainBgmFlag(void) */

undefined4 __thiscall JAIZelBasic::checkPlayingMainBgmFlag(JAIZelBasic *this)

{
  if (*(int *)&this->field_0x68 != 0) {
    return *(undefined4 *)(*(int *)&this->field_0x68 + 0xc);
  }
  return 0xffffffff;
}


/* __thiscall JAIZelBasic::checkSubBgmPlaying(void) */

bool __thiscall JAIZelBasic::checkSubBgmPlaying(JAIZelBasic *this)

{
  return *(int *)&this->field_0x6c != 0;
}


/* __thiscall JAIZelBasic::checkPlayingSubBgmFlag(void) */

undefined4 __thiscall JAIZelBasic::checkPlayingSubBgmFlag(JAIZelBasic *this)

{
  if (*(int *)&this->field_0x6c != 0) {
    return *(undefined4 *)(*(int *)&this->field_0x6c + 0xc);
  }
  return 0xffffffff;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::checkPlayingStreamBgmFlag(void) */

undefined4 __thiscall JAIZelBasic::checkPlayingStreamBgmFlag(JAIZelBasic *this)

{
  if (*(int *)(_streamUpdate + 0x14) == 0) {
    return 0xffffffff;
  }
  return *(undefined4 *)(*(int *)(_streamUpdate + 0x14) + 0xc);
}


/* __thiscall JAIZelBasic::changeBgmStatus(long) */

void __thiscall JAIZelBasic::changeBgmStatus(JAIZelBasic *this,long param_1)

{
  if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
    JAISound::setPortData(*(JAISound **)&this->field_0x68,'\t',(ushort)param_1);
  }
  return;
}


/* __thiscall JAIZelBasic::changeSubBgmStatus(long) */

void __thiscall JAIZelBasic::changeSubBgmStatus(JAIZelBasic *this,long param_1)

{
  int iVar1;
  
  if (*(JAISound **)&this->field_0x6c != (JAISound *)0x0) {
    iVar1 = JAISound::getSeqParameter(*(JAISound **)&this->field_0x6c);
    JASystem::TTrack::writePortApp((TTrack *)(iVar1 + 0x1360),0x90000,(ushort)param_1);
  }
  return;
}


/* __thiscall JAIZelBasic::bgmMuteMtDragon(void) */

void __thiscall JAIZelBasic::bgmMuteMtDragon(JAIZelBasic *this)

{
  *(undefined *)&this->field_0x65 = 1;
  return;
}


/* __thiscall JAIZelBasic::enemyNearBy(void) */

void __thiscall JAIZelBasic::enemyNearBy(JAIZelBasic *this)

{
  if (((*(int *)&this->field_0x68 != 0) && ((undefined *)this->field_0x78 == &DAT_80000014)) &&
     (*(char *)&this->field_0xcb == -1)) {
    if (*(char *)&this->field_0xcc == '\0') {
      bgmStart(this,(uint)&DAT_80000111,0,0);
    }
    else {
      bgmStart(this,(uint)&DAT_80000112,0,0);
    }
  }
  if (((*(int *)&this->field_0x68 != 0) && ((undefined *)this->field_0x78 == &DAT_80000015)) &&
     (*(char *)&this->field_0xcb == -1)) {
    bgmStart(this,(uint)&DAT_80000115,0,0);
  }
  *(undefined *)&this->field_0xcb = JAIZelParam::COMMON_BATTLE_FO_DELAY;
  return;
}


/* __thiscall JAIZelBasic::enemyNearByGFrame(void) */

void __thiscall JAIZelBasic::enemyNearByGFrame(JAIZelBasic *this)

{
  if (this->field_0x224 == 9) {
    if (*(char *)&this->field_0xcb == '\0') {
      if ((*(int *)&this->field_0x68 != 0) && ((undefined *)this->field_0x78 == &DAT_80000014)) {
        if (*(char *)&this->field_0xcc == '\0') {
          bgmStart(this,(uint)&DAT_80000014,0,0);
        }
        else {
          bgmStart(this,(uint)&DAT_80000110,0,0);
        }
      }
      if ((*(int *)&this->field_0x68 != 0) && ((undefined *)this->field_0x78 == &DAT_80000015)) {
        bgmStart(this,(uint)&DAT_80000015,0,0);
      }
      *(undefined *)&this->field_0xcb = 0xff;
    }
    if ('\0' < *(char *)&this->field_0xcb) {
      *(char *)&this->field_0xcb = *(char *)&this->field_0xcb + -1;
    }
  }
  return;
}


/* __thiscall JAIZelBasic::bgmAllMute(unsigned long) */

void __thiscall JAIZelBasic::bgmAllMute(JAIZelBasic *this,ulong param_1)

{
  this->field_0x80 = JAZelAudio::_4004;
  if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
    JAISound::setVolume(*(JAISound **)&this->field_0x68,
                        this->field_0xac *
                        this->field_0x9c *
                        this->field_0x98 *
                        this->field_0x94 *
                        this->field_0x90 *
                        this->field_0x8c * this->field_0x88 * this->field_0x80 * this->field_0x84,
                        param_1,0);
  }
  return;
}


/* __thiscall JAIZelBasic::taktModeMute(void) */

void __thiscall JAIZelBasic::taktModeMute(JAIZelBasic *this)

{
  this->field_0x98 = JAZelAudio::_4004;
  if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
    if (((undefined *)this->field_0x78 == &DAT_80000021) ||
       ((undefined *)this->field_0x78 == &DAT_80000022)) {
      this->field_0x98 = JAZelAudio::1_0;
    }
    else {
      JAISound::setVolume(*(JAISound **)&this->field_0x68,
                          this->field_0xac *
                          this->field_0x9c *
                          this->field_0x98 *
                          this->field_0x94 *
                          this->field_0x90 *
                          this->field_0x8c * this->field_0x88 * this->field_0x80 * this->field_0x84,
                          10,0);
    }
  }
  this->field_0xa4 = JAZelAudio::_4004;
  if (*(JAISound **)&this->field_0x6c != (JAISound *)0x0) {
    JAISound::setVolume(*(JAISound **)&this->field_0x6c,
                        this->field_0xa8 * this->field_0xa0 * this->field_0xa4,10,0);
  }
  return;
}


/* __thiscall JAIZelBasic::taktModeMuteOff(void) */

void __thiscall JAIZelBasic::taktModeMuteOff(JAIZelBasic *this)

{
  this->field_0x98 = JAZelAudio::1_0;
  if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
    JAISound::setVolume(*(JAISound **)&this->field_0x68,
                        this->field_0xac *
                        this->field_0x9c *
                        this->field_0x98 *
                        this->field_0x94 *
                        this->field_0x90 *
                        this->field_0x8c * this->field_0x88 * this->field_0x80 * this->field_0x84,10
                        ,0);
  }
  if ((undefined *)this->field_0x74 == &DAT_80000031) {
    this->field_0x8c = JAZelAudio::1_0;
    if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
      JAISound::setVolume(*(JAISound **)&this->field_0x68,
                          this->field_0xac *
                          this->field_0x9c *
                          this->field_0x98 *
                          this->field_0x94 *
                          this->field_0x90 *
                          this->field_0x8c * this->field_0x88 * this->field_0x80 * this->field_0x84,
                          0x2d,0);
    }
  }
  this->field_0xa4 = JAZelAudio::1_0;
  if (*(JAISound **)&this->field_0x6c != (JAISound *)0x0) {
    JAISound::setVolume(*(JAISound **)&this->field_0x6c,
                        this->field_0xa8 * this->field_0xa0 * this->field_0xa4,10,0);
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x802a6188) */
/* WARNING: Removing unreachable block (ram,0x802a6180) */
/* WARNING: Removing unreachable block (ram,0x802a6190) */
/* __thiscall JAIZelBasic::cbPracticePlay(Vec *) */

void __thiscall JAIZelBasic::cbPracticePlay(JAIZelBasic *this,Vec *param_1)

{
  MTX34 *pMtx;
  float *pfVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  cXyz local_48;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  *(Vec **)&this->field_0xd0 = param_1;
  pMtx = (MTX34 *)(*(float ***)&this->field_0x4)[2];
  local_48.x = JAZelAudio::_5341;
  local_48.y = DAT_8036a10c;
  local_48.z = DAT_8036a110;
  if (param_1 == (Vec *)0x0) {
    pfVar1 = **(float ***)&this->field_0x4;
    if (pfVar1 != (float *)0x0) {
      local_48.x = *pfVar1;
      local_48.y = pfVar1[1];
      local_48.z = pfVar1[2];
    }
  }
  else {
    local_48.x = *(float *)param_1;
    local_48.y = *(float *)(param_1 + 4);
    local_48.z = *(float *)(param_1 + 8);
  }
  if (pMtx != (MTX34 *)0x0) {
    mtx::PSMTXMultVec(pMtx,&local_48,&local_48);
  }
  if (this->field_0x224 == 0x39) {
    JAIBasic::startSoundVec
              ((JAIBasic *)this,0x80000037,(JAISound **)&this->field_0x6c,(Vec *)0x0,0,0,'\x04');
    this->field_0x74 = -0x7fffffc9;
  }
  else {
    JAIBasic::startSoundVec
              ((JAIBasic *)this,0x80000036,(JAISound **)&this->field_0x6c,(Vec *)0x0,0,0,'\x04');
    this->field_0x74 = -0x7fffffca;
  }
  if (*(JAISound **)&this->field_0x6c != (JAISound *)0x0) {
    JAISound::setSeqInterVolume(*(JAISound **)&this->field_0x6c,'\0',this->field_0xa0,0);
  }
  dVar3 = (double)calcPosVolume(this,(Vec *)&local_48,JAZelAudio::_5371);
  dVar4 = (double)calcPosPanLR(this,(Vec *)&local_48);
  dVar5 = (double)calcPosPanSR(this,(Vec *)&local_48,JAZelAudio::1_0);
  this->field_0xa8 = (float)dVar3;
  if (*(JAISound **)&this->field_0x6c != (JAISound *)0x0) {
    JAISound::setVolume(*(JAISound **)&this->field_0x6c,
                        this->field_0xa8 * this->field_0xa0 * this->field_0xa4,0,0);
    JAISound::setPan(*(JAISound **)&this->field_0x6c,(float)dVar4,0,'\0');
    JAISound::setDolby(*(JAISound **)&this->field_0x6c,(float)dVar5,0,'\0');
  }
  if (this->field_0x224 == 0x27) {
    this->field_0x9c = JAZelAudio::1_0 - (float)((double)JAZelAudio::_5372 * dVar3);
  }
  else {
    this->field_0x9c = (float)((double)JAZelAudio::1_0 - dVar3);
  }
  if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
    JAISound::setVolume(*(JAISound **)&this->field_0x68,
                        this->field_0xac *
                        this->field_0x9c *
                        this->field_0x98 *
                        this->field_0x94 *
                        this->field_0x90 *
                        this->field_0x8c * this->field_0x88 * this->field_0x80 * this->field_0x84,
                        0x1e,0);
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  return;
}


/* WARNING: Removing unreachable block (ram,0x802a6410) */
/* WARNING: Removing unreachable block (ram,0x802a6408) */
/* WARNING: Removing unreachable block (ram,0x802a6418) */
/* __thiscall JAIZelBasic::cbPracticeProcess(void) */

void __thiscall JAIZelBasic::cbPracticeProcess(JAIZelBasic *this)

{
  int iVar1;
  MTX34 *pMtx;
  float *pfVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  cXyz local_48;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if (*(int *)&this->field_0xd0 != 0) {
    iVar1 = checkCbPracticePlay(this);
    if (iVar1 == 0) {
      if (JAZelAudio::1_0 != this->field_0x9c) {
        this->field_0x9c = JAZelAudio::1_0;
        if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
          JAISound::setVolume(*(JAISound **)&this->field_0x68,
                              this->field_0xac *
                              this->field_0x9c *
                              this->field_0x98 *
                              this->field_0x94 *
                              this->field_0x90 *
                              this->field_0x8c *
                              this->field_0x88 * this->field_0x80 * this->field_0x84,0,0);
        }
      }
    }
    else {
      pMtx = (MTX34 *)(*(float ***)&this->field_0x4)[2];
      local_48.x = JAZelAudio::_5384;
      local_48.y = DAT_8036a118;
      local_48.z = DAT_8036a11c;
      pfVar2 = *(float **)&this->field_0xd0;
      if (pfVar2 == (float *)0x0) {
        pfVar2 = **(float ***)&this->field_0x4;
        if (pfVar2 != (float *)0x0) {
          local_48.x = *pfVar2;
          local_48.y = pfVar2[1];
          local_48.z = pfVar2[2];
        }
      }
      else {
        local_48.x = *pfVar2;
        local_48.y = pfVar2[1];
        local_48.z = pfVar2[2];
      }
      if (pMtx != (MTX34 *)0x0) {
        mtx::PSMTXMultVec(pMtx,&local_48,&local_48);
      }
      dVar4 = (double)calcPosVolume(this,(Vec *)&local_48,JAZelAudio::_5371);
      dVar5 = (double)calcPosPanLR(this,(Vec *)&local_48);
      dVar6 = (double)calcPosPanSR(this,(Vec *)&local_48,JAZelAudio::1_0);
      this->field_0xa8 = (float)dVar4;
      if (*(JAISound **)&this->field_0x6c != (JAISound *)0x0) {
        JAISound::setVolume(*(JAISound **)&this->field_0x6c,
                            this->field_0xa8 * this->field_0xa0 * this->field_0xa4,0,0);
        JAISound::setPan(*(JAISound **)&this->field_0x6c,(float)dVar5,0,'\0');
        JAISound::setDolby(*(JAISound **)&this->field_0x6c,(float)dVar6,0,'\0');
      }
      if (this->field_0x224 == 0x27) {
        this->field_0x9c = JAZelAudio::1_0 - (float)((double)JAZelAudio::_5372 * dVar4);
      }
      else {
        this->field_0x9c = (float)((double)JAZelAudio::1_0 - dVar4);
      }
      if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
        JAISound::setVolume(*(JAISound **)&this->field_0x68,
                            this->field_0xac *
                            this->field_0x9c *
                            this->field_0x98 *
                            this->field_0x94 *
                            this->field_0x90 *
                            this->field_0x8c *
                            this->field_0x88 * this->field_0x80 * this->field_0x84,0,0);
      }
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  return;
}


/* __thiscall JAIZelBasic::cbPracticeStop(void) */

void __thiscall JAIZelBasic::cbPracticeStop(JAIZelBasic *this)

{
  float fVar1;
  
  if ((*(JAISound **)&this->field_0x6c != (JAISound *)0x0) &&
     ((this->field_0x74 == -0x7fffffca || (this->field_0x74 == -0x7fffffc9)))) {
    JAISound::stop(*(JAISound **)&this->field_0x6c,0xf);
    *(undefined4 *)&this->field_0x6c = 0;
    this->field_0x74 = -1;
  }
  fVar1 = JAZelAudio::1_0;
  this->field_0xa8 = JAZelAudio::1_0;
  this->field_0x9c = fVar1;
  if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
    JAISound::setVolume(*(JAISound **)&this->field_0x68,
                        this->field_0xac *
                        this->field_0x9c *
                        this->field_0x98 *
                        this->field_0x94 *
                        this->field_0x90 *
                        this->field_0x8c * this->field_0x88 * this->field_0x80 * this->field_0x84,
                        0x5a,0);
  }
  *(undefined4 *)&this->field_0xd0 = 0;
  return;
}


/* __thiscall JAIZelBasic::checkCbPracticePlay(void) */

undefined4 __thiscall JAIZelBasic::checkCbPracticePlay(JAIZelBasic *this)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = checkSubBgmPlaying(this);
  if ((iVar1 == 1) &&
     ((iVar1 = checkPlayingSubBgmFlag(this), iVar1 == -0x7fffffca ||
      (iVar1 = checkPlayingSubBgmFlag(this), iVar1 == -0x7fffffc9)))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __thiscall JAIZelBasic::prepareLandingDemo(long) */

void __thiscall JAIZelBasic::prepareLandingDemo(JAIZelBasic *this,long param_1)

{
  this->mbLandingDemoStarted = (byte)param_1;
  bgmStop(this,0x5a,0);
  return;
}


/* __thiscall JAIZelBasic::startLandingDemo(void) */

void __thiscall JAIZelBasic::startLandingDemo(JAIZelBasic *this)

{
  byte bVar1;
  
  bVar1 = this->mbLandingDemoStarted;
  if (bVar1 == 3) {
    bgmStart(this,0x80000039,0,0);
  }
  else {
    if (((bVar1 < 3) && (bVar1 != 1)) && (bVar1 != 0)) {
      bgmStart(this,0x8000003a,0,0);
    }
  }
  return;
}


/* __thiscall JAIZelBasic::endLandingDemo(void) */

void __thiscall JAIZelBasic::endLandingDemo(JAIZelBasic *this)

{
  this->mbLandingDemoStarted = 0;
  return;
}


/* __thiscall JAIZelBasic::initSe(void) */

void __thiscall JAIZelBasic::initSe(JAIZelBasic *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  **(undefined4 **)&this->field_0x4 = 0;
  *(undefined4 *)(*(int *)&this->field_0x4 + 4) = 0;
  *(undefined4 *)(*(int *)&this->field_0x4 + 8) = 0;
  *(undefined4 *)&this->field_0x1f4 = 0;
  iVar1 = 0;
  iVar3 = 0x18;
  do {
    iVar2 = (int)&this->vtbl + iVar1;
    *(undefined4 *)(iVar2 + 0xd4) = 0;
    *(undefined4 *)(iVar2 + 0x134) = 0;
    *(undefined4 *)(iVar2 + 0x194) = 0;
    iVar1 = iVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar1 = 0;
  iVar3 = 4;
  do {
    iVar2 = (int)&this->vtbl + iVar1;
    *(undefined4 *)(iVar2 + 0x2040) = 0;
    *(undefined4 *)(iVar2 + 0x2050) = 0;
    iVar1 = iVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined *)&this->field_0x203c = 0;
  *(undefined *)&this->field_0x203d = 0;
  *(undefined4 *)&this->field_0x2064 = 0;
  *(undefined4 *)&this->field_0x20c = 0;
  *(undefined4 *)&this->field_0x210 = 0;
  *(undefined4 *)&this->field_0x218 = 0;
  *(undefined4 *)&this->field_0x1b80 = 0;
  *(undefined4 *)&this->field_0x1dd0 = 0;
  *(undefined4 *)&this->field_0x1e98 = 0;
  *(undefined4 *)&this->field_0x1f38 = 0;
  *(undefined4 *)&this->field_0x1ec4 = 0;
  *(undefined4 *)&this->field_0x1ec8 = 0;
  *(undefined4 *)&this->field_0x1ecc = 0;
  *(undefined4 *)&this->field_0x1ed0 = 0;
  *(undefined4 *)&this->field_0x1f44 = 0;
  *(undefined4 *)&this->field_0x1f48 = 0;
  *(undefined4 *)&this->field_0x2060 = 0;
  *(undefined4 *)&this->field_0x214 = 0;
  this->field_0x20 = 0;
  *(undefined4 *)&this->field_0x1f34 = 0;
  this->field_0x1f9 = 0;
  *(undefined *)&this->field_0x1fb = 0;
  *(undefined *)&this->field_0x1fc = 0;
  this->field_0x201 = 0;
  monsSeInit(this);
  initLevObjSE(this);
  *(undefined *)&this->field_0xba = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x802a8528) */
/* WARNING: Removing unreachable block (ram,0x802a8518) */
/* WARNING: Removing unreachable block (ram,0x802a8510) */
/* WARNING: Removing unreachable block (ram,0x802a8520) */
/* WARNING: Removing unreachable block (ram,0x802a8530) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::seStart(unsigned long,
                                   Vec *,
                                   unsigned long,
                                   signed char,
                                   float,
                                   float,
                                   float,
                                   float,
                                   unsigned char) */

JAISound ** __thiscall
JAIZelBasic::seStart
          (JAIZelBasic *this,ulong soundId,cXyz *param_2,ulong param_3,sbyte param_4,float param_5,
          float param_6,float param_7,float param_8,byte param_9)

{
  float fVar1;
  float fVar2;
  undefined *puVar3;
  ushort uVar4;
  ushort uVar5;
  JAISound **ppJVar6;
  MTX34 *pMtx;
  JAISound *this_00;
  float *pfVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  undefined8 in_f27;
  double dVar15;
  undefined8 in_f28;
  double dVar16;
  undefined8 in_f29;
  double dVar17;
  undefined8 in_f30;
  undefined8 in_f31;
  cXyz local_8c;
  undefined4 local_80;
  ulong uStack124;
  undefined4 local_78;
  ulong uStack116;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar13 = (double)param_8;
  dVar17 = (double)param_7;
  dVar16 = (double)param_6;
  dVar15 = (double)param_5;
  uVar11 = 0;
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
  if (this->field_0x201 == 1) {
    ppJVar6 = (JAISound **)0x0;
    goto LAB_802a8510;
  }
  if ((0x5879 < soundId) && (soundId < 0x587d)) {
    kuroboMotionPlay(this,soundId,(Vec *)param_2,param_3,param_4);
    ppJVar6 = (JAISound **)0x0;
    goto LAB_802a8510;
  }
  if ((0x592c < soundId) && (soundId < 0x5930)) {
    kuroboMotionPlay(this,soundId,(Vec *)param_2,param_3,param_4);
    ppJVar6 = (JAISound **)0x0;
    goto LAB_802a8510;
  }
  if (this->field_0x224 != 0x2d) goto LAB_802a6854;
  if (soundId == 0x7051) {
    ppJVar6 = (JAISound **)0x0;
    goto LAB_802a8510;
  }
  if ((int)soundId < 0x5930) {
    if ((soundId != 0x5135) && ((0x5134 < (int)soundId || (soundId != 0x383c)))) {
LAB_802a6854:
      if ((0x486c < soundId) && (soundId < 0x4870)) {
        m_Do_printf::OSReport("クロボーの声は monsSeStartで！\n");
        ppJVar6 = (JAISound **)0x0;
        goto LAB_802a8510;
      }
      if (((undefined *)this->field_0x78 == &DAT_80000012) &&
         ((soundId == 0x580e || (soundId == 0x580d)))) {
        ppJVar6 = (JAISound **)0x0;
        goto LAB_802a8510;
      }
      if ((*(char *)&this->field_0x206 != '\0') &&
         (((soundId < 0x690b || (0x6913 < soundId)) && ((soundId & 0xfffff000) != 0)))) {
        ppJVar6 = (JAISound **)0x0;
        goto LAB_802a8510;
      }
      if ((*(char *)&this->field_0x207 != '\0') && ((soundId & 0xfffff000) != 0)) {
        if ((int)soundId < 0x2882) {
          if (soundId != 0x2868) {
            if ((int)soundId < 0x2868) {
              if (soundId != 0x2066) goto LAB_802a6934;
            }
            else {
              if ((int)soundId < 0x2880) goto LAB_802a6934;
            }
          }
        }
        else {
          if ((int)soundId < 0x4901) {
            if (soundId != 0x48a1) {
LAB_802a6934:
              ppJVar6 = (JAISound **)0x0;
              goto LAB_802a8510;
            }
          }
          else {
            if (0x4902 < (int)soundId) goto LAB_802a6934;
          }
        }
      }
      if (soundId == 0x3814) {
        if (this->field_0x1f9 == 1) {
          ppJVar6 = (JAISound **)0x0;
          goto LAB_802a8510;
        }
        this->field_0x1f9 = 1;
        if (((this->field_0x224 == 0x12) && (this->mIslandRoomNo == 0x2c)) &&
           ((*(char *)&this->field_0x239 == '\t' && (*(uint *)&this->field_0x28 < 0x1e)))) {
          ppJVar6 = (JAISound **)0x0;
          goto LAB_802a8510;
        }
      }
      if (soundId == 0x6847) {
        if (*(char *)&this->field_0x1fc == '\x01') {
          ppJVar6 = (JAISound **)0x0;
          goto LAB_802a8510;
        }
        *(undefined *)&this->field_0x1fc = 1;
      }
      if (soundId == 0x693f) {
        if (*(char *)&this->field_0x1fb == '\x01') {
          ppJVar6 = (JAISound **)0x0;
          goto LAB_802a8510;
        }
        *(undefined *)&this->field_0x1fb = 1;
      }
      if (soundId == 0x282c) {
        if (*(char *)&this->field_0x1fa != '\0') {
          ppJVar6 = (JAISound **)0x0;
          goto LAB_802a8510;
        }
        *(undefined *)&this->field_0x1fa = 4;
      }
      if ((soundId == 0x6932) || (soundId == 0x69e6)) {
        if (*(char *)&this->field_0x202 != '\0') {
          ppJVar6 = (JAISound **)0x0;
          goto LAB_802a8510;
        }
        *(undefined *)&this->field_0x202 = 2;
      }
      if (soundId == 0x6806) {
        if (*(char *)&this->field_0x203 != '\0') {
          ppJVar6 = (JAISound **)0x0;
          goto LAB_802a8510;
        }
        *(undefined *)&this->field_0x203 = 2;
      }
      if (soundId == 0x6a42) {
        if (*(char *)&this->field_0x1fd != '\0') {
          ppJVar6 = (JAISound **)0x0;
          goto LAB_802a8510;
        }
        *(undefined *)&this->field_0x1fd = 0x14;
      }
      if (soundId == 0x6a43) {
        if (*(char *)&this->field_0x1fe != '\0') {
          ppJVar6 = (JAISound **)0x0;
          goto LAB_802a8510;
        }
        *(undefined *)&this->field_0x1fe = 0x14;
      }
      if (soundId == 0x6a44) {
        if (*(char *)&this->field_0x1ff != '\0') {
          ppJVar6 = (JAISound **)0x0;
          goto LAB_802a8510;
        }
        *(undefined *)&this->field_0x1ff = 0x14;
      }
      if (soundId == 0x6a45) {
        if (*(char *)&this->field_0x200 != '\0') {
          ppJVar6 = (JAISound **)0x0;
          goto LAB_802a8510;
        }
        *(undefined *)&this->field_0x200 = 0x14;
      }
      if (soundId == 0xffffffff) {
        ppJVar6 = (JAISound **)0x0;
        goto LAB_802a8510;
      }
      if (((soundId & 0xffffff00) == 0x1800) && ((soundId & 0xff) < 0x5a)) {
        JAIBasic::startSoundVec
                  ((JAIBasic *)this,soundId,(JAISound **)&this->field_0x2064,(Vec *)param_2,0,0,
                   '\x04');
        if (*(JAISound **)&this->field_0x2064 != (JAISound *)0x0) {
          JAISound::setPortData(*(JAISound **)&this->field_0x2064,'\t',(short)param_4);
        }
        ppJVar6 = (JAISound **)0x0;
        goto LAB_802a8510;
      }
      pMtx = (MTX34 *)(*(float ***)&this->field_0x4)[2];
      local_8c.x = JAZelAudio::_5583;
      local_8c.y = DAT_8036a124;
      local_8c.z = DAT_8036a128;
      if (param_2 == (cXyz *)0x0) {
        pfVar7 = **(float ***)&this->field_0x4;
        if (pfVar7 != (float *)0x0) {
          local_8c.x = *pfVar7;
          local_8c.y = pfVar7[1];
          local_8c.z = pfVar7[2];
        }
      }
      else {
        local_8c.x = param_2->x;
        local_8c.y = param_2->y;
        local_8c.z = param_2->z;
      }
      if (soundId == 0x381f) {
LAB_802a7018:
        ppJVar6 = (JAISound **)0x0;
        goto LAB_802a8510;
      }
      if ((int)soundId < 0x381f) {
        if (soundId == 0x8e4) {
          if (99 < param_3) {
            param_3 = 100;
          }
          if (param_3 != 0) {
            param_3 = param_3 - 1;
          }
          local_78 = 0x43300000;
          dVar15 = (double)(JAZelAudio::1_0 +
                           JAZelAudio::_6047 *
                           (float)((double)CONCAT44(0x43300000,param_3) - JAZelAudio::_6050));
          uStack116 = param_3;
        }
        else {
          if ((int)soundId < 0x8e4) {
            if (soundId == 0x825) {
LAB_802a75ec:
              iVar9 = checkStreamPlaying(this,0xc0000005);
              if (iVar9 == 1) {
                ppJVar6 = (JAISound **)0x0;
                goto LAB_802a8510;
              }
              iVar9 = isDemo(this);
              if (iVar9 == 1) {
                ppJVar6 = (JAISound **)0x0;
                goto LAB_802a8510;
              }
              if (*(char *)&this->field_0x207 != '\0') {
                ppJVar6 = (JAISound **)0x0;
                goto LAB_802a8510;
              }
              if (this->field_0xbe != 0) {
                ppJVar6 = (JAISound **)0x0;
                goto LAB_802a8510;
              }
            }
            else {
              if ((int)soundId < 0x825) {
                if (soundId == 0x80b) {
                  iVar9 = checkStreamPlaying(this,0xc0000005);
                  if (iVar9 == 1) {
                    ppJVar6 = (JAISound **)0x0;
                    goto LAB_802a8510;
                  }
                  iVar9 = isDemo(this);
                  if ((iVar9 == 1) || (*(char *)&this->field_0x207 != '\0')) {
                    soundId = JA_SE_DEMO_MSG_NEXT;
                  }
                  if (this->field_0xbe != 0) {
                    ppJVar6 = (JAISound **)0x0;
                    goto LAB_802a8510;
                  }
                }
                else {
                  if ((int)soundId < 0x80b) {
                    if (soundId == 0x804) {
LAB_802a778c:
                      seStop(this,0x805,0);
                      seStop(this,0x81d,0);
                    }
                    else {
                      if ((int)soundId < 0x804) {
                        if (soundId == 0x1b) goto LAB_802a7018;
                        if (((int)soundId < 0x1b) && (soundId == 8)) {
                          if (param_3 < 0xccc) {
                            param_3 = 0xccc;
                          }
                          else {
                            if (0x8000 < param_3) {
                              param_3 = 0x8000;
                            }
                          }
                          JAIBasic::startSoundVec
                                    ((JAIBasic *)this,JA_STRM_DK_START,
                                     (JAISound **)&this->field_0x214,(Vec *)0x0,0,0,'\x04');
                          local_80 = 0x43300000;
                          uStack124 = param_3;
                          JAISound::setPitch(*(JAISound **)&this->field_0x214,
                                             JAZelAudio::_6029 +
                                             JAZelAudio::_5372 *
                                             ((float)((double)CONCAT44(0x43300000,param_3) -
                                                     JAZelAudio::_6050) / JAZelAudio::_6030),0,'\0')
                          ;
                          ppJVar6 = (JAISound **)0x0;
                          goto LAB_802a8510;
                        }
                      }
                      else {
                        if (0x809 < (int)soundId) goto LAB_802a75ec;
                        if ((int)soundId < 0x806) goto LAB_802a77b0;
                      }
                    }
                  }
                  else {
                    if (soundId == 0x810) {
                      menuOut(this);
                    }
                    else {
                      if ((int)soundId < 0x810) {
                        if (soundId != 0x80e) {
                          if ((int)soundId < 0x80e) {
                            if ((int)soundId < 0x80d) goto LAB_802a75ec;
                            iVar9 = checkStreamPlaying(this,0xc0000005);
                            if (iVar9 == 1) {
                              ppJVar6 = (JAISound **)0x0;
                              goto LAB_802a8510;
                            }
                            iVar9 = isDemo(this);
                            if (iVar9 == 1) {
                              soundId = JA_SE_DEMO_MSG_END;
                            }
                            iVar9 = checkSePlaying(this,0x871);
                            if (iVar9 == 1) {
                              ppJVar6 = (JAISound **)0x0;
                              goto LAB_802a8510;
                            }
                            if (this->field_0xbe != 0) {
                              ppJVar6 = (JAISound **)0x0;
                              goto LAB_802a8510;
                            }
                          }
                          else {
                            menuIn(this);
                          }
                        }
                      }
                      else {
                        if (soundId == 0x81d) {
LAB_802a77b0:
                          seStop(this,0x804,0);
                          seStop(this,0x81c,0);
                        }
                        else {
                          if (((int)soundId < 0x81d) && (0x81b < (int)soundId)) goto LAB_802a778c;
                        }
                      }
                    }
                  }
                }
              }
              else {
                if (soundId == 0x8a7) goto LAB_802a7254;
                if ((int)soundId < 0x8a7) {
                  if (soundId == 0x876) {
                    subBgmStart(this,(ulong)&DAT_80000031);
                  }
                  else {
                    if ((int)soundId < 0x876) {
                      if (soundId == 0x854) {
                        iVar9 = this->field_0x224;
                        if (iVar9 != 0xc) {
                          if (iVar9 < 0xc) {
                            if (iVar9 != 8) {
LAB_802a7760:
                              soundId = JA_SE_ITM_OMAMORI_SHIP;
                            }
                          }
                          else {
                            if (iVar9 != 0x13) goto LAB_802a7760;
                          }
                        }
                      }
                      else {
                        if (((int)soundId < 0x854) && (soundId == 0x82f)) {
                          seStop(this,0x90b,0x3c);
                        }
                      }
                    }
                    else {
                      if (soundId == 0x87d) {
                        if (param_3 != 0) {
                          param_3 = param_3 - 1;
                        }
                        local_78 = 0x43300000;
                        dVar15 = (double)(JAZelAudio::1_0 +
                                         JAZelAudio::_6046 *
                                         (float)((double)CONCAT44(0x43300000,param_3) -
                                                JAZelAudio::_6050));
                        uStack116 = param_3;
                      }
                    }
                  }
                }
                else {
                  if (soundId == 0x8c1) {
                    menuOut(this);
                  }
                  else {
                    if ((int)soundId < 0x8c1) {
                      if (soundId == 0x8b3) {
                        *(undefined *)&this->field_0x205 = 1;
                        stopBattleBgm(this);
                        this->field_0x8c = JAZelAudio::1_0;
                        if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
                          JAISound::setVolume(*(JAISound **)&this->field_0x68,
                                              this->field_0xac *
                                              this->field_0x9c *
                                              this->field_0x98 *
                                              this->field_0x94 *
                                              this->field_0x90 *
                                              this->field_0x8c *
                                              this->field_0x88 * this->field_0x80 * this->field_0x84
                                              ,0x2d,0);
                        }
                        stopBattleBgm(this);
                        *(undefined *)&this->field_0xc1 = 0;
                        *(undefined4 *)&this->field_0xc4 = 0;
                        *(undefined *)&this->field_0xc0 = 0;
                        subBgmStop(this);
                      }
                      else {
                        if (((int)soundId < 0x8b3) && (soundId == 0x8ab)) {
                          seStop(this,0x8aa,0);
                        }
                      }
                    }
                    else {
                      if (soundId == 0x8da) {
                        subBgmStart(this,(ulong)&DAT_80000030);
                        *(undefined *)&this->field_0x33 = 1;
                        ppJVar6 = (JAISound **)0x0;
                        goto LAB_802a8510;
                      }
                    }
                  }
                }
              }
            }
          }
          else {
            if (soundId == 0x205a) {
              switch(param_3) {
              case 7:
              case 9:
              case 0xb:
              case 0xc:
              case 0xd:
              case 0xe:
              case 0x11:
              case 0x12:
                soundId = JA_SE_LK_SLIP_SUS_STONE;
                break;
              case 10:
                soundId = JA_SE_LK_SLIP_SUS_ICE;
              }
            }
            else {
              if ((int)soundId < 0x205a) {
                if (soundId == 0x1072) {
                  if (99 < param_3) {
                    param_3 = 100;
                  }
                  if (param_3 == 0) {
                    param_3 = 0;
                  }
                  local_78 = 0x43300000;
                  fVar2 = (float)((double)CONCAT44(0x43300000,param_3) - JAZelAudio::_6050);
                  dVar15 = (double)(JAZelAudio::_6033 + (fVar2 * fVar2) / JAZelAudio::_6036);
                  local_80 = 0x43300000;
                  dVar16 = (double)(((float)((double)CONCAT44(0x43300000,param_3) -
                                            JAZelAudio::_6050) / JAZelAudio::_6032) *
                                    JAZelAudio::_6039 + JAZelAudio::_5372);
                  uStack124 = param_3;
                  uStack116 = param_3;
                  if (pMtx != (MTX34 *)0x0) {
                    mtx::PSMTXMultVec(pMtx,&local_8c,&local_8c);
                  }
                  dVar14 = (double)(local_8c.z * local_8c.z +
                                   local_8c.x * local_8c.x + local_8c.y * local_8c.y);
                  if ((double)JAZelAudio::_4004 < dVar14) {
                    dVar12 = 1.0 / SQRT(dVar14);
                    dVar12 = JAZelAudio::_4349 * dVar12 *
                             (JAZelAudio::_4350 - dVar14 * dVar12 * dVar12);
                    dVar12 = JAZelAudio::_4349 * dVar12 *
                             (JAZelAudio::_4350 - dVar14 * dVar12 * dVar12);
                    dVar14 = (double)(float)(dVar14 * JAZelAudio::_4349 * dVar12 *
                                                      (JAZelAudio::_4350 - dVar14 * dVar12 * dVar12)
                                            );
                  }
                  if (dVar14 < (double)JAZelAudio::_6040) {
                    param_2 = (cXyz *)0x0;
                    dVar17 = (double)JAZelAudio::_6028;
                    dVar16 = (double)(float)(dVar16 * (double)(JAZelAudio::_4346 *
                                                              (float)(dVar14 / (double)JAZelAudio::
                                                                                       _6040)));
                    dVar13 = dVar17;
                  }
                }
                else {
                  if ((int)soundId < 0x1072) {
                    if (soundId == 0x1068) goto LAB_802a787c;
                    if ((int)soundId < 0x1068) {
                      if (soundId == 0x105b) {
                        if ((this->field_0x224 == 0x5c) && (*(byte *)&this->field_0x239 < 8)) {
                          soundId = JA_SE_ATM_VS_GANON_RAIN;
                        }
                      }
                      else {
                        if (((int)soundId < 0x105b) && (soundId == 0x8f5)) {
                          *(undefined *)&this->field_0x206 = 0;
                          *(undefined *)&this->field_0xbb = 0;
                          if ((this->mLastMinibossSubBGMType == 0) &&
                             ((this->field_0x74 != -0x7fffffca && (this->field_0x74 != -0x7fffffc9))
                             )) {
                            this->field_0xb0 = -2;
                            subBgmStopInner(this);
                          }
                        }
                      }
                    }
                    else {
                      if (soundId == 0x106a) {
                        if (99 < param_3) {
                          param_3 = 100;
                        }
                        if (param_3 == 0) {
                          param_3 = 0;
                        }
                        local_78 = 0x43300000;
                        fVar2 = (float)((double)CONCAT44(0x43300000,param_3) - JAZelAudio::_6050);
                        local_80 = 0x43300000;
                        dVar16 = (double)(((float)((double)CONCAT44(0x43300000,param_3) -
                                                  JAZelAudio::_6050) / JAZelAudio::_6032) *
                                          JAZelAudio::_6037 + JAZelAudio::_6038);
                        dVar15 = (double)(JAZelAudio::_6033 + (fVar2 * fVar2) / JAZelAudio::_6034);
                        uStack124 = param_3;
                        uStack116 = param_3;
                      }
                    }
                  }
                  else {
                    if (soundId == 0x1863) {
                      *(undefined *)&this->field_0x204 = 1;
                    }
                    else {
                      if ((int)soundId < 0x1863) {
                        if (soundId == 0x1088) {
                          if ((this->field_0x224 == 0x55) &&
                             ((*(char *)&this->field_0x239 == '\t' ||
                              (*(char *)&this->field_0x239 == '\n')))) {
                            ppJVar6 = (JAISound **)0x0;
                            goto LAB_802a8510;
                          }
                        }
                        else {
                          if (((int)soundId < 0x1088) && (soundId == 0x107d)) {
                            if (99 < param_3) {
                              param_3 = 100;
                            }
                            if (param_3 == 0) {
                              param_3 = 0;
                            }
                            local_78 = 0x43300000;
                            dVar16 = (double)((float)((double)CONCAT44(0x43300000,param_3) -
                                                     JAZelAudio::_6050) / JAZelAudio::_6032);
                            if ((double)JAZelAudio::_4004 != dVar16) {
                              dVar16 = (double)(JAZelAudio::_5372 +
                                               (float)((double)JAZelAudio::_6039 * dVar16));
                            }
                            local_80 = 0x43300000;
                            dVar15 = (double)(JAZelAudio::_6028 +
                                             (float)((double)CONCAT44(0x43300000,param_3) -
                                                    JAZelAudio::_6050) / JAZelAudio::_6044);
                            uStack124 = param_3;
                            uStack116 = param_3;
                          }
                        }
                      }
                      else {
                        if (soundId == 0x186e) {
                          subBgmStart(this,(ulong)&DAT_80000032);
                        }
                      }
                    }
                  }
                }
              }
              else {
                if (soundId == 0x303e) {
LAB_802a7b88:
                  if (99 < param_3) {
                    param_3 = 100;
                  }
                  if (param_3 == 0) {
                    param_3 = 0;
                  }
                  local_78 = 0x43300000;
                  fVar2 = (float)((double)CONCAT44(0x43300000,param_3) - JAZelAudio::_6050);
                  local_80 = 0x43300000;
                  dVar16 = (double)(((float)((double)CONCAT44(0x43300000,param_3) -
                                            JAZelAudio::_6050) / JAZelAudio::_6032) *
                                    JAZelAudio::_4346 + JAZelAudio::_4345);
                  dVar15 = (double)(JAZelAudio::_6033 + (fVar2 * fVar2) / JAZelAudio::_6036);
                  uStack124 = param_3;
                  uStack116 = param_3;
                }
                else {
                  if ((int)soundId < 0x303e) {
                    if (soundId == 0x2831) {
                      if (((*(int *)&this->field_0x68 != 0) &&
                          ((undefined *)this->field_0x78 == &DAT_8000000b)) &&
                         (this->field_0x90 = _VOL_BGM_DEFAULT, *(int *)&this->field_0x6c == 0)) {
                        JAISound::setVolume(*(JAISound **)&this->field_0x68,
                                            this->field_0xac *
                                            this->field_0x9c *
                                            this->field_0x98 *
                                            this->field_0x94 *
                                            this->field_0x90 *
                                            this->field_0x8c *
                                            this->field_0x88 * this->field_0x80 * this->field_0x84,2
                                            ,0);
                      }
                    }
                    else {
                      if ((int)soundId < 0x2831) {
                        if ((int)soundId < 0x282d) {
                          if (soundId == 0x2066) {
                            *(undefined *)&this->field_0x207 = 2;
                          }
                        }
                        else {
                          if ((int)soundId < 0x282f) {
                            onEnemyDamage(this);
                          }
                        }
                      }
                      else {
                        if (soundId == 0x285d) goto LAB_802a7254;
                        if ((0x285c < (int)soundId) && (0x303c < (int)soundId)) goto LAB_802a78c0;
                      }
                    }
                  }
                  else {
                    if (soundId == 0x3815) {
LAB_802a7334:
                      if ((this->field_0x46 == 1) && (soundId = JA_SE_LK_WALK_HEAVY, param_3 != 0xd)
                         ) {
                        param_3 = 9;
                      }
                      if (this->field_0x45 == 1) {
                        seStart(this,0x3831,param_2,0,param_4,JAZelAudio::1_0,JAZelAudio::1_0,
                                JAZelAudio::_4357,JAZelAudio::_4357,0);
                      }
                    }
                    else {
                      if ((int)soundId < 0x3815) {
                        if (soundId == 0x380d) {
                          if (param_2 != (cXyz *)0x0) {
                            pfVar7 = (float *)(&this->field_0x1ed4 +
                                              *(int *)&this->field_0x1f34 * 0xc);
                            *pfVar7 = param_2->x;
                            pfVar7[1] = param_2->y;
                            pfVar7[2] = param_2->z;
                            puVar3 = *(undefined **)(**(int **)&this->field_0x4 + 4);
                            if ((float)puVar3 <
                                (float)(&this->vtbl + *(int *)&this->field_0x1f34 * 3)[0x7b6]) {
                              (&this->vtbl + *(int *)&this->field_0x1f34 * 3)[0x7b6] = puVar3;
                            }
                            param_2 = (cXyz *)(&this->field_0x1ed4 +
                                              *(int *)&this->field_0x1f34 * 0xc);
                            *(int *)&this->field_0x1f34 = *(int *)&this->field_0x1f34 + 1;
                          }
                        }
                        else {
                          if (((int)soundId < 0x380d) && (soundId == 0x3808)) {
                            iVar9 = checkStreamPlaying(this,0xc0000005);
                            if (iVar9 == 1) {
                              ppJVar6 = (JAISound **)0x0;
                              goto LAB_802a8510;
                            }
                            if (*(JAISound **)&this->field_0x2064 != (JAISound *)0x0) {
                              JAISound::stop(*(JAISound **)&this->field_0x2064,1);
                            }
                          }
                        }
                      }
                      else {
                        if (soundId == 0x3818) goto LAB_802a7334;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else {
        if (soundId == 0x6909) {
          seStop(this,0x6907,0);
          seStop(this,0x6908,0);
        }
        else {
          if ((int)soundId < 0x6909) {
            if (soundId == 0x5825) {
              this->mSomeSpecialBGMFlag = 1;
            }
            else {
              if ((int)soundId < 0x5825) {
                if (soundId == 0x5128) {
LAB_802a78c0:
                  if (99 < param_3) {
                    param_3 = 100;
                  }
                  if (param_3 == 0) {
                    ppJVar6 = (JAISound **)0x0;
                    goto LAB_802a8510;
                  }
                  local_80 = 0x43300000;
                  dVar16 = (double)((float)((double)CONCAT44(0x43300000,param_3) - JAZelAudio::_6050
                                           ) / JAZelAudio::_6032);
                  uStack124 = param_3;
                }
                else {
                  if ((int)soundId < 0x5128) {
                    if (soundId == 0x50bf) {
LAB_802a7d94:
                      if (99 < param_3) {
                        param_3 = 100;
                      }
                      if (param_3 == 0) {
                        param_3 = 0;
                      }
                      local_78 = 0x43300000;
                      dVar16 = (double)((float)((double)CONCAT44(0x43300000,param_3) -
                                               JAZelAudio::_6050) / JAZelAudio::_6032);
                      local_80 = 0x43300000;
                      dVar15 = (double)(JAZelAudio::1_0 +
                                       (float)((double)CONCAT44(0x43300000,param_3) -
                                              JAZelAudio::_6050) / JAZelAudio::_6043);
                      uStack124 = param_3;
                      uStack116 = param_3;
                    }
                    else {
                      if ((int)soundId < 0x50bf) {
                        if (soundId == 0x3822) goto LAB_802a787c;
                        if ((((0x3821 < (int)soundId) && (0x50bd < (int)soundId)) &&
                            (this->field_0x224 == 0x12)) &&
                           ((this->mIslandRoomNo == 0x2c && (*(char *)&this->field_0x239 == '\n'))))
                        {
                          iVar9 = checkStreamPlaying(this,0xc000001c);
                          if ((iVar9 == 0) && (*(char *)&this->field_0x208 == '\0')) {
                            ppJVar6 = (JAISound **)0x0;
                            goto LAB_802a8510;
                          }
                          *(undefined *)&this->field_0x208 = 1;
                        }
                      }
                      else {
                        if (soundId == 0x50ce) goto LAB_802a78c0;
                        if ((0x50cd < (int)soundId) && (0x5126 < (int)soundId)) {
                          if (99 < param_3) {
                            param_3 = 100;
                          }
                          if (param_3 == 0) {
                            ppJVar6 = (JAISound **)0x0;
                            goto LAB_802a8510;
                          }
                          local_78 = 0x43300000;
                          fVar2 = (float)((double)CONCAT44(0x43300000,param_3) - JAZelAudio::_6050);
                          local_80 = 0x43300000;
                          fVar1 = (float)((double)CONCAT44(0x43300000,param_3) - JAZelAudio::_6050);
                          dVar16 = (double)((fVar2 * fVar2) / JAZelAudio::_6031);
                          dVar15 = (double)(JAZelAudio::_6028 + (fVar1 * fVar1) / JAZelAudio::_6036)
                          ;
                          uStack124 = param_3;
                          uStack116 = param_3;
                        }
                      }
                    }
                  }
                  else {
                    if (soundId != 0x5810) {
                      if ((int)soundId < 0x5810) {
                        if (soundId == 0x5807) goto LAB_802a787c;
                        if ((0x5806 < (int)soundId) && (0x580d < (int)soundId)) {
                          if (pMtx != (MTX34 *)0x0) {
                            mtx::PSMTXMultVec(pMtx,&local_8c,&local_8c);
                          }
                          dVar14 = (double)(local_8c.z * local_8c.z +
                                           local_8c.x * local_8c.x + local_8c.y * local_8c.y);
                          if ((double)JAZelAudio::_4004 < dVar14) {
                            dVar12 = 1.0 / SQRT(dVar14);
                            dVar12 = JAZelAudio::_4349 * dVar12 *
                                     (JAZelAudio::_4350 - dVar14 * dVar12 * dVar12);
                            dVar12 = JAZelAudio::_4349 * dVar12 *
                                     (JAZelAudio::_4350 - dVar14 * dVar12 * dVar12);
                            dVar14 = (double)(float)(dVar14 * JAZelAudio::_4349 * dVar12 *
                                                              (JAZelAudio::_4350 -
                                                              dVar14 * dVar12 * dVar12));
                          }
                          dVar12 = (double)JAIGlobalParameter::getParamDistanceMax
                                                     ((JAIGlobalParameter *)pMtx);
                          if (dVar12 < dVar14) {
                            ppJVar6 = (JAISound **)0x0;
                            goto LAB_802a8510;
                          }
                        }
                      }
                      else {
                        if ((int)soundId < 0x5814) {
                          if ((int)soundId < 0x5812) goto LAB_802a787c;
                        }
                        else {
                          if ((int)soundId < 0x5816) goto LAB_802a787c;
                        }
                      }
                    }
                  }
                }
              }
              else {
                if (soundId == 0x591b) {
LAB_802a7254:
                  param_2 = (cXyz *)0x0;
                }
                else {
                  if ((int)soundId < 0x591b) {
                    if (soundId == 0x5875) {
                      *(undefined *)&this->field_0xcc = 1;
                    }
                    else {
                      if ((int)soundId < 0x5875) {
                        if (soundId == 0x584c) {
                          seStart(this,0x7818,(cXyz *)0x0,0,0,JAZelAudio::1_0,JAZelAudio::1_0,
                                  JAZelAudio::_4357,JAZelAudio::_4357,0);
                        }
                        else {
                          if (((int)soundId < 0x584c) && (0x584a < (int)soundId)) goto LAB_802a7018;
                        }
                      }
                      else {
                        if (soundId == 0x5895) goto LAB_802a7d94;
                        if (((int)soundId < 0x5895) && (soundId == 0x588c)) goto LAB_802a787c;
                      }
                    }
                  }
                  else {
                    if (soundId == 0x61fe) {
                      if ((this->field_0x224 == 0x35) &&
                         (iVar9 = checkEventBit(this,0x2d04), iVar9 == 0)) {
                        ppJVar6 = (JAISound **)0x0;
                        goto LAB_802a8510;
                      }
                    }
                    else {
                      if ((int)soundId < 0x61fe) {
                        if (soundId == 0x61b1) {
                          uStack116 = param_3;
                          if (99 < param_3) {
                            uStack116 = 100;
                          }
                          if (uStack116 == 0) {
                            ppJVar6 = (JAISound **)0x0;
                            goto LAB_802a8510;
                          }
                          local_78 = 0x43300000;
                          param_3 = uStack116;
                          if (0x1d < uStack116) {
                            param_3 = 0x1e;
                          }
                          local_80 = 0x43300000;
                          dVar16 = (double)((float)((double)CONCAT44(0x43300000,param_3) -
                                                   JAZelAudio::_6050) / JAZelAudio::_6045);
                          dVar15 = (double)(JAZelAudio::1_0 +
                                           (float)((double)CONCAT44(0x43300000,uStack116) -
                                                  JAZelAudio::_6050) / JAZelAudio::_6032);
                          uStack124 = param_3;
                        }
                        else {
                          if (((int)soundId < 0x61b1) && (soundId == 0x5973)) goto LAB_802a787c;
                        }
                      }
                      else {
                        if (soundId == 0x6906) {
                          seStop(this,0x6906,0);
                        }
                        else {
                          if (0x6905 < (int)soundId) {
                            seStop(this,0x6907,0);
                            seStop(this,0x6908,0);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else {
            if (soundId == 0x69f2) goto LAB_802a787c;
            if ((int)soundId < 0x69f2) {
              if (soundId == 0x6981) goto LAB_802a7254;
              if ((int)soundId < 0x6981) {
                if (soundId == 0x6942) {
                  if (pMtx != (MTX34 *)0x0) {
                    mtx::PSMTXMultVec(pMtx,&local_8c,&local_8c);
                  }
                  dVar14 = (double)(local_8c.z * local_8c.z +
                                   local_8c.x * local_8c.x + local_8c.y * local_8c.y);
                  if ((double)JAZelAudio::_4004 < dVar14) {
                    dVar12 = 1.0 / SQRT(dVar14);
                    dVar12 = JAZelAudio::_4349 * dVar12 *
                             (JAZelAudio::_4350 - dVar14 * dVar12 * dVar12);
                    dVar12 = JAZelAudio::_4349 * dVar12 *
                             (JAZelAudio::_4350 - dVar14 * dVar12 * dVar12);
                    dVar14 = (double)(float)(dVar14 * JAZelAudio::_4349 * dVar12 *
                                                      (JAZelAudio::_4350 - dVar14 * dVar12 * dVar12)
                                            );
                  }
                  dVar12 = (double)JAIGlobalParameter::getParamDistanceMax
                                             ((JAIGlobalParameter *)pMtx);
                  if ((double)(float)(dVar12 * (double)JAZelAudio::_6028) < dVar14) {
                    ppJVar6 = (JAISound **)0x0;
                    goto LAB_802a8510;
                  }
                }
                else {
                  if ((int)soundId < 0x6942) {
                    if (soundId == 0x6934) {
                      this->field_0xca = 1;
                      stopBattleBgm(this);
                      this->field_0x8c = JAZelAudio::1_0;
                      if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
                        JAISound::setVolume(*(JAISound **)&this->field_0x68,
                                            this->field_0xac *
                                            this->field_0x9c *
                                            this->field_0x98 *
                                            this->field_0x94 *
                                            this->field_0x90 *
                                            this->field_0x8c *
                                            this->field_0x88 * this->field_0x80 * this->field_0x84,
                                            0x2d,0);
                      }
                      stopBattleBgm(this);
                      *(undefined *)&this->field_0xc1 = 0;
                      *(undefined4 *)&this->field_0xc4 = 0;
                      *(undefined *)&this->field_0xc0 = 0;
                      param_2 = (cXyz *)0x0;
                    }
                    else {
                      if (((int)soundId < 0x6934) && ((int)soundId < 0x690b)) {
                        seStop(this,0x6907,0);
                        seStop(this,0x6908,0);
                      }
                    }
                  }
                  else {
                    if (soundId == 0x6956) {
                      seStop(this,0x6957,0);
                    }
                    else {
                      if ((int)soundId < 0x6956) {
                        if (0x6954 < (int)soundId) goto LAB_802a787c;
                      }
                      else {
                        if ((int)soundId < 0x6958) {
                          seStop(this,0x6956,0);
                        }
                      }
                    }
                  }
                }
              }
              else {
                if ((int)soundId < 0x6998) {
                  if ((soundId == 0x6991) ||
                     ((((int)soundId < 0x6991 && ((int)soundId < 0x698a)) && (0x6987 < (int)soundId)
                      ))) goto LAB_802a787c;
                }
                else {
                  if ((int)soundId < 0x69e7) {
                    if ((int)soundId < 0x699a) {
LAB_802a787c:
                      if (99 < param_3) {
                        param_3 = 100;
                      }
                      if (param_3 == 0) {
                        ppJVar6 = (JAISound **)0x0;
                        goto LAB_802a8510;
                      }
                      param_3 = param_3 * param_3;
                      local_80 = 0x43300000;
                      dVar16 = (double)((float)((double)CONCAT44(0x43300000,param_3) -
                                               JAZelAudio::_6050) / JAZelAudio::_6031);
                      uStack124 = param_3;
                    }
                  }
                  else {
                    if ((int)soundId < 0x69e9) goto LAB_802a787c;
                  }
                }
              }
            }
            else {
              if ((int)soundId < 0x7036) {
                if ((int)soundId < 0x701d) {
                  if ((int)soundId < 0x6a2a) {
                    if (((int)soundId < 0x6a0e) && (0x6a05 < (int)soundId)) goto LAB_802a787c;
                  }
                  else {
                    if ((int)soundId < 0x6a2c) {
                      ppJVar6 = (JAISound **)0x0;
                      goto LAB_802a8510;
                    }
                  }
                }
                else {
                  if (soundId == 0x702c) {
                    if (pMtx != (MTX34 *)0x0) {
                      mtx::PSMTXMultVec(pMtx,&local_8c,&local_8c);
                    }
                    dVar14 = (double)ABS(local_8c.y);
                    dVar16 = (double)JAIGlobalParameter::getParamDistanceMax
                                               ((JAIGlobalParameter *)pMtx);
                    dVar16 = (double)(JAZelAudio::1_0 -
                                     (float)(dVar14 / (double)(float)((double)JAZelAudio::_5371 *
                                                                     dVar16)));
                    if (dVar16 < (double)JAZelAudio::_4004) {
                      dVar16 = (double)JAZelAudio::_4004;
                    }
                    if ((double)JAZelAudio::1_0 < dVar16) {
                      dVar16 = (double)JAZelAudio::1_0;
                    }
                    param_2 = (cXyz *)0x0;
                  }
                  else {
                    if (((int)soundId < 0x702c) && ((int)soundId < 0x701f)) {
                      if (99 < param_3) {
                        param_3 = 100;
                      }
                      if (param_3 == 0) {
                        ppJVar6 = (JAISound **)0x0;
                        goto LAB_802a8510;
                      }
                      local_80 = 0x43300000;
                      fVar2 = (float)((double)CONCAT44(0x43300000,param_3) - JAZelAudio::_6050);
                      local_78 = 0x43300000;
                      fVar1 = (float)((double)CONCAT44(0x43300000,param_3) - JAZelAudio::_6050);
                      dVar16 = (double)((fVar2 * fVar2) / JAZelAudio::_6031);
                      dVar15 = (double)(JAZelAudio::_6033 + (fVar1 * fVar1) / JAZelAudio::_6034);
                      uStack124 = param_3;
                      uStack116 = param_3;
                    }
                  }
                }
              }
              else {
                if (soundId == 0x705a) {
                  if (99 < param_3) {
                    param_3 = 100;
                  }
                  if (param_3 == 0) {
                    ppJVar6 = (JAISound **)0x0;
                    goto LAB_802a8510;
                  }
                  local_78 = 0x43300000;
                  fVar2 = (float)((double)CONCAT44(0x43300000,param_3) - JAZelAudio::_6050);
                  local_80 = 0x43300000;
                  fVar1 = (float)((double)CONCAT44(0x43300000,param_3) - JAZelAudio::_6050);
                  dVar16 = (double)((fVar2 * fVar2) / JAZelAudio::_6031);
                  dVar15 = (double)(JAZelAudio::_6033 + (fVar1 * fVar1) / JAZelAudio::_6034);
                  uStack124 = param_3;
                  uStack116 = param_3;
                }
                else {
                  if ((int)soundId < 0x705a) {
                    if (soundId == 0x7051) goto LAB_802a7b88;
                    if ((int)soundId < 0x7051) {
                      if (soundId == 0x703a) {
                        this->field_0xbe = 1;
                      }
                      else {
                        if ((int)soundId < 0x703a) {
                          if (99 < param_3) {
                            param_3 = 100;
                          }
                          if (param_3 == 0) {
                            ppJVar6 = (JAISound **)0x0;
                            goto LAB_802a8510;
                          }
                          local_78 = 0x43300000;
                          fVar2 = (float)((double)CONCAT44(0x43300000,param_3) - JAZelAudio::_6050);
                          local_80 = 0x43300000;
                          fVar1 = (float)((double)CONCAT44(0x43300000,param_3) - JAZelAudio::_6050);
                          dVar16 = (double)((fVar2 * fVar2) / JAZelAudio::_6031);
                          dVar15 = (double)(JAZelAudio::_6041 + (fVar1 * fVar1) / JAZelAudio::_6042)
                          ;
                          uStack124 = param_3;
                          uStack116 = param_3;
                        }
                      }
                    }
                  }
                  else {
                    if (soundId == 0x705c) {
                      if (99 < param_3) {
                        param_3 = 100;
                      }
                      if (param_3 == 0) {
                        ppJVar6 = (JAISound **)0x0;
                        goto LAB_802a8510;
                      }
                      local_78 = 0x43300000;
                      fVar2 = (float)((double)CONCAT44(0x43300000,param_3) - JAZelAudio::_6050);
                      local_80 = 0x43300000;
                      dVar16 = (double)((fVar2 * fVar2) / JAZelAudio::_6031);
                      dVar15 = (double)(JAZelAudio::_4732 +
                                       (float)((double)CONCAT44(0x43300000,param_3) -
                                              JAZelAudio::_6050) / JAZelAudio::_6035);
                      uStack124 = param_3;
                      uStack116 = param_3;
                      if (dVar15 <= (double)JAZelAudio::_6028) {
                        dVar15 = (double)JAZelAudio::_6028;
                      }
                    }
                    else {
                      if ((int)soundId < 0x705c) {
                        if (99 < param_3) {
                          param_3 = 100;
                        }
                        if (param_3 == 0) {
                          ppJVar6 = (JAISound **)0x0;
                          goto LAB_802a8510;
                        }
                        local_78 = 0x43300000;
                        fVar2 = (float)((double)CONCAT44(0x43300000,param_3) - JAZelAudio::_6050);
                        local_80 = 0x43300000;
                        fVar1 = (float)((double)CONCAT44(0x43300000,param_3) - JAZelAudio::_6050);
                        dVar16 = (double)((fVar2 * fVar2) / JAZelAudio::_6031);
                        dVar15 = (double)(JAZelAudio::_6033 + (fVar1 * fVar1) / JAZelAudio::_6034);
                        uStack124 = param_3;
                        uStack116 = param_3;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      if (param_9 == 1) goto LAB_802a815c;
      if ((int)soundId < 0x5055) {
        if ((int)soundId < 0x3035) {
          if (soundId != JA_SE_OBJ_OTOSHIANA_SUS) {
            if ((int)soundId < 0x3019) {
              if (soundId != JA_SE_ATM_RAKUBAN) goto LAB_802a815c;
            }
            else {
              if ((int)soundId < 0x3033) goto LAB_802a815c;
            }
          }
        }
        else {
          if ((int)soundId < 0x501e) {
            if (soundId != JA_SE_ATM_RIVER_S_ISLE) {
LAB_802a815c:
              if ((soundId & 0x800) == 0) {
                iVar9 = 0;
                iVar10 = 0x18;
                do {
                  iVar8 = (int)&this->vtbl + iVar9;
                  if (((*(JAISoundInfoID *)(iVar8 + 0x134) == soundId) &&
                      (*(int *)(iVar8 + 0xd4) != 0)) && (*(cXyz **)(iVar8 + 0x194) == param_2)) {
                    ppJVar6 = (JAISound **)(iVar8 + 0xd4);
                    JAIBasic::startSoundVec
                              ((JAIBasic *)this,soundId,ppJVar6,(Vec *)param_2,0,param_3,'\x04');
                    iVar9 = (int)&this->vtbl + iVar9;
                    if (*(JAISound **)(iVar9 + 0xd4) != (JAISound *)0x0) {
                      JAISound::setPortData(*(JAISound **)(iVar9 + 0xd4),'\t',(short)param_4);
                      if ((double)JAZelAudio::1_0 != dVar15) {
                        JAISound::setPitch(*(JAISound **)(iVar9 + 0xd4),(float)dVar15,0,'\0');
                      }
                      if ((double)JAZelAudio::1_0 != dVar16) {
                        JAISound::setVolume(*(JAISound **)(iVar9 + 0xd4),(float)dVar16,0,0);
                      }
                      if ((double)JAZelAudio::_4357 != dVar17) {
                        JAISound::setPan(*(JAISound **)(iVar9 + 0xd4),(float)dVar17,0,'\0');
                      }
                      if ((double)JAZelAudio::_4357 != dVar13) {
                        JAISound::setDolby(*(JAISound **)(iVar9 + 0xd4),(float)dVar13,0,'\0');
                      }
                    }
                    goto LAB_802a8510;
                  }
                  iVar9 = iVar9 + 4;
                  iVar10 = iVar10 + -1;
                } while (iVar10 != 0);
              }
              iVar10 = *(int *)&this->field_0x1f4;
              iVar9 = iVar10;
              if (*(int *)(&this->field_0xd4 + iVar10 * 4) != 0) {
                do {
                  if (*(int *)(&this->field_0xd4 + iVar9 * 4) == 0) {
                    *(int *)&this->field_0x1f4 = iVar9;
                    goto LAB_802a82d8;
                  }
                  iVar9 = (iVar9 + 1) % 0x18;
                } while (iVar9 != iVar10);
                m_Do_printf::OSReport("[JAIZelBasic::seStart] overflow JAISound pointer\n");
                ppJVar6 = (JAISound **)0x0;
                goto LAB_802a8510;
              }
LAB_802a82d8:
              *(undefined4 *)(&this->field_0xd4 + *(int *)&this->field_0x1f4 * 4) = 0;
              JAIBasic::startSoundVec
                        ((JAIBasic *)this,soundId,
                         (JAISound **)(&this->field_0xd4 + *(int *)&this->field_0x1f4 * 4),
                         (Vec *)param_2,0,param_3,'\x04');
              if (soundId == JA_SE_PLAYSPOT_END_S) {
                if (param_2 != (cXyz *)0x0) {
                  JAIBasic::deleteObject((JAIBasic *)this,param_2);
                }
                param_2 = (cXyz *)0x0;
              }
              this_00 = *(JAISound **)(&this->field_0xd4 + *(int *)&this->field_0x1f4 * 4);
              if (this_00 != (JAISound *)0x0) {
                JAISound::setPortData(this_00,'\t',(short)param_4);
                if ((double)JAZelAudio::1_0 != dVar15) {
                  JAISound::setPitch(*(JAISound **)
                                      (&this->field_0xd4 + *(int *)&this->field_0x1f4 * 4),
                                     (float)dVar15,0,'\0');
                }
                if ((double)JAZelAudio::1_0 != dVar16) {
                  JAISound::setVolume(*(JAISound **)
                                       (&this->field_0xd4 + *(int *)&this->field_0x1f4 * 4),
                                      (float)dVar16,0,0);
                }
                if ((double)JAZelAudio::_4357 != dVar17) {
                  JAISound::setPan(*(JAISound **)
                                    (&this->field_0xd4 + *(int *)&this->field_0x1f4 * 4),
                                   (float)dVar17,0,'\0');
                }
                if ((double)JAZelAudio::_4357 != dVar13) {
                  JAISound::setDolby(*(JAISound **)
                                      (&this->field_0xd4 + *(int *)&this->field_0x1f4 * 4),
                                     (float)dVar13,0,'\0');
                }
                uVar4 = (ushort)param_3;
                if ((int)soundId < 0x893) {
                  if (soundId == JA_SE_WTAKT_METRONOME) {
LAB_802a8428:
                    JAISound::setPortData
                              (*(JAISound **)(&this->field_0xd4 + *(int *)&this->field_0x1f4 * 4),
                               '\b',uVar4);
                  }
                }
                else {
                  if ((int)soundId < 0x896) goto LAB_802a8428;
                }
                uVar5 = (ushort)(param_3 >> 0x10);
                if (soundId == JA_SE_WTAKT_ARM_SWING) {
                  JAISound::setPortData
                            (*(JAISound **)(&this->field_0xd4 + *(int *)&this->field_0x1f4 * 4),'\a'
                             ,uVar5);
                  JAISound::setPortData
                            (*(JAISound **)(&this->field_0xd4 + *(int *)&this->field_0x1f4 * 4),'\b'
                             ,uVar4);
                }
                if (soundId == JA_SE_LK_WTAKT_SWING) {
                  JAISound::setPortData
                            (*(JAISound **)(&this->field_0xd4 + *(int *)&this->field_0x1f4 * 4),'\a'
                             ,uVar5);
                  JAISound::setPortData
                            (*(JAISound **)(&this->field_0xd4 + *(int *)&this->field_0x1f4 * 4),'\b'
                             ,uVar4);
                }
              }
              iVar9 = *(int *)&this->field_0x1f4 * 4;
              ppJVar6 = (JAISound **)(&this->field_0xd4 + iVar9);
              *(ulong *)(&this->field_0x134 + iVar9) = soundId;
              *(cXyz **)(&this->field_0x194 + *(int *)&this->field_0x1f4 * 4) = param_2;
              *(int *)&this->field_0x1f4 = *(int *)&this->field_0x1f4 + 1;
              *(int *)&this->field_0x1f4 = *(int *)&this->field_0x1f4 % 0x18;
              goto LAB_802a8510;
            }
          }
          else {
            if (((int)soundId < 0x5053) && (0x501f < (int)soundId)) goto LAB_802a815c;
          }
        }
      }
      else {
        if (soundId != JA_SE_OBJ_SEARCH_LIGHT) {
          if ((int)soundId < 0x6131) {
            if ((soundId != JA_SE_OBJ_STEAM) &&
               ((0x612d < (int)soundId || (soundId != JA_SE_OBJ_TORCH_BURNING)))) goto LAB_802a815c;
          }
          else {
            if ((soundId != JA_SE_CM_BST_HORI) &&
               ((0x7034 < (int)soundId || (soundId != JA_SE_OBJ_BAR_FRAME_BURN))))
            goto LAB_802a815c;
          }
        }
      }
      setLevObjSE(this,soundId,(Vec *)param_2,param_4);
      ppJVar6 = (JAISound **)0x0;
      goto LAB_802a8510;
    }
  }
  else {
    if ((soundId != 0x5936) && ((0x5935 < (int)soundId || (0x5934 < (int)soundId))))
    goto LAB_802a6854;
  }
  kuroboMotionPlay(this,soundId,(Vec *)param_2,param_3,param_4);
  ppJVar6 = (JAISound **)0x0;
LAB_802a8510:
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  __psq_l0(auStack24,uVar11);
  __psq_l1(auStack24,uVar11);
  __psq_l0(auStack40,uVar11);
  __psq_l1(auStack40,uVar11);
  __psq_l0(auStack56,uVar11);
  __psq_l1(auStack56,uVar11);
  __psq_l0(auStack72,uVar11);
  __psq_l1(auStack72,uVar11);
  return ppJVar6;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __thiscall JAIZelBasic::seStop(unsigned long,
                                  long) */

void __thiscall JAIZelBasic::seStop(JAIZelBasic *this,ulong param_1,long param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != 0xffffffff) {
    if (param_1 == 0x280d) {
      param_2 = 8;
    }
    iVar1 = 0;
    iVar3 = 0;
    do {
      iVar2 = (int)&this->vtbl + iVar3;
      if ((*(ulong *)(iVar2 + 0x134) == param_1) &&
         (*(JAISound **)(iVar2 + 0xd4) != (JAISound *)0x0)) {
        JAISound::stop(*(JAISound **)(iVar2 + 0xd4),param_2);
        *(undefined4 *)(iVar2 + 0xd4) = 0;
        *(undefined4 *)(iVar2 + 0x134) = 0;
        *(undefined4 *)(iVar2 + 0x194) = 0;
      }
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar1 < 0x18);
  }
  return;
}


/* __thiscall JAIZelBasic::checkSePlaying(unsigned long) */

undefined4 __thiscall JAIZelBasic::checkSePlaying(JAIZelBasic *this,ulong param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = 0x18;
  while ((iVar2 = (int)&this->vtbl + iVar1, *(ulong *)(iVar2 + 0x134) != param_1 ||
         (*(int *)(iVar2 + 0xd4) == 0))) {
    iVar1 = iVar1 + 4;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return 0;
    }
  }
  return 1;
}


/* __thiscall JAIZelBasic::seStopActor(Vec *,
                                       unsigned long) */

void __thiscall JAIZelBasic::seStopActor(JAIZelBasic *this,Vec *param_1,ulong param_2)

{
  if (param_2 == 0xffffffff) {
    JAIBasic::stopAllSound((JAIBasic *)this,param_1);
  }
  else {
    if (param_1 == (Vec *)0x0) {
      JAIBasic::stopAllSound((JAIBasic *)this,param_2);
    }
    else {
      JAIBasic::stopAllSound((JAIBasic *)this,param_2,param_1);
    }
  }
  return;
}


/* __thiscall JAIZelBasic::seDeleteObject(Vec *) */

void __thiscall JAIZelBasic::seDeleteObject(JAIZelBasic *this,Vec *param_1)

{
  JAIBasic::deleteObject((JAIBasic *)this,param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802a8728) */
/* __thiscall JAIZelBasic::getLinkVoiceVowel(unsigned long) */

undefined __thiscall JAIZelBasic::getLinkVoiceVowel(JAIZelBasic *this,ulong param_1)

{
  int iVar1;
  undefined uVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar3 = 0;
  dVar6 = (double)JAZelAudio::_6153;
  do {
    dVar5 = (double)JKernel::JMath::TRandom_enough_::get((TRandom_enough_ *)&this->field_0x2068);
    iVar1 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)(float)(dVar6 * dVar5));
    if ((&linkVoiceTable + param_1 * 8)[iVar1 * 2] != -1) break;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 400);
  if (iVar3 == 400) {
    uVar2 = 0xff;
  }
  else {
    uVar2 = (&linkVoiceTable + param_1 * 8)[iVar1 * 2 + 1];
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x802a890c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::linkVoiceStart(unsigned long,
                                          Vec *,
                                          unsigned char,
                                          signed char) */

void __thiscall
JAIZelBasic::linkVoiceStart(JAIZelBasic *this,ulong param_1,Vec *param_2,uchar param_3,char param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (this->field_0x22d == 0) goto LAB_802a890c;
  if (this->field_0x7c == 0xc0000005) {
    if (*(char *)&this->field_0xb8 == '\0') {
      if ((param_1 == 0x10) && (iVar2 = getRandomU32(this,3), iVar2 != 0)) goto LAB_802a890c;
    }
    else {
      if (param_1 == 0x10) goto LAB_802a890c;
    }
  }
  if (((undefined *)this->field_0x78 == &DAT_8000000b) && (param_1 == 3)) {
    this->field_0x90 = _VOL_BGM_TALKING;
    if ((*(JAISound **)&this->field_0x68 != (JAISound *)0x0) && (*(int *)&this->field_0x6c == 0)) {
      JAISound::setVolume(*(JAISound **)&this->field_0x68,
                          this->field_0xac *
                          this->field_0x9c *
                          this->field_0x98 *
                          this->field_0x94 *
                          this->field_0x90 *
                          this->field_0x8c * this->field_0x88 * this->field_0x80 * this->field_0x84,
                          2,0);
    }
  }
  if (param_1 == 0xc) {
    param_2 = (Vec *)0x0;
  }
  pbVar4 = &linkVoiceTable + param_1 * 8;
  if (param_3 == 0xff) {
    uVar3 = (uint)*pbVar4;
  }
  else {
    iVar2 = 0;
    dVar7 = (double)JAZelAudio::_6153;
    do {
      dVar6 = (double)JKernel::JMath::TRandom_enough_::get((TRandom_enough_ *)&this->field_0x2068);
      iVar1 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)(float)(dVar7 * dVar6));
      if ((param_3 == (pbVar4 + iVar1 * 2)[1]) && (uVar3 = (uint)pbVar4[iVar1 * 2], uVar3 != 0xff))
      break;
      iVar2 = iVar2 + 1;
      uVar3 = 0;
    } while (iVar2 < 400);
    if (iVar2 == 400) {
      uVar3 = (uint)*pbVar4;
    }
  }
  if (uVar3 != 0xff) {
    seStart(this,uVar3 + 0x1800,(cXyz *)param_2,0,param_4,JAZelAudio::1_0,JAZelAudio::1_0,
            JAZelAudio::_4357,JAZelAudio::_4357,0);
  }
LAB_802a890c:
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* __thiscall JAIZelBasic::monsSeInit(void) */

void __thiscall JAIZelBasic::monsSeInit(JAIZelBasic *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = 0x1e;
  do {
    iVar2 = (int)&this->vtbl + iVar1;
    *(undefined4 *)(iVar2 + 0x1f4c) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0x1f50) = 0;
    iVar1 = iVar1 + 8;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall JAIZelBasic::monsSeStart(unsigned long,
                                       Vec *,
                                       unsigned long,
                                       unsigned long,
                                       signed char) */

void __thiscall
JAIZelBasic::monsSeStart
          (JAIZelBasic *this,ulong param_1,cXyz *param_2,ulong param_3,ulong param_4,char param_5)

{
  int iVar1;
  JAISound *pJVar2;
  int iVar3;
  int iVar4;
  
  if (this->field_0x201 != 1) {
    if ((param_1 < 0x486d) || (0x486f < param_1)) {
      if ((param_1 < 0x48f7) || (0x48fc < param_1)) {
        if ((this->field_0x224 == 0x2d) &&
           ((param_1 == 0x48fd ||
            ((((int)param_1 < 0x48fd && ((int)param_1 < 0x48f7)) && (0x48f0 < (int)param_1)))))) {
          kuroboVoicePlay(this,param_1,(Vec *)param_2,param_5);
        }
        else {
          iVar3 = 0;
          iVar1 = 0;
          iVar4 = 0x1e;
          do {
            if (*(ulong *)(&this->field_0x1f4c + iVar1) == param_3) {
              pJVar2 = *(JAISound **)(&this->field_0x1f50 + iVar1);
              if (pJVar2 != (JAISound *)0x0) {
                JAISound::stop(pJVar2,0);
              }
              break;
            }
            iVar3 = iVar3 + 1;
            iVar1 = iVar1 + 8;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
          if (iVar3 == 0x1e) {
            iVar3 = 0;
            iVar1 = 0;
            iVar4 = 0x1e;
            do {
              if (*(int *)(&this->field_0x1f4c + iVar1) == -1) {
                *(ulong *)(&this->field_0x1f4c + iVar1) = param_3;
                break;
              }
              iVar3 = iVar3 + 1;
              iVar1 = iVar1 + 8;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
            if (iVar3 == 0x1e) {
              iVar3 = 0x1d;
            }
          }
          if (9 < param_4) {
            param_4 = param_3 % 10;
          }
          JAIBasic::startSoundVec
                    ((JAIBasic *)this,param_1,(JAISound **)(&this->field_0x1f50 + iVar3 * 8),
                     (Vec *)param_2,0,param_4,'\x04');
          pJVar2 = *(JAISound **)(&this->field_0x1f50 + iVar3 * 8);
          if (pJVar2 != (JAISound *)0x0) {
            JAISound::setPortData(pJVar2,'\t',(short)param_5);
          }
        }
      }
      else {
        kuroboVoicePlay(this,param_1,(Vec *)param_2,param_5);
      }
    }
    else {
      kuroboVoicePlay(this,param_1,(Vec *)param_2,param_5);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JAIZelBasic::kuroboMotionPlay(unsigned long,
                                            Vec *,
                                            unsigned long,
                                            signed char) */

void __thiscall
JAIZelBasic::kuroboMotionPlay
          (JAIZelBasic *this,ulong param_1,Vec *param_2,ulong param_3,char param_4)

{
  int iVar1;
  JAISound *this_00;
  int iVar2;
  int iVar3;
  
  if (*(byte *)&this->field_0x203c < 4) {
    *(byte *)&this->field_0x203c = *(byte *)&this->field_0x203c + 1;
    iVar2 = 0;
    iVar1 = 0;
    iVar3 = 4;
    do {
      if (*(int *)(&this->field_0x2040 + iVar1) == 0) break;
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (iVar2 != 4) {
      JAIBasic::startSoundVec
                ((JAIBasic *)this,param_1,(JAISound **)(&this->field_0x2040 + iVar2 * 4),param_2,0,
                 param_3,'\x04');
      this_00 = *(JAISound **)(&this->field_0x2040 + iVar2 * 4);
      if (this_00 != (JAISound *)0x0) {
        JAISound::setPortData(this_00,'\t',(short)param_4);
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JAIZelBasic::kuroboVoicePlay(unsigned long,
                                           Vec *,
                                           signed char) */

void __thiscall
JAIZelBasic::kuroboVoicePlay(JAIZelBasic *this,ulong param_1,Vec *param_2,char param_3)

{
  int iVar1;
  JAISound *this_00;
  int iVar2;
  int iVar3;
  
  if (*(byte *)&this->field_0x203d < 4) {
    *(byte *)&this->field_0x203d = *(byte *)&this->field_0x203d + 1;
    JAIBasic::stopAllSe((JAIBasic *)this,'\x04',param_2);
    iVar2 = 0;
    iVar1 = 0;
    iVar3 = 4;
    do {
      if (*(int *)(&this->field_0x2050 + iVar1) == 0) break;
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (iVar2 != 4) {
      JAIBasic::startSoundVec
                ((JAIBasic *)this,param_1,(JAISound **)(&this->field_0x2050 + iVar2 * 4),param_2,0,0
                 ,'\x04');
      this_00 = *(JAISound **)(&this->field_0x2050 + iVar2 * 4);
      if (this_00 != (JAISound *)0x0) {
        JAISound::setPortData(this_00,'\t',(short)param_3);
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802a8f30) */
/* WARNING: Removing unreachable block (ram,0x802a8f38) */
/* __thiscall JAIZelBasic::setLevObjSE(unsigned long,
                                       Vec *,
                                       signed char) */

void __thiscall JAIZelBasic::setLevObjSE(JAIZelBasic *this,ulong param_1,Vec *param_2,char param_3)

{
  float fVar1;
  MTX34 *pMtx;
  int iVar2;
  undefined **ppuVar3;
  float *pfVar4;
  int iVar5;
  undefined **ppuVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  undefined8 in_f30;
  undefined8 in_f31;
  cXyz local_48 [2];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  pMtx = (MTX34 *)(*(float ***)&this->field_0x4)[2];
  local_48[0].x = JAZelAudio::_6301;
  local_48[0].y = DAT_8036a130;
  local_48[0].z = DAT_8036a134;
  if (param_2 == (Vec *)0x0) {
    pfVar4 = **(float ***)&this->field_0x4;
    if (pfVar4 != (float *)0x0) {
      local_48[0].x = *pfVar4;
      local_48[0].y = pfVar4[1];
      local_48[0].z = pfVar4[2];
    }
  }
  else {
    local_48[0].x = *(float *)param_2;
    local_48[0].y = *(float *)(param_2 + 4);
    local_48[0].z = *(float *)(param_2 + 8);
  }
  if ((param_1 == 0x7009) &&
     (fVar1 = *(float *)(**(int **)&this->field_0x4 + 4), fVar1 < local_48[0].y)) {
    local_48[0].y = fVar1;
  }
  if (pMtx != (MTX34 *)0x0) {
    mtx::PSMTXMultVec(pMtx,local_48,local_48);
  }
  fVar1 = JAZelAudio::_6028;
  if (param_1 != 0x6103) {
    fVar1 = JAZelAudio::1_0;
    if ((int)param_1 < 0x6103) {
      if ((int)param_1 < 0x3035) {
        if (param_1 != 0x3019) {
          if ((int)param_1 < 0x3019) {
            if (param_1 == 0x105f) goto LAB_802a8e4c;
          }
          else {
            if (0x3032 < (int)param_1) goto LAB_802a8e44;
          }
        }
      }
      else {
        if (param_1 == 0x501f) {
LAB_802a8e4c:
          fVar1 = JAZelAudio::_6153;
        }
        else {
          if ((int)param_1 < 0x501f) {
            if (0x501d < (int)param_1) goto LAB_802a8e44;
          }
          else {
            if (((int)param_1 < 0x5055) && (0x5052 < (int)param_1)) goto LAB_802a8e4c;
          }
        }
      }
    }
    else {
      if (param_1 == 0x7009) {
LAB_802a8e44:
        fVar1 = JAZelAudio::_6358;
      }
      else {
        if ((int)param_1 < 0x7009) {
          if (((param_1 != 0x6131) && ((int)param_1 < 0x6131)) &&
             (fVar1 = JAZelAudio::_5372, param_1 != 0x612e)) {
            fVar1 = JAZelAudio::1_0;
          }
        }
        else {
          fVar1 = JAZelAudio::_6028;
          if (((param_1 != 0x7035) && (fVar1 = JAZelAudio::1_0, (int)param_1 < 0x7035)) &&
             (fVar1 = JAZelAudio::_6359, param_1 != 0x701f)) {
            fVar1 = JAZelAudio::1_0;
          }
        }
      }
    }
  }
  dVar10 = (double)calcPosVolume(this,(Vec *)local_48,fVar1);
  dVar11 = (double)calcPosPanLR(this,(Vec *)local_48);
  dVar12 = (double)calcPosPanSR(this,(Vec *)local_48,JAZelAudio::1_0);
  if ((double)JAZelAudio::_4004 != dVar10) {
    iVar7 = 0;
    iVar5 = *(int *)&this->field_0x157c;
    iVar8 = iVar5;
    for (iVar2 = 0; (iVar8 != 0 && (*(ulong *)(&this->field_0x244 + iVar2) != param_1));
        iVar2 = iVar2 + 0x148) {
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + -1;
    }
    if (iVar7 == iVar5) {
      if (iVar5 == 0xf) goto LAB_802a8f30;
      *(ulong *)(&this->field_0x244 + iVar7 * 0x148) = param_1;
      *(int *)&this->field_0x157c = *(int *)&this->field_0x157c + 1;
    }
    ppuVar6 = &this->vtbl + iVar7 * 0x52;
    if (ppuVar6[0x92] != (undefined *)0x14) {
      ppuVar3 = ppuVar6 + (int)ppuVar6[0x92] * 4;
      ppuVar3[0x93] = (undefined *)(float)dVar10;
      ppuVar3[0x94] = (undefined *)(float)dVar11;
      ppuVar3[0x95] = (undefined *)(float)dVar12;
      *(char *)(ppuVar3 + 0x96) = param_3;
      ppuVar6[0x92] = ppuVar6[0x92] + 1;
    }
  }
LAB_802a8f30:
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802a9098) */
/* WARNING: Removing unreachable block (ram,0x802a90a0) */
/* __thiscall JAIZelBasic::processLevObjSE(void) */

void __thiscall JAIZelBasic::processLevObjSE(JAIZelBasic *this)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  sbyte sVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  undefined8 in_f30;
  double dVar16;
  undefined8 in_f31;
  double dVar17;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  iVar8 = 0;
  dVar16 = (double)JAZelAudio::_4004;
  dVar17 = (double)JAZelAudio::1_0;
  for (uVar7 = 0; uVar7 < *(uint *)&this->field_0x157c; uVar7 = uVar7 + 1) {
    dVar13 = (double)JAZelAudio::_4004;
    sVar6 = 0;
    iVar3 = 0;
    iVar4 = (int)&this->vtbl + iVar8;
    dVar14 = dVar13;
    dVar15 = dVar13;
    for (iVar2 = *(int *)(iVar4 + 0x248); iVar2 != 0; iVar2 = iVar2 + -1) {
      iVar5 = iVar4 + iVar3;
      dVar11 = (double)*(float *)(iVar5 + 0x24c);
      if (dVar16 < dVar11) {
        sVar6 = *(sbyte *)(iVar5 + 600);
      }
      dVar12 = (double)(float)((double)(float)(dVar17 - (double)*(float *)(iVar5 + 0x250)) * dVar11)
      ;
      dVar10 = (double)(float)((double)*(float *)(iVar5 + 0x250) * dVar11);
      dVar11 = (double)(float)((double)*(float *)(iVar5 + 0x254) * dVar11);
      if (dVar14 < dVar12) {
        dVar14 = dVar12;
      }
      if (dVar15 < dVar10) {
        dVar15 = dVar10;
      }
      if (dVar13 < dVar11) {
        dVar13 = dVar11;
      }
      iVar3 = iVar3 + 0x10;
    }
    dVar11 = dVar15;
    if (dVar15 < dVar14) {
      dVar11 = dVar14;
    }
    dVar10 = dVar13;
    if (dVar13 < dVar11) {
      dVar10 = dVar11;
    }
    if ((dVar16 != dVar14) || (fVar1 = JAZelAudio::_6028, dVar16 != dVar15)) {
      fVar1 = (float)(dVar15 / (double)(float)(dVar14 + dVar15));
    }
    if (*(char *)&this->field_0x207 == '\0') {
      seStart(this,*(ulong *)(iVar4 + 0x244),(cXyz *)0x0,0,sVar6,JAZelAudio::1_0,(float)dVar10,fVar1
              ,(float)dVar13,1);
    }
    iVar8 = iVar8 + 0x148;
  }
  initLevObjSE(this);
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  return;
}


/* __thiscall JAIZelBasic::initLevObjSE(void) */

void __thiscall JAIZelBasic::initLevObjSE(JAIZelBasic *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  *(undefined4 *)&this->field_0x157c = 0;
  fVar2 = JAZelAudio::_6028;
  fVar1 = JAZelAudio::_4004;
  iVar7 = 0;
  iVar3 = 0;
  do {
    iVar5 = (int)&this->vtbl + iVar3;
    *(undefined4 *)(iVar5 + 0x244) = 0xffffffff;
    *(undefined4 *)(iVar5 + 0x248) = 0;
    iVar4 = 0;
    iVar8 = 0x14;
    do {
      iVar6 = iVar5 + iVar4;
      *(float *)(iVar6 + 0x24c) = fVar1;
      *(float *)(iVar6 + 0x250) = fVar2;
      *(float *)(iVar6 + 0x254) = fVar1;
      iVar4 = iVar4 + 0x10;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    iVar7 = iVar7 + 1;
    iVar3 = iVar3 + 0x148;
  } while (iVar7 < 0xf);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JAIZelBasic::charVoicePlay(long,
                                         long,
                                         Vec *,
                                         signed char) */

void __thiscall
JAIZelBasic::charVoicePlay(JAIZelBasic *this,long param_1,long param_2,Vec *param_3,char param_4)

{
  if (this->field_0x201 != 1) {
    if (*(JAISound **)&this->field_0x2060 != (JAISound *)0x0) {
      JAISound::stop(*(JAISound **)&this->field_0x2060,0);
    }
    JAIBasic::startSoundVec
              ((JAIBasic *)this,JA_SE_CV_COMMON_PEOPLE,(JAISound **)&this->field_0x2060,param_3,0,0,
               '\x04');
    if (*(JAISound **)&this->field_0x2060 != (JAISound *)0x0) {
      JAISound::setPortData
                (*(JAISound **)&this->field_0x2060,'\b',(short)(param_1 << 8) + (short)param_2);
      JAISound::setPortData(*(JAISound **)&this->field_0x2060,'\t',(short)param_4);
    }
  }
  return;
}


/* __thiscall JAIZelBasic::messageSePlay(unsigned short,
                                         Vec *,
                                         signed char) */

void __thiscall
JAIZelBasic::messageSePlay(JAIZelBasic *this,ushort param_1,Vec *param_2,char param_3)

{
  ushort uVar1;
  uint soundId;
  ushort uVar2;
  
  if (param_1 < 0x118) {
    if ((param_1 == 0x104) || (((param_1 < 0x104 && (param_1 < 0xbb)) && (0xb3 < param_1)))) {
      param_2 = (Vec *)0x0;
    }
    uVar1 = *(ushort *)(&charVoiceTable + (uint)param_1 * 4);
    soundId = (uint)*(ushort *)(&DAT_8039bc32 + (uint)param_1 * 4);
    if ((uVar1 != 0xffff) && (soundId != 0xffff)) {
      uVar2 = uVar1 & 0xf000;
      if (uVar2 != 0x2000) {
        if (uVar2 < 0x2000) {
          if (uVar2 != 0x1000) {
            if (0xfff < uVar2) {
              return;
            }
            if ((uVar1 & 0xf000) != 0) {
              return;
            }
            charVoicePlay(this,(uint)uVar1,soundId,param_2,param_3);
            return;
          }
        }
        else {
          if (uVar2 != 0x8000) {
            if (0x7fff < uVar2) {
              return;
            }
            if (uVar2 != 0x3000) {
              return;
            }
          }
        }
      }
      seStart(this,soundId,(cXyz *)param_2,0,param_3,JAZelAudio::1_0,JAZelAudio::1_0,
              JAZelAudio::_4357,JAZelAudio::_4357,0);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802a9634) */
/* WARNING: Removing unreachable block (ram,0x802a963c) */
/* __thiscall JAIZelBasic::shipCruiseSePlay(Vec *,
                                            float) */

void __thiscall JAIZelBasic::shipCruiseSePlay(JAIZelBasic *this,Vec *param_1,float param_2)

{
  MTX34 *pMtx;
  float *pfVar1;
  JAISoundInfoID JVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f30;
  undefined8 in_f31;
  cXyz local_44 [2];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar5 = (double)param_2;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  this->field_0x1f40 = param_2;
  if ((*(int *)&this->field_0x68 == 0) || ((undefined *)this->field_0x78 != &DAT_8000002e)) {
    if ((*(int *)&this->field_0x68 != 0) && ((undefined4 *)this->field_0x78 == &DAT_8000003c)) {
      if ((this->mIsSailing != 0) || ((double)JAZelAudio::_4732 <= dVar5)) {
        bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_8000003c,0,0x1e);
      }
      else {
        bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_8000003c,1,0x1e);
      }
    }
  }
  else {
    if ((this->mIsSailing != 0) || ((double)JAZelAudio::_4732 <= dVar5)) {
      bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_8000002e,0,0x1e);
    }
    else {
      bgmMute(this,(JAISound **)&this->field_0x68,(ulong)&DAT_8000002e,1,0x1e);
    }
  }
  if (this->field_0x201 != 1) {
    pMtx = (MTX34 *)(*(float ***)&this->field_0x4)[2];
    local_44[0].x = JAZelAudio::_6473;
    local_44[0].y = DAT_8036a13c;
    local_44[0].z = DAT_8036a140;
    if (param_1 == (Vec *)0x0) {
      pfVar1 = **(float ***)&this->field_0x4;
      if (pfVar1 != (float *)0x0) {
        local_44[0].x = *pfVar1;
        local_44[0].y = pfVar1[1];
        local_44[0].z = pfVar1[2];
      }
    }
    else {
      local_44[0].x = *(float *)param_1;
      local_44[0].y = *(float *)(param_1 + 4);
      local_44[0].z = *(float *)(param_1 + 8);
    }
    if (pMtx != (MTX34 *)0x0) {
      mtx::PSMTXMultVec(pMtx,local_44,local_44);
    }
    dVar6 = (double)(local_44[0].z * local_44[0].z +
                    local_44[0].x * local_44[0].x + local_44[0].y * local_44[0].y);
    if ((double)JAZelAudio::_4004 < dVar6) {
      dVar4 = 1.0 / SQRT(dVar6);
      dVar4 = JAZelAudio::_4349 * dVar4 * (JAZelAudio::_4350 - dVar6 * dVar4 * dVar4);
      dVar4 = JAZelAudio::_4349 * dVar4 * (JAZelAudio::_4350 - dVar6 * dVar4 * dVar4);
      dVar6 = (double)(float)(dVar6 * JAZelAudio::_4349 * dVar4 *
                                      (JAZelAudio::_4350 - dVar6 * dVar4 * dVar4));
    }
    dVar4 = (double)JAIGlobalParameter::getParamDistanceMax((JAIGlobalParameter *)pMtx);
    if (dVar6 < dVar4) {
      dVar6 = (double)JAZelAudio::_4004;
      if ((double)JAZelAudio::_6517 < dVar5) {
        dVar4 = (double)JAZelAudio::_6028;
        if (dVar4 < dVar5) {
          if ((double)JAZelAudio::_6029 < dVar5) {
            if ((double)JAZelAudio::_6518 < dVar5) {
              dVar6 = (double)JAZelAudio::1_0;
              JVar2 = JA_SE_SHIP_WAVE_L;
              dVar5 = dVar6;
            }
            else {
              dVar6 = (double)JAZelAudio::1_0;
              JVar2 = JA_SE_SHIP_WAVE_L;
              dVar5 = (double)((float)(dVar5 - dVar4) / JAZelAudio::_5372);
            }
          }
          else {
            dVar6 = (double)JAZelAudio::1_0;
            JVar2 = JA_SE_SHIP_WAVE_L;
            dVar5 = (double)((float)(dVar5 - dVar4) / JAZelAudio::_5372);
          }
        }
        else {
          dVar6 = (double)((float)(dVar5 - (double)JAZelAudio::_6517) / JAZelAudio::_5372);
          JVar2 = JA_SE_SHIP_WAVE_S;
          dVar5 = (double)(float)((double)JAZelAudio::1_0 - dVar6);
        }
      }
      else {
        JVar2 = JA_SE_SHIP_WAVE_S;
        dVar5 = (double)JAZelAudio::1_0;
      }
      if ((double)JAZelAudio::_4004 != dVar6) {
        JAIBasic::startSoundVec
                  ((JAIBasic *)this,JA_SE_SHIP_GO_NORMAL,(JAISound **)&this->field_0x1f44,param_1,0,
                   0,'\x04');
        JAISound::setVolume(*(JAISound **)&this->field_0x1f44,(float)dVar6,0,0);
      }
      if ((double)JAZelAudio::_4004 != dVar5) {
        JAIBasic::startSoundVec
                  ((JAIBasic *)this,JVar2,(JAISound **)&this->field_0x1f48,param_1,0,0,'\x04');
        JAISound::setVolume(*(JAISound **)&this->field_0x1f48,(float)dVar5,0,0);
      }
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return;
}


/* __thiscall JAIZelBasic::setShipSailState(long) */

void __thiscall JAIZelBasic::setShipSailState(JAIZelBasic *this,long param_1)

{
  this->mIsSailing = (byte)param_1;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::init(JKRSolidHeap *,
                                unsigned long) */

int __thiscall JAIZelBasic::init(JAIZelBasic *this,EVP_PKEY_CTX *ctx)

{
  float fVar1;
  JAIGlobalParameter *pJVar2;
  int iVar3;
  ulong extraout_r4;
  ulong extraout_r4_00;
  ulong extraout_r4_01;
  ulong extraout_r4_02;
  ulong extraout_r4_03;
  ulong extraout_r4_04;
  ulong extraout_r4_05;
  ulong extraout_r4_06;
  ulong extraout_r4_07;
  ulong extraout_r4_08;
  long extraout_r4_09;
  uchar extraout_r4_20;
  ushort extraout_r4_19;
  char *extraout_r4_10;
  char *extraout_r4_11;
  char *extraout_r4_12;
  char *extraout_r4_13;
  char *extraout_r4_14;
  char *extraout_r4_15;
  ulong extraout_r4_16;
  ulong extraout_r4_17;
  ulong extraout_r4_18;
  bool extraout_r4_21;
  ulong in_r5;
  
  JAIGlobalParameter::setParamInterfaceHeapSize(_DRAM_HEAP_SIZE,(ulong)ctx);
  JAIGlobalParameter::setParamSeRegistMax(_SE_REGIST_MAX,extraout_r4);
  JAIGlobalParameter::setParamSoundSceneMax(_SOUND_SCENE_MAX,extraout_r4_00);
  JAIGlobalParameter::setParamSeqControlBufferMax(_SEQ_CONTROL_BUF_MAX,extraout_r4_01);
  JAIGlobalParameter::setParamStreamControlBufferMax(_STREAM_CONTROL_BUF_MAX,extraout_r4_02);
  JAIGlobalParameter::setParamStreamDecodedBufferBlocks(_STREAM_DECODED_BUFFERS,extraout_r4_03);
  JAIGlobalParameter::setParamAutoHeapMax(_AUTO_HEAP_MAX,extraout_r4_04);
  JAIGlobalParameter::setParamStayHeapMax(_STAY_HEAP_MAX,extraout_r4_05);
  JAIGlobalParameter::setParamAutoHeapRoomSize(_AUTO_HEAP_ROOM_SIZE,extraout_r4_06);
  JAIGlobalParameter::setParamStayHeapSize(_STAY_HEAP_ROOM_SIZE,extraout_r4_07);
  JAIGlobalParameter::setParamSeqPlayTrackMax(_PLAY_TRACK_MAX,extraout_r4_08);
  pJVar2 = (JAIGlobalParameter *)
           JAIGlobalParameter::setParamSystemTrackMax(_SYSTEM_TRACK_MAX,extraout_r4_09);
  pJVar2 = (JAIGlobalParameter *)JAIGlobalParameter::setParamDistanceMax(pJVar2,_DISTANCE_MAX);
  pJVar2 = (JAIGlobalParameter *)
           JAIGlobalParameter::setParamMaxVolumeDistance(pJVar2,_MAX_VOLUME_DISTANCE);
  JAIGlobalParameter::setParamMinDistanceVolume(pJVar2,_MIN_DISTANCE_VOLUME);
  pJVar2 = (JAIGlobalParameter *)
           JAIGlobalParameter::setParamSeDolbyCenterValue
                     ((JAIGlobalParameter *)(uint)JAIZelParam::DOLBY_CENTER_VALUE,extraout_r4_20);
  pJVar2 = (JAIGlobalParameter *)
           JAIGlobalParameter::setParamSeDolbyFrontDistanceMax(pJVar2,_DOLBY_FLONT_DISTANCE_MAX);
  JAIGlobalParameter::setParamSeDolbyBehindDistanceMax(pJVar2,_DOLBY_BEHIND_DISTANCE_MAX);
  pJVar2 = (JAIGlobalParameter *)
           JAIGlobalParameter::setParamSeDistanceFxParameter
                     ((JAIGlobalParameter *)(uint)_DISTANCE_FX_PARAM,extraout_r4_19);
  pJVar2 = (JAIGlobalParameter *)JAIGlobalParameter::setParamInputGainDown(pJVar2,JAZelAudio::1_0);
  JAIGlobalParameter::setParamOutputGainUp(pJVar2,JAZelAudio::_6528);
  JAIGlobalParameter::setParamAudioResPath((JAIGlobalParameter *)0x0,extraout_r4_10);
  JAIGlobalParameter::setParamInitDataFileName
            ((JAIGlobalParameter *)JAIZelParam::INIT_DATA_FILE_NAME,extraout_r4_11);
  JAIGlobalParameter::setParamWavePath(_WAVE_PATH,extraout_r4_12);
  JAIGlobalParameter::setParamSequenceArchivesPath(_SEQ_PATH,extraout_r4_13);
  JAIGlobalParameter::setParamStreamPath(_STREAM_PATH,extraout_r4_14);
  JAIGlobalParameter::setParamSequenceArchivesFileName(_SEQ_ARCH_FILE_NAME,extraout_r4_15);
  JAIGlobalParameter::setParamAudioCameraMax((JAIGlobalParameter *)&DAT_00000001,extraout_r4_16);
  JAIGlobalParameter::setParamDummyObjectMax(_DUMMY_POSITION_MAX,extraout_r4_17);
  JAIGlobalParameter::setParamDummyObjectLifeTime(_DUMMY_POSITION_LIFE_TIME,extraout_r4_18);
  JAIGlobalParameter::setParamStreamInsideBufferCut
            ((JAIGlobalParameter *)&DAT_00000001,extraout_r4_21);
  JAIBasic::initDriver((JAIBasic *)this,(JKRSolidHeap *)ctx,in_r5,'\x01');
  JAIBasic::initInterface((JAIBasic *)this,'\x01');
  *(undefined4 *)&this->field_0x68 = 0;
  *(undefined4 *)&this->field_0x6c = 0;
  this->mpSound = (JAISound *)0x0;
  initSe(this);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\0',JAIZelParam::VOL_SE_SYSTEM_DEFAULT);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x01',JAIZelParam::VOL_SE_LINK_VOICE_DEFAULT);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x02',JAIZelParam::VOL_SE_LINK_MOTION_DEFAULT);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x03',JAIZelParam::VOL_SE_LINK_FOOTNOTE_DEFAULT);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x04',JAIZelParam::VOL_SE_CHAR_VOICE_DEFAULT);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x05',JAIZelParam::VOL_SE_CHAR_MOVE_DEFAULT);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x06',JAIZelParam::VOL_SE_OBJECT_DEFAULT);
  iVar3 = JAIBasic::setSeCategoryVolume
                    ((JAIBasic *)this,'\a',JAIZelParam::VOL_SE_ATMOSPHERE_DEFAULT);
  fVar1 = JAZelAudio::1_0;
  this->field_0x80 = JAZelAudio::1_0;
  this->field_0x84 = fVar1;
  this->field_0x88 = fVar1;
  this->field_0x8c = fVar1;
  this->field_0x90 = fVar1;
  this->field_0x94 = fVar1;
  this->field_0x98 = fVar1;
  this->field_0x9c = fVar1;
  this->field_0xac = fVar1;
  return iVar3;
}


/* __thiscall JAIZelBasic::setOutputMode(unsigned long) */

JAIZelBasic * __thiscall JAIZelBasic::setOutputMode(JAIZelBasic *this,ulong param_1)

{
  if (param_1 < 3) {
    this = (JAIZelBasic *)
           JAIGlobalParameter::setParamSoundOutputMode((JAIGlobalParameter *)param_1,param_1);
  }
  return this;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::talkIn(void) */

void __thiscall JAIZelBasic::talkIn(JAIZelBasic *this)

{
  int iVar1;
  
  if (((*(char *)&this->field_0x64 != '\x01') && (iVar1 = isDemo(this), iVar1 != 1)) &&
     (JAZelAudio::_4004 != this->field_0x98)) {
    this->field_0x84 = _VOL_BGM_TALKING;
    if (((*(JAISound **)&this->field_0x68 != (JAISound *)0x0) &&
        ((undefined *)this->field_0x78 != &DAT_80000051)) &&
       ((undefined *)this->field_0x78 != &DAT_80000052)) {
      JAISound::setVolume(*(JAISound **)&this->field_0x68,
                          this->field_0xac *
                          this->field_0x9c *
                          this->field_0x98 *
                          this->field_0x94 *
                          this->field_0x90 *
                          this->field_0x8c * this->field_0x88 * this->field_0x80 * this->field_0x84,
                          2,0);
    }
    this->field_0xa0 = _VOL_BGM_TALKING;
    if (*(JAISound **)&this->field_0x6c != (JAISound *)0x0) {
      JAISound::setSeqInterVolume
                (*(JAISound **)&this->field_0x6c,'\0',
                 this->field_0xa8 * this->field_0xa0 * this->field_0xa4,2);
    }
    JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\0',JAIZelParam::VOL_SE_SYSTEM_TALKING);
    JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x01',JAIZelParam::VOL_SE_LINK_VOICE_TALKING);
    JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x02',JAIZelParam::VOL_SE_LINK_MOTION_TALKING);
    JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x03',JAIZelParam::VOL_SE_LINK_FOOTNOTE_TALKING)
    ;
    JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x04',JAIZelParam::VOL_SE_CHAR_VOICE_TALKING);
    JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x05',JAIZelParam::VOL_SE_CHAR_MOVE_TALKING);
    JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x06',JAIZelParam::VOL_SE_OBJECT_TALKING);
    JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\a',JAIZelParam::VOL_SE_ATMOSPHERE_TALKING);
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::talkOut(void) */

void __thiscall JAIZelBasic::talkOut(JAIZelBasic *this)

{
  int iVar1;
  
  iVar1 = checkStreamPlaying(this,0xc0000006);
  if (iVar1 != 1) {
    this->field_0x84 = _VOL_BGM_DEFAULT;
    if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
      JAISound::setVolume(*(JAISound **)&this->field_0x68,
                          this->field_0xac *
                          this->field_0x9c *
                          this->field_0x98 *
                          this->field_0x94 *
                          this->field_0x90 *
                          this->field_0x8c * this->field_0x88 * this->field_0x80 * this->field_0x84,
                          2,0);
    }
    this->field_0xa0 = _VOL_BGM_DEFAULT;
    if (*(JAISound **)&this->field_0x6c != (JAISound *)0x0) {
      JAISound::setSeqInterVolume
                (*(JAISound **)&this->field_0x6c,'\0',
                 this->field_0xa8 * this->field_0xa0 * this->field_0xa4,2);
    }
    JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\0',JAIZelParam::VOL_SE_SYSTEM_DEFAULT);
    JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x01',JAIZelParam::VOL_SE_LINK_VOICE_DEFAULT);
    JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x02',JAIZelParam::VOL_SE_LINK_MOTION_DEFAULT);
    JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x03',JAIZelParam::VOL_SE_LINK_FOOTNOTE_DEFAULT)
    ;
    JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x04',JAIZelParam::VOL_SE_CHAR_VOICE_DEFAULT);
    JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x05',JAIZelParam::VOL_SE_CHAR_MOVE_DEFAULT);
    JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x06',JAIZelParam::VOL_SE_OBJECT_DEFAULT);
    JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\a',JAIZelParam::VOL_SE_ATMOSPHERE_DEFAULT);
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::menuIn(void) */

void __thiscall JAIZelBasic::menuIn(JAIZelBasic *this)

{
  this->field_0x88 = _VOL_BGM_PAUSING;
  if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
    JAISound::setVolume(*(JAISound **)&this->field_0x68,
                        this->field_0xac *
                        this->field_0x9c *
                        this->field_0x98 *
                        this->field_0x94 *
                        this->field_0x90 *
                        this->field_0x8c * this->field_0x88 * this->field_0x80 * this->field_0x84,2,
                        0);
  }
  this->field_0xa0 = _VOL_BGM_PAUSING;
  if (*(JAISound **)&this->field_0x6c != (JAISound *)0x0) {
    JAISound::setSeqInterVolume
              (*(JAISound **)&this->field_0x6c,'\0',
               this->field_0xa8 * this->field_0xa0 * this->field_0xa4,2);
  }
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\0',JAIZelParam::VOL_SE_SYSTEM_PAUSING);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x01',JAIZelParam::VOL_SE_LINK_VOICE_PAUSING);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x02',JAIZelParam::VOL_SE_LINK_MOTION_PAUSING);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x03',JAIZelParam::VOL_SE_LINK_FOOTNOTE_PAUSING);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x04',JAIZelParam::VOL_SE_CHAR_VOICE_PAUSING);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x05',JAIZelParam::VOL_SE_CHAR_MOVE_PAUSING);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\x06',JAIZelParam::VOL_SE_OBJECT_PAUSING);
  JAIBasic::setSeCategoryVolume((JAIBasic *)this,'\a',JAIZelParam::VOL_SE_ATMOSPHERE_PAUSING);
  this->field_0x20 = 1;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::menuOut(void) */

void __thiscall JAIZelBasic::menuOut(JAIZelBasic *this)

{
  this->field_0x88 = _VOL_BGM_DEFAULT;
  talkOut(this);
  this->field_0x20 = 0;
  return;
}


/* __thiscall JAIZelBasic::getCameraInfo(Vec *,
                                         float *[][][][],
                                         unsigned long) */

void __thiscall
JAIZelBasic::getCameraInfo(JAIZelBasic *this,Vec *param_1,float *param_2,ulong param_3)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  
  iVar3 = param_3 * 0xc;
  *(Vec **)(*(int *)&this->field_0x4 + iVar3) = param_1;
  *(float **)(*(int *)&this->field_0x4 + iVar3 + 4) = &this->field_0x48;
  *(float **)(*(int *)&this->field_0x4 + iVar3 + 8) = param_2;
  pfVar2 = **(float ***)&this->field_0x4;
  if (pfVar2 != (float *)0x0) {
    if (((JAZelAudio::_4003 == *pfVar2) && (JAZelAudio::_4003 == pfVar2[1])) &&
       (JAZelAudio::_4003 == pfVar2[2])) {
      *(undefined *)&this->field_0x1f8 = 10;
    }
    else {
      if (*(char *)&this->field_0x1f8 != '\0') {
        *(char *)&this->field_0x1f8 = *(char *)&this->field_0x1f8 + -1;
      }
    }
    fVar1 = JAZelAudio::_4003;
    this->field_0x48 = JAZelAudio::_4003;
    this->field_0x4c = fVar1;
    this->field_0x50 = fVar1;
    return;
  }
  *(undefined *)&this->field_0x1f8 = 10;
  this->field_0x48 = *(float *)param_1;
  this->field_0x4c = *(float *)(param_1 + 4);
  this->field_0x50 = *(float *)(param_1 + 8);
  return;
}


/* __thiscall JAIZelBasic::getCameraMapInfo(unsigned long) */

void __thiscall JAIZelBasic::getCameraMapInfo(JAIZelBasic *this,ulong param_1)

{
  *(ulong *)&this->field_0x218 = param_1;
  return;
}


/* __thiscall JAIZelBasic::setCameraPolygonPos(Vec *) */

void __thiscall JAIZelBasic::setCameraPolygonPos(JAIZelBasic *this,Vec *param_1)

{
  if (param_1 == (Vec *)0x0) {
    return;
  }
  this->field_0x54 = *(float *)param_1;
  this->field_0x58 = *(float *)(param_1 + 4);
  this->field_0x5c = *(float *)(param_1 + 8);
  return;
}


/* __thiscall JAIZelBasic::setCameraGroupInfo(unsigned char) */

void __thiscall JAIZelBasic::setCameraGroupInfo(JAIZelBasic *this,byte newSeaFloorGroupInfo)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = isDemo(this);
  if (iVar2 == 1) {
    return;
  }
  if (*(char *)&this->field_0xbd != '\0') {
    return;
  }
  if (*(char *)&this->field_0xbf != '\0') {
    return;
  }
  bVar1 = this->mCameraSeaFloorGroupInfo;
  if (newSeaFloorGroupInfo != bVar1) {
    if ((newSeaFloorGroupInfo & 0x80) == 0) {
      if ((newSeaFloorGroupInfo == 0) || ((newSeaFloorGroupInfo & 0x40) != 0)) {
        if ((bVar1 & 0x80) == 0) {
          if (((bVar1 & 0x40) == 0) && (bVar1 != 0)) {
            m_Do_printf::OSReport("[JAIZelBasic::setCameraGroupInfo] Inner Edge -> Inner Sea\n");
          }
        }
        else {
          m_Do_printf::OSReport("[JAIZelBasic::setCameraGroupInfo] Outer Edge -> Outer Sea\n");
          this->mIslandRoomNo = 0;
        }
      }
      else {
        if ((bVar1 & 0x40) == 0) {
          m_Do_printf::OSReport("[JAIZelBasic::setCameraGroupInfo] Outer Edge -> Inner Edge\n");
        }
        else {
          m_Do_printf::OSReport("[JAIZelBasic::setCameraGroupInfo] Inner Sea -> Inner Edge\n");
        }
      }
    }
    else {
      this->mIslandRoomNo = newSeaFloorGroupInfo & 0x3f;
      if (this->mCameraSeaFloorGroupInfo == 0) {
        m_Do_printf::OSReport("[JAIZelBasic::setCameraGroupInfo] Outer Sea -> Outer Edge\n");
        setScene(this,0x12,(uint)this->mIslandRoomNo,1,-1);
        load1stDynamicWave(this);
        load2ndDynamicWave(this);
        this->field_0x21e = 0;
        this->field_0x22d = 1;
      }
      else {
        m_Do_printf::OSReport("[JAIZelBasic::setCameraGroupInfo] Inner Edge -> Outer Edge\n");
      }
    }
    this->mCameraSeaFloorGroupInfo = newSeaFloorGroupInfo;
    return;
  }
  return;
}


/* __thiscall JAIZelBasic::changeSeaBgm(void) */

void __thiscall JAIZelBasic::changeSeaBgm(JAIZelBasic *this)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint bgmId;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  
  if ((((((this->field_0x224 == 0x12) && (this->mIslandRoomNo != 0)) &&
        ((undefined *)this->field_0x78 != &DAT_8000000a)) &&
       ((iVar1 = checkEventBit(this,0xf80), iVar1 != 0 && (**(int **)&this->field_0x4 != 0)))) &&
      (((this->field_0x22d != 0 &&
        ((*(char *)&this->field_0x1f8 == '\0' && (this->mbLandingDemoStarted == 0)))) &&
       (*(char *)&this->field_0x62 == '\0')))) &&
     (((((iVar1 = checkDayTime(this), iVar1 != 0 ||
         (puVar2 = (undefined4 *)checkSeaBgmID(this), puVar2 == &DAT_8000003c)) &&
        (this->field_0x32 != 1)) &&
       ((iVar1 = isDemo(this), iVar1 != 1 &&
        ((*(int *)&this->field_0x6c == 0 || (this->field_0x74 != -0x7fffffd5)))))) &&
      (((*(int *)&this->field_0x68 == 0 || ((undefined *)this->field_0x78 != &DAT_80000053)) &&
       (*(char *)&this->field_0xbd == '\0')))))) {
    local_28 = JAZelAudio::_4004;
    iVar3 = checkOnOuterSea(this,&local_28);
    iVar1 = (uint)this->mIslandRoomNo * 0x10;
    local_24 = *(undefined4 *)(&mIsleArea + iVar1);
    local_20 = *(undefined4 *)(&DAT_8039c79c + iVar1);
    local_1c = *(undefined4 *)(&DAT_8039c7a0 + iVar1);
    local_18 = *(float *)(&DAT_8039c7a4 + iVar1);
    if (((undefined4 *)this->field_0x78 == (undefined4 *)&DAT_8000002e) ||
       ((undefined4 *)this->field_0x78 == &DAT_8000003c)) {
      if (iVar3 == 2) {
        this->field_0x94 = (local_28 - (JAZelAudio::_4356 + local_18)) / JAZelAudio::_6743;
        if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
          JAISound::setVolume(*(JAISound **)&this->field_0x68,
                              this->field_0xac *
                              this->field_0x9c *
                              this->field_0x98 *
                              this->field_0x94 *
                              this->field_0x90 *
                              this->field_0x8c *
                              this->field_0x88 * this->field_0x80 * this->field_0x84,1,0);
        }
      }
      else {
        if ((iVar3 < 2) && (0 < iVar3)) {
          this->field_0x94 = JAZelAudio::_4004;
          startIsleBgm(this);
        }
      }
    }
    else {
      if (iVar3 == 4) {
        this->field_0x94 = JAZelAudio::1_0;
        bgmId = checkSeaBgmID(this);
        bgmStart(this,bgmId,0x5a,1);
      }
      else {
        if (iVar3 < 4) {
          if (iVar3 == 1) {
            this->field_0x94 = ((JAZelAudio::_4356 + local_18) - local_28) / JAZelAudio::_4356;
            if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
              JAISound::setVolume(*(JAISound **)&this->field_0x68,
                                  this->field_0xac *
                                  this->field_0x9c *
                                  this->field_0x98 *
                                  this->field_0x94 *
                                  this->field_0x90 *
                                  this->field_0x8c *
                                  this->field_0x88 * this->field_0x80 * this->field_0x84,1,0);
            }
          }
          else {
            if (0 < iVar3) {
              this->field_0x94 = JAZelAudio::_4004;
              if (*(JAISound **)&this->field_0x68 != (JAISound *)0x0) {
                JAISound::setVolume(*(JAISound **)&this->field_0x68,
                                    this->field_0xac *
                                    this->field_0x9c *
                                    this->field_0x98 *
                                    this->field_0x94 *
                                    this->field_0x90 *
                                    this->field_0x8c *
                                    this->field_0x88 * this->field_0x80 * this->field_0x84,0,0);
              }
            }
          }
        }
      }
    }
  }
  return;
}


/* __thiscall JAIZelBasic::startIsleBgm(void) */

void __thiscall JAIZelBasic::startIsleBgm(JAIZelBasic *this)

{
  int iVar1;
  undefined *bgmId;
  
  iVar1 = checkDayTime(this);
  if (iVar1 != 0) {
    if ((this->mIslandRoomNo == 0x2c) && (iVar1 = checkEventBit(this,0xe20), iVar1 == 1)) {
      bgmId = &DAT_80000055;
    }
    else {
      bgmId = (undefined *)
              expandSceneBgmNum(this,(uint)*(ushort *)(&m_isle_info + (uint)this->mIslandRoomNo * 4)
                               );
    }
    bgmStart(this,(uint)bgmId,0,1);
  }
  return;
}


/* __thiscall JAIZelBasic::setLinkGroupInfo(unsigned char) */

void __thiscall JAIZelBasic::setLinkGroupInfo(JAIZelBasic *this,uchar newSeaFloorGroupInfo)

{
  if (this->field_0x224 != 0x12) {
    return;
  }
  if (this->mIslandRoomNo == 0) {
    return;
  }
  if (newSeaFloorGroupInfo == this->mLinkSeaFloorGroupInfo) {
    return;
  }
  this->mLinkSeaFloorGroupInfo = newSeaFloorGroupInfo;
  return;
}


/* __thiscall JAIZelBasic::getMapInfoFxline(unsigned long) */

uint __thiscall JAIZelBasic::getMapInfoFxline(JAIZelBasic *this,ulong param_1)

{
  return param_1 & 0xffff;
}


/* __thiscall JAIZelBasic::getMapInfoFxParameter(unsigned long) */

double __thiscall JAIZelBasic::getMapInfoFxParameter(JAIZelBasic *this,ulong param_1)

{
  return (double)JAZelAudio::_4004;
}


/* __thiscall JAIZelBasic::getMapInfoGround(unsigned long) */

undefined4 __thiscall JAIZelBasic::getMapInfoGround(JAIZelBasic *this,ulong param_1)

{
  return 0;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::setScene(long,
                                    long,
                                    long,
                                    long) */

void __thiscall
JAIZelBasic::setScene(JAIZelBasic *this,long param_1,long param_2,long param_3,long param_4)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  m_Do_printf::OSReport
            ("[JAIZelBasic::setScene] num = %d, start = %d, layer = %d (%d)\n",param_1,param_2,
             param_4,param_3);
  if (param_1 < 0x79) {
    if (*(char *)&this->field_0x22c == '\0') {
      puVar5 = (undefined4 *)0x0;
      *(undefined *)&this->field_0xcd = 0;
      *(undefined *)&this->field_0xbd = 0;
      if (param_1 == 0x12) {
        if (param_2 < 1) {
          this->mIslandRoomNo = 0;
        }
        else {
          this->mIslandRoomNo = (byte)param_2;
        }
        m_Do_printf::OSReport("  --- Isle = %d\n",this->mIslandRoomNo);
        if (param_3 != 1) {
          uVar3 = (uint)this->mIslandRoomNo;
          if (uVar3 == 0x2c) {
            if (param_4 == 10) {
              puVar5 = (undefined4 *)0x0;
            }
            else {
              iVar4 = checkEventBit(this,0x3510);
              if (iVar4 == 0) {
                puVar5 = &DAT_80000038;
              }
              else {
                iVar4 = checkEventBit(this,1);
                if ((iVar4 == 1) && (iVar4 = checkEventBit(this,0x101), iVar4 == 0)) {
                  puVar5 = (undefined4 *)&DAT_8000000e;
                }
                else {
                  iVar4 = checkEventBit(this,0x101);
                  if ((iVar4 == 1) && (iVar4 = checkEventBit(this,0xe20), iVar4 == 0)) {
                    puVar5 = (undefined4 *)0x0;
                  }
                  else {
                    iVar4 = checkEventBit(this,0xe20);
                    if (iVar4 == 1) {
                      puVar5 = (undefined4 *)&DAT_80000055;
                    }
                    else {
                      puVar5 = (undefined4 *)
                               expandSceneBgmNum(this,(uint)*(ushort *)
                                                             (&m_isle_info +
                                                             (uint)this->mIslandRoomNo * 4));
                    }
                  }
                }
              }
            }
          }
          else {
            if (uVar3 == 0xb) {
              iVar4 = checkEventBit(this,0x2e01);
              if (iVar4 == 0) {
                puVar5 = (undefined4 *)0x0;
              }
              else {
                puVar5 = (undefined4 *)
                         expandSceneBgmNum(this,(uint)*(ushort *)
                                                       (&m_isle_info + (uint)this->mIslandRoomNo * 4
                                                       ));
              }
            }
            else {
              if (uVar3 == 0xd) {
                if (((param_4 == 8) || (param_4 == 10)) || (param_4 == 0xb)) {
                  puVar5 = (undefined4 *)0x0;
                }
                else {
                  puVar5 = (undefined4 *)expandSceneBgmNum(this,(uint)uRam8039c524);
                }
              }
              else {
                if (uVar3 == 0xe) {
                  if ((param_4 == 2) || (param_4 == 3)) {
                    puVar5 = (undefined4 *)0x0;
                    *(undefined *)&this->field_0xbd = 1;
                  }
                  else {
                    puVar5 = (undefined4 *)expandSceneBgmNum(this,(uint)uRam8039c528);
                  }
                }
                else {
                  puVar5 = (undefined4 *)
                           expandSceneBgmNum(this,(uint)*(ushort *)(&m_isle_info + uVar3 * 4));
                }
              }
            }
          }
        }
        iVar4 = (uint)this->mIslandRoomNo * 4;
        bVar1 = (&DAT_8039c4f2)[iVar4];
        bVar2 = (&DAT_8039c4f3)[iVar4];
      }
      else {
        this->mIslandRoomNo = 0;
        if ((param_1 == 0x10) && (iVar4 = checkEventBit(this,0x280), iVar4 == 0)) {
          puVar5 = (undefined4 *)&DAT_80000016;
        }
        else {
          if ((param_1 == 0x13) && (iVar4 = checkEventBit(this,0x801), iVar4 == 0)) {
            puVar5 = (undefined4 *)0x0;
          }
          else {
            if ((param_1 == 2) && (this->field_0x21 != 0)) {
              iVar4 = dSv_memBit_c::isDungeonItem
                                ((dSv_memBit_c *)
                                 (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mMemory + 3),5);
              if (iVar4 != 0) {
                *(undefined *)&this->field_0xcd = 1;
              }
              iVar4 = dSv_memBit_c::isDungeonItem
                                ((dSv_memBit_c *)
                                 (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mMemory + 3),3);
              if (iVar4 == 0) {
                puVar5 = (undefined4 *)expandSceneBgmNum(this,(uint)uRam8039c314);
              }
              else {
                puVar5 = (undefined4 *)expandSceneBgmNum(this,(uint)_DAT_8039c310);
                *(undefined *)&this->field_0x204 = 1;
              }
            }
            else {
              if ((param_1 == 7) && (this->field_0x21 != 0)) {
                iVar4 = dSv_memBit_c::isDungeonItem
                                  ((dSv_memBit_c *)
                                   (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mMemory + 4),5)
                ;
                if (iVar4 != 0) {
                  *(undefined *)&this->field_0xcd = 1;
                }
                iVar4 = dSv_memBit_c::isDungeonItem
                                  ((dSv_memBit_c *)
                                   (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mMemory + 4),3)
                ;
                if (iVar4 == 0) {
                  puVar5 = (undefined4 *)expandSceneBgmNum(this,(uint)uRam8039c328);
                }
                else {
                  puVar5 = (undefined4 *)expandSceneBgmNum(this,(uint)_DAT_8039c318);
                }
              }
              else {
                if ((param_1 == 0x25) && (this->field_0x21 != 0)) {
                  iVar4 = dSv_memBit_c::isDungeonItem
                                    ((dSv_memBit_c *)
                                     (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mMemory + 5),
                                     5);
                  if (iVar4 != 0) {
                    *(undefined *)&this->field_0xcd = 1;
                  }
                  iVar4 = dSv_memBit_c::isDungeonItem
                                    ((dSv_memBit_c *)
                                     (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mMemory + 5),
                                     3);
                  if (iVar4 == 0) {
                    puVar5 = (undefined4 *)expandSceneBgmNum(this,(uint)uRam8039c3a0);
                  }
                  else {
                    puVar5 = (undefined4 *)expandSceneBgmNum(this,(uint)_DAT_8039c334);
                  }
                }
                else {
                  if ((param_1 == 0x18) && (this->field_0x21 != 0)) {
                    iVar4 = dSv_memBit_c::isDungeonItem
                                      ((dSv_memBit_c *)
                                       (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mMemory + 7
                                       ),5);
                    if (iVar4 != 0) {
                      *(undefined *)&this->field_0xcd = 1;
                    }
                    if ((param_4 - 8U < 3) || (param_4 == 0xb)) {
                      puVar5 = (undefined4 *)0x0;
                    }
                    else {
                      iVar4 = dSv_memBit_c::isDungeonItem
                                        ((dSv_memBit_c *)
                                         (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mMemory +
                                         7),3);
                      if (iVar4 == 0) {
                        puVar5 = (undefined4 *)expandSceneBgmNum(this,(uint)uRam8039c36c);
                      }
                      else {
                        puVar5 = (undefined4 *)0x0;
                      }
                    }
                  }
                  else {
                    if ((param_1 == 0x2d) && (this->field_0x21 != 0)) {
                      iVar4 = dSv_memBit_c::isDungeonItem
                                        ((dSv_memBit_c *)
                                         (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mMemory +
                                         6),5);
                      if (iVar4 != 0) {
                        *(undefined *)&this->field_0xcd = 1;
                      }
                      if ((param_4 - 8U < 3) || (param_4 == 0xb)) {
                        puVar5 = (undefined4 *)0x0;
                      }
                      else {
                        iVar4 = dSv_memBit_c::isDungeonItem
                                          ((dSv_memBit_c *)
                                           (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mMemory
                                           + 6),3);
                        if (iVar4 == 0) {
                          puVar5 = (undefined4 *)expandSceneBgmNum(this,(uint)uRam8039c3c0);
                        }
                        else {
                          puVar5 = (undefined4 *)0x0;
                        }
                      }
                    }
                    else {
                      if (param_1 == 0x36) {
                        iVar4 = checkEventBit(this,0x2d04);
                        if (iVar4 == 0) {
                          puVar5 = &DAT_80000034;
                        }
                        else {
                          puVar5 = (undefined4 *)expandSceneBgmNum(this,(uint)uRam8039c3e4);
                        }
                      }
                      else {
                        if (param_1 == 0x35) {
                          if ((param_4 - 8U < 3) || (param_4 == 0xb)) {
                            puVar5 = (undefined4 *)0x0;
                          }
                          else {
                            puVar5 = (undefined4 *)expandSceneBgmNum(this,(uint)uRam8039c3e0);
                          }
                        }
                        else {
                          if (param_1 == 0x36) {
                            if ((param_4 - 8U < 3) || (param_4 == 0xb)) {
                              puVar5 = (undefined4 *)0x0;
                            }
                            else {
                              puVar5 = (undefined4 *)expandSceneBgmNum(this,(uint)uRam8039c3e4);
                            }
                          }
                          else {
                            if (param_1 == 0x59) {
                              if ((param_4 - 8U < 3) || (param_4 == 0xb)) {
                                puVar5 = (undefined4 *)0x0;
                              }
                              else {
                                iVar4 = checkEventBit(this,0x2d04);
                                if (iVar4 == 0) {
                                  puVar5 = &DAT_80000034;
                                }
                                else {
                                  puVar5 = (undefined4 *)expandSceneBgmNum(this,(uint)uRam8039c470);
                                }
                              }
                            }
                            else {
                              if (param_1 == 0x27) {
                                if ((param_4 - 8U < 3) || (param_4 == 0xb)) {
                                  puVar5 = (undefined4 *)0x0;
                                }
                                else {
                                  puVar5 = (undefined4 *)expandSceneBgmNum(this,(uint)uRam8039c3a8);
                                }
                              }
                              else {
                                if (param_1 == 0x29) {
                                  if ((param_4 - 8U < 3) || (param_4 == 0xb)) {
                                    puVar5 = (undefined4 *)0x0;
                                  }
                                  else {
                                    puVar5 = (undefined4 *)
                                             expandSceneBgmNum(this,(uint)uRam8039c3b0);
                                  }
                                }
                                else {
                                  if (param_1 == 0x16) {
                                    if ((param_4 - 8U < 3) || (param_4 == 0xb)) {
                                      puVar5 = (undefined4 *)0x0;
                                    }
                                    else {
                                      puVar5 = (undefined4 *)
                                               expandSceneBgmNum(this,(uint)uRam8039c364);
                                    }
                                  }
                                  else {
                                    if (param_1 == 0x2c) {
                                      if ((param_4 - 8U < 3) || (param_4 == 0xb)) {
                                        puVar5 = (undefined4 *)0x0;
                                      }
                                      else {
                                        puVar5 = (undefined4 *)
                                                 expandSceneBgmNum(this,(uint)uRam8039c3bc);
                                      }
                                    }
                                    else {
                                      if (param_1 == 0xb) {
                                        if ((param_4 == 9) && (this->field_0x43 == 0)) {
                                          puVar5 = (undefined4 *)0x0;
                                        }
                                        else {
                                          if ((this->field_0x43 == 0) ||
                                             (iVar4 = checkEventBit(this,0x2a20), iVar4 != 0)) {
                                            puVar5 = (undefined4 *)
                                                     expandSceneBgmNum(this,(uint)uRam8039c338);
                                          }
                                          else {
                                            puVar5 = &DAT_80000044;
                                          }
                                        }
                                      }
                                      else {
                                        if (param_1 == 0x20) {
                                          iVar4 = checkEventBit(this,0x2110);
                                          if ((iVar4 == 0) &&
                                             (iVar4 = checkEventBit(this,0xa02), iVar4 == 1)) {
                                            puVar5 = (undefined4 *)0x8000003d;
                                          }
                                          else {
                                            puVar5 = (undefined4 *)
                                                     expandSceneBgmNum(this,(uint)uRam8039c38c);
                                          }
                                        }
                                        else {
                                          puVar5 = (undefined4 *)
                                                   expandSceneBgmNum(this,(uint)*(ushort *)
                                                                                 (&m_scene_info +
                                                                                 param_1 * 4));
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        bVar1 = (&DAT_8039c30e)[param_1 * 4];
        bVar2 = (&DAT_8039c30f)[param_1 * 4];
      }
      sceneChange(this,(ulong)puVar5,(uint)bVar1,(uint)bVar2,param_3);
      this->field_0x22d = 0;
      *(long *)&this->field_0x220 = param_1;
      *(undefined *)&this->field_0x22c = 1;
      *(char *)&this->field_0x239 = (char)param_4;
    }
  }
  else {
    m_Do_printf::OSReport("[JAIZelBasic::setScene] too large scene number\n");
  }
  return;
}


/* __thiscall JAIZelBasic::expandSceneBgmNum(unsigned long) */

uint __thiscall JAIZelBasic::expandSceneBgmNum(JAIZelBasic *this,ulong param_1)

{
  if ((param_1 & 0xf000) == 0x8000) {
    return param_1 & 0x7fff | 0xc0000000;
  }
  return param_1 & 0x7fff | 0x80000000;
}


/* __thiscall JAIZelBasic::checkLinkOnSea(void) */

undefined4 __thiscall JAIZelBasic::checkLinkOnSea(JAIZelBasic *this)

{
  if (this->field_0x224 == 0x12) {
    if (this->mIslandRoomNo == 0) {
      return 1;
    }
    if (this->mLinkSeaFloorGroupInfo != 0) {
      return 1;
    }
  }
  return 0;
}


/* __thiscall JAIZelBasic::checkLinkOnBoardSea(void) */

undefined4 __thiscall JAIZelBasic::checkLinkOnBoardSea(JAIZelBasic *this)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = checkLinkOnSea(this);
  if ((iVar1 == 1) && (this->field_0x47 != 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* __thiscall JAIZelBasic::setSceneName(char *,
                                        long,
                                        long) */

void __thiscall JAIZelBasic::setSceneName(JAIZelBasic *this,char *param_1,long param_2,long param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  m_Do_printf::OSReport("[JAIZelBasic::setSceneName] spot = %s, room = %d\n");
  iVar1 = spotNameToId(this,param_1);
  if (iVar1 == 0x75) {
    iVar2 = 0;
    iVar4 = 0;
    do {
      iVar3 = (int)&this->vtbl + iVar4;
      if (*(JAISound **)(iVar3 + 0xd4) != (JAISound *)0x0) {
        JAISound::stop(*(JAISound **)(iVar3 + 0xd4),1);
        *(undefined4 *)(iVar3 + 0xd4) = 0;
        *(undefined4 *)(iVar3 + 0x134) = 0;
        *(undefined4 *)(iVar3 + 0x194) = 0;
      }
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar2 < 0x18);
    menuOut(this);
    this->field_0x66 = 1;
    *(undefined *)&this->field_0xbf = 0;
  }
  else {
    this->field_0x66 = 0;
  }
  setScene(this,iVar1,param_2,0,param_3);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JAIZelBasic::spotNameToId(char *) */

int __thiscall JAIZelBasic::spotNameToId(JAIZelBasic *this,char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == (char *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    iVar3 = 0;
    do {
      iVar2 = MSL_C.PPCEABI.bare.H::strcmp(param_1,*(char **)((int)&spot_dir_name + iVar3));
      if (iVar2 == 0) break;
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar1 < 0x78);
    if (iVar1 == 0x78) {
      iVar1 = 0;
    }
    else {
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::sceneChange(unsigned long,
                                       unsigned long,
                                       unsigned long,
                                       long) */

void __thiscall
JAIZelBasic::sceneChange(JAIZelBasic *this,ulong param_1,ulong param_2,ulong param_3,long param_4)

{
  byte bVar1;
  int iVar2;
  undefined *puVar3;
  
  m_Do_printf::OSReport("[JAIZelBasic::sceneChange] bgm = 0x%08x, wave1 = %d, wave2 = %d (%d)\n");
  if (((this->field_0x224 == 0x12) && (*(char *)&this->field_0x33 != '\0')) &&
     (iVar2 = checkDayTime(this), iVar2 == 1)) {
    param_1 = 0;
  }
  if (param_1 == this->mNextSceneBgmId) {
    if ((param_1 == this->field_0x78) && (iVar2 = checkBgmPlaying(this), iVar2 != 0)) {
      this->field_0x22e = 0;
    }
    else {
      iVar2 = checkSeqIDDemoPlaying(this,param_1);
      if (iVar2 == 1) {
        this->field_0x22e = 0;
      }
      else {
        this->field_0x22e = 1;
      }
    }
  }
  else {
    if ((this->field_0x78 == 0x80000042) && (iVar2 = checkBgmPlaying(this), iVar2 == 1)) {
      if ((int)param_1 < -0x7ffffed0) {
        if (param_1 == 0x80000042) {
LAB_802aafc4:
          this->field_0x22e = 0;
          goto LAB_802ab080;
        }
      }
      else {
        if ((int)param_1 < -0x7ffffecc) goto LAB_802aafc4;
      }
      this->field_0x22e = 1;
    }
    else {
      if ((param_1 == this->field_0x78) && (iVar2 = checkBgmPlaying(this), iVar2 == 1)) {
        this->field_0x22e = 0;
      }
      else {
        iVar2 = checkSeqIDDemoPlaying(this,param_1);
        if (iVar2 == 1) {
          this->field_0x22e = 0;
        }
        else {
          this->field_0x22e = 1;
        }
      }
    }
  }
LAB_802ab080:
  this->mNextSceneBgmId = param_1;
  if (this->mpSound != (JAISound *)0x0) {
    JAISound::stop(this->mpSound,_BGM_SCENE_CHANGE_FO_TIME);
  }
  this->mpSound = (JAISound *)0x0;
  this->field_0x7c = 0xffffffff;
  if (this->field_0x22e == 0) goto LAB_802ab178;
  if (param_4 == 0) {
    puVar3 = (undefined *)this->field_0x74;
    if (puVar3 != &DAT_80000031) {
      if ((int)puVar3 < -0x7fffffcf) {
        if (-0x7fffffd1 < (int)puVar3) {
LAB_802ab0f0:
          if (*(int *)&this->field_0x6c == 0) {
            bgmStop(this,_BGM_SCENE_CHANGE_FO_TIME,0);
          }
          else {
            bgmStop(this,_BGM_SCENE_CHANGE_FO_TIME,1);
          }
          goto LAB_802ab134;
        }
      }
      else {
        if ((int)puVar3 < -0x7fffffcd) goto LAB_802ab0f0;
      }
    }
    bgmStop(this,_BGM_SCENE_CHANGE_FO_TIME,0);
  }
LAB_802ab134:
  bVar1 = (&m_bgm_wave_info)[param_1 & 0xff];
  if ((bVar1 == this->field_0x22f) || (bVar1 == 0)) {
    this->field_0x231 = 0;
  }
  else {
    this->field_0x231 = 1;
    this->field_0x230 = this->field_0x22f;
    this->field_0x22f = bVar1;
  }
LAB_802ab178:
  if ((param_2 == this->mFirstDynamicSceneWaveIndex) || (param_2 == 0)) {
    this->mSetNum = 0;
  }
  else {
    this->mSetNum = 1;
    this->field_0x233 = this->mFirstDynamicSceneWaveIndex;
    this->mFirstDynamicSceneWaveIndex = (byte)param_2;
  }
  if (((param_3 == this->mSecondDynamicSceneWaveIndex) || (param_3 == 0)) && (this->mSetNum == 0)) {
    this->field_0x237 = 0;
  }
  else {
    this->field_0x237 = 1;
    this->field_0x236 = this->mSecondDynamicSceneWaveIndex;
    this->mSecondDynamicSceneWaveIndex = (byte)param_3;
  }
  return;
}


/* __thiscall JAIZelBasic::sceneBgmStart(void) */

void __thiscall JAIZelBasic::sceneBgmStart(JAIZelBasic *this)

{
  bool bVar1;
  int iVar2;
  uint bgmId;
  
  m_Do_printf::OSReport("[JAIZelBasic::sceneBgmStart] %08x\n",this->mNextSceneBgmId);
  this->field_0x21 = 1;
  bVar1 = false;
  if ((this->field_0x224 == 0x12) && (iVar2 = checkDayTime(this), iVar2 == 0)) {
    this->field_0x22e = 0;
    bVar1 = true;
    m_Do_printf::OSReport("--- No BGM because of night time ---\n");
  }
  if (this->field_0x32 == 1) {
    return;
  }
  this->field_0xca = 0;
  this->field_0x22d = 1;
  *(undefined *)&this->field_0x205 = 0;
  if (this->field_0x22e == 0) {
    iVar2 = this->field_0x224;
    if (iVar2 != 0x19) {
      if (iVar2 < 0x19) {
        if (iVar2 != 10) {
          if (iVar2 < 10) {
            if (6 < iVar2) {
              return;
            }
            if (iVar2 < 5) {
              return;
            }
          }
          else {
            if (0x15 < iVar2) {
              return;
            }
            if (iVar2 < 0x14) {
              return;
            }
          }
        }
      }
      else {
        if (iVar2 != 0x38) {
          if (iVar2 < 0x38) {
            if (0x34 < iVar2) {
              return;
            }
            if (iVar2 < 0x2e) {
              return;
            }
          }
          else {
            if (0x6a < iVar2) {
              return;
            }
            if (iVar2 < 0x69) {
              return;
            }
          }
        }
      }
    }
  }
  bgmId = this->mNextSceneBgmId;
  if (((bgmId != 0) && (bgmId != 0x80000000)) && (!bVar1)) {
    bgmStart(this,bgmId,0,0);
  }
  *(undefined *)&this->field_0x33 = 0;
  this->field_0x22e = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JAIZelBasic::load1stDynamicWave(void) */

void __thiscall JAIZelBasic::load1stDynamicWave(JAIZelBasic *this)

{
  byte bVar1;
  int iVar2;
  undefined *puVar3;
  float fVar4;
  undefined *puVar5;
  uint uVar6;
  uint uVar7;
  
  m_Do_printf::OSReport
            ("[JAIZelBasic::load1stDynamicWave] (%d) set num = %d\n",this->mSetNum,
             this->mFirstDynamicSceneWaveIndex);
  this->field_0x224 = *(int *)&this->field_0x220;
  if (((this->field_0x231 != 0) || (this->mSetNum != 0)) || (this->field_0x237 != 0)) {
    iVar2 = (uint)this->field_0x236 * 2;
    uVar6 = (uint)(byte)(&m_dy_wave_set_2nd)[iVar2];
    uVar7 = (uint)(byte)(&DAT_8039c2e5)[iVar2];
    if (uVar7 != 0) {
      JASystem::WaveBankMgr::eraseWave(uVar7,0);
      JAInter::BankWave::setWsLoadStatus(uVar7,0);
      JAInter::BankWave::setWsGroupNumber(uVar7,-1);
    }
    if (uVar6 != 0) {
      JASystem::WaveBankMgr::eraseWave(uVar6,0);
      JAInter::BankWave::setWsLoadStatus(uVar6,0);
      JAInter::BankWave::setWsGroupNumber(uVar6,-1);
    }
  }
  if ((this->field_0x231 != 0) || (this->mSetNum != 0)) {
    iVar2 = (uint)this->field_0x233 * 2;
    uVar7 = (uint)(byte)(&m_dy_wave_set_1st)[iVar2];
    uVar6 = (uint)(byte)(&DAT_8039c281)[iVar2];
    if (uVar6 != 0) {
      JASystem::WaveBankMgr::eraseWave(uVar6,0);
      JAInter::BankWave::setWsLoadStatus(uVar6,0);
      JAInter::BankWave::setWsGroupNumber(uVar6,-1);
    }
    if (uVar7 != 0) {
      JASystem::WaveBankMgr::eraseWave(uVar7,0);
      JAInter::BankWave::setWsLoadStatus(uVar7,0);
      JAInter::BankWave::setWsGroupNumber(uVar7,-1);
    }
  }
  if ((this->field_0x231 != 0) && (this->field_0x230 != 0)) {
    JASystem::WaveBankMgr::eraseWave((uint)this->field_0x230,0);
    JAInter::BankWave::setWsLoadStatus((uint)this->field_0x230,0);
    JAInter::BankWave::setWsGroupNumber((uint)this->field_0x230,-1);
  }
  if ((this->field_0x231 != 0) && (this->field_0x22f != 0)) {
    JAInter::BankWave::loadSceneWave((uint)this->field_0x22f,0);
  }
  if (this->mSetNum != 0) {
    iVar2 = (uint)this->mFirstDynamicSceneWaveIndex * 2;
    bVar1 = (&DAT_8039c281)[iVar2];
    if ((byte)(&m_dy_wave_set_1st)[iVar2] != 0) {
      JAInter::BankWave::loadSceneWave((uint)(byte)(&m_dy_wave_set_1st)[iVar2],0);
    }
    if (bVar1 != 0) {
      JAInter::BankWave::loadSceneWave((uint)bVar1,0);
    }
  }
  *(undefined *)&this->field_0x22c = 0;
  *(undefined *)&this->field_0x1f3c = 0;
  fVar4 = JAZelAudio::1_0;
  this->field_0x80 = JAZelAudio::1_0;
  this->field_0x84 = fVar4;
  this->field_0x88 = fVar4;
  puVar5 = (undefined *)this->field_0x74;
  if (puVar5 != &DAT_80000030) {
    if ((int)puVar5 < -0x7fffffd0) {
      puVar3 = &DAT_8000001c;
    }
    else {
      puVar3 = &DAT_80000032;
    }
    if (puVar5 != puVar3) {
      this->field_0x8c = JAZelAudio::1_0;
    }
  }
  if (this->field_0x78 != 0x80000039) {
    this->field_0x90 = JAZelAudio::1_0;
  }
  fVar4 = JAZelAudio::1_0;
  this->field_0x94 = JAZelAudio::1_0;
  this->field_0x98 = fVar4;
  this->field_0x9c = fVar4;
  this->field_0xac = fVar4;
  this->field_0xa0 = fVar4;
  this->field_0xa4 = fVar4;
  this->field_0xa8 = fVar4;
  if ((*(int *)&this->field_0x68 == 0) || ((undefined *)this->field_0x78 != &DAT_8000001d)) {
    this->field_0x32 = 0;
  }
  *(undefined *)&this->field_0xb9 = 0;
  this->field_0x21e = 1;
  this->field_0x22d = 0;
  *(undefined *)&this->field_0x1dd4 = 0;
  this->mbLandingDemoStarted = 0;
  *(undefined *)&this->field_0x208 = 0;
  *(undefined4 *)&this->field_0xd0 = 0;
  *(undefined *)&this->field_0x204 = 0;
  this->field_0xbe = 0;
  *(undefined4 *)&this->field_0x28 = 0;
  *(undefined *)&this->field_0x62 = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JAIZelBasic::check1stDynamicWave(void) */

int __thiscall JAIZelBasic::check1stDynamicWave(JAIZelBasic *this)

{
  byte bVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  
  iVar5 = 0;
  iVar4 = 0;
  iVar2 = (uint)this->mFirstDynamicSceneWaveIndex * 2;
  puVar3 = &m_dy_wave_set_1st + iVar2;
  bVar1 = (&DAT_8039c281)[iVar2];
  if ((BankWave *)(uint)(byte)(&m_dy_wave_set_1st)[iVar2] != (BankWave *)0x0) {
    uVar6 = JAInter::BankWave::getWaveLoadStatus
                      ((BankWave *)(uint)(byte)(&m_dy_wave_set_1st)[iVar2],(long)puVar3);
    puVar3 = (undefined1 *)uVar6;
    iVar5 = 2 - (int)((ulonglong)uVar6 >> 0x20);
  }
  if ((BankWave *)(uint)bVar1 != (BankWave *)0x0) {
    iVar4 = JAInter::BankWave::getWaveLoadStatus((BankWave *)(uint)bVar1,(long)puVar3);
    iVar4 = 2 - iVar4;
  }
  return iVar5 * 0x100 + iVar4;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JAIZelBasic::load2ndDynamicWave(void) */

void __thiscall JAIZelBasic::load2ndDynamicWave(JAIZelBasic *this)

{
  byte bVar1;
  int iVar2;
  ulong uVar3;
  
  m_Do_printf::OSReport
            ("[JAIZelBasic::load2ndDynamicWave] (%d) set num = %d\n",this->field_0x237,
             this->mSecondDynamicSceneWaveIndex);
  uVar3 = 0;
  iVar2 = this->field_0x224;
  if (iVar2 == 0x18) {
    if (*(char *)&this->field_0xcd == '\0') {
      uVar3 = 0xc000000f;
    }
  }
  else {
    if (iVar2 < 0x18) {
      if (iVar2 == 7) {
        if (*(char *)&this->field_0xcd == '\0') {
          uVar3 = 0xc0000007;
        }
      }
      else {
        if (((iVar2 < 7) && (iVar2 == 2)) && (*(char *)&this->field_0xcd == '\0')) {
          uVar3 = 0xc0000002;
        }
      }
    }
    else {
      if (iVar2 == 0x2d) {
        if (*(char *)&this->field_0xcd == '\0') {
          uVar3 = 0xc0000034;
        }
      }
      else {
        if (((iVar2 < 0x2d) && (iVar2 == 0x25)) && (*(char *)&this->field_0xcd == '\0')) {
          uVar3 = 0xc0000009;
        }
      }
    }
  }
  if (this->field_0x237 != 0) {
    iVar2 = (uint)this->mSecondDynamicSceneWaveIndex * 2;
    bVar1 = (&DAT_8039c2e5)[iVar2];
    if ((byte)(&m_dy_wave_set_2nd)[iVar2] != 0) {
      JAInter::BankWave::loadSceneWave((uint)(byte)(&m_dy_wave_set_2nd)[iVar2],0);
    }
    if (bVar1 != 0) {
      JAInter::BankWave::loadSceneWave((uint)bVar1,0);
    }
  }
  if (uVar3 != 0) {
    bgmStreamPrepare(this,uVar3);
  }
  return;
}


/* __thiscall JAIZelBasic::loadStaticWaves(void) */

void __thiscall JAIZelBasic::loadStaticWaves(JAIZelBasic *this)

{
  m_Do_printf::OSReport
            (
            "[JAIZelBasic::loadStaticWaves] 常駐シーン波形はここでなく、gFrameProcessの一番最初で読み込まれます。\n"
            );
  return;
}


/* __thiscall JAIZelBasic::checkFirstWaves(void) */

int __thiscall JAIZelBasic::checkFirstWaves(JAIZelBasic *this)

{
  int iVar1;
  long in_r4;
  
  iVar1 = JAInter::BankWave::getWaveLoadStatus((BankWave *)&DAT_00000002,in_r4);
  return 2 - iVar1;
}


/* __thiscall JAIZelBasic::setLinkHp(long,
                                     long) */

void __thiscall JAIZelBasic::setLinkHp(JAIZelBasic *this,long param_1,long param_2)

{
  JAISound *this_00;
  undefined1 *puVar1;
  
  this->field_0x34 = param_1;
  this->field_0x38 = param_2;
  if (param_2 == 0) {
    this->field_0x3c = JAZelAudio::1_0;
  }
  else {
    this->field_0x3c =
         (float)((double)CONCAT44(0x43300000,param_1 ^ 0x80000000) - JAZelAudio::_7417) /
         (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - JAZelAudio::_7417);
  }
  if (JAZelAudio::1_0 < this->field_0x3c) {
    this->field_0x3c = JAZelAudio::1_0;
  }
  this_00 = *(JAISound **)&this->field_0x6c;
  if (this_00 != (JAISound *)0x0) {
    puVar1 = (undefined1 *)this->field_0x74;
    if (puVar1 != (undefined1 *)0x8000001b) {
      if ((int)puVar1 < -0x7fffffe5) {
        if (puVar1 == &DAT_80000004) {
          JAISound::setTempoProportion
                    (this_00,JAZelAudio::1_0 +
                             JAZelAudio::_7413 * (JAZelAudio::1_0 - this->field_0x3c),0);
        }
        else {
          if ((-0x7ffffffd < (int)puVar1) && (-0x7fffffe8 < (int)puVar1)) {
            JAISound::setTempoProportion
                      (this_00,JAZelAudio::1_0 +
                               JAZelAudio::_7414 * (JAZelAudio::1_0 - this->field_0x3c),0);
          }
        }
      }
      else {
        if ((int)puVar1 < -0x7fffffe3) {
          JAISound::setTempoProportion
                    (this_00,JAZelAudio::1_0 +
                             JAZelAudio::_7415 * (JAZelAudio::1_0 - this->field_0x3c),0);
        }
      }
    }
  }
  return;
}


/* __thiscall JAIZelBasic::setLinkSwordType(long,
                                            long) */

void __thiscall JAIZelBasic::setLinkSwordType(JAIZelBasic *this,long param_1,long param_2)

{
  this->field_0x41 = (byte)param_1;
  this->field_0x42 = (byte)param_2;
  if ((((this->field_0x41 != 0) && (this->field_0x42 == 2)) && (this->field_0x43 != 0)) &&
     (this->field_0x44 == 2)) {
    this->field_0x45 = 1;
    return;
  }
  this->field_0x45 = 0;
  return;
}


/* __thiscall JAIZelBasic::setLinkShieldType(long,
                                             long) */

void __thiscall JAIZelBasic::setLinkShieldType(JAIZelBasic *this,long param_1,long param_2)

{
  this->field_0x43 = (byte)param_1;
  this->field_0x44 = (byte)param_2;
  if ((((this->field_0x41 != 0) && (this->field_0x42 == 2)) && (this->field_0x43 != 0)) &&
     (this->field_0x44 == 2)) {
    this->field_0x45 = 1;
    return;
  }
  this->field_0x45 = 0;
  return;
}


/* __thiscall JAIZelBasic::setLinkBootsType(long) */

void __thiscall JAIZelBasic::setLinkBootsType(JAIZelBasic *this,long param_1)

{
  this->field_0x46 = (byte)param_1;
  return;
}


/* __thiscall JAIZelBasic::setLinkOnBoard(long) */

void __thiscall JAIZelBasic::setLinkOnBoard(JAIZelBasic *this,long param_1)

{
  this->field_0x47 = (byte)param_1;
  if ((*(int *)&this->field_0x6c != 0) && ((undefined *)this->field_0x74 == &DAT_8000001c)) {
    if (this->field_0x47 == 1) {
      bgmMute(this,(JAISound **)&this->field_0x6c,(ulong)&DAT_8000001c,0,10);
    }
    else {
      bgmMute(this,(JAISound **)&this->field_0x6c,(ulong)&DAT_8000001c,1,10);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JAIZelBasic::bgmMute(JAISound * *,
                                   unsigned long,
                                   long,
                                   unsigned long) */

void __thiscall
JAIZelBasic::bgmMute(JAIZelBasic *this,JAISound **param_1,ulong param_2,long param_3,ulong param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(&m_bgm_mute_state + param_3 * 4 + (param_2 & 0xff) * 0x10);
  if (*param_1 == (JAISound *)0x0) {
    m_Do_printf::OSReport("Warning : bgm pointer is NULL!\n");
  }
  else {
    iVar1 = 0;
    do {
      if ((uVar2 & 1) == 0) {
        JAISound::setTrackVolume(*param_1,(uchar)iVar1,JAZelAudio::_4004,param_4);
      }
      else {
        JAISound::setTrackVolume(*param_1,(uchar)iVar1,JAZelAudio::1_0,param_4);
      }
      uVar2 = uVar2 >> 1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x10);
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::checkStreamPlaying(unsigned long) */

uint __thiscall JAIZelBasic::checkStreamPlaying(JAIZelBasic *this,ulong param_1)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = *(int *)(_streamUpdate + 0x14);
  if (iVar3 == 0) {
    uVar1 = 0;
  }
  else {
    cVar2 = JAInter::StreamLib::getPlayingFlag(_streamUpdate);
    if (cVar2 == '\0') {
      uVar1 = 0;
    }
    else {
      uVar1 = countLeadingZeros(*(int *)(iVar3 + 0xc) - param_1);
      uVar1 = uVar1 >> 5;
    }
  }
  return uVar1;
}


/* __thiscall JAIZelBasic::stWaterLevelUp(void) */

void __thiscall JAIZelBasic::stWaterLevelUp(JAIZelBasic *this)

{
  if ((*(char *)&this->field_0xb7 == '\0') && ((undefined4 *)this->field_0x78 == &DAT_80000028)) {
    bgmStart(this,(uint)&DAT_80000125,1,0);
  }
  return;
}


/* __thiscall JAIZelBasic::stWaterLevelDown(void) */

void __thiscall JAIZelBasic::stWaterLevelDown(JAIZelBasic *this)

{
  if ((*(char *)&this->field_0xb7 == '\0') && ((undefined4 *)this->field_0x78 == &DAT_80000028)) {
    bgmStart(this,(uint)&DAT_80000028,1,0);
  }
  return;
}


/* __thiscall JAIZelBasic::stSkyCloisters(void) */

void __thiscall JAIZelBasic::stSkyCloisters(JAIZelBasic *this)

{
  if ((undefined4 *)this->field_0x78 == &DAT_80000028) {
    if (*(char *)&this->field_0xb7 == '\0') {
      bgmStart(this,(uint)&DAT_80000126,1,0);
    }
    *(undefined *)&this->field_0xb7 = 4;
  }
  return;
}


/* __thiscall JAIZelBasic::stSkyCloistersProcess(void) */

void __thiscall JAIZelBasic::stSkyCloistersProcess(JAIZelBasic *this)

{
  byte bVar1;
  
  bVar1 = *(byte *)&this->field_0xb7;
  if (bVar1 != 0) {
    if (1 < bVar1) {
      *(byte *)&this->field_0xb7 = bVar1 - 1;
    }
    if (*(char *)&this->field_0xb7 == '\x01') {
      if ((undefined4 *)this->field_0x78 == &DAT_80000028) {
        bgmStart(this,(uint)&DAT_80000028,1,0);
      }
      *(undefined *)&this->field_0xb7 = 0;
    }
    seStart(this,0x105a,(cXyz *)0x0,0,0,JAZelAudio::1_0,JAZelAudio::1_0,JAZelAudio::_4357,
            JAZelAudio::_4357,0);
  }
  return;
}


/* __thiscall JAIZelBasic::getRandomU32(unsigned long) */

int __thiscall JAIZelBasic::getRandomU32(JAIZelBasic *this,ulong param_1)

{
  JAZelAudio::jai_rnd_seed =
       JAZelAudio::jai_rnd_seed * 2 +
       (JAZelAudio::jai_rnd_seed >> 0x1f ^ JAZelAudio::jai_rnd_seed >> 6 & 0x10);
  return JAZelAudio::jai_rnd_seed - (JAZelAudio::jai_rnd_seed / param_1) * param_1;
}


/* __thiscall JAIZelBasic::setEventBit(void *) */

void __thiscall JAIZelBasic::setEventBit(JAIZelBasic *this,void *param_1)

{
  this->field_0x24 = (int)param_1;
  return;
}


/* __thiscall JAIZelBasic::checkEventBit(unsigned short) */

bool __thiscall JAIZelBasic::checkEventBit(JAIZelBasic *this,ushort param_1)

{
  if (this->field_0x24 == 0) {
    return false;
  }
  return (param_1 & 0xff & (ushort)*(byte *)(this->field_0x24 + ((int)(param_1 & 0xff00) >> 8))) !=
         0;
}


/* __thiscall JAIZelBasic::checkDayTime(void) */

undefined4 __thiscall JAIZelBasic::checkDayTime(JAIZelBasic *this)

{
  if ((5 < this->field_0x2c) && (this->field_0x2c < 0x14)) {
    return 1;
  }
  return 0;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::processTime(void) */

void __thiscall JAIZelBasic::processTime(JAIZelBasic *this)

{
  ushort uVar1;
  
  uVar1 = (ushort)this->field_0x2c * 0x100 + (ushort)this->field_0x2d;
  if ((this->field_0x224 == 0x12) && (this->field_0x22d == 1)) {
    if (((ushort)this->field_0x30 < 0x1400) && (0x13ff < uVar1)) {
      mainBgmStopOnly(this,_JAI_ZEL_NIGHT_FADEOUT_TIME);
    }
    else {
      if (((ushort)this->field_0x30 < 0x53b) && (0x53a < uVar1)) {
        bgmStart(this,(uint)&DAT_8000001d,0,0);
        this->field_0x32 = 1;
      }
    }
  }
  this->field_0x30 = uVar1;
  processMorningToNormal(this);
  return;
}


/* __thiscall JAIZelBasic::processMorningToNormal(void) */

void __thiscall JAIZelBasic::processMorningToNormal(JAIZelBasic *this)

{
  int iVar1;
  float afStack24 [5];
  
  if ((undefined *)this->field_0x78 == &DAT_8000001d) {
    if (*(int *)&this->field_0x68 == 0) {
      this->field_0x94 = JAZelAudio::1_0;
      iVar1 = checkOnOuterSea(this,afStack24);
      if (iVar1 < 2) {
        startIsleBgm(this);
      }
      else {
        bgmStart(this,(uint)&DAT_8000002e,0,1);
      }
      this->field_0x32 = 0;
    }
  }
  else {
    this->field_0x32 = 0;
  }
  return;
}


/* __thiscall JAIZelBasic::checkOnOuterSea(float *) */

undefined4 __thiscall JAIZelBasic::checkOnOuterSea(JAIZelBasic *this,float *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  undefined4 uVar5;
  uint uVar6;
  double dVar7;
  double dVar8;
  
  if (param_1 == (float *)0x0) {
    uVar5 = 0xffffffff;
  }
  else {
    dVar8 = (double)JAZelAudio::_4004;
    *param_1 = JAZelAudio::_4004;
    if (this->field_0x224 == 0x12) {
      uVar6 = (uint)this->mIslandRoomNo;
      if (uVar6 == 0) {
        uVar5 = 4;
      }
      else {
        iVar3 = uVar6 * 0x10;
        fVar4 = *(float *)(&DAT_8039c7a4 + iVar3);
        if (*(float *)(&mIsleArea + iVar3) <= JAZelAudio::_7608) {
          fVar1 = *(float *)(&mIsleArea + iVar3) -
                  (***(float ***)&this->field_0x4 -
                  JAZelAudio::_7609 *
                  (float)((double)CONCAT44(0x43300000,(int)(uVar6 - 1) % 7 - 3U ^ 0x80000000) -
                         JAZelAudio::_7417));
          fVar2 = *(float *)(&DAT_8039c7a0 + iVar3) -
                  ((**(float ***)&this->field_0x4)[2] -
                  JAZelAudio::_7609 *
                  (float)((double)CONCAT44(0x43300000,(int)(uVar6 - 1) / 7 - 3U ^ 0x80000000) -
                         JAZelAudio::_7417));
          *param_1 = fVar1 * fVar1 + fVar2 * fVar2;
          dVar7 = (double)*param_1;
          if (dVar8 < dVar7) {
            dVar8 = 1.0 / SQRT(dVar7);
            dVar8 = JAZelAudio::_4349 * dVar8 * (JAZelAudio::_4350 - dVar7 * dVar8 * dVar8);
            dVar8 = JAZelAudio::_4349 * dVar8 * (JAZelAudio::_4350 - dVar7 * dVar8 * dVar8);
            dVar7 = (double)(float)(dVar7 * JAZelAudio::_4349 * dVar8 *
                                            (JAZelAudio::_4350 - dVar7 * dVar8 * dVar8));
          }
          *param_1 = (float)dVar7;
          fVar1 = *param_1;
          if (fVar4 < fVar1) {
            if (JAZelAudio::_4356 + fVar4 < fVar1) {
              if (JAZelAudio::_4343 + fVar4 < fVar1) {
                if (JAZelAudio::_7610 + fVar4 < fVar1) {
                  uVar5 = 4;
                }
                else {
                  uVar5 = 3;
                }
              }
              else {
                uVar5 = 2;
              }
            }
            else {
              uVar5 = 1;
            }
          }
          else {
            uVar5 = 0;
          }
        }
        else {
          uVar5 = 4;
        }
      }
    }
    else {
      uVar5 = 0xffffffff;
    }
  }
  return uVar5;
}


/* __thiscall JAIZelBasic::makeSound(unsigned long) */

void __thiscall JAIZelBasic::makeSound(JAIZelBasic *this,ulong param_1)

{
  undefined4 uVar1;
  
  if (*(int *)&this->field_0x8 == 0) {
    uVar1 = JKernel::operator_new__(param_1 * 0x44 + 0x10,JAudio::JASDram,0);
    Runtime.PPCEABI.H::__construct_new_array
              (uVar1,JAIZelSound::JAIZelSound,JAIZelSound::_JAIZelSound,0x44,param_1);
  }
  else {
    uVar1 = JKernel::operator_new__(param_1 * 0x44 + 0x10,*(int *)&this->field_0x8,0);
    Runtime.PPCEABI.H::__construct_new_array
              (uVar1,JAIZelSound::JAIZelSound,JAIZelSound::_JAIZelSound,0x44,param_1);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JAIZelBasic::checkSeqIDDemoPlaying(unsigned long) */

undefined4 __thiscall JAIZelBasic::checkSeqIDDemoPlaying(JAIZelBasic *this,ulong param_1)

{
  JAIZelBasic *this_00;
  SequenceMgr *this_01;
  undefined8 uVar1;
  
  this_01 = (SequenceMgr *)0x0;
  this_00 = this;
  while( true ) {
    uVar1 = JAIGlobalParameter::getParamSeqPlayTrackMax((JAIGlobalParameter *)this_00);
    if ((SequenceMgr *)((ulonglong)uVar1 >> 0x20) <= this_01) {
      return 0;
    }
    this_00 = (JAIZelBasic *)JAInter::SequenceMgr::getPlayTrackInfo(this_01,(ulong)uVar1);
    if ((((this_00 != (JAIZelBasic *)0x0) &&
         (this_00 = (JAIZelBasic *)this_00->field_0x48, this_00 != (JAIZelBasic *)0x0)) &&
        (this_00 != *(JAIZelBasic **)&this->field_0x68)) &&
       (((this_00 != *(JAIZelBasic **)&this->field_0x6c &&
         (this_00 = *(JAIZelBasic **)&this_00->field_0xc, this_00 != (JAIZelBasic *)&DAT_80000800))
        && ((JAIZelBasic *)param_1 == this_00)))) break;
    this_01 = this_01 + 1;
  }
  return 1;
}


/* __thiscall JAIZelBasic::checkDemoFanfarePlaying(void) */

undefined1 * __thiscall JAIZelBasic::checkDemoFanfarePlaying(JAIZelBasic *this)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = checkSeqIDDemoPlaying(this,(ulong)&DAT_80000002);
  if (iVar1 == 1) {
    puVar2 = &DAT_80000002;
  }
  else {
    iVar1 = checkSeqIDDemoPlaying(this,(ulong)&DAT_80000025);
    if (iVar1 == 1) {
      puVar2 = &DAT_80000025;
    }
    else {
      iVar1 = checkSeqIDDemoPlaying(this,(ulong)&DAT_80000027);
      if (iVar1 == 1) {
        puVar2 = &DAT_80000027;
      }
      else {
        iVar1 = checkSeqIDDemoPlaying(this,(ulong)&DAT_80000024);
        if (iVar1 == 1) {
          puVar2 = &DAT_80000024;
        }
        else {
          iVar1 = checkSeqIDDemoPlaying(this,(ulong)&DAT_8000004f);
          if (iVar1 == 1) {
            puVar2 = &DAT_8000004f;
          }
          else {
            iVar1 = checkSeqIDDemoPlaying(this,(ulong)&DAT_8000005d);
            puVar2 = (undefined1 *)(-(uint)(iVar1 == 1) & 0x8000005d);
          }
        }
      }
    }
  }
  return puVar2;
}


/* __thiscall JAIZelBasic::processDemoFanfareMute(void) */

void __thiscall JAIZelBasic::processDemoFanfareMute(JAIZelBasic *this)

{
  int iVar1;
  
  iVar1 = checkDemoFanfarePlaying(this);
  if (iVar1 == 0) {
    if (*(char *)&this->field_0xb9 != '\0') {
      unmuteMainBgmAll(this);
    }
  }
  else {
    if (*(char *)&this->field_0xb9 == '\0') {
      muteMainBgmAll(this);
    }
    *(undefined *)&this->field_0xb9 = 1;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::muteMainBgmAll(void) */

void __thiscall JAIZelBasic::muteMainBgmAll(JAIZelBasic *this)

{
  JAIZelBasic *this_00;
  SequenceMgr *this_01;
  undefined8 uVar1;
  
  this->field_0x8c = JAZelAudio::_4004;
  this_00 = this;
  for (this_01 = (SequenceMgr *)0x0;
      uVar1 = JAIGlobalParameter::getParamSeqPlayTrackMax((JAIGlobalParameter *)this_00),
      this_01 < (SequenceMgr *)((ulonglong)uVar1 >> 0x20); this_01 = this_01 + 1) {
    this_00 = (JAIZelBasic *)JAInter::SequenceMgr::getPlayTrackInfo(this_01,(ulong)uVar1);
    if (((this_00 != (JAIZelBasic *)0x0) &&
        (this_00 = (JAIZelBasic *)this_00->field_0x48, this_00 != (JAIZelBasic *)0x0)) &&
       (*(char *)&this_00->field_0x4 == '\0')) {
      this_00 = (JAIZelBasic *)
                JAISound::setVolume((JAISound *)this_00,
                                    this->field_0xac *
                                    this->field_0x9c *
                                    this->field_0x98 *
                                    this->field_0x94 *
                                    this->field_0x90 *
                                    this->field_0x8c *
                                    this->field_0x88 * this->field_0x80 * this->field_0x84,1,0);
    }
  }
  if (*(JAISound **)(_streamUpdate + 0x14) != (JAISound *)0x0) {
    JAISound::setVolume(*(JAISound **)(_streamUpdate + 0x14),
                        this->field_0xac *
                        this->field_0x9c *
                        this->field_0x98 *
                        this->field_0x94 *
                        this->field_0x90 *
                        this->field_0x8c * this->field_0x88 * this->field_0x80 * this->field_0x84,1,
                        0);
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIZelBasic::unmuteMainBgmAll(void) */

void __thiscall JAIZelBasic::unmuteMainBgmAll(JAIZelBasic *this)

{
  JAIZelBasic *this_00;
  SequenceMgr *this_01;
  undefined8 uVar1;
  
  this->field_0x8c = JAZelAudio::1_0;
  this_00 = this;
  for (this_01 = (SequenceMgr *)0x0;
      uVar1 = JAIGlobalParameter::getParamSeqPlayTrackMax((JAIGlobalParameter *)this_00),
      this_01 < (SequenceMgr *)((ulonglong)uVar1 >> 0x20); this_01 = this_01 + 1) {
    this_00 = (JAIZelBasic *)JAInter::SequenceMgr::getPlayTrackInfo(this_01,(ulong)uVar1);
    if (((this_00 != (JAIZelBasic *)0x0) &&
        (this_00 = (JAIZelBasic *)this_00->field_0x48, this_00 != (JAIZelBasic *)0x0)) &&
       (*(char *)&this_00->field_0x4 == '\0')) {
      this_00 = (JAIZelBasic *)
                JAISound::setVolume((JAISound *)this_00,
                                    this->field_0xac *
                                    this->field_0x9c *
                                    this->field_0x98 *
                                    this->field_0x94 *
                                    this->field_0x90 *
                                    this->field_0x8c *
                                    this->field_0x88 * this->field_0x80 * this->field_0x84,0x2d,0);
    }
  }
  if (*(JAISound **)(_streamUpdate + 0x14) != (JAISound *)0x0) {
    JAISound::setVolume(*(JAISound **)(_streamUpdate + 0x14),
                        this->field_0xac *
                        this->field_0x9c *
                        this->field_0x98 *
                        this->field_0x94 *
                        this->field_0x90 *
                        this->field_0x8c * this->field_0x88 * this->field_0x80 * this->field_0x84,
                        0x2d,0);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JAIZelBasic::demoBgmStop(unsigned long) */

void __thiscall JAIZelBasic::demoBgmStop(JAIZelBasic *this,ulong param_1)

{
  JAIZelBasic *this_00;
  SequenceMgr *this_01;
  undefined8 uVar1;
  
  this_00 = this;
  for (this_01 = (SequenceMgr *)0x0;
      uVar1 = JAIGlobalParameter::getParamSeqPlayTrackMax((JAIGlobalParameter *)this_00),
      this_01 < (SequenceMgr *)((ulonglong)uVar1 >> 0x20); this_01 = this_01 + 1) {
    this_00 = (JAIZelBasic *)JAInter::SequenceMgr::getPlayTrackInfo(this_01,(ulong)uVar1);
    if ((((this_00 != (JAIZelBasic *)0x0) &&
         (this_00 = (JAIZelBasic *)this_00->field_0x48, this_00 != (JAIZelBasic *)0x0)) &&
        (this_00 != *(JAIZelBasic **)&this->field_0x68)) &&
       ((this_00 != *(JAIZelBasic **)&this->field_0x6c && (*(char *)&this_00->field_0x4 == '\0'))))
    {
      this_00 = (JAIZelBasic *)JAISound::stop((JAISound *)this_00,param_1);
    }
  }
  return;
}


/* __thiscall JAIZelBasic::isDemo(void) */

undefined4 __thiscall JAIZelBasic::isDemo(JAIZelBasic *this)

{
  if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr != (dDemo_manager_c *)0x0) &&
     ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->mState != 0)) {
    return 1;
  }
  return 0;
}


/* __thiscall JAIZelBasic::checkSeaBgmID(void) */

undefined4 * __thiscall JAIZelBasic::checkSeaBgmID(JAIZelBasic *this)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = checkEventBit(this,0xa02);
  if ((iVar1 == 1) && (iVar1 = checkEventBit(this,0x3920), iVar1 == 0)) {
    puVar2 = &DAT_8000003c;
  }
  else {
    puVar2 = (undefined4 *)&DAT_8000002e;
  }
  return puVar2;
}


/* __thiscall JAIZelSound::~JAIZelSound(void) */

void __thiscall JAIZelSound::_JAIZelSound(JAIZelSound *this)

{
  short in_r4;
  
  if ((this != (JAIZelSound *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

