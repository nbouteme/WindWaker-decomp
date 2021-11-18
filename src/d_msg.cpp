#include <d_msg.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J2DGraph/J2DScreen.h>
#include <d_msg.h>
#include <f_op_msg_mng.h>
#include <J2DGraph/J2DPicture.h>
#include <J2DGraph/J2DTextBox.h>
#include <gx/GXTransform.h>
#include <gx/GXFrameBuf.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DPane.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JKernel/JKRArchivePub.h>
#include <m_Do_ext.h>
#include <SComponent/c_xyz.h>
#include <m_Do_lib.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JKernel/JKRFileLoader.h>
#include <JAZelAudio/JAIZelInst.h>
#include <d_a_player_main.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_com_inf_game.h>
#include <d_event.h>
#include <d_particle.h>
#include <d_drawlist.h>
#include <d_save.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dDlst_2DMSG_c.h>
#include <dDlst_2Dtact_c.h>


namespace d_msg {
}

namespace d_msg {
undefined4 button_icon;
undefined4 button_kage;
undefined2 buttonTimer;
undefined4 numberPane;
undefined4 capture;
undefined4 multiTex;
undefined4 sScreen;
undefined4 sScreen2;
undefined4 textFont;
undefined4 rubyFont;
undefined4 arrowPane;
undefined4 maskPane;
float talkPosX;
float talkPosY;
undefined2 textOffsetY;
undefined1 dMsg_font_flag;
undefined4 agb_work_area;
undefined4 message;
undefined1 flag$7049;
undefined1 init$7050;
undefined2 cnt$7052;
undefined1 init$7053;
undefined4 posY0$7922;
undefined1 init$7923;
undefined4 posY1$7925;
undefined1 init$7926;
undefined4 posY2$7928;
undefined1 init$7929;
undefined4 posY3$7931;
undefined1 init$7932;

/* __stdcall dMsg_getAgbWorkArea(void) */

undefined4 dMsg_getAgbWorkArea(void)

{
  return agb_work_area;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8020a930) */
/* __thiscall dDlst_2DMSG_c::draw(void) */

void __thiscall dDlst_2DMSG_c::draw(dDlst_2DMSG_c *this)

{
  J2DOrthoGraph *pCtx;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack8 [8];
  
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar2 = *(int *)(this + 4);
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(d_msg::sScreen,d_msg::_4185,d_msg::_4185,&pCtx->parent);
  if (d_msg::sScreen2 != (J2DScreen *)0x0) {
    J2DScreen::draw(d_msg::sScreen2,d_msg::_4185,d_msg::_4185,&pCtx->parent);
  }
  outFontDraw(this);
  if (*(short *)(iVar2 + 0xf8) == 0x14) {
    iVar2 = *(int *)(this + 4);
    fopMsgM_msgDataProc_c::selectArrow
              ((fopMsgM_msgDataProc_c *)(iVar2 + 0xe04),d_msg::arrowPane,*(float *)(iVar2 + 0x1070),
               *(float *)(iVar2 + 0x1074),*(float *)(iVar2 + 0x107c),*(float *)(iVar2 + 0x1078));
  }
  else {
    if (*(short *)(iVar2 + 0xf8) == 0x15) {
      iVar1 = *(int *)(this + 4);
      if ((*(char *)(iVar1 + 0x10c) == '\0') || (*(char *)(iVar1 + 0x10c) == '\n')) {
        dVar4 = (double)(((d_msg::numberPane->parent).mPosBR.x -
                         (d_msg::numberPane->parent).mPosTL.x) + d_msg::numberPane->field_0xe0);
        if (*(int *)(iVar2 + 0xec) == 0x1cfa) {
          J2DPicture::draw(d_msg::maskPane,
                           *(float *)(iVar1 + 0x10ec) +
                           (float)(dVar4 * (double)(float)((double)CONCAT44(0x43300000,
                                                                            2 - *(byte *)(iVar2 + 
                                                  0xfa) ^ 0x80000000) - d_msg::_4188)),
                           *(float *)(iVar1 + 0x10f0),
                           (d_msg::maskPane->parent).mPosBR.x - (d_msg::maskPane->parent).mPosTL.x,
                           (d_msg::maskPane->parent).mPosBR.y - (d_msg::maskPane->parent).mPosTL.y,
                           false,false,false);
          J2DTextBox::draw(DAT_803e6f04,*(float *)(*(int *)(this + 4) + 0x10ec),
                           *(float *)(*(int *)(this + 4) + 0x10f0) +
                           ((DAT_803e6f04->parent).mPosBR.y - (DAT_803e6f04->parent).mPosTL.y),
                           (DAT_803e6f04->parent).mPosBR.x - (DAT_803e6f04->parent).mPosTL.x,0);
          J2DTextBox::draw(DAT_803e6f00,
                           (float)((double)*(float *)(*(int *)(this + 4) + 0x10ec) + dVar4),
                           *(float *)(*(int *)(this + 4) + 0x10f0) +
                           ((DAT_803e6f00->parent).mPosBR.y - (DAT_803e6f00->parent).mPosTL.y),
                           (DAT_803e6f00->parent).mPosBR.x - (DAT_803e6f00->parent).mPosTL.x,0);
          J2DTextBox::draw(d_msg::numberPane,
                           *(float *)(*(int *)(this + 4) + 0x10ec) +
                           (float)((double)d_msg::_4186 * dVar4),
                           *(float *)(*(int *)(this + 4) + 0x10f0) +
                           ((d_msg::numberPane->parent).mPosBR.y -
                           (d_msg::numberPane->parent).mPosTL.y),
                           (d_msg::numberPane->parent).mPosBR.x -
                           (d_msg::numberPane->parent).mPosTL.x,0);
        }
        else {
          (DAT_803e6f04->parent).mbDraw = 0;
          J2DPicture::draw(d_msg::maskPane,
                           *(float *)(*(int *)(this + 4) + 0x10ec) +
                           (float)(dVar4 * (double)(float)((double)CONCAT44(0x43300000,
                                                                            1 - *(byte *)(iVar2 + 
                                                  0xfa) ^ 0x80000000) - d_msg::_4188)),
                           *(float *)(*(int *)(this + 4) + 0x10f0),
                           (d_msg::maskPane->parent).mPosBR.x - (d_msg::maskPane->parent).mPosTL.x,
                           (d_msg::maskPane->parent).mPosBR.y - (d_msg::maskPane->parent).mPosTL.y,
                           false,false,false);
          J2DTextBox::draw(DAT_803e6f00,*(float *)(*(int *)(this + 4) + 0x10ec),
                           *(float *)(*(int *)(this + 4) + 0x10f0) +
                           ((DAT_803e6f00->parent).mPosBR.y - (DAT_803e6f00->parent).mPosTL.y),
                           (DAT_803e6f00->parent).mPosBR.x - (DAT_803e6f00->parent).mPosTL.x,0);
          J2DTextBox::draw(d_msg::numberPane,
                           (float)((double)*(float *)(*(int *)(this + 4) + 0x10ec) + dVar4),
                           *(float *)(*(int *)(this + 4) + 0x10f0) +
                           ((d_msg::numberPane->parent).mPosBR.y -
                           (d_msg::numberPane->parent).mPosTL.y),
                           (d_msg::numberPane->parent).mPosBR.x -
                           (d_msg::numberPane->parent).mPosTL.x,0);
        }
      }
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dDlst_2DMSG_c::outFontDraw(void) */

void __thiscall dDlst_2DMSG_c::outFontDraw(dDlst_2DMSG_c *this)

{
  double dVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  double local_38;
  double local_30;
  double local_28;
  
  iVar12 = 0;
  iVar11 = 0;
  iVar10 = 0;
  do {
    iVar5 = *(int *)(this + 4);
    cVar2 = *(char *)(iVar5 + iVar12 + 0x1085);
    iVar3 = iVar5 + iVar10 + 0xe04;
    iVar9 = *(int *)(iVar3 + 0x1a4);
    uVar7 = *(uint *)(iVar3 + 0x1e0);
    if ((((cVar2 != -1) && (cVar2 != '\x14')) && (cVar2 != '\x15')) && (cVar2 != '\x16')) {
      iVar4 = *(int *)(iVar5 + 0x544);
      local_38 = (double)CONCAT44(0x43300000,*(uint *)(iVar3 + 0x168) ^ 0x80000000);
      dVar1 = local_38 - d_msg::_4188;
      if (*(char *)(iVar5 + 0x10c) == '\x05') {
        local_30 = (double)CONCAT44(0x43300000,DAT_803e6ba2 * iVar9 ^ 0x80000000);
        local_38 = (double)CONCAT44(0x43300000,
                                    *(int *)(iVar5 + 0x1104) * (2 - *(int *)(iVar5 + 0x1108)) ^
                                    0x80000000);
        iVar3 = (int)((float)(local_30 - d_msg::_4188) +
                     (float)(local_38 - d_msg::_4188) + *(float *)(iVar4 + 0x10));
        uVar8 = *(undefined *)(iVar5 + 0x579);
      }
      else {
        if (*(char *)(iVar5 + 0x10c) == '\x0e') {
          local_28 = (double)CONCAT44(0x43300000,DAT_803e6ba2 * iVar9 ^ 0x80000000);
          local_30 = (double)CONCAT44(0x43300000,*(uint *)(iVar5 + 0x1104) ^ 0x80000000);
          iVar3 = (int)((float)(local_28 - d_msg::_4188) +
                       (float)(local_30 - d_msg::_4188) + *(float *)(iVar4 + 0x10));
          uVar8 = *(undefined *)(iVar5 + 0x579);
        }
        else {
          if (*(int *)(iVar5 + 0x110c) < (int)uVar7) {
            if (*(int *)(iVar5 + 0x1108) < 2) {
              local_28 = (double)CONCAT44(0x43300000,*(int *)(iVar5 + 0x1104) << 2 ^ 0x80000000);
              local_30 = (double)CONCAT44(0x43300000,
                                          ((int)uVar7 >> 1) +
                                          (uint)((int)uVar7 < 0 && (uVar7 & 1) != 0) ^ 0x80000000);
              iVar3 = (int)(((float)(local_28 - d_msg::_4188) + *(float *)(iVar4 + 0x10)) -
                           (float)(local_30 - d_msg::_4188));
            }
            else {
              uVar6 = uVar7 - *(int *)(iVar5 + 0x110c);
              local_28 = (double)CONCAT44(0x43300000,
                                          *(int *)(iVar5 + 0x1104) *
                                          ((3 - iVar9) - (*(int *)(iVar5 + 0x1108) + -2)) ^
                                          0x80000000);
              local_30 = (double)CONCAT44(0x43300000,
                                          ((int)uVar7 >> 1) +
                                          (uint)((int)uVar7 < 0 && (uVar7 & 1) != 0) ^ 0x80000000);
              iVar3 = ((int)uVar6 >> 1) + (uint)((int)uVar6 < 0 && (uVar6 & 1) != 0) +
                      (int)(((float)(local_28 - d_msg::_4188) + *(float *)(iVar4 + 0x10)) -
                           (float)(local_30 - d_msg::_4188));
            }
          }
          else {
            local_28 = (double)CONCAT44(0x43300000,DAT_803e6ba2 * iVar9 ^ 0x80000000);
            local_30 = (double)CONCAT44(0x43300000,
                                        *(int *)(iVar5 + 0x1104) * (3 - *(int *)(iVar5 + 0x1108)) ^
                                        0x80000000);
            iVar3 = (int)((float)(local_28 - d_msg::_4188) +
                         (float)(local_30 - d_msg::_4188) + *(float *)(iVar4 + 0x10));
          }
          uVar8 = *(undefined *)(iVar5 + 0x579);
        }
      }
      f_op_msg_mng::fopMsgM_outFontDraw
                (*(undefined4 *)((int)&d_msg::button_icon + iVar10),
                 *(undefined4 *)((int)&d_msg::button_kage + iVar10),
                 (int)((float)dVar1 + *(float *)(iVar4 + 0xc)),iVar3,uVar7,
                 (int)&d_msg::buttonTimer + iVar11,uVar8);
    }
    iVar12 = iVar12 + 1;
    iVar11 = iVar11 + 2;
    iVar10 = iVar10 + 4;
  } while (iVar12 < 8);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dDlst_2Dtact_c::draw(void) */

void __thiscall dDlst_2Dtact_c::draw(dDlst_2Dtact_c *this)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  J2DOrthoGraph *pCtx;
  uint uVar4;
  
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  uVar4 = (uint)d_msg::_4267;
  uVar1 = (uint)d_msg::_4268;
  uVar2 = (uint)d_msg::_4269;
  uVar3 = (uint)d_msg::_4270;
  gx::GXSetScissor(uVar4,uVar1,uVar2,uVar3);
  J2DScreen::draw(d_msg::sScreen,d_msg::_4185,d_msg::_4185,&pCtx->parent);
  gx::GXSetTexCopySrc(uVar4 & 0xffff,uVar1 & 0xffff,uVar2 & 0xffff,uVar3 & 0xffff);
  gx::GXSetTexCopyDst(uVar2 & 0xffff,uVar3 & 0xffff,4,0);
  uVar4 = countLeadingZeros((int)d_s_play::g_regHIO.mChild[1].mShorts[6]);
  gx::GXCopyTex(*(undefined4 *)(this + 8),uVar4 >> 5);
  return;
}


namespace d_msg {

/* __stdcall dMsg_msg_pane_parts_set(fopMsgM_pane_class *,
                                     unsigned char) */

void dMsg_msg_pane_parts_set(int param_1,byte param_2)

{
  float fVar1;
  
  if (param_2 == 2) {
    *(float *)(param_1 + 0x10) = _4288 - *(float *)(param_1 + 0x28) * _4289;
  }
  else {
    if ((param_2 < 2) && (param_2 != 0)) {
      *(float *)(param_1 + 0x10) =
           _4286 + (_4287 - (*(float *)(param_1 + 8) + *(float *)(param_1 + 0x28)));
    }
    else {
      *(float *)(param_1 + 0x10) = _4290 + *(float *)(param_1 + 8);
    }
  }
  fVar1 = _4289;
  *(float *)(param_1 + 0x1c) = *(float *)(param_1 + 0xc) + *(float *)(param_1 + 0x24) * _4289;
  *(float *)(param_1 + 0x20) = *(float *)(param_1 + 0x10) + *(float *)(param_1 + 0x28) * fVar1;
  return;
}


/* __stdcall dMsg_arw_pane_parts_set(fopMsgM_pane_class *,
                                     fopMsgM_pane_class *) */

void dMsg_arw_pane_parts_set(fopMsgM_pane_class *param_1,int param_2)

{
  (param_1->mPosTopLeft).y =
       (*(float *)(param_2 + 0x10) + (param_1->mPosTopLeftOrig).y) - *(float *)(param_2 + 8);
  (param_1->mPosCenter).y = (param_1->mPosTopLeft).y + (param_1->mSizeOrig).y * _4289;
  f_op_msg_mng::fopMsgM_cposMove(param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8020b930) */
/* WARNING: Removing unreachable block (ram,0x8020b928) */
/* WARNING: Removing unreachable block (ram,0x8020b938) */
/* __stdcall dMsg_screenDataSetTalk(sub_msg_class *) */

void dMsg_screenDataSetTalk(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  J2DScreen *pJVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  double dVar10;
  undefined8 in_f29;
  double dVar11;
  undefined8 in_f30;
  double dVar12;
  double in_f31;
  undefined uStack246;
  undefined uStack245;
  undefined uStack242;
  undefined uStack241;
  undefined local_f0;
  undefined uStack239;
  undefined uStack238;
  undefined uStack237;
  undefined local_ec;
  undefined uStack235;
  undefined uStack234;
  undefined uStack233;
  undefined local_d4;
  undefined uStack211;
  undefined local_cc;
  undefined uStack203;
  TBox2_float_ local_98;
  undefined4 local_88;
  uint uStack132;
  undefined4 local_80;
  uint uStack124;
  undefined4 local_78;
  uint uStack116;
  undefined4 local_70;
  uint uStack108;
  undefined4 local_68;
  uint uStack100;
  undefined4 local_60;
  uint uStack92;
  double local_58;
  double local_50;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,SUB84(in_f31,0),0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  pJVar5 = (J2DScreen *)JKernel::operator_new(0xd4);
  if (pJVar5 != (J2DScreen *)0x0) {
    local_98.mTL.x = _4185;
    local_98.mTL.y = _4185;
    local_98.mBR.x = _4515;
    local_98.mBR.y = _4287;
    J2DPane::J2DPane((J2DPane *)pJVar5,(J2DPane *)0x0,true,0x726f6f74,&local_98);
    (pJVar5->parent).vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    pJVar5->field_0xd0 = (_GXColor)0xffffffff;
    pJVar5->mbClipToParent = 0;
    (pJVar5->parent).vtbl = (J2DPane__vtable *)&MyScreen::__vt;
  }
  sScreen = pJVar5;
  J2DScreen::set(pJVar5,"hukidashi_00.blo",d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6d733030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x49c),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x797a3030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x4d4),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x64743030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x50c),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x74783032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x544),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x74783033);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x57c),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x74787430);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x5b4),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x74783031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x5ec),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x74786332);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x11c),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x74656333);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x154),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x74786330);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x18c),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x74786331);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x1c4),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x63757231);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x1fc),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x63757232);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x234),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6d633030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x26c),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6d633031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x2a4),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6d633032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x2dc),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6d633033);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x314),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6d633034);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x34c),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6d633035);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 900),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6d633036);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x3bc),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6d633037);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x3f4),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6d633038);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x42c),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6d633039);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x464),pJVar5);
  iVar6 = 0;
  iVar8 = 10;
  do {
    *(undefined *)(param_1 + iVar6 + 0x2a0) = 0xaa;
    uVar4 = DAT_803e6b49;
    iVar6 = iVar6 + 0x38;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  uStack242 = (undefined)((uint)DAT_803e6b49 >> 8);
  uStack241 = (undefined)DAT_803e6b49;
  iVar6 = *(int *)(param_1 + 0x49c);
  local_cc = (undefined)((uint)DAT_803e6b49 >> 0x18);
  *(undefined *)(iVar6 + 0x104) = local_cc;
  uStack203 = (undefined)((uint)uVar4 >> 0x10);
  *(undefined *)(iVar6 + 0x105) = uStack203;
  *(undefined *)(iVar6 + 0x106) = uStack242;
  *(undefined *)(iVar6 + 0x107) = uStack241;
  uVar4 = DAT_803e6b4d;
  uStack246 = (undefined)((uint)DAT_803e6b4d >> 8);
  uStack245 = (undefined)DAT_803e6b4d;
  iVar6 = *(int *)(param_1 + 0x49c);
  local_d4 = (undefined)((uint)DAT_803e6b4d >> 0x18);
  *(undefined *)(iVar6 + 0x108) = local_d4;
  uStack211 = (undefined)((uint)uVar4 >> 0x10);
  *(undefined *)(iVar6 + 0x109) = uStack211;
  *(undefined *)(iVar6 + 0x10a) = uStack246;
  *(undefined *)(iVar6 + 0x10b) = uStack245;
  iVar6 = *(int *)(param_1 + 0x26c);
  *(undefined *)(iVar6 + 0x104) = 0;
  *(undefined *)(iVar6 + 0x105) = 0;
  *(undefined *)(iVar6 + 0x106) = 0;
  *(undefined *)(iVar6 + 0x107) = 0;
  iVar6 = *(int *)(param_1 + 0x26c);
  *(undefined *)(iVar6 + 0x108) = 0;
  *(undefined *)(iVar6 + 0x109) = 0;
  *(undefined *)(iVar6 + 0x10a) = 0;
  *(undefined *)(iVar6 + 0x10b) = 0;
  J2DTextBox::setFont(*(J2DTextBox **)(param_1 + 0x544),textFont);
  J2DTextBox::setFont(*(J2DTextBox **)(param_1 + 0x57c),rubyFont);
  J2DTextBox::setFont(*(J2DTextBox **)(param_1 + 0x5b4),textFont);
  J2DTextBox::setFont(*(J2DTextBox **)(param_1 + 0x5ec),rubyFont);
  J2DTextBox::setFont(*(J2DTextBox **)(param_1 + 0x11c),textFont);
  J2DTextBox::setFont(*(J2DTextBox **)(param_1 + 0x154),rubyFont);
  J2DTextBox::setFont(*(J2DTextBox **)(param_1 + 0x18c),textFont);
  J2DTextBox::setFont(*(J2DTextBox **)(param_1 + 0x1c4),rubyFont);
  iVar6 = 0;
  iVar8 = 0;
  do {
    J2DTextBox::setFont(*(J2DTextBox **)((int)&numberPane + iVar8),textFont);
    iVar6 = iVar6 + 1;
    iVar8 = iVar8 + 4;
  } while (iVar6 < 3);
  textOffsetY = 2;
  uStack132 = (int)DAT_803e6bb4 ^ 0x80000000;
  local_88 = 0x43300000;
  fVar1 = (float)((double)CONCAT44(0x43300000,uStack132) - _4188);
  local_80 = 0x43300000;
  fVar2 = (float)((double)CONCAT44(0x43300000,uStack132) - _4188);
  iVar6 = *(int *)(param_1 + 0x544);
  fVar3 = _4185;
  if (_4185 < fVar1) {
    fVar3 = fVar1;
  }
  *(float *)(iVar6 + 0xe8) = fVar3;
  fVar3 = _4185;
  if (_4185 < fVar2) {
    fVar3 = fVar2;
  }
  *(float *)(iVar6 + 0xec) = fVar3;
  iVar6 = *(int *)(param_1 + 0x5b4);
  fVar3 = _4185;
  if (_4185 < fVar1) {
    fVar3 = fVar1;
  }
  *(float *)(iVar6 + 0xe8) = fVar3;
  fVar3 = _4185;
  if (_4185 < fVar2) {
    fVar3 = fVar2;
  }
  *(float *)(iVar6 + 0xec) = fVar3;
  iVar6 = *(int *)(param_1 + 0x11c);
  fVar3 = _4185;
  if (_4185 < fVar1) {
    fVar3 = fVar1;
  }
  *(float *)(iVar6 + 0xe8) = fVar3;
  fVar3 = _4185;
  if (_4185 < fVar2) {
    fVar3 = fVar2;
  }
  *(float *)(iVar6 + 0xec) = fVar3;
  iVar6 = *(int *)(param_1 + 0x18c);
  fVar3 = _4185;
  if (_4185 < fVar1) {
    fVar3 = fVar1;
  }
  *(float *)(iVar6 + 0xe8) = fVar3;
  fVar3 = _4185;
  if (_4185 < fVar2) {
    fVar3 = fVar2;
  }
  *(float *)(iVar6 + 0xec) = fVar3;
  iVar6 = 0;
  iVar8 = 0;
  dVar11 = (double)fVar2;
  dVar12 = (double)_4185;
  uStack124 = uStack132;
  do {
    iVar7 = *(int *)((int)&numberPane + iVar8);
    dVar10 = dVar12;
    if (dVar12 < (double)fVar1) {
      dVar10 = (double)fVar1;
    }
    *(float *)(iVar7 + 0xe8) = (float)dVar10;
    dVar10 = dVar12;
    if (dVar12 < (double)fVar2) {
      dVar10 = (double)fVar2;
    }
    *(float *)(iVar7 + 0xec) = (float)dVar10;
    (**(code **)(**(int **)((int)&numberPane + iVar8) + 0x18))((double)fVar1,dVar11);
    iVar6 = iVar6 + 1;
    iVar8 = iVar8 + 4;
  } while (iVar6 < 3);
  (**(code **)(*maskPane + 0x18))((double)fVar1,dVar11);
  dVar11 = _4188;
  uStack124 = (int)DAT_803e6b9e ^ 0x80000000;
  local_80 = 0x43300000;
  *(float *)(*(int *)(param_1 + 0x544) + 0xe0) =
       (float)((double)CONCAT44(0x43300000,uStack124) - _4188);
  uStack132 = (int)DAT_803e6ba0 ^ 0x80000000;
  local_88 = 0x43300000;
  *(float *)(*(int *)(param_1 + 0x57c) + 0xe0) =
       (float)((double)CONCAT44(0x43300000,uStack132) - dVar11);
  uStack116 = (int)DAT_803e6b9e ^ 0x80000000;
  local_78 = 0x43300000;
  *(float *)(*(int *)(param_1 + 0x5b4) + 0xe0) =
       (float)((double)CONCAT44(0x43300000,uStack116) - dVar11);
  uStack108 = (int)DAT_803e6ba0 ^ 0x80000000;
  local_70 = 0x43300000;
  *(float *)(*(int *)(param_1 + 0x5ec) + 0xe0) =
       (float)((double)CONCAT44(0x43300000,uStack108) - dVar11);
  *(float *)(*(int *)(param_1 + 0x11c) + 0xe0) =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6b9e ^ 0x80000000) - dVar11);
  *(float *)(*(int *)(param_1 + 0x154) + 0xe0) =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6ba0 ^ 0x80000000) - dVar11);
  local_58 = (double)CONCAT44(0x43300000,(int)DAT_803e6b9e ^ 0x80000000);
  *(float *)(*(int *)(param_1 + 0x18c) + 0xe0) = (float)(local_58 - dVar11);
  local_50 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba0 ^ 0x80000000);
  *(float *)(*(int *)(param_1 + 0x1c4) + 0xe0) = (float)(local_50 - dVar11);
  iVar6 = 0;
  iVar8 = 3;
  do {
    local_50 = (double)CONCAT44(0x43300000,(int)DAT_803e6b9e ^ 0x80000000);
    *(float *)(*(int *)((int)&numberPane + iVar6) + 0xe0) = (float)(local_50 - dVar11);
    dVar12 = _4188;
    iVar6 = iVar6 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  local_50 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000);
  *(float *)(*(int *)(param_1 + 0x544) + 0xe4) = (float)(local_50 - _4188);
  local_58 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000);
  *(float *)(*(int *)(param_1 + 0x5b4) + 0xe4) = (float)(local_58 - dVar12);
  uStack92 = (int)DAT_803e6ba2 ^ 0x80000000;
  local_60 = 0x43300000;
  *(float *)(*(int *)(param_1 + 0x11c) + 0xe4) =
       (float)((double)CONCAT44(0x43300000,uStack92) - dVar12);
  uStack100 = (int)DAT_803e6ba2 ^ 0x80000000;
  local_68 = 0x43300000;
  *(float *)(*(int *)(param_1 + 0x18c) + 0xe4) =
       (float)((double)CONCAT44(0x43300000,uStack100) - dVar12);
  iVar6 = 0;
  iVar8 = 3;
  do {
    local_50 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000);
    *(float *)(*(int *)((int)&numberPane + iVar6) + 0xe4) = (float)(local_50 - dVar12);
    iVar6 = iVar6 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  f_op_msg_mng::fopMsgM_blendInit((fopMsgM_pane_class *)(param_1 + 0x1fc),"cursor_00_02.bti");
  f_op_msg_mng::fopMsgM_blendInit((fopMsgM_pane_class *)(param_1 + 0x234),"cursor_00_02.bti");
  *(int *)(param_1 + 0x110c) = (int)*(float *)(*(int *)(param_1 + 0x544) + 0xe8);
  *(int *)(param_1 + 0x1110) = (int)in_f31;
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 0x50c) + 0x108);
  local_ec = (undefined)((uint)uVar4 >> 0x18);
  *(undefined *)(param_1 + 0x10bc) = local_ec;
  uStack235 = (undefined)((uint)uVar4 >> 0x10);
  *(undefined *)(param_1 + 0x10bd) = uStack235;
  uStack234 = (undefined)((uint)uVar4 >> 8);
  *(undefined *)(param_1 + 0x10be) = uStack234;
  uStack233 = (undefined)uVar4;
  *(undefined *)(param_1 + 0x10bf) = uStack233;
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 0x50c) + 0x104);
  local_f0 = (undefined)((uint)uVar4 >> 0x18);
  *(undefined *)(param_1 + 0x10c4) = local_f0;
  uStack239 = (undefined)((uint)uVar4 >> 0x10);
  *(undefined *)(param_1 + 0x10c5) = uStack239;
  uStack238 = (undefined)((uint)uVar4 >> 8);
  *(undefined *)(param_1 + 0x10c6) = uStack238;
  uStack237 = (undefined)uVar4;
  *(undefined *)(param_1 + 0x10c7) = uStack237;
  *(undefined2 *)(param_1 + 0x2a2) = 0;
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  __psq_l0(auStack40,uVar9);
  __psq_l1(auStack40,uVar9);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8020cc44) */
/* WARNING: Removing unreachable block (ram,0x8020cc4c) */
/* __stdcall dMsg_screenDataSetItem(sub_msg_class *) */

void dMsg_screenDataSetItem(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  J2DScreen *pJVar6;
  void *pvVar7;
  ulong uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  double dVar12;
  undefined8 in_f30;
  double dVar13;
  undefined8 in_f31;
  double dVar14;
  undefined local_1e8;
  undefined uStack487;
  undefined uStack486;
  undefined uStack485;
  undefined local_1e4;
  undefined uStack483;
  undefined uStack482;
  undefined uStack481;
  TBox2_float_ local_78;
  undefined4 local_68;
  uint uStack100;
  undefined4 local_60;
  uint uStack92;
  double local_48;
  double local_40;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  pJVar6 = (J2DScreen *)JKernel::operator_new(0xd4);
  if (pJVar6 != (J2DScreen *)0x0) {
    local_78.mTL.x = _4185;
    local_78.mTL.y = _4185;
    local_78.mBR.x = _4515;
    local_78.mBR.y = _4287;
    J2DPane::J2DPane((J2DPane *)pJVar6,(J2DPane *)0x0,true,0x726f6f74,&local_78);
    (pJVar6->parent).vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    pJVar6->field_0xd0 = (_GXColor)0xffffffff;
    pJVar6->mbClipToParent = 0;
    (pJVar6->parent).vtbl = (J2DPane__vtable *)&MyScreen::__vt;
  }
  sScreen = pJVar6;
  J2DScreen::set(pJVar6,"hukidashi_09.blo",d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive);
  pJVar6 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6d733930);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x49c),pJVar6);
  pJVar6 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x797a3930);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x4d4),pJVar6);
  pJVar6 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x64743930);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x50c),pJVar6);
  pJVar6 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x74783932);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x544),pJVar6);
  pJVar6 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x74783933);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x57c),pJVar6);
  pJVar6 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x74783930);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x5b4),pJVar6);
  pJVar6 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x74783931);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x5ec),pJVar6);
  pJVar6 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6974656d);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x7e4),pJVar6);
  pJVar6 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x72696e31);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x81c),pJVar6);
  pJVar6 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6c696731);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x624),pJVar6);
  pJVar6 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6c696732);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x65c),pJVar6);
  pJVar6 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6c696733);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x694),pJVar6);
  pJVar6 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6c696734);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x6cc),pJVar6);
  pJVar6 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6c696735);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x704),pJVar6);
  pJVar6 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6c696736);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x73c),pJVar6);
  pJVar6 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6c696737);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x774),pJVar6);
  pJVar6 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6c696738);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x7ac),pJVar6);
  pvVar7 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0xc00,0x20);
  *(void **)(param_1 + 0x10cc) = pvVar7;
  if (*(int *)(param_1 + 0x10cc) == 0) {
    uVar8 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar8,"d_msg.cpp",0x295,"i_Msg->buffer_p != 0");
    m_Do_printf::OSPanic("d_msg.cpp",0x295,&DAT_80361ec0);
  }
  if ((*(char *)(param_1 + 0x10c) == '\t') &&
     (dItem_data::item_resource[*(int *)(param_1 + 0xec) - 0x65U & 0xff].mIconFilename !=
      (char *)0x0)) {
    JKRArchive::readTypeResource
              (*(void **)(param_1 + 0x10cc),0xc00,0x54494d47,
               dItem_data::item_resource[*(int *)(param_1 + 0xec) - 0x65U & 0xff].mIconFilename,
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
    J2DPicture::changeTexture
              (*(J2DPicture **)(param_1 + 0x7e4),*(ResTIMG **)(param_1 + 0x10cc),'\0');
  }
  else {
    iVar4 = 0;
    iVar10 = 10;
    do {
      *(undefined *)(*(int *)(param_1 + iVar4 + 0x624) + 0xaa) = 0;
      iVar4 = iVar4 + 0x38;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    *(undefined2 *)(param_1 + 0x81a) = 1;
    dVar13 = (double)(*(float *)(param_1 + 0x4b0) - *(float *)(param_1 + 0x558));
    iVar4 = 0;
    iVar10 = 0;
    dVar14 = (double)_5088;
    do {
      iVar9 = param_1 + iVar10;
      *(float *)(iVar9 + 0x570) = (float)dVar14;
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(iVar9 + 0x544),dVar13,(double)_4185);
      *(undefined4 *)(iVar9 + 0x548) = *(undefined4 *)(iVar9 + 0x550);
      *(undefined4 *)(iVar9 + 0x558) = *(undefined4 *)(iVar9 + 0x560);
      *(undefined4 *)(iVar9 + 0x568) = *(undefined4 *)(iVar9 + 0x570);
      iVar4 = iVar4 + 1;
      iVar10 = iVar10 + 0x38;
    } while (iVar4 < 4);
  }
  iVar4 = *(int *)(param_1 + 0xec);
  if (iVar4 == 0x66) {
    iVar4 = *(int *)(param_1 + 0x7e4);
    *(undefined *)(iVar4 + 0x108) = 10;
    *(undefined *)(iVar4 + 0x109) = 0x28;
    *(undefined *)(iVar4 + 0x10a) = 10;
    *(undefined *)(iVar4 + 0x10b) = 0;
    iVar4 = *(int *)(param_1 + 0x7e4);
    *(undefined *)(iVar4 + 0x104) = 0x28;
    *(undefined *)(iVar4 + 0x105) = 0xff;
    *(undefined *)(iVar4 + 0x106) = 0x28;
    *(undefined *)(iVar4 + 0x107) = 0xff;
  }
  else {
    if (iVar4 == 0x67) {
      iVar4 = *(int *)(param_1 + 0x7e4);
      *(undefined *)(iVar4 + 0x108) = 0x14;
      *(undefined *)(iVar4 + 0x109) = 0x14;
      *(undefined *)(iVar4 + 0x10a) = 0xa0;
      *(undefined *)(iVar4 + 0x10b) = 0;
      iVar4 = *(int *)(param_1 + 0x7e4);
      *(undefined *)(iVar4 + 0x104) = 0x32;
      *(undefined *)(iVar4 + 0x105) = 200;
      *(undefined *)(iVar4 + 0x106) = 0xff;
      *(undefined *)(iVar4 + 0x107) = 0xff;
    }
    else {
      if (iVar4 == 0x68) {
        iVar4 = *(int *)(param_1 + 0x7e4);
        *(undefined *)(iVar4 + 0x108) = 0x50;
        *(undefined *)(iVar4 + 0x109) = 0x50;
        *(undefined *)(iVar4 + 0x10a) = 0;
        *(undefined *)(iVar4 + 0x10b) = 0;
        iVar4 = *(int *)(param_1 + 0x7e4);
        *(undefined *)(iVar4 + 0x104) = 0xff;
        *(undefined *)(iVar4 + 0x105) = 0xff;
        *(undefined *)(iVar4 + 0x106) = 0;
        *(undefined *)(iVar4 + 0x107) = 0xff;
      }
      else {
        if (iVar4 == 0x69) {
          iVar4 = *(int *)(param_1 + 0x7e4);
          *(undefined *)(iVar4 + 0x108) = 0x50;
          *(undefined *)(iVar4 + 0x109) = 0x28;
          *(undefined *)(iVar4 + 0x10a) = 0x28;
          *(undefined *)(iVar4 + 0x10b) = 0;
          iVar4 = *(int *)(param_1 + 0x7e4);
          *(undefined *)(iVar4 + 0x104) = 0xff;
          *(undefined *)(iVar4 + 0x105) = 0x50;
          *(undefined *)(iVar4 + 0x106) = 0x50;
          *(undefined *)(iVar4 + 0x107) = 0xff;
        }
        else {
          if (iVar4 == 0x6a) {
            iVar4 = *(int *)(param_1 + 0x7e4);
            *(undefined *)(iVar4 + 0x108) = 0x50;
            *(undefined *)(iVar4 + 0x109) = 0x1e;
            *(undefined *)(iVar4 + 0x10a) = 0x82;
            *(undefined *)(iVar4 + 0x10b) = 0;
            iVar4 = *(int *)(param_1 + 0x7e4);
            *(undefined *)(iVar4 + 0x104) = 0xbe;
            *(undefined *)(iVar4 + 0x105) = 0x78;
            *(undefined *)(iVar4 + 0x106) = 0xff;
            *(undefined *)(iVar4 + 0x107) = 0xff;
          }
          else {
            if (iVar4 == 0x6b) {
              iVar4 = *(int *)(param_1 + 0x7e4);
              *(undefined *)(iVar4 + 0x108) = 0x50;
              *(undefined *)(iVar4 + 0x109) = 0x28;
              *(undefined *)(iVar4 + 0x10a) = 0;
              *(undefined *)(iVar4 + 0x10b) = 0;
              iVar4 = *(int *)(param_1 + 0x7e4);
              *(undefined *)(iVar4 + 0x104) = 0xff;
              *(undefined *)(iVar4 + 0x105) = 0x8c;
              *(undefined *)(iVar4 + 0x106) = 0;
              *(undefined *)(iVar4 + 0x107) = 0xff;
            }
            else {
              if (iVar4 == 0x74) {
                iVar4 = *(int *)(param_1 + 0x7e4);
                *(undefined *)(iVar4 + 0x108) = 0;
                *(undefined *)(iVar4 + 0x109) = 0;
                *(undefined *)(iVar4 + 0x10a) = 0;
                *(undefined *)(iVar4 + 0x10b) = 0;
                iVar4 = *(int *)(param_1 + 0x7e4);
                *(undefined *)(iVar4 + 0x104) = 0xff;
                *(undefined *)(iVar4 + 0x105) = 0xff;
                *(undefined *)(iVar4 + 0x106) = 0xff;
                *(undefined *)(iVar4 + 0x107) = 0xff;
              }
              else {
                if (iVar4 == 0x7f) {
                  iVar4 = *(int *)(param_1 + 0x7e4);
                  *(undefined *)(iVar4 + 0x108) = 0x50;
                  *(undefined *)(iVar4 + 0x109) = 0x50;
                  *(undefined *)(iVar4 + 0x10a) = 0;
                  *(undefined *)(iVar4 + 0x10b) = 0;
                  iVar4 = *(int *)(param_1 + 0x7e4);
                  *(undefined *)(iVar4 + 0x104) = 0xff;
                  *(undefined *)(iVar4 + 0x105) = 0xff;
                  *(undefined *)(iVar4 + 0x106) = 0;
                  *(undefined *)(iVar4 + 0x107) = 0xff;
                }
                else {
                  if ((((iVar4 == 0x118) || (iVar4 == 0x119)) || (iVar4 == 0x11a)) ||
                     ((iVar4 == 0x11b || (iVar4 == 0x11c)))) {
                    iVar4 = *(int *)(param_1 + 0x7e4);
                    *(undefined *)(iVar4 + 0x108) = 0x50;
                    *(undefined *)(iVar4 + 0x109) = 0x1e;
                    *(undefined *)(iVar4 + 0x10a) = 0x82;
                    *(undefined *)(iVar4 + 0x10b) = 0;
                    iVar4 = *(int *)(param_1 + 0x7e4);
                    *(undefined *)(iVar4 + 0x104) = 0xbe;
                    *(undefined *)(iVar4 + 0x105) = 0x78;
                    *(undefined *)(iVar4 + 0x106) = 0xff;
                    *(undefined *)(iVar4 + 0x107) = 0xff;
                  }
                  else {
                    if (iVar4 == 0x11d) {
                      iVar4 = *(int *)(param_1 + 0x7e4);
                      *(undefined *)(iVar4 + 0x108) = 0x50;
                      *(undefined *)(iVar4 + 0x109) = 0x28;
                      *(undefined *)(iVar4 + 0x10a) = 0;
                      *(undefined *)(iVar4 + 0x10b) = 0;
                      iVar4 = *(int *)(param_1 + 0x7e4);
                      *(undefined *)(iVar4 + 0x104) = 0xff;
                      *(undefined *)(iVar4 + 0x105) = 0x8c;
                      *(undefined *)(iVar4 + 0x106) = 0;
                      *(undefined *)(iVar4 + 0x107) = 0xff;
                    }
                    else {
                      if (iVar4 == 0xd2) {
                        iVar4 = *(int *)(param_1 + 0x7e4);
                        *(undefined *)(iVar4 + 0x108) = 0;
                        *(undefined *)(iVar4 + 0x109) = 0;
                        *(undefined *)(iVar4 + 0x10a) = 0;
                        *(undefined *)(iVar4 + 0x10b) = 0;
                        iVar4 = *(int *)(param_1 + 0x7e4);
                        *(undefined *)(iVar4 + 0x104) = 0x50;
                        *(undefined *)(iVar4 + 0x105) = 0xff;
                        *(undefined *)(iVar4 + 0x106) = 0xff;
                        *(undefined *)(iVar4 + 0x107) = 0xff;
                      }
                      else {
                        if (iVar4 == 0xd3) {
                          iVar4 = *(int *)(param_1 + 0x7e4);
                          *(undefined *)(iVar4 + 0x108) = 0;
                          *(undefined *)(iVar4 + 0x109) = 0;
                          *(undefined *)(iVar4 + 0x10a) = 0;
                          *(undefined *)(iVar4 + 0x10b) = 0;
                          iVar4 = *(int *)(param_1 + 0x7e4);
                          *(undefined *)(iVar4 + 0x104) = 0xaa;
                          *(undefined *)(iVar4 + 0x105) = 0xaa;
                          *(undefined *)(iVar4 + 0x106) = 0xff;
                          *(undefined *)(iVar4 + 0x107) = 0xff;
                        }
                        else {
                          if (iVar4 == 0xd4) {
                            iVar4 = *(int *)(param_1 + 0x7e4);
                            *(undefined *)(iVar4 + 0x108) = 0;
                            *(undefined *)(iVar4 + 0x109) = 0;
                            *(undefined *)(iVar4 + 0x10a) = 0;
                            *(undefined *)(iVar4 + 0x10b) = 0;
                            iVar4 = *(int *)(param_1 + 0x7e4);
                            *(undefined *)(iVar4 + 0x104) = 0xff;
                            *(undefined *)(iVar4 + 0x105) = 200;
                            *(undefined *)(iVar4 + 0x106) = 0;
                            *(undefined *)(iVar4 + 0x107) = 0xff;
                          }
                          else {
                            if (iVar4 == 0xd5) {
                              iVar4 = *(int *)(param_1 + 0x7e4);
                              *(undefined *)(iVar4 + 0x108) = 0;
                              *(undefined *)(iVar4 + 0x109) = 0;
                              *(undefined *)(iVar4 + 0x10a) = 0;
                              *(undefined *)(iVar4 + 0x10b) = 0;
                              iVar4 = *(int *)(param_1 + 0x7e4);
                              *(undefined *)(iVar4 + 0x104) = 0xff;
                              *(undefined *)(iVar4 + 0x105) = 0x50;
                              *(undefined *)(iVar4 + 0x106) = 0x50;
                              *(undefined *)(iVar4 + 0x107) = 0xff;
                            }
                            else {
                              if (iVar4 == 0xd6) {
                                iVar4 = *(int *)(param_1 + 0x7e4);
                                *(undefined *)(iVar4 + 0x108) = 0;
                                *(undefined *)(iVar4 + 0x109) = 0;
                                *(undefined *)(iVar4 + 0x10a) = 0;
                                *(undefined *)(iVar4 + 0x10b) = 0;
                                iVar4 = *(int *)(param_1 + 0x7e4);
                                *(undefined *)(iVar4 + 0x104) = 0xdc;
                                *(undefined *)(iVar4 + 0x105) = 0x96;
                                *(undefined *)(iVar4 + 0x106) = 0xff;
                                *(undefined *)(iVar4 + 0x107) = 0xff;
                              }
                              else {
                                if (iVar4 == 0xd7) {
                                  iVar4 = *(int *)(param_1 + 0x7e4);
                                  *(undefined *)(iVar4 + 0x108) = 0;
                                  *(undefined *)(iVar4 + 0x109) = 0;
                                  *(undefined *)(iVar4 + 0x10a) = 0;
                                  *(undefined *)(iVar4 + 0x10b) = 0;
                                  iVar4 = *(int *)(param_1 + 0x7e4);
                                  *(undefined *)(iVar4 + 0x104) = 0xff;
                                  *(undefined *)(iVar4 + 0x105) = 0xff;
                                  *(undefined *)(iVar4 + 0x106) = 0xff;
                                  *(undefined *)(iVar4 + 0x107) = 0xff;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  fVar2 = _5090;
  fVar1 = _4290;
  iVar4 = *(int *)(param_1 + 0xec);
  if (iVar4 == 0xc6) {
    *(float *)(param_1 + 0x810) = _4290;
    *(float *)(param_1 + 0x814) = fVar1;
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(param_1 + 0x7e4),(double)_4185,(double)_4185);
  }
  else {
    if (iVar4 == 199) {
      *(float *)(param_1 + 0x810) = _5089;
      *(float *)(param_1 + 0x814) = _5090;
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(param_1 + 0x7e4),(double)_4185,(double)_4185);
    }
    else {
      if (iVar4 == 200) {
        *(float *)(param_1 + 0x810) = _4290;
        *(float *)(param_1 + 0x814) = fVar1;
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(param_1 + 0x7e4),(double)_4185,(double)_4185);
      }
      else {
        if (iVar4 == 0xc9) {
          *(float *)(param_1 + 0x810) = _4290;
          *(float *)(param_1 + 0x814) = fVar1;
          f_op_msg_mng::fopMsgM_paneTrans
                    ((fopMsgM_pane_class *)(param_1 + 0x7e4),(double)_4185,(double)_4185);
        }
        else {
          if (iVar4 == 0xca) {
            *(float *)(param_1 + 0x810) = _5091;
            *(float *)(param_1 + 0x814) = _5090;
            f_op_msg_mng::fopMsgM_paneTrans
                      ((fopMsgM_pane_class *)(param_1 + 0x7e4),(double)_4185,(double)_4185);
          }
          else {
            if (iVar4 == 0xcb) {
              *(float *)(param_1 + 0x810) = _5092;
              *(float *)(param_1 + 0x814) = _4290;
              f_op_msg_mng::fopMsgM_paneTrans
                        ((fopMsgM_pane_class *)(param_1 + 0x7e4),(double)_4185,(double)_4185);
            }
            else {
              if (iVar4 == 0xcc) {
                *(float *)(param_1 + 0x810) = _5090;
                *(float *)(param_1 + 0x814) = _4290;
                f_op_msg_mng::fopMsgM_paneTrans
                          ((fopMsgM_pane_class *)(param_1 + 0x7e4),(double)_4185,(double)_4185);
              }
              else {
                if (iVar4 == 0xcd) {
                  *(float *)(param_1 + 0x810) = _5090;
                  *(float *)(param_1 + 0x814) = fVar2;
                  f_op_msg_mng::fopMsgM_paneTrans
                            ((fopMsgM_pane_class *)(param_1 + 0x7e4),(double)_4185,(double)_4185);
                }
              }
            }
          }
        }
      }
    }
  }
  if (*(char *)(param_1 + 0x10c) == '\x01') {
    iVar4 = *(int *)(param_1 + 0x49c);
    *(undefined *)(iVar4 + 0x108) = 0;
    *(undefined *)(iVar4 + 0x109) = 0;
    *(undefined *)(iVar4 + 0x10a) = 0;
    *(undefined *)(iVar4 + 0x10b) = 0;
    iVar4 = *(int *)(param_1 + 0x49c);
    *(undefined *)(iVar4 + 0x104) = 0xff;
    *(undefined *)(iVar4 + 0x105) = 0xff;
    *(undefined *)(iVar4 + 0x106) = 0xff;
    *(undefined *)(iVar4 + 0x107) = 0xff;
    iVar4 = *(int *)(param_1 + 0x49c);
    *(undefined *)(iVar4 + 0x10c) = 0x32;
    *(undefined *)(iVar4 + 0x10d) = 0x32;
    *(undefined *)(iVar4 + 0x10e) = 0xb4;
    *(undefined *)(iVar4 + 0x10f) = 0xff;
    *(undefined *)(iVar4 + 0x110) = 0x32;
    *(undefined *)(iVar4 + 0x111) = 0x32;
    *(undefined *)(iVar4 + 0x112) = 0xb4;
    *(undefined *)(iVar4 + 0x113) = 0xff;
    *(undefined *)(iVar4 + 0x114) = 0x32;
    *(undefined *)(iVar4 + 0x115) = 0x32;
    *(undefined *)(iVar4 + 0x116) = 0xb4;
    *(undefined *)(iVar4 + 0x117) = 0x96;
    *(undefined *)(iVar4 + 0x118) = 100;
    *(undefined *)(iVar4 + 0x119) = 100;
    *(undefined *)(iVar4 + 0x11a) = 0x78;
    *(undefined *)(iVar4 + 0x11b) = 0xff;
  }
  J2DTextBox::setFont(*(J2DTextBox **)(param_1 + 0x544),textFont);
  J2DTextBox::setFont(*(J2DTextBox **)(param_1 + 0x57c),rubyFont);
  J2DTextBox::setFont(*(J2DTextBox **)(param_1 + 0x5b4),textFont);
  J2DTextBox::setFont(*(J2DTextBox **)(param_1 + 0x5ec),rubyFont);
  iVar4 = 0;
  iVar10 = 0;
  do {
    J2DTextBox::setFont(*(J2DTextBox **)((int)&numberPane + iVar10),textFont);
    iVar4 = iVar4 + 1;
    iVar10 = iVar10 + 4;
  } while (iVar4 < 3);
  textOffsetY = 2;
  uStack100 = (int)DAT_803e6bb4 ^ 0x80000000;
  local_68 = 0x43300000;
  fVar1 = (float)((double)CONCAT44(0x43300000,uStack100) - _4188);
  local_60 = 0x43300000;
  fVar2 = (float)((double)CONCAT44(0x43300000,uStack100) - _4188);
  iVar4 = *(int *)(param_1 + 0x544);
  fVar3 = _4185;
  if (_4185 < fVar1) {
    fVar3 = fVar1;
  }
  *(float *)(iVar4 + 0xe8) = fVar3;
  fVar3 = _4185;
  if (_4185 < fVar2) {
    fVar3 = fVar2;
  }
  *(float *)(iVar4 + 0xec) = fVar3;
  iVar4 = *(int *)(param_1 + 0x5b4);
  fVar3 = _4185;
  if (_4185 < fVar1) {
    fVar3 = fVar1;
  }
  *(float *)(iVar4 + 0xe8) = fVar3;
  fVar3 = _4185;
  if (_4185 < fVar2) {
    fVar3 = fVar2;
  }
  *(float *)(iVar4 + 0xec) = fVar3;
  iVar4 = 0;
  iVar10 = 0;
  dVar13 = (double)fVar2;
  dVar14 = (double)_4185;
  uStack92 = uStack100;
  do {
    iVar9 = *(int *)((int)&numberPane + iVar10);
    dVar12 = dVar14;
    if (dVar14 < (double)fVar1) {
      dVar12 = (double)fVar1;
    }
    *(float *)(iVar9 + 0xe8) = (float)dVar12;
    dVar12 = dVar14;
    if (dVar14 < (double)fVar2) {
      dVar12 = (double)fVar2;
    }
    *(float *)(iVar9 + 0xec) = (float)dVar12;
    (**(code **)(**(int **)((int)&numberPane + iVar10) + 0x18))((double)fVar1,dVar13);
    iVar4 = iVar4 + 1;
    iVar10 = iVar10 + 4;
  } while (iVar4 < 3);
  (**(code **)(*maskPane + 0x18))((double)fVar1,dVar13);
  dVar13 = (double)CONCAT44(0x43300000,(int)DAT_803e6bac ^ 0x80000000U) - _4188;
  fVar1 = (float)dVar13;
  fVar2 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6bac ^ 0x80000000U) - _4188);
  iVar4 = *(int *)(param_1 + 0x57c);
  fVar3 = _4185;
  if (_4185 < fVar1) {
    fVar3 = fVar1;
  }
  *(float *)(iVar4 + 0xe8) = fVar3;
  fVar3 = _4185;
  if (_4185 < fVar2) {
    fVar3 = fVar2;
  }
  *(float *)(iVar4 + 0xec) = fVar3;
  iVar4 = *(int *)(param_1 + 0x5ec);
  fVar3 = _4185;
  if (_4185 < fVar1) {
    fVar3 = fVar1;
  }
  *(float *)(iVar4 + 0xe8) = fVar3;
  fVar1 = _4185;
  if (_4185 < fVar2) {
    fVar1 = fVar2;
  }
  *(float *)(iVar4 + 0xec) = fVar1;
  dVar14 = _4188;
  *(float *)(*(int *)(param_1 + 0x544) + 0xe0) =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6b9e ^ 0x80000000) - _4188);
  *(float *)(*(int *)(param_1 + 0x57c) + 0xe0) =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6ba0 ^ 0x80000000) - dVar14);
  local_48 = (double)CONCAT44(0x43300000,(int)DAT_803e6b9e ^ 0x80000000);
  *(float *)(*(int *)(param_1 + 0x5b4) + 0xe0) = (float)(local_48 - dVar14);
  local_40 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba0 ^ 0x80000000);
  *(float *)(*(int *)(param_1 + 0x5ec) + 0xe0) = (float)(local_40 - dVar14);
  iVar4 = 0;
  iVar10 = 3;
  do {
    local_40 = (double)CONCAT44(0x43300000,(int)DAT_803e6b9e ^ 0x80000000);
    *(float *)(*(int *)((int)&numberPane + iVar4) + 0xe0) = (float)(local_40 - dVar14);
    dVar12 = _4188;
    iVar4 = iVar4 + 4;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  local_40 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000);
  *(float *)(*(int *)(param_1 + 0x544) + 0xe4) = (float)(local_40 - _4188);
  local_48 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000);
  *(float *)(*(int *)(param_1 + 0x5b4) + 0xe4) = (float)(local_48 - dVar12);
  iVar4 = 0;
  iVar10 = 3;
  do {
    local_40 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000);
    *(float *)(*(int *)((int)&numberPane + iVar4) + 0xe4) = (float)(local_40 - dVar12);
    iVar4 = iVar4 + 4;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  *(int *)(param_1 + 0x110c) = (int)*(float *)(*(int *)(param_1 + 0x544) + 0xe8);
  *(int *)(param_1 + 0x1110) = (int)dVar13;
  uVar5 = *(undefined4 *)(*(int *)(param_1 + 0x50c) + 0x108);
  local_1e4 = (undefined)((uint)uVar5 >> 0x18);
  *(undefined *)(param_1 + 0x10bc) = local_1e4;
  uStack483 = (undefined)((uint)uVar5 >> 0x10);
  *(undefined *)(param_1 + 0x10bd) = uStack483;
  uStack482 = (undefined)((uint)uVar5 >> 8);
  *(undefined *)(param_1 + 0x10be) = uStack482;
  uStack481 = (undefined)uVar5;
  *(undefined *)(param_1 + 0x10bf) = uStack481;
  uVar5 = *(undefined4 *)(*(int *)(param_1 + 0x50c) + 0x104);
  local_1e8 = (undefined)((uint)uVar5 >> 0x18);
  *(undefined *)(param_1 + 0x10c4) = local_1e8;
  uStack487 = (undefined)((uint)uVar5 >> 0x10);
  *(undefined *)(param_1 + 0x10c5) = uStack487;
  uStack486 = (undefined)((uint)uVar5 >> 8);
  *(undefined *)(param_1 + 0x10c6) = uStack486;
  uStack485 = (undefined)uVar5;
  *(undefined *)(param_1 + 0x10c7) = uStack485;
  *(undefined2 *)(param_1 + 0x2a2) = 0;
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  __psq_l0(auStack24,uVar11);
  __psq_l1(auStack24,uVar11);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8020d138) */
/* WARNING: Removing unreachable block (ram,0x8020d130) */
/* WARNING: Removing unreachable block (ram,0x8020d140) */
/* __stdcall dMsg_screenDataSetDemo(sub_msg_class *) */

void dMsg_screenDataSetDemo(int param_1)

{
  double dVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  J2DScreen *pJVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  double dVar10;
  undefined8 in_f29;
  double dVar11;
  undefined8 in_f30;
  double dVar12;
  double in_f31;
  TBox2_float_ local_78;
  undefined4 local_68;
  uint uStack100;
  undefined4 local_60;
  uint uStack92;
  double local_58;
  double local_50;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,SUB84(in_f31,0),0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  pJVar5 = (J2DScreen *)JKernel::operator_new(0xd4);
  if (pJVar5 != (J2DScreen *)0x0) {
    local_78.mTL.x = _4185;
    local_78.mTL.y = _4185;
    local_78.mBR.x = _4515;
    local_78.mBR.y = _4287;
    J2DPane::J2DPane((J2DPane *)pJVar5,(J2DPane *)0x0,true,0x726f6f74,&local_78);
    (pJVar5->parent).vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    pJVar5->field_0xd0 = (_GXColor)0xffffffff;
    pJVar5->mbClipToParent = 0;
    (pJVar5->parent).vtbl = (J2DPane__vtable *)&MyScreen::__vt;
  }
  sScreen = pJVar5;
  J2DScreen::set(pJVar5,"hukidashi_05.blo",d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x74783832);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x544),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x74783833);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x57c),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x74783830);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x5b4),pJVar5);
  pJVar5 = (J2DScreen *)(*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x74783831);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x5ec),pJVar5);
  J2DTextBox::setFont(*(J2DTextBox **)(param_1 + 0x544),textFont);
  J2DTextBox::setFont(*(J2DTextBox **)(param_1 + 0x57c),rubyFont);
  J2DTextBox::setFont(*(J2DTextBox **)(param_1 + 0x5b4),textFont);
  J2DTextBox::setFont(*(J2DTextBox **)(param_1 + 0x5ec),rubyFont);
  iVar7 = 0;
  iVar8 = 0;
  do {
    J2DTextBox::setFont(*(J2DTextBox **)((int)&numberPane + iVar8),textFont);
    iVar7 = iVar7 + 1;
    iVar8 = iVar8 + 4;
  } while (iVar7 < 3);
  textOffsetY = 2;
  uStack100 = (int)DAT_803e6bb4 ^ 0x80000000;
  local_68 = 0x43300000;
  dVar1 = (double)CONCAT44(0x43300000,uStack100) - _4188;
  fVar2 = (float)dVar1;
  local_60 = 0x43300000;
  fVar3 = (float)((double)CONCAT44(0x43300000,uStack100) - _4188);
  iVar7 = *(int *)(param_1 + 0x544);
  fVar4 = _4185;
  if (_4185 < fVar2) {
    fVar4 = fVar2;
  }
  *(float *)(iVar7 + 0xe8) = fVar4;
  fVar4 = _4185;
  if (_4185 < fVar3) {
    fVar4 = fVar3;
  }
  *(float *)(iVar7 + 0xec) = fVar4;
  iVar7 = *(int *)(param_1 + 0x5b4);
  fVar4 = _4185;
  if (_4185 < fVar2) {
    fVar4 = fVar2;
  }
  *(float *)(iVar7 + 0xe8) = fVar4;
  fVar4 = _4185;
  if (_4185 < fVar3) {
    fVar4 = fVar3;
  }
  *(float *)(iVar7 + 0xec) = fVar4;
  iVar7 = 0;
  iVar8 = 0;
  dVar11 = (double)fVar3;
  dVar12 = (double)_4185;
  uStack92 = uStack100;
  do {
    iVar6 = *(int *)((int)&numberPane + iVar8);
    dVar10 = dVar12;
    if (dVar12 < (double)fVar2) {
      dVar10 = (double)fVar2;
    }
    *(float *)(iVar6 + 0xe8) = (float)dVar10;
    dVar10 = dVar12;
    if (dVar12 < (double)fVar3) {
      dVar10 = (double)fVar3;
    }
    *(float *)(iVar6 + 0xec) = (float)dVar10;
    (**(code **)(**(int **)((int)&numberPane + iVar8) + 0x18))((double)fVar2,dVar11);
    iVar7 = iVar7 + 1;
    iVar8 = iVar8 + 4;
  } while (iVar7 < 3);
  (**(code **)(*maskPane + 0x18))((double)fVar2,dVar11);
  dVar11 = _4188;
  *(float *)(*(int *)(param_1 + 0x544) + 0xe0) =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6b9e ^ 0x80000000) - _4188);
  *(float *)(*(int *)(param_1 + 0x57c) + 0xe0) =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6ba0 ^ 0x80000000) - dVar11);
  local_58 = (double)CONCAT44(0x43300000,(int)DAT_803e6b9e ^ 0x80000000);
  *(float *)(*(int *)(param_1 + 0x5b4) + 0xe0) = (float)(local_58 - dVar11);
  local_50 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba0 ^ 0x80000000);
  *(float *)(*(int *)(param_1 + 0x5ec) + 0xe0) = (float)(local_50 - dVar11);
  iVar7 = 0;
  iVar8 = 3;
  do {
    local_50 = (double)CONCAT44(0x43300000,(int)DAT_803e6b9e ^ 0x80000000);
    *(float *)(*(int *)((int)&numberPane + iVar7) + 0xe0) = (float)(local_50 - dVar11);
    dVar12 = _4188;
    iVar7 = iVar7 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  local_50 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000);
  *(float *)(*(int *)(param_1 + 0x544) + 0xe4) = (float)(local_50 - _4188);
  local_58 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000);
  *(float *)(*(int *)(param_1 + 0x5b4) + 0xe4) = (float)(local_58 - dVar12);
  iVar7 = 0;
  iVar8 = 3;
  do {
    local_50 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000);
    *(float *)(*(int *)((int)&numberPane + iVar7) + 0xe4) = (float)(local_50 - dVar12);
    iVar7 = iVar7 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  *(int *)(param_1 + 0x110c) = (int)dVar1;
  *(int *)(param_1 + 0x1110) = (int)in_f31;
  *(undefined2 *)(param_1 + 0x2a2) = 0;
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  __psq_l0(auStack40,uVar9);
  __psq_l1(auStack40,uVar9);
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x8020da98) */
/* WARNING: Removing unreachable block (ram,0x8020daa0) */
/* __stdcall dMsg_screenDataSetTact(sub_msg_class *) */

void dMsg_screenDataSetTact(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  J2DScreen *pJVar4;
  int iVar5;
  ulong uVar6;
  void *pvVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  double dVar12;
  undefined8 in_f30;
  double dVar13;
  undefined8 in_f31;
  double dVar14;
  TBox2_float_ local_a0;
  TBox2_float_ local_90;
  undefined4 local_80;
  uint uStack124;
  undefined4 local_78;
  uint uStack116;
  undefined4 local_70;
  uint uStack108;
  undefined4 local_68;
  uint uStack100;
  double local_60;
  double local_58;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  pJVar4 = (J2DScreen *)JKernel::operator_new(0xd4);
  if (pJVar4 != (J2DScreen *)0x0) {
    local_a0.mTL.x = _4185;
    local_a0.mTL.y = _4185;
    local_a0.mBR.x = _4515;
    local_a0.mBR.y = _4287;
    J2DPane::J2DPane((J2DPane *)pJVar4,(J2DPane *)0x0,true,0x726f6f74,&local_a0);
    (pJVar4->parent).vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    pJVar4->field_0xd0 = (_GXColor)0xffffffff;
    pJVar4->mbClipToParent = 0;
    (pJVar4->parent).vtbl = (J2DPane__vtable *)&MyScreen::__vt;
  }
  sScreen = pJVar4;
  J2DScreen::set(pJVar4,"hukidashi_14.blo",d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive);
  if ((*(uint *)(param_1 + 0xec) < 0x5ac) || (0x5b2 < *(uint *)(param_1 + 0xec))) {
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x49c),sScreen,0x6d313432);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x544),sScreen,0x74313432);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x57c),sScreen,0x72313432);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x5b4),sScreen,0x6b313432);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x5ec),sScreen,0x62313432);
    iVar5 = (*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6d313431);
    *(undefined *)(iVar5 + 0xaa) = 0;
    iVar5 = (*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x74313431);
    *(undefined *)(iVar5 + 0xaa) = 0;
    iVar5 = (*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x72313431);
    *(undefined *)(iVar5 + 0xaa) = 0;
    iVar5 = (*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6b313431);
    *(undefined *)(iVar5 + 0xaa) = 0;
    iVar5 = (*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x62313431);
    *(undefined *)(iVar5 + 0xaa) = 0;
  }
  else {
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x49c),sScreen,0x6d313431);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x544),sScreen,0x74313431);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x57c),sScreen,0x72313431);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x5b4),sScreen,0x6b313431);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0x5ec),sScreen,0x62313431);
    iVar5 = (*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6d313432);
    *(undefined *)(iVar5 + 0xaa) = 0;
    iVar5 = (*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x74313432);
    *(undefined *)(iVar5 + 0xaa) = 0;
    iVar5 = (*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x72313432);
    *(undefined *)(iVar5 + 0xaa) = 0;
    iVar5 = (*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x6b313432);
    *(undefined *)(iVar5 + 0xaa) = 0;
    iVar5 = (*(code *)((sScreen->parent).vtbl)->search)(sScreen,0x62313432);
    *(undefined *)(iVar5 + 0xaa) = 0;
  }
  if ((*(int *)(param_1 + 0xec) == 0x5b3) || (*(int *)(param_1 + 0xec) == 0x5b4)) {
    if (7 < d_com_inf_game::g_dComIfG_gameInfo._23536_1_) {
      uVar6 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar6,"d_msg.cpp",0x40c,"dComIfGp_getMelodyNum() <= 7");
      m_Do_printf::OSPanic("d_msg.cpp",0x40c,&DAT_80361ec0);
    }
    pJVar4 = (J2DScreen *)JKernel::operator_new(0xd4);
    if (pJVar4 != (J2DScreen *)0x0) {
      local_90.mTL.x = _4185;
      local_90.mTL.y = _4185;
      local_90.mBR.x = _4515;
      local_90.mBR.y = _4287;
      J2DPane::J2DPane((J2DPane *)pJVar4,(J2DPane *)0x0,true,0x726f6f74,&local_90);
      (pJVar4->parent).vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
      pJVar4->field_0xd0 = (_GXColor)0xffffffff;
      pJVar4->mbClipToParent = 0;
    }
    sScreen2 = pJVar4;
    J2DScreen::set(pJVar4,(&mLayout)[d_com_inf_game::g_dComIfG_gameInfo._23536_1_],
                   d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive);
    iVar10 = 0;
    iVar9 = 0;
    for (iVar5 = 0;
        iVar5 < (int)(uint)(byte)(&mBeatNum)[d_com_inf_game::g_dComIfG_gameInfo._23536_1_];
        iVar5 = iVar5 + 1) {
      iVar8 = param_1 + iVar9;
      f_op_msg_mng::fopMsgM_setPaneData
                ((fopMsgM_pane_class *)(iVar8 + 0x8c4),sScreen2,*(int *)((int)&ar_t_5217 + iVar10));
      f_op_msg_mng::fopMsgM_setPaneData
                ((fopMsgM_pane_class *)(iVar8 + 0xa14),sScreen2,*(int *)((int)&wn_t_5218 + iVar10));
      f_op_msg_mng::fopMsgM_setPaneData
                ((fopMsgM_pane_class *)(iVar8 + 0xb64),sScreen2,*(int *)((int)&bs_t_5219 + iVar10));
      if (4 < d_com_inf_game::g_dComIfG_gameInfo._23536_1_) {
        f_op_msg_mng::fopMsgM_setPaneData
                  ((fopMsgM_pane_class *)(iVar8 + 0xcb4),sScreen2,*(int *)((int)&i0_t_5220 + iVar10)
                  );
      }
      iVar10 = iVar10 + 4;
      iVar9 = iVar9 + 0x38;
    }
  }
  J2DTextBox::setFont(*(J2DTextBox **)(param_1 + 0x544),textFont);
  J2DTextBox::setFont(*(J2DTextBox **)(param_1 + 0x57c),rubyFont);
  J2DTextBox::setFont(*(J2DTextBox **)(param_1 + 0x5b4),textFont);
  J2DTextBox::setFont(*(J2DTextBox **)(param_1 + 0x5ec),rubyFont);
  iVar5 = 0;
  iVar9 = 0;
  do {
    J2DTextBox::setFont(*(J2DTextBox **)((int)&numberPane + iVar9),textFont);
    iVar5 = iVar5 + 1;
    iVar9 = iVar9 + 4;
  } while (iVar5 < 3);
  textOffsetY = 2;
  uStack124 = (int)DAT_803e6bb4 ^ 0x80000000;
  local_80 = 0x43300000;
  fVar1 = (float)((double)CONCAT44(0x43300000,uStack124) - _4188);
  local_78 = 0x43300000;
  fVar2 = (float)((double)CONCAT44(0x43300000,uStack124) - _4188);
  iVar5 = *(int *)(param_1 + 0x544);
  fVar3 = _4185;
  if (_4185 < fVar1) {
    fVar3 = fVar1;
  }
  *(float *)(iVar5 + 0xe8) = fVar3;
  fVar3 = _4185;
  if (_4185 < fVar2) {
    fVar3 = fVar2;
  }
  *(float *)(iVar5 + 0xec) = fVar3;
  iVar5 = *(int *)(param_1 + 0x5b4);
  fVar3 = _4185;
  if (_4185 < fVar1) {
    fVar3 = fVar1;
  }
  *(float *)(iVar5 + 0xe8) = fVar3;
  fVar3 = _4185;
  if (_4185 < fVar2) {
    fVar3 = fVar2;
  }
  *(float *)(iVar5 + 0xec) = fVar3;
  iVar5 = 0;
  iVar9 = 0;
  dVar13 = (double)fVar2;
  dVar14 = (double)_4185;
  uStack116 = uStack124;
  do {
    iVar10 = *(int *)((int)&numberPane + iVar9);
    dVar12 = dVar14;
    if (dVar14 < (double)fVar1) {
      dVar12 = (double)fVar1;
    }
    *(float *)(iVar10 + 0xe8) = (float)dVar12;
    dVar12 = dVar14;
    if (dVar14 < (double)fVar2) {
      dVar12 = (double)fVar2;
    }
    *(float *)(iVar10 + 0xec) = (float)dVar12;
    (**(code **)(**(int **)((int)&numberPane + iVar9) + 0x18))((double)fVar1,dVar13);
    iVar5 = iVar5 + 1;
    iVar9 = iVar9 + 4;
  } while (iVar5 < 3);
  (**(code **)(*maskPane + 0x18))((double)fVar1,dVar13);
  uStack124 = (int)DAT_803e6bac ^ 0x80000000;
  local_78 = 0x43300000;
  dVar13 = (double)CONCAT44(0x43300000,uStack124) - _4188;
  fVar1 = (float)dVar13;
  local_80 = 0x43300000;
  fVar2 = (float)((double)CONCAT44(0x43300000,uStack124) - _4188);
  iVar5 = *(int *)(param_1 + 0x57c);
  fVar3 = _4185;
  if (_4185 < fVar1) {
    fVar3 = fVar1;
  }
  *(float *)(iVar5 + 0xe8) = fVar3;
  fVar3 = _4185;
  if (_4185 < fVar2) {
    fVar3 = fVar2;
  }
  *(float *)(iVar5 + 0xec) = fVar3;
  iVar5 = *(int *)(param_1 + 0x5ec);
  fVar3 = _4185;
  if (_4185 < fVar1) {
    fVar3 = fVar1;
  }
  *(float *)(iVar5 + 0xe8) = fVar3;
  fVar1 = _4185;
  if (_4185 < fVar2) {
    fVar1 = fVar2;
  }
  *(float *)(iVar5 + 0xec) = fVar1;
  dVar14 = _4188;
  uStack108 = (int)DAT_803e6b9e ^ 0x80000000;
  local_70 = 0x43300000;
  *(float *)(*(int *)(param_1 + 0x544) + 0xe0) =
       (float)((double)CONCAT44(0x43300000,uStack108) - _4188);
  uStack100 = (int)DAT_803e6ba0 ^ 0x80000000;
  local_68 = 0x43300000;
  *(float *)(*(int *)(param_1 + 0x57c) + 0xe0) =
       (float)((double)CONCAT44(0x43300000,uStack100) - dVar14);
  local_60 = (double)CONCAT44(0x43300000,(int)DAT_803e6b9e ^ 0x80000000);
  *(float *)(*(int *)(param_1 + 0x5b4) + 0xe0) = (float)(local_60 - dVar14);
  local_58 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba0 ^ 0x80000000);
  *(float *)(*(int *)(param_1 + 0x5ec) + 0xe0) = (float)(local_58 - dVar14);
  iVar5 = 0;
  iVar9 = 3;
  do {
    local_58 = (double)CONCAT44(0x43300000,(int)DAT_803e6b9e ^ 0x80000000);
    *(float *)(*(int *)((int)&numberPane + iVar5) + 0xe0) = (float)(local_58 - dVar14);
    dVar12 = _4188;
    iVar5 = iVar5 + 4;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  local_58 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000);
  *(float *)(*(int *)(param_1 + 0x544) + 0xe4) = (float)(local_58 - _4188);
  local_60 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000);
  *(float *)(*(int *)(param_1 + 0x5b4) + 0xe4) = (float)(local_60 - dVar12);
  iVar5 = 0;
  iVar9 = 3;
  do {
    local_58 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000);
    *(float *)(*(int *)((int)&numberPane + iVar5) + 0xe4) = (float)(local_58 - dVar12);
    iVar5 = iVar5 + 4;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  iVar5 = (int)*(float *)(*(int *)(param_1 + 0x544) + 0xe8);
  local_58 = (double)(longlong)iVar5;
  *(int *)(param_1 + 0x110c) = iVar5;
  iVar5 = (int)dVar13;
  local_60 = (double)(longlong)iVar5;
  *(int *)(param_1 + 0x1110) = iVar5;
  *(undefined *)(param_1 + 0x1168) = DAT_803a2caf;
  *(undefined4 *)(param_1 + 0x1144) = 0;
  uStack116 = uStack124;
  pvVar7 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x1a280,0x20);
  *(void **)(param_1 + 0x10cc) = pvVar7;
  if (*(int *)(param_1 + 0x10cc) == 0) {
    uVar6 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar6,"d_msg.cpp",0x468,"i_Msg->buffer_p != 0");
    m_Do_printf::OSPanic("d_msg.cpp",0x468,&DAT_80361ec0);
  }
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  __psq_l0(auStack24,uVar11);
  __psq_l1(auStack24,uVar11);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dMsg_screenDataSet(sub_msg_class *) */

void dMsg_screenDataSet(int param_1)

{
  bool bVar2;
  ulong uVar1;
  J2DTextBox *this;
  J2DPicture *this_00;
  int iVar3;
  int iVar4;
  
  sScreen2 = 0;
  bVar2 = f_op_msg_mng::fopMsgM_hyrule_language_check(*(undefined4 *)(param_1 + 0xec));
  if (bVar2 == false) {
    textFont = m_Do_ext::mDoExt_getMesgFont();
    if (textFont == (JUTFont *)0x0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"d_msg.cpp",0x48f,"textFont != 0");
      m_Do_printf::OSPanic("d_msg.cpp",0x48f,&DAT_80361ec0);
    }
    dMsg_font_flag = 0;
  }
  else {
    textFont = m_Do_ext::mDoExt_getRubyFont();
    if (textFont == (JUTFont *)0x0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"d_msg.cpp",0x48a,"textFont != 0");
      m_Do_printf::OSPanic("d_msg.cpp",0x48a,&DAT_80361ec0);
    }
    dMsg_font_flag = 1;
  }
  rubyFont = textFont;
  iVar3 = 0;
  iVar4 = 0;
  do {
    this = (J2DTextBox *)JKernel::operator_new(0x100);
    if (this != (J2DTextBox *)0x0) {
      J2DTextBox::J2DTextBox(this,"rock_24_20_4i_usa.bfn","0");
    }
    *(J2DTextBox **)((int)&numberPane + iVar4) = this;
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar3 < 3);
  this_00 = (J2DPicture *)JKernel::operator_new(0x124);
  if (this_00 != (J2DPicture *)0x0) {
    J2DPicture::J2DPicture(this_00,"black.bti");
  }
  maskPane = this_00;
  switch(*(undefined *)(param_1 + 0x10c)) {
  default:
    dMsg_screenDataSetTalk(param_1);
    break;
  case 1:
  case 9:
    dMsg_screenDataSetItem(param_1);
    break;
  case 5:
    dMsg_screenDataSetDemo(param_1);
    break;
  case 0xe:
    dMsg_screenDataSetTact(param_1);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dMsg_messagePaneShow(sub_msg_class *) */

void dMsg_messagePaneShow(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    *(undefined *)(*(int *)(param_1 + iVar2 + 0x544) + 0xaa) = 1;
    f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + iVar2 + 0x544);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 4);
  if ((*(char *)(param_1 + 0x10c) == '\t') || (*(char *)(param_1 + 0x10c) == '\x01')) {
    iVar1 = 0;
    iVar2 = 0;
    do {
      f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + iVar2 + 0x624);
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x38;
    } while (iVar1 < 10);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dMsg_messagePaneHide(sub_msg_class *) */

void dMsg_messagePaneHide(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar4 = 4;
  do {
    *(undefined *)(*(int *)(param_1 + iVar2 + 0x544) + 0xaa) = 0;
    iVar2 = iVar2 + 0x38;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  cVar1 = *(char *)(param_1 + 0x10c);
  if ((cVar1 == '\t') || (cVar1 == '\x01')) {
    iVar2 = 0;
    iVar4 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + iVar4 + 0x624));
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 0x38;
    } while (iVar2 < 10);
  }
  else {
    if ((cVar1 == '\x0e') &&
       ((*(int *)(param_1 + 0xec) == 0x5b3 || (*(int *)(param_1 + 0xec) == 0x5b4)))) {
      iVar4 = 0;
      for (iVar2 = 0;
          iVar2 < (int)(uint)(byte)(&mBeatNum)[d_com_inf_game::g_dComIfG_gameInfo._23536_1_];
          iVar2 = iVar2 + 1) {
        iVar3 = param_1 + iVar4;
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar3 + 0x8c4));
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar3 + 0xa14));
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar3 + 0xb64));
        if (4 < d_com_inf_game::g_dComIfG_gameInfo._23536_1_) {
          f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar3 + 0xcb4));
        }
        iVar4 = iVar4 + 0x38;
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8020debc) */
/* __stdcall dMsg_outFontHide(sub_msg_class *) */

void dMsg_outFontHide(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar2 = 0;
  iVar4 = 0;
  iVar3 = 0;
  dVar6 = (double)_4185;
  do {
    *(undefined *)(*(int *)((int)&button_icon + iVar3) + 0xaa) = 0;
    *(undefined *)(*(int *)((int)&button_kage + iVar3) + 0xaa) = 0;
    piVar1 = *(int **)((int)&button_icon + iVar3);
    piVar1[0x29] = (int)(float)dVar6;
    (**(code **)(*piVar1 + 0x20))();
    piVar1 = *(int **)((int)&button_kage + iVar3);
    piVar1[0x29] = (int)(float)dVar6;
    (**(code **)(*piVar1 + 0x20))();
    *(undefined2 *)((int)&buttonTimer + iVar4) = 0xffff;
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 2;
    iVar3 = iVar3 + 4;
  } while (iVar2 < 8);
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dMsg_ScreenDataValueInitTalk(sub_msg_class *) */

void dMsg_ScreenDataValueInitTalk(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  float fVar5;
  char cVar6;
  cXyz local_48;
  float local_3c;
  float local_38;
  float local_34;
  longlong local_30;
  double local_28;
  double local_20;
  
  iVar1 = (int)*(float *)(*(int *)(param_1 + 0x544) + 0xe0);
  local_30 = (longlong)iVar1;
  iVar2 = (int)*(float *)(*(int *)(param_1 + 0x57c) + 0xe0);
  local_28 = (double)(longlong)iVar2;
  local_3c = _4185;
  local_38 = _4185;
  local_34 = _4185;
  cVar6 = ::cXyz::operator___((cXyz *)(param_1 + 0xe0),(Vec *)&local_3c);
  if (cVar6 == '\0') {
    m_Do_lib::mDoLib_project((cXyz *)(param_1 + 0xe0),(cXyz *)(param_1 + 0x10e0));
  }
  else {
    *(undefined4 *)(param_1 + 0x10e0) = *(undefined4 *)(param_1 + 0x4b0);
    *(undefined4 *)(param_1 + 0x10e4) = *(undefined4 *)(param_1 + 0x4b4);
  }
  dMsg_mesgOutPos(param_1);
  local_28 = (double)(longlong)(int)*(float *)(param_1 + 0x4b8);
  *(int *)(param_1 + 0x10d8) = (int)*(float *)(param_1 + 0x4b8);
  local_30 = (longlong)(int)*(float *)(param_1 + 0x4bc);
  *(int *)(param_1 + 0x10dc) = (int)*(float *)(param_1 + 0x4bc);
  iVar3 = (int)(*(float *)(*(int *)(param_1 + 0x544) + 0xe4) * _4289);
  local_20 = (double)(longlong)iVar3;
  *(int *)(param_1 + 0x1104) = iVar3;
  *(undefined *)(param_1 + 0x10c0) = *(undefined *)(param_1 + 0x10bc);
  *(undefined *)(param_1 + 0x10c1) = *(undefined *)(param_1 + 0x10bd);
  *(undefined *)(param_1 + 0x10c2) = *(undefined *)(param_1 + 0x10be);
  *(undefined *)(param_1 + 0x10c3) = *(undefined *)(param_1 + 0x10bf);
  *(undefined *)(param_1 + 0x10c8) = *(undefined *)(param_1 + 0x10c4);
  *(undefined *)(param_1 + 0x10c9) = *(undefined *)(param_1 + 0x10c5);
  *(undefined *)(param_1 + 0x10ca) = *(undefined *)(param_1 + 0x10c6);
  *(undefined *)(param_1 + 0x10cb) = *(undefined *)(param_1 + 0x10c7);
  local_48.x = _4185;
  local_48.y = _4185;
  local_48.z = _4185;
  cVar6 = ::cXyz::operator___((cXyz *)(param_1 + 0xe0),&local_48);
  if ((cVar6 == '\0') || (*(char *)(param_1 + 0x10c) == '\n')) {
    *(undefined4 *)(param_1 + 0x10e0) = *(undefined4 *)(param_1 + 0x4b8);
    *(undefined4 *)(param_1 + 0x10e4) = *(undefined4 *)(param_1 + 0x4bc);
  }
  else {
    *(undefined4 *)(param_1 + 0x4b8) = *(undefined4 *)(param_1 + 0x10e0);
    *(undefined4 *)(param_1 + 0x4bc) = *(undefined4 *)(param_1 + 0x10e4);
  }
  fVar5 = _5611;
  *(float *)(param_1 + 0x4c8) = _5611;
  *(float *)(param_1 + 0x4cc) = fVar5 * (*(float *)(param_1 + 0x4c4) / *(float *)(param_1 + 0x4c0));
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_1 + 0x49c));
  fopMsgM_msgDataProc_c::dataInit((fopMsgM_msgDataProc_c *)(param_1 + 0xe04));
  *(undefined4 *)(param_1 + 0x1060) = *(undefined4 *)(param_1 + 0x1164);
  *(int *)(param_1 + 0xe14) = param_1 + 0xe0;
  *(undefined4 *)(param_1 + 0xe40) = *(undefined4 *)(param_1 + 0x111c);
  *(undefined4 *)(param_1 + 0xe64) = *(undefined4 *)(param_1 + 0x1120);
  *(undefined4 *)(param_1 + 0xe44) = *(undefined4 *)(param_1 + 0x1120);
  *(undefined4 *)(param_1 + 0xe68) = *(undefined4 *)(param_1 + 0x1124);
  *(undefined4 *)(param_1 + 0xe48) = *(undefined4 *)(param_1 + 0x1124);
  *(undefined4 *)(param_1 + 0xe6c) = *(undefined4 *)(param_1 + 0x1128);
  *(undefined4 *)(param_1 + 0xe4c) = *(undefined4 *)(param_1 + 0x1128);
  *(undefined4 *)(param_1 + 0xe70) = *(undefined4 *)(param_1 + 0x112c);
  *(undefined4 *)(param_1 + 0xe50) = *(undefined4 *)(param_1 + 0x112c);
  *(undefined4 *)(param_1 + 0xe54) = *(undefined4 *)(param_1 + 0x1130);
  *(undefined4 *)(param_1 + 0xe58) = *(undefined4 *)(param_1 + 0x1134);
  *(undefined4 *)(param_1 + 0xe5c) = *(undefined4 *)(param_1 + 0x1138);
  *(undefined4 *)(param_1 + 0xe60) = *(undefined4 *)(param_1 + 0x113c);
  *(undefined4 *)(param_1 + 0xe08) = textFont;
  *(undefined4 *)(param_1 + 0xe0c) = rubyFont;
  *(int *)(param_1 + 0xf20) = iVar1;
  *(int *)(param_1 + 0xf28) = iVar2;
  *(int *)(param_1 + 0xf24) = (int)*(float *)(*(int *)(param_1 + 0x544) + 0xe4);
  *(int *)(param_1 + 0xe10) = param_1 + 0x100;
  *(undefined4 *)(param_1 + 0xf48) = *(undefined4 *)(param_1 + 0x110c);
  *(undefined4 *)(param_1 + 0xf50) = *(undefined4 *)(param_1 + 0x1110);
  *(undefined4 *)(param_1 + 0xf2c) = 0x1f7;
  *(undefined4 *)(param_1 + 0xf30) = 0x1e6;
  *(uint *)(param_1 + 0xf64) = (uint)DAT_803e6bc6;
  *(undefined4 *)(param_1 + 0xf60) = 2;
  if (DAT_803e6bc7 == '\0') {
    *(undefined *)(param_1 + 0x10a0) = 0;
  }
  else {
    *(undefined *)(param_1 + 0x10a0) = 1;
  }
  dVar4 = _4188;
  local_20 = (double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x10d8) ^ 0x80000000);
  *(float *)(param_1 + 0x10d0) = (float)(local_20 - _4188) - *(float *)(param_1 + 0x4b8);
  local_28 = (double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x10dc) ^ 0x80000000);
  *(float *)(param_1 + 0x10d4) = (float)(local_28 - dVar4) - *(float *)(param_1 + 0x4bc);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall dMsg_ScreenDataValueInitItem(sub_msg_class *) */

void dMsg_ScreenDataValueInitItem(int param_1)

{
  uint uVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  float fVar6;
  int iVar7;
  double local_78;
  double local_70;
  double local_68;
  double local_30;
  double local_28;
  
  fVar3 = *(float *)(*(int *)(param_1 + 0x544) + 0xe0);
  fVar4 = *(float *)(*(int *)(param_1 + 0x57c) + 0xe0);
  dMsg_msg_pane_parts_set(param_1 + 0x49c,1);
  fVar6 = _5685;
  if (*(char *)(param_1 + 0x10e) != '\x01') {
    *(float *)(param_1 + 0x4bc) = *(float *)(param_1 + 0x4bc) + _5685;
    *(float *)(param_1 + 0x4ac) = *(float *)(param_1 + 0x4ac) + fVar6;
  }
  dMsg_arw_pane_parts_set(param_1 + 0x4d4,param_1 + 0x49c);
  dMsg_arw_pane_parts_set(param_1 + 0x50c,param_1 + 0x49c);
  *(int *)(param_1 + 0x1114) = (int)(*(float *)(param_1 + 0x4e4) + *(float *)(param_1 + 0x4fc));
  uVar1 = (uint)*(float *)(param_1 + 0x548);
  iVar2 = (int)(_4287 - (*(float *)(param_1 + 0x54c) + *(float *)(param_1 + 0x56c)));
  iVar7 = iVar2 + -0x13;
  if (*(char *)(param_1 + 0x10e) == '\x01') {
    *(uint *)(param_1 + 0x10f8) = uVar1;
    *(int *)(param_1 + 0x10fc) = iVar7;
  }
  else {
    *(uint *)(param_1 + 0x10f8) = uVar1;
    *(int *)(param_1 + 0x10fc) = iVar2 + 0xce;
  }
  local_68 = (double)CONCAT44(0x43300000,uVar1 ^ 0x80000000);
  local_70 = (double)CONCAT44(0x43300000,(iVar7 - DAT_803e6ba6) - (int)textOffsetY ^ 0x80000000);
  (**(code **)(**(int **)(param_1 + 0x544) + 0x10))
            ((double)(float)(local_68 - _4188),(double)(float)(local_70 - _4188));
  local_78 = (double)CONCAT44(0x43300000,uVar1 ^ 0x80000000);
  (**(code **)(**(int **)(param_1 + 0x57c) + 0x10))
            ((double)(float)(local_78 - _4188),
             (double)(float)((double)CONCAT44(0x43300000,
                                              (iVar7 - DAT_803e6ba4) - (int)textOffsetY ^ 0x80000000
                                             ) - _4188));
  (**(code **)(**(int **)(param_1 + 0x5b4) + 0x10))
            ((double)(float)((double)CONCAT44(0x43300000,uVar1 + 2 ^ 0x80000000) - _4188),
             (double)(float)((double)CONCAT44(0x43300000,
                                              ((iVar7 - DAT_803e6ba6) - (int)textOffsetY) + 2U ^
                                              0x80000000) - _4188));
  (**(code **)(**(int **)(param_1 + 0x5ec) + 0x10))
            ((double)(float)((double)CONCAT44(0x43300000,uVar1 + 2 ^ 0x80000000) - _4188),
             (double)(float)((double)CONCAT44(0x43300000,
                                              ((iVar7 - DAT_803e6ba4) - (int)textOffsetY) + 2U ^
                                              0x80000000) - _4188));
  *(int *)(param_1 + 0x10d8) = (int)*(float *)(param_1 + 0x4b8);
  *(int *)(param_1 + 0x10dc) = (int)*(float *)(param_1 + 0x4bc);
  *(int *)(param_1 + 0x1104) = (int)(*(float *)(*(int *)(param_1 + 0x544) + 0xe4) * _4289);
  *(undefined *)(param_1 + 0x10c0) = *(undefined *)(param_1 + 0x10bc);
  *(undefined *)(param_1 + 0x10c1) = *(undefined *)(param_1 + 0x10bd);
  *(undefined *)(param_1 + 0x10c2) = *(undefined *)(param_1 + 0x10be);
  *(undefined *)(param_1 + 0x10c3) = *(undefined *)(param_1 + 0x10bf);
  *(undefined *)(param_1 + 0x10c8) = *(undefined *)(param_1 + 0x10c4);
  *(undefined *)(param_1 + 0x10c9) = *(undefined *)(param_1 + 0x10c5);
  *(undefined *)(param_1 + 0x10ca) = *(undefined *)(param_1 + 0x10c6);
  *(undefined *)(param_1 + 0x10cb) = *(undefined *)(param_1 + 0x10c7);
  *(undefined4 *)(param_1 + 0x10e0) = *(undefined4 *)(param_1 + 0x4b8);
  *(undefined4 *)(param_1 + 0x10e4) = *(undefined4 *)(param_1 + 0x4bc);
  *(undefined4 *)(param_1 + 0x4b8) = *(undefined4 *)(param_1 + 0x10e0);
  *(undefined4 *)(param_1 + 0x4bc) = *(undefined4 *)(param_1 + 0x10e4);
  fVar6 = _5611;
  *(float *)(param_1 + 0x4c8) = _5611;
  *(float *)(param_1 + 0x4cc) = fVar6 * (*(float *)(param_1 + 0x4c4) / *(float *)(param_1 + 0x4c0));
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_1 + 0x49c));
  fopMsgM_msgDataProc_c::dataInit((fopMsgM_msgDataProc_c *)(param_1 + 0xe04));
  *(int *)(param_1 + 0xe14) = param_1 + 0xe0;
  *(undefined4 *)(param_1 + 0xe40) = *(undefined4 *)(param_1 + 0x111c);
  *(undefined4 *)(param_1 + 0xe64) = *(undefined4 *)(param_1 + 0x1120);
  *(undefined4 *)(param_1 + 0xe44) = *(undefined4 *)(param_1 + 0x1120);
  *(undefined4 *)(param_1 + 0xe68) = *(undefined4 *)(param_1 + 0x1124);
  *(undefined4 *)(param_1 + 0xe48) = *(undefined4 *)(param_1 + 0x1124);
  *(undefined4 *)(param_1 + 0xe6c) = *(undefined4 *)(param_1 + 0x1128);
  *(undefined4 *)(param_1 + 0xe4c) = *(undefined4 *)(param_1 + 0x1128);
  *(undefined4 *)(param_1 + 0xe70) = *(undefined4 *)(param_1 + 0x112c);
  *(undefined4 *)(param_1 + 0xe50) = *(undefined4 *)(param_1 + 0x112c);
  *(undefined4 *)(param_1 + 0xe54) = *(undefined4 *)(param_1 + 0x1130);
  *(undefined4 *)(param_1 + 0xe58) = *(undefined4 *)(param_1 + 0x1134);
  *(undefined4 *)(param_1 + 0xe5c) = *(undefined4 *)(param_1 + 0x1138);
  *(undefined4 *)(param_1 + 0xe60) = *(undefined4 *)(param_1 + 0x113c);
  *(undefined4 *)(param_1 + 0xe08) = textFont;
  *(undefined4 *)(param_1 + 0xe0c) = rubyFont;
  *(int *)(param_1 + 0xf20) = (int)fVar3;
  *(int *)(param_1 + 0xf28) = (int)fVar4;
  *(int *)(param_1 + 0xe10) = param_1 + 0x100;
  *(undefined4 *)(param_1 + 0xf48) = *(undefined4 *)(param_1 + 0x110c);
  *(undefined4 *)(param_1 + 0xf50) = *(undefined4 *)(param_1 + 0x1110);
  if ((*(char *)(param_1 + 0x10c) == '\t') && (*(short *)(param_1 + 0x81a) == 0)) {
    *(undefined4 *)(param_1 + 0xf2c) = 0x1a3;
    *(undefined4 *)(param_1 + 0xf30) = 0x192;
  }
  else {
    *(undefined4 *)(param_1 + 0xf2c) = 0x1f7;
    *(undefined4 *)(param_1 + 0xf30) = 0x1e6;
  }
  *(uint *)(param_1 + 0xf64) = (uint)DAT_803e6bc6;
  *(undefined4 *)(param_1 + 0xf60) = 2;
  if (DAT_803e6bc7 == '\0') {
    *(undefined *)(param_1 + 0x10a0) = 0;
  }
  else {
    *(undefined *)(param_1 + 0x10a0) = 1;
  }
  dVar5 = _4188;
  local_28 = (double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x10d8) ^ 0x80000000);
  *(float *)(param_1 + 0x10d0) = (float)(local_28 - _4188) - *(float *)(param_1 + 0x4b8);
  local_30 = (double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x10dc) ^ 0x80000000);
  *(float *)(param_1 + 0x10d4) = (float)(local_30 - dVar5) - *(float *)(param_1 + 0x4bc);
  *(undefined2 *)(param_1 + 0x852) = 0;
  *(undefined2 *)(param_1 + 0x65a) = 0;
  *(undefined2 *)(param_1 + 0x4d2) = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x8020ea9c) */
/* WARNING: Removing unreachable block (ram,0x8020eaa4) */
/* __stdcall dMsg_ScreenDataValueInitTact(sub_msg_class *) */

void dMsg_ScreenDataValueInitTact(int param_1)

{
  uint uVar1;
  int iVar2;
  float fVar3;
  undefined4 uVar4;
  undefined8 in_f30;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  double local_48;
  double local_40;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar6 = (double)*(float *)(*(int *)(param_1 + 0x544) + 0xe0);
  dVar5 = (double)*(float *)(*(int *)(param_1 + 0x57c) + 0xe0);
  uVar1 = (uint)*(float *)(param_1 + 0x548);
  iVar2 = (int)*(float *)(param_1 + 0x54c);
  *(uint *)(param_1 + 0x10f8) = uVar1;
  *(int *)(param_1 + 0x10fc) = iVar2;
  (**(code **)(**(int **)(param_1 + 0x544) + 0x10))
            ((double)(float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - _4188),
             (double)(float)((double)CONCAT44(0x43300000,
                                              (iVar2 - DAT_803e6ba6) - (int)textOffsetY ^ 0x80000000
                                             ) - _4188));
  (**(code **)(**(int **)(param_1 + 0x57c) + 0x10))
            ((double)(float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - _4188),
             (double)(float)((double)CONCAT44(0x43300000,
                                              (iVar2 - DAT_803e6ba4) - (int)textOffsetY ^ 0x80000000
                                             ) - _4188));
  (**(code **)(**(int **)(param_1 + 0x5b4) + 0x10))
            ((double)(float)((double)CONCAT44(0x43300000,uVar1 + 2 ^ 0x80000000) - _4188),
             (double)(float)((double)CONCAT44(0x43300000,
                                              ((iVar2 - DAT_803e6ba6) - (int)textOffsetY) + 2U ^
                                              0x80000000) - _4188));
  (**(code **)(**(int **)(param_1 + 0x5ec) + 0x10))
            ((double)(float)((double)CONCAT44(0x43300000,uVar1 + 2 ^ 0x80000000) - _4188),
             (double)(float)((double)CONCAT44(0x43300000,
                                              ((iVar2 - DAT_803e6ba4) - (int)textOffsetY) + 2U ^
                                              0x80000000) - _4188));
  *(int *)(param_1 + 0x10d8) = (int)*(float *)(param_1 + 0x4b8);
  *(int *)(param_1 + 0x10dc) = (int)*(float *)(param_1 + 0x4bc);
  *(undefined4 *)(param_1 + 0x1104) = 0;
  *(undefined *)(param_1 + 0x10c0) = *(undefined *)(param_1 + 0x10bc);
  *(undefined *)(param_1 + 0x10c1) = *(undefined *)(param_1 + 0x10bd);
  *(undefined *)(param_1 + 0x10c2) = *(undefined *)(param_1 + 0x10be);
  *(undefined *)(param_1 + 0x10c3) = *(undefined *)(param_1 + 0x10bf);
  *(undefined *)(param_1 + 0x10c8) = *(undefined *)(param_1 + 0x10c4);
  *(undefined *)(param_1 + 0x10c9) = *(undefined *)(param_1 + 0x10c5);
  *(undefined *)(param_1 + 0x10ca) = *(undefined *)(param_1 + 0x10c6);
  *(undefined *)(param_1 + 0x10cb) = *(undefined *)(param_1 + 0x10c7);
  *(undefined4 *)(param_1 + 0x10e0) = *(undefined4 *)(param_1 + 0x4b8);
  *(undefined4 *)(param_1 + 0x10e4) = *(undefined4 *)(param_1 + 0x4bc);
  *(undefined4 *)(param_1 + 0x4b8) = *(undefined4 *)(param_1 + 0x10e0);
  *(undefined4 *)(param_1 + 0x4bc) = *(undefined4 *)(param_1 + 0x10e4);
  fVar3 = _5611;
  *(float *)(param_1 + 0x4c8) = _5611;
  *(float *)(param_1 + 0x4cc) = fVar3 * (*(float *)(param_1 + 0x4c4) / *(float *)(param_1 + 0x4c0));
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_1 + 0x49c));
  fopMsgM_msgDataProc_c::dataInit((fopMsgM_msgDataProc_c *)(param_1 + 0xe04));
  *(int *)(param_1 + 0xe14) = param_1 + 0xe0;
  *(undefined4 *)(param_1 + 0xe40) = *(undefined4 *)(param_1 + 0x111c);
  *(undefined4 *)(param_1 + 0xe64) = *(undefined4 *)(param_1 + 0x1120);
  *(undefined4 *)(param_1 + 0xe44) = *(undefined4 *)(param_1 + 0x1120);
  *(undefined4 *)(param_1 + 0xe68) = *(undefined4 *)(param_1 + 0x1124);
  *(undefined4 *)(param_1 + 0xe48) = *(undefined4 *)(param_1 + 0x1124);
  *(undefined4 *)(param_1 + 0xe6c) = *(undefined4 *)(param_1 + 0x1128);
  *(undefined4 *)(param_1 + 0xe4c) = *(undefined4 *)(param_1 + 0x1128);
  *(undefined4 *)(param_1 + 0xe70) = *(undefined4 *)(param_1 + 0x112c);
  *(undefined4 *)(param_1 + 0xe50) = *(undefined4 *)(param_1 + 0x112c);
  *(undefined4 *)(param_1 + 0xe54) = *(undefined4 *)(param_1 + 0x1130);
  *(undefined4 *)(param_1 + 0xe58) = *(undefined4 *)(param_1 + 0x1134);
  *(undefined4 *)(param_1 + 0xe5c) = *(undefined4 *)(param_1 + 0x1138);
  *(undefined4 *)(param_1 + 0xe60) = *(undefined4 *)(param_1 + 0x113c);
  *(undefined4 *)(param_1 + 0xe08) = textFont;
  *(undefined4 *)(param_1 + 0xe0c) = rubyFont;
  *(int *)(param_1 + 0xf20) = (int)dVar6;
  *(int *)(param_1 + 0xf28) = (int)dVar5;
  *(int *)(param_1 + 0xe10) = param_1 + 0x100;
  *(undefined4 *)(param_1 + 0xf48) = *(undefined4 *)(param_1 + 0x110c);
  *(undefined4 *)(param_1 + 0xf50) = *(undefined4 *)(param_1 + 0x1110);
  if ((*(char *)(param_1 + 0x10c) == '\t') && (*(short *)(param_1 + 0x81a) == 0)) {
    *(undefined4 *)(param_1 + 0xf2c) = 0x1a3;
    *(undefined4 *)(param_1 + 0xf30) = 0x192;
  }
  else {
    *(undefined4 *)(param_1 + 0xf2c) = 0x1f7;
    *(undefined4 *)(param_1 + 0xf30) = 0x1e6;
  }
  *(uint *)(param_1 + 0xf64) = (uint)DAT_803e6bc6;
  *(undefined4 *)(param_1 + 0xf60) = 2;
  if (DAT_803e6bc7 == '\0') {
    *(undefined *)(param_1 + 0x10a0) = 0;
  }
  else {
    *(undefined *)(param_1 + 0x10a0) = 1;
  }
  dVar5 = _4188;
  local_40 = (double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x10d8) ^ 0x80000000);
  *(float *)(param_1 + 0x10d0) = (float)(local_40 - _4188) - *(float *)(param_1 + 0x4b8);
  local_48 = (double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x10dc) ^ 0x80000000);
  *(float *)(param_1 + 0x10d4) = (float)(local_48 - dVar5) - *(float *)(param_1 + 0x4bc);
  *(undefined2 *)(param_1 + 0x852) = 0;
  *(undefined2 *)(param_1 + 0x65a) = 0;
  *(undefined2 *)(param_1 + 0x692) = 0;
  *(undefined2 *)(param_1 + 0x4d2) = 0;
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8020ec04) */
/* WARNING: Removing unreachable block (ram,0x8020ec0c) */
/* __stdcall dMsg_ScreenDataValueInitDemo(sub_msg_class *) */

void dMsg_ScreenDataValueInitDemo(int param_1)

{
  undefined4 uVar1;
  undefined8 in_f30;
  double dVar2;
  undefined8 in_f31;
  double dVar3;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar3 = (double)*(float *)(*(int *)(param_1 + 0x544) + 0xe0);
  dVar2 = (double)*(float *)(*(int *)(param_1 + 0x57c) + 0xe0);
  *(int *)(param_1 + 0x1104) = (int)(*(float *)(*(int *)(param_1 + 0x544) + 0xe4) * _4289);
  fopMsgM_msgDataProc_c::dataInit((fopMsgM_msgDataProc_c *)(param_1 + 0xe04));
  *(undefined4 *)(param_1 + 0xe40) = *(undefined4 *)(param_1 + 0x111c);
  *(undefined4 *)(param_1 + 0xe64) = *(undefined4 *)(param_1 + 0x1120);
  *(undefined4 *)(param_1 + 0xe44) = *(undefined4 *)(param_1 + 0x1120);
  *(undefined4 *)(param_1 + 0xe68) = *(undefined4 *)(param_1 + 0x1124);
  *(undefined4 *)(param_1 + 0xe48) = *(undefined4 *)(param_1 + 0x1124);
  *(undefined4 *)(param_1 + 0xe6c) = *(undefined4 *)(param_1 + 0x1128);
  *(undefined4 *)(param_1 + 0xe4c) = *(undefined4 *)(param_1 + 0x1128);
  *(undefined4 *)(param_1 + 0xe70) = *(undefined4 *)(param_1 + 0x112c);
  *(undefined4 *)(param_1 + 0xe50) = *(undefined4 *)(param_1 + 0x112c);
  *(undefined4 *)(param_1 + 0xe54) = *(undefined4 *)(param_1 + 0x1130);
  *(undefined4 *)(param_1 + 0xe58) = *(undefined4 *)(param_1 + 0x1134);
  *(undefined4 *)(param_1 + 0xe5c) = *(undefined4 *)(param_1 + 0x1138);
  *(undefined4 *)(param_1 + 0xe60) = *(undefined4 *)(param_1 + 0x113c);
  *(undefined4 *)(param_1 + 0xe08) = textFont;
  *(undefined4 *)(param_1 + 0xe0c) = rubyFont;
  *(int *)(param_1 + 0xf20) = (int)dVar3;
  *(int *)(param_1 + 0xf28) = (int)dVar2;
  *(int *)(param_1 + 0xe10) = param_1 + 0x100;
  *(undefined4 *)(param_1 + 0xf48) = *(undefined4 *)(param_1 + 0x110c);
  *(undefined4 *)(param_1 + 0xf50) = *(undefined4 *)(param_1 + 0x1110);
  *(undefined4 *)(param_1 + 0xf2c) = 0x1f7;
  *(undefined4 *)(param_1 + 0xf30) = 0x1e6;
  *(uint *)(param_1 + 0xf64) = (uint)DAT_803e6bc6;
  *(undefined4 *)(param_1 + 0xf60) = 2;
  if (DAT_803e6bc7 == '\0') {
    *(undefined *)(param_1 + 0x10a0) = 0;
  }
  else {
    *(undefined *)(param_1 + 0x10a0) = 1;
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  return;
}


/* __stdcall dMsg_value_init(sub_msg_class *) */

void dMsg_value_init(int param_1)

{
  char acStack104 [28];
  char acStack76 [28];
  char acStack48 [44];
  
  MSL_C.PPCEABI.bare.H::sprintf(acStack48,"\x1bCC[%08x]\x1bGM[0]",*(undefined4 *)(param_1 + 0x1164))
  ;
  MSL_C.PPCEABI.bare.H::sprintf(acStack76,"\x1bCC[FFFFFFFF]\x1bGM[0]");
  MSL_C.PPCEABI.bare.H::sprintf(acStack104,"\x1bCC[000000FF]\x1bGM[0]");
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(param_1 + 0x1120),acStack48);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(param_1 + 0x1124),acStack76);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(param_1 + 0x1128),acStack104);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(param_1 + 0x112c),acStack104);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(param_1 + 0x1130),acStack48);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(param_1 + 0x1134),acStack76);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(param_1 + 0x1138),acStack104);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(param_1 + 0x113c),acStack104);
  *(undefined4 *)(param_1 + 0x1060) = *(undefined4 *)(param_1 + 0x1164);
  dMsg_outFontHide(param_1);
  *(undefined4 *)(param_1 + 0x1108) = 0;
  return;
}


/* __stdcall dMsg_setString(sub_msg_class *) */

void dMsg_setString(int param_1,undefined4 param_2,___ param_3)

{
  char cVar1;
  
  J2DTextBox::setString(*(J2DTextBox **)(param_1 + 0x544),*(char **)(param_1 + 0x1120),param_3);
  J2DTextBox::setString(*(J2DTextBox **)(param_1 + 0x57c),*(char **)(param_1 + 0x1124),param_3);
  J2DTextBox::setString(*(J2DTextBox **)(param_1 + 0x5b4),*(char **)(param_1 + 0x1128),param_3);
  J2DTextBox::setString(*(J2DTextBox **)(param_1 + 0x5ec),*(char **)(param_1 + 0x112c),param_3);
  cVar1 = *(char *)(param_1 + 0x10c);
  if ((((cVar1 != '\t') && (cVar1 != '\x0e')) && (cVar1 != '\x01')) && (cVar1 != '\x05')) {
    J2DTextBox::setString(*(J2DTextBox **)(param_1 + 0x11c),*(char **)(param_1 + 0x1130),param_3);
    J2DTextBox::setString(*(J2DTextBox **)(param_1 + 0x154),*(char **)(param_1 + 0x1134),param_3);
    J2DTextBox::setString(*(J2DTextBox **)(param_1 + 0x18c),*(char **)(param_1 + 0x1138),param_3);
    J2DTextBox::setString(*(J2DTextBox **)(param_1 + 0x1c4),*(char **)(param_1 + 0x113c),param_3);
  }
  return;
}


/* __stdcall dMsg_yose_select(sub_msg_class *) */

void dMsg_yose_select(int param_1)

{
  fopMsgM_msgDataProc_c::stringLength((fopMsgM_msgDataProc_c *)(param_1 + 0xe04));
  *(undefined4 *)(param_1 + 0x1108) = *(undefined4 *)(param_1 + 0xf34);
  *(undefined4 *)(param_1 + 0xf34) = 0;
  fopMsgM_msgDataProc_c::stringShift((fopMsgM_msgDataProc_c *)(param_1 + 0xe04));
  fopMsgM_msgDataProc_c::iconIdxRefresh((fopMsgM_msgDataProc_c *)(param_1 + 0xe04));
  dMsg_textPosition(param_1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8020f05c) */
/* WARNING: Removing unreachable block (ram,0x8020f054) */
/* WARNING: Removing unreachable block (ram,0x8020f064) */
/* __stdcall dMsg_frame_openTalk(sub_msg_class *) */

void dMsg_frame_openTalk(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  undefined4 uVar6;
  double dVar7;
  undefined8 in_f29;
  double dVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  double local_48;
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
  *(int *)(param_1 + 0x1100) = *(int *)(param_1 + 0x1100) + 1;
  dVar7 = _4188;
  uVar5 = *(uint *)(param_1 + 0x1100);
  if ((int)uVar5 < 0xd) {
    if ((int)uVar5 < 10) {
      dVar10 = (double)(float)((double)_5611 *
                              (double)(float)((double)*(float *)(param_1 + 0x4c4) /
                                             (double)*(float *)(param_1 + 0x4c0)));
      dVar9 = (double)(float)((double)*(float *)(param_1 + 0x4c0) - (double)_5611);
      dVar8 = (double)(float)((double)*(float *)(param_1 + 0x4c4) - dVar10);
      dVar7 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,uVar5,0);
      *(float *)(param_1 + 0x4c8) = _5611 + (float)(dVar9 * dVar7);
      *(float *)(param_1 + 0x4cc) = (float)(dVar10 + (double)(float)(dVar8 * dVar7));
      *(float *)(param_1 + 0x4b8) =
           *(float *)(param_1 + 0x10e0) + (float)((double)*(float *)(param_1 + 0x10d0) * dVar7);
      *(float *)(param_1 + 0x4bc) =
           *(float *)(param_1 + 0x10e4) + (float)((double)*(float *)(param_1 + 0x10d4) * dVar7);
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_1 + 0x49c));
    }
    else {
      fVar1 = *(float *)(param_1 + 0x4c0);
      fVar3 = _4287 / (fVar1 - _5611);
      fVar4 = _5864 * (*(float *)(param_1 + 0x4c4) / fVar1);
      fVar2 = JKernel::JMath::jmaSinTable
              [(int)((int)(((float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - _4188) - _5865
                           ) * _5866) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f)];
      *(float *)(param_1 + 0x4c8) = fVar1 + (_5864 - fVar1) * fVar2;
      *(float *)(param_1 + 0x4cc) =
           *(float *)(param_1 + 0x4c4) + (fVar4 - *(float *)(param_1 + 0x4c4)) * fVar2;
      *(float *)(param_1 + 0x4b8) =
           *(float *)(param_1 + 0x10e0) + *(float *)(param_1 + 0x10d0) +
           (fVar3 * *(float *)(param_1 + 0x10d0) - *(float *)(param_1 + 0x10d0)) * fVar2;
      *(float *)(param_1 + 0x4bc) =
           *(float *)(param_1 + 0x10e4) + *(float *)(param_1 + 0x10d4) +
           (fVar3 * *(float *)(param_1 + 0x10d4) - *(float *)(param_1 + 0x10d4)) * fVar2;
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_1 + 0x49c));
    }
    dVar7 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0xd,*(undefined4 *)(param_1 + 0x1100),0);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x49c),(float)dVar7);
  }
  else {
    local_48 = (double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x10d8) ^ 0x80000000);
    *(float *)(param_1 + 0x4b8) = (float)(local_48 - _4188);
    *(float *)(param_1 + 0x4bc) =
         (float)((double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x10dc) ^ 0x80000000) - dVar7);
    f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(param_1 + 0x49c),_5863);
    f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x49c);
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  __psq_l0(auStack40,uVar6);
  __psq_l1(auStack40,uVar6);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8020f1a4) */
/* __stdcall dMsg_frame_openItem(sub_msg_class *) */

void dMsg_frame_openItem(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  *(int *)(param_1 + 0x1100) = *(int *)(param_1 + 0x1100) + 1;
  dVar3 = _4188;
  iVar1 = *(int *)(param_1 + 0x1100);
  if (iVar1 < 8) {
    if (iVar1 < 6) {
      dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,iVar1,0);
      *(float *)(param_1 + 0x4b8) =
           *(float *)(param_1 + 0x10e0) + (float)((double)*(float *)(param_1 + 0x10d0) * dVar3);
      *(float *)(param_1 + 0x4bc) =
           *(float *)(param_1 + 0x10e4) + (float)((double)*(float *)(param_1 + 0x10d4) * dVar3);
      f_op_msg_mng::fopMsgM_paneScaleXY
                ((fopMsgM_pane_class *)(param_1 + 0x49c),_5884 + (float)((double)_4289 * dVar3));
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x49c),(float)dVar3);
    }
    else {
      dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(3,iVar1 + -5,0);
      f_op_msg_mng::fopMsgM_paneScaleXY
                ((fopMsgM_pane_class *)(param_1 + 0x49c),_5885 + (float)((double)_5886 * dVar3));
      f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x49c);
    }
  }
  else {
    *(float *)(param_1 + 0x4b8) =
         (float)((double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x10d8) ^ 0x80000000) - _4188);
    *(float *)(param_1 + 0x4bc) =
         (float)((double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x10dc) ^ 0x80000000) - dVar3);
    f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(param_1 + 0x49c),_5863);
    f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x49c);
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


/* __stdcall dMsg_frame_close(sub_msg_class *) */

void dMsg_frame_close(int param_1)

{
  float fVar1;
  float fVar2;
  double dVar3;
  
  dMsg_messagePaneHide();
  dMsg_outFontHide(param_1);
  *(int *)(param_1 + 0x1100) = *(int *)(param_1 + 0x1100) + 1;
  if (*(int *)(param_1 + 0x1100) == 10) {
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x49c));
    JKRFileLoader::removeResource(*(void **)(param_1 + 0x118),(JKRFileLoader *)0x0);
    *(undefined2 *)(param_1 + 0xf8) = 0x12;
    *(undefined *)(*(int *)(param_1 + 0x49c) + 0xaa) = 0;
  }
  else {
    dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,*(int *)(param_1 + 0x1100),0);
    fVar1 = *(float *)(param_1 + 0x4c0);
    fVar2 = _5907 * (*(float *)(param_1 + 0x4c4) / fVar1);
    *(float *)(param_1 + 0x4c8) = fVar1 + (float)(dVar3 * (double)(_5907 - fVar1));
    *(float *)(param_1 + 0x4cc) =
         *(float *)(param_1 + 0x4c4) +
         (float)(dVar3 * (double)(fVar2 - *(float *)(param_1 + 0x4c4)));
    dVar3 = _4188;
    *(float *)(param_1 + 0x4b8) =
         (float)((double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x10d8) ^ 0x80000000) - _4188);
    *(float *)(param_1 + 0x4bc) =
         (float)((double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x10dc) ^ 0x80000000) - dVar3);
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_1 + 0x49c));
    dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - *(int *)(param_1 + 0x1100),0);
    if (dVar3 < (double)((float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x4d1)) -
                                _5912) / _5908)) {
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x49c),(float)dVar3);
    }
    if (*(int *)(param_1 + 0x1100) == 1) {
      dMsg_setCloseSound(param_1,0);
    }
  }
  return;
}


/* __stdcall dMsg_textPosition(sub_msg_class *) */

void dMsg_textPosition(int param_1)

{
  byte bVar1;
  float fVar2;
  double dVar3;
  uint uVar4;
  int iVar5;
  
  fVar2 = _4185;
  bVar1 = *(byte *)(param_1 + 0x10c);
  if (bVar1 == 0xe) {
    uVar4 = 0;
  }
  else {
    if ((bVar1 < 0xe) && (bVar1 == 5)) {
      uVar4 = *(int *)(param_1 + 0x1104) * (2 - *(int *)(param_1 + 0x1108));
    }
    else {
      uVar4 = *(int *)(param_1 + 0x1104) * (3 - *(int *)(param_1 + 0x1108));
    }
  }
  iVar5 = *(int *)(param_1 + 0x544);
  *(float *)(iVar5 + 0xd8) = _4185;
  dVar3 = _4188;
  uVar4 = uVar4 ^ 0x80000000;
  *(float *)(iVar5 + 0xdc) = (float)((double)CONCAT44(0x43300000,uVar4) - _4188);
  iVar5 = *(int *)(param_1 + 0x57c);
  *(float *)(iVar5 + 0xd8) = fVar2;
  *(float *)(iVar5 + 0xdc) = (float)((double)CONCAT44(0x43300000,uVar4) - dVar3);
  iVar5 = *(int *)(param_1 + 0x5b4);
  *(float *)(iVar5 + 0xd8) = fVar2;
  *(float *)(iVar5 + 0xdc) = (float)((double)CONCAT44(0x43300000,uVar4) - dVar3);
  iVar5 = *(int *)(param_1 + 0x5ec);
  *(float *)(iVar5 + 0xd8) = fVar2;
  *(float *)(iVar5 + 0xdc) = (float)((double)CONCAT44(0x43300000,uVar4) - dVar3);
  return;
}


/* __stdcall dMsg_rubySet(sub_msg_class *) */

void dMsg_rubySet(int param_1)

{
  char cVar1;
  
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ == '\0') {
    if (*(char *)(*(int *)(param_1 + 0x57c) + 0xaa) != '\0') {
      *(undefined *)(*(int *)(param_1 + 0x57c) + 0xaa) = 1;
    }
    if (*(char *)(*(int *)(param_1 + 0x5ec) + 0xaa) != '\0') {
      *(undefined *)(*(int *)(param_1 + 0x5ec) + 0xaa) = 1;
    }
    cVar1 = *(char *)(param_1 + 0x10c);
    if (cVar1 == '\t') {
      return;
    }
    if (cVar1 == '\x0e') {
      return;
    }
    if (cVar1 == '\x01') {
      return;
    }
    if (cVar1 == '\x05') {
      return;
    }
    if (*(char *)(*(int *)(param_1 + 0x154) + 0xaa) != '\0') {
      *(undefined *)(*(int *)(param_1 + 0x154) + 0xaa) = 1;
    }
    if (*(char *)(*(int *)(param_1 + 0x1c4) + 0xaa) == '\0') {
      return;
    }
    *(undefined *)(*(int *)(param_1 + 0x1c4) + 0xaa) = 1;
    return;
  }
  *(undefined *)(*(int *)(param_1 + 0x57c) + 0xaa) = 0;
  *(undefined *)(*(int *)(param_1 + 0x5ec) + 0xaa) = 0;
  cVar1 = *(char *)(param_1 + 0x10c);
  if (cVar1 == '\t') {
    return;
  }
  if (cVar1 == '\x0e') {
    return;
  }
  if (cVar1 == '\x01') {
    return;
  }
  if (cVar1 == '\x05') {
    return;
  }
  *(undefined *)(*(int *)(param_1 + 0x154) + 0xaa) = 0;
  *(undefined *)(*(int *)(param_1 + 0x1c4) + 0xaa) = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dMsg_mesgOutPos(sub_msg_class *) */

void dMsg_mesgOutPos(int param_1)

{
  uint uVar1;
  char cVar3;
  int iVar2;
  cXyz local_68;
  double local_58;
  undefined4 local_50;
  uint uStack76;
  undefined4 local_48;
  uint uStack68;
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
  
  cVar3 = *(char *)(param_1 + 0x10e);
  if (cVar3 == '\0') {
    m_Do_lib::mDoLib_project
              (&((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mEyePos
               ,&local_68);
    talkPosX = _4289 * (local_68.x + *(float *)(param_1 + 0x10e0));
    talkPosY = _4289 * (local_68.y + *(float *)(param_1 + 0x10e4));
    local_58 = (double)CONCAT44(0x43300000,(int)DAT_803e6bb2 ^ 0x80000000);
    if ((float)(local_58 - _4188) <= talkPosY) {
      cVar3 = '\x01';
    }
    else {
      cVar3 = '\x03';
    }
  }
  dMsg_msg_pane_parts_set(param_1 + 0x49c,cVar3);
  if ((*(char *)(param_1 + 0x10c) != '\x05') && (*(char *)(param_1 + 0x10c) != '\x0e')) {
    dMsg_arw_pane_parts_set(param_1 + 0x4d4,param_1 + 0x49c);
    dMsg_arw_pane_parts_set(param_1 + 0x50c,param_1 + 0x49c);
    *(int *)(param_1 + 0x1114) = (int)(*(float *)(param_1 + 0x4e4) + *(float *)(param_1 + 0x4fc));
  }
  uVar1 = (uint)*(float *)(param_1 + 0x548);
  if (cVar3 == '\x01') {
    iVar2 = (int)(_4287 - (*(float *)(param_1 + 0x54c) + *(float *)(param_1 + 0x56c))) + -0x13;
  }
  else {
    if (cVar3 == '\x02') {
      iVar2 = (int)(_4288 - *(float *)(param_1 + 0x56c) * _4289);
    }
    else {
      iVar2 = (int)*(float *)(param_1 + 0x54c) + 0x20;
    }
  }
  *(uint *)(param_1 + 0x10f8) = uVar1;
  *(int *)(param_1 + 0x10fc) = iVar2;
  local_58 = (double)CONCAT44(0x43300000,uVar1 ^ 0x80000000);
  uStack76 = (iVar2 - DAT_803e6ba6) - (int)textOffsetY ^ 0x80000000;
  local_50 = 0x43300000;
  (**(code **)(**(int **)(param_1 + 0x544) + 0x10))
            ((double)(float)(local_58 - _4188),
             (double)(float)((double)CONCAT44(0x43300000,uStack76) - _4188));
  uStack68 = uVar1 ^ 0x80000000;
  local_48 = 0x43300000;
  uStack60 = (iVar2 - DAT_803e6ba4) - (int)textOffsetY ^ 0x80000000;
  local_40 = 0x43300000;
  (**(code **)(**(int **)(param_1 + 0x57c) + 0x10))
            ((double)(float)((double)CONCAT44(0x43300000,uStack68) - _4188),
             (double)(float)((double)CONCAT44(0x43300000,uStack60) - _4188));
  uStack52 = uVar1 + 2 ^ 0x80000000;
  local_38 = 0x43300000;
  uStack44 = ((iVar2 - DAT_803e6ba6) - (int)textOffsetY) + 2U ^ 0x80000000;
  local_30 = 0x43300000;
  (**(code **)(**(int **)(param_1 + 0x5b4) + 0x10))
            ((double)(float)((double)CONCAT44(0x43300000,uStack52) - _4188),
             (double)(float)((double)CONCAT44(0x43300000,uStack44) - _4188));
  uStack36 = uVar1 + 2 ^ 0x80000000;
  local_28 = 0x43300000;
  uStack28 = ((iVar2 - DAT_803e6ba4) - (int)textOffsetY) + 2U ^ 0x80000000;
  local_20 = 0x43300000;
  (**(code **)(**(int **)(param_1 + 0x5ec) + 0x10))
            ((double)(float)((double)CONCAT44(0x43300000,uStack36) - _4188),
             (double)(float)((double)CONCAT44(0x43300000,uStack28) - _4188));
  return;
}


/* __stdcall dMsg_arrowInit(sub_msg_class *) */

void dMsg_arrowInit(int param_1)

{
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x4d4));
  *(undefined4 *)(param_1 + 0x4f0) = *(undefined4 *)(param_1 + 0x4e8);
  *(undefined4 *)(param_1 + 0x4f4) = *(undefined4 *)(param_1 + 0x4ec);
  *(undefined4 *)(param_1 + 0x500) = *(undefined4 *)(param_1 + 0x4f8);
  *(undefined4 *)(param_1 + 0x504) = *(undefined4 *)(param_1 + 0x4fc);
  *(undefined4 *)(param_1 + 0x1100) = 0;
  return;
}


/* __stdcall dMsg_arrowMove(sub_msg_class *) */

void dMsg_arrowMove(int param_1)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  double dVar13;
  
  uVar7 = DAT_80361dc0;
  uVar6 = DAT_80361dbc;
  uVar5 = DAT_80361db8;
  uVar4 = DAT_80361db4;
  uVar3 = DAT_80361db0;
  uVar9 = DAT_80361db0 + DAT_80361db4;
  uVar10 = uVar9 + DAT_80361db8;
  uVar11 = uVar10 + DAT_80361dbc;
  iVar12 = uVar11 + DAT_80361dc0;
  *(int *)(param_1 + 0x1100) = *(int *)(param_1 + 0x1100) + 1;
  fVar1 = _5863;
  if (*(byte *)(param_1 + 0x509) < *(byte *)(param_1 + 0x508)) {
    dVar13 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,*(undefined4 *)(param_1 + 0x1100),0);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x4d4),(float)dVar13);
    if (*(int *)(param_1 + 0x1100) == 10) {
      *(undefined4 *)(param_1 + 0x1100) = 0;
    }
  }
  else {
    uVar8 = *(uint *)(param_1 + 0x1100);
    fVar2 = fVar1;
    if ((int)uVar3 < (int)uVar8) {
      if ((int)uVar9 < (int)uVar8) {
        if ((int)uVar10 < (int)uVar8) {
          if ((int)uVar11 < (int)uVar8) {
            if (iVar12 < (int)uVar8) {
              *(undefined4 *)(param_1 + 0x1100) = 0;
            }
            else {
              fVar1 = (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - _4188) -
                      (float)((double)CONCAT44(0x43300000,uVar11 ^ 0x80000000) - _4188);
              fVar2 = (fVar1 * fVar1) /
                      ((float)((double)CONCAT44(0x43300000,uVar7 ^ 0x80000000) - _4188) *
                      (float)((double)CONCAT44(0x43300000,uVar7 ^ 0x80000000) - _4188));
              fVar1 = DAT_80361dd0 + fVar2 * (DAT_80361dd4 - DAT_80361dd0);
              fVar2 = DAT_80361de4 + fVar2 * (DAT_80361de8 - DAT_80361de4);
            }
          }
          else {
            fVar1 = (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - _4188) -
                    (float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) - _4188);
            fVar2 = (fVar1 * fVar1) /
                    ((float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) - _4188) *
                    (float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) - _4188));
            fVar1 = DAT_80361dcc + fVar2 * (DAT_80361dd0 - DAT_80361dcc);
            fVar2 = DAT_80361de0 + fVar2 * (DAT_80361de4 - DAT_80361de0);
          }
        }
        else {
          fVar1 = (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - _4188) -
                  (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - _4188);
          fVar2 = (fVar1 * fVar1) /
                  ((float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - _4188) *
                  (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - _4188));
          fVar1 = DAT_80361dc8 + fVar2 * (DAT_80361dcc - DAT_80361dc8);
          fVar2 = DAT_80361ddc + fVar2 * (DAT_80361de0 - DAT_80361ddc);
        }
      }
      else {
        fVar1 = (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - _4188) -
                (float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - _4188);
        fVar2 = (fVar1 * fVar1) /
                ((float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - _4188) *
                (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - _4188));
        fVar1 = scaleX_6040 + fVar2 * (DAT_80361dc8 - scaleX_6040);
        fVar2 = scaleY_6041 + fVar2 * (DAT_80361ddc - scaleY_6041);
      }
    }
    *(float *)(param_1 + 0x500) = *(float *)(param_1 + 0x4f8) * fVar1;
    *(float *)(param_1 + 0x504) = *(float *)(param_1 + 0x4fc) * fVar2;
    *(float *)(param_1 + 0x4f4) =
         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6baa ^ 0x80000000) - _4188) +
         ((float)((double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x1114) ^ 0x80000000) - _4188) -
         *(float *)(param_1 + 0x504) * _4289);
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_1 + 0x4d4));
  }
  return;
}


/* __stdcall dMsg_dotMove(sub_msg_class *) */

void dMsg_dotMove(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  double dVar4;
  double dVar5;
  undefined local_b8;
  undefined uStack183;
  undefined uStack182;
  undefined uStack181;
  undefined local_b4;
  undefined uStack179;
  undefined uStack178;
  undefined uStack177;
  double local_b0;
  double local_a0;
  double local_98;
  double local_88;
  double local_80;
  double local_70;
  double local_68;
  double local_58;
  double local_50;
  double local_40;
  double local_38;
  double local_28;
  double local_20;
  double local_10;
  
  *(int *)(param_1 + 0x1100) = *(int *)(param_1 + 0x1100) + 1;
  if (*(byte *)(param_1 + 0x541) < *(byte *)(param_1 + 0x540)) {
    dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,*(undefined4 *)(param_1 + 0x1100),0);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x50c),(float)dVar4);
    if (*(int *)(param_1 + 0x1100) == 10) {
      *(undefined4 *)(param_1 + 0x1100) = 0;
    }
  }
  else {
    iVar3 = *(int *)(param_1 + 0x1100);
    if (iVar3 < 0x3c) {
      if (iVar3 < 0x1f) {
        dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x1e,iVar3,0);
        fVar1 = _6142;
        dVar4 = _5912;
        local_10 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x10bc));
        *(char *)(param_1 + 0x10c0) =
             (char)(int)((float)(local_10 - _5912) +
                        (float)((double)(_6142 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x10bc)) -
                                                        _5912)) * dVar5));
        local_28 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x10bd));
        *(char *)(param_1 + 0x10c1) =
             (char)(int)((float)(local_28 - dVar4) +
                        (float)((double)(fVar1 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x10bd)) -
                                                        dVar4)) * dVar5));
        local_40 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x10be));
        *(char *)(param_1 + 0x10c2) =
             (char)(int)((float)(local_40 - dVar4) +
                        (float)((double)(fVar1 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x10be)) -
                                                        dVar4)) * dVar5));
        fVar1 = _5908;
        local_58 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x10c4));
        *(char *)(param_1 + 0x10c8) =
             (char)(int)((float)(local_58 - dVar4) +
                        (float)((double)(_5908 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x10c4)) -
                                                        dVar4)) * dVar5));
        local_70 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x10c5));
        *(char *)(param_1 + 0x10c9) =
             (char)(int)((float)(local_70 - dVar4) +
                        (float)((double)(fVar1 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x10c5)) -
                                                        dVar4)) * dVar5));
        local_88 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x10c6));
        *(char *)(param_1 + 0x10ca) =
             (char)(int)((float)(local_88 - dVar4) +
                        (float)((double)(_6143 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x10c6)) -
                                                        dVar4)) * dVar5));
        local_a0 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x540));
        *(char *)(param_1 + 0x541) =
             (char)(int)((float)(local_a0 - dVar4) +
                        (float)((double)(fVar1 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x540)) -
                                                        dVar4)) * dVar5));
      }
      else {
        dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x1e,0x3c - iVar3,0);
        fVar1 = _6142;
        dVar4 = _5912;
        local_b0 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x10bc));
        *(char *)(param_1 + 0x10c0) =
             (char)(int)((float)(local_b0 - _5912) +
                        (float)((double)(_6142 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x10bc)) -
                                                        _5912)) * dVar5));
        local_98 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x10bd));
        *(char *)(param_1 + 0x10c1) =
             (char)(int)((float)(local_98 - dVar4) +
                        (float)((double)(fVar1 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x10bd)) -
                                                        dVar4)) * dVar5));
        local_80 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x10be));
        *(char *)(param_1 + 0x10c2) =
             (char)(int)((float)(local_80 - dVar4) +
                        (float)((double)(fVar1 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x10be)) -
                                                        dVar4)) * dVar5));
        fVar1 = _5908;
        local_68 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x10c4));
        *(char *)(param_1 + 0x10c8) =
             (char)(int)((float)(local_68 - dVar4) +
                        (float)((double)(_5908 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x10c4)) -
                                                        dVar4)) * dVar5));
        local_50 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x10c5));
        *(char *)(param_1 + 0x10c9) =
             (char)(int)((float)(local_50 - dVar4) +
                        (float)((double)(fVar1 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x10c5)) -
                                                        dVar4)) * dVar5));
        local_38 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x10c6));
        *(char *)(param_1 + 0x10ca) =
             (char)(int)((float)(local_38 - dVar4) +
                        (float)((double)(_6143 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x10c6)) -
                                                        dVar4)) * dVar5));
        local_20 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x540));
        *(char *)(param_1 + 0x541) =
             (char)(int)((float)(local_20 - dVar4) +
                        (float)((double)(fVar1 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x540)) -
                                                        dVar4)) * dVar5));
      }
    }
    else {
      *(undefined *)(param_1 + 0x10c0) = *(undefined *)(param_1 + 0x10bc);
      *(undefined *)(param_1 + 0x10c1) = *(undefined *)(param_1 + 0x10bd);
      *(undefined *)(param_1 + 0x10c2) = *(undefined *)(param_1 + 0x10be);
      *(undefined *)(param_1 + 0x10c3) = *(undefined *)(param_1 + 0x10bf);
      *(undefined *)(param_1 + 0x10c8) = *(undefined *)(param_1 + 0x10c4);
      *(undefined *)(param_1 + 0x10c9) = *(undefined *)(param_1 + 0x10c5);
      *(undefined *)(param_1 + 0x10ca) = *(undefined *)(param_1 + 0x10c6);
      *(undefined *)(param_1 + 0x10cb) = *(undefined *)(param_1 + 0x10c7);
      f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x50c);
      *(undefined4 *)(param_1 + 0x1100) = 0;
    }
    uVar2 = *(undefined4 *)(param_1 + 0x10c0);
    iVar3 = *(int *)(param_1 + 0x50c);
    local_b4 = (undefined)((uint)uVar2 >> 0x18);
    *(undefined *)(iVar3 + 0x108) = local_b4;
    uStack179 = (undefined)((uint)uVar2 >> 0x10);
    *(undefined *)(iVar3 + 0x109) = uStack179;
    uStack178 = (undefined)((uint)uVar2 >> 8);
    *(undefined *)(iVar3 + 0x10a) = uStack178;
    uStack177 = (undefined)uVar2;
    *(undefined *)(iVar3 + 0x10b) = uStack177;
    uVar2 = *(undefined4 *)(param_1 + 0x10c8);
    iVar3 = *(int *)(param_1 + 0x50c);
    local_b8 = (undefined)((uint)uVar2 >> 0x18);
    *(undefined *)(iVar3 + 0x104) = local_b8;
    uStack183 = (undefined)((uint)uVar2 >> 0x10);
    *(undefined *)(iVar3 + 0x105) = uStack183;
    uStack182 = (undefined)((uint)uVar2 >> 8);
    *(undefined *)(iVar3 + 0x106) = uStack182;
    uStack181 = (undefined)uVar2;
    *(undefined *)(iVar3 + 0x107) = uStack181;
  }
  return;
}


/* __stdcall dMsg_ringMove(sub_msg_class *) */

void dMsg_ringMove(int param_1)

{
  int iVar1;
  double dVar2;
  
  *(short *)(param_1 + 0x852) = *(short *)(param_1 + 0x852) + 1;
  if (0x77 < *(short *)(param_1 + 0x852)) {
    *(undefined2 *)(param_1 + 0x852) = 0;
  }
  iVar1 = (int)*(short *)(param_1 + 0x852);
  if (iVar1 < 0x3c) {
    dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x3c,iVar1,0);
  }
  else {
    dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x3c,0x78 - iVar1,0);
  }
  f_op_msg_mng::fopMsgM_setNowAlpha
            ((fopMsgM_pane_class *)(param_1 + 0x81c),
             (float)((double)_6176 + (double)(float)((double)_6176 * dVar2)));
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802103ac) */
/* WARNING: Removing unreachable block (ram,0x802103b4) */
/* __stdcall dMsg_lightMove(sub_msg_class *) */

void dMsg_lightMove(int param_1)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 in_f30;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  *(short *)(param_1 + 0x65a) = *(short *)(param_1 + 0x65a) + 1;
  if (799 < *(short *)(param_1 + 0x65a)) {
    *(undefined2 *)(param_1 + 0x65a) = 0;
  }
  dVar6 = (double)(_6213 * ((float)((double)CONCAT44(0x43300000,
                                                     (int)*(short *)(param_1 + 0x65a) ^ 0x80000000)
                                   - _4188) / _6214));
  piVar2 = *(int **)(param_1 + 0x624);
  piVar2[0x27] = *(int *)(param_1 + 0x650);
  piVar2[0x28] = (int)_4185;
  *(undefined *)(piVar2 + 0x2a) = 0x7a;
  dVar7 = -dVar6;
  piVar2[0x29] = (int)(float)dVar7;
  (**(code **)(*piVar2 + 0x20))();
  fVar1 = _4185;
  piVar2 = *(int **)(param_1 + 0x65c);
  piVar2[0x27] = (int)_4185;
  piVar2[0x28] = (int)fVar1;
  *(undefined *)(piVar2 + 0x2a) = 0x7a;
  piVar2[0x29] = (int)(float)dVar7;
  (**(code **)(*piVar2 + 0x20))();
  iVar3 = *(int *)(param_1 + 0x6c4);
  piVar2 = *(int **)(param_1 + 0x694);
  piVar2[0x27] = *(int *)(param_1 + 0x6c0);
  piVar2[0x28] = iVar3;
  *(undefined *)(piVar2 + 0x2a) = 0x7a;
  piVar2[0x29] = (int)(float)dVar7;
  (**(code **)(*piVar2 + 0x20))();
  iVar3 = *(int *)(param_1 + 0x6fc);
  piVar2 = *(int **)(param_1 + 0x6cc);
  piVar2[0x27] = (int)_4185;
  piVar2[0x28] = iVar3;
  *(undefined *)(piVar2 + 0x2a) = 0x7a;
  piVar2[0x29] = (int)(float)dVar7;
  (**(code **)(*piVar2 + 0x20))();
  piVar2 = *(int **)(param_1 + 0x704);
  piVar2[0x27] = *(int *)(param_1 + 0x730);
  piVar2[0x28] = (int)_4185;
  *(undefined *)(piVar2 + 0x2a) = 0x7a;
  piVar2[0x29] = (int)(float)dVar6;
  (**(code **)(*piVar2 + 0x20))();
  fVar1 = _4185;
  piVar2 = *(int **)(param_1 + 0x73c);
  piVar2[0x27] = (int)_4185;
  piVar2[0x28] = (int)fVar1;
  *(undefined *)(piVar2 + 0x2a) = 0x7a;
  piVar2[0x29] = (int)(float)dVar6;
  (**(code **)(*piVar2 + 0x20))();
  iVar3 = *(int *)(param_1 + 0x7a4);
  piVar2 = *(int **)(param_1 + 0x774);
  piVar2[0x27] = *(int *)(param_1 + 0x7a0);
  piVar2[0x28] = iVar3;
  *(undefined *)(piVar2 + 0x2a) = 0x7a;
  piVar2[0x29] = (int)(float)dVar6;
  (**(code **)(*piVar2 + 0x20))();
  iVar3 = *(int *)(param_1 + 0x7dc);
  piVar2 = *(int **)(param_1 + 0x7ac);
  piVar2[0x27] = (int)_4185;
  piVar2[0x28] = iVar3;
  *(undefined *)(piVar2 + 0x2a) = 0x7a;
  piVar2[0x29] = (int)(float)dVar6;
  (**(code **)(*piVar2 + 0x20))();
  iVar3 = 0;
  iVar4 = 0;
  do {
    f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + iVar4 + 0x624);
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar3 < 4);
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return;
}


/* __stdcall dMsg_cornerMove(sub_msg_class *) */

void dMsg_cornerMove(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  double dVar6;
  undefined local_88;
  undefined uStack135;
  undefined uStack134;
  undefined uStack133;
  undefined local_84;
  undefined uStack131;
  undefined uStack130;
  undefined uStack129;
  undefined local_80;
  undefined uStack127;
  undefined uStack126;
  undefined uStack125;
  undefined local_7c;
  undefined uStack123;
  undefined uStack122;
  undefined uStack121;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  double local_50;
  double local_40;
  double local_38;
  double local_28;
  double local_20;
  double local_10;
  
  *(short *)(param_1 + 0x4d2) = *(short *)(param_1 + 0x4d2) + 1;
  if (0xef < *(short *)(param_1 + 0x4d2)) {
    *(undefined2 *)(param_1 + 0x4d2) = 0;
  }
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                            (0x3c,(int)*(short *)(param_1 + 0x4d2) % 0x3c,2);
  if (*(char *)(param_1 + 0x10c) == '\x01') {
    iVar2 = 0;
    iVar3 = 0;
    iVar5 = 4;
    do {
      iVar4 = iVar2 + 1;
      if (3 < iVar4) {
        iVar4 = 0;
      }
      *(char *)((int)&local_78 + iVar3) =
           (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)(&cc2_r_6222)[iVar2]) - _5912
                              ) +
                      (float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000,
                                                                       (uint)(byte)(&cc2_r_6222)
                                                                                   [iVar4] -
                                                                       (uint)(byte)(&cc2_r_6222)
                                                                                   [iVar2] ^
                                                                       0x80000000) - _4188)));
      local_50 = (double)CONCAT44(0x43300000,(uint)(byte)(&cc2_g_6223)[iVar2]);
      *(char *)((int)&local_78 + iVar3 + 1) =
           (char)(int)((float)(local_50 - _5912) +
                      (float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000,
                                                                       (uint)(byte)(&cc2_g_6223)
                                                                                   [iVar4] -
                                                                       (uint)(byte)(&cc2_g_6223)
                                                                                   [iVar2] ^
                                                                       0x80000000) - _4188)));
      local_38 = (double)CONCAT44(0x43300000,(uint)(byte)(&cc2_b_6224)[iVar2]);
      *(char *)((int)&local_78 + iVar3 + 2) =
           (char)(int)((float)(local_38 - _5912) +
                      (float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000,
                                                                       (uint)(byte)(&cc2_b_6224)
                                                                                   [iVar4] -
                                                                       (uint)(byte)(&cc2_b_6224)
                                                                                   [iVar2] ^
                                                                       0x80000000) - _4188)));
      local_20 = (double)CONCAT44(0x43300000,(uint)(byte)(&cc2_a_6225)[iVar2]);
      *(char *)((int)&local_78 + iVar3 + 3) =
           (char)(int)((float)(local_20 - _5912) +
                      (float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000,
                                                                       (uint)(byte)(&cc2_a_6225)
                                                                                   [iVar4] -
                                                                       (uint)(byte)(&cc2_a_6225)
                                                                                   [iVar2] ^
                                                                       0x80000000) - _4188)));
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  else {
    iVar3 = 0;
    iVar2 = 0;
    iVar5 = 4;
    do {
      iVar4 = iVar3 + 1;
      if (3 < iVar4) {
        iVar4 = 0;
      }
      local_10 = (double)CONCAT44(0x43300000,(uint)(byte)(&cc_r_6219)[iVar3]);
      *(char *)((int)&local_78 + iVar2) =
           (char)(int)((float)(local_10 - _5912) +
                      (float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000,
                                                                       (uint)(byte)(&cc_r_6219)
                                                                                   [iVar4] -
                                                                       (uint)(byte)(&cc_r_6219)
                                                                                   [iVar3] ^
                                                                       0x80000000) - _4188)));
      local_28 = (double)CONCAT44(0x43300000,(uint)(byte)(&cc_g_6220)[iVar3]);
      *(char *)((int)&local_78 + iVar2 + 1) =
           (char)(int)((float)(local_28 - _5912) +
                      (float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000,
                                                                       (uint)(byte)(&cc_g_6220)
                                                                                   [iVar4] -
                                                                       (uint)(byte)(&cc_g_6220)
                                                                                   [iVar3] ^
                                                                       0x80000000) - _4188)));
      local_40 = (double)CONCAT44(0x43300000,(uint)(byte)(&cc_b_6221)[iVar3]);
      *(char *)((int)&local_78 + iVar2 + 2) =
           (char)(int)((float)(local_40 - _5912) +
                      (float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000,
                                                                       (uint)(byte)(&cc_b_6221)
                                                                                   [iVar4] -
                                                                       (uint)(byte)(&cc_b_6221)
                                                                                   [iVar3] ^
                                                                       0x80000000) - _4188)));
      *(undefined *)((int)&local_78 + iVar2 + 3) = 0xff;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  sVar1 = *(short *)(param_1 + 0x4d2);
  uStack121 = (undefined)local_78;
  uStack122 = (undefined)((uint)local_78 >> 8);
  uStack123 = (undefined)((uint)local_78 >> 0x10);
  local_7c = (undefined)((uint)local_78 >> 0x18);
  uStack125 = (undefined)local_74;
  uStack126 = (undefined)((uint)local_74 >> 8);
  uStack127 = (undefined)((uint)local_74 >> 0x10);
  local_80 = (undefined)((uint)local_74 >> 0x18);
  uStack129 = (undefined)local_6c;
  uStack130 = (undefined)((uint)local_6c >> 8);
  uStack131 = (undefined)((uint)local_6c >> 0x10);
  local_84 = (undefined)((uint)local_6c >> 0x18);
  uStack133 = (undefined)local_70;
  uStack134 = (undefined)((uint)local_70 >> 8);
  uStack135 = (undefined)((uint)local_70 >> 0x10);
  local_88 = (undefined)((uint)local_70 >> 0x18);
  if (sVar1 < 0x3c) {
    iVar2 = *(int *)(param_1 + 0x49c);
    *(undefined *)(iVar2 + 0x10c) = local_7c;
    *(undefined *)(iVar2 + 0x10d) = uStack123;
    *(undefined *)(iVar2 + 0x10e) = uStack122;
    *(undefined *)(iVar2 + 0x10f) = uStack121;
    *(undefined *)(iVar2 + 0x110) = local_80;
    *(undefined *)(iVar2 + 0x111) = uStack127;
    *(undefined *)(iVar2 + 0x112) = uStack126;
    *(undefined *)(iVar2 + 0x113) = uStack125;
    *(undefined *)(iVar2 + 0x114) = local_84;
    *(undefined *)(iVar2 + 0x115) = uStack131;
    *(undefined *)(iVar2 + 0x116) = uStack130;
    *(undefined *)(iVar2 + 0x117) = uStack129;
    *(undefined *)(iVar2 + 0x118) = local_88;
    *(undefined *)(iVar2 + 0x119) = uStack135;
    *(undefined *)(iVar2 + 0x11a) = uStack134;
    *(undefined *)(iVar2 + 0x11b) = uStack133;
  }
  else {
    if (sVar1 < 0x78) {
      iVar2 = *(int *)(param_1 + 0x49c);
      *(undefined *)(iVar2 + 0x10c) = local_80;
      *(undefined *)(iVar2 + 0x10d) = uStack127;
      *(undefined *)(iVar2 + 0x10e) = uStack126;
      *(undefined *)(iVar2 + 0x10f) = uStack125;
      *(undefined *)(iVar2 + 0x110) = local_88;
      *(undefined *)(iVar2 + 0x111) = uStack135;
      *(undefined *)(iVar2 + 0x112) = uStack134;
      *(undefined *)(iVar2 + 0x113) = uStack133;
      *(undefined *)(iVar2 + 0x114) = local_7c;
      *(undefined *)(iVar2 + 0x115) = uStack123;
      *(undefined *)(iVar2 + 0x116) = uStack122;
      *(undefined *)(iVar2 + 0x117) = uStack121;
      *(undefined *)(iVar2 + 0x118) = local_84;
      *(undefined *)(iVar2 + 0x119) = uStack131;
      *(undefined *)(iVar2 + 0x11a) = uStack130;
      *(undefined *)(iVar2 + 0x11b) = uStack129;
    }
    else {
      if (sVar1 < 0xb4) {
        iVar2 = *(int *)(param_1 + 0x49c);
        *(undefined *)(iVar2 + 0x10c) = local_88;
        *(undefined *)(iVar2 + 0x10d) = uStack135;
        *(undefined *)(iVar2 + 0x10e) = uStack134;
        *(undefined *)(iVar2 + 0x10f) = uStack133;
        *(undefined *)(iVar2 + 0x110) = local_84;
        *(undefined *)(iVar2 + 0x111) = uStack131;
        *(undefined *)(iVar2 + 0x112) = uStack130;
        *(undefined *)(iVar2 + 0x113) = uStack129;
        *(undefined *)(iVar2 + 0x114) = local_80;
        *(undefined *)(iVar2 + 0x115) = uStack127;
        *(undefined *)(iVar2 + 0x116) = uStack126;
        *(undefined *)(iVar2 + 0x117) = uStack125;
        *(undefined *)(iVar2 + 0x118) = local_7c;
        *(undefined *)(iVar2 + 0x119) = uStack123;
        *(undefined *)(iVar2 + 0x11a) = uStack122;
        *(undefined *)(iVar2 + 0x11b) = uStack121;
      }
      else {
        iVar2 = *(int *)(param_1 + 0x49c);
        *(undefined *)(iVar2 + 0x10c) = local_84;
        *(undefined *)(iVar2 + 0x10d) = uStack131;
        *(undefined *)(iVar2 + 0x10e) = uStack130;
        *(undefined *)(iVar2 + 0x10f) = uStack129;
        *(undefined *)(iVar2 + 0x110) = local_7c;
        *(undefined *)(iVar2 + 0x111) = uStack123;
        *(undefined *)(iVar2 + 0x112) = uStack122;
        *(undefined *)(iVar2 + 0x113) = uStack121;
        *(undefined *)(iVar2 + 0x114) = local_88;
        *(undefined *)(iVar2 + 0x115) = uStack135;
        *(undefined *)(iVar2 + 0x116) = uStack134;
        *(undefined *)(iVar2 + 0x117) = uStack133;
        *(undefined *)(iVar2 + 0x118) = local_80;
        *(undefined *)(iVar2 + 0x119) = uStack127;
        *(undefined *)(iVar2 + 0x11a) = uStack126;
        *(undefined *)(iVar2 + 0x11b) = uStack125;
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dMsg_tactGuideShow(sub_msg_class *,
                                unsigned char) */

void dMsg_tactGuideShow(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  for (iVar1 = 0; iVar1 < (int)(uint)(byte)(&mBeatNum)[d_com_inf_game::g_dComIfG_gameInfo._23536_1_]
      ; iVar1 = iVar1 + 1) {
    if (iVar1 < (int)(param_2 & 0xff)) {
      if (d_com_inf_game::g_dComIfG_gameInfo._23536_1_ < 5) {
        iVar2 = param_1 + iVar3;
        f_op_msg_mng::fopMsgM_setInitAlpha(iVar2 + 0x8c4);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar2 + 0xa14),_4289);
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar2 + 0xb64));
      }
      else {
        iVar2 = param_1 + iVar3;
        f_op_msg_mng::fopMsgM_setInitAlpha(iVar2 + 0xb64);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar2 + 0xa14),_4289);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar2 + 0x8c4),_4289);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar2 + 0xcb4),_4289);
      }
    }
    else {
      iVar2 = param_1 + iVar3;
      *(undefined *)(*(int *)(iVar2 + 0x8c4) + 0xaa) = 0;
      *(undefined *)(*(int *)(iVar2 + 0xa14) + 0xaa) = 0;
      *(undefined *)(*(int *)(iVar2 + 0xb64) + 0xaa) = 0;
      if (4 < d_com_inf_game::g_dComIfG_gameInfo._23536_1_) {
        *(undefined *)(*(int *)(iVar2 + 0xcb4) + 0xaa) = 0;
      }
    }
    iVar3 = iVar3 + 0x38;
  }
  return;
}


/* __stdcall dMsg_numberInput(sub_msg_class *) */

void dMsg_numberInput(int param_1,undefined4 param_2,___ param_3)

{
  double dVar1;
  int iVar2;
  undefined uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  iVar2 = 0;
  iVar6 = 8;
  do {
    dVar1 = _4188;
    if (*(char *)(param_1 + iVar5 + 0x1085) == '\x16') {
      *(float *)(param_1 + 0x10ec) =
           *(float *)(*(int *)(param_1 + 0x544) + 0xc) +
           (float)((double)CONCAT44(0x43300000,*(uint *)(param_1 + iVar2 + 0xf6c) ^ 0x80000000) -
                  _4188);
      param_3 = *(___ *)(param_1 + 0x1104);
      *(float *)(param_1 + 0x10f0) =
           *(float *)(*(int *)(param_1 + 0x544) + 0x10) +
           (float)((double)CONCAT44(0x43300000,
                                    param_3 * ((3 - *(int *)(param_1 + 0x1108)) +
                                              *(int *)(param_1 + iVar2 + 0xfa8) * 2) ^ 0x80000000) -
                  dVar1);
    }
    iVar5 = iVar5 + 1;
    iVar2 = iVar2 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if (*(int *)(param_1 + 0xec) == 0x1cfa) {
    uVar3 = fopMsgM_msgDataProc_c::inputNumber((fopMsgM_msgDataProc_c *)(param_1 + 0xe04),3);
    *(undefined *)(param_1 + 0xfa) = uVar3;
  }
  else {
    uVar3 = fopMsgM_msgDataProc_c::inputNumber((fopMsgM_msgDataProc_c *)(param_1 + 0xe04),2);
    *(undefined *)(param_1 + 0xfa) = uVar3;
  }
  fopMsgM_msgDataProc_c::colorAnime((fopMsgM_msgDataProc_c *)(param_1 + 0xe04),maskPane);
  J2DTextBox::setString
            (DAT_803e6f04,
             (&num_str_6386)[(int)d_com_inf_game::g_dComIfG_gameInfo.field_0x5bba / 100],param_3);
  J2DTextBox::setString
            (DAT_803e6f00,
             (&num_str_6386)[((int)d_com_inf_game::g_dComIfG_gameInfo.field_0x5bba % 100) / 10],
             (int)d_com_inf_game::g_dComIfG_gameInfo.field_0x5bba);
  J2DTextBox::setString
            (numberPane,(&num_str_6386)[(int)d_com_inf_game::g_dComIfG_gameInfo.field_0x5bba % 10],
             (int)d_com_inf_game::g_dComIfG_gameInfo.field_0x5bba);
  daNpc_Bs1_c::m_tag_buy_item = (undefined)d_com_inf_game::g_dComIfG_gameInfo.field_0x5bba;
  if ((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
      (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3)) &&
     (cVar4 = f_op_msg_mng::fopMsgM_checkMessageSend(), cVar4 == '\0')) {
    d_meter::dMeter_Info = 3;
  }
  else {
    dMsg_setCancelMode(param_1);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x80210f08) */
/* __stdcall dMsg_tactInput(sub_msg_class *) */

void dMsg_tactInput(int param_1)

{
  float alpha;
  ushort uVar1;
  short sVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  double dVar9;
  undefined8 in_f31;
  int local_38 [3];
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar6 = (uint)d_com_inf_game::g_dComIfG_gameInfo._23536_1_;
  if (*(int *)(param_1 + 0x1100) < (int)(uint)(byte)(&mBeatNum)[uVar6]) {
    if (((uint)(byte)(&mBeatNum)[uVar6] != (uint)DAT_803a2caf) ||
       ((uint)*(byte *)(param_1 + 0x1168) != (uint)DAT_803a2caf)) {
      *(undefined4 *)(param_1 + 0x1100) = 0;
      *(undefined2 *)(param_1 + 0x65a) = 0;
      *(byte *)(param_1 + 0x1168) = DAT_803a2caf;
      dMsg_tactGuideShow(param_1,(&mBeatNum)[uVar6]);
    }
    if ((((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x2a4 &
        0x1000000) == 0) {
      if (((((uVar6 != 1) && (uVar6 != 5)) && (uVar6 != 6)) && (uVar6 != 7)) &&
         (((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0' ||
          (cVar4 = f_op_msg_mng::fopMsgM_checkMessageSend(), cVar4 != '\0')))) {
        dMsg_setCancelMode(param_1);
      }
    }
    else {
      uVar1 = (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->field_0x34d6;
      JAIZelInst::getMelodyPattern
                (&mDoAud_zelAudio_c::mTact,uVar6,*(long *)(param_1 + 0x1100),local_38);
      *(int *)(param_1 + 0x1100) = *(int *)(param_1 + 0x1100) + 1;
      if ((((short)uVar1 == local_38[0]) && ((&mBeatNum)[uVar6] == DAT_803a2caf)) &&
         ((int)*(short *)(param_1 + 0x65a) == *(int *)(param_1 + 0x1100) + -1)) {
        *(undefined2 *)(param_1 + *(short *)(param_1 + 0x65a) * 0x38 + 0xb9a) = 1;
        *(short *)(param_1 + 0x65a) = *(short *)(param_1 + 0x65a) + 1;
      }
      if (((int)(uint)DAT_803a2caf <= *(int *)(param_1 + 0x1100)) &&
         (iVar3 = daPy_lk_c::checkTactLastInput
                            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor), iVar3 == 0)) {
        *(undefined4 *)(param_1 + 0x1100) = 0;
        *(undefined2 *)(param_1 + 0x65a) = 0;
        dMsg_tactGuideShow(param_1,(&mBeatNum)[uVar6]);
      }
    }
  }
  iVar7 = 0;
  for (iVar3 = 0; iVar3 < (int)(uint)(byte)(&mBeatNum)[uVar6]; iVar3 = iVar3 + 1) {
    iVar5 = param_1 + iVar7;
    sVar2 = *(short *)(iVar5 + 0xb9a);
    if ((0 < sVar2) && (sVar2 < 6)) {
      dVar9 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)sVar2,0);
      alpha = (float)((double)_4289 + (double)(float)((double)_4289 * dVar9));
      dVar9 = (double)alpha;
      if (d_com_inf_game::g_dComIfG_gameInfo._23536_1_ < 5) {
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar5 + 0xa14),alpha);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar5 + 0xb64),(float)dVar9);
      }
      else {
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar5 + 0xa14),alpha);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar5 + 0x8c4),(float)dVar9);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar5 + 0xcb4),(float)dVar9);
      }
      if (*(short *)(param_1 + (uint)(byte)(&mBeatNum)[uVar6] * 0x38 + 0xb62) == 5) {
        *(undefined2 *)(param_1 + 0xf8) = 0xe;
        *(undefined4 *)(param_1 + 0x1100) = 0;
      }
      *(short *)(iVar5 + 0xb9a) = *(short *)(iVar5 + 0xb9a) + 1;
    }
    iVar7 = iVar7 + 0x38;
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  return;
}


/* __stdcall dMsg_tactInput2(sub_msg_class *) */

void dMsg_tactInput2(void)

{
  if (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3) {
    return;
  }
  d_com_inf_game::g_dComIfG_gameInfo._23529_1_ = 1;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x80210fd8) */
/* __stdcall dMsg_subTextScale(sub_msg_class *,
                               float) */

void dMsg_subTextScale(double param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar1 = 1;
  iVar3 = 0x38;
  do {
    iVar2 = param_2 + iVar3;
    (**(code **)(**(int **)(iVar2 + 0x26c) + 0x10))
              ((double)(float)((double)*(float *)(iVar2 + 0x278) * param_1),
               (double)(float)((double)*(float *)(iVar2 + 0x27c) * param_1));
    (**(code **)(**(int **)(iVar2 + 0x26c) + 0x18))
              ((double)(float)((double)*(float *)(iVar2 + 0x298) * param_1),
               (double)(float)((double)*(float *)(iVar2 + 0x29c) * param_1));
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 10);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80211704) */
/* WARNING: Removing unreachable block (ram,0x8021170c) */
/* __stdcall dMsg_subTextSizeSet(sub_msg_class *) */

void dMsg_subTextSizeSet(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  double in_f0;
  undefined8 in_f30;
  double dVar12;
  undefined8 in_f31;
  double dVar13;
  double local_78;
  double local_68;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  iVar7 = (int)*(float *)(*(int *)(param_1 + 0x544) + 0xe4);
  if (*(short *)(param_1 + 0xf8) == 8) {
    local_78 = (double)CONCAT44(0x43300000,iVar7 + *(int *)(param_1 + 0x110c) ^ 0x80000000);
    in_f0 = (double)(float)(local_78 - _4188);
  }
  else {
    if (*(short *)(param_1 + 0xf8) == 9) {
      local_78 = (double)CONCAT44(0x43300000,*(int *)(param_1 + 0x110c) + iVar7 * 2 ^ 0x80000000);
      in_f0 = (double)(float)(local_78 - _4188);
    }
  }
  fVar1 = *(float *)(param_1 + 0x4bc);
  if (fVar1 < _4288) {
    fVar1 = (fVar1 + *(float *)(param_1 + 0x4cc) * _4289) -
            (float)((double)CONCAT44(0x43300000,(int)DAT_803e6bc0 ^ 0x80000000) - _4188);
  }
  else {
    local_78 = (double)CONCAT44(0x43300000,(int)DAT_803e6bc0 ^ 0x80000000);
    fVar1 = (float)(local_78 - _4188) + (fVar1 - *(float *)(param_1 + 0x4cc) * _4289);
  }
  local_68 = (double)CONCAT44(0x43300000,(int)DAT_803e6bbc ^ 0x80000000);
  fVar2 = (float)(local_68 - _4188) +
          ((_4186 * (float)((double)CONCAT44(0x43300000,(uint)DAT_803e6bc2) - _5912) +
           (float)((double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x1020) ^ 0x80000000) - _4188)) -
          *(float *)(param_1 + 0x140));
  iVar7 = 0;
  iVar10 = 4;
  do {
    *(float *)(param_1 + iVar7 + 0x148) = *(float *)(param_1 + iVar7 + 0x140) + fVar2;
    iVar7 = iVar7 + 0x38;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  *(float *)(param_1 + 0x3b0) = *(float *)(param_1 + 0x3a8) + fVar2;
  *(float *)(param_1 + 0x458) = *(float *)(param_1 + 0x450) + fVar2;
  *(float *)(param_1 + 0x490) = *(float *)(param_1 + 0x488) + fVar2;
  fVar2 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6bbe ^ 0x80000000) - _4188) +
          (float)(in_f0 - (double)*(float *)(param_1 + 0x144));
  iVar7 = 0;
  iVar10 = 4;
  do {
    *(float *)(param_1 + iVar7 + 0x14c) = *(float *)(param_1 + iVar7 + 0x144) + fVar2;
    iVar7 = iVar7 + 0x38;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  *(float *)(param_1 + 0x3ec) = *(float *)(param_1 + 0x3e4) + fVar2;
  *(float *)(param_1 + 0x424) = *(float *)(param_1 + 0x41c) + fVar2;
  *(float *)(param_1 + 0x494) = *(float *)(param_1 + 0x48c) + fVar2;
  fVar3 = _4289;
  fVar2 = (*(float *)(param_1 + 0x488) - *(float *)(param_1 + 0x490)) * _4289;
  *(float *)(param_1 + 0x288) = *(float *)(param_1 + 0x280) + fVar2;
  *(float *)(param_1 + 0x2c0) = *(float *)(param_1 + 0x2b8) + fVar2;
  *(float *)(param_1 + 0x2f8) = *(float *)(param_1 + 0x2f0) - fVar2;
  *(float *)(param_1 + 0x330) = *(float *)(param_1 + 0x328) + fVar2;
  *(float *)(param_1 + 0x368) = *(float *)(param_1 + 0x360) - fVar2;
  *(float *)(param_1 + 0x3d8) = *(float *)(param_1 + 0x3d0) + fVar2;
  *(float *)(param_1 + 0x410) = *(float *)(param_1 + 0x408) - fVar2;
  dVar12 = _5912;
  fVar3 = (*(float *)(param_1 + 0x140) - *(float *)(param_1 + 0x148)) * fVar3;
  iVar7 = 0;
  iVar10 = 4;
  do {
    *(float *)(param_1 + iVar7 + 0x138) =
         (float)((double)CONCAT44(0x43300000,(uint)DAT_803e6bc2) - dVar12) +
         *(float *)(param_1 + iVar7 + 0x130) + fVar3;
    iVar7 = iVar7 + 0x38;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  fVar4 = (*(float *)(param_1 + 0x48c) - *(float *)(param_1 + 0x494)) * _4289;
  fVar2 = *(float *)(param_1 + 0x284);
  *(float *)(param_1 + 0x28c) = fVar1;
  *(float *)(param_1 + 0x2c4) = *(float *)(param_1 + 700) - fVar4;
  *(float *)(param_1 + 0x2fc) = *(float *)(param_1 + 0x2f4) - fVar4;
  *(float *)(param_1 + 0x334) = *(float *)(param_1 + 0x32c) + fVar4;
  *(float *)(param_1 + 0x36c) = *(float *)(param_1 + 0x364) + fVar4;
  *(float *)(param_1 + 0x3a4) = *(float *)(param_1 + 0x39c) - fVar4;
  *(float *)(param_1 + 0x44c) = *(float *)(param_1 + 0x444) + fVar4;
  iVar7 = 0;
  iVar10 = 4;
  do {
    *(float *)(param_1 + iVar7 + 0x13c) = *(float *)(param_1 + iVar7 + 0x134) + (fVar1 - fVar2);
    fVar5 = _4289;
    iVar7 = iVar7 + 0x38;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  *(float *)(param_1 + 0x210) =
       fVar3 + *(float *)(param_1 + 0x200) + *(float *)(param_1 + 0x220) * _4289;
  *(float *)(param_1 + 0x248) =
       _4186 * (float)((double)CONCAT44(0x43300000,(uint)DAT_803e6bc2) - _5912) +
       *(float *)(param_1 + 0x210) + *(float *)(param_1 + 0x220) +
       (float)((double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x1020) ^ 0x80000000) - _4188);
  *(float *)(param_1 + 0x214) =
       fVar4 + *(float *)(param_1 + 0x204) + *(float *)(param_1 + 0x224) * fVar5;
  *(float *)(param_1 + 0x24c) =
       fVar4 + *(float *)(param_1 + 0x23c) + *(float *)(param_1 + 0x25c) * fVar5;
  iVar7 = 0;
  iVar10 = 0;
  do {
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_1 + iVar10 + 0x11c));
    iVar7 = iVar7 + 1;
    iVar10 = iVar10 + 0x38;
  } while (iVar7 < 4);
  iVar7 = 0;
  iVar10 = 0;
  do {
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_1 + iVar10 + 0x26c));
    iVar7 = iVar7 + 1;
    iVar10 = iVar10 + 0x38;
  } while (iVar7 < 10);
  fVar1 = _6606;
  if (_6607 <= *(float *)(param_1 + 0x490)) {
    fVar1 = _4186;
  }
  dVar13 = (double)fVar1;
  fVar2 = *(float *)(param_1 + 0x29c) * _4289;
  piVar8 = *(int **)(param_1 + 0x26c);
  piVar8[0x27] = (int)(*(float *)(param_1 + 0x298) * _4289);
  piVar8[0x28] = (int)fVar2;
  *(undefined *)(piVar8 + 0x2a) = 0x7a;
  piVar8[0x29] = (int)fVar1;
  (**(code **)(*piVar8 + 0x20))();
  iVar7 = 0;
  iVar10 = 0;
  dVar12 = (double)_4289;
  do {
    iVar9 = param_1 + iVar10;
    fVar1 = *(float *)(iVar9 + 0x14c);
    fVar2 = *(float *)(param_1 + 0x28c);
    fVar3 = *(float *)(iVar9 + 0x13c);
    piVar8 = *(int **)(iVar9 + 0x11c);
    piVar8[0x27] = (int)(((float)((double)*(float *)(iVar9 + 0x148) * dVar12) +
                         *(float *)(param_1 + 0x288)) - *(float *)(iVar9 + 0x138));
    piVar8[0x28] = (int)(((float)((double)fVar1 * dVar12) + fVar2) - fVar3);
    *(undefined *)(piVar8 + 0x2a) = 0x7a;
    piVar8[0x29] = (int)(float)dVar13;
    (**(code **)(*piVar8 + 0x20))();
    iVar7 = iVar7 + 1;
    iVar10 = iVar10 + 0x38;
  } while (iVar7 < 4);
  uVar6 = (int)DAT_803e6bb8 ^ 0x80000000;
  fVar1 = _5863;
  if ((float)((double)CONCAT44(0x43300000,uVar6) - _4188) < *(float *)(param_1 + 0x490)) {
    fVar1 = (float)((double)CONCAT44(0x43300000,
                                     (int)(_4289 + *(float *)(param_1 + 0x490) /
                                                   (float)((double)CONCAT44(0x43300000,uVar6) -
                                                          _4188)) ^ 0x80000000) - _4188);
  }
  uVar6 = (int)DAT_803e6bb8 ^ 0x80000000;
  local_78 = (double)CONCAT44(0x43300000,uVar6);
  fVar2 = _5863;
  if ((float)(local_78 - _4188) < *(float *)(param_1 + 0x494)) {
    fVar2 = (float)((double)CONCAT44(0x43300000,
                                     (int)(_4289 + *(float *)(param_1 + 0x494) /
                                                   (float)((double)CONCAT44(0x43300000,uVar6) -
                                                          _4188)) ^ 0x80000000) - _4188);
  }
  *(undefined *)(*(int *)(param_1 + 900) + 0x134) = 1;
  fVar3 = _4185;
  *(float *)(*(int *)(param_1 + 900) + 0x124) = _4185;
  *(float *)(*(int *)(param_1 + 900) + 0x128) = fVar3;
  *(float *)(*(int *)(param_1 + 900) + 300) = fVar1;
  fVar4 = _5863;
  *(float *)(*(int *)(param_1 + 900) + 0x130) = _5863;
  *(undefined *)(*(int *)(param_1 + 0x3bc) + 0x134) = 1;
  *(float *)(*(int *)(param_1 + 0x3bc) + 0x124) = fVar3;
  *(float *)(*(int *)(param_1 + 0x3bc) + 0x128) = fVar3;
  *(float *)(*(int *)(param_1 + 0x3bc) + 300) = fVar2;
  *(float *)(*(int *)(param_1 + 0x3bc) + 0x130) = fVar4;
  *(undefined *)(*(int *)(param_1 + 0x3f4) + 0x134) = 1;
  *(float *)(*(int *)(param_1 + 0x3f4) + 0x124) = fVar3;
  *(float *)(*(int *)(param_1 + 0x3f4) + 0x128) = fVar3;
  *(float *)(*(int *)(param_1 + 0x3f4) + 300) = fVar2;
  *(float *)(*(int *)(param_1 + 0x3f4) + 0x130) = fVar4;
  *(undefined *)(*(int *)(param_1 + 0x42c) + 0x134) = 1;
  *(float *)(*(int *)(param_1 + 0x42c) + 0x124) = fVar3;
  *(float *)(*(int *)(param_1 + 0x42c) + 0x128) = fVar3;
  *(float *)(*(int *)(param_1 + 0x42c) + 300) = fVar1;
  *(float *)(*(int *)(param_1 + 0x42c) + 0x130) = fVar4;
  *(undefined2 *)(param_1 + 0x49a) = 0;
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  __psq_l0(auStack24,uVar11);
  __psq_l1(auStack24,uVar11);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802118b0) */
/* WARNING: Removing unreachable block (ram,0x802118b8) */
/* __stdcall dMsg_subTextOpen(sub_msg_class *) */

void dMsg_subTextOpen(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  iVar3 = (int)DAT_803e6b88;
  iVar2 = (int)DAT_803e6b8a;
  *(short *)(param_1 + 0x49a) = *(short *)(param_1 + 0x49a) + 1;
  dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                            (iVar3 + iVar2,(int)*(short *)(param_1 + 0x49a),0);
  iVar3 = (int)*(short *)(param_1 + 0x49a);
  iVar2 = (int)DAT_803e6b88;
  if (iVar3 < iVar2) {
    dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar2,iVar3,0);
    fVar1 = frameScale_6619 + (float)(dVar6 * (double)(DAT_80361df0 - frameScale_6619));
  }
  else {
    dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease((int)DAT_803e6b8a,iVar3 - iVar2,0);
    fVar1 = DAT_80361df0 + (float)(dVar6 * (double)(DAT_80361df4 - DAT_80361df0));
  }
  dMsg_subTextScale((double)fVar1,param_1);
  iVar2 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + iVar3 + 0x26c),(float)dVar5);
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar2 < 10);
  dVar6 = (double)(_5863 - (float)((double)(_5863 - (float)((double)CONCAT44(0x43300000,
                                                                             (uint)DAT_803e6bc5) -
                                                           _5912) / _5908) * dVar5));
  f_op_msg_mng::fopMsgM_setNowAlpha
            ((fopMsgM_pane_class *)(param_1 + 0x49c),
             _5863 - (float)((double)(_5863 - (float)((double)CONCAT44(0x43300000,(uint)DAT_803e6bc4
                                                                      ) - _5912) / _5908) * dVar5));
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x544),(float)dVar6);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x57c),(float)dVar6);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x5b4),(float)dVar6);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x5ec),(float)dVar6);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80211a6c) */
/* __stdcall dMsg_subTextClose(sub_msg_class *) */

void dMsg_subTextClose(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  *(short *)(param_1 + 0x49a) = *(short *)(param_1 + 0x49a) + 1;
  iVar1 = (int)*(short *)(param_1 + 0x49a);
  iVar2 = (int)DAT_803e6b8c;
  if (iVar2 < iVar1) {
    dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                              ((int)DAT_803e6bba,(int)DAT_803e6bba - (iVar1 - iVar2),0);
    dVar5 = (double)(_5863 - (float)((double)(_5863 - (float)((double)CONCAT44(0x43300000,
                                                                               (uint)DAT_803e6bc5) -
                                                             _5912) / _5908) * dVar4));
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)(param_1 + 0x49c),
               _5863 - (float)((double)(_5863 - (float)((double)CONCAT44(0x43300000,
                                                                         (uint)DAT_803e6bc4) - _5912
                                                       ) / _5908) * dVar4));
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x544),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x57c),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x5b4),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x5ec),(float)dVar5);
  }
  else {
    dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar2,iVar2 - iVar1,0);
    dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                              ((int)DAT_803e6b8c,(int)*(short *)(param_1 + 0x49a),0);
    dMsg_subTextScale((double)(_5863 + (float)((double)(DAT_803e6b84 - _5863) * dVar5)),param_1);
    iVar1 = 0;
    iVar2 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlpha
                ((fopMsgM_pane_class *)(param_1 + iVar2 + 0x26c),(float)dVar4);
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x38;
    } while (iVar1 < 10);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x1fc));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x234));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x11c));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x154));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x18c));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x1c4));
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __stdcall dMsg_setCloseSound(sub_msg_class *,
                                unsigned char) */

void dMsg_setCloseSound(undefined4 param_1,char param_2)

{
  JAIZelBasic::talkOut(JAIZelBasic::zel_basic);
  if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 == 0x27) || (param_2 != '\0')) {
    JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x880,(cXyz *)0x0,0,0,_5863,_5863,_6707,_6707,0);
  }
  else {
    JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x80d,(cXyz *)0x0,0,0,_5863,_5863,_6707,_6707,0);
  }
  return;
}


/* __stdcall dMsg_setCancelMode(sub_msg_class *) */

void dMsg_setCancelMode(int param_1)

{
  *(undefined2 *)(param_1 + 0xf8) = 0xe;
  *(undefined4 *)(param_1 + 0x1100) = 0;
  if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
    *(undefined *)(param_1 + 0x1169) = 1;
    d_com_inf_game::g_dComIfG_gameInfo._23529_1_ = 1;
  }
  else {
    *(undefined *)(param_1 + 0x1169) = 0;
  }
  dMsg_setCloseSound(param_1,0);
  JAIZelBasic::talkOut(JAIZelBasic::zel_basic);
  *(char *)(param_1 + 0x116a) = *(char *)(param_1 + 0x116a) + '\x01';
  d_com_inf_game::g_dComIfG_gameInfo._23528_1_ = *(undefined *)(param_1 + 0x116a);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dMsg_messageShow(sub_msg_class *) */

void dMsg_messageShow(int param_1)

{
  char cVar2;
  int iVar1;
  int iVar3;
  int iVar4;
  int iVar5;
  
  f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(param_1 + 0x49c),_5863);
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x49c);
  dMsg_messagePaneShow(param_1);
  dMsg_yose_select(param_1);
  if (*(char *)(param_1 + 0x111) != '\0') {
    cVar2 = d_com_inf_game::dComIfGp_getReverb((int)(char)dStage_roomControl_c::mStayNo);
    JAIZelBasic::messageSePlay
              (JAIZelBasic::zel_basic,(ushort)*(byte *)(param_1 + 0x111),(Vec *)0x0,cVar2);
  }
  *(undefined *)(param_1 + 0x109d) = 1;
  fopMsgM_msgDataProc_c::stringSet((fopMsgM_msgDataProc_c *)(param_1 + 0xe04));
  iVar3 = 0;
  iVar5 = 0;
  iVar4 = 0;
  do {
    cVar2 = *(char *)(param_1 + iVar3 + 0x1085);
    iVar1 = *(int *)(param_1 + iVar4 + 0x1024);
    if (((((byte)(cVar2 - 10U) < 4) || (cVar2 == '\x15')) || (cVar2 == '\x17')) && (iVar1 == 0)) {
      iVar1 = -1;
    }
    if (((cVar2 != -1) && (*(short *)((int)&buttonTimer + iVar5) == -1)) &&
       ((cVar2 != '\x14' && ((cVar2 != '\x15' && (cVar2 != '\x16')))))) {
      f_op_msg_mng::fopMsgM_outFontSet
                (*(undefined4 *)((int)&button_icon + iVar4),
                 *(undefined4 *)((int)&button_kage + iVar4),(short *)((int)&buttonTimer + iVar5),
                 iVar1);
    }
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 2;
    iVar4 = iVar4 + 4;
  } while (iVar3 < 8);
  dMsg_setString(param_1);
  *(undefined4 *)(param_1 + 0x1100) = 0;
  iVar4 = 0;
  for (iVar3 = 0; iVar3 < (int)(uint)(byte)(&mBeatNum)[d_com_inf_game::g_dComIfG_gameInfo._23536_1_]
      ; iVar3 = iVar3 + 1) {
    iVar5 = param_1 + iVar4;
    *(undefined2 *)(iVar5 + 0xb9a) = 0;
    if (d_com_inf_game::g_dComIfG_gameInfo._23536_1_ < 5) {
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar5 + 0xa14),_4289);
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar5 + 0xb64));
    }
    else {
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar5 + 0xa14),_4289);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar5 + 0x8c4),_4289);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar5 + 0xcb4),_4289);
    }
    iVar4 = iVar4 + 0x38;
  }
  return;
}


/* __stdcall dMsg_stopProc(sub_msg_class *) */

undefined4 dMsg_stopProc(int param_1)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 0x109b) == '\0') {
    if ((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
        (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3)) ||
       (d_com_inf_game::g_dComIfG_gameInfo._23575_1_ != '\0')) {
      if ((*(char *)(param_1 + 0x10c) != '\x05') && (*(char *)(param_1 + 0x10c) != '\x0e')) {
        dMsg_arrowMove(param_1);
      }
      d_meter::dMeter_Info = 1;
    }
    else {
      *(undefined2 *)(param_1 + 0xf8) = 6;
      dMsg_value_init(param_1);
      dMsg_yose_select(param_1);
      dMsg_setString(param_1);
      if ((*(char *)(param_1 + 0x10c) != '\x05') && (*(char *)(param_1 + 0x10c) != '\x0e')) {
        dMsg_arrowInit(param_1);
      }
      d_meter::dMeter_Info = 2;
      if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 == 0x27) {
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x880,(cXyz *)0x0,0,0,_5863,_5863,_6707,_6707,0)
        ;
      }
      else {
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x80b,(cXyz *)0x0,0,0,_5863,_5863,_6707,_6707,0)
        ;
      }
      if (((*(char *)(param_1 + 0x10d) == '\0') &&
          ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0')) &&
         (d_com_inf_game::g_dComIfG_gameInfo._23575_1_ == '\0')) {
        if (*(char *)(param_1 + 0x109a) == '\0') {
          *(undefined *)(param_1 + 0x109d) = 1;
        }
        if (((*(char *)(param_1 + 0x109b) == '\0') && (*(char *)(param_1 + 0x109c) == '\0')) &&
           (*(int *)(param_1 + 0xf5c) != 0)) {
          *(undefined4 *)(param_1 + 0xf5c) = 0;
          *(undefined *)(param_1 + 0x109a) = 0;
        }
      }
      *(char *)(param_1 + 0x116a) = *(char *)(param_1 + 0x116a) + '\x01';
      d_com_inf_game::g_dComIfG_gameInfo._23528_1_ = *(undefined *)(param_1 + 0x116a);
    }
  }
  else {
    uVar1 = *(uint *)(param_1 + 0xf5c);
    uVar1 = uVar1 - 1 & (int)(-uVar1 & ~uVar1) >> 0x1f;
    *(uint *)(param_1 + 0xf5c) = uVar1;
    if (uVar1 == 0) {
      *(undefined *)(param_1 + 0x109b) = 0;
      *(undefined *)(param_1 + 0x109a) = 0;
      *(undefined2 *)(param_1 + 0xf8) = 6;
      dMsg_value_init();
      dMsg_yose_select(param_1);
      dMsg_setString(param_1);
      if ((*(char *)(param_1 + 0x10c) != '\x05') && (*(char *)(param_1 + 0x10c) != '\x0e')) {
        dMsg_arrowInit(param_1);
      }
      d_meter::dMeter_Info = 2;
      if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 == 0x27) {
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x880,(cXyz *)0x0,0,0,_5863,_5863,_6707,_6707,0)
        ;
      }
      else {
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x80b,(cXyz *)0x0,0,0,_5863,_5863,_6707,_6707,0)
        ;
      }
      *(char *)(param_1 + 0x116a) = *(char *)(param_1 + 0x116a) + '\x01';
      d_com_inf_game::g_dComIfG_gameInfo._23528_1_ = *(undefined *)(param_1 + 0x116a);
    }
    else {
      if ((*(char *)(param_1 + 0x10c) != '\x05') && (*(char *)(param_1 + 0x10c) != '\x0e')) {
        dMsg_arrowMove();
      }
      d_meter::dMeter_Info = 1;
    }
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dMsg_selectProc(sub_msg_class *) */

undefined4 dMsg_selectProc(int param_1)

{
  uint uVar1;
  short sVar2;
  float fVar3;
  char cVar5;
  undefined uVar6;
  int iVar4;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  J2DPicture *pJVar13;
  int iVar14;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  
  iVar7 = *(int *)(param_1 + 0x544);
  uVar1 = (uint)*(float *)(iVar7 + 0xe4);
  sVar2 = *(short *)(param_1 + 0x2a2);
  if (sVar2 == 0) {
    sVar2 = *(short *)(param_1 + 0xf8);
    if ((sVar2 != 8) && (sVar2 != 9)) {
      if (sVar2 != 0x14) {
        return 1;
      }
      *(undefined2 *)(param_1 + 0x2a2) = 2;
      return 1;
    }
    if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
       ((-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 &&
        (cVar5 = f_op_msg_mng::fopMsgM_checkMessageSend(), cVar5 == '\0')))) {
      if ((*(char *)(param_1 + 0x10c) != '\x05') && (*(char *)(param_1 + 0x10c) != '\x0e')) {
        dMsg_arrowMove(param_1);
      }
      d_meter::dMeter_Info = 1;
      return 1;
    }
    dMsg_subTextSizeSet(param_1);
    *(undefined2 *)(param_1 + 0x2a2) = 1;
    JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x884,(cXyz *)0x0,0,0,_5863,_5863,_6707,_6707,0);
    return 1;
  }
  if (sVar2 == 1) {
    if ((int)*(short *)(param_1 + 0x49a) < (int)DAT_803e6b88 + (int)DAT_803e6b8a) {
      dMsg_subTextOpen();
      return 1;
    }
    f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x1fc);
    f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x234);
    f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x11c);
    f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x154);
    f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x18c);
    f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x1c4);
    *(undefined2 *)(param_1 + 0x49a) = 0;
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(param_1 + 0x1fc),(double)_4185,(double)_4185);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(param_1 + 0x234),(double)_4185,(double)_4185);
    *(undefined2 *)(param_1 + 0x2a2) = 2;
    if (*(char *)(param_1 + 0x10c) == '\x05') {
      return 1;
    }
    if (*(char *)(param_1 + 0x10c) == '\x0e') {
      return 1;
    }
    dMsg_arrowInit(param_1);
    return 1;
  }
  if (sVar2 != 2) {
    return 1;
  }
  sVar2 = *(short *)(param_1 + 0xf8);
  if (sVar2 == 8) {
    uVar6 = fopMsgM_msgDataProc_c::selectCheck2
                      ((fopMsgM_msgDataProc_c *)(param_1 + 0xe04),arrowPane,
                       (int)*(float *)(iVar7 + 0xc),
                       (int)*(float *)(iVar7 + 0x10) +
                       uVar1 + ((int)uVar1 >> 1) + (uint)((int)uVar1 < 0 && (uVar1 & 1) != 0),uVar1)
    ;
    *(undefined *)(param_1 + 0xfa) = uVar6;
    *(short *)(param_1 + 0x462) = *(short *)(param_1 + 0x462) + 1;
    if (0x13 < *(short *)(param_1 + 0x462)) {
      *(undefined2 *)(param_1 + 0x462) = 0;
    }
    fVar3 = _5863;
    if (*(short *)(param_1 + 0x462) < 10) {
      pJVar13 = *(J2DPicture **)(param_1 + 0x1fc);
      pJVar13->mBlendKonstColorF[0] = _5863;
      pJVar13->mBlendKonstColorF[1] = _4185;
      pJVar13->mBlendKonstColorF[2] = fVar3;
      pJVar13->mBlendKonstColorF[3] = fVar3;
      J2DPicture::setBlendKonstColor(pJVar13);
      fVar3 = _5863;
      pJVar13->mBlendKonstAlphaF[0] = _5863;
      pJVar13->mBlendKonstAlphaF[1] = _4185;
      pJVar13->mBlendKonstAlphaF[2] = fVar3;
      pJVar13->mBlendKonstAlphaF[3] = fVar3;
      J2DPicture::setBlendKonstAlpha(pJVar13);
      fVar3 = _5863;
      pJVar13 = *(J2DPicture **)(param_1 + 0x234);
      pJVar13->mBlendKonstColorF[0] = _5863;
      pJVar13->mBlendKonstColorF[1] = _4185;
      pJVar13->mBlendKonstColorF[2] = fVar3;
      pJVar13->mBlendKonstColorF[3] = fVar3;
      J2DPicture::setBlendKonstColor(pJVar13);
      fVar3 = _5863;
      pJVar13->mBlendKonstAlphaF[0] = _5863;
      pJVar13->mBlendKonstAlphaF[1] = _4185;
      pJVar13->mBlendKonstAlphaF[2] = fVar3;
      pJVar13->mBlendKonstAlphaF[3] = fVar3;
      J2DPicture::setBlendKonstAlpha(pJVar13);
    }
    else {
      if (*(short *)(param_1 + 0x462) < 0x14) {
        pJVar13 = *(J2DPicture **)(param_1 + 0x1fc);
        pJVar13->mBlendKonstColorF[0] = _4185;
        fVar3 = _5863;
        pJVar13->mBlendKonstColorF[1] = _5863;
        pJVar13->mBlendKonstColorF[2] = fVar3;
        pJVar13->mBlendKonstColorF[3] = fVar3;
        J2DPicture::setBlendKonstColor(pJVar13);
        pJVar13->mBlendKonstAlphaF[0] = _4185;
        fVar3 = _5863;
        pJVar13->mBlendKonstAlphaF[1] = _5863;
        pJVar13->mBlendKonstAlphaF[2] = fVar3;
        pJVar13->mBlendKonstAlphaF[3] = fVar3;
        J2DPicture::setBlendKonstAlpha(pJVar13);
        pJVar13 = *(J2DPicture **)(param_1 + 0x234);
        pJVar13->mBlendKonstColorF[0] = _4185;
        fVar3 = _5863;
        pJVar13->mBlendKonstColorF[1] = _5863;
        pJVar13->mBlendKonstColorF[2] = fVar3;
        pJVar13->mBlendKonstColorF[3] = fVar3;
        J2DPicture::setBlendKonstColor(pJVar13);
        pJVar13->mBlendKonstAlphaF[0] = _4185;
        fVar3 = _5863;
        pJVar13->mBlendKonstAlphaF[1] = _5863;
        pJVar13->mBlendKonstAlphaF[2] = fVar3;
        pJVar13->mBlendKonstAlphaF[3] = fVar3;
        J2DPicture::setBlendKonstAlpha(pJVar13);
      }
    }
    local_28 = (double)CONCAT44(0x43300000,*(byte *)(param_1 + 0xfa) * uVar1 ^ 0x80000000);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(param_1 + 0x1fc),(double)_4185,
               (double)(float)(local_28 - _4188));
    local_30 = (double)CONCAT44(0x43300000,*(byte *)(param_1 + 0xfa) * uVar1 ^ 0x80000000);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(param_1 + 0x234),(double)_4185,
               (double)(float)(local_30 - _4188));
  }
  else {
    if (sVar2 == 9) {
      uVar6 = fopMsgM_msgDataProc_c::selectCheck3
                        ((fopMsgM_msgDataProc_c *)(param_1 + 0xe04),arrowPane,
                         (int)*(float *)(iVar7 + 0xc),(int)*(float *)(iVar7 + 0x10),uVar1);
      *(undefined *)(param_1 + 0xfa) = uVar6;
      *(short *)(param_1 + 0x462) = *(short *)(param_1 + 0x462) + 1;
      if (0x13 < *(short *)(param_1 + 0x462)) {
        *(undefined2 *)(param_1 + 0x462) = 0;
      }
      fVar3 = _5863;
      if (*(short *)(param_1 + 0x462) < 10) {
        pJVar13 = *(J2DPicture **)(param_1 + 0x1fc);
        pJVar13->mBlendKonstColorF[0] = _5863;
        pJVar13->mBlendKonstColorF[1] = _4185;
        pJVar13->mBlendKonstColorF[2] = fVar3;
        pJVar13->mBlendKonstColorF[3] = fVar3;
        J2DPicture::setBlendKonstColor(pJVar13);
        fVar3 = _5863;
        pJVar13->mBlendKonstAlphaF[0] = _5863;
        pJVar13->mBlendKonstAlphaF[1] = _4185;
        pJVar13->mBlendKonstAlphaF[2] = fVar3;
        pJVar13->mBlendKonstAlphaF[3] = fVar3;
        J2DPicture::setBlendKonstAlpha(pJVar13);
        fVar3 = _5863;
        pJVar13 = *(J2DPicture **)(param_1 + 0x234);
        pJVar13->mBlendKonstColorF[0] = _5863;
        pJVar13->mBlendKonstColorF[1] = _4185;
        pJVar13->mBlendKonstColorF[2] = fVar3;
        pJVar13->mBlendKonstColorF[3] = fVar3;
        J2DPicture::setBlendKonstColor(pJVar13);
        fVar3 = _5863;
        pJVar13->mBlendKonstAlphaF[0] = _5863;
        pJVar13->mBlendKonstAlphaF[1] = _4185;
        pJVar13->mBlendKonstAlphaF[2] = fVar3;
        pJVar13->mBlendKonstAlphaF[3] = fVar3;
        J2DPicture::setBlendKonstAlpha(pJVar13);
      }
      else {
        if (*(short *)(param_1 + 0x462) < 0x14) {
          pJVar13 = *(J2DPicture **)(param_1 + 0x1fc);
          pJVar13->mBlendKonstColorF[0] = _4185;
          fVar3 = _5863;
          pJVar13->mBlendKonstColorF[1] = _5863;
          pJVar13->mBlendKonstColorF[2] = fVar3;
          pJVar13->mBlendKonstColorF[3] = fVar3;
          J2DPicture::setBlendKonstColor(pJVar13);
          pJVar13->mBlendKonstAlphaF[0] = _4185;
          fVar3 = _5863;
          pJVar13->mBlendKonstAlphaF[1] = _5863;
          pJVar13->mBlendKonstAlphaF[2] = fVar3;
          pJVar13->mBlendKonstAlphaF[3] = fVar3;
          J2DPicture::setBlendKonstAlpha(pJVar13);
          pJVar13 = *(J2DPicture **)(param_1 + 0x234);
          pJVar13->mBlendKonstColorF[0] = _4185;
          fVar3 = _5863;
          pJVar13->mBlendKonstColorF[1] = _5863;
          pJVar13->mBlendKonstColorF[2] = fVar3;
          pJVar13->mBlendKonstColorF[3] = fVar3;
          J2DPicture::setBlendKonstColor(pJVar13);
          pJVar13->mBlendKonstAlphaF[0] = _4185;
          fVar3 = _5863;
          pJVar13->mBlendKonstAlphaF[1] = _5863;
          pJVar13->mBlendKonstAlphaF[2] = fVar3;
          pJVar13->mBlendKonstAlphaF[3] = fVar3;
          J2DPicture::setBlendKonstAlpha(pJVar13);
        }
      }
      local_28 = (double)CONCAT44(0x43300000,*(byte *)(param_1 + 0xfa) * uVar1 ^ 0x80000000);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(param_1 + 0x1fc),(double)_4185,
                 (double)(float)(local_28 - _4188));
      local_30 = (double)CONCAT44(0x43300000,*(byte *)(param_1 + 0xfa) * uVar1 ^ 0x80000000);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(param_1 + 0x234),(double)_4185,
                 (double)(float)(local_30 - _4188));
    }
    else {
      if (sVar2 == 0x14) {
        iVar9 = 0;
        iVar10 = 0;
        iVar12 = 0;
        iVar4 = 0;
        iVar11 = 0;
        iVar14 = 8;
        do {
          cVar5 = *(char *)(param_1 + iVar4 + 0x1085);
          if (cVar5 == '\x14') {
            local_28 = (double)CONCAT44(0x43300000,*(uint *)(param_1 + iVar11 + 0xf6c) ^ 0x80000000)
            ;
            iVar9 = (int)(*(float *)(iVar7 + 0xc) + (float)(local_28 - _4188));
            local_38 = (double)CONCAT44(0x43300000,
                                        *(int *)(param_1 + 0x1104) *
                                        ((2 - *(int *)(param_1 + 0x1108)) +
                                        *(int *)(param_1 + iVar11 + 0xfa8) * 2) ^ 0x80000000);
            iVar10 = (int)(*(float *)(iVar7 + 0x10) + (float)(local_38 - _4188));
          }
          else {
            if (cVar5 == '\x15') {
              local_20 = (double)CONCAT44(0x43300000,
                                          *(uint *)(param_1 + iVar11 + 0xf6c) ^ 0x80000000);
              iVar12 = (int)(*(float *)(iVar7 + 0xc) + (float)(local_20 - _4188));
            }
          }
          iVar4 = iVar4 + 1;
          iVar11 = iVar11 + 4;
          iVar14 = iVar14 + -1;
        } while (iVar14 != 0);
        uVar6 = fopMsgM_msgDataProc_c::selectCheckYoko
                          ((fopMsgM_msgDataProc_c *)(param_1 + 0xe04),arrowPane,iVar9,iVar10,
                           iVar12 - iVar9);
        *(undefined *)(param_1 + 0xfa) = uVar6;
      }
    }
  }
  if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
     (((-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 ||
       (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction != 0x27)) &&
      (cVar5 = f_op_msg_mng::fopMsgM_checkMessageSend(), cVar5 == '\0')))) {
    return 1;
  }
  if ((*(short *)(param_1 + 0xf8) == 8) || (*(short *)(param_1 + 0xf8) == 9)) {
    *(undefined2 *)(param_1 + 0x2a2) = 3;
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x1fc));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x234));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x11c));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x154));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x18c));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x1c4));
  }
  else {
    *(undefined2 *)(param_1 + 0x2a2) = 0;
  }
  *(undefined4 *)(param_1 + 0x1100) = 0;
  *(undefined2 *)(param_1 + 0x49a) = 0;
  if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
    *(undefined *)(param_1 + 0x1169) = 1;
    d_com_inf_game::g_dComIfG_gameInfo._23529_1_ = 1;
  }
  else {
    *(undefined *)(param_1 + 0x1169) = 0;
  }
  if (*(short *)(param_1 + 0x108) == 1) {
    if (*(char *)(param_1 + 0xfa) == '\0') {
      uVar8 = 1;
    }
    else {
      uVar8 = 0;
    }
  }
  else {
    if (*(short *)(param_1 + 0x108) == 2) {
      uVar8 = 0;
    }
    else {
      if (((*(short *)(param_1 + 0xf8) == 8) && (*(char *)(param_1 + 0xfa) == '\x01')) ||
         ((*(short *)(param_1 + 0xf8) == 9 && (*(char *)(param_1 + 0xfa) == '\x02')))) {
        uVar8 = 1;
      }
      else {
        uVar8 = 0;
      }
    }
  }
  dMsg_setCloseSound(param_1,uVar8);
  *(undefined2 *)(param_1 + 0xf8) = 0xe;
  *(char *)(param_1 + 0x116a) = *(char *)(param_1 + 0x116a) + '\x01';
  d_com_inf_game::g_dComIfG_gameInfo._23528_1_ = *(undefined *)(param_1 + 0x116a);
  return 1;
}


/* __stdcall dMsg_inputProc(sub_msg_class *) */

undefined4 dMsg_inputProc(int param_1)

{
  char cVar1;
  
  if (*(char *)(param_1 + 0x10c) == '\x0e') {
    cVar1 = f_op_msg_mng::fopMsgM_tactMsgFlagCheck();
    if (cVar1 == '\0') {
      dMsg_tactInput(param_1);
    }
    else {
      dMsg_tactInput2(param_1);
    }
  }
  else {
    dMsg_numberInput();
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x80212da0) */
/* __stdcall dMsg_demoProc(sub_msg_class *) */

undefined4 dMsg_demoProc(int param_1)

{
  float alpha;
  char cVar2;
  int iVar1;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  double dVar10;
  undefined8 in_f31;
  long lStack104;
  float local_64 [7];
  longlong local_48;
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (*(char *)(param_1 + 0x116b) == '\0') {
    uVar8 = (uint)d_com_inf_game::g_dComIfG_gameInfo._23536_1_;
    if (init_7050 == '\0') {
      flag_7049 = '\0';
      init_7050 = '\x01';
    }
    if (init_7053 == '\0') {
      cnt_7052 = 0;
      init_7053 = '\x01';
    }
    local_64[0] = _4185;
    iVar4 = 0;
    for (iVar6 = 0; iVar6 < (int)(uint)(byte)(&mBeatNum)[uVar8]; iVar6 = iVar6 + 1) {
      dVar10 = (double)JAIZelInst::getMelodyPattern
                                 (&mDoAud_zelAudio_c::mTact,uVar8,iVar6,&lStack104);
      *(float *)((int)local_64 + iVar4 + 4) = (float)dVar10;
      *(float *)((int)local_64 + iVar4 + 4) =
           *(float *)((int)local_64 + iVar4 + 4) + *(float *)((int)local_64 + iVar4);
      iVar4 = iVar4 + 4;
    }
    if (*(int *)(param_1 + 0x1100) == 0) {
      cnt_7052 = 0;
      JAIZelInst::melodyPlay(&mDoAud_zelAudio_c::mTact,uVar8);
    }
    iVar4 = (int)local_64[(byte)(&mBeatNum)[uVar8]];
    local_48 = (longlong)iVar4;
    if (*(int *)(param_1 + 0x1100) < (int)(short)iVar4) {
      *(int *)(param_1 + 0x1100) = *(int *)(param_1 + 0x1100) + 1;
      iVar4 = (int)local_64[cnt_7052];
      local_48 = (longlong)iVar4;
      if ((int)(short)iVar4 <= *(int *)(param_1 + 0x1100)) {
        *(undefined2 *)(param_1 + cnt_7052 * 0x38 + 0xb9a) = 1;
        cnt_7052 = cnt_7052 + 1;
      }
    }
    iVar4 = 0;
    for (iVar6 = 0; iVar6 < (int)(uint)(byte)(&mBeatNum)[uVar8]; iVar6 = iVar6 + 1) {
      iVar5 = param_1 + iVar4;
      iVar3 = (int)*(short *)(iVar5 + 0xb9a);
      if ((0 < *(short *)(iVar5 + 0xb9a)) && (iVar3 < 0x24)) {
        if (iVar3 < 5) {
          dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,iVar3,0);
          alpha = (float)((double)_4289 + (double)(float)((double)_4289 * dVar10));
          dVar10 = (double)alpha;
          if (d_com_inf_game::g_dComIfG_gameInfo._23536_1_ < 5) {
            f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar5 + 0xa14),alpha);
            f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar5 + 0xb64),(float)dVar10);
          }
          else {
            f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar5 + 0xa14),alpha);
            f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar5 + 0x8c4),(float)dVar10);
            f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar5 + 0xcb4),(float)dVar10);
          }
        }
        else {
          f_op_msg_mng::fopMsgM_setInitAlpha(iVar5 + 0xa14);
          f_op_msg_mng::fopMsgM_setInitAlpha(iVar5 + 0xb64);
          if (4 < d_com_inf_game::g_dComIfG_gameInfo._23536_1_) {
            f_op_msg_mng::fopMsgM_setInitAlpha(iVar5 + 0xcb4);
          }
        }
        *(short *)(iVar5 + 0xb9a) = *(short *)(iVar5 + 0xb9a) + 1;
        if (0x23 < *(short *)(param_1 + (uint)(byte)(&mBeatNum)[uVar8] * 0x38 + 0xb62)) {
          if (flag_7049 == '\0') {
            flag_7049 = '\x01';
          }
          else {
            dMsg_messagePaneShow(param_1);
            dMsg_yose_select(param_1);
            if (*(char *)(param_1 + 0x111) != '\0') {
              cVar2 = d_com_inf_game::dComIfGp_getReverb((int)(char)dStage_roomControl_c::mStayNo);
              JAIZelBasic::messageSePlay
                        (JAIZelBasic::zel_basic,(ushort)*(byte *)(param_1 + 0x111),(Vec *)0x0,cVar2)
              ;
            }
            *(undefined *)(param_1 + 0x109d) = 1;
            fopMsgM_msgDataProc_c::stringSet((fopMsgM_msgDataProc_c *)(param_1 + 0xe04));
            iVar7 = 0;
            iVar5 = 0;
            iVar3 = 0;
            do {
              cVar2 = *(char *)(param_1 + iVar7 + 0x1085);
              iVar1 = *(int *)(param_1 + iVar3 + 0x1024);
              if (((((byte)(cVar2 - 10U) < 4) || (cVar2 == '\x15')) || (cVar2 == '\x17')) &&
                 (iVar1 == 0)) {
                iVar1 = -1;
              }
              if (((cVar2 != -1) && (*(short *)((int)&buttonTimer + iVar5) == -1)) &&
                 ((cVar2 != '\x14' && ((cVar2 != '\x15' && (cVar2 != '\x16')))))) {
                f_op_msg_mng::fopMsgM_outFontSet
                          (*(undefined4 *)((int)&button_icon + iVar3),
                           *(undefined4 *)((int)&button_kage + iVar3),
                           (short *)((int)&buttonTimer + iVar5),iVar1);
              }
              iVar7 = iVar7 + 1;
              iVar5 = iVar5 + 2;
              iVar3 = iVar3 + 4;
            } while (iVar7 < 8);
            dMsg_setString(param_1);
            f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x544));
            f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x57c));
            f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x5b4));
            f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x5ec));
            *(undefined *)(param_1 + 0x116b) = 1;
            flag_7049 = '\0';
          }
          *(undefined4 *)(param_1 + 0x1100) = 0;
          iVar5 = 0;
          for (iVar3 = 0; iVar3 < (int)(uint)(byte)(&mBeatNum)[uVar8]; iVar3 = iVar3 + 1) {
            iVar7 = param_1 + iVar5;
            *(undefined2 *)(iVar7 + 0xb9a) = 0;
            if (d_com_inf_game::g_dComIfG_gameInfo._23536_1_ < 5) {
              f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar7 + 0xa14),_4289);
              f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar7 + 0xb64));
            }
            else {
              f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar7 + 0xa14),_4289);
              f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar7 + 0x8c4),_4289);
              f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar7 + 0xcb4),_4289);
            }
            iVar5 = iVar5 + 0x38;
          }
        }
      }
      iVar4 = iVar4 + 0x38;
    }
  }
  else {
    dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,*(char *)(param_1 + 0x116b),0);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x544),(float)dVar10);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x57c),(float)dVar10);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x5b4),(float)dVar10);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x5ec),(float)dVar10);
    if (*(byte *)(param_1 + 0x116b) < 5) {
      *(byte *)(param_1 + 0x116b) = *(byte *)(param_1 + 0x116b) + 1;
    }
    else {
      *(undefined2 *)(param_1 + 0xf8) = 0x15;
    }
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dMsg_continueProc(sub_msg_class *) */

undefined4 dMsg_continueProc(int param_1)

{
  int iVar1;
  int iVar2;
  double dVar3;
  float fVar4;
  float fVar5;
  char cVar8;
  undefined4 uVar6;
  ulong uVar7;
  undefined4 local_8c;
  undefined2 local_88;
  undefined2 local_86;
  undefined2 local_84;
  undefined2 local_82;
  undefined local_80;
  undefined local_7f;
  undefined local_7e;
  undefined local_7d;
  undefined local_7c;
  undefined local_7b;
  undefined local_7a;
  undefined local_79;
  undefined local_78;
  undefined local_77;
  undefined local_76;
  undefined local_75;
  double local_70;
  double local_68;
  undefined4 local_60;
  uint uStack92;
  double local_58;
  double local_50;
  undefined4 local_48;
  uint uStack68;
  undefined4 local_40;
  uint uStack60;
  undefined4 local_38;
  uint uStack52;
  longlong local_30;
  longlong local_28;
  
  iVar1 = (int)*(float *)(*(int *)(param_1 + 0x544) + 0xe0);
  local_70 = (double)(longlong)iVar1;
  iVar2 = (int)*(float *)(*(int *)(param_1 + 0x57c) + 0xe0);
  local_68 = (double)(longlong)iVar2;
  if ((((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
        (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3)) &&
       (*(char *)(param_1 + 0x1098) == '\0')) &&
      ((cVar8 = f_op_msg_mng::fopMsgM_checkMessageSend(), cVar8 == '\0' &&
       ((*(int *)(param_1 + 0xec) != 0x5ac || (d_com_inf_game::g_dComIfG_gameInfo._23529_1_ == '\0')
        ))))) || (d_com_inf_game::g_dComIfG_gameInfo._23575_1_ != '\0')) {
    if ((*(char *)(param_1 + 0x10c) != '\x05') && (*(char *)(param_1 + 0x10c) != '\x0e')) {
      dMsg_arrowMove(param_1);
    }
    d_meter::dMeter_Info = 1;
  }
  else {
    *(undefined *)(param_1 + 0x1098) = 0;
    *(undefined4 *)(param_1 + 0x1100) = 0;
    JKRFileLoader::removeResource(*(void **)(param_1 + 0x118),(JKRFileLoader *)0x0);
    if ((*(char *)(param_1 + 0x10c) != '\x05') && (*(char *)(param_1 + 0x10c) != '\x0e')) {
      dMsg_arrowInit(param_1);
    }
    if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
      *(undefined *)(param_1 + 0x1169) = 1;
      d_com_inf_game::g_dComIfG_gameInfo._23529_1_ = '\x01';
    }
    if (*(char *)(param_1 + 0x1169) != '\0') {
      *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 0xf0);
      *(undefined *)(param_1 + 0x1169) = 0;
    }
    uVar6 = fopMsgM_msgGet_c::getMesgHeader
                      ((fopMsgM_msgGet_c *)(param_1 + 0x10a4),*(ulong *)(param_1 + 0xec));
    *(undefined4 *)(param_1 + 0x118) = uVar6;
    if (*(int *)(param_1 + 0x118) == 0) {
      uVar7 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar7,"d_msg.cpp",0xfa2,"i_Msg->head_p");
      m_Do_printf::OSPanic("d_msg.cpp",0xfa2,&DAT_80361ec0);
    }
    uVar6 = fopMsgM_msgGet_c::getMessage
                      ((fopMsgM_msgGet_c *)(param_1 + 0x10a4),*(mesg_header **)(param_1 + 0x118));
    *(undefined4 *)(param_1 + 0x111c) = uVar6;
    fopMsgM_msgGet_c::getMesgEntry((fopMsgM_msgGet_c *)&local_8c,(mesg_header *)(param_1 + 0x10a4));
    *(undefined4 *)(param_1 + 0x100) = local_8c;
    *(undefined2 *)(param_1 + 0x104) = local_88;
    *(undefined2 *)(param_1 + 0x106) = local_86;
    *(undefined2 *)(param_1 + 0x108) = local_84;
    *(undefined2 *)(param_1 + 0x10a) = local_82;
    *(undefined *)(param_1 + 0x10c) = local_80;
    *(undefined *)(param_1 + 0x10d) = local_7f;
    *(undefined *)(param_1 + 0x10e) = local_7e;
    *(undefined *)(param_1 + 0x10f) = local_7d;
    *(undefined *)(param_1 + 0x110) = local_7c;
    *(undefined *)(param_1 + 0x111) = local_7b;
    *(undefined *)(param_1 + 0x112) = local_7a;
    *(undefined *)(param_1 + 0x113) = local_79;
    *(undefined *)(param_1 + 0x114) = local_78;
    *(undefined *)(param_1 + 0x115) = local_77;
    *(undefined *)(param_1 + 0x116) = local_76;
    *(undefined *)(param_1 + 0x117) = local_75;
    *(uint *)(param_1 + 0x1140) =
         (uint)*(ushort *)(param_1 + 0x10ac) << 8 | (uint)*(ushort *)(param_1 + 0x10b0);
    *(undefined *)(param_1 + 0x116a) = 0;
    *(undefined4 *)(param_1 + 0x1164) = 0xffffffff;
    dMsg_value_init(param_1);
    fopMsgM_msgDataProc_c::dataInit((fopMsgM_msgDataProc_c *)(param_1 + 0xe04));
    *(undefined4 *)(param_1 + 0x1060) = *(undefined4 *)(param_1 + 0x1164);
    *(undefined4 *)(param_1 + 0xe40) = *(undefined4 *)(param_1 + 0x111c);
    *(undefined4 *)(param_1 + 0xe64) = *(undefined4 *)(param_1 + 0x1120);
    *(undefined4 *)(param_1 + 0xe44) = *(undefined4 *)(param_1 + 0x1120);
    *(undefined4 *)(param_1 + 0xe68) = *(undefined4 *)(param_1 + 0x1124);
    *(undefined4 *)(param_1 + 0xe48) = *(undefined4 *)(param_1 + 0x1124);
    *(undefined4 *)(param_1 + 0xe6c) = *(undefined4 *)(param_1 + 0x1128);
    *(undefined4 *)(param_1 + 0xe4c) = *(undefined4 *)(param_1 + 0x1128);
    *(undefined4 *)(param_1 + 0xe70) = *(undefined4 *)(param_1 + 0x112c);
    *(undefined4 *)(param_1 + 0xe50) = *(undefined4 *)(param_1 + 0x112c);
    *(undefined4 *)(param_1 + 0xe54) = *(undefined4 *)(param_1 + 0x1130);
    *(undefined4 *)(param_1 + 0xe58) = *(undefined4 *)(param_1 + 0x1134);
    *(undefined4 *)(param_1 + 0xe5c) = *(undefined4 *)(param_1 + 0x1138);
    *(undefined4 *)(param_1 + 0xe60) = *(undefined4 *)(param_1 + 0x113c);
    *(undefined4 *)(param_1 + 0xe08) = textFont;
    *(undefined4 *)(param_1 + 0xe0c) = rubyFont;
    *(int *)(param_1 + 0xf20) = iVar1;
    *(int *)(param_1 + 0xf28) = iVar2;
    *(int *)(param_1 + 0xe10) = param_1 + 0x100;
    *(undefined4 *)(param_1 + 0xf48) = *(undefined4 *)(param_1 + 0x110c);
    *(undefined4 *)(param_1 + 0xf50) = *(undefined4 *)(param_1 + 0x1110);
    if ((*(char *)(param_1 + 0x10c) == '\t') && (*(short *)(param_1 + 0x81a) == 0)) {
      *(undefined4 *)(param_1 + 0xf2c) = 0x1a3;
      *(undefined4 *)(param_1 + 0xf30) = 0x192;
    }
    else {
      *(undefined4 *)(param_1 + 0xf2c) = 0x1f7;
      *(undefined4 *)(param_1 + 0xf30) = 0x1e6;
    }
    *(uint *)(param_1 + 0xf64) = (uint)DAT_803e6bc6;
    *(undefined4 *)(param_1 + 0xf60) = 2;
    if (DAT_803e6bc7 == '\0') {
      *(undefined *)(param_1 + 0x10a0) = 0;
    }
    else {
      *(undefined *)(param_1 + 0x10a0) = 1;
    }
    dMsg_yose_select(param_1);
    if (*(char *)(param_1 + 0x111) != '\0') {
      cVar8 = d_com_inf_game::dComIfGp_getReverb((int)(char)dStage_roomControl_c::mStayNo);
      JAIZelBasic::messageSePlay
                (JAIZelBasic::zel_basic,(ushort)*(byte *)(param_1 + 0x111),(Vec *)0x0,cVar8);
    }
    dMsg_setString(param_1);
    d_meter::dMeter_Info = 2;
    if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 == 0x27) {
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x880,(cXyz *)0x0,0,0,_5863,_5863,_6707,_6707,0);
    }
    else {
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x80b,(cXyz *)0x0,0,0,_5863,_5863,_6707,_6707,0);
    }
    *(char *)(param_1 + 0x116a) = *(char *)(param_1 + 0x116a) + '\x01';
    d_com_inf_game::g_dComIfG_gameInfo._23528_1_ = *(undefined *)(param_1 + 0x116a);
    d_com_inf_game::g_dComIfG_gameInfo._23529_1_ = '\0';
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bdb = *(byte *)(param_1 + 0x113);
    d_com_inf_game::g_dComIfG_gameInfo._23588_4_ = (uint)*(byte *)(param_1 + 0x112);
    d_com_inf_game::g_dComIfG_gameInfo._23484_2_ = *(undefined2 *)(param_1 + 0x106);
    if (((((d_com_inf_game::g_dComIfG_gameInfo._23588_4_ == 1) ||
          (d_com_inf_game::g_dComIfG_gameInfo._23588_4_ == 2)) ||
         (d_com_inf_game::g_dComIfG_gameInfo._23588_4_ == 3)) ||
        ((d_com_inf_game::g_dComIfG_gameInfo._23588_4_ == 4 ||
         (d_com_inf_game::g_dComIfG_gameInfo._23588_4_ == 5)))) &&
       (*(fopAc_ac_c **)
         (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems +
         d_com_inf_game::g_dComIfG_gameInfo._23588_4_ * 4 + 0x51) != (fopAc_ac_c *)0x0)) {
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mPtTalk =
           dEvt_control_c::getPId
                     (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,
                      *(fopAc_ac_c **)
                       (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems +
                       d_com_inf_game::g_dComIfG_gameInfo._23588_4_ * 4 + 0x51));
    }
    if (*(char *)(param_1 + 0x10c) == '\x01') {
      dMsg_msg_pane_parts_set(param_1 + 0x49c,1);
      fVar4 = _5685;
      if (*(char *)(param_1 + 0x10e) != '\x01') {
        *(float *)(param_1 + 0x4bc) = *(float *)(param_1 + 0x4bc) + _5685;
        *(float *)(param_1 + 0x4ac) = *(float *)(param_1 + 0x4ac) + fVar4;
      }
      dMsg_arw_pane_parts_set(param_1 + 0x4d4,param_1 + 0x49c);
      dMsg_arw_pane_parts_set(param_1 + 0x50c,param_1 + 0x49c);
      iVar1 = (int)(*(float *)(param_1 + 0x4e4) + *(float *)(param_1 + 0x4fc));
      local_68 = (double)(longlong)iVar1;
      *(int *)(param_1 + 0x1114) = iVar1;
      local_70 = (double)(longlong)(int)*(float *)(param_1 + 0x548);
      uStack92 = (int)*(float *)(param_1 + 0x548) ^ 0x80000000;
      local_60 = 0x43300000;
      dVar3 = (double)CONCAT44(0x43300000,uStack92) - _4188;
      fVar4 = (float)dVar3;
      local_50 = (double)CONCAT44(0x43300000,
                                  (int)(_4287 - (*(float *)(param_1 + 0x54c) +
                                                *(float *)(param_1 + 0x56c))) - 0x13U ^ 0x80000000);
      local_50 = local_50 - _4188;
      fVar5 = (float)local_50;
      if (*(char *)(param_1 + 0x10e) == '\x01') {
        *(int *)(param_1 + 0x10f8) = (int)dVar3;
        *(int *)(param_1 + 0x10fc) = (int)local_50;
      }
      else {
        *(int *)(param_1 + 0x10f8) = (int)dVar3;
        *(int *)(param_1 + 0x10fc) = (int)(_5685 + fVar5);
      }
      local_50 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba6 ^ 0x80000000);
      local_58 = (double)CONCAT44(0x43300000,(int)textOffsetY ^ 0x80000000);
      (**(code **)(**(int **)(param_1 + 0x544) + 0x10))
                ((double)fVar4,
                 (double)((fVar5 - (float)(local_50 - _4188)) - (float)(local_58 - _4188)));
      uStack92 = (int)DAT_803e6ba4 ^ 0x80000000;
      local_60 = 0x43300000;
      local_68 = (double)CONCAT44(0x43300000,(int)textOffsetY ^ 0x80000000);
      (**(code **)(**(int **)(param_1 + 0x57c) + 0x10))
                ((double)fVar4,
                 (double)((fVar5 - (float)((double)CONCAT44(0x43300000,uStack92) - _4188)) -
                         (float)(local_68 - _4188)));
      local_70 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba6 ^ 0x80000000);
      uStack68 = (int)textOffsetY ^ 0x80000000;
      local_48 = 0x43300000;
      (**(code **)(**(int **)(param_1 + 0x5b4) + 0x10))
                ((double)(_4186 + fVar4),
                 (double)(_4186 + ((fVar5 - (float)(local_70 - _4188)) -
                                  (float)((double)CONCAT44(0x43300000,uStack68) - _4188))));
      uStack60 = (int)DAT_803e6ba4 ^ 0x80000000;
      local_40 = 0x43300000;
      uStack52 = (int)textOffsetY ^ 0x80000000;
      local_38 = 0x43300000;
      (**(code **)(**(int **)(param_1 + 0x5ec) + 0x10))
                ((double)(_4186 + fVar4),
                 (double)(_4186 + ((fVar5 - (float)((double)CONCAT44(0x43300000,uStack60) - _4188))
                                  - (float)((double)CONCAT44(0x43300000,uStack52) - _4188))));
      local_30 = (longlong)(int)*(float *)(param_1 + 0x4b8);
      *(int *)(param_1 + 0x10d8) = (int)*(float *)(param_1 + 0x4b8);
      local_28 = (longlong)(int)*(float *)(param_1 + 0x4bc);
      *(int *)(param_1 + 0x10dc) = (int)*(float *)(param_1 + 0x4bc);
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_1 + 0x49c));
    }
    else {
      if (*(char *)(param_1 + 0x10c) != '\x0e') {
        dMsg_mesgOutPos(param_1);
        *(int *)(param_1 + 0x10d8) = (int)*(float *)(param_1 + 0x4b8);
        *(int *)(param_1 + 0x10dc) = (int)*(float *)(param_1 + 0x4bc);
      }
    }
    if (((*(char *)(param_1 + 0x10d) == '\0') &&
        ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0')) &&
       (d_com_inf_game::g_dComIfG_gameInfo._23575_1_ == '\0')) {
      if (*(char *)(param_1 + 0x109a) == '\0') {
        *(undefined *)(param_1 + 0x109d) = 1;
      }
      if (((*(char *)(param_1 + 0x109b) == '\0') && (*(char *)(param_1 + 0x109c) == '\0')) &&
         (*(int *)(param_1 + 0xf5c) != 0)) {
        *(undefined4 *)(param_1 + 0xf5c) = 0;
        *(undefined *)(param_1 + 0x109a) = 0;
      }
    }
    *(undefined2 *)(param_1 + 0xf8) = 6;
  }
  return 1;
}


/* __stdcall dMsg_closewaitProc(sub_msg_class *) */

undefined4 dMsg_closewaitProc(int param_1)

{
  char cVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 0x109b) == '\0') {
    if (*(char *)(param_1 + 0x109c) != '\0') {
      uVar2 = *(uint *)(param_1 + 0xf5c);
      uVar2 = uVar2 - 1 & (int)(-uVar2 & ~uVar2) >> 0x1f;
      *(uint *)(param_1 + 0xf5c) = uVar2;
      if (uVar2 == 0) {
        *(undefined *)(param_1 + 0x109c) = 0;
        *(undefined2 *)(param_1 + 0xf8) = 0x11;
        if ((*(char *)(param_1 + 0x10c) != '\x05') && (*(char *)(param_1 + 0x10c) != '\x0e')) {
          f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x50c));
        }
        *(undefined4 *)(param_1 + 0x1100) = 0;
        d_meter::dMeter_Info = 0;
        *(char *)(param_1 + 0x116a) = *(char *)(param_1 + 0x116a) + '\x01';
        d_com_inf_game::g_dComIfG_gameInfo._23528_1_ = *(undefined *)(param_1 + 0x116a);
      }
      else {
        if (((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
             (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3)) &&
            (cVar1 = f_op_msg_mng::fopMsgM_checkMessageSend(), cVar1 == '\0')) ||
           (d_com_inf_game::g_dComIfG_gameInfo._23575_1_ != '\0')) {
          if ((*(char *)(param_1 + 0x10c) != '\x05') && (*(char *)(param_1 + 0x10c) != '\x0e')) {
            dMsg_dotMove(param_1);
          }
          d_meter::dMeter_Info = 4;
        }
        else {
          *(undefined *)(param_1 + 0x109c) = 0;
          *(undefined2 *)(param_1 + 0xf8) = 0x11;
          if ((*(char *)(param_1 + 0x10c) != '\x05') && (*(char *)(param_1 + 0x10c) != '\x0e')) {
            f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x50c));
          }
          *(undefined4 *)(param_1 + 0x1100) = 0;
          d_meter::dMeter_Info = 0;
          *(char *)(param_1 + 0x116a) = *(char *)(param_1 + 0x116a) + '\x01';
          d_com_inf_game::g_dComIfG_gameInfo._23528_1_ = *(undefined *)(param_1 + 0x116a);
        }
      }
    }
  }
  else {
    uVar2 = *(uint *)(param_1 + 0xf5c);
    uVar2 = uVar2 - 1 & (int)(-uVar2 & ~uVar2) >> 0x1f;
    *(uint *)(param_1 + 0xf5c) = uVar2;
    if ((uVar2 == 0) || (cVar1 = f_op_msg_mng::fopMsgM_checkMessageSend(), cVar1 != '\0')) {
      *(undefined *)(param_1 + 0x109b) = 0;
      *(undefined *)(param_1 + 0x109a) = 0;
      *(undefined2 *)(param_1 + 0xf8) = 0x11;
      *(undefined4 *)(param_1 + 0x1100) = 0;
      *(undefined4 *)(param_1 + 0xf5c) = 0;
      *(char *)(param_1 + 0x116a) = *(char *)(param_1 + 0x116a) + '\x01';
      d_com_inf_game::g_dComIfG_gameInfo._23528_1_ = *(undefined *)(param_1 + 0x116a);
    }
  }
  return 1;
}


/* __stdcall dMsg_finishProc(sub_msg_class *) */

undefined4 dMsg_finishProc(int param_1)

{
  char cVar1;
  
  if (((((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
         (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3)) &&
        (*(char *)(param_1 + 0x1098) == '\0')) &&
       (cVar1 = f_op_msg_mng::fopMsgM_checkMessageSend(), cVar1 == '\0')) &&
      ((*(int *)(param_1 + 0xec) != 0x5ac || (d_com_inf_game::g_dComIfG_gameInfo._23529_1_ == '\0'))
      )) || (d_com_inf_game::g_dComIfG_gameInfo._23575_1_ != '\0')) {
    if ((*(char *)(param_1 + 0x10c) != '\x05') && (*(char *)(param_1 + 0x10c) != '\x0e')) {
      dMsg_dotMove(param_1);
    }
    d_meter::dMeter_Info = 4;
  }
  else {
    *(undefined *)(param_1 + 0x1098) = 0;
    *(undefined2 *)(param_1 + 0xf8) = 0x11;
    if ((*(char *)(param_1 + 0x10c) != '\x05') && (*(char *)(param_1 + 0x10c) != '\x0e')) {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x50c));
    }
    *(undefined4 *)(param_1 + 0x1100) = 0;
    d_meter::dMeter_Info = 0;
    *(char *)(param_1 + 0x116a) = *(char *)(param_1 + 0x116a) + '\x01';
    d_com_inf_game::g_dComIfG_gameInfo._23528_1_ = *(undefined *)(param_1 + 0x116a);
    if (*(int *)(param_1 + 0xec) == 0x1072) {
      JAIZelBasic::bgmStop(JAIZelBasic::zel_basic,0x3c,0);
    }
  }
  return 1;
}


/* __stdcall dMsg_openTalkProc(sub_msg_class *) */

undefined4 dMsg_openTalkProc(int param_1)

{
  char cVar1;
  
  if (*(int *)(param_1 + 0x1100) == 0xd) {
    *(undefined2 *)(param_1 + 0xf8) = 6;
    dMsg_messagePaneShow();
    dMsg_yose_select(param_1);
    if (*(char *)(param_1 + 0x111) != '\0') {
      cVar1 = d_com_inf_game::dComIfGp_getReverb((int)(char)dStage_roomControl_c::mStayNo);
      JAIZelBasic::messageSePlay
                (JAIZelBasic::zel_basic,(ushort)*(byte *)(param_1 + 0x111),(Vec *)0x0,cVar1);
    }
    dMsg_setString(param_1);
    d_meter::dMeter_Info = 2;
  }
  else {
    dMsg_frame_openTalk();
  }
  return 1;
}


/* __stdcall dMsg_openItemProc(sub_msg_class *) */

undefined4 dMsg_openItemProc(int param_1)

{
  int iVar1;
  char cVar3;
  JPABaseEmitter *pJVar2;
  cXyz local_28;
  cXyz local_1c;
  
  if (*(int *)(param_1 + 0x1100) == 8) {
    *(undefined2 *)(param_1 + 0xf8) = 6;
    dMsg_messagePaneShow();
    dMsg_yose_select(param_1);
    if (*(char *)(param_1 + 0x111) != '\0') {
      cVar3 = d_com_inf_game::dComIfGp_getReverb((int)(char)dStage_roomControl_c::mStayNo);
      JAIZelBasic::messageSePlay
                (JAIZelBasic::zel_basic,(ushort)*(byte *)(param_1 + 0x111),(Vec *)0x0,cVar3);
    }
    dMsg_setString(param_1);
    iVar1 = *(int *)(param_1 + 0xec);
    if ((iVar1 == 0x74) || (iVar1 == 0xbe)) {
      local_1c.y = (*(float *)(param_1 + 0x814) * _4289 +
                   *(float *)(*(int *)(param_1 + 0x7e4) + 0x20)) - _4288;
      local_1c.x = (*(float *)(param_1 + 0x810) * _4289 +
                   *(float *)(*(int *)(param_1 + 0x7e4) + 0x1c)) - _7566;
      local_1c.z = _4185;
      pJVar2 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,7,0x2d,
                                  &local_1c,(csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,
                                  -1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
      *(JPABaseEmitter **)(param_1 + 0x10b4) = pJVar2;
      if (*(int *)(param_1 + 0xec) == 0xbe) {
        pJVar2 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,7,0x2d,
                                    &local_1c,(csXyz *)0x0,(cXyz *)0x0,0xff,
                                    (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                                    (cXyz *)0x0);
        *(JPABaseEmitter **)(param_1 + 0x10b8) = pJVar2;
      }
    }
    else {
      if (iVar1 == 0x9a) {
        local_28.y = ((*(float *)(param_1 + 0x814) * _4289 +
                      *(float *)(*(int *)(param_1 + 0x7e4) + 0x20)) - _4288) - _5865;
        local_28.x = _5865 + ((*(float *)(param_1 + 0x810) * _4289 +
                              *(float *)(*(int *)(param_1 + 0x7e4) + 0x1c)) - _7566);
        local_28.z = _4185;
        pJVar2 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,7,0x2e1,
                                    &local_28,(csXyz *)0x0,(cXyz *)0x0,0xff,
                                    (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                                    (cXyz *)0x0);
        *(JPABaseEmitter **)(param_1 + 0x10b4) = pJVar2;
      }
    }
    d_meter::dMeter_Info = 2;
  }
  else {
    dMsg_frame_openItem();
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dMsg_openTactProc(sub_msg_class *) */

undefined4 dMsg_openTactProc(int param_1)

{
  int iVar1;
  uint uVar2;
  char cVar4;
  int iVar3;
  int iVar5;
  int iVar6;
  
  iVar1 = *(int *)(param_1 + 0xec);
  if (iVar1 == 0x5ac) {
    *(undefined2 *)(param_1 + 0xf8) = 0x15;
  }
  else {
    if ((iVar1 == 0x5b3) || (iVar1 == 0x5b4)) {
      uVar2 = (uint)d_com_inf_game::g_dComIfG_gameInfo._23536_1_;
      if ((uVar2 == 1) || (uVar2 == 5)) {
        dMsg_tactGuideShow(param_1,(&mBeatNum)[uVar2]);
        dMsg_messageShow(param_1);
        *(undefined2 *)(param_1 + 0xf8) = 0x15;
        *(undefined *)(param_1 + 0x1168) = DAT_803a2caf;
        return 1;
      }
      dMsg_tactGuideShow(param_1,(&mBeatNum)[uVar2]);
      *(undefined2 *)(param_1 + 0xf8) = 0x17;
      *(undefined *)(param_1 + 0x116b) = 0;
    }
    else {
      *(undefined2 *)(param_1 + 0xf8) = 0x16;
    }
  }
  f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(param_1 + 0x49c),_5863);
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x49c);
  if (*(short *)(param_1 + 0xf8) != 0x17) {
    dMsg_messagePaneShow(param_1);
    dMsg_yose_select(param_1);
    if (*(char *)(param_1 + 0x111) != '\0') {
      cVar4 = d_com_inf_game::dComIfGp_getReverb((int)(char)dStage_roomControl_c::mStayNo);
      JAIZelBasic::messageSePlay
                (JAIZelBasic::zel_basic,(ushort)*(byte *)(param_1 + 0x111),(Vec *)0x0,cVar4);
    }
    *(undefined *)(param_1 + 0x109d) = 1;
    fopMsgM_msgDataProc_c::stringSet((fopMsgM_msgDataProc_c *)(param_1 + 0xe04));
    iVar1 = 0;
    iVar6 = 0;
    iVar5 = 0;
    do {
      cVar4 = *(char *)(param_1 + iVar1 + 0x1085);
      iVar3 = *(int *)(param_1 + iVar5 + 0x1024);
      if (((((byte)(cVar4 - 10U) < 4) || (cVar4 == '\x15')) || (cVar4 == '\x17')) && (iVar3 == 0)) {
        iVar3 = -1;
      }
      if (((cVar4 != -1) && (*(short *)((int)&buttonTimer + iVar6) == -1)) &&
         ((cVar4 != '\x14' && ((cVar4 != '\x15' && (cVar4 != '\x16')))))) {
        f_op_msg_mng::fopMsgM_outFontSet
                  (*(undefined4 *)((int)&button_icon + iVar5),
                   *(undefined4 *)((int)&button_kage + iVar5),(short *)((int)&buttonTimer + iVar6),
                   iVar3);
      }
      iVar1 = iVar1 + 1;
      iVar6 = iVar6 + 2;
      iVar5 = iVar5 + 4;
    } while (iVar1 < 8);
    dMsg_setString(param_1);
  }
  *(undefined4 *)(param_1 + 0x1100) = 0;
  return 1;
}


/* __stdcall dMsg_openDemoProc(sub_msg_class *) */

undefined4 dMsg_openDemoProc(int param_1)

{
  char cVar1;
  
  *(undefined2 *)(param_1 + 0xf8) = 6;
  dMsg_yose_select();
  if (*(char *)(param_1 + 0x111) != '\0') {
    cVar1 = d_com_inf_game::dComIfGp_getReverb((int)(char)dStage_roomControl_c::mStayNo);
    JAIZelBasic::messageSePlay
              (JAIZelBasic::zel_basic,(ushort)*(byte *)(param_1 + 0x111),(Vec *)0x0,cVar1);
  }
  dMsg_setString(param_1);
  dMsg_messagePaneShow(param_1);
  return 1;
}


/* __stdcall dMsg_closeProc(sub_msg_class *) */

undefined4 dMsg_closeProc(void)

{
  dMsg_frame_close();
  return 1;
}


/* __stdcall dMsg_closeProc2(sub_msg_class *) */

undefined4 dMsg_closeProc2(int param_1)

{
  *(undefined2 *)(param_1 + 0xf8) = 0x12;
  dMsg_messagePaneHide();
  dMsg_outFontHide(param_1);
  return 1;
}


/* __stdcall dMsg_initProc(sub_msg_class *) */

undefined4 dMsg_initProc(int param_1)

{
  char cVar2;
  undefined4 uVar1;
  char *pcVar3;
  char acStack40 [36];
  
  if (((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo
        [(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCamera].field_0x8 & 4) != 0) ||
     (cVar2 = f_op_msg_mng::fopMsgM_demoMsgFlagCheck(), cVar2 != '\0')) {
    pcVar3 = *(char **)(param_1 + 0x111c);
    if ((*pcVar3 == '\x1a') && (pcVar3[2] == '\x02')) {
      d_com_inf_game::g_dComIfG_gameInfo.mMesgCameraTagInfo = ZEXT24(*(ushort *)(pcVar3 + 3));
      *(char **)(param_1 + 0x111c) = pcVar3 + pcVar3[1];
      *(int *)(param_1 + 0x1118) = d_com_inf_game::g_dComIfG_gameInfo.mMesgCameraTagInfo;
    }
    else {
      if ((((*pcVar3 == '\x1a') && (pcVar3[2] == -1)) && (pcVar3[3] == '\0')) && (pcVar3[4] == '\0')
         ) {
        if ((-1 < pcVar3[5]) && (pcVar3[5] < '\t')) {
          uVar1 = f_op_msg_mng::fopMsgM_getColorTable();
          *(undefined4 *)(param_1 + 0x1164) = uVar1;
          MSL_C.PPCEABI.bare.H::sprintf
                    (acStack40,"\x1bCC[%08x]\x1bGM[0]",*(undefined4 *)(param_1 + 0x1164));
          MSL_C.PPCEABI.bare.H::strcat(*(char **)(param_1 + 0x1120),acStack40);
        }
        *(int *)(param_1 + 0x111c) =
             *(int *)(param_1 + 0x111c) + (int)*(char *)(*(int *)(param_1 + 0x111c) + 1);
      }
      else {
        switch(*(undefined *)(param_1 + 0x10c)) {
        default:
          dMsg_ScreenDataValueInitTalk(param_1);
          break;
        case 1:
        case 9:
          dMsg_ScreenDataValueInitItem(param_1);
          break;
        case 5:
          dMsg_ScreenDataValueInitDemo(param_1);
          break;
        case 0xe:
          dMsg_ScreenDataValueInitTact(param_1);
        }
        *(undefined2 *)(param_1 + 0xf8) = 2;
        JAIZelBasic::talkIn(JAIZelBasic::zel_basic);
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x80c,(cXyz *)0x0,0,0,_5863,_5863,_6707,_6707,0)
        ;
      }
    }
  }
  return 1;
}


/* __stdcall dMsg_tactProc(sub_msg_class *) */

undefined4 dMsg_tactProc(int param_1)

{
  char cVar1;
  
  cVar1 = f_op_msg_mng::fopMsgM_checkMessageSend();
  if (cVar1 != '\0') {
    *(undefined *)(param_1 + 0x109b) = 1;
    *(undefined4 *)(param_1 + 0xf5c) = 0x1e;
    *(undefined2 *)(param_1 + 0xf8) = 10;
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dMsg_outnowProc(sub_msg_class *) */

undefined4 dMsg_outnowProc(int param_1)

{
  char cVar2;
  int iVar1;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (*(int *)(param_1 + 0x1118) != d_com_inf_game::g_dComIfG_gameInfo.mMesgCameraTagInfo) {
    if (((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo
          [(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCamera].field_0x8 & 4) != 0) ||
       (cVar2 = f_op_msg_mng::fopMsgM_demoMsgFlagCheck(), cVar2 != '\0')) {
      dMsg_mesgOutPos(param_1);
      *(int *)(param_1 + 0x10d8) = (int)*(float *)(param_1 + 0x4b8);
      *(int *)(param_1 + 0x10dc) = (int)*(float *)(param_1 + 0x4bc);
      f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x49c);
      *(int *)(param_1 + 0x1118) = d_com_inf_game::g_dComIfG_gameInfo.mMesgCameraTagInfo;
    }
  }
  if (*(char *)(param_1 + 0x10d) == '\0') {
    if ((((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) != 0) ||
          ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0')) &&
         (d_com_inf_game::g_dComIfG_gameInfo._23575_1_ == '\0')) &&
        ((*(undefined *)(param_1 + 0x109d) = 1, *(char *)(param_1 + 0x109b) == '\0' &&
         (*(char *)(param_1 + 0x109c) == '\0')))) && (*(int *)(param_1 + 0xf5c) != 0)) {
      *(undefined4 *)(param_1 + 0xf5c) = 0;
      *(undefined *)(param_1 + 0x109a) = 0;
    }
  }
  else {
    if ((*(char *)(param_1 + 0x10d) == '\x01') && (*(char *)(param_1 + 0x109a) == '\0')) {
      *(undefined *)(param_1 + 0x109d) = 1;
    }
  }
  if (((*(char *)(param_1 + 0x109b) == '\0') && (*(char *)(param_1 + 0x109c) == '\0')) &&
     (uVar3 = *(uint *)(param_1 + 0xf5c), uVar3 != 0)) {
    *(uint *)(param_1 + 0xf5c) = uVar3 - 1 & (int)(-uVar3 & ~uVar3) >> 0x1f;
  }
  else {
    fopMsgM_msgDataProc_c::stringSet((fopMsgM_msgDataProc_c *)(param_1 + 0xe04));
    *(undefined4 *)(param_1 + 0x1164) = *(undefined4 *)(param_1 + 0x1060);
    *(ushort *)(param_1 + 0xf8) = (ushort)*(byte *)(param_1 + 0x1080);
    iVar4 = 0;
    iVar6 = 0;
    iVar5 = 0;
    do {
      cVar2 = *(char *)(param_1 + iVar4 + 0x1085);
      iVar1 = *(int *)(param_1 + iVar5 + 0x1024);
      if (((((byte)(cVar2 - 10U) < 4) || (cVar2 == '\x15')) || (cVar2 == '\x15')) && (iVar1 == 0)) {
        iVar1 = -1;
      }
      if (((cVar2 != -1) && (*(short *)((int)&buttonTimer + iVar6) == -1)) &&
         ((cVar2 != '\x14' && ((cVar2 != '\x15' && (cVar2 != '\x16')))))) {
        f_op_msg_mng::fopMsgM_outFontSet
                  (*(undefined4 *)((int)&button_icon + iVar5),
                   *(undefined4 *)((int)&button_kage + iVar5),(short *)((int)&buttonTimer + iVar6),
                   iVar1);
      }
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + 2;
      iVar5 = iVar5 + 4;
    } while (iVar4 < 8);
    if (*(short *)(param_1 + 0xf8) == 7) {
      *(undefined4 *)(param_1 + 0x1100) = 0;
    }
    else {
      if ((*(short *)(param_1 + 0xf8) == 10) && (*(char *)(param_1 + 0x109b) == '\0')) {
        *(undefined4 *)(param_1 + 0x1100) = 0;
      }
    }
  }
  dMsg_setString(param_1);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dMsg_Draw(sub_msg_class *) */

undefined4 dMsg_Draw(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((*(char *)(param_1 + 0x10c) != '\x05') &&
     (f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x49c)),
     *(char *)(param_1 + 0x10c) != '\x0e')) {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x4d4));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x50c));
  }
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x544));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x57c));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x5b4));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x5ec));
  cVar1 = *(char *)(param_1 + 0x10c);
  if ((cVar1 == '\t') || (cVar1 == '\x01')) {
    iVar2 = 0;
    iVar4 = 0;
    do {
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + iVar4 + 0x624));
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 0x38;
    } while (iVar2 < 10);
  }
  else {
    if (cVar1 == '\x0e') {
      if ((*(int *)(param_1 + 0xec) == 0x5b3) || (*(int *)(param_1 + 0xec) == 0x5b4)) {
        iVar4 = 0;
        for (iVar2 = 0;
            iVar2 < (int)(uint)(byte)(&mBeatNum)[d_com_inf_game::g_dComIfG_gameInfo._23536_1_];
            iVar2 = iVar2 + 1) {
          iVar3 = param_1 + iVar4;
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar3 + 0x8c4));
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar3 + 0xa14));
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar3 + 0xb64));
          if (4 < d_com_inf_game::g_dComIfG_gameInfo._23536_1_) {
            f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar3 + 0xcb4));
          }
          iVar4 = iVar4 + 0x38;
        }
      }
    }
    else {
      if (cVar1 != '\x05') {
        iVar2 = 0;
        iVar4 = 0;
        do {
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + iVar4 + 0x26c));
          iVar2 = iVar2 + 1;
          iVar4 = iVar4 + 0x38;
        } while (iVar2 < 10);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x1fc));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x234));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x11c));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x154));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x18c));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x1c4));
      }
    }
  }
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    (dDlst_base_c *)&message);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80215390) */
/* __stdcall dMsg_Execute(sub_msg_class *) */

undefined4 dMsg_Execute(int param_1)

{
  char cVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  short sVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  undefined8 in_f31;
  double dVar14;
  undefined uStack182;
  undefined uStack181;
  undefined uStack178;
  undefined uStack177;
  undefined local_ac;
  undefined uStack171;
  undefined local_a4;
  undefined uStack163;
  double local_a0;
  double local_98;
  double local_90;
  double local_88;
  undefined auStack8 [8];
  
  uVar13 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar7 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
  if (d_com_inf_game::g_dComIfG_gameInfo._23528_1_ != '\0') {
    d_com_inf_game::g_dComIfG_gameInfo._23528_1_ = '\0';
  }
  if ((d_com_inf_game::g_dComIfG_gameInfo._23575_1_ != '\0') &&
     ((*(char *)(param_1 + 0x10c) != '\t' ||
      (((((puVar8 = (undefined1 *)JAIZelBasic::checkPlayingSubBgmFlag(JAIZelBasic::zel_basic),
          puVar8 != &DAT_80000002 &&
          (puVar9 = (undefined *)JAIZelBasic::checkPlayingSubBgmFlag(JAIZelBasic::zel_basic),
          puVar9 != &DAT_80000025)) &&
         (puVar9 = (undefined *)JAIZelBasic::checkPlayingSubBgmFlag(JAIZelBasic::zel_basic),
         puVar9 != &DAT_80000024)) &&
        ((puVar9 = (undefined *)JAIZelBasic::checkPlayingSubBgmFlag(JAIZelBasic::zel_basic),
         puVar9 != &DAT_80000027 &&
         (iVar10 = JAIZelBasic::checkPlayingSubBgmFlag(JAIZelBasic::zel_basic),
         iVar10 != -0x7fffffb2)))) &&
       (puVar9 = (undefined *)JAIZelBasic::checkPlayingSubBgmFlag(JAIZelBasic::zel_basic),
       puVar9 != &DAT_8000004f)))))) {
    d_com_inf_game::g_dComIfG_gameInfo._23575_1_ = '\0';
  }
  if ((*(short *)(param_1 + 0x2a2) == 3) ||
     (((*(short *)(param_1 + 0xf8) != 8 && (*(short *)(param_1 + 0xf8) != 9)) &&
      (*(short *)(param_1 + 0x2a2) != 0)))) {
    if ((int)*(short *)(param_1 + 0x49a) < (int)DAT_803e6b8c + (int)DAT_803e6bba) {
      dMsg_subTextClose(param_1);
    }
    else {
      *(undefined2 *)(param_1 + 0x49a) = 0;
      *(undefined2 *)(param_1 + 0x2a2) = 0;
    }
  }
  sVar5 = *(short *)(param_1 + 0xf8);
  if (sVar5 == 1) {
    dMsg_initProc(param_1);
  }
  else {
    if (sVar5 == 6) {
      dMsg_outnowProc(param_1);
    }
    else {
      if (sVar5 == 7) {
        dMsg_stopProc(param_1);
      }
      else {
        if (((sVar5 == 8) || (sVar5 == 9)) || (sVar5 == 0x14)) {
          dMsg_selectProc(param_1);
        }
        else {
          if (sVar5 == 0x15) {
            dMsg_inputProc(param_1);
          }
          else {
            if (sVar5 == 0x17) {
              dMsg_demoProc(param_1);
            }
            else {
              if (sVar5 == 10) {
                dMsg_closewaitProc(param_1);
              }
              else {
                if (sVar5 == 2) {
                  switch(*(undefined *)(param_1 + 0x10c)) {
                  default:
                    dMsg_openTalkProc(param_1);
                    break;
                  case 1:
                  case 9:
                    dMsg_openItemProc(param_1);
                    break;
                  case 5:
                    dMsg_openDemoProc(param_1);
                    break;
                  case 0xe:
                    dMsg_openTactProc(param_1);
                  }
                }
                else {
                  if (sVar5 == 0xf) {
                    dMsg_continueProc(param_1);
                  }
                  else {
                    if (sVar5 == 0x10) {
                      dMsg_finishProc(param_1);
                    }
                    else {
                      if (sVar5 == 0x11) {
                        if (*(char *)(param_1 + 0x10c) == '\x05') {
                          dMsg_closeProc2(param_1);
                        }
                        else {
                          dMsg_closeProc(param_1);
                        }
                      }
                      else {
                        if (sVar5 == 0x13) {
                          f_op_msg_mng::fopMsgM_Delete(param_1);
                          d_com_inf_game::g_dComIfG_gameInfo.mMesgAnimeTagInfo = 0xff;
                          d_com_inf_game::g_dComIfG_gameInfo.mMesgCameraTagInfo = -1;
                          d_com_inf_game::g_dComIfG_gameInfo.field_0x5bdb = 0;
                          d_com_inf_game::g_dComIfG_gameInfo._23588_4_ = 0;
                        }
                        else {
                          if (sVar5 == 0x16) {
                            dMsg_tactProc(param_1);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  cVar1 = *(char *)(param_1 + 0x10c);
  if ((cVar1 == '\t') || (cVar1 == '\x01')) {
    if (*(char *)(param_1 + 0x819) == *(char *)(param_1 + 0x818)) {
      dMsg_ringMove(param_1);
      dMsg_lightMove(param_1);
      dMsg_cornerMove(param_1);
    }
    iVar10 = 0;
    iVar12 = 2;
    do {
      iVar11 = *(int *)(param_1 + iVar10 + 0x10b4);
      if (iVar11 != 0) {
        *(uint *)(iVar11 + 0x20c) = *(uint *)(iVar11 + 0x20c) & 0xfffffffb;
        *(undefined *)(*(int *)(param_1 + iVar10 + 0x10b4) + 0x1ff) =
             *(undefined *)(param_1 + 0x819);
      }
      iVar10 = iVar10 + 4;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  else {
    if (cVar1 == '\x0e') {
      dMsg_cornerMove(param_1);
    }
  }
  dMsg_rubySet(param_1);
  fVar2 = _4185;
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ != '\0') {
    fVar2 = _8056;
  }
  dVar14 = (double)fVar2;
  f_op_msg_mng::fopMsgM_messageSendOff();
  uVar6 = DAT_803e6b49;
  cVar1 = *(char *)(param_1 + 0x10c);
  if (cVar1 == '\x05') {
    if (init_7923 == '\0') {
      posY0_7922 = (uint)*(float *)(*(int *)(param_1 + 0x544) + 0x10);
      init_7923 = '\x01';
    }
    if (init_7926 == '\0') {
      posY1_7925 = (uint)*(float *)(*(int *)(param_1 + 0x57c) + 0x10);
      init_7926 = '\x01';
    }
    if (init_7929 == '\0') {
      posY2_7928 = (uint)*(float *)(*(int *)(param_1 + 0x5b4) + 0x10);
      init_7929 = '\x01';
    }
    if (init_7932 == '\0') {
      posY3_7931 = (uint)*(float *)(*(int *)(param_1 + 0x5ec) + 0x10);
      init_7932 = '\x01';
    }
    fVar2 = *(float *)(*(int *)(param_1 + 0x57c) + 0xc);
    fVar3 = *(float *)(*(int *)(param_1 + 0x5b4) + 0xc);
    fVar4 = *(float *)(*(int *)(param_1 + 0x5ec) + 0xc);
    (**(code **)(**(int **)(param_1 + 0x544) + 0x10))
              ((double)(float)((double)CONCAT44(0x43300000,
                                                (int)(float)(*(int **)(param_1 + 0x544))[3] ^
                                                0x80000000) - _4188),
               (double)(float)((double)CONCAT44(0x43300000,posY0_7922 ^ 0x80000000) - _4188));
    (**(code **)(**(int **)(param_1 + 0x57c) + 0x10))
              ((double)(float)((double)CONCAT44(0x43300000,(int)fVar2 ^ 0x80000000) - _4188),
               (double)(float)((double)CONCAT44(0x43300000,posY1_7925 ^ 0x80000000) - _4188));
    (**(code **)(**(int **)(param_1 + 0x5b4) + 0x10))
              ((double)(float)((double)CONCAT44(0x43300000,(int)fVar3 ^ 0x80000000) - _4188),
               (double)(float)((double)CONCAT44(0x43300000,posY2_7928 ^ 0x80000000) - _4188));
    (**(code **)(**(int **)(param_1 + 0x5ec) + 0x10))
              ((double)(float)((double)CONCAT44(0x43300000,(int)fVar4 ^ 0x80000000) - _4188),
               (double)(float)((double)CONCAT44(0x43300000,posY3_7931 ^ 0x80000000) - _4188));
  }
  else {
    if ((cVar1 == '\t') || (cVar1 == '\x01')) {
      (**(code **)(**(int **)(param_1 + 0x49c) + 0x10))
                ((double)*(float *)(param_1 + 0x4a8),
                 (double)(*(float *)(param_1 + 0x4ac) +
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6baa ^ 0x80000000) - _4188
                                )));
      (**(code **)(**(int **)(param_1 + 0x50c) + 0x10))
                ((double)*(float *)(param_1 + 0x518),
                 (double)(*(float *)(param_1 + 0x51c) +
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6baa ^ 0x80000000) - _4188
                                )));
      (**(code **)(**(int **)(param_1 + 0x544) + 0x10))
                ((double)(float)((double)CONCAT44(0x43300000,
                                                  *(uint *)(param_1 + 0x10f8) ^ 0x80000000) - _4188)
                 ,(double)((float)((double)CONCAT44(0x43300000,(int)DAT_803e6baa ^ 0x80000000) -
                                  _4188) +
                          (float)(dVar14 + (double)(float)((double)CONCAT44(0x43300000,
                                                                            (*(int *)(param_1 +
                                                                                     0x10fc) -
                                                                            (int)DAT_803e6ba6) -
                                                                            (int)textOffsetY ^
                                                                            0x80000000) - _4188))));
      (**(code **)(**(int **)(param_1 + 0x57c) + 0x10))
                ((double)(float)((double)CONCAT44(0x43300000,
                                                  *(uint *)(param_1 + 0x10f8) ^ 0x80000000) - _4188)
                 ,(double)((float)((double)CONCAT44(0x43300000,(int)DAT_803e6baa ^ 0x80000000) -
                                  _4188) +
                          (float)(dVar14 + (double)(float)((double)CONCAT44(0x43300000,
                                                                            (*(int *)(param_1 +
                                                                                     0x10fc) -
                                                                            (int)DAT_803e6ba4) -
                                                                            (int)textOffsetY ^
                                                                            0x80000000) - _4188))));
      local_88 = (double)CONCAT44(0x43300000,*(int *)(param_1 + 0x10f8) + 2U ^ 0x80000000);
      local_90 = (double)CONCAT44(0x43300000,(int)DAT_803e6baa ^ 0x80000000);
      local_98 = (double)CONCAT44(0x43300000,
                                  ((*(int *)(param_1 + 0x10fc) - (int)DAT_803e6ba6) + 2) -
                                  (int)textOffsetY ^ 0x80000000);
      (**(code **)(**(int **)(param_1 + 0x5b4) + 0x10))
                ((double)(float)(local_88 - _4188),
                 (double)((float)(local_90 - _4188) +
                         (float)(dVar14 + (double)(float)(local_98 - _4188))));
      local_a0 = (double)CONCAT44(0x43300000,*(int *)(param_1 + 0x10f8) + 2U ^ 0x80000000);
      (**(code **)(**(int **)(param_1 + 0x5ec) + 0x10))
                ((double)(float)(local_a0 - _4188),
                 (double)((float)((double)CONCAT44(0x43300000,(int)DAT_803e6baa ^ 0x80000000) -
                                 _4188) +
                         (float)(dVar14 + (double)(float)((double)CONCAT44(0x43300000,
                                                                           ((*(int *)(param_1 +
                                                                                     0x10fc) -
                                                                            (int)DAT_803e6ba4) + 2)
                                                                           - (int)textOffsetY ^
                                                                           0x80000000) - _4188))));
    }
    else {
      if (cVar1 == '\x0e') {
        (**(code **)(**(int **)(param_1 + 0x49c) + 0x10))
                  ((double)*(float *)(param_1 + 0x4a8),
                   (double)(*(float *)(param_1 + 0x4ac) +
                           (float)((double)CONCAT44(0x43300000,(int)DAT_803e6baa ^ 0x80000000) -
                                  _4188)));
        (**(code **)(**(int **)(param_1 + 0x544) + 0x10))
                  ((double)(float)((double)CONCAT44(0x43300000,
                                                    *(uint *)(param_1 + 0x10f8) ^ 0x80000000) -
                                  _4188),
                   (double)((float)((double)CONCAT44(0x43300000,(int)DAT_803e6baa ^ 0x80000000) -
                                   _4188) +
                           (float)(dVar14 + (double)(float)((double)CONCAT44(0x43300000,
                                                                             (*(int *)(param_1 +
                                                                                      0x10fc) -
                                                                             (int)DAT_803e6ba6) -
                                                                             (int)textOffsetY ^
                                                                             0x80000000) - _4188))))
        ;
        (**(code **)(**(int **)(param_1 + 0x57c) + 0x10))
                  ((double)(float)((double)CONCAT44(0x43300000,
                                                    *(uint *)(param_1 + 0x10f8) ^ 0x80000000) -
                                  _4188),
                   (double)((float)((double)CONCAT44(0x43300000,(int)DAT_803e6baa ^ 0x80000000) -
                                   _4188) +
                           (float)(dVar14 + (double)(float)((double)CONCAT44(0x43300000,
                                                                             (*(int *)(param_1 +
                                                                                      0x10fc) -
                                                                             (int)DAT_803e6ba4) -
                                                                             (int)textOffsetY ^
                                                                             0x80000000) - _4188))))
        ;
        (**(code **)(**(int **)(param_1 + 0x5b4) + 0x10))
                  ((double)(float)((double)CONCAT44(0x43300000,
                                                    *(int *)(param_1 + 0x10f8) + 2U ^ 0x80000000) -
                                  _4188),
                   (double)((float)((double)CONCAT44(0x43300000,(int)DAT_803e6baa ^ 0x80000000) -
                                   _4188) +
                           (float)(dVar14 + (double)(float)((double)CONCAT44(0x43300000,
                                                                             ((*(int *)(param_1 +
                                                                                       0x10fc) -
                                                                              (int)DAT_803e6ba6) + 2
                                                                             ) - (int)textOffsetY ^
                                                                             0x80000000) - _4188))))
        ;
        local_88 = (double)CONCAT44(0x43300000,*(int *)(param_1 + 0x10f8) + 2U ^ 0x80000000);
        local_90 = (double)CONCAT44(0x43300000,(int)DAT_803e6baa ^ 0x80000000);
        local_98 = (double)CONCAT44(0x43300000,
                                    ((*(int *)(param_1 + 0x10fc) - (int)DAT_803e6ba4) + 2) -
                                    (int)textOffsetY ^ 0x80000000);
        (**(code **)(**(int **)(param_1 + 0x5ec) + 0x10))
                  ((double)(float)(local_88 - _4188),
                   (double)((float)(local_90 - _4188) +
                           (float)(dVar14 + (double)(float)(local_98 - _4188))));
      }
      else {
        uStack178 = (undefined)((uint)DAT_803e6b49 >> 8);
        uStack177 = (undefined)DAT_803e6b49;
        iVar10 = *(int *)(param_1 + 0x49c);
        local_a4 = (undefined)((uint)DAT_803e6b49 >> 0x18);
        *(undefined *)(iVar10 + 0x104) = local_a4;
        uStack163 = (undefined)((uint)uVar6 >> 0x10);
        *(undefined *)(iVar10 + 0x105) = uStack163;
        *(undefined *)(iVar10 + 0x106) = uStack178;
        *(undefined *)(iVar10 + 0x107) = uStack177;
        uVar6 = DAT_803e6b4d;
        uStack182 = (undefined)((uint)DAT_803e6b4d >> 8);
        uStack181 = (undefined)DAT_803e6b4d;
        iVar10 = *(int *)(param_1 + 0x49c);
        local_ac = (undefined)((uint)DAT_803e6b4d >> 0x18);
        *(undefined *)(iVar10 + 0x108) = local_ac;
        uStack171 = (undefined)((uint)uVar6 >> 0x10);
        *(undefined *)(iVar10 + 0x109) = uStack171;
        *(undefined *)(iVar10 + 0x10a) = uStack182;
        *(undefined *)(iVar10 + 0x10b) = uStack181;
        (**(code **)(**(int **)(param_1 + 0x49c) + 0x10))
                  ((double)*(float *)(param_1 + 0x4a8),
                   (double)(*(float *)(param_1 + 0x4ac) +
                           (float)((double)CONCAT44(0x43300000,(int)DAT_803e6baa ^ 0x80000000) -
                                  _4188)));
        (**(code **)(**(int **)(param_1 + 0x50c) + 0x10))
                  ((double)*(float *)(param_1 + 0x518),
                   (double)(*(float *)(param_1 + 0x51c) +
                           (float)((double)CONCAT44(0x43300000,(int)DAT_803e6baa ^ 0x80000000) -
                                  _4188)));
        (**(code **)(**(int **)(param_1 + 0x544) + 0x10))
                  ((double)(float)((double)CONCAT44(0x43300000,
                                                    *(uint *)(param_1 + 0x10f8) ^ 0x80000000) -
                                  _4188),
                   (double)((float)((double)CONCAT44(0x43300000,(int)DAT_803e6baa ^ 0x80000000) -
                                   _4188) +
                           (float)(dVar14 + (double)(float)((double)CONCAT44(0x43300000,
                                                                             (*(int *)(param_1 +
                                                                                      0x10fc) -
                                                                             (int)DAT_803e6ba6) -
                                                                             (int)textOffsetY ^
                                                                             0x80000000) - _4188))))
        ;
        (**(code **)(**(int **)(param_1 + 0x57c) + 0x10))
                  ((double)(float)((double)CONCAT44(0x43300000,
                                                    *(uint *)(param_1 + 0x10f8) ^ 0x80000000) -
                                  _4188),
                   (double)((float)((double)CONCAT44(0x43300000,(int)DAT_803e6baa ^ 0x80000000) -
                                   _4188) +
                           (float)(dVar14 + (double)(float)((double)CONCAT44(0x43300000,
                                                                             (*(int *)(param_1 +
                                                                                      0x10fc) -
                                                                             (int)DAT_803e6ba4) -
                                                                             (int)textOffsetY ^
                                                                             0x80000000) - _4188))))
        ;
        local_88 = (double)CONCAT44(0x43300000,
                                    ((*(int *)(param_1 + 0x10fc) - (int)DAT_803e6ba6) + 2) -
                                    (int)textOffsetY ^ 0x80000000);
        (**(code **)(**(int **)(param_1 + 0x5b4) + 0x10))
                  ((double)(float)((double)CONCAT44(0x43300000,
                                                    *(int *)(param_1 + 0x10f8) + 2U ^ 0x80000000) -
                                  _4188),
                   (double)((float)((double)CONCAT44(0x43300000,(int)DAT_803e6baa ^ 0x80000000) -
                                   _4188) + (float)(dVar14 + (double)(float)(local_88 - _4188))));
        local_90 = (double)CONCAT44(0x43300000,*(int *)(param_1 + 0x10f8) + 2U ^ 0x80000000);
        local_98 = (double)CONCAT44(0x43300000,(int)DAT_803e6baa ^ 0x80000000);
        local_a0 = (double)CONCAT44(0x43300000,
                                    ((*(int *)(param_1 + 0x10fc) - (int)DAT_803e6ba4) + 2) -
                                    (int)textOffsetY ^ 0x80000000);
        (**(code **)(**(int **)(param_1 + 0x5ec) + 0x10))
                  ((double)(float)(local_90 - _4188),
                   (double)((float)(local_98 - _4188) +
                           (float)(dVar14 + (double)(float)(local_a0 - _4188))));
      }
    }
  }
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = (byte)*(undefined2 *)(param_1 + 0xf8);
  m_Do_ext::mDoExt_setCurrentHeap(uVar7);
  __psq_l0(auStack8,uVar13);
  __psq_l1(auStack8,uVar13);
  return 1;
}


/* __stdcall dMsg_IsDelete(sub_msg_class *) */

undefined4 dMsg_IsDelete(void)

{
  return 1;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall dMsg_Delete(sub_msg_class *) */

undefined4 dMsg_Delete(int param_1)

{
  char cVar4;
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar5;
  int iVar6;
  
  cVar4 = f_op_msg_mng::fopMsgM_demoMsgFlagCheck();
  if (cVar4 != '\0') {
    f_op_msg_mng::fopMsgM_demoMsgFlagOff();
  }
  cVar4 = f_op_msg_mng::fopMsgM_tactMsgFlagCheck();
  if (cVar4 != '\0') {
    f_op_msg_mng::fopMsgM_tactMsgFlagOff();
  }
  cVar4 = f_op_msg_mng::fopMsgM_nextMsgFlagCheck();
  if (cVar4 != '\0') {
    f_op_msg_mng::fopMsgM_nextMsgFlagOff();
  }
  *(undefined *)(param_1 + 0x116a) = 0;
  d_com_inf_game::g_dComIfG_gameInfo._23528_1_ = *(undefined *)(param_1 + 0x116a);
  d_com_inf_game::g_dComIfG_gameInfo._23529_1_ = 0;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = 0;
  if (d_com_inf_game::g_dComIfG_gameInfo._23575_1_ != '\0') {
    d_com_inf_game::g_dComIfG_gameInfo._23575_1_ = '\0';
  }
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
  iVar2 = 0;
  iVar6 = 2;
  do {
    iVar5 = *(int *)(param_1 + iVar2 + 0x10b4);
    if (iVar5 != 0) {
      *(undefined4 *)(iVar5 + 0x60) = 0xffffffff;
      *(uint *)(iVar5 + 0x20c) = *(uint *)(iVar5 + 0x20c) | 1;
      iVar5 = *(int *)(param_1 + iVar2 + 0x10b4);
      *(uint *)(iVar5 + 0x20c) = *(uint *)(iVar5 + 0x20c) & 0xffffffbf;
    }
    iVar2 = iVar2 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if (sScreen != (int *)0x0) {
    (**(code **)(*sScreen + 8))(sScreen,1);
  }
  if ((sScreen2 != (int *)0x0) && (sScreen2 != (int *)0x0)) {
    (**(code **)(*sScreen2 + 8))(sScreen2,1);
  }
  if (dMsg_font_flag == '\0') {
    m_Do_ext::mDoExt_removeMesgFont();
  }
  else {
    m_Do_ext::mDoExt_removeRubyFont();
  }
  iVar2 = 0;
  iVar6 = 0;
  do {
    piVar3 = *(int **)((int)&button_icon + iVar6);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3,1);
    }
    piVar3 = *(int **)((int)&button_kage + iVar6);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3,1);
    }
    iVar2 = iVar2 + 1;
    iVar6 = iVar6 + 4;
  } while (iVar2 < 8);
  if (arrowPane != (int *)0x0) {
    (**(code **)(*arrowPane + 8))(arrowPane,1);
  }
  if (maskPane != (int *)0x0) {
    (**(code **)(*maskPane + 8))(maskPane,1);
  }
  iVar2 = 0;
  iVar6 = 0;
  do {
    piVar3 = *(int **)((int)&numberPane + iVar6);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3,1);
    }
    iVar2 = iVar2 + 1;
    iVar6 = iVar6 + 4;
  } while (iVar2 < 3);
  JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(param_1 + 0x1120));
  JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(param_1 + 0x1124));
  JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(param_1 + 0x1128));
  JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(param_1 + 0x112c));
  JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(param_1 + 0x1130));
  JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(param_1 + 0x1134));
  JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(param_1 + 0x1138));
  JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(param_1 + 0x113c));
  agb_work_area = 0;
  if (*(void **)(param_1 + 0x10cc) != (void *)0x0) {
    JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(param_1 + 0x10cc));
  }
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive)->parent).parent.vtbl)->
            removeResourceAll)();
  JKRHeap::freeAll(*(JKRHeap **)(param_1 + 0xfc));
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 0;
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __stdcall dMsg_Create(msg_class *) */

undefined4 dMsg_Create(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  J2DPicture *pJVar4;
  void *pvVar5;
  ulong uVar6;
  int iVar7;
  int iVar8;
  undefined4 local_48;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  undefined2 local_3e;
  undefined local_3c;
  undefined local_3b;
  undefined local_3a;
  undefined local_39;
  undefined local_38;
  undefined local_37;
  undefined local_36;
  undefined local_35;
  undefined local_34;
  undefined local_33;
  undefined local_32;
  undefined local_31;
  
  if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 0) ||
     (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 7)) {
    *(JKRExpHeap **)(param_1 + 0xfc) = d_com_inf_game::g_dComIfG_gameInfo.field_0x5c1c;
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 7;
    uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
    uVar6 = *(ulong *)(param_1 + 0xec);
    if ((uVar6 < 0xc6) || (0xcd < uVar6)) {
      uVar3 = fopMsgM_msgGet_c::getMesgHeader((fopMsgM_msgGet_c *)(param_1 + 0x10a4),uVar6);
      *(undefined4 *)(param_1 + 0x118) = uVar3;
    }
    else {
      iVar2 = dSv_player_collect_c::getTriforceNum
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect);
      uVar3 = fopMsgM_msgGet_c::getMesgHeader((fopMsgM_msgGet_c *)(param_1 + 0x10a4),iVar2 + 0xc6);
      *(undefined4 *)(param_1 + 0x118) = uVar3;
    }
    if (*(int *)(param_1 + 0x118) == 0) {
      uVar6 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar6,"d_msg.cpp",0x1528,"i_Msg->head_p");
      m_Do_printf::OSPanic("d_msg.cpp",0x1528,&DAT_80361ec0);
    }
    uVar3 = fopMsgM_msgGet_c::getMessage
                      ((fopMsgM_msgGet_c *)(param_1 + 0x10a4),*(mesg_header **)(param_1 + 0x118));
    *(undefined4 *)(param_1 + 0x111c) = uVar3;
    fopMsgM_msgGet_c::getMesgEntry((fopMsgM_msgGet_c *)&local_48,(mesg_header *)(param_1 + 0x10a4));
    *(undefined4 *)(param_1 + 0x100) = local_48;
    *(undefined2 *)(param_1 + 0x104) = local_44;
    *(undefined2 *)(param_1 + 0x106) = local_42;
    *(undefined2 *)(param_1 + 0x108) = local_40;
    *(undefined2 *)(param_1 + 0x10a) = local_3e;
    *(undefined *)(param_1 + 0x10c) = local_3c;
    *(undefined *)(param_1 + 0x10d) = local_3b;
    *(undefined *)(param_1 + 0x10e) = local_3a;
    *(undefined *)(param_1 + 0x10f) = local_39;
    *(undefined *)(param_1 + 0x110) = local_38;
    *(undefined *)(param_1 + 0x111) = local_37;
    *(undefined *)(param_1 + 0x112) = local_36;
    *(undefined *)(param_1 + 0x113) = local_35;
    *(undefined *)(param_1 + 0x114) = local_34;
    *(undefined *)(param_1 + 0x115) = local_33;
    *(undefined *)(param_1 + 0x116) = local_32;
    *(undefined *)(param_1 + 0x117) = local_31;
    *(uint *)(param_1 + 0x1140) =
         (uint)*(ushort *)(param_1 + 0x10ac) << 8 | (uint)*(ushort *)(param_1 + 0x10b0);
    *(int *)(param_1 + 0x1118) = d_com_inf_game::g_dComIfG_gameInfo.mMesgCameraTagInfo;
    dMsg_screenDataSet(param_1);
    iVar8 = 0;
    iVar7 = 0;
    iVar2 = 0;
    do {
      pJVar4 = (J2DPicture *)JKernel::operator_new(0x124);
      if (pJVar4 != (J2DPicture *)0x0) {
        J2DPicture::J2DPicture(pJVar4,"font_07_02.bti");
      }
      *(J2DPicture **)((int)&button_icon + iVar2) = pJVar4;
      pJVar4 = (J2DPicture *)JKernel::operator_new(0x124);
      if (pJVar4 != (J2DPicture *)0x0) {
        J2DPicture::J2DPicture(pJVar4,"font_07_02.bti");
      }
      *(J2DPicture **)((int)&button_kage + iVar2) = pJVar4;
      f_op_msg_mng::fopMsgM_blendInit(*(undefined4 *)((int)&button_icon + iVar2),"font_00.bti");
      f_op_msg_mng::fopMsgM_blendInit(*(undefined4 *)((int)&button_kage + iVar2),"font_00.bti");
      *(undefined *)(*(int *)((int)&button_icon + iVar2) + 0xaa) = 0;
      *(undefined *)(*(int *)((int)&button_kage + iVar2) + 0xaa) = 0;
      *(undefined *)(*(int *)((int)&button_icon + iVar2) + 0xac) = 0;
      *(undefined *)(*(int *)((int)&button_kage + iVar2) + 0xac) = 0;
      *(undefined2 *)((int)&buttonTimer + iVar7) = 0xffff;
      iVar8 = iVar8 + 1;
      iVar7 = iVar7 + 2;
      iVar2 = iVar2 + 4;
    } while (iVar8 < 8);
    pJVar4 = (J2DPicture *)JKernel::operator_new(0x124);
    if (pJVar4 != (J2DPicture *)0x0) {
      J2DPicture::J2DPicture(pJVar4,"font_10.bti");
    }
    arrowPane = pJVar4;
    pvVar5 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x385,4);
    *(void **)(param_1 + 0x1120) = pvVar5;
    if (*(int *)(param_1 + 0x1120) == 0) {
      uVar6 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar6,"d_msg.cpp",0x1544,"i_Msg->output_text != 0");
      m_Do_printf::OSPanic("d_msg.cpp",0x1544,&DAT_80361ec0);
    }
    pvVar5 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x385,4);
    *(void **)(param_1 + 0x1124) = pvVar5;
    if (*(int *)(param_1 + 0x1124) == 0) {
      uVar6 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar6,"d_msg.cpp",0x1547,"i_Msg->output_rub != 0");
      m_Do_printf::OSPanic("d_msg.cpp",0x1547,&DAT_80361ec0);
    }
    pvVar5 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x385,4);
    *(void **)(param_1 + 0x1128) = pvVar5;
    if (*(int *)(param_1 + 0x1128) == 0) {
      uVar6 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar6,"d_msg.cpp",0x154a,"i_Msg->output_textSdw != 0");
      m_Do_printf::OSPanic("d_msg.cpp",0x154a,&DAT_80361ec0);
    }
    pvVar5 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x385,4);
    *(void **)(param_1 + 0x112c) = pvVar5;
    if (*(int *)(param_1 + 0x112c) == 0) {
      uVar6 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar6,"d_msg.cpp",0x154d,"i_Msg->output_rubSdw != 0");
      m_Do_printf::OSPanic("d_msg.cpp",0x154d,&DAT_80361ec0);
    }
    pvVar5 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x65,4);
    *(void **)(param_1 + 0x1130) = pvVar5;
    if (*(int *)(param_1 + 0x1130) == 0) {
      uVar6 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar6,"d_msg.cpp",0x1550,"i_Msg->select_text != 0");
      m_Do_printf::OSPanic("d_msg.cpp",0x1550,&DAT_80361ec0);
    }
    pvVar5 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x65,4);
    *(void **)(param_1 + 0x1134) = pvVar5;
    if (*(int *)(param_1 + 0x1134) == 0) {
      uVar6 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar6,"d_msg.cpp",0x1553,"i_Msg->select_rub != 0");
      m_Do_printf::OSPanic("d_msg.cpp",0x1553,&DAT_80361ec0);
    }
    pvVar5 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x65,4);
    *(void **)(param_1 + 0x1138) = pvVar5;
    if (*(int *)(param_1 + 0x1138) == 0) {
      uVar6 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar6,"d_msg.cpp",0x1556,"i_Msg->select_textSdw != 0");
      m_Do_printf::OSPanic("d_msg.cpp",0x1556,&DAT_80361ec0);
    }
    pvVar5 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x65,4);
    *(void **)(param_1 + 0x113c) = pvVar5;
    if (*(int *)(param_1 + 0x113c) == 0) {
      uVar6 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar6,"d_msg.cpp",0x1559,"i_Msg->select_rubSdw != 0");
      m_Do_printf::OSPanic("d_msg.cpp",0x1559,&DAT_80361ec0);
    }
    agb_work_area = *(int *)(param_1 + 0xfc);
    if (agb_work_area == 0) {
      uVar6 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar6,"d_msg.cpp",0x155c,"agb_work_area != 0");
      m_Do_printf::OSPanic("d_msg.cpp",0x155c,&DAT_80361ec0);
    }
    *(undefined2 *)(param_1 + 0xf8) = 1;
    *(undefined4 *)(param_1 + 0x1164) = 0xffffffff;
    dMsg_value_init(param_1);
    dMsg_setString(param_1);
    *(undefined *)(param_1 + 0x116a) = 0;
    d_com_inf_game::g_dComIfG_gameInfo._23528_1_ = *(undefined *)(param_1 + 0x116a);
    d_com_inf_game::g_dComIfG_gameInfo._23529_1_ = 0;
    m_Do_ext::mDoExt_setCurrentHeap(uVar1);
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = (byte)*(undefined2 *)(param_1 + 0xf8);
    uVar1 = 4;
    iRam803f71d4 = param_1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

}

/* __thiscall dDlst_2Dtact_c::~dDlst_2Dtact_c(void) */

void __thiscall dDlst_2Dtact_c::_dDlst_2Dtact_c(dDlst_2Dtact_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2Dtact_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_2Dtact_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_2DMSG_c::~dDlst_2DMSG_c(void) */

void __thiscall dDlst_2DMSG_c::_dDlst_2DMSG_c(dDlst_2DMSG_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2DMSG_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_2DMSG_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_msg {

void __sinit_d_msg_cpp(void)

{
  message = &::dDlst_2DMSG_c::__vt;
  Runtime.PPCEABI.H::__register_global_object(&message,::dDlst_2DMSG_c::_dDlst_2DMSG_c,&_4275);
  capture = &::dDlst_2Dtact_c::__vt;
  Runtime.PPCEABI.H::__register_global_object(&capture,::dDlst_2Dtact_c::_dDlst_2Dtact_c,&_4276);
  multiTex = &dDlst_2DM_c::__vt;
  Runtime.PPCEABI.H::__register_global_object(&multiTex,dDlst_2DM_c::_dDlst_2DM_c,&_4277);
  return;
}

