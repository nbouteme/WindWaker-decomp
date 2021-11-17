#include <JAudio/JASHardStream.h>
#include <JAudio/JASHardStream.h>
#include <dvd/dvd.h>
#include <ai/ai.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <dvd/dvdfs.h>
#include <m_Do_printf.h>
#include <JUtility/JUTAssert.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JKernel/JKRHeap.h>
#include <JASystem/HardStream.h>
#include <Demangler/JASystem/HardStream/TControl.h>


namespace JASystem {
undefined1 HardStream;
}

namespace JAudio {
undefined finfo$822;
undefined get_addr_cmd$826;
undefined stop_cmd$827;
undefined finish_cmd$828;
}

namespace JASystem {
undefined1 HardStream;
undefined1 HardStream;
undefined1 HardStream;
}

namespace JAudio {
undefined4 cur_finfo$823;
undefined1 init$824;
undefined1 cur_addr_cmd$829;
undefined1 init$830;
undefined4 last_frame$988;
undefined1 init$989;
}

namespace JASystem {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall HardStream::unregistBgmAll(void) */

undefined4 __thiscall HardStream::unregistBgmAll(HardStream *this)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (DAT_803e8d70 == 0) {
    return 0;
  }
  DAT_803e8d70 = 0;
  iVar1 = 0;
  for (iVar3 = 0; iVar3 < _playListMax; iVar3 = iVar3 + 1) {
    puVar2 = (undefined4 *)(_playList + iVar1);
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    iVar1 = iVar1 + 0xc;
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall HardStream::main(void) */

void __thiscall HardStream::main(HardStream *this)

{
  undefined4 uVar1;
  ushort uVar3;
  int iVar2;
  
  if (JAudio::init_824 == '\0') {
    JAudio::cur_finfo_823 = 0;
    JAudio::init_824 = '\x01';
  }
  if (JAudio::init_830 == '\0') {
    JAudio::cur_addr_cmd_829 = 0;
    JAudio::init_830 = '\x01';
  }
  if (useHardStreaming != '\0') {
LAB_8027bf10:
    switch(DAT_803e8d77) {
    case 1:
      if (DAT_803e8d70 == (int *)0x0) {
        return;
      }
      uVar3 = TControl::getIntroNum((TControl *)&strCtrl);
      if (uVar3 == 0xffff) {
        uVar3 = TControl::getLoopNum((TControl *)&strCtrl);
        iVar2 = TControl::startFirst
                          ((TControl *)&strCtrl,uVar3,(DVDFileInfo *)&JAudio::finfo_822,
                           &JAudio::cur_finfo_823);
        if (iVar2 == 0) {
          DAT_803e8d77 = 0;
          return;
        }
        TControl::clearListOne((TControl *)&strCtrl);
        DAT_803e8d74 = 1;
      }
      else {
        iVar2 = TControl::startFirst
                          ((TControl *)&strCtrl,uVar3,(DVDFileInfo *)&JAudio::finfo_822,
                           &JAudio::cur_finfo_823);
        if (iVar2 == 0) {
          DAT_803e8d77 = 0;
          return;
        }
        DAT_803e8d74 = 0;
      }
      DAT_803e8d77 = 3;
      return;
    case 2:
      if ((DAT_803e8d74 == 0) &&
         (uVar3 = TControl::getLoopNum((TControl *)&strCtrl), uVar3 != 0xffff)) {
        iVar2 = TControl::startSecond
                          ((TControl *)&strCtrl,uVar3,(DVDFileInfo *)&JAudio::finfo_822,
                           &JAudio::cur_finfo_823);
        if (iVar2 == 0) {
          DAT_803e8d77 = 0;
          return;
        }
        TControl::clearListOne((TControl *)&strCtrl);
        DAT_803e8d74 = 1;
        DAT_803e8d77 = 4;
        return;
      }
      TControl::clearListOne((TControl *)&strCtrl);
      if (DAT_803e8d70 == (int *)0x0) {
        if (DAT_803e8d74 == 0) {
          dvd::DVDStopStreamAtEndAsync(&JAudio::stop_cmd_827,0);
          DAT_803e8d74 = 2;
          DAT_803e8d77 = 4;
          return;
        }
        DAT_803e8d74 = 3;
        DAT_803e8d77 = 4;
        return;
      }
      uVar3 = TControl::getIntroNum((TControl *)&strCtrl);
      if (uVar3 == 0xffff) {
        uVar3 = TControl::getLoopNum((TControl *)&strCtrl);
        iVar2 = TControl::startSecond
                          ((TControl *)&strCtrl,uVar3,(DVDFileInfo *)&JAudio::finfo_822,
                           &JAudio::cur_finfo_823);
        if (iVar2 == 0) {
          DAT_803e8d77 = 0;
          return;
        }
        TControl::clearListOne((TControl *)&strCtrl);
        DAT_803e8d74 = 1;
      }
      else {
        iVar2 = TControl::startSecond
                          ((TControl *)&strCtrl,uVar3,(DVDFileInfo *)&JAudio::finfo_822,
                           &JAudio::cur_finfo_823);
        if (iVar2 == 0) {
          DAT_803e8d77 = 0;
          return;
        }
        DAT_803e8d74 = 0;
      }
      DAT_803e8d77 = 4;
      return;
    case 4:
      uVar1 = TControl::getCurVol((TControl *)&strCtrl);
      ai::AISetStreamVolLeft();
      ai::AISetStreamVolRight(uVar1);
      dvd::DVDGetStreamPlayAddrAsync
                (&JAudio::get_addr_cmd_826 + (uint)JAudio::cur_addr_cmd_829 * 0x30,getAddrCallback);
      JAudio::cur_addr_cmd_829 = JAudio::cur_addr_cmd_829 + 1 & 0xf;
      return;
    case 5:
      if (DAT_803e8d70 == (int *)0x0) {
        if (DAT_803e8d74 != 2) {
          DAT_803e8d74 = 3;
        }
        DAT_803e8d77 = 4;
        return;
      }
      if (DAT_803e8d74 == 0) {
        if (*(short *)(*DAT_803e8d70 + 6) != -1) {
          uVar3 = TControl::getLoopNum((TControl *)&strCtrl);
          iVar2 = TControl::startSecond
                            ((TControl *)&strCtrl,uVar3,(DVDFileInfo *)&JAudio::finfo_822,
                             &JAudio::cur_finfo_823);
          if (iVar2 == 0) {
            DAT_803e8d77 = 0;
            return;
          }
          TControl::clearListOne((TControl *)&strCtrl);
          DAT_803e8d74 = 1;
          DAT_803e8d77 = 4;
          return;
        }
        if (DAT_803e8d70[1] == 0) {
          dvd::DVDStopStreamAtEndAsync(&JAudio::stop_cmd_827,0);
          TControl::clearListOne((TControl *)&strCtrl);
          DAT_803e8d74 = 2;
          DAT_803e8d77 = 4;
          return;
        }
        TControl::clearListOne((TControl *)&strCtrl);
        DAT_803e8d74 = 1;
      }
      else {
        if (DAT_803e8d70 == (int *)0x0) {
          DAT_803e8d74 = 3;
          DAT_803e8d77 = 4;
          return;
        }
        uVar3 = TControl::getIntroNum((TControl *)&strCtrl);
        if (uVar3 != 0xffff) {
          iVar2 = TControl::startSecond
                            ((TControl *)&strCtrl,uVar3,(DVDFileInfo *)&JAudio::finfo_822,
                             &JAudio::cur_finfo_823);
          if (iVar2 != 0) {
            DAT_803e8d74 = 0;
            DAT_803e8d77 = 4;
            return;
          }
          DAT_803e8d77 = 0;
          return;
        }
        DAT_803e8d74 = 0;
      }
      goto LAB_8027bf10;
    case 6:
      ai::AISetStreamVolLeft(0);
      ai::AISetStreamVolRight(0);
      ai::AISetStreamPlayState(0);
      dvd::DVDCancelStreamAsync(&JAudio::finish_cmd_828,0);
      DAT_803e8d77 = 0;
      DAT_803e8d74 = 0;
      TControl::resetFader((TControl *)&strCtrl);
      DAT_803e8d76 = 0;
    }
  }
  return;
}


/* __thiscall HardStream::firstBgmCallback(long,
                                                     DVDFileInfo *) */

void __thiscall
HardStream::firstBgmCallback(HardStream *this,long param_1,DVDFileInfo *param_2)

{
  undefined4 uVar1;
  
  if (DAT_803e8d76 == '\0') {
    uVar1 = TControl::getCurVol((TControl *)&strCtrl);
    ai::AISetStreamVolLeft();
    ai::AISetStreamVolRight(uVar1);
    ai::AISetStreamSampleRate(1);
    ai::AIResetStreamSampleCount();
    ai::AISetStreamPlayState(1);
    DAT_803e8d77 = 2;
  }
  else {
    DAT_803e8d77 = 4;
    DAT_803e8d76 = '\0';
  }
  return;
}


/* __thiscall HardStream::secondBgmCallback(long,
                                                      DVDFileInfo *) */

void __thiscall
HardStream::secondBgmCallback(HardStream *this,long param_1,DVDFileInfo *param_2)

{
  DAT_803e8d77 = 4;
  return;
}


/* __thiscall HardStream::getAddrCallback(long,
                                                    DVDCommandBlock *) */

void __thiscall
HardStream::getAddrCallback(HardStream *this,long param_1,DVDCommandBlock *param_2)

{
  HardStream *pHVar1;
  
  if (JAudio::init_989 == '\0') {
    JAudio::last_frame_988 = 0;
    JAudio::init_989 = '\x01';
  }
  if (DAT_803e8d74 == 3) {
    if (this == *(HardStream **)(&DAT_803e8db0 + (DAT_803e8db8 ^ 1) * 4)) {
      JAudio::last_frame_988 = 1;
    }
    else {
      if (JAudio::last_frame_988 != 0) {
        JAudio::last_frame_988 = 0;
        DAT_803e8d77 = 5;
      }
    }
  }
  else {
    if (DAT_803e8d74 == 2) {
      if (this == (HardStream *)(*(int *)(&DAT_803e8db0 + (DAT_803e8db8 ^ 1) * 4) + -0x8000)) {
        JAudio::last_frame_988 = 1;
      }
      else {
        if (JAudio::last_frame_988 != 0) {
          DAT_803e8d77 = 6;
          unregistBgmAll((HardStream *)&strCtrl);
          JAudio::last_frame_988 = 0;
        }
      }
    }
    else {
      pHVar1 = (HardStream *)TControl::getLastAddr((TControl *)&strCtrl);
      if (this == pHVar1) {
        JAudio::last_frame_988 = 1;
      }
      else {
        if (JAudio::last_frame_988 != 0) {
          JAudio::last_frame_988 = 0;
          DAT_803e8d77 = 5;
        }
      }
    }
  }
  return;
}


namespace HardStream {

/* __thiscall TControl::TControl(void) */

void __thiscall TControl::TControl(TControl *this)

{
  float fVar1;
  float fVar2;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  this[10] = (TControl)0x0;
  *(undefined2 *)(this + 8) = 0;
  this[0xb] = (TControl)0x0;
  fVar2 = JAudio::_1025;
  *(float *)(this + 0xc) = JAudio::_1025;
  fVar1 = JAudio::_648;
  *(float *)(this + 0x10) = JAudio::_648;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(float *)(this + 0x20) = fVar1;
  *(float *)(this + 0x24) = fVar1;
  *(float *)(this + 0x2c) = fVar2;
  *(float *)(this + 0x30) = fVar2;
  *(float *)(this + 0x28) = fVar2;
  *(float *)(this + 0x34) = fVar1;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  this[0x4c] = (TControl)0x0;
  return;
}


/* __thiscall TControl::getIntroNum(void) */

undefined2 __thiscall TControl::getIntroNum(TControl *this)

{
  int iVar1;
  
  if (*(int **)(this + 4) == (int *)0x0) {
    return 0xffff;
  }
  iVar1 = **(int **)(this + 4);
  if (iVar1 == 0) {
    return 0xffff;
  }
  return *(undefined2 *)(iVar1 + 4);
}


/* __thiscall TControl::getLoopNum(void) */

undefined2 __thiscall TControl::getLoopNum(TControl *this)

{
  int iVar1;
  
  if (*(int **)(this + 4) == (int *)0x0) {
    return 0xffff;
  }
  iVar1 = **(int **)(this + 4);
  if (iVar1 == 0) {
    return 0xffff;
  }
  return *(undefined2 *)(iVar1 + 6);
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TControl::fileOpen(unsigned short,
                                                       DVDFileInfo *) */

bool __thiscall
TControl::fileOpen(TControl *this,ushort param_1,DVDFileInfo *param_2)

{
  bool bVar1;
  char *__src;
  char acStack72 [64];
  
  __src = (char *)(_streamFiles + (uint)param_1 * 0x24);
  MSL_C.PPCEABI.bare.H::strcpy(acStack72,&rootDir);
  MSL_C.PPCEABI.bare.H::strcat(acStack72,__src);
  bVar1 = dvd::DVDOpen(acStack72,(int)param_2);
  if (bVar1 == false) {
    m_Do_printf::OSReport("[JASHardStream::main] ファイルが開けません。(%s)\n",acStack72)
    ;
  }
  return bVar1 != false;
}


/* __thiscall TControl::clearListOne(void) */

undefined4 __thiscall TControl::clearListOne(TControl *this)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(this + 4);
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  *(undefined4 *)(this + 4) = puVar1[1];
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  return 1;
}


/* __thiscall TControl::setLastAddr(DVDFileInfo *) */

void __thiscall TControl::setLastAddr(TControl *this,DVDFileInfo *param_1)

{
  ulong uVar1;
  
  if (param_1 == (DVDFileInfo *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASHardStream.cpp",0x38a,"finfo != 0");
    m_Do_printf::OSPanic("JASHardStream.cpp",0x38a,&DAT_80366e31);
  }
  *(int *)(this + (uint)(byte)this[0x4c] * 4 + 0x44) =
       *(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x34) + -0x8000;
  this[0x4c] = (TControl)((byte)this[0x4c] ^ 1);
  return;
}


/* __thiscall TControl::getLastAddr(void) */

undefined4 __thiscall TControl::getLastAddr(TControl *this)

{
  return *(undefined4 *)(this + (uint)(byte)this[0x4c] * 4 + 0x44);
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TControl::startFirst(unsigned short,
                                                         DVDFileInfo *,
                                                         unsigned long *) */

bool __thiscall
TControl::startFirst
          (TControl *this,ushort param_1,DVDFileInfo *param_2,ulong *param_3)

{
  int iVar1;
  
  iVar1 = fileOpen(this,param_1,param_2 + *param_3 * 0x3c);
  if (iVar1 != 0) {
    setLastAddr(this,param_2 + *param_3 * 0x3c);
    dvd::DVDPrepareStreamAsync(param_2 + *param_3 * 0x3c,0,0,firstBgmCallback);
    *param_3 = *param_3 + 1;
    *param_3 = *param_3 % 3;
  }
  return iVar1 != 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TControl::startSecond(unsigned short,
                                                          DVDFileInfo *,
                                                          unsigned long *) */

bool __thiscall
TControl::startSecond
          (TControl *this,ushort param_1,DVDFileInfo *param_2,ulong *param_3)

{
  int iVar1;
  
  iVar1 = fileOpen(this,param_1,param_2 + *param_3 * 0x3c);
  if (iVar1 != 0) {
    setLastAddr(this,param_2 + *param_3 * 0x3c);
    dvd::DVDPrepareStreamAsync(param_2 + *param_3 * 0x3c,0,0,secondBgmCallback);
    *param_3 = *param_3 + 1;
    *param_3 = *param_3 % 3;
  }
  return iVar1 != 0;
}


/* __thiscall TControl::resetFader(void) */

void __thiscall TControl::resetFader(TControl *this)

{
  float fVar1;
  
  *(undefined4 *)(this + 0x14) = 0;
  fVar1 = JAudio::_648;
  *(float *)(this + 0x20) = JAudio::_648;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(float *)(this + 0x24) = fVar1;
  *(undefined4 *)(this + 0x3c) = 0;
  fVar1 = JAudio::_1025;
  *(float *)(this + 0x30) = JAudio::_1025;
  *(float *)(this + 0x2c) = fVar1;
  *(float *)(this + 0x28) = fVar1;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  return;
}


/* __thiscall TControl::getCurVol(void) */

void __thiscall TControl::getCurVol(TControl *this)

{
  calcCurVolume(this);
  volFloatToU8(this,*(float *)(this + 0x10));
  return;
}


/* WARNING: Removing unreachable block (ram,0x8027cb38) */
/* WARNING: Removing unreachable block (ram,0x8027cb30) */
/* WARNING: Removing unreachable block (ram,0x8027cb40) */
/* __thiscall TControl::calcCurVolume(void) */

void __thiscall TControl::calcCurVolume(TControl *this)

{
  float fVar1;
  HardStream *this_00;
  uint uVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
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
  dVar7 = (double)JAudio::_1025;
  dVar6 = dVar7;
  if (*(int *)(this + 0x14) != 0) {
    if (*(int *)(this + 0x38) == 0) {
      *(float *)(this + 0x20) =
           (float)(dVar7 / (double)(float)((double)CONCAT44(0x43300000,*(int *)(this + 0x14)) -
                                          JAudio::_1135));
    }
    dVar6 = (double)(*(float *)(this + 0x20) *
                    (float)((double)CONCAT44(0x43300000,*(int *)(this + 0x38)) - JAudio::_1135));
    dVar4 = (double)JAudio::_1025;
    if (dVar6 < dVar4) {
      *(int *)(this + 0x38) = *(int *)(this + 0x38) + 1;
    }
    else {
      *(undefined4 *)(this + 0x14) = 0;
      *(float *)(this + 0x20) = JAudio::_648;
      *(undefined4 *)(this + 0x38) = 0;
      dVar6 = dVar4;
    }
  }
  dVar4 = dVar7;
  if (*(int *)(this + 0x18) != 0) {
    if (*(int *)(this + 0x3c) == 0) {
      *(float *)(this + 0x24) =
           JAudio::_1025 /
           (float)((double)CONCAT44(0x43300000,*(int *)(this + 0x18)) - JAudio::_1135);
    }
    dVar4 = (double)(JAudio::_1025 -
                    *(float *)(this + 0x24) *
                    (float)((double)CONCAT44(0x43300000,*(int *)(this + 0x3c)) - JAudio::_1135));
    dVar5 = (double)JAudio::_648;
    if (dVar5 < dVar4) {
      *(int *)(this + 0x3c) = *(int *)(this + 0x3c) + 1;
    }
    else {
      this_00 = (HardStream *)resetFader(this);
      this[0xb] = (TControl)0x6;
      unregistBgmAll(this_00);
      dVar4 = dVar5;
    }
  }
  if (*(int *)(this + 0x1c) != 0) {
    if (*(int *)(this + 0x40) == 0) {
      *(float *)(this + 0x34) =
           (*(float *)(this + 0x28) - *(float *)(this + 0x30)) /
           (float)((double)CONCAT44(0x43300000,*(int *)(this + 0x1c)) - JAudio::_1135);
    }
    uVar2 = *(uint *)(this + 0x40);
    fVar1 = *(float *)(this + 0x30) +
            *(float *)(this + 0x34) * (float)((double)CONCAT44(0x43300000,uVar2) - JAudio::_1135);
    if (uVar2 < *(uint *)(this + 0x1c)) {
      *(uint *)(this + 0x40) = uVar2 + 1;
    }
    else {
      fVar1 = *(float *)(this + 0x28);
      *(float *)(this + 0x30) = fVar1;
      *(undefined4 *)(this + 0x28) = *(undefined4 *)(this + 0x30);
      *(undefined4 *)(this + 0x1c) = 0;
      *(float *)(this + 0x34) = JAudio::_648;
      *(undefined4 *)(this + 0x40) = 0;
    }
    *(float *)(this + 0x2c) = fVar1;
  }
  *(float *)(this + 0x10) =
       (float)(dVar7 * (double)(*(float *)(this + 0x2c) * (float)(dVar6 * dVar4))) *
       *(float *)(this + 0xc);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  return;
}


/* __thiscall TControl::volFloatToU8(float) */

int __thiscall TControl::volFloatToU8(TControl *this,float param_1)

{
  if (JAudio::_1025 < param_1) {
    param_1 = JAudio::_1025;
  }
  if (param_1 < JAudio::_648) {
    param_1 = JAudio::_648;
  }
  return (int)(JAudio::_1160 * param_1);
}

}

void __sinit_JASHardStream_cpp(void)

{
  ::JASystem::HardStream::TControl::TControl((TControl *)&::JASystem::HardStream::strCtrl);
  Runtime.PPCEABI.H::__register_global_object();
  return;
}


namespace HardStream {

/* __thiscall TControl::~TControl(void) */

void __thiscall TControl::_TControl(TControl *this)

{
  short in_r4;
  
  if ((this != (TControl *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

