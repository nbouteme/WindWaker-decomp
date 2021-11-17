#include <d_a_bomb.h>
#include <d_a_bomb_static.h>
#include <mtx/vec.h>
#include <JPABase/JPAEmitter.h>
#include <m_Do_ext.h>
#include <d_a_bomb.h>
#include <J3DU/J3DUClipper.h>
#include <d_kankyo.h>
#include <SComponent/c_bg_s.h>
#include <d_drawlist.h>
#include <d_cc_d.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <d_a_obj.h>
#include <f_op_actor_mng.h>
#include <d_bg_s_acch.h>
#include <d_a_sea.h>
#include <SComponent/c_lib.h>
#include <d_bg_s.h>
#include <d_particle.h>
#include <d_vibration.h>
#include <d_com_inf_game.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <f_op_kankyo_mng.h>
#include <SComponent/c_m3d_g_sph.h>
#include <SComponent/c_cc_s.h>
#include <d_cc_mass_s.h>
#include <d_camera.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <SComponent/c_bg_s_chk.h>
#include <d_kankyo_wether.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <mtx/mtxvec.h>
#include <SComponent/c_math.h>
#include <SComponent/c_xyz.h>
#include <mtx/mtx.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <f_op_actor.h>
#include <JKernel/JKRHeap.h>
#include <daBomb_c.h>
#include <LIGHT_INFLUENCE.h>
#include <mDoExt_bckAnm.h>
#include <daBomb_fuseSparksEcallBack.h>
#include <dBgS_BombAcch.h>
#include <daBomb_fuseSmokeEcallBack.h>


namespace d_a_bomb {
undefined4 fuse_offset$5399;
undefined1 init$4555;
undefined1 init$4644;
undefined1 init$5401;
}

namespace @unnamed@d_a_bomb_cpp@ {

/* __thiscall chk_attrState(daBomb_c const *,
                                                    AttrSt_e) */

bool chk_attrState(daBomb_c *param_1,AttrSt_e param_2)

{
  int iVar1;
  
  iVar1 = daBomb_c::prm_get_state(param_1);
  return (*(uint *)(&L_attrState + iVar1 * 4) & param_2) != 0;
}

}

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x800d9754) */
/* WARNING: Removing unreachable block (ram,0x800d9744) */
/* WARNING: Removing unreachable block (ram,0x800d9734) */
/* WARNING: Removing unreachable block (ram,0x800d9724) */
/* WARNING: Removing unreachable block (ram,0x800d9714) */
/* WARNING: Removing unreachable block (ram,0x800d9704) */
/* WARNING: Removing unreachable block (ram,0x800d96f4) */
/* WARNING: Removing unreachable block (ram,0x800d96e4) */
/* WARNING: Removing unreachable block (ram,0x800d96d4) */
/* WARNING: Removing unreachable block (ram,0x800d96dc) */
/* WARNING: Removing unreachable block (ram,0x800d96ec) */
/* WARNING: Removing unreachable block (ram,0x800d96fc) */
/* WARNING: Removing unreachable block (ram,0x800d970c) */
/* WARNING: Removing unreachable block (ram,0x800d971c) */
/* WARNING: Removing unreachable block (ram,0x800d972c) */
/* WARNING: Removing unreachable block (ram,0x800d973c) */
/* WARNING: Removing unreachable block (ram,0x800d974c) */
/* WARNING: Removing unreachable block (ram,0x800d975c) */
/* __thiscall daBomb_fuseSmokeEcallBack::executeAfter(JPABaseEmitter *) */

void __thiscall
daBomb_fuseSmokeEcallBack::executeAfter(daBomb_fuseSmokeEcallBack *this,JPABaseEmitter *param_1)

{
  int iVar1;
  float fVar2;
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
  undefined8 in_f14;
  undefined8 in_f15;
  undefined8 in_f16;
  double dVar17;
  undefined8 in_f17;
  double dVar18;
  undefined8 in_f18;
  double dVar19;
  undefined8 in_f19;
  undefined8 in_f20;
  double dVar20;
  undefined8 in_f21;
  undefined8 in_f22;
  undefined8 in_f23;
  undefined8 in_f24;
  double dVar21;
  undefined8 in_f25;
  double dVar22;
  undefined8 in_f26;
  double dVar23;
  undefined8 in_f27;
  double dVar24;
  undefined8 in_f28;
  double dVar25;
  undefined8 in_f29;
  double dVar26;
  undefined8 in_f30;
  double dVar27;
  undefined8 in_f31;
  double dVar28;
  float fVar29;
  float fVar30;
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
  dVar28 = (double)*pfVar4;
  dVar27 = (double)pfVar4[1];
  dVar26 = (double)pfVar4[2];
  pfVar4 = *(float **)(this + 8);
  dVar25 = (double)*pfVar4;
  fVar29 = pfVar4[1];
  dVar24 = (double)fVar29;
  fVar2 = pfVar4[2];
  dVar23 = (double)fVar2;
  (param_1->mGlobalTranslation).x = *pfVar4;
  (param_1->mGlobalTranslation).y = fVar29;
  (param_1->mGlobalTranslation).z = fVar2;
  fVar29 = mtx::PSVECSquareDistance(*(cXyz **)(this + 8),*(cXyz **)(this + 0xc));
  dVar11 = (double)fVar29;
  if ((double)d_a_bomb::_4271 < dVar11) {
    dVar9 = 1.0 / SQRT(dVar11);
    dVar9 = d_a_bomb::_4272 * dVar9 * (d_a_bomb::_4273 - dVar11 * dVar9 * dVar9);
    dVar9 = d_a_bomb::_4272 * dVar9 * (d_a_bomb::_4273 - dVar11 * dVar9 * dVar9);
    dVar11 = (double)(float)(dVar11 * d_a_bomb::_4272 * dVar9 *
                                      (d_a_bomb::_4273 - dVar11 * dVar9 * dVar9));
  }
  sVar7 = (short)(int)(d_a_bomb::_4274 + d_a_bomb::_4275 * (float)((double)d_a_bomb::_4276 - dVar11)
                      );
  if (sVar7 < 10) {
    sVar7 = 10;
  }
  param_1->mLifeTime = sVar7;
  fVar29 = d_a_bomb::_4275 * (float)(dVar25 - dVar28);
  fVar2 = d_a_bomb::_4275 * (float)(dVar24 - dVar27);
  fVar3 = d_a_bomb::_4275 * (float)(dVar23 - dVar26);
  pfVar4 = *(float **)(this + 0x10);
  dVar22 = (double)(d_a_bomb::_4275 * (float)(dVar28 - (double)*pfVar4));
  dVar21 = (double)(d_a_bomb::_4275 * (float)(dVar27 - (double)pfVar4[1]));
  dVar9 = (double)(d_a_bomb::_4275 * (float)(dVar26 - (double)pfVar4[2]));
  fVar30 = mtx::PSVECSquareDistance(*(cXyz **)(this + 8),*(cXyz **)(this + 0xc));
  dVar11 = (double)fVar30;
  if ((double)d_a_bomb::_4271 < dVar11) {
    dVar10 = 1.0 / SQRT(dVar11);
    dVar10 = d_a_bomb::_4272 * dVar10 * (d_a_bomb::_4273 - dVar11 * dVar10 * dVar10);
    dVar10 = d_a_bomb::_4272 * dVar10 * (d_a_bomb::_4273 - dVar11 * dVar10 * dVar10);
    dVar11 = (double)(float)(dVar11 * d_a_bomb::_4272 * dVar10 *
                                      (d_a_bomb::_4273 - dVar11 * dVar10 * dVar10));
  }
  dVar10 = (double)d_a_bomb::1_0;
  if (dVar10 < (double)(float)((double)d_a_bomb::_4277 * dVar11)) {
    dVar20 = (double)(float)(dVar10 / (double)(float)((double)d_a_bomb::_4277 * dVar11));
    local_160 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 4) - (int)sVar7 ^ 0x80000000);
    iVar1 = (int)(dVar20 * (double)(float)(local_160 - d_a_bomb::_4283));
    iVar6 = (int)(short)(sVar7 + (short)iVar1);
    dVar17 = (double)d_a_bomb::_4279;
    dVar18 = (double)d_a_bomb::_4280;
    dVar19 = (double)d_a_bomb::_4281;
    dVar11 = dVar20;
    for (; dVar20 < dVar10; dVar20 = (double)(float)(dVar20 + dVar11)) {
      dVar16 = (double)(float)(dVar20 * dVar20);
      dVar15 = (double)(float)(dVar16 * dVar20);
      dVar14 = (double)(float)(dVar10 + (double)((float)(dVar17 * dVar15) - (float)(dVar18 * dVar16)
                                                ));
      dVar13 = (double)((float)(dVar19 * dVar15) + (float)(dVar18 * dVar16));
      dVar12 = (double)(float)(dVar20 + (double)(float)(dVar15 - (double)(float)(dVar17 * dVar16)));
      fVar30 = (float)(dVar15 - dVar16);
      dVar16 = (double)(fVar30 * fVar29 +
                       (float)(dVar12 * dVar22) +
                       (float)(dVar14 * dVar28) + (float)(dVar13 * dVar25));
      dVar15 = (double)(fVar30 * fVar2 +
                       (float)(dVar12 * dVar21) +
                       (float)(dVar14 * dVar27) + (float)(dVar13 * dVar24));
      dVar12 = (double)(fVar30 * fVar3 +
                       (float)(dVar12 * dVar9) + (float)(dVar14 * dVar26) + (float)(dVar13 * dVar23)
                       );
      param_1->mLifeTime = (short)iVar6;
      iVar5 = JPABaseEmitter::createParticle(param_1);
      if (iVar5 != 0) {
        *(float *)(iVar5 + 0x10) = (float)dVar16;
        *(float *)(iVar5 + 0x14) = (float)dVar15;
        *(float *)(iVar5 + 0x18) = (float)dVar12;
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


/* __thiscall daBomb_fuseSparksEcallBack::execute(JPABaseEmitter *) */

void __thiscall
daBomb_fuseSparksEcallBack::execute(daBomb_fuseSparksEcallBack *this,JPABaseEmitter *param_1)

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


/* __thiscall daBomb_c::draw_norm(void) */

void __thiscall daBomb_c::draw_norm(daBomb_c *this)

{
  float fVar1;
  short sVar2;
  float fVar3;
  uint uVar4;
  
  sVar2 = *(short *)(*(int *)&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->field_0x2eb0 +
                    6);
  fVar1 = (float)((double)CONCAT44(0x43300000,
                                   ((int)sVar2 - (int)this->field_0x6fc) + 2U ^ 0x80000000) -
                 d_a_bomb::_4283);
  fVar3 = d_a_bomb::_4271;
  if ((d_a_bomb::_4271 <= fVar1) &&
     (uVar4 = (int)sVar2 ^ 0x80000000, fVar3 = fVar1,
     (float)((double)CONCAT44(0x43300000,uVar4) - d_a_bomb::_4283) <= fVar1)) {
    fVar3 = (float)((double)CONCAT44(0x43300000,uVar4) - d_a_bomb::_4283) - d_a_bomb::_4374;
  }
  *(float *)(*(int *)&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->field_0x2eb0 + 8) =
       fVar3;
  sVar2 = (((this->field_0x2a8).mpAnmTransform)->parent).mDuration;
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)sVar2 - (int)this->field_0x6fc ^ 0x80000000) -
                 d_a_bomb::_4283);
  fVar3 = d_a_bomb::_4271;
  if ((d_a_bomb::_4271 <= fVar1) &&
     (uVar4 = (int)sVar2 ^ 0x80000000, fVar3 = fVar1,
     (float)((double)CONCAT44(0x43300000,uVar4) - d_a_bomb::_4283) <= fVar1)) {
    fVar3 = (float)((double)CONCAT44(0x43300000,uVar4) - d_a_bomb::_4283) - d_a_bomb::_4374;
  }
  ::mDoExt_bckAnm::entry(&this->field_0x2a8,this->mpModel->mpModelData,fVar3);
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0xc;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x10
  ;
  m_Do_ext::mDoExt_modelUpdateDL(this->mpModel);
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  return;
}


/* __thiscall daBomb_c::draw_nut(void) */

void __thiscall daBomb_c::draw_nut(daBomb_c *this)

{
  char cVar1;
  
  cVar1 = chk_state(this,5);
  if ((cVar1 == '\0') && (cVar1 = chk_state(this,6), cVar1 == '\0')) {
    ::mDoExt_bckAnm::entry
              ((mDoExt_bckAnm *)&this->field_0x2b8,this->mpModel->mpModelData,
               *(float *)(*(int *)&this->field_0x2bc + 0x10));
    ::mDoExt_brkAnm::entry
              ((mDoExt_brkAnm *)&this->field_0x2e0,this->mpModel->mpModelData,
               *(float *)(*(int *)&this->field_0x2e4 + 0x10));
  }
  else {
    ::mDoExt_bckAnm::entry
              (&this->field_0x2a8,this->mpModel->mpModelData,
               ((this->field_0x2a8).parent.mpFrameCtrl)->mCurrentTime);
    ::mDoExt_brkAnm::entry
              ((mDoExt_brkAnm *)&this->field_0x2c8,this->mpModel->mpModelData,
               *(float *)(*(int *)&this->field_0x2cc + 0x10));
  }
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0xc;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x10
  ;
  m_Do_ext::mDoExt_modelUpdateDL(this->mpModel);
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  return;
}


/* __thiscall daBomb_c::draw(void) */

undefined4 __thiscall daBomb_c::draw(daBomb_c *this)

{
  char cVar2;
  uint uVar1;
  cM3dGPla *pFloorNrm;
  cXyz local_18;
  
  cVar2 = @unnamed@d_a_bomb_cpp@::chk_attrState(this,0x20);
  if ((cVar2 == '\0') &&
     ((cVar2 = chk_state(this,4), cVar2 == '\0' || (*(char *)&this->field_0x77d != '\x01')))) {
    local_18.x = (this->parent).mCurrent.mPos.x;
    local_18.y = (this->parent).mCurrent.mPos.y;
    local_18.z = (this->parent).mCurrent.mPos.z;
    uVar1 = J3DUClipper::clip(&mDoLib_clipper::mClipper,&J3DGraphBase::j3dSys.mCurViewMtx,&local_18,
                              d_a_bomb::_4476);
    if ((uVar1 == 0) && (this->field_0x7c8 < 1)) {
      dScnKy_env_light_c::settingTevStruct
                (&d_kankyo::g_env_light,Actor,&(this->parent).mCurrent.mPos,&(this->parent).mTevStr)
      ;
      dScnKy_env_light_c::setLightTevColorType
                (&d_kankyo::g_env_light,this->mpModel,&(this->parent).mTevStr);
      if (this->field_0x2f8 == 1) {
        draw_nut(this);
      }
      else {
        draw_norm(this);
      }
      if ((((this->parent).mpGrabbedShadowModel == (J3DModel *)0x0) &&
          (d_a_bomb::_4477 != (this->mBgSAcch).field_0x94)) &&
         (pFloorNrm = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                      (uint)(ushort)(this->mBgSAcch).mGndChk.parent.mPolyInfo.
                                                    mBgIndex,
                                      (uint)(ushort)(this->mBgSAcch).mGndChk.parent.mPolyInfo.
                                                    mTriIdx), pFloorNrm != (cM3dGPla *)0x0)) {
        dDlst_shadowControl_c::setSimple
                  (&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mShadowControl,
                   &(this->parent).mCurrent.mPos,(this->mBgSAcch).field_0x94,d_a_bomb::_4478,
                   (cXyz *)pFloorNrm,0,d_a_bomb::1_0,&dDlst_shadowControl_c::mSimpleTexObj);
      }
    }
  }
  return 1;
}


namespace d_a_bomb {

/* __stdcall daBomb_Draw(daBomb_c *) */

void daBomb_Draw(daBomb_c *param_1)

{
  ::daBomb_c::draw(param_1);
  return;
}

}

/* WARNING: Type propagation algorithm not settling */
/* __thiscall daBomb_c::checkExplodeCc_norm(void) */

bool __thiscall daBomb_c::checkExplodeCc_norm(daBomb_c *this)

{
  int iVar1;
  cCcD_Obj *pcVar2;
  cCcD_Obj__DamageTypes cVar3;
  bool bVar4;
  
  bVar4 = false;
  iVar1 = dCcD_GObjInf::ChkTgHit(&(this->mCcDSph).parent);
  if (iVar1 != 0) {
    pcVar2 = dCcD_GObjInf::GetTgHitObj(&(this->mCcDSph).parent);
    if (pcVar2 != (cCcD_Obj *)0x0) {
      cVar3 = (pcVar2->parent).mObjAt.mDamageTypes;
      if ((cVar3 & Bomb) == 0) {
        if ((cVar3 & DekuLeafWind) == 0) {
          bVar4 = true;
        }
      }
      else {
        bVar4 = true;
      }
    }
    (*(code *)((this->mCcDSph).parent.parent.parent.parent.vtbl)->ClrTgHit)(&this->mCcDSph);
  }
  if (bVar4) {
    iVar1 = procExplode_init(this);
    bVar4 = iVar1 != 0;
  }
  else {
    bVar4 = false;
  }
  return bVar4;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall daBomb_c::checkExplodeCc_nut(void) */

bool __thiscall daBomb_c::checkExplodeCc_nut(daBomb_c *this)

{
  bool bVar1;
  bool bVar2;
  float fVar3;
  int iVar4;
  cCcD_Obj *pcVar5;
  cCcD_Obj__DamageTypes cVar6;
  bool bVar7;
  
  bVar1 = false;
  bVar2 = false;
  iVar4 = dCcD_GObjInf::ChkTgHit(&(this->mCcDSph).parent);
  if (iVar4 != 0) {
    pcVar5 = dCcD_GObjInf::GetTgHitObj(&(this->mCcDSph).parent);
    if (pcVar5 != (cCcD_Obj *)0x0) {
      cVar6 = (pcVar5->parent).mObjAt.mDamageTypes;
      if ((cVar6 & Bomb) == 0) {
        if ((cVar6 & DekuLeafWind) == 0) {
          bVar2 = true;
        }
      }
      else {
        bVar1 = true;
      }
    }
    (*(code *)((this->mCcDSph).parent.parent.parent.parent.vtbl)->ClrTgHit)(&this->mCcDSph);
  }
  iVar4 = dCcD_GObjInf::ChkCoHit(&(this->mCcDSph).parent);
  if (iVar4 != 0) {
    if (this->field_0x780 != 0) {
      bVar2 = true;
    }
    (*(code *)((this->mCcDSph).parent.parent.parent.parent.vtbl)->ClrCoHit)(&this->mCcDSph);
  }
  bVar7 = false;
  if (bVar1) {
    iVar4 = procExplode_init(this);
    bVar7 = iVar4 != 0;
  }
  else {
    if (bVar2) {
      change_state(this,1);
      setFuseEffect(this);
      if (0x1e < this->field_0x6fc) {
        this->field_0x6fc = 0x1e;
        fVar3 = d_a_bomb::_4531;
        *(float *)(*(int *)&this->field_0x2bc + 0x10) = d_a_bomb::_4531;
        *(float *)(*(int *)&this->field_0x2e4 + 0x10) = fVar3;
      }
    }
  }
  return bVar7;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall daBomb_c::checkExplodeCc_cannon(void) */

bool __thiscall daBomb_c::checkExplodeCc_cannon(daBomb_c *this)

{
  int iVar1;
  cCcD_Obj *pcVar2;
  bool bVar3;
  
  bVar3 = false;
  iVar1 = dCcD_GObjInf::ChkTgHit(&(this->mCcDSph).parent);
  if (iVar1 != 0) {
    pcVar2 = dCcD_GObjInf::GetTgHitObj(&(this->mCcDSph).parent);
    if ((pcVar2 != (cCcD_Obj *)0x0) && (((pcVar2->parent).mObjAt.mDamageTypes & DekuLeafWind) == 0))
    {
      bVar3 = true;
    }
    (*(code *)((this->mCcDSph).parent.parent.parent.parent.vtbl)->ClrTgHit)(&this->mCcDSph);
  }
  iVar1 = dCcD_GObjInf::ChkCoHit(&(this->mCcDSph).parent);
  if (iVar1 != 0) {
    bVar3 = true;
    (*(code *)((this->mCcDSph).parent.parent.parent.parent.vtbl)->ClrCoHit)(&this->mCcDSph);
  }
  if (bVar3) {
    iVar1 = procExplode_init(this);
    bVar3 = iVar1 != 0;
  }
  else {
    bVar3 = false;
  }
  return bVar3;
}


/* __thiscall daBomb_c::checkExplodeCc(void) */

void __thiscall daBomb_c::checkExplodeCc(daBomb_c *this)

{
  undefined *puVar1;
  
  if (0 < this->field_0x6fc) {
    puVar1 = &DAT_80390000;
    if (d_a_bomb::init_4555 == '\0') {
      d_a_bomb::proc_4551 = d_a_bomb::_4552;
      DAT_80389df8 = DAT_80389dd4;
      DAT_80389dfc = PTR_checkExplodeCc_norm_80389dd8;
      DAT_80389e00 = d_a_bomb::_4553;
      DAT_80389e04 = DAT_80389de0;
      DAT_80389e08 = PTR_checkExplodeCc_nut_80389de4;
      DAT_80389e0c = d_a_bomb::_4554;
      DAT_80389e10 = DAT_80389dec;
      DAT_80389e14 = PTR_checkExplodeCc_cannon_80389df0;
      d_a_bomb::init_4555 = '\x01';
      puVar1 = d_a_bomb::_4554;
    }
    Runtime.PPCEABI.H::__ptmf_scall
              ((PTMF *)(&d_a_bomb::proc_4551 + this->field_0x2f8 * 3),this,puVar1);
  }
  return;
}


/* __thiscall daBomb_c::checkExplodeTimer(void) */

bool __thiscall daBomb_c::checkExplodeTimer(daBomb_c *this)

{
  short sVar1;
  char cVar3;
  int iVar2;
  bool bVar4;
  
  bVar4 = false;
  cVar3 = @unnamed@d_a_bomb_cpp@::chk_attrState(this,0x200);
  if (cVar3 == '\0') {
    if (0 < this->field_0x6fc) {
      sVar1 = this->field_0x6fc + -1;
      this->field_0x6fc = sVar1;
      if (sVar1 == 0) {
        iVar2 = procExplode_init(this);
        bVar4 = iVar2 != 0;
      }
    }
  }
  return bVar4;
}


/* __thiscall daBomb_c::checkExplode(void) */

undefined4 __thiscall daBomb_c::checkExplode(daBomb_c *this)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  cVar1 = checkExplodeCc(this);
  if ((cVar1 != '\0') || (cVar1 = checkExplodeTimer(this), cVar1 != '\0')) {
    uVar2 = 1;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall daBomb_c::checkExplodeBg_norm(void) */

bool __thiscall daBomb_c::checkExplodeBg_norm(daBomb_c *this)

{
  char cVar2;
  char cVar3;
  char cVar4;
  int iVar1;
  bool bVar5;
  
  cVar2 = chk_water_sink(this);
  cVar3 = chk_water_land(this);
  cVar4 = chk_lava_hit(this);
  if (cVar2 != '\0') {
    this->field_0x781 = 1;
  }
  if (cVar3 != '\0') {
    eff_water_splash(this);
  }
  if (cVar4 == '\0') {
    bVar5 = false;
  }
  else {
    iVar1 = procExplode_init(this);
    bVar5 = iVar1 != 0;
  }
  return bVar5;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daBomb_c::checkExplodeBg_nut(void) */

bool __thiscall daBomb_c::checkExplodeBg_nut(daBomb_c *this)

{
  bool bVar1;
  float fVar2;
  char cVar4;
  char cVar5;
  int iVar3;
  uint uVar6;
  bool bVar7;
  
  cVar4 = chk_water_in(this);
  cVar5 = chk_lava_hit(this);
  bVar1 = true;
  bVar7 = false;
  uVar6 = (this->mBgSAcch).mFlags;
  if (((uVar6 & 0x10) != 0) || ((uVar6 & 0x20) != 0)) {
    bVar7 = true;
  }
  if ((!bVar7) && ((uVar6 & 0x200) == 0)) {
    bVar1 = false;
  }
  bVar7 = false;
  if (cVar5 == '\0') {
    if (cVar4 == '\0') {
      if ((bVar1) && (this->field_0x780 != 0)) {
        change_state(this,1);
        setFuseEffect(this);
        if (0x1e < this->field_0x6fc) {
          this->field_0x6fc = 0x1e;
          fVar2 = d_a_bomb::_4531;
          *(float *)(*(int *)&this->field_0x2bc + 0x10) = d_a_bomb::_4531;
          *(float *)(*(int *)&this->field_0x2e4 + 0x10) = fVar2;
        }
      }
    }
    else {
      makeWaterEffect(this);
      this->field_0x781 = 1;
    }
  }
  else {
    iVar3 = procExplode_init(this);
    bVar7 = iVar3 != 0;
  }
  return bVar7;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall daBomb_c::checkExplodeBg_cannon(void) */

bool __thiscall daBomb_c::checkExplodeBg_cannon(daBomb_c *this)

{
  bool bVar1;
  bool bVar2;
  char cVar4;
  char cVar5;
  char cVar6;
  int iVar3;
  uint uVar7;
  
  cVar4 = chk_water_in(this);
  cVar5 = chk_lava_hit(this);
  bVar2 = true;
  bVar1 = false;
  uVar7 = (this->mBgSAcch).mFlags;
  if (((uVar7 & 0x10) != 0) || ((uVar7 & 0x20) != 0)) {
    bVar1 = true;
  }
  if ((!bVar1) && ((uVar7 & 0x200) == 0)) {
    bVar2 = false;
  }
  cVar6 = chk_dead_zone(this);
  if ((cVar5 != '\0') || (bVar2)) {
    iVar3 = procExplode_init(this);
    return iVar3 != 0;
  }
  if (cVar4 != '\0') {
    makeWaterEffect(this);
    this->field_0x781 = 1;
    return false;
  }
  if (cVar6 == '\0') {
    return false;
  }
  this->field_0x781 = 1;
  return false;
}


/* __thiscall daBomb_c::checkExplodeBg(void) */

void __thiscall daBomb_c::checkExplodeBg(daBomb_c *this)

{
  undefined *puVar1;
  
  puVar1 = &DAT_80390000;
  if (d_a_bomb::init_4644 == '\0') {
    d_a_bomb::proc_4640 = d_a_bomb::_4641;
    DAT_80389e40 = DAT_80389e1c;
    DAT_80389e44 = PTR_checkExplodeBg_norm_80389e20;
    DAT_80389e48 = d_a_bomb::_4642;
    DAT_80389e4c = DAT_80389e28;
    DAT_80389e50 = PTR_checkExplodeBg_nut_80389e2c;
    DAT_80389e54 = d_a_bomb::_4643;
    DAT_80389e58 = DAT_80389e34;
    DAT_80389e5c = PTR_checkExplodeBg_cannon_80389e38;
    d_a_bomb::init_4644 = '\x01';
    puVar1 = d_a_bomb::_4643;
  }
  Runtime.PPCEABI.H::__ptmf_scall
            ((PTMF *)(&d_a_bomb::proc_4640 + this->field_0x2f8 * 3),this,puVar1);
  return;
}


/* __thiscall daBomb_c::water_tention(void) */

void __thiscall daBomb_c::water_tention(daBomb_c *this)

{
  float fVar1;
  float fVar2;
  char cVar3;
  
  cVar3 = chk_water_in(this);
  if (((cVar3 != '\0') && (fVar1 = (this->field_0x554).y, d_a_bomb::_4477 != fVar1)) &&
     (fVar2 = (this->field_0x554).z, d_a_bomb::_4477 != fVar2)) {
    fVar1 = fVar1 - fVar2;
    fVar2 = d_a_bomb::_4662;
    if (fVar1 < d_a_bomb::_4271) {
      fVar2 = d_a_bomb::_4661;
    }
    (this->parent).mCurrent.mPos.y = (this->parent).mCurrent.mPos.y + fVar2 * fVar1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x800da500) */
/* __thiscall daBomb_c::posMoveF(void) */

void __thiscall daBomb_c::posMoveF(daBomb_c *this)

{
  float fVar1;
  uint uVar2;
  char cVar4;
  cM3dGPla *pcVar3;
  undefined4 uVar5;
  double in_f31;
  float fVar6;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,SUB84(in_f31,0),0);
  uVar2 = -(int)this->field_0x700 & ~(int)this->field_0x700;
  if ((int)uVar2 < 0) {
    in_f31 = (double)(this->parent).mAccelerationY;
    (this->parent).mAccelerationY = d_a_bomb::_4271;
  }
  if ((this->field_0x2f8 == 0) &&
     (cVar4 = chk_water_in(this), fVar6 = d_a_bomb::_4691, cVar4 != '\0')) {
    (this->parent).mVelocity.y = (this->parent).mVelocity.y * d_a_bomb::_4691;
    (this->parent).mVelocityFwd = (this->parent).mVelocityFwd * fVar6;
  }
  cVar4 = chk_state(this,5);
  if (((cVar4 == '\0') && (cVar4 = chk_state(this,6), cVar4 == '\0')) &&
     (*(char *)&this->field_0x6f3 != '\x01')) {
    water_tention(this);
    pcVar3 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                             (uint)(ushort)(this->mBgSAcch).mGndChk.parent.mPolyInfo.mBgIndex,
                             (uint)(ushort)(this->mBgSAcch).mGndChk.parent.mPolyInfo.mTriIdx);
    fVar6 = mtx::PSVECSquareMag((cXyz *)&this->field_0x788);
    if (fVar6 <= d_a_bomb::_4692) {
      f_op_actor_mng::fopAcM_posMoveF(&this->parent,(cXyz *)&this->mCcDStts);
    }
    else {
      if (pcVar3 == (cM3dGPla *)0x0) {
        pcVar3 = (cM3dGPla *)0x0;
        fVar6 = d_a_bomb::_4271;
        fVar1 = d_a_bomb::_4271;
      }
      else {
        fVar6 = d_a_bomb::_4693;
        fVar1 = JKernel::JMath::jmaCosTable[0xa4f >> (JKernel::JMath::jmaSinShift & 0x3f)];
      }
      ::daObj::posMoveF_grade
                (&this->parent,(cXyz *)&this->mCcDStts,(cXyz *)&this->field_0x788,d_a_bomb::_4694,
                 d_a_bomb::_4695,(cXyz *)pcVar3,fVar6,fVar1,(cXyz *)0x0);
    }
  }
  if ((int)uVar2 < 0) {
    (this->parent).mAccelerationY = (float)in_f31;
    this->field_0x700 = this->field_0x700 + -1;
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* __thiscall daBomb_c::bgCrrPos(void) */

void __thiscall daBomb_c::bgCrrPos(daBomb_c *this)

{
  dBgS_Acch::CrrPos(&this->mBgSAcch,&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS);
  bgCrrPos_lava(this);
  bgCrrPos_water(this);
  setRoomInfo(this);
  return;
}


/* __thiscall daBomb_c::bgCrrPos_lava(void) */

void __thiscall daBomb_c::bgCrrPos_lava(daBomb_c *this)

{
  float fVar1;
  float fVar2;
  double dVar3;
  
  fVar1 = (this->parent).mCurrent.mPos.z;
  fVar2 = d_a_bomb::1_0 + (this->parent).mNext.mPos.y;
  *(float *)&this->field_0x524 = (this->parent).mCurrent.mPos.x;
  *(float *)&this->field_0x528 = fVar2;
  *(float *)&this->field_0x52c = fVar1;
  dVar3 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                    (cBgS_GndChk *)&this->field_0x500);
  (this->field_0x554).x = (float)dVar3;
  return;
}


/* WARNING: Removing unreachable block (ram,0x800da6e0) */
/* __thiscall daBomb_c::bgCrrPos_water(void) */

void __thiscall daBomb_c::bgCrrPos_water(daBomb_c *this)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  undefined uVar4;
  uint uVar5;
  undefined4 uVar6;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar8 = (double)(this->mBgSAcch).mWtrChk.parent.mHeight;
  uVar3 = d_a_sea::daSea_ChkArea((this->parent).mCurrent.mPos.x,(this->parent).mCurrent.mPos.z);
  dVar7 = (double)d_a_sea::daSea_calcWave
                            ((double)(this->parent).mCurrent.mPos.x,
                             (double)(this->parent).mCurrent.mPos.z);
  uVar5 = (this->mBgSAcch).mFlags >> 0xc & 1;
  bVar1 = false;
  if (((uVar3 & 0xff) != 0) && ((double)(this->parent).mCurrent.mPos.y < dVar7)) {
    bVar1 = true;
  }
  bVar2 = false;
  (this->field_0x554).z = (this->field_0x554).y;
  if ((uVar5 != 0) && (bVar1)) {
    if (dVar8 <= dVar7) {
      uVar5 = 0;
    }
    else {
      bVar1 = false;
    }
  }
  if (uVar5 == 0) {
    if (bVar1) {
      (this->field_0x554).y = (float)dVar7;
      bVar2 = true;
      *(undefined *)&this->field_0x562 = 1;
    }
    else {
      (this->field_0x554).y = d_a_bomb::_4477;
      *(undefined *)&this->field_0x562 = 0;
    }
  }
  else {
    (this->field_0x554).y = (float)dVar8;
    bVar2 = true;
    *(undefined *)&this->field_0x562 = 0;
  }
  uVar4 = 0;
  if ((bVar2) && (*(char *)&this->field_0x561 == '\0')) {
    uVar4 = 1;
  }
  *(undefined *)&this->field_0x560 = uVar4;
  *(bool *)&this->field_0x561 = bVar2;
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return;
}


/* __thiscall daBomb_c::chk_water_land(void) */

undefined __thiscall daBomb_c::chk_water_land(daBomb_c *this)

{
  return *(undefined *)&this->field_0x560;
}


/* __thiscall daBomb_c::chk_water_in(void) */

undefined __thiscall daBomb_c::chk_water_in(daBomb_c *this)

{
  return *(undefined *)&this->field_0x561;
}


/* __thiscall daBomb_c::chk_water_sink(void) */

undefined4 __thiscall daBomb_c::chk_water_sink(daBomb_c *this)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = chk_water_in(this);
  uVar2 = 0;
  if ((cVar1 != '\0') && (d_a_bomb::_4753 < (this->field_0x554).y - (this->parent).mCurrent.mPos.y))
  {
    uVar2 = 1;
  }
  return uVar2;
}


/* __thiscall daBomb_c::chk_lava_hit(void) */

uint __thiscall daBomb_c::chk_lava_hit(daBomb_c *this)

{
  float fVar1;
  
  fVar1 = (this->field_0x554).x;
  if (d_a_bomb::_4477 == fVar1) {
    return 0;
  }
  return ((uint)(byte)(((this->parent).mCurrent.mPos.y < fVar1) << 3) << 0x1c) >> 0x1f;
}


/* __thiscall daBomb_c::chk_dead_zone(void) */

undefined4 __thiscall daBomb_c::chk_dead_zone(daBomb_c *this)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((d_a_bomb::_4477 == (this->mBgSAcch).field_0x94) &&
      (d_a_bomb::_4477 == (this->field_0x554).y)) && (d_a_bomb::_4477 == (this->field_0x554).x)) {
    uVar1 = 1;
  }
  return uVar1;
}


/* WARNING: Removing unreachable block (ram,0x800da8ac) */
/* __thiscall daBomb_c::bound(float) */

void __thiscall daBomb_c::bound(daBomb_c *this,float param_1)

{
  float fVar1;
  uint uVar2;
  dBgS_GndChk *in_r5;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar4 = (double)param_1;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (((this->mBgSAcch).mFlags & 0x10) != 0) {
    (this->parent).mVelocityFwd = (this->parent).mVelocityFwd * d_a_bomb::_4661;
    (this->parent).mCurrent.mRot.y =
         (short)((int)(this->mBgSAcchCir).field_0x3c << 1) -
         ((this->parent).mCurrent.mRot.y + -0x8000);
  }
  uVar2 = (this->mBgSAcch).mFlags;
  if ((uVar2 & 0x80) == 0) {
    if ((uVar2 & 0x20) != 0) {
      SComponent::cLib_addCalc
                (&(this->parent).mVelocityFwd,d_a_bomb::_4271,d_a_bomb::_4275,d_a_bomb::_4797,
                 d_a_bomb::1_0);
    }
  }
  else {
    ::daObj::make_land_effect
              ((daObj *)this,(fopAc_ac_c *)&(this->mBgSAcch).mGndChk,in_r5,d_a_bomb::_4793);
    fVar1 = (float)(dVar4 * (double)d_a_bomb::_4794);
    if (d_a_bomb::_4795 <= fVar1) {
      (this->parent).mVelocityFwd = (this->parent).mVelocityFwd * d_a_bomb::_4691;
      if (fVar1 <= d_a_bomb::_4796) {
        (this->parent).mVelocity.y = fVar1;
      }
      else {
        (this->parent).mVelocity.y = d_a_bomb::_4796;
      }
    }
    else {
      this->field_0x780 = 0;
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall daBomb_c::set_real_shadow_flag(void) */

void __thiscall daBomb_c::set_real_shadow_flag(daBomb_c *this)

{
  bool bVar1;
  daPy_lk_c *pdVar2;
  J3DModel *pJVar3;
  char cVar5;
  char cVar6;
  uint uVar4;
  uint uVar7;
  
  cVar5 = chk_state(this,2);
  cVar6 = chk_state(this,3);
  pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  bVar1 = false;
  if (this->field_0x7c8 < 2) {
    if ((cVar5 != '\0') || (cVar6 != '\0')) {
      if ((this->parent).mpGrabbedShadowModel == (J3DModel *)0x0) {
        if (cVar6 == '\0') {
          if (this->field_0x7c8 == 1) {
            bVar1 = true;
          }
          else {
            if (this == (daBomb_c *)0x0) {
              uVar7 = 0xffffffff;
            }
            else {
              uVar7 = (this->parent).parent.parent.mBsPcId;
            }
            uVar4 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->vtbl->
                              getGrabActorID)
                              (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor);
            if ((uVar4 == uVar7) && (((pdVar2->parent).field_0x2a4 & 0x8000) != 0)) {
              bVar1 = true;
            }
          }
        }
        else {
          bVar1 = true;
        }
      }
      else {
        bVar1 = true;
      }
    }
  }
  if (0 < this->field_0x7c8) {
    this->field_0x7c8 = this->field_0x7c8 + -1;
  }
  if (bVar1) {
    pJVar3 = this->mpModel;
  }
  else {
    pJVar3 = (J3DModel *)0x0;
  }
  (this->parent).mpGrabbedShadowModel = pJVar3;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daBomb_c::setRoomInfo(void) */

void __thiscall daBomb_c::setRoomInfo(daBomb_c *this)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = dStage_roomControl_c::mStayNo;
  if (d_a_bomb::_4477 != (this->mBgSAcch).field_0x94) {
    bVar1 = dBgS::GetRoomId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                            &(this->mBgSAcch).mGndChk.parent.mPolyInfo);
    bVar2 = dBgS::GetPolyColor(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                               &(this->mBgSAcch).mGndChk.parent.mPolyInfo);
    (this->parent).mTevStr.mEnvrIdxOverride = bVar2;
  }
  (this->parent).mTevStr.mRoomNo = bVar1;
  (this->mCcDStts).mGStts.mRoomNo = bVar1;
  (this->parent).mCurrent.mRoomNo = bVar1;
  return;
}


/* __thiscall daBomb_c::makeFireEffect(cXyz &,
                                       csXyz &) */

void __thiscall daBomb_c::makeFireEffect(daBomb_c *this,cXyz *param_1,csXyz *param_2)

{
  cXyz local_20;
  cXyz local_14;
  
  local_14.x = d_a_bomb::_4869;
  local_14.y = d_a_bomb::_4869;
  local_14.z = d_a_bomb::_4869;
  param_2->x = param_2->x + 0x4000;
  dPa_control_c::setBombSmoke
            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0x200a,param_1,param_2,&local_14
             ,0xff);
  local_20.x = d_a_bomb::_4271;
  local_20.y = d_a_bomb::1_0;
  local_20.z = d_a_bomb::_4271;
  dVibration_c::StartShock(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,7,-0x21,&local_20);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall daBomb_c::makeWaterEffect(void) */

void __thiscall daBomb_c::makeWaterEffect(daBomb_c *this)

{
  sbyte sVar1;
  
  if (*(char *)&this->field_0x77d == '\0') {
    sVar1 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x6982,&(this->parent).mEyePos,0,sVar1,d_a_bomb::1_0,
               d_a_bomb::1_0,d_a_bomb::_4895,d_a_bomb::_4895,0);
    f_op_kankyo_mng::fopKyM_createWpillar
              ((double)d_a_bomb::1_0,(double)d_a_bomb::1_0,&(this->parent).mCurrent,1);
    (this->mCcDSph).parent.parent.parent.parent.mObjTg.parent.mCommonFlag =
         (this->mCcDSph).parent.parent.parent.parent.mObjTg.parent.mCommonFlag & ~EnableCheck;
    (this->mCcDSph).parent.parent.parent.parent.mObjCo.parent.mCommonFlag =
         (this->mCcDSph).parent.parent.parent.parent.mObjCo.parent.mCommonFlag & ~EnableCheck;
    (this->mCcDSph).parent.parent.parent.parent.mObjAt.parent.mCommonFlag =
         (this->mCcDSph).parent.parent.parent.parent.mObjAt.parent.mCommonFlag | 1;
    ::cM3dGSph::SetR(&(this->mCcDSph).mSphAttr.mSph,d_a_bomb::_4896);
    ::cM3dGSph::SetC(&(this->mCcDSph).mSphAttr.mSph,&(this->parent).mCurrent.mPos);
    if (this->field_0x7c4 != SComponent::g_Counter) {
      cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)&this->mCcDSph);
      dCcMassS_Mng::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng,
                        (cCcD_Obj *)&this->mCcDSph,3);
      this->field_0x7c4 = SComponent::g_Counter;
      this->field_0x782 = 1;
    }
    *(undefined *)&this->field_0x77d = 1;
  }
  return;
}


/* __thiscall daBomb_c::setFuseEffect(void) */

void __thiscall daBomb_c::setFuseEffect(daBomb_c *this)

{
  if (this->field_0x77e == 0) {
    this->field_0x77e = 1;
    (this->field_0x704).x = (this->parent).mCurrent.mPos.x;
    (this->field_0x704).y = d_a_bomb::_4917 + (this->parent).mCurrent.mPos.y;
    (this->field_0x704).z = (this->parent).mCurrent.mPos.z;
    (this->field_0x710).x = (this->field_0x704).x;
    (this->field_0x710).y = (this->field_0x704).y;
    (this->field_0x710).z = (this->field_0x704).z;
    (this->field_0x71c).x = (this->field_0x704).x;
    (this->field_0x71c).y = (this->field_0x704).y;
    (this->field_0x71c).z = (this->field_0x704).z;
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,1,0x11,
                       &this->field_0x704,(csXyz *)0x0,&(this->parent).mScale,0xff,
                       (dPa_levelEcallBack *)&this->field_0x6e4,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                       (cXyz *)0x0);
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,3,0x2012,
                       &this->field_0x704,(csXyz *)0x0,&(this->parent).mScale,0xdc,
                       (dPa_levelEcallBack *)&this->field_0x6cc,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                       (cXyz *)0x0);
    this->field_0x6d8 = &this->field_0x710;
    this->field_0x6dc = &this->field_0x71c;
    this->field_0x6d0 = 0x14;
  }
  return;
}


/* __thiscall daBomb_c::eff_explode_normal(csXyz const *) */

void __thiscall daBomb_c::eff_explode_normal(daBomb_c *this,csXyz *param_1)

{
  dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,1,0xb,
                     &(this->parent).mCurrent.mPos,param_1,&(this->parent).mScale,0xff,
                     (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
  dPa_control_c::setBombSmoke
            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0x2009,
             &(this->parent).mCurrent.mPos,(csXyz *)0x0,&(this->parent).mScale,0xff);
  dPa_control_c::setBombSmoke
            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0x200a,
             &(this->parent).mCurrent.mPos,(csXyz *)0x0,&(this->parent).mScale,0xff);
  dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,3,0x2008,
                     &(this->parent).mCurrent.mPos,(csXyz *)0x0,&(this->parent).mScale,0xff,
                     (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
  return;
}


/* __thiscall daBomb_c::eff_explode_cheap(csXyz const *) */

void __thiscall daBomb_c::eff_explode_cheap(daBomb_c *this,csXyz *param_1)

{
  JPABaseEmitter *pJVar1;
  int iVar2;
  
  pJVar1 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,1,0xb,
                              &(this->parent).mCurrent.mPos,param_1,&(this->parent).mScale,0xff,
                              (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                              (cXyz *)0x0);
  if (pJVar1 != (JPABaseEmitter *)0x0) {
    pJVar1->mLifeTime = 0xc;
    (pJVar1->mGlobalScale2D).x = d_a_bomb::_4275;
    (pJVar1->mGlobalScale2D).y = d_a_bomb::_4968;
    (pJVar1->mGlobalScale2D).z = d_a_bomb::1_0;
  }
  dPa_control_c::setBombSmoke
            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0x232a,
             &(this->parent).mCurrent.mPos,(csXyz *)0x0,&(this->parent).mScale,0xff);
  iVar2 = dPa_control_c::setBombSmoke
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0x200a,
                     &(this->parent).mCurrent.mPos,(csXyz *)0x0,&(this->parent).mScale,0xff);
  if (iVar2 != 0) {
    *(undefined2 *)(iVar2 + 100) = 0x46;
  }
  pJVar1 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,3,0x2008,
                              &(this->parent).mCurrent.mPos,(csXyz *)0x0,&(this->parent).mScale,0xff
                              ,(dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                              (cXyz *)0x0);
  if (pJVar1 != (JPABaseEmitter *)0x0) {
    pJVar1->mLifeTime = 0x46;
    pJVar1->mInitialVelAxis = d_a_bomb::_4478;
    pJVar1->mInitialVelDir = d_a_bomb::_4969;
  }
  return;
}


/* __thiscall daBomb_c::eff_explode(void) */

void __thiscall daBomb_c::eff_explode(daBomb_c *this)

{
  char cVar1;
  camera_class *pcVar2;
  csXyz local_18 [3];
  
  pcVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo
           [(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCamera].mpCamera;
  local_18[0].x = -pcVar2->field_0x230;
  local_18[0].y = pcVar2->field_0x232 + -0x8000;
  local_18[0].z = 0;
  cVar1 = prm_get_cheapEff(this);
  if (cVar1 == '\0') {
    eff_explode_normal(this,local_18);
  }
  else {
    eff_explode_cheap(this,local_18);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall daBomb_c::procExplode_init(void) */

undefined4 __thiscall daBomb_c::procExplode_init(daBomb_c *this)

{
  undefined4 uVar1;
  float fVar2;
  char cVar4;
  int iVar3;
  sbyte sVar5;
  uint uVar6;
  cBgS_PolyPassChk *pcVar7;
  double dVar8;
  float local_b8;
  cXyz local_b4;
  cXyz local_a8;
  float local_9c;
  float local_98;
  float local_94;
  cBgS_GndChk local_90;
  cBgS_PolyPassChk local_50;
  undefined local_44 [24];
  
  if (this == (daBomb_c *)0x0) {
    uVar6 = 0xffffffff;
  }
  else {
    uVar6 = (this->parent).parent.parent.mBsPcId;
  }
  dCamera_c::ForceLockOff
            (&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo
               [(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCamera].mpCamera)->mBody,uVar6);
  cVar4 = chk_state(this,8);
  if (cVar4 == '\0') {
    uVar6 = 0;
  }
  else {
    uVar6 = f_op_actor_mng::fopAcM_getWaterY(&(this->parent).mCurrent.mPos,&local_b8);
    if (uVar6 != 0) {
      ::cBgS_GndChk::cBgS_GndChk(&local_90);
      pcVar7 = &local_50;
      local_50.mbCamThrough = 0;
      local_50.mbLinkThrough = 0;
      local_50.mbArrowsAndLightThrough = 0;
      local_50.mbBombThrough = 0;
      local_50.mbBoomerangThrough = 0;
      local_50.mbHookshotThrough = 0;
      local_44._4_4_ = 1;
      local_90.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar7;
      if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
        local_90.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_44;
      }
      local_90.parent.vtbl = &::dBgS_ObjGndChk::__vt;
      local_90.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371ed8;
      local_50.vtbl = &cBgS_PolyPassChk__vtbl_80371ee4;
      local_44._0_4_ = &cBgS_GrpPassChk__vtbl_80371ef0;
      local_50.mbObjThrough = 1;
      local_94 = (this->parent).mCurrent.mPos.z;
      local_98 = d_a_bomb::1_0 + (this->parent).mCurrent.mPos.y;
      local_9c = (this->parent).mCurrent.mPos.x;
      local_90.parent.mpPolyPassChk = pcVar7;
      local_90.mPos.x = local_9c;
      local_90.mPos.y = local_98;
      local_90.mPos.z = local_94;
      dVar8 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_90)
      ;
      if (((double)local_b8 < dVar8) ||
         ((float)((double)d_a_bomb::_5171 + (double)local_b8) < (this->parent).mCurrent.mPos.y)) {
        uVar6 = 0;
      }
      local_50.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
      local_44._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
      if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
        local_50.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
        local_44._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
        if (((undefined *)register0x00000004 != &DAT_00000044) &&
           (local_44._0_4_ = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
           (undefined *)register0x00000004 != &DAT_00000044)) {
          local_44._0_4_ = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
        }
        if ((pcVar7 != (cBgS_PolyPassChk *)0x0) &&
           (local_50.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
           pcVar7 != (cBgS_PolyPassChk *)0x0)) {
          local_50.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
        }
      }
      local_90.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
      local_90.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
      cBgS_Chk::_cBgS_Chk(&local_90.parent);
    }
  }
  if (uVar6 == 0) {
    eff_explode(this);
  }
  else {
    f_op_kankyo_mng::fopKyM_createWpillar
              ((double)d_a_bomb::1_0,(double)d_a_bomb::1_0,&(this->parent).mCurrent,1);
  }
  if (*(int *)&this->field_0x6e0 != 0) {
    *(undefined4 *)(*(int *)&this->field_0x6e0 + 0x19c) = 0;
    iVar3 = *(int *)&this->field_0x6e0;
    *(undefined4 *)(iVar3 + 0x60) = 0xffffffff;
    *(uint *)(iVar3 + 0x20c) = *(uint *)(iVar3 + 0x20c) | 1;
  }
  *(undefined4 *)&this->field_0x6e0 = 0;
  if (*(int *)&this->field_0x6ec != 0) {
    *(undefined4 *)(*(int *)&this->field_0x6ec + 0x19c) = 0;
    iVar3 = *(int *)&this->field_0x6ec;
    *(undefined4 *)(iVar3 + 0x60) = 0xffffffff;
    *(uint *)(iVar3 + 0x20c) = *(uint *)(iVar3 + 0x20c) | 1;
  }
  *(undefined4 *)&this->field_0x6ec = 0;
  *(float *)&this->field_0x728 = (this->parent).mCurrent.mPos.x;
  *(float *)&this->field_0x72c = (this->parent).mCurrent.mPos.y;
  *(float *)&this->field_0x730 = (this->parent).mCurrent.mPos.z;
  fVar2 = d_a_bomb::_5172;
  *(float *)&this->field_0x72c = *(float *)&this->field_0x72c + d_a_bomb::_5172;
  *(undefined2 *)&this->field_0x734 = 200;
  *(undefined2 *)&this->field_0x736 = 200;
  *(undefined2 *)&this->field_0x738 = 0xa0;
  this->field_0x73c = d_a_bomb::_5173;
  *(float *)&this->field_0x740 = fVar2;
  d_kankyo::dKy_efplight_set((LIGHT_INFLUENCE *)&this->field_0x728);
  *(float *)&this->field_0x748 = (this->parent).mCurrent.mPos.x;
  *(float *)&this->field_0x74c = (this->parent).mCurrent.mPos.y;
  *(float *)&this->field_0x750 = (this->parent).mCurrent.mPos.z;
  fVar2 = d_a_bomb::_4271;
  *(float *)&this->field_0x754 = d_a_bomb::_4271;
  *(float *)&this->field_0x758 = d_a_bomb::1_0;
  *(float *)&this->field_0x75c = fVar2;
  *(float *)&this->field_0x760 = d_a_bomb::_5174;
  *(float *)&this->field_0x768 = fVar2;
  this->field_0x764 = d_a_bomb::_4275;
  d_kankyo_wether::dKyw_pntwind_set((WIND_INFLUENCE *)&this->field_0x748);
  this->field_0x774 = 0;
  fVar2 = d_a_bomb::_4271;
  this->field_0x778 = d_a_bomb::_4271;
  uVar1 = DAT_80389e64;
  *(undefined4 *)&this->field_0x290 = d_a_bomb::_5001;
  *(undefined4 *)&this->field_0x294 = uVar1;
  *(undefined **)&this->field_0x298 = PTR_procExplode_80389e68;
  (this->parent).mVelocityFwd = fVar2;
  (this->parent).mVelocity.x = ::cXyz::Zero.x;
  (this->parent).mVelocity.y = ::cXyz::Zero.y;
  (this->parent).mVelocity.z = ::cXyz::Zero.z;
  (this->parent).mAccelerationY = fVar2;
  cVar4 = chk_state(this,8);
  if (cVar4 == '\0') {
    change_state(this,0);
  }
  (this->parent).mAttentionFlags = (this->parent).mAttentionFlags & ~Action_Carry;
  if (*(char *)&this->field_0x6f0 != '\0') {
    if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->mActivePlayerBombs != 0) {
      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->mActivePlayerBombs =
           (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->mActivePlayerBombs - 1;
    }
    *(undefined *)&this->field_0x6f0 = 0;
  }
  (this->mCcDSph).parent.parent.parent.parent.mObjTg.parent.mCommonFlag =
       (this->mCcDSph).parent.parent.parent.parent.mObjTg.parent.mCommonFlag & ~EnableCheck;
  (this->mCcDSph).parent.parent.parent.parent.mObjCo.parent.mCommonFlag =
       (this->mCcDSph).parent.parent.parent.parent.mObjCo.parent.mCommonFlag & ~EnableCheck;
  (this->mCcDSph).parent.parent.parent.parent.mObjAt.parent.mCommonFlag =
       (this->mCcDSph).parent.parent.parent.parent.mObjAt.parent.mCommonFlag | 1;
  ::cM3dGSph::SetR(&(this->mCcDSph).mSphAttr.mSph,d_a_bomb::_4896);
  ::cM3dGSph::SetC(&(this->mCcDSph).mSphAttr.mSph,&(this->parent).mCurrent.mPos);
  if (this->field_0x7c4 != SComponent::g_Counter) {
    cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)&this->mCcDSph);
    dCcMassS_Mng::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng,
                      (cCcD_Obj *)&this->mCcDSph,3);
    this->field_0x782 = 1;
    this->field_0x7c4 = SComponent::g_Counter;
  }
  if (uVar6 == 0) {
    sVar5 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x6901,&(this->parent).mEyePos,0,sVar5,d_a_bomb::1_0,
               d_a_bomb::1_0,d_a_bomb::_4895,d_a_bomb::_4895,0);
  }
  else {
    sVar5 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x6982,&(this->parent).mEyePos,0,sVar5,d_a_bomb::1_0,
               d_a_bomb::1_0,d_a_bomb::_4895,d_a_bomb::_4895,0);
  }
  f_op_actor_mng::fopAcM_cancelCarryNow(this);
  local_a8.x = (this->parent).mCurrent.mPos.x;
  local_a8.y = (this->parent).mCurrent.mPos.y;
  local_a8.z = (this->parent).mCurrent.mPos.z;
  if (this == (daBomb_c *)0x0) {
    uVar6 = 0xffffffff;
  }
  else {
    uVar6 = (this->parent).parent.parent.mBsPcId;
  }
  d_kankyo::dKy_Sound_set(&local_a8,0xff,uVar6,10);
  this->field_0x6fc = 0;
  this->field_0x6fe = 2;
  local_b4.x = d_a_bomb::_4271;
  local_b4.y = d_a_bomb::1_0;
  local_b4.z = d_a_bomb::_4271;
  dVibration_c::StartShock(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,7,-0x21,&local_b4);
  se_cannon_fly_stop(this);
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x800db75c) */
/* WARNING: Removing unreachable block (ram,0x800db864) */
/* __thiscall daBomb_c::procExplode(void) */

undefined4 __thiscall daBomb_c::procExplode(daBomb_c *this)

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
  dVar5 = (double)d_a_bomb::_4271;
  this->field_0x73c = d_a_bomb::_5276 * this->field_0x778;
  this->field_0x764 = this->field_0x778;
  fVar6 = mtx::PSVECSquareDistance(&(this->parent).mCurrent.mPos,&pcVar1->mEyePos);
  dVar4 = (double)fVar6;
  if ((double)d_a_bomb::_4271 < dVar4) {
    dVar3 = 1.0 / SQRT(dVar4);
    dVar3 = d_a_bomb::_4272 * dVar3 * (d_a_bomb::_4273 - dVar4 * dVar3 * dVar3);
    dVar3 = d_a_bomb::_4272 * dVar3 * (d_a_bomb::_4273 - dVar4 * dVar3 * dVar3);
    dVar4 = (double)(float)(dVar4 * d_a_bomb::_4272 * dVar3 *
                                    (d_a_bomb::_4273 - dVar4 * dVar3 * dVar3));
  }
  if (dVar4 < (double)d_a_bomb::_5276) {
    dVar5 = (double)(d_a_bomb::1_0 - (float)(dVar4 / (double)d_a_bomb::_5276));
  }
  d_kankyo::dKy_actor_addcol_amb_set
            ((double)(float)((double)this->field_0x778 * dVar5),200,0xb4,100);
  d_kankyo::dKy_bg_addcol_amb_set((double)(float)((double)this->field_0x778 * dVar5),0xb4,0xa0,0x3c)
  ;
  d_kankyo::dKy_bg_addcol_dif_set((double)(float)((double)this->field_0x778 * dVar5),0xff,0xe1,0x78)
  ;
  if (this->field_0x774 == 1) {
    SComponent::cLib_addCalc
              (&this->field_0x778,d_a_bomb::_4271,d_a_bomb::0_05,d_a_bomb::_5280,d_a_bomb::_4374);
    if (this->field_0x778 <= d_a_bomb::_4692) {
      this->field_0x774 = this->field_0x774 + 1;
    }
  }
  else {
    if ((this->field_0x774 == 0) &&
       (SComponent::cLib_addCalc
                  (&this->field_0x778,d_a_bomb::1_0,d_a_bomb::_4275,d_a_bomb::_5277,d_a_bomb::_4692)
       , d_a_bomb::_5278 <= this->field_0x778)) {
      this->field_0x774 = this->field_0x774 + 1;
    }
  }
  if (this->field_0x6fe == 0) {
    if (1 < this->field_0x774) {
      this->field_0x781 = 1;
    }
  }
  else {
    this->field_0x6fe = this->field_0x6fe + -1;
    ::cM3dGSph::SetC(&(this->mCcDSph).mSphAttr.mSph,&(this->parent).mCurrent.mPos);
    if (this->field_0x7c4 != SComponent::g_Counter) {
      cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)&this->mCcDSph);
      dCcMassS_Mng::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng,
                        (cCcD_Obj *)&this->mCcDSph,3);
      this->field_0x7c4 = SComponent::g_Counter;
      this->field_0x782 = 1;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return 1;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall daBomb_c::procCarry_init(void) */

undefined4 __thiscall daBomb_c::procCarry_init(daBomb_c *this)

{
  undefined4 uVar1;
  char cVar2;
  
  cVar2 = @unnamed@d_a_bomb_cpp@::chk_attrState(this,0x100);
  if (cVar2 != '\0') {
    setFuseEffect(this);
  }
  uVar1 = DAT_80389e70;
  *(undefined4 *)&this->field_0x290 = d_a_bomb::_5286;
  *(undefined4 *)&this->field_0x294 = uVar1;
  *(undefined **)&this->field_0x298 = PTR_procCarry_80389e74;
  change_state(this,2);
  (this->parent).mVelocityFwd = d_a_bomb::_4271;
  (this->parent).mVelocity.x = ::cXyz::Zero.x;
  (this->parent).mVelocity.y = ::cXyz::Zero.y;
  (this->parent).mVelocity.z = ::cXyz::Zero.z;
  (this->parent).mAttentionFlags = (this->parent).mAttentionFlags & ~Action_Carry;
  (this->mCcDSph).parent.parent.parent.parent.mObjCo.parent.mCommonFlag =
       (this->mCcDSph).parent.parent.parent.parent.mObjCo.parent.mCommonFlag & ~EnableCheck;
  return 1;
}


/* __thiscall daBomb_c::procCarry(void) */

undefined4 __thiscall daBomb_c::procCarry(daBomb_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  char cVar5;
  
  if (((this->parent).mStatus & IsBeingCarried) == 0) {
    if (d_a_bomb::_4271 < (this->parent).mVelocityFwd) {
      this->field_0x780 = 1;
    }
    procWait_init(this);
    uVar4 = procWait(this);
  }
  else {
    cVar5 = checkExplode(this);
    if (cVar5 == '\0') {
      fVar1 = (this->parent).mCurrent.mPos.x;
      fVar2 = (this->parent).mCurrent.mPos.y;
      fVar3 = (this->parent).mCurrent.mPos.z;
      bgCrrPos(this);
      (this->parent).mCurrent.mPos.x = fVar1;
      (this->parent).mCurrent.mPos.y = fVar2;
      (this->parent).mCurrent.mPos.z = fVar3;
      uVar4 = 1;
    }
    else {
      uVar4 = 1;
    }
  }
  return uVar4;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall daBomb_c::procWait_init(void) */

undefined4 __thiscall daBomb_c::procWait_init(daBomb_c *this)

{
  undefined4 uVar1;
  char cVar2;
  
  uVar1 = DAT_80389e7c;
  *(undefined4 *)&this->field_0x290 = d_a_bomb::_5316;
  *(undefined4 *)&this->field_0x294 = uVar1;
  *(undefined **)&this->field_0x298 = PTR_procWait_80389e80;
  cVar2 = @unnamed@d_a_bomb_cpp@::chk_attrState(this,0x80);
  if (cVar2 != '\0') {
    change_state(this,1);
  }
  (this->mCcDSph).parent.parent.parent.parent.mObjCo.parent.mCommonFlag =
       (this->mCcDSph).parent.parent.parent.parent.mObjCo.parent.mCommonFlag | EnableCheck;
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x800dbb80) */
/* __thiscall daBomb_c::procWait(void) */

undefined4 __thiscall daBomb_c::procWait(daBomb_c *this)

{
  bool bVar1;
  char cVar3;
  undefined4 uVar2;
  undefined4 uVar4;
  undefined8 in_f31;
  double dVar5;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  cVar3 = checkExplode(this);
  if (cVar3 == '\0') {
    if (((this->parent).mStatus & IsBeingCarried) == 0) {
      posMoveF(this);
      dVar5 = (double)(this->parent).mVelocity.y;
      bgCrrPos(this);
      bVar1 = false;
      cVar3 = checkExplodeBg(this);
      if (cVar3 == '\0') {
        cVar3 = chk_state(this,4);
        if (cVar3 == '\0') {
          cVar3 = chk_state(this,7);
          if (cVar3 != '\0') {
            waitState_bomtyu(this);
          }
        }
        else {
          cVar3 = waitState_cannon(this);
          if (cVar3 != '\0') {
            bVar1 = true;
          }
        }
      }
      else {
        bVar1 = true;
      }
      if ((!bVar1) && (this->field_0x781 == 0)) {
        bound(this,(float)dVar5);
        if (((((this->mBgSAcch).mFlags & 0x20) == 0) && (cVar3 = chk_state(this,5), cVar3 == '\0'))
           || (((this->mBgSAcch).mFlags & 0x80) != 0)) {
          (this->parent).mAttentionFlags = (this->parent).mAttentionFlags & ~Action_Carry;
        }
        else {
          (this->parent).mAttentionFlags = (this->parent).mAttentionFlags | Action_Carry;
        }
      }
      uVar2 = 1;
    }
    else {
      uVar2 = procCarry_init(this);
    }
  }
  else {
    uVar2 = 1;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return uVar2;
}


/* __thiscall daBomb_c::waitState_cannon(void) */

undefined4 __thiscall daBomb_c::waitState_cannon(daBomb_c *this)

{
  se_cannon_fly_set(this);
  return 0;
}


/* __thiscall daBomb_c::waitState_bomtyu(void) */

void __thiscall daBomb_c::waitState_bomtyu(daBomb_c *this)

{
  SComponent::cLib_chaseF(&(this->parent).mScale.x,d_a_bomb::1_0,d_a_bomb::0_05);
  SComponent::cLib_chaseF(&(this->parent).mScale.y,d_a_bomb::1_0,d_a_bomb::0_05);
  SComponent::cLib_chaseF(&(this->parent).mScale.z,d_a_bomb::1_0,d_a_bomb::0_05);
  if (this->field_0x6f2 != 0) {
    setFuseEffect(this);
    this->field_0x6f2 = 0;
    this->field_0x6f4 = 1;
    change_state(this,1);
  }
  return;
}


/* __thiscall daBomb_c::procSink(void) */

undefined4 __thiscall daBomb_c::procSink(daBomb_c *this)

{
  this->field_0x781 = 1;
  return 1;
}


/* __thiscall daBomb_c::execute(void) */

undefined4 __thiscall daBomb_c::execute(daBomb_c *this)

{
  char cVar1;
  bool bVar2;
  sbyte sVar3;
  void *extraout_r4;
  void *pvVar4;
  cXyz local_28;
  cXyz local_1c [2];
  
  if (d_a_bomb::init_5401 == '\0') {
    d_a_bomb::fuse_offset_5399 = d_a_bomb::_4271;
    DAT_803e3698 = d_a_bomb::_4917;
    DAT_803e369c = d_a_bomb::_4797;
    Runtime.PPCEABI.H::__register_global_object
              (&d_a_bomb::fuse_offset_5399,::cXyz::_cXyz,&d_a_bomb::_5400);
    d_a_bomb::init_5401 = '\x01';
  }
  cVar1 = chk_state(this,4);
  if ((cVar1 != '\0') && (*(char *)&this->field_0x77c == '\0')) {
    *(undefined *)&this->field_0x77c = 1;
    local_1c[0].x = (this->parent).mCurrent.mPos.x;
    local_1c[0].z = (this->parent).mCurrent.mPos.z;
    local_1c[0].y = (this->parent).mCurrent.mPos.y + d_a_bomb::_4276;
    makeFireEffect(this,local_1c,&(this->parent).mCollisionRot);
  }
  set_wind_vec(this);
  pvVar4 = extraout_r4;
  bVar2 = Runtime.PPCEABI.H::__ptmf_test((PTMF *)&this->field_0x290);
  if (bVar2 != false) {
    Runtime.PPCEABI.H::__ptmf_scall((PTMF *)&this->field_0x290,this,pvVar4);
  }
  if (this->field_0x781 == 0) {
    set_real_shadow_flag(this);
    if (this->field_0x2f8 == 1) {
      anm_play_nut(this);
    }
    ::dCcD_GStts::Move(&(this->mCcDStts).mGStts);
    (this->parent).mAttentionPos.x = (this->parent).mCurrent.mPos.x;
    (this->parent).mAttentionPos.y = d_a_bomb::_5171 + (this->parent).mCurrent.mPos.y;
    (this->parent).mAttentionPos.z = (this->parent).mCurrent.mPos.z;
    (this->parent).mEyePos.x = (this->parent).mAttentionPos.x;
    (this->parent).mEyePos.y = (this->parent).mAttentionPos.y;
    (this->parent).mEyePos.z = (this->parent).mAttentionPos.z;
    cVar1 = @unnamed@d_a_bomb_cpp@::chk_attrState(this,0x20);
    if (cVar1 == '\0') {
      set_mtx(this);
      (this->field_0x71c).x = (this->field_0x710).x;
      (this->field_0x71c).y = (this->field_0x710).y;
      (this->field_0x71c).z = (this->field_0x710).z;
      (this->field_0x710).x = (this->field_0x704).x;
      (this->field_0x710).y = (this->field_0x704).y;
      (this->field_0x710).z = (this->field_0x704).z;
      mtx::PSMTXMultVec(&mDoMtx_stack_c::now,(cXyz *)&d_a_bomb::fuse_offset_5399,&this->field_0x704)
      ;
      local_28.x = (this->parent).mCurrent.mPos.x;
      local_28.y = d_a_bomb::_4753 + (this->parent).mCurrent.mPos.y;
      local_28.z = (this->parent).mCurrent.mPos.z;
      ::cM3dGSph::SetC(&(this->mCcDSph).mSphAttr.mSph,&local_28);
      ::cM3dGSph::SetR(&(this->mCcDSph).mSphAttr.mSph,d_a_bomb::_4753 * (this->parent).mScale.x);
      if (this->field_0x7c4 != SComponent::g_Counter) {
        cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)&this->mCcDSph);
        dCcMassS_Mng::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng,
                          (cCcD_Obj *)&this->mCcDSph,3);
        this->field_0x7c4 = SComponent::g_Counter;
      }
    }
    cVar1 = @unnamed@d_a_bomb_cpp@::chk_attrState(this,0x10);
    if ((cVar1 != '\0') || (this->field_0x6f4 == 1)) {
      sVar3 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x6100,&(this->parent).mEyePos,0,sVar3,d_a_bomb::1_0,
                 d_a_bomb::1_0,d_a_bomb::_4895,d_a_bomb::_4895,0);
    }
  }
  else {
    f_op_actor_mng::fopAcM_delete((base_process_class *)this);
  }
  if (this->field_0x782 != 0) {
    *(int *)&this->field_0x784 = *(int *)&this->field_0x784 + 1;
  }
  return 1;
}


namespace d_a_bomb {

/* __stdcall daBomb_Execute(daBomb_c *) */

void daBomb_Execute(daBomb_c *param_1)

{
  ::daBomb_c::execute(param_1);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x800dc228) */
/* WARNING: Removing unreachable block (ram,0x800dc218) */
/* WARNING: Removing unreachable block (ram,0x800dc220) */
/* WARNING: Removing unreachable block (ram,0x800dc230) */
/* __thiscall daBomb_c::set_wind_vec(void) */

void __thiscall daBomb_c::set_wind_vec(daBomb_c *this)

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
  mtx::PSVECScale((cXyz *)&this->field_0x788,(cXyz *)&this->field_0x788,d_a_bomb::_5523);
  fVar10 = mtx::PSVECSquareMag((cXyz *)&this->field_0x788);
  fVar11 = d_a_bomb::_4271;
  if (fVar10 < d_a_bomb::_4277) {
    *(float *)&this->field_0x788 = d_a_bomb::_4271;
    *(float *)&this->field_0x78c = fVar11;
    *(float *)&this->field_0x790 = fVar11;
  }
  iVar1 = dCcD_GObjInf::ChkTgHit(&(this->mCcDSph).parent);
  if (((iVar1 != 0) &&
      (pcVar2 = dCcD_GObjInf::GetTgHitObj(&(this->mCcDSph).parent), pcVar2 != (cCcD_Obj *)0x0)) &&
     (((pcVar2->parent).mObjAt.mDamageTypes & DekuLeafWind) != 0)) {
    local_68[0].x = (this->mCcDSph).parent.mObjTg.mAtVel.x;
    local_68[0].y = (this->mCcDSph).parent.mObjTg.mAtVel.y;
    local_68[0].z = (this->mCcDSph).parent.mObjTg.mAtVel.z;
    fVar11 = mtx::PSVECSquareMag(local_68);
    dVar7 = (double)fVar11;
    if ((double)d_a_bomb::_5524 < dVar7) {
      dVar6 = dVar7;
      if ((double)d_a_bomb::_4271 < dVar7) {
        dVar6 = 1.0 / SQRT(dVar7);
        dVar6 = d_a_bomb::_4272 * dVar6 * (d_a_bomb::_4273 - dVar7 * dVar6 * dVar6);
        dVar6 = d_a_bomb::_4272 * dVar6 * (d_a_bomb::_4273 - dVar7 * dVar6 * dVar6);
        dVar6 = (double)(float)(dVar7 * d_a_bomb::_4272 * dVar6 *
                                        (d_a_bomb::_4273 - dVar7 * dVar6 * dVar6));
      }
      mtx::PSVECScale(local_68,local_68,(float)((double)d_a_bomb::_5525 / dVar6));
    }
    iVar1 = (*(code *)((pcVar2->parent).vtbl)->GetShapeAttr_1)(pcVar2);
    local_74.x = ::cXyz::Zero.x;
    local_74.y = ::cXyz::Zero.y;
    local_74.z = ::cXyz::Zero.z;
    dVar8 = (double)d_a_bomb::1_0;
    dVar6 = dVar8;
    cVar4 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x50))(iVar1,&(this->parent).mCurrent,&local_74);
    if (cVar4 != '\0') {
      mtx::PSVECScale(&local_74,&local_74,d_a_bomb::_5171);
      mtx::PSVECSquareMag((cXyz *)&this->field_0x788);
      pfVar3 = dCcD_GAtTgCoCommonBase::GetAc(&(this->mCcDSph).parent.mObjTg.parent);
      if ((pfVar3 != (fopAc_ac_c *)0x0) && ((pfVar3->parent).parent.mBsTypeId == 0xa9)) {
        iVar1 = SComponent::cM_atan2s(local_74.x,local_74.z);
        fVar11 = JKernel::JMath::jmaCosTable
                 [(int)((pfVar3->mCollisionRot).y - iVar1 & 0xffffU) >>
                  (JKernel::JMath::jmaSinShift & 0x3f)];
        if (d_a_bomb::_4271 < fVar11) {
          dVar6 = (double)(d_a_bomb::1_0 + d_a_bomb::_4279 * fVar11);
          dVar8 = (double)(d_a_bomb::1_0 + d_a_bomb::_4869 * fVar11);
        }
      }
    }
    fVar10 = d_a_bomb::1_0;
    fVar11 = d_a_bomb::_4271;
    if ((double)d_a_bomb::_4692 < dVar7) {
      fVar10 = d_a_bomb::_4277;
      fVar11 = d_a_bomb::_4691;
    }
    dVar9 = (double)fVar11;
    dVar7 = (double)fVar10;
    ::cXyz::operator_(&cStack128,local_68,fVar11);
    ::cXyz::operator_(&cStack140,&local_74,(float)dVar7);
    ::cXyz::operator_(&cStack152,&cStack140,(float)dVar6);
    ::cXyz::operator__(&local_a4,&cStack128,&cStack152);
    *(float *)&this->field_0x788 = local_a4.x;
    *(float *)&this->field_0x78c = local_a4.y;
    *(float *)&this->field_0x790 = local_a4.z;
    if (ABS(*(float *)&this->field_0x78c) < d_a_bomb::_4797) {
      *(float *)&this->field_0x78c =
           *(float *)&this->field_0x78c +
           (float)((double)d_a_bomb::_5526 * dVar9) +
           (float)(dVar8 * (double)(float)((double)d_a_bomb::_5172 * dVar7));
    }
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


/* __thiscall daBomb_c::anm_play_nut(void) */

void __thiscall daBomb_c::anm_play_nut(daBomb_c *this)

{
  char cVar1;
  
  cVar1 = chk_state(this,5);
  if ((cVar1 == '\0') && (cVar1 = chk_state(this,6), cVar1 == '\0')) {
    if (this->field_0x6fc + 2 < 0x88) {
      ::mDoExt_baseAnm::play((mDoExt_baseAnm *)&this->field_0x2b8);
      ::mDoExt_baseAnm::play((mDoExt_baseAnm *)&this->field_0x2e0);
    }
  }
  else {
    ::mDoExt_baseAnm::play(&(this->field_0x2a8).parent);
    ::mDoExt_baseAnm::play((mDoExt_baseAnm *)&this->field_0x2c8);
  }
  return;
}


/* __thiscall daBomb_c::set_mtx(void) */

void __thiscall daBomb_c::set_mtx(daBomb_c *this)

{
  J3DModel *pJVar1;
  char cVar2;
  
  pJVar1 = this->mpModel;
  (pJVar1->mBaseScale).x = (this->parent).mScale.x;
  (pJVar1->mBaseScale).y = (this->parent).mScale.y;
  (pJVar1->mBaseScale).z = (this->parent).mScale.z;
  mtx::PSMTXTrans((double)(this->parent).mCurrent.mPos.x,(double)(this->parent).mCurrent.mPos.y,
                  (double)(this->parent).mCurrent.mPos.z,&mDoMtx_stack_c::now);
  cVar2 = prm_get_angXZero(this);
  if (cVar2 == '\0') {
    m_Do_mtx::mDoMtx_ZXYrotM
              (&mDoMtx_stack_c::now,(int)(this->parent).mCollisionRot.x,
               (int)(this->parent).mCollisionRot.y,(int)(this->parent).mCollisionRot.z);
  }
  else {
    m_Do_mtx::mDoMtx_ZXYrotM
              (&mDoMtx_stack_c::now,0,(int)(this->parent).mCollisionRot.y,
               (int)(this->parent).mCollisionRot.z);
  }
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,&this->mpModel->mBaseMtx);
  return;
}


/* __thiscall daBomb_c::init_mtx(void) */

void __thiscall daBomb_c::init_mtx(daBomb_c *this)

{
  set_mtx(this);
  return;
}


/* __thiscall daBomb_c::se_cannon_fly_set(void) */

void __thiscall daBomb_c::se_cannon_fly_set(daBomb_c *this)

{
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,0x381f,&(this->parent).mCurrent.mPos,0,0,d_a_bomb::1_0,
             d_a_bomb::1_0,d_a_bomb::_4895,d_a_bomb::_4895,0);
  *(undefined *)&this->field_0x77f = 1;
  return;
}


/* __thiscall daBomb_c::se_cannon_fly_stop(void) */

void __thiscall daBomb_c::se_cannon_fly_stop(daBomb_c *this)

{
  if (*(char *)&this->field_0x77f != '\0') {
    JAIZelBasic::seStopActor(JAIZelBasic::zel_basic,(Vec *)&(this->parent).mCurrent,0xffffffff);
    *(undefined *)&this->field_0x77f = 0;
  }
  return;
}


/* __thiscall daBomb_c::eff_water_splash(void) */

void __thiscall daBomb_c::eff_water_splash(daBomb_c *this)

{
  int iVar1;
  sbyte sVar2;
  cBgS_PolyInfo *pcVar3;
  ulong uVar4;
  int iVar5;
  dBgS_WtrChk *local_28;
  cBgS_PolyInfo *local_24;
  float local_20;
  float local_1c;
  float local_18;
  
  local_18 = (this->parent).mCurrent.mPos.z;
  local_1c = (this->field_0x554).y;
  local_20 = (this->parent).mCurrent.mPos.x;
  f_op_kankyo_mng::fopKyM_createWpillar((double)d_a_bomb::_4275,(double)d_a_bomb::_5616,&local_20,0)
  ;
  if (*(char *)&this->field_0x562 == '\0') {
    local_28 = &(this->mBgSAcch).mWtrChk;
  }
  else {
    local_28 = (dBgS_WtrChk *)0x0;
  }
  local_24 = &(this->mBgSAcch).mGndChk.parent.mPolyInfo;
  uVar4 = 0x13;
  iVar1 = 0;
  iVar5 = 2;
  while ((pcVar3 = *(cBgS_PolyInfo **)((int)&local_28 + iVar1), pcVar3 == (cBgS_PolyInfo *)0x0 ||
         (0xff < (ushort)pcVar3->mBgIndex))) {
    iVar1 = iVar1 + 4;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
LAB_800dc518:
      sVar2 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x6918,&(this->parent).mEyePos,uVar4,sVar2,d_a_bomb::1_0,
                 d_a_bomb::1_0,d_a_bomb::_4895,d_a_bomb::_4895,0);
      return;
    }
  }
  uVar4 = dBgS::GetMtrlSndId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,pcVar3);
  goto LAB_800dc518;
}


namespace d_a_bomb {

/* __stdcall daBomb_IsDelete(daBomb_c *) */

undefined4 daBomb_IsDelete(void)

{
  return 1;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daBomb_c::bombDelete(void) */

undefined4 __thiscall daBomb_c::bombDelete(daBomb_c *this)

{
  int iVar1;
  
  if (*(int *)&this->field_0x6e0 != 0) {
    *(undefined4 *)(*(int *)&this->field_0x6e0 + 0x19c) = 0;
    iVar1 = *(int *)&this->field_0x6e0;
    *(undefined4 *)(iVar1 + 0x60) = 0xffffffff;
    *(uint *)(iVar1 + 0x20c) = *(uint *)(iVar1 + 0x20c) | 1;
  }
  *(undefined4 *)&this->field_0x6e0 = 0;
  if (*(int *)&this->field_0x6ec != 0) {
    *(undefined4 *)(*(int *)&this->field_0x6ec + 0x19c) = 0;
    iVar1 = *(int *)&this->field_0x6ec;
    *(undefined4 *)(iVar1 + 0x60) = 0xffffffff;
    *(uint *)(iVar1 + 0x20c) = *(uint *)(iVar1 + 0x20c) | 1;
  }
  *(undefined4 *)&this->field_0x6ec = 0;
  if (*(char *)&this->field_0x6f0 != '\0') {
    if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->mActivePlayerBombs != 0) {
      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->mActivePlayerBombs =
           (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->mActivePlayerBombs - 1;
    }
  }
  se_cannon_fly_stop(this);
  if (this->field_0x2f8 == 1) {
    d_com_inf_game::dComIfG_resDelete
              ((request_of_phase_process_class *)&this->field_0x29c,_UNK_8035b9d0);
  }
  d_kankyo::dKy_actor_addcol_set(0,0,0,d_a_bomb::_4271);
  d_kankyo::dKy_efplight_cut((LIGHT_INFLUENCE *)&this->field_0x728);
  d_kankyo_wether::dKyw_pntwind_cut(&this->field_0x748);
  return 1;
}


namespace d_a_bomb {

/* __stdcall daBomb_Delete(daBomb_c *) */

undefined4 daBomb_Delete(daBomb_c *param_1)

{
  ::daBomb_c::bombDelete(param_1);
  return 1;
}

}

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daBomb_c::createHeap(void) */

bool __thiscall daBomb_c::createHeap(daBomb_c *this)

{
  J3DModelData *pJVar1;
  ulong uVar2;
  J3DModel *pJVar3;
  J3DAnmTransform *pJVar4;
  int iVar5;
  int iVar6;
  J3DAnmTevRegKey *pJVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  if (this->field_0x2f8 == 1) {
    pJVar1 = (J3DModelData *)
             dRes_control_c::getRes
                       (_UNK_8035b9d0,0xc,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                        0x40);
    if (pJVar1 == (J3DModelData *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_a_bomb3.inc",0x9a5,"modelData != 0");
      m_Do_printf::OSPanic("d_a_bomb3.inc",0x9a5,&DAT_8035ba08);
    }
    pJVar3 = m_Do_ext::mDoExt_J3DModel__create(pJVar1,0x80000,0x11000022);
    this->mpModel = pJVar3;
    pJVar4 = (J3DAnmTransform *)
             dRes_control_c::getRes
                       ((&m_attrType)[this->field_0x2f8 * 2],8,
                        d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pJVar4 == (J3DAnmTransform *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_a_bomb3.inc",0x9ae,"bck0_data != 0");
      m_Do_printf::OSPanic("d_a_bomb3.inc",0x9ae,&DAT_8035ba08);
    }
    iVar5 = ::mDoExt_bckAnm::init
                      (&this->field_0x2a8,pJVar1,pJVar4,true,Once,d_a_bomb::1_0,0,-1,false);
    pJVar4 = (J3DAnmTransform *)
             dRes_control_c::getRes
                       ((&m_attrType)[this->field_0x2f8 * 2],7,
                        d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pJVar4 == (J3DAnmTransform *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_a_bomb3.inc",0x9b4,"bck1_data != 0");
      m_Do_printf::OSPanic("d_a_bomb3.inc",0x9b4,&DAT_8035ba08);
    }
    iVar6 = ::mDoExt_bckAnm::init
                      ((mDoExt_bckAnm *)&this->field_0x2b8,pJVar1,pJVar4,true,Once,d_a_bomb::1_0,0,
                       -1,false);
    pJVar7 = (J3DAnmTevRegKey *)
             dRes_control_c::getRes
                       ((&m_attrType)[this->field_0x2f8 * 2],0x11,
                        d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pJVar7 == (J3DAnmTevRegKey *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_a_bomb3.inc",0x9bb,"brk0_data != 0");
      m_Do_printf::OSPanic("d_a_bomb3.inc",0x9bb,&DAT_8035ba08);
    }
    iVar8 = ::mDoExt_brkAnm::init
                      ((mDoExt_brkAnm *)&this->field_0x2c8,pJVar1,pJVar7,true,Once,d_a_bomb::1_0,0,
                       -1,false,0);
    pJVar7 = (J3DAnmTevRegKey *)
             dRes_control_c::getRes
                       ((&m_attrType)[this->field_0x2f8 * 2],0x10,
                        d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pJVar7 == (J3DAnmTevRegKey *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_a_bomb3.inc",0x9c1,"brk1_data != 0");
      m_Do_printf::OSPanic("d_a_bomb3.inc",0x9c1,&DAT_8035ba08);
    }
    iVar9 = ::mDoExt_brkAnm::init
                      ((mDoExt_brkAnm *)&this->field_0x2e0,pJVar1,pJVar7,true,Once,d_a_bomb::1_0,0,
                       -1,false,0);
    bVar10 = false;
    if ((((this->mpModel != (J3DModel *)0x0) && (iVar5 != 0)) && (iVar6 != 0)) &&
       ((iVar8 != 0 && (iVar9 != 0)))) {
      bVar10 = true;
    }
  }
  else {
    pJVar1 = (J3DModelData *)
             dRes_control_c::getRes
                       ((&m_attrType)[this->field_0x2f8 * 2],0x3c,
                        d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pJVar1 == (J3DModelData *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_a_bomb3.inc",0x9ce,"modelData != 0");
      m_Do_printf::OSPanic("d_a_bomb3.inc",0x9ce,&DAT_8035ba08);
    }
    pJVar3 = m_Do_ext::mDoExt_J3DModel__create(pJVar1,0x80000,0x11000002);
    this->mpModel = pJVar3;
    if (this->mpModel == (J3DModel *)0x0) {
      bVar10 = false;
    }
    else {
      pJVar4 = (J3DAnmTransform *)
               dRes_control_c::getRes
                         ((&m_attrType)[this->field_0x2f8 * 2],0xb,
                          d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
      iVar5 = ::mDoExt_bckAnm::init
                        (&this->field_0x2a8,pJVar1,pJVar4,false,Repeat,d_a_bomb::1_0,0,-1,false);
      bVar10 = iVar5 != 0;
    }
  }
  return bVar10;
}


namespace d_a_bomb {

/* __stdcall daBomb_createHeap(fopAc_ac_c *) */

void daBomb_createHeap(daBomb_c *param_1)

{
  ::daBomb_c::createHeap(param_1);
  return;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daBomb_c::create(void) */

PhaseState __thiscall daBomb_c::create(daBomb_c *this)

{
  int iVar1;
  PhaseState PVar2;
  uint uVar3;
  
  iVar1 = prm_get_state(this);
  if ((iVar1 == 5) || (iVar1 == 6)) {
    this->field_0x2f8 = 1;
  }
  else {
    if (iVar1 == 4) {
      this->field_0x2f8 = 2;
    }
    else {
      this->field_0x2f8 = 0;
    }
  }
  if (((this->parent).mCondition & Constructed) == 0) {
    if (this != (daBomb_c *)0x0) {
      daBomb_c(this);
    }
    (this->parent).mCondition = (this->parent).mCondition | Constructed;
  }
  if (this->field_0x2f8 == 1) {
    PVar2 = d_com_inf_game::dComIfG_resLoad
                      ((request_of_phase_process_class *)&this->field_0x29c,_UNK_8035b9d0);
  }
  else {
    PVar2 = cPhs_COMPLEATE_e;
  }
  if (PVar2 == cPhs_COMPLEATE_e) {
    uVar3 = f_op_actor_mng::fopAcM_entrySolidHeap
                      (&this->parent,d_a_bomb::daBomb_createHeap,
                       *(ulong *)(&DAT_8035b9cc + this->field_0x2f8 * 8));
    if ((uVar3 & 0xff) == 0) {
      PVar2 = cPhs_ERROR_e;
    }
    else {
      create_init(this);
    }
  }
  return PVar2;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall daBomb_c::daBomb_c(void) */

void __thiscall daBomb_c::daBomb_c(daBomb_c *this)

{
  int iVar1;
  
  fopAc_ac_c::fopAc_ac_c(&this->parent);
  (this->field_0x2a8).parent.vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_baseAnm::__vt;
  (this->field_0x2a8).parent.mpFrameCtrl = (J3DFrameCtrl *)0x0;
  (this->field_0x2a8).parent.vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_bckAnm::__vt;
  (this->field_0x2a8).mpMtxCalc = (J3DMtxCalc *)0x0;
  *(undefined ***)&this->field_0x2b8 = &::mDoExt_baseAnm::__vt;
  *(undefined4 *)&this->field_0x2bc = 0;
  *(undefined ***)&this->field_0x2b8 = &::mDoExt_bckAnm::__vt;
  *(undefined4 *)&this->field_0x2c4 = 0;
  *(undefined ***)&this->field_0x2c8 = &::mDoExt_baseAnm::__vt;
  *(undefined4 *)&this->field_0x2cc = 0;
  *(undefined ***)&this->field_0x2c8 = &::mDoExt_brkAnm::__vt;
  *(undefined4 *)&this->field_0x2d4 = 0;
  *(undefined4 *)&this->field_0x2d8 = 0;
  *(undefined ***)&this->field_0x2e0 = &::mDoExt_baseAnm::__vt;
  *(undefined4 *)&this->field_0x2e4 = 0;
  *(undefined ***)&this->field_0x2e0 = &::mDoExt_brkAnm::__vt;
  *(undefined4 *)&this->field_0x2ec = 0;
  *(undefined4 *)&this->field_0x2f0 = 0;
  dBgS_Acch::dBgS_Acch(&this->mBgSAcch);
  (this->mBgSAcch).mChk.vtbl = (cBgS_Chk__vtbl *)&dBgS_BombAcch::__vt;
  (this->mBgSAcch).mDChk.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&DAT_8038a0c8;
  (this->mBgSAcch).mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&DAT_8038a0d4;
  (this->mBgSAcch).mDChk.mPolyPassChk.parent.mbBombThrough = 1;
  ::dBgS_AcchCir::dBgS_AcchCir(&this->mBgSAcchCir);
  ::cBgS_GndChk::cBgS_GndChk((cBgS_GndChk *)&this->field_0x500);
  *(undefined ***)&this->field_0x540 = &::cBgS_PolyPassChk::__vt;
  *(undefined ***)&this->field_0x540 = &::dBgS_PolyPassChk::__vt;
  *(undefined *)&this->field_0x544 = 0;
  *(undefined *)&this->field_0x545 = 0;
  *(undefined *)&this->field_0x546 = 0;
  *(undefined *)&this->field_0x547 = 0;
  *(undefined *)&this->field_0x548 = 0;
  *(undefined *)&this->field_0x549 = 0;
  *(undefined *)&this->field_0x54a = 0;
  *(undefined ***)&this->field_0x54c = &::cBgS_GrpPassChk::__vt;
  *(undefined ***)&this->field_0x54c = &::dBgS_GrpPassChk::__vt;
  *(undefined4 *)&this->field_0x550 = 1;
  *(undefined ***)&this->field_0x540 = &::dBgS_Chk::__vt;
  *(undefined ***)&this->field_0x54c = &PTR_80371f68;
  *(cBgS_Chk__vtbl **)&this->field_0x510 = &::dBgS_GndChk::__vt;
  *(cBgS_PolyInfo__vtbl **)&this->field_0x520 = &cBgS_PolyInfo__vtbl_80371f08;
  *(undefined ***)&this->field_0x540 = &PTR_80371f14;
  *(undefined ***)&this->field_0x54c = &PTR_80371f20;
  (((cBgS_GndChk *)&this->field_0x500)->parent).mpPolyPassChk =
       (cBgS_PolyPassChk *)&this->field_0x540;
  iVar1 = &this->field_0x540;
  if (iVar1 != 0) {
    iVar1 = &this->field_0x54c;
  }
  *(int *)&this->field_0x504 = iVar1;
  *(cBgS_Chk__vtbl **)&this->field_0x510 = &::dBgS_ObjGndChk::__vt;
  *(cBgS_PolyInfo__vtbl **)&this->field_0x520 = &cBgS_PolyInfo__vtbl_80371ed8;
  *(cBgS_PolyPassChk__vtbl **)&this->field_0x540 = &cBgS_PolyPassChk__vtbl_80371ee4;
  *(cBgS_GrpPassChk__vtbl **)&this->field_0x54c = &cBgS_GrpPassChk__vtbl_80371ef0;
  *(undefined *)&this->field_0x544 = 1;
  *(undefined1 **)&this->field_0x510 = &dBgS_ObjGndChk_Yogan::__vt;
  *(undefined **)&this->field_0x520 = &DAT_80371e60;
  *(undefined **)&this->field_0x540 = &DAT_80371e6c;
  *(undefined **)&this->field_0x54c = &DAT_80371e78;
  *(uint *)&this->field_0x550 = *(uint *)&this->field_0x550 & 0xfffffffe;
  *(uint *)&this->field_0x550 = *(uint *)&this->field_0x550 | 4;
  (this->mCcDStts).parent.vtbl = &cCcD_Stts::__vt;
  ::dCcD_GStts::dCcD_GStts(&(this->mCcDStts).mGStts);
  (this->mCcDStts).parent.vtbl = &::dCcD_Stts::__vt.parent;
  (this->mCcDStts).mGStts.parent.vtbl = (cCcD_GStts__vtbl *)0x8037ec40;
  dCcD_GObjInf::dCcD_GObjInf(&(this->mCcDSph).parent);
  (this->mCcDSph).mSphAttr.parent.vtbl = (cCcD_ShapeAttr__vtbl *)&::cCcD_ShapeAttr::__vt;
  (this->mCcDSph).mSphAttr.parent.mAab.vtbl = &::cM3dGAab::__vt;
  (this->mCcDSph).mSphAttr.mSph.vtbl = (undefined *)&::cM3dGSph::__vt;
  (this->mCcDSph).mSphAttr.parent.vtbl = (cCcD_ShapeAttr__vtbl *)&::cCcD_SphAttr::__vt;
  (this->mCcDSph).mSphAttr.mSph.vtbl = (undefined *)&PTR_8039514c;
  (this->mCcDSph).parent.parent.parent.parent.vtbl = (cCcD_GObjInf__vtbl *)&::dCcD_Sph::__vt;
  (this->mCcDSph).mSphAttr.parent.vtbl = (cCcD_ShapeAttr__vtbl *)&DAT_803899f8;
  (this->mCcDSph).mSphAttr.mSph.vtbl = &DAT_80389a4c;
  *(undefined1 **)&this->field_0x6cc = &::JPACallBackBase<JPABaseEmitter*>::__vt;
  *(undefined1 **)&this->field_0x6cc = &::dPa_levelEcallBack::__vt;
  *(undefined1 **)&this->field_0x6cc = &daBomb_fuseSmokeEcallBack::__vt;
  *(undefined1 **)&this->field_0x6e4 = &::JPACallBackBase<JPABaseEmitter*>::__vt;
  *(undefined1 **)&this->field_0x6e4 = &::dPa_levelEcallBack::__vt;
  *(undefined1 **)&this->field_0x6e4 = &daBomb_fuseSparksEcallBack::__vt;
  return;
}


/* __thiscall LIGHT_INFLUENCE::~LIGHT_INFLUENCE(void) */

void __thiscall LIGHT_INFLUENCE::_LIGHT_INFLUENCE(LIGHT_INFLUENCE *this)

{
  short in_r4;
  
  if ((this != (LIGHT_INFLUENCE *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace d_a_bomb {

/* __stdcall daBomb_Create(fopAc_ac_c *) */

void daBomb_Create(daBomb_c *param_1)

{
  ::daBomb_c::create(param_1);
  return;
}

}

/* WARNING: Type propagation algorithm not settling */
/* __thiscall daBomb_c::create_init(void) */

void __thiscall daBomb_c::create_init(daBomb_c *this)

{
  float fVar1;
  char cVar3;
  int iVar2;
  
  ::dBgS_AcchCir::SetWall(&this->mBgSAcchCir,d_a_bomb::_4753,d_a_bomb::_4753);
  dBgS_Acch::Set(&this->mBgSAcch,&(this->parent).mCurrent.mPos,&(this->parent).mNext.mPos,
                 &this->parent,1,&this->mBgSAcchCir,&(this->parent).mVelocity,
                 &(this->parent).mCurrent.mRot,&(this->parent).mCollisionRot);
  (this->mBgSAcch).mFlags = (this->mBgSAcch).mFlags & 0xfffffbff;
  (this->mBgSAcch).mFlags = (this->mBgSAcch).mFlags & 0xfffffff7;
  (this->mBgSAcch).field_0xc0 = d_a_bomb::_5171;
  (this->mBgSAcch).mFlags = (this->mBgSAcch).mFlags | 0x2000;
  fVar1 = d_a_bomb::_4477;
  (this->field_0x554).x = d_a_bomb::_4477;
  (this->field_0x554).y = fVar1;
  (this->field_0x554).z = fVar1;
  *(undefined *)&this->field_0x560 = 0;
  *(undefined *)&this->field_0x561 = 0;
  *(undefined *)&this->field_0x562 = 0;
  (this->parent).mpCullMtx = &this->mpModel->mBaseMtx;
  ::dCcD_Stts::Init(&this->mCcDStts,200,0xff,&this->parent);
  ::dCcD_Sph::Set(&this->mCcDSph,&d_a_bomb::l_sph_src);
  (this->mCcDSph).parent.parent.parent.mpStts = &this->mCcDStts;
  cVar3 = chk_state(this,8);
  if (cVar3 != '\0') {
    (this->mCcDSph).parent.parent.parent.parent.mObjAt.mDamage = 2;
  }
  (this->parent).mAccelerationY = d_a_bomb::_6043;
  (this->parent).mVelocityYMin = d_a_bomb::_6044;
  this->field_0x6fc = 0x96;
  iVar2 = prm_get_state(this);
  this->field_0x6f8 = iVar2;
  cVar3 = chk_state(this,4);
  if (cVar3 == '\0') {
    (this->parent).mAttentionFlags = (this->parent).mAttentionFlags | Action_Carry;
  }
  *(undefined *)&this->field_0x77c = 0;
  *(undefined *)&this->field_0x77d = 0;
  this->field_0x77e = 0;
  this->field_0x6f4 = 0;
  *(undefined *)&this->field_0x77f = 0;
  this->field_0x780 = 0;
  this->field_0x781 = 0;
  this->field_0x782 = 0;
  *(undefined4 *)&this->field_0x784 = 0;
  *(float *)&this->field_0x788 = ::cXyz::Zero.x;
  *(float *)&this->field_0x78c = ::cXyz::Zero.y;
  *(float *)&this->field_0x790 = ::cXyz::Zero.z;
  this->field_0x7c4 = SComponent::g_Counter + -1;
  cVar3 = @unnamed@d_a_bomb_cpp@::chk_attrState(this,2);
  fVar1 = d_a_bomb::_4271;
  if (cVar3 != '\0') {
    (this->parent).mScale.x = d_a_bomb::_4271;
    (this->parent).mScale.y = fVar1;
    (this->parent).mScale.z = fVar1;
  }
  cVar3 = @unnamed@d_a_bomb_cpp@::chk_attrState(this,4);
  if (cVar3 != '\0') {
    setFuseEffect(this);
  }
  cVar3 = @unnamed@d_a_bomb_cpp@::chk_attrState(this,8);
  if (cVar3 != '\0') {
    bgCrrPos(this);
  }
  cVar3 = chk_state(this,3);
  if (cVar3 == '\0') {
    this->field_0x7c8 = 0;
  }
  else {
    *(undefined *)&this->field_0x6f0 = 1;
    this->field_0x7c8 = 2;
  }
  cVar3 = @unnamed@d_a_bomb_cpp@::chk_attrState(this,1);
  if (cVar3 == '\0') {
    procWait_init(this);
  }
  else {
    procExplode_init(this);
  }
  fVar1 = d_a_bomb::_6045;
  (this->parent).mCullSizeBoxMin.x = d_a_bomb::_6045;
  (this->parent).mCullSizeBoxMin.y = d_a_bomb::_4271;
  (this->parent).mCullSizeBoxMin.z = fVar1;
  fVar1 = d_a_bomb::_6046;
  (this->parent).mCullSizeBoxMax.x = d_a_bomb::_6046;
  (this->parent).mCullSizeBoxMax.y = d_a_bomb::_6047;
  (this->parent).mCullSizeBoxMax.z = fVar1;
  (this->parent).mCullFarDistanceRatio = d_a_bomb::_4274;
  init_mtx(this);
  return;
}


/* __thiscall daBomb_fuseSparksEcallBack::~daBomb_fuseSparksEcallBack(void) */

void __thiscall
daBomb_fuseSparksEcallBack::_daBomb_fuseSparksEcallBack(daBomb_fuseSparksEcallBack *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (daBomb_fuseSparksEcallBack *)0x0;
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


/* __thiscall daBomb_fuseSmokeEcallBack::~daBomb_fuseSmokeEcallBack(void) */

void __thiscall
daBomb_fuseSmokeEcallBack::_daBomb_fuseSmokeEcallBack(daBomb_fuseSmokeEcallBack *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (daBomb_fuseSmokeEcallBack *)0x0;
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


/* __thiscall dBgS_BombAcch::~dBgS_BombAcch(void) */

void __thiscall dBgS_BombAcch::_dBgS_BombAcch(dBgS_BombAcch *this)

{
  short in_r4;
  
  if (this != (dBgS_BombAcch *)0x0) {
    (this->parent).mChk.vtbl = (cBgS_Chk__vtbl *)&__vt;
    (this->parent).mDChk.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&DAT_8038a0c8;
    (this->parent).mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&DAT_8038a0d4;
    dBgS_Acch::_dBgS_Acch(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall mDoExt_bckAnm::~mDoExt_bckAnm(void) */

void __thiscall mDoExt_bckAnm::_mDoExt_bckAnm(mDoExt_bckAnm *this)

{
  short in_r4;
  
  if (this != (mDoExt_bckAnm *)0x0) {
    (this->parent).vtbl = (mDoExt_baseAnm__vtbl *)&__vt;
    if (this != (mDoExt_bckAnm *)0x0) {
      (this->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_baseAnm::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall daBomb_fuseSparksEcallBack::draw(JPABaseEmitter *) */

void __thiscall
daBomb_fuseSparksEcallBack::draw(daBomb_fuseSparksEcallBack *this,JPABaseEmitter *param_1)

{
  return;
}


/* __thiscall daBomb_fuseSparksEcallBack::setup(JPABaseEmitter *,
                                                cXyz const *,
                                                csXyz const *,
                                                signed char) */

void __thiscall
daBomb_fuseSparksEcallBack::setup
          (daBomb_fuseSparksEcallBack *this,JPABaseEmitter *param_1,cXyz *param_2,csXyz *param_3,
          char param_4)

{
  *(cXyz **)(this + 4) = param_2;
  *(JPABaseEmitter **)(this + 8) = param_1;
  return;
}


/* __thiscall daBomb_fuseSmokeEcallBack::execute(JPABaseEmitter *) */

void __thiscall
daBomb_fuseSmokeEcallBack::execute(daBomb_fuseSmokeEcallBack *this,JPABaseEmitter *param_1)

{
  return;
}


/* __thiscall daBomb_fuseSmokeEcallBack::draw(JPABaseEmitter *) */

void __thiscall
daBomb_fuseSmokeEcallBack::draw(daBomb_fuseSmokeEcallBack *this,JPABaseEmitter *param_1)

{
  return;
}


/* __thiscall daBomb_fuseSmokeEcallBack::setup(JPABaseEmitter *,
                                               cXyz const *,
                                               csXyz const *,
                                               signed char) */

void __thiscall
daBomb_fuseSmokeEcallBack::setup
          (daBomb_fuseSmokeEcallBack *this,JPABaseEmitter *param_1,cXyz *param_2,csXyz *param_3,
          char param_4)

{
  *(cXyz **)(this + 8) = param_2;
  *(JPABaseEmitter **)(this + 0x14) = param_1;
  return;
}


/* [thunk]:__thiscall dBgS_BombAcch::~dBgS_BombAcch(void) */

void __thiscall dBgS_BombAcch::_dBgS_BombAcch(dBgS_BombAcch *this)

{
  _dBgS_BombAcch((dBgS_BombAcch *)&this[-1].parent.mWtrChk.parent.mDChk.mGrpPassChk);
  return;
}


/* [thunk]:__thiscall dBgS_BombAcch::~dBgS_BombAcch(void) */

void __thiscall dBgS_BombAcch::_dBgS_BombAcch(dBgS_BombAcch *this)

{
  _dBgS_BombAcch((dBgS_BombAcch *)&this[-1].parent.mWtrChk.parent.mStartPos.y);
  return;
}

