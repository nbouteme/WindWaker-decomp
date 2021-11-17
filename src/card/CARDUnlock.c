#include <card/CARDUnlock.h>
#include <exi/EXIBios.h>
#include <os/OSTime.h>
#include <card/CARDUnlock.h>
#include <os/OSCache.h>
#include <JAudio/osdsp.h>
#include <dsp/dsp.h>
#include <card/CARDMount.h>
#include <card/CARDBios.h>


namespace card {

uint bitrev(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 8;
  uVar1 = param_1 >> 0x1f;
  iVar5 = 0;
  iVar6 = 1;
  uVar2 = 0;
  uVar3 = 0;
  do {
    if (uVar3 < 0x10) {
      uVar2 = uVar2 | (param_1 & 1 << uVar3) << (0x1f - uVar3) - iVar5;
      iVar5 = iVar5 + 1;
    }
    else {
      if (uVar3 == 0x1f) {
        uVar2 = uVar2 | uVar1;
      }
      else {
        uVar2 = uVar2 | (param_1 & 1 << uVar3) >> iVar6;
        iVar6 = iVar6 + 2;
      }
    }
    uVar4 = uVar3 + 1;
    if (uVar4 < 0x10) {
      uVar2 = uVar2 | (param_1 & 1 << uVar4) << (0x1f - uVar4) - iVar5;
      iVar5 = iVar5 + 1;
    }
    else {
      if (uVar4 == 0x1f) {
        uVar2 = uVar2 | uVar1;
      }
      else {
        uVar2 = uVar2 | (param_1 & 1 << uVar4) >> iVar6;
        iVar6 = iVar6 + 2;
      }
    }
    uVar4 = uVar3 + 2;
    if (uVar4 < 0x10) {
      uVar2 = uVar2 | (param_1 & 1 << uVar4) << (0x1f - uVar4) - iVar5;
      iVar5 = iVar5 + 1;
    }
    else {
      if (uVar4 == 0x1f) {
        uVar2 = uVar2 | uVar1;
      }
      else {
        uVar2 = uVar2 | (param_1 & 1 << uVar4) >> iVar6;
        iVar6 = iVar6 + 2;
      }
    }
    uVar4 = uVar3 + 3;
    if (uVar4 < 0x10) {
      uVar2 = uVar2 | (param_1 & 1 << uVar4) << (0x1f - uVar4) - iVar5;
      iVar5 = iVar5 + 1;
    }
    else {
      if (uVar4 == 0x1f) {
        uVar2 = uVar2 | uVar1;
      }
      else {
        uVar2 = uVar2 | (param_1 & 1 << uVar4) >> iVar6;
        iVar6 = iVar6 + 2;
      }
    }
    uVar3 = uVar3 + 4;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  return uVar2;
}


card_errors
ReadArrayUnlock(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  card_errors cVar6;
  undefined4 uVar7;
  undefined local_24;
  byte local_23;
  undefined local_22;
  byte local_21;
  byte local_20;
  
  iVar5 = exi::EXISelect(param_1,0,4);
  if (iVar5 == 0) {
    cVar6 = CARD_ERROR_NOCARD;
  }
  else {
    FUN_800033a8((int)&local_24,0,5);
    local_24 = 0x52;
    local_23 = (byte)((param_2 & 0xfffff000) >> 0x18);
    if (param_5 == 0) {
      local_23 = local_23 >> 5 & 3;
      local_22 = (undefined)(param_2 >> 0x15);
      local_21 = (byte)(param_2 >> 0x13) & 3;
      local_20 = (byte)(param_2 >> 0xc) & 0x7f;
    }
    else {
      local_22 = (undefined)((param_2 & 0xfffff000) >> 0x10);
    }
    uVar7 = exi::EXIImmEx(param_1,&local_24,5,1);
    uVar1 = countLeadingZeros(uVar7);
    uVar7 = exi::EXIImmEx(param_1,((__CARDBlock[param_1].mCard_block.mpWorkarea)->mHeaderData).
                                  mDirEntries + 8,__CARDBlock[param_1].field_0x14,1);
    uVar2 = countLeadingZeros(uVar7);
    uVar7 = exi::EXIImmEx(param_1,param_3,param_4,0);
    uVar3 = countLeadingZeros(uVar7);
    uVar7 = exi::EXIDeselect(param_1);
    uVar4 = countLeadingZeros(uVar7);
    if ((uVar1 | uVar2 | uVar3 | uVar4) >> 5 == 0) {
      cVar6 = CARD_ERROR_READY;
    }
    else {
      cVar6 = CARD_ERROR_NOCARD;
    }
  }
  return cVar6;
}


uint DummyLen(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 1;
  iVar1 = os::OSGetTick();
  for (uVar3 = 0;
      (next = iVar1 * 0x41c64e6d + 0x3039, uVar2 = (next >> 0x10 & 0x1f) + 1, uVar2 < 4 &&
      (uVar3 < 10)); uVar3 = uVar3 + 1) {
    iVar1 = os::OSGetTick();
    iVar1 = iVar1 << uVar4;
    uVar4 = uVar4 + 1;
    if (0x10 < uVar4) {
      uVar4 = 1;
    }
  }
  if (uVar2 < 4) {
    uVar2 = 4;
  }
  return uVar2;
}


/* WARNING: Type propagation algorithm not settling */

undefined4 __CARDUnlock(int param_1,uint *param_2)

{
  uint *puVar1;
  card_workarea *pcVar2;
  int iVar3;
  uint uVar4;
  card_errors cVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  
  pcVar2 = __CARDBlock[param_1].mCard_block.mpWorkarea;
  puVar1 = (uint *)((int)&(pcVar2->mHeaderData).mDirEntries[0].mIconaddr + 3U & 0xffffffe0);
  iVar3 = os::OSGetTick();
  next = iVar3 * 0x41c64e6d + 0x3039;
  uVar9 = next >> 0x10 & 0x7000 | 0x7fec8000;
  uVar4 = DummyLen();
  cVar5 = ReadArrayUnlock(param_1,uVar9,&local_7c,uVar4,0);
  if ((int)cVar5 < 0) {
    uVar6 = 0xfffffffd;
  }
  else {
    uVar8 = uVar4 * 8 + 1;
    uVar7 = 0;
    if (uVar8 != 0) {
      if ((8 < uVar8) && (uVar10 = uVar4 & 0x1fffffff, uVar4 * 8 != 7)) {
        do {
          uVar9 = uVar9 >> 1 | (~(uVar9 >> 0x17 ^ uVar9 >> 0xf ^ uVar9 ^ uVar9 >> 7) & 1) << 0x1e;
          uVar9 = uVar9 >> 1 | (~(uVar9 >> 0x17 ^ uVar9 >> 0xf ^ uVar9 ^ uVar9 >> 7) & 1) << 0x1e;
          uVar9 = uVar9 >> 1 | (~(uVar9 >> 0x17 ^ uVar9 >> 0xf ^ uVar9 ^ uVar9 >> 7) & 1) << 0x1e;
          uVar9 = uVar9 >> 1 | (~(uVar9 >> 0x17 ^ uVar9 >> 0xf ^ uVar9 ^ uVar9 >> 7) & 1) << 0x1e;
          uVar9 = uVar9 >> 1 | (~(uVar9 >> 0x17 ^ uVar9 >> 0xf ^ uVar9 ^ uVar9 >> 7) & 1) << 0x1e;
          uVar9 = uVar9 >> 1 | (~(uVar9 >> 0x17 ^ uVar9 >> 0xf ^ uVar9 ^ uVar9 >> 7) & 1) << 0x1e;
          uVar9 = uVar9 >> 1 | (~(uVar9 >> 0x17 ^ uVar9 >> 0xf ^ uVar9 ^ uVar9 >> 7) & 1) << 0x1e;
          uVar9 = uVar9 >> 1 | (~(uVar9 >> 0x17 ^ uVar9 >> 0xf ^ uVar9 ^ uVar9 >> 7) & 1) << 0x1e;
          uVar7 = uVar7 + 8;
          uVar10 = uVar10 - 1;
        } while (uVar10 != 0);
      }
      iVar3 = uVar8 - uVar7;
      if (uVar7 < uVar8) {
        do {
          uVar9 = uVar9 >> 1 | (~(uVar9 >> 0x17 ^ uVar9 >> 0xf ^ uVar9 ^ uVar9 >> 7) & 1) << 0x1e;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
    *(uint *)&__CARDBlock[param_1].field_0x2c =
         uVar9 | ~(uVar9 >> 0x17 ^ uVar9 >> 0xf ^ uVar9 ^ uVar9 >> 7) << 0x1f;
    uVar6 = bitrev(*(undefined4 *)&__CARDBlock[param_1].field_0x2c);
    *(undefined4 *)&__CARDBlock[param_1].field_0x2c = uVar6;
    iVar3 = DummyLen();
    cVar5 = ReadArrayUnlock(param_1,0,&local_7c,iVar3 + 0x14,1);
    if ((int)cVar5 < 0) {
      uVar6 = 0xfffffffd;
    }
    else {
      uVar9 = *(uint *)&__CARDBlock[param_1].field_0x2c;
      iVar11 = 4;
      local_7c = local_7c ^ uVar9;
      do {
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      *(uint *)&__CARDBlock[param_1].field_0x2c =
           uVar9 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1f;
      iVar11 = 4;
      uVar9 = *(uint *)&__CARDBlock[param_1].field_0x2c;
      local_78 = local_78 ^ uVar9;
      do {
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      *(uint *)&__CARDBlock[param_1].field_0x2c =
           uVar9 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1f;
      iVar11 = 4;
      uVar9 = *(uint *)&__CARDBlock[param_1].field_0x2c;
      local_74 = local_74 ^ uVar9;
      do {
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      *(uint *)&__CARDBlock[param_1].field_0x2c =
           uVar9 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1f;
      iVar11 = 4;
      uVar9 = *(uint *)&__CARDBlock[param_1].field_0x2c;
      local_70 = local_70 ^ uVar9;
      do {
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        uVar9 = uVar9 << 1 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1e & 2;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      *(uint *)&__CARDBlock[param_1].field_0x2c =
           uVar9 | ~(uVar9 << 0x17 ^ uVar9 << 0xf ^ uVar9 ^ uVar9 << 7) >> 0x1f;
      uVar9 = iVar3 * 8;
      uVar7 = *(uint *)&__CARDBlock[param_1].field_0x2c;
      uVar4 = 0;
      local_6c = local_6c ^ uVar7;
      if (uVar9 != 0) {
        if ((8 < uVar9) && (uVar8 = uVar9 - 1 >> 3, uVar9 != 8)) {
          do {
            uVar7 = uVar7 << 1 | ~(uVar7 << 0x17 ^ uVar7 << 0xf ^ uVar7 ^ uVar7 << 7) >> 0x1e & 2;
            uVar7 = uVar7 << 1 | ~(uVar7 << 0x17 ^ uVar7 << 0xf ^ uVar7 ^ uVar7 << 7) >> 0x1e & 2;
            uVar7 = uVar7 << 1 | ~(uVar7 << 0x17 ^ uVar7 << 0xf ^ uVar7 ^ uVar7 << 7) >> 0x1e & 2;
            uVar7 = uVar7 << 1 | ~(uVar7 << 0x17 ^ uVar7 << 0xf ^ uVar7 ^ uVar7 << 7) >> 0x1e & 2;
            uVar7 = uVar7 << 1 | ~(uVar7 << 0x17 ^ uVar7 << 0xf ^ uVar7 ^ uVar7 << 7) >> 0x1e & 2;
            uVar7 = uVar7 << 1 | ~(uVar7 << 0x17 ^ uVar7 << 0xf ^ uVar7 ^ uVar7 << 7) >> 0x1e & 2;
            uVar7 = uVar7 << 1 | ~(uVar7 << 0x17 ^ uVar7 << 0xf ^ uVar7 ^ uVar7 << 7) >> 0x1e & 2;
            uVar7 = uVar7 << 1 | ~(uVar7 << 0x17 ^ uVar7 << 0xf ^ uVar7 ^ uVar7 << 7) >> 0x1e & 2;
            uVar4 = uVar4 + 8;
            uVar8 = uVar8 - 1;
          } while (uVar8 != 0);
        }
        iVar3 = uVar9 - uVar4;
        if (uVar4 < uVar9) {
          do {
            uVar7 = uVar7 << 1 | ~(uVar7 << 0x17 ^ uVar7 << 0xf ^ uVar7 ^ uVar7 << 7) >> 0x1e & 2;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
      }
      *(uint *)&__CARDBlock[param_1].field_0x2c =
           uVar7 | ~(uVar7 << 0x17 ^ uVar7 << 0xf ^ uVar7 ^ uVar7 << 7) >> 0x1f;
      iVar3 = 4;
      uVar9 = 0;
      uVar4 = *(uint *)&__CARDBlock[param_1].field_0x2c;
      do {
        uVar4 = uVar4 << 1 | ~(uVar4 << 0x17 ^ uVar4 << 0xf ^ uVar4 ^ uVar4 << 7) >> 0x1e & 2;
        uVar4 = uVar4 << 1 | ~(uVar4 << 0x17 ^ uVar4 << 0xf ^ uVar4 ^ uVar4 << 7) >> 0x1e & 2;
        uVar4 = uVar4 << 1 | ~(uVar4 << 0x17 ^ uVar4 << 0xf ^ uVar4 ^ uVar4 << 7) >> 0x1e & 2;
        uVar4 = uVar4 << 1 | ~(uVar4 << 0x17 ^ uVar4 << 0xf ^ uVar4 ^ uVar4 << 7) >> 0x1e & 2;
        uVar4 = uVar4 << 1 | ~(uVar4 << 0x17 ^ uVar4 << 0xf ^ uVar4 ^ uVar4 << 7) >> 0x1e & 2;
        uVar4 = uVar4 << 1 | ~(uVar4 << 0x17 ^ uVar4 << 0xf ^ uVar4 ^ uVar4 << 7) >> 0x1e & 2;
        uVar4 = uVar4 << 1 | ~(uVar4 << 0x17 ^ uVar4 << 0xf ^ uVar4 ^ uVar4 << 7) >> 0x1e & 2;
        uVar4 = uVar4 << 1 | ~(uVar4 << 0x17 ^ uVar4 << 0xf ^ uVar4 ^ uVar4 << 7) >> 0x1e & 2;
        uVar9 = uVar9 + 8;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      iVar3 = 0x21 - uVar9;
      if (uVar9 < 0x21) {
        do {
          uVar4 = uVar4 << 1 | ~(uVar4 << 0x17 ^ uVar4 << 0xf ^ uVar4 ^ uVar4 << 7) >> 0x1e & 2;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      *(uint *)&__CARDBlock[param_1].field_0x2c =
           uVar4 | ~(uVar4 << 0x17 ^ uVar4 << 0xf ^ uVar4 ^ uVar4 << 7) >> 0x1f;
      *puVar1 = local_70;
      puVar1[1] = local_6c;
      *(uint **)(pcVar2->mHeaderData).mDirEntries[0].mGamecode = puVar1;
      *(undefined **)(pcVar2->mHeaderData).mDirEntries[0].mCompany = &DAT_00000008;
      *(uint **)((pcVar2->mHeaderData).mDirEntries[0].mFilename + 4) = puVar1 + 8;
      *(undefined4 *)(pcVar2->mHeaderData).mDirEntries[0].mFilename = 0;
      os::DCFlushRange(puVar1,8);
      os::DCInvalidateRange(puVar1 + 8,4);
      os::DCFlushRange(pcVar2,0x10);
      *(undefined4 *)(__CARDBlock[param_1].mCard_block.mCmd + 6) = 0xff;
      *(undefined4 *)((int)&__CARDBlock[param_1].mCard_block.mCmd_mode + 2) = 0x3a1640;
      *(undefined4 *)((int)&__CARDBlock[param_1].mCard_block.mCmd_blck_cnt + 2) = 0x160;
      *(undefined4 *)((int)&__CARDBlock[param_1].mCard_block.mCmd_sector_addr + 2) = 0;
      *(undefined2 *)((int)&__CARDBlock[param_1].mCard_block.mCid + 2) = 0x10;
      __CARDBlock[param_1].mCard_block.mMount_step = (uint)InitCallback;
      __CARDBlock[param_1].mCard_block.mFormat_step = 0;
      __CARDBlock[param_1].mCard_block.mSector_size = (uint)DoneCallback;
      *(undefined4 *)&__CARDBlock[param_1].mCard_block.mBlocks = 0;
      JAudio::DSPAddTask(param_1 * 0x110 + -0x7fc0ecd0);
      *param_2 = local_7c;
      uVar6 = 0;
      param_2[1] = local_78;
      param_2[2] = local_74;
    }
  }
  return uVar6;
}


void InitCallback(int param_1)

{
  int iVar1;
  CardBlockData *pCVar2;
  card_workarea *pcVar3;
  
  pCVar2 = __CARDBlock;
  if (param_1 != -0x7fc0ecd0) {
    pCVar2 = (CardBlockData *)0x803f1410;
  }
  pcVar3 = (pCVar2->mCard_block).mpWorkarea;
  dsp::DSPSendMailToDSP(0xff000000);
  do {
    iVar1 = dsp::DSPCheckMailToDSP();
  } while (iVar1 != 0);
  dsp::DSPSendMailToDSP(pcVar3);
  do {
    iVar1 = dsp::DSPCheckMailToDSP();
  } while (iVar1 != 0);
  return;
}


/* WARNING: Type propagation algorithm not settling */

void DoneCallback(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  card_errors cVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  CardBlockData *pCVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  byte local_58 [4];
  undefined auStack84 [68];
  
  iVar10 = 0;
  pCVar8 = __CARDBlock;
  if (param_1 != -0x7fc0ecd0) {
    iVar10 = 1;
    pCVar8 = (CardBlockData *)0x803f1410;
    if (param_1 != -0x7fc0ebc0) {
      iVar10 = 2;
      pCVar8 = (CardBlockData *)0x803f1410;
    }
  }
  uVar9 = *(uint *)(((int)&(((pCVar8->mCard_block).mpWorkarea)->mHeaderData).mDirEntries[0].
                           mIconaddr + 3U & 0xffffffe0U) + 0x20);
  iVar3 = DummyLen();
  cVar4 = ReadArrayUnlock(iVar10,(uVar9 ^ *(uint *)&pCVar8->field_0x2c) & 0xffff0000,auStack84,iVar3
                          ,1);
  if ((int)cVar4 < 0) {
    exi::EXIUnlock(iVar10);
    __CARDMountCallback(iVar10,0xfffffffd);
  }
  else {
    uVar5 = 0;
    uVar2 = *(uint *)&pCVar8->field_0x2c;
    iVar1 = (int)(pCVar8->field_0x14 + iVar3 + 4) * 8;
    uVar7 = iVar1 + 1;
    if (uVar7 != 0) {
      if ((8 < uVar7) && (uVar11 = (uint)(pCVar8->field_0x14 + iVar3 + 4) & 0x1fffffff, iVar1 != 7))
      {
        do {
          uVar2 = uVar2 << 1 | ~(uVar2 << 0x17 ^ uVar2 << 0xf ^ uVar2 ^ uVar2 << 7) >> 0x1e & 2;
          uVar2 = uVar2 << 1 | ~(uVar2 << 0x17 ^ uVar2 << 0xf ^ uVar2 ^ uVar2 << 7) >> 0x1e & 2;
          uVar2 = uVar2 << 1 | ~(uVar2 << 0x17 ^ uVar2 << 0xf ^ uVar2 ^ uVar2 << 7) >> 0x1e & 2;
          uVar2 = uVar2 << 1 | ~(uVar2 << 0x17 ^ uVar2 << 0xf ^ uVar2 ^ uVar2 << 7) >> 0x1e & 2;
          uVar2 = uVar2 << 1 | ~(uVar2 << 0x17 ^ uVar2 << 0xf ^ uVar2 ^ uVar2 << 7) >> 0x1e & 2;
          uVar2 = uVar2 << 1 | ~(uVar2 << 0x17 ^ uVar2 << 0xf ^ uVar2 ^ uVar2 << 7) >> 0x1e & 2;
          uVar2 = uVar2 << 1 | ~(uVar2 << 0x17 ^ uVar2 << 0xf ^ uVar2 ^ uVar2 << 7) >> 0x1e & 2;
          uVar2 = uVar2 << 1 | ~(uVar2 << 0x17 ^ uVar2 << 0xf ^ uVar2 ^ uVar2 << 7) >> 0x1e & 2;
          uVar5 = uVar5 + 8;
          uVar11 = uVar11 - 1;
        } while (uVar11 != 0);
      }
      iVar3 = uVar7 - uVar5;
      if (uVar5 < uVar7) {
        do {
          uVar2 = uVar2 << 1 | ~(uVar2 << 0x17 ^ uVar2 << 0xf ^ uVar2 ^ uVar2 << 7) >> 0x1e & 2;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
    *(uint *)&pCVar8->field_0x2c =
         uVar2 | ~(uVar2 << 0x17 ^ uVar2 << 0xf ^ uVar2 ^ uVar2 << 7) >> 0x1f;
    uVar6 = DummyLen();
    cVar4 = ReadArrayUnlock(iVar10,(uVar9 << 0x10 ^ *(uint *)&pCVar8->field_0x2c) & 0xffff0000,
                            auStack84,uVar6,1);
    if ((int)cVar4 < 0) {
      exi::EXIUnlock(iVar10);
      __CARDMountCallback(iVar10,0xfffffffd);
    }
    else {
      cVar4 = __CARDReadStatus(iVar10,local_58);
      iVar3 = exi::EXIProbe(iVar10);
      if (iVar3 == 0) {
        exi::EXIUnlock(iVar10);
        __CARDMountCallback(iVar10,0xfffffffd);
      }
      else {
        if ((cVar4 == CARD_ERROR_READY) && ((local_58[0] & 0x40) == 0)) {
          exi::EXIUnlock(iVar10);
          cVar4 = CARD_ERROR_IOERROR;
        }
        __CARDMountCallback(iVar10,cVar4);
      }
    }
  }
  return;
}

