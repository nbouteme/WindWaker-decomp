#include <gx/GXBump.h>
#include <gx/GXBump.h>


namespace gx {

void GXSetTevIndirect
               (int param_1,uint param_2,int param_3,int param_4,int param_5,int param_6,int param_7
               ,uint param_8,byte param_9,int param_10)

{
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,
                   ((((((((param_2 & 0xfffffff3 | param_3 << 2) & 0xffffff8f | param_4 << 4) &
                         0xfffffe7f | param_10 << 7) & 0xffffe1ff | param_5 << 9) & 0xffff1fff |
                      param_6 << 0xd) & 0xfff8ffff | param_7 << 0x10) & 0xfff7ffff |
                    (uint)param_9 << 0x13) & 0xffefffff | (param_8 & 0xff) << 0x14) & 0xffffff |
                   (param_1 + 0x10) * 0x1000000);
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXSetIndTexMtx(GXIndTexMtxID param_1,float (*param_2) [6],int param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 != 8) {
    if ((int)param_1 < 8) {
      if (param_1 != 4) {
        if (3 < (int)param_1) {
          iVar1 = param_1 + 0xfffffffb;
          goto LAB_80325860;
        }
        if (0 < (int)param_1) {
          iVar1 = param_1 + ~GX_ITM_OFF;
          goto LAB_80325860;
        }
      }
    }
    else {
      if ((int)param_1 < 0xc) {
        iVar1 = param_1 + 0xfffffff7;
        goto LAB_80325860;
      }
    }
  }
  iVar1 = 0;
LAB_80325860:
  iVar1 = iVar1 * 3;
  uVar2 = SEXT14((char)((char)param_3 + '\x11'));
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,
                   (uVar2 & 3) << 0x16 |
                   (int)(_57 * (*param_2)[0]) & 0x7ffU |
                   ((int)(_57 * (*param_2)[3]) & 0x7ffU) << 0xb | (iVar1 + 6) * 0x1000000);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,
                   (iVar1 + 7) * 0x1000000 |
                   (uVar2 & 0xc) << 0x14 |
                   (int)(_57 * (*param_2)[1]) & 0x7ffU |
                   ((int)(_57 * (*param_2)[4]) & 0x7ffU) << 0xb);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,
                   (iVar1 + 8) * 0x1000000 |
                   (uVar2 & 0x30) << 0x12 |
                   (int)(_57 * (*param_2)[2]) & 0x7ffU |
                   ((int)(_57 * (*param_2)[5]) & 0x7ffU) << 0xb);
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXSetIndTexCoordScale(int param_1,uint param_2,int param_3)

{
  int iVar1;
  
  iVar1 = gx;
  if (param_1 == 2) {
    *(uint *)(gx + 300) = *(uint *)(gx + 300) & 0xfffffff0 | param_2;
    *(uint *)(iVar1 + 300) = *(uint *)(iVar1 + 300) & 0xffffff0f | param_3 << 4;
    *(uint *)(iVar1 + 300) = *(uint *)(iVar1 + 300) & 0xffffff | 0x26000000;
    write_volatile_1(DAT_cc008000,0x61);
    write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 300));
  }
  else {
    if (param_1 < 2) {
      if (param_1 == 0) {
        *(uint *)(gx + 0x128) = *(uint *)(gx + 0x128) & 0xfffffff0 | param_2;
        *(uint *)(iVar1 + 0x128) = *(uint *)(iVar1 + 0x128) & 0xffffff0f | param_3 << 4;
        *(uint *)(iVar1 + 0x128) = *(uint *)(iVar1 + 0x128) & 0xffffff | 0x25000000;
        write_volatile_1(DAT_cc008000,0x61);
        write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 0x128));
      }
      else {
        if (-1 < param_1) {
          *(uint *)(gx + 0x128) = *(uint *)(gx + 0x128) & 0xfffff0ff | param_2 << 8;
          *(uint *)(iVar1 + 0x128) = *(uint *)(iVar1 + 0x128) & 0xffff0fff | param_3 << 0xc;
          *(uint *)(iVar1 + 0x128) = *(uint *)(iVar1 + 0x128) & 0xffffff | 0x25000000;
          write_volatile_1(DAT_cc008000,0x61);
          write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 0x128));
        }
      }
    }
    else {
      if (param_1 < 4) {
        *(uint *)(gx + 300) = *(uint *)(gx + 300) & 0xfffff0ff | param_2 << 8;
        *(uint *)(iVar1 + 300) = *(uint *)(iVar1 + 300) & 0xffff0fff | param_3 << 0xc;
        *(uint *)(iVar1 + 300) = *(uint *)(iVar1 + 300) & 0xffffff | 0x26000000;
        write_volatile_1(DAT_cc008000,0x61);
        write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 300));
      }
    }
  }
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXSetIndTexOrder(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = gx;
  if (param_1 == 2) {
    *(uint *)(gx + 0x120) = *(uint *)(gx + 0x120) & 0xffff8fff | param_3 << 0xc;
    *(uint *)(iVar1 + 0x120) = *(uint *)(iVar1 + 0x120) & 0xfffc7fff | param_2 << 0xf;
  }
  else {
    if (param_1 < 2) {
      if (param_1 == 0) {
        puVar2 = (uint *)(gx + 0x120);
        *puVar2 = *(uint *)(gx + 0x120) & 0xfffffff8 | param_3;
        *puVar2 = *puVar2 & 0xffffffc7 | param_2 << 3;
      }
      else {
        if (-1 < param_1) {
          *(uint *)(gx + 0x120) = *(uint *)(gx + 0x120) & 0xfffffe3f | param_3 << 6;
          *(uint *)(iVar1 + 0x120) = *(uint *)(iVar1 + 0x120) & 0xfffff1ff | param_2 << 9;
        }
      }
    }
    else {
      if (param_1 < 4) {
        *(uint *)(gx + 0x120) = *(uint *)(gx + 0x120) & 0xffe3ffff | param_3 << 0x12;
        *(uint *)(iVar1 + 0x120) = *(uint *)(iVar1 + 0x120) & 0xff1fffff | param_2 << 0x15;
      }
    }
  }
  iVar1 = gx;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x120));
  *(uint *)(gx + 0x4f4) = *(uint *)(gx + 0x4f4) | 3;
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXSetNumIndStages(int param_1)

{
  int iVar1;
  
  iVar1 = gx;
  *(uint *)(gx + 0x204) = *(uint *)(gx + 0x204) & 0xfff8ffff | (param_1 & 0xffU) << 0x10;
  *(uint *)(iVar1 + 0x4f4) = *(uint *)(iVar1 + 0x4f4) | 6;
  return;
}


void GXSetTevDirect(undefined4 param_1)

{
  GXSetTevIndirect(param_1,0,0,0,0,0,0,0,0,0);
  return;
}


void GXSetTevIndWarp(undefined4 param_1,undefined4 param_2,char param_3,char param_4,
                        undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_4 == '\0') {
    uVar1 = 0;
  }
  else {
    uVar1 = 6;
  }
  if (param_3 == '\0') {
    uVar2 = 0;
  }
  else {
    uVar2 = 7;
  }
  GXSetTevIndirect(param_1,param_2,0,uVar2,param_5,uVar1,uVar1,0,0,0);
  return;
}


void __GXUpdateBPMask(undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  iVar2 = 0;
  for (uVar1 = *(uint *)(gx + 0x204) >> 0x10 & 7; uVar1 != 0; uVar1 = uVar1 - 1) {
    if (iVar2 == 2) {
      param_3 = *(uint *)(gx + 0x120) >> 0xc & 7;
    }
    else {
      if (iVar2 < 2) {
        if (iVar2 == 0) {
          param_3 = *(uint *)(gx + 0x120) & 7;
        }
        else {
          if (-1 < iVar2) {
            param_3 = *(uint *)(gx + 0x120) >> 6 & 7;
          }
        }
      }
      else {
        if (iVar2 < 4) {
          param_3 = *(uint *)(gx + 0x120) >> 0x12 & 7;
        }
      }
    }
    uVar3 = uVar3 | 1 << param_3;
    iVar2 = iVar2 + 1;
  }
  if ((*(uint *)(gx + 0x124) & 0xff) == uVar3) {
    return;
  }
  *(uint *)(gx + 0x124) = *(uint *)(gx + 0x124) & 0xffffff00 | uVar3;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x124));
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void __GXFlushTextureState(void)

{
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x124));
  *(undefined2 *)(gx + 2) = 0;
  return;
}

