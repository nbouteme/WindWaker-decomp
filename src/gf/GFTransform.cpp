#include <gf/GFTransform.h>


namespace gf {

/* __stdcall GFLoadPosMtxImm(float *[][][][],
                             unsigned long) */

void GFLoadPosMtxImm(MTX34 *param_1,int param_2)

{
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_2(0xcc008000,0xb);
  write_volatile_2(0xcc008000,(short)(param_2 << 2));
  write_volatile_4(0xcc008000,param_1->m[0]);
  write_volatile_4(0xcc008000,param_1->m[1]);
  write_volatile_4(0xcc008000,param_1->m[2]);
  write_volatile_4(0xcc008000,param_1->m[3]);
  write_volatile_4(0xcc008000,param_1->m[1][0]);
  write_volatile_4(0xcc008000,param_1->m[1][1]);
  write_volatile_4(0xcc008000,param_1->m[1][2]);
  write_volatile_4(0xcc008000,param_1->m[1][3]);
  write_volatile_4(0xcc008000,param_1->m[2][0]);
  write_volatile_4(0xcc008000,param_1->m[2][1]);
  write_volatile_4(0xcc008000,param_1->m[2][2]);
  write_volatile_4(0xcc008000,param_1->m[2][3]);
  return;
}


/* __stdcall GFLoadNrmMtxImm(float *[][][][],
                             unsigned long) */

void GFLoadNrmMtxImm(undefined4 *param_1,short param_2)

{
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_2(0xcc008000,8);
  write_volatile_2(0xcc008000,param_2 * 3 + 0x400);
  write_volatile_4(0xcc008000,*param_1);
  write_volatile_4(0xcc008000,param_1[1]);
  write_volatile_4(0xcc008000,param_1[2]);
  write_volatile_4(0xcc008000,param_1[4]);
  write_volatile_4(0xcc008000,param_1[5]);
  write_volatile_4(0xcc008000,param_1[6]);
  write_volatile_4(0xcc008000,param_1[8]);
  write_volatile_4(0xcc008000,param_1[9]);
  write_volatile_4(0xcc008000,param_1[10]);
  return;
}


/* __stdcall GFSetCurrentMtx(unsigned long,
                             unsigned long,
                             unsigned long,
                             unsigned long,
                             unsigned long,
                             unsigned long,
                             unsigned long,
                             unsigned long,
                             unsigned long) */

void GFSetCurrentMtx(uint param_1,int param_2,int param_3,int param_4,int param_5,uint param_6,
                        int param_7,int param_8,int param_9)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_5 << 0x18 | param_4 << 0x12 | param_3 << 0xc | param_1 | param_2 << 6;
  uVar2 = param_9 << 0x12 | param_8 << 0xc | param_6 | param_7 << 6;
  write_volatile_1(DAT_cc008000,8);
  write_volatile_1(DAT_cc008000,0x30);
  write_volatile_4(0xcc008000,uVar1);
  write_volatile_1(DAT_cc008000,8);
  write_volatile_1(DAT_cc008000,0x40);
  write_volatile_4(0xcc008000,uVar2);
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_2(0xcc008000,1);
  write_volatile_2(0xcc008000,0x1018);
  write_volatile_4(0xcc008000,uVar1);
  write_volatile_4(0xcc008000,uVar2);
  return;
}

