#include <m_Do_MemCard.h>
#include <card/CARDBios.h>
#include <os/OSMutex.h>
#include <os/OSThread.h>
#include <m_Do_MemCard.h>
#include <card/CARDMount.h>
#include <card/CARDOpen.h>
#include <m_Do_MemCardRWmng.h>
#include <card/CARDCreate.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <card/CARDFormat.h>
#include <card/CARDCheck.h>
#include <JKernel/JKRThread.h>
#include <JKernel/JKRHeap.h>
#include <mDoMemCd_Ctrl_c.h>


namespace m_Do_MemCard {
undefined MemCardStack;
undefined MemCardThread;
byte MemCardWorkArea0[8192];
struct mDoMemCd_Ctrl_c g_mDoMemCd_control;
}

/* __thiscall mDoMemCd_Ctrl_c::mDoMemCd_Ctrl_c(void) */

void __thiscall mDoMemCd_Ctrl_c::mDoMemCd_Ctrl_c(mDoMemCd_Ctrl_c *this)

{
  return;
}


/* __thiscall mDoMemCd_Ctrl_c::ThdInit(void) */

void __thiscall mDoMemCd_Ctrl_c::ThdInit(mDoMemCd_Ctrl_c *this)

{
  int iVar1;
  
  card::CARDInit();
  this->field_0x1650 = 0;
  this->field_0x1654 = 0;
  *(undefined *)((int)&this->mCardSlot + 1) = 0;
  *(undefined *)((int)&this->mCardSlot + 2) = 2;
  this->mStatus = STANDBY;
  this->mNextAction = STANDBY;
  *(undefined *)&this->mCardSlot = 0;
  os::OSInitMutex(&this->mOSMutex);
  os::OSInitCond(this + 1);
  os::OSGetCurrentThread();
  iVar1 = os::OSGetThreadPriority();
  os::OSCreateThread(&m_Do_MemCard::MemCardThread,m_Do_MemCard::mDoMemCd_main,0,
                     &m_Do_MemCard::MemCardThread,0x1000,iVar1 + 1,1);
  os::OSResumeThread((OSThread *)&m_Do_MemCard::MemCardThread);
  return;
}


/* __thiscall mDoMemCd_Ctrl_c::main(void) */

void __thiscall mDoMemCd_Ctrl_c::main(mDoMemCd_Ctrl_c *this)

{
  mDoMemCd_Ctrl_status mVar1;
  char *in_r6;
  ulong in_r7;
  void *in_r8;
  
  do {
    os::OSLockMutex(&this->mOSMutex);
    while (mVar1 = this->mNextAction, mVar1 == STANDBY) {
      os::OSWaitCond(this + 1,&this->mOSMutex);
    }
    if (mVar1 == FORMAT) {
      format(this);
    }
    else {
      if ((int)mVar1 < 3) {
        if (mVar1 == RESTORE) {
          restore(this);
        }
        else {
          if (0 < (int)mVar1) {
            store(this);
          }
        }
      }
      else {
        if (mVar1 == DETACH) {
          detach(this);
        }
        else {
          if ((int)mVar1 < 5) {
            attach(this,in_r6,in_r7,in_r8);
          }
        }
      }
    }
    this->mNextAction = STANDBY;
    os::OSUnlockMutex(&this->mOSMutex);
  } while( true );
}


/* __thiscall mDoMemCd_Ctrl_c::update(void) */

void __thiscall mDoMemCd_Ctrl_c::update(mDoMemCd_Ctrl_c *this)

{
  mDoMemCd_Ctrl_status mVar1;
  card_errors cVar2;
  
  if (*mDoRst::mResetData == 0) {
    mVar1 = getStatus(this,0);
    if (mVar1 != 0xe) {
      cVar2 = card::CARDProbe(0);
      if ((cVar2 == CARD_ERROR_READY) || (mVar1 = getStatus(this,0), mVar1 != STANDBY)) {
        cVar2 = card::CARDProbe(0);
        if ((cVar2 == CARD_ERROR_READY) && (mVar1 = getStatus(this,0), mVar1 != STANDBY)) {
          os::OSLockMutex(&this->mOSMutex);
          *(undefined *)((int)&this->mCardSlot + 2) = 1;
          this->mNextAction = DETACH;
          os::OSUnlockMutex(&this->mOSMutex);
          os::OSSignalCond(this + 1);
        }
      }
      else {
        os::OSLockMutex(&this->mOSMutex);
        *(undefined *)((int)&this->mCardSlot + 2) = 0;
        this->mNextAction = READY;
        os::OSUnlockMutex(&this->mOSMutex);
        os::OSSignalCond(this + 1);
      }
    }
  }
  else {
    os::OSLockMutex(&this->mOSMutex);
    this->mNextAction = DETACH;
    *(undefined *)((int)&this->mCardSlot + 2) = 3;
    os::OSUnlockMutex(&this->mOSMutex);
    os::OSSignalCond(this + 1);
  }
  return;
}


/* __thiscall mDoMemCd_Ctrl_c::restore(void) */

void __thiscall mDoMemCd_Ctrl_c::restore(mDoMemCd_Ctrl_c *this)

{
  card_errors cVar1;
  int iVar2;
  CARDFileInfo CStack40;
  
  cVar1 = card::CARDOpen((uint)*(byte *)&this->mCardSlot,"gczelda",&CStack40);
  if (cVar1 == CARD_ERROR_READY) {
    iVar2 = m_Do_MemCardRWmng::mDoMemCdRWm_Restore(&CStack40,this,0x1650);
    if (iVar2 == 0) {
      this->mStatus = FORMAT;
    }
    else {
      setCardState(this,CARD_ERROR_READY);
    }
    card::CARDClose(&CStack40);
  }
  else {
    setCardState(this,cVar1);
  }
  return;
}


/* __thiscall mDoMemCd_Ctrl_c::store(void) */

void __thiscall mDoMemCd_Ctrl_c::store(mDoMemCd_Ctrl_c *this)

{
  card_errors cVar1;
  card_errors unaff_r31;
  CARDFileInfo CStack40;
  
  if (this->mStatus == CREATE) {
    unaff_r31 = card::CARDCreate((uint)*(byte *)&this->mCardSlot,"gczelda",0x18000,&CStack40);
    if (unaff_r31 == CARD_ERROR_READY) {
      this->mStatus = RESTORE;
    }
    else {
      if (unaff_r31 == CARD_ERROR_EXIST) {
        this->mStatus = RESTORE;
      }
      else {
        setCardState(this,unaff_r31);
      }
    }
  }
  if (this->mStatus == RESTORE) {
    cVar1 = card::CARDOpen((uint)*(byte *)&this->mCardSlot,"gczelda",&CStack40);
    if (cVar1 == CARD_ERROR_READY) {
      cVar1 = m_Do_MemCardRWmng::mDoMemCdRWm_Store(&CStack40,this,0x1650);
      if (cVar1 == CARD_ERROR_READY) {
        this->mStatus = READY;
      }
      else {
        setCardState(this,cVar1);
      }
      card::CARDClose(&CStack40);
    }
    else {
      setCardState(this,cVar1);
    }
  }
  else {
    setCardState(this,unaff_r31);
  }
  return;
}


/* __thiscall mDoMemCd_Ctrl_c::command_format(void) */

void __thiscall mDoMemCd_Ctrl_c::command_format(mDoMemCd_Ctrl_c *this)

{
  int iVar1;
  
  iVar1 = os::OSTryLockMutex(&this->mOSMutex);
  if (iVar1 != 0) {
    this->mNextAction = FORMAT;
    os::OSUnlockMutex(&this->mOSMutex);
    os::OSSignalCond(this + 1);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall mDoMemCd_Ctrl_c::save(void *,
                                    unsigned long,
                                    unsigned long) */

void __thiscall mDoMemCd_Ctrl_c::save(mDoMemCd_Ctrl_c *this,void *data,uint len,uint offset)

{
  int iVar1;
  
  iVar1 = os::OSTryLockMutex(&this->mOSMutex);
  if (iVar1 != 0) {
    copy_bytes((byte *)(&(this->mMemCardData).field_0x0 + offset),(byte *)data,len);
    this->mNextAction = CREATE;
    os::OSUnlockMutex(&this->mOSMutex);
    os::OSSignalCond(this + 1);
  }
  return;
}


/* __thiscall mDoMemCd_Ctrl_c::load(void) */

void __thiscall mDoMemCd_Ctrl_c::load(mDoMemCd_Ctrl_c *this)

{
  int iVar1;
  
  iVar1 = os::OSTryLockMutex(&this->mOSMutex);
  if (iVar1 != 0) {
    this->mNextAction = RESTORE;
    os::OSUnlockMutex(&this->mOSMutex);
    os::OSSignalCond(this + 1);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall mDoMemCd_Ctrl_c::LoadSync(void *,
                                        unsigned long,
                                        unsigned long) */

undefined4 __thiscall
mDoMemCd_Ctrl_c::LoadSync(mDoMemCd_Ctrl_c *this,void *param_1,ulong param_2,ulong param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = os::OSTryLockMutex(&this->mOSMutex);
  if (iVar1 != 0) {
    if (this->mStatus == FORMAT) {
      copy_bytes((byte *)param_1,(byte *)(&(this->mMemCardData).field_0x0 + param_3),param_2);
      this->mStatus = RESTORE;
      uVar2 = 1;
    }
    else {
      this->mStatus = CREATE;
      uVar2 = 2;
    }
    os::OSUnlockMutex(&this->mOSMutex);
  }
  return uVar2;
}


/* __thiscall mDoMemCd_Ctrl_c::SaveSync(void) */

undefined4 __thiscall mDoMemCd_Ctrl_c::SaveSync(mDoMemCd_Ctrl_c *this)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = os::OSTryLockMutex(&this->mOSMutex);
  if (iVar1 != 0) {
    if (this->mStatus == READY) {
      this->mStatus = RESTORE;
      uVar2 = 1;
    }
    else {
      if (this->mStatus == RESTORE) {
        uVar2 = 0;
      }
      else {
        uVar2 = 2;
      }
    }
    os::OSUnlockMutex(&this->mOSMutex);
  }
  return uVar2;
}


/* __thiscall mDoMemCd_Ctrl_c::getStatus(unsigned long) */

mDoMemCd_Ctrl_status __thiscall mDoMemCd_Ctrl_c::getStatus(mDoMemCd_Ctrl_c *this,ulong param_1)

{
  int iVar1;
  mDoMemCd_Ctrl_status unaff_r31;
  
  iVar1 = os::OSTryLockMutex(&this->mOSMutex);
  if (iVar1 == 0) {
    unaff_r31 = 0xe;
  }
  else {
    switch(this->mStatus) {
    case STANDBY:
      unaff_r31 = STANDBY;
      break;
    case RESTORE:
      unaff_r31 = CREATE;
      break;
    case CREATE:
      unaff_r31 = RESTORE;
      break;
    case FORMAT:
      unaff_r31 = FORMAT;
      break;
    case READY:
      unaff_r31 = READY;
      break;
    case DETACH:
      unaff_r31 = DETACH;
      break;
    case ENCODING:
      unaff_r31 = ERROR;
      break;
    case ERROR:
      unaff_r31 = ENCODING;
      break;
    case 8:
      unaff_r31 = 0xb;
      break;
    case 9:
      unaff_r31 = IOERROR;
      break;
    case WRONG_DEVICE:
      unaff_r31 = 9;
      break;
    case 0xb:
      unaff_r31 = WRONG_DEVICE;
      break;
    case IOERROR:
      unaff_r31 = 8;
      break;
    case 0xd:
      unaff_r31 = 0xe;
    }
    os::OSUnlockMutex(&this->mOSMutex);
  }
  return unaff_r31;
}


/* __thiscall mDoMemCd_Ctrl_c::format(void) */

void __thiscall mDoMemCd_Ctrl_c::format(mDoMemCd_Ctrl_c *this)

{
  card_errors cVar1;
  
  cVar1 = card::CARDFormat((uint)*(byte *)&this->mCardSlot);
  if (cVar1 == CARD_ERROR_READY) {
    this->mStatus = DETACH;
  }
  else {
    setCardState(this,cVar1);
  }
  return;
}


/* __thiscall mDoMemCd_Ctrl_c::FormatSync(void) */

undefined4 __thiscall mDoMemCd_Ctrl_c::FormatSync(mDoMemCd_Ctrl_c *this)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = os::OSTryLockMutex(&this->mOSMutex);
  if (iVar1 != 0) {
    if (this->mStatus == DETACH) {
      this->mStatus = CREATE;
      uVar2 = 1;
    }
    else {
      uVar2 = 2;
    }
    os::OSUnlockMutex(&this->mOSMutex);
  }
  return uVar2;
}


/* __thiscall mDoMemCd_Ctrl_c::attach(void) */

void __thiscall
mDoMemCd_Ctrl_c::attach(mDoMemCd_Ctrl_c *this,char *filename,ulong param_3,void *param_4)

{
  card_errors cVar1;
  int iVar2;
  mDoMemCd_Ctrl_status mVar3;
  uint *mem_size;
  uint *sect_size;
  uint local_18;
  uint auStack20 [4];
  
  mem_size = auStack20;
  sect_size = &local_18;
  cVar1 = card::CARDProbeEx((uint)*(byte *)&this->mCardSlot,mem_size,sect_size);
  if (cVar1 == CARD_ERROR_WRONGDEVICE) {
    this->mStatus = WRONG_DEVICE;
  }
  else {
    if (local_18 == 0x2000) {
      iVar2 = mount(this,(char *)mem_size,(char *)sect_size,filename,param_3,param_4);
      if (iVar2 != 0) {
        iVar2 = loadfile(this);
        if (iVar2 == 0) {
          mVar3 = checkspace(this);
          if (mVar3 == CREATE) {
            this->mStatus = 9;
          }
          else {
            if ((int)mVar3 < 2) {
              if (mVar3 == STANDBY) {
                this->mStatus = CREATE;
              }
              else {
                if (-1 < (int)mVar3) {
                  this->mStatus = 8;
                }
              }
            }
          }
        }
        else {
          this->mStatus = RESTORE;
        }
      }
    }
    else {
      this->mStatus = 0xb;
    }
  }
  return;
}


/* __thiscall mDoMemCd_Ctrl_c::detach(void) */

void __thiscall mDoMemCd_Ctrl_c::detach(mDoMemCd_Ctrl_c *this)

{
  card::CARDUnmount((uint)*(byte *)&this->mCardSlot);
  this->mStatus = STANDBY;
  return;
}


/* __thiscall mDoMemCd_Ctrl_c::mount(void) */

int __thiscall
mDoMemCd_Ctrl_c::mount
          (mDoMemCd_Ctrl_c *this,char *__special_file,char *__dir,char *__fstype,ulong __rwflag,
          void *__data)

{
  card_errors cVar1;
  
  cVar1 = card::CARDMount((uint)*(byte *)&this->mCardSlot,m_Do_MemCard::MemCardWorkArea0,0);
  if (cVar1 == CARD_ERROR_IOERROR) {
LAB_800196bc:
    this->mStatus = IOERROR;
    return 0;
  }
  if ((int)cVar1 < -5) {
    if (cVar1 == CARD_ERROR_ENCODING) {
      this->mStatus = ENCODING;
      return 0;
    }
    if ((int)cVar1 < -0xd) {
      if (cVar1 != CARD_ERROR_FATAL_ERROR) {
        return 0;
      }
      goto LAB_800196bc;
    }
    if ((int)cVar1 < -6) {
      return 0;
    }
  }
  else {
    if (cVar1 != CARD_ERROR_READY) {
      if (-1 < (int)cVar1) {
        return 0;
      }
      if (cVar1 != CARD_ERROR_NOCARD) {
        return 0;
      }
      this->mStatus = STANDBY;
      return 0;
    }
  }
  cVar1 = card::CARDCheck((uint)*(byte *)&this->mCardSlot);
  if (cVar1 == CARD_ERROR_READY) {
    return 1;
  }
  this->mStatus = ERROR;
  return 0;
}


/* __thiscall mDoMemCd_Ctrl_c::loadfile(void) */

bool __thiscall mDoMemCd_Ctrl_c::loadfile(mDoMemCd_Ctrl_c *this)

{
  card_errors cVar1;
  CARDFileInfo CStack40;
  
  cVar1 = card::CARDOpen((uint)*(byte *)&this->mCardSlot,"gczelda",&CStack40);
  if (cVar1 != CARD_ERROR_READY) {
    setCardState(this,cVar1);
  }
  else {
    card::CARDClose(&CStack40);
  }
  return cVar1 == CARD_ERROR_READY;
}


/* __thiscall mDoMemCd_Ctrl_c::checkspace(void) */

mDoMemCd_Ctrl_status __thiscall mDoMemCd_Ctrl_c::checkspace(mDoMemCd_Ctrl_c *this)

{
  card_errors cVar1;
  mDoMemCd_Ctrl_status mVar2;
  int block_count;
  int block_size;
  
  cVar1 = card::CARDFreeBlocks
                    ((uint)*(byte *)&this->mCardSlot,(CARDFileInfo *)&block_size,&block_count);
  if (cVar1 == CARD_ERROR_READY) {
    if (block_size < 0x18000) {
      mVar2 = RESTORE;
    }
    else {
      mVar2 = -((uint)(block_count == 0) - (block_count >> 0x1f)) & 2;
    }
  }
  else {
    setCardState(this,cVar1);
    mVar2 = FORMAT;
  }
  return mVar2;
}


/* __thiscall mDoMemCd_Ctrl_c::setCardState(long) */

void __thiscall mDoMemCd_Ctrl_c::setCardState(mDoMemCd_Ctrl_c *this,card_errors param_1)

{
  card_errors cVar1;
  
  if (param_1 == CARD_ERROR_IOERROR) {
LAB_80019874:
    this->mStatus = IOERROR;
  }
  else {
    if ((int)param_1 < -5) {
      if (param_1 == CARD_ERROR_ENCODING) {
        this->mStatus = ENCODING;
        return;
      }
      if ((int)param_1 < -0xd) {
        if (param_1 != CARD_ERROR_FATAL_ERROR) {
          return;
        }
        goto LAB_80019874;
      }
      if ((int)param_1 < -6) {
        return;
      }
    }
    else {
      if (param_1 != CARD_ERROR_READY) {
        if (-1 < (int)param_1) {
          return;
        }
        if (param_1 != CARD_ERROR_NOCARD) {
          return;
        }
        this->mStatus = STANDBY;
        return;
      }
    }
    cVar1 = card::CARDCheck((uint)*(byte *)&this->mCardSlot);
    if (cVar1 != CARD_ERROR_READY) {
      this->mStatus = ERROR;
    }
  }
  return;
}


namespace m_Do_MemCard {

/* __stdcall mDoMemCd_main(void *) */

undefined4 mDoMemCd_main(void)

{
  OSThread *pOVar1;
  JKRThread JStack104;
  
  pOVar1 = (OSThread *)os::OSGetCurrentThread();
  JKRThread::JKRThread(&JStack104,pOVar1,0);
  JKRThread::_JKRThread(&JStack104);
  JKRHeap::becomeCurrentHeap((JKRHeap *)0x0);
  ::mDoMemCd_Ctrl_c::main(&g_mDoMemCd_control);
  return 0;
}


void __sinit_m_Do_MemCard_cpp(void)

{
  ::mDoMemCd_Ctrl_c::mDoMemCd_Ctrl_c(&g_mDoMemCd_control);
  return;
}

