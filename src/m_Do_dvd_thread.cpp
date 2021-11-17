#include <m_Do_dvd_thread.h>
#include <os/OSThread.h>
#include <JKernel/JKRThread.h>
#include <JKernel/JKRHeap.h>
#include <m_Do_dvd_thread.h>
#include <dvd/dvdfs.h>
#include <JUtility/JUTAssert.h>
#include <os/OSMessage.h>
#include <os/OSMutex.h>
#include <SComponent/c_list.h>
#include <m_Do_printf.h>
#include <JAudio/JASDvdThread.h>
#include <SComponent/c_node.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <m_Do_ext.h>
#include <JKernel/JKRMemArchive.h>
#include <JKernel/JKRArchivePub.h>
#include <JKernel/JKRDvdRipper.h>
#include <mDoDvdThd_mountArchive_c.h>
#include <mDoDvdThd_param_c.h>
#include <mDoDvdThd_callback_c.h>
#include <mDoDvdThd_toMainRam_c.h>
#include <mDoDvdThd_command_c.h>
#include <mDoDvdThd_mountXArchive_c.h>
#include <mDoDvdThd.h>

undefined1 mDoDvdThd;
undefined1 mDoDvdThd;
struct mDoDvdThd_param_c mDoDvdThd;
undefined1 mDoDvdThd;
undefined1 mDoDvdThd;

/* __thiscall mDoDvdThd::main(void *) */

undefined4 __thiscall mDoDvdThd::main(mDoDvdThd *this,void *param_1)

{
  OSThread *pOVar1;
  JKRThread JStack120;
  
  pOVar1 = (OSThread *)os::OSGetCurrentThread();
  JKRThread::JKRThread(&JStack120,pOVar1,0);
  JKRThread::_JKRThread(&JStack120);
  JKRHeap::becomeCurrentHeap((JKRHeap *)0x0);
  mDoDvdThd_param_c::mainLoop((mDoDvdThd_param_c *)this);
  return 0;
}


namespace mDoDvdThd {

/* __thiscall create(long) */

void create(long param_1)

{
  os::OSCreateThread(&l_thread,main,&l_param,&l_param,0x1000,param_1,1);
  os::OSResumeThread((OSThread *)&l_thread);
  return;
}

}

/* __thiscall mDoDvdThd::suspend(void) */

void __thiscall mDoDvdThd::suspend(mDoDvdThd *this)

{
  os::OSSuspendThread(&l_thread);
  return;
}


namespace m_Do_dvd_thread {

/* __stdcall my_DVDConvertPathToEntrynum(char const *) */

int my_DVDConvertPathToEntrynum(char *pFilePath)

{
  int entryNum;
  ulong uVar1;
  
  entryNum = dvd::DVDConvertPathToEntrynum(pFilePath);
  if (entryNum < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::setWarningMessage_f
              (uVar1,"m_Do_dvd_thread.cpp",0x240,"can\'t open:[%s]\n",(___)pFilePath);
  }
  return entryNum;
}

}

/* __thiscall mDoDvdThd_command_c::~mDoDvdThd_command_c(void) */

void __thiscall mDoDvdThd_command_c::_mDoDvdThd_command_c(mDoDvdThd_command_c *this)

{
  short in_r4;
  
  if ((this != (mDoDvdThd_command_c *)0x0) && (this->vtbl = (mDoDvdThd__vt *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall mDoDvdThd_param_c::mDoDvdThd_param_c(void) */

void __thiscall mDoDvdThd_param_c::mDoDvdThd_param_c(mDoDvdThd_param_c *this)

{
  os::OSInitMessageQueue((OSMessageQueue *)this,(OSMessage *)&this->field_0x20,1);
  os::OSInitMutex(&this->mMutex);
  SComponent::cLs_Create(&this->mChildList);
  return;
}


/* __thiscall mDoDvdThd_param_c::kick(void) */

void __thiscall mDoDvdThd_param_c::kick(mDoDvdThd_param_c *this)

{
  os::OSSendMessage(this,0,0);
  return;
}


/* __thiscall mDoDvdThd_param_c::waitForKick(void) */

void __thiscall mDoDvdThd_param_c::waitForKick(mDoDvdThd_param_c *this)

{
  os::OSReceiveMessage(this,0,1);
  return;
}


/* __thiscall mDoDvdThd_param_c::getFirstCommand(void) */

node_class * __thiscall mDoDvdThd_param_c::getFirstCommand(mDoDvdThd_param_c *this)

{
  return (this->mChildList).mpHead;
}


/* __thiscall mDoDvdThd_param_c::addition(mDoDvdThd_command_c *) */

void __thiscall mDoDvdThd_param_c::addition(mDoDvdThd_param_c *this,mDoDvdThd_command_c *param_1)

{
  os::OSLockMutex(&this->mMutex);
  SComponent::cLs_Addition(&this->mChildList,&param_1->parent);
  os::OSUnlockMutex(&this->mMutex);
  kick(this);
  return;
}


/* __thiscall mDoDvdThd_param_c::cut(mDoDvdThd_command_c *) */

void __thiscall mDoDvdThd_param_c::cut(mDoDvdThd_param_c *this,mDoDvdThd_command_c *param_1)

{
  os::OSLockMutex(&this->mMutex);
  SComponent::cLs_SingleCut(&param_1->parent);
  os::OSUnlockMutex(&this->mMutex);
  kick(this);
  return;
}


namespace m_Do_dvd_thread {

/* __stdcall cb(void *) */

undefined4 cb(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)(*param_1 + 0x10) + 0xc))();
  if (iVar1 != 1) {
    m_Do_printf::OSReport_Error
              ("mDoDvdThd_param_c::mainLoop() コマンドの実行が失敗しました。\n");
  }
  return 0;
}

}

/* __thiscall mDoDvdThd_param_c::mainLoop(void) */

void __thiscall mDoDvdThd_param_c::mainLoop(mDoDvdThd_param_c *this)

{
  int iVar1;
  ulong in_r6;
  mDoDvdThd_command_c *local_18 [4];
  
  while (iVar1 = waitForKick(this), iVar1 != 0) {
    while( true ) {
      local_18[0] = (mDoDvdThd_command_c *)getFirstCommand(this);
      if (local_18[0] == (mDoDvdThd_command_c *)0x0) break;
      cut(this,local_18[0]);
      if (mDoDvdThd::SyncWidthSound == '\0') {
        m_Do_dvd_thread::cb(local_18);
      }
      else {
        JASystem::Dvd::sendCmdMsg
                  ((Dvd *)m_Do_dvd_thread::cb,(FuncDef568 *)local_18,&DAT_00000004,in_r6);
      }
    }
  }
  return;
}


/* __thiscall mDoDvdThd_command_c::mDoDvdThd_command_c(void) */

void __thiscall mDoDvdThd_command_c::mDoDvdThd_command_c(mDoDvdThd_command_c *this)

{
  this->vtbl = (mDoDvdThd__vt *)&__vt;
  this->mStatus = 0;
  SComponent::cNd_ForcedClear(&this->parent);
  return;
}


/* __thiscall mDoDvdThd_callback_c::~mDoDvdThd_callback_c(void) */

void __thiscall mDoDvdThd_callback_c::_mDoDvdThd_callback_c(mDoDvdThd_callback_c *this)

{
  short in_r4;
  
  if (this != (mDoDvdThd_callback_c *)0x0) {
    *(undefined1 **)(this + 0x10) = &__vt;
    mDoDvdThd_command_c::_mDoDvdThd_command_c((mDoDvdThd_command_c *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall mDoDvdThd_callback_c::mDoDvdThd_callback_c(void * *(void *),
                                                         void *) */

void __thiscall
mDoDvdThd_callback_c::mDoDvdThd_callback_c
          (mDoDvdThd_callback_c *this,FuncDef500 *param_1,void *param_2)

{
  mDoDvdThd_command_c::mDoDvdThd_command_c((mDoDvdThd_command_c *)this);
  *(undefined1 **)(this + 0x10) = &__vt;
  *(FuncDef500 **)(this + 0x14) = param_1;
  *(void **)(this + 0x18) = param_2;
  *(undefined4 *)(this + 0x1c) = 0;
  return;
}


namespace mDoDvdThd_callback_c {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall create(void * *(void *),
                                           void *) */

mDoDvdThd_command_c * create(FuncDef501 *param_1,void *param_2)

{
  JKRHeap *heap;
  mDoDvdThd_command_c *this;
  
  heap = m_Do_ext::mDoExt_getCommandHeap();
  this = (mDoDvdThd_command_c *)JKernel::operator_new(0x20,heap,0xfffffffc);
  if (this != (mDoDvdThd_command_c *)0x0) {
    mDoDvdThd_callback_c((mDoDvdThd_callback_c *)this,(FuncDef500 *)param_1,param_2);
  }
  if (this != (mDoDvdThd_command_c *)0x0) {
    mDoDvdThd_param_c::addition(&mDoDvdThd::l_param,this);
  }
  return this;
}

}

/* __thiscall mDoDvdThd_callback_c::execute(void) */

bool __thiscall mDoDvdThd_callback_c::execute(mDoDvdThd_callback_c *this)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(this + 0x14))(*(undefined4 *)(this + 0x18));
  *(undefined4 *)(this + 0x1c) = uVar1;
  this[0xc] = (mDoDvdThd_callback_c)0x1;
  return *(int *)(this + 0x1c) != 0;
}


/* __thiscall mDoDvdThd_mountArchive_c::~mDoDvdThd_mountArchive_c(void) */

void __thiscall mDoDvdThd_mountArchive_c::_mDoDvdThd_mountArchive_c(mDoDvdThd_mountArchive_c *this)

{
  short in_r4;
  
  if (this != (mDoDvdThd_mountArchive_c *)0x0) {
    (this->parent).vtbl = (mDoDvdThd__vt *)&__vt;
    mDoDvdThd_command_c::_mDoDvdThd_command_c(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall mDoDvdThd_mountArchive_c::mDoDvdThd_mountArchive_c(unsigned char) */

void __thiscall
mDoDvdThd_mountArchive_c::mDoDvdThd_mountArchive_c(mDoDvdThd_mountArchive_c *this,uchar param_1)

{
  mDoDvdThd_command_c::mDoDvdThd_command_c(&this->parent);
  (this->parent).vtbl = (mDoDvdThd__vt *)&__vt;
  this->mDirection = param_1;
  this->mEntryNum = -1;
  this->mpResult = (JKRMemArchive *)0x0;
  this->mpHeap = (JKRHeap *)0x0;
  if (param_1 == '\0') {
    this->mDirection = mDoDvdThd::sDefaultDirection;
  }
  return;
}


namespace mDoDvdThd_mountArchive_c {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall create(char const *,
                                               unsigned char,
                                               JKRHeap *) */

mDoDvdThd_command_c * create(char *param_1,uchar param_2,JKRHeap *param_3)

{
  JKRHeap *heap;
  int iVar1;
  mDoDvdThd_mountArchive_c *pCmd;
  
  heap = m_Do_ext::mDoExt_getCommandHeap();
  pCmd = (mDoDvdThd_mountArchive_c *)JKernel::operator_new(0x24,heap,0xfffffffc);
  if (pCmd != (mDoDvdThd_mountArchive_c *)0x0) {
    mDoDvdThd_mountArchive_c(pCmd,param_2);
  }
  if (pCmd != (mDoDvdThd_mountArchive_c *)0x0) {
    iVar1 = m_Do_dvd_thread::my_DVDConvertPathToEntrynum(param_1);
    pCmd->mEntryNum = iVar1;
    if (pCmd->mEntryNum == -1) {
      (pCmd->parent).mStatus = 1;
      if (pCmd != (mDoDvdThd_mountArchive_c *)0x0) {
        (*(code *)((pCmd->parent).vtbl)->_mDoDvdThd_toMainRam_c)(pCmd,1);
      }
      pCmd = (mDoDvdThd_mountArchive_c *)0x0;
    }
    else {
      pCmd->mpHeap = param_3;
      mDoDvdThd_param_c::addition(&mDoDvdThd::l_param,&pCmd->parent);
    }
  }
  return &pCmd->parent;
}

}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall mDoDvdThd_mountArchive_c::execute(void) */

bool __thiscall mDoDvdThd_mountArchive_c::execute(mDoDvdThd_mountArchive_c *this)

{
  JKRHeap *heap;
  JKRMemArchive *this_00;
  JKRHeap *pJVar1;
  
  heap = this->mpHeap;
  if (heap == (JKRHeap *)0x0) {
    heap = m_Do_ext::mDoExt_getArchiveHeap();
  }
  while( true ) {
    if (this->mDirection == 0) {
      this_00 = (JKRMemArchive *)JKernel::operator_new(0x70,heap,0);
      if (this_00 != (JKRMemArchive *)0x0) {
        JKRMemArchive::JKRMemArchive(this_00,this->mEntryNum,1);
      }
    }
    else {
      this_00 = (JKRMemArchive *)JKernel::operator_new(0x70,heap,0xfffffffc);
      if (this_00 != (JKRMemArchive *)0x0) {
        JKRMemArchive::JKRMemArchive(this_00,this->mEntryNum,2);
      }
    }
    if ((this_00 != (JKRMemArchive *)0x0) && ((this_00->parent).parent.mbIsMounted != 0)) break;
    m_Do_printf::OSReport_Error("mDoDvdThd_mountArchive_c::execute マウント失敗\n");
    if ((this_00 != (JKRMemArchive *)0x0) && (this_00 != (JKRMemArchive *)0x0)) {
      (*(code *)((this_00->parent).parent.parent.vtbl)->_)(this_00,1);
    }
    pJVar1 = m_Do_ext::mDoExt_getZeldaHeap();
    if (heap == pJVar1) {
      m_Do_printf::OSReport_FatalError
                ("mDoDvdThd_mountArchive_c::execute ヒープが致命的に足りません！\n");
LAB_80018740:
      (this->parent).mStatus = 1;
      return this->mpResult != (JKRMemArchive *)0x0;
    }
    m_Do_printf::OSReport_Error
              ("mDoDvdThd_mountArchive_c::execute システムヒープで再チャレンジ！\n");
    heap = m_Do_ext::mDoExt_getZeldaHeap();
  }
  this->mpResult = this_00;
  goto LAB_80018740;
}


/* __thiscall mDoDvdThd_mountXArchive_c::~mDoDvdThd_mountXArchive_c(void) */

void __thiscall
mDoDvdThd_mountXArchive_c::_mDoDvdThd_mountXArchive_c(mDoDvdThd_mountXArchive_c *this)

{
  short in_r4;
  
  if (this != (mDoDvdThd_mountXArchive_c *)0x0) {
    (this->parent).vtbl = (mDoDvdThd__vt *)&__vt;
    mDoDvdThd_command_c::_mDoDvdThd_command_c(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall mDoDvdThd_mountXArchive_c::mDoDvdThd_mountXArchive_c(unsigned char,
                                                                   JKRArchive::EMountMode) */

void __thiscall
mDoDvdThd_mountXArchive_c::mDoDvdThd_mountXArchive_c
          (mDoDvdThd_mountXArchive_c *this,uchar param_1,EMountMode param_2)

{
  undefined3 in_register_00000014;
  
  mDoDvdThd_command_c::mDoDvdThd_command_c(&this->parent);
  (this->parent).vtbl = (mDoDvdThd__vt *)&__vt;
  this->mDirection = param_1;
  this->field_0x18 = &DAT_ffffffff;
  this->mpArchive = (JKRArchive *)0x0;
  this->mMountMode = CONCAT31(in_register_00000014,param_2);
  if (param_1 == '\0') {
    this->mDirection = mDoDvdThd::sDefaultDirection;
  }
  return;
}


namespace mDoDvdThd_mountXArchive_c {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall create(char const *,
                                                unsigned char,
                                                JKRArchive::EMountMode) */

mDoDvdThd_mountXArchive_c *
create(char *param_1,byte param_2,EMountMode param_3)

{
  JKRHeap *heap;
  mDoDvdThd_mountXArchive_c *this;
  undefined *puVar1;
  
  heap = m_Do_ext::mDoExt_getCommandHeap();
  this = (mDoDvdThd_mountXArchive_c *)JKernel::operator_new(0x24,heap,0xfffffffc);
  if (this != (mDoDvdThd_mountXArchive_c *)0x0) {
    mDoDvdThd_mountXArchive_c(this,param_2,param_3);
  }
  if (this != (mDoDvdThd_mountXArchive_c *)0x0) {
    puVar1 = (undefined *)m_Do_dvd_thread::my_DVDConvertPathToEntrynum(param_1);
    this->field_0x18 = puVar1;
    if (this->field_0x18 == &DAT_ffffffff) {
      (this->parent).mStatus = 1;
      if (this != (mDoDvdThd_mountXArchive_c *)0x0) {
        (*(code *)((this->parent).vtbl)->_mDoDvdThd_toMainRam_c)(this,1);
      }
      this = (mDoDvdThd_mountXArchive_c *)0x0;
    }
    else {
      mDoDvdThd_param_c::addition(&mDoDvdThd::l_param,&this->parent);
    }
  }
  return this;
}

}

/* __thiscall mDoDvdThd_mountXArchive_c::execute(void) */

bool __thiscall mDoDvdThd_mountXArchive_c::execute(mDoDvdThd_mountXArchive_c *this)

{
  JKRHeap *pJVar1;
  JKRArchive *pJVar2;
  EMountDirection EVar3;
  
  EVar3 = 2;
  if (this->mDirection == 0) {
    EVar3 = 1;
  }
  pJVar1 = m_Do_ext::mDoExt_getArchiveHeap();
  pJVar2 = (JKRArchive *)
           JKRArchive::mount((long)this->field_0x18,(EMountMode)this->mMountMode,pJVar1,EVar3);
  this->mpArchive = pJVar2;
  pJVar2 = this->mpArchive;
  (this->parent).mStatus = 1;
  return pJVar2 != (JKRArchive *)0x0;
}


/* __thiscall mDoDvdThd_toMainRam_c::mDoDvdThd_toMainRam_c(unsigned char) */

void __thiscall
mDoDvdThd_toMainRam_c::mDoDvdThd_toMainRam_c(mDoDvdThd_toMainRam_c *this,byte direction)

{
  mDoDvdThd_command_c::mDoDvdThd_command_c(&this->parent);
  (this->parent).vtbl = &__vt;
  this->mDirection = direction;
  if (direction == 0) {
    this->mDirection = mDoDvdThd::sDefaultDirection;
  }
  return;
}


namespace mDoDvdThd_toMainRam_c {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall create(char const *,
                                            unsigned char,
                                            JKRHeap *) */

mDoDvdThd_toMainRam_c * create(char *pFilePath,byte direction,JKRHeap *pHeap)

{
  JKRHeap *heap;
  int entryNum;
  mDoDvdThd_toMainRam_c *dvdThd;
  
  heap = m_Do_ext::mDoExt_getCommandHeap();
  dvdThd = (mDoDvdThd_toMainRam_c *)JKernel::operator_new(0x28,heap,0xfffffffc);
  if (dvdThd != (mDoDvdThd_toMainRam_c *)0x0) {
    mDoDvdThd_toMainRam_c(dvdThd,direction);
  }
  if (dvdThd != (mDoDvdThd_toMainRam_c *)0x0) {
    entryNum = m_Do_dvd_thread::my_DVDConvertPathToEntrynum(pFilePath);
    dvdThd->mDvdEntryNum = entryNum;
    if (dvdThd->mDvdEntryNum == -1) {
      (dvdThd->parent).mStatus = 1;
      if (dvdThd != (mDoDvdThd_toMainRam_c *)0x0) {
        (*(code *)((dvdThd->parent).vtbl)->_mDoDvdThd_toMainRam_c)(dvdThd,1);
      }
      dvdThd = (mDoDvdThd_toMainRam_c *)0x0;
    }
    else {
      dvdThd->mpHeap = pHeap;
      mDoDvdThd_param_c::addition(&mDoDvdThd::l_param,&dvdThd->parent);
    }
  }
  return dvdThd;
}

}

/* __thiscall mDoDvdThd_toMainRam_c::~mDoDvdThd_toMainRam_c(void) */

void __thiscall mDoDvdThd_toMainRam_c::_mDoDvdThd_toMainRam_c(mDoDvdThd_toMainRam_c *this)

{
  short in_r4;
  
  if (this != (mDoDvdThd_toMainRam_c *)0x0) {
    (this->parent).vtbl = &__vt;
    mDoDvdThd_command_c::_mDoDvdThd_command_c(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall mDoDvdThd_toMainRam_c::execute(void) */

bool __thiscall mDoDvdThd_toMainRam_c::execute(mDoDvdThd_toMainRam_c *this)

{
  JKRArchive__Header *pJVar1;
  int heapSize;
  JKRHeap *heap;
  EAllocDirection EVar2;
  
  heap = this->mpHeap;
  if (heap == (JKRHeap *)0x0) {
    heap = m_Do_ext::mDoExt_getArchiveHeap();
  }
  EVar2 = 2;
  if (this->mDirection == 0) {
    EVar2 = 1;
  }
  pJVar1 = JKRDvdRipper::loadToMainRAM(this->mDvdEntryNum,(uchar *)0x0,1,0,heap,EVar2,0,(int *)0x0);
  this->mpArchiveHeader = pJVar1;
  if (this->mpArchiveHeader != (JKRArchive__Header *)0x0) {
    heapSize = JKRHeap::getSize(heap,this->mpArchiveHeader);
    this->mHeapSize = heapSize;
  }
  (this->parent).mStatus = 1;
  return this->mpArchiveHeader != (JKRArchive__Header *)0x0;
}


namespace m_Do_dvd_thread {

void __sinit_m_Do_dvd_thread_cpp(void)

{
  ::mDoDvdThd_param_c::mDoDvdThd_param_c(&::mDoDvdThd::l_param);
  return;
}

