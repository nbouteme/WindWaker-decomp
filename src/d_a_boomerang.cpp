#include <d_a_boomerang.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <mtx/mtxvec.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <J3DGraphBase/J3DSys.h>
#include <gx/GXBump.h>
#include <gx/GXTexture.h>
#include <gx/GXDisplayList.h>
#include <gf/GFTev.h>
#include <gf/GFGeometry.h>
#include <gf/GFTransform.h>
#include <m_Do_lib.h>
#include <d_a_boomerang.h>
#include <d_drawlist.h>
#include <d_kankyo.h>
#include <d_material.h>
#include <m_Do_ext.h>
#include <SComponent/c_bg_s.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_bg_s.h>
#include <d_bg_s_lin_chk.h>
#include <d_particle.h>
#include <d_com_inf_game.h>
#include <d_cc_d.h>
#include <SComponent/c_math.h>
#include <d_camera.h>
#include <SComponent/c_cc_s.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <f_op_actor_mng.h>
#include <d_a_player_main.h>
#include <SComponent/c_lib.h>
#include <d_cc_mass_s.h>
#include <f_pc_searcher.h>
#include <f_op_actor_iter.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <f_op_actor.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <SComponent/c_bg_s_lin_chk.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <SComponent/c_bg_s_chk.h>
#include <JKernel/JKRHeap.h>
#include <daBoomerang_c.h>
#include <dBgS_BoomerangLinChk.h>
#include <daPy_lk_c.h>
#include <daPy_py_c.h>
#include <daPy_sightPacket_c.h>
#include <daBoomerang_sightPacket_c.h>
#include <daBoomerang_blur_c.h>


namespace d_a_boomerang {
undefined4 l_blur_top;
undefined4 l_blur_root;
undefined texObj$4441;
undefined at_offset$5155;
undefined1 init$5157;
}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daBoomerang_blur_c::initBlur(float *[][][][],
                                           short) */

void __thiscall daBoomerang_blur_c::initBlur(daBoomerang_blur_c *this,float *param_1,short param_2)

{
  mtx::PSMTXMultVec((MTX34 *)param_1,(cXyz *)&d_a_boomerang::l_blur_top,(cXyz *)(this + 0x24));
  mtx::PSMTXMultVec((MTX34 *)param_1,(cXyz *)&d_a_boomerang::l_blur_root,(cXyz *)(this + 0x2f4));
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(this + 0x24);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(this + 0x28);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(this + 0x2c);
  *(undefined4 *)(this + 0x300) = *(undefined4 *)(this + 0x2f4);
  *(undefined4 *)(this + 0x304) = *(undefined4 *)(this + 0x2f8);
  *(undefined4 *)(this + 0x308) = *(undefined4 *)(this + 0x2fc);
  *(undefined4 *)(this + 0x14) = 0;
  *(float *)(this + 0x18) = param_1[3];
  *(float *)(this + 0x1c) = param_1[7];
  *(float *)(this + 0x20) = param_1[0xb];
  mtx::PSMTXCopy((MTX34 *)param_1,&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,-(short)((int)param_2 << 1));
  mtx::PSMTXMultVec(&mDoMtx_stack_c::now,(cXyz *)&d_a_boomerang::l_blur_top,(cXyz *)(this + 0x5c4));
  mtx::PSMTXMultVec(&mDoMtx_stack_c::now,(cXyz *)&d_a_boomerang::l_blur_root,(cXyz *)(this + 0x894))
  ;
  *(undefined4 *)(this + 0x5d0) = *(undefined4 *)(this + 0x5c4);
  *(undefined4 *)(this + 0x5d4) = *(undefined4 *)(this + 0x5c8);
  *(undefined4 *)(this + 0x5d8) = *(undefined4 *)(this + 0x5cc);
  *(undefined4 *)(this + 0x8a0) = *(undefined4 *)(this + 0x894);
  *(undefined4 *)(this + 0x8a4) = *(undefined4 *)(this + 0x898);
  *(undefined4 *)(this + 0x8a8) = *(undefined4 *)(this + 0x89c);
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x800e0ff4) */
/* WARNING: Removing unreachable block (ram,0x800e0ffc) */
/* __thiscall daBoomerang_blur_c::copyBlur(float *[][][][],
                                           short) */

void __thiscall daBoomerang_blur_c::copyBlur(daBoomerang_blur_c *this,float *param_1,short param_2)

{
  int iVar1;
  daBoomerang_blur_c *pdVar2;
  cXyz *pcVar3;
  cXyz *pcVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 in_f30;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  cXyz cStack168;
  cXyz cStack156;
  cXyz cStack144;
  cXyz cStack132;
  cXyz local_78;
  cXyz local_6c;
  cXyz local_60 [2];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  iVar1 = 0x288;
  iVar5 = 0x37;
  do {
    pdVar2 = this + iVar1;
    *(undefined4 *)(pdVar2 + 0x60) = *(undefined4 *)(pdVar2 + 0x24);
    *(undefined4 *)(pdVar2 + 100) = *(undefined4 *)(pdVar2 + 0x28);
    *(undefined4 *)(pdVar2 + 0x68) = *(undefined4 *)(pdVar2 + 0x2c);
    *(undefined4 *)(pdVar2 + 0x330) = *(undefined4 *)(pdVar2 + 0x2f4);
    *(undefined4 *)(pdVar2 + 0x334) = *(undefined4 *)(pdVar2 + 0x2f8);
    *(undefined4 *)(pdVar2 + 0x338) = *(undefined4 *)(pdVar2 + 0x2fc);
    *(undefined4 *)(pdVar2 + 0x600) = *(undefined4 *)(pdVar2 + 0x5c4);
    *(undefined4 *)(pdVar2 + 0x604) = *(undefined4 *)(pdVar2 + 0x5c8);
    *(undefined4 *)(pdVar2 + 0x608) = *(undefined4 *)(pdVar2 + 0x5cc);
    *(undefined4 *)(pdVar2 + 0x8d0) = *(undefined4 *)(pdVar2 + 0x894);
    *(undefined4 *)(pdVar2 + 0x8d4) = *(undefined4 *)(pdVar2 + 0x898);
    *(undefined4 *)(pdVar2 + 0x8d8) = *(undefined4 *)(pdVar2 + 0x89c);
    iVar1 = iVar1 + -0xc;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  dVar7 = (double)d_a_boomerang::_4431;
  local_60[0].x = param_1[3];
  local_60[0].y = param_1[7];
  local_60[0].z = param_1[0xb];
  ::cXyz::operator__(&local_78,(cXyz *)(this + 0x18),local_60);
  local_6c.x = local_78.x;
  local_6c.y = local_78.y;
  local_6c.z = local_78.z;
  *(float *)(this + 0x18) = local_60[0].x;
  *(float *)(this + 0x1c) = local_60[0].y;
  *(float *)(this + 0x20) = local_60[0].z;
  mDoMtx_stack_c::push();
  iVar1 = 0;
  iVar5 = 0;
  dVar8 = (double)d_a_boomerang::_4432;
  do {
    pcVar3 = (cXyz *)(this + iVar5 + 0x24);
    mtx::PSMTXMultVec(&mDoMtx_stack_c::now,(cXyz *)&d_a_boomerang::l_blur_top,pcVar3);
    pcVar4 = (cXyz *)(this + iVar5 + 0x2f4);
    mtx::PSMTXMultVec(&mDoMtx_stack_c::now,(cXyz *)&d_a_boomerang::l_blur_root,pcVar4);
    ::cXyz::operator_(&cStack132,&local_6c,(float)dVar7);
    mtx::PSVECAdd(pcVar3,&cStack132,pcVar3);
    ::cXyz::operator_(&cStack144,&local_6c,(float)dVar7);
    mtx::PSVECAdd(pcVar4,&cStack144,pcVar4);
    dVar7 = (double)(float)(dVar7 + dVar8);
    m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,0x633);
    iVar1 = iVar1 + 1;
    iVar5 = iVar5 + 0xc;
  } while (iVar1 < 5);
  dVar7 = (double)d_a_boomerang::_4431;
  mDoMtx_stack_c::pop();
  m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,-(short)((int)param_2 << 1));
  iVar1 = 0;
  iVar5 = 0;
  dVar8 = (double)d_a_boomerang::_4432;
  do {
    pcVar4 = (cXyz *)(this + iVar5 + 0x5c4);
    mtx::PSMTXMultVec(&mDoMtx_stack_c::now,(cXyz *)&d_a_boomerang::l_blur_top,pcVar4);
    pcVar3 = (cXyz *)(this + iVar5 + 0x894);
    mtx::PSMTXMultVec(&mDoMtx_stack_c::now,(cXyz *)&d_a_boomerang::l_blur_root,pcVar3);
    ::cXyz::operator_(&cStack156,&local_6c,(float)dVar7);
    mtx::PSVECAdd(pcVar4,&cStack156,pcVar4);
    ::cXyz::operator_(&cStack168,&local_6c,(float)dVar7);
    mtx::PSVECAdd(pcVar3,&cStack168,pcVar3);
    dVar7 = (double)(float)(dVar7 + dVar8);
    m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,-0x633);
    iVar1 = iVar1 + 1;
    iVar5 = iVar5 + 0xc;
  } while (iVar1 < 5);
  *(int *)(this + 0x14) = *(int *)(this + 0x14) + 5;
  if (0x3a < *(int *)(this + 0x14)) {
    *(undefined4 *)(this + 0x14) = 0x3a;
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daBoomerang_blur_c::draw(void) */

void __thiscall daBoomerang_blur_c::draw(daBoomerang_blur_c *this)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  daBoomerang_blur_c *pdVar6;
  short sVar7;
  short sVar8;
  double dVar9;
  _GXColor local_28 [5];
  
  J3DSys::reinitGX(&J3DGraphBase::j3dSys);
  gx::GXSetNumIndStages(0);
  gx::GXInitTexObj((GXTexObj *)&d_a_boomerang::texObj_4441,*(void **)(this + 0x10),0x10,4,GX_TF_I4,
                   GX_CLAMP,GX_CLAMP,false);
  dVar9 = (double)d_a_boomerang::_4431;
  gx::GXInitTexObjLOD(dVar9,dVar9,dVar9,&d_a_boomerang::texObj_4441,1,1,0,0,0);
  gx::GXLoadTexObj((GXTexObj *)&d_a_boomerang::texObj_4441,0);
  gx::GXCallDisplayList(&d_a_boomerang::l_matDL_4438,0x80);
  local_28[0] = d_a_boomerang::color0_4442;
  gf::GFSetTevColor(GX_TEVREG0,local_28);
  sVar8 = (short)(0xff / ((*(int *)(this + 0x14) >> 1) + 1));
  gf::GFSetVtxDescv(&d_a_boomerang::l_vtxDescList_4439);
  gf::GFSetVtxAttrFmtv(0,&d_a_boomerang::l_vtxAttrFmtList_4440);
  gf::GFLoadPosMtxImm(&J3DGraphBase::j3dSys.mCurViewMtx,0);
  write_volatile_1(DAT_cc008000,0x80);
  write_volatile_2(0xcc008000,(short)(*(int *)(this + 0x14) << 2) + 4);
  iVar5 = *(int *)(this + 0x14);
  iVar4 = iVar5 * 0xc;
  iVar3 = iVar5 + 1;
  sVar2 = sVar8;
  sVar7 = 0;
  if (-1 < iVar5) {
    do {
      sVar1 = sVar2;
      pdVar6 = this + iVar4;
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x24));
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x28));
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x2c));
      write_volatile_2(0xcc008000,sVar1);
      write_volatile_2(0xcc008000,0);
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x2f4));
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x2f8));
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x2fc));
      write_volatile_2(0xcc008000,sVar1);
      write_volatile_2(0xcc008000,0xff);
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x300));
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x304));
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x308));
      write_volatile_2(0xcc008000,sVar7);
      write_volatile_2(0xcc008000,0xff);
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x30));
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x34));
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x38));
      write_volatile_2(0xcc008000,sVar7);
      write_volatile_2(0xcc008000,0);
      iVar4 = iVar4 + -0xc;
      iVar3 = iVar3 + -1;
      sVar2 = sVar1 + sVar8;
      sVar7 = sVar1;
    } while (iVar3 != 0);
  }
  write_volatile_1(DAT_cc008000,0x80);
  write_volatile_2(0xcc008000,(short)(*(int *)(this + 0x14) << 2) + 4);
  iVar5 = *(int *)(this + 0x14);
  iVar4 = iVar5 * 0xc;
  iVar3 = iVar5 + 1;
  sVar2 = sVar8;
  sVar7 = 0;
  if (-1 < iVar5) {
    do {
      sVar1 = sVar2;
      pdVar6 = this + iVar4;
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x5c4));
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x5c8));
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x5cc));
      write_volatile_2(0xcc008000,sVar1);
      write_volatile_2(0xcc008000,0);
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x894));
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x898));
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x89c));
      write_volatile_2(0xcc008000,sVar1);
      write_volatile_2(0xcc008000,0xff);
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x8a0));
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x8a4));
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x8a8));
      write_volatile_2(0xcc008000,sVar7);
      write_volatile_2(0xcc008000,0xff);
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x5d0));
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x5d4));
      write_volatile_4(0xcc008000,*(undefined4 *)(pdVar6 + 0x5d8));
      write_volatile_2(0xcc008000,sVar7);
      write_volatile_2(0xcc008000,0);
      iVar4 = iVar4 + -0xc;
      iVar3 = iVar3 + -1;
      sVar2 = sVar1 + sVar8;
      sVar7 = sVar1;
    } while (iVar3 != 0);
  }
  _sOldVcdVatCmd = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall daBoomerang_sightPacket_c::draw(void) */

void __thiscall daBoomerang_sightPacket_c::draw(daBoomerang_sightPacket_c *this)

{
  _GXTexFmt *p_Var1;
  int iVar2;
  int iVar3;
  double dVar4;
  _GXColor local_48;
  _GXColor local_44;
  _GXColor local_40;
  _GXColor local_3c;
  GXTexObj GStack56;
  
  p_Var1 = *(_GXTexFmt **)(this + 0x108);
  gx::GXInitTexObj(&GStack56,*(void **)(this + 0x104),(uint)*(ushort *)(p_Var1 + 2),
                   (uint)*(ushort *)(p_Var1 + 4),*p_Var1,p_Var1[6],p_Var1[7],
                   SUB41(1 - (uint)p_Var1[0x18] >> 0x1f,0));
  dVar4 = (double)d_a_boomerang::_4431;
  gx::GXInitTexObjLOD(dVar4,dVar4,dVar4,&GStack56,1,1,0,0,0);
  gx::GXLoadTexObj(&GStack56,0);
  gx::GXCallDisplayList(&d_a_boomerang::l_sightMatDL,0x60);
  gf::GFSetVtxDescv(&d_a_boomerang::l_vtxDescList_4674);
  gf::GFSetVtxAttrFmtv(0,&d_a_boomerang::l_vtxAttrFmtList_4675);
  local_3c = d_a_boomerang::_4676;
  local_40 = d_a_boomerang::_4677;
  iVar2 = 0;
  iVar3 = 0;
  do {
    if ((*(uint *)(this + 0x100) & 1 << iVar2) != 0) {
      local_3c = (_GXColor)((uint)local_3c & 0xffffff00 | (uint)(byte)this[iVar2 + 0xf9]);
      local_40 = (_GXColor)((uint)local_40 & 0xffffff00 | (uint)(byte)this[iVar2 + 0xf9]);
      local_44 = local_3c;
      gf::GFSetTevColor(GX_TEVREG0,&local_44);
      local_48 = local_40;
      gf::GFSetTevColor(GX_TEVREG1,&local_48);
      gf::GFLoadPosMtxImm((MTX34 *)(this + iVar3 + 4),0);
      gx::GXCallDisplayList(&d_a_boomerang::l_sightDL,0x20);
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x30;
  } while (iVar2 < 5);
  return;
}


/* WARNING: Removing unreachable block (ram,0x800e16f0) */
/* WARNING: Removing unreachable block (ram,0x800e16e0) */
/* WARNING: Removing unreachable block (ram,0x800e16e8) */
/* WARNING: Removing unreachable block (ram,0x800e16f8) */
/* __thiscall daBoomerang_sightPacket_c::setSight(cXyz *,
                                                  int) */

void __thiscall
daBoomerang_sightPacket_c::setSight(daBoomerang_sightPacket_c *this,cXyz *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar5;
  undefined8 in_f30;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  cXyz local_88;
  double local_78;
  undefined4 local_70;
  uint uStack108;
  undefined4 local_68;
  uint uStack100;
  longlong local_60;
  longlong local_58;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  if (param_1 == (cXyz *)0x0) {
    *(uint *)(this + 0x100) = *(uint *)(this + 0x100) & ~(1 << param_2);
  }
  else {
    uVar2 = (uint)(byte)this[param_2 + 0xf4];
    if (uVar2 < 0xd) {
      local_78 = (double)CONCAT44(0x43300000,uVar2 ^ 0x80000000);
      dVar4 = (double)(d_a_boomerang::_4727 -
                      (float)(local_78 - d_a_boomerang::_4737) / d_a_boomerang::_4728);
      dVar7 = -dVar4;
    }
    else {
      local_78 = (double)CONCAT44(0x43300000,uVar2 - 0xd ^ 0x80000000);
      dVar4 = (double)((float)(local_78 - d_a_boomerang::_4737) / d_a_boomerang::_4728);
      dVar7 = dVar4;
    }
    iVar1 = (int)(d_a_boomerang::_4729 + (float)((double)d_a_boomerang::_4730 * dVar4));
    local_78 = (double)(longlong)iVar1;
    this[param_2 + 0xf9] = SUB41(iVar1,0);
    dVar6 = (double)(d_a_boomerang::_4731 *
                    (d_a_boomerang::_4732 + (float)((double)d_a_boomerang::_4733 * dVar4)));
    uStack108 = (uint)*(ushort *)(*(int *)(this + 0x108) + 2);
    local_70 = 0x43300000;
    dVar5 = (double)(float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000,uStack108) -
                                                   d_a_boomerang::_4739));
    uStack100 = (uint)*(ushort *)(*(int *)(this + 0x108) + 4);
    local_68 = 0x43300000;
    dVar4 = (double)(float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000,uStack100) -
                                                   d_a_boomerang::_4739));
    m_Do_lib::mDoLib_project(param_1,&local_88);
    mtx::PSMTXTrans((double)local_88.x,(double)local_88.y,(double)local_88.z,&mDoMtx_stack_c::now);
    mDoMtx_stack_c::scaleM((float)dVar5,(float)dVar4,(float)dVar6);
    local_60 = (longlong)(int)((double)d_a_boomerang::_4735 * dVar7);
    local_58 = (longlong)
               (int)(d_a_boomerang::_4734 *
                    JKernel::JMath::jmaSinTable
                    [(int)((int)((double)d_a_boomerang::_4735 * dVar7) & 0xffffU) >>
                     (JKernel::JMath::jmaSinShift & 0x3f)]);
    m_Do_mtx::mDoMtx_ZrotM
              (&mDoMtx_stack_c::now,
               (short)(int)(d_a_boomerang::_4734 *
                           JKernel::JMath::jmaSinTable
                           [(int)((int)((double)d_a_boomerang::_4735 * dVar7) & 0xffffU) >>
                            (JKernel::JMath::jmaSinShift & 0x3f)]));
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(this + param_2 * 0x30 + 4));
    *(uint *)(this + 0x100) = *(uint *)(this + 0x100) | 1 << param_2;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  __psq_l0(auStack56,uVar3);
  __psq_l1(auStack56,uVar3);
  return;
}


/* __thiscall daBoomerang_sightPacket_c::play(int) */

void __thiscall daBoomerang_sightPacket_c::play(daBoomerang_sightPacket_c *this,int param_1)

{
  daBoomerang_sightPacket_c *pdVar1;
  
  pdVar1 = this + 0xf4;
  if (param_1 < 1) {
    return;
  }
  do {
    *pdVar1 = (daBoomerang_sightPacket_c)((char)*pdVar1 + '\x01');
    if (*pdVar1 == (daBoomerang_sightPacket_c)0x1a) {
      *pdVar1 = (daBoomerang_sightPacket_c)0x0;
    }
    pdVar1 = pdVar1 + 1;
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daBoomerang_c::draw(void) */

undefined4 __thiscall daBoomerang_c::draw(daBoomerang_c *this)

{
  int iVar1;
  cM3dGPla *pFloorNrm;
  int iVar2;
  uint uVar3;
  
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0xc;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x10
  ;
  if ((*(char *)&this->field_0xf33 == '\0') && (*(char *)&this->field_0xf31 != '\0')) {
    *(undefined4 *)&this->field_0x394 = 0;
    uVar3 = (uint)*(byte *)&this->field_0xf32;
    iVar1 = uVar3 << 2;
    for (; (int)uVar3 < (int)(uint)*(byte *)&this->field_0xf31; uVar3 = uVar3 + 1) {
      iVar2 = *(int *)(&this->field_0xf18 + iVar1);
      if (iVar2 == 0) {
        daBoomerang_sightPacket_c::setSight
                  ((daBoomerang_sightPacket_c *)&this->field_0x294,(cXyz *)0x0,uVar3);
      }
      else {
        daBoomerang_sightPacket_c::setSight
                  ((daBoomerang_sightPacket_c *)&this->field_0x294,(cXyz *)(iVar2 + 0x260),uVar3);
      }
      iVar1 = iVar1 + 4;
    }
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x224,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x228,
                      (dDlst_base_c *)&this->field_0x294);
  }
  if (0 < *(int *)&this->field_0x3b4) {
    dDlst_list_c::entryZSortXluDrawList
              (&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
               d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu,
               (J3DPacket *)&this->field_0x3a0,&(this->parent).mCurrent.mPos);
  }
  iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->vtbl->
                    checkPlayerNoDraw)();
  if ((iVar1 == 0) || ((this->parent).parent.parent.mParameters != 0)) {
    dScnKy_env_light_c::settingTevStruct
              (&d_kankyo::g_env_light,Actor,&(this->parent).mCurrent.mPos,&(this->parent).mTevStr);
    dScnKy_env_light_c::setLightTevColorType
              (&d_kankyo::g_env_light,this->mpModel,&(this->parent).mTevStr);
    if (((this->parent).parent.parent.mParameters == 0) &&
       ((((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).field_0x2a0 & 0x800) != 0)
       ) {
      dMat_ice_c::updateDL(_mIce,this->mpModel,-1,(mDoExt_invisibleModel *)0x0);
    }
    else {
      m_Do_ext::mDoExt_modelUpdateDL(this->mpModel);
    }
    J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
    if (((d_a_boomerang::_4846 != *(float *)&this->field_0xf3c) &&
        ((this->parent).parent.parent.mParameters == 1)) &&
       (pFloorNrm = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                    (uint)*(ushort *)&this->field_0x1142,
                                    (uint)*(ushort *)&this->field_0x1140),
       pFloorNrm != (cM3dGPla *)0x0)) {
      dDlst_shadowControl_c::setSimple
                (&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mShadowControl,
                 &(this->parent).mCurrent.mPos,*(float *)&this->field_0xf3c,d_a_boomerang::_4730,
                 (cXyz *)pFloorNrm,0,d_a_boomerang::_4727,&dDlst_shadowControl_c::mSimpleTexObj);
    }
  }
  else {
    J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  }
  return 1;
}


namespace d_a_boomerang {

/* __stdcall daBoomerang_Draw(daBoomerang_c *) */

void daBoomerang_Draw(daBoomerang_c *param_1)

{
  ::daBoomerang_c::draw(param_1);
  return;
}

}

/* __thiscall daBoomerang_c::getFlyMax(void) */

double __thiscall daBoomerang_c::getFlyMax(daBoomerang_c *this)

{
  int iVar1;
  double dVar2;
  
  if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x10000U) == 0) {
    iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"GanonK");
    if (iVar1 == 0) {
      dVar2 = (double)d_a_boomerang::_4863;
    }
    else {
      dVar2 = (double)d_a_boomerang::_4864;
    }
  }
  else {
    dVar2 = (double)d_a_boomerang::_4863;
  }
  return dVar2;
}


/* __thiscall daBoomerang_c::rockLineCallback(fopAc_ac_c *) */

void __thiscall daBoomerang_c::rockLineCallback(daBoomerang_c *this,fopAc_ac_c *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if ((this->parent).parent.parent.mParameters == 0) {
    if (param_1 != (fopAc_ac_c *)0x0) {
      setLockActor(this,param_1,1);
    }
  }
  else {
    uVar3 = 0;
    iVar1 = 0;
    iVar4 = 5;
    do {
      iVar2 = (int)&(this->parent).parent.parent.mBsType + iVar1;
      if (*(fopAc_ac_c **)(iVar2 + 0xf18) == param_1) {
        *(undefined4 *)(iVar2 + 0xf04) = 0xffffffff;
        *(undefined4 *)(iVar2 + 0xf18) = 0;
        if (uVar3 == *(byte *)&this->field_0xf32) {
          *(undefined *)&this->field_0xf2e = 1;
          *(char *)&this->field_0xf32 = *(char *)&this->field_0xf32 + '\x01';
        }
      }
      uVar3 = uVar3 + 1;
      iVar1 = iVar1 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}


namespace d_a_boomerang {

/* __stdcall daBoomerang_rockLineCallback(fopAc_ac_c *,
                                          dCcD_GObjInf *,
                                          fopAc_ac_c *,
                                          dCcD_GObjInf *) */

void daBoomerang_rockLineCallback
               (daBoomerang_c *param_1,undefined4 param_2,fopAc_ac_c *param_3)

{
  ::daBoomerang_c::rockLineCallback(param_1,param_3);
  return;
}

}

/* __thiscall daBoomerang_c::setAimActor(fopAc_ac_c *) */

void __thiscall daBoomerang_c::setAimActor(daBoomerang_c *this,fopAc_ac_c *param_1)

{
  resetLockActor(this);
  *(undefined *)&this->field_0xf33 = 1;
  setLockActor(this,param_1,0);
  return;
}


/* __thiscall daBoomerang_c::setLockActor(fopAc_ac_c *,
                                          int) */

undefined4 __thiscall
daBoomerang_c::setLockActor(daBoomerang_c *this,fopAc_ac_c *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = (uint)*(byte *)&this->field_0xf31;
  if (uVar4 < 5) {
    if (param_1 == (fopAc_ac_c *)0x0) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = (param_1->parent).parent.mBsPcId;
    }
    iVar2 = 0;
    for (uVar5 = uVar4; uVar5 != 0; uVar5 = uVar5 - 1) {
      if (*(uint *)(&this->field_0xf04 + iVar2) == uVar3) {
        return 0;
      }
      iVar2 = iVar2 + 4;
    }
    *(uint *)(&this->field_0xf04 + uVar4 * 4) = uVar3;
    *(fopAc_ac_c **)(&this->field_0xf18 + (uint)*(byte *)&this->field_0xf31 * 4) = param_1;
    *(undefined *)(&this->field_0x388 + (uint)*(byte *)&this->field_0xf31) = 0;
    if (param_2 != 0) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,
                 *(ulong *)(&d_a_boomerang::se_flg_4897 + (uint)*(byte *)&this->field_0xf31 * 4),
                 (cXyz *)0x0,0,0,d_a_boomerang::_4727,d_a_boomerang::_4727,d_a_boomerang::_4921,
                 d_a_boomerang::_4921,0);
    }
    *(char *)&this->field_0xf31 = *(char *)&this->field_0xf31 + '\x01';
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* __thiscall daBoomerang_c::resetLockActor(void) */

void __thiscall daBoomerang_c::resetLockActor(daBoomerang_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = 5;
  do {
    iVar2 = (int)&(this->parent).parent.parent.mBsType + iVar1;
    *(undefined4 *)(iVar2 + 0xf04) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0xf18) = 0;
    iVar1 = iVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined *)&this->field_0xf31 = 0;
  *(undefined *)&this->field_0xf32 = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daBoomerang_c::setRoomInfo(void) */

void __thiscall daBoomerang_c::setRoomInfo(daBoomerang_c *this)

{
  byte bVar1;
  byte bVar2;
  double dVar3;
  
  *(float *)&this->field_0x1150 = (this->parent).mCurrent.mPos.x;
  *(float *)&this->field_0x1154 = (this->parent).mCurrent.mPos.y;
  *(float *)&this->field_0x1158 = (this->parent).mCurrent.mPos.z;
  dVar3 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                    (cBgS_GndChk *)&this->field_0x112c);
  bVar1 = dStage_roomControl_c::mStayNo;
  if ((double)d_a_boomerang::_4846 != dVar3) {
    bVar1 = dBgS::GetRoomId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                            (cBgS_PolyInfo *)&this->field_0x1140);
    bVar2 = dBgS::GetPolyColor(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                               (cBgS_PolyInfo *)&this->field_0x1140);
    (this->parent).mTevStr.mEnvrIdxOverride = bVar2;
  }
  (this->parent).mTevStr.mRoomNo = bVar1;
  *(byte *)&this->field_0xf6e = bVar1;
  (this->parent).mCurrent.mRoomNo = bVar1;
  return;
}


/* __thiscall daBoomerang_c::setKeepMatrix(void) */

void __thiscall daBoomerang_c::setKeepMatrix(daBoomerang_c *this)

{
  float fVar1;
  float fVar2;
  MTX34 *pMVar3;
  
  pMVar3 = (MTX34 *)(*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->vtbl->
                              getLeftHandMatrix)();
  mtx::PSMTXCopy(pMVar3,&mDoMtx_stack_c::now);
  mDoMtx_stack_c::transM(d_a_boomerang::_4961,d_a_boomerang::_4962,d_a_boomerang::_4963);
  m_Do_mtx::mDoMtx_XYZrotM(&mDoMtx_stack_c::now,0xffffc60c,0xfffffca9,0xffffd50d);
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,&this->mpModel->mBaseMtx);
  fVar2 = mDoMtx_stack_c::now.m[2][3];
  fVar1 = mDoMtx_stack_c::now.m[1][3];
  (this->parent).mCurrent.mPos.x = mDoMtx_stack_c::now.m[0][3];
  (this->parent).mCurrent.mPos.y = fVar1;
  (this->parent).mCurrent.mPos.z = fVar2;
  return;
}


/* __thiscall daBoomerang_c::setAimPos(void) */

void __thiscall daBoomerang_c::setAimPos(daBoomerang_c *this)

{
  int iVar1;
  uint uVar2;
  uint local_18;
  uint local_14;
  undefined4 local_10;
  
  if (*(char *)&this->field_0xf2c == '\0') {
    uVar2 = (uint)*(byte *)&this->field_0xf32;
    iVar1 = uVar2 << 2;
    for (; (int)uVar2 < (int)(uint)*(byte *)&this->field_0xf31; uVar2 = uVar2 + 1) {
      if (*(int *)(&this->field_0xf18 + iVar1) != 0) {
        iVar1 = *(int *)(&this->field_0xf18 + iVar1);
        *(undefined4 *)&this->field_0xf40 = *(undefined4 *)(iVar1 + 0x260);
        *(undefined4 *)&this->field_0xf44 = *(undefined4 *)(iVar1 + 0x264);
        *(undefined4 *)&this->field_0xf48 = *(undefined4 *)(iVar1 + 0x268);
        return;
      }
      *(char *)&this->field_0xf32 = *(char *)&this->field_0xf32 + '\x01';
      iVar1 = iVar1 + 4;
    }
  }
  else {
    daPy_lk_c::getBoomerangCatchPos((daPy_lk_c *)&local_18);
    *(uint *)&this->field_0xf40 = local_18;
    *(uint *)&this->field_0xf44 = local_14;
    *(undefined4 *)&this->field_0xf48 = local_10;
  }
  return;
}


/* __thiscall daBoomerang_c::checkBgHit(cXyz *,
                                        cXyz *) */

void __thiscall daBoomerang_c::checkBgHit(daBoomerang_c *this,cXyz *param_1,cXyz *param_2)

{
  char cVar2;
  ulong uVar1;
  sbyte sVar3;
  
  ::dBgS_LinChk::Set((dBgS_LinChk *)&this->field_0x10c0,param_1,param_2,&this->parent);
  cVar2 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                          (cBgS_LinChk *)&this->field_0x10c0);
  if (cVar2 != '\0') {
    (this->parent).mCurrent.mPos.x = *(float *)&this->field_0x10f0;
    (this->parent).mCurrent.mPos.y = *(float *)&this->field_0x10f4;
    (this->parent).mCurrent.mPos.z = *(float *)&this->field_0x10f8;
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,1,0xc,
                       &(this->parent).mCurrent.mPos,(csXyz *)0x0,(cXyz *)0x0,0xff,
                       (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
    *(undefined *)&this->field_0xf2c = 1;
    (this->parent).mCurrent.mRot.y = (this->parent).mCurrent.mRot.y + -0x8000;
    (this->parent).mCollisionRot.y = (this->parent).mCurrent.mRot.y;
    resetLockActor(this);
    uVar1 = dBgS::GetMtrlSndId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                               (cBgS_PolyInfo *)&this->field_0x10d4);
    sVar3 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x2833,&(this->parent).mEyePos,uVar1,sVar3,
               d_a_boomerang::_4727,d_a_boomerang::_4727,d_a_boomerang::_4921,d_a_boomerang::_4921,0
              );
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall daBoomerang_c::procWait(void) */

undefined4 __thiscall daBoomerang_c::procWait(daBoomerang_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  bool bVar8;
  undefined4 uVar9;
  daPy_lk_c *pdVar10;
  int iVar11;
  int iVar12;
  camera_class *pcVar13;
  double dVar14;
  double dVar15;
  float fVar16;
  cXyz local_64;
  node_class *local_58;
  undefined *local_54;
  node_class *local_50;
  cXyz local_4c;
  node_class *local_40;
  undefined *local_3c;
  node_class *local_38;
  create_request *local_34;
  float local_30;
  layer_class *local_2c;
  cXyz local_28;
  node_class *local_1c;
  create_request *local_18;
  create_request *local_14;
  
  pdVar10 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor;
  (this->parent).mVelocityFwd = d_a_boomerang::_4431;
  setKeepMatrix(this);
  if (0 < *(int *)&this->field_0x3b4) {
    *(int *)&this->field_0x3b4 = *(int *)&this->field_0x3b4 + -5;
  }
  if ((this->parent).parent.parent.mParameters == 1) {
    (this->parent).mVelocityFwd = d_a_boomerang::_5144;
    dCcD_GObjInf::ResetAtHit((dCcD_GObjInf *)&this->field_0xf88);
    *(uint *)&this->field_0xf88 = *(uint *)&this->field_0xf88 & 0xffffffef;
    *(undefined *)&this->field_0xf2c = 0;
    *(undefined *)&this->field_0xf2d = 1;
    *(undefined *)&this->field_0xf2e = 0;
    *(undefined *)&this->field_0xf32 = 0;
    setAimPos(this);
    if (*(char *)&this->field_0xf32 == *(char *)&this->field_0xf31) {
      resetLockActor(this);
      sVar5 = (pdVar10->parent).parent.mCollisionRot.y;
      sVar6 = *(short *)&(pdVar10->parent).field_0x2b6;
      sVar7 = *(short *)&(pdVar10->parent).field_0x2b4;
      dVar15 = (double)getFlyMax(this);
      fVar16 = (this->parent).mCurrent.mPos.z;
      iVar11 = (int)((int)(short)(sVar5 + sVar6) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
      fVar2 = JKernel::JMath::jmaCosTable[iVar11];
      iVar12 = (int)((int)sVar7 & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
      fVar3 = JKernel::JMath::jmaCosTable[iVar12];
      fVar1 = (this->parent).mCurrent.mPos.y;
      fVar4 = JKernel::JMath::jmaSinTable[iVar12];
      *(float *)&this->field_0xf40 =
           (this->parent).mCurrent.mPos.x +
           (float)(dVar15 * (double)JKernel::JMath::jmaSinTable[iVar11]) * fVar3;
      *(float *)&this->field_0xf44 = fVar1 - (float)(dVar15 * (double)fVar4);
      *(float *)&this->field_0xf48 = fVar16 + (float)(dVar15 * (double)fVar2) * fVar3;
    }
    *(undefined2 *)&this->field_0xf3a = 0;
    ::cXyz::operator__(&local_4c,(cXyz *)&this->field_0xf40,&(this->parent).mCurrent.mPos);
    local_1c = (node_class *)local_4c.x;
    local_18 = (create_request *)local_4c.y;
    local_14 = (create_request *)local_4c.z;
    local_64.x = local_4c.x;
    local_64.y = d_a_boomerang::_4431;
    local_64.z = local_4c.z;
    fVar16 = mtx::PSVECSquareMag(&local_64);
    dVar15 = (double)fVar16;
    if ((double)d_a_boomerang::_4431 < dVar15) {
      dVar14 = 1.0 / SQRT(dVar15);
      dVar14 = d_a_boomerang::_5145 * dVar14 * (d_a_boomerang::_5146 - dVar15 * dVar14 * dVar14);
      dVar14 = d_a_boomerang::_5145 * dVar14 * (d_a_boomerang::_5146 - dVar15 * dVar14 * dVar14);
      dVar15 = (double)(float)(dVar15 * d_a_boomerang::_5145 * dVar14 *
                                        (d_a_boomerang::_5146 - dVar15 * dVar14 * dVar14));
    }
    iVar11 = SComponent::cM_atan2s(-(float)local_18,(float)dVar15);
    (this->parent).mCurrent.mRot.x = (short)iVar11;
    if (*(char *)&this->field_0xf31 == '\0') {
      iVar11 = SComponent::cM_atan2s((float)local_1c,(float)local_14);
      (this->parent).mCurrent.mRot.y = (short)iVar11 + 0x3000;
      if (*(char *)&this->field_0xf33 == '\0') {
        *(undefined *)&this->field_0xf36 = 1;
      }
      else {
        *(undefined *)&this->field_0xf36 = 0;
      }
    }
    else {
      iVar11 = SComponent::cM_atan2s((float)local_1c,(float)local_14);
      (this->parent).mCurrent.mRot.y = (short)iVar11;
      *(undefined *)&this->field_0xf36 = 0;
    }
    (this->parent).mCollisionRot.x = (this->parent).mCurrent.mRot.x;
    (this->parent).mCollisionRot.y = (this->parent).mCurrent.mRot.y;
    (this->parent).mCollisionRot.z = 0x2000;
    *(undefined2 *)&this->field_0xf38 = 0x2000;
    uVar9 = DAT_8038a8f4;
    *(undefined4 *)&this->field_0x1180 = d_a_boomerang::_5029;
    *(undefined4 *)&this->field_0x1184 = uVar9;
    *(undefined **)&this->field_0x1188 = PTR_procMove_8038a8f8;
    *(undefined *)&this->field_0xf34 = 0;
    daBoomerang_blur_c::initBlur
              ((daBoomerang_blur_c *)&this->field_0x3a0,(float *)&this->mpModel->mBaseMtx,
               *(short *)&this->field_0xf3a);
    local_28.z = (pdVar10->parent).parent.mCurrent.mPos.z;
    local_28.y = d_a_boomerang::_5144 + (pdVar10->parent).parent.mCurrent.mPos.y;
    local_28.x = (pdVar10->parent).parent.mCurrent.mPos.x;
    checkBgHit(this,&local_28,&(this->parent).mCurrent.mPos);
    procMove(this);
  }
  else {
    iVar11 = d_camera::dCam_getBody();
    if (*(int *)(iVar11 + 0x13c) == 0xb) {
      bVar8 = false;
      if (((pdVar10->mCurProc == 0x80) || (pdVar10->mCurProc == 0x8b)) &&
         ((pdVar10->mSightPacket).field_0x4 != 0)) {
        bVar8 = true;
      }
      if (bVar8) {
        pcVar13 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo
                  [(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCamera].mpCamera;
        local_34 = (create_request *)(pcVar13->mEyePos).x;
        local_30 = (pcVar13->mEyePos).y;
        local_2c = (layer_class *)(pcVar13->mEyePos).z;
        daPy_lk_c::getLineTopPos((daPy_lk_c *)&local_58);
        local_40 = local_58;
        local_3c = local_54;
        local_38 = local_50;
        *(uint *)&this->field_0xf88 = *(uint *)&this->field_0xf88 | 0x10;
        *(create_request **)&this->field_0x10a0 = local_34;
        *(float *)&this->field_0x10a4 = local_30;
        *(layer_class **)&this->field_0x10a8 = local_2c;
        *(node_class **)&this->field_0x10ac = local_58;
        *(undefined **)&this->field_0x10b0 = local_54;
        *(node_class **)&this->field_0x10b4 = local_50;
        *(float *)&this->field_0x10bc = d_a_boomerang::_5147;
        mtx::PSVECSubtract((cXyz *)&this->field_0x10ac,(cXyz *)&this->field_0x10a0,
                           (cXyz *)&this->field_0x1004);
        *(code **)&this->field_0xfe0 = d_a_boomerang::daBoomerang_rockLineCallback;
        cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,
                  (cCcD_Obj *)&this->field_0xf88);
      }
    }
    else {
      resetLockActor(this);
    }
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x800e2ad4) */
/* __thiscall daBoomerang_c::procMove(void) */

undefined4 __thiscall daBoomerang_c::procMove(daBoomerang_c *this)

{
  float fVar1;
  undefined4 uVar2;
  daPy_lk_c *this_00;
  short sVar3;
  sbyte sVar6;
  int iVar4;
  fopAc_ac_c *pfVar5;
  undefined uVar7;
  short sVar8;
  undefined4 uVar9;
  double dVar10;
  undefined8 in_f31;
  double dVar11;
  float fVar12;
  cXyz local_70;
  cXyz local_64;
  cXyz local_58;
  float local_4c;
  float local_48;
  float local_44;
  cXyz local_40;
  longlong local_30;
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (d_a_boomerang::init_5157 == '\0') {
    Runtime.PPCEABI.H::__register_global_object
              (&d_a_boomerang::at_offset_5155,::cXyz::_cXyz,&d_a_boomerang::_5156);
    d_a_boomerang::init_5157 = '\x01';
  }
  this_00 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor;
  if (*(char *)&this->field_0xf2f == '\0') {
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
      sVar3 = *(short *)&this->field_0xf3a;
      *(short *)&this->field_0xf3a = sVar3 + -0x1f00;
      if ((-1 < sVar3) && (*(short *)&this->field_0xf3a < 0)) {
        sVar6 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x2814,&(this->parent).mEyePos,0,sVar6,
                   d_a_boomerang::_4727,d_a_boomerang::_4727,d_a_boomerang::_4921,
                   d_a_boomerang::_4921,0);
      }
      setAimPos(this);
      ::cXyz::operator__(&local_58,(cXyz *)&this->field_0xf40,&(this->parent).mCurrent.mPos);
      local_40.x = local_58.x;
      local_40.y = local_58.y;
      local_40.z = local_58.z;
      fVar12 = mtx::PSVECSquareMag(&local_40);
      dVar11 = (double)fVar12;
      if ((double)d_a_boomerang::_4431 < dVar11) {
        dVar10 = 1.0 / SQRT(dVar11);
        dVar10 = d_a_boomerang::_5145 * dVar10 * (d_a_boomerang::_5146 - dVar11 * dVar10 * dVar10);
        dVar10 = d_a_boomerang::_5145 * dVar10 * (d_a_boomerang::_5146 - dVar11 * dVar10 * dVar10);
        dVar11 = (double)(float)(dVar11 * d_a_boomerang::_5145 * dVar10 *
                                          (d_a_boomerang::_5146 - dVar11 * dVar10 * dVar10));
      }
      if (dVar11 <= (double)d_a_boomerang::_5337) {
        local_4c = local_40.x;
        local_48 = local_40.y;
        local_44 = local_40.z;
      }
      else {
        ::cXyz::operator__(&local_64,(float)dVar11);
        local_4c = local_64.x;
        local_48 = local_64.y;
        local_44 = local_64.z;
      }
      iVar4 = SComponent::cM_atan2s(local_4c,local_44);
      sVar3 = (this->parent).mCurrent.mRot.y;
      sVar8 = (short)iVar4;
      if (*(char *)&this->field_0xf2e != '\0') {
        *(undefined *)&this->field_0xf2e = 0;
        if ((short)(sVar8 - (this->parent).mCurrent.mRot.y) < 1) {
          (this->parent).mCurrent.mRot.y = sVar8 + 0x3000;
        }
        else {
          (this->parent).mCurrent.mRot.y = sVar8 + -0x3000;
        }
        sVar3 = (this->parent).mCurrent.mRot.y;
      }
      sVar3 = sVar8 - sVar3;
      if (*(char *)&this->field_0xf2c == '\0') {
        if ((dVar11 < (double)(this->parent).mVelocityFwd) ||
           ((iVar4 = dCcD_GObjInf::ChkAtHit((dCcD_GObjInf *)&this->field_0xf88), iVar4 != 0 &&
            (pfVar5 = dCcD_GAtTgCoCommonBase::GetAc((dCcD_GAtTgCoCommonBase *)&this->field_0xfd8),
            pfVar5 == *(fopAc_ac_c **)(&this->field_0xf18 + (uint)*(byte *)&this->field_0xf32 * 4)))
           )) {
          *(undefined *)&this->field_0xf2e = 1;
          *(undefined4 *)(&this->field_0xf18 + (uint)*(byte *)&this->field_0xf32 * 4) = 0;
          *(undefined4 *)(&this->field_0xf04 + (uint)*(byte *)&this->field_0xf32 * 4) = 0xffffffff;
          *(char *)&this->field_0xf32 = *(char *)&this->field_0xf32 + '\x01';
          *(undefined *)&this->field_0xf36 = 0;
        }
      }
      else {
        if (dVar11 < (double)(d_a_boomerang::_5338 * (this->parent).mVelocityFwd)) {
          iVar4 = daPy_lk_c::returnBoomerang(this_00);
          if (iVar4 == 0) {
            *(undefined *)&this->field_0xf2f = 1;
          }
          else {
            (this->parent).parent.parent.mParameters = 0;
            *(undefined *)&this->field_0xf33 = 0;
            uVar2 = DAT_8038a900;
            *(undefined4 *)&this->field_0x1180 = d_a_boomerang::_5180;
            *(undefined4 *)&this->field_0x1184 = uVar2;
            *(undefined **)&this->field_0x1188 = PTR_procWait_8038a904;
            *(undefined4 *)&this->field_0xfe0 = 0;
          }
        }
      }
      if ((*(char *)&this->field_0xf2c == '\0') &&
         ((*(char *)&this->field_0xf34 != '\0' ||
          (((*(char *)&this->field_0xf36 == '\0' &&
            (*(byte *)&this->field_0xf31 <= *(byte *)&this->field_0xf32)) ||
           ((*(uint *)&this->field_0xfdc & 1) != 0)))))) {
        *(undefined *)&this->field_0xf2e = 1;
        *(undefined *)&this->field_0xf2c = 1;
        resetLockActor(this);
        *(undefined *)&this->field_0xf34 = 0;
        *(undefined *)&this->field_0xf36 = 0;
      }
      if (*(char *)&this->field_0xf2e == '\0') {
        if (*(char *)&this->field_0xf33 == '\0') {
          fVar12 = d_a_boomerang::_5339 -
                   (float)((double)d_a_boomerang::_5338 * dVar11) / (this->parent).mVelocityFwd;
          fVar1 = d_a_boomerang::_4431;
          if ((d_a_boomerang::_4431 <= fVar12) && (fVar1 = fVar12, d_a_boomerang::_5340 < fVar12)) {
            fVar1 = d_a_boomerang::_5339 + d_a_boomerang::_5341 * (fVar12 - d_a_boomerang::_5340);
          }
          iVar4 = (int)(d_a_boomerang::_5342 + d_a_boomerang::_5343 * fVar1);
          local_30 = (longlong)iVar4;
          sVar8 = (short)iVar4;
        }
        else {
          sVar8 = 0x4000;
        }
        if (((int)sVar3 <= (int)sVar8) && (iVar4 = -(int)sVar8, sVar8 = sVar3, sVar3 < iVar4)) {
          sVar8 = (short)iVar4;
        }
        sVar3 = sVar8;
        (this->parent).mCurrent.mRot.y = (this->parent).mCurrent.mRot.y + sVar3;
      }
      else {
        (this->parent).mCurrent.mRot.y = sVar8;
      }
      local_70.x = local_4c;
      local_70.y = d_a_boomerang::_4431;
      local_70.z = local_44;
      fVar12 = mtx::PSVECSquareMag(&local_70);
      dVar11 = (double)fVar12;
      if ((double)d_a_boomerang::_4431 < dVar11) {
        dVar10 = 1.0 / SQRT(dVar11);
        dVar10 = d_a_boomerang::_5145 * dVar10 * (d_a_boomerang::_5146 - dVar11 * dVar10 * dVar10);
        dVar10 = d_a_boomerang::_5145 * dVar10 * (d_a_boomerang::_5146 - dVar11 * dVar10 * dVar10);
        dVar11 = (double)(float)(dVar11 * d_a_boomerang::_5145 * dVar10 *
                                          (d_a_boomerang::_5146 - dVar11 * dVar10 * dVar10));
      }
      iVar4 = SComponent::cM_atan2s(-local_48,(float)dVar11);
      (this->parent).mCurrent.mRot.x = (short)iVar4;
      (this->parent).mCurrent.mPos.x =
           (this->parent).mCurrent.mPos.x +
           (this->parent).mVelocityFwd *
           JKernel::JMath::jmaCosTable
           [(int)((int)(this->parent).mCurrent.mRot.x & 0xffffU) >>
            (JKernel::JMath::jmaSinShift & 0x3f)] *
           JKernel::JMath::jmaSinTable
           [(int)((int)(this->parent).mCurrent.mRot.y & 0xffffU) >>
            (JKernel::JMath::jmaSinShift & 0x3f)];
      (this->parent).mCurrent.mPos.y =
           (this->parent).mCurrent.mPos.y -
           (this->parent).mVelocityFwd *
           JKernel::JMath::jmaSinTable
           [(int)((int)(this->parent).mCurrent.mRot.x & 0xffffU) >>
            (JKernel::JMath::jmaSinShift & 0x3f)];
      (this->parent).mCurrent.mPos.z =
           (this->parent).mCurrent.mPos.z +
           (this->parent).mVelocityFwd *
           JKernel::JMath::jmaCosTable
           [(int)((int)(this->parent).mCurrent.mRot.x & 0xffffU) >>
            (JKernel::JMath::jmaSinShift & 0x3f)] *
           JKernel::JMath::jmaCosTable
           [(int)((int)(this->parent).mCurrent.mRot.y & 0xffffU) >>
            (JKernel::JMath::jmaSinShift & 0x3f)];
      (this->parent).mCollisionRot.y = (this->parent).mCurrent.mRot.y;
      (this->parent).mCollisionRot.x = (this->parent).mCurrent.mRot.x;
      if (*(char *)&this->field_0xf2c == '\0') {
        checkBgHit(this,&(this->parent).mNext.mPos,&(this->parent).mCurrent.mPos);
      }
      sVar3 = -(short)((int)sVar3 << 1);
      if (sVar3 < 0x101) {
        if (sVar3 < -0x100) {
          sVar3 = -0x2000;
        }
        else {
          sVar3 = *(short *)&this->field_0xf38;
        }
      }
      else {
        sVar3 = 0x2000;
      }
      *(short *)&this->field_0xf38 = sVar3;
      SComponent::cLib_addCalcAngleS(&(this->parent).mCollisionRot.z,sVar3,0x10,0x1000,0x10);
    }
    mtx::PSMTXTrans((double)(this->parent).mCurrent.mPos.x,(double)(this->parent).mCurrent.mPos.y,
                    (double)(this->parent).mCurrent.mPos.z,&mDoMtx_stack_c::now);
    iVar4 = (int)(this->parent).mCollisionRot.z;
    m_Do_mtx::mDoMtx_ZXYrotM
              (&mDoMtx_stack_c::now,(int)(this->parent).mCollisionRot.x,
               (int)(this->parent).mCollisionRot.y);
    m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,*(short *)&this->field_0xf3a);
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,&this->mpModel->mBaseMtx);
    *(float *)&this->field_0x10a0 = (this->parent).mNext.mPos.x;
    *(float *)&this->field_0x10a4 = (this->parent).mNext.mPos.y;
    *(float *)&this->field_0x10a8 = (this->parent).mNext.mPos.z;
    *(float *)&this->field_0x10ac = (this->parent).mCurrent.mPos.x;
    *(float *)&this->field_0x10b0 = (this->parent).mCurrent.mPos.y;
    *(float *)&this->field_0x10b4 = (this->parent).mCurrent.mPos.z;
    *(float *)&this->field_0x10bc = d_a_boomerang::_4730;
    mtx::PSVECSubtract((cXyz *)&this->field_0x10ac,(cXyz *)&this->field_0x10a0,
                       (cXyz *)&this->field_0x1004);
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
      daBoomerang_blur_c::copyBlur
                ((daBoomerang_blur_c *)&this->field_0x3a0,(float *)&mDoMtx_stack_c::now,
                 *(short *)&this->field_0xf3a);
      cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)&this->field_0xf88
               );
      dCcMassS_Mng::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng,
                        (cCcD_Obj *)&this->field_0xf88,1);
    }
    else {
      daBoomerang_blur_c::copyBlur
                ((daBoomerang_blur_c *)&this->field_0x3a0,(float *)&mDoMtx_stack_c::now,0);
      dCcD_GObjInf::ResetAtHit((dCcD_GObjInf *)&this->field_0xf88);
    }
    uVar7 = daPy_lk_c::setItemWaterEffect
                      ((daPy_lk_c *)this,(fopAc_ac_c *)(uint)*(byte *)&this->field_0xf35,1,iVar4);
    *(undefined *)&this->field_0xf35 = uVar7;
  }
  else {
    f_op_actor_mng::fopAcM_delete((base_process_class *)this);
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall daBoomerang_c::execute(void) */

undefined4 __thiscall daBoomerang_c::execute(daBoomerang_c *this)

{
  fopAc_ac_c *pfVar1;
  bool bVar2;
  undefined4 *in_r4;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_28 [5];
  
  iVar5 = 0;
  for (iVar3 = 0; iVar3 < (int)(uint)*(byte *)&this->field_0xf31; iVar3 = iVar3 + 1) {
    iVar4 = (int)&(this->parent).parent.parent.mBsType + iVar5;
    local_28[0] = *(undefined4 *)(iVar4 + 0xf04);
    in_r4 = local_28;
    pfVar1 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,in_r4);
    *(fopAc_ac_c **)(iVar4 + 0xf18) = pfVar1;
    iVar5 = iVar5 + 4;
  }
  bVar2 = Runtime.PPCEABI.H::__ptmf_test((PTMF *)&this->field_0x1180);
  if (bVar2 != false) {
    Runtime.PPCEABI.H::__ptmf_scall((PTMF *)&this->field_0x1180,this,in_r4);
  }
  (this->parent).mAttentionPos.x = (this->parent).mCurrent.mPos.x;
  (this->parent).mAttentionPos.y = (this->parent).mCurrent.mPos.y;
  (this->parent).mAttentionPos.z = (this->parent).mCurrent.mPos.z;
  (this->parent).mEyePos.x = (this->parent).mCurrent.mPos.x;
  (this->parent).mEyePos.y = (this->parent).mCurrent.mPos.y;
  (this->parent).mEyePos.z = (this->parent).mCurrent.mPos.z;
  setRoomInfo(this);
  daBoomerang_sightPacket_c::play
            ((daBoomerang_sightPacket_c *)&this->field_0x294,(uint)*(byte *)&this->field_0xf31);
  return 1;
}


namespace d_a_boomerang {

/* __stdcall daBoomerang_Execute(daBoomerang_c *) */

void daBoomerang_Execute(daBoomerang_c *param_1)

{
  ::daBoomerang_c::execute(param_1);
  return;
}


/* __stdcall daBoomerang_IsDelete(daBoomerang_c *) */

undefined4 daBoomerang_IsDelete(void)

{
  return 1;
}


/* __stdcall daBoomerang_Delete(daBoomerang_c *) */

undefined4 daBoomerang_Delete(void)

{
  return 1;
}

}

/* __thiscall daBoomerang_c::createHeap(void) */

bool __thiscall daBoomerang_c::createHeap(daBoomerang_c *this)

{
  J3DModelData *pModel;
  ulong uVar1;
  J3DModel *pJVar2;
  
  pModel = (J3DModelData *)
           dRes_control_c::getRes
                     ("Link",0x14,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pModel == (J3DModelData *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_a_boomerang.cpp",0x60a,"modelData != 0");
    m_Do_printf::OSPanic("d_a_boomerang.cpp",0x60a,&DAT_8035bb69);
  }
  pJVar2 = m_Do_ext::mDoExt_J3DModel__create(pModel,0x80000,0x37220202);
  this->mpModel = pJVar2;
  return this->mpModel != (J3DModel *)0x0;
}


namespace d_a_boomerang {

/* __stdcall daBoomerang_createHeap(fopAc_ac_c *) */

void daBoomerang_createHeap(daBoomerang_c *param_1)

{
  ::daBoomerang_c::createHeap(param_1);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daBoomerang_c::create(void) */

undefined4 __thiscall daBoomerang_c::create(daBoomerang_c *this)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  ulong uVar5;
  int iVar6;
  
  if (((this->parent).mCondition & Constructed) == 0) {
    if (this != (daBoomerang_c *)0x0) {
      daBoomerang_c(this);
    }
    (this->parent).mCondition = (this->parent).mCondition | Constructed;
  }
  uVar1 = f_op_actor_mng::fopAcM_entrySolidHeap
                    (&this->parent,d_a_boomerang::daBoomerang_createHeap,0xd40);
  if ((uVar1 & 0xff) == 0) {
    uVar2 = 5;
  }
  else {
    setKeepMatrix(this);
    (this->parent).mpCullMtx = &this->mpModel->mBaseMtx;
    uVar2 = DAT_8038a958;
    *(undefined4 *)&this->field_0x1180 = d_a_boomerang::_5409;
    *(undefined4 *)&this->field_0x1184 = uVar2;
    *(undefined **)&this->field_0x1188 = PTR_procWait_8038a95c;
    ::dCcD_Stts::Init((dCcD_Stts *)&this->field_0xf4c,0x3c,0xff,&this->parent);
    ::dCcD_Cps::Set((dCcD_Cps *)&this->field_0xf88,(dCcD_SrcCps *)&d_a_boomerang::l_at_cps_src);
    *(int *)&this->field_0xfcc = &this->field_0xf4c;
    *(code **)&this->field_0xfe0 = d_a_boomerang::daBoomerang_rockLineCallback;
    *(uint *)&this->field_0x110c = *(uint *)&this->field_0x110c & 0xdfffffff;
    iVar3 = 0;
    iVar6 = 5;
    do {
      *(undefined4 *)(&this->field_0xf04 + iVar3) = 0xffffffff;
      iVar3 = iVar3 + 4;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    pvVar4 = dRes_control_c::getRes
                       ("Link",0x70,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pvVar4 == (void *)0x0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_a_boomerang.cpp",0x65d,"tmp_img != 0");
      m_Do_printf::OSPanic("d_a_boomerang.cpp",0x65d,&DAT_8035bb69);
    }
    *(int *)&this->field_0x3b0 = (int)pvVar4 + *(int *)((int)pvVar4 + 0x1c);
    pvVar4 = dRes_control_c::getRes
                       ("Link",0x72,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pvVar4 == (void *)0x0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_a_boomerang.cpp",0x665,"tmp_img != 0");
      m_Do_printf::OSPanic("d_a_boomerang.cpp",0x665,&DAT_8035bb69);
    }
    *(int *)&this->field_0x398 = (int)pvVar4 + *(int *)((int)pvVar4 + 0x1c);
    *(void **)&this->field_0x39c = pvVar4;
    setRoomInfo(this);
    (this->parent).mpGrabbedShadowModel = this->mpModel;
    uVar2 = 4;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daBoomerang_c::daBoomerang_c(void) */

void __thiscall daBoomerang_c::daBoomerang_c(daBoomerang_c *this)

{
  int iVar1;
  
  fopAc_ac_c::fopAc_ac_c(&this->parent);
  *(undefined ***)&this->field_0x294 = &dDlst_base_c::__vt;
  *(undefined1 **)&this->field_0x294 = &daBoomerang_sightPacket_c::__vt;
  *(undefined ***)&this->field_0x3a0 = &J3DPacket::__vt;
  *(undefined4 *)&this->field_0x3a4 = 0;
  *(undefined4 *)&this->field_0x3a8 = 0;
  *(undefined4 *)&this->field_0x3ac = 0;
  *(undefined1 **)&this->field_0x3a0 = &daBoomerang_blur_c::__vt;
  Runtime.PPCEABI.H::__construct_array
            ((void *)&this->field_0x3c4,::cXyz::cXyz,::cXyz::_cXyz,0xc,0x3c);
  Runtime.PPCEABI.H::__construct_array
            ((void *)&this->field_0x694,::cXyz::cXyz,::cXyz::_cXyz,0xc,0x3c);
  Runtime.PPCEABI.H::__construct_array
            ((void *)&this->field_0x964,::cXyz::cXyz,::cXyz::_cXyz,0xc,0x3c);
  Runtime.PPCEABI.H::__construct_array
            ((void *)&this->field_0xc34,::cXyz::cXyz,::cXyz::_cXyz,0xc,0x3c);
  *(cCcD_Stts__vtbl **)&this->field_0xf64 = &cCcD_Stts::__vt;
  ::dCcD_GStts::dCcD_GStts((dCcD_GStts *)&this->field_0xf68);
  *(dCcD_Stts__vtbl **)&this->field_0xf64 = &::dCcD_Stts::__vt;
  *(undefined4 *)&this->field_0xf68 = 0x8037ec40;
  dCcD_GObjInf::dCcD_GObjInf((dCcD_GObjInf *)&this->field_0xf88);
  *(undefined ***)&this->field_0x109c = &::cCcD_ShapeAttr::__vt;
  *(cM3dGAab__vtbl **)&this->field_0x1098 = &::cM3dGAab::__vt;
  *(undefined ***)&this->field_0x10b8 = &::cM3dGLin::__vt;
  *(undefined ***)&this->field_0x10b8 = &::cM3dGCps::__vt;
  *(cCcD_ShapeAttr__vtbl **)&this->field_0x109c = &::cCcD_CpsAttr::__vt;
  *(undefined **)&this->field_0x10b8 = &DAT_8039520c;
  *(undefined1 **)&this->field_0xfc4 = &::dCcD_Cps::__vt;
  *(undefined **)&this->field_0x109c = &DAT_80389a8c;
  *(undefined **)&this->field_0x10b8 = &DAT_80389ae0;
  *(cBgS_Chk__vtbl **)&this->field_0x10d0 = &cBgS_Chk::__vt;
  *(undefined4 *)&this->field_0x10c0 = 0;
  *(undefined4 *)&this->field_0x10c4 = 0;
  *(undefined *)&this->field_0x10cc = 1;
  *(undefined ***)&this->field_0x10e0 = &::cBgS_PolyInfo::__vt;
  *(undefined2 *)&this->field_0x10d4 = 0xffff;
  *(undefined2 *)&this->field_0x10d6 = 0x100;
  *(undefined4 *)&this->field_0x10d8 = 0;
  *(undefined4 *)&this->field_0x10dc = 0xffffffff;
  *(undefined ***)&this->field_0x10d0 = &::cBgS_LinChk::__vt;
  *(undefined ***)&this->field_0x10e0 = &PTR_80371fbc;
  *(undefined ***)&this->field_0x10fc = &::cM3dGLin::__vt;
  ::cBgS_LinChk::ct((cBgS_LinChk *)&this->field_0x10c0);
  *(undefined ***)&this->field_0x1118 = &::cBgS_PolyPassChk::__vt;
  *(undefined ***)&this->field_0x1118 = &::dBgS_PolyPassChk::__vt;
  *(undefined *)&this->field_0x111c = 0;
  *(undefined *)&this->field_0x111d = 0;
  *(undefined *)&this->field_0x111e = 0;
  *(undefined *)&this->field_0x111f = 0;
  *(undefined *)&this->field_0x1120 = 0;
  *(undefined *)&this->field_0x1121 = 0;
  *(undefined *)&this->field_0x1122 = 0;
  *(undefined ***)&this->field_0x1124 = &::cBgS_GrpPassChk::__vt;
  *(undefined ***)&this->field_0x1124 = &::dBgS_GrpPassChk::__vt;
  *(undefined4 *)&this->field_0x1128 = 1;
  *(undefined ***)&this->field_0x1118 = &::dBgS_Chk::__vt;
  *(undefined ***)&this->field_0x1124 = &PTR_80371f68;
  *(undefined ***)&this->field_0x10d0 = &::dBgS_LinChk::__vt;
  *(undefined **)&this->field_0x10e0 = &DAT_80371f38;
  *(undefined ***)&this->field_0x1118 = &PTR_80371f44;
  *(undefined ***)&this->field_0x1124 = &PTR_80371f50;
  (((cBgS_LinChk *)&this->field_0x10c0)->parent).mpPolyPassChk =
       (cBgS_PolyPassChk *)&this->field_0x1118;
  iVar1 = &this->field_0x1118;
  if (iVar1 != 0) {
    iVar1 = &this->field_0x1124;
  }
  *(int *)&this->field_0x10c4 = iVar1;
  *(undefined1 **)&this->field_0x10d0 = &dBgS_BoomerangLinChk::__vt;
  *(undefined **)&this->field_0x10e0 = &DAT_8038aa4c;
  *(undefined **)&this->field_0x1118 = &DAT_8038aa58;
  *(undefined ***)&this->field_0x1124 = &PTR_8038aa64;
  *(undefined *)&this->field_0x1121 = 1;
  ::cBgS_GndChk::cBgS_GndChk((cBgS_GndChk *)&this->field_0x112c);
  *(undefined ***)&this->field_0x116c = &::cBgS_PolyPassChk::__vt;
  *(undefined ***)&this->field_0x116c = &::dBgS_PolyPassChk::__vt;
  *(undefined *)&this->field_0x1170 = 0;
  *(undefined *)&this->field_0x1171 = 0;
  *(undefined *)&this->field_0x1172 = 0;
  *(undefined *)&this->field_0x1173 = 0;
  *(undefined *)&this->field_0x1174 = 0;
  *(undefined *)&this->field_0x1175 = 0;
  *(undefined *)&this->field_0x1176 = 0;
  *(undefined ***)&this->field_0x1178 = &::cBgS_GrpPassChk::__vt;
  *(undefined ***)&this->field_0x1178 = &::dBgS_GrpPassChk::__vt;
  *(undefined4 *)&this->field_0x117c = 1;
  *(undefined ***)&this->field_0x116c = &::dBgS_Chk::__vt;
  *(undefined ***)&this->field_0x1178 = &PTR_80371f68;
  *(cBgS_Chk__vtbl **)&this->field_0x113c = &::dBgS_GndChk::__vt;
  *(cBgS_PolyInfo__vtbl **)&this->field_0x114c = &cBgS_PolyInfo__vtbl_80371f08;
  *(undefined ***)&this->field_0x116c = &PTR_80371f14;
  *(undefined ***)&this->field_0x1178 = &PTR_80371f20;
  (((cBgS_GndChk *)&this->field_0x112c)->parent).mpPolyPassChk =
       (cBgS_PolyPassChk *)&this->field_0x116c;
  iVar1 = &this->field_0x116c;
  if (iVar1 != 0) {
    iVar1 = &this->field_0x1178;
  }
  *(int *)&this->field_0x1130 = iVar1;
  *(cBgS_Chk__vtbl **)&this->field_0x113c = &::dBgS_ObjGndChk::__vt;
  *(cBgS_PolyInfo__vtbl **)&this->field_0x114c = &cBgS_PolyInfo__vtbl_80371ed8;
  *(cBgS_PolyPassChk__vtbl **)&this->field_0x116c = &cBgS_PolyPassChk__vtbl_80371ee4;
  *(cBgS_GrpPassChk__vtbl **)&this->field_0x1178 = &cBgS_GrpPassChk__vtbl_80371ef0;
  *(undefined *)&this->field_0x1170 = 1;
  return;
}


/* __thiscall dBgS_BoomerangLinChk::~dBgS_BoomerangLinChk(void) */

void __thiscall dBgS_BoomerangLinChk::_dBgS_BoomerangLinChk(dBgS_BoomerangLinChk *this)

{
  short in_r4;
  
  if (this != (dBgS_BoomerangLinChk *)0x0) {
    (this->parent).parent.parent.vtbl = (cBgS_Chk__vtbl *)&__vt;
    (this->parent).parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_8038aa4c;
    (this->parent).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&DAT_8038aa58;
    (this->parent).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_8038aa64;
    if (this != (dBgS_BoomerangLinChk *)0x0) {
      (this->parent).parent.parent.vtbl = (cBgS_Chk__vtbl *)&::dBgS_LinChk::__vt;
      (this->parent).parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_80371f38;
      (this->parent).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f44;
      (this->parent).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f50;
      if (this != (dBgS_BoomerangLinChk *)0xffffffa8) {
        (this->parent).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
        (this->parent).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
        if (this != (dBgS_BoomerangLinChk *)0xffffff9c) {
          (this->parent).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt
          ;
          if (this != (dBgS_BoomerangLinChk *)0xffffff9c) {
            (this->parent).mGrpPassChk.parent.vtbl =
                 (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
          }
        }
        if ((this != (dBgS_BoomerangLinChk *)0xffffffa8) &&
           ((this->parent).mPolyPassChk.parent.vtbl =
                 (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
           this != (dBgS_BoomerangLinChk *)0xffffffa8)) {
          (this->parent).mPolyPassChk.parent.vtbl =
               (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
        }
      }
      if (this != (dBgS_BoomerangLinChk *)0x0) {
        (this->parent).parent.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
        (this->parent).parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371fbc;
        if (this != (dBgS_BoomerangLinChk *)0xffffffdc) {
          (this->parent).parent.mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
        }
        if (this != (dBgS_BoomerangLinChk *)0xffffffec) {
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


namespace d_a_boomerang {

/* __stdcall daBoomerang_Create(fopAc_ac_c *) */

void daBoomerang_Create(daBoomerang_c *param_1)

{
  ::daBoomerang_c::create(param_1);
  return;
}


void __sinit_d_a_boomerang_cpp(void)

{
  l_blur_top = _5341;
  DAT_803e36ec = _4431;
  DAT_803e36f0 = _4431;
  Runtime.PPCEABI.H::__register_global_object(&l_blur_top,::cXyz::_cXyz,&_4320);
  l_blur_root = _5799;
  DAT_803e3704 = _4431;
  DAT_803e3708 = _4431;
  Runtime.PPCEABI.H::__register_global_object(&l_blur_root,::cXyz::_cXyz,&_4321);
  return;
}

}

/* [thunk]:__thiscall dBgS_BoomerangLinChk::~dBgS_BoomerangLinChk(void) */

void __thiscall dBgS_BoomerangLinChk::_dBgS_BoomerangLinChk(dBgS_BoomerangLinChk *this)

{
  _dBgS_BoomerangLinChk((dBgS_BoomerangLinChk *)&this[-1].parent.mPolyPassChk);
  return;
}


/* [thunk]:__thiscall dBgS_BoomerangLinChk::~dBgS_BoomerangLinChk(void) */

void __thiscall dBgS_BoomerangLinChk::_dBgS_BoomerangLinChk(dBgS_BoomerangLinChk *this)

{
  _dBgS_BoomerangLinChk((dBgS_BoomerangLinChk *)&this[-1].parent.parent.parent.mProcID);
  return;
}


/* [thunk]:__thiscall dBgS_BoomerangLinChk::~dBgS_BoomerangLinChk(void) */

void __thiscall dBgS_BoomerangLinChk::_dBgS_BoomerangLinChk(dBgS_BoomerangLinChk *this)

{
  _dBgS_BoomerangLinChk((dBgS_BoomerangLinChk *)&this[-1].parent.parent.mPolyInfo);
  return;
}


/* __thiscall daPy_py_c::checkPlayerNoDraw(void) */

undefined4 __thiscall daPy_py_c::checkPlayerNoDraw(daPy_py_c *this)

{
  return 0;
}


/* __thiscall daPy_lk_c::getBoomerangCatchPos(void) const */

void __thiscall daPy_lk_c::getBoomerangCatchPos(daPy_lk_c *this)

{
  int in_r4;
  
  (this->parent).parent.parent.parent.mBsType = *(uint *)(in_r4 + 0x36f4);
  (this->parent).parent.parent.parent.mBsPcId = *(uint *)(in_r4 + 0x36f8);
  *(undefined4 *)&(this->parent).parent.parent.parent.mProcName = *(undefined4 *)(in_r4 + 0x36fc);
  return;
}


/* __thiscall daPy_lk_c::getLineTopPos(void) */

void __thiscall daPy_lk_c::getLineTopPos(daPy_lk_c *this)

{
  daPy_sightPacket_c::getPos((daPy_sightPacket_c *)this);
  return;
}


/* __thiscall daPy_sightPacket_c::getPos(void) */

void __thiscall daPy_sightPacket_c::getPos(daPy_sightPacket_c *this)

{
  int in_r4;
  
  (this->parent).vtbl = *(undefined **)(in_r4 + 8);
  *(undefined4 *)&this->field_0x4 = *(undefined4 *)(in_r4 + 0xc);
  (this->field_0x8).x = *(float *)(in_r4 + 0x10);
  return;
}


/* __thiscall daBoomerang_blur_c::~daBoomerang_blur_c(void) */

void __thiscall daBoomerang_blur_c::_daBoomerang_blur_c(daBoomerang_blur_c *this)

{
  short in_r4;
  
  if (this != (daBoomerang_blur_c *)0x0) {
    *(undefined1 **)this = &__vt;
    Runtime.PPCEABI.H::__destroy_arr(this + 0x894,::cXyz::_cXyz,0xc,0x3c);
    Runtime.PPCEABI.H::__destroy_arr(this + 0x5c4,::cXyz::_cXyz,0xc,0x3c);
    Runtime.PPCEABI.H::__destroy_arr(this + 0x2f4,::cXyz::_cXyz,0xc,0x3c);
    Runtime.PPCEABI.H::__destroy_arr(this + 0x24,::cXyz::_cXyz,0xc,0x3c);
    if (this != (daBoomerang_blur_c *)0x0) {
      *(undefined ***)this = &J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall daBoomerang_sightPacket_c::~daBoomerang_sightPacket_c(void) */

void __thiscall
daBoomerang_sightPacket_c::_daBoomerang_sightPacket_c(daBoomerang_sightPacket_c *this)

{
  short in_r4;
  
  if (this != (daBoomerang_sightPacket_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (daBoomerang_sightPacket_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

