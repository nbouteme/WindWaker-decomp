#include <JAudio/JAISound.h>
#include <JAudio/JAISeMgr.h>
#include <JAudio/JAISound.h>
#include <JAudio/JAIBasic.h>
#include <m_Do_printf.h>
#include <JUtility/JUTAssert.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JAudio/JASTrack.h>
#include <JAudio/JAIStreamMgr.h>
#include <JAudio/JAIGlobalParameter.h>
#include <JKernel/JKRHeap.h>
#include <Demangler/JAInter/MoveParaSet.h>
#include <JAInter/LinkSound.h>
#include <JAISound.h>


/* __thiscall JAISound::JAISound(void) */

void __thiscall JAISound::JAISound(JAISound *this)

{
  *(undefined ***)this = &__vt;
  this[1].field_0x1c = 0;
  *(undefined *)&this->field_0x5 = 0;
  *(undefined *)&this->field_0x6 = 10;
  *(undefined4 *)&this[1].field_0x4 = 0;
  return;
}


/* __thiscall JAISound::getSeCategoryNumber(void) */

void __thiscall JAISound::getSeCategoryNumber(JAISound *this)

{
  ulong in_r4;
  
  JAInter::SeMgr::changeIDToCategory((SeMgr *)this->field_0xc,in_r4);
  return;
}


/* __thiscall JAISound::getSwBit(void) */

undefined4 __thiscall JAISound::getSwBit(JAISound *this)

{
  return **(undefined4 **)(this + 2);
}


/* __thiscall JAISound::checkSwBit(unsigned long) */

uint __thiscall JAISound::checkSwBit(JAISound *this,ulong param_1)

{
  uint uVar1;
  
  uVar1 = getSwBit(this);
  return param_1 & uVar1;
}


/* __thiscall JAISound::getInfoPriority(void) */

undefined __thiscall JAISound::getInfoPriority(JAISound *this)

{
  return *(undefined *)(*(int *)(this + 2) + 4);
}


/* __thiscall JAISound::clearMainSoundPPointer(void) */

void __thiscall JAISound::clearMainSoundPPointer(JAISound *this)

{
  if ((undefined4 *)this[1].field_0x18 == (undefined4 *)0x0) {
    return;
  }
  *(undefined4 *)this[1].field_0x18 = 0;
  return;
}


/* __thiscall JAISound::start(unsigned long) */

void __thiscall JAISound::start(JAISound *this,ulong param_1)

{
  setPrepareFlag(this,'\0');
  *(ulong *)&this->field_0x14 = param_1;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAISound::stop(unsigned long) */

void __thiscall JAISound::stop(JAISound *this,ulong param_1)

{
  JAIBasic::stopSoundHandle(_msBasic,this,param_1);
  return;
}


/* __thiscall JAISound::setVolume(float,
                                  unsigned long,
                                  unsigned char) */

void __thiscall JAISound::setVolume(JAISound *this,float param_1,ulong param_2,byte param_3)

{
  uint uVar1;
  
  uVar1 = this->field_0xc & 0xc0000000;
  if (uVar1 == 0xc0000000) {
    setStreamInterVolume(this,param_3,param_1,param_2);
  }
  else {
    if ((int)uVar1 < -0x40000000) {
      if ((int)uVar1 < -0x7fffffff) {
        setSeqInterVolume(this,param_3,param_1,param_2);
        return;
      }
    }
    else {
      if (uVar1 == 0) {
        setSeInterVolume(this,param_3,param_1,param_2,'\0');
        return;
      }
    }
    m_Do_printf::OSReport
              ("JAISound::setVolume サウンドカテゴリービットが異常です。\n");
    JUTAssertion::showAssert(3,"JAISound.cpp",0xb1,"0");
    m_Do_printf::OSPanic("JAISound.cpp",0xb1,"Halt");
  }
  return;
}


/* __thiscall JAISound::setPan(float,
                               unsigned long,
                               unsigned char) */

void __thiscall JAISound::setPan(JAISound *this,float param_1,ulong param_2,uchar param_3)

{
  uint uVar1;
  
  uVar1 = this->field_0xc & 0xc0000000;
  if (uVar1 == 0xc0000000) {
    setStreamInterPan(this,param_3,param_1,param_2);
  }
  else {
    if ((int)uVar1 < -0x40000000) {
      if ((int)uVar1 < -0x7fffffff) {
        setSeqInterPan(this,param_3,param_1,param_2);
        return;
      }
    }
    else {
      if (uVar1 == 0) {
        setSeInterPan(this,param_3,param_1,param_2,'\0');
        return;
      }
    }
    m_Do_printf::OSReport
              ("JAISound::setPan サウンドカテゴリービットが異常です。\n");
    JUTAssertion::showAssert(3,"JAISound.cpp",0xd9,"0");
    m_Do_printf::OSPanic("JAISound.cpp",0xd9,"Halt");
  }
  return;
}


/* __thiscall JAISound::setPitch(float,
                                 unsigned long,
                                 unsigned char) */

void __thiscall JAISound::setPitch(JAISound *this,float param_1,ulong param_2,uchar param_3)

{
  uint uVar1;
  
  uVar1 = this->field_0xc & 0xc0000000;
  if (uVar1 == 0xc0000000) {
    setStreamInterPitch(this,param_3,param_1,param_2);
  }
  else {
    if ((int)uVar1 < -0x40000000) {
      if ((int)uVar1 < -0x7fffffff) {
        setSeqInterPitch(this,param_3,param_1,param_2);
        return;
      }
    }
    else {
      if (uVar1 == 0) {
        setSeInterPitch(this,param_3,param_1,param_2,JAudio::_771);
        return;
      }
    }
    m_Do_printf::OSReport
              ("JAISound::setPitch サウンドカテゴリービットが異常です。\n");
    JUTAssertion::showAssert(3,"JAISound.cpp",0x101,"0");
    m_Do_printf::OSPanic("JAISound.cpp",0x101,"Halt");
  }
  return;
}


/* __thiscall JAISound::setFxmix(float,
                                 unsigned long,
                                 unsigned char) */

void __thiscall JAISound::setFxmix(JAISound *this,float param_1,ulong param_2,uchar param_3)

{
  uint uVar1;
  
  uVar1 = this->field_0xc & 0xc0000000;
  if (uVar1 != 0xc0000000) {
    if ((int)uVar1 < -0x40000000) {
      if ((int)uVar1 < -0x7fffffff) {
        setSeqInterFxmix(this,param_3,param_1,param_2);
        return;
      }
    }
    else {
      if (uVar1 == 0) {
        setSeInterFxmix(this,param_3,param_1,param_2,'\0');
        return;
      }
    }
    m_Do_printf::OSReport
              ("JAISound::setFxmix サウンドカテゴリービットが異常です。\n");
    JUTAssertion::showAssert(3,"JAISound.cpp",0x129,"0");
    m_Do_printf::OSPanic("JAISound.cpp",0x129,"Halt");
  }
  return;
}


/* __thiscall JAISound::setDolby(float,
                                 unsigned long,
                                 unsigned char) */

void __thiscall JAISound::setDolby(JAISound *this,float param_1,ulong param_2,uchar param_3)

{
  uint uVar1;
  
  uVar1 = this->field_0xc & 0xc0000000;
  if (uVar1 != 0xc0000000) {
    if ((int)uVar1 < -0x40000000) {
      if ((int)uVar1 < -0x7fffffff) {
        setSeqInterDolby(this,param_3,param_1,param_2);
        return;
      }
    }
    else {
      if (uVar1 == 0) {
        setSeInterDolby(this,param_3,param_1,param_2,'\0');
        return;
      }
    }
    m_Do_printf::OSReport
              ("JAISound::setDolby サウンドカテゴリービットが異常です。\n");
    JUTAssertion::showAssert(3,"JAISound.cpp",0x151,"0");
    m_Do_printf::OSPanic("JAISound.cpp",0x151,"Halt");
  }
  return;
}


/* __thiscall JAISound::setTempoProportion(float,
                                           unsigned long) */

void __thiscall JAISound::setTempoProportion(JAISound *this,float param_1,ulong param_2)

{
  uint uVar1;
  
  uVar1 = this->field_0xc & 0xc0000000;
  if (uVar1 != 0xc0000000) {
    if ((int)uVar1 < -0x40000000) {
      if ((int)uVar1 < -0x7fffffff) {
        setSeqTempoProportion(this,param_1,param_2);
        return;
      }
    }
    else {
      if (uVar1 == 0) {
        return;
      }
    }
    m_Do_printf::OSReport
              (
              "JAISound::setTempoProportion サウンドカテゴリービットが異常です。\n"
              );
    JUTAssertion::showAssert(3,"JAISound.cpp",0x179,"0");
    m_Do_printf::OSPanic("JAISound.cpp",0x179,"Halt");
  }
  return;
}


/* __thiscall JAISound::setPortData(unsigned char,
                                    unsigned short) */

void __thiscall JAISound::setPortData(JAISound *this,uchar param_1,ushort param_2)

{
  uint uVar1;
  
  uVar1 = this->field_0xc & 0xc0000000;
  if (uVar1 != 0xc0000000) {
    if ((int)uVar1 < -0x40000000) {
      if ((int)uVar1 < -0x7fffffff) {
        setSeqPortData(this,param_1,param_2,0);
        return;
      }
    }
    else {
      if (uVar1 == 0) {
        setSePortData(this,param_1,param_2);
        return;
      }
    }
    m_Do_printf::OSReport
              ("JAISound::setPortData サウンドカテゴリービットが異常です。\n");
    JUTAssertion::showAssert(3,"JAISound.cpp",0x18d,"0");
    m_Do_printf::OSPanic("JAISound.cpp",0x18d,"Halt");
  }
  return;
}


/* __thiscall JAISound::setPrepareFlag(unsigned char) */

void __thiscall JAISound::setPrepareFlag(JAISound *this,uchar param_1)

{
  uint uVar1;
  
  uVar1 = this->field_0xc & 0xc0000000;
  if (uVar1 == 0xc0000000) {
    setStreamPrepareFlag(this,param_1);
  }
  else {
    if ((int)uVar1 < -0x40000000) {
      if ((int)uVar1 < -0x7fffffff) {
        setSeqPrepareFlag(this,param_1);
        return;
      }
    }
    else {
      if (uVar1 == 0) {
        return;
      }
    }
    m_Do_printf::OSReport
              ("JAISound::setPrepareFlag サウンドカテゴリービットが異常です。\n");
    JUTAssertion::showAssert(3,"JAISound.cpp",0x1a0,"0");
    m_Do_printf::OSPanic("JAISound.cpp",0x1a0,"Halt");
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAISound::setDistanceVolumeCommon(float,
                                                unsigned char) */

double __thiscall JAISound::setDistanceVolumeCommon(JAISound *this,float param_1,uchar param_2)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  double dVar4;
  
  if (*(byte *)&this->field_0x8 == 4) {
    fVar1 = *(float *)(*(int *)(this + 1) + 0x18);
    for (uVar3 = 1; (uVar3 & 0xff) < _audioCameraMax; uVar3 = uVar3 + 1) {
      fVar2 = *(float *)(*(int *)(this + 1) + (uVar3 & 0xff) * 0x1c + 0x18);
      if (fVar2 < fVar1) {
        fVar1 = fVar2;
      }
    }
  }
  else {
    fVar1 = *(float *)(*(int *)(this + 1) + (uint)*(byte *)&this->field_0x8 * 0x1c + 0x18);
  }
  if (_maxVolumeDistance <= fVar1) {
    fVar1 = fVar1 - _maxVolumeDistance;
    fVar2 = param_1 - _maxVolumeDistance;
    if (param_2 < 4) {
      if (param_2 != '\0') {
        fVar2 = fVar2 * (float)((double)CONCAT44(0x43300000,1 << (param_2 & 3) ^ 0x80000000) -
                               JAudio::_1001);
      }
    }
    else {
      fVar2 = fVar2 / (float)((double)CONCAT44(0x43300000,1 << (param_2 & 3) + 1 ^ 0x80000000) -
                             JAudio::_1001);
    }
    if (fVar2 <= fVar1) {
      if (param_2 < 4) {
        dVar4 = (double)_minDistanceVolume;
      }
      else {
        dVar4 = (double)JAudio::_771;
      }
    }
    else {
      if (param_2 < 4) {
        dVar4 = (double)(_minDistanceVolume +
                        (JAudio::_999 - _minDistanceVolume) * (JAudio::_999 - fVar1 / fVar2));
      }
      else {
        dVar4 = (double)(JAudio::_999 - fVar1 / fVar2);
      }
    }
  }
  else {
    dVar4 = (double)JAudio::_999;
  }
  return dVar4;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAISound::setDistancePanCommon(void) */

double __thiscall JAISound::setDistancePanCommon(JAISound *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  double dVar5;
  
  if (_audioCameraMax == 1) {
    pfVar4 = *(float **)(this + 1);
    fVar2 = ABS(*pfVar4);
    fVar3 = ABS(pfVar4[2]);
    if ((JAudio::_999 <= fVar2) || (JAudio::_999 <= fVar3)) {
      if (_panDistanceMax < fVar2) {
        fVar2 = _panDistanceMax;
      }
      if (_panDistanceMax < fVar3) {
        fVar3 = _panDistanceMax;
      }
      fVar1 = *pfVar4;
      if ((JAudio::_771 == fVar1) && (JAudio::_771 == pfVar4[2])) {
        dVar5 = (double)JAudio::_1045;
      }
      else {
        if ((fVar1 <= JAudio::_771) || (fVar2 < fVar3)) {
          if ((JAudio::_771 < fVar1) || (fVar2 < fVar3)) {
            dVar5 = (double)(JAudio::_1045 + fVar1 / (_panAngleParameter2 * fVar3));
          }
          else {
            dVar5 = (double)((_panDistance2Max - fVar2) /
                            (_panAngleParameter * (_panDistance2Max - fVar3)));
          }
        }
        else {
          dVar5 = (double)(JAudio::_999 -
                          (_panDistance2Max - fVar2) /
                          (_panAngleParameter * (_panDistance2Max - fVar3)));
        }
      }
    }
    else {
      dVar5 = (double)JAudio::_1045;
    }
  }
  else {
    if (*(byte *)&this->field_0x8 == 4) {
      dVar5 = (double)JAudio::_1045;
    }
    else {
      dVar5 = (double)(float)((double)CONCAT44(0x43300000,*(byte *)&this->field_0x8 & 1 ^ 0x80000000
                                              ) - JAudio::_1001);
    }
  }
  return dVar5;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAISound::setPositionDopplarCommon(unsigned long) */

double __thiscall JAISound::setPositionDopplarCommon(JAISound *this,ulong param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  
  pfVar5 = *(float **)(this + 1);
  pfVar6 = **(float ***)(_msBasic + 4);
  pfVar4 = (*(float ***)(_msBasic + 4))[1];
  fVar1 = *pfVar6 - *pfVar5;
  fVar2 = pfVar6[1] - pfVar5[1];
  fVar3 = pfVar6[2] - pfVar5[2];
  dVar9 = (double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2);
  if ((double)JAudio::_771 < dVar9) {
    dVar8 = 1.0 / SQRT(dVar9);
    dVar8 = JAudio::_1082 * dVar8 * (JAudio::_1083 - dVar9 * dVar8 * dVar8);
    dVar8 = JAudio::_1082 * dVar8 * (JAudio::_1083 - dVar9 * dVar8 * dVar8);
    dVar9 = (double)(float)(dVar9 * JAudio::_1082 * dVar8 * (JAudio::_1083 - dVar9 * dVar8 * dVar8))
    ;
  }
  fVar1 = fVar1 + ((*pfVar6 - *pfVar4) - (*pfVar5 - pfVar5[3]));
  fVar2 = fVar2 + ((pfVar6[1] - pfVar4[1]) - (pfVar5[1] - pfVar5[4]));
  fVar3 = fVar3 + ((pfVar6[2] - pfVar4[2]) - (pfVar5[2] - pfVar5[5]));
  dVar8 = (double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2);
  if ((double)JAudio::_771 < dVar8) {
    dVar7 = 1.0 / SQRT(dVar8);
    dVar7 = JAudio::_1082 * dVar7 * (JAudio::_1083 - dVar8 * dVar7 * dVar7);
    dVar7 = JAudio::_1082 * dVar7 * (JAudio::_1083 - dVar8 * dVar7 * dVar7);
    dVar8 = (double)(float)(dVar8 * JAudio::_1082 * dVar7 * (JAudio::_1083 - dVar8 * dVar7 * dVar7))
    ;
  }
  dVar8 = (double)(JAudio::_999 /
                  (JAudio::_999 -
                  (float)(dVar9 - dVar8) /
                  (_dopplarParameter /
                  (float)((double)CONCAT44(0x43300000,(param_1 >> 8) * (param_1 >> 8)) -
                         JAudio::_1087))));
  dVar9 = (double)JAudio::_1084;
  if ((dVar9 <= dVar8) && (dVar9 = dVar8, (double)JAudio::_1085 < dVar8)) {
    dVar9 = (double)JAudio::_1085;
  }
  return dVar9;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JAISound::setSeqInterVolume(unsigned char,
                                          float,
                                          unsigned long) */

void __thiscall
JAISound::setSeqInterVolume(JAISound *this,uchar param_1,float param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  double dVar3;
  
  dVar3 = (double)param_2;
  if (((this->field_0xc & 0xc0000000U) == 0x80000000) && (iVar1 = getSeqParameter(this), iVar1 != 0)
     ) {
    iVar1 = getSeqParameter(this);
    iVar1 = JAInter::MoveParaSet::set
                      ((MoveParaSet *)(iVar1 + (uint)param_1 * 0x10 + 0x110),(float)dVar3,param_3);
    if (iVar1 == 1) {
      iVar2 = getSeqParameter(this);
      *(uint *)(iVar2 + 0x126c) = *(uint *)(iVar2 + 0x126c) | 1 << param_1;
    }
    iVar2 = getSeqParameter(this);
    if ((*(int *)(iVar2 + 0x135c) != 0) && (iVar1 != 2)) {
      iVar1 = getSeqParameter(this);
      *(uint *)(*(int *)(iVar1 + 0x135c) + 8) = *(uint *)(*(int *)(iVar1 + 0x135c) + 8) | 0x40000;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JAISound::setSeqInterPan(unsigned char,
                                       float,
                                       unsigned long) */

void __thiscall JAISound::setSeqInterPan(JAISound *this,uchar param_1,float param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  double dVar3;
  
  dVar3 = (double)param_2;
  if (((this->field_0xc & 0xc0000000U) == 0x80000000) && (iVar1 = getSeqParameter(this), iVar1 != 0)
     ) {
    if ((JAIGlobalParameter::seqParameterLines <= param_1) &&
       (m_Do_printf::OSReport
                  ("JAISound::setSeqInterPan 設定できるライン数を超えています。\n")
       , JAIGlobalParameter::seqParameterLines <= param_1)) {
      JUTAssertion::showAssert(3,"JAISound.cpp",0x294,"line_<JAIGlobalParameter::seqParameterLines")
      ;
      m_Do_printf::OSPanic("JAISound.cpp",0x294,"Halt");
    }
    iVar1 = getSeqParameter(this);
    iVar1 = JAInter::MoveParaSet::set
                      ((MoveParaSet *)(*(int *)(iVar1 + 0x250) + (uint)param_1 * 0x10),(float)dVar3,
                       param_3);
    if (iVar1 == 1) {
      iVar2 = getSeqParameter(this);
      *(uint *)(iVar2 + 0x1270) = *(uint *)(iVar2 + 0x1270) | 1 << param_1;
    }
    iVar2 = getSeqParameter(this);
    if ((*(int *)(iVar2 + 0x135c) != 0) && (iVar1 != 2)) {
      iVar1 = getSeqParameter(this);
      *(uint *)(*(int *)(iVar1 + 0x135c) + 8) = *(uint *)(*(int *)(iVar1 + 0x135c) + 8) | 0x80000;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JAISound::setSeqInterPitch(unsigned char,
                                         float,
                                         unsigned long) */

void __thiscall JAISound::setSeqInterPitch(JAISound *this,uchar param_1,float param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  double dVar3;
  
  dVar3 = (double)param_2;
  if (((this->field_0xc & 0xc0000000U) == 0x80000000) && (iVar1 = getSeqParameter(this), iVar1 != 0)
     ) {
    if ((JAIGlobalParameter::seqParameterLines <= param_1) &&
       (m_Do_printf::OSReport
                  ("JAISound::setSeqInterPan 設定できるライン数を超えています。\n")
       , JAIGlobalParameter::seqParameterLines <= param_1)) {
      JUTAssertion::showAssert(3,"JAISound.cpp",0x2a6,"line_<JAIGlobalParameter::seqParameterLines")
      ;
      m_Do_printf::OSPanic("JAISound.cpp",0x2a6,"Halt");
    }
    iVar1 = getSeqParameter(this);
    iVar1 = JAInter::MoveParaSet::set
                      ((MoveParaSet *)(*(int *)(iVar1 + 0x254) + (uint)param_1 * 0x10),(float)dVar3,
                       param_3);
    if (iVar1 == 1) {
      iVar2 = getSeqParameter(this);
      *(uint *)(iVar2 + 0x1274) = *(uint *)(iVar2 + 0x1274) | 1 << param_1;
    }
    iVar2 = getSeqParameter(this);
    if ((*(int *)(iVar2 + 0x135c) != 0) && (iVar1 != 2)) {
      iVar1 = getSeqParameter(this);
      *(uint *)(*(int *)(iVar1 + 0x135c) + 8) = *(uint *)(*(int *)(iVar1 + 0x135c) + 8) | 0x100000;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JAISound::setSeqInterFxmix(unsigned char,
                                         float,
                                         unsigned long) */

void __thiscall JAISound::setSeqInterFxmix(JAISound *this,uchar param_1,float param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  double dVar3;
  
  dVar3 = (double)param_2;
  if (((this->field_0xc & 0xc0000000U) == 0x80000000) && (iVar1 = getSeqParameter(this), iVar1 != 0)
     ) {
    if ((JAIGlobalParameter::seqParameterLines <= param_1) &&
       (m_Do_printf::OSReport
                  ("JAISound::setSeqInterPan 設定できるライン数を超えています。\n")
       , JAIGlobalParameter::seqParameterLines <= param_1)) {
      JUTAssertion::showAssert(3,"JAISound.cpp",0x2b8,"line_<JAIGlobalParameter::seqParameterLines")
      ;
      m_Do_printf::OSPanic("JAISound.cpp",0x2b8,"Halt");
    }
    iVar1 = getSeqParameter(this);
    iVar1 = JAInter::MoveParaSet::set
                      ((MoveParaSet *)(*(int *)(iVar1 + 600) + (uint)param_1 * 0x10),(float)dVar3,
                       param_3);
    if (iVar1 == 1) {
      iVar2 = getSeqParameter(this);
      *(uint *)(iVar2 + 0x1278) = *(uint *)(iVar2 + 0x1278) | 1 << param_1;
    }
    iVar2 = getSeqParameter(this);
    if ((*(int *)(iVar2 + 0x135c) != 0) && (iVar1 != 2)) {
      iVar1 = getSeqParameter(this);
      *(uint *)(*(int *)(iVar1 + 0x135c) + 8) = *(uint *)(*(int *)(iVar1 + 0x135c) + 8) | 0x200000;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802997c4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAISound::setSeqInterDolby(unsigned char,
                                         float,
                                         unsigned long) */

void __thiscall JAISound::setSeqInterDolby(JAISound *this,uchar param_1,float param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar4 = (double)param_2;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (((this->field_0xc & 0xc0000000U) == 0x80000000) && (iVar1 = getSeqParameter(this), iVar1 != 0)
     ) {
    if ((JAIGlobalParameter::seqParameterLines <= param_1) &&
       (m_Do_printf::OSReport
                  ("JAISound::setSeqInterPan 設定できるライン数を超えています。\n")
       , JAIGlobalParameter::seqParameterLines <= param_1)) {
      JUTAssertion::showAssert(3,"JAISound.cpp",0x2ca,"line_<JAIGlobalParameter::seqParameterLines")
      ;
      m_Do_printf::OSPanic("JAISound.cpp",0x2ca,"Halt");
    }
    if (*(char *)(_msBasic + 0xd) != '\x02') {
      iVar1 = getSeqParameter(this);
      dVar4 = (double)JAudio::_771;
      if (dVar4 == (double)*(float *)(*(int *)(iVar1 + 0x25c) + (uint)param_1 * 0x10 + 4))
      goto LAB_802997c4;
    }
    iVar1 = getSeqParameter(this);
    iVar1 = JAInter::MoveParaSet::set
                      ((MoveParaSet *)(*(int *)(iVar1 + 0x25c) + (uint)param_1 * 0x10),(float)dVar4,
                       param_3);
    if (iVar1 == 1) {
      iVar2 = getSeqParameter(this);
      *(uint *)(iVar2 + 0x127c) = *(uint *)(iVar2 + 0x127c) | 1 << param_1;
    }
    iVar2 = getSeqParameter(this);
    if ((*(int *)(iVar2 + 0x135c) != 0) && (iVar1 != 2)) {
      iVar1 = getSeqParameter(this);
      *(uint *)(*(int *)(iVar1 + 0x135c) + 8) = *(uint *)(*(int *)(iVar1 + 0x135c) + 8) | 0x400000;
    }
  }
LAB_802997c4:
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __thiscall JAISound::setSeqTempoProportion(float,
                                              unsigned long) */

void __thiscall JAISound::setSeqTempoProportion(JAISound *this,float param_1,ulong param_2)

{
  int iVar1;
  MoveParaSet *this_00;
  double dVar2;
  
  dVar2 = (double)param_1;
  if (((this->field_0xc & 0xc0000000U) == 0x80000000) && (iVar1 = getSeqParameter(this), iVar1 != 0)
     ) {
    this_00 = (MoveParaSet *)getSeqParameter(this);
    JAInter::MoveParaSet::set(this_00,(float)dVar2,param_2);
    iVar1 = getSeqParameter(this);
    if (*(int *)(iVar1 + 0x135c) != 0) {
      iVar1 = getSeqParameter(this);
      *(uint *)(*(int *)(iVar1 + 0x135c) + 8) = *(uint *)(*(int *)(iVar1 + 0x135c) + 8) | 4;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x802999d4) */
/* __thiscall JAISound::setSeqPortData(unsigned char,
                                       unsigned short,
                                       unsigned long) */

void __thiscall JAISound::setSeqPortData(JAISound *this,uchar param_1,ushort param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 in_f31;
  double dVar4;
  ushort local_38 [4];
  undefined4 local_30;
  uint uStack44;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (((this->field_0xc & 0xc0000000U) == 0x80000000) && (iVar1 = getSeqParameter(this), iVar1 != 0)
     ) {
    iVar1 = getSeqParameter(this);
    iVar2 = (uint)param_1 * 0x10;
    if ((JAudio::_771 == *(float *)(iVar1 + iVar2 + 0x14)) && (2 < *(byte *)&this->field_0x5)) {
      iVar1 = getSeqParameter(this);
      JASystem::TTrack::readPortApp((TTrack *)(iVar1 + 0x1360),(uint)param_1 << 0x10,local_38);
      uStack44 = (uint)local_38[0];
      local_30 = 0x43300000;
      dVar4 = (double)(float)((double)CONCAT44(0x43300000,uStack44) - JAudio::_1087);
      iVar1 = getSeqParameter(this);
      *(float *)(iVar1 + iVar2 + 0x14) = (float)dVar4;
    }
    iVar1 = getSeqParameter(this);
    uStack44 = (uint)param_2;
    local_30 = 0x43300000;
    iVar1 = JAInter::MoveParaSet::set
                      ((MoveParaSet *)(iVar1 + iVar2 + 0x10),
                       (float)((double)CONCAT44(0x43300000,uStack44) - JAudio::_1087),param_3);
    if (iVar1 == 1) {
      iVar2 = getSeqParameter(this);
      *(uint *)(iVar2 + 0x1268) = *(uint *)(iVar2 + 0x1268) | 1 << param_1;
    }
    iVar2 = getSeqParameter(this);
    if ((*(int *)(iVar2 + 0x135c) != 0) && (iVar1 != 2)) {
      iVar1 = getSeqParameter(this);
      *(uint *)(*(int *)(iVar1 + 0x135c) + 8) = *(uint *)(*(int *)(iVar1 + 0x135c) + 8) | 0x10;
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JAISound::setTrackVolume(unsigned char,
                                       float,
                                       unsigned long) */

void __thiscall JAISound::setTrackVolume(JAISound *this,uchar param_1,float param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  double dVar3;
  
  dVar3 = (double)param_2;
  if (((this->field_0xc & 0xc0000000U) == 0x80000000) && (iVar1 = getSeqParameter(this), iVar1 != 0)
     ) {
    if ((3 < *(byte *)&this->field_0x5) &&
       (iVar1 = getSeqParameter(this), (1 << param_1 & *(uint *)(*(int *)(iVar1 + 0x135c) + 4)) == 0
       )) {
      return;
    }
    if (param_3 == 0) {
      param_3 = 1;
    }
    iVar1 = getSeqParameter(this);
    iVar1 = JAInter::MoveParaSet::set
                      ((MoveParaSet *)(iVar1 + (uint)param_1 * 0x10 + 0x260),(float)dVar3,param_3);
    if (iVar1 == 1) {
      iVar2 = getSeqParameter(this);
      *(uint *)(iVar2 + 0x1280) = *(uint *)(iVar2 + 0x1280) | 1 << param_1;
    }
    iVar2 = getSeqParameter(this);
    if ((*(int *)(iVar2 + 0x135c) != 0) && (iVar1 != 2)) {
      iVar1 = getSeqParameter(this);
      *(uint *)(*(int *)(iVar1 + 0x135c) + 8) = *(uint *)(*(int *)(iVar1 + 0x135c) + 8) | 0x40;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JAISound::setTrackInterruptSwitch(unsigned char,
                                                unsigned char) */

void __thiscall JAISound::setTrackInterruptSwitch(JAISound *this,uchar param_1,uchar param_2)

{
  int iVar1;
  
  if (((this->field_0xc & 0xc0000000U) == 0x80000000) && (iVar1 = getSeqParameter(this), iVar1 != 0)
     ) {
    iVar1 = getSeqParameter(this);
    *(uchar *)(iVar1 + param_1 + 0x131c) = param_2;
    iVar1 = getSeqParameter(this);
    if (*(int *)(iVar1 + 0x135c) != 0) {
      iVar1 = getSeqParameter(this);
      *(uint *)(*(int *)(iVar1 + 0x135c) + 8) = *(uint *)(*(int *)(iVar1 + 0x135c) + 8) | 0x800000;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JAISound::setTrackPortData(unsigned char,
                                         unsigned char,
                                         unsigned short) */

void __thiscall
JAISound::setTrackPortData(JAISound *this,uchar param_1,uchar param_2,ushort param_3)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  
  if ((((this->field_0xc & 0xc0000000U) == 0x80000000) &&
      (iVar1 = getSeqParameter(this), iVar1 != 0)) &&
     (iVar1 = getSeqParameter(this), *(int *)(iVar1 + 0x135c) != 0)) {
    if (*(byte *)&this->field_0x5 < 4) {
      iVar1 = getSeqParameter(this);
      *(uint *)(*(int *)(iVar1 + 0x135c) + 8) = *(uint *)(*(int *)(iVar1 + 0x135c) + 8) | 0x1000;
      iVar1 = getSeqParameter(this);
      *(uint *)(iVar1 + 0x1298) = *(uint *)(iVar1 + 0x1298) | 1 << param_1;
      iVar1 = getSeqParameter(this);
      iVar3 = (uint)param_1 * 4 + 0x129c;
      *(uint *)(iVar1 + iVar3) = *(uint *)(iVar1 + iVar3) | 1 << param_2;
    }
    else {
      iVar1 = getSeqParameter(this);
      uVar2 = getTrackPortRoute(this,param_1,param_2);
      JASystem::TTrack::writePortApp((TTrack *)(iVar1 + 0x1360),uVar2,param_3);
    }
    iVar1 = getSeqParameter(this);
    *(ushort *)(iVar1 + (uint)param_1 * 0x20 + (uint)param_2 * 2 + 0xe60) = param_3;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x80299dc0) */
/* WARNING: Removing unreachable block (ram,0x80299dc8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAISound::setSeInterRandomPara(float *,
                                             unsigned long,
                                             float,
                                             float) */

void __thiscall
JAISound::setSeInterRandomPara
          (JAISound *this,float *param_1,ulong param_2,float param_3,float param_4)

{
  float fVar1;
  uint uVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar6 = (double)param_4;
  dVar5 = (double)param_3;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  _random = _random * 0x19660d + 0x3c6ef35f;
  uVar2 = Runtime.PPCEABI.H::__cvt_fp2unsigned
                    ((double)(JAudio::_1466 * ((float)(_random >> 9 | 0x3f800000) - JAudio::_999)));
  dVar4 = (double)(((float)((double)CONCAT44(0x43300000,
                                             (uVar2 - (uVar2 / (param_2 * 2)) * param_2 * 2) + 1) -
                           JAudio::_1087) -
                   (float)((double)CONCAT44(0x43300000,param_2) - JAudio::_1087)) / JAudio::_1467);
  fVar1 = (float)((double)*param_1 + dVar4);
  if ((double)fVar1 <= dVar6) {
    if ((double)(float)(dVar5 - dVar4) <= (double)*param_1) {
      *param_1 = fVar1;
    }
    else {
      *param_1 = (float)dVar5;
    }
  }
  else {
    *param_1 = (float)dVar6;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JAISound::setSeInterVolume(unsigned char,
                                         float,
                                         unsigned long,
                                         unsigned char) */

void __thiscall
JAISound::setSeInterVolume(JAISound *this,uchar param_1,float param_2,ulong param_3,uchar param_4)

{
  int iVar1;
  float local_18 [2];
  
  if ((this->field_0xc & 0xc0000000U) == 0) {
    local_18[0] = param_2;
    iVar1 = getSeParameter(this);
    if (iVar1 != 0) {
      if (param_4 != '\0') {
        setSeInterRandomPara(this,local_18,((uint)param_4 * 1000) / 0x7f,JAudio::_771,JAudio::_999);
      }
      iVar1 = getSeParameter(this);
      JAInter::MoveParaSet::set
                ((MoveParaSet *)(iVar1 + (uint)param_1 * 0x10 + 0x124),local_18[0],param_3);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JAISound::setSeInterPan(unsigned char,
                                      float,
                                      unsigned long,
                                      unsigned char) */

void __thiscall
JAISound::setSeInterPan(JAISound *this,uchar param_1,float param_2,ulong param_3,uchar param_4)

{
  int iVar1;
  float local_18 [2];
  
  if ((this->field_0xc & 0xc0000000U) == 0) {
    local_18[0] = param_2;
    iVar1 = getSeParameter(this);
    if (iVar1 != 0) {
      if (param_4 != '\0') {
        setSeInterRandomPara(this,local_18,((uint)param_4 * 1000) / 0x7f,JAudio::_771,JAudio::_999);
      }
      iVar1 = getSeParameter(this);
      JAInter::MoveParaSet::set
                ((MoveParaSet *)(iVar1 + (uint)param_1 * 0x10 + 0x1a4),local_18[0],param_3);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80299fc0) */
/* __thiscall JAISound::setSeInterPitch(unsigned char,
                                        float,
                                        unsigned long,
                                        float) */

void __thiscall
JAISound::setSeInterPitch(JAISound *this,uchar param_1,float param_2,ulong param_3,float param_4)

{
  int iVar1;
  ulong uVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  float local_28 [3];
  undefined auStack8 [8];
  
  dVar4 = (double)param_4;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (((this->field_0xc & 0xc0000000U) == 0) &&
     (local_28[0] = param_2, iVar1 = getSeParameter(this), iVar1 != 0)) {
    if ((double)JAudio::_771 != dVar4) {
      uVar2 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)(float)((double)JAudio::_1467 * dVar4));
      setSeInterRandomPara(this,local_28,uVar2,JAudio::_1084,JAudio::_1497);
    }
    iVar1 = getSeParameter(this);
    JAInter::MoveParaSet::set
              ((MoveParaSet *)(iVar1 + (uint)param_1 * 0x10 + 0x224),local_28[0],param_3);
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JAISound::setSeInterFxmix(unsigned char,
                                        float,
                                        unsigned long,
                                        unsigned char) */

void __thiscall
JAISound::setSeInterFxmix(JAISound *this,uchar param_1,float param_2,ulong param_3,uchar param_4)

{
  int iVar1;
  float local_18 [2];
  
  if ((this->field_0xc & 0xc0000000U) == 0) {
    local_18[0] = param_2;
    iVar1 = getSeParameter(this);
    if (iVar1 != 0) {
      if (param_4 != '\0') {
        setSeInterRandomPara(this,local_18,((uint)param_4 * 1000) / 0x7f,JAudio::_771,JAudio::_999);
      }
      iVar1 = getSeParameter(this);
      JAInter::MoveParaSet::set
                ((MoveParaSet *)(iVar1 + (uint)param_1 * 0x10 + 0x2a4),local_18[0],param_3);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JAISound::setSeInterDolby(unsigned char,
                                        float,
                                        unsigned long,
                                        unsigned char) */

void __thiscall
JAISound::setSeInterDolby(JAISound *this,uchar param_1,float param_2,ulong param_3,uchar param_4)

{
  int iVar1;
  float local_18 [2];
  
  if ((this->field_0xc & 0xc0000000U) == 0) {
    local_18[0] = param_2;
    iVar1 = getSeParameter(this);
    if (iVar1 != 0) {
      if (param_4 != '\0') {
        setSeInterRandomPara(this,local_18,((uint)param_4 * 1000) / 0x7f,JAudio::_771,JAudio::_999);
      }
      iVar1 = getSeParameter(this);
      JAInter::MoveParaSet::set
                ((MoveParaSet *)(iVar1 + (uint)param_1 * 0x10 + 0x3a4),local_18[0],param_3);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAISound::setSePortData(unsigned char,
                                      unsigned short) */

void __thiscall JAISound::setSePortData(JAISound *this,uchar param_1,ushort param_2)

{
  int iVar1;
  
  if (((this->field_0xc & 0xc0000000U) == 0) && (iVar1 = getSeParameter(this), iVar1 != 0)) {
    if (*(char *)&this->field_0x5 == '\x01') {
      iVar1 = getSeParameter(this);
      *(ushort *)(iVar1 + (uint)param_1 * 2) = param_2;
      iVar1 = getSeParameter(this);
      *(ushort *)(iVar1 + 0x20) = *(ushort *)(iVar1 + 0x20) | (ushort)(1 << param_1);
    }
    else {
      setTrackPortData(_seHandle,*(uchar *)&this->field_0x4,param_1,param_2);
    }
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAISound::setSeDistanceParameters(void) */

void __thiscall JAISound::setSeDistanceParameters(JAISound *this)

{
  uint uVar1;
  undefined uVar2;
  double dVar3;
  
  uVar2 = *(undefined *)&this->field_0x9;
  if (*(char *)&this->field_0x5 == '\x02') {
    uVar2 = 0;
  }
  (**(code **)(*(int *)this + 0x18))(this,uVar2);
  (**(code **)(*(int *)this + 0x1c))(this,uVar2);
  (**(code **)(*(int *)this + 0x20))(this,uVar2);
  (**(code **)(*(int *)this + 0x30))(this);
  (**(code **)(*(int *)this + 0x24))(this,uVar2);
  (**(code **)(*(int *)this + 0x28))(this,uVar2);
  uVar1 = getSwBit(this);
  if ((uVar1 & 0x400) == 0) {
    dVar3 = (double)(**(code **)(*_msBasic + 0x14))(_msBasic,this->field_0x1c);
    setFxmix(this,(float)dVar3,0,'\x02');
  }
  (**(code **)(*(int *)this + 0x2c))(this,uVar2);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAISound::setSeDistanceVolume(unsigned char) */

void __thiscall JAISound::setSeDistanceVolume(JAISound *this,uchar param_1)

{
  uint uVar1;
  double dVar2;
  
  uVar1 = getSwBit(this);
  if ((uVar1 & 2) == 0) {
    uVar1 = getSwBit(this);
    dVar2 = (double)(**(code **)(*(int *)this + 0xc))((double)_distanceMax,this,uVar1 >> 0x10 & 7);
  }
  else {
    dVar2 = (double)JAudio::_999;
  }
  setSeInterVolume(this,'\x04',(float)dVar2,(uint)param_1,'\0');
  return;
}


/* __thiscall JAISound::setSeDistancePan(unsigned char) */

void __thiscall JAISound::setSeDistancePan(JAISound *this,uchar param_1)

{
  double dVar1;
  
  dVar1 = (double)(**(code **)(*(int *)this + 0x10))();
  setSeInterPan(this,'\x04',(float)dVar1,(uint)param_1,'\0');
  return;
}


/* WARNING: Removing unreachable block (ram,0x8029a524) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAISound::setSeDistancePitch(unsigned char) */

void __thiscall JAISound::setSeDistancePitch(JAISound *this,uchar param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 in_f31;
  double dVar3;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar3 = (double)JAudio::_999;
  uVar1 = getSwBit(this);
  if ((uVar1 & 0x10) != 0) {
    _random = _random * 0x19660d + 0x3c6ef35f;
    dVar3 = (double)(JAudio::_999 -
                    (float)((double)CONCAT44(0x43300000,
                                             (int)(JAudio::_1497 *
                                                  ((float)(_random >> 9 | 0x3f800000) - JAudio::_999
                                                  )) & 0xfU ^ 0x80000000) - JAudio::_1001) /
                    JAudio::_1596);
  }
  uVar1 = getSwBit(this);
  if (((((uVar1 & 0x4000) != 0) && (uVar1 = getSwBit(this), (uVar1 & 2) == 0)) &&
      (uVar1 = getSwBit(this), (uVar1 & 0x300) == 0)) && (_audioCameraMax == 1)) {
    if (*(float *)(*(int *)(this + 1) + 0x18) < _distanceMax) {
      dVar3 = (double)(float)(dVar3 + (double)(_seDistancepitchMax *
                                              (*(float *)(*(int *)(this + 1) + 0x18) / _distanceMax)
                                              ));
    }
    else {
      dVar3 = (double)(float)(dVar3 + (double)_seDistancepitchMax);
    }
  }
  uVar1 = getSwBit(this);
  if ((uVar1 & 0xc0) != 0) {
    dVar3 = (double)(float)(dVar3 + (double)((float)((double)CONCAT44(0x43300000,
                                                                      (uint)*(byte *)&this->
                                                  field_0x7) - JAudio::_1087) / JAudio::_1596));
  }
  setSeInterPitch(this,'\x04',(float)dVar3,(uint)param_1,JAudio::_771);
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAISound::setSePositionDopplar(void) */

void __thiscall JAISound::setSePositionDopplar(JAISound *this)

{
  uint uVar1;
  ulong uVar2;
  double dVar3;
  
  uVar2 = _dopplarMoveTime;
  if (*(char *)&this->field_0x5 == '\x02') {
    uVar2 = 1;
  }
  uVar1 = getSwBit(this);
  if (((uVar1 & 0x300) != 0) && (_audioCameraMax == 1)) {
    dVar3 = (double)(**(code **)(*(int *)this + 8))(this);
    setSeInterPitch(this,'\x01',(float)dVar3,uVar2,JAudio::_771);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAISound::setSeDistanceFxmix(unsigned char) */

void __thiscall JAISound::setSeDistanceFxmix(JAISound *this,uchar param_1)

{
  uint uVar1;
  uint uVar2;
  double local_20;
  
  uVar2 = (uint)_seDefaultFx;
  uVar1 = getSwBit(this);
  if (((uVar1 & 4) == 0) && (_audioCameraMax == 1)) {
    if (_distanceMax <= *(float *)(*(int *)(this + 1) + 0x18)) {
      uVar2 = (uint)_seDistanceFxParameter;
    }
    else {
      uVar2 = (uint)((float)((double)CONCAT44(0x43300000,(uint)_seDistanceFxParameter) -
                            JAudio::_1087) * (*(float *)(*(int *)(this + 1) + 0x18) / _distanceMax))
      ;
    }
  }
  if (0x7f < (uVar2 & 0xffff)) {
    uVar2 = 0x7f;
  }
  local_20 = (double)CONCAT44(0x43300000,uVar2 & 0xff);
  setSeInterFxmix(this,'\x04',(float)(local_20 - JAudio::_1087) / JAudio::_1622,(uint)param_1,'\0');
  return;
}


/* __thiscall JAISound::setSeDistanceFir(unsigned char) */

void __thiscall JAISound::setSeDistanceFir(JAISound *this,uchar param_1)

{
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAISound::setSeDistanceDolby(unsigned char) */

void __thiscall JAISound::setSeDistanceDolby(JAISound *this,uchar param_1)

{
  float fVar1;
  float fVar2;
  
  fVar2 = JAudio::_771;
  if ((*(int *)&this[1].field_0x8 != 0) &&
     (fVar1 = *(float *)(*(int *)(this + 1) + 8), _seDolbyFrontDistanceMax <= fVar1)) {
    if (JAudio::_771 <= fVar1) {
      fVar2 = JAudio::_1622;
      if (fVar1 < _seDolbyBehindDistanceMax) {
        fVar2 = _seDolbyCenterValue +
                (JAudio::_1622 - _seDolbyCenterValue) * (fVar1 / _seDolbyBehindDistanceMax);
      }
    }
    else {
      fVar2 = (_seDolbyCenterValue * (_seDolbyFrontDistanceMax - fVar1)) / _seDolbyFrontDistanceMax;
    }
  }
  setSeInterDolby(this,'\x04',
                  (float)((double)CONCAT44(0x43300000,(int)fVar2 & 0xff) - JAudio::_1087) /
                  JAudio::_1622,(uint)param_1,'\0');
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JAISound::setStreamInterVolume(unsigned char,
                                             float,
                                             unsigned long) */

void __thiscall
JAISound::setStreamInterVolume(JAISound *this,uchar param_1,float param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  double dVar3;
  
  dVar3 = (double)param_2;
  if (((this->field_0xc & 0xc0000000U) == 0xc0000000) &&
     (iVar1 = getStreamParameter(this), iVar1 != 0)) {
    iVar1 = getStreamParameter(this);
    iVar1 = JAInter::MoveParaSet::set
                      ((MoveParaSet *)(iVar1 + (uint)param_1 * 0x10 + 0x14),(float)dVar3,param_3);
    if (iVar1 == 1) {
      iVar2 = getStreamParameter(this);
      *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) | 1 << param_1;
    }
    iVar2 = getStreamParameter(this);
    if ((*(int *)(iVar2 + 0x15c) != 0) && (iVar1 != 2)) {
      iVar1 = getStreamParameter(this);
      *(uint *)(*(int *)(iVar1 + 0x15c) + 0x10) =
           *(uint *)(*(int *)(iVar1 + 0x15c) + 0x10) | 0x40000;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JAISound::setStreamInterPitch(unsigned char,
                                            float,
                                            unsigned long) */

void __thiscall
JAISound::setStreamInterPitch(JAISound *this,uchar param_1,float param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  double dVar3;
  
  dVar3 = (double)param_2;
  if (((this->field_0xc & 0xc0000000U) == 0xc0000000) &&
     (iVar1 = getStreamParameter(this), iVar1 != 0)) {
    iVar1 = getStreamParameter(this);
    iVar1 = JAInter::MoveParaSet::set
                      ((MoveParaSet *)(*(int *)(iVar1 + 0x154) + (uint)param_1 * 0x10),(float)dVar3,
                       param_3);
    if (iVar1 == 1) {
      iVar2 = getStreamParameter(this);
      *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 1 << param_1;
    }
    iVar2 = getStreamParameter(this);
    if ((*(int *)(iVar2 + 0x15c) != 0) && (iVar1 != 2)) {
      iVar1 = getStreamParameter(this);
      *(uint *)(*(int *)(iVar1 + 0x15c) + 0x10) =
           *(uint *)(*(int *)(iVar1 + 0x15c) + 0x10) | 0x100000;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JAISound::setStreamInterPan(unsigned char,
                                          float,
                                          unsigned long) */

void __thiscall
JAISound::setStreamInterPan(JAISound *this,uchar param_1,float param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  double dVar3;
  
  dVar3 = (double)param_2;
  if (((this->field_0xc & 0xc0000000U) == 0xc0000000) &&
     (iVar1 = getStreamParameter(this), iVar1 != 0)) {
    iVar1 = getStreamParameter(this);
    iVar1 = JAInter::MoveParaSet::set
                      ((MoveParaSet *)(*(int *)(iVar1 + 0x158) + (uint)param_1 * 0x10),(float)dVar3,
                       param_3);
    if (iVar1 == 1) {
      iVar2 = getStreamParameter(this);
      *(uint *)(iVar2 + 0x10) = *(uint *)(iVar2 + 0x10) | 1 << param_1;
    }
    iVar2 = getStreamParameter(this);
    if ((*(int *)(iVar2 + 0x15c) != 0) && (iVar1 != 2)) {
      iVar1 = getStreamParameter(this);
      *(uint *)(*(int *)(iVar1 + 0x15c) + 0x10) =
           *(uint *)(*(int *)(iVar1 + 0x15c) + 0x10) | 0x80000;
    }
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAISound::setStreamPrepareFlag(unsigned char) */

void __thiscall JAISound::setStreamPrepareFlag(JAISound *this,uchar param_1)

{
  int iVar1;
  
  if (((this->field_0xc & 0xc0000000U) == 0xc0000000) &&
     (iVar1 = getStreamParameter(this), iVar1 != 0)) {
    *(uchar *)(_streamUpdate + 2) = param_1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JAISound::setPauseMode(unsigned char,
                                     unsigned char) */

void __thiscall JAISound::setPauseMode(JAISound *this,uchar param_1,uchar param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  uchar *puVar5;
  uchar extraout_r4;
  uchar extraout_r4_00;
  
  uVar2 = this->field_0xc & 0xc0000000;
  if (uVar2 == 0xc0000000) {
    iVar3 = getStreamParameter(this);
    if (iVar3 != 0) {
      if (param_1 == '\0') {
        pbVar4 = (byte *)getStreamParameter(this);
        bVar1 = *pbVar4;
        if (bVar1 == 2) {
          JAInter::StreamLib::clearPauseFlag((StreamLib *)&DAT_00000002,extraout_r4_00);
        }
        else {
          if ((bVar1 < 2) && (bVar1 != 0)) {
            setStreamInterVolume(this,'\v',JAudio::_999,1);
          }
        }
      }
      else {
        if (param_1 == '\x02') {
          JAInter::StreamLib::setPauseFlag((StreamLib *)&DAT_00000002,extraout_r4);
        }
        else {
          if ((param_1 < 2) && (param_1 != '\0')) {
            setStreamInterVolume
                      (this,'\v',
                       (float)((double)CONCAT44(0x43300000,(uint)param_2) - JAudio::_1087) /
                       JAudio::_1622,1);
          }
        }
      }
      puVar5 = (uchar *)getStreamParameter(this);
      *puVar5 = param_1;
    }
  }
  else {
    if (((int)uVar2 < -0x40000000) && ((int)uVar2 < -0x7fffffff)) {
      iVar3 = getSeqParameter(this);
      if (iVar3 != 0) {
        if (param_1 == '\x03') {
          param_1 = 4;
        }
        if (param_1 == 0) {
          getSeqParameter(this);
          iVar3 = getSeqParameter(this);
          bVar1 = *(byte *)(iVar3 + 0x1261);
          if (bVar1 == 2) {
            iVar3 = getSeqParameter(this);
            JASystem::TTrack::pause((TTrack *)(iVar3 + 0x1360));
          }
          else {
            if ((bVar1 < 2) && (bVar1 != 0)) {
              setSeqInterVolume(this,'\v',JAudio::_999,1);
            }
          }
        }
        else {
          if (param_1 == 2) {
            iVar3 = getSeqParameter(this);
            JASystem::TTrack::pause((TTrack *)(iVar3 + 0x1360));
          }
          else {
            if ((param_1 < 2) && (param_1 != 0)) {
              setSeqInterVolume(this,'\v',
                                (float)((double)CONCAT44(0x43300000,(uint)param_2) - JAudio::_1087)
                                / JAudio::_1622,1);
            }
          }
        }
        iVar3 = getSeqParameter(this);
        *(uchar *)(iVar3 + 0x1261) = param_1;
      }
    }
    else {
      m_Do_printf::OSReport
                ("JAISound::setPauseMode サウンドカテゴリービットが異常です。\n");
      JUTAssertion::showAssert(3,"JAISound.cpp",0x5a3,"0");
      m_Do_printf::OSPanic("JAISound.cpp",0x5a3,"Halt");
    }
  }
  return;
}


/* __thiscall JAISound::setSeqPrepareFlag(unsigned char) */

void __thiscall JAISound::setSeqPrepareFlag(JAISound *this,uchar param_1)

{
  int iVar1;
  
  if (((this->field_0xc & 0xc0000000U) == 0x80000000) && (iVar1 = getSeqParameter(this), iVar1 != 0)
     ) {
    iVar1 = getSeqParameter(this);
    *(uchar *)(*(int *)(iVar1 + 0x135c) + 2) = param_1;
  }
  return;
}


/* __thiscall JAISound::getSeqInterVolume(unsigned char) */

double __thiscall JAISound::getSeqInterVolume(JAISound *this,uchar param_1)

{
  float fVar1;
  int iVar2;
  
  if ((*(char *)&this->field_0x5 == '\x04') ||
     (fVar1 = JAudio::_1784, *(char *)&this->field_0x5 == '\x05')) {
    iVar2 = getSeqParameter(this);
    fVar1 = *(float *)(iVar2 + (uint)param_1 * 0x10 + 0x114);
  }
  return (double)fVar1;
}


/* __thiscall JAISound::getStreamInterVolume(unsigned char) */

double __thiscall JAISound::getStreamInterVolume(JAISound *this,uchar param_1)

{
  int iVar1;
  double dVar2;
  
  if (((this->field_0xc & 0xc0000000U) == 0xc0000000) &&
     (iVar1 = getStreamParameter(this), iVar1 != 0)) {
    if ((*(char *)&this->field_0x5 == '\x04') || (*(char *)&this->field_0x5 == '\x05')) {
      iVar1 = getStreamParameter(this);
      dVar2 = (double)*(float *)(iVar1 + (uint)param_1 * 0x10 + 0x18);
    }
    else {
      dVar2 = (double)JAudio::_1784;
    }
  }
  else {
    dVar2 = (double)JAudio::_1784;
  }
  return dVar2;
}


/* __thiscall JAISound::getSeqParameter(void) */

int __thiscall JAISound::getSeqParameter(JAISound *this)

{
  return this[1].field_0x1c;
}


/* __thiscall JAISound::getSeParameter(void) */

int __thiscall JAISound::getSeParameter(JAISound *this)

{
  return this[1].field_0x1c;
}


/* __thiscall JAISound::getStreamParameter(void) */

int __thiscall JAISound::getStreamParameter(JAISound *this)

{
  return this[1].field_0x1c;
}


/* __thiscall JAISound::getTrackPortRoute(unsigned char,
                                          unsigned char) */

int __thiscall JAISound::getTrackPortRoute(JAISound *this,uchar param_1,uchar param_2)

{
  if ((this->field_0xc & 0x800U) != 0) {
    return (param_1 >> 4) + 0x20000000 + (param_1 & 0xf) * 0x10 + (uint)param_2 * 0x10000;
  }
  return (param_1 & 0xf) + 0x10000000 + (uint)param_2 * 0x10000;
}


/* __thiscall JAISound::checkSoundHandle(unsigned long,
                                         void *) */

undefined4 __thiscall JAISound::checkSoundHandle(JAISound *this,ulong param_1,void *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((this->field_0xc & 0xc0000000U) == (param_1 & 0xc0000000)) {
    if (*(byte *)((int)param_2 + 4) < *(byte *)(*(int *)(this + 2) + 4)) {
      uVar1 = 1;
    }
    else {
      stop(this,0);
    }
  }
  else {
    stop(this,0);
  }
  return uVar1;
}


/* __thiscall JAISound::initParameter(JAISound * *,
                                      JAInter::Actor *,
                                      unsigned long,
                                      unsigned long,
                                      unsigned char,
                                      void *) */

void __thiscall
JAISound::initParameter
          (JAISound *this,JAISound **param_1,Actor *param_2,ulong param_3,ulong param_4,
          uchar param_5,void *param_6)

{
  undefined uVar1;
  
  this->field_0xc = param_3;
  if (param_2 == (Actor *)0x0) {
    *(undefined4 *)&this[1].field_0x4 = 0;
    *(undefined4 *)&this[1].field_0x8 = 0;
    this[1].field_0xc = 0;
    this->field_0x1c = 0;
  }
  else {
    *(undefined **)&this[1].field_0x4 = param_2->field_0x0;
    if (param_2->field_0x0 == (undefined *)0x0) {
      *(undefined4 *)&this[1].field_0x8 = 0;
      this[1].field_0xc = 0;
      this->field_0x1c = (int)param_2->field_0xc;
    }
    else {
      *(undefined **)&this[1].field_0x8 = param_2->field_0x4;
      this[1].field_0xc = (int)param_2->field_0x8;
      this->field_0x1c = (int)param_2->field_0xc;
    }
  }
  this[1].field_0x18 = (uint)param_1;
  *(ulong *)&this->field_0x14 = param_4;
  *(uchar *)&this->field_0x8 = param_5;
  *(void **)(this + 2) = param_6;
  *(undefined *)&this->field_0x6 = 10;
  uVar1 = JAIGlobalParameter::getParamDistanceParameterMoveTime((JAIGlobalParameter *)this);
  *(undefined *)&this->field_0x9 = uVar1;
  *(undefined2 *)&this->field_0xa = 0;
  this->field_0x18 = 0;
  if (param_1 != (JAISound **)0x0) {
    *param_1 = this;
  }
  return;
}


namespace JAInter {

/* __thiscall MoveParaSet::set(float,
                                        unsigned long) */

undefined4 __thiscall MoveParaSet::set(MoveParaSet *this,float param_1,ulong param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(this + 0xc) == 0) && (*(float *)(this + 4) == param_1)) {
    uVar1 = 2;
  }
  else {
    if ((*(int *)(this + 0xc) == 0) || (*(float *)this != param_1)) {
      *(float *)this = param_1;
      if (param_2 == 0) {
        *(float *)(this + 4) = param_1;
        uVar1 = 0;
      }
      else {
        if (param_2 == 1) {
          *(float *)(this + 8) = *(float *)(this + 4) - *(float *)this;
        }
        else {
          *(float *)(this + 8) =
               (*(float *)(this + 4) - *(float *)this) /
               (float)((double)CONCAT44(0x43300000,param_2) - JAudio::_1087);
        }
        *(ulong *)(this + 0xc) = param_2;
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 2;
    }
  }
  return uVar1;
}


/* __thiscall MoveParaSet::move(void) */

undefined4 __thiscall MoveParaSet::move(MoveParaSet *this)

{
  int iVar1;
  
  if (*(int *)(this + 0xc) == 0) {
    return 0;
  }
  iVar1 = *(int *)(this + 0xc) + -1;
  *(int *)(this + 0xc) = iVar1;
  if (iVar1 != 0) {
    *(float *)(this + 4) = *(float *)(this + 4) - *(float *)(this + 8);
    return 1;
  }
  *(undefined4 *)(this + 4) = *(undefined4 *)this;
  return 0;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall LinkSound::init(JAISound *,
                                       unsigned long) */

int __thiscall LinkSound::init(LinkSound *this,EVP_PKEY_CTX *ctx)

{
  JAIGlobalParameter *pJVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int in_r5;
  int iVar5;
  uint uVar6;
  
  JAIGlobalParameter::getParamAudioCameraMax((JAIGlobalParameter *)this);
  *(EVP_PKEY_CTX **)(this + 8) = ctx;
  *(undefined4 *)this = *(undefined4 *)(this + 8);
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(*(int *)(this + 8) + 0x30) = 0;
  *(int *)(*(int *)(this + 8) + 0x34) = *(int *)(this + 8) + 0x44;
  pJVar1 = *(JAIGlobalParameter **)(this + 8);
  pJVar1[5] = (JAIGlobalParameter)0x0;
  if ((_msCurrentHeap == 0) &&
     (pJVar1 = (JAIGlobalParameter *)
               m_Do_printf::OSReport
                         (
                         "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                         ), _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    pJVar1 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAIBasic.h",0x94,"Halt");
  }
  iVar5 = _msCurrentHeap;
  iVar2 = JAIGlobalParameter::getParamAudioCameraMax(pJVar1);
  uVar3 = JKernel::operator_new__(iVar2 * 0x1c,iVar5,0x20);
  *(undefined4 *)(*(int *)(this + 8) + 0x20) = uVar3;
  if ((*(int *)(*(int *)(this + 8) + 0x20) == 0) &&
     (m_Do_printf::OSReport("LinkSound::initLinkSound Cannot Alloc Heap!!\n"),
     *(int *)(*(int *)(this + 8) + 0x20) == 0)) {
    JUTAssertion::showAssert(3,"JAISound.cpp",0x824,"Buffer[0x00].mPositionInfo");
    m_Do_printf::OSPanic("JAISound.cpp",0x824,"Halt");
  }
  iVar5 = 0x44;
  for (uVar6 = 1; uVar6 < in_r5 - 1U; uVar6 = uVar6 + 1) {
    *(uint *)(*(int *)(this + 8) + iVar5 + 0x30) = *(int *)(this + 8) + (uVar6 - 1) * 0x44;
    *(uint *)(*(int *)(this + 8) + iVar5 + 0x34) = *(int *)(this + 8) + (uVar6 + 1) * 0x44;
    pJVar1 = *(JAIGlobalParameter **)(this + 8);
    pJVar1[iVar5 + 5] = (JAIGlobalParameter)0x0;
    if ((_msCurrentHeap == 0) &&
       (pJVar1 = (JAIGlobalParameter *)
                 m_Do_printf::OSReport
                           (
                           "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                           ), _msCurrentHeap == 0)) {
      JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
      pJVar1 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAIBasic.h",0x94,"Halt");
    }
    iVar2 = _msCurrentHeap;
    iVar4 = JAIGlobalParameter::getParamAudioCameraMax(pJVar1);
    uVar3 = JKernel::operator_new__(iVar4 * 0x1c,iVar2,0x20);
    *(undefined4 *)(*(int *)(this + 8) + iVar5 + 0x20) = uVar3;
    if ((*(int *)(*(int *)(this + 8) + iVar5 + 0x20) == 0) &&
       (m_Do_printf::OSReport("LinkSound::initLinkSound Cannot Alloc Heap!!\n"),
       *(int *)(*(int *)(this + 8) + iVar5 + 0x20) == 0)) {
      JUTAssertion::showAssert(3,"JAISound.cpp",0x82c,"Buffer[i].mPositionInfo");
      m_Do_printf::OSPanic("JAISound.cpp",0x82c,"Halt");
    }
    iVar5 = iVar5 + 0x44;
  }
  iVar5 = uVar6 * 0x44;
  *(uint *)(*(int *)(this + 8) + iVar5 + 0x30) = *(int *)(this + 8) + (uVar6 - 1) * 0x44;
  *(undefined4 *)(*(int *)(this + 8) + iVar5 + 0x34) = 0;
  pJVar1 = (JAIGlobalParameter *)(*(int *)(this + 8) + iVar5);
  pJVar1[5] = (JAIGlobalParameter)0x0;
  if ((_msCurrentHeap == 0) &&
     (pJVar1 = (JAIGlobalParameter *)
               m_Do_printf::OSReport
                         (
                         "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                         ), _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    pJVar1 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAIBasic.h",0x94,"Halt");
  }
  iVar2 = _msCurrentHeap;
  iVar4 = JAIGlobalParameter::getParamAudioCameraMax(pJVar1);
  uVar3 = JKernel::operator_new__(iVar4 * 0x1c,iVar2,0x20);
  *(undefined4 *)(*(int *)(this + 8) + iVar5 + 0x20) = uVar3;
  iVar2 = *(int *)(this + 8) + iVar5;
  if (*(int *)(iVar2 + 0x20) == 0) {
    m_Do_printf::OSReport("LinkSound::initLinkSound Cannot Alloc Heap!!\n");
    iVar2 = *(int *)(this + 8) + iVar5;
    if (*(int *)(iVar2 + 0x20) == 0) {
      JUTAssertion::showAssert(3,"JAISound.cpp",0x833,"Buffer[i].mPositionInfo");
      iVar2 = m_Do_printf::OSPanic("JAISound.cpp",0x833,"Halt");
    }
  }
  return iVar2;
}


/* __thiscall LinkSound::getSound(void) */

int __thiscall LinkSound::getSound(LinkSound *this)

{
  int iVar1;
  
  iVar1 = *(int *)this;
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    *(undefined4 *)this = *(undefined4 *)(iVar1 + 0x34);
    if (*(int *)(this + 4) == 0) {
      *(undefined4 *)(iVar1 + 0x34) = 0;
    }
    else {
      *(int *)(iVar1 + 0x34) = *(int *)(this + 4);
      *(int *)(*(int *)(this + 4) + 0x30) = iVar1;
    }
    *(undefined4 *)(iVar1 + 0x30) = 0;
    *(int *)(this + 4) = iVar1;
  }
  return iVar1;
}


/* __thiscall LinkSound::releaseSound(JAISound *) */

void __thiscall LinkSound::releaseSound(LinkSound *this,JAISound *param_1)

{
  param_1[1].field_0x18 = 0;
  if (*(JAISound **)(this + 4) == param_1) {
    *(undefined4 *)(this + 4) = *(undefined4 *)&param_1[1].field_0x14;
    if (*(int *)&param_1[1].field_0x14 != 0) {
      *(undefined4 *)(*(int *)&param_1[1].field_0x14 + 0x30) = 0;
    }
  }
  else {
    *(undefined4 *)(*(int *)&param_1[1].field_0x10 + 0x34) = *(undefined4 *)&param_1[1].field_0x14;
    if (*(int *)&param_1[1].field_0x14 != 0) {
      *(undefined4 *)(*(int *)&param_1[1].field_0x14 + 0x30) = *(undefined4 *)&param_1[1].field_0x10
      ;
    }
  }
  *(undefined4 *)&param_1[1].field_0x14 = *(undefined4 *)this;
  if (*(int *)&param_1[1].field_0x14 != 0) {
    *(JAISound **)(*(int *)&param_1[1].field_0x14 + 0x30) = param_1;
  }
  *(JAISound **)this = param_1;
  return;
}

