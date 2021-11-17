#include <Runtime.PPCEABI.H/runtime.h>


namespace Runtime.PPCEABI.H {

int __cvt_fp2unsigned(double param_1)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = 0;
  if ((__constants <= param_1) && (iVar1 = -1, param_1 < DAT_80370fd0)) {
    bVar2 = DAT_80370fd8 <= param_1;
    if (bVar2) {
      param_1 = param_1 - DAT_80370fd8;
    }
    iVar1 = (int)param_1;
    if (bVar2) {
      iVar1 = iVar1 + -0x80000000;
    }
  }
  return iVar1;
}


void __save_fpr(void)

{
  int in_r11;
  undefined8 in_f14;
  undefined8 in_f15;
  undefined8 in_f16;
  undefined8 in_f17;
  undefined8 in_f18;
  undefined8 in_f19;
  undefined8 in_f20;
  undefined8 in_f21;
  undefined8 in_f22;
  undefined8 in_f23;
  undefined8 in_f24;
  undefined8 in_f25;
  undefined8 in_f26;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  
  *(undefined8 *)(in_r11 + -0x90) = in_f14;
  *(undefined8 *)(in_r11 + -0x88) = in_f15;
  *(undefined8 *)(in_r11 + -0x80) = in_f16;
  *(undefined8 *)(in_r11 + -0x78) = in_f17;
  *(undefined8 *)(in_r11 + -0x70) = in_f18;
  *(undefined8 *)(in_r11 + -0x68) = in_f19;
  *(undefined8 *)(in_r11 + -0x60) = in_f20;
  *(undefined8 *)(in_r11 + -0x58) = in_f21;
  *(undefined8 *)(in_r11 + -0x50) = in_f22;
  *(undefined8 *)(in_r11 + -0x48) = in_f23;
  *(undefined8 *)(in_r11 + -0x40) = in_f24;
  *(undefined8 *)(in_r11 + -0x38) = in_f25;
  *(undefined8 *)(in_r11 + -0x30) = in_f26;
  *(undefined8 *)(in_r11 + -0x28) = in_f27;
  *(undefined8 *)(in_r11 + -0x20) = in_f28;
  *(undefined8 *)(in_r11 + -0x18) = in_f29;
  *(undefined8 *)(in_r11 + -0x10) = in_f30;
  *(undefined8 *)(in_r11 + -8) = in_f31;
  return;
}

}

void FUN_80328e98(void)

{
  int in_r11;
  undefined8 in_f25;
  undefined8 in_f26;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  
  *(undefined8 *)(in_r11 + -0x38) = in_f25;
  *(undefined8 *)(in_r11 + -0x30) = in_f26;
  *(undefined8 *)(in_r11 + -0x28) = in_f27;
  *(undefined8 *)(in_r11 + -0x20) = in_f28;
  *(undefined8 *)(in_r11 + -0x18) = in_f29;
  *(undefined8 *)(in_r11 + -0x10) = in_f30;
  *(undefined8 *)(in_r11 + -8) = in_f31;
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328e9c(void)

{
  int in_r11;
  undefined8 in_f26;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  
  *(undefined8 *)(in_r11 + -0x30) = in_f26;
  *(undefined8 *)(in_r11 + -0x28) = in_f27;
  *(undefined8 *)(in_r11 + -0x20) = in_f28;
  *(undefined8 *)(in_r11 + -0x18) = in_f29;
  *(undefined8 *)(in_r11 + -0x10) = in_f30;
  *(undefined8 *)(in_r11 + -8) = in_f31;
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328ea4(void)

{
  int in_r11;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  
  *(undefined8 *)(in_r11 + -0x20) = in_f28;
  *(undefined8 *)(in_r11 + -0x18) = in_f29;
  *(undefined8 *)(in_r11 + -0x10) = in_f30;
  *(undefined8 *)(in_r11 + -8) = in_f31;
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328ea8(void)

{
  int in_r11;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  
  *(undefined8 *)(in_r11 + -0x18) = in_f29;
  *(undefined8 *)(in_r11 + -0x10) = in_f30;
  *(undefined8 *)(in_r11 + -8) = in_f31;
  return;
}


namespace Runtime.PPCEABI.H {

void __restore_fpr(void)

{
  return;
}

}

void FUN_80328ee4(void)

{
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328ee8(void)

{
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328ef0(void)

{
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328ef4(void)

{
  return;
}


namespace Runtime.PPCEABI.H {

/* WARNING: This is an inlined function */

void __save_gpr(void)

{
  int in_r11;
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
  
  *(undefined4 *)(in_r11 + -0x48) = unaff_r14;
  *(undefined4 *)(in_r11 + -0x44) = unaff_r15;
  *(undefined4 *)(in_r11 + -0x40) = unaff_r16;
  *(undefined4 *)(in_r11 + -0x3c) = unaff_r17;
  *(undefined4 *)(in_r11 + -0x38) = unaff_r18;
  *(undefined4 *)(in_r11 + -0x34) = unaff_r19;
  *(undefined4 *)(in_r11 + -0x30) = unaff_r20;
  *(undefined4 *)(in_r11 + -0x2c) = unaff_r21;
  *(undefined4 *)(in_r11 + -0x28) = unaff_r22;
  *(undefined4 *)(in_r11 + -0x24) = unaff_r23;
  *(undefined4 *)(in_r11 + -0x20) = unaff_r24;
  *(undefined4 *)(in_r11 + -0x1c) = unaff_r25;
  *(undefined4 *)(in_r11 + -0x18) = unaff_r26;
  *(undefined4 *)(in_r11 + -0x14) = unaff_r27;
  *(undefined4 *)(in_r11 + -0x10) = unaff_r28;
  *(undefined4 *)(in_r11 + -0xc) = unaff_r29;
  *(undefined4 *)(in_r11 + -8) = unaff_r30;
  *(undefined4 *)(in_r11 + -4) = unaff_r31;
  return;
}

}

/* WARNING: This is an inlined function */

void FUN_80328f08(void)

{
  int in_r11;
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
  
  *(undefined4 *)(in_r11 + -0x44) = unaff_r15;
  *(undefined4 *)(in_r11 + -0x40) = unaff_r16;
  *(undefined4 *)(in_r11 + -0x3c) = unaff_r17;
  *(undefined4 *)(in_r11 + -0x38) = unaff_r18;
  *(undefined4 *)(in_r11 + -0x34) = unaff_r19;
  *(undefined4 *)(in_r11 + -0x30) = unaff_r20;
  *(undefined4 *)(in_r11 + -0x2c) = unaff_r21;
  *(undefined4 *)(in_r11 + -0x28) = unaff_r22;
  *(undefined4 *)(in_r11 + -0x24) = unaff_r23;
  *(undefined4 *)(in_r11 + -0x20) = unaff_r24;
  *(undefined4 *)(in_r11 + -0x1c) = unaff_r25;
  *(undefined4 *)(in_r11 + -0x18) = unaff_r26;
  *(undefined4 *)(in_r11 + -0x14) = unaff_r27;
  *(undefined4 *)(in_r11 + -0x10) = unaff_r28;
  *(undefined4 *)(in_r11 + -0xc) = unaff_r29;
  *(undefined4 *)(in_r11 + -8) = unaff_r30;
  *(undefined4 *)(in_r11 + -4) = unaff_r31;
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f0c(void)

{
  int in_r11;
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
  
  *(undefined4 *)(in_r11 + -0x40) = unaff_r16;
  *(undefined4 *)(in_r11 + -0x3c) = unaff_r17;
  *(undefined4 *)(in_r11 + -0x38) = unaff_r18;
  *(undefined4 *)(in_r11 + -0x34) = unaff_r19;
  *(undefined4 *)(in_r11 + -0x30) = unaff_r20;
  *(undefined4 *)(in_r11 + -0x2c) = unaff_r21;
  *(undefined4 *)(in_r11 + -0x28) = unaff_r22;
  *(undefined4 *)(in_r11 + -0x24) = unaff_r23;
  *(undefined4 *)(in_r11 + -0x20) = unaff_r24;
  *(undefined4 *)(in_r11 + -0x1c) = unaff_r25;
  *(undefined4 *)(in_r11 + -0x18) = unaff_r26;
  *(undefined4 *)(in_r11 + -0x14) = unaff_r27;
  *(undefined4 *)(in_r11 + -0x10) = unaff_r28;
  *(undefined4 *)(in_r11 + -0xc) = unaff_r29;
  *(undefined4 *)(in_r11 + -8) = unaff_r30;
  *(undefined4 *)(in_r11 + -4) = unaff_r31;
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f10(void)

{
  int in_r11;
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
  
  *(undefined4 *)(in_r11 + -0x3c) = unaff_r17;
  *(undefined4 *)(in_r11 + -0x38) = unaff_r18;
  *(undefined4 *)(in_r11 + -0x34) = unaff_r19;
  *(undefined4 *)(in_r11 + -0x30) = unaff_r20;
  *(undefined4 *)(in_r11 + -0x2c) = unaff_r21;
  *(undefined4 *)(in_r11 + -0x28) = unaff_r22;
  *(undefined4 *)(in_r11 + -0x24) = unaff_r23;
  *(undefined4 *)(in_r11 + -0x20) = unaff_r24;
  *(undefined4 *)(in_r11 + -0x1c) = unaff_r25;
  *(undefined4 *)(in_r11 + -0x18) = unaff_r26;
  *(undefined4 *)(in_r11 + -0x14) = unaff_r27;
  *(undefined4 *)(in_r11 + -0x10) = unaff_r28;
  *(undefined4 *)(in_r11 + -0xc) = unaff_r29;
  *(undefined4 *)(in_r11 + -8) = unaff_r30;
  *(undefined4 *)(in_r11 + -4) = unaff_r31;
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f14(void)

{
  int in_r11;
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
  
  *(undefined4 *)(in_r11 + -0x38) = unaff_r18;
  *(undefined4 *)(in_r11 + -0x34) = unaff_r19;
  *(undefined4 *)(in_r11 + -0x30) = unaff_r20;
  *(undefined4 *)(in_r11 + -0x2c) = unaff_r21;
  *(undefined4 *)(in_r11 + -0x28) = unaff_r22;
  *(undefined4 *)(in_r11 + -0x24) = unaff_r23;
  *(undefined4 *)(in_r11 + -0x20) = unaff_r24;
  *(undefined4 *)(in_r11 + -0x1c) = unaff_r25;
  *(undefined4 *)(in_r11 + -0x18) = unaff_r26;
  *(undefined4 *)(in_r11 + -0x14) = unaff_r27;
  *(undefined4 *)(in_r11 + -0x10) = unaff_r28;
  *(undefined4 *)(in_r11 + -0xc) = unaff_r29;
  *(undefined4 *)(in_r11 + -8) = unaff_r30;
  *(undefined4 *)(in_r11 + -4) = unaff_r31;
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f18(void)

{
  int in_r11;
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
  
  *(undefined4 *)(in_r11 + -0x34) = unaff_r19;
  *(undefined4 *)(in_r11 + -0x30) = unaff_r20;
  *(undefined4 *)(in_r11 + -0x2c) = unaff_r21;
  *(undefined4 *)(in_r11 + -0x28) = unaff_r22;
  *(undefined4 *)(in_r11 + -0x24) = unaff_r23;
  *(undefined4 *)(in_r11 + -0x20) = unaff_r24;
  *(undefined4 *)(in_r11 + -0x1c) = unaff_r25;
  *(undefined4 *)(in_r11 + -0x18) = unaff_r26;
  *(undefined4 *)(in_r11 + -0x14) = unaff_r27;
  *(undefined4 *)(in_r11 + -0x10) = unaff_r28;
  *(undefined4 *)(in_r11 + -0xc) = unaff_r29;
  *(undefined4 *)(in_r11 + -8) = unaff_r30;
  *(undefined4 *)(in_r11 + -4) = unaff_r31;
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f1c(void)

{
  int in_r11;
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
  
  *(undefined4 *)(in_r11 + -0x30) = unaff_r20;
  *(undefined4 *)(in_r11 + -0x2c) = unaff_r21;
  *(undefined4 *)(in_r11 + -0x28) = unaff_r22;
  *(undefined4 *)(in_r11 + -0x24) = unaff_r23;
  *(undefined4 *)(in_r11 + -0x20) = unaff_r24;
  *(undefined4 *)(in_r11 + -0x1c) = unaff_r25;
  *(undefined4 *)(in_r11 + -0x18) = unaff_r26;
  *(undefined4 *)(in_r11 + -0x14) = unaff_r27;
  *(undefined4 *)(in_r11 + -0x10) = unaff_r28;
  *(undefined4 *)(in_r11 + -0xc) = unaff_r29;
  *(undefined4 *)(in_r11 + -8) = unaff_r30;
  *(undefined4 *)(in_r11 + -4) = unaff_r31;
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f20(void)

{
  int in_r11;
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
  
  *(undefined4 *)(in_r11 + -0x2c) = unaff_r21;
  *(undefined4 *)(in_r11 + -0x28) = unaff_r22;
  *(undefined4 *)(in_r11 + -0x24) = unaff_r23;
  *(undefined4 *)(in_r11 + -0x20) = unaff_r24;
  *(undefined4 *)(in_r11 + -0x1c) = unaff_r25;
  *(undefined4 *)(in_r11 + -0x18) = unaff_r26;
  *(undefined4 *)(in_r11 + -0x14) = unaff_r27;
  *(undefined4 *)(in_r11 + -0x10) = unaff_r28;
  *(undefined4 *)(in_r11 + -0xc) = unaff_r29;
  *(undefined4 *)(in_r11 + -8) = unaff_r30;
  *(undefined4 *)(in_r11 + -4) = unaff_r31;
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f24(void)

{
  int in_r11;
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
  
  *(undefined4 *)(in_r11 + -0x28) = unaff_r22;
  *(undefined4 *)(in_r11 + -0x24) = unaff_r23;
  *(undefined4 *)(in_r11 + -0x20) = unaff_r24;
  *(undefined4 *)(in_r11 + -0x1c) = unaff_r25;
  *(undefined4 *)(in_r11 + -0x18) = unaff_r26;
  *(undefined4 *)(in_r11 + -0x14) = unaff_r27;
  *(undefined4 *)(in_r11 + -0x10) = unaff_r28;
  *(undefined4 *)(in_r11 + -0xc) = unaff_r29;
  *(undefined4 *)(in_r11 + -8) = unaff_r30;
  *(undefined4 *)(in_r11 + -4) = unaff_r31;
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f28(void)

{
  int in_r11;
  undefined4 unaff_r23;
  undefined4 unaff_r24;
  undefined4 unaff_r25;
  undefined4 unaff_r26;
  undefined4 unaff_r27;
  undefined4 unaff_r28;
  undefined4 unaff_r29;
  undefined4 unaff_r30;
  undefined4 unaff_r31;
  
  *(undefined4 *)(in_r11 + -0x24) = unaff_r23;
  *(undefined4 *)(in_r11 + -0x20) = unaff_r24;
  *(undefined4 *)(in_r11 + -0x1c) = unaff_r25;
  *(undefined4 *)(in_r11 + -0x18) = unaff_r26;
  *(undefined4 *)(in_r11 + -0x14) = unaff_r27;
  *(undefined4 *)(in_r11 + -0x10) = unaff_r28;
  *(undefined4 *)(in_r11 + -0xc) = unaff_r29;
  *(undefined4 *)(in_r11 + -8) = unaff_r30;
  *(undefined4 *)(in_r11 + -4) = unaff_r31;
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f2c(void)

{
  int in_r11;
  undefined4 unaff_r24;
  undefined4 unaff_r25;
  undefined4 unaff_r26;
  undefined4 unaff_r27;
  undefined4 unaff_r28;
  undefined4 unaff_r29;
  undefined4 unaff_r30;
  undefined4 unaff_r31;
  
  *(undefined4 *)(in_r11 + -0x20) = unaff_r24;
  *(undefined4 *)(in_r11 + -0x1c) = unaff_r25;
  *(undefined4 *)(in_r11 + -0x18) = unaff_r26;
  *(undefined4 *)(in_r11 + -0x14) = unaff_r27;
  *(undefined4 *)(in_r11 + -0x10) = unaff_r28;
  *(undefined4 *)(in_r11 + -0xc) = unaff_r29;
  *(undefined4 *)(in_r11 + -8) = unaff_r30;
  *(undefined4 *)(in_r11 + -4) = unaff_r31;
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f30(void)

{
  int in_r11;
  undefined4 unaff_r25;
  undefined4 unaff_r26;
  undefined4 unaff_r27;
  undefined4 unaff_r28;
  undefined4 unaff_r29;
  undefined4 unaff_r30;
  undefined4 unaff_r31;
  
  *(undefined4 *)(in_r11 + -0x1c) = unaff_r25;
  *(undefined4 *)(in_r11 + -0x18) = unaff_r26;
  *(undefined4 *)(in_r11 + -0x14) = unaff_r27;
  *(undefined4 *)(in_r11 + -0x10) = unaff_r28;
  *(undefined4 *)(in_r11 + -0xc) = unaff_r29;
  *(undefined4 *)(in_r11 + -8) = unaff_r30;
  *(undefined4 *)(in_r11 + -4) = unaff_r31;
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f34(void)

{
  int in_r11;
  undefined4 unaff_r26;
  undefined4 unaff_r27;
  undefined4 unaff_r28;
  undefined4 unaff_r29;
  undefined4 unaff_r30;
  undefined4 unaff_r31;
  
  *(undefined4 *)(in_r11 + -0x18) = unaff_r26;
  *(undefined4 *)(in_r11 + -0x14) = unaff_r27;
  *(undefined4 *)(in_r11 + -0x10) = unaff_r28;
  *(undefined4 *)(in_r11 + -0xc) = unaff_r29;
  *(undefined4 *)(in_r11 + -8) = unaff_r30;
  *(undefined4 *)(in_r11 + -4) = unaff_r31;
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f38(void)

{
  int in_r11;
  undefined4 unaff_r27;
  undefined4 unaff_r28;
  undefined4 unaff_r29;
  undefined4 unaff_r30;
  undefined4 unaff_r31;
  
  *(undefined4 *)(in_r11 + -0x14) = unaff_r27;
  *(undefined4 *)(in_r11 + -0x10) = unaff_r28;
  *(undefined4 *)(in_r11 + -0xc) = unaff_r29;
  *(undefined4 *)(in_r11 + -8) = unaff_r30;
  *(undefined4 *)(in_r11 + -4) = unaff_r31;
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f3c(void)

{
  int in_r11;
  undefined4 unaff_r28;
  undefined4 unaff_r29;
  undefined4 unaff_r30;
  undefined4 unaff_r31;
  
  *(undefined4 *)(in_r11 + -0x10) = unaff_r28;
  *(undefined4 *)(in_r11 + -0xc) = unaff_r29;
  *(undefined4 *)(in_r11 + -8) = unaff_r30;
  *(undefined4 *)(in_r11 + -4) = unaff_r31;
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f40(void)

{
  int in_r11;
  undefined4 unaff_r29;
  undefined4 unaff_r30;
  undefined4 unaff_r31;
  
  *(undefined4 *)(in_r11 + -0xc) = unaff_r29;
  *(undefined4 *)(in_r11 + -8) = unaff_r30;
  *(undefined4 *)(in_r11 + -4) = unaff_r31;
  return;
}


namespace Runtime.PPCEABI.H {

/* WARNING: This is an inlined function */

void __restore_gpr(void)

{
  return;
}

}

/* WARNING: This is an inlined function */

void FUN_80328f54(void)

{
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f58(void)

{
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f5c(void)

{
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f60(void)

{
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f64(void)

{
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f68(void)

{
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f6c(void)

{
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f70(void)

{
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f74(void)

{
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f78(void)

{
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f7c(void)

{
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f80(void)

{
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f84(void)

{
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f88(void)

{
  return;
}


/* WARNING: This is an inlined function */

void FUN_80328f8c(void)

{
  return;
}


namespace Runtime.PPCEABI.H {

undefined8 __div2u(uint param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  bool bVar12;
  
  iVar3 = countLeadingZeros(param_1);
  iVar8 = countLeadingZeros(param_2);
  if (param_1 == 0) {
    iVar3 = iVar8 + 0x20;
  }
  iVar8 = countLeadingZeros(param_3);
  iVar10 = countLeadingZeros(param_4);
  if (param_3 == 0) {
    iVar8 = iVar10 + 0x20;
  }
  if (iVar3 <= iVar8) {
    iVar10 = 0x40 - (iVar8 + 1);
    iVar8 = iVar3 + iVar10;
    iVar10 = (0x40 - iVar3) - iVar10;
    if (iVar10 < 0x20) {
      uVar6 = param_2 >> iVar10 | param_1 << 0x20 - iVar10;
      uVar5 = param_1 >> iVar10;
    }
    else {
      uVar6 = param_1 >> iVar10 + -0x20;
      uVar5 = 0;
    }
    if (iVar8 < 0x20) {
      uVar4 = param_1 << iVar8 | param_2 >> 0x20 - iVar8;
      param_2 = param_2 << iVar8;
    }
    else {
      uVar4 = param_2 << iVar8 + -0x20;
      param_2 = 0;
    }
    bVar11 = false;
    do {
      bVar12 = CARRY4(param_2,(uint)bVar11);
      uVar1 = param_2 + bVar11;
      bVar11 = CARRY4(param_2,uVar1);
      param_2 = param_2 + uVar1;
      uVar1 = (uint)(bVar12 || bVar11);
      bVar12 = CARRY4(uVar4,uVar1);
      uVar1 = uVar4 + uVar1;
      bVar11 = CARRY4(uVar4,uVar1);
      uVar4 = uVar4 + uVar1;
      uVar1 = (uint)(bVar12 || bVar11);
      uVar2 = uVar6 + uVar1;
      uVar7 = uVar6 + uVar2;
      uVar1 = uVar5 * 2 + (uint)(CARRY4(uVar6,uVar1) || CARRY4(uVar6,uVar2));
      uVar2 = (uint)(uVar7 < param_4) + param_3;
      uVar9 = uVar1 - uVar2;
      uVar5 = uVar1;
      uVar6 = uVar7;
      if (-1 < (int)uVar9) {
        uVar5 = uVar9;
        uVar6 = uVar7 - param_4;
      }
      bVar11 = -1 < (int)uVar9 || uVar2 <= uVar1;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    uVar5 = param_2 + bVar11;
    return CONCAT44(uVar4 * 2 + (uint)(CARRY4(param_2,(uint)bVar11) || CARRY4(param_2,uVar5)),
                    param_2 + uVar5);
  }
  return 0;
}


undefined8 __div2i(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  bool bVar13;
  bool bVar14;
  
  uVar3 = param_1 & 0x80000000;
  if (uVar3 != 0) {
    bVar13 = param_2 != 0;
    param_2 = -param_2;
    param_1 = -(bVar13 + param_1);
  }
  uVar4 = param_3 & 0x80000000;
  if (uVar4 != 0) {
    bVar13 = param_4 != 0;
    param_4 = -param_4;
    param_3 = -(bVar13 + param_3);
  }
  iVar5 = countLeadingZeros(param_1);
  iVar10 = countLeadingZeros(param_2);
  if (param_1 == 0) {
    iVar5 = iVar10 + 0x20;
  }
  iVar10 = countLeadingZeros(param_3);
  iVar12 = countLeadingZeros(param_4);
  if (param_3 == 0) {
    iVar10 = iVar12 + 0x20;
  }
  if (iVar10 < iVar5) {
    iVar10 = 0;
    iVar5 = 0;
  }
  else {
    iVar12 = 0x40 - (iVar10 + 1);
    iVar10 = iVar5 + iVar12;
    iVar12 = (0x40 - iVar5) - iVar12;
    if (iVar12 < 0x20) {
      uVar8 = param_2 >> iVar12 | param_1 << 0x20 - iVar12;
      uVar7 = param_1 >> iVar12;
    }
    else {
      uVar8 = param_1 >> iVar12 + -0x20;
      uVar7 = 0;
    }
    if (iVar10 < 0x20) {
      uVar6 = param_1 << iVar10 | param_2 >> 0x20 - iVar10;
      param_2 = param_2 << iVar10;
    }
    else {
      uVar6 = param_2 << iVar10 + -0x20;
      param_2 = 0;
    }
    bVar13 = false;
    do {
      bVar14 = CARRY4(param_2,(uint)bVar13);
      uVar1 = param_2 + bVar13;
      bVar13 = CARRY4(param_2,uVar1);
      param_2 = param_2 + uVar1;
      uVar1 = (uint)(bVar14 || bVar13);
      bVar14 = CARRY4(uVar6,uVar1);
      uVar1 = uVar6 + uVar1;
      bVar13 = CARRY4(uVar6,uVar1);
      uVar6 = uVar6 + uVar1;
      uVar1 = (uint)(bVar14 || bVar13);
      uVar2 = uVar8 + uVar1;
      uVar9 = uVar8 + uVar2;
      uVar1 = uVar7 * 2 + (uint)(CARRY4(uVar8,uVar1) || CARRY4(uVar8,uVar2));
      uVar2 = (uVar9 < param_4) + param_3;
      uVar11 = uVar1 - uVar2;
      uVar7 = uVar1;
      uVar8 = uVar9;
      if (-1 < (int)uVar11) {
        uVar7 = uVar11;
        uVar8 = uVar9 - param_4;
      }
      bVar13 = -1 < (int)uVar11 || uVar2 <= uVar1;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
    uVar7 = param_2 + bVar13;
    iVar10 = param_2 + uVar7;
    iVar5 = uVar6 * 2 + (uint)(CARRY4(param_2,(uint)bVar13) || CARRY4(param_2,uVar7));
    if (uVar3 != uVar4) {
      bVar13 = iVar10 != 0;
      iVar10 = -iVar10;
      iVar5 = -((uint)bVar13 + iVar5);
    }
  }
  return CONCAT44(iVar5,iVar10);
}


undefined8 __mod2u(uint param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  bool bVar12;
  
  iVar3 = countLeadingZeros(param_1);
  iVar8 = countLeadingZeros(param_2);
  if (param_1 == 0) {
    iVar3 = iVar8 + 0x20;
  }
  iVar8 = countLeadingZeros(param_3);
  iVar10 = countLeadingZeros(param_4);
  if (param_3 == 0) {
    iVar8 = iVar10 + 0x20;
  }
  if (iVar8 < iVar3) {
    return CONCAT44(param_1,param_2);
  }
  iVar10 = 0x40 - (iVar8 + 1);
  iVar8 = iVar3 + iVar10;
  iVar10 = (0x40 - iVar3) - iVar10;
  if (iVar10 < 0x20) {
    uVar6 = param_2 >> iVar10 | param_1 << 0x20 - iVar10;
    uVar5 = param_1 >> iVar10;
  }
  else {
    uVar6 = param_1 >> iVar10 + -0x20;
    uVar5 = 0;
  }
  if (iVar8 < 0x20) {
    uVar4 = param_1 << iVar8 | param_2 >> 0x20 - iVar8;
    param_2 = param_2 << iVar8;
  }
  else {
    uVar4 = param_2 << iVar8 + -0x20;
    param_2 = 0;
  }
  bVar11 = false;
  do {
    bVar12 = CARRY4(param_2,(uint)bVar11);
    uVar1 = param_2 + bVar11;
    bVar11 = CARRY4(param_2,uVar1);
    param_2 = param_2 + uVar1;
    uVar1 = (uint)(bVar12 || bVar11);
    bVar12 = CARRY4(uVar4,uVar1);
    uVar1 = uVar4 + uVar1;
    bVar11 = CARRY4(uVar4,uVar1);
    uVar4 = uVar4 + uVar1;
    uVar1 = (uint)(bVar12 || bVar11);
    uVar2 = uVar6 + uVar1;
    uVar7 = uVar6 + uVar2;
    uVar1 = uVar5 * 2 + (uint)(CARRY4(uVar6,uVar1) || CARRY4(uVar6,uVar2));
    uVar2 = (uint)(uVar7 < param_4) + param_3;
    uVar9 = uVar1 - uVar2;
    uVar5 = uVar1;
    uVar6 = uVar7;
    if (-1 < (int)uVar9) {
      uVar5 = uVar9;
      uVar6 = uVar7 - param_4;
    }
    bVar11 = -1 < (int)uVar9 || uVar2 <= uVar1;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  return CONCAT44(uVar5,uVar6);
}


undefined8 __mod2i(uint param_1,uint param_2,int param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  bool bVar12;
  
  bVar1 = (int)param_1 < 0;
  if (bVar1) {
    bVar11 = param_2 != 0;
    param_2 = -param_2;
    param_1 = -(bVar11 + param_1);
  }
  if (param_3 < 0) {
    bVar11 = param_4 != 0;
    param_4 = -param_4;
    param_3 = -((uint)bVar11 + param_3);
  }
  iVar2 = countLeadingZeros(param_1);
  iVar8 = countLeadingZeros(param_2);
  if (param_1 == 0) {
    iVar2 = iVar8 + 0x20;
  }
  iVar8 = countLeadingZeros(param_3);
  iVar10 = countLeadingZeros(param_4);
  if (param_3 == 0) {
    iVar8 = iVar10 + 0x20;
  }
  if (iVar2 <= iVar8) {
    iVar10 = 0x40 - (iVar8 + 1);
    iVar8 = iVar2 + iVar10;
    iVar10 = (0x40 - iVar2) - iVar10;
    if (iVar10 < 0x20) {
      uVar6 = param_2 >> iVar10 | param_1 << 0x20 - iVar10;
      uVar5 = param_1 >> iVar10;
    }
    else {
      uVar6 = param_1 >> iVar10 + -0x20;
      uVar5 = 0;
    }
    if (iVar8 < 0x20) {
      uVar3 = param_1 << iVar8 | param_2 >> 0x20 - iVar8;
      uVar4 = param_2 << iVar8;
    }
    else {
      uVar3 = param_2 << iVar8 + -0x20;
      uVar4 = 0;
    }
    bVar11 = false;
    param_1 = uVar5;
    param_2 = uVar6;
    do {
      bVar12 = CARRY4(uVar4,(uint)bVar11);
      uVar5 = uVar4 + bVar11;
      bVar11 = CARRY4(uVar4,uVar5);
      uVar4 = uVar4 + uVar5;
      uVar5 = (uint)(bVar12 || bVar11);
      bVar12 = CARRY4(uVar3,uVar5);
      uVar5 = uVar3 + uVar5;
      bVar11 = CARRY4(uVar3,uVar5);
      uVar3 = uVar3 + uVar5;
      uVar5 = (uint)(bVar12 || bVar11);
      uVar6 = param_2 + uVar5;
      uVar7 = param_2 + uVar6;
      uVar5 = param_1 * 2 + (uint)(CARRY4(param_2,uVar5) || CARRY4(param_2,uVar6));
      uVar6 = (uint)(uVar7 < param_4) + param_3;
      uVar9 = uVar5 - uVar6;
      param_1 = uVar5;
      param_2 = uVar7;
      if (-1 < (int)uVar9) {
        param_1 = uVar9;
        param_2 = uVar7 - param_4;
      }
      bVar11 = -1 < (int)uVar9 || uVar6 <= uVar5;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  if (bVar1) {
    return CONCAT44(-((param_2 != 0) + param_1),-param_2);
  }
  return CONCAT44(param_1,param_2);
}


undefined8 __shl2i(int param_1,uint param_2,int param_3)

{
  return CONCAT44(param_1 << param_3 | param_2 >> 0x20 - param_3 | param_2 << param_3 + -0x20,
                  param_2 << param_3);
}


undefined8 __shr2u(uint param_1,uint param_2,int param_3)

{
  return CONCAT44(param_1 >> param_3,
                  param_2 >> param_3 | param_1 << 0x20 - param_3 | param_1 >> param_3 + -0x20);
}


undefined8 __shr2i(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = param_2 >> param_3 | param_1 << 0x20 - param_3;
  if (0 < (int)(param_3 - 0x20)) {
    uVar1 = uVar1 | param_1 >> (param_3 - 0x20 & 0x3f);
  }
  return CONCAT44(param_1 >> (param_3 & 0x3f),uVar1);
}


undefined8 __cvt_dbl_usll(ulonglong param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint local_8;
  uint uStack4;
  
  local_8 = (uint)(param_1 >> 0x20);
  uStack4 = (uint)param_1;
  uVar3 = local_8 >> 0x14 & 0x7ff;
  if (uVar3 < 0x3ff) {
    uVar2 = 0;
    uStack4 = 0;
  }
  else {
    uVar2 = local_8 & 0xfffff | 0x100000;
    iVar4 = uVar3 - 0x433;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
      uStack4 = uStack4 >> iVar4 | uVar2 << uVar3 - 0x413 | uVar2 >> iVar4 + -0x20;
      uVar2 = uVar2 >> iVar4;
    }
    else {
      if (10 < iVar4) {
        if ((param_1 & 0x8000000000000000) == 0) {
          uVar2 = 0x7fffffff;
          uStack4 = 0xffffffff;
        }
        else {
          uVar2 = 0x80000000;
          uStack4 = 0;
        }
        goto LAB_803294e4;
      }
      uVar2 = uVar2 << iVar4 | uStack4 >> 0x20 - iVar4 | uStack4 << uVar3 - 0x453;
      uStack4 = uStack4 << iVar4;
    }
    if ((param_1 & 0x8000000000000000) != 0) {
      bVar1 = uStack4 != 0;
      uStack4 = -uStack4;
      uVar2 = -(bVar1 + uVar2);
    }
  }
LAB_803294e4:
  return CONCAT44(uVar2,uStack4);
}

