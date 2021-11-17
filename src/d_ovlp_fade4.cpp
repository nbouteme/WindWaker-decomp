#include <d_ovlp_fade4.h>
#include <d_ovlp_fade4.h>
#include <gx/GXTexture.h>
#include <gx/GXFrameBuf.h>
#include <gx/GXMisc.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <gx/GXAttr.h>
#include <gx/GXLight.h>
#include <gx/GXTev.h>
#include <gx/GXPixel.h>
#include <gx/GXGeometry.h>
#include <gx/GXTransform.h>
#include <d_drawlist.h>
#include <d_a_arrow.h>
#include <f_op_overlap_mng.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <JKernel/JKRHeap.h>
#include <dOvlpFd4_c.h>
#include <dDlst_2Dt_Sp_c.h>
#include <dDlst_2DtEff1_c.h>
#include <dDlst_snapShot2_c.h>


/* __thiscall dDlst_2DtEff1_c::init(_GXColor) */

int __thiscall dDlst_2DtEff1_c::init(dDlst_2DtEff1_c *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  *(ResTIMG **)(this + 0x10) = mDoGph_gInf_c::mFrameBufferTex;
  *(undefined2 *)(this + 0x14) = 0x280;
  *(undefined2 *)(this + 0x16) = 0x1e0;
  dDlst_2Dt_Sp_c::init
            ((dDlst_2Dt_Sp_c *)(this + 0x18),(EVP_PKEY_CTX *)mDoGph_gInf_c::mFrameBufferTimg);
  *(ResTIMG **)(this + 0x68) = mDoGph_gInf_c::mFrameBufferTex;
  *(undefined2 *)(this + 0x6c) = 0x280;
  *(undefined2 *)(this + 0x6e) = 0x1e0;
  dDlst_2Dt_Sp_c::init
            ((dDlst_2Dt_Sp_c *)(this + 0x70),(EVP_PKEY_CTX *)mDoGph_gInf_c::mFrameBufferTimg);
  *(ResTIMG **)(this + 0xc0) = mDoGph_gInf_c::mFrameBufferTex;
  *(undefined2 *)(this + 0xc4) = 0x280;
  *(undefined2 *)(this + 0xc6) = 0x1e0;
  iVar1 = dDlst_2Dt_Sp_c::init
                    ((dDlst_2Dt_Sp_c *)(this + 200),(EVP_PKEY_CTX *)mDoGph_gInf_c::mFrameBufferTimg)
  ;
  return iVar1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x802246ac) */
/* __thiscall dDlst_2DtEff1_c::draw(void) */

void __thiscall dDlst_2DtEff1_c::draw(dDlst_2DtEff1_c *this)

{
  float fVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined8 in_f31;
  double dVar8;
  double local_38;
  double local_30;
  undefined auStack8 [8];
  
  fVar1 = d_ovlp_fade4::_4043;
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  *(short *)(this + 0x114) = 0x140 - (short)((int)(d_ovlp_fade4::_4043 * *(float *)(this + 4)) << 4)
  ;
  *(short *)(this + 0x116) = (short)(int)(fVar1 * *(float *)(this + 4)) * -0xc + 0xf0;
  if (this[8] == (dDlst_2DtEff1_c)0x0) {
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 == 0) {
      uVar2 = gx::GXGetTexObjData(&mDoGph_gInf_c::mZbufferTexObj);
      *(undefined4 *)(this + 0x98) = uVar2;
      uVar2 = gx::GXGetTexObjData(&mDoGph_gInf_c::mZbufferTexObj);
      *(undefined4 *)(this + 0xf0) = uVar2;
      uVar5 = 0xf0;
      uVar6 = 0x140;
      dVar8 = d_ovlp_fade4::_4046;
      while( true ) {
        uVar4 = uVar6 - 0x10;
        uVar3 = uVar5 - 0xc;
        if (((int)uVar4 < (int)(uint)*(ushort *)(this + 0x114)) ||
           ((int)uVar3 < (int)(uint)*(ushort *)(this + 0x116))) break;
        *(int *)(this + 0x9c) = (int)uVar6 >> 1;
        *(int *)(this + 0xa0) = (int)uVar5 >> 1;
        local_30 = (double)CONCAT44(0x43300000,uVar4 ^ 0x80000000);
        *(float *)(this + 0xac) = (float)(local_30 - dVar8);
        local_38 = (double)CONCAT44(0x43300000,uVar3 ^ 0x80000000);
        *(float *)(this + 0xb0) = (float)(local_38 - dVar8);
        (**(code **)(*(int *)(this + 0x70) + 0xc))(this + 0x70);
        *(short *)(this + 0xc4) = (short)uVar4;
        *(short *)(this + 0xc6) = (short)uVar3;
        (**(code **)(*(int *)(this + 0xbc) + 0xc))(this + 0xbc);
        *(ResTIMG **)(this + 0x98) = mDoGph_gInf_c::mFrameBufferTex;
        *(ResTIMG **)(this + 0xf0) = mDoGph_gInf_c::mFrameBufferTex;
        uVar5 = uVar3;
        uVar6 = uVar4;
      }
      *(int *)(this + 0xf4) = (int)uVar6 >> 1;
      *(int *)(this + 0xf8) = (int)uVar5 >> 1;
      fVar1 = d_ovlp_fade4::_4004;
      *(float *)(this + 0xfc) = d_ovlp_fade4::_4004;
      *(float *)(this + 0x100) = fVar1;
      (**(code **)(*(int *)(this + 200) + 0xc))(this + 200);
    }
  }
  else {
    (**(code **)(*(int *)(this + 0xc) + 0xc))(this + 0xc);
    (**(code **)(*(int *)(this + 0x18) + 0xc))(this + 0x18);
    (**(code **)(*(int *)(this + 100) + 0xc))(this + 100);
    (**(code **)(*(int *)(this + 0x70) + 0xc))(this + 0x70);
    (**(code **)(*(int *)(this + 0xbc) + 0xc))(this + 0xbc);
    (**(code **)(*(int *)(this + 200) + 0xc))(this + 200);
    this[8] = (dDlst_2DtEff1_c)0x0;
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return;
}


/* __thiscall dDlst_snapShot2_c::draw(void) */

void __thiscall dDlst_snapShot2_c::draw(dDlst_snapShot2_c *this)

{
  gx::GXSetCopyFilter(0,0,0,0);
  gx::GXSetTexCopySrc(0,0,*(undefined2 *)(this + 8),*(undefined2 *)(this + 10));
  gx::GXSetTexCopyDst(*(ushort *)(this + 8) >> 1,*(ushort *)(this + 10) >> 1,6,1);
  gx::GXCopyTex(*(undefined4 *)(this + 4),0);
  gx::GXPixModeSync();
  return;
}


namespace d_ovlp_fade4 {

/* __stdcall dDlst_setResTimgObj(ResTIMG const *,
                                 _GXTexObj *,
                                 void *,
                                 unsigned long,
                                 unsigned long) */

undefined4
dDlst_setResTimgObj
          (_GXTexFmt *param_1,GXTexObj *param_2,void *param_3,uint param_4,uint param_5)

{
  uint uVar1;
  ulong uVar2;
  
  if (param_1[8] == GX_TF_I4) {
    uVar1 = param_1[0x18] ^ 1;
    gx::GXInitTexObj(param_2,param_3,param_4 & 0xffff,param_5 & 0xffff,*param_1,param_1[6],
                     param_1[7],SUB41(((int)uVar1 >> 1) - (uVar1 & param_1[0x18]) >> 0x1f,0));
  }
  else {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_ovlp_fade4.cpp",0xd9,"0");
    m_Do_printf::OSPanic("d_ovlp_fade4.cpp",0xd9,&DAT_803624cb);
  }
  gx::GXInitTexObjLOD((double)(_4061 * (float)((double)CONCAT44(0x43300000,
                                                                (int)(char)param_1[0x16] ^
                                                                0x80000000) - _4046)),
                      (double)(_4061 * (float)((double)CONCAT44(0x43300000,
                                                                (int)(char)param_1[0x17] ^
                                                                0x80000000) - _4046)),
                      (double)(_4062 * (float)((double)CONCAT44(0x43300000,
                                                                (int)*(short *)(param_1 + 0x1a) ^
                                                                0x80000000) - _4046)),param_2,
                      param_1[0x14],param_1[0x15],param_1[0x12],param_1[0x11],param_1[0x13]);
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x8022499c) */
/* WARNING: Removing unreachable block (ram,0x802249a4) */
/* __stdcall cnvAddress(float,
                        float,
                        float *,
                        float *) */

void cnvAddress(double param_1,double param_2,float *param_3,float *param_4)

{
  double dVar1;
  ulong uVar2;
  undefined4 uVar3;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (param_3 == (float *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_ovlp_fade4.cpp",0x11a,"x2 != 0");
    m_Do_printf::OSPanic("d_ovlp_fade4.cpp",0x11a,&DAT_803624cb);
  }
  if (param_4 == (float *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_ovlp_fade4.cpp",0x11b,"y2 != 0");
    m_Do_printf::OSPanic("d_ovlp_fade4.cpp",0x11b,&DAT_803624cb);
  }
  dVar1 = _4046;
  *param_3 = (float)((double)_4075 +
                    (double)(float)((double)CONCAT44(0x43300000,
                                                     (int)(_4076 * (float)(param_1 - (double)_4075))
                                                     ^ 0x80000000) - _4046));
  *param_4 = (float)((double)_4077 +
                    (double)(float)((double)CONCAT44(0x43300000,
                                                     (int)(_4078 * (float)(param_2 - (double)_4077))
                                                     ^ 0x80000000) - dVar1));
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return;
}

}

/* WARNING: Removing unreachable block (ram,0x80224ca0) */
/* WARNING: Removing unreachable block (ram,0x80224ca8) */
/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall dDlst_2Dt_Sp_c::draw(void) */

void __thiscall dDlst_2Dt_Sp_c::draw(dDlst_2Dt_Sp_c *this)

{
  int iVar1;
  uint3 uVar2;
  undefined4 uVar3;
  undefined8 in_f30;
  double dVar4;
  undefined8 in_f31;
  double dVar5;
  _GXColor local_48;
  _GXColor local_44;
  _GXColor local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  longlong local_30;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  d_ovlp_fade4::dDlst_setResTimgObj
            (mDoGph_gInf_c::mFrameBufferTimg,this + 4,*(undefined4 *)(this + 0x28),
             *(undefined4 *)(this + 0x2c),*(undefined4 *)(this + 0x30));
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGB,GX_F32,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGB565,0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
  gx::GXLoadTexObj((GXTexObj *)(this + 4),0);
  gx::GXSetNumChans(0);
  local_40 = *(_GXColor *)(this + 0x44);
  gx::GXSetTevColor(GX_TEVREG0,&local_40);
  iVar1 = (int)(d_ovlp_fade4::_4114 * *(float *)(this + 0x48));
  local_30 = (longlong)iVar1;
  uVar2 = CONCAT12((byte)iVar1,local_34._2_2_);
  local_34._2_2_ = local_34._2_2_ & 0xff | (ushort)(byte)iVar1 << 8;
  local_34 = (_GXColor)(iVar1 << 0x18 | uVar2 & 0xffff0000 | (uint)local_34._2_2_);
  local_44 = local_34;
  gx::GXSetTevColor(GX_TEVREG1,&local_44);
  gx::GXSetNumTexGens(1);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetNumTevStages(1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_TEXC,GX_CC_C0,GX_CC_C1,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevKAlphaSel(0,0);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_KONST);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetZCompLoc(0);
  gx::GXSetZMode(false,GX_ALWAYS,false);
  gx::GXSetBlendMode(GX_BM_NONE,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_CLEAR);
  gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
  local_48 = d_com_inf_game::g_clearColor;
  gx::GXSetFog(GX_FOG_NONE,d_ovlp_fade4::_4004,d_ovlp_fade4::_4004,d_ovlp_fade4::_4004,
               d_ovlp_fade4::_4004,&local_48);
  gx::GXSetCullMode(0);
  gx::GXSetDither(0);
  gx::GXSetClipMode(true);
  gx::GXLoadPosMtxImm(&m_Do_mtx::g_mDoMtx_identity,0);
  gx::GXSetCurrentMtx(0);
  d_ovlp_fade4::cnvAddress
            ((double)*(float *)(this + 0x34),(double)*(float *)(this + 0x38),&local_38,&local_3c);
  local_38 = d_ovlp_fade4::_4115;
  local_3c = d_ovlp_fade4::_4116;
  dVar5 = (double)(d_ovlp_fade4::_4115 + d_ovlp_fade4::_4076 * *(float *)(this + 0x3c));
  dVar4 = (double)(d_ovlp_fade4::_4116 + d_ovlp_fade4::_4117 * *(float *)(this + 0x40));
  gx::GXBegin(0x80,0,4);
  write_volatile_4(0xcc008000,local_38);
  write_volatile_4(0xcc008000,local_3c);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_4(0xcc008000,(float)dVar5);
  write_volatile_4(0xcc008000,local_3c);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_4(0xcc008000,(float)dVar5);
  write_volatile_4(0xcc008000,(float)dVar4);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_4(0xcc008000,local_38);
  write_volatile_4(0xcc008000,(float)dVar4);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,1);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80224d94) */
/* WARNING: Removing unreachable block (ram,0x80224d84) */
/* WARNING: Removing unreachable block (ram,0x80224d8c) */
/* WARNING: Removing unreachable block (ram,0x80224d9c) */
/* __thiscall dDlst_2Dt_Sp_c::init(ResTIMG *,
                                   float,
                                   float,
                                   float,
                                   float,
                                   _GXColor) */

int __thiscall dDlst_2Dt_Sp_c::init(dDlst_2Dt_Sp_c *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  dDlst_2Dt_Sp_c *in_r5;
  undefined4 uVar2;
  double in_f1;
  double in_f2;
  double in_f3;
  double in_f4;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  *(uint *)(this + 0x2c) = (uint)*(ushort *)(ctx + 2);
  *(uint *)(this + 0x30) = (uint)*(ushort *)(ctx + 4);
  *(EVP_PKEY_CTX **)(this + 0x24) = ctx;
  *(int *)(this + 0x28) = *(int *)(this + 0x24) + *(int *)(*(int *)(this + 0x24) + 0x1c);
  iVar1 = d_ovlp_fade4::dDlst_setResTimgObj
                    (*(undefined4 *)(this + 0x24),this + 4,*(undefined4 *)(this + 0x28),
                     *(undefined4 *)(this + 0x2c),*(undefined4 *)(this + 0x30));
  *(float *)(this + 0x34) = (float)in_f1;
  *(float *)(this + 0x38) = (float)in_f2;
  *(float *)(this + 0x3c) = (float)in_f3;
  *(float *)(this + 0x40) = (float)in_f4;
  this[0x44] = *in_r5;
  this[0x45] = in_r5[1];
  this[0x46] = in_r5[2];
  this[0x47] = in_r5[3];
  *(float *)(this + 0x48) = d_ovlp_fade4::_4004;
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  __psq_l0(auStack56,uVar2);
  __psq_l1(auStack56,uVar2);
  return iVar1;
}


/* __thiscall dOvlpFd4_c::dOvlpFd4_c(void) */

void __thiscall dOvlpFd4_c::dOvlpFd4_c(dOvlpFd4_c *this)

{
  undefined4 uVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  *(undefined ***)(this + 0xe4) = &dDlst_base_c::__vt;
  *(undefined1 **)(this + 0xe4) = &dDlst_snapShot2_c::__vt;
  *(undefined ***)(this + 0xf0) = &dDlst_base_c::__vt;
  *(undefined1 **)(this + 0xf0) = &dDlst_snapShot2_c::__vt;
  *(undefined ***)(this + 0xfc) = &dDlst_base_c::__vt;
  *(undefined1 **)(this + 0xfc) = &dDlst_2Dt_Sp_c::__vt;
  *(undefined ***)(this + 0x148) = &dDlst_base_c::__vt;
  *(undefined1 **)(this + 0x148) = &dDlst_2Dt_Sp_c::__vt;
  *(undefined ***)(this + 0x194) = &dDlst_base_c::__vt;
  *(undefined1 **)(this + 0x194) = &dDlst_2DtEff1_c::__vt;
  *(undefined ***)(this + 0x1a0) = &dDlst_base_c::__vt;
  *(undefined1 **)(this + 0x1a0) = &dDlst_snapShot2_c::__vt;
  *(undefined ***)(this + 0x1ac) = &dDlst_base_c::__vt;
  *(undefined1 **)(this + 0x1ac) = &dDlst_2Dt_Sp_c::__vt;
  *(undefined ***)(this + 0x1f8) = &dDlst_base_c::__vt;
  *(undefined1 **)(this + 0x1f8) = &dDlst_snapShot2_c::__vt;
  *(undefined ***)(this + 0x204) = &dDlst_base_c::__vt;
  *(undefined1 **)(this + 0x204) = &dDlst_2Dt_Sp_c::__vt;
  *(undefined ***)(this + 0x250) = &dDlst_base_c::__vt;
  *(undefined1 **)(this + 0x250) = &dDlst_snapShot2_c::__vt;
  *(undefined ***)(this + 0x25c) = &dDlst_base_c::__vt;
  *(undefined1 **)(this + 0x25c) = &dDlst_2Dt_Sp_c::__vt;
  this[0x2ac] = (dOvlpFd4_c)0x1;
  uVar1 = DAT_80393e94;
  *(undefined4 *)(this + 0xcc) = d_ovlp_fade4::_4129;
  *(undefined4 *)(this + 0xd0) = uVar1;
  *(undefined **)(this + 0xd4) = PTR_execFirstSnap_80393e98;
  uVar1 = DAT_80393ea0;
  *(undefined4 *)(this + 0xd8) = d_ovlp_fade4::_4131;
  *(undefined4 *)(this + 0xdc) = uVar1;
  *(undefined **)(this + 0xe0) = PTR_drawFadeOut_80393ea4;
  if (*(short *)(this + 8) == 0x12) {
    local_18 = d_com_inf_game::g_saftyWhiteColor;
    dDlst_2Dt_Sp_c::init
              ((dDlst_2Dt_Sp_c *)(this + 0xfc),(EVP_PKEY_CTX *)mDoGph_gInf_c::mFrameBufferTimg);
  }
  else {
    local_20 = d_ovlp_fade4::_4138;
    local_1c = d_ovlp_fade4::_4138;
    dDlst_2Dt_Sp_c::init
              ((dDlst_2Dt_Sp_c *)(this + 0xfc),(EVP_PKEY_CTX *)mDoGph_gInf_c::mFrameBufferTimg);
  }
  local_24 = d_com_inf_game::g_whiteColor;
  dDlst_2Dt_Sp_c::init
            ((dDlst_2Dt_Sp_c *)(this + 0x148),(EVP_PKEY_CTX *)mDoGph_gInf_c::mFrameBufferTimg);
  *(ResTIMG **)(this + 0xe8) = mDoGph_gInf_c::mFrameBufferTex;
  *(undefined2 *)(this + 0xec) = 0x280;
  *(undefined2 *)(this + 0xee) = 0x1e0;
  *(ResTIMG **)(this + 0xf4) = mDoGph_gInf_c::mFrameBufferTex;
  *(undefined2 *)(this + 0xf8) = 0x280;
  *(undefined2 *)(this + 0xfa) = 0x1e0;
  local_28 = d_com_inf_game::g_saftyWhiteColor;
  dDlst_2DtEff1_c::init((dDlst_2DtEff1_c *)(this + 0x194),(EVP_PKEY_CTX *)&local_28);
  d_com_inf_game::g_dComIfG_gameInfo._23577_1_ = 0;
  *(undefined2 *)(this + 0x2b0) = 2;
  this[0x2ae] = (dOvlpFd4_c)0x27;
  *(float *)(this + 0x2b4) = d_ovlp_fade4::_4004;
  this[0x2ad] = (dOvlpFd4_c)0x0;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dOvlpFd4_c::drawFadeOut(void) */

void __thiscall dOvlpFd4_c::drawFadeOut(dOvlpFd4_c *this)

{
  if (this[0x2ac] == (dOvlpFd4_c)0x0) {
    if (this[0x2ad] == (dOvlpFd4_c)0x1) {
      dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                        &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x224,
                        &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x228,
                        (dDlst_base_c *)(this + 0x148));
      dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                        &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x224,
                        &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x228,
                        (dDlst_base_c *)(this + 0xe4));
    }
  }
  else {
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x224,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x228,
                      (dDlst_base_c *)(this + 0xf0));
    this[0x2ac] = (dOvlpFd4_c)0x0;
  }
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x224,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x228,
                    (dDlst_base_c *)(this + 0xfc));
  return;
}


/* __thiscall dOvlpFd4_c::drawFadeIn(void) */

void __thiscall dOvlpFd4_c::drawFadeIn(dOvlpFd4_c *this)

{
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x224,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x228,
                    (dDlst_base_c *)(this + 0x194));
  return;
}


/* __thiscall dOvlpFd4_c::execFirstSnap(void) */

void __thiscall dOvlpFd4_c::execFirstSnap(dOvlpFd4_c *this)

{
  float fVar1;
  undefined4 uVar2;
  short sVar4;
  uint uVar3;
  double local_18;
  double local_10;
  
  if ((this[0x2ac] == (dOvlpFd4_c)0x0) &&
     (sVar4 = d_a_arrow::cLib_calcTimer(this + 0x2b0), uVar2 = DAT_80393eac, sVar4 == 0)) {
    *(undefined4 *)(this + 0xcc) = d_ovlp_fade4::_4276;
    *(undefined4 *)(this + 0xd0) = uVar2;
    *(undefined **)(this + 0xd4) = PTR_execFadeOut_80393eb0;
    f_op_overlap_mng::fopOvlpM_Done(this);
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 = 0;
    this[0x2ad] = (dOvlpFd4_c)0x1;
    uVar3 = SEXT14((char)this[0x2ae]);
    if ((int)uVar3 < 0x50) {
      local_18 = (double)CONCAT44(0x43300000,uVar3 ^ 0x80000000);
      fVar1 = d_ovlp_fade4::_4289 / (float)(local_18 - d_ovlp_fade4::_4046);
      *(float *)(this + 700) = d_ovlp_fade4::_4004;
      this[0x2c0] = SUB41((int)(fVar1 * d_ovlp_fade4::_4290) << 4,0);
    }
    else {
      local_18 = (double)CONCAT44(0x43300000,uVar3 - 0x4f ^ 0x80000000);
      *(float *)(this + 700) = (float)(local_18 - d_ovlp_fade4::_4046) / d_ovlp_fade4::_4288;
      this[0x2c0] = (dOvlpFd4_c)0x8;
    }
    *(short *)(this + 0x2b0) = (short)(char)this[0x2ae];
    local_10 = (double)CONCAT44(0x43300000,(int)(char)this[0x2ae] ^ 0x80000000);
    this[0x2c1] = (dOvlpFd4_c)
                  ((char)this[0x2ae] -
                  (char)(int)((float)(local_10 - d_ovlp_fade4::_4046) * *(float *)(this + 0x2b4)));
  }
  return;
}


/* __thiscall dOvlpFd4_c::execFadeOut(void) */

void __thiscall dOvlpFd4_c::execFadeOut(dOvlpFd4_c *this)

{
  float fVar1;
  undefined4 uVar2;
  double dVar3;
  short sVar6;
  int iVar4;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 = 0;
  sVar6 = d_a_arrow::cLib_calcTimer(this + 0x2b0);
  if ((sVar6 == 0) &&
     (((*(ushort *)(this + 0xec) <= (ushort)(byte)this[0x2c0] ||
       (*(ushort *)(this + 0xee) <= (ushort)(byte)this[0x2c0])) &&
      (iVar4 = f_op_overlap_mng::fopOvlpM_IsOutReq(this), iVar4 != 0)))) {
    f_op_overlap_mng::fopOvlpM_SceneIsStart();
    uVar2 = DAT_80393eb8;
    *(undefined4 *)(this + 0xcc) = d_ovlp_fade4::_4301;
    *(undefined4 *)(this + 0xd0) = uVar2;
    *(undefined **)(this + 0xd4) = PTR_execNextSnap_80393ebc;
    this[0x2ad] = (dOvlpFd4_c)0x0;
    *(undefined2 *)(this + 0x2b0) = 200;
    d_com_inf_game::g_dComIfG_gameInfo._23577_1_ = 0;
  }
  else {
    uVar5 = (uint)*(ushort *)(this + 0xec);
    uVar7 = (uint)*(ushort *)(this + 0xee);
    *(uint *)(this + 0x174) = (uint)(*(ushort *)(this + 0xec) >> 1);
    *(uint *)(this + 0x178) = (uint)(*(ushort *)(this + 0xee) >> 1);
    uVar8 = (uint)(byte)this[0x2c0];
    if ((uVar8 < uVar5) && (uVar8 < uVar7)) {
      uVar5 = uVar5 - uVar8;
      uVar7 = uVar7 - uVar8;
    }
    fVar1 = d_ovlp_fade4::_4004;
    if (((int)*(short *)(this + 0x2b0) <= (int)(char)this[0x2c1]) &&
       ((uVar8 < (uVar5 & 0xffff) || (fVar1 = d_ovlp_fade4::_4340, uVar8 < (uVar7 & 0xffff))))) {
      fVar1 = d_ovlp_fade4::_4340 -
              (float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x2b0) ^ 0x80000000) -
                     d_ovlp_fade4::_4046) /
              (float)((double)CONCAT44(0x43300000,(int)(char)this[0x2c1] ^ 0x80000000) -
                     d_ovlp_fade4::_4046);
      fVar1 = fVar1 * fVar1;
    }
    *(float *)(this + 0x144) = fVar1;
    dVar3 = d_ovlp_fade4::_4343;
    *(float *)(this + 0x184) =
         (float)((double)CONCAT44(0x43300000,uVar5 & 0xffff) - d_ovlp_fade4::_4343);
    *(float *)(this + 0x188) = (float)((double)CONCAT44(0x43300000,uVar7 & 0xffff) - dVar3);
    *(short *)(this + 0xec) = (short)uVar5;
    *(short *)(this + 0xee) = (short)uVar7;
    *(uint *)(this + 0x128) = uVar5 >> 1 & 0x7fff;
    *(uint *)(this + 300) = uVar7 >> 1 & 0x7fff;
  }
  return;
}


/* __thiscall dOvlpFd4_c::execNextSnap(void) */

void __thiscall dOvlpFd4_c::execNextSnap(dOvlpFd4_c *this)

{
  float fVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_80393ec4;
  *(undefined4 *)(this + 0xcc) = d_ovlp_fade4::_4347;
  *(undefined4 *)(this + 0xd0) = uVar2;
  *(undefined **)(this + 0xd4) = PTR_execFadeIn_80393ec8;
  uVar2 = DAT_80393ed0;
  *(undefined4 *)(this + 0xd8) = d_ovlp_fade4::_4349;
  *(undefined4 *)(this + 0xdc) = uVar2;
  *(undefined **)(this + 0xe0) = PTR_drawFadeIn_80393ed4;
  this[0x19c] = (dOvlpFd4_c)0x1;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 = 1;
  *(undefined2 *)(this + 0x1a8) = 0x280;
  *(undefined2 *)(this + 0x1aa) = 0x1e0;
  *(undefined4 *)(this + 0x1d8) = 0x140;
  *(undefined4 *)(this + 0x1dc) = 0xf0;
  *(float *)(this + 0x1e8) = d_ovlp_fade4::_4075;
  *(float *)(this + 0x1ec) = d_ovlp_fade4::_4077;
  uVar2 = gx::GXGetTexObjData(&mDoGph_gInf_c::mZbufferTexObj);
  *(undefined4 *)(this + 0x1fc) = uVar2;
  *(undefined2 *)(this + 0x200) = 0x140;
  *(undefined2 *)(this + 0x202) = 0xf0;
  uVar2 = gx::GXGetTexObjData(&mDoGph_gInf_c::mZbufferTexObj);
  *(undefined4 *)(this + 0x22c) = uVar2;
  *(undefined4 *)(this + 0x230) = 0xa0;
  *(undefined4 *)(this + 0x234) = 0x78;
  fVar1 = d_ovlp_fade4::_4381;
  *(float *)(this + 0x240) = d_ovlp_fade4::_4381;
  *(float *)(this + 0x244) = fVar1;
  *(undefined2 *)(this + 600) = 0x10;
  *(undefined2 *)(this + 0x25a) = 0x10;
  fVar1 = d_ovlp_fade4::_4340;
  *(float *)(this + 0x2a4) = d_ovlp_fade4::_4340;
  *(undefined4 *)(this + 0x288) = 8;
  *(undefined4 *)(this + 0x28c) = 8;
  *(float *)(this + 0x298) = d_ovlp_fade4::_4005;
  *(float *)(this + 0x29c) = d_ovlp_fade4::_4006;
  *(short *)(this + 0x2b0) = (short)(char)this[0x2ae];
  *(float *)(this + 0x198) = fVar1;
  *(float *)(this + 0x2c8) =
       d_ovlp_fade4::_4382 /
       (float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x2b0) ^ 0x80000000) -
              d_ovlp_fade4::_4046);
  return;
}


/* __thiscall dOvlpFd4_c::execFadeIn(void) */

void __thiscall dOvlpFd4_c::execFadeIn(dOvlpFd4_c *this)

{
  short sVar1;
  
  sVar1 = d_a_arrow::cLib_calcTimer(this + 0x2b0);
  if ((sVar1 != 0) || (d_ovlp_fade4::_4004 < *(float *)(this + 0x198))) {
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 = 0;
    f_op_overlap_mng::fopOvlpM_SceneIsStop();
    *(float *)(this + 0x2a4) = *(float *)(this + 0x198) * *(float *)(this + 0x198);
    *(float *)(this + 0x198) = *(float *)(this + 0x198) + *(float *)(this + 0x2c8);
    if (*(float *)(this + 0x198) < d_ovlp_fade4::_4004) {
      *(float *)(this + 0x198) = d_ovlp_fade4::_4004;
    }
  }
  else {
    if (this[0x2cc] == (dOvlpFd4_c)0x0) {
      f_op_overlap_mng::fopOvlpM_SceneIsStart();
      this[0x2cc] = (dOvlpFd4_c)0x1;
    }
    else {
      f_op_overlap_mng::fopOvlpM_Done(this);
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 = 1;
      d_com_inf_game::g_dComIfG_gameInfo._23577_1_ = 1;
    }
  }
  return;
}


namespace d_ovlp_fade4 {

/* __stdcall dOvlpFd4_Draw(dOvlpFd4_c *) */

undefined4 dOvlpFd4_Draw(void *param_1,void *param_2)

{
  bool bVar1;
  PTMF local_18;
  
  local_18.this_delta = *(int *)((int)param_1 + 0xd8);
  local_18.vtbl_offset = *(int *)((int)param_1 + 0xdc);
  local_18.func = *(undefined **)((int)param_1 + 0xe0);
  bVar1 = Runtime.PPCEABI.H::__ptmf_test(&local_18);
  if (bVar1 != false) {
    Runtime.PPCEABI.H::__ptmf_scall((PTMF *)((int)param_1 + 0xd8),param_1,param_2);
  }
  return 1;
}


/* __stdcall dOvlpFd4_Execute(dOvlpFd4_c *) */

undefined4 dOvlpFd4_Execute(void *param_1,void *param_2)

{
  Runtime.PPCEABI.H::__ptmf_scall((PTMF *)((int)param_1 + 0xcc),param_1,param_2);
  return 1;
}


/* __stdcall dOvlpFd4_IsDelete(dOvlpFd4_c *) */

undefined4 dOvlpFd4_IsDelete(void)

{
  return 1;
}


/* __stdcall dOvlpFd4_Delete(dOvlpFd4_c *) */

undefined4 dOvlpFd4_Delete(void)

{
  return 1;
}


/* __stdcall dOvlpFd4_Create(void *) */

undefined4 dOvlpFd4_Create(dOvlpFd4_c *param_1)

{
  if (param_1 != (dOvlpFd4_c *)0x0) {
    ::dOvlpFd4_c::dOvlpFd4_c(param_1);
  }
  return 4;
}

}

/* __thiscall dDlst_2DtEff1_c::~dDlst_2DtEff1_c(void) */

void __thiscall dDlst_2DtEff1_c::_dDlst_2DtEff1_c(dDlst_2DtEff1_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2DtEff1_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_2DtEff1_c *)0xffffff38) {
      *(undefined1 **)(this + 200) = &dDlst_2Dt_Sp_c::__vt;
      if (this != (dDlst_2DtEff1_c *)0xffffff38) {
        *(undefined ***)(this + 200) = &dDlst_base_c::__vt;
      }
    }
    if (this != (dDlst_2DtEff1_c *)0xffffff44) {
      *(undefined1 **)(this + 0xbc) = &dDlst_snapShot2_c::__vt;
      if (this != (dDlst_2DtEff1_c *)0xffffff44) {
        *(undefined ***)(this + 0xbc) = &dDlst_base_c::__vt;
      }
    }
    if (this != (dDlst_2DtEff1_c *)0xffffff90) {
      *(undefined1 **)(this + 0x70) = &dDlst_2Dt_Sp_c::__vt;
      if (this != (dDlst_2DtEff1_c *)0xffffff90) {
        *(undefined ***)(this + 0x70) = &dDlst_base_c::__vt;
      }
    }
    if (this != (dDlst_2DtEff1_c *)0xffffff9c) {
      *(undefined1 **)(this + 100) = &dDlst_snapShot2_c::__vt;
      if (this != (dDlst_2DtEff1_c *)0xffffff9c) {
        *(undefined ***)(this + 100) = &dDlst_base_c::__vt;
      }
    }
    if (this != (dDlst_2DtEff1_c *)0xffffffe8) {
      *(undefined1 **)(this + 0x18) = &dDlst_2Dt_Sp_c::__vt;
      if (this != (dDlst_2DtEff1_c *)0xffffffe8) {
        *(undefined ***)(this + 0x18) = &dDlst_base_c::__vt;
      }
    }
    if ((this != (dDlst_2DtEff1_c *)0xfffffff4) &&
       (*(undefined1 **)(this + 0xc) = &dDlst_snapShot2_c::__vt,
       this != (dDlst_2DtEff1_c *)0xfffffff4)) {
      *(undefined ***)(this + 0xc) = &dDlst_base_c::__vt;
    }
    if (this != (dDlst_2DtEff1_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_2Dt_Sp_c::~dDlst_2Dt_Sp_c(void) */

void __thiscall dDlst_2Dt_Sp_c::_dDlst_2Dt_Sp_c(dDlst_2Dt_Sp_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2Dt_Sp_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_2Dt_Sp_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_snapShot2_c::~dDlst_snapShot2_c(void) */

void __thiscall dDlst_snapShot2_c::_dDlst_snapShot2_c(dDlst_snapShot2_c *this)

{
  short in_r4;
  
  if (this != (dDlst_snapShot2_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_snapShot2_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

