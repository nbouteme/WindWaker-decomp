#include <mtx/mtxvec.h>


namespace mtx {

/* WARNING: Removing unreachable block (ram,0x8030da84) */
/* WARNING: Removing unreachable block (ram,0x8030da74) */
/* WARNING: Removing unreachable block (ram,0x8030da64) */
/* WARNING: Removing unreachable block (ram,0x8030da54) */
/* WARNING: Removing unreachable block (ram,0x8030da48) */
/* WARNING: Removing unreachable block (ram,0x8030da44) */
/* WARNING: Removing unreachable block (ram,0x8030da4c) */
/* WARNING: Removing unreachable block (ram,0x8030da5c) */
/* WARNING: Removing unreachable block (ram,0x8030da6c) */
/* WARNING: Removing unreachable block (ram,0x8030da7c) */
/* WARNING: Removing unreachable block (ram,0x8030da90) */

void PSMTXMultVec(MTX34 *pMtx,cXyz *pSrc,cXyz *pDst)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  fVar2 = (float)__psq_l0(pSrc,0);
  fVar3 = (float)__psq_l1(pSrc,0);
  fVar5 = (float)__psq_l0(pMtx,0);
  fVar6 = (float)__psq_l1(pMtx,0);
  fVar4 = (float)__psq_l0(&pSrc->z,0);
  pfVar1 = pMtx->m + 2;
  fVar7 = (float)__psq_l0(pfVar1,0);
  fVar8 = (float)__psq_l1(pfVar1,0);
  fVar9 = (float)__psq_l0(pMtx->m[1],0);
  fVar10 = (float)__psq_l1(pMtx->m[1],0);
  pfVar1 = pMtx->m[1] + 2;
  fVar11 = (float)__psq_l0(pfVar1,0);
  fVar12 = (float)__psq_l1(pfVar1,0);
  __psq_st0(pDst,fVar7 * fVar4 + fVar5 * fVar2 + fVar8 * 1.0 + fVar6 * fVar3,0);
  fVar5 = (float)__psq_l0(pMtx->m[2],0);
  fVar6 = (float)__psq_l1(pMtx->m[2],0);
  pfVar1 = pMtx->m[2] + 2;
  fVar7 = (float)__psq_l0(pfVar1,0);
  fVar8 = (float)__psq_l1(pfVar1,0);
  __psq_st0(&pDst->y,fVar11 * fVar4 + fVar9 * fVar2 + fVar12 * 1.0 + fVar10 * fVar3,0);
  __psq_st0(&pDst->z,fVar7 * fVar4 + fVar5 * fVar2 + fVar8 * 1.0 + fVar6 * fVar3,0);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8030db1c) */
/* WARNING: Removing unreachable block (ram,0x8030db18) */
/* WARNING: Removing unreachable block (ram,0x8030db04) */
/* WARNING: Removing unreachable block (ram,0x8030dae4) */
/* WARNING: Removing unreachable block (ram,0x8030daec) */
/* WARNING: Removing unreachable block (ram,0x8030dad0) */
/* WARNING: Removing unreachable block (ram,0x8030dacc) */
/* WARNING: Removing unreachable block (ram,0x8030dabc) */
/* WARNING: Removing unreachable block (ram,0x8030daa4) */
/* WARNING: Removing unreachable block (ram,0x8030da98) */
/* WARNING: Removing unreachable block (ram,0x8030da9c) */
/* WARNING: Removing unreachable block (ram,0x8030dab0) */
/* WARNING: Removing unreachable block (ram,0x8030dac4) */
/* WARNING: Removing unreachable block (ram,0x8030dafc) */

void PSMTXMultVecArray(int param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  float fVar6;
  float fVar7;
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
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  
  fVar23 = (float)__psq_l0(param_1,0);
  fVar24 = (float)__psq_l1(param_1,0);
  fVar21 = (float)__psq_l0(param_1 + 0x10,0);
  fVar22 = (float)__psq_l1(param_1 + 0x10,0);
  param_4 = param_4 + -1;
  fVar19 = (float)__psq_l0(param_1 + 8,0);
  fVar20 = (float)__psq_l1(param_1 + 8,0);
  fVar17 = (float)__psq_l0(param_1 + 0x18,0);
  fVar18 = (float)__psq_l1(param_1 + 0x18,0);
  fVar6 = (float)__psq_l0(param_1 + 0x20,0);
  fVar7 = (float)__psq_l1(param_1 + 0x20,0);
  fVar8 = (float)__psq_l0(param_1 + 0x28,0);
  fVar9 = (float)__psq_l1(param_1 + 0x28,0);
  fVar10 = (float)__psq_l0(param_2,0);
  fVar12 = (float)__psq_l1(param_2,0);
  pfVar4 = (float *)(param_2 + 8);
  fVar14 = *pfVar4;
  fVar15 = fVar24 * fVar12 + fVar23 * fVar10 + fVar20;
  fVar16 = fVar22 * fVar12 + fVar21 * fVar10 + fVar18;
  fVar10 = fVar8 * fVar14 + fVar6 * fVar10;
  fVar12 = fVar9 * 1.0 + fVar7 * fVar12;
  pfVar3 = (float *)(param_3 + -4);
  do {
    pfVar5 = pfVar3;
    fVar11 = pfVar4[1];
    fVar13 = pfVar4[2];
    fVar1 = fVar19 * fVar14;
    fVar2 = fVar17 * fVar14;
    pfVar4 = pfVar4 + 3;
    fVar14 = *pfVar4;
    pfVar5[1] = fVar1 + fVar15;
    pfVar5[2] = fVar2 + fVar16;
    fVar15 = fVar24 * fVar13 + fVar23 * fVar11 + fVar20;
    fVar16 = fVar22 * fVar13 + fVar21 * fVar11 + fVar18;
    pfVar5[3] = fVar10 + fVar12;
    fVar10 = fVar8 * fVar14 + fVar6 * fVar11;
    fVar12 = fVar9 * 1.0 + fVar7 * fVar13;
    param_4 = param_4 + -1;
    pfVar3 = pfVar5 + 3;
  } while (param_4 != 0);
  pfVar5[4] = fVar19 * fVar14 + fVar15;
  pfVar5[5] = fVar17 * fVar14 + fVar16;
  pfVar5[6] = fVar10 + fVar12;
  return;
}


/* WARNING: Removing unreachable block (ram,0x8030db68) */
/* WARNING: Removing unreachable block (ram,0x8030db54) */
/* WARNING: Removing unreachable block (ram,0x8030db44) */
/* WARNING: Removing unreachable block (ram,0x8030db34) */
/* WARNING: Removing unreachable block (ram,0x8030db28) */
/* WARNING: Removing unreachable block (ram,0x8030db24) */
/* WARNING: Removing unreachable block (ram,0x8030db2c) */
/* WARNING: Removing unreachable block (ram,0x8030db3c) */
/* WARNING: Removing unreachable block (ram,0x8030db4c) */
/* WARNING: Removing unreachable block (ram,0x8030db60) */
/* WARNING: Removing unreachable block (ram,0x8030db70) */

undefined8 PSMTXMultVecSR(int param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  
  fVar1 = (float)__psq_l0(param_1,0);
  fVar2 = (float)__psq_l1(param_1,0);
  fVar11 = (float)__psq_l0(param_2,0);
  fVar12 = (float)__psq_l1(param_2,0);
  fVar5 = (float)__psq_l0(param_1 + 0x10,0);
  fVar6 = (float)__psq_l1(param_1 + 0x10,0);
  fVar8 = (float)__psq_l0(param_1 + 0x20,0);
  fVar9 = (float)__psq_l1(param_1 + 0x20,0);
  fVar13 = (float)__psq_l0(param_2 + 8,0);
  fVar7 = (float)__psq_l0(param_1 + 0x18,0);
  __psq_l1(param_1 + 0x18,0);
  fVar10 = (float)__psq_l0(param_1 + 0x28,0);
  __psq_l1(param_1 + 0x28,0);
  fVar3 = (float)__psq_l0(param_1 + 8,0);
  uVar4 = __psq_l1(param_1 + 8,0);
  __psq_st0(param_3,fVar3 * fVar13 + fVar1 * fVar11 + fVar2 * fVar12,0);
  __psq_st0(param_3 + 4,fVar7 * fVar13 + fVar5 * fVar11 + fVar6 * fVar12,0);
  __psq_st0(param_3 + 8,fVar10 * fVar13 + fVar8 * fVar11 + fVar9 * fVar12,0);
  return CONCAT44(fVar3,uVar4);
}

