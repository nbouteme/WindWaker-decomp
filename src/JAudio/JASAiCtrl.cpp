#include <JAudio/JASAiCtrl.h>
#include <JAudio/JASCallback.h>
#include <JAudio/JASAiCtrl.h>
#include <JAudio/JASCmdStack.h>
#include <JAudio/JASCalc.h>
#include <JAudio/JASSystemHeap.h>
#include <os/OSCache.h>
#include <ai/ai.h>
#include <JAudio/JASDSPBuf.h>
#include <os/OSInterrupt.h>
#include <JAudio/JASHardStream.h>
#include <JAudio/JASProbe.h>
#include <JASystem/Kernel.h>


namespace JASystem {
undefined1 Kernel;
undefined1 Kernel;
undefined1 Kernel;
undefined1 Kernel;
undefined1 Kernel;
undefined1 Kernel;
undefined1 Kernel;
pointer Kernel;
undefined1 Kernel;
}

namespace JAudio {
undefined4 dacp$389;
undefined1 init$390;
}

namespace JASystem {

/* __thiscall Kernel::init(void) */

int __thiscall Kernel::init(Kernel *this,EVP_PKEY_CTX *ctx)

{
  Kernel *pKVar1;
  Calc *this_00;
  int iVar2;
  
  pKVar1 = (Kernel *)resetCallback(this);
  pKVar1 = (Kernel *)initSystem(pKVar1);
  this_00 = (Calc *)portCmdInit(pKVar1);
  iVar2 = Calc::initSinfT(this_00);
  return iVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Kernel::initSystem(void) */

void __thiscall Kernel::initSystem(Kernel *this)

{
  undefined4 uVar1;
  ulong in_r4;
  ulong extraout_r4;
  size_t in_r5;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  do {
    uVar1 = allocFromSysDram((Kernel *)(_gDacSize << 1),in_r4);
    *(undefined4 *)(&dac + iVar3) = uVar1;
    Calc::bzero(*(Calc **)(&dac + iVar3),(void *)(_gDacSize << 1),in_r5);
    os::DCStoreRange(*(undefined4 *)(&dac + iVar3),_gDacSize << 1);
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 4;
    in_r4 = extraout_r4;
  } while (iVar2 < 3);
  ai::AIInit(0);
  ai::AIInitDMA(DAT_803e8d58,_gDacSize << 1);
  return;
}


namespace Kernel {

/* __thiscall registerMixCallback(short * *(long),
                                                    unsigned char) */

void registerMixCallback(FuncDef562 *param_1,uchar param_2)

{
  extMixCallback = param_1;
  extMixMode = param_2;
  return;
}

}

/* WARNING: Removing unreachable block (ram,0x8027afa0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Kernel::vframeWork(void) */

void __thiscall Kernel::vframeWork(Kernel *this)

{
  int iVar1;
  short *psVar2;
  undefined4 uVar3;
  long in_r4;
  long in_r7;
  
  if (JAudio::init_390 == '\0') {
    JAudio::dacp_389 = 0;
    JAudio::init_390 = '\x01';
  }
  _JASVframeCounter = _JASVframeCounter + 1;
  psVar2 = (short *)TDSP_DACBuffer::mixDSP((TDSP_DACBuffer *)(_gDacSize >> 1),in_r4);
  Calc::imixcopy((Calc *)(psVar2 + _gFrameSamples),psVar2,*(short **)(&dac + JAudio::dacp_389 * 4),
                 (short *)(_gDacSize >> 1),in_r7);
  if (extMixCallback != (undefined *)0x0) {
    if (extMixMode == 2) {
      mixExtraTrack(*(short **)(&dac + JAudio::dacp_389 * 4),_gDacSize >> 1,
                    (FuncDef565 *)extMixCallback);
    }
    else {
      if (extMixMode < 2) {
        if (extMixMode == 0) {
          mixMonoTrack(*(short **)(&dac + JAudio::dacp_389 * 4),_gDacSize >> 1,
                       (FuncDef563 *)extMixCallback);
        }
        else {
          mixMonoTrackWide(*(short **)(&dac + JAudio::dacp_389 * 4),_gDacSize >> 1,
                           (FuncDef564 *)extMixCallback);
        }
      }
      else {
        if (extMixMode < 4) {
          mixInterleaveTrack(*(short **)(&dac + JAudio::dacp_389 * 4),_gDacSize >> 1,
                             (FuncDef566 *)extMixCallback);
        }
      }
    }
  }
  uVar3 = os::OSDisableInterrupts();
  os::DCStoreRange(*(undefined4 *)(&dac + JAudio::dacp_389 * 4),_gDacSize << 1);
  os::OSRestoreInterrupts(uVar3);
  iVar1 = JAudio::dacp_389 * 4;
  JAudio::dacp_389 = JAudio::dacp_389 + 1;
  if (JAudio::dacp_389 == 3) {
    JAudio::dacp_389 = 0;
  }
  _lastRspMadep = *(undefined4 *)(&dac + iVar1);
  _vframeWorkRunning = 0;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Kernel::updateDac(void) */

void __thiscall Kernel::updateDac(Kernel *this)

{
  Kernel *this_00;
  
  if (_useRspMadep == 0) {
    _useRspMadep = _lastRspMadep;
    _lastRspMadep = 0;
  }
  if (_useRspMadep == 0) {
    this_00 = _JASUniversalDacCounter;
    _JASUniversalDacCounter = _JASUniversalDacCounter + 1;
  }
  else {
    this_00 = (Kernel *)ai::AIInitDMA(_useRspMadep,_gDacSize << 1);
    _useRspMadep = 0;
  }
  if ((_lastRspMadep == 0) && (_vframeWorkRunning == 0)) {
    this_00 = (Kernel *)vframeWork(this_00);
  }
  HardStream::main((HardStream *)this_00);
  if (_dacCallbackFunc != (code *)0x0) {
    (*_dacCallbackFunc)(_lastRspMadep,_gDacSize >> 1);
  }
  return;
}


namespace Kernel {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall mixMonoTrack(short *,
                                             long,
                                             short * *(long)) */

void mixMonoTrack(short *param_1,long param_2,FuncDef563 *param_3)

{
  int iVar1;
  short sVar2;
  short *psVar3;
  undefined8 uVar4;
  
  probeStart((Kernel *)0x5,(long)"MONO-MIX",(char *)param_3);
  uVar4 = (undefined8)(*param_3)(param_2);
  psVar3 = (short *)((ulonglong)uVar4 >> 0x20);
  if ((psVar3 != (short *)0x0) && (probeFinish((Kernel *)0x5,(long)uVar4), 0 < param_2)) {
    do {
      iVar1 = (int)*param_1 + (int)*psVar3;
      if (iVar1 < -0x8000) {
        sVar2 = -0x7fff;
      }
      else {
        if (iVar1 < 0x8000) {
          sVar2 = (short)iVar1;
        }
        else {
          sVar2 = 0x7fff;
        }
      }
      *param_1 = sVar2;
      iVar1 = (int)param_1[1] + (int)*psVar3;
      if (iVar1 < -0x8000) {
        sVar2 = -0x7fff;
      }
      else {
        if (iVar1 < 0x8000) {
          sVar2 = (short)iVar1;
        }
        else {
          sVar2 = 0x7fff;
        }
      }
      param_1[1] = sVar2;
      param_1 = param_1 + 2;
      psVar3 = psVar3 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall mixMonoTrackWide(short *,
                                                 long,
                                                 short * *(long)) */

void mixMonoTrackWide(short *param_1,long param_2,FuncDef564 *param_3)

{
  int iVar1;
  short sVar2;
  short *psVar3;
  undefined8 uVar4;
  
  probeStart((Kernel *)0x5,(long)"MONO(W)-MIX",(char *)param_3);
  uVar4 = (undefined8)(*param_3)(param_2);
  psVar3 = (short *)((ulonglong)uVar4 >> 0x20);
  if ((psVar3 != (short *)0x0) && (probeFinish((Kernel *)0x5,(long)uVar4), 0 < param_2)) {
    do {
      iVar1 = (int)*param_1 + (int)*psVar3;
      if (iVar1 < -0x8000) {
        sVar2 = -0x7fff;
      }
      else {
        if (iVar1 < 0x8000) {
          sVar2 = (short)iVar1;
        }
        else {
          sVar2 = 0x7fff;
        }
      }
      *param_1 = sVar2;
      iVar1 = (int)param_1[1] - (int)*psVar3;
      if (iVar1 < -0x8000) {
        sVar2 = -0x7fff;
      }
      else {
        if (iVar1 < 0x8000) {
          sVar2 = (short)iVar1;
        }
        else {
          sVar2 = 0x7fff;
        }
      }
      param_1[1] = sVar2;
      param_1 = param_1 + 2;
      psVar3 = psVar3 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mixExtraTrack(short *,
                                              long,
                                              short * *(long)) */

void mixExtraTrack(short *param_1,long param_2,FuncDef565 *param_3)

{
  int iVar1;
  short sVar2;
  FuncDef565 *pFVar3;
  short *psVar4;
  short *psVar5;
  undefined8 uVar6;
  
  pFVar3 = param_3;
  probeStart((Kernel *)0x5,(long)"DSPMIX",(char *)param_3);
  uVar6 = (undefined8)(*param_3)(param_2);
  psVar4 = (short *)((ulonglong)uVar6 >> 0x20);
  if (psVar4 != (short *)0x0) {
    probeFinish((Kernel *)0x5,(long)uVar6);
    probeStart((Kernel *)0x6,(long)"MIXING",(char *)pFVar3);
    psVar5 = psVar4 + _gFrameSamples;
    if (0 < param_2) {
      do {
        iVar1 = (int)*param_1 + (int)*psVar5;
        if (iVar1 < -0x8000) {
          sVar2 = -0x7fff;
        }
        else {
          if (iVar1 < 0x8000) {
            sVar2 = (short)iVar1;
          }
          else {
            sVar2 = 0x7fff;
          }
        }
        *param_1 = sVar2;
        iVar1 = (int)param_1[1] + (int)*psVar4;
        if (iVar1 < -0x8000) {
          sVar2 = -0x7fff;
        }
        else {
          if (iVar1 < 0x8000) {
            sVar2 = (short)iVar1;
          }
          else {
            sVar2 = 0x7fff;
          }
        }
        param_1[1] = sVar2;
        param_1 = param_1 + 2;
        psVar5 = psVar5 + 1;
        psVar4 = psVar4 + 1;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
    probeFinish((Kernel *)0x6,(long)param_1);
  }
  return;
}


/* __thiscall mixInterleaveTrack(short *,
                                                   long,
                                                   short * *(long)) */

void mixInterleaveTrack(short *param_1,long param_2,FuncDef566 *param_3)

{
  int iVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  
  psVar3 = (*param_3)(param_2);
  if ((psVar3 != (short *)0x0) && (iVar4 = param_2 << 1, 0 < iVar4)) {
    do {
      iVar1 = (int)*param_1 + (int)*psVar3;
      if (iVar1 < -0x8000) {
        sVar2 = -0x7fff;
      }
      else {
        if (iVar1 < 0x8000) {
          sVar2 = (short)iVar1;
        }
        else {
          sVar2 = 0x7fff;
        }
      }
      *param_1 = sVar2;
      param_1 = param_1 + 1;
      psVar3 = psVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}

