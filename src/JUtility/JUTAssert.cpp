#include <JUtility/JUTAssert.h>
#include <JUtility/JUTAssert.h>
#include <JUtility/JUTDirectPrint.h>
#include <vi/vi.h>
#include <JUtility/JUTFont.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <JUtility/JUTConsole.h>
#include <m_Do_printf.h>
#include <os/OSTime.h>
#include <JUTAssertion.h>


namespace JUTAssertion {

/* __thiscall create(void) */

void create(void)

{
  return;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTAssertion::flush_subroutine(void) */

uint __thiscall JUTAssertion::flush_subroutine(JUTAssertion *this)

{
  if (_sMessageLife == 0) {
    return 0;
  }
  if (_sMessageLife != 0xffffffff) {
    _sMessageLife = _sMessageLife - 1;
  }
  if (4 < _sMessageLife) {
    return _sMessageLife;
  }
  return 0;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTAssertion::flushMessage(void) */

void __thiscall JUTAssertion::flushMessage(JUTAssertion *this)

{
  int iVar1;
  
  iVar1 = flush_subroutine(this);
  if ((iVar1 != 0) && (@unnamed@JUTAssert_cpp@::mVisible == '\x01')) {
    JUTDirectPrint::drawString(_sDirectPrint,0x10,0x10,&@unnamed@JUTAssert_cpp@::sMessageFileLine);
    JUTDirectPrint::drawString(_sDirectPrint,0x10,0x18,&@unnamed@JUTAssert_cpp@::sMessageString);
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x802c7670) */
/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall JUTAssertion::flushMessage_dbPrint(void) */

void __thiscall JUTAssertion::flushMessage_dbPrint(JUTAssertion *this)

{
  undefined uVar1;
  int iVar2;
  size_t sVar3;
  JUTFont *this_00;
  undefined4 uVar4;
  undefined8 in_f31;
  double dVar5;
  _GXColor local_48;
  _GXColor local_44;
  undefined4 local_40;
  uint uStack60;
  undefined4 local_38;
  uint uStack52;
  undefined4 local_30;
  uint uStack44;
  undefined4 local_28;
  uint uStack36;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar2 = flush_subroutine(this);
  if ((((iVar2 != 0) && (@unnamed@JUTAssert_cpp@::mVisible == '\x01')) &&
      (JUTDbPrint::sDebugPrint != (JUTDbPrint *)0x0)) &&
     (this_00 = *(JUTFont **)(JUTDbPrint::sDebugPrint + 4), this_00 != (JUTFont *)0x0)) {
    iVar2 = vi::VIGetRetraceCount();
    uVar1 = (undefined)(iVar2 << 2);
    (*(code *)this_00->vtbl->setGX)(this_00);
    local_48 = (_GXColor)CONCAT31(CONCAT21(CONCAT11(0xff,uVar1),uVar1) & 0xfff0f0 | 0xf0f,0xff);
    local_44 = local_48;
    JUTFont::setCharColor(this_00,&local_44);
    sVar3 = MSL_C.PPCEABI.bare.H::strlen(&@unnamed@JUTAssert_cpp@::sMessageFileLine);
    uStack60 = (*(code *)this_00->vtbl->getHeight)(this_00);
    uStack60 = uStack60 ^ 0x80000000;
    local_40 = 0x43300000;
    dVar5 = (double)(float)((double)CONCAT44(0x43300000,uStack60) - JUtility::_638);
    uStack52 = (*(code *)this_00->vtbl->getWidth)(this_00);
    uStack52 = uStack52 ^ 0x80000000;
    local_38 = 0x43300000;
    JUTFont::drawString_size_scale
              (this_00,JUtility::_634,JUtility::_635,
               (float)((double)CONCAT44(0x43300000,uStack52) - JUtility::_638),(float)dVar5,
               &@unnamed@JUTAssert_cpp@::sMessageFileLine,sVar3,true);
    sVar3 = MSL_C.PPCEABI.bare.H::strlen(&@unnamed@JUTAssert_cpp@::sMessageString);
    uStack44 = (*(code *)this_00->vtbl->getHeight)(this_00);
    uStack44 = uStack44 ^ 0x80000000;
    local_30 = 0x43300000;
    dVar5 = (double)(float)((double)CONCAT44(0x43300000,uStack44) - JUtility::_638);
    uStack36 = (*(code *)this_00->vtbl->getWidth)(this_00);
    uStack36 = uStack36 ^ 0x80000000;
    local_28 = 0x43300000;
    JUTFont::drawString_size_scale
              (this_00,JUtility::_634,JUtility::_636,
               (float)((double)CONCAT44(0x43300000,uStack36) - JUtility::_638),(float)dVar5,
               &@unnamed@JUTAssert_cpp@::sMessageString,sVar3,true);
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


namespace JUTAssertion {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall getSDevice(void) */

undefined4 getSDevice(void)

{
  return _sDevice;
}

}

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTAssertion::setConfirmMessage(unsigned long,
                                              char *,
                                              int,
                                              bool,
                                              char const *) */

void __thiscall
JUTAssertion::setConfirmMessage
          (JUTAssertion *this,ulong param_1,char *param_2,int param_3,bool param_4,char *param_5)

{
  int iVar1;
  undefined3 in_register_0000001c;
  
  iVar1 = _sMessageLife;
  if ((param_3 & 0xffU) != 1) {
    if ((_sMessageLife == 0) && (((uint)this & 1) != 0)) {
      _sMessageLife = _sDisplayTime;
      _sMessageOwner = 2;
      MSL_C.PPCEABI.bare.H::snprintf
                (&@unnamed@JUTAssert_cpp@::sMessageFileLine,0x3f,"FAILED [%s:%d]",param_1,param_2);
      MSL_C.PPCEABI.bare.H::snprintf
                (&@unnamed@JUTAssert_cpp@::sMessageString,0x5f,"%s",
                 CONCAT31(in_register_0000001c,param_4));
    }
    if (((iVar1 == 0) || (@unnamed@JUTAssert_cpp@::mSynchro == '\0')) && (((uint)this & 2) != 0)) {
      JUtility::JUTWarningConsole_f
                ("FAILED [%s:%d] %s\n",param_1,param_2,CONCAT31(in_register_0000001c,param_4));
    }
  }
  return;
}


namespace JUTAssertion {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall showAssert(unsigned long,
                                       char const *,
                                       int,
                                       char const *) */

void showAssert(ulong param_1,char *param_2,int param_3,char *param_4)

{
  int iVar1;
  int iVar2;
  uint extraout_r4;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  char acStack280 [264];
  
  m_Do_printf::OSReport("Failed assertion %s in \"%s\" on line %d\n",param_4,param_2,param_3);
  if ((param_1 & 1) != 0) {
    if (_sDirectPrint != (undefined4 *)0x0) {
      JUTDirectPrint::erase((JUTDirectPrint *)_sDirectPrint,10,0x10,0x132,0x18);
      MSL_C.PPCEABI.bare.H::snprintf(acStack280,0x5f,"Failed assertion: %s:%d",param_2,param_3);
      JUTDirectPrint::drawString((JUTDirectPrint *)_sDirectPrint,0x10,0x10,acStack280);
      MSL_C.PPCEABI.bare.H::snprintf(acStack280,0x5f,"%s",param_4);
      JUTDirectPrint::drawString((JUTDirectPrint *)_sDirectPrint,0x10,0x18,acStack280);
      vi::VISetNextFrameBuffer(*_sDirectPrint);
      vi::VIWaitForRetrace();
      vi::VIFlush();
      uVar3 = extraout_r4;
      iVar1 = os::OSGetTime();
      uVar4 = uVar3;
      do {
        iVar2 = os::OSGetTime();
        uVar5 = Runtime.PPCEABI.H::__div2i
                          (iVar2 - ((uint)(uVar4 < uVar3) + iVar1),uVar4 - uVar3,0,
                           (DAT_800000f8 >> 2) / 1000);
        uVar4 = (uint)uVar5;
      } while (((uint)((ulonglong)uVar5 >> 0x20) ^ 0x80000000) < (uVar4 < 2000) + 0x80000000);
    }
  }
  return;
}

}

namespace JUtility {

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void setWarningMessage_f_va
               (uint param_1,undefined4 param_2,undefined4 param_3,char *param_4,
               __gnuc_va_list param_5)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = _sMessageLife;
  bVar1 = false;
  if (_sMessageLife == 0) {
    if ((param_1 & 1) != 0) {
      _sMessageLife = _sDisplayTime;
      _sMessageOwner = 3;
      MSL_C.PPCEABI.bare.H::snprintf
                (&::JUTAssertion::@unnamed@JUTAssert_cpp@::sMessageFileLine,0x3f,"WARNING [%s:%d]",
                 param_2,param_3);
    }
    MSL_C.PPCEABI.bare.H::vsnprintf
              (&::JUTAssertion::@unnamed@JUTAssert_cpp@::sMessageString,0x5f,param_4,param_5);
    bVar1 = true;
  }
  if (((iVar2 == 0) || (::JUTAssertion::@unnamed@JUTAssert_cpp@::mSynchro == '\0')) &&
     ((param_1 & 2) != 0)) {
    JUTWarningConsole_f("WARNING [%s:%d] ",param_2,param_3);
    if (bVar1) {
      JUTWarningConsole(&::JUTAssertion::@unnamed@JUTAssert_cpp@::sMessageString);
    }
    else {
      JUTWarningConsole_f_va(param_4,param_5);
    }
    JUTWarningConsole(&DAT_8036c716);
  }
  return;
}

}

namespace JUTAssertion {

/* __thiscall setWarningMessage_f(unsigned long,
                                                char *,
                                                int,
                                                char const *,
                                                ...) */

void setWarningMessage_f
               (ulong param_1,char *param_2,int param_3,char *param_4,___ param_5)

{
  ulong local_78;
  char *local_74;
  int local_70;
  char *local_6c;
  ___ local_68;
  undefined4 local_18;
  undefined *local_14;
  ulong *local_10;
  
  local_18 = 0x4000000;
  local_14 = &stack0x00000008;
  local_10 = &local_78;
  local_78 = param_1;
  local_74 = param_2;
  local_70 = param_3;
  local_6c = param_4;
  local_68 = param_5;
  JUtility::setWarningMessage_f_va();
  return;
}

}

namespace JUtility {

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void setLogMessage_f_va
               (uint param_1,undefined4 param_2,undefined4 param_3,char *param_4,
               __gnuc_va_list param_5)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = _sMessageLife;
  bVar1 = false;
  if (_sMessageLife == 0) {
    if ((param_1 & 1) != 0) {
      _sMessageLife = _sDisplayTime;
      _sMessageOwner = 4;
      MSL_C.PPCEABI.bare.H::snprintf
                (&::JUTAssertion::@unnamed@JUTAssert_cpp@::sMessageFileLine,0x3f,"[%s:%d]",param_2,
                 param_3);
    }
    MSL_C.PPCEABI.bare.H::vsnprintf
              (&::JUTAssertion::@unnamed@JUTAssert_cpp@::sMessageString,0x5f,param_4,param_5);
    bVar1 = true;
  }
  if (((iVar2 == 0) || (::JUTAssertion::@unnamed@JUTAssert_cpp@::mSynchro == '\0')) &&
     ((param_1 & 2) != 0)) {
    JUTReportConsole_f("[%s:%d] ",param_2,param_3);
    if (bVar1) {
      JUTReportConsole(&::JUTAssertion::@unnamed@JUTAssert_cpp@::sMessageString);
    }
    else {
      JUTReportConsole_f_va(param_4,param_5);
    }
    JUTReportConsole(&DAT_8036c716);
  }
  return;
}

}

/* __thiscall JUTAssertion::setLogMessage_f(unsigned long,
                                            char *,
                                            int,
                                            char const *,
                                            ...) */

void __thiscall
JUTAssertion::setLogMessage_f
          (JUTAssertion *this,ulong param_1,char *param_2,int param_3,char *param_4,___ param_5)

{
  JUTAssertion *local_78;
  ulong local_74;
  char *local_70;
  int local_6c;
  char *local_68;
  ___ local_64;
  undefined4 local_18;
  undefined *local_14;
  JUTAssertion **local_10;
  
  local_18 = 0x4000000;
  local_14 = &stack0x00000008;
  local_10 = &local_78;
  local_78 = this;
  local_74 = param_1;
  local_70 = param_2;
  local_6c = param_3;
  local_68 = param_4;
  local_64 = param_5;
  JUtility::setLogMessage_f_va();
  return;
}


namespace JUTAssertion {

/* __thiscall setVisible(bool) */

void setVisible(bool param_1)

{
  @unnamed@JUTAssert_cpp@::mVisible = param_1;
  return;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTAssertion::setMessageCount(int) */

void __thiscall JUTAssertion::setMessageCount(JUTAssertion *this,int param_1)

{
  _sMessageLife = (uint)this & ~((int)((uint)this | ~-(int)this) >> 0x1f);
  return;
}

