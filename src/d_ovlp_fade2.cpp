#include <d_ovlp_fade2.h>
#include <gx/GXTransform.h>
#include <gx/GXAttr.h>
#include <gx/GXLight.h>
#include <gx/GXTev.h>
#include <gx/GXPixel.h>
#include <gx/GXGeometry.h>
#include <mtx/mtx44.h>
#include <gx/GXTexture.h>
#include <J2DGraph/J2DOrthoGraph.h>
#include <d_ovlp_fade2.h>
#include <f_op_overlap_mng.h>
#include <m_Do_graphic.h>
#include <SComponent/c_lib.h>
#include <d_drawlist.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <JKernel/JKRHeap.h>
#include <dOvlpFd2_dlst_c.h>
#include <dOvlpFd2_c.h>
#include <dDlst_snapShot_c.h>


namespace d_ovlp_fade2 {
}

/* __thiscall dOvlpFd2_dlst_c::draw(void) */

void __thiscall dOvlpFd2_dlst_c::draw(dOvlpFd2_dlst_c *this)

{
  J2DOrthoGraph *pJVar1;
  double dVar2;
  _GXColor local_68;
  undefined4 local_64;
  undefined4 local_60;
  _GXColor local_5c;
  TBox2_float_ local_58;
  MTX44 MStack72;
  
  dVar2 = (double)d_ovlp_fade2::_4016;
  gx::GXSetViewport(dVar2,dVar2,(double)d_ovlp_fade2::_4017,(double)d_ovlp_fade2::_4018,dVar2,
                    (double)d_ovlp_fade2::_4019);
  gx::GXSetScissor(0,0,0x280,0x1e0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGB,GX_RGBA4,0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetNumChans(1);
  gx::GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  gx::GXSetNumTexGens(0);
  gx::GXSetNumTevStages(1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetZCompLoc(1);
  gx::GXSetZMode(false,GX_ALWAYS,false);
  gx::GXSetBlendMode(GX_BM_NONE,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_CLEAR);
  gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
  local_5c = d_com_inf_game::g_clearColor;
  gx::GXSetFog(GX_FOG_NONE,d_ovlp_fade2::_4016,d_ovlp_fade2::_4016,d_ovlp_fade2::_4016,
               d_ovlp_fade2::_4016,&local_5c);
  gx::GXSetCullMode(0);
  gx::GXSetDither(1);
  gx::GXSetClipMode(true);
  gx::GXLoadPosMtxImm(&m_Do_mtx::g_mDoMtx_identity,0);
  gx::GXSetCurrentMtx(0);
  gx::GXBegin(0x80,0,4);
  write_volatile_2(0xcc008000,0);
  write_volatile_2(0xcc008000,0);
  write_volatile_2(0xcc008000,0x280);
  write_volatile_2(0xcc008000,0);
  write_volatile_2(0xcc008000,0x280);
  write_volatile_2(0xcc008000,0x1e0);
  write_volatile_2(0xcc008000,0);
  write_volatile_2(0xcc008000,0x1e0);
  mtx::C_MTXPerspective
            ((double)d_ovlp_fade2::_4020,
             (double)(d_ovlp_fade2::_4021 * f_ap_game::g_HIO.aspectRatio),
             (double)d_ovlp_fade2::_4022,(double)d_ovlp_fade2::_4023,&MStack72);
  gx::GXSetProjection(&MStack72,GX_PERSPECTIVE);
  gx::GXInitTexObj(&mDoGph_gInf_c::mFrameBufferTexObj,mDoGph_gInf_c::mFrameBufferTex,0x140,0xf0,
                   GX_TF_RGBA8,GX_CLAMP,GX_CLAMP,false);
  dVar2 = (double)d_ovlp_fade2::_4016;
  gx::GXInitTexObjLOD(dVar2,dVar2,dVar2,&mDoGph_gInf_c::mFrameBufferTexObj,1,1,0,0,0);
  gx::GXLoadTexObj(&mDoGph_gInf_c::mFrameBufferTexObj,0);
  gx::GXSetNumChans(1);
  gx::GXSetChanCtrl(GX_COLOR0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  local_64 = d_ovlp_fade2::_3981;
  local_60 = d_ovlp_fade2::_3981;
  gx::GXSetChanMatColor(0,&local_60);
  gx::GXSetNumTexGens(1);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetNumTevStages(1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR0A0);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_RASC,GX_CC_TEXC,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetZCompLoc(1);
  gx::GXSetZMode(false,GX_ALWAYS,false);
  gx::GXSetBlendMode(GX_BM_NONE,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_CLEAR);
  gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
  local_68 = d_com_inf_game::g_clearColor;
  gx::GXSetFog(GX_FOG_NONE,d_ovlp_fade2::_4016,d_ovlp_fade2::_4016,d_ovlp_fade2::_4016,
               d_ovlp_fade2::_4016,&local_68);
  gx::GXSetCullMode(0);
  gx::GXSetDither(1);
  gx::GXSetClipMode(false);
  gx::GXLoadPosMtxImm((MTX34 *)(this + 4),0);
  gx::GXSetCurrentMtx(0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGB,GX_RGBA4,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGB8,0);
  gx::GXBegin(0x80,0,4);
  pJVar1 = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  write_volatile_2(0xcc008000,0xfec0);
  write_volatile_2(0xcc008000,0xf0);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_2(0xcc008000,0x140);
  write_volatile_2(0xcc008000,0xf0);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_2(0xcc008000,0x140);
  write_volatile_2(0xcc008000,0xff10);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_2(0xcc008000,0xfec0);
  write_volatile_2(0xcc008000,0xff10);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,1);
  local_58.mTL.x = d_ovlp_fade2::_4024;
  local_58.mTL.y = d_ovlp_fade2::_4025;
  local_58.mBR.x = d_ovlp_fade2::_4026;
  local_58.mBR.y = d_ovlp_fade2::_4027;
  J2DOrthoGraph::setOrtho
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph,&local_58,d_ovlp_fade2::_4028,
             d_ovlp_fade2::_4019);
  (*(code *)((pJVar1->parent).vtbl)->setup2D)(pJVar1);
  return;
}


/* __thiscall dOvlpFd2_c::dOvlpFd2_c(void) */

void __thiscall dOvlpFd2_c::dOvlpFd2_c(dOvlpFd2_c *this)

{
  undefined4 uVar1;
  
  *(undefined ***)(this + 0xd8) = &dDlst_base_c::__vt;
  *(undefined ***)(this + 0xd8) = &dDlst_snapShot_c::__vt;
  *(undefined ***)(this + 0xdc) = &dDlst_base_c::__vt;
  *(undefined ***)(this + 0xdc) = &dOvlpFd2_dlst_c::__vt;
  uVar1 = DAT_80393ddc;
  *(undefined4 *)(this + 0xcc) = d_ovlp_fade2::_4032;
  *(undefined4 *)(this + 0xd0) = uVar1;
  *(undefined **)(this + 0xd4) = PTR_execFirstSnap_80393de0;
  d_com_inf_game::g_dComIfG_gameInfo._23577_1_ = 0;
  this[0x11d] = (dOvlpFd2_c)0x2;
  return;
}


/* __thiscall dOvlpFd2_c::execFirstSnap(void) */

void __thiscall dOvlpFd2_c::execFirstSnap(dOvlpFd2_c *this)

{
  undefined4 uVar1;
  char cVar2;
  
  if (this[0x11c] != (dOvlpFd2_c)0x0) {
    cVar2 = d_ovlp_fade2::cLib_calcTimer(this + 0x11d);
    uVar1 = DAT_80393de8;
    if (cVar2 == '\0') {
      *(undefined4 *)(this + 0xcc) = d_ovlp_fade2::_4069;
      *(undefined4 *)(this + 0xd0) = uVar1;
      *(undefined **)(this + 0xd4) = PTR_execFadeOut_80393dec;
      f_op_overlap_mng::fopOvlpM_Done(this);
      this[0x11d] = (dOvlpFd2_c)0xf4;
    }
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 = 0;
    if (mDoGph_gInf_c::mMonotone != 0) {
      mDoGph_gInf_c::offMonotone();
    }
  }
  return;
}


/* __thiscall dOvlpFd2_c::execFadeOut(void) */

void __thiscall dOvlpFd2_c::execFadeOut(dOvlpFd2_c *this)

{
  short sVar1;
  undefined4 uVar2;
  dOvlpFd2_c dVar3;
  int iVar4;
  int *piVar5;
  
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 = 0;
  SComponent::cLib_chaseAngleS(this + 0x112,2000,100);
  sVar1 = *(short *)(this + 0x110);
  *(short *)(this + 0x110) = sVar1 + *(short *)(this + 0x112);
  if ((int)*(short *)(this + 0x112) *
      (int)(short)(((sVar1 + 0x4000U & 0x8000 | 0x4000) - *(short *)(this + 0x112)) -
                  *(short *)(this + 0x110)) < 0) {
    if (this[0x11d] == (dOvlpFd2_c)0x0) {
      iVar4 = f_op_overlap_mng::fopOvlpM_IsOutReq(this);
      if (iVar4 != 0) {
        f_op_overlap_mng::fopOvlpM_SceneIsStart();
        uVar2 = DAT_80393df4;
        *(undefined4 *)(this + 0xcc) = d_ovlp_fade2::_4086;
        *(undefined4 *)(this + 0xd0) = uVar2;
        *(undefined **)(this + 0xd4) = PTR_execNextSnap_80393df8;
        *(undefined2 *)(this + 0x110) = 0xc000;
        this[0x11d] = (dOvlpFd2_c)0xf;
      }
    }
  }
  if ((char)this[0x11d] < '\0') {
    dVar3 = (dOvlpFd2_c)((char)this[0x11d] + '\x01');
    this[0x11d] = dVar3;
    if (dVar3 == (dOvlpFd2_c)0x0) {
      piVar5 = (int *)JFWDisplay::sManager->mpFader;
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0x10))(piVar5,0x10);
      }
      this[0x11d] = (dOvlpFd2_c)((char)d_s_play::g_regHIO.mChild[0].mShorts[1] + '\x14');
    }
  }
  else {
    d_ovlp_fade2::cLib_calcTimer(this + 0x11d);
  }
  *(short *)(this + 0x114) =
       *(short *)(this + 0x114) + d_s_play::g_regHIO.mChild[0].mShorts[0] + 0x800;
  SComponent::cLib_addCalc2
            ((float *)(this + 0x118),d_ovlp_fade2::_4019 + d_s_play::g_regHIO.mChild[0].mFloats[1],
             d_ovlp_fade2::_4019,d_ovlp_fade2::_4107 + d_s_play::g_regHIO.mChild[0].mFloats[2]);
  return;
}


/* __thiscall dOvlpFd2_c::execNextSnap(void) */

void __thiscall dOvlpFd2_c::execNextSnap(dOvlpFd2_c *this)

{
  undefined4 uVar1;
  char cVar2;
  
  cVar2 = d_ovlp_fade2::cLib_calcTimer(this + 0x11d);
  if ((cVar2 == '\0') &&
     (cVar2 = (**(code **)(*(int *)JFWDisplay::sManager->mpFader + 0xc))
                        (JFWDisplay::sManager->mpFader,0x10), cVar2 == '\0')) {
    *(short *)(this + 0x110) = *(short *)(this + 0x110) + *(short *)(this + 0x112);
    this[0x11c] = (dOvlpFd2_c)0x0;
    uVar1 = DAT_80393e00;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 = 1;
    d_com_inf_game::g_dComIfG_gameInfo._23577_1_ = 0;
    *(undefined4 *)(this + 0xcc) = d_ovlp_fade2::_4115;
    *(undefined4 *)(this + 0xd0) = uVar1;
    *(undefined **)(this + 0xd4) = PTR_execFadeIn_80393e04;
  }
  return;
}


/* __thiscall dOvlpFd2_c::execFadeIn(void) */

void __thiscall dOvlpFd2_c::execFadeIn(dOvlpFd2_c *this)

{
  *(short *)(this + 0x114) =
       *(short *)(this + 0x114) - (d_s_play::g_regHIO.mChild[0].mShorts[0] + 0x800);
  SComponent::cLib_addCalc0
            ((float *)(this + 0x118),d_ovlp_fade2::_4019,
             d_ovlp_fade2::_4144 + d_s_play::g_regHIO.mChild[0].mFloats[3]);
  if (d_ovlp_fade2::_4145 <= *(float *)(this + 0x118)) {
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 = 0;
    f_op_overlap_mng::fopOvlpM_SceneIsStop();
  }
  else {
    if (this[0x11e] == (dOvlpFd2_c)0x0) {
      f_op_overlap_mng::fopOvlpM_SceneIsStart();
      this[0x11e] = (dOvlpFd2_c)0x1;
    }
    else {
      f_op_overlap_mng::fopOvlpM_Done(this);
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 = 1;
      d_com_inf_game::g_dComIfG_gameInfo._23577_1_ = 1;
    }
  }
  return;
}


namespace d_ovlp_fade2 {

/* __stdcall dOvlpFd2_Draw(dOvlpFd2_c *) */

undefined4 dOvlpFd2_Draw(int param_1)

{
  if (*(char *)(param_1 + 0x11c) == '\0') {
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x224,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x228,
                      (dDlst_base_c *)(param_1 + 0xd8));
    *(undefined *)(param_1 + 0x11c) = 1;
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 == 0) {
      mtx::PSMTXTrans((double)_4016,(double)_4016,
                      (double)(_4173 + d_s_play::g_regHIO.mChild[0].mFloats[0]),&mDoMtx_stack_c::now
                     );
      m_Do_mtx::mDoMtx_ZrotM(&mDoMtx_stack_c::now,*(short *)(param_1 + 0x114));
      mDoMtx_stack_c::scaleM(_4019,_4019 + *(float *)(param_1 + 0x118),_4019);
      m_Do_mtx::mDoMtx_ZrotM(&mDoMtx_stack_c::now,-*(short *)(param_1 + 0x114));
      mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(param_1 + 0xe0));
      dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                        &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x224,
                        &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x228,
                        (dDlst_base_c *)(param_1 + 0xdc));
    }
  }
  mDoGph_gInf_c::mBlureFlag = 0;
  return 1;
}


/* __stdcall dOvlpFd2_Execute(dOvlpFd2_c *) */

undefined4 dOvlpFd2_Execute(void *param_1,void *param_2)

{
  Runtime.PPCEABI.H::__ptmf_scall((PTMF *)((int)param_1 + 0xcc),param_1,param_2);
  return 1;
}


/* __stdcall dOvlpFd2_IsDelete(dOvlpFd2_c *) */

undefined4 dOvlpFd2_IsDelete(void)

{
  return 1;
}


/* __stdcall dOvlpFd2_Delete(dOvlpFd2_c *) */

undefined4 dOvlpFd2_Delete(void)

{
  return 1;
}


/* __stdcall dOvlpFd2_Create(void *) */

undefined4 dOvlpFd2_Create(dOvlpFd2_c *param_1)

{
  if (param_1 != (dOvlpFd2_c *)0x0) {
    ::dOvlpFd2_c::dOvlpFd2_c(param_1);
  }
  return 4;
}


/* __stdcall cLib_calcTimer<signed char>(signed char *) */

char cLib_calcTimer(char *param_1)

{
  if (*param_1 != '\0') {
    *param_1 = *param_1 + -1;
  }
  return *param_1;
}

}

/* __thiscall dOvlpFd2_dlst_c::~dOvlpFd2_dlst_c(void) */

void __thiscall dOvlpFd2_dlst_c::_dOvlpFd2_dlst_c(dOvlpFd2_dlst_c *this)

{
  short in_r4;
  
  if (this != (dOvlpFd2_dlst_c *)0x0) {
    *(undefined ***)this = &__vt;
    if (this != (dOvlpFd2_dlst_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_snapShot_c::~dDlst_snapShot_c(void) */

void __thiscall dDlst_snapShot_c::_dDlst_snapShot_c(dDlst_snapShot_c *this)

{
  short in_r4;
  
  if (this != (dDlst_snapShot_c *)0x0) {
    *(undefined ***)this = &__vt;
    if (this != (dDlst_snapShot_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

