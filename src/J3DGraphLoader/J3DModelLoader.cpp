#include <J3DGraphLoader/J3DModelLoader.h>
#include <J3DGraphLoader/J3DModelLoader.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <J3DGraphAnimator/J3DModelData.h>
#include <m_Do_printf.h>
#include <J3DGraphAnimator/J3DMaterialAttach.h>
#include <J3DGraphAnimator/J3DJoint.h>
#include <J3DGraphLoader/J3DMaterialFactory.h>
#include <J3DGraphLoader/J3DClusterLoader.h>
#include <J3DGraphLoader/J3DJointFactory.h>
#include <JUtility/JUTNameTab.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <J3DGraphLoader/J3DMaterialFactory_v21.h>
#include <J3DGraphLoader/J3DShapeFactory.h>
#include <J3DGraphBase/J3DMaterial.h>
#include <Demangler/J3DMaterial.h>
#include <J3DModelLoaderDataBase.h>
#include <J3DModelLoader.h>
#include <J3DTexture.h>
#include <J3DModelLoader_v26.h>
#include <J3DModelLoader_v21.h>


namespace J3DModelLoaderDataBase {

/* __thiscall load(void const *,
                                           unsigned long) */

undefined4 load(void *param_1,ulong param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined local_38 [20];
  undefined4 local_24;
  undefined local_20;
  undefined local_1c [20];
  undefined4 local_8;
  undefined local_4;
  
  if (param_1 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    iVar2 = *param_1;
    if ((iVar2 == 0x4a334431) && (*(int *)((int)param_1 + 4) == 0x626d6431)) {
      uVar1 = 0;
    }
    else {
      if ((iVar2 == 0x4a334432) && (*(int *)((int)param_1 + 4) == 0x626d6432)) {
        local_1c._4_4_ = (J3DModelData *)0x0;
        local_1c._8_4_ = (J3DMaterialTable *)0x0;
        local_1c._12_4_ = (J3DShapeBlock *)0x0;
        local_1c._16_4_ = 0;
        local_8 = 0;
        local_4 = 0;
        local_1c._0_4_ = &J3DModelLoader_v21::__vt;
        uVar1 = J3DModelLoader::load((J3DModelLoader *)local_1c,param_1,param_2);
      }
      else {
        if ((iVar2 == 0x4a334432) && (*(int *)((int)param_1 + 4) == 0x626d6433)) {
          local_38._4_4_ = (J3DModelData *)0x0;
          local_38._8_4_ = (J3DMaterialTable *)0x0;
          local_38._12_4_ = (J3DShapeBlock *)0x0;
          local_38._16_4_ = 0;
          local_24 = 0;
          local_20 = 0;
          local_38._0_4_ = &J3DModelLoader_v26::__vt;
          uVar1 = J3DModelLoader::load((J3DModelLoader *)local_38,param_1,param_2);
        }
        else {
          uVar1 = 0;
        }
      }
    }
  }
  return uVar1;
}

}

/* __thiscall J3DModelLoaderDataBase::loadMaterialTable(void const *) */

undefined4 __thiscall
J3DModelLoaderDataBase::loadMaterialTable(J3DModelLoaderDataBase *this,void *param_1)

{
  undefined4 uVar1;
  undefined local_28 [20];
  undefined4 local_14;
  undefined local_10;
  
  if (this == (J3DModelLoaderDataBase *)0x0) {
    uVar1 = 0;
  }
  else {
    if ((*(int *)this == 0x4a334432) && (*(int *)(this + 4) == 0x626d7433)) {
      local_28._4_4_ = (J3DModelData *)0x0;
      local_28._8_4_ = (J3DMaterialTable *)0x0;
      local_28._12_4_ = (J3DShapeBlock *)0x0;
      local_28._16_4_ = 0;
      local_14 = 0;
      local_10 = 0;
      local_28._0_4_ = &J3DModelLoader_v26::__vt;
      uVar1 = J3DModelLoader::loadMaterialTable((J3DModelLoader *)local_28,this);
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


namespace J3DModelLoaderDataBase {

/* __thiscall loadBinaryDisplayList(void const *,
                                                            unsigned long) */

undefined4 loadBinaryDisplayList(void *param_1,ulong param_2)

{
  undefined4 uVar1;
  J3DModelLoader *local_28;
  J3DModelData *local_24;
  J3DMaterialTable *local_20;
  J3DShapeBlock *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined local_10;
  
  if (param_1 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if ((*param_1 == 0x4a334432) &&
       ((*(int *)((int)param_1 + 4) == 0x62646c33 || (*(int *)((int)param_1 + 4) == 0x62646c34)))) {
      local_24 = (J3DModelData *)0x0;
      local_20 = (J3DMaterialTable *)0x0;
      local_1c = (J3DShapeBlock *)0x0;
      local_18 = 0;
      local_14 = 0;
      local_10 = 0;
      local_28 = (J3DModelLoader *)&J3DModelLoader_v26::__vt;
      uVar1 = J3DModelLoader::loadBinaryDisplayList((J3DModelLoader *)&local_28,param_1,param_2);
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

}

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall J3DModelLoader::load(void const *,
                                   unsigned long) */

J3DModelData * __thiscall J3DModelLoader::load(J3DModelLoader *this,void *param_1,ulong param_2)

{
  J3DModelData *pJVar1;
  J3DShape *pJVar2;
  int iVar3;
  ushort uVar4;
  uint uVar5;
  J3DVertexBlock *pJVar6;
  J3DModelHierarchy *local_28 [4];
  
  JKRHeap::getTotalFreeSize(JKRHeap::sCurrentHeap);
  pJVar1 = (J3DModelData *)JKernel::operator_new(0xe4);
  if (pJVar1 != (J3DModelData *)0x0) {
    J3DModelData::J3DModelData(pJVar1);
  }
  this->mpModelData = pJVar1;
  J3DModelData::clear(this->mpModelData);
  this->mpModelData->mpData = param_1;
  (this->mpModelData->mJointTree).mbIsBDL = 0;
  this->mpMaterialTable = &this->mpModelData->mMaterialTable;
  pJVar6 = (J3DVertexBlock *)((int)param_1 + 0x20);
  uVar5 = 0;
  do {
    if (*(uint *)((int)param_1 + 0xc) <= uVar5) {
      local_28[0] = (this->mpModelData->mJointTree).mpHierarchy;
      pJVar1 = this->mpModelData;
      J3DJointTree::makeHierarchy
                (&pJVar1->mJointTree,(J3DJoint *)0x0,local_28,&pJVar1->mMaterialTable,
                 (J3DShape **)(pJVar1->mShapeTable).mpShapes);
      J3DModelData::initShapeNodes(pJVar1);
      J3DModelData::sortVcdVatCmd(this->mpModelData);
      (**(code **)(this->vtbl + 0x24))(this);
      if ((this->mpModelData->mLoadArgs & 0x100U) != 0) {
        for (uVar4 = 0; uVar4 < (this->mpModelData->mShapeTable).mShapeCount; uVar4 = uVar4 + 1) {
          pJVar2 = (this->mpModelData->mShapeTable).mpShapes[uVar4];
          pJVar2->mVisFlags = pJVar2->mVisFlags | 0x200;
        }
      }
      return this->mpModelData;
    }
    iVar3 = *(int *)pJVar6->mMagic;
    if (iVar3 == 0x4d415432) {
      (**(code **)(this->vtbl + 0x30))(this,pJVar6,param_2);
    }
    else {
      if (iVar3 < 0x4d415432) {
        if (iVar3 == 0x494e4631) {
          readInformation(this,(J3DModelInfoBlock *)pJVar6,param_2);
        }
        else {
          if (iVar3 < 0x494e4631) {
            if (iVar3 == 0x45565031) {
              readEnvelop(this,(J3DEnvelopBlock *)pJVar6);
            }
            else {
              if ((0x45565030 < iVar3) || (iVar3 != 0x44525731)) goto LAB_802fbbec;
              readDraw(this,(J3DDrawBlock *)pJVar6);
            }
          }
          else {
            if (iVar3 == 0x4a4e5431) {
              readJoint(this,(J3DJointBlock *)pJVar6);
            }
            else {
LAB_802fbbec:
              m_Do_printf::OSReport("Unknown data block\n");
            }
          }
        }
      }
      else {
        if (iVar3 == 0x54455831) {
          readTexture(this,(J3DTextureBlock *)pJVar6);
        }
        else {
          if (iVar3 < 0x54455831) {
            if (iVar3 == 0x53485031) {
              readShape(this,(J3DShapeBlock *)pJVar6,param_2);
            }
            else {
              if ((0x53485030 < iVar3) || (0x4d415433 < iVar3)) goto LAB_802fbbec;
              (**(code **)(this->vtbl + 0x2c))(this,pJVar6,param_2);
            }
          }
          else {
            if (iVar3 != 0x56545831) goto LAB_802fbbec;
            readVertex(this,pJVar6);
          }
        }
      }
    }
    pJVar6 = (J3DVertexBlock *)(pJVar6->mMagic + pJVar6->mSize);
    uVar5 = uVar5 + 1;
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DModelLoader::loadMaterialTable(void const *) */

J3DMaterialTable * __thiscall J3DModelLoader::loadMaterialTable(J3DModelLoader *this,void *param_1)

{
  J3DMaterialTable *this_00;
  J3DTexture *pJVar1;
  int iVar2;
  uint uVar3;
  J3DTextureBlock *pJVar4;
  
  this_00 = (J3DMaterialTable *)JKernel::operator_new(0x24);
  if (this_00 != (J3DMaterialTable *)0x0) {
    J3DMaterialTable::J3DMaterialTable(this_00);
  }
  this->mpMaterialTable = this_00;
  J3DMaterialTable::clear(this->mpMaterialTable);
  pJVar4 = (J3DTextureBlock *)((int)param_1 + 0x20);
  uVar3 = 0;
  do {
    if (*(uint *)((int)param_1 + 0xc) <= uVar3) {
      if (this->mpMaterialTable->mpTexture == (J3DTexture *)0x0) {
        pJVar1 = (J3DTexture *)JKernel::operator_new(0xc);
        if (pJVar1 != (J3DTexture *)0x0) {
          pJVar1->vtbl = (undefined *)&J3DTexture::__vt;
          pJVar1->mCount = 0;
          pJVar1->mpTexData = (ResTIMG *)0x0;
        }
        this->mpMaterialTable->mpTexture = pJVar1;
      }
      return this->mpMaterialTable;
    }
    iVar2 = *(int *)pJVar4;
    if (iVar2 == 0x4d415433) {
      (**(code **)(this->vtbl + 0x34))(this,pJVar4,0x51100000);
    }
    else {
      if (iVar2 < 0x4d415433) {
        if (iVar2 < 0x4d415432) {
LAB_802fbda0:
          m_Do_printf::OSReport("Unknown data block\n");
        }
        else {
          (**(code **)(this->vtbl + 0x38))(this,pJVar4,0x51100000);
        }
      }
      else {
        if (iVar2 != 0x54455831) goto LAB_802fbda0;
        readTextureTable(this,pJVar4);
      }
    }
    pJVar4 = (J3DTextureBlock *)(&pJVar4->field_0x0 + *(int *)&pJVar4->field_0x4);
    uVar3 = uVar3 + 1;
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall J3DModelLoader::loadBinaryDisplayList(void const *,
                                                    unsigned long) */

J3DModelData * __thiscall
J3DModelLoader::loadBinaryDisplayList(J3DModelLoader *this,void *param_1,ulong loadArgs)

{
  J3DModelData *pJVar1;
  int iVar2;
  uint uVar3;
  J3DVertexBlock *pJVar4;
  J3DModelHierarchy *local_28 [2];
  
  pJVar1 = (J3DModelData *)JKernel::operator_new(0xe4);
  if (pJVar1 != (J3DModelData *)0x0) {
    J3DModelData::J3DModelData(pJVar1);
  }
  this->mpModelData = pJVar1;
  J3DModelData::clear(this->mpModelData);
  this->mpModelData->mpData = param_1;
  (this->mpModelData->mJointTree).mbIsBDL = 1;
  this->mpMaterialTable = &this->mpModelData->mMaterialTable;
  pJVar4 = (J3DVertexBlock *)((int)param_1 + 0x20);
  uVar3 = 0;
  do {
    if (*(uint *)((int)param_1 + 0xc) <= uVar3) {
      local_28[0] = (this->mpModelData->mJointTree).mpHierarchy;
      pJVar1 = this->mpModelData;
      J3DJointTree::makeHierarchy
                (&pJVar1->mJointTree,(J3DJoint *)0x0,local_28,&pJVar1->mMaterialTable,
                 (J3DShape **)(pJVar1->mShapeTable).mpShapes);
      J3DModelData::initShapeNodes(pJVar1);
      J3DModelData::sortVcdVatCmd(this->mpModelData);
      (**(code **)(this->vtbl + 0x24))(this);
      J3DModelData::indexToPtr(this->mpModelData);
      return this->mpModelData;
    }
    iVar2 = *(int *)pJVar4->mMagic;
    if (iVar2 == 0x4d415433) {
      *(J3DVertexBlock **)&this->field_0x10 = pJVar4;
      if ((loadArgs & 0x3000) == 0) {
        (**(code **)(this->vtbl + 0x2c))(this,pJVar4);
      }
      else {
        if ((loadArgs & 0x3000) == 0x2000) {
          readPatchedMaterial(this,(J3DMaterialBlock *)pJVar4,loadArgs & 0x3000000 | 0x50100000);
        }
      }
    }
    else {
      if (iVar2 < 0x4d415433) {
        if (iVar2 == 0x494e4631) {
          readInformation(this,(J3DModelInfoBlock *)pJVar4,loadArgs);
        }
        else {
          if (iVar2 < 0x494e4631) {
            if (iVar2 == 0x45565031) {
              readEnvelop(this,(J3DEnvelopBlock *)pJVar4);
            }
            else {
              if ((0x45565030 < iVar2) || (iVar2 != 0x44525731)) goto LAB_802fc034;
              readDraw(this,(J3DDrawBlock *)pJVar4);
            }
          }
          else {
            if (iVar2 == 0x4a4e5431) {
              readJoint(this,(J3DJointBlock *)pJVar4);
            }
            else {
LAB_802fc034:
              m_Do_printf::OSReport("Unknown data block\n");
            }
          }
        }
      }
      else {
        if (iVar2 == 0x54455831) {
          readTexture(this,(J3DTextureBlock *)pJVar4);
        }
        else {
          if (iVar2 < 0x54455831) {
            if (iVar2 == 0x53485031) {
              readShape(this,(J3DShapeBlock *)pJVar4,loadArgs);
            }
            else {
              if ((0x53485030 < iVar2) || (iVar2 != 0x4d444c33)) goto LAB_802fc034;
              readMaterialDL(this,(J3DMaterialDLBlock *)pJVar4,loadArgs);
              modifyMaterial(this,loadArgs);
            }
          }
          else {
            if (iVar2 != 0x56545831) goto LAB_802fc034;
            readVertex(this,pJVar4);
          }
        }
      }
    }
    pJVar4 = (J3DVertexBlock *)(pJVar4->mMagic + pJVar4->mSize);
    uVar3 = uVar3 + 1;
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x802fc150) */
/* __thiscall J3DModelLoader::setupBBoardInfo(void) */

void __thiscall J3DModelLoader::setupBBoardInfo(J3DModelLoader *this)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  J3DMaterial *pJVar4;
  int iVar5;
  int iVar6;
  J3DJoint *pJVar7;
  ushort uVar8;
  
  for (uVar8 = 0; uVar8 < (ushort)(this->mpModelData->mJointTree).mJointCount; uVar8 = uVar8 + 1) {
    uVar3 = (uint)uVar8;
    pJVar4 = (this->mpModelData->mJointTree).mpJoints[uVar3]->mpMaterial;
    if (pJVar4 != (J3DMaterial *)0x0) {
      uVar2 = pJVar4->mpShape->mShapeIdx;
      iVar5 = J3DGraphLoader::JSUConvertOffsetToPtr
                        (this->mpShapeBlock,*(undefined4 *)(this->mpShapeBlock + 0x10));
      iVar6 = J3DGraphLoader::JSUConvertOffsetToPtr
                        (this->mpShapeBlock,*(undefined4 *)(this->mpShapeBlock + 0xc));
      bVar1 = *(byte *)(iVar6 + (uint)*(ushort *)(iVar5 + (uint)uVar2 * 2) * 0x28);
      if (bVar1 == 2) {
        pJVar7 = (this->mpModelData->mJointTree).mpJoints[uVar3];
        pJVar7->mMtxTypeFlags = pJVar7->mMtxTypeFlags & 0xf | 0x20;
        this->mpModelData->field_0xe = 1;
      }
      else {
        if (bVar1 < 2) {
          if (bVar1 == 0) {
            pJVar7 = (this->mpModelData->mJointTree).mpJoints[uVar3];
            pJVar7->mMtxTypeFlags = pJVar7->mMtxTypeFlags & 0xf;
          }
          else {
            pJVar7 = (this->mpModelData->mJointTree).mpJoints[uVar3];
            pJVar7->mMtxTypeFlags = pJVar7->mMtxTypeFlags & 0xf | 0x10;
            this->mpModelData->field_0xe = 1;
          }
        }
        else {
          if (bVar1 < 4) {
            pJVar7 = (this->mpModelData->mJointTree).mpJoints[uVar3];
            pJVar7->mMtxTypeFlags = pJVar7->mMtxTypeFlags & 0xf;
          }
          else {
            m_Do_printf::OSReport("WRONG SHAPE MATRIX TYPE (__FILE__)\n");
          }
        }
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802fc290) */
/* __thiscall J3DModelLoader::readInformation(J3DModelInfoBlock const *,
                                              unsigned long) */

void __thiscall
J3DModelLoader::readInformation(J3DModelLoader *this,J3DModelInfoBlock *param_1,ulong loadArgs)

{
  uint uVar1;
  J3DModelHierarchy *pJVar2;
  J3DMtxCalcBasic *this_00;
  
  this->mpModelData->mLoadArgs = loadArgs | *(ushort *)(param_1 + 8);
  (this->mpModelData->mJointTree).mMatrixCalcFlags = this->mpModelData->mLoadArgs;
  this_00 = (J3DMtxCalcBasic *)0x0;
  uVar1 = this->mpModelData->mLoadArgs & 0xf;
  if (uVar1 == 1) {
    this_00 = (J3DMtxCalcBasic *)JKernel::operator_new(0x78);
    if (this_00 != (J3DMtxCalcBasic *)0x0) {
      this_00->vderiv = (J3DMtxCalc *)(this_00 + 1);
      this_00[1].vderiv = (J3DMtxCalc *)&J3DMtxCalc::__vt;
      J3DMtxCalcBasic::J3DMtxCalcBasic(this_00);
      this_00->vtbl = &J3DMtxCalcSoftimage::__vt;
      this_00->vderiv->vtbl = &DAT_8039ebd8;
      this_00->vderiv[9].vtbl = (undefined *)((int)this_00 + (0x50 - (int)this_00->vderiv));
      this_00 = (J3DMtxCalcBasic *)this_00->vderiv;
    }
  }
  else {
    if (uVar1 == 0) {
      this_00 = (J3DMtxCalcBasic *)JKernel::operator_new(0x78);
      if (this_00 != (J3DMtxCalcBasic *)0x0) {
        this_00 = J3DMtxCalcBasic::J3DMtxCalcBasic(this_00);
      }
      if (this_00 != (J3DMtxCalcBasic *)0x0) {
        this_00 = (J3DMtxCalcBasic *)this_00->vderiv;
      }
    }
    else {
      if ((uVar1 < 3) &&
         (this_00 = (J3DMtxCalcBasic *)JKernel::operator_new(0x78),
         this_00 != (J3DMtxCalcBasic *)0x0)) {
        this_00->vderiv = (J3DMtxCalc *)(this_00 + 1);
        this_00[1].vderiv = (J3DMtxCalc *)&J3DMtxCalc::__vt;
        J3DMtxCalcBasic::J3DMtxCalcBasic(this_00);
        this_00->vtbl = &J3DMtxCalcMaya::__vt;
        this_00->vderiv->vtbl = &DAT_8039eba4;
        this_00->vderiv[9].vtbl = (undefined *)((int)this_00 + (0x50 - (int)this_00->vderiv));
        this_00 = (J3DMtxCalcBasic *)this_00->vderiv;
      }
    }
  }
  (this->mpModelData->mJointTree).mpMtxCalc = (undefined *)this_00;
  *(undefined4 *)&(this->mpModelData->mVertexData).field_0x58 = *(undefined4 *)(param_1 + 0xc);
  (this->mpModelData->mVertexData).mVertexCount = *(int *)(param_1 + 0x10);
  pJVar2 = (J3DModelHierarchy *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x14));
  (this->mpModelData->mJointTree).mpHierarchy = pJVar2;
  return;
}


namespace J3DGraphLoader {

/* __stdcall getFmtType(_GXVtxAttrFmtList *,
                        _GXAttr) */

int getFmtType(int *param_1,int param_2)

{
  while( true ) {
    if (*param_1 == 0xff) {
      return 4;
    }
    if (*param_1 == param_2) break;
    param_1 = param_1 + 4;
  }
  return param_1[2];
}

}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DModelLoader::readVertex(J3DVertexBlock const *) */

void __thiscall J3DModelLoader::readVertex(J3DModelLoader *this,J3DVertexBlock *param_1)

{
  char *pcVar1;
  J3DModelData *pJVar2;
  undefined *puVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  pJVar2 = this->mpModelData;
  puVar3 = (undefined *)J3DGraphLoader::JSUConvertOffsetToPtr(param_1,param_1->mVertexFormatsOffs);
  (pJVar2->mVertexData).mpAttribFormats = puVar3;
  pcVar4 = (char *)J3DGraphLoader::JSUConvertOffsetToPtr(param_1,param_1->mVertexDataOffsets[0]);
  (pJVar2->mVertexData).mpVertexArr_Pos = pcVar4;
  pcVar4 = (char *)J3DGraphLoader::JSUConvertOffsetToPtr(param_1,param_1->mVertexDataOffsets[1]);
  (pJVar2->mVertexData).mpVertexArr_Nrm = pcVar4;
  pcVar4 = (char *)J3DGraphLoader::JSUConvertOffsetToPtr(param_1,param_1->mVertexDataOffsets[2]);
  (pJVar2->mVertexData).mpVertexArr_Nbt = pcVar4;
  iVar7 = 0;
  iVar8 = 0;
  do {
    uVar5 = J3DGraphLoader::JSUConvertOffsetToPtr
                      (param_1,*(undefined4 *)((int)param_1->mVertexDataOffsets + iVar8 + 0xc));
    *(undefined4 *)((int)(pJVar2->mVertexData).mpVertexArr_Clr + iVar8) = uVar5;
    iVar7 = iVar7 + 1;
    iVar8 = iVar8 + 4;
  } while (iVar7 < 2);
  iVar7 = 0;
  iVar8 = 0;
  do {
    uVar5 = J3DGraphLoader::JSUConvertOffsetToPtr
                      (param_1,*(undefined4 *)((int)param_1->mVertexDataOffsets + iVar8 + 0x14));
    *(undefined4 *)((int)(pJVar2->mVertexData).mpVertexArr_Tex + iVar8) = uVar5;
    iVar7 = iVar7 + 1;
    iVar8 = iVar8 + 4;
  } while (iVar7 < 8);
  iVar7 = J3DGraphLoader::getFmtType((pJVar2->mVertexData).mpAttribFormats,10);
  uVar6 = 6;
  if (iVar7 == 4) {
    uVar6 = 0xc;
  }
  pcVar4 = (pJVar2->mVertexData).mpVertexArr_Nbt;
  if (((pcVar4 == (char *)0x0) &&
      (pcVar4 = (pJVar2->mVertexData).mpVertexArr_Clr[0], pcVar4 == (char *)0x0)) &&
     (pcVar1 = (pJVar2->mVertexData).mpVertexArr_Tex[0], pcVar4 = (char *)0x0, pcVar1 != (char *)0x0
     )) {
    pcVar4 = pcVar1;
  }
  pcVar1 = (pJVar2->mVertexData).mpVertexArr_Nrm;
  if (pcVar1 == (char *)0x0) {
    (pJVar2->mVertexData).mArrSizeNrm = 0;
  }
  else {
    if (pcVar4 == (char *)0x0) {
      (pJVar2->mVertexData).mArrSizeNrm =
           (uint)(param_1->mSize - param_1->mVertexDataOffsets[1]) / uVar6 + 1;
    }
    else {
      (pJVar2->mVertexData).mArrSizeNrm = (uint)((int)pcVar4 - (int)pcVar1) / uVar6 + 1;
    }
  }
  pcVar4 = (pJVar2->mVertexData).mpVertexArr_Clr[1];
  if ((pcVar4 == (char *)0x0) &&
     (pcVar1 = (pJVar2->mVertexData).mpVertexArr_Tex[0], pcVar4 = (char *)0x0, pcVar1 != (char *)0x0
     )) {
    pcVar4 = pcVar1;
  }
  pcVar1 = (pJVar2->mVertexData).mpVertexArr_Clr[0];
  if (pcVar1 == (char *)0x0) {
    (pJVar2->mVertexData).mArrSizeClr = 0;
  }
  else {
    if (pcVar4 == (char *)0x0) {
      (pJVar2->mVertexData).mArrSizeClr =
           ((uint)(param_1->mSize - param_1->mVertexDataOffsets[3]) >> 2) + 1;
    }
    else {
      (pJVar2->mVertexData).mArrSizeClr = ((uint)((int)pcVar4 - (int)pcVar1) >> 2) + 1;
    }
  }
  if ((pJVar2->mVertexData).mpVertexArr_Tex[0] == (char *)0x0) {
    (pJVar2->mVertexData).mArrSizeTex = 0;
  }
  else {
    (pJVar2->mVertexData).mArrSizeTex =
         ((uint)(param_1->mSize - param_1->mVertexDataOffsets[5]) >> 3) + 1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DModelLoader::readEnvelop(J3DEnvelopBlock const *) */

void __thiscall J3DModelLoader::readEnvelop(J3DModelLoader *this,J3DEnvelopBlock *param_1)

{
  char *pcVar1;
  ushort *puVar2;
  float *pfVar3;
  MTX34 *pMVar4;
  J3DModelData *pJVar5;
  
  (this->mpModelData->mJointTree).mEnvelopeCount = *(short *)(param_1 + 8);
  pJVar5 = this->mpModelData;
  pcVar1 = (char *)J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0xc));
  (pJVar5->mJointTree).mpEnvJointCountTable = pcVar1;
  pJVar5 = this->mpModelData;
  puVar2 = (ushort *)J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x10));
  (pJVar5->mJointTree).mpEnvJointIndexTable = puVar2;
  pJVar5 = this->mpModelData;
  pfVar3 = (float *)J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x14));
  (pJVar5->mJointTree).mpEnvWeightTable = pfVar3;
  pJVar5 = this->mpModelData;
  pMVar4 = (MTX34 *)J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x18));
  (pJVar5->mJointTree).mpEnvInvBindPoseTable = pMVar4;
  return;
}


/* __thiscall J3DModelLoader::readDraw(J3DDrawBlock const *) */

void __thiscall J3DModelLoader::readDraw(J3DModelLoader *this,J3DDrawBlock *param_1)

{
  byte *pbVar1;
  short *psVar2;
  ushort uVar3;
  J3DModelData *pJVar4;
  
  pJVar4 = this->mpModelData;
  (pJVar4->mJointTree).mDrawMtxData.mDrawMtxCount = *(short *)(param_1 + 8);
  pbVar1 = (byte *)J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0xc));
  (pJVar4->mJointTree).mDrawMtxData.mpMtxTypeArray = pbVar1;
  psVar2 = (short *)J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x10));
  (pJVar4->mJointTree).mDrawMtxData.mpDataArray = psVar2;
  for (uVar3 = 0;
      (uVar3 < (ushort)(pJVar4->mJointTree).mDrawMtxData.mDrawMtxCount &&
      ((pJVar4->mJointTree).mDrawMtxData.mpMtxTypeArray[uVar3] != 1)); uVar3 = uVar3 + 1) {
  }
  (pJVar4->mJointTree).mDrawMtxData.mRigidMtxCount = uVar3;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DModelLoader::readJoint(J3DJointBlock const *) */

void __thiscall J3DModelLoader::readJoint(J3DModelLoader *this,J3DJointBlock *param_1)

{
  JUTNameTab *this_00;
  ResNTAB *pRVar1;
  J3DJoint **ppJVar2;
  J3DJoint *pJVar3;
  ushort uVar4;
  J3DModelData *pJVar5;
  J3DJointFactory JStack24;
  
  J3DJointFactory::J3DJointFactory(&JStack24,param_1);
  (this->mpModelData->mJointTree).mJointCount = param_1->field_0x8;
  if (param_1->field_0x14 == 0) {
    (this->mpModelData->mJointTree).mpNameTable = (JUTNameTab *)0x0;
  }
  else {
    this_00 = (JUTNameTab *)JKernel::operator_new(0x10);
    if (this_00 != (JUTNameTab *)0x0) {
      pRVar1 = (ResNTAB *)J3DGraphLoader::JSUConvertOffsetToPtr(param_1,param_1->field_0x14);
      JUTNameTab::JUTNameTab(this_00,pRVar1);
    }
    (this->mpModelData->mJointTree).mpNameTable = this_00;
  }
  pJVar5 = this->mpModelData;
  ppJVar2 = (J3DJoint **)
            JKernel::operator_new__((uint)(ushort)(pJVar5->mJointTree).mJointCount << 2);
  (pJVar5->mJointTree).mpJoints = ppJVar2;
  for (uVar4 = 0; pJVar5 = this->mpModelData, uVar4 < (ushort)(pJVar5->mJointTree).mJointCount;
      uVar4 = uVar4 + 1) {
    pJVar3 = (J3DJoint *)J3DJointFactory::create(&JStack24,(uint)uVar4);
    (pJVar5->mJointTree).mpJoints[uVar4] = pJVar3;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DModelLoader_v26::readMaterial(J3DMaterialBlock const *,
                                               unsigned long) */

void __thiscall
J3DModelLoader_v26::readMaterial(J3DModelLoader_v26 *this,J3DMaterialBlock *param_1,ulong param_2)

{
  undefined2 uVar3;
  JUTNameTab *this_00;
  ResNTAB *pRVar1;
  undefined4 uVar2;
  int iVar4;
  uint uVar5;
  ushort uVar6;
  J3DMaterialFactory aJStack168 [12];
  
  J3DMaterialFactory::J3DMaterialFactory(aJStack168,param_1);
  *(undefined2 *)(*(int *)(this + 8) + 4) = *(undefined2 *)(param_1 + 8);
  uVar3 = J3DMaterialFactory::countUniqueMaterials(aJStack168);
  *(undefined2 *)(*(int *)(this + 8) + 0x10) = uVar3;
  if (*(int *)(param_1 + 0x14) == 0) {
    *(undefined4 *)(*(int *)(this + 8) + 0xc) = 0;
  }
  else {
    this_00 = (JUTNameTab *)JKernel::operator_new(0x10);
    if (this_00 != (JUTNameTab *)0x0) {
      pRVar1 = (ResNTAB *)
               J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x14));
      JUTNameTab::JUTNameTab(this_00,pRVar1);
    }
    *(JUTNameTab **)(*(int *)(this + 8) + 0xc) = this_00;
  }
  uVar2 = JKernel::operator_new__((uint)*(ushort *)(*(int *)(this + 8) + 4) << 2);
  *(undefined4 *)(*(int *)(this + 8) + 8) = uVar2;
  if ((param_2 & 0x200000) == 0) {
    *(undefined4 *)(*(int *)(this + 8) + 0x14) = 0;
  }
  else {
    uVar6 = *(ushort *)(*(int *)(this + 8) + 0x10);
    uVar2 = JKernel::operator_new__((uint)uVar6 * 0x4c + 0x10,0x20);
    uVar2 = Runtime.PPCEABI.H::__construct_new_array
                      (uVar2,J3DMaterial::J3DMaterial,J3DMaterial::_J3DMaterial,0x4c,(uint)uVar6);
    *(undefined4 *)(*(int *)(this + 8) + 0x14) = uVar2;
    for (uVar6 = 0; uVar6 < *(ushort *)(*(int *)(this + 8) + 0x10); uVar6 = uVar6 + 1) {
      iVar4 = (uint)uVar6 * 0x4c;
      J3DMaterialFactory::create
                (aJStack168,(J3DMaterial *)(*(int *)(*(int *)(this + 8) + 0x14) + iVar4),0,
                 (uint)uVar6,param_2);
      uVar5 = *(int *)(*(int *)(this + 8) + 0x14) + iVar4;
      *(uint *)(uVar5 + 0x20) = uVar5 >> 4;
    }
  }
  for (uVar6 = 0; uVar6 < *(ushort *)(*(int *)(this + 8) + 4); uVar6 = uVar6 + 1) {
    uVar2 = J3DMaterialFactory::create(aJStack168,(J3DMaterial *)0x0,0,(uint)uVar6,param_2);
    *(undefined4 *)(*(int *)(*(int *)(this + 8) + 8) + (uint)uVar6 * 4) = uVar2;
  }
  if ((param_2 & 0x200000) == 0) {
    for (uVar6 = 0; uVar6 < *(ushort *)(*(int *)(this + 8) + 4); uVar6 = uVar6 + 1) {
      uVar5 = *(uint *)(*(int *)(this + 8) + 8);
      *(uint *)(*(int *)(uVar5 + (uint)uVar6 * 4) + 0x20) =
           (uVar5 >> 4) + (uint)*(ushort *)(aJStack168[0].field_0x8 + (uint)uVar6 * 2);
    }
  }
  else {
    for (uVar6 = 0; iVar4 = *(int *)(this + 8), uVar6 < *(ushort *)(iVar4 + 4); uVar6 = uVar6 + 1) {
      *(uint *)(*(int *)(*(int *)(iVar4 + 8) + (uint)uVar6 * 4) + 0x20) =
           *(int *)(iVar4 + 0x14) +
           (uint)*(ushort *)(aJStack168[0].field_0x8 + (uint)uVar6 * 2) * 0x4c >> 4;
      *(uint *)(*(int *)(*(int *)(*(int *)(this + 8) + 8) + (uint)uVar6 * 4) + 0x38) =
           *(int *)(*(int *)(this + 8) + 0x14) +
           (uint)*(ushort *)(aJStack168[0].field_0x8 + (uint)uVar6 * 2) * 0x4c;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DModelLoader_v21::readMaterial_v21(J3DMaterialBlock_v21 const *,
                                                   unsigned long) */

void __thiscall
J3DModelLoader_v21::readMaterial_v21
          (J3DModelLoader_v21 *this,J3DMaterialBlock_v21 *param_1,ulong param_2)

{
  undefined2 uVar4;
  JUTNameTab *this_00;
  ResNTAB *pRVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar5;
  ushort uVar6;
  J3DMaterialFactory_v21 aJStack136 [8];
  int local_80;
  
  J3DMaterialFactory_v21::J3DMaterialFactory_v21(aJStack136,param_1);
  *(undefined2 *)(*(int *)(this + 8) + 4) = *(undefined2 *)(param_1 + 8);
  uVar4 = J3DMaterialFactory_v21::countUniqueMaterials(aJStack136);
  *(undefined2 *)(*(int *)(this + 8) + 0x10) = uVar4;
  if (*(int *)(param_1 + 0x14) == 0) {
    *(undefined4 *)(*(int *)(this + 8) + 0xc) = 0;
  }
  else {
    this_00 = (JUTNameTab *)JKernel::operator_new(0x10);
    if (this_00 != (JUTNameTab *)0x0) {
      pRVar1 = (ResNTAB *)
               J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x14));
      JUTNameTab::JUTNameTab(this_00,pRVar1);
    }
    *(JUTNameTab **)(*(int *)(this + 8) + 0xc) = this_00;
  }
  uVar2 = JKernel::operator_new__((uint)*(ushort *)(*(int *)(this + 8) + 4) << 2);
  *(undefined4 *)(*(int *)(this + 8) + 8) = uVar2;
  if ((param_2 & 0x200000) == 0) {
    *(undefined4 *)(*(int *)(this + 8) + 0x14) = 0;
  }
  else {
    uVar6 = *(ushort *)(*(int *)(this + 8) + 0x10);
    uVar2 = JKernel::operator_new__((uint)uVar6 * 0x4c + 0x10,0x20);
    uVar2 = Runtime.PPCEABI.H::__construct_new_array
                      (uVar2,J3DMaterial::J3DMaterial,J3DMaterial::_J3DMaterial,0x4c,(uint)uVar6);
    *(undefined4 *)(*(int *)(this + 8) + 0x14) = uVar2;
    for (uVar6 = 0; uVar6 < *(ushort *)(*(int *)(this + 8) + 0x10); uVar6 = uVar6 + 1) {
      iVar5 = (uint)uVar6 * 0x4c;
      J3DMaterialFactory_v21::create
                (aJStack136,(J3DMaterial *)(*(int *)(*(int *)(this + 8) + 0x14) + iVar5),(uint)uVar6
                 ,param_2);
      uVar3 = *(int *)(*(int *)(this + 8) + 0x14) + iVar5;
      *(uint *)(uVar3 + 0x20) = uVar3 >> 4;
    }
  }
  for (uVar6 = 0; uVar6 < *(ushort *)(*(int *)(this + 8) + 4); uVar6 = uVar6 + 1) {
    uVar2 = J3DMaterialFactory_v21::create(aJStack136,(J3DMaterial *)0x0,(uint)uVar6,param_2);
    *(undefined4 *)(*(int *)(*(int *)(this + 8) + 8) + (uint)uVar6 * 4) = uVar2;
  }
  if ((param_2 & 0x200000) == 0) {
    for (uVar6 = 0; uVar6 < *(ushort *)(*(int *)(this + 8) + 4); uVar6 = uVar6 + 1) {
      *(undefined4 *)(*(int *)(*(int *)(*(int *)(this + 8) + 8) + (uint)uVar6 * 4) + 0x20) =
           0xc0000000;
    }
  }
  else {
    for (uVar6 = 0; iVar5 = *(int *)(this + 8), uVar6 < *(ushort *)(iVar5 + 4); uVar6 = uVar6 + 1) {
      *(uint *)(*(int *)(*(int *)(iVar5 + 8) + (uint)uVar6 * 4) + 0x20) =
           *(int *)(iVar5 + 0x14) + (uint)*(ushort *)(local_80 + (uint)uVar6 * 2) * 0x4c >> 4;
      *(uint *)(*(int *)(*(int *)(*(int *)(this + 8) + 8) + (uint)uVar6 * 4) + 0x38) =
           *(int *)(*(int *)(this + 8) + 0x14) +
           (uint)*(ushort *)(local_80 + (uint)uVar6 * 2) * 0x4c;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DModelLoader::readShape(J3DShapeBlock const *,
                                        unsigned long) */

void __thiscall J3DModelLoader::readShape(J3DModelLoader *this,J3DShapeBlock *param_1,ulong param_2)

{
  JUTNameTab *this_00;
  ResNTAB *pRVar1;
  J3DShape **ppJVar2;
  J3DShape *pJVar3;
  _GXVtxDescList *p_Var4;
  J3DModelHierarchy *pJVar5;
  int local_38;
  int local_34;
  int local_30;
  
  this->mpShapeBlock = param_1;
  J3DShapeFactory::J3DShapeFactory((J3DShapeFactory *)&local_38,param_1);
  (this->mpModelData->mShapeTable).mShapeCount = *(ushort *)(param_1 + 8);
  if (*(int *)(param_1 + 0x14) == 0) {
    this->mpModelData->mpNameTab = (JUTNameTab *)0x0;
  }
  else {
    this_00 = (JUTNameTab *)JKernel::operator_new(0x10);
    if (this_00 != (JUTNameTab *)0x0) {
      pRVar1 = (ResNTAB *)
               J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x14));
      JUTNameTab::JUTNameTab(this_00,pRVar1);
    }
    this->mpModelData->mpNameTab = this_00;
  }
  ppJVar2 = (J3DShape **)
            JKernel::operator_new__((uint)(this->mpModelData->mShapeTable).mShapeCount << 2);
  (this->mpModelData->mShapeTable).mpShapes = ppJVar2;
  J3DShapeFactory::allocVcdVatCmdBuffer
            ((J3DShapeFactory *)&local_38,(uint)(this->mpModelData->mShapeTable).mShapeCount);
  p_Var4 = (_GXVtxDescList *)0x0;
  for (pJVar5 = (this->mpModelData->mJointTree).mpHierarchy; pJVar5->mHierarchyType != 0;
      pJVar5 = pJVar5 + 1) {
    if (pJVar5->mHierarchyType == 0x12) {
      pJVar3 = (J3DShape *)
               J3DShapeFactory::create
                         ((J3DShapeFactory *)&local_38,(uint)(ushort)pJVar5->mHierarchyValue,param_2
                          ,p_Var4);
      (this->mpModelData->mShapeTable).mpShapes[(ushort)pJVar5->mHierarchyValue] = pJVar3;
      p_Var4 = (_GXVtxDescList *)
               (local_30 +
               (uint)*(ushort *)
                      (local_38 +
                      (uint)*(ushort *)(local_34 + (uint)(ushort)pJVar5->mHierarchyValue * 2) * 0x28
                      + 4));
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DModelLoader::readTexture(J3DTextureBlock const *) */

void __thiscall J3DModelLoader::readTexture(J3DModelLoader *this,J3DTextureBlock *param_1)

{
  short sVar1;
  ResTIMG *pTexData;
  JUTNameTab *this_00;
  ResNTAB *pRVar2;
  J3DTexture *pJVar3;
  
  sVar1 = param_1->mCount;
  pTexData = (ResTIMG *)J3DGraphLoader::JSUConvertOffsetToPtr(param_1,param_1->mTexDataOffs);
  if (param_1->mTexNamTabOffs == 0) {
    this->mpMaterialTable->mpTexNameTab = (JUTNameTab *)0x0;
  }
  else {
    this_00 = (JUTNameTab *)JKernel::operator_new(0x10);
    if (this_00 != (JUTNameTab *)0x0) {
      pRVar2 = (ResNTAB *)J3DGraphLoader::JSUConvertOffsetToPtr(param_1,param_1->mTexNamTabOffs);
      JUTNameTab::JUTNameTab(this_00,pRVar2);
    }
    this->mpMaterialTable->mpTexNameTab = this_00;
  }
  pJVar3 = (J3DTexture *)JKernel::operator_new(0xc);
  if (pJVar3 != (J3DTexture *)0x0) {
    pJVar3->vtbl = (undefined *)&J3DTexture::__vt;
    pJVar3->mCount = sVar1;
    pJVar3->mpTexData = pTexData;
  }
  this->mpMaterialTable->mpTexture = pJVar3;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DModelLoader_v26::readMaterialTable(J3DMaterialBlock const *,
                                                    unsigned long) */

void __thiscall
J3DModelLoader_v26::readMaterialTable
          (J3DModelLoader_v26 *this,J3DMaterialBlock *param_1,ulong param_2)

{
  JUTNameTab *this_00;
  ResNTAB *pRVar1;
  undefined4 uVar2;
  int iVar3;
  ushort uVar4;
  J3DMaterialFactory aJStack152 [11];
  
  J3DMaterialFactory::J3DMaterialFactory(aJStack152,param_1);
  *(undefined2 *)(*(int *)(this + 8) + 4) = *(undefined2 *)(param_1 + 8);
  if (*(int *)(param_1 + 0x14) == 0) {
    *(undefined4 *)(*(int *)(this + 8) + 0xc) = 0;
  }
  else {
    this_00 = (JUTNameTab *)JKernel::operator_new(0x10);
    if (this_00 != (JUTNameTab *)0x0) {
      pRVar1 = (ResNTAB *)
               J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x14));
      JUTNameTab::JUTNameTab(this_00,pRVar1);
    }
    *(JUTNameTab **)(*(int *)(this + 8) + 0xc) = this_00;
  }
  uVar2 = JKernel::operator_new__((uint)*(ushort *)(*(int *)(this + 8) + 4) << 2);
  *(undefined4 *)(*(int *)(this + 8) + 8) = uVar2;
  for (uVar4 = 0; uVar4 < *(ushort *)(*(int *)(this + 8) + 4); uVar4 = uVar4 + 1) {
    uVar2 = J3DMaterialFactory::create(aJStack152,(J3DMaterial *)0x0,0,(uint)uVar4,param_2);
    *(undefined4 *)(*(int *)(*(int *)(this + 8) + 8) + (uint)uVar4 * 4) = uVar2;
  }
  for (uVar4 = 0; uVar4 < *(ushort *)(*(int *)(this + 8) + 4); uVar4 = uVar4 + 1) {
    iVar3 = *(int *)(*(int *)(this + 8) + 8);
    *(uint *)(*(int *)(iVar3 + (uint)uVar4 * 4) + 0x20) =
         iVar3 + (uint)*(ushort *)(aJStack152[0].field_0x8 + (uint)uVar4 * 2);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DModelLoader_v21::readMaterialTable_v21(J3DMaterialBlock_v21 const *,
                                                        unsigned long) */

void __thiscall
J3DModelLoader_v21::readMaterialTable_v21
          (J3DModelLoader_v21 *this,J3DMaterialBlock_v21 *param_1,ulong param_2)

{
  JUTNameTab *this_00;
  ResNTAB *pRVar1;
  undefined4 uVar2;
  uint uVar3;
  ushort uVar4;
  J3DMaterialFactory_v21 aJStack136 [8];
  int local_80;
  
  J3DMaterialFactory_v21::J3DMaterialFactory_v21(aJStack136,param_1);
  *(undefined2 *)(*(int *)(this + 8) + 4) = *(undefined2 *)(param_1 + 8);
  if (*(int *)(param_1 + 0x14) == 0) {
    *(undefined4 *)(*(int *)(this + 8) + 0xc) = 0;
  }
  else {
    this_00 = (JUTNameTab *)JKernel::operator_new(0x10);
    if (this_00 != (JUTNameTab *)0x0) {
      pRVar1 = (ResNTAB *)
               J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x14));
      JUTNameTab::JUTNameTab(this_00,pRVar1);
    }
    *(JUTNameTab **)(*(int *)(this + 8) + 0xc) = this_00;
  }
  uVar2 = JKernel::operator_new__((uint)*(ushort *)(*(int *)(this + 8) + 4) << 2);
  *(undefined4 *)(*(int *)(this + 8) + 8) = uVar2;
  for (uVar4 = 0; uVar4 < *(ushort *)(*(int *)(this + 8) + 4); uVar4 = uVar4 + 1) {
    uVar2 = J3DMaterialFactory_v21::create(aJStack136,(J3DMaterial *)0x0,(uint)uVar4,param_2);
    *(undefined4 *)(*(int *)(*(int *)(this + 8) + 8) + (uint)uVar4 * 4) = uVar2;
  }
  for (uVar4 = 0; uVar4 < *(ushort *)(*(int *)(this + 8) + 4); uVar4 = uVar4 + 1) {
    uVar3 = *(uint *)(*(int *)(this + 8) + 8);
    *(uint *)(*(int *)(uVar3 + (uint)uVar4 * 4) + 0x20) =
         (uVar3 >> 4) + (uint)*(ushort *)(local_80 + (uint)uVar4 * 2);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DModelLoader::readTextureTable(J3DTextureBlock const *) */

void __thiscall J3DModelLoader::readTextureTable(J3DModelLoader *this,J3DTextureBlock *param_1)

{
  short sVar1;
  ResTIMG *pRVar2;
  JUTNameTab *this_00;
  ResNTAB *pRVar3;
  J3DTexture *pTexture;
  
  sVar1 = param_1->mCount;
  pRVar2 = (ResTIMG *)J3DGraphLoader::JSUConvertOffsetToPtr(param_1,param_1->mTexDataOffs);
  if (param_1->mTexNamTabOffs == 0) {
    this->mpMaterialTable->mpTexNameTab = (JUTNameTab *)0x0;
  }
  else {
    this_00 = (JUTNameTab *)JKernel::operator_new(0x10);
    if (this_00 != (JUTNameTab *)0x0) {
      pRVar3 = (ResNTAB *)J3DGraphLoader::JSUConvertOffsetToPtr(param_1,param_1->mTexNamTabOffs);
      JUTNameTab::JUTNameTab(this_00,pRVar3);
    }
    this->mpMaterialTable->mpTexNameTab = this_00;
  }
  pTexture = (J3DTexture *)JKernel::operator_new(0xc);
  if (pTexture != (J3DTexture *)0x0) {
    pTexture->vtbl = (undefined *)&J3DTexture::__vt;
    pTexture->mCount = sVar1;
    pTexture->mpTexData = pRVar2;
  }
  this->mpMaterialTable->mpTexture = pTexture;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DModelLoader::readPatchedMaterial(J3DMaterialBlock const *,
                                                  unsigned long) */

void __thiscall
J3DModelLoader::readPatchedMaterial(J3DModelLoader *this,J3DMaterialBlock *param_1,ulong param_2)

{
  undefined2 uVar4;
  JUTNameTab *this_00;
  ResNTAB *pRVar1;
  J3DMaterial **ppJVar2;
  J3DMaterial *pJVar3;
  ushort uVar5;
  J3DMaterialFactory aJStack152 [11];
  
  J3DMaterialFactory::J3DMaterialFactory(aJStack152,param_1);
  this->mpMaterialTable->mMaterialCount = *(ushort *)(param_1 + 8);
  uVar4 = J3DMaterialFactory::countUniqueMaterials(aJStack152);
  *(undefined2 *)&this->mpMaterialTable->field_0x10 = uVar4;
  if (*(int *)(param_1 + 0x14) == 0) {
    this->mpMaterialTable->mpNameTab = (JUTNameTab *)0x0;
  }
  else {
    this_00 = (JUTNameTab *)JKernel::operator_new(0x10);
    if (this_00 != (JUTNameTab *)0x0) {
      pRVar1 = (ResNTAB *)
               J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x14));
      JUTNameTab::JUTNameTab(this_00,pRVar1);
    }
    this->mpMaterialTable->mpNameTab = this_00;
  }
  ppJVar2 = (J3DMaterial **)
            JKernel::operator_new__((uint)this->mpMaterialTable->mMaterialCount << 2);
  this->mpMaterialTable->mpMaterials = ppJVar2;
  *(undefined4 *)&this->mpMaterialTable->field_0x14 = 0;
  for (uVar5 = 0; uVar5 < this->mpMaterialTable->mMaterialCount; uVar5 = uVar5 + 1) {
    pJVar3 = (J3DMaterial *)
             J3DMaterialFactory::create(aJStack152,(J3DMaterial *)0x0,2,(uint)uVar5,param_2);
    this->mpMaterialTable->mpMaterials[uVar5] = pJVar3;
    ppJVar2 = this->mpMaterialTable->mpMaterials;
    ppJVar2[uVar5]->field_0x20 =
         ((uint)ppJVar2 >> 4) + (uint)*(ushort *)(aJStack152[0].field_0x8 + (uint)uVar5 * 2);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DModelLoader::readMaterialDL(J3DMaterialDLBlock const *,
                                             unsigned long) */

void __thiscall
J3DModelLoader::readMaterialDL(J3DModelLoader *this,J3DMaterialDLBlock *param_1,ulong param_2)

{
  JUTNameTab *this_00;
  ResNTAB *pRVar1;
  J3DMaterial **ppJVar2;
  J3DMaterial *pJVar3;
  ushort uVar4;
  J3DMaterialFactory aJStack152 [11];
  
  J3DMaterialFactory::J3DMaterialFactory(aJStack152,param_1);
  if (this->mpMaterialTable->mMaterialCount == 0) {
    *(undefined2 *)&this->mpMaterialTable[1].vtbl = 1;
    this->mpMaterialTable->mMaterialCount = *(ushort *)(param_1 + 8);
    *(undefined2 *)&this->mpMaterialTable->field_0x10 = *(undefined2 *)(param_1 + 8);
    if (*(int *)(param_1 + 0x20) == 0) {
      this->mpMaterialTable->mpNameTab = (JUTNameTab *)0x0;
    }
    else {
      this_00 = (JUTNameTab *)JKernel::operator_new(0x10);
      if (this_00 != (JUTNameTab *)0x0) {
        pRVar1 = (ResNTAB *)
                 J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x20));
        JUTNameTab::JUTNameTab(this_00,pRVar1);
      }
      this->mpMaterialTable->mpNameTab = this_00;
    }
    ppJVar2 = (J3DMaterial **)
              JKernel::operator_new__((uint)this->mpMaterialTable->mMaterialCount << 2);
    this->mpMaterialTable->mpMaterials = ppJVar2;
    *(undefined4 *)&this->mpMaterialTable->field_0x14 = 0;
    for (uVar4 = 0; uVar4 < this->mpMaterialTable->mMaterialCount; uVar4 = uVar4 + 1) {
      pJVar3 = (J3DMaterial *)
               J3DMaterialFactory::create(aJStack152,(J3DMaterial *)0x0,1,(uint)uVar4,param_2);
      this->mpMaterialTable->mpMaterials[uVar4] = pJVar3;
    }
    for (uVar4 = 0; uVar4 < this->mpMaterialTable->mMaterialCount; uVar4 = uVar4 + 1) {
      this->mpMaterialTable->mpMaterials[uVar4]->field_0x20 = 0xc0000000;
    }
  }
  else {
    for (uVar4 = 0; uVar4 < this->mpMaterialTable->mMaterialCount; uVar4 = uVar4 + 1) {
      pJVar3 = (J3DMaterial *)
               J3DMaterialFactory::create
                         (aJStack152,this->mpMaterialTable->mpMaterials[uVar4],1,(uint)uVar4,param_2
                         );
      this->mpMaterialTable->mpMaterials[uVar4] = pJVar3;
    }
  }
  return;
}


/* __thiscall J3DModelLoader::modifyMaterial(unsigned long) */

void __thiscall J3DModelLoader::modifyMaterial(J3DModelLoader *this,ulong param_1)

{
  ushort uVar1;
  J3DMaterialFactory aJStack152 [12];
  
  if ((param_1 & 0x2000) != 0) {
    J3DMaterialFactory::J3DMaterialFactory(aJStack152,*(J3DMaterialBlock **)&this->field_0x10);
    for (uVar1 = 0; uVar1 < this->mpMaterialTable->mMaterialCount; uVar1 = uVar1 + 1) {
      J3DMaterialFactory::modifyPatchedCurrentMtx
                (aJStack152,this->mpMaterialTable->mpMaterials[uVar1],(uint)uVar1);
    }
  }
  return;
}


/* __thiscall J3DModelLoader_v26::~J3DModelLoader_v26(void) */

void __thiscall J3DModelLoader_v26::_J3DModelLoader_v26(J3DModelLoader_v26 *this)

{
  short in_r4;
  
  if (this != (J3DModelLoader_v26 *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DModelLoader_v26 *)0x0) {
      *(undefined1 **)this = &J3DModelLoader::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DModelLoader_v21::~J3DModelLoader_v21(void) */

void __thiscall J3DModelLoader_v21::_J3DModelLoader_v21(J3DModelLoader_v21 *this)

{
  short in_r4;
  
  if (this != (J3DModelLoader_v21 *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DModelLoader_v21 *)0x0) {
      *(undefined1 **)this = &J3DModelLoader::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DModelLoader::~J3DModelLoader(void) */

void __thiscall J3DModelLoader::_J3DModelLoader(J3DModelLoader *this)

{
  short in_r4;
  
  if ((this != (J3DModelLoader *)0x0) && (this->vtbl = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall J3DModelLoader::readMaterial_v21(J3DMaterialBlock_v21 const *,
                                               unsigned long) */

void __thiscall
J3DModelLoader::readMaterial_v21(J3DModelLoader *this,J3DMaterialBlock_v21 *param_1,ulong param_2)

{
  return;
}


/* __thiscall J3DModelLoader::readMaterial(J3DMaterialBlock const *,
                                           unsigned long) */

void __thiscall
J3DModelLoader::readMaterial(J3DModelLoader *this,J3DMaterialBlock *param_1,ulong param_2)

{
  return;
}


/* __thiscall J3DModelLoader::readMaterialTable_v21(J3DMaterialBlock_v21 const *,
                                                    unsigned long) */

void __thiscall
J3DModelLoader::readMaterialTable_v21
          (J3DModelLoader *this,J3DMaterialBlock_v21 *param_1,ulong param_2)

{
  return;
}


/* __thiscall J3DModelLoader::readMaterialTable(J3DMaterialBlock const *,
                                                unsigned long) */

void __thiscall
J3DModelLoader::readMaterialTable(J3DModelLoader *this,J3DMaterialBlock *param_1,ulong param_2)

{
  return;
}


/* __thiscall J3DModelLoader::calcSizeMaterial(J3DMaterialBlock const *,
                                               unsigned long) */

undefined4 __thiscall
J3DModelLoader::calcSizeMaterial(J3DModelLoader *this,J3DMaterialBlock *param_1,ulong param_2)

{
  return 0;
}


/* __thiscall J3DModelLoader::calcSizeMaterialTable(J3DMaterialBlock const *,
                                                    unsigned long) */

undefined4 __thiscall
J3DModelLoader::calcSizeMaterialTable(J3DModelLoader *this,J3DMaterialBlock *param_1,ulong param_2)

{
  return 0;
}


/* __thiscall J3DMaterial::J3DMaterial(void) */

void __thiscall J3DMaterial::J3DMaterial(J3DMaterial *this)

{
  this->vtbl = (undefined *)&__vt;
  this->field_0x40 = (undefined *)0x3cf3cf00;
  this->field_0x44 = (undefined *)0xf3cf3c;
  initialize(this);
  return;
}


/* __thiscall J3DTexture::~J3DTexture(void) */

void __thiscall J3DTexture::_J3DTexture(J3DTexture *this)

{
  short in_r4;
  
  if ((this != (J3DTexture *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace J3DGraphLoader {

/* __stdcall JSUConvertOffsetToPtr<ResTIMG>(void const *,
                                            void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<float[][][]>(void const *,
                                                void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<void>(void const *,
                                         void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<_GXVtxAttrFmtList>(void const *,
                                                      void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DModelHierarchy>(void const *,
                                                      void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DShapeInitData>(void const *,
                                                     unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<unsigned short>(void const *,
                                                   unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}

