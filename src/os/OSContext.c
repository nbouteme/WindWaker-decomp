#include <os/OSContext.h>
#include <os/OSContext.h>
#include <os/OSInterrupt.h>
#include <m_Do_printf.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <os/OS.h>
#include <db/db.h>


namespace os {

/* WARNING: Removing unreachable block (ram,0x803037ac) */
/* WARNING: Removing unreachable block (ram,0x803037a4) */
/* WARNING: Removing unreachable block (ram,0x8030379c) */
/* WARNING: Removing unreachable block (ram,0x80303794) */
/* WARNING: Removing unreachable block (ram,0x8030378c) */
/* WARNING: Removing unreachable block (ram,0x80303784) */
/* WARNING: Removing unreachable block (ram,0x8030377c) */
/* WARNING: Removing unreachable block (ram,0x80303774) */
/* WARNING: Removing unreachable block (ram,0x8030376c) */
/* WARNING: Removing unreachable block (ram,0x80303764) */
/* WARNING: Removing unreachable block (ram,0x8030375c) */
/* WARNING: Removing unreachable block (ram,0x80303754) */
/* WARNING: Removing unreachable block (ram,0x8030374c) */
/* WARNING: Removing unreachable block (ram,0x80303744) */
/* WARNING: Removing unreachable block (ram,0x8030373c) */
/* WARNING: Removing unreachable block (ram,0x80303734) */
/* WARNING: Removing unreachable block (ram,0x80303738) */
/* WARNING: Removing unreachable block (ram,0x80303740) */
/* WARNING: Removing unreachable block (ram,0x80303748) */
/* WARNING: Removing unreachable block (ram,0x80303750) */
/* WARNING: Removing unreachable block (ram,0x80303758) */
/* WARNING: Removing unreachable block (ram,0x80303760) */
/* WARNING: Removing unreachable block (ram,0x80303768) */
/* WARNING: Removing unreachable block (ram,0x80303770) */
/* WARNING: Removing unreachable block (ram,0x80303778) */
/* WARNING: Removing unreachable block (ram,0x80303780) */
/* WARNING: Removing unreachable block (ram,0x80303788) */
/* WARNING: Removing unreachable block (ram,0x80303790) */
/* WARNING: Removing unreachable block (ram,0x80303798) */
/* WARNING: Removing unreachable block (ram,0x803037a0) */
/* WARNING: Removing unreachable block (ram,0x803037a8) */
/* WARNING: Removing unreachable block (ram,0x803037b0) */

undefined8 __OSLoadFPUContext(undefined8 param_1,undefined4 param_2,int param_3)

{
  uint in_HID2;
  
  if ((*(ushort *)(param_3 + 0x1a2) & 1) != 0) {
    if ((in_HID2 >> 0x1d & 1) != 0) {
      __psq_l0(param_3 + 0x1c8,0);
      __psq_l1(param_3 + 0x1c8,0);
      __psq_l0(param_3 + 0x1d0,0);
      __psq_l1(param_3 + 0x1d0,0);
      __psq_l0(param_3 + 0x1d8,0);
      __psq_l1(param_3 + 0x1d8,0);
      __psq_l0(param_3 + 0x1e0,0);
      __psq_l1(param_3 + 0x1e0,0);
      __psq_l0(param_3 + 0x1e8,0);
      __psq_l1(param_3 + 0x1e8,0);
      __psq_l0(param_3 + 0x1f0,0);
      __psq_l1(param_3 + 0x1f0,0);
      __psq_l0(param_3 + 0x1f8,0);
      __psq_l1(param_3 + 0x1f8,0);
      __psq_l0(param_3 + 0x200,0);
      __psq_l1(param_3 + 0x200,0);
      __psq_l0(param_3 + 0x208,0);
      __psq_l1(param_3 + 0x208,0);
      __psq_l0(param_3 + 0x210,0);
      __psq_l1(param_3 + 0x210,0);
      __psq_l0(param_3 + 0x218,0);
      __psq_l1(param_3 + 0x218,0);
      __psq_l0(param_3 + 0x220,0);
      __psq_l1(param_3 + 0x220,0);
      __psq_l0(param_3 + 0x228,0);
      __psq_l1(param_3 + 0x228,0);
      __psq_l0(param_3 + 0x230,0);
      __psq_l1(param_3 + 0x230,0);
      __psq_l0(param_3 + 0x238,0);
      __psq_l1(param_3 + 0x238,0);
      __psq_l0(param_3 + 0x240,0);
      __psq_l1(param_3 + 0x240,0);
      __psq_l0(param_3 + 0x248,0);
      __psq_l1(param_3 + 0x248,0);
      __psq_l0(param_3 + 0x250,0);
      __psq_l1(param_3 + 0x250,0);
      __psq_l0(param_3 + 600,0);
      __psq_l1(param_3 + 600,0);
      __psq_l0(param_3 + 0x260,0);
      __psq_l1(param_3 + 0x260,0);
      __psq_l0(param_3 + 0x268,0);
      __psq_l1(param_3 + 0x268,0);
      __psq_l0(param_3 + 0x270,0);
      __psq_l1(param_3 + 0x270,0);
      __psq_l0(param_3 + 0x278,0);
      __psq_l1(param_3 + 0x278,0);
      __psq_l0(param_3 + 0x280,0);
      __psq_l1(param_3 + 0x280,0);
      __psq_l0(param_3 + 0x288,0);
      __psq_l1(param_3 + 0x288,0);
      __psq_l0(param_3 + 0x290,0);
      __psq_l1(param_3 + 0x290,0);
      __psq_l0(param_3 + 0x298,0);
      __psq_l1(param_3 + 0x298,0);
      __psq_l0(param_3 + 0x2a0,0);
      __psq_l1(param_3 + 0x2a0,0);
      __psq_l0(param_3 + 0x2a8,0);
      __psq_l1(param_3 + 0x2a8,0);
      __psq_l0(param_3 + 0x2b0,0);
      __psq_l1(param_3 + 0x2b0,0);
      __psq_l0(param_3 + 0x2b8,0);
      __psq_l1(param_3 + 0x2b8,0);
      __psq_l0(param_3 + 0x2c0,0);
      __psq_l1(param_3 + 0x2c0,0);
    }
    param_1 = *(undefined8 *)(param_3 + 0x98);
  }
  return param_1;
}


void __OSSaveFPUContext
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
               undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
               undefined8 param_13,undefined4 param_14,undefined4 param_15,int param_16)

{
  byte in_fp_fx;
  byte in_fp_fex;
  byte in_fp_vx;
  byte in_fp_ox;
  byte in_fp_ux;
  byte in_fp_zx;
  byte in_fp_xx;
  byte in_fp_vxsnan;
  byte in_fp_vxisi;
  byte in_fp_vxidi;
  byte in_fp_vxzdz;
  byte in_fp_vximz;
  byte in_fp_vxvc;
  byte in_fp_fr;
  byte in_fp_fi;
  byte in_fp_c;
  byte in_fp_cc0;
  byte in_fp_cc1;
  byte in_fp_cc2;
  byte in_fp_cc3;
  byte in_fp_reserve1;
  byte in_fp_vxsoft;
  byte in_fp_vxsqrt;
  byte in_fp_vxcvi;
  byte in_fp_ve;
  byte in_fp_oe;
  byte in_fp_ue;
  byte in_fp_ze;
  byte in_fp_xe;
  byte in_fp_ni;
  byte in_fp_rn0;
  byte in_fp_rn1;
  uint in_HID2;
  undefined8 in_f0;
  undefined4 in_ps14_0;
  undefined4 in_ps14_1;
  undefined4 in_ps15_0;
  undefined4 in_ps15_1;
  undefined4 in_ps16_0;
  undefined4 in_ps16_1;
  undefined4 in_ps17_0;
  undefined4 in_ps17_1;
  undefined4 in_ps18_0;
  undefined4 in_ps18_1;
  undefined4 in_ps19_0;
  undefined4 in_ps19_1;
  undefined4 in_ps20_0;
  undefined4 in_ps20_1;
  undefined4 in_ps21_0;
  undefined4 in_ps21_1;
  undefined4 in_ps22_0;
  undefined4 in_ps22_1;
  undefined4 in_ps23_0;
  undefined4 in_ps23_1;
  undefined4 in_ps24_0;
  undefined4 in_ps24_1;
  undefined4 in_ps25_0;
  undefined4 in_ps25_1;
  undefined4 in_ps26_0;
  undefined4 in_ps26_1;
  undefined4 in_ps27_0;
  undefined4 in_ps27_1;
  undefined4 in_ps28_0;
  undefined4 in_ps28_1;
  undefined4 in_ps29_0;
  undefined4 in_ps29_1;
  undefined4 in_ps30_0;
  undefined4 in_ps30_1;
  undefined4 in_ps31_0;
  undefined4 in_ps31_1;
  
  *(ushort *)(param_16 + 0x1a2) = *(ushort *)(param_16 + 0x1a2) | 1;
  *(undefined8 *)(param_16 + 0x90) = in_f0;
  *(undefined8 *)(param_16 + 0x98) = param_1;
  *(undefined8 *)(param_16 + 0xa0) = param_2;
  *(undefined8 *)(param_16 + 0xa8) = param_3;
  *(undefined8 *)(param_16 + 0xb0) = param_4;
  *(undefined8 *)(param_16 + 0xb8) = param_5;
  *(undefined8 *)(param_16 + 0xc0) = param_6;
  *(undefined8 *)(param_16 + 200) = param_7;
  *(undefined8 *)(param_16 + 0xd0) = param_8;
  *(undefined8 *)(param_16 + 0xd8) = param_9;
  *(undefined8 *)(param_16 + 0xe0) = param_10;
  *(undefined8 *)(param_16 + 0xe8) = param_11;
  *(undefined8 *)(param_16 + 0xf0) = param_12;
  *(undefined8 *)(param_16 + 0xf8) = param_13;
  *(ulonglong *)(param_16 + 0x100) = CONCAT44(in_ps14_0,in_ps14_1);
  *(ulonglong *)(param_16 + 0x108) = CONCAT44(in_ps15_0,in_ps15_1);
  *(ulonglong *)(param_16 + 0x110) = CONCAT44(in_ps16_0,in_ps16_1);
  *(ulonglong *)(param_16 + 0x118) = CONCAT44(in_ps17_0,in_ps17_1);
  *(ulonglong *)(param_16 + 0x120) = CONCAT44(in_ps18_0,in_ps18_1);
  *(ulonglong *)(param_16 + 0x128) = CONCAT44(in_ps19_0,in_ps19_1);
  *(ulonglong *)(param_16 + 0x130) = CONCAT44(in_ps20_0,in_ps20_1);
  *(ulonglong *)(param_16 + 0x138) = CONCAT44(in_ps21_0,in_ps21_1);
  *(ulonglong *)(param_16 + 0x140) = CONCAT44(in_ps22_0,in_ps22_1);
  *(ulonglong *)(param_16 + 0x148) = CONCAT44(in_ps23_0,in_ps23_1);
  *(ulonglong *)(param_16 + 0x150) = CONCAT44(in_ps24_0,in_ps24_1);
  *(ulonglong *)(param_16 + 0x158) = CONCAT44(in_ps25_0,in_ps25_1);
  *(ulonglong *)(param_16 + 0x160) = CONCAT44(in_ps26_0,in_ps26_1);
  *(ulonglong *)(param_16 + 0x168) = CONCAT44(in_ps27_0,in_ps27_1);
  *(ulonglong *)(param_16 + 0x170) = CONCAT44(in_ps28_0,in_ps28_1);
  *(ulonglong *)(param_16 + 0x178) = CONCAT44(in_ps29_0,in_ps29_1);
  *(ulonglong *)(param_16 + 0x180) = CONCAT44(in_ps30_0,in_ps30_1);
  *(ulonglong *)(param_16 + 0x188) = CONCAT44(in_ps31_0,in_ps31_1);
  *(ulonglong *)(param_16 + 400) =
       (ulonglong)
       (in_fp_rn1 & 1 | (uint)in_fp_fx << 0x1f | (in_fp_fex & 1) << 0x1e | (in_fp_vx & 1) << 0x1d |
        (in_fp_ox & 1) << 0x1c | (in_fp_ux & 1) << 0x1b | (in_fp_zx & 1) << 0x1a |
        (in_fp_xx & 1) << 0x19 | (in_fp_vxsnan & 1) << 0x18 | (in_fp_vxisi & 1) << 0x17 |
        (in_fp_vxidi & 1) << 0x16 | (in_fp_vxzdz & 1) << 0x15 | (in_fp_vximz & 1) << 0x14 |
        (in_fp_vxvc & 1) << 0x13 | (in_fp_fr & 1) << 0x12 | (in_fp_fi & 1) << 0x11 |
        (in_fp_c & 1) << 0x10 | (in_fp_cc0 & 1) << 0xf | (in_fp_cc1 & 1) << 0xe |
        (in_fp_cc2 & 1) << 0xd | (in_fp_cc3 & 1) << 0xc | (in_fp_reserve1 & 1) << 0xb |
        (in_fp_vxsoft & 1) << 10 | (in_fp_vxsqrt & 1) << 9 | (in_fp_vxcvi & 1) << 8 |
        (in_fp_ve & 1) << 7 | (in_fp_oe & 1) << 6 | (in_fp_ue & 1) << 5 | (in_fp_ze & 1) << 4 |
        (in_fp_xe & 1) << 3 | (in_fp_ni & 1) << 2 | (in_fp_rn0 & 1) << 1);
  if ((in_HID2 >> 0x1d & 1) != 0) {
    __psq_st0(param_16 + 0x1c8,(int)((ulonglong)*(undefined8 *)(param_16 + 0x90) >> 0x20),0);
    __psq_st1(param_16 + 0x1c8,(int)*(undefined8 *)(param_16 + 0x90),0);
    __psq_st0(param_16 + 0x1d0,(int)((ulonglong)param_1 >> 0x20),0);
    __psq_st1(param_16 + 0x1d0,(int)param_1,0);
    __psq_st0(param_16 + 0x1d8,(int)((ulonglong)param_2 >> 0x20),0);
    __psq_st1(param_16 + 0x1d8,(int)param_2,0);
    __psq_st0(param_16 + 0x1e0,(int)((ulonglong)param_3 >> 0x20),0);
    __psq_st1(param_16 + 0x1e0,(int)param_3,0);
    __psq_st0(param_16 + 0x1e8,(int)((ulonglong)param_4 >> 0x20),0);
    __psq_st1(param_16 + 0x1e8,(int)param_4,0);
    __psq_st0(param_16 + 0x1f0,(int)((ulonglong)param_5 >> 0x20),0);
    __psq_st1(param_16 + 0x1f0,(int)param_5,0);
    __psq_st0(param_16 + 0x1f8,(int)((ulonglong)param_6 >> 0x20),0);
    __psq_st1(param_16 + 0x1f8,(int)param_6,0);
    __psq_st0(param_16 + 0x200,(int)((ulonglong)param_7 >> 0x20),0);
    __psq_st1(param_16 + 0x200,(int)param_7,0);
    __psq_st0(param_16 + 0x208,(int)((ulonglong)param_8 >> 0x20),0);
    __psq_st1(param_16 + 0x208,(int)param_8,0);
    __psq_st0(param_16 + 0x210,(int)((ulonglong)param_9 >> 0x20),0);
    __psq_st1(param_16 + 0x210,(int)param_9,0);
    __psq_st0(param_16 + 0x218,(int)((ulonglong)param_10 >> 0x20),0);
    __psq_st1(param_16 + 0x218,(int)param_10,0);
    __psq_st0(param_16 + 0x220,(int)((ulonglong)param_11 >> 0x20),0);
    __psq_st1(param_16 + 0x220,(int)param_11,0);
    __psq_st0(param_16 + 0x228,(int)((ulonglong)param_12 >> 0x20),0);
    __psq_st1(param_16 + 0x228,(int)param_12,0);
    __psq_st0(param_16 + 0x230,(int)((ulonglong)param_13 >> 0x20),0);
    __psq_st1(param_16 + 0x230,(int)param_13,0);
    __psq_st0(param_16 + 0x238,in_ps14_0,0);
    __psq_st1(param_16 + 0x238,in_ps14_1,0);
    __psq_st0(param_16 + 0x240,in_ps15_0,0);
    __psq_st1(param_16 + 0x240,in_ps15_1,0);
    __psq_st0(param_16 + 0x248,in_ps16_0,0);
    __psq_st1(param_16 + 0x248,in_ps16_1,0);
    __psq_st0(param_16 + 0x250,in_ps17_0,0);
    __psq_st1(param_16 + 0x250,in_ps17_1,0);
    __psq_st0(param_16 + 600,in_ps18_0,0);
    __psq_st1(param_16 + 600,in_ps18_1,0);
    __psq_st0(param_16 + 0x260,in_ps19_0,0);
    __psq_st1(param_16 + 0x260,in_ps19_1,0);
    __psq_st0(param_16 + 0x268,in_ps20_0,0);
    __psq_st1(param_16 + 0x268,in_ps20_1,0);
    __psq_st0(param_16 + 0x270,in_ps21_0,0);
    __psq_st1(param_16 + 0x270,in_ps21_1,0);
    __psq_st0(param_16 + 0x278,in_ps22_0,0);
    __psq_st1(param_16 + 0x278,in_ps22_1,0);
    __psq_st0(param_16 + 0x280,in_ps23_0,0);
    __psq_st1(param_16 + 0x280,in_ps23_1,0);
    __psq_st0(param_16 + 0x288,in_ps24_0,0);
    __psq_st1(param_16 + 0x288,in_ps24_1,0);
    __psq_st0(param_16 + 0x290,in_ps25_0,0);
    __psq_st1(param_16 + 0x290,in_ps25_1,0);
    __psq_st0(param_16 + 0x298,in_ps26_0,0);
    __psq_st1(param_16 + 0x298,in_ps26_1,0);
    __psq_st0(param_16 + 0x2a0,in_ps27_0,0);
    __psq_st1(param_16 + 0x2a0,in_ps27_1,0);
    __psq_st0(param_16 + 0x2a8,in_ps28_0,0);
    __psq_st1(param_16 + 0x2a8,in_ps28_1,0);
    __psq_st0(param_16 + 0x2b0,in_ps29_0,0);
    __psq_st1(param_16 + 0x2b0,in_ps29_1,0);
    __psq_st0(param_16 + 0x2b8,in_ps30_0,0);
    __psq_st1(param_16 + 0x2b8,in_ps30_1,0);
    __psq_st0(param_16 + 0x2c0,in_ps31_0,0);
    __psq_st1(param_16 + 0x2c0,in_ps31_1,0);
  }
  return;
}


void OSSaveFPUContext(undefined4 param_1,undefined4 param_2)

{
  __OSSaveFPUContext(param_1,param_2,param_1);
  return;
}


void OSSetCurrentContext(uint param_1)

{
  DAT_800000c0 = param_1 & 0x3fffffff;
  DAT_800000d4 = param_1;
  if (DAT_800000d8 == param_1) {
    *(uint *)(param_1 + 0x19c) = *(uint *)(param_1 + 0x19c) | 0x2000;
    return;
  }
  *(uint *)(param_1 + 0x19c) = *(uint *)(param_1 + 0x19c) & 0xffffdfff;
  instructionSynchronize();
  return;
}


undefined4 OSGetCurrentContext(void)

{
  return DAT_800000d4;
}


undefined4 OSSaveContext(int param_1)

{
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
  undefined4 in_MSR;
  byte in_cr0;
  byte in_cr1;
  byte in_cr2;
  byte in_cr3;
  byte unaff_cr4;
  byte in_cr5;
  byte in_cr6;
  byte in_cr7;
  undefined4 in_XER;
  undefined4 in_LR;
  undefined4 in_CTR;
  undefined4 in_GQR1;
  undefined4 in_GQR7;
  
  *(undefined4 *)(param_1 + 0x34) = 0x803fe0e0;
  *(undefined4 *)(param_1 + 0x38) = unaff_r14;
  *(undefined4 *)(param_1 + 0x3c) = unaff_r15;
  *(undefined4 *)(param_1 + 0x40) = unaff_r16;
  *(undefined4 *)(param_1 + 0x44) = unaff_r17;
  *(undefined4 *)(param_1 + 0x48) = unaff_r18;
  *(undefined4 *)(param_1 + 0x4c) = unaff_r19;
  *(undefined4 *)(param_1 + 0x50) = unaff_r20;
  *(undefined4 *)(param_1 + 0x54) = unaff_r21;
  *(undefined4 *)(param_1 + 0x58) = unaff_r22;
  *(undefined4 *)(param_1 + 0x5c) = unaff_r23;
  *(undefined4 *)(param_1 + 0x60) = unaff_r24;
  *(undefined4 *)(param_1 + 100) = unaff_r25;
  *(undefined4 *)(param_1 + 0x68) = unaff_r26;
  *(undefined4 *)(param_1 + 0x6c) = unaff_r27;
  *(undefined4 *)(param_1 + 0x70) = unaff_r28;
  *(undefined4 *)(param_1 + 0x74) = unaff_r29;
  *(undefined4 *)(param_1 + 0x78) = unaff_r30;
  *(undefined4 *)(param_1 + 0x7c) = unaff_r31;
  *(undefined4 *)(param_1 + 0x1a8) = in_GQR1;
  *(undefined4 *)(param_1 + 0x1ac) = 0x40004;
  *(undefined4 *)(param_1 + 0x1b0) = 0x50005;
  *(undefined4 *)(param_1 + 0x1b4) = 0x60006;
  *(undefined4 *)(param_1 + 0x1b8) = 0x70007;
  *(undefined4 *)(param_1 + 0x1bc) = 0x3d043d04;
  *(undefined4 *)(param_1 + 0x1c0) = in_GQR7;
  *(uint *)(param_1 + 0x80) =
       (uint)(in_cr0 & 0xf) << 0x1c | (uint)(in_cr1 & 0xf) << 0x18 | (uint)(in_cr2 & 0xf) << 0x14 |
       (uint)(in_cr3 & 0xf) << 0x10 | (uint)(unaff_cr4 & 0xf) << 0xc | (uint)(in_cr5 & 0xf) << 8 |
       (uint)(in_cr6 & 0xf) << 4 | (uint)(in_cr7 & 0xf);
  *(undefined4 *)(param_1 + 0x84) = in_LR;
  *(undefined4 *)(param_1 + 0x198) = in_LR;
  *(undefined4 *)(param_1 + 0x19c) = in_MSR;
  *(undefined4 *)(param_1 + 0x88) = in_CTR;
  *(undefined4 *)(param_1 + 0x8c) = in_XER;
  *(BADSPACEBASE **)(param_1 + 4) = register0x00000004;
  *(undefined4 *)(param_1 + 8) = 0x803ffd00;
  *(undefined4 *)(param_1 + 0xc) = 1;
  return 0;
}


undefined8 OSLoadContext(int param_1)

{
  uint in_MSR;
  
  if ((OSDisableInterrupts < *(code **)(param_1 + 0x198)) &&
     (*(code **)(param_1 + 0x198) < (code *)0x80304614)) {
    *(code **)(param_1 + 0x198) = OSDisableInterrupts;
  }
  if ((*(ushort *)(param_1 + 0x1a2) & 2) != 0) {
    *(ushort *)(param_1 + 0x1a2) = *(ushort *)(param_1 + 0x1a2) & 0xfffd;
  }
  returnFromInterrupt(in_MSR & 0x9000,*(undefined4 *)(param_1 + 0x19c));
  return *(undefined8 *)(param_1 + 0xc);
}


undefined * OSGetStackPointer(void)

{
  return (undefined *)register0x00000004;
}


void OSClearContext(int param_1)

{
  *(undefined2 *)(param_1 + 0x1a0) = 0;
  *(undefined2 *)(param_1 + 0x1a2) = 0;
  if (param_1 == DAT_800000d8) {
    DAT_800000d8 = 0;
  }
  return;
}


void OSInitContext(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x198) = param_2;
  *(undefined4 *)(param_1 + 4) = param_3;
  *(undefined4 *)(param_1 + 0x19c) = 0x9032;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 8) = 0x803ffd00;
  *(undefined4 *)(param_1 + 0x34) = 0x803fe0e0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x1a4) = 0;
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  *(undefined4 *)(param_1 + 0x1ac) = 0;
  *(undefined4 *)(param_1 + 0x1b0) = 0;
  *(undefined4 *)(param_1 + 0x1b4) = 0;
  *(undefined4 *)(param_1 + 0x1b8) = 0;
  *(undefined4 *)(param_1 + 0x1bc) = 0;
  *(undefined4 *)(param_1 + 0x1c0) = 0;
  OSClearContext();
  return;
}


void OSDumpContext(undefined4 *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined auStack744 [416];
  undefined2 local_148;
  undefined2 local_146;
  
  m_Do_printf::OSReport(_61,param_1);
  uVar6 = 0;
  puVar7 = param_1;
  do {
    m_Do_printf::OSReport(_62,uVar6,*puVar7,*puVar7,uVar6 + 0x10,puVar7[0x10],puVar7[0x10]);
    puVar7 = puVar7 + 1;
    uVar6 = uVar6 + 1;
  } while (uVar6 < 0x10);
  m_Do_printf::OSReport(_63,param_1[0x21],param_1[0x20]);
  m_Do_printf::OSReport(_64,param_1[0x66],param_1[0x67]);
  m_Do_printf::OSReport(_65);
  uVar6 = 0;
  puVar7 = param_1;
  do {
    m_Do_printf::OSReport(_66,uVar6,puVar7[0x69],uVar6 + 4,puVar7[0x6d]);
    puVar7 = puVar7 + 1;
    uVar6 = uVar6 + 1;
  } while (uVar6 < 4);
  if ((*(ushort *)((int)param_1 + 0x1a2) & 1) != 0) {
    uVar3 = OSDisableInterrupts();
    uVar2 = DAT_800000d4;
    local_148 = 0;
    local_146 = 0;
    if (auStack744 == DAT_800000d8) {
      DAT_800000d8 = (undefined *)0x0;
    }
    OSSetCurrentContext(auStack744);
    m_Do_printf::OSReport(_67);
    uVar6 = 0;
    puVar7 = param_1;
    do {
      uVar4 = Runtime.PPCEABI.H::__cvt_fp2unsigned(*(undefined8 *)(puVar7 + 0x26));
      uVar5 = Runtime.PPCEABI.H::__cvt_fp2unsigned(*(undefined8 *)(puVar7 + 0x24));
      m_Do_printf::OSReport(_68,uVar6,uVar5,uVar6 + 1,uVar4);
      puVar7 = puVar7 + 4;
      uVar6 = uVar6 + 2;
    } while (uVar6 < 0x20);
    m_Do_printf::OSReport(_69);
    uVar6 = 0;
    puVar7 = param_1;
    do {
      uVar4 = Runtime.PPCEABI.H::__cvt_fp2unsigned(*(undefined8 *)(puVar7 + 0x74));
      uVar5 = Runtime.PPCEABI.H::__cvt_fp2unsigned(*(undefined8 *)(puVar7 + 0x72));
      m_Do_printf::OSReport(_70,uVar6,uVar5,uVar6 + 1,uVar4);
      puVar7 = puVar7 + 4;
      uVar6 = uVar6 + 2;
    } while (uVar6 < 0x20);
    local_148 = 0;
    local_146 = 0;
    if (auStack744 == DAT_800000d8) {
      DAT_800000d8 = (undefined *)0x0;
    }
    OSSetCurrentContext(uVar2);
    OSRestoreInterrupts(uVar3);
  }
  m_Do_printf::OSReport(_71);
  puVar7 = (undefined4 *)param_1[1];
  uVar6 = 0;
  while (((puVar7 != (undefined4 *)0x0 && (puVar7 != (undefined4 *)&DAT_ffffffff)) &&
         (bVar1 = uVar6 < 0x10, uVar6 = uVar6 + 1, bVar1))) {
    m_Do_printf::OSReport(_72,puVar7,*puVar7,puVar7[1]);
    puVar7 = (undefined4 *)*puVar7;
  }
  return;
}


undefined8 OSSwitchFPUContext(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int extraout_r4;
  uint uVar3;
  uint in_MSR;
  uint uVar4;
  
  uVar4 = in_MSR & 0x9000;
  instructionSynchronize();
  uVar3 = *(uint *)(param_2 + 0x19c) | 0x2000;
  iVar2 = param_2;
  if (DAT_800000d8 != param_2) {
    bVar1 = DAT_800000d8 != 0;
    DAT_800000d8 = param_2;
    if (bVar1) {
      __OSSaveFPUContext();
    }
    __OSLoadFPUContext();
    param_2 = extraout_r4;
    iVar2 = DAT_800000d8;
  }
  DAT_800000d8 = iVar2;
  *(ushort *)(param_2 + 0x1a2) = *(ushort *)(param_2 + 0x1a2) & 0xfffd;
  returnFromInterrupt(uVar4,uVar3);
  return *(undefined8 *)(param_2 + 0xc);
}


void __OSContextInit(void)

{
  __OSSetExceptionHandler(7,OSSwitchFPUContext);
  DAT_800000d8 = 0;
  db::DBPrintf(_76);
  return;
}


void OSFillFPUContext
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
               undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
               undefined8 param_13,int param_14)

{
  byte in_fp_fx;
  byte in_fp_fex;
  byte in_fp_vx;
  byte in_fp_ox;
  byte in_fp_ux;
  byte in_fp_zx;
  byte in_fp_xx;
  byte in_fp_vxsnan;
  byte in_fp_vxisi;
  byte in_fp_vxidi;
  byte in_fp_vxzdz;
  byte in_fp_vximz;
  byte in_fp_vxvc;
  byte in_fp_fr;
  byte in_fp_fi;
  byte in_fp_c;
  byte in_fp_cc0;
  byte in_fp_cc1;
  byte in_fp_cc2;
  byte in_fp_cc3;
  byte in_fp_reserve1;
  byte in_fp_vxsoft;
  byte in_fp_vxsqrt;
  byte in_fp_vxcvi;
  byte in_fp_ve;
  byte in_fp_oe;
  byte in_fp_ue;
  byte in_fp_ze;
  byte in_fp_xe;
  byte in_fp_ni;
  byte in_fp_rn0;
  byte in_fp_rn1;
  uint in_HID2;
  undefined8 in_f0;
  undefined4 in_ps14_0;
  undefined4 in_ps14_1;
  undefined4 in_ps15_0;
  undefined4 in_ps15_1;
  undefined4 in_ps16_0;
  undefined4 in_ps16_1;
  undefined4 in_ps17_0;
  undefined4 in_ps17_1;
  undefined4 in_ps18_0;
  undefined4 in_ps18_1;
  undefined4 in_ps19_0;
  undefined4 in_ps19_1;
  undefined4 in_ps20_0;
  undefined4 in_ps20_1;
  undefined4 in_ps21_0;
  undefined4 in_ps21_1;
  undefined4 in_ps22_0;
  undefined4 in_ps22_1;
  undefined4 in_ps23_0;
  undefined4 in_ps23_1;
  undefined4 in_ps24_0;
  undefined4 in_ps24_1;
  undefined4 in_ps25_0;
  undefined4 in_ps25_1;
  undefined4 in_ps26_0;
  undefined4 in_ps26_1;
  undefined4 in_ps27_0;
  undefined4 in_ps27_1;
  undefined4 in_ps28_0;
  undefined4 in_ps28_1;
  undefined4 in_ps29_0;
  undefined4 in_ps29_1;
  undefined4 in_ps30_0;
  undefined4 in_ps30_1;
  undefined4 in_ps31_0;
  undefined4 in_ps31_1;
  
  instructionSynchronize();
  *(undefined8 *)(param_14 + 0x90) = in_f0;
  *(undefined8 *)(param_14 + 0x98) = param_1;
  *(undefined8 *)(param_14 + 0xa0) = param_2;
  *(undefined8 *)(param_14 + 0xa8) = param_3;
  *(undefined8 *)(param_14 + 0xb0) = param_4;
  *(undefined8 *)(param_14 + 0xb8) = param_5;
  *(undefined8 *)(param_14 + 0xc0) = param_6;
  *(undefined8 *)(param_14 + 200) = param_7;
  *(undefined8 *)(param_14 + 0xd0) = param_8;
  *(undefined8 *)(param_14 + 0xd8) = param_9;
  *(undefined8 *)(param_14 + 0xe0) = param_10;
  *(undefined8 *)(param_14 + 0xe8) = param_11;
  *(undefined8 *)(param_14 + 0xf0) = param_12;
  *(undefined8 *)(param_14 + 0xf8) = param_13;
  *(ulonglong *)(param_14 + 0x100) = CONCAT44(in_ps14_0,in_ps14_1);
  *(ulonglong *)(param_14 + 0x108) = CONCAT44(in_ps15_0,in_ps15_1);
  *(ulonglong *)(param_14 + 0x110) = CONCAT44(in_ps16_0,in_ps16_1);
  *(ulonglong *)(param_14 + 0x118) = CONCAT44(in_ps17_0,in_ps17_1);
  *(ulonglong *)(param_14 + 0x120) = CONCAT44(in_ps18_0,in_ps18_1);
  *(ulonglong *)(param_14 + 0x128) = CONCAT44(in_ps19_0,in_ps19_1);
  *(ulonglong *)(param_14 + 0x130) = CONCAT44(in_ps20_0,in_ps20_1);
  *(ulonglong *)(param_14 + 0x138) = CONCAT44(in_ps21_0,in_ps21_1);
  *(ulonglong *)(param_14 + 0x140) = CONCAT44(in_ps22_0,in_ps22_1);
  *(ulonglong *)(param_14 + 0x148) = CONCAT44(in_ps23_0,in_ps23_1);
  *(ulonglong *)(param_14 + 0x150) = CONCAT44(in_ps24_0,in_ps24_1);
  *(ulonglong *)(param_14 + 0x158) = CONCAT44(in_ps25_0,in_ps25_1);
  *(ulonglong *)(param_14 + 0x160) = CONCAT44(in_ps26_0,in_ps26_1);
  *(ulonglong *)(param_14 + 0x168) = CONCAT44(in_ps27_0,in_ps27_1);
  *(ulonglong *)(param_14 + 0x170) = CONCAT44(in_ps28_0,in_ps28_1);
  *(ulonglong *)(param_14 + 0x178) = CONCAT44(in_ps29_0,in_ps29_1);
  *(ulonglong *)(param_14 + 0x180) = CONCAT44(in_ps30_0,in_ps30_1);
  *(ulonglong *)(param_14 + 0x188) = CONCAT44(in_ps31_0,in_ps31_1);
  *(ulonglong *)(param_14 + 400) =
       (ulonglong)
       (in_fp_rn1 & 1 | (uint)in_fp_fx << 0x1f | (in_fp_fex & 1) << 0x1e | (in_fp_vx & 1) << 0x1d |
        (in_fp_ox & 1) << 0x1c | (in_fp_ux & 1) << 0x1b | (in_fp_zx & 1) << 0x1a |
        (in_fp_xx & 1) << 0x19 | (in_fp_vxsnan & 1) << 0x18 | (in_fp_vxisi & 1) << 0x17 |
        (in_fp_vxidi & 1) << 0x16 | (in_fp_vxzdz & 1) << 0x15 | (in_fp_vximz & 1) << 0x14 |
        (in_fp_vxvc & 1) << 0x13 | (in_fp_fr & 1) << 0x12 | (in_fp_fi & 1) << 0x11 |
        (in_fp_c & 1) << 0x10 | (in_fp_cc0 & 1) << 0xf | (in_fp_cc1 & 1) << 0xe |
        (in_fp_cc2 & 1) << 0xd | (in_fp_cc3 & 1) << 0xc | (in_fp_reserve1 & 1) << 0xb |
        (in_fp_vxsoft & 1) << 10 | (in_fp_vxsqrt & 1) << 9 | (in_fp_vxcvi & 1) << 8 |
        (in_fp_ve & 1) << 7 | (in_fp_oe & 1) << 6 | (in_fp_ue & 1) << 5 | (in_fp_ze & 1) << 4 |
        (in_fp_xe & 1) << 3 | (in_fp_ni & 1) << 2 | (in_fp_rn0 & 1) << 1);
  if ((in_HID2 >> 0x1d & 1) != 0) {
    __psq_st0(param_14 + 0x1c8,(int)((ulonglong)*(undefined8 *)(param_14 + 0x90) >> 0x20),0);
    __psq_st1(param_14 + 0x1c8,(int)*(undefined8 *)(param_14 + 0x90),0);
    __psq_st0(param_14 + 0x1d0,(int)((ulonglong)param_1 >> 0x20),0);
    __psq_st1(param_14 + 0x1d0,(int)param_1,0);
    __psq_st0(param_14 + 0x1d8,(int)((ulonglong)param_2 >> 0x20),0);
    __psq_st1(param_14 + 0x1d8,(int)param_2,0);
    __psq_st0(param_14 + 0x1e0,(int)((ulonglong)param_3 >> 0x20),0);
    __psq_st1(param_14 + 0x1e0,(int)param_3,0);
    __psq_st0(param_14 + 0x1e8,(int)((ulonglong)param_4 >> 0x20),0);
    __psq_st1(param_14 + 0x1e8,(int)param_4,0);
    __psq_st0(param_14 + 0x1f0,(int)((ulonglong)param_5 >> 0x20),0);
    __psq_st1(param_14 + 0x1f0,(int)param_5,0);
    __psq_st0(param_14 + 0x1f8,(int)((ulonglong)param_6 >> 0x20),0);
    __psq_st1(param_14 + 0x1f8,(int)param_6,0);
    __psq_st0(param_14 + 0x200,(int)((ulonglong)param_7 >> 0x20),0);
    __psq_st1(param_14 + 0x200,(int)param_7,0);
    __psq_st0(param_14 + 0x208,(int)((ulonglong)param_8 >> 0x20),0);
    __psq_st1(param_14 + 0x208,(int)param_8,0);
    __psq_st0(param_14 + 0x210,(int)((ulonglong)param_9 >> 0x20),0);
    __psq_st1(param_14 + 0x210,(int)param_9,0);
    __psq_st0(param_14 + 0x218,(int)((ulonglong)param_10 >> 0x20),0);
    __psq_st1(param_14 + 0x218,(int)param_10,0);
    __psq_st0(param_14 + 0x220,(int)((ulonglong)param_11 >> 0x20),0);
    __psq_st1(param_14 + 0x220,(int)param_11,0);
    __psq_st0(param_14 + 0x228,(int)((ulonglong)param_12 >> 0x20),0);
    __psq_st1(param_14 + 0x228,(int)param_12,0);
    __psq_st0(param_14 + 0x230,(int)((ulonglong)param_13 >> 0x20),0);
    __psq_st1(param_14 + 0x230,(int)param_13,0);
    __psq_st0(param_14 + 0x238,in_ps14_0,0);
    __psq_st1(param_14 + 0x238,in_ps14_1,0);
    __psq_st0(param_14 + 0x240,in_ps15_0,0);
    __psq_st1(param_14 + 0x240,in_ps15_1,0);
    __psq_st0(param_14 + 0x248,in_ps16_0,0);
    __psq_st1(param_14 + 0x248,in_ps16_1,0);
    __psq_st0(param_14 + 0x250,in_ps17_0,0);
    __psq_st1(param_14 + 0x250,in_ps17_1,0);
    __psq_st0(param_14 + 600,in_ps18_0,0);
    __psq_st1(param_14 + 600,in_ps18_1,0);
    __psq_st0(param_14 + 0x260,in_ps19_0,0);
    __psq_st1(param_14 + 0x260,in_ps19_1,0);
    __psq_st0(param_14 + 0x268,in_ps20_0,0);
    __psq_st1(param_14 + 0x268,in_ps20_1,0);
    __psq_st0(param_14 + 0x270,in_ps21_0,0);
    __psq_st1(param_14 + 0x270,in_ps21_1,0);
    __psq_st0(param_14 + 0x278,in_ps22_0,0);
    __psq_st1(param_14 + 0x278,in_ps22_1,0);
    __psq_st0(param_14 + 0x280,in_ps23_0,0);
    __psq_st1(param_14 + 0x280,in_ps23_1,0);
    __psq_st0(param_14 + 0x288,in_ps24_0,0);
    __psq_st1(param_14 + 0x288,in_ps24_1,0);
    __psq_st0(param_14 + 0x290,in_ps25_0,0);
    __psq_st1(param_14 + 0x290,in_ps25_1,0);
    __psq_st0(param_14 + 0x298,in_ps26_0,0);
    __psq_st1(param_14 + 0x298,in_ps26_1,0);
    __psq_st0(param_14 + 0x2a0,in_ps27_0,0);
    __psq_st1(param_14 + 0x2a0,in_ps27_1,0);
    __psq_st0(param_14 + 0x2a8,in_ps28_0,0);
    __psq_st1(param_14 + 0x2a8,in_ps28_1,0);
    __psq_st0(param_14 + 0x2b0,in_ps29_0,0);
    __psq_st1(param_14 + 0x2b0,in_ps29_1,0);
    __psq_st0(param_14 + 0x2b8,in_ps30_0,0);
    __psq_st1(param_14 + 0x2b8,in_ps30_1,0);
    __psq_st0(param_14 + 0x2c0,in_ps31_0,0);
    __psq_st1(param_14 + 0x2c0,in_ps31_1,0);
  }
  return;
}

