#include <d_jnt_hit.h>
#include <JKernel/JKRHeap.h>
#include <m_Do_ext.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <mtx/mtx.h>
#include <mtx/mtxvec.h>
#include <d_jnt_hit.h>
#include <JntHit_HIO_c.h>
#include <JntHit_c.h>


/* __thiscall JntHit_HIO_c::JntHit_HIO_c(void) */

void __thiscall JntHit_HIO_c::JntHit_HIO_c(JntHit_HIO_c *this)

{
  float fVar1;
  
  this->vtbl = (undefined *)&__vt;
  this->field_0x6 = 0;
  this->field_0x8 = 0;
  this->field_0xc = d_jnt_hit::_4005;
  (this->field_0x10).x = ::cXyz::Zero.x;
  (this->field_0x10).y = ::cXyz::Zero.y;
  (this->field_0x10).z = ::cXyz::Zero.z;
  fVar1 = d_jnt_hit::_4006;
  this->field_0x1c = d_jnt_hit::_4006;
  this->field_0x20 = fVar1;
  this->field_0x24 = d_jnt_hit::_4007;
  this->field_0x4 = 0xff;
  return;
}


/* __thiscall JntHit_c::CreateInit(void) */

undefined4 __thiscall JntHit_c::CreateInit(JntHit_c *this)

{
  bool bVar1;
  short *psVar2;
  int iVar3;
  undefined4 uVar4;
  cXyz *pcVar5;
  short *psVar6;
  cXyz *pcVar7;
  int iVar8;
  int *piVar9;
  __jnt_hit_data_c *pHitData;
  int iVar10;
  int iVar11;
  
  pHitData = this->mpHitData;
  iVar10 = 0;
  iVar8 = (int)this->field_0x18;
  iVar11 = iVar8;
  if (0 < iVar8) {
    do {
      iVar3 = (int)pHitData->field_0x0;
      if ((((iVar3 == 0) || (iVar3 - 2U < 2)) || (iVar3 == 5)) || (iVar3 == 7)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        iVar10 = iVar10 + 2;
      }
      else {
        if (((iVar3 == 1) || (iVar3 == 4)) || ((iVar3 == 6 || (iVar3 == 8)))) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          iVar10 = iVar10 + 1;
        }
      }
      pHitData = pHitData + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  uVar4 = JKernel::operator_new__(iVar8 << 1);
  *(undefined4 *)&this->field_0x10 = uVar4;
  uVar4 = JKernel::operator_new__(iVar10 * 0xc + 0x10);
  pcVar5 = (cXyz *)Runtime.PPCEABI.H::__construct_new_array
                             (uVar4,::cXyz::cXyz,::cXyz::_cXyz,0xc,iVar10);
  this->field_0x8 = pcVar5;
  uVar4 = JKernel::operator_new__((int)this->field_0x18 << 2);
  *(undefined4 *)&this->field_0xc = uVar4;
  uVar4 = JKernel::operator_new__((int)this->field_0x18 << 1);
  *(undefined4 *)&this->field_0x14 = uVar4;
  psVar2 = *(short **)&this->field_0x10;
  if (((psVar2 == (short *)0x0) || (pcVar5 = this->field_0x8, pcVar5 == (cXyz *)0x0)) ||
     ((piVar9 = *(int **)&this->field_0xc, piVar9 == (int *)0x0 ||
      (psVar6 = *(short **)&this->field_0x14, psVar6 == (short *)0x0)))) {
    uVar4 = 0;
  }
  else {
    pHitData = this->mpHitData;
    for (iVar11 = 0; iVar11 < this->field_0x18; iVar11 = iVar11 + 1) {
      *psVar2 = pHitData->field_0x0;
      *psVar6 = pHitData->field_0x2;
      *piVar9 = pHitData->field_0x4;
      iVar8 = (int)*psVar2;
      if ((((iVar8 == 0) || (iVar8 - 2U < 2)) || (iVar8 == 5)) || (iVar8 == 7)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        pcVar7 = pHitData->field_0x8;
        pcVar5->x = pcVar7->x;
        pcVar5->y = pcVar7->y;
        pcVar5->z = pcVar7->z;
        pcVar7 = pHitData->field_0x8;
        pcVar5[1].x = pcVar7[1].x;
        pcVar5[1].y = pcVar7[1].y;
        pcVar5[1].z = pcVar7[1].z;
        pcVar5 = pcVar5 + 1;
      }
      else {
        if (((iVar8 == 1) || (iVar8 == 4)) || ((iVar8 == 6 || (iVar8 == 8)))) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          pcVar7 = pHitData->field_0x8;
          pcVar5->x = pcVar7->x;
          pcVar5->y = pcVar7->y;
          pcVar5->z = pcVar7->z;
        }
      }
      pcVar5 = pcVar5 + 1;
      pHitData = pHitData + 1;
      psVar2 = psVar2 + 1;
      psVar6 = psVar6 + 1;
      piVar9 = piVar9 + 1;
    }
    uVar4 = 1;
  }
  return uVar4;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80061418) */
/* WARNING: Removing unreachable block (ram,0x80061408) */
/* WARNING: Removing unreachable block (ram,0x80061410) */
/* WARNING: Removing unreachable block (ram,0x80061420) */
/* __thiscall JntHit_c::CylHitPosAngleOffset(cXyz *,
                                             csXyz *,
                                             cXyz *,
                                             csXyz *,
                                             cXyz,
                                             cXyz,
                                             float) */

undefined4 __thiscall
JntHit_c::CylHitPosAngleOffset
          (JntHit_c *this,cXyz *param_1,csXyz *param_2,cXyz *param_3,csXyz *param_4,cXyz *param_5,
          cXyz *param_6,float param_7)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  float fVar10;
  cXyz cStack352;
  cXyz cStack340;
  cXyz local_148;
  cXyz cStack316;
  cXyz cStack304;
  cXyz cStack292;
  cXyz local_118;
  cXyz cStack268;
  cXyz cStack256;
  cXyz local_f4;
  cXyz local_e8;
  cXyz local_dc;
  cXyz local_d0;
  cXyz local_c4;
  cXyz local_b8;
  cXyz local_ac;
  cXyz local_a0;
  cXyz local_94;
  cXyz local_88;
  cXyz local_7c;
  cXyz local_70 [2];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar8 = (double)param_7;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  ::cXyz::operator__(&local_dc,param_6,param_5);
  local_70[0].x = local_dc.x;
  local_70[0].y = local_dc.y;
  local_70[0].z = local_dc.z;
  ::cXyz::normZP(&local_e8,local_70);
  local_7c.x = local_e8.x;
  local_7c.y = local_e8.y;
  local_7c.z = local_e8.z;
  fVar10 = mtx::PSVECSquareMag(local_70);
  dVar9 = (double)fVar10;
  if ((double)d_jnt_hit::_4006 < dVar9) {
    dVar5 = 1.0 / SQRT(dVar9);
    dVar5 = d_jnt_hit::_4254 * dVar5 * (d_jnt_hit::_4255 - dVar9 * dVar5 * dVar5);
    dVar5 = d_jnt_hit::_4254 * dVar5 * (d_jnt_hit::_4255 - dVar9 * dVar5 * dVar5);
    dVar9 = (double)(float)(dVar9 * d_jnt_hit::_4254 * dVar5 *
                                    (d_jnt_hit::_4255 - dVar9 * dVar5 * dVar5));
  }
  dVar5 = (double)mtx::PSVECDotProduct(param_1,&local_7c);
  local_94.x = param_1->x;
  local_94.y = param_1->y;
  local_94.z = param_1->z;
  local_a0.x = local_7c.x;
  local_a0.y = local_7c.y;
  local_a0.z = local_7c.z;
  mtx::PSVECScale(&local_a0,&local_a0,(float)dVar5);
  mtx::PSVECSubtract(&local_94,&local_a0,&local_94);
  iVar1 = (int)((int)param_2->x & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  iVar2 = (int)((int)param_2->y & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  local_ac.x = JKernel::JMath::jmaCosTable[iVar1] * JKernel::JMath::jmaSinTable[iVar2];
  local_ac.y = -JKernel::JMath::jmaSinTable[iVar1];
  local_ac.z = JKernel::JMath::jmaCosTable[iVar1] * JKernel::JMath::jmaCosTable[iVar2];
  dVar5 = (double)mtx::PSVECDotProduct(&local_ac,&local_7c);
  local_b8.x = local_ac.x;
  local_b8.y = local_ac.y;
  local_b8.z = local_ac.z;
  local_a0.x = local_7c.x;
  local_a0.y = local_7c.y;
  local_a0.z = local_7c.z;
  mtx::PSVECScale(&local_a0,&local_a0,(float)dVar5);
  mtx::PSVECSubtract(&local_b8,&local_a0,&local_b8);
  cVar3 = ::cXyz::normalizeRS(&local_b8);
  if (cVar3 == '\0') {
    local_d0.x = param_1->x;
    local_d0.y = param_1->y;
    local_d0.z = param_1->z;
    local_88.x = local_d0.x;
    local_88.y = local_d0.y;
    local_88.z = local_d0.z;
    dVar5 = (double)mtx::PSVECDotProduct(&local_88,&local_7c);
    ::cXyz::operator_(&cStack304,&local_7c,(float)dVar5);
    mtx::PSVECSubtract(&local_d0,&cStack304,&local_d0);
    ::cXyz::normalizeZP(&cStack316);
    ::cXyz::operator_(&local_148,&local_d0,(float)dVar8);
    local_d0.x = local_148.x;
    local_d0.y = local_148.y;
    local_d0.z = local_148.z;
    dVar8 = (double)mtx::PSVECDotProduct(&local_88,&local_7c);
    ::cXyz::operator_(&cStack340,&local_7c,(float)dVar8);
    mtx::PSVECAdd(&local_d0,&cStack340,&local_d0);
    local_88.x = local_d0.x;
    local_88.y = local_d0.y;
    local_88.z = local_d0.z;
  }
  else {
    dVar7 = (double)mtx::PSVECDotProduct(&local_94,&local_b8);
    fVar10 = mtx::PSVECSquareMag(&local_94);
    dVar5 = (double)(((float)(dVar7 * dVar7) + (float)(dVar8 * dVar8)) - fVar10);
    if (dVar5 < (double)d_jnt_hit::_4006) {
      dVar5 = (double)d_jnt_hit::_4006;
    }
    dVar6 = dVar5;
    if ((double)d_jnt_hit::_4006 < dVar5) {
      dVar6 = 1.0 / SQRT(dVar5);
      dVar6 = d_jnt_hit::_4254 * dVar6 * (d_jnt_hit::_4255 - dVar5 * dVar6 * dVar6);
      dVar6 = d_jnt_hit::_4254 * dVar6 * (d_jnt_hit::_4255 - dVar5 * dVar6 * dVar6);
      dVar6 = (double)(float)(dVar5 * d_jnt_hit::_4254 * dVar6 *
                                      (d_jnt_hit::_4255 - dVar5 * dVar6 * dVar6));
    }
    ::cXyz::operator_(&local_f4,&local_ac,(float)(-dVar7 - dVar6));
    local_88.x = local_f4.x;
    local_88.y = local_f4.y;
    local_88.z = local_f4.z;
    mtx::PSVECAdd(&local_88,param_1,&local_88);
    if ((double)d_jnt_hit::_4006 == dVar5) {
      local_c4.x = local_88.x;
      local_c4.y = local_88.y;
      local_c4.z = local_88.z;
      dVar5 = (double)mtx::PSVECDotProduct(&local_88,&local_7c);
      ::cXyz::operator_(&cStack256,&local_7c,(float)dVar5);
      mtx::PSVECSubtract(&local_c4,&cStack256,&local_c4);
      ::cXyz::normalizeZP(&cStack268);
      ::cXyz::operator_(&local_118,&local_c4,(float)dVar8);
      local_c4.x = local_118.x;
      local_c4.y = local_118.y;
      local_c4.z = local_118.z;
      dVar8 = (double)mtx::PSVECDotProduct(&local_88,&local_7c);
      ::cXyz::operator_(&cStack292,&local_7c,(float)dVar8);
      mtx::PSVECAdd(&local_c4,&cStack292,&local_c4);
      local_88.x = local_c4.x;
      local_88.y = local_c4.y;
      local_88.z = local_c4.z;
    }
  }
  dVar5 = (double)mtx::PSVECDotProduct(&local_88,&local_7c);
  dVar8 = (double)d_jnt_hit::_4006;
  if (dVar8 <= dVar5) {
    if (dVar9 < dVar5) {
      dVar8 = (double)(float)(dVar9 - dVar5);
    }
  }
  else {
    dVar8 = -dVar5;
  }
  ::cXyz::operator_(&cStack352,&local_7c,(float)dVar8);
  mtx::PSVECAdd(&local_88,&cStack352,&local_88);
  mtx::PSVECAdd(&local_88,param_5,&local_88);
  mtx::PSMTXInverse(&mDoMtx_stack_c::now,&mDoMtx_stack_c::now);
  mDoMtx_stack_c::transM(local_88.x,local_88.y,local_88.z);
  m_Do_mtx::mDoMtx_ZXYrotM(&mDoMtx_stack_c::now,(int)param_2->x,(int)param_2->y,(int)param_2->z);
  param_3->x = mDoMtx_stack_c::now.m[0][3];
  param_3->y = mDoMtx_stack_c::now.m[1][3];
  param_3->z = mDoMtx_stack_c::now.m[2][3];
  m_Do_mtx::mDoMtx_MtxToRot(&mDoMtx_stack_c::now,param_4);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80061808) */
/* WARNING: Removing unreachable block (ram,0x80061800) */
/* WARNING: Removing unreachable block (ram,0x80061810) */
/* __thiscall JntHit_c::Cyl2HitPosAngleOffset(cXyz *,
                                              csXyz *,
                                              cXyz *,
                                              csXyz *,
                                              cXyz,
                                              cXyz,
                                              float) */

undefined4 __thiscall
JntHit_c::Cyl2HitPosAngleOffset
          (JntHit_c *this,cXyz *param_1,csXyz *param_2,cXyz *param_3,csXyz *param_4,cXyz *param_5,
          cXyz *param_6,float param_7)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f29;
  double dVar8;
  undefined8 in_f30;
  undefined8 in_f31;
  float fVar9;
  cXyz local_e0;
  cXyz local_d4;
  cXyz local_c8;
  cXyz local_bc;
  cXyz local_b0;
  cXyz local_a4;
  cXyz local_98;
  cXyz local_8c;
  float local_80;
  float local_7c;
  float local_78;
  cXyz local_74;
  float local_68;
  float local_64;
  float local_60;
  cXyz local_5c [2];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar6 = (double)param_7;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  ::cXyz::operator__(&local_bc,param_6,param_5);
  local_5c[0].x = local_bc.x;
  local_5c[0].y = local_bc.y;
  local_5c[0].z = local_bc.z;
  ::cXyz::normZP(&local_c8,local_5c);
  local_68 = local_c8.x;
  local_64 = local_c8.y;
  local_60 = local_c8.z;
  fVar9 = mtx::PSVECSquareMag(local_5c);
  dVar8 = (double)fVar9;
  if ((double)d_jnt_hit::_4006 < dVar8) {
    dVar5 = 1.0 / SQRT(dVar8);
    dVar5 = d_jnt_hit::_4254 * dVar5 * (d_jnt_hit::_4255 - dVar8 * dVar5 * dVar5);
    dVar5 = d_jnt_hit::_4254 * dVar5 * (d_jnt_hit::_4255 - dVar8 * dVar5 * dVar5);
    dVar8 = (double)(float)(dVar8 * d_jnt_hit::_4254 * dVar5 *
                                    (d_jnt_hit::_4255 - dVar8 * dVar5 * dVar5));
  }
  dVar5 = (double)mtx::PSVECDotProduct(param_1,&local_68);
  iVar1 = (int)((int)param_2->x & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  iVar2 = (int)((int)param_2->y & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  local_80 = JKernel::JMath::jmaCosTable[iVar1] * JKernel::JMath::jmaSinTable[iVar2];
  local_7c = -JKernel::JMath::jmaSinTable[iVar1];
  local_78 = JKernel::JMath::jmaCosTable[iVar1] * JKernel::JMath::jmaCosTable[iVar2];
  dVar7 = (double)mtx::PSVECDotProduct(&local_80,&local_68);
  if ((float)ABS(dVar7) < d_jnt_hit::_4390) {
    local_74.x = param_1->x;
    local_74.y = param_1->y;
    local_74.z = param_1->z;
  }
  else {
    if (dVar7 <= (double)d_jnt_hit::_4006) {
      dVar5 = (double)(float)(dVar8 - dVar5);
    }
    else {
      dVar5 = -dVar5;
    }
    local_8c.x = local_80;
    local_8c.y = local_7c;
    local_8c.z = local_78;
    mtx::PSVECScale(&local_8c,&local_8c,(float)(dVar5 / dVar7));
    ::cXyz::operator__(&local_d4,param_1,&local_8c);
    local_74.x = local_d4.x;
    local_74.y = local_d4.y;
    local_74.z = local_d4.z;
  }
  local_98.x = local_74.x;
  local_98.y = local_74.y;
  local_98.z = local_74.z;
  dVar8 = (double)mtx::PSVECDotProduct(&local_98,&local_68);
  local_a4.x = local_68;
  local_a4.y = local_64;
  local_a4.z = local_60;
  mtx::PSVECScale(&local_a4,&local_a4,(float)dVar8);
  mtx::PSVECSubtract(&local_98,&local_a4,&local_98);
  local_b0.x = local_98.x;
  local_b0.y = local_98.y;
  local_b0.z = local_98.z;
  fVar9 = mtx::PSVECSquareMag(&local_98);
  dVar8 = (double)fVar9;
  if ((double)d_jnt_hit::_4006 < dVar8) {
    dVar5 = 1.0 / SQRT(dVar8);
    dVar5 = d_jnt_hit::_4254 * dVar5 * (d_jnt_hit::_4255 - dVar8 * dVar5 * dVar5);
    dVar5 = d_jnt_hit::_4254 * dVar5 * (d_jnt_hit::_4255 - dVar8 * dVar5 * dVar5);
    dVar8 = (double)(float)(dVar8 * d_jnt_hit::_4254 * dVar5 *
                                    (d_jnt_hit::_4255 - dVar8 * dVar5 * dVar5));
  }
  if ((dVar6 < dVar8) && (cVar3 = ::cXyz::normalizeRS(&local_98), cVar3 != '\0')) {
    mtx::PSVECScale(&local_98,&local_98,(float)dVar6);
    ::cXyz::operator__(&local_e0,&local_b0,&local_98);
    local_98.x = local_e0.x;
    local_98.y = local_e0.y;
    local_98.z = local_e0.z;
    mtx::PSVECSubtract(&local_74,&local_98,&local_74);
  }
  mtx::PSVECAdd(&local_74,param_5,&local_74);
  mtx::PSMTXInverse(&mDoMtx_stack_c::now,&mDoMtx_stack_c::now);
  mDoMtx_stack_c::transM(local_74.x,local_74.y,local_74.z);
  m_Do_mtx::mDoMtx_ZXYrotM(&mDoMtx_stack_c::now,(int)param_2->x,(int)param_2->y,(int)param_2->z);
  param_3->x = mDoMtx_stack_c::now.m[0][3];
  param_3->y = mDoMtx_stack_c::now.m[1][3];
  param_3->z = mDoMtx_stack_c::now.m[2][3];
  m_Do_mtx::mDoMtx_MtxToRot(&mDoMtx_stack_c::now,param_4);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80061aa4) */
/* WARNING: Removing unreachable block (ram,0x80061aac) */
/* __thiscall JntHit_c::SphHitPosAngleOffset(cXyz *,
                                             csXyz *,
                                             cXyz *,
                                             csXyz *,
                                             cXyz,
                                             float) */

undefined4 __thiscall
JntHit_c::SphHitPosAngleOffset
          (JntHit_c *this,cXyz *param_1,csXyz *param_2,cXyz *param_3,csXyz *param_4,cXyz *param_5,
          float param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f30;
  undefined8 in_f31;
  float fVar8;
  cXyz cStack112;
  cXyz local_64;
  cXyz local_58;
  cXyz local_4c [2];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar5 = (double)param_6;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  iVar1 = (int)((int)param_2->x & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  iVar2 = (int)((int)param_2->y & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  local_4c[0].x = JKernel::JMath::jmaCosTable[iVar1] * JKernel::JMath::jmaSinTable[iVar2];
  local_4c[0].y = -JKernel::JMath::jmaSinTable[iVar1];
  local_4c[0].z = JKernel::JMath::jmaCosTable[iVar1] * JKernel::JMath::jmaCosTable[iVar2];
  dVar6 = (double)mtx::PSVECDotProduct(param_1,local_4c);
  fVar8 = mtx::PSVECSquareMag(param_1);
  dVar7 = (double)(((float)(dVar6 * dVar6) + (float)(dVar5 * dVar5)) - fVar8);
  if (dVar7 < (double)d_jnt_hit::_4006) {
    dVar7 = (double)d_jnt_hit::_4006;
  }
  if ((double)d_jnt_hit::_4006 < dVar7) {
    dVar4 = 1.0 / SQRT(dVar7);
    dVar4 = d_jnt_hit::_4254 * dVar4 * (d_jnt_hit::_4255 - dVar7 * dVar4 * dVar4);
    dVar4 = d_jnt_hit::_4254 * dVar4 * (d_jnt_hit::_4255 - dVar7 * dVar4 * dVar4);
    dVar7 = (double)(float)(dVar7 * d_jnt_hit::_4254 * dVar4 *
                                    (d_jnt_hit::_4255 - dVar7 * dVar4 * dVar4));
  }
  ::cXyz::operator_(&local_64,local_4c,(float)(-dVar6 - dVar7));
  local_58.x = local_64.x;
  local_58.y = local_64.y;
  local_58.z = local_64.z;
  mtx::PSVECAdd(&local_58,param_1,&local_58);
  fVar8 = mtx::PSVECSquareMag(&local_58);
  dVar7 = (double)fVar8;
  if ((double)d_jnt_hit::_4006 < dVar7) {
    dVar6 = 1.0 / SQRT(dVar7);
    dVar6 = d_jnt_hit::_4254 * dVar6 * (d_jnt_hit::_4255 - dVar7 * dVar6 * dVar6);
    dVar6 = d_jnt_hit::_4254 * dVar6 * (d_jnt_hit::_4255 - dVar7 * dVar6 * dVar6);
    dVar7 = (double)(float)(dVar7 * d_jnt_hit::_4254 * dVar6 *
                                    (d_jnt_hit::_4255 - dVar7 * dVar6 * dVar6));
  }
  if (dVar5 < dVar7) {
    ::cXyz::normalizeZP(&cStack112);
    mtx::PSVECScale(&local_58,&local_58,(float)dVar5);
  }
  mtx::PSVECAdd(&local_58,param_5,&local_58);
  mtx::PSMTXInverse(&mDoMtx_stack_c::now,&mDoMtx_stack_c::now);
  mDoMtx_stack_c::transM(local_58.x,local_58.y,local_58.z);
  m_Do_mtx::mDoMtx_ZXYrotM(&mDoMtx_stack_c::now,(int)param_2->x,(int)param_2->y,(int)param_2->z);
  param_3->x = mDoMtx_stack_c::now.m[0][3];
  param_3->y = mDoMtx_stack_c::now.m[1][3];
  param_3->z = mDoMtx_stack_c::now.m[2][3];
  m_Do_mtx::mDoMtx_MtxToRot(&mDoMtx_stack_c::now,param_4);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JntHit_c::HitBufferUpdate(int *,
                                        cXyz *,
                                        int,
                                        csXyz *,
                                        cXyz *) */

undefined4 __thiscall
JntHit_c::HitBufferUpdate
          (JntHit_c *this,int *pDstJointIndex,cXyz *pDstHitPos,int jointIndex,csXyz *pRot,
          cXyz *lpPos)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  cXyz local_48;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  cXyz local_24;
  
  mtx::PSMTXCopy(this->mpModel->mpNodeMtx + jointIndex,&mDoMtx_stack_c::now);
  mtx::PSMTXMultVec(&mDoMtx_stack_c::now,lpPos,&local_24);
  if (*pDstJointIndex < 0) {
    *pDstJointIndex = jointIndex;
    pDstHitPos->x = local_24.x;
    pDstHitPos->y = local_24.y;
    pDstHitPos->z = local_24.z;
    uVar3 = 1;
  }
  else {
    iVar1 = (int)((int)pRot->y & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
    iVar2 = (int)((int)pRot->x & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
    local_30 = JKernel::JMath::jmaCosTable[iVar2] * JKernel::JMath::jmaSinTable[iVar1];
    local_2c = -JKernel::JMath::jmaSinTable[iVar2];
    local_28 = JKernel::JMath::jmaCosTable[iVar2] * JKernel::JMath::jmaCosTable[iVar1];
    ::cXyz::operator__(&local_48,&local_24,pDstHitPos);
    local_3c = local_48.x;
    local_38 = local_48.y;
    local_34 = local_48.z;
    dVar4 = (double)mtx::PSVECDotProduct(&local_3c,&local_30);
    if ((double)d_jnt_hit::_4006 <= dVar4) {
      uVar3 = 0;
    }
    else {
      *pDstJointIndex = jointIndex;
      pDstHitPos->x = local_24.x;
      pDstHitPos->y = local_24.y;
      pDstHitPos->z = local_24.z;
      uVar3 = 1;
    }
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f08 */
/* WARNING: Inlined function: FUN_80328f54 */
/* WARNING: Removing unreachable block (ram,0x800627b4) */
/* WARNING: Removing unreachable block (ram,0x800627ac) */
/* WARNING: Removing unreachable block (ram,0x800627bc) */
/* __thiscall JntHit_c::searchJntHitPosAngleOffset(cXyz *,
                                                   csXyz *,
                                                   cXyz *,
                                                   csXyz *) */

int __thiscall
JntHit_c::searchJntHitPosAngleOffset
          (JntHit_c *this,cXyz *param_1,csXyz *param_2,cXyz *param_3,csXyz *param_4)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  char cVar4;
  J3DModel *pJVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  cXyz *pcVar9;
  float *pfVar10;
  short *psVar11;
  short *psVar12;
  int iVar13;
  int iVar14;
  int jointIndex;
  undefined4 uVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar20;
  float fVar21;
  int local_210;
  short local_20c;
  short local_20a;
  short local_208;
  cXyz local_204;
  cXyz local_1f8;
  cXyz local_1ec;
  cXyz local_1e0;
  cXyz local_1d4;
  cXyz local_1c8;
  cXyz local_1bc;
  cXyz local_1b0;
  cXyz local_1a4;
  cXyz local_198;
  cXyz local_18c;
  cXyz local_180;
  cXyz local_174;
  cXyz local_168;
  cXyz local_15c;
  cXyz local_150;
  cXyz local_144;
  cXyz local_138;
  cXyz local_12c;
  cXyz local_120;
  cXyz local_114;
  cXyz local_108;
  cXyz local_fc;
  cXyz local_f0;
  cXyz local_e4;
  cXyz local_d8;
  cXyz local_cc;
  cXyz local_c0;
  cXyz local_b4;
  float local_a8;
  float local_a4;
  float local_a0;
  cXyz cStack156;
  cXyz local_90 [2];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar15 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  pJVar5 = this->mpModel;
  dVar20 = (double)d_jnt_hit::_5053;
  iVar6 = 0;
  jointIndex = -1;
  psVar12 = *(short **)&this->field_0x10;
  psVar11 = *(short **)&this->field_0x14;
  pfVar10 = *(float **)&this->field_0xc;
  pcVar9 = this->field_0x8;
  iVar8 = 0;
  iVar7 = 0;
  iVar13 = 0;
  iVar14 = 0;
  local_210 = -1;
  do {
    bVar1 = this->field_0x18 <= iVar6;
    iVar6 = iVar6 + 1;
    if (bVar1) {
      if (local_210 < 0) {
        iVar6 = *(int *)&this->field_0x10;
        iVar7 = *(int *)&this->field_0xc;
        pcVar9 = this->field_0x8;
        mtx::PSMTXCopy(pJVar5->mpNodeMtx + jointIndex,&mDoMtx_stack_c::now);
        sVar2 = *(short *)(iVar6 + iVar13 * 2);
        if ((sVar2 == 4) || (sVar2 == 3)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          jointIndex = -1;
        }
        else {
          if ((sVar2 == 8) || (sVar2 == 7)) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            jointIndex = -3;
          }
          else {
            if (sVar2 == 0) {
              mtx::PSMTXMultVec(&mDoMtx_stack_c::now,pcVar9 + iVar14,&local_fc);
              mtx::PSMTXMultVec(&mDoMtx_stack_c::now,pcVar9 + iVar14 + 1,&local_108);
              ::cXyz::operator__(&local_1b0,param_1,&local_fc);
              local_90[0].x = local_1b0.x;
              local_90[0].y = local_1b0.y;
              local_90[0].z = local_1b0.z;
              local_1bc.x = local_fc.x;
              local_1bc.y = local_fc.y;
              local_1bc.z = local_fc.z;
              local_1c8.x = local_108.x;
              local_1c8.y = local_108.y;
              local_1c8.z = local_108.z;
              CylHitPosAngleOffset
                        (this,local_90,param_2,param_3,param_4,&local_1bc,&local_1c8,
                         *(float *)(iVar7 + iVar13 * 4));
            }
            else {
              if (sVar2 == 1) {
                mtx::PSMTXMultVec(&mDoMtx_stack_c::now,pcVar9 + iVar14,&local_114);
                ::cXyz::operator__(&local_1d4,param_1,&local_114);
                local_90[0].x = local_1d4.x;
                local_90[0].y = local_1d4.y;
                local_90[0].z = local_1d4.z;
                local_1e0.x = local_114.x;
                local_1e0.y = local_114.y;
                local_1e0.z = local_114.z;
                SphHitPosAngleOffset
                          (this,local_90,param_2,param_3,param_4,&local_1e0,
                           *(float *)(iVar7 + iVar13 * 4));
              }
              else {
                mtx::PSMTXMultVec(&mDoMtx_stack_c::now,pcVar9 + iVar14,&local_120);
                mtx::PSMTXMultVec(&mDoMtx_stack_c::now,pcVar9 + iVar14 + 1,&local_12c);
                ::cXyz::operator__(&local_1ec,param_1,&local_120);
                local_90[0].x = local_1ec.x;
                local_90[0].y = local_1ec.y;
                local_90[0].z = local_1ec.z;
                local_1f8.x = local_120.x;
                local_1f8.y = local_120.y;
                local_1f8.z = local_120.z;
                local_204.x = local_12c.x;
                local_204.y = local_12c.y;
                local_204.z = local_12c.z;
                Cyl2HitPosAngleOffset
                          (this,local_90,param_2,param_3,param_4,&local_1f8,&local_204,
                           *(float *)(iVar7 + iVar13 * 4));
              }
            }
          }
        }
      }
      else {
        param_3->x = local_a8;
        param_3->y = local_a4;
        param_3->z = local_a0;
        param_4->x = local_20c;
        param_4->y = local_20a;
        param_4->z = local_208;
        jointIndex = local_210;
      }
LAB_800627ac:
      __psq_l0(auStack8,uVar15);
      __psq_l1(auStack8,uVar15);
      __psq_l0(auStack24,uVar15);
      __psq_l1(auStack24,uVar15);
      __psq_l0(auStack40,uVar15);
      __psq_l1(auStack40,uVar15);
      return jointIndex;
    }
    mtx::PSMTXCopy(pJVar5->mpNodeMtx + *psVar11,&mDoMtx_stack_c::now);
    iVar3 = (int)*psVar12;
    if ((((iVar3 == 0) || (iVar3 - 2U < 2)) || (iVar3 == 5)) || (iVar3 == 7)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      mtx::PSMTXMultVec(&mDoMtx_stack_c::now,pcVar9,&local_b4);
      mtx::PSMTXMultVec(&mDoMtx_stack_c::now,pcVar9 + 1,&local_c0);
      ::cXyz::operator__(&local_138,&local_c0,&local_b4);
      local_cc.x = local_138.x;
      local_cc.y = local_138.y;
      local_cc.z = local_138.z;
      local_d8.x = local_138.x;
      local_d8.y = local_138.y;
      local_d8.z = local_138.z;
      ::cXyz::operator__(&local_144,param_1,&local_b4);
      local_90[0].x = local_144.x;
      local_90[0].y = local_144.y;
      local_90[0].z = local_144.z;
      cVar4 = ::cXyz::normalizeRS(&local_d8);
      if (cVar4 == '\0') {
        fVar21 = mtx::PSVECSquareMag(local_90);
        dVar18 = (double)fVar21;
        if ((double)d_jnt_hit::_4006 < dVar18) {
          dVar16 = 1.0 / SQRT(dVar18);
          dVar16 = d_jnt_hit::_4254 * dVar16 * (d_jnt_hit::_4255 - dVar18 * dVar16 * dVar16);
          dVar16 = d_jnt_hit::_4254 * dVar16 * (d_jnt_hit::_4255 - dVar18 * dVar16 * dVar16);
          dVar18 = (double)(float)(dVar18 * d_jnt_hit::_4254 * dVar16 *
                                            (d_jnt_hit::_4255 - dVar18 * dVar16 * dVar16));
        }
        dVar18 = (double)(float)(dVar18 - (double)*pfVar10);
        if (dVar18 < (double)d_jnt_hit::_4006) {
          dVar18 = (double)d_jnt_hit::_4006;
        }
        if ((dVar18 <= dVar20) &&
           (jointIndex = (int)*psVar11, iVar13 = iVar8, iVar14 = iVar7, dVar20 = dVar18,
           dVar18 < (double)*pfVar10)) {
          local_150.x = local_b4.x;
          local_150.y = local_b4.y;
          local_150.z = local_b4.z;
          SphHitPosAngleOffset(this,local_90,param_2,param_3,param_4,&local_150,*pfVar10);
          iVar3 = HitBufferUpdate(this,&local_210,&cStack156,jointIndex,param_2,param_3);
          dVar20 = dVar18;
          if (iVar3 != 0) {
            local_a8 = param_3->x;
            local_a4 = param_3->y;
            local_a0 = param_3->z;
            local_20c = param_4->x;
            local_20a = param_4->y;
            local_208 = param_4->z;
          }
        }
      }
      else {
        ::cXyz::outprod(&local_15c,&local_d8,local_90);
        local_e4.x = local_15c.x;
        local_e4.y = local_15c.y;
        local_e4.z = local_15c.z;
        fVar21 = mtx::PSVECSquareMag(&local_e4);
        dVar18 = (double)fVar21;
        if ((double)d_jnt_hit::_4006 < dVar18) {
          dVar16 = 1.0 / SQRT(dVar18);
          dVar16 = d_jnt_hit::_4254 * dVar16 * (d_jnt_hit::_4255 - dVar18 * dVar16 * dVar16);
          dVar16 = d_jnt_hit::_4254 * dVar16 * (d_jnt_hit::_4255 - dVar18 * dVar16 * dVar16);
          dVar18 = (double)(float)(dVar18 * d_jnt_hit::_4254 * dVar16 *
                                            (d_jnt_hit::_4255 - dVar18 * dVar16 * dVar16));
        }
        dVar18 = (double)(float)(dVar18 - (double)*pfVar10);
        if (dVar18 < (double)d_jnt_hit::_4006) {
          dVar18 = (double)d_jnt_hit::_4006;
        }
        dVar16 = (double)mtx::PSVECDotProduct(&local_d8,local_90);
        if ((double)d_jnt_hit::_4006 <= dVar16) {
          fVar21 = mtx::PSVECSquareMag(&local_cc);
          dVar19 = (double)fVar21;
          if ((double)d_jnt_hit::_4006 < dVar19) {
            dVar17 = 1.0 / SQRT(dVar19);
            dVar17 = d_jnt_hit::_4254 * dVar17 * (d_jnt_hit::_4255 - dVar19 * dVar17 * dVar17);
            dVar17 = d_jnt_hit::_4254 * dVar17 * (d_jnt_hit::_4255 - dVar19 * dVar17 * dVar17);
            dVar19 = (double)(float)(dVar19 * d_jnt_hit::_4254 * dVar17 *
                                              (d_jnt_hit::_4255 - dVar19 * dVar17 * dVar17));
          }
          if (dVar16 <= dVar19) {
            dVar16 = (double)d_jnt_hit::_4006;
          }
          else {
            fVar21 = mtx::PSVECSquareMag(&local_cc);
            dVar19 = (double)fVar21;
            if ((double)d_jnt_hit::_4006 < dVar19) {
              dVar17 = 1.0 / SQRT(dVar19);
              dVar17 = d_jnt_hit::_4254 * dVar17 * (d_jnt_hit::_4255 - dVar19 * dVar17 * dVar17);
              dVar17 = d_jnt_hit::_4254 * dVar17 * (d_jnt_hit::_4255 - dVar19 * dVar17 * dVar17);
              dVar19 = (double)(float)(dVar19 * d_jnt_hit::_4254 * dVar17 *
                                                (d_jnt_hit::_4255 - dVar19 * dVar17 * dVar17));
            }
            dVar16 = (double)(float)(dVar16 - dVar19);
          }
        }
        else {
          dVar16 = -dVar16;
        }
        dVar19 = (double)((float)(dVar16 * dVar16) + (float)(dVar18 * dVar18));
        if ((double)d_jnt_hit::_4006 < dVar19) {
          dVar17 = 1.0 / SQRT(dVar19);
          dVar17 = d_jnt_hit::_4254 * dVar17 * (d_jnt_hit::_4255 - dVar19 * dVar17 * dVar17);
          dVar17 = d_jnt_hit::_4254 * dVar17 * (d_jnt_hit::_4255 - dVar19 * dVar17 * dVar17);
          dVar19 = (double)(float)(dVar19 * d_jnt_hit::_4254 * dVar17 *
                                            (d_jnt_hit::_4255 - dVar19 * dVar17 * dVar17));
        }
        if (((dVar19 <= dVar20) &&
            (jointIndex = (int)*psVar11, iVar13 = iVar8, iVar14 = iVar7, dVar20 = dVar19,
            (float)ABS(dVar16) < d_jnt_hit::_4390)) && ((float)ABS(dVar18) < d_jnt_hit::_4390)) {
          sVar2 = *psVar12;
          if ((sVar2 == 4) || (sVar2 == 3)) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (!bVar1) {
            if (sVar2 == 0) {
              local_168.x = local_b4.x;
              local_168.y = local_b4.y;
              local_168.z = local_b4.z;
              local_174.x = local_c0.x;
              local_174.y = local_c0.y;
              local_174.z = local_c0.z;
              CylHitPosAngleOffset
                        (this,local_90,param_2,param_3,param_4,&local_168,&local_174,*pfVar10);
              dVar20 = dVar19;
            }
            else {
              if (sVar2 == 2) {
                local_180.x = local_b4.x;
                local_180.y = local_b4.y;
                local_180.z = local_b4.z;
                local_18c.x = local_c0.x;
                local_18c.y = local_c0.y;
                local_18c.z = local_c0.z;
                Cyl2HitPosAngleOffset
                          (this,local_90,param_2,param_3,param_4,&local_180,&local_18c,*pfVar10);
                dVar20 = dVar19;
              }
            }
            if ((*psVar12 == 8) || (*psVar12 == 7)) {
              bVar1 = true;
            }
            else {
              bVar1 = false;
            }
            if (bVar1) {
              jointIndex = -3;
              goto LAB_800627ac;
            }
            iVar3 = HitBufferUpdate(this,&local_210,&cStack156,jointIndex,param_2,param_3);
            if (iVar3 != 0) {
              local_a8 = param_3->x;
              local_a4 = param_3->y;
              local_a0 = param_3->z;
              local_20c = param_4->x;
              local_20a = param_4->y;
              local_208 = param_4->z;
            }
          }
        }
      }
      pcVar9 = pcVar9 + 2;
      iVar7 = iVar7 + 2;
    }
    else {
      if (((iVar3 == 1) || (iVar3 == 4)) || ((iVar3 == 6 || (iVar3 == 8)))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        mtx::PSMTXMultVec(&mDoMtx_stack_c::now,pcVar9,&local_f0);
        ::cXyz::operator__(&local_198,param_1,&local_f0);
        local_90[0].x = local_198.x;
        local_90[0].y = local_198.y;
        local_90[0].z = local_198.z;
        fVar21 = mtx::PSVECSquareMag(local_90);
        dVar18 = (double)fVar21;
        if ((double)d_jnt_hit::_4006 < dVar18) {
          dVar16 = 1.0 / SQRT(dVar18);
          dVar16 = d_jnt_hit::_4254 * dVar16 * (d_jnt_hit::_4255 - dVar18 * dVar16 * dVar16);
          dVar16 = d_jnt_hit::_4254 * dVar16 * (d_jnt_hit::_4255 - dVar18 * dVar16 * dVar16);
          dVar18 = (double)(float)(dVar18 * d_jnt_hit::_4254 * dVar16 *
                                            (d_jnt_hit::_4255 - dVar18 * dVar16 * dVar16));
        }
        dVar18 = (double)(float)(dVar18 - (double)*pfVar10);
        if (dVar18 < (double)d_jnt_hit::_4006) {
          dVar18 = (double)d_jnt_hit::_4006;
        }
        if ((dVar18 <= dVar20) &&
           (jointIndex = (int)*psVar11, iVar13 = iVar8, iVar14 = iVar7, dVar20 = dVar18,
           (float)ABS(dVar18) < d_jnt_hit::_4390)) {
          local_1a4.x = local_f0.x;
          local_1a4.y = local_f0.y;
          local_1a4.z = local_f0.z;
          SphHitPosAngleOffset(this,local_90,param_2,param_3,param_4,&local_1a4,*pfVar10);
          sVar2 = *psVar12;
          if ((sVar2 == 8) || (sVar2 == 7)) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            jointIndex = -3;
            goto LAB_800627ac;
          }
          if ((sVar2 == 4) || (sVar2 == 3)) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          dVar20 = dVar18;
          if ((!bVar1) &&
             (iVar3 = HitBufferUpdate(this,&local_210,&cStack156,jointIndex,param_2,param_3),
             dVar20 = dVar18, iVar3 != 0)) {
            local_a8 = param_3->x;
            local_a4 = param_3->y;
            local_a0 = param_3->z;
            local_20c = param_4->x;
            local_20a = param_4->y;
            local_208 = param_4->z;
          }
        }
        pcVar9 = pcVar9 + 1;
        iVar7 = iVar7 + 1;
      }
    }
    psVar12 = psVar12 + 1;
    psVar11 = psVar11 + 1;
    pfVar10 = pfVar10 + 1;
    iVar8 = iVar8 + 1;
  } while( true );
}


namespace d_jnt_hit {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall JntHit_create(J3DModel *,
                           __jnt_hit_data_c *,
                           short) */

JntHit_c * JntHit_create(J3DModel *param_1,__jnt_hit_data_c *param_2,short param_3)

{
  JntHit_c *local_r3_36;
  int iVar1;
  
  local_r3_36 = (JntHit_c *)JKernel::operator_new(0x20);
  if (local_r3_36 != (JntHit_c *)0x0) {
    local_r3_36->mpModel = (J3DModel *)0x0;
    local_r3_36->field_0x8 = (cXyz *)0x0;
    *(undefined4 *)&local_r3_36->field_0xc = 0;
    *(undefined4 *)&local_r3_36->field_0x10 = 0;
    *(undefined4 *)&local_r3_36->field_0x1c = 0;
    local_r3_36->mpHitData = param_2;
    local_r3_36->mpModel = param_1;
    local_r3_36->field_0x18 = param_3;
    iVar1 = ::JntHit_c::CreateInit(local_r3_36);
    if (iVar1 != 0) {
      return local_r3_36;
    }
  }
  return (JntHit_c *)0x0;
}

}

/* __thiscall JntHit_HIO_c::~JntHit_HIO_c(void) */

void __thiscall JntHit_HIO_c::_JntHit_HIO_c(JntHit_HIO_c *this)

{
  short in_r4;
  
  if ((this != (JntHit_HIO_c *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

