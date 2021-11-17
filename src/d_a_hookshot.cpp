#include <d_a_hookshot.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J3DGraphBase/J3DSys.h>
#include <gx/GXBump.h>
#include <gx/GXAttr.h>
#include <d_kankyo.h>
#include <gx/GXDisplayList.h>
#include <gx/GXTev.h>
#include <gx/GXTransform.h>
#include <d_a_hookshot.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <mtx/vec.h>
#include <J3DGraphBase/J3DDrawBuffer.h>
#include <d_com_inf_game.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_cc_d.h>
#include <SComponent/c_xyz.h>
#include <d_bg_s_lin_chk.h>
#include <SComponent/c_bg_s.h>
#include <d_bg_s.h>
#include <SComponent/c_math.h>
#include <SComponent/c_cc_s.h>
#include <d_cc_mass_s.h>
#include <d_vibration.h>
#include <d_particle.h>
#include <SComponent/c_m3d.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <f_pc_searcher.h>
#include <f_op_actor_iter.h>
#include <mtx/mtxvec.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <d_a_player_main.h>
#include <f_op_actor.h>
#include <SComponent/c_bg_s_lin_chk.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <SComponent/c_bg_s_chk.h>
#include <JKernel/JKRHeap.h>
#include <daPy_lk_c.h>
#include <daHookshot_shape.h>
#include <daHookshot_c.h>
#include <dBgS_RopeLinChk.h>


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daHookshot_shape::draw(void) */

void __thiscall daHookshot_shape::draw(daHookshot_shape *this)

{
  int iVar1;
  int iVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  _GXColor local_68;
  undefined4 local_64;
  undefined4 local_60;
  node_class *local_5c;
  undefined *local_58;
  node_class *local_54;
  cXyz local_50;
  cXyz local_44 [2];
  
  iVar5 = *(int *)(this + 0xc);
  iVar6 = *(int *)(iVar5 + 0x2a8);
  if (0 < iVar6) {
    J3DSys::reinitGX(&J3DGraphBase::j3dSys);
    gx::GXSetNumIndStages(0);
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX8);
    gx::GXSetVtxDesc(GX_VA_TEX0,GX_INDEX8);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,0);
    gx::GXSetArray(GX_VA_POS,&d_a_hookshot::l_pos,0xc);
    gx::GXSetArray(GX_VA_TEX0,&d_a_hookshot::l_texCoord,8);
    d_kankyo::dKy_GxFog_set();
    gx::GXCallDisplayList(&d_a_hookshot::l_matDL,0xa0);
    local_64 = *(undefined4 *)(iVar5 + 0x18c);
    local_60 = *(undefined4 *)(iVar5 + 400);
    gx::GXSetTevColorS10(GX_TEVREG0,(_GXColorS10 *)&local_64);
    local_68 = *(_GXColor *)(iVar5 + 0x194);
    gx::GXSetTevColor(GX_TEVREG1,&local_68);
    gx::GXSetCurrentMtx(0);
    daPy_lk_c::getHookshotRootPos((daPy_lk_c *)&local_5c);
    local_44[0].x = (float)local_5c;
    local_44[0].y = (float)local_58;
    local_44[0].z = (float)local_54;
    iVar1 = (int)((int)*(short *)(iVar5 + 0x20e) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
    iVar2 = (int)((int)*(short *)(iVar5 + 0x20c) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
    local_50.x = d_a_hookshot::_4127 * JKernel::JMath::jmaCosTable[iVar2] *
                 JKernel::JMath::jmaSinTable[iVar1];
    local_50.y = d_a_hookshot::_4128 * JKernel::JMath::jmaSinTable[iVar2];
    local_50.z = d_a_hookshot::_4127 * JKernel::JMath::jmaCosTable[iVar2] *
                 JKernel::JMath::jmaCosTable[iVar1];
    sVar3 = (short)(g__Timer << 0xc) + ((ushort)((uint)g__Timer >> 4) & 0xfff);
    for (uVar4 = 0; (int)uVar4 <= iVar6; uVar4 = uVar4 + 1) {
      mtx::PSMTXTrans((double)local_44[0].x,(double)local_44[0].y,(double)local_44[0].z,
                      &mDoMtx_stack_c::now);
      m_Do_mtx::mDoMtx_ZXYrotM
                (&mDoMtx_stack_c::now,(int)*(short *)(iVar5 + 0x20c),(int)*(short *)(iVar5 + 0x20e),
                 (int)sVar3);
      sVar3 = (((short)g__Timer + (short)uVar4) * 0x1000 +
               ((ushort)((uint)g__Timer >> (uVar4 & 0xf) + 1) & 0xfff) & 0x1fff) + sVar3 + 0x3000;
      mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,&mDoMtx_stack_c::now,&mDoMtx_stack_c::now);
      gx::GXLoadPosMtxImm(&mDoMtx_stack_c::now,0);
      gx::GXCallDisplayList(&d_a_hookshot::l_chainDL,0x60);
      mtx::PSVECAdd(local_44,&local_50,local_44);
    }
    _sOldVcdVatCmd = 0;
  }
  return;
}


/* __thiscall daHookshot_c::draw(void) */

undefined4 __thiscall daHookshot_c::draw(daHookshot_c *this)

{
  dScnKy_env_light_c::settingTevStruct
            (&d_kankyo::g_env_light,Actor,(cXyz *)(this + 0x1f8),(dKy_tevstr_c *)(this + 0x10c));
  J3DDrawBuffer::entryImm
            (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0xc,(J3DPacket *)(this + 0x290),0);
  return 1;
}


namespace d_a_hookshot {

/* __stdcall daHookshot_Draw(daHookshot_c *) */

void daHookshot_Draw(daHookshot_c *param_1)

{
  ::daHookshot_c::draw(param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x800f13c8) */
/* __stdcall daHookshot_rockLineCallback(fopAc_ac_c *,
                                         dCcD_GObjInf *,
                                         fopAc_ac_c *,
                                         dCcD_GObjInf *) */

void daHookshot_rockLineCallback(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f31;
  float fVar3;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar3 = mtx::PSVECSquareDistance((cXyz *)(param_2 + 0x70),(cXyz *)(param_1 + 0x1f8));
  dVar2 = (double)fVar3;
  fVar3 = mtx::PSVECSquareDistance((cXyz *)(param_1 + 0x2cc),(cXyz *)(param_1 + 0x1f8));
  if (dVar2 < (double)fVar3) {
    *(float *)(param_1 + 0x2cc) = ((cXyz *)(param_2 + 0x70))->x;
    *(undefined4 *)(param_1 + 0x2d0) = *(undefined4 *)(param_2 + 0x74);
    *(undefined4 *)(param_1 + 0x2d4) = *(undefined4 *)(param_2 + 0x78);
    if ((*(uint *)(param_3 + 0x1c4) & 0x10280000) == 0) {
      *(undefined4 *)(param_1 + 0x2b0) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x2b0) = 1;
    }
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daHookshot_c::procWait_init(int) */

undefined4 __thiscall daHookshot_c::procWait_init(daHookshot_c *this,int param_1)

{
  undefined4 uVar1;
  daPy_lk_c *pdVar2;
  sbyte sVar3;
  uint local_28;
  uint local_24;
  undefined4 local_20;
  
  pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor;
  *(undefined4 *)(this + 0xb0) = 0;
  uVar1 = DAT_8038c16c;
  *(undefined4 *)(this + 0x54c) = d_a_hookshot::_4172;
  *(undefined4 *)(this + 0x550) = uVar1;
  *(undefined **)(this + 0x554) = PTR_procWait_8038c170;
  *(undefined4 *)(this + 0x2a8) = 0;
  daPy_lk_c::getHookshotRootPos((daPy_lk_c *)&local_28);
  *(uint *)(this + 0x1f8) = local_28;
  *(uint *)(this + 0x1fc) = local_24;
  *(undefined4 *)(this + 0x200) = local_20;
  *(undefined4 *)(this + 0x518) = 0xffffffff;
  *(undefined4 *)(this + 0x2b0) = 0;
  if (param_1 != 0) {
    sVar3 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x286e,&(pdVar2->parent).parent.mCurrent.mPos,0,sVar3,
               d_a_hookshot::_4190,d_a_hookshot::_4190,d_a_hookshot::_4191,d_a_hookshot::_4191,0);
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daHookshot_c::procWait(void) */

undefined4 __thiscall daHookshot_c::procWait(daHookshot_c *this)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  daPy_lk_c *pdVar6;
  MTX34 *pMVar7;
  char cVar10;
  int iVar8;
  cM3dGPla *pcVar9;
  double dVar11;
  double dVar12;
  float fVar13;
  cXyz local_54;
  cXyz local_48;
  cXyz cStack60;
  uint local_30;
  uint local_2c;
  undefined4 local_28;
  cXyz local_24 [2];
  
  pdVar6 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor;
  daPy_lk_c::getHookshotRootPos((daPy_lk_c *)&local_30);
  *(uint *)(this + 0x1f8) = local_30;
  *(uint *)(this + 0x1fc) = local_2c;
  *(undefined4 *)(this + 0x200) = local_28;
  pMVar7 = (MTX34 *)(*(code *)pdVar6->vtbl->getModelJointMtx)(pdVar6,8);
  mtx::PSMTXCopy(pMVar7,(MTX34 *)(this + 0x51c));
  *(undefined4 *)(this + 0x528) = *(undefined4 *)(this + 0x1f8);
  *(undefined4 *)(this + 0x538) = *(undefined4 *)(this + 0x1fc);
  *(undefined4 *)(this + 0x548) = *(undefined4 *)(this + 0x200);
  *(undefined4 *)(this + 0x2b0) = 0;
  if (*(int *)(this + 0xb0) == 1) {
    uVar3 = (int)(pdVar6->parent).parent.mCollisionRot.y +
            (int)*(short *)&(pdVar6->parent).field_0x2b6 & 0xffff;
    uVar4 = (int)*(short *)&(pdVar6->parent).field_0x2b4 & 0xffff;
    *(float *)(this + 0x2c0) =
         JKernel::JMath::jmaSinTable[(int)uVar3 >> (JKernel::JMath::jmaSinShift & 0x3f)] *
         JKernel::JMath::jmaCosTable[(int)uVar4 >> (JKernel::JMath::jmaSinShift & 0x3f)];
    *(float *)(this + 0x2c4) =
         -JKernel::JMath::jmaSinTable[(int)uVar4 >> (JKernel::JMath::jmaSinShift & 0x3f)];
    *(float *)(this + 0x2c8) =
         JKernel::JMath::jmaCosTable[(int)uVar3 >> (JKernel::JMath::jmaSinShift & 0x3f)] *
         JKernel::JMath::jmaCosTable[(int)uVar4 >> (JKernel::JMath::jmaSinShift & 0x3f)];
    dCcD_GObjInf::ResetAtHit((dCcD_GObjInf *)(this + 0x3d4));
    *(uint *)(this + 0x3d4) = *(uint *)(this + 0x3d4) & 0xffffffef;
    *(undefined4 *)(this + 0x42c) = 0;
    ::cXyz::operator_(&cStack60,(cXyz *)(this + 0x2c0),d_a_hookshot::_4337);
    ::cXyz::operator__(&local_48,(cXyz *)(this + 0x1f8),&cStack60);
    local_24[0].x = local_48.x;
    local_24[0].y = local_48.y;
    local_24[0].z = local_48.z;
    ::dBgS_LinChk::Set((dBgS_LinChk *)(this + 0x2d8),local_24,(cXyz *)(this + 0x1f8),
                       (fopAc_ac_c *)this);
    this[0x2a0] = (daHookshot_c)0x1;
    cVar10 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                             (cBgS_LinChk *)(this + 0x2d8));
    if (cVar10 == '\0') {
      mtx::PSVECScale((cXyz *)(this + 0x2c0),(cXyz *)(this + 0x2c0),d_a_hookshot::_4127);
      *(float *)(this + 0x4ec) = local_24[0].x;
      *(float *)(this + 0x4f0) = local_24[0].y;
      *(float *)(this + 0x4f4) = local_24[0].z;
      *(undefined4 *)(this + 0x4f8) = *(undefined4 *)(this + 0x1f8);
      *(undefined4 *)(this + 0x4fc) = *(undefined4 *)(this + 0x1fc);
      *(undefined4 *)(this + 0x500) = *(undefined4 *)(this + 0x200);
      *(float *)(this + 0x508) = d_a_hookshot::_4341;
      mtx::PSVECSubtract((cXyz *)(this + 0x4f8),(cXyz *)(this + 0x4ec),(cXyz *)(this + 0x450));
      cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)(this + 0x3d4));
      dCcMassS_Mng::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng,
                        (cCcD_Obj *)(this + 0x3d4),1);
      this[0x2a3] = (daHookshot_c)0x0;
      uVar5 = DAT_8038c190;
      *(undefined4 *)(this + 0x54c) = d_a_hookshot::_4205;
      *(undefined4 *)(this + 0x550) = uVar5;
      *(undefined **)(this + 0x554) = PTR_procShot_8038c194;
    }
    else {
      iVar8 = dBgS::ChkPolyHSStick
                        (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                         (cBgS_PolyInfo *)(this + 0x2ec));
      if (iVar8 == 0) {
        *(undefined4 *)(this + 0xb0) = 2;
        uVar5 = DAT_8038c184;
        *(undefined4 *)(this + 0x54c) = d_a_hookshot::_4203;
        *(undefined4 *)(this + 0x550) = uVar5;
        *(undefined **)(this + 0x554) = PTR_procReturn_8038c188;
      }
      else {
        *(undefined4 *)(this + 0xb0) = 3;
        this[0x2a2] = (daHookshot_c)0x0;
        uVar5 = DAT_8038c178;
        *(undefined4 *)(this + 0x54c) = d_a_hookshot::_4201;
        *(undefined4 *)(this + 0x550) = uVar5;
        *(undefined **)(this + 0x554) = PTR_procPlayerPull_8038c17c;
        pcVar9 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                 (uint)*(ushort *)(this + 0x2ee),(uint)*(ushort *)(this + 0x2ec));
        local_54.z = (pcVar9->mNorm).z;
        local_54.x = (pcVar9->mNorm).x;
        local_54.y = d_a_hookshot::_4338;
        fVar13 = mtx::PSVECSquareMag(&local_54);
        dVar12 = (double)fVar13;
        if ((double)d_a_hookshot::_4338 < dVar12) {
          dVar11 = 1.0 / SQRT(dVar12);
          dVar11 = d_a_hookshot::_4339 * dVar11 * (d_a_hookshot::_4340 - dVar12 * dVar11 * dVar11);
          dVar11 = d_a_hookshot::_4339 * dVar11 * (d_a_hookshot::_4340 - dVar12 * dVar11 * dVar11);
          dVar12 = (double)(float)(dVar12 * d_a_hookshot::_4339 * dVar11 *
                                            (d_a_hookshot::_4340 - dVar12 * dVar11 * dVar11));
        }
        iVar8 = SComponent::cM_atan2s((pcVar9->mNorm).y,(float)dVar12);
        *(short *)(this + 0x2b4) = (short)iVar8;
        iVar8 = SComponent::cM_atan2s(-(pcVar9->mNorm).x,-(pcVar9->mNorm).z);
        *(short *)(this + 0x2b6) = (short)iVar8;
        *(undefined2 *)(this + 0x2b8) = 0;
        *(float *)(this + 0x2c0) = ::cXyz::Zero.x;
        *(float *)(this + 0x2c4) = ::cXyz::Zero.y;
        *(float *)(this + 0x2c8) = ::cXyz::Zero.z;
      }
    }
  }
  else {
    *(uint *)(this + 0x3d4) = *(uint *)(this + 0x3d4) | 0x10;
    uVar3 = (int)*(short *)&(pdVar6->parent).field_0x2b4 & 0xffff;
    fVar13 = JKernel::JMath::jmaCosTable[(int)uVar3 >> (JKernel::JMath::jmaSinShift & 0x3f)];
    iVar8 = (int)((int)(pdVar6->parent).parent.mCollisionRot.y & 0xffffU) >>
            (JKernel::JMath::jmaSinShift & 0x3f);
    fVar1 = d_a_hookshot::_4342 * JKernel::JMath::jmaCosTable[iVar8];
    fVar2 = d_a_hookshot::_4342 *
            JKernel::JMath::jmaSinTable[(int)uVar3 >> (JKernel::JMath::jmaSinShift & 0x3f)];
    *(float *)(this + 0x2cc) =
         *(float *)(this + 0x1f8) +
         d_a_hookshot::_4342 * JKernel::JMath::jmaSinTable[iVar8] *
         JKernel::JMath::jmaCosTable[(int)uVar3 >> (JKernel::JMath::jmaSinShift & 0x3f)];
    *(float *)(this + 0x2d0) = *(float *)(this + 0x1fc) - fVar2;
    *(float *)(this + 0x2d4) = *(float *)(this + 0x200) + fVar1 * fVar13;
    *(undefined4 *)(this + 0x4ec) = *(undefined4 *)(this + 0x1f8);
    *(undefined4 *)(this + 0x4f0) = *(undefined4 *)(this + 0x1fc);
    *(undefined4 *)(this + 0x4f4) = *(undefined4 *)(this + 0x200);
    *(undefined4 *)(this + 0x4f8) = *(undefined4 *)(this + 0x2cc);
    *(undefined4 *)(this + 0x4fc) = *(undefined4 *)(this + 0x2d0);
    *(undefined4 *)(this + 0x500) = *(undefined4 *)(this + 0x2d4);
    *(float *)(this + 0x508) = d_a_hookshot::_4341;
    mtx::PSVECSubtract((cXyz *)(this + 0x4f8),(cXyz *)(this + 0x4ec),(cXyz *)(this + 0x450));
    *(code **)(this + 0x42c) = d_a_hookshot::daHookshot_rockLineCallback;
    cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)(this + 0x3d4));
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall daHookshot_c::procShot(void) */

undefined4 __thiscall daHookshot_c::procShot(daHookshot_c *this)

{
  uint uVar1;
  int iVar2;
  fopAc_ac_c *pfVar3;
  fopAcM__Status fVar4;
  sbyte sVar7;
  char cVar8;
  cM3dGPla *pcVar5;
  undefined4 uVar6;
  ulong uVar9;
  double dVar10;
  double dVar11;
  float fVar12;
  cXyz local_90;
  cXyz local_84;
  cXyz local_78;
  cXyz cStack108;
  cXyz cStack96;
  cXyz local_54;
  cXyz local_48;
  cXyz local_3c;
  cXyz local_30;
  cXyz local_24;
  
  uVar6 = DAT_8038c19c;
  if (*(int *)(this + 0xb0) == 2) {
    *(undefined4 *)(this + 0x54c) = d_a_hookshot::_4350;
    *(undefined4 *)(this + 0x550) = uVar6;
    *(undefined **)(this + 0x554) = PTR_procReturn_8038c1a0;
  }
  else {
    iVar2 = dCcD_GObjInf::ChkAtHit((dCcD_GObjInf *)(this + 0x3d4));
    if (iVar2 == 0) {
      if (this[0x2a3] == (daHookshot_c)0x0) {
        daPy_lk_c::getHookshotRootPos((daPy_lk_c *)&cStack96);
        fVar12 = mtx::PSVECSquareDistance((cXyz *)(this + 0x1f8),&cStack96);
        dVar11 = (double)fVar12;
        if ((double)d_a_hookshot::_4338 < dVar11) {
          dVar10 = 1.0 / SQRT(dVar11);
          dVar10 = d_a_hookshot::_4339 * dVar10 * (d_a_hookshot::_4340 - dVar11 * dVar10 * dVar10);
          dVar10 = d_a_hookshot::_4339 * dVar10 * (d_a_hookshot::_4340 - dVar11 * dVar10 * dVar10);
          dVar11 = (double)(float)(dVar11 * d_a_hookshot::_4339 * dVar10 *
                                            (d_a_hookshot::_4340 - dVar11 * dVar10 * dVar10));
        }
        if (dVar11 < (double)d_a_hookshot::_4342) {
          ::cXyz::operator_(&cStack108,(cXyz *)(this + 0x2c0),d_a_hookshot::_4563);
          ::cXyz::operator__(&local_78,(cXyz *)(this + 0x1f8),&cStack108);
          local_24.x = local_78.x;
          local_24.y = local_78.y;
          local_24.z = local_78.z;
          ::dBgS_LinChk::Set((dBgS_LinChk *)(this + 0x2d8),(cXyz *)(this + 0x1f8),&local_24,
                             (fopAc_ac_c *)this);
          cVar8 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                  (cBgS_LinChk *)(this + 0x2d8));
          if (cVar8 != '\0') {
            local_24.x = *(float *)(this + 0x308);
            local_24.y = *(float *)(this + 0x30c);
            local_24.z = *(float *)(this + 0x310);
            iVar2 = dBgS::ChkPolyHSStick
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                               (cBgS_PolyInfo *)(this + 0x2ec));
            if (iVar2 == 0) {
              pcVar5 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                       (uint)*(ushort *)(this + 0x2ee),
                                       (uint)*(ushort *)(this + 0x2ec));
              SComponent::cM3d_CalcVecZAngle(pcVar5,this + 0x2ba);
              iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                                (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                 "kazeB");
              if ((iVar2 != 0) ||
                 (((d_a_hookshot::_4564 <= local_24.y ||
                   (pcVar5 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                             (uint)*(ushort *)(this + 0x2ee),
                                             (uint)*(ushort *)(this + 0x2ec)),
                   (pcVar5->mNorm).y < d_a_hookshot::_4565)) &&
                  (iVar2 = dBgS::GetAttributeCode
                                     (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                                      (cBgS_PolyInfo *)(this + 0x2ec)), iVar2 != 0xb)))) {
                *(undefined2 *)(this + 0x2a6) = 0xc;
              }
              else {
                *(undefined2 *)(this + 0x2a6) = 0x825f;
              }
              uVar6 = dBgS::GetMtrlSndId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                                         (cBgS_PolyInfo *)(this + 0x2ec));
              *(undefined4 *)(this + 0x2ac) = uVar6;
              this[0x2a3] = (daHookshot_c)0x1;
            }
            else {
              *(undefined4 *)(this + 0xb0) = 3;
              this[0x2a2] = (daHookshot_c)0x0;
              uVar6 = DAT_8038c1cc;
              *(undefined4 *)(this + 0x54c) = d_a_hookshot::_4380;
              *(undefined4 *)(this + 0x550) = uVar6;
              *(undefined **)(this + 0x554) = PTR_procPlayerPull_8038c1d0;
              pcVar5 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                       (uint)*(ushort *)(this + 0x2ee),
                                       (uint)*(ushort *)(this + 0x2ec));
              local_90.z = (pcVar5->mNorm).z;
              local_90.x = (pcVar5->mNorm).x;
              local_90.y = d_a_hookshot::_4338;
              fVar12 = mtx::PSVECSquareMag(&local_90);
              dVar11 = (double)fVar12;
              if ((double)d_a_hookshot::_4338 < dVar11) {
                dVar10 = 1.0 / SQRT(dVar11);
                dVar10 = d_a_hookshot::_4339 * dVar10 *
                         (d_a_hookshot::_4340 - dVar11 * dVar10 * dVar10);
                dVar10 = d_a_hookshot::_4339 * dVar10 *
                         (d_a_hookshot::_4340 - dVar11 * dVar10 * dVar10);
                dVar11 = (double)(float)(dVar11 * d_a_hookshot::_4339 * dVar10 *
                                                  (d_a_hookshot::_4340 - dVar11 * dVar10 * dVar10));
              }
              iVar2 = SComponent::cM_atan2s((pcVar5->mNorm).y,(float)dVar11);
              *(short *)(this + 0x2b4) = (short)iVar2;
              iVar2 = SComponent::cM_atan2s(-(pcVar5->mNorm).x,-(pcVar5->mNorm).z);
              *(short *)(this + 0x2b6) = (short)iVar2;
              *(undefined2 *)(this + 0x2b8) = 0;
              *(float *)(this + 0x2c0) = ::cXyz::Zero.x;
              *(float *)(this + 0x2c4) = ::cXyz::Zero.y;
              *(float *)(this + 0x2c8) = ::cXyz::Zero.z;
              uVar9 = dBgS::GetMtrlSndId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                                         (cBgS_PolyInfo *)(this + 0x2ec));
              sVar7 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
              JAIZelBasic::seStart
                        (JAIZelBasic::zel_basic,0x286f,(cXyz *)(this + 0x1f8),uVar9,sVar7,
                         d_a_hookshot::_4190,d_a_hookshot::_4190,d_a_hookshot::_4191,
                         d_a_hookshot::_4191,0);
              local_84.x = d_a_hookshot::_4338;
              local_84.y = d_a_hookshot::_4190;
              local_84.z = d_a_hookshot::_4338;
              dVibration_c::StartShock
                        (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,4,-0x21,&local_84);
            }
          }
          *(undefined4 *)(this + 0x4ec) = *(undefined4 *)(this + 0x1f8);
          *(undefined4 *)(this + 0x4f0) = *(undefined4 *)(this + 0x1fc);
          *(undefined4 *)(this + 0x4f4) = *(undefined4 *)(this + 0x200);
          *(float *)(this + 0x4f8) = local_24.x;
          *(float *)(this + 0x4fc) = local_24.y;
          *(float *)(this + 0x500) = local_24.z;
          *(float *)(this + 0x508) = d_a_hookshot::_4341;
          mtx::PSVECSubtract((cXyz *)(this + 0x4f8),(cXyz *)(this + 0x4ec),(cXyz *)(this + 0x450));
          cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)(this + 0x3d4)
                   );
          dCcMassS_Mng::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng,
                            (cCcD_Obj *)(this + 0x3d4),1);
          *(float *)(this + 0x1f8) = local_24.x;
          *(float *)(this + 0x1fc) = local_24.y;
          *(float *)(this + 0x200) = local_24.z;
          return 1;
        }
      }
      if (this[0x2a3] != (daHookshot_c)0x0) {
        if (*(ushort *)(this + 0x2a6) == 0x825f) {
          dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,1,0x825f,
                             (cXyz *)(this + 0x1f8),(csXyz *)0x0,(cXyz *)0x0,0xff,
                             (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                             (cXyz *)0x0);
        }
        else {
          dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,1,
                             *(ushort *)(this + 0x2a6),(cXyz *)(this + 0x1f8),
                             (csXyz *)(this + 0x2ba),(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1,
                             (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
        }
        uVar9 = *(ulong *)(this + 0x2ac);
        sVar7 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x287b,(cXyz *)(this + 0x1f8),uVar9,sVar7,
                   d_a_hookshot::_4190,d_a_hookshot::_4190,d_a_hookshot::_4191,d_a_hookshot::_4191,0
                  );
      }
      *(undefined4 *)(this + 0xb0) = 2;
      uVar6 = DAT_8038c1c0;
      *(undefined4 *)(this + 0x54c) = d_a_hookshot::_4374;
      *(undefined4 *)(this + 0x550) = uVar6;
      *(undefined **)(this + 0x554) = PTR_procReturn_8038c1c4;
    }
    else {
      pfVar3 = dCcD_GAtTgCoCommonBase::GetAc((dCcD_GAtTgCoCommonBase *)(this + 0x424));
      if (pfVar3 != (fopAc_ac_c *)0x0) {
        if (pfVar3 == (fopAc_ac_c *)0x0) {
          uVar1 = 0xffffffff;
        }
        else {
          uVar1 = (pfVar3->parent).parent.mBsPcId;
        }
        *(uint *)(this + 0x518) = uVar1;
        fVar4 = pfVar3->mStatus;
        if ((fVar4 & 0x80000) == 0) {
          if ((fVar4 & 0x200000) != 0) {
            *(undefined4 *)(this + 0x1f8) = *(undefined4 *)(this + 0x444);
            *(undefined4 *)(this + 0x1fc) = *(undefined4 *)(this + 0x448);
            *(undefined4 *)(this + 0x200) = *(undefined4 *)(this + 0x44c);
            ::cXyz::operator__(&local_48,(cXyz *)(this + 0x1f8),&(pfVar3->mCurrent).mPos);
            *(float *)(this + 0x50c) = local_48.x;
            *(float *)(this + 0x510) = local_48.y;
            *(float *)(this + 0x514) = local_48.z;
            *(short *)(this + 0x2a4) = (pfVar3->mCollisionRot).y;
            *(undefined2 *)(this + 0x2b4) = *(undefined2 *)(this + 0x20c);
            *(undefined2 *)(this + 0x2b6) = *(undefined2 *)(this + 0x20e);
            *(undefined2 *)(this + 0x2b8) = 0;
            *(float *)(this + 0x2c0) = ::cXyz::Zero.x;
            *(float *)(this + 0x2c4) = ::cXyz::Zero.y;
            *(float *)(this + 0x2c8) = ::cXyz::Zero.z;
            *(undefined4 *)(this + 0xb0) = 3;
            this[0x2a2] = (daHookshot_c)0x0;
            uVar6 = DAT_8038c1a8;
            *(undefined4 *)(this + 0x54c) = d_a_hookshot::_4360;
            *(undefined4 *)(this + 0x550) = uVar6;
            *(undefined **)(this + 0x554) = PTR_procPlayerPull_8038c1ac;
            sVar7 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x286f,(cXyz *)(this + 0x1f8),0,sVar7,
                       d_a_hookshot::_4190,d_a_hookshot::_4190,d_a_hookshot::_4191,
                       d_a_hookshot::_4191,0);
            local_54.x = d_a_hookshot::_4338;
            local_54.y = d_a_hookshot::_4190;
            local_54.z = d_a_hookshot::_4338;
            dVibration_c::StartShock
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,4,-0x21,&local_54);
            return 1;
          }
          if ((*(uint *)(this + 0x428) & 1) != 0) {
            sVar7 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x287b,(cXyz *)(this + 0x1f8),0x20,sVar7,
                       d_a_hookshot::_4190,d_a_hookshot::_4190,d_a_hookshot::_4191,
                       d_a_hookshot::_4191,0);
          }
        }
        else {
          pfVar3->mStatus = fVar4 | 0x100000;
          ::cXyz::operator__(&local_30,&(pfVar3->mCurrent).mPos,(cXyz *)(this + 0x1f8));
          *(float *)(this + 0x50c) = local_30.x;
          *(float *)(this + 0x510) = local_30.y;
          *(float *)(this + 0x514) = local_30.z;
          sVar7 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x286f,(cXyz *)(this + 0x1f8),0,sVar7,
                     d_a_hookshot::_4190,d_a_hookshot::_4190,d_a_hookshot::_4191,d_a_hookshot::_4191
                     ,0);
          local_3c.x = d_a_hookshot::_4338;
          local_3c.y = d_a_hookshot::_4190;
          local_3c.z = d_a_hookshot::_4338;
          dVibration_c::StartShock
                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,4,-0x21,&local_3c);
        }
      }
      *(undefined4 *)(this + 0xb0) = 2;
      uVar6 = DAT_8038c1b4;
      *(undefined4 *)(this + 0x54c) = d_a_hookshot::_4364;
      *(undefined4 *)(this + 0x550) = uVar6;
      *(undefined **)(this + 0x554) = PTR_procReturn_8038c1b8;
    }
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daHookshot_c::procPlayerPull(void) */

undefined4 __thiscall daHookshot_c::procPlayerPull(daHookshot_c *this)

{
  short sVar1;
  undefined4 uVar2;
  char cVar4;
  uint uVar3;
  uint uVar5;
  uint uVar6;
  daShip_c *pdVar7;
  double dVar8;
  double dVar9;
  float fVar10;
  int local_64;
  cXyz local_60;
  cXyz local_54;
  cXyz cStack72;
  cXyz local_3c;
  cXyz local_30;
  cXyz local_24;
  double local_18;
  
  pdVar7 = (daShip_c *)0x0;
  if (*(int *)(this + 0x518) == -1) {
    if ((*(int *)(this + 0xb0) == 2) ||
       (cVar4 = cBgS::ChkPolySafe((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                  (cBgS_PolyInfo *)(this + 0x2ec)), cVar4 == '\0')) {
      uVar2 = DAT_8038c1e4;
      *(undefined4 *)(this + 0x54c) = d_a_hookshot::_4581;
      *(undefined4 *)(this + 0x550) = uVar2;
      *(undefined **)(this + 0x554) = PTR_procReturn_8038c1e8;
      return 1;
    }
    cVar4 = dBgS::ChkMoveBG(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                            (cBgS_PolyInfo *)(this + 0x2ec));
    if (cVar4 != '\0') {
      dBgS::MoveBgTransPos
                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,(cBgS_PolyInfo *)(this + 0x2ec),true
                 ,(cXyz *)(this + 0x1f8),(csXyz *)(this + 0x2b4),(csXyz *)0x0);
    }
  }
  else {
    local_64 = *(int *)(this + 0x518);
    pdVar7 = (daShip_c *)f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_64);
    uVar2 = DAT_8038c1d8;
    if ((pdVar7 == (daShip_c *)0x0) || (*(int *)(this + 0xb0) == 2)) {
      *(undefined4 *)(this + 0x54c) = d_a_hookshot::_4574;
      *(undefined4 *)(this + 0x550) = uVar2;
      *(undefined **)(this + 0x554) = PTR_procReturn_8038c1dc;
      *(undefined4 *)(this + 0x518) = 0xffffffff;
      return 1;
    }
    sVar1 = (pdVar7->parent).mCollisionRot.y;
    if (sVar1 != *(short *)(this + 0x2a4)) {
      m_Do_mtx::mDoMtx_YrotS(&mDoMtx_stack_c::now,(int)(short)(sVar1 - *(short *)(this + 0x2a4)));
      mtx::PSMTXMultVec(&mDoMtx_stack_c::now,(cXyz *)(this + 0x50c),&local_24);
      *(float *)(this + 0x50c) = local_24.x;
      *(float *)(this + 0x510) = local_24.y;
      *(float *)(this + 0x514) = local_24.z;
      *(short *)(this + 0x2a4) = (pdVar7->parent).mCollisionRot.y;
    }
    ::cXyz::operator__(&local_3c,&(pdVar7->parent).mCurrent.mPos,(cXyz *)(this + 0x50c));
    *(float *)(this + 0x1f8) = local_3c.x;
    *(float *)(this + 0x1fc) = local_3c.y;
    *(float *)(this + 0x200) = local_3c.z;
  }
  daPy_lk_c::getHookshotRootPos((daPy_lk_c *)&cStack72);
  ::cXyz::operator__(&local_54,(cXyz *)(this + 0x1f8),&cStack72);
  local_30.x = local_54.x;
  local_30.y = local_54.y;
  local_30.z = local_54.z;
  fVar10 = mtx::PSVECSquareMag(&local_30);
  dVar9 = (double)fVar10;
  if ((double)d_a_hookshot::_4338 < dVar9) {
    dVar8 = 1.0 / SQRT(dVar9);
    dVar8 = d_a_hookshot::_4339 * dVar8 * (d_a_hookshot::_4340 - dVar9 * dVar8 * dVar8);
    dVar8 = d_a_hookshot::_4339 * dVar8 * (d_a_hookshot::_4340 - dVar9 * dVar8 * dVar8);
    dVar9 = (double)(float)(dVar9 * d_a_hookshot::_4339 * dVar8 *
                                    (d_a_hookshot::_4340 - dVar9 * dVar8 * dVar8));
  }
  uVar3 = (uint)(dVar9 / (double)d_a_hookshot::_4127);
  local_18 = (double)(longlong)(int)uVar3;
  if ((int)uVar3 < 1) {
    *(undefined4 *)(this + 0x2a8) = 0;
  }
  else {
    uVar5 = *(uint *)(this + 0x2a8);
    uVar3 = uVar3 - uVar5 & -((uint)(uVar5 < uVar3) - ((int)uVar5 >> 0x1f)) - ((int)uVar3 >> 0x1f);
    uVar6 = uVar3 + 9;
    if ((int)uVar5 < 10) {
      uVar6 = uVar3 + uVar5;
    }
    *(uint *)(this + 0x2a8) = *(int *)(this + 0x2a8) - uVar6;
    local_18 = (double)CONCAT44(0x43300000,uVar6 ^ 0x80000000);
    ::cXyz::operator_(&local_60,&local_30,
                      (float)((double)(d_a_hookshot::_4127 * (float)(local_18 - d_a_hookshot::_4651)
                                      ) / dVar9));
    *(float *)(this + 0x2c0) = local_60.x;
    *(float *)(this + 0x2c4) = local_60.y;
    *(float *)(this + 0x2c8) = local_60.z;
  }
  if (*(int *)(this + 0x2a8) < 1) {
    if ((pdVar7 != (daShip_c *)0x0) && (pdVar7 == d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpShip))
    {
      this[0x2a2] = (daHookshot_c)0x1;
    }
    procWait_init(this,1);
  }
  return 1;
}


/* __thiscall daHookshot_c::procReturn(void) */

undefined4 __thiscall daHookshot_c::procReturn(daHookshot_c *this)

{
  fopAc_ac_c *pfVar1;
  double dVar2;
  double dVar3;
  float fVar4;
  int local_64;
  cXyz local_60;
  cXyz cStack84;
  cXyz local_48;
  cXyz cStack60;
  float local_30;
  f_pc_profile__Profile_Actor *local_2c;
  create_request *local_28;
  cXyz local_24;
  longlong local_18;
  
  if (*(int *)(this + 0x518) == -1) {
    pfVar1 = (fopAc_ac_c *)0x0;
  }
  else {
    local_64 = *(int *)(this + 0x518);
    pfVar1 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_64);
    if ((pfVar1 == (fopAc_ac_c *)0x0) || ((pfVar1->mStatus & 0x100000) == 0)) {
      *(undefined4 *)(this + 0x518) = 0xffffffff;
      pfVar1 = (fopAc_ac_c *)0x0;
    }
  }
  if (*(int *)(this + 0x2a8) < 10) {
    if (pfVar1 != (fopAc_ac_c *)0x0) {
      pfVar1->mStatus = pfVar1->mStatus & 0xffefffff;
    }
    procWait_init(this,1);
    procWait(this);
  }
  else {
    daPy_lk_c::getHookshotRootPos((daPy_lk_c *)&cStack60);
    ::cXyz::operator__(&local_48,(cXyz *)(this + 0x1f8),&cStack60);
    local_24.x = local_48.x;
    local_24.y = local_48.y;
    local_24.z = local_48.z;
    fVar4 = mtx::PSVECSquareMag(&local_24);
    dVar3 = (double)fVar4;
    if ((double)d_a_hookshot::_4338 < dVar3) {
      dVar2 = 1.0 / SQRT(dVar3);
      dVar2 = d_a_hookshot::_4339 * dVar2 * (d_a_hookshot::_4340 - dVar3 * dVar2 * dVar2);
      dVar2 = d_a_hookshot::_4339 * dVar2 * (d_a_hookshot::_4340 - dVar3 * dVar2 * dVar2);
      dVar3 = (double)(float)(dVar3 * d_a_hookshot::_4339 * dVar2 *
                                      (d_a_hookshot::_4340 - dVar3 * dVar2 * dVar2));
    }
    local_18 = (longlong)(int)(dVar3 / (double)d_a_hookshot::_4127);
    if ((int)(dVar3 / (double)d_a_hookshot::_4127) < 10) {
      if (pfVar1 != (fopAc_ac_c *)0x0) {
        pfVar1->mStatus = pfVar1->mStatus & 0xffefffff;
      }
      procWait_init(this,1);
      procWait(this);
    }
    else {
      *(int *)(this + 0x2a8) = *(int *)(this + 0x2a8) + -9;
      ::cXyz::operator_(&cStack84,&local_24,(float)((double)d_a_hookshot::_4726 / dVar3));
      mtx::PSVECSubtract((cXyz *)(this + 0x1f8),&cStack84,(cXyz *)(this + 0x1f8));
      if (pfVar1 != (fopAc_ac_c *)0x0) {
        ::cXyz::operator__(&local_60,(cXyz *)(this + 0x1f8),(cXyz *)(this + 0x50c));
        (pfVar1->mCurrent).mPos.x = local_60.x;
        (pfVar1->mCurrent).mPos.y = local_60.y;
        (pfVar1->mCurrent).mPos.z = local_60.z;
        local_28 = (create_request *)(pfVar1->mCurrent).mPos.z;
        local_30 = (pfVar1->mCurrent).mPos.x;
        local_2c = (f_pc_profile__Profile_Actor *)
                   (d_a_hookshot::_4727 + (pfVar1->mCurrent).mPos.y + d_a_hookshot::_4727);
        *(float *)(this + 0x368) = local_30;
        *(f_pc_profile__Profile_Actor **)(this + 0x36c) = local_2c;
        *(create_request **)(this + 0x370) = local_28;
        dVar3 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                          (cBgS_GndChk *)(this + 0x344));
        if ((double)(pfVar1->mCurrent).mPos.y < dVar3) {
          (pfVar1->mCurrent).mPos.y = (float)dVar3;
          *(float *)(this + 0x510) = (float)(dVar3 - (double)*(float *)(this + 0x1fc));
        }
      }
    }
  }
  return 1;
}


/* __thiscall daHookshot_c::execute(void) */

undefined4 __thiscall daHookshot_c::execute(daHookshot_c *this)

{
  daPy_lk_c *pdVar1;
  byte bVar2;
  sbyte sVar4;
  bool bVar5;
  int iVar3;
  daHookshot_c dVar6;
  void *in_r4;
  int in_r6;
  double dVar7;
  double dVar8;
  float fVar9;
  cXyz local_48;
  cXyz local_3c;
  cXyz cStack48;
  cXyz local_24;
  longlong local_18;
  
  pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor;
  if (*(int *)(this + 0xb0) != 0) {
    sVar4 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
    in_r4 = (void *)0x206c;
    in_r6 = 0;
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x206c,&(pdVar1->parent).parent.mCurrent.mPos,0,sVar4,
               d_a_hookshot::_4190,d_a_hookshot::_4190,d_a_hookshot::_4191,d_a_hookshot::_4191,0);
    if (*(int *)(this + 0xb0) != 1) {
      sVar4 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
      in_r4 = (void *)0x206d;
      in_r6 = 0;
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x206d,&(pdVar1->parent).parent.mCurrent.mPos,0,sVar4,
                 d_a_hookshot::_4190,d_a_hookshot::_4190,d_a_hookshot::_4191,d_a_hookshot::_4191,0);
    }
  }
  bVar5 = Runtime.PPCEABI.H::__ptmf_test((PTMF *)(this + 0x54c));
  if (bVar5 != false) {
    Runtime.PPCEABI.H::__ptmf_scall((PTMF *)(this + 0x54c),this,in_r4);
  }
  *(undefined4 *)(this + 0x274) = *(undefined4 *)(this + 0x1f8);
  *(undefined4 *)(this + 0x278) = *(undefined4 *)(this + 0x1fc);
  *(undefined4 *)(this + 0x27c) = *(undefined4 *)(this + 0x200);
  *(undefined4 *)(this + 0x260) = *(undefined4 *)(this + 0x274);
  *(undefined4 *)(this + 0x264) = *(undefined4 *)(this + 0x278);
  *(undefined4 *)(this + 0x268) = *(undefined4 *)(this + 0x27c);
  daPy_lk_c::getHookshotRootPos((daPy_lk_c *)&cStack48);
  ::cXyz::operator__(&local_3c,(cXyz *)(this + 0x1f8),&cStack48);
  local_24.x = local_3c.x;
  local_24.y = local_3c.y;
  local_24.z = local_3c.z;
  fVar9 = mtx::PSVECSquareMag(&local_24);
  dVar8 = (double)fVar9;
  if ((double)d_a_hookshot::_4338 < dVar8) {
    dVar7 = 1.0 / SQRT(dVar8);
    dVar7 = d_a_hookshot::_4339 * dVar7 * (d_a_hookshot::_4340 - dVar8 * dVar7 * dVar7);
    dVar7 = d_a_hookshot::_4339 * dVar7 * (d_a_hookshot::_4340 - dVar8 * dVar7 * dVar7);
    dVar8 = (double)(float)(dVar8 * d_a_hookshot::_4339 * dVar7 *
                                    (d_a_hookshot::_4340 - dVar8 * dVar7 * dVar7));
  }
  local_18 = (longlong)(int)(dVar8 / (double)d_a_hookshot::_4127);
  *(int *)(this + 0x2a8) = (int)(dVar8 / (double)d_a_hookshot::_4127);
  if ((*(int *)(this + 0xb0) == 3) && (*(int *)(this + 0x2a8) < 0x13)) {
    *(short *)(this + 0x20c) = (pdVar1->parent).parent.mCollisionRot.x;
    *(short *)(this + 0x20e) = (pdVar1->parent).parent.mCollisionRot.y;
  }
  else {
    local_48.x = local_24.x;
    local_48.y = d_a_hookshot::_4338;
    local_48.z = local_24.z;
    fVar9 = mtx::PSVECSquareMag(&local_48);
    dVar8 = (double)fVar9;
    if ((double)d_a_hookshot::_4338 < dVar8) {
      dVar7 = 1.0 / SQRT(dVar8);
      dVar7 = d_a_hookshot::_4339 * dVar7 * (d_a_hookshot::_4340 - dVar8 * dVar7 * dVar7);
      dVar7 = d_a_hookshot::_4339 * dVar7 * (d_a_hookshot::_4340 - dVar8 * dVar7 * dVar7);
      dVar8 = (double)(float)(dVar8 * d_a_hookshot::_4339 * dVar7 *
                                      (d_a_hookshot::_4340 - dVar8 * dVar7 * dVar7));
    }
    iVar3 = SComponent::cM_atan2s(-local_24.y,(float)dVar8);
    *(short *)(this + 0x20c) = (short)iVar3;
    iVar3 = SComponent::cM_atan2s(local_24.x,local_24.z);
    *(short *)(this + 0x20e) = (short)iVar3;
  }
  if ((*(int *)(this + 0xb0) == 0) || (this[0x2a0] != (daHookshot_c)0x0)) {
    this[0x2a0] = (daHookshot_c)0x0;
  }
  else {
    mtx::PSMTXTrans((double)*(float *)(this + 0x1f8),(double)*(float *)(this + 0x1fc),
                    (double)*(float *)(this + 0x200),&mDoMtx_stack_c::now);
    in_r6 = 0;
    m_Do_mtx::mDoMtx_ZXYrotM
              (&mDoMtx_stack_c::now,(int)*(short *)(this + 0x20c),(int)*(short *)(this + 0x20e));
    m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,-0x4000);
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(this + 0x51c));
  }
  bVar2 = dStage_roomControl_c::mStayNo;
  this[0x1b5] = (daHookshot_c)dStage_roomControl_c::mStayNo;
  this[0x3ba] = (daHookshot_c)bVar2;
  this[0x20a] = (daHookshot_c)bVar2;
  if (*(int *)(this + 0xb0) != 0) {
    dVar6 = (daHookshot_c)
            daPy_lk_c::setItemWaterEffect
                      ((daPy_lk_c *)this,(fopAc_ac_c *)(uint)(byte)this[0x2a1],0,in_r6);
    this[0x2a1] = dVar6;
  }
  iVar3 = *(int *)(this + 0xb0);
  if (iVar3 == 1) {
    fVar9 = mtx::PSVECSquareDistance((cXyz *)(this + 0x1f8),(cXyz *)(this + 0x1e4));
    dVar8 = (double)fVar9;
    if ((double)d_a_hookshot::_4338 < dVar8) {
      dVar7 = 1.0 / SQRT(dVar8);
      dVar7 = d_a_hookshot::_4339 * dVar7 * (d_a_hookshot::_4340 - dVar8 * dVar7 * dVar7);
      dVar7 = d_a_hookshot::_4339 * dVar7 * (d_a_hookshot::_4340 - dVar8 * dVar7 * dVar7);
      dVar8 = (double)(float)(dVar8 * d_a_hookshot::_4339 * dVar7 *
                                      (d_a_hookshot::_4340 - dVar8 * dVar7 * dVar7));
    }
    *(float *)(this + 0x254) = (float)dVar8;
  }
  else {
    if ((iVar3 == 2) || (iVar3 == 3)) {
      fVar9 = mtx::PSVECSquareDistance((cXyz *)(this + 0x1f8),(cXyz *)(this + 0x1e4));
      dVar8 = (double)fVar9;
      if ((double)d_a_hookshot::_4338 < dVar8) {
        dVar7 = 1.0 / SQRT(dVar8);
        dVar7 = d_a_hookshot::_4339 * dVar7 * (d_a_hookshot::_4340 - dVar8 * dVar7 * dVar7);
        dVar7 = d_a_hookshot::_4339 * dVar7 * (d_a_hookshot::_4340 - dVar8 * dVar7 * dVar7);
        dVar8 = (double)(float)(dVar8 * d_a_hookshot::_4339 * dVar7 *
                                        (d_a_hookshot::_4340 - dVar8 * dVar7 * dVar7));
      }
      *(float *)(this + 0x254) = (float)-dVar8;
    }
    else {
      *(float *)(this + 0x254) = d_a_hookshot::_4338;
    }
  }
  return 1;
}


namespace d_a_hookshot {

/* __stdcall daHookshot_Execute(daHookshot_c *) */

void daHookshot_Execute(daHookshot_c *param_1)

{
  ::daHookshot_c::execute(param_1);
  return;
}


/* __stdcall daHookshot_IsDelete(daHookshot_c *) */

undefined4 daHookshot_IsDelete(void)

{
  return 1;
}

}

/* __thiscall daHookshot_c::hookshot_delete(void) */

undefined4 __thiscall daHookshot_c::hookshot_delete(daHookshot_c *this)

{
  fopAc_ac_c *pfVar1;
  int local_18 [5];
  
  local_18[0] = *(int *)(this + 0x518);
  if (local_18[0] != -1) {
    pfVar1 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,local_18);
    if ((pfVar1 != (fopAc_ac_c *)0x0) && ((pfVar1->mStatus & 0x100000) != 0)) {
      pfVar1->mStatus = pfVar1->mStatus & 0xffefffff;
      *(undefined4 *)(this + 0x518) = 0xffffffff;
    }
  }
  return 1;
}


namespace d_a_hookshot {

/* __stdcall daHookshot_Delete(daHookshot_c *) */

undefined4 daHookshot_Delete(daHookshot_c *param_1)

{
  ::daHookshot_c::hookshot_delete(param_1);
  return 1;
}

}

/* __thiscall daHookshot_c::create(void) */

undefined4 __thiscall daHookshot_c::create(daHookshot_c *this)

{
  byte bVar1;
  
  if ((*(uint *)(this + 0x1c8) & 8) == 0) {
    if (this != (daHookshot_c *)0x0) {
      daHookshot_c(this);
    }
    *(uint *)(this + 0x1c8) = *(uint *)(this + 0x1c8) | 8;
  }
  *(daHookshot_c **)(this + 0x29c) = this;
  *(uint *)(this + 0x324) = *(uint *)(this + 0x324) & 0xdfffffff;
  procWait_init(this,0);
  *(float *)(this + 600) = d_a_hookshot::_4913;
  ::dCcD_Stts::Init((dCcD_Stts *)(this + 0x398),10,0xff,(fopAc_ac_c *)this);
  ::dCcD_Cps::Set((dCcD_Cps *)(this + 0x3d4),(dCcD_SrcCps *)&d_a_hookshot::l_at_cps_src);
  *(daHookshot_c **)(this + 0x418) = this + 0x398;
  bVar1 = dStage_roomControl_c::mStayNo;
  this[0x1b5] = (daHookshot_c)dStage_roomControl_c::mStayNo;
  this[0x3ba] = (daHookshot_c)bVar1;
  this[0x20a] = (daHookshot_c)bVar1;
  return 4;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daHookshot_c::daHookshot_c(void) */

void __thiscall daHookshot_c::daHookshot_c(daHookshot_c *this)

{
  daHookshot_c *pdVar1;
  
  fopAc_ac_c::fopAc_ac_c((fopAc_ac_c *)this);
  *(undefined ***)(this + 0x290) = &J3DPacket::__vt;
  *(undefined4 *)(this + 0x294) = 0;
  *(undefined4 *)(this + 0x298) = 0;
  *(undefined4 *)(this + 0x29c) = 0;
  *(undefined1 **)(this + 0x290) = &daHookshot_shape::__vt;
  *(cBgS_Chk__vtbl **)(this + 0x2e8) = &cBgS_Chk::__vt;
  *(undefined4 *)(this + 0x2d8) = 0;
  *(undefined4 *)(this + 0x2dc) = 0;
  this[0x2e4] = (daHookshot_c)0x1;
  *(undefined ***)(this + 0x2f8) = &::cBgS_PolyInfo::__vt;
  *(undefined2 *)(this + 0x2ec) = 0xffff;
  *(undefined2 *)(this + 0x2ee) = 0x100;
  *(undefined4 *)(this + 0x2f0) = 0;
  *(undefined4 *)(this + 0x2f4) = 0xffffffff;
  *(undefined ***)(this + 0x2e8) = &::cBgS_LinChk::__vt;
  *(undefined ***)(this + 0x2f8) = &PTR_80371fbc;
  *(undefined ***)(this + 0x314) = &::cM3dGLin::__vt;
  ::cBgS_LinChk::ct((cBgS_LinChk *)(this + 0x2d8));
  *(undefined ***)(this + 0x330) = &::cBgS_PolyPassChk::__vt;
  *(undefined ***)(this + 0x330) = &::dBgS_PolyPassChk::__vt;
  this[0x334] = (daHookshot_c)0x0;
  this[0x335] = (daHookshot_c)0x0;
  this[0x336] = (daHookshot_c)0x0;
  this[0x337] = (daHookshot_c)0x0;
  this[0x338] = (daHookshot_c)0x0;
  this[0x339] = (daHookshot_c)0x0;
  this[0x33a] = (daHookshot_c)0x0;
  *(undefined ***)(this + 0x33c) = &::cBgS_GrpPassChk::__vt;
  *(undefined ***)(this + 0x33c) = &::dBgS_GrpPassChk::__vt;
  *(undefined4 *)(this + 0x340) = 1;
  *(undefined ***)(this + 0x330) = &::dBgS_Chk::__vt;
  *(undefined ***)(this + 0x33c) = &PTR_80371f68;
  *(undefined ***)(this + 0x2e8) = &::dBgS_LinChk::__vt;
  *(undefined **)(this + 0x2f8) = &DAT_80371f38;
  *(undefined ***)(this + 0x330) = &PTR_80371f44;
  *(undefined ***)(this + 0x33c) = &PTR_80371f50;
  (((cBgS_LinChk *)(this + 0x2d8))->parent).mpPolyPassChk = (cBgS_PolyPassChk *)(this + 0x330);
  pdVar1 = this + 0x330;
  if (pdVar1 != (daHookshot_c *)0x0) {
    pdVar1 = this + 0x33c;
  }
  *(daHookshot_c **)(this + 0x2dc) = pdVar1;
  *(undefined ***)(this + 0x2e8) = &dBgS_RopeLinChk::__vt;
  *(undefined **)(this + 0x2f8) = &DAT_8038c418;
  *(undefined **)(this + 0x330) = &DAT_8038c424;
  *(undefined **)(this + 0x33c) = &DAT_8038c430;
  this[0x33a] = (daHookshot_c)0x1;
  ::cBgS_GndChk::cBgS_GndChk((cBgS_GndChk *)(this + 0x344));
  *(undefined ***)(this + 900) = &::cBgS_PolyPassChk::__vt;
  *(undefined ***)(this + 900) = &::dBgS_PolyPassChk::__vt;
  this[0x388] = (daHookshot_c)0x0;
  this[0x389] = (daHookshot_c)0x0;
  this[0x38a] = (daHookshot_c)0x0;
  this[0x38b] = (daHookshot_c)0x0;
  this[0x38c] = (daHookshot_c)0x0;
  this[0x38d] = (daHookshot_c)0x0;
  this[0x38e] = (daHookshot_c)0x0;
  *(undefined ***)(this + 0x390) = &::cBgS_GrpPassChk::__vt;
  *(undefined ***)(this + 0x390) = &::dBgS_GrpPassChk::__vt;
  *(undefined4 *)(this + 0x394) = 1;
  *(undefined ***)(this + 900) = &::dBgS_Chk::__vt;
  *(undefined ***)(this + 0x390) = &PTR_80371f68;
  *(cBgS_Chk__vtbl **)(this + 0x354) = &::dBgS_GndChk::__vt;
  *(cBgS_PolyInfo__vtbl **)(this + 0x364) = &cBgS_PolyInfo__vtbl_80371f08;
  *(undefined ***)(this + 900) = &PTR_80371f14;
  *(undefined ***)(this + 0x390) = &PTR_80371f20;
  (((cBgS_GndChk *)(this + 0x344))->parent).mpPolyPassChk = (cBgS_PolyPassChk *)(this + 900);
  pdVar1 = this + 900;
  if (pdVar1 != (daHookshot_c *)0x0) {
    pdVar1 = this + 0x390;
  }
  *(daHookshot_c **)(this + 0x348) = pdVar1;
  *(cBgS_Chk__vtbl **)(this + 0x354) = &::dBgS_ObjGndChk::__vt;
  *(cBgS_PolyInfo__vtbl **)(this + 0x364) = &cBgS_PolyInfo__vtbl_80371ed8;
  *(cBgS_PolyPassChk__vtbl **)(this + 900) = &cBgS_PolyPassChk__vtbl_80371ee4;
  *(cBgS_GrpPassChk__vtbl **)(this + 0x390) = &cBgS_GrpPassChk__vtbl_80371ef0;
  this[0x388] = (daHookshot_c)0x1;
  *(cCcD_Stts__vtbl **)(this + 0x3b0) = &cCcD_Stts::__vt;
  ::dCcD_GStts::dCcD_GStts((dCcD_GStts *)(this + 0x3b4));
  *(dCcD_Stts__vtbl **)(this + 0x3b0) = &::dCcD_Stts::__vt;
  *(undefined4 *)(this + 0x3b4) = 0x8037ec40;
  dCcD_GObjInf::dCcD_GObjInf((dCcD_GObjInf *)(this + 0x3d4));
  *(undefined ***)(this + 0x4e8) = &::cCcD_ShapeAttr::__vt;
  *(cM3dGAab__vtbl **)(this + 0x4e4) = &::cM3dGAab::__vt;
  *(undefined ***)(this + 0x504) = &::cM3dGLin::__vt;
  *(undefined ***)(this + 0x504) = &::cM3dGCps::__vt;
  *(cCcD_ShapeAttr__vtbl **)(this + 0x4e8) = &::cCcD_CpsAttr::__vt;
  *(undefined **)(this + 0x504) = &DAT_8039520c;
  *(undefined1 **)(this + 0x410) = &::dCcD_Cps::__vt;
  *(undefined **)(this + 0x4e8) = &DAT_80389a8c;
  *(undefined **)(this + 0x504) = &DAT_80389ae0;
  return;
}


/* __thiscall dBgS_RopeLinChk::~dBgS_RopeLinChk(void) */

void __thiscall dBgS_RopeLinChk::_dBgS_RopeLinChk(dBgS_RopeLinChk *this)

{
  short in_r4;
  
  if (this != (dBgS_RopeLinChk *)0x0) {
    (this->parent).parent.parent.vtbl = (cBgS_Chk__vtbl *)&__vt;
    (this->parent).parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_8038c418;
    (this->parent).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&DAT_8038c424;
    (this->parent).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&DAT_8038c430;
    if (this != (dBgS_RopeLinChk *)0x0) {
      (this->parent).parent.parent.vtbl = (cBgS_Chk__vtbl *)&::dBgS_LinChk::__vt;
      (this->parent).parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_80371f38;
      (this->parent).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f44;
      (this->parent).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f50;
      if (this != (dBgS_RopeLinChk *)0xffffffa8) {
        (this->parent).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
        (this->parent).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
        if (this != (dBgS_RopeLinChk *)0xffffff9c) {
          (this->parent).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt
          ;
          if (this != (dBgS_RopeLinChk *)0xffffff9c) {
            (this->parent).mGrpPassChk.parent.vtbl =
                 (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
          }
        }
        if ((this != (dBgS_RopeLinChk *)0xffffffa8) &&
           ((this->parent).mPolyPassChk.parent.vtbl =
                 (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
           this != (dBgS_RopeLinChk *)0xffffffa8)) {
          (this->parent).mPolyPassChk.parent.vtbl =
               (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
        }
      }
      if (this != (dBgS_RopeLinChk *)0x0) {
        (this->parent).parent.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
        (this->parent).parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371fbc;
        if (this != (dBgS_RopeLinChk *)0xffffffdc) {
          (this->parent).parent.mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
        }
        if (this != (dBgS_RopeLinChk *)0xffffffec) {
          (this->parent).parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
        }
        cBgS_Chk::_cBgS_Chk((cBgS_Chk *)this);
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_a_hookshot {

/* __stdcall daHookshot_Create(fopAc_ac_c *) */

void daHookshot_Create(daHookshot_c *param_1)

{
  ::daHookshot_c::create(param_1);
  return;
}


void __sinit_d_a_hookshot_cpp(void)

{
  DAT_8038c0d1 = 1;
  DAT_8038c0d2 = 0xc5;
  DAT_8038c0d3 = 0xea;
  return;
}

}

/* [thunk]:__thiscall dBgS_RopeLinChk::~dBgS_RopeLinChk(void) */

void __thiscall dBgS_RopeLinChk::_dBgS_RopeLinChk(dBgS_RopeLinChk *this)

{
  _dBgS_RopeLinChk((dBgS_RopeLinChk *)&this[-1].parent.mPolyPassChk);
  return;
}


/* [thunk]:__thiscall dBgS_RopeLinChk::~dBgS_RopeLinChk(void) */

void __thiscall dBgS_RopeLinChk::_dBgS_RopeLinChk(dBgS_RopeLinChk *this)

{
  _dBgS_RopeLinChk((dBgS_RopeLinChk *)&this[-1].parent.parent.parent.mProcID);
  return;
}


/* [thunk]:__thiscall dBgS_RopeLinChk::~dBgS_RopeLinChk(void) */

void __thiscall dBgS_RopeLinChk::_dBgS_RopeLinChk(dBgS_RopeLinChk *this)

{
  _dBgS_RopeLinChk((dBgS_RopeLinChk *)&this[-1].parent.parent.mPolyInfo);
  return;
}


/* __thiscall daPy_lk_c::getHookshotRootPos(void) const */

void __thiscall daPy_lk_c::getHookshotRootPos(daPy_lk_c *this)

{
  int in_r4;
  
  (this->parent).parent.parent.parent.mBsType = *(uint *)(in_r4 + 0x36e8);
  (this->parent).parent.parent.parent.mBsPcId = *(uint *)(in_r4 + 0x36ec);
  *(undefined4 *)&(this->parent).parent.parent.parent.mProcName = *(undefined4 *)(in_r4 + 0x36f0);
  return;
}


/* __thiscall daPy_lk_c::getModelJointMtx(unsigned short) */

MTX34 * __thiscall daPy_lk_c::getModelJointMtx(daPy_lk_c *this,ushort param_1)

{
  return this->mpCLModel->mpNodeMtx + param_1;
}


/* __thiscall daHookshot_shape::~daHookshot_shape(void) */

void __thiscall daHookshot_shape::_daHookshot_shape(daHookshot_shape *this)

{
  short in_r4;
  
  if (this != (daHookshot_shape *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (daHookshot_shape *)0x0) {
      *(undefined ***)this = &J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

