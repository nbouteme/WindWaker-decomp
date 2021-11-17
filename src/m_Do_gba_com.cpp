#include <m_Do_gba_com.h>
#include <m_Do_gba_com.h>
#include <SComponent/c_math.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTGba.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JKernel/JKRHeap.h>
#include <mDoGaC_agbCom_c.h>


namespace m_Do_ext {

namespace m_Do_gba_com {
undefined1 g_mDoGaC_gbaCom;
undefined TestDataManager;
undefined4 flag$4426;
undefined1 init$4427;
undefined1 data_type$4481;
undefined1 init$4482;
undefined4 check_sum$4484;
undefined1 init$4485;
undefined4 data_sum$4487;
undefined1 init$4488;
undefined4 recv_p$4490;
undefined1 init$4491;
undefined4 end_p$4493;
undefined1 init$4494;

/* __stdcall ProbeCheck_0(JUTGbaParam *,
                          void *) */

void ProbeCheck_0(void)

{
  ::mDoGaC_agbCom_c::mDoGaC_ProbeCheck0((mDoGaC_agbCom_c *)&g_mDoGaC_gbaCom);
  return;
}


/* __stdcall ProbeCheck_1(JUTGbaParam *,
                          void *) */

void ProbeCheck_1(void)

{
  ::mDoGaC_agbCom_c::mDoGaC_ProbeCheck1((mDoGaC_agbCom_c *)&g_mDoGaC_gbaCom);
  return;
}


/* __stdcall CodeExchange_0(JUTGbaParam *,
                            void *) */

void CodeExchange_0(void)

{
  ::mDoGaC_agbCom_c::mDoGaC_CodeExchange0((mDoGaC_agbCom_c *)&g_mDoGaC_gbaCom);
  return;
}


/* __stdcall CodeExchange_1(JUTGbaParam *,
                            void *) */

void CodeExchange_1(void)

{
  ::mDoGaC_agbCom_c::mDoGaC_CodeExchange1((mDoGaC_agbCom_c *)&g_mDoGaC_gbaCom);
  return;
}


/* __stdcall CodeExchange_2(JUTGbaParam *,
                            void *) */

void CodeExchange_2(void)

{
  ::mDoGaC_agbCom_c::mDoGaC_CodeExchange2((mDoGaC_agbCom_c *)&g_mDoGaC_gbaCom);
  return;
}


/* __stdcall CodeExchange_3(JUTGbaParam *,
                            void *) */

void CodeExchange_3(void)

{
  ::mDoGaC_agbCom_c::mDoGaC_CodeExchange3((mDoGaC_agbCom_c *)&g_mDoGaC_gbaCom);
  return;
}


/* __stdcall CodeExchange_4(JUTGbaParam *,
                            void *) */

void CodeExchange_4(void)

{
  ::mDoGaC_agbCom_c::mDoGaC_CodeExchange4((mDoGaC_agbCom_c *)&g_mDoGaC_gbaCom);
  return;
}


/* __stdcall ContextCheck(JUTGbaParam *,
                          void *) */

void ContextCheck(void)

{
  ::mDoGaC_agbCom_c::mDoGaC_ContextCheck((mDoGaC_agbCom_c *)&g_mDoGaC_gbaCom);
  return;
}


/* __stdcall ContextSend(JUTGbaParam *,
                         void *) */

void ContextSend(void)

{
  ::mDoGaC_agbCom_c::mDoGaC_ContextSend((mDoGaC_agbCom_c *)&g_mDoGaC_gbaCom);
  return;
}


/* __stdcall ContextRead(JUTGbaParam *,
                         void *) */

void ContextRead(void)

{
  ::mDoGaC_agbCom_c::mDoGaC_ContextRead((mDoGaC_agbCom_c *)&g_mDoGaC_gbaCom);
  return;
}


/* __stdcall GbaWriteResult(JUTGbaParam *,
                            void *) */

void GbaWriteResult(void)

{
  ::mDoGaC_agbCom_c::mDoGaC_WriteResult((mDoGaC_agbCom_c *)&g_mDoGaC_gbaCom);
  return;
}


/* __stdcall GbaReadResult(JUTGbaParam *,
                           void *) */

void GbaReadResult(void)

{
  ::mDoGaC_agbCom_c::mDoGaC_ReadResult((mDoGaC_agbCom_c *)&g_mDoGaC_gbaCom);
  return;
}


/* __stdcall GbaReset(JUTGbaParam *,
                      void *) */

void GbaReset(void)

{
  ::mDoGaC_agbCom_c::mDoGaC_GbaReset((mDoGaC_agbCom_c *)&g_mDoGaC_gbaCom);
  return;
}

}
}

/* __thiscall mDoGaC_agbCom_c::mDoGaC_Initial(mDoGaC_DataManag_c *,
                                              unsigned char) */

void __thiscall
mDoGaC_agbCom_c::mDoGaC_Initial(mDoGaC_agbCom_c *this,mDoGaC_DataManag_c *param_1,uchar param_2)

{
  int iVar1;
  ushort uVar2;
  undefined4 *puVar3;
  mDoGaC_agbCom_c *pmVar4;
  int iVar5;
  uint uVar6;
  float fVar7;
  
  *this = (mDoGaC_agbCom_c)0x0;
  this[1] = (mDoGaC_agbCom_c)0x0;
  this[2] = (mDoGaC_agbCom_c)0x0;
  this[3] = (mDoGaC_agbCom_c)0x0;
  this[4] = (mDoGaC_agbCom_c)0x1;
  this[5] = (mDoGaC_agbCom_c)0x0;
  this[0x10d] = (mDoGaC_agbCom_c)0x1;
  this[0x10e] = (mDoGaC_agbCom_c)0x0;
  this[7] = (mDoGaC_agbCom_c)0x0;
  this[8] = (mDoGaC_agbCom_c)0x0;
  this[0x10c] = (mDoGaC_agbCom_c)param_2;
  this[9] = (mDoGaC_agbCom_c)0x0;
  this[10] = (mDoGaC_agbCom_c)0x0;
  this[0xb] = (mDoGaC_agbCom_c)0x0;
  iVar1 = 0;
  iVar5 = 0x10;
  do {
    pmVar4 = this + iVar1;
    *(undefined4 *)(pmVar4 + 0xc) = 0;
    *(undefined4 *)(pmVar4 + 0x10) = 0;
    pmVar4[0x14] = (mDoGaC_agbCom_c)0x0;
    *(undefined4 *)(pmVar4 + 0x18) = 0;
    iVar1 = iVar1 + 0x10;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(mDoGaC_DataManag_c **)(this + 0x110) = param_1;
  iVar1 = 0;
  uVar6 = (uint)param_2;
  if (param_2 != '\0') {
    do {
      puVar3 = (undefined4 *)(param_1 + iVar1);
      *puVar3 = 0;
      *(undefined *)(puVar3 + 1) = 0;
      *(undefined *)((int)puVar3 + 5) = 0;
      iVar1 = iVar1 + 8;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  *(undefined4 *)(this + 0x114) = 0xffffffff;
  *(undefined4 *)(this + 0x118) = 0;
  fVar7 = SComponent::cM_rndF(m_Do_ext::m_Do_gba_com::_4066);
  uVar2 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)fVar7);
  *(ushort *)(this + 0x12e) = uVar2 & 0x7fff | *(ushort *)(this + 0x12e) & 0x8000;
  fVar7 = SComponent::cM_rndF(m_Do_ext::m_Do_gba_com::_4066);
  uVar6 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)fVar7);
  *(uint *)(this + 300) = (uVar6 & 0x7fff) << 0xf | *(uint *)(this + 300) & 0xc0007fff;
  this[300] = (mDoGaC_agbCom_c)((byte)this[300] & 0x3f | 0x40);
  this[0x128] = (mDoGaC_agbCom_c)0x0;
  return;
}


/* __thiscall mDoGaC_agbCom_c::mDoGaC_ComOpen(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_ComOpen(mDoGaC_agbCom_c *this)

{
  this[2] = (mDoGaC_agbCom_c)0x2;
  return;
}


/* __thiscall mDoGaC_agbCom_c::mDoGaC_ComClose(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_ComClose(mDoGaC_agbCom_c *this)

{
  int iVar1;
  int iVar2;
  
  this[4] = (mDoGaC_agbCom_c)0x1;
  iVar1 = 0;
  this[2] = (mDoGaC_agbCom_c)0x0;
  this[0x10e] = (mDoGaC_agbCom_c)0x0;
  for (iVar2 = 0; iVar2 < (int)(uint)(byte)this[0x10c]; iVar2 = iVar2 + 1) {
    *(undefined *)(*(int *)(this + 0x110) + iVar1 + 4) = 9;
    *(undefined *)(*(int *)(this + 0x110) + iVar1 + 5) = 1;
    iVar1 = iVar1 + 8;
  }
  return;
}


/* __thiscall mDoGaC_agbCom_c::mDoGaC_ComStart(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_ComStart(mDoGaC_agbCom_c *this)

{
  this[1] = (mDoGaC_agbCom_c)0x1;
  return;
}


/* __thiscall mDoGaC_agbCom_c::mDoGaC_ComStop(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_ComStop(mDoGaC_agbCom_c *this)

{
  mDoGaC_ComClose(this);
  this[1] = (mDoGaC_agbCom_c)0x0;
  this[5] = (mDoGaC_agbCom_c)0x0;
  return;
}


/* __thiscall mDoGaC_agbCom_c::mDoGaC_GbaReboot(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_GbaReboot(mDoGaC_agbCom_c *this)

{
  uint uVar1;
  float fVar2;
  
  mDoGaC_ComStop(this);
  *this = (mDoGaC_agbCom_c)0x0;
  this[3] = (mDoGaC_agbCom_c)0x0;
  fVar2 = SComponent::cM_rndF(m_Do_ext::m_Do_gba_com::_4066);
  uVar1 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)fVar2);
  *(uint *)(this + 300) = (uVar1 & 0x7fff) << 0xf | *(uint *)(this + 300) & 0xc0007fff;
  this[0x128] = (mDoGaC_agbCom_c)0x0;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mDoGaC_agbCom_c::mDoGaC_GbaReset(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_GbaReset(mDoGaC_agbCom_c *this)

{
  int iVar1;
  uchar auStack24 [16];
  
  iVar1 = JUTGba::resultReset(_sManager,(uint)DAT_803b9159,auStack24);
  if (iVar1 == 0) {
    this[6] = (mDoGaC_agbCom_c)((char)this[6] + '\x01');
    if ((byte)this[6] < 0x3d) {
      JUTGba::doReset(_sManager,(uint)DAT_803b9159,m_Do_ext::m_Do_gba_com::GbaReset,(void *)0x0);
    }
    else {
      mDoGaC_GbaReboot(this);
    }
  }
  else {
    mDoGaC_GbaReboot(this);
  }
  return;
}


/* __thiscall mDoGaC_agbCom_c::mDoGaC_ComRestart(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_ComRestart(mDoGaC_agbCom_c *this)

{
  int iVar1;
  int iVar2;
  
  this[4] = (mDoGaC_agbCom_c)0x0;
  this[7] = (mDoGaC_agbCom_c)0x0;
  this[8] = (mDoGaC_agbCom_c)0x0;
  this[9] = (mDoGaC_agbCom_c)0x0;
  this[10] = (mDoGaC_agbCom_c)0x0;
  this[0xb] = (mDoGaC_agbCom_c)0x0;
  iVar1 = 0;
  for (iVar2 = 0; iVar2 < (int)(uint)(byte)this[0x10c]; iVar2 = iVar2 + 1) {
    *(undefined *)(*(int *)(this + 0x110) + iVar1 + 4) = 0;
    *(undefined *)(*(int *)(this + 0x110) + iVar1 + 5) = 0;
    iVar1 = iVar1 + 8;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mDoGaC_agbCom_c::mDoGaC_Connect(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_Connect(mDoGaC_agbCom_c *this)

{
  mDoGaC_agbCom_c mVar1;
  
  if (*this != (mDoGaC_agbCom_c)0x0) {
    if (*mDoRst::mResetData == 0) {
      if (this[1] != (mDoGaC_agbCom_c)0x0) {
        mVar1 = this[2];
        if (mVar1 == (mDoGaC_agbCom_c)0x2) {
          mDoGaC_ComRestart(this);
          mDoGaC_GbaWrite(this);
          this[2] = (mDoGaC_agbCom_c)0x3;
        }
        else {
          if ((byte)mVar1 < 2) {
            if (mVar1 == (mDoGaC_agbCom_c)0x0) {
              this[2] = (mDoGaC_agbCom_c)0x1;
              JUTGba::doProbe(_sManager,(uint)DAT_803b9159,m_Do_ext::m_Do_gba_com::ProbeCheck_0,
                              (void *)0x0);
              if ((byte)this[0x10e] < 3) {
                this[0x10e] = (mDoGaC_agbCom_c)((char)this[0x10e] + 1);
              }
            }
          }
          else {
            if ((mVar1 != (mDoGaC_agbCom_c)0x4) && ((byte)mVar1 < 4)) {
              if (this[5] == (mDoGaC_agbCom_c)0x0) {
                mDoGaC_SendDataWrite(this);
              }
              if (this[4] == (mDoGaC_agbCom_c)0x1) {
                mDoGaC_ComClose(this);
              }
              this[0x10e] = (mDoGaC_agbCom_c)0x0;
            }
          }
        }
      }
    }
    else {
      mDoGaC_ComStop(this);
      this[6] = (mDoGaC_agbCom_c)0x0;
      JUTGba::doReset(_sManager,(uint)DAT_803b9159,m_Do_ext::m_Do_gba_com::GbaReset,(void *)0x0);
    }
  }
  return;
}


/* __thiscall mDoGaC_agbCom_c::mDoGaC_ConnectSleep(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_ConnectSleep(mDoGaC_agbCom_c *this)

{
  if (this[2] != (mDoGaC_agbCom_c)0x0) {
    return;
  }
  this[2] = (mDoGaC_agbCom_c)0x4;
  return;
}


/* __thiscall mDoGaC_agbCom_c::mDoGaC_ConnectWake(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_ConnectWake(mDoGaC_agbCom_c *this)

{
  this[2] = (mDoGaC_agbCom_c)0x0;
  return;
}


/* __thiscall mDoGaC_agbCom_c::mDoGaC_GbaLink(void) */

undefined4 __thiscall mDoGaC_agbCom_c::mDoGaC_GbaLink(mDoGaC_agbCom_c *this)

{
  if (((*this == (mDoGaC_agbCom_c)0x1) && (this[2] == (mDoGaC_agbCom_c)0x3)) &&
     (this[4] == (mDoGaC_agbCom_c)0x0)) {
    return 1;
  }
  if ((this[0x128] == (mDoGaC_agbCom_c)0x1) && ((byte)this[0x10e] < 3)) {
    return 1;
  }
  return 0;
}


/* __thiscall mDoGaC_agbCom_c::mDoGaC_SendDataSet(unsigned long *,
                                                  int,
                                                  unsigned char,
                                                  unsigned long) */

undefined4 __thiscall
mDoGaC_agbCom_c::mDoGaC_SendDataSet
          (mDoGaC_agbCom_c *this,ulong *param_1,int param_2,uchar param_3,ulong param_4)

{
  uint uVar1;
  
  uVar1 = (byte)this[9] + 1 & 0xff;
  if (0xf < uVar1) {
    uVar1 = 0;
  }
  if ((uVar1 != (byte)this[10]) && (0 < param_2)) {
    if (param_2 < 4) {
      param_2 = 4;
    }
    *(ulong **)(this + (uint)(byte)this[9] * 0x10 + 0xc) = param_1;
    *(int *)(this + (uint)(byte)this[9] * 0x10 + 0x10) = param_2;
    this[(uint)(byte)this[9] * 0x10 + 0x14] = (mDoGaC_agbCom_c)param_3;
    *(ulong *)(this + (uint)(byte)this[9] * 0x10 + 0x18) = param_4;
    *(undefined *)(*(int *)(this + 0x110) + (uint)param_3 * 8 + 4) = 2;
    this[9] = (mDoGaC_agbCom_c)((char)this[9] + '\x01');
    if (0xf < (byte)this[9]) {
      this[9] = (mDoGaC_agbCom_c)0x0;
    }
    this[0xb] = (mDoGaC_agbCom_c)((char)this[0xb] + '\x01');
    return 1;
  }
  return 0;
}


/* __thiscall mDoGaC_agbCom_c::mDoGaC_SendDataWrite(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_SendDataWrite(mDoGaC_agbCom_c *this)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  mDoGaC_agbCom_c mVar5;
  uint uVar6;
  
  mVar5 = (mDoGaC_agbCom_c)0x0;
  do {
    if ((byte)this[0x10c] <= (byte)mVar5) {
      return;
    }
    iVar4 = (uint)(byte)mVar5 * 8;
    cVar1 = *(char *)(*(int *)(this + 0x110) + iVar4 + 5);
    if (cVar1 != '\0') {
      uVar6 = (uint)(byte)this[9];
      uVar3 = uVar6 + 1 & 0xff;
      if (0xf < uVar3) {
        uVar3 = 0;
      }
      if (uVar3 == (byte)this[10]) {
        return;
      }
      cVar2 = *(char *)(*(int *)(this + 0x110) + iVar4 + 4);
      if ((cVar2 == '\0') || (cVar2 == '\x01')) {
        if (cVar1 == '\x01') {
          *(mDoGaC_agbCom_c **)(this + uVar6 * 0x10 + 0xc) = this + 0x11c;
          *(undefined4 *)(this + (uint)(byte)this[9] * 0x10 + 0x10) = 4;
        }
        else {
          *(mDoGaC_agbCom_c **)(this + uVar6 * 0x10 + 0xc) = this + 0x120;
          *(undefined4 *)(this + (uint)(byte)this[9] * 0x10 + 0x10) = 8;
        }
        this[(uint)(byte)this[9] * 0x10 + 0x14] = mVar5;
        *(undefined4 *)(this + (uint)(byte)this[9] * 0x10 + 0x18) = 0;
        *(undefined *)(*(int *)(this + 0x110) + iVar4 + 4) = 2;
        this[9] = (mDoGaC_agbCom_c)((char)this[9] + '\x01');
        if (0xf < (byte)this[9]) {
          this[9] = (mDoGaC_agbCom_c)0x0;
        }
        this[0xb] = (mDoGaC_agbCom_c)((char)this[0xb] + '\x01');
        *(undefined *)(*(int *)(this + 0x110) + iVar4 + 5) = 0;
      }
    }
    mVar5 = (mDoGaC_agbCom_c)((char)mVar5 + '\x01');
  } while( true );
}


/* __thiscall mDoGaC_agbCom_c::mDoGaC_SendEntry(unsigned char,
                                                unsigned long) */

undefined4 __thiscall
mDoGaC_agbCom_c::mDoGaC_SendEntry(mDoGaC_agbCom_c *this,uchar param_1,ulong param_2)

{
  if (*(char *)(*(int *)(this + 0x110) + (uint)param_1 * 8 + 5) == '\0') {
    *(ulong *)(this + 0x11c) = param_2;
    *(undefined *)(*(int *)(this + 0x110) + (uint)param_1 * 8 + 5) = 1;
    return 1;
  }
  return 0;
}


/* __thiscall mDoGaC_agbCom_c::mDoGaC_SendStatusCheck(unsigned char) */

undefined4 __thiscall mDoGaC_agbCom_c::mDoGaC_SendStatusCheck(mDoGaC_agbCom_c *this,uchar param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(*(int *)(this + 0x110) + (uint)param_1 * 8 + 4);
  if ((cVar1 != '\0') && (cVar1 != '\x01')) {
    return 0;
  }
  return 1;
}


/* __thiscall mDoGaC_agbCom_c::mDoGaC_SendEndCheck(unsigned char) */

undefined4 __thiscall mDoGaC_agbCom_c::mDoGaC_SendEndCheck(mDoGaC_agbCom_c *this,uchar param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(*(int *)(this + 0x110) + (uint)param_1 * 8 + 4);
  if ((cVar1 != '\x04') && (cVar1 != '\0')) {
    return 0;
  }
  return 1;
}


/* __thiscall mDoGaC_agbCom_c::mDoGaC_RecvStatusCheck(unsigned char) */

uint __thiscall mDoGaC_agbCom_c::mDoGaC_RecvStatusCheck(mDoGaC_agbCom_c *this,uchar param_1)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(8 - (uint)*(byte *)(*(int *)(this + 0x110) + (uint)param_1 * 8 + 4));
  return uVar1 >> 5;
}


/* __thiscall mDoGaC_agbCom_c::mDoGaC_DataStatusReset(unsigned char) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_DataStatusReset(mDoGaC_agbCom_c *this,uchar param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x110) + (uint)param_1 * 8;
  if (*(char *)(iVar1 + 4) == '\b') {
    *(undefined *)(iVar1 + 4) = 0;
    mDoGaC_StatusSendSet(this,param_1);
  }
  return;
}


/* __thiscall mDoGaC_agbCom_c::mDoGaC_StatusSendSet(unsigned char) */

undefined4 __thiscall mDoGaC_agbCom_c::mDoGaC_StatusSendSet(mDoGaC_agbCom_c *this,uchar param_1)

{
  uint uVar1;
  
  uVar1 = (byte)this[9] + 1 & 0xff;
  if (0xf < uVar1) {
    uVar1 = 0;
  }
  if (uVar1 == (byte)this[10]) {
    return 0;
  }
  *(undefined4 *)(this + (uint)(byte)this[9] * 0x10 + 0xc) = 0;
  *(undefined4 *)(this + (uint)(byte)this[9] * 0x10 + 0x10) = 0;
  this[(uint)(byte)this[9] * 0x10 + 0x14] = (mDoGaC_agbCom_c)param_1;
  *(undefined4 *)(this + (uint)(byte)this[9] * 0x10 + 0x18) = 0;
  this[9] = (mDoGaC_agbCom_c)((char)this[9] + '\x01');
  if (0xf < (byte)this[9]) {
    this[9] = (mDoGaC_agbCom_c)0x0;
  }
  this[0xb] = (mDoGaC_agbCom_c)((char)this[0xb] + '\x01');
  return 1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mDoGaC_agbCom_c::mDoGaC_ProbeCheck0(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_ProbeCheck0(mDoGaC_agbCom_c *this)

{
  int iVar1;
  ulong local_18 [4];
  
  iVar1 = JUTGba::resultProbe(_sManager,(uint)DAT_803b9159,local_18);
  if ((iVar1 == 0) && (local_18[0] == 0x40000)) {
    JUTGba::doReset(_sManager,(uint)DAT_803b9159,m_Do_ext::m_Do_gba_com::ProbeCheck_1,(void *)0x0);
  }
  else {
    this[2] = (mDoGaC_agbCom_c)0x0;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mDoGaC_agbCom_c::mDoGaC_ProbeCheck1(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_ProbeCheck1(mDoGaC_agbCom_c *this)

{
  int iVar1;
  uchar auStack24 [16];
  
  iVar1 = JUTGba::resultReset(_sManager,(uint)DAT_803b9159,auStack24);
  if (iVar1 == 0) {
    JUTGba::doGetStatus(_sManager,(uint)DAT_803b9159,m_Do_ext::m_Do_gba_com::CodeExchange_0,
                        (void *)0x0);
  }
  else {
    this[2] = (mDoGaC_agbCom_c)0x0;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mDoGaC_agbCom_c::mDoGaC_CodeExchange0(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_CodeExchange0(mDoGaC_agbCom_c *this)

{
  int iVar1;
  uchar local_18 [16];
  
  iVar1 = JUTGba::resultGetStatus(_sManager,(uint)DAT_803b9159,local_18);
  if ((iVar1 == 0) && (local_18[0] == '(')) {
    JUTGba::doRead(_sManager,(uint)DAT_803b9159,(uchar *)(this + 0x118),
                   m_Do_ext::m_Do_gba_com::CodeExchange_1,(void *)0x0);
  }
  else {
    this[2] = (mDoGaC_agbCom_c)0x0;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mDoGaC_agbCom_c::mDoGaC_CodeExchange1(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_CodeExchange1(mDoGaC_agbCom_c *this)

{
  int iVar1;
  uchar auStack24 [16];
  
  iVar1 = JUTGba::resultRead(_sManager,(uint)DAT_803b9159,auStack24);
  if (iVar1 == 0) {
    if (*(int *)(this + 0x118) == m_Do_ext::m_Do_gba_com::_stringBase0) {
      JUTGba::doGetStatus(_sManager,(uint)DAT_803b9159,m_Do_ext::m_Do_gba_com::CodeExchange_2,
                          (void *)0x0);
    }
    else {
      mDoGaC_GbaReboot(this);
    }
  }
  else {
    this[2] = (mDoGaC_agbCom_c)0x0;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mDoGaC_agbCom_c::mDoGaC_CodeExchange2(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_CodeExchange2(mDoGaC_agbCom_c *this)

{
  int iVar1;
  uchar local_18 [16];
  
  iVar1 = JUTGba::resultGetStatus(_sManager,(uint)DAT_803b9159,local_18);
  if ((iVar1 == 0) && (local_18[0] == ' ')) {
    *(undefined4 *)(this + 0x114) = m_Do_ext::m_Do_gba_com::_stringBase0;
    JUTGba::doWrite(_sManager,(uint)DAT_803b9159,(uchar *)(this + 0x114),
                    m_Do_ext::m_Do_gba_com::CodeExchange_3,(void *)0x0);
  }
  else {
    this[2] = (mDoGaC_agbCom_c)0x0;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mDoGaC_agbCom_c::mDoGaC_CodeExchange3(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_CodeExchange3(mDoGaC_agbCom_c *this)

{
  int iVar1;
  uchar auStack24 [16];
  
  iVar1 = JUTGba::resultWrite(_sManager,(uint)DAT_803b9159,auStack24);
  if (iVar1 == 0) {
    JUTGba::doGetStatus(_sManager,(uint)DAT_803b9159,m_Do_ext::m_Do_gba_com::CodeExchange_4,
                        (void *)0x0);
  }
  else {
    this[2] = (mDoGaC_agbCom_c)0x0;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mDoGaC_agbCom_c::mDoGaC_CodeExchange4(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_CodeExchange4(mDoGaC_agbCom_c *this)

{
  int iVar1;
  undefined4 uVar2;
  uchar local_18 [16];
  
  iVar1 = JUTGba::resultGetStatus(_sManager,(uint)DAT_803b9159,local_18);
  if ((iVar1 == 0) && (local_18[0] == '0')) {
    this[300] = (mDoGaC_agbCom_c)(DAT_803b9159 << 6 | (byte)this[300] & 0x3f);
    uVar2 = m_Do_ext::m_Do_gba_com::BigLittleChange(*(undefined4 *)(this + 300));
    *(undefined4 *)(this + 0x114) = uVar2;
    JUTGba::doWrite(_sManager,(uint)DAT_803b9159,(uchar *)(this + 0x114),
                    m_Do_ext::m_Do_gba_com::ContextSend,(void *)0x0);
  }
  else {
    this[2] = (mDoGaC_agbCom_c)0x0;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mDoGaC_agbCom_c::mDoGaC_ContextCheck(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_ContextCheck(mDoGaC_agbCom_c *this)

{
  int iVar1;
  uchar auStack24 [20];
  
  iVar1 = JUTGba::resultRead(_sManager,(uint)DAT_803b9159,auStack24);
  if (iVar1 == 0) {
    iVar1 = m_Do_ext::m_Do_gba_com::BigLittleChange(*(undefined4 *)(this + 0x118));
    if (iVar1 == *(int *)(this + 300)) {
      if (this[0x128] == (mDoGaC_agbCom_c)0x1) {
        this[3] = (mDoGaC_agbCom_c)0x1;
      }
      else {
        this[0x128] = (mDoGaC_agbCom_c)0x1;
      }
      mDoGaC_ComOpen(this);
    }
    else {
      this[2] = (mDoGaC_agbCom_c)0x0;
    }
  }
  else {
    this[2] = (mDoGaC_agbCom_c)0x0;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mDoGaC_agbCom_c::mDoGaC_ContextSend(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_ContextSend(mDoGaC_agbCom_c *this)

{
  int iVar1;
  uchar auStack24 [16];
  
  iVar1 = JUTGba::resultWrite(_sManager,(uint)DAT_803b9159,auStack24);
  if (iVar1 == 0) {
    JUTGba::doGetStatus(_sManager,(uint)DAT_803b9159,m_Do_ext::m_Do_gba_com::ContextRead,(void *)0x0
                       );
  }
  else {
    this[2] = (mDoGaC_agbCom_c)0x0;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mDoGaC_agbCom_c::mDoGaC_ContextRead(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_ContextRead(mDoGaC_agbCom_c *this)

{
  int iVar1;
  uchar local_18 [16];
  
  iVar1 = JUTGba::resultGetStatus(_sManager,(uint)DAT_803b9159,local_18);
  if ((iVar1 == 0) && (local_18[0] == '8')) {
    JUTGba::doRead(_sManager,(uint)DAT_803b9159,(uchar *)(this + 0x118),
                   m_Do_ext::m_Do_gba_com::ContextCheck,(void *)0x0);
  }
  else {
    this[2] = (mDoGaC_agbCom_c)0x0;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x8001b4d0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mDoGaC_agbCom_c::mDoGaC_GbaWrite(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_GbaWrite(mDoGaC_agbCom_c *this)

{
  mDoGaC_agbCom_c mVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  if (m_Do_ext::m_Do_gba_com::init_4427 == '\0') {
    m_Do_ext::m_Do_gba_com::flag_4426 = 0;
    m_Do_ext::m_Do_gba_com::init_4427 = '\x01';
  }
  if ((uint)(byte)this[10] == (uint)(byte)this[9]) {
    if (this[5] == (mDoGaC_agbCom_c)0x1) {
      mDoGaC_ComStop(this);
      *(undefined4 *)(this + 0x114) = 0xefefefef;
    }
    else {
      *(undefined4 *)(this + 0x114) = 0xffffffff;
    }
  }
  else {
    piVar4 = (int *)(this + (uint)(byte)this[10] * 0x10 + 0xc);
    mVar1 = this[8];
    if (mVar1 == (mDoGaC_agbCom_c)0x3) {
      uVar2 = m_Do_ext::m_Do_gba_com::BigLittleChange(piVar4[1]);
      *(undefined4 *)(this + 0x114) = uVar2;
      piVar4[3] = 0;
      this[8] = (mDoGaC_agbCom_c)0x5;
    }
    else {
      if ((byte)mVar1 < 3) {
        if (mVar1 == (mDoGaC_agbCom_c)0x1) {
          uVar2 = m_Do_ext::m_Do_gba_com::BigLittleChange(*(undefined *)(piVar4 + 2));
          *(undefined4 *)(this + 0x114) = uVar2;
          this[8] = (mDoGaC_agbCom_c)0x2;
        }
        else {
          if (mVar1 == (mDoGaC_agbCom_c)0x0) {
            uVar2 = m_Do_ext::m_Do_gba_com::BigLittleChange(0xfefefefe);
            *(undefined4 *)(this + 0x114) = uVar2;
            this[8] = (mDoGaC_agbCom_c)0x1;
          }
          else {
            iVar3 = *(int *)(this + 0x110) + (uint)*(byte *)(piVar4 + 2) * 8;
            if (*(char *)(iVar3 + 4) == '\x02') {
              *(undefined *)(iVar3 + 4) = 3;
              uVar2 = m_Do_ext::m_Do_gba_com::BigLittleChange(3);
              *(undefined4 *)(this + 0x114) = uVar2;
              this[8] = (mDoGaC_agbCom_c)0x3;
            }
            else {
              uVar2 = m_Do_ext::m_Do_gba_com::BigLittleChange();
              *(undefined4 *)(this + 0x114) = uVar2;
              iVar3 = *(int *)(this + 0x110) + (uint)*(byte *)(piVar4 + 2) * 8;
              if (*(char *)(iVar3 + 4) == '\x05') {
                *(undefined *)(iVar3 + 4) = 6;
              }
              this[0xb] = (mDoGaC_agbCom_c)((char)this[0xb] + -1);
              this[10] = (mDoGaC_agbCom_c)((char)this[10] + '\x01');
              if (0xf < (byte)this[10]) {
                this[10] = (mDoGaC_agbCom_c)0x0;
              }
              this[8] = (mDoGaC_agbCom_c)0x0;
            }
          }
        }
      }
      else {
        if (mVar1 == (mDoGaC_agbCom_c)0x5) {
          *(undefined4 *)(this + 0x114) = *(undefined4 *)*piVar4;
          iVar3 = m_Do_ext::m_Do_gba_com::BigLittleChange(*(undefined4 *)(this + 0x114));
          piVar4[3] = piVar4[3] + iVar3;
          piVar4[1] = piVar4[1] + -4;
          if (piVar4[1] < 1) {
            this[8] = (mDoGaC_agbCom_c)0x4;
          }
          else {
            *piVar4 = *piVar4 + 4;
          }
        }
        else {
          if ((byte)mVar1 < 5) {
            uVar2 = m_Do_ext::m_Do_gba_com::BigLittleChange(piVar4[3]);
            *(undefined4 *)(this + 0x114) = uVar2;
            *(undefined *)(*(int *)(this + 0x110) + (uint)*(byte *)(piVar4 + 2) * 8 + 4) = 4;
            this[0xb] = (mDoGaC_agbCom_c)((char)this[0xb] + -1);
            this[10] = (mDoGaC_agbCom_c)((char)this[10] + '\x01');
            if (0xf < (byte)this[10]) {
              this[10] = (mDoGaC_agbCom_c)0x0;
            }
            this[8] = (mDoGaC_agbCom_c)0x0;
          }
          else {
            *(undefined4 *)(this + 0x114) = 0xffffffff;
          }
        }
      }
    }
  }
  JUTGba::doWrite(_sManager,(uint)DAT_803b9159,(uchar *)(this + 0x114),
                  m_Do_ext::m_Do_gba_com::GbaWriteResult,(void *)0x0);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mDoGaC_agbCom_c::mDoGaC_WriteResult(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_WriteResult(mDoGaC_agbCom_c *this)

{
  int iVar1;
  uchar auStack24 [20];
  
  iVar1 = JUTGba::resultWrite(_sManager,(uint)DAT_803b9159,auStack24);
  if ((iVar1 == 0) && (this[4] == (mDoGaC_agbCom_c)0x0)) {
    mDoGaC_GbaRead(this);
  }
  else {
    this[4] = (mDoGaC_agbCom_c)0x1;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mDoGaC_agbCom_c::mDoGaC_GbaRead(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_GbaRead(mDoGaC_agbCom_c *this)

{
  JUTGba::doRead(_sManager,(uint)DAT_803b9159,(uchar *)(this + 0x118),
                 m_Do_ext::m_Do_gba_com::GbaReadResult,(void *)0x0);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mDoGaC_agbCom_c::mDoGaC_ReadResult(void) */

void __thiscall mDoGaC_agbCom_c::mDoGaC_ReadResult(mDoGaC_agbCom_c *this)

{
  int iVar1;
  uchar auStack24 [20];
  
  if (m_Do_ext::m_Do_gba_com::init_4482 == '\0') {
    m_Do_ext::m_Do_gba_com::data_type_4481 = 0;
    m_Do_ext::m_Do_gba_com::init_4482 = '\x01';
  }
  if (m_Do_ext::m_Do_gba_com::init_4485 == '\0') {
    m_Do_ext::m_Do_gba_com::check_sum_4484 = 0;
    m_Do_ext::m_Do_gba_com::init_4485 = '\x01';
  }
  if (m_Do_ext::m_Do_gba_com::init_4488 == '\0') {
    m_Do_ext::m_Do_gba_com::data_sum_4487 = 0;
    m_Do_ext::m_Do_gba_com::init_4488 = '\x01';
  }
  if (m_Do_ext::m_Do_gba_com::init_4491 == '\0') {
    m_Do_ext::m_Do_gba_com::recv_p_4490 = (undefined4 *)0x0;
    m_Do_ext::m_Do_gba_com::init_4491 = '\x01';
  }
  if (m_Do_ext::m_Do_gba_com::init_4494 == '\0') {
    m_Do_ext::m_Do_gba_com::end_p_4493 = (undefined4 *)0x0;
    m_Do_ext::m_Do_gba_com::init_4494 = '\x01';
  }
  iVar1 = JUTGba::resultRead(_sManager,(uint)DAT_803b9159,auStack24);
  if ((iVar1 == 0) && (this[4] == (mDoGaC_agbCom_c)0x0)) {
    switch(this[7]) {
    case (mDoGaC_agbCom_c)0x0:
      iVar1 = m_Do_ext::m_Do_gba_com::BigLittleChange(*(undefined4 *)(this + 0x118));
      if (iVar1 == -0x1010102) {
        this[7] = (mDoGaC_agbCom_c)0x1;
      }
      break;
    case (mDoGaC_agbCom_c)0x1:
      m_Do_ext::m_Do_gba_com::data_type_4481 =
           m_Do_ext::m_Do_gba_com::BigLittleChange(*(undefined4 *)(this + 0x118));
      if (m_Do_ext::m_Do_gba_com::data_type_4481 < 0x10) {
        m_Do_ext::m_Do_gba_com::recv_p_4490 =
             *(undefined4 **)
              (*(int *)(this + 0x110) + (uint)m_Do_ext::m_Do_gba_com::data_type_4481 * 8);
      }
      else {
        m_Do_ext::m_Do_gba_com::recv_p_4490 = (undefined4 *)0x0;
      }
      this[7] = (mDoGaC_agbCom_c)0x2;
      break;
    case (mDoGaC_agbCom_c)0x2:
      iVar1 = m_Do_ext::m_Do_gba_com::BigLittleChange(*(undefined4 *)(this + 0x118));
      *(char *)(*(int *)(this + 0x110) + (uint)m_Do_ext::m_Do_gba_com::data_type_4481 * 8 + 4) =
           (char)iVar1;
      if (iVar1 == 7) {
        this[7] = (mDoGaC_agbCom_c)0x3;
      }
      else {
        this[7] = (mDoGaC_agbCom_c)0x0;
        if (iVar1 == 9) {
          this[4] = (mDoGaC_agbCom_c)0x1;
        }
      }
      break;
    case (mDoGaC_agbCom_c)0x3:
      iVar1 = m_Do_ext::m_Do_gba_com::BigLittleChange(*(undefined4 *)(this + 0x118));
      m_Do_ext::m_Do_gba_com::end_p_4493 =
           (undefined4 *)
           (*(int *)(*(int *)(this + 0x110) + (uint)m_Do_ext::m_Do_gba_com::data_type_4481 * 8) +
           (iVar1 + 3U & 0xfffffffc));
      m_Do_ext::m_Do_gba_com::data_sum_4487 = 0;
      if (m_Do_ext::m_Do_gba_com::recv_p_4490 == (undefined4 *)0x0) {
        this[7] = (mDoGaC_agbCom_c)0x6;
      }
      else {
        this[7] = (mDoGaC_agbCom_c)0x5;
      }
      break;
    case (mDoGaC_agbCom_c)0x4:
      m_Do_ext::m_Do_gba_com::check_sum_4484 =
           m_Do_ext::m_Do_gba_com::BigLittleChange(*(undefined4 *)(this + 0x118));
      if (m_Do_ext::m_Do_gba_com::data_sum_4487 == m_Do_ext::m_Do_gba_com::check_sum_4484) {
        *(undefined *)
         (*(int *)(this + 0x110) + (uint)m_Do_ext::m_Do_gba_com::data_type_4481 * 8 + 4) = 8;
      }
      else {
        *(undefined *)
         (*(int *)(this + 0x110) + (uint)m_Do_ext::m_Do_gba_com::data_type_4481 * 8 + 4) = 9;
        mDoGaC_StatusSendSet(this,m_Do_ext::m_Do_gba_com::data_type_4481);
        this[4] = (mDoGaC_agbCom_c)0x1;
      }
      this[7] = (mDoGaC_agbCom_c)0x0;
      break;
    case (mDoGaC_agbCom_c)0x5:
      *m_Do_ext::m_Do_gba_com::recv_p_4490 = *(undefined4 *)(this + 0x118);
      iVar1 = m_Do_ext::m_Do_gba_com::BigLittleChange();
      m_Do_ext::m_Do_gba_com::data_sum_4487 = m_Do_ext::m_Do_gba_com::data_sum_4487 + iVar1;
    case (mDoGaC_agbCom_c)0x6:
      m_Do_ext::m_Do_gba_com::recv_p_4490 = m_Do_ext::m_Do_gba_com::recv_p_4490 + 1;
      if (m_Do_ext::m_Do_gba_com::end_p_4493 <= m_Do_ext::m_Do_gba_com::recv_p_4490) {
        this[7] = (mDoGaC_agbCom_c)0x4;
      }
    }
    mDoGaC_GbaWrite(this);
  }
  else {
    this[4] = (mDoGaC_agbCom_c)0x1;
  }
  return;
}


namespace m_Do_ext {

namespace m_Do_gba_com {

/* __stdcall BigLittleChange(unsigned long) */

undefined4 BigLittleChange(undefined4 param_1)

{
  undefined local_4;
  undefined uStack3;
  undefined uStack2;
  
  uStack2 = (undefined)((uint)param_1 >> 8);
  uStack3 = (undefined)((uint)param_1 >> 0x10);
  local_4 = (undefined)((uint)param_1 >> 0x18);
  return CONCAT31(CONCAT21(CONCAT11((char)param_1,uStack2),uStack3),local_4);
}


void __sinit_m_Do_gba_com_cpp(void)

{
  Runtime.PPCEABI.H::__register_global_object
            (&g_mDoGaC_gbaCom,::mDoGaC_agbCom_c::_mDoGaC_agbCom_c,&_3978);
  return;
}

}
}

/* __thiscall mDoGaC_agbCom_c::~mDoGaC_agbCom_c(void) */

void __thiscall mDoGaC_agbCom_c::_mDoGaC_agbCom_c(mDoGaC_agbCom_c *this)

{
  short in_r4;
  
  if ((this != (mDoGaC_agbCom_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

