#include <J3DGraphLoader/J3DMaterialFactory.h>
#include <J3DGraphLoader/J3DMaterialFactory.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <J3DGraphBase/J3DMaterial.h>
#include <m_Do_ext.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <J3DGraphBase/J3DMatBlock.h>
#include <J3DGraphBase/J3DPacket.h>
#include <J3DTevStage.h>
#include <Demangler/J3DMaterial.h>
#include <J3DColorBlockNull.h>
#include <J3DTexGenBlockNull.h>
#include <J3DPEBlockNull.h>
#include <J3DMaterialFactory.h>
#include <J3DTevBlockNull.h>


/* __thiscall J3DMaterialFactory::J3DMaterialFactory(J3DMaterialBlock const &) */

void __thiscall
J3DMaterialFactory::J3DMaterialFactory(J3DMaterialFactory *this,J3DMaterialBlock *param_1)

{
  undefined *puVar1;
  
  *(undefined2 *)&this->field_0x0 = *(undefined2 *)(param_1 + 8);
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0xc));
  this->mpData = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x10));
  this->field_0x8 = puVar1;
  if ((*(int *)(param_1 + 0x18) == 0) ||
     ((uint)(*(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14)) < 5)) {
    this[1].field_0x0 = (undefined *)0x0;
  }
  else {
    puVar1 = (undefined *)J3DGraphLoader::JSUConvertOffsetToPtr(param_1);
    this[1].field_0x0 = puVar1;
  }
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x1c));
  this[5].field_0x0 = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x20));
  this[1].mpData = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x24));
  this[1].field_0x8 = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x28));
  this[2].field_0x0 = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x2c));
  this[2].mpData = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x30));
  this[2].field_0x8 = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x34));
  this[3].field_0x0 = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x38));
  this[3].mpData = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x3c));
  this[3].field_0x8 = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x40));
  this[4].field_0x0 = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x44));
  this[4].mpData = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x48));
  this[4].field_0x8 = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x4c));
  this[5].mpData = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x50));
  this[5].field_0x8 = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x54));
  this[6].field_0x0 = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x58));
  this[6].mpData = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x5c));
  this[6].field_0x8 = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x60));
  this[7].field_0x0 = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 100));
  this[7].mpData = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x68));
  this[7].field_0x8 = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x6c));
  this[8].field_0x0 = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x70));
  this[8].mpData = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x74));
  this[8].field_0x8 = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x78));
  this[9].field_0x0 = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x7c));
  this[9].mpData = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x80));
  this[9].field_0x8 = puVar1;
  this[10].field_0x0 = (undefined *)0x0;
  this[10].mpData = (undefined *)0x0;
  this[10].field_0x8 = (undefined *)0x0;
  this[0xb].field_0x0 = (undefined *)0x0;
  return;
}


/* __thiscall J3DMaterialFactory::J3DMaterialFactory(J3DMaterialDLBlock const &) */

void __thiscall
J3DMaterialFactory::J3DMaterialFactory(J3DMaterialFactory *this,J3DMaterialDLBlock *param_1)

{
  undefined *puVar1;
  
  *(undefined2 *)&this->field_0x0 = *(undefined2 *)(param_1 + 8);
  this->mpData = (undefined *)0x0;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0xc));
  this[10].field_0x0 = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x10));
  this[10].mpData = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x14));
  this[10].field_0x8 = puVar1;
  puVar1 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x18));
  this[0xb].field_0x0 = puVar1;
  return;
}


/* __thiscall J3DMaterialFactory::countUniqueMaterials(void) */

int __thiscall J3DMaterialFactory::countUniqueMaterials(J3DMaterialFactory *this)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  
  iVar1 = 0;
  uVar2 = 0xffffffff;
  for (uVar3 = 0; uVar3 < *(ushort *)&this->field_0x0; uVar3 = uVar3 + 1) {
    if ((int)uVar2 < (int)(uint)*(ushort *)(this->field_0x8 + (uint)uVar3 * 2)) {
      iVar1 = iVar1 + 1;
      uVar2 = (uint)*(ushort *)(this->field_0x8 + (uint)uVar3 * 2);
    }
  }
  return iVar1;
}


/* __thiscall J3DMaterialFactory::countTexGens(int) const */

undefined __thiscall J3DMaterialFactory::countTexGens(J3DMaterialFactory *this,int param_1)

{
  if ((byte)this->mpData[(uint)*(ushort *)(this->field_0x8 + param_1 * 2) * 0x14c + 3] != 0xff) {
    return this[3].field_0x0
           [(byte)this->mpData[(uint)*(ushort *)(this->field_0x8 + param_1 * 2) * 0x14c + 3]];
  }
  return 0;
}


/* __thiscall J3DMaterialFactory::countStages(int) const */

uint __thiscall J3DMaterialFactory::countStages(J3DMaterialFactory *this,int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = 0;
  uVar4 = 0;
  uVar1 = (uint)(byte)(this->mpData + (uint)*(ushort *)(this->field_0x8 + param_1 * 2) * 0x14c)[4];
  if (uVar1 != 0xff) {
    uVar4 = (uint)(byte)this[6].mpData[uVar1];
  }
  iVar2 = 0;
  iVar5 = 8;
  do {
    if (*(short *)(this->mpData + (uint)*(ushort *)(this->field_0x8 + param_1 * 2) * 0x14c +
                  iVar2 + 0x84) != -1) {
      uVar3 = uVar3 + 1;
    }
    iVar2 = iVar2 + 2;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if ((uVar4 != uVar3) && (uVar3 != 0)) {
    if (uVar4 <= uVar3) {
      return uVar3;
    }
    return uVar4;
  }
  return uVar4;
}


/* __thiscall J3DMaterialFactory::create(J3DMaterial *,
                                         J3DMaterialFactory::MaterialType,
                                         int,
                                         unsigned long) const */

J3DMaterial * __thiscall
J3DMaterialFactory::create
          (J3DMaterialFactory *this,J3DMaterial *param_1,MaterialType param_2,int param_3,
          ulong param_4)

{
  if (param_2 == 1) {
    param_1 = (J3DMaterial *)createLockedMaterial(this,param_1,param_3,param_4);
  }
  else {
    if ((int)param_2 < 1) {
      if (-1 < (int)param_2) {
        param_1 = (J3DMaterial *)createNormalMaterial(this,param_1,param_3,param_4);
      }
    }
    else {
      if ((int)param_2 < 3) {
        param_1 = (J3DMaterial *)createPatchedMaterial(this,param_1,param_3,param_4);
      }
    }
  }
  return param_1;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall J3DMaterialFactory::createNormalMaterial(J3DMaterial *,
                                                       int,
                                                       unsigned long) const */

J3DMaterial * __thiscall
J3DMaterialFactory::createNormalMaterial
          (J3DMaterialFactory *this,J3DMaterial *param_1,int param_2,ulong param_3)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  J3DColorBlockLightOn *pJVar8;
  undefined *puVar9;
  J3DPEBlockFull *pJVar10;
  undefined4 uVar11;
  int iVar12;
  byte bVar13;
  ulong uVar14;
  ulong extraout_r4;
  byte bVar15;
  int iVar16;
  uint uVar17;
  undefined8 uVar18;
  undefined local_e8;
  undefined local_e4 [4];
  undefined2 local_e0;
  undefined2 local_dc;
  undefined2 local_d8 [2];
  undefined2 local_d4 [2];
  undefined local_d0 [4];
  undefined *local_cc;
  undefined auStack200 [8];
  undefined *local_c0;
  undefined local_bc [4];
  undefined auStack184 [4];
  undefined auStack180 [4];
  undefined auStack176 [8];
  undefined *local_a8;
  undefined local_a4 [4];
  undefined *local_a0;
  undefined local_9c [4];
  undefined *local_98;
  undefined *local_94;
  undefined auStack144 [12];
  undefined4 local_84;
  undefined *local_80;
  undefined4 local_7c;
  J3DMaterialFactory local_78;
  undefined4 local_6c;
  undefined *local_68;
  undefined *local_64;
  undefined *local_60;
  undefined4 local_5c;
  J3DMaterialFactory aJStack88 [3];
  
  if (this[10].field_0x0 == (undefined *)0x0) {
    uVar6 = countStages(this,param_2);
    uVar17 = param_3 >> 0x10 & 0x1f;
    if (uVar17 < uVar6) {
      uVar17 = uVar6;
    }
    uVar6 = 8;
    if (uVar17 < 9) {
      uVar6 = uVar17;
    }
    uVar18 = countTexGens(this,param_2);
    uVar7 = (uint)((ulonglong)uVar18 >> 0x20);
    uVar14 = (ulong)uVar18;
    if ((param_1 == (J3DMaterial *)0x0) &&
       (param_1 = (J3DMaterial *)JKernel::operator_new(0x4c), param_1 != (J3DMaterial *)0x0)) {
      param_1->vtbl = (undefined *)&J3DMaterial::__vt;
      param_1->field_0x40 = (undefined *)0x3cf3cf00;
      param_1->field_0x44 = (undefined *)0xf3cf3c;
      J3DMaterial::initialize(param_1);
      uVar14 = extraout_r4;
    }
    pJVar8 = J3DMaterial::createColorBlock(param_3 & 0xc0000000);
    param_1->mpColorBlock = &pJVar8->parent;
    uVar18 = J3DMaterial::createTexGenBlock
                       ((J3DMaterial *)(param_3 & 0xc000000 & ~-(uint)(4 < uVar7)),uVar14);
    param_1->mpTexGenBlock = (J3DTexGenBlockPatched *)((ulonglong)uVar18 >> 0x20);
    uVar18 = J3DMaterial::createTevBlock((J3DMaterial *)(uVar17 & 0xffff),(int)uVar18);
    param_1->mpTevBlock = (J3DTevBlock *)((ulonglong)uVar18 >> 0x20);
    puVar9 = (undefined *)
             J3DMaterial::createIndBlock((J3DMaterial *)(param_3 >> 0x18 & 1),(int)uVar18);
    param_1->mpIndBlock = puVar9;
    iVar3 = param_2 * 2;
    pJVar10 = J3DMaterial::createPEBlock
                        (param_3 & 0x30000000,
                         (uint)(byte)this->mpData
                                     [(uint)*(ushort *)(this->field_0x8 + iVar3) * 0x14c]);
    param_1->mpPEBlock = pJVar10;
    param_1->mIdx = (short)param_2;
    param_1->mMaterialMode =
         (uint)(byte)this->mpData[(uint)*(ushort *)(this->field_0x8 + iVar3) * 0x14c];
    uVar11 = newColorChanNum(this,param_2);
    (*(code *)param_1->mpColorBlock->vtbl->setColorChanNum_0)(param_1->mpColorBlock,uVar11);
    uVar11 = newCullMode(this,param_2);
    (*(code *)param_1->mpColorBlock->vtbl->setCullMode_1)(param_1->mpColorBlock,uVar11);
    uVar11 = newTexGenNum(this,param_2);
    (*(code *)param_1->mpTexGenBlock->vtbl->setTexGenNum_1)(param_1->mpTexGenBlock,uVar11);
    newNBTScale(&local_78,(int)this);
    local_68 = local_78.field_0x0;
    local_64 = local_78.mpData;
    local_60 = local_78.field_0x8;
    local_5c = local_6c;
    (*(code *)param_1->mpTexGenBlock->vtbl->setNBTScale_1)(param_1->mpTexGenBlock,&local_68);
    uVar11 = newFog(this,param_2);
    (**(code **)(param_1->mpPEBlock->vtbl + 0x28))(param_1->mpPEBlock,uVar11);
    newAlphaComp((J3DMaterialFactory *)(local_a4 + 8),(int)this);
    local_98 = local_9c;
    (**(code **)(param_1->mpPEBlock->vtbl + 0x34))(param_1->mpPEBlock,local_9c + 4);
    newBlend((J3DMaterialFactory *)local_a4,(int)this);
    local_a0 = local_a4;
    (**(code **)(param_1->mpPEBlock->vtbl + 0x40))(param_1->mpPEBlock,local_a4 + 4);
    newZMode((J3DMaterialFactory *)&local_dc,(int)this);
    local_d8[0] = local_dc;
    (**(code **)(param_1->mpPEBlock->vtbl + 0x4c))(param_1->mpPEBlock,local_d8);
    uVar11 = newZCompLoc(this,param_2);
    (**(code **)(param_1->mpPEBlock->vtbl + 0x58))(param_1->mpPEBlock,uVar11);
    uVar11 = newDither(this,param_2);
    (**(code **)(param_1->mpPEBlock->vtbl + 100))(param_1->mpPEBlock,uVar11);
    uVar11 = newTevStageNum(this,param_2);
    (*(code *)param_1->mpTevBlock->vtbl->setTevStageNum_1)(param_1->mpTevBlock,uVar11);
    for (bVar13 = 0; bVar13 < uVar6; bVar13 = bVar13 + 1) {
      uVar11 = newTexNo(this,param_2,(uint)bVar13);
      (*(code *)param_1->mpTevBlock->vtbl->setTexNo_1)(param_1->mpTevBlock,bVar13,uVar11);
    }
    for (bVar13 = 0; bVar13 < uVar17; bVar13 = bVar13 + 1) {
      newTevOrder((J3DMaterialFactory *)(auStack176 + 4),(int)this,param_2);
      local_a8 = auStack176._4_4_;
      (*(code *)param_1->mpTevBlock->vtbl->setTevOrder_1)(param_1->mpTevBlock,bVar13,&local_a8);
    }
    for (uVar6 = 0; (uVar6 & 0xff) < uVar17; uVar6 = uVar6 + 1) {
      puVar9 = this->mpData;
      uVar2 = *(ushort *)(this->field_0x8 + iVar3);
      newTevStage((J3DMaterialFactory *)(auStack144 + 8),(int)this,param_2);
      local_80 = auStack144._8_4_;
      local_7c = local_84;
      uVar4 = uVar6 & 0xff;
      (*(code *)param_1->mpTevBlock->vtbl->setTevStage_1)(param_1->mpTevBlock,uVar4,&local_80);
      iVar16 = uVar4 * 2 + 0x104;
      uVar5 = (uint)*(ushort *)(puVar9 + (uint)uVar2 * 0x14c + iVar16);
      if (uVar5 != 0xffff) {
        cVar1 = this[7].field_0x0[uVar5 * 4 + 1];
        iVar12 = (*(code *)param_1->mpTevBlock->vtbl->getTevStage)(param_1->mpTevBlock,uVar4);
        *(byte *)(iVar12 + 7) = *(byte *)(iVar12 + 7) & 0xf3 | cVar1 << 2;
        bVar13 = this[7].field_0x0[(uint)*(ushort *)(puVar9 + (uint)uVar2 * 0x14c + iVar16) * 4];
        iVar16 = (*(code *)param_1->mpTevBlock->vtbl->getTevStage)(param_1->mpTevBlock,uVar4);
        *(byte *)(iVar16 + 7) = *(byte *)(iVar16 + 7) & 0xfc | bVar13;
      }
    }
    for (bVar13 = 0; bVar13 < 4; bVar13 = bVar13 + 1) {
      newTevKColor((J3DMaterialFactory *)auStack176,(int)this,param_2);
      (*(code *)param_1->mpTevBlock->vtbl->setTevKColor_1)(param_1->mpTevBlock,bVar13,auStack176);
    }
    for (bVar13 = 0; bVar13 < 4; bVar13 = bVar13 + 1) {
      newTevColor((J3DMaterialFactory *)auStack144,(int)this,param_2);
      (*(code *)param_1->mpTevBlock->vtbl->setTevColor_1)(param_1->mpTevBlock,bVar13,auStack144);
    }
    for (bVar13 = 0; bVar13 < 4; bVar13 = bVar13 + 1) {
      newTevSwapModeTable((J3DMaterialFactory *)&local_e8,(int)this,param_2);
      local_e4[0] = local_e8;
      (*(code *)param_1->mpTevBlock->vtbl->setTevSwapModeTable_1)
                (param_1->mpTevBlock,bVar13,local_e4);
    }
    for (bVar13 = 0; bVar13 < 2; bVar13 = bVar13 + 1) {
      newAmbColor((J3DMaterialFactory *)auStack180,(int)this,param_2);
      (*(code *)param_1->mpColorBlock->vtbl->setAmbColor_1)(param_1->mpColorBlock,bVar13,auStack180)
      ;
    }
    for (bVar13 = 0; bVar13 < 2; bVar13 = bVar13 + 1) {
      newMatColor((J3DMaterialFactory *)auStack184,(int)this,param_2);
      (*(code *)param_1->mpColorBlock->vtbl->setMatColor_1)(param_1->mpColorBlock,bVar13,auStack184)
      ;
    }
    for (bVar13 = 0; bVar13 < 4; bVar13 = bVar13 + 1) {
      newColorChan((J3DMaterialFactory *)&local_e0,(int)this,param_2);
      local_d4[0] = local_e0;
      (*(code *)param_1->mpColorBlock->vtbl->setColorChan_0)(param_1->mpColorBlock,bVar13,local_d4);
    }
    for (bVar13 = 0; bVar13 < uVar7; bVar13 = bVar13 + 1) {
      newTexCoord((J3DMaterialFactory *)local_bc,(int)this,param_2);
      local_94 = local_bc;
      (*(code *)param_1->mpTexGenBlock->vtbl->setTexCoord)
                (param_1->mpTexGenBlock,bVar13,local_9c + 8);
    }
    for (bVar13 = 0; bVar13 < 8; bVar13 = bVar13 + 1) {
      uVar11 = newTexMtx(this,param_2,(uint)bVar13);
      (*(code *)param_1->mpTexGenBlock->vtbl->setTexMtx)(param_1->mpTexGenBlock,bVar13,uVar11);
    }
    puVar9 = this->mpData;
    uVar2 = *(ushort *)(this->field_0x8 + iVar3);
    for (uVar6 = 0; (uVar6 & 0xff) < uVar17; uVar6 = uVar6 + 1) {
      if ((puVar9 + (uint)uVar2 * 0x14c)[(uVar6 & 0xff) + 0x9c] == -1) {
        (*(code *)param_1->mpTevBlock->vtbl->setTevKColorSel_1)
                  (param_1->mpTevBlock,uVar6 & 0xff,0xc);
      }
      else {
        (*(code *)param_1->mpTevBlock->vtbl->setTevKColorSel_1)();
      }
    }
    for (uVar6 = 0; (uVar6 & 0xff) < uVar17; uVar6 = uVar6 + 1) {
      if ((puVar9 + (uint)uVar2 * 0x14c)[(uVar6 & 0xff) + 0xac] == -1) {
        (*(code *)param_1->mpTevBlock->vtbl->setTevKAlphaSel_1)
                  (param_1->mpTevBlock,uVar6 & 0xff,0x1c);
      }
      else {
        (*(code *)param_1->mpTevBlock->vtbl->setTevKAlphaSel_1)();
      }
    }
    if (this[1].field_0x0 != (undefined *)0x0) {
      bVar13 = newIndTexStageNum(this,param_2);
      uVar11 = newIndTexStageNum(this,param_2);
      (**(code **)(*(int *)param_1->mpIndBlock + 0x1c))(param_1->mpIndBlock,uVar11);
      for (bVar15 = 0; bVar15 < bVar13; bVar15 = bVar15 + 1) {
        newIndTexMtx(aJStack88,(int)this,param_2);
        (**(code **)(*(int *)param_1->mpIndBlock + 0x34))(param_1->mpIndBlock,bVar15,aJStack88);
      }
      for (bVar15 = 0; bVar15 < bVar13; bVar15 = bVar15 + 1) {
        newIndTexOrder((J3DMaterialFactory *)(auStack200 + 4),(int)this,param_2);
        local_c0 = auStack200._4_4_;
        (**(code **)(*(int *)param_1->mpIndBlock + 0x24))(param_1->mpIndBlock,bVar15,&local_c0);
      }
      for (bVar15 = 0; bVar15 < bVar13; bVar15 = bVar15 + 1) {
        newIndTexCoordScale((J3DMaterialFactory *)auStack200,(int)this,param_2);
        (**(code **)(*(int *)param_1->mpIndBlock + 0x40))(param_1->mpIndBlock,bVar15,auStack200);
      }
      for (bVar13 = 0; bVar13 < uVar17; bVar13 = bVar13 + 1) {
        newIndTevStage((J3DMaterialFactory *)local_d0,(int)this,param_2);
        local_cc = local_d0;
        (*(code *)param_1->mpTevBlock->vtbl->setIndTevStage_1)
                  (param_1->mpTevBlock,bVar13,local_d0 + 4);
      }
    }
  }
  else {
    param_1 = (J3DMaterial *)createLockedMaterial(this,param_1,param_2,param_3);
  }
  return param_1;
}


/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall J3DMaterialFactory::createPatchedMaterial(J3DMaterial *,
                                                        int,
                                                        unsigned long) const */

J3DMaterial * __thiscall
J3DMaterialFactory::createPatchedMaterial
          (J3DMaterialFactory *this,J3DMaterial *param_1,int param_2,ulong param_3)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  J3DMaterial *this_00;
  J3DColorBlockLightOn *pJVar5;
  J3DTexGenBlockPatched *this_01;
  J3DTevBlockPatched *this_02;
  undefined *puVar6;
  J3DPEBlockFull *pJVar7;
  undefined4 uVar8;
  byte bVar11;
  int iVar9;
  uint uVar10;
  byte bVar12;
  J3DMaterial *extraout_r4;
  J3DMaterial *extraout_r4_00;
  J3DMaterial *extraout_r4_01;
  byte bVar13;
  int iVar14;
  bool bVar15;
  undefined2 local_b8;
  undefined2 local_b4;
  undefined2 local_b0 [2];
  undefined2 local_ac [2];
  undefined local_a8 [4];
  undefined *local_a4;
  undefined auStack160 [8];
  undefined *local_98;
  undefined local_94 [4];
  undefined auStack144 [4];
  undefined auStack140 [8];
  undefined *local_84;
  undefined local_80 [4];
  undefined *local_7c;
  undefined local_78 [4];
  undefined *local_74;
  undefined *local_70;
  undefined local_6c [8];
  undefined *local_64;
  undefined *local_60;
  undefined auStack92 [8];
  J3DMaterialFactory aJStack84 [3];
  
  this_00 = param_1;
  if ((param_1 == (J3DMaterial *)0x0) &&
     (this_00 = (J3DMaterial *)JKernel::operator_new(0x4c), this_00 != (J3DMaterial *)0x0)) {
    this_00->vtbl = (undefined *)&J3DMaterial::__vt;
    this_00->field_0x40 = (undefined *)0x3cf3cf00;
    this_00->field_0x44 = (undefined *)0xf3cf3c;
    J3DMaterial::initialize(this_00);
    this_00->vtbl = &J3DPatchedMaterial::__vt;
    J3DPatchedMaterial::initialize((J3DPatchedMaterial *)this_00);
    param_1 = extraout_r4;
  }
  bVar15 = (param_3 & 0x3000000) != 0;
  pJVar5 = J3DMaterial::createColorBlock(0x40000000);
  this_00->mpColorBlock = &pJVar5->parent;
  this_01 = (J3DTexGenBlockPatched *)JKernel::operator_new(0x4c);
  if (this_01 != (J3DTexGenBlockPatched *)0x0) {
    this_01->vtbl = (J3DTexGenBlock__vtbl *)&J3DTexGenBlock::__vt;
    this_01->vtbl = (J3DTexGenBlock__vtbl *)&J3DTexGenBlockPatched::__vt;
    Runtime.PPCEABI.H::__construct_array(this_01 + 1,J3DTexCoord::J3DTexCoord,(undefined *)0x0,4,8);
    J3DTexGenBlockPatched::initialize(this_01);
    param_1 = extraout_r4_00;
  }
  this_00->mpTexGenBlock = this_01;
  this_02 = (J3DTevBlockPatched *)JKernel::operator_new(0xd8);
  if (this_02 != (J3DTevBlockPatched *)0x0) {
    *(undefined ***)this_02 = &J3DTevBlock::__vt;
    *(undefined ***)this_02 = &J3DTevBlockPatched::__vt;
    Runtime.PPCEABI.H::__construct_array
              (this_02->mTevOrder,J3DTevOrder::J3DTevOrder,(undefined *)0x0,4,8);
    Runtime.PPCEABI.H::__construct_array
              (this_02->mTevStages,J3DTevStage::J3DTevStage,(undefined *)0x0,8,8);
    Runtime.PPCEABI.H::__construct_array
              (this_02->mIndStages,J3DIndTevStage::J3DIndTevStage,(undefined *)0x0,4,8);
    Runtime.PPCEABI.H::__construct_array
              (this_02->mTevColor,J3DGXColorS10::J3DGXColorS10,(undefined *)0x0,8,4);
    Runtime.PPCEABI.H::__construct_array
              (this_02->mTevKColor,J3DGXColor::J3DGXColor,(undefined *)0x0,4,4);
    J3DTevBlockPatched::initialize(this_02);
    param_1 = extraout_r4_01;
  }
  this_00->mpTevBlock = (J3DTevBlock *)this_02;
  puVar6 = (undefined *)J3DMaterial::createIndBlock((J3DMaterial *)(uint)bVar15,(int)param_1);
  this_00->mpIndBlock = puVar6;
  iVar3 = param_2 * 2;
  pJVar7 = J3DMaterial::createPEBlock
                     (0x10000000,
                      (uint)(byte)this->mpData[(uint)*(ushort *)(this->field_0x8 + iVar3) * 0x14c]);
  this_00->mpPEBlock = pJVar7;
  this_00->mIdx = (short)param_2;
  this_00->mMaterialMode =
       (uint)(byte)this->mpData[(uint)*(ushort *)(this->field_0x8 + iVar3) * 0x14c];
  uVar8 = newTevStageNum(this,param_2);
  (*(code *)this_00->mpTevBlock->vtbl->setTevStageNum_1)(this_00->mpTevBlock,uVar8);
  uVar8 = newColorChanNum(this,param_2);
  (*(code *)this_00->mpColorBlock->vtbl->setColorChanNum_0)(this_00->mpColorBlock,uVar8);
  uVar8 = newCullMode(this,param_2);
  (*(code *)this_00->mpColorBlock->vtbl->setCullMode_1)(this_00->mpColorBlock,uVar8);
  uVar8 = newFog(this,param_2);
  (**(code **)(this_00->mpPEBlock->vtbl + 0x28))(this_00->mpPEBlock,uVar8);
  newAlphaComp((J3DMaterialFactory *)(local_80 + 8),(int)this);
  local_74 = local_78;
  (**(code **)(this_00->mpPEBlock->vtbl + 0x34))(this_00->mpPEBlock,local_78 + 4);
  newBlend((J3DMaterialFactory *)local_80,(int)this);
  local_7c = local_80;
  (**(code **)(this_00->mpPEBlock->vtbl + 0x40))(this_00->mpPEBlock,local_80 + 4);
  newZMode((J3DMaterialFactory *)&local_b4,(int)this);
  local_b0[0] = local_b4;
  (**(code **)(this_00->mpPEBlock->vtbl + 0x4c))(this_00->mpPEBlock,local_b0);
  uVar8 = newZCompLoc(this,param_2);
  (**(code **)(this_00->mpPEBlock->vtbl + 0x58))(this_00->mpPEBlock,uVar8);
  uVar8 = newDither(this,param_2);
  (**(code **)(this_00->mpPEBlock->vtbl + 100))(this_00->mpPEBlock,uVar8);
  bVar11 = (*(code *)this_00->mpTevBlock->vtbl->getTevStageNum)();
  for (bVar12 = 0; bVar12 < 8; bVar12 = bVar12 + 1) {
    uVar8 = newTexNo(this,param_2,(uint)bVar12);
    (*(code *)this_00->mpTevBlock->vtbl->setTexNo_1)(this_00->mpTevBlock,bVar12,uVar8);
  }
  for (bVar12 = 0; bVar12 < bVar11; bVar12 = bVar12 + 1) {
    newTevOrder((J3DMaterialFactory *)(auStack140 + 4),(int)this,param_2);
    local_84 = auStack140._4_4_;
    (*(code *)this_00->mpTevBlock->vtbl->setTevOrder_1)(this_00->mpTevBlock,bVar12,&local_84);
  }
  for (bVar12 = 0; bVar12 < 4; bVar12 = bVar12 + 1) {
    newTevKColor((J3DMaterialFactory *)auStack140,(int)this,param_2);
    (*(code *)this_00->mpTevBlock->vtbl->setTevKColor_1)(this_00->mpTevBlock,bVar12,auStack140);
  }
  for (bVar12 = 0; bVar12 < 4; bVar12 = bVar12 + 1) {
    newTevColor((J3DMaterialFactory *)auStack92,(int)this,param_2);
    (*(code *)this_00->mpTevBlock->vtbl->setTevColor_1)(this_00->mpTevBlock,bVar12,auStack92);
  }
  for (bVar12 = 0; bVar12 < bVar11; bVar12 = bVar12 + 1) {
    puVar6 = this->mpData;
    uVar2 = *(ushort *)(this->field_0x8 + iVar3);
    newTevStage((J3DMaterialFactory *)local_6c,(int)this,param_2);
    local_64 = local_6c._0_4_;
    local_60 = local_6c._4_4_;
    uVar10 = (uint)bVar12;
    (*(code *)this_00->mpTevBlock->vtbl->setTevStage_1)(this_00->mpTevBlock,uVar10,local_6c + 8);
    iVar14 = uVar10 * 2 + 0x104;
    uVar4 = (uint)*(ushort *)(puVar6 + (uint)uVar2 * 0x14c + iVar14);
    if (uVar4 != 0xffff) {
      cVar1 = this[7].field_0x0[uVar4 * 4 + 1];
      iVar9 = (*(code *)this_00->mpTevBlock->vtbl->getTevStage)(this_00->mpTevBlock,uVar10);
      *(byte *)(iVar9 + 7) = *(byte *)(iVar9 + 7) & 0xf3 | cVar1 << 2;
      bVar13 = this[7].field_0x0[(uint)*(ushort *)(puVar6 + (uint)uVar2 * 0x14c + iVar14) * 4];
      iVar14 = (*(code *)this_00->mpTevBlock->vtbl->getTevStage)(this_00->mpTevBlock,uVar10);
      *(byte *)(iVar14 + 7) = *(byte *)(iVar14 + 7) & 0xfc | bVar13;
    }
  }
  puVar6 = this->mpData;
  uVar2 = *(ushort *)(this->field_0x8 + iVar3);
  for (bVar12 = 0; bVar12 < bVar11; bVar12 = bVar12 + 1) {
    if (puVar6[bVar12 + 0x9c + (uint)uVar2 * 0x14c] == -1) {
      (*(code *)this_00->mpTevBlock->vtbl->setTevKColorSel_1)(this_00->mpTevBlock,(uint)bVar12,0xc);
    }
    else {
      (*(code *)this_00->mpTevBlock->vtbl->setTevKColorSel_1)();
    }
  }
  for (bVar12 = 0; bVar12 < 2; bVar12 = bVar12 + 1) {
    newMatColor((J3DMaterialFactory *)auStack144,(int)this,param_2);
    (*(code *)this_00->mpColorBlock->vtbl->setMatColor_1)(this_00->mpColorBlock,bVar12,auStack144);
  }
  for (bVar12 = 0; bVar12 < 4; bVar12 = bVar12 + 1) {
    newColorChan((J3DMaterialFactory *)&local_b8,(int)this,param_2);
    local_ac[0] = local_b8;
    (*(code *)this_00->mpColorBlock->vtbl->setColorChan_0)(this_00->mpColorBlock,bVar12,local_ac);
  }
  uVar10 = countTexGens(this,param_2);
  uVar8 = newTexGenNum(this,param_2);
  (*(code *)this_00->mpTexGenBlock->vtbl->setTexGenNum_1)(this_00->mpTexGenBlock,uVar8);
  for (bVar12 = 0; bVar12 < 8; bVar12 = bVar12 + 1) {
    uVar8 = newTexMtx(this,param_2,(uint)bVar12);
    (*(code *)this_00->mpTexGenBlock->vtbl->setTexMtx)(this_00->mpTexGenBlock,bVar12,uVar8);
  }
  for (bVar12 = 0; bVar12 < uVar10; bVar12 = bVar12 + 1) {
    newTexCoord((J3DMaterialFactory *)local_94,(int)this,param_2);
    local_70 = local_94;
    (*(code *)this_00->mpTexGenBlock->vtbl->setTexCoord)(this_00->mpTexGenBlock,bVar12,local_78 + 8)
    ;
  }
  if ((bVar15) && (this[1].field_0x0 != (undefined *)0x0)) {
    bVar12 = newIndTexStageNum(this,param_2);
    uVar8 = newIndTexStageNum(this,param_2);
    (**(code **)(*(int *)this_00->mpIndBlock + 0x1c))(this_00->mpIndBlock,uVar8);
    for (bVar13 = 0; bVar13 < bVar12; bVar13 = bVar13 + 1) {
      newIndTexMtx((J3DMaterialFactory *)(auStack92 + 8),(int)this,param_2);
      (**(code **)(*(int *)this_00->mpIndBlock + 0x34))(this_00->mpIndBlock,bVar13,auStack92 + 8);
    }
    for (bVar13 = 0; bVar13 < bVar12; bVar13 = bVar13 + 1) {
      newIndTexOrder((J3DMaterialFactory *)(auStack160 + 4),(int)this,param_2);
      local_98 = auStack160._4_4_;
      (**(code **)(*(int *)this_00->mpIndBlock + 0x24))(this_00->mpIndBlock,bVar13,&local_98);
    }
    for (bVar13 = 0; bVar13 < bVar12; bVar13 = bVar13 + 1) {
      newIndTexCoordScale((J3DMaterialFactory *)auStack160,(int)this,param_2);
      (**(code **)(*(int *)this_00->mpIndBlock + 0x40))(this_00->mpIndBlock,bVar13,auStack160);
    }
    for (bVar12 = 0; bVar12 < bVar11; bVar12 = bVar12 + 1) {
      newIndTevStage((J3DMaterialFactory *)local_a8,(int)this,param_2);
      local_a4 = local_a8;
      (*(code *)this_00->mpTevBlock->vtbl->setIndTevStage_1)
                (this_00->mpTevBlock,bVar12,local_a8 + 4);
    }
  }
  return this_00;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DMaterialFactory::modifyPatchedCurrentMtx(J3DMaterial *,
                                                          int) const */

void __thiscall
J3DMaterialFactory::modifyPatchedCurrentMtx
          (J3DMaterialFactory *this,J3DMaterial *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte local_48;
  byte local_47;
  byte local_46;
  byte local_44 [6];
  byte local_3e;
  byte local_3c;
  undefined local_3b;
  byte local_3a;
  byte local_38;
  undefined local_37;
  byte local_36;
  byte local_34;
  undefined local_33;
  byte local_32;
  byte local_30;
  undefined local_2f;
  byte local_2e;
  byte local_2c;
  undefined local_2b;
  byte local_2a;
  byte local_28;
  undefined local_27;
  byte local_26;
  
  local_44[0] = J3DGraphBase::j3dDefaultTexCoordInfo;
  local_44[1] = DAT_80370d4d;
  local_44[2] = DAT_80370d4e;
  local_44[4] = J3DGraphBase::j3dDefaultTexCoordInfo;
  local_44[5] = DAT_80370d4d;
  local_3e = DAT_80370d4e;
  local_3c = J3DGraphBase::j3dDefaultTexCoordInfo;
  local_3b = DAT_80370d4d;
  local_3a = DAT_80370d4e;
  local_38 = J3DGraphBase::j3dDefaultTexCoordInfo;
  local_37 = DAT_80370d4d;
  local_36 = DAT_80370d4e;
  local_34 = J3DGraphBase::j3dDefaultTexCoordInfo;
  local_33 = DAT_80370d4d;
  local_32 = DAT_80370d4e;
  local_30 = J3DGraphBase::j3dDefaultTexCoordInfo;
  local_2f = DAT_80370d4d;
  local_2e = DAT_80370d4e;
  local_2c = J3DGraphBase::j3dDefaultTexCoordInfo;
  local_2b = DAT_80370d4d;
  local_2a = DAT_80370d4e;
  local_28 = J3DGraphBase::j3dDefaultTexCoordInfo;
  local_27 = DAT_80370d4d;
  local_26 = DAT_80370d4e;
  uVar2 = countTexGens(this,param_2);
  for (uVar3 = 0; (uVar3 & 0xff) < uVar2; uVar3 = uVar3 + 1) {
    newTexCoord((J3DMaterialFactory *)&local_48,(int)this,param_2);
    iVar1 = (uVar3 & 0xff) * 4;
    local_44[iVar1] = local_48;
    local_44[iVar1 + 1] = local_47;
    local_44[iVar1 + 2] = local_46;
  }
  param_1->field_0x40 =
       (undefined *)
       ((uint)local_36 << 0x18 |
       (uint)local_3a << 0x12 | (uint)local_44[2] << 6 | (uint)local_3e << 0xc);
  param_1->field_0x44 =
       (undefined *)
       ((uint)local_26 << 0x12 | (uint)local_2a << 0xc | (uint)local_32 | (uint)local_2e << 6);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DMaterialFactory::createLockedMaterial(J3DMaterial *,
                                                       int,
                                                       unsigned long) const */

J3DMaterial * __thiscall
J3DMaterialFactory::createLockedMaterial
          (J3DMaterialFactory *this,J3DMaterial *param_1,int param_2,ulong param_3)

{
  int iVar1;
  undefined *puVar2;
  J3DColorBlock *pJVar3;
  J3DTexGenBlockPatched *pJVar4;
  J3DTevBlock *this_00;
  undefined4 *puVar5;
  J3DPEBlockFull *pJVar6;
  J3DDisplayListObj *pJVar7;
  int *piVar8;
  
  if (param_1 == (J3DMaterial *)0x0) {
    param_1 = (J3DMaterial *)JKernel::operator_new(0x4c);
    if (param_1 != (J3DMaterial *)0x0) {
      param_1->vtbl = (undefined *)&J3DMaterial::__vt;
      param_1->field_0x40 = (undefined *)0x3cf3cf00;
      param_1->field_0x44 = (undefined *)0xf3cf3c;
      J3DMaterial::initialize(param_1);
      param_1->vtbl = &J3DLockedMaterial::__vt;
      J3DLockedMaterial::initialize((J3DLockedMaterial *)param_1);
    }
    pJVar3 = (J3DColorBlock *)JKernel::operator_new(4);
    if (pJVar3 != (J3DColorBlock *)0x0) {
      pJVar3->vtbl = (J3DColorBlock__vtbl *)&J3DColorBlock::__vt;
      pJVar3->vtbl = (J3DColorBlock__vtbl *)&J3DColorBlockNull::__vt;
    }
    param_1->mpColorBlock = pJVar3;
    pJVar4 = (J3DTexGenBlockPatched *)JKernel::operator_new(4);
    if (pJVar4 != (J3DTexGenBlockPatched *)0x0) {
      pJVar4->vtbl = (J3DTexGenBlock__vtbl *)&J3DTexGenBlock::__vt;
      pJVar4->vtbl = (J3DTexGenBlock__vtbl *)&J3DTexGenBlockNull::__vt;
    }
    param_1->mpTexGenBlock = pJVar4;
    this_00 = (J3DTevBlock *)JKernel::operator_new(8);
    if (this_00 != (J3DTevBlock *)0x0) {
      this_00->vtbl = (J3DTevBlock__vtbl *)&J3DTevBlock::__vt;
      this_00->vtbl = (J3DTevBlock__vtbl *)&J3DTevBlockNull::__vt;
      J3DTevBlockNull::initialize((J3DTevBlockNull *)this_00);
    }
    param_1->mpTevBlock = this_00;
    puVar5 = (undefined4 *)JKernel::operator_new(4);
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = &J3DIndBlock::__vt;
      *puVar5 = &J3DIndBlockNull::__vt;
    }
    param_1->mpIndBlock = (undefined *)puVar5;
    pJVar6 = (J3DPEBlockFull *)JKernel::operator_new(4);
    if (pJVar6 != (J3DPEBlockFull *)0x0) {
      pJVar6->vtbl = &J3DPEBlock::__vt;
      pJVar6->vtbl = &J3DPEBlockNull::__vt;
    }
    param_1->mpPEBlock = pJVar6;
    param_1->mIdx = (short)param_2;
    param_1->mMaterialMode = (uint)(byte)this[0xb].field_0x0[param_2];
  }
  puVar2 = this[10].field_0x8;
  param_1->field_0x40 = *(undefined **)(puVar2 + param_2 * 8);
  param_1->field_0x44 = *(undefined **)((int)(puVar2 + param_2 * 8) + 4);
  iVar1 = param_2 * 0x10;
  (*(code *)param_1->mpColorBlock->vtbl->setMatColorOffset)
            (param_1->mpColorBlock,*(undefined2 *)(this[10].mpData + iVar1));
  (*(code *)param_1->mpColorBlock->vtbl->setColorChanOffset)
            (param_1->mpColorBlock,*(undefined2 *)(this[10].mpData + iVar1 + 2));
  (*(code *)param_1->mpTexGenBlock->vtbl->setTexMtxOffset)
            (param_1->mpTexGenBlock,*(undefined2 *)(this[10].mpData + iVar1 + 4));
  (*(code *)param_1->mpTevBlock->vtbl->setTexNoOffset)
            (param_1->mpTevBlock,*(undefined2 *)(this[10].mpData + iVar1 + 6));
  (*(code *)param_1->mpTevBlock->vtbl->setTevRegOffset)
            (param_1->mpTevBlock,*(undefined2 *)(this[10].mpData + iVar1 + 8));
  (**(code **)(param_1->mpPEBlock->vtbl + 0x70))
            (param_1->mpPEBlock,*(undefined2 *)(this[10].mpData + iVar1 + 10));
  if (param_1->mpDLObj == (J3DDisplayListObj *)0x0) {
    pJVar7 = (J3DDisplayListObj *)JKernel::operator_new(0x10);
    if (pJVar7 != (J3DDisplayListObj *)0x0) {
      pJVar7->mpData[0] = (void *)0x0;
      pJVar7->mpData[1] = (void *)0x0;
      pJVar7->mSize = 0;
      pJVar7->mCapacity = 0;
    }
    param_1->mpDLObj = pJVar7;
    piVar8 = (int *)(this[10].field_0x0 + param_2 * 8);
    J3DDisplayListObj::setSingleDisplayList
              (param_1->mpDLObj,(void *)(*piVar8 + (int)piVar8),piVar8[1]);
  }
  return param_1;
}


/* __thiscall J3DMaterialFactory::calcSize(J3DMaterial *,
                                           J3DMaterialFactory::MaterialType,
                                           int,
                                           unsigned long) const */

undefined4 __thiscall
J3DMaterialFactory::calcSize
          (J3DMaterialFactory *this,J3DMaterial *param_1,MaterialType param_2,int param_3,
          ulong param_4)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 == 1) {
    uVar1 = calcSizeLockedMaterial(this,param_1,param_3,param_4);
  }
  else {
    if ((int)param_2 < 1) {
      if (-1 < (int)param_2) {
        uVar1 = calcSizeNormalMaterial(this,param_1,param_3,param_4);
      }
    }
    else {
      if ((int)param_2 < 3) {
        uVar1 = calcSizePatchedMaterial(this,param_1,param_3,param_4);
      }
    }
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall J3DMaterialFactory::calcSizeNormalMaterial(J3DMaterial *,
                                                         int,
                                                         unsigned long) const */

int __thiscall
J3DMaterialFactory::calcSizeNormalMaterial
          (J3DMaterialFactory *this,J3DMaterial *param_1,int param_2,ulong param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  iVar5 = 0;
  if (this[10].field_0x0 == (undefined *)0x0) {
    uVar2 = countStages(this,param_2);
    uVar4 = param_3 >> 0x10 & 0x1f;
    if (uVar4 < uVar2) {
      uVar4 = uVar2;
    }
    uVar6 = countTexGens(this,param_2);
    if (param_1 == (J3DMaterial *)0x0) {
      iVar5 = 0x4c;
    }
    uVar7 = J3DMaterial::calcSizeColorBlock((J3DMaterial *)(param_3 & 0xc0000000),(ulong)uVar6);
    uVar6 = J3DMaterial::calcSizeTexGenBlock
                      ((J3DMaterial *)
                       (param_3 & 0xc000000 & ~-(uint)(4 < (uint)((ulonglong)uVar6 >> 0x20))),
                       (ulong)uVar7);
    uVar8 = J3DMaterial::calcSizeTevBlock((J3DMaterial *)(uVar4 & 0xffff),(int)uVar6);
    iVar3 = J3DMaterial::calcSizeIndBlock((J3DMaterial *)(param_3 >> 0x18 & 1),(int)uVar8);
    iVar1 = J3DMaterial::calcSizePEBlock
                      ((J3DMaterial *)(param_3 & 0x30000000),
                       (uint)(byte)this->mpData
                                   [(uint)*(ushort *)(this->field_0x8 + param_2 * 2) * 0x14c],
                       (ulong)this->mpData);
    iVar1 = iVar5 + (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar6 >> 0x20) +
            (int)((ulonglong)uVar8 >> 0x20) + iVar3 + iVar1;
    iVar5 = 0;
    iVar3 = 8;
    do {
      if (*(short *)(this->mpData +
                    iVar5 + 0x48 + (uint)*(ushort *)(this->field_0x8 + param_2 * 2) * 0x14c) != -1)
      {
        iVar1 = iVar1 + 0xc4;
      }
      iVar5 = iVar5 + 2;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar1 = iVar1 + 0x2c;
  }
  else {
    iVar1 = calcSizeLockedMaterial(this,param_1,param_2,param_3);
  }
  return iVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DMaterialFactory::calcSizePatchedMaterial(J3DMaterial *,
                                                          int,
                                                          unsigned long) const */

int __thiscall
J3DMaterialFactory::calcSizePatchedMaterial
          (J3DMaterialFactory *this,J3DMaterial *param_1,int param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar3 = 0;
  if (param_1 == (J3DMaterial *)0x0) {
    iVar3 = 0x4c;
  }
  uVar4 = J3DMaterial::calcSizeColorBlock((J3DMaterial *)0x40000000,(ulong)param_1);
  iVar1 = J3DMaterial::calcSizeIndBlock
                    ((J3DMaterial *)(uint)((param_3 & 0x3000000) != 0),(int)uVar4);
  iVar2 = J3DMaterial::calcSizePEBlock
                    ((J3DMaterial *)0x10000000,
                     (uint)(byte)this->mpData
                                 [(uint)*(ushort *)(this->field_0x8 + param_2 * 2) * 0x14c],
                     (ulong)this->mpData);
  iVar2 = iVar3 + (int)((ulonglong)uVar4 >> 0x20) + 0x124 + iVar1 + iVar2;
  iVar3 = 0;
  iVar1 = 8;
  do {
    if (*(short *)(this->mpData +
                  iVar3 + 0x48 + (uint)*(ushort *)(this->field_0x8 + param_2 * 2) * 0x14c) != -1) {
      iVar2 = iVar2 + 0xc4;
    }
    iVar3 = iVar3 + 2;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return iVar2 + 0x2c;
}


/* __thiscall J3DMaterialFactory::calcSizeLockedMaterial(J3DMaterial *,
                                                         int,
                                                         unsigned long) const */

int __thiscall
J3DMaterialFactory::calcSizeLockedMaterial
          (J3DMaterialFactory *this,J3DMaterial *param_1,int param_2,ulong param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 == (J3DMaterial *)0x0) {
    iVar1 = 100;
  }
  return iVar1 + 0x10;
}


/* __thiscall J3DMaterialFactory::newMatColor(int,
                                              int) const */

void __thiscall J3DMaterialFactory::newMatColor(J3DMaterialFactory *this,int param_1,int param_2)

{
  uint uVar1;
  undefined *puVar2;
  int in_r6;
  undefined local_8;
  undefined uStack7;
  undefined uStack6;
  undefined uStack5;
  
  uStack7 = (undefined)((uint)J3DGraphLoader::_2369 >> 0x10);
  uStack6 = (undefined)((uint)J3DGraphLoader::_2369 >> 8);
  uStack5 = (undefined)J3DGraphLoader::_2369;
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + param_2 * 2) * 0x14c + in_r6 * 2 + 8);
  if (uVar1 == 0xffff) {
    local_8 = (undefined)((uint)J3DGraphLoader::_2369 >> 0x18);
    *(undefined *)&this->field_0x0 = local_8;
    *(undefined *)((int)&this->field_0x0 + 1) = uStack7;
    *(undefined *)((int)&this->field_0x0 + 2) = uStack6;
    *(undefined *)((int)&this->field_0x0 + 3) = uStack5;
  }
  else {
    puVar2 = (undefined *)(*(int *)(param_1 + 0x10) + uVar1 * 4);
    *(undefined *)&this->field_0x0 = *puVar2;
    *(undefined *)((int)&this->field_0x0 + 1) = puVar2[1];
    *(undefined *)((int)&this->field_0x0 + 2) = puVar2[2];
    *(undefined *)((int)&this->field_0x0 + 3) = puVar2[3];
  }
  return;
}


/* __thiscall J3DMaterialFactory::newColorChanNum(int) const */

undefined __thiscall J3DMaterialFactory::newColorChanNum(J3DMaterialFactory *this,int param_1)

{
  if ((byte)this->mpData[(uint)*(ushort *)(this->field_0x8 + param_1 * 2) * 0x14c + 2] != 0xff) {
    return this[1].field_0x8
           [(byte)this->mpData[(uint)*(ushort *)(this->field_0x8 + param_1 * 2) * 0x14c + 2]];
  }
  return 0;
}


/* __thiscall J3DMaterialFactory::newColorChan(int,
                                               int) const */

void __thiscall J3DMaterialFactory::newColorChan(J3DMaterialFactory *this,int param_1,int param_2)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  int in_r6;
  uint uVar4;
  
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + param_2 * 2) * 0x14c + in_r6 * 2 + 0xc);
  if (uVar1 != 0xffff) {
    pbVar2 = (byte *)(*(int *)(param_1 + 0x18) + uVar1 * 8);
    uVar4 = (uint)pbVar2[4];
    uVar1 = (uint)pbVar2[2];
    iVar3 = -uVar4 + 2;
    *(ushort *)&this->field_0x0 =
         (((ushort)((uVar1 & 0x20) << 7) |
           (ushort)((uVar1 & 0x10) << 7) |
           (ushort)((uVar1 & 8) << 2) |
           (ushort)((uVar1 & 4) << 2) |
           (ushort)((uVar1 & 2) << 2) |
           (ushort)((uVar1 & 1) << 2) |
           (((ushort)*pbVar2 << 1 | (ushort)pbVar2[1]) & 0xff83 |
           (ushort)(((uint)pbVar2[5] & ~-(uint)(pbVar2[5] == 0xff)) << 6)) & 0x67f |
           (ushort)((uVar1 & 0x40) << 7) | (pbVar2[2] & 0x80) << 7 |
          (ushort)(((uint)pbVar2[3] & ~-(uint)(uVar4 == 0)) << 7)) & 0xfdff |
         ((short)iVar3 - ((ushort)(iVar3 == 0) + (short)-uVar4 + 1)) * 0x200) & 0xfbff |
         (ushort)(uVar4 != 0) * 0x400;
    return;
  }
  uVar4 = (uint)UNK_803fc964;
  uVar1 = (uint)UNK_803fc962;
  iVar3 = -uVar4 + 2;
  *(ushort *)&this->field_0x0 =
       (((ushort)((uVar1 & 0x20) << 7) |
         (ushort)((uVar1 & 0x10) << 7) |
         (ushort)((uVar1 & 8) << 2) |
         (ushort)((uVar1 & 4) << 2) |
         (ushort)((uVar1 & 2) << 2) |
         (ushort)((uVar1 & 1) << 2) |
         (((ushort)J3DGraphBase::j3dDefaultColorChanInfo << 1 | (ushort)UNK_803fc961) & 0xff83 |
         (ushort)(((uint)UNK_803fc965 & ~-(uint)(UNK_803fc965 == 0xffff)) << 6)) & 0x67f |
         (ushort)((uVar1 & 0x40) << 7) | (UNK_803fc962 & 0x80) << 7 |
        (ushort)(((uint)UNK_803fc963 & ~-(uint)(uVar4 == 0)) << 7)) & 0xfdff |
       ((short)iVar3 - ((ushort)(iVar3 == 0) + (short)-uVar4 + 1)) * 0x200) & 0xfbff |
       (ushort)(uVar4 != 0) * 0x400;
  return;
}


/* __thiscall J3DMaterialFactory::newAmbColor(int,
                                              int) const */

void __thiscall J3DMaterialFactory::newAmbColor(J3DMaterialFactory *this,int param_1,int param_2)

{
  uint uVar1;
  undefined *puVar2;
  int in_r6;
  undefined local_8;
  undefined uStack7;
  undefined uStack6;
  undefined uStack5;
  
  uStack7 = (undefined)((uint)J3DGraphLoader::_2476 >> 0x10);
  uStack6 = (undefined)((uint)J3DGraphLoader::_2476 >> 8);
  uStack5 = (undefined)J3DGraphLoader::_2476;
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + param_2 * 2) * 0x14c + in_r6 * 2 + 0x14)
  ;
  if (uVar1 == 0xffff) {
    local_8 = (undefined)((uint)J3DGraphLoader::_2476 >> 0x18);
    *(undefined *)&this->field_0x0 = local_8;
    *(undefined *)((int)&this->field_0x0 + 1) = uStack7;
    *(undefined *)((int)&this->field_0x0 + 2) = uStack6;
    *(undefined *)((int)&this->field_0x0 + 3) = uStack5;
  }
  else {
    puVar2 = (undefined *)(*(int *)(param_1 + 0x1c) + uVar1 * 4);
    *(undefined *)&this->field_0x0 = *puVar2;
    *(undefined *)((int)&this->field_0x0 + 1) = puVar2[1];
    *(undefined *)((int)&this->field_0x0 + 2) = puVar2[2];
    *(undefined *)((int)&this->field_0x0 + 3) = puVar2[3];
  }
  return;
}


/* __thiscall J3DMaterialFactory::newTexGenNum(int) const */

undefined __thiscall J3DMaterialFactory::newTexGenNum(J3DMaterialFactory *this,int param_1)

{
  if ((byte)this->mpData[(uint)*(ushort *)(this->field_0x8 + param_1 * 2) * 0x14c + 3] != 0xff) {
    return this[3].field_0x0
           [(byte)this->mpData[(uint)*(ushort *)(this->field_0x8 + param_1 * 2) * 0x14c + 3]];
  }
  return 0;
}


/* __thiscall J3DMaterialFactory::newTexCoord(int,
                                              int) const */

void __thiscall J3DMaterialFactory::newTexCoord(J3DMaterialFactory *this,int param_1,int param_2)

{
  uint uVar1;
  undefined *puVar2;
  int in_r6;
  
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + param_2 * 2) * 0x14c + in_r6 * 2 + 0x28)
  ;
  if (uVar1 != 0xffff) {
    puVar2 = (undefined *)(*(int *)(param_1 + 0x28) + uVar1 * 4);
    *(undefined *)&this->field_0x0 = *puVar2;
    *(undefined *)((int)&this->field_0x0 + 1) = puVar2[1];
    *(undefined *)((int)&this->field_0x0 + 2) = puVar2[2];
    return;
  }
  *(undefined *)&this->field_0x0 = J3DGraphBase::j3dDefaultTexCoordInfo;
  *(undefined *)((int)&this->field_0x0 + 1) = DAT_80370d4d;
  *(undefined *)((int)&this->field_0x0 + 2) = DAT_80370d4e;
  return;
}


/* __thiscall J3DMaterialFactory::newTexMtx(int,
                                            int) const */

undefined * __thiscall
J3DMaterialFactory::newTexMtx(J3DMaterialFactory *this,int param_1,int param_2)

{
  ushort uVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  
  puVar2 = (undefined *)0x0;
  puVar5 = this->mpData;
  uVar1 = *(ushort *)(this->field_0x8 + param_1 * 2);
  if ((*(short *)(puVar5 + param_2 * 2 + (uint)uVar1 * 0x14c + 0x48) != -1) &&
     (puVar2 = (undefined *)JKernel::operator_new(0xc4), puVar2 != (undefined *)0x0)) {
    puVar5 = this[4].field_0x0 +
             (uint)*(ushort *)(puVar5 + param_2 * 2 + (uint)uVar1 * 0x14c + 0x48) * 100;
    iVar6 = 0;
    iVar3 = 0;
    do {
      iVar4 = 0;
      iVar7 = 4;
      do {
        *(undefined4 *)(puVar2 + iVar4 + 0x24 + iVar3) =
             *(undefined4 *)(puVar5 + iVar4 + 0x24 + iVar3);
        iVar4 = iVar4 + 4;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      iVar6 = iVar6 + 1;
      iVar3 = iVar3 + 0x10;
    } while (iVar6 < 4);
    *(undefined4 *)(puVar2 + 4) = *(undefined4 *)(puVar5 + 4);
    *(undefined4 *)(puVar2 + 8) = *(undefined4 *)(puVar5 + 8);
    *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(puVar5 + 0xc);
    *puVar2 = *puVar5;
    puVar2[1] = puVar5[1];
    *(undefined4 *)(puVar2 + 0x10) = *(undefined4 *)(puVar5 + 0x10);
    *(undefined4 *)(puVar2 + 0x14) = *(undefined4 *)(puVar5 + 0x14);
    *(undefined2 *)(puVar2 + 0x18) = *(undefined2 *)(puVar5 + 0x18);
    *(undefined4 *)(puVar2 + 0x1c) = *(undefined4 *)(puVar5 + 0x1c);
    *(undefined4 *)(puVar2 + 0x20) = *(undefined4 *)(puVar5 + 0x20);
  }
  return puVar2;
}


/* __thiscall J3DMaterialFactory::newCullMode(int) const */

uint __thiscall J3DMaterialFactory::newCullMode(J3DMaterialFactory *this,int param_1)

{
  if ((byte)this->mpData[(uint)*(ushort *)(this->field_0x8 + param_1 * 2) * 0x14c + 1] != 0xff) {
    return *(uint *)(this[5].field_0x0 +
                    (uint)(byte)this->mpData
                                [(uint)*(ushort *)(this->field_0x8 + param_1 * 2) * 0x14c + 1] * 4)
           & 0xff;
  }
  return 0xff;
}


/* __thiscall J3DMaterialFactory::newTexNo(int,
                                           int) const */

undefined2 __thiscall J3DMaterialFactory::newTexNo(J3DMaterialFactory *this,int param_1,int param_2)

{
  if (*(ushort *)
       (this->mpData + param_2 * 2 + (uint)*(ushort *)(this->field_0x8 + param_1 * 2) * 0x14c + 0x84
       ) != 0xffff) {
    return *(undefined2 *)
            (this[4].field_0x8 +
            (uint)*(ushort *)
                   (this->mpData +
                   param_2 * 2 + (uint)*(ushort *)(this->field_0x8 + param_1 * 2) * 0x14c + 0x84) *
            2);
  }
  return 0xffff;
}


/* __thiscall J3DMaterialFactory::newTevOrder(int,
                                              int) const */

void __thiscall J3DMaterialFactory::newTevOrder(J3DMaterialFactory *this,int param_1,int param_2)

{
  uint uVar1;
  undefined *puVar2;
  int in_r6;
  
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + param_2 * 2) * 0x14c + in_r6 * 2 + 0xbc)
  ;
  if (uVar1 != 0xffff) {
    puVar2 = (undefined *)(*(int *)(param_1 + 0x40) + uVar1 * 4);
    *(undefined *)&this->field_0x0 = *puVar2;
    *(undefined *)((int)&this->field_0x0 + 1) = puVar2[1];
    *(undefined *)((int)&this->field_0x0 + 2) = puVar2[2];
    return;
  }
  *(undefined *)&this->field_0x0 = J3DGraphBase::j3dDefaultTevOrderInfoNull;
  *(undefined *)((int)&this->field_0x0 + 1) = UNK_803fc93d;
  *(undefined *)((int)&this->field_0x0 + 2) = UNK_803fc93e;
  return;
}


/* __thiscall J3DMaterialFactory::newTevColor(int,
                                              int) const */

void __thiscall J3DMaterialFactory::newTevColor(J3DMaterialFactory *this,int param_1,int param_2)

{
  uint uVar1;
  undefined2 *puVar2;
  int in_r6;
  undefined2 local_8;
  undefined2 uStack6;
  undefined2 local_4;
  undefined2 uStack2;
  
  uStack6 = (undefined2)J3DGraphLoader::_2587;
  local_4 = (undefined2)((uint)DAT_803fcf9c >> 0x10);
  uStack2 = (undefined2)DAT_803fcf9c;
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + param_2 * 2) * 0x14c + in_r6 * 2 + 0xdc)
  ;
  if (uVar1 == 0xffff) {
    local_8 = (undefined2)((uint)J3DGraphLoader::_2587 >> 0x10);
    *(undefined2 *)&this->field_0x0 = local_8;
    *(undefined2 *)((int)&this->field_0x0 + 2) = uStack6;
    *(undefined2 *)&this->mpData = local_4;
    *(undefined2 *)((int)&this->mpData + 2) = uStack2;
  }
  else {
    puVar2 = (undefined2 *)(*(int *)(param_1 + 0x44) + uVar1 * 8);
    *(undefined2 *)&this->field_0x0 = *puVar2;
    *(undefined2 *)((int)&this->field_0x0 + 2) = puVar2[1];
    *(undefined2 *)&this->mpData = puVar2[2];
    *(undefined2 *)((int)&this->mpData + 2) = puVar2[3];
  }
  return;
}


/* __thiscall J3DMaterialFactory::newTevKColor(int,
                                               int) const */

void __thiscall J3DMaterialFactory::newTevKColor(J3DMaterialFactory *this,int param_1,int param_2)

{
  uint uVar1;
  undefined *puVar2;
  int in_r6;
  undefined local_8;
  undefined uStack7;
  undefined uStack6;
  undefined uStack5;
  
  uStack7 = (undefined)((uint)J3DGraphLoader::_2608 >> 0x10);
  uStack6 = (undefined)((uint)J3DGraphLoader::_2608 >> 8);
  uStack5 = (undefined)J3DGraphLoader::_2608;
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + param_2 * 2) * 0x14c + in_r6 * 2 + 0x94)
  ;
  if (uVar1 == 0xffff) {
    local_8 = (undefined)((uint)J3DGraphLoader::_2608 >> 0x18);
    *(undefined *)&this->field_0x0 = local_8;
    *(undefined *)((int)&this->field_0x0 + 1) = uStack7;
    *(undefined *)((int)&this->field_0x0 + 2) = uStack6;
    *(undefined *)((int)&this->field_0x0 + 3) = uStack5;
  }
  else {
    puVar2 = (undefined *)(*(int *)(param_1 + 0x48) + uVar1 * 4);
    *(undefined *)&this->field_0x0 = *puVar2;
    *(undefined *)((int)&this->field_0x0 + 1) = puVar2[1];
    *(undefined *)((int)&this->field_0x0 + 2) = puVar2[2];
    *(undefined *)((int)&this->field_0x0 + 3) = puVar2[3];
  }
  return;
}


/* __thiscall J3DMaterialFactory::newTevStageNum(int) const */

undefined __thiscall J3DMaterialFactory::newTevStageNum(J3DMaterialFactory *this,int param_1)

{
  if ((byte)this->mpData[(uint)*(ushort *)(this->field_0x8 + param_1 * 2) * 0x14c + 4] != 0xff) {
    return this[6].mpData
           [(byte)this->mpData[(uint)*(ushort *)(this->field_0x8 + param_1 * 2) * 0x14c + 4]];
  }
  return 0xff;
}


/* __thiscall J3DMaterialFactory::newTevStage(int,
                                              int) const */

void __thiscall J3DMaterialFactory::newTevStage(J3DMaterialFactory *this,int param_1,int param_2)

{
  uint uVar1;
  int in_r6;
  
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + param_2 * 2) * 0x14c + in_r6 * 2 + 0xe4)
  ;
  if (uVar1 == 0xffff) {
    J3DTevStage::J3DTevStage((J3DTevStage *)this);
  }
  else {
    J3DTevStage::J3DTevStage
              ((J3DTevStage *)this,(J3DTevStageInfo *)(*(int *)(param_1 + 0x50) + uVar1 * 0x14));
  }
  return;
}


/* __thiscall J3DMaterialFactory::newTevSwapModeTable(int,
                                                      int) const */

void __thiscall
J3DMaterialFactory::newTevSwapModeTable(J3DMaterialFactory *this,int param_1,int param_2)

{
  uint uVar1;
  int in_r6;
  char *pcVar2;
  
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + param_2 * 2) * 0x14c + in_r6 * 2 + 0x124
                 );
  if (uVar1 != 0xffff) {
    pcVar2 = (char *)(*(int *)(param_1 + 0x58) + uVar1 * 4);
    *(char *)&this->field_0x0 = *pcVar2 * '@' + pcVar2[1] * '\x10' + pcVar2[2] * '\x04' + pcVar2[3];
    return;
  }
  *(char *)&this->field_0x0 =
       J3DGraphBase::j3dDefaultTevSwapModeTable * '@' +
       UNK_803fc959 * '\x10' + UNK_803fc95a * '\x04' + UNK_803fc95b;
  return;
}


/* __thiscall J3DMaterialFactory::newIndTexStageNum(int) const */

undefined __thiscall J3DMaterialFactory::newIndTexStageNum(J3DMaterialFactory *this,int param_1)

{
  if (this[1].field_0x0[param_1 * 0x138] == '\x01') {
    return this[1].field_0x0[param_1 * 0x138 + 1];
  }
  return 0;
}


/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall J3DMaterialFactory::newIndTexOrder(int,
                                                 int) const */

void __thiscall J3DMaterialFactory::newIndTexOrder(J3DMaterialFactory *this,int param_1,int param_2)

{
  char *pcVar1;
  int in_r6;
  undefined4 local_8;
  
  local_8._1_3_ = local_8._1_3_ & 0xffff | (uint3)UNK_803fc941 << 0x10;
  local_8 = (undefined *)CONCAT13(J3DGraphBase::j3dDefaultIndTexOrderNull,local_8._1_3_);
  pcVar1 = (char *)(*(int *)(param_1 + 0xc) + param_2 * 0x138);
  if (*pcVar1 == '\x01') {
    pcVar1 = pcVar1 + in_r6 * 4 + 4;
    *(char *)&this->field_0x0 = *pcVar1;
    *(char *)((int)&this->field_0x0 + 1) = pcVar1[1];
  }
  else {
    this->field_0x0 = local_8;
  }
  return;
}


/* __thiscall J3DMaterialFactory::newIndTexMtx(int,
                                               int) const */

void __thiscall J3DMaterialFactory::newIndTexMtx(J3DMaterialFactory *this,int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined **ppuVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined **ppuVar6;
  int in_r6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uStack44;
  undefined4 local_28 [6];
  undefined local_10;
  
  iVar9 = 0;
  iVar7 = 0;
  do {
    iVar8 = 0;
    iVar10 = 3;
    do {
      *(undefined4 *)((int)local_28 + iVar8 + iVar7) =
           *(undefined4 *)((int)&J3DGraphBase::j3dDefaultIndTexMtxInfo + iVar8 + iVar7);
      iVar8 = iVar8 + 4;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    iVar9 = iVar9 + 1;
    iVar7 = iVar7 + 0xc;
  } while (iVar9 < 2);
  local_10 = DAT_80370de8;
  pcVar5 = (char *)(*(int *)(param_1 + 0xc) + param_2 * 0x138);
  if (*pcVar5 == '\x01') {
    pcVar5 = pcVar5 + in_r6 * 0x1c + 0x14;
    iVar9 = 0;
    iVar7 = 0;
    do {
      iVar8 = 0;
      iVar10 = 3;
      do {
        *(undefined4 *)((int)&this->field_0x0 + iVar8 + iVar7) =
             *(undefined4 *)(pcVar5 + iVar8 + iVar7);
        iVar8 = iVar8 + 4;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      iVar9 = iVar9 + 1;
      iVar7 = iVar7 + 0xc;
    } while (iVar9 < 2);
    *(char *)&this[2].field_0x0 = pcVar5[0x18];
  }
  else {
    iVar7 = 3;
    puVar1 = &uStack44;
    ppuVar2 = &this[-1].field_0x8;
    do {
      ppuVar6 = ppuVar2;
      puVar4 = puVar1;
      puVar3 = (undefined *)puVar4[2];
      ppuVar6[1] = (undefined *)puVar4[1];
      ppuVar6[2] = puVar3;
      iVar7 = iVar7 + -1;
      puVar1 = puVar4 + 2;
      ppuVar2 = ppuVar6 + 2;
    } while (iVar7 != 0);
    ppuVar6[3] = (undefined *)puVar4[3];
  }
  return;
}


/* __thiscall J3DMaterialFactory::newIndTevStage(int,
                                                 int) const */

void __thiscall J3DMaterialFactory::newIndTevStage(J3DMaterialFactory *this,int param_1,int param_2)

{
  byte *pbVar1;
  char *pcVar2;
  int in_r6;
  
  pcVar2 = (char *)(*(int *)(param_1 + 0xc) + param_2 * 0x138);
  if (*pcVar2 == '\x01') {
    pbVar1 = (byte *)(pcVar2 + in_r6 * 0xc + 0x78);
    this->field_0x0 = (undefined *)0x0;
    this->field_0x0 = (undefined *)((uint)this->field_0x0 & 0xfffffffc | (uint)*pbVar1);
    this->field_0x0 = (undefined *)((uint)this->field_0x0 & 0xfffffff3 | (uint)pbVar1[1] << 2);
    this->field_0x0 = (undefined *)((uint)this->field_0x0 & 0xffffff8f | (uint)pbVar1[2] << 4);
    this->field_0x0 = (undefined *)((uint)this->field_0x0 & 0xffffe1ff | (uint)pbVar1[3] << 9);
    this->field_0x0 = (undefined *)((uint)this->field_0x0 & 0xffff1fff | (uint)pbVar1[4] << 0xd);
    this->field_0x0 = (undefined *)((uint)this->field_0x0 & 0xfff8ffff | (uint)pbVar1[5] << 0x10);
    this->field_0x0 = (undefined *)((uint)this->field_0x0 & 0xffefffff | (uint)pbVar1[6] << 0x14);
    this->field_0x0 = (undefined *)((uint)this->field_0x0 & 0xfff7ffff | (uint)pbVar1[7] << 0x13);
    this->field_0x0 = (undefined *)((uint)this->field_0x0 & 0xfffffe7f | (uint)pbVar1[8] << 7);
    return;
  }
  this->field_0x0 =
       (undefined *)
       (((((J3DGraphBase::j3dDefaultIndTevStageInfo & 0xfffffff3 | (uint)DAT_80370e01 << 2) &
           0xffffff8f | (uint)DAT_80370e02 << 4) & 0x1ff | (DAT_80370e03 & 0x8f) << 9 |
         (uint)DAT_80370e04 << 0xd) & 0xfff8ffff | (uint)DAT_80370e05 << 0x10) & 0xffe7fe7f |
        (uint)DAT_80370e06 << 0x14 | (uint)DAT_80370e07 << 0x13 | (uint)DAT_80370e08 << 7);
  return;
}


/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall J3DMaterialFactory::newIndTexCoordScale(int,
                                                      int) const */

void __thiscall
J3DMaterialFactory::newIndTexCoordScale(J3DMaterialFactory *this,int param_1,int param_2)

{
  char *pcVar1;
  int in_r6;
  undefined4 local_8;
  
  local_8._1_3_ = local_8._1_3_ & 0xffff | (uint3)UNK_803fc94d << 0x10;
  local_8 = (undefined *)CONCAT13(J3DGraphBase::j3dDefaultIndTexCoordScaleInfo,local_8._1_3_);
  pcVar1 = (char *)(*(int *)(param_1 + 0xc) + param_2 * 0x138);
  if (*pcVar1 == '\x01') {
    pcVar1 = pcVar1 + in_r6 * 4 + 0x68;
    *(char *)&this->field_0x0 = *pcVar1;
    *(char *)((int)&this->field_0x0 + 1) = pcVar1[1];
  }
  else {
    this->field_0x0 = local_8;
  }
  return;
}


/* __thiscall J3DMaterialFactory::newFog(int) const */

void __thiscall J3DMaterialFactory::newFog(J3DMaterialFactory *this,int param_1)

{
  ushort uVar1;
  undefined *puVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  
  puVar4 = this->mpData;
  uVar1 = *(ushort *)(this->field_0x8 + param_1 * 2);
  if (*(short *)(puVar4 + (uint)uVar1 * 0x14c + 0x144) == -1) {
    puVar4 = (undefined *)JKernel::operator_new(0x2c);
    if (puVar4 != (undefined *)0x0) {
      *puVar4 = J3DGraphBase::j3dDefaultFogInfo;
      puVar4[1] = DAT_80370e0d;
      *(undefined2 *)(puVar4 + 2) = DAT_80370e0e;
      *(undefined4 *)(puVar4 + 4) = DAT_80370e10;
      *(undefined4 *)(puVar4 + 8) = DAT_80370e14;
      *(undefined4 *)(puVar4 + 0xc) = DAT_80370e18;
      *(undefined4 *)(puVar4 + 0x10) = DAT_80370e1c;
      puVar4[0x14] = DAT_80370e20;
      puVar4[0x15] = DAT_80370e21;
      puVar4[0x16] = DAT_80370e22;
      puVar4[0x17] = DAT_80370e23;
      iVar3 = 0;
      iVar5 = 10;
      do {
        *(undefined2 *)(puVar4 + iVar3 + 0x18) = *(undefined2 *)((int)&DAT_80370e24 + iVar3);
        iVar3 = iVar3 + 2;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  else {
    puVar2 = (undefined *)JKernel::operator_new(0x2c);
    if (puVar2 != (undefined *)0x0) {
      puVar4 = this[7].field_0x8 + (uint)*(ushort *)(puVar4 + (uint)uVar1 * 0x14c + 0x144) * 0x2c;
      *puVar2 = *puVar4;
      puVar2[1] = puVar4[1];
      *(undefined2 *)(puVar2 + 2) = *(undefined2 *)(puVar4 + 2);
      *(undefined4 *)(puVar2 + 4) = *(undefined4 *)(puVar4 + 4);
      *(undefined4 *)(puVar2 + 8) = *(undefined4 *)(puVar4 + 8);
      *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(puVar4 + 0xc);
      *(undefined4 *)(puVar2 + 0x10) = *(undefined4 *)(puVar4 + 0x10);
      puVar2[0x14] = puVar4[0x14];
      puVar2[0x15] = puVar4[0x15];
      puVar2[0x16] = puVar4[0x16];
      puVar2[0x17] = puVar4[0x17];
      iVar3 = 0;
      iVar5 = 10;
      do {
        *(undefined2 *)(puVar2 + iVar3 + 0x18) = *(undefined2 *)(puVar4 + iVar3 + 0x18);
        iVar3 = iVar3 + 2;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  return;
}


/* __thiscall J3DMaterialFactory::newAlphaComp(int) const */

void __thiscall J3DMaterialFactory::newAlphaComp(J3DMaterialFactory *this,int param_1)

{
  uint uVar1;
  int in_r5;
  byte *pbVar2;
  
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + in_r5 * 2) * 0x14c + 0x146);
  if (uVar1 != 0xffff) {
    pbVar2 = (byte *)(*(int *)(param_1 + 0x60) + uVar1 * 8);
    *(ushort *)&this->field_0x0 = (ushort)*pbVar2 * 0x20 + (ushort)pbVar2[2] * 8 + (ushort)pbVar2[3]
    ;
    *(byte *)((int)&this->field_0x0 + 2) = pbVar2[1];
    *(byte *)((int)&this->field_0x0 + 3) = pbVar2[4];
    return;
  }
  *(undefined2 *)&this->field_0x0 = 0xffff;
  *(undefined *)((int)&this->field_0x0 + 2) = 0;
  *(undefined *)((int)&this->field_0x0 + 3) = 0;
  return;
}


/* __thiscall J3DMaterialFactory::newBlend(int) const */

void __thiscall J3DMaterialFactory::newBlend(J3DMaterialFactory *this,int param_1)

{
  uint uVar1;
  undefined *puVar2;
  int in_r5;
  
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + in_r5 * 2) * 0x14c + 0x148);
  if (uVar1 != 0xffff) {
    puVar2 = (undefined *)(*(int *)(param_1 + 100) + uVar1 * 4);
    *(undefined *)&this->field_0x0 = *puVar2;
    *(undefined *)((int)&this->field_0x0 + 1) = puVar2[1];
    *(undefined *)((int)&this->field_0x0 + 2) = puVar2[2];
    *(undefined *)((int)&this->field_0x0 + 3) = puVar2[3];
    return;
  }
  *(undefined *)&this->field_0x0 = J3DGraphBase::j3dDefaultBlendInfo;
  *(undefined *)((int)&this->field_0x0 + 1) = UNK_803fc95d;
  *(undefined *)((int)&this->field_0x0 + 2) = UNK_803fc95e;
  *(undefined *)((int)&this->field_0x0 + 3) = UNK_803fc95f;
  return;
}


/* __thiscall J3DMaterialFactory::newZMode(int) const */

void __thiscall J3DMaterialFactory::newZMode(J3DMaterialFactory *this,int param_1)

{
  uint uVar1;
  byte *pbVar2;
  int in_r5;
  
  uVar1 = (uint)*(byte *)(*(int *)(param_1 + 4) +
                          (uint)*(ushort *)(*(int *)(param_1 + 8) + in_r5 * 2) * 0x14c + 6);
  if (uVar1 != 0xff) {
    pbVar2 = (byte *)(*(int *)(param_1 + 0x68) + uVar1 * 4);
    *(ushort *)&this->field_0x0 = (ushort)pbVar2[1] * 2 + (ushort)*pbVar2 * 0x10 + (ushort)pbVar2[2]
    ;
    return;
  }
  *(undefined2 *)&this->field_0x0 = J3DGraphBase::j3dDefaultZModeID;
  return;
}


/* __thiscall J3DMaterialFactory::newZCompLoc(int) const */

undefined __thiscall J3DMaterialFactory::newZCompLoc(J3DMaterialFactory *this,int param_1)

{
  if ((byte)this->mpData[(uint)*(ushort *)(this->field_0x8 + param_1 * 2) * 0x14c + 5] != 0xff) {
    return this[9].field_0x0
           [(byte)this->mpData[(uint)*(ushort *)(this->field_0x8 + param_1 * 2) * 0x14c + 5]];
  }
  return 0;
}


/* __thiscall J3DMaterialFactory::newDither(int) const */

undefined __thiscall J3DMaterialFactory::newDither(J3DMaterialFactory *this,int param_1)

{
  if ((byte)this->mpData[(uint)*(ushort *)(this->field_0x8 + param_1 * 2) * 0x14c + 7] != 0xff) {
    return this[9].mpData
           [(byte)this->mpData[(uint)*(ushort *)(this->field_0x8 + param_1 * 2) * 0x14c + 7]];
  }
  return 1;
}


/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall J3DMaterialFactory::newNBTScale(int) const */

void __thiscall J3DMaterialFactory::newNBTScale(J3DMaterialFactory *this,int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined *puVar4;
  int in_r5;
  undefined4 local_18;
  
  puVar2 = DAT_80370e44;
  puVar1 = DAT_80370e40;
  puVar4 = DAT_80370e3c;
  local_18 = (undefined *)CONCAT13(J3DGraphBase::j3dDefaultNBTScaleInfo,local_18._1_3_);
  uVar3 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + in_r5 * 2) * 0x14c + 0x14a);
  if (uVar3 == 0xffff) {
    this->field_0x0 = local_18;
    this->mpData = puVar4;
    this->field_0x8 = puVar1;
    this[1].field_0x0 = puVar2;
  }
  else {
    puVar4 = (undefined *)(*(int *)(param_1 + 0x74) + uVar3 * 0x10);
    *(undefined *)&this->field_0x0 = *puVar4;
    this->mpData = *(undefined **)(puVar4 + 4);
    this->field_0x8 = *(undefined **)(puVar4 + 8);
    this[1].field_0x0 = *(undefined **)(puVar4 + 0xc);
  }
  return;
}


/* __thiscall J3DPEBlockNull::load(void) */

void __thiscall J3DPEBlockNull::load(J3DPEBlockNull *this)

{
  return;
}


/* __thiscall J3DPEBlockNull::getType(void) */

undefined4 __thiscall J3DPEBlockNull::getType(J3DPEBlockNull *this)

{
  return 0x50454e4c;
}


/* __thiscall J3DPEBlockNull::~J3DPEBlockNull(void) */

void __thiscall J3DPEBlockNull::_J3DPEBlockNull(J3DPEBlockNull *this)

{
  short in_r4;
  
  if (this != (J3DPEBlockNull *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DPEBlockNull *)0x0) {
      *(undefined1 **)this = &J3DPEBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DTevBlockNull::reset(J3DTevBlock *) */

void __thiscall J3DTevBlockNull::reset(J3DTevBlockNull *this,J3DTevBlock *param_1)

{
  return;
}


/* __thiscall J3DTevBlockNull::ptrToIndex(void) */

void __thiscall J3DTevBlockNull::ptrToIndex(J3DTevBlockNull *this)

{
  return;
}


/* __thiscall J3DTevBlockNull::indexToPtr(void) */

void __thiscall J3DTevBlockNull::indexToPtr(J3DTevBlockNull *this)

{
  J3DTevBlock::indexToPtr_private((J3DTevBlock *)this,*(ulong *)(this + 4));
  return;
}


/* __thiscall J3DTevBlockNull::getType(void) */

undefined4 __thiscall J3DTevBlockNull::getType(J3DTevBlockNull *this)

{
  return 0x54564e4c;
}


/* __thiscall J3DTevBlockNull::~J3DTevBlockNull(void) */

void __thiscall J3DTevBlockNull::_J3DTevBlockNull(J3DTevBlockNull *this)

{
  short in_r4;
  
  if (this != (J3DTevBlockNull *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DTevBlockNull *)0x0) {
      *(undefined ***)this = &J3DTevBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DTexGenBlockNull::calc(float const *[][][][]) */

void __thiscall J3DTexGenBlockNull::calc(J3DTexGenBlockNull *this,float *param_1)

{
  return;
}


/* __thiscall J3DTexGenBlockNull::load(void) */

void __thiscall J3DTexGenBlockNull::load(J3DTexGenBlockNull *this)

{
  return;
}


/* __thiscall J3DTexGenBlockNull::patch(void) */

void __thiscall J3DTexGenBlockNull::patch(J3DTexGenBlockNull *this)

{
  return;
}


/* __thiscall J3DTexGenBlockNull::diff(unsigned long) */

void __thiscall J3DTexGenBlockNull::diff(J3DTexGenBlockNull *this,ulong param_1)

{
  return;
}


/* __thiscall J3DTexGenBlockNull::diffTexMtx(void) */

void __thiscall J3DTexGenBlockNull::diffTexMtx(J3DTexGenBlockNull *this)

{
  return;
}


/* __thiscall J3DTexGenBlockNull::diffTexGen(void) */

void __thiscall J3DTexGenBlockNull::diffTexGen(J3DTexGenBlockNull *this)

{
  return;
}


/* __thiscall J3DTexGenBlockNull::getType(void) */

undefined4 __thiscall J3DTexGenBlockNull::getType(J3DTexGenBlockNull *this)

{
  return 0x54474e4c;
}


/* __thiscall J3DTexGenBlockNull::~J3DTexGenBlockNull(void) */

void __thiscall J3DTexGenBlockNull::_J3DTexGenBlockNull(J3DTexGenBlockNull *this)

{
  short in_r4;
  
  if (this != (J3DTexGenBlockNull *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DTexGenBlockNull *)0x0) {
      *(undefined1 **)this = &J3DTexGenBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DColorBlockNull::getType(void) */

undefined4 __thiscall J3DColorBlockNull::getType(J3DColorBlockNull *this)

{
  return 0x434c4e4c;
}


/* __thiscall J3DColorBlockNull::~J3DColorBlockNull(void) */

void __thiscall J3DColorBlockNull::_J3DColorBlockNull(J3DColorBlockNull *this)

{
  short in_r4;
  
  if (this != (J3DColorBlockNull *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DColorBlockNull *)0x0) {
      *(undefined ***)this = &J3DColorBlock::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DTevStage::J3DTevStage(J3DTevStageInfo const &) */

void __thiscall J3DTevStage::J3DTevStage(J3DTevStage *this,J3DTevStageInfo *param_1)

{
  setTevStageInfo(this,param_1);
  this->field_0x7 = this->field_0x7 & 0xf3 | UNK_803fc955 << 2;
  this->field_0x7 = this->field_0x7 & 0xfc | J3DGraphBase::j3dDefaultTevSwapMode;
  return;
}


/* __thiscall J3DMaterial::~J3DMaterial(void) */

void __thiscall J3DMaterial::_J3DMaterial(J3DMaterial *this)

{
  short in_r4;
  
  if ((this != (J3DMaterial *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace J3DGraphLoader {

/* __stdcall JSUConvertOffsetToPtr<J3DCurrentMtxInfo>(void const *,
                                                      void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DPatchingInfo>(void const *,
                                                    void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DDisplayListInit>(void const *,
                                                       void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DNBTScaleInfo>(void const *,
                                                    void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DZModeInfo>(void const *,
                                                 void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DBlendInfo>(void const *,
                                                 void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DAlphaCompInfo>(void const *,
                                                     void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DFogInfo>(void const *,
                                               void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DTevSwapModeTableInfo>(void const *,
                                                            void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DTevSwapModeInfo>(void const *,
                                                       void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DTevStageInfo>(void const *,
                                                    void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<_GXColorS10>(void const *,
                                                void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DTevOrderInfo>(void const *,
                                                    void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DTexMtxInfo>(void const *,
                                                  void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DTexCoord2Info>(void const *,
                                                     void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DTexCoordInfo>(void const *,
                                                    void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DLightInfo>(void const *,
                                                 void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DColorChanInfo>(void const *,
                                                     void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<unsigned char>(void const *,
                                                  void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<_GXColor>(void const *,
                                             void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<_GXCullMode>(void const *,
                                                void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DIndInitData>(void const *,
                                                   void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<unsigned short>(void const *,
                                                   void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DMaterialInitData>(void const *,
                                                        void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}

