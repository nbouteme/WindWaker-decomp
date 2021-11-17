#include <gx/GXGeometry.h>
#include <gx/GXTexture.h>
#include <gx/GXBump.h>
#include <gx/GXGeometry.h>
#include <gx/GXAttr.h>


namespace gx {

void __GXSetDirtyState(void)

{
  if ((*(uint *)(gx + 0x4f4) & 1) != 0) {
    __GXSetSUTexRegs();
  }
  if ((*(uint *)(gx + 0x4f4) & 2) != 0) {
    __GXUpdateBPMask();
  }
  if ((*(uint *)(gx + 0x4f4) & 4) != 0) {
    __GXSetGenMode();
  }
  if ((*(uint *)(gx + 0x4f4) & 8) != 0) {
    __GXSetVCD();
  }
  if ((*(uint *)(gx + 0x4f4) & 0x10) != 0) {
    __GXSetVAT();
  }
  if ((*(uint *)(gx + 0x4f4) & 0x18) != 0) {
    __GXCalculateVLim();
  }
  *(undefined4 *)(gx + 0x4f4) = 0;
  return;
}


void GXBegin(byte param_1,byte param_2,undefined2 param_3)

{
  if (gx[0x13d] != 0) {
    if ((gx[0x13d] & 1U) != 0) {
      __GXSetSUTexRegs();
    }
    if ((gx[0x13d] & 2U) != 0) {
      __GXUpdateBPMask();
    }
    if ((gx[0x13d] & 4U) != 0) {
      __GXSetGenMode();
    }
    if ((gx[0x13d] & 8U) != 0) {
      __GXSetVCD();
    }
    if ((gx[0x13d] & 0x10U) != 0) {
      __GXSetVAT();
    }
    if ((gx[0x13d] & 0x18U) != 0) {
      __GXCalculateVLim();
    }
    gx[0x13d] = 0;
  }
  if (*gx == 0) {
    __GXSendFlushPrim();
  }
  write_volatile_1(DAT_cc008000,param_2 | param_1);
  write_volatile_2(0xcc008000,param_3);
  return;
}


void __GXSendFlushPrim(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = (uint)*(ushort *)(gx + 4) * (uint)*(ushort *)(gx + 6);
  write_volatile_1(DAT_cc008000,0x98);
  write_volatile_2(0xcc008000,*(ushort *)(gx + 4));
  uVar1 = iVar3 + 3;
  uVar2 = uVar1 >> 2;
  if (iVar3 != 0) {
    uVar1 = uVar1 >> 5;
    if (uVar1 != 0) {
      do {
        write_volatile_4(0xcc008000,0);
        write_volatile_4(0xcc008000,0);
        write_volatile_4(0xcc008000,0);
        write_volatile_4(0xcc008000,0);
        write_volatile_4(0xcc008000,0);
        write_volatile_4(0xcc008000,0);
        write_volatile_4(0xcc008000,0);
        write_volatile_4(0xcc008000,0);
        uVar1 = uVar1 - 1;
      } while (uVar1 != 0);
      uVar2 = uVar2 & 7;
      if (uVar2 == 0) goto LAB_8032322c;
    }
    do {
      write_volatile_4(0xcc008000,0);
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
LAB_8032322c:
  *(undefined2 *)(gx + 2) = 1;
  return;
}


void GXSetLineWidth(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = gx;
  *(uint *)(gx + 0x7c) = param_1 & 0xff | *(uint *)(gx + 0x7c) & 0xffffff00;
  *(uint *)(iVar1 + 0x7c) = *(uint *)(iVar1 + 0x7c) & 0xfff8ffff | param_2 << 0x10;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 0x7c));
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXSetPointSize(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = gx;
  *(uint *)(gx + 0x7c) = (param_1 & 0xff) << 8 | *(uint *)(gx + 0x7c) & 0xffff00ff;
  *(uint *)(iVar1 + 0x7c) = *(uint *)(iVar1 + 0x7c) & 0xffc7ffff | param_2 << 0x13;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 0x7c));
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXEnableTexOffsets(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = gx;
  param_1 = param_1 * 4;
  iVar2 = gx + param_1;
  *(uint *)(gx + param_1 + 0xb8) =
       *(uint *)(gx + param_1 + 0xb8) & 0xfffbffff | (param_2 & 0xff) << 0x12;
  *(uint *)(iVar2 + 0xb8) = *(uint *)(iVar2 + 0xb8) & 0xfff7ffff | (param_3 & 0xff) << 0x13;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + param_1 + 0xb8));
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXSetCullMode(int param_1)

{
  int iVar1;
  
  iVar1 = gx;
  if (param_1 == 2) {
    param_1 = 1;
  }
  else {
    if ((param_1 < 2) && (0 < param_1)) {
      param_1 = 2;
    }
  }
  *(uint *)(gx + 0x204) = *(uint *)(gx + 0x204) & 0xffff3fff | param_1 << 0xe;
  *(uint *)(iVar1 + 0x4f4) = *(uint *)(iVar1 + 0x4f4) | 4;
  return;
}


void GXSetCoPlanar(uint param_1)

{
  int iVar1;
  
  iVar1 = gx;
  *(uint *)(gx + 0x204) = *(uint *)(gx + 0x204) & 0xfff7ffff | (param_1 & 0xff) << 0x13;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,0xfe080000);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 0x204));
  return;
}


void __GXSetGenMode(void)

{
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x204));
  *(undefined2 *)(gx + 2) = 0;
  return;
}

