#include <JKernel/JKRAramPiece.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRAramPiece.h>
#include <os/OSMutex.h>
#include <m_Do_printf.h>
#include <os/OSMessage.h>
#include <JSupport/JSUList.h>
#include <os/OSCache.h>
#include <ar/arq.h>
#include <JKernel/JKRDecomp.h>
#include <JKernel/JKRAram.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JKRAramPiece.h>
#include <Demangler/JKRAMCommand.h>

undefined1 JKRAramPiece;
undefined1 JKRAramPiece;

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall JKRAramPiece::prepareCommand(int,
                                           unsigned long,
                                           unsigned long,
                                           unsigned long,
                                           JKRAramBlock *,
                                           void *(unsigned long)) */

JKRAMCommand * __thiscall
JKRAramPiece::prepareCommand
          (JKRAramPiece *this,int param_1,ulong param_2,ulong param_3,ulong param_4,
          JKRAramBlock *param_5,FuncDef585 *param_6)

{
  JKRAMCommand *this_00;
  
  this_00 = (JKRAMCommand *)JKernel::operator_new(0x98,JKRHeap::sSystemHeap,0xfffffffc);
  if (this_00 != (JKRAMCommand *)0x0) {
    JKRAMCommand::JKRAMCommand(this_00);
  }
  *(JKRAramPiece **)(this_00 + 0x40) = this;
  *(int *)(this_00 + 0x48) = param_1;
  *(ulong *)(this_00 + 0x4c) = param_2;
  *(ulong *)(this_00 + 0x50) = param_4;
  *(ulong *)(this_00 + 0x44) = param_3;
  *(JKRAramBlock **)(this_00 + 0x58) = param_5;
  return this_00;
}


/* __thiscall JKRAramPiece::sendCommand(JKRAMCommand *) */

void __thiscall JKRAramPiece::sendCommand(JKRAramPiece *this,JKRAMCommand *param_1)

{
  startDMA(this,param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall JKRAramPiece::orderAsync(int,
                                       unsigned long,
                                       unsigned long,
                                       unsigned long,
                                       JKRAramBlock *,
                                       void *(unsigned long)) */

int __thiscall
JKRAramPiece::orderAsync
          (JKRAramPiece *this,int param_1,ulong param_2,ulong param_3,ulong param_4,
          JKRAramBlock *param_5,FuncDef586 *param_6)

{
  undefined4 *puVar1;
  int iVar2;
  
  os::OSLockMutex((OSMutex *)&mMutex);
  if (((param_1 & 0x1fU) != 0) || ((param_2 & 0x1f) != 0)) {
    m_Do_printf::OSReport("direction = %x\n",this);
    m_Do_printf::OSReport("source = %x\n",param_1);
    m_Do_printf::OSReport("destination = %x\n",param_2);
    m_Do_printf::OSReport("length = %x\n",param_3);
    m_Do_printf::OSPanic("JKRAramPiece.cpp",0x66,"Abort.");
  }
  puVar1 = (undefined4 *)JKernel::operator_new(8,JKRHeap::sSystemHeap,0xfffffffc);
  iVar2 = prepareCommand(this,param_1,param_2,param_3,param_4,param_5,(FuncDef585 *)param_6);
  *puVar1 = 1;
  puVar1[1] = iVar2;
  os::OSSendMessage(&JKRAram::sMessageQueue,puVar1,1);
  if (*(int *)(iVar2 + 0x58) != 0) {
    JSUPtrList::append((JSUPtrList *)&sAramPieceCommandList,(JSUPtrLink *)(iVar2 + 0x20));
  }
  os::OSUnlockMutex(&mMutex);
  return iVar2;
}


/* __thiscall JKRAramPiece::sync(JKRAMCommand *,
                                 int) */

void __thiscall JKRAramPiece::sync(JKRAramPiece *this)

{
  int iVar1;
  int in_r4;
  undefined auStack24 [16];
  
  os::OSLockMutex((OSMutex *)&mMutex);
  if (in_r4 == 0) {
    os::OSReceiveMessage(this + 0x68,auStack24,1);
    JSUPtrList::remove((JSUPtrList *)&sAramPieceCommandList,(JSUPtrLink *)(this + 0x20));
    os::OSUnlockMutex(&mMutex);
  }
  else {
    iVar1 = os::OSReceiveMessage(this + 0x68,auStack24,0);
    if (iVar1 == 0) {
      os::OSUnlockMutex(&mMutex);
    }
    else {
      JSUPtrList::remove((JSUPtrList *)&sAramPieceCommandList,(JSUPtrLink *)(this + 0x20));
      os::OSUnlockMutex(&mMutex);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JKRAramPiece::orderSync(int,
                                      unsigned long,
                                      unsigned long,
                                      unsigned long,
                                      JKRAramBlock *) */

JKRAramPiece * __thiscall
JKRAramPiece::orderSync
          (JKRAramPiece *this,int param_1,ulong param_2,ulong param_3,ulong param_4,
          JKRAramBlock *param_5)

{
  JKRAramPiece *this_00;
  JKRAramPiece *pJVar1;
  FuncDef586 *in_r9;
  
  os::OSLockMutex((OSMutex *)&mMutex);
  this_00 = (JKRAramPiece *)
            orderAsync(this,param_1,param_2,param_3,param_4,(JKRAramBlock *)0x0,in_r9);
  pJVar1 = this_00;
  sync(this_00);
  JKRAMCommand::_JKRAMCommand((JKRAMCommand *)this_00);
  os::OSUnlockMutex(&mMutex);
  return pJVar1;
}


/* __thiscall JKRAramPiece::startDMA(JKRAMCommand *) */

void __thiscall JKRAramPiece::startDMA(JKRAramPiece *this,JKRAMCommand *param_1)

{
  if (*(int *)(this + 0x40) == 1) {
    os::DCInvalidateRange(*(undefined4 *)(this + 0x4c),*(undefined4 *)(this + 0x44));
  }
  else {
    os::DCStoreRange(*(undefined4 *)(this + 0x48),*(undefined4 *)(this + 0x44));
  }
  ar::ARQPostRequest(this,0,*(undefined4 *)(this + 0x40),0,*(undefined4 *)(this + 0x48),
                     *(undefined4 *)(this + 0x4c),*(undefined4 *)(this + 0x44),doneDMA);
  return;
}


/* __thiscall JKRAramPiece::doneDMA(unsigned long) */

void __thiscall JKRAramPiece::doneDMA(JKRAramPiece *this,ulong param_1)

{
  JKRDecompCommand *extraout_r4;
  
  if (*(int *)(this + 0x40) == 1) {
    os::DCInvalidateRange(*(undefined4 *)(this + 0x4c),*(undefined4 *)(this + 0x44));
    param_1 = (ulong)extraout_r4;
  }
  if (*(int *)(this + 0x60) == 0) {
    if (*(code **)(this + 0x58) == (code *)0x0) {
      if (*(int *)(this + 0x5c) == 0) {
        os::OSSendMessage(this + 0x68,this,0);
      }
      else {
        os::OSSendMessage(*(int *)(this + 0x5c),this,0);
      }
    }
    else {
      (**(code **)(this + 0x58))(this);
    }
  }
  else {
    if (*(int *)(this + 0x60) == 2) {
      JKRDecomp::sendCommand(*(JKRDecomp **)(this + 100),(JKRDecompCommand *)param_1);
    }
  }
  return;
}


/* __thiscall JKRAMCommand::JKRAMCommand(void) */

void __thiscall JKRAMCommand::JKRAMCommand(JKRAMCommand *this)

{
  JSUPtrLink::JSUPtrLink((JSUPtrLink *)(this + 0x20),this);
  JSUPtrLink::JSUPtrLink((JSUPtrLink *)(this + 0x30),this);
  os::OSInitMessageQueue((OSMessageQueue *)(this + 0x68),(OSMessage *)(this + 0x88),1);
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined4 *)(this + 0x90) = 0;
  *(undefined4 *)(this + 0x94) = 0;
  return;
}


/* __thiscall JKRAMCommand::~JKRAMCommand(void) */

void __thiscall JKRAMCommand::_JKRAMCommand(JKRAMCommand *this)

{
  short in_r4;
  
  if (this != (JKRAMCommand *)0x0) {
    if (*(JKRHeap **)(this + 0x8c) != (JKRHeap *)0x0) {
      JKernel::operator_delete(*(JKRHeap **)(this + 0x8c));
    }
    if (*(JKRHeap **)(this + 0x90) != (JKRHeap *)0x0) {
      JKernel::operator_delete(*(JKRHeap **)(this + 0x90));
    }
    if (*(void **)(this + 0x94) != (void *)0x0) {
      JKRHeap::free(*(void **)(this + 0x94),(JKRHeap *)0x0);
    }
    if (this != (JKRAMCommand *)0xffffffd0) {
      JSUPtrLink::_JSUPtrLink((JSUPtrLink *)(this + 0x30));
    }
    if (this != (JKRAMCommand *)0xffffffe0) {
      JSUPtrLink::_JSUPtrLink((JSUPtrLink *)(this + 0x20));
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace JKernel {

void __sinit_JKRAramPiece_cpp(void)

{
  JSUPtrList::initiate((JSUPtrList *)&::JKRAramPiece::sAramPieceCommandList);
  Runtime.PPCEABI.H::__register_global_object
            (&::JKRAramPiece::sAramPieceCommandList,::JSUList<JKRAMCommand>::_JSUList,&_287);
  return;
}

