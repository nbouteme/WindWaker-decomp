#include <d_boss_magma.h>
#include <SComponent/c_lib.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <f_op_actor.h>
#include <SComponent/c_math.h>
#include <d_boss_magma.h>
#include <f_pc_executor.h>
#include <JKernel/JKRHeap.h>
#include <dMagma_ballBoss_c.h>


namespace d_boss_magma {
undefined4 btd;
}

/* __thiscall dMagma_ballBoss_c::calc(float,
                                      unsigned char,
                                      int) */

void __thiscall
dMagma_ballBoss_c::calc(dMagma_ballBoss_c *this,float param_1,uchar param_2,int param_3)

{
  float fVar1;
  double dVar2;
  double dVar3;
  
  if ((d_boss_magma::btd == 0) || (d_boss_magma::_4020 < *(float *)(d_boss_magma::btd + 0x6e84))) {
    if (d_boss_magma::btd != 0) {
      dVar3 = (double)(*(float *)(this + 4) * *(float *)(this + 4) +
                      *(float *)(this + 0xc) * *(float *)(this + 0xc));
      if ((double)d_boss_magma::_4022 < dVar3) {
        dVar2 = 1.0 / SQRT(dVar3);
        dVar2 = d_boss_magma::_4023 * dVar2 * (d_boss_magma::_4024 - dVar3 * dVar2 * dVar2);
        dVar2 = d_boss_magma::_4023 * dVar2 * (d_boss_magma::_4024 - dVar3 * dVar2 * dVar2);
        dVar3 = (double)(float)(dVar3 * d_boss_magma::_4023 * dVar2 *
                                        (d_boss_magma::_4024 - dVar3 * dVar2 * dVar2));
      }
      fVar1 = ABS((float)((double)*(float *)(d_boss_magma::btd + 0x6e7c) - dVar3));
      if (fVar1 < d_boss_magma::_4025) {
        SComponent::cLib_addCalc2
                  ((float *)(this + 8),
                   (d_boss_magma::_4026 +
                   *(float *)(this + 0x14) +
                   d_boss_magma::_4027 + d_s_play::g_regHIO.mChild[0].mFloats[5]) -
                   d_boss_magma::_4028 * fVar1,d_boss_magma::_4029,d_boss_magma::_4030);
        SComponent::cLib_addCalc2
                  ((float *)(this + 0x10),d_boss_magma::_4031,d_boss_magma::_4032,
                   d_boss_magma::_4032);
        *(undefined2 *)(this + 0x18) = 0x4000;
        *(undefined2 *)(this + 0x7c) = 1000;
        return;
      }
    }
    if (*(short *)(this + 0x18) < 0) {
      (**(code **)(*(int *)this + 0x14))((double)param_1,this,0,0xffffffff);
      *(undefined2 *)(this + 0x18) = 0;
    }
    *(float *)(this + 8) =
         *(float *)(this + 0x14) +
         (d_boss_magma::_4027 + d_s_play::g_regHIO.mChild[0].mFloats[5]) *
         JKernel::JMath::jmaSinTable
         [(int)((int)*(short *)(this + 0x18) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f)];
    *(short *)(this + 0x18) = *(short *)(this + 0x18) + *(short *)(this + 0x7c);
  }
  else {
    *(float *)(this + 8) = d_boss_magma::_4021;
  }
  return;
}


/* __thiscall dMagma_ballBoss_c::update(void) */

void __thiscall dMagma_ballBoss_c::update(dMagma_ballBoss_c *this)

{
  mtx::PSMTXTrans((double)*(float *)(this + 4),(double)*(float *)(this + 8),
                  (double)*(float *)(this + 0xc),&mDoMtx_stack_c::now);
  mDoMtx_stack_c::scaleM(*(float *)(this + 0x10),d_boss_magma::_4048,*(float *)(this + 0x10));
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(this + 0x4c));
  mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,(MTX34 *)(this + 0x4c),(MTX34 *)(this + 0x1c));
  return;
}


namespace d_boss_magma {

/* __stdcall b_a_sub(void *,
                     void *) */

fopAc_ac_c * b_a_sub(fopAc_ac_c *param_1)

{
  bool bVar1;
  
  bVar1 = f_op_actor::fopAc_IsActor(param_1);
  if ((bVar1 == false) || ((param_1->parent).parent.mProcName != 0xeb)) {
    param_1 = (fopAc_ac_c *)0x0;
  }
  return param_1;
}

}

/* WARNING: Removing unreachable block (ram,0x80076fd0) */
/* __thiscall dMagma_ballBoss_c::setup(float,
                                       unsigned char,
                                       int) */

void __thiscall
dMagma_ballBoss_c::setup(dMagma_ballBoss_c *this,float param_1,uchar param_2,int param_3)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f31;
  float fVar5;
  undefined auStack8 [8];
  
  dVar4 = (double)param_1;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar5 = SComponent::cM_rndFX(d_boss_magma::_4091);
  *(float *)(this + 4) = fVar5;
  dVar3 = (double)d_boss_magma::_4022;
  *(float *)(this + 8) = d_boss_magma::_4022;
  dVar2 = (double)(d_boss_magma::_4092 - *(float *)(this + 4) * *(float *)(this + 4));
  if (dVar3 < dVar2) {
    dVar3 = 1.0 / SQRT(dVar2);
    dVar3 = d_boss_magma::_4023 * dVar3 * (d_boss_magma::_4024 - dVar2 * dVar3 * dVar3);
    dVar3 = d_boss_magma::_4023 * dVar3 * (d_boss_magma::_4024 - dVar2 * dVar3 * dVar3);
    dVar2 = (double)(float)(dVar2 * d_boss_magma::_4023 * dVar3 *
                                    (d_boss_magma::_4024 - dVar2 * dVar3 * dVar3));
  }
  fVar5 = SComponent::cM_rndFX((float)dVar2);
  *(float *)(this + 0xc) = fVar5;
  fVar5 = SComponent::cM_rndF(d_boss_magma::_4029 + d_s_play::g_regHIO.mChild[0].mFloats[12]);
  *(float *)(this + 0x10) = d_boss_magma::_4029 + d_s_play::g_regHIO.mChild[0].mFloats[11] + fVar5;
  *(float *)(this + 0x14) =
       d_boss_magma::_4093 +
       (float)((double)((d_boss_magma::_4020 + d_s_play::g_regHIO.mChild[0].mFloats[6]) -
                       d_boss_magma::_4030) + dVar4);
  d_boss_magma::btd = f_pc_executor::fpcEx_Search(d_boss_magma::b_a_sub,(void *)0x0);
  if (d_boss_magma::btd != (void *)0x0) {
    if (*(char *)((int)d_boss_magma::btd + 0x6e88) == '\x01') {
      dVar4 = (double)(*(float *)(this + 4) * *(float *)(this + 4) +
                      *(float *)(this + 0xc) * *(float *)(this + 0xc));
      if ((double)d_boss_magma::_4022 < dVar4) {
        dVar2 = 1.0 / SQRT(dVar4);
        dVar2 = d_boss_magma::_4023 * dVar2 * (d_boss_magma::_4024 - dVar4 * dVar2 * dVar2);
        dVar2 = d_boss_magma::_4023 * dVar2 * (d_boss_magma::_4024 - dVar4 * dVar2 * dVar2);
        dVar4 = (double)(float)(dVar4 * d_boss_magma::_4023 * dVar2 *
                                        (d_boss_magma::_4024 - dVar4 * dVar2 * dVar2));
      }
      if (dVar4 < (double)(d_boss_magma::_4094 + d_s_play::g_regHIO.mChild[0].mFloats[16])) {
        *(float *)(this + 0x14) =
             *(float *)(this + 0x14) +
             (d_boss_magma::_4095 + d_s_play::g_regHIO.mChild[0].mFloats[17]) *
             (float)((double)(d_boss_magma::_4094 + d_s_play::g_regHIO.mChild[0].mFloats[16]) -
                    dVar4);
      }
    }
    *(float *)(this + 0x14) = *(float *)(this + 0x14) + *(float *)((int)d_boss_magma::btd + 0x6e84);
  }
  fVar5 = SComponent::cM_rndF(d_boss_magma::_4097);
  *(short *)(this + 0x7c) = (short)(int)(d_boss_magma::_4096 + fVar5);
  fVar5 = SComponent::cM_rndF(d_boss_magma::_4099);
  *(short *)(this + 0x18) = (short)(int)(d_boss_magma::_4098 * fVar5);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}


/* __thiscall dMagma_ballBoss_c::~dMagma_ballBoss_c(void) */

void __thiscall dMagma_ballBoss_c::_dMagma_ballBoss_c(dMagma_ballBoss_c *this)

{
  short in_r4;
  
  if (this != (dMagma_ballBoss_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dMagma_ballBoss_c *)0x0) {
      *(undefined1 **)this = &dMagma_ball_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

