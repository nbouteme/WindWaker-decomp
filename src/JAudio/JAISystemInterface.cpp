#include <JAudio/JAISystemInterface.h>
#include <dvd/dvdfs.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JAudio/JAISound.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JAudio/JAIGlobalParameter.h>
#include <JAudio/JAISystemInterface.h>
#include <JAudio/JASCmdStack.h>
#include <JAudio/JASOuterParam.h>
#include <JAudio/JASTrack.h>
#include <JAudio/JAISequenceMgr.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JAInter/SystemInterface.h>


namespace JAInter {
undefined1 SystemInterface;

/* __thiscall SystemInterface::checkFileExsistence(char *) */

int __thiscall SystemInterface::checkFileExsistence(SystemInterface *this,char *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = dvd::DVDConvertPathToEntrynum((char *)this);
  iVar2 = -iVar1 + -1;
  return iVar2 - ((uint)(iVar2 == 0) + -iVar1 + -2);
}


/* __thiscall SystemInterface::checkSeqActiveFlag(JASystem::TTrack *) */

ulonglong __thiscall
SystemInterface::checkSeqActiveFlag(SystemInterface *this,TTrack *param_1)

{
  if (this != (SystemInterface *)0x0) {
    param_1 = (TTrack *)(uint)(byte)this[0x37e];
    if (param_1 != (TTrack *)0x0) {
      if (((((*(int *)(this + 800) == 0) && (*(int *)(this + 0x324) == 0)) &&
           (*(int *)(this + 0x328) == 0)) &&
          (((*(int *)(this + 0x32c) == 0 && (*(int *)(this + 0x330) == 0)) &&
           ((*(int *)(this + 0x334) == 0 &&
            ((*(int *)(this + 0x338) == 0 && (*(int *)(this + 0x33c) == 0)))))))) &&
         ((*(int *)(this + 0x340) == 0 &&
          (((((*(int *)(this + 0x344) == 0 && (*(int *)(this + 0x348) == 0)) &&
             (*(int *)(this + 0x34c) == 0)) &&
            ((*(int *)(this + 0x350) == 0 && (*(int *)(this + 0x354) == 0)))) &&
           ((*(int *)(this + 0x358) == 0 && (*(int *)(this + 0x35c) == 0)))))))) {
        return ZEXT48(param_1);
      }
      return (ulonglong)CONCAT14(this[0x37e],param_1);
    }
  }
  return ZEXT48(param_1);
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8029e360) */
/* WARNING: Removing unreachable block (ram,0x8029e2dc) */
/* WARNING: Removing unreachable block (ram,0x8029e3e8) */
/* __thiscall SystemInterface::trackToSeqp(JAISound *,
                                                    unsigned char) */

undefined4 __thiscall
SystemInterface::trackToSeqp(SystemInterface *this,JAISound *param_1,uchar param_2)

{
  int iVar1;
  ulong uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar3 = 0;
  if ((*(uint *)(this + 0xc) & 0x800) == 0) {
    iVar1 = JAISound::getSeqParameter((JAISound *)this);
    if (0xf < ((uint)param_1 & 0xf)) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"JASTrack.h",0xf3,"index < MAX_CHILDREN");
      m_Do_printf::OSPanic("JASTrack.h",0xf3,&DAT_8036a0ee);
    }
    uVar3 = *(undefined4 *)(iVar1 + ((uint)param_1 & 0xf) * 4 + 0x1680);
  }
  else {
    iVar1 = JAISound::getSeqParameter((JAISound *)this);
    uVar4 = (uint)param_1 >> 4 & 0xf;
    if (0xf < uVar4) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"JASTrack.h",0xf3,"index < MAX_CHILDREN");
      m_Do_printf::OSPanic("JASTrack.h",0xf3,&DAT_8036a0ee);
    }
    iVar1 = *(int *)(iVar1 + uVar4 * 4 + 0x1680);
    if (iVar1 != 0) {
      if (0xf < ((uint)param_1 & 0xf)) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"JASTrack.h",0xf3,"index < MAX_CHILDREN");
        m_Do_printf::OSPanic("JASTrack.h",0xf3,&DAT_8036a0ee);
      }
      uVar3 = *(undefined4 *)(iVar1 + ((uint)param_1 & 0xf) * 4 + 800);
    }
  }
  return uVar3;
}


/* __thiscall SystemInterface::setSeqPortargsF32(SeqUpdateData *,
                                                          unsigned long,
                                                          unsigned char,
                                                          float) */

void __thiscall
SystemInterface::setSeqPortargsF32
          (SystemInterface *this,SeqUpdateData *param_1,ulong param_2,uchar param_3,float param_4)

{
  *(float *)(*(int *)(this + 0x4c) + (int)param_1 * 0x3c + (param_2 & 0xff) * 4 + 4) = param_4;
  return;
}


/* __thiscall SystemInterface::setSeqPortargsU32(SeqUpdateData *,
                                                          unsigned long,
                                                          unsigned char,
                                                          unsigned long) */

void __thiscall
SystemInterface::setSeqPortargsU32
          (SystemInterface *this,SeqUpdateData *param_1,ulong param_2,uchar param_3,ulong param_4)

{
  undefined3 in_register_00000018;
  
  *(uint *)(*(int *)(this + 0x4c) + (int)param_1 * 0x3c + (param_2 & 0xff) * 4 + 4) =
       CONCAT31(in_register_00000018,param_3);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall SystemInterface::rootInit(SeqUpdateData *) */

void __thiscall SystemInterface::rootInit(SystemInterface *this,SeqUpdateData *param_1)

{
  JAIGlobalParameter *this_00;
  void *pvVar1;
  uchar in_r8;
  JAISound *this_01;
  
  this_01 = *(JAISound **)(this + 0x48);
  this_00 = (JAIGlobalParameter *)JAISound::getSeqParameter(this_01);
  pvVar1 = (void *)JAIGlobalParameter::getParamSeqTrackMax(this_00);
  outerInit(this,(SeqUpdateData *)(this_00 + 0x1360),pvVar1,0xffff,0,in_r8);
  JAISound::getSeqParameter(this_01);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall SystemInterface::trackInit(SeqUpdateData *) */

void __thiscall SystemInterface::trackInit(SystemInterface *this,SeqUpdateData *param_1)

{
  SeqUpdateData *pSVar1;
  undefined *in_r5;
  uchar in_r8;
  undefined *puVar2;
  undefined *puVar3;
  SystemInterface *this_00;
  
  this_00 = *(SystemInterface **)(this + 0x48);
  puVar3 = &DAT_00000010;
  if ((*(uint *)(this_00 + 0xc) & 0x800) != 0) {
    puVar3 = (undefined *)JAIGlobalParameter::getParamSeqTrackMax((JAIGlobalParameter *)this);
  }
  puVar2 = (undefined *)0x0;
  while( true ) {
    if (puVar3 <= puVar2) break;
    if ((*(uint *)(this + 4) & 1 << (int)puVar2) == 0) {
      pSVar1 = (SeqUpdateData *)trackToSeqp(this_00,(JAISound *)((uint)puVar2 & 0xff),(uchar)in_r5);
      in_r5 = puVar2;
      outerInit(this,pSVar1,puVar2,0xffff,0,in_r8);
    }
    puVar2 = puVar2 + 1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall SystemInterface::outerInit(SeqUpdateData *,
                                                  void *,
                                                  unsigned long,
                                                  unsigned short,
                                                  unsigned char) */

void __thiscall
SystemInterface::outerInit
          (SystemInterface *this,SeqUpdateData *param_1,void *param_2,ulong param_3,ushort param_4,
          uchar param_5)

{
  SeqUpdateData **ppSVar1;
  JAIGlobalParameter *this_00;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  TOuterParam *this_01;
  
  if (param_1 != (SeqUpdateData *)0x0) {
    iVar5 = (int)param_2 * 0x3c;
    ppSVar1 = (SeqUpdateData **)(*(int *)(this + 0x4c) + iVar5);
    *ppSVar1 = param_1;
    ppSVar1[1] = param_1;
    this_00 = (JAIGlobalParameter *)
              JASystem::Kernel::TPortCmd::setPortCmd
                        ((TPortCmd *)(*(int *)(this + 0x4c) + iVar5 + 0x2c),setSePortParameter,
                         (TPortArgs *)(ppSVar1 + 1));
    this_01 = *(TOuterParam **)(param_1 + 0x360);
    pvVar2 = (void *)JAIGlobalParameter::getParamSeqTrackMax(this_00);
    if (param_2 == pvVar2) {
      ppSVar1[3] = *(SeqUpdateData **)(this + 0xc);
      ppSVar1[4] = *(SeqUpdateData **)(this + 0x10);
      ppSVar1[6] = *(SeqUpdateData **)(this + 0x14);
      ppSVar1[5] = *(SeqUpdateData **)(this + 0x18);
      ppSVar1[7] = *(SeqUpdateData **)(this + 0x1c);
      ppSVar1[10] = *(SeqUpdateData **)(this + 0x20);
      ppSVar1[2] = (SeqUpdateData *)0xff;
      JASystem::TTrack::TOuterParam::onSwitch(this_01,0x40);
    }
    else {
      iVar3 = JAISound::getSeqParameter(*(JAISound **)(this + 0x48));
      iVar4 = iVar3 + (int)param_2 * 0x10;
      ppSVar1[3] = *(SeqUpdateData **)(iVar4 + 0x264);
      ppSVar1[4] = *(SeqUpdateData **)(iVar4 + 0x664);
      ppSVar1[6] = *(SeqUpdateData **)(iVar4 + 0x864);
      ppSVar1[5] = *(SeqUpdateData **)(iVar4 + 0x464);
      ppSVar1[7] = *(SeqUpdateData **)(iVar4 + 0xa64);
      ppSVar1[9] = (SeqUpdateData *)0x0;
      ppSVar1[2] = (SeqUpdateData *)0x7f;
      JASystem::TTrack::muteTrack((TTrack *)param_1,*(char *)((int)param_2 + iVar3 + 0x133c) < '\0')
      ;
    }
    JASystem::TTrack::TOuterParam::onSwitch(this_01,1);
    JASystem::TTrack::TOuterParam::onSwitch(this_01,2);
    JASystem::TTrack::TOuterParam::onSwitch(this_01,4);
    JASystem::TTrack::TOuterParam::onSwitch(this_01,8);
    JASystem::TTrack::TOuterParam::onSwitch(this_01,0x10);
    if ((param_3 & 1) == 0) {
      JASystem::TTrack::TOuterParam::setParam(this_01,'\x01',JAudio::_906);
    }
    if ((param_3 & 2) == 0) {
      JASystem::TTrack::TOuterParam::setParam(this_01,'\x02',JAudio::_906);
    }
    if ((param_3 & 4) == 0) {
      JASystem::TTrack::TOuterParam::setParam(this_01,'\x04',JAudio::_906);
    }
    if ((param_3 & 8) == 0) {
      JASystem::TTrack::TOuterParam::setParam(this_01,'\b',JAudio::_906);
    }
    if ((param_3 & 0x10) == 0) {
      JASystem::TTrack::TOuterParam::setParam(this_01,'\x10',JAudio::_906);
    }
    JASystem::Kernel::TPortCmd::addPortCmdOnce((TPortCmd *)(*(int *)(this + 0x4c) + iVar5 + 0x2c));
  }
  return;
}


/* __thiscall SystemInterface::setPortParameter(JASystem::Kernel::TPortArgs *,
                                                         JASystem::TTrack *,
                                                         unsigned long,
                                                         unsigned long) */

void __thiscall
SystemInterface::setPortParameter
          (SystemInterface *this,TPortArgs *param_1,TTrack *param_2,ulong param_3,ulong param_4)

{
  if ((*(uint *)(this + 4) & 1 << (int)(param_2 + -2)) != 0) {
    JASystem::TTrack::TOuterParam::setParam
              (*(TOuterParam **)(param_1 + 0x360),(uchar)param_3,*(float *)(this + (int)param_2 * 4)
              );
    *(uint *)(this + 4) = *(uint *)(this + 4) ^ 1 << (int)(param_2 + -2);
  }
  return;
}


/* __thiscall SystemInterface::setSePortParameter(JASystem::Kernel::TPortArgs *) */

void __thiscall
SystemInterface::setSePortParameter(SystemInterface *this,TPortArgs *param_1)

{
  ulong in_r7;
  TPortArgs *this_00;
  
  this_00 = *(TPortArgs **)this;
  if (this_00 != (TPortArgs *)0x0) {
    setPortParameter(this,this_00,(TTrack *)&DAT_00000002,1,in_r7);
    setPortParameter(this,this_00,(TTrack *)&DAT_00000003,2,in_r7);
    setPortParameter(this,this_00,(TTrack *)&DAT_00000004,8,in_r7);
    setPortParameter(this,this_00,(TTrack *)0x5,4,in_r7);
    setPortParameter(this,this_00,(TTrack *)0x9,0x40,in_r7);
    setPortParameter(this,this_00,(TTrack *)0x6,0x10,in_r7);
    if (((*(uint *)(this + 4) & 0x40) != 0) && (*(int *)(this + 0x20) != 0)) {
      JASystem::TTrack::setInterrupt((TTrack *)this_00,5);
    }
  }
  return;
}

}

namespace JAudio {

void __sinit_JAISystemInterface_cpp(void)

{
  ::JASystem::Kernel::TPortCmd::TPortCmd((TPortCmd *)&::JAInter::SystemInterface::systemPortCmd);
  Runtime.PPCEABI.H::__register_global_object();
  return;
}

