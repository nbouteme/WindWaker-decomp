#include <d_a_himo2.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <m_Do_mtx.h>
#include <SComponent/c_lib.h>
#include <m_Do_ext.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <mtx/mtx.h>
#include <d_kankyo.h>
#include <SComponent/c_math.h>
#include <SComponent/c_xyz.h>
#include <d_a_himo2.h>
#include <mtx/vec.h>
#include <f_op_actor.h>
#include <f_pc_executor.h>
#include <d_bg_s_acch.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_bg_s.h>
#include <d_com_inf_game.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_particle.h>
#include <d_ev_camera.h>
#include <d_attention.h>
#include <d_cc_d.h>
#include <f_pc_searcher.h>
#include <f_op_actor_iter.h>
#include <f_op_actor_mng.h>
#include <d_camera.h>
#include <d_bg_s_lin_chk.h>
#include <SComponent/c_bg_s.h>
#include <c_damagereaction.h>
#include <SComponent/c_bg_s_lin_chk.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <SComponent/c_m3d_g_sph.h>
#include <SComponent/c_cc_s.h>
#include <SComponent/c_bg_s_chk.h>
#include <m_Do_hostIO.h>
#include <d_resorce.h>
#include <d_a_esa.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JKernel/JKRHeap.h>
#include <d_save.h>
#include <cXyz.h>
#include <std.h>
#include <himo2_s.h>
#include <dEvt_info_c.h>
#include <himo2HIO_c.h>
#include <daPy_py_c.h>
#include <dAttention_c.h>
#include <cBgS_LinChk.h>
#include <daYkgr_c.h>
#include <dBgS_LinChk.h>
#include <himo2_class.h>


namespace d_a_himo2 {
undefined4 l_himo2HIO;
float rope_scale;
undefined4 btd;
undefined4 dr;

/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Removing unreachable block (ram,0x800eba9c) */
/* __stdcall spin_draw(himo2_class *) */

void spin_draw(int param_1)

{
  float fVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  undefined4 *puVar6;
  short sVar7;
  short sVar8;
  J3DModel *pJVar9;
  int iVar10;
  undefined4 uVar11;
  double dVar12;
  undefined8 in_f31;
  double dVar13;
  cXyz local_528;
  float local_51c;
  float local_518;
  float local_514;
  cXyz local_510;
  cXyz local_504;
  float local_4f8 [303];
  undefined auStack8 [8];
  
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  sVar4 = 0;
  sVar2 = *(short *)(param_1 + 0x2510);
  fVar1 = *(float *)(*(int *)(param_1 + 0x217c) + 0x218);
  local_504.z = fVar1 - _4333;
  local_504.y = _4332 * local_504.z;
  local_504.z = _4334 * local_504.z;
  if ((*(uint *)(*(int *)(param_1 + 0x217c) + 0xb0) & 0xf) == 3) {
    local_504.y = local_504.y + _4335 + d_s_play::g_regHIO.mChild[8].mFloats[8];
    local_504.z = local_504.z + _4336 + d_s_play::g_regHIO.mChild[8].mFloats[9];
  }
  if (fVar1 < _4338) {
    local_504.y = local_504.y + _4337;
  }
  if (*(char *)(param_1 + 0x251c) == '\0') {
    sVar8 = -700;
    local_504.x = _4340 + _4339 * d_s_play::g_regHIO.mChild[0].mFloats[0];
  }
  else {
    sVar8 = 700;
    local_504.x = _4339 * d_s_play::g_regHIO.mChild[0].mFloats[0] - _4340;
  }
  local_504.x = local_504.x + *(float *)(param_1 + 0x24b8);
  local_504.y = _4341 + local_504.y;
  local_504.z = _4342 + *(float *)(param_1 + 0x24b4) + local_504.z;
  m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)sVar2);
  SComponent::MtxPosition(&local_504,&local_510);
  iVar5 = *(int *)(param_1 + 0x217c);
  local_51c = *(float *)(iVar5 + 0x1f8) + local_510.x;
  local_518 = *(float *)(iVar5 + 0x1fc) + local_510.y;
  local_514 = *(float *)(iVar5 + 0x200) + local_510.z;
  local_504.x = _4343;
  local_504.y = _4343;
  local_504.z = _4344;
  puVar6 = (undefined4 *)(**(int **)(param_1 + 0x1f68) + *(int *)(param_1 + 0x1f6c) * 0xc);
  Runtime.PPCEABI.H::__construct_array(local_4f8,::cXyz::cXyz,::cXyz::_cXyz,0xc,100);
  iVar10 = 0;
  iVar5 = 0;
  dVar13 = (double)_4345;
  sVar7 = -0x30d4;
  do {
    *(float *)((int)local_4f8 + iVar5 + 4) = (float)dVar13;
    if (iVar10 < 0x32) {
      sVar3 = sVar7 + d_s_play::g_regHIO.mChild[0].mShorts[2] + 100;
    }
    else {
      if ((iVar10 < 0x32) || (*(int *)(param_1 + 0x24bc) + 0x31 < iVar10)) {
        if (*(int *)(param_1 + 0x24bc) == 0) {
          sVar3 = sVar7 + d_s_play::g_regHIO.mChild[0].mShorts[2] + 0x46;
        }
        else {
          sVar3 = sVar7 + 0x32;
        }
      }
      else {
        sVar3 = sVar7 + *(short *)(param_1 + 0x24c8);
        if (100 - (d_s_play::g_regHIO.mChild[0].mShorts[4] + 5) <= iVar10) {
          sVar3 = d_s_play::g_regHIO.mChild[0].mShorts[5] + sVar3 + -1000;
        }
        if ((*(int *)(param_1 + 0x217c) != 0) &&
           ((*(uint *)(*(int *)(param_1 + 0x217c) + 0xb0) & 0xf0) != 0)) {
          sVar4 = d_s_play::g_regHIO.mChild[0].mShorts[4] + sVar4 + -400;
        }
      }
    }
    m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)sVar2);
    m_Do_mtx::mDoMtx_ZrotM(SComponent::calc_mtx,sVar4);
    m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,sVar7);
    m_Do_mtx::mDoMtx_YrotM(SComponent::calc_mtx,sVar8);
    SComponent::MtxPosition(&local_504,&local_510);
    local_51c = local_51c + local_510.x;
    local_518 = local_518 + local_510.y;
    local_514 = local_514 + local_510.z;
    if (iVar10 == d_s_play::g_regHIO.mChild[0].mShorts[6] + 0x30) {
      *(float *)(param_1 + 0x2504) = local_51c;
      *(float *)(param_1 + 0x2508) = local_518;
      *(float *)(param_1 + 0x250c) = local_514;
    }
    if ((*(char *)(param_1 + 0x24d8) < '\x02') || (0x31 < iVar10)) {
      if (iVar10 == 99) {
        SComponent::MtxTrans((double)local_51c,(double)local_518,(double)local_514,false);
        m_Do_mtx::mDoMtx_YrotM(SComponent::calc_mtx,sVar2);
        m_Do_mtx::mDoMtx_ZrotM(SComponent::calc_mtx,sVar4);
        m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,sVar7);
        m_Do_mtx::mDoMtx_YrotM(SComponent::calc_mtx,sVar8);
        SComponent::MtxTrans((double)_4343,(double)_4343,(double)_4335,true);
        m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,*(short *)(param_1 + 0x24ca));
        local_528.x = _4343;
        local_528.y = _4343;
        local_528.z = _4340;
        SComponent::MtxPosition(&local_528,(cXyz *)(param_1 + 0x24cc));
        dVar12 = (double)_4346;
        SComponent::MtxScale(dVar12,dVar12,dVar12,1);
        pJVar9 = *(J3DModel **)(param_1 + 0x24b0);
        mtx::PSMTXCopy(SComponent::calc_mtx,&pJVar9->mBaseMtx);
        dScnKy_env_light_c::setLightTevColorType
                  (&d_kankyo::g_env_light,pJVar9,(dKy_tevstr_c *)(param_1 + 0x10c));
        m_Do_ext::mDoExt_modelUpdateDL(pJVar9);
      }
      else {
        *(float *)((int)local_4f8 + iVar5) = local_51c;
        *(float *)((int)local_4f8 + iVar5 + 4) = local_518;
        *(float *)((int)local_4f8 + iVar5 + 8) = local_514;
      }
    }
    fVar1 = _4347;
    iVar10 = iVar10 + 1;
    iVar5 = iVar5 + 0xc;
    sVar7 = sVar3;
  } while (iVar10 < 100);
  iVar5 = 0x4a4;
  iVar10 = 100;
  do {
    if (fVar1 < *(float *)((int)local_4f8 + iVar5 + 4)) {
      *puVar6 = *(undefined4 *)((int)local_4f8 + iVar5);
      puVar6[1] = *(undefined4 *)((int)local_4f8 + iVar5 + 4);
      puVar6[2] = *(undefined4 *)((int)local_4f8 + iVar5 + 8);
      *(int *)(param_1 + 0x1f6c) = *(int *)(param_1 + 0x1f6c) + 1;
      puVar6 = puVar6 + 3;
    }
    iVar5 = iVar5 + -0xc;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  Runtime.PPCEABI.H::__destroy_arr(local_4f8,::cXyz::_cXyz,0xc,100);
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x800ebca8) */
/* WARNING: Removing unreachable block (ram,0x800ebc98) */
/* WARNING: Removing unreachable block (ram,0x800ebca0) */
/* WARNING: Removing unreachable block (ram,0x800ebcb0) */
/* __stdcall himo2_control(himo2_class *,
                           himo2_s *) */

void himo2_control(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 in_f28;
  double dVar7;
  undefined8 in_f29;
  double dVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  cXyz local_74;
  cXyz local_68;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  local_68.x = _4343;
  local_68.y = _4343;
  if (*(int *)(param_1 + 0x2dc) == 0) {
    local_68.z = _4388 * *(float *)(param_1 + 0x2188) *
                 (_4389 + d_s_play::g_regHIO.mChild[8].mFloats[18]);
  }
  else {
    local_68.z = _4388 * *(float *)(param_1 + 0x2188) *
                 (_4390 + d_s_play::g_regHIO.mChild[0].mFloats[1]);
  }
  iVar3 = *(int *)(param_1 + 0x2cc) + 1;
  param_2 = param_2 + iVar3 * 0x24;
  dVar10 = (double)_4343;
  for (; iVar3 < 100; iVar3 = iVar3 + 1) {
    dVar9 = (double)((*(float *)(param_2 + 0x14) + *(float *)(param_1 + 0x2e4)) -
                    *(float *)(param_2 + -0x10));
    fVar1 = *(float *)(param_2 + 0x10) - *(float *)(param_2 + -0x14);
    dVar8 = (double)fVar1;
    fVar2 = *(float *)(param_2 + 0x18) - *(float *)(param_2 + -0xc);
    dVar7 = (double)fVar2;
    iVar4 = SComponent::cM_atan2s(fVar1,fVar2);
    dVar7 = (double)((float)(dVar8 * dVar8) + (float)(dVar7 * dVar7));
    if (dVar10 < dVar7) {
      dVar8 = 1.0 / SQRT(dVar7);
      dVar8 = _4391 * dVar8 * (_4392 - dVar7 * dVar8 * dVar8);
      dVar8 = _4391 * dVar8 * (_4392 - dVar7 * dVar8 * dVar8);
      dVar7 = (double)(float)(dVar7 * _4391 * dVar8 * (_4392 - dVar7 * dVar8 * dVar8));
    }
    iVar5 = SComponent::cM_atan2s((float)dVar9,(float)dVar7);
    m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)(short)iVar4);
    m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,-(short)iVar5);
    SComponent::MtxPosition(&local_68,&local_74);
    *(float *)(param_2 + 0x10) = *(float *)(param_2 + -0x14) + local_74.x;
    *(float *)(param_2 + 0x14) = *(float *)(param_2 + -0x10) + local_74.y;
    *(float *)(param_2 + 0x18) = *(float *)(param_2 + -0xc) + local_74.z;
    param_2 = param_2 + 0x24;
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  __psq_l0(auStack40,uVar6);
  __psq_l1(auStack40,uVar6);
  __psq_l0(auStack56,uVar6);
  __psq_l1(auStack56,uVar6);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x800ebfc4) */
/* WARNING: Removing unreachable block (ram,0x800ebfb4) */
/* WARNING: Removing unreachable block (ram,0x800ebfa4) */
/* WARNING: Removing unreachable block (ram,0x800ebf9c) */
/* WARNING: Removing unreachable block (ram,0x800ebfac) */
/* WARNING: Removing unreachable block (ram,0x800ebfbc) */
/* WARNING: Removing unreachable block (ram,0x800ebfcc) */
/* __stdcall himo2_control2(himo2_class *,
                            himo2_s *) */

void himo2_control2(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 in_f25;
  double dVar7;
  undefined8 in_f26;
  double dVar8;
  undefined8 in_f27;
  double dVar9;
  undefined8 in_f28;
  double dVar10;
  undefined8 in_f29;
  double dVar11;
  undefined8 in_f30;
  double dVar12;
  undefined8 in_f31;
  double dVar13;
  cXyz local_b4;
  cXyz local_a8;
  undefined4 local_98;
  uint uStack148;
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  local_a8.x = _4343;
  local_a8.y = _4343;
  param_2 = param_2 + 0xdc8;
  if (*(int *)(param_1 + 0x2dc) == 0) {
    local_a8.z = _4388 * *(float *)(param_1 + 0x2188) *
                 (_4389 + d_s_play::g_regHIO.mChild[8].mFloats[18]);
  }
  else {
    local_a8.z = _4388 * *(float *)(param_1 + 0x2188) *
                 (_4390 + d_s_play::g_regHIO.mChild[0].mFloats[1]);
  }
  dVar10 = (double)_4343;
  dVar9 = (double)(_4339 + d_s_play::g_regHIO.mChild[8].mFloats[17]);
  iVar4 = *(int *)(param_1 + 0x2cc);
  dVar11 = dVar10;
  dVar13 = dVar10;
  while (iVar4 = iVar4 + 1, iVar4 < 100) {
    dVar12 = (double)(*(float *)(param_2 + 0x14) - *(float *)(param_2 + 0x38));
    iVar3 = *(int *)(param_1 + 0x2dc);
    if ((-1 < iVar3) && (iVar3 < 4)) {
      if (iVar3 != 0) {
        uStack148 = 99U - iVar4 ^ 0x80000000;
        local_98 = 0x43300000;
        dVar9 = (double)(_4450 * *(float *)(param_1 + 0x2530) *
                                 (float)((double)CONCAT44(0x43300000,uStack148) - _4452));
      }
      dVar11 = (double)(float)(dVar9 * (double)JKernel::JMath::jmaSinTable
                                               [(int)(*(int *)(param_1 + 0x2d8) *
                                                      (d_s_play::g_regHIO.mChild[0].mShorts[5] + 700
                                                      ) + iVar4 * (d_s_play::g_regHIO.mChild[0].
                                                                   mShorts[6] + 2000) & 0xffffU) >>
                                                (JKernel::JMath::jmaSinShift & 0x3f)]);
      dVar10 = (double)(float)(dVar9 * (double)JKernel::JMath::jmaCosTable
                                               [(int)(*(int *)(param_1 + 0x2d8) *
                                                      (d_s_play::g_regHIO.mChild[0].mShorts[7] + 500
                                                      ) + iVar4 * (d_s_play::g_regHIO.mChild[0].
                                                                   mShorts[8] + 2000) & 0xffffU) >>
                                                (JKernel::JMath::jmaSinShift & 0x3f)]);
    }
    fVar1 = (float)(dVar11 + (double)(*(float *)(param_2 + 0x10) - *(float *)(param_2 + 0x34)));
    dVar8 = (double)fVar1;
    fVar2 = (float)(dVar10 + (double)(*(float *)(param_2 + 0x18) - *(float *)(param_2 + 0x3c)));
    dVar7 = (double)fVar2;
    iVar3 = SComponent::cM_atan2s(fVar1,fVar2);
    dVar7 = (double)((float)(dVar8 * dVar8) + (float)(dVar7 * dVar7));
    if (dVar13 < dVar7) {
      dVar8 = 1.0 / SQRT(dVar7);
      dVar8 = _4391 * dVar8 * (_4392 - dVar7 * dVar8 * dVar8);
      dVar8 = _4391 * dVar8 * (_4392 - dVar7 * dVar8 * dVar8);
      dVar7 = (double)(float)(dVar7 * _4391 * dVar8 * (_4392 - dVar7 * dVar8 * dVar8));
    }
    iVar5 = SComponent::cM_atan2s((float)dVar12,(float)dVar7);
    *(short *)(param_2 + 0x42) = (short)iVar3;
    *(short *)(param_2 + 0x40) = -(short)iVar5;
    m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)(short)iVar3);
    m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,-(short)iVar5);
    SComponent::MtxPosition(&local_a8,&local_b4);
    *(float *)(param_2 + 0x10) = *(float *)(param_2 + 0x34) + local_b4.x;
    *(float *)(param_2 + 0x14) = *(float *)(param_2 + 0x38) + local_b4.y;
    *(float *)(param_2 + 0x18) = *(float *)(param_2 + 0x3c) + local_b4.z;
    param_2 = param_2 + -0x24;
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  __psq_l0(auStack40,uVar6);
  __psq_l1(auStack40,uVar6);
  __psq_l0(auStack56,uVar6);
  __psq_l1(auStack56,uVar6);
  __psq_l0(auStack72,uVar6);
  __psq_l1(auStack72,uVar6);
  __psq_l0(auStack88,uVar6);
  __psq_l1(auStack88,uVar6);
  __psq_l0(auStack104,uVar6);
  __psq_l1(auStack104,uVar6);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall himo2_draw(himo2_class *,
                        himo2_s *) */

void himo2_draw(int param_1,int param_2)

{
  daPy_lk_c *pdVar1;
  int iVar2;
  MTX34 *pMVar3;
  J3DModel *pJVar4;
  undefined4 *puVar5;
  double dVar6;
  cXyz local_38 [2];
  
  pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  puVar5 = (undefined4 *)(**(int **)(param_1 + 0x1f68) + *(int *)(param_1 + 0x1f6c) * 0xc);
  *puVar5 = *(undefined4 *)(param_1 + 0x2b4);
  puVar5[1] = *(undefined4 *)(param_1 + 0x2b8);
  puVar5[2] = *(undefined4 *)(param_1 + 700);
  *(int *)(param_1 + 0x1f6c) = *(int *)(param_1 + 0x1f6c) + 1;
  iVar2 = *(int *)(param_1 + 0x2cc);
  param_2 = param_2 + (iVar2 + 1) * 0x24;
  puVar5 = puVar5 + 3;
  do {
    if (0x61 < iVar2) {
      return;
    }
    if (iVar2 == 0x61) {
      if (*(int *)(param_1 + 0x2dc) == 0) {
        if (_4492 + d_s_play::g_regHIO.mChild[0].mFloats[3] <= *(float *)(param_1 + 0x2188))
        goto LAB_800ec0d8;
        pMVar3 = (MTX34 *)(*(code *)pdVar1->vtbl->getLeftHandMatrix)(pdVar1);
        mtx::PSMTXCopy(pMVar3,SComponent::calc_mtx);
        SComponent::MtxTrans((double)_4339,(double)_4343,(double)_4343,true);
        m_Do_mtx::mDoMtx_YrotM(SComponent::calc_mtx,0x4000);
      }
      else {
LAB_800ec0d8:
        SComponent::MtxTrans
                  ((double)*(float *)(param_2 + 0x10),(double)*(float *)(param_2 + 0x14),
                   (double)*(float *)(param_2 + 0x18),false);
        m_Do_mtx::mDoMtx_YrotM(SComponent::calc_mtx,*(short *)(param_2 + 0x1e));
        m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,*(short *)(param_2 + 0x1c));
        SComponent::MtxTrans((double)_4343,(double)_4343,(double)_4493,true);
        SComponent::MtxRotX((double)_4494,1);
        SComponent::MtxRotZ((double)_4494,1);
      }
      dVar6 = (double)_4346;
      SComponent::MtxScale(dVar6,dVar6,dVar6,1);
      local_38[0].x = _4343;
      local_38[0].y = _4343;
      local_38[0].z = _4340;
      SComponent::MtxPosition(local_38,(cXyz *)(param_1 + 0x24cc));
      pJVar4 = *(J3DModel **)(param_1 + 0x24b0);
      mtx::PSMTXCopy(SComponent::calc_mtx,&pJVar4->mBaseMtx);
      dScnKy_env_light_c::setLightTevColorType
                (&d_kankyo::g_env_light,pJVar4,(dKy_tevstr_c *)(param_1 + 0x10c));
      m_Do_ext::mDoExt_modelUpdateDL(pJVar4);
    }
    else {
      *puVar5 = *(undefined4 *)(param_2 + 0x10);
      puVar5[1] = *(undefined4 *)(param_2 + 0x14);
      puVar5[2] = *(undefined4 *)(param_2 + 0x18);
      *(int *)(param_1 + 0x1f6c) = *(int *)(param_1 + 0x1f6c) + 1;
      puVar5 = puVar5 + 3;
    }
    iVar2 = iVar2 + 1;
    param_2 = param_2 + 0x24;
  } while( true );
}


/* __stdcall himo_hang_draw(himo2_class *) */

void himo_hang_draw(int param_1)

{
  double dVar1;
  uint uVar2;
  uint uVar3;
  float *pfVar4;
  int iVar5;
  cXyz local_38 [4];
  
  pfVar4 = (float *)(**(int **)(param_1 + 0x1f68) + *(int *)(param_1 + 0x1f6c) * 0xc);
  ::cXyz::operator__(local_38,(cXyz *)(param_1 + 0x2ec),(cXyz *)(param_1 + 0x2504));
  dVar1 = _4452;
  local_38[0].x = local_38[0].x * _4515;
  local_38[0].y = local_38[0].y * _4515;
  local_38[0].z = local_38[0].z * _4515;
  uVar3 = 0;
  iVar5 = 5;
  do {
    uVar2 = uVar3 ^ 0x80000000;
    *pfVar4 = *(float *)(param_1 + 0x2504) +
              local_38[0].x * (float)((double)CONCAT44(0x43300000,uVar2) - dVar1);
    pfVar4[1] = *(float *)(param_1 + 0x2508) +
                local_38[0].y * (float)((double)CONCAT44(0x43300000,uVar2) - dVar1);
    pfVar4[2] = *(float *)(param_1 + 0x250c) +
                local_38[0].z * (float)((double)CONCAT44(0x43300000,uVar2) - dVar1);
    *(int *)(param_1 + 0x1f6c) = *(int *)(param_1 + 0x1f6c) + 1;
    uVar3 = uVar3 + 1;
    pfVar4 = pfVar4 + 3;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return;
}


/* __stdcall himo2_disp(himo2_class *) */

void himo2_disp(int param_1)

{
  if (*(int *)(param_1 + 0x2dc) < 10) {
    himo2_draw(param_1,param_1 + 0x310);
  }
  else {
    himo_hang_draw();
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* WARNING: Removing unreachable block (ram,0x800ecbc0) */
/* WARNING: Removing unreachable block (ram,0x800ecbb0) */
/* WARNING: Removing unreachable block (ram,0x800ecba0) */
/* WARNING: Removing unreachable block (ram,0x800ecba8) */
/* WARNING: Removing unreachable block (ram,0x800ecbb8) */
/* WARNING: Removing unreachable block (ram,0x800ecbc8) */
/* __stdcall daHimo2_Draw(himo2_class *) */

undefined4 daHimo2_Draw(int param_1)

{
  float fVar1;
  daPy_lk_c *pdVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  cXyz *pDst;
  float *pfVar10;
  undefined4 uVar11;
  undefined8 in_f26;
  double dVar12;
  undefined8 in_f27;
  double dVar13;
  undefined8 in_f28;
  double dVar14;
  undefined8 in_f29;
  double dVar15;
  undefined8 in_f30;
  double dVar16;
  undefined8 in_f31;
  double dVar17;
  undefined auStack4184 [16];
  undefined auStack4168 [16];
  undefined auStack4152 [16];
  undefined auStack4136 [16];
  undefined auStack4120 [16];
  undefined auStack4104 [1448];
  _GXColor local_a58;
  _GXColor local_a54;
  _GXColor local_a50;
  cXyz local_a4c;
  cXyz local_a40;
  float local_a34;
  float local_a30;
  float local_a2c;
  cXyz local_a28;
  cXyz local_a1c;
  undefined4 local_a10 [600];
  double local_b0;
  double local_a8;
  undefined4 local_a0;
  uint uStack156;
  
  uVar11 = 0;
  __psq_st0(auStack4104,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack4104,(int)in_f31,0);
  __psq_st0(auStack4120,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack4120,(int)in_f30,0);
  __psq_st0(auStack4136,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack4136,(int)in_f29,0);
  __psq_st0(auStack4152,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack4152,(int)in_f28,0);
  __psq_st0(auStack4168,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack4168,(int)in_f27,0);
  __psq_st0(auStack4184,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack4184,(int)in_f26,0);
  if (((-1 < *(char *)(param_1 + 0x24d9)) && (*(short *)(param_1 + 0x29e) == 0)) &&
     ((*(int *)(param_1 + 0x2dc) != 0 ||
      ((iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->vtbl->
                          checkPlayerNoDraw)(), iVar3 == 0 &&
       (iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->vtbl->
                          checkPlayerGuard)(), iVar3 == 0)))))) {
    dScnKy_env_light_c::settingTevStruct
              (&d_kankyo::g_env_light,Actor,(cXyz *)(param_1 + 0x1f8),
               (dKy_tevstr_c *)(param_1 + 0x10c));
    *(undefined4 *)(param_1 + 0x1f6c) = 0;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0xc;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x10;
    if (*(char *)(param_1 + 0x24d8) != '\0') {
      spin_draw(param_1);
    }
    if ((*(char *)(param_1 + 0x24d9) == '\0') || ('\x02' < *(char *)(param_1 + 0x24d9))) {
      himo2_disp(param_1);
    }
    if (*(int *)(param_1 + 0x1f6c) < 0xc9) {
      puVar7 = (undefined4 *)**(undefined4 **)(param_1 + 0x1f68);
      Runtime.PPCEABI.H::__construct_array(local_a10,::cXyz::cXyz,::cXyz::_cXyz,0xc,200);
      iVar3 = 0;
      for (iVar5 = 0; iVar5 < *(int *)(param_1 + 0x1f6c); iVar5 = iVar5 + 1) {
        *(undefined4 *)((int)local_a10 + iVar3) = *puVar7;
        *(undefined4 *)((int)local_a10 + iVar3 + 4) = puVar7[1];
        *(undefined4 *)((int)local_a10 + iVar3 + 8) = puVar7[2];
        puVar7 = puVar7 + 3;
        iVar3 = iVar3 + 0xc;
      }
      iVar3 = 0;
      for (iVar5 = 0; iVar5 < *(int *)(param_1 + 0x1f6c); iVar5 = iVar5 + 1) {
        puVar7[-3] = *(undefined4 *)((int)local_a10 + iVar3);
        puVar7[-2] = *(undefined4 *)((int)local_a10 + iVar3 + 4);
        puVar7[-1] = *(undefined4 *)((int)local_a10 + iVar3 + 8);
        iVar3 = iVar3 + 0xc;
        puVar7 = puVar7 + -3;
      }
      local_a50 = _4561;
      mDoExt_3DlineMat1_c::update
                ((mDoExt_3DlineMat1_c *)(param_1 + 0x1f30),(ushort)*(undefined4 *)(param_1 + 0x1f6c)
                 ,rope_scale,&local_a50,0,(dKy_tevstr_c *)(param_1 + 0x10c));
      iVar3 = (**(code **)(*(int *)(param_1 + 0x1f30) + 8))(param_1 + 0x1f30);
      mDoExt_3DlineMatSortPacket::setMat
                (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.m3DLineMatSortPacket + iVar3,
                 (mDoExt_3DlineMat_c *)(param_1 + 0x1f30));
      pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
      m_Do_mtx::mDoMtx_YrotS
                (SComponent::calc_mtx,
                 (int)-((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.
                       mCollisionRot.y);
      ::cXyz::operator__(&local_a40,(cXyz *)(param_1 + 0x2f8),(cXyz *)(param_1 + 0x1f84));
      local_a1c.x = local_a40.x;
      local_a1c.y = local_a40.y;
      local_a1c.z = local_a40.z;
      SComponent::MtxPosition(&local_a1c,&local_a28);
      local_a28.z = local_a28.z * (_4719 + d_s_play::g_regHIO.mChild[0].mFloats[5]);
      if (_4720 < local_a28.z) {
        local_a28.z = _4720;
      }
      if (local_a28.z < _4721) {
        local_a28.z = _4721;
      }
      local_b0 = (double)(longlong)(int)local_a28.z;
      SComponent::cLib_addCalcAngleS2
                ((short *)(param_1 + 0x1f90),(short)(int)local_a28.z,2,
                 d_s_play::g_regHIO.mChild[0].mShorts[2] + 0x800);
      local_a28.x = local_a28.x * (_4722 + d_s_play::g_regHIO.mChild[0].mFloats[6]);
      fVar1 = _4723 + d_s_play::g_regHIO.mChild[0].mFloats[7];
      if (fVar1 < local_a28.x) {
        local_a28.x = fVar1;
      }
      if (local_a28.x < -fVar1) {
        local_a28.x = -fVar1;
      }
      local_a8 = (double)(longlong)(int)local_a28.x;
      SComponent::cLib_addCalcAngleS2
                ((short *)(param_1 + 0x1f94),(short)(int)local_a28.x,2,
                 d_s_play::g_regHIO.mChild[0].mShorts[2] + 0x800);
      if (_4724 + d_s_play::g_regHIO.mChild[0].mFloats[8] <= local_a28.y) {
        SComponent::cLib_addCalcAngleS2((short *)(param_1 + 0x1f92),0,2,0x1000);
      }
      else {
        SComponent::cLib_addCalcAngleS2((short *)(param_1 + 0x1f92),-0x8000,2,0x1000);
      }
      *(undefined4 *)(param_1 + 0x1f84) = *(undefined4 *)(param_1 + 0x2f8);
      *(undefined4 *)(param_1 + 0x1f88) = *(undefined4 *)(param_1 + 0x2fc);
      *(undefined4 *)(param_1 + 0x1f8c) = *(undefined4 *)(param_1 + 0x300);
      local_a1c.z = _4343;
      local_a1c.x = _4343;
      dVar15 = (double)((d_s_play::g_regHIO.mChild[0].mFloats[10] +
                        *(float *)(param_1 + 0x2188) *
                        (_4337 + d_s_play::g_regHIO.mChild[0].mFloats[9])) - _4725);
      iVar9 = 0;
      iVar5 = 0;
      iVar3 = 0;
      dVar16 = (double)_4726;
      dVar12 = (double)_4340;
      dVar13 = (double)_4333;
      dVar14 = (double)_4728;
      dVar17 = _4452;
      do {
        pDst = *(cXyz **)(*(int *)(param_1 + 0x1fd0) + iVar3);
        local_a8 = (double)CONCAT44(0x43300000,4U - iVar9 ^ 0x80000000);
        if (dVar15 <= (double)(float)(dVar16 * (double)(float)(local_a8 - dVar17))) {
          SComponent::cLib_addCalc2
                    ((float *)(param_1 + iVar5 + 0x1f70),_4333,_4333,
                     _4727 + d_s_play::g_regHIO.mChild[0].mFloats[12]);
        }
        else {
          SComponent::cLib_addCalc0
                    ((float *)(param_1 + iVar5 + 0x1f70),_4333,
                     _4346 + d_s_play::g_regHIO.mChild[0].mFloats[11]);
        }
        local_a1c.y = (float)(dVar12 * (double)*(float *)(param_1 + iVar5 + 0x1f70));
        m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)(pdVar2->parent).parent.mCollisionRot.y);
        iVar8 = (int)((float)(dVar13 - (double)*(float *)(param_1 + iVar5 + 0x1f70)) *
                     (float)(dVar14 + (double)d_s_play::g_regHIO.mChild[0].mFloats[13]));
        local_a8 = (double)(longlong)iVar8;
        m_Do_mtx::mDoMtx_ZrotM
                  (SComponent::calc_mtx,
                   *(short *)(param_1 + 0x1f92) +
                   (short)iVar9 *
                   (d_s_play::g_regHIO.mChild[0].mShorts[0] + *(short *)(param_1 + 0x1f94) + -2000)
                   + (short)iVar8);
        m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,*(short *)(param_1 + 0x1f90));
        SComponent::MtxTrans((double)_4343,-(double)local_a1c.y,(double)_4343,true);
        iVar8 = 0;
        do {
          m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,0x800);
          SComponent::MtxPosition(&local_a1c,pDst);
          mtx::PSVECAdd(pDst,(cXyz *)(param_1 + 0x2f8),pDst);
          iVar8 = iVar8 + 1;
          pDst = pDst + 1;
        } while (iVar8 < 0x20);
        iVar9 = iVar9 + 1;
        iVar5 = iVar5 + 4;
        iVar3 = iVar3 + 0x18;
      } while (iVar9 < 5);
      local_a54 = _4587;
      mDoExt_3DlineMat1_c::update
                ((mDoExt_3DlineMat1_c *)(param_1 + 0x1f98),0x20,rope_scale,&local_a54,0,
                 (dKy_tevstr_c *)(param_1 + 0x10c));
      iVar3 = (**(code **)(*(int *)(param_1 + 0x1f98) + 8))(param_1 + 0x1f98);
      mDoExt_3DlineMatSortPacket::setMat
                (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.m3DLineMatSortPacket + iVar3,
                 (mDoExt_3DlineMat_c *)(param_1 + 0x1f98));
      pfVar10 = **(float ***)(param_1 + 0x2010);
      local_a8 = (double)(longlong)(int)*(float *)(param_1 + 0x2188);
      fVar1 = _4343;
      if (((int)*(float *)(param_1 + 0x2188) & (int)d_s_play::g_regHIO.mChild[0].mShorts[4] + 0x40U)
          != 0) {
        fVar1 = _4340 + d_s_play::g_regHIO.mChild[0].mFloats[14];
      }
      SComponent::cLib_addCalc2
                ((float *)(param_1 + 0x1fd4),fVar1,_4333,
                 _4729 + d_s_play::g_regHIO.mChild[0].mFloats[15]);
      ::cXyz::operator__(&local_a4c,(cXyz *)(param_1 + 0x2ec),(cXyz *)(param_1 + 0x2f8));
      local_a34 = local_a4c.x;
      local_a30 = local_a4c.y;
      local_a2c = local_a4c.z;
      iVar3 = SComponent::cM_atan2s(local_a4c.x,local_a4c.z);
      m_Do_mtx::mDoMtx_YrotS
                (SComponent::calc_mtx,
                 (int)(short)((short)iVar3 + d_s_play::g_regHIO.mChild[0].mShorts[0] + -0x4000));
      local_a1c.x = _4343;
      local_a1c.y = ((_4730 + d_s_play::g_regHIO.mChild[0].mFloats[7]) -
                    *(float *)(param_1 + 0x1fd4)) * *(float *)(param_1 + 0x1f70);
      local_a1c.z = (_4339 + d_s_play::g_regHIO.mChild[0].mFloats[8] + *(float *)(param_1 + 0x1fd4))
                    * *(float *)(param_1 + 0x1f70);
      SComponent::MtxPosition(&local_a1c,&local_a28);
      dVar17 = _4452;
      local_a34 = local_a34 * _4731;
      local_a30 = local_a30 * _4731;
      local_a2c = local_a2c * _4731;
      uVar6 = 0;
      uVar4 = 0;
      iVar3 = 0x10;
      do {
        fVar1 = JKernel::JMath::jmaSinTable
                [(int)(uVar4 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
        uStack156 = uVar6 ^ 0x80000000;
        local_a8 = (double)CONCAT44(0x43300000,uStack156);
        *pfVar10 = *(float *)(param_1 + 0x2f8) + local_a34 * (float)(local_a8 - dVar17) +
                   local_a28.x * fVar1;
        local_b0 = (double)CONCAT44(0x43300000,uStack156);
        pfVar10[1] = *(float *)(param_1 + 0x2fc) + local_a30 * (float)(local_b0 - dVar17) +
                     local_a28.y * fVar1;
        local_a0 = 0x43300000;
        pfVar10[2] = *(float *)(param_1 + 0x300) +
                     local_a2c * (float)((double)CONCAT44(0x43300000,uStack156) - dVar17) +
                     local_a28.z * fVar1;
        pfVar10 = pfVar10 + 3;
        uVar6 = uVar6 + 1;
        uVar4 = uVar4 + 0x888;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      local_a58 = _4597;
      mDoExt_3DlineMat1_c::update
                ((mDoExt_3DlineMat1_c *)(param_1 + 0x1fd8),0x10,rope_scale,&local_a58,0,
                 (dKy_tevstr_c *)(param_1 + 0x10c));
      iVar3 = (**(code **)(*(int *)(param_1 + 0x1fd8) + 8))(param_1 + 0x1fd8);
      mDoExt_3DlineMatSortPacket::setMat
                (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.m3DLineMatSortPacket + iVar3,
                 (mDoExt_3DlineMat_c *)(param_1 + 0x1fd8));
      J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
           d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
      J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
           d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
      Runtime.PPCEABI.H::__destroy_arr(local_a10,::cXyz::_cXyz,0xc,200);
    }
    else {
      J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
           d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
      J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
           d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
    }
  }
  __psq_l0(auStack4104,uVar11);
  __psq_l1(auStack4104,uVar11);
  __psq_l0(auStack4120,uVar11);
  __psq_l1(auStack4120,uVar11);
  __psq_l0(auStack4136,uVar11);
  __psq_l1(auStack4136,uVar11);
  __psq_l0(auStack4152,uVar11);
  __psq_l1(auStack4152,uVar11);
  __psq_l0(auStack4168,uVar11);
  __psq_l1(auStack4168,uVar11);
  __psq_l0(auStack4184,uVar11);
  __psq_l1(auStack4184,uVar11);
  return 1;
}


/* __stdcall s_a_d_sub(void *,
                       void *) */

undefined4 s_a_d_sub(fopAc_ac_c *param_1,int param_2)

{
  bool bVar1;
  
  bVar1 = f_op_actor::fopAc_IsActor(param_1);
  if ((bVar1 != false) && ((param_1->parent).parent.mProcName == 0xfc)) {
    *(fopAc_ac_c **)(param_2 + (uint)*(byte *)(param_2 + 0x24ac) * 4 + 0x218c) = param_1;
    *(char *)(param_2 + 0x24ac) = *(char *)(param_2 + 0x24ac) + '\x01';
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Removing unreachable block (ram,0x800ed17c) */
/* __stdcall search_target(himo2_class *,
                           cXyz) */

int search_target(void *param_1,float *param_2)

{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  daPy_lk_c *pdVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  short sVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  undefined4 uVar18;
  double dVar19;
  double dVar20;
  undefined8 in_f31;
  double dVar21;
  cXyz local_60;
  cXyz local_54 [2];
  undefined auStack8 [8];
  
  pdVar9 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  uVar18 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  *(undefined *)((int)param_1 + 0x24ac) = 0;
  iVar14 = 0;
  iVar17 = 100;
  do {
    *(undefined4 *)((int)param_1 + iVar14 + 0x218c) = 0;
    iVar14 = iVar14 + 4;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  f_pc_executor::fpcEx_Search(s_a_d_sub,param_1);
  m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)-(pdVar9->parent).parent.mCollisionRot.y);
  dVar21 = (double)_4915;
  sVar10 = 0x4000 - DAT_803e421c;
  sVar11 = DAT_803e421c + 0x4000;
  if (*(char *)((int)param_1 + 0x24ac) == '\0') {
    iVar14 = 0;
  }
  else {
    uVar16 = 0;
    do {
      do {
        if ((int)(uint)*(byte *)((int)param_1 + 0x24ac) <= (int)uVar16) {
          iVar14 = 0;
          goto LAB_800ed17c;
        }
        iVar14 = *(int *)((int)param_1 + uVar16 * 4 + 0x218c);
        bVar1 = (*(uint *)(iVar14 + 0xb0) & 0xf0) != 0;
        local_54[0].x = (pdVar9->parent).parent.mCurrent.mPos.x - *(float *)(iVar14 + 0x1f8);
        local_54[0].z = (pdVar9->parent).parent.mCurrent.mPos.z - *(float *)(iVar14 + 0x200);
        iVar17 = SComponent::cM_atan2s(local_54[0].x,local_54[0].z);
        sVar12 = *(short *)(iVar14 + 0x206) - (short)iVar17;
        if ((-1 < sVar12) || (bVar1)) {
          *(undefined *)((int)param_1 + 0x251c) = 0;
        }
        else {
          sVar12 = -sVar12;
          *(undefined *)((int)param_1 + 0x251c) = 1;
        }
        if ((bVar1) || ((sVar10 < sVar12 && (sVar12 < sVar11)))) {
          local_54[0].x = *(float *)(iVar14 + 0x1f8) - (pdVar9->parent).parent.mCurrent.mPos.x;
          local_54[0].y = *(float *)(iVar14 + 0x1fc) - (pdVar9->parent).parent.mCurrent.mPos.y;
          local_54[0].z = *(float *)(iVar14 + 0x200) - (pdVar9->parent).parent.mCurrent.mPos.z;
          SComponent::MtxPosition(local_54,&local_60);
          if ((_4915 < local_60.z) && ((bVar1 || (ABS(local_60.y) < DAT_803e4228)))) {
            dVar20 = (double)(local_60.x * local_60.x + local_60.z * local_60.z);
            if ((double)_4343 < dVar20) {
              dVar19 = 1.0 / SQRT(dVar20);
              dVar19 = _4391 * dVar19 * (_4392 - dVar20 * dVar19 * dVar19);
              dVar19 = _4391 * dVar19 * (_4392 - dVar20 * dVar19 * dVar19);
              dVar20 = (double)(float)(dVar20 * _4391 * dVar19 * (_4392 - dVar20 * dVar19 * dVar19))
              ;
            }
            if (dVar20 < dVar21) {
              fVar2 = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mEyePos).
                      x;
              fVar6 = *param_2 - fVar2;
              fVar3 = param_2[1];
              fVar4 = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mEyePos).
                      y;
              fVar5 = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mEyePos).
                      z;
              fVar8 = param_2[2] - fVar5;
              fVar2 = *(float *)(iVar14 + 0x1f8) - fVar2;
              fVar7 = *(float *)(iVar14 + 0x1fc) - fVar4;
              fVar5 = *(float *)(iVar14 + 0x200) - fVar5;
              iVar17 = SComponent::cM_atan2s(fVar6,fVar8);
              iVar15 = SComponent::cM_atan2s(fVar2,fVar5);
              sVar12 = (short)iVar15 - (short)iVar17;
              if (sVar12 < 0) {
                sVar12 = -sVar12;
              }
              dVar20 = (double)(fVar5 * fVar5 + fVar2 * fVar2 + fVar7 * fVar7);
              if ((double)_4343 < dVar20) {
                dVar19 = 1.0 / SQRT(dVar20);
                dVar19 = _4391 * dVar19 * (_4392 - dVar20 * dVar19 * dVar19);
                dVar19 = _4391 * dVar19 * (_4392 - dVar20 * dVar19 * dVar19);
                dVar20 = (double)(float)(dVar20 * _4391 * dVar19 *
                                                  (_4392 - dVar20 * dVar19 * dVar19));
              }
              iVar17 = SComponent::cM_atan2s
                                 (*(float *)(iVar14 + 0x21c) * DAT_803e4224,(float)dVar20);
              sVar13 = (short)iVar17;
              if (sVar13 < 0) {
                sVar13 = -sVar13;
              }
              if ((-sVar13 < sVar12) && (sVar12 < sVar13)) {
                dVar20 = (double)(fVar6 * fVar6 + fVar8 * fVar8);
                if ((double)_4343 < dVar20) {
                  dVar19 = 1.0 / SQRT(dVar20);
                  dVar19 = _4391 * dVar19 * (_4392 - dVar20 * dVar19 * dVar19);
                  dVar19 = _4391 * dVar19 * (_4392 - dVar20 * dVar19 * dVar19);
                  dVar20 = (double)(float)(dVar20 * _4391 * dVar19 *
                                                    (_4392 - dVar20 * dVar19 * dVar19));
                }
                iVar17 = SComponent::cM_atan2s(fVar3 - fVar4,(float)dVar20);
                dVar20 = (double)(fVar2 * fVar2 + fVar5 * fVar5);
                if ((double)_4343 < dVar20) {
                  dVar19 = 1.0 / SQRT(dVar20);
                  dVar19 = _4391 * dVar19 * (_4392 - dVar20 * dVar19 * dVar19);
                  dVar19 = _4391 * dVar19 * (_4392 - dVar20 * dVar19 * dVar19);
                  dVar20 = (double)(float)(dVar20 * _4391 * dVar19 *
                                                    (_4392 - dVar20 * dVar19 * dVar19));
                }
                iVar15 = SComponent::cM_atan2s(fVar7,(float)dVar20);
                sVar12 = DAT_803e4220;
                if (bVar1) {
                  sVar12 = 2000;
                }
                if (((int)(short)-(short)iVar17 < (int)(short)-(short)iVar15 + (int)DAT_803e4222) &&
                   ((short)(-(short)iVar15 + (short)iVar17) < sVar12)) goto LAB_800ed17c;
              }
            }
          }
        }
        uVar16 = uVar16 + 1;
      } while (uVar16 != *(byte *)((int)param_1 + 0x24ac));
      uVar16 = 0;
      dVar21 = (double)(float)(dVar21 + (double)_4915);
      fVar2 = DAT_803e422c;
      if (bVar1) {
        fVar2 = _4916;
      }
    } while (dVar21 <= (double)fVar2);
    iVar14 = 0;
  }
LAB_800ed17c:
  __psq_l0(auStack8,uVar18);
  __psq_l1(auStack8,uVar18);
  return iVar14;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall himo2_class::setTargetPos(cXyz *,
                                        float *,
                                        float *) */

undefined4 __thiscall
himo2_class::setTargetPos(himo2_class *this,cXyz *param_1,float *param_2,float *param_3)

{
  float fVar1;
  double dVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  fVar1 = d_a_himo2::_4949;
  *param_2 = d_a_himo2::_4949;
  *param_3 = fVar1;
  *(float *)(this + 0x2524) = param_1->x;
  *(float *)(this + 0x2528) = param_1->y;
  *(float *)(this + 0x252c) = param_1->z;
  local_38 = *(undefined4 *)(this + 0x2524);
  local_34 = *(undefined4 *)(this + 0x2528);
  local_30 = *(undefined4 *)(this + 0x252c);
  iVar3 = d_a_himo2::search_target(this,&local_38);
  *(int *)(this + 0x217c) = iVar3;
  dVar2 = d_a_himo2::_4953;
  fVar1 = d_a_himo2::_4915;
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    if ((*(uint *)(*(int *)(this + 0x217c) + 0xb0) & 0xf0) == 0) {
      *param_2 = d_a_himo2::_4915 *
                 (float)((double)CONCAT44(0x43300000,
                                          *(uint *)(*(int *)(this + 0x217c) + 0xb0) >> 0x10 & 0xf) -
                        d_a_himo2::_4953);
      *param_3 = fVar1 * (float)((double)CONCAT44(0x43300000,
                                                  *(uint *)(*(int *)(this + 0x217c) + 0xb0) >> 0x14
                                                  & 0xf) - dVar2);
      if (d_a_himo2::_4951 <= *param_2) {
        *param_2 = d_a_himo2::_4949;
      }
      if (d_a_himo2::_4951 <= *param_3) {
        *param_3 = d_a_himo2::_4949;
      }
    }
    else {
      *param_2 = d_a_himo2::_4950;
      *param_3 = d_a_himo2::_4915;
    }
    uVar4 = 1;
  }
  return uVar4;
}


namespace d_a_himo2 {

/* __stdcall dr_a_sub(void *,
                      void *) */

fopAc_ac_c * dr_a_sub(fopAc_ac_c *param_1)

{
  bool bVar1;
  
  bVar1 = f_op_actor::fopAc_IsActor(param_1);
  if ((bVar1 == false) || ((param_1->parent).parent.mProcName != 0xe0)) {
    param_1 = (fopAc_ac_c *)0x0;
  }
  return param_1;
}


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


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall himo2_bg_check(himo2_class *) */

undefined4 himo2_bg_check(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  char cVar6;
  ulong uVar3;
  sbyte sVar7;
  int iVar4;
  JPABaseEmitter *pJVar5;
  csXyz local_38;
  cXyz local_30;
  cBgS_PolyInfo local_24;
  
  if (*(short *)(param_1 + 0x2a2) == 0) {
    dBgS_Acch::CrrPos((dBgS_Acch *)(param_1 + 0x2574),&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS
                     );
    uVar2 = *(uint *)(param_1 + 0x259c);
    if ((((uVar2 & 0x10) == 0) && ((uVar2 & 0x200) == 0)) && ((uVar2 & 0x20) == 0)) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x2dc) = 9;
    *(float *)(param_1 + 0x254) = *(float *)(param_1 + 0x254) * _4949;
    *(undefined2 *)(param_1 + 0x308) = 0x1e;
    local_24.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    local_24.mTriIdx = -1;
    local_24.mBgIndex = 0x100;
    local_24.mpBgW = (cBgW *)0x0;
    local_24.mProcID = -1;
    cVar6 = dBgS_Acch::GetOnePolyInfo((dBgS_Acch *)(param_1 + 0x2574),&local_24);
    if (cVar6 != '\0') {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_a_himo2.cpp",0x621,"flag == 0");
      m_Do_printf::OSPanic("d_a_himo2.cpp",0x621,&DAT_8035be48);
    }
    uVar3 = dBgS::GetMtrlSndId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&local_24);
    sVar7 = d_com_inf_game::dComIfGp_getReverb((int)*(char *)(param_1 + 0x20a));
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x2803,(cXyz *)(param_1 + 0x1f8),uVar3,sVar7,_4333,_4333,_4949
               ,_4949,0);
    iVar4 = dBgS::GetAttributeCode(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&local_24);
    if ((iVar4 == 2) || (iVar4 == 3)) {
      local_38.x = *(short *)(param_1 + 0x204);
      local_38.z = *(short *)(param_1 + 0x208);
      local_38.y = *(short *)(param_1 + 0x206) + -0x8000;
      sVar7 = d_com_inf_game::dComIfGp_getReverb((int)*(char *)(param_1 + 0x20a));
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x2834,(cXyz *)(param_1 + 0x260),0,sVar7,_4333,_4333,_4949,
                 _4949,0);
      if (iVar4 == 2) {
        pJVar5 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x2b,
                                    (cXyz *)(param_1 + 0x1f8),&local_38,(cXyz *)0x0,0xff,
                                    (dPa_levelEcallBack *)0x0,-1,(_GXColor *)(param_1 + 0x194),
                                    (_GXColor *)(param_1 + 0x194),(cXyz *)0x0);
        if (pJVar5 != (JPABaseEmitter *)0x0) {
          pJVar5->mSpread = _4346;
          pJVar5->mVolumeSweep = _5042;
        }
      }
      else {
        local_38.x = local_38.x + 0x4000;
        pJVar5 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x2c,
                                    (cXyz *)(param_1 + 0x1f8),&local_38,(cXyz *)0x0,0xff,
                                    (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                                    (cXyz *)0x0);
        if (pJVar5 != (JPABaseEmitter *)0x0) {
          pJVar5->mInitialVelAxis = _4340;
        }
        local_30.x = *(float *)(param_1 + 0x1f8);
        local_30.y = *(float *)(param_1 + 0x1fc);
        local_30.z = *(float *)(param_1 + 0x200);
        if (param_1 == 0) {
          uVar2 = 0xffffffff;
        }
        else {
          uVar2 = *(uint *)(param_1 + 4);
        }
        d_kankyo::dKy_Sound_set(&local_30,100,uVar2,5);
      }
      if (pJVar5 != (JPABaseEmitter *)0x0) {
        pJVar5->mRate = _4332;
        pJVar5->mMaxFrame = 1;
      }
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* __stdcall pl_pos_add(himo2_class *) */

void pl_pos_add(int param_1)

{
  cXyz local_28;
  cXyz local_1c [2];
  
  ::cXyz::operator__(&local_28,
                     &((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.
                      mNext.mPos,
                     &((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.
                      mCurrent.mPos);
  local_1c[0].x = local_28.x;
  local_1c[0].y = local_28.y;
  local_1c[0].z = local_28.z;
  mtx::PSVECAdd((cXyz *)(param_1 + 0x1f8),local_1c,(cXyz *)(param_1 + 0x1f8));
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x800f0010) */
/* WARNING: Removing unreachable block (ram,0x800f0000) */
/* WARNING: Removing unreachable block (ram,0x800efff0) */
/* WARNING: Removing unreachable block (ram,0x800efff8) */
/* WARNING: Removing unreachable block (ram,0x800f0008) */
/* WARNING: Removing unreachable block (ram,0x800f0018) */
/* WARNING: Type propagation algorithm not settling */
/* __stdcall new_himo2_move(himo2_class *) */

void new_himo2_move(fopAc_ac_c *param_1)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  node_class *pnVar6;
  daPy_py_c *this;
  int iVar7;
  dAttention_c *this_00;
  uint uVar8;
  uint uVar9;
  daPy_py_c *this_01;
  int iVar10;
  short sVar17;
  int iVar11;
  undefined4 uVar12;
  char *pcVar13;
  daYkgr_c *pdVar14;
  std *psVar15;
  char cVar18;
  cXyz *pcVar16;
  int __x;
  fopAc_ac_c *pfVar19;
  undefined **ppuVar20;
  undefined4 uVar21;
  undefined8 in_f26;
  double dVar22;
  double dVar23;
  double dVar24;
  undefined8 in_f27;
  double dVar25;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar26;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar27;
  undefined *puVar28;
  float fVar29;
  undefined4 local_238;
  undefined4 local_234;
  cXyz cStack560;
  cXyz cStack548;
  cXyz cStack536;
  cXyz cStack524;
  cXyz cStack512;
  cXyz cStack500;
  cXyz cStack488;
  cXyz cStack476;
  cXyz cStack464;
  cXyz cStack452;
  cXyz cStack440;
  cXyz cStack428;
  cXyz cStack416;
  cXyz cStack404;
  cXyz local_188;
  cXyz local_17c;
  cXyz local_170;
  cXyz local_164;
  cXyz cStack344;
  cXyz cStack332;
  cXyz local_140;
  cXyz local_134;
  cXyz cStack296;
  cXyz local_11c;
  cXyz local_110;
  dBgS_LinChk dStack260;
  longlong local_98;
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar21 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  this = (daPy_py_c *)dComIfGp_getPlayer(0);
  dComIfGp_getPlayerCameraID(0);
  iVar7 = dComIfGp_getCamera();
  ::cXyz::cXyz(&local_140,(cXyz *)&param_1[1].parent.parent.mDtTg.parent.mbAdded);
  pcVar16 = &cStack332;
  ::cXyz::cXyz(pcVar16,(cXyz *)&param_1[1].parent.parent.mPi);
  fVar29 = (param_1->mCurrent).mPos.x - local_140.x;
  fVar1 = (param_1->mCurrent).mPos.y - local_140.y;
  fVar2 = (param_1->mCurrent).mPos.z - local_140.z;
  puVar28 = (undefined *)
            ::std::sqrtf((std *)pcVar16,fVar2 * fVar2 + fVar29 * fVar29 + fVar1 * fVar1);
  param_1[0xd].parent.parent.mLnTg.parent.parent.mpData = puVar28;
  sVar17 = *(short *)&param_1[1].parent.parent.mPi.parent.mbAdded;
  if (sVar17 != 0) {
    *(short *)&param_1[1].parent.parent.mPi.parent.mbAdded = sVar17 + -1;
  }
  sVar17 = *(short *)((int)&param_1[1].parent.parent.mpProf + 2);
  if (sVar17 != 0) {
    *(short *)((int)&param_1[1].parent.parent.mpProf + 2) = sVar17 + -1;
  }
  sVar17 = *(short *)&param_1[1].parent.parent.mInitState;
  if (sVar17 != 0) {
    *(short *)&param_1[1].parent.parent.mInitState = sVar17 + -1;
  }
  sVar17 = param_1[1].parent.parent.mBsTypeId;
  if (sVar17 != 0) {
    param_1[1].parent.parent.mBsTypeId = sVar17 + -1;
  }
  sVar17 = *(short *)&param_1[1].parent.parent.mpProf;
  if (sVar17 != 0) {
    *(short *)&param_1[1].parent.parent.mpProf = sVar17 + -1;
  }
  this_00 = (dAttention_c *)dComIfGp_getAttention();
  uVar8 = ::dAttention_c::Lockon(this_00);
  uVar8 = countLeadingZeros(uVar8 & 0xff);
  uVar8 = uVar8 >> 5 & 0xff;
  if (uVar8 == 0) {
    rope_scale = DAT_803e4230;
    param_1[1].parent.parent.mBsTypeId = 0;
  }
  else {
    rope_scale = DAT_803e4234;
  }
  bVar4 = false;
  bVar5 = false;
  bVar3 = false;
  pfVar19 = (fopAc_ac_c *)0x0;
  uVar9 = ::dAttention_c::LockonTruth(this_00);
  if (((uVar9 & 0xff) != 0) &&
     (pfVar19 = ::dAttention_c::LockonTarget(this_00,0), pfVar19 != (fopAc_ac_c *)0x0)) {
    ::cXyz::operator__((cXyz *)&param_1[0xe].mTevStr.mLightObj.field_0x38,&pfVar19->mEyePos);
    bVar4 = true;
  }
  if ((param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode != (node_class *)0x0) &&
     (*(char *)((int)&param_1[0xe].mEvtInfo.mCommand + 1) < '\x03')) {
    this_01 = (daPy_py_c *)daPy_getPlayerLinkActorClass();
    iVar10 = ::daPy_py_c::checkRopeForceEnd(this_01);
    if ((iVar10 != 0) &&
       (iVar10 = ::dEvt_info_c::checkCommandDemoAccrpt(&param_1->mEvtInfo), iVar10 == 0)) {
      *(undefined *)((int)&param_1[0xe].mEvtInfo.mCommand + 1) = 0;
      *(undefined *)&param_1[0xe].mEvtInfo.mCommand = 0;
      fopAcM_SetParam(param_1,0);
      *(undefined2 *)&param_1[1].parent.parent.mPi.parent.mbAdded = 0x1e;
      if (param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode == (node_class *)0xb) {
        fopAcM_seStart(param_1,0x2821,0);
        param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode = (node_class *)0x0;
      }
      else {
        param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode = (node_class *)0x9;
      }
      if ((param_1[0xd].parent.parent.mLyTg.mpLayer != (layer_class *)0x0) &&
         (sVar17 = fopAcM_GetName(), sVar17 == 0xfc)) {
        *(undefined *)((int)&param_1[0xd].parent.parent.mLyTg.mpLayer[0xe].mCancelList.mpHead + 1) =
             0;
      }
      param_1[0xd].parent.parent.mLyTg.mpLayer = (layer_class *)0x0;
    }
  }
  switch(param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode) {
  case (node_class *)0x0:
    param_1->mVelocityFwd = _4343;
    if ((uVar8 == 0) &&
       (iVar10 = (*(code *)this[1].parent.parent.parent.mLyTg.parent.parent.mpPrevNode[8].mpNextNode
                 )(this), iVar10 != 0)) {
      m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)(this->parent).mCollisionRot.y);
      m_Do_mtx::mDoMtx_ZrotM(SComponent::calc_mtx,d_s_play::g_regHIO.mChild[0].mShorts[2] + -12000);
      m_Do_mtx::mDoMtx_YrotM
                (SComponent::calc_mtx,
                 (short)param_1[1].parent.parent.mLnTg.mLineListID *
                 (d_s_play::g_regHIO.mChild[0].mShorts[3] + 0x2000));
      local_110.x = _4343;
      local_110.y = _4343;
      local_110.z = _5528 + d_s_play::g_regHIO.mChild[0].mFloats[11];
      SComponent::MtxPosition(&local_110,&(param_1->mCurrent).mPos);
      ::cXyz::operator___(&(param_1->mCurrent).mPos,(Vec *)&local_140);
      param_1[1].parent.parent.mLnTg.parent.parent.mpNextNode =
           (node_class *)(d_s_play::g_regHIO.mChild[0].mShorts[5] + 0x60);
      if ((param_1[1].parent.parent.mLnTg.mLineListID & 7U) == 0) {
        fopAcM_seStart(param_1,0x2818,0);
      }
    }
    else {
      iVar10 = (int)((float)param_1[0xd].parent.parent.mLnTg.parent.parent.mpData *
                    (_5529 + d_s_play::g_regHIO.mChild[0].mFloats[3]));
      local_98 = (longlong)iVar10;
      param_1[1].parent.parent.mLnTg.parent.parent.mpNextNode = (node_class *)(0x61 - iVar10);
      SComponent::cLib_addCalc2
                ((float *)&param_1->mCurrent,local_140.x,_4333,
                 _5530 * param_1[0xe].mTevStr.mLightObj.mDir.z);
      SComponent::cLib_addCalc2
                (&(param_1->mCurrent).mPos.y,local_140.y,_4333,
                 _5530 * param_1[0xe].mTevStr.mLightObj.mDir.z);
      SComponent::cLib_addCalc2
                (&(param_1->mCurrent).mPos.z,local_140.z,_4333,
                 _5530 * param_1[0xe].mTevStr.mLightObj.mDir.z);
      SComponent::cLib_addCalc2(&param_1[0xe].mTevStr.mLightObj.mDir.z,_4333,_4333,_5531);
      ::cXyz::operator__(&cStack404,&(param_1->mCurrent).mPos,&local_140);
      dVar23 = (double)::cXyz::operator__(&local_110,&cStack404);
      iVar10 = -1;
      ::cXyz::_cXyz(&cStack404);
      ::cXyz::abs(&local_110,iVar10);
      if ((double)_5532 < dVar23) {
        fopAcM_seStart(this,0x201f,0);
      }
    }
    iVar10 = fopAcM_GetParam(param_1);
    fVar29 = _4343;
    if (iVar10 == 1) {
      param_1[0xe].mTevStr.mLightObj.mDir.z = _4343;
      param_1[1].parent.parent.mDtTg.parent.parent.mpNextNode = (node_class *)fVar29;
      *(short *)&param_1[1].parent.parent.mPi.parent.mbAdded =
           d_s_play::g_regHIO.mChild[0].mShorts[2] + 0x28;
      param_1[1].parent.parent.mBsTypeId = 0;
      *(short *)&param_1[1].parent.parent.mpProf = d_s_play::g_regHIO.mChild[0].mShorts[9] + 10;
      *(undefined2 *)((int)&param_1[1].parent.parent.mpProf + 2) = 3;
      iVar10 = dComIfGp_getCamera(0);
      dVar22 = (double)(*(float *)&param_1[0xe].mTevStr.mLightObj.field_0x38 -
                       *(float *)(iVar10 + 0xd8));
      dVar24 = (double)(*(float *)&param_1[0xe].mTevStr.mLightObj.field_0x3c -
                       *(float *)(iVar10 + 0xdc));
      dVar23 = (double)(*(float *)&param_1[0xe].mTevStr.mLightObj.field_0x40 -
                       *(float *)(iVar10 + 0xe0));
      local_110.z = _5533 + _4915 * d_s_play::g_regHIO.mChild[0].mFloats[15];
      dVar25 = (double)(float)(dVar23 * dVar23);
      dVar26 = (double)(float)(dVar22 * dVar22);
      fVar29 = ::std::sqrtf((std *)&d_s_play::g_regHIO,
                            (float)(dVar25 + (double)(float)(dVar26 + (double)(float)(dVar24 * 
                                                  dVar24))));
      if (local_110.z < fVar29) {
        psVar15 = (std *)SComponent::cM_atan2s((float)dVar22,(float)dVar23);
        fVar29 = ::std::sqrtf(psVar15,(float)(dVar26 + dVar25));
        iVar11 = SComponent::cM_atan2s((float)dVar24,fVar29);
        m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)(short)psVar15);
        m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,-(short)iVar11);
        local_110.x = _4343;
        local_110.y = _4343;
        SComponent::MtxPosition(&local_110,&local_11c);
        *(float *)&param_1[0xe].mTevStr.mLightObj.field_0x38 =
             *(float *)(iVar10 + 0xd8) + local_11c.x;
        *(float *)&param_1[0xe].mTevStr.mLightObj.field_0x3c =
             *(float *)(iVar10 + 0xdc) + local_11c.y;
        *(float *)&param_1[0xe].mTevStr.mLightObj.field_0x40 =
             *(float *)(iVar10 + 0xe0) + local_11c.z;
      }
      ppuVar20 = &param_1[1].parent.parent.mPi.mMtdTg.parent.parent.mpData;
      if (uVar8 == 0) {
        param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode = (node_class *)0x1;
        *(short *)&param_1[1].parent.parent.mPi.parent.mbAdded =
             d_s_play::g_regHIO.mChild[0].mShorts[4] + 2;
        *(float *)&param_1[0xe].mTevStr.mLightObj.field_0x44 = _4729;
        param_1[1].parent.parent.mLnTg.parent.parent.mpNextNode =
             (node_class *)(d_s_play::g_regHIO.mChild[0].mShorts[6] + 0x5a);
        ::cXyz::operator__(&(param_1->mCurrent).mPos,&local_140);
        iVar10 = 0;
        do {
          ::cXyz::operator__((cXyz *)(ppuVar20 + 4),&local_140);
          iVar10 = iVar10 + 1;
          ppuVar20 = ppuVar20 + 9;
        } while (iVar10 < 100);
      }
      else {
        param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode = (node_class *)0x2;
        *(float *)&param_1[0xe].mTevStr.mLightObj.field_0x44 = _4729;
        param_1[1].parent.parent.mLnTg.parent.parent.mpNextNode =
             (node_class *)(d_s_play::g_regHIO.mChild[0].mShorts[6] + 0x5a);
        ::cXyz::operator__(&(param_1->mCurrent).mPos,&local_140);
        iVar10 = 0;
        do {
          ::cXyz::operator__((cXyz *)(ppuVar20 + 4),&local_140);
          iVar10 = iVar10 + 1;
          ppuVar20 = ppuVar20 + 9;
        } while (iVar10 < 100);
      }
    }
    break;
  case (node_class *)0x1:
    m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)(this->parent).mCollisionRot.y);
    m_Do_mtx::mDoMtx_ZrotM(SComponent::calc_mtx,d_s_play::g_regHIO.mChild[0].mShorts[2] + -12000);
    m_Do_mtx::mDoMtx_YrotM
              (SComponent::calc_mtx,
               (short)param_1[1].parent.parent.mLnTg.mLineListID *
               (d_s_play::g_regHIO.mChild[0].mShorts[3] + 0x2000));
    local_110.x = _4343;
    local_110.y = _4343;
    local_110.z = _5528 + d_s_play::g_regHIO.mChild[0].mFloats[11];
    SComponent::MtxPosition(&local_110,&(param_1->mCurrent).mPos);
    ::cXyz::operator___(&(param_1->mCurrent).mPos,(Vec *)&local_140);
    param_1[1].parent.parent.mLnTg.parent.parent.mpNextNode =
         (node_class *)(d_s_play::g_regHIO.mChild[0].mShorts[5] + 0x60);
    if ((param_1[1].parent.parent.mLnTg.mLineListID & 7U) == 0) {
      fopAcM_seStart(param_1,0x2842,0);
    }
    sVar17 = (short)param_1[1].parent.parent.mLnTg.mLineListID *
             (d_s_play::g_regHIO.mChild[0].mShorts[3] + 0x2000);
    if (((short)(d_s_play::g_regHIO.mChild[0].mShorts[7] + -20000) <= sVar17) &&
       (sVar17 < (short)(d_s_play::g_regHIO.mChild[0].mShorts[7] + -0x2e20))) {
      bVar3 = true;
    }
    if ((*(short *)&param_1[1].parent.parent.mPi.parent.mbAdded == 0) && (bVar3)) {
      param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode = (node_class *)0x3;
      if (bVar4) {
        *(short *)&param_1[1].parent.parent.mPi.parent.mbAdded =
             d_s_play::g_regHIO.mChild[0].mShorts[4] + 0x46;
        param_1[0xd].parent.parent.mLyTg.mpLayer = (layer_class *)pfVar19;
        uVar12 = fopAcM_GetID(pfVar19);
        *(undefined4 *)&param_1[0xd].parent.parent.mLyTg.mNodeListID = uVar12;
      }
      else {
        *(short *)&param_1[1].parent.parent.mPi.parent.mbAdded =
             d_s_play::g_regHIO.mChild[0].mShorts[2] + 0x14;
        *(undefined4 *)&param_1[0xd].parent.parent.mLyTg.mNodeListID = 0xffffffff;
      }
      ::cXyz::operator__(&cStack416,(cXyz *)&param_1[0xe].mTevStr.mLightObj.field_0x38,
                         &(param_1->mCurrent).mPos);
      ::cXyz::operator__(&local_110,&cStack416);
      ::cXyz::_cXyz(&cStack416);
      psVar15 = (std *)SComponent::cM_atan2s(local_110.x,local_110.z);
      (param_1->mCurrent).mRot.y = (short)psVar15;
      fVar29 = ::std::sqrtf(psVar15,local_110.x * local_110.x + local_110.z * local_110.z);
      iVar10 = SComponent::cM_atan2s(local_110.y,fVar29);
      (param_1->mCurrent).mRot.x = -(short)iVar10;
      fopAcM_seStart(param_1,0x2817,0);
    }
    break;
  case (node_class *)0x2:
    param_1[1].parent.parent.mLnTg.parent.parent.mpNextNode =
         (node_class *)(int)d_s_play::g_regHIO.mChild[0].mShorts[0];
    if (param_1[0xd].parent.parent.mLyTg.mpLayer == (layer_class *)0x0) {
      psVar15 = (std *)::cXyz::operator__(&local_134,
                                          (cXyz *)&param_1[0xe].mTevStr.mLightObj.field_0x38);
    }
    else {
      uVar8 = fopAcM_GetParam();
      if (((uVar8 & 0xf0) == 0) &&
         (uVar8 = fopAcM_GetParam(param_1[0xd].parent.parent.mLyTg.mpLayer), (uVar8 & 0xf) != 3)) {
        ::cXyz::operator__(&local_134,(cXyz *)&param_1[0xe].mTevStr.mLightObj.field_0x38);
      }
      else {
        ::cXyz::operator__(&local_134,
                           (cXyz *)&param_1[0xd].parent.parent.mLyTg.mpLayer[0xb].mNodeListTree.
                                    mNumLists);
      }
      m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)(param_1->mCurrent).mRot.y);
      m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,(param_1->mCurrent).mRot.x);
      local_110.y = _4343;
      local_110.x = _4343;
      local_110.z = _4915 + _4915 * d_s_play::g_regHIO.mChild[0].mFloats[14];
      psVar15 = (std *)SComponent::MtxPosition(&local_110,&local_11c);
      local_134.x = local_134.x + local_11c.x;
      local_134.y = local_134.y + local_11c.y;
      local_134.z = local_134.z + local_11c.z;
    }
    dVar27 = (double)(local_134.x - (param_1->mCurrent).mPos.x);
    dVar25 = (double)(local_134.y - (param_1->mCurrent).mPos.y);
    dVar22 = (double)(local_134.z - (param_1->mCurrent).mPos.z);
    dVar26 = (double)(float)(dVar22 * dVar22);
    dVar24 = (double)(float)(dVar27 * dVar27);
    fVar29 = ::std::sqrtf(psVar15,(float)(dVar26 + (double)(float)(dVar24 + (double)(float)(dVar25 *
                                                                                           dVar25)))
                         );
    dVar23 = (double)fVar29;
    fVar29 = ::std::sqrtf(psVar15,(float)(dVar24 + dVar26));
    dVar24 = (double)fVar29;
    iVar10 = (int)(dVar23 * (double)(_5534 + d_s_play::g_regHIO.mChild[0].mFloats[3]));
    local_98 = (longlong)iVar10;
    sVar17 = (short)iVar10;
    if (sVar17 < (short)(d_s_play::g_regHIO.mChild[0].mShorts[2] + -3000)) {
      sVar17 = d_s_play::g_regHIO.mChild[0].mShorts[2] + -3000;
    }
    if ((param_1[0xd].parent.parent.mLyTg.mpLayer != (layer_class *)0x0) ||
       ((double)(_4339 * param_1->mVelocityFwd) < dVar23)) {
      iVar10 = SComponent::cM_atan2s((float)dVar27,(float)dVar22);
      (param_1->mCurrent).mRot.y = (short)iVar10;
      iVar10 = SComponent::cM_atan2s((float)dVar25,(float)dVar24);
      (param_1->mCurrent).mRot.x = -(short)iVar10;
    }
    param_1->mVelocityFwd = _5535;
    m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)(param_1->mCurrent).mRot.y);
    m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,(param_1->mCurrent).mRot.x + sVar17);
    local_110.y = _4343;
    local_110.x = _4343;
    local_110.z = param_1->mVelocityFwd;
    SComponent::MtxPosition(&local_110,&param_1->mVelocity);
    ::cXyz::operator___(&(param_1->mCurrent).mPos,(Vec *)&param_1->mVelocity);
    pl_pos_add(param_1);
    if (param_1[0xd].parent.parent.mLyTg.mpLayer == (layer_class *)0x0) {
      iVar10 = himo2_bg_check(param_1);
      if (iVar10 == 0) {
        if ((*(short *)((int)&param_1[1].parent.parent.mpProf + 2) == 0) &&
           (iVar10 = dCcD_GObjInf::ChkAtHit((dCcD_GObjInf *)&param_1[0xc].mTevStr.mColorC0.b),
           iVar10 != 0)) {
          param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode = (node_class *)0x9;
          param_1->mVelocityFwd = param_1->mVelocityFwd * _4949;
          *(undefined2 *)&param_1[1].parent.parent.mPi.parent.mbAdded = 0x28;
        }
        else {
          if (*(short *)&param_1[1].parent.parent.mPi.parent.mbAdded != 0) goto LAB_800ee264;
          param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode = (node_class *)0x8;
          *(undefined2 *)&param_1[1].parent.parent.mPi.parent.mbAdded = 0x32;
          fopAcM_seStart(param_1,0x2820,0);
        }
      }
    }
    else {
      if ((dVar23 < (double)(_4339 * param_1->mVelocityFwd)) ||
         (*(short *)&param_1[1].parent.parent.mPi.parent.mbAdded == 0)) {
        param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode = (node_class *)0xa;
        *(undefined *)((int)&param_1[0xe].mEvtInfo.mCommand + 1) = 0xff;
        *(undefined *)&param_1[0xe].mEvtInfo.mCommand = 1;
        if (btd != 0) {
          fopAcM_OffStatus(btd,0x4000);
        }
      }
      else {
        if ((*(short *)((int)&param_1[1].parent.parent.mpProf + 2) == 0) &&
           (iVar10 = dCcD_GObjInf::ChkAtHit((dCcD_GObjInf *)&param_1[0xc].mTevStr.mColorC0.b),
           iVar10 != 0)) {
          param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode = (node_class *)0x9;
          param_1->mVelocityFwd = param_1->mVelocityFwd * _4949;
          *(undefined2 *)&param_1[1].parent.parent.mPi.parent.mbAdded = 0x28;
          param_1[0xd].parent.parent.mLyTg.mpLayer = (layer_class *)0x0;
        }
        else {
LAB_800ee264:
          if ((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 6 & 1) != 0) ||
              (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) != 0 ||
               ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 3 & 1) != 0)))) &&
             (*(short *)&param_1[1].parent.parent.mpProf == 0)) {
            param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode = (node_class *)0x8;
            *(undefined2 *)&param_1[1].parent.parent.mPi.parent.mbAdded = 0x28;
            fopAcM_seStart(param_1,0x2820,0);
            param_1[0xd].parent.parent.mLyTg.mpLayer = (layer_class *)0x0;
          }
        }
      }
    }
    break;
  case (node_class *)0x3:
    param_1[1].parent.parent.mLnTg.parent.parent.mpNextNode =
         (node_class *)(int)d_s_play::g_regHIO.mChild[0].mShorts[0];
    local_234 = *(undefined4 *)&param_1[0xd].parent.parent.mLyTg.mNodeListID;
    pfVar19 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_234);
    if (pfVar19 != (fopAc_ac_c *)0x0) {
      ::cXyz::operator__(&cStack428,&pfVar19->mEyePos,&(param_1->mCurrent).mPos);
      ::cXyz::operator__(&local_110,&cStack428);
      ::cXyz::_cXyz(&cStack428);
      iVar10 = SComponent::cM_atan2s(local_110.x,local_110.z);
      psVar15 = (std *)SComponent::cLib_addCalcAngleS2
                                 (&(param_1->mCurrent).mRot.y,(short)iVar10,2,
                                  d_s_play::g_regHIO.mChild[0].mShorts[1] + 0x800);
      fVar29 = ::std::sqrtf(psVar15,local_110.x * local_110.x + local_110.z * local_110.z);
      iVar10 = SComponent::cM_atan2s(local_110.y,fVar29);
      dVar23 = (double)SComponent::cLib_addCalcAngleS2
                                 (&(param_1->mCurrent).mRot.x,-(short)iVar10,2,
                                  d_s_play::g_regHIO.mChild[0].mShorts[1] + 0x800);
      ::cXyz::abs(&local_110,__x);
      if (dVar23 < (double)(_4492 + d_s_play::g_regHIO.mChild[0].mFloats[3])) {
        bVar5 = true;
      }
    }
    param_1->mVelocityFwd = _5536 + d_s_play::g_regHIO.mChild[0].mFloats[14];
    m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)(param_1->mCurrent).mRot.y);
    m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,(param_1->mCurrent).mRot.x);
    local_110.y = _4343;
    local_110.x = _4343;
    local_110.z = param_1->mVelocityFwd;
    SComponent::MtxPosition(&local_110,&param_1->mVelocity);
    ::cXyz::operator___(&(param_1->mCurrent).mPos,(Vec *)&param_1->mVelocity);
    pl_pos_add(param_1);
    iVar10 = himo2_bg_check(param_1);
    if (iVar10 != 0) {
      bVar5 = true;
      param_1[0xe].mTevStr.mLightObj.mDir.z = _4727;
    }
    if ((*(short *)((int)&param_1[1].parent.parent.mpProf + 2) == 0) &&
       (iVar10 = dCcD_GObjInf::ChkAtHit((dCcD_GObjInf *)&param_1[0xc].mTevStr.mColorC0.b),
       iVar10 != 0)) {
      bVar5 = true;
      param_1[0xe].mTevStr.mLightObj.mDir.z = _4727;
    }
    if (*(short *)&param_1[1].parent.parent.mPi.parent.mbAdded == 0) {
      bVar5 = true;
      param_1[0xe].mTevStr.mLightObj.mDir.z = _5537;
    }
    if ((((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 6 & 1) != 0) ||
          ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) != 0)) ||
         ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 3 & 1) != 0)) &&
        (*(short *)&param_1[1].parent.parent.mpProf == 0)) || (bVar5)) {
      param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode = (node_class *)0x5;
    }
    break;
  case (node_class *)0x4:
    local_238 = *(undefined4 *)&param_1[0xd].parent.parent.mLyTg.mNodeListID;
    pfVar19 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_238);
    if (pfVar19 == (fopAc_ac_c *)0x0) {
      param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode = (node_class *)0x5;
    }
    else {
      m_Do_mtx::mDoMtx_YrotS
                (SComponent::calc_mtx,
                 (int)(short)(param_1[1].parent.parent.mLnTg.mLineListID << 0xd));
      local_110.x = _4343;
      local_110.y = _4343;
      local_110.z = (float)param_1[0xd].parent.parent.mLnTg.parent.parent.mpPrevNode;
      SComponent::MtxPosition(&local_110,&local_11c);
      ::cXyz::operator__(&cStack440,&pfVar19->mEyePos,&local_11c);
      ::cXyz::operator__(&(param_1->mCurrent).mPos,&cStack440);
      ::cXyz::_cXyz(&cStack440);
      SComponent::cLib_addCalc0((float *)&param_1[0xd].parent.parent.mLnTg,_4333,_5532);
      if ((float)param_1[0xd].parent.parent.mLnTg.parent.parent.mpPrevNode < _4727) {
        fopAcM_SetParam(param_1,0);
      }
      iVar10 = (int)((float)param_1[0xd].parent.parent.mLnTg.parent.parent.mpData *
                    (_5529 + d_s_play::g_regHIO.mChild[0].mFloats[5]));
      local_98 = (longlong)iVar10;
      pnVar6 = (node_class *)(0x61 - iVar10);
      if (((int)pnVar6 < (int)param_1[1].parent.parent.mLnTg.parent.parent.mpNextNode) ||
         ((float)param_1[0xd].parent.parent.mLnTg.parent.parent.mpPrevNode < _4727)) {
        param_1[1].parent.parent.mLnTg.parent.parent.mpNextNode = pnVar6;
      }
      if ((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 6 & 1) != 0) ||
          ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) != 0)) ||
         ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 3 & 1) != 0)) {
        param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode = (node_class *)0x5;
        sVar17 = fopAcM_GetName(pfVar19);
        if (sVar17 == 0xbe) {
          *(undefined2 *)((int)&pfVar19[1].mDwTg.mpTagData + 2) = 0;
          *(undefined2 *)&pfVar19[1].mDwTg.mpTagData = 0;
        }
      }
    }
    param_1[1].parent.parent.mDtTg.parent.parent.mpNextNode = (node_class *)_5534;
    break;
  case (node_class *)0x5:
    param_1[1].parent.parent.mLnTg.parent.parent.mpNextNode =
         (node_class *)(int)d_s_play::g_regHIO.mChild[0].mShorts[0];
    SComponent::cLib_addCalc2
              ((float *)&param_1->mCurrent,local_140.x,_4333,
               (_5538 + d_s_play::g_regHIO.mChild[0].mFloats[15]) *
               param_1[0xe].mTevStr.mLightObj.mDir.z);
    SComponent::cLib_addCalc2
              (&(param_1->mCurrent).mPos.y,local_140.y,_4333,
               (_5538 + d_s_play::g_regHIO.mChild[0].mFloats[15]) *
               param_1[0xe].mTevStr.mLightObj.mDir.z);
    SComponent::cLib_addCalc2
              (&(param_1->mCurrent).mPos.z,local_140.z,_4333,
               (_5538 + d_s_play::g_regHIO.mChild[0].mFloats[15]) *
               param_1[0xe].mTevStr.mLightObj.mDir.z);
    SComponent::cLib_addCalc2(&param_1[0xe].mTevStr.mLightObj.mDir.z,_4333,_4333,_4450);
    pl_pos_add(param_1);
    ::cXyz::operator__(&cStack452,&(param_1->mCurrent).mPos,&local_140);
    dVar23 = (double)::cXyz::operator__(&local_110,&cStack452);
    iVar10 = -1;
    ::cXyz::_cXyz(&cStack452);
    ::cXyz::abs(&local_110,iVar10);
    if (dVar23 <= (double)_5532) {
      fopAcM_SetParam(param_1,0);
      fopAcM_seStart(param_1,0x2821,0);
      param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode = (node_class *)0x0;
      param_1[0xd].parent.parent.mLyTg.mpLayer = (layer_class *)0x0;
      *(undefined *)&param_1[0xe].mEvtInfo.mCommand = 0;
    }
    else {
      fopAcM_seStart(this,0x201f,0);
    }
    break;
  case (node_class *)0x8:
    SComponent::cLib_addCalc2(&param_1->mVelocityFwd,_5539,_4333,_5540);
  case (node_class *)0x9:
    SComponent::cLib_addCalc2
              ((float *)&param_1->mCurrent,local_140.x,_4333,
               (_5538 + d_s_play::g_regHIO.mChild[0].mFloats[15]) *
               param_1[0xe].mTevStr.mLightObj.mDir.z);
    SComponent::cLib_addCalc2
              (&(param_1->mCurrent).mPos.y,local_140.y,_4333,
               (_5538 + d_s_play::g_regHIO.mChild[0].mFloats[15]) *
               param_1[0xe].mTevStr.mLightObj.mDir.z);
    SComponent::cLib_addCalc2
              (&(param_1->mCurrent).mPos.z,local_140.z,_4333,
               (_5538 + d_s_play::g_regHIO.mChild[0].mFloats[15]) *
               param_1[0xe].mTevStr.mLightObj.mDir.z);
    SComponent::cLib_addCalc2(&param_1[0xe].mTevStr.mLightObj.mDir.z,_4333,_4333,_4450);
    pl_pos_add(param_1);
    ::cXyz::operator__(&cStack464,&(param_1->mCurrent).mPos,&local_140);
    dVar23 = (double)::cXyz::operator__(&local_110,&cStack464);
    iVar10 = -1;
    ::cXyz::_cXyz(&cStack464);
    ::cXyz::abs(&local_110,iVar10);
    if (dVar23 <= (double)_5532) {
      fopAcM_SetParam(param_1,0);
      param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode = (node_class *)0x0;
      ::cXyz::operator__(&(param_1->mCurrent).mPos,&local_140);
      param_1[1].parent.parent.mBsTypeId = d_s_play::g_regHIO.mChild[0].mShorts[6] + 0x14;
    }
    else {
      fopAcM_seStart(this,0x201f,0);
    }
    param_1[1].parent.parent.mLnTg.parent.parent.mpNextNode =
         (node_class *)(int)d_s_play::g_regHIO.mChild[0].mShorts[0];
    break;
  case (node_class *)0xa:
    iVar10 = (int)((float)param_1[0xd].parent.parent.mLnTg.parent.parent.mpData *
                  (_5529 + d_s_play::g_regHIO.mChild[0].mFloats[1]));
    local_98 = (longlong)iVar10;
    param_1[1].parent.parent.mLnTg.parent.parent.mpNextNode = (node_class *)(100 - iVar10);
    ::cXyz::operator__(&(param_1->mCurrent).mPos,(cXyz *)&param_1[0xe].mTevStr.mLightObj.mColor);
    SComponent::cLib_addCalc2
              ((float *)&param_1[1].parent.parent.mDtTg.parent.parent.mpNextNode,_5541,_4333,_5542);
    iVar10 = fopAcM_GetParam(param_1);
    if (iVar10 == 3) {
      param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode = (node_class *)0xb;
      uVar8 = fopAcM_GetParam(param_1[0xd].parent.parent.mLyTg.mpLayer);
      if ((uVar8 & 0xf0) == 0) {
        dComIfGs_onEventBit(0x580);
      }
      else {
        dComIfGs_onEventBit(0x540);
      }
    }
    *(undefined *)((int)&param_1[0xd].parent.parent.mLyTg.mpLayer[0xe].mCancelList.mpHead + 1) = 1;
    goto LAB_800ee954;
  case (node_class *)0xb:
    ::cXyz::operator__(&(param_1->mCurrent).mPos,(cXyz *)&param_1[0xe].mTevStr.mLightObj.mColor);
    iVar10 = (int)((float)param_1[0xd].parent.parent.mLnTg.parent.parent.mpData *
                  (_5529 + d_s_play::g_regHIO.mChild[0].mFloats[2]));
    local_98 = (longlong)iVar10;
    param_1[1].parent.parent.mLnTg.parent.parent.mpNextNode = (node_class *)(100 - iVar10);
    *(undefined *)((int)&param_1[0xd].parent.parent.mLyTg.mpLayer[0xe].mCancelList.mpHead + 1) = 3;
LAB_800ee954:
    iVar10 = fopAcM_GetParam(param_1);
    if (iVar10 == 4) {
      fopAcM_SetParam(param_1,0);
      fopAcM_seStart(param_1,0x2821,0);
      param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode = (node_class *)0x0;
      *(undefined *)((int)&param_1[0xd].parent.parent.mLyTg.mpLayer[0xe].mCancelList.mpHead + 1) = 0
      ;
      param_1[0xd].parent.parent.mLyTg.mpLayer = (layer_class *)0x0;
      if (*(char *)((int)&param_1[0xe].mEvtInfo.mCommand + 1) != '\0') {
        *(undefined *)((int)&param_1[0xe].mEvtInfo.mCommand + 1) = 6;
        *(undefined2 *)&param_1[1].parent.parent.mInitState = 0x78;
      }
      *(undefined *)&param_1[0xe].mEvtInfo.mCommand = 0;
    }
  }
  dVar23 = (double)_4343;
  switch(*(undefined *)((int)&param_1[0xe].mEvtInfo.mCommand + 1)) {
  default:
    break;
  case 3:
    *(undefined *)((int)&param_1[0xd].parent.parent.mLyTg.mpLayer[0xe].mCancelList.mpHead + 1) = 2;
    m_Do_mtx::mDoMtx_YrotS
              (SComponent::calc_mtx,
               (int)*(short *)((int)&param_1[0xd].parent.parent.mLyTg.mpLayer[0xb].mCancelList.
                                     mpTail + 2));
    local_110.x = ((_4916 + d_s_play::g_regHIO.mChild[0].mFloats[11]) - _5555) - _4726;
    local_110.y = _4916 + (float)param_1[0xd].parent.parent.mLyTg.mpLayer[10].mCancelList.mpHead +
                          d_s_play::g_regHIO.mChild[0].mFloats[12];
    local_110.z = _5533 + d_s_play::g_regHIO.mChild[0].mFloats[13];
    SComponent::MtxPosition(&local_110,&local_11c);
    SComponent::cLib_addCalc2((float *)&param_1[0xe].mEvtInfo.mEventId,local_11c.x,_5551,_5530);
    SComponent::cLib_addCalc2((float *)&param_1[0xe].mEvtInfo.mpEventCB,local_11c.y,_5551,_5530);
    SComponent::cLib_addCalc2((float *)&param_1[0xe].mEvtInfo.mpCheckCB,local_11c.z,_5551,_5530);
    SComponent::cLib_addCalc2
              ((float *)&param_1[0xe].mTevStr,
               _5556 + (float)param_1[0xd].parent.parent.mLyTg.mpLayer[10].mCancelList.mpHead +
               d_s_play::g_regHIO.mChild[0].mFloats[14],_5551,_4915);
    SComponent::cLib_addCalc2
              (&param_1[0xe].mTevStr.mLightObj.mPos.z,
               _5553 + d_s_play::g_regHIO.mChild[0].mFloats[13],_4333,_5557);
    if (*(short *)&param_1[1].parent.parent.mInitState < 0x1e) {
      *(undefined *)(btd + 0x6e15) = 0xb4;
    }
    if (*(short *)&param_1[1].parent.parent.mInitState == 0x1e) {
      fopAcM_seStartCurrent(dr,0x5827,0);
    }
    pcVar13 = dComIfGp_getStartStageName();
    if (((*pcVar13 != 'X') && (*(short *)&param_1[1].parent.parent.mInitState < 2)) &&
       (iVar10 = dComIfGs_isEventBit(0x420), iVar10 == 0)) {
      d_kankyo::dKy_custom_colset(0,4,_4333);
    }
    if ((*(short *)&param_1[1].parent.parent.mInitState != 0) ||
       (d_s_play::g_regHIO.mChild[0].mShorts[8] != 0)) break;
    *(undefined *)(btd + 0x6e15) = 1;
    *(undefined *)((int)&param_1[0xe].mEvtInfo.mCommand + 1) = 4;
    pcVar13 = dComIfGp_getStartStageName();
    if ((*pcVar13 == 'X') || (iVar10 = dComIfGs_isEventBit(0x420), iVar10 != 0)) {
      *(undefined2 *)&param_1[1].parent.parent.mInitState = 0;
    }
    else {
      dComIfGs_onEventBit(0x420);
      pdVar14 = (daYkgr_c *)(int)d_s_play::g_regHIO.mChild[0].mShorts[2];
      *(short *)&param_1[1].parent.parent.mInitState =
           d_s_play::g_regHIO.mChild[0].mShorts[2] + 0x3e;
      ::daYkgr_c::hide(pdVar14);
    }
    *(undefined *)&param_1[1].parent.parent.mDtTg.parent.parent.mpData = 0;
    *(undefined *)((int)&param_1[0xd].parent.parent.mLyTg.mpLayer[0xe].mCancelList.mpHead + 1) = 0;
    if (btd != 0) {
      fopAcM_OnStatus(btd,0x4000);
    }
  case 4:
    d_kankyo::dKy_custom_colset(0,4,_4333);
    if (*(short *)&param_1[1].parent.parent.mInitState ==
        (short)(d_s_play::g_regHIO.mChild[0].mShorts[2] + 0x39)) {
      mDoAud_seStart(0x4841,0,0,0);
    }
    if (*(short *)&param_1[1].parent.parent.mInitState < 2) {
      d_kankyo::dKy_custom_colset(0,4,_4343);
    }
    if ((*(short *)&param_1[1].parent.parent.mInitState == 0) &&
       (d_s_play::g_regHIO.mChild[0].mShorts[8] == 0)) {
      *(undefined *)(dr + 0x50c) = 0;
      d_kankyo::dKy_custom_colset(0,4,_4343);
      *(undefined *)((int)&param_1[0xe].mEvtInfo.mCommand + 1) = 5;
      *(undefined2 *)&param_1[1].parent.parent.mInitState = 0x32;
      *(undefined *)&param_1[1].parent.parent.mDtTg.parent.parent.mpData = 0;
      fopAcM_SetParam(param_1,2);
      dComIfGp_event_reset();
      *(undefined2 *)&param_1[1].parent.parent.mpCtRq = 0x14;
      sVar17 = fopAcM_searchPlayerAngleY(param_1);
      *(short *)&param_1[0xe].mTevStr.mLightObj.mCosAtten.z = sVar17 + -0x8000;
      *(undefined2 *)((int)&param_1[0xe].mTevStr.mLightObj.mCosAtten.z + 2) =
           *(undefined2 *)&param_1[0xe].mTevStr.mLightObj.mCosAtten.z;
      fVar29 = _5558;
      param_1[0xe].mTevStr.mLightObj.mPos.z = _5558;
      param_1[0xe].mTevStr.mLightObj.mDir.x = fVar29;
      m_Do_mtx::mDoMtx_YrotS
                (SComponent::calc_mtx,(int)*(short *)&param_1[0xe].mTevStr.mLightObj.mCosAtten.z);
      local_110.x = _5530 + _4915 + d_s_play::g_regHIO.mChild[0].mFloats[7];
      local_110.y = _4950 + (this->parent).mCurrent.mPos.y + d_s_play::g_regHIO.mChild[0].mFloats[8]
      ;
      local_110.z = _5559 + d_s_play::g_regHIO.mChild[0].mFloats[9];
      SComponent::MtxPosition(&local_110,(cXyz *)&param_1[0xe].mEvtInfo.mEventId);
      fVar29 = _5560;
      *(float *)&param_1[0xe].mEvtInfo.mEventId =
           *(float *)&param_1[0xe].mEvtInfo.mEventId +
           (this->parent).mCurrent.mPos.x * (_5560 + d_s_play::g_regHIO.mChild[0].mFloats[15]);
      param_1[0xe].mEvtInfo.mpCheckCB =
           (undefined *)
           ((float)param_1[0xe].mEvtInfo.mpCheckCB +
           (this->parent).mCurrent.mPos.z * (fVar29 + d_s_play::g_regHIO.mChild[0].mFloats[15]));
      pdVar14 = (daYkgr_c *)
                ::cXyz::operator__((cXyz *)&param_1[0xe].mEvtInfo.mpPhotoCB,
                                   &(this->parent).mCurrent.mPos);
      param_1[0xe].mTevStr.mLightObj.mPos.x = param_1[0xe].mTevStr.mLightObj.mPos.x - _4492;
      ::daYkgr_c::show(pdVar14);
    }
    else {
      param_1[0xe].mTevStr.mLightObj.mPos.z = _4492 + d_s_play::g_regHIO.mChild[0].mFloats[12];
      *(undefined *)(dr + 0x50c) = 1;
      fVar1 = _5562;
      fVar29 = _4916;
      *(float *)&param_1[0xe].mEvtInfo.mEventId =
           _4916 + ((_5561 + d_s_play::g_regHIO.mChild[0].mFloats[14]) - _5562);
      fVar2 = _5563;
      param_1[0xe].mEvtInfo.mpEventCB =
           (undefined *)(_5563 + fVar29 + fVar1 + d_s_play::g_regHIO.mChild[0].mFloats[15]);
      param_1[0xe].mEvtInfo.mpCheckCB =
           (undefined *)((_5564 + d_s_play::g_regHIO.mChild[0].mFloats[16]) - fVar29);
      param_1[0xe].mEvtInfo.mpPhotoCB = (undefined *)d_s_play::g_regHIO.mChild[0].mFloats[17];
      param_1[0xe].mTevStr.mLightObj.mPos.x =
           (fVar2 + fVar29 + fVar1 + d_s_play::g_regHIO.mChild[0].mFloats[18]) - _4726;
      param_1[0xe].mTevStr.mLightObj.mPos.y = d_s_play::g_regHIO.mChild[0].mFloats[19];
    }
    break;
  case 5:
    if (*(short *)&param_1[1].parent.parent.mInitState == 0) {
      cVar18 = *(char *)&param_1[1].parent.parent.mDtTg.parent.parent.mpData;
      if (cVar18 == '\0') {
        mDoAud_seStart(0x483f,0,0,0);
      }
      else {
        if (cVar18 == '\x01') {
          mDoAud_seStart(0x4844,0,0,0);
        }
        else {
          if ('\x01' < cVar18) {
            mDoAud_seStart(0x4845,0,0,0);
            *(undefined *)&param_1[1].parent.parent.mDtTg.parent.parent.mpData = 2;
          }
        }
      }
      *(char *)&param_1[1].parent.parent.mDtTg.parent.parent.mpData =
           *(char *)&param_1[1].parent.parent.mDtTg.parent.parent.mpData + '\x01';
      *(undefined2 *)&param_1[1].parent.parent.mInitState = 0x32;
    }
    dVar23 = (double)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickCPosY;
    goto LAB_800ef4e4;
  case 6:
    iVar10 = ::daPy_py_c::getRopeJumpLand(this);
    if ((iVar10 != 0) || (*(short *)&param_1[1].parent.parent.mInitState == 0)) {
      *(undefined *)((int)&param_1[0xe].mEvtInfo.mCommand + 1) = 7;
      *(undefined2 *)&param_1[1].parent.parent.mInitState = 10;
      goto switchD_800ee9e4_caseD_7;
    }
    iVar10 = ::dEvt_info_c::checkCommandDemoAccrpt(&param_1->mEvtInfo);
    if (iVar10 == 0) {
      f_op_actor_mng::fopAcM_orderPotentialEvent(param_1,2,0xffff,0);
      ::dEvt_info_c::onCondition(&param_1->mEvtInfo,2);
    }
    *(undefined2 *)(dr + 0x4ca) = 0x5a;
    SComponent::cLib_addCalc2
              (&param_1[0xe].mTevStr.mLightObj.mDir.x,
               _5535 + d_s_play::g_regHIO.mChild[0].mFloats[8],_4333,
               _5557 + d_s_play::g_regHIO.mChild[0].mFloats[9]);
LAB_800ef4e4:
    iVar10 = (int)(m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickCPosX *
                  (_5533 + d_s_play::g_regHIO.mChild[0].mFloats[6]));
    local_98 = (longlong)iVar10;
    *(short *)((int)&param_1[0xe].mTevStr.mLightObj.mCosAtten.z + 2) =
         *(short *)((int)&param_1[0xe].mTevStr.mLightObj.mCosAtten.z + 2) + (short)iVar10;
    psVar15 = (std *)SComponent::cLib_addCalcAngleS2
                               ((short *)&param_1[0xe].mTevStr.mLightObj.mCosAtten.z,
                                *(short *)((int)&param_1[0xe].mTevStr.mLightObj.mCosAtten.z + 2),4,
                                0x1000);
    if ((double)_5565 < dVar23) {
      if ((double)_4727 <= dVar23) {
        fVar29 = ::std::fabsf(psVar15,(float)dVar23);
        SComponent::cLib_addCalc2
                  (&param_1[0xe].mTevStr.mLightObj.mDir.x,
                   _5535 + d_s_play::g_regHIO.mChild[0].mFloats[8],_4333,_4337 * fVar29);
      }
    }
    else {
      fVar29 = ::std::fabsf(psVar15,(float)dVar23);
      SComponent::cLib_addCalc2
                (&param_1[0xe].mTevStr.mLightObj.mDir.x,
                 _5528 + d_s_play::g_regHIO.mChild[0].mFloats[7],_4333,_4337 * fVar29);
    }
    SComponent::cLib_addCalc2
              (&param_1[0xe].mTevStr.mLightObj.mPos.z,param_1[0xe].mTevStr.mLightObj.mDir.x,_4727,
               _4339);
    m_Do_mtx::mDoMtx_YrotS
              (SComponent::calc_mtx,(int)*(short *)&param_1[0xe].mTevStr.mLightObj.mCosAtten.z);
    local_110.x = _5530 + _4915 + d_s_play::g_regHIO.mChild[0].mFloats[7];
    local_110.y = _4950 + (this->parent).mCurrent.mPos.y + d_s_play::g_regHIO.mChild[0].mFloats[8];
    local_110.z = _5559 + d_s_play::g_regHIO.mChild[0].mFloats[9];
    SComponent::MtxPosition(&local_110,(cXyz *)&param_1[0xe].mEvtInfo.mEventId);
    fVar29 = _5560;
    *(float *)&param_1[0xe].mEvtInfo.mEventId =
         *(float *)&param_1[0xe].mEvtInfo.mEventId +
         (this->parent).mCurrent.mPos.x * (_5560 + d_s_play::g_regHIO.mChild[0].mFloats[15]);
    param_1[0xe].mEvtInfo.mpCheckCB =
         (undefined *)
         ((float)param_1[0xe].mEvtInfo.mpCheckCB +
         (this->parent).mCurrent.mPos.z * (fVar29 + d_s_play::g_regHIO.mChild[0].mFloats[15]));
    SComponent::cLib_addCalc2
              ((float *)&param_1[0xe].mEvtInfo.mpPhotoCB,(this->parent).mCurrent.mPos.x,_5551,_4915)
    ;
    SComponent::cLib_addCalc2
              ((float *)&param_1[0xe].mTevStr,
               ((this->parent).mCurrent.mPos.y - _4492) + d_s_play::g_regHIO.mChild[0].mFloats[10],
               _5551,_4915);
    SComponent::cLib_addCalc2
              (&param_1[0xe].mTevStr.mLightObj.mPos.y,(this->parent).mCurrent.mPos.z,_5551,_4915);
    if ((*(short *)&param_1[1].parent.parent.mpCtRq == 0) &&
       (iVar10 = (*(code *)this[1].parent.parent.parent.mLyTg.parent.parent.mpPrevNode[3].mpPrevNode
                 )(this), iVar10 == 0)) {
      dCamera_c::Start((dCamera_c *)(iVar7 + 0x244));
      *(undefined *)((int)&param_1[0xe].mEvtInfo.mCommand + 1) = 0;
      *(undefined *)&param_1[0xe].mEvtInfo.mCommand = 0;
      fopAcM_SetParam(param_1,0);
      param_1[1].parent.parent.mDtTg.parent.parent.mpPrevNode = (node_class *)0x0;
      param_1[0xd].parent.parent.mLyTg.mpLayer = (layer_class *)0x0;
      dComIfGp_event_reset();
    }
    break;
  case 7:
switchD_800ee9e4_caseD_7:
    if (*(short *)&param_1[1].parent.parent.mInitState != 0) break;
    if (9 < *(short *)(dr + 0x4ba)) {
      *(undefined *)((int)&param_1[0xe].mEvtInfo.mCommand + 1) = 0;
      ::cXyz::cXyz(&cStack476,(cXyz *)&param_1[0xe].mEvtInfo.mpPhotoCB);
      ::cXyz::cXyz(&cStack488,(cXyz *)&param_1[0xe].mEvtInfo.mEventId);
      dCamera_c::Reset((dCamera_c *)(iVar7 + 0x244),&cStack476,&cStack488);
      ::cXyz::_cXyz(&cStack488);
      ::cXyz::_cXyz(&cStack476);
      dCamera_c::Start((dCamera_c *)(iVar7 + 0x244));
      dCamera_c::SetTrimSize((dCamera_c *)(iVar7 + 0x244),0);
      dComIfGp_event_reset();
      break;
    }
    param_1[0xe].mTevStr.mLightObj.mPos.z = _4492 + d_s_play::g_regHIO.mChild[0].mFloats[12];
    fopAcM_OnStatus(btd,0x4000);
    *(undefined *)((int)&param_1[0xe].mEvtInfo.mCommand + 1) = 8;
    param_1[0xe].mEvtInfo.mpPhotoCB = (undefined *)_4343;
    fVar29 = _4727;
    param_1[0xe].mTevStr.mLightObj.mPos.x = _5561 + _4727 * d_s_play::g_regHIO.mChild[0].mFloats[5];
    param_1[0xe].mTevStr.mLightObj.mPos.y = fVar29 * d_s_play::g_regHIO.mChild[0].mFloats[6];
    m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)*(short *)(btd + 0x206));
    local_110.x = _4727 * d_s_play::g_regHIO.mChild[0].mFloats[7];
    local_110.y = _5533 + _4727 * d_s_play::g_regHIO.mChild[0].mFloats[8];
    local_110.z = _5566 + _4727 * d_s_play::g_regHIO.mChild[0].mFloats[9];
    SComponent::MtxPosition(&local_110,(cXyz *)&param_1[0xe].mEvtInfo.mEventId);
    param_1[0xe].mTevStr.mLightObj.mPos.z = _5553 + d_s_play::g_regHIO.mChild[0].mFloats[13];
    *(undefined2 *)&param_1[1].parent.parent.mInitState = 0xd2;
    ::dBgS_LinChk::dBgS_LinChk(&dStack260);
    ::dBgS_LinChk::Set(&dStack260,(cXyz *)&param_1[0xe].mEvtInfo.mpPhotoCB,
                       (cXyz *)&param_1[0xe].mEvtInfo.mEventId,param_1);
    cVar18 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&dStack260.parent);
    if (cVar18 != '\0') {
      pcVar16 = (cXyz *)::cBgS_LinChk::GetCross(&dStack260.parent);
      ::cXyz::operator__((cXyz *)&param_1[0xe].mEvtInfo.mEventId,pcVar16);
    }
    ::dBgS_LinChk::_dBgS_LinChk(&dStack260);
  case 8:
    *(undefined *)(dr + 0x40a) = 3;
    if (*(short *)&param_1[1].parent.parent.mInitState == 200) {
      mDoAud_seStart(0x4840,0,0,0);
    }
    if (*(short *)&param_1[1].parent.parent.mInitState == 0xaa) {
      fopAcM_seStartCurrent(dr,0x5829,0);
    }
    fVar29 = _4915;
    if (0x96 < *(short *)&param_1[1].parent.parent.mInitState) {
      fVar29 = _4916;
    }
    SComponent::cLib_addCalc2((float *)(dr + 0x414),fVar29,_5546,_4915);
    if (*(short *)&param_1[1].parent.parent.mInitState < 0x79) {
      SComponent::cLib_addCalc2
                ((float *)&param_1[0xe].mTevStr,
                 _5567 + _4727 * d_s_play::g_regHIO.mChild[0].mFloats[5],_4333,_4915);
      SComponent::cLib_addCalc2((float *)&param_1[0xe].mEvtInfo.mpEventCB,_4343,_5546,_4915);
      if (*(short *)&param_1[1].parent.parent.mInitState ==
          (short)(d_s_play::g_regHIO.mChild[0].mShorts[4] + 0x6e)) {
        *(float *)&param_1[0xe].mTevStr.mLightObj.field_0x34 =
             _4492 + d_s_play::g_regHIO.mChild[0].mFloats[11];
        *(undefined *)(btd + 0x6e15) = 0xb4;
      }
      if (*(short *)&param_1[1].parent.parent.mInitState < 0x51) {
        SComponent::cLib_addCalc2
                  (&param_1[0xe].mTevStr.mLightObj.mPos.z,
                   _5568 + d_s_play::g_regHIO.mChild[0].mFloats[14],_5546,_5557);
      }
    }
    if (*(short *)&param_1[1].parent.parent.mInitState == 2) {
      *(undefined *)(btd + 0x6e15) = 1;
    }
    if (*(short *)&param_1[1].parent.parent.mInitState == 0) {
      if (*(byte *)(btd + 0x6190) < 3) {
        *(undefined *)((int)&param_1[0xe].mEvtInfo.mCommand + 1) = 0;
        ::cXyz::cXyz(&local_164,&(this->parent).mEyePos);
        local_164.x = local_164.x * _5569;
        local_164.z = local_164.z * _5569;
        ::cXyz::cXyz(&cStack500,&(this->parent).mEyePos);
        ::cXyz::cXyz(&cStack512,&local_164);
        dCamera_c::Reset((dCamera_c *)(iVar7 + 0x244),&cStack500,&cStack512);
        ::cXyz::_cXyz(&cStack512);
        ::cXyz::_cXyz(&cStack500);
        dCamera_c::Start((dCamera_c *)(iVar7 + 0x244));
        dCamera_c::SetTrimSize((dCamera_c *)(iVar7 + 0x244),0);
        fopAcM_OffStatus(btd,0x4000);
        dComIfGp_event_reset();
        ::cXyz::_cXyz(&local_164);
      }
      else {
        *(undefined *)((int)&param_1[0xe].mEvtInfo.mCommand + 1) = 9;
        *(undefined2 *)&param_1[1].parent.parent.mInitState = 0xdc;
      }
      *(undefined *)(dr + 0x40a) = 0;
    }
    break;
  case 9:
    SComponent::cLib_addCalc2
              (&param_1[0xe].mTevStr.mLightObj.mPos.z,
               _4492 + d_s_play::g_regHIO.mChild[0].mFloats[4],_5546,_4337);
    SComponent::cLib_addCalc2
              ((float *)&param_1[0xe].mTevStr,
               _5530 + *(float *)(btd + 0x264) + _4727 * d_s_play::g_regHIO.mChild[0].mFloats[5],
               _4346,_5533);
    m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)*(short *)(btd + 0x206));
    local_110.x = _5570 + _4727 * d_s_play::g_regHIO.mChild[0].mFloats[7];
    local_110.y = _4915 + _4727 * d_s_play::g_regHIO.mChild[0].mFloats[8];
    local_110.z = _4916 + _4727 * d_s_play::g_regHIO.mChild[0].mFloats[9];
    SComponent::MtxPosition(&local_110,&local_11c);
    SComponent::cLib_addCalc2((float *)&param_1[0xe].mEvtInfo.mEventId,local_11c.x,_4727,_4492);
    SComponent::cLib_addCalc2((float *)&param_1[0xe].mEvtInfo.mpEventCB,local_11c.y,_4727,_4492);
    SComponent::cLib_addCalc2((float *)&param_1[0xe].mEvtInfo.mpCheckCB,local_11c.z,_4727,_4492);
    if (*(short *)&param_1[1].parent.parent.mInitState == 99) {
      *(undefined *)(btd + 0x6e15) = 0xb4;
    }
    if (*(short *)&param_1[1].parent.parent.mInitState == 0x28) {
      *(undefined *)(btd + 0x6e15) = 1;
    }
    if (*(short *)&param_1[1].parent.parent.mInitState == 0) {
      *(undefined *)((int)&param_1[0xe].mEvtInfo.mCommand + 1) = 0;
      ::cXyz::cXyz(&local_170,&(this->parent).mEyePos);
      local_170.x = local_170.x * _5569;
      local_170.z = local_170.z * _5569;
      ::cXyz::cXyz(&cStack524,&(this->parent).mEyePos);
      ::cXyz::cXyz(&cStack536,&local_170);
      dCamera_c::Reset((dCamera_c *)(iVar7 + 0x244),&cStack524,&cStack536);
      ::cXyz::_cXyz(&cStack536);
      ::cXyz::_cXyz(&cStack524);
      dCamera_c::Start((dCamera_c *)(iVar7 + 0x244));
      dCamera_c::SetTrimSize((dCamera_c *)(iVar7 + 0x244),0);
      fopAcM_OffStatus(btd,0x4000);
      dComIfGp_event_reset();
      ::cXyz::_cXyz(&local_170);
    }
    break;
  case 0xff:
    iVar10 = ::dEvt_info_c::checkCommandDemoAccrpt(&param_1->mEvtInfo);
    if (iVar10 == 0) {
      f_op_actor_mng::fopAcM_orderPotentialEvent(param_1,1,0xffff,0);
      ::dEvt_info_c::onCondition(&param_1->mEvtInfo,2);
      break;
    }
    param_1[0xe].mTevStr.mLightObj.mPos.z = _4492 + d_s_play::g_regHIO.mChild[0].mFloats[12];
    dCamera_c::Stop((dCamera_c *)(iVar7 + 0x244));
    dCamera_c::SetTrimSize((dCamera_c *)(iVar7 + 0x244),2);
    *(undefined *)((int)&param_1[0xe].mEvtInfo.mCommand + 1) = 2;
    *(float *)&param_1[0xe].mAcTg.mbAdded = _5543;
    param_1[0xe].mDwTg.parent.mpData = (undefined *)0x0;
    *(undefined2 *)&param_1[0xe].mDwTg.mbAdded = 0;
    param_1[0xe].mDwTg.mpTagData = (create_request *)_4343;
    *(undefined2 *)&param_1[0xe].mDwTg.field_0x12 = 0;
    if (*(char *)&param_1[0xe].mTevStr.mLightObj.mDistAtten.z == '\0') {
      *(short *)&param_1[0xe].mTevStr.mLightObj.mCosAtten.z =
           *(short *)((int)&param_1[0xd].parent.parent.mLyTg.mpLayer[0xb].mCancelList.mpTail + 2) +
           0x4000;
    }
    else {
      *(short *)&param_1[0xe].mTevStr.mLightObj.mCosAtten.z =
           *(short *)((int)&param_1[0xd].parent.parent.mLyTg.mpLayer[0xb].mCancelList.mpTail + 2) +
           -0x4000;
    }
    uVar8 = fopAcM_GetParam(param_1[0xd].parent.parent.mLyTg.mpLayer);
    if ((uVar8 & 0xf0) == 0) {
      param_1[0xe].mDwTg.parent.mpPrevNode = (node_class *)_4343;
      fVar1 = _4949;
      fVar29 = _4333;
      if (DAT_803e421a == 2) {
        param_1[0xe].mTevStr.mLightObj.mDistAtten.x = _4333;
        param_1[0xe].mTevStr.mLightObj.mDistAtten.y = _4949;
      }
      else {
        if (DAT_803e421a < 2) {
          if (DAT_803e421a == 0) {
            fVar29 = SComponent::cM_rndF(_4333);
            if (_5546 <= fVar29) {
              param_1[0xe].mTevStr.mLightObj.mDistAtten.x = _4949;
            }
            else {
              param_1[0xe].mTevStr.mLightObj.mDistAtten.x = _4333;
            }
            fVar29 = SComponent::cM_rndF(_4333);
            if (_5546 <= fVar29) {
              param_1[0xe].mTevStr.mLightObj.mDistAtten.y = _4949;
            }
            else {
              param_1[0xe].mTevStr.mLightObj.mDistAtten.y = _4333;
            }
          }
          else {
            if (-1 < DAT_803e421a) {
              param_1[0xe].mTevStr.mLightObj.mDistAtten.x = _4333;
              param_1[0xe].mTevStr.mLightObj.mDistAtten.y = fVar29;
            }
          }
        }
        else {
          if (DAT_803e421a == 4) {
            param_1[0xe].mTevStr.mLightObj.mDistAtten.x = _4949;
            param_1[0xe].mTevStr.mLightObj.mDistAtten.y = fVar1;
          }
          else {
            if (DAT_803e421a < 4) {
              param_1[0xe].mTevStr.mLightObj.mDistAtten.x = _4949;
              param_1[0xe].mTevStr.mLightObj.mDistAtten.y = _4333;
            }
          }
        }
      }
      if (_4343 <= param_1[0xe].mTevStr.mLightObj.mDistAtten.y) {
        param_1[0xe].mTevStr.mLightObj.mDir.y = _4333;
      }
      else {
        param_1[0xe].mTevStr.mLightObj.mDir.y = _4337 + d_s_play::g_regHIO.mChild[0].mFloats[6];
      }
    }
    else {
      param_1[0xe].mDwTg.parent.mpPrevNode =
           (node_class *)(_5544 + d_s_play::g_regHIO.mChild[0].mFloats[6]);
      param_1[0xe].mTevStr.mLightObj.mDistAtten.x = _4949;
      param_1[0xe].mTevStr.mLightObj.mDistAtten.y = _4333 + d_s_play::g_regHIO.mChild[0].mFloats[7];
      param_1[0xe].mTevStr.mLightObj.mDir.y = _5545 + d_s_play::g_regHIO.mChild[0].mFloats[16];
    }
    ::cXyz::operator__((cXyz *)&param_1[0xe].mEvtInfo.mpPhotoCB,
                       (cXyz *)&param_1[0xd].parent.parent.mLyTg.mpLayer[0xb].mNodeListTree.
                                mNumLists);
  case 2:
    SComponent::cLib_addCalc0
              ((float *)&param_1[0xe].mDwTg,_4333,_4337 + d_s_play::g_regHIO.mChild[0].mFloats[7]);
    SComponent::cLib_addCalc2((float *)&param_1[0xe].mAcTg.mbAdded,_5547,_4333,_4339);
    if (_5548 < *(float *)&param_1[0xe].mAcTg.mbAdded) {
      pnVar6 = (node_class *)param_1[0xe].mDwTg.parent.mpData;
      if ((int)pnVar6 < 400) {
        fVar29 = _5535 - _5549 * ((float)param_1[0xd].parent.parent.mLyTg.mpLayer[0xc].parent.
                                         mpNextNode - _4333);
        if (fVar29 < _5546) {
          fVar29 = _5546;
        }
        iVar10 = (int)((float)param_1[0xe].mDwTg.mpTagData / fVar29);
        local_98 = (longlong)iVar10;
        param_1[0xe].mDwTg.parent.mpNextNode = pnVar6;
        param_1[0xe].mDwTg.parent.mpData = param_1[0xe].mDwTg.parent.mpData + iVar10 + 1;
        param_1[0xe].mDwTg.mpTagData =
             (create_request *)((float)param_1[0xe].mDwTg.mpTagData + _4333);
        pnVar6 = param_1[0xe].mDwTg.parent.mpNextNode;
        if (pnVar6 == (node_class *)0x0) {
          fopAcM_seStart(param_1,0x2818,0);
        }
        else {
          if (((int)pnVar6 < 0xd) || (iVar10 + 0xe < (int)param_1[0xe].mDwTg.parent.mpData)) {
            if (((int)pnVar6 < 0x1a) || (iVar10 + 0x1b < (int)param_1[0xe].mDwTg.parent.mpData)) {
              if ((0x26 < (int)pnVar6) && ((int)param_1[0xe].mDwTg.parent.mpData <= iVar10 + 0x28))
              {
                fopAcM_seStart(param_1,0x281a,0);
              }
            }
            else {
              fopAcM_seStart(param_1,0x281a,0);
            }
          }
          else {
            fopAcM_seStart(param_1,0x2819,0);
          }
        }
      }
      uVar8 = fopAcM_GetParam(param_1[0xd].parent.parent.mLyTg.mpLayer);
      if ((uVar8 & 0xf) == 3) {
        pnVar6 = (node_class *)
                 (((float)param_1[0xd].parent.parent.mLyTg.mpLayer[0xc].parent.mpNextNode - _5550) +
                 d_s_play::g_regHIO.mChild[8].mFloats[7]);
      }
      else {
        pnVar6 = param_1[0xd].parent.parent.mLyTg.mpLayer[0xc].parent.mpNextNode;
      }
      uVar8 = (uint)(_4723 - _4916 * ((float)pnVar6 - _4333));
      local_98 = (longlong)(int)uVar8;
      sVar17 = (short)uVar8;
      SComponent::cLib_addCalcAngleS2
                ((short *)&param_1[0xe].mDwTg.mbAdded,sVar17,1,
                 (sVar17 >> 3) + (ushort)(sVar17 < 0 && (uVar8 & 7) != 0));
      if (0x31 < (int)param_1[0xe].mDwTg.parent.mpData) {
        sVar17 = *(short *)&param_1[0xe].mDwTg.field_0x12;
        if (sVar17 == 9000) {
          *(undefined2 *)&param_1[0xe].mDwTg.field_0x12 = 0x238c;
        }
        else {
          if (sVar17 < 9000) {
            *(undefined2 *)&param_1[0xe].mDwTg.field_0x12 = 9000;
            uVar8 = fopAcM_GetParam(param_1[0xd].parent.parent.mLyTg.mpLayer);
            if ((uVar8 & 0xf0) == 0) {
              fopAcM_seStart(param_1,0x281b,0);
            }
            else {
              fopAcM_seStart(param_1,0x2830,0);
            }
          }
        }
      }
    }
    SComponent::cLib_addCalc2
              ((float *)&param_1[0xe].mEvtInfo.mpPhotoCB,
               (float)param_1[0xd].parent.parent.mLyTg.mpLayer[0xb].mNodeListTree.mNumLists,_5551,
               _4915);
    SComponent::cLib_addCalc2
              ((float *)&param_1[0xe].mTevStr,
               (float)param_1[0xd].parent.parent.mLyTg.mpLayer[0xb].mpPcNode,_5551,_4915);
    SComponent::cLib_addCalc2
              (&param_1[0xe].mTevStr.mLightObj.mPos.y,
               (float)param_1[0xd].parent.parent.mLyTg.mpLayer[0xb].mCancelList.mpHead,_5551,_4915);
    ::cXyz::operator__((cXyz *)&param_1[0xe].mEvtInfo.mEventId,
                       (cXyz *)&param_1[0xd].parent.parent.mLyTg.mpLayer[0xb].mNodeListTree.
                                mNumLists);
    m_Do_mtx::mDoMtx_YrotS
              (SComponent::calc_mtx,(int)*(short *)&param_1[0xe].mTevStr.mLightObj.mCosAtten.z);
    local_110.x = (_4492 + _4339 * d_s_play::g_regHIO.mChild[0].mFloats[5]) *
                  param_1[0xe].mTevStr.mLightObj.mDistAtten.x;
    local_110.y = _5552 + (_4339 * d_s_play::g_regHIO.mChild[0].mFloats[4] - _5530);
    local_110.z = ((_5530 + _4339 * d_s_play::g_regHIO.mChild[0].mFloats[3]) - _5553) *
                  param_1[0xe].mTevStr.mLightObj.mDistAtten.y;
    SComponent::MtxPosition(&local_110,&local_11c);
    *(float *)&param_1[0xe].mEvtInfo.mEventId =
         *(float *)&param_1[0xe].mEvtInfo.mEventId +
         local_11c.x * param_1[0xe].mTevStr.mLightObj.mDir.y;
    param_1[0xe].mEvtInfo.mpEventCB =
         (undefined *)
         ((float)param_1[0xe].mEvtInfo.mpEventCB +
         local_11c.y * param_1[0xe].mTevStr.mLightObj.mDir.y);
    param_1[0xe].mEvtInfo.mpCheckCB =
         (undefined *)
         ((float)param_1[0xe].mEvtInfo.mpCheckCB +
         local_11c.z * param_1[0xe].mTevStr.mLightObj.mDir.y);
    uVar8 = fopAcM_GetParam(param_1[0xd].parent.parent.mLyTg.mpLayer);
    if ((uVar8 & 0xf0) == 0) {
      SComponent::cLib_addCalc2
                (&param_1[0xe].mTevStr.mLightObj.mDir.y,_4333,
                 _4346 + d_s_play::g_regHIO.mChild[0].mFloats[4],
                 _4727 + d_s_play::g_regHIO.mChild[0].mFloats[5]);
    }
    else {
      SComponent::cLib_addCalc2
                (&param_1[0xe].mTevStr.mLightObj.mDir.y,
                 _5554 + d_s_play::g_regHIO.mChild[0].mFloats[6],
                 _4346 + d_s_play::g_regHIO.mChild[0].mFloats[4],
                 _4727 + d_s_play::g_regHIO.mChild[0].mFloats[5]);
    }
  }
  if ('\0' < *(char *)((int)&param_1[0xe].mEvtInfo.mCommand + 1)) {
    dVar23 = (double)cM_ssin((int)(short)((short)param_1[1].parent.parent.mLnTg.mLineListID * 0x3300
                                         ));
    dVar24 = (double)(float)((double)*(float *)&param_1[0xe].mTevStr.mLightObj.field_0x34 * dVar23);
    dVar23 = (double)cM_scos((int)(short)((short)param_1[1].parent.parent.mLnTg.mLineListID * 0x3000
                                         ));
    local_188.y = (float)((double)*(float *)&param_1[0xe].mTevStr.mLightObj.field_0x34 * dVar23);
    local_17c.x = (float)((double)*(float *)&param_1[0xe].mEvtInfo.mEventId + dVar24);
    local_17c.y = (float)param_1[0xe].mEvtInfo.mpEventCB + local_188.y;
    local_17c.z = (float)param_1[0xe].mEvtInfo.mpCheckCB;
    local_188.x = (float)((double)(float)param_1[0xe].mEvtInfo.mpPhotoCB + dVar24);
    local_188.y = param_1[0xe].mTevStr.mLightObj.mPos.x + local_188.y;
    local_188.z = param_1[0xe].mTevStr.mLightObj.mPos.y;
    dVar23 = (double)cM_scos((int)(short)((short)param_1[1].parent.parent.mLnTg.mLineListID * 0x1c00
                                         ));
    iVar10 = (int)(_5571 * (float)((double)*(float *)&param_1[0xe].mTevStr.mLightObj.field_0x34 *
                                  dVar23));
    local_98 = (longlong)iVar10;
    ::cXyz::cXyz(&cStack548,&local_188);
    ::cXyz::cXyz(&cStack560,&local_17c);
    dCamera_c::Set((dCamera_c *)(iVar7 + 0x244),&cStack548,&cStack560,(short)iVar10,
                   param_1[0xe].mTevStr.mLightObj.mPos.z);
    ::cXyz::_cXyz(&cStack560);
    ::cXyz::_cXyz(&cStack548);
    SComponent::cLib_addCalc0
              ((float *)&param_1[0xe].mTevStr.mLightObj.field_0x34,_4333,
               _5557 + d_s_play::g_regHIO.mChild[0].mFloats[16]);
    sVar17 = 0;
    if ((param_1[0xd].parent.parent.mLyTg.mpLayer != (layer_class *)0x0) &&
       (uVar8 = fopAcM_GetParam(), (uVar8 & 0xf0) != 0)) {
      sVar17 = -0x32;
    }
    if (((int)(short)(sVar17 + 0x82) < (int)param_1[0xe].mDwTg.parent.mpData) &&
       (d_s_play::g_regHIO.mChild[0].mShorts[8] == 0)) {
      uVar8 = fopAcM_GetParam(param_1[0xd].parent.parent.mLyTg.mpLayer);
      if ((uVar8 & 0xf0) == 0) {
        dCamera_c::Start((dCamera_c *)(iVar7 + 0x244));
        *(undefined *)((int)&param_1[0xe].mEvtInfo.mCommand + 1) = 0;
        *(undefined *)&param_1[0xe].mEvtInfo.mCommand = 2;
        fopAcM_SetParam(param_1,2);
        dComIfGp_event_reset();
      }
      else {
        if (*(char *)((int)&param_1[0xe].mEvtInfo.mCommand + 1) == '\x02') {
          if (*(short *)(dr + 0x4ba) < 10) {
            *(undefined *)((int)&param_1[0xe].mEvtInfo.mCommand + 1) = 3;
            *(short *)&param_1[1].parent.parent.mInitState =
                 d_s_play::g_regHIO.mChild[0].mShorts[2] + 0x41;
          }
          else {
            *(undefined *)((int)&param_1[0xe].mEvtInfo.mCommand + 1) = 4;
            *(undefined *)&param_1[0xe].mEvtInfo.mCommand = 2;
            *(undefined2 *)&param_1[1].parent.parent.mInitState = 0;
            if (btd != 0) {
              fopAcM_OnStatus(btd,0x4000);
            }
          }
          *(undefined *)&param_1[0xe].mEvtInfo.mCommand = 2;
        }
      }
    }
    ::cXyz::_cXyz(&local_188);
    ::cXyz::_cXyz(&local_17c);
  }
  if ((int)param_1[1].parent.parent.mLnTg.parent.parent.mpNextNode < 2) {
    param_1[1].parent.parent.mLnTg.parent.parent.mpNextNode = (node_class *)&DAT_00000002;
  }
  ::cXyz::_cXyz(&cStack344);
  ::cXyz::_cXyz(&cStack332);
  ::cXyz::_cXyz(&local_140);
  ::cXyz::_cXyz(&local_134);
  ::cXyz::_cXyz(&cStack296);
  ::cXyz::_cXyz(&local_11c);
  ::cXyz::_cXyz(&local_110);
  __psq_l0(auStack8,uVar21);
  __psq_l1(auStack8,uVar21);
  __psq_l0(auStack24,uVar21);
  __psq_l1(auStack24,uVar21);
  __psq_l0(auStack40,uVar21);
  __psq_l1(auStack40,uVar21);
  __psq_l0(auStack56,uVar21);
  __psq_l1(auStack56,uVar21);
  __psq_l0(auStack72,uVar21);
  __psq_l1(auStack72,uVar21);
  __psq_l0(auStack88,uVar21);
  __psq_l1(auStack88,uVar21);
  return;
}


/* __stdcall cM_scos(short) */

double cM_scos(uint param_1)

{
  return (double)JKernel::JMath::jmaCosTable
                 [(int)(param_1 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
}


/* __stdcall cM_ssin(short) */

double cM_ssin(uint param_1)

{
  return (double)JKernel::JMath::jmaSinTable
                 [(int)(param_1 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
}

}

/* __thiscall cBgS_LinChk::GetCross(void) */

cXyz * __thiscall cBgS_LinChk::GetCross(cBgS_LinChk *this)

{
  return &(this->mLin).mP1;
}


/* __thiscall dBgS_LinChk::dBgS_LinChk(void) */

void __thiscall dBgS_LinChk::dBgS_LinChk(dBgS_LinChk *this)

{
  dBgS_PolyPassChk *pdVar1;
  
  (this->parent).parent.vtbl = &cBgS_Chk::__vt;
  (this->parent).parent.mpPolyPassChk = (cBgS_PolyPassChk *)0x0;
  (this->parent).parent.mpGrpPassChk = (cBgS_GrpPassChk *)0x0;
  (this->parent).parent.mbExcludeSameProcID = true;
  (this->parent).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  (this->parent).mPolyInfo.mTriIdx = -1;
  (this->parent).mPolyInfo.mBgIndex = 0x100;
  (this->parent).mPolyInfo.mpBgW = (cBgW *)0x0;
  (this->parent).mPolyInfo.mProcID = -1;
  (this->parent).parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
  (this->parent).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371fbc;
  (this->parent).mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
  ::cBgS_LinChk::ct(&this->parent);
  (this->mPolyPassChk).parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
  (this->mPolyPassChk).parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt;
  (this->mPolyPassChk).parent.mbObjThrough = 0;
  (this->mPolyPassChk).parent.mbCamThrough = 0;
  (this->mPolyPassChk).parent.mbLinkThrough = 0;
  (this->mPolyPassChk).parent.mbArrowsAndLightThrough = 0;
  (this->mPolyPassChk).parent.mbBombThrough = 0;
  (this->mPolyPassChk).parent.mbBoomerangThrough = 0;
  (this->mPolyPassChk).parent.mbHookshotThrough = 0;
  (this->mGrpPassChk).parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
  (this->mGrpPassChk).parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt;
  (this->mGrpPassChk).parent.mAttr = 1;
  (this->mPolyPassChk).parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
  (this->mGrpPassChk).parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
  (this->parent).parent.vtbl = (cBgS_Chk__vtbl *)&__vt;
  (this->parent).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_80371f38;
  (this->mPolyPassChk).parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f44;
  (this->mGrpPassChk).parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f50;
  (this->parent).parent.mpPolyPassChk = (cBgS_PolyPassChk *)&this->mPolyPassChk;
  pdVar1 = &this->mPolyPassChk;
  if (pdVar1 != (dBgS_PolyPassChk *)0x0) {
    pdVar1 = (dBgS_PolyPassChk *)&this->mGrpPassChk;
  }
  (this->parent).parent.mpGrpPassChk = (cBgS_GrpPassChk *)pdVar1;
  return;
}


namespace d_a_himo2 {

/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Removing unreachable block (ram,0x800f0604) */
/* WARNING: Removing unreachable block (ram,0x800f05fc) */
/* WARNING: Removing unreachable block (ram,0x800f060c) */
/* __stdcall daHimo2_Execute(himo2_class *) */

undefined4 daHimo2_Execute(void *param_1)

{
  daPy_lk_c *pdVar1;
  MTX34 *pMVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  cBgS_PolyPassChk *pcVar6;
  undefined4 uVar7;
  double dVar8;
  undefined8 in_f29;
  double dVar9;
  undefined8 in_f30;
  double dVar10;
  undefined8 in_f31;
  double dVar11;
  cXyz local_c8;
  cBgS_GndChk local_bc;
  cBgS_PolyPassChk local_7c;
  undefined local_70 [20];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if (btd == (void *)0x0) {
    btd = f_pc_executor::fpcEx_Search(b_a_sub,param_1);
  }
  if (dr == (void *)0x0) {
    dr = f_pc_executor::fpcEx_Search(dr_a_sub,param_1);
  }
  *(int *)((int)param_1 + 0x2d8) = *(int *)((int)param_1 + 0x2d8) + 1;
  rope_scale = DAT_803e4230;
  local_c8.x = _4729;
  local_c8.y = _4343;
  local_c8.z = _4343;
  if (((pdVar1->parent).field_0x2a4 & 4) == 0) {
    pMVar2 = (MTX34 *)(*(code *)pdVar1->vtbl->getLeftHandMatrix)(pdVar1);
    mtx::PSMTXCopy(pMVar2,SComponent::calc_mtx);
    SComponent::MtxPosition(&local_c8,(cXyz *)((int)param_1 + 0x2ec));
    pMVar2 = (MTX34 *)(*(code *)pdVar1->vtbl->getRightHandMatrix)(pdVar1);
    mtx::PSMTXCopy(pMVar2,SComponent::calc_mtx);
    SComponent::MtxPosition(&local_c8,(cXyz *)((int)param_1 + 0x2f8));
  }
  else {
    pMVar2 = (MTX34 *)(*(code *)pdVar1->vtbl->getLeftHandMatrix)(pdVar1);
    mtx::PSMTXCopy(pMVar2,SComponent::calc_mtx);
    SComponent::MtxPosition(&local_c8,(cXyz *)((int)param_1 + 0x2f8));
    pMVar2 = (MTX34 *)(*(code *)pdVar1->vtbl->getRightHandMatrix)(pdVar1);
    mtx::PSMTXCopy(pMVar2,SComponent::calc_mtx);
    SComponent::MtxPosition(&local_c8,(cXyz *)((int)param_1 + 0x2ec));
  }
  *(undefined4 *)((int)param_1 + 0x2b4) = *(undefined4 *)((int)param_1 + 0x2ec);
  *(undefined4 *)((int)param_1 + 0x2b8) = *(undefined4 *)((int)param_1 + 0x2f0);
  *(undefined4 *)((int)param_1 + 700) = *(undefined4 *)((int)param_1 + 0x2f4);
  iVar5 = *(int *)((int)param_1 + 0x2cc) + -0x32;
  if (iVar5 < 3) {
    iVar5 = 3;
  }
  ::cBgS_GndChk::cBgS_GndChk(&local_bc);
  pcVar6 = &local_7c;
  local_7c.mbObjThrough = 0;
  local_7c.mbCamThrough = 0;
  local_7c.mbLinkThrough = 0;
  local_7c.mbArrowsAndLightThrough = 0;
  local_7c.mbBombThrough = 0;
  local_7c.mbBoomerangThrough = 0;
  local_7c.mbHookshotThrough = 0;
  local_70._4_4_ = 1;
  local_bc.parent.vtbl = &::dBgS_GndChk::__vt;
  local_bc.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371f08;
  local_7c.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_70._0_4_ = &PTR_80371f20;
  local_bc.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar6;
  if (pcVar6 != (cBgS_PolyPassChk *)0x0) {
    local_bc.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_70;
  }
  iVar4 = (int)param_1 + 0x1120;
  dVar9 = (double)_5868;
  dVar10 = (double)_5532;
  dVar11 = (double)_4347;
  local_bc.parent.mpPolyPassChk = pcVar6;
  for (iVar3 = 0; iVar3 < iVar5; iVar3 = iVar3 + 1) {
    if (*(int *)((int)param_1 + 0x2dc) == 2) {
      *(float *)(iVar4 + 0xc) = (float)dVar11;
    }
    else {
      local_bc.mPos.z = *(float *)(iVar4 + 0x18);
      local_bc.mPos.y = (float)((double)*(float *)(iVar4 + 0x14) + dVar9);
      local_bc.mPos.x = *(float *)(iVar4 + 0x10);
      dVar8 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_bc)
      ;
      *(float *)(iVar4 + 0xc) = (float)(dVar10 + dVar8);
    }
    iVar4 = iVar4 + 0x24;
  }
  new_himo2_move(param_1);
  iVar5 = (int)param_1 + 0x310;
  for (iVar3 = 0; iVar3 < *(int *)((int)param_1 + 0x2cc) + 1; iVar3 = iVar3 + 1) {
    *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)((int)param_1 + 0x2b4);
    *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)((int)param_1 + 0x2b8);
    *(undefined4 *)(iVar5 + 0x18) = *(undefined4 *)((int)param_1 + 700);
    iVar5 = iVar5 + 0x24;
  }
  himo2_control(param_1,(int)param_1 + 0x310);
  *(undefined4 *)((int)param_1 + 0x110c) = *(undefined4 *)((int)param_1 + 0x1f8);
  *(undefined4 *)((int)param_1 + 0x1110) = *(undefined4 *)((int)param_1 + 0x1fc);
  *(undefined4 *)((int)param_1 + 0x1114) = *(undefined4 *)((int)param_1 + 0x200);
  himo2_control2(param_1,(int)param_1 + 0x310);
  if ((*(int *)((int)param_1 + 0x2dc) == 2) || (*(int *)((int)param_1 + 0x2dc) == 3)) {
    ::cM3dGSph::SetR((cM3dGSph *)((int)param_1 + 0x2168),_5535);
  }
  else {
    ::cM3dGSph::SetR((cM3dGSph *)((int)param_1 + 0x2168),_5869);
  }
  ::cM3dGSph::SetC((cM3dGSph *)((int)param_1 + 0x2168),(cXyz *)((int)param_1 + 0x1f8));
  cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,
            (cCcD_Obj *)((int)param_1 + 0x2050));
  *(undefined4 *)((int)param_1 + 0x260) = *(undefined4 *)((int)param_1 + 0x1f8);
  *(undefined4 *)((int)param_1 + 0x264) = *(undefined4 *)((int)param_1 + 0x1fc);
  *(undefined4 *)((int)param_1 + 0x268) = *(undefined4 *)((int)param_1 + 0x200);
  local_7c.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_70._0_4_ = &PTR_80371f20;
  if (pcVar6 != (cBgS_PolyPassChk *)0x0) {
    local_7c.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_70._0_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x70) &&
       (local_70._0_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x70)) {
      local_70._0_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar6 != (cBgS_PolyPassChk *)0x0) &&
       (local_7c.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar6 != (cBgS_PolyPassChk *)0x0)) {
      local_7c.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_bc.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_bc.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_bc.parent);
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  __psq_l0(auStack40,uVar7);
  __psq_l1(auStack40,uVar7);
  return 1;
}


/* __stdcall daHimo2_IsDelete(himo2_class *) */

undefined4 daHimo2_IsDelete(void)

{
  return 1;
}


/* __stdcall daHimo2_Delete(himo2_class *) */

undefined4 daHimo2_Delete(void)

{
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e4218);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall CallbackCreateHeap(fopAc_ac_c *) */

bool CallbackCreateHeap(int param_1)

{
  ResTIMG *pRVar1;
  int iVar2;
  J3DModelData *pModel;
  ulong uVar3;
  J3DModel *pJVar4;
  bool bVar5;
  
  pRVar1 = (ResTIMG *)
           dRes_control_c::getRes
                     ("Always",0x7e,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  iVar2 = mDoExt_3DlineMat1_c::init((mDoExt_3DlineMat1_c *)(param_1 + 0x1f30),1,200,pRVar1,0);
  if (iVar2 == 0) {
    bVar5 = false;
  }
  else {
    pModel = (J3DModelData *)
             dRes_control_c::getRes
                       ("Link",0x2e,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pModel == (J3DModelData *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_a_himo2.cpp",0xf5d,"modelData != 0");
      m_Do_printf::OSPanic("d_a_himo2.cpp",0xf5d,&DAT_8035be48);
    }
    pJVar4 = m_Do_ext::mDoExt_J3DModel__create(pModel,0,0x11020203);
    *(J3DModel **)(param_1 + 0x24b0) = pJVar4;
    if (*(int *)(param_1 + 0x24b0) == 0) {
      bVar5 = false;
    }
    else {
      pRVar1 = (ResTIMG *)
               dRes_control_c::getRes
                         ("Always",0x7e,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40
                         );
      iVar2 = mDoExt_3DlineMat1_c::init((mDoExt_3DlineMat1_c *)(param_1 + 0x1f98),5,0x20,pRVar1,0);
      if (iVar2 == 0) {
        bVar5 = false;
      }
      else {
        pRVar1 = (ResTIMG *)
                 dRes_control_c::getRes
                           ("Always",0x7e,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                            0x40);
        iVar2 = mDoExt_3DlineMat1_c::init((mDoExt_3DlineMat1_c *)(param_1 + 0x1fd8),1,0x10,pRVar1,0)
        ;
        bVar5 = iVar2 != 0;
      }
    }
  }
  return bVar5;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Type propagation algorithm not settling */
/* __stdcall daHimo2_Create(fopAc_ac_c *) */

undefined4 daHimo2_Create(fopAc_ac_c *param_1)

{
  daPy_lk_c *this;
  float fVar1;
  uint uVar2;
  undefined4 uVar3;
  create_request *pcVar4;
  cXyz local_30;
  float local_24;
  float local_20;
  float local_1c;
  
  this = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  if ((param_1->mCondition & Constructed) == 0) {
    if (param_1 != (fopAc_ac_c *)0x0) {
      fopAc_ac_c::fopAc_ac_c(param_1);
      Runtime.PPCEABI.H::__construct_array
                (&param_1[1].parent.parent.mDtTg.parent.mbAdded,::cXyz::cXyz,::cXyz::_cXyz,0xc,2);
      Runtime.PPCEABI.H::__construct_array
                (&param_1[1].parent.parent.mPi.mMtdTg.parent.parent.mpData,::himo2_s::himo2_s,
                 ::himo2_s::_himo2_s,0x24,100);
      Runtime.PPCEABI.H::__construct_array
                (&param_1[6].mDemoObjId,::himo2_s::himo2_s,::himo2_s::_himo2_s,0x24,100);
      param_1[0xc].parent.parent.mPi.parent.parent.mpNextNode =
           (node_class *)&::mDoExt_3DlineMat_c::__vt;
      param_1[0xc].parent.parent.mPi.parent.parent.mpNextNode =
           (node_class *)&mDoExt_3DlineMat1_c::__vt;
      param_1[0xc].mDwTg.parent.mpPrevNode = (node_class *)&::mDoExt_3DlineMat_c::__vt;
      param_1[0xc].mDwTg.parent.mpPrevNode = (node_class *)&mDoExt_3DlineMat1_c::__vt;
      param_1[0xc].mTevStr.mLightObj.mDir.x = (float)&::mDoExt_3DlineMat_c::__vt;
      param_1[0xc].mTevStr.mLightObj.mDir.x = (float)&mDoExt_3DlineMat1_c::__vt;
      *(cCcD_Stts__vtbl **)&param_1[0xc].mTevStr.mLightObj.field_0x60 = &cCcD_Stts::__vt;
      ::dCcD_GStts::dCcD_GStts((dCcD_GStts *)&param_1[0xc].mTevStr.mLightObj.field_0x64);
      *(dCcD_Stts__vtbl **)&param_1[0xc].mTevStr.mLightObj.field_0x60 = &::dCcD_Stts::__vt;
      *(undefined4 *)&param_1[0xc].mTevStr.mLightObj.field_0x64 = 0x8037ec40;
      dCcD_GObjInf::dCcD_GObjInf((dCcD_GObjInf *)&param_1[0xc].mTevStr.mColorC0.b);
      param_1[0xd].parent.parent.mpCtRq = (create_request *)&::cCcD_ShapeAttr::__vt;
      param_1[0xd].parent.parent.mpProf = (f_pc_profile__Profile_Actor *)&::cM3dGAab::__vt;
      *(undefined ***)&param_1[0xd].parent.parent.mLyTg.parent.mbAdded = &::cM3dGSph::__vt;
      param_1[0xd].parent.parent.mpCtRq = (create_request *)&::cCcD_SphAttr::__vt;
      *(undefined ***)&param_1[0xd].parent.parent.mLyTg.parent.mbAdded = &PTR_8039514c;
      param_1[0xc].mParentPcId = (int)&::dCcD_Sph::__vt;
      param_1[0xd].parent.parent.mpCtRq = (create_request *)&DAT_803899f8;
      *(undefined **)&param_1[0xd].parent.parent.mLyTg.parent.mbAdded = &DAT_80389a4c;
      ::dBgS_AcchCir::dBgS_AcchCir((dBgS_AcchCir *)&param_1[0xe].mTevStr.mLightObj.field_0x48);
      dBgS_Acch::dBgS_Acch((dBgS_Acch *)&param_1[0xe].mTevStr.mColorK0);
      param_1[0xe].mTevStr.mFogStartZ = (float)&::dBgS_ObjAcch::__vt;
      param_1[0xe].mTevStr.mFogEndZ = -5.134856e-39;
      *(undefined4 *)&param_1[0xe].mTevStr.mColpatPrev = 0x8037e9f0;
      *(undefined *)&param_1[0xe].mTevStr.mColpatBlend = 1;
    }
    param_1->mCondition = param_1->mCondition | Constructed;
  }
  uVar2 = f_op_actor_mng::fopAcM_entrySolidHeap
                    (param_1,CallbackCreateHeap,
                     (int)d_s_play::g_regHIO.mChild[0].mShorts[9] + 0x9050);
  fVar1 = _4333;
  if ((uVar2 & 0xff) == 0) {
    uVar3 = 5;
  }
  else {
    local_24 = _4333;
    local_20 = _4333;
    local_1c = _4333;
    pcVar4 = param_1[0xe].mAcTg.mpTagData;
    (pcVar4->mMtdTg).parent.parent.mpPrevNode = (node_class *)_4333;
    (pcVar4->mMtdTg).parent.parent.mpData = (undefined *)fVar1;
    (pcVar4->mMtdTg).parent.parent.mpNextNode = (node_class *)fVar1;
    param_1[1].parent.parent.mLnTg.parent.parent.mpNextNode =
         (node_class *)(d_s_play::g_regHIO.mChild[0].mShorts[1] + 0x60);
    ::daPy_py_c::getLeftHandPos(&local_30,&this->parent);
    (param_1->mCurrent).mPos.x = local_30.x;
    (param_1->mCurrent).mPos.y = local_30.y;
    (param_1->mCurrent).mPos.z = local_30.z;
    dBgS_Acch::Set((dBgS_Acch *)&param_1[0xe].mTevStr.mColorK0,&(param_1->mCurrent).mPos,
                   &(param_1->mNext).mPos,param_1,1,
                   (dBgS_AcchCir *)&param_1[0xe].mTevStr.mLightObj.field_0x48,&param_1->mVelocity,
                   (csXyz *)0x0,(csXyz *)0x0);
    ::dBgS_AcchCir::SetWall((dBgS_AcchCir *)&param_1[0xe].mTevStr.mLightObj.field_0x48,_5536,_5536);
    *(uint *)&param_1[0xe].mSetID = *(uint *)&param_1[0xe].mSetID & 0xfffffff7;
    param_1[0xe].mVelocityFwd = _5868 + d_s_play::g_regHIO.mChild[0].mFloats[7];
    param_1[0xe].mTevStr.mLightObj.mDir.z = _4333;
    DAT_803e4218 = mDoHIO_subRoot_c::createChild
                             (&mDoHIO_subRoot_c_803a5778,"ロープ",(JORReflexible *)&l_himo2HIO);
    rope_scale = _5557;
    ::dCcD_Stts::Init((dCcD_Stts *)&param_1[0xc].mTevStr.mLightObj.field_0x48,0xff,0xff,param_1);
    ::dCcD_Sph::Set((dCcD_Sph *)&param_1[0xc].mTevStr.mColorC0.b,&sph_src_5934);
    param_1[0xc].mOrig.mPos.y = (float)&param_1[0xc].mTevStr.mLightObj.field_0x48;
    btd = 0;
    dr = 0;
    uVar3 = 4;
  }
  return uVar3;
}


void __sinit_d_a_himo2_cpp(void)

{
  l_himo2HIO = &::himo2HIO_c::__vt;
  DAT_803e421a = 0;
  DAT_803e421c = 15000;
  DAT_803e421e = 1000;
  DAT_803e4220 = 600;
  DAT_803e4222 = 400;
  DAT_803e4224 = _5868;
  DAT_803e4228 = _4951;
  DAT_803e422c = _5533;
  DAT_803e4230 = _6143;
  DAT_803e4234 = _6144;
  Runtime.PPCEABI.H::__register_global_object(&l_himo2HIO,::himo2HIO_c::_himo2HIO_c,&_4210);
  return;
}

}

/* __thiscall himo2HIO_c::~himo2HIO_c(void) */

void __thiscall himo2HIO_c::_himo2HIO_c(himo2HIO_c *this)

{
  short in_r4;
  
  if ((this != (himo2HIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall daPy_py_c::checkPlayerGuard(void) const */

undefined4 __thiscall daPy_py_c::checkPlayerGuard(daPy_py_c *this)

{
  return 0;
}


/* __thiscall daPy_py_c::getRopeJumpLand(void) const */

uint __thiscall daPy_py_c::getRopeJumpLand(daPy_py_c *this)

{
  return this->field_0x2a4 & 0x200;
}


/* __thiscall std::fabsf(float) */

float __thiscall std::fabsf(std *this,float __x)

{
  return ABS(__x);
}


/* __thiscall daPy_py_c::checkRopeReadyAnime(void) const */

undefined4 __thiscall daPy_py_c::checkRopeReadyAnime(daPy_py_c *this)

{
  return 0;
}


/* __thiscall daPy_py_c::checkRopeForceEnd(void) const */

uint __thiscall daPy_py_c::checkRopeForceEnd(daPy_py_c *this)

{
  return this->field_0x2a4 & 0x40000000;
}


/* __thiscall himo2_s::~himo2_s(void) */

void __thiscall himo2_s::_himo2_s(himo2_s *this)

{
  short in_r4;
  
  if ((this != (himo2_s *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall himo2_s::himo2_s(void) */

void __thiscall himo2_s::himo2_s(himo2_s *this)

{
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daYkgr_c::show(void) */

void __thiscall daYkgr_c::show(daYkgr_c *this)

{
  if (_m_emitter == 0) {
    return;
  }
  *(uint *)(_m_emitter + 0x20c) = *(uint *)(_m_emitter + 0x20c) & 0xfffffffb;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daYkgr_c::hide(void) */

void __thiscall daYkgr_c::hide(daYkgr_c *this)

{
  if (_m_emitter == 0) {
    return;
  }
  *(uint *)(_m_emitter + 0x20c) = *(uint *)(_m_emitter + 0x20c) | 4;
  return;
}


namespace d_a_himo2 {

/* __stdcall dComIfGs_isEventBit(unsigned short) */

void dComIfGs_isEventBit(ushort param_1)

{
  dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,param_1);
  return;
}


/* WARNING: Unknown calling convention yet parameter storage is locked */
/* __stdcall dComIfGp_getStartStageName(void) */

char * dComIfGp_getStartStageName(void)

{
  return d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName;
}


/* __stdcall fopAcM_searchPlayerAngleY(fopAc_ac_c *) */

void fopAcM_searchPlayerAngleY(fopAc_ac_c *param_1)

{
  f_op_actor_mng::fopAcM_searchActorAngleY
            (param_1,(fopAc_ac_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor);
  return;
}


/* __stdcall dComIfGp_event_reset(void) */

void dComIfGp_event_reset(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mStateFlags =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mStateFlags | 8;
  return;
}


/* __stdcall mDoAud_seStart(unsigned long,
                            Vec *,
                            unsigned long,
                            signed char) */

void mDoAud_seStart(ulong param_1,cXyz *param_2,ulong param_3,sbyte param_4)

{
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,param_1,param_2,param_3,param_4,_4333,_4333,_4949,_4949,0);
  return;
}


/* __stdcall fopAcM_OnStatus(fopAc_ac_c *,
                             unsigned long) */

void fopAcM_OnStatus(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x1c4) = *(uint *)(param_1 + 0x1c4) | param_2;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fopAcM_seStartCurrent(fopAc_ac_c *,
                                   unsigned long,
                                   unsigned long) */

void fopAcM_seStartCurrent(int param_1,ulong param_2,ulong param_3)

{
  sbyte sVar1;
  
  sVar1 = d_com_inf_game::dComIfGp_getReverb((int)*(char *)(param_1 + 0x20a));
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,param_2,(cXyz *)(param_1 + 0x1f8),param_3,sVar1,_4333,_4333,
             _4949,_4949,0);
  return;
}

}

/* __thiscall dEvt_info_c::onCondition(unsigned short) */

void __thiscall dEvt_info_c::onCondition(dEvt_info_c *this,ushort param_1)

{
  this->mCondition = this->mCondition | param_1;
  return;
}


namespace d_a_himo2 {

/* __stdcall dComIfGs_onEventBit(unsigned short) */

void dComIfGs_onEventBit(ushort param_1)

{
  dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,param_1);
  return;
}


/* __stdcall fopAcM_OffStatus(fopAc_ac_c *,
                              unsigned long) */

void fopAcM_OffStatus(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x1c4) = *(uint *)(param_1 + 0x1c4) & ~param_2;
  return;
}


/* __stdcall fopAcM_GetID(void *) */

undefined4 fopAcM_GetID(int param_1)

{
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 4);
  }
  return 0xffffffff;
}


/* __stdcall fopAcM_GetParam(void *) */

undefined4 fopAcM_GetParam(int param_1)

{
  return *(undefined4 *)(param_1 + 0xb0);
}

}

/* __thiscall cXyz::operator +=(Vec const &) */

cXyz * __thiscall cXyz::operator___(cXyz *this,Vec *param_1)

{
  mtx::PSVECAdd(this,(cXyz *)param_1,this);
  return this;
}


namespace d_a_himo2 {

/* __stdcall fopAcM_GetName(void *) */

int fopAcM_GetName(int param_1)

{
  return (int)*(short *)(param_1 + 8);
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fopAcM_seStart(fopAc_ac_c *,
                            unsigned long,
                            unsigned long) */

void fopAcM_seStart(int param_1,ulong param_2,ulong param_3)

{
  sbyte sVar1;
  
  sVar1 = d_com_inf_game::dComIfGp_getReverb((int)*(char *)(param_1 + 0x20a));
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,param_2,(cXyz *)(param_1 + 0x260),param_3,sVar1,_4333,_4333,
             _4949,_4949,0);
  return;
}


/* __stdcall fopAcM_SetParam(void *,
                             unsigned long) */

void fopAcM_SetParam(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xb0) = param_2;
  return;
}

}

/* __thiscall dEvt_info_c::checkCommandDemoAccrpt(void) */

uint __thiscall dEvt_info_c::checkCommandDemoAccrpt(dEvt_info_c *this)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(2 - (uint)this->mCommand);
  return uVar1 >> 5 & 0xff;
}


namespace d_a_himo2 {

/* __stdcall daPy_getPlayerLinkActorClass(void) */

daPy_lk_c * daPy_getPlayerLinkActorClass(void)

{
  return d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor;
}

}

/* __thiscall dAttention_c::Lockon(void) */

undefined4 __thiscall dAttention_c::Lockon(dAttention_c *this)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  uVar1 = LockonTruth(this);
  if (((uVar1 & 0xff) == 0) && ((this->mFlags & 0x20000000) == 0)) {
    uVar2 = 0;
  }
  return uVar2;
}


namespace d_a_himo2 {

/* __stdcall dComIfGp_getAttention(void) */

undefined4 dComIfGp_getAttention(void)

{
  return 0x803ca410;
}

}

/* __thiscall std::sqrtf(float) */

float __thiscall std::sqrtf(std *this,float __x)

{
  double dVar1;
  double dVar2;
  
  dVar2 = (double)__x;
  if ((double)d_a_himo2::_4343 < dVar2) {
    dVar1 = 1.0 / SQRT(dVar2);
    dVar1 = d_a_himo2::_4391 * dVar1 * (d_a_himo2::_4392 - dVar2 * dVar1 * dVar1);
    dVar1 = d_a_himo2::_4391 * dVar1 * (d_a_himo2::_4392 - dVar2 * dVar1 * dVar1);
    dVar2 = (double)(float)(dVar2 * d_a_himo2::_4391 * dVar1 *
                                    (d_a_himo2::_4392 - dVar2 * dVar1 * dVar1));
  }
  return (float)dVar2;
}


namespace d_a_himo2 {

/* __stdcall dComIfGp_getCamera(int) */

camera_class * dComIfGp_getCamera(int param_1)

{
  return d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[param_1].mpCamera;
}


/* __stdcall dComIfGp_getPlayerCameraID(int) */

int dComIfGp_getPlayerCameraID(int param_1)

{
  return (int)*(char *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor + param_1 * 2 + 1)
  ;
}


/* __stdcall dComIfGp_getPlayer(int) */

daPy_lk_c * dComIfGp_getPlayer(int param_1)

{
  return d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor[param_1 * 2];
}

