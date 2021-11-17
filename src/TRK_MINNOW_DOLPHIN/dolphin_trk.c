#include <TRK_MINNOW_DOLPHIN/dolphin_trk.h>
#include <TRK_MINNOW_DOLPHIN/mpc_7xx_603e.h>
#include <TRK_MINNOW_DOLPHIN/dolphin_trk_glue.h>
#include <TRK_MINNOW_DOLPHIN/main_TRK.h>
#include <TRK_MINNOW_DOLPHIN/targimpl.h>


namespace TRK_MINNOW_DOLPHIN {
undefined4 lc_base;

/* WARNING: This function may have set the stack pointer */

undefined8
InitMetroTRK
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 in_r0;
  int iVar1;
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
  uint in_MSR;
  byte in_cr0;
  byte in_cr1;
  byte in_cr2;
  byte in_cr3;
  byte unaff_cr4;
  byte in_cr5;
  byte in_cr6;
  byte in_cr7;
  undefined4 in_LR;
  undefined8 uVar2;
  
  DAT_803f39b8 = 0x803ffd00;
  DAT_803f39e4 = 0x803fe0e0;
  DAT_803f3a38 = (uint)(in_cr0 & 0xf) << 0x1c | (uint)(in_cr1 & 0xf) << 0x18 |
                 (uint)(in_cr2 & 0xf) << 0x14 | (uint)(in_cr3 & 0xf) << 0x10 |
                 (uint)(unaff_cr4 & 0xf) << 0xc | (uint)(in_cr5 & 0xf) << 8 |
                 (uint)(in_cr6 & 0xf) << 4 | (uint)(in_cr7 & 0xf);
  gTRKCPUState = in_r0;
  DAT_803f39b4 = (undefined *)register0x00000004;
  DAT_803f39bc = param_1;
  DAT_803f39c0 = param_2;
  DAT_803f39c4 = param_3;
  DAT_803f39c8 = param_4;
  DAT_803f39cc = param_5;
  DAT_803f39d0 = param_6;
  DAT_803f39d4 = param_7;
  DAT_803f39d8 = param_8;
  DAT_803f39dc = in_r11;
  DAT_803f39e0 = in_r12;
  DAT_803f39e8 = unaff_r14;
  DAT_803f39ec = unaff_r15;
  DAT_803f39f0 = unaff_r16;
  DAT_803f39f4 = unaff_r17;
  DAT_803f39f8 = unaff_r18;
  DAT_803f39fc = unaff_r19;
  DAT_803f3a00 = unaff_r20;
  DAT_803f3a04 = unaff_r21;
  DAT_803f3a08 = unaff_r22;
  DAT_803f3a0c = unaff_r23;
  DAT_803f3a10 = unaff_r24;
  DAT_803f3a14 = unaff_r25;
  DAT_803f3a18 = unaff_r26;
  DAT_803f3a1c = unaff_r27;
  DAT_803f3a20 = unaff_r28;
  DAT_803f3a24 = unaff_r29;
  DAT_803f3a28 = unaff_r30;
  DAT_803f3a2c = unaff_r31;
  DAT_803f3a30 = in_LR;
  DAT_803f3a34 = in_LR;
  TRKSaveExtended1Block((in_MSR | 0x8000) ^ 0x8000);
  iVar1 = InitMetroTRKCommTable
                    (DAT_803f39c4,DAT_803f39c0,DAT_803f39c4,DAT_803f39c8,DAT_803f39cc,DAT_803f39d0,
                     DAT_803f39d4,DAT_803f39d8);
  if (iVar1 == 1) {
    return uRam0000000d;
  }
  uVar2 = TRK_main();
  return uVar2;
}


undefined4 TRKInitializeTarget(void)

{
  DAT_803f39a4 = 1;
  DAT_803f3998 = __TRK_get_MSR();
  lc_base = 0xe0000000;
  return 0;
}


uint TRKTargetTranslate(uint param_1)

{
  if (lc_base <= param_1) {
    if ((param_1 < lc_base + 0x4000) && ((DAT_803f3be8 & 3) != 0)) {
      return param_1;
    }
  }
  return param_1 & 0x3fffffff | 0x80000000;
}


void EnableMetroTRKInterrupts(void)

{
  EnableEXI2Interrupts();
  return;
}

