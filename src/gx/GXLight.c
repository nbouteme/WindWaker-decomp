#include <gx/GXLight.h>
#include <MSL_C.PPCEABI.bare.H/math_ppc.h>


namespace gx {

void GXInitLightAttn(_GXLightObj *param_1,double param_2,double param_3,double param_4,
                        double param_5,double param_6,double param_7)

{
  param_1->a[0] = (float)param_2;
  param_1->a[1] = (float)param_3;
  param_1->a[2] = (float)param_4;
  param_1->k[0] = (float)param_5;
  param_1->k[1] = (float)param_6;
  param_1->k[2] = (float)param_7;
  return;
}


void GXInitLightSpot(_GXLightObj *param_1,float param_2,GXSpotFn param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  if ((param_2 <= _134) || (_135 < param_2)) {
    param_3 = GX_SP_OFF;
  }
  fVar4 = MSL_C.PPCEABI.bare.H::cosf((_136 * param_2) / _137);
  fVar2 = _134;
  fVar3 = _134;
  fVar1 = _140;
  switch(param_3) {
  case GX_SP_FLAT:
    fVar1 = _138 * fVar4;
    fVar2 = _139;
    break;
  case GX_SP_COS:
    fVar2 = _140 / (_140 - fVar4);
    fVar1 = -fVar4 * fVar2;
    break;
  case GX_SP_COS2:
    fVar3 = _140 / (_140 - fVar4);
    fVar2 = -fVar4 * fVar3;
    fVar1 = _134;
    break;
  case GX_SP_SHARP:
    fVar1 = _140 / ((_140 - fVar4) * (_140 - fVar4));
    fVar2 = _141 * fVar1;
    fVar3 = -fVar1;
    fVar1 = fVar1 * fVar4 * (fVar4 - _141);
    break;
  case GX_SP_RING1:
    fVar1 = _140 / ((_140 - fVar4) * (_140 - fVar4));
    fVar3 = _142 * fVar1;
    fVar2 = _143 * (_140 + fVar4) * fVar1;
    fVar1 = fVar3 * fVar4;
    break;
  case GX_SP_RING2:
    fVar1 = _140 / ((_140 - fVar4) * (_140 - fVar4));
    fVar2 = _143 * fVar4 * fVar1;
    fVar3 = _144 * fVar1;
    fVar1 = _140 - fVar1 * _141 * fVar4 * fVar4;
  }
  param_1->a[0] = fVar1;
  param_1->a[1] = fVar2;
  param_1->a[2] = fVar3;
  return;
}


void GXInitLightDistAttn(_GXLightObj *param_1,float param_2,float param_3,GXDistAttnFn param_4)

{
  float fVar1;
  float fVar2;
  
  if (param_2 < _134) {
    param_4 = GX_DA_OFF;
  }
  if ((param_3 <= _134) || (_140 <= param_3)) {
    param_4 = GX_DA_OFF;
  }
  if (param_4 == GX_DA_MEDIUM) {
    fVar2 = _160 * (_140 - param_3);
    fVar1 = fVar2 / (param_2 * param_3 * param_2);
    fVar2 = fVar2 / (param_3 * param_2);
  }
  else {
    fVar1 = _134;
    fVar2 = _134;
    if ((int)param_4 < 2) {
      if ((param_4 != GX_DA_OFF) && (-1 < (int)param_4)) {
        fVar2 = (_140 - param_3) / (param_3 * param_2);
      }
    }
    else {
      if ((int)param_4 < 4) {
        fVar1 = (_140 - param_3) / (param_2 * param_3 * param_2);
      }
    }
  }
  param_1->k[0] = _140;
  param_1->k[1] = fVar2;
  param_1->k[2] = fVar1;
  return;
}


void GXInitLightPos(double param_1,double param_2,double param_3,_GXLightObj *param_4)

{
  param_4->lpos[0] = (float)param_1;
  param_4->lpos[1] = (float)param_2;
  param_4->lpos[2] = (float)param_3;
  return;
}


void GXInitLightDir(double param_1,double param_2,double param_3,_GXLightObj *param_4)

{
  param_4->ldir[0] = (float)-param_1;
  param_4->ldir[1] = (float)-param_2;
  param_4->ldir[2] = (float)-param_3;
  return;
}


void GXInitLightColor(_GXLightObj *param_1,_GXColor *param_2)

{
  param_1->color = *param_2;
  return;
}


/* WARNING: Removing unreachable block (ram,0x80324350) */
/* WARNING: Removing unreachable block (ram,0x80324348) */
/* WARNING: Removing unreachable block (ram,0x80324340) */
/* WARNING: Removing unreachable block (ram,0x80324344) */
/* WARNING: Removing unreachable block (ram,0x8032434c) */
/* WARNING: Removing unreachable block (ram,0x80324354) */

void GXLoadLightObjImm(_GXLightObj *param_1,GXLightID param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  
  iVar1 = countLeadingZeros(param_2);
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_4(0xcc008000,((0x1f - iVar1) * 0x10 & 0x70U) + 0x600 | 0xf0000);
  uVar12 = __psq_l0(param_1->a,0);
  uVar13 = __psq_l1(param_1->a,0);
  uVar10 = __psq_l0(param_1->a + 2,0);
  uVar11 = __psq_l1(param_1->a + 2,0);
  uVar8 = __psq_l0(param_1->k + 1,0);
  uVar9 = __psq_l1(param_1->k + 1,0);
  uVar6 = __psq_l0(param_1->lpos,0);
  uVar7 = __psq_l1(param_1->lpos,0);
  uVar4 = __psq_l0(param_1->lpos + 2,0);
  uVar5 = __psq_l1(param_1->lpos + 2,0);
  uVar2 = __psq_l0(param_1->ldir + 1,0);
  uVar3 = __psq_l1(param_1->ldir + 1,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,0);
  write_volatile_4(0xcc008000,param_1->color);
  __psq_st0(0xcc008000,uVar12,0);
  __psq_st1(0xcc008000,uVar13,0);
  __psq_st0(0xcc008000,uVar10,0);
  __psq_st1(0xcc008000,uVar11,0);
  __psq_st0(0xcc008000,uVar8,0);
  __psq_st1(0xcc008000,uVar9,0);
  __psq_st0(0xcc008000,uVar6,0);
  __psq_st1(0xcc008000,uVar7,0);
  __psq_st0(0xcc008000,uVar4,0);
  __psq_st1(0xcc008000,uVar5,0);
  __psq_st0(0xcc008000,uVar2,0);
  __psq_st1(0xcc008000,uVar3,0);
  *(undefined2 *)(gx + 2) = 1;
  return;
}


void GXSetChanAmbColor(int param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 3) {
    iVar1 = 1;
    uVar2 = *(uint *)(gx + 0xac) & 0xffffff00 | (uint)*(byte *)((int)param_2 + 3);
  }
  else {
    if (param_1 < 3) {
      if (param_1 == 1) {
        iVar1 = 1;
        uVar2 = *(uint *)(gx + 0xac) & 0xff | *param_2 & 0xffffff00;
      }
      else {
        if (param_1 < 1) {
          if (param_1 < 0) {
            return;
          }
          iVar1 = 0;
          uVar2 = *(uint *)(gx + 0xa8) & 0xff | *param_2 & 0xffffff00;
        }
        else {
          iVar1 = 0;
          uVar2 = *(uint *)(gx + 0xa8) & 0xffffff00 | (uint)*(byte *)((int)param_2 + 3);
        }
      }
    }
    else {
      if (param_1 == 5) {
        uVar2 = *param_2;
        iVar1 = 1;
      }
      else {
        if (4 < param_1) {
          return;
        }
        uVar2 = *param_2;
        iVar1 = 0;
      }
    }
  }
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_4(0xcc008000,iVar1 + 0x100a);
  iVar1 = gx + iVar1 * 4;
  write_volatile_4(0xcc008000,uVar2);
  *(undefined2 *)(gx + 2) = 1;
  *(uint *)(iVar1 + 0xa8) = uVar2;
  return;
}


void GXSetChanMatColor(int param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 3) {
    iVar1 = 1;
    uVar2 = *(uint *)(gx + 0xb4) & 0xffffff00 | (uint)*(byte *)((int)param_2 + 3);
  }
  else {
    if (param_1 < 3) {
      if (param_1 == 1) {
        iVar1 = 1;
        uVar2 = *(uint *)(gx + 0xb4) & 0xff | *param_2 & 0xffffff00;
      }
      else {
        if (param_1 < 1) {
          if (param_1 < 0) {
            return;
          }
          iVar1 = 0;
          uVar2 = *(uint *)(gx + 0xb0) & 0xff | *param_2 & 0xffffff00;
        }
        else {
          iVar1 = 0;
          uVar2 = *(uint *)(gx + 0xb0) & 0xffffff00 | (uint)*(byte *)((int)param_2 + 3);
        }
      }
    }
    else {
      if (param_1 == 5) {
        uVar2 = *param_2;
        iVar1 = 1;
      }
      else {
        if (4 < param_1) {
          return;
        }
        uVar2 = *param_2;
        iVar1 = 0;
      }
    }
  }
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_4(0xcc008000,iVar1 + 0x100c);
  iVar1 = gx + iVar1 * 4;
  write_volatile_4(0xcc008000,uVar2);
  *(undefined2 *)(gx + 2) = 1;
  *(uint *)(iVar1 + 0xb0) = uVar2;
  return;
}


void GXSetNumChans(uint param_1)

{
  int iVar1;
  
  iVar1 = gx;
  *(uint *)(gx + 0x204) = *(uint *)(gx + 0x204) & 0xffffff8f | (param_1 & 0xff) << 4;
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_4(0xcc008000,0x1009);
  write_volatile_4(0xcc008000,param_1 & 0xff);
  *(uint *)(iVar1 + 0x4f4) = *(uint *)(iVar1 + 0x4f4) | 4;
  return;
}


void GXSetChanCtrl(GXChannelID param_1,bool param_2,GXColorSrc param_3,GXColorSrc param_4,
                      int lightMask,GXDiffuseFn param_6,GXAttnFn param_7)

{
  int iVar1;
  uint uVar2;
  
  if (param_7 == GX_AF_SPEC) {
    param_6 = GX_DF_NONE;
  }
  iVar1 = -param_7 + 2;
  write_volatile_1(DAT_cc008000,0x10);
  uVar2 = (lightMask & 0xf0U) << 7 |
          (lightMask & 0xfU) << 2 |
          ((((((uint)param_2 << 1 | param_4) & 0xffffffbf | param_3 << 6) & 0xfffffe7f |
            param_6 << 7) & 0xfffffdff | (iVar1 - ((uint)(iVar1 == 0) + -param_7 + 1)) * 0x200) &
           0xfffffbc3 | (uint)(param_7 != GX_AF_SPEC) * 0x400) & 0xffff87ff;
  write_volatile_4(0xcc008000,(param_1 & 3) + 0x100e);
  write_volatile_4(0xcc008000,uVar2);
  if (param_1 == GX_COLOR0A0) {
    write_volatile_1(DAT_cc008000,0x10);
    write_volatile_4(0xcc008000,0x1010);
    write_volatile_4(0xcc008000,uVar2);
  }
  else {
    if (param_1 == GX_COLOR1A1) {
      write_volatile_1(DAT_cc008000,0x10);
      write_volatile_4(0xcc008000,0x1011);
      write_volatile_4(0xcc008000,uVar2);
    }
  }
  *(undefined2 *)(gx + 2) = 1;
  return;
}

