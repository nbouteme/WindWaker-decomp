#include <gx/GXPixel.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <gx/GXBump.h>


namespace gx {

void GXSetFog(_GXFogType param_1,float param_2,float param_3,float param_4,float param_5,
                 _GXColor *param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  double dVar6;
  
  fVar1 = _138;
  fVar2 = _137;
  fVar3 = _137;
  if ((param_5 != param_4) && (param_3 != param_2)) {
    fVar1 = param_5 / (param_5 - param_4);
    fVar2 = (param_5 * param_4) / ((param_5 - param_4) * (param_3 - param_2));
    fVar3 = param_2 / (param_3 - param_2);
  }
  iVar4 = 0;
  while (dVar6 = (double)fVar1, _139 < dVar6) {
    iVar4 = iVar4 + 1;
    fVar1 = (float)(dVar6 * (double)_138);
  }
  for (; ((double)_137 < dVar6 && (dVar6 < _141)); dVar6 = (double)(float)(dVar6 * (double)_140)) {
    iVar4 = iVar4 + -1;
  }
  fVar2 = fVar2 / (float)((double)CONCAT44(0x43300000,1 << iVar4 + 1U ^ 0x80000000) - _144);
  uVar5 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)(float)((double)_142 * dVar6));
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,
                   (uint)fVar2 >> 0xc & 0x7ff | (uint)fVar2 >> 0xc & 0x7f800 |
                   (uint)fVar2 >> 0xc & 0x80000 | 0xee000000);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar5 & 0xffffff | 0xef000000);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,iVar4 + 1U & 0xffffff | 0xf0000000);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,
                   (uint)fVar3 >> 0xc & 0x7ff | (uint)fVar3 >> 0xc & 0x7f800 |
                   (uint)fVar3 >> 0xc & 0x80000 | (param_1 & 7) << 0x15 | 0xf1000000);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(uint3 *)param_6 | 0xf2000000);
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXSetFogRangeAdj(bool param_1,u16 param_2,_GXFogAdjTable *param_3)

{
  if (param_1 != false) {
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,param_3->r[0] & 0xfff | (param_3->r[1] & 0xfff) << 0xc | 0xe9000000)
    ;
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,param_3->r[2] & 0xfff | (param_3->r[3] & 0xfff) << 0xc | 0xea000000)
    ;
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,param_3->r[4] & 0xfff | (param_3->r[5] & 0xfff) << 0xc | 0xeb000000)
    ;
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,param_3->r[6] & 0xfff | (param_3->r[7] & 0xfff) << 0xc | 0xec000000)
    ;
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,param_3->r[8] & 0xfff | (param_3->r[9] & 0xfff) << 0xc | 0xed000000)
    ;
  }
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,param_2 + 0x156 & 0xfffbff | (uint)param_1 << 10 | 0xe8000000);
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXSetBlendMode(GXBlendMode param_1,GXBlendFactor param_2,GXBlendFactor param_3,
                       GXLogicOp param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  GXBlendMode GVar4;
  
  iVar1 = gx;
  uVar3 = countLeadingZeros(3 - param_1);
  uVar2 = countLeadingZeros(2 - param_1);
  write_volatile_1(DAT_cc008000,0x61);
  GVar4 = (param_3 & 7) << 5 |
          (param_2 & 7) << 8 |
          (param_4 & 0xf) << 0xc |
          uVar2 >> 4 & GX_BM_LOGIC |
          param_1 & GX_BM_BLEND | (uVar3 & 0x20) << 6 | *(GXBlendMode *)(gx + 0x1d0) & 0xffff001c;
  write_volatile_4(0xcc008000,GVar4);
  *(GXBlendMode *)(gx + 0x1d0) = GVar4;
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXSetColorUpdate(bool param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = gx;
  uVar2 = (param_1 & 1) << 3 | *(uint *)(gx + 0x1d0) & 0xfffffff7;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar2);
  *(uint *)(gx + 0x1d0) = uVar2;
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXSetAlphaUpdate(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = gx;
  uVar2 = (param_1 & 1) << 4 | *(uint *)(gx + 0x1d0) & 0xffffffef;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar2);
  *(uint *)(gx + 0x1d0) = uVar2;
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXSetZMode(bool param_1,GXCompare param_2,bool param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = gx;
  write_volatile_1(DAT_cc008000,0x61);
  uVar2 = (param_3 & 1) << 4 | (param_2 & 7) << 1 | param_1 & 1 | *(uint *)(gx + 0x1d8) & 0xffffffe0
  ;
  write_volatile_4(0xcc008000,uVar2);
  *(uint *)(gx + 0x1d8) = uVar2;
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXSetZCompLoc(uint param_1)

{
  int iVar1;
  
  iVar1 = gx;
  *(uint *)(gx + 0x1dc) = *(uint *)(gx + 0x1dc) & 0xffffffbf | (param_1 & 0xff) << 6;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 0x1dc));
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXSetPixelFmt(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = gx;
  uVar3 = *(uint *)(gx + 0x1dc);
  *(uint *)(gx + 0x1dc) = uVar3 & 0xfffffff8 | *(uint *)(&p2f_247 + param_1 * 4);
  *(uint *)(iVar1 + 0x1dc) = *(uint *)(iVar1 + 0x1dc) & 0xffffffc7 | param_2 << 3;
  iVar2 = gx;
  if (uVar3 != *(uint *)(iVar1 + 0x1dc)) {
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,*(uint *)(iVar1 + 0x1dc));
    *(uint *)(gx + 0x204) = *(uint *)(gx + 0x204) & 0xfffffdff | (uint)(param_1 == 2) << 9;
    *(uint *)(iVar2 + 0x4f4) = *(uint *)(iVar2 + 0x4f4) | 4;
  }
  iVar1 = gx;
  if (*(uint *)(&p2f_247 + param_1 * 4) == 4) {
    *(uint *)(gx + 0x1d4) = (param_1 + -4) * 0x200 & 0x600U | *(uint *)(gx + 0x1d4) & 0xfffff9ff;
    *(uint *)(iVar1 + 0x1d4) = *(uint *)(iVar1 + 0x1d4) & 0xffffff | 0x42000000;
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 0x1d4));
  }
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXSetDither(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = gx;
  write_volatile_1(DAT_cc008000,0x61);
  uVar2 = *(uint *)(gx + 0x1d0) & 0xfffffffb | (param_1 & 0xff) << 2;
  write_volatile_4(0xcc008000,uVar2);
  *(uint *)(gx + 0x1d0) = uVar2;
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXSetDstAlpha(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = gx;
  write_volatile_1(DAT_cc008000,0x61);
  uVar2 = (param_1 & 1) << 8 | param_2 & 0xff | *(uint *)(gx + 0x1d4) & 0xfffffe00;
  write_volatile_4(0xcc008000,uVar2);
  *(uint *)(gx + 0x1d4) = uVar2;
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXSetFieldMask(uint param_1,uint param_2)

{
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,param_2 & 0xfd | (param_1 & 0xff) << 1 | 0x44000000);
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXSetFieldMode(uint param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = gx;
  *(uint *)(gx + 0x7c) = *(uint *)(gx + 0x7c) & 0xffbfffff | (param_2 & 0xff) << 0x16;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 0x7c));
  __GXFlushTextureState();
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,param_1 & 0xff | 0x68000000);
  __GXFlushTextureState();
  return;
}

