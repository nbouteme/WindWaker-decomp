#include <JAudio/JASSeqParser.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JAudio/JASTrack.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JAudio/JASSeqCtrl.h>
#include <JAudio/JASSeqParser.h>
#include <JAudio/JASOuterParam.h>
#include <JAudio/JASTrackInterrupt.h>
#include <JAudio/JASChannelMgr.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <JAudio/JASNoteMgr.h>
#include <JAudio/JASChannel.h>
#include <JASystem/TSeqParser.h>


namespace JASystem {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TSeqParser::cmdOpenTrack(TTrack *,
                                                 unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdOpenTrack(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  uint uVar1;
  TTrack *this_00;
  ulong uVar2;
  byte bVar3;
  ulong uVar4;
  
  uVar1 = *param_2;
  uVar4 = param_2[1];
  bVar3 = (byte)(uVar1 >> 6) & 3;
  if ((uVar1 & 0x20) != 0) {
    bVar3 = 4;
  }
  this_00 = (TTrack *)TTrack::openChild(param_1,(byte)uVar1 & 0xf,bVar3);
  if (this_00 == (TTrack *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASSeqParser.cpp",0xff,"child");
    m_Do_printf::OSPanic("JASSeqParser.cpp",0xff,&DAT_803676ff);
  }
  TTrack::start(this_00,*(void **)param_1,uVar4);
  return 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TSeqParser::cmdOpenTrackBros(TTrack *,
                                                     unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdOpenTrackBros(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  ulong uVar1;
  TTrack *this_00;
  ulong uVar2;
  byte bVar3;
  uint uVar4;
  
  if (*(TTrack **)(param_1 + 0x31c) == (TTrack *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::setWarningMessage_f
              (uVar1,"JASSeqParser.cpp",0x10c,"%s",(___)"cannot opentrackB in ROOT Track");
  }
  else {
    uVar4 = *param_2;
    uVar1 = param_2[1];
    bVar3 = (byte)(uVar4 >> 6) & 3;
    if ((uVar4 & 0x20) != 0) {
      bVar3 = 4;
    }
    this_00 = (TTrack *)TTrack::openChild(*(TTrack **)(param_1 + 0x31c),(byte)uVar4 & 0xf,bVar3);
    if (this_00 == (TTrack *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"JASSeqParser.cpp",0x11a,"bros");
      m_Do_printf::OSPanic("JASSeqParser.cpp",0x11a,&DAT_803676ff);
    }
    TTrack::start(this_00,*(void **)param_1,uVar1);
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall TSeqParser::cmdCall(TTrack *,
                                            unsigned long *) */

undefined4 __thiscall TSeqParser::cmdCall(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  byte bVar1;
  byte *pbVar2;
  uchar *puVar3;
  uint uVar4;
  uint uVar5;
  char cVar7;
  int iVar6;
  
  pbVar2 = *(byte **)(param_1 + 4);
  *(byte **)(param_1 + 4) = pbVar2 + 1;
  bVar1 = *pbVar2;
  if ((bVar1 & 0x80) == 0) {
    uVar4 = TSeqCtrl::read24((TSeqCtrl *)param_1);
  }
  else {
    puVar3 = *(uchar **)(param_1 + 4);
    *(uchar **)(param_1 + 4) = puVar3 + 1;
    uVar4 = TTrack::readReg16(param_1,*puVar3);
    uVar4 = uVar4 & 0xffff;
    if ((bVar1 & 0x40) != 0) {
      if ((bVar1 & 0x20) == 0) {
        uVar5 = TSeqCtrl::read24((TSeqCtrl *)param_1);
      }
      else {
        puVar3 = *(uchar **)(param_1 + 4);
        *(uchar **)(param_1 + 4) = puVar3 + 1;
        uVar5 = TTrack::readReg16(param_1,*puVar3);
        uVar5 = uVar5 & 0xffff;
      }
      uVar4 = TSeqCtrl::get24((TSeqCtrl *)param_1,uVar5 + uVar4 * 3);
    }
  }
  cVar7 = conditionCheck(this,param_1,bVar1);
  if (cVar7 != '\0') {
    iVar6 = *(int *)(param_1 + 0xc);
    *(int *)(param_1 + 0xc) = iVar6 + 1;
    *(undefined4 *)(param_1 + iVar6 * 4 + 0x10) = *(undefined4 *)(param_1 + 4);
    *(uint *)(param_1 + 4) = *(int *)param_1 + uVar4;
  }
  return 0;
}


/* __thiscall TSeqParser::cmdRet(TTrack *,
                                           unsigned long *) */

undefined4 __thiscall TSeqParser::cmdRet(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  int iVar1;
  char cVar3;
  ulong uVar2;
  
  cVar3 = conditionCheck(this,param_1,(uchar)*param_2);
  if (cVar3 != '\0') {
    if (*(int *)(param_1 + 0xc) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::setWarningMessage_f
                (uVar2,"JASSeqParser.cpp",0x14f,"%s",(___)"cannot ret for call-stack is NULL");
      return 3;
    }
    iVar1 = *(int *)(param_1 + 0xc) + -1;
    *(int *)(param_1 + 0xc) = iVar1;
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + iVar1 * 4 + 0x10);
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall TSeqParser::cmdJmp(TTrack *,
                                           unsigned long *) */

undefined4 __thiscall TSeqParser::cmdJmp(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  byte *pbVar4;
  uint uVar5;
  uchar *puVar6;
  uint uVar7;
  char cVar8;
  int unaff_r26;
  void *pvVar9;
  
  bVar3 = false;
  pvVar9 = (void *)0x0;
  pbVar4 = *(byte **)(param_1 + 4);
  *(byte **)(param_1 + 4) = pbVar4 + 1;
  bVar1 = *pbVar4;
  if ((bVar1 & 0x80) == 0) {
    unaff_r26 = TSeqCtrl::read24((TSeqCtrl *)param_1);
  }
  else {
    pbVar4 = *(byte **)(param_1 + 4);
    *(byte **)(param_1 + 4) = pbVar4 + 1;
    bVar2 = *pbVar4;
    if ((bVar1 & 0x40) == 0) {
      if ((bVar2 < 0x28) || (0x2b < bVar2)) {
        unaff_r26 = TTrack::readReg32(param_1,bVar2);
      }
      else {
        pvVar9 = (void *)TTrack::readReg32(param_1,bVar2);
        bVar3 = true;
      }
    }
    else {
      uVar5 = TTrack::readReg16(param_1,bVar2);
      if ((bVar1 & 0x20) == 0) {
        uVar7 = TSeqCtrl::read24((TSeqCtrl *)param_1);
      }
      else {
        puVar6 = *(uchar **)(param_1 + 4);
        *(uchar **)(param_1 + 4) = puVar6 + 1;
        uVar7 = TTrack::readReg16(param_1,*puVar6);
        uVar7 = uVar7 & 0xffff;
      }
      unaff_r26 = TSeqCtrl::get24((TSeqCtrl *)param_1,uVar7 + (uVar5 & 0xffff) * 3);
    }
  }
  cVar8 = conditionCheck(this,param_1,bVar1);
  if (cVar8 != '\0') {
    if (bVar3) {
      TSeqCtrl::start((TSeqCtrl *)param_1,pvVar9,0);
    }
    else {
      *(int *)(param_1 + 4) = *(int *)param_1 + unaff_r26;
    }
  }
  return 0;
}


/* __thiscall TSeqParser::cmdLoopS(TTrack *,
                                             unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdLoopS(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = *param_2;
  *(undefined4 *)(param_1 + *(int *)(param_1 + 0xc) * 4 + 0x10) = *(undefined4 *)(param_1 + 4);
  iVar1 = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0xc) = iVar1 + 1;
  *(short *)(param_1 + iVar1 * 2 + 0x30) = (short)uVar2;
  return 0;
}


/* __thiscall TSeqParser::cmdLoopE(TTrack *,
                                             unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdLoopE(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  TSeqCtrl::loopEnd((TSeqCtrl *)param_1);
  return 0;
}


/* __thiscall TSeqParser::cmdReadPort(TTrack *,
                                                unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdReadPort(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  ushort uVar1;
  
  uVar1 = TTrack::readSelfPort(param_1,*param_2);
  TTrack::writeRegDirect(param_1,(uchar)param_2[1],uVar1);
  return 0;
}


/* __thiscall TSeqParser::cmdWritePort(TTrack *,
                                                 unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdWritePort(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  TTrack::writeSelfPort(param_1,*param_2,(ushort)param_2[1]);
  return 0;
}


/* __thiscall TSeqParser::cmdParentWritePort(TTrack *,
                                                       unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdParentWritePort(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  ulong uVar1;
  TTrack *this_00;
  
  this_00 = *(TTrack **)(param_1 + 0x31c);
  if (this_00 == (TTrack *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASSeqParser.cpp",0x1c4,"parent != 0");
    m_Do_printf::OSPanic("JASSeqParser.cpp",0x1c4,&DAT_803676ff);
  }
  TTrack::writePortAppDirect(this_00,*param_2 & 0xf,(ushort)param_2[1]);
  return 0;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8027ec94) */
/* __thiscall TSeqParser::cmdChildWritePort(TTrack *,
                                                      unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdChildWritePort(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  uint uVar1;
  ulong uVar2;
  uint uVar3;
  TTrack *this_00;
  
  uVar1 = *param_2;
  uVar3 = uVar1 >> 4 & 0xf;
  if (0xf < uVar3) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASTrack.h",0xf3,"index < MAX_CHILDREN");
    m_Do_printf::OSPanic("JASTrack.h",0xf3,&DAT_803676ff);
  }
  this_00 = *(TTrack **)(param_1 + uVar3 * 4 + 800);
  if (this_00 == (TTrack *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASSeqParser.cpp",0x1ce,"child != 0");
    m_Do_printf::OSPanic("JASSeqParser.cpp",0x1ce,&DAT_803676ff);
  }
  TTrack::writePortAppDirect(this_00,uVar1 & 0xf,(ushort)param_2[1]);
  return 0;
}


/* __thiscall TSeqParser::cmdCheckPortImport(TTrack *,
                                                       unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdCheckPortImport(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  *(ushort *)(param_1 + 0x292) = (ushort)(byte)param_1[*param_2 + 0x48];
  return 0;
}


/* __thiscall TSeqParser::cmdCheckPortExport(TTrack *,
                                                       unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdCheckPortExport(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  *(ushort *)(param_1 + 0x292) = (ushort)(byte)param_1[*param_2 + 0x58];
  return 0;
}


/* __thiscall TSeqParser::cmdWait(TTrack *,
                                            unsigned long *) */

bool __thiscall TSeqParser::cmdWait(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  ulong uVar1;
  
  uVar1 = *param_2;
  *(ulong *)(param_1 + 8) = uVar1;
  return uVar1 != 0;
}


/* __thiscall TSeqParser::cmdSetLastNote(TTrack *,
                                                   unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdSetLastNote(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar3 = *param_2;
  iVar1 = TTrack::getTranspose(param_1);
  if (0xff < uVar3 + iVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASSeqParser.cpp",0x1fa,"key < 256");
    m_Do_printf::OSPanic("JASSeqParser.cpp",0x1fa,&DAT_803676ff);
  }
  param_1[0xe9] = SUB41(uVar3 + iVar1,0);
  return 0;
}


/* __thiscall TSeqParser::cmdTimeRelate(TTrack *,
                                                  unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdTimeRelate(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  param_1[0x387] = (TTrack)('\x01' - (*param_2 == 0));
  return 0;
}


/* __thiscall TSeqParser::cmdSimpleOsc(TTrack *,
                                                 unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdSimpleOsc(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  TTrack::oscSetupSimple(param_1,(uchar)*param_2);
  return 0;
}


/* __thiscall TSeqParser::cmdSimpleEnv(TTrack *,
                                                 unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdSimpleEnv(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  TTrack::oscSetupSimpleEnv(param_1,(uchar)*param_2,param_2[1]);
  return 0;
}


/* __thiscall TSeqParser::cmdSimpleADSR(TTrack *,
                                                  unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdSimpleADSR(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  param_1[0x2cc] = Player::sAdsrDef;
  *(undefined4 *)(param_1 + 0x2d0) = DAT_80367554;
  *(undefined4 *)(param_1 + 0x2d4) = DAT_80367558;
  *(undefined4 *)(param_1 + 0x2d8) = DAT_8036755c;
  *(undefined4 *)(param_1 + 0x2dc) = DAT_80367560;
  *(undefined4 *)(param_1 + 0x2e0) = DAT_80367564;
  *(TTrack **)(param_1 + 0x2d4) = param_1 + 0x304;
  *(short *)(param_1 + 0x306) = (short)*param_2;
  *(short *)(param_1 + 0x30c) = (short)param_2[1];
  *(short *)(param_1 + 0x312) = (short)param_2[2];
  *(short *)(param_1 + 0x314) = (short)param_2[3];
  *(short *)(param_1 + 0x374) = (short)param_2[4];
  return 0;
}


/* __thiscall TSeqParser::cmdTranspose(TTrack *,
                                                 unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdTranspose(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  param_1[0x37a] = SUB41(*param_2,0);
  return 0;
}


/* __thiscall TSeqParser::cmdCloseTrack(TTrack *,
                                                  unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdCloseTrack(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  uint uVar1;
  ulong uVar2;
  TTrack *this_00;
  TTrack *extraout_r4;
  TTrack *__fd;
  
  uVar1 = *param_2;
  __fd = param_1;
  if (0xf < (uVar1 & 0xff)) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASSeqParser.cpp",0x235,"track_no < TTrack::MAX_CHILDREN");
    m_Do_printf::OSPanic("JASSeqParser.cpp",0x235,&DAT_803676ff);
    __fd = extraout_r4;
  }
  this_00 = *(TTrack **)(param_1 + (uVar1 & 0xff) * 4 + 800);
  if (this_00 != (TTrack *)0x0) {
    TTrack::close(this_00,(int)__fd);
    *(undefined4 *)(param_1 + (uVar1 & 0xff) * 4 + 800) = 0;
  }
  return 0;
}


/* __thiscall TSeqParser::cmdOutSwitch(TTrack *,
                                                 unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdOutSwitch(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  TOuterParam *this_00;
  
  this_00 = *(TOuterParam **)(param_1 + 0x360);
  if (this_00 != (TOuterParam *)0x0) {
    TTrack::TOuterParam::setOuterSwitch(this_00,(ushort)*param_2);
    TTrack::TOuterParam::setOuterUpdate(this_00,0xffff);
  }
  return 0;
}


/* __thiscall TSeqParser::cmdUpdateSync(TTrack *,
                                                  unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdUpdateSync(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  TTrack::updateTrack(param_1,*param_2);
  return 0;
}


/* __thiscall TSeqParser::cmdBusConnect(TTrack *,
                                                  unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdBusConnect(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  TTrack::connectBus(param_1,*param_2,param_2[1]);
  return 0;
}


/* __thiscall TSeqParser::cmdPauseStatus(TTrack *,
                                                   unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdPauseStatus(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  param_1[0x37c] = SUB41(*param_2,0);
  return 0;
}


/* __thiscall TSeqParser::cmdVolumeMode(TTrack *,
                                                  unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdVolumeMode(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  param_1[0x37d] = SUB41(*param_2,0);
  return 0;
}


/* __thiscall TSeqParser::cmdSetInterrupt(TTrack *,
                                                    unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdSetInterrupt(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  TIntrMgr::setIntr((TIntrMgr *)(param_1 + 0x88),*param_2,(void *)(*(int *)param_1 + param_2[1]));
  return 0;
}


/* __thiscall TSeqParser::cmdDisInterrupt(TTrack *,
                                                    unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdDisInterrupt(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  TIntrMgr::resetInter((TIntrMgr *)(param_1 + 0x88),*param_2);
  return 0;
}


/* __thiscall TSeqParser::cmdClrI(TTrack *,
                                            unsigned long *) */

undefined4 __thiscall TSeqParser::cmdClrI(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  param_1[0x88] = (TTrack)0x1;
  *(undefined4 *)(param_1 + 0x44) = 0;
  return 0;
}


/* __thiscall TSeqParser::cmdSetI(TTrack *,
                                            unsigned long *) */

undefined4 __thiscall TSeqParser::cmdSetI(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  param_1[0x88] = (TTrack)0x0;
  return 0;
}


/* __thiscall TSeqParser::cmdRetI(TTrack *,
                                            unsigned long *) */

undefined4 __thiscall TSeqParser::cmdRetI(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  param_1[0x88] = (TTrack)0x1;
  TSeqCtrl::retIntr((TSeqCtrl *)param_1);
  TTrack::tryInterrupt(param_1);
  return 0;
}


/* __thiscall TSeqParser::cmdIntTimer(TTrack *,
                                                unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdIntTimer(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  ulong uVar1;
  
  uVar1 = param_2[1];
  param_1[0x8b] = SUB41(*param_2,0);
  *(ulong *)(param_1 + 0x8c) = uVar1;
  *(ulong *)(param_1 + 0x90) = uVar1;
  return 0;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TSeqParser::cmdSyncCPU(TTrack *,
                                               unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdSyncCPU(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  undefined2 uVar1;
  
  uVar1 = 0xffff;
  if (_sCallBackFunc != (code *)0x0) {
    uVar1 = (*_sCallBackFunc)(param_1,*param_2 & 0xffff);
  }
  *(undefined2 *)(param_1 + 0x292) = uVar1;
  return 0;
}


/* __thiscall TSeqParser::cmdFlushAll(TTrack *,
                                                unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdFlushAll(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  TTrack::flushAll(param_1);
  return 0;
}


/* __thiscall TSeqParser::cmdFlushRelease(TTrack *,
                                                    unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdFlushRelease(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  TChannelMgr::stopAllRelease((TChannelMgr *)(param_1 + 0xf8));
  return 0;
}


/* __thiscall TSeqParser::cmdTimeBase(TTrack *,
                                                unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdTimeBase(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  TTrack::setTimebase(param_1,(ushort)*param_2);
  return 0;
}


/* __thiscall TSeqParser::cmdTempo(TTrack *,
                                             unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdTempo(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  TTrack::setTempo(param_1,(ushort)*param_2);
  return 0;
}


/* __thiscall TSeqParser::cmdFinish(TTrack *,
                                              unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdFinish(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  return 3;
}


/* __thiscall TSeqParser::cmdNop(TTrack *,
                                           unsigned long *) */

undefined4 __thiscall TSeqParser::cmdNop(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  return 0;
}


/* __thiscall TSeqParser::cmdPanPowSet(TTrack *,
                                                 unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdPanPowSet(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  float fVar1;
  double dVar2;
  
  *(short *)(param_1 + 0x29c) = (short)*param_2;
  *(short *)(param_1 + 0x29e) = (short)param_2[1];
  *(short *)(param_1 + 0x2a0) = (short)param_2[2];
  dVar2 = JAudio::_988;
  fVar1 = JAudio::_986;
  *(short *)(param_1 + 0x2a2) =
       (short)(int)(JAudio::_986 * (float)((double)CONCAT44(0x43300000,param_2[3]) - JAudio::_988));
  *(short *)(param_1 + 0x2a4) =
       (short)(int)(fVar1 * (float)((double)CONCAT44(0x43300000,param_2[4]) - dVar2));
  return 0;
}


/* __thiscall TSeqParser::cmdFIRSet(TTrack *,
                                              unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdFIRSet(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  TTrack::TOuterParam::setFirFilter
            (*(TOuterParam **)(param_1 + 0x360),(short *)(*(int *)param_1 + *param_2));
  return 0;
}


/* __thiscall TSeqParser::cmdEXTSet(TTrack *,
                                              unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdEXTSet(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  ulong uVar1;
  int iVar2;
  
  iVar2 = *(int *)param_1;
  uVar1 = *param_2;
  TTrack::TOuterParam::initExtBuffer((TOuterParam *)(iVar2 + uVar1));
  TTrack::assignExtBuffer(param_1,(TOuterParam *)(iVar2 + uVar1));
  return 0;
}


/* __thiscall TSeqParser::cmdPanSwSet(TTrack *,
                                                unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdPanSwSet(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  uint uVar1;
  TTrack *pTVar2;
  byte bVar3;
  undefined4 local_18;
  undefined2 local_14;
  undefined local_12;
  undefined4 local_10;
  undefined2 local_c;
  undefined local_a;
  
  local_10 = JAudio::_1014;
  local_c = DAT_803fc0e4;
  local_a = DAT_803fc0e6;
  local_18 = JAudio::_1015;
  local_14 = DAT_803fc0ec;
  local_12 = DAT_803fc0ee;
  for (bVar3 = 0; bVar3 < 3; bVar3 = bVar3 + 1) {
    uVar1 = (uint)bVar3;
    pTVar2 = param_1 + bVar3;
    pTVar2[0x37f] = *(TTrack *)((int)&local_10 + (param_2[uVar1] >> 5));
    pTVar2[0x382] = *(TTrack *)((int)&local_18 + (param_2[uVar1] >> 5));
    pTVar2[0x15a] = (TTrack)((byte)param_2[uVar1] & 0x1f);
    *(uint *)(param_1 + 0x370) = *(uint *)(param_1 + 0x370) | 0x1c;
  }
  return 0;
}


/* __thiscall TSeqParser::cmdOscRoute(TTrack *,
                                                unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdOscRoute(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  *(ulong *)(param_1 + (*param_2 >> 2 & 0x3c) + 0x2fc) = *param_2 & 0xf;
  return 0;
}


/* __thiscall TSeqParser::cmdVibDepth(TTrack *,
                                                unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdVibDepth(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  *(float *)(param_1 + 0xf0) =
       (float)((double)CONCAT44(0x43300000,
                                ((*param_2 & 0xff) << 8 | (*param_2 & 0xff) << 1) ^ 0x80000000) -
              JAudio::_1040) / JAudio::_1038;
  return 0;
}


/* __thiscall TSeqParser::cmdVibDepthMidi(TTrack *,
                                                    unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdVibDepthMidi(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  *(float *)(param_1 + 0xf0) =
       (float)((double)CONCAT44(0x43300000,*param_2) - JAudio::_988) / JAudio::_1038;
  return 0;
}


/* __thiscall TSeqParser::cmdVibPitch(TTrack *,
                                                unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdVibPitch(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  *(float *)(param_1 + 0xf4) =
       (float)((double)CONCAT44(0x43300000,(*param_2 & 0xff) << 8 | (*param_2 & 0xff) << 1) -
              JAudio::_988) / JAudio::_1053;
  return 0;
}


/* __thiscall TSeqParser::cmdIIRSet(TTrack *,
                                              unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdIIRSet(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  double dVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  fVar4 = JAudio::_1066;
  fVar3 = JAudio::_1065;
  fVar2 = JAudio::_1064;
  dVar1 = JAudio::_1040;
  for (uVar6 = 0; (uVar6 & 0xff) < 4; uVar6 = uVar6 + 1) {
    puVar5 = (undefined4 *)(param_1 + ((uVar6 + 0xc) * 0x10 & 0xff0) + 0x16c);
    puVar5[1] = (float)((double)CONCAT44(0x43300000,(int)(short)param_2[uVar6 & 0xff] ^ 0x80000000)
                       - dVar1) / fVar2;
    *puVar5 = puVar5[1];
    puVar5[3] = fVar3;
    puVar5[2] = fVar4;
  }
  return 0;
}


/* __thiscall TSeqParser::cmdIIRCutOff(TTrack *,
                                                 unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdIIRCutOff(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  double dVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  fVar4 = JAudio::_1078;
  fVar3 = JAudio::_1066;
  fVar2 = JAudio::_1065;
  dVar1 = JAudio::_1040;
  uVar5 = *param_2;
  for (uVar7 = 0; (uVar7 & 0xff) < 4; uVar7 = uVar7 + 1) {
    puVar6 = (undefined4 *)(param_1 + ((uVar7 + 0xc) * 0x10 & 0xff0) + 0x16c);
    puVar6[1] = (float)((double)CONCAT44(0x43300000,
                                         (int)*(short *)(&Player::CUTOFF_TO_IIR_TABLE +
                                                        (uVar7 & 0xff) * 2 + (uVar5 & 0xff) * 8) ^
                                         0x80000000) - dVar1) / fVar4;
    *puVar6 = puVar6[1];
    puVar6[3] = fVar2;
    puVar6[2] = fVar3;
  }
  return 0;
}


/* __thiscall TSeqParser::cmdOscFull(TTrack *,
                                               unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdOscFull(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  TTrack::oscSetupFull(param_1,(uchar)*param_2,param_2[1],param_2[2]);
  return 0;
}


/* __thiscall TSeqParser::cmdCheckWave(TTrack *,
                                                 unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdCheckWave(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  *(undefined2 *)(param_1 + 0x292) = 0;
  return 0;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall TSeqParser::cmdPrintf(TTrack *,
                                              unsigned long *) */

undefined4 __thiscall
TSeqParser::cmdPrintf(TSeqParser *this,TTrack *param_1,ulong *param_2)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  undefined4 uVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  byte local_b8 [4];
  uint local_b4 [4];
  char local_a4 [140];
  
  uVar9 = 0;
  for (uVar5 = 0; uVar5 < 0x80; uVar5 = uVar5 + 1) {
    pcVar6 = *(char **)(param_1 + 4);
    *(char **)(param_1 + 4) = pcVar6 + 1;
    local_a4[uVar5] = *pcVar6;
    cVar2 = local_a4[uVar5];
    if (cVar2 == '\0') break;
    if (cVar2 == '\\') {
      pcVar6 = *(char **)(param_1 + 4);
      *(char **)(param_1 + 4) = pcVar6 + 1;
      local_a4[uVar5] = *pcVar6;
      cVar2 = local_a4[uVar5];
      if (cVar2 == '\0') break;
      if (cVar2 == 'n') {
        local_a4[uVar5] = '\r';
      }
    }
    else {
      if (cVar2 == '%') {
        pcVar6 = *(char **)(param_1 + 4);
        *(char **)(param_1 + 4) = pcVar6 + 1;
        uVar5 = uVar5 + 1;
        local_a4[uVar5] = *pcVar6;
        cVar2 = local_a4[uVar5];
        if (cVar2 == '\0') break;
        if (cVar2 == 'r') {
          local_b8[uVar9] = 3;
          local_a4[uVar5] = 'd';
        }
        else {
          if (cVar2 < 'r') {
            if (cVar2 == 'd') {
              local_b8[uVar9] = 0;
            }
            else {
              if ((cVar2 < 'd') && (cVar2 == 'R')) {
                local_b8[uVar9] = 4;
                local_a4[uVar5] = 'x';
              }
            }
          }
          else {
            if (cVar2 == 'x') {
              local_b8[uVar9] = 1;
            }
            else {
              if (cVar2 < 'x') {
                if (cVar2 == 't') {
                  local_b8[uVar9] = 5;
                  local_a4[uVar5] = 'x';
                }
                else {
                  if (cVar2 < 't') {
                    local_b8[uVar9] = 2;
                  }
                }
              }
            }
          }
        }
        uVar9 = uVar9 + 1;
      }
    }
  }
  iVar7 = 0;
  pbVar8 = local_b8;
  for (uVar5 = 0; uVar5 < uVar9; uVar5 = uVar5 + 1) {
    pbVar3 = *(byte **)(param_1 + 4);
    *(byte **)(param_1 + 4) = pbVar3 + 1;
    *(uint *)((int)local_b4 + iVar7) = (uint)*pbVar3;
    bVar1 = *pbVar8;
    if (bVar1 == 2) {
      *(int *)((int)local_b4 + iVar7) = *(int *)param_1 + *(int *)((int)local_b4 + iVar7);
    }
    else {
      if (bVar1 == 5) {
        *(undefined4 *)((int)local_b4 + iVar7) = *(undefined4 *)(param_1 + 0x36c);
      }
      else {
        if (2 < bVar1) {
          uVar4 = TTrack::exchangeRegisterValue
                            (param_1,(uchar)*(undefined4 *)((int)local_b4 + iVar7));
          *(undefined4 *)((int)local_b4 + iVar7) = uVar4;
        }
      }
    }
    pbVar8 = pbVar8 + 1;
    iVar7 = iVar7 + 4;
  }
  m_Do_printf::OSReport(local_a4,local_b4[0],local_b4[1],local_b4[2],local_b4[3]);
  return 0;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x8027f968) */
/* __thiscall TSeqParser::Cmd_Process(TTrack *,
                                                unsigned char,
                                                unsigned short) */

void __thiscall
TSeqParser::Cmd_Process(TSeqParser *this,TTrack *param_1,uchar param_2,ushort param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  uchar *puVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  PTMF local_54;
  uint local_48 [10];
  
  uVar2 = *(uint *)(
                   "[Nas_HeapInit] アドレス０からヒープを初期化しようとしています。\n"
                   + (uint)param_2 * 4 + 0xe);
  uVar9 = uVar2 & 0xffff | (uint)param_3;
  iVar7 = 0;
  for (iVar8 = 0; iVar8 < (int)(uVar2 >> 0x10); iVar8 = iVar8 + 1) {
    uVar3 = 0;
    uVar1 = uVar9 & 3;
    if (uVar1 == 2) {
      uVar3 = TSeqCtrl::read24((TSeqCtrl *)param_1);
    }
    else {
      if (uVar1 < 2) {
        if (uVar1 == 0) {
          pbVar4 = *(byte **)(param_1 + 4);
          *(byte **)(param_1 + 4) = pbVar4 + 1;
          uVar3 = (uint)*pbVar4;
        }
        else {
          uVar3 = TSeqCtrl::read16((TSeqCtrl *)param_1);
          uVar3 = uVar3 & 0xffff;
        }
      }
      else {
        if (uVar1 < 4) {
          puVar5 = *(uchar **)(param_1 + 4);
          *(uchar **)(param_1 + 4) = puVar5 + 1;
          uVar3 = TTrack::exchangeRegisterValue(param_1,*puVar5);
        }
      }
    }
    *(uint *)((int)local_48 + iVar7) = uVar3;
    uVar9 = uVar9 >> 2;
    iVar7 = iVar7 + 4;
  }
  iVar7 = (uint)param_2 * 0xc;
  local_54.this_delta = (int)(&PTR_adaptor_do_FACULTY_80397d5c)[(uint)param_2 * 3];
  local_54.vtbl_offset = *(int *)(&JStudio_JAudio::TCreateObject::__vt + iVar7);
  local_54.func = *(undefined **)(&DAT_80397d64 + iVar7);
  bVar6 = Runtime.PPCEABI.H::__ptmf_test(&local_54);
  if (bVar6 != false) {
    Runtime.PPCEABI.H::__ptmf_scall(&local_54,this,param_1);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall TSeqParser::RegCmd_Process(TTrack *,
                                                   int,
                                                   int) */

void __thiscall
TSeqParser::RegCmd_Process(TSeqParser *this,TTrack *param_1,int param_2,int param_3)

{
  int iVar1;
  uchar *puVar2;
  uchar uVar5;
  byte *pbVar3;
  uint uVar4;
  uint uVar6;
  uint uVar7;
  ushort uVar8;
  
  puVar2 = *(uchar **)(param_1 + 4);
  *(uchar **)(param_1 + 4) = puVar2 + 1;
  uVar5 = *puVar2;
  if (param_2 != 0) {
    uVar5 = TTrack::exchangeRegisterValue(param_1,uVar5);
  }
  uVar7 = 0;
  uVar8 = 0;
  if ((param_2 == 0) || (param_3 != 0)) {
    pbVar3 = *(byte **)(param_1 + 4);
    *(byte **)(param_1 + 4) = pbVar3 + 1;
    uVar4 = (uint)*pbVar3;
    uVar6 = 3;
    for (iVar1 = param_3 + 1; iVar1 != 0; iVar1 = iVar1 + -1) {
      if ((uVar4 & 0x80) != 0) {
        uVar7 = uVar7 | uVar6;
      }
      uVar8 = (ushort)uVar7;
      uVar4 = (uVar4 & 0x7f) << 1;
      uVar6 = (uVar6 & 0x3fff) << 2;
    }
  }
  Cmd_Process(this,param_1,uVar5,uVar8);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8027fbf0) */
/* __thiscall TSeqParser::cmdSetParam(TTrack *,
                                                unsigned char) */

undefined4 __thiscall
TSeqParser::cmdSetParam(TSeqParser *this,TTrack *param_1,uchar param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  uchar *puVar4;
  uint uVar5;
  ushort unaff_r29;
  
  pbVar3 = *(byte **)(param_1 + 4);
  *(byte **)(param_1 + 4) = pbVar3 + 1;
  bVar1 = *pbVar3;
  switch(param_2 & 0xc) {
  case 0:
    puVar4 = *(uchar **)(param_1 + 4);
    *(uchar **)(param_1 + 4) = puVar4 + 1;
    unaff_r29 = TTrack::readReg16(param_1,*puVar4);
    break;
  case 4:
    pbVar3 = *(byte **)(param_1 + 4);
    *(byte **)(param_1 + 4) = pbVar3 + 1;
    unaff_r29 = (ushort)*pbVar3;
    break;
  case 8:
    pbVar3 = *(byte **)(param_1 + 4);
    *(byte **)(param_1 + 4) = pbVar3 + 1;
    bVar2 = *pbVar3;
    if ((bVar2 & 0x80) == 0) {
      unaff_r29 = (ushort)bVar2 << 8 | (ushort)bVar2 << 1;
    }
    else {
      unaff_r29 = (ushort)bVar2 << 8;
    }
    break;
  case 0xc:
    unaff_r29 = TSeqCtrl::read16((TSeqCtrl *)param_1);
  }
  uVar5 = 0;
  bVar2 = param_2 & 3;
  if (bVar2 == 2) {
    pbVar3 = *(byte **)(param_1 + 4);
    *(byte **)(param_1 + 4) = pbVar3 + 1;
    uVar5 = (uint)*pbVar3;
  }
  else {
    if (bVar2 < 2) {
      if ((param_2 & 3) == 0) {
        uVar5 = 0xffffffff;
      }
      else {
        puVar4 = *(uchar **)(param_1 + 4);
        *(uchar **)(param_1 + 4) = puVar4 + 1;
        uVar5 = TTrack::readReg16(param_1,*puVar4);
        uVar5 = uVar5 & 0xffff;
      }
    }
    else {
      if (bVar2 < 4) {
        uVar5 = TSeqCtrl::read16((TSeqCtrl *)param_1);
        uVar5 = uVar5 & 0xffff;
      }
    }
  }
  TTrack::setParam(param_1,(uint)bVar1,
                   (float)((double)CONCAT44(0x43300000,(int)(short)unaff_r29 ^ 0x80000000) -
                          JAudio::_1040) / JAudio::_1078,uVar5);
  return 0;
}


/* __thiscall TSeqParser::cmdWait(TTrack *,
                                            unsigned char) */

bool __thiscall TSeqParser::cmdWait(TSeqParser *this,TTrack *param_1,uchar param_2)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  
  iVar1 = 2 - (uint)(param_2 == 0x80);
  uVar3 = 0;
  if (0 < iVar1) {
    do {
      pbVar2 = *(byte **)(param_1 + 4);
      *(byte **)(param_1 + 4) = pbVar2 + 1;
      uVar3 = uVar3 << 8 | (uint)*pbVar2;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  *(uint *)(param_1 + 8) = uVar3;
  return uVar3 != 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TSeqParser::cmdNoteOff(TTrack *,
                                               unsigned char) */

undefined4 __thiscall
TSeqParser::cmdNoteOff(TSeqParser *this,TTrack *param_1,uchar param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte bVar4;
  ulong uVar3;
  ushort uVar5;
  
  if (param_2 == 0xf9) {
    pbVar2 = *(byte **)(param_1 + 4);
    *(byte **)(param_1 + 4) = pbVar2 + 1;
    bVar1 = *pbVar2;
    bVar4 = TTrack::exchangeRegisterValue(param_1,bVar1 & 7);
    if (bVar4 == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"JASSeqParser.cpp",0x496,"rdata2 >= 1");
      m_Do_printf::OSPanic("JASSeqParser.cpp",0x496,&DAT_803676ff);
    }
    if (7 < bVar4) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"JASSeqParser.cpp",0x497,"rdata2 <= 7");
      m_Do_printf::OSPanic("JASSeqParser.cpp",0x497,&DAT_803676ff);
    }
    param_2 = bVar4 + 0x80;
    if ((bVar1 & 0x80) != 0) {
      param_2 = param_2 | 8;
    }
  }
  uVar5 = 0;
  if ((param_2 & 8) != 0) {
    pbVar2 = *(byte **)(param_1 + 4);
    *(byte **)(param_1 + 4) = pbVar2 + 1;
    bVar1 = *pbVar2;
    uVar5 = (ushort)bVar1;
    if (100 < bVar1) {
      uVar5 = (bVar1 - 0x62) * 0x14;
    }
  }
  TTrack::noteOff(param_1,param_2 & 7,uVar5);
  return 0;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* __thiscall TSeqParser::cmdNoteOn(TTrack *,
                                              unsigned char) */

undefined4 __thiscall
TSeqParser::cmdNoteOn(TSeqParser *this,TTrack *param_1,uchar param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  byte bVar7;
  byte bVar8;
  uchar *puVar5;
  TChannel *this_00;
  char cVar9;
  undefined4 uVar6;
  uint uVar10;
  ulong uVar11;
  ulong uVar12;
  TTrack TVar14;
  ulong uVar13;
  uint uVar15;
  uint unaff_r31;
  uint uVar16;
  
  uVar3 = (uint)param_2;
  pbVar2 = *(byte **)(param_1 + 4);
  *(byte **)(param_1 + 4) = pbVar2 + 1;
  bVar1 = *pbVar2;
  if ((bVar1 & 0x80) != 0) {
    uVar3 = TTrack::exchangeRegisterValue(param_1,param_2);
    uVar3 = uVar3 & 0xff;
  }
  iVar4 = TTrack::getTranspose(param_1);
  uVar3 = uVar3 + iVar4 & 0xff;
  TVar14 = (TTrack)(bVar1 >> 5 & 3);
  uVar15 = uVar3;
  if ((bVar1 >> 5 & 2) != 0) {
    uVar15 = (uint)(byte)param_1[0xe9];
    unaff_r31 = uVar3;
  }
  pbVar2 = *(byte **)(param_1 + 4);
  *(byte **)(param_1 + 4) = pbVar2 + 1;
  bVar8 = *pbVar2;
  uVar3 = (uint)bVar8;
  if ((bVar8 & 0x80) != 0) {
    uVar3 = TTrack::exchangeRegisterValue(param_1,bVar8 & 0x7f);
    uVar3 = uVar3 & 0xff;
  }
  bVar8 = bVar1 & 7;
  uVar11 = 0;
  if ((bVar1 & 7) == 0) {
    pbVar2 = *(byte **)(param_1 + 4);
    *(byte **)(param_1 + 4) = pbVar2 + 1;
    bVar7 = *pbVar2;
    if ((bVar7 & 0x80) != 0) {
      bVar7 = TTrack::exchangeRegisterValue(param_1,bVar7 & 0x7f);
    }
    uVar12 = 0;
    uVar10 = bVar1 >> 3 & 3;
    uVar16 = uVar10;
    if ((bVar1 >> 3 & 3) != 0) {
      do {
        pbVar2 = *(byte **)(param_1 + 4);
        *(byte **)(param_1 + 4) = pbVar2 + 1;
        uVar12 = uVar12 << 8 | (uint)*pbVar2;
        uVar16 = uVar16 - 1;
      } while (uVar16 != 0);
    }
    if ((uVar10 == 1) && ((uVar12 & 0x80) != 0)) {
      uVar12 = TTrack::exchangeRegisterValue(param_1,(byte)uVar12 & 0x7f);
    }
  }
  else {
    if ((bVar1 >> 3 & 3) != 0) {
      bVar8 = TTrack::exchangeRegisterValue(param_1,bVar8 - 1);
      if (7 < bVar8) {
        uVar12 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar12,"JASSeqParser.cpp",0x4fe,"noteid < 8");
        m_Do_printf::OSPanic("JASSeqParser.cpp",0x4fe,&DAT_803676ff);
      }
    }
    if ((bVar1 >> 5 & 1) != 0) {
      puVar5 = *(uchar **)(param_1 + 4);
      *(uchar **)(param_1 + 4) = puVar5 + 1;
      uVar11 = TTrack::exchangeRegisterValue(param_1,*puVar5);
      TVar14 = (TTrack)((byte)TVar14 ^ 1);
    }
    uVar12 = 0xffffffff;
    bVar7 = 100;
  }
  param_1[0xe8] = TVar14;
  uVar13 = uVar12;
  if (param_1[0xea] == (TTrack)0x0) {
    if (uVar12 != 0xffffffff) {
      uVar13 = TTrack::seqTimeToDspTime(param_1,uVar12,bVar7);
    }
    if (((byte)param_1[0xe8] & 1) != 0) {
      uVar13 = 0xffffffff;
    }
    if ((param_1[0x385] == (TTrack)0x0) || (((byte)param_1[0x37c] & 0x10) == 0)) {
      TTrack::noteOn(param_1,bVar8,uVar15,uVar3,uVar13,uVar11);
    }
  }
  else {
    if (((byte)param_1[0xe8] & 1) != 0) {
      uVar13 = 0xffffffff;
    }
    if (uVar13 != 0xffffffff) {
      uVar13 = TTrack::seqTimeToDspTime(param_1,uVar13,bVar7);
    }
    if ((param_1[0x385] == (TTrack)0x0) || (((byte)param_1[0x37c] & 0x10) == 0)) {
      TTrack::gateOn(param_1,bVar8,uVar15,uVar3,uVar13);
    }
  }
  *(ulong *)(param_1 + 0xe4) = uVar12;
  param_1[0xea] = (TTrack)((byte)param_1[0xe8] & 1);
  if (((byte)param_1[0xe8] & 2) != 0) {
    if (uVar13 == 0xffffffff) {
      uVar13 = TTrack::seqTimeToDspTime(param_1,uVar12,bVar7);
    }
    this_00 = (TChannel *)TTrack::TNoteMgr::getChannel((TNoteMgr *)(param_1 + 0xb4),0);
    uVar15 = unaff_r31;
    if (this_00 != (TChannel *)0x0) {
      cVar9 = TTrack::getTranspose(param_1);
      TChannel::setKeySweepTarget(this_00,(char)unaff_r31 + cVar9,uVar13);
    }
  }
  param_1[0xe9] = SUB41(uVar15,0);
  if (uVar12 == 0xffffffff) {
    uVar6 = 0;
  }
  else {
    uVar11 = 0xffffffff;
    if (uVar12 != 0) {
      uVar11 = uVar12;
    }
    *(ulong *)(param_1 + 8) = uVar11;
    uVar6 = 1;
  }
  return uVar6;
}


/* WARNING: Removing unreachable block (ram,0x8028017c) */
/* __thiscall TSeqParser::conditionCheck(TTrack *,
                                                   unsigned char) */

uint __thiscall TSeqParser::conditionCheck(TSeqParser *this,TTrack *param_1,uchar param_2)

{
  ushort uVar1;
  byte bVar2;
  ulong uVar3;
  uint uVar4;
  
  uVar1 = *(ushort *)(param_1 + 0x292);
  bVar2 = param_2 & 0xf;
  if (bVar2 == 3) {
    uVar4 = countLeadingZeros(1 - (uint)uVar1);
    uVar4 = uVar4 >> 5;
  }
  else {
    if (bVar2 < 3) {
      if (bVar2 == 1) {
        uVar4 = countLeadingZeros((uint)uVar1);
        uVar4 = uVar4 >> 5;
      }
      else {
        if ((param_2 & 0xf) == 0) {
          uVar4 = 1;
        }
        else {
          uVar4 = (uint)(uVar1 != 0);
        }
      }
    }
    else {
      if (bVar2 == 5) {
        uVar4 = uVar1 - 0x8000 >> 0x1f;
      }
      else {
        if (bVar2 < 5) {
          uVar4 = -((uVar1 < 0x8000) - 1);
        }
        else {
          uVar3 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar3,"JASSeqParser.cpp",0x578,"false");
          m_Do_printf::OSPanic("JASSeqParser.cpp",0x578,&DAT_803676ff);
          uVar4 = 0;
        }
      }
    }
  }
  return uVar4;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TSeqParser::parseSeq(TTrack *) */

undefined4 __thiscall TSeqParser::parseSeq(TSeqParser *this,TTrack *param_1)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  
  do {
    pbVar3 = *(byte **)(param_1 + 4);
    *(byte **)(param_1 + 4) = pbVar3 + 1;
    bVar1 = *pbVar3;
    iVar4 = 0;
    if ((bVar1 & 0x80) == 0) {
      iVar4 = cmdNoteOn(this,param_1,bVar1);
    }
    else {
      if (((bVar1 & 0xf0) == 0x80) && ((bVar1 & 7) == 0)) {
        iVar4 = cmdWait(this,param_1,bVar1);
      }
      else {
        if (((bVar1 & 0xf0) == 0x80) || (bVar1 == 0xf9)) {
          iVar4 = cmdNoteOff(this,param_1,bVar1);
        }
        else {
          bVar2 = bVar1 & 0xf0;
          if (bVar2 == 0xa0) {
            TTrack::writeRegParam(param_1,bVar1 & 0xf);
          }
          else {
            if (bVar2 < 0xa0) {
              if (bVar2 == 0x90) {
                iVar4 = cmdSetParam(this,param_1,bVar1 & 0xf);
              }
              else {
LAB_8028035c:
                iVar4 = Cmd_Process(this,param_1,bVar1,0);
              }
            }
            else {
              if (bVar2 != 0xb0) goto LAB_8028035c;
              iVar4 = RegCmd_Process(this,param_1,bVar1 >> 3 & 1,bVar1 & 7);
            }
          }
        }
      }
    }
    if (iVar4 != 0) {
      if (iVar4 == 1) {
        return 0;
      }
      if (iVar4 == 3) {
        return 0xffffffff;
      }
    }
  } while( true );
}

}

namespace JAudio {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __sinit_JASSeqParser_cpp(void)

{
  _sCmdPList = Runtime.PPCEABI.H::__ptmf_null;
  DAT_80398660 = DAT_80370fbc;
  DAT_80398664 = DAT_80370fc0;
  DAT_80398668 = _620;
  DAT_8039866c = DAT_803983e4;
  DAT_80398670 = PTR_cmdOpenTrack_803983e8;
  DAT_80398674 = _621;
  DAT_80398678 = DAT_803983f0;
  DAT_8039867c = PTR_cmdOpenTrackBros_803983f4;
  DAT_80398680 = Runtime.PPCEABI.H::__ptmf_null;
  DAT_80398684 = DAT_80370fbc;
  DAT_80398688 = DAT_80370fc0;
  DAT_8039868c = _622;
  DAT_80398690 = DAT_803983fc;
  DAT_80398694 = PTR_cmdCall_80398400;
  DAT_80398698 = Runtime.PPCEABI.H::__ptmf_null;
  DAT_8039869c = DAT_80370fbc;
  DAT_803986a0 = DAT_80370fc0;
  DAT_803986a4 = _623;
  DAT_803986a8 = DAT_80398408;
  DAT_803986ac = PTR_cmdRet_8039840c;
  DAT_803986b0 = Runtime.PPCEABI.H::__ptmf_null;
  DAT_803986b4 = DAT_80370fbc;
  DAT_803986b8 = DAT_80370fc0;
  DAT_803986bc = _624;
  DAT_803986c0 = DAT_80398414;
  DAT_803986c4 = PTR_cmdJmp_80398418;
  DAT_803986c8 = _625;
  DAT_803986cc = DAT_80398420;
  DAT_803986d0 = PTR_cmdLoopS_80398424;
  DAT_803986d4 = _626;
  DAT_803986d8 = DAT_8039842c;
  DAT_803986dc = PTR_cmdLoopE_80398430;
  DAT_803986e0 = _627;
  DAT_803986e4 = DAT_80398438;
  DAT_803986e8 = PTR_cmdReadPort_8039843c;
  DAT_803986ec = _628;
  DAT_803986f0 = DAT_80398444;
  DAT_803986f4 = PTR_cmdWritePort_80398448;
  DAT_803986f8 = _629;
  DAT_803986fc = DAT_80398450;
  DAT_80398700 = PTR_cmdCheckPortImport_80398454;
  DAT_80398704 = _630;
  DAT_80398708 = DAT_8039845c;
  DAT_8039870c = PTR_cmdCheckPortExport_80398460;
  DAT_80398710 = _631;
  DAT_80398714 = DAT_80398468;
  DAT_80398718 = PTR_cmdWait_8039846c;
  DAT_8039871c = Runtime.PPCEABI.H::__ptmf_null;
  DAT_80398720 = DAT_80370fbc;
  DAT_80398724 = DAT_80370fc0;
  DAT_80398728 = _632;
  DAT_8039872c = DAT_80398474;
  DAT_80398730 = PTR_cmdParentWritePort_80398478;
  DAT_80398734 = _633;
  DAT_80398738 = DAT_80398480;
  DAT_8039873c = PTR_cmdChildWritePort_80398484;
  DAT_80398740 = Runtime.PPCEABI.H::__ptmf_null;
  DAT_80398744 = DAT_80370fbc;
  DAT_80398748 = DAT_80370fc0;
  DAT_8039874c = _634;
  DAT_80398750 = DAT_8039848c;
  DAT_80398754 = PTR_cmdSetLastNote_80398490;
  DAT_80398758 = _635;
  DAT_8039875c = DAT_80398498;
  DAT_80398760 = PTR_cmdTimeRelate_8039849c;
  DAT_80398764 = _636;
  DAT_80398768 = DAT_803984a4;
  DAT_8039876c = PTR_cmdSimpleOsc_803984a8;
  DAT_80398770 = _637;
  DAT_80398774 = DAT_803984b0;
  DAT_80398778 = PTR_cmdSimpleEnv_803984b4;
  DAT_8039877c = _638;
  DAT_80398780 = DAT_803984bc;
  DAT_80398784 = PTR_cmdSimpleADSR_803984c0;
  DAT_80398788 = _639;
  DAT_8039878c = DAT_803984c8;
  DAT_80398790 = PTR_cmdTranspose_803984cc;
  DAT_80398794 = _640;
  DAT_80398798 = DAT_803984d4;
  DAT_8039879c = PTR_cmdCloseTrack_803984d8;
  DAT_803987a0 = _641;
  DAT_803987a4 = DAT_803984e0;
  DAT_803987a8 = PTR_cmdOutSwitch_803984e4;
  DAT_803987ac = _642;
  DAT_803987b0 = DAT_803984ec;
  DAT_803987b4 = PTR_cmdUpdateSync_803984f0;
  DAT_803987b8 = _643;
  DAT_803987bc = DAT_803984f8;
  DAT_803987c0 = PTR_cmdBusConnect_803984fc;
  DAT_803987c4 = _644;
  DAT_803987c8 = DAT_80398504;
  DAT_803987cc = PTR_cmdPauseStatus_80398508;
  DAT_803987d0 = _645;
  DAT_803987d4 = DAT_80398510;
  DAT_803987d8 = PTR_cmdSetInterrupt_80398514;
  DAT_803987dc = _646;
  DAT_803987e0 = DAT_8039851c;
  DAT_803987e4 = PTR_cmdDisInterrupt_80398520;
  DAT_803987e8 = _647;
  DAT_803987ec = DAT_80398528;
  DAT_803987f0 = PTR_cmdClrI_8039852c;
  DAT_803987f4 = _648;
  DAT_803987f8 = DAT_80398534;
  DAT_803987fc = PTR_cmdSetI_80398538;
  DAT_80398800 = _649;
  DAT_80398804 = DAT_80398540;
  DAT_80398808 = PTR_cmdRetI_80398544;
  DAT_8039880c = _650;
  DAT_80398810 = DAT_8039854c;
  DAT_80398814 = PTR_cmdIntTimer_80398550;
  DAT_80398818 = _651;
  DAT_8039881c = DAT_80398558;
  DAT_80398820 = PTR_cmdVibDepth_8039855c;
  DAT_80398824 = _652;
  DAT_80398828 = DAT_80398564;
  DAT_8039882c = PTR_cmdVibDepthMidi_80398568;
  DAT_80398830 = _653;
  DAT_80398834 = DAT_80398570;
  DAT_80398838 = PTR_cmdSyncCPU_80398574;
  DAT_8039883c = _654;
  DAT_80398840 = DAT_8039857c;
  DAT_80398844 = PTR_cmdFlushAll_80398580;
  DAT_80398848 = _655;
  DAT_8039884c = DAT_80398588;
  DAT_80398850 = PTR_cmdFlushRelease_8039858c;
  DAT_80398854 = _656;
  DAT_80398858 = DAT_80398594;
  DAT_8039885c = PTR_cmdWait_80398598;
  DAT_80398860 = _657;
  DAT_80398864 = DAT_803985a0;
  DAT_80398868 = PTR_cmdPanPowSet_803985a4;
  DAT_8039886c = _658;
  DAT_80398870 = DAT_803985ac;
  DAT_80398874 = PTR_cmdIIRSet_803985b0;
  DAT_80398878 = _659;
  DAT_8039887c = DAT_803985b8;
  DAT_80398880 = PTR_cmdFIRSet_803985bc;
  DAT_80398884 = _660;
  DAT_80398888 = DAT_803985c4;
  DAT_8039888c = PTR_cmdEXTSet_803985c8;
  DAT_80398890 = _661;
  DAT_80398894 = DAT_803985d0;
  DAT_80398898 = PTR_cmdPanSwSet_803985d4;
  DAT_8039889c = _662;
  DAT_803988a0 = DAT_803985dc;
  DAT_803988a4 = PTR_cmdOscRoute_803985e0;
  DAT_803988a8 = _663;
  DAT_803988ac = DAT_803985e8;
  DAT_803988b0 = PTR_cmdIIRCutOff_803985ec;
  DAT_803988b4 = _664;
  DAT_803988b8 = DAT_803985f4;
  DAT_803988bc = PTR_cmdOscFull_803985f8;
  DAT_803988c0 = _665;
  DAT_803988c4 = DAT_80398600;
  DAT_803988c8 = PTR_cmdVolumeMode_80398604;
  DAT_803988cc = _666;
  DAT_803988d0 = DAT_8039860c;
  DAT_803988d4 = PTR_cmdVibPitch_80398610;
  DAT_803988d8 = Runtime.PPCEABI.H::__ptmf_null;
  DAT_803988dc = DAT_80370fbc;
  DAT_803988e0 = DAT_80370fc0;
  DAT_803988e4 = Runtime.PPCEABI.H::__ptmf_null;
  DAT_803988e8 = DAT_80370fbc;
  DAT_803988ec = DAT_80370fc0;
  DAT_803988f0 = Runtime.PPCEABI.H::__ptmf_null;
  DAT_803988f4 = DAT_80370fbc;
  DAT_803988f8 = DAT_80370fc0;
  DAT_803988fc = Runtime.PPCEABI.H::__ptmf_null;
  DAT_80398900 = DAT_80370fbc;
  DAT_80398904 = DAT_80370fc0;
  DAT_80398908 = Runtime.PPCEABI.H::__ptmf_null;
  DAT_8039890c = DAT_80370fbc;
  DAT_80398910 = DAT_80370fc0;
  DAT_80398914 = _667;
  DAT_80398918 = DAT_80398618;
  DAT_8039891c = PTR_cmdCheckWave_8039861c;
  DAT_80398920 = _668;
  DAT_80398924 = DAT_80398624;
  DAT_80398928 = PTR_cmdPrintf_80398628;
  DAT_8039892c = _669;
  DAT_80398930 = DAT_80398630;
  DAT_80398934 = PTR_cmdNop_80398634;
  DAT_80398938 = _670;
  DAT_8039893c = DAT_8039863c;
  DAT_80398940 = PTR_cmdTempo_80398640;
  DAT_80398944 = _671;
  DAT_80398948 = DAT_80398648;
  DAT_8039894c = PTR_cmdTimeBase_8039864c;
  DAT_80398950 = _672;
  DAT_80398954 = DAT_80398654;
  DAT_80398958 = PTR_cmdFinish_80398658;
  return;
}

