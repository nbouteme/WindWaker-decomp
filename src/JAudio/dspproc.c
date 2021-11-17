#include <JAudio/dspproc.h>
#include <JAudio/JASDSPInterface.h>
#include <JAudio/dsptask.h>
#include <JAudio/dspproc.h>


namespace JAudio {
undefined4 flag;
undefined4 d_waitflag;

/* __stdcall DSPReleaseHalt2(unsigned long) */

void DSPReleaseHalt2(int param_1)

{
  uint uVar1;
  uint local_18 [5];
  
  uVar1 = DSP_CreateMap2();
  local_18[0] = param_1 << 0x10 | uVar1 & 0xffff;
  DSPSendCommands2(local_18,0,0);
  return;
}


/* __stdcall DSPReleaseHalt(void) */

void DSPReleaseHalt(void)

{
  undefined4 local_8 [2];
  
  local_8[0] = 0x30000;
  DSPSendCommands2(local_8,0,0);
  return;
}


/* __stdcall setup_callback(unsigned short) */

void setup_callback(void)

{
  flag = 0;
  return;
}


/* __stdcall DsetupTable(unsigned long,
                         unsigned long,
                         unsigned long,
                         unsigned long,
                         unsigned long) */

void DsetupTable(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                        undefined4 param_5)

{
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_18 = param_1 & 0xffff | 0x81000000;
  flag = 1;
  local_14 = param_2;
  local_10 = param_3;
  local_c = param_4;
  local_8 = param_5;
  DSPSendCommands2(&local_18,5,setup_callback);
  do {
  } while (flag != 0);
  return;
}


/* __stdcall DsetMixerLevel(float) */

void DsetMixerLevel(double param_1)

{
  DSP_MIXERLEVEL = (short)(int)((double)_315 * param_1);
  return;
}


/* __stdcall DsyncFrame(unsigned long,
                        unsigned long,
                        unsigned long) */

void DsyncFrame(uint param_1,undefined4 param_2,undefined4 param_3)

{
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = (param_1 & 0xff) << 0x10 | 0x82000000 | (uint)DSP_MIXERLEVEL;
  local_14 = param_2;
  local_10 = param_3;
  DSPSendCommands2(&local_18,3,0);
  return;
}


/* __stdcall dummy_callback(unsigned short) */

void dummy_callback(void)

{
  d_waitflag = 0;
  return;
}


/* __stdcall DsetDolbyDelay(unsigned long,
                            unsigned short) */

void DsetDolbyDelay(undefined4 param_1,uint param_2)

{
  uint local_8;
  undefined4 local_4;
  
  local_8 = param_2 & 0xffff | 0x8d000000;
  d_waitflag = 1;
  local_4 = param_1;
  DSPSendCommands2(&local_8,2,dummy_callback);
  do {
  } while (d_waitflag != 0);
  return;
}

