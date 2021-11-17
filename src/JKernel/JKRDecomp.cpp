#include <JKernel/JKRDecomp.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRDecomp.h>
#include <JKernel/JKRThread.h>
#include <os/OSThread.h>
#include <os/OSMessage.h>
#include <JKernel/JKRAramPiece.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <Demangler/JKRDecompCommand.h>
#include <JKRDecomp.h>

undefined1 JKRDecomp;

namespace JKRDecomp {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall create(long) */

JKRDecomp * create(long param_1)

{
  JKRDecomp *this;
  
  this = _sDecompObject;
  if ((_sDecompObject == (JKRDecomp *)0x0) &&
     (this = (JKRDecomp *)JKernel::operator_new(0x68,JKRHeap::sSystemHeap,0),
     this != (JKRDecomp *)0x0)) {
    JKRDecomp(this,param_1);
  }
  _sDecompObject = this;
  return _sDecompObject;
}

}

/* __thiscall JKRDecomp::JKRDecomp(long) */

void __thiscall JKRDecomp::JKRDecomp(JKRDecomp *this,long param_1)

{
  JKRThread::JKRThread((JKRThread *)this,0x4000,0x10,param_1);
  *(undefined1 **)this = &__vt;
  os::OSResumeThread(*(OSThread **)(this + 0x2c));
  return;
}


/* __thiscall JKRDecomp::~JKRDecomp(void) */

void __thiscall JKRDecomp::_JKRDecomp(JKRDecomp *this)

{
  short in_r4;
  
  if (this != (JKRDecomp *)0x0) {
    *(undefined1 **)this = &__vt;
    JKRThread::_JKRThread((JKRThread *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JKRDecomp::run(void) */

void __thiscall JKRDecomp::run(JKRDecomp *this)

{
  int iVar1;
  JKRAMCommand *extraout_r4;
  ulong in_r7;
  int local_18 [4];
  
  os::OSInitMessageQueue((OSMessageQueue *)&sMessageQueue,(OSMessage *)&sMessageBuffer,4);
  do {
    while( true ) {
      while( true ) {
        os::OSReceiveMessage(&sMessageQueue,local_18,1);
        iVar1 = local_18[0];
        decode(*(JKRDecomp **)(local_18[0] + 4),*(uchar **)(local_18[0] + 8),
               *(uchar **)(local_18[0] + 0xc),*(ulong *)(local_18[0] + 0x10),in_r7);
        if (*(int *)(iVar1 + 0x20) == 0) break;
        if (*(int *)(iVar1 + 0x20) == 1) {
          JKRAramPiece::sendCommand(*(JKRAramPiece **)(iVar1 + 0x24),extraout_r4);
        }
      }
      if (*(code **)(iVar1 + 0x14) == (code *)0x0) break;
      (**(code **)(iVar1 + 0x14))(iVar1);
    }
    if (*(int *)(iVar1 + 0x1c) == 0) {
      os::OSSendMessage(iVar1 + 0x28,1,0);
    }
    else {
      os::OSSendMessage(*(int *)(iVar1 + 0x1c),1,0);
    }
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JKRDecomp::prepareCommand(unsigned char *,
                                        unsigned char *,
                                        unsigned long,
                                        unsigned long,
                                        void *(unsigned long)) */

JKRDecompCommand * __thiscall
JKRDecomp::prepareCommand
          (JKRDecomp *this,uchar *param_1,uchar *param_2,ulong param_3,ulong param_4,
          FuncDef588 *param_5)

{
  JKRDecompCommand *this_00;
  
  this_00 = (JKRDecompCommand *)JKernel::operator_new(0x4c,JKRHeap::sSystemHeap,0xfffffffc);
  if (this_00 != (JKRDecompCommand *)0x0) {
    JKRDecompCommand::JKRDecompCommand(this_00);
  }
  *(JKRDecomp **)(this_00 + 4) = this;
  *(uchar **)(this_00 + 8) = param_1;
  *(uchar **)(this_00 + 0xc) = param_2;
  *(ulong *)(this_00 + 0x10) = param_3;
  *(ulong *)(this_00 + 0x14) = param_4;
  return this_00;
}


/* __thiscall JKRDecomp::sendCommand(JKRDecompCommand *) */

void __thiscall JKRDecomp::sendCommand(JKRDecomp *this,JKRDecompCommand *param_1)

{
  os::OSSendMessage(&sMessageQueue,this,1);
  return;
}


/* __thiscall JKRDecomp::orderAsync(unsigned char *,
                                    unsigned char *,
                                    unsigned long,
                                    unsigned long,
                                    void *(unsigned long)) */

JKRDecomp * __thiscall
JKRDecomp::orderAsync
          (JKRDecomp *this,uchar *param_1,uchar *param_2,ulong param_3,ulong param_4,
          FuncDef589 *param_5)

{
  JKRDecomp *this_00;
  undefined8 uVar1;
  
  uVar1 = prepareCommand(this,param_1,param_2,param_3,param_4,(FuncDef588 *)param_5);
  this_00 = (JKRDecomp *)((ulonglong)uVar1 >> 0x20);
  sendCommand(this_00,(JKRDecompCommand *)uVar1);
  return this_00;
}


/* __thiscall JKRDecomp::sync(JKRDecompCommand *,
                              int) */

void __thiscall JKRDecomp::sync(JKRDecomp *this)

{
  int in_r4;
  undefined auStack8 [8];
  
  if (in_r4 == 0) {
    os::OSReceiveMessage(this + 0x28,auStack8,1);
  }
  else {
    os::OSReceiveMessage(this + 0x28,auStack8,0);
  }
  return;
}


/* __thiscall JKRDecomp::orderSync(unsigned char *,
                                   unsigned char *,
                                   unsigned long,
                                   unsigned long) */

JKRDecomp * __thiscall
JKRDecomp::orderSync(JKRDecomp *this,uchar *param_1,uchar *param_2,ulong param_3,ulong param_4)

{
  JKRDecomp *this_00;
  JKRDecomp *pJVar1;
  FuncDef589 *in_r8;
  
  this_00 = (JKRDecomp *)orderAsync(this,param_1,param_2,param_3,0,in_r8);
  pJVar1 = this_00;
  sync(this_00);
  JKRDecompCommand::_JKRDecompCommand((JKRDecompCommand *)this_00);
  return pJVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRDecomp::decode(unsigned char *,
                                unsigned char *,
                                unsigned long,
                                unsigned long) */

void __thiscall
JKRDecomp::decode(JKRDecomp *this,uchar *param_1,uchar *param_2,ulong param_3,ulong param_4)

{
  JKRDecomp__CompressionType JVar1;
  
  JVar1 = checkCompressed(this,param_1);
  if (JVar1 == Yay0Compressed) {
    decodeSZP(this,param_1,param_2,param_3,param_4);
  }
  else {
    if (JVar1 == Yaz0Compressed) {
      decodeSZS(this,param_1,param_2,param_3,param_4);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JKRDecomp::decodeSZP(unsigned char *,
                                   unsigned char *,
                                   unsigned long,
                                   unsigned long) */

void __thiscall
JKRDecomp::decodeSZP(JKRDecomp *this,uchar *param_1,uchar *param_2,ulong param_3,ulong param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  JKRDecomp *pJVar6;
  JKRDecomp *pJVar7;
  int iVar8;
  int iVar9;
  ushort *puVar10;
  uchar *puVar11;
  JKRDecomp *pJVar12;
  
  uVar1 = (uint)(byte)this[7] |
          (uint)(byte)this[6] << 8 | (uint)(byte)this[4] << 0x18 | (uint)(byte)this[5] << 0x10;
  uVar4 = (uint)(byte)this[0xb] |
          (uint)(byte)this[10] << 8 | (uint)(byte)this[8] << 0x18 | (uint)(byte)this[9] << 0x10;
  iVar3 = 0;
  iVar5 = 0;
  iVar2 = 0x10;
  if ((param_2 != (uchar *)0x0) && (param_3 <= uVar1)) {
    pJVar7 = this + ((uint)(byte)this[0xf] |
                    (uint)(byte)this[0xe] << 8 |
                    (uint)(byte)this[0xc] << 0x18 | (uint)(byte)this[0xd] << 0x10);
    pJVar12 = (JKRDecomp *)param_1;
    do {
      if (iVar5 == 0) {
        pJVar6 = this + iVar2;
        register0x00000004 =
             (BADSPACEBASE *)
             ((uint)(byte)pJVar6[3] |
             (uint)(byte)pJVar6[2] << 8 |
             (uint)(byte)*pJVar6 << 0x18 | (uint)(byte)pJVar6[1] << 0x10);
        iVar5 = 0x20;
        iVar2 = iVar2 + 4;
      }
      if (((uint)register0x00000004 & 0x80000000) == 0) {
        puVar10 = (ushort *)(this + uVar4);
        iVar8 = iVar3 - ((*(byte *)puVar10 & 0xf) << 8 | (uint)*(byte *)((int)puVar10 + 1));
        uVar4 = uVar4 + 2;
        if ((int)(uint)*puVar10 >> 0xc == 0) {
          iVar9 = (byte)*pJVar7 + 0x12;
          pJVar7 = pJVar7 + 1;
        }
        else {
          iVar9 = ((int)(uint)*puVar10 >> 0xc) + 2;
        }
        if ((int)(uVar1 - iVar3) < iVar9) {
          iVar9 = uVar1 - iVar3;
        }
        puVar11 = param_1 + iVar3;
        if (0 < iVar9) {
          do {
            if (param_3 == 0) {
              *puVar11 = param_1[iVar8 + -1];
              param_2 = param_2 + -1;
              if (param_2 == (uchar *)0x0) {
                return;
              }
            }
            else {
              param_3 = param_3 - 1;
            }
            iVar3 = iVar3 + 1;
            pJVar12 = pJVar12 + 1;
            puVar11 = puVar11 + 1;
            iVar8 = iVar8 + 1;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
      }
      else {
        if (param_3 == 0) {
          *pJVar12 = *pJVar7;
          param_2 = param_2 + -1;
          if (param_2 == (uchar *)0x0) {
            return;
          }
        }
        else {
          param_3 = param_3 - 1;
        }
        iVar3 = iVar3 + 1;
        pJVar12 = pJVar12 + 1;
        pJVar7 = pJVar7 + 1;
      }
      register0x00000004 = (BADSPACEBASE *)((int)register0x00000004 << 1);
      iVar5 = iVar5 + -1;
    } while (iVar3 < (int)uVar1);
  }
  return;
}


/* __thiscall JKRDecomp::decodeSZS(unsigned char *,
                                   unsigned char *,
                                   unsigned long,
                                   unsigned long) */

void __thiscall
JKRDecomp::decodeSZS(JKRDecomp *this,uchar *param_1,uchar *param_2,ulong param_3,ulong param_4)

{
  int iVar1;
  JKRDecomp *pJVar2;
  int iVar3;
  int iVar4;
  uint in_r10;
  JKRDecomp *pJVar5;
  JKRDecomp *pJVar6;
  
  iVar4 = 0;
  pJVar2 = (JKRDecomp *)(param_1 + (*(int *)(this + 4) - param_3));
  if (param_2 == (uchar *)0x0) {
    return;
  }
  if (*(uint *)this < param_3) {
    return;
  }
  pJVar5 = this + 0x10;
  do {
    pJVar6 = pJVar5;
    if (iVar4 == 0) {
      in_r10 = (uint)(byte)*pJVar5;
      iVar4 = 8;
      pJVar6 = pJVar5 + 1;
    }
    if ((in_r10 & 0x80) == 0) {
      iVar1 = (int)(uint)(byte)*pJVar6 >> 4;
      iVar3 = (int)param_1 - (((byte)*pJVar6 & 0xf) << 8 | (uint)(byte)pJVar6[1]);
      pJVar5 = pJVar6 + 2;
      if (iVar1 == 0) {
        iVar1 = (byte)*pJVar5 + 0x12;
        pJVar5 = pJVar6 + 3;
      }
      else {
        iVar1 = iVar1 + 2;
      }
      do {
        if (param_3 == 0) {
          *param_1 = (uchar)*(JKRDecomp *)(iVar3 + -1);
          param_2 = param_2 + -1;
          param_1 = (uchar *)((JKRDecomp *)param_1 + 1);
          if (param_2 == (uchar *)0x0) {
            return;
          }
        }
        else {
          param_3 = param_3 - 1;
        }
        iVar1 = iVar1 + -1;
        iVar3 = iVar3 + 1;
      } while (iVar1 != 0);
    }
    else {
      if (param_3 == 0) {
        *param_1 = (uchar)*pJVar6;
        param_2 = param_2 + -1;
        param_1 = (uchar *)((JKRDecomp *)param_1 + 1);
        if (param_2 == (uchar *)0x0) {
          return;
        }
      }
      else {
        param_3 = param_3 - 1;
      }
      pJVar5 = pJVar6 + 1;
    }
    in_r10 = in_r10 << 1;
    iVar4 = iVar4 + -1;
  } while ((JKRDecomp *)param_1 != pJVar2);
  return;
}


/* __thiscall JKRDecomp::checkCompressed(unsigned char *) */

JKRDecomp__CompressionType __thiscall JKRDecomp::checkCompressed(JKRDecomp *this,uchar *param_1)

{
  if (((*this == (JKRDecomp)0x59) && (this[1] == (JKRDecomp)0x61)) && (this[3] == (JKRDecomp)0x30))
  {
    if (this[2] == (JKRDecomp)0x79) {
      return Yay0Compressed;
    }
    if (this[2] == (JKRDecomp)0x7a) {
      return Yaz0Compressed;
    }
  }
  return NotCompressed;
}


/* __thiscall JKRDecompCommand::JKRDecompCommand(void) */

void __thiscall JKRDecompCommand::JKRDecompCommand(JKRDecompCommand *this)

{
  os::OSInitMessageQueue((OSMessageQueue *)(this + 0x28),(OSMessage *)(this + 0x48),1);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(JKRDecompCommand **)(this + 0x18) = this;
  *(undefined4 *)(this + 0x20) = 0;
  return;
}


/* __thiscall JKRDecompCommand::~JKRDecompCommand(void) */

void __thiscall JKRDecompCommand::_JKRDecompCommand(JKRDecompCommand *this)

{
  short in_r4;
  
  if ((this != (JKRDecompCommand *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

