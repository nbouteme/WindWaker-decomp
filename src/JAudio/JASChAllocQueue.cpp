#include <JAudio/JASChAllocQueue.h>
#include <JAudio/JASDSPChannel.h>
#include <JSupport/JSUList.h>
#include <JAudio/JASChannel.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JAudio/JASChannelMgr.h>
#include <JAudio/JASChAllocQueue.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JKernel/JKRHeap.h>
#include <JSUList<JASystem::TChannel>.h>
#include <JASystem/TDSPQueue.h>


namespace JASystem {
undefined1 sDspQueueList;

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TDSPQueue::deQueue(void) */

void __thiscall TDSPQueue::deQueue(TDSPQueue *this)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  TChannel **ppTVar4;
  uchar extraout_r4;
  ulong in_r5;
  TChannel *this_00;
  TChannel **ppTVar5;
  
  iVar1 = TDSPChannel::getNumBreak((TDSPChannel *)this);
  ppTVar4 = _sDspQueueList;
  while (ppTVar4 != (TChannel **)0x0) {
    ppTVar5 = (TChannel **)ppTVar4[3];
    this_00 = *ppTVar4;
    iVar2 = TDSPChannel::alloc((TDSPChannel *)0x0,(ulong)this_00,in_r5);
    ppTVar4 = ppTVar5;
    if (iVar2 == 0) {
      if (iVar1 == 0) {
        iVar2 = TDSPChannel::breakLower
                          ((TDSPChannel *)(*(uint *)(this_00 + 0x48) & 0xff),extraout_r4);
        if (iVar2 == 0) {
          (**(code **)(this_00 + 0x28))(this_00,6);
          JSUPtrList::remove((JSUPtrList *)&sDspQueueList,(JSUPtrLink *)(this_00 + 0xd8));
        }
      }
      else {
        iVar1 = iVar1 + -1;
      }
    }
    else {
      *(int *)(this_00 + 0x20) = iVar2;
      iVar2 = TChannel::playLogicalChannel(this_00);
      if (iVar2 == 0) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar3,"JASChAllocQueue.cpp",0x45,"status");
        m_Do_printf::OSPanic("JASChAllocQueue.cpp",0x45,&DAT_803684a3);
      }
      iVar2 = TChannelMgr::cutList(*(TChannelMgr **)(this_00 + 4),this_00);
      if (iVar2 < 0) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar3,"JASChAllocQueue.cpp",0x48,"sst >= 0");
        m_Do_printf::OSPanic("JASChAllocQueue.cpp",0x48,&DAT_803684a3);
      }
      in_r5 = 1;
      TChannelMgr::addListTail(*(TChannelMgr **)(this_00 + 4),this_00,1);
      JSUPtrList::remove((JSUPtrList *)&sDspQueueList,(JSUPtrLink *)(this_00 + 0xd8));
    }
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TDSPQueue::enQueue(TChannel *) */

void __thiscall TDSPQueue::enQueue(TDSPQueue *this,TChannel *param_1)

{
  JSUPtrLink *pJVar1;
  
  pJVar1 = _sDspQueueList;
  while ((pJVar1 != (JSUPtrLink *)0x0 &&
         ((*(uint *)(this + 0x48) & 0xff) <= (*(uint *)(pJVar1->mpData + 0x48) & 0xff)))) {
    pJVar1 = pJVar1->mpNext;
  }
  JSUPtrList::insert((JSUPtrList *)&sDspQueueList,pJVar1,(JSUPtrLink *)(this + 0xd8));
  return;
}


/* __thiscall TDSPQueue::deleteQueue(TChannel *) */

uint __thiscall TDSPQueue::deleteQueue(TDSPQueue *this,TChannel *param_1)

{
  uint uVar1;
  
  uVar1 = JSUPtrList::remove((JSUPtrList *)&sDspQueueList,(JSUPtrLink *)(this + 0xd8));
  return uVar1 & 0xff;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TDSPQueue::checkQueue(void) */

void __thiscall TDSPQueue::checkQueue(TDSPQueue *this)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  deQueue(this);
  piVar1 = _sDspQueueList;
  while (piVar1 != (int *)0x0) {
    piVar3 = (int *)piVar1[3];
    iVar2 = *piVar1;
    if (0 < *(int *)(iVar2 + 0x30)) {
      *(int *)(iVar2 + 0x30) = *(int *)(iVar2 + 0x30) + -1;
    }
    piVar1 = piVar3;
    if (*(int *)(iVar2 + 0x30) == 0) {
      (**(code **)(iVar2 + 0x28))(iVar2,6);
      JSUPtrList::remove((JSUPtrList *)&sDspQueueList,(JSUPtrLink *)(iVar2 + 0xd8));
    }
  }
  return;
}

}

namespace JAudio {

void __sinit_JASChAllocQueue_cpp(void)

{
  JSUPtrList::initiate((JSUPtrList *)&::JASystem::sDspQueueList);
  Runtime.PPCEABI.H::__register_global_object
            (&::JASystem::sDspQueueList,::JSUList<JASystem::TChannel>::_JSUList,&_364);
  return;
}

}

/* __thiscall JSUList<JASystem::TChannel>::~JSUList(void) */

JSUList_JASystem__TChannel_ * __thiscall
JSUList<JASystem::TChannel>::_JSUList(JSUList_JASystem__TChannel_ *this)

{
  short in_r4;
  
  if ((this != (JSUList_JASystem__TChannel_ *)0x0) &&
     (JSUPtrList::_JSUPtrList((JSUPtrList *)this), 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return this;
}

