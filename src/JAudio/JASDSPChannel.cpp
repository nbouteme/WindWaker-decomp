#include <JAudio/JASDSPChannel.h>
#include <JAudio/JASDSPInterface.h>
#include <m_Do_printf.h>
#include <JKernel/JKRHeap.h>
#include <JAudio/JASDSPChannel.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JUtility/JUTAssert.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <os/OSTime.h>
#include <JAudio/JASChAllocQueue.h>
#include <JAudio/dspproc.h>
#include <JASystem/TDSPChannel.h>


namespace JASystem {
undefined1 TDSPChannel;
undefined1 TDSPChannel;
}

namespace JAudio {
undefined4 first$417;
undefined1 init$418;
}

namespace JASystem {
undefined1 old_time;

/* __thiscall TDSPChannel::init(unsigned char) */

int __thiscall TDSPChannel::init(TDSPChannel *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  *this = SUB41(ctx,0);
  this[1] = (TDSPChannel)0x1;
  *(undefined4 *)(this + 8) = 0;
  *(undefined2 *)(this + 6) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  this[3] = (TDSPChannel)0x0;
  *(undefined2 *)(this + 4) = 0;
  iVar1 = DSPInterface::getDSPHandle((DSPInterface *)ctx,(uchar)SUB41(ctx,0));
  *(int *)(this + 0xc) = iVar1;
  return iVar1;
}


/* __thiscall TDSPChannel::allocate(unsigned long) */

undefined4 __thiscall TDSPChannel::allocate(TDSPChannel *this,ulong param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (this[1] == (TDSPChannel)0x1) {
    uVar1 = countLeadingZeros(*(undefined4 *)(this + 8));
    if (uVar1 >> 5 == 0) {
      m_Do_printf::OSReport
                ("sign %x があるのにCH.%d はFREE\n",*(undefined4 *)(this + 8),*this);
    }
    this[1] = (TDSPChannel)0x0;
    *(ulong *)(this + 8) = param_1;
    this[3] = (TDSPChannel)0x1;
    DSPInterface::DSPBuffer::allocInit(*(DSPBuffer **)(this + 0xc));
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __thiscall TDSPChannel::free(void) */

void __thiscall TDSPChannel::free(TDSPChannel *this,void *__ptr)

{
  this[1] = (TDSPChannel)0x1;
  this[3] = (TDSPChannel)0x0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TDSPChannel::forceStop(void) */

undefined4 __thiscall TDSPChannel::forceStop(TDSPChannel *this)

{
  undefined4 uVar1;
  
  if (this[1] == (TDSPChannel)0x2) {
    uVar1 = 0;
  }
  else {
    if (this[1] == (TDSPChannel)0x1) {
      m_Do_printf::OSReport("----- JASDSPChannel::forceStop Warning! : CH_FREE\n");
      uVar1 = 0;
    }
    else {
      if (**(short **)(this + 0xc) == 0) {
        uVar1 = 0;
      }
      else {
        _smnUse = _smnUse + -1;
        *(undefined2 *)(*(int *)(this + 0xc) + 0x10a) = 1;
        DSPInterface::DSPBuffer::flushChannel(*(DSPBuffer **)(this + 0xc));
        this[1] = (TDSPChannel)0x2;
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}


/* __thiscall TDSPChannel::forceDelete(void) */

void __thiscall TDSPChannel::forceDelete(TDSPChannel *this)

{
  *(undefined4 *)(this + 8) = 0;
  this[3] = (TDSPChannel)0x0;
  *(undefined4 *)(this + 0x10) = 0;
  return;
}


/* __thiscall TDSPChannel::play(void) */

void __thiscall TDSPChannel::play(TDSPChannel *this)

{
  if (*(int *)(this + 0x10) == 0) {
    *(undefined4 *)(*(int *)(this + 0xc) + 0x68) = 0;
  }
  DSPInterface::DSPBuffer::playStart(*(DSPBuffer **)(this + 0xc));
  DSPInterface::DSPBuffer::flushChannel(*(DSPBuffer **)(this + 0xc));
  return;
}


/* __thiscall TDSPChannel::stop(void) */

void __thiscall TDSPChannel::stop(TDSPChannel *this)

{
  **(undefined2 **)(this + 0xc) = 0;
  DSPInterface::DSPBuffer::flushChannel(*(DSPBuffer **)(this + 0xc));
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TDSPChannel::initAll(void) */

void __thiscall TDSPChannel::initAll(TDSPChannel *this)

{
  undefined4 uVar1;
  ulong uVar2;
  EVP_PKEY_CTX *ctx;
  
  if (JAudio::init_418 == '\0') {
    JAudio::first_417 = 1;
    JAudio::init_418 = '\x01';
  }
  if (JAudio::first_417 == 0) {
    m_Do_printf::OSReport("---- DSPChannel::initAll : already initialized\n");
  }
  else {
    uVar1 = JKernel::operator_new__(0x510,JAudio::JASDram,0x20);
    _DSPCH = Runtime.PPCEABI.H::__construct_new_array(uVar1,TDSPChannel,_TDSPChannel,0x14,0x40);
    if (_DSPCH == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"JASDSPChannel.cpp",0xcc,"DSPCH");
      m_Do_printf::OSPanic("JASDSPChannel.cpp",0xcc,&DAT_80368133);
    }
    m_Do_printf::OSReport("----- JASDSPChannel size : %d\n",0x14);
    for (ctx = (EVP_PKEY_CTX *)0x0; ((uint)ctx & 0xff) < 0x40; ctx = ctx + 1) {
      init((TDSPChannel *)(_DSPCH + ((uint)ctx & 0xff) * 0x14),ctx);
    }
    JAudio::first_417 = 0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TDSPChannel::alloc(unsigned long,
                                           unsigned long) */

int __thiscall TDSPChannel::alloc(TDSPChannel *this,ulong param_1,ulong param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (this == (TDSPChannel *)0x0) {
    iVar3 = 0;
    iVar4 = 0;
    do {
      uVar1 = countLeadingZeros(1 - (uint)(byte)((TDSPChannel *)(_DSPCH + iVar4))[1]);
      if ((uVar1 >> 5 != 0) &&
         (iVar2 = allocate((TDSPChannel *)(_DSPCH + iVar4),param_1), iVar2 != 0)) {
        _smnFree = _smnFree + -1;
        _smnUse = _smnUse + 1;
        return _DSPCH + iVar4;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x14;
    } while (iVar3 < 0x40);
  }
  else {
    m_Do_printf::OSReport
              (
              "----- JASDSPChannel::alloc : 多チャネルモードはサポートされていません\n"
              );
  }
  return 0;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TDSPChannel::free(TDSPChannel *,
                                          unsigned long) */

void __thiscall TDSPChannel::free(TDSPChannel *this,void *__ptr)

{
  if (this == (TDSPChannel *)0x0) {
    m_Do_printf::OSReport
              ("----- JASDSPChannel::free : NULL のチャネルを解放しようとしました\n"
              );
  }
  else {
    if (*(void **)(this + 8) == __ptr) {
      if (this[1] == (TDSPChannel)0x0) {
        __ptr = _smnUse;
        _smnUse = (void *)((int)_smnUse + -1);
      }
      if (this[1] != (TDSPChannel)0x1) {
        __ptr = _smnFree;
        _smnFree = (void *)((int)_smnFree + 1);
      }
      free(this,__ptr);
    }
    else {
      m_Do_printf::OSReport("----- JASDSPChannel::free : BAD USERが開放を試みた\n");
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TDSPChannel::getLower(void) */

int __thiscall TDSPChannel::getLower(TDSPChannel *this)

{
  ulong uVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  
  bVar7 = 0xff;
  bVar5 = 0;
  uVar4 = 0;
  for (bVar3 = 0; bVar6 = bVar5, bVar3 < 0x40; bVar3 = bVar3 + 1) {
    pbVar2 = (byte *)(_DSPCH + (uint)bVar3 * 0x14);
    if (pbVar2[1] != 2) {
      bVar6 = bVar3;
      if (pbVar2[1] == 1) break;
      if ((*(int *)(pbVar2 + 0x10) != 0) && (bVar6 = pbVar2[3], bVar6 <= bVar7)) {
        if ((uint)bVar3 != (uint)*pbVar2) {
          uVar1 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar1,"JASDSPChannel.cpp",0x131,"i == dspch->getNumber()");
          m_Do_printf::OSPanic("JASDSPChannel.cpp",0x131,&DAT_80368133);
        }
        if ((bVar6 != bVar7) || (uVar4 <= *(uint *)(*(int *)(pbVar2 + 0xc) + 0x10c))) {
          uVar4 = *(uint *)(*(int *)(pbVar2 + 0xc) + 0x10c);
          bVar7 = bVar6;
          bVar5 = bVar3;
        }
      }
    }
  }
  return _DSPCH + (uint)bVar6 * 0x14;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TDSPChannel::getLowerActive(void) */

int __thiscall TDSPChannel::getLowerActive(TDSPChannel *this)

{
  byte bVar1;
  ulong uVar2;
  byte *pbVar3;
  uint uVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  
  bVar6 = 0xff;
  bVar5 = 0;
  uVar4 = 0;
  for (bVar7 = 0; bVar7 < 0x40; bVar7 = bVar7 + 1) {
    pbVar3 = (byte *)(_DSPCH + (uint)bVar7 * 0x14);
    if (((pbVar3[1] != 2) && (pbVar3[1] != 1)) && (bVar1 = pbVar3[3], bVar1 <= bVar6)) {
      if ((uint)bVar7 != (uint)*pbVar3) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"JASDSPChannel.cpp",0x159,"i == dspch->getNumber()");
        m_Do_printf::OSPanic("JASDSPChannel.cpp",0x159,&DAT_80368133);
      }
      if ((bVar1 != bVar6) || (uVar4 <= *(uint *)(*(int *)(pbVar3 + 0xc) + 0x10c))) {
        uVar4 = *(uint *)(*(int *)(pbVar3 + 0xc) + 0x10c);
        bVar6 = bVar1;
        bVar5 = bVar7;
      }
    }
  }
  return _DSPCH + (uint)bVar5 * 0x14;
}


/* __thiscall TDSPChannel::breakLower(unsigned char) */

undefined4 __thiscall TDSPChannel::breakLower(TDSPChannel *this,uchar param_1)

{
  TDSPChannel *this_00;
  undefined4 uVar1;
  
  this_00 = (TDSPChannel *)getLower(this);
  if (((uint)this & 0xff) < (uint)(byte)this_00[3]) {
    uVar1 = 0;
  }
  else {
    if (this_00[1] == (TDSPChannel)0x1) {
      m_Do_printf::OSReport("----- BreakLowerDSPchannel : DSP Ch is FREE %d \n",*this_00);
      uVar1 = 0;
    }
    else {
      if (*(int *)(this_00 + 0x10) == 0) {
        m_Do_printf::OSReport("----- BreakLowerDSPchannel : Error:Callback is NULL\n");
      }
      else {
        onUpdate(this_00,3);
      }
      forceStop(this_00);
      uVar1 = 1;
    }
  }
  return uVar1;
}


/* __thiscall TDSPChannel::breakLowerActive(unsigned char) */

undefined4 __thiscall TDSPChannel::breakLowerActive(TDSPChannel *this,uchar param_1)

{
  TDSPChannel *this_00;
  undefined4 uVar1;
  
  this_00 = (TDSPChannel *)getLowerActive(this);
  if (((uint)this & 0xff) < (uint)(byte)this_00[3]) {
    uVar1 = 0;
  }
  else {
    if (this_00[1] == (TDSPChannel)0x1) {
      m_Do_printf::OSReport("----- BreakLowerActiveDSPchannel : DSP Ch is FREE %d\n",*this_00);
      uVar1 = 0;
    }
    else {
      if (*(int *)(this_00 + 0x10) != 0) {
        onUpdate(this_00,3);
      }
      forceStop(this_00);
      uVar1 = 1;
    }
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TDSPChannel::updateAll(void) */

void __thiscall TDSPChannel::updateAll(TDSPChannel *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined2 *this_00;
  TDSPChannel *this_01;
  
  if (_gSubFrames < 0xb) {
    iVar1 = os::OSGetTick();
    iVar3 = iVar1 - _old_time;
    iVar2 = _gSubFrames - _snIntCount;
    this = (TDSPChannel *)&history;
    _old_time = iVar1;
    *(int *)(&history + iVar2 * 4) = iVar3;
    if (iVar2 != 0) {
      if ((float)((double)CONCAT44(0x43300000,_history) - JAudio::_612) /
          (float)((double)CONCAT44(0x43300000,iVar3) - JAudio::_612) < _DSP_LIMIT_RATIO) {
        this = (TDSPChannel *)breakLowerActive((TDSPChannel *)0x7e,(uchar)iVar2);
      }
    }
  }
  TDSPQueue::checkQueue((TDSPQueue *)this);
  uVar4 = 0;
  iVar1 = 0;
  do {
    if (((uVar4 & 0xf) == 0) && (uVar4 != 0)) {
      JAudio::DSPReleaseHalt2(uVar4 - 1 >> 4);
    }
    this_01 = (TDSPChannel *)(_DSPCH + iVar1);
    this_00 = *(undefined2 **)(this_01 + 0xc);
    if (this_01[1] != (TDSPChannel)0x1) {
      if (this_00[1] != 0) {
        if (*(int *)(this_01 + 0x10) != 0) {
          onUpdate(this_01,2);
        }
        this_00[1] = 0;
        *this_00 = 0;
        DSPInterface::DSPBuffer::flushChannel((DSPBuffer *)this_00);
        if (this_01[1] == (TDSPChannel)0x1) goto LAB_8028a01c;
      }
      if (((this_00[0x85] == 0) &&
          (*(int *)(this_00 + 0x86) = *(int *)(this_00 + 0x86) + 1,
          *(uint *)(this_00 + 0x86) == (uint)*(ushort *)(this_01 + 4))) &&
         (*(code **)(this_01 + 0x10) != (code *)0x0)) {
        (**(code **)(this_01 + 0x10))(this_01,4);
      }
      if (*(int *)(this_01 + 0x10) != 0) {
        if (*(short *)(this_01 + 6) != 0) {
          *(short *)(this_01 + 6) = *(short *)(this_01 + 6) + -1;
        }
        if ((*(short *)(this_01 + 6) == 0) && (onUpdate(this_01,0), *(short *)(this_01 + 6) == 0)) {
          this_00[1] = 0;
          *this_00 = 0;
          DSPInterface::DSPBuffer::flushChannel((DSPBuffer *)this_00);
        }
      }
    }
LAB_8028a01c:
    uVar4 = uVar4 + 1;
    iVar1 = iVar1 + 0x14;
    if (0x3f < uVar4) {
      JAudio::DSPReleaseHalt2(3);
      return;
    }
  } while( true );
}


/* __thiscall TDSPChannel::onUpdate(unsigned long) */

void __thiscall TDSPChannel::onUpdate(TDSPChannel *this,ulong param_1)

{
  undefined2 uVar1;
  
  if (*(code **)(this + 0x10) != (code *)0x0) {
    uVar1 = (**(code **)(this + 0x10))();
    *(undefined2 *)(this + 6) = uVar1;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TDSPChannel::getNumBreak(void) */

int __thiscall TDSPChannel::getNumBreak(TDSPChannel *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar2 = 0;
  iVar3 = 0x40;
  do {
    if (*(char *)(_DSPCH + iVar2 + 1) == '\x02') {
      iVar1 = iVar1 + 1;
    }
    iVar2 = iVar2 + 0x14;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return iVar1;
}


/* __thiscall TDSPChannel::~TDSPChannel(void) */

void __thiscall TDSPChannel::_TDSPChannel(TDSPChannel *this)

{
  short in_r4;
  
  if ((this != (TDSPChannel *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall TDSPChannel::TDSPChannel(void) */

void __thiscall TDSPChannel::TDSPChannel(TDSPChannel *this)

{
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  return;
}

