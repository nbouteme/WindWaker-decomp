#include <gx/GXFrameBuf.h>
#include <gx/GXTexture.h>
#include <Runtime.PPCEABI.H/runtime.h>


namespace gx {

void GXSetDispCopySrc(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = gx;
  *(undefined4 *)(gx + 0x1e0) = 0;
  *(uint *)(iVar1 + 0x1e0) = *(uint *)(iVar1 + 0x1e0) & 0xfffffc00 | param_1 & 0xffff;
  *(uint *)(iVar1 + 0x1e0) = *(uint *)(iVar1 + 0x1e0) & 0xfff003ff | (param_2 & 0xffff) << 10;
  *(uint *)(iVar1 + 0x1e0) = *(uint *)(iVar1 + 0x1e0) & 0xffffff | 0x49000000;
  *(undefined4 *)(iVar1 + 0x1e4) = 0;
  *(uint *)(iVar1 + 0x1e4) = *(uint *)(iVar1 + 0x1e4) & 0xfffffc00 | (param_3 & 0xffff) - 1;
  *(uint *)(iVar1 + 0x1e4) =
       *(uint *)(iVar1 + 0x1e4) & 0xfff003ff | ((param_4 & 0xffff) - 1) * 0x400;
  *(uint *)(iVar1 + 0x1e4) = *(uint *)(iVar1 + 0x1e4) & 0xffffff | 0x4a000000;
  return;
}


void GXSetTexCopySrc(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = gx;
  *(undefined4 *)(gx + 0x1f0) = 0;
  *(uint *)(iVar1 + 0x1f0) = *(uint *)(iVar1 + 0x1f0) & 0xfffffc00 | param_1 & 0xffff;
  *(uint *)(iVar1 + 0x1f0) = *(uint *)(iVar1 + 0x1f0) & 0xfff003ff | (param_2 & 0xffff) << 10;
  *(uint *)(iVar1 + 0x1f0) = *(uint *)(iVar1 + 0x1f0) & 0xffffff | 0x49000000;
  *(undefined4 *)(iVar1 + 500) = 0;
  *(uint *)(iVar1 + 500) = *(uint *)(iVar1 + 500) & 0xfffffc00 | (param_3 & 0xffff) - 1;
  *(uint *)(iVar1 + 500) = *(uint *)(iVar1 + 500) & 0xfff003ff | ((param_4 & 0xffff) - 1) * 0x400;
  *(uint *)(iVar1 + 500) = *(uint *)(iVar1 + 500) & 0xffffff | 0x4a000000;
  return;
}


void GXSetDispCopyDst(uint param_1)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = gx;
  *(undefined4 *)(gx + 0x1e8) = 0;
  puVar2 = (uint *)(iVar1 + 0x1e8);
  *puVar2 = *(uint *)(iVar1 + 0x1e8) & 0xfffffc00 | (int)((param_1 & 0x7fff) << 1) >> 5;
  *puVar2 = *puVar2 & 0xffffff | 0x4d000000;
  return;
}


void GXSetTexCopyDst(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  int local_18;
  undefined auStack20 [4];
  int local_10 [2];
  
  uVar5 = param_3 & 0xf;
  *(undefined *)(gx + 0x200) = 0;
  if (param_3 == 0x13) {
    uVar5 = 0xb;
  }
  if ((param_3 == 0x26) || ((((int)param_3 < 0x26 && ((int)param_3 < 4)) && (-1 < (int)param_3)))) {
    *(uint *)(gx + 0x1fc) = *(uint *)(gx + 0x1fc) & 0xfffe7fff | 0x18000;
  }
  else {
    *(uint *)(gx + 0x1fc) = *(uint *)(gx + 0x1fc) & 0xfffe7fff | 0x10000;
  }
  iVar1 = gx;
  uVar2 = countLeadingZeros((param_3 & 0x10) - 0x10);
  *(char *)(gx + 0x200) = (char)(uVar2 >> 5);
  *(uint *)(iVar1 + 0x1fc) = uVar5 & 8 | *(uint *)(iVar1 + 0x1fc) & 0xfffffff7;
  __GetImageTileCount(param_3,param_1,param_2,local_10,auStack20,&local_18);
  iVar1 = gx;
  *(undefined4 *)(gx + 0x1f8) = 0;
  puVar3 = (uint *)(iVar1 + 0x1f8);
  puVar4 = (uint *)(iVar1 + 0x1fc);
  *puVar3 = *puVar3 & 0xfffffc00 | local_10[0] * local_18;
  *puVar3 = *puVar3 & 0xffffff | 0x4d000000;
  *puVar4 = *puVar4 & 0xfffffdff | (param_4 & 0xff) << 9;
  *puVar4 = *puVar4 & 0xffffff8f | (uVar5 & 7) << 4;
  return;
}


void GXSetDispCopyFrame2Field(int param_1)

{
  int iVar1;
  
  iVar1 = gx;
  *(uint *)(gx + 0x1ec) = *(uint *)(gx + 0x1ec) & 0xffffcfff | param_1 << 0xc;
  *(uint *)(iVar1 + 0x1fc) = *(uint *)(iVar1 + 0x1fc) & 0xffffcfff;
  return;
}


void GXSetCopyClamp(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = gx;
  uVar2 = countLeadingZeros((param_1 & 1) - 1);
  uVar3 = uVar2 >> 5 & 0xff;
  *(uint *)(gx + 0x1ec) = *(uint *)(gx + 0x1ec) & 0xfffffffe | uVar3;
  uVar2 = countLeadingZeros((param_1 & 2) - 2);
  uVar2 = uVar2 >> 4 & 0x1fe;
  *(uint *)(iVar1 + 0x1ec) = *(uint *)(iVar1 + 0x1ec) & 0xfffffffd | uVar2;
  *(uint *)(iVar1 + 0x1fc) = *(uint *)(iVar1 + 0x1fc) & 0xfffffffe | uVar3;
  *(uint *)(iVar1 + 0x1fc) = *(uint *)(iVar1 + 0x1fc) & 0xfffffffd | uVar2;
  return;
}


uint GXGetNumXfbLines(double param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)(float)((double)_95 / param_1));
  param_2 = param_2 & 0xffff;
  uVar1 = uVar1 & 0x1ff;
  uVar2 = ((param_2 - 1) * 0x100) / uVar1;
  uVar3 = uVar2 + 1;
  if ((0x80 < uVar1) && (uVar1 < 0x100)) {
    for (; (uVar1 & 1) == 0; uVar1 = uVar1 >> 1) {
    }
    if (param_2 == (param_2 / uVar1) * uVar1) {
      uVar3 = uVar2 + 2;
    }
  }
  if (0x400 < uVar3) {
    uVar3 = 0x400;
  }
  return uVar3 & 0xffff;
}


double GXGetYScaleFactor(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  
  uVar6 = param_2 & 0xffff;
  uVar2 = param_1 & 0xffff;
  dVar8 = (double)((float)((double)CONCAT44(0x43300000,uVar6) - _150) /
                  (float)((double)CONCAT44(0x43300000,uVar2) - _150));
  uVar3 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)(float)((double)_95 / dVar8));
  uVar3 = uVar3 & 0x1ff;
  uVar1 = (uVar2 - 1) * 0x100;
  uVar4 = uVar1 / uVar3;
  uVar5 = uVar4 + 1;
  if ((0x80 < uVar3) && (uVar3 < 0x100)) {
    for (; (uVar3 & 1) == 0; uVar3 = uVar3 >> 1) {
    }
    if (uVar2 == (uVar2 / uVar3) * uVar3) {
      uVar5 = uVar4 + 2;
    }
  }
  if (0x400 < uVar5) {
    uVar5 = 0x400;
  }
  dVar10 = (double)_95;
  dVar9 = _150;
  while ((param_2 & 0xffff) < uVar5) {
    uVar6 = uVar6 - 1;
    dVar8 = (double)((float)((double)CONCAT44(0x43300000,uVar6) - dVar9) /
                    (float)((double)CONCAT44(0x43300000,param_1 & 0xffff) - dVar9));
    uVar3 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)(float)(dVar10 / dVar8));
    uVar3 = uVar3 & 0x1ff;
    uVar4 = uVar1 / uVar3;
    uVar5 = uVar4 + 1;
    if ((0x80 < uVar3) && (uVar3 < 0x100)) {
      for (; (uVar3 & 1) == 0; uVar3 = uVar3 >> 1) {
      }
      if (uVar2 == (uVar2 / uVar3) * uVar3) {
        uVar5 = uVar4 + 2;
      }
    }
    if (0x400 < uVar5) {
      uVar5 = 0x400;
    }
  }
  dVar11 = (double)_95;
  dVar9 = dVar8;
  dVar10 = _150;
  while (uVar5 < (param_2 & 0xffff)) {
    uVar6 = uVar6 + 1;
    dVar7 = (double)((float)((double)CONCAT44(0x43300000,uVar6) - dVar10) /
                    (float)((double)CONCAT44(0x43300000,param_1 & 0xffff) - dVar10));
    dVar8 = dVar9;
    uVar3 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)(float)(dVar11 / dVar7));
    uVar3 = uVar3 & 0x1ff;
    uVar4 = uVar1 / uVar3;
    uVar5 = uVar4 + 1;
    if ((0x80 < uVar3) && (uVar3 < 0x100)) {
      for (; (uVar3 & 1) == 0; uVar3 = uVar3 >> 1) {
      }
      if (uVar2 == (uVar2 / uVar3) * uVar3) {
        uVar5 = uVar4 + 2;
      }
    }
    dVar9 = dVar7;
    if (0x400 < uVar5) {
      uVar5 = 0x400;
    }
  }
  return dVar8;
}


uint GXSetDispCopyYScale(double param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)(float)((double)_95 / param_1));
  iVar1 = gx;
  uVar2 = uVar2 & 0x1ff;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar2 | 0x4e000000);
  iVar3 = -uVar2 + 0x100;
  *(undefined2 *)(gx + 2) = 0;
  *(uint *)(iVar1 + 0x1ec) =
       *(uint *)(iVar1 + 0x1ec) & 0xfffffbff |
       (iVar3 - ((uint)(iVar3 == 0) + -uVar2 + 0xff)) * 0x400 & 0x3fc00;
  uVar4 = (*(uint *)(iVar1 + 0x1e4) >> 2 & 0x3ff00) / uVar2;
  uVar6 = (*(uint *)(iVar1 + 0x1e4) >> 10 & 0x3ff) + 1;
  uVar5 = uVar4 + 1;
  if ((0x80 < uVar2) && (uVar2 < 0x100)) {
    for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1) {
    }
    if (uVar6 == (uVar6 / uVar2) * uVar2) {
      uVar5 = uVar4 + 2;
    }
  }
  if (0x400 < uVar5) {
    uVar5 = 0x400;
  }
  return uVar5;
}


void GXSetCopyClear(undefined *param_1,uint param_2)

{
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,CONCAT11(param_1[3],*param_1) | 0x4f000000);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(ushort *)(param_1 + 1) | 0x50000000);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,param_2 & 0xffffff | 0x51000000);
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXSetCopyFilter(char param_1,byte *param_2,char param_3,byte *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == '\0') {
    uVar2 = 0x1666666;
    uVar1 = 0x2666666;
    uVar3 = 0x3666666;
    uVar4 = 0x4666666;
  }
  else {
    uVar2 = *param_2 & 0xf | (param_2[1] & 0xf) << 4 | (param_2[2] & 0xf) << 8 |
            (param_2[3] & 0xf) << 0xc | (param_2[4] & 0xf) << 0x10 | (param_2[5] & 0xf) << 0x14 |
            0x1000000;
    uVar1 = param_2[6] & 0xf | (param_2[7] & 0xf) << 4 | (param_2[8] & 0xf) << 8 |
            (param_2[9] & 0xf) << 0xc | (param_2[10] & 0xf) << 0x10 | (param_2[0xb] & 0xf) << 0x14 |
            0x2000000;
    uVar3 = param_2[0xc] & 0xf | (param_2[0xd] & 0xf) << 4 | (param_2[0xe] & 0xf) << 8 |
            (param_2[0xf] & 0xf) << 0xc | (param_2[0x10] & 0xf) << 0x10 |
            (param_2[0x11] & 0xf) << 0x14 | 0x3000000;
    uVar4 = param_2[0x12] & 0xf | (param_2[0x13] & 0xf) << 4 | (param_2[0x14] & 0xf) << 8 |
            (param_2[0x15] & 0xf) << 0xc | (param_2[0x16] & 0xf) << 0x10 |
            (param_2[0x17] & 0xf) << 0x14 | 0x4000000;
  }
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar2);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar1);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar3);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar4);
  if (param_3 == '\0') {
    uVar1 = 0x53595000;
    uVar2 = 0x54000015;
  }
  else {
    uVar1 = *param_4 & 0xfffff03f | 0x53000000 | (param_4[1] & 0x3fff03f) << 6 |
            (param_4[2] & 0xff03f) << 0xc | (uint)param_4[3] << 0x12;
    uVar2 = param_4[4] & 0xfffff03f | 0x54000000 | (param_4[5] & 0x3fff03f) << 6 |
            (uint)param_4[6] << 0xc;
  }
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar1);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar2);
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXSetDispCopyGamma(int param_1)

{
  *(uint *)(gx + 0x1ec) = *(uint *)(gx + 0x1ec) & 0xfffffe7f | param_1 << 7;
  return;
}


void GXCopyDisp(uint param_1,byte param_2)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = gx;
  if (param_2 != 0) {
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,*(uint *)(gx + 0x1d8) & 0xfffffff0 | 0xf);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,*(uint *)(gx + 0x1d0) & 0xfffffffc);
  }
  bVar1 = false;
  if (param_2 == 0) {
    if ((*(uint *)(gx + 0x1dc) & 7) != 3) goto LAB_80323ddc;
  }
  if ((*(uint *)(gx + 0x1dc) >> 6 & 1) == 1) {
    write_volatile_1(DAT_cc008000,0x61);
    bVar1 = true;
    write_volatile_4(0xcc008000,*(uint *)(gx + 0x1dc) & 0xffffffbf);
  }
LAB_80323ddc:
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x1e0));
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x1e4));
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x1e8));
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,param_1 >> 5 & 0xffffff | 0x4b000000);
  *(uint *)(gx + 0x1ec) = *(uint *)(gx + 0x1ec) & 0xfffff7ff | (uint)param_2 << 0xb;
  *(uint *)(iVar2 + 0x1ec) = *(uint *)(iVar2 + 0x1ec) & 0xffffbfff | 0x4000;
  *(uint *)(iVar2 + 0x1ec) = *(uint *)(iVar2 + 0x1ec) & 0xffffff | 0x52000000;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar2 + 0x1ec));
  if (param_2 != 0) {
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,*(undefined4 *)(iVar2 + 0x1d8));
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,*(undefined4 *)(iVar2 + 0x1d0));
  }
  if (bVar1) {
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x1dc));
  }
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXCopyTex(uint param_1,byte param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = gx;
  if (param_2 != 0) {
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,*(uint *)(gx + 0x1d8) & 0xfffffff0 | 0xf);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,*(uint *)(gx + 0x1d0) & 0xfffffffc);
  }
  bVar1 = false;
  uVar3 = *(uint *)(gx + 0x1dc);
  if (*(char *)(gx + 0x200) != '\0') {
    if ((uVar3 & 7) != 3) {
      uVar3 = uVar3 & 0xfffffff8 | 3;
      bVar1 = true;
    }
  }
  if (param_2 == 0) {
    if ((uVar3 & 7) != 3) goto LAB_80323f44;
  }
  if ((uVar3 >> 6 & 1) == 1) {
    bVar1 = true;
    uVar3 = uVar3 & 0xffffffbf;
  }
LAB_80323f44:
  if (bVar1) {
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,uVar3);
  }
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x1f0));
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(gx + 500));
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x1f8));
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,param_1 >> 5 & 0xffffff | 0x4b000000);
  *(uint *)(gx + 0x1fc) = *(uint *)(gx + 0x1fc) & 0xfffff7ff | (uint)param_2 << 0xb;
  *(uint *)(iVar2 + 0x1fc) = *(uint *)(iVar2 + 0x1fc) & 0xffffbfff;
  *(uint *)(iVar2 + 0x1fc) = *(uint *)(iVar2 + 0x1fc) & 0xffffff | 0x52000000;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar2 + 0x1fc));
  if (param_2 != 0) {
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,*(undefined4 *)(iVar2 + 0x1d8));
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,*(undefined4 *)(iVar2 + 0x1d0));
  }
  if (bVar1) {
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x1dc));
  }
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXClearBoundingBox(void)

{
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,0x550003ff);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,0x560003ff);
  *(undefined2 *)(gx + 2) = 0;
  return;
}

