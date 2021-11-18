#include <J3DGraphAnimator/J3DCluster.h>
#include <J3DGraphAnimator/J3DCluster.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <os/OSCache.h>
#include <MSL_C.PPCEABI.bare.H/w_acos.h>
#include <JKernel/JKRHeap.h>
#include <m_Do_printf.h>
#include <J3DGraphBase/J3DShape.h>
#include <J3DGraphBase/J3DTransform.h>
#include <J3DDeformData.h>
#include <J3DDeformer.h>
#include <Demangler/J3DSkinDeform.h>


namespace J3DSkinDeform {
}

/* __thiscall J3DDeformData::clear(void) */

void __thiscall J3DDeformData::clear(J3DDeformData *this)

{
  *(undefined2 *)this = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined2 *)(this + 2) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  return;
}


/* __thiscall J3DDeformData::J3DDeformData(void) */

void __thiscall J3DDeformData::J3DDeformData(J3DDeformData *this)

{
  clear(this);
  return;
}


/* __thiscall J3DDeformData::deform(J3DModel *) */

void __thiscall J3DDeformData::deform(J3DDeformData *this,J3DModel *param_1)

{
  deform(this,&param_1->mVertexBuffer);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DDeformData::deform(J3DVertexBuffer *) */

void __thiscall J3DDeformData::deform(J3DDeformData *this,J3DVertexBuffer *pBuffer)

{
  undefined *puVar1;
  ushort uVar2;
  
  puVar1 = pBuffer->mpVertexArr_Pos;
  pBuffer->mpVertexArr_Pos = pBuffer->field_0x8;
  pBuffer->field_0x8 = puVar1;
  puVar1 = pBuffer->mpVertexArr_Nrm;
  pBuffer->mpVertexArr_Nrm = pBuffer->field_0x10;
  pBuffer->field_0x10 = puVar1;
  for (uVar2 = 0; uVar2 < *(ushort *)this; uVar2 = uVar2 + 1) {
    J3DDeformer::deform(*(J3DDeformer **)(*(int *)(this + 8) + (uint)uVar2 * 0x24 + 0x20),pBuffer,
                        uVar2);
  }
  os::DCStoreRange(pBuffer->mpVertexArr_Pos,pBuffer->mpVertexData->mVertexCount * 0xc);
  os::DCStoreRange(pBuffer->mpVertexArr_Nrm,pBuffer->mpVertexData->mArrSizeNrm * 0xc);
  pBuffer->mpCurrentVtxPos = pBuffer->mpVertexArr_Pos;
  pBuffer->mpCurrentVtxNrm = pBuffer->mpVertexArr_Nrm;
  return;
}


/* __thiscall J3DDeformer::clear(void) */

void __thiscall J3DDeformer::clear(J3DDeformer *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 3;
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall J3DDeformer::deform(J3DVertexBuffer *,
                                  unsigned short) */

void __thiscall J3DDeformer::deform(J3DDeformer *this,J3DVertexBuffer *param_1,ushort param_2)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  double dVar4;
  
  iVar3 = 0;
  if (*(int *)(this + 4) != 0) {
    for (uVar1 = 0; (uVar1 & 0xffff) < (uint)param_2; uVar1 = uVar1 + 1) {
      iVar3 = iVar3 + (uint)*(ushort *)(*(int *)(*(int *)this + 8) + (uVar1 & 0xffff) * 0x24 + 0x10)
      ;
    }
    for (uVar2 = 0; uVar2 < *(ushort *)(*(int *)(*(int *)this + 8) + (uint)param_2 * 0x24 + 0x10);
        uVar2 = uVar2 + 1) {
      dVar4 = (double)(**(code **)(**(int **)(this + 4) + 0xc))(*(int **)(this + 4),iVar3);
      *(float *)(*(int *)(this + 8) + (uint)uVar2 * 4) = (float)dVar4;
      iVar3 = iVar3 + 1;
    }
    deform(this,param_1,param_2,*(float **)(this + 8));
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x802f3f80) */
/* WARNING: Removing unreachable block (ram,0x802f3f78) */
/* WARNING: Removing unreachable block (ram,0x802f3f88) */
/* __thiscall J3DDeformer::deform(J3DVertexBuffer *,
                                  unsigned short,
                                  float *) */

void __thiscall
J3DDeformer::deform(J3DDeformer *this,J3DVertexBuffer *param_1,ushort param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  undefined *puVar7;
  float *pfVar8;
  uint uVar9;
  float *pfVar10;
  int iVar11;
  float fVar12;
  uint uVar13;
  ushort uVar14;
  ushort uVar15;
  ushort *puVar16;
  float *pfVar17;
  int iVar18;
  undefined4 uVar19;
  double dVar20;
  undefined8 in_f29;
  double dVar21;
  double dVar22;
  undefined8 in_f30;
  double dVar23;
  undefined8 in_f31;
  float local_78 [4];
  float local_68;
  undefined4 local_60;
  uint uStack92;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar19 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if (((*(uint *)(this + 0x10) & 2) != 0) && (*(int *)&param_1->mpVertexData->field_0x4c == 4)) {
    iVar11 = *(int *)(*(int *)this + 8);
    pfVar17 = (float *)(iVar11 + (uint)param_2 * 0x24);
    uVar15 = *(ushort *)((int)pfVar17 + 0x12);
    uVar14 = *(ushort *)(pfVar17 + 4);
    uVar9 = 0;
    for (uVar13 = 0; (uVar13 & 0xffff) < (uint)param_2; uVar13 = uVar13 + 1) {
      uVar9 = *(ushort *)(iVar11 + (uVar13 & 0xffff) * 0x24 + 0x10) + uVar9 + 1 & 0xffff;
    }
    iVar18 = *(int *)(*(int *)this + 0xc) + uVar9 * 0xc;
    normalizeWeight(this,(uint)uVar14,param_3);
    fVar1 = J3DGraphAnimator::_1783;
    puVar7 = param_1->mpVertexArr_Pos;
    iVar6 = *(int *)(*(int *)this + 0x18);
    fVar12 = pfVar17[6];
    iVar11 = 0;
    for (uVar9 = (uint)uVar15; uVar9 != 0; uVar9 = uVar9 - 1) {
      pfVar10 = (float *)(puVar7 + (uint)*(ushort *)((int)fVar12 + iVar11) * 0xc);
      *pfVar10 = fVar1;
      pfVar10[1] = fVar1;
      pfVar10[2] = fVar1;
      iVar11 = iVar11 + 2;
    }
    local_78[0] = J3DGraphAnimator::_1647;
    local_78[1] = (float)DAT_803fc9c0;
    for (uVar9 = 0; (uVar9 & 0xffff) < (uint)uVar15; uVar9 = uVar9 + 1) {
      iVar11 = (uVar9 & 0xffff) * 2;
      for (uVar13 = 0; (uVar13 & 0xffff) < (uint)uVar14; uVar13 = uVar13 + 1) {
        uVar4 = *(ushort *)(iVar11 + *(int *)(iVar18 + (uVar13 & 0xffff) * 0xc + 4));
        pfVar10 = (float *)(iVar6 + (uVar4 & 0xffff1fff) * 0xc);
        fVar1 = pfVar10[1];
        fVar12 = pfVar10[2];
        fVar2 = *(float *)((int)local_78 + (uVar4 >> 0xc & 4));
        fVar3 = *(float *)((int)local_78 + (uVar4 >> 0xb & 4));
        pfVar8 = (float *)(puVar7 + (uint)*(ushort *)(iVar11 + (int)pfVar17[6]) * 0xc);
        uVar5 = uVar13 & 0xffff;
        *pfVar8 = *pfVar8 + *pfVar10 * *(float *)((int)local_78 + (uVar4 >> 0xd & 4)) *
                            param_3[uVar5];
        pfVar8[1] = pfVar8[1] + fVar1 * fVar2 * param_3[uVar5];
        pfVar8[2] = pfVar8[2] + fVar12 * fVar3 * param_3[uVar5];
      }
    }
    if ((((*(uint *)(this + 0x10) & 1) != 0) && (*(char *)(pfVar17 + 3) != '\0')) &&
       (*(int *)&param_1->mpVertexData->field_0x54 == 4)) {
      puVar7 = param_1->mpVertexArr_Nrm;
      iVar6 = *(int *)(*(int *)this + 0x1c);
      iVar11 = *(int *)(this + 0xc);
      dVar21 = (double)J3DGraphAnimator::_1783;
      for (uVar15 = 0; uVar15 < *(ushort *)(pfVar17 + 5); uVar15 = uVar15 + 1) {
        pfVar10 = (float *)(iVar11 + (uint)uVar15 * 0xc);
        *pfVar10 = (float)dVar21;
        pfVar10[1] = (float)dVar21;
        pfVar10[2] = (float)dVar21;
        for (uVar14 = 0; uVar14 < *(ushort *)(pfVar17 + 4); uVar14 = uVar14 + 1) {
          uVar9 = (uint)uVar14;
          uVar4 = *(ushort *)((uint)uVar15 * 2 + *(int *)(iVar18 + uVar9 * 0xc + 8));
          pfVar8 = (float *)(iVar6 + (uVar4 & 0xffff1fff) * 0xc);
          fVar1 = *pfVar8;
          fVar12 = pfVar8[1];
          fVar2 = pfVar8[2];
          if ((uVar4 & 0x8000) != 0) {
            fVar1 = -fVar1;
          }
          if ((uVar4 & 0x4000) != 0) {
            fVar12 = -fVar12;
          }
          if ((uVar4 & 0x2000) != 0) {
            fVar2 = -fVar2;
          }
          *pfVar10 = *pfVar10 + fVar1 * param_3[uVar9];
          pfVar10[1] = pfVar10[1] + fVar12 * param_3[uVar9];
          pfVar10[2] = pfVar10[2] + fVar2 * param_3[uVar9];
        }
        normalize(this,pfVar10);
      }
      dVar22 = (double)J3DGraphAnimator::_1783;
      dVar23 = (double)J3DGraphAnimator::_1629;
      dVar21 = J3DGraphAnimator::_1788;
      for (uVar15 = 0; uVar15 < *(ushort *)((int)pfVar17 + 0x16); uVar15 = uVar15 + 1) {
        puVar16 = (ushort *)((int)pfVar17[7] + (uint)uVar15 * 0xc);
        local_78[2] = (float)dVar22;
        local_78[3] = (float)dVar22;
        local_68 = (float)dVar22;
        uStack92 = (uint)*puVar16;
        local_60 = 0x43300000;
        fVar1 = (float)(dVar23 / (double)(float)((double)CONCAT44(0x43300000,uStack92) - dVar21));
        for (uVar14 = 0; uVar14 < *puVar16; uVar14 = uVar14 + 1) {
          pfVar10 = (float *)(iVar11 + (uint)*(ushort *)(*(int *)(puVar16 + 2) + (uint)uVar14 * 2) *
                                       0xc);
          local_78[2] = local_78[2] + fVar1 * *pfVar10;
          local_78[3] = local_78[3] + fVar1 * pfVar10[1];
          local_68 = local_68 + fVar1 * pfVar10[2];
        }
        normalize(this,local_78 + 2);
        for (uVar14 = 0; uVar14 < *puVar16; uVar14 = uVar14 + 1) {
          uVar9 = (uint)*(ushort *)(*(int *)(puVar16 + 4) + (uint)uVar14 * 2);
          if (uVar9 != 0xffff) {
            pfVar10 = (float *)(iVar11 + (uint)*(ushort *)(*(int *)(puVar16 + 2) + (uint)uVar14 * 2)
                                         * 0xc);
            dVar20 = (double)(local_68 * pfVar10[2] +
                             local_78[2] * *pfVar10 + local_78[3] * pfVar10[1]);
            fVar1 = J3DGraphAnimator::_1783;
            if ((dVar20 < (double)J3DGraphAnimator::_1629) &&
               (fVar1 = J3DGraphAnimator::_1785, (double)J3DGraphAnimator::_1784 < dVar20)) {
              dVar20 = MSL_C.PPCEABI.bare.H::acos(dVar20);
              fVar1 = (J3DGraphAnimator::_1785 * (float)dVar20) / J3DGraphAnimator::_1786;
            }
            fVar12 = pfVar17[1];
            if (fVar12 < fVar1) {
              if (fVar1 <= *pfVar17) {
                fVar1 = (fVar1 - fVar12) / (*pfVar17 - fVar12);
                fVar12 = J3DGraphAnimator::_1629 - fVar1;
                pfVar8 = (float *)(puVar7 + uVar9 * 0xc);
                *pfVar8 = fVar12 * local_78[2] + fVar1 * *pfVar10;
                pfVar8[1] = fVar12 * local_78[3] + fVar1 * pfVar10[1];
                pfVar8[2] = fVar12 * local_68 + fVar1 * pfVar10[2];
              }
              else {
                pfVar8 = (float *)(puVar7 + uVar9 * 0xc);
                *pfVar8 = *pfVar10;
                pfVar8[1] = pfVar10[1];
                pfVar8[2] = pfVar10[2];
              }
            }
            else {
              pfVar10 = (float *)(puVar7 + uVar9 * 0xc);
              *pfVar10 = local_78[2];
              pfVar10[1] = local_78[3];
              pfVar10[2] = local_68;
            }
          }
        }
      }
    }
  }
  __psq_l0(auStack8,uVar19);
  __psq_l1(auStack8,uVar19);
  __psq_l0(auStack24,uVar19);
  __psq_l1(auStack24,uVar19);
  __psq_l0(auStack40,uVar19);
  __psq_l1(auStack40,uVar19);
  return;
}


/* __thiscall J3DDeformer::normalize(float *) */

void __thiscall J3DDeformer::normalize(J3DDeformer *this,float *param_1)

{
  float fVar1;
  double dVar2;
  double dVar3;
  
  dVar3 = (double)(param_1[2] * param_1[2] + *param_1 * *param_1 + param_1[1] * param_1[1]);
  if ((double)J3DGraphAnimator::_1783 < dVar3) {
    dVar2 = 1.0 / SQRT(dVar3);
    dVar2 = J3DGraphAnimator::_1957 * dVar2 * (J3DGraphAnimator::_1958 - dVar3 * dVar2 * dVar2);
    dVar2 = J3DGraphAnimator::_1957 * dVar2 * (J3DGraphAnimator::_1958 - dVar3 * dVar2 * dVar2);
    dVar3 = (double)(float)(dVar3 * J3DGraphAnimator::_1957 * dVar2 *
                                    (J3DGraphAnimator::_1958 - dVar3 * dVar2 * dVar2));
  }
  fVar1 = (float)((double)J3DGraphAnimator::_1629 / dVar3);
  *param_1 = *param_1 * fVar1;
  param_1[1] = param_1[1] * fVar1;
  param_1[2] = param_1[2] * fVar1;
  return;
}


/* __thiscall J3DDeformer::normalizeWeight(int,
                                           float *) */

void __thiscall J3DDeformer::normalizeWeight(J3DDeformer *this,int param_1,float *param_2)

{
  float fVar1;
  uint uVar2;
  
  fVar1 = J3DGraphAnimator::_1783;
  for (uVar2 = 0; (int)(uVar2 & 0xffff) < param_1; uVar2 = uVar2 + 1) {
    fVar1 = fVar1 + param_2[uVar2 & 0xffff];
  }
  fVar1 = J3DGraphAnimator::_1629 / fVar1;
  for (uVar2 = 0; (int)(uVar2 & 0xffff) < param_1; uVar2 = uVar2 + 1) {
    param_2[uVar2 & 0xffff] = param_2[uVar2 & 0xffff] * fVar1;
  }
  return;
}


/* __thiscall J3DSkinDeform::J3DSkinDeform(void) */

void __thiscall J3DSkinDeform::J3DSkinDeform(J3DSkinDeform *this)

{
  *(undefined1 **)this = &__vt;
  *(undefined4 *)&this->field_0x4 = 0;
  *(undefined4 *)&this->field_0x8 = 0;
  *(undefined4 *)&this->field_0xc = 0;
  *(undefined4 *)&this->field_0x10 = 3;
  *(undefined *)&this->field_0x14 = 1;
  return;
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* __thiscall J3DSkinDeform::initMtxIndexArray(J3DModelData *) */

undefined4 __thiscall J3DSkinDeform::initMtxIndexArray(J3DSkinDeform *this,J3DModelData *param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  ushort uVar9;
  char *pcVar10;
  J3DShape **ppJVar11;
  J3DShape *pJVar12;
  uint uVar13;
  int *piVar14;
  char *pcVar15;
  ushort uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  ushort uVar21;
  char *pcVar22;
  int local_78 [4];
  ushort auStack104 [10];
  int *local_54;
  
  if ((*(int *)&this->field_0x4 == 0) || (*(int *)&this->field_0x8 == 0)) {
    uVar7 = JKernel::operator_new__((param_1->mVertexData).mVertexCount << 1);
    *(undefined4 *)&this->field_0x4 = uVar7;
    if (*(int *)&this->field_0x4 == 0) {
      uVar7 = 4;
    }
    else {
      iVar8 = 0;
      for (uVar13 = 0; uVar13 < (uint)(param_1->mVertexData).mVertexCount; uVar13 = uVar13 + 1) {
        *(undefined2 *)(*(int *)&this->field_0x4 + iVar8) = 0xffff;
        iVar8 = iVar8 + 2;
      }
      iVar8 = (param_1->mVertexData).mArrSizeNrm;
      if (iVar8 == 0) {
        *(undefined4 *)&this->field_0x8 = 0;
      }
      else {
        uVar7 = JKernel::operator_new__(iVar8 << 1);
        *(undefined4 *)&this->field_0x8 = uVar7;
        if (*(int *)&this->field_0x8 == 0) {
          return 4;
        }
        iVar8 = 0;
        for (uVar13 = 0; uVar13 < (uint)(param_1->mVertexData).mArrSizeNrm; uVar13 = uVar13 + 1) {
          *(undefined2 *)(*(int *)&this->field_0x8 + iVar8) = 0;
          iVar8 = iVar8 + 2;
        }
      }
      uVar7 = JKernel::operator_new__
                        ((uint)(ushort)(param_1->mJointTree).mDrawMtxData.mDrawMtxCount * 0x24,0x20)
      ;
      *(undefined4 *)&this->field_0xc = uVar7;
      if (*(int *)&this->field_0xc == 0) {
        uVar7 = 4;
      }
      else {
        for (uVar21 = 0; uVar21 < (param_1->mShapeTable).mShapeCount; uVar21 = uVar21 + 1) {
          local_78[0] = J3DGraphAnimator::_2006;
          local_78[1] = DAT_80370e5c;
          local_78[2] = DAT_80370e60;
          local_78[3] = DAT_80370e64;
          iVar18 = -1;
          iVar8 = -1;
          iVar17 = 0;
          uVar13 = (uint)uVar21;
          iVar20 = -1;
          for (piVar14 = (int *)(param_1->mShapeTable).mpShapes[uVar13]->mpAttrDecl;
              iVar5 = *piVar14, iVar5 != 0xff; piVar14 = piVar14 + 2) {
            iVar19 = iVar20;
            if (iVar5 == 10) {
              iVar8 = iVar17;
              if (piVar14[1] != 3) {
                m_Do_printf::OSReport(" Invlid Data : CPU Pipeline process GX_INDEX16 Data Only\n");
              }
            }
            else {
              if (iVar5 < 10) {
                iVar19 = iVar17;
                if ((((iVar5 != 0) && (iVar19 = iVar20, -1 < iVar5)) && (8 < iVar5)) &&
                   (iVar18 = iVar17, piVar14[1] != 3)) {
                  m_Do_printf::OSReport
                            (" Invlid Data : CPU Pipeline process GX_INDEX16 Data Only\n");
                }
              }
              else {
                if ((iVar5 == 0xd) && (piVar14[1] != 3)) {
                  m_Do_printf::OSReport
                            (" Invlid Data : CPU Pipeline process GX_INDEX16 Data Only\n");
                }
              }
            }
            iVar17 = iVar17 + local_78[piVar14[1]];
            iVar20 = iVar19;
          }
          for (uVar16 = 0; pJVar12 = (param_1->mShapeTable).mpShapes[uVar13],
              uVar16 < (ushort)pJVar12->mMtxGroupNum; uVar16 = uVar16 + 1) {
            uVar4 = (uint)uVar16;
            local_54 = (int *)pJVar12->mpShapeMtx[uVar4];
            pcVar22 = *(char **)(pJVar12->mpShapeDraw[uVar4] + 8);
            for (pcVar15 = pcVar22;
                (ppJVar11 = (param_1->mShapeTable).mpShapes,
                (uint)((int)pcVar15 - (int)pcVar22) <
                *(uint *)(ppJVar11[uVar13]->mpShapeDraw[uVar4] + 4) &&
                ((*pcVar15 == -0x60 || (*pcVar15 == -0x68))));
                pcVar15 = pcVar15 + iVar17 * (uint)uVar1 + 3) {
              uVar1 = *(ushort *)(pcVar15 + 1);
              for (iVar5 = 0; iVar5 < (int)(uint)uVar1; iVar5 = iVar5 + 1) {
                pcVar10 = pcVar15 + iVar17 * iVar5 + 3;
                uVar6 = (byte)pcVar10[iVar20] / 3;
                uVar2 = *(ushort *)(pcVar10 + iVar18);
                uVar3 = *(ushort *)(pcVar10 + iVar8);
                uVar9 = (**(code **)(*local_54 + 0x14))(local_54,uVar6);
                if (uVar9 == 0xffff) {
                  uVar9 = auStack104[uVar6];
                }
                else {
                  if (iVar20 != -1) {
                    auStack104[uVar6] = uVar9;
                  }
                }
                *(ushort *)(*(int *)&this->field_0x4 + (uint)uVar2 * 2) = uVar9;
                if (iVar8 != -1) {
                  *(ushort *)(*(int *)&this->field_0x8 + (uint)uVar3 * 2) = uVar9;
                }
              }
            }
            if (iVar8 == -1) {
              pJVar12 = ppJVar11[uVar13];
              pJVar12->mVisFlags = pJVar12->mVisFlags | 0x100;
              pJVar12 = (param_1->mShapeTable).mpShapes[uVar13];
              pJVar12->mVisFlags = pJVar12->mVisFlags & 0xfffffff7;
            }
          }
        }
        iVar8 = 0;
        for (uVar13 = 0; uVar13 < (uint)(param_1->mVertexData).mVertexCount; uVar13 = uVar13 + 1) {
          if (*(short *)(*(int *)&this->field_0x4 + iVar8) == -1) {
            *(undefined *)&this->field_0x14 = 0;
            *(undefined2 *)(*(int *)&this->field_0x4 + iVar8) = 0;
          }
          iVar8 = iVar8 + 2;
        }
        uVar7 = 0;
      }
    }
  }
  else {
    uVar7 = 0;
  }
  return uVar7;
}


/* WARNING: Inlined function: FUN_80328f10 */
/* WARNING: Inlined function: FUN_80328f5c */
/* __thiscall J3DSkinDeform::changeFastSkinDL(J3DModelData *) */

void __thiscall J3DSkinDeform::changeFastSkinDL(J3DSkinDeform *this,J3DModelData *param_1)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  char *pcVar4;
  int *piVar5;
  int *piVar6;
  J3DShape *pJVar7;
  int iVar8;
  ushort *dst;
  ushort *puVar9;
  ushort *puVar10;
  ushort uVar11;
  int iVar12;
  ushort uVar13;
  ushort *puVar14;
  int local_58 [7];
  
  uVar13 = 0;
  do {
    if ((param_1->mShapeTable).mShapeCount <= uVar13) {
      for (uVar13 = 0; uVar13 < (param_1->mShapeTable).mShapeCount; uVar13 = uVar13 + 1) {
        pJVar7 = (param_1->mShapeTable).mpShapes[uVar13];
        piVar5 = (int *)pJVar7->mpAttrDecl;
        piVar6 = piVar5;
        for (; *piVar5 != 0xff; piVar5 = piVar5 + 2) {
          if (*piVar5 != 0) {
            *piVar6 = *piVar5;
            piVar6[1] = piVar5[1];
            piVar6 = piVar6 + 2;
          }
        }
        *piVar6 = 0xff;
        piVar6[1] = 0;
        J3DShape::makeVcdVatCmd(pJVar7);
      }
      return;
    }
    local_58[0] = J3DGraphAnimator::_2118;
    local_58[1] = DAT_80370e6c;
    local_58[2] = DAT_80370e70;
    local_58[3] = DAT_80370e74;
    iVar8 = -1;
    iVar12 = 0;
    pJVar7 = (param_1->mShapeTable).mpShapes[uVar13];
    for (piVar6 = (int *)pJVar7->mpAttrDecl; *piVar6 != 0xff; piVar6 = piVar6 + 2) {
      if (*piVar6 == 0) {
        iVar8 = iVar12;
      }
      iVar12 = iVar12 + local_58[piVar6[1]];
    }
    if (iVar8 != -1) {
      for (uVar11 = 0; uVar11 < (ushort)pJVar7->mMtxGroupNum; uVar11 = uVar11 + 1) {
        uVar3 = (uint)uVar11;
        puVar14 = *(ushort **)(pJVar7->mpShapeDraw[uVar3] + 8);
        dst = puVar14;
        for (puVar10 = puVar14; puVar9 = dst,
            (uint)((int)puVar10 - (int)puVar14) < *(uint *)(pJVar7->mpShapeDraw[uVar3] + 4);
            puVar10 = (ushort *)((int)puVar10 + iVar12 * (uint)uVar2 + 3)) {
          cVar1 = *(char *)puVar10;
          *(char *)dst = cVar1;
          puVar9 = (ushort *)((int)dst + 1);
          if ((cVar1 != -0x60) && (cVar1 != -0x68)) break;
          uVar2 = *(ushort *)((int)puVar10 + 1);
          *puVar9 = uVar2;
          dst = (ushort *)((int)dst + 3);
          for (iVar8 = 0; iVar8 < (int)(uint)uVar2; iVar8 = iVar8 + 1) {
            copy_bytes((byte *)dst,(byte *)((int)puVar10 + iVar12 * iVar8 + 4),iVar12 + -1);
            dst = (ushort *)((int)dst + iVar12 + -1);
          }
        }
        pcVar4 = (char *)((int)puVar9 + (0x1f - (int)puVar14));
        for (; (uint)((int)puVar9 - (int)puVar14) < *(uint *)(pJVar7->mpShapeDraw[uVar3] + 4);
            puVar9 = (ushort *)((int)puVar9 + 1)) {
          *(char *)puVar9 = '\0';
        }
        *(uint *)(pJVar7->mpShapeDraw[uVar3] + 4) = (uint)pcVar4 & 0xffffffe0;
        os::DCStoreRange(puVar14,*(undefined4 *)(pJVar7->mpShapeDraw[uVar3] + 4));
      }
    }
    uVar13 = uVar13 + 1;
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DSkinDeform::calcNrmMtx(J3DModel *) */

void __thiscall J3DSkinDeform::calcNrmMtx(J3DSkinDeform *this,J3DModel *param_1)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  J3DModelData *pJVar4;
  
  pJVar4 = param_1->mpModelData;
  for (uVar3 = 0; uVar3 < (ushort)(pJVar4->mJointTree).mDrawMtxData.mDrawMtxCount; uVar3 = uVar3 + 1
      ) {
    uVar1 = (uint)uVar3;
    if ((pJVar4->mJointTree).mDrawMtxData.mpMtxTypeArray[uVar1] == 0) {
      uVar2 = (uint)(ushort)(pJVar4->mJointTree).mDrawMtxData.mpDataArray[uVar1];
      if (param_1->field_0x84[uVar2] == 1) {
        J3DGraphBase::J3DPSMtx33CopyFrom34
                  (param_1->mpNodeMtx + uVar2,*(int *)&this->field_0xc + uVar1 * 0x24);
      }
      else {
        J3DGraphBase::J3DPSCalcInverseTranspose
                  (param_1->mpNodeMtx + uVar2,*(int *)&this->field_0xc + uVar1 * 0x24);
      }
    }
    else {
      uVar2 = (uint)(ushort)(pJVar4->mJointTree).mDrawMtxData.mpDataArray[uVar1];
      if (param_1->field_0x88[uVar2] == '\x01') {
        J3DGraphBase::J3DPSMtx33CopyFrom34
                  (param_1->mpWeightEnvMtx + uVar2,*(int *)&this->field_0xc + uVar1 * 0x24);
      }
      else {
        J3DGraphBase::J3DPSCalcInverseTranspose
                  (param_1->mpWeightEnvMtx + uVar2,*(int *)&this->field_0xc + uVar1 * 0x24);
      }
    }
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x802f4928) */
/* WARNING: Removing unreachable block (ram,0x802f4918) */
/* WARNING: Removing unreachable block (ram,0x802f4908) */
/* WARNING: Removing unreachable block (ram,0x802f48f8) */
/* WARNING: Removing unreachable block (ram,0x802f48ec) */
/* WARNING: Removing unreachable block (ram,0x802f48e8) */
/* WARNING: Removing unreachable block (ram,0x802f48f0) */
/* WARNING: Removing unreachable block (ram,0x802f4900) */
/* WARNING: Removing unreachable block (ram,0x802f4910) */
/* WARNING: Removing unreachable block (ram,0x802f4920) */
/* WARNING: Removing unreachable block (ram,0x802f4934) */
/* __thiscall J3DSkinDeform::deformVtxPos_F32(J3DModel *) const */

void __thiscall J3DSkinDeform::deformVtxPos_F32(J3DSkinDeform *this,J3DModel *param_1)

{
  float *pfVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  MTX34 *pMVar7;
  undefined *puVar8;
  undefined *puVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  MTX34 *local_18 [4];
  
  local_18[0] = param_1->mpNodeMtx;
  local_18[1] = param_1->mpWeightEnvMtx;
  puVar4 = (param_1->mVertexBuffer).mpTransformedVtxPos[0];
  (param_1->mVertexBuffer).mpTransformedVtxPos[0] = (param_1->mVertexBuffer).mpTransformedVtxPos[1];
  (param_1->mVertexBuffer).mpTransformedVtxPos[1] = puVar4;
  iVar2 = (param_1->mpModelData->mVertexData).mVertexCount;
  puVar4 = (param_1->mVertexBuffer).mpTransformedVtxPos[0];
  iVar5 = 0;
  iVar6 = 0;
  if (0 < iVar2) {
    do {
      uVar3 = (uint)*(ushort *)(*(int *)&this->field_0x4 + iVar6);
      puVar9 = puVar4 + iVar5;
      puVar8 = (param_1->mVertexBuffer).mpCurrentVtxPos + iVar5;
      pMVar7 = local_18[(param_1->mpModelData->mJointTree).mDrawMtxData.mpMtxTypeArray[uVar3]] +
               (ushort)(param_1->mpModelData->mJointTree).mDrawMtxData.mpDataArray[uVar3];
      fVar10 = (float)__psq_l0(puVar8,0);
      fVar11 = (float)__psq_l1(puVar8,0);
      fVar13 = (float)__psq_l0(pMVar7,0);
      fVar14 = (float)__psq_l1(pMVar7,0);
      fVar12 = (float)__psq_l0(puVar8 + 8,0);
      pfVar1 = pMVar7->m + 2;
      fVar15 = (float)__psq_l0(pfVar1,0);
      fVar16 = (float)__psq_l1(pfVar1,0);
      fVar17 = (float)__psq_l0(pMVar7->m[1],0);
      fVar18 = (float)__psq_l1(pMVar7->m[1],0);
      pfVar1 = pMVar7->m[1] + 2;
      fVar19 = (float)__psq_l0(pfVar1,0);
      fVar20 = (float)__psq_l1(pfVar1,0);
      __psq_st0(puVar9,fVar15 * fVar12 + fVar13 * fVar10 + fVar16 * 1.0 + fVar14 * fVar11,0);
      fVar13 = (float)__psq_l0(pMVar7->m[2],0);
      fVar14 = (float)__psq_l1(pMVar7->m[2],0);
      pfVar1 = pMVar7->m[2] + 2;
      fVar15 = (float)__psq_l0(pfVar1,0);
      fVar16 = (float)__psq_l1(pfVar1,0);
      __psq_st0(puVar9 + 4,fVar19 * fVar12 + fVar17 * fVar10 + fVar20 * 1.0 + fVar18 * fVar11,0);
      __psq_st0(puVar9 + 8,fVar15 * fVar12 + fVar13 * fVar10 + fVar16 * 1.0 + fVar14 * fVar11,0);
      iVar5 = iVar5 + 0xc;
      iVar6 = iVar6 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  os::DCStoreRange((param_1->mVertexBuffer).mpTransformedVtxPos[0],
                   (param_1->mpModelData->mVertexData).mVertexCount * 0xc);
  (param_1->mVertexBuffer).mpCurrentVtxPos = puVar4;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802f4a68) */
/* WARNING: Removing unreachable block (ram,0x802f4a58) */
/* WARNING: Removing unreachable block (ram,0x802f4a48) */
/* WARNING: Removing unreachable block (ram,0x802f4a38) */
/* WARNING: Removing unreachable block (ram,0x802f4a2c) */
/* WARNING: Removing unreachable block (ram,0x802f4a28) */
/* WARNING: Removing unreachable block (ram,0x802f4a30) */
/* WARNING: Removing unreachable block (ram,0x802f4a40) */
/* WARNING: Removing unreachable block (ram,0x802f4a50) */
/* WARNING: Removing unreachable block (ram,0x802f4a60) */
/* WARNING: Removing unreachable block (ram,0x802f4a74) */
/* __thiscall J3DSkinDeform::deformVtxPos_S16(J3DModel *) const */

void __thiscall J3DSkinDeform::deformVtxPos_S16(J3DSkinDeform *this,J3DModel *param_1)

{
  float *pfVar1;
  undefined uVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  MTX34 *pMVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined4 uVar11;
  undefined4 in_GQR7;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  MTX34 *local_18 [3];
  
  uVar11 = 0;
  local_18[0] = param_1->mpNodeMtx;
  local_18[1] = param_1->mpWeightEnvMtx;
  uVar2 = *(undefined *)&(param_1->mpModelData->mVertexData).mPacketCount;
  J3DGraphBase::J3DGQRSetup7(uVar2,7,uVar2,7);
  puVar5 = (param_1->mVertexBuffer).mpTransformedVtxPos[0];
  (param_1->mVertexBuffer).mpTransformedVtxPos[0] = (param_1->mVertexBuffer).mpTransformedVtxPos[1];
  (param_1->mVertexBuffer).mpTransformedVtxPos[1] = puVar5;
  iVar3 = (param_1->mpModelData->mVertexData).mVertexCount;
  puVar5 = (param_1->mVertexBuffer).mpTransformedVtxPos[0];
  iVar6 = 0;
  iVar7 = 0;
  if (0 < iVar3) {
    do {
      uVar4 = (uint)*(ushort *)(*(int *)&this->field_0x4 + iVar7);
      puVar10 = puVar5 + iVar6;
      puVar9 = (param_1->mVertexBuffer).mpCurrentVtxPos + iVar6;
      pMVar8 = local_18[(param_1->mpModelData->mJointTree).mDrawMtxData.mpMtxTypeArray[uVar4]] +
               (ushort)(param_1->mpModelData->mJointTree).mDrawMtxData.mpDataArray[uVar4];
      fVar12 = (float)__psq_l0(puVar9,in_GQR7);
      fVar13 = (float)__psq_l1(puVar9,in_GQR7);
      fVar15 = (float)__psq_l0(pMVar8,uVar11);
      fVar16 = (float)__psq_l1(pMVar8,uVar11);
      fVar14 = (float)__psq_l0(puVar9 + 4,in_GQR7);
      pfVar1 = pMVar8->m + 2;
      fVar17 = (float)__psq_l0(pfVar1,uVar11);
      fVar18 = (float)__psq_l1(pfVar1,uVar11);
      fVar19 = (float)__psq_l0(pMVar8->m[1],uVar11);
      fVar20 = (float)__psq_l1(pMVar8->m[1],uVar11);
      pfVar1 = pMVar8->m[1] + 2;
      fVar21 = (float)__psq_l0(pfVar1,uVar11);
      fVar22 = (float)__psq_l1(pfVar1,uVar11);
      __psq_st0(puVar10,fVar17 * fVar14 + fVar15 * fVar12 + fVar18 * 1.0 + fVar16 * fVar13,in_GQR7);
      fVar15 = (float)__psq_l0(pMVar8->m[2],uVar11);
      fVar16 = (float)__psq_l1(pMVar8->m[2],uVar11);
      pfVar1 = pMVar8->m[2] + 2;
      fVar17 = (float)__psq_l0(pfVar1,uVar11);
      fVar18 = (float)__psq_l1(pfVar1,uVar11);
      __psq_st0(puVar10 + 2,fVar21 * fVar14 + fVar19 * fVar12 + fVar22 * 1.0 + fVar20 * fVar13,
                in_GQR7);
      __psq_st0(puVar10 + 4,fVar17 * fVar14 + fVar15 * fVar12 + fVar18 * 1.0 + fVar16 * fVar13,
                in_GQR7);
      iVar6 = iVar6 + 6;
      iVar7 = iVar7 + 2;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  os::DCStoreRange((param_1->mVertexBuffer).mpTransformedVtxPos[0],
                   (param_1->mpModelData->mVertexData).mVertexCount * 6);
  (param_1->mVertexBuffer).mpCurrentVtxPos = puVar5;
  return;
}


/* WARNING: Removing unreachable block (ram,0x802f4b6c) */
/* WARNING: Removing unreachable block (ram,0x802f4b5c) */
/* WARNING: Removing unreachable block (ram,0x802f4b4c) */
/* WARNING: Removing unreachable block (ram,0x802f4b38) */
/* WARNING: Removing unreachable block (ram,0x802f4b2c) */
/* WARNING: Removing unreachable block (ram,0x802f4b20) */
/* WARNING: Removing unreachable block (ram,0x802f4b28) */
/* WARNING: Removing unreachable block (ram,0x802f4b30) */
/* WARNING: Removing unreachable block (ram,0x802f4b40) */
/* WARNING: Removing unreachable block (ram,0x802f4b54) */
/* WARNING: Removing unreachable block (ram,0x802f4b64) */
/* WARNING: Removing unreachable block (ram,0x802f4b78) */
/* __thiscall J3DSkinDeform::deformVtxNrm_F32(J3DModel *) const */

void __thiscall J3DSkinDeform::deformVtxNrm_F32(J3DSkinDeform *this,J3DModel *param_1)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  undefined *puVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  
  puVar2 = (param_1->mVertexBuffer).mpTransformVtxNrm[0];
  (param_1->mVertexBuffer).mpTransformVtxNrm[0] = (param_1->mVertexBuffer).mpTransformVtxNrm[1];
  (param_1->mVertexBuffer).mpTransformVtxNrm[1] = puVar2;
  iVar1 = (param_1->mpModelData->mVertexData).mArrSizeNrm;
  puVar2 = (param_1->mVertexBuffer).mpTransformVtxNrm[0];
  iVar3 = 0;
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      puVar7 = puVar2 + iVar4;
      puVar6 = (param_1->mVertexBuffer).mpCurrentVtxNrm + iVar4;
      iVar5 = *(int *)&this->field_0xc + (uint)*(ushort *)(*(int *)&this->field_0x8 + iVar3) * 0x24;
      fVar8 = (float)__psq_l0(puVar6,0);
      fVar9 = (float)__psq_l1(puVar6,0);
      fVar11 = (float)__psq_l0(iVar5,0);
      fVar12 = (float)__psq_l1(iVar5,0);
      fVar16 = (float)__psq_l0(0x8039d8b8,0);
      fVar17 = (float)__psq_l1(0x8039d8b8,0);
      fVar10 = (float)__psq_l0(puVar6 + 8,0);
      fVar16 = fVar16 + fVar10;
      fVar17 = fVar17 + 1.0;
      fVar10 = (float)__psq_l0(iVar5 + 8,0);
      fVar13 = (float)__psq_l0(iVar5 + 0xc,0);
      fVar14 = (float)__psq_l1(iVar5 + 0xc,0);
      fVar15 = (float)__psq_l0(iVar5 + 0x14,0);
      __psq_st0(puVar7,fVar10 * fVar16 + fVar11 * fVar8 + fVar17 * 1.0 + fVar12 * fVar9,0);
      fVar10 = (float)__psq_l0(iVar5 + 0x18,0);
      fVar11 = (float)__psq_l1(iVar5 + 0x18,0);
      fVar12 = (float)__psq_l0(iVar5 + 0x20,0);
      __psq_st0(puVar7 + 4,fVar15 * fVar16 + fVar13 * fVar8 + fVar17 * 1.0 + fVar14 * fVar9,0);
      __psq_st0(puVar7 + 8,fVar12 * fVar16 + fVar10 * fVar8 + fVar17 * 1.0 + fVar11 * fVar9,0);
      iVar3 = iVar3 + 2;
      iVar4 = iVar4 + 0xc;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  os::DCStoreRange((param_1->mVertexBuffer).mpTransformVtxNrm[0],
                   (param_1->mpModelData->mVertexData).mArrSizeNrm * 0xc);
  (param_1->mVertexBuffer).mpCurrentVtxNrm = puVar2;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802f4c8c) */
/* WARNING: Removing unreachable block (ram,0x802f4c7c) */
/* WARNING: Removing unreachable block (ram,0x802f4c6c) */
/* WARNING: Removing unreachable block (ram,0x802f4c58) */
/* WARNING: Removing unreachable block (ram,0x802f4c4c) */
/* WARNING: Removing unreachable block (ram,0x802f4c40) */
/* WARNING: Removing unreachable block (ram,0x802f4c48) */
/* WARNING: Removing unreachable block (ram,0x802f4c50) */
/* WARNING: Removing unreachable block (ram,0x802f4c60) */
/* WARNING: Removing unreachable block (ram,0x802f4c74) */
/* WARNING: Removing unreachable block (ram,0x802f4c84) */
/* WARNING: Removing unreachable block (ram,0x802f4c98) */
/* __thiscall J3DSkinDeform::deformVtxNrm_S16(J3DModel *) const */

void __thiscall J3DSkinDeform::deformVtxNrm_S16(J3DSkinDeform *this,J3DModel *param_1)

{
  undefined uVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined4 uVar9;
  undefined4 in_GQR7;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  
  uVar9 = 0;
  uVar1 = *(undefined *)&(param_1->mpModelData->mVertexData).field_0x50;
  J3DGraphBase::J3DGQRSetup7(uVar1,7,uVar1,7);
  puVar3 = (param_1->mVertexBuffer).mpTransformVtxNrm[0];
  (param_1->mVertexBuffer).mpTransformVtxNrm[0] = (param_1->mVertexBuffer).mpTransformVtxNrm[1];
  (param_1->mVertexBuffer).mpTransformVtxNrm[1] = puVar3;
  iVar2 = (param_1->mpModelData->mVertexData).mArrSizeNrm;
  puVar3 = (param_1->mVertexBuffer).mpTransformVtxNrm[0];
  iVar4 = 0;
  iVar5 = 0;
  if (0 < iVar2) {
    do {
      puVar8 = puVar3 + iVar5;
      puVar7 = (param_1->mVertexBuffer).mpCurrentVtxNrm + iVar5;
      iVar6 = *(int *)&this->field_0xc + (uint)*(ushort *)(*(int *)&this->field_0x8 + iVar4) * 0x24;
      fVar10 = (float)__psq_l0(puVar7,in_GQR7);
      fVar11 = (float)__psq_l1(puVar7,in_GQR7);
      fVar13 = (float)__psq_l0(iVar6,uVar9);
      fVar14 = (float)__psq_l1(iVar6,uVar9);
      fVar18 = (float)__psq_l0(0x8039d8b8,uVar9);
      fVar19 = (float)__psq_l1(0x8039d8b8,uVar9);
      fVar12 = (float)__psq_l0(puVar7 + 4,in_GQR7);
      fVar18 = fVar18 + fVar12;
      fVar19 = fVar19 + 1.0;
      fVar12 = (float)__psq_l0(iVar6 + 8,uVar9);
      fVar15 = (float)__psq_l0(iVar6 + 0xc,uVar9);
      fVar16 = (float)__psq_l1(iVar6 + 0xc,uVar9);
      fVar17 = (float)__psq_l0(iVar6 + 0x14,uVar9);
      __psq_st0(puVar8,fVar12 * fVar18 + fVar13 * fVar10 + fVar19 * 1.0 + fVar14 * fVar11,in_GQR7);
      fVar12 = (float)__psq_l0(iVar6 + 0x18,uVar9);
      fVar13 = (float)__psq_l1(iVar6 + 0x18,uVar9);
      fVar14 = (float)__psq_l0(iVar6 + 0x20,uVar9);
      __psq_st0(puVar8 + 2,fVar17 * fVar18 + fVar15 * fVar10 + fVar19 * 1.0 + fVar16 * fVar11,
                in_GQR7);
      __psq_st0(puVar8 + 4,fVar14 * fVar18 + fVar12 * fVar10 + fVar19 * 1.0 + fVar13 * fVar11,
                in_GQR7);
      iVar4 = iVar4 + 2;
      iVar5 = iVar5 + 6;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  os::DCStoreRange((param_1->mVertexBuffer).mpTransformVtxNrm[0],
                   (param_1->mpModelData->mVertexData).mArrSizeNrm * 6);
  (param_1->mVertexBuffer).mpCurrentVtxNrm = puVar3;
  return;
}


/* __thiscall J3DSkinDeform::deform(J3DModel *) */

void __thiscall J3DSkinDeform::deform(J3DSkinDeform *this,J3DModel *param_1)

{
  if ((param_1->mFlags & 4) != 0) {
    if (*(int *)&(param_1->mpModelData->mVertexData).field_0x4c == 4) {
      deformVtxPos_F32(this,param_1);
    }
    else {
      deformVtxPos_S16(this,param_1);
    }
  }
  if ((param_1->mFlags & 8) != 0) {
    calcNrmMtx(this,param_1);
    if (*(int *)&(param_1->mpModelData->mVertexData).field_0x54 == 4) {
      deformVtxNrm_F32(this,param_1);
    }
    else {
      deformVtxNrm_S16(this,param_1);
    }
  }
  return;
}


/* __thiscall J3DSkinDeform::~J3DSkinDeform(void) */

void __thiscall J3DSkinDeform::_J3DSkinDeform(J3DSkinDeform *this)

{
  short in_r4;
  
  if ((this != (J3DSkinDeform *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

