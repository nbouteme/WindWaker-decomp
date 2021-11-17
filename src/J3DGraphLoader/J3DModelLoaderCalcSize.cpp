#include <J3DGraphLoader/J3DModelLoaderCalcSize.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J3DGraphLoader/J3DModelLoaderCalcSize.h>
#include <m_Do_printf.h>
#include <J3DGraphLoader/J3DModelLoader.h>
#include <J3DGraphLoader/J3DMaterialFactory.h>
#include <J3DGraphLoader/J3DShapeFactory.h>
#include <J3DModelLoader.h>
#include <J3DModelLoader_v26.h>


/* __thiscall J3DModelLoader::countMaterialNum(void const *) */

undefined2 __thiscall J3DModelLoader::countMaterialNum(J3DModelLoader *this,void *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)((int)param_1 + 0x20);
  iVar1 = *(int *)((int)param_1 + 0xc);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (*piVar2 == 0x4d415433) break;
    piVar2 = (int *)((int)piVar2 + piVar2[1]);
    iVar1 = iVar1 + -1;
  }
  return *(undefined2 *)(piVar2 + 2);
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall J3DModelLoader::calcLoadSize(void const *,
                                           unsigned long) */

int __thiscall J3DModelLoader::calcLoadSize(J3DModelLoader *this,void *param_1,ulong param_2)

{
  int iVar1;
  uint uVar2;
  J3DTextureBlock *pJVar3;
  int iVar4;
  
  pJVar3 = (J3DTextureBlock *)((int)param_1 + 0x20);
  uVar2 = 0;
  iVar4 = 0xe4;
  do {
    if (*(uint *)((int)param_1 + 0xc) <= uVar2) {
      return iVar4;
    }
    iVar1 = *(int *)pJVar3;
    if (iVar1 != 0x4d415432) {
      if (iVar1 < 0x4d415432) {
        if (iVar1 == 0x494e4631) {
          iVar1 = calcSizeInformation(this,(J3DModelInfoBlock *)pJVar3,param_2);
          iVar4 = iVar4 + iVar1;
        }
        else {
          if (iVar1 < 0x494e4631) {
            if ((iVar1 != 0x45565031) && ((0x45565030 < iVar1 || (iVar1 != 0x44525731)))) {
LAB_802fd9cc:
              m_Do_printf::OSReport("Unknown data block\n");
            }
          }
          else {
            if (iVar1 != 0x4a4e5431) goto LAB_802fd9cc;
            iVar1 = calcSizeJoint(this,(J3DJointBlock *)pJVar3);
            iVar4 = iVar4 + iVar1;
          }
        }
      }
      else {
        if (iVar1 == 0x54455831) {
          iVar1 = calcSizeTexture(this,pJVar3);
          iVar4 = iVar4 + iVar1;
        }
        else {
          if (iVar1 < 0x54455831) {
            if (iVar1 == 0x53485031) {
              iVar1 = calcSizeShape(this,(J3DShapeBlock *)pJVar3,param_2);
              iVar4 = iVar4 + iVar1;
            }
            else {
              if ((0x53485030 < iVar1) || (0x4d415433 < iVar1)) goto LAB_802fd9cc;
              iVar1 = (**(code **)(this->vtbl + 0x3c))(this,pJVar3,param_2);
              iVar4 = iVar4 + iVar1;
            }
          }
          else {
            if (iVar1 != 0x56545831) goto LAB_802fd9cc;
          }
        }
      }
    }
    pJVar3 = (J3DTextureBlock *)(&pJVar3->field_0x0 + *(int *)&pJVar3->field_0x4);
    uVar2 = uVar2 + 1;
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall J3DModelLoader::calcLoadMaterialTableSize(void const *) */

int __thiscall J3DModelLoader::calcLoadMaterialTableSize(J3DModelLoader *this,void *param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  J3DTextureBlock *pJVar4;
  int iVar5;
  
  pJVar4 = (J3DTextureBlock *)((int)param_1 + 0x20);
  bVar1 = false;
  uVar3 = 0;
  iVar5 = 0x24;
  do {
    if (*(uint *)((int)param_1 + 0xc) <= uVar3) {
      if (!bVar1) {
        iVar5 = iVar5 + 0xc;
      }
      return iVar5;
    }
    iVar2 = *(int *)pJVar4;
    if (iVar2 == 0x4d415433) {
      iVar2 = (**(code **)(this->vtbl + 0x40))(this,pJVar4,0x51100000);
      iVar5 = iVar5 + iVar2;
    }
    else {
      if (iVar2 < 0x4d415433) {
        if (iVar2 < 0x4d415432) {
LAB_802fdabc:
          m_Do_printf::OSReport("Unknown data block\n");
        }
      }
      else {
        if (iVar2 != 0x54455831) goto LAB_802fdabc;
        iVar2 = calcSizeTextureTable(this,pJVar4);
        iVar5 = iVar5 + iVar2;
        bVar1 = true;
      }
    }
    pJVar4 = (J3DTextureBlock *)(&pJVar4->field_0x0 + *(int *)&pJVar4->field_0x4);
    uVar3 = uVar3 + 1;
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* __thiscall J3DModelLoader::calcLoadBinaryDisplayListSize(void const *,
                                                            unsigned long) */

int __thiscall
J3DModelLoader::calcLoadBinaryDisplayListSize(J3DModelLoader *this,void *param_1,ulong param_2)

{
  int iVar1;
  uint uVar2;
  J3DTextureBlock *pJVar3;
  int iVar4;
  
  pJVar3 = (J3DTextureBlock *)((int)param_1 + 0x20);
  uVar2 = 0;
  iVar4 = 0xe4;
  do {
    if (*(uint *)((int)param_1 + 0xc) <= uVar2) {
      return iVar4;
    }
    iVar1 = *(int *)pJVar3;
    if (iVar1 == 0x4d415433) {
      *(J3DTextureBlock **)&this->field_0x10 = pJVar3;
      if ((param_2 & 0x3000) == 0) {
        *(undefined *)&this->field_0x18 = 1;
        iVar1 = (**(code **)(this->vtbl + 0x3c))(this,pJVar3);
        iVar4 = iVar4 + iVar1;
      }
      else {
        if ((param_2 & 0x3000) == 0x2000) {
          *(undefined *)&this->field_0x18 = 1;
          iVar1 = calcSizePatchedMaterial
                            (this,(J3DMaterialBlock *)pJVar3,param_2 & 0x3000000 | 0x50100000);
          iVar4 = iVar4 + iVar1;
        }
      }
    }
    else {
      if (iVar1 < 0x4d415433) {
        if (iVar1 == 0x494e4631) {
          iVar1 = calcSizeInformation(this,(J3DModelInfoBlock *)pJVar3,param_2);
          iVar4 = iVar4 + iVar1;
        }
        else {
          if (iVar1 < 0x494e4631) {
            if ((iVar1 != 0x45565031) && ((0x45565030 < iVar1 || (iVar1 != 0x44525731)))) {
LAB_802fdce4:
              m_Do_printf::OSReport("Unknown data block\n");
            }
          }
          else {
            if (iVar1 == 0x4a4e5431) {
              iVar1 = calcSizeJoint(this,(J3DJointBlock *)pJVar3);
              iVar4 = iVar4 + iVar1;
            }
            else {
              if ((iVar1 < 0x4a4e5431) || (iVar1 < 0x4d415432)) goto LAB_802fdce4;
            }
          }
        }
      }
      else {
        if (iVar1 == 0x54455831) {
          iVar1 = calcSizeTexture(this,pJVar3);
          iVar4 = iVar4 + iVar1;
        }
        else {
          if (iVar1 < 0x54455831) {
            if (iVar1 == 0x53485031) {
              iVar1 = calcSizeShape(this,(J3DShapeBlock *)pJVar3,param_2);
              iVar4 = iVar4 + iVar1;
            }
            else {
              if ((0x53485030 < iVar1) || (iVar1 != 0x4d444c33)) goto LAB_802fdce4;
              iVar1 = calcSizeMaterialDL(this,(J3DMaterialDLBlock *)pJVar3,param_2);
              iVar4 = iVar4 + iVar1;
            }
          }
          else {
            if (iVar1 != 0x56545831) goto LAB_802fdce4;
          }
        }
      }
    }
    pJVar3 = (J3DTextureBlock *)(&pJVar3->field_0x0 + *(int *)&pJVar3->field_0x4);
    uVar2 = uVar2 + 1;
  } while( true );
}


/* WARNING: Removing unreachable block (ram,0x802fdd64) */
/* __thiscall J3DModelLoader::calcSizeInformation(J3DModelInfoBlock const *,
                                                  unsigned long) */

undefined4 __thiscall
J3DModelLoader::calcSizeInformation(J3DModelLoader *this,J3DModelInfoBlock *param_1,ulong param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar1 = (param_2 | *(ushort *)(param_1 + 8)) & 0xf;
  if (uVar1 == 1) {
    uVar3 = 0x78;
  }
  else {
    if (uVar1 == 0) {
      uVar3 = 0x78;
    }
    else {
      if (uVar1 < 3) {
        uVar3 = 0x78;
      }
    }
  }
  uVar2 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x14));
  *(undefined4 *)&this->field_0x14 = uVar2;
  return uVar3;
}


/* __thiscall J3DModelLoader::calcSizeJoint(J3DJointBlock const *) */

int __thiscall J3DModelLoader::calcSizeJoint(J3DModelLoader *this,J3DJointBlock *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1->field_0x14 != 0) {
    iVar1 = 0x10;
  }
  return iVar1 + (uint)(ushort)param_1->field_0x8 * 0x68;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DModelLoader_v26::calcSizeMaterial(J3DMaterialBlock const *,
                                                   unsigned long) */

int __thiscall
J3DModelLoader_v26::calcSizeMaterial
          (J3DModelLoader_v26 *this,J3DMaterialBlock *param_1,ulong param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  J3DMaterialFactory aJStack168 [12];
  
  iVar5 = 0;
  J3DMaterialFactory::J3DMaterialFactory(aJStack168,param_1);
  uVar1 = *(ushort *)(param_1 + 8);
  uVar2 = J3DMaterialFactory::countUniqueMaterials(aJStack168);
  if (*(int *)(param_1 + 0x14) != 0) {
    iVar5 = 0x10;
  }
  iVar5 = iVar5 + (uint)uVar1 * 4;
  if ((param_2 & 0x200000) != 0) {
    iVar5 = iVar5 + ((uVar2 & 0xffff) * 0x4c + 0x1f & 0xffffffe0);
    for (uVar4 = 0; uVar4 < (uVar2 & 0xffff); uVar4 = uVar4 + 1) {
      iVar3 = J3DMaterialFactory::calcSize(aJStack168,(J3DMaterial *)0x0,0,uVar4,param_2);
      iVar5 = iVar5 + iVar3;
    }
  }
  for (uVar2 = 0; uVar2 < uVar1; uVar2 = uVar2 + 1) {
    iVar3 = J3DMaterialFactory::calcSize(aJStack168,(J3DMaterial *)0x0,0,uVar2,param_2);
    iVar5 = iVar5 + iVar3;
  }
  return iVar5;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DModelLoader::calcSizeShape(J3DShapeBlock const *,
                                            unsigned long) */

int __thiscall
J3DModelLoader::calcSizeShape(J3DModelLoader *this,J3DShapeBlock *param_1,ulong param_2)

{
  ushort uVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  J3DShapeFactory aJStack56 [40];
  
  iVar4 = 0;
  J3DShapeFactory::J3DShapeFactory(aJStack56,param_1);
  uVar1 = *(ushort *)(param_1 + 8);
  if (*(int *)(param_1 + 0x14) != 0) {
    iVar4 = 0x10;
  }
  iVar2 = J3DShapeFactory::calcSizeVcdVatCmdBuffer(aJStack56,(uint)uVar1);
  iVar2 = iVar4 + (uint)uVar1 * 4 + iVar2;
  for (psVar3 = *(short **)&this->field_0x14; *psVar3 != 0; psVar3 = psVar3 + 2) {
    if (*psVar3 == 0x12) {
      iVar4 = J3DShapeFactory::calcSize(aJStack56,(uint)(ushort)psVar3[1],param_2);
      iVar2 = iVar2 + iVar4;
    }
  }
  return iVar2;
}


/* __thiscall J3DModelLoader::calcSizeTexture(J3DTextureBlock const *) */

int __thiscall J3DModelLoader::calcSizeTexture(J3DModelLoader *this,J3DTextureBlock *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1->mTexNamTabOffs != 0) {
    iVar1 = 0x10;
  }
  return iVar1 + 0xc;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DModelLoader_v26::calcSizeMaterialTable(J3DMaterialBlock const *,
                                                        unsigned long) */

int __thiscall
J3DModelLoader_v26::calcSizeMaterialTable
          (J3DModelLoader_v26 *this,J3DMaterialBlock *param_1,ulong param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  J3DMaterialFactory aJStack152 [11];
  
  iVar4 = 0;
  uVar1 = *(ushort *)(param_1 + 8);
  J3DMaterialFactory::J3DMaterialFactory(aJStack152,param_1);
  if (*(int *)(param_1 + 0x14) != 0) {
    iVar4 = 0x10;
  }
  iVar4 = iVar4 + (uint)uVar1 * 4;
  for (uVar3 = 0; (uVar3 & 0xffff) < (uint)uVar1; uVar3 = uVar3 + 1) {
    iVar2 = J3DMaterialFactory::calcSize(aJStack152,(J3DMaterial *)0x0,0,uVar3 & 0xffff,param_2);
    iVar4 = iVar4 + iVar2;
  }
  return iVar4;
}


/* __thiscall J3DModelLoader::calcSizeTextureTable(J3DTextureBlock const *) */

void __thiscall J3DModelLoader::calcSizeTextureTable(J3DModelLoader *this,J3DTextureBlock *param_1)

{
  calcSizeTexture(this,param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DModelLoader::calcSizePatchedMaterial(J3DMaterialBlock const *,
                                                      unsigned long) */

int __thiscall
J3DModelLoader::calcSizePatchedMaterial
          (J3DModelLoader *this,J3DMaterialBlock *param_1,ulong param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  J3DMaterialFactory aJStack152 [11];
  
  iVar4 = 0;
  uVar1 = *(ushort *)(param_1 + 8);
  J3DMaterialFactory::J3DMaterialFactory(aJStack152,param_1);
  if (*(int *)(param_1 + 0x14) != 0) {
    iVar4 = 0x10;
  }
  iVar4 = iVar4 + (uint)uVar1 * 4;
  for (uVar3 = 0; (uVar3 & 0xffff) < (uint)uVar1; uVar3 = uVar3 + 1) {
    iVar2 = J3DMaterialFactory::calcSize(aJStack152,(J3DMaterial *)0x0,2,uVar3 & 0xffff,param_2);
    iVar4 = iVar4 + iVar2;
  }
  return iVar4;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DModelLoader::calcSizeMaterialDL(J3DMaterialDLBlock const *,
                                                 unsigned long) */

int __thiscall
J3DModelLoader::calcSizeMaterialDL(J3DModelLoader *this,J3DMaterialDLBlock *param_1,ulong param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  J3DMaterialFactory aJStack168 [12];
  
  iVar4 = 0;
  J3DMaterialFactory::J3DMaterialFactory(aJStack168,param_1);
  if (*(char *)&this->field_0x18 == '\0') {
    uVar1 = *(ushort *)(param_1 + 8);
    if (*(int *)(param_1 + 0x20) != 0) {
      iVar4 = 0x10;
    }
    iVar4 = iVar4 + (uint)uVar1 * 4;
    for (uVar3 = 0; (uVar3 & 0xffff) < (uint)uVar1; uVar3 = uVar3 + 1) {
      iVar2 = J3DMaterialFactory::calcSize(aJStack168,(J3DMaterial *)0x0,1,uVar3 & 0xffff,param_2);
      iVar4 = iVar4 + iVar2;
    }
  }
  else {
    uVar1 = *(ushort *)(param_1 + 8);
    for (uVar3 = 0; (uVar3 & 0xffff) < (uint)uVar1; uVar3 = uVar3 + 1) {
      iVar2 = J3DMaterialFactory::calcSize(aJStack168,(J3DMaterial *)this,1,uVar3 & 0xffff,param_2);
      iVar4 = iVar4 + iVar2;
    }
  }
  return iVar4;
}

