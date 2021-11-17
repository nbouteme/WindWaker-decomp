#include <d_chain.h>
#include <JKernel/JKRHeap.h>
#include <m_Do_ext.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <gx/GXAttr.h>
#include <d_kankyo.h>
#include <gx/GXDisplayList.h>
#include <gx/GXTev.h>
#include <gx/GXTransform.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <d_a_obj.h>
#include <mtx/mtx.h>
#include <d_chain.h>
#include <dChain_packet_c.h>


/* __thiscall dChain_packet_c::dChain_packet_c(int,
                                               dKy_tevstr_c *,
                                               float) */

void __thiscall
dChain_packet_c::dChain_packet_c
          (dChain_packet_c *this,int param_1,dKy_tevstr_c *param_2,float param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  *(undefined ***)this = &J3DPacket::__vt;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined1 **)this = &__vt;
  *(int *)(this + 0x20) = param_1;
  *(float *)(this + 0x14) = param_3;
  *(float *)(this + 0x18) = param_3;
  *(float *)(this + 0x1c) = param_3;
  *(dKy_tevstr_c **)(this + 0x10) = param_2;
  iVar2 = *(int *)(this + 0x20);
  uVar1 = JKernel::operator_new__(iVar2 * 0xc + 0x10);
  uVar1 = Runtime.PPCEABI.H::__construct_new_array(uVar1,::cXyz::cXyz,::cXyz::_cXyz,0xc,iVar2);
  *(undefined4 *)(this + 0x24) = uVar1;
  return;
}


/* __thiscall dChain_packet_c::~dChain_packet_c(void) */

void __thiscall dChain_packet_c::_dChain_packet_c(dChain_packet_c *this)

{
  short in_r4;
  
  if (this != (dChain_packet_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dChain_packet_c *)0x0) {
      *(undefined ***)this = &J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x80062c88) */
/* WARNING: Removing unreachable block (ram,0x80062c78) */
/* WARNING: Removing unreachable block (ram,0x80062c80) */
/* WARNING: Removing unreachable block (ram,0x80062c90) */
/* __thiscall dChain_packet_c::draw(void) */

void __thiscall dChain_packet_c::draw(dChain_packet_c *this)

{
  char cVar1;
  cXyz *pcVar2;
  int iVar3;
  short sVar4;
  float *pfVar5;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  float fVar11;
  _GXColor local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  cXyz cStack168;
  cXyz local_9c;
  Quaternion QStack144;
  undefined local_80 [16];
  float local_70;
  float local_6c;
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
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX8);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_INDEX8);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,0);
  gx::GXSetArray(GX_VA_POS,&d_chain::l_pos,0xc);
  gx::GXSetArray(GX_VA_TEX0,&d_chain::l_texCoord,8);
  d_kankyo::dKy_GxFog_tevstr_set(*(dKy_tevstr_c **)(this + 0x10));
  gx::GXCallDisplayList(&d_chain::l_matDL,0xa0);
  local_b0 = *(undefined4 *)(*(int *)(this + 0x10) + 0x80);
  local_ac = *(undefined4 *)(*(int *)(this + 0x10) + 0x84);
  gx::GXSetTevColorS10(GX_TEVREG0,(_GXColorS10 *)&local_b0);
  local_b4 = *(_GXColor *)(*(int *)(this + 0x10) + 0x88);
  gx::GXSetTevColor(GX_TEVREG1,&local_b4);
  gx::GXSetCurrentMtx(0);
  pfVar5 = *(float **)(this + 0x24);
  dVar9 = (double)((d_chain::_4078 + d_s_play::g_regHIO.mChild[10].mFloats[11]) *
                  *(float *)(this + 0x1c));
  sVar4 = 0;
  local_80._12_4_ = *pfVar5;
  local_70 = pfVar5[1];
  local_6c = pfVar5[2];
  dVar10 = (double)d_chain::_4079;
  for (iVar3 = 0; iVar3 < *(int *)(this + 0x20) + -1; iVar3 = iVar3 + 1) {
    pcVar2 = (cXyz *)(local_80 + 0xc);
    ::cXyz::operator__(&local_9c,(cXyz *)(pfVar5 + (iVar3 + 1) * 3),pcVar2);
    local_80._0_4_ = local_9c.x;
    local_80._4_4_ = local_9c.y;
    local_80._8_4_ = local_9c.z;
    fVar11 = mtx::PSVECSquareMag((cXyz *)local_80);
    dVar8 = (double)fVar11;
    if (dVar10 < dVar8) {
      dVar7 = 1.0 / SQRT(dVar8);
      dVar7 = d_chain::_4080 * dVar7 * (d_chain::_4081 - dVar8 * dVar7 * dVar7);
      dVar7 = d_chain::_4080 * dVar7 * (d_chain::_4081 - dVar8 * dVar7 * dVar7);
      dVar8 = (double)(float)(dVar8 * d_chain::_4080 * dVar7 *
                                      (d_chain::_4081 - dVar8 * dVar7 * dVar7));
    }
    cVar1 = ::cXyz::normalizeRS((cXyz *)local_80);
    if (cVar1 != '\0') {
      ::daObj::quat_rotBaseZ((daObj *)&QStack144,(Quaternion *)local_80,pcVar2);
      dVar7 = (double)d_chain::_4079;
      while (dVar7 < dVar8) {
        mtx::PSMTXTrans((double)local_80._12_4_,(double)local_70,(double)local_6c,
                        &mDoMtx_stack_c::now);
        mDoMtx_stack_c::quatM(&QStack144);
        m_Do_mtx::mDoMtx_ZrotM(&mDoMtx_stack_c::now,sVar4);
        mDoMtx_stack_c::scaleM
                  (*(float *)(this + 0x14),*(float *)(this + 0x18),*(float *)(this + 0x1c));
        mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,&mDoMtx_stack_c::now,&mDoMtx_stack_c::now
                        );
        gx::GXLoadPosMtxImm(&mDoMtx_stack_c::now,0);
        gx::GXCallDisplayList(&d_chain::l_chainDL,0x60);
        dVar8 = (double)(float)(dVar8 - dVar9);
        ::cXyz::operator_(&cStack168,(cXyz *)local_80,(float)dVar9);
        mtx::PSVECAdd((cXyz *)(local_80 + 0xc),&cStack168,(cXyz *)(local_80 + 0xc));
        sVar4 = sVar4 + 0x4000;
      }
    }
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


namespace d_chain {

/* __stdcall dChain_packet_create(int,
                                  dKy_tevstr_c *,
                                  float) */

dChain_packet_c * dChain_packet_create(double param_1,int param_2,dKy_tevstr_c *param_3)

{
  dChain_packet_c *this;
  
  this = (dChain_packet_c *)JKernel::operator_new(0x28);
  if (this != (dChain_packet_c *)0x0) {
    ::dChain_packet_c::dChain_packet_c(this,param_2,param_3,(float)param_1);
  }
  if ((this != (dChain_packet_c *)0x0) && (*(int *)(this + 0x24) == 0)) {
    this = (dChain_packet_c *)0x0;
  }
  return this;
}


void __sinit_d_chain_cpp(void)

{
  DAT_80376d71 = 1;
  DAT_80376d72 = 0xbb;
  DAT_80376d73 = 0x4f;
  return;
}

