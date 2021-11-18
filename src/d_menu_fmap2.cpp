#include <d_menu_fmap2.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DPane.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <J2DGraph/J2DScreen.h>
#include <d_lib.h>
#include <m_Do_ext.h>
#include <d_menu_fmap2.h>
#include <m_Do_hostIO.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <f_op_msg_mng.h>
#include <J2DGraph/J2DTextBox.h>
#include <d_2dnumber.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <d_map.h>
#include <d_stage.h>
#include <d_save.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <m_Do_dvd_thread.h>
#include <d_kankyo.h>
#include <J2DGraph/J2DPicture.h>
#include <d_drawlist.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <JKernel/JKRArchivePub.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dDlst_FMAP2GS_c.h>
#include <dMenu_Fmap2_c.h>
#include <dDlst_FMAP2_c.h>
#include <dMf2_HIO_c.h>


namespace d_menu_fmap2 {
}

namespace d_menu_fmap2 {
undefined g_mf2HIO;
}

/* __thiscall dMf2_HIO_c::dMf2_HIO_c(void) */

void __thiscall dMf2_HIO_c::dMf2_HIO_c(dMf2_HIO_c *this)

{
  float fVar1;
  
  *(undefined1 **)this = &__vt;
  this[0x77] = (dMf2_HIO_c)0x1;
  this[0x78] = (dMf2_HIO_c)0x1;
  this[0x79] = (dMf2_HIO_c)0x1;
  this[0x76] = (dMf2_HIO_c)0x0;
  *(undefined2 *)(this + 0x16) = 0x19;
  this[9] = (dMf2_HIO_c)0xff;
  this[10] = (dMf2_HIO_c)0x0;
  this[0xb] = (dMf2_HIO_c)0x0;
  this[0xc] = (dMf2_HIO_c)0xff;
  this[5] = (dMf2_HIO_c)0xff;
  this[6] = (dMf2_HIO_c)0xff;
  this[7] = (dMf2_HIO_c)0x0;
  this[8] = (dMf2_HIO_c)0xff;
  this[0x11] = (dMf2_HIO_c)0xff;
  this[0x12] = (dMf2_HIO_c)0x8e;
  this[0x13] = (dMf2_HIO_c)0x0;
  this[0x14] = (dMf2_HIO_c)0xff;
  this[0xd] = (dMf2_HIO_c)0xff;
  this[0xe] = (dMf2_HIO_c)0xff;
  this[0xf] = (dMf2_HIO_c)0x82;
  this[0x10] = (dMf2_HIO_c)0x9b;
  this[0x1e] = (dMf2_HIO_c)0x0;
  this[0x20] = (dMf2_HIO_c)0x0;
  this[0x1f] = (dMf2_HIO_c)0x0;
  this[0x22] = (dMf2_HIO_c)0x32;
  this[0x28] = (dMf2_HIO_c)0x1e;
  *(float *)(this + 0x24) = d_menu_fmap2::_4112;
  this[0x30] = (dMf2_HIO_c)0x5;
  this[0x31] = (dMf2_HIO_c)0xb;
  *(float *)(this + 0x34) = d_menu_fmap2::_4113;
  this[0x38] = (dMf2_HIO_c)0x8;
  *(undefined2 *)(this + 0x3a) = 0;
  *(undefined2 *)(this + 0x3c) = 0;
  this[0x3e] = (dMf2_HIO_c)0x8;
  this[0x48] = (dMf2_HIO_c)0x8;
  this[0x3f] = (dMf2_HIO_c)0xa;
  this[0x40] = (dMf2_HIO_c)0xa;
  *(float *)(this + 0x44) = d_menu_fmap2::_4114;
  *(float *)(this + 0x58) = d_menu_fmap2::_4115;
  *(float *)(this + 0x5c) = d_menu_fmap2::_4116;
  *(float *)(this + 0x60) = d_menu_fmap2::_4117;
  this[100] = (dMf2_HIO_c)0x4;
  fVar1 = d_menu_fmap2::_4118;
  *(float *)(this + 0x68) = d_menu_fmap2::_4118;
  *(float *)(this + 0x6c) = fVar1;
  *(float *)(this + 0x70) = d_menu_fmap2::_4119;
  this[0x74] = (dMf2_HIO_c)0x0;
  this[0x75] = (dMf2_HIO_c)0x2d;
  this[0x49] = (dMf2_HIO_c)0x8;
  this[0x4a] = (dMf2_HIO_c)0x2;
  this[0x4b] = (dMf2_HIO_c)0xc;
  this[0x4c] = (dMf2_HIO_c)0x0;
  this[0x4d] = (dMf2_HIO_c)0x0;
  this[0x4e] = (dMf2_HIO_c)0x0;
  fVar1 = d_menu_fmap2::_4120;
  *(float *)(this + 0x50) = d_menu_fmap2::_4120;
  *(float *)(this + 0x54) = fVar1;
  this[0x7a] = (dMf2_HIO_c)0x1e;
  this[0x7b] = (dMf2_HIO_c)0x6;
  this[0x7c] = (dMf2_HIO_c)0xff;
  this[0x7c] = (dMf2_HIO_c)0xff;
  this[0x7c] = (dMf2_HIO_c)0xff;
  this[0x7f] = (dMf2_HIO_c)0xff;
  this[0x80] = (dMf2_HIO_c)0x0;
  this[0x81] = (dMf2_HIO_c)0x0;
  this[0x82] = (dMf2_HIO_c)0xa8;
  this[0x83] = (dMf2_HIO_c)0x0;
  this[0x84] = (dMf2_HIO_c)0xf;
  this[0x85] = (dMf2_HIO_c)0x3c;
  this[0x86] = (dMf2_HIO_c)0xff;
  this[0x87] = (dMf2_HIO_c)0xff;
  this[0x88] = (dMf2_HIO_c)0xff;
  this[0x89] = (dMf2_HIO_c)0xff;
  this[0x8a] = (dMf2_HIO_c)0x0;
  this[0x8b] = (dMf2_HIO_c)0x0;
  this[0x8c] = (dMf2_HIO_c)0x0;
  this[0x8d] = (dMf2_HIO_c)0x0;
  this[0x8e] = (dMf2_HIO_c)0x1e;
  this[0x8f] = (dMf2_HIO_c)0x0;
  this[0x90] = (dMf2_HIO_c)0xff;
  this[0x91] = (dMf2_HIO_c)0x20;
  this[0x92] = (dMf2_HIO_c)0xf;
  this[0x93] = (dMf2_HIO_c)0xff;
  this[0x94] = (dMf2_HIO_c)0x20;
  return;
}


/* __thiscall dMenu_Fmap2_c::_create(void) */

void __thiscall dMenu_Fmap2_c::_create(dMenu_Fmap2_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  STControl *this_01;
  void *pvVar2;
  JUTFont *pJVar3;
  TBox2_float_ local_18;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_18.mTL.x = d_menu_fmap2::_4118;
    local_18.mTL.y = d_menu_fmap2::_4118;
    local_18.mBR.x = d_menu_fmap2::_4183;
    local_18.mBR.y = d_menu_fmap2::_4184;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_18);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 0x24) = this_00;
  if (*(int *)(this + 0x24) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.cpp",0x13c,"fmap2Dl.scrn != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x13c,&DAT_8035ff21);
  }
  J2DScreen::set(*(J2DScreen **)(this + 0x24),"f_hikaku_1.blo",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFMapResArchive);
  this_01 = (STControl *)JKernel::operator_new(0x28);
  if (this_01 != (STControl *)0x0) {
    STControl::STControl(this_01,5,2,3,2,d_menu_fmap2::_4185,d_menu_fmap2::_4117,0,0x2000);
  }
  *(STControl **)(this + 0x30) = this_01;
  if (*(int *)(this + 0x30) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.cpp",0x140,"stick != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x140,&DAT_8035ff21);
  }
  pvVar2 = JKernel::operator_new(0x150);
  if (pvVar2 != (void *)0x0) {
    *(undefined4 *)((int)pvVar2 + 0x20) = 0;
    *(undefined4 *)((int)pvVar2 + 0x18) = 0;
    *(undefined4 *)((int)pvVar2 + 0x2c) = 0;
    *(undefined *)((int)pvVar2 + 0x74) = 0;
  }
  *(void **)(this + 0x3c) = pvVar2;
  if (*(int *)(this + 0x3c) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.cpp",0x144,"outFont[0] != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x144,&DAT_8035ff21);
  }
  pvVar2 = JKernel::operator_new(0x150);
  if (pvVar2 != (void *)0x0) {
    *(undefined4 *)((int)pvVar2 + 0x20) = 0;
    *(undefined4 *)((int)pvVar2 + 0x18) = 0;
    *(undefined4 *)((int)pvVar2 + 0x2c) = 0;
    *(undefined *)((int)pvVar2 + 0x74) = 0;
  }
  *(void **)(this + 0x40) = pvVar2;
  if (*(int *)(this + 0x40) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.cpp",0x147,"outFont[1] != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x147,&DAT_8035ff21);
  }
  pvVar2 = JKernel::operator_new(0x150);
  if (pvVar2 != (void *)0x0) {
    *(undefined4 *)((int)pvVar2 + 0x20) = 0;
    *(undefined4 *)((int)pvVar2 + 0x18) = 0;
    *(undefined4 *)((int)pvVar2 + 0x2c) = 0;
    *(undefined *)((int)pvVar2 + 0x74) = 0;
  }
  *(void **)(this + 0x44) = pvVar2;
  if (*(int *)(this + 0x44) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.cpp",0x14a,"outFontS[0] != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x14a,&DAT_8035ff21);
  }
  pvVar2 = JKernel::operator_new(0x150);
  if (pvVar2 != (void *)0x0) {
    *(undefined4 *)((int)pvVar2 + 0x20) = 0;
    *(undefined4 *)((int)pvVar2 + 0x18) = 0;
    *(undefined4 *)((int)pvVar2 + 0x2c) = 0;
    *(undefined *)((int)pvVar2 + 0x74) = 0;
  }
  *(void **)(this + 0x48) = pvVar2;
  if (*(int *)(this + 0x48) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.cpp",0x14d,"outFontS[1] != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x14d,&DAT_8035ff21);
  }
  pJVar3 = m_Do_ext::mDoExt_getMesgFont();
  *(JUTFont **)(this + 0x34) = pJVar3;
  pJVar3 = m_Do_ext::mDoExt_getRubyFont();
  *(JUTFont **)(this + 0x38) = pJVar3;
  pvVar2 = JKernel::operator_new(0x2c00,0x20);
  *(void **)(this + 4) = pvVar2;
  if (*(int *)(this + 4) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.cpp",0x154,"mChkPntTxt_p != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x154,&DAT_8035ff21);
  }
  pvVar2 = JKernel::operator_new(0x2c00,0x20);
  *(void **)(this + 8) = pvVar2;
  if (*(int *)(this + 8) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.cpp",0x158,"mCmapTxtMain_p[0] != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x158,&DAT_8035ff21);
  }
  pvVar2 = JKernel::operator_new(0x2c00,0x20);
  *(void **)(this + 0xc) = pvVar2;
  if (*(int *)(this + 0xc) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.cpp",0x15a,"mCmapTxtMain_p[1] != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x15a,&DAT_8035ff21);
  }
  screenSet(this);
  this[0x27fb] = (dMenu_Fmap2_c)0x0;
  DAT_803e61d0 = mDoHIO_subRoot_c::createChild
                           (&mDoHIO_subRoot_c_803a5778,"フィールドマップ画面2",
                            (JORReflexible *)&d_menu_fmap2::g_mf2HIO);
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __thiscall dMenu_Fmap2_c::screenSet(void) */

void __thiscall dMenu_Fmap2_c::screenSet(dMenu_Fmap2_c *this)

{
  J2DScreen *pJVar1;
  char *pcVar2;
  undefined4 uVar3;
  fopMsgM_pane_class *pfVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  dMenu_Fmap2_c dStack1109;
  dMenu_Fmap2_c dStack1105;
  char local_448 [127];
  undefined local_3c9;
  char local_3c8 [255];
  undefined local_2c9;
  dDlst_2DOutFont_c adStack712 [24];
  undefined4 local_2b0;
  undefined4 local_2a8;
  undefined4 local_29c;
  undefined4 local_298;
  undefined4 local_294;
  undefined local_254;
  dDlst_2DOutFont_c adStack376 [24];
  undefined4 local_160;
  undefined4 local_158;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined local_104;
  
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636c)
  ;
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x4c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x4b646d);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x404),pJVar1);
  iVar8 = 0x46633031;
  iVar10 = 0x46633131;
  iVar6 = 0x63633031;
  iVar5 = 0x63633131;
  iVar7 = 0;
  iVar9 = 0;
  do {
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),iVar8);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar9 + 0x84),pJVar1);
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),iVar10);
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + (iVar7 + 4) * 0x38 + 0x84),pJVar1);
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),iVar6);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar9 + 0x244),pJVar1);
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),iVar5);
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + (iVar7 + 4) * 0x38 + 0x244),pJVar1);
    iVar7 = iVar7 + 1;
    iVar8 = iVar8 + 1;
    iVar10 = iVar10 + 1;
    iVar6 = iVar6 + 1;
    iVar5 = iVar5 + 1;
    iVar9 = iVar9 + 0x38;
  } while (iVar7 < 4);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x6e636464);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x12fc),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x6d6b4344);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x128c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x6d6b6d30);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x12c4),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x6d7377);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x43c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x6d7354);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x474),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x6d735432);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x4ac),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x6d735231);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x4e4),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x6d735232);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x51c),pJVar1);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x474),*(JUTFont **)(this + 0x34));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x4ac),*(JUTFont **)(this + 0x34));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x4e4),*(JUTFont **)(this + 0x38));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x51c),*(JUTFont **)(this + 0x38));
  local_158 = 0;
  local_160 = 0;
  local_14c = 0;
  local_104 = 0;
  local_2a8 = 0;
  local_2b0 = 0;
  local_29c = 0;
  local_254 = 0;
  dDlst_2DOutFont_c::setPaneEx
            (adStack376,*(JUTFont **)(this + 0x34),(fopMsgM_pane_class *)(this + 0x474),
             (fopMsgM_pane_class *)0x0,(fopMsgM_pane_class *)0x0,(fopMsgM_pane_class *)0x0,
             (char *)0x0);
  dDlst_2DOutFont_c::setPaneEx
            (adStack712,*(JUTFont **)(this + 0x34),(fopMsgM_pane_class *)(this + 0x4ac),
             (fopMsgM_pane_class *)0x0,(fopMsgM_pane_class *)0x0,(fopMsgM_pane_class *)0x0,
             (char *)0x0);
  dDlst_2DOutFont_c::setRuby
            (adStack376,*(JUTFont **)(this + 0x38),(fopMsgM_pane_class *)(this + 0x4e4));
  pfVar4 = (fopMsgM_pane_class *)(this + 0x51c);
  dDlst_2DOutFont_c::setRuby(adStack712,*(JUTFont **)(this + 0x38),pfVar4);
  dDlst_2DOutFont_c::messageSet(adStack376,0x319f);
  dDlst_2DOutFont_c::messageSet(adStack712,0x319f);
  local_144 = *(undefined4 *)(this + 0x484);
  local_148 = *(undefined4 *)(this + 0x480);
  local_294 = *(undefined4 *)(this + 0x4bc);
  local_298 = *(undefined4 *)(this + 0x4b8);
  dDlst_2DOutFont_c::move(adStack376);
  dDlst_2DOutFont_c::move(adStack712);
  pcVar2 = local_3c8;
  iVar5 = 0x100;
  do {
    *pcVar2 = 'A';
    pcVar2 = pcVar2 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar5 = 0;
  local_2c9 = 0;
  iVar6 = 0;
  iVar7 = 0;
  do {
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 0x24) + 0x30))
                       (*(int **)(this + 0x24),
                        *(undefined4 *)((int)&d_menu_fmap2::l_tagNm01_4199 + iVar7));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar6 + 0x554),pJVar1);
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 0x24) + 0x30))
                       (*(int **)(this + 0x24),
                        *(undefined4 *)((int)&d_menu_fmap2::l_tagNm02_4200 + iVar7));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar6 + 0x90c),pJVar1);
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 0x38;
    iVar7 = iVar7 + 4;
  } while (iVar5 < 0x11);
  *(undefined4 *)(this + 0x2830) = *(undefined4 *)(*(int *)(this + 0x58c) + 0xe8);
  *(undefined4 *)(this + 0x2834) = *(undefined4 *)(*(int *)(this + 0x58c) + 0xec);
  *(undefined4 *)(this + 0x2838) = *(undefined4 *)(*(int *)(this + 0x5fc) + 0xe8);
  *(undefined4 *)(this + 0x283c) = *(undefined4 *)(*(int *)(this + 0x5fc) + 0xec);
  *(undefined4 *)(this + 0x2840) = *(undefined4 *)(*(int *)(this + 0x58c) + 0xe4);
  *(undefined4 *)(this + 0x2844) = *(undefined4 *)(*(int *)(this + 0x5fc) + 0xe4);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x58c),*(JUTFont **)(this + 0x34));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x5c4),*(JUTFont **)(this + 0x34));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x5fc),*(JUTFont **)(this + 0x38));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x634),*(JUTFont **)(this + 0x38));
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x58c),local_3c8,(___)pfVar4);
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x5c4),local_3c8,(___)pfVar4);
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x5fc),local_3c8,(___)pfVar4);
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x634),local_3c8,(___)pfVar4);
  uVar3 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x58c));
  *(undefined4 *)(this + 0x27d8) = uVar3;
  uVar3 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x5c4));
  *(undefined4 *)(this + 0x27dc) = uVar3;
  uVar3 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x5fc));
  *(undefined4 *)(this + 0x27e8) = uVar3;
  uVar3 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x634));
  *(undefined4 *)(this + 0x27ec) = uVar3;
  **(undefined **)(this + 0x27d8) = 0;
  **(undefined **)(this + 0x27dc) = 0;
  **(undefined **)(this + 0x27e8) = 0;
  **(undefined **)(this + 0x27ec) = 0;
  dDlst_2DOutFont_c::setPaneEx
            (*(dDlst_2DOutFont_c **)(this + 0x3c),*(JUTFont **)(this + 0x34),
             (fopMsgM_pane_class *)(this + 0x58c),(fopMsgM_pane_class *)(this + 0x89c),
             (fopMsgM_pane_class *)0x0,(fopMsgM_pane_class *)0x0,*(char **)(this + 0x27d8));
  dDlst_2DOutFont_c::setRubyEx
            (*(dDlst_2DOutFont_c **)(this + 0x3c),*(JUTFont **)(this + 0x38),
             (fopMsgM_pane_class *)(this + 0x5fc),*(char **)(this + 0x27e8));
  dDlst_2DOutFont_c::setPaneEx
            (*(dDlst_2DOutFont_c **)(this + 0x44),*(JUTFont **)(this + 0x34),
             (fopMsgM_pane_class *)(this + 0x5c4),(fopMsgM_pane_class *)(this + 0x8d4),
             (fopMsgM_pane_class *)0x0,(fopMsgM_pane_class *)0x0,*(char **)(this + 0x27dc));
  pfVar4 = (fopMsgM_pane_class *)(this + 0x634);
  dDlst_2DOutFont_c::setRubyEx
            (*(dDlst_2DOutFont_c **)(this + 0x44),*(JUTFont **)(this + 0x38),pfVar4,
             *(char **)(this + 0x27ec));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x944),*(JUTFont **)(this + 0x34));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x97c),*(JUTFont **)(this + 0x34));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x9b4),*(JUTFont **)(this + 0x38));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x9ec),*(JUTFont **)(this + 0x38));
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x944),local_3c8,(___)pfVar4);
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x97c),local_3c8,(___)pfVar4);
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x9b4),local_3c8,(___)pfVar4);
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x9ec),local_3c8,(___)pfVar4);
  uVar3 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x944));
  *(undefined4 *)(this + 0x27e0) = uVar3;
  uVar3 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x97c));
  *(undefined4 *)(this + 0x27e4) = uVar3;
  uVar3 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x9b4));
  *(undefined4 *)(this + 0x27f0) = uVar3;
  uVar3 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x9ec));
  *(undefined4 *)(this + 0x27f4) = uVar3;
  **(undefined **)(this + 0x27e0) = 0;
  **(undefined **)(this + 0x27e4) = 0;
  **(undefined **)(this + 0x27f0) = 0;
  **(undefined **)(this + 0x27f4) = 0;
  *(dMenu_Fmap2_c **)(this + 0xcc4) = this + 0x554;
  *(dMenu_Fmap2_c **)(this + 0xcc8) = this + 0x90c;
  this[0x2816] = (dMenu_Fmap2_c)0x0;
  dDlst_2DOutFont_c::setPaneEx
            (*(dDlst_2DOutFont_c **)(this + 0x40),*(JUTFont **)(this + 0x34),
             (fopMsgM_pane_class *)(this + 0x944),(fopMsgM_pane_class *)(this + 0xc54),
             (fopMsgM_pane_class *)0x0,(fopMsgM_pane_class *)0x0,*(char **)(this + 0x27e0));
  dDlst_2DOutFont_c::setRubyEx
            (*(dDlst_2DOutFont_c **)(this + 0x40),*(JUTFont **)(this + 0x38),
             (fopMsgM_pane_class *)(this + 0x9b4),*(char **)(this + 0x27f0));
  dDlst_2DOutFont_c::setPaneEx
            (*(dDlst_2DOutFont_c **)(this + 0x48),*(JUTFont **)(this + 0x34),
             (fopMsgM_pane_class *)(this + 0x97c),(fopMsgM_pane_class *)(this + 0xc8c),
             (fopMsgM_pane_class *)0x0,(fopMsgM_pane_class *)0x0,*(char **)(this + 0x27e4));
  pfVar4 = (fopMsgM_pane_class *)(this + 0x9ec);
  dDlst_2DOutFont_c::setRubyEx
            (*(dDlst_2DOutFont_c **)(this + 0x48),*(JUTFont **)(this + 0x38),pfVar4,
             *(char **)(this + 0x27f4));
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x63693232);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xccc),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x63693231);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xd04),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x63693132);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xd3c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x63693131);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xd74),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636d7975);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xe8c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636d7964);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xec4),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636e6430);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xefc),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636d3131);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xf34),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636d3132);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xf6c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636d3231);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xfa4),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636d3232);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xfdc),pJVar1);
  this[0x2814] = (dMenu_Fmap2_c)0x0;
  *(dMenu_Fmap2_c **)(this + 0x1244) = this + 0xf34;
  *(dMenu_Fmap2_c **)(this + 0x1248) = this + 0xfa4;
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636c5331);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1014),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636d3031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x104c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636d7331);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1084),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x4e5a3031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x10bc),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x63636b31);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x10f4),pJVar1);
  *(ushort *)(this + 0x104a) = (ushort)(byte)this[0x1048];
  *(ushort *)(this + 0x1082) = (ushort)(byte)this[0x1080];
  *(ushort *)(this + 0x10ba) = (ushort)(byte)this[0x10b8];
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636c5332);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x112c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636d3032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1164),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636d7332);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x119c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x4e5a3032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x11d4),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x63636b32);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x120c),pJVar1);
  *(ushort *)(this + 0x1162) = (ushort)(byte)this[0x1160];
  *(ushort *)(this + 0x119a) = (ushort)(byte)this[0x1198];
  *(ushort *)(this + 0x11d2) = (ushort)(byte)this[0x11d0];
  *(dMenu_Fmap2_c **)(this + 0x124c) = this + 0x1014;
  *(dMenu_Fmap2_c **)(this + 0x1250) = this + 0x112c;
  this[0x2813] = (dMenu_Fmap2_c)0x0;
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x63646431);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1644),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636c6331);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x167c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636c7967);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x16b4),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636c4231);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x16ec),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x6c6e6b34);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1724),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x63627431);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x175c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x63627432);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1794),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636d7231);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x17cc),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636d7233);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1804),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636c6332);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x183c),pJVar1);
  *(ushort *)(this + 0x167a) = (ushort)(byte)this[0x1678];
  *(ushort *)(this + 0x16b2) = (ushort)(byte)this[0x16b0];
  *(ushort *)(this + 0x16ea) = (ushort)(byte)this[0x16e8];
  *(ushort *)(this + 0x1722) = (ushort)(byte)this[0x1720];
  *(ushort *)(this + 0x1872) = (ushort)(byte)this[0x1870];
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x63646432);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1874),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636c6333);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x18ac),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636c7932);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x18e4),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636c4232);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x191c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x6c6e6b35);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1954),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x63627433);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x198c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x63627434);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x19c4),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636d7232);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x19fc),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636d7234);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1a34),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636c6334);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1a6c),pJVar1);
  *(ushort *)(this + 0x18aa) = (ushort)(byte)this[0x18a8];
  *(ushort *)(this + 0x18e2) = (ushort)(byte)this[0x18e0];
  *(ushort *)(this + 0x191a) = (ushort)(byte)this[0x1918];
  *(ushort *)(this + 0x1952) = (ushort)(byte)this[0x1950];
  *(ushort *)(this + 0x1aa2) = (ushort)(byte)this[0x1aa0];
  *(dMenu_Fmap2_c **)(this + 0x1aa4) = this + 0x1644;
  *(dMenu_Fmap2_c **)(this + 0x1aa8) = this + 0x1874;
  this[0x2815] = (dMenu_Fmap2_c)0x0;
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636d7431);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1484),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636d7432);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x14bc),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x637433);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x14f4),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x637434);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x152c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636d7433);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1564),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636d7434);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x159c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636d6b31);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x15d4),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636d6b32);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x160c),pJVar1);
  pcVar2 = local_448;
  iVar5 = 0x80;
  do {
    *pcVar2 = 'A';
    pcVar2 = pcVar2 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  local_3c9 = 0;
  iVar5 = 0;
  iVar6 = 0;
  iVar7 = 0;
  do {
    iVar8 = iVar7 + 0x1484;
    J2DTextBox::setFont(*(J2DTextBox **)(this + iVar8),*(JUTFont **)(this + 0x34));
    J2DTextBox::setString(*(J2DTextBox **)(this + iVar8),local_448,(___)pfVar4);
    uVar3 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + iVar8));
    *(undefined4 *)(this + iVar6 + 0x27c8) = uVar3;
    **(undefined **)(this + iVar6 + 0x27c8) = 0;
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 0x38;
  } while (iVar5 < 4);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x6e666b64);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1334),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x6d6b4644);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1254),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x6c6e6b33);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xdac),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x52303147);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x136c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636c67);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x13a4),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x666d6b31);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x13dc),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x526b6a6e);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1414),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x636c6732);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x144c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x61726561);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xde4),pJVar1);
  dStack1105 = SUB41(*(undefined4 *)(*(int *)(this + 0xde4) + 0x104),0);
  dStack1109 = SUB41(*(undefined4 *)(*(int *)(this + 0xde4) + 0x108),0);
  this[0x27f8] = dStack1109;
  this[0x27f9] = dStack1105;
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x66647431);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xe1c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x24) + 0x30))(*(int **)(this + 0x24),0x66747331);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xe54),pJVar1);
  iVar5 = 0;
  iVar7 = 0;
  iVar6 = 0;
  do {
    iVar8 = iVar6 + 0xe1c;
    J2DTextBox::setFont(*(J2DTextBox **)(this + iVar8),*(JUTFont **)(this + 0x34));
    J2DTextBox::setString(*(J2DTextBox **)(this + iVar8),local_448,(___)pfVar4);
    uVar3 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + iVar8));
    *(undefined4 *)(this + iVar7 + 0x27c0) = uVar3;
    **(undefined **)(this + iVar7 + 0x27c0) = 0;
    iVar5 = iVar5 + 1;
    iVar7 = iVar7 + 4;
    iVar6 = iVar6 + 0x38;
  } while (iVar5 < 2);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Fmap2_c::initialize(void) */

void __thiscall dMenu_Fmap2_c::initialize(dMenu_Fmap2_c *this)

{
  undefined uVar1;
  byte bVar2;
  daPy_lk_c *pdVar3;
  int iVar4;
  stage_map_info_class *psVar5;
  ulong uVar6;
  dMenu_Fmap2_c dVar7;
  char *in_r5;
  dMenu_Fmap2_c local_28;
  dMenu_Fmap2_c local_27 [7];
  undefined4 local_20;
  uint uStack28;
  
  *(undefined2 *)(this + 0x27ac) = 0;
  this[0x280d] = (dMenu_Fmap2_c)0x0;
  this[0x280e] = (dMenu_Fmap2_c)0x0;
  *(undefined2 *)(this + 0x2848) = 0xffff;
  *(undefined2 *)(this + 0x284a) = 0xffff;
  this[0x27fc] = (dMenu_Fmap2_c)0x0;
  this[0x2810] = (dMenu_Fmap2_c)0x1;
  pdVar3 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  *(float *)(this + 0x27b0) =
       ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent.mPos.x;
  *(float *)(this + 0x27b4) = (pdVar3->parent).parent.mCurrent.mPos.z;
  uStack28 = (int)(short)((pdVar3->parent).parent.mCollisionRot.y + -0x8000) ^ 0x80000000;
  local_20 = 0x43300000;
  *(float *)(this + 0x27b8) =
       (d_menu_fmap2::_4403 * (float)((double)CONCAT44(0x43300000,uStack28) - d_menu_fmap2::_4406))
       / d_menu_fmap2::_4404;
  iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"sea");
  if (iVar4 == 0) {
    dMap_c::point2Grid((dMap_c *)local_27,*(float *)(this + 0x27b0),*(float *)(this + 0x27b4),
                       (char *)&local_28,in_r5);
    this[0x27bc] = local_27[0];
    this[0x27bd] = local_28;
  }
  else {
    this[0x2810] = (dMenu_Fmap2_c)0x0;
    iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Obshop");
    if ((iVar4 != 0) &&
       (iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Abship"),
       iVar4 != 0)) {
      iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"PShip");
      if (iVar4 != 0) {
        psVar5 = (stage_map_info_class *)
                 (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getMapInfo)
                           (0x803c9d58);
        if (psVar5 == (stage_map_info_class *)0x0) {
          this[0x27bc] = (dMenu_Fmap2_c)0x0;
          this[0x27bd] = (dMenu_Fmap2_c)0x0;
        }
        else {
          dVar7 = (dMenu_Fmap2_c)d_stage::dStage_mapInfo_GetOceanX(psVar5);
          this[0x27bc] = dVar7;
          if (this[0x27bc] == (dMenu_Fmap2_c)0x4) {
            this[0x27bc] = (dMenu_Fmap2_c)0x0;
          }
          dVar7 = (dMenu_Fmap2_c)d_stage::dStage_mapInfo_GetOceanZ(psVar5);
          this[0x27bd] = dVar7;
          if (this[0x27bd] == (dMenu_Fmap2_c)0x4) {
            this[0x27bd] = (dMenu_Fmap2_c)0x0;
          }
        }
        goto LAB_801bce50;
      }
    }
    bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mLastSeaRoom / 7;
    this[0x27bc] = (dMenu_Fmap2_c)(d_com_inf_game::g_dComIfG_gameInfo.mLastSeaRoom % 7 - 3);
    this[0x27bd] = (dMenu_Fmap2_c)(bVar2 - 3);
  }
LAB_801bce50:
  if (*(int *)(this + 0x10) == 0) {
    uVar6 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar6,"d_menu_fmap2.h",0x1d2,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.h",0x1d2,&DAT_8035ff21);
  }
  if (-4 < *(char *)(*(int *)(this + 0x10) + 10)) {
    if (*(int *)(this + 0x10) == 0) {
      uVar6 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar6,"d_menu_fmap2.h",0x1dc,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap2.h",0x1dc,&DAT_8035ff21);
    }
    if (-4 < *(char *)(*(int *)(this + 0x10) + 0xb)) {
      if (*(int *)(this + 0x10) == 0) {
        uVar6 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar6,"d_menu_fmap2.h",0x1ac,"fmapSv != 0");
        m_Do_printf::OSPanic("d_menu_fmap2.h",0x1ac,&DAT_8035ff21);
      }
      if (**(char **)(this + 0x10) == '\0') {
        if (*(char **)(this + 0x10) == (char *)0x0) {
          uVar6 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar6,"d_menu_fmap2.h",0x1bd,"fmapSv != 0");
          m_Do_printf::OSPanic("d_menu_fmap2.h",0x1bd,&DAT_8035ff21);
        }
        uVar1 = *(undefined *)(*(int *)(this + 0x10) + 4);
        if (*(int *)(this + 0x10) == 0) {
          uVar6 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar6,"d_menu_fmap2.h",0x1d7,"fmapSv != 0");
          m_Do_printf::OSPanic("d_menu_fmap2.h",0x1d7,&DAT_8035ff21);
        }
        *(undefined *)(*(int *)(this + 0x10) + 10) = uVar1;
        if (*(int *)(this + 0x10) == 0) {
          uVar6 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar6,"d_menu_fmap2.h",0x1c7,"fmapSv != 0");
          m_Do_printf::OSPanic("d_menu_fmap2.h",0x1c7,&DAT_8035ff21);
        }
        uVar1 = *(undefined *)(*(int *)(this + 0x10) + 5);
        if (*(int *)(this + 0x10) == 0) {
          uVar6 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar6,"d_menu_fmap2.h",0x1e1,"fmapSv != 0");
          m_Do_printf::OSPanic("d_menu_fmap2.h",0x1e1,&DAT_8035ff21);
        }
        *(undefined *)(*(int *)(this + 0x10) + 0xb) = uVar1;
      }
      goto LAB_801bd114;
    }
  }
  dVar7 = this[0x27bc];
  if (*(int *)(this + 0x10) == 0) {
    uVar6 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar6,"d_menu_fmap2.h",0x1d7,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.h",0x1d7,&DAT_8035ff21);
  }
  *(dMenu_Fmap2_c *)(*(int *)(this + 0x10) + 10) = dVar7;
  dVar7 = this[0x27bd];
  if (*(int *)(this + 0x10) == 0) {
    uVar6 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar6,"d_menu_fmap2.h",0x1e1,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.h",0x1e1,&DAT_8035ff21);
  }
  *(dMenu_Fmap2_c *)(*(int *)(this + 0x10) + 0xb) = dVar7;
LAB_801bd114:
  playerPointGridAnimeInit(this);
  *(ushort *)(this + 0xec2) = DAT_803e6216 + 1;
  dVar7 = (dMenu_Fmap2_c)calcGetCollectMap(this);
  this[0x27a8] = dVar7;
  if (*(int *)(this + 0x10) == 0) {
    uVar6 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar6,"d_menu_fmap2.h",0x1e8,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.h",0x1e8,&DAT_8035ff21);
  }
  if (*(char *)(*(int *)(this + 0x10) + 9) == -1) {
    dVar7 = (dMenu_Fmap2_c)getNowCmapFirstNum(this);
    this[0x27a9] = dVar7;
    dVar7 = this[0x27a9];
    if (*(int *)(this + 0x10) == 0) {
      uVar6 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar6,"d_menu_fmap2.h",0x1ed,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap2.h",0x1ed,&DAT_8035ff21);
    }
    *(dMenu_Fmap2_c *)(*(int *)(this + 0x10) + 9) = dVar7;
  }
  else {
    if (*(int *)(this + 0x10) == 0) {
      uVar6 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar6,"d_menu_fmap2.h",0x1e8,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap2.h",0x1e8,&DAT_8035ff21);
    }
    this[0x27a9] = *(dMenu_Fmap2_c *)(*(int *)(this + 0x10) + 9);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801bd4a8) */
/* WARNING: Removing unreachable block (ram,0x801bd568) */
/* __thiscall dMenu_Fmap2_c::displayInit(void) */

void __thiscall dMenu_Fmap2_c::displayInit(dMenu_Fmap2_c *this)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  dMenu_Fmap2_c *pdVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 in_f31;
  double dVar8;
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar5 = 0;
  iVar6 = 0;
  do {
    uVar2 = dSv_player_map_c::isSaveArriveGrid
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,iVar5);
    uVar1 = countLeadingZeros(uVar2);
    setPaneOnOff(this,*(J2DScreen **)(this + 0x24),
                 *(ulong *)(
                           "mR01mR02mR03mR04mR05mR06mR07mR08mR09mR0AmR0BmR0CmR0DmR0EmR0FmR10mR11mR12mR13mR14mR15mR16mR17mR18mR19mR1AmR1BmR1CmR1DmR1EmR1FmR20mR21mR22mR23mR24mR25mR26mR27mR28mR29mR2AmR2BmR2CmR2DmR2EmR2FmR30mR31cmap_tri.bti"
                           + iVar6),SUB41(uVar1 >> 5,0));
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 4;
  } while (iVar5 < 0x31);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xde4),
             (double)(d_menu_fmap2::_4467 *
                     (float)((double)CONCAT44(0x43300000,(int)(char)this[0x27bc] ^ 0x80000000) -
                            d_menu_fmap2::_4406)),
             (double)(d_menu_fmap2::_4467 *
                     (float)((double)CONCAT44(0x43300000,(int)(char)this[0x27bd] ^ 0x80000000) -
                            d_menu_fmap2::_4406)));
  fCursorMove(this);
  getCollectMapTexChange(this);
  finCollectMapTexChange(this);
  *(undefined *)(**(int **)(this + (uint)(byte)this[0x2816] * 4 + 0xcc4) + 0xaa) = 0;
  *(undefined *)(**(int **)(this + ((byte)this[0x2816] ^ 1) * 4 + 0xcc4) + 0xaa) = 0;
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ != '\0') {
    iVar5 = 0xa8;
    iVar6 = 2;
    do {
      pdVar4 = this + iVar5;
      *(undefined *)(*(int *)(pdVar4 + 0x43c) + 0xaa) = 0;
      *(undefined *)(*(int *)(pdVar4 + 0x554) + 0xaa) = 0;
      *(undefined *)(*(int *)(pdVar4 + 0x90c) + 0xaa) = 0;
      iVar5 = iVar5 + 0x38;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar5 = 1;
    iVar6 = 0x38;
    dVar8 = (double)d_menu_fmap2::_4468;
    do {
      pdVar4 = this + iVar6;
      *(float *)(pdVar4 + 0x454) = (float)((double)*(float *)(pdVar4 + 0x454) - dVar8);
      *(undefined4 *)(pdVar4 + 0x45c) = *(undefined4 *)(pdVar4 + 0x454);
      *(float *)(pdVar4 + 0x56c) = (float)((double)*(float *)(pdVar4 + 0x56c) - dVar8);
      *(undefined4 *)(pdVar4 + 0x574) = *(undefined4 *)(pdVar4 + 0x56c);
      *(float *)(pdVar4 + 0x924) = (float)((double)*(float *)(pdVar4 + 0x924) - dVar8);
      *(undefined4 *)(pdVar4 + 0x92c) = *(undefined4 *)(pdVar4 + 0x924);
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar4 + 0x43c));
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar4 + 0x554));
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar4 + 0x90c));
      *(undefined4 *)(pdVar4 + 0x444) = *(undefined4 *)(pdVar4 + 0x44c);
      *(undefined4 *)(pdVar4 + 0x55c) = *(undefined4 *)(pdVar4 + 0x564);
      *(undefined4 *)(pdVar4 + 0x914) = *(undefined4 *)(pdVar4 + 0x91c);
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 0x38;
    } while (iVar5 < 3);
  }
  collectMapCheck(this);
  if (*(int *)(this + 0x10) == 0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_menu_fmap2.h",0x1b2,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.h",0x1b2,&DAT_8035ff21);
  }
  if (*(char *)(*(int *)(this + 0x10) + 8) == '\x01') {
    cmapPaneInit(this);
    STControl::setWaitParm
              (*(STControl **)(this + 0x30),0,0,0,0,d_menu_fmap2::_4185,d_menu_fmap2::_4117,0,0x800)
    ;
    this[0x27a1] = (dMenu_Fmap2_c)0x2;
  }
  else {
    if (*(char *)(*(int *)(this + 0x10) + 8) == '\0') {
      fmapPaneInit(this);
      STControl::setWaitParm
                (*(STControl **)(this + 0x30),5,2,3,2,d_menu_fmap2::_4185,d_menu_fmap2::_4117,0,
                 0x800);
      this[0x27a1] = (dMenu_Fmap2_c)0x0;
    }
  }
  paneTransBase(this,0,DAT_803e6204,
                (float)((double)CONCAT44(0x43300000,(int)DAT_803e6206 ^ 0x80000000) -
                       d_menu_fmap2::_4406),d_menu_fmap2::_4118,'\0',(uchar)this[0x2815],0);
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return;
}


/* __thiscall dMenu_Fmap2_c::fmapPaneInit(void) */

void __thiscall dMenu_Fmap2_c::fmapPaneInit(dMenu_Fmap2_c *this)

{
  *(undefined *)(*(int *)(this + 0x128c) + 0xaa) = 1;
  *(undefined *)(*(int *)(this + 0x1254) + 0xaa) = 0;
  if (*(char *)(*(int *)(this + 0x43c) + 0xaa) != '\0') {
    paneAlphaMessage2(this,*(short *)(this + 0x27ac),DAT_803e620a,'\0',0);
  }
  if (*(char *)(**(int **)(this + (uint)(byte)this[0x2816] * 4 + 0xcc4) + 0xaa) != '\0') {
    paneTranceMessage(this,*(short *)(this + 0x27ac),DAT_803e620a,d_menu_fmap2::_4119,
                      d_menu_fmap2::_4119,d_menu_fmap2::_4118,d_menu_fmap2::_4118,'\0',
                      (uchar)this[0x2816],0);
  }
  if (*(char *)(**(int **)(this + (uint)(byte)this[0x2815] * 4 + 0x1aa4) + 0xaa) == '\0') {
    this[0x12f9] = (dMenu_Fmap2_c)0x80;
    this[0x12f8] = (dMenu_Fmap2_c)0x80;
  }
  else {
    this[0x12f9] = (dMenu_Fmap2_c)0x40;
    this[0x12f8] = (dMenu_Fmap2_c)0x40;
  }
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x12c4));
  this[0xf31] = (dMenu_Fmap2_c)0x30;
  this[0xf30] = (dMenu_Fmap2_c)0x30;
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xefc));
  cSelCursorHide(this);
  cCursorHide(this);
  fCursorInit(this);
  return;
}


/* __thiscall dMenu_Fmap2_c::cmapPaneInit(void) */

void __thiscall dMenu_Fmap2_c::cmapPaneInit(dMenu_Fmap2_c *this)

{
  *(undefined *)(*(int *)(this + 0x1254) + 0xaa) = 1;
  *(undefined *)(*(int *)(this + 0x128c) + 0xaa) = 0;
  this[0xf31] = (dMenu_Fmap2_c)0xaa;
  this[0xf30] = (dMenu_Fmap2_c)0xaa;
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xefc));
  fCursorInit(this);
  return;
}


/* __thiscall dMenu_Fmap2_c::collectMapCheck(void) */

void __thiscall dMenu_Fmap2_c::collectMapCheck(dMenu_Fmap2_c *this)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (this[0x27a8] == (dMenu_Fmap2_c)0x0) {
    *(undefined *)(*(int *)(this + 0x43c) + 0xaa) = 1;
    cSelCursorHide(this);
    cCursorHide(this);
    *(undefined *)(*(int *)(this + 0xefc) + 0xaa) = 0;
    iVar2 = 0;
    iVar3 = 8;
    do {
      *(undefined *)(*(int *)(this + iVar2 + 0x1484) + 0xaa) = 0;
      iVar2 = iVar2 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar2 = 0;
    iVar3 = 5;
    do {
      *(undefined *)
       (*(int *)(*(int *)(this + (uint)(byte)this[0x2813] * 4 + 0x124c) + iVar2) + 0xaa) = 0;
      iVar2 = iVar2 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar2 = 0;
    iVar3 = 2;
    do {
      *(undefined *)
       (*(int *)(*(int *)(this + (uint)(byte)this[0x2814] * 4 + 0x1244) + iVar2) + 0xaa) = 0;
      iVar2 = iVar2 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *(undefined *)(**(int **)(this + (uint)(byte)this[0x2815] * 4 + 0x1aa4) + 0xaa) = 0;
  }
  else {
    cCursorAnimeInit(this);
    if ((byte)this[0x27a8] < 2) {
      cSelCursorHide(this);
    }
    else {
      cSelCursorInit(this);
    }
    *(undefined *)(**(int **)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0xaa) = 0;
    *(undefined *)(**(int **)(this + ((byte)this[0x2816] ^ 1) * 4 + 0xcc4) + 0xaa) = 0;
    iVar2 = 0;
    iVar3 = 2;
    do {
      *(undefined *)
       (*(int *)(*(int *)(this + ((byte)this[0x2814] ^ 1) * 4 + 0x1244) + iVar2) + 0xaa) = 0;
      iVar2 = iVar2 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar2 = 0;
    iVar3 = 5;
    do {
      *(undefined *)
       (*(int *)(*(int *)(this + ((byte)this[0x2813] ^ 1) * 4 + 0x124c) + iVar2) + 0xaa) = 0;
      iVar2 = iVar2 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    paneTransSelCmapCle(this,0,DAT_803e6230,DAT_803e622c,d_menu_fmap2::_4119,d_menu_fmap2::_4118,
                        d_menu_fmap2::_4118,'\x04',(byte)this[0x2814] ^ 1,0);
    paneTransSelCmapOpn(this,0,DAT_803e6230,DAT_803e622c,d_menu_fmap2::_4119,d_menu_fmap2::_4118,
                        d_menu_fmap2::_4118,'\x04',(byte)this[0x2813] ^ 1,0);
    paneAlphaZoomCmapBase
              (this,0,DAT_803e6230,d_menu_fmap2::_4118,d_menu_fmap2::_4118,'\0',
               (byte)this[0x2815] ^ 1,0);
    paneTranceMessage(this,0,DAT_803e6230,d_menu_fmap2::_4119,d_menu_fmap2::_4119,
                      d_menu_fmap2::_4118,d_menu_fmap2::_4118,'\0',(byte)this[0x2816] ^ 1,0);
    paneAlphaCmapName(this,0,DAT_803e6230,'\0');
    this[0x2813] = (dMenu_Fmap2_c)((byte)this[0x2813] ^ 1);
    this[0x2814] = (dMenu_Fmap2_c)((byte)this[0x2814] ^ 1);
    this[0x2815] = (dMenu_Fmap2_c)((byte)this[0x2815] ^ 1);
    this[0x2816] = (dMenu_Fmap2_c)((byte)this[0x2816] ^ 1);
    cmapMove(this);
    this[0x2813] = (dMenu_Fmap2_c)((byte)this[0x2813] ^ 1);
    this[0x2814] = (dMenu_Fmap2_c)((byte)this[0x2814] ^ 1);
    this[0x2815] = (dMenu_Fmap2_c)((byte)this[0x2815] ^ 1);
    this[0x2816] = (dMenu_Fmap2_c)((byte)this[0x2816] ^ 1);
    iVar3 = *(int *)(this + (uint)(byte)this[0x2816] * 4 + 0xcc4);
    uVar1 = *(undefined4 *)(iVar3 + 0x48);
    iVar2 = *(int *)(this + (uint)(byte)this[0x2816] * 4 + 0x3c);
    *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(iVar3 + 0x44);
    *(undefined4 *)(iVar2 + 0x34) = uVar1;
    iVar3 = *(int *)(this + (uint)(byte)this[0x2816] * 4 + 0xcc4);
    uVar1 = *(undefined4 *)(iVar3 + 0x80);
    iVar2 = *(int *)(this + (uint)(byte)this[0x2816] * 4 + 0x44);
    *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(iVar3 + 0x7c);
    *(undefined4 *)(iVar2 + 0x34) = uVar1;
    dDlst_2DOutFont_c::move(*(dDlst_2DOutFont_c **)(this + (uint)(byte)this[0x2816] * 4 + 0x3c));
    dDlst_2DOutFont_c::move(*(dDlst_2DOutFont_c **)(this + (uint)(byte)this[0x2816] * 4 + 0x44));
    iVar2 = *(int *)(*(int *)(this + (uint)(byte)this[0x2816] * 4 + 0xcc4) + 0x380);
    *(undefined *)(iVar2 + 0x108) = 0;
    *(undefined *)(iVar2 + 0x109) = 0;
    *(undefined *)(iVar2 + 0x10a) = 0;
    *(undefined *)(iVar2 + 0x10b) = 0;
    *(undefined *)(iVar2 + 0x104) = 0;
    *(undefined *)(iVar2 + 0x105) = 0;
    *(undefined *)(iVar2 + 0x106) = 0;
    *(undefined *)(iVar2 + 0x107) = 0xff;
    *(undefined *)(*(int *)(*(int *)(this + (uint)(byte)this[0x2816] * 4 + 0xcc4) + 0x380) + 0xac) =
         0x40;
  }
  return;
}


/* __thiscall dMenu_Fmap2_c::_move(void) */

void __thiscall dMenu_Fmap2_c::_move(dMenu_Fmap2_c *this)

{
  undefined4 uVar1;
  ulong uVar2;
  char cVar4;
  int iVar3;
  
  STControl::checkTrigger(*(STControl **)(this + 0x30));
  if ((this[0x27a1] == (dMenu_Fmap2_c)0x0) || (this[0x27a1] == (dMenu_Fmap2_c)0x2)) {
    if (m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mTriggerRightLevel == 0) {
      if (m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mTriggerLeftLevel != 0) {
        if (*(int *)(this + 0x10) == 0) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_menu_fmap2.h",0x1b2,"fmapSv != 0");
          m_Do_printf::OSPanic("d_menu_fmap2.h",0x1b2,&DAT_8035ff21);
        }
        if (*(char *)(*(int *)(this + 0x10) + 8) == '\x01') {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x8c7,(cXyz *)0x0,0,0,d_menu_fmap2::_4119,
                     d_menu_fmap2::_4119,d_menu_fmap2::_4713,d_menu_fmap2::_4713,0);
          if (*(int *)(this + 0x10) == 0) {
            uVar2 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar2,"d_menu_fmap2.h",0x1b7,"fmapSv != 0");
            m_Do_printf::OSPanic("d_menu_fmap2.h",0x1b7,&DAT_8035ff21);
          }
          *(undefined *)(*(int *)(this + 0x10) + 8) = 0;
          if (*(char *)(**(int **)(this + (uint)(byte)this[0x2815] * 4 + 0x1aa4) + 0xaa) == '\0') {
            this[0x12f9] = (dMenu_Fmap2_c)0x80;
            this[0x12f8] = (dMenu_Fmap2_c)0x80;
          }
          else {
            this[0x12f9] = (dMenu_Fmap2_c)0x40;
            this[0x12f8] = (dMenu_Fmap2_c)0x40;
          }
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x12c4));
          cCursorHide(this);
          cSelCursorHide(this);
          playerPointGridAnimeInit(this);
          STControl::setWaitParm
                    (*(STControl **)(this + 0x30),5,2,3,2,d_menu_fmap2::_4185,d_menu_fmap2::_4117,0,
                     0x800);
          *(undefined *)(*(int *)(this + 0x128c) + 0xaa) = 1;
          paneAlphaFmapBase(this,*(short *)(this + 0x27ac),DAT_803e620a,'\0',0);
          this[0x27a1] = (dMenu_Fmap2_c)0x9;
        }
      }
    }
    else {
      if (*(int *)(this + 0x10) == 0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_menu_fmap2.h",0x1b2,"fmapSv != 0");
        m_Do_printf::OSPanic("d_menu_fmap2.h",0x1b2,&DAT_8035ff21);
      }
      if (*(char *)(*(int *)(this + 0x10) + 8) == '\0') {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x8c7,(cXyz *)0x0,0,0,d_menu_fmap2::_4119,
                   d_menu_fmap2::_4119,d_menu_fmap2::_4713,d_menu_fmap2::_4713,0);
        if (*(int *)(this + 0x10) == 0) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_menu_fmap2.h",0x1b7,"fmapSv != 0");
          m_Do_printf::OSPanic("d_menu_fmap2.h",0x1b7,&DAT_8035ff21);
        }
        *(undefined *)(*(int *)(this + 0x10) + 8) = 1;
        fCursorInit(this);
        playerPointGridAnimeInit(this);
        playerPointGridAnime(this,(fopMsgM_pane_class *)(this + 0xde4));
        STControl::setWaitParm
                  (*(STControl **)(this + 0x30),0,0,0,0,d_menu_fmap2::_4185,d_menu_fmap2::_4117,0,
                   0x800);
        *(undefined *)(*(int *)(this + 0x1254) + 0xaa) = 1;
        paneAlphaCmapBase(this,*(short *)(this + 0x27ac),DAT_803e620a,'\0',0);
        this[0x27a1] = (dMenu_Fmap2_c)0x9;
      }
    }
  }
  if (1 < (byte)this[0x27a1]) {
    cVar4 = STControl::checkLeftTrigger(*(STControl **)(this + 0x30));
    if (cVar4 == '\0') {
      this[0x280d] = (dMenu_Fmap2_c)0x0;
    }
    else {
      if ((byte)this[0x280d] < (byte)DAT_803e6241) {
        this[0x280d] = (dMenu_Fmap2_c)((char)this[0x280d] + 1);
      }
    }
    cVar4 = STControl::checkRightTrigger(*(STControl **)(this + 0x30));
    if (cVar4 == '\0') {
      this[0x280e] = (dMenu_Fmap2_c)0x0;
    }
    else {
      if ((byte)this[0x280e] < (byte)DAT_803e6241) {
        this[0x280e] = (dMenu_Fmap2_c)((char)this[0x280e] + 1);
      }
    }
  }
  Runtime.PPCEABI.H::__ptmf_scall
            ((PTMF *)(&d_menu_fmap2::mainProc + (uint)(byte)this[0x27a1] * 3),this,&DAT_80390000);
  if (*(int *)(this + 0x10) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_fmap2.h",0x1b2,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.h",0x1b2,&DAT_8035ff21);
  }
  if (*(char *)(*(int *)(this + 0x10) + 8) == '\x01') {
    cSelCursorAnime(this);
    if (*(ushort *)(this + 0x2848) != 0xffff) {
      dDlst_2DOutFont_c::messageSet
                (*(dDlst_2DOutFont_c **)(this + 0x3c),(uint)*(ushort *)(this + 0x2848));
      dDlst_2DOutFont_c::messageSet
                (*(dDlst_2DOutFont_c **)(this + 0x44),(uint)*(ushort *)(this + 0x2848));
    }
    uVar1 = *(undefined4 *)(*(int *)(this + 0xcc4) + 0x48);
    iVar3 = *(int *)(this + 0x3c);
    *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)(*(int *)(this + 0xcc4) + 0x44);
    *(undefined4 *)(iVar3 + 0x34) = uVar1;
    uVar1 = *(undefined4 *)(*(int *)(this + 0xcc4) + 0x80);
    iVar3 = *(int *)(this + 0x44);
    *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)(*(int *)(this + 0xcc4) + 0x7c);
    *(undefined4 *)(iVar3 + 0x34) = uVar1;
    dDlst_2DOutFont_c::move(*(dDlst_2DOutFont_c **)(this + 0x3c));
    dDlst_2DOutFont_c::move(*(dDlst_2DOutFont_c **)(this + 0x44));
    if (*(ushort *)(this + 0x284a) != 0xffff) {
      dDlst_2DOutFont_c::messageSet
                (*(dDlst_2DOutFont_c **)(this + 0x40),(uint)*(ushort *)(this + 0x284a));
      dDlst_2DOutFont_c::messageSet
                (*(dDlst_2DOutFont_c **)(this + 0x48),(uint)*(ushort *)(this + 0x284a));
    }
    uVar1 = *(undefined4 *)(*(int *)(this + 0xcc8) + 0x48);
    iVar3 = *(int *)(this + 0x40);
    *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)(*(int *)(this + 0xcc8) + 0x44);
    *(undefined4 *)(iVar3 + 0x34) = uVar1;
    uVar1 = *(undefined4 *)(*(int *)(this + 0xcc8) + 0x80);
    iVar3 = *(int *)(this + 0x48);
    *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)(*(int *)(this + 0xcc8) + 0x7c);
    *(undefined4 *)(iVar3 + 0x34) = uVar1;
    dDlst_2DOutFont_c::move(*(dDlst_2DOutFont_c **)(this + 0x40));
    dDlst_2DOutFont_c::move(*(dDlst_2DOutFont_c **)(this + 0x48));
    iVar3 = *(int *)(*(int *)(this + (uint)(byte)this[0x2816] * 4 + 0xcc4) + 0x380);
    *(undefined *)(iVar3 + 0x108) = 0;
    *(undefined *)(iVar3 + 0x109) = 0;
    *(undefined *)(iVar3 + 0x10a) = 0;
    *(undefined *)(iVar3 + 0x10b) = 0;
    *(undefined *)(iVar3 + 0x104) = 0;
    *(undefined *)(iVar3 + 0x105) = 0;
    *(undefined *)(iVar3 + 0x106) = 0;
    *(undefined *)(iVar3 + 0x107) = 0xff;
    *(undefined *)(*(int *)(*(int *)(this + (uint)(byte)this[0x2816] * 4 + 0xcc4) + 0x380) + 0xac) =
         0x40;
  }
  return;
}


/* __thiscall dMenu_Fmap2_c::FmapProcMain(void) */

void __thiscall dMenu_Fmap2_c::FmapProcMain(dMenu_Fmap2_c *this)

{
  char cVar2;
  ulong uVar1;
  
  cVar2 = STControl::checkLeftTrigger(*(STControl **)(this + 0x30));
  if (cVar2 == '\0') {
    cVar2 = STControl::checkRightTrigger(*(STControl **)(this + 0x30));
    if (cVar2 == '\0') {
      cVar2 = STControl::checkUpTrigger(*(STControl **)(this + 0x30));
      if (cVar2 == '\0') {
        cVar2 = STControl::checkDownTrigger(*(STControl **)(this + 0x30));
        if (cVar2 != '\0') {
          if (*(int *)(this + 0x10) == 0) {
            uVar1 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar1,"d_menu_fmap2.h",0x1dc,"fmapSv != 0");
            m_Do_printf::OSPanic("d_menu_fmap2.h",0x1dc,&DAT_8035ff21);
          }
          if (*(char *)(*(int *)(this + 0x10) + 0xb) < '\x03') {
            if (*(int *)(this + 0x10) == 0) {
              uVar1 = JUTAssertion::getSDevice();
              JUTAssertion::showAssert(uVar1,"d_menu_fmap2.h",0x1dc,"fmapSv != 0");
              m_Do_printf::OSPanic("d_menu_fmap2.h",0x1dc,&DAT_8035ff21);
            }
            cVar2 = *(char *)(*(int *)(this + 0x10) + 0xb);
            if (*(int *)(this + 0x10) == 0) {
              uVar1 = JUTAssertion::getSDevice();
              JUTAssertion::showAssert(uVar1,"d_menu_fmap2.h",0x1e1,"fmapSv != 0");
              m_Do_printf::OSPanic("d_menu_fmap2.h",0x1e1,&DAT_8035ff21);
            }
            *(char *)(*(int *)(this + 0x10) + 0xb) = cVar2 + '\x01';
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x8c3,(cXyz *)0x0,0,0,d_menu_fmap2::_4119,
                       d_menu_fmap2::_4119,d_menu_fmap2::_4713,d_menu_fmap2::_4713,0);
            *(undefined *)(*(int *)(this + 0x136c) + 0xaa) = 0;
            this[0x27a1] = (dMenu_Fmap2_c)0x1;
          }
        }
      }
      else {
        if (*(int *)(this + 0x10) == 0) {
          uVar1 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar1,"d_menu_fmap2.h",0x1dc,"fmapSv != 0");
          m_Do_printf::OSPanic("d_menu_fmap2.h",0x1dc,&DAT_8035ff21);
        }
        if (-3 < *(char *)(*(int *)(this + 0x10) + 0xb)) {
          if (*(int *)(this + 0x10) == 0) {
            uVar1 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar1,"d_menu_fmap2.h",0x1dc,"fmapSv != 0");
            m_Do_printf::OSPanic("d_menu_fmap2.h",0x1dc,&DAT_8035ff21);
          }
          cVar2 = *(char *)(*(int *)(this + 0x10) + 0xb);
          if (*(int *)(this + 0x10) == 0) {
            uVar1 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar1,"d_menu_fmap2.h",0x1e1,"fmapSv != 0");
            m_Do_printf::OSPanic("d_menu_fmap2.h",0x1e1,&DAT_8035ff21);
          }
          *(char *)(*(int *)(this + 0x10) + 0xb) = cVar2 + -1;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x8c3,(cXyz *)0x0,0,0,d_menu_fmap2::_4119,
                     d_menu_fmap2::_4119,d_menu_fmap2::_4713,d_menu_fmap2::_4713,0);
          *(undefined *)(*(int *)(this + 0x136c) + 0xaa) = 0;
          this[0x27a1] = (dMenu_Fmap2_c)0x1;
        }
      }
    }
    else {
      if (*(int *)(this + 0x10) == 0) {
        uVar1 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar1,"d_menu_fmap2.h",0x1d2,"fmapSv != 0");
        m_Do_printf::OSPanic("d_menu_fmap2.h",0x1d2,&DAT_8035ff21);
      }
      if (*(char *)(*(int *)(this + 0x10) + 10) < '\x03') {
        if (*(int *)(this + 0x10) == 0) {
          uVar1 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar1,"d_menu_fmap2.h",0x1d2,"fmapSv != 0");
          m_Do_printf::OSPanic("d_menu_fmap2.h",0x1d2,&DAT_8035ff21);
        }
        cVar2 = *(char *)(*(int *)(this + 0x10) + 10);
        if (*(int *)(this + 0x10) == 0) {
          uVar1 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar1,"d_menu_fmap2.h",0x1d7,"fmapSv != 0");
          m_Do_printf::OSPanic("d_menu_fmap2.h",0x1d7,&DAT_8035ff21);
        }
        *(char *)(*(int *)(this + 0x10) + 10) = cVar2 + '\x01';
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x8c3,(cXyz *)0x0,0,0,d_menu_fmap2::_4119,
                   d_menu_fmap2::_4119,d_menu_fmap2::_4713,d_menu_fmap2::_4713,0);
        *(undefined *)(*(int *)(this + 0x136c) + 0xaa) = 0;
        this[0x27a1] = (dMenu_Fmap2_c)0x1;
      }
    }
  }
  else {
    if (*(int *)(this + 0x10) == 0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"d_menu_fmap2.h",0x1d2,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap2.h",0x1d2,&DAT_8035ff21);
    }
    if (-3 < *(char *)(*(int *)(this + 0x10) + 10)) {
      if (*(int *)(this + 0x10) == 0) {
        uVar1 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar1,"d_menu_fmap2.h",0x1d2,"fmapSv != 0");
        m_Do_printf::OSPanic("d_menu_fmap2.h",0x1d2,&DAT_8035ff21);
      }
      cVar2 = *(char *)(*(int *)(this + 0x10) + 10);
      if (*(int *)(this + 0x10) == 0) {
        uVar1 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar1,"d_menu_fmap2.h",0x1d7,"fmapSv != 0");
        m_Do_printf::OSPanic("d_menu_fmap2.h",0x1d7,&DAT_8035ff21);
      }
      *(char *)(*(int *)(this + 0x10) + 10) = cVar2 + -1;
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8c3,(cXyz *)0x0,0,0,d_menu_fmap2::_4119,
                 d_menu_fmap2::_4119,d_menu_fmap2::_4713,d_menu_fmap2::_4713,0);
      *(undefined *)(*(int *)(this + 0x136c) + 0xaa) = 0;
      this[0x27a1] = (dMenu_Fmap2_c)0x1;
    }
  }
  fCursorAnime(this);
  playerPointGridAnime(this,(fopMsgM_pane_class *)(this + 0xde4));
  return;
}


/* __thiscall dMenu_Fmap2_c::FmapChange(void) */

void __thiscall dMenu_Fmap2_c::FmapChange(dMenu_Fmap2_c *this)

{
  fCursorMove(this);
  *(undefined *)(*(int *)(this + 0x136c) + 0xaa) = 1;
  this[0x27a1] = (dMenu_Fmap2_c)0x0;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Fmap2_c::CmapProcMain(void) */

void __thiscall dMenu_Fmap2_c::CmapProcMain(dMenu_Fmap2_c *this)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  
  if (this[0x27a8] != (dMenu_Fmap2_c)0x0) {
    iVar4 = (int)(char)this[0x27a9];
    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
      cVar3 = STControl::checkLeftTrigger(*(STControl **)(this + 0x30));
      if (cVar3 == '\0') {
        cVar3 = STControl::checkRightTrigger(*(STControl **)(this + 0x30));
        if (cVar3 != '\0') {
          this[0x27ab] = (dMenu_Fmap2_c)0x1;
          iVar4 = getNowCmapNextNum(this,(char)this[0x27a9],(int)(char)this[0x27ab]);
        }
      }
      else {
        this[0x27ab] = (dMenu_Fmap2_c)0xff;
        iVar4 = getNowCmapNextNum(this,(char)this[0x27a9],(int)(char)this[0x27ab]);
      }
    }
    else {
      iVar1 = getCollectMapKind(this,(char)this[0x27a9]);
      *(undefined2 *)(this + 0x27ac) = 0;
      iVar2 = isSpMap(this,iVar1);
      if (iVar2 == 0) {
        iVar1 = cmapOpenCheck(this);
        if (iVar1 == 1) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x8c8,(cXyz *)0x0,0,0,d_menu_fmap2::_4119,
                     d_menu_fmap2::_4119,d_menu_fmap2::_4713,d_menu_fmap2::_4713,0);
          this[0x27fc] = (dMenu_Fmap2_c)0x1;
          iVar1 = 0;
          iVar2 = 3;
          do {
            *(char *)(*(int *)(this + (uint)(byte)this[0x2813] * 4 + 0x124c) + iVar1 + 0x34) =
                 (char)*(undefined2 *)
                        (*(int *)(this + (uint)(byte)this[0x2813] * 4 + 0x124c) + iVar1 + 0x36);
            iVar1 = iVar1 + 0x38;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
          iVar1 = 0;
          iVar2 = 4;
          do {
            *(char *)(*(int *)(this + (uint)(byte)this[0x2815] * 4 + 0x1aa4) + iVar1 + 0x34) =
                 (char)*(undefined2 *)
                        (*(int *)(this + (uint)(byte)this[0x2815] * 4 + 0x1aa4) + iVar1 + 0x36);
            iVar1 = iVar1 + 0x38;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
          *(char *)(*(int *)(this + (uint)(byte)this[0x2815] * 4 + 0x1aa4) + 0x22c) =
               (char)*(undefined2 *)(*(int *)(this + (uint)(byte)this[0x2815] * 4 + 0x1aa4) + 0x22e)
          ;
          this[0x27a1] = (dMenu_Fmap2_c)0x4;
        }
      }
      else {
        iVar2 = isOpenCollectMap(this,(char)this[0x27a9]);
        if (iVar2 == 0) {
          *(undefined2 *)(this + (uint)(byte)this[0x2816] * 2 + 0x2848) = 0x319e;
        }
        else {
          *(undefined2 *)(this + (uint)(byte)this[0x2816] * 2 + 0x2848) = 0x319c;
        }
        this[0x27fc] = (dMenu_Fmap2_c)0x1;
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x8c8,(cXyz *)0x0,0,0,d_menu_fmap2::_4119,
                   d_menu_fmap2::_4119,d_menu_fmap2::_4713,d_menu_fmap2::_4713,0);
        this[0x280f] = SUB41(iVar1,0);
        spMapLoadForDVD(this,(uchar)this[0x280f]);
        this[0x27a1] = (dMenu_Fmap2_c)0x5;
      }
    }
    if (iVar4 != (char)this[0x27a9]) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8c9,(cXyz *)0x0,0,0,d_menu_fmap2::_4119,
                 d_menu_fmap2::_4119,d_menu_fmap2::_4713,d_menu_fmap2::_4713,0);
      this[0x27fc] = (dMenu_Fmap2_c)0x1;
      this[0x27aa] = this[0x27a9];
      this[0x27a9] = SUB41(iVar4,0);
      cCursorHide(this);
      cSelCursorAnimeInit(this);
      if ((this[0x280d] == DAT_803e6241) || (this[0x280e] == DAT_803e6241)) {
        *(undefined4 *)(this + 0x2800) = DAT_803e6234;
        *(undefined4 *)(this + 0x2804) = DAT_803e6238;
        *(undefined4 *)(this + 0x2808) = DAT_803e623c;
        this[0x280c] = DAT_803e6240;
      }
      else {
        *(undefined4 *)(this + 0x2800) = DAT_803e6224;
        *(undefined4 *)(this + 0x2804) = DAT_803e6228;
        *(float *)(this + 0x2808) = DAT_803e622c;
        this[0x280c] = DAT_803e6230;
      }
      paneTransSelCmapCle(this,0,(uchar)DAT_803e6230,DAT_803e622c,d_menu_fmap2::_4119,
                          d_menu_fmap2::_4118,d_menu_fmap2::_4118,'\x04',(byte)this[0x2814] ^ 1,0);
      paneTransSelCmapOpn(this,0,(uchar)DAT_803e6230,DAT_803e622c,d_menu_fmap2::_4119,
                          d_menu_fmap2::_4118,d_menu_fmap2::_4118,'\x04',(byte)this[0x2813] ^ 1,0);
      paneAlphaZoomCmapBase
                (this,0,(uchar)DAT_803e6230,d_menu_fmap2::_4118,d_menu_fmap2::_4118,'\0',
                 (byte)this[0x2815] ^ 1,0);
      paneTranceMessage(this,0,(uchar)DAT_803e6230,d_menu_fmap2::_4119,d_menu_fmap2::_4119,
                        d_menu_fmap2::_4118,d_menu_fmap2::_4118,'\0',(byte)this[0x2816] ^ 1,0);
      cmapMove(this);
      this[0x27a1] = (dMenu_Fmap2_c)0x7;
    }
    cCursorAnime(this);
  }
  return;
}


/* __thiscall dMenu_Fmap2_c::spMapLoadForDVD(unsigned char) */

void __thiscall dMenu_Fmap2_c::spMapLoadForDVD(dMenu_Fmap2_c *this,uchar param_1)

{
  mDoDvdThd_command_c *pmVar1;
  
  *(undefined *)(**(int **)(this + (uint)(byte)this[0x2813] * 4 + 0x124c) + 0xaa) = 0;
  switch(param_1) {
  case '\x03':
    pmVar1 = mDoDvdThd_mountArchive_c::create("/res/Msg/tnmapres.arc",'\0',(JKRHeap *)0x0);
    *(mDoDvdThd_command_c **)(this + 0x18) = pmVar1;
    break;
  case '\x04':
    pmVar1 = mDoDvdThd_mountArchive_c::create("/res/Msg/gsmapres.arc",'\0',(JKRHeap *)0x0);
    *(mDoDvdThd_command_c **)(this + 0x18) = pmVar1;
    break;
  case '\a':
    pmVar1 = mDoDvdThd_mountArchive_c::create("/res/Msg/trmapres.arc",'\0',(JKRHeap *)0x0);
    *(mDoDvdThd_command_c **)(this + 0x18) = pmVar1;
    break;
  case '\t':
    pmVar1 = mDoDvdThd_mountArchive_c::create("/res/Msg/docmapres.arc",'\0',(JKRHeap *)0x0);
    *(mDoDvdThd_command_c **)(this + 0x18) = pmVar1;
    break;
  case '\n':
    pmVar1 = mDoDvdThd_mountArchive_c::create("/res/Msg/ysmapres.arc",'\0',(JKRHeap *)0x0);
    *(mDoDvdThd_command_c **)(this + 0x18) = pmVar1;
    break;
  case '\v':
    pmVar1 = mDoDvdThd_mountArchive_c::create("/res/Msg/heartmapres.arc",'\0',(JKRHeap *)0x0);
    *(mDoDvdThd_command_c **)(this + 0x18) = pmVar1;
    break;
  case '\f':
    pmVar1 = mDoDvdThd_mountArchive_c::create("/res/Msg/htmmapres.arc",'\0',(JKRHeap *)0x0);
    *(mDoDvdThd_command_c **)(this + 0x18) = pmVar1;
    break;
  case '\r':
    pmVar1 = mDoDvdThd_mountArchive_c::create("/res/Msg/irmapres.arc",'\0',(JKRHeap *)0x0);
    *(mDoDvdThd_command_c **)(this + 0x18) = pmVar1;
    break;
  case '\x0e':
    pmVar1 = mDoDvdThd_mountArchive_c::create("/res/Msg/moonmapres.arc",'\0',(JKRHeap *)0x0);
    *(mDoDvdThd_command_c **)(this + 0x18) = pmVar1;
    break;
  case '\x0f':
    pmVar1 = mDoDvdThd_mountArchive_c::create("/res/Msg/ygmapres.arc",'\0',(JKRHeap *)0x0);
    *(mDoDvdThd_command_c **)(this + 0x18) = pmVar1;
    break;
  case '\x10':
    pmVar1 = mDoDvdThd_mountArchive_c::create("/res/Msg/terrymapres.arc",'\0',(JKRHeap *)0x0);
    *(mDoDvdThd_command_c **)(this + 0x18) = pmVar1;
    break;
  case '\x11':
    pmVar1 = mDoDvdThd_mountArchive_c::create("/res/Msg/submamapres.arc",'\0',(JKRHeap *)0x0);
    *(mDoDvdThd_command_c **)(this + 0x18) = pmVar1;
  }
  return;
}


/* __thiscall dMenu_Fmap2_c::cmapOpenCheck(void) */

undefined4 __thiscall dMenu_Fmap2_c::cmapOpenCheck(dMenu_Fmap2_c *this)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = isOpenCollectMap(this,(char)this[0x27a9]);
  if (iVar1 == 0) {
    iVar1 = 0;
    iVar3 = 5;
    do {
      *(undefined *)
       (*(int *)(*(int *)(this + (uint)(byte)this[0x2813] * 4 + 0x124c) + iVar1) + 0xaa) = 1;
      iVar1 = iVar1 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *(undefined *)(*(int *)(*(int *)(this + (uint)(byte)this[0x2813] * 4 + 0x124c) + 0xe0) + 0xaa) =
         0;
    *(undefined *)(**(int **)(this + (uint)(byte)this[0x2815] * 4 + 0x1aa4) + 0xaa) = 1;
    *(undefined2 *)(this + (uint)(byte)this[0x2816] * 2 + 0x2848) = 0x319e;
    iVar1 = getCollectMapKind(this,(char)this[0x27a9]);
    if (iVar1 == 0) {
      iVar1 = isOpenCollectMapTriforce(this,(char)this[0x27a9]);
      if (iVar1 == 0) {
        *(undefined *)(**(int **)(this + (uint)(byte)this[0x2813] * 4 + 0x124c) + 0xaa) = 0;
        *(undefined *)(**(int **)(this + (uint)(byte)this[0x2815] * 4 + 0x1aa4) + 0xaa) = 0;
      }
      else {
        *(undefined *)
         (*(int *)(*(int *)(this + (uint)(byte)this[0x2813] * 4 + 0x124c) + 0xa8) + 0xaa) = 0;
      }
    }
    else {
      *(undefined *)(*(int *)(*(int *)(this + (uint)(byte)this[0x2813] * 4 + 0x124c) + 0xa8) + 0xaa)
           = 0;
    }
    paneTransSelCmapOpn(this,*(short *)(this + 0x27ac),DAT_803e620b,d_menu_fmap2::_4119,
                        d_menu_fmap2::_4119,d_menu_fmap2::_4118,d_menu_fmap2::_4118,'\0',
                        (uchar)this[0x2813],0);
    paneAlphaZoomCmapBase
              (this,*(short *)(this + 0x27ac),DAT_803e620b,d_menu_fmap2::_4118,d_menu_fmap2::_4118,
               '\0',(uchar)this[0x2815],0);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x801bf288) */
/* WARNING: Removing unreachable block (ram,0x801bf290) */
/* __thiscall dMenu_Fmap2_c::CmapScroll(void) */

void __thiscall dMenu_Fmap2_c::CmapScroll(dMenu_Fmap2_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if ((char)this[0x27ab] < '\0') {
    dVar10 = (double)*(float *)(this + 0x2800);
    dVar9 = (double)*(float *)(this + 0x2804);
  }
  else {
    dVar10 = -(double)*(float *)(this + 0x2800);
    dVar9 = -(double)*(float *)(this + 0x2804);
  }
  iVar1 = isOpenCollectMap(this,(char)this[0x27aa]);
  if (iVar1 == 0) {
    iVar1 = paneTransSelCmapCle(this,*(short *)(this + 0x27ac),(uchar)this[0x280c],
                                d_menu_fmap2::_4119,*(float *)(this + 0x2808),d_menu_fmap2::_4118,
                                (float)dVar10,'\x04',(uchar)this[0x2814],1);
  }
  else {
    iVar1 = getCollectMapKind(this,(char)this[0x27aa]);
    iVar1 = isSpMap(this,iVar1);
    if (iVar1 == 0) {
      iVar1 = paneTransSelCmapOpn(this,*(short *)(this + 0x27ac),(uchar)this[0x280c],
                                  d_menu_fmap2::_4119,*(float *)(this + 0x2808),d_menu_fmap2::_4118,
                                  (float)dVar10,'\x04',(uchar)this[0x2813],1);
    }
    else {
      iVar1 = paneTransSelCmapCle(this,*(short *)(this + 0x27ac),(uchar)this[0x280c],
                                  d_menu_fmap2::_4119,*(float *)(this + 0x2808),d_menu_fmap2::_4118,
                                  (float)dVar10,'\x04',(uchar)this[0x2814],1);
    }
  }
  iVar2 = isOpenCollectMap(this,(char)this[0x27a9]);
  if (iVar2 == 0) {
    iVar2 = paneTransSelCmapCle(this,*(short *)(this + 0x27ac),(uchar)this[0x280c],
                                *(float *)(this + 0x2808),d_menu_fmap2::_4119,(float)-dVar10,
                                d_menu_fmap2::_4118,'\x04',(byte)this[0x2814] ^ 1,0);
  }
  else {
    iVar2 = getCollectMapKind(this,(char)this[0x27a9]);
    iVar2 = isSpMap(this,iVar2);
    if (iVar2 == 0) {
      iVar2 = paneTransSelCmapOpn(this,*(short *)(this + 0x27ac),(uchar)this[0x280c],
                                  *(float *)(this + 0x2808),d_menu_fmap2::_4119,(float)-dVar10,
                                  d_menu_fmap2::_4118,'\x04',(byte)this[0x2813] ^ 1,0);
    }
    else {
      iVar2 = paneTransSelCmapCle(this,*(short *)(this + 0x27ac),(uchar)this[0x280c],
                                  *(float *)(this + 0x2808),d_menu_fmap2::_4119,(float)-dVar10,
                                  d_menu_fmap2::_4118,'\x04',(byte)this[0x2814] ^ 1,0);
    }
  }
  if (*(char *)(**(int **)(this + (uint)(byte)this[0x2815] * 4 + 0x1aa4) + 0xaa) == '\0') {
    iVar3 = 1;
  }
  else {
    iVar3 = paneAlphaZoomCmapBase
                      (this,*(short *)(this + 0x27ac),(uchar)this[0x280c],d_menu_fmap2::_4118,
                       (float)dVar9,'\0',(uchar)this[0x2815],1);
  }
  if (*(char *)(**(int **)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0xaa) == '\0') {
    iVar4 = 1;
  }
  else {
    iVar4 = paneAlphaZoomCmapBase
                      (this,*(short *)(this + 0x27ac),(uchar)this[0x280c],(float)-dVar9,
                       d_menu_fmap2::_4118,'\0',(uchar)((byte)this[0x2815] ^ 1),0);
  }
  if (*(char *)(**(int **)(this + (uint)(byte)this[0x2816] * 4 + 0xcc4) + 0xaa) == '\0') {
    iVar5 = 1;
  }
  else {
    iVar5 = paneTranceMessage(this,*(short *)(this + 0x27ac),(uchar)this[0x280c],d_menu_fmap2::_4119
                              ,d_menu_fmap2::_4119,d_menu_fmap2::_4118,(float)dVar9,'\0',
                              (uchar)this[0x2816],1);
  }
  if (*(char *)(**(int **)(this + ((byte)this[0x2816] ^ 1) * 4 + 0xcc4) + 0xaa) == '\0') {
    iVar6 = 1;
  }
  else {
    iVar6 = paneTranceMessage(this,*(short *)(this + 0x27ac),(uchar)this[0x280c],d_menu_fmap2::_4119
                              ,d_menu_fmap2::_4119,(float)-dVar9,d_menu_fmap2::_4118,'\0',
                              (uchar)((byte)this[0x2816] ^ 1),0);
  }
  iVar7 = paneAlphaCmapName(this,*(short *)(this + 0x27ac),(uchar)this[0x280c],'\0');
  *(short *)(this + 0x27ac) = *(short *)(this + 0x27ac) + 1;
  if ((((iVar1 == 1) && (iVar2 == 1)) && (iVar3 == 1)) &&
     (((iVar4 == 1 && (iVar5 == 1)) && ((iVar6 == 1 && (iVar7 == 1)))))) {
    *(undefined2 *)(this + 0x27ac) = 0;
    *(undefined *)(**(int **)(this + (uint)(byte)this[0x2815] * 4 + 0x1aa4) + 0xaa) = 0;
    *(undefined *)(**(int **)(this + (uint)(byte)this[0x2816] * 4 + 0xcc4) + 0xaa) = 0;
    iVar1 = 0;
    iVar2 = 2;
    do {
      *(undefined *)
       (*(int *)(*(int *)(this + (uint)(byte)this[0x2814] * 4 + 0x1244) + iVar1) + 0xaa) = 0;
      iVar1 = iVar1 + 0x38;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar1 = 0;
    iVar2 = 5;
    do {
      *(undefined *)
       (*(int *)(*(int *)(this + (uint)(byte)this[0x2813] * 4 + 0x124c) + iVar1) + 0xaa) = 0;
      iVar1 = iVar1 + 0x38;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    this[0x2815] = (dMenu_Fmap2_c)((byte)this[0x2815] ^ 1);
    this[0x2813] = (dMenu_Fmap2_c)((byte)this[0x2813] ^ 1);
    this[0x2814] = (dMenu_Fmap2_c)((byte)this[0x2814] ^ 1);
    this[0x2816] = (dMenu_Fmap2_c)((byte)this[0x2816] ^ 1);
    cCursorAnimeInit(this);
    cSelCursorInit(this);
    this[0x27fc] = (dMenu_Fmap2_c)0x0;
    this[0x27a1] = (dMenu_Fmap2_c)0x2;
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  return;
}


/* __thiscall dMenu_Fmap2_c::isSpMap(int) */

undefined4 __thiscall dMenu_Fmap2_c::isSpMap(dMenu_Fmap2_c *this,int param_1)

{
  if ((((1 < param_1 - 3U) && (param_1 != 7)) && (7 < param_1 - 9U)) && (param_1 != 0x11)) {
    return 0;
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMenu_Fmap2_c::CmapOpen(void) */

void __thiscall dMenu_Fmap2_c::CmapOpen(dMenu_Fmap2_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = paneTranceMessage(this,*(short *)(this + 0x27ac),DAT_803e620b,d_menu_fmap2::_4119,
                            DAT_803e6210,d_menu_fmap2::_4118,d_menu_fmap2::_4118,'\0',
                            (uchar)this[0x2816],1);
  iVar2 = getCollectMapKind(this,(char)this[0x27a9]);
  if ((iVar2 == 0) && (iVar2 = isOpenCollectMapTriforce(this,(char)this[0x27a9]), iVar2 == 0)) {
    if (*(ushort *)(this + 0x27ac) == (ushort)DAT_803e620b) {
      *(undefined2 *)(this + (uint)(byte)this[0x2816] * 2 + 0x2848) = 0x319d;
    }
    iVar2 = paneTranceMessage(this,*(short *)(this + 0x27ac) - (ushort)DAT_803e620b,DAT_803e620b,
                              DAT_803e6210,d_menu_fmap2::_4119,d_menu_fmap2::_4118,
                              d_menu_fmap2::_4118,'\0',(uchar)this[0x2816],0);
  }
  else {
    iVar2 = paneAlphaZoomCmapBase
                      (this,*(short *)(this + 0x27ac) - (ushort)DAT_803e620b,DAT_803e620b,
                       d_menu_fmap2::_4118,d_menu_fmap2::_4118,'\0',(uchar)this[0x2815],0);
  }
  iVar3 = paneTransSelCmapCle(this,*(short *)(this + 0x27ac) - (ushort)DAT_803e620b,DAT_803e620b,
                              d_menu_fmap2::_4119,d_menu_fmap2::_4119,d_menu_fmap2::_4118,
                              d_menu_fmap2::_4118,'\0',(uchar)this[0x2814],1);
  iVar4 = paneTransSelCmapOpn(this,*(short *)(this + 0x27ac) - (ushort)DAT_803e620b,DAT_803e620b,
                              d_menu_fmap2::_4119,d_menu_fmap2::_4119,d_menu_fmap2::_4118,
                              d_menu_fmap2::_4118,'\0',(uchar)this[0x2813],0);
  *(short *)(this + 0x27ac) = *(short *)(this + 0x27ac) + 1;
  if ((((iVar1 == 1) && (iVar2 == 1)) && (iVar3 == 1)) && (iVar4 == 1)) {
    *(undefined2 *)(this + 0x27ac) = 0;
    this[0x2812] = (dMenu_Fmap2_c)0x2;
    iVar1 = getCollectMapKind(this,(char)this[0x27a9]);
    if ((iVar1 != 0) || (iVar1 = isOpenCollectMapTriforce(this,(char)this[0x27a9]), iVar1 != 0)) {
      paneTranceMessage(this,0,DAT_803e620b,d_menu_fmap2::_4119,d_menu_fmap2::_4119,
                        d_menu_fmap2::_4118,d_menu_fmap2::_4118,'\0',(uchar)this[0x2816],0);
      *(undefined *)(**(int **)(this + (uint)(byte)this[0x2816] * 4 + 0xcc4) + 0xaa) = 0;
    }
    *(undefined2 *)(this + (uint)(byte)this[0x2816] * 2 + 0x2848) = 0xffff;
    iVar1 = 0;
    iVar2 = 2;
    do {
      *(undefined *)
       (*(int *)(*(int *)(this + (uint)(byte)this[0x2814] * 4 + 0x1244) + iVar1) + 0xaa) = 0;
      iVar1 = iVar1 + 0x38;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar1 = getCmapDatPnt4(this,(int)(char)this[0x27a9]);
    dSv_player_map_c::onOpenMap
              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,
               *(char *)(iVar1 + 1) + -1);
    this[0x27fc] = (dMenu_Fmap2_c)0x0;
    this[0x27a1] = (dMenu_Fmap2_c)0x2;
  }
  return;
}


/* __thiscall dMenu_Fmap2_c::CmapSpLoadWait(void) */

void __thiscall dMenu_Fmap2_c::CmapSpLoadWait(dMenu_Fmap2_c *this)

{
  if (*(char *)(*(int *)(this + 0x18) + 0xc) != '\0') {
    *(undefined4 *)(this + 0x279c) = 0;
    switch(this[0x280f]) {
    case (dMenu_Fmap2_c)0x3:
      screenSetTn(this);
      paneAlphaTingleMap(this,0,DAT_803e620b,'\0',0);
      break;
    case (dMenu_Fmap2_c)0x4:
      screenSetGs(this);
      paneAlphaGostShipMap(this,0,DAT_803e620b,'\0',0);
      break;
    case (dMenu_Fmap2_c)0x7:
      screenSetTr(this);
      paneAlphaTreasureMap(this,0,DAT_803e620b,'\0',0);
      break;
    case (dMenu_Fmap2_c)0x9:
      screenSetIk(this);
      paneAlphaDoctaMap(this,0,DAT_803e620b,'\0',0);
      break;
    case (dMenu_Fmap2_c)0xa:
      screenSetDfaliy(this);
      paneAlphaDfaliyMap(this,0,DAT_803e620b,'\0',0);
      break;
    case (dMenu_Fmap2_c)0xb:
      screenSetHeartP(this);
      paneAlphaHeartPMap(this,0,DAT_803e620b,'\0',0);
      break;
    case (dMenu_Fmap2_c)0xc:
      screenSetHeartM(this);
      paneAlphaHeartMMap(this,0,DAT_803e620b,'\0',0);
      break;
    case (dMenu_Fmap2_c)0xd:
      screenSetSubdan(this);
      paneAlphaSubdanMap(this,0,DAT_803e620b,'\0',0);
      break;
    case (dMenu_Fmap2_c)0xe:
      screenSetMoon(this);
      paneAlphaMoonMap(this,0,DAT_803e620b,'\0',0);
      break;
    case (dMenu_Fmap2_c)0xf:
      screenSetYagura(this);
      paneAlphaYaguraMap(this,0,DAT_803e620b,'\0',0);
      break;
    case (dMenu_Fmap2_c)0x10:
      screenSetTerry(this);
      paneAlphaTerryMap(this,0,DAT_803e620b,'\0',0);
      break;
    case (dMenu_Fmap2_c)0x11:
      screenSetSubMa(this);
      paneAlphaSubMaMap(this,0,DAT_803e620b,'\0',0);
    }
    this[0x27fb] = (dMenu_Fmap2_c)0x1;
    this[0x27a1] = (dMenu_Fmap2_c)0x6;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dMenu_Fmap2_c::screenSetGs(void) */

void __thiscall dMenu_Fmap2_c::screenSetGs(dMenu_Fmap2_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  undefined4 uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  dMenu_Fmap2_c local_48;
  dMenu_Fmap2_c dStack71;
  dMenu_Fmap2_c dStack70;
  dMenu_Fmap2_c dStack69;
  dMenu_Fmap2_c local_44;
  dMenu_Fmap2_c dStack67;
  dMenu_Fmap2_c dStack66;
  dMenu_Fmap2_c dStack65;
  dMenu_Fmap2_c local_40;
  dMenu_Fmap2_c dStack63;
  dMenu_Fmap2_c dStack62;
  dMenu_Fmap2_c dStack61;
  dMenu_Fmap2_c local_3c;
  dMenu_Fmap2_c dStack59;
  dMenu_Fmap2_c dStack58;
  dMenu_Fmap2_c dStack57;
  TBox2_float_ local_38;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_38.mTL.x = d_menu_fmap2::_4118;
    local_38.mTL.y = d_menu_fmap2::_4118;
    local_38.mBR.x = d_menu_fmap2::_4183;
    local_38.mBR.y = d_menu_fmap2::_4184;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_38);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 0x2c) = this_00;
  if (*(int *)(this + 0x2c) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.cpp",0x701,"fmap2GsDl.scrn != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x701,&DAT_8035ff21);
  }
  J2DScreen::set(*(J2DScreen **)(this + 0x2c),"g_map_01.blo",
                 *(JKRArchive **)(*(int *)(this + 0x18) + 0x1c));
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1aac),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1ab4),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x73643035);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1abc),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x68733034);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1ac4),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x79673031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1acc),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x4253646d);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1ad4),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x746b6432);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1b14),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x746b6431);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1b1c),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x533032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1b24),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6b7a3035);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1b2c),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6b7a3031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1b34),uVar2);
  uVar2 = *(undefined4 *)(*(int *)(this + 0x1b34) + 0x108);
  local_3c = SUB41((uint)uVar2 >> 0x18,0);
  this[0x2828] = local_3c;
  dStack59 = SUB41((uint)uVar2 >> 0x10,0);
  this[0x2829] = dStack59;
  dStack58 = SUB41((uint)uVar2 >> 8,0);
  this[0x282a] = dStack58;
  dStack57 = SUB41(uVar2,0);
  this[0x282b] = dStack57;
  uVar2 = *(undefined4 *)(*(int *)(this + 0x1b34) + 0x104);
  local_40 = SUB41((uint)uVar2 >> 0x18,0);
  this[0x282c] = local_40;
  dStack63 = SUB41((uint)uVar2 >> 0x10,0);
  this[0x282d] = dStack63;
  dStack62 = SUB41((uint)uVar2 >> 8,0);
  this[0x282e] = dStack62;
  dStack61 = SUB41(uVar2,0);
  this[0x282f] = dStack61;
  iVar4 = 0;
  iVar6 = 0;
  iVar5 = 0;
  do {
    uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))
                      (*(int **)(this + 0x2c),*(undefined4 *)((int)&d_menu_fmap2::moon_5099 + iVar5)
                      );
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar6 + 0x1adc),uVar2);
    uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))
                      (*(int **)(this + 0x2c),
                       *(undefined4 *)((int)&d_menu_fmap2::shipicon_5100 + iVar5));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar6 + 0x1b3c),uVar2);
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 8;
    iVar5 = iVar5 + 4;
  } while (iVar4 < 7);
  uVar2 = *(undefined4 *)(*(int *)(this + 0x1adc) + 0x108);
  local_44 = SUB41((uint)uVar2 >> 0x18,0);
  this[0x2820] = local_44;
  dStack67 = SUB41((uint)uVar2 >> 0x10,0);
  this[0x2821] = dStack67;
  dStack66 = SUB41((uint)uVar2 >> 8,0);
  this[0x2822] = dStack66;
  dStack65 = SUB41(uVar2,0);
  this[0x2823] = dStack65;
  uVar2 = *(undefined4 *)(*(int *)(this + 0x1adc) + 0x104);
  local_48 = SUB41((uint)uVar2 >> 0x18,0);
  this[0x2824] = local_48;
  dStack71 = SUB41((uint)uVar2 >> 0x10,0);
  this[0x2825] = dStack71;
  dStack70 = SUB41((uint)uVar2 >> 8,0);
  this[0x2826] = dStack70;
  dStack69 = SUB41(uVar2,0);
  this[0x2827] = dStack69;
  uVar3 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x8803);
  if ((uVar3 & 0xff) == 3) {
    this[0x2811] = (dMenu_Fmap2_c)0x1;
    iVar4 = 0;
    iVar5 = 7;
    do {
      *(undefined *)(*(int *)(this + iVar4 + 0x1adc) + 0xaa) = 0;
      iVar4 = iVar4 + 8;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    *(undefined *)(*(int *)(this + 0x1b34) + 0xaa) = 0;
    this[0x1b21] = (dMenu_Fmap2_c)0xc8;
    this[0x1b20] = (dMenu_Fmap2_c)0xc8;
    f_op_msg_mng::fopMsgM_setAlpha(this + 0x1b1c);
  }
  else {
    this[0x2811] = (dMenu_Fmap2_c)0x0;
    this[0x2817] = (dMenu_Fmap2_c)0x0;
    if ((d_menu_fmap2::_5194 <=
         d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime) ||
       ((d_menu_fmap2::_4118 <=
         d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime &&
        (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime <=
         d_menu_fmap2::_5195)))) {
      this[0x2817] = (dMenu_Fmap2_c)0x1;
      iVar4 = d_kankyo::dKy_moon_type_chk();
      *(undefined *)(*(int *)(this + iVar4 * 8 + 0x1b3c) + 0xaa) = 1;
    }
    gsMoonAnimeInit(this);
    gsIconAnimeInit(this);
  }
  return;
}


/* __thiscall dMenu_Fmap2_c::gsMoonAnimeInit(void) */

void __thiscall dMenu_Fmap2_c::gsMoonAnimeInit(dMenu_Fmap2_c *this)

{
  this[0x2818] = DAT_803e6246;
  this[0x2819] = DAT_803e6247;
  this[0x281a] = (dMenu_Fmap2_c)0x1;
  this[0x281b] = DAT_803e6250;
  this[0x281c] = DAT_803e6251;
  return;
}


/* __thiscall dMenu_Fmap2_c::gsMoonAnime(void) */

void __thiscall dMenu_Fmap2_c::gsMoonAnime(dMenu_Fmap2_c *this)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  dMenu_Fmap2_c dVar13;
  dMenu_Fmap2_c dVar14;
  int iVar15;
  double dVar16;
  
  if ((this[0x2811] == (dMenu_Fmap2_c)0x0) && (this[0x2817] != (dMenu_Fmap2_c)0x0)) {
    dVar16 = (double)f_op_msg_mng::fopMsgM_valueIncrease(DAT_803e6246,this[0x2818],2);
    if (this[0x281a] == (dMenu_Fmap2_c)0x0) {
      dVar16 = (double)(float)((double)d_menu_fmap2::_4119 - dVar16);
    }
    dVar1 = (double)CONCAT44(0x43300000,(uint)DAT_803e6248) - d_menu_fmap2::_5260;
    dVar2 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x2824] - (uint)DAT_803e6248 ^ 0x80000000)
            - d_menu_fmap2::_4406;
    dVar3 = (double)CONCAT44(0x43300000,(uint)DAT_803e6249) - d_menu_fmap2::_5260;
    dVar4 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x2825] - (uint)DAT_803e6249 ^ 0x80000000)
            - d_menu_fmap2::_4406;
    dVar5 = (double)CONCAT44(0x43300000,(uint)DAT_803e624a) - d_menu_fmap2::_5260;
    dVar6 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x2826] - (uint)DAT_803e624a ^ 0x80000000)
            - d_menu_fmap2::_4406;
    dVar13 = this[0x2827];
    dVar7 = (double)CONCAT44(0x43300000,(uint)DAT_803e624c) - d_menu_fmap2::_5260;
    dVar8 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x2820] - (uint)DAT_803e624c ^ 0x80000000)
            - d_menu_fmap2::_4406;
    dVar9 = (double)CONCAT44(0x43300000,(uint)DAT_803e624d) - d_menu_fmap2::_5260;
    dVar10 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x2821] - (uint)DAT_803e624d ^ 0x80000000)
             - d_menu_fmap2::_4406;
    dVar11 = (double)CONCAT44(0x43300000,(uint)DAT_803e624e) - d_menu_fmap2::_5260;
    dVar12 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x2822] - (uint)DAT_803e624e ^ 0x80000000)
             - d_menu_fmap2::_4406;
    dVar14 = this[0x2823];
    if (this[0x2818] == (dMenu_Fmap2_c)0x0) {
      if (this[0x2819] == (dMenu_Fmap2_c)0x0) {
        if (this[0x281a] != (dMenu_Fmap2_c)0x0) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x904,(cXyz *)0x0,0,0,d_menu_fmap2::_4119,
                     d_menu_fmap2::_4119,d_menu_fmap2::_4713,d_menu_fmap2::_4713,0);
        }
        this[0x2818] = DAT_803e6246;
        this[0x2819] = DAT_803e6247;
        this[0x281a] = (dMenu_Fmap2_c)((byte)this[0x281a] ^ 1);
      }
      else {
        this[0x2819] = (dMenu_Fmap2_c)((char)this[0x2819] + -1);
      }
    }
    else {
      this[0x2818] = (dMenu_Fmap2_c)((char)this[0x2818] + -1);
    }
    iVar15 = d_kankyo::dKy_moon_type_chk();
    iVar15 = *(int *)(this + iVar15 * 8 + 0x1adc);
    *(char *)(iVar15 + 0x108) = (char)(int)((float)dVar7 + (float)(dVar16 * (double)(float)dVar8));
    *(char *)(iVar15 + 0x109) = (char)(int)((float)dVar9 + (float)(dVar16 * (double)(float)dVar10));
    *(char *)(iVar15 + 0x10a) = (char)(int)((float)dVar11 + (float)(dVar16 * (double)(float)dVar12))
    ;
    *(dMenu_Fmap2_c *)(iVar15 + 0x10b) = dVar14;
    *(char *)(iVar15 + 0x104) = (char)(int)((float)dVar1 + (float)(dVar16 * (double)(float)dVar2));
    *(char *)(iVar15 + 0x105) = (char)(int)((float)dVar3 + (float)(dVar16 * (double)(float)dVar4));
    *(char *)(iVar15 + 0x106) = (char)(int)((float)dVar5 + (float)(dVar16 * (double)(float)dVar6));
    *(dMenu_Fmap2_c *)(iVar15 + 0x107) = dVar13;
  }
  return;
}


/* __thiscall dMenu_Fmap2_c::gsShipAnime(void) */

void __thiscall dMenu_Fmap2_c::gsShipAnime(dMenu_Fmap2_c *this)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  int iVar15;
  double dVar16;
  
  if ((this[0x2811] == (dMenu_Fmap2_c)0x0) && (this[0x2817] != (dMenu_Fmap2_c)0x0)) {
    if (this[0x281b] == (dMenu_Fmap2_c)0x0) {
      if (this[0x281c] != (dMenu_Fmap2_c)0xff) {
        dVar16 = (double)f_op_msg_mng::fopMsgM_valueIncrease(DAT_803e6251,this[0x281c],2);
        dVar1 = (double)CONCAT44(0x43300000,(uint)DAT_803e6252) - d_menu_fmap2::_5260;
        dVar2 = (double)CONCAT44(0x43300000,
                                 (uint)(byte)this[0x282c] - (uint)DAT_803e6252 ^ 0x80000000) -
                d_menu_fmap2::_4406;
        dVar3 = (double)CONCAT44(0x43300000,(uint)DAT_803e6253) - d_menu_fmap2::_5260;
        dVar4 = (double)CONCAT44(0x43300000,
                                 (uint)(byte)this[0x282d] - (uint)DAT_803e6253 ^ 0x80000000) -
                d_menu_fmap2::_4406;
        dVar5 = (double)CONCAT44(0x43300000,(uint)DAT_803e6254) - d_menu_fmap2::_5260;
        dVar6 = (double)CONCAT44(0x43300000,
                                 (uint)(byte)this[0x282e] - (uint)DAT_803e6254 ^ 0x80000000) -
                d_menu_fmap2::_4406;
        dVar7 = (double)CONCAT44(0x43300000,(uint)DAT_803e6255) - d_menu_fmap2::_5260;
        dVar8 = (double)CONCAT44(0x43300000,
                                 (uint)(byte)this[0x282f] - (uint)DAT_803e6255 ^ 0x80000000) -
                d_menu_fmap2::_4406;
        dVar9 = (double)CONCAT44(0x43300000,(uint)DAT_803e6257) - d_menu_fmap2::_5260;
        dVar10 = (double)CONCAT44(0x43300000,
                                  (uint)(byte)this[0x2829] - (uint)DAT_803e6257 ^ 0x80000000) -
                 d_menu_fmap2::_4406;
        dVar11 = (double)CONCAT44(0x43300000,(uint)DAT_803e6258) - d_menu_fmap2::_5260;
        dVar12 = (double)CONCAT44(0x43300000,
                                  (uint)(byte)this[0x282a] - (uint)DAT_803e6258 ^ 0x80000000) -
                 d_menu_fmap2::_4406;
        dVar13 = (double)CONCAT44(0x43300000,(uint)DAT_803e6259) - d_menu_fmap2::_5260;
        dVar14 = (double)CONCAT44(0x43300000,
                                  (uint)(byte)this[0x282b] - (uint)DAT_803e6259 ^ 0x80000000) -
                 d_menu_fmap2::_4406;
        iVar15 = *(int *)(this + 0x1b34);
        *(char *)(iVar15 + 0x108) =
             (char)(int)((float)((double)CONCAT44(0x43300000,(uint)DAT_803e6256) -
                                d_menu_fmap2::_5260) +
                        (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,
                                                                          (uint)(byte)this[0x2828] -
                                                                          (uint)DAT_803e6256 ^
                                                                          0x80000000) -
                                                        d_menu_fmap2::_4406)));
        *(char *)(iVar15 + 0x109) =
             (char)(int)((float)dVar9 + (float)(dVar16 * (double)(float)dVar10));
        *(char *)(iVar15 + 0x10a) =
             (char)(int)((float)dVar11 + (float)(dVar16 * (double)(float)dVar12));
        *(char *)(iVar15 + 0x10b) =
             (char)(int)((float)dVar13 + (float)(dVar16 * (double)(float)dVar14));
        *(char *)(iVar15 + 0x104) =
             (char)(int)((float)dVar1 + (float)(dVar16 * (double)(float)dVar2));
        *(char *)(iVar15 + 0x105) =
             (char)(int)((float)dVar3 + (float)(dVar16 * (double)(float)dVar4));
        *(char *)(iVar15 + 0x106) =
             (char)(int)((float)dVar5 + (float)(dVar16 * (double)(float)dVar6));
        *(char *)(iVar15 + 0x107) =
             (char)(int)((float)dVar7 + (float)(dVar16 * (double)(float)dVar8));
        if (this[0x281c] == (dMenu_Fmap2_c)0x0) {
          this[0x281c] = (dMenu_Fmap2_c)0xff;
        }
        else {
          this[0x281c] = (dMenu_Fmap2_c)((char)this[0x281c] + -1);
        }
      }
    }
    else {
      this[0x281b] = (dMenu_Fmap2_c)((char)this[0x281b] + -1);
    }
  }
  return;
}


/* __thiscall dMenu_Fmap2_c::gsIconAnimeInit(void) */

void __thiscall dMenu_Fmap2_c::gsIconAnimeInit(dMenu_Fmap2_c *this)

{
  this[0x284c] = DAT_803e625a;
  this[0x284d] = DAT_803e625b;
  this[0x284e] = (dMenu_Fmap2_c)0x1;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_Fmap2_c::gsIconAnime(void) */

void __thiscall dMenu_Fmap2_c::gsIconAnime(dMenu_Fmap2_c *this)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  double dVar4;
  
  if ((this[0x2811] == (dMenu_Fmap2_c)0x0) && (this[0x2817] != (dMenu_Fmap2_c)0x0)) {
    iVar2 = d_kankyo::dKy_moon_type_chk();
    dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(DAT_803e625a,this[0x284c],2);
    bVar1 = DAT_803e625d;
    if (this[0x284e] == (dMenu_Fmap2_c)0x0) {
      dVar4 = (double)(float)((double)d_menu_fmap2::_4119 - dVar4);
    }
    cVar3 = Runtime.PPCEABI.H::__cvt_fp2unsigned
                      ((double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                                        (uint)DAT_803e625c -
                                                                        (uint)DAT_803e625d ^
                                                                        0x80000000) -
                                                      d_menu_fmap2::_4406) * dVar4));
    this[iVar2 * 8 + 0x1b41] = (dMenu_Fmap2_c)(bVar1 + cVar3);
    f_op_msg_mng::fopMsgM_setAlpha(this + iVar2 * 8 + 0x1b3c);
    if (this[0x284c] == (dMenu_Fmap2_c)0x0) {
      if (this[0x284d] == (dMenu_Fmap2_c)0x0) {
        this[0x284c] = DAT_803e625a;
        this[0x284d] = DAT_803e625b;
        this[0x284e] = (dMenu_Fmap2_c)((byte)this[0x284e] ^ 1);
      }
      else {
        this[0x284d] = (dMenu_Fmap2_c)((char)this[0x284d] + -1);
      }
    }
    else {
      this[0x284c] = (dMenu_Fmap2_c)((char)this[0x284c] + -1);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMenu_Fmap2_c::screenSetTn(void) */

void __thiscall dMenu_Fmap2_c::screenSetTn(dMenu_Fmap2_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  undefined4 uVar2;
  J2DScreen *pJVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  TBox2_float_ local_28;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_28.mTL.x = d_menu_fmap2::_4118;
    local_28.mTL.y = d_menu_fmap2::_4118;
    local_28.mBR.x = d_menu_fmap2::_4183;
    local_28.mBR.y = d_menu_fmap2::_4184;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_28);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 0x2c) = this_00;
  if (*(int *)(this + 0x2c) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.cpp",0x807,"fmap2GsDl.scrn != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x807,&DAT_8035ff21);
  }
  J2DScreen::set(*(J2DScreen **)(this + 0x2c),"t_map_01.blo",
                 *(JKRArchive **)(*(int *)(this + 0x18) + 0x1c));
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x484b3030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1b74),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x484b3031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1b7c),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x484e3139);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1b84),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x484b3239);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1b8c),uVar2);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6764646d);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1b94),pJVar3);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6c6e6b);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1c7c),pJVar3);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x67646774);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1cb4),pJVar3);
  iVar4 = 0;
  iVar6 = 0;
  iVar5 = 0;
  do {
    uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))
                      (*(int **)(this + 0x2c),
                       *(undefined4 *)((int)&d_menu_fmap2::b1Tag_5396 + iVar5));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar6 + 0x1bcc),uVar2);
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 8;
    iVar5 = iVar5 + 4;
  } while (iVar4 < 0x16);
  setPlayerPos(this,(fopMsgM_pane_class *)(this + 0x1c7c),(fopMsgM_pane_class *)(this + 0x1cb4),
               (fopMsgM_pane_class *)(this + 0x1b94));
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dMenu_Fmap2_c::screenSetTr(void) */

void __thiscall dMenu_Fmap2_c::screenSetTr(dMenu_Fmap2_c *this)

{
  char cVar1;
  J2DPane *this_00;
  ulong uVar2;
  undefined4 uVar3;
  J2DScreen *pJVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  dMenu_Fmap2_c *pdVar9;
  int iVar10;
  TBox2_float_ local_38;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_38.mTL.x = d_menu_fmap2::_4118;
    local_38.mTL.y = d_menu_fmap2::_4118;
    local_38.mBR.x = d_menu_fmap2::_4183;
    local_38.mBR.y = d_menu_fmap2::_4184;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_38);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 0x2c) = this_00;
  if (*(int *)(this + 0x2c) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_fmap2.cpp",0x832,"fmap2GsDl.scrn != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x832,&DAT_8035ff21);
  }
  J2DScreen::set(*(J2DScreen **)(this + 0x2c),"TR_map_1.blo",
                 *(JKRArchive **)(*(int *)(this + 0x18) + 0x1c));
  uVar3 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1cec),uVar3);
  uVar3 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1cf4),uVar3);
  uVar3 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x68733034);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1cfc),uVar3);
  uVar3 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x73643035);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1d04),uVar3);
  uVar3 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6b7a3035);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1d0c),uVar3);
  pJVar4 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6764646d);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1d14),pJVar4);
  uVar3 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d6b646d);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1d4c),uVar3);
  pJVar4 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6c6e6b);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1d54),pJVar4);
  pJVar4 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x67646774);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1d8c),pJVar4);
  iVar7 = 0x746631;
  iVar6 = 0x746731;
  iVar5 = 0x6d6731;
  iVar8 = 0;
  iVar10 = 0;
  do {
    uVar3 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),iVar5);
    pdVar9 = this + iVar10;
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar9 + 0x1dc4),uVar3);
    uVar3 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),iVar7);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar9 + 0x1e04),uVar3);
    uVar3 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),iVar6);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar9 + 0x1e44),uVar3);
    iVar8 = iVar8 + 1;
    iVar5 = iVar5 + 1;
    iVar7 = iVar7 + 1;
    iVar6 = iVar6 + 1;
    iVar10 = iVar10 + 8;
  } while (iVar8 < 8);
  iVar5 = 0;
  iVar6 = 0;
  do {
    cVar1 = (char)iVar5;
    iVar7 = isGetCollectMap(this,cVar1 + '\x01');
    if (iVar7 != 0) {
      pdVar9 = this + iVar6;
      *(undefined *)(*(int *)(pdVar9 + 0x1dc4) + 0xaa) = 1;
      iVar7 = isOpenCollectMapTriforce(this,cVar1);
      if (iVar7 != 0) {
        *(undefined *)(*(int *)(pdVar9 + 0x1e04) + 0xaa) = 1;
        iVar7 = isCompleteCollectMap(this,cVar1);
        if (iVar7 != 0) {
          *(undefined *)(*(int *)(pdVar9 + 0x1e44) + 0xaa) = 1;
        }
      }
    }
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 8;
  } while (iVar5 < 8);
  trTrifAnimeInit(this);
  setPlayerPos(this,(fopMsgM_pane_class *)(this + 0x1d54),(fopMsgM_pane_class *)(this + 0x1d8c),
               (fopMsgM_pane_class *)(this + 0x1d14));
  return;
}


/* __thiscall dMenu_Fmap2_c::trTrifAnimeInit(void) */

void __thiscall dMenu_Fmap2_c::trTrifAnimeInit(dMenu_Fmap2_c *this)

{
  this[0x284f] = DAT_803e625e;
  this[0x2850] = (dMenu_Fmap2_c)0x1;
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dMenu_Fmap2_c::trTrifAnime(void) */

void __thiscall dMenu_Fmap2_c::trTrifAnime(dMenu_Fmap2_c *this)

{
  char cVar1;
  dMenu_Fmap2_c *pdVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  
  dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(DAT_803e625e,this[0x284f],2);
  if (this[0x2850] == (dMenu_Fmap2_c)0x0) {
    dVar5 = (double)(float)((double)d_menu_fmap2::_4119 - dVar5);
  }
  iVar3 = 0;
  iVar4 = 0;
  cVar1 = Runtime.PPCEABI.H::__cvt_fp2unsigned
                    ((double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                                      (uint)DAT_803e625f -
                                                                      (uint)DAT_803e6260 ^
                                                                      0x80000000) -
                                                    d_menu_fmap2::_4406) * dVar5));
  do {
    pdVar2 = this + iVar4;
    if ((*(char *)(*(int *)(pdVar2 + 0x1e04) + 0xaa) != '\0') &&
       (*(char *)(*(int *)(pdVar2 + 0x1e44) + 0xaa) == '\0')) {
      pdVar2[0x1e09] = (dMenu_Fmap2_c)(DAT_803e6260 + cVar1);
      f_op_msg_mng::fopMsgM_setAlpha(pdVar2 + 0x1e04);
    }
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 8;
  } while (iVar3 < 8);
  if (this[0x284f] == (dMenu_Fmap2_c)0x0) {
    this[0x284f] = DAT_803e625e;
    this[0x2850] = (dMenu_Fmap2_c)((byte)this[0x2850] ^ 1);
  }
  else {
    this[0x284f] = (dMenu_Fmap2_c)((char)this[0x284f] + -1);
  }
  return;
}


/* __thiscall dMenu_Fmap2_c::screenSetIk(void) */

void __thiscall dMenu_Fmap2_c::screenSetIk(dMenu_Fmap2_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  undefined4 uVar2;
  J2DScreen *pJVar3;
  TBox2_float_ local_18;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_18.mTL.x = d_menu_fmap2::_4118;
    local_18.mTL.y = d_menu_fmap2::_4118;
    local_18.mBR.x = d_menu_fmap2::_4183;
    local_18.mBR.y = d_menu_fmap2::_4184;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_18);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 0x2c) = this_00;
  if (*(int *)(this + 0x2c) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.cpp",0x8a3,"fmap2GsDl.scrn != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x8a3,&DAT_8035ff21);
  }
  J2DScreen::set(*(J2DScreen **)(this + 0x2c),"DOC_map_01.blo",
                 *(JKRArchive **)(*(int *)(this + 0x18) + 0x1c));
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1e84),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1e8c),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x68733034);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1e9c),uVar2);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6764646d);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1ea4),pJVar3);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d6b646d);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1edc),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x73643035);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1e94),uVar2);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6c6e6b);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1ee4),pJVar3);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x67646774);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1f1c),pJVar3);
  setPlayerPos(this,(fopMsgM_pane_class *)(this + 0x1ee4),(fopMsgM_pane_class *)(this + 0x1f1c),
               (fopMsgM_pane_class *)(this + 0x1ea4));
  return;
}


/* __thiscall dMenu_Fmap2_c::screenSetHeartP(void) */

void __thiscall dMenu_Fmap2_c::screenSetHeartP(dMenu_Fmap2_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  undefined4 uVar2;
  J2DScreen *pJVar3;
  TBox2_float_ local_18;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_18.mTL.x = d_menu_fmap2::_4118;
    local_18.mTL.y = d_menu_fmap2::_4118;
    local_18.mBR.x = d_menu_fmap2::_4183;
    local_18.mBR.y = d_menu_fmap2::_4184;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_18);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 0x2c) = this_00;
  if (*(int *)(this + 0x2c) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.cpp",0x8bc,"fmap2GsDl.scrn != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x8bc,&DAT_8035ff21);
  }
  J2DScreen::set(*(J2DScreen **)(this + 0x2c),"HRT_map_1.blo",
                 *(JKRArchive **)(*(int *)(this + 0x18) + 0x1c));
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1f54),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1f5c),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x68733034);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1f6c),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x73643035);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1f64),uVar2);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6764646d);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1f74),pJVar3);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d6b3230);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1fac),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6e6d3038);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1fb4),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6b6b3132);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1fbc),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x626831);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1fc4),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x626832);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1fcc),uVar2);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6c6e6b);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1fd4),pJVar3);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x67646774);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x200c),pJVar3);
  setPlayerPos(this,(fopMsgM_pane_class *)(this + 0x1fd4),(fopMsgM_pane_class *)(this + 0x200c),
               (fopMsgM_pane_class *)(this + 0x1f74));
  return;
}


/* __thiscall dMenu_Fmap2_c::screenSetTerry(void) */

void __thiscall dMenu_Fmap2_c::screenSetTerry(dMenu_Fmap2_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  undefined4 uVar2;
  J2DScreen *pJVar3;
  TBox2_float_ local_18;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_18.mTL.x = d_menu_fmap2::_4118;
    local_18.mTL.y = d_menu_fmap2::_4118;
    local_18.mBR.x = d_menu_fmap2::_4183;
    local_18.mBR.y = d_menu_fmap2::_4184;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_18);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 0x2c) = this_00;
  if (*(int *)(this + 0x2c) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.cpp",0x8d9,"fmap2GsDl.scrn != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x8d9,&DAT_8035ff21);
  }
  J2DScreen::set(*(J2DScreen **)(this + 0x2c),"TERRY_map_1.blo",
                 *(JKRArchive **)(*(int *)(this + 0x18) + 0x1c));
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2044),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x204c),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x68733034);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x205c),uVar2);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6764646d);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2064),pJVar3);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x73643035);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2054),uVar2);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6c6e6b);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x209c),pJVar3);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x67646774);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x20d4),pJVar3);
  setPlayerPos(this,(fopMsgM_pane_class *)(this + 0x209c),(fopMsgM_pane_class *)(this + 0x20d4),
               (fopMsgM_pane_class *)(this + 0x2064));
  return;
}


/* __thiscall dMenu_Fmap2_c::screenSetSubMa(void) */

void __thiscall dMenu_Fmap2_c::screenSetSubMa(dMenu_Fmap2_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  undefined4 uVar2;
  J2DScreen *pJVar3;
  TBox2_float_ local_18;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_18.mTL.x = d_menu_fmap2::_4118;
    local_18.mTL.y = d_menu_fmap2::_4118;
    local_18.mBR.x = d_menu_fmap2::_4183;
    local_18.mBR.y = d_menu_fmap2::_4184;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_18);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 0x2c) = this_00;
  if (*(int *)(this + 0x2c) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.cpp",0x8f1,"fmap2GsDl.scrn != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x8f1,&DAT_8035ff21);
  }
  J2DScreen::set(*(J2DScreen **)(this + 0x2c),"SENSUI_map_1.blo",
                 *(JKRArchive **)(*(int *)(this + 0x18) + 0x1c));
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x210c),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2114),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x68733034);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2124),uVar2);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6764646d);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x212c),pJVar3);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x73643035);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x211c),uVar2);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6c6e6b);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2164),pJVar3);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x67646774);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x219c),pJVar3);
  setPlayerPos(this,(fopMsgM_pane_class *)(this + 0x2164),(fopMsgM_pane_class *)(this + 0x219c),
               (fopMsgM_pane_class *)(this + 0x212c));
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMenu_Fmap2_c::screenSetMoon(void) */

void __thiscall dMenu_Fmap2_c::screenSetMoon(dMenu_Fmap2_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  undefined4 uVar2;
  J2DScreen *pJVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  TBox2_float_ local_28;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_28.mTL.x = d_menu_fmap2::_4118;
    local_28.mTL.y = d_menu_fmap2::_4118;
    local_28.mBR.x = d_menu_fmap2::_4183;
    local_28.mBR.y = d_menu_fmap2::_4184;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_28);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 0x2c) = this_00;
  if (*(int *)(this + 0x2c) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.cpp",0x90b,"fmap2GsDl.scrn != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x90b,&DAT_8035ff21);
  }
  J2DScreen::set(*(J2DScreen **)(this + 0x2c),"MN_map_1.blo",
                 *(JKRArchive **)(*(int *)(this + 0x18) + 0x1c));
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x21d4),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x21dc),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x68733034);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x21ec),uVar2);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6764646d);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x21f4),pJVar3);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x73643035);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x21e4),uVar2);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6c6e6b);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x235c),pJVar3);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x67646774);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2394),pJVar3);
  iVar4 = 0;
  iVar6 = 0;
  iVar5 = 0;
  do {
    uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))
                      (*(int **)(this + 0x2c),*(undefined4 *)((int)&d_menu_fmap2::tag_5576 + iVar5))
    ;
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar6 + 0x222c),uVar2);
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 8;
    iVar5 = iVar5 + 4;
  } while (iVar4 < 0x26);
  setPlayerPos(this,(fopMsgM_pane_class *)(this + 0x235c),(fopMsgM_pane_class *)(this + 0x2394),
               (fopMsgM_pane_class *)(this + 0x21f4));
  return;
}


/* __thiscall dMenu_Fmap2_c::screenSetDfaliy(void) */

void __thiscall dMenu_Fmap2_c::screenSetDfaliy(dMenu_Fmap2_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  undefined4 uVar2;
  J2DScreen *pJVar3;
  TBox2_float_ local_18;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_18.mTL.x = d_menu_fmap2::_4118;
    local_18.mTL.y = d_menu_fmap2::_4118;
    local_18.mBR.x = d_menu_fmap2::_4183;
    local_18.mBR.y = d_menu_fmap2::_4184;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_18);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 0x2c) = this_00;
  if (*(int *)(this + 0x2c) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.cpp",0x92b,"fmap2GsDl.scrn != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x92b,&DAT_8035ff21);
  }
  J2DScreen::set(*(J2DScreen **)(this + 0x2c),"YS_map_1.blo",
                 *(JKRArchive **)(*(int *)(this + 0x18) + 0x1c));
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x23cc),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x23d4),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x68733034);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x23e4),uVar2);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6764646d);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x23ec),pJVar3);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x73643035);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x23dc),uVar2);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6c6e6b);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2424),pJVar3);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x67646774);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x245c),pJVar3);
  setPlayerPos(this,(fopMsgM_pane_class *)(this + 0x2424),(fopMsgM_pane_class *)(this + 0x245c),
               (fopMsgM_pane_class *)(this + 0x23ec));
  return;
}


/* __thiscall dMenu_Fmap2_c::screenSetYagura(void) */

void __thiscall dMenu_Fmap2_c::screenSetYagura(dMenu_Fmap2_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  undefined4 uVar2;
  J2DScreen *pJVar3;
  TBox2_float_ local_18;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_18.mTL.x = d_menu_fmap2::_4118;
    local_18.mTL.y = d_menu_fmap2::_4118;
    local_18.mBR.x = d_menu_fmap2::_4183;
    local_18.mBR.y = d_menu_fmap2::_4184;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_18);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 0x2c) = this_00;
  if (*(int *)(this + 0x2c) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.cpp",0x943,"fmap2GsDl.scrn != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x943,&DAT_8035ff21);
  }
  J2DScreen::set(*(J2DScreen **)(this + 0x2c),"YG_map_1.blo",
                 *(JKRArchive **)(*(int *)(this + 0x18) + 0x1c));
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2494),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x249c),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x68733034);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x24ac),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x73643035);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x24a4),uVar2);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6764646d);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x24b4),pJVar3);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x74746c31);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x24ec),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x74746c32);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x24f4),uVar2);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6c6e6b);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x24fc),pJVar3);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x67646774);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2534),pJVar3);
  setPlayerPos(this,(fopMsgM_pane_class *)(this + 0x24fc),(fopMsgM_pane_class *)(this + 0x2534),
               (fopMsgM_pane_class *)(this + 0x24b4));
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMenu_Fmap2_c::screenSetHeartM(void) */

void __thiscall dMenu_Fmap2_c::screenSetHeartM(dMenu_Fmap2_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  undefined4 uVar2;
  J2DScreen *pJVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  TBox2_float_ local_28;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_28.mTL.x = d_menu_fmap2::_4118;
    local_28.mTL.y = d_menu_fmap2::_4118;
    local_28.mBR.x = d_menu_fmap2::_4183;
    local_28.mBR.y = d_menu_fmap2::_4184;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_28);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 0x2c) = this_00;
  if (*(int *)(this + 0x2c) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.cpp",0x95f,"fmap2GsDl.scrn != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x95f,&DAT_8035ff21);
  }
  J2DScreen::set(*(J2DScreen **)(this + 0x2c),"HM_map_1.blo",
                 *(JKRArchive **)(*(int *)(this + 0x18) + 0x1c));
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x256c),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2574),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x68733034);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2584),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x73643035);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x257c),uVar2);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6764646d);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x258c),pJVar3);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x73743039);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x25c4),uVar2);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6c6e6b);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x264c),pJVar3);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x67646774);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2684),pJVar3);
  iVar4 = 0;
  iVar5 = 0;
  iVar6 = 0;
  do {
    uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))
                      (*(int **)(this + 0x2c),*(undefined4 *)((int)&d_menu_fmap2::tag_5642 + iVar6))
    ;
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar5 + 0x25cc),uVar2);
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + 8;
    iVar6 = iVar6 + 4;
  } while (iVar4 < 7);
  iVar4 = 0;
  iVar6 = 0;
  iVar5 = 0;
  do {
    uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))
                      (*(int **)(this + 0x2c),*(undefined4 *)((int)&d_menu_fmap2::tag2_5643 + iVar5)
                      );
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar6 + 0x2604),uVar2);
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 8;
    iVar5 = iVar5 + 4;
  } while (iVar4 < 9);
  setPlayerPos(this,(fopMsgM_pane_class *)(this + 0x264c),(fopMsgM_pane_class *)(this + 0x2684),
               (fopMsgM_pane_class *)(this + 0x258c));
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMenu_Fmap2_c::screenSetSubdan(void) */

void __thiscall dMenu_Fmap2_c::screenSetSubdan(dMenu_Fmap2_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  undefined4 uVar2;
  J2DScreen *pJVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  TBox2_float_ local_28;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_28.mTL.x = d_menu_fmap2::_4118;
    local_28.mTL.y = d_menu_fmap2::_4118;
    local_28.mBR.x = d_menu_fmap2::_4183;
    local_28.mBR.y = d_menu_fmap2::_4184;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_28);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 0x2c) = this_00;
  if (*(int *)(this + 0x2c) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.cpp",0x985,"fmap2GsDl.scrn != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.cpp",0x985,&DAT_8035ff21);
  }
  J2DScreen::set(*(J2DScreen **)(this + 0x2c),"IR_map_1.blo",
                 *(JKRArchive **)(*(int *)(this + 0x18) + 0x1c));
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x26bc),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6d733032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x26c4),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x68733034);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x26d4),uVar2);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6764646d);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x26dc),pJVar3);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x73643035);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x26cc),uVar2);
  uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x49473236);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2714),uVar2);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x6c6e6b);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x272c),pJVar3);
  pJVar3 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x2c) + 0x30))(*(int **)(this + 0x2c),0x67646774);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2764),pJVar3);
  iVar4 = 0;
  iVar6 = 0;
  iVar5 = 0;
  do {
    uVar2 = (**(code **)(**(int **)(this + 0x2c) + 0x30))
                      (*(int **)(this + 0x2c),*(undefined4 *)(&d_menu_fmap2::tag_5675 + iVar5));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar6 + 0x271c),uVar2);
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 8;
    iVar5 = iVar5 + 4;
  } while (iVar4 < 2);
  setPlayerPos(this,(fopMsgM_pane_class *)(this + 0x272c),(fopMsgM_pane_class *)(this + 0x2764),
               (fopMsgM_pane_class *)(this + 0x26dc));
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Fmap2_c::setPlayerPos(fopMsgM_pane_class *,
                                          fopMsgM_pane_class *,
                                          fopMsgM_pane_class *) */

void __thiscall
dMenu_Fmap2_c::setPlayerPos
          (dMenu_Fmap2_c *this,fopMsgM_pane_class *param_1,fopMsgM_pane_class *param_2,
          fopMsgM_pane_class *param_3)

{
  float fVar1;
  float fVar2;
  J2DScreen *pJVar3;
  
  fVar1 = d_menu_fmap2::_5715;
  if (this[0x2810] == (dMenu_Fmap2_c)0x0) {
    (param_1->mpPane->parent).mbDraw = 0;
  }
  else {
    (param_1->mPosCenterOrig).x =
         (param_3->mPosCenterOrig).x +
         (*(float *)(this + 0x27b0) * (param_3->mSizeOrig).x) / d_menu_fmap2::_5715;
    (param_1->mPosCenterOrig).y =
         (param_3->mPosCenterOrig).y + (*(float *)(this + 0x27b4) * (param_3->mSizeOrig).y) / fVar1;
    (param_1->mPosCenter).x = (param_1->mPosCenterOrig).x;
    (param_1->mPosCenter).y = (param_1->mPosCenterOrig).y;
    f_op_msg_mng::fopMsgM_cposMove(param_1);
    fVar1 = *(float *)(this + 0x27b8);
    fVar2 = d_menu_fmap2::_4117 * (param_1->mSizeOrig).y;
    pJVar3 = param_1->mpPane;
    (pJVar3->parent).mBasePosition.x = d_menu_fmap2::_4117 * (param_1->mSizeOrig).x;
    (pJVar3->parent).mBasePosition.y = fVar2;
    (pJVar3->parent).mRotationAxis = 'z';
    (pJVar3->parent).mRotation = fVar1;
    (*(code *)((pJVar3->parent).vtbl)->calcMtx)();
  }
  f_op_msg_mng::fopMsgM_paneTrans
            (param_2,(double)((float)((double)CONCAT44(0x43300000,
                                                       (int)(char)this[0x27bc] ^ 0x80000000) -
                                     d_menu_fmap2::_4406) * (param_2->mSizeOrig).x),
             (double)((float)((double)CONCAT44(0x43300000,(int)(char)this[0x27bd] ^ 0x80000000) -
                             d_menu_fmap2::_4406) * (param_2->mSizeOrig).y));
  *(fopMsgM_pane_class **)(this + 0x279c) = param_2;
  playerPointGridAnimeInit(this);
  playerPointGridAnime(this,param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dMenu_Fmap2_c::CmapOpenSp(void) */

void __thiscall dMenu_Fmap2_c::CmapOpenSp(dMenu_Fmap2_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_r27;
  
  iVar1 = paneTranceMessage(this,*(short *)(this + 0x27ac),DAT_803e620c,d_menu_fmap2::_4119,
                            DAT_803e6210,d_menu_fmap2::_4118,d_menu_fmap2::_4118,'\0',
                            (uchar)this[0x2816],1);
  iVar2 = paneTransSelCmapCle(this,*(short *)(this + 0x27ac) - (ushort)DAT_803e620c,DAT_803e620c,
                              d_menu_fmap2::_4119,d_menu_fmap2::_4119,d_menu_fmap2::_4118,
                              d_menu_fmap2::_4118,'\0',(uchar)this[0x2814],1);
  iVar3 = paneTransSelCmapOpn(this,*(short *)(this + 0x27ac) - (ushort)DAT_803e620c,DAT_803e620c,
                              d_menu_fmap2::_4119,d_menu_fmap2::_4119,d_menu_fmap2::_4118,
                              d_menu_fmap2::_4118,'\0',(uchar)this[0x2813],0);
  switch(this[0x280f]) {
  case (dMenu_Fmap2_c)0x3:
    unaff_r27 = paneAlphaTingleMap(this,*(short *)(this + 0x27ac) - (ushort)DAT_803e620c,
                                   DAT_803e620c,'\0',0);
    break;
  case (dMenu_Fmap2_c)0x4:
    unaff_r27 = paneAlphaGostShipMap
                          (this,*(short *)(this + 0x27ac) - (ushort)DAT_803e620c,DAT_803e620c,'\0',0
                          );
    break;
  case (dMenu_Fmap2_c)0x7:
    unaff_r27 = paneAlphaTreasureMap
                          (this,*(short *)(this + 0x27ac) - (ushort)DAT_803e620c,DAT_803e620c,'\0',0
                          );
    break;
  case (dMenu_Fmap2_c)0x9:
    unaff_r27 = paneAlphaDoctaMap(this,*(short *)(this + 0x27ac) - (ushort)DAT_803e620c,DAT_803e620c
                                  ,'\0',0);
    break;
  case (dMenu_Fmap2_c)0xa:
    unaff_r27 = paneAlphaDfaliyMap(this,*(short *)(this + 0x27ac) - (ushort)DAT_803e620c,
                                   DAT_803e620c,'\0',0);
    break;
  case (dMenu_Fmap2_c)0xb:
    unaff_r27 = paneAlphaHeartPMap(this,*(short *)(this + 0x27ac) - (ushort)DAT_803e620c,
                                   DAT_803e620c,'\0',0);
    break;
  case (dMenu_Fmap2_c)0xc:
    unaff_r27 = paneAlphaHeartMMap(this,*(short *)(this + 0x27ac) - (ushort)DAT_803e620c,
                                   DAT_803e620c,'\0',0);
    break;
  case (dMenu_Fmap2_c)0xd:
    unaff_r27 = paneAlphaSubdanMap(this,*(short *)(this + 0x27ac) - (ushort)DAT_803e620c,
                                   DAT_803e620c,'\0',0);
    break;
  case (dMenu_Fmap2_c)0xe:
    unaff_r27 = paneAlphaMoonMap(this,*(short *)(this + 0x27ac) - (ushort)DAT_803e620c,DAT_803e620c,
                                 '\0',0);
    break;
  case (dMenu_Fmap2_c)0xf:
    unaff_r27 = paneAlphaYaguraMap(this,*(short *)(this + 0x27ac) - (ushort)DAT_803e620c,
                                   DAT_803e620c,'\0',0);
    break;
  case (dMenu_Fmap2_c)0x10:
    unaff_r27 = paneAlphaTerryMap(this,*(short *)(this + 0x27ac) - (ushort)DAT_803e620c,DAT_803e620c
                                  ,'\0',0);
    break;
  case (dMenu_Fmap2_c)0x11:
    unaff_r27 = paneAlphaSubMaMap(this,*(short *)(this + 0x27ac) - (ushort)DAT_803e620c,DAT_803e620c
                                  ,'\0',0);
  }
  *(short *)(this + 0x27ac) = *(short *)(this + 0x27ac) + 1;
  if ((((iVar1 == 1) && (iVar2 == 1)) && (iVar3 == 1)) && (unaff_r27 == 1)) {
    *(undefined2 *)(this + 0x27ac) = 0;
    this[0x2812] = (dMenu_Fmap2_c)0x4;
    *(undefined2 *)(this + (uint)(byte)this[0x2816] * 2 + 0x2848) = 0xffff;
    iVar1 = getCmapDatPnt4(this,(int)(char)this[0x27a9]);
    dSv_player_map_c::onOpenMap
              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,
               *(char *)(iVar1 + 1) + -1);
    this[0x27a1] = (dMenu_Fmap2_c)0x3;
  }
  return;
}


/* __thiscall dMenu_Fmap2_c::CmapProc2(void) */

void __thiscall dMenu_Fmap2_c::CmapProc2(dMenu_Fmap2_c *this)

{
  if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
    if (this[0x280f] == (dMenu_Fmap2_c)0x4) {
      gsMoonAnimeInit(this);
      gsIconAnimeInit(this);
    }
    *(undefined2 *)(this + (uint)(byte)this[0x2816] * 2 + 0x2848) = 0x319c;
    this[0x27a1] = (dMenu_Fmap2_c)0x8;
    if (this[0x280f] == (dMenu_Fmap2_c)0x3) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x90e,(cXyz *)0x0,0,0,d_menu_fmap2::_4119,
                 d_menu_fmap2::_4119,d_menu_fmap2::_4713,d_menu_fmap2::_4713,0);
    }
    else {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x90d,(cXyz *)0x0,0,0,d_menu_fmap2::_4119,
                 d_menu_fmap2::_4119,d_menu_fmap2::_4713,d_menu_fmap2::_4713,0);
    }
  }
  if (this[0x280f] == (dMenu_Fmap2_c)0x4) {
    gsShipAnime(this);
    gsMoonAnime(this);
    gsIconAnime(this);
  }
  if (this[0x280f] == (dMenu_Fmap2_c)0x7) {
    trTrifAnime(this);
  }
  playerPointGridAnime(this,*(fopMsgM_pane_class **)(this + 0x279c));
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dMenu_Fmap2_c::CmapClose(void) */

void __thiscall dMenu_Fmap2_c::CmapClose(dMenu_Fmap2_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int unaff_r26;
  
  iVar1 = paneTranceMessage(this,*(short *)(this + 0x27ac) - (ushort)DAT_803e620c,DAT_803e620c,
                            DAT_803e6210,d_menu_fmap2::_4119,d_menu_fmap2::_4118,d_menu_fmap2::_4118
                            ,'\0',(uchar)this[0x2816],0);
  iVar2 = paneTransSelCmapCle(this,*(short *)(this + 0x27ac),DAT_803e620c,d_menu_fmap2::_4119,
                              d_menu_fmap2::_4119,d_menu_fmap2::_4118,d_menu_fmap2::_4118,'\0',
                              (uchar)this[0x2814],0);
  iVar3 = paneTransSelCmapOpn(this,*(short *)(this + 0x27ac),DAT_803e620c,d_menu_fmap2::_4119,
                              d_menu_fmap2::_4119,d_menu_fmap2::_4118,d_menu_fmap2::_4118,'\0',
                              (uchar)this[0x2813],1);
  switch(this[0x280f]) {
  case (dMenu_Fmap2_c)0x3:
    unaff_r26 = paneAlphaTingleMap(this,*(short *)(this + 0x27ac),DAT_803e620c,'\0',1);
    break;
  case (dMenu_Fmap2_c)0x4:
    unaff_r26 = paneAlphaGostShipMap(this,*(short *)(this + 0x27ac),DAT_803e620c,'\0',1);
    break;
  case (dMenu_Fmap2_c)0x7:
    unaff_r26 = paneAlphaTreasureMap(this,*(short *)(this + 0x27ac),DAT_803e620c,'\0',1);
    break;
  case (dMenu_Fmap2_c)0x9:
    unaff_r26 = paneAlphaDoctaMap(this,*(short *)(this + 0x27ac),DAT_803e620c,'\0',1);
    break;
  case (dMenu_Fmap2_c)0xa:
    unaff_r26 = paneAlphaDfaliyMap(this,*(short *)(this + 0x27ac),DAT_803e620c,'\0',1);
    break;
  case (dMenu_Fmap2_c)0xb:
    unaff_r26 = paneAlphaHeartPMap(this,*(short *)(this + 0x27ac),DAT_803e620c,'\0',1);
    break;
  case (dMenu_Fmap2_c)0xc:
    unaff_r26 = paneAlphaHeartMMap(this,*(short *)(this + 0x27ac),DAT_803e620c,'\0',1);
    break;
  case (dMenu_Fmap2_c)0xd:
    unaff_r26 = paneAlphaSubdanMap(this,*(short *)(this + 0x27ac),DAT_803e620c,'\0',1);
    break;
  case (dMenu_Fmap2_c)0xe:
    unaff_r26 = paneAlphaMoonMap(this,*(short *)(this + 0x27ac),DAT_803e620c,'\0',1);
    break;
  case (dMenu_Fmap2_c)0xf:
    unaff_r26 = paneAlphaYaguraMap(this,*(short *)(this + 0x27ac),DAT_803e620c,'\0',1);
    break;
  case (dMenu_Fmap2_c)0x10:
    unaff_r26 = paneAlphaTerryMap(this,*(short *)(this + 0x27ac),DAT_803e620c,'\0',1);
    break;
  case (dMenu_Fmap2_c)0x11:
    unaff_r26 = paneAlphaSubMaMap(this,*(short *)(this + 0x27ac),DAT_803e620c,'\0',1);
  }
  *(short *)(this + 0x27ac) = *(short *)(this + 0x27ac) + 1;
  if ((((iVar1 == 1) && (iVar2 == 1)) && (iVar3 == 1)) && (unaff_r26 == 1)) {
    *(undefined2 *)(this + 0x27ac) = 0;
    this[0x2812] = (dMenu_Fmap2_c)0x3;
    *(undefined2 *)(this + (uint)(byte)this[0x2816] * 2 + 0x2848) = 0xffff;
    piVar4 = *(int **)(this + 0x2c);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 8))(piVar4,1);
    }
    (**(code **)(**(int **)(*(int *)(this + 0x18) + 0x1c) + 0x24))();
    (**(code **)(**(int **)(*(int *)(this + 0x18) + 0x1c) + 0xc))();
    iVar1 = *(int *)(this + 0x18);
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar1 + 0x10) + 8))(iVar1,1);
    }
    this[0x27fb] = (dMenu_Fmap2_c)0x0;
    this[0x27fc] = (dMenu_Fmap2_c)0x0;
    this[0x27a1] = (dMenu_Fmap2_c)0x2;
  }
  return;
}


/* __thiscall dMenu_Fmap2_c::cmapMove(void) */

void __thiscall dMenu_Fmap2_c::cmapMove(dMenu_Fmap2_c *this)

{
  int iVar1;
  
  iVar1 = getCollectMapKind(this,(char)this[0x27a9]);
  iVar1 = isSpMap(this,iVar1);
  if (iVar1 == 0) {
    readPaneCmapTexture(this,*(ResTIMG **)(this + ((byte)this[0x2815] ^ 1) * 4 + 8),
                        (int)(char)this[0x27a9]);
    changeSelCmap(this);
    changeZoomCmap(this);
  }
  else {
    changeSelCmap2(this);
  }
  changeCmapName(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMenu_Fmap2_c::changeSelCmap(void) */

void __thiscall dMenu_Fmap2_c::changeSelCmap(dMenu_Fmap2_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = getCollectMapKind(this,(char)this[0x27a9]);
  J2DPicture::changeTexture
            (*(J2DPicture **)
              &(*(J2DPicture **)(this + ((byte)this[0x2813] ^ 1) * 4 + 0x124c))->parent,
             *(ResTIMG **)(this + ((byte)this[0x2815] ^ 1) * 4 + 8),'\0');
  iVar2 = isOpenCollectMap(this,(char)this[0x27a9]);
  if (iVar2 == 0) {
    this[0x2812] = (dMenu_Fmap2_c)0x3;
    iVar3 = 0;
    *(undefined *)(**(int **)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0xaa) = 0;
    iVar2 = 0;
    do {
      *(undefined *)
       (*(int *)(*(int *)(this + ((byte)this[0x2814] ^ 1) * 4 + 0x1244) + iVar2) + 0xaa) = 1;
      J2DPicture::changeTexture
                (*(J2DPicture **)(*(int *)(this + ((byte)this[0x2814] ^ 1) * 4 + 0x1244) + iVar2),
                 *(char **)(&d_menu_fmap2::rollmapTex + iVar1 * 4),0);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x38;
    } while (iVar3 < 2);
    *(undefined *)(**(int **)(this + ((byte)this[0x2816] ^ 1) * 4 + 0xcc4) + 0xaa) = 1;
    dDlst_2DOutFont_c::messageSet
              (*(dDlst_2DOutFont_c **)(this + ((byte)this[0x2816] ^ 1) * 4 + 0x3c),0x319e);
    dDlst_2DOutFont_c::messageSet
              (*(dDlst_2DOutFont_c **)(this + ((byte)this[0x2816] ^ 1) * 4 + 0x44),0x319e);
    if (iVar1 == 0) {
      J2DPicture::changeTexture
                (*(J2DPicture **)(*(int *)(this + ((byte)this[0x2813] ^ 1) * 4 + 0x124c) + 0x38),
                 "f_cmap_t.bti",0);
      J2DPicture::changeTexture
                (*(J2DPicture **)(*(int *)(this + ((byte)this[0x2813] ^ 1) * 4 + 0x124c) + 0x70),
                 "f_cmap_t.bti",0);
    }
    else {
      J2DPicture::changeTexture
                (*(J2DPicture **)(*(int *)(this + ((byte)this[0x2813] ^ 1) * 4 + 0x124c) + 0x38),
                 "f_cmap_normal.bti",0);
      J2DPicture::changeTexture
                (*(J2DPicture **)(*(int *)(this + ((byte)this[0x2813] ^ 1) * 4 + 0x124c) + 0x70),
                 "f_cmap_normal.bti",0);
    }
    iVar1 = 0;
    iVar2 = 5;
    do {
      *(undefined *)
       (*(int *)(*(int *)(this + ((byte)this[0x2813] ^ 1) * 4 + 0x124c) + iVar1) + 0xaa) = 0;
      iVar1 = iVar1 + 0x38;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  else {
    this[0x2812] = (dMenu_Fmap2_c)0x2;
    *(undefined *)(**(int **)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0xaa) = 1;
    iVar2 = 0;
    iVar3 = 2;
    do {
      *(undefined *)
       (*(int *)(*(int *)(this + ((byte)this[0x2814] ^ 1) * 4 + 0x1244) + iVar2) + 0xaa) = 0;
      iVar2 = iVar2 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar2 = 0;
    iVar3 = 5;
    do {
      *(undefined *)
       (*(int *)(*(int *)(this + ((byte)this[0x2813] ^ 1) * 4 + 0x124c) + iVar2) + 0xaa) = 1;
      iVar2 = iVar2 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (iVar1 == 0) {
      J2DPicture::changeTexture
                (*(J2DPicture **)(*(int *)(this + ((byte)this[0x2813] ^ 1) * 4 + 0x124c) + 0x38),
                 "f_cmap_t.bti",0);
      J2DPicture::changeTexture
                (*(J2DPicture **)(*(int *)(this + ((byte)this[0x2813] ^ 1) * 4 + 0x124c) + 0x70),
                 "f_cmap_t.bti",0);
      iVar1 = isOpenCollectMapTriforce(this,(char)this[0x27a9]);
      if (iVar1 == 0) {
        *(undefined *)(**(int **)(this + ((byte)this[0x2813] ^ 1) * 4 + 0x124c) + 0xaa) = 0;
        *(undefined *)(**(int **)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0xaa) = 0;
        *(undefined *)(**(int **)(this + ((byte)this[0x2816] ^ 1) * 4 + 0xcc4) + 0xaa) = 1;
        dDlst_2DOutFont_c::messageSet
                  (*(dDlst_2DOutFont_c **)(this + ((byte)this[0x2816] ^ 1) * 4 + 0x3c),0x319d);
        dDlst_2DOutFont_c::messageSet
                  (*(dDlst_2DOutFont_c **)(this + ((byte)this[0x2816] ^ 1) * 4 + 0x44),0x319d);
      }
      else {
        *(undefined *)
         (*(int *)(*(int *)(this + ((byte)this[0x2813] ^ 1) * 4 + 0x124c) + 0xa8) + 0xaa) = 0;
      }
    }
    else {
      J2DPicture::changeTexture
                (*(J2DPicture **)(*(int *)(this + ((byte)this[0x2813] ^ 1) * 4 + 0x124c) + 0x38),
                 "f_cmap_normal.bti",0);
      J2DPicture::changeTexture
                (*(J2DPicture **)(*(int *)(this + ((byte)this[0x2813] ^ 1) * 4 + 0x124c) + 0x70),
                 "f_cmap_normal.bti",0);
      *(undefined *)(*(int *)(*(int *)(this + ((byte)this[0x2813] ^ 1) * 4 + 0x124c) + 0xa8) + 0xaa)
           = 0;
    }
    iVar1 = isCompleteCollectMap(this,(char)this[0x27a9]);
    if (iVar1 == 0) {
      *(undefined *)(*(int *)(*(int *)(this + ((byte)this[0x2813] ^ 1) * 4 + 0x124c) + 0xe0) + 0xaa)
           = 0;
    }
    cmapAlphaSet(this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dMenu_Fmap2_c::changeSelCmap2(void) */

void __thiscall dMenu_Fmap2_c::changeSelCmap2(dMenu_Fmap2_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  this[0x2812] = (dMenu_Fmap2_c)0x3;
  iVar1 = getCollectMapKind(this,(char)this[0x27a9]);
  iVar3 = 0;
  *(undefined *)(**(int **)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0xaa) = 0;
  iVar2 = 0;
  do {
    *(undefined *)(*(int *)(*(int *)(this + ((byte)this[0x2814] ^ 1) * 4 + 0x1244) + iVar3) + 0xaa)
         = 1;
    J2DPicture::changeTexture
              (*(J2DPicture **)(*(int *)(this + ((byte)this[0x2814] ^ 1) * 4 + 0x1244) + iVar3),
               *(char **)(&d_menu_fmap2::rollmapTex + iVar1 * 4),0);
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar2 < 2);
  *(undefined *)(**(int **)(this + ((byte)this[0x2816] ^ 1) * 4 + 0xcc4) + 0xaa) = 1;
  iVar1 = isOpenCollectMap(this,(char)this[0x27a9]);
  if (iVar1 == 0) {
    dDlst_2DOutFont_c::messageSet
              (*(dDlst_2DOutFont_c **)(this + ((byte)this[0x2816] ^ 1) * 4 + 0x3c),0x319e);
    dDlst_2DOutFont_c::messageSet
              (*(dDlst_2DOutFont_c **)(this + ((byte)this[0x2816] ^ 1) * 4 + 0x44),0x319e);
  }
  else {
    dDlst_2DOutFont_c::messageSet
              (*(dDlst_2DOutFont_c **)(this + ((byte)this[0x2816] ^ 1) * 4 + 0x3c),0x319c);
    dDlst_2DOutFont_c::messageSet
              (*(dDlst_2DOutFont_c **)(this + ((byte)this[0x2816] ^ 1) * 4 + 0x44),0x319c);
  }
  iVar1 = 0;
  iVar2 = 5;
  do {
    *(undefined *)(*(int *)(*(int *)(this + ((byte)this[0x2813] ^ 1) * 4 + 0x124c) + iVar1) + 0xaa)
         = 0;
    iVar1 = iVar1 + 0x38;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


/* __thiscall dMenu_Fmap2_c::cmapAlphaSet(void) */

void __thiscall dMenu_Fmap2_c::cmapAlphaSet(dMenu_Fmap2_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = isCompleteCollectMap(this,(char)this[0x27a9]);
  if (iVar1 == 0) {
    iVar1 = 0;
    iVar2 = 3;
    do {
      *(char *)(*(int *)(this + ((byte)this[0x2813] ^ 1) * 4 + 0x124c) + iVar1 + 0x34) =
           (char)*(undefined2 *)
                  (*(int *)(this + ((byte)this[0x2813] ^ 1) * 4 + 0x124c) + iVar1 + 0x36);
      iVar1 = iVar1 + 0x38;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar1 = 0;
    iVar2 = 4;
    do {
      *(char *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + iVar1 + 0x34) =
           (char)*(undefined2 *)
                  (*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + iVar1 + 0x36);
      iVar1 = iVar1 + 0x38;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(char *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0x22c) =
         (char)*(undefined2 *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0x22e);
  }
  else {
    iVar1 = 0;
    iVar2 = 3;
    do {
      *(undefined *)(*(int *)(this + ((byte)this[0x2813] ^ 1) * 4 + 0x124c) + iVar1 + 0x34) = 0x50;
      iVar1 = iVar1 + 0x38;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar1 = 0;
    iVar2 = 4;
    do {
      *(undefined *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + iVar1 + 0x34) = 0x50;
      iVar1 = iVar1 + 0x38;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(undefined *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0x22c) = 0x50;
  }
  return;
}


/* __thiscall dMenu_Fmap2_c::changeZoomCmap(void) */

void __thiscall dMenu_Fmap2_c::changeZoomCmap(dMenu_Fmap2_c *this)

{
  J2DPicture::changeTexture
            (*(J2DPicture **)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0xa8),
             *(ResTIMG **)(this + ((byte)this[0x2815] ^ 1) * 4 + 8),'\0');
  cmapPlayerPosDisp(this);
  cmapSalvagePosDisp(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801c3428) */
/* WARNING: Removing unreachable block (ram,0x801c3654) */
/* __thiscall dMenu_Fmap2_c::ChangeProcMode(void) */

void __thiscall dMenu_Fmap2_c::ChangeProcMode(dMenu_Fmap2_c *this)

{
  ulong uVar1;
  int unaff_r27;
  int unaff_r29;
  int unaff_r30;
  int unaff_r31;
  
  if (*(int *)(this + 0x10) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.h",0x1b2,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.h",0x1b2,&DAT_8035ff21);
  }
  if (*(char *)(*(int *)(this + 0x10) + 8) == '\x01') {
    unaff_r31 = paneAlphaFmapBase(this,*(short *)(this + 0x27ac),DAT_803e620a,'\0',0);
    unaff_r30 = paneAlphaCmapBase(this,*(short *)(this + 0x27ac),DAT_803e620a,'\0',1);
    if (*(char *)(*(int *)(this + 0x43c) + 0xaa) == '\0') {
      unaff_r29 = 1;
    }
    else {
      unaff_r29 = paneAlphaMessage2(this,*(short *)(this + 0x27ac),DAT_803e620a,'\0',0);
    }
    if (*(char *)(**(int **)(this + (uint)(byte)this[0x2816] * 4 + 0xcc4) + 0xaa) == '\0') {
      unaff_r27 = 1;
    }
    else {
      unaff_r27 = paneTranceMessage(this,*(short *)(this + 0x27ac),DAT_803e620a,d_menu_fmap2::_4119,
                                    d_menu_fmap2::_4119,d_menu_fmap2::_4118,d_menu_fmap2::_4118,'\0'
                                    ,(uchar)this[0x2816],0);
    }
  }
  else {
    if (*(char *)(*(int *)(this + 0x10) + 8) == '\0') {
      unaff_r31 = paneAlphaFmapBase(this,*(short *)(this + 0x27ac),DAT_803e620a,'\0',1);
      unaff_r30 = paneAlphaCmapBase(this,*(short *)(this + 0x27ac),DAT_803e620a,'\0',0);
      if (*(char *)(*(int *)(this + 0x43c) + 0xaa) == '\0') {
        unaff_r29 = 1;
      }
      else {
        unaff_r29 = paneAlphaMessage2(this,*(short *)(this + 0x27ac),DAT_803e620a,'\0',1);
      }
      if (*(char *)(**(int **)(this + (uint)(byte)this[0x2816] * 4 + 0xcc4) + 0xaa) == '\0') {
        unaff_r27 = 1;
      }
      else {
        unaff_r27 = paneTranceMessage(this,*(short *)(this + 0x27ac),DAT_803e620a,
                                      d_menu_fmap2::_4119,d_menu_fmap2::_4119,d_menu_fmap2::_4118,
                                      d_menu_fmap2::_4118,'\0',(uchar)this[0x2816],1);
      }
    }
  }
  *(short *)(this + 0x27ac) = *(short *)(this + 0x27ac) + 1;
  if ((((unaff_r31 == 1) && (unaff_r30 == 1)) && (unaff_r29 == 1)) && (unaff_r27 == 1)) {
    *(undefined2 *)(this + 0x27ac) = 0;
    if (*(int *)(this + 0x10) == 0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"d_menu_fmap2.h",0x1b2,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap2.h",0x1b2,&DAT_8035ff21);
    }
    if (*(char *)(*(int *)(this + 0x10) + 8) == '\x01') {
      if ((byte)this[0x27a8] < 2) {
        cSelCursorHide(this);
      }
      else {
        cCursorAnimeInit(this);
        cSelCursorInit(this);
      }
      *(undefined *)(*(int *)(this + 0x128c) + 0xaa) = 0;
      this[0x27a1] = (dMenu_Fmap2_c)0x2;
    }
    else {
      if (*(char *)(*(int *)(this + 0x10) + 8) == '\0') {
        fCursorInit(this);
        *(undefined *)(*(int *)(this + 0x1254) + 0xaa) = 0;
        this[0x27a1] = (dMenu_Fmap2_c)0x0;
      }
    }
  }
  return;
}


/* __thiscall dMenu_Fmap2_c::_open(void) */

bool __thiscall dMenu_Fmap2_c::_open(dMenu_Fmap2_c *this)

{
  int iVar1;
  
  iVar1 = paneTransBase(this,*(short *)(this + 0x27ac),DAT_803e6204,
                        (float)((double)CONCAT44(0x43300000,(int)DAT_803e6206 ^ 0x80000000) -
                               d_menu_fmap2::_4406),d_menu_fmap2::_4118,'\0',(uchar)this[0x2815],0);
  *(short *)(this + 0x27ac) = *(short *)(this + 0x27ac) + 1;
  if (iVar1 == 1) {
    *(undefined2 *)(this + 0x27ac) = 0;
    *(undefined2 *)(this + 0x2848) = 0xffff;
    *(undefined2 *)(this + 0x284a) = 0xffff;
  }
  return iVar1 == 1;
}


/* __thiscall dMenu_Fmap2_c::_close(void) */

undefined4 __thiscall dMenu_Fmap2_c::_close(dMenu_Fmap2_c *this)

{
  dMenu_Fmap2_c dVar1;
  int iVar2;
  ulong uVar3;
  undefined4 uVar4;
  
  iVar2 = paneTransBase(this,*(short *)(this + 0x27ac),DAT_803e6204,d_menu_fmap2::_4118,
                        (float)((double)CONCAT44(0x43300000,(int)DAT_803e6208 ^ 0x80000000) -
                               d_menu_fmap2::_4406),'\0',(uchar)this[0x2815],1);
  *(short *)(this + 0x27ac) = *(short *)(this + 0x27ac) + 1;
  if (iVar2 == 1) {
    *(undefined2 *)(this + 0x27ac) = 0;
    dVar1 = this[0x27a9];
    if (*(int *)(this + 0x10) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_menu_fmap2.h",0x1ed,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap2.h",0x1ed,&DAT_8035ff21);
    }
    *(dMenu_Fmap2_c *)(*(int *)(this + 0x10) + 9) = dVar1;
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_Fmap2_c::_draw(void) */

void __thiscall dMenu_Fmap2_c::_draw(dMenu_Fmap2_c *this)

{
  dMenu_Fmap2_c dVar1;
  
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    (dDlst_base_c *)(this + 0x20));
  dVar1 = this[0x27fb];
  if (((dVar1 != (dMenu_Fmap2_c)0x2) && ((byte)dVar1 < 2)) && (dVar1 != (dMenu_Fmap2_c)0x0)) {
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                      (dDlst_base_c *)(this + 0x28));
  }
  return;
}


/* __thiscall dMenu_Fmap2_c::_delete(void) */

void __thiscall dMenu_Fmap2_c::_delete(dMenu_Fmap2_c *this)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 0x24);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  JKernel::operator_delete(*(JKRHeap **)(this + 0x30));
  JKernel::operator_delete(*(JKRHeap **)(this + 4));
  JKernel::operator_delete(*(JKRHeap **)(this + 8));
  JKernel::operator_delete(*(JKRHeap **)(this + 0xc));
  if (*(JKRHeap **)(this + 0x3c) != (JKRHeap *)0x0) {
    JKernel::operator_delete(*(JKRHeap **)(this + 0x3c));
  }
  if (*(JKRHeap **)(this + 0x44) != (JKRHeap *)0x0) {
    JKernel::operator_delete(*(JKRHeap **)(this + 0x44));
  }
  if (*(JKRHeap **)(this + 0x40) != (JKRHeap *)0x0) {
    JKernel::operator_delete(*(JKRHeap **)(this + 0x40));
  }
  if (*(JKRHeap **)(this + 0x48) != (JKRHeap *)0x0) {
    JKernel::operator_delete(*(JKRHeap **)(this + 0x48));
  }
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e61d0);
  return;
}


/* __thiscall dMenu_Fmap2_c::fCursorInit(void) */

void __thiscall dMenu_Fmap2_c::fCursorInit(dMenu_Fmap2_c *this)

{
  int iVar1;
  int iVar2;
  
  this[0x27a5] = (dMenu_Fmap2_c)0x0;
  iVar1 = 0;
  iVar2 = 4;
  do {
    *(undefined *)(*(int *)(this + iVar1 + 0x84) + 0xaa) = 1;
    *(undefined *)(*(int *)(this + iVar1 + 0x164) + 0xaa) = 0;
    iVar1 = iVar1 + 0x38;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(ushort *)(this + 0xba) = (ushort)DAT_803e6214;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x801c3ca4) */
/* WARNING: Removing unreachable block (ram,0x801c3cac) */
/* __thiscall dMenu_Fmap2_c::fCursorMove(void) */

void __thiscall dMenu_Fmap2_c::fCursorMove(dMenu_Fmap2_c *this)

{
  char cVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 in_f30;
  double y;
  undefined8 in_f31;
  double x;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (*(int *)(this + 0x10) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_fmap2.h",0x1d2,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.h",0x1d2,&DAT_8035ff21);
  }
  x = (double)(d_menu_fmap2::_4467 *
              (float)((double)CONCAT44(0x43300000,
                                       (int)*(char *)(*(int *)(this + 0x10) + 10) ^ 0x80000000) -
                     d_menu_fmap2::_4406));
  if (*(int *)(this + 0x10) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_fmap2.h",0x1dc,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.h",0x1dc,&DAT_8035ff21);
  }
  y = (double)(d_menu_fmap2::_4467 *
              (float)((double)CONCAT44(0x43300000,
                                       (int)*(char *)(*(int *)(this + 0x10) + 0xb) ^ 0x80000000) -
                     d_menu_fmap2::_4406));
  iVar3 = 0;
  iVar4 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar4 + 0x84),x,y);
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar3 < 8);
  if (*(int *)(this + 0x10) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_fmap2.h",0x1dc,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.h",0x1dc,&DAT_8035ff21);
  }
  cVar1 = *(char *)(*(int *)(this + 0x10) + 0xb);
  if (*(int *)(this + 0x10) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_fmap2.h",0x1d2,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.h",0x1d2,&DAT_8035ff21);
  }
  iVar3 = dSv_player_map_c::isSaveArriveGrid
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,
                     (int)*(char *)(*(int *)(this + 0x10) + 10) + (cVar1 + 3) * 7 + 3);
  if (iVar3 == 0) {
    **(undefined **)(this + 0x27c0) = 0;
    **(undefined **)(this + 0x27c4) = 0;
    *(undefined *)(*(int *)(this + 0x13a4) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + 0x13dc) + 0xaa) = 1;
    *(undefined *)(*(int *)(this + 0x1414) + 0xaa) = 1;
    *(undefined *)(*(int *)(this + 0x144c) + 0xaa) = 1;
    *(undefined *)(*(int *)(this + 0xdac) + 0xaa) = 0;
  }
  else {
    changeIslandName(this);
    *(undefined *)(*(int *)(this + 0x13a4) + 0xaa) = 1;
    *(undefined *)(*(int *)(this + 0x13dc) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + 0x1414) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + 0x144c) + 0xaa) = 0;
    changeFmapTexture(this);
    this[0x13a0] = (dMenu_Fmap2_c)0xff;
    this[0x13a1] = (dMenu_Fmap2_c)0xff;
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x136c),d_menu_fmap2::_4119);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x136c));
    fmapPlayerPosDisp(this);
  }
  if (this[0x2810] == (dMenu_Fmap2_c)0x0) {
    *(undefined *)(*(int *)(this + 0xdac) + 0xaa) = 0;
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return;
}


/* __thiscall dMenu_Fmap2_c::fCursorAnime(void) */

void __thiscall dMenu_Fmap2_c::fCursorAnime(dMenu_Fmap2_c *this)

{
  int iVar1;
  int iVar2;
  
  if (*(short *)(this + 0xba) == 0) {
    iVar1 = 0;
    iVar2 = 4;
    do {
      *(undefined *)(*(int *)(this + (iVar1 + ((byte)this[0x27a5] ^ 1) * 4) * 0x38 + 0x84) + 0xaa) =
           1;
      *(undefined *)(*(int *)(this + (iVar1 + (uint)(byte)this[0x27a5] * 4) * 0x38 + 0x84) + 0xaa) =
           0;
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    this[0x27a5] = (dMenu_Fmap2_c)((byte)this[0x27a5] ^ 1);
    *(ushort *)(this + 0xba) = (ushort)DAT_803e6214;
    return;
  }
  *(short *)(this + 0xba) = *(short *)(this + 0xba) + -1;
  return;
}


/* __thiscall dMenu_Fmap2_c::cCursorAnimeInit(void) */

void __thiscall dMenu_Fmap2_c::cCursorAnimeInit(dMenu_Fmap2_c *this)

{
  int iVar1;
  int iVar2;
  
  this[0x27a6] = (dMenu_Fmap2_c)0x0;
  iVar1 = 0;
  iVar2 = 4;
  do {
    *(undefined *)(*(int *)(this + iVar1 + 0x244) + 0xaa) = 1;
    *(undefined *)(*(int *)(this + iVar1 + 0x324) + 0xaa) = 0;
    iVar1 = iVar1 + 0x38;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined2 *)(this + 0x27a) = 0;
  return;
}


/* __thiscall dMenu_Fmap2_c::cCursorAnime(void) */

void __thiscall dMenu_Fmap2_c::cCursorAnime(dMenu_Fmap2_c *this)

{
  int iVar1;
  int iVar2;
  
  if (*(short *)(this + 0x27a) == 0) {
    iVar1 = 0;
    iVar2 = 4;
    do {
      *(undefined *)(*(int *)(this + (iVar1 + ((byte)this[0x27a6] ^ 1) * 4) * 0x38 + 0x244) + 0xaa)
           = 1;
      *(undefined *)(*(int *)(this + (iVar1 + (uint)(byte)this[0x27a6] * 4) * 0x38 + 0x244) + 0xaa)
           = 0;
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    this[0x27a6] = (dMenu_Fmap2_c)((byte)this[0x27a6] ^ 1);
    *(ushort *)(this + 0x27a) = (ushort)DAT_803e6215;
    return;
  }
  *(short *)(this + 0x27a) = *(short *)(this + 0x27a) + -1;
  return;
}


/* __thiscall dMenu_Fmap2_c::cCursorHide(void) */

void __thiscall dMenu_Fmap2_c::cCursorHide(dMenu_Fmap2_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 8;
  do {
    *(undefined *)(*(int *)(this + iVar1 + 0x244) + 0xaa) = 0;
    iVar1 = iVar1 + 0x38;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


/* __thiscall dMenu_Fmap2_c::cSelCursorInit(void) */

void __thiscall dMenu_Fmap2_c::cSelCursorInit(dMenu_Fmap2_c *this)

{
  *(undefined *)(*(int *)(this + 0xe8c) + 0xaa) = 1;
  *(undefined *)(*(int *)(this + 0xec4) + 0xaa) = 1;
  return;
}


/* __thiscall dMenu_Fmap2_c::cSelCursorAnimeInit(void) */

void __thiscall dMenu_Fmap2_c::cSelCursorAnimeInit(dMenu_Fmap2_c *this)

{
  this[0x27a7] = (dMenu_Fmap2_c)0x0;
  *(ushort *)(this + 0xec2) = (ushort)DAT_803e6216;
  return;
}


/* __thiscall dMenu_Fmap2_c::cSelCursorAnime(void) */

void __thiscall dMenu_Fmap2_c::cSelCursorAnime(dMenu_Fmap2_c *this)

{
  short sVar1;
  double dVar2;
  
  sVar1 = *(short *)(this + 0xec2);
  if ((-1 < sVar1) && ((int)sVar1 <= (int)(uint)DAT_803e6216)) {
    dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease((uint)DAT_803e6216,(int)sVar1,0);
    if (this[0x27a7] == (dMenu_Fmap2_c)0x0) {
      dVar2 = (double)(float)((double)d_menu_fmap2::_4119 - dVar2);
    }
    dVar2 = (double)(float)(dVar2 * (double)(float)((double)CONCAT44(0x43300000,(uint)DAT_803e6217)
                                                   - d_menu_fmap2::_5260));
    if (this[0x27ab] == (dMenu_Fmap2_c)0x1) {
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0xe8c),dVar2,(double)d_menu_fmap2::_4118);
    }
    else {
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0xec4),-dVar2,(double)d_menu_fmap2::_4118);
    }
    if (*(short *)(this + 0xec2) == 0) {
      this[0x27a7] = (dMenu_Fmap2_c)((byte)this[0x27a7] ^ 1);
      if (this[0x27a7] == (dMenu_Fmap2_c)0x0) {
        *(ushort *)(this + 0xec2) = DAT_803e6216 + 1;
      }
      else {
        *(ushort *)(this + 0xec2) = (ushort)DAT_803e6216;
      }
    }
    else {
      *(short *)(this + 0xec2) = *(short *)(this + 0xec2) + -1;
    }
  }
  return;
}


/* __thiscall dMenu_Fmap2_c::cSelCursorHide(void) */

void __thiscall dMenu_Fmap2_c::cSelCursorHide(dMenu_Fmap2_c *this)

{
  *(undefined *)(*(int *)(this + 0xe8c) + 0xaa) = 0;
  *(undefined *)(*(int *)(this + 0xec4) + 0xaa) = 0;
  return;
}


/* __thiscall dMenu_Fmap2_c::playerPointGridAnimeInit(void) */

void __thiscall dMenu_Fmap2_c::playerPointGridAnimeInit(dMenu_Fmap2_c *this)

{
  this[0x27be] = SUB21(DAT_803e61e2,0);
  this[0x27bf] = (dMenu_Fmap2_c)0x0;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMenu_Fmap2_c::playerPointGridAnime(fopMsgM_pane_class *) */

void __thiscall dMenu_Fmap2_c::playerPointGridAnime(dMenu_Fmap2_c *this,fopMsgM_pane_class *param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  dMenu_Fmap2_c dVar11;
  dMenu_Fmap2_c dVar12;
  J2DScreen *pJVar13;
  double dVar14;
  
  if (param_1 != (fopMsgM_pane_class *)0x0) {
    dVar14 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                               ((int)DAT_803e61e2,(int)(char)this[0x27be],2);
    if (this[0x27bf] == (dMenu_Fmap2_c)0x0) {
      dVar14 = (double)(float)((double)d_menu_fmap2::_4119 - dVar14);
    }
    dVar1 = (double)CONCAT44(0x43300000,(uint)DAT_803e61d5) - d_menu_fmap2::_5260;
    dVar2 = (double)CONCAT44(0x43300000,(uint)DAT_803e61dd - (uint)DAT_803e61d5 ^ 0x80000000) -
            d_menu_fmap2::_4406;
    dVar3 = (double)CONCAT44(0x43300000,(uint)DAT_803e61d6) - d_menu_fmap2::_5260;
    dVar4 = (double)CONCAT44(0x43300000,(uint)DAT_803e61de - (uint)DAT_803e61d6 ^ 0x80000000) -
            d_menu_fmap2::_4406;
    dVar5 = (double)CONCAT44(0x43300000,(uint)DAT_803e61d7) - d_menu_fmap2::_5260;
    dVar6 = (double)CONCAT44(0x43300000,(uint)DAT_803e61df - (uint)DAT_803e61d7 ^ 0x80000000) -
            d_menu_fmap2::_4406;
    dVar11 = this[0x27f8];
    dVar7 = (double)CONCAT44(0x43300000,(uint)DAT_803e61d2) - d_menu_fmap2::_5260;
    dVar8 = (double)CONCAT44(0x43300000,(uint)DAT_803e61da - (uint)DAT_803e61d2 ^ 0x80000000) -
            d_menu_fmap2::_4406;
    dVar9 = (double)CONCAT44(0x43300000,(uint)DAT_803e61d3) - d_menu_fmap2::_5260;
    dVar10 = (double)CONCAT44(0x43300000,(uint)DAT_803e61db - (uint)DAT_803e61d3 ^ 0x80000000) -
             d_menu_fmap2::_4406;
    dVar12 = this[0x27f9];
    pJVar13 = param_1->mpPane;
    *(char *)&pJVar13[1].parent.mBox.mTL.y =
         (char)(int)((float)((double)CONCAT44(0x43300000,(uint)DAT_803e61d1) - d_menu_fmap2::_5260)
                    + (float)(dVar14 * (double)(float)((double)CONCAT44(0x43300000,
                                                                        (uint)DAT_803e61d9 -
                                                                        (uint)DAT_803e61d1 ^
                                                                        0x80000000) -
                                                      d_menu_fmap2::_4406)));
    *(char *)((int)&pJVar13[1].parent.mBox.mTL.y + 1) =
         (char)(int)((float)dVar7 + (float)(dVar14 * (double)(float)dVar8));
    *(char *)((int)&pJVar13[1].parent.mBox.mTL.y + 2) =
         (char)(int)((float)dVar9 + (float)(dVar14 * (double)(float)dVar10));
    *(dMenu_Fmap2_c *)((int)&pJVar13[1].parent.mBox.mTL.y + 3) = dVar12;
    pJVar13 = param_1->mpPane;
    *(char *)&pJVar13[1].parent.mBox.mBR.x =
         (char)(int)((float)dVar1 + (float)(dVar14 * (double)(float)dVar2));
    *(char *)((int)&pJVar13[1].parent.mBox.mBR.x + 1) =
         (char)(int)((float)dVar3 + (float)(dVar14 * (double)(float)dVar4));
    *(char *)((int)&pJVar13[1].parent.mBox.mBR.x + 2) =
         (char)(int)((float)dVar5 + (float)(dVar14 * (double)(float)dVar6));
    *(dMenu_Fmap2_c *)((int)&pJVar13[1].parent.mBox.mBR.x + 3) = dVar11;
    if (this[0x27be] == (dMenu_Fmap2_c)0x0) {
      this[0x27be] = SUB21(DAT_803e61e2,0);
      this[0x27bf] = (dMenu_Fmap2_c)((byte)this[0x27bf] ^ 1);
    }
    else {
      this[0x27be] = (dMenu_Fmap2_c)((char)this[0x27be] + -1);
    }
  }
  return;
}


/* __thiscall dMenu_Fmap2_c::changeFmapTexture(void) */

void __thiscall dMenu_Fmap2_c::changeFmapTexture(dMenu_Fmap2_c *this)

{
  char cVar1;
  ulong uVar2;
  int iVar3;
  char acStack72 [64];
  
  if (*(int *)(this + 0x10) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_fmap2.h",0x1dc,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.h",0x1dc,&DAT_8035ff21);
  }
  cVar1 = *(char *)(*(int *)(this + 0x10) + 0xb);
  if (*(int *)(this + 0x10) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_fmap2.h",0x1d2,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.h",0x1d2,&DAT_8035ff21);
  }
  MSL_C.PPCEABI.bare.H::sprintf
            (acStack72,"R%02X_b.bti",
             (int)*(char *)(*(int *)(this + 0x10) + 10) + (cVar1 + 3) * 7 + 4);
  iVar3 = readFmapTexture(this,acStack72);
  if (iVar3 == 0) {
    *(undefined *)(*(int *)(this + 0x136c) + 0xaa) = 0;
  }
  else {
    *(undefined *)(*(int *)(this + 0x136c) + 0xaa) = 1;
    J2DPicture::changeTexture(*(J2DPicture **)(this + 0x136c),*(ResTIMG **)(this + 4),'\0');
  }
  return;
}


/* __thiscall dMenu_Fmap2_c::changeIslandName(void) */

void __thiscall dMenu_Fmap2_c::changeIslandName(dMenu_Fmap2_c *this)

{
  char cVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(this + 0x10) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_fmap2.h",0x1dc,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.h",0x1dc,&DAT_8035ff21);
  }
  cVar1 = *(char *)(*(int *)(this + 0x10) + 0xb);
  if (*(int *)(this + 0x10) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_fmap2.h",0x1d2,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.h",0x1d2,&DAT_8035ff21);
  }
  iVar4 = (int)*(char *)(*(int *)(this + 0x10) + 10) + (cVar1 + 3) * 7 + 3;
  if ((iVar4 == 0x20) &&
     (iVar3 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2d80),
     iVar3 != 0)) {
    iVar4 = 0x31d7;
  }
  else {
    iVar4 = iVar4 + 0x31a6;
  }
  f_op_msg_mng::fopMsgM_messageGet(*(undefined4 *)(this + 0x27c0),iVar4);
  f_op_msg_mng::fopMsgM_messageGet(*(undefined4 *)(this + 0x27c4),iVar4);
  return;
}


/* __thiscall dMenu_Fmap2_c::fmapPlayerPosDisp(void) */

void __thiscall dMenu_Fmap2_c::fmapPlayerPosDisp(dMenu_Fmap2_c *this)

{
  double dVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int *piVar5;
  float local_38;
  float local_34;
  longlong local_30;
  undefined4 local_28;
  uint uStack36;
  longlong local_20;
  undefined4 local_18;
  uint uStack20;
  
  iVar4 = fmapPlayerPosDispCheck(this,&local_34,&local_38);
  fVar3 = d_menu_fmap2::_6402;
  if (iVar4 == 1) {
    fVar2 = *(float *)(this + 0x1394) * d_menu_fmap2::_4117;
    *(float *)(this + 0xdc0) =
         *(float *)(this + 0x1370) + *(float *)(this + 0x1390) * d_menu_fmap2::_4117 +
         local_34 * (*(float *)(this + 0x1390) / d_menu_fmap2::_6402);
    *(float *)(this + 0xdc4) =
         *(float *)(this + 0x1374) + fVar2 + local_38 * (*(float *)(this + 0x1394) / fVar3);
    *(undefined4 *)(this + 0xdc8) = *(undefined4 *)(this + 0xdc0);
    *(undefined4 *)(this + 0xdcc) = *(undefined4 *)(this + 0xdc4);
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(this + 0xdac));
    iVar4 = *(int *)(this + 0x27b8);
    local_30 = (longlong)(int)(d_menu_fmap2::_4117 * *(float *)(this + 0xdd4));
    uStack36 = (int)(d_menu_fmap2::_4117 * *(float *)(this + 0xdd4)) ^ 0x80000000;
    local_28 = 0x43300000;
    dVar1 = (double)CONCAT44(0x43300000,uStack36) - d_menu_fmap2::_4406;
    piVar5 = *(int **)(this + 0xdac);
    local_20 = (longlong)(int)(d_menu_fmap2::_4117 * *(float *)(this + 0xdd0));
    uStack20 = (int)(d_menu_fmap2::_4117 * *(float *)(this + 0xdd0)) ^ 0x80000000;
    local_18 = 0x43300000;
    piVar5[0x27] = (int)(float)((double)CONCAT44(0x43300000,uStack20) - d_menu_fmap2::_4406);
    piVar5[0x28] = (int)(float)dVar1;
    *(undefined *)(piVar5 + 0x2a) = 0x7a;
    piVar5[0x29] = iVar4;
    (**(code **)(*piVar5 + 0x20))();
    *(undefined *)(*(int *)(this + 0xdac) + 0xaa) = 1;
  }
  else {
    *(undefined *)(*(int *)(this + 0xdac) + 0xaa) = 0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMenu_Fmap2_c::fmapPlayerPosDispCheck(float *,
                                                    float *) */

undefined4 __thiscall
dMenu_Fmap2_c::fmapPlayerPosDispCheck(dMenu_Fmap2_c *this,float *param_1,float *param_2)

{
  double dVar1;
  char cVar2;
  float fVar3;
  dMap_c *this_00;
  ulong uVar4;
  dMap_c *pdVar5;
  undefined4 uVar6;
  float *pfVar7;
  char cVar8;
  uchar *in_r9;
  char local_48;
  char local_47;
  short local_46;
  short local_44 [24];
  
  pfVar7 = param_2;
  this_00 = (dMap_c *)
            dMap_c::getCheckPointUseGrid
                      ((dMap_c *)(uint)(byte)this[0x27bc],(char)this[0x27bd],(char)param_2);
  cVar8 = (char)pfVar7;
  if (*(int *)(this + 0x10) == 0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_menu_fmap2.h",0x1dc,"fmapSv != 0");
    cVar8 = '!';
    m_Do_printf::OSPanic("d_menu_fmap2.h",0x1dc);
  }
  cVar2 = *(char *)(*(int *)(this + 0x10) + 0xb);
  if (*(int *)(this + 0x10) == 0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_menu_fmap2.h",0x1d2,"fmapSv != 0");
    cVar8 = '!';
    m_Do_printf::OSPanic("d_menu_fmap2.h",0x1d2);
  }
  pdVar5 = (dMap_c *)
           dMap_c::getCheckPointUseGrid
                     ((dMap_c *)(uint)*(byte *)(*(int *)(this + 0x10) + 10),cVar2,cVar8);
  if ((this_00 == (dMap_c *)&DAT_ffffffff) || (this_00 != pdVar5)) {
    uVar6 = 0;
  }
  else {
    dMap_c::getFmapChkPntPrm
              (this_00,(int)&local_47,&local_48,(char *)local_44,&local_46,(short *)0x0,in_r9);
    dVar1 = (double)CONCAT44(0x43300000,(int)local_46 ^ 0x80000000) - d_menu_fmap2::_4406;
    fVar3 = d_menu_fmap2::_6446 *
            (float)((double)CONCAT44(0x43300000,(int)local_48 ^ 0x80000000) - d_menu_fmap2::_4406);
    *param_1 = *(float *)(this + 0x27b0) -
               ((float)((double)CONCAT44(0x43300000,(int)local_44[0] ^ 0x80000000) -
                       d_menu_fmap2::_4406) +
               d_menu_fmap2::_6446 *
               (float)((double)CONCAT44(0x43300000,(int)local_47 ^ 0x80000000) - d_menu_fmap2::_4406
                      ));
    *param_2 = *(float *)(this + 0x27b4) - ((float)dVar1 + fVar3);
    if ((*param_1 < d_menu_fmap2::_6447) ||
       (((d_menu_fmap2::_6448 < *param_1 || (*param_2 < d_menu_fmap2::_6447)) ||
        (d_menu_fmap2::_6448 < *param_2)))) {
      uVar6 = 0;
    }
    else {
      uVar6 = 1;
    }
  }
  return uVar6;
}


/* __thiscall dMenu_Fmap2_c::changeCmapName(void) */

void __thiscall dMenu_Fmap2_c::changeCmapName(dMenu_Fmap2_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = getCmapDatPnt4(this,(int)(char)this[0x27a9]);
  iVar1 = (int)*(char *)(iVar1 + 2);
  if (iVar1 < 0x34) {
    if (iVar1 < 0x2a) {
      iVar2 = iVar1 + 0x31d7;
    }
    else {
      iVar2 = iVar1 + 0x36eb;
    }
  }
  else {
    iVar2 = iVar1 + 0x36eb;
  }
  if (iVar1 < 9) {
    iVar1 = *(int *)(this + ((byte)this[0x2814] ^ 1) * 0x38 + 0x1484);
    *(undefined *)(iVar1 + 0xf8) = 0xd6;
    *(undefined *)(iVar1 + 0xf9) = 0;
    *(undefined *)(iVar1 + 0xfa) = 0;
    *(undefined *)(iVar1 + 0xfb) = 0;
    *(undefined *)(iVar1 + 0xf4) = 0xf4;
    *(undefined *)(iVar1 + 0xf5) = 0x2f;
    *(undefined *)(iVar1 + 0xf6) = 0;
    *(undefined *)(iVar1 + 0xf7) = 0xff;
    iVar1 = *(int *)(this + ((byte)this[0x2814] ^ 1) * 0x38 + 0x14f4);
    *(undefined *)(iVar1 + 0xf8) = 0x65;
    *(undefined *)(iVar1 + 0xf9) = 0x10;
    *(undefined *)(iVar1 + 0xfa) = 0;
    *(undefined *)(iVar1 + 0xfb) = 0;
    *(undefined *)(iVar1 + 0xf4) = 0xab;
    *(undefined *)(iVar1 + 0xf5) = 0;
    *(undefined *)(iVar1 + 0xf6) = 0;
    *(undefined *)(iVar1 + 0xf7) = 0xff;
  }
  else {
    iVar1 = *(int *)(this + ((byte)this[0x2814] ^ 1) * 0x38 + 0x1484);
    *(undefined *)(iVar1 + 0xf8) = 0;
    *(undefined *)(iVar1 + 0xf9) = 0;
    *(undefined *)(iVar1 + 0xfa) = 0x4a;
    *(undefined *)(iVar1 + 0xfb) = 0;
    *(undefined *)(iVar1 + 0xf4) = 0;
    *(undefined *)(iVar1 + 0xf5) = 0;
    *(undefined *)(iVar1 + 0xf6) = 0xff;
    *(undefined *)(iVar1 + 0xf7) = 0xff;
    iVar1 = *(int *)(this + ((byte)this[0x2814] ^ 1) * 0x38 + 0x14f4);
    *(undefined *)(iVar1 + 0xf8) = 0;
    *(undefined *)(iVar1 + 0xf9) = 0;
    *(undefined *)(iVar1 + 0xfa) = 0;
    *(undefined *)(iVar1 + 0xfb) = 0;
    *(undefined *)(iVar1 + 0xf4) = 0;
    *(undefined *)(iVar1 + 0xf5) = 0;
    *(undefined *)(iVar1 + 0xf6) = 0;
    *(undefined *)(iVar1 + 0xf7) = 0xff;
  }
  f_op_msg_mng::fopMsgM_messageGet
            (*(undefined4 *)(this + ((byte)this[0x2814] ^ 1) * 4 + 0x27c8),iVar2);
  f_op_msg_mng::fopMsgM_messageGet
            (*(undefined4 *)(this + ((byte)this[0x2814] ^ 1) * 4 + 0x27d0),iVar2);
  return;
}


/* __thiscall dMenu_Fmap2_c::cmapPlayerPosDisp(void) */

void __thiscall dMenu_Fmap2_c::cmapPlayerPosDisp(dMenu_Fmap2_c *this)

{
  double dVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  float local_38;
  float local_34;
  longlong local_30;
  undefined4 local_28;
  uint uStack36;
  longlong local_20;
  undefined4 local_18;
  uint uStack20;
  
  iVar4 = cmapPlayerPosDispCheck(this,&local_34,&local_38);
  fVar3 = d_menu_fmap2::_6448;
  if (iVar4 == 1) {
    iVar4 = *(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4);
    fVar2 = *(float *)(iVar4 + 0xd0) * d_menu_fmap2::_4117;
    *(float *)(iVar4 + 0xf4) =
         *(float *)(iVar4 + 0xac) + *(float *)(iVar4 + 0xcc) * d_menu_fmap2::_4117 +
         local_34 * (*(float *)(iVar4 + 0xcc) / d_menu_fmap2::_6448);
    *(float *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0xf8) =
         *(float *)(iVar4 + 0xb0) + fVar2 +
         local_38 *
         (*(float *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0xd0) / fVar3);
    iVar4 = *(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4);
    *(undefined4 *)(iVar4 + 0xfc) = *(undefined4 *)(iVar4 + 0xf4);
    *(undefined4 *)(iVar4 + 0x100) = *(undefined4 *)(iVar4 + 0xf8);
    f_op_msg_mng::fopMsgM_cposMove
              ((fopMsgM_pane_class *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0xe0)
              );
    iVar4 = *(int *)(this + 0x27b8);
    iVar6 = *(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4);
    uStack36 = (uint)(d_menu_fmap2::_4117 * *(float *)(iVar6 + 0x108));
    local_30 = (longlong)(int)uStack36;
    uStack36 = uStack36 ^ 0x80000000;
    local_28 = 0x43300000;
    dVar1 = (double)CONCAT44(0x43300000,uStack36) - d_menu_fmap2::_4406;
    piVar5 = *(int **)(iVar6 + 0xe0);
    uStack20 = (uint)(d_menu_fmap2::_4117 * *(float *)(iVar6 + 0x104));
    local_20 = (longlong)(int)uStack20;
    uStack20 = uStack20 ^ 0x80000000;
    local_18 = 0x43300000;
    piVar5[0x27] = (int)(float)((double)CONCAT44(0x43300000,uStack20) - d_menu_fmap2::_4406);
    piVar5[0x28] = (int)(float)dVar1;
    *(undefined *)(piVar5 + 0x2a) = 0x7a;
    piVar5[0x29] = iVar4;
    (**(code **)(*piVar5 + 0x20))();
    *(undefined *)(*(int *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0xe0) + 0xaa) =
         1;
  }
  else {
    *(undefined *)(*(int *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0xe0) + 0xaa) =
         0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x801c4f58) */
/* WARNING: Removing unreachable block (ram,0x801c4f60) */
/* __thiscall dMenu_Fmap2_c::cmapSalvagePosDisp(void) */

void __thiscall dMenu_Fmap2_c::cmapSalvagePosDisp(dMenu_Fmap2_c *this)

{
  int iVar1;
  uint uVar2;
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
  uVar2 = (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo._89_1_;
  iVar1 = getCmapDatPnt4(this,(int)(char)this[0x27a9]);
  iVar1 = iVar1 + uVar2 * 8;
  iVar4 = 5;
  iVar3 = 0x118;
  dVar6 = (double)(d_menu_fmap2::_6592 *
                  (((float)((double)CONCAT44(0x43300000,(int)*(short *)(iVar1 + 10) ^ 0x80000000) -
                           d_menu_fmap2::_4406) -
                   (float)((double)CONCAT44(0x43300000,(int)*(short *)(iVar1 + 6) ^ 0x80000000) -
                          d_menu_fmap2::_4406)) / d_menu_fmap2::_6593));
  dVar7 = (double)(d_menu_fmap2::_6592 *
                  (((float)((double)CONCAT44(0x43300000,(int)*(short *)(iVar1 + 0xc) ^ 0x80000000) -
                           d_menu_fmap2::_4406) -
                   (float)((double)CONCAT44(0x43300000,(int)*(short *)(iVar1 + 8) ^ 0x80000000) -
                          d_menu_fmap2::_4406)) / d_menu_fmap2::_6593));
  do {
    *(float *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + iVar3 + 0x14) =
         (float)((double)*(float *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0xbc) +
                dVar6);
    *(float *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + iVar3 + 0x18) =
         (float)((double)*(float *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0xc0) +
                dVar7);
    iVar1 = *(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + iVar3;
    *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(iVar1 + 0x14);
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(iVar1 + 0x18);
    f_op_msg_mng::fopMsgM_cposMove
              ((fopMsgM_pane_class *)
               (*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + iVar3));
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar4 < 9);
  iVar1 = isCompleteCollectMap(this,(char)this[0x27a9]);
  if (iVar1 == 0) {
    *(undefined *)(*(int *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0x150) + 0xaa)
         = 1;
    *(undefined *)(*(int *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0x188) + 0xaa)
         = 0;
    *(undefined *)(*(int *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0x1c0) + 0xaa)
         = 0;
  }
  else {
    *(undefined *)(*(int *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0x150) + 0xaa)
         = 0;
    *(undefined *)(*(int *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0x188) + 0xaa)
         = 1;
    *(undefined *)(*(int *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0x1c0) + 0xaa)
         = 1;
  }
  *(undefined *)(*(int *)(*(int *)(this + ((byte)this[0x2815] ^ 1) * 4 + 0x1aa4) + 0x118) + 0xaa) =
       1;
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dMenu_Fmap2_c::cmapPlayerPosDispCheck(float *,
                                                    float *) */

undefined4 __thiscall
dMenu_Fmap2_c::cmapPlayerPosDispCheck(dMenu_Fmap2_c *this,float *param_1,float *param_2)

{
  char cVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  double dVar5;
  float fVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  float *pfVar10;
  char cVar11;
  uint uVar12;
  
  uVar12 = (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo._89_1_;
  pfVar10 = param_2;
  iVar7 = getCmapDatPnt4(this,(int)(char)this[0x27a9]);
  iVar9 = iVar7 + uVar12 * 8;
  sVar3 = *(short *)(iVar9 + 6);
  sVar4 = *(short *)(iVar9 + 8);
  cVar1 = *(char *)(iVar7 + 4);
  cVar2 = *(char *)(iVar7 + 5);
  cVar11 = (char)pfVar10;
  iVar7 = dMap_c::getCheckPointUseGrid((dMap_c *)(uint)(byte)this[0x27bc],(char)this[0x27bd],cVar11)
  ;
  iVar9 = dMap_c::getCheckPointUseGrid((dMap_c *)(int)cVar1,cVar2,cVar11);
  fVar6 = d_menu_fmap2::_6446;
  dVar5 = d_menu_fmap2::_4406;
  if ((iVar7 == -1) || (iVar7 != iVar9)) {
    uVar8 = 0;
  }
  else {
    *param_1 = *(float *)(this + 0x27b0) -
               ((float)((double)CONCAT44(0x43300000,(int)sVar3 ^ 0x80000000) - d_menu_fmap2::_4406)
               + d_menu_fmap2::_6446 *
                 (float)((double)CONCAT44(0x43300000,(uint)(dMap_c *)(int)cVar1 ^ 0x80000000) -
                        d_menu_fmap2::_4406));
    *param_2 = *(float *)(this + 0x27b4) -
               ((float)((double)CONCAT44(0x43300000,(int)sVar4 ^ 0x80000000) - dVar5) +
               fVar6 * (float)((double)CONCAT44(0x43300000,(int)cVar2 ^ 0x80000000) - dVar5));
    if ((*param_1 < d_menu_fmap2::_6627) ||
       (((d_menu_fmap2::_6628 < *param_1 || (*param_2 < d_menu_fmap2::_6627)) ||
        (d_menu_fmap2::_6628 < *param_2)))) {
      uVar8 = 0;
    }
    else {
      uVar8 = 1;
    }
  }
  return uVar8;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801c5328) */
/* WARNING: Removing unreachable block (ram,0x801c5320) */
/* WARNING: Removing unreachable block (ram,0x801c5330) */
/* __thiscall dMenu_Fmap2_c::paneTransBase(short,
                                           unsigned char,
                                           float,
                                           float,
                                           unsigned char,
                                           unsigned char,
                                           int) */

undefined4 __thiscall
dMenu_Fmap2_c::paneTransBase
          (dMenu_Fmap2_c *this,short param_1,uchar param_2,float param_3,float param_4,uchar param_5
          ,uchar param_6,int param_7)

{
  undefined4 uVar1;
  ulong uVar2;
  undefined3 in_register_00000018;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar9 = (double)param_4;
  dVar7 = (double)param_3;
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar8 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_5));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x4c),(double)d_menu_fmap2::_4118,
                 (double)(float)(dVar7 + (double)(float)(dVar8 * (double)(float)(dVar9 - dVar7))));
      if (param_7 != 2) {
        if (param_7 == 1) {
          dVar8 = (double)(float)((double)d_menu_fmap2::_4119 - dVar8);
        }
        if (this[0x27a8] != (dMenu_Fmap2_c)0x0) {
          if (*(int *)(this + 0x10) == 0) {
            uVar2 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar2,"d_menu_fmap2.h",0x1e8,"fmapSv != 0");
            m_Do_printf::OSPanic("d_menu_fmap2.h",0x1e8,&DAT_8035ff21);
          }
          if ((*(char *)(*(int *)(this + 0x10) + 9) != -1) &&
             (*(char *)(**(int **)(this + (uint)param_6 * 4 + 0x1aa4) + 0xaa) != '\0')) {
            iVar3 = 0;
            iVar5 = 0;
            iVar4 = (uint)param_6 * 4 + 0x1aa4;
            do {
              f_op_msg_mng::fopMsgM_setNowAlpha
                        ((fopMsgM_pane_class *)(*(int *)(this + iVar4) + iVar5),(float)dVar8);
              f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(*(int *)(this + iVar4) + iVar5))
              ;
              iVar3 = iVar3 + 1;
              iVar5 = iVar5 + 0x38;
            } while (iVar3 < 10);
          }
        }
        iVar3 = 0;
        iVar4 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)
                     (*(int *)(this + (uint)(byte)this[0x2813] * 4 + 0x124c) + iVar4),(float)dVar8);
          f_op_msg_mng::fopMsgM_setAlpha
                    ((fopMsgM_pane_class *)
                     (*(int *)(this + (uint)(byte)this[0x2813] * 4 + 0x124c) + iVar4));
          iVar3 = iVar3 + 1;
          iVar4 = iVar4 + 0x38;
        } while (iVar3 < 5);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1334),(float)dVar8);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1254),(float)dVar8);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1334));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1254));
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x12fc),(float)dVar8);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x128c),(float)dVar8);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x12fc));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x128c));
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x404),(float)dVar8);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x404));
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x4c),(float)dVar8);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x4c));
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  __psq_l0(auStack40,uVar6);
  __psq_l1(auStack40,uVar6);
  return uVar1;
}


/* __thiscall dMenu_Fmap2_c::paneAlphaFmapBase(short,
                                               unsigned char,
                                               unsigned char,
                                               int) */

undefined4 __thiscall
dMenu_Fmap2_c::paneAlphaFmapBase
          (dMenu_Fmap2_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  double dVar2;
  
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_3));
      if (param_4 != 2) {
        if (param_4 == 1) {
          dVar2 = (double)(float)((double)d_menu_fmap2::_4119 - dVar2);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1254),(float)dVar2);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1254));
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


/* WARNING: Removing unreachable block (ram,0x801c54a0) */
/* __thiscall dMenu_Fmap2_c::paneAlphaCmapBase(short,
                                               unsigned char,
                                               unsigned char,
                                               int) */

undefined4 __thiscall
dMenu_Fmap2_c::paneAlphaCmapBase
          (dMenu_Fmap2_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_3));
      if (param_4 != 2) {
        if (param_4 == 1) {
          dVar3 = (double)(float)((double)d_menu_fmap2::_4119 - dVar3);
        }
        this[0xf31] = SUB41((int)(d_menu_fmap2::_6703 +
                                 d_menu_fmap2::_6704 * (float)((double)d_menu_fmap2::_4119 - dVar3))
                            ,0);
        this[0xf30] = this[0xf31];
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xefc));
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x128c),(float)dVar3);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x128c));
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801c55b0) */
/* WARNING: Removing unreachable block (ram,0x801c55a8) */
/* WARNING: Removing unreachable block (ram,0x801c55b8) */
/* __thiscall dMenu_Fmap2_c::paneAlphaZoomCmapBase(short,
                                                   unsigned char,
                                                   float,
                                                   float,
                                                   unsigned char,
                                                   unsigned char,
                                                   int) */

undefined4 __thiscall
dMenu_Fmap2_c::paneAlphaZoomCmapBase
          (dMenu_Fmap2_c *this,short param_1,uchar param_2,float param_3,float param_4,uchar param_5
          ,uchar param_6,int param_7)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar8 = (double)param_4;
  dVar6 = (double)param_3;
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar7 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_5));
      f_op_msg_mng::fopMsgM_paneTrans
                (*(fopMsgM_pane_class **)(this + (uint)param_6 * 4 + 0x1aa4),
                 (double)(float)(dVar6 + (double)(float)(dVar7 * (double)(float)(dVar8 - dVar6))),
                 (double)d_menu_fmap2::_4118);
      if (param_7 != 2) {
        if (param_7 == 1) {
          dVar7 = (double)(float)((double)d_menu_fmap2::_4119 - dVar7);
        }
        iVar2 = 0;
        iVar4 = 0;
        iVar3 = (uint)param_6 * 4 + 0x1aa4;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(*(int *)(this + iVar3) + iVar4),(float)dVar7);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(*(int *)(this + iVar3) + iVar4));
          iVar2 = iVar2 + 1;
          iVar4 = iVar4 + 0x38;
        } while (iVar2 < 10);
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  return uVar1;
}


/* WARNING: Removing unreachable block (ram,0x801c570c) */
/* WARNING: Removing unreachable block (ram,0x801c5714) */
/* __thiscall dMenu_Fmap2_c::paneAlphaCmapName(short,
                                               unsigned char,
                                               unsigned char) */

undefined4 __thiscall
dMenu_Fmap2_c::paneAlphaCmapName(dMenu_Fmap2_c *this,short param_1,uchar param_2,uchar param_3)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f30;
  double dVar4;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_3));
      dVar4 = (double)(float)((double)d_menu_fmap2::_4119 - dVar3);
      f_op_msg_mng::fopMsgM_setNowAlpha
                ((fopMsgM_pane_class *)(this + (uint)(byte)this[0x2814] * 0x38 + 0x1484),
                 (float)((double)d_menu_fmap2::_4119 - dVar3));
      f_op_msg_mng::fopMsgM_setNowAlpha
                ((fopMsgM_pane_class *)(this + ((byte)this[0x2814] + 2) * 0x38 + 0x1484),
                 (float)dVar4);
      f_op_msg_mng::fopMsgM_setAlpha
                ((fopMsgM_pane_class *)(this + (uint)(byte)this[0x2814] * 0x38 + 0x1484));
      f_op_msg_mng::fopMsgM_setAlpha
                ((fopMsgM_pane_class *)(this + ((byte)this[0x2814] + 2) * 0x38 + 0x1484));
      f_op_msg_mng::fopMsgM_setNowAlpha
                ((fopMsgM_pane_class *)(this + ((byte)this[0x2814] ^ 1) * 0x38 + 0x1484),
                 (float)dVar3);
      f_op_msg_mng::fopMsgM_setNowAlpha
                ((fopMsgM_pane_class *)(this + (((byte)this[0x2814] ^ 1) + 2) * 0x38 + 0x1484),
                 (float)dVar3);
      f_op_msg_mng::fopMsgM_setAlpha
                ((fopMsgM_pane_class *)(this + ((byte)this[0x2814] ^ 1) * 0x38 + 0x1484));
      f_op_msg_mng::fopMsgM_setAlpha
                ((fopMsgM_pane_class *)(this + (((byte)this[0x2814] ^ 1) + 2) * 0x38 + 0x1484));
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  return uVar1;
}


/* __thiscall dMenu_Fmap2_c::paneAlphaMessage2(short,
                                               unsigned char,
                                               unsigned char,
                                               int) */

undefined4 __thiscall
dMenu_Fmap2_c::paneAlphaMessage2
          (dMenu_Fmap2_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  double dVar2;
  
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_3));
      if (param_4 != 2) {
        if (param_4 == 1) {
          dVar2 = (double)(float)((double)d_menu_fmap2::_4119 - dVar2);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x43c),(float)dVar2);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x43c));
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x801c5ac4) */
/* WARNING: Removing unreachable block (ram,0x801c5ab4) */
/* WARNING: Removing unreachable block (ram,0x801c5aac) */
/* WARNING: Removing unreachable block (ram,0x801c5abc) */
/* WARNING: Removing unreachable block (ram,0x801c5acc) */
/* __thiscall dMenu_Fmap2_c::paneTranceMessage(short,
                                               unsigned char,
                                               float,
                                               float,
                                               float,
                                               float,
                                               unsigned char,
                                               unsigned char,
                                               int) */

undefined4 __thiscall
dMenu_Fmap2_c::paneTranceMessage
          (dMenu_Fmap2_c *this,short param_1,uchar param_2,float param_3,float param_4,float param_5
          ,float param_6,uchar param_7,uchar param_8,int param_9)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined4 uVar8;
  undefined3 in_register_00000018;
  int iVar9;
  int iVar10;
  int iVar11;
  dMenu_Fmap2_c *pdVar12;
  undefined4 uVar13;
  double dVar14;
  double dVar15;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar16;
  double dVar17;
  undefined8 in_f30;
  double dVar18;
  undefined8 in_f31;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar17 = (double)param_5;
  dVar18 = (double)param_6;
  dVar16 = (double)param_4;
  dVar14 = (double)param_3;
  uVar13 = 0;
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
  if (param_1 < 0) {
    uVar8 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar8 = 1;
    }
    else {
      dVar15 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                 ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_7))
      ;
      dVar16 = (double)(float)(dVar15 * (double)(float)(dVar16 - dVar14));
      pdVar12 = this + (uint)param_8 * 4;
      dVar18 = (double)(float)(dVar17 + (double)(float)(dVar15 * (double)(float)(dVar18 - dVar17)));
      f_op_msg_mng::fopMsgM_paneTrans
                (*(fopMsgM_pane_class **)(pdVar12 + 0xcc4),dVar18,(double)d_menu_fmap2::_4118);
      dVar17 = (double)(float)(dVar14 + dVar16);
      f_op_msg_mng::fopMsgM_paneScaleXY
                (*(fopMsgM_pane_class **)(pdVar12 + 0xcc4),(float)(dVar14 + dVar16));
      iVar9 = 1;
      iVar11 = 0x38;
      iVar10 = (uint)param_8 * 4 + 0xcc4;
      do {
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(*(int *)(this + iVar10) + iVar11),dVar18,
                   (double)d_menu_fmap2::_4118);
        paneScaleXYChild(this,(fopMsgM_pane_class *)(*(int *)(this + iVar10) + iVar11),(float)dVar17
                        );
        iVar9 = iVar9 + 1;
        iVar11 = iVar11 + 0x38;
      } while (iVar9 < 0xf);
      fVar1 = (float)((double)*(float *)(this + 0x2830) * dVar17);
      fVar2 = (float)((double)*(float *)(this + 0x2834) * dVar17);
      fVar3 = (float)((double)*(float *)(this + 0x2838) * dVar17);
      fVar4 = (float)((double)*(float *)(this + 0x283c) * dVar17);
      fVar5 = *(float *)(this + 0x2840);
      fVar6 = *(float *)(this + 0x2844);
      iVar9 = *(int *)(*(int *)(pdVar12 + 0xcc4) + 0x38);
      fVar7 = d_menu_fmap2::_4118;
      if (d_menu_fmap2::_4118 < fVar1) {
        fVar7 = fVar1;
      }
      *(float *)(iVar9 + 0xe8) = fVar7;
      fVar7 = d_menu_fmap2::_4118;
      if (d_menu_fmap2::_4118 < fVar2) {
        fVar7 = fVar2;
      }
      *(float *)(iVar9 + 0xec) = fVar7;
      *(float *)(*(int *)(*(int *)(pdVar12 + 0xcc4) + 0x38) + 0xe4) =
           (float)((double)fVar5 * dVar17);
      iVar9 = *(int *)(*(int *)(pdVar12 + 0xcc4) + 0x70);
      fVar7 = d_menu_fmap2::_4118;
      if (d_menu_fmap2::_4118 < fVar1) {
        fVar7 = fVar1;
      }
      *(float *)(iVar9 + 0xe8) = fVar7;
      fVar1 = d_menu_fmap2::_4118;
      if (d_menu_fmap2::_4118 < fVar2) {
        fVar1 = fVar2;
      }
      *(float *)(iVar9 + 0xec) = fVar1;
      *(float *)(*(int *)(*(int *)(pdVar12 + 0xcc4) + 0x70) + 0xe4) =
           (float)((double)fVar5 * dVar17);
      iVar9 = *(int *)(*(int *)(pdVar12 + 0xcc4) + 0xa8);
      fVar1 = d_menu_fmap2::_4118;
      if (d_menu_fmap2::_4118 < fVar3) {
        fVar1 = fVar3;
      }
      *(float *)(iVar9 + 0xe8) = fVar1;
      fVar1 = d_menu_fmap2::_4118;
      if (d_menu_fmap2::_4118 < fVar4) {
        fVar1 = fVar4;
      }
      *(float *)(iVar9 + 0xec) = fVar1;
      *(float *)(*(int *)(*(int *)(pdVar12 + 0xcc4) + 0xa8) + 0xe4) =
           (float)((double)fVar6 * dVar17);
      iVar9 = *(int *)(*(int *)(pdVar12 + 0xcc4) + 0xe0);
      fVar1 = d_menu_fmap2::_4118;
      if (d_menu_fmap2::_4118 < fVar3) {
        fVar1 = fVar3;
      }
      *(float *)(iVar9 + 0xe8) = fVar1;
      fVar1 = d_menu_fmap2::_4118;
      if (d_menu_fmap2::_4118 < fVar4) {
        fVar1 = fVar4;
      }
      *(float *)(iVar9 + 0xec) = fVar1;
      *(float *)(*(int *)(*(int *)(pdVar12 + 0xcc4) + 0xe0) + 0xe4) =
           (float)((double)fVar6 * dVar17);
      if (param_9 != 2) {
        if (param_9 == 1) {
          dVar15 = (double)(float)((double)d_menu_fmap2::_4119 - dVar15);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha(*(fopMsgM_pane_class **)(pdVar12 + 0xcc4),(float)dVar15);
        f_op_msg_mng::fopMsgM_setAlpha(*(fopMsgM_pane_class **)(pdVar12 + 0xcc4));
      }
      uVar8 = 0;
    }
  }
  __psq_l0(auStack8,uVar13);
  __psq_l1(auStack8,uVar13);
  __psq_l0(auStack24,uVar13);
  __psq_l1(auStack24,uVar13);
  __psq_l0(auStack40,uVar13);
  __psq_l1(auStack40,uVar13);
  __psq_l0(auStack56,uVar13);
  __psq_l1(auStack56,uVar13);
  __psq_l0(auStack72,uVar13);
  __psq_l1(auStack72,uVar13);
  return uVar8;
}


/* __thiscall dMenu_Fmap2_c::paneScaleXYChild(fopMsgM_pane_class *,
                                              float) */

void __thiscall
dMenu_Fmap2_c::paneScaleXYChild(dMenu_Fmap2_c *this,fopMsgM_pane_class *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  J2DScreen *pJVar3;
  
  (param_1->mSize).x = (param_1->mSizeOrig).x * param_2;
  (param_1->mSize).y = (param_1->mSizeOrig).y * param_2;
  (param_1->mPosTopLeft).x = (param_1->mPosTopLeftOrig).x * param_2;
  (param_1->mPosTopLeft).y = (param_1->mPosTopLeftOrig).y * param_2;
  fVar1 = d_menu_fmap2::_4117;
  (param_1->mPosCenter).x = (param_1->mPosTopLeft).x + (param_1->mSize).x * d_menu_fmap2::_4117;
  (param_1->mPosCenter).y = (param_1->mPosTopLeft).y + (param_1->mSize).y * fVar1;
  (*(code *)((param_1->mpPane->parent).vtbl)->resize)
            ((double)(param_1->mSize).x,(double)(param_1->mSize).y);
  (*(code *)((param_1->mpPane->parent).vtbl)->move)
            ((double)(param_1->mPosTopLeft).x,(double)(param_1->mPosTopLeft).y);
  pJVar3 = param_1->mpPane;
  fVar1 = (pJVar3->parent).mRotation;
  if (d_menu_fmap2::_4118 != fVar1) {
    fVar2 = d_menu_fmap2::_4117 * (param_1->mSize).y;
    (pJVar3->parent).mBasePosition.x = d_menu_fmap2::_4117 * (param_1->mSize).x;
    (pJVar3->parent).mBasePosition.y = fVar2;
    (pJVar3->parent).mRotationAxis = 'z';
    (pJVar3->parent).mRotation = fVar1;
    (*(code *)((pJVar3->parent).vtbl)->calcMtx)();
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801c5d44) */
/* WARNING: Removing unreachable block (ram,0x801c5d34) */
/* WARNING: Removing unreachable block (ram,0x801c5d2c) */
/* WARNING: Removing unreachable block (ram,0x801c5d3c) */
/* WARNING: Removing unreachable block (ram,0x801c5d4c) */
/* __thiscall dMenu_Fmap2_c::paneTransSelCmapCle(short,
                                                 unsigned char,
                                                 float,
                                                 float,
                                                 float,
                                                 float,
                                                 unsigned char,
                                                 unsigned char,
                                                 int) */

undefined4 __thiscall
dMenu_Fmap2_c::paneTransSelCmapCle
          (dMenu_Fmap2_c *this,short param_1,uchar param_2,float param_3,float param_4,float param_5
          ,float param_6,uchar param_7,uchar param_8,int param_9)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar7 = (double)param_5;
  dVar8 = (double)param_6;
  dVar10 = (double)param_4;
  dVar9 = (double)param_3;
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
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_7));
      iVar2 = 0;
      iVar4 = 0;
      dVar10 = (double)(float)(dVar9 + (double)(float)(dVar6 * (double)(float)(dVar10 - dVar9)));
      iVar3 = (uint)param_8 * 4 + 0x1244;
      dVar9 = (double)(float)(dVar7 + (double)(float)(dVar6 * (double)(float)(dVar8 - dVar7)));
      do {
        f_op_msg_mng::fopMsgM_paneScaleXY
                  ((fopMsgM_pane_class *)(*(int *)(this + iVar3) + iVar4),(float)dVar10);
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(*(int *)(this + iVar3) + iVar4),dVar9,
                   (double)d_menu_fmap2::_4118);
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 0x38;
      } while (iVar2 < 2);
      if (param_9 != 2) {
        if (param_9 == 1) {
          dVar6 = (double)(float)((double)d_menu_fmap2::_4119 - dVar6);
        }
        iVar2 = 0;
        iVar4 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(*(int *)(this + iVar3) + iVar4),(float)dVar6);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(*(int *)(this + iVar3) + iVar4));
          iVar2 = iVar2 + 1;
          iVar4 = iVar4 + 0x38;
        } while (iVar2 < 2);
      }
      uVar1 = 0;
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
  __psq_l0(auStack72,uVar5);
  __psq_l1(auStack72,uVar5);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801c5ebc) */
/* WARNING: Removing unreachable block (ram,0x801c5eac) */
/* WARNING: Removing unreachable block (ram,0x801c5ea4) */
/* WARNING: Removing unreachable block (ram,0x801c5eb4) */
/* WARNING: Removing unreachable block (ram,0x801c5ec4) */
/* __thiscall dMenu_Fmap2_c::paneTransSelCmapOpn(short,
                                                 unsigned char,
                                                 float,
                                                 float,
                                                 float,
                                                 float,
                                                 unsigned char,
                                                 unsigned char,
                                                 int) */

undefined4 __thiscall
dMenu_Fmap2_c::paneTransSelCmapOpn
          (dMenu_Fmap2_c *this,short param_1,uchar param_2,float param_3,float param_4,float param_5
          ,float param_6,uchar param_7,uchar param_8,int param_9)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar7 = (double)param_5;
  dVar8 = (double)param_6;
  dVar10 = (double)param_4;
  dVar9 = (double)param_3;
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
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_7));
      iVar2 = 0;
      iVar4 = 0;
      dVar10 = (double)(float)(dVar9 + (double)(float)(dVar6 * (double)(float)(dVar10 - dVar9)));
      iVar3 = (uint)param_8 * 4 + 0x124c;
      dVar9 = (double)(float)(dVar7 + (double)(float)(dVar6 * (double)(float)(dVar8 - dVar7)));
      do {
        f_op_msg_mng::fopMsgM_paneScaleXY
                  ((fopMsgM_pane_class *)(*(int *)(this + iVar3) + iVar4),(float)dVar10);
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(*(int *)(this + iVar3) + iVar4),dVar9,
                   (double)d_menu_fmap2::_4118);
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 0x38;
      } while (iVar2 < 5);
      if (param_9 != 2) {
        if (param_9 == 1) {
          dVar6 = (double)(float)((double)d_menu_fmap2::_4119 - dVar6);
        }
        iVar2 = 0;
        iVar4 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(*(int *)(this + iVar3) + iVar4),(float)dVar6);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(*(int *)(this + iVar3) + iVar4));
          iVar2 = iVar2 + 1;
          iVar4 = iVar4 + 0x38;
        } while (iVar2 < 5);
      }
      uVar1 = 0;
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
  __psq_l0(auStack72,uVar5);
  __psq_l1(auStack72,uVar5);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801c607c) */
/* __thiscall dMenu_Fmap2_c::paneAlphaGostShipMap(short,
                                                  unsigned char,
                                                  unsigned char,
                                                  int) */

undefined4 __thiscall
dMenu_Fmap2_c::paneAlphaGostShipMap
          (dMenu_Fmap2_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  dMenu_Fmap2_c *pdVar3;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_3));
      if (param_4 != 2) {
        if (param_4 == 1) {
          dVar6 = (double)(float)((double)d_menu_fmap2::_4119 - dVar6);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar6,this + 0x1aac);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar6,this + 0x1ab4);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar6,this + 0x1abc);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar6,this + 0x1ac4);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar6,this + 0x1acc);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar6,this + 0x1ad4);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar6,this + 0x1b14);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar6,this + 0x1b1c);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar6,this + 0x1b24);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar6,this + 0x1b2c);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1aac);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1ab4);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1abc);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1ac4);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1acc);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1ad4);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1b14);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1b1c);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1b24);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1b2c);
        iVar2 = 0;
        iVar4 = 0;
        do {
          pdVar3 = this + iVar4;
          f_op_msg_mng::fopMsgM_setNowAlpha(dVar6,pdVar3 + 0x1adc);
          f_op_msg_mng::fopMsgM_setAlpha(pdVar3 + 0x1adc);
          if (*(char *)(*(int *)(pdVar3 + 0x1b3c) + 0xaa) != '\0') {
            f_op_msg_mng::fopMsgM_setNowAlpha(dVar6,pdVar3 + 0x1b3c);
            f_op_msg_mng::fopMsgM_setAlpha(pdVar3 + 0x1b3c);
          }
          iVar2 = iVar2 + 1;
          iVar4 = iVar4 + 8;
        } while (iVar2 < 7);
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801c61d0) */
/* __thiscall dMenu_Fmap2_c::paneAlphaTingleMap(short,
                                                unsigned char,
                                                unsigned char,
                                                int) */

undefined4 __thiscall
dMenu_Fmap2_c::paneAlphaTingleMap
          (dMenu_Fmap2_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_3));
      if (param_4 != 2) {
        if (param_4 == 1) {
          dVar5 = (double)(float)((double)d_menu_fmap2::_4119 - dVar5);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x1b74);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x1b7c);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x1b84);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x1b8c);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1b74);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1b7c);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1b84);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1b8c);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1b94),(float)dVar5);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1b94));
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1c7c),(float)dVar5);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1c7c));
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1cb4),(float)dVar5);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1cb4));
        iVar2 = 0;
        iVar3 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + iVar3 + 0x1bcc);
          f_op_msg_mng::fopMsgM_setAlpha(this + iVar3 + 0x1bcc);
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 8;
        } while (iVar2 < 0x16);
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return uVar1;
}


/* WARNING: Removing unreachable block (ram,0x801c6318) */
/* __thiscall dMenu_Fmap2_c::paneAlphaTreasureMap(short,
                                                  unsigned char,
                                                  unsigned char,
                                                  int) */

undefined4 __thiscall
dMenu_Fmap2_c::paneAlphaTreasureMap
          (dMenu_Fmap2_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_3));
      if (param_4 != 2) {
        if (param_4 == 1) {
          dVar3 = (double)(float)((double)d_menu_fmap2::_4119 - dVar3);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x1cec);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x1cf4);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x1cfc);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x1d04);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x1d0c);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1d14),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x1d4c);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1d54),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1d8c),(float)dVar3);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1cec);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1cf4);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1cfc);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1d04);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1d0c);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1d14));
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1d4c);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1d54));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1d8c));
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801c6480) */
/* __thiscall dMenu_Fmap2_c::paneAlphaSubdanMap(short,
                                                unsigned char,
                                                unsigned char,
                                                int) */

undefined4 __thiscall
dMenu_Fmap2_c::paneAlphaSubdanMap
          (dMenu_Fmap2_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_3));
      if (param_4 != 2) {
        if (param_4 == 1) {
          dVar5 = (double)(float)((double)d_menu_fmap2::_4119 - dVar5);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x26bc);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x26c4);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x26d4);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x26dc),(float)dVar5);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x2714);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x26cc);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x272c),(float)dVar5);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2764),(float)dVar5);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x26bc);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x26c4);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x26d4);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x26dc));
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x2714);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x26cc);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x272c));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x2764));
        iVar2 = 0;
        iVar3 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + iVar3 + 0x271c);
          f_op_msg_mng::fopMsgM_setAlpha(this + iVar3 + 0x271c);
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 8;
        } while (iVar2 < 2);
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801c661c) */
/* __thiscall dMenu_Fmap2_c::paneAlphaHeartMMap(short,
                                                unsigned char,
                                                unsigned char,
                                                int) */

undefined4 __thiscall
dMenu_Fmap2_c::paneAlphaHeartMMap
          (dMenu_Fmap2_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_3));
      if (param_4 != 2) {
        if (param_4 == 1) {
          dVar5 = (double)(float)((double)d_menu_fmap2::_4119 - dVar5);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x256c);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x2574);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x2584);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x258c),(float)dVar5);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x25c4);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x257c);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x264c),(float)dVar5);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2684),(float)dVar5);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x256c);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x2574);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x2584);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x258c));
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x25c4);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x257c);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x264c));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x2684));
        iVar2 = 0;
        iVar3 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + iVar3 + 0x25cc);
          f_op_msg_mng::fopMsgM_setAlpha(this + iVar3 + 0x25cc);
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 8;
        } while (iVar2 < 7);
        iVar2 = 0;
        iVar3 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + iVar3 + 0x2604);
          f_op_msg_mng::fopMsgM_setAlpha(this + iVar3 + 0x2604);
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 8;
        } while (iVar2 < 9);
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801c6770) */
/* __thiscall dMenu_Fmap2_c::paneAlphaYaguraMap(short,
                                                unsigned char,
                                                unsigned char,
                                                int) */

undefined4 __thiscall
dMenu_Fmap2_c::paneAlphaYaguraMap
          (dMenu_Fmap2_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_3));
      if (param_4 != 2) {
        if (param_4 == 1) {
          dVar5 = (double)(float)((double)d_menu_fmap2::_4119 - dVar5);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x2494);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x249c);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x24ac);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x24b4),(float)dVar5);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x24a4);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x24fc),(float)dVar5);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2534),(float)dVar5);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x2494);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x249c);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x24ac);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x24b4));
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x24a4);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x24fc));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x2534));
        iVar2 = 0;
        iVar3 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + iVar3 + 0x24ec);
          f_op_msg_mng::fopMsgM_setAlpha(this + iVar3 + 0x24ec);
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 8;
        } while (iVar2 < 2);
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return uVar1;
}


/* WARNING: Removing unreachable block (ram,0x801c6890) */
/* __thiscall dMenu_Fmap2_c::paneAlphaDfaliyMap(short,
                                                unsigned char,
                                                unsigned char,
                                                int) */

undefined4 __thiscall
dMenu_Fmap2_c::paneAlphaDfaliyMap
          (dMenu_Fmap2_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_3));
      if (param_4 != 2) {
        if (param_4 == 1) {
          dVar3 = (double)(float)((double)d_menu_fmap2::_4119 - dVar3);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x23cc);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x23d4);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x23e4);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x23ec),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x23dc);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2424),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x245c),(float)dVar3);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x23cc);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x23d4);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x23e4);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x23ec));
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x23dc);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x2424));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x245c));
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return uVar1;
}


/* WARNING: Removing unreachable block (ram,0x801c6a14) */
/* __thiscall dMenu_Fmap2_c::paneAlphaHeartPMap(short,
                                                unsigned char,
                                                unsigned char,
                                                int) */

undefined4 __thiscall
dMenu_Fmap2_c::paneAlphaHeartPMap
          (dMenu_Fmap2_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_3));
      if (param_4 != 2) {
        if (param_4 == 1) {
          dVar3 = (double)(float)((double)d_menu_fmap2::_4119 - dVar3);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x1f54);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x1f5c);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x1f6c);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x1f64);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1f74),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x1fac);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x1fb4);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x1fbc);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x1fc4);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x1fcc);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1fd4),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x200c),(float)dVar3);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1f54);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1f5c);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1f6c);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1f64);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1f74));
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1fac);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1fb4);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1fbc);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1fc4);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1fcc);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1fd4));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x200c));
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return uVar1;
}


/* WARNING: Removing unreachable block (ram,0x801c6b34) */
/* __thiscall dMenu_Fmap2_c::paneAlphaTerryMap(short,
                                               unsigned char,
                                               unsigned char,
                                               int) */

undefined4 __thiscall
dMenu_Fmap2_c::paneAlphaTerryMap
          (dMenu_Fmap2_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_3));
      if (param_4 != 2) {
        if (param_4 == 1) {
          dVar3 = (double)(float)((double)d_menu_fmap2::_4119 - dVar3);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x2044);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x204c);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x205c);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2064),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x2054);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x209c),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x20d4),(float)dVar3);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x2044);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x204c);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x205c);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x2064));
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x2054);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x209c));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x20d4));
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return uVar1;
}


/* WARNING: Removing unreachable block (ram,0x801c6c54) */
/* __thiscall dMenu_Fmap2_c::paneAlphaSubMaMap(short,
                                               unsigned char,
                                               unsigned char,
                                               int) */

undefined4 __thiscall
dMenu_Fmap2_c::paneAlphaSubMaMap
          (dMenu_Fmap2_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_3));
      if (param_4 != 2) {
        if (param_4 == 1) {
          dVar3 = (double)(float)((double)d_menu_fmap2::_4119 - dVar3);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x210c);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x2114);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x2124);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x212c),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x211c);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2164),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x219c),(float)dVar3);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x210c);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x2114);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x2124);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x212c));
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x211c);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x2164));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x219c));
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801c6da8) */
/* __thiscall dMenu_Fmap2_c::paneAlphaMoonMap(short,
                                              unsigned char,
                                              unsigned char,
                                              int) */

undefined4 __thiscall
dMenu_Fmap2_c::paneAlphaMoonMap
          (dMenu_Fmap2_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_3));
      if (param_4 != 2) {
        if (param_4 == 1) {
          dVar5 = (double)(float)((double)d_menu_fmap2::_4119 - dVar5);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x21d4);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x21dc);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x21ec);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x21f4),(float)dVar5);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + 0x21e4);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x235c),(float)dVar5);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2394),(float)dVar5);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x21d4);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x21dc);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x21ec);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x21f4));
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x21e4);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x235c));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x2394));
        iVar2 = 0;
        iVar3 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha(dVar5,this + iVar3 + 0x222c);
          f_op_msg_mng::fopMsgM_setAlpha(this + iVar3 + 0x222c);
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 8;
        } while (iVar2 < 0x26);
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return uVar1;
}


/* WARNING: Removing unreachable block (ram,0x801c6edc) */
/* __thiscall dMenu_Fmap2_c::paneAlphaDoctaMap(short,
                                               unsigned char,
                                               unsigned char,
                                               int) */

undefined4 __thiscall
dMenu_Fmap2_c::paneAlphaDoctaMap
          (dMenu_Fmap2_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_3));
      if (param_4 != 2) {
        if (param_4 == 1) {
          dVar3 = (double)(float)((double)d_menu_fmap2::_4119 - dVar3);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x1e84);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x1e8c);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x1e9c);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1ea4),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x1edc);
        f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0x1e94);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1ee4),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1f1c),(float)dVar3);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1e84);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1e8c);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1e9c);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1ea4));
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1edc);
        f_op_msg_mng::fopMsgM_setAlpha(this + 0x1e94);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1ee4));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1f1c));
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return uVar1;
}


/* __thiscall dMenu_Fmap2_c::setPaneOnOff(J2DScreen *,
                                          unsigned long,
                                          bool) */

void __thiscall
dMenu_Fmap2_c::setPaneOnOff(dMenu_Fmap2_c *this,J2DScreen *param_1,ulong param_2,bool param_3)

{
  int iVar1;
  
  iVar1 = (*(code *)((param_1->parent).vtbl)->search)(param_1,param_2);
  if (iVar1 != 0) {
    if (param_3 == false) {
      *(undefined *)(iVar1 + 0xaa) = 0;
    }
    else {
      *(undefined *)(iVar1 + 0xaa) = 1;
    }
  }
  return;
}


/* __thiscall dMenu_Fmap2_c::getCollectMapTexChange(void) */

void __thiscall dMenu_Fmap2_c::getCollectMapTexChange(dMenu_Fmap2_c *this)

{
  int iVar1;
  char acStack24 [16];
  
  iVar1 = calcGetCollectMap2(this);
  MSL_C.PPCEABI.bare.H::sprintf(acStack24,"rupy_num_%02d.bti",iVar1 % 10);
  J2DPicture::changeTexture(*(J2DPicture **)(this + 0xccc),acStack24,0);
  MSL_C.PPCEABI.bare.H::sprintf(acStack24,"rupy_num_%02d.bti",iVar1 / 10);
  J2DPicture::changeTexture(*(J2DPicture **)(this + 0xd04),acStack24,0);
  return;
}


/* __thiscall dMenu_Fmap2_c::finCollectMapTexChange(void) */

void __thiscall dMenu_Fmap2_c::finCollectMapTexChange(dMenu_Fmap2_c *this)

{
  int iVar1;
  char acStack24 [16];
  
  iVar1 = calcFinCollectMap(this);
  MSL_C.PPCEABI.bare.H::sprintf(acStack24,"rupy_num_%02d.bti",iVar1 % 10);
  J2DPicture::changeTexture(*(J2DPicture **)(this + 0xd3c),acStack24,0);
  MSL_C.PPCEABI.bare.H::sprintf(acStack24,"rupy_num_%02d.bti",iVar1 / 10);
  J2DPicture::changeTexture(*(J2DPicture **)(this + 0xd74),acStack24,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMenu_Fmap2_c::calcGetCollectMap(void) */

int __thiscall dMenu_Fmap2_c::calcGetCollectMap(dMenu_Fmap2_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = 0;
  do {
    iVar1 = getCmapDatPnt4(this,iVar4);
    iVar2 = (int)*(char *)(iVar1 + 1);
    iVar1 = isGetCollectMap(this,*(char *)(iVar1 + 1));
    if (iVar1 == 0) {
      iVar1 = dSv_player_map_c::isOpenMap
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,iVar2 + -1);
      if (iVar1 != 0) {
        dSv_player_map_c::offOpenMap
                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,iVar2 + -1);
      }
      iVar1 = dSv_player_map_c::isCompleteMap
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,iVar2 + -1);
      if (iVar1 != 0) {
        dSv_player_map_c::offCompleteMap
                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,iVar2 + -1);
      }
    }
    else {
      iVar3 = iVar3 + 1;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x3d);
  return iVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Fmap2_c::calcGetCollectMap2(void) */

int __thiscall dMenu_Fmap2_c::calcGetCollectMap2(dMenu_Fmap2_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  do {
    iVar1 = getCmapDatPnt4(this,iVar3);
    iVar1 = isGetCollectMap(this,*(char *)(iVar1 + 1));
    if (iVar1 != 0) {
      iVar2 = iVar2 + 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x31);
  return iVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Fmap2_c::calcFinCollectMap(void) */

int __thiscall dMenu_Fmap2_c::calcFinCollectMap(dMenu_Fmap2_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  do {
    if (((iVar3 != 0x22) && (iVar3 != 0x23)) &&
       (iVar1 = dSv_player_map_c::isCompleteMap
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,iVar3),
       iVar1 != 0)) {
      iVar2 = iVar2 + 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x34);
  return iVar2;
}


/* __thiscall dMenu_Fmap2_c::getNowCmapFirstNum(void) */

int __thiscall dMenu_Fmap2_c::getNowCmapFirstNum(dMenu_Fmap2_c *this)

{
  int iVar1;
  int iVar2;
  
  if (this[0x27a8] == (dMenu_Fmap2_c)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = 0;
    do {
      iVar2 = getCmapDatPnt4(this,iVar1);
      iVar2 = isGetCollectMap(this,*(char *)(iVar2 + 1));
      if (iVar2 != 0) break;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x3d);
    if (0x3d < iVar1) {
      iVar1 = -1;
    }
  }
  return iVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Fmap2_c::getNowCmapNextNum(signed char,
                                               int) */

int __thiscall dMenu_Fmap2_c::getNowCmapNextNum(dMenu_Fmap2_c *this,char param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (this[0x27a8] == (dMenu_Fmap2_c)0x1) {
    iVar1 = (int)param_1;
  }
  else {
    iVar1 = (int)param_1;
    do {
      iVar1 = iVar1 + param_2;
      if (iVar1 < 0) {
        iVar1 = 0x3c;
      }
      if (0x3c < iVar1) {
        iVar1 = 0;
      }
      iVar2 = getCmapDatPnt4(this,iVar1);
      iVar2 = isGetCollectMap(this,*(char *)(iVar2 + 1));
    } while (iVar2 == 0);
  }
  return iVar1;
}


/* __thiscall dMenu_Fmap2_c::getCmapDatPnt4(int) */

int __thiscall dMenu_Fmap2_c::getCmapDatPnt4(dMenu_Fmap2_c *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = (*(int **)(this + 0x1c))[1];
  iVar2 = 0;
  iVar3 = **(int **)(this + 0x1c);
  iVar4 = iVar3;
  if (0 < iVar3) {
    do {
      if ((int)*(char *)(iVar1 + 2) == param_1 + 1) break;
      iVar1 = iVar1 + 0x26;
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  if (iVar2 < iVar3) {
    return iVar1;
  }
  return 0;
}


/* __thiscall dMenu_Fmap2_c::readPaneCmapTexture(ResTIMG const *,
                                                 int) */

void __thiscall dMenu_Fmap2_c::readPaneCmapTexture(dMenu_Fmap2_c *this,ResTIMG *param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char acStack40 [36];
  
  pcVar2 = (char *)(*(int **)(this + 0x1c))[1];
  iVar1 = 0;
  iVar3 = **(int **)(this + 0x1c);
  iVar4 = iVar3;
  if (0 < iVar3) {
    do {
      if ((int)pcVar2[2] == param_2 + 1) break;
      pcVar2 = pcVar2 + 0x26;
      iVar1 = iVar1 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  if (iVar3 <= iVar1) {
    pcVar2 = (char *)0x0;
  }
  MSL_C.PPCEABI.bare.H::sprintf
            (acStack40,"R%02X_col_%d.bti",(int)*pcVar2,
             (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo._89_1_);
  JKRArchive::readTypeResource
            (param_1,0x2c00,0x434d2020,acStack40,
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFMapArchive);
  return;
}


/* __thiscall dMenu_Fmap2_c::readFmapTexture(char const *) */

void __thiscall dMenu_Fmap2_c::readFmapTexture(dMenu_Fmap2_c *this,char *param_1)

{
  JKRArchive::readTypeResource
            (*(void **)(this + 4),0x2c00,0x464d2020,param_1,
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFMapArchive);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801c752c) */
/* __thiscall dMenu_Fmap2_c::getButtonIconMode(void) */

uint __thiscall dMenu_Fmap2_c::getButtonIconMode(dMenu_Fmap2_c *this)

{
  ulong uVar1;
  uint unaff_r31;
  
  if (*(int *)(this + 0x10) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap2.h",0x1b2,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap2.h",0x1b2,&DAT_8035ff21);
  }
  if (*(char *)(*(int *)(this + 0x10) + 8) == '\x01') {
    if (this[0x27a8] == (dMenu_Fmap2_c)0x0) {
      unaff_r31 = 1;
    }
    else {
      unaff_r31 = (uint)(byte)this[0x2812];
    }
  }
  else {
    if (*(char *)(*(int *)(this + 0x10) + 8) == '\0') {
      unaff_r31 = 0;
    }
  }
  return unaff_r31;
}


/* __thiscall dMenu_Fmap2_c::isLockBbutton(void) */

dMenu_Fmap2_c __thiscall dMenu_Fmap2_c::isLockBbutton(dMenu_Fmap2_c *this)

{
  return this[0x27fc];
}


/* __thiscall dMenu_Fmap2_c::isGetCollectMap(signed char) */

void __thiscall dMenu_Fmap2_c::isGetCollectMap(dMenu_Fmap2_c *this,char param_1)

{
  dSv_player_map_c::isGetMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,param_1 + -1);
  return;
}


/* __thiscall dMenu_Fmap2_c::isOpenCollectMap(signed char) */

undefined4 __thiscall dMenu_Fmap2_c::isOpenCollectMap(dMenu_Fmap2_c *this,char param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  piVar5 = *(int **)(this + 0x1c);
  iVar4 = piVar5[1];
  iVar3 = 0;
  iVar1 = *piVar5;
  iVar6 = iVar1;
  if (0 < iVar1) {
    do {
      if ((int)*(char *)(iVar4 + 2) == param_1 + 1) break;
      iVar4 = iVar4 + 0x26;
      iVar3 = iVar3 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  if (iVar1 <= iVar3) {
    iVar4 = 0;
  }
  if (iVar4 == 0) {
    uVar2 = 0;
  }
  else {
    iVar3 = piVar5[1];
    iVar1 = 0;
    iVar4 = *piVar5;
    iVar6 = iVar4;
    if (0 < iVar4) {
      do {
        if ((int)*(char *)(iVar3 + 2) == param_1 + 1) break;
        iVar3 = iVar3 + 0x26;
        iVar1 = iVar1 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    if (iVar4 <= iVar1) {
      iVar3 = 0;
    }
    uVar2 = dSv_player_map_c::isOpenMap
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,
                       *(char *)(iVar3 + 1) + -1);
  }
  return uVar2;
}


/* __thiscall dMenu_Fmap2_c::isOpenCollectMapTriforce(signed char) */

undefined4 __thiscall dMenu_Fmap2_c::isOpenCollectMapTriforce(dMenu_Fmap2_c *this,char param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  piVar5 = *(int **)(this + 0x1c);
  iVar4 = piVar5[1];
  iVar3 = 0;
  iVar1 = *piVar5;
  iVar6 = iVar1;
  if (0 < iVar1) {
    do {
      if ((int)*(char *)(iVar4 + 2) == param_1 + 1) break;
      iVar4 = iVar4 + 0x26;
      iVar3 = iVar3 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  if (iVar1 <= iVar3) {
    iVar4 = 0;
  }
  if (iVar4 == 0) {
    uVar2 = 0;
  }
  else {
    iVar3 = piVar5[1];
    iVar1 = 0;
    iVar4 = *piVar5;
    iVar6 = iVar4;
    if (0 < iVar4) {
      do {
        if ((int)*(char *)(iVar3 + 2) == param_1 + 1) break;
        iVar3 = iVar3 + 0x26;
        iVar1 = iVar1 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    if (iVar4 <= iVar1) {
      iVar3 = 0;
    }
    uVar2 = dSv_player_map_c::isTriforce
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,
                       *(char *)(iVar3 + 1) + -1);
  }
  return uVar2;
}


/* __thiscall dMenu_Fmap2_c::getCollectMapKind(signed char) */

int __thiscall dMenu_Fmap2_c::getCollectMapKind(dMenu_Fmap2_c *this,char param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = (*(int **)(this + 0x1c))[1];
  iVar2 = 0;
  iVar1 = **(int **)(this + 0x1c);
  iVar4 = iVar1;
  if (0 < iVar1) {
    do {
      if ((int)*(char *)(iVar3 + 2) == param_1 + 1) break;
      iVar3 = iVar3 + 0x26;
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  if (iVar1 <= iVar2) {
    iVar3 = 0;
  }
  return (int)*(char *)(iVar3 + 3);
}


/* __thiscall dMenu_Fmap2_c::isCompleteCollectMap(signed char) */

void __thiscall dMenu_Fmap2_c::isCompleteCollectMap(dMenu_Fmap2_c *this,char param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = (*(int **)(this + 0x1c))[1];
  iVar2 = 0;
  iVar1 = **(int **)(this + 0x1c);
  iVar4 = iVar1;
  if (0 < iVar1) {
    do {
      if ((int)*(char *)(iVar3 + 2) == param_1 + 1) break;
      iVar3 = iVar3 + 0x26;
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  if (iVar1 <= iVar2) {
    iVar3 = 0;
  }
  dSv_player_map_c::isCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,
             *(char *)(iVar3 + 1) + -1);
  return;
}


/* __thiscall dDlst_FMAP2_c::draw(void) */

void __thiscall dDlst_FMAP2_c::draw(dDlst_FMAP2_c *this)

{
  J2DOrthoGraph *pCtx;
  
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(*(J2DScreen **)(this + 4),d_menu_fmap2::_4118,d_menu_fmap2::_4118,&pCtx->parent);
  return;
}


/* __thiscall dDlst_FMAP2GS_c::draw(void) */

void __thiscall dDlst_FMAP2GS_c::draw(dDlst_FMAP2GS_c *this)

{
  J2DOrthoGraph *pCtx;
  
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(*(J2DScreen **)(this + 4),d_menu_fmap2::_4118,d_menu_fmap2::_4118,&pCtx->parent);
  return;
}


/* __thiscall dDlst_FMAP2GS_c::~dDlst_FMAP2GS_c(void) */

void __thiscall dDlst_FMAP2GS_c::_dDlst_FMAP2GS_c(dDlst_FMAP2GS_c *this)

{
  short in_r4;
  
  if (this != (dDlst_FMAP2GS_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_FMAP2GS_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_FMAP2_c::~dDlst_FMAP2_c(void) */

void __thiscall dDlst_FMAP2_c::_dDlst_FMAP2_c(dDlst_FMAP2_c *this)

{
  short in_r4;
  
  if (this != (dDlst_FMAP2_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_FMAP2_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMf2_HIO_c::~dMf2_HIO_c(void) */

void __thiscall dMf2_HIO_c::_dMf2_HIO_c(dMf2_HIO_c *this)

{
  short in_r4;
  
  if ((this != (dMf2_HIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace d_menu_fmap2 {

void __sinit_d_menu_fmap2_cpp(void)

{
  ::dMf2_HIO_c::dMf2_HIO_c((dMf2_HIO_c *)&g_mf2HIO);
  Runtime.PPCEABI.H::__register_global_object();
  mainProc = _4587;
  DAT_8039269c = DAT_80392624;
  DAT_803926a0 = PTR_FmapProcMain_80392628;
  DAT_803926a4 = _4588;
  DAT_803926a8 = DAT_80392630;
  DAT_803926ac = PTR_FmapChange_80392634;
  DAT_803926b0 = _4589;
  DAT_803926b4 = DAT_8039263c;
  DAT_803926b8 = PTR_CmapProcMain_80392640;
  DAT_803926bc = _4590;
  DAT_803926c0 = DAT_80392648;
  DAT_803926c4 = PTR_CmapProc2_8039264c;
  DAT_803926c8 = _4591;
  DAT_803926cc = DAT_80392654;
  DAT_803926d0 = PTR_CmapOpen_80392658;
  DAT_803926d4 = _4592;
  DAT_803926d8 = DAT_80392660;
  DAT_803926dc = PTR_CmapSpLoadWait_80392664;
  DAT_803926e0 = _4593;
  DAT_803926e4 = DAT_8039266c;
  DAT_803926e8 = PTR_CmapOpenSp_80392670;
  DAT_803926ec = _4594;
  DAT_803926f0 = DAT_80392678;
  DAT_803926f4 = PTR_CmapScroll_8039267c;
  DAT_803926f8 = _4595;
  DAT_803926fc = DAT_80392684;
  DAT_80392700 = PTR_CmapClose_80392688;
  DAT_80392704 = _4596;
  DAT_80392708 = DAT_80392690;
  DAT_8039270c = PTR_ChangeProcMode_80392694;
  return;
}

