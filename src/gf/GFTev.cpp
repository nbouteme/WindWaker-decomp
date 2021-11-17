#include <gf/GFTev.h>


namespace gf {

/* __stdcall GFSetTevColor(_GXTevRegID,
                           _GXColor) */

void GFSetTevColor(GXTevRegID param_1,_GXColor *param_2)

{
  uint uVar1;
  
  uVar1 = (param_1 * 2 + 0xe1) * 0x1000000 | (uint)param_2->g << 0xc | (uint)param_2->b;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,
                   (param_1 * 2 + 0xe0) * 0x1000000 | (uint)param_2->a << 0xc | (uint)param_2->r);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar1);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar1);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar1);
  return;
}


/* __stdcall GFSetTevColorS10(_GXTevRegID,
                              _GXColorS10) */

void GFSetTevColorS10(GXTevRegID param_1,_GXColorS10 *param_2)

{
  uint uVar1;
  
  uVar1 = (param_1 * 2 + 0xe1) * 0x1000000 |
          (int)param_2->b & 0x7ffU | ((int)param_2->g & 0x7ffU) << 0xc;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,
                   (param_1 * 2 + 0xe0) * 0x1000000 |
                   (int)param_2->r & 0x7ffU | ((int)param_2->a & 0x7ffU) << 0xc);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar1);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar1);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar1);
  return;
}


/* __stdcall GFSetAlphaCompare(_GXCompare,
                               unsigned char,
                               _GXAlphaOp,
                               _GXCompare,
                               unsigned char) */

void GFSetAlphaCompare(int param_1,uint param_2,int param_3,int param_4,uint param_5)

{
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,
                   param_3 << 0x16 |
                   param_4 << 0x13 | param_1 << 0x10 | param_2 & 0xff | (param_5 & 0xff) << 8 |
                   0xf3000000);
  return;
}

