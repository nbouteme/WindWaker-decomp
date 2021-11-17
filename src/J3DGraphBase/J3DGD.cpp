#include <J3DGraphBase/J3DGD.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <gd/GDBase.h>


namespace J3DGraphBase {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall J3DGDSetGenMode(unsigned char,
                             unsigned char,
                             unsigned char,
                             unsigned char,
                             _GXCullMode) */

void J3DGDSetGenMode(uint param_1,uint param_2,uint param_3,byte param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  undefined *puVar5;
  
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 10U) {
    gd::GDOverflowed();
  }
  puVar5 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar5 + 1;
  *puVar5 = 0x61;
  puVar5 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar5 + 1;
  *puVar5 = 0xfe;
  puVar5 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar5 + 1;
  *puVar5 = 7;
  puVar5 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar5 + 1;
  *puVar5 = 0xfc;
  puVar5 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar5 + 1;
  *puVar5 = 0x3f;
  uVar1 = ((param_3 & 0xff) - 1) * 0x400;
  uVar2 = param_1 & 0xff | (param_2 & 0xff) << 4;
  uVar3 = (uint)(byte)(&cm2hw_547)[param_5] << 0xe | uVar1 | uVar2;
  puVar5 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar5 + 1;
  *puVar5 = 0x61;
  puVar5 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar5 + 1;
  *puVar5 = (char)(uVar1 >> 0x18);
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = param_4 | (byte)(uVar3 >> 0x10);
  puVar5 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar5 + 1;
  *puVar5 = (char)(uVar3 >> 8);
  puVar5 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar5 + 1;
  *puVar5 = (char)uVar2;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall J3DGDSetGenMode_3Param(unsigned char,
                                    unsigned char,
                                    unsigned char) */

void J3DGDSetGenMode_3Param(undefined param_1,uint param_2,byte param_3)

{
  int iVar1;
  undefined *puVar2;
  byte *pbVar3;
  
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 10U) {
    gd::GDOverflowed();
  }
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0x61;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0xfe;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 7;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0x3c;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0xf;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0x61;
  iVar1 = ((param_2 & 0xff) - 1) * 0x400;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)((uint)iVar1 >> 0x18);
  pbVar3 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar3 + 1;
  *pbVar3 = param_3 | (byte)((uint)iVar1 >> 0x10);
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)((uint)iVar1 >> 8);
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = param_1;
  return;
}


/* __stdcall J3DGDSetIndTexStageNum(unsigned long) */

void J3DGDSetIndTexStageNum(undefined4 param_1)

{
  undefined *puVar1;
  
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 10U) {
    gd::GDOverflowed();
  }
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0xfe;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 7;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)((uint)param_1 >> 8);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)param_1;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  return;
}


/* __stdcall J3DGDSetLightAttn(_GXLightID,
                               float,
                               float,
                               float,
                               float,
                               float,
                               float) */

void J3DGDSetLightAttn
               (double param_1,double param_2,double param_3,double param_4,double param_5,
               double param_6,undefined4 param_7)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  
  iVar2 = countLeadingZeros(param_7);
  uVar3 = 0x1fU - iVar2 & 0xffff;
  if (7 < uVar3) {
    uVar3 = 0;
  }
  iVar2 = (uVar3 & 0xfff) * 0x10 + 0x604;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 0x10;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 0;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 5;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)iVar2 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)iVar2;
  fVar1 = (float)param_1;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x18);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x10);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = SUB41(fVar1,0);
  fVar1 = (float)param_2;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x18);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x10);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = SUB41(fVar1,0);
  fVar1 = (float)param_3;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x18);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x10);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = SUB41(fVar1,0);
  fVar1 = (float)param_4;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x18);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x10);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = SUB41(fVar1,0);
  fVar1 = (float)param_5;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x18);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x10);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = SUB41(fVar1,0);
  fVar1 = (float)param_6;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x18);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x10);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = SUB41(fVar1,0);
  return;
}


/* __stdcall J3DGDSetLightColor(_GXLightID,
                                _GXColor) */

void J3DGDSetLightColor(undefined4 param_1,undefined *param_2)

{
  undefined uVar1;
  undefined uVar2;
  undefined uVar3;
  undefined uVar4;
  int iVar5;
  uint uVar6;
  undefined *puVar7;
  
  uVar1 = param_2[3];
  uVar2 = param_2[2];
  uVar3 = *param_2;
  uVar4 = param_2[1];
  iVar5 = countLeadingZeros(param_1);
  uVar6 = 0x1fU - iVar5 & 0xffff;
  if (7 < uVar6) {
    uVar6 = 0;
  }
  iVar5 = (uVar6 & 0xfff) * 0x10 + 0x603;
  puVar7 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar7 + 1;
  *puVar7 = 0x10;
  puVar7 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar7 + 1;
  *puVar7 = 0;
  puVar7 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar7 + 1;
  *puVar7 = 0;
  puVar7 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar7 + 1;
  *puVar7 = (char)((uint)iVar5 >> 8);
  puVar7 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar7 + 1;
  *puVar7 = (char)iVar5;
  puVar7 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar7 + 1;
  *puVar7 = uVar3;
  puVar7 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar7 + 1;
  *puVar7 = uVar4;
  puVar7 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar7 + 1;
  *puVar7 = uVar2;
  puVar7 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar7 + 1;
  *puVar7 = uVar1;
  return;
}


/* __stdcall J3DGDSetLightPos(_GXLightID,
                              float,
                              float,
                              float) */

void J3DGDSetLightPos(double param_1,double param_2,double param_3,undefined4 param_4)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  
  iVar2 = countLeadingZeros(param_4);
  uVar3 = 0x1fU - iVar2 & 0xffff;
  if (7 < uVar3) {
    uVar3 = 0;
  }
  iVar2 = (uVar3 & 0xfff) * 0x10 + 0x60a;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 0x10;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 0;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 2;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)iVar2 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)iVar2;
  fVar1 = (float)param_1;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x18);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x10);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = SUB41(fVar1,0);
  fVar1 = (float)param_2;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x18);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x10);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = SUB41(fVar1,0);
  fVar1 = (float)param_3;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x18);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x10);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = SUB41(fVar1,0);
  return;
}


/* __stdcall J3DGDSetLightDir(_GXLightID,
                              float,
                              float,
                              float) */

void J3DGDSetLightDir(double param_1,double param_2,double param_3,undefined4 param_4)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  
  iVar2 = countLeadingZeros(param_4);
  uVar3 = 0x1fU - iVar2 & 0xffff;
  if (7 < uVar3) {
    uVar3 = 0;
  }
  iVar2 = (uVar3 & 0xfff) * 0x10 + 0x60d;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 0x10;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 0;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 2;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)iVar2 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)iVar2;
  fVar1 = (float)param_1;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x18);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x10);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = SUB41(fVar1,0);
  fVar1 = (float)param_2;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x18);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x10);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = SUB41(fVar1,0);
  fVar1 = (float)param_3;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x18);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 0x10);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)((uint)fVar1 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = SUB41(fVar1,0);
  return;
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* __stdcall J3DGDSetVtxAttrFmtv(_GXVtxFmt,
                                 _GXVtxAttrFmtList *,
                                 bool) */

void J3DGDSetVtxAttrFmtv(char param_1,int *param_2,char param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  char *pcVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  uint local_98;
  int local_94;
  int local_90;
  uint local_8c;
  int local_88;
  uint local_84;
  uint local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  uint local_60;
  int local_5c;
  uint local_58;
  
  local_58 = 1;
  local_5c = 4;
  local_60 = 0;
  iVar23 = 0;
  local_64 = 4;
  iVar22 = 0;
  local_68 = 1;
  local_6c = 5;
  local_70 = 1;
  local_74 = 5;
  local_78 = 1;
  local_7c = 4;
  local_80 = 0;
  local_84 = 1;
  local_88 = 4;
  local_8c = 0;
  local_90 = 1;
  local_94 = 4;
  local_98 = 0;
  iVar7 = 1;
  iVar21 = 4;
  uVar20 = 0;
  iVar19 = 1;
  iVar18 = 4;
  uVar17 = 0;
  iVar16 = 1;
  iVar15 = 4;
  uVar14 = 0;
  iVar13 = 1;
  iVar12 = 4;
  uVar11 = 0;
  iVar10 = 1;
  iVar9 = 4;
  uVar8 = 0;
  for (; *param_2 != 0xff; param_2 = param_2 + 4) {
    switch(*param_2) {
    case 9:
      local_58 = param_2[1];
      local_5c = param_2[2];
      local_60 = (uint)*(byte *)(param_2 + 3);
      break;
    case 10:
    case 0x19:
      local_64 = param_2[2];
      if (param_2[1] == 2) {
        iVar23 = 1;
        iVar22 = 1;
      }
      else {
        iVar23 = 1;
        if (param_3 == '\0') {
          iVar23 = param_2[1];
        }
        iVar22 = 0;
      }
      break;
    case 0xb:
      local_68 = param_2[1];
      local_6c = param_2[2];
      break;
    case 0xc:
      local_70 = param_2[1];
      local_74 = param_2[2];
      break;
    case 0xd:
      local_78 = param_2[1];
      local_7c = param_2[2];
      local_80 = (uint)*(byte *)(param_2 + 3);
      break;
    case 0xe:
      local_84 = param_2[1];
      local_88 = param_2[2];
      local_8c = (uint)*(byte *)(param_2 + 3);
      break;
    case 0xf:
      local_90 = param_2[1];
      local_94 = param_2[2];
      local_98 = (uint)*(byte *)(param_2 + 3);
      break;
    case 0x10:
      iVar7 = param_2[1];
      iVar21 = param_2[2];
      uVar20 = (uint)*(byte *)(param_2 + 3);
      break;
    case 0x11:
      iVar19 = param_2[1];
      iVar18 = param_2[2];
      uVar17 = (uint)*(byte *)(param_2 + 3);
      break;
    case 0x12:
      iVar16 = param_2[1];
      iVar15 = param_2[2];
      uVar14 = (uint)*(byte *)(param_2 + 3);
      break;
    case 0x13:
      iVar13 = param_2[1];
      iVar12 = param_2[2];
      uVar11 = (uint)*(byte *)(param_2 + 3);
      break;
    case 0x14:
      iVar10 = param_2[1];
      iVar9 = param_2[2];
      uVar8 = (uint)*(byte *)(param_2 + 3);
    }
  }
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 0x12U) {
    gd::GDOverflowed();
  }
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 8;
  pcVar5 = *(char **)(gd::__GDCurrentDL + 8);
  *(char **)(gd::__GDCurrentDL + 8) = pcVar5 + 1;
  *pcVar5 = param_1 + 'p';
  uVar1 = local_60 << 4 | local_58 | local_5c << 1;
  uVar2 = local_6c << 0xe | local_68 << 0xd | local_64 << 10 | iVar23 << 9 | uVar1;
  uVar3 = local_7c << 0x16 | local_78 << 0x15 | local_74 << 0x12 | local_70 << 0x11 | uVar2;
  pbVar6 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar6 + 1;
  *pbVar6 = (byte)((uint)(iVar22 << 0x1f) >> 0x18) |
            (byte)((local_80 << 0x19) >> 0x18) | (byte)(uVar3 >> 0x18) | 0x40;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)(uVar3 >> 0x10);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)(uVar2 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)uVar1;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 8;
  pcVar5 = *(char **)(gd::__GDCurrentDL + 8);
  *(char **)(gd::__GDCurrentDL + 8) = pcVar5 + 1;
  *pcVar5 = param_1 + -0x80;
  uVar2 = local_8c << 4 | local_84 | local_88 << 1;
  uVar1 = local_98 << 0xd | local_94 << 10 | local_90 << 9 | uVar2;
  uVar20 = uVar20 << 0x16 | iVar21 << 0x13 | iVar7 << 0x12 | uVar1;
  pbVar6 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar6 + 1;
  *pbVar6 = (byte)((uint)(iVar18 << 0x1c) >> 0x18) |
            (byte)((uint)(iVar19 << 0x1b) >> 0x18) | (byte)(uVar20 >> 0x18) | 0x80;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)(uVar20 >> 0x10);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)(uVar1 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)uVar2;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 8;
  pcVar5 = *(char **)(gd::__GDCurrentDL + 8);
  *(char **)(gd::__GDCurrentDL + 8) = pcVar5 + 1;
  *pcVar5 = param_1 + -0x70;
  uVar17 = iVar15 << 6 | uVar17 | iVar16 << 5;
  uVar14 = iVar12 << 0xf | iVar13 << 0xe | uVar14 << 9 | uVar17;
  uVar11 = iVar10 << 0x17 | uVar11 << 0x12 | uVar14;
  pbVar6 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar6 + 1;
  *pbVar6 = (byte)((uVar8 << 0x1b) >> 0x18) | (byte)iVar9 | (byte)(uVar11 >> 0x18);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)(uVar11 >> 0x10);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)(uVar14 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)uVar17;
  return;
}


/* __stdcall J3DGDSetTexCoordGen(_GXTexGenType,
                                 _GXTexGenSrc) */

void J3DGDSetTexCoordGen(int param_1,int param_2)

{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar6 = 0;
  iVar7 = 0;
  iVar8 = 5;
  iVar3 = 5;
  iVar5 = 0;
  switch(param_2) {
  case 0:
    iVar8 = 0;
    iVar6 = 1;
    break;
  case 1:
    iVar8 = 1;
    iVar6 = 1;
    break;
  case 2:
    iVar8 = 3;
    iVar6 = 1;
    break;
  case 3:
    iVar8 = 4;
    iVar6 = 1;
    break;
  case 4:
    iVar8 = 5;
    break;
  case 5:
    iVar8 = 6;
    break;
  case 6:
    iVar8 = 7;
    break;
  case 7:
    iVar8 = 8;
    break;
  case 8:
    iVar8 = 9;
    break;
  case 9:
    iVar8 = 10;
    break;
  case 10:
    iVar8 = 0xb;
    break;
  case 0xb:
    iVar8 = 0xc;
    break;
  case 0xc:
    iVar3 = 0;
    break;
  case 0xd:
    iVar3 = 1;
    break;
  case 0xe:
    iVar3 = 2;
    break;
  case 0xf:
    iVar3 = 3;
    break;
  case 0x10:
    iVar3 = 4;
    break;
  case 0x11:
    iVar3 = 5;
    break;
  case 0x12:
    iVar3 = 6;
    break;
  case 0x13:
    iVar8 = 2;
    break;
  case 0x14:
    iVar8 = 2;
  }
  if (param_1 == 1) {
    param_2 = 0;
  }
  else {
    if (param_1 < 1) {
      if (-1 < param_1) {
        param_2 = 0;
        iVar7 = 1;
      }
    }
    else {
      if (param_1 == 10) {
        if (param_2 == 0x13) {
          param_2 = 2;
        }
        else {
          param_2 = 3;
        }
      }
      else {
        if (param_1 < 10) {
          param_2 = 1;
          iVar5 = param_1 + -2;
        }
      }
    }
  }
  uVar1 = iVar8 << 7 | param_2 << 4 | iVar7 << 1 | iVar6 << 2;
  uVar4 = iVar5 << 0xf | iVar3 << 0xc | uVar1;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)(uVar4 >> 0x18);
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)(uVar4 >> 0x10);
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)(uVar4 >> 8);
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)uVar1;
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall J3DGDSetTexCoordScale2(_GXTexCoordID,
                                    unsigned short,
                                    unsigned char,
                                    unsigned char,
                                    unsigned short,
                                    unsigned char,
                                    unsigned char) */

void J3DGDSetTexCoordScale2
               (char param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
               uint param_7)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 0xfU) {
    gd::GDOverflowed();
  }
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0xfe;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 3;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0xff;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0xff;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  uVar2 = (param_2 & 0xffff) - 1;
  uVar3 = (param_4 & 0xff) << 0x11 | uVar2 | (param_3 & 0xff) << 0x10;
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)(uVar3 >> 0x18) | param_1 * '\x02' + 0x30U;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)(uVar3 >> 0x10);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)(uVar2 >> 8);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)uVar2;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0x61;
  uVar2 = (param_5 & 0xffff) - 1;
  uVar3 = (param_7 & 0xff) << 0x11 | uVar2 | (param_6 & 0xff) << 0x10;
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)(uVar3 >> 0x18) | param_1 * '\x02' + 0x31U;
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)(uVar3 >> 0x10);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)(uVar2 >> 8);
  puVar1 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)uVar2;
  return;
}


/* __stdcall J3DGDSetTexLookupMode(_GXTexMapID,
                                   _GXTexWrapMode,
                                   _GXTexWrapMode,
                                   _GXTexFilter,
                                   _GXTexFilter,
                                   float,
                                   float,
                                   float,
                                   unsigned char,
                                   unsigned char,
                                   _GXAnisotropy) */

void J3DGDSetTexLookupMode
               (double param_1,double param_2,double param_3,int param_4,uint param_5,int param_6,
               int param_7,int param_8,uint param_9,uint param_10,int param_11)

{
  byte bVar1;
  undefined uVar2;
  uint uVar3;
  undefined *puVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  double dVar8;
  
  bVar1 = (&J3DGDTexMode0Ids)[param_4];
  uVar7 = countLeadingZeros(param_10 & 0xff);
  uVar6 = countLeadingZeros(1 - param_8);
  uVar6 = (uint)(byte)(&GX2HWFiltConv)[param_7] << 5 | uVar6 >> 1 & 0xff0 | param_5 | param_6 << 2;
  uVar7 = ((int)((double)_1044 * param_3) & 0xffU) << 9 | (uVar7 & 0x1fe0) << 3 | uVar6;
  uVar3 = (param_9 & 0xff) << 0x15 | param_11 << 0x13 | uVar7;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 0x61;
  pbVar5 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar5 + 1;
  *pbVar5 = bVar1 | (byte)(uVar3 >> 0x18);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)(uVar3 >> 0x10);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)(uVar7 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)uVar6;
  uVar2 = (&J3DGDTexMode1Ids)[param_4];
  dVar8 = (double)_1045;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 0x61;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = uVar2;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 0;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)(int)(dVar8 * param_2);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)(int)(dVar8 * param_1);
  return;
}


/* __stdcall J3DGDSetTexImgAttr(_GXTexMapID,
                                unsigned short,
                                unsigned short,
                                _GXTexFmt) */

void J3DGDSetTexImgAttr(int param_1,uint param_2,uint param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  byte *pbVar5;
  uint uVar6;
  
  bVar1 = (&J3DGDTexImage0Ids)[param_1];
  uVar6 = (param_2 & 0xffff) - 1;
  uVar2 = uVar6 | ((param_3 & 0xffff) - 1) * 0x400;
  uVar3 = param_4 << 0x14 | uVar2;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 0x61;
  pbVar5 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar5 + 1;
  *pbVar5 = bVar1 | (byte)(uVar3 >> 0x18);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)(uVar3 >> 0x10);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)(uVar2 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)uVar6;
  return;
}


/* __stdcall J3DGDSetTexImgPtr(_GXTexMapID,
                               void *) */

void J3DGDSetTexImgPtr(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  undefined *puVar3;
  byte *pbVar4;
  
  uVar2 = param_2 + 0x80000000U >> 5;
  bVar1 = (&J3DGDTexImage3Ids)[param_1];
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0x61;
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)(param_2 + 0x80000000U >> 0x1d) | bVar1;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)(uVar2 >> 0x10);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)(uVar2 >> 8);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)uVar2;
  return;
}


/* __stdcall J3DGDSetTexImgPtrRaw(_GXTexMapID,
                                  unsigned long) */

void J3DGDSetTexImgPtrRaw(int param_1,undefined4 param_2)

{
  byte bVar1;
  undefined *puVar2;
  byte *pbVar3;
  
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 5U) {
    gd::GDOverflowed();
  }
  bVar1 = (&J3DGDTexImage3Ids)[param_1];
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0x61;
  pbVar3 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar3 + 1;
  *pbVar3 = (byte)((uint)param_2 >> 0x18) | bVar1;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)((uint)param_2 >> 0x10);
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)((uint)param_2 >> 8);
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)param_2;
  return;
}


/* __stdcall J3DGDSetTexTlut(_GXTexMapID,
                             unsigned long,
                             _GXTlutFmt) */

void J3DGDSetTexTlut(int param_1,int param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  byte *pbVar5;
  
  bVar1 = (&J3DGDTexTlutIds)[param_1];
  uVar2 = param_2 - 0x80000U >> 9;
  uVar3 = uVar2 | param_3 << 10;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 0x61;
  pbVar5 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar5 + 1;
  *pbVar5 = bVar1 | (byte)((uint)(param_3 << 10) >> 0x18);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)(uVar3 >> 0x10);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)(uVar3 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)uVar2;
  return;
}


/* __stdcall J3DGDLoadTlut(void *,
                           unsigned long,
                           _GXTlutSize) */

void J3DGDLoadTlut(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  byte *pbVar4;
  
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0x61;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0xfe;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0xff;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0xff;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0x61;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0xf;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0x61;
  uVar1 = param_1 + 0x80000000U >> 5;
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)(param_1 + 0x80000000U >> 0x1d) | 100;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)(uVar1 >> 0x10);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)(uVar1 >> 8);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)uVar1;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0x61;
  uVar1 = param_2 - 0x80000U >> 9;
  uVar2 = uVar1 | param_3 << 10;
  pbVar4 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar4 + 1;
  *pbVar4 = (byte)((uint)(param_3 << 10) >> 0x18) | 0x65;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)(uVar2 >> 0x10);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)(uVar2 >> 8);
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = (char)uVar1;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0x61;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0xfe;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0xff;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0xff;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0x61;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0xf;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0;
  puVar3 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar3 + 1;
  *puVar3 = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __stdcall J3DGDSetIndTexMtx(_GXIndTexMtxID,
                               float *[][][],
                               signed char) */

void J3DGDSetIndTexMtx(int param_1,float *param_2,char param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  undefined *puVar9;
  byte *pbVar10;
  
  if (param_1 != 8) {
    if (param_1 < 8) {
      if (param_1 != 4) {
        if (3 < param_1) {
          param_1 = param_1 + -5;
          goto LAB_802d7b5c;
        }
        if (0 < param_1) {
          param_1 = param_1 + -1;
          goto LAB_802d7b5c;
        }
      }
    }
    else {
      if (param_1 < 0xc) {
        param_1 = param_1 + -9;
        goto LAB_802d7b5c;
      }
    }
  }
  param_1 = 0;
LAB_802d7b5c:
  uVar1 = (int)(_1227 * *param_2) & 0x7ff;
  fVar5 = _1227 * param_2[3];
  uVar2 = (int)(_1227 * param_2[1]) & 0x7ff;
  fVar6 = _1227 * param_2[4];
  uVar3 = (int)(_1227 * param_2[2]) & 0x7ff;
  fVar7 = _1227 * param_2[5];
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 0xfU) {
    gd::GDOverflowed();
  }
  iVar8 = (int)(char)(param_3 + '\x11');
  iVar4 = ((int)fVar5 & 0x7ffU) << 0xb;
  param_1 = param_1 * 3;
  puVar9 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar9 + 1;
  *puVar9 = 0x61;
  puVar9 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar9 + 1;
  *puVar9 = (char)((uint)((param_1 + 6) * 0x1000000) >> 0x18);
  pbVar10 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar10 + 1;
  *pbVar10 = (byte)((uint)(iVar8 << 0x16) >> 0x10) | (byte)((uint)iVar4 >> 0x10);
  pbVar10 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar10 + 1;
  *pbVar10 = (byte)(uVar1 >> 8) | (byte)((uint)iVar4 >> 8);
  puVar9 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar9 + 1;
  *puVar9 = (char)uVar1;
  iVar4 = ((int)fVar6 & 0x7ffU) << 0xb;
  puVar9 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar9 + 1;
  *puVar9 = 0x61;
  puVar9 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar9 + 1;
  *puVar9 = (char)((uint)((param_1 + 7) * 0x1000000) >> 0x18);
  pbVar10 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar10 + 1;
  *pbVar10 = (byte)((uint)(iVar8 << 0x14) >> 0x10) & 0xc0 | (byte)((uint)iVar4 >> 0x10);
  pbVar10 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar10 + 1;
  *pbVar10 = (byte)(uVar2 >> 8) | (byte)((uint)iVar4 >> 8);
  puVar9 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar9 + 1;
  *puVar9 = (char)uVar2;
  iVar4 = ((int)fVar7 & 0x7ffU) << 0xb;
  puVar9 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar9 + 1;
  *puVar9 = 0x61;
  puVar9 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar9 + 1;
  *puVar9 = (char)((uint)((param_1 + 8) * 0x1000000) >> 0x18);
  pbVar10 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar10 + 1;
  *pbVar10 = (byte)((uint)(iVar8 << 0x12) >> 0x10) & 0xc0 | (byte)((uint)iVar4 >> 0x10);
  pbVar10 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar10 + 1;
  *pbVar10 = (byte)(uVar3 >> 8) | (byte)((uint)iVar4 >> 8);
  puVar9 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar9 + 1;
  *puVar9 = (char)uVar3;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall J3DGDSetIndTexCoordScale(_GXIndTexStageID,
                                      _GXIndTexScale,
                                      _GXIndTexScale,
                                      _GXIndTexScale,
                                      _GXIndTexScale) */

void J3DGDSetIndTexCoordScale
               (int param_1,uint param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  undefined *puVar2;
  byte *pbVar3;
  
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 5U) {
    gd::GDOverflowed();
  }
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0x61;
  param_2 = param_2 | param_3 << 4;
  uVar1 = param_5 << 0xc | param_4 << 8 | param_2;
  pbVar3 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar3 + 1;
  *pbVar3 = (byte)((uint)(((param_1 >> 1) + 0x25) * 0x1000000) >> 0x18) | (byte)(uVar1 >> 0x18);
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)(uVar1 >> 0x10);
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)(uVar1 >> 8);
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)param_2;
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __stdcall J3DGDSetIndTexOrder(unsigned long,
                                 _GXTexCoordID,
                                 _GXTexMapID,
                                 _GXTexCoordID,
                                 _GXTexMapID,
                                 _GXTexCoordID,
                                 _GXTexMapID,
                                 _GXTexCoordID,
                                 _GXTexMapID) */

void J3DGDSetIndTexOrder
               (int param_1,int param_2,uint param_3,int param_4,uint param_5,uint param_6,
               uint param_7,int param_8,uint param_9)

{
  int iVar1;
  undefined *puVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 10U) {
    gd::GDOverflowed();
  }
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0x61;
  iVar5 = (param_5 & 7) << 6;
  iVar1 = (param_6 & 7) << 0xf;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0x27;
  pbVar3 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar3 + 1;
  *pbVar3 = (byte)((uint)(param_8 << 0x15) >> 0x10) |
            (byte)((param_9 << 0x12) >> 0x10) & 0x1c | (byte)((uint)iVar1 >> 0x10);
  pbVar3 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar3 + 1;
  *pbVar3 = (byte)((uint)iVar1 >> 8) |
            (byte)((param_7 << 0xc) >> 8) & 0x70 |
            (byte)((uint)(param_4 << 9) >> 8) & 0xe | (byte)((uint)iVar5 >> 8);
  pbVar3 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar3 + 1;
  *pbVar3 = (byte)iVar5 | (byte)param_3 & 7 | (byte)(param_2 << 3) & 0x38;
  uVar4 = 0;
  iVar5 = 0;
  if (param_1 != 0) {
    do {
      if (iVar5 == 2) {
        uVar4 = uVar4 | 1 << (param_7 & 7);
      }
      else {
        if (iVar5 < 2) {
          if (iVar5 == 0) {
            uVar4 = uVar4 | 1 << (param_3 & 7);
          }
          else {
            if (-1 < iVar5) {
              uVar4 = uVar4 | 1 << (param_5 & 7);
            }
          }
        }
        else {
          if (iVar5 < 4) {
            uVar4 = uVar4 | 1 << (param_9 & 7);
          }
        }
      }
      iVar5 = iVar5 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = 0x61;
  pbVar3 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar3 + 1;
  *pbVar3 = (byte)(uVar4 >> 0x18) | 0xf;
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)(uVar4 >> 0x10);
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)(uVar4 >> 8);
  puVar2 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar2 + 1;
  *puVar2 = (char)uVar4;
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall J3DGDSetTevOrder(_GXTevStageID,
                              _GXTexCoordID,
                              _GXTexMapID,
                              _GXChannelID,
                              _GXTexCoordID,
                              _GXTexMapID,
                              _GXChannelID) */

void J3DGDSetTevOrder
               (uint param_1,int param_2,uint param_3,uint param_4,int param_5,uint param_6,
               uint param_7)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  
  if (7 < param_2) {
    param_2 = 0;
  }
  if (7 < param_5) {
    param_5 = 0;
  }
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 5U) {
    gd::GDOverflowed();
  }
  iVar6 = 0;
  if ((param_6 != 0xff) && ((param_6 & 0x100) == 0)) {
    iVar6 = 1;
  }
  iVar7 = 0;
  if ((param_3 != 0xff) && ((param_3 & 0x100) == 0)) {
    iVar7 = 1;
  }
  uVar1 = (uint)(byte)(&c2r_1296)[param_4 & 0xf] << 7 | param_3 & 7 | param_2 << 3 | iVar7 << 6;
  uVar2 = param_5 << 0xf | (param_6 & 7) << 0xc | uVar1;
  uVar3 = (uint)(byte)(&c2r_1296)[param_7 & 0xf] << 0x13 | iVar6 << 0x12 | uVar2;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 0x61;
  pbVar5 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar5 + 1;
  *pbVar5 = (byte)((((int)param_1 >> 1) + (uint)((int)param_1 < 0 && (param_1 & 1) != 0) + 0x28) *
                   0x1000000 >> 0x18) | (byte)(uVar3 >> 0x18);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)(uVar3 >> 0x10);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)(uVar2 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = (char)uVar1;
  return;
}


/* __stdcall J3DGDSetTevKColor(_GXTevKColorID,
                               _GXColor) */

void J3DGDSetTevKColor(char param_1,undefined *param_2)

{
  undefined uVar1;
  byte bVar2;
  undefined uVar3;
  byte bVar4;
  undefined *puVar5;
  char *pcVar6;
  byte *pbVar7;
  
  uVar1 = *param_2;
  bVar2 = param_2[3];
  uVar3 = param_2[2];
  bVar4 = param_2[1];
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 10U) {
    gd::GDOverflowed();
  }
  puVar5 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar5 + 1;
  *puVar5 = 0x61;
  pcVar6 = *(char **)(gd::__GDCurrentDL + 8);
  *(char **)(gd::__GDCurrentDL + 8) = pcVar6 + 1;
  *pcVar6 = param_1 * '\x02' + -0x20;
  pbVar7 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar7 + 1;
  *pbVar7 = (byte)(((uint)bVar2 << 0xc) >> 0x10) | 0x80;
  puVar5 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar5 + 1;
  *puVar5 = (char)(((uint)bVar2 << 0xc) >> 8);
  puVar5 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar5 + 1;
  *puVar5 = uVar1;
  puVar5 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar5 + 1;
  *puVar5 = 0x61;
  pcVar6 = *(char **)(gd::__GDCurrentDL + 8);
  *(char **)(gd::__GDCurrentDL + 8) = pcVar6 + 1;
  *pcVar6 = param_1 * '\x02' + -0x1f;
  pbVar7 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar7 + 1;
  *pbVar7 = (byte)(((uint)bVar4 << 0xc) >> 0x10) | 0x80;
  puVar5 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar5 + 1;
  *puVar5 = (char)(((uint)bVar4 << 0xc) >> 8);
  puVar5 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar5 + 1;
  *puVar5 = uVar3;
  return;
}


/* __stdcall J3DGDSetTevColorS10(_GXTevRegID,
                                 _GXColorS10) */

void J3DGDSetTevColorS10(char param_1,short *param_2)

{
  short sVar1;
  short sVar2;
  undefined uVar3;
  undefined uVar4;
  byte bVar5;
  char cVar6;
  int iVar7;
  undefined *puVar8;
  char *pcVar9;
  byte *pbVar10;
  int iVar11;
  
  sVar1 = *param_2;
  iVar11 = ((int)param_2[3] & 0x7ffU) << 0xc;
  sVar2 = param_2[2];
  iVar7 = ((int)param_2[1] & 0x7ffU) << 0xc;
  bVar5 = (byte)(((int)sVar2 & 0x7ffU) >> 8) | (byte)((uint)iVar7 >> 8);
  cVar6 = param_1 * '\x02' + -0x1f;
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 0x14U) {
    gd::GDOverflowed();
  }
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = 0x61;
  pcVar9 = *(char **)(gd::__GDCurrentDL + 8);
  *(char **)(gd::__GDCurrentDL + 8) = pcVar9 + 1;
  *pcVar9 = param_1 * '\x02' + -0x20;
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = (char)((uint)iVar11 >> 0x10);
  pbVar10 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar10 + 1;
  *pbVar10 = (byte)(((int)sVar1 & 0x7ffU) >> 8) | (byte)((uint)iVar11 >> 8);
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = (char)((int)sVar1 & 0x7ffU);
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = 0x61;
  pcVar9 = *(char **)(gd::__GDCurrentDL + 8);
  *(char **)(gd::__GDCurrentDL + 8) = pcVar9 + 1;
  *pcVar9 = cVar6;
  uVar4 = (undefined)((uint)iVar7 >> 0x10);
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = uVar4;
  pbVar10 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar10 + 1;
  *pbVar10 = bVar5;
  uVar3 = (undefined)((int)sVar2 & 0x7ffU);
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = uVar3;
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = 0x61;
  pcVar9 = *(char **)(gd::__GDCurrentDL + 8);
  *(char **)(gd::__GDCurrentDL + 8) = pcVar9 + 1;
  *pcVar9 = cVar6;
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = uVar4;
  pbVar10 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar10 + 1;
  *pbVar10 = bVar5;
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = uVar3;
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = 0x61;
  pcVar9 = *(char **)(gd::__GDCurrentDL + 8);
  *(char **)(gd::__GDCurrentDL + 8) = pcVar9 + 1;
  *pcVar9 = cVar6;
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = uVar4;
  pbVar10 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar10 + 1;
  *pbVar10 = bVar5;
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = uVar3;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall J3DGDSetFog(_GXFogType,
                         float,
                         float,
                         float,
                         float,
                         _GXColor) */

void J3DGDSetFog
               (double param_1,double param_2,double param_3,double param_4,int param_5,
               undefined *param_6)

{
  float fVar1;
  undefined uVar2;
  undefined uVar3;
  undefined uVar4;
  uint uVar5;
  float fVar6;
  undefined4 uVar7;
  undefined *puVar8;
  byte *pbVar9;
  int iVar10;
  double dVar11;
  float local_24;
  
  if ((param_4 == param_3) || (param_2 == param_1)) {
    local_24 = _1454;
    fVar1 = _1455;
    fVar6 = _1454;
  }
  else {
    fVar6 = (float)(param_4 * param_3) /
            (float)((double)(float)(param_4 - param_3) * (double)(float)(param_2 - param_1));
    fVar1 = (float)(param_4 / (double)(float)(param_4 - param_3));
    local_24 = (float)(param_1 / (double)(float)(param_2 - param_1));
  }
  iVar10 = 1;
  while (dVar11 = (double)fVar1, _1456 < dVar11) {
    iVar10 = iVar10 + 1;
    fVar1 = (float)(dVar11 * (double)_1455);
  }
  for (; ((double)_1454 < dVar11 && (dVar11 < _1458));
      dVar11 = (double)(float)(dVar11 * (double)_1457)) {
    iVar10 = iVar10 + -1;
  }
  fVar6 = fVar6 / (float)((double)CONCAT44(0x43300000,1 << iVar10 ^ 0x80000000) - _1462);
  uVar7 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)(float)((double)_1459 * dVar11));
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = 0x61;
  uVar5 = (uint)fVar6 >> 0xc;
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = 0xee;
  pbVar9 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar9 + 1;
  *pbVar9 = (byte)((uint)fVar6 >> 0x1c);
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = (char)(uVar5 >> 8);
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = (char)uVar5;
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = 0x61;
  pbVar9 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar9 + 1;
  *pbVar9 = (byte)((uint)uVar7 >> 0x18) | 0xef;
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = (char)((uint)uVar7 >> 0x10);
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = (char)((uint)uVar7 >> 8);
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = (char)uVar7;
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = 0x61;
  pbVar9 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar9 + 1;
  *pbVar9 = (byte)((uint)iVar10 >> 0x18) | 0xf0;
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = (char)((uint)iVar10 >> 0x10);
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = (char)((uint)iVar10 >> 8);
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = (char)iVar10;
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = 0x61;
  pbVar9 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar9 + 1;
  *pbVar9 = (byte)((uint)(param_5 << 0x15) >> 0x18) | 0xf1;
  pbVar9 = *(byte **)(gd::__GDCurrentDL + 8);
  *(byte **)(gd::__GDCurrentDL + 8) = pbVar9 + 1;
  *pbVar9 = (byte)((uint)local_24 >> 0x1c) | (byte)((uint)(param_5 << 0x15) >> 0x10);
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = (char)(((uint)local_24 >> 0xc) >> 8);
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = (char)((uint)local_24 >> 0xc);
  uVar2 = *param_6;
  uVar3 = param_6[2];
  uVar4 = param_6[1];
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = 0x61;
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = 0xf2;
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = uVar2;
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = uVar4;
  puVar8 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar8 + 1;
  *puVar8 = uVar3;
  return;
}


/* __stdcall J3DGDSetFogRangeAdj(unsigned char,
                                 unsigned short,
                                 _GXFogAdjTable *) */

void J3DGDSetFogRangeAdj(byte param_1,uint param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined *puVar7;
  byte *pbVar8;
  int iVar9;
  
  if (param_1 != 0) {
    iVar4 = 0;
    iVar6 = 0;
    iVar9 = 5;
    do {
      iVar2 = (uint)((ushort *)(param_3 + iVar6))[1] << 0xc;
      uVar1 = *(ushort *)(param_3 + iVar6);
      puVar7 = *(undefined **)(gd::__GDCurrentDL + 8);
      *(undefined **)(gd::__GDCurrentDL + 8) = puVar7 + 1;
      *puVar7 = 0x61;
      pbVar8 = *(byte **)(gd::__GDCurrentDL + 8);
      *(byte **)(gd::__GDCurrentDL + 8) = pbVar8 + 1;
      *pbVar8 = (byte)((uint)(((iVar4 >> 1) + 0xe9) * 0x1000000) >> 0x18) |
                (byte)((uint)iVar2 >> 0x18);
      puVar7 = *(undefined **)(gd::__GDCurrentDL + 8);
      *(undefined **)(gd::__GDCurrentDL + 8) = puVar7 + 1;
      *puVar7 = (char)((uint)iVar2 >> 0x10);
      pbVar8 = *(byte **)(gd::__GDCurrentDL + 8);
      *(byte **)(gd::__GDCurrentDL + 8) = pbVar8 + 1;
      *pbVar8 = (byte)((uint)iVar2 >> 8) | (byte)((uint)uVar1 >> 8);
      puVar7 = *(undefined **)(gd::__GDCurrentDL + 8);
      *(undefined **)(gd::__GDCurrentDL + 8) = puVar7 + 1;
      *puVar7 = (char)uVar1;
      iVar4 = iVar4 + 2;
      iVar6 = iVar6 + 4;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  uVar3 = (param_2 & 0xffff) + 0x156;
  uVar5 = uVar3 | (uint)param_1 << 10;
  puVar7 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar7 + 1;
  *puVar7 = 0x61;
  puVar7 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar7 + 1;
  *puVar7 = 0xe8;
  puVar7 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar7 + 1;
  *puVar7 = (char)(uVar5 >> 0x10);
  puVar7 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar7 + 1;
  *puVar7 = (char)(uVar5 >> 8);
  puVar7 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar7 + 1;
  *puVar7 = (char)uVar3;
  return;
}

