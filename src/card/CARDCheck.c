#include <card/CARDCheck.h>
#include <os/OSRtc.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <card/CARDBios.h>
#include <card/CARDCheck.h>
#include <card/CARDDir.h>
#include <card/CARDBlock.h>
#include <os/OSInterrupt.h>


namespace card {

void __CARDCheckSum(ushort *param_1,uint param_2,short *param_3,short *param_4)

{
  ushort *puVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  
  *param_4 = 0;
  uVar3 = ((int)param_2 >> 1) + (uint)((int)param_2 < 0 && (param_2 & 1) != 0);
  *param_3 = 0;
  if (0 < (int)uVar3) {
    uVar4 = uVar3 >> 3;
    if (uVar4 != 0) {
      do {
        *param_3 = *param_3 + *param_1;
        *param_4 = *param_4 + ~*param_1;
        *param_3 = *param_3 + param_1[1];
        *param_4 = *param_4 + ~param_1[1];
        *param_3 = *param_3 + param_1[2];
        *param_4 = *param_4 + ~param_1[2];
        *param_3 = *param_3 + param_1[3];
        *param_4 = *param_4 + ~param_1[3];
        *param_3 = *param_3 + param_1[4];
        *param_4 = *param_4 + ~param_1[4];
        *param_3 = *param_3 + param_1[5];
        *param_4 = *param_4 + ~param_1[5];
        *param_3 = *param_3 + param_1[6];
        *param_4 = *param_4 + ~param_1[6];
        *param_3 = *param_3 + param_1[7];
        puVar1 = param_1 + 7;
        param_1 = param_1 + 8;
        *param_4 = *param_4 + ~*puVar1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
      uVar3 = uVar3 & 7;
      if (uVar3 == 0) goto LAB_8031c550;
    }
    do {
      *param_3 = *param_3 + *param_1;
      uVar2 = *param_1;
      param_1 = param_1 + 1;
      *param_4 = *param_4 + ~uVar2;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
LAB_8031c550:
  if (*param_3 == -1) {
    *param_3 = 0;
  }
  if (*param_4 == -1) {
    *param_4 = 0;
    return;
  }
  return;
}


card_errors VerifyID(int param_1)

{
  ushort uVar1;
  ushort *puVar2;
  card_errors cVar3;
  int iVar4;
  ushort uVar5;
  uint extraout_r4;
  ushort uVar6;
  ushort *puVar7;
  uint uVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  ulonglong uVar12;
  
  puVar2 = *(ushort **)(param_1 + 0x80);
  if ((puVar2[0x10] == 0) && (puVar2[0x11] == *(ushort *)(param_1 + 8))) {
    uVar6 = 0;
    uVar5 = 0;
    iVar11 = 0x1f;
    puVar7 = puVar2;
    do {
      uVar5 = uVar5 + *puVar7 + puVar7[1] + puVar7[2] + puVar7[3] + puVar7[4] + puVar7[5] +
              puVar7[6] + puVar7[7];
      uVar6 = uVar6 + ~*puVar7 + ~puVar7[1] + ~puVar7[2] + ~puVar7[3] + ~puVar7[4] + ~puVar7[5] +
              ~puVar7[6] + ~puVar7[7];
      puVar7 = puVar7 + 8;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    iVar11 = 6;
    do {
      uVar1 = *puVar7;
      puVar7 = puVar7 + 1;
      uVar5 = uVar5 + uVar1;
      uVar6 = uVar6 + ~uVar1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    if (uVar5 == 0xffff) {
      uVar5 = 0;
    }
    if (uVar6 == 0xffff) {
      uVar6 = 0;
    }
    if ((puVar2[0xfe] == uVar5) && (puVar2[0xff] == uVar6)) {
      iVar10 = *(int *)(puVar2 + 6);
      uVar8 = *(uint *)(puVar2 + 8);
      iVar4 = os::__OSLockSramEx();
      iVar11 = (param_1 + 0x7fc0ed00) / 0x110 + (param_1 + 0x7fc0ed00 >> 0x1f);
      pbVar9 = (byte *)(iVar4 + (iVar11 - (iVar11 >> 0x1f)) * 0xc);
      iVar11 = 0;
      puVar7 = puVar2;
      do {
        uVar12 = Runtime.PPCEABI.H::__shr2i
                           (iVar10 * 0x41c64e6d + (int)((ulonglong)uVar8 * 0x41c64e6d >> 0x20) +
                            (uint)(0xffffcfc6 < uVar8 * 0x41c64e6d),uVar8 * 0x41c64e6d + 0x3039,0x10
                           );
        if ((uint)*(byte *)puVar7 != ((int)uVar12 + (uint)*pbVar9 & 0xff)) {
          os::__OSUnlockSramEx(0);
          return CARD_ERROR_BROKEN;
        }
        uVar8 = (int)uVar12 * 0x41c64e6d;
        Runtime.PPCEABI.H::__shr2i
                  ((int)(uVar12 >> 0x20) * 0x41c64e6d +
                   (int)((uVar12 & 0xffffffff) * 0x41c64e6d >> 0x20) + (uint)(0xffffcfc6 < uVar8),
                   uVar8 + 0x3039,0x10);
        iVar11 = iVar11 + 1;
        uVar8 = extraout_r4 & 0x7fff;
        iVar10 = 0;
        pbVar9 = pbVar9 + 1;
        puVar7 = (ushort *)((int)puVar7 + 1);
      } while (iVar11 < 0xc);
      os::__OSUnlockSramEx(0);
      uVar5 = __CARDGetFontEncode();
      if (puVar2[0x12] == uVar5) {
        cVar3 = CARD_ERROR_READY;
      }
      else {
        cVar3 = CARD_ERROR_ENCODING;
      }
    }
    else {
      cVar3 = CARD_ERROR_BROKEN;
    }
  }
  else {
    cVar3 = CARD_ERROR_BROKEN;
  }
  return cVar3;
}


int VerifyDir(int param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  ushort *puVar3;
  ushort **ppuVar4;
  ushort **ppuVar5;
  ushort uVar6;
  ushort uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  ushort *local_24;
  int local_20;
  ushort *local_1c [4];
  
  ppuVar4 = local_1c;
  ppuVar5 = &local_24;
  iVar9 = 0;
  uVar8 = 0;
  uVar2 = 0;
  do {
    *ppuVar4 = (ushort *)(*(int *)(param_1 + 0x80) + (uVar2 + 1) * 0x2000);
    uVar7 = 0;
    *ppuVar5 = *ppuVar4 + 0xfe0;
    uVar6 = 0;
    puVar3 = *ppuVar4;
    iVar10 = 0x1ff;
    do {
      uVar6 = uVar6 + *puVar3 + puVar3[1] + puVar3[2] + puVar3[3] + puVar3[4] + puVar3[5] +
              puVar3[6] + puVar3[7];
      uVar7 = uVar7 + ~*puVar3 + ~puVar3[1] + ~puVar3[2] + ~puVar3[3] + ~puVar3[4] + ~puVar3[5] +
              ~puVar3[6] + ~puVar3[7];
      puVar3 = puVar3 + 8;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    iVar10 = 6;
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 1;
      uVar6 = uVar6 + uVar1;
      uVar7 = uVar7 + ~uVar1;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    if (uVar6 == 0xffff) {
      uVar6 = 0;
    }
    if (uVar7 == 0xffff) {
      uVar7 = 0;
    }
    if ((uVar6 != (*ppuVar5)[0x1e]) || (uVar7 != (*ppuVar5)[0x1f])) {
      *(undefined4 *)(param_1 + 0x84) = 0;
      iVar9 = iVar9 + 1;
      uVar8 = uVar2;
    }
    uVar2 = uVar2 + 1;
    ppuVar4 = ppuVar4 + 1;
    ppuVar5 = ppuVar5 + 1;
  } while ((int)uVar2 < 2);
  if (iVar9 == 0) {
    if (*(ushort **)(param_1 + 0x84) == (ushort *)0x0) {
      uVar8 = (uint)(-1 < (int)(short)local_24[0x1d] - (int)*(short *)(local_20 + 0x3a));
      *(ushort **)(param_1 + 0x84) = local_1c[uVar8];
      copy_bytes((byte *)local_1c[uVar8],(byte *)local_1c[uVar8 ^ 1],0x2000);
    }
    else {
      uVar8 = (uint)(*(ushort **)(param_1 + 0x84) != local_1c[0]);
    }
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = uVar8;
  }
  return iVar9;
}


int VerifyFAT(int param_1,uint *param_2)

{
  short **ppsVar1;
  uint uVar2;
  ushort *puVar3;
  short *psVar4;
  short *psVar5;
  ushort uVar6;
  short sVar7;
  short sVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  short *local_18;
  int local_14;
  
  uVar2 = 0;
  iVar10 = 0;
  uVar9 = 0;
  ppsVar1 = &local_18;
  do {
    psVar5 = (short *)(*(int *)(param_1 + 0x80) + (uVar2 + 3) * 0x2000);
    *ppsVar1 = psVar5;
    puVar3 = (ushort *)(psVar5 + 2);
    sVar8 = 0;
    sVar7 = 0;
    iVar11 = 0x1ff;
    do {
      sVar7 = sVar7 + *puVar3 + puVar3[1] + puVar3[2] + puVar3[3] + puVar3[4] + puVar3[5] +
              puVar3[6] + puVar3[7];
      sVar8 = sVar8 + ~*puVar3 + ~puVar3[1] + ~puVar3[2] + ~puVar3[3] + ~puVar3[4] + ~puVar3[5] +
              ~puVar3[6] + ~puVar3[7];
      puVar3 = puVar3 + 8;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    iVar11 = 6;
    do {
      uVar6 = *puVar3;
      puVar3 = puVar3 + 1;
      sVar7 = sVar7 + uVar6;
      sVar8 = sVar8 + ~uVar6;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    if (sVar7 == -1) {
      sVar7 = 0;
    }
    if (sVar8 == -1) {
      sVar8 = 0;
    }
    if ((*psVar5 == sVar7) && (psVar5[1] == sVar8)) {
      psVar4 = psVar5 + 5;
      sVar7 = 0;
      for (uVar6 = 5; uVar6 < *(ushort *)(param_1 + 0x10); uVar6 = uVar6 + 1) {
        if (*psVar4 == 0) {
          sVar7 = sVar7 + 1;
        }
        psVar4 = psVar4 + 1;
      }
      if (sVar7 != psVar5[3]) {
        *(undefined4 *)(param_1 + 0x88) = 0;
        iVar10 = iVar10 + 1;
        uVar9 = uVar2;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x88) = 0;
      iVar10 = iVar10 + 1;
      uVar9 = uVar2;
    }
    uVar2 = uVar2 + 1;
    ppsVar1 = ppsVar1 + 1;
  } while ((int)uVar2 < 2);
  if (iVar10 == 0) {
    if (*(short **)(param_1 + 0x88) == (short *)0x0) {
      uVar9 = (uint)(-1 < (int)local_18[2] - (int)*(short *)(local_14 + 4));
      *(short **)(param_1 + 0x88) = (&local_18)[uVar9];
      copy_bytes((byte *)(&local_18)[uVar9],(byte *)(&local_18)[uVar9 ^ 1],0x2000);
    }
    else {
      uVar9 = (uint)(*(short **)(param_1 + 0x88) != local_18);
    }
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = uVar9;
  }
  return iVar10;
}


card_errors __CARDVerify(int param_1)

{
  card_errors cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = VerifyID(param_1);
  if (-1 < (int)cVar1) {
    iVar2 = VerifyDir(param_1,0);
    iVar3 = VerifyFAT(param_1,0);
    iVar2 = iVar2 + iVar3;
    if (iVar2 == 1) {
      cVar1 = CARD_ERROR_BROKEN;
    }
    else {
      if ((iVar2 < 1) && (-1 < iVar2)) {
        cVar1 = CARD_ERROR_READY;
      }
      else {
        cVar1 = CARD_ERROR_BROKEN;
      }
    }
  }
  return cVar1;
}


/* WARNING: Type propagation algorithm not settling */

card_errors CARDCheckExAsync(int param_1,undefined4 *param_2,code *param_3)

{
  ushort *puVar1;
  uint uVar2;
  bool bVar3;
  byte bVar4;
  bool bVar5;
  card_errors cVar6;
  int iVar7;
  int iVar8;
  ushort uVar10;
  undefined4 uVar9;
  card_workarea *pcVar11;
  ushort *puVar12;
  short *psVar13;
  card_fat_block *pcVar14;
  char *pcVar15;
  ushort uVar16;
  short sVar17;
  uint local_40;
  uint local_3c;
  card_workarea *local_38;
  card_dat *local_34;
  card_dat *local_30 [2];
  CardBlockData *local_28 [3];
  
  bVar4 = 0;
  bVar5 = false;
  bVar3 = false;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  cVar6 = __CARDGetControlBlock(param_1,local_28);
  if (-1 < (int)cVar6) {
    cVar6 = VerifyID((int)local_28[0]);
    if ((int)cVar6 < 0) {
      cVar6 = __CARDPutControlBlock(local_28[0],cVar6);
    }
    else {
      iVar7 = VerifyDir(local_28[0],&local_40);
      iVar8 = VerifyFAT(local_28[0],&local_3c);
      if (iVar7 + iVar8 < 2) {
        pcVar11 = (local_28[0]->mCard_block).mpWorkarea;
        local_30[0] = &pcVar11->mWorkarea1;
        local_38 = pcVar11 + 1;
        local_30[1] = &pcVar11->mWorkarea2;
        local_34 = &pcVar11[1].mWorkarea1;
        if (iVar7 + iVar8 == 1) {
          if ((local_28[0]->mCard_block).mpCurr_dir == (card_dat *)0x0) {
            (local_28[0]->mCard_block).mpCurr_dir = local_30[local_40];
            copy_bytes((byte *)local_30[local_40],(byte *)local_30[local_40 ^ 1],0x2000);
            bVar5 = true;
          }
          else {
            (local_28[0]->mCard_block).mpCurr_fat = (card_fat_block *)(&local_38)[local_3c];
            copy_bytes((byte *)(&local_38)[local_3c],(byte *)(&local_38)[local_3c ^ 1],0x2000);
            bVar4 = 1;
          }
        }
        pcVar11 = (&local_38)[local_3c ^ 1];
        FUN_800033a8((int)pcVar11,0,0x2000);
        iVar8 = 0x7f;
        iVar7 = 0;
        do {
          pcVar15 = ((local_28[0]->mCard_block).mpCurr_dir)->mDirEntries[0].mGamecode + iVar7;
          if (*pcVar15 != -1) {
            uVar10 = *(ushort *)(pcVar15 + 0x36);
            for (uVar16 = 0; (uVar10 != 0xffff && (uVar16 < *(ushort *)(pcVar15 + 0x38)));
                uVar16 = uVar16 + 1) {
              uVar2 = (uint)uVar10;
              if ((uVar2 < 5) ||
                 (((ushort)local_28[0]->mMaxBlockSize <= uVar2 ||
                  (uVar10 = *(short *)((pcVar11->mHeaderData).mDirEntries[0].mGamecode + uVar2 * 2)
                            + 1,
                  *(ushort *)((pcVar11->mHeaderData).mDirEntries[0].mGamecode + uVar2 * 2) = uVar10,
                  1 < uVar10)))) {
                cVar6 = __CARDPutControlBlock(local_28[0],CARD_ERROR_BROKEN);
                return cVar6;
              }
              uVar10 = ((local_28[0]->mCard_block).mpCurr_fat)->mFat[uVar2 - 5];
            }
            if ((uVar16 != *(ushort *)(pcVar15 + 0x38)) || (uVar10 != 0xffff)) {
              cVar6 = __CARDPutControlBlock(local_28[0],CARD_ERROR_BROKEN);
              return cVar6;
            }
          }
          iVar7 = iVar7 + 0x40;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        psVar13 = (short *)((pcVar11->mHeaderData).mDirEntries[0].mFilename + 2);
        sVar17 = 0;
        iVar7 = 10;
        for (uVar10 = 5; uVar10 < (ushort)local_28[0]->mMaxBlockSize; uVar10 = uVar10 + 1) {
          puVar12 = (ushort *)((int)((local_28[0]->mCard_block).mpCurr_fat)->mFat + iVar7 + -10);
          uVar16 = *puVar12;
          if (*psVar13 == 0) {
            if (uVar16 != 0) {
              *puVar12 = 0;
              bVar3 = true;
            }
            sVar17 = sVar17 + 1;
          }
          else {
            if (((uVar16 < 5) || ((ushort)local_28[0]->mMaxBlockSize <= uVar16)) &&
               (uVar16 != 0xffff)) {
              cVar6 = __CARDPutControlBlock(local_28[0],CARD_ERROR_BROKEN);
              return cVar6;
            }
          }
          iVar7 = iVar7 + 2;
          psVar13 = psVar13 + 1;
        }
        psVar13 = &((local_28[0]->mCard_block).mpCurr_fat)->mFreeblocks;
        if (sVar17 != *psVar13) {
          *psVar13 = sVar17;
          bVar3 = true;
        }
        if (bVar3) {
          pcVar14 = (local_28[0]->mCard_block).mpCurr_fat;
          pcVar14->mChksum2 = 0;
          psVar13 = &pcVar14->mChksum2;
          puVar12 = (ushort *)&pcVar14->mUpdated;
          pcVar14->mChksum1 = 0;
          iVar7 = 0x1ff;
          do {
            pcVar14->mChksum1 = pcVar14->mChksum1 + *puVar12;
            *psVar13 = *psVar13 + ~*puVar12;
            pcVar14->mChksum1 = pcVar14->mChksum1 + puVar12[1];
            *psVar13 = *psVar13 + ~puVar12[1];
            pcVar14->mChksum1 = pcVar14->mChksum1 + puVar12[2];
            *psVar13 = *psVar13 + ~puVar12[2];
            pcVar14->mChksum1 = pcVar14->mChksum1 + puVar12[3];
            *psVar13 = *psVar13 + ~puVar12[3];
            pcVar14->mChksum1 = pcVar14->mChksum1 + puVar12[4];
            *psVar13 = *psVar13 + ~puVar12[4];
            pcVar14->mChksum1 = pcVar14->mChksum1 + puVar12[5];
            *psVar13 = *psVar13 + ~puVar12[5];
            pcVar14->mChksum1 = pcVar14->mChksum1 + puVar12[6];
            *psVar13 = *psVar13 + ~puVar12[6];
            pcVar14->mChksum1 = pcVar14->mChksum1 + puVar12[7];
            puVar1 = puVar12 + 7;
            puVar12 = puVar12 + 8;
            *psVar13 = *psVar13 + ~*puVar1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          iVar7 = 6;
          do {
            pcVar14->mChksum1 = pcVar14->mChksum1 + *puVar12;
            uVar10 = *puVar12;
            puVar12 = puVar12 + 1;
            *psVar13 = *psVar13 + ~uVar10;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          if (pcVar14->mChksum1 == -1) {
            pcVar14->mChksum1 = 0;
          }
          if (*psVar13 == -1) {
            *psVar13 = 0;
          }
        }
        copy_bytes((byte *)(&local_38)[local_3c ^ 1],(byte *)(&local_38)[local_3c],0x2000);
        if (bVar5) {
          if (param_2 != (undefined4 *)0x0) {
            *param_2 = 0x2000;
          }
          cVar6 = __CARDUpdateDir(param_1,param_3);
        }
        else {
          if ((bool)(bVar4 | bVar3)) {
            if (param_2 != (undefined4 *)0x0) {
              *param_2 = 0x2000;
            }
            cVar6 = __CARDUpdateFatBlock(param_1,(local_28[0]->mCard_block).mpCurr_fat,param_3);
          }
          else {
            __CARDPutControlBlock(local_28[0],CARD_ERROR_READY);
            if (param_3 != (code *)0x0) {
              uVar9 = os::OSDisableInterrupts();
              (*param_3)(param_1,0);
              os::OSRestoreInterrupts(uVar9);
            }
            cVar6 = CARD_ERROR_READY;
          }
        }
      }
      else {
        cVar6 = __CARDPutControlBlock(local_28[0],CARD_ERROR_BROKEN);
      }
    }
  }
  return cVar6;
}


card_errors CARDCheck(int card_slot)

{
  card_errors cVar1;
  undefined auStack12 [8];
  
  cVar1 = CARDCheckExAsync(card_slot,auStack12,__CARDSyncCallback);
  if ((-1 < (int)cVar1) && ((undefined *)register0x00000004 != &DAT_0000000c)) {
    cVar1 = __CARDSync(card_slot);
  }
  return cVar1;
}

