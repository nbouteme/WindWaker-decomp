#include <J3DGraphAnimator/J3DMaterialAttach.h>
#include <J3DGraphAnimator/J3DMaterialAttach.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <Demangler/J3DMaterialTable.h>


namespace J3DMaterialTable {
}

/* __thiscall J3DMaterialTable::clear(void) */

void __thiscall J3DMaterialTable::clear(J3DMaterialTable *this)

{
  this->mMaterialCount = 0;
  this->mpMaterials = (J3DMaterial **)0x0;
  this->mpNameTab = (JUTNameTab *)0x0;
  *(undefined2 *)&this->field_0x10 = 0;
  *(undefined4 *)&this->field_0x14 = 0;
  this->mpTexture = (J3DTexture *)0x0;
  this->mpTexNameTab = (JUTNameTab *)0x0;
  *(undefined2 *)&this[1].vtbl = 0;
  return;
}


/* __thiscall J3DMaterialTable::J3DMaterialTable(void) */

void __thiscall J3DMaterialTable::J3DMaterialTable(J3DMaterialTable *this)

{
  this->vtbl = &__vt;
  clear(this);
  return;
}


/* __thiscall J3DMaterialTable::~J3DMaterialTable(void) */

void __thiscall J3DMaterialTable::_J3DMaterialTable(J3DMaterialTable *this)

{
  short in_r4;
  
  if ((this != (J3DMaterialTable *)0x0) && (this->vtbl = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall J3DMaterialTable::entryMatColorAnimator(J3DAnmColor *) */

undefined4 __thiscall
J3DMaterialTable::entryMatColorAnimator(J3DMaterialTable *this,J3DAnmColor *param_1)

{
  ushort uVar1;
  uint uVar2;
  ushort *puVar3;
  ushort uVar4;
  undefined4 uVar5;
  J3DMaterialAnm *pJVar6;
  
  uVar5 = 0;
  uVar1 = *(ushort *)(param_1 + 0x18);
  if (*(short *)&this[1].vtbl == 1) {
    uVar5 = 2;
  }
  else {
    for (uVar4 = 0; uVar4 < uVar1; uVar4 = uVar4 + 1) {
      uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x1c) + (uint)uVar4 * 2);
      if (uVar2 != 0xffff) {
        pJVar6 = this->mpMaterials[uVar2]->mpMaterialAnm;
        if ((J3DMaterialAnm *)0xbfffffff < pJVar6) {
          pJVar6 = (J3DMaterialAnm *)0x0;
        }
        if (pJVar6 == (J3DMaterialAnm *)0x0) {
          uVar5 = 1;
        }
        else {
          puVar3 = (ushort *)JKernel::operator_new(8);
          if (puVar3 != (ushort *)0x0) {
            *(J3DAnmColor **)(puVar3 + 2) = param_1;
            *puVar3 = uVar4;
          }
          pJVar6->mpMatColorAnm[0] = (J3DMatColorAnm *)puVar3;
        }
      }
    }
  }
  return uVar5;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* __thiscall J3DMaterialTable::entryTexMtxAnimator(J3DAnmTextureSRTKey *) */

undefined4 __thiscall
J3DMaterialTable::entryTexMtxAnimator(J3DMaterialTable *this,J3DAnmTextureSRTKey *param_1)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  J3DTexMtxAnm *pJVar6;
  int iVar7;
  int iVar8;
  ushort uVar9;
  undefined4 uVar10;
  J3DMaterialAnm *pJVar11;
  J3DMaterial *pJVar12;
  int iVar13;
  
  uVar10 = 0;
  uVar2 = param_1->mTrackCount;
  if (*(short *)&this[1].vtbl == 1) {
    uVar10 = 2;
  }
  else {
    for (uVar9 = 0; (uint)uVar9 < uVar2 / 3; uVar9 = uVar9 + 1) {
      uVar3 = (uint)(ushort)((param_1->mMaterialNameTable).mpRes)->mEntries[uVar9 - 2];
      if (uVar3 != 0xffff) {
        pJVar12 = this->mpMaterials[uVar3];
        pJVar11 = pJVar12->mpMaterialAnm;
        if ((J3DMaterialAnm *)0xbfffffff < pJVar11) {
          pJVar11 = (J3DMaterialAnm *)0x0;
        }
        bVar1 = (param_1->mMaterialNameTable).vtbl[uVar9];
        if (pJVar11 == (J3DMaterialAnm *)0x0) {
          uVar10 = 1;
        }
        else {
          if (bVar1 != 0xff) {
            iVar4 = (*(code *)pJVar12->mpTexGenBlock->vtbl->getTexMtx)(pJVar12->mpTexGenBlock,bVar1)
            ;
            if (iVar4 == 0) {
              puVar5 = (undefined *)JKernel::operator_new(0xc4);
              if (puVar5 != (undefined *)0x0) {
                iVar8 = 0;
                iVar4 = 0;
                do {
                  iVar7 = 0;
                  iVar13 = 4;
                  do {
                    *(undefined4 *)(puVar5 + iVar7 + 0x24 + iVar4) =
                         *(undefined4 *)(&J3DGraphBase::j3dDefaultTexMtxInfo + iVar7 + 0x24 + iVar4)
                    ;
                    iVar7 = iVar7 + 4;
                    iVar13 = iVar13 + -1;
                  } while (iVar13 != 0);
                  iVar8 = iVar8 + 1;
                  iVar4 = iVar4 + 0x10;
                } while (iVar8 < 4);
                *(undefined4 *)(puVar5 + 4) = DAT_80370d70;
                *(undefined4 *)(puVar5 + 8) = DAT_80370d74;
                *(undefined4 *)(puVar5 + 0xc) = DAT_80370d78;
                *puVar5 = J3DGraphBase::j3dDefaultTexMtxInfo;
                puVar5[1] = DAT_80370d6d;
                *(undefined4 *)(puVar5 + 0x10) = DAT_80370d7c;
                *(undefined4 *)(puVar5 + 0x14) = DAT_80370d80;
                *(undefined2 *)(puVar5 + 0x18) = DAT_80370d84;
                *(undefined4 *)(puVar5 + 0x1c) = DAT_80370d88;
                *(undefined4 *)(puVar5 + 0x20) = DAT_80370d8c;
              }
              (*(code *)pJVar12->mpTexGenBlock->vtbl->setTexMtx)(pJVar12->mpTexGenBlock,bVar1);
            }
            iVar4 = (*(code *)pJVar12->mpTexGenBlock->vtbl->getTexCoord)
                              (pJVar12->mpTexGenBlock,bVar1);
            if (iVar4 != 0) {
              iVar4 = (*(code *)pJVar12->mpTexGenBlock->vtbl->getTexCoord)
                                (pJVar12->mpTexGenBlock,bVar1);
              *(byte *)(iVar4 + 2) = bVar1 * '\x03' + '\x1e';
            }
            iVar4 = (*(code *)pJVar12->mpTexGenBlock->vtbl->getTexMtx)(pJVar12->mpTexGenBlock,bVar1)
            ;
            pJVar6 = (J3DTexMtxAnm *)JKernel::operator_new(8);
            if (pJVar6 != (J3DTexMtxAnm *)0x0) {
              pJVar6->mMatIndex = uVar9;
              pJVar6->mpAnm = param_1;
            }
            *(byte *)(iVar4 + 1) =
                 *(byte *)(iVar4 + 1) & 0x7f | (byte)((int)param_1[1].parent.mCurrentTime << 7);
            iVar8 = (uint)uVar9 * 0xc;
            *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(*(int *)&param_1->field_0x48 + iVar8);
            *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(*(int *)&param_1->field_0x48 + iVar8 + 4);
            *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(*(int *)&param_1->field_0x48 + iVar8 + 8)
            ;
            pJVar11->mpTexMtxAnm[bVar1] = pJVar6;
          }
        }
      }
    }
  }
  return uVar10;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall J3DMaterialTable::entryTevRegAnimator(J3DAnmTevRegKey *) */

undefined4 __thiscall
J3DMaterialTable::entryTevRegAnimator(J3DMaterialTable *this,J3DAnmTevRegKey *param_1)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  J3DTevColorAnm *pJVar4;
  J3DTevKColorAnm *pJVar5;
  J3DMaterialAnm *pJVar6;
  ushort uVar7;
  ushort uVar8;
  undefined4 uVar9;
  
  uVar9 = 0;
  uVar8 = *(ushort *)(param_1 + 0x10);
  uVar2 = *(ushort *)(param_1 + 0x12);
  if (*(short *)&this[1].vtbl == 1) {
    uVar9 = 2;
  }
  else {
    for (uVar7 = 0; uVar7 < uVar8; uVar7 = uVar7 + 1) {
      uVar3 = (uint)*(ushort *)(*(int *)(param_1 + 0x24) + (uint)uVar7 * 2);
      if (uVar3 != 0xffff) {
        pJVar6 = this->mpMaterials[uVar3]->mpMaterialAnm;
        if ((J3DMaterialAnm *)0xbfffffff < pJVar6) {
          pJVar6 = (J3DMaterialAnm *)0x0;
        }
        bVar1 = *(byte *)(*(int *)(param_1 + 0x4c) + (uint)uVar7 * 0x1c + 0x18);
        if (pJVar6 == (J3DMaterialAnm *)0x0) {
          uVar9 = 1;
        }
        else {
          pJVar4 = (J3DTevColorAnm *)JKernel::operator_new(8);
          if (pJVar4 != (J3DTevColorAnm *)0x0) {
            pJVar4->mpAnm = param_1;
            pJVar4->mIdx = uVar7;
          }
          pJVar6->mpTevColorAnm[bVar1] = pJVar4;
        }
      }
    }
    for (uVar8 = 0; uVar8 < uVar2; uVar8 = uVar8 + 1) {
      uVar3 = (uint)*(ushort *)(*(int *)(param_1 + 0x38) + (uint)uVar8 * 2);
      if (uVar3 != 0xffff) {
        pJVar6 = this->mpMaterials[uVar3]->mpMaterialAnm;
        if ((J3DMaterialAnm *)0xbfffffff < pJVar6) {
          pJVar6 = (J3DMaterialAnm *)0x0;
        }
        bVar1 = *(byte *)(*(int *)(param_1 + 0x50) + (uint)uVar8 * 0x1c + 0x18);
        if (pJVar6 == (J3DMaterialAnm *)0x0) {
          uVar9 = 1;
        }
        else {
          pJVar5 = (J3DTevKColorAnm *)JKernel::operator_new(8);
          if (pJVar5 != (J3DTevKColorAnm *)0x0) {
            pJVar5->mpAnm = param_1;
            pJVar5->mIdx = uVar8;
          }
          pJVar6->mpTevKColorAnm[bVar1] = pJVar5;
        }
      }
    }
  }
  return uVar9;
}


/* __thiscall J3DMaterialTable::removeMatColorAnimator(J3DAnmColor *) */

undefined4 __thiscall
J3DMaterialTable::removeMatColorAnimator(J3DMaterialTable *this,J3DAnmColor *param_1)

{
  ushort uVar1;
  uint uVar2;
  J3DMaterialAnm *pJVar3;
  undefined4 uVar4;
  ushort uVar5;
  
  uVar4 = 0;
  uVar1 = *(ushort *)(param_1 + 0x18);
  for (uVar5 = 0; uVar5 < uVar1; uVar5 = uVar5 + 1) {
    uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x1c) + (uint)uVar5 * 2);
    if (uVar2 != 0xffff) {
      pJVar3 = this->mpMaterials[uVar2]->mpMaterialAnm;
      if ((J3DMaterialAnm *)0xbfffffff < pJVar3) {
        pJVar3 = (J3DMaterialAnm *)0x0;
      }
      if (pJVar3 == (J3DMaterialAnm *)0x0) {
        uVar4 = 1;
      }
      else {
        pJVar3->mpMatColorAnm[0] = (J3DMatColorAnm *)0x0;
      }
    }
  }
  return uVar4;
}


/* __thiscall J3DMaterialTable::removeTexNoAnimator(J3DAnmTexPattern *) */

undefined4 __thiscall
J3DMaterialTable::removeTexNoAnimator(J3DMaterialTable *this,J3DAnmTexPattern *param_1)

{
  ushort uVar1;
  uint uVar2;
  J3DMaterialAnm *pJVar3;
  undefined4 uVar4;
  ushort uVar5;
  
  uVar4 = 0;
  uVar1 = *(ushort *)&param_1[1].field_0x2;
  for (uVar5 = 0; uVar5 < uVar1; uVar5 = uVar5 + 1) {
    uVar2 = (uint)*(ushort *)(*(int *)&param_1[1].field_0x4 + (uint)uVar5 * 2);
    if (uVar2 != 0xffff) {
      pJVar3 = this->mpMaterials[uVar2]->mpMaterialAnm;
      if ((J3DMaterialAnm *)0xbfffffff < pJVar3) {
        pJVar3 = (J3DMaterialAnm *)0x0;
      }
      if (pJVar3 == (J3DMaterialAnm *)0x0) {
        uVar4 = 1;
      }
      else {
        pJVar3->mpTexNoAnm[*(byte *)(param_1->field_0x14 + (uint)uVar5 * 8 + 4)] =
             (J3DTexNoAnm *)0x0;
      }
    }
  }
  return uVar4;
}


/* __thiscall J3DMaterialTable::removeTexMtxAnimator(J3DAnmTextureSRTKey *) */

undefined4 __thiscall
J3DMaterialTable::removeTexMtxAnimator(J3DMaterialTable *this,J3DAnmTextureSRTKey *param_1)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  J3DMaterialAnm *pJVar4;
  undefined4 uVar5;
  uint uVar6;
  
  uVar5 = 0;
  uVar2 = param_1->mTrackCount;
  for (uVar6 = 0; (uVar6 & 0xffff) < uVar2 / 3; uVar6 = uVar6 + 1) {
    uVar3 = (uint)(ushort)((param_1->mMaterialNameTable).mpRes)->mEntries[(uVar6 & 0xffff) - 2];
    if (uVar3 != 0xffff) {
      pJVar4 = this->mpMaterials[uVar3]->mpMaterialAnm;
      if ((J3DMaterialAnm *)0xbfffffff < pJVar4) {
        pJVar4 = (J3DMaterialAnm *)0x0;
      }
      bVar1 = (param_1->mMaterialNameTable).vtbl[uVar6 & 0xffff];
      if (pJVar4 == (J3DMaterialAnm *)0x0) {
        uVar5 = 1;
      }
      else {
        if (bVar1 != 0xff) {
          pJVar4->mpTexMtxAnm[bVar1] = (J3DTexMtxAnm *)0x0;
        }
      }
    }
  }
  return uVar5;
}


/* __thiscall J3DMaterialTable::removeTevRegAnimator(J3DAnmTevRegKey *) */

undefined4 __thiscall
J3DMaterialTable::removeTevRegAnimator(J3DMaterialTable *this,J3DAnmTevRegKey *param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  J3DMaterialAnm *pJVar4;
  ushort uVar5;
  ushort uVar6;
  
  uVar2 = 0;
  uVar5 = *(ushort *)(param_1 + 0x10);
  uVar1 = *(ushort *)(param_1 + 0x12);
  for (uVar6 = 0; uVar6 < uVar5; uVar6 = uVar6 + 1) {
    uVar3 = (uint)*(ushort *)(*(int *)(param_1 + 0x24) + (uint)uVar6 * 2);
    if (uVar3 != 0xffff) {
      pJVar4 = this->mpMaterials[uVar3]->mpMaterialAnm;
      if ((J3DMaterialAnm *)0xbfffffff < pJVar4) {
        pJVar4 = (J3DMaterialAnm *)0x0;
      }
      if (pJVar4 == (J3DMaterialAnm *)0x0) {
        uVar2 = 1;
      }
      else {
        pJVar4->mpTevColorAnm[*(byte *)(*(int *)(param_1 + 0x4c) + (uint)uVar6 * 0x1c + 0x18)] =
             (J3DTevColorAnm *)0x0;
      }
    }
  }
  for (uVar5 = 0; uVar5 < uVar1; uVar5 = uVar5 + 1) {
    uVar3 = (uint)*(ushort *)(*(int *)(param_1 + 0x38) + (uint)uVar5 * 2);
    if (uVar3 != 0xffff) {
      pJVar4 = this->mpMaterials[uVar3]->mpMaterialAnm;
      if ((J3DMaterialAnm *)0xbfffffff < pJVar4) {
        pJVar4 = (J3DMaterialAnm *)0x0;
      }
      if (pJVar4 == (J3DMaterialAnm *)0x0) {
        uVar2 = 1;
      }
      else {
        pJVar4->mpTevKColorAnm[*(byte *)(*(int *)(param_1 + 0x50) + (uint)uVar5 * 0x1c + 0x18)] =
             (J3DTevKColorAnm *)0x0;
      }
    }
  }
  return uVar2;
}


/* __thiscall J3DMaterialTable::setMatColorAnimator(J3DAnmColor *,
                                                    J3DMatColorAnm *) */

undefined4 __thiscall
J3DMaterialTable::setMatColorAnimator
          (J3DMaterialTable *this,J3DAnmColor *param_1,J3DMatColorAnm *param_2)

{
  ushort uVar1;
  uint uVar2;
  J3DMaterialAnm *pJVar3;
  undefined4 uVar4;
  ushort uVar5;
  
  uVar4 = 0;
  uVar1 = *(ushort *)(param_1 + 0x18);
  if (*(short *)&this[1].vtbl != 1) {
    for (uVar5 = 0; uVar5 < uVar1; uVar5 = uVar5 + 1) {
      uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x1c) + (uint)uVar5 * 2);
      if (uVar2 != 0xffff) {
        pJVar3 = this->mpMaterials[uVar2]->mpMaterialAnm;
        if ((J3DMaterialAnm *)0xbfffffff < pJVar3) {
          pJVar3 = (J3DMaterialAnm *)0x0;
        }
        if (pJVar3 == (J3DMaterialAnm *)0x0) {
          uVar4 = 1;
        }
        else {
          pJVar3->mpMatColorAnm[0] = param_2 + (uint)uVar5 * 8;
        }
      }
    }
    return uVar4;
  }
  return 2;
}


/* __thiscall J3DMaterialTable::setTexNoAnimator(J3DAnmTexPattern *,
                                                 J3DTexNoAnm *) */

undefined4 __thiscall
J3DMaterialTable::setTexNoAnimator
          (J3DMaterialTable *this,J3DAnmTexPattern *param_1,J3DTexNoAnm *param_2)

{
  ushort uVar1;
  uint uVar2;
  J3DMaterialAnm *pJVar3;
  undefined4 uVar4;
  ushort uVar5;
  
  uVar4 = 0;
  uVar1 = *(ushort *)&param_1[1].field_0x2;
  if (*(short *)&this[1].vtbl != 1) {
    for (uVar5 = 0; uVar5 < uVar1; uVar5 = uVar5 + 1) {
      uVar2 = (uint)*(ushort *)(*(int *)&param_1[1].field_0x4 + (uint)uVar5 * 2);
      if (uVar2 != 0xffff) {
        pJVar3 = this->mpMaterials[uVar2]->mpMaterialAnm;
        if ((J3DMaterialAnm *)0xbfffffff < pJVar3) {
          pJVar3 = (J3DMaterialAnm *)0x0;
        }
        if (pJVar3 == (J3DMaterialAnm *)0x0) {
          uVar4 = 1;
        }
        else {
          pJVar3->mpTexNoAnm[*(byte *)(param_1->field_0x14 + (uint)uVar5 * 8 + 4)] = param_2 + uVar5
          ;
        }
      }
    }
    return uVar4;
  }
  return 2;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* __thiscall J3DMaterialTable::setTexMtxAnimator(J3DAnmTextureSRTKey *,
                                                  J3DTexMtxAnm *,
                                                  J3DTexMtxAnm *) */

undefined4 __thiscall
J3DMaterialTable::setTexMtxAnimator
          (J3DMaterialTable *this,J3DAnmTextureSRTKey *param_1,J3DTexMtxAnm *param_2,
          J3DTexMtxAnm *param_3)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  J3DMaterial *pJVar7;
  uint uVar8;
  undefined4 uVar9;
  J3DMaterialAnm *pJVar10;
  
  uVar9 = 0;
  uVar2 = param_1->mTrackCount;
  if (*(short *)&this[1].vtbl == 1) {
    uVar9 = 2;
  }
  else {
    for (uVar8 = 0; (uVar8 & 0xffff) < uVar2 / 3; uVar8 = uVar8 + 1) {
      uVar3 = uVar8 & 0xffff;
      uVar4 = (uint)(ushort)((param_1->mMaterialNameTable).mpRes)->mEntries[(uVar8 & 0xffff) - 2];
      if (uVar4 != 0xffff) {
        pJVar7 = this->mpMaterials[uVar4];
        pJVar10 = pJVar7->mpMaterialAnm;
        if ((J3DMaterialAnm *)0xbfffffff < pJVar10) {
          pJVar10 = (J3DMaterialAnm *)0x0;
        }
        bVar1 = (param_1->mMaterialNameTable).vtbl[uVar3];
        if (pJVar10 == (J3DMaterialAnm *)0x0) {
          uVar9 = 1;
        }
        else {
          if (bVar1 != 0xff) {
            iVar5 = (*(code *)pJVar7->mpTexGenBlock->vtbl->getTexCoord)(pJVar7->mpTexGenBlock,bVar1)
            ;
            if (iVar5 != 0) {
              iVar5 = (*(code *)pJVar7->mpTexGenBlock->vtbl->getTexCoord)
                                (pJVar7->mpTexGenBlock,bVar1);
              *(byte *)(iVar5 + 2) = bVar1 * '\x03' + '\x1e';
            }
            iVar5 = (*(code *)pJVar7->mpTexGenBlock->vtbl->getTexMtx)(pJVar7->mpTexGenBlock,bVar1);
            *(byte *)(iVar5 + 1) =
                 *(byte *)(iVar5 + 1) & 0x7f | (byte)((int)param_1[1].parent.mCurrentTime << 7);
            iVar6 = uVar3 * 0xc;
            *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(*(int *)&param_1->field_0x48 + iVar6);
            *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(*(int *)&param_1->field_0x48 + iVar6 + 4);
            *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(*(int *)&param_1->field_0x48 + iVar6 + 8)
            ;
            pJVar10->mpTexMtxAnm[bVar1] = param_2 + uVar3;
          }
        }
      }
    }
  }
  return uVar9;
}


/* __thiscall J3DMaterialTable::setTevRegAnimator(J3DAnmTevRegKey *,
                                                  J3DTevColorAnm *,
                                                  J3DTevKColorAnm *) */

undefined4 __thiscall
J3DMaterialTable::setTevRegAnimator
          (J3DMaterialTable *this,J3DAnmTevRegKey *param_1,J3DTevColorAnm *param_2,
          J3DTevKColorAnm *param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  J3DMaterialAnm *pJVar4;
  ushort uVar5;
  ushort uVar6;
  
  uVar2 = 0;
  uVar5 = *(ushort *)(param_1 + 0x10);
  uVar1 = *(ushort *)(param_1 + 0x12);
  if (*(short *)&this[1].vtbl == 1) {
    uVar2 = 2;
  }
  else {
    for (uVar6 = 0; uVar6 < uVar5; uVar6 = uVar6 + 1) {
      uVar3 = (uint)*(ushort *)(*(int *)(param_1 + 0x24) + (uint)uVar6 * 2);
      if (uVar3 != 0xffff) {
        pJVar4 = this->mpMaterials[uVar3]->mpMaterialAnm;
        if ((J3DMaterialAnm *)0xbfffffff < pJVar4) {
          pJVar4 = (J3DMaterialAnm *)0x0;
        }
        if (pJVar4 == (J3DMaterialAnm *)0x0) {
          uVar2 = 1;
        }
        else {
          pJVar4->mpTevColorAnm[*(byte *)(*(int *)(param_1 + 0x4c) + (uint)uVar6 * 0x1c + 0x18)] =
               param_2 + uVar6;
        }
      }
    }
    for (uVar5 = 0; uVar5 < uVar1; uVar5 = uVar5 + 1) {
      uVar3 = (uint)*(ushort *)(*(int *)(param_1 + 0x38) + (uint)uVar5 * 2);
      if (uVar3 != 0xffff) {
        pJVar4 = this->mpMaterials[uVar3]->mpMaterialAnm;
        if ((J3DMaterialAnm *)0xbfffffff < pJVar4) {
          pJVar4 = (J3DMaterialAnm *)0x0;
        }
        if (pJVar4 == (J3DMaterialAnm *)0x0) {
          uVar2 = 1;
        }
        else {
          pJVar4->mpTevKColorAnm[*(byte *)(*(int *)(param_1 + 0x50) + (uint)uVar5 * 0x1c + 0x18)] =
               param_3 + uVar5;
        }
      }
    }
  }
  return uVar2;
}

