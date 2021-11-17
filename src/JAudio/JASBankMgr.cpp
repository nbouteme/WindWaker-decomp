#include <JAudio/JASBankMgr.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JAudio/JASCalc.h>
#include <JAudio/JASBankMgr.h>
#include <JAudio/JASBNKParser.h>
#include <JAudio/JASWaveBankMgr.h>
#include <JAudio/JASChannelMgr.h>
#include <JAudio/JASChannel.h>
#include <JASystem/BankMgr.h>


namespace JASystem {
undefined1 BankMgr;
undefined1 BankMgr;
undefined1 BankMgr;

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall BankMgr::init(int) */

int __thiscall BankMgr::init(BankMgr *this,EVP_PKEY_CTX *ctx)

{
  ulong uVar1;
  int iVar2;
  undefined *__n;
  BankMgr *pBVar3;
  
  _sBankArray = (Calc *)JKernel::operator_new__((void *)((int)this << 2),JAudio::JASDram,0);
  if (_sBankArray == (Calc *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASBankMgr.cpp",0x45,"sBankArray != 0");
    m_Do_printf::OSPanic("JASBankMgr.cpp",0x45,&DAT_80367ee7);
  }
  __n = (undefined *)0x0;
  _sVir2PhyTable = JKernel::operator_new__((int)this << 1,JAudio::JASDram);
  if (_sVir2PhyTable == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASBankMgr.cpp",0x48,"sVir2PhyTable != 0");
    __n = &DAT_80367ee7;
    m_Do_printf::OSPanic("JASBankMgr.cpp",0x48);
  }
  Calc::bzero(_sBankArray,(void *)((int)this << 2),(size_t)__n);
  iVar2 = 0;
  pBVar3 = this;
  if (0 < (int)this) {
    do {
      *(undefined2 *)(_sVir2PhyTable + iVar2) = 0xffff;
      iVar2 = iVar2 + 2;
      pBVar3 = pBVar3 + -1;
    } while (pBVar3 != (BankMgr *)0x0);
  }
  _sTableSize = this;
  return iVar2;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall BankMgr::registBank(int,
                                            TBank *) */

undefined4 __thiscall BankMgr::registBank(BankMgr *this,int param_1,TBank *param_2)

{
  ulong uVar1;
  
  if ((int)this < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASBankMgr.cpp",0x56,"banknum >= 0");
    m_Do_printf::OSPanic("JASBankMgr.cpp",0x56,&DAT_80367ee7);
  }
  if (_sTableSize <= (int)this) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASBankMgr.cpp",0x57,"banknum < sTableSize");
    m_Do_printf::OSPanic("JASBankMgr.cpp",0x57,&DAT_80367ee7);
  }
  *(int *)(_sBankArray + (int)this * 4) = param_1;
  return 1;
}


/* __thiscall BankMgr::registBankBNK(int,
                                               void *) */

undefined4 __thiscall BankMgr::registBankBNK(BankMgr *this,int param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  void *extraout_r4;
  
  setVir2PhyTable(*(BankMgr **)(param_1 + 8),(ulong)this,(int)param_2);
  iVar1 = BNKParser::createBasicBank((BNKParser *)param_1,extraout_r4);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = registBank(this,iVar1,(TBank *)param_2);
  }
  return uVar2;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall BankMgr::getBank(int) */

undefined4 __thiscall BankMgr::getBank(BankMgr *this,int param_1)

{
  if ((int)this < 0) {
    return 0;
  }
  if (_sTableSize <= (int)this) {
    return 0;
  }
  return *(undefined4 *)(_sBankArray + (int)this * 4);
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall BankMgr::getPhysicalNumber(unsigned short) */

undefined2 __thiscall BankMgr::getPhysicalNumber(BankMgr *this,ushort param_1)

{
  return *(undefined2 *)(_sVir2PhyTable + ((uint)this & 0xffff) * 2);
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall BankMgr::setVir2PhyTable(unsigned long,
                                                 int) */

void __thiscall BankMgr::setVir2PhyTable(BankMgr *this,ulong param_1,int param_2)

{
  short sVar1;
  ulong uVar2;
  
  if (this != (BankMgr *)0xffff) {
    if (_sTableSize <= this) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"JASBankMgr.cpp",0x7f,"vir_id < sTableSize");
      m_Do_printf::OSPanic("JASBankMgr.cpp",0x7f,&DAT_80367ee7);
    }
    sVar1 = *(short *)(_sVir2PhyTable + (int)this * 2);
    if (sVar1 != -1) {
      m_Do_printf::OSReport("Warning : Duplicated Bank vir_id ID %d (%d,%d)\n",this,sVar1,param_1);
    }
    *(short *)(_sVir2PhyTable + (int)this * 2) = (short)param_1;
  }
  return;
}


/* __thiscall BankMgr::assignWaveBank(int,
                                                int) */

undefined4 __thiscall BankMgr::assignWaveBank(BankMgr *this,int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = getBank(this,param_1);
  iVar1 = (int)((ulonglong)uVar4 >> 0x20);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar3 = WaveBankMgr::getWaveBank((WaveBankMgr *)param_1,(int)uVar4);
    if (iVar3 == 0) {
      uVar2 = 0;
    }
    else {
      *(int *)(iVar1 + 4) = iVar3;
      uVar2 = 1;
    }
  }
  return uVar2;
}


/* __thiscall BankMgr::clamp01(float) */

double __thiscall BankMgr::clamp01(BankMgr *this,float param_1)

{
  double dVar1;
  
  dVar1 = (double)param_1;
  if (dVar1 < (double)JAudio::_720) {
    return (double)JAudio::_720;
  }
  if (dVar1 <= (double)JAudio::_721) {
    return dVar1;
  }
  return (double)JAudio::_721;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall BankMgr::noteOn(TChannelMgr *,
                                        int,
                                        int,
                                        unsigned char,
                                        unsigned char,
                                        unsigned long) */

TChannel * __thiscall
BankMgr::noteOn
          (BankMgr *this,TChannelMgr *param_1,int param_2,int param_3,uchar param_4,uchar param_5,
          ulong param_6)

{
  float fVar1;
  TChannel *this_00;
  int *piVar2;
  int *piVar3;
  char cVar6;
  int iVar4;
  int iVar5;
  TChannel *this_01;
  ulong uVar7;
  undefined3 in_register_00000020;
  uint uVar8;
  double extraout_f1;
  TChannel local_78 [4];
  undefined4 local_74;
  int local_70;
  uint local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  char local_40;
  ushort local_3e;
  int local_3c;
  uint local_38;
  undefined4 local_30;
  uint uStack44;
  
  if (param_2 < 0xf0) {
    piVar2 = (int *)getBank((BankMgr *)param_1,(int)param_1);
    if (piVar2 == (int *)0x0) {
      this_00 = (TChannel *)0x0;
    }
    else {
      piVar3 = (int *)(**(code **)(*piVar2 + 0xc))(piVar2,param_2);
      if (piVar3 == (int *)0x0) {
        this_00 = (TChannel *)0x0;
      }
      else {
        local_78[0] = (TChannel)0x0;
        local_74 = 0;
        local_70 = 0;
        local_6c = 0;
        local_68 = JAudio::_721;
        local_64 = JAudio::_721;
        local_60 = JAudio::_721;
        local_5c = JAudio::_721;
        local_58 = JAudio::_793;
        local_54 = JAudio::_720;
        local_50 = JAudio::_720;
        local_4c = JAudio::_793;
        local_48 = JAudio::_720;
        local_44 = JAudio::_720;
        local_40 = '\0';
        local_3e = 0;
        local_3c = 0;
        local_38 = 0;
        cVar6 = (**(code **)(*piVar3 + 0xc))(piVar3,param_3 & 0xffU,param_4,local_78);
        if (cVar6 == '\0') {
          this_00 = (TChannel *)0x0;
        }
        else {
          piVar2 = (int *)piVar2[1];
          if (piVar2 == (int *)0x0) {
            this_00 = (TChannel *)0x0;
          }
          else {
            piVar2 = (int *)(**(code **)(*piVar2 + 0xc))(piVar2,local_74);
            if (piVar2 == (int *)0x0) {
              this_00 = (TChannel *)0x0;
            }
            else {
              iVar4 = (**(code **)(*piVar2 + 0xc))();
              if (iVar4 == 0) {
                this_00 = (TChannel *)0x0;
              }
              else {
                iVar5 = (**(code **)(*piVar2 + 0x10))(piVar2);
                if (iVar5 == 0) {
                  this_00 = (TChannel *)0x0;
                }
                else {
                  uVar7 = param_2 | local_38 << 0x18 | (int)param_1 << 8;
                  uVar8 = local_38 & 0xc0;
                  if (uVar8 == 0x80) {
                    uVar7 = uVar7 | 0xff;
                  }
                  else {
                    if (uVar8 < 0x80) {
                      if (uVar8 == 0x40) {
                        uVar7 = uVar7 | local_3c << 0x10;
                      }
                    }
                    else {
                      if (uVar8 == 0xc0) {
                        uVar7 = uVar7 | 0xffffff;
                      }
                    }
                  }
                  this_00 = (TChannel *)TChannelMgr::getLogicalChannel((TChannelMgr *)this,uVar7);
                  if (this_00 == (TChannel *)0x0) {
                    this_00 = (TChannel *)0x0;
                  }
                  else {
                    *(int *)(this_00 + 0x10) = iVar4;
                    *(int *)(this_00 + 0x14) = iVar5;
                    this_00[0xc] = local_78[0];
                    *this_00 = (TChannel)param_4;
                    this_00[1] = SUB41(param_3,0);
                    *(float *)(this_00 + 0x50) = local_64 * (*(float *)(iVar4 + 4) / _gDacRate);
                    *(float *)(this_00 + 0x58) = *(float *)(this_00 + 0x50) * local_5c;
                    this_01 = this_00;
                    if (local_40 == '\0') {
                      iVar4 = ((param_3 & 0xffU) + 0x3c) - (uint)*(byte *)(iVar4 + 2);
                      if (iVar4 < 0) {
                        iVar4 = 0;
                      }
                      if (0x7f < iVar4) {
                        iVar4 = 0x7f;
                      }
                      this_01 = (TChannel *)&Driver::C5BASE_PITCHTABLE;
                      *(float *)(this_00 + 0x58) =
                           *(float *)(this_00 + 0x58) *
                           *(float *)(&Driver::C5BASE_PITCHTABLE + iVar4 * 4);
                    }
                    *(float *)(this_00 + 0x54) = local_68;
                    uStack44 = (uint)(byte)*this_00;
                    local_30 = 0x43300000;
                    *(float *)(this_00 + 0x5c) =
                         (float)((double)CONCAT44(0x43300000,uStack44) - JAudio::_796) /
                         JAudio::_794;
                    *(float *)(this_00 + 0x5c) =
                         *(float *)(this_00 + 0x54) *
                         *(float *)(this_00 + 0x5c) * *(float *)(this_00 + 0x5c);
                    *(float *)(this_00 + 0x5c) = *(float *)(this_00 + 0x5c) * local_60;
                    *(float *)(this_00 + 0x70) = local_58;
                    *(float *)(this_00 + 0x7c) = local_54;
                    *(float *)(this_00 + 0x88) = local_50;
                    iVar5 = 1;
                    iVar4 = 0xc;
                    do {
                      this_01 = (TChannel *)
                                clamp01((BankMgr *)this_01,*(float *)(this_00 + iVar4 + 100));
                      *(float *)(this_00 + iVar4 + 100) = (float)extraout_f1;
                      iVar5 = iVar5 + 1;
                      iVar4 = iVar4 + 0xc;
                    } while (iVar5 < 3);
                    *(float *)(this_00 + 0x74) = local_4c;
                    *(float *)(this_00 + 0x80) = local_48;
                    *(float *)(this_00 + 0x8c) = local_44;
                    fVar1 = JAudio::_721;
                    *(float *)(this_00 + 0x94) = JAudio::_721;
                    *(float *)(this_00 + 0x98) = fVar1;
                    iVar4 = 0;
                    for (uVar8 = 0; uVar8 < local_6c; uVar8 = uVar8 + 1) {
                      TChannel::setOscInit(this_00,uVar8,*(Osc_ **)(local_70 + iVar4));
                      iVar4 = iVar4 + 4;
                    }
                    TChannel::directReleaseOsc(this_00,0,local_3e);
                    iVar4 = TChannel::play(this_00,CONCAT31(in_register_00000020,param_5));
                    if (iVar4 == 0) {
                      this_00 = (TChannel *)0x0;
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
  else {
    this_00 = (TChannel *)
              noteOnOsc(this,(TChannelMgr *)(param_2 + -0xf0),param_3,param_4,param_5,
                        CONCAT31(in_register_00000020,param_5));
  }
  return this_00;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80288d58) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall BankMgr::noteOnOsc(TChannelMgr *,
                                           int,
                                           unsigned char,
                                           unsigned char,
                                           unsigned long) */

TChannel * __thiscall
BankMgr::noteOnOsc
          (BankMgr *this,TChannelMgr *param_1,int param_2,uchar param_3,uchar param_4,ulong param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  TChannel *this_00;
  int iVar5;
  undefined3 in_register_0000001c;
  
  this_00 = (TChannel *)TChannelMgr::getLogicalChannel((TChannelMgr *)this,0);
  if (this_00 == (TChannel *)0x0) {
    this_00 = (TChannel *)0x0;
  }
  else {
    *(TChannelMgr **)(this_00 + 0x14) = param_1;
    this_00[0xc] = (TChannel)0x2;
    *this_00 = (TChannel)param_3;
    this_00[1] = SUB41(param_2,0);
    *(float *)(this_00 + 0x50) = JAudio::_813 / _gDacRate;
    *(undefined4 *)(this_00 + 0x58) = *(undefined4 *)(this_00 + 0x50);
    uVar4 = param_2 & 0xff;
    if (0x7f < uVar4) {
      uVar4 = 0x7f;
    }
    *(float *)(this_00 + 0x58) =
         *(float *)(this_00 + 0x58) * *(float *)(&Driver::C5BASE_PITCHTABLE + uVar4 * 4);
    fVar2 = JAudio::_721;
    *(float *)(this_00 + 0x54) = JAudio::_721;
    *(float *)(this_00 + 0x5c) =
         (float)((double)CONCAT44(0x43300000,(uint)(byte)*this_00) - JAudio::_796) / JAudio::_794;
    *(float *)(this_00 + 0x5c) =
         *(float *)(this_00 + 0x54) * *(float *)(this_00 + 0x5c) * *(float *)(this_00 + 0x5c);
    fVar3 = JAudio::_793;
    *(float *)(this_00 + 0x70) = JAudio::_793;
    fVar1 = JAudio::_720;
    *(float *)(this_00 + 0x7c) = JAudio::_720;
    *(float *)(this_00 + 0x88) = fVar1;
    *(float *)(this_00 + 0x74) = fVar3;
    *(float *)(this_00 + 0x80) = fVar1;
    *(float *)(this_00 + 0x8c) = fVar1;
    *(float *)(this_00 + 0x94) = fVar2;
    *(float *)(this_00 + 0x98) = fVar2;
    TChannel::setOscInit(this_00,0,(Osc_ *)&OSC_ENV);
    *(undefined4 *)(this_00 + 0xcc) = 0;
    iVar5 = TChannel::play(this_00,CONCAT31(in_register_0000001c,param_4));
    if (iVar5 == 0) {
      this_00 = (TChannel *)0x0;
    }
  }
  return this_00;
}


/* __thiscall BankMgr::gateOn(TChannel *,
                                        unsigned char,
                                        unsigned char,
                                        unsigned long) */

void __thiscall
BankMgr::gateOn(BankMgr *this,TChannel *param_1,uchar param_2,uchar param_3,ulong param_4)

{
  float fVar1;
  uint uVar2;
  undefined3 in_register_00000018;
  
  if (*(int *)(this + 0x30) == -1) {
    *(uint *)(this + 0x30) = CONCAT31(in_register_00000018,param_3);
    *(undefined4 *)(this + 0x34) = *(undefined4 *)(this + 0x30);
    if (this[0xc] == (BankMgr)0x2) {
      uVar2 = (uint)param_1 & 0xff;
    }
    else {
      uVar2 = (((uint)param_1 & 0xff) + 0x3c) - (uint)*(byte *)(*(int *)(this + 0x10) + 2);
    }
    if ((int)uVar2 < 0) {
      uVar2 = 0;
    }
    if (0x7f < (int)uVar2) {
      uVar2 = 0x7f;
    }
    fVar1 = *(float *)(&Driver::C5BASE_PITCHTABLE + uVar2 * 4);
    *this = (BankMgr)param_2;
    this[1] = SUB41(param_1,0);
    *(float *)(this + 0x58) = *(float *)(this + 0x50) * fVar1;
    *(float *)(this + 0x5c) =
         (float)((double)CONCAT44(0x43300000,(uint)(byte)*this) - JAudio::_796) / JAudio::_794;
    *(float *)(this + 0x5c) =
         *(float *)(this + 0x54) * *(float *)(this + 0x5c) * *(float *)(this + 0x5c);
  }
  return;
}

