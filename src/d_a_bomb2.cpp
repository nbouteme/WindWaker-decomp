#include <d_a_bomb2.h>
#include <d_kankyo.h>
#include <d_kankyo_wether.h>
#include <mtx/vec.h>
#include <SComponent/c_lib.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JPABase/JPAEmitter.h>
#include <d_a_bomb2.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <m_Do_ext.h>
#include <d_bg_s_acch.h>
#include <d_cc_d.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <f_op_actor_mng.h>
#include <d_com_inf_game.h>
#include <f_op_actor.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <mtx/mtxvec.h>
#include <SComponent/c_m3d_g_sph.h>
#include <SComponent/c_cc_s.h>
#include <d_cc_mass_s.h>
#include <d_camera.h>
#include <SComponent/c_bg_s.h>
#include <d_a_obj.h>
#include <d_a_sea.h>
#include <d_bg_s.h>
#include <SComponent/c_math.h>
#include <SComponent/c_xyz.h>
#include <d_particle.h>
#include <f_op_kankyo_mng.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_vibration.h>
#include <J3DGraphAnimator/J3DMaterialAttach.h>
#include <JKernel/JKRHeap.h>
#include <daBomb2/Env_c.h>
#include <Demangler/daBomb2/Act_c.h>
#include <daBomb2/FuseSparksCB_c.h>
#include <daBomb2/FuseSmokeCB_c.h>
#include <daObj.h>
#include <daBomb2/@unnamed@d_a_bomb2_cpp@.h>


namespace d_a_bomb2 {
undefined4 local_center$4864;
undefined4 fuse_offset$5178;
undefined1 init$4478;
undefined1 init$4866;
undefined1 init$5180;
undefined1 init$5592;
undefined1 init$5670;
}

namespace daBomb2 {

/* __thiscall Env_c::set(cXyz const &) */

void __thiscall Env_c::set(Env_c *this,cXyz *param_1)

{
  float fVar1;
  
  *(float *)this = param_1->x;
  *(float *)(this + 4) = param_1->y;
  *(float *)(this + 8) = param_1->z;
  fVar1 = d_a_bomb2::_4156;
  *(float *)(this + 4) = *(float *)(this + 4) + d_a_bomb2::_4156;
  *(undefined2 *)(this + 0xc) = 200;
  *(undefined2 *)(this + 0xe) = 200;
  *(undefined2 *)(this + 0x10) = 0xa0;
  *(float *)(this + 0x14) = d_a_bomb2::_4157;
  *(float *)(this + 0x18) = fVar1;
  d_kankyo::dKy_efplight_set((LIGHT_INFLUENCE *)this);
  *(float *)(this + 0x20) = param_1->x;
  *(float *)(this + 0x24) = param_1->y;
  *(float *)(this + 0x28) = param_1->z;
  fVar1 = d_a_bomb2::_4158;
  *(float *)(this + 0x2c) = d_a_bomb2::_4158;
  *(float *)(this + 0x30) = d_a_bomb2::_4159;
  *(float *)(this + 0x34) = fVar1;
  *(float *)(this + 0x38) = d_a_bomb2::_4160;
  *(float *)(this + 0x40) = fVar1;
  *(float *)(this + 0x3c) = d_a_bomb2::_4161;
  d_kankyo_wether::dKyw_pntwind_set((WIND_INFLUENCE *)(this + 0x20));
  this[0x4c] = (Env_c)0x0;
  *(float *)(this + 0x50) = d_a_bomb2::_4158;
  return;
}


/* __thiscall Env_c::clean(void) */

void __thiscall Env_c::clean(Env_c *this)

{
  d_kankyo::dKy_actor_addcol_set(0,0,0,d_a_bomb2::_4158);
  d_kankyo::dKy_efplight_cut((LIGHT_INFLUENCE *)this);
  d_kankyo_wether::dKyw_pntwind_cut(this + 0x20);
  return;
}


/* __thiscall Env_c::is_end(void) const */

uint __thiscall Env_c::is_end(Env_c *this)

{
  return 1 - (byte)this[0x4c] >> 0x1f;
}


/* WARNING: Removing unreachable block (ram,0x800dd5dc) */
/* WARNING: Removing unreachable block (ram,0x800dd654) */
/* __thiscall Env_c::proc(cXyz const &) */

void __thiscall Env_c::proc(Env_c *this,cXyz *param_1)

{
  camera_class *pcVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f31;
  double dVar5;
  float fVar6;
  undefined auStack8 [8];
  
  pcVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar5 = (double)d_a_bomb2::_4158;
  *(float *)(this + 0x14) = d_a_bomb2::_4199 * *(float *)(this + 0x50);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(this + 0x50);
  fVar6 = mtx::PSVECSquareDistance(param_1,&pcVar1->mEyePos);
  dVar4 = (double)fVar6;
  if ((double)d_a_bomb2::_4158 < dVar4) {
    dVar3 = 1.0 / SQRT(dVar4);
    dVar3 = d_a_bomb2::_4200 * dVar3 * (d_a_bomb2::_4201 - dVar4 * dVar3 * dVar3);
    dVar3 = d_a_bomb2::_4200 * dVar3 * (d_a_bomb2::_4201 - dVar4 * dVar3 * dVar3);
    dVar4 = (double)(float)(dVar4 * d_a_bomb2::_4200 * dVar3 *
                                    (d_a_bomb2::_4201 - dVar4 * dVar3 * dVar3));
  }
  if (dVar4 < (double)d_a_bomb2::_4199) {
    dVar5 = (double)(d_a_bomb2::_4159 - (float)((double)d_a_bomb2::_4202 * dVar4));
  }
  dVar4 = (double)(float)((double)*(float *)(this + 0x50) * dVar5);
  d_kankyo::dKy_actor_addcol_amb_set(dVar4,200,0xb4,100);
  d_kankyo::dKy_bg_addcol_amb_set(dVar4,0xb4,0xa0,0x3c);
  d_kankyo::dKy_bg_addcol_dif_set(dVar4,0xff,0xe1,0x78);
  if (this[0x4c] == (Env_c)0x1) {
    SComponent::cLib_addCalc
              ((float *)(this + 0x50),d_a_bomb2::_4158,d_a_bomb2::_4206,d_a_bomb2::_4207,
               d_a_bomb2::_4208);
    if (*(float *)(this + 0x50) <= d_a_bomb2::_4204) {
      this[0x4c] = (Env_c)((char)this[0x4c] + '\x01');
    }
  }
  else {
    if ((this[0x4c] == (Env_c)0x0) &&
       (SComponent::cLib_addCalc
                  ((float *)(this + 0x50),d_a_bomb2::_4159,d_a_bomb2::_4161,d_a_bomb2::_4203,
                   d_a_bomb2::_4204), d_a_bomb2::_4205 <= *(float *)(this + 0x50))) {
      this[0x4c] = (Env_c)((char)this[0x4c] + '\x01');
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


/* __thiscall FuseSmokeCB_c::setOldPosP(cXyz const *,
                                                 cXyz const *) */

void __thiscall FuseSmokeCB_c::setOldPosP(FuseSmokeCB_c *this,cXyz *param_1,cXyz *param_2)

{
  *(cXyz **)(this + 0xc) = param_1;
  *(cXyz **)(this + 0x10) = param_2;
  *(undefined2 *)(this + 4) = 0x14;
  return;
}


/* __thiscall FuseSmokeCB_c::deleteCallBack(void) */

void __thiscall FuseSmokeCB_c::deleteCallBack(FuseSmokeCB_c *this)

{
  int iVar1;
  
  if (*(int *)(this + 0x14) != 0) {
    *(undefined4 *)(*(int *)(this + 0x14) + 0x19c) = 0;
    iVar1 = *(int *)(this + 0x14);
    *(undefined4 *)(iVar1 + 0x60) = 0xffffffff;
    *(uint *)(iVar1 + 0x20c) = *(uint *)(iVar1 + 0x20c) | 1;
  }
  *(undefined4 *)(this + 0x14) = 0;
  return;
}


/* __thiscall FuseSmokeCB_c::execute(JPABaseEmitter *) */

void __thiscall FuseSmokeCB_c::execute(FuseSmokeCB_c *this,JPABaseEmitter *param_1)

{
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x800ddac0) */
/* WARNING: Removing unreachable block (ram,0x800ddab0) */
/* WARNING: Removing unreachable block (ram,0x800ddaa0) */
/* WARNING: Removing unreachable block (ram,0x800dda90) */
/* WARNING: Removing unreachable block (ram,0x800dda80) */
/* WARNING: Removing unreachable block (ram,0x800dda70) */
/* WARNING: Removing unreachable block (ram,0x800dda60) */
/* WARNING: Removing unreachable block (ram,0x800dda50) */
/* WARNING: Removing unreachable block (ram,0x800dda40) */
/* WARNING: Removing unreachable block (ram,0x800dda48) */
/* WARNING: Removing unreachable block (ram,0x800dda58) */
/* WARNING: Removing unreachable block (ram,0x800dda68) */
/* WARNING: Removing unreachable block (ram,0x800dda78) */
/* WARNING: Removing unreachable block (ram,0x800dda88) */
/* WARNING: Removing unreachable block (ram,0x800dda98) */
/* WARNING: Removing unreachable block (ram,0x800ddaa8) */
/* WARNING: Removing unreachable block (ram,0x800ddab8) */
/* WARNING: Removing unreachable block (ram,0x800ddac8) */
/* __thiscall FuseSmokeCB_c::executeAfter(JPABaseEmitter *) */

void __thiscall FuseSmokeCB_c::executeAfter(FuseSmokeCB_c *this,JPABaseEmitter *param_1)

{
  int iVar1;
  double dVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  short sVar7;
  undefined4 uVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  undefined8 in_f14;
  undefined8 in_f15;
  double dVar18;
  undefined8 in_f16;
  double dVar19;
  undefined8 in_f17;
  double dVar20;
  undefined8 in_f18;
  double dVar21;
  undefined8 in_f19;
  undefined8 in_f20;
  double dVar22;
  undefined8 in_f21;
  undefined8 in_f22;
  undefined8 in_f23;
  double dVar23;
  undefined8 in_f24;
  double dVar24;
  undefined8 in_f25;
  double dVar25;
  undefined8 in_f26;
  double dVar26;
  undefined8 in_f27;
  double dVar27;
  undefined8 in_f28;
  double dVar28;
  undefined8 in_f29;
  double dVar29;
  undefined8 in_f30;
  double dVar30;
  undefined8 in_f31;
  double dVar31;
  float fVar32;
  double local_160;
  undefined auStack280 [16];
  undefined auStack264 [16];
  undefined auStack248 [16];
  undefined auStack232 [16];
  undefined auStack216 [16];
  undefined auStack200 [16];
  undefined auStack184 [16];
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar8 = 0;
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
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  __psq_st0(auStack184,(int)((ulonglong)in_f20 >> 0x20),0);
  __psq_st1(auStack184,(int)in_f20,0);
  __psq_st0(auStack200,(int)((ulonglong)in_f19 >> 0x20),0);
  __psq_st1(auStack200,(int)in_f19,0);
  __psq_st0(auStack216,(int)((ulonglong)in_f18 >> 0x20),0);
  __psq_st1(auStack216,(int)in_f18,0);
  __psq_st0(auStack232,(int)((ulonglong)in_f17 >> 0x20),0);
  __psq_st1(auStack232,(int)in_f17,0);
  __psq_st0(auStack248,(int)((ulonglong)in_f16 >> 0x20),0);
  __psq_st1(auStack248,(int)in_f16,0);
  __psq_st0(auStack264,(int)((ulonglong)in_f15 >> 0x20),0);
  __psq_st1(auStack264,(int)in_f15,0);
  __psq_st0(auStack280,(int)((ulonglong)in_f14 >> 0x20),0);
  __psq_st1(auStack280,(int)in_f14,0);
  pfVar4 = *(float **)(this + 0xc);
  dVar31 = (double)*pfVar4;
  dVar30 = (double)pfVar4[1];
  dVar29 = (double)pfVar4[2];
  pfVar4 = *(float **)(this + 8);
  dVar28 = (double)*pfVar4;
  fVar32 = pfVar4[1];
  dVar27 = (double)fVar32;
  fVar3 = pfVar4[2];
  dVar26 = (double)fVar3;
  dVar18 = (double)DAT_8035ba74;
  (param_1->mGlobalTranslation).x = *pfVar4;
  (param_1->mGlobalTranslation).y = fVar32;
  (param_1->mGlobalTranslation).z = fVar3;
  fVar32 = mtx::PSVECSquareDistance(*(cXyz **)(this + 8),*(cXyz **)(this + 0xc));
  dVar11 = (double)fVar32;
  if ((double)d_a_bomb2::_4158 < dVar11) {
    dVar9 = 1.0 / SQRT(dVar11);
    dVar9 = d_a_bomb2::_4200 * dVar9 * (d_a_bomb2::_4201 - dVar11 * dVar9 * dVar9);
    dVar9 = d_a_bomb2::_4200 * dVar9 * (d_a_bomb2::_4201 - dVar11 * dVar9 * dVar9);
    dVar11 = (double)(float)(dVar11 * d_a_bomb2::_4200 * dVar9 *
                                      (d_a_bomb2::_4201 - dVar11 * dVar9 * dVar9));
  }
  sVar7 = (short)(int)(d_a_bomb2::_4337 +
                      d_a_bomb2::_4161 * (float)((double)d_a_bomb2::_4338 - dVar11));
  if (sVar7 < 10) {
    sVar7 = 10;
  }
  param_1->mLifeTime = sVar7;
  dVar11 = dVar28 - dVar31;
  dVar9 = dVar27 - dVar30;
  dVar2 = dVar26 - dVar29;
  pfVar4 = *(float **)(this + 0x10);
  dVar25 = (double)(float)(dVar18 * (double)(float)(dVar31 - (double)*pfVar4));
  dVar24 = (double)(float)(dVar18 * (double)(float)(dVar30 - (double)pfVar4[1]));
  dVar23 = (double)(float)(dVar18 * (double)(float)(dVar29 - (double)pfVar4[2]));
  fVar32 = mtx::PSVECSquareDistance(*(cXyz **)(this + 8),*(cXyz **)(this + 0xc));
  dVar12 = (double)fVar32;
  if ((double)d_a_bomb2::_4158 < dVar12) {
    dVar10 = 1.0 / SQRT(dVar12);
    dVar10 = d_a_bomb2::_4200 * dVar10 * (d_a_bomb2::_4201 - dVar12 * dVar10 * dVar10);
    dVar10 = d_a_bomb2::_4200 * dVar10 * (d_a_bomb2::_4201 - dVar12 * dVar10 * dVar10);
    dVar12 = (double)(float)(dVar12 * d_a_bomb2::_4200 * dVar10 *
                                      (d_a_bomb2::_4201 - dVar12 * dVar10 * dVar10));
  }
  dVar10 = (double)d_a_bomb2::_4159;
  if (dVar10 < (double)(float)(dVar12 * (double)DAT_8035ba70)) {
    dVar22 = (double)(float)(dVar10 / (double)(float)(dVar12 * (double)DAT_8035ba70));
    local_160 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 4) - (int)sVar7 ^ 0x80000000);
    iVar1 = (int)(dVar22 * (double)(float)(local_160 - d_a_bomb2::_4343));
    iVar6 = (int)(short)(sVar7 + (short)iVar1);
    dVar19 = (double)d_a_bomb2::_4339;
    dVar20 = (double)d_a_bomb2::_4340;
    dVar21 = (double)d_a_bomb2::_4341;
    dVar12 = dVar22;
    for (; dVar22 < dVar10; dVar22 = (double)(float)(dVar22 + dVar12)) {
      dVar17 = (double)(float)(dVar22 * dVar22);
      dVar16 = (double)(float)(dVar17 * dVar22);
      dVar15 = (double)(float)(dVar10 + (double)((float)(dVar19 * dVar16) - (float)(dVar20 * dVar17)
                                                ));
      dVar14 = (double)((float)(dVar21 * dVar16) + (float)(dVar20 * dVar17));
      dVar13 = (double)(float)(dVar22 + (double)(float)(dVar16 - (double)(float)(dVar19 * dVar17)));
      fVar32 = (float)(dVar16 - dVar17);
      dVar17 = (double)(fVar32 * (float)(dVar18 * (double)(float)dVar11) +
                       (float)(dVar13 * dVar25) +
                       (float)(dVar15 * dVar31) + (float)(dVar14 * dVar28));
      dVar16 = (double)(fVar32 * (float)(dVar18 * (double)(float)dVar9) +
                       (float)(dVar13 * dVar24) +
                       (float)(dVar15 * dVar30) + (float)(dVar14 * dVar27));
      dVar13 = (double)(fVar32 * (float)(dVar18 * (double)(float)dVar2) +
                       (float)(dVar13 * dVar23) +
                       (float)(dVar15 * dVar29) + (float)(dVar14 * dVar26));
      param_1->mLifeTime = (short)iVar6;
      iVar5 = JPABaseEmitter::createParticle(param_1);
      if (iVar5 != 0) {
        *(float *)(iVar5 + 0x10) = (float)dVar17;
        *(float *)(iVar5 + 0x14) = (float)dVar16;
        *(float *)(iVar5 + 0x18) = (float)dVar13;
      }
      iVar6 = iVar6 + iVar1;
    }
  }
  *(short *)(this + 4) = sVar7;
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  __psq_l0(auStack40,uVar8);
  __psq_l1(auStack40,uVar8);
  __psq_l0(auStack56,uVar8);
  __psq_l1(auStack56,uVar8);
  __psq_l0(auStack72,uVar8);
  __psq_l1(auStack72,uVar8);
  __psq_l0(auStack88,uVar8);
  __psq_l1(auStack88,uVar8);
  __psq_l0(auStack104,uVar8);
  __psq_l1(auStack104,uVar8);
  __psq_l0(auStack120,uVar8);
  __psq_l1(auStack120,uVar8);
  __psq_l0(auStack136,uVar8);
  __psq_l1(auStack136,uVar8);
  __psq_l0(auStack152,uVar8);
  __psq_l1(auStack152,uVar8);
  __psq_l0(auStack168,uVar8);
  __psq_l1(auStack168,uVar8);
  __psq_l0(auStack184,uVar8);
  __psq_l1(auStack184,uVar8);
  __psq_l0(auStack200,uVar8);
  __psq_l1(auStack200,uVar8);
  __psq_l0(auStack216,uVar8);
  __psq_l1(auStack216,uVar8);
  __psq_l0(auStack232,uVar8);
  __psq_l1(auStack232,uVar8);
  __psq_l0(auStack248,uVar8);
  __psq_l1(auStack248,uVar8);
  __psq_l0(auStack264,uVar8);
  __psq_l1(auStack264,uVar8);
  __psq_l0(auStack280,uVar8);
  __psq_l1(auStack280,uVar8);
  return;
}


/* __thiscall FuseSmokeCB_c::draw(JPABaseEmitter *) */

void __thiscall FuseSmokeCB_c::draw(FuseSmokeCB_c *this,JPABaseEmitter *param_1)

{
  return;
}


/* __thiscall FuseSmokeCB_c::setup(JPABaseEmitter *,
                                            cXyz const *,
                                            csXyz const *,
                                            signed char) */

void __thiscall
FuseSmokeCB_c::setup
          (FuseSmokeCB_c *this,JPABaseEmitter *param_1,cXyz *param_2,csXyz *param_3,char param_4)

{
  *(cXyz **)(this + 8) = param_2;
  *(JPABaseEmitter **)(this + 0x14) = param_1;
  return;
}


/* __thiscall FuseSparksCB_c::deleteCallBack(void) */

void __thiscall FuseSparksCB_c::deleteCallBack(FuseSparksCB_c *this)

{
  int iVar1;
  
  if (*(int *)(this + 8) != 0) {
    *(undefined4 *)(*(int *)(this + 8) + 0x19c) = 0;
    iVar1 = *(int *)(this + 8);
    *(undefined4 *)(iVar1 + 0x60) = 0xffffffff;
    *(uint *)(iVar1 + 0x20c) = *(uint *)(iVar1 + 0x20c) | 1;
  }
  *(undefined4 *)(this + 8) = 0;
  return;
}


/* __thiscall FuseSparksCB_c::execute(JPABaseEmitter *) */

void __thiscall FuseSparksCB_c::execute(FuseSparksCB_c *this,JPABaseEmitter *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  JSUPtrLink *pJVar4;
  float *pfVar5;
  undefined *puVar6;
  JSUPtrLink *pJVar7;
  
  pfVar5 = *(float **)(this + 4);
  fVar1 = *pfVar5;
  fVar2 = pfVar5[1];
  fVar3 = pfVar5[2];
  (param_1->mGlobalTranslation).x = fVar1;
  (param_1->mGlobalTranslation).y = fVar2;
  (param_1->mGlobalTranslation).z = fVar3;
  pJVar7 = (param_1->mActiveParticles).mpHead;
  while (pJVar7 != (JSUPtrLink *)0x0) {
    pJVar4 = pJVar7->mpNext;
    puVar6 = pJVar7->mpData;
    *(float *)(puVar6 + 0x10) = fVar1;
    *(float *)(puVar6 + 0x14) = fVar2;
    *(float *)(puVar6 + 0x18) = fVar3;
    pJVar7 = pJVar4;
  }
  return;
}


/* __thiscall FuseSparksCB_c::draw(JPABaseEmitter *) */

void __thiscall FuseSparksCB_c::draw(FuseSparksCB_c *this,JPABaseEmitter *param_1)

{
  return;
}


/* __thiscall FuseSparksCB_c::setup(JPABaseEmitter *,
                                             cXyz const *,
                                             csXyz const *,
                                             signed char) */

void __thiscall
FuseSparksCB_c::setup
          (FuseSparksCB_c *this,JPABaseEmitter *param_1,cXyz *param_2,csXyz *param_3,char param_4)

{
  *(cXyz **)(this + 4) = param_2;
  *(JPABaseEmitter **)(this + 8) = param_1;
  return;
}


/* __thiscall Act_c::solidHeapCB(fopAc_ac_c *) */

undefined __thiscall Act_c::solidHeapCB(Act_c *this,fopAc_ac_c *param_1)

{
  undefined uVar1;
  
  uVar1 = create_heap(this);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall Act_c::create_heap_nut(void) */

undefined4 __thiscall Act_c::create_heap_nut(Act_c *this)

{
  undefined *arcName;
  J3DModelData *pModel;
  ulong uVar1;
  J3DModel *pJVar2;
  J3DAnmTransform *pJVar3;
  int iVar4;
  J3DAnmTevRegKey *pJVar5;
  int iVar6;
  undefined4 uVar7;
  
  arcName = @unnamed@d_a_bomb2_cpp@::L_attr;
  pModel = (J3DModelData *)
           dRes_control_c::getRes
                     (@unnamed@d_a_bomb2_cpp@::L_attr,0xc,
                      d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pModel == (J3DModelData *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_a_bomb2.cpp",0x303,"mdl_data != 0");
    m_Do_printf::OSPanic("d_a_bomb2.cpp",0x303,&DAT_8035bb06);
  }
  pJVar2 = m_Do_ext::mDoExt_J3DModel__create(pModel,0x80000,0x11000022);
  *(J3DModel **)(this + 0x298) = pJVar2;
  pJVar3 = (J3DAnmTransform *)
           dRes_control_c::getRes
                     (arcName,7,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pJVar3 == (J3DAnmTransform *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_a_bomb2.cpp",0x30d,"bck_data != 0");
    m_Do_printf::OSPanic("d_a_bomb2.cpp",0x30d,&DAT_8035bb06);
  }
  iVar4 = ::mDoExt_bckAnm::init
                    ((mDoExt_bckAnm *)(this + 0x29c),pModel,pJVar3,true,Once,d_a_bomb2::_4159,0,-1,
                     false);
  pJVar5 = (J3DAnmTevRegKey *)
           dRes_control_c::getRes
                     (arcName,0x10,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pJVar5 == (J3DAnmTevRegKey *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_a_bomb2.cpp",0x314,"brk_data != 0");
    m_Do_printf::OSPanic("d_a_bomb2.cpp",0x314,&DAT_8035bb06);
  }
  iVar6 = ::mDoExt_brkAnm::init
                    ((mDoExt_brkAnm *)(this + 0x2ac),pModel,pJVar5,true,Once,d_a_bomb2::_4159,0,-1,
                     false,0);
  uVar7 = 0;
  if (((*(int *)(this + 0x298) != 0) && (iVar4 != 0)) && (iVar6 != 0)) {
    uVar7 = 1;
  }
  return uVar7;
}


/* __thiscall Act_c::create_heap(void) */

void __thiscall Act_c::create_heap(Act_c *this)

{
  create_heap_nut(this);
  return;
}


/* __thiscall Act_c::crr_init(void) */

void __thiscall Act_c::crr_init(Act_c *this)

{
  float fVar1;
  
  ::dBgS_AcchCir::SetWall((dBgS_AcchCir *)(this + 0x488),d_a_bomb2::_4448,d_a_bomb2::_4448);
  dBgS_Acch::Set((dBgS_Acch *)(this + 0x2c4),(cXyz *)(this + 0x1f8),(cXyz *)(this + 0x1e4),
                 (fopAc_ac_c *)this,1,(dBgS_AcchCir *)(this + 0x488),(cXyz *)(this + 0x220),
                 (csXyz *)(this + 0x204),(csXyz *)(this + 0x20c));
  *(uint *)(this + 0x2ec) = *(uint *)(this + 0x2ec) & 0xfffffbff;
  *(uint *)(this + 0x2ec) = *(uint *)(this + 0x2ec) & 0xfffffff7;
  *(float *)(this + 900) = d_a_bomb2::_4449;
  *(uint *)(this + 0x2ec) = *(uint *)(this + 0x2ec) | 0x2000;
  fVar1 = d_a_bomb2::_4450;
  *(float *)(this + 0x51c) = d_a_bomb2::_4450;
  *(float *)(this + 0x520) = fVar1;
  this[0x524] = (Act_c)0x0;
  this[0x525] = (Act_c)0x0;
  this[0x526] = (Act_c)0x0;
  *(float *)(this + 0x528) = fVar1;
  return;
}


/* __thiscall Act_c::cc_init(void) */

void __thiscall Act_c::cc_init(Act_c *this)

{
  ::dCcD_Stts::Init((dCcD_Stts *)(this + 0x52c),200,0xff,(fopAc_ac_c *)this);
  ::dCcD_Sph::Set((dCcD_Sph *)(this + 0x568),(dCcD_SrcSph *)&M_sph_src);
  *(Act_c **)(this + 0x5ac) = this + 0x52c;
  return;
}


/* __thiscall Act_c::start_explode_instant(void) */

void __thiscall Act_c::start_explode_instant(Act_c *this)

{
  char cVar1;
  
  cVar1 = chk_water_in(this);
  if (cVar1 == '\0') {
    eff_explode(this);
  }
  else {
    eff_explode_water(this);
  }
  mode_explode_init(this);
  return;
}


/* __thiscall Act_c::start_explode_interval(void) */

void __thiscall Act_c::start_explode_interval(Act_c *this)

{
  eff_fuse_start(this);
  set_nut_exp_interval(this);
  mode_wait_init(this);
  return;
}


/* __thiscall Act_c::start_carry(void) */

void __thiscall Act_c::start_carry(Act_c *this)

{
  mode_carry_init(this);
  return;
}


/* __thiscall Act_c::start_proc_call(void) */

void __thiscall Act_c::start_proc_call(Act_c *this)

{
  Prm_e in_r6;
  undefined8 uVar1;
  
  if (d_a_bomb2::init_4478 == '\0') {
    d_a_bomb2::start_proc_4474 = d_a_bomb2::_4475;
    DAT_8038a290 = DAT_8038a26c;
    DAT_8038a294 = PTR_start_explode_instant_8038a270;
    DAT_8038a298 = d_a_bomb2::_4476;
    DAT_8038a29c = DAT_8038a278;
    DAT_8038a2a0 = PTR_start_explode_interval_8038a27c;
    DAT_8038a2a4 = d_a_bomb2::_4477;
    DAT_8038a2a8 = DAT_8038a284;
    DAT_8038a2ac = PTR_start_carry_8038a288;
    d_a_bomb2::init_4478 = '\x01';
  }
  uVar1 = ::daObj::PrmAbstract((daObj *)this,(fopAc_ac_c *)&DAT_00000002,0,in_r6);
  Runtime.PPCEABI.H::__ptmf_scall
            ((PTMF *)(&d_a_bomb2::start_proc_4474 + (int)((ulonglong)uVar1 >> 0x20) * 3),this,
             (void *)uVar1);
  return;
}


/* __thiscall Act_c::create_init(void) */

void __thiscall Act_c::create_init(Act_c *this)

{
  float fVar1;
  int iVar2;
  Prm_e in_r6;
  
  crr_init(this);
  cc_init(this);
  *(int *)(this + 0x22c) = *(int *)(this + 0x298) + 0x24;
  f_op_actor_mng::fopAcM_setCullSizeBox
            ((fopAc_ac_c *)this,(double)d_a_bomb2::_4497,(double)d_a_bomb2::_4158,
             (double)d_a_bomb2::_4497,(double)d_a_bomb2::_4498,(double)d_a_bomb2::_4499,
             (double)d_a_bomb2::_4498);
  *(float *)(this + 0x248) = d_a_bomb2::_4337;
  iVar2 = ::daObj::PrmAbstract((daObj *)this,(fopAc_ac_c *)&DAT_00000001,8,in_r6);
  if (iVar2 == 0) {
    on_carry(this);
  }
  else {
    off_carry(this);
  }
  *(undefined4 *)(this + 600) = DAT_8035ba5c;
  *(undefined4 *)(this + 0x25c) = DAT_8035ba60;
  bgCrrPos(this);
  fVar1 = d_a_bomb2::_4158;
  *(float *)(this + 0x224) = d_a_bomb2::_4158;
  *(float *)(this + 0x254) = fVar1;
  *(undefined4 *)(this + 0x1f8) = *(undefined4 *)(this + 0x1d0);
  *(undefined4 *)(this + 0x1fc) = *(undefined4 *)(this + 0x1d4);
  *(undefined4 *)(this + 0x200) = *(undefined4 *)(this + 0x1d8);
  init_mtx(this);
  *(int *)(this + 0x738) = (int)DAT_8035ba58;
  this[0x740] = (Act_c)0x0;
  this[0x741] = (Act_c)0x0;
  this[0x742] = (Act_c)0x0;
  this[0x743] = (Act_c)0x0;
  *(float *)(this + 0x748) = ::cXyz::Zero.x;
  *(float *)(this + 0x74c) = ::cXyz::Zero.y;
  *(float *)(this + 0x750) = ::cXyz::Zero.z;
  start_proc_call(this);
  return;
}


/* __thiscall Act_c::_create(void) */

PhaseState __thiscall Act_c::_create(Act_c *this)

{
  PhaseState PVar1;
  uint uVar2;
  
  if ((*(uint *)(this + 0x1c8) & 8) == 0) {
    if (this != (Act_c *)0x0) {
      Act_c(this);
    }
    *(uint *)(this + 0x1c8) = *(uint *)(this + 0x1c8) | 8;
  }
  PVar1 = d_com_inf_game::dComIfG_resLoad
                    ((request_of_phase_process_class *)(this + 0x290),
                     @unnamed@d_a_bomb2_cpp@::L_attr);
  if (PVar1 == cPhs_COMPLEATE_e) {
    uVar2 = f_op_actor_mng::fopAcM_entrySolidHeap((fopAc_ac_c *)this,solidHeapCB,DAT_8035ba54);
    if ((uVar2 & 0xff) == 0) {
      PVar1 = cPhs_ERROR_e;
    }
    else {
      create_init(this);
    }
  }
  return PVar1;
}


/* __thiscall Act_c::Act_c(void) */

void __thiscall Act_c::Act_c(Act_c *this)

{
  Act_c *pAVar1;
  
  fopAc_ac_c::fopAc_ac_c((fopAc_ac_c *)this);
  *(undefined ***)(this + 0x29c) = &::mDoExt_baseAnm::__vt;
  *(undefined4 *)(this + 0x2a0) = 0;
  *(undefined ***)(this + 0x29c) = &::mDoExt_bckAnm::__vt;
  *(undefined4 *)(this + 0x2a8) = 0;
  *(undefined ***)(this + 0x2ac) = &::mDoExt_baseAnm::__vt;
  *(undefined4 *)(this + 0x2b0) = 0;
  *(undefined ***)(this + 0x2ac) = &::mDoExt_brkAnm::__vt;
  *(undefined4 *)(this + 0x2b8) = 0;
  *(undefined4 *)(this + 700) = 0;
  dBgS_Acch::dBgS_Acch((dBgS_Acch *)(this + 0x2c4));
  *(undefined1 **)(this + 0x2d4) = &dBgS_BombAcch::__vt;
  *(undefined **)(this + 0x2d8) = &DAT_8038a0c8;
  *(undefined **)(this + 0x2e4) = &DAT_8038a0d4;
  this[0x2e0] = (Act_c)0x1;
  ::dBgS_AcchCir::dBgS_AcchCir((dBgS_AcchCir *)(this + 0x488));
  ::cBgS_GndChk::cBgS_GndChk((cBgS_GndChk *)(this + 0x4c8));
  *(undefined ***)(this + 0x508) = &::cBgS_PolyPassChk::__vt;
  *(undefined ***)(this + 0x508) = &::dBgS_PolyPassChk::__vt;
  this[0x50c] = (Act_c)0x0;
  this[0x50d] = (Act_c)0x0;
  this[0x50e] = (Act_c)0x0;
  this[0x50f] = (Act_c)0x0;
  this[0x510] = (Act_c)0x0;
  this[0x511] = (Act_c)0x0;
  this[0x512] = (Act_c)0x0;
  *(undefined ***)(this + 0x514) = &::cBgS_GrpPassChk::__vt;
  *(undefined ***)(this + 0x514) = &::dBgS_GrpPassChk::__vt;
  *(undefined4 *)(this + 0x518) = 1;
  *(undefined ***)(this + 0x508) = &::dBgS_Chk::__vt;
  *(undefined ***)(this + 0x514) = &PTR_80371f68;
  *(cBgS_Chk__vtbl **)(this + 0x4d8) = &::dBgS_GndChk::__vt;
  *(cBgS_PolyInfo__vtbl **)(this + 0x4e8) = &cBgS_PolyInfo__vtbl_80371f08;
  *(undefined ***)(this + 0x508) = &PTR_80371f14;
  *(undefined ***)(this + 0x514) = &PTR_80371f20;
  (((cBgS_GndChk *)(this + 0x4c8))->parent).mpPolyPassChk = (cBgS_PolyPassChk *)(this + 0x508);
  pAVar1 = this + 0x508;
  if (pAVar1 != (Act_c *)0x0) {
    pAVar1 = this + 0x514;
  }
  *(Act_c **)(this + 0x4cc) = pAVar1;
  *(cBgS_Chk__vtbl **)(this + 0x4d8) = &::dBgS_ObjGndChk::__vt;
  *(cBgS_PolyInfo__vtbl **)(this + 0x4e8) = &cBgS_PolyInfo__vtbl_80371ed8;
  *(cBgS_PolyPassChk__vtbl **)(this + 0x508) = &cBgS_PolyPassChk__vtbl_80371ee4;
  *(cBgS_GrpPassChk__vtbl **)(this + 0x514) = &cBgS_GrpPassChk__vtbl_80371ef0;
  this[0x50c] = (Act_c)0x1;
  *(undefined1 **)(this + 0x4d8) = &dBgS_ObjGndChk_Yogan::__vt;
  *(undefined **)(this + 0x4e8) = &DAT_80371e60;
  *(undefined **)(this + 0x508) = &DAT_80371e6c;
  *(undefined **)(this + 0x514) = &DAT_80371e78;
  *(uint *)(this + 0x518) = *(uint *)(this + 0x518) & 0xfffffffe;
  *(uint *)(this + 0x518) = *(uint *)(this + 0x518) | 4;
  *(cCcD_Stts__vtbl **)(this + 0x544) = &cCcD_Stts::__vt;
  ::dCcD_GStts::dCcD_GStts((dCcD_GStts *)(this + 0x548));
  *(dCcD_Stts__vtbl **)(this + 0x544) = &::dCcD_Stts::__vt;
  *(undefined4 *)(this + 0x548) = 0x8037ec40;
  dCcD_GObjInf::dCcD_GObjInf((dCcD_GObjInf *)(this + 0x568));
  *(undefined ***)(this + 0x67c) = &::cCcD_ShapeAttr::__vt;
  *(cM3dGAab__vtbl **)(this + 0x678) = &::cM3dGAab::__vt;
  *(undefined ***)(this + 0x690) = &::cM3dGSph::__vt;
  *(undefined ***)(this + 0x67c) = &::cCcD_SphAttr::__vt;
  *(undefined ***)(this + 0x690) = &PTR_8039514c;
  *(undefined1 **)(this + 0x5a4) = &::dCcD_Sph::__vt;
  *(undefined **)(this + 0x67c) = &DAT_803899f8;
  *(undefined **)(this + 0x690) = &DAT_80389a4c;
  *(undefined1 **)(this + 0x69c) = &::JPACallBackBase<JPABaseEmitter*>::__vt;
  *(undefined1 **)(this + 0x69c) = &::dPa_levelEcallBack::__vt;
  *(undefined1 **)(this + 0x69c) = &FuseSmokeCB_c::__vt;
  *(undefined1 **)(this + 0x6b4) = &::JPACallBackBase<JPABaseEmitter*>::__vt;
  *(undefined1 **)(this + 0x6b4) = &::dPa_levelEcallBack::__vt;
  *(undefined1 **)(this + 0x6b4) = &FuseSparksCB_c::__vt;
  return;
}


/* __thiscall Act_c::_delete(void) */

undefined4 __thiscall Act_c::_delete(Act_c *this)

{
  eff_fuse_end(this);
  Env_c::clean((Env_c *)(this + 0x6e4));
  d_com_inf_game::dComIfG_resDelete
            ((request_of_phase_process_class *)(this + 0x290),@unnamed@d_a_bomb2_cpp@::L_attr);
  return 1;
}


/* __thiscall Act_c::set_mtx(void) */

void __thiscall Act_c::set_mtx(Act_c *this)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x298);
  *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(this + 0x214);
  *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(this + 0x218);
  *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(this + 0x21c);
  mtx::PSMTXTrans((double)*(float *)(this + 0x1f8),(double)*(float *)(this + 0x1fc),
                  (double)*(float *)(this + 0x200),&mDoMtx_stack_c::now);
  mtx::PSMTXConcat(&mDoMtx_stack_c::now,(MTX34 *)(this + 0x754),&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_ZXYrotM
            (&mDoMtx_stack_c::now,(int)*(short *)(this + 0x20c),(int)*(short *)(this + 0x20e),
             (int)*(short *)(this + 0x210));
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)(this + 0x298) + 0x24));
  eff_fuse_move(this);
  return;
}


/* __thiscall Act_c::init_mtx(void) */

void __thiscall Act_c::init_mtx(Act_c *this)

{
  tensor_init(this);
  eff_fuse_init(this);
  set_mtx(this);
  return;
}


/* WARNING: Removing unreachable block (ram,0x800de720) */
/* __thiscall Act_c::cc_set(void) */

void __thiscall Act_c::cc_set(Act_c *this)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined8 in_f31;
  double dVar5;
  cXyz local_28;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar3 = countLeadingZeros(2 - *(int *)(this + 0x694));
  uVar2 = countLeadingZeros(3 - *(int *)(this + 0x694));
  bVar1 = true;
  dVar5 = (double)d_a_bomb2::_4885;
  local_28.x = *(float *)(this + 0x1f8);
  local_28.y = *(float *)(this + 0x1fc);
  local_28.z = *(float *)(this + 0x200);
  if ((uVar3 >> 5 & 0xff) == 0) {
    if ((uVar2 >> 5 & 0xff) == 0) {
      dVar5 = (double)(d_a_bomb2::_4448 * *(float *)(this + 0x214));
      if (d_a_bomb2::init_4866 == '\0') {
        d_a_bomb2::local_center_4864 = d_a_bomb2::_4158;
        DAT_803e36b0 = d_a_bomb2::_4448;
        DAT_803e36b4 = d_a_bomb2::_4158;
        Runtime.PPCEABI.H::__register_global_object
                  (&d_a_bomb2::local_center_4864,::cXyz::_cXyz,&d_a_bomb2::_4865);
        d_a_bomb2::init_4866 = '\x01';
      }
      mtx::PSMTXCopy((MTX34 *)(*(int *)(this + 0x298) + 0x24),&mDoMtx_stack_c::now);
      mDoMtx_stack_c::scaleM
                (*(float *)(this + 0x214),*(float *)(this + 0x218),*(float *)(this + 0x21c));
      mtx::PSMTXMultVec(&mDoMtx_stack_c::now,(cXyz *)&d_a_bomb2::local_center_4864,&local_28);
    }
    else {
      bVar1 = false;
    }
  }
  else {
    if (0 < *(int *)(this + 0x73c)) {
      *(int *)(this + 0x73c) = *(int *)(this + 0x73c) + -1;
    }
    if (*(int *)(this + 0x73c) < 1) {
      bVar1 = false;
    }
  }
  if (bVar1) {
    ::dCcD_GStts::Move((dCcD_GStts *)(this + 0x548));
    ::cM3dGSph::SetR((cM3dGSph *)(this + 0x680),(float)dVar5);
    ::cM3dGSph::SetC((cM3dGSph *)(this + 0x680),&local_28);
    cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)(this + 0x568));
    dCcMassS_Mng::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng,
                      (cCcD_Obj *)(this + 0x568),3);
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* __thiscall Act_c::camera_lockoff(void) const */

void __thiscall Act_c::camera_lockoff(Act_c *this)

{
  uint uVar1;
  
  if (this == (Act_c *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(uint *)(this + 4);
  }
  dCamera_c::ForceLockOff
            (&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo
               [(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCamera].mpCamera)->mBody,uVar1);
  return;
}


/* __thiscall Act_c::posMoveF(void) */

void __thiscall Act_c::posMoveF(Act_c *this)

{
  float fVar1;
  cM3dGPla *pcVar2;
  float fVar3;
  
  fVar3 = mtx::PSVECSquareMag((cXyz *)(this + 0x748));
  if (fVar3 <= d_a_bomb2::_4204) {
    f_op_actor_mng::fopAcM_posMoveF((fopAc_ac_c *)this,(cXyz *)(this + 0x52c));
  }
  else {
    pcVar2 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                             (uint)*(ushort *)(this + 0x3ae),(uint)*(ushort *)(this + 0x3ac));
    if (pcVar2 == (cM3dGPla *)0x0) {
      pcVar2 = (cM3dGPla *)0x0;
      fVar3 = d_a_bomb2::_4158;
      fVar1 = d_a_bomb2::_4158;
    }
    else {
      fVar3 = d_a_bomb2::_4916;
      fVar1 = JKernel::JMath::jmaCosTable[0xa4f >> (JKernel::JMath::jmaSinShift & 0x3f)];
    }
    ::daObj::posMoveF_grade
              ((fopAc_ac_c *)this,(cXyz *)(this + 0x52c),(cXyz *)(this + 0x748),DAT_8035ba80,
               DAT_8035ba84,(cXyz *)pcVar2,fVar3,fVar1,(cXyz *)0x0);
  }
  return;
}


/* __thiscall Act_c::bgCrrPos(void) */

void __thiscall Act_c::bgCrrPos(Act_c *this)

{
  dBgS_Acch::CrrPos((dBgS_Acch *)(this + 0x2c4),&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS);
  bgCrrPos_lava(this);
  bgCrrPos_water(this);
  setRoomInfo(this);
  return;
}


/* __thiscall Act_c::bgCrrPos_lava(void) */

void __thiscall Act_c::bgCrrPos_lava(Act_c *this)

{
  float fVar1;
  double dVar2;
  
  fVar1 = d_a_bomb2::_4159 + *(float *)(this + 0x1e8);
  *(undefined4 *)(this + 0x4ec) = *(undefined4 *)(this + 0x1f8);
  *(float *)(this + 0x4f0) = fVar1;
  *(undefined4 *)(this + 0x4f4) = *(undefined4 *)(this + 0x200);
  dVar2 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                    (cBgS_GndChk *)(this + 0x4c8));
  *(float *)(this + 0x51c) = (float)dVar2;
  return;
}


/* WARNING: Removing unreachable block (ram,0x800de9ec) */
/* __thiscall Act_c::bgCrrPos_water(void) */

void __thiscall Act_c::bgCrrPos_water(Act_c *this)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  Act_c AVar4;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar7 = (double)*(float *)(this + 0x480);
  uVar2 = d_a_sea::daSea_ChkArea(*(float *)(this + 0x1f8),*(float *)(this + 0x200));
  dVar6 = (double)d_a_sea::daSea_calcWave
                            ((double)*(float *)(this + 0x1f8),(double)*(float *)(this + 0x200));
  uVar3 = *(uint *)(this + 0x2ec) >> 0xc & 1;
  bVar1 = false;
  if (((uVar2 & 0xff) != 0) && ((double)*(float *)(this + 0x1fc) < dVar6)) {
    bVar1 = true;
  }
  AVar4 = (Act_c)0x0;
  if ((uVar3 != 0) && (bVar1)) {
    if (dVar7 <= dVar6) {
      uVar3 = 0;
    }
    else {
      bVar1 = false;
    }
  }
  if (uVar3 == 0) {
    if (bVar1) {
      *(float *)(this + 0x520) = (float)dVar6;
      AVar4 = (Act_c)0x1;
      this[0x526] = (Act_c)0x1;
    }
    else {
      *(float *)(this + 0x520) = d_a_bomb2::_4450;
      this[0x526] = (Act_c)0x0;
    }
  }
  else {
    *(float *)(this + 0x520) = (float)dVar7;
    AVar4 = (Act_c)0x1;
    this[0x526] = (Act_c)0x0;
  }
  this[0x525] = AVar4;
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* __thiscall Act_c::chk_water_in(void) const */

Act_c __thiscall Act_c::chk_water_in(Act_c *this)

{
  return this[0x525];
}


/* __thiscall Act_c::chk_lava_in(void) const */

uint __thiscall Act_c::chk_lava_in(Act_c *this)

{
  if (d_a_bomb2::_4450 == *(float *)(this + 0x51c)) {
    return 0;
  }
  return ((uint)(byte)((*(float *)(this + 0x1fc) < *(float *)(this + 0x51c)) << 3) << 0x1c) >> 0x1f;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall Act_c::setRoomInfo(void) */

void __thiscall Act_c::setRoomInfo(Act_c *this)

{
  Act_c AVar1;
  Act_c AVar2;
  
  AVar1 = (Act_c)dStage_roomControl_c::mStayNo;
  if (d_a_bomb2::_4450 != *(float *)(this + 0x358)) {
    AVar1 = (Act_c)dBgS::GetRoomId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                                   (cBgS_PolyInfo *)(this + 0x3ac));
    AVar2 = (Act_c)dBgS::GetPolyColor(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                                      (cBgS_PolyInfo *)(this + 0x3ac));
    this[0x1b6] = AVar2;
  }
  this[0x1b5] = AVar1;
  this[0x54e] = AVar1;
  this[0x20a] = AVar1;
  return;
}


/* WARNING: Removing unreachable block (ram,0x800debb4) */
/* __thiscall Act_c::bound(float) */

void __thiscall Act_c::bound(Act_c *this,float param_1)

{
  float fVar1;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar3 = (double)param_1;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if ((*(uint *)(this + 0x2ec) & 0x10) != 0) {
    *(float *)(this + 0x254) = *(float *)(this + 0x254) * d_a_bomb2::_5004;
    *(short *)(this + 0x206) =
         (short)((int)*(short *)(this + 0x4c4) << 1) - (*(short *)(this + 0x206) + -0x8000);
  }
  if ((*(uint *)(this + 0x2ec) & 0x80) == 0) {
    if ((*(uint *)(this + 0x2ec) & 0x20) != 0) {
      SComponent::cLib_addCalc
                ((float *)(this + 0x254),d_a_bomb2::_4158,d_a_bomb2::_4161,d_a_bomb2::_5006,
                 d_a_bomb2::_4159);
    }
  }
  else {
    ::daObj::make_land_effect
              ((daObj *)this,(fopAc_ac_c *)(this + 0x398),
               (dBgS_GndChk *)&@unnamed@d_a_bomb2_cpp@::L_attr,DAT_8035bab8);
    fVar1 = (float)(dVar3 * (double)DAT_8035ba64);
    if (DAT_8035ba68 <= fVar1) {
      *(float *)(this + 0x254) = *(float *)(this + 0x254) * d_a_bomb2::_5005;
      if (fVar1 <= DAT_8035ba6c) {
        *(float *)(this + 0x224) = fVar1;
      }
      else {
        *(float *)(this + 0x224) = DAT_8035ba6c;
      }
    }
    else {
      this[0x741] = (Act_c)0x0;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


/* __thiscall Act_c::set_nut_exp_interval(void) */

void __thiscall Act_c::set_nut_exp_interval(Act_c *this)

{
  float fVar1;
  int iVar2;
  
  iVar2 = (int)DAT_8035ba5a;
  if (iVar2 < *(int *)(this + 0x738)) {
    *(int *)(this + 0x738) = iVar2;
    fVar1 = (float)((double)CONCAT44(0x43300000,0x87U - iVar2 ^ 0x80000000) - d_a_bomb2::_4343);
    *(float *)(*(int *)(this + 0x2a0) + 0x10) = fVar1;
    *(float *)(*(int *)(this + 0x2b0) + 0x10) = fVar1;
  }
  return;
}


/* __thiscall Act_c::anm_play(void) */

void __thiscall Act_c::anm_play(Act_c *this)

{
  if (*(int *)(this + 0x738) + 1 < 0x88) {
    ::mDoExt_baseAnm::play((mDoExt_baseAnm *)(this + 0x29c));
    ::mDoExt_baseAnm::play((mDoExt_baseAnm *)(this + 0x2ac));
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x800def84) */
/* WARNING: Removing unreachable block (ram,0x800def74) */
/* WARNING: Removing unreachable block (ram,0x800def7c) */
/* WARNING: Removing unreachable block (ram,0x800def8c) */
/* __thiscall Act_c::set_wind_vec(void) */

void __thiscall Act_c::set_wind_vec(Act_c *this)

{
  int iVar1;
  cCcD_Obj *pcVar2;
  char cVar4;
  fopAc_ac_c *pfVar3;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f28;
  double dVar7;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  float fVar10;
  float fVar11;
  cXyz local_a4;
  cXyz cStack152;
  cXyz cStack140;
  cXyz cStack128;
  cXyz local_74;
  cXyz local_68 [2];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  mtx::PSVECScale((cXyz *)(this + 0x748),(cXyz *)(this + 0x748),d_a_bomb2::_5102);
  fVar10 = mtx::PSVECSquareMag((cXyz *)(this + 0x748));
  fVar11 = d_a_bomb2::_4158;
  if (fVar10 < d_a_bomb2::_5103) {
    *(float *)(this + 0x748) = d_a_bomb2::_4158;
    *(float *)(this + 0x74c) = fVar11;
    *(float *)(this + 0x750) = fVar11;
  }
  iVar1 = dCcD_GObjInf::ChkTgHit((dCcD_GObjInf *)(this + 0x568));
  if (((iVar1 != 0) &&
      (pcVar2 = dCcD_GObjInf::GetTgHitObj((dCcD_GObjInf *)(this + 0x568)), pcVar2 != (cCcD_Obj *)0x0
      )) && (((pcVar2->parent).mObjAt.mDamageTypes & DekuLeafWind) != 0)) {
    dVar8 = (double)DAT_8035ba90;
    local_68[0].x = *(float *)(this + 0x628);
    local_68[0].y = *(float *)(this + 0x62c);
    local_68[0].z = *(float *)(this + 0x630);
    fVar11 = mtx::PSVECSquareMag(local_68);
    dVar7 = (double)fVar11;
    if ((double)(float)(dVar8 * dVar8) < dVar7) {
      dVar6 = dVar7;
      if ((double)d_a_bomb2::_4158 < dVar7) {
        dVar6 = 1.0 / SQRT(dVar7);
        dVar6 = d_a_bomb2::_4200 * dVar6 * (d_a_bomb2::_4201 - dVar7 * dVar6 * dVar6);
        dVar6 = d_a_bomb2::_4200 * dVar6 * (d_a_bomb2::_4201 - dVar7 * dVar6 * dVar6);
        dVar6 = (double)(float)(dVar7 * d_a_bomb2::_4200 * dVar6 *
                                        (d_a_bomb2::_4201 - dVar7 * dVar6 * dVar6));
      }
      mtx::PSVECScale(local_68,local_68,(float)(dVar8 / dVar6));
    }
    iVar1 = (*(code *)((pcVar2->parent).vtbl)->GetShapeAttr_1)(pcVar2);
    local_74.x = ::cXyz::Zero.x;
    local_74.y = ::cXyz::Zero.y;
    local_74.z = ::cXyz::Zero.z;
    dVar6 = (double)d_a_bomb2::_4159;
    dVar8 = dVar6;
    cVar4 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x50))(iVar1,this + 0x1f8,&local_74);
    if (cVar4 != '\0') {
      mtx::PSVECScale(&local_74,&local_74,DAT_8035ba94);
      mtx::PSVECSquareMag((cXyz *)(this + 0x748));
      pfVar3 = dCcD_GAtTgCoCommonBase::GetAc((dCcD_GAtTgCoCommonBase *)(this + 0x5fc));
      if ((pfVar3 != (fopAc_ac_c *)0x0) && ((pfVar3->parent).parent.mBsTypeId == 0xa9)) {
        iVar1 = SComponent::cM_atan2s(local_74.x,local_74.z);
        fVar11 = JKernel::JMath::jmaCosTable
                 [(int)((pfVar3->mCollisionRot).y - iVar1 & 0xffffU) >>
                  (JKernel::JMath::jmaSinShift & 0x3f)];
        if (d_a_bomb2::_4158 < fVar11) {
          dVar8 = (double)(d_a_bomb2::_4159 + fVar11 * DAT_8035ba98);
          dVar6 = (double)(d_a_bomb2::_4159 + fVar11 * DAT_8035ba9c);
        }
      }
    }
    fVar10 = d_a_bomb2::_4159;
    fVar11 = d_a_bomb2::_4158;
    if ((double)d_a_bomb2::_4204 < dVar7) {
      fVar10 = d_a_bomb2::_5103;
      fVar11 = d_a_bomb2::_5005;
    }
    dVar9 = (double)fVar11;
    dVar7 = (double)fVar10;
    ::cXyz::operator_(&cStack128,local_68,fVar11);
    ::cXyz::operator_(&cStack140,&local_74,(float)dVar7);
    ::cXyz::operator_(&cStack152,&cStack140,(float)dVar8);
    ::cXyz::operator__(&local_a4,&cStack128,&cStack152);
    *(float *)(this + 0x748) = local_a4.x;
    *(float *)(this + 0x74c) = local_a4.y;
    *(float *)(this + 0x750) = local_a4.z;
    if (ABS(*(float *)(this + 0x74c)) < d_a_bomb2::_5006) {
      *(float *)(this + 0x74c) =
           *(float *)(this + 0x74c) +
           (float)(dVar9 * (double)DAT_8035ba88) +
           (float)(dVar6 * (double)(float)(dVar7 * (double)DAT_8035ba8c));
    }
    *(undefined4 *)(this + 0x7a8) = 2;
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  __psq_l0(auStack56,uVar5);
  __psq_l1(auStack56,uVar5);
  return;
}


/* __thiscall Act_c::eff_explode(void) */

void __thiscall Act_c::eff_explode(Act_c *this)

{
  camera_class *pcVar1;
  csXyz local_18 [3];
  
  if (this[0x742] == (Act_c)0x0) {
    this[0x742] = (Act_c)0x1;
    pcVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo
             [(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCamera].mpCamera;
    local_18[0].x = -pcVar1->field_0x230;
    local_18[0].y = pcVar1->field_0x232 + -0x8000;
    local_18[0].z = 0;
    eff_explode_normal(this,local_18);
    se_explode(this);
    set_sound_env(this,0xff,10);
  }
  return;
}


/* __thiscall Act_c::eff_explode_normal(csXyz const *) */

void __thiscall Act_c::eff_explode_normal(Act_c *this,csXyz *param_1)

{
  dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,1,0xb,
                     (cXyz *)(this + 0x1f8),param_1,(cXyz *)(this + 0x214),0xff,
                     (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
  dPa_control_c::setBombSmoke
            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0x2009,(cXyz *)(this + 0x1f8),
             (csXyz *)0x0,(cXyz *)(this + 0x214),0xff);
  dPa_control_c::setBombSmoke
            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0x200a,(cXyz *)(this + 0x1f8),
             (csXyz *)0x0,(cXyz *)(this + 0x214),0xff);
  dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,3,0x2008,
                     (cXyz *)(this + 0x1f8),(csXyz *)0x0,(cXyz *)(this + 0x214),0xff,
                     (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
  return;
}


/* __thiscall Act_c::eff_explode_water(void) */

void __thiscall Act_c::eff_explode_water(Act_c *this)

{
  if (this[0x743] == (Act_c)0x0) {
    f_op_kankyo_mng::fopKyM_createWpillar
              ((double)d_a_bomb2::_4159,(double)d_a_bomb2::_4159,this + 0x1f8,1);
    this[0x743] = (Act_c)0x1;
    se_explode_water(this);
    set_sound_env(this,0xff,10);
  }
  return;
}


/* __thiscall Act_c::eff_fuse_init(void) */

void __thiscall Act_c::eff_fuse_init(Act_c *this)

{
  *(float *)(this + 0x6c0) = ::cXyz::Zero.x;
  *(float *)(this + 0x6c4) = ::cXyz::Zero.y;
  *(float *)(this + 0x6c8) = ::cXyz::Zero.z;
  *(float *)(this + 0x6cc) = ::cXyz::Zero.x;
  *(float *)(this + 0x6d0) = ::cXyz::Zero.y;
  *(float *)(this + 0x6d4) = ::cXyz::Zero.z;
  *(float *)(this + 0x6d8) = ::cXyz::Zero.x;
  *(float *)(this + 0x6dc) = ::cXyz::Zero.y;
  *(float *)(this + 0x6e0) = ::cXyz::Zero.z;
  this[0x744] = (Act_c)0x0;
  return;
}


/* __thiscall Act_c::eff_fuse_start(void) */

void __thiscall Act_c::eff_fuse_start(Act_c *this)

{
  if (this[0x744] == (Act_c)0x0) {
    this[0x744] = (Act_c)0x1;
    *(undefined4 *)(this + 0x6c0) = *(undefined4 *)(this + 0x1f8);
    *(float *)(this + 0x6c4) = d_a_bomb2::_5174 + *(float *)(this + 0x1fc);
    *(undefined4 *)(this + 0x6c8) = *(undefined4 *)(this + 0x200);
    *(undefined4 *)(this + 0x6cc) = *(undefined4 *)(this + 0x6c0);
    *(undefined4 *)(this + 0x6d0) = *(undefined4 *)(this + 0x6c4);
    *(undefined4 *)(this + 0x6d4) = *(undefined4 *)(this + 0x6c8);
    *(undefined4 *)(this + 0x6d8) = *(undefined4 *)(this + 0x6c0);
    *(undefined4 *)(this + 0x6dc) = *(undefined4 *)(this + 0x6c4);
    *(undefined4 *)(this + 0x6e0) = *(undefined4 *)(this + 0x6c8);
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,1,0x11,
                       (cXyz *)(this + 0x6c0),(csXyz *)0x0,(cXyz *)(this + 0x214),0xff,
                       (dPa_levelEcallBack *)(this + 0x6b4),-1,(_GXColor *)0x0,(_GXColor *)0x0,
                       (cXyz *)0x0);
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,3,0x2012,
                       (cXyz *)(this + 0x6c0),(csXyz *)0x0,(cXyz *)(this + 0x214),0xdc,
                       (dPa_levelEcallBack *)(this + 0x69c),-1,(_GXColor *)0x0,(_GXColor *)0x0,
                       (cXyz *)0x0);
    FuseSmokeCB_c::setOldPosP
              ((FuseSmokeCB_c *)(this + 0x69c),(cXyz *)(this + 0x6cc),(cXyz *)(this + 0x6d8));
  }
  return;
}


/* __thiscall Act_c::eff_fuse_move(void) */

void __thiscall Act_c::eff_fuse_move(Act_c *this)

{
  if (d_a_bomb2::init_5180 == '\0') {
    d_a_bomb2::fuse_offset_5178 = d_a_bomb2::_4158;
    DAT_803e36c8 = d_a_bomb2::_5174;
    DAT_803e36cc = d_a_bomb2::_5006;
    Runtime.PPCEABI.H::__register_global_object
              (&d_a_bomb2::fuse_offset_5178,::cXyz::_cXyz,&d_a_bomb2::_5179);
    d_a_bomb2::init_5180 = '\x01';
  }
  *(undefined4 *)(this + 0x6d8) = *(undefined4 *)(this + 0x6cc);
  *(undefined4 *)(this + 0x6dc) = *(undefined4 *)(this + 0x6d0);
  *(undefined4 *)(this + 0x6e0) = *(undefined4 *)(this + 0x6d4);
  *(undefined4 *)(this + 0x6cc) = *(undefined4 *)(this + 0x6c0);
  *(undefined4 *)(this + 0x6d0) = *(undefined4 *)(this + 0x6c4);
  *(undefined4 *)(this + 0x6d4) = *(undefined4 *)(this + 0x6c8);
  mtx::PSMTXMultVec(&mDoMtx_stack_c::now,(cXyz *)&d_a_bomb2::fuse_offset_5178,(cXyz *)(this + 0x6c0)
                   );
  if (this[0x744] != (Act_c)0x0) {
    se_ignition(this);
  }
  return;
}


/* __thiscall Act_c::eff_fuse_end(void) */

void __thiscall Act_c::eff_fuse_end(Act_c *this)

{
  FuseSmokeCB_c::deleteCallBack((FuseSmokeCB_c *)(this + 0x69c));
  FuseSparksCB_c::deleteCallBack((FuseSparksCB_c *)(this + 0x6b4));
  this[0x744] = (Act_c)0x0;
  return;
}


/* __thiscall Act_c::eff_water_splash(void) */

void __thiscall Act_c::eff_water_splash(Act_c *this)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_10 = *(undefined4 *)(this + 0x200);
  local_14 = *(undefined4 *)(this + 0x520);
  local_18 = *(undefined4 *)(this + 0x1f8);
  f_op_kankyo_mng::fopKyM_createWpillar
            ((double)d_a_bomb2::_4161,(double)d_a_bomb2::_5206,&local_18,0);
  se_fall_water(this);
  set_sound_env(this,100,5);
  return;
}


/* __thiscall Act_c::se_fall_water(void) */

void __thiscall Act_c::se_fall_water(Act_c *this)

{
  int iVar1;
  sbyte sVar2;
  cBgS_PolyInfo *pcVar3;
  ulong uVar4;
  int iVar5;
  cBgS_PolyInfo *local_18;
  Act_c *local_14;
  
  if (this[0x526] == (Act_c)0x0) {
    local_18 = (cBgS_PolyInfo *)(this + 0x438);
  }
  else {
    local_18 = (cBgS_PolyInfo *)0x0;
  }
  local_14 = this + 0x3ac;
  uVar4 = 0x13;
  iVar1 = 0;
  iVar5 = 2;
  while ((pcVar3 = *(cBgS_PolyInfo **)((int)&local_18 + iVar1), pcVar3 == (cBgS_PolyInfo *)0x0 ||
         (0xff < (ushort)pcVar3->mBgIndex))) {
    iVar1 = iVar1 + 4;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
LAB_800df528:
      sVar2 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x6918,(cXyz *)(this + 0x260),uVar4,sVar2,d_a_bomb2::_4159,
                 d_a_bomb2::_4159,d_a_bomb2::_5235,d_a_bomb2::_5235,0);
      return;
    }
  }
  uVar4 = dBgS::GetMtrlSndId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,pcVar3);
  goto LAB_800df528;
}


/* __thiscall Act_c::se_explode(void) */

void __thiscall Act_c::se_explode(Act_c *this)

{
  sbyte sVar1;
  
  sVar1 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,0x6901,(cXyz *)(this + 0x260),0,sVar1,d_a_bomb2::_4159,
             d_a_bomb2::_4159,d_a_bomb2::_5235,d_a_bomb2::_5235,0);
  return;
}


/* __thiscall Act_c::se_explode_water(void) */

void __thiscall Act_c::se_explode_water(Act_c *this)

{
  sbyte sVar1;
  
  sVar1 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,0x6982,(cXyz *)(this + 0x260),0,sVar1,d_a_bomb2::_4159,
             d_a_bomb2::_4159,d_a_bomb2::_5235,d_a_bomb2::_5235,0);
  return;
}


/* __thiscall Act_c::se_ignition(void) */

void __thiscall Act_c::se_ignition(Act_c *this)

{
  sbyte sVar1;
  
  sVar1 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,0x6100,(cXyz *)(this + 0x260),0,sVar1,d_a_bomb2::_4159,
             d_a_bomb2::_4159,d_a_bomb2::_5235,d_a_bomb2::_5235,0);
  return;
}


/* __thiscall Act_c::set_sound_env(int,
                                            int) */

void __thiscall Act_c::set_sound_env(Act_c *this,int param_1,int param_2)

{
  uint uVar1;
  cXyz local_18 [2];
  
  local_18[0].x = *(float *)(this + 0x1f8);
  local_18[0].y = *(float *)(this + 0x1fc);
  local_18[0].z = *(float *)(this + 0x200);
  if (this == (Act_c *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(uint *)(this + 4);
  }
  d_kankyo::dKy_Sound_set(local_18,param_1,uVar1,param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall Act_c::chk_exp_cc_nut(void) */

int __thiscall Act_c::chk_exp_cc_nut(Act_c *this)

{
  bool bVar1;
  int iVar2;
  cCcD_Obj *pcVar3;
  cCcD_Obj__DamageTypes cVar4;
  int iVar5;
  double dVar6;
  double dVar7;
  float fVar8;
  
  iVar5 = 0;
  bVar1 = false;
  iVar2 = dCcD_GObjInf::ChkTgHit((dCcD_GObjInf *)(this + 0x568));
  if (iVar2 != 0) {
    pcVar3 = dCcD_GObjInf::GetTgHitObj((dCcD_GObjInf *)(this + 0x568));
    if (pcVar3 != (cCcD_Obj *)0x0) {
      cVar4 = (pcVar3->parent).mObjAt.mDamageTypes;
      if ((cVar4 & Bomb) == 0) {
        if ((cVar4 & DekuLeafWind) == 0) {
          bVar1 = true;
        }
      }
      else {
        iVar5 = 1;
      }
    }
    (**(code **)(*(int *)(this + 0x5a4) + 0x20))(this + 0x568);
  }
  iVar2 = dCcD_GObjInf::ChkCoHit((dCcD_GObjInf *)(this + 0x568));
  if (iVar2 == 0) goto LAB_800df814;
  if (this[0x741] == (Act_c)0x0) {
    fVar8 = mtx::PSVECSquareMag((cXyz *)(this + 0x220));
    dVar7 = (double)fVar8;
    if ((double)d_a_bomb2::_4158 < dVar7) {
      dVar6 = 1.0 / SQRT(dVar7);
      dVar6 = d_a_bomb2::_4200 * dVar6 * (d_a_bomb2::_4201 - dVar7 * dVar6 * dVar6);
      dVar6 = d_a_bomb2::_4200 * dVar6 * (d_a_bomb2::_4201 - dVar7 * dVar6 * dVar6);
      dVar7 = (double)(float)(dVar7 * d_a_bomb2::_4200 * dVar6 *
                                      (d_a_bomb2::_4201 - dVar7 * dVar6 * dVar6));
    }
    if ((double)DAT_8035ba7c < dVar7) goto LAB_800df7fc;
  }
  else {
LAB_800df7fc:
    bVar1 = true;
  }
  (**(code **)(*(int *)(this + 0x5a4) + 0x24))(this + 0x568);
LAB_800df814:
  if (bVar1) {
    eff_fuse_start(this);
    set_nut_exp_interval(this);
  }
  if (iVar5 != 0) {
    eff_explode(this);
  }
  return iVar5;
}


/* __thiscall Act_c::chk_exp_cc(void) */

undefined4 __thiscall Act_c::chk_exp_cc(Act_c *this)

{
  undefined4 uVar1;
  
  if (*(int *)(this + 0x738) < 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = chk_exp_cc_nut(this);
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall Act_c::chk_exp_bg_nut(void) */

undefined4 __thiscall Act_c::chk_exp_bg_nut(Act_c *this)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  uint uVar5;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  float fVar9;
  
  cVar3 = chk_water_in(this);
  cVar4 = chk_lava_in(this);
  bVar2 = true;
  bVar1 = false;
  uVar5 = *(uint *)(this + 0x2ec);
  if (((uVar5 & 0x10) != 0) || ((uVar5 & 0x20) != 0)) {
    bVar1 = true;
  }
  if ((!bVar1) && ((uVar5 & 0x200) == 0)) {
    bVar2 = false;
  }
  uVar6 = 0;
  if (cVar4 == '\0') {
    if (cVar3 != '\0') {
      fVar9 = mtx::PSVECSquareMag((cXyz *)(this + 0x220));
      dVar8 = (double)fVar9;
      if ((double)d_a_bomb2::_4158 < dVar8) {
        dVar7 = 1.0 / SQRT(dVar8);
        dVar7 = d_a_bomb2::_4200 * dVar7 * (d_a_bomb2::_4201 - dVar8 * dVar7 * dVar7);
        dVar7 = d_a_bomb2::_4200 * dVar7 * (d_a_bomb2::_4201 - dVar8 * dVar7 * dVar7);
        dVar8 = (double)(float)(dVar8 * d_a_bomb2::_4200 * dVar7 *
                                        (d_a_bomb2::_4201 - dVar8 * dVar7 * dVar7));
      }
      if ((double)DAT_8035ba78 < dVar8) {
        eff_explode_water(this);
        return 1;
      }
    }
    if (bVar2) {
      if (this[0x741] == (Act_c)0x0) {
        fVar9 = mtx::PSVECSquareMag((cXyz *)(this + 0x220));
        dVar8 = (double)fVar9;
        if ((double)d_a_bomb2::_4158 < dVar8) {
          dVar7 = 1.0 / SQRT(dVar8);
          dVar7 = d_a_bomb2::_4200 * dVar7 * (d_a_bomb2::_4201 - dVar8 * dVar7 * dVar7);
          dVar7 = d_a_bomb2::_4200 * dVar7 * (d_a_bomb2::_4201 - dVar8 * dVar7 * dVar7);
          dVar8 = (double)(float)(dVar8 * d_a_bomb2::_4200 * dVar7 *
                                          (d_a_bomb2::_4201 - dVar8 * dVar7 * dVar7));
        }
        if (dVar8 <= (double)DAT_8035ba7c) {
          return 0;
        }
      }
      eff_fuse_start(this);
      set_nut_exp_interval(this);
    }
  }
  else {
    eff_explode(this);
    uVar6 = 1;
  }
  return uVar6;
}


/* __thiscall Act_c::chk_exp_bg(void) */

void __thiscall Act_c::chk_exp_bg(Act_c *this)

{
  chk_exp_bg_nut(this);
  return;
}


/* __thiscall Act_c::chk_exp_timer(void) */

undefined4 __thiscall Act_c::chk_exp_timer(Act_c *this)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (0 < *(int *)(this + 0x738)) {
    iVar1 = *(int *)(this + 0x738) + -1;
    *(int *)(this + 0x738) = iVar1;
    if (iVar1 == 0) {
      eff_explode(this);
      uVar2 = 1;
    }
  }
  return uVar2;
}


/* __thiscall Act_c::chk_sink_bg_nut(void) */

undefined4 __thiscall Act_c::chk_sink_bg_nut(Act_c *this)

{
  char cVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  float fVar5;
  
  cVar1 = chk_water_in(this);
  uVar2 = 0;
  if (cVar1 != '\0') {
    fVar5 = mtx::PSVECSquareMag((cXyz *)(this + 0x220));
    dVar4 = (double)fVar5;
    if ((double)d_a_bomb2::_4158 < dVar4) {
      dVar3 = 1.0 / SQRT(dVar4);
      dVar3 = d_a_bomb2::_4200 * dVar3 * (d_a_bomb2::_4201 - dVar4 * dVar3 * dVar3);
      dVar3 = d_a_bomb2::_4200 * dVar3 * (d_a_bomb2::_4201 - dVar4 * dVar3 * dVar3);
      dVar4 = (double)(float)(dVar4 * d_a_bomb2::_4200 * dVar3 *
                                      (d_a_bomb2::_4201 - dVar4 * dVar3 * dVar3));
    }
    if (dVar4 <= (double)DAT_8035ba78) {
      eff_water_splash(this);
      uVar2 = 1;
    }
  }
  return uVar2;
}


/* __thiscall Act_c::chk_sink_bg(void) */

void __thiscall Act_c::chk_sink_bg(Act_c *this)

{
  chk_sink_bg_nut(this);
  return;
}


/* __thiscall Act_c::chk_exp_pre(void) */

undefined4 __thiscall Act_c::chk_exp_pre(Act_c *this)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  cVar1 = chk_exp_cc(this);
  if ((cVar1 != '\0') || (cVar1 = chk_exp_timer(this), cVar1 != '\0')) {
    uVar2 = 1;
  }
  return uVar2;
}


/* __thiscall Act_c::chk_exp_post(void) */

undefined __thiscall Act_c::chk_exp_post(Act_c *this)

{
  undefined uVar1;
  
  uVar1 = chk_exp_bg(this);
  return uVar1;
}


/* __thiscall Act_c::chk_sink_post(void) */

undefined __thiscall Act_c::chk_sink_post(Act_c *this)

{
  undefined uVar1;
  
  uVar1 = chk_sink_bg(this);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall Act_c::set_real_shadow_flag(void) */

void __thiscall Act_c::set_real_shadow_flag(Act_c *this)

{
  bool bVar1;
  daPy_lk_c *pdVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  bVar1 = false;
  if (*(int *)(this + 0x694) == 1) {
    if (*(int *)(this + 0x24c) == 0) {
      if (this == (Act_c *)0x0) {
        iVar5 = -1;
      }
      else {
        iVar5 = *(int *)(this + 4);
      }
      iVar4 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->vtbl->
                        getGrabActorID)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor);
      if ((iVar4 == iVar5) && (((pdVar2->parent).field_0x2a4 & 0x8000) != 0)) {
        bVar1 = true;
      }
    }
    else {
      bVar1 = true;
    }
  }
  if (bVar1) {
    uVar3 = *(undefined4 *)(this + 0x298);
  }
  else {
    uVar3 = 0;
  }
  *(undefined4 *)(this + 0x24c) = uVar3;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall Act_c::carry_fuse_start(void) */

void __thiscall Act_c::carry_fuse_start(Act_c *this)

{
  bool bVar1;
  daPy_lk_c *pdVar2;
  int iVar3;
  int iVar4;
  
  pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  bVar1 = false;
  if (this[0x744] == (Act_c)0x0) {
    if (this == (Act_c *)0x0) {
      iVar4 = -1;
    }
    else {
      iVar4 = *(int *)(this + 4);
    }
    iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->vtbl->
                      getGrabActorID)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor);
    if (iVar3 == iVar4) {
      if (((pdVar2->parent).field_0x2a4 & 0x20) != 0) {
        bVar1 = true;
      }
    }
    else {
      bVar1 = true;
    }
  }
  if (bVar1) {
    eff_fuse_start(this);
  }
  return;
}


/* __thiscall Act_c::on_carry(void) */

void __thiscall Act_c::on_carry(Act_c *this)

{
  *(uint *)(this + 0x280) = *(uint *)(this + 0x280) | 0x10;
  return;
}


/* __thiscall Act_c::off_carry(void) */

void __thiscall Act_c::off_carry(Act_c *this)

{
  *(uint *)(this + 0x280) = *(uint *)(this + 0x280) & 0xffffffef;
  return;
}


/* __thiscall Act_c::mode_wait_init(void) */

void __thiscall Act_c::mode_wait_init(Act_c *this)

{
  *(undefined4 *)(this + 0x694) = 0;
  *(undefined4 *)(this + 600) = DAT_8035ba5c;
  *(uint *)(this + 0x594) = *(uint *)(this + 0x594) | 1;
  return;
}


/* WARNING: Removing unreachable block (ram,0x800dff20) */
/* __thiscall Act_c::mode_wait(void) */

void __thiscall Act_c::mode_wait(Act_c *this)

{
  char cVar2;
  int iVar1;
  Prm_e in_r6;
  undefined4 uVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  cVar2 = chk_exp_pre(this);
  if (cVar2 == '\0') {
    if ((*(uint *)(this + 0x1c4) & 0x2000) == 0) {
      iVar1 = ::daObj::PrmAbstract((daObj *)this,(fopAc_ac_c *)&DAT_00000001,8,in_r6);
      dVar4 = (double)d_a_bomb2::_4158;
      if (iVar1 == 0) {
        if (this[0x745] == (Act_c)0x0) {
          posMoveF(this);
        }
        dVar4 = (double)*(float *)(this + 0x224);
        bgCrrPos(this);
      }
      cVar2 = chk_exp_post(this);
      if (cVar2 == '\0') {
        cVar2 = chk_sink_post(this);
        if (cVar2 == '\0') {
          if (this[0x740] == (Act_c)0x0) {
            if (iVar1 == 0) {
              bound(this,(float)dVar4);
              if ((*(uint *)(this + 0x2ec) & 0x20) == 0) {
                off_carry(this);
              }
              else {
                on_carry(this);
              }
            }
            else {
              off_carry(this);
            }
          }
        }
        else {
          mode_sink_init(this);
        }
      }
      else {
        mode_explode_init(this);
      }
    }
    else {
      mode_carry_init(this);
      mode_carry(this);
    }
  }
  else {
    mode_explode_init(this);
    mode_explode(this);
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __thiscall Act_c::mode_carry_init(void) */

void __thiscall Act_c::mode_carry_init(Act_c *this)

{
  *(undefined4 *)(this + 0x694) = 1;
  *(float *)(this + 0x254) = d_a_bomb2::_4158;
  *(float *)(this + 0x220) = ::cXyz::Zero.x;
  *(float *)(this + 0x224) = ::cXyz::Zero.y;
  *(float *)(this + 0x228) = ::cXyz::Zero.z;
  off_carry(this);
  *(uint *)(this + 0x594) = *(uint *)(this + 0x594) & 0xfffffffe;
  return;
}


/* __thiscall Act_c::mode_carry(void) */

void __thiscall Act_c::mode_carry(Act_c *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  
  carry_fuse_start(this);
  cVar4 = chk_exp_pre(this);
  if (cVar4 == '\0') {
    if ((*(uint *)(this + 0x1c4) & 0x2000) == 0) {
      if (d_a_bomb2::_4158 < *(float *)(this + 0x254)) {
        this[0x741] = (Act_c)0x1;
        *(undefined4 *)(this + 0x7a8) = 2;
      }
      mode_wait_init(this);
      mode_wait(this);
    }
    else {
      uVar1 = *(undefined4 *)(this + 0x1f8);
      uVar2 = *(undefined4 *)(this + 0x1fc);
      uVar3 = *(undefined4 *)(this + 0x200);
      bgCrrPos(this);
      *(undefined4 *)(this + 0x1f8) = uVar1;
      *(undefined4 *)(this + 0x1fc) = uVar2;
      *(undefined4 *)(this + 0x200) = uVar3;
    }
  }
  else {
    mode_explode_init(this);
    mode_explode(this);
  }
  return;
}


/* __thiscall Act_c::mode_explode_init(void) */

void __thiscall Act_c::mode_explode_init(Act_c *this)

{
  float fVar1;
  cXyz local_18;
  
  *(undefined4 *)(this + 0x694) = 2;
  camera_lockoff(this);
  eff_fuse_end(this);
  Env_c::set((Env_c *)(this + 0x6e4),(cXyz *)(this + 0x1f8));
  fVar1 = d_a_bomb2::_4158;
  *(float *)(this + 0x254) = d_a_bomb2::_4158;
  *(float *)(this + 0x220) = ::cXyz::Zero.x;
  *(float *)(this + 0x224) = ::cXyz::Zero.y;
  *(float *)(this + 0x228) = ::cXyz::Zero.z;
  *(float *)(this + 600) = fVar1;
  off_carry(this);
  *(uint *)(this + 0x580) = *(uint *)(this + 0x580) & 0xfffffffe;
  *(uint *)(this + 0x594) = *(uint *)(this + 0x594) & 0xfffffffe;
  *(uint *)(this + 0x568) = *(uint *)(this + 0x568) | 1;
  f_op_actor_mng::fopAcM_cancelCarryNow(this);
  *(undefined4 *)(this + 0x738) = 0;
  *(undefined4 *)(this + 0x73c) = 4;
  local_18.x = d_a_bomb2::_4158;
  local_18.y = d_a_bomb2::_4159;
  local_18.z = d_a_bomb2::_4158;
  dVibration_c::StartShock(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,7,-0x21,&local_18);
  return;
}


/* __thiscall Act_c::mode_explode(void) */

void __thiscall Act_c::mode_explode(Act_c *this)

{
  char cVar1;
  
  Env_c::proc((Env_c *)(this + 0x6e4),(cXyz *)(this + 0x1f8));
  if ((*(int *)(this + 0x73c) == 0) &&
     (cVar1 = Env_c::is_end((Env_c *)(this + 0x6e4)), cVar1 != '\0')) {
    this[0x740] = (Act_c)0x1;
  }
  return;
}


/* __thiscall Act_c::mode_sink_init(void) */

void __thiscall Act_c::mode_sink_init(Act_c *this)

{
  float fVar1;
  
  *(undefined4 *)(this + 0x694) = 3;
  fVar1 = d_a_bomb2::_5004;
  *(float *)(this + 0x224) = *(float *)(this + 0x224) * d_a_bomb2::_5004;
  *(float *)(this + 0x254) = *(float *)(this + 0x254) * fVar1;
  *(uint *)(this + 0x568) = *(uint *)(this + 0x568) & 0xfffffffe;
  *(uint *)(this + 0x580) = *(uint *)(this + 0x580) & 0xfffffffe;
  *(uint *)(this + 0x594) = *(uint *)(this + 0x594) & 0xfffffffe;
  off_carry(this);
  f_op_actor_mng::fopAcM_cancelCarryNow(this);
  *(undefined4 *)(this + 0x698) = 4;
  f_op_actor_mng::fopAcM_getWaterY((cXyz *)(this + 0x1f8),(float *)(this + 0x528));
  return;
}


/* __thiscall Act_c::mode_sink(void) */

void __thiscall Act_c::mode_sink(Act_c *this)

{
  uint uVar1;
  int iVar2;
  float local_18 [5];
  
  uVar1 = f_op_actor_mng::fopAcM_getWaterY((cXyz *)(this + 0x1f8),local_18);
  if (((uVar1 != 0) && (d_a_bomb2::_4450 != *(float *)(this + 0x528))) &&
     (iVar2 = *(int *)(this + 0x698), *(int *)(this + 0x698) = iVar2 + -1, 0 < iVar2 + -1)) {
    *(float *)(this + 0x1fc) = *(float *)(this + 0x1fc) + (local_18[0] - *(float *)(this + 0x528));
    *(float *)(this + 0x528) = local_18[0];
    posMoveF(this);
    return;
  }
  this[0x740] = (Act_c)0x1;
  return;
}


/* __thiscall Act_c::mode_proc_call(void) */

void __thiscall Act_c::mode_proc_call(Act_c *this)

{
  undefined4 *in_r4;
  undefined4 *extraout_r4;
  
  if (d_a_bomb2::init_5592 == '\0') {
    d_a_bomb2::mode_proc_5587 = d_a_bomb2::_5588;
    DAT_8038a2e4 = DAT_8038a2b4;
    DAT_8038a2e8 = PTR_mode_wait_8038a2b8;
    in_r4 = &d_a_bomb2::mode_proc_5587;
    DAT_8038a2ec = d_a_bomb2::_5589;
    DAT_8038a2f0 = DAT_8038a2c0;
    DAT_8038a2f4 = PTR_mode_carry_8038a2c4;
    DAT_8038a2f8 = d_a_bomb2::_5590;
    DAT_8038a2fc = DAT_8038a2cc;
    DAT_8038a300 = PTR_mode_explode_8038a2d0;
    DAT_8038a304 = d_a_bomb2::_5591;
    DAT_8038a308 = DAT_8038a2d8;
    DAT_8038a30c = PTR_mode_sink_8038a2dc;
    d_a_bomb2::init_5592 = '\x01';
  }
  if (((*(uint *)(this + 0x1c4) & 0x2000) != 0) && (*(int *)(this + 0x694) != 1)) {
    mode_carry_init(this);
    in_r4 = extraout_r4;
  }
  Runtime.PPCEABI.H::__ptmf_scall
            ((PTMF *)(&d_a_bomb2::mode_proc_5587 + *(int *)(this + 0x694) * 3),this,in_r4);
  set_real_shadow_flag(this);
  return;
}


/* __thiscall Act_c::tensor_init(void) */

void __thiscall Act_c::tensor_init(Act_c *this)

{
  mtx::PSMTXIdentity((MTX34 *)(this + 0x754));
  vib_init(this);
  return;
}


/* __thiscall Act_c::vib_init(void) */

void __thiscall Act_c::vib_init(Act_c *this)

{
  float fVar1;
  
  fVar1 = d_a_bomb2::_4158;
  *(float *)(this + 0x784) = d_a_bomb2::_4158;
  *(float *)(this + 0x788) = fVar1;
  *(float *)(this + 0x78c) = fVar1;
  *(float *)(this + 0x790) = fVar1;
  *(float *)(this + 0x794) = fVar1;
  *(float *)(this + 0x798) = fVar1;
  *(float *)(this + 0x79c) = fVar1;
  *(float *)(this + 0x7a0) = fVar1;
  *(float *)(this + 0x7a4) = fVar1;
  *(undefined4 *)(this + 0x7a8) = 0;
  return;
}


/* __thiscall Act_c::vib_proc(void) */

void __thiscall Act_c::vib_proc(Act_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = (*(float *)(this + 0x790) - *(float *)(this + 0x788)) * DAT_8035baa0;
  fVar2 = d_a_bomb2::_4159 / DAT_8035baac;
  fVar3 = d_a_bomb2::_4159 - *(float *)(this + 0x7a4);
  *(float *)(this + 0x794) =
       *(float *)(this + 0x794) +
       (*(float *)(this + 0x79c) -
       (*(float *)(this + 0x78c) - *(float *)(this + 0x784)) * DAT_8035baa0) * fVar2;
  *(float *)(this + 0x798) = *(float *)(this + 0x798) + (*(float *)(this + 0x7a0) - fVar1) * fVar2;
  *(float *)(this + 0x794) = *(float *)(this + 0x794) * fVar3;
  *(float *)(this + 0x798) = *(float *)(this + 0x798) * fVar3;
  *(float *)(this + 0x78c) = *(float *)(this + 0x78c) + *(float *)(this + 0x794);
  *(float *)(this + 0x790) = *(float *)(this + 0x790) + *(float *)(this + 0x798);
  fVar1 = d_a_bomb2::_4158;
  *(float *)(this + 0x79c) = d_a_bomb2::_4158;
  *(float *)(this + 0x7a0) = fVar1;
  if (*(int *)(this + 0x7a8) < 1) {
    return;
  }
  *(int *)(this + 0x7a8) = *(int *)(this + 0x7a8) + -1;
  return;
}


/* __thiscall Act_c::set_vib_tensor(void) */

void __thiscall Act_c::set_vib_tensor(Act_c *this)

{
  cXyz *in_r5;
  daObj adStack40 [16];
  Quaternion local_18;
  
  local_18.z = *(float *)(this + 0x78c);
  local_18.x = *(float *)(this + 0x790);
  local_18.y = d_a_bomb2::_4159;
  ::daObj::quat_rotBaseY2(adStack40,&local_18,in_r5);
  mtx::PSMTXQuat(this + 0x754,adStack40);
  return;
}


/* __thiscall Act_c::tensor_wait(void) */

void __thiscall Act_c::tensor_wait(Act_c *this)

{
  if ((*(uint *)(this + 0x2ec) & 0x20) == 0) {
    tensor_wait_drop(this);
  }
  else {
    tensor_wait_ground(this);
  }
  return;
}


/* __thiscall Act_c::tensor_wait_drop(void) */

void __thiscall Act_c::tensor_wait_drop(Act_c *this)

{
  float fVar1;
  
  fVar1 = DAT_8035bab0;
  if (0 < *(int *)(this + 0x7a8)) {
    *(float *)(this + 0x79c) = *(float *)(this + 0x228) * DAT_8035bab0;
    *(float *)(this + 0x7a0) = *(float *)(this + 0x220) * fVar1;
  }
  fVar1 = d_a_bomb2::_4158;
  *(float *)(this + 0x784) = d_a_bomb2::_4158;
  *(float *)(this + 0x788) = fVar1;
  *(undefined4 *)(this + 0x7a4) = DAT_8035baa4;
  return;
}


/* __thiscall Act_c::tensor_wait_ground(void) */

void __thiscall Act_c::tensor_wait_ground(Act_c *this)

{
  float fVar1;
  float fVar2;
  cM3dGPla *pcVar3;
  
  pcVar3 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                           (uint)*(ushort *)(this + 0x3ae),(uint)*(ushort *)(this + 0x3ac));
  fVar2 = d_a_bomb2::_4158;
  fVar1 = DAT_8035bab4;
  if (pcVar3 == (cM3dGPla *)0x0) {
    *(float *)(this + 0x784) = d_a_bomb2::_4158;
    *(float *)(this + 0x788) = fVar2;
  }
  else {
    *(float *)(this + 0x784) = (pcVar3->mNorm).z * DAT_8035bab4;
    *(float *)(this + 0x788) = (pcVar3->mNorm).x * fVar1;
  }
  *(undefined4 *)(this + 0x7a4) = DAT_8035baa8;
  return;
}


/* __thiscall Act_c::tensor_carry(void) */

void __thiscall Act_c::tensor_carry(Act_c *this)

{
  float fVar1;
  
  fVar1 = d_a_bomb2::_4158;
  *(float *)(this + 0x784) = d_a_bomb2::_4158;
  *(float *)(this + 0x788) = fVar1;
  *(undefined4 *)(this + 0x7a4) = DAT_8035baa8;
  return;
}


/* __thiscall Act_c::tensor_explode(void) */

void __thiscall Act_c::tensor_explode(Act_c *this)

{
  float fVar1;
  
  fVar1 = d_a_bomb2::_4158;
  *(float *)(this + 0x784) = d_a_bomb2::_4158;
  *(float *)(this + 0x788) = fVar1;
  *(undefined4 *)(this + 0x7a4) = DAT_8035baa8;
  return;
}


/* __thiscall Act_c::tensor_sink(void) */

void __thiscall Act_c::tensor_sink(Act_c *this)

{
  float fVar1;
  
  fVar1 = d_a_bomb2::_4158;
  *(float *)(this + 0x784) = d_a_bomb2::_4158;
  *(float *)(this + 0x788) = fVar1;
  *(undefined4 *)(this + 0x7a4) = DAT_8035baa8;
  return;
}


/* __thiscall Act_c::tensor_proc_call(void) */

void __thiscall Act_c::tensor_proc_call(Act_c *this)

{
  Prm_e in_r6;
  undefined8 uVar1;
  
  if (d_a_bomb2::init_5670 == '\0') {
    d_a_bomb2::tensor_proc_5665 = d_a_bomb2::_5666;
    DAT_8038a344 = DAT_8038a314;
    DAT_8038a348 = PTR_tensor_wait_8038a318;
    DAT_8038a34c = d_a_bomb2::_5667;
    DAT_8038a350 = DAT_8038a320;
    DAT_8038a354 = PTR_tensor_carry_8038a324;
    DAT_8038a358 = d_a_bomb2::_5668;
    DAT_8038a35c = DAT_8038a32c;
    DAT_8038a360 = PTR_tensor_explode_8038a330;
    DAT_8038a364 = d_a_bomb2::_5669;
    DAT_8038a368 = DAT_8038a338;
    DAT_8038a36c = PTR_tensor_sink_8038a33c;
    d_a_bomb2::init_5670 = '\x01';
  }
  uVar1 = ::daObj::PrmAbstract((daObj *)this,(fopAc_ac_c *)&DAT_00000001,8,in_r6);
  if ((int)((ulonglong)uVar1 >> 0x20) == 0) {
    Runtime.PPCEABI.H::__ptmf_scall
              ((PTMF *)(&d_a_bomb2::tensor_proc_5665 + *(int *)(this + 0x694) * 3),this,
               (void *)uVar1);
    vib_proc(this);
    set_vib_tensor(this);
  }
  return;
}


/* __thiscall Act_c::_execute(void) */

undefined4 __thiscall Act_c::_execute(Act_c *this)

{
  set_wind_vec(this);
  mode_proc_call(this);
  if (this[0x740] == (Act_c)0x0) {
    tensor_proc_call(this);
    anm_play(this);
    *(undefined4 *)(this + 0x274) = *(undefined4 *)(this + 0x1f8);
    *(float *)(this + 0x278) = d_a_bomb2::_4449 + *(float *)(this + 0x1fc);
    *(undefined4 *)(this + 0x27c) = *(undefined4 *)(this + 0x200);
    *(undefined4 *)(this + 0x260) = *(undefined4 *)(this + 0x274);
    *(undefined4 *)(this + 0x264) = *(undefined4 *)(this + 0x278);
    *(undefined4 *)(this + 0x268) = *(undefined4 *)(this + 0x27c);
    set_mtx(this);
    cc_set(this);
  }
  else {
    f_op_actor_mng::fopAcM_delete((base_process_class *)this);
  }
  return 1;
}


/* __thiscall Act_c::is_draw(void) */

undefined4 __thiscall Act_c::is_draw(Act_c *this)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((*(int *)(this + 0x694) != 2) && (this[0x743] == (Act_c)0x0)) && (this[0x742] == (Act_c)0x0))
  {
    uVar1 = 1;
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall Act_c::draw_nut(void) */

void __thiscall Act_c::draw_nut(Act_c *this)

{
  J3DModelData *pJVar1;
  
  pJVar1 = *(J3DModelData **)(*(int *)(this + 0x298) + 4);
  ::mDoExt_bckAnm::entry
            ((mDoExt_bckAnm *)(this + 0x29c),pJVar1,*(float *)(*(int *)(this + 0x2a0) + 0x10));
  ::mDoExt_brkAnm::entry
            ((mDoExt_brkAnm *)(this + 0x2ac),pJVar1,*(float *)(*(int *)(this + 0x2b0) + 0x10));
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0xc;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x10
  ;
  m_Do_ext::mDoExt_modelUpdateDL(*(J3DModel **)(this + 0x298));
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  (*(pJVar1->mJointTree).mpJoints)->mpMtxCalc = (J3DMtxCalc *)0x0;
  J3DMaterialTable::removeTevRegAnimator
            (&pJVar1->mMaterialTable,*(J3DAnmTevRegKey **)(this + 0x2b4));
  return;
}


/* __thiscall Act_c::draw_shadow(void) */

void __thiscall Act_c::draw_shadow(Act_c *this)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(this + 0x24c) == 0) {
    iVar1 = (int)((float)((double)CONCAT44(0x43300000,
                                           (int)*(short *)(*(int *)(this + 0x2a0) + 8) ^ 0x80000000)
                         - d_a_bomb2::_4343) - *(float *)(*(int *)(this + 0x2a0) + 0x10));
    if (iVar1 < 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = 9;
      if (iVar1 < 10) {
        iVar2 = iVar1;
      }
    }
    d_com_inf_game::dComIfGd_setSimpleShadow2
              ((cXyz *)(this + 0x1f8),*(float *)(this + 0x358),
               d_a_bomb2::_5766 * (float)(&d_a_bomb2::mult_5741)[iVar2],
               (cBgS_PolyInfo *)(this + 0x3ac),0,d_a_bomb2::_4159,
               &dDlst_shadowControl_c::mSimpleTexObj);
  }
  return;
}


/* __thiscall Act_c::_draw(void) */

undefined4 __thiscall Act_c::_draw(Act_c *this)

{
  char cVar1;
  
  cVar1 = is_draw(this);
  if (cVar1 != '\0') {
    dScnKy_env_light_c::settingTevStruct
              (&d_kankyo::g_env_light,Actor,(cXyz *)(this + 0x1f8),(dKy_tevstr_c *)(this + 0x10c));
    dScnKy_env_light_c::setLightTevColorType
              (&d_kankyo::g_env_light,*(J3DModel **)(this + 0x298),(dKy_tevstr_c *)(this + 0x10c));
    draw_nut(this);
    draw_shadow(this);
  }
  return 1;
}


/* __thiscall @unnamed@d_a_bomb2_cpp@::Mthd_Create(void *) */

void __thiscall
@unnamed@d_a_bomb2_cpp@::Mthd_Create(_unnamed_d_a_bomb2_cpp_ *this,void *param_1)

{
  Act_c::_create((Act_c *)this);
  return;
}


/* __thiscall @unnamed@d_a_bomb2_cpp@::Mthd_Delete(void *) */

undefined __thiscall
@unnamed@d_a_bomb2_cpp@::Mthd_Delete(_unnamed_d_a_bomb2_cpp_ *this,void *param_1)

{
  undefined uVar1;
  
  uVar1 = Act_c::_delete((Act_c *)this);
  return uVar1;
}


/* __thiscall @unnamed@d_a_bomb2_cpp@::Mthd_Execute(void *) */

undefined __thiscall
@unnamed@d_a_bomb2_cpp@::Mthd_Execute(_unnamed_d_a_bomb2_cpp_ *this,void *param_1)

{
  undefined uVar1;
  
  uVar1 = Act_c::_execute((Act_c *)this);
  return uVar1;
}


/* __thiscall @unnamed@d_a_bomb2_cpp@::Mthd_Draw(void *) */

undefined __thiscall
@unnamed@d_a_bomb2_cpp@::Mthd_Draw(_unnamed_d_a_bomb2_cpp_ *this,void *param_1)

{
  undefined uVar1;
  
  uVar1 = Act_c::_draw((Act_c *)this);
  return uVar1;
}


/* __thiscall @unnamed@d_a_bomb2_cpp@::Mthd_IsDelete(void *) */

undefined4 __thiscall
@unnamed@d_a_bomb2_cpp@::Mthd_IsDelete(_unnamed_d_a_bomb2_cpp_ *this,void *param_1)

{
  return 1;
}


/* __thiscall FuseSparksCB_c::~FuseSparksCB_c(void) */

void __thiscall FuseSparksCB_c::_FuseSparksCB_c(FuseSparksCB_c *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (FuseSparksCB_c *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined1 **)this = &::dPa_levelEcallBack::__vt, bVar1)) {
      *(undefined1 **)this = &::JPACallBackBase<JPABaseEmitter*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall FuseSmokeCB_c::~FuseSmokeCB_c(void) */

void __thiscall FuseSmokeCB_c::_FuseSmokeCB_c(FuseSmokeCB_c *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (FuseSmokeCB_c *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined1 **)this = &::dPa_levelEcallBack::__vt, bVar1)) {
      *(undefined1 **)this = &::JPACallBackBase<JPABaseEmitter*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

}

/* __thiscall daObj::PrmAbstract<daBomb2::Act_c::Prm_e>(fopAc_ac_c const *,
                                                        daBomb2::Act_c::Prm_e,
                                                        daBomb2::Act_c::Prm_e) */

uint __thiscall daObj::PrmAbstract(daObj *this,fopAc_ac_c *param_1,Prm_e param_2,Prm_e param_3)

{
  return (1 << (int)param_1) - 1U & *(uint *)(this + 0xb0) >> param_2;
}

