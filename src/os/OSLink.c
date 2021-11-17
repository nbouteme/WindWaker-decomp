#include <os/OSLink.h>
#include <os/OSCache.h>
#include <m_Do_printf.h>
#include <os/OSLink.h>


namespace os {

void OSNotifyLink(void)

{
  return;
}


void OSNotifyUnlink(void)

{
  return;
}


void OSSetStringTable(undefined4 param_1)

{
  DAT_800030d0 = param_1;
  return;
}


/* WARNING: Removing unreachable block (ram,0x80304f58) */

undefined4 Relocate(int *param_1,int param_2)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  uint *puVar4;
  uint *unaff_r28;
  uint *puVar5;
  ushort *puVar6;
  int iVar7;
  uint uVar8;
  
  if (param_1 == (int *)0x0) {
    iVar7 = 0;
  }
  else {
    iVar7 = *param_1;
  }
  piVar2 = *(int **)(param_2 + 0x28);
  piVar3 = (int *)((int)piVar2 + *(int *)(param_2 + 0x2c));
  uVar8 = (uint)((int)piVar3 + (7 - (int)piVar2)) >> 3;
  if (piVar2 < piVar3) {
    do {
      if (*piVar2 == iVar7) {
        puVar6 = (ushort *)piVar2[1];
        puVar5 = (uint *)0x0;
        goto LAB_803050f8;
      }
      piVar2 = piVar2 + 2;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
  }
  return 0;
LAB_803050f8:
  bVar1 = *(byte *)(puVar6 + 1);
  if (bVar1 == 0xcb) {
    if (puVar5 != (uint *)0x0) {
      uVar8 = *puVar5;
      DCFlushRange(uVar8 & 0xfffffffe,puVar5[1]);
      ICInvalidateRange(uVar8 & 0xfffffffe,puVar5[1]);
    }
    return 1;
  }
  unaff_r28 = (uint *)((int)unaff_r28 + (uint)*puVar6);
  if (iVar7 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = *(uint *)(param_1[4] + (uint)*(byte *)((int)puVar6 + 3) * 8) & 0xfffffffe;
  }
  puVar4 = puVar5;
  if (bVar1 == 6) {
    *(ushort *)unaff_r28 =
         (short)(uVar8 + *(int *)(puVar6 + 2) >> 0x10) +
         (ushort)((uVar8 + *(int *)(puVar6 + 2) & 0x8000) != 0);
  }
  else {
    if (bVar1 < 6) {
      if (bVar1 == 2) {
        *unaff_r28 = uVar8 + *(int *)(puVar6 + 2) & 0x3fffffc | *unaff_r28 & 0xfc000003;
      }
      else {
        if (bVar1 < 2) {
          if (bVar1 != 0) {
            *unaff_r28 = uVar8 + *(int *)(puVar6 + 2);
          }
        }
        else {
          if (bVar1 == 4) {
            *(short *)unaff_r28 = (short)uVar8 + (short)*(undefined4 *)(puVar6 + 2);
          }
          else {
            if (bVar1 < 4) {
              *(short *)unaff_r28 = (short)uVar8 + (short)*(undefined4 *)(puVar6 + 2);
            }
            else {
              *(short *)unaff_r28 = (short)(uVar8 + *(int *)(puVar6 + 2) >> 0x10);
            }
          }
        }
      }
    }
    else {
      if (bVar1 != 0xc9) {
        if (bVar1 < 0xc9) {
          if (bVar1 == 10) {
            *unaff_r28 = (uVar8 + *(int *)(puVar6 + 2)) - (int)unaff_r28 & 0x3fffffc |
                         *unaff_r28 & 0xfc000003;
          }
          else {
            if (bVar1 < 10) {
              *unaff_r28 = uVar8 + *(int *)(puVar6 + 2) & 0xfffc | *unaff_r28 & 0xffff0003;
            }
            else {
              if (0xd < bVar1) goto LAB_803050e8;
              *unaff_r28 = (uVar8 + *(int *)(puVar6 + 2)) - (int)unaff_r28 & 0xfffc |
                           *unaff_r28 & 0xffff0003;
            }
          }
        }
        else {
          if (bVar1 < 0xcb) {
            puVar4 = (uint *)(*(int *)(param_2 + 0x10) + (uint)*(byte *)((int)puVar6 + 3) * 8);
            unaff_r28 = (uint *)(*puVar4 & 0xfffffffe);
            if (puVar5 != (uint *)0x0) {
              uVar8 = *puVar5;
              DCFlushRange(uVar8 & 0xfffffffe,puVar5[1]);
              ICInvalidateRange(uVar8 & 0xfffffffe,puVar5[1]);
            }
            if ((*puVar4 & 1) == 0) {
              puVar4 = (uint *)0x0;
            }
          }
          else {
LAB_803050e8:
            m_Do_printf::OSReport(_62);
          }
        }
      }
    }
  }
  puVar6 = puVar6 + 4;
  puVar5 = puVar4;
  goto LAB_803050f8;
}


undefined4 Link(DynamicModule *rel,uint param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  DynamicModule__ImpEntry *pDVar4;
  uint *puVar5;
  DynamicModule__ImpEntry *pDVar6;
  DynamicModule__ImpEntry *pDVar7;
  DynamicModule *pDVar8;
  
  rel->mBssSectionIdx = 0;
  if ((rel->mRELFormatVersion < 4) &&
     ((rel->mRELFormatVersion < 2 ||
      (((uVar1 = rel->mAlignment, uVar1 == 0 ||
        (rel == (DynamicModule *)(((uint)rel / uVar1) * uVar1))) &&
       ((uVar1 = rel->mBssAlignment, uVar1 == 0 || (param_2 == (param_2 / uVar1) * uVar1)))))))) {
    pDVar8 = rel;
    if (DAT_800030cc != (DynamicModule *)0x0) {
      DAT_800030cc->mpNextModule = rel;
      pDVar8 = DAT_800030c8;
    }
    DAT_800030c8 = pDVar8;
    rel->mpPrevModule = DAT_800030cc;
    rel->mpNextModule = (DynamicModule *)0x0;
    DAT_800030cc = rel;
    rel->mpSectionInfoOffset =
         (DynamicModule__SectionInfo *)
         ((int)&rel->mModuleID + (int)&rel->mpSectionInfoOffset->mSectionOffsetAndFlag);
    rel->mpRelocationTable = rel->mpRelocationTable + (int)rel;
    rel->mpImpTable =
         (DynamicModule__ImpEntry *)
         ((int)&rel->mModuleID + (int)&rel->mpImpTable->mModuleIDToRelocateAgainst);
    if (2 < rel->mRELFormatVersion) {
      rel->mFixSize = (int)&rel->mModuleID + rel->mFixSize;
    }
    iVar3 = 8;
    for (uVar1 = 1; uVar1 < (uint)rel->mNumSections; uVar1 = uVar1 + 1) {
      puVar5 = (uint *)((int)&rel->mpSectionInfoOffset->mSectionOffsetAndFlag + iVar3);
      if (*puVar5 == 0) {
        if (puVar5[1] != 0) {
          rel->mBssSectionIdx = (byte)uVar1;
          *puVar5 = param_2;
        }
      }
      else {
        *puVar5 = (int)&rel->mModuleID + *puVar5;
      }
      iVar3 = iVar3 + 8;
    }
    for (pDVar6 = rel->mpImpTable;
        pDVar6 < (DynamicModule__ImpEntry *)
                 ((int)&rel->mpImpTable->mModuleIDToRelocateAgainst + rel->mImpSize);
        pDVar6 = pDVar6 + 1) {
      pDVar6->mpRelocations = (int)&rel->mModuleID + pDVar6->mpRelocations;
    }
    if (rel->mPrologSectionIdx != 0) {
      rel->mpProlog =
           rel->mpProlog +
           (rel->mpSectionInfoOffset[rel->mPrologSectionIdx].mSectionOffsetAndFlag & 0xfffffffe);
    }
    if (rel->mEpilogSectionIdx != 0) {
      rel->mpEpilog =
           rel->mpEpilog +
           (rel->mpSectionInfoOffset[rel->mEpilogSectionIdx].mSectionOffsetAndFlag & 0xfffffffe);
    }
    if (rel->mUnresolvedSectionIdx != 0) {
      rel->mpUnresolved =
           rel->mpUnresolved +
           (rel->mpSectionInfoOffset[rel->mUnresolvedSectionIdx].mSectionOffsetAndFlag & 0xfffffffe)
      ;
    }
    if (DAT_800030d0 != 0) {
      rel->mpName = rel->mpName + DAT_800030d0;
    }
    Relocate(0,rel);
    for (pDVar8 = DAT_800030c8; pDVar8 != (DynamicModule *)0x0; pDVar8 = pDVar8->mpNextModule) {
      Relocate(rel,pDVar8);
      if (pDVar8 != rel) {
        Relocate(pDVar8,rel);
      }
    }
    if (param_3 != 0) {
      pDVar7 = rel->mpImpTable;
      pDVar4 = (DynamicModule__ImpEntry *)((int)&pDVar7->mModuleIDToRelocateAgainst + rel->mImpSize)
      ;
      uVar1 = (uint)((int)pDVar4 + (7 - (int)pDVar7)) >> 3;
      pDVar6 = pDVar7;
      if (pDVar7 < pDVar4) {
        do {
          if ((pDVar6->mModuleIDToRelocateAgainst == 0) ||
             (pDVar6->mModuleIDToRelocateAgainst == rel->mModuleID)) {
            rel->mImpSize = (int)pDVar6 - (int)pDVar7;
            break;
          }
          pDVar6 = pDVar6 + 1;
          uVar1 = uVar1 - 1;
        } while (uVar1 != 0);
      }
    }
    FUN_800033a8(param_2,0,rel->mBssSize);
    OSNotifyLink(rel);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


void OSLink(DynamicModule *param_1,undefined4 param_2)

{
  Link(param_1,param_2,0);
  return;
}


undefined4 OSLinkFixed(DynamicModule *rel,undefined4 param_2)

{
  undefined4 uVar1;
  
  if ((rel->mRELFormatVersion < 4) && (2 < rel->mRELFormatVersion)) {
    uVar1 = Link(rel,param_2,1);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* WARNING: Removing unreachable block (ram,0x80305524) */

undefined4 Undo(int *param_1,int param_2)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  uint *puVar4;
  uint *unaff_r29;
  uint *puVar5;
  ushort *puVar6;
  uint uVar7;
  
  piVar2 = *(int **)(param_2 + 0x28);
  piVar3 = (int *)((int)piVar2 + *(int *)(param_2 + 0x2c));
  uVar7 = (uint)((int)piVar3 + (7 - (int)piVar2)) >> 3;
  if (piVar2 < piVar3) {
    do {
      if (*piVar2 == *param_1) {
        puVar6 = (ushort *)piVar2[1];
        puVar5 = (uint *)0x0;
        goto LAB_80305670;
      }
      piVar2 = piVar2 + 2;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  return 0;
LAB_80305670:
  bVar1 = *(byte *)(puVar6 + 1);
  if (bVar1 == 0xcb) {
    if (puVar5 != (uint *)0x0) {
      uVar7 = *puVar5;
      DCFlushRange(uVar7 & 0xfffffffe,puVar5[1]);
      ICInvalidateRange(uVar7 & 0xfffffffe,puVar5[1]);
    }
    return 1;
  }
  uVar7 = 0;
  unaff_r29 = (uint *)((int)unaff_r29 + (uint)*puVar6);
  puVar4 = puVar5;
  if (bVar1 == 6) {
    *(undefined2 *)unaff_r29 = 0;
  }
  else {
    if (bVar1 < 6) {
      if (bVar1 == 2) {
        *unaff_r29 = *unaff_r29 & 0xfc000003;
      }
      else {
        if (bVar1 < 2) {
          if (bVar1 != 0) {
            *unaff_r29 = 0;
          }
        }
        else {
          if (bVar1 == 4) {
            *(undefined2 *)unaff_r29 = 0;
          }
          else {
            if (bVar1 < 4) {
              *(undefined2 *)unaff_r29 = 0;
            }
            else {
              *(undefined2 *)unaff_r29 = 0;
            }
          }
        }
      }
    }
    else {
      if (bVar1 != 0xc9) {
        if (bVar1 < 0xc9) {
          if (bVar1 == 10) {
            if (*(char *)(param_2 + 0x32) != '\0') {
              uVar7 = *(int *)(param_2 + 0x3c) - (int)unaff_r29;
            }
            *unaff_r29 = uVar7 & 0x3fffffc | *unaff_r29 & 0xfc000003;
          }
          else {
            if (bVar1 < 10) {
              *unaff_r29 = *unaff_r29 & 0xffff0003;
            }
            else {
              if (0xd < bVar1) goto LAB_80305660;
              *unaff_r29 = *unaff_r29 & 0xffff0003;
            }
          }
        }
        else {
          if (bVar1 < 0xcb) {
            puVar4 = (uint *)(*(int *)(param_2 + 0x10) + (uint)*(byte *)((int)puVar6 + 3) * 8);
            unaff_r29 = (uint *)(*puVar4 & 0xfffffffe);
            if (puVar5 != (uint *)0x0) {
              uVar7 = *puVar5;
              DCFlushRange(uVar7 & 0xfffffffe,puVar5[1]);
              ICInvalidateRange(uVar7 & 0xfffffffe,puVar5[1]);
            }
            if ((*puVar4 & 1) == 0) {
              puVar4 = (uint *)0x0;
            }
          }
          else {
LAB_80305660:
            m_Do_printf::OSReport(_189);
          }
        }
      }
    }
  }
  puVar6 = puVar6 + 4;
  puVar5 = puVar4;
  goto LAB_80305670;
}


undefined4 OSUnlink(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  
  iVar2 = *(int *)(param_1 + 4);
  iVar5 = *(int *)(param_1 + 8);
  iVar1 = iVar5;
  if (iVar2 != 0) {
    *(int *)(iVar2 + 8) = iVar5;
    iVar1 = DAT_800030cc;
  }
  DAT_800030cc = iVar1;
  iVar1 = iVar2;
  if (iVar5 != 0) {
    *(int *)(iVar5 + 4) = iVar2;
    iVar2 = DAT_800030c8;
    iVar1 = DAT_800030c8;
  }
  for (; DAT_800030c8 = iVar1, iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
    Undo(param_1,iVar2);
    iVar1 = DAT_800030c8;
  }
  OSNotifyUnlink(param_1);
  if (DAT_800030d0 != 0) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - DAT_800030d0;
  }
  if (*(byte *)(param_1 + 0x30) != 0) {
    *(uint *)(param_1 + 0x34) =
         *(int *)(param_1 + 0x34) -
         (*(uint *)(*(int *)(param_1 + 0x10) + (uint)*(byte *)(param_1 + 0x30) * 8) & 0xfffffffe);
  }
  if (*(byte *)(param_1 + 0x31) != 0) {
    *(uint *)(param_1 + 0x38) =
         *(int *)(param_1 + 0x38) -
         (*(uint *)(*(int *)(param_1 + 0x10) + (uint)*(byte *)(param_1 + 0x31) * 8) & 0xfffffffe);
  }
  if (*(byte *)(param_1 + 0x32) != 0) {
    *(uint *)(param_1 + 0x3c) =
         *(int *)(param_1 + 0x3c) -
         (*(uint *)(*(int *)(param_1 + 0x10) + (uint)*(byte *)(param_1 + 0x32) * 8) & 0xfffffffe);
  }
  for (uVar3 = *(uint *)(param_1 + 0x28);
      uVar3 < (uint)(*(int *)(param_1 + 0x28) + *(int *)(param_1 + 0x2c)); uVar3 = uVar3 + 8) {
    *(int *)(uVar3 + 4) = *(int *)(uVar3 + 4) - param_1;
  }
  iVar2 = 8;
  for (uVar3 = 1; uVar3 < *(uint *)(param_1 + 0xc); uVar3 = uVar3 + 1) {
    piVar4 = (int *)(*(int *)(param_1 + 0x10) + iVar2);
    if (uVar3 == *(byte *)(param_1 + 0x33)) {
      *(undefined *)(param_1 + 0x33) = 0;
      *piVar4 = 0;
    }
    else {
      if (*piVar4 != 0) {
        *piVar4 = *piVar4 - param_1;
      }
    }
    iVar2 = iVar2 + 8;
  }
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) - param_1;
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - param_1;
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) - param_1;
  return 1;
}


void __OSModuleInit(void)

{
  DAT_800030c8 = 0;
  DAT_800030cc = 0;
  DAT_800030d0 = 0;
  return;
}

