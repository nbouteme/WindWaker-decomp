#include <J3DGraphLoader/J3DMaterialFactory_v21.h>
#include <J3DGraphLoader/J3DMaterialFactory_v21.h>
#include <J3DGraphLoader/J3DMaterialFactory.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <J3DGraphBase/J3DMaterial.h>
#include <m_Do_ext.h>
#include <J3DMaterialFactory_v21.h>


/* __thiscall J3DMaterialFactory_v21::J3DMaterialFactory_v21(J3DMaterialBlock_v21 const &) */

void __thiscall
J3DMaterialFactory_v21::J3DMaterialFactory_v21
          (J3DMaterialFactory_v21 *this,J3DMaterialBlock_v21 *param_1)

{
  undefined4 uVar1;
  
  *(undefined2 *)this = *(undefined2 *)(param_1 + 8);
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0xc));
  *(undefined4 *)(this + 4) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x10));
  *(undefined4 *)(this + 8) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x18));
  *(undefined4 *)(this + 0x30) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x1c));
  *(undefined4 *)(this + 0xc) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x20));
  *(undefined4 *)(this + 0x10) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x24));
  *(undefined4 *)(this + 0x14) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x28));
  *(undefined4 *)(this + 0x18) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x2c));
  *(undefined4 *)(this + 0x1c) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x30));
  *(undefined4 *)(this + 0x20) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x34));
  *(undefined4 *)(this + 0x24) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x38));
  *(undefined4 *)(this + 0x28) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x3c));
  *(undefined4 *)(this + 0x2c) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x40));
  *(undefined4 *)(this + 0x34) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x44));
  *(undefined4 *)(this + 0x38) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x48));
  *(undefined4 *)(this + 0x3c) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x4c));
  *(undefined4 *)(this + 0x40) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x50));
  *(undefined4 *)(this + 0x44) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x54));
  *(undefined4 *)(this + 0x48) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x58));
  *(undefined4 *)(this + 0x4c) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x5c));
  *(undefined4 *)(this + 0x50) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x60));
  *(undefined4 *)(this + 0x54) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 100));
  *(undefined4 *)(this + 0x58) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x68));
  *(undefined4 *)(this + 0x5c) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x6c));
  *(undefined4 *)(this + 0x60) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x70));
  *(undefined4 *)(this + 100) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x74));
  *(undefined4 *)(this + 0x68) = uVar1;
  return;
}


/* __thiscall J3DMaterialFactory_v21::countUniqueMaterials(void) */

uint __thiscall J3DMaterialFactory_v21::countUniqueMaterials(J3DMaterialFactory_v21 *this)

{
  uint uVar1;
  
  for (uVar1 = 0; (uVar1 & 0xffff) < (uint)*(ushort *)this; uVar1 = uVar1 + 1) {
  }
  return uVar1;
}


/* __thiscall J3DMaterialFactory_v21::countTexGens(int) const */

undefined __thiscall J3DMaterialFactory_v21::countTexGens(J3DMaterialFactory_v21 *this,int param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(*(int *)(this + 4) +
                          (uint)*(ushort *)(*(int *)(this + 8) + param_1 * 2) * 0x138 + 3);
  if (uVar1 != 0xff) {
    return *(undefined *)(*(int *)(this + 0x18) + uVar1);
  }
  return 0;
}


/* __thiscall J3DMaterialFactory_v21::countStages(int) const */

uint __thiscall J3DMaterialFactory_v21::countStages(J3DMaterialFactory_v21 *this,int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar3 = *(int *)(this + 4) + (uint)*(ushort *)(*(int *)(this + 8) + param_1 * 2) * 0x138;
  uVar4 = 0;
  uVar5 = 0;
  uVar1 = (uint)*(byte *)(iVar3 + 4);
  if (uVar1 != 0xff) {
    uVar5 = (uint)*(byte *)(*(int *)(this + 0x40) + uVar1);
  }
  iVar2 = 0;
  iVar6 = 8;
  do {
    if (*(short *)(iVar3 + iVar2 + 0x70) != -1) {
      uVar4 = uVar4 + 1;
    }
    iVar2 = iVar2 + 2;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if ((uVar5 != uVar4) && (uVar4 != 0)) {
    if (uVar5 <= uVar4) {
      return uVar4;
    }
    return uVar5;
  }
  return uVar5;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* __thiscall J3DMaterialFactory_v21::create(J3DMaterial *,
                                             int,
                                             unsigned long) const */

J3DMaterial * __thiscall
J3DMaterialFactory_v21::create
          (J3DMaterialFactory_v21 *this,J3DMaterial *param_1,int param_2,ulong param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  J3DColorBlockLightOn *pJVar6;
  undefined *puVar7;
  J3DPEBlockFull *pJVar8;
  undefined4 uVar9;
  int iVar10;
  ulong uVar11;
  ulong extraout_r4;
  byte bVar13;
  int iVar12;
  int iVar14;
  int iVar15;
  uint uVar16;
  undefined8 uVar17;
  J3DMaterialFactory_v21 local_a8 [4];
  J3DMaterialFactory_v21 local_a4 [4];
  undefined2 local_a0 [2];
  undefined2 local_9c [2];
  undefined2 local_98 [2];
  undefined2 local_94 [2];
  undefined4 local_90;
  J3DMaterialFactory_v21 aJStack140 [4];
  J3DMaterialFactory_v21 aJStack136 [4];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  J3DMaterialFactory_v21 aJStack104 [8];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  
  uVar4 = countStages(this,param_2);
  uVar16 = param_3 >> 0x10 & 0x1f;
  if (uVar16 < uVar4) {
    uVar16 = uVar4;
  }
  uVar4 = 8;
  if (uVar16 < 9) {
    uVar4 = uVar16;
  }
  uVar17 = countTexGens(this,param_2);
  uVar5 = (uint)((ulonglong)uVar17 >> 0x20);
  uVar11 = (ulong)uVar17;
  if ((param_1 == (J3DMaterial *)0x0) &&
     (param_1 = (J3DMaterial *)JKernel::operator_new(0x4c), param_1 != (J3DMaterial *)0x0)) {
    param_1->vtbl = (undefined *)&J3DMaterial::__vt;
    param_1->field_0x40 = (undefined *)0x3cf3cf00;
    param_1->field_0x44 = (undefined *)0xf3cf3c;
    J3DMaterial::initialize(param_1);
    uVar11 = extraout_r4;
  }
  pJVar6 = J3DMaterial::createColorBlock(param_3 & 0xc0000000);
  param_1->mpColorBlock = &pJVar6->parent;
  uVar17 = J3DMaterial::createTexGenBlock
                     ((J3DMaterial *)(param_3 & 0xc000000 & ~-(uint)(4 < uVar5)),uVar11);
  param_1->mpTexGenBlock = (J3DTexGenBlockPatched *)((ulonglong)uVar17 >> 0x20);
  uVar17 = J3DMaterial::createTevBlock((J3DMaterial *)(uVar16 & 0xffff),(int)uVar17);
  param_1->mpTevBlock = (J3DTevBlock *)((ulonglong)uVar17 >> 0x20);
  puVar7 = (undefined *)
           J3DMaterial::createIndBlock((J3DMaterial *)(param_3 >> 0x18 & 1),(int)uVar17);
  param_1->mpIndBlock = puVar7;
  iVar12 = param_2 * 2;
  pJVar8 = J3DMaterial::createPEBlock
                     (param_3 & 0x30000000,
                      (uint)*(byte *)(*(int *)(this + 4) +
                                     (uint)*(ushort *)(*(int *)(this + 8) + iVar12) * 0x138));
  param_1->mpPEBlock = pJVar8;
  param_1->mIdx = (short)param_2;
  param_1->mMaterialMode =
       (uint)*(byte *)(*(int *)(this + 4) + (uint)*(ushort *)(*(int *)(this + 8) + iVar12) * 0x138);
  uVar9 = newColorChanNum(this,param_2);
  (*(code *)param_1->mpColorBlock->vtbl->setColorChanNum_0)(param_1->mpColorBlock,uVar9);
  uVar9 = newCullMode(this,param_2);
  (*(code *)param_1->mpColorBlock->vtbl->setCullMode_1)(param_1->mpColorBlock,uVar9);
  uVar9 = newTexGenNum(this,param_2);
  (*(code *)param_1->mpTexGenBlock->vtbl->setTexGenNum_1)(param_1->mpTexGenBlock,uVar9);
  newNBTScale((J3DMaterialFactory_v21 *)&local_50,(int)this);
  local_40 = local_50;
  local_3c = local_4c;
  local_38 = local_48;
  local_34 = local_44;
  (*(code *)param_1->mpTexGenBlock->vtbl->setNBTScale_1)(param_1->mpTexGenBlock,&local_40);
  uVar9 = newFog(this,param_2);
  (**(code **)(param_1->mpPEBlock->vtbl + 0x28))(param_1->mpPEBlock,uVar9);
  newAlphaComp((J3DMaterialFactory_v21 *)&local_74,(int)this);
  local_70 = local_74;
  (**(code **)(param_1->mpPEBlock->vtbl + 0x34))(param_1->mpPEBlock,&local_70);
  newBlend((J3DMaterialFactory_v21 *)&local_7c,(int)this);
  local_78 = local_7c;
  (**(code **)(param_1->mpPEBlock->vtbl + 0x40))(param_1->mpPEBlock,&local_78);
  newZMode((J3DMaterialFactory_v21 *)local_9c,(int)this);
  local_98[0] = local_9c[0];
  (**(code **)(param_1->mpPEBlock->vtbl + 0x4c))(param_1->mpPEBlock,local_98);
  uVar9 = newZCompLoc(this,param_2);
  (**(code **)(param_1->mpPEBlock->vtbl + 0x58))(param_1->mpPEBlock,uVar9);
  uVar9 = newDither(this,param_2);
  (**(code **)(param_1->mpPEBlock->vtbl + 100))(param_1->mpPEBlock,uVar9);
  uVar9 = newTevStageNum(this,param_2);
  (*(code *)param_1->mpTevBlock->vtbl->setTevStageNum_1)(param_1->mpTevBlock,uVar9);
  for (bVar13 = 0; bVar13 < uVar4; bVar13 = bVar13 + 1) {
    uVar9 = newTexNo(this,param_2,(uint)bVar13);
    (*(code *)param_1->mpTevBlock->vtbl->setTexNo_1)(param_1->mpTevBlock,bVar13,uVar9);
  }
  for (bVar13 = 0; bVar13 < uVar16; bVar13 = bVar13 + 1) {
    newTevOrder((J3DMaterialFactory_v21 *)&local_84,(int)this,param_2);
    local_80 = local_84;
    (*(code *)param_1->mpTevBlock->vtbl->setTevOrder_1)(param_1->mpTevBlock,bVar13,&local_80);
  }
  for (uVar4 = 0; (uVar4 & 0xff) < uVar16; uVar4 = uVar4 + 1) {
    iVar15 = *(int *)(this + 4) + (uint)*(ushort *)(iVar12 + *(int *)(this + 8)) * 0x138;
    newTevStage((J3DMaterialFactory_v21 *)&local_60,(int)this,param_2);
    local_58 = local_60;
    local_54 = local_5c;
    uVar2 = uVar4 & 0xff;
    (*(code *)param_1->mpTevBlock->vtbl->setTevStage_1)(param_1->mpTevBlock,uVar2,&local_58);
    iVar14 = uVar2 * 2 + 0xf0;
    uVar3 = (uint)*(ushort *)(iVar15 + iVar14);
    if (uVar3 != 0xffff) {
      cVar1 = *(char *)(*(int *)(this + 0x48) + uVar3 * 4 + 1);
      iVar10 = (*(code *)param_1->mpTevBlock->vtbl->getTevStage)(param_1->mpTevBlock,uVar2);
      *(byte *)(iVar10 + 7) = *(byte *)(iVar10 + 7) & 0xf3 | cVar1 << 2;
      bVar13 = *(byte *)(*(int *)(this + 0x48) + (uint)*(ushort *)(iVar15 + iVar14) * 4);
      iVar14 = (*(code *)param_1->mpTevBlock->vtbl->getTevStage)(param_1->mpTevBlock,uVar2);
      *(byte *)(iVar14 + 7) = *(byte *)(iVar14 + 7) & 0xfc | bVar13;
    }
  }
  for (bVar13 = 0; bVar13 < 4; bVar13 = bVar13 + 1) {
    newTevKColor(aJStack136,(int)this,param_2);
    (*(code *)param_1->mpTevBlock->vtbl->setTevKColor_1)(param_1->mpTevBlock,bVar13,aJStack136);
  }
  for (bVar13 = 0; bVar13 < 4; bVar13 = bVar13 + 1) {
    newTevColor(aJStack104,(int)this,param_2);
    (*(code *)param_1->mpTevBlock->vtbl->setTevColor_1)(param_1->mpTevBlock,bVar13,aJStack104);
  }
  for (bVar13 = 0; bVar13 < 4; bVar13 = bVar13 + 1) {
    newTevSwapModeTable(local_a8,(int)this,param_2);
    local_a4[0] = local_a8[0];
    (*(code *)param_1->mpTevBlock->vtbl->setTevSwapModeTable_1)(param_1->mpTevBlock,bVar13,local_a4)
    ;
  }
  for (bVar13 = 0; bVar13 < 2; bVar13 = bVar13 + 1) {
    newMatColor(aJStack140,(int)this,param_2);
    (*(code *)param_1->mpColorBlock->vtbl->setMatColor_1)(param_1->mpColorBlock,bVar13,aJStack140);
  }
  for (bVar13 = 0; bVar13 < 4; bVar13 = bVar13 + 1) {
    newColorChan((J3DMaterialFactory_v21 *)local_a0,(int)this,param_2);
    local_94[0] = local_a0[0];
    (*(code *)param_1->mpColorBlock->vtbl->setColorChan_0)(param_1->mpColorBlock,bVar13,local_94);
  }
  for (bVar13 = 0; bVar13 < uVar5; bVar13 = bVar13 + 1) {
    newTexCoord((J3DMaterialFactory_v21 *)&local_90,(int)this,param_2);
    local_6c = local_90;
    (*(code *)param_1->mpTexGenBlock->vtbl->setTexCoord)(param_1->mpTexGenBlock,bVar13,&local_6c);
  }
  for (bVar13 = 0; bVar13 < 8; bVar13 = bVar13 + 1) {
    uVar9 = newTexMtx(this,param_2,(uint)bVar13);
    (*(code *)param_1->mpTexGenBlock->vtbl->setTexMtx)(param_1->mpTexGenBlock,bVar13,uVar9);
  }
  iVar12 = *(int *)(this + 4) + (uint)*(ushort *)(*(int *)(this + 8) + iVar12) * 0x138;
  for (uVar4 = 0; (uVar4 & 0xff) < uVar16; uVar4 = uVar4 + 1) {
    if (*(char *)(iVar12 + (uVar4 & 0xff) + 0x88) == -1) {
      (*(code *)param_1->mpTevBlock->vtbl->setTevKColorSel_1)(param_1->mpTevBlock,uVar4 & 0xff,0xc);
    }
    else {
      (*(code *)param_1->mpTevBlock->vtbl->setTevKColorSel_1)();
    }
  }
  for (uVar4 = 0; (uVar4 & 0xff) < uVar16; uVar4 = uVar4 + 1) {
    if (*(char *)(iVar12 + (uVar4 & 0xff) + 0x98) == -1) {
      (*(code *)param_1->mpTevBlock->vtbl->setTevKAlphaSel_1)(param_1->mpTevBlock,uVar4 & 0xff,0x1c)
      ;
    }
    else {
      (*(code *)param_1->mpTevBlock->vtbl->setTevKAlphaSel_1)();
    }
  }
  return param_1;
}


/* __thiscall J3DMaterialFactory_v21::newMatColor(int,
                                                  int) const */

void __thiscall
J3DMaterialFactory_v21::newMatColor(J3DMaterialFactory_v21 *this,int param_1,int param_2)

{
  uint uVar1;
  J3DMaterialFactory_v21 *pJVar2;
  int in_r6;
  J3DMaterialFactory_v21 local_8;
  J3DMaterialFactory_v21 JStack7;
  J3DMaterialFactory_v21 JStack6;
  J3DMaterialFactory_v21 JStack5;
  
  JStack7 = SUB41((uint)J3DGraphLoader::_1815 >> 0x10,0);
  JStack6 = SUB41((uint)J3DGraphLoader::_1815 >> 8,0);
  JStack5 = SUB41(J3DGraphLoader::_1815,0);
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + param_2 * 2) * 0x138 + in_r6 * 2 + 8);
  if (uVar1 == 0xffff) {
    local_8 = SUB41((uint)J3DGraphLoader::_1815 >> 0x18,0);
    *this = local_8;
    this[1] = JStack7;
    this[2] = JStack6;
    this[3] = JStack5;
  }
  else {
    pJVar2 = (J3DMaterialFactory_v21 *)(*(int *)(param_1 + 0xc) + uVar1 * 4);
    *this = *pJVar2;
    this[1] = pJVar2[1];
    this[2] = pJVar2[2];
    this[3] = pJVar2[3];
  }
  return;
}


/* __thiscall J3DMaterialFactory_v21::newColorChanNum(int) const */

undefined __thiscall
J3DMaterialFactory_v21::newColorChanNum(J3DMaterialFactory_v21 *this,int param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(*(int *)(this + 4) +
                          (uint)*(ushort *)(*(int *)(this + 8) + param_1 * 2) * 0x138 + 2);
  if (uVar1 != 0xff) {
    return *(undefined *)(*(int *)(this + 0x10) + uVar1);
  }
  return 0;
}


/* __thiscall J3DMaterialFactory_v21::newColorChan(int,
                                                   int) const */

void __thiscall
J3DMaterialFactory_v21::newColorChan(J3DMaterialFactory_v21 *this,int param_1,int param_2)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  int in_r6;
  uint uVar4;
  
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + param_2 * 2) * 0x138 + in_r6 * 2 + 0xc);
  if (uVar1 != 0xffff) {
    pbVar2 = (byte *)(*(int *)(param_1 + 0x14) + uVar1 * 8);
    uVar4 = (uint)pbVar2[4];
    uVar1 = (uint)pbVar2[2];
    iVar3 = -uVar4 + 2;
    *(ushort *)this =
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
  *(ushort *)this =
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


/* __thiscall J3DMaterialFactory_v21::newTexGenNum(int) const */

undefined __thiscall J3DMaterialFactory_v21::newTexGenNum(J3DMaterialFactory_v21 *this,int param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(*(int *)(this + 4) +
                          (uint)*(ushort *)(*(int *)(this + 8) + param_1 * 2) * 0x138 + 3);
  if (uVar1 != 0xff) {
    return *(undefined *)(*(int *)(this + 0x18) + uVar1);
  }
  return 0;
}


/* __thiscall J3DMaterialFactory_v21::newTexCoord(int,
                                                  int) const */

void __thiscall
J3DMaterialFactory_v21::newTexCoord(J3DMaterialFactory_v21 *this,int param_1,int param_2)

{
  uint uVar1;
  J3DMaterialFactory_v21 *pJVar2;
  int in_r6;
  
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + param_2 * 2) * 0x138 + in_r6 * 2 + 0x14)
  ;
  if (uVar1 != 0xffff) {
    pJVar2 = (J3DMaterialFactory_v21 *)(*(int *)(param_1 + 0x1c) + uVar1 * 4);
    *this = *pJVar2;
    this[1] = pJVar2[1];
    this[2] = pJVar2[2];
    return;
  }
  *this = J3DGraphBase::j3dDefaultTexCoordInfo;
  this[1] = DAT_80370d4d;
  this[2] = DAT_80370d4e;
  return;
}


/* __thiscall J3DMaterialFactory_v21::newTexMtx(int,
                                                int) const */

undefined * __thiscall
J3DMaterialFactory_v21::newTexMtx(J3DMaterialFactory_v21 *this,int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  puVar1 = (undefined *)0x0;
  iVar5 = *(int *)(this + 4) + (uint)*(ushort *)(*(int *)(this + 8) + param_1 * 2) * 0x138 +
          param_2 * 2;
  if ((*(short *)(iVar5 + 0x34) != -1) &&
     (puVar1 = (undefined *)JKernel::operator_new(0xc4), puVar1 != (undefined *)0x0)) {
    puVar3 = (undefined *)(*(int *)(this + 0x24) + (uint)*(ushort *)(iVar5 + 0x34) * 100);
    iVar4 = 0;
    iVar5 = 0;
    do {
      iVar2 = 0;
      iVar6 = 4;
      do {
        *(undefined4 *)(puVar1 + iVar2 + 0x24 + iVar5) =
             *(undefined4 *)(puVar3 + iVar2 + 0x24 + iVar5);
        iVar2 = iVar2 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x10;
    } while (iVar4 < 4);
    *(undefined4 *)(puVar1 + 4) = *(undefined4 *)(puVar3 + 4);
    *(undefined4 *)(puVar1 + 8) = *(undefined4 *)(puVar3 + 8);
    *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(puVar3 + 0xc);
    *puVar1 = *puVar3;
    puVar1[1] = puVar3[1];
    *(undefined4 *)(puVar1 + 0x10) = *(undefined4 *)(puVar3 + 0x10);
    *(undefined4 *)(puVar1 + 0x14) = *(undefined4 *)(puVar3 + 0x14);
    *(undefined2 *)(puVar1 + 0x18) = *(undefined2 *)(puVar3 + 0x18);
    *(undefined4 *)(puVar1 + 0x1c) = *(undefined4 *)(puVar3 + 0x1c);
    *(undefined4 *)(puVar1 + 0x20) = *(undefined4 *)(puVar3 + 0x20);
  }
  return puVar1;
}


/* __thiscall J3DMaterialFactory_v21::newCullMode(int) const */

uint __thiscall J3DMaterialFactory_v21::newCullMode(J3DMaterialFactory_v21 *this,int param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(*(int *)(this + 4) +
                          (uint)*(ushort *)(*(int *)(this + 8) + param_1 * 2) * 0x138 + 1);
  if (uVar1 != 0xff) {
    return *(uint *)(*(int *)(this + 0x30) + uVar1 * 4) & 0xff;
  }
  return 0xff;
}


/* __thiscall J3DMaterialFactory_v21::newTexNo(int,
                                               int) const */

undefined2 __thiscall
J3DMaterialFactory_v21::newTexNo(J3DMaterialFactory_v21 *this,int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (uint)*(ushort *)
                 (*(int *)(this + 4) + (uint)*(ushort *)(*(int *)(this + 8) + param_1 * 2) * 0x138 +
                  param_2 * 2 + 0x70);
  if (uVar1 != 0xffff) {
    return *(undefined2 *)(*(int *)(this + 0x2c) + uVar1 * 2);
  }
  return 0xffff;
}


/* __thiscall J3DMaterialFactory_v21::newTevOrder(int,
                                                  int) const */

void __thiscall
J3DMaterialFactory_v21::newTevOrder(J3DMaterialFactory_v21 *this,int param_1,int param_2)

{
  uint uVar1;
  J3DMaterialFactory_v21 *pJVar2;
  int in_r6;
  
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + param_2 * 2) * 0x138 + in_r6 * 2 + 0xa8)
  ;
  if (uVar1 != 0xffff) {
    pJVar2 = (J3DMaterialFactory_v21 *)(*(int *)(param_1 + 0x34) + uVar1 * 4);
    *this = *pJVar2;
    this[1] = pJVar2[1];
    this[2] = pJVar2[2];
    return;
  }
  *this = J3DGraphBase::j3dDefaultTevOrderInfoNull;
  this[1] = UNK_803fc93d;
  this[2] = UNK_803fc93e;
  return;
}


/* __thiscall J3DMaterialFactory_v21::newTevColor(int,
                                                  int) const */

void __thiscall
J3DMaterialFactory_v21::newTevColor(J3DMaterialFactory_v21 *this,int param_1,int param_2)

{
  uint uVar1;
  undefined2 *puVar2;
  int in_r6;
  undefined2 local_8;
  undefined2 uStack6;
  undefined2 local_4;
  undefined2 uStack2;
  
  uStack6 = (undefined2)J3DGraphLoader::_1994;
  local_4 = (undefined2)((uint)DAT_803fcfa4 >> 0x10);
  uStack2 = (undefined2)DAT_803fcfa4;
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + param_2 * 2) * 0x138 + in_r6 * 2 + 200);
  if (uVar1 == 0xffff) {
    local_8 = (undefined2)((uint)J3DGraphLoader::_1994 >> 0x10);
    *(undefined2 *)this = local_8;
    *(undefined2 *)(this + 2) = uStack6;
    *(undefined2 *)(this + 4) = local_4;
    *(undefined2 *)(this + 6) = uStack2;
  }
  else {
    puVar2 = (undefined2 *)(*(int *)(param_1 + 0x38) + uVar1 * 8);
    *(undefined2 *)this = *puVar2;
    *(undefined2 *)(this + 2) = puVar2[1];
    *(undefined2 *)(this + 4) = puVar2[2];
    *(undefined2 *)(this + 6) = puVar2[3];
  }
  return;
}


/* __thiscall J3DMaterialFactory_v21::newTevKColor(int,
                                                   int) const */

void __thiscall
J3DMaterialFactory_v21::newTevKColor(J3DMaterialFactory_v21 *this,int param_1,int param_2)

{
  uint uVar1;
  J3DMaterialFactory_v21 *pJVar2;
  int in_r6;
  J3DMaterialFactory_v21 local_8;
  J3DMaterialFactory_v21 JStack7;
  J3DMaterialFactory_v21 JStack6;
  J3DMaterialFactory_v21 JStack5;
  
  JStack7 = SUB41((uint)J3DGraphLoader::_2015 >> 0x10,0);
  JStack6 = SUB41((uint)J3DGraphLoader::_2015 >> 8,0);
  JStack5 = SUB41(J3DGraphLoader::_2015,0);
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + param_2 * 2) * 0x138 + in_r6 * 2 + 0x80)
  ;
  if (uVar1 == 0xffff) {
    local_8 = SUB41((uint)J3DGraphLoader::_2015 >> 0x18,0);
    *this = local_8;
    this[1] = JStack7;
    this[2] = JStack6;
    this[3] = JStack5;
  }
  else {
    pJVar2 = (J3DMaterialFactory_v21 *)(*(int *)(param_1 + 0x3c) + uVar1 * 4);
    *this = *pJVar2;
    this[1] = pJVar2[1];
    this[2] = pJVar2[2];
    this[3] = pJVar2[3];
  }
  return;
}


/* __thiscall J3DMaterialFactory_v21::newTevStageNum(int) const */

undefined __thiscall
J3DMaterialFactory_v21::newTevStageNum(J3DMaterialFactory_v21 *this,int param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(*(int *)(this + 4) +
                          (uint)*(ushort *)(*(int *)(this + 8) + param_1 * 2) * 0x138 + 4);
  if (uVar1 != 0xff) {
    return *(undefined *)(*(int *)(this + 0x40) + uVar1);
  }
  return 0xff;
}


/* __thiscall J3DMaterialFactory_v21::newTevStage(int,
                                                  int) const */

void __thiscall
J3DMaterialFactory_v21::newTevStage(J3DMaterialFactory_v21 *this,int param_1,int param_2)

{
  uint uVar1;
  int in_r6;
  
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + param_2 * 2) * 0x138 + in_r6 * 2 + 0xd0)
  ;
  if (uVar1 == 0xffff) {
    J3DTevStage::J3DTevStage((J3DTevStage *)this);
  }
  else {
    J3DTevStage::J3DTevStage
              ((J3DTevStage *)this,(J3DTevStageInfo *)(*(int *)(param_1 + 0x44) + uVar1 * 0x14));
  }
  return;
}


/* __thiscall J3DMaterialFactory_v21::newTevSwapModeTable(int,
                                                          int) const */

void __thiscall
J3DMaterialFactory_v21::newTevSwapModeTable(J3DMaterialFactory_v21 *this,int param_1,int param_2)

{
  uint uVar1;
  int in_r6;
  char *pcVar2;
  
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + param_2 * 2) * 0x138 + in_r6 * 2 + 0x110
                 );
  if (uVar1 != 0xffff) {
    pcVar2 = (char *)(*(int *)(param_1 + 0x4c) + uVar1 * 4);
    *this = (J3DMaterialFactory_v21)
            (*pcVar2 * '@' + pcVar2[1] * '\x10' + pcVar2[2] * '\x04' + pcVar2[3]);
    return;
  }
  *this = (J3DMaterialFactory_v21)
          (J3DGraphBase::j3dDefaultTevSwapModeTable * '@' +
          UNK_803fc959 * '\x10' + UNK_803fc95a * '\x04' + UNK_803fc95b);
  return;
}


/* __thiscall J3DMaterialFactory_v21::newFog(int) const */

void __thiscall J3DMaterialFactory_v21::newFog(J3DMaterialFactory_v21 *this,int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(this + 4) + (uint)*(ushort *)(*(int *)(this + 8) + param_1 * 2) * 0x138;
  if (*(short *)(iVar3 + 0x130) == -1) {
    puVar1 = (undefined *)JKernel::operator_new(0x2c);
    if (puVar1 != (undefined *)0x0) {
      *puVar1 = J3DGraphBase::j3dDefaultFogInfo;
      puVar1[1] = DAT_80370e0d;
      *(undefined2 *)(puVar1 + 2) = DAT_80370e0e;
      *(undefined4 *)(puVar1 + 4) = DAT_80370e10;
      *(undefined4 *)(puVar1 + 8) = DAT_80370e14;
      *(undefined4 *)(puVar1 + 0xc) = DAT_80370e18;
      *(undefined4 *)(puVar1 + 0x10) = DAT_80370e1c;
      puVar1[0x14] = DAT_80370e20;
      puVar1[0x15] = DAT_80370e21;
      puVar1[0x16] = DAT_80370e22;
      puVar1[0x17] = DAT_80370e23;
      iVar3 = 0;
      iVar4 = 10;
      do {
        *(undefined2 *)(puVar1 + iVar3 + 0x18) = *(undefined2 *)((int)&DAT_80370e24 + iVar3);
        iVar3 = iVar3 + 2;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  else {
    puVar1 = (undefined *)JKernel::operator_new(0x2c);
    if (puVar1 != (undefined *)0x0) {
      puVar2 = (undefined *)(*(int *)(this + 0x50) + (uint)*(ushort *)(iVar3 + 0x130) * 0x2c);
      *puVar1 = *puVar2;
      puVar1[1] = puVar2[1];
      *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(puVar2 + 2);
      *(undefined4 *)(puVar1 + 4) = *(undefined4 *)(puVar2 + 4);
      *(undefined4 *)(puVar1 + 8) = *(undefined4 *)(puVar2 + 8);
      *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(puVar2 + 0xc);
      *(undefined4 *)(puVar1 + 0x10) = *(undefined4 *)(puVar2 + 0x10);
      puVar1[0x14] = puVar2[0x14];
      puVar1[0x15] = puVar2[0x15];
      puVar1[0x16] = puVar2[0x16];
      puVar1[0x17] = puVar2[0x17];
      iVar3 = 0;
      iVar4 = 10;
      do {
        *(undefined2 *)(puVar1 + iVar3 + 0x18) = *(undefined2 *)(puVar2 + iVar3 + 0x18);
        iVar3 = iVar3 + 2;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  return;
}


/* __thiscall J3DMaterialFactory_v21::newAlphaComp(int) const */

void __thiscall J3DMaterialFactory_v21::newAlphaComp(J3DMaterialFactory_v21 *this,int param_1)

{
  uint uVar1;
  int in_r5;
  byte *pbVar2;
  
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + in_r5 * 2) * 0x138 + 0x132);
  if (uVar1 != 0xffff) {
    pbVar2 = (byte *)(*(int *)(param_1 + 0x54) + uVar1 * 8);
    *(ushort *)this = (ushort)*pbVar2 * 0x20 + (ushort)pbVar2[2] * 8 + (ushort)pbVar2[3];
    this[2] = *(J3DMaterialFactory_v21 *)(pbVar2 + 1);
    this[3] = *(J3DMaterialFactory_v21 *)(pbVar2 + 4);
    return;
  }
  *(undefined2 *)this = 0xffff;
  this[2] = (J3DMaterialFactory_v21)0x0;
  this[3] = (J3DMaterialFactory_v21)0x0;
  return;
}


/* __thiscall J3DMaterialFactory_v21::newBlend(int) const */

void __thiscall J3DMaterialFactory_v21::newBlend(J3DMaterialFactory_v21 *this,int param_1)

{
  uint uVar1;
  J3DMaterialFactory_v21 *pJVar2;
  int in_r5;
  
  uVar1 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + in_r5 * 2) * 0x138 + 0x134);
  if (uVar1 != 0xffff) {
    pJVar2 = (J3DMaterialFactory_v21 *)(*(int *)(param_1 + 0x58) + uVar1 * 4);
    *this = *pJVar2;
    this[1] = pJVar2[1];
    this[2] = pJVar2[2];
    this[3] = pJVar2[3];
    return;
  }
  *this = J3DGraphBase::j3dDefaultBlendInfo;
  this[1] = UNK_803fc95d;
  this[2] = UNK_803fc95e;
  this[3] = UNK_803fc95f;
  return;
}


/* __thiscall J3DMaterialFactory_v21::newZMode(int) const */

void __thiscall J3DMaterialFactory_v21::newZMode(J3DMaterialFactory_v21 *this,int param_1)

{
  uint uVar1;
  byte *pbVar2;
  int in_r5;
  
  uVar1 = (uint)*(byte *)(*(int *)(param_1 + 4) +
                          (uint)*(ushort *)(*(int *)(param_1 + 8) + in_r5 * 2) * 0x138 + 6);
  if (uVar1 != 0xff) {
    pbVar2 = (byte *)(*(int *)(param_1 + 0x5c) + uVar1 * 4);
    *(ushort *)this = (ushort)pbVar2[1] * 2 + (ushort)*pbVar2 * 0x10 + (ushort)pbVar2[2];
    return;
  }
  *(undefined2 *)this = J3DGraphBase::j3dDefaultZModeID;
  return;
}


/* __thiscall J3DMaterialFactory_v21::newZCompLoc(int) const */

undefined __thiscall J3DMaterialFactory_v21::newZCompLoc(J3DMaterialFactory_v21 *this,int param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(*(int *)(this + 4) +
                          (uint)*(ushort *)(*(int *)(this + 8) + param_1 * 2) * 0x138 + 5);
  if (uVar1 != 0xff) {
    return *(undefined *)(*(int *)(this + 0x60) + uVar1);
  }
  return 0;
}


/* __thiscall J3DMaterialFactory_v21::newDither(int) const */

undefined __thiscall J3DMaterialFactory_v21::newDither(J3DMaterialFactory_v21 *this,int param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(*(int *)(this + 4) +
                          (uint)*(ushort *)(*(int *)(this + 8) + param_1 * 2) * 0x138 + 7);
  if (uVar1 != 0xff) {
    return *(undefined *)(*(int *)(this + 100) + uVar1);
  }
  return 1;
}


/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall J3DMaterialFactory_v21::newNBTScale(int) const */

void __thiscall J3DMaterialFactory_v21::newNBTScale(J3DMaterialFactory_v21 *this,int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  J3DMaterialFactory_v21 *pJVar5;
  int in_r5;
  undefined4 local_18;
  
  uVar3 = DAT_80370e44;
  uVar2 = DAT_80370e40;
  uVar1 = DAT_80370e3c;
  local_18 = CONCAT13(J3DGraphBase::j3dDefaultNBTScaleInfo,local_18._1_3_);
  uVar4 = (uint)*(ushort *)
                 (*(int *)(param_1 + 4) +
                  (uint)*(ushort *)(*(int *)(param_1 + 8) + in_r5 * 2) * 0x138 + 0x136);
  if (uVar4 == 0xffff) {
    *(undefined4 *)this = local_18;
    *(undefined4 *)(this + 4) = uVar1;
    *(undefined4 *)(this + 8) = uVar2;
    *(undefined4 *)(this + 0xc) = uVar3;
  }
  else {
    pJVar5 = (J3DMaterialFactory_v21 *)(*(int *)(param_1 + 0x68) + uVar4 * 0x10);
    *this = *pJVar5;
    *(undefined4 *)(this + 4) = *(undefined4 *)(pJVar5 + 4);
    *(undefined4 *)(this + 8) = *(undefined4 *)(pJVar5 + 8);
    *(undefined4 *)(this + 0xc) = *(undefined4 *)(pJVar5 + 0xc);
  }
  return;
}


namespace J3DGraphLoader {

/* __stdcall JSUConvertOffsetToPtr<J3DMaterialInitData_v21>(void const *,
                                                            void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}

