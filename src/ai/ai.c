#include <ai/ai.h>
#include <os/OSInterrupt.h>
#include <ai/ai.h>
#include <os/OS.h>
#include <os/OSContext.h>
#include <os/OSTime.h>


namespace ai {
undefined4 __AIS_Callback;
undefined4 __AID_Callback;
undefined4 __CallbackStack;
undefined4 __OldStack;
undefined4 __AI_init_flag;
undefined4 __AID_Active;
undefined4 bound_32KHz;
undefined4 bound_48KHz;
undefined4 min_wait;
undefined4 max_wait;
undefined4 buffer;

undefined4 AIRegisterDMACallback(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = __AID_Callback;
  os::OSDisableInterrupts();
  __AID_Callback = param_1;
  os::OSRestoreInterrupts();
  return uVar1;
}


void AIInitDMA(undefined4 param_1,uint param_2)

{
  os::OSDisableInterrupts();
  DAT_cc005030 = DAT_cc005030 & 0xfc00 | (ushort)((uint)param_1 >> 0x10);
  DAT_cc005032 = DAT_cc005032 & 0x1f | (ushort)param_1;
  DAT_cc005036 = DAT_cc005036 & 0x8000 | (ushort)(param_2 >> 5);
  os::OSRestoreInterrupts();
  return;
}


void AIStartDMA(void)

{
  DAT_cc005036 = DAT_cc005036 | 0x8000;
  return;
}


void AIResetStreamSampleCount(void)

{
  DAT_cc006c00 = DAT_cc006c00 & 0xffffffdf | 0x20;
  return;
}


void AISetStreamPlayState(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar1 = AIGetStreamPlayState();
  if (param_1 != uVar1) {
    iVar2 = AIGetStreamSampleRate();
    if ((iVar2 == 0) && (param_1 == 1)) {
      uVar3 = AIGetStreamVolRight();
      uVar4 = AIGetStreamVolLeft();
      AISetStreamVolRight(0);
      AISetStreamVolLeft(0);
      uVar5 = os::OSDisableInterrupts();
      __AI_SRC_INIT();
      DAT_cc006c00 = DAT_cc006c00 & 0xffffffde | 0x21;
      os::OSRestoreInterrupts(uVar5);
      AISetStreamVolLeft(uVar3);
      AISetStreamVolRight(uVar4);
    }
    else {
      DAT_cc006c00 = DAT_cc006c00 & 0xfffffffe | param_1;
    }
  }
  return;
}


uint AIGetStreamPlayState(void)

{
  return DAT_cc006c00 & 1;
}


void AISetDSPSampleRate(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar2 = AIGetDSPSampleRate();
  if ((param_1 != iVar2) && (DAT_cc006c00 = DAT_cc006c00 & 0xffffffbf, param_1 == 0)) {
    uVar3 = AIGetStreamVolLeft();
    uVar4 = AIGetStreamVolRight();
    uVar1 = DAT_cc006c00 & 1;
    iVar2 = AIGetStreamSampleRate();
    AISetStreamVolLeft(0);
    AISetStreamVolRight(0);
    uVar5 = os::OSDisableInterrupts();
    __AI_SRC_INIT();
    DAT_cc006c00 = DAT_cc006c00 & 0xffffffdc | 0x20 | iVar2 << 1 | uVar1 | 0x40;
    os::OSRestoreInterrupts(uVar5);
    AISetStreamVolLeft(uVar3);
    AISetStreamVolRight(uVar4);
  }
  return;
}


uint AIGetDSPSampleRate(void)

{
  return DAT_cc006c00 >> 6 & 1 ^ 1;
}


void AISetStreamSampleRate(int param_1)

{
  if (param_1 == 1) {
    __AI_set_stream_sample_rate();
  }
  return;
}


void __AI_set_stream_sample_rate(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  iVar3 = AIGetStreamSampleRate();
  if (param_1 != iVar3) {
    uVar1 = DAT_cc006c00 & 1;
    uVar4 = AIGetStreamVolLeft();
    uVar5 = AIGetStreamVolRight();
    AISetStreamVolRight(0);
    AISetStreamVolLeft(0);
    uVar2 = DAT_cc006c00 & 0x40;
    DAT_cc006c00 = DAT_cc006c00 & 0xffffffbf;
    uVar6 = os::OSDisableInterrupts();
    __AI_SRC_INIT();
    DAT_cc006c00 = DAT_cc006c00 & 0xffffffdd | uVar2 | 0x20 | param_1 << 1;
    os::OSRestoreInterrupts(uVar6);
    AISetStreamPlayState(uVar1);
    AISetStreamVolLeft(uVar4);
    AISetStreamVolRight(uVar5);
  }
  return;
}


uint AIGetStreamSampleRate(void)

{
  return DAT_cc006c00 >> 1 & 1;
}


void AISetStreamVolLeft(uint param_1)

{
  DAT_cc006c04 = param_1 & 0xff | DAT_cc006c04 & 0xffffff00;
  return;
}


uint AIGetStreamVolLeft(void)

{
  return DAT_cc006c04 & 0xff;
}


void AISetStreamVolRight(uint param_1)

{
  DAT_cc006c04 = (param_1 & 0xff) << 8 | DAT_cc006c04 & 0xffff00ff;
  return;
}


uint AIGetStreamVolRight(void)

{
  return DAT_cc006c04 >> 8 & 0xff;
}


void AIInit(undefined4 param_1)

{
  uint uVar1;
  
  if (__AI_init_flag != 1) {
    os::OSRegisterVersion(__AIVersion);
    uVar1 = (DAT_800000f8 >> 2) / 0x1e848;
    DAT_803f7bd4 = (uVar1 * 0x7b24) / 8000;
    DAT_803f7bdc = (uVar1 * 0xa428) / 8000;
    DAT_803f7be4 = (uVar1 * 42000) / 8000;
    DAT_803f7bec = (uVar1 * 63000) / 8000;
    DAT_803f7bf4 = (uVar1 * 3000) / 8000;
    DAT_cc006c00 = DAT_cc006c00 & 0xffffffdf | 0x20;
    bound_32KHz = 0;
    bound_48KHz = 0;
    min_wait = 0;
    max_wait = 0;
    buffer = 0;
    DAT_cc006c04 = DAT_cc006c04 & 0xffff0000;
    DAT_cc006c0c = 0;
    __AI_set_stream_sample_rate(1);
    AISetDSPSampleRate(0);
    __AIS_Callback = 0;
    __AID_Callback = 0;
    __CallbackStack = param_1;
    os::__OSSetInterruptHandler(5,__AIDHandler);
    os::__OSUnmaskInterrupts(0x4000000);
    os::__OSSetInterruptHandler(8,__AISHandler);
    os::__OSUnmaskInterrupts(0x800000);
    __AI_init_flag = 1;
  }
  return;
}


void __AISHandler(undefined4 param_1,undefined4 param_2)

{
  undefined auStack720 [712];
  
  DAT_cc006c00 = DAT_cc006c00 | 8;
  os::OSClearContext(auStack720);
  os::OSSetCurrentContext(auStack720);
  if (__AIS_Callback != (code *)0x0) {
    (*__AIS_Callback)(DAT_cc006c08);
  }
  os::OSClearContext(auStack720);
  os::OSSetCurrentContext(param_2);
  return;
}


void __AIDHandler(undefined4 param_1,undefined4 param_2)

{
  undefined auStack720 [716];
  
  DAT_cc00500a = DAT_cc00500a & 0xff5f | 8;
  os::OSClearContext(auStack720);
  os::OSSetCurrentContext(auStack720);
  if ((__AID_Callback != (code *)0x0) && (__AID_Active == 0)) {
    __AID_Active = 1;
    if (__CallbackStack == 0) {
      (*__AID_Callback)();
    }
    else {
      __AICallbackStackSwitch();
    }
    __AID_Active = 0;
  }
  os::OSClearContext(auStack720);
  os::OSSetCurrentContext(param_2);
  return;
}


void __AICallbackStackSwitch(code *param_1)

{
  __OldStack = &stack0xffffffe8;
  (*param_1)();
  return;
}


/* WARNING: Removing unreachable block (ram,0x80317090) */
/* WARNING: Removing unreachable block (ram,0x803170c8) */
/* WARNING: Removing unreachable block (ram,0x803170d4) */
/* WARNING: Removing unreachable block (ram,0x80317140) */
/* WARNING: Removing unreachable block (ram,0x80317164) */
/* WARNING: Removing unreachable block (ram,0x803171a0) */
/* WARNING: Removing unreachable block (ram,0x80317190) */
/* WARNING: Removing unreachable block (ram,0x80317130) */
/* WARNING: Removing unreachable block (ram,0x803171ac) */
/* WARNING: Removing unreachable block (ram,0x803171bc) */
/* WARNING: Removing unreachable block (ram,0x803171e0) */

void __AI_SRC_INIT(void)

{
  do {
  } while( true );
}

