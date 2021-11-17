#include <gf/GFPixel.h>
#include <Runtime.PPCEABI.H/runtime.h>


namespace gf {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall GFSetFog(_GXFogType,
                      float,
                      float,
                      float,
                      float,
                      _GXColor) */

void GFSetFog(double param_1,double param_2,double param_3,double param_4,int param_5,
                 uint3 *param_6)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  double dVar5;
  float local_24;
  
  if ((param_4 == param_3) || (param_2 == param_1)) {
    local_24 = _292;
    fVar1 = _293;
    fVar2 = _292;
  }
  else {
    fVar2 = (float)(param_4 * param_3) /
            (float)((double)(float)(param_4 - param_3) * (double)(float)(param_2 - param_1));
    fVar1 = (float)(param_4 / (double)(float)(param_4 - param_3));
    local_24 = (float)(param_1 / (double)(float)(param_2 - param_1));
  }
  uVar4 = 1;
  while (dVar5 = (double)fVar1, _294 < dVar5) {
    uVar4 = uVar4 + 1;
    fVar1 = (float)(dVar5 * (double)_293);
  }
  for (; ((double)_292 < dVar5 && (dVar5 < _296)); dVar5 = (double)(float)(dVar5 * (double)_295)) {
    uVar4 = uVar4 - 1;
  }
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,
                   (uint)(fVar2 / (float)((double)CONCAT44(0x43300000,1 << uVar4 ^ 0x80000000) -
                                         _300)) >> 0xc | 0xee000000);
  write_volatile_1(DAT_cc008000,0x61);
  uVar3 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)(float)((double)_297 * dVar5));
  write_volatile_4(0xcc008000,uVar3 | 0xef000000);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar4 | 0xf0000000);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,(uint)local_24 >> 0xc | param_5 << 0x15 | 0xf1000000);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*param_6 | 0xf2000000);
  return;
}


/* __stdcall GFSetBlendModeEtc(_GXBlendMode,
                               _GXBlendFactor,
                               _GXBlendFactor,
                               _GXLogicOp,
                               unsigned char,
                               unsigned char,
                               unsigned char) */

void GFSetBlendModeEtc
               (int param_1,int param_2,int param_3,int param_4,uint param_5,uint param_6,
               uint param_7)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  write_volatile_1(DAT_cc008000,0x61);
  uVar3 = 0;
  if ((param_1 == 1) || (param_1 == 3)) {
    uVar3 = 1;
  }
  uVar1 = countLeadingZeros(3 - param_1);
  uVar2 = countLeadingZeros(2 - param_1);
  write_volatile_4(0xcc008000,
                   param_4 << 0xc |
                   (uVar1 & 0x1fe0) << 6 |
                   param_2 << 8 |
                   param_3 << 5 |
                   (param_6 & 0xff) << 4 |
                   (param_5 & 0xff) << 3 | (param_7 & 0xff) << 2 | uVar2 >> 4 & 0x1fe | uVar3 |
                   0x41000000);
  return;
}

