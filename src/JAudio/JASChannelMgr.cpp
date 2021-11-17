#include <JAudio/JASChannelMgr.h>
#include <JAudio/JASChannel.h>
#include <m_Do_printf.h>
#include <JAudio/JASChGlobal.h>
#include <JAudio/JASChannelMgr.h>
#include <JAudio/JASDSPChannel.h>
#include <JAudio/JASChAllocQueue.h>
#include <Demangler/JASystem/TChannelMgr.h>


namespace JASystem {

/* __thiscall TChannelMgr::init(void) */

int __thiscall TChannelMgr::init(TChannelMgr *this,EVP_PKEY_CTX *ctx)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 0x70) = 1;
  fVar1 = JAudio::_357;
  *(float *)(this + 0x18) = JAudio::_357;
  *(float *)(this + 0x1c) = fVar1;
  *(float *)(this + 0x20) = JAudio::_358;
  fVar1 = JAudio::_359;
  *(float *)(this + 0x24) = JAudio::_359;
  *(float *)(this + 0x28) = fVar1;
  iVar2 = 0;
  iVar3 = 8;
  do {
    *(undefined2 *)(this + iVar2 + 0x2c) = 0;
    iVar2 = iVar2 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined2 *)(this + 0x2c) = 0x7fff;
  *(undefined2 *)(this + 0x4c) = 0;
  iVar2 = 0;
  iVar3 = 4;
  do {
    *(undefined2 *)(this + iVar2 + 0x3c) = 0;
    iVar2 = iVar2 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar2 = 0;
  iVar3 = 6;
  do {
    this[iVar2 + 0x5a] = (TChannelMgr)0x0;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  this[0x60] = (TChannelMgr)0x0;
  *(undefined2 *)(this + 0x3c) = 0x7fff;
  this[0x61] = (TChannelMgr)0x0;
  *(undefined2 *)(this + 0x4e) = 0x150;
  *(undefined2 *)(this + 0x50) = 0x210;
  *(undefined2 *)(this + 0x52) = 0x352;
  *(undefined2 *)(this + 0x54) = 0x412;
  *(undefined2 *)(this + 0x56) = 0;
  *(undefined2 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x68) = 0x20103;
  *(undefined2 *)(this + 0x6c) = 600;
  this[0x62] = (TChannelMgr)0xd;
  this[99] = (TChannelMgr)0xd;
  this[100] = (TChannelMgr)0xd;
  return (int)this;
}


/* __thiscall TChannelMgr::stopAll(void) */

void __thiscall TChannelMgr::stopAll(TChannelMgr *this)

{
  TChannel *this_00;
  TChannel *pTVar1;
  
  this_00 = *(TChannel **)(this + 0xc);
  while (this_00 != (TChannel *)0x0) {
    pTVar1 = *(TChannel **)(this_00 + 0x24);
    TChannel::stop(this_00,0);
    this_00 = pTVar1;
  }
  return;
}


/* __thiscall TChannelMgr::stopAllRelease(void) */

void __thiscall TChannelMgr::stopAllRelease(TChannelMgr *this)

{
  TChannel *this_00;
  
  for (this_00 = *(TChannel **)(this + 0x10); this_00 != (TChannel *)0x0;
      this_00 = *(TChannel **)(this_00 + 0x24)) {
    TChannel::forceStopOsc(this_00,0);
  }
  return;
}


/* __thiscall TChannelMgr::initAllocChannel(unsigned long) */

void __thiscall TChannelMgr::initAllocChannel(TChannelMgr *this,ulong param_1)

{
  EVP_PKEY_CTX *ctx;
  TChannelMgr *extraout_r4;
  EVP_PKEY_CTX *extraout_r4_00;
  ulong in_r5;
  
  ctx = *(EVP_PKEY_CTX **)this;
  if (ctx != (EVP_PKEY_CTX *)0x0) {
    m_Do_printf::OSReport
              (
              "----- Warning JCSにボイスが %d 残っているのでグローバルに返却します\n"
              );
    TGlobalChannel::releaseAll((TGlobalChannel *)this,extraout_r4);
    ctx = extraout_r4_00;
  }
  init(this,ctx);
  TGlobalChannel::alloc((TGlobalChannel *)this,(TChannelMgr *)param_1,in_r5);
  *(uint *)(this + 0x70) = (uint)(param_1 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall TChannelMgr::getLogicalChannel(unsigned long) */

TChannel * __thiscall TChannelMgr::getLogicalChannel(TChannelMgr *this,ulong param_1)

{
  bool bVar1;
  int iVar2;
  TChannel *pTVar3;
  uint extraout_r4;
  uint extraout_r4_00;
  uint extraout_r4_01;
  ulong in_r5;
  ulonglong uVar4;
  
  bVar1 = false;
  iVar2 = checkLimitStart(this,param_1);
  if (iVar2 == 0) {
    if ((param_1 >> 0x18 & 0x10) != 0) {
      return (TChannel *)0x0;
    }
    bVar1 = true;
  }
  uVar4 = getListHead(this,0);
  if ((int)(uVar4 >> 0x20) == 0) {
    iVar2 = TGlobalChannel::alloc((TGlobalChannel *)this,(TChannelMgr *)&DAT_00000001,in_r5);
    if (iVar2 == 0) {
      m_Do_printf::OSReport("----- getLC グローバル論理チャンネルの残りがない\n");
      return (TChannel *)0x0;
    }
    *(int *)(this + 4) = *(int *)(this + 4) + 1;
    uVar4 = getListHead(this,0);
    if (*(int *)(this + 0x70) == 1) {
      pTVar3 = (TChannel *)getListHead(this,2);
      if ((pTVar3 == (TChannel *)0x0) &&
         (pTVar3 = (TChannel *)getListHead(this,1), pTVar3 == (TChannel *)0x0)) {
        m_Do_printf::OSReport("----- getLC Error ----- fjc is NULL again\n");
      }
      if (pTVar3 == (TChannel *)0x0) {
        m_Do_printf::OSReport("cannot FORCESTOP (thisの論理ボイスが飽和?)\n");
        uVar4 = uVar4 & 0xffffffff00000000 | (ulonglong)extraout_r4_01;
      }
      else {
        TChannel::forceStopOsc(pTVar3,0);
        addListHead(this,pTVar3,3);
        if (*(TDSPChannel **)(pTVar3 + 0x20) == (TDSPChannel *)0x0) {
          m_Do_printf::OSReport("----- getLC -----does not have DSP CH\n");
          uVar4 = uVar4 & 0xffffffff00000000 | (ulonglong)extraout_r4_00;
        }
        else {
          TDSPChannel::forceStop(*(TDSPChannel **)(pTVar3 + 0x20));
          uVar4 = uVar4 & 0xffffffff00000000 | (ulonglong)extraout_r4;
        }
      }
    }
  }
  pTVar3 = (TChannel *)(uVar4 >> 0x20);
  TChannel::init(pTVar3,(EVP_PKEY_CTX *)uVar4);
  if (bVar1) {
    pTVar3[2] = (TChannel)0x1;
    pTVar3[3] = (TChannel)0x1;
  }
  *(ulong *)(pTVar3 + 0xcc) = param_1;
  *(undefined4 *)(pTVar3 + 0x18) = 0;
  TChannel::setPanPower(pTVar3,JAudio::_357,JAudio::_357,JAudio::_357,JAudio::_357);
  return pTVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TChannelMgr::moveListHead(TChannel *,
                                                  unsigned long) */

bool __thiscall
TChannelMgr::moveListHead(TChannelMgr *this,TChannel *param_1,ulong param_2)

{
  int iVar1;
  
  iVar1 = cutList(this,param_1);
  if (iVar1 != -1) {
    addListHead(this,param_1,param_2);
  }
  return iVar1 != -1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TChannelMgr::moveListTail(TChannel *,
                                                  unsigned long) */

bool __thiscall
TChannelMgr::moveListTail(TChannelMgr *this,TChannel *param_1,ulong param_2)

{
  int iVar1;
  
  iVar1 = cutList(this,param_1);
  if (iVar1 != -1) {
    addListTail(this,param_1,param_2);
  }
  return iVar1 != -1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TChannelMgr::addListHead(TChannel *,
                                                 unsigned long) */

void __thiscall
TChannelMgr::addListHead(TChannelMgr *this,TChannel *param_1,ulong param_2)

{
  TChannel *pTVar1;
  TChannel **ppTVar2;
  
  if (param_2 == 2) {
    ppTVar2 = (TChannel **)(this + 0x10);
    goto LAB_8028d89c;
  }
  if ((int)param_2 < 2) {
    if (param_2 == 0) {
      ppTVar2 = (TChannel **)(this + 8);
      goto LAB_8028d89c;
    }
    if (-1 < (int)param_2) {
      ppTVar2 = (TChannel **)(this + 0xc);
      goto LAB_8028d89c;
    }
  }
  else {
    if ((int)param_2 < 4) {
      ppTVar2 = (TChannel **)(this + 0x14);
      goto LAB_8028d89c;
    }
  }
  ppTVar2 = (TChannel **)0x0;
LAB_8028d89c:
  pTVar1 = *ppTVar2;
  if (*(int *)(param_1 + 8) != 0) {
    m_Do_printf::OSReport("RootJc Error 2\n");
  }
  *(TChannel ***)(param_1 + 8) = ppTVar2;
  *ppTVar2 = param_1;
  *(TChannel **)(param_1 + 0x24) = pTVar1;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TChannelMgr::addListTail(TChannel *,
                                                 unsigned long) */

void __thiscall
TChannelMgr::addListTail(TChannelMgr *this,TChannel *param_1,ulong param_2)

{
  TChannel *pTVar1;
  TChannel *pTVar2;
  TChannel **ppTVar3;
  
  if (param_2 == 2) {
    ppTVar3 = (TChannel **)(this + 0x10);
    goto LAB_8028d948;
  }
  if ((int)param_2 < 2) {
    if (param_2 == 0) {
      ppTVar3 = (TChannel **)(this + 8);
      goto LAB_8028d948;
    }
    if (-1 < (int)param_2) {
      ppTVar3 = (TChannel **)(this + 0xc);
      goto LAB_8028d948;
    }
  }
  else {
    if ((int)param_2 < 4) {
      ppTVar3 = (TChannel **)(this + 0x14);
      goto LAB_8028d948;
    }
  }
  ppTVar3 = (TChannel **)0x0;
LAB_8028d948:
  pTVar1 = *ppTVar3;
  if (*(int *)(param_1 + 8) != 0) {
    m_Do_printf::OSReport("ROOTJC Error\n");
  }
  *(TChannel ***)(param_1 + 8) = ppTVar3;
  if (pTVar1 == (TChannel *)0x0) {
    *ppTVar3 = param_1;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  else {
    do {
      pTVar2 = pTVar1;
      pTVar1 = *(TChannel **)(pTVar2 + 0x24);
    } while (pTVar1 != (TChannel *)0x0);
    *(TChannel **)(pTVar2 + 0x24) = param_1;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


/* __thiscall TChannelMgr::getListHead(unsigned long) */

int __thiscall TChannelMgr::getListHead(TChannelMgr *this,ulong param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 2) {
    piVar2 = (int *)(this + 0x10);
    goto LAB_8028da10;
  }
  if ((int)param_1 < 2) {
    if (param_1 == 0) {
      piVar2 = (int *)(this + 8);
      goto LAB_8028da10;
    }
    if (-1 < (int)param_1) {
      piVar2 = (int *)(this + 0xc);
      goto LAB_8028da10;
    }
  }
  else {
    if ((int)param_1 < 4) {
      piVar2 = (int *)(this + 0x14);
      goto LAB_8028da10;
    }
  }
  piVar2 = (int *)0x0;
LAB_8028da10:
  iVar1 = *piVar2;
  if (iVar1 != 0) {
    *piVar2 = *(int *)(iVar1 + 0x24);
    *(undefined4 *)(iVar1 + 8) = 0;
    return iVar1;
  }
  return 0;
}


/* __thiscall TChannelMgr::cutList(TChannel *) */

int __thiscall TChannelMgr::cutList(TChannelMgr *this,TChannel *param_1)

{
  int iVar1;
  TChannel *pTVar2;
  TChannel *pTVar3;
  
  iVar1 = 0;
  pTVar2 = **(TChannel ***)(param_1 + 8);
  if (pTVar2 == (TChannel *)0x0) {
    m_Do_printf::OSReport("cutChList Error: No Member\n");
    iVar1 = -1;
  }
  else {
    if (pTVar2 == param_1) {
      **(TChannel ***)(param_1 + 8) = *(TChannel **)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 8) = 0;
      iVar1 = 0;
    }
    else {
      do {
        pTVar3 = pTVar2;
        iVar1 = iVar1 + 1;
        if (pTVar3 == (TChannel *)0x0) {
          m_Do_printf::OSReport("cutChList Error: Not Member\n");
          return -1;
        }
        pTVar2 = *(TChannel **)(pTVar3 + 0x24);
      } while (*(TChannel **)(pTVar3 + 0x24) != param_1);
      *(undefined4 *)(pTVar3 + 0x24) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 8) = 0;
    }
  }
  return iVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall TChannelMgr::receiveAllChannels(TChannelMgr *) */

undefined4 __thiscall
TChannelMgr::receiveAllChannels(TChannelMgr *this,TChannelMgr *param_1)

{
  TChannel *pTVar1;
  TDSPQueue *this_00;
  int iVar2;
  undefined8 uVar3;
  
  while (pTVar1 = (TChannel *)getListHead(param_1,0), pTVar1 != (TChannel *)0x0) {
    addListHead(this,pTVar1,0);
    *(TChannelMgr **)(pTVar1 + 4) = this;
  }
  while (pTVar1 = (TChannel *)getListHead(param_1,1), pTVar1 != (TChannel *)0x0) {
    addListHead(this,pTVar1,1);
    *(TChannelMgr **)(pTVar1 + 4) = this;
    *(undefined4 *)(pTVar1 + 0xd4) = 1;
  }
  while (pTVar1 = (TChannel *)getListHead(param_1,2), pTVar1 != (TChannel *)0x0) {
    addListHead(this,pTVar1,2);
    *(TChannelMgr **)(pTVar1 + 4) = this;
    *(undefined4 *)(pTVar1 + 0xd4) = 1;
  }
  while( true ) {
    uVar3 = getListHead(param_1,3);
    this_00 = (TDSPQueue *)((ulonglong)uVar3 >> 0x20);
    if (this_00 == (TDSPQueue *)0x0) break;
    iVar2 = TDSPQueue::deleteQueue(this_00,(TChannel *)uVar3);
    if (iVar2 == 0) {
      addListHead(this,(TChannel *)this_00,3);
    }
    else {
      addListHead(this,(TChannel *)this_00,0);
    }
    *(TChannelMgr **)(this_00 + 4) = this;
  }
  *(int *)this = *(int *)this + *(int *)param_1;
  *(undefined4 *)param_1 = 0;
  *(int *)(this + 4) = *(int *)(this + 4) + *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = 0;
  return 0;
}


/* __thiscall TChannelMgr::checkLimitStart(unsigned long) */

undefined4 __thiscall TChannelMgr::checkLimitStart(TChannelMgr *this,ulong param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  TChannel *pTVar5;
  TChannel *this_00;
  
  bVar1 = (&Driver::polys_table)[param_1 >> 0x18 & 0xf];
  if (bVar1 == 0) {
    uVar2 = 1;
  }
  else {
    uVar4 = 0;
    pTVar5 = *(TChannel **)(this + 0x10);
    if ((param_1 >> 0x18 & 0x20) == 0) {
      this_00 = (TChannel *)0x0;
      while (pTVar5 != (TChannel *)0x0) {
        if ((*(ulong *)(pTVar5 + 0xcc) == param_1) && (pTVar5[2] == (TChannel)0x0)) {
          if (this_00 == (TChannel *)0x0) {
            this_00 = pTVar5;
          }
          if (uVar4 == bVar1) {
            TChannel::forceStopLogicalChannel(this_00);
            return 1;
          }
          uVar4 = uVar4 + 1;
        }
      }
      pTVar5 = *(TChannel **)(this + 0xc);
      while (pTVar5 != (TChannel *)0x0) {
        if ((*(ulong *)(pTVar5 + 0xcc) == param_1) && (pTVar5[2] == (TChannel)0x0)) {
          if (this_00 == (TChannel *)0x0) {
            this_00 = pTVar5;
          }
          if (uVar4 == bVar1) {
            if ((param_1 >> 0x18 & 0x10) == 0) {
              TChannel::setPauseFlagReq(pTVar5,'\x01');
            }
            else {
              TChannel::forceStopLogicalChannel(this_00);
            }
            return 1;
          }
          uVar4 = uVar4 + 1;
        }
      }
      uVar2 = 1;
    }
    else {
      while (pTVar5 != (TChannel *)0x0) {
        if ((*(ulong *)(pTVar5 + 0xcc) == param_1) && (pTVar5[2] == (TChannel)0x0)) {
          uVar4 = uVar4 + 1;
        }
      }
      iVar3 = *(int *)(this + 0xc);
      while (iVar3 != 0) {
        if ((*(ulong *)(iVar3 + 0xcc) == param_1) && (*(char *)(iVar3 + 2) == '\0')) {
          uVar4 = uVar4 + 1;
        }
      }
      if (uVar4 == bVar1) {
        uVar2 = 0;
      }
      else {
        if (bVar1 < uVar4) {
          m_Do_printf::OSReport("----- checkLimitStart Why? chNum is over\n");
          uVar2 = 0;
        }
        else {
          uVar2 = 1;
        }
      }
    }
  }
  return uVar2;
}


/* __thiscall TChannelMgr::checkLimitStop(TChannel *,
                                                    unsigned long) */

void __thiscall
TChannelMgr::checkLimitStop(TChannelMgr *this,TChannel *param_1,ulong param_2)

{
  TChannel *this_00;
  TChannel *this_01;
  
  this_00 = *(TChannel **)(this + 0xc);
  if ((param_2 != 0) && ((&Driver::polys_table)[param_2 >> 0x18 & 0xf] != '\0')) {
    if ((param_2 >> 0x18 & 0x20) == 0) {
      this_01 = (TChannel *)0x0;
      for (; this_00 != (TChannel *)0x0; this_00 = *(TChannel **)(this_00 + 0x24)) {
        if ((*(ulong *)(this_00 + 0xcc) == param_2) && (this_00[2] == (TChannel)0x1)) {
          this_01 = this_00;
        }
      }
      if (this_01 != (TChannel *)0x0) {
        TChannel::setPauseFlagReq(this_01,'\0');
      }
    }
    else {
      for (; this_00 != (TChannel *)0x0; this_00 = *(TChannel **)(this_00 + 0x24)) {
        if ((*(ulong *)(this_00 + 0xcc) == param_2) && (this_00[2] == (TChannel)0x1)) {
          TChannel::setPauseFlagReq(this_00,'\0');
          return;
        }
      }
    }
  }
  return;
}

