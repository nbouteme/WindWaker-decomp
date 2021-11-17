#include <JUtility/JUTException.h>
#include <JKernel/JKRThread.h>
#include <JUtility/JUTException.h>
#include <os/OSError.h>
#include <JKernel/JKRHeap.h>
#include <os/OSThread.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <base/PPCArch.h>
#include <os/OSMessage.h>
#include <os/OSInterrupt.h>
#include <m_Do_printf.h>
#include <os/OSContext.h>
#include <os/OSMemory.h>
#include <JUtility/JUTConsole.h>
#include <os/OSTime.h>
#include <JUtility/JUTGamePad.h>
#include <vi/vi.h>
#include <os/OSArena.h>
#include <JUtility/JUTDirectPrint.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JSupport/JSUList.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <JUtility/JUTDirectFile.h>
#include <MSL_C.PPCEABI.bare.H/strtoul.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JUTException.h>
#include <JSUList<JUTException::JUTExMapFile>.h>
#include <JUTExternalFB.h>


namespace JUtility {
undefined4 exCallbackObject;
}
undefined1 JUTException;
struct JUTException * JUTException;
undefined1 JUTException;
undefined1 JUTException;
undefined1 JUTException;
undefined1 JUTException;
undefined1 JUTException;
undefined1 JUTException;
undefined1 JUTException;

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTException::JUTException(JUTDirectPrint *) */

void __thiscall JUTException::JUTException(JUTException *this,JUTDirectPrint *param_1)

{
  ulong extraout_r4;
  
  JKRThread::JKRThread((JKRThread *)this,0x4000,0x10,0);
  *(undefined1 **)this = &__vt;
  *(JUTDirectPrint **)(this + 0x6c) = param_1;
  os::OSSetErrorHandler(2,errorHandler);
  os::OSSetErrorHandler(3,errorHandler);
  os::OSSetErrorHandler(6,errorHandler);
  os::OSSetErrorHandler(5,errorHandler);
  os::OSSetErrorHandler(0xf,errorHandler);
  setFPException((JUTException *)0x0,extraout_r4);
  _sPreUserCallback = 0;
  _sPostUserCallback = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x74) = 0xffffffff;
  *(undefined4 *)(this + 0x78) = 10;
  *(undefined4 *)(this + 0x7c) = 10;
  *(undefined4 *)(this + 0x80) = 0xffffffff;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x88) = 0x1f;
  return;
}


namespace JUTException {

/* __thiscall create(JUTDirectPrint *) */

JUTException * create(JUTDirectPrint *param_1)

{
  JUTException *this;
  
  if (sErrorManager == (JUTException *)0x0) {
    this = (JUTException *)JKernel::operator_new(0x8c,JKRHeap::sSystemHeap,0);
    if (this != (JUTException *)0x0) {
      JUTException(this,param_1);
    }
    sErrorManager = this;
    os::OSResumeThread(*(OSThread **)(this + 0x2c));
  }
  return sErrorManager;
}

}

/* WARNING: Inlined function: FUN_80328f30 */
/* __thiscall JUTException::run(void) */

void __thiscall JUTException::run(JUTException *this)

{
  ushort uVar1;
  uint uVar2;
  code *pcVar3;
  code *pcVar4;
  OSContext *pOVar5;
  code *pcVar6;
  code **local_28 [3];
  
  uVar2 = base::PPCMfmsr();
  base::PPCMtmsr(uVar2 & 0xfffff6ff);
  os::OSInitMessageQueue((OSMessageQueue *)&sMessageQueue,(OSMessage *)&sMessageBuffer,1);
  do {
    os::OSReceiveMessage(&sMessageQueue,local_28,1);
    pcVar6 = *local_28[0];
    uVar1 = *(ushort *)(local_28[0] + 1);
    pOVar5 = (OSContext *)local_28[0][2];
    pcVar4 = local_28[0][3];
    pcVar3 = local_28[0][4];
    *(undefined4 *)(this + 0x68) = **(undefined4 **)(sErrorManager + 0x6c);
    if (**(int **)(sErrorManager + 0x6c) == 0) {
      createFB(sErrorManager);
    }
    if (pcVar6 != (code *)0x0) {
      (*pcVar6)(uVar1,pOVar5,pcVar4,pcVar3);
    }
    os::OSDisableInterrupts();
    printContext(sErrorManager,uVar1,pOVar5,(ulong)pcVar4,(ulong)pcVar3);
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTException::errorHandler(unsigned short,
                                         OSContext *,
                                         unsigned long,
                                         unsigned long) */

void __thiscall
JUTException::errorHandler
          (JUTException *this,ushort param_1,OSContext *param_2,ulong param_3,ulong param_4)

{
  char cVar1;
  undefined2 in_register_00000010;
  int iVar2;
  ulong *in_r8;
  uint uVar3;
  ulong local_48;
  ulong local_44;
  undefined auStack64 [4];
  ulong local_3c;
  undefined auStack56 [40];
  
  iVar2 = CONCAT22(in_register_00000010,param_1);
  if (((uint)this & 0xffff) == 0x10) {
    m_Do_printf::OSReport("\x1b[41;37m");
    m_Do_printf::OSReport
              (" FPE: 浮動小数点例外が発生しました。アドレスは %08x fpscr=%08x\n"
               ,*(undefined4 *)(iVar2 + 0x198),*(undefined4 *)(iVar2 + 0x194));
    cVar1 = searchPartialModule(*(JUTException **)(iVar2 + 0x198),(ulong)auStack64,&local_44,
                                &local_48,&local_3c,in_r8);
    if (cVar1 == '\x01') {
      JUtility::search_name_part(local_3c,auStack56,0x20);
      m_Do_printf::OSReport("%s:%x section:%d\n",auStack56,local_48,local_44);
    }
    uVar3 = *(uint *)(iVar2 + 0x194) & (*(uint *)(iVar2 + 0x194) & 0xf8) << 0x16;
    if ((uVar3 & 0x20000000) != 0) {
      *(uint *)(iVar2 + 0x194) = *(uint *)(iVar2 + 0x194) & 0xffffff7f;
      m_Do_printf::OSReport(" FPE: Invalid operation(無効な演算)\n");
      if ((_fpscr & 0x1000000) != 0) {
        m_Do_printf::OSReport(" SNaN\n");
      }
      if ((_fpscr & 0x800000) != 0) {
        m_Do_printf::OSReport(" Infinity - Infinity\n");
      }
      if ((_fpscr & 0x400000) != 0) {
        m_Do_printf::OSReport(" Infinity / Infinity\n");
      }
      if ((_fpscr & 0x200000) != 0) {
        m_Do_printf::OSReport(" 0 / 0\n");
      }
      if ((_fpscr & 0x100000) != 0) {
        m_Do_printf::OSReport(" Infinity * 0\n");
      }
      if ((_fpscr & 0x80000) != 0) {
        m_Do_printf::OSReport(" Invalid compare\n");
      }
      if ((_fpscr & 0x400) != 0) {
        m_Do_printf::OSReport(" Software request\n");
      }
      if ((_fpscr & 0x200) != 0) {
        m_Do_printf::OSReport(" Invalid square root\n");
      }
      if ((_fpscr & 0x100) != 0) {
        m_Do_printf::OSReport(" Invalid integer convert\n");
      }
    }
    if ((uVar3 & 0x10000000) != 0) {
      *(uint *)(iVar2 + 0x194) = *(uint *)(iVar2 + 0x194) & 0xffffffbf;
      m_Do_printf::OSReport(" FPE: Overflow(オーバーフロー)\n");
    }
    if ((uVar3 & 0x8000000) != 0) {
      *(uint *)(iVar2 + 0x194) = *(uint *)(iVar2 + 0x194) & 0xffffffdf;
      m_Do_printf::OSReport(" FPE: Underflow(アンダーフロー)\n");
    }
    if ((uVar3 & 0x4000000) != 0) {
      *(uint *)(iVar2 + 0x194) = *(uint *)(iVar2 + 0x194) & 0xffffffef;
      m_Do_printf::OSReport(" FPE: Zero division(０による割り算)\n");
    }
    if ((uVar3 & 0x2000000) != 0) {
      *(uint *)(iVar2 + 0x194) = *(uint *)(iVar2 + 0x194) & 0xfffffff7;
      m_Do_printf::OSReport(" FPE: Inexact result(不正確な結果)\n");
    }
    m_Do_printf::OSReport("\x1b[m");
  }
  else {
    _msr = base::PPCMfmsr();
    _fpscr = *(uint *)(iVar2 + 0x194);
    os::OSFillFPUContext(iVar2);
    os::OSSetErrorHandler(this,0);
    if (((uint)this & 0xffff) == 0xf) {
      os::OSProtectRange(0,0,0,3);
      os::OSProtectRange(1,0,0,3);
      os::OSProtectRange(2,0,0,3);
      os::OSProtectRange(3,0,0,3);
    }
    JUtility::exCallbackObject = _sPreUserCallback;
    DAT_803ed98c = SUB42(this,0);
    DAT_803ed990 = iVar2;
    DAT_803ed994 = param_2;
    DAT_803ed998 = param_3;
    os::OSSendMessage(&sMessageQueue,&JUtility::exCallbackObject,1);
    os::OSEnableScheduler();
    os::OSYieldThread();
  }
  return;
}


/* __thiscall JUTException::setFPException(unsigned long) */

void __thiscall JUTException::setFPException(JUTException *this,ulong param_1)

{
  os::__OSFpscrEnableBits = this;
  if (this == (JUTException *)0x0) {
    os::OSSetErrorHandler(0x10,0);
  }
  else {
    os::OSSetErrorHandler(0x10,errorHandler);
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTException::showFloatSub(int,
                                         float) */

void __thiscall JUTException::showFloatSub(JUTException *this,int param_1,float param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)param_2 & 0x7f800000;
  if (uVar1 == 0x7f800000) {
    if (((uint)param_2 & 0x7fffff) == 0) {
      iVar2 = 2;
    }
    else {
      iVar2 = 1;
    }
  }
  else {
    if ((uVar1 < 0x7f800000) && (uVar1 == 0)) {
      if (((uint)param_2 & 0x7fffff) == 0) {
        iVar2 = 3;
      }
      else {
        iVar2 = 5;
      }
    }
    else {
      iVar2 = 4;
    }
  }
  if (iVar2 == 1) {
    JUTConsole::print_f(_sConsole,"F%02d: Nan      ",param_1);
  }
  else {
    uVar1 = (uint)param_2 & 0x7f800000;
    if (uVar1 == 0x7f800000) {
      if (((uint)param_2 & 0x7fffff) == 0) {
        iVar2 = 2;
      }
      else {
        iVar2 = 1;
      }
    }
    else {
      if ((uVar1 < 0x7f800000) && (uVar1 == 0)) {
        if (((uint)param_2 & 0x7fffff) == 0) {
          iVar2 = 3;
        }
        else {
          iVar2 = 5;
        }
      }
      else {
        iVar2 = 4;
      }
    }
    if (iVar2 == 2) {
      if (((uint)param_2 & 0x80000000) == 0) {
        JUTConsole::print_f(_sConsole,"F%02d:-Inf     ",param_1);
      }
      else {
        JUTConsole::print_f(_sConsole,"F%02d:+Inf     ",param_1);
      }
    }
    else {
      if (JUtility::_2258 == param_2) {
        JUTConsole::print_f(_sConsole,"F%02d: 0.0      ",param_1);
      }
      else {
        JUTConsole::print_f(_sConsole,"F%02d:%+.3E",param_1);
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTException::showFloat(OSContext *) */

void __thiscall JUTException::showFloat(JUTException *this,OSContext *param_1)

{
  int iVar1;
  OSContext *pOVar2;
  int iVar3;
  
  if (_sConsole != (JUTConsole *)0x0) {
    JUTConsole::print(_sConsole,"-------------------------------- FPR\n");
    iVar1 = 0;
    iVar3 = 0;
    do {
      pOVar2 = param_1 + iVar3;
      showFloatSub(this,iVar1,(float)*(double *)(pOVar2 + 0x90));
      JUTConsole::print(_sConsole," ");
      showFloatSub(this,iVar1 + 0xb,(float)*(double *)(pOVar2 + 0xe8));
      JUTConsole::print(_sConsole," ");
      showFloatSub(this,iVar1 + 0x16,(float)*(double *)(pOVar2 + 0x140));
      JUTConsole::print(_sConsole,"\n");
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 8;
    } while (iVar1 < 10);
    showFloatSub(this,10,(float)*(double *)(param_1 + 0xe0));
    JUTConsole::print(_sConsole," ");
    showFloatSub(this,0x15,(float)*(double *)(param_1 + 0x138));
    JUTConsole::print(_sConsole,"\n");
  }
  return;
}


/* __thiscall JUTException::searchPartialModule(unsigned long,
                                                unsigned long *,
                                                unsigned long *,
                                                unsigned long *,
                                                unsigned long *) */

undefined4 __thiscall
JUTException::searchPartialModule
          (JUTException *this,ulong param_1,ulong *param_2,ulong *param_3,ulong *param_4,
          ulong *param_5)

{
  JUTException *pJVar1;
  int iVar2;
  undefined4 *puVar3;
  uint *puVar4;
  ulong uVar5;
  
  puVar3 = DAT_800030c8;
  if (this == (JUTException *)0x0) {
    return 0;
  }
  do {
    if (puVar3 == (undefined4 *)0x0) {
      return 0;
    }
    puVar4 = (uint *)puVar3[4];
    uVar5 = 0;
    for (iVar2 = puVar3[3]; iVar2 != 0; iVar2 = iVar2 + -1) {
      if (((puVar4[1] != 0) && (pJVar1 = (JUTException *)(*puVar4 & 0xfffffffe), pJVar1 <= this)) &&
         (this < pJVar1 + puVar4[1])) {
        if (param_1 != 0) {
          *(undefined4 *)param_1 = *puVar3;
        }
        if (param_2 != (ulong *)0x0) {
          *param_2 = uVar5;
        }
        if (param_3 != (ulong *)0x0) {
          *param_3 = (int)this - (int)pJVar1;
        }
        if (param_4 != (ulong *)0x0) {
          *param_4 = puVar3[5];
        }
        return 1;
      }
      puVar4 = puVar4 + 2;
      uVar5 = uVar5 + 1;
    }
    puVar3 = (undefined4 *)puVar3[1];
  } while( true );
}


namespace JUtility {

/* __stdcall search_name_part(unsigned char *,
                              unsigned char *,
                              int) */

void search_name_part(char *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  
  for (pcVar1 = param_1; *pcVar1 != '\0'; pcVar1 = pcVar1 + 1) {
    if (*pcVar1 == '\\') {
      param_1 = pcVar1;
    }
  }
  if (*param_1 == '\\') {
    param_1 = param_1 + 1;
  }
  iVar2 = 0;
  for (; ((*param_1 != '\0' && (iVar2 < param_3)) && (*param_1 != '.')); param_1 = param_1 + 1) {
    *param_2 = *param_1;
    param_2 = param_2 + 1;
    iVar2 = iVar2 + 1;
  }
  *param_2 = '\0';
  return;
}

}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTException::showStack(OSContext *) */

void __thiscall JUTException::showStack(JUTException *this,OSContext *param_1)

{
  bool bVar1;
  ___ in_r5;
  undefined4 *puVar2;
  uint uVar3;
  
  if (_sConsole != (JUTConsole *)0x0) {
    JUTConsole::print(_sConsole,"-------------------------------- TRACE\n");
    JUTConsole::print_f(_sConsole,"Address:   BackChain   LR save\n",in_r5);
    uVar3 = 0;
    puVar2 = *(undefined4 **)(param_1 + 4);
    while( true ) {
      if (puVar2 == (undefined4 *)0x0) {
        return;
      }
      if (puVar2 == (undefined4 *)&DAT_ffffffff) {
        return;
      }
      bVar1 = 0xf < uVar3;
      uVar3 = uVar3 + 1;
      if (bVar1) {
        return;
      }
      if (*(uint *)(this + 0x80) < uVar3) break;
      JUTConsole::print_f(_sConsole,"%08X:  %08X    %08X\n",(___)puVar2);
      showMapInfo_subroutine(this,puVar2[1],false);
      JUTConsoleManager::drawDirect(JUTConsoleManager::sManager,true);
      waitTime(*(long *)(this + 0x7c));
      puVar2 = (undefined4 *)*puVar2;
    }
    JUTConsole::print(_sConsole,"Suppress trace.\n");
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTException::showMainInfo(unsigned short,
                                         OSContext *,
                                         unsigned long,
                                         unsigned long) */

void __thiscall
JUTException::showMainInfo
          (JUTException *this,ushort param_1,OSContext *param_2,ulong param_3,ulong param_4)

{
  OSContext *pOVar1;
  uint uVar2;
  
  if (_sConsole != (JUTConsole *)0x0) {
    pOVar1 = param_2;
    JUTConsole::print_f(_sConsole,"CONTEXT:%08XH  (%s EXCEPTION)\n",(___)param_2);
    if (param_1 == 0x10) {
      uVar2 = _fpscr & (_fpscr & 0xf8) << 0x16;
      if ((uVar2 & 0x20000000) != 0) {
        JUTConsole::print_f(_sConsole," FPE: Invalid operation\n",(___)pOVar1);
        if ((_fpscr & 0x1000000) != 0) {
          JUTConsole::print_f(_sConsole," SNaN\n",(___)pOVar1);
        }
        if ((_fpscr & 0x800000) != 0) {
          JUTConsole::print_f(_sConsole," Infinity - Infinity\n",(___)pOVar1);
        }
        if ((_fpscr & 0x400000) != 0) {
          JUTConsole::print_f(_sConsole," Infinity / Infinity\n",(___)pOVar1);
        }
        if ((_fpscr & 0x200000) != 0) {
          JUTConsole::print_f(_sConsole," 0 / 0\n",(___)pOVar1);
        }
        if ((_fpscr & 0x100000) != 0) {
          JUTConsole::print_f(_sConsole," Infinity * 0\n",(___)pOVar1);
        }
        if ((_fpscr & 0x80000) != 0) {
          JUTConsole::print_f(_sConsole," Invalid compare\n",(___)pOVar1);
        }
        if ((_fpscr & 0x400) != 0) {
          JUTConsole::print_f(_sConsole," Software request\n",(___)pOVar1);
        }
        if ((_fpscr & 0x200) != 0) {
          JUTConsole::print_f(_sConsole," Invalid square root\n",(___)pOVar1);
        }
        if ((_fpscr & 0x100) != 0) {
          JUTConsole::print_f(_sConsole," Invalid integer convert\n",(___)pOVar1);
        }
      }
      if ((uVar2 & 0x10000000) != 0) {
        JUTConsole::print_f(_sConsole," FPE: Overflow\n",(___)pOVar1);
      }
      if ((uVar2 & 0x8000000) != 0) {
        JUTConsole::print_f(_sConsole," FPE: Underflow\n",(___)pOVar1);
      }
      if ((uVar2 & 0x4000000) != 0) {
        JUTConsole::print_f(_sConsole," FPE: Zero division\n",(___)pOVar1);
      }
      if ((uVar2 & 0x2000000) != 0) {
        JUTConsole::print_f(_sConsole," FPE: Inexact result\n",(___)pOVar1);
      }
    }
    JUTConsole::print_f(_sConsole,"SRR0:   %08XH   SRR1:%08XH\n",*(___ *)(param_2 + 0x198));
    JUTConsole::print_f(_sConsole,"DSISR:  %08XH   DAR: %08XH\n",param_3);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTException::showGPR(OSContext *) */

void __thiscall JUTException::showGPR(JUTException *this,OSContext *param_1)

{
  ___ _Var1;
  
  if (_sConsole != (JUTConsole *)0x0) {
    JUTConsole::print(_sConsole,"-------------------------------- GPR\n");
    _Var1 = 0;
    do {
      JUTConsole::print_f(_sConsole,"R%02d:%08XH  R%02d:%08XH  R%02d:%08XH\n",_Var1);
      _Var1 = _Var1 + 1;
    } while ((int)_Var1 < 10);
    JUTConsole::print_f(_sConsole,"R%02d:%08XH  R%02d:%08XH\n",10);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTException::showMapInfo_subroutine(unsigned long,
                                                   bool) */

undefined4 __thiscall
JUTException::showMapInfo_subroutine(JUTException *this,ulong param_1,bool param_2)

{
  char cVar1;
  ulong *in_r8;
  undefined *puVar2;
  undefined in_stack_fffffeaf;
  ulong uStack336;
  undefined auStack332 [4];
  char *local_148;
  ulong local_144;
  undefined auStack320 [4];
  ulong local_13c;
  JUTException aJStack312 [36];
  ulong auStack276 [65];
  
  if ((param_1 < 0x80000000) || (0x82ffffff < param_1)) {
    return 0;
  }
  puVar2 = &DAT_8036c395;
  if (param_2 == false) {
    puVar2 = &DAT_8036c528;
  }
  cVar1 = searchPartialModule((JUTException *)param_1,(ulong)auStack320,&local_144,
                              (ulong *)&local_148,&local_13c,in_r8);
  if (cVar1 == '\x01') {
    JUtility::search_name_part(local_13c,aJStack312,0x20);
    JUTConsole::print_f(_sConsole,"%s %s:%x section:%d\n",(___)puVar2);
    param_2 = false;
  }
  if (_sMapFileList != 0) {
    if (cVar1 == '\x01') {
      cVar1 = queryMapAddress(aJStack312,local_148,local_144,(long)auStack332,&uStack336,auStack276,
                              (char *)0x100,1,param_2,(bool)in_stack_fffffeaf);
    }
    else {
      cVar1 = queryMapAddress((JUTException *)0x0,(char *)param_1,0xffffffff,(long)auStack332,
                              &uStack336,auStack276,(char *)0x100,1,param_2,(bool)in_stack_fffffeaf)
      ;
    }
    if (cVar1 == '\x01') {
      return 1;
    }
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTException::showGPRMap(OSContext *) */

void __thiscall JUTException::showGPRMap(JUTException *this,OSContext *param_1)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  ___ _Var4;
  int iVar5;
  
  if (_sConsole != (JUTConsole *)0x0) {
    bVar1 = false;
    JUTConsole::print(_sConsole,"-------------------------------- GPRMAP\n");
    _Var4 = 0;
    iVar5 = 0;
    do {
      uVar3 = *(uint *)(param_1 + iVar5);
      if ((0x7fffffff < uVar3) && (uVar3 < 0x83000000)) {
        bVar1 = true;
        JUTConsole::print_f(_sConsole,"R%02d: %08XH",_Var4);
        cVar2 = showMapInfo_subroutine(this,uVar3,true);
        if (cVar2 == '\0') {
          JUTConsole::print(_sConsole,"  no information\n");
        }
        JUTConsoleManager::drawDirect(JUTConsoleManager::sManager,true);
        waitTime(*(long *)(this + 0x7c));
      }
      _Var4 = _Var4 + 1;
      iVar5 = iVar5 + 4;
    } while ((int)_Var4 < 0x1f);
    if (!bVar1) {
      JUTConsole::print(_sConsole,"  no register which seem to address.\n");
    }
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTException::showSRR0Map(OSContext *) */

void __thiscall JUTException::showSRR0Map(JUTException *this,OSContext *param_1)

{
  char cVar1;
  uint uVar2;
  
  if (_sConsole != (JUTConsole *)0x0) {
    JUTConsole::print(_sConsole,"-------------------------------- SRR0MAP\n");
    uVar2 = *(uint *)(param_1 + 0x198);
    if ((0x7fffffff < uVar2) && (uVar2 < 0x83000000)) {
      JUTConsole::print_f(_sConsole,"SRR0: %08XH",uVar2);
      cVar1 = showMapInfo_subroutine(this,uVar2,true);
      if (cVar1 == '\0') {
        JUTConsole::print(_sConsole,"  no information\n");
      }
      JUTConsoleManager::drawDirect(JUTConsoleManager::sManager,true);
    }
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTException::printDebugInfo(JUTException::EInfoPage,
                                           unsigned short,
                                           OSContext *,
                                           unsigned long,
                                           unsigned long) */

void __thiscall
JUTException::printDebugInfo
          (JUTException *this,EInfoPage param_1,ushort param_2,OSContext *param_3,ulong param_4,
          ulong param_5)

{
  if (param_1 == 3) {
    showStack(this,param_3);
  }
  else {
    if ((int)param_1 < 3) {
      if (param_1 == 1) {
        showGPR(this,param_3);
      }
      else {
        if ((0 < (int)param_1) && (showFloat(this,param_3), _sConsole != (JUTConsole *)0x0)) {
          JUTConsole::print_f(_sConsole," MSR:%08XH\t FPSCR:%08XH\n",_msr);
        }
      }
    }
    else {
      if (param_1 == 5) {
        showSRR0Map(this,param_3);
      }
      else {
        if ((int)param_1 < 5) {
          showGPRMap(this,param_3);
        }
      }
    }
  }
  return;
}


/* __thiscall JUTException::isEnablePad(void) const */

bool __thiscall JUTException::isEnablePad(JUTException *this)

{
  if (*(int *)(this + 0x70) == -1) {
    return true;
  }
  if (-1 < *(int *)(this + 0x74)) {
    return true;
  }
  return *(int *)(this + 0x70) != 0;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* __thiscall JUTException::readPad(unsigned long *,
                                    unsigned long *) */

undefined4 __thiscall JUTException::readPad(JUTException *this,ulong *param_1,ulong *param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  JUTGamePad *pJVar4;
  ulong *puVar5;
  ulong *puVar6;
  long_long extraout_r4;
  long_long extraout_r4_00;
  long_long extraout_r4_01;
  uint uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined auStack888 [168];
  undefined auStack720 [168];
  undefined auStack552 [168];
  undefined auStack384 [168];
  undefined auStack216 [176];
  
  uVar8 = 0;
  puVar5 = param_1;
  iVar2 = os::OSGetTime();
  puVar6 = puVar5;
  do {
    iVar3 = os::OSGetTime();
    uVar9 = Runtime.PPCEABI.H::__div2i
                      (iVar3 - ((uint)(puVar6 < puVar5) + iVar2),(int)puVar6 - (int)puVar5,0,
                       (DAT_800000f8 >> 2) / 1000);
    puVar6 = (ulong *)uVar9;
  } while (((uint)((ulonglong)uVar9 >> 0x20) ^ 0x80000000) < (puVar6 < (ulong *)0x32) + 0x80000000);
  pJVar4 = *(JUTGamePad **)(this + 0x70);
  if (pJVar4 == (JUTGamePad *)&DAT_ffffffff) {
    JUTGamePad::JUTGamePad((JUTGamePad *)auStack216,0);
    JUTGamePad::JUTGamePad((JUTGamePad *)auStack384,1);
    JUTGamePad::JUTGamePad((JUTGamePad *)auStack552,2);
    pJVar4 = (JUTGamePad *)auStack720;
    JUTGamePad::JUTGamePad(pJVar4,3);
    JUTGamePad::read(pJVar4);
    bVar1 = false;
    if ((auStack216._120_2_ != -1) && (auStack216[152] != '\0')) {
      bVar1 = true;
    }
    if (bVar1) {
      if ((DAT_8039d23c | JUtility::c3bcnt) == 0) {
        JUtility::c3bcnt = os::OSGetTime();
      }
    }
    else {
      DAT_8039d23c = 0;
      JUtility::c3bcnt = 0;
    }
    bVar1 = false;
    if ((auStack384._120_2_ != -1) && (auStack384[152] != '\0')) {
      bVar1 = true;
    }
    if (bVar1) {
      if ((DAT_8039d244 | DAT_8039d240) == 0) {
        DAT_8039d240 = os::OSGetTime();
      }
    }
    else {
      DAT_8039d244 = 0;
      DAT_8039d240 = 0;
    }
    bVar1 = false;
    if ((auStack552._120_2_ != -1) && (auStack552[152] != '\0')) {
      bVar1 = true;
    }
    if (bVar1) {
      if ((DAT_8039d24c | DAT_8039d248) == 0) {
        DAT_8039d248 = os::OSGetTime();
      }
    }
    else {
      DAT_8039d24c = 0;
      DAT_8039d248 = 0;
    }
    bVar1 = false;
    if ((auStack720._120_2_ != -1) && (auStack720[152] != '\0')) {
      bVar1 = true;
    }
    if (bVar1) {
      uVar7 = DAT_8039d254;
      if ((DAT_8039d254 | DAT_8039d250) == 0) {
        DAT_8039d250 = os::OSGetTime();
        uVar7 = DAT_8039d254;
      }
    }
    else {
      DAT_8039d250 = 0;
      uVar7 = 0;
    }
    DAT_8039d254 = uVar7;
    if ((DAT_8039d23c | JUtility::c3bcnt) != 0) {
      os::OSGetTime();
    }
    if ((DAT_8039d244 | DAT_8039d240) != 0) {
      os::OSGetTime();
    }
    if ((DAT_8039d24c | DAT_8039d248) != 0) {
      os::OSGetTime();
    }
    if ((DAT_8039d254 | DAT_8039d250) != 0) {
      os::OSGetTime();
    }
    JUTGamePad::checkResetCallback((JUTGamePad *)auStack216,uVar7);
    JUTGamePad::checkResetCallback((JUTGamePad *)auStack384,extraout_r4);
    JUTGamePad::checkResetCallback((JUTGamePad *)auStack552,extraout_r4_00);
    JUTGamePad::checkResetCallback((JUTGamePad *)auStack720,extraout_r4_01);
    if (param_1 != (ulong *)0x0) {
      *param_1 = auStack720._28_4_ | auStack552._28_4_ | auStack216._28_4_ | auStack384._28_4_;
    }
    if (param_2 != (ulong *)0x0) {
      *param_2 = auStack720._24_4_ | auStack552._24_4_ | auStack216._24_4_ | auStack384._24_4_;
    }
    uVar8 = 1;
    JUTGamePad::_JUTGamePad((JUTGamePad *)auStack720);
    JUTGamePad::_JUTGamePad((JUTGamePad *)auStack552);
    JUTGamePad::_JUTGamePad((JUTGamePad *)auStack384);
    JUTGamePad::_JUTGamePad((JUTGamePad *)auStack216);
  }
  else {
    if ((int)*(EPadPort *)(this + 0x74) < 0) {
      if (pJVar4 != (JUTGamePad *)0x0) {
        JUTGamePad::read(pJVar4);
        if (param_1 != (ulong *)0x0) {
          *param_1 = *(ulong *)(*(int *)(this + 0x70) + 0x1c);
        }
        if (param_2 != (ulong *)0x0) {
          *param_2 = *(ulong *)(*(int *)(this + 0x70) + 0x18);
        }
        uVar8 = 1;
      }
    }
    else {
      JUTGamePad::JUTGamePad((JUTGamePad *)auStack888,*(EPadPort *)(this + 0x74));
      bVar1 = false;
      if ((auStack888._120_2_ != -1) && (auStack888[152] != '\0')) {
        bVar1 = true;
      }
      if (bVar1) {
        uVar7 = DAT_8039d23c;
        if ((DAT_8039d23c | JUtility::c3bcnt) == 0) {
          JUtility::c3bcnt = os::OSGetTime();
          uVar7 = DAT_8039d23c;
        }
      }
      else {
        JUtility::c3bcnt = 0;
        uVar7 = 0;
      }
      DAT_8039d23c = uVar7;
      if ((uVar7 | JUtility::c3bcnt) != 0) {
        os::OSGetTime();
      }
      pJVar4 = (JUTGamePad *)JUTGamePad::checkResetCallback((JUTGamePad *)auStack888,uVar7);
      JUTGamePad::read(pJVar4);
      if (param_1 != (ulong *)0x0) {
        *param_1 = auStack888._28_4_;
      }
      if (param_2 != (ulong *)0x0) {
        *param_2 = auStack888._24_4_;
      }
      uVar8 = 1;
      JUTGamePad::_JUTGamePad((JUTGamePad *)auStack888);
    }
  }
  return uVar8;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTException::printContext(unsigned short,
                                         OSContext *,
                                         unsigned long,
                                         unsigned long) */

void __thiscall
JUTException::printContext
          (JUTException *this,ushort param_1,OSContext *param_2,ulong param_3,ulong param_4)

{
  bool bVar1;
  JUTConsole *pJVar2;
  uint uVar3;
  undefined4 uVar4;
  bool bVar7;
  int iVar5;
  int iVar6;
  undefined2 in_register_00000010;
  int iVar8;
  int iVar9;
  ulong local_38;
  ulong local_34 [3];
  
  uVar3 = isEnablePad(this);
  uVar3 = countLeadingZeros(uVar3 & 0xff);
  if ((**(int **)(sErrorManager + 0x6c) == 0) || (_sConsole == (JUTConsole *)0x0)) {
    return;
  }
  JUTConsole::print_f(_sConsole,"******** EXCEPTION OCCURRED! ********\nFrameMemory:%XH\n",
                      *(___ *)(this + 0x68));
  bVar1 = false;
  while( true ) {
    showMainInfo(this,param_1,param_2,param_3,param_4);
    JUTConsoleManager::drawDirect(JUTConsoleManager::sManager,true);
    waitTime(*(long *)(this + 0x78));
    if ((*(uint *)(this + 0x88) & 1) != 0) {
      printDebugInfo(this,1,param_1,param_2,param_3,param_4);
      JUTConsoleManager::drawDirect(JUTConsoleManager::sManager,true);
      waitTime(*(long *)(this + 0x78));
    }
    if ((*(uint *)(this + 0x88) & 4) != 0) {
      printDebugInfo(this,5,param_1,param_2,param_3,param_4);
      JUTConsoleManager::drawDirect(JUTConsoleManager::sManager,true);
      waitTime(*(long *)(this + 0x78));
    }
    if ((*(uint *)(this + 0x88) & 2) != 0) {
      printDebugInfo(this,4,param_1,param_2,param_3,param_4);
      JUTConsoleManager::drawDirect(JUTConsoleManager::sManager,true);
      waitTime(*(long *)(this + 0x78));
    }
    if ((*(uint *)(this + 0x88) & 8) != 0) {
      printDebugInfo(this,2,param_1,param_2,param_3,param_4);
      JUTConsoleManager::drawDirect(JUTConsoleManager::sManager,true);
      waitTime(*(long *)(this + 0x78));
    }
    if ((*(uint *)(this + 0x88) & 0x10) != 0) {
      printDebugInfo(this,3,param_1,param_2,param_3,param_4);
      JUTConsoleManager::drawDirect(JUTConsoleManager::sManager,true);
      waitTime(*(long *)(this + 0x7c));
    }
    JUTConsole::print(_sConsole,"--------------------------------\n");
    JUTConsoleManager::drawDirect(JUTConsoleManager::sManager,true);
    if ((!bVar1) && (_sPostUserCallback != (code *)0x0)) {
      uVar4 = os::OSEnableInterrupts();
      bVar1 = true;
      (*_sPostUserCallback)(CONCAT22(in_register_00000010,param_1),param_2,param_3,param_4);
      os::OSRestoreInterrupts(uVar4);
    }
    if ((*(int *)(this + 0x84) == 0) || ((uVar3 >> 5 & 0xff) == 0)) break;
    *(uint *)(_sConsole + 0x58) = *(uint *)(_sConsole + 0x58) & 1;
  }
  if ((uVar3 >> 5 & 0xff) == 0) {
    os::OSEnableInterrupts();
    iVar8 = 0;
    iVar9 = 0;
    do {
      readPad(this,&local_38,local_34);
      bVar1 = local_38 == 0x100;
      if (bVar1) {
        JUTConsole::scroll(_sConsole,*(int *)(_sConsole + 0x24));
      }
      bVar7 = local_38 == 0x200;
      if (bVar7) {
        JUTConsole::scroll(_sConsole,-*(int *)(_sConsole + 0x24));
      }
      bVar7 = bVar7 || bVar1;
      if (local_34[0] == 8) {
        if (iVar8 < 3) {
          iVar9 = -1;
        }
        else {
          if (iVar8 < 5) {
            iVar9 = -2;
          }
          else {
            iVar9 = -8;
            if (iVar8 < 7) {
              iVar9 = -4;
            }
          }
        }
        JUTConsole::scroll(_sConsole,iVar9);
        bVar7 = true;
        iVar9 = 0;
        iVar8 = iVar8 + 1;
      }
      else {
        if (local_34[0] == 4) {
          if (iVar9 < 3) {
            iVar8 = 1;
          }
          else {
            if (iVar9 < 5) {
              iVar8 = 2;
            }
            else {
              iVar8 = 8;
              if (iVar9 < 7) {
                iVar8 = 4;
              }
            }
          }
          JUTConsole::scroll(_sConsole,iVar8);
          bVar7 = true;
          iVar8 = 0;
          iVar9 = iVar9 + 1;
        }
        else {
          iVar8 = 0;
          iVar9 = 0;
        }
      }
      if (bVar7) {
        iVar5 = vi::VIGetRetraceCount();
        do {
          iVar6 = vi::VIGetRetraceCount();
        } while (iVar5 == iVar6);
        JUTConsoleManager::drawDirect(JUTConsoleManager::sManager,true);
      }
      waitTime(0x1e);
    } while( true );
  }
  do {
    JUTConsole::scroll(_sConsole,-*(int *)(_sConsole + 0x24));
    JUTConsoleManager::drawDirect(JUTConsoleManager::sManager,true);
    waitTime(2000);
    do {
      for (iVar8 = *(int *)(_sConsole + 0x48); iVar8 != 0; iVar8 = iVar8 + -1) {
        JUTConsole::scroll(_sConsole,1);
        JUTConsoleManager::drawDirect(JUTConsoleManager::sManager,true);
        pJVar2 = _sConsole;
        iVar5 = *(int *)(_sConsole + 0x48);
        uVar3 = JUTConsole::getLineOffset(_sConsole);
        iVar9 = JUTConsole::getUsedLine(pJVar2);
        if ((iVar9 - iVar5) + 1U <= uVar3) break;
        waitTime(0x14);
      }
      waitTime(3000);
      pJVar2 = _sConsole;
      iVar9 = *(int *)(_sConsole + 0x48);
      uVar3 = JUTConsole::getLineOffset(_sConsole);
      iVar8 = JUTConsole::getUsedLine(pJVar2);
    } while (uVar3 < (iVar8 - iVar9) + 1U);
  } while( true );
}


namespace JUTException {

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall waitTime(long) */

void waitTime(long param_1)

{
  int iVar1;
  int iVar2;
  uint in_r4;
  uint uVar3;
  undefined8 uVar4;
  
  if (param_1 != 0) {
    iVar1 = os::OSGetTime();
    uVar3 = in_r4;
    do {
      iVar2 = os::OSGetTime();
      uVar4 = Runtime.PPCEABI.H::__div2i
                        (iVar2 - ((uint)(uVar3 < in_r4) + iVar1),uVar3 - in_r4,0,
                         (DAT_800000f8 >> 2) / 1000);
      uVar3 = (uint)uVar4;
    } while (((uint)((ulonglong)uVar4 >> 0x20) ^ 0x80000000) <
             (uint)(uVar3 < (uint)param_1) + (param_1 >> 0x1f ^ 0x80000000U));
  }
  return;
}

}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JUTException::createFB(void) */

void __thiscall JUTException::createFB(JUTException *this)

{
  void *pvVar1;
  JUTExternalFB *this_00;
  int iVar2;
  int iVar3;
  JUTDirectPrint *this_01;
  
  iVar3 = os::OSGetArenaHi();
  iVar2 = (DAT_803a1af8 + 0xf & 0xfff0) * (uint)DAT_803a1afc;
  pvVar1 = (void *)(iVar3 + iVar2 * -2 & 0xffffffe0);
  this_00 = (JUTExternalFB *)((int)pvVar1 + -0x20);
  if (this_00 != (JUTExternalFB *)0x0) {
    JUTExternalFB::JUTExternalFB(this_00,(_GXRenderModeObj *)&gx::GXNtsc480Int,1,pvVar1,iVar2 * 2);
  }
  this_01 = *(JUTDirectPrint **)(this + 0x6c);
  JUTDirectPrint::changeFrameBuffer
            (this_01,this_00,*(ushort *)(this_01 + 4),*(ushort *)(this_01 + 6));
  vi::VIConfigure(&gx::GXNtsc480Int);
  vi::VISetNextFrameBuffer(pvVar1);
  vi::VISetBlack(0);
  vi::VIFlush();
  *(JUTExternalFB **)(this + 0x68) = this_00;
  return;
}


namespace JUTException {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall setPreUserCallback(void *(unsigned short,OSContext *,unsigned
   long,unsigned long)) */

undefined4 setPreUserCallback(FuncDef590 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = _sPreUserCallback;
  _sPreUserCallback = param_1;
  return uVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall setPostUserCallback(void *(unsigned short,OSContext *,unsigned
   long,unsigned long)) */

undefined4 setPostUserCallback(FuncDef591 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = _sPostUserCallback;
  _sPostUserCallback = param_1;
  return uVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall appendMapFile(char const *) */

void appendMapFile(char *param_1)

{
  int iVar1;
  char **ppcVar2;
  
  ppcVar2 = _sMapFileList;
  if (param_1 != (char *)0x0) {
    for (; ppcVar2 != (char **)0x0; ppcVar2 = (char **)ppcVar2[3]) {
      iVar1 = MSL_C.PPCEABI.bare.H::strcmp(param_1,*(char **)*ppcVar2);
      if (iVar1 == 0) {
        return;
      }
    }
    ppcVar2 = (char **)JKernel::operator_new(0x14);
    if (ppcVar2 != (char **)0x0) {
      JSUPtrLink::JSUPtrLink((JSUPtrLink *)(ppcVar2 + 1),ppcVar2);
      *ppcVar2 = param_1;
    }
    JSUPtrList::append((JSUPtrList *)&sMapFileList,(JSUPtrLink *)(ppcVar2 + 1));
  }
  return;
}

}

/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTException::queryMapAddress(char *,
                                            unsigned long,
                                            long,
                                            unsigned long *,
                                            unsigned long *,
                                            char *,
                                            unsigned long,
                                            bool,
                                            bool) */

undefined4 __thiscall
JUTException::queryMapAddress
          (JUTException *this,char *param_1,ulong param_2,long param_3,ulong *param_4,ulong *param_5
          ,char *param_6,ulong param_7,bool param_8,bool param_9)

{
  char cVar1;
  bool in_stack_ffffff8f;
  JUTException aJStack112 [80];
  
  if (this == (JUTException *)0x0) {
    if ((_sMapFileList != (JUTException **)0x0) &&
       (cVar1 = queryMapAddress_single
                          (*(JUTException **)*_sMapFileList,param_1,0xffffffff,param_3,param_4,
                           param_5,param_6,param_7,param_8,in_stack_ffffff8f), cVar1 == '\x01')) {
      return 1;
    }
  }
  else {
    MSL_C.PPCEABI.bare.H::snprintf((char *)aJStack112,0x50,"/maps/%s.map",this);
    cVar1 = queryMapAddress_single
                      (aJStack112,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                       in_stack_ffffff8f);
    if (cVar1 == '\x01') {
      return 1;
    }
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f0c */
/* WARNING: Inlined function: FUN_80328f58 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTException::queryMapAddress_single(char *,
                                                   unsigned long,
                                                   long,
                                                   unsigned long *,
                                                   unsigned long *,
                                                   char *,
                                                   unsigned long,
                                                   bool,
                                                   bool) */

undefined __thiscall
JUTException::queryMapAddress_single
          (JUTException *this,char *param_1,ulong param_2,long param_3,ulong *param_4,ulong *param_5
          ,char *param_6,ulong param_7,bool param_8,bool param_9)

{
  byte bVar1;
  bool bVar2;
  FILE *pFVar3;
  char *pcVar4;
  uint uVar5;
  ulong uVar6;
  undefined uVar7;
  char *pcVar8;
  FILE *extraout_r4;
  FILE *extraout_r4_00;
  ulong *puVar9;
  FILE *__stream;
  ulong uVar10;
  undefined local_ac8 [16];
  undefined local_ab8;
  char local_ab7 [10];
  char acStack2733 [7];
  char local_aa6;
  char acStack2725 [9];
  char local_a9c;
  FILE local_a9a [3];
  JUTDirectFile aJStack2232 [2168];
  
  if (this == (JUTException *)0x0) {
    uVar7 = 0;
  }
  else {
    pcVar4 = (char *)param_2;
    __stream = (FILE *)param_3;
    JUTDirectFile::JUTDirectFile(aJStack2232);
    uVar10 = 0;
    pFVar3 = JUTDirectFile::fopen(aJStack2232,(char *)this,pcVar4);
    if (((uint)pFVar3 & 0xff) == 0) {
      JUTDirectFile::_JUTDirectFile(aJStack2232);
      uVar7 = 0;
    }
    else {
      uVar7 = 0;
      do {
        do {
          do {
            bVar2 = false;
            uVar10 = uVar10 + 1;
            do {
              do {
                do {
                  pFVar3 = (FILE *)&local_ab8;
                  pcVar4 = JUTDirectFile::fgets(aJStack2232,(char *)pFVar3,0x200,__stream);
                  if ((int)pcVar4 < 0) goto LAB_802c6b50;
                } while (local_ab8 != '.');
                __stream = (FILE *)0x0;
                pcVar8 = local_ac8;
                pcVar4 = local_ab7;
                while( true ) {
                  if (*pcVar4 == '\0') break;
                  *pcVar8 = *pcVar4;
                  if ((*pcVar4 == ' ') || (__stream == (FILE *)0xf)) break;
                  __stream = (FILE *)((int)&__stream->_flags + 1);
                  pcVar8 = pcVar8 + 1;
                  pcVar4 = pcVar4 + 1;
                }
                pFVar3 = (FILE *)local_ac8;
                *(char *)((int)__stream + (int)((int)pFVar3->_shortbuf + -0x47)) = '\0';
                if (*pcVar4 == '\0') goto LAB_802c6b50;
              } while (((pcVar4[1] != 's') || (pcVar4[2] != 'e')) || (pcVar4[3] != 'c'));
            } while (pcVar4[4] != 't');
            bVar2 = true;
LAB_802c6b50:
            if (!bVar2) goto LAB_802c6d24;
          } while ((-1 < (int)param_2) && (param_2 != uVar10));
          do {
            do {
              pFVar3 = (FILE *)&local_ab8;
              pcVar4 = JUTDirectFile::fgets(aJStack2232,(char *)pFVar3,0x200,__stream);
              if ((int)pcVar4 < 5) goto LAB_802c6cf0;
            } while (((int)pcVar4 < 0x1c) || (local_a9c != '4'));
            uVar5 = MSL_C.PPCEABI.bare.H::strtol(acStack2725,(char **)0x0,0x10);
            pcVar4 = (char *)((int)local_aa6 << 0x1c | uVar5);
            pFVar3 = (FILE *)0x0;
            uVar6 = MSL_C.PPCEABI.bare.H::strtol(acStack2733,(char **)0x0,0x10);
          } while ((param_1 < pcVar4) || (pcVar4 + uVar6 <= param_1));
          if (param_3 != 0) {
            *(char **)param_3 = pcVar4;
          }
          if (param_4 != (ulong *)0x0) {
            *param_4 = uVar6;
          }
          if (param_5 != (ulong *)0x0) {
            __stream = (FILE *)0x0;
            pFVar3 = local_a9a;
            puVar9 = param_5;
            while (__stream < (FILE *)(param_6 + -1)) {
              bVar1 = *(byte *)&pFVar3->_flags;
              if ((bVar1 < 0x20) && (bVar1 != 9)) break;
              if (((bVar1 == 0x20) || (bVar1 == 9)) && (__stream != (FILE *)0x0)) {
                if (*(byte *)((int)puVar9 + -1) != 0x20) {
                  *(byte *)puVar9 = 0x20;
                  puVar9 = (ulong *)((int)puVar9 + 1);
                  __stream = (FILE *)((int)&__stream->_flags + 1);
                }
              }
              else {
                *(byte *)puVar9 = bVar1;
                puVar9 = (ulong *)((int)puVar9 + 1);
                __stream = (FILE *)((int)&__stream->_flags + 1);
              }
              pFVar3 = (FILE *)((int)&pFVar3->_flags + 1);
            }
            if (__stream != (FILE *)0x0) {
              if (*(byte *)((int)puVar9 + -1) == 0x20) {
                puVar9 = (ulong *)((int)puVar9 + -1);
              }
            }
            *(byte *)puVar9 = 0;
            if ((param_7 & 0xff) != 0) {
              if (param_8 != false) {
                JUTConsole::print(_sConsole,"\n");
              }
              __stream = (FILE *)local_ac8;
              JUTConsole::print_f(_sConsole,"  [%08X]: .%s [%08X: %XH]\n  %s\n",(___)param_1);
              param_8 = false;
              pFVar3 = extraout_r4;
            }
          }
          uVar7 = 1;
LAB_802c6cf0:
        } while ((int)param_2 < 0);
      } while (param_2 != uVar10);
      if (((param_7 & 0xff) != 0) && (param_8 != false)) {
        JUTConsole::print(_sConsole,"\n");
        pFVar3 = extraout_r4_00;
      }
LAB_802c6d24:
      JUTDirectFile::fclose(aJStack2232,pFVar3);
      JUTDirectFile::_JUTDirectFile(aJStack2232);
    }
  }
  return uVar7;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTException::createConsole(void *,
                                          unsigned long) */

void __thiscall JUTException::createConsole(JUTException *this,void *param_1,ulong param_2)

{
  JUTConsole *pJVar1;
  int iVar2;
  
  if (((this != (JUTException *)0x0) && (param_1 != (void *)0x0)) &&
     (iVar2 = JUTConsole::getLineFromObjectSize((JUTConsole *)param_1,0x32,param_2), iVar2 != 0)) {
    _sConsoleBuffer = this;
    _sConsoleBufferSize = param_1;
    _sConsole = JUTConsole::create(0x32,this,(ulong)param_1);
    JUTConsoleManager::setDirectConsole(JUTConsoleManager::sManager,_sConsole);
    pJVar1 = _sConsole;
    *(float *)(_sConsole + 0x50) = JUtility::_2982;
    *(float *)(pJVar1 + 0x54) = JUtility::_2983;
    pJVar1 = _sConsole;
    *(undefined4 *)(_sConsole + 0x40) = 0xc;
    *(undefined4 *)(pJVar1 + 0x44) = 0x28;
    pJVar1 = _sConsole;
    *(undefined4 *)(_sConsole + 0x48) = 0x17;
    if (*(uint *)(pJVar1 + 0x24) < *(uint *)(pJVar1 + 0x48)) {
      *(uint *)(pJVar1 + 0x48) = *(uint *)(pJVar1 + 0x24);
    }
    _sConsole[100] = (JUTConsole)0x1;
    *(undefined4 *)(_sConsole + 0x58) = 3;
  }
  return;
}


/* __thiscall JUTExternalFB::JUTExternalFB(_GXRenderModeObj *,
                                           _GXGamma,
                                           void *,
                                           unsigned long) */

void __thiscall
JUTExternalFB::JUTExternalFB
          (JUTExternalFB *this,_GXRenderModeObj *param_1,_GXGamma param_2,void *param_3,
          ulong param_4)

{
  this->mpRenderModeObj = param_1;
  this->field_0x4 = param_4;
  this->field_0xc = 1;
  this->mGamma = (short)param_2;
  this->field_0x10 = 0;
  return;
}


/* __thiscall JUTException::~JUTException(void) */

void __thiscall JUTException::_JUTException(JUTException *this)

{
  short in_r4;
  
  if (this != (JUTException *)0x0) {
    *(undefined1 **)this = &__vt;
    JKRThread::_JKRThread((JKRThread *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace JUtility {

void __sinit_JUTException_cpp(void)

{
  JSUPtrList::JSUPtrList((JSUPtrList *)&::JUTException::sMapFileList,false);
  Runtime.PPCEABI.H::__register_global_object
            (&::JUTException::sMapFileList,::JSUList<JUTException::JUTExMapFile>::_JSUList,&_2144);
  return;
}

}

/* __thiscall JSUList<JUTException::JUTExMapFile>::~JSUList(void) */

JSUList_JUTException__JUTExMapFile_ * __thiscall
JSUList<JUTException::JUTExMapFile>::_JSUList(JSUList_JUTException__JUTExMapFile_ *this)

{
  short in_r4;
  
  if ((this != (JSUList_JUTException__JUTExMapFile_ *)0x0) &&
     (JSUPtrList::_JSUPtrList((JSUPtrList *)this), 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return this;
}

