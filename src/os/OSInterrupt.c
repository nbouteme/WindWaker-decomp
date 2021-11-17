#include <os/OSInterrupt.h>
#include <os/OSInterrupt.h>
#include <os/OS.h>
#include <os/OSContext.h>
#include <os/OSTime.h>
#include <os/OSThread.h>


namespace os {
undefined4 InterruptHandlerTable;
undefined4 __OSLastInterruptSrr0;
undefined2 __OSLastInterrupt;
undefined4 __OSLastInterruptTime;

ulonglong OSDisableInterrupts(void)

{
  uint in_MSR;
  
  return CONCAT44(in_MSR >> 0xf,in_MSR) & 0x1ffff7fff;
}


ulonglong OSEnableInterrupts(void)

{
  uint in_MSR;
  
  return CONCAT44(in_MSR >> 0xf,in_MSR) & 0x1ffffffff | 0x8000;
}


uint OSRestoreInterrupts(void)

{
  uint in_MSR;
  
  return in_MSR >> 0xf & 1;
}


undefined4 __OSSetInterruptHandler(short param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(InterruptHandlerTable + param_1 * 4);
  uVar1 = *puVar2;
  *puVar2 = param_2;
  return uVar1;
}


undefined4 __OSGetInterruptHandler(short param_1)

{
  return *(undefined4 *)(InterruptHandlerTable + param_1 * 4);
}


void __OSInterruptInit(void)

{
  InterruptHandlerTable = &DAT_80003040;
  FUN_800033a8((int)&DAT_80003040,0,0x80);
  DAT_800000c4 = 0;
  DAT_800000c8 = 0;
  DAT_cc003004 = 0xf0;
  __OSMaskInterrupts(0xffffffe0);
  __OSSetExceptionHandler(4,ExternalInterruptHandler);
  return;
}


uint SetInterruptMask(uint param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = countLeadingZeros(param_1);
  if (iVar1 < 0xc) {
    if (iVar1 == 8) {
      DAT_cc006c00 = DAT_cc006c00 & 0xffffffd3;
      if ((param_2 & 0x800000) == 0) {
        DAT_cc006c00 = DAT_cc006c00 | 4;
      }
      param_1 = param_1 & 0xff7fffff;
    }
    else {
      if (iVar1 < 8) {
        if (iVar1 < 5) {
          if (-1 < iVar1) {
            DAT_cc00401c = (ushort)((param_2 & 0x80000000) == 0);
            if ((param_2 & 0x40000000) == 0) {
              DAT_cc00401c = DAT_cc00401c | 2;
            }
            if ((param_2 & 0x20000000) == 0) {
              DAT_cc00401c = DAT_cc00401c | 4;
            }
            if ((param_2 & 0x10000000) == 0) {
              DAT_cc00401c = DAT_cc00401c | 8;
            }
            if ((param_2 & 0x8000000) == 0) {
              DAT_cc00401c = DAT_cc00401c | 0x10;
            }
            param_1 = param_1 & 0x7ffffff;
          }
        }
        else {
          DAT_cc00500a = DAT_cc00500a & 0xfe07;
          if ((param_2 & 0x4000000) == 0) {
            DAT_cc00500a = DAT_cc00500a | 0x10;
          }
          if ((param_2 & 0x2000000) == 0) {
            DAT_cc00500a = DAT_cc00500a | 0x40;
          }
          if ((param_2 & 0x1000000) == 0) {
            DAT_cc00500a = DAT_cc00500a | 0x100;
          }
          param_1 = param_1 & 0xf8ffffff;
        }
      }
      else {
        DAT_cc006800 = DAT_cc006800 & 0xffffd3f0;
        if ((param_2 & 0x400000) == 0) {
          DAT_cc006800 = DAT_cc006800 | 1;
        }
        if ((param_2 & 0x200000) == 0) {
          DAT_cc006800 = DAT_cc006800 | 4;
        }
        if ((param_2 & 0x100000) == 0) {
          DAT_cc006800 = DAT_cc006800 | 0x400;
        }
        param_1 = param_1 & 0xff8fffff;
      }
    }
  }
  else {
    if (iVar1 < 0x11) {
      if (iVar1 < 0xf) {
        DAT_cc006814 = DAT_cc006814 & 0xfffff3f0;
        if ((param_2 & 0x80000) == 0) {
          DAT_cc006814 = DAT_cc006814 | 1;
        }
        if ((param_2 & 0x40000) == 0) {
          DAT_cc006814 = DAT_cc006814 | 4;
        }
        if ((param_2 & 0x20000) == 0) {
          DAT_cc006814 = DAT_cc006814 | 0x400;
        }
        param_1 = param_1 & 0xfff1ffff;
      }
      else {
        DAT_cc006828 = DAT_cc006828 & 0xfffffff0;
        if ((param_2 & 0x10000) == 0) {
          DAT_cc006828 = DAT_cc006828 | 1;
        }
        if ((param_2 & 0x8000) == 0) {
          DAT_cc006828 = DAT_cc006828 | 4;
        }
        param_1 = param_1 & 0xfffe7fff;
      }
    }
    else {
      if (iVar1 < 0x1b) {
        DAT_cc003004 = 0xf0;
        if ((param_2 & 0x4000) == 0) {
          DAT_cc003004 = 0x8f0;
        }
        if ((param_2 & 0x800) == 0) {
          DAT_cc003004 = DAT_cc003004 | 8;
        }
        if ((param_2 & 0x400) == 0) {
          DAT_cc003004 = DAT_cc003004 | 4;
        }
        if ((param_2 & 0x200) == 0) {
          DAT_cc003004 = DAT_cc003004 | 2;
        }
        if ((param_2 & 0x100) == 0) {
          DAT_cc003004 = DAT_cc003004 | 1;
        }
        if ((param_2 & 0x80) == 0) {
          DAT_cc003004 = DAT_cc003004 | 0x100;
        }
        if ((param_2 & 0x40) == 0) {
          DAT_cc003004 = DAT_cc003004 | 0x1000;
        }
        if ((param_2 & 0x2000) == 0) {
          DAT_cc003004 = DAT_cc003004 | 0x200;
        }
        if ((param_2 & 0x1000) == 0) {
          DAT_cc003004 = DAT_cc003004 | 0x400;
        }
        if ((param_2 & 0x20) == 0) {
          DAT_cc003004 = DAT_cc003004 | 0x2000;
        }
        param_1 = param_1 & 0xffff801f;
      }
    }
  }
  return param_1;
}


uint __OSMaskInterrupts(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar3 = OSDisableInterrupts();
  uVar1 = DAT_800000c4;
  uVar2 = DAT_800000c4 | DAT_800000c8;
  DAT_800000c4 = param_1 | DAT_800000c4;
  uVar4 = DAT_800000c4 | DAT_800000c8;
  for (param_1 = param_1 & ~uVar2; param_1 != 0; param_1 = SetInterruptMask(param_1,uVar4)) {
  }
  OSRestoreInterrupts(uVar3);
  return uVar1;
}


uint __OSUnmaskInterrupts(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar3 = OSDisableInterrupts();
  uVar1 = DAT_800000c4;
  uVar2 = DAT_800000c4 | DAT_800000c8;
  DAT_800000c4 = DAT_800000c4 & ~param_1;
  uVar4 = DAT_800000c4 | DAT_800000c8;
  for (param_1 = param_1 & uVar2; param_1 != 0; param_1 = SetInterruptMask(param_1,uVar4)) {
  }
  OSRestoreInterrupts(uVar3);
  return uVar1;
}


void __OSDispatchInterrupt(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 uVar4;
  int iVar5;
  code *pcVar6;
  
  uVar1 = DAT_cc003000;
  if (((DAT_cc003000 & 0xfffeffff) == 0) || ((DAT_cc003000 & 0xfffeffff & DAT_cc003004) == 0)) {
    OSLoadContext(param_2);
  }
  uVar2 = 0;
  if ((uVar1 & 0x80) != 0) {
    if ((DAT_cc00401e & 1) != 0) {
      uVar2 = 0x80000000;
    }
    if ((DAT_cc00401e & 2) != 0) {
      uVar2 = uVar2 | 0x40000000;
    }
    if ((DAT_cc00401e & 4) != 0) {
      uVar2 = uVar2 | 0x20000000;
    }
    if ((DAT_cc00401e & 8) != 0) {
      uVar2 = uVar2 | 0x10000000;
    }
    if ((DAT_cc00401e & 0x10) != 0) {
      uVar2 = uVar2 | 0x8000000;
    }
  }
  if ((uVar1 & 0x40) != 0) {
    if ((DAT_cc00500a & 8) != 0) {
      uVar2 = uVar2 | 0x4000000;
    }
    if ((DAT_cc00500a & 0x20) != 0) {
      uVar2 = uVar2 | 0x2000000;
    }
    if ((DAT_cc00500a & 0x80) != 0) {
      uVar2 = uVar2 | 0x1000000;
    }
  }
  if (((uVar1 & 0x20) != 0) && ((DAT_cc006c00 & 8) != 0)) {
    uVar2 = uVar2 | 0x800000;
  }
  if ((uVar1 & 0x10) != 0) {
    if ((DAT_cc006800 & 2) != 0) {
      uVar2 = uVar2 | 0x400000;
    }
    if ((DAT_cc006800 & 8) != 0) {
      uVar2 = uVar2 | 0x200000;
    }
    if ((DAT_cc006800 & 0x800) != 0) {
      uVar2 = uVar2 | 0x100000;
    }
    if ((DAT_cc006814 & 2) != 0) {
      uVar2 = uVar2 | 0x80000;
    }
    if ((DAT_cc006814 & 8) != 0) {
      uVar2 = uVar2 | 0x40000;
    }
    if ((DAT_cc006814 & 0x800) != 0) {
      uVar2 = uVar2 | 0x20000;
    }
    if ((DAT_cc006828 & 2) != 0) {
      uVar2 = uVar2 | 0x10000;
    }
    if ((DAT_cc006828 & 8) != 0) {
      uVar2 = uVar2 | 0x8000;
    }
  }
  if ((uVar1 & 0x2000) != 0) {
    uVar2 = uVar2 | 0x20;
  }
  if ((uVar1 & 0x1000) != 0) {
    uVar2 = uVar2 | 0x40;
  }
  if ((uVar1 & 0x400) != 0) {
    uVar2 = uVar2 | 0x1000;
  }
  if ((uVar1 & 0x200) != 0) {
    uVar2 = uVar2 | 0x2000;
  }
  if ((uVar1 & 0x100) != 0) {
    uVar2 = uVar2 | 0x80;
  }
  if ((uVar1 & 8) != 0) {
    uVar2 = uVar2 | 0x800;
  }
  if ((uVar1 & 4) != 0) {
    uVar2 = uVar2 | 0x400;
  }
  if ((uVar1 & 2) != 0) {
    uVar2 = uVar2 | 0x200;
  }
  if ((uVar1 & 0x800) != 0) {
    uVar2 = uVar2 | 0x4000;
  }
  if ((uVar1 & 1) != 0) {
    uVar2 = uVar2 | 0x100;
  }
  uVar2 = uVar2 & ~(DAT_800000c4 | DAT_800000c8);
  if (uVar2 != 0) {
    for (puVar3 = &InterruptPrioTable; (uVar2 & *puVar3) == 0; puVar3 = puVar3 + 1) {
    }
    uVar4 = countLeadingZeros(uVar2 & *puVar3);
    iVar5 = (int)(short)uVar4;
    pcVar6 = *(code **)(InterruptHandlerTable + iVar5 * 4);
    if (pcVar6 != (code *)0x0) {
      if (4 < iVar5) {
        __OSLastInterrupt = (short)uVar4;
        __OSLastInterruptTime = OSGetTime();
        __OSLastInterruptSrr0 = *(undefined4 *)(param_2 + 0x198);
        DAT_803f79f4 = uVar2;
      }
      OSDisableScheduler();
      (*pcVar6)(iVar5,param_2);
      OSEnableScheduler();
      __OSReschedule();
      OSLoadContext(param_2);
    }
  }
  OSLoadContext(param_2);
  return;
}


void ExternalInterruptHandler
               (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 in_r0;
  undefined4 in_r11;
  undefined4 in_r12;
  undefined4 unaff_r14;
  undefined4 unaff_r15;
  undefined4 unaff_r16;
  undefined4 unaff_r17;
  undefined4 unaff_r18;
  undefined4 unaff_r19;
  undefined4 unaff_r20;
  undefined4 unaff_r21;
  undefined4 unaff_r22;
  undefined4 unaff_r23;
  undefined4 unaff_r24;
  undefined4 unaff_r25;
  undefined4 unaff_r26;
  undefined4 unaff_r27;
  undefined4 unaff_r28;
  undefined4 unaff_r29;
  undefined4 unaff_r30;
  undefined4 unaff_r31;
  undefined4 in_GQR1;
  undefined4 in_GQR7;
  
  *param_2 = in_r0;
  param_2[1] = register0x00000004;
  param_2[2] = 0x803ffd00;
  param_2[6] = param_4;
  param_2[7] = param_5;
  param_2[8] = param_6;
  param_2[9] = param_7;
  param_2[10] = param_8;
  param_2[0xb] = in_r11;
  param_2[0xc] = in_r12;
  param_2[0xd] = 0x803fe0e0;
  param_2[0xe] = unaff_r14;
  param_2[0xf] = unaff_r15;
  param_2[0x10] = unaff_r16;
  param_2[0x11] = unaff_r17;
  param_2[0x12] = unaff_r18;
  param_2[0x13] = unaff_r19;
  param_2[0x14] = unaff_r20;
  param_2[0x15] = unaff_r21;
  param_2[0x16] = unaff_r22;
  param_2[0x17] = unaff_r23;
  param_2[0x18] = unaff_r24;
  param_2[0x19] = unaff_r25;
  param_2[0x1a] = unaff_r26;
  param_2[0x1b] = unaff_r27;
  param_2[0x1c] = unaff_r28;
  param_2[0x1d] = unaff_r29;
  param_2[0x1e] = unaff_r30;
  param_2[0x1f] = unaff_r31;
  param_2[0x6a] = in_GQR1;
  param_2[0x6b] = 0x40004;
  param_2[0x6c] = 0x50005;
  param_2[0x6d] = 0x60006;
  param_2[0x6e] = 0x70007;
  param_2[0x6f] = 0x3d043d04;
  param_2[0x70] = in_GQR7;
  __OSDispatchInterrupt();
  return;
}

