#include <d_a_grid.h>
#include <mtx/vec.h>
#include <m_Do_mtx.h>
#include <SComponent/c_xyz.h>
#include <SComponent/c_lib.h>
#include <J3DGraphBase/J3DSys.h>
#include <gx/GXBump.h>
#include <d_kankyo.h>
#include <gx/GXAttr.h>
#include <d_resorce.h>
#include <gx/GXTexture.h>
#include <gx/GXLight.h>
#include <gx/GXTev.h>
#include <gx/GXDisplayList.h>
#include <gx/GXTransform.h>
#include <gx/GXGeometry.h>
#include <d_a_grid.h>
#include <d_kankyo_wether.h>
#include <SComponent/c_math.h>
#include <os/OSCache.h>
#include <f_op_actor.h>
#include <J3DGraphBase/J3DPacket.h>
#include <m_Do_ext.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <d_com_inf_game.h>
#include <m_Do_hostIO.h>
#include <MSL_C.PPCEABI.bare.H/s_sin.h>
#include <f_pc_searcher.h>
#include <f_op_actor_iter.h>
#include <mtx/mtx.h>
#include <J3DGraphBase/J3DDrawBuffer.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JKernel/JKRHeap.h>
#include <J3DMatPacket.h>
#include <cXyz.h>
#include <daHo_packet_c.h>
#include <daGrid_c.h>
#include <dCamera_c.h>
#include <daHo_HIO_c.h>


namespace d_a_grid {
undefined4 l_HIO;
undefined4 l_ship;
}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x800e8d28) */
/* __thiscall daHo_packet_c::setBackNrm(void) */

void __thiscall daHo_packet_c::setBackNrm(daHo_packet_c *this)

{
  int iVar1;
  cXyz *pcVar2;
  cXyz *pcVar3;
  undefined4 uVar4;
  undefined8 in_f31;
  double dVar5;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  pcVar3 = (cXyz *)(this + (uint)(byte)this[0x18a2] * 0x3fc + 0x8ac);
  pcVar2 = (cXyz *)(this + (uint)(byte)this[0x18a2] * 0x3fc + 0x10a4);
  iVar1 = 0;
  dVar5 = (double)d_a_grid::_4151;
  do {
    pcVar2->x = (float)dVar5;
    pcVar2->y = (float)dVar5;
    pcVar2->z = (float)dVar5;
    mtx::PSVECSubtract(pcVar2,pcVar3,pcVar2);
    iVar1 = iVar1 + 1;
    pcVar3 = pcVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (iVar1 < 0x55);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* __thiscall daHo_packet_c::setNrmMtx(cXyz &) */

void __thiscall daHo_packet_c::setNrmMtx(daHo_packet_c *this,cXyz *param_1)

{
  m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)*(short *)(this + 0x189c));
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall daHo_packet_c::setNrmVtx(cXyz *,
                                       int,
                                       int) */

void __thiscall daHo_packet_c::setNrmVtx(daHo_packet_c *this,cXyz *param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  daHo_packet_c *pdVar4;
  cXyz local_158;
  cXyz local_14c;
  cXyz local_140;
  cXyz local_134;
  cXyz local_128;
  cXyz local_11c;
  cXyz local_110;
  cXyz local_104;
  cXyz local_f8;
  cXyz local_ec;
  cXyz local_e0;
  cXyz local_d4;
  cXyz local_c8;
  cXyz local_bc;
  cXyz local_b0;
  cXyz local_a4;
  cXyz local_98;
  cXyz local_8c;
  cXyz local_80;
  cXyz local_74;
  cXyz local_68;
  cXyz local_5c;
  cXyz local_50;
  cXyz local_44;
  cXyz local_38;
  cXyz local_2c;
  longlong local_20;
  
  pdVar4 = this + (uint)(byte)this[0x18a2] * 0x3fc + 0xb4;
  iVar3 = param_2 + param_3 * 7;
  iVar1 = iVar3 * 0xc;
  local_5c.x = *(float *)(pdVar4 + iVar1);
  local_5c.y = *(float *)(pdVar4 + iVar1 + 4);
  local_5c.z = *(float *)(pdVar4 + iVar1 + 8);
  local_50.x = d_a_grid::_4151;
  local_50.y = d_a_grid::_4151;
  local_50.z = d_a_grid::_4151;
  if (param_2 != 0) {
    ::cXyz::operator__(&local_68,(cXyz *)(pdVar4 + (iVar3 + -1) * 0xc),&local_5c);
    local_2c.x = local_68.x;
    local_2c.y = local_68.y;
    local_2c.z = local_68.z;
    if ((param_3 != 0) && (param_3 != 9)) {
      ::cXyz::operator__(&local_74,(cXyz *)(pdVar4 + (param_2 + (param_3 + -1) * 7) * 0xc),&local_5c
                        );
      local_38.x = local_74.x;
      local_38.y = local_74.y;
      local_38.z = local_74.z;
      ::cXyz::outprod(&local_80,&local_2c,&local_38);
      local_44.x = local_80.x;
      local_44.y = local_80.y;
      local_44.z = local_80.z;
      ::cXyz::normZC(&local_8c,&local_44);
      local_44.x = local_8c.x;
      local_44.y = local_8c.y;
      local_44.z = local_8c.z;
      mtx::PSVECAdd(&local_50,&local_44,&local_50);
    }
    if (param_3 == 0xb) {
      ::cXyz::operator__(&local_98,(cXyz *)(pdVar4 + 0x3f0),&local_5c);
      local_38.x = local_98.x;
      local_38.y = local_98.y;
      local_38.z = local_98.z;
      ::cXyz::outprod(&local_a4,&local_38,&local_2c);
      local_44.x = local_a4.x;
      local_44.y = local_a4.y;
      local_44.z = local_a4.z;
      ::cXyz::normZC(&local_b0,&local_44);
      local_44.x = local_b0.x;
      local_44.y = local_b0.y;
      local_44.z = local_b0.z;
      mtx::PSVECAdd(&local_50,&local_44,&local_50);
    }
    else {
      if (param_3 != 8) {
        ::cXyz::operator__(&local_bc,(cXyz *)(pdVar4 + (param_2 + (param_3 + 1) * 7) * 0xc),
                           &local_5c);
        local_38.x = local_bc.x;
        local_38.y = local_bc.y;
        local_38.z = local_bc.z;
        ::cXyz::outprod(&local_c8,&local_38,&local_2c);
        local_44.x = local_c8.x;
        local_44.y = local_c8.y;
        local_44.z = local_c8.z;
        ::cXyz::normZC(&local_d4,&local_44);
        local_44.x = local_d4.x;
        local_44.y = local_d4.y;
        local_44.z = local_d4.z;
        mtx::PSVECAdd(&local_50,&local_44,&local_50);
      }
    }
  }
  if (param_2 != 6) {
    ::cXyz::operator__(&local_e0,(cXyz *)(pdVar4 + (param_2 + param_3 * 7 + 1) * 0xc),&local_5c);
    local_2c.x = local_e0.x;
    local_2c.y = local_e0.y;
    local_2c.z = local_e0.z;
    if ((param_3 != 0) && (param_3 != 9)) {
      ::cXyz::operator__(&local_ec,(cXyz *)(pdVar4 + (param_2 + (param_3 + -1) * 7) * 0xc),&local_5c
                        );
      local_38.x = local_ec.x;
      local_38.y = local_ec.y;
      local_38.z = local_ec.z;
      ::cXyz::outprod(&local_f8,&local_38,&local_2c);
      local_44.x = local_f8.x;
      local_44.y = local_f8.y;
      local_44.z = local_f8.z;
      ::cXyz::normZC(&local_104,&local_44);
      local_44.x = local_104.x;
      local_44.y = local_104.y;
      local_44.z = local_104.z;
      mtx::PSVECAdd(&local_50,&local_44,&local_50);
    }
    if (param_3 == 0xb) {
      ::cXyz::operator__(&local_110,(cXyz *)(pdVar4 + 0x3f0),&local_5c);
      local_38.x = local_110.x;
      local_38.y = local_110.y;
      local_38.z = local_110.z;
      ::cXyz::outprod(&local_11c,&local_2c,&local_38);
      local_44.x = local_11c.x;
      local_44.y = local_11c.y;
      local_44.z = local_11c.z;
      ::cXyz::normZC(&local_128,&local_44);
      local_44.x = local_128.x;
      local_44.y = local_128.y;
      local_44.z = local_128.z;
      mtx::PSVECAdd(&local_50,&local_44,&local_50);
    }
    else {
      if (param_3 != 8) {
        ::cXyz::operator__(&local_134,(cXyz *)(pdVar4 + (param_2 + (param_3 + 1) * 7) * 0xc),
                           &local_5c);
        local_38.x = local_134.x;
        local_38.y = local_134.y;
        local_38.z = local_134.z;
        ::cXyz::outprod(&local_140,&local_2c,&local_38);
        local_44.x = local_140.x;
        local_44.y = local_140.y;
        local_44.z = local_140.z;
        ::cXyz::normZC(&local_14c,&local_44);
        local_44.x = local_14c.x;
        local_44.y = local_14c.y;
        local_44.z = local_14c.z;
        mtx::PSVECAdd(&local_50,&local_44,&local_50);
      }
    }
  }
  if (7 < param_3) {
    local_50.y = d_a_grid::_4151;
  }
  cVar2 = ::cXyz::normalizeRS(&local_50);
  if (cVar2 == '\0') {
    local_50.x = d_a_grid::_4129;
    local_50.y = d_a_grid::_4151;
    local_50.z = d_a_grid::_4151;
  }
  SComponent::MtxPush();
  local_20 = (longlong)
             (int)(d_a_grid::_4336 *
                  JKernel::JMath::jmaSinTable
                  [(int)((param_2 + param_3) * -800 & 0xffffU) >>
                   (JKernel::JMath::jmaSinShift & 0x3f)]);
  m_Do_mtx::mDoMtx_YrotM
            (SComponent::calc_mtx,
             (short)(int)(d_a_grid::_4336 *
                         JKernel::JMath::jmaSinTable
                         [(int)((param_2 + param_3) * -800 & 0xffffU) >>
                          (JKernel::JMath::jmaSinShift & 0x3f)]));
  SComponent::MtxPosition(&local_50,&local_44);
  ::cXyz::normZC(&local_158,&local_44);
  param_1->x = local_158.x;
  param_1->y = local_158.y;
  param_1->z = local_158.z;
  SComponent::MtxPull();
  return;
}


/* __thiscall daHo_packet_c::setTopNrmVtx(cXyz *) */

void __thiscall daHo_packet_c::setTopNrmVtx(daHo_packet_c *this,cXyz *param_1)

{
  daHo_packet_c *pdVar1;
  cXyz local_78;
  cXyz local_6c;
  cXyz local_60;
  cXyz local_54;
  cXyz local_48;
  cXyz local_3c;
  cXyz cStack48;
  cXyz local_24;
  cXyz local_18;
  
  pdVar1 = this + (uint)(byte)this[0x18a2] * 0x3fc + 0xb4;
  ::cXyz::operator__(&local_48,(cXyz *)(pdVar1 + 0x39c),(cXyz *)(pdVar1 + 0x3f0));
  local_18.x = local_48.x;
  local_18.y = local_48.y;
  local_18.z = local_48.z;
  ::cXyz::operator__(&local_54,(cXyz *)(pdVar1 + 0x3e4),(cXyz *)(pdVar1 + 0x3f0));
  local_24.x = local_54.x;
  local_24.y = local_54.y;
  local_24.z = local_54.z;
  ::cXyz::outprod(&local_60,&local_18,&local_24);
  local_3c.x = local_60.x;
  local_3c.y = local_60.y;
  local_3c.z = local_60.z;
  ::cXyz::normZC(&local_6c,&local_3c);
  local_3c.x = local_6c.x;
  local_3c.y = local_6c.y;
  local_3c.z = local_6c.z;
  SComponent::MtxPosition(&local_3c,&cStack48);
  ::cXyz::normZC(&local_78,&cStack48);
  param_1->x = local_78.x;
  param_1->y = local_78.y;
  param_1->z = local_78.z;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daHo_packet_c::draw(void) */

void __thiscall daHo_packet_c::draw(daHo_packet_c *this)

{
  undefined *puVar1;
  _GXTexFmt *p_Var2;
  int lightMask;
  int iVar3;
  _GXColor local_80;
  _GXColor local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined auStack112 [12];
  GXTexObj GStack100;
  undefined4 local_40;
  uint uStack60;
  undefined4 local_38;
  uint uStack52;
  undefined4 local_30;
  uint uStack44;
  undefined4 local_28;
  uint uStack36;
  undefined4 local_20;
  uint uStack28;
  undefined4 local_18;
  uint uStack20;
  
  J3DSys::reinitGX(&J3DGraphBase::j3dSys);
  gx::GXSetNumIndStages(0);
  d_kankyo::dKy_GxFog_tevstr_set(*(dKy_tevstr_c **)(this + 0xb0));
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX8);
  gx::GXSetVtxDesc(GX_VA_NRM,GX_INDEX8);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_INDEX8);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_NRM,GX_CLR_RGB,GX_F32,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,0);
  gx::GXSetArray(GX_VA_POS,this + (uint)(byte)this[0x18a2] * 0x3fc + 0xb4,0xc);
  gx::GXSetArray(GX_VA_NRM,this + (uint)(byte)this[0x18a2] * 0x3fc + 0x8ac,0xc);
  gx::GXSetArray(GX_VA_TEX0,&d_a_grid::l_texCoord,8);
  puVar1 = (undefined *)
           dRes_control_c::getRes
                     ("Ship",0x17,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  gx::GXInitTlutObj(auStack112,puVar1 + *(int *)(puVar1 + 0xc),1,0x100);
  gx::GXInitTexObjCI(&GStack100,puVar1 + *(int *)(puVar1 + 0x1c),*(undefined2 *)(puVar1 + 2),
                     *(undefined2 *)(puVar1 + 4),*puVar1,puVar1[6],puVar1[7],
                     1 - (byte)puVar1[0x18] >> 0x1f,0);
  uStack60 = (int)(char)puVar1[0x16] ^ 0x80000000;
  local_40 = 0x43300000;
  uStack52 = (int)(char)puVar1[0x17] ^ 0x80000000;
  local_38 = 0x43300000;
  uStack44 = (int)*(short *)(puVar1 + 0x1a) ^ 0x80000000;
  local_30 = 0x43300000;
  gx::GXInitTexObjLOD((double)(d_a_grid::_4421 *
                              (float)((double)CONCAT44(0x43300000,uStack60) - d_a_grid::_4137)),
                      (double)(d_a_grid::_4421 *
                              (float)((double)CONCAT44(0x43300000,uStack52) - d_a_grid::_4137)),
                      (double)(d_a_grid::_4422 *
                              (float)((double)CONCAT44(0x43300000,uStack44) - d_a_grid::_4137)),
                      &GStack100,puVar1[0x14],puVar1[0x15],puVar1[0x12],puVar1[0x11],puVar1[0x13]);
  gx::GXLoadTlut(auStack112,0);
  gx::GXLoadTexObj(&GStack100,0);
  p_Var2 = (_GXTexFmt *)
           dRes_control_c::getRes
                     ("Cloth",3,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  gx::GXInitTexObj(&GStack100,p_Var2 + *(int *)(p_Var2 + 0x1c),(uint)*(ushort *)(p_Var2 + 2),
                   (uint)*(ushort *)(p_Var2 + 4),*p_Var2,p_Var2[6],p_Var2[7],
                   SUB41(1 - (uint)p_Var2[0x18] >> 0x1f,0));
  uStack36 = (int)(char)p_Var2[0x16] ^ 0x80000000;
  local_28 = 0x43300000;
  uStack28 = (int)(char)p_Var2[0x17] ^ 0x80000000;
  local_20 = 0x43300000;
  uStack20 = (int)*(short *)(p_Var2 + 0x1a) ^ 0x80000000;
  local_18 = 0x43300000;
  gx::GXInitTexObjLOD((double)(d_a_grid::_4421 *
                              (float)((double)CONCAT44(0x43300000,uStack36) - d_a_grid::_4137)),
                      (double)(d_a_grid::_4421 *
                              (float)((double)CONCAT44(0x43300000,uStack28) - d_a_grid::_4137)),
                      (double)(d_a_grid::_4422 *
                              (float)((double)CONCAT44(0x43300000,uStack20) - d_a_grid::_4137)),
                      &GStack100,p_Var2[0x14],p_Var2[0x15],p_Var2[0x12],p_Var2[0x11],p_Var2[0x13]);
  gx::GXLoadTexObj(&GStack100,1);
  gx::GXSetNumChans(1);
  if (*(char *)(*(int *)(this + 0xb0) + 0x8f) == '\0') {
    iVar3 = 2;
    lightMask = 1;
  }
  else {
    iVar3 = 3;
    lightMask = 3;
  }
  if (DAT_803e4169 == '\0') {
    gx::GXSetChanCtrl(GX_COLOR0,true,GX_SRC_REG,GX_SRC_REG,lightMask,GX_DF_CLAMP,GX_AF_NONE);
    gx::GXSetNumTexGens(1);
    gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
    gx::GXSetNumTevStages(iVar3);
    gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
    gx::GXSetTevSwapMode(0,1,0);
    gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C0,GX_CC_C1,GX_CC_RASC,GX_CC_ZERO);
    gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevSwapMode(1,0,0);
    gx::GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
    gx::GXSetTevColorIn(GX_TEVSTAGE1,GX_CC_ZERO,GX_CC_CPREV,GX_CC_TEXC,GX_CC_ZERO);
    gx::GXSetTevColorOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE1,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_TEXA);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    if (iVar3 == 3) {
      gx::GXSetTevSwapMode(2,2,0);
      gx::GXSetTevOrder(GX_TEVSTAGE2,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
      gx::GXSetTevColorIn(GX_TEVSTAGE2,GX_CC_ZERO,GX_CC_C2,GX_CC_RASC,GX_CC_CPREV);
      gx::GXSetTevColorOp(GX_TEVSTAGE2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetTevAlphaIn(GX_TEVSTAGE2,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_TEXA);
      gx::GXSetTevAlphaOp(GX_TEVSTAGE2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    }
  }
  else {
    gx::GXSetChanCtrl(GX_COLOR0,true,GX_SRC_REG,GX_SRC_REG,lightMask,GX_DF_CLAMP,GX_AF_NONE);
    gx::GXSetNumTexGens(2);
    gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
    gx::GXSetTexCoordGen2(GX_TEXCOORD1,GX_TG_SRTG,GX_TG_COLOR0,GX_IDENTITY,false,GX_PTIDENTITY);
    gx::GXSetNumTevStages(iVar3);
    gx::GXSetTevSwapMode(0,0,1);
    gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD1,GX_TEXMAP1,GX_COLOR0A0);
    gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C0,GX_CC_C1,GX_CC_TEXC,GX_CC_ZERO);
    gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevSwapMode(1,0,0);
    gx::GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
    gx::GXSetTevColorIn(GX_TEVSTAGE1,GX_CC_ZERO,GX_CC_TEXC,GX_CC_CPREV,GX_CC_ZERO);
    gx::GXSetTevColorOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE1,GX_CA_ZERO,GX_CA_A0,GX_CA_TEXA,GX_CA_ZERO);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    if (iVar3 == 3) {
      gx::GXSetTevSwapMode(2,0,2);
      gx::GXSetTevOrder(GX_TEVSTAGE2,GX_TEXCOORD1,GX_TEXMAP1,GX_COLOR_NULL);
      gx::GXSetTevColorIn(GX_TEVSTAGE2,GX_CC_ZERO,GX_CC_C2,GX_CC_TEXC,GX_CC_CPREV);
      gx::GXSetTevColorOp(GX_TEVSTAGE2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetTevAlphaIn(GX_TEVSTAGE2,GX_CA_ZERO,GX_CA_A0,GX_CA_TEXA,GX_CA_ZERO);
      gx::GXSetTevAlphaOp(GX_TEVSTAGE2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    }
  }
  *(ushort *)(*(int *)(this + 0xb0) + 0x86) = (ushort)(byte)this[0x18a3];
  local_78 = *(undefined4 *)(*(int *)(this + 0xb0) + 0x80);
  local_74 = *(undefined4 *)(*(int *)(this + 0xb0) + 0x84);
  gx::GXSetTevColorS10(GX_TEVREG0,(_GXColorS10 *)&local_78);
  local_7c = *(_GXColor *)(*(int *)(this + 0xb0) + 0x88);
  gx::GXSetTevColor(GX_TEVREG1,&local_7c);
  local_80 = *(_GXColor *)(*(int *)(this + 0xb0) + 0x8c);
  gx::GXSetTevColor(GX_TEVREG2,&local_80);
  gx::GXCallDisplayList(&d_a_grid::l_matDL,0x20);
  gx::GXLoadPosMtxImm((MTX34 *)(this + 0x80),0);
  gx::GXLoadNrmMtxImm(this + 0x80,0);
  gx::GXSetCullMode(2);
  gx::GXCallDisplayList(&d_a_grid::l_DL,0x220);
  gx::GXSetCullMode(1);
  gx::GXSetArray(GX_VA_NRM,this + (uint)(byte)this[0x18a2] * 0x3fc + 0x10a4,0xc);
  gx::GXCallDisplayList(&d_a_grid::l_DL,0x220);
  _sOldVcdVatCmd = 0;
  return;
}


namespace d_a_grid {

/* __stdcall daGrid_Draw(daGrid_c *) */

undefined daGrid_Draw(daGrid_c *param_1)

{
  undefined uVar1;
  
  uVar1 = ::daGrid_c::_draw(param_1);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f14 */
/* WARNING: Inlined function: FUN_80328f60 */
/* WARNING: Removing unreachable block (ram,0x800ea900) */
/* WARNING: Removing unreachable block (ram,0x800ea8f0) */
/* WARNING: Removing unreachable block (ram,0x800ea8e0) */
/* WARNING: Removing unreachable block (ram,0x800ea8d0) */
/* WARNING: Removing unreachable block (ram,0x800ea8c0) */
/* WARNING: Removing unreachable block (ram,0x800ea8b0) */
/* WARNING: Removing unreachable block (ram,0x800ea8a0) */
/* WARNING: Removing unreachable block (ram,0x800ea890) */
/* WARNING: Removing unreachable block (ram,0x800ea888) */
/* WARNING: Removing unreachable block (ram,0x800ea898) */
/* WARNING: Removing unreachable block (ram,0x800ea8a8) */
/* WARNING: Removing unreachable block (ram,0x800ea8b8) */
/* WARNING: Removing unreachable block (ram,0x800ea8c8) */
/* WARNING: Removing unreachable block (ram,0x800ea8d8) */
/* WARNING: Removing unreachable block (ram,0x800ea8e8) */
/* WARNING: Removing unreachable block (ram,0x800ea8f8) */
/* WARNING: Removing unreachable block (ram,0x800ea908) */
/* __stdcall ho_move(daGrid_c *) */

void ho_move(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  short sVar10;
  int iVar9;
  cXyz *pcVar11;
  int iVar12;
  short sVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  float *pfVar19;
  ushort uVar20;
  undefined4 uVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  undefined8 in_f15;
  double dVar25;
  undefined8 in_f16;
  double dVar26;
  undefined8 in_f17;
  double dVar27;
  undefined8 in_f18;
  double dVar28;
  undefined8 in_f19;
  double dVar29;
  undefined8 in_f20;
  undefined8 in_f21;
  double dVar30;
  undefined8 in_f22;
  double dVar31;
  undefined8 in_f23;
  double dVar32;
  undefined8 in_f24;
  double dVar33;
  undefined8 in_f25;
  double dVar34;
  undefined8 in_f26;
  double dVar35;
  undefined8 in_f27;
  double dVar36;
  undefined8 in_f28;
  double dVar37;
  undefined8 in_f29;
  double dVar38;
  undefined8 in_f30;
  double dVar39;
  undefined8 in_f31;
  double dVar40;
  cXyz local_1d0;
  cXyz local_1c4;
  cXyz local_1b8;
  cXyz local_1ac;
  double local_1a0;
  double local_198;
  double local_190;
  double local_188;
  double local_180;
  double local_178;
  double local_170;
  double local_168;
  double local_160;
  double local_158;
  double local_150;
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
  if (DAT_803e419c == '\0') {
    pcVar11 = d_kankyo_wether::dKyw_get_wind_vec();
    dVar23 = d_kankyo_wether::dKyw_get_wind_pow();
    *(byte *)(param_1 + 0x1b42) = *(byte *)(param_1 + 0x1b42) ^ 1;
    *(undefined2 *)(param_1 + 0x1b4c) = 0x1d4c;
    *(undefined2 *)(param_1 + 0x1b4e) = 0x1c20;
    sVar13 = *(short *)(l_ship + 0x364);
    iVar12 = SComponent::cM_atan2s(pcVar11->x,pcVar11->z);
    uVar20 = (*(short *)(param_1 + 0x206) + sVar13) - (short)iVar12;
    sVar10 = uVar20 + 0x8000;
    if (sVar10 < 1) {
      if ((sVar13 < 0) && (-0x4000 < sVar13)) {
        sVar10 = 0;
      }
    }
    else {
      if ((0 < sVar13) && (sVar13 < 0x4000)) {
        sVar10 = 0;
      }
    }
    local_1a0 = (double)CONCAT44(0x43300000,(int)sVar10 ^ 0x80000000);
    iVar12 = (int)(_4752 * (float)(local_1a0 - _4137));
    local_198 = (double)(longlong)iVar12;
    if (*(char *)(param_1 + 0x2218) == '\0') {
      SComponent::cLib_addCalcAngleS2((short *)(param_1 + 0x2210),(short)iVar12,4,0x1000);
    }
    else {
      SComponent::cLib_addCalcAngleS2
                ((short *)(param_1 + 0x2210),
                 (*(short *)(param_1 + 0x2216) - *(short *)(l_ship + 0x364)) + -0x8000,2,0x1400);
    }
    *(undefined *)(param_1 + 0x2218) = 0;
    m_Do_mtx::mDoMtx_YrotS(SComponent::calc_mtx,(int)*(short *)(param_1 + 0x2210));
    local_1ac.x = _4151;
    local_1ac.y = _4151;
    local_1ac.z = _4753;
    SComponent::MtxPosition(&local_1ac,&local_1b8);
    dVar38 = (double)(_4754 + ABS(local_1b8.z));
    local_1ac.x = _4129;
    local_1ac.z = _4151;
    SComponent::MtxPosition(&local_1ac,&local_1b8);
    dVar37 = (double)(ABS(local_1b8.z) * (_4129 - *(float *)(param_1 + 0x2200)));
    dVar36 = (double)(_4129 + (_4422 + d_s_play::g_regHIO.mChild[6].mFloats[15]) *
                              (float)(dVar37 * (double)JKernel::JMath::jmaSinTable
                                                       [(int)(*(uint *)(param_1 + 0x1b44) & 0xffff)
                                                        >> (JKernel::JMath::jmaSinShift & 0x3f)]));
    iVar12 = (int)(_4755 + _4756 * (float)((double)_4757 * dVar23));
    local_198 = (double)(longlong)iVar12;
    iVar15 = 10000;
    if (iVar12 < 0x2711) {
      iVar15 = iVar12;
    }
    *(int *)(param_1 + 0x1b44) = *(int *)(param_1 + 0x1b44) + iVar15;
    local_1a0 = (double)(longlong)
                        (int)(_4758 * JKernel::JMath::jmaCosTable
                                      [(int)(uint)uVar20 >> (JKernel::JMath::jmaSinShift & 0x3f)]);
    *(short *)(param_1 + 0x2212) =
         *(short *)(param_1 + 0x2212) +
         (short)(int)(_4758 * JKernel::JMath::jmaCosTable
                              [(int)(uint)uVar20 >> (JKernel::JMath::jmaSinShift & 0x3f)]);
    sVar13 = -300;
    if (0 < *(short *)(param_1 + 0x2212)) {
      sVar13 = 300;
    }
    *(short *)(param_1 + 0x2212) = *(short *)(param_1 + 0x2212) + sVar13;
    dVar35 = (double)(_4130 * JKernel::JMath::jmaSinTable
                              [(int)(uint)uVar20 >> (JKernel::JMath::jmaSinShift & 0x3f)]);
    local_1ac.x = _4151;
    local_1ac.z = _4759;
    pfVar19 = (float *)(param_1 + (uint)*(byte *)(param_1 + 0x1b42) * 0x3fc + 0x354);
    if (DAT_803e416c == '\0') {
      if ((*(uint *)(l_ship + 0x358) & 0x200) == 0) {
        if (_4765 < *(float *)(param_1 + 0x2200)) {
          *(float *)(param_1 + 0x2208) = _4151;
          *(undefined2 *)(param_1 + 0x1b4a) = 0;
        }
        SComponent::cLib_addCalc2
                  ((float *)(param_1 + 0x2204),_4129 - _4766 * *(float *)(param_1 + 0x2200),_4763,
                   _4764);
      }
      else {
        if (_4151 == *(float *)(param_1 + 0x2208)) {
          if (*(float *)(param_1 + 0x2200) <= _4760 + DAT_803e4170) {
            *(float *)(param_1 + 0x2208) = _4129;
            *(undefined2 *)(param_1 + 0x1b4a) = 0xf;
          }
        }
        else {
          if (*(short *)(param_1 + 0x1b4a) < 1) {
            SComponent::cLib_addCalc2((float *)(param_1 + 0x2204),_4129,_4763,_4764);
          }
          else {
            SComponent::cLib_addCalc2((float *)(param_1 + 0x2204),_4761,_4762,DAT_803e4184);
            *(short *)(param_1 + 0x1b4a) = *(short *)(param_1 + 0x1b4a) + -1;
          }
        }
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x2200) = DAT_803e4174;
    }
    uVar18 = 0;
    iVar17 = 0;
    iVar16 = 0;
    iVar15 = 0;
    dVar27 = (double)_4762;
    dVar26 = (double)(float)(dVar27 + (double)(float)((double)_4767 * dVar23));
    dVar28 = (double)_4130;
    dVar25 = (double)(float)(dVar28 + (double)(float)(dVar27 * dVar23));
    dVar29 = (double)_4129;
    local_188 = (double)_4768;
    dVar30 = (double)_4151;
    local_180 = (double)_4764;
    local_178 = (double)_4771;
    local_170 = (double)_4772;
    dVar31 = (double)_4775;
    local_168 = (double)_4776;
    local_160 = (double)_4778;
    local_158 = (double)_4766;
    local_150 = (double)_4779;
    iVar12 = 0;
    dVar23 = _4137;
    do {
      dVar34 = (double)(float)(dVar29 - (double)*(float *)(param_1 + 0x2200));
      local_198 = (double)CONCAT44(0x43300000,3 - uVar18 ^ 0x80000000);
      dVar33 = (double)(float)(local_198 - dVar23);
      local_1a0 = (double)CONCAT44(0x43300000,iVar12 - 2U ^ 0x80000000);
      dVar32 = (double)(float)(local_1a0 - dVar23);
      dVar24 = local_188 * (double)(float)(&x_rate_tbl_4446)[iVar12];
      local_190 = (double)(longlong)(int)dVar24;
      dVar40 = (double)(float)(dVar38 * (double)JKernel::JMath::jmaSinTable
                                                [(int)(*(int *)(param_1 + 0x1b44) +
                                                       iVar17 * *(short *)(param_1 + 0x1b4c) &
                                                      0xffffU) >>
                                                 (JKernel::JMath::jmaSinShift & 0x3f)]);
      dVar39 = (double)(float)(dVar28 * (double)(float)(dVar38 * (double)JKernel::JMath::jmaCosTable
                                                                         [(int)(*(int *)(param_1 +
                                                                                        0x1b44) +
                                                                                iVar17 * *(short *)(
                                                  param_1 + 0x1b4e) & 0xffffU) >>
                                                  (JKernel::JMath::jmaSinShift & 0x3f)]));
      SComponent::MtxPosition(&local_1ac,&local_1b8);
      dVar22 = dVar26;
      if (dVar29 < dVar26) {
        dVar22 = dVar29;
      }
      local_1b8.x = (float)((double)local_1b8.x * dVar22);
      dVar22 = dVar25;
      if (dVar29 < dVar25) {
        dVar22 = dVar29;
      }
      local_1b8.z = (float)((double)local_1b8.z * dVar22);
      fVar1 = (float)(dVar40 + (double)(*(float *)(param_1 + 0x2204) *
                                       (float)(dVar34 * (double)(float)((double)local_1b8.x * dVar36
                                                                       ))));
      fVar2 = (float)(dVar39 + (double)(*(float *)(param_1 + 0x2204) *
                                       (float)(dVar34 * (double)(float)((double)local_1b8.z * dVar37
                                                                       ))));
      dVar22 = (double)(fVar1 * fVar1 + fVar2 * fVar2);
      if (dVar30 < dVar22) {
        dVar39 = 1.0 / SQRT(dVar22);
        dVar39 = _4769 * dVar39 * (_4770 - dVar22 * dVar39 * dVar39);
        dVar39 = _4769 * dVar39 * (_4770 - dVar22 * dVar39 * dVar39);
        dVar22 = (double)(float)(dVar22 * _4769 * dVar39 * (_4770 - dVar22 * dVar39 * dVar39));
      }
      fVar7 = *(float *)(param_1 + iVar15 + 0x1b54);
      dVar39 = dVar30;
      if (dVar32 < dVar30) {
        dVar39 = dVar32;
      }
      dVar32 = (double)(float)((double)(float)(dVar39 * dVar39) * dVar27);
      fVar4 = *(float *)(param_1 + 0x2200);
      if (DAT_803e419d == '\0') {
        fVar5 = (float)(&z_rate_tbl2_4445)[iVar12];
        fVar6 = (float)(&z_rate_tbl_4444)[iVar12];
        local_190 = (double)CONCAT44(0x43300000,uVar18 ^ 0x80000000);
        fVar8 = (float)(local_190 - _4137) * _4774 * fVar6;
      }
      else {
        fVar5 = (float)(&DAT_803e41d4)[iVar12];
        fVar6 = (float)(&DAT_803e41a0)[iVar12];
        local_190 = (double)CONCAT44(0x43300000,uVar18 ^ 0x80000000);
        fVar8 = _4774 * fVar6 * (float)(local_190 - _4137);
      }
      fVar6 = _4773 * fVar6 * fVar4;
      dVar39 = (double)((float)(dVar29 - (double)((float)(local_178 +
                                                         (double)(float)(local_170 * dVar32)) *
                                                 fVar4)) * (float)(dVar34 + (double)(fVar5 * fVar4))
                       );
      *pfVar19 = *(float *)((int)&l_pos + iVar16);
      pfVar19[1] = (float)(dVar39 * (double)*(float *)((int)&DAT_8038b1dc + iVar16)) +
                   (float)(dVar29 - dVar39) * (float)(&DAT_8038b1dc)[iVar12 * 0x15];
      pfVar19[2] = (float)(dVar39 * (double)*(float *)((int)&DAT_8038b1e0 + iVar16));
      iVar14 = (int)(short)(int)dVar24;
      iVar9 = (int)((int)*(short *)(param_1 + 0x2212) + iVar14 * uVar18 & 0xffff) >>
              (JKernel::JMath::jmaSinShift & 0x3f);
      dVar24 = (double)(float)(dVar31 - (double)(float)(dVar33 * dVar33));
      local_190 = (double)CONCAT44(0x43300000,uVar18 ^ 0x80000000);
      fVar5 = (float)(dVar29 - (double)(float)(dVar28 * dVar32));
      fVar4 = fVar4 * fVar8 *
              (float)((double)((float)(local_190 - dVar23) *
                              *(float *)(param_1 + 0x2200) * JKernel::JMath::jmaCosTable[iVar9]) /
                     local_168) * fVar5;
      fVar5 = fVar6 * ((float)((double)(float)(dVar24 * (double)(*(float *)(param_1 + 0x2200) *
                                                                JKernel::JMath::jmaSinTable[iVar9]))
                              / dVar31) - (float)((double)(float)(dVar35 * dVar24) / dVar31)) *
              fVar5;
      dVar24 = (double)(fVar5 * fVar5 + fVar4 * fVar4);
      if (dVar30 < dVar24) {
        dVar32 = 1.0 / SQRT(dVar24);
        dVar32 = _4769 * dVar32 * (_4770 - dVar24 * dVar32 * dVar32);
        dVar32 = _4769 * dVar32 * (_4770 - dVar24 * dVar32 * dVar32);
        dVar24 = (double)(float)(dVar24 * _4769 * dVar32 * (_4770 - dVar24 * dVar32 * dVar32));
      }
      fVar6 = (float)(dVar27 * -dVar24);
      if (4 < (int)uVar18) {
        local_190 = (double)CONCAT44(0x43300000,uVar18 - 4 ^ 0x80000000);
        fVar6 = fVar6 + _4777 * (float)(local_190 - _4137) *
                                ABS(JKernel::JMath::jmaSinTable
                                    [(int)((int)*(short *)(param_1 + 0x2212) + uVar18 * iVar14 * 2 &
                                          0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)]);
      }
      if (DAT_803e419d == '\0') {
        local_198 = (double)CONCAT44(0x43300000,uVar18 ^ 0x80000000);
        fVar8 = *(float *)(param_1 + 0x2200) *
                ((float)(local_198 - _4137) / _4776) * _4776 * (float)(&z_rate_tbl_4444)[iVar12];
      }
      else {
        local_190 = (double)CONCAT44(0x43300000,uVar18 ^ 0x80000000);
        fVar8 = *(float *)(param_1 + 0x2200) *
                _4776 * (float)(&DAT_803e41a0)[iVar12] * ((float)(local_190 - _4137) / _4776);
      }
      fVar3 = (float)(local_160 + (double)(float)(local_158 * dVar34));
      *pfVar19 = *pfVar19 + fVar5 + fVar3 * fVar1 * fVar7 * *(float *)(param_1 + 0x2204);
      pfVar19[1] = pfVar19[1] + fVar4 + (float)(local_180 * dVar22) * fVar7 * fVar3;
      pfVar19[2] = pfVar19[2] +
                   fVar6 * fVar8 +
                   (float)((double)(fVar3 * fVar2 * fVar7 * *(float *)(param_1 + 0x2204)) -
                          local_150);
      iVar9 = iVar12 + 1;
      if ((int)uVar18 < 6) {
        iVar9 = iVar12;
      }
      uVar18 = uVar18 + 1 & -((uint)(uVar18 < 6) - ((int)uVar18 >> 0x1f));
      iVar17 = iVar17 + 1;
      iVar16 = iVar16 + 0xc;
      iVar15 = iVar15 + 4;
      pfVar19 = pfVar19 + 3;
      iVar12 = iVar9;
    } while (iVar17 < 0x55);
    iVar12 = param_1 + (uint)*(byte *)(param_1 + 0x1b42) * 0x3fc;
    iVar15 = iVar12 + 0x354;
    fVar1 = ABS(*(float *)(iVar12 + 0x618));
    fVar2 = _4129 - fVar1 * (_4780 + d_s_play::g_regHIO.mChild[6].mFloats[8]);
    fVar7 = _4129 - fVar1 * (_4781 + d_s_play::g_regHIO.mChild[6].mFloats[9]);
    fVar4 = _4129 - fVar1 * (_4782 + d_s_play::g_regHIO.mChild[6].mFloats[10]);
    fVar5 = _4129 - fVar1 * (_4780 + d_s_play::g_regHIO.mChild[6].mFloats[11]);
    fVar1 = _4129 - fVar1 * (_4783 + d_s_play::g_regHIO.mChild[6].mFloats[12]);
    iVar12 = 0;
    iVar16 = 0x55;
    do {
      if ((iVar12 < 0x38) || (0x3e < iVar12)) {
        if ((iVar12 < 0x31) || (0x37 < iVar12)) {
          if ((iVar12 < 0x2a) || (0x30 < iVar12)) {
            if ((iVar12 < 0x3f) || (0x45 < iVar12)) {
              if ((0x45 < iVar12) && (iVar12 < 0x4e)) {
                *(float *)(iVar15 + 8) = *(float *)(iVar15 + 8) * fVar1;
              }
            }
            else {
              *(float *)(iVar15 + 8) = *(float *)(iVar15 + 8) * fVar5;
            }
          }
          else {
            *(float *)(iVar15 + 8) = *(float *)(iVar15 + 8) * fVar4;
          }
        }
        else {
          *(float *)(iVar15 + 8) = *(float *)(iVar15 + 8) * fVar7;
        }
      }
      else {
        *(float *)(iVar15 + 8) = *(float *)(iVar15 + 8) * fVar2;
      }
      iVar12 = iVar12 + 1;
      iVar15 = iVar15 + 0xc;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
    pcVar11 = (cXyz *)(param_1 + (uint)*(byte *)(param_1 + 0x1b42) * 0x3fc + 0xb4c);
    ::cXyz::operator__(&local_1d0,(cXyz *)(param_1 + 0x180),(cXyz *)(param_1 + 0x1f8));
    local_1c4.x = local_1d0.x;
    local_1c4.y = local_1d0.y;
    local_1c4.z = local_1d0.z;
    ::daHo_packet_c::setNrmMtx((daHo_packet_c *)(param_1 + 0x2a0),&local_1c4);
    iVar12 = 0;
    do {
      iVar15 = 0;
      do {
        ::daHo_packet_c::setNrmVtx((daHo_packet_c *)(param_1 + 0x2a0),pcVar11,iVar15,iVar12);
        iVar15 = iVar15 + 1;
        pcVar11 = pcVar11 + 1;
      } while (iVar15 < 7);
      iVar12 = iVar12 + 1;
    } while (iVar12 < 0xc);
    ::daHo_packet_c::setTopNrmVtx((daHo_packet_c *)(param_1 + 0x2a0),pcVar11);
    ::daHo_packet_c::setBackNrm((daHo_packet_c *)(param_1 + 0x2a0));
    os::DCStoreRangeNoSync(param_1 + (uint)*(byte *)(param_1 + 0x1b42) * 0x3fc + 0x354,0x3fc);
    os::DCStoreRangeNoSync(param_1 + (uint)*(byte *)(param_1 + 0x1b42) * 0x3fc + 0xb4c,0x3fc);
    os::DCStoreRangeNoSync(param_1 + (uint)*(byte *)(param_1 + 0x1b42) * 0x3fc + 0x1344,0x3fc);
  }
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
  __psq_l0(auStack104,uVar21);
  __psq_l1(auStack104,uVar21);
  __psq_l0(auStack120,uVar21);
  __psq_l1(auStack120,uVar21);
  __psq_l0(auStack136,uVar21);
  __psq_l1(auStack136,uVar21);
  __psq_l0(auStack152,uVar21);
  __psq_l1(auStack152,uVar21);
  __psq_l0(auStack168,uVar21);
  __psq_l1(auStack168,uVar21);
  __psq_l0(auStack184,uVar21);
  __psq_l1(auStack184,uVar21);
  __psq_l0(auStack200,uVar21);
  __psq_l1(auStack200,uVar21);
  __psq_l0(auStack216,uVar21);
  __psq_l1(auStack216,uVar21);
  __psq_l0(auStack232,uVar21);
  __psq_l1(auStack232,uVar21);
  __psq_l0(auStack248,uVar21);
  __psq_l1(auStack248,uVar21);
  __psq_l0(auStack264,uVar21);
  __psq_l1(auStack264,uVar21);
  return;
}


/* __stdcall daGrid_Execute(daGrid_c *) */

undefined daGrid_Execute(daGrid_c *param_1)

{
  undefined uVar1;
  
  uVar1 = ::daGrid_c::_execute(param_1);
  return uVar1;
}


/* __stdcall daGrid_IsDelete(daGrid_c *) */

undefined4 daGrid_IsDelete(void)

{
  return 1;
}


/* __stdcall daGrid_Delete(daGrid_c *) */

undefined daGrid_Delete(daGrid_c *param_1)

{
  undefined uVar1;
  
  uVar1 = ::daGrid_c::_delete(param_1);
  return uVar1;
}


/* __stdcall daGrid_Create(fopAc_ac_c *) */

void daGrid_Create(daGrid_c *param_1)

{
  ::daGrid_c::_create(param_1);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x800eae84) */
/* WARNING: Removing unreachable block (ram,0x800eae74) */
/* WARNING: Removing unreachable block (ram,0x800eae64) */
/* WARNING: Removing unreachable block (ram,0x800eae6c) */
/* WARNING: Removing unreachable block (ram,0x800eae7c) */
/* WARNING: Removing unreachable block (ram,0x800eae8c) */
/* __thiscall daGrid_c::_create(void) */

PhaseState __thiscall daGrid_c::_create(daGrid_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  PhaseState PVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  double dVar13;
  double dVar14;
  undefined8 in_f26;
  undefined8 in_f27;
  double dVar15;
  undefined8 in_f28;
  double dVar16;
  undefined8 in_f29;
  double dVar17;
  undefined8 in_f30;
  double dVar18;
  undefined8 in_f31;
  double dVar19;
  undefined2 local_88 [2];
  float local_84;
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar12 = 0;
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
  if ((*(uint *)(this + 0x1c8) & 8) == 0) {
    if (this != (daGrid_c *)0x0) {
      fopAc_ac_c::fopAc_ac_c((fopAc_ac_c *)this);
      J3DMatPacket::J3DMatPacket((J3DMatPacket *)(this + 0x2a0));
      (((J3DMatPacket *)(this + 0x2a0))->parent).parent.vtbl = &daHo_packet_c::__vt;
      J3DShapePacket::J3DShapePacket((J3DShapePacket *)(this + 0x2dc));
      Runtime.PPCEABI.H::__construct_array(this + 0x354,::cXyz::cXyz,::cXyz::_cXyz,0xc,0xaa);
      Runtime.PPCEABI.H::__construct_array(this + 0xb4c,::cXyz::cXyz,::cXyz::_cXyz,0xc,0xaa);
      Runtime.PPCEABI.H::__construct_array(this + 0x1344,::cXyz::cXyz,::cXyz::_cXyz,0xc,0xaa);
      this[0x1b42] = (daGrid_c)0x0;
      *(undefined2 *)(this + 0x1b3c) = 0;
      *(undefined2 *)(this + 0x1b40) = 0;
      *(undefined2 *)(this + 0x1b3e) = 0;
      this[0x1b43] = (daGrid_c)0xff;
      *(daGrid_c **)(this + 0x2c8) = this + 0x2dc;
      Runtime.PPCEABI.H::__construct_array(this + 0x1ca8,::cXyz::cXyz,::cXyz::_cXyz,0xc,0x55);
    }
    *(uint *)(this + 0x1c8) = *(uint *)(this + 0x1c8) | 8;
  }
  this[0x1b48] = SUB41(*(undefined4 *)(this + 0xb0),0);
  PVar5 = d_com_inf_game::dComIfG_resLoad((request_of_phase_process_class *)(this + 0x290),"Cloth");
  if ((PVar5 == cPhs_COMPLEATE_e) &&
     (PVar5 = d_com_inf_game::dComIfG_resLoad
                        ((request_of_phase_process_class *)(this + 0x298),"Ship"),
     PVar5 == cPhs_COMPLEATE_e)) {
    if (DAT_803e4168 < '\0') {
      DAT_803e4168 = mDoHIO_subRoot_c::createChild
                               (&mDoHIO_subRoot_c_803a5778,"船の帆",
                                (JORReflexible *)&d_a_grid::l_HIO);
    }
    iVar9 = 0;
    iVar8 = 0;
    iVar7 = 0;
    dVar16 = (double)d_a_grid::_4130;
    dVar17 = (double)d_a_grid::_5027;
    dVar18 = (double)d_a_grid::_5028;
    dVar19 = (double)d_a_grid::_4151;
    do {
      if ((iVar9 < 0) || (6 < iVar9)) {
        if ((iVar9 < 7) || (0xd < iVar9)) {
          if (((iVar9 < 0x31) || (0x37 < iVar9)) && ((iVar9 < 0x2a || (0x30 < iVar9)))) {
            dVar15 = (double)d_a_grid::_5026;
          }
          else {
            dVar15 = (double)d_a_grid::_5025;
          }
        }
        else {
          dVar15 = (double)d_a_grid::_5024;
        }
      }
      else {
        dVar15 = (double)d_a_grid::_5023;
      }
      iVar10 = 6;
      fVar1 = ABS(DAT_8038b1e0 - *(float *)((int)&DAT_8038b1e0 + iVar7));
      fVar2 = ABS(DAT_8038b228 - *(float *)((int)&DAT_8038b1e0 + iVar7));
      if (fVar2 < fVar1) {
        fVar1 = fVar2;
      }
      dVar13 = MSL_C.PPCEABI.bare.H::sin
                         ((double)(fVar1 * (float)(dVar17 * (double)(float)(dVar18 / (double)(float)
                                                  ((double)ABS(DAT_8038b1e0 - DAT_8038b228) * dVar16
                                                  )))));
      dVar15 = (double)(float)(dVar15 * (double)(float)dVar13);
      iVar6 = 0;
      iVar11 = 7;
      do {
        if ((((iVar9 == iVar6) || (iVar9 == iVar6 + 7)) || (iVar9 == iVar6 + 0xe)) ||
           (((((iVar9 == iVar6 + 0x15 || (iVar9 == iVar6 + 0x1c)) ||
              ((iVar9 == iVar6 + 0x23 || ((iVar9 == iVar6 + 0x2a || (iVar9 == iVar6 + 0x31)))))) ||
             (iVar9 == iVar6 + 0x38)) ||
            (((iVar9 == iVar6 + 0x3f || (iVar9 == iVar6 + 0x46)) || (iVar9 == iVar6 + 0x4d)))))) {
          iVar10 = iVar6 + 0x38;
        }
        iVar6 = iVar6 + 1;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      fVar1 = *(float *)((int)&DAT_8038b1dc + iVar7);
      fVar2 = (&DAT_8038b1dc)[iVar10 * 3];
      if (fVar2 <= fVar1) {
        fVar3 = ABS(fVar2 - fVar1);
        fVar4 = ABS(DAT_8038b5cc - fVar1);
        fVar1 = d_a_grid::_5030 * (d_a_grid::_5028 / (ABS(fVar2 - DAT_8038b5cc) * d_a_grid::_4130));
        dVar13 = (double)d_a_grid::_5031;
      }
      else {
        fVar3 = ABS(DAT_8038b1dc - fVar1);
        fVar4 = ABS(fVar2 - fVar1);
        fVar1 = d_a_grid::_5027 * (d_a_grid::_5028 / (ABS(fVar2 - DAT_8038b1dc) * d_a_grid::_4130));
        if (iVar10 == 0x38) {
          dVar13 = (double)d_a_grid::_5029;
        }
        else {
          if (iVar10 == 0x39) {
            dVar13 = (double)d_a_grid::_5024;
          }
          else {
            dVar13 = (double)d_a_grid::_5026;
          }
        }
      }
      if (fVar4 < fVar3) {
        fVar3 = fVar4;
      }
      dVar14 = MSL_C.PPCEABI.bare.H::sin((double)(fVar3 * fVar1));
      dVar15 = (double)((float)(dVar15 * dVar15) +
                       (float)(dVar13 * (double)(float)dVar14) *
                       (float)(dVar13 * (double)(float)dVar14));
      if (dVar19 < dVar15) {
        dVar13 = 1.0 / SQRT(dVar15);
        dVar13 = d_a_grid::_4769 * dVar13 * (d_a_grid::_4770 - dVar15 * dVar13 * dVar13);
        dVar13 = d_a_grid::_4769 * dVar13 * (d_a_grid::_4770 - dVar15 * dVar13 * dVar13);
        local_84 = (float)(dVar15 * d_a_grid::_4769 * dVar13 *
                                    (d_a_grid::_4770 - dVar15 * dVar13 * dVar13));
        dVar15 = (double)local_84;
      }
      *(float *)(this + iVar8 + 0x1b54) = (float)dVar15;
      iVar9 = iVar9 + 1;
      iVar8 = iVar8 + 4;
      iVar7 = iVar7 + 0xc;
    } while (iVar9 < 0x55);
    local_88[0] = 0xa7;
    d_a_grid::l_ship = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,local_88);
    d_a_grid::ho_move(this);
    PVar5 = cPhs_COMPLEATE_e;
  }
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  __psq_l0(auStack24,uVar12);
  __psq_l1(auStack24,uVar12);
  __psq_l0(auStack40,uVar12);
  __psq_l1(auStack40,uVar12);
  __psq_l0(auStack56,uVar12);
  __psq_l1(auStack56,uVar12);
  __psq_l0(auStack72,uVar12);
  __psq_l1(auStack72,uVar12);
  __psq_l0(auStack88,uVar12);
  __psq_l1(auStack88,uVar12);
  return PVar5;
}


/* __thiscall daGrid_c::_delete(void) */

undefined4 __thiscall daGrid_c::_delete(daGrid_c *this)

{
  d_com_inf_game::dComIfG_resDelete((request_of_phase_process_class *)(this + 0x290),"Cloth");
  d_com_inf_game::dComIfG_resDelete((request_of_phase_process_class *)(this + 0x298),"Ship");
  if (-1 < DAT_803e4168) {
    mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e4168);
    DAT_803e4168 = -1;
  }
  return 1;
}


/* __thiscall daGrid_c::_execute(void) */

undefined4 __thiscall daGrid_c::_execute(daGrid_c *this)

{
  daGrid_c dVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  float fVar7;
  cXyz cStack68;
  cXyz local_38;
  cXyz local_2c;
  undefined4 local_20;
  uint uStack28;
  undefined4 local_18;
  uint uStack20;
  longlong local_10;
  
  dVar1 = this[0x1b43];
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
    dCamera_c::Eye(&local_38,
                   &(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mBody);
    local_2c.x = local_38.x;
    local_2c.y = local_38.y;
    local_2c.z = local_38.z;
    ::cXyz::operator__(&cStack68,(cXyz *)(this + 0x1f8),&local_2c);
    fVar7 = mtx::PSVECSquareMag(&cStack68);
    dVar6 = (double)fVar7;
    if ((double)d_a_grid::_4151 < dVar6) {
      dVar5 = 1.0 / SQRT(dVar6);
      dVar5 = d_a_grid::_4769 * dVar5 * (d_a_grid::_4770 - dVar6 * dVar5 * dVar5);
      dVar5 = d_a_grid::_4769 * dVar5 * (d_a_grid::_4770 - dVar6 * dVar5 * dVar5);
      dVar6 = (double)(float)(dVar6 * d_a_grid::_4769 * dVar5 *
                                      (d_a_grid::_4770 - dVar6 * dVar5 * dVar5));
    }
    if (dVar6 <= (double)DAT_803e4198) {
      fVar7 = (float)(dVar6 / (double)DAT_803e4198);
      uStack28 = (uint)DAT_803e4194;
      local_20 = 0x43300000;
      uStack20 = (uint)DAT_803e4195;
      local_18 = 0x43300000;
      uVar2 = (uint)((float)((double)CONCAT44(0x43300000,uStack28) - d_a_grid::_5098) * fVar7 +
                    (float)((double)CONCAT44(0x43300000,uStack20) - d_a_grid::_5098) *
                    (d_a_grid::_4129 - fVar7));
      local_10 = (longlong)(int)uVar2;
    }
    else {
      uVar2 = (uint)DAT_803e4194;
    }
  }
  else {
    uVar2 = (uint)DAT_803e4194;
  }
  uVar3 = (byte)dVar1 + 5;
  if (uVar3 < (uVar2 & 0xff)) {
    this[0x1b43] = SUB41(uVar3,0);
  }
  else {
    iVar4 = (byte)dVar1 - 5;
    if ((int)(uVar2 & 0xff) < iVar4) {
      this[0x1b43] = SUB41(iVar4,0);
    }
    else {
      this[0x1b43] = SUB41(uVar2,0);
    }
  }
  if (d_a_grid::_5096 <= *(float *)(this + 0x218)) {
    d_a_grid::ho_move(this);
  }
  return 1;
}


/* __thiscall daGrid_c::_draw(void) */

undefined4 __thiscall daGrid_c::_draw(daGrid_c *this)

{
  int iVar1;
  undefined4 uVar2;
  J3DDrawBuffer *this_00;
  
  iVar1 = d_a_grid::l_ship;
  if (d_a_grid::_5096 <= *(float *)(this + 0x218)) {
    *(undefined4 *)(this + 0x10c) = *(undefined4 *)(d_a_grid::l_ship + 0x10c);
    *(undefined4 *)(this + 0x110) = *(undefined4 *)(iVar1 + 0x110);
    *(undefined4 *)(this + 0x114) = *(undefined4 *)(iVar1 + 0x114);
    *(undefined4 *)(this + 0x118) = *(undefined4 *)(iVar1 + 0x118);
    *(undefined4 *)(this + 0x11c) = *(undefined4 *)(iVar1 + 0x11c);
    *(undefined4 *)(this + 0x120) = *(undefined4 *)(iVar1 + 0x120);
    this[0x124] = *(daGrid_c *)(iVar1 + 0x124);
    this[0x125] = *(daGrid_c *)(iVar1 + 0x125);
    this[0x126] = *(daGrid_c *)(iVar1 + 0x126);
    this[0x127] = *(daGrid_c *)(iVar1 + 0x127);
    *(undefined4 *)(this + 0x128) = *(undefined4 *)(iVar1 + 0x128);
    *(undefined4 *)(this + 300) = *(undefined4 *)(iVar1 + 300);
    *(undefined4 *)(this + 0x130) = *(undefined4 *)(iVar1 + 0x130);
    *(undefined4 *)(this + 0x134) = *(undefined4 *)(iVar1 + 0x134);
    *(undefined4 *)(this + 0x138) = *(undefined4 *)(iVar1 + 0x138);
    *(undefined4 *)(this + 0x13c) = *(undefined4 *)(iVar1 + 0x13c);
    *(undefined4 *)(this + 0x180) = *(undefined4 *)(iVar1 + 0x180);
    *(undefined4 *)(this + 0x184) = *(undefined4 *)(iVar1 + 0x184);
    *(undefined4 *)(this + 0x188) = *(undefined4 *)(iVar1 + 0x188);
    uVar2 = *(undefined4 *)(iVar1 + 400);
    *(undefined4 *)(this + 0x18c) = *(undefined4 *)(iVar1 + 0x18c);
    *(undefined4 *)(this + 400) = uVar2;
    *(undefined4 *)(this + 0x194) = *(undefined4 *)(iVar1 + 0x194);
    *(undefined4 *)(this + 0x198) = *(undefined4 *)(iVar1 + 0x198);
    uVar2 = *(undefined4 *)(iVar1 + 0x1a0);
    *(undefined4 *)(this + 0x19c) = *(undefined4 *)(iVar1 + 0x19c);
    *(undefined4 *)(this + 0x1a0) = uVar2;
    *(undefined4 *)(this + 0x1a4) = *(undefined4 *)(iVar1 + 0x1a4);
    *(undefined4 *)(this + 0x1a8) = *(undefined4 *)(iVar1 + 0x1a8);
    *(undefined4 *)(this + 0x1ac) = *(undefined4 *)(iVar1 + 0x1ac);
    this[0x1b0] = *(daGrid_c *)(iVar1 + 0x1b0);
    this[0x1b1] = *(daGrid_c *)(iVar1 + 0x1b1);
    this[0x1b2] = *(daGrid_c *)(iVar1 + 0x1b2);
    this[0x1b3] = *(daGrid_c *)(iVar1 + 0x1b3);
    this[0x1b4] = *(daGrid_c *)(iVar1 + 0x1b4);
    this[0x1b5] = *(daGrid_c *)(iVar1 + 0x1b5);
    this[0x1b6] = *(daGrid_c *)(iVar1 + 0x1b6);
    this[0x1b7] = *(daGrid_c *)(iVar1 + 0x1b7);
    this[0x1b8] = *(daGrid_c *)(iVar1 + 0x1b8);
    SComponent::MtxTrans
              ((double)*(float *)(this + 0x1f8),(double)*(float *)(this + 0x1fc),
               (double)*(float *)(this + 0x200),false);
    m_Do_mtx::mDoMtx_YrotM(SComponent::calc_mtx,*(short *)(this + 0x206));
    m_Do_mtx::mDoMtx_XrotM(SComponent::calc_mtx,*(short *)(this + 0x204));
    m_Do_mtx::mDoMtx_ZrotM(SComponent::calc_mtx,*(short *)(this + 0x208));
    m_Do_mtx::mDoMtx_YrotM(SComponent::calc_mtx,*(short *)(d_a_grid::l_ship + 0x364));
    SComponent::MtxScale
              ((double)d_a_grid::_4129,(double)*(float *)(this + 0x218),(double)d_a_grid::_4129,1);
    SComponent::MtxScale((double)DAT_803e4188,(double)DAT_803e418c,(double)DAT_803e4190,1);
    mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,SComponent::calc_mtx,(MTX34 *)(this + 800));
    *(daGrid_c **)(this + 0x350) = this + 0x10c;
    this_00 = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
    if (mDoGph_gInf_c::mMonotone != 0) {
      this_00 = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x10;
    }
    this_00->mpNodeMtx = SComponent::calc_mtx;
    J3DDrawBuffer::entryZSort(this_00,(J3DMatPacket *)(this + 0x2a0));
  }
  return 1;
}


/* __thiscall J3DMatPacket::entry(J3DDrawBuffer *) */

void __thiscall J3DMatPacket::entry(J3DMatPacket *this,J3DDrawBuffer *param_1)

{
  int iVar1;
  PTMF local_18 [2];
  
  iVar1 = param_1->mSortType;
  local_18[0].this_delta = *(int *)(&J3DDrawBuffer::sortFuncTable + iVar1 * 0xc);
  local_18[0].vtbl_offset = (&DAT_8039e974)[iVar1 * 3];
  local_18[0].func = (undefined *)(&DAT_8039e978)[iVar1 * 3];
  Runtime.PPCEABI.H::__ptmf_scall(local_18,param_1,this);
  return;
}


namespace d_a_grid {

void __sinit_d_a_grid_cpp(void)

{
  l_HIO = &::daHo_HIO_c::__vt;
  DAT_803e4168 = 0xff;
  DAT_803e4169 = 1;
  DAT_803e416b = 0;
  DAT_803e4178 = _5023;
  DAT_803e416a = 0;
  DAT_803e416c = 0;
  DAT_803e417c = _4130;
  DAT_803e4180 = _4763;
  DAT_803e4170 = _4763;
  DAT_803e4184 = _5152;
  DAT_803e4188 = _4129;
  DAT_803e418c = _4129;
  DAT_803e4190 = _4129;
  DAT_803e4194 = 0xff;
  DAT_803e4195 = 0x32;
  DAT_803e4198 = _4336;
  DAT_803e419c = 0;
  DAT_803e419d = 0;
  DAT_803e41d4 = _4129;
  DAT_803e41d8 = _5153;
  DAT_803e41dc = _5154;
  DAT_803e41e0 = _5152;
  DAT_803e41e4 = _5155;
  DAT_803e41e8 = _5152;
  DAT_803e41ec = _5154;
  DAT_803e41f0 = _5152;
  DAT_803e41f4 = _5155;
  DAT_803e41f8 = _4130;
  DAT_803e41fc = _4767;
  DAT_803e4200 = _4129;
  DAT_803e4204 = _4129;
  DAT_803e41a0 = _4764;
  DAT_803e41a4 = _4421;
  DAT_803e41a8 = _5156;
  DAT_803e41ac = _5157;
  DAT_803e41b0 = _5158;
  DAT_803e41b4 = _5157;
  DAT_803e41b8 = _5155;
  DAT_803e41bc = _5157;
  DAT_803e41c0 = _5159;
  DAT_803e41c4 = _5156;
  DAT_803e41c8 = _5156;
  DAT_803e41cc = _4763;
  DAT_803e41d0 = _4151;
  Runtime.PPCEABI.H::__register_global_object(&l_HIO,::daHo_HIO_c::_daHo_HIO_c,&_4099);
  return;
}

}

/* __thiscall daHo_HIO_c::~daHo_HIO_c(void) */

void __thiscall daHo_HIO_c::_daHo_HIO_c(daHo_HIO_c *this)

{
  short in_r4;
  
  if (this != (daHo_HIO_c *)0x0) {
    *(undefined1 **)this = &__vt;
    this[4] = (daHo_HIO_c)0xff;
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall daHo_packet_c::~daHo_packet_c(void) */

void __thiscall daHo_packet_c::_daHo_packet_c(daHo_packet_c *this)

{
  short in_r4;
  
  if (this != (daHo_packet_c *)0x0) {
    *(undefined **)this = &__vt;
    Runtime.PPCEABI.H::__destroy_arr(this + 0x10a4,::cXyz::_cXyz,0xc,0xaa);
    Runtime.PPCEABI.H::__destroy_arr(this + 0x8ac,::cXyz::_cXyz,0xc,0xaa);
    Runtime.PPCEABI.H::__destroy_arr(this + 0xb4,::cXyz::_cXyz,0xc,0xaa);
    J3DShapePacket::_J3DShapePacket((J3DShapePacket *)(this + 0x3c));
    J3DMatPacket::_J3DMatPacket((J3DMatPacket *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dCamera_c::Eye(void) */

cXyz * __thiscall dCamera_c::Eye(cXyz *__return_storage_ptr__,dCamera_c *this)

{
  cXyz *pcVar1;
  
  pcVar1 = ::cXyz::operator__(__return_storage_ptr__,&this->mEye,&this->mEyeShake);
  return pcVar1;
}

