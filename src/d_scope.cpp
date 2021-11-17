#include <d_scope.h>
#include <J2DGraph/J2DScreen.h>
#include <d_scope.h>
#include <f_op_msg_mng.h>
#include <m_Do_ext.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <J2DGraph/J2DTextBox.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <J2DGraph/J2DPicture.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JKernel/JKRFileLoader.h>
#include <d_camera.h>
#include <d_drawlist.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DPane.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dDlst_2DSCP_c.h>


namespace d_scope {
struct J2DPicture * sbutton_icon[8];
struct J2DPicture * sbutton_kage[8];
undefined2 sbuttonTimer;
undefined4 dScp_ScpScreen;
undefined4 dScp_MsgScreen;
undefined4 font0;
undefined4 font1;
undefined4 scope;
}

/* __thiscall dDlst_2DSCP_c::draw(void) */

void __thiscall dDlst_2DSCP_c::draw(dDlst_2DSCP_c *this)

{
  J2DOrthoGraph *pCtx;
  
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(d_scope::dScp_ScpScreen,d_scope::0_0,d_scope::0_0,&pCtx->parent);
  J2DScreen::draw(d_scope::dScp_MsgScreen,d_scope::0_0,d_scope::0_0,&pCtx->parent);
  outFontDraw(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80237700) */
/* __thiscall dDlst_2DSCP_c::outFontDraw(void) */

void __thiscall dDlst_2DSCP_c::outFontDraw(dDlst_2DSCP_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 in_f31;
  double dVar8;
  double local_48;
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar6 = 0;
  iVar5 = 0;
  iVar4 = 0;
  dVar8 = (double)d_scope::0_5;
  do {
    iVar2 = *(int *)(this + 4);
    iVar1 = iVar2 + iVar4 + 0x634;
    iVar3 = *(int *)(iVar2 + 0x60c);
    if (*(char *)(iVar2 + iVar6 + 0x8b5) != -1) {
      local_48 = (double)CONCAT44(0x43300000,*(uint *)(iVar1 + 0x168) ^ 0x80000000);
      f_op_msg_mng::fopMsgM_outFontDraw
                (*(undefined4 *)((int)d_scope::sbutton_icon + iVar4),
                 *(undefined4 *)((int)d_scope::sbutton_kage + iVar4),
                 (int)((float)(local_48 - d_scope::_4142) + *(float *)(iVar3 + 0xc)),
                 (int)((float)((double)CONCAT44(0x43300000,
                                                (int)((double)*(float *)(iVar3 + 0xe4) * dVar8) *
                                                ((2 - *(short *)(iVar2 + 0x916)) +
                                                *(int *)(iVar1 + 0x1a4) * 2) ^ 0x80000000) -
                              d_scope::_4142) + *(float *)(iVar3 + 0x10)),
                 *(undefined4 *)(iVar1 + 0x1e0),(int)&d_scope::sbuttonTimer + iVar5,0xff);
    }
    iVar6 = iVar6 + 1;
    iVar5 = iVar5 + 2;
    iVar4 = iVar4 + 4;
  } while (iVar6 < 8);
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return;
}


namespace d_scope {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dScp_ScreenDataSet(sub_scp_class *) */

void dScp_ScreenDataSet(sub_scp_class *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  ulong uVar4;
  J2DScreen *pJVar5;
  J2DTextBox *pJVar6;
  int iVar7;
  int iVar8;
  
  font0 = m_Do_ext::mDoExt_getMesgFont();
  if (font0 == (JUTFont *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_scope.cpp",0xb0,"font0 != 0");
    m_Do_printf::OSPanic("d_scope.cpp",0xb0,&DAT_8036387f);
  }
  font1 = m_Do_ext::mDoExt_getRubyFont();
  if (font1 == (JUTFont *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_scope.cpp",0xb3,"font1 != 0");
    m_Do_printf::OSPanic("d_scope.cpp",0xb3,&DAT_8036387f);
  }
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x77637273);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x104,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x776e756d);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x13c,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x7763726b);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x174,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x776e756b);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x1ac,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x77706261);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x1e4,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x77626170);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x21c,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x77707363);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x254,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x7972746e);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x28c,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x797a6f6d);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x2c4,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x6372746e);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x2fc,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x637a6f6d);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x334,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x6c72746e);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x36c,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x727a6f6d);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x3a4,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x77703033);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x3dc,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x77703032);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x414,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x77703031);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x44c,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x77703030);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x484,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x77703034);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x4bc,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x77703035);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x4f4,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x77703037);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x52c,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_ScpScreen + 0x30))(dScp_ScpScreen,0x77703036);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x564,pJVar5);
  (param_1->field_0x28c).mPosCenterOrig.x = (param_1->field_0x28c).mPosCenterOrig.x - 12_0;
  f_op_msg_mng::fopMsgM_paneTrans(&param_1->field_0x28c,(double)0_0,(double)0_0);
  (param_1->field_0x2c4).mPosCenterOrig.x = (param_1->field_0x2c4).mPosCenterOrig.x - 12_0;
  f_op_msg_mng::fopMsgM_paneTrans(&param_1->field_0x2c4,(double)0_0,(double)0_0);
  (param_1->field_0x2fc).mPosCenterOrig.x = (param_1->field_0x2fc).mPosCenterOrig.x - 12_0;
  f_op_msg_mng::fopMsgM_paneTrans(&param_1->field_0x2fc,(double)0_0,(double)0_0);
  (param_1->field_0x334).mPosCenterOrig.x = (param_1->field_0x334).mPosCenterOrig.x - 12_0;
  f_op_msg_mng::fopMsgM_paneTrans(&param_1->field_0x334,(double)0_0,(double)0_0);
  f_op_msg_mng::fopMsgM_blendInit(&param_1->field_0x2fc,"font_09_02.bti");
  f_op_msg_mng::fopMsgM_blendInit(&param_1->field_0x334,"font_09_02.bti");
  fVar1 = (param_1->field_0x334).mSizeOrig.y * 0_5;
  pJVar5 = (param_1->field_0x334).mpPane;
  (pJVar5->parent).mBasePosition.x = (param_1->field_0x334).mSizeOrig.x * 0_5;
  (pJVar5->parent).mBasePosition.y = fVar1;
  (pJVar5->parent).mRotationAxis = 'z';
  (pJVar5->parent).mRotation = _4240;
  (*(code *)((pJVar5->parent).vtbl)->calcMtx)();
  f_op_msg_mng::fopMsgM_blendInit(&param_1->field_0x28c,"cursor_00_02.bti");
  f_op_msg_mng::fopMsgM_blendInit(&param_1->field_0x2c4,"cursor_00_02.bti");
  dScp_wipeMove((double)3_0,param_1);
  iVar7 = 0;
  iVar8 = 0;
  do {
    f_op_msg_mng::fopMsgM_setInitAlpha((int)&(param_1->field_0x3dc).mpPane + iVar8);
    iVar7 = iVar7 + 1;
    iVar8 = iVar8 + 0x38;
  } while (iVar7 < 8);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_MsgScreen + 0x30))(dScp_MsgScreen,0x797a3830);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->mArrow,pJVar5);
  pJVar5 = (J2DScreen *)(**(code **)(*dScp_MsgScreen + 0x30))(dScp_MsgScreen,0x64743830);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)&param_1->field_0x5d4,pJVar5);
  pJVar6 = (J2DTextBox *)(**(code **)(*dScp_MsgScreen + 0x30))(dScp_MsgScreen,0x74783832);
  param_1->field_0x60c = pJVar6;
  pJVar6 = (J2DTextBox *)(**(code **)(*dScp_MsgScreen + 0x30))(dScp_MsgScreen,0x74783833);
  param_1->field_0x610 = pJVar6;
  pJVar6 = (J2DTextBox *)(**(code **)(*dScp_MsgScreen + 0x30))(dScp_MsgScreen,0x74783830);
  param_1->field_0x614 = pJVar6;
  pJVar6 = (J2DTextBox *)(**(code **)(*dScp_MsgScreen + 0x30))(dScp_MsgScreen,0x74783831);
  param_1->field_0x618 = pJVar6;
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ != '\0') {
    pJVar6 = param_1->field_0x60c;
    (*(code *)((pJVar6->parent).vtbl)->move)
              ((double)(pJVar6->parent).mPosTL.x,(double)((pJVar6->parent).mPosTL.y - _4242));
    pJVar6 = param_1->field_0x614;
    (*(code *)((pJVar6->parent).vtbl)->move)
              ((double)(pJVar6->parent).mPosTL.x,(double)((pJVar6->parent).mPosTL.y - _4242));
  }
  pJVar6 = param_1->field_0x610;
  (*(code *)((pJVar6->parent).vtbl)->move)
            ((double)(pJVar6->parent).mPosTL.x,(double)((pJVar6->parent).mPosTL.y - 3_0));
  pJVar6 = param_1->field_0x618;
  (*(code *)((pJVar6->parent).vtbl)->move)
            ((double)(pJVar6->parent).mPosTL.x,(double)((pJVar6->parent).mPosTL.y - 3_0));
  J2DTextBox::setFont(param_1->field_0x60c,font0);
  J2DTextBox::setFont(param_1->field_0x610,font1);
  J2DTextBox::setFont(param_1->field_0x614,font0);
  J2DTextBox::setFont(param_1->field_0x618,font1);
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U) - _4142);
  fVar2 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U) - _4142);
  pJVar6 = param_1->field_0x60c;
  fVar3 = 0_0;
  if (0_0 < fVar1) {
    fVar3 = fVar1;
  }
  pJVar6->mFontWidth = fVar3;
  fVar3 = 0_0;
  if (0_0 < fVar2) {
    fVar3 = fVar2;
  }
  pJVar6->mFontHeight = fVar3;
  pJVar6 = param_1->field_0x614;
  fVar3 = 0_0;
  if (0_0 < fVar1) {
    fVar3 = fVar1;
  }
  pJVar6->mFontWidth = fVar3;
  fVar1 = 0_0;
  if (0_0 < fVar2) {
    fVar1 = fVar2;
  }
  pJVar6->mFontHeight = fVar1;
  fVar1 = 0_0;
  param_1->field_0x60c->field_0xe0 = 0_0;
  param_1->field_0x610->field_0xe0 = fVar1;
  param_1->field_0x614->field_0xe0 = fVar1;
  param_1->field_0x618->field_0xe0 = fVar1;
  fVar1 = _4243;
  param_1->field_0x60c->mFontLeading = _4243;
  param_1->field_0x614->mFontLeading = fVar1;
  f_op_msg_mng::fopMsgM_blendInit(&param_1->field_0x13c,"rupy_num_01.bti");
  f_op_msg_mng::fopMsgM_blendInit(&param_1->field_0x1ac,"rupy_num_01.bti");
  return;
}


/* __stdcall dScp_valueInit(sub_scp_class *) */

void dScp_valueInit(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined local_18;
  undefined uStack23;
  undefined uStack22;
  undefined uStack21;
  undefined local_14;
  undefined uStack19;
  undefined uStack18;
  undefined uStack17;
  
  if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5be5 == 1) {
    *(undefined2 *)(param_1 + 0xf8) = 3;
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = 3;
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5be5 == 2) {
      *(undefined2 *)(param_1 + 0xf8) = 4;
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = 4;
    }
    else {
      *(undefined2 *)(param_1 + 0xf8) = 2;
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = 2;
    }
  }
  d_com_inf_game::g_dComIfG_gameInfo._23497_1_ = 5;
  *(undefined2 *)(param_1 + 0x914) = 0;
  fVar1 = 0_0;
  *(float *)(param_1 + 0x904) = 0_0;
  *(float *)(param_1 + 0x908) = fVar1;
  *(float *)(param_1 + 0x910) = 1_0;
  dScp_wipeAngleCalc(param_1);
  *(undefined4 *)(param_1 + 0x8e4) = *(undefined4 *)(*(int *)(param_1 + 0x60c) + 0xe8);
  *(undefined4 *)(param_1 + 0x8e8) = *(undefined4 *)(*(int *)(param_1 + 0x60c) + 0xec);
  *(undefined4 *)(param_1 + 0x8ec) = *(undefined4 *)(*(int *)(param_1 + 0x610) + 0xe8);
  *(undefined4 *)(param_1 + 0x8f0) = *(undefined4 *)(*(int *)(param_1 + 0x610) + 0xec);
  *(undefined4 *)(*(int *)(param_1 + 0x610) + 0xe4) =
       *(undefined4 *)(*(int *)(param_1 + 0x60c) + 0xe4);
  *(undefined4 *)(*(int *)(param_1 + 0x618) + 0xe4) =
       *(undefined4 *)(*(int *)(param_1 + 0x60c) + 0xe4);
  *(int *)(param_1 + 0x90c) = (int)(*(float *)(param_1 + 0x5a4) + *(float *)(param_1 + 0x5c4));
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x5d4) + 0x108);
  local_14 = (undefined)((uint)uVar2 >> 0x18);
  *(undefined *)(param_1 + 0x8f4) = local_14;
  uStack19 = (undefined)((uint)uVar2 >> 0x10);
  *(undefined *)(param_1 + 0x8f5) = uStack19;
  uStack18 = (undefined)((uint)uVar2 >> 8);
  *(undefined *)(param_1 + 0x8f6) = uStack18;
  uStack17 = (undefined)uVar2;
  *(undefined *)(param_1 + 0x8f7) = uStack17;
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x5d4) + 0x104);
  local_18 = (undefined)((uint)uVar2 >> 0x18);
  *(undefined *)(param_1 + 0x8fc) = local_18;
  uStack23 = (undefined)((uint)uVar2 >> 0x10);
  *(undefined *)(param_1 + 0x8fd) = uStack23;
  uStack22 = (undefined)((uint)uVar2 >> 8);
  *(undefined *)(param_1 + 0x8fe) = uStack22;
  uStack21 = (undefined)uVar2;
  *(undefined *)(param_1 + 0x8ff) = uStack21;
  *(undefined *)(param_1 + 0x8f8) = *(undefined *)(param_1 + 0x8f4);
  *(undefined *)(param_1 + 0x8f9) = *(undefined *)(param_1 + 0x8f5);
  *(undefined *)(param_1 + 0x8fa) = *(undefined *)(param_1 + 0x8f6);
  *(undefined *)(param_1 + 0x8fb) = *(undefined *)(param_1 + 0x8f7);
  *(undefined *)(param_1 + 0x900) = *(undefined *)(param_1 + 0x8fc);
  *(undefined *)(param_1 + 0x901) = *(undefined *)(param_1 + 0x8fd);
  *(undefined *)(param_1 + 0x902) = *(undefined *)(param_1 + 0x8fe);
  *(undefined *)(param_1 + 0x903) = *(undefined *)(param_1 + 0x8ff);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dScp_setAlpha(sub_scp_class *) */

void dScp_setAlpha(int param_1)

{
  int iVar1;
  int iVar2;
  
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x104));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x13c));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x174));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x1ac));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x1e4));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x21c));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x254));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x28c));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x2c4));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x2fc));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x334));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x36c));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x3a4));
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + iVar2 + 0x3dc));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 8);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x59c));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x5d4));
  return;
}


/* WARNING: Removing unreachable block (ram,0x802384d8) */
/* WARNING: Removing unreachable block (ram,0x802384c8) */
/* WARNING: Removing unreachable block (ram,0x802384c0) */
/* WARNING: Removing unreachable block (ram,0x802384d0) */
/* WARNING: Removing unreachable block (ram,0x802384e0) */
/* __stdcall dScp_wipeAngleCalc(sub_scp_class *) */

void dScp_wipeAngleCalc(sub_scp_class *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  J2DPicture *pJVar3;
  J2DScreen *pJVar4;
  undefined4 uVar5;
  undefined8 in_f27;
  double dVar6;
  undefined8 in_f28;
  double dVar7;
  undefined8 in_f29;
  double dVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  char acStack184 [16];
  longlong local_a8;
  longlong local_a0;
  undefined4 local_98;
  uint uStack148;
  longlong local_90;
  undefined4 local_88;
  uint uStack132;
  longlong local_80;
  undefined4 local_78;
  uint uStack116;
  longlong local_70;
  undefined4 local_68;
  uint uStack100;
  undefined auStack72 [16];
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
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  dVar10 = (double)(_4349 + d_s_play::g_regHIO.mChild[6].mFloats[4]);
  dVar9 = (double)(_4350 + d_s_play::g_regHIO.mChild[6].mFloats[0]);
  dVar8 = (double)(_4351 + d_s_play::g_regHIO.mChild[6].mFloats[1]);
  dVar6 = (double)(d_s_play::g_regHIO.mChild[6].mFloats[3] +
                  (_4352 - ((param_1->field_0x21c).mPosTopLeftOrig.x +
                           (param_1->field_0x21c).mSizeOrig.x)));
  dVar7 = (double)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0xc;
  if ((double)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0xc < (double)1_0) {
    dVar7 = (double)1_0;
  }
  if ((double)_4353 < dVar7) {
    dVar7 = (double)_4353;
  }
  if (dVar7 != (double)param_1->field_0x910) {
    if ((((double)1_0 == dVar7) || ((double)_4354 == dVar7)) || ((double)_4353 == dVar7)) {
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x809,(cXyz *)0x0,0,0,1_0,1_0,_1_0,_1_0,0);
    }
    else {
      uVar1 = Runtime.PPCEABI.H::__cvt_fp2unsigned
                        ((double)(0_5 + _4356 * d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo
                                                [0].field_0x10));
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,8,(cXyz *)0x0,uVar1,0,1_0,1_0,_1_0,_1_0,0);
    }
    param_1->field_0x910 = (float)dVar7;
  }
  dVar10 = (double)((float)((double)_4242 * dVar10) -
                   (float)(dVar10 * (double)(float)(dVar7 - (double)1_0)));
  uVar2 = m_Do_ext::mDoExt_setCurrentHeap(param_1->mpHeap);
  local_a8 = (longlong)(int)dVar7;
  MSL_C.PPCEABI.bare.H::sprintf(acStack184,"rupy_num_%02d.bti",(int)(short)(int)dVar7);
  pJVar3 = (J2DPicture *)(param_1->field_0x13c).mpPane;
  J2DPicture::remove(pJVar3,(char *)(pJVar3->mNumTexture - 1 & 0xff));
  pJVar3 = (J2DPicture *)(param_1->field_0x13c).mpPane;
  J2DPicture::insert(pJVar3,acStack184,pJVar3->mNumTexture,1_0);
  pJVar3 = (J2DPicture *)(param_1->field_0x1ac).mpPane;
  J2DPicture::remove(pJVar3,(char *)(pJVar3->mNumTexture - 1 & 0xff));
  pJVar3 = (J2DPicture *)(param_1->field_0x1ac).mpPane;
  J2DPicture::insert(pJVar3,acStack184,pJVar3->mNumTexture,1_0);
  m_Do_ext::mDoExt_setCurrentHeap(uVar2);
  uStack148 = (uint)((double)((param_1->field_0x21c).mSizeOrig.y * 0_5) + dVar8);
  local_a0 = (longlong)(int)uStack148;
  uStack148 = uStack148 ^ 0x80000000;
  local_98 = 0x43300000;
  dVar7 = (double)CONCAT44(0x43300000,uStack148) - _4142;
  pJVar4 = (param_1->field_0x21c).mpPane;
  local_90 = (longlong)(int)(dVar6 - dVar9);
  uStack132 = (int)(dVar6 - dVar9) ^ 0x80000000;
  local_88 = 0x43300000;
  (pJVar4->parent).mBasePosition.x = (float)((double)CONCAT44(0x43300000,uStack132) - _4142);
  (pJVar4->parent).mBasePosition.y = (float)dVar7;
  (pJVar4->parent).mRotationAxis = 'z';
  (pJVar4->parent).mRotation = (float)dVar10;
  (*(code *)((pJVar4->parent).vtbl)->calcMtx)();
  uStack116 = (uint)((param_1->field_0x1e4).mSizeOrig.y * 0_5);
  local_80 = (longlong)(int)uStack116;
  uStack116 = uStack116 ^ 0x80000000;
  local_78 = 0x43300000;
  dVar7 = (double)CONCAT44(0x43300000,uStack116) - _4142;
  pJVar4 = (param_1->field_0x1e4).mpPane;
  uStack100 = (uint)((param_1->field_0x1e4).mSizeOrig.x * 0_5);
  local_70 = (longlong)(int)uStack100;
  uStack100 = uStack100 ^ 0x80000000;
  local_68 = 0x43300000;
  (pJVar4->parent).mBasePosition.x = (float)((double)CONCAT44(0x43300000,uStack100) - _4142);
  (pJVar4->parent).mBasePosition.y = (float)dVar7;
  (pJVar4->parent).mRotationAxis = 'z';
  (pJVar4->parent).mRotation = (float)-dVar10;
  (*(code *)((pJVar4->parent).vtbl)->calcMtx)();
  dScp_ArrowAnime(param_1);
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  __psq_l0(auStack56,uVar5);
  __psq_l1(auStack56,uVar5);
  __psq_l0(auStack72,uVar5);
  __psq_l1(auStack72,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802389c8) */
/* WARNING: Removing unreachable block (ram,0x802389d0) */
/* __stdcall dScp_ArrowAnime(sub_scp_class *) */

void dScp_ArrowAnime(sub_scp_class *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  J2DPicture *pJVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  (param_1->field_0x2fc).mUserData = (param_1->field_0x2fc).mUserData + 1;
  iVar3 = (int)(param_1->field_0x2fc).mUserData;
  if (iVar3 < 10) {
    dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x14,iVar3,0);
    pJVar4 = (J2DPicture *)(param_1->field_0x28c).mpPane;
    pJVar4->mBlendKonstColorF[0] = 0_0;
    fVar2 = 1_0;
    pJVar4->mBlendKonstColorF[1] = 1_0;
    pJVar4->mBlendKonstColorF[2] = fVar2;
    pJVar4->mBlendKonstColorF[3] = fVar2;
    J2DPicture::setBlendKonstColor(pJVar4);
    pJVar4->mBlendKonstAlphaF[0] = 0_0;
    fVar2 = 1_0;
    pJVar4->mBlendKonstAlphaF[1] = 1_0;
    pJVar4->mBlendKonstAlphaF[2] = fVar2;
    pJVar4->mBlendKonstAlphaF[3] = fVar2;
    J2DPicture::setBlendKonstAlpha(pJVar4);
    pJVar4 = (J2DPicture *)(param_1->field_0x2c4).mpPane;
    pJVar4->mBlendKonstColorF[0] = 0_0;
    fVar2 = 1_0;
    pJVar4->mBlendKonstColorF[1] = 1_0;
    pJVar4->mBlendKonstColorF[2] = fVar2;
    pJVar4->mBlendKonstColorF[3] = fVar2;
    J2DPicture::setBlendKonstColor(pJVar4);
    pJVar4->mBlendKonstAlphaF[0] = 0_0;
    fVar2 = 1_0;
    pJVar4->mBlendKonstAlphaF[1] = 1_0;
    pJVar4->mBlendKonstAlphaF[2] = fVar2;
    pJVar4->mBlendKonstAlphaF[3] = fVar2;
    J2DPicture::setBlendKonstAlpha(pJVar4);
    fVar2 = 1_0;
    dVar7 = (double)1_0;
    if ((dVar7 != (double)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0xc) &&
       ((param_1->field_0x28c).mUserData == 0)) {
      pJVar4 = (J2DPicture *)(param_1->field_0x2fc).mpPane;
      pJVar4->mBlendKonstColorF[0] = (float)dVar6;
      fVar1 = (float)(dVar7 - dVar6);
      dVar7 = (double)fVar1;
      pJVar4->mBlendKonstColorF[1] = fVar1;
      pJVar4->mBlendKonstColorF[2] = fVar2;
      pJVar4->mBlendKonstColorF[3] = fVar2;
      J2DPicture::setBlendKonstColor(pJVar4);
      pJVar4->mBlendKonstAlphaF[0] = (float)dVar6;
      pJVar4->mBlendKonstAlphaF[1] = (float)dVar7;
      fVar2 = 1_0;
      pJVar4->mBlendKonstAlphaF[2] = 1_0;
      pJVar4->mBlendKonstAlphaF[3] = fVar2;
      J2DPicture::setBlendKonstAlpha(pJVar4);
      f_op_msg_mng::fopMsgM_paneTrans(&param_1->field_0x28c,(double)0_0,(double)_4480);
    }
    if ((_4353 != d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0xc) &&
       ((param_1->field_0x2c4).mUserData == 0)) {
      f_op_msg_mng::fopMsgM_paneTrans(&param_1->field_0x2c4,(double)0_0,(double)_4481);
      pJVar4 = (J2DPicture *)(param_1->field_0x334).mpPane;
      pJVar4->mBlendKonstColorF[0] = (float)dVar6;
      fVar2 = 1_0;
      dVar7 = (double)(float)((double)1_0 - dVar6);
      pJVar4->mBlendKonstColorF[1] = (float)((double)1_0 - dVar6);
      pJVar4->mBlendKonstColorF[2] = fVar2;
      pJVar4->mBlendKonstColorF[3] = fVar2;
      J2DPicture::setBlendKonstColor(pJVar4);
      pJVar4->mBlendKonstAlphaF[0] = (float)dVar6;
      pJVar4->mBlendKonstAlphaF[1] = (float)dVar7;
      fVar2 = 1_0;
      pJVar4->mBlendKonstAlphaF[2] = 1_0;
      pJVar4->mBlendKonstAlphaF[3] = fVar2;
      J2DPicture::setBlendKonstAlpha(pJVar4);
    }
  }
  else {
    dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x14,iVar3 + -10,0);
    fVar2 = 1_0;
    pJVar4 = (J2DPicture *)(param_1->field_0x28c).mpPane;
    pJVar4->mBlendKonstColorF[0] = 1_0;
    pJVar4->mBlendKonstColorF[1] = 0_0;
    pJVar4->mBlendKonstColorF[2] = fVar2;
    pJVar4->mBlendKonstColorF[3] = fVar2;
    J2DPicture::setBlendKonstColor(pJVar4);
    fVar2 = 1_0;
    pJVar4->mBlendKonstAlphaF[0] = 1_0;
    pJVar4->mBlendKonstAlphaF[1] = 0_0;
    pJVar4->mBlendKonstAlphaF[2] = fVar2;
    pJVar4->mBlendKonstAlphaF[3] = fVar2;
    J2DPicture::setBlendKonstAlpha(pJVar4);
    fVar2 = 1_0;
    pJVar4 = (J2DPicture *)(param_1->field_0x2c4).mpPane;
    pJVar4->mBlendKonstColorF[0] = 1_0;
    pJVar4->mBlendKonstColorF[1] = 0_0;
    pJVar4->mBlendKonstColorF[2] = fVar2;
    pJVar4->mBlendKonstColorF[3] = fVar2;
    J2DPicture::setBlendKonstColor(pJVar4);
    fVar2 = 1_0;
    pJVar4->mBlendKonstAlphaF[0] = 1_0;
    pJVar4->mBlendKonstAlphaF[1] = 0_0;
    pJVar4->mBlendKonstAlphaF[2] = fVar2;
    pJVar4->mBlendKonstAlphaF[3] = fVar2;
    J2DPicture::setBlendKonstAlpha(pJVar4);
    fVar2 = 1_0;
    dVar7 = (double)1_0;
    if (dVar7 == (double)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0xc) {
      if ((param_1->field_0x28c).mUserData == 0) {
        pJVar4 = (J2DPicture *)(param_1->field_0x2fc).mpPane;
        dVar8 = (double)(float)(dVar7 - dVar6);
        pJVar4->mBlendKonstColorF[0] = (float)(dVar7 - dVar6);
        pJVar4->mBlendKonstColorF[1] = (float)dVar6;
        pJVar4->mBlendKonstColorF[2] = fVar2;
        pJVar4->mBlendKonstColorF[3] = fVar2;
        J2DPicture::setBlendKonstColor(pJVar4);
        pJVar4->mBlendKonstAlphaF[0] = (float)dVar8;
        pJVar4->mBlendKonstAlphaF[1] = (float)dVar6;
        fVar2 = 1_0;
        pJVar4->mBlendKonstAlphaF[2] = 1_0;
        pJVar4->mBlendKonstAlphaF[3] = fVar2;
        J2DPicture::setBlendKonstAlpha(pJVar4);
        f_op_msg_mng::fopMsgM_paneTrans(&param_1->field_0x28c,(double)0_0,(double)0_0);
      }
      else {
        if ((param_1->field_0x2fc).mUserData == 0x14) {
          (param_1->field_0x28c).mUserData = 1;
        }
      }
    }
    else {
      if ((param_1->field_0x28c).mUserData == 0) {
        pJVar4 = (J2DPicture *)(param_1->field_0x2fc).mpPane;
        dVar8 = (double)(float)(dVar7 - dVar6);
        pJVar4->mBlendKonstColorF[0] = (float)(dVar7 - dVar6);
        pJVar4->mBlendKonstColorF[1] = (float)dVar6;
        pJVar4->mBlendKonstColorF[2] = fVar2;
        pJVar4->mBlendKonstColorF[3] = fVar2;
        J2DPicture::setBlendKonstColor(pJVar4);
        pJVar4->mBlendKonstAlphaF[0] = (float)dVar8;
        pJVar4->mBlendKonstAlphaF[1] = (float)dVar6;
        fVar2 = 1_0;
        pJVar4->mBlendKonstAlphaF[2] = 1_0;
        pJVar4->mBlendKonstAlphaF[3] = fVar2;
        J2DPicture::setBlendKonstAlpha(pJVar4);
        f_op_msg_mng::fopMsgM_paneTrans(&param_1->field_0x28c,(double)0_0,(double)0_0);
      }
      if ((param_1->field_0x2fc).mUserData == 0x14) {
        (param_1->field_0x28c).mUserData = 0;
      }
    }
    if (_4353 == d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0xc) {
      if ((param_1->field_0x2c4).mUserData == 0) {
        f_op_msg_mng::fopMsgM_paneTrans(&param_1->field_0x2c4,(double)0_0,(double)0_0);
        fVar2 = 1_0;
        pJVar4 = (J2DPicture *)(param_1->field_0x334).mpPane;
        dVar7 = (double)(float)((double)1_0 - dVar6);
        pJVar4->mBlendKonstColorF[0] = (float)((double)1_0 - dVar6);
        pJVar4->mBlendKonstColorF[1] = (float)dVar6;
        pJVar4->mBlendKonstColorF[2] = fVar2;
        pJVar4->mBlendKonstColorF[3] = fVar2;
        J2DPicture::setBlendKonstColor(pJVar4);
        pJVar4->mBlendKonstAlphaF[0] = (float)dVar7;
        pJVar4->mBlendKonstAlphaF[1] = (float)dVar6;
        fVar2 = 1_0;
        pJVar4->mBlendKonstAlphaF[2] = 1_0;
        pJVar4->mBlendKonstAlphaF[3] = fVar2;
        J2DPicture::setBlendKonstAlpha(pJVar4);
      }
      else {
        if ((param_1->field_0x2fc).mUserData == 0x14) {
          (param_1->field_0x2c4).mUserData = 1;
        }
      }
    }
    else {
      if ((param_1->field_0x2c4).mUserData == 0) {
        f_op_msg_mng::fopMsgM_paneTrans(&param_1->field_0x2c4,(double)0_0,(double)0_0);
        fVar2 = 1_0;
        pJVar4 = (J2DPicture *)(param_1->field_0x334).mpPane;
        dVar7 = (double)(float)((double)1_0 - dVar6);
        pJVar4->mBlendKonstColorF[0] = (float)((double)1_0 - dVar6);
        pJVar4->mBlendKonstColorF[1] = (float)dVar6;
        pJVar4->mBlendKonstColorF[2] = fVar2;
        pJVar4->mBlendKonstColorF[3] = fVar2;
        J2DPicture::setBlendKonstColor(pJVar4);
        pJVar4->mBlendKonstAlphaF[0] = (float)dVar7;
        pJVar4->mBlendKonstAlphaF[1] = (float)dVar6;
        fVar2 = 1_0;
        pJVar4->mBlendKonstAlphaF[2] = 1_0;
        pJVar4->mBlendKonstAlphaF[3] = fVar2;
        J2DPicture::setBlendKonstAlpha(pJVar4);
      }
      if ((param_1->field_0x2fc).mUserData == 0x14) {
        (param_1->field_0x2c4).mUserData = 0;
      }
    }
  }
  if (1_0 == d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0xc) {
    (((param_1->field_0x28c).mpPane)->parent).mbDraw = 0;
    (((param_1->field_0x2c4).mpPane)->parent).mbDraw = 1;
  }
  else {
    if (_4353 == d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0xc) {
      (((param_1->field_0x28c).mpPane)->parent).mbDraw = 1;
      (((param_1->field_0x2c4).mpPane)->parent).mbDraw = 0;
    }
    else {
      (((param_1->field_0x28c).mpPane)->parent).mbDraw = 1;
      (((param_1->field_0x2c4).mpPane)->parent).mbDraw = 1;
    }
  }
  if (0x13 < (param_1->field_0x2fc).mUserData) {
    (param_1->field_0x2fc).mUserData = 0;
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80238b90) */
/* WARNING: Removing unreachable block (ram,0x80238b98) */
/* __stdcall dScp_wipeMove(sub_scp_class *,
                           float) */

void dScp_wipeMove(double param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar5;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (param_1 < (double)1_0) {
    param_1 = (double)1_0;
  }
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18616_4_ = (float)param_1;
  dVar5 = (double)(float)(param_1 - (double)1_0);
  iVar2 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneScaleXY
              ((fopMsgM_pane_class *)(param_2 + iVar3 + 0x3dc),(float)param_1);
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar2 < 8);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(param_2 + 0x3dc),
             -(double)(float)((double)(*(float *)(param_2 + 0x400) * 0_5) * dVar5),
             -(double)(float)((double)(*(float *)(param_2 + 0x404) * 0_5) * dVar5));
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(param_2 + 0x414),
             (double)(float)((double)(*(float *)(param_2 + 0x438) * 0_5) * dVar5),
             -(double)(float)((double)(*(float *)(param_2 + 0x43c) * 0_5) * dVar5));
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(param_2 + 0x44c),
             -(double)(float)((double)(*(float *)(param_2 + 0x470) * 0_5) * dVar5),
             (double)(float)((double)(*(float *)(param_2 + 0x474) * 0_5) * dVar5));
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(param_2 + 0x484),
             (double)(float)((double)(*(float *)(param_2 + 0x4a8) * 0_5) * dVar5),
             (double)(float)((double)(*(float *)(param_2 + 0x4ac) * 0_5) * dVar5));
  fVar1 = 0_5;
  *(float *)(param_2 + 0x4dc) = *(float *)(param_2 + 0x3ec) - *(float *)(param_2 + 0x4ec) * 0_5;
  *(float *)(param_2 + 0x514) =
       *(float *)(param_2 + 0x524) * fVar1 +
       *(float *)(param_2 + 0x494) + *(float *)(param_2 + 0x4b4);
  *(float *)(param_2 + 0x548) = *(float *)(param_2 + 1000) - *(float *)(param_2 + 0x558) * fVar1;
  *(float *)(param_2 + 0x580) =
       *(float *)(param_2 + 0x590) * fVar1 +
       *(float *)(param_2 + 0x490) + *(float *)(param_2 + 0x4b0);
  iVar2 = 4;
  iVar3 = 0xe0;
  do {
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_2 + iVar3 + 0x3dc));
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar2 < 8);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80238df8) */
/* WARNING: Removing unreachable block (ram,0x80238e00) */
/* __stdcall dScp_wipeMove2(sub_scp_class *,
                            float) */

void dScp_wipeMove2(double param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar5;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18616_4_ = (float)param_1;
  dVar5 = (double)(float)(param_1 - (double)1_0);
  iVar2 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneScaleXY
              ((fopMsgM_pane_class *)(param_2 + iVar3 + 0x3dc),(float)param_1);
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar2 < 4);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(param_2 + 0x3dc),
             -(double)(float)((double)(*(float *)(param_2 + 0x400) * 0_5) * dVar5),
             -(double)(float)((double)(*(float *)(param_2 + 0x404) * 0_5) * dVar5));
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(param_2 + 0x414),
             (double)(float)((double)(*(float *)(param_2 + 0x438) * 0_5) * dVar5),
             -(double)(float)((double)(*(float *)(param_2 + 0x43c) * 0_5) * dVar5));
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(param_2 + 0x44c),
             -(double)(float)((double)(*(float *)(param_2 + 0x470) * 0_5) * dVar5),
             (double)(float)((double)(*(float *)(param_2 + 0x474) * 0_5) * dVar5));
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(param_2 + 0x484),
             (double)(float)((double)(*(float *)(param_2 + 0x4a8) * 0_5) * dVar5),
             (double)(float)((double)(*(float *)(param_2 + 0x4ac) * 0_5) * dVar5));
  if (param_1 < (double)1_0) {
    *(undefined4 *)(param_2 + 0x4e8) = *(undefined4 *)(param_2 + 0x4e0);
    fVar1 = _4532;
    *(float *)(param_2 + 0x4ec) =
         _4532 * (*(float *)(param_2 + 0x3ec) - *(float *)(param_2 + 0x4d4));
    *(undefined4 *)(param_2 + 0x520) = *(undefined4 *)(param_2 + 0x518);
    *(float *)(param_2 + 0x524) =
         fVar1 * (*(float *)(param_2 + 0x50c) - *(float *)(param_2 + 0x494));
    *(float *)(param_2 + 0x558) = fVar1 * (*(float *)(param_2 + 1000) - *(float *)(param_2 + 0x540))
    ;
    *(undefined4 *)(param_2 + 0x55c) = *(undefined4 *)(param_2 + 0x554);
    *(float *)(param_2 + 0x590) =
         fVar1 * (*(float *)(param_2 + 0x578) - *(float *)(param_2 + 0x490));
    *(undefined4 *)(param_2 + 0x594) = *(undefined4 *)(param_2 + 0x58c);
  }
  else {
    iVar2 = 4;
    iVar3 = 0xe0;
    do {
      f_op_msg_mng::fopMsgM_paneScaleXY
                ((fopMsgM_pane_class *)(param_2 + iVar3 + 0x3dc),(float)param_1);
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar2 < 8);
  }
  fVar1 = 0_5;
  *(float *)(param_2 + 0x4dc) = *(float *)(param_2 + 0x3ec) - *(float *)(param_2 + 0x4ec) * 0_5;
  *(float *)(param_2 + 0x514) =
       *(float *)(param_2 + 0x524) * fVar1 +
       *(float *)(param_2 + 0x494) + *(float *)(param_2 + 0x4b4);
  *(float *)(param_2 + 0x548) = *(float *)(param_2 + 1000) - *(float *)(param_2 + 0x558) * fVar1;
  *(float *)(param_2 + 0x580) =
       *(float *)(param_2 + 0x590) * fVar1 +
       *(float *)(param_2 + 0x490) + *(float *)(param_2 + 0x4b0);
  iVar2 = 4;
  iVar3 = 0xe0;
  do {
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_2 + iVar3 + 0x3dc));
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar2 < 8);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80239034) */
/* WARNING: Removing unreachable block (ram,0x8023902c) */
/* WARNING: Removing unreachable block (ram,0x8023903c) */
/* __stdcall dScp_wipeMoveDemo(sub_scp_class *,
                               float,
                               bool) */

void dScp_wipeMoveDemo(double param_1,int param_2,char param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar6;
  undefined8 in_f31;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  dVar5 = (double)1_0;
  dVar6 = (double)((float)(param_1 - dVar5) / (float)((double)DAT_803e6930 - dVar5));
  if (param_3 != '\0') {
    dVar6 = dVar5;
  }
  dVar5 = (double)(*(float *)(param_2 + 0x488) -
                  (float)((double)(*(float *)(param_2 + 0x488) - _4551) * dVar6));
  dVar6 = (double)(*(float *)(param_2 + 0x48c) -
                  (float)((double)(*(float *)(param_2 + 0x48c) - _4552) * dVar6));
  iVar2 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneScaleXY
              ((fopMsgM_pane_class *)(param_2 + iVar3 + 0x3dc),(float)param_1);
    fVar1 = 0_5;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar2 < 8);
  *(float *)(param_2 + 0x3f8) = (float)(dVar5 - (double)(*(float *)(param_2 + 0x408) * 0_5));
  *(float *)(param_2 + 0x3fc) = (float)(dVar6 - (double)(*(float *)(param_2 + 0x40c) * fVar1));
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_2 + 0x3dc));
  fVar1 = 0_5;
  *(float *)(param_2 + 0x430) = (float)(dVar5 + (double)(*(float *)(param_2 + 0x440) * 0_5));
  *(float *)(param_2 + 0x434) = (float)(dVar6 - (double)(*(float *)(param_2 + 0x444) * fVar1));
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_2 + 0x414));
  fVar1 = 0_5;
  *(float *)(param_2 + 0x468) = (float)(dVar5 - (double)(*(float *)(param_2 + 0x478) * 0_5));
  *(float *)(param_2 + 0x46c) = (float)(dVar6 + (double)(*(float *)(param_2 + 0x47c) * fVar1));
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_2 + 0x44c));
  fVar1 = 0_5;
  *(float *)(param_2 + 0x4a0) = (float)(dVar5 + (double)(*(float *)(param_2 + 0x4b0) * 0_5));
  *(float *)(param_2 + 0x4a4) = (float)(dVar6 + (double)(*(float *)(param_2 + 0x4b4) * fVar1));
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_2 + 0x484));
  fVar1 = 0_5;
  *(float *)(param_2 + 0x4dc) = *(float *)(param_2 + 0x3ec) - *(float *)(param_2 + 0x4ec) * 0_5;
  *(float *)(param_2 + 0x514) =
       *(float *)(param_2 + 0x524) * fVar1 +
       *(float *)(param_2 + 0x494) + *(float *)(param_2 + 0x4b4);
  *(float *)(param_2 + 0x548) = *(float *)(param_2 + 1000) - *(float *)(param_2 + 0x558) * fVar1;
  *(float *)(param_2 + 0x54c) = *(float *)(param_2 + 0x3ec) + *(float *)(param_2 + 0x55c) * fVar1;
  *(float *)(param_2 + 0x580) =
       *(float *)(param_2 + 0x590) * fVar1 +
       *(float *)(param_2 + 0x420) + *(float *)(param_2 + 0x440);
  *(float *)(param_2 + 0x584) = *(float *)(param_2 + 0x424) + *(float *)(param_2 + 0x594) * fVar1;
  iVar2 = 4;
  iVar3 = 0xe0;
  do {
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_2 + iVar3 + 0x3dc));
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar2 < 8);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  return;
}


/* __stdcall dScp_mesgPaneShow(sub_scp_class *) */

void dScp_mesgPaneShow(int param_1)

{
  *(undefined *)(*(int *)(param_1 + 0x60c) + 0xaa) = 1;
  *(undefined *)(*(int *)(param_1 + 0x610) + 0xaa) = 1;
  *(undefined *)(*(int *)(param_1 + 0x614) + 0xaa) = 1;
  *(undefined *)(*(int *)(param_1 + 0x618) + 0xaa) = 1;
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x8023915c) */
/* __stdcall dScp_mesgPaneHide(sub_scp_class *) */

void dScp_mesgPaneHide(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 in_f31;
  double dVar7;
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  *(undefined *)(*(int *)(param_1 + 0x60c) + 0xaa) = 0;
  *(undefined *)(*(int *)(param_1 + 0x610) + 0xaa) = 0;
  *(undefined *)(*(int *)(param_1 + 0x614) + 0xaa) = 0;
  *(undefined *)(*(int *)(param_1 + 0x618) + 0xaa) = 0;
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
  iVar3 = 0;
  iVar5 = 0;
  iVar4 = 0;
  dVar7 = (double)0_0;
  do {
    *(undefined *)(*(int *)((int)sbutton_icon + iVar4) + 0xaa) = 0;
    *(undefined *)(*(int *)((int)sbutton_kage + iVar4) + 0xaa) = 0;
    piVar2 = *(int **)((int)sbutton_icon + iVar4);
    piVar2[0x29] = (int)(float)dVar7;
    (**(code **)(*piVar2 + 0x20))();
    piVar2 = *(int **)((int)sbutton_kage + iVar4);
    piVar2[0x29] = (int)(float)dVar7;
    (**(code **)(*piVar2 + 0x20))();
    *(undefined2 *)((int)&sbuttonTimer + iVar5) = 0xffff;
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 2;
    iVar4 = iVar4 + 4;
  } while (iVar3 < 8);
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return;
}


/* __stdcall dScp_scopeAlpha(sub_scp_class *,
                             float) */

void dScp_scopeAlpha(double param_1,int param_2)

{
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_2 + 0x104),(float)param_1);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_2 + 0x13c),(float)param_1);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_2 + 0x174),(float)param_1);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_2 + 0x1ac),(float)param_1);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_2 + 0x1e4),(float)param_1);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_2 + 0x21c),(float)param_1);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_2 + 0x254),(float)param_1);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_2 + 0x28c),(float)param_1);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_2 + 0x2c4),(float)param_1);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_2 + 0x2fc),(float)param_1);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_2 + 0x334),(float)param_1);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_2 + 0x36c),(float)param_1);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_2 + 0x3a4),(float)param_1);
  return;
}


/* __stdcall dScp_scopeInitAlpha(sub_scp_class *) */

void dScp_scopeInitAlpha(sub_scp_class *param_1)

{
  f_op_msg_mng::fopMsgM_setInitAlpha(&param_1->field_0x104);
  f_op_msg_mng::fopMsgM_setInitAlpha(&param_1->field_0x13c);
  f_op_msg_mng::fopMsgM_setInitAlpha(&param_1->field_0x174);
  f_op_msg_mng::fopMsgM_setInitAlpha(&param_1->field_0x1ac);
  f_op_msg_mng::fopMsgM_setInitAlpha(&param_1->field_0x1e4);
  f_op_msg_mng::fopMsgM_setInitAlpha(&param_1->field_0x21c);
  f_op_msg_mng::fopMsgM_setInitAlpha(&param_1->field_0x254);
  f_op_msg_mng::fopMsgM_setInitAlpha(&param_1->field_0x28c);
  f_op_msg_mng::fopMsgM_setInitAlpha(&param_1->field_0x2c4);
  f_op_msg_mng::fopMsgM_setInitAlpha(&param_1->field_0x2fc);
  f_op_msg_mng::fopMsgM_setInitAlpha(&param_1->field_0x334);
  f_op_msg_mng::fopMsgM_setInitAlpha(&param_1->field_0x36c);
  f_op_msg_mng::fopMsgM_setInitAlpha(&param_1->field_0x3a4);
  return;
}


/* __stdcall dScp_scopeAlphaZero(sub_scp_class *) */

void dScp_scopeAlphaZero(int param_1)

{
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x104));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x13c));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x174));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x1ac));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x1e4));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x21c));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x254));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x28c));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2c4));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2fc));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x334));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x36c));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x3a4));
  return;
}


/* __stdcall dScp_stringInit(sub_scp_class *) */

void dScp_stringInit(int param_1)

{
  undefined4 uVar1;
  char acStack72 [28];
  char acStack44 [36];
  
  uVar1 = f_op_msg_mng::fopMsgM_getColorTable(0);
  MSL_C.PPCEABI.bare.H::sprintf(acStack44,"\x1bCC[%08x]\x1bGM[0]",uVar1);
  MSL_C.PPCEABI.bare.H::sprintf(acStack72,"\x1bCC[000000FF]\x1bGM[0]");
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(param_1 + 0x920),acStack44);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(param_1 + 0x924),acStack44);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(param_1 + 0x928),acStack72);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(param_1 + 0x92c),acStack72);
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  *(undefined2 *)(param_1 + 0x916) = 0;
  return;
}


/* __stdcall dScp_stringSet(sub_scp_class *) */

void dScp_stringSet(int param_1,undefined4 param_2,___ param_3)

{
  undefined4 uVar1;
  
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
  J2DTextBox::setString(*(J2DTextBox **)(param_1 + 0x60c),*(char **)(param_1 + 0x920),param_3);
  J2DTextBox::setString(*(J2DTextBox **)(param_1 + 0x610),*(char **)(param_1 + 0x924),param_3);
  J2DTextBox::setString(*(J2DTextBox **)(param_1 + 0x614),*(char **)(param_1 + 0x928),param_3);
  J2DTextBox::setString(*(J2DTextBox **)(param_1 + 0x618),*(char **)(param_1 + 0x92c),param_3);
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  return;
}


/* __stdcall dScp_yose_select(sub_scp_class *) */

void dScp_yose_select(sub_scp_class *param_1)

{
  fopMsgM_msgDataProc_c::stringLength(&param_1->field_0x634);
  *(short *)&param_1->field_0x916 = (short)(param_1->field_0x634).field_0x130;
  (param_1->field_0x634).field_0x130 = 0;
  fopMsgM_msgDataProc_c::stringShift(&param_1->field_0x634);
  fopMsgM_msgDataProc_c::iconIdxRefresh(&param_1->field_0x634);
  dScp_textPosition(param_1);
  return;
}


/* __stdcall dScp_textPosition(sub_scp_class *) */

void dScp_textPosition(int param_1)

{
  short sVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  uint uVar5;
  int iVar6;
  
  fVar3 = 0_0;
  iVar6 = *(int *)(param_1 + 0x60c);
  fVar2 = *(float *)(iVar6 + 0xe4) * 0_5;
  sVar1 = *(short *)(param_1 + 0x916);
  *(float *)(iVar6 + 0xd8) = 0_0;
  dVar4 = _4142;
  uVar5 = (int)fVar2 * (2 - sVar1) ^ 0x80000000;
  *(float *)(iVar6 + 0xdc) = (float)((double)CONCAT44(0x43300000,uVar5) - _4142);
  iVar6 = *(int *)(param_1 + 0x610);
  *(float *)(iVar6 + 0xd8) = fVar3;
  *(float *)(iVar6 + 0xdc) = (float)((double)CONCAT44(0x43300000,uVar5) - dVar4);
  iVar6 = *(int *)(param_1 + 0x614);
  *(float *)(iVar6 + 0xd8) = fVar3;
  *(float *)(iVar6 + 0xdc) = (float)((double)CONCAT44(0x43300000,uVar5) - dVar4);
  iVar6 = *(int *)(param_1 + 0x618);
  *(float *)(iVar6 + 0xd8) = fVar3;
  *(float *)(iVar6 + 0xdc) = (float)((double)CONCAT44(0x43300000,uVar5) - dVar4);
  return;
}


/* __stdcall dScp_arrowInit(sub_scp_class *) */

void dScp_arrowInit(sub_scp_class *param_1)

{
  f_op_msg_mng::fopMsgM_setNowAlphaZero(&param_1->mArrow);
  (param_1->mArrow).mPosCenter.x = (param_1->mArrow).mPosCenterOrig.x;
  (param_1->mArrow).mPosCenter.y = (param_1->mArrow).mPosCenterOrig.y;
  (param_1->mArrow).mSize.x = (param_1->mArrow).mSizeOrig.x;
  (param_1->mArrow).mSize.y = (param_1->mArrow).mSizeOrig.y;
  return;
}


/* __stdcall dScp_arrowMove(sub_scp_class *) */

void dScp_arrowMove(sub_scp_class *param_1)

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
  
  uVar7 = DAT_8036383c;
  uVar6 = DAT_80363838;
  uVar5 = DAT_80363834;
  uVar4 = DAT_80363830;
  uVar3 = DAT_8036382c;
  uVar9 = DAT_8036382c + DAT_80363830;
  uVar10 = uVar9 + DAT_80363834;
  uVar11 = uVar10 + DAT_80363838;
  iVar12 = uVar11 + DAT_8036383c;
  param_1->field_0x918 = param_1->field_0x918 + 1;
  fVar1 = 1_0;
  if ((param_1->mArrow).mAlpha < (param_1->mArrow).mAlphaOrig) {
    dVar13 = (double)f_op_msg_mng::fopMsgM_valueIncrease(DAT_803e6bc2,(int)param_1->field_0x918,0);
    f_op_msg_mng::fopMsgM_setNowAlpha(&param_1->mArrow,(float)dVar13);
    if ((ushort)DAT_803e6bc2 == param_1->field_0x918) {
      param_1->field_0x918 = 0;
    }
  }
  else {
    uVar8 = SEXT24(param_1->field_0x918);
    fVar2 = fVar1;
    if ((int)uVar3 < (int)uVar8) {
      if ((int)uVar9 < (int)uVar8) {
        if ((int)uVar10 < (int)uVar8) {
          if ((int)uVar11 < (int)uVar8) {
            if (iVar12 < (int)uVar8) {
              param_1->field_0x918 = 0;
            }
            else {
              fVar1 = (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - _4142) -
                      (float)((double)CONCAT44(0x43300000,uVar11 ^ 0x80000000) - _4142);
              fVar2 = (fVar1 * fVar1) /
                      ((float)((double)CONCAT44(0x43300000,uVar7 ^ 0x80000000) - _4142) *
                      (float)((double)CONCAT44(0x43300000,uVar7 ^ 0x80000000) - _4142));
              fVar1 = DAT_8036384c + fVar2 * (DAT_80363850 - DAT_8036384c);
              fVar2 = DAT_80363860 + fVar2 * (DAT_80363864 - DAT_80363860);
            }
          }
          else {
            fVar1 = (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - _4142) -
                    (float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) - _4142);
            fVar2 = (fVar1 * fVar1) /
                    ((float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) - _4142) *
                    (float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) - _4142));
            fVar1 = DAT_80363848 + fVar2 * (DAT_8036384c - DAT_80363848);
            fVar2 = DAT_8036385c + fVar2 * (DAT_80363860 - DAT_8036385c);
          }
        }
        else {
          fVar1 = (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - _4142) -
                  (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - _4142);
          fVar2 = (fVar1 * fVar1) /
                  ((float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - _4142) *
                  (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - _4142));
          fVar1 = DAT_80363844 + fVar2 * (DAT_80363848 - DAT_80363844);
          fVar2 = DAT_80363858 + fVar2 * (DAT_8036385c - DAT_80363858);
        }
      }
      else {
        fVar1 = (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - _4142) -
                (float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - _4142);
        fVar2 = (fVar1 * fVar1) /
                ((float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - _4142) *
                (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - _4142));
        fVar1 = scaleX_4656 + fVar2 * (DAT_80363844 - scaleX_4656);
        fVar2 = scaleY_4657 + fVar2 * (DAT_80363858 - scaleY_4657);
      }
    }
    (param_1->mArrow).mSize.x = (param_1->mArrow).mSizeOrig.x * fVar1;
    (param_1->mArrow).mSize.y = (param_1->mArrow).mSizeOrig.y * fVar2;
    (param_1->mArrow).mPosCenter.y =
         (float)((double)CONCAT44(0x43300000,*(uint *)&param_1->field_0x90c ^ 0x80000000) - _4142) -
         (param_1->mArrow).mSize.y * 0_5;
    f_op_msg_mng::fopMsgM_cposMove(&param_1->mArrow);
  }
  return;
}


/* __stdcall dScp_dotMove(sub_scp_class *) */

void dScp_dotMove(int param_1)

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
  
  *(short *)(param_1 + 0x918) = *(short *)(param_1 + 0x918) + 1;
  if (*(byte *)(param_1 + 0x609) < *(byte *)(param_1 + 0x608)) {
    dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(param_1 + 0x918),0);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x5d4),(float)dVar4);
    if (*(short *)(param_1 + 0x918) == 10) {
      *(undefined2 *)(param_1 + 0x918) = 0;
    }
  }
  else {
    iVar3 = (int)*(short *)(param_1 + 0x918);
    if (iVar3 < 0x3c) {
      if (iVar3 < 0x1f) {
        dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x1e,iVar3,0);
        dVar4 = _4765;
        fVar1 = _4761;
        local_10 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x8f4));
        *(char *)(param_1 + 0x8f8) =
             (char)(int)((float)(local_10 - _4765) +
                        (float)((double)(_4761 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x8f4)) -
                                                        _4765)) * dVar5));
        local_28 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x8f5));
        *(char *)(param_1 + 0x8f9) =
             (char)(int)((float)(local_28 - dVar4) +
                        (float)((double)(fVar1 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x8f5)) -
                                                        dVar4)) * dVar5));
        local_40 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x8f6));
        *(char *)(param_1 + 0x8fa) =
             (char)(int)((float)(local_40 - dVar4) +
                        (float)((double)(fVar1 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x8f6)) -
                                                        dVar4)) * dVar5));
        fVar1 = _4762;
        local_58 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x8fc));
        *(char *)(param_1 + 0x900) =
             (char)(int)((float)(local_58 - dVar4) +
                        (float)((double)(_4762 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x8fc)) -
                                                        dVar4)) * dVar5));
        local_70 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x8fd));
        *(char *)(param_1 + 0x901) =
             (char)(int)((float)(local_70 - dVar4) +
                        (float)((double)(fVar1 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x8fd)) -
                                                        dVar4)) * dVar5));
        local_88 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x8fe));
        *(char *)(param_1 + 0x902) =
             (char)(int)((float)(local_88 - dVar4) +
                        (float)((double)(_4763 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x8fe)) -
                                                        dVar4)) * dVar5));
        local_a0 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x608));
        *(char *)(param_1 + 0x609) =
             (char)(int)((float)(local_a0 - dVar4) +
                        (float)((double)(fVar1 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x608)) -
                                                        dVar4)) * dVar5));
      }
      else {
        dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x1e,0x3c - iVar3,0);
        dVar4 = _4765;
        fVar1 = _4761;
        local_b0 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x8f4));
        *(char *)(param_1 + 0x8f8) =
             (char)(int)((float)(local_b0 - _4765) +
                        (float)((double)(_4761 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x8f4)) -
                                                        _4765)) * dVar5));
        local_98 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x8f5));
        *(char *)(param_1 + 0x8f9) =
             (char)(int)((float)(local_98 - dVar4) +
                        (float)((double)(fVar1 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x8f5)) -
                                                        dVar4)) * dVar5));
        local_80 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x8f6));
        *(char *)(param_1 + 0x8fa) =
             (char)(int)((float)(local_80 - dVar4) +
                        (float)((double)(fVar1 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x8f6)) -
                                                        dVar4)) * dVar5));
        fVar1 = _4762;
        local_68 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x8fc));
        *(char *)(param_1 + 0x900) =
             (char)(int)((float)(local_68 - dVar4) +
                        (float)((double)(_4762 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x8fc)) -
                                                        dVar4)) * dVar5));
        local_50 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x8fd));
        *(char *)(param_1 + 0x901) =
             (char)(int)((float)(local_50 - dVar4) +
                        (float)((double)(fVar1 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x8fd)) -
                                                        dVar4)) * dVar5));
        local_38 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x8fe));
        *(char *)(param_1 + 0x902) =
             (char)(int)((float)(local_38 - dVar4) +
                        (float)((double)(_4763 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x8fe)) -
                                                        dVar4)) * dVar5));
        local_20 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x608));
        *(char *)(param_1 + 0x609) =
             (char)(int)((float)(local_20 - dVar4) +
                        (float)((double)(fVar1 - (float)((double)CONCAT44(0x43300000,
                                                                          (uint)*(byte *)(param_1 +
                                                                                         0x608)) -
                                                        dVar4)) * dVar5));
      }
    }
    else {
      *(undefined *)(param_1 + 0x8f8) = *(undefined *)(param_1 + 0x8f4);
      *(undefined *)(param_1 + 0x8f9) = *(undefined *)(param_1 + 0x8f5);
      *(undefined *)(param_1 + 0x8fa) = *(undefined *)(param_1 + 0x8f6);
      *(undefined *)(param_1 + 0x8fb) = *(undefined *)(param_1 + 0x8f7);
      *(undefined *)(param_1 + 0x900) = *(undefined *)(param_1 + 0x8fc);
      *(undefined *)(param_1 + 0x901) = *(undefined *)(param_1 + 0x8fd);
      *(undefined *)(param_1 + 0x902) = *(undefined *)(param_1 + 0x8fe);
      *(undefined *)(param_1 + 0x903) = *(undefined *)(param_1 + 0x8ff);
      f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x5d4);
      *(undefined2 *)(param_1 + 0x918) = 0;
    }
    uVar2 = *(undefined4 *)(param_1 + 0x8f8);
    iVar3 = *(int *)(param_1 + 0x5d4);
    local_b4 = (undefined)((uint)uVar2 >> 0x18);
    *(undefined *)(iVar3 + 0x108) = local_b4;
    uStack179 = (undefined)((uint)uVar2 >> 0x10);
    *(undefined *)(iVar3 + 0x109) = uStack179;
    uStack178 = (undefined)((uint)uVar2 >> 8);
    *(undefined *)(iVar3 + 0x10a) = uStack178;
    uStack177 = (undefined)uVar2;
    *(undefined *)(iVar3 + 0x10b) = uStack177;
    uVar2 = *(undefined4 *)(param_1 + 0x900);
    iVar3 = *(int *)(param_1 + 0x5d4);
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


/* __stdcall dScp_talkBeforeProc(sub_scp_class *) */

void dScp_talkBeforeProc(sub_scp_class *param_1)

{
  int iVar1;
  void *pvVar2;
  ulong uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
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
  longlong local_30;
  longlong local_28;
  longlong local_20;
  longlong local_18;
  longlong local_10;
  
  dScp_arrowInit(param_1);
  pvVar2 = (void *)fopMsgM_msgGet_c::getMesgHeader
                             ((fopMsgM_msgGet_c *)&param_1->field_0x8d4,(param_1->parent).field_0xec
                             );
  param_1->field_0x100 = pvVar2;
  if (param_1->field_0x100 == (void *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_scope.cpp",0x4fe,"i_Scp->head_p");
    m_Do_printf::OSPanic("d_scope.cpp",0x4fe,&DAT_8036387f);
  }
  uVar4 = fopMsgM_msgGet_c::getMessage
                    ((fopMsgM_msgGet_c *)&param_1->field_0x8d4,(mesg_header *)param_1->field_0x100);
  *(undefined4 *)&param_1->field_0x91c = uVar4;
  fopMsgM_msgGet_c::getMesgEntry((fopMsgM_msgGet_c *)&local_48,(mesg_header *)&param_1->field_0x8d4)
  ;
  *(undefined4 *)&param_1->field_0x61c = local_48;
  *(undefined2 *)&param_1->field_0x620 = local_44;
  *(undefined2 *)&param_1->field_0x622 = local_42;
  *(undefined2 *)&param_1->field_0x624 = local_40;
  *(undefined2 *)&param_1->field_0x626 = local_3e;
  *(undefined *)&param_1->field_0x628 = local_3c;
  *(undefined *)&param_1->field_0x629 = local_3b;
  *(undefined *)&param_1->field_0x62a = local_3a;
  *(undefined *)&param_1->field_0x62b = local_39;
  *(undefined *)&param_1->field_0x62c = local_38;
  *(undefined *)&param_1->field_0x62d = local_37;
  *(undefined *)&param_1->field_0x62e = local_36;
  *(undefined *)&param_1->field_0x62f = local_35;
  *(undefined *)&param_1->field_0x630 = local_34;
  *(undefined *)&param_1->field_0x631 = local_33;
  *(undefined *)&param_1->field_0x632 = local_32;
  *(undefined *)&param_1->field_0x633 = local_31;
  dScp_stringInit(param_1);
  fopMsgM_msgDataProc_c::dataInit(&param_1->field_0x634);
  *(undefined4 *)&(param_1->field_0x634).field_0x3c = *(undefined4 *)&param_1->field_0x91c;
  m_Do_ext::mDoExt_setCurrentHeap(param_1->mpHeap);
  uVar7 = *(undefined4 *)&param_1->field_0x92c;
  uVar6 = *(undefined4 *)&param_1->field_0x928;
  uVar5 = *(undefined4 *)&param_1->field_0x924;
  uVar4 = *(undefined4 *)&param_1->field_0x920;
  *(undefined4 *)&(param_1->field_0x634).field_0x60 = uVar4;
  *(undefined4 *)&(param_1->field_0x634).field_0x40 = uVar4;
  *(undefined4 *)&(param_1->field_0x634).field_0x64 = uVar5;
  *(undefined4 *)&(param_1->field_0x634).field_0x44 = uVar5;
  *(undefined4 *)&(param_1->field_0x634).field_0x68 = uVar6;
  *(undefined4 *)&(param_1->field_0x634).field_0x48 = uVar6;
  *(undefined4 *)&(param_1->field_0x634).field_0x6c = uVar7;
  *(undefined4 *)&(param_1->field_0x634).field_0x4c = uVar7;
  m_Do_ext::mDoExt_setCurrentHeap();
  *(undefined4 *)&(param_1->field_0x634).field_0x4 = font0;
  *(undefined4 *)&(param_1->field_0x634).field_0x8 = font1;
  iVar1 = (int)param_1->field_0x60c->field_0xe0;
  local_30 = (longlong)iVar1;
  (param_1->field_0x634).field_0x11c = iVar1;
  iVar1 = (int)param_1->field_0x610->field_0xe0;
  local_28 = (longlong)iVar1;
  (param_1->field_0x634).field_0x124 = iVar1;
  iVar1 = (int)param_1->field_0x60c->mFontLeading;
  local_20 = (longlong)iVar1;
  (param_1->field_0x634).field_0x120 = iVar1;
  *(int *)&(param_1->field_0x634).field_0xc = &param_1->field_0x61c;
  local_18 = (longlong)(int)*(float *)&param_1->field_0x8e4;
  (param_1->field_0x634).field_0x144 = (int)*(float *)&param_1->field_0x8e4;
  local_10 = (longlong)(int)*(float *)&param_1->field_0x8ec;
  (param_1->field_0x634).field_0x14c = (int)*(float *)&param_1->field_0x8ec;
  (param_1->field_0x634).field_0x128 = 0x1f7;
  (param_1->field_0x634).field_0x12c = 0x1e6;
  (param_1->field_0x634).field_0x160 = (uint)DAT_803e6bc6;
  (param_1->field_0x634).field_0x15c = (int)DAT_803e6bb0;
  if (DAT_803e6bc7 == '\0') {
    *(undefined *)&(param_1->field_0x634).field_0x29c = 0;
  }
  else {
    *(undefined *)&(param_1->field_0x634).field_0x29c = 1;
  }
  dScp_yose_select(param_1);
  dScp_stringSet(param_1);
  d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 6;
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __stdcall dScp_outnowProc(sub_scp_class *) */

undefined4 dScp_outnowProc(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  if (*(char *)(param_1 + 0x629) == '\0') {
    if (((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) != 0) ||
         ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0')) &&
        (*(undefined *)(param_1 + 0x8cd) = 1, *(char *)(param_1 + 0x8cb) == '\0')) &&
       ((*(char *)(param_1 + 0x8cc) == '\0' && (*(int *)(param_1 + 0x78c) != 0)))) {
      *(undefined4 *)(param_1 + 0x78c) = 0;
    }
  }
  else {
    if (*(char *)(param_1 + 0x629) == '\x01') {
      *(undefined *)(param_1 + 0x8cd) = 1;
    }
  }
  if (((*(char *)(param_1 + 0x8cb) == '\0') && (*(char *)(param_1 + 0x8cc) == '\0')) &&
     (uVar3 = *(uint *)(param_1 + 0x78c), uVar3 != 0)) {
    *(uint *)(param_1 + 0x78c) = uVar3 - 1 & (int)(-uVar3 & ~uVar3) >> 0x1f;
  }
  else {
    fopMsgM_msgDataProc_c::stringSet((fopMsgM_msgDataProc_c *)(param_1 + 0x634));
    d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = *(byte *)(param_1 + 0x8b0);
    if (d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane == 0xe) {
      *(undefined2 *)(param_1 + 0x918) = 0;
    }
    iVar4 = 0;
    iVar7 = 0;
    iVar6 = 0;
    do {
      cVar1 = *(char *)(param_1 + iVar4 + 0x8b5);
      uVar5 = *(undefined4 *)(param_1 + 0x890);
      if ((cVar1 != -1) && (*(short *)((int)&sbuttonTimer + iVar6) == -1)) {
        uVar2 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
        f_op_msg_mng::fopMsgM_outFontSet
                  (*(undefined4 *)((int)sbutton_icon + iVar7),
                   *(undefined4 *)((int)sbutton_kage + iVar7),(short *)((int)&sbuttonTimer + iVar6),
                   uVar5,cVar1);
        m_Do_ext::mDoExt_setCurrentHeap(uVar2);
      }
      iVar4 = iVar4 + 1;
      iVar7 = iVar7 + 4;
      iVar6 = iVar6 + 2;
    } while (iVar4 < 8);
  }
  dScp_stringSet(param_1);
  return 1;
}


/* __stdcall dScp_continueProc(sub_scp_class *) */

undefined4 dScp_continueProc(sub_scp_class *param_1)

{
  if ((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
      (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3)) &&
     (*(char *)&(param_1->field_0x634).field_0x294 == '\0')) {
    dScp_arrowMove(param_1);
  }
  else {
    *(undefined *)&(param_1->field_0x634).field_0x294 = 0;
    JKRFileLoader::removeResource(param_1->field_0x100,(JKRFileLoader *)0x0);
    dScp_talkBeforeProc(param_1);
    JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x80b,(cXyz *)0x0,0,0,1_0,1_0,_1_0,_1_0,0);
  }
  return 1;
}


/* __stdcall dScp_forceContinueProc(sub_scp_class *) */

undefined4 dScp_forceContinueProc(int param_1)

{
  JKRFileLoader::removeResource(*(void **)(param_1 + 0x100),(JKRFileLoader *)0x0);
  dScp_talkBeforeProc(param_1);
  JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x80b,(cXyz *)0x0,0,0,1_0,1_0,_1_0,_1_0,0);
  return 1;
}


/* __stdcall dScp_closewaitProc(sub_scp_class *) */

undefined4 dScp_closewaitProc(int param_1)

{
  char cVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 0x8cb) == '\0') {
    if (*(char *)(param_1 + 0x8cc) != '\0') {
      uVar2 = *(uint *)(param_1 + 0x78c);
      uVar2 = uVar2 - 1 & (int)(-uVar2 & ~uVar2) >> 0x1f;
      *(uint *)(param_1 + 0x78c) = uVar2;
      if (uVar2 == 0) {
        *(undefined *)(param_1 + 0x8cc) = 0;
        d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0x12;
        dScp_mesgPaneHide();
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x5d4));
      }
      else {
        if ((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
            (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3)) &&
           (cVar1 = f_op_msg_mng::fopMsgM_checkForceSend(), cVar1 == '\0')) {
          dScp_dotMove(param_1);
        }
        else {
          *(undefined *)(param_1 + 0x8cc) = 0;
          d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0x12;
          dScp_mesgPaneHide(param_1);
          f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x5d4));
        }
      }
    }
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x78c);
    uVar2 = uVar2 - 1 & (int)(-uVar2 & ~uVar2) >> 0x1f;
    *(uint *)(param_1 + 0x78c) = uVar2;
    if ((uVar2 == 0) || (cVar1 = f_op_msg_mng::fopMsgM_checkForceSend(), cVar1 != '\0')) {
      *(undefined *)(param_1 + 0x8cb) = 0;
      d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0x12;
      dScp_mesgPaneHide(param_1);
    }
  }
  return 1;
}


/* __stdcall dScp_finishProc(sub_scp_class *) */

undefined4 dScp_finishProc(int param_1)

{
  char cVar1;
  
  if ((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
      (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3)) &&
     (cVar1 = f_op_msg_mng::fopMsgM_checkForceSend(), cVar1 == '\0')) {
    dScp_dotMove(param_1);
  }
  else {
    *(undefined *)(param_1 + 0x8c8) = 0;
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x5d4));
    d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0x12;
    dScp_mesgPaneHide(param_1);
  }
  return 1;
}


/* __stdcall dScp_openProc(sub_scp_class *) */

void dScp_openProc(sub_scp_class *param_1)

{
  float fVar1;
  int iVar2;
  double dVar3;
  
  param_1->field_0x914 = param_1->field_0x914 + 1;
  iVar2 = (int)param_1->field_0x914;
  if (iVar2 < 5) {
    dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,iVar2,0);
    dScp_wipeMove((double)(3_0 * (float)((double)1_0 - dVar3)),param_1);
  }
  else {
    if (iVar2 == 5) {
      dScp_wipeMove((double)1_0);
    }
    else {
      if (iVar2 < 10) {
        f_op_msg_mng::fopMsgM_valueIncrease(5,iVar2 + -5,0);
        dScp_scopeAlpha(param_1);
      }
      else {
        dScp_scopeInitAlpha(param_1);
        fVar1 = 1_0;
        param_1->field_0x910 = 1_0;
        (param_1->parent).mMode = 0xb;
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = 0xb;
        d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0xb;
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 7;
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x823,(cXyz *)0x0,0,0,fVar1,fVar1,_1_0,_1_0,0);
      }
    }
  }
  return;
}


/* __stdcall dScp_openProc1(sub_scp_class *) */

void dScp_openProc1(sub_scp_class *param_1)

{
  float fVar1;
  int iVar2;
  double dVar3;
  
  param_1->field_0x914 = param_1->field_0x914 + 1;
  iVar2 = (int)param_1->field_0x914;
  if (iVar2 < 5) {
    dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(4,iVar2,1);
    dScp_wipeMove2((double)(3_0 * (float)((double)1_0 - dVar3)),param_1);
    if (param_1->field_0x914 == 3) {
      d_com_inf_game::g_dComIfG_gameInfo._23576_1_ = 1;
    }
    else {
      d_com_inf_game::g_dComIfG_gameInfo._23576_1_ = 0;
    }
  }
  else {
    if (iVar2 == 5) {
      dScp_wipeMove2((double)1_0);
    }
    else {
      if (iVar2 < 10) {
        f_op_msg_mng::fopMsgM_valueIncrease(5,iVar2 + -5,0);
        dScp_scopeAlpha(param_1);
      }
      else {
        dScp_scopeInitAlpha(param_1);
        fVar1 = 1_0;
        param_1->field_0x910 = 1_0;
        (param_1->parent).mMode = 0xb;
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = 0xb;
        d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0xb;
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 7;
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x823,(cXyz *)0x0,0,0,fVar1,fVar1,_1_0,_1_0,0);
      }
    }
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x8023a8b4) */
/* __stdcall dScp_openProc2(sub_scp_class *) */

void dScp_openProc2(int param_1)

{
  short sVar1;
  daPy_lk_c *pdVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  double dVar5;
  undefined auStack8 [8];
  
  pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar5 = (double)DAT_803e6930;
  *(short *)(param_1 + 0x914) = *(short *)(param_1 + 0x914) + 1;
  sVar1 = *(short *)(param_1 + 0x914);
  if (sVar1 < 6) {
    (pdVar2->parent).field_0x29c = (pdVar2->parent).field_0x29c | 0x80000;
    dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)*(short *)(param_1 + 0x914),1);
    dScp_scopeAlpha((double)(float)((double)1_0 - dVar5),param_1);
  }
  else {
    if (sVar1 < 10) {
      (pdVar2->parent).field_0x29c = (pdVar2->parent).field_0x29c | 0x80000;
      dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,*(short *)(param_1 + 0x914) + -5,0);
      dScp_wipeMoveDemo((double)(float)((double)1_0 +
                                       (double)(float)((double)(float)(dVar5 - (double)1_0) * dVar4)
                                       ),param_1,0);
    }
    else {
      if (sVar1 == 10) {
        dScp_wipeMoveDemo(dVar5,param_1,0);
        dScp_scopeAlpha((double)0_0,param_1);
      }
      else {
        dScp_wipeMoveDemo(dVar5,param_1,0);
        *(float *)(param_1 + 0x910) = 1_0;
        *(undefined2 *)(param_1 + 0xf8) = 0xc;
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = 0xc;
        d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0xd;
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 0;
      }
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __stdcall dScp_moveProc(sub_scp_class *) */

void dScp_moveProc(int param_1)

{
  if (d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane == 0xd) {
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
      dScp_wipeAngleCalc();
    }
    else {
      d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0xb;
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 0;
      *(undefined2 *)(param_1 + 0xf8) = 4;
      *(undefined2 *)(param_1 + 0x914) = 0;
    }
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane == 2) {
      dScp_mesgPaneShow();
      *(undefined2 *)(param_1 + 0xf8) = 6;
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = 6;
      dScp_talkBeforeProc(param_1);
      dScp_wipeAngleCalc(param_1);
    }
    else {
      if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0x8 & 8) == 0) {
        *(undefined2 *)(param_1 + 0xf8) = 0xe;
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = 0xe;
        *(undefined2 *)(param_1 + 0x914) = 0;
      }
      else {
        dScp_wipeAngleCalc();
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 7;
      }
    }
  }
  return;
}


/* __stdcall dScp_demoProc(sub_scp_class *) */

void dScp_demoProc(int param_1)

{
  int iVar1;
  camera_class *pcVar2;
  int iVar3;
  
  pcVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo
           [(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCamera].mpCamera;
  if (d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane == 0xd) {
    dScp_wipeMoveDemo((double)DAT_803e6930,param_1,0);
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr != (dDemo_manager_c *)0x0) {
      if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->field_0xd8 == 0x1a9) {
        dCamera_c::SetTrimSize(&pcVar2->mBody,3);
        iVar1 = 0;
        iVar3 = 8;
        do {
          *(undefined *)(*(int *)(param_1 + iVar1 + 0x3dc) + 0xaa) = 0;
          iVar1 = iVar1 + 0x38;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      else {
        if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->field_0xd8 == 0x460) {
          dCamera_c::SetTrimSize(&pcVar2->mBody,4);
          iVar1 = 0;
          iVar3 = 8;
          do {
            *(undefined *)(*(int *)(param_1 + iVar1 + 0x3dc) + 0xaa) = 1;
            iVar1 = iVar1 + 0x38;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
      }
    }
  }
  else {
    if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0x8 & 8) == 0) {
      *(undefined2 *)(param_1 + 0xf8) = 0xe;
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = 0xe;
      *(undefined2 *)(param_1 + 0x914) = 0;
      *(undefined *)(param_1 + 0x930) = 1;
    }
  }
  return;
}


/* __stdcall dScp_talkNowProc(sub_scp_class *) */

void dScp_talkNowProc(int param_1)

{
  if (d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane == 6) {
    dScp_outnowProc();
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane == 0xf) {
      dScp_continueProc();
    }
    else {
      if (d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane == 0x10) {
        dScp_finishProc();
      }
      else {
        if (d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane == 0xd) {
          dScp_forceContinueProc();
        }
        else {
          if (d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane == 10) {
            dScp_closewaitProc();
          }
          else {
            if (d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane == 0x11) {
              if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca == 0xd) {
                d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0xd;
                d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 0;
              }
              else {
                d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0xb;
                d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 7;
              }
              *(undefined2 *)(param_1 + 0xf8) = 0xb;
              d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = 0xb;
            }
          }
        }
      }
    }
  }
  dScp_wipeAngleCalc(param_1);
  f_op_msg_mng::fopMsgM_forceSendOff();
  return;
}


/* WARNING: Removing unreachable block (ram,0x8023ac44) */
/* __stdcall dScp_closeProc(sub_scp_class *) */

void dScp_closeProc(int param_1)

{
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  *(short *)(param_1 + 0x914) = *(short *)(param_1 + 0x914) + 1;
  dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)*(short *)(param_1 + 0x914),0);
  if (*(short *)(param_1 + 0x914) < 5) {
    dScp_wipeMove((double)(float)((double)3_0 * dVar2),param_1);
    dScp_scopeAlpha((double)(float)((double)1_0 - dVar2),param_1);
  }
  else {
    dScp_wipeMove((double)3_0,param_1);
    dScp_scopeAlphaZero(param_1);
    JKRFileLoader::removeResource(*(void **)(param_1 + 0x100),(JKRFileLoader *)0x0);
    *(undefined2 *)(param_1 + 0xf8) = 0x12;
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = 0x12;
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8023ad04) */
/* __stdcall dScp_closeDemoProc(sub_scp_class *) */

void dScp_closeDemoProc(int param_1)

{
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f31;
  double dVar3;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar3 = (double)DAT_803e6930;
  *(short *)(param_1 + 0x914) = *(short *)(param_1 + 0x914) + 1;
  dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)*(short *)(param_1 + 0x914),0);
  if (*(short *)(param_1 + 0x914) < 5) {
    dScp_wipeMoveDemo((double)(float)(dVar3 + (double)(float)((double)(float)((double)3_0 - dVar3) *
                                                             dVar2)),param_1,1);
  }
  else {
    dScp_wipeMoveDemo((double)3_0,param_1,1);
    JKRFileLoader::removeResource(*(void **)(param_1 + 0x100),(JKRFileLoader *)0x0);
    *(undefined2 *)(param_1 + 0xf8) = 0x12;
    *(undefined2 *)(param_1 + 0xf8) = 0x12;
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = 0x12;
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}


/* __stdcall dScp_Draw(sub_scp_class *) */

undefined4 dScp_Draw(void)

{
  dScp_setAlpha();
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,(dDlst_base_c *)&scope)
  ;
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x8023aecc) */
/* WARNING: Removing unreachable block (ram,0x8023aed4) */
/* __stdcall dScp_Execute(sub_scp_class *) */

undefined4 dScp_Execute(sub_scp_class *param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 in_f30;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  sVar1 = (param_1->parent).mMode;
  if (sVar1 == 2) {
    dScp_openProc(param_1);
  }
  else {
    if (sVar1 == 3) {
      dScp_openProc1();
    }
    else {
      if (sVar1 == 4) {
        dScp_openProc2();
      }
      else {
        if (sVar1 == 0xb) {
          dScp_moveProc();
        }
        else {
          if (sVar1 == 0xc) {
            dScp_demoProc();
          }
          else {
            if (sVar1 == 6) {
              dScp_talkNowProc();
            }
            else {
              if (sVar1 == 0x10) {
                if (*(char *)&param_1->field_0x930 == '\0') {
                  dScp_closeProc();
                }
                else {
                  dScp_closeDemoProc();
                }
              }
              else {
                if (sVar1 == 0x13) {
                  f_op_msg_mng::fopMsgM_Delete();
                }
              }
            }
          }
        }
      }
    }
  }
  iVar2 = 0;
  iVar3 = 0;
  dVar6 = (double)_4762;
  dVar5 = _4765;
  do {
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)((int)&(param_1->field_0x3dc).mpPane + iVar3),
               (float)((double)(float)((double)CONCAT44(0x43300000,(uint)DAT_803e6934) - dVar5) /
                      dVar6));
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar2 < 8);
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ == '\0') {
    if ((param_1->field_0x610->parent).mbDraw != 0) {
      (param_1->field_0x610->parent).mbDraw = 1;
    }
    if ((param_1->field_0x618->parent).mbDraw != 0) {
      (param_1->field_0x618->parent).mbDraw = 1;
    }
  }
  else {
    (param_1->field_0x610->parent).mbDraw = 0;
    (param_1->field_0x618->parent).mbDraw = 0;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return 1;
}


/* __stdcall dScp_IsDelete(sub_scp_class *) */

undefined4 dScp_IsDelete(void)

{
  return 1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dScp_Delete(sub_scp_class *) */

undefined4 dScp_Delete(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
  if (dScp_ScpScreen != (int *)0x0) {
    (**(code **)(*dScp_ScpScreen + 8))(dScp_ScpScreen,1);
  }
  if (dScp_MsgScreen != (int *)0x0) {
    (**(code **)(*dScp_MsgScreen + 8))(dScp_MsgScreen,1);
  }
  m_Do_ext::mDoExt_removeMesgFont();
  m_Do_ext::mDoExt_removeRubyFont();
  iVar3 = 0;
  iVar4 = 0;
  do {
    piVar2 = *(int **)((int)sbutton_icon + iVar4);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,1);
    }
    piVar2 = *(int **)((int)sbutton_kage + iVar4);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,1);
    }
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar3 < 8);
  JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(param_1 + 0x920));
  JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(param_1 + 0x924));
  JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(param_1 + 0x928));
  JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(param_1 + 0x92c));
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive)->parent).parent.vtbl)->
            removeResourceAll)();
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpScopeResArchive)->parent).parent.vtbl)->
            removeResourceAll)();
  JKRHeap::freeAll(*(JKRHeap **)(param_1 + 0xfc));
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 0;
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = 0;
  d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 0;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5be5 = 0;
  d_com_inf_game::g_dComIfG_gameInfo._23576_1_ = 0;
  return 1;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __stdcall dScp_Create(msg_class *) */

undefined4 dScp_Create(sub_scp_class *param_1)

{
  undefined4 uVar1;
  J2DScreen *pJVar2;
  J2DPicture *pJVar3;
  void *pvVar4;
  ulong uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  TBox2_float_ local_48;
  TBox2_float_ local_38;
  
  if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 0) ||
     (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 5)) {
    param_1->mpHeap = d_com_inf_game::g_dComIfG_gameInfo.field_0x5c1c;
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 5;
    uVar1 = m_Do_ext::mDoExt_setCurrentHeap(param_1->mpHeap);
    pJVar2 = (J2DScreen *)JKernel::operator_new(0xd4);
    if (pJVar2 != (J2DScreen *)0x0) {
      local_38.mTL.x = 0_0;
      local_38.mTL.y = 0_0;
      local_38.mBR.x = 640_0;
      local_38.mBR.y = 480_0;
      J2DPane::J2DPane((J2DPane *)pJVar2,(J2DPane *)0x0,true,0x726f6f74,&local_38);
      (pJVar2->parent).vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
      pJVar2->field_0xd0 = (_GXColor)0xffffffff;
      pJVar2->mbClipToParent = 0;
    }
    dScp_ScpScreen = pJVar2;
    if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5be5 == 0) {
      J2DScreen::set(pJVar2,"wipe_00_2.blo",
                     d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpScopeResArchive);
    }
    else {
      J2DScreen::set(pJVar2,"wipe_00.blo",d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpScopeResArchive
                    );
    }
    pJVar2 = (J2DScreen *)JKernel::operator_new(0xd4);
    if (pJVar2 != (J2DScreen *)0x0) {
      local_48.mTL.x = 0_0;
      local_48.mTL.y = 0_0;
      local_48.mBR.x = 640_0;
      local_48.mBR.y = 480_0;
      J2DPane::J2DPane((J2DPane *)pJVar2,(J2DPane *)0x0,true,0x726f6f74,&local_48);
      (pJVar2->parent).vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
      pJVar2->field_0xd0 = (_GXColor)0xffffffff;
      pJVar2->mbClipToParent = 0;
    }
    dScp_MsgScreen = pJVar2;
    J2DScreen::set(pJVar2,"hukidashi_08.blo",d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive);
    dScp_ScreenDataSet(param_1);
    iVar8 = 0;
    iVar7 = 0;
    iVar6 = 0;
    do {
      pJVar3 = (J2DPicture *)JKernel::operator_new(0x124);
      if (pJVar3 != (J2DPicture *)0x0) {
        J2DPicture::J2DPicture(pJVar3,"font_07_02.bti");
      }
      *(J2DPicture **)((int)sbutton_icon + iVar6) = pJVar3;
      pJVar3 = (J2DPicture *)JKernel::operator_new(0x124);
      if (pJVar3 != (J2DPicture *)0x0) {
        J2DPicture::J2DPicture(pJVar3,"font_07_02.bti");
      }
      *(J2DPicture **)((int)sbutton_kage + iVar6) = pJVar3;
      f_op_msg_mng::fopMsgM_blendInit(*(undefined4 *)((int)sbutton_icon + iVar6),"font_00.bti");
      f_op_msg_mng::fopMsgM_blendInit(*(undefined4 *)((int)sbutton_kage + iVar6),"font_00.bti");
      *(undefined *)(*(int *)((int)sbutton_icon + iVar6) + 0xaa) = 0;
      *(undefined *)(*(int *)((int)sbutton_kage + iVar6) + 0xaa) = 0;
      *(undefined *)(*(int *)((int)sbutton_icon + iVar6) + 0xac) = 0;
      *(undefined *)(*(int *)((int)sbutton_kage + iVar6) + 0xac) = 0;
      *(undefined2 *)((int)&sbuttonTimer + iVar7) = 0xffff;
      iVar8 = iVar8 + 1;
      iVar7 = iVar7 + 2;
      iVar6 = iVar6 + 4;
    } while (iVar8 < 8);
    pvVar4 = JKRHeap::alloc(&param_1->mpHeap->parent,1000,4);
    *(void **)&param_1->field_0x920 = pvVar4;
    if (*(int *)&param_1->field_0x920 == 0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_scope.cpp",0x8d1,"i_Scp->oTx != 0");
      m_Do_printf::OSPanic("d_scope.cpp",0x8d1,&DAT_8036387f);
    }
    pvVar4 = JKRHeap::alloc(&param_1->mpHeap->parent,1000,4);
    *(void **)&param_1->field_0x924 = pvVar4;
    if (*(int *)&param_1->field_0x924 == 0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_scope.cpp",0x8d4,"i_Scp->oRb != 0");
      m_Do_printf::OSPanic("d_scope.cpp",0x8d4,&DAT_8036387f);
    }
    pvVar4 = JKRHeap::alloc(&param_1->mpHeap->parent,1000,4);
    *(void **)&param_1->field_0x928 = pvVar4;
    if (*(int *)&param_1->field_0x928 == 0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_scope.cpp",0x8d7,"i_Scp->oTxSdw != 0");
      m_Do_printf::OSPanic("d_scope.cpp",0x8d7,&DAT_8036387f);
    }
    pvVar4 = JKRHeap::alloc(&param_1->mpHeap->parent,1000,4);
    *(void **)&param_1->field_0x92c = pvVar4;
    if (*(int *)&param_1->field_0x92c == 0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_scope.cpp",0x8da,"i_Scp->oRbSdw != 0");
      m_Do_printf::OSPanic("d_scope.cpp",0x8da,&DAT_8036387f);
    }
    m_Do_ext::mDoExt_setCurrentHeap(uVar1);
    dScp_valueInit(param_1);
    dScp_mesgPaneHide(param_1);
    f_op_msg_mng::fopMsgM_setNowAlphaZero(&param_1->mArrow);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)&param_1->field_0x5d4);
    d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0;
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 0;
    uVar1 = 4;
    psRam803f72ec = param_1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

}

/* __thiscall dDlst_2DSCP_c::~dDlst_2DSCP_c(void) */

void __thiscall dDlst_2DSCP_c::_dDlst_2DSCP_c(dDlst_2DSCP_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2DSCP_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_2DSCP_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_scope {

void __sinit_d_scope_cpp(void)

{
  scope = &::dDlst_2DSCP_c::__vt;
  Runtime.PPCEABI.H::__register_global_object(&scope,::dDlst_2DSCP_c::_dDlst_2DSCP_c,&_4096);
  return;
}

