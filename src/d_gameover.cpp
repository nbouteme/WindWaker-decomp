#include <d_gameover.h>
#include <gx/GXFrameBuf.h>
#include <gx/GXMisc.h>
#include <gx/GXTexture.h>
#include <gx/GXLight.h>
#include <gx/GXAttr.h>
#include <gx/GXTev.h>
#include <gx/GXPixel.h>
#include <gx/GXGeometry.h>
#include <mtx/mtx44.h>
#include <gx/GXTransform.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_com_inf_game.h>
#include <d_meter.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <m_Do_ext.h>
#include <JKernel/JKRHeap.h>
#include <d_gameover.h>
#include <d_menu_save.h>
#include <d_drawlist.h>
#include <J2DGraph/J2DPane.h>
#include <J2DGraph/J2DScreen.h>
#include <f_op_msg_mng.h>
#include <SComponent/c_math.h>
#include <d_particle.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <dDlst_GameOverScrnDraw_c.h>
#include <dMenu_save_c.h>
#include <dGameover_c.h>
#include <dDlst_Gameover_CAPTURE_c.h>
#include <dDlst_MenuSave_c.h>


namespace d_gameover {
}

namespace d_gameover {
}

/* __thiscall dDlst_Gameover_CAPTURE_c::draw(void) */

void __thiscall dDlst_Gameover_CAPTURE_c::draw(dDlst_Gameover_CAPTURE_c *this)

{
  double dVar1;
  _GXColor local_68;
  GXTexObj GStack100;
  MTX44 MStack68;
  
  gx::GXSetTexCopySrc(0,0,0x280,0x1e0);
  gx::GXSetTexCopyDst(0x140,0xf0,4,1);
  gx::GXCopyTex(mDoGph_gInf_c::mZbufferTex,0);
  gx::GXPixModeSync();
  gx::GXInitTexObj(&GStack100,mDoGph_gInf_c::mFrameBufferTex,0x140,0xf0,
                   mDoGph_gInf_c::mFrameBufferTimg->mTexFmt,GX_CLAMP,GX_CLAMP,false);
  dVar1 = (double)d_gameover::_4075;
  gx::GXInitTexObjLOD(dVar1,dVar1,dVar1,&GStack100,1,1,0,0,0);
  gx::GXLoadTexObj(&GStack100,0);
  gx::GXSetNumChans(0);
  gx::GXSetNumTexGens(1);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetNumTevStages(1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_TEXC);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetZCompLoc(1);
  gx::GXSetZMode(false,GX_ALWAYS,false);
  gx::GXSetBlendMode(GX_BM_NONE,GX_BL_ZERO,GX_BL_ZERO,GX_LO_OR);
  gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
  local_68 = d_com_inf_game::g_clearColor;
  gx::GXSetFog(GX_FOG_NONE,d_gameover::_4075,d_gameover::_4075,d_gameover::_4075,d_gameover::_4075,
               &local_68);
  gx::GXSetFogRangeAdj(false,0,(_GXFogAdjTable *)0x0);
  gx::GXSetCullMode(0);
  gx::GXSetDither(1);
  mtx::C_MTXOrtho(d_gameover::_4075,d_gameover::_4076,d_gameover::_4075,d_gameover::_4076,
                  d_gameover::_4075,d_gameover::_4077,&MStack68);
  gx::GXSetProjection(&MStack68,GX_ORTHOGRAPHIC);
  gx::GXLoadPosMtxImm(&m_Do_mtx::g_mDoMtx_identity,0);
  gx::GXSetCurrentMtx(0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGB8,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGB8,0);
  gx::GXBegin(0x80,0,4);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0xfb);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0xfb);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0xfb);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0xfb);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dGameover_c::_create(void) */

PhaseState __thiscall dGameover_c::_create(dGameover_c *this)

{
  PhaseState PVar1;
  byte bVar7;
  dRes_info_c *pdVar2;
  ulong uVar3;
  undefined4 uVar4;
  undefined **ppuVar5;
  undefined4 *puVar6;
  
  PVar1 = d_com_inf_game::dComIfG_resLoad((request_of_phase_process_class *)(this + 0x108),"Gover");
  bVar7 = d_meter::dMenu_flag();
  if ((bVar7 == 0) &&
     (((d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 0 ||
       (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 4)) &&
      (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca == 0)))) {
    if (PVar1 == cPhs_COMPLEATE_e) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo._18_2_ < 9999) {
        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo._18_2_ =
             d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo._18_2_ + 1;
      }
      pdVar2 = dRes_control_c::getResInfo
                         ("Gover",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
      if (pdVar2 == (dRes_info_c *)0x0) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar3,"d_gameover.cpp",0xa0,"resInfo != 0");
        m_Do_printf::OSPanic("d_gameover.cpp",0xa0,&DAT_8035ef26);
      }
      *(JKRExpHeap **)(this + 0x110) = d_com_inf_game::g_dComIfG_gameInfo.field_0x5c1c;
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 4;
      uVar4 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(this + 0x110));
      ppuVar5 = (undefined **)JKernel::operator_new(0x410);
      if (ppuVar5 != (undefined **)0x0) {
        *ppuVar5 = (undefined *)&dDlst_base_c::__vt;
        *ppuVar5 = &dDlst_GameOverScrnDraw_c::__vt;
        ppuVar5[0xce] = (undefined *)0x0;
        *(undefined2 *)(ppuVar5 + 0xcf) = 0;
        ppuVar5[0xcc] = (undefined *)0x0;
        ppuVar5[0xcd] = (undefined *)0x0;
        ppuVar5[0xcb] = (undefined *)0x8;
        ppuVar5[0xca] = (undefined *)d_gameover::_4075;
      }
      *(undefined ***)(this + 0x100) = ppuVar5;
      dDlst_GameOverScrnDraw_c::setScreen
                (*(dDlst_GameOverScrnDraw_c **)(this + 0x100),"gameover.blo",pdVar2->mpArchive);
      puVar6 = (undefined4 *)JKernel::operator_new(0x1ba4);
      if (puVar6 != (undefined4 *)0x0) {
        *puVar6 = &dMenu_save_c::__vt;
        puVar6[2] = &dDlst_base_c::__vt;
        puVar6[2] = &dDlst_MenuSave_c::__vt;
      }
      *(undefined4 **)(this + 0xfc) = puVar6;
      if (*(int *)(this + 0xfc) == 0) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar3,"d_gameover.cpp",0xb6,"dMs_c != 0");
        m_Do_printf::OSPanic("d_gameover.cpp",0xb6,&DAT_8035ef26);
      }
      *(undefined *)(*(int *)(this + 0xfc) + 0x537) = 2;
      dMenu_save_c::_create(*(dMenu_save_c **)(this + 0xfc));
      ppuVar5 = (undefined **)JKernel::operator_new(4);
      if (ppuVar5 != (undefined **)0x0) {
        *ppuVar5 = (undefined *)&dDlst_base_c::__vt;
        *ppuVar5 = &dDlst_Gameover_CAPTURE_c::__vt;
      }
      *(undefined ***)(this + 0x104) = ppuVar5;
      if (*(int *)(this + 0x104) == 0) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar3,"d_gameover.cpp",0xbb,"dgo_capture_c != 0");
        m_Do_printf::OSPanic("d_gameover.cpp",0xbb,&DAT_8035ef26);
      }
      m_Do_ext::mDoExt_setCurrentHeap(uVar4);
      *(undefined2 *)(this + 0x114) = 0x5a;
      *(undefined2 *)(this + 0x116) = DAT_803e6b22;
      this[0x119] = (dGameover_c)0x0;
      PVar1 = cPhs_COMPLEATE_e;
    }
  }
  else {
    PVar1 = 0;
  }
  return PVar1;
}


/* __thiscall dGameover_c::_execute(void) */

undefined4 __thiscall dGameover_c::_execute(dGameover_c *this)

{
  dGameover_c dVar1;
  short sVar2;
  undefined4 uVar3;
  char cVar5;
  int iVar4;
  cXyz local_38;
  cXyz local_2c;
  float local_20;
  float local_1c;
  float local_18;
  
  uVar3 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(this + 0x110));
  dVar1 = this[0x118];
  if (dVar1 == (dGameover_c)0x3) {
    cVar5 = dMenu_save_c::_open(*(dMenu_save_c **)(this + 0xfc));
    if (cVar5 != '\0') {
      this[0x118] = (dGameover_c)0x4;
      d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrHp = 0xc;
    }
  }
  else {
    if (dVar1 == (dGameover_c)0x4) {
      dMenu_save_c::_move(*(dMenu_save_c **)(this + 0xfc));
      if (*(char *)(*(int *)(this + 0xfc) + 0x531) == '\x03') {
        this[0x118] = (dGameover_c)0x5;
      }
    }
    else {
      if (dVar1 == (dGameover_c)0x5) {
        cVar5 = dMenu_save_c::_close(*(dMenu_save_c **)(this + 0xfc));
        if (cVar5 != '\0') {
          if (*(char *)(*(int *)(this + 0xfc) + 0x538) == '\0') {
            d_com_inf_game::g_dComIfG_gameInfo._23545_1_ = 3;
            d_meter::dMenu_flagSet(0);
            *mDoRst::mResetData = 1;
          }
          else {
            if (*(char *)(*(int *)(this + 0xfc) + 0x538) == '\x01') {
              d_com_inf_game::g_dComIfG_gameInfo._23545_1_ = 2;
              d_meter::dMenu_flagSet(0);
            }
          }
          iVar4 = *(int *)(*(int *)(this + 0x100) + 0x324);
          if (iVar4 != 0) {
            *(undefined4 *)(iVar4 + 0x60) = 0xffffffff;
            *(uint *)(iVar4 + 0x20c) = *(uint *)(iVar4 + 0x20c) | 1;
          }
          this[0x118] = (dGameover_c)0x6;
        }
      }
      else {
        if ((dVar1 != (dGameover_c)0x6) && (this[0x119] != (dGameover_c)0x0)) {
          sVar2 = *(short *)(this + 0x114);
          if (sVar2 == 0x5a) {
            iVar4 = dDlst_GameOverScrnDraw_c::animeOpen
                              (*(dDlst_GameOverScrnDraw_c **)(this + 0x100));
            if (iVar4 == 1) {
              local_20 = d_gameover::_4075;
              local_1c = d_gameover::_4075;
              local_18 = d_gameover::_4075;
              local_2c.x = d_gameover::_4075;
              local_2c.y = d_gameover::_4075;
              local_2c.z = d_gameover::_4075;
              dDlst_GameOverScrnDraw_c::setEmitter0
                        (*(dDlst_GameOverScrnDraw_c **)(this + 0x100),&local_2c);
              local_38.x = local_20;
              local_38.y = local_1c;
              local_38.z = local_18;
              dDlst_GameOverScrnDraw_c::setEmitter1
                        (*(dDlst_GameOverScrnDraw_c **)(this + 0x100),&local_38);
              *(short *)(this + 0x114) = *(short *)(this + 0x114) + -1;
            }
          }
          else {
            if (sVar2 < 1) {
              iVar4 = dDlst_GameOverScrnDraw_c::animeClose
                                (*(dDlst_GameOverScrnDraw_c **)(this + 0x100));
              if (iVar4 == 1) {
                iVar4 = *(int *)(*(int *)(this + 0x100) + 800);
                if (iVar4 != 0) {
                  *(undefined4 *)(iVar4 + 0x60) = 0xffffffff;
                  *(uint *)(iVar4 + 0x20c) = *(uint *)(iVar4 + 0x20c) | 1;
                }
                sVar2 = *(short *)(this + 0x116);
                *(short *)(this + 0x116) = sVar2 + -1;
                if (sVar2 < 1) {
                  this[0x118] = (dGameover_c)0x3;
                  d_meter::dMenu_flagSet(1);
                }
              }
            }
            else {
              *(short *)(this + 0x114) = sVar2 + -1;
              if (*(short *)(this + 0x114) == 0) {
                dDlst_GameOverScrnDraw_c::valueInit(*(dDlst_GameOverScrnDraw_c **)(this + 0x100));
              }
            }
          }
        }
      }
    }
  }
  m_Do_ext::mDoExt_setCurrentHeap(uVar3);
  return 1;
}


/* __thiscall dGameover_c::_draw(void) */

undefined4 __thiscall dGameover_c::_draw(dGameover_c *this)

{
  byte bVar1;
  
  if ((*(int *)(this + 0x104) != 0) && (bVar1 = d_meter::dMenu_flag(), bVar1 != 0)) {
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                      *(dDlst_base_c **)(this + 0x104));
  }
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(this + 0x100));
  dMenu_save_c::_draw2(*(dMenu_save_c **)(this + 0xfc));
  return 1;
}


/* __thiscall dGameover_c::_delete(void) */

undefined4 __thiscall dGameover_c::_delete(dGameover_c *this)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(this + 0x110));
  piVar2 = *(int **)(*(int *)(this + 0x100) + 4);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2,1);
  }
  piVar2 = *(int **)(this + 0x100);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2,1);
  }
  dMenu_save_c::_delete(*(dMenu_save_c **)(this + 0xfc));
  piVar2 = *(int **)(this + 0xfc);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2,1);
  }
  piVar2 = *(int **)(this + 0x104);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2,1);
  }
  JKRHeap::freeAll(*(JKRHeap **)(this + 0x110));
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 0;
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  d_com_inf_game::dComIfG_resDelete((request_of_phase_process_class *)(this + 0x108),"Gover");
  return 1;
}


/* __thiscall dGameover_c::deleteCheck(void) */

uint __thiscall dGameover_c::deleteCheck(dGameover_c *this)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(6 - (uint)(byte)this[0x118]);
  return uVar1 >> 5 & 0xff;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dDlst_GameOverScrnDraw_c::setScreen(char const *,
                                                  JKRArchive *) */

void __thiscall
dDlst_GameOverScrnDraw_c::setScreen
          (dDlst_GameOverScrnDraw_c *this,char *param_1,JKRArchive *param_2)

{
  J2DPane *this_00;
  J2DScreen *pJVar1;
  undefined4 pData;
  int iVar2;
  int iVar3;
  int iVar4;
  TBox2_float_ local_28;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_28.mTL.x = d_gameover::_4075;
    local_28.mTL.y = d_gameover::_4075;
    local_28.mBR.x = d_gameover::_4319;
    local_28.mBR.y = d_gameover::_4320;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_28);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 4) = this_00;
  J2DScreen::set(*(J2DScreen **)(this + 4),param_1,param_2);
  iVar4 = 0;
  iVar3 = 0;
  for (iVar2 = 0; iVar2 < d_gameover::dGover_tex_number; iVar2 = iVar2 + 1) {
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 4) + 0x30))
                       (*(int **)(this + 4),*(undefined4 *)((int)&d_gameover::labelt_4302 + iVar3));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar4 + 8),pJVar1);
    iVar4 = iVar4 + 0x38;
    iVar3 = iVar3 + 4;
  }
  pData = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x626c616b);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x318),pData);
  this[0x31c] = (dDlst_GameOverScrnDraw_c)0xff;
  return;
}


/* __thiscall dDlst_GameOverScrnDraw_c::valueInit(void) */

void __thiscall dDlst_GameOverScrnDraw_c::valueInit(dDlst_GameOverScrnDraw_c *this)

{
  int iVar1;
  int iVar2;
  
  *(int *)(this + 0x32c) = (int)d_gameover::dGover_tex_number;
  *(undefined4 *)(this + 0x330) = 0;
  iVar1 = 0;
  for (iVar2 = 0; iVar2 < d_gameover::dGover_tex_number; iVar2 = iVar2 + 1) {
    *(undefined2 *)(this + iVar1 + 0x3e) = 0;
    iVar1 = iVar1 + 0x38;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dDlst_GameOverScrnDraw_c::animeOpen(void) */

uint __thiscall dDlst_GameOverScrnDraw_c::animeOpen(dDlst_GameOverScrnDraw_c *this)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  float fVar9;
  cXyz local_48;
  undefined4 local_38;
  uint uStack52;
  longlong local_30;
  
  uVar8 = 0;
  sVar4 = -1;
  if (-1 < (int)*(uint *)(this + 0x32c)) {
    if (*(int *)(this + 0x330) == 0) {
      uStack52 = *(uint *)(this + 0x32c) ^ 0x80000000;
      local_38 = 0x43300000;
      fVar9 = SComponent::cM_rndF((float)((double)CONCAT44(0x43300000,uStack52) - d_gameover::_4389)
                                 );
      iVar5 = (int)fVar9;
      local_30 = (longlong)iVar5;
      if (*(int *)(this + 0x32c) + -1 <= iVar5) {
        iVar5 = *(int *)(this + 0x32c) + -1;
      }
      iVar3 = 0;
      iVar7 = 0;
      iVar6 = (int)d_gameover::dGover_tex_number;
      if (0 < iVar6) {
        do {
          if (*(short *)(this + iVar7 + 0x3e) == 0) {
            if (iVar5 == 0) {
              anime1(this,iVar3);
              sVar4 = (short)iVar3;
              break;
            }
            iVar5 = iVar5 + -1;
          }
          iVar3 = iVar3 + 1;
          iVar7 = iVar7 + 0x38;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      *(int *)(this + 0x32c) = *(int *)(this + 0x32c) + -1;
      *(int *)(this + 0x330) = (*(int *)(this + 0x32c) * *(int *)(this + 0x32c)) / 5;
    }
    else {
      *(int *)(this + 0x330) = *(int *)(this + 0x330) + -1;
    }
  }
  iVar6 = 0;
  iVar5 = 0;
  for (iVar7 = 0; iVar7 < d_gameover::dGover_tex_number; iVar7 = iVar7 + 1) {
    sVar1 = *(short *)(this + iVar5 + 0x3e);
    if ((-1 < sVar1) && (sVar1 < 9)) {
      if ((0 < sVar1) &&
         ((sVar4 != iVar7 && (anime1(this,iVar7), *(short *)(this + iVar5 + 0x3e) == 5)))) {
        local_48.x = *(float *)((int)&d_gameover::x_4363 + iVar6);
        local_48.y = d_gameover::_4387;
        local_48.z = d_gameover::_4075;
        dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,7,0x2e,&local_48,
                           (csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1,
                           (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
      }
      uVar8 = 1;
    }
    iVar6 = iVar6 + 4;
    iVar5 = iVar5 + 0x38;
  }
  uVar2 = countLeadingZeros(uVar8);
  return uVar2 >> 5;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dDlst_GameOverScrnDraw_c::animeClose(void) */

uint __thiscall dDlst_GameOverScrnDraw_c::animeClose(dDlst_GameOverScrnDraw_c *this)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short sVar7;
  int iVar6;
  undefined4 uVar8;
  float fVar9;
  
  uVar8 = 0;
  sVar7 = -1;
  if (-1 < (int)*(uint *)(this + 0x32c)) {
    if (*(int *)(this + 0x330) == 0) {
      fVar9 = SComponent::cM_rndF((float)((double)CONCAT44(0x43300000,
                                                           *(uint *)(this + 0x32c) ^ 0x80000000) -
                                         d_gameover::_4389));
      iVar4 = (int)fVar9;
      if (*(int *)(this + 0x32c) + -1 <= (int)fVar9) {
        iVar4 = *(int *)(this + 0x32c) + -1;
      }
      iVar5 = 0;
      iVar3 = 0;
      iVar6 = (int)d_gameover::dGover_tex_number;
      if (0 < iVar6) {
        do {
          if (*(short *)(this + iVar3 + 0x3e) == 0) {
            if (iVar4 == 0) {
              anime2(this,iVar5);
              sVar7 = (short)iVar5;
              break;
            }
            iVar4 = iVar4 + -1;
          }
          iVar5 = iVar5 + 1;
          iVar3 = iVar3 + 0x38;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      fVar9 = SComponent::cM_rndF(d_gameover::_4433);
      *(int *)(this + 0x330) = (int)fVar9 + 1;
      if (2 < *(int *)(this + 0x330)) {
        *(undefined4 *)(this + 0x330) = 3;
      }
      *(int *)(this + 0x32c) = *(int *)(this + 0x32c) + -1;
    }
    else {
      *(undefined4 *)(this + 0x330) = 0;
    }
  }
  iVar6 = 0;
  for (iVar4 = 0; iVar4 < d_gameover::dGover_tex_number; iVar4 = iVar4 + 1) {
    sVar1 = *(short *)(this + iVar6 + 0x3e);
    if ((-1 < sVar1) && (sVar1 < 7)) {
      if ((0 < sVar1) && (sVar7 != iVar4)) {
        anime2(this,iVar4);
      }
      uVar8 = 1;
    }
    iVar6 = iVar6 + 0x38;
  }
  uVar2 = countLeadingZeros(uVar8);
  return uVar2 >> 5;
}


/* __thiscall dDlst_GameOverScrnDraw_c::setEmitter0(cXyz) */

void __thiscall dDlst_GameOverScrnDraw_c::setEmitter0(dDlst_GameOverScrnDraw_c *this,cXyz *param_1)

{
  JPABaseEmitter *pJVar1;
  
  pJVar1 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,7,0x2f,param_1,
                              (csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1,
                              (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
  *(JPABaseEmitter **)(this + 800) = pJVar1;
  return;
}


/* __thiscall dDlst_GameOverScrnDraw_c::setEmitter1(cXyz) */

void __thiscall dDlst_GameOverScrnDraw_c::setEmitter1(dDlst_GameOverScrnDraw_c *this,cXyz *param_1)

{
  JPABaseEmitter *pJVar1;
  
  pJVar1 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,9,0x30,param_1,
                              (csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1,
                              (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
  *(JPABaseEmitter **)(this + 0x324) = pJVar1;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dDlst_GameOverScrnDraw_c::anime1(int) */

bool __thiscall dDlst_GameOverScrnDraw_c::anime1(dDlst_GameOverScrnDraw_c *this,int param_1)

{
  short sVar1;
  uint uVar2;
  dDlst_GameOverScrnDraw_c *pdVar3;
  int iVar4;
  
  iVar4 = param_1 * 0x38;
  pdVar3 = this + iVar4;
  sVar1 = *(short *)(pdVar3 + 0x3e);
  if (sVar1 < 5) {
    if (sVar1 == 0) {
      f_op_msg_mng::fopMsgM_setInitAlpha(this + iVar4 + 8);
    }
    *(short *)(pdVar3 + 0x3e) = *(short *)(pdVar3 + 0x3e) + 1;
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + iVar4 + 8),(double)d_gameover::_4075,
               (double)(d_gameover::_4492 *
                       (d_gameover::_4076 -
                       ((float)((double)CONCAT44(0x43300000,
                                                 (int)*(short *)(pdVar3 + 0x3e) ^ 0x80000000U) -
                               d_gameover::_4389) *
                       (float)((double)CONCAT44(0x43300000,
                                                (int)*(short *)(pdVar3 + 0x3e) ^ 0x80000000U) -
                              d_gameover::_4389)) / d_gameover::_4491)));
  }
  else {
    if (sVar1 < 7) {
      *(short *)(pdVar3 + 0x3e) = sVar1 + 1;
      uVar2 = (int)(short)(*(short *)(pdVar3 + 0x3e) + -5) ^ 0x80000000;
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + iVar4 + 8),(double)d_gameover::_4075,
                 (double)(d_gameover::_4494 *
                         (float)((double)CONCAT44(0x43300000,uVar2) - d_gameover::_4389) *
                         (float)((double)CONCAT44(0x43300000,uVar2) - d_gameover::_4389) *
                         d_gameover::_4493));
    }
    else {
      if (sVar1 < 9) {
        *(short *)(pdVar3 + 0x3e) = sVar1 + 1;
        uVar2 = (int)(short)(*(short *)(pdVar3 + 0x3e) + -7) ^ 0x80000000;
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + iVar4 + 8),(double)d_gameover::_4075,
                   (double)(d_gameover::_4494 *
                           (d_gameover::_4076 -
                           (float)((double)CONCAT44(0x43300000,uVar2) - d_gameover::_4389) *
                           (float)((double)CONCAT44(0x43300000,uVar2) - d_gameover::_4389) *
                           d_gameover::_4493)));
        if (*(short *)(pdVar3 + 0x3e) == 9) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x85a,(cXyz *)0x0,0,0,d_gameover::_4076,
                     d_gameover::_4076,d_gameover::_4495,d_gameover::_4495,0);
        }
      }
    }
  }
  return *(short *)(pdVar3 + 0x3e) == 9;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8018f488) */
/* __thiscall dDlst_GameOverScrnDraw_c::anime2(int) */

bool __thiscall dDlst_GameOverScrnDraw_c::anime2(dDlst_GameOverScrnDraw_c *this,int param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  dDlst_GameOverScrnDraw_c *pdVar5;
  undefined4 uVar6;
  undefined8 in_f31;
  double dVar7;
  float fVar8;
  double local_48;
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar4 = param_1 * 0x38;
  pdVar5 = this + iVar4;
  if (*(short *)(pdVar5 + 0x3e) < 7) {
    if (*(short *)(pdVar5 + 0x3e) == 0) {
      fVar8 = SComponent::cM_rndF(d_gameover::_4520);
      iVar2 = (int)fVar8;
      if (5 < iVar2) {
        iVar2 = 5;
      }
      *(undefined2 *)(this + param_1 * 2 + 0x33e) =
           *(undefined2 *)(&d_gameover::rot_4501 + iVar2 * 2);
    }
    *(short *)(pdVar5 + 0x3e) = *(short *)(pdVar5 + 0x3e) + 1;
    uVar3 = (int)*(short *)(pdVar5 + 0x3e) ^ 0x80000000;
    local_48 = (double)CONCAT44(0x43300000,uVar3);
    dVar7 = (double)(((float)(local_48 - d_gameover::_4389) *
                     (float)((double)CONCAT44(0x43300000,uVar3) - d_gameover::_4389)) /
                    d_gameover::_4521);
    setRotate(this,(fopMsgM_pane_class *)(this + iVar4 + 8),
              (float)((double)CONCAT44(0x43300000,
                                       (int)*(short *)(this + param_1 * 2 + 0x33e) ^ 0x80000000) -
                     d_gameover::_4389) *
              (d_gameover::_4076 -
              (float)((double)CONCAT44(0x43300000,uVar3) - d_gameover::_4389) / d_gameover::_4522));
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + iVar4 + 8),(double)d_gameover::_4075,
               (double)(float)((double)d_gameover::_4523 * dVar7));
  }
  sVar1 = *(short *)(pdVar5 + 0x3e);
  if (sVar1 == 7) {
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar4 + 8));
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return sVar1 == 7;
}


/* __thiscall dDlst_GameOverScrnDraw_c::setRotate(fopMsgM_pane_class *,
                                                  float) */

void __thiscall
dDlst_GameOverScrnDraw_c::setRotate
          (dDlst_GameOverScrnDraw_c *this,fopMsgM_pane_class *param_1,float param_2)

{
  double dVar1;
  J2DScreen *pJVar2;
  
  dVar1 = (double)CONCAT44(0x43300000,(int)((param_1->mSize).y * d_gameover::_4536) ^ 0x80000000) -
          d_gameover::_4389;
  pJVar2 = param_1->mpPane;
  (pJVar2->parent).mBasePosition.x =
       (float)((double)CONCAT44(0x43300000,
                                (int)((param_1->mSize).x * d_gameover::_4536) ^ 0x80000000) -
              d_gameover::_4389);
  (pJVar2->parent).mBasePosition.y = (float)dVar1;
  (pJVar2->parent).mRotationAxis = 'z';
  (pJVar2->parent).mRotation = param_2;
  (*(code *)((pJVar2->parent).vtbl)->calcMtx)();
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDlst_GameOverScrnDraw_c::draw(void) */

void __thiscall dDlst_GameOverScrnDraw_c::draw(dDlst_GameOverScrnDraw_c *this)

{
  J2DOrthoGraph *pCtx;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (iVar1 = 0; iVar1 < d_gameover::dGover_tex_number; iVar1 = iVar1 + 1) {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar2 + 8));
    iVar2 = iVar2 + 0x38;
  }
  f_op_msg_mng::fopMsgM_setNowAlpha((double)*(float *)(this + 0x328),this + 0x318);
  f_op_msg_mng::fopMsgM_setAlpha(this + 0x318);
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(*(J2DScreen **)(this + 4),d_gameover::_4075,d_gameover::_4075,&pCtx->parent);
  return;
}


namespace d_gameover {

/* __stdcall dGameover_Draw(dGameover_c *) */

void dGameover_Draw(dGameover_c *param_1)

{
  ::dGameover_c::_draw(param_1);
  return;
}


/* __stdcall dGameover_Execute(dGameover_c *) */

void dGameover_Execute(dGameover_c *param_1)

{
  ::dGameover_c::_execute(param_1);
  return;
}


/* __stdcall dGameover_IsDelete(dGameover_c *) */

undefined4 dGameover_IsDelete(void)

{
  return 1;
}


/* __stdcall dGameover_Delete(dGameover_c *) */

void dGameover_Delete(dGameover_c *param_1)

{
  ::dGameover_c::_delete(param_1);
  return;
}


/* __stdcall dGameover_Create(msg_class *) */

void dGameover_Create(dGameover_c *param_1)

{
  ::dGameover_c::_create(param_1);
  return;
}

}

/* __thiscall dDlst_MenuSave_c::~dDlst_MenuSave_c(void) */

void __thiscall dDlst_MenuSave_c::_dDlst_MenuSave_c(dDlst_MenuSave_c *this)

{
  short in_r4;
  
  if (this != (dDlst_MenuSave_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_MenuSave_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMenu_save_c::~dMenu_save_c(void) */

void __thiscall dMenu_save_c::_dMenu_save_c(dMenu_save_c *this)

{
  short in_r4;
  
  if (this != (dMenu_save_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dMenu_save_c *)&DAT_fffffff8) {
      *(undefined1 **)(this + 8) = &dDlst_MenuSave_c::__vt;
      if (this != (dMenu_save_c *)&DAT_fffffff8) {
        *(undefined ***)(this + 8) = &dDlst_base_c::__vt;
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_Gameover_CAPTURE_c::~dDlst_Gameover_CAPTURE_c(void) */

void __thiscall dDlst_Gameover_CAPTURE_c::_dDlst_Gameover_CAPTURE_c(dDlst_Gameover_CAPTURE_c *this)

{
  short in_r4;
  
  if (this != (dDlst_Gameover_CAPTURE_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_Gameover_CAPTURE_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_GameOverScrnDraw_c::~dDlst_GameOverScrnDraw_c(void) */

void __thiscall dDlst_GameOverScrnDraw_c::_dDlst_GameOverScrnDraw_c(dDlst_GameOverScrnDraw_c *this)

{
  short in_r4;
  
  if (this != (dDlst_GameOverScrnDraw_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_GameOverScrnDraw_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

