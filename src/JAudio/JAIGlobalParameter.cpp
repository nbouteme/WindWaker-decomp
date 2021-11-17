#include <JAudio/JAIGlobalParameter.h>
#include <JAudio/JAIStreamMgr.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <m_Do_printf.h>
#include <JUtility/JUTAssert.h>
#include <JAudio/JASDriverIF.h>
#include <JAudio/JAISoundTable.h>
#include <JAIGlobalParameter.h>

undefined1 JAIGlobalParameter;
undefined1 JAIGlobalParameter;
undefined1 JAIGlobalParameter;

namespace JAIGlobalParameter {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall setParamInitDataPointer(void *) */

void setParamInitDataPointer(void *param_1)

{
  _aafPointer = param_1;
  *(undefined *)(_msBasic + 0xc) = 4;
  return;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamInterfaceHeapSize(unsigned long) */

void __thiscall
JAIGlobalParameter::setParamInterfaceHeapSize(JAIGlobalParameter *this,ulong param_1)

{
  _interfaceHeapSize = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamSoundSceneMax(unsigned long) */

void __thiscall JAIGlobalParameter::setParamSoundSceneMax(JAIGlobalParameter *this,ulong param_1)

{
  _soundSceneMax = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamSeRegistMax(unsigned long) */

void __thiscall JAIGlobalParameter::setParamSeRegistMax(JAIGlobalParameter *this,ulong param_1)

{
  _seRegistMax = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamSeTrackMax(unsigned long) */

void __thiscall JAIGlobalParameter::setParamSeTrackMax(JAIGlobalParameter *this,ulong param_1)

{
  _seTrackMax = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamSeqPlayTrackMax(unsigned long) */

void __thiscall JAIGlobalParameter::setParamSeqPlayTrackMax(JAIGlobalParameter *this,ulong param_1)

{
  _seqPlayTrackMax = this;
  _seqControlBufferMax = (int)this << 1;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamSeqControlBufferMax(unsigned long) */

void __thiscall
JAIGlobalParameter::setParamSeqControlBufferMax(JAIGlobalParameter *this,ulong param_1)

{
  _seqControlBufferMax = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamStreamControlBufferMax(unsigned long) */

void __thiscall
JAIGlobalParameter::setParamStreamControlBufferMax(JAIGlobalParameter *this,ulong param_1)

{
  _streamControlBufferMax = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamAutoHeapMax(unsigned long) */

void __thiscall JAIGlobalParameter::setParamAutoHeapMax(JAIGlobalParameter *this,ulong param_1)

{
  _autoHeapMax = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamStayHeapMax(unsigned long) */

void __thiscall JAIGlobalParameter::setParamStayHeapMax(JAIGlobalParameter *this,ulong param_1)

{
  _stayHeapMax = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamInputGainDown(float) */

void __thiscall JAIGlobalParameter::setParamInputGainDown(JAIGlobalParameter *this,float param_1)

{
  _inputGainDown = param_1;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamOutputGainUp(float) */

void __thiscall JAIGlobalParameter::setParamOutputGainUp(JAIGlobalParameter *this,float param_1)

{
  _outputGainUp = param_1;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamDistanceMax(float) */

void __thiscall JAIGlobalParameter::setParamDistanceMax(JAIGlobalParameter *this,float param_1)

{
  _distanceMax = param_1;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamMaxVolumeDistance(float) */

void __thiscall
JAIGlobalParameter::setParamMaxVolumeDistance(JAIGlobalParameter *this,float param_1)

{
  _maxVolumeDistance = param_1;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamMinDistanceVolume(float) */

void __thiscall
JAIGlobalParameter::setParamMinDistanceVolume(JAIGlobalParameter *this,float param_1)

{
  _minDistanceVolume = param_1;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamSeDistanceFxParameter(unsigned short) */

void __thiscall
JAIGlobalParameter::setParamSeDistanceFxParameter(JAIGlobalParameter *this,ushort param_1)

{
  _seDistanceFxParameter = (short)this;
  return;
}


/* __thiscall JAIGlobalParameter::setParamStreamDecodedBufferBlocks(unsigned long) */

void __thiscall
JAIGlobalParameter::setParamStreamDecodedBufferBlocks(JAIGlobalParameter *this,ulong param_1)

{
  JAInter::StreamLib::setDecodedBufferBlocks((StreamLib *)this,param_1);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamStreamInsideBufferCut(bool) */

void __thiscall
JAIGlobalParameter::setParamStreamInsideBufferCut(JAIGlobalParameter *this,bool param_1)

{
  *(byte *)(_msBasic + 0xe) =
       (byte)(((uint)this & 0xff) << 3) & 8 | *(byte *)(_msBasic + 0xe) & 0xf7;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamAutoHeapRoomSize(unsigned long) */

void __thiscall JAIGlobalParameter::setParamAutoHeapRoomSize(JAIGlobalParameter *this,ulong param_1)

{
  _autoHeapRoomSize = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamStayHeapSize(unsigned long) */

void __thiscall JAIGlobalParameter::setParamStayHeapSize(JAIGlobalParameter *this,ulong param_1)

{
  _stayHeapSize = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamSeDolbyCenterValue(unsigned char) */

void __thiscall
JAIGlobalParameter::setParamSeDolbyCenterValue(JAIGlobalParameter *this,uchar param_1)

{
  _seDolbyCenterValue = (float)((double)CONCAT44(0x43300000,(uint)this & 0xff) - JAudio::_855);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamSeDolbyFrontDistanceMax(float) */

void __thiscall
JAIGlobalParameter::setParamSeDolbyFrontDistanceMax(JAIGlobalParameter *this,float param_1)

{
  _seDolbyFrontDistanceMax = param_1;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamSeDolbyBehindDistanceMax(float) */

void __thiscall
JAIGlobalParameter::setParamSeDolbyBehindDistanceMax(JAIGlobalParameter *this,float param_1)

{
  _seDolbyBehindDistanceMax = param_1;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamInitDataFileName(char *) */

void __thiscall JAIGlobalParameter::setParamInitDataFileName(JAIGlobalParameter *this,char *param_1)

{
  _initDataFileName = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamWavePath(char *) */

void __thiscall JAIGlobalParameter::setParamWavePath(JAIGlobalParameter *this,char *param_1)

{
  _wavePath = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamSequenceArchivesPath(char *) */

void __thiscall
JAIGlobalParameter::setParamSequenceArchivesPath(JAIGlobalParameter *this,char *param_1)

{
  _sequenceArchivesPath = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamStreamPath(char *) */

void __thiscall JAIGlobalParameter::setParamStreamPath(JAIGlobalParameter *this,char *param_1)

{
  _streamPath = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamAudioResPath(char *) */

void __thiscall JAIGlobalParameter::setParamAudioResPath(JAIGlobalParameter *this,char *param_1)

{
  _audioResPath = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamSequenceArchivesFileName(char *) */

void __thiscall
JAIGlobalParameter::setParamSequenceArchivesFileName(JAIGlobalParameter *this,char *param_1)

{
  _sequenceArchivesFileName = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamDummyObjectLifeTime(unsigned long) */

void __thiscall
JAIGlobalParameter::setParamDummyObjectLifeTime(JAIGlobalParameter *this,ulong param_1)

{
  _dummyObjectLifeTime = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamDummyObjectMax(unsigned long) */

void __thiscall JAIGlobalParameter::setParamDummyObjectMax(JAIGlobalParameter *this,ulong param_1)

{
  _dummyObjectMax = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamAudioCameraMax(unsigned long) */

void __thiscall JAIGlobalParameter::setParamAudioCameraMax(JAIGlobalParameter *this,ulong param_1)

{
  _audioCameraMax = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamSystemTrackMax(long) */

void __thiscall JAIGlobalParameter::setParamSystemTrackMax(JAIGlobalParameter *this,long param_1)

{
  _systemTrackMax = this;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::setParamSoundOutputMode(unsigned long) */

void __thiscall JAIGlobalParameter::setParamSoundOutputMode(JAIGlobalParameter *this,ulong param_1)

{
  ulong extraout_r4;
  ulong extraout_r4_00;
  StreamLib *this_00;
  Driver *this_01;
  
  this_01 = (Driver *)&DAT_00000001;
  this_00 = (StreamLib *)0x0;
  if (this == (JAIGlobalParameter *)&DAT_00000001) {
    this_01 = (Driver *)&DAT_00000001;
    this_00 = (StreamLib *)&DAT_00000001;
  }
  else {
    if ((int)this < 1) {
      if (-1 < (int)this) {
        this_01 = (Driver *)0x0;
        this_00 = (StreamLib *)0x0;
        goto LAB_80292304;
      }
    }
    else {
      if ((int)this < 3) {
        this_01 = (Driver *)&DAT_00000002;
        this_00 = (StreamLib *)&DAT_00000001;
        goto LAB_80292304;
      }
    }
    m_Do_printf::OSReport
              ("JAIGlobalParameter::setParamSoundOutputMode 出力モードが不正です。\n");
    JUTAssertion::showAssert(3,"JAIGlobalParameter.cpp",0x159,"0");
    m_Do_printf::OSPanic("JAIGlobalParameter.cpp",0x159,"Halt");
    param_1 = extraout_r4;
  }
LAB_80292304:
  *(char *)(_msBasic + 0xd) = (char)this;
  JASystem::Driver::setOutputMode(this_01,param_1);
  JAInter::StreamLib::setOutputMode(this_00,extraout_r4_00);
  return;
}


/* __thiscall JAIGlobalParameter::getParamSeCategoryMax(void) */

undefined __thiscall JAIGlobalParameter::getParamSeCategoryMax(JAIGlobalParameter *this)

{
  undefined uVar1;
  
  uVar1 = JAInter::SoundTable::getCategotyMax();
  return uVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamSoundSceneMax(void) */

undefined4 __thiscall JAIGlobalParameter::getParamSoundSceneMax(JAIGlobalParameter *this)

{
  return _soundSceneMax;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamSeRegistMax(void) */

undefined4 __thiscall JAIGlobalParameter::getParamSeRegistMax(JAIGlobalParameter *this)

{
  return _seRegistMax;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamSeTrackMax(void) */

undefined4 __thiscall JAIGlobalParameter::getParamSeTrackMax(JAIGlobalParameter *this)

{
  return _seTrackMax;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamSeqTrackMax(void) */

undefined4 __thiscall JAIGlobalParameter::getParamSeqTrackMax(JAIGlobalParameter *this)

{
  return _seqTrackMax;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamSeqControlBufferMax(void) */

undefined4 __thiscall JAIGlobalParameter::getParamSeqControlBufferMax(JAIGlobalParameter *this)

{
  return _seqControlBufferMax;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamStreamControlBufferMax(void) */

undefined4 __thiscall JAIGlobalParameter::getParamStreamControlBufferMax(JAIGlobalParameter *this)

{
  return _streamControlBufferMax;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamStreamParameterBufferMax(void) */

undefined4 __thiscall JAIGlobalParameter::getParamStreamParameterBufferMax(JAIGlobalParameter *this)

{
  return _streamParameterBufferMax;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamAutoHeapMax(void) */

undefined4 __thiscall JAIGlobalParameter::getParamAutoHeapMax(JAIGlobalParameter *this)

{
  return _autoHeapMax;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamStayHeapMax(void) */

undefined4 __thiscall JAIGlobalParameter::getParamStayHeapMax(JAIGlobalParameter *this)

{
  return _stayHeapMax;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamSeqPlayTrackMax(void) */

undefined4 __thiscall JAIGlobalParameter::getParamSeqPlayTrackMax(JAIGlobalParameter *this)

{
  return _seqPlayTrackMax;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamDistanceMax(void) */

double __thiscall JAIGlobalParameter::getParamDistanceMax(JAIGlobalParameter *this)

{
  return (double)_distanceMax;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamMaxVolumeDistance(void) */

double __thiscall JAIGlobalParameter::getParamMaxVolumeDistance(JAIGlobalParameter *this)

{
  return (double)_maxVolumeDistance;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamMinDistanceVolume(void) */

double __thiscall JAIGlobalParameter::getParamMinDistanceVolume(JAIGlobalParameter *this)

{
  return (double)_minDistanceVolume;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamAutoHeapRoomSize(void) */

undefined4 __thiscall JAIGlobalParameter::getParamAutoHeapRoomSize(JAIGlobalParameter *this)

{
  return _autoHeapRoomSize;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamStayHeapSize(void) */

undefined4 __thiscall JAIGlobalParameter::getParamStayHeapSize(JAIGlobalParameter *this)

{
  return _stayHeapSize;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamSeDolbyCenterValue(void) */

double __thiscall JAIGlobalParameter::getParamSeDolbyCenterValue(JAIGlobalParameter *this)

{
  return (double)_seDolbyCenterValue;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamSeDolbyFrontDistanceMax(void) */

double __thiscall JAIGlobalParameter::getParamSeDolbyFrontDistanceMax(JAIGlobalParameter *this)

{
  return (double)_seDolbyFrontDistanceMax;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamSeDolbyBehindDistanceMax(void) */

double __thiscall JAIGlobalParameter::getParamSeDolbyBehindDistanceMax(JAIGlobalParameter *this)

{
  return (double)_seDolbyBehindDistanceMax;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamInitDataFileName(void) */

undefined4 __thiscall JAIGlobalParameter::getParamInitDataFileName(JAIGlobalParameter *this)

{
  return _initDataFileName;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamWavePath(void) */

undefined4 __thiscall JAIGlobalParameter::getParamWavePath(JAIGlobalParameter *this)

{
  return _wavePath;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamSequenceArchivesPath(void) */

undefined4 __thiscall JAIGlobalParameter::getParamSequenceArchivesPath(JAIGlobalParameter *this)

{
  return _sequenceArchivesPath;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamStreamPath(void) */

undefined4 __thiscall JAIGlobalParameter::getParamStreamPath(JAIGlobalParameter *this)

{
  return _streamPath;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamAudioResPath(void) */

undefined4 __thiscall JAIGlobalParameter::getParamAudioResPath(JAIGlobalParameter *this)

{
  return _audioResPath;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamSequenceArchivesFileName(void) */

undefined4 __thiscall JAIGlobalParameter::getParamSequenceArchivesFileName(JAIGlobalParameter *this)

{
  return _sequenceArchivesFileName;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamDopplarMoveTime(void) */

undefined4 __thiscall JAIGlobalParameter::getParamDopplarMoveTime(JAIGlobalParameter *this)

{
  return _dopplarMoveTime;
}


/* __thiscall JAIGlobalParameter::getParamDistanceParameterMoveTime(void) */

undefined __thiscall JAIGlobalParameter::getParamDistanceParameterMoveTime(JAIGlobalParameter *this)

{
  return distanceParameterMoveTime;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamDummyObjectMax(void) */

undefined4 __thiscall JAIGlobalParameter::getParamDummyObjectMax(JAIGlobalParameter *this)

{
  return _dummyObjectMax;
}


/* __thiscall JAIGlobalParameter::getParamSeqMuteVolumeSePlay(void) */

undefined __thiscall JAIGlobalParameter::getParamSeqMuteVolumeSePlay(JAIGlobalParameter *this)

{
  return seqMuteVolumeSePlay;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamSeqMuteMoveSpeedSePlay(void) */

undefined4 __thiscall JAIGlobalParameter::getParamSeqMuteMoveSpeedSePlay(JAIGlobalParameter *this)

{
  return _seqMuteMoveSpeedSePlay;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamAudioCameraMax(void) */

undefined4 __thiscall JAIGlobalParameter::getParamAudioCameraMax(JAIGlobalParameter *this)

{
  return _audioCameraMax;
}


/* __thiscall JAIGlobalParameter::getParamSeqParameterLines(void) */

undefined __thiscall JAIGlobalParameter::getParamSeqParameterLines(JAIGlobalParameter *this)

{
  return seqParameterLines;
}


/* __thiscall JAIGlobalParameter::getParamStreamParameterLines(void) */

undefined __thiscall JAIGlobalParameter::getParamStreamParameterLines(JAIGlobalParameter *this)

{
  return streamParameterLines;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIGlobalParameter::getParamSeDistanceWaitMax(void) */

undefined2 __thiscall JAIGlobalParameter::getParamSeDistanceWaitMax(JAIGlobalParameter *this)

{
  return _seDistanceWaitMax;
}

