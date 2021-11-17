#include <gx/GXTexture.h>
#include <gx/GXTexture.h>
#include <gx/GXBump.h>


namespace gx {

int GXGetTexBufferSize(uint param_1,uint param_2,int param_3,char param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  switch(param_3) {
  case 0:
  case 8:
  case 0xe:
  case 0x20:
  case 0x30:
    iVar3 = 3;
    iVar5 = 3;
    break;
  case 1:
  case 2:
  case 9:
  case 0x11:
  case 0x22:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x39:
  case 0x3a:
    iVar3 = 3;
    iVar5 = 2;
    break;
  case 3:
  case 4:
  case 5:
  case 6:
  case 10:
  case 0x13:
  case 0x16:
  case 0x23:
  case 0x2b:
  case 0x2c:
  case 0x3c:
    iVar3 = 2;
    iVar5 = 2;
    break;
  default:
    iVar5 = 0;
    iVar3 = 0;
  }
  if ((param_3 == 6) || (param_3 == 0x16)) {
    iVar4 = 0x40;
  }
  else {
    iVar4 = 0x20;
  }
  if (param_4 == '\x01') {
    iVar6 = 0;
    for (param_5 = param_5 & 0xff; param_5 != 0; param_5 = param_5 - 1) {
      uVar1 = param_1 & 0xffff;
      uVar2 = param_2 & 0xffff;
      iVar6 = iVar6 + iVar4 * ((int)(uVar1 + (1 << iVar3) + -1) >> iVar3) *
                              ((int)(uVar2 + (1 << iVar5) + -1) >> iVar5);
      if ((uVar1 == 1) && (uVar2 == 1)) {
        return iVar6;
      }
      if ((param_1 & 0xffff) < 2) {
        param_1 = 1;
      }
      else {
        param_1 = (int)uVar1 >> 1;
      }
      if ((param_2 & 0xffff) < 2) {
        param_2 = 1;
      }
      else {
        param_2 = (int)uVar2 >> 1;
      }
    }
  }
  else {
    iVar6 = iVar4 * ((int)((param_1 & 0xffff) + (1 << iVar3) + -1) >> iVar3) *
                    ((int)((param_2 & 0xffff) + (1 << iVar5) + -1) >> iVar5);
  }
  return iVar6;
}


void __GetImageTileCount
               (int param_1,ushort param_2,ushort param_3,int *param_4,int *param_5,
               undefined4 *param_6)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  switch(param_1) {
  case 0:
  case 8:
  case 0xe:
  case 0x20:
  case 0x30:
    iVar3 = 3;
    iVar4 = 3;
    break;
  case 1:
  case 2:
  case 9:
  case 0x11:
  case 0x22:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x39:
  case 0x3a:
    iVar3 = 3;
    iVar4 = 2;
    break;
  case 3:
  case 4:
  case 5:
  case 6:
  case 10:
  case 0x13:
  case 0x16:
  case 0x23:
  case 0x2b:
  case 0x2c:
  case 0x3c:
    iVar3 = 2;
    iVar4 = 2;
    break;
  default:
    iVar4 = 0;
    iVar3 = 0;
  }
  if (param_2 == 0) {
    param_2 = 1;
  }
  if (param_3 == 0) {
    param_3 = 1;
  }
  bVar1 = true;
  *param_4 = (int)((uint)param_2 + (1 << iVar3) + -1) >> iVar3;
  *param_5 = (int)((uint)param_3 + (1 << iVar4) + -1) >> iVar4;
  if ((param_1 != 6) && (param_1 != 0x16)) {
    bVar1 = false;
  }
  if (bVar1) {
    uVar2 = 2;
  }
  else {
    uVar2 = 1;
  }
  *param_6 = uVar2;
  return;
}


void GXInitTexObj(GXTexObj *param_1,void *param_2,uint param_3,uint param_4,_GXTexFmt format,
                     _GXTexWrapMode wrap_s,_GXTexWrapMode wrap_t,bool mipmap)

{
  int iVar1;
  undefined3 in_register_0000001c;
  int iVar2;
  undefined3 in_register_00000020;
  undefined3 in_register_00000024;
  
  FUN_800033a8((int)param_1,0,0x20);
  param_1->dummy[0] = param_1->dummy[0] & 0xfffffffc | CONCAT31(in_register_00000020,wrap_s);
  param_1->dummy[0] = param_1->dummy[0] & 0xfffffff3 | CONCAT31(in_register_00000024,wrap_t) << 2;
  param_1->dummy[0] = param_1->dummy[0] & 0xffffffef | 0x10;
  if (mipmap == false) {
    param_1->dummy[0] = param_1->dummy[0] & 0xffffff1f | 0x80;
  }
  else {
    *(byte *)((int)param_1->dummy + 0x1f) = *(byte *)((int)param_1->dummy + 0x1f) | 1;
    if (CONCAT31(in_register_0000001c,format) - 8 < 3) {
      param_1->dummy[0] = param_1->dummy[0] & 0xffffff1f | 0xa0;
    }
    else {
      param_1->dummy[0] = param_1->dummy[0] & 0xffffff1f | 0xc0;
    }
    if ((param_4 & 0xffff) < (param_3 & 0xffff)) {
      iVar1 = countLeadingZeros(param_3 & 0xffff);
    }
    else {
      iVar1 = countLeadingZeros(param_4 & 0xffff);
    }
    param_1->dummy[1] =
         ((int)(_176 * (float)((double)CONCAT44(0x43300000,0x1f - iVar1) - _178)) & 0xffU) << 8 |
         param_1->dummy[1] & 0xffff00ff;
  }
  param_1->dummy[5] = CONCAT31(in_register_0000001c,format);
  param_1->dummy[2] = param_1->dummy[2] & 0xfffffc00 | (param_3 & 0xffff) - 1;
  param_1->dummy[2] = param_1->dummy[2] & 0xfff003ff | ((param_4 & 0xffff) - 1) * 0x400;
  param_1->dummy[2] = (format & 0xf) << 0x14 | param_1->dummy[2] & 0xff0fffff;
  param_1->dummy[3] = param_1->dummy[3] & 0xffe00000 | (uint)param_2 >> 5 & 0x1ffffff;
  switch(format & GX_CTF_R4) {
  case GX_TF_I4:
  case 8:
    *(undefined *)((int)param_1->dummy + 0x1e) = 1;
    iVar1 = 3;
    iVar2 = 3;
    break;
  case GX_TF_I8:
  case GX_TF_IA4:
  case 9:
    *(undefined *)((int)param_1->dummy + 0x1e) = 2;
    iVar1 = 3;
    iVar2 = 2;
    break;
  case GX_TF_IA8:
  case GX_TF_RGB565:
  case GX_TF_RGB5A3:
  case 10:
    *(undefined *)((int)param_1->dummy + 0x1e) = 2;
    iVar1 = 2;
    iVar2 = 2;
    break;
  case GX_TF_RGBA8:
    *(undefined *)((int)param_1->dummy + 0x1e) = 3;
    iVar1 = 2;
    iVar2 = 2;
    break;
  default:
    *(undefined *)((int)param_1->dummy + 0x1e) = 2;
    iVar1 = 2;
    iVar2 = 2;
    break;
  case GX_TF_CMPR:
    *(undefined *)((int)param_1->dummy + 0x1e) = 0;
    iVar1 = 3;
    iVar2 = 3;
  }
  *(ushort *)(param_1->dummy + 7) =
       (short)((int)((param_3 & 0xffff) + (1 << iVar1) + -1) >> iVar1) *
       (short)((int)((param_4 & 0xffff) + (1 << iVar2) + -1) >> iVar2) & 0x7fff;
  *(byte *)((int)param_1->dummy + 0x1f) = *(byte *)((int)param_1->dummy + 0x1f) | 2;
  return;
}


void GXInitTexObjCI(GXTexObj *param_1,void *param_2,uint param_3,uint param_4,_GXTexFmt param_5,
                       _GXTexWrapMode param_6,_GXTexWrapMode param_7,bool param_8,u32 param_9)

{
  GXInitTexObj(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  *(byte *)((int)param_1->dummy + 0x1f) = *(byte *)((int)param_1->dummy + 0x1f) & 0xfd;
  param_1->dummy[6] = param_9;
  return;
}


void GXInitTexObjLOD(double param_1,double param_2,double param_3,uint *param_4,int param_5,
                        int param_6,uint param_7,char param_8,int param_9)

{
  double dVar1;
  double dVar2;
  
  dVar1 = (double)_204;
  if ((dVar1 <= param_3) && (dVar1 = param_3, (double)_205 <= param_3)) {
    dVar1 = (double)_206;
  }
  *param_4 = ((int)((double)_207 * dVar1) & 0xffU) << 9 | *param_4 & 0xfffe01ff;
  *param_4 = *param_4 & 0xffffffef | (uint)(param_6 == 1) << 4;
  *param_4 = *param_4 & 0xffffff1f | (uint)(byte)(&GX2HWFiltConv)[param_5] << 5;
  *param_4 = *param_4 & 0xfffffeff | (uint)(param_8 == '\0') << 8;
  *param_4 = *param_4 & 0xfffdffff;
  *param_4 = *param_4 & 0xfffbffff;
  *param_4 = *param_4 & 0xffe7ffff | param_9 << 0x13;
  *param_4 = *param_4 & 0xffdfffff | (param_7 & 0xff) << 0x15;
  dVar1 = (double)_208;
  if ((dVar1 <= param_1) && (dVar1 = param_1, (double)_209 < param_1)) {
    dVar1 = (double)_209;
  }
  dVar2 = (double)_208;
  if ((dVar2 <= param_2) && (dVar2 = param_2, (double)_209 < param_2)) {
    dVar2 = (double)_209;
  }
  param_4[1] = (int)((double)_176 * dVar1) & 0xffU | param_4[1] & 0xffffff00;
  param_4[1] = ((int)((double)_176 * dVar2) & 0xffU) << 8 | param_4[1] & 0xffff00ff;
  return;
}


int GXGetTexObjData(int param_1)

{
  return (*(uint *)(param_1 + 0xc) & 0x1fffff) << 5;
}


int GXGetTexObjWidth(int param_1)

{
  return (*(uint *)(param_1 + 8) & 0x3ff) + 1;
}


int GXGetTexObjHeight(int param_1)

{
  return (*(uint *)(param_1 + 8) >> 10 & 0x3ff) + 1;
}


undefined4 GXGetTexObjFmt(int param_1)

{
  return *(undefined4 *)(param_1 + 0x14);
}


uint GXGetTexObjWrapS(uint *param_1)

{
  return *param_1 & 3;
}


uint GXGetTexObjWrapT(uint *param_1)

{
  return *param_1 >> 2 & 3;
}


undefined4 GXGetTexObjTlut(int param_1)

{
  return *(undefined4 *)(param_1 + 0x18);
}


void GXLoadTexObjPreLoaded(uint *param_1,uint *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  *param_1 = *param_1 & 0xffffff | (uint)(byte)(&GXTexMode0Ids)[param_3] << 0x18;
  param_1[1] = param_1[1] & 0xffffff | (uint)(byte)(&GXTexMode1Ids)[param_3] << 0x18;
  param_1[2] = param_1[2] & 0xffffff | (uint)(byte)(&GXTexImage0Ids)[param_3] << 0x18;
  *param_2 = *param_2 & 0xffffff | (uint)(byte)(&GXTexImage1Ids)[param_3] << 0x18;
  param_2[1] = param_2[1] & 0xffffff | (uint)(byte)(&GXTexImage2Ids)[param_3] << 0x18;
  param_1[3] = param_1[3] & 0xffffff | (uint)(byte)(&GXTexImage3Ids)[param_3] << 0x18;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*param_1);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,param_1[1]);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,param_1[2]);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*param_2);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,param_2[1]);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,param_1[3]);
  if ((*(byte *)((int)param_1 + 0x1f) & 2) == 0) {
    iVar1 = (**(code **)(gx + 0x414))(param_1[6]);
    *(uint *)(iVar1 + 4) =
         *(uint *)(iVar1 + 4) & 0xffffff | (uint)(byte)(&GXTexTlutIds)[param_3] << 0x18;
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 4));
  }
  iVar1 = gx;
  iVar2 = gx + param_3 * 4;
  *(uint *)(iVar2 + 0x45c) = param_1[2];
  *(uint *)(iVar2 + 0x47c) = *param_1;
  *(uint *)(iVar1 + 0x4f4) = *(uint *)(iVar1 + 0x4f4) | 1;
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXLoadTexObj(GXTexObj *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(gx + 0x410))();
  GXLoadTexObjPreLoaded(param_1,uVar1,param_2);
  return;
}


void GXInitTlutObj(uint *param_1,uint param_2,int param_3,undefined2 param_4)

{
  *param_1 = 0;
  *param_1 = *param_1 & 0xfffff3ff | param_3 << 10;
  param_1[1] = param_1[1] & 0xffe00000 | param_2 >> 5 & 0x1ffffff;
  param_1[1] = param_1[1] & 0xffffff | 0x64000000;
  *(undefined2 *)(param_1 + 2) = param_4;
  return;
}


void GXLoadTlut(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = (uint *)(**(code **)(gx + 0x414))(param_2);
  __GXFlushTextureState();
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,param_1[1]);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*puVar2);
  __GXFlushTextureState();
  *param_1 = *param_1 & 0xfffffc00 | *puVar2 & 0x3ff;
  uVar1 = param_1[1];
  puVar2[1] = *param_1;
  puVar2[2] = uVar1;
  puVar2[3] = param_1[2];
  return;
}


void GXInitTexCacheRegion
               (uint *param_1,undefined param_2,uint param_3,int param_4,uint param_5,int param_6,
               undefined4 param_7,int param_8)

{
  if (param_4 == 1) {
    param_8 = 4;
  }
  else {
    if (param_4 < 1) {
      if (-1 < param_4) {
        param_8 = 3;
      }
    }
    else {
      if (param_4 < 3) {
        param_8 = 5;
      }
    }
  }
  *param_1 = 0;
  *param_1 = *param_1 & 0xffff8000 | param_3 >> 5;
  *param_1 = *param_1 & 0xfffc7fff | param_8 << 0xf;
  *param_1 = *param_1 & 0xffe3ffff | param_8 << 0x12;
  *param_1 = *param_1 & 0xffdfffff;
  if (param_6 == 2) {
    param_8 = 5;
  }
  else {
    if (param_6 < 2) {
      if (param_6 == 0) {
        param_8 = 3;
      }
      else {
        if (-1 < param_6) {
          param_8 = 4;
        }
      }
    }
    else {
      if (param_6 < 4) {
        param_8 = 0;
      }
    }
  }
  param_1[1] = 0;
  param_1[1] = param_1[1] & 0xffff8000 | param_5 >> 5;
  param_1[1] = param_1[1] & 0xfffc7fff | param_8 << 0xf;
  param_1[1] = param_1[1] & 0xffe3ffff | param_8 << 0x12;
  *(undefined *)(param_1 + 3) = param_2;
  *(undefined *)((int)param_1 + 0xd) = 1;
  return;
}


void GXInitTlutRegion(uint *param_1,int param_2,int param_3)

{
  *param_1 = 0;
  *param_1 = *param_1 & 0xfffffc00 | param_2 - 0x80000U >> 9;
  *param_1 = *param_1 & 0xffe003ff | param_3 << 10;
  *param_1 = *param_1 & 0xffffff | 0x65000000;
  return;
}


void GXInvalidateTexAll(void)

{
  __GXFlushTextureState();
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,0x66001000);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,0x66001100);
  __GXFlushTextureState();
  return;
}


undefined4 GXSetTexRegionCallback(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(gx + 0x410);
  *(undefined4 *)(gx + 0x410) = param_1;
  return uVar1;
}


undefined4 GXSetTlutRegionCallback(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(gx + 0x414);
  *(undefined4 *)(gx + 0x414) = param_1;
  return uVar1;
}


void GXSetTexCoordScaleManually(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = gx;
  *(uint *)(gx + 0x4dc) = *(uint *)(gx + 0x4dc) & ~(1 << param_1) | (param_2 & 0xff) << param_1;
  if ((param_2 & 0xff) == 0) {
    return;
  }
  param_1 = param_1 * 4;
  *(uint *)(iVar1 + param_1 + 0xb8) =
       *(uint *)(iVar1 + param_1 + 0xb8) & 0xffff0000 | param_3 - 1U & 0xffff;
  *(uint *)(iVar1 + param_1 + 0xd8) =
       param_4 - 1U & 0xffff | *(uint *)(iVar1 + param_1 + 0xd8) & 0xffff0000;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + param_1 + 0xb8));
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + param_1 + 0xd8));
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXSetTexCoordBias(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = gx;
  iVar1 = param_1 * 4;
  iVar3 = gx + iVar1;
  *(uint *)(gx + iVar1 + 0xb8) =
       *(uint *)(gx + iVar1 + 0xb8) & 0xfffeffff | (param_2 & 0xff) << 0x10;
  *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) & 0xfffeffff | (param_3 & 0xff) << 0x10;
  if ((*(uint *)(iVar2 + 0x4dc) & 1 << param_1) == 0) {
    return;
  }
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar2 + iVar1 + 0xb8));
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar2 + iVar1 + 0xd8));
  *(undefined2 *)(iVar2 + 2) = 0;
  return;
}


void __SetSURegs(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = gx;
  param_2 = param_2 * 4;
  iVar2 = gx + param_1 * 4;
  uVar3 = *(uint *)(iVar2 + 0x45c);
  iVar5 = gx + param_2;
  iVar6 = gx + param_2;
  *(uint *)(gx + param_2 + 0xb8) = uVar3 & 0x3ff | *(uint *)(gx + param_2 + 0xb8) & 0xffff0000;
  *(uint *)(iVar5 + 0xd8) = uVar3 >> 10 & 0x3ff | *(uint *)(iVar5 + 0xd8) & 0xffff0000;
  uVar4 = *(uint *)(iVar2 + 0x47c);
  uVar3 = countLeadingZeros(1 - (uVar4 & 3));
  *(uint *)(iVar6 + 0xb8) = *(uint *)(iVar6 + 0xb8) & 0xfffeffff | (uVar3 & 0x1fe0) << 0xb;
  uVar3 = countLeadingZeros(1 - (uVar4 >> 2 & 3));
  *(uint *)(iVar1 + param_2 + 0xd8) =
       *(uint *)(iVar1 + param_2 + 0xd8) & 0xfffeffff | (uVar3 & 0x1fe0) << 0xb;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + param_2 + 0xb8));
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + param_2 + 0xd8));
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void __GXSetSUTexRegs(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint unaff_r28;
  uint unaff_r29;
  uint uVar6;
  
  if (*(int *)(gx + 0x4dc) != 0xff) {
    uVar3 = *(uint *)(gx + 0x204);
    for (uVar6 = 0; uVar6 < (uVar3 >> 0x10 & 7); uVar6 = uVar6 + 1) {
      if (uVar6 == 2) {
        unaff_r29 = *(uint *)(gx + 0x120) >> 0xc & 7;
        unaff_r28 = *(uint *)(gx + 0x120) >> 0xf & 7;
      }
      else {
        if ((int)uVar6 < 2) {
          if (uVar6 == 0) {
            unaff_r29 = *(uint *)(gx + 0x120) & 7;
            unaff_r28 = *(uint *)(gx + 0x120) >> 3 & 7;
          }
          else {
            if (-1 < (int)uVar6) {
              unaff_r29 = *(uint *)(gx + 0x120) >> 6 & 7;
              unaff_r28 = *(uint *)(gx + 0x120) >> 9 & 7;
            }
          }
        }
        else {
          if ((int)uVar6 < 4) {
            unaff_r29 = *(uint *)(gx + 0x120) >> 0x12 & 7;
            unaff_r28 = *(uint *)(gx + 0x120) >> 0x15 & 7;
          }
        }
      }
      if ((*(uint *)(gx + 0x4dc) & 1 << unaff_r28) == 0) {
        __SetSURegs(unaff_r29,unaff_r28);
      }
    }
    iVar5 = 0;
    for (uVar6 = 0; uVar6 < (uVar3 >> 10 & 0xf) + 1; uVar6 = uVar6 + 1) {
      puVar4 = (uint *)(gx + (uVar6 & 0x7ffffffe) * 2 + 0x100);
      uVar2 = *(uint *)(gx + iVar5 + 0x49c) & 0xfffffeff;
      if ((uVar6 & 1) == 0) {
        uVar1 = *puVar4 >> 3;
      }
      else {
        uVar1 = *puVar4 >> 0xf;
      }
      if (((uVar2 != 0xff) && ((*(uint *)(gx + 0x4dc) & 1 << (uVar1 & 7)) == 0)) &&
         ((*(uint *)(gx + 0x4e0) & 1 << uVar6) != 0)) {
        __SetSURegs(uVar2,uVar1 & 7);
      }
      iVar5 = iVar5 + 4;
    }
  }
  return;
}


void __GXSetTmemConfig(int param_1)

{
  if (param_1 == 1) {
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0x8c0d8000);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0x900dc000);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0x8d0d8800);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0x910dc800);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0x8e0d9000);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0x920dd000);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0x8f0d9800);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0x930dd800);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0xac0da000);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0xb00de000);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0xad0da800);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0xb10de800);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0xae0db000);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0xb20df000);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0xaf0db800);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0xb30df800);
  }
  else {
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0x8c0d8000);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0x900dc000);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0x8d0d8400);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0x910dc400);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0x8e0d8800);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0x920dc800);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0x8f0d8c00);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0x930dcc00);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0xac0d9000);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0xb00dd000);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0xad0d9400);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0xb10dd400);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0xae0d9800);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0xb20dd800);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0xaf0d9c00);
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,0xb30ddc00);
  }
  return;
}

