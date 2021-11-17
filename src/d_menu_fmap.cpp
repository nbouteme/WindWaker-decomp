#include <d_menu_fmap.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DPane.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <J2DGraph/J2DScreen.h>
#include <d_lib.h>
#include <d_menu_fmap.h>
#include <f_op_actor_mng.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <f_op_msg_mng.h>
#include <J2DGraph/J2DTextBox.h>
#include <d_2dnumber.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <d_map.h>
#include <d_stage.h>
#include <d_save.h>
#include <d_menu_fmap2.h>
#include <m_Do_hostIO.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <J2DGraph/J2DPicture.h>
#include <d_com_inf_game.h>
#include <d_kankyo_wether.h>
#include <SComponent/c_math.h>
#include <MSL_C.PPCEABI.bare.H/w_fmod.h>
#include <JKernel/JKRArchivePub.h>
#include <d_drawlist.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <d_kankyo.h>
#include <d_particle.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dMf_HIO_c.h>
#include <dDlst_FMAP_c.h>
#include <dMenu_Fmap_c.h>


namespace d_menu_fmap {
undefined g_mfHIO;
}

/* __thiscall dMf_HIO_c::dMf_HIO_c(void) */

void __thiscall dMf_HIO_c::dMf_HIO_c(dMf_HIO_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  *(undefined1 **)this = &__vt;
  this[0x107] = (dMf_HIO_c)0x14;
  this[0x108] = (dMf_HIO_c)0xff;
  this[0x109] = (dMf_HIO_c)0xff;
  this[0x10a] = (dMf_HIO_c)0x0;
  this[0x10b] = (dMf_HIO_c)0xff;
  this[0x10c] = (dMf_HIO_c)0x80;
  this[0x10d] = (dMf_HIO_c)0x80;
  this[0x10e] = (dMf_HIO_c)0x80;
  this[0x10f] = (dMf_HIO_c)0xff;
  this[0x104] = (dMf_HIO_c)0x7;
  this[0x105] = (dMf_HIO_c)0x2;
  this[0x106] = (dMf_HIO_c)0x5;
  *(undefined2 *)(this + 0x26) = 0xf;
  *(undefined2 *)(this + 0x28) = 0x19;
  *(undefined2 *)(this + 0x12) = 0;
  *(undefined2 *)(this + 0x14) = 2;
  *(undefined2 *)(this + 0x2a) = 0xf;
  *(undefined2 *)(this + 0x2c) = 5;
  this[9] = (dMf_HIO_c)0xff;
  this[10] = (dMf_HIO_c)0xff;
  this[0xb] = (dMf_HIO_c)0xff;
  this[0xc] = (dMf_HIO_c)0xff;
  this[0xd] = (dMf_HIO_c)0x80;
  this[0xe] = (dMf_HIO_c)0x80;
  this[0xf] = (dMf_HIO_c)0xff;
  this[0x10] = (dMf_HIO_c)0xff;
  this[0x1a] = (dMf_HIO_c)0xff;
  this[0x1b] = (dMf_HIO_c)0x0;
  this[0x1c] = (dMf_HIO_c)0x0;
  this[0x1d] = (dMf_HIO_c)0xff;
  this[0x16] = (dMf_HIO_c)0xff;
  this[0x17] = (dMf_HIO_c)0xff;
  this[0x18] = (dMf_HIO_c)0x0;
  this[0x19] = (dMf_HIO_c)0xff;
  this[0x22] = (dMf_HIO_c)0xff;
  this[0x23] = (dMf_HIO_c)0x8e;
  this[0x24] = (dMf_HIO_c)0x0;
  this[0x25] = (dMf_HIO_c)0xff;
  this[0x1e] = (dMf_HIO_c)0xff;
  this[0x1f] = (dMf_HIO_c)0xff;
  this[0x20] = (dMf_HIO_c)0x82;
  this[0x21] = (dMf_HIO_c)0x9b;
  this[0x2e] = (dMf_HIO_c)0x7;
  this[0x2f] = (dMf_HIO_c)0x7;
  this[0x30] = (dMf_HIO_c)0x5;
  fVar1 = d_menu_fmap::_4189;
  *(float *)(this + 0x50) = d_menu_fmap::_4189;
  fVar2 = d_menu_fmap::_4190;
  *(float *)(this + 0x74) = d_menu_fmap::_4190;
  fVar3 = d_menu_fmap::_4191;
  *(float *)(this + 0x54) = d_menu_fmap::_4191;
  *(float *)(this + 0x78) = fVar2;
  fVar4 = d_menu_fmap::_4192;
  *(float *)(this + 0x58) = d_menu_fmap::_4192;
  *(float *)(this + 0x7c) = fVar2;
  *(float *)(this + 0x5c) = fVar1;
  fVar5 = d_menu_fmap::_4193;
  *(float *)(this + 0x80) = d_menu_fmap::_4193;
  *(float *)(this + 0x60) = d_menu_fmap::_4194;
  *(float *)(this + 0x84) = fVar5;
  *(float *)(this + 100) = fVar4;
  fVar6 = d_menu_fmap::_4195;
  *(float *)(this + 0x88) = d_menu_fmap::_4195;
  *(float *)(this + 0x68) = fVar1;
  fVar1 = d_menu_fmap::_4196;
  *(float *)(this + 0x8c) = d_menu_fmap::_4196;
  *(float *)(this + 0x6c) = fVar2;
  fVar7 = d_menu_fmap::_4197;
  *(float *)(this + 0x90) = d_menu_fmap::_4197;
  *(float *)(this + 0x70) = d_menu_fmap::_4198;
  *(float *)(this + 0x94) = fVar6;
  *(float *)(this + 0x98) = d_menu_fmap::_4199;
  *(float *)(this + 0x9c) = d_menu_fmap::_4200;
  *(float *)(this + 0xa0) = fVar4;
  *(float *)(this + 0xac) = d_menu_fmap::_4201;
  fVar6 = d_menu_fmap::_4202;
  *(float *)(this + 0xa4) = d_menu_fmap::_4202;
  *(float *)(this + 0xb0) = fVar5;
  *(float *)(this + 0xa8) = fVar4;
  *(float *)(this + 0xb4) = d_menu_fmap::_4203;
  *(float *)(this + 0xb8) = fVar3;
  *(float *)(this + 0xc4) = fVar7;
  *(float *)(this + 0xbc) = fVar3;
  *(float *)(this + 200) = d_menu_fmap::_4204;
  *(float *)(this + 0xc0) = fVar4;
  *(float *)(this + 0xcc) = fVar5;
  *(float *)(this + 0xd0) = fVar7;
  *(float *)(this + 0xd8) = fVar6;
  *(float *)(this + 0xd4) = fVar2;
  *(float *)(this + 0xdc) = fVar1;
  this[0x31] = (dMf_HIO_c)0x32;
  this[0x32] = (dMf_HIO_c)0xa;
  this[0xe0] = (dMf_HIO_c)0x32;
  this[0xe1] = (dMf_HIO_c)0xff;
  this[0xe2] = (dMf_HIO_c)0xff;
  this[0xe3] = (dMf_HIO_c)0xff;
  this[0xe5] = (dMf_HIO_c)0xff;
  this[0xe6] = (dMf_HIO_c)0xff;
  this[0xe7] = (dMf_HIO_c)0xff;
  this[0xe9] = (dMf_HIO_c)0x32;
  this[0xee] = (dMf_HIO_c)0xff;
  this[0xef] = (dMf_HIO_c)0x40;
  this[0xf0] = (dMf_HIO_c)0x0;
  this[0xf1] = (dMf_HIO_c)0x0;
  this[0xea] = (dMf_HIO_c)0x0;
  this[0xeb] = (dMf_HIO_c)0x0;
  this[0xec] = (dMf_HIO_c)0x0;
  this[0xed] = (dMf_HIO_c)0xff;
  this[0xf2] = (dMf_HIO_c)0xc0;
  this[0xf7] = (dMf_HIO_c)0x0;
  this[0xf8] = (dMf_HIO_c)0x40;
  this[0xf9] = (dMf_HIO_c)0x0;
  this[0xfa] = (dMf_HIO_c)0x0;
  this[0xf3] = (dMf_HIO_c)0x0;
  this[0xf4] = (dMf_HIO_c)0x81;
  this[0xf5] = (dMf_HIO_c)0x0;
  this[0xf6] = (dMf_HIO_c)0xff;
  this[0xfb] = (dMf_HIO_c)0x80;
  this[0xfc] = (dMf_HIO_c)0x88;
  this[0xfd] = (dMf_HIO_c)0x32;
  this[0xfe] = (dMf_HIO_c)0x0;
  this[0xff] = (dMf_HIO_c)0xff;
  this[0x100] = (dMf_HIO_c)0xf0;
  this[0x101] = (dMf_HIO_c)0x0;
  this[0x102] = (dMf_HIO_c)0x0;
  this[0x103] = (dMf_HIO_c)0xff;
  this[0x34] = (dMf_HIO_c)0x6;
  this[0x33] = (dMf_HIO_c)0x4;
  *(undefined2 *)(this + 0x36) = 0x14;
  *(undefined2 *)(this + 0x38) = 0x3c;
  this[0x3a] = (dMf_HIO_c)0x8;
  this[0x3b] = (dMf_HIO_c)0x3;
  this[0x3c] = (dMf_HIO_c)0x3;
  this[0x3d] = (dMf_HIO_c)0x3;
  this[0x3e] = (dMf_HIO_c)0x6;
  this[0x3f] = (dMf_HIO_c)0x0;
  this[0x40] = (dMf_HIO_c)0x0;
  this[0x41] = (dMf_HIO_c)0x5;
  *(undefined2 *)(this + 0x44) = 0xfe0c;
  this[0x42] = (dMf_HIO_c)0x0;
  this[0x43] = (dMf_HIO_c)0x0;
  this[0x46] = (dMf_HIO_c)0x5;
  this[0x47] = (dMf_HIO_c)0x8;
  this[0x48] = (dMf_HIO_c)0x5;
  this[0x49] = (dMf_HIO_c)0x2;
  *(undefined2 *)(this + 0x4a) = 200;
  this[0x4c] = (dMf_HIO_c)0xc;
  this[0x4e] = (dMf_HIO_c)0x8c;
  this[0x4d] = (dMf_HIO_c)0x46;
  this[5] = (dMf_HIO_c)0x0;
  this[6] = (dMf_HIO_c)0x0;
  this[7] = (dMf_HIO_c)0x0;
  this[8] = (dMf_HIO_c)0x0;
  this[0x110] = (dMf_HIO_c)0xa;
  this[0x111] = (dMf_HIO_c)0x7;
  this[0x112] = (dMf_HIO_c)0x7;
  this[0x113] = (dMf_HIO_c)0x7;
  this[0x114] = (dMf_HIO_c)0x7;
  this[0x115] = (dMf_HIO_c)0x1e;
  this[0x116] = (dMf_HIO_c)0x1e;
  this[0x117] = (dMf_HIO_c)0xa;
  this[0x118] = (dMf_HIO_c)0x2;
  this[0x119] = (dMf_HIO_c)0x1e;
  this[0x11a] = (dMf_HIO_c)0x0;
  this[0x11b] = (dMf_HIO_c)0xa;
  this[0x11c] = (dMf_HIO_c)0x14;
  this[0x11d] = (dMf_HIO_c)0xff;
  this[0x11e] = (dMf_HIO_c)0x20;
  return;
}


/* __thiscall dMenu_Fmap_c::_create(void) */

void __thiscall dMenu_Fmap_c::_create(dMenu_Fmap_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  void *pvVar2;
  STControl *this_01;
  TBox2_float_ local_18;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_18.mTL.x = d_menu_fmap::_4256;
    local_18.mTL.y = d_menu_fmap::_4256;
    local_18.mBR.x = d_menu_fmap::_4257;
    local_18.mBR.y = d_menu_fmap::_4258;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_18);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)&this->field_0x20 = this_00;
  if (*(int *)&this->field_0x20 == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap.cpp",0x23b,"fmapDl.scrn != 0");
    m_Do_printf::OSPanic("d_menu_fmap.cpp",0x23b,&DAT_8035fc8d);
  }
  J2DScreen::set(*(J2DScreen **)&this->field_0x20,"f_map.blo",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFMapResArchive);
  pvVar2 = JKernel::operator_new(0x150);
  if (pvVar2 != (void *)0x0) {
    *(undefined4 *)((int)pvVar2 + 0x20) = 0;
    *(undefined4 *)((int)pvVar2 + 0x18) = 0;
    *(undefined4 *)((int)pvVar2 + 0x2c) = 0;
    *(undefined *)((int)pvVar2 + 0x74) = 0;
  }
  *(void **)&this->field_0x2884 = pvVar2;
  if (*(int *)&this->field_0x2884 == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap.cpp",0x23f,"outFont != 0");
    m_Do_printf::OSPanic("d_menu_fmap.cpp",0x23f,&DAT_8035fc8d);
  }
  *(undefined *)(*(int *)&this->field_0x2884 + 0x74) = 1;
  pvVar2 = JKernel::operator_new(0x150);
  if (pvVar2 != (void *)0x0) {
    *(undefined4 *)((int)pvVar2 + 0x20) = 0;
    *(undefined4 *)((int)pvVar2 + 0x18) = 0;
    *(undefined4 *)((int)pvVar2 + 0x2c) = 0;
    *(undefined *)((int)pvVar2 + 0x74) = 0;
  }
  *(void **)&this->field_0x2888 = pvVar2;
  if (*(int *)&this->field_0x2888 == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap.cpp",0x243,"outFont2 != 0");
    m_Do_printf::OSPanic("d_menu_fmap.cpp",0x243,&DAT_8035fc8d);
  }
  this_01 = (STControl *)JKernel::operator_new(0x28);
  if (this_01 != (STControl *)0x0) {
    STControl::STControl(this_01,5,2,3,2,d_menu_fmap::_4259,d_menu_fmap::_4260,0,0x2000);
  }
  *(STControl **)&this->field_0x50cc = this_01;
  if (*(int *)&this->field_0x50cc == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap.cpp",0x246,"stick != 0");
    m_Do_printf::OSPanic("d_menu_fmap.cpp",0x246,&DAT_8035fc8d);
  }
  STControl::setWaitParm
            (*(STControl **)&this->field_0x50cc,5,2,3,2,d_menu_fmap::_4259,d_menu_fmap::_4260,0,
             0x800);
  pvVar2 = JKernel::operator_new(0x2c00,0x20);
  *(void **)&this->field_0x18 = pvVar2;
  if (*(int *)&this->field_0x18 == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap.cpp",0x24a,"mChkPntTxt_p != 0");
    m_Do_printf::OSPanic("d_menu_fmap.cpp",0x24a,&DAT_8035fc8d);
  }
  screenSet(this);
  aramCmapDatRead(this);
  *(undefined *)(this + 1) = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo._89_1_;
  initialize(this);
  displayinit(this);
  phantomShipCheck(this);
  *(undefined *)&this->field_0x510c = 0;
  *(undefined *)&this->field_0x516b = 0;
  return;
}


/* __thiscall dMenu_Fmap_c::phantomShipCheck(void) */

void __thiscall dMenu_Fmap_c::phantomShipCheck(dMenu_Fmap_c *this)

{
  int iVar1;
  
  iVar1 = f_op_actor_mng::fopAcM_searchFromName("Ayush",0,0);
  if ((iVar1 != 0) && (*(float *)(iVar1 + 0x2fc) != d_menu_fmap::_4256)) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x107a,(cXyz *)0x0,0,0,d_menu_fmap::_4271,d_menu_fmap::_4271,
               d_menu_fmap::_4272,d_menu_fmap::_4272,0);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* __thiscall dMenu_Fmap_c::screenSet(void) */

void __thiscall dMenu_Fmap_c::screenSet(dMenu_Fmap_c *this)

{
  char *pcVar1;
  undefined4 uVar2;
  J2DScreen *pJVar3;
  ___ _Var4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined local_158;
  undefined uStack343;
  undefined uStack342;
  undefined uStack341;
  undefined local_154;
  undefined uStack339;
  undefined uStack338;
  undefined uStack337;
  undefined local_150;
  undefined uStack335;
  undefined uStack334;
  undefined uStack333;
  undefined local_14c;
  undefined uStack331;
  undefined uStack330;
  undefined uStack329;
  undefined local_148;
  undefined uStack327;
  undefined uStack326;
  undefined uStack325;
  undefined local_144;
  undefined uStack323;
  undefined uStack322;
  undefined uStack321;
  undefined uStack317;
  undefined uStack313;
  char local_130 [127];
  undefined local_b1;
  char local_b0 [127];
  undefined local_31;
  
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x288c,*(J2DScreen **)&this->field_0x20,0x6664646d);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x28c4,*(J2DScreen **)&this->field_0x20,0x636c);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x2dcc,*(J2DScreen **)&this->field_0x20,0x61726561);
  uStack313 = (undefined)*(undefined4 *)(*(int *)&this->field_0x2dcc + 0x104);
  uStack317 = (undefined)*(undefined4 *)(*(int *)&this->field_0x2dcc + 0x108);
  *(undefined *)&this->field_0x5166 = uStack317;
  *(undefined *)&this->field_0x5167 = uStack313;
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x28fc,*(J2DScreen **)&this->field_0x20,0x63693232);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x2934,*(J2DScreen **)&this->field_0x20,0x63693231);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x296c,*(J2DScreen **)&this->field_0x20,0x63693332);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x29a4,*(J2DScreen **)&this->field_0x20,0x63693331);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x29dc,*(J2DScreen **)&this->field_0x20,0x47544931);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x2a14,*(J2DScreen **)&this->field_0x20,0x47544932);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x2e04,*(J2DScreen **)&this->field_0x20,0x6c6e6b31);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x2e3c,*(J2DScreen **)&this->field_0x20,0x73706931);
  iVar9 = 0x6b6b3130;
  iVar7 = 0x6b6b3230;
  iVar6 = 0x6b6b3330;
  iVar5 = 0x6b6b3430;
  iVar8 = 0;
  iVar11 = 0;
  do {
    iVar10 = &this->field_0x0 + iVar11;
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(iVar10 + 0x2a4c),*(J2DScreen **)&this->field_0x20,iVar9);
    iVar12 = &this->field_0xe0 + iVar8 * 0x38;
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(iVar12 + 0x2a4c),*(J2DScreen **)&this->field_0x20,iVar7);
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(iVar10 + 0x2c0c),*(J2DScreen **)&this->field_0x20,iVar6);
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(iVar12 + 0x2c0c),*(J2DScreen **)&this->field_0x20,iVar5);
    iVar8 = iVar8 + 1;
    iVar9 = iVar9 + 1;
    iVar7 = iVar7 + 1;
    iVar6 = iVar6 + 1;
    iVar5 = iVar5 + 1;
    iVar11 = iVar11 + 0x38;
  } while (iVar8 < 4);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x4a74,*(J2DScreen **)&this->field_0x20,0x776e6431);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x4aac,*(J2DScreen **)&this->field_0x20,0x776e6432);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x2e74,*(J2DScreen **)&this->field_0x20,0x6b6b646d);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x2eac,*(J2DScreen **)&this->field_0x20,0x736d736b);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x30dc,*(J2DScreen **)&this->field_0x20,0x73633131);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x3114,*(J2DScreen **)&this->field_0x20,0x73633132);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x314c,*(J2DScreen **)&this->field_0x20,0x73633133);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x3184,*(J2DScreen **)&this->field_0x20,0x73633134);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x31bc,*(J2DScreen **)&this->field_0x20,0x73633135);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x31f4,*(J2DScreen **)&this->field_0x20,0x73633136);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x322c,*(J2DScreen **)&this->field_0x20,0x73633137);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x3264,*(J2DScreen **)&this->field_0x20,0x73633138);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x329c,*(J2DScreen **)&this->field_0x20,0x73633139);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x2f54,*(J2DScreen **)&this->field_0x20,0x74737731);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x2fc4,*(J2DScreen **)&this->field_0x20,0x53544d31);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x2f8c,*(J2DScreen **)&this->field_0x20,0x52303142);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x2ee4,*(J2DScreen **)&this->field_0x20,0x6c6e6b32);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x2f1c,*(J2DScreen **)&this->field_0x20,0x73706932);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x30a4,*(J2DScreen **)&this->field_0x20,0x636c62);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x306c,*(J2DScreen **)&this->field_0x20,0x636c6232);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x2ffc,*(J2DScreen **)&this->field_0x20,0x6b747831);
  _Var4 = 0x6b747832;
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x3034,*(J2DScreen **)&this->field_0x20,0x6b747832);
  J2DTextBox::setFont(*(J2DTextBox **)&this->field_0x2ffc,*(JUTFont **)&this->field_0x50d0);
  J2DTextBox::setFont(*(J2DTextBox **)&this->field_0x3034,*(JUTFont **)&this->field_0x50d4);
  pcVar1 = local_b0;
  iVar5 = 0x80;
  do {
    *pcVar1 = 'A';
    pcVar1 = pcVar1 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  local_31 = 0;
  J2DTextBox::setString(*(J2DTextBox **)&this->field_0x2ffc,local_b0,_Var4);
  J2DTextBox::setString(*(J2DTextBox **)&this->field_0x3034,local_b0,_Var4);
  uVar2 = J2DTextBox::getStringPtr(*(J2DTextBox **)&this->field_0x2ffc);
  *(undefined4 *)&this[1].field_0xc = uVar2;
  uVar2 = J2DTextBox::getStringPtr(*(J2DTextBox **)&this->field_0x3034);
  *(undefined4 *)&this[1].field_0x10 = uVar2;
  dDlst_2DOutFont_c::setPaneEx
            (*(dDlst_2DOutFont_c **)&this->field_0x2888,*(JUTFont **)&this->field_0x50d0,
             (fopMsgM_pane_class *)&this->field_0x2ffc,(fopMsgM_pane_class *)0x0,
             (fopMsgM_pane_class *)0x0,(fopMsgM_pane_class *)0x0,*(char **)&this[1].field_0xc);
  dDlst_2DOutFont_c::setRubyEx
            (*(dDlst_2DOutFont_c **)&this->field_0x2888,*(JUTFont **)&this->field_0x50d4,
             (fopMsgM_pane_class *)&this->field_0x3034,*(char **)&this[1].field_0x10);
  dDlst_2DOutFont_c::messageSet(*(dDlst_2DOutFont_c **)&this->field_0x2888,0x319b);
  uVar2 = *(undefined4 *)&this->field_0x300c;
  iVar5 = *(int *)&this->field_0x2888;
  *(undefined4 *)(iVar5 + 0x30) = *(undefined4 *)&this->field_0x3008;
  *(undefined4 *)(iVar5 + 0x34) = uVar2;
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ != '\0') {
    *(float *)&this->field_0x3014 = *(float *)&this->field_0x3014 - d_menu_fmap::_4441;
    *(undefined4 *)&this->field_0x301c = *(undefined4 *)&this->field_0x3014;
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)&this->field_0x2ffc);
    *(undefined4 *)&this->field_0x3004 = *(undefined4 *)&this->field_0x300c;
  }
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x3814,*(J2DScreen **)&this->field_0x20,0x636c67);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x32d4,*(J2DScreen **)&this->field_0x20,0x6c6e6b33);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x330c,*(J2DScreen **)&this->field_0x20,0x73706933);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x3344,*(J2DScreen **)&this->field_0x20,0x53544c31);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x337c,*(J2DScreen **)&this->field_0x20,0x52303147);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x33b4,*(J2DScreen **)&this->field_0x20,0x666d756d);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x33ec,*(J2DScreen **)&this->field_0x20,0x666d7731);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x3424,*(J2DScreen **)&this->field_0x20,0x666d7732);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x345c,*(J2DScreen **)&this->field_0x20,0x666d7733);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x3494,*(J2DScreen **)&this->field_0x20,0x666d7734);
  iVar5 = 0;
  iVar6 = 0;
  iVar7 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(&this->field_0x34cc + iVar7),*(J2DScreen **)&this->field_0x20,
               *(int *)((int)&d_menu_fmap::tag00_4288 + iVar6));
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 0x38;
  } while (iVar5 < 0xf);
  iVar6 = 0x73633231;
  iVar5 = 0;
  iVar7 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(&this->field_0x384c + iVar7),*(J2DScreen **)&this->field_0x20,
               iVar6);
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + 0x38;
  } while (iVar5 < 7);
  iVar8 = 0x434b3131;
  iVar6 = 0x434b3231;
  iVar5 = 0;
  iVar7 = 0;
  do {
    iVar9 = &this->field_0x0 + iVar7;
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(iVar9 + 0x46f4),*(J2DScreen **)&this->field_0x20,iVar8);
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(iVar9 + 0x479c),*(J2DScreen **)&this->field_0x20,iVar6);
    iVar5 = iVar5 + 1;
    iVar8 = iVar8 + 1;
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + 0x38;
  } while (iVar5 < 3);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x4844,*(J2DScreen **)&this->field_0x20,0x434b3331);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x487c,*(J2DScreen **)&this->field_0x20,0x434b3332);
  uVar2 = *(undefined4 *)(*(int *)&this->field_0x46f4 + 0x108);
  local_144 = (undefined)((uint)uVar2 >> 0x18);
  *(undefined *)&this[1].field_0x14 = local_144;
  uStack323 = (undefined)((uint)uVar2 >> 0x10);
  *(undefined *)&this[1].field_0x15 = uStack323;
  uStack322 = (undefined)((uint)uVar2 >> 8);
  *(undefined *)&this[1].field_0x16 = uStack322;
  uStack321 = (undefined)uVar2;
  *(undefined *)&this[1].field_0x17 = uStack321;
  uVar2 = *(undefined4 *)(*(int *)&this->field_0x46f4 + 0x104);
  local_148 = (undefined)((uint)uVar2 >> 0x18);
  *(undefined *)&this[1].field_0x18 = local_148;
  uStack327 = (undefined)((uint)uVar2 >> 0x10);
  *(undefined *)&this[1].field_0x19 = uStack327;
  uStack326 = (undefined)((uint)uVar2 >> 8);
  *(undefined *)&this[1].field_0x1a = uStack326;
  uStack325 = (undefined)uVar2;
  *(undefined *)&this[1].field_0x1b = uStack325;
  iVar5 = 0;
  iVar6 = 0;
  iVar7 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(&this->field_0x48b4 + iVar7),*(J2DScreen **)&this->field_0x20,
               *(int *)((int)&d_menu_fmap::tagkr_4304 + iVar6));
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 0x38;
  } while (iVar5 < 8);
  uVar2 = *(undefined4 *)(*(int *)&this->field_0x48b4 + 0x108);
  local_14c = (undefined)((uint)uVar2 >> 0x18);
  *(undefined *)&this[1].field_0x1c = local_14c;
  uStack331 = (undefined)((uint)uVar2 >> 0x10);
  *(undefined *)&this[1].field_0x1d = uStack331;
  uStack330 = (undefined)((uint)uVar2 >> 8);
  *(undefined *)&this[1].field_0x1e = uStack330;
  uStack329 = (undefined)uVar2;
  *(undefined *)&this[1].field_0x1f = uStack329;
  uVar2 = *(undefined4 *)(*(int *)&this->field_0x48b4 + 0x104);
  local_150 = (undefined)((uint)uVar2 >> 0x18);
  *(undefined *)&this[1].field_0x20 = local_150;
  uStack335 = (undefined)((uint)uVar2 >> 0x10);
  *(undefined *)&this[1].field_0x21 = uStack335;
  uStack334 = (undefined)((uint)uVar2 >> 8);
  *(undefined *)&this[1].field_0x22 = uStack334;
  uStack333 = (undefined)uVar2;
  *(undefined *)&this[1].field_0x23 = uStack333;
  iVar5 = 0;
  iVar6 = 0;
  iVar7 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(&this->field_0x39d4 + iVar7),*(J2DScreen **)&this->field_0x20,
               *(int *)((int)&d_menu_fmap::l_island_4310 + iVar6));
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 0x38;
  } while (iVar5 < 0xb);
  iVar5 = 0;
  iVar6 = 0;
  iVar7 = 0;
  do {
    pJVar3 = (J2DScreen *)
             (**(code **)(**(int **)&this->field_0x20 + 0x30))
                       (*(int **)&this->field_0x20,
                        *(undefined4 *)
                         (
                         "R2DST01ST02ST03ST04ST05ST06ST07ST08ST09ST10ST11ST12ST13ST14ST15ST16ST17ST18ST19ST20ST21ST22ST23ST24ST25ST26ST27ST28ST29ST30ST31ST32ST33ST34ST35ST36ST37ST38ST39ST40ST41ST42ST43ST44ST45ST46ST47ST48ST49gs07gs01gs02gs03gs04gs05gs06cmap_tri.bti"
                         + iVar7 + 3));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(&this->field_0x3c3c + iVar6),pJVar3);
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 0x38;
    iVar7 = iVar7 + 4;
  } while (iVar5 < 0x31);
  pcVar1 = local_130;
  iVar5 = 0x80;
  do {
    *pcVar1 = 'A';
    pcVar1 = pcVar1 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar5 = 0;
  local_b1 = 0;
  iVar7 = 0;
  iVar6 = 0;
  do {
    iVar8 = &this->field_0x0 + iVar6;
    _Var4 = *(___ *)((int)&d_menu_fmap::txtnm_4327 + iVar7);
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(iVar8 + 0x4b1c),*(J2DScreen **)&this->field_0x20,_Var4);
    J2DTextBox::setFont(*(J2DTextBox **)(iVar8 + 0x4b1c),*(JUTFont **)&this->field_0x50d0);
    J2DTextBox::setString(*(J2DTextBox **)(iVar8 + 0x4b1c),local_130,_Var4);
    uVar2 = J2DTextBox::getStringPtr(*(J2DTextBox **)(iVar8 + 0x4b1c));
    *(undefined4 *)(&this->field_0x5148 + iVar7) = uVar2;
    **(undefined **)(&this->field_0x5148 + iVar7) = 0;
    *(undefined *)(*(int *)(iVar8 + 0x4b1c) + 0xaa) = 1;
    iVar5 = iVar5 + 1;
    iVar7 = iVar7 + 4;
    iVar6 = iVar6 + 0x38;
  } while (iVar5 < 3);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x4bc4,*(J2DScreen **)&this->field_0x20,0x62743030);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x4bfc,*(J2DScreen **)&this->field_0x20,0x62743031);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x4c34,*(J2DScreen **)&this->field_0x20,0x62743032);
  dDlst_2DOutFont_c::setPane
            (*(dDlst_2DOutFont_c **)&this->field_0x2884,*(JUTFont **)&this->field_0x50d0,
             (fopMsgM_pane_class *)&this->field_0x4b8c,(fopMsgM_pane_class *)&this->field_0x4bc4,
             (fopMsgM_pane_class *)&this->field_0x4bfc,(fopMsgM_pane_class *)&this->field_0x4c34);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x4c6c,*(J2DScreen **)&this->field_0x20,0x77747331);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x4ca4,*(J2DScreen **)&this->field_0x20,0x63633031);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x4d4c,*(J2DScreen **)&this->field_0x20,0x79733031);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x4d84,*(J2DScreen **)&this->field_0x20,0x79733030);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x4dbc,*(J2DScreen **)&this->field_0x20,0x79736b30);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x4df4,*(J2DScreen **)&this->field_0x20,0x796573);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x4e2c,*(J2DScreen **)&this->field_0x20,0x6e6f3031);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x4e64,*(J2DScreen **)&this->field_0x20,0x6e6f3030);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x4e9c,*(J2DScreen **)&this->field_0x20,0x6e6f6b30);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x4ed4,*(J2DScreen **)&this->field_0x20,0x6e6f);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x4f0c,*(J2DScreen **)&this->field_0x20,0x63757231);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x4d14,*(J2DScreen **)&this->field_0x20,0x777430);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x4cdc,*(J2DScreen **)&this->field_0x20,0x777431);
  J2DTextBox::setFont(*(J2DTextBox **)&this->field_0x4df4,*(JUTFont **)&this->field_0x50d0);
  J2DTextBox::setFont(*(J2DTextBox **)&this->field_0x4ed4,*(JUTFont **)&this->field_0x50d0);
  J2DTextBox::setFont(*(J2DTextBox **)&this->field_0x4d14,*(JUTFont **)&this->field_0x50d0);
  J2DTextBox::setFont(*(J2DTextBox **)&this->field_0x4cdc,*(JUTFont **)&this->field_0x50d4);
  uVar2 = *(undefined4 *)(*(int *)&this->field_0x4d4c + 0x104);
  local_154 = (undefined)((uint)uVar2 >> 0x18);
  *(undefined *)&this[1].field_0x28 = local_154;
  uStack339 = (undefined)((uint)uVar2 >> 0x10);
  *(undefined *)&this[1].field_0x29 = uStack339;
  uStack338 = (undefined)((uint)uVar2 >> 8);
  *(undefined *)&this[1].field_0x2a = uStack338;
  uStack337 = (undefined)uVar2;
  *(undefined *)&this[1].field_0x2b = uStack337;
  uVar2 = *(undefined4 *)(*(int *)&this->field_0x4d4c + 0x108);
  local_158 = (undefined)((uint)uVar2 >> 0x18);
  *(undefined *)&this[1].field_0x24 = local_158;
  uStack343 = (undefined)((uint)uVar2 >> 0x10);
  *(undefined *)&this[1].field_0x25 = uStack343;
  uStack342 = (undefined)((uint)uVar2 >> 8);
  *(undefined *)&this[1].field_0x26 = uStack342;
  uStack341 = (undefined)uVar2;
  *(undefined *)&this[1].field_0x27 = uStack341;
  iVar5 = *(int *)&this->field_0x4d14;
  *(undefined *)(iVar5 + 0xf8) = 0xff;
  *(undefined *)(iVar5 + 0xf9) = 0xff;
  *(undefined *)(iVar5 + 0xfa) = 0xff;
  *(undefined *)(iVar5 + 0xfb) = 0;
  iVar5 = *(int *)&this->field_0x4d14;
  *(undefined *)(iVar5 + 0xf4) = 0xff;
  *(undefined *)(iVar5 + 0xf5) = 0xff;
  *(undefined *)(iVar5 + 0xf6) = 0xff;
  *(undefined *)(iVar5 + 0xf7) = 0xff;
  iVar5 = 0;
  iVar7 = 0;
  iVar6 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(&this->field_0x4f44 + iVar6),*(J2DScreen **)&this->field_0x20,
               *(int *)(
                       "R2DST01ST02ST03ST04ST05ST06ST07ST08ST09ST10ST11ST12ST13ST14ST15ST16ST17ST18ST19ST20ST21ST22ST23ST24ST25ST26ST27ST28ST29ST30ST31ST32ST33ST34ST35ST36ST37ST38ST39ST40ST41ST42ST43ST44ST45ST46ST47ST48ST49gs07gs01gs02gs03gs04gs05gs06cmap_tri.bti"
                       + iVar7 + 199));
    iVar5 = iVar5 + 1;
    iVar7 = iVar7 + 4;
    iVar6 = iVar6 + 0x38;
  } while (iVar5 < 7);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x801b0cec) */
/* __thiscall dMenu_Fmap_c::initialize(void) */

void __thiscall dMenu_Fmap_c::initialize(dMenu_Fmap_c *this)

{
  byte bVar1;
  daPy_lk_c *pdVar2;
  daShip_c *pdVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double dVar7;
  int iVar8;
  stage_map_info_class *psVar9;
  undefined uVar11;
  ulong uVar10;
  dComIfG_inf_c *pdVar12;
  char cVar13;
  char local_28;
  dMap_c local_27 [7];
  undefined4 local_20;
  uint uStack28;
  
  *(undefined2 *)&this->field_0x5116 = 0;
  *(undefined *)&this->field_0x516a = 0;
  pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  pdVar12 = &d_com_inf_game::g_dComIfG_gameInfo;
  *(float *)&this->field_0x511c =
       ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent.mPos.x;
  *(float *)&this->field_0x5120 = (pdVar2->parent).parent.mCurrent.mPos.z;
  dVar7 = d_menu_fmap::_4609;
  fVar6 = d_menu_fmap::_4607;
  fVar5 = d_menu_fmap::_4606;
  uStack28 = (int)(short)((pdVar2->parent).parent.mCollisionRot.y + -0x8000) ^ 0x80000000;
  *(float *)&this->field_0x5124 =
       (d_menu_fmap::_4606 * (float)((double)CONCAT44(0x43300000,uStack28) - d_menu_fmap::_4609)) /
       d_menu_fmap::_4607;
  fVar4 = d_menu_fmap::_4256;
  pdVar3 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpShip;
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpShip == (daShip_c *)0x0) {
    *(float *)&this->field_0x5128 = d_menu_fmap::_4256;
    *(float *)&this->field_0x512c = fVar4;
  }
  else {
    *(float *)&this->field_0x5128 =
         ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpShip)->parent).mCurrent.mPos.x;
    *(float *)&this->field_0x512c = (pdVar3->parent).mCurrent.mPos.z;
    uStack28 = (int)(short)((pdVar3->parent).mCollisionRot.y + -0x8000) ^ 0x80000000;
    *(float *)&this->field_0x5130 =
         (fVar5 * (float)((double)CONCAT44(0x43300000,uStack28) - dVar7)) / fVar6;
  }
  local_20 = 0x43300000;
  iVar8 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"sea");
  if (iVar8 == 0) {
    *(undefined *)&this->field_0x517f = 1;
    dMap_c::point2Grid(local_27,*(float *)&this->field_0x511c,*(float *)&this->field_0x5120,
                       &local_28,(char *)pdVar12);
    *(dMap_c *)&this->field_0x5118 = local_27[0];
    *(char *)&this->field_0x5119 = local_28;
    dMap_c::point2Grid(local_27,*(float *)&this->field_0x5128,*(float *)&this->field_0x512c,
                       &local_28,(char *)pdVar12);
    cVar13 = (char)pdVar12;
    *(dMap_c *)&this->field_0x511a = local_27[0];
    *(char *)&this->field_0x511b = local_28;
  }
  else {
    *(undefined *)&this->field_0x517f = 0;
    iVar8 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Obshop");
    cVar13 = (char)pdVar12;
    if (((iVar8 == 0) ||
        (iVar8 = MSL_C.PPCEABI.bare.H::strcmp
                           (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Abship"),
        iVar8 == 0)) ||
       (iVar8 = MSL_C.PPCEABI.bare.H::strcmp
                          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"PShip"),
       iVar8 == 0)) {
      bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mLastSeaRoom / 7;
      *(byte *)&this->field_0x5118 = d_com_inf_game::g_dComIfG_gameInfo.mLastSeaRoom % 7 - 3;
      *(byte *)&this->field_0x5119 = bVar1 - 3;
    }
    else {
      psVar9 = (stage_map_info_class *)
               (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getMapInfo)
                         (0x803c9d58);
      if (psVar9 == (stage_map_info_class *)0x0) {
        *(undefined *)&this->field_0x5118 = 0;
        *(undefined *)&this->field_0x5119 = 0;
      }
      else {
        uVar11 = d_stage::dStage_mapInfo_GetOceanX(psVar9);
        *(undefined *)&this->field_0x5118 = uVar11;
        if (*(char *)&this->field_0x5118 == '\x04') {
          *(undefined *)&this->field_0x5118 = 0;
        }
        uVar11 = d_stage::dStage_mapInfo_GetOceanZ(psVar9);
        *(undefined *)&this->field_0x5119 = uVar11;
        if (*(char *)&this->field_0x5119 == '\x04') {
          *(undefined *)&this->field_0x5119 = 0;
        }
      }
    }
    *(undefined *)&this->field_0x511a = *(undefined *)&this->field_0x5118;
    *(undefined *)&this->field_0x511b = *(undefined *)&this->field_0x5119;
  }
  uVar11 = dMap_c::getCheckPointUseGrid
                     ((dMap_c *)(uint)*(byte *)&this->field_0x5118,*(char *)&this->field_0x5119,
                      cVar13);
  *(undefined *)&this->field_0x5112 = uVar11;
  *(undefined2 *)&this->field_0x4aaa = 0;
  checkMarkAnimeInit(this);
  *(undefined *)&this->field_0x5140 = 0;
  *(undefined *)&this->field_0x5141 = 0;
  *(undefined *)&this->field_0x5142 = 0;
  *(undefined *)&this->field_0x513d = 0;
  *(undefined *)&this->field_0x513e = 0;
  *(undefined *)&this->field_0x513f = 0;
  if (this->mFmapSv == (undefined *)0x0) {
    uVar10 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar10,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9,&DAT_8035fc8d);
  }
  if ((char)this->mFmapSv[4] < -3) {
LAB_801b0a18:
    uVar11 = *(undefined *)&this->field_0x5118;
    if (this->mFmapSv == (undefined *)0x0) {
      uVar10 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar10,"d_menu_fmap.h",0x1ee,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap.h",0x1ee,&DAT_8035fc8d);
    }
    this->mFmapSv[4] = uVar11;
    uVar11 = *(undefined *)&this->field_0x5119;
    if (this->mFmapSv == (undefined *)0x0) {
      uVar10 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar10,"d_menu_fmap.h",0x1f9,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap.h",0x1f9,&DAT_8035fc8d);
    }
    this->mFmapSv[5] = uVar11;
  }
  else {
    if (this->mFmapSv == (undefined *)0x0) {
      uVar10 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar10,"d_menu_fmap.h",500,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap.h",500,&DAT_8035fc8d);
    }
    if ((char)this->mFmapSv[5] < -3) goto LAB_801b0a18;
  }
  if (this->mFmapSv == (undefined *)0x0) {
    uVar10 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar10,"d_menu_fmap.h",0x215,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x215,&DAT_8035fc8d);
  }
  if (-4 < (char)this->mFmapSv[2]) {
    if (this->mFmapSv == (undefined *)0x0) {
      uVar10 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar10,"d_menu_fmap.h",0x21f,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap.h",0x21f,&DAT_8035fc8d);
    }
    if (-4 < (char)this->mFmapSv[3]) goto LAB_801b0c8c;
  }
  if (this->mFmapSv == (undefined *)0x0) {
    uVar10 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar10,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9,&DAT_8035fc8d);
  }
  uVar11 = this->mFmapSv[4];
  if (this->mFmapSv == (undefined *)0x0) {
    uVar10 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar10,"d_menu_fmap.h",0x21a,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x21a,&DAT_8035fc8d);
  }
  this->mFmapSv[2] = uVar11;
  if (this->mFmapSv == (undefined *)0x0) {
    uVar10 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar10,"d_menu_fmap.h",500,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",500,&DAT_8035fc8d);
  }
  uVar11 = this->mFmapSv[5];
  if (this->mFmapSv == (undefined *)0x0) {
    uVar10 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar10,"d_menu_fmap.h",0x224,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x224,&DAT_8035fc8d);
  }
  this->mFmapSv[3] = uVar11;
LAB_801b0c8c:
  if (this->mFmapSv == (undefined *)0x0) {
    uVar10 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar10,"d_menu_fmap.h",0x1d3,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x1d3,&DAT_8035fc8d);
  }
  cVar13 = *this->mFmapSv;
  if (cVar13 == '\x01') {
    *(undefined *)&this->field_0x5113 = 1;
    *(undefined *)&this->field_0x5169 = 1;
  }
  else {
    if (cVar13 == '\0') {
      if (this->mFmapSv == (char *)0x0) {
        uVar10 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar10,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
        m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9,&DAT_8035fc8d);
      }
      uVar11 = this->mFmapSv[4];
      if (this->mFmapSv == (undefined *)0x0) {
        uVar10 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar10,"d_menu_fmap.h",0x22f,"fmapSv != 0");
        m_Do_printf::OSPanic("d_menu_fmap.h",0x22f,&DAT_8035fc8d);
      }
      this->mFmapSv[10] = uVar11;
      if (this->mFmapSv == (undefined *)0x0) {
        uVar10 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar10,"d_menu_fmap.h",500,"fmapSv != 0");
        m_Do_printf::OSPanic("d_menu_fmap.h",500,&DAT_8035fc8d);
      }
      uVar11 = this->mFmapSv[5];
      if (this->mFmapSv == (undefined *)0x0) {
        uVar10 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar10,"d_menu_fmap.h",0x239,"fmapSv != 0");
        m_Do_printf::OSPanic("d_menu_fmap.h",0x239,&DAT_8035fc8d);
      }
      this->mFmapSv[0xb] = uVar11;
      *(undefined *)&this->field_0x5113 = 0;
      *(undefined *)&this->field_0x5169 = 0;
    }
  }
  *(undefined *)&this->field_0x5115 = 0;
  uStack28 = (int)DAT_803e60d2 ^ 0x80000000;
  local_20 = 0x43300000;
  paneTransBase(this,0,DAT_803e60d0,
                (float)((double)CONCAT44(0x43300000,uStack28) - d_menu_fmap::_4609),
                d_menu_fmap::_4256,'\0',0);
  *(undefined *)&this->field_0x5164 = 0;
  *(undefined *)&this->field_0x5165 = 0;
  if (this->mFmapSv == (undefined *)0x0) {
    uVar10 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar10,"d_menu_fmap.h",0x1e3,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x1e3,&DAT_8035fc8d);
  }
  this->mFmapSv[1] = 0;
  selGridMaskAlphaCtrl(this,0,DAT_803e60ca,'\0',0);
  fmapMaskAlphaCtrl(this,0,DAT_803e60ca,'\0',0);
  paneTranceZoomMap(this,0,DAT_803e60ca,d_menu_fmap::_4256,d_menu_fmap::_4256,d_menu_fmap::_4256,
                    d_menu_fmap::_4256,d_menu_fmap::_4271,d_menu_fmap::_4271,'\0',0);
  paneTranceZoom2Map(this,0,DAT_803e60ca,d_menu_fmap::_4256,d_menu_fmap::_4256,d_menu_fmap::_4256,
                     d_menu_fmap::_4256,d_menu_fmap::_4271,d_menu_fmap::_4271,'\0',0);
  paneAlphaFmapCursor(this,(fopMsgM_pane_class *)&this->field_0x2c0c,0,DAT_803e60d7,'\0',0);
  *(undefined *)&this->field_0x5114 = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dMenu_Fmap_c::displayinit(void) */

void __thiscall dMenu_Fmap_c::displayinit(dMenu_Fmap_c *this)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = 0;
  iVar5 = 0;
  do {
    uVar2 = dSv_player_map_c::isSaveArriveGrid
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,iVar4);
    uVar1 = countLeadingZeros(uVar2);
    setPaneOnOff(this,*(J2DScreen **)&this->field_0x20,*(ulong *)((int)&d_menu_fmap::hist + iVar5),
                 SUB41(uVar1 >> 5,0));
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + 4;
  } while (iVar4 < 0x31);
  iVar4 = 0;
  iVar6 = 0;
  iVar5 = 0;
  do {
    iVar3 = dSv_player_map_c::isSaveArriveGrid
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,
                       *(int *)((int)&d_menu_fmap::islandPos_4618 + iVar5) + -1);
    if (iVar3 == 0) {
      *(undefined *)(*(int *)(&this->field_0x39d4 + iVar6) + 0xaa) = 0;
    }
    else {
      *(undefined *)(*(int *)(&this->field_0x39d4 + iVar6) + 0xaa) = 1;
    }
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 0x38;
    iVar5 = iVar5 + 4;
  } while (iVar4 < 0xb);
  dispEndSalvageMark(this);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)&this->field_0x2dcc,
             (double)((float)((double)CONCAT44(0x43300000,
                                               (int)*(char *)&this->field_0x5118 ^ 0x80000000) -
                             d_menu_fmap::_4609) * *(float *)&this->field_0x2df0),
             (double)((float)((double)CONCAT44(0x43300000,
                                               (int)*(char *)&this->field_0x5119 ^ 0x80000000) -
                             d_menu_fmap::_4609) * *(float *)&this->field_0x2df4));
  setDspNormalMapLink(this);
  setDspLargeMapLink(this);
  selCursorInit(this);
  selCursorMove(this);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x4b54,d_menu_fmap::_4256);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)&this->field_0x4b54);
  changeIslandName(this,*(uchar *)&this->field_0x5140);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x29dc,d_menu_fmap::_4271);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)&this->field_0x29dc);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x2a14,d_menu_fmap::_4256);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)&this->field_0x2a14);
  changeSalvageGetItem(this,*(uchar *)&this->field_0x513d);
  playerPointGridAnimeInit(this);
  checkMarkCheck1(this);
  checkMarkCheck2(this);
  checkMarkCheck3(this);
  setDspWindAngle(this);
  calcGetMapCount(this);
  gShipMarkAnimeInit(this);
  *(undefined **)&this->field_0x34 = this->mFmapSv;
  dMenu_Fmap2_c::_create((dMenu_Fmap2_c *)&this->field_0x24);
  *(int *)&this->field_0x40 = &this->field_0x287c;
  dMenu_Fmap2_c::initialize((dMenu_Fmap2_c *)&this->field_0x24);
  dMenu_Fmap2_c::displayInit((dMenu_Fmap2_c *)&this->field_0x24);
  DAT_803e60a0 = mDoHIO_subRoot_c::createChild
                           (&mDoHIO_subRoot_c_803a5778,"フィールドマップ画面",
                            (JORReflexible *)&d_menu_fmap::g_mfHIO);
  return;
}


/* __thiscall dMenu_Fmap_c::backClothDispInit(void) */

void __thiscall dMenu_Fmap_c::backClothDispInit(dMenu_Fmap_c *this)

{
  *(undefined *)(*(int *)&this->field_0x28c4 + 0xaa) = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMenu_Fmap_c::calcGetMapCount(void) */

void __thiscall dMenu_Fmap_c::calcGetMapCount(dMenu_Fmap_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char acStack56 [36];
  
  iVar4 = 0;
  iVar2 = 0;
  iVar3 = 1;
  do {
    if ((iVar3 != 0x23) && (iVar3 != 0x24)) {
      iVar1 = dSv_player_map_c::isGetMap
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,iVar3 + -1);
      if (iVar1 != 0) {
        iVar4 = iVar4 + 1;
      }
      iVar1 = dSv_player_map_c::isCompleteMap
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,iVar3 + -1);
      if (iVar1 != 0) {
        iVar2 = iVar2 + 1;
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x34);
  MSL_C.PPCEABI.bare.H::sprintf(acStack56,"rupy_num_%02d.bti",iVar2 / 10);
  J2DPicture::changeTexture(*(J2DPicture **)&this->field_0x29a4,acStack56,0);
  MSL_C.PPCEABI.bare.H::sprintf(acStack56,"rupy_num_%02d.bti",iVar2 % 10);
  J2DPicture::changeTexture(*(J2DPicture **)&this->field_0x296c,acStack56,0);
  MSL_C.PPCEABI.bare.H::sprintf(acStack56,"rupy_num_%02d.bti",iVar4 / 10);
  J2DPicture::changeTexture(*(J2DPicture **)&this->field_0x2934,acStack56,0);
  MSL_C.PPCEABI.bare.H::sprintf(acStack56,"rupy_num_%02d.bti",iVar4 % 10);
  J2DPicture::changeTexture(*(J2DPicture **)&this->field_0x28fc,acStack56,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dMenu_Fmap_c::dispEndSalvageMark(void) */

void __thiscall dMenu_Fmap_c::dispEndSalvageMark(dMenu_Fmap_c *this)

{
  double dVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  fopMsgM_pane_class fStack104;
  undefined4 local_30;
  uint uStack44;
  undefined4 local_28;
  uint uStack36;
  
  iVar8 = 0;
  iVar7 = 0;
  iVar6 = 0;
  do {
    iVar4 = getGridNumToCmapDatPnt(this,iVar8);
    iVar5 = dSv_player_map_c::isCompleteMap
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,
                       *(char *)(iVar4 + 1) + -1);
    if (iVar5 == 0) {
      *(undefined *)(*(int *)(&this->field_0x3c3c + iVar6) + 0xaa) = 0;
    }
    else {
      f_op_msg_mng::fopMsgM_setPaneData
                (&fStack104,*(J2DScreen **)&this->field_0x20,
                 *(int *)((int)&d_menu_fmap::hist + iVar7));
      fVar3 = d_menu_fmap::_4719;
      fVar2 = d_menu_fmap::_4718;
      iVar4 = iVar4 + (uint)*(byte *)(this + 1) * 8;
      uStack44 = (int)*(short *)(iVar4 + 0xc) ^ 0x80000000;
      local_30 = 0x43300000;
      dVar1 = (double)CONCAT44(0x43300000,uStack44) - d_menu_fmap::_4609;
      uStack36 = (int)*(short *)(iVar4 + 10) ^ 0x80000000;
      local_28 = 0x43300000;
      iVar4 = &this->field_0x0 + iVar6;
      *(float *)(iVar4 + 0x3c50) =
           fStack104.mPosCenterOrig.x +
           (d_menu_fmap::_4718 * (float)((double)CONCAT44(0x43300000,uStack36) - d_menu_fmap::_4609)
           ) / d_menu_fmap::_4719;
      *(float *)(iVar4 + 0x3c54) = fStack104.mPosCenterOrig.y + (fVar2 * (float)dVar1) / fVar3;
      *(undefined4 *)(iVar4 + 0x3c58) = *(undefined4 *)(iVar4 + 0x3c50);
      *(undefined4 *)(iVar4 + 0x3c5c) = *(undefined4 *)(iVar4 + 0x3c54);
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(iVar4 + 0x3c3c));
      *(undefined *)(*(int *)(iVar4 + 0x3c3c) + 0xaa) = 1;
    }
    iVar8 = iVar8 + 1;
    iVar7 = iVar7 + 4;
    iVar6 = iVar6 + 0x38;
  } while (iVar8 < 0x31);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Fmap_c::checkMarkCheck1(void) */

void __thiscall dMenu_Fmap_c::checkMarkCheck1(dMenu_Fmap_c *this)

{
  int iVar1;
  
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1480);
  if (((iVar1 == 0) ||
      (iVar1 = dSv_event_c::isEventBit
                         (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1440),
      iVar1 == 0)) ||
     (iVar1 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1410),
     iVar1 == 0)) {
    iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xf80);
    if (iVar1 != 0) {
      *(undefined *)(*(int *)&this->field_0x46f4 + 0xaa) = 1;
    }
    iVar1 = dSv_player_collect_c::isSymbol
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x01');
    if (iVar1 != 0) {
      *(undefined *)(*(int *)&this->field_0x46f4 + 0xaa) = 0;
      *(undefined *)(*(int *)&this->field_0x4764 + 0xaa) = 1;
    }
    iVar1 = dSv_player_collect_c::isSymbol
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x02');
    if (iVar1 != 0) {
      *(undefined *)(*(int *)&this->field_0x4764 + 0xaa) = 0;
      *(undefined *)(*(int *)&this->field_0x472c + 0xaa) = 1;
    }
    iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1e80)
    ;
    if (iVar1 != 0) {
      *(undefined *)(*(int *)&this->field_0x472c + 0xaa) = 0;
    }
    iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3920)
    ;
    if (iVar1 != 0) {
      iVar1 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1480);
      if (iVar1 == 0) {
        *(undefined *)(*(int *)&this->field_0x479c + 0xaa) = 1;
      }
      else {
        *(undefined *)(*(int *)&this->field_0x479c + 0xaa) = 0;
      }
      iVar1 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1440);
      if (iVar1 == 0) {
        *(undefined *)(*(int *)&this->field_0x480c + 0xaa) = 1;
      }
      else {
        *(undefined *)(*(int *)&this->field_0x480c + 0xaa) = 0;
      }
      iVar1 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1410);
      if (iVar1 == 0) {
        *(undefined *)(*(int *)&this->field_0x47d4 + 0xaa) = 1;
      }
      else {
        *(undefined *)(*(int *)&this->field_0x47d4 + 0xaa) = 0;
      }
    }
  }
  return;
}


/* __thiscall dMenu_Fmap_c::checkMarkCheck2(void) */

void __thiscall dMenu_Fmap_c::checkMarkCheck2(dMenu_Fmap_c *this)

{
  int iVar1;
  
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1820);
  if (iVar1 != 0) {
    *(undefined *)(*(int *)&this->field_0x4844 + 0xaa) = 1;
    *(undefined *)(*(int *)&this->field_0x487c + 0xaa) = 1;
    iVar1 = d_com_inf_game::dComIfGs_isStageBossEnemy(6);
    if (iVar1 != 0) {
      *(undefined *)(*(int *)&this->field_0x487c + 0xaa) = 0;
    }
    iVar1 = d_com_inf_game::dComIfGs_isStageBossEnemy(7);
    if (iVar1 != 0) {
      *(undefined *)(*(int *)&this->field_0x4844 + 0xaa) = 0;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dMenu_Fmap_c::checkMarkCheck3(void) */

void __thiscall dMenu_Fmap_c::checkMarkCheck3(dMenu_Fmap_c *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  undefined uStack54;
  undefined uStack53;
  undefined uStack50;
  undefined uStack49;
  undefined local_2c;
  undefined uStack43;
  undefined local_24;
  undefined uStack35;
  
  iVar3 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x102);
  if ((iVar3 == 0) &&
     (iVar3 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3940),
     iVar3 != 0)) {
    uVar7 = 0;
    iVar3 = 0;
    do {
      iVar8 = 1;
      iVar4 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x102);
      if (iVar4 == 0) {
        uVar5 = dSv_event_c::getEventReg
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x9eff);
        if (((int)(uVar5 & 0xff) >> (uVar7 & 7) & 1U) == 0) {
          iVar8 = 0;
        }
      }
      uVar2 = DAT_803e6193;
      uVar1 = DAT_803e618f;
      if (iVar8 != 0) {
        uStack50 = (undefined)((uint)DAT_803e618f >> 8);
        uStack49 = (undefined)DAT_803e618f;
        uStack54 = (undefined)((uint)DAT_803e6193 >> 8);
        uStack53 = (undefined)DAT_803e6193;
        iVar4 = *(int *)(&this->field_0x48b4 + iVar3);
        local_24 = (undefined)((uint)DAT_803e6193 >> 0x18);
        *(undefined *)(iVar4 + 0x108) = local_24;
        uStack35 = (undefined)((uint)uVar2 >> 0x10);
        *(undefined *)(iVar4 + 0x109) = uStack35;
        *(undefined *)(iVar4 + 0x10a) = uStack54;
        *(undefined *)(iVar4 + 0x10b) = uStack53;
        local_2c = (undefined)((uint)uVar1 >> 0x18);
        *(undefined *)(iVar4 + 0x104) = local_2c;
        uStack43 = (undefined)((uint)uVar1 >> 0x10);
        *(undefined *)(iVar4 + 0x105) = uStack43;
        *(undefined *)(iVar4 + 0x106) = uStack50;
        *(undefined *)(iVar4 + 0x107) = uStack49;
      }
      iVar4 = &this->field_0x0 + iVar3;
      J2DPicture::changeTexture(*(J2DPicture **)(iVar4 + 0x48b4),(&d_menu_fmap::korogStat)[iVar8],0)
      ;
      *(undefined *)(*(int *)(iVar4 + 0x48b4) + 0xaa) = 1;
      cVar6 = dSv_player_item_c::checkBottle
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem,0x59);
      if (cVar6 == '\0') {
        *(undefined *)(iVar4 + 0x48e8) = 0x30;
        *(undefined *)(iVar4 + 0x48e9) = 0x30;
        f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(iVar4 + 0x48b4),d_menu_fmap::_4271)
        ;
      }
      else {
        *(undefined *)(iVar4 + 0x48e8) = 0xc0;
        *(undefined *)(iVar4 + 0x48e9) = 0xc0;
        f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(iVar4 + 0x48b4),d_menu_fmap::_4895)
        ;
      }
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar4 + 0x48b4));
      uVar7 = uVar7 + 1;
      iVar3 = iVar3 + 0x38;
    } while ((int)uVar7 < 8);
  }
  return;
}


/* __thiscall dMenu_Fmap_c::isFmapClose(void) */

undefined __thiscall dMenu_Fmap_c::isFmapClose(dMenu_Fmap_c *this)

{
  return *(undefined *)&this->field_0x510c;
}


/* __thiscall dMenu_Fmap_c::setPaneOnOff(J2DScreen *,
                                         unsigned long,
                                         bool) */

void __thiscall
dMenu_Fmap_c::setPaneOnOff(dMenu_Fmap_c *this,J2DScreen *param_1,ulong param_2,bool param_3)

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


/* __thiscall dMenu_Fmap_c::childPaneMoveSp(fopMsgM_pane_class *,
                                            fopMsgM_pane_class *,
                                            float,
                                            float,
                                            float) */

void __thiscall
dMenu_Fmap_c::childPaneMoveSp
          (dMenu_Fmap_c *this,fopMsgM_pane_class *param_1,fopMsgM_pane_class *param_2,float param_3,
          float param_4,float param_5)

{
  float fVar1;
  float fVar2;
  
  fVar2 = d_menu_fmap::_4260;
  fVar1 = (param_2->mSize).y * d_menu_fmap::_4260;
  (param_1->mPosCenter).x =
       (param_2->mSize).x * d_menu_fmap::_4260 +
       param_3 * ((param_1->mPosCenterOrig).x - (param_2->mSizeOrig).x * d_menu_fmap::_4260);
  (param_1->mPosCenter).y =
       fVar1 + param_3 * ((param_1->mPosCenterOrig).y - (param_2->mSizeOrig).y * fVar2);
  f_op_msg_mng::fopMsgM_paneScale((double)param_4,(double)param_5,param_1);
  return;
}


/* __thiscall dMenu_Fmap_c::selGridMaskAlphaCtrl(short,
                                                 unsigned char,
                                                 unsigned char,
                                                 int) */

undefined4 __thiscall
dMenu_Fmap_c::selGridMaskAlphaCtrl
          (dMenu_Fmap_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

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
          dVar2 = (double)(float)((double)d_menu_fmap::_4271 - dVar2);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x2e74,(float)dVar2);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)&this->field_0x2e74);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


/* __thiscall dMenu_Fmap_c::fmapMaskAlphaCtrl(short,
                                              unsigned char,
                                              unsigned char,
                                              int) */

undefined4 __thiscall
dMenu_Fmap_c::fmapMaskAlphaCtrl
          (dMenu_Fmap_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

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
          dVar2 = (double)(float)((double)d_menu_fmap::_4271 - dVar2);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x2eac,(float)dVar2);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)&this->field_0x2eac);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


/* __thiscall dMenu_Fmap_c::selCursorInit(void) */

void __thiscall dMenu_Fmap_c::selCursorInit(dMenu_Fmap_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(undefined *)&this->field_0x510d = 0;
  iVar1 = 0;
  iVar3 = 4;
  do {
    iVar2 = &this->field_0x0 + iVar1;
    *(undefined *)(*(int *)(iVar2 + 0x2a4c) + 0xaa) = 1;
    *(undefined *)(*(int *)(iVar2 + 0x2b2c) + 0xaa) = 0;
    iVar1 = iVar1 + 0x38;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(ushort *)&this->field_0x2a82 = (ushort)DAT_803e60d6;
  return;
}


/* __thiscall dMenu_Fmap_c::selCursorHide(void) */

void __thiscall dMenu_Fmap_c::selCursorHide(dMenu_Fmap_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 8;
  do {
    *(undefined *)(*(int *)(&this->field_0x2a4c + iVar1) + 0xaa) = 0;
    iVar1 = iVar1 + 0x38;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x801b1cc8) */
/* WARNING: Removing unreachable block (ram,0x801b1cd0) */
/* __thiscall dMenu_Fmap_c::selCursorMove(void) */

void __thiscall dMenu_Fmap_c::selCursorMove(dMenu_Fmap_c *this)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 in_f30;
  double y;
  undefined8 in_f31;
  double x;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (this->mFmapSv == (undefined *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9,&DAT_8035fc8d);
  }
  x = (double)(d_menu_fmap::_4718 *
              (float)((double)CONCAT44(0x43300000,(int)(char)this->mFmapSv[4] ^ 0x80000000) -
                     d_menu_fmap::_4609));
  if (this->mFmapSv == (undefined *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap.h",500,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",500,&DAT_8035fc8d);
  }
  y = (double)(d_menu_fmap::_4718 *
              (float)((double)CONCAT44(0x43300000,(int)(char)this->mFmapSv[5] ^ 0x80000000) -
                     d_menu_fmap::_4609));
  iVar2 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(&this->field_0x2a4c + iVar3),x,y);
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar2 < 8);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)&this->field_0x2e74,x,y);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return;
}


/* __thiscall dMenu_Fmap_c::islandNameChange(void) */

void __thiscall dMenu_Fmap_c::islandNameChange(dMenu_Fmap_c *this)

{
  if (*(char *)&this->field_0x5142 == '\x01') {
    AreaTxtChgFast(this);
  }
  else {
    *(undefined *)&this->field_0x5142 = 1;
  }
  changeIslandName(this,*(byte *)&this->field_0x5140 ^ 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Fmap_c::changeIslandName(unsigned char) */

void __thiscall dMenu_Fmap_c::changeIslandName(dMenu_Fmap_c *this,uchar param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  ulong uVar4;
  int iVar5;
  int iVar6;
  undefined uStack54;
  undefined uStack53;
  undefined uStack50;
  undefined uStack49;
  undefined local_30;
  undefined uStack47;
  undefined local_2c;
  undefined uStack43;
  
  if (this->mFmapSv == (undefined *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_menu_fmap.h",500,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",500,&DAT_8035fc8d);
  }
  cVar1 = this->mFmapSv[5];
  if (this->mFmapSv == (undefined *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9,&DAT_8035fc8d);
  }
  iVar6 = (int)(char)this->mFmapSv[4] + (cVar1 + 3) * 7 + 3;
  iVar5 = dSv_player_map_c::isSaveArriveGrid
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,iVar6);
  if (iVar5 == 0) {
    **(undefined **)(&this->field_0x5148 + (uint)param_1 * 4) = 0;
  }
  else {
    if ((iVar6 == 0x20) &&
       (iVar5 = dSv_event_c::isEventBit
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2d80),
       iVar5 != 0)) {
      iVar5 = 0x31d7;
    }
    else {
      iVar5 = iVar6 + 0x31a6;
    }
    uVar3 = DAT_803e619c;
    uVar2 = DAT_803e6198;
    if ((((((iVar6 == 0) || (iVar6 == 3)) || (iVar6 == 10)) || ((iVar6 == 0xc || (iVar6 == 0x13))))
        || ((iVar6 == 0x16 || ((iVar6 == 0x19 || (iVar6 - 0x27U < 2)))))) ||
       ((iVar6 == 0x2b || (iVar6 == 0x2c)))) {
      uStack50 = (undefined)((uint)DAT_803e619c >> 8);
      uStack49 = (undefined)DAT_803e619c;
      iVar6 = *(int *)(&this->field_0x4b1c + (uint)param_1 * 0x38);
      local_2c = (undefined)((uint)DAT_803e619c >> 0x18);
      *(undefined *)(iVar6 + 0xd0) = local_2c;
      uStack43 = (undefined)((uint)uVar3 >> 0x10);
      *(undefined *)(iVar6 + 0xd1) = uStack43;
      *(undefined *)(iVar6 + 0xd2) = uStack50;
      *(undefined *)(iVar6 + 0xd3) = uStack49;
    }
    else {
      uStack54 = (undefined)((uint)DAT_803e6198 >> 8);
      uStack53 = (undefined)DAT_803e6198;
      iVar6 = *(int *)(&this->field_0x4b1c + (uint)param_1 * 0x38);
      local_30 = (undefined)((uint)DAT_803e6198 >> 0x18);
      *(undefined *)(iVar6 + 0xd0) = local_30;
      uStack47 = (undefined)((uint)uVar2 >> 0x10);
      *(undefined *)(iVar6 + 0xd1) = uStack47;
      *(undefined *)(iVar6 + 0xd2) = uStack54;
      *(undefined *)(iVar6 + 0xd3) = uStack53;
    }
    f_op_msg_mng::fopMsgM_messageGet(*(undefined4 *)(&this->field_0x5148 + (uint)param_1 * 4),iVar5)
    ;
  }
  return;
}


/* __thiscall dMenu_Fmap_c::AreaTxtChg(void) */

void __thiscall dMenu_Fmap_c::AreaTxtChg(dMenu_Fmap_c *this)

{
  int iVar1;
  
  if (*(char *)&this->field_0x5142 != '\0') {
    iVar1 = PaneAlphaAreaTxt(this,(ushort)*(byte *)&this->field_0x5141,DAT_803e60ce,0);
    *(char *)&this->field_0x5141 = *(char *)&this->field_0x5141 + '\x01';
    if (iVar1 == 1) {
      *(byte *)&this->field_0x5140 = *(byte *)&this->field_0x5140 ^ 1;
      *(undefined *)&this->field_0x5141 = 0;
      *(undefined *)&this->field_0x5142 = 0;
    }
  }
  return;
}


/* __thiscall dMenu_Fmap_c::AreaTxtChgFast(void) */

void __thiscall dMenu_Fmap_c::AreaTxtChgFast(dMenu_Fmap_c *this)

{
  *(undefined *)&this->field_0x5141 = 0;
  f_op_msg_mng::fopMsgM_setNowAlpha
            ((fopMsgM_pane_class *)(&this->field_0x4b1c + (*(byte *)&this->field_0x5140 ^ 1) * 0x38)
             ,d_menu_fmap::_4271);
  f_op_msg_mng::fopMsgM_setAlpha
            ((fopMsgM_pane_class *)(&this->field_0x4b1c + (*(byte *)&this->field_0x5140 ^ 1) * 0x38)
            );
  f_op_msg_mng::fopMsgM_setNowAlpha
            ((fopMsgM_pane_class *)(&this->field_0x4b1c + (uint)*(byte *)&this->field_0x5140 * 0x38)
             ,d_menu_fmap::_4256);
  f_op_msg_mng::fopMsgM_setAlpha
            ((fopMsgM_pane_class *)(&this->field_0x4b1c + (uint)*(byte *)&this->field_0x5140 * 0x38)
            );
  *(byte *)&this->field_0x5140 = *(byte *)&this->field_0x5140 ^ 1;
  return;
}


/* __thiscall dMenu_Fmap_c::salvageGetItemChg(void) */

void __thiscall dMenu_Fmap_c::salvageGetItemChg(dMenu_Fmap_c *this)

{
  int iVar1;
  
  if (*(char *)&this->field_0x513f != '\0') {
    iVar1 = PaneAlphaSelvageItem(this,(ushort)*(byte *)&this->field_0x513e,DAT_803e60ce);
    *(char *)&this->field_0x513e = *(char *)&this->field_0x513e + '\x01';
    if (iVar1 == 1) {
      *(byte *)&this->field_0x513d = *(byte *)&this->field_0x513d ^ 1;
      *(undefined *)&this->field_0x513e = 0;
      *(undefined *)&this->field_0x513f = 0;
    }
  }
  return;
}


/* __thiscall dMenu_Fmap_c::salvageGetItemChange(void) */

void __thiscall dMenu_Fmap_c::salvageGetItemChange(dMenu_Fmap_c *this)

{
  if (*(char *)&this->field_0x513f == '\x01') {
    SalvItmDispChgFast(this);
  }
  else {
    *(undefined *)&this->field_0x513f = 1;
  }
  changeSalvageGetItem(this,*(byte *)&this->field_0x513d ^ 1);
  return;
}


/* __thiscall dMenu_Fmap_c::SalvItmDispChgFast(void) */

void __thiscall dMenu_Fmap_c::SalvItmDispChgFast(dMenu_Fmap_c *this)

{
  *(undefined *)&this->field_0x513e = 0;
  if (*(char *)&this->field_0x513c == '\x01') {
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)
               (&this->field_0x29dc + (*(byte *)&this->field_0x513d ^ 1) * 0x38),d_menu_fmap::_4271)
    ;
  }
  else {
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)
               (&this->field_0x29dc + (*(byte *)&this->field_0x513d ^ 1) * 0x38),d_menu_fmap::_4256)
    ;
  }
  f_op_msg_mng::fopMsgM_setAlpha
            ((fopMsgM_pane_class *)(&this->field_0x29dc + (*(byte *)&this->field_0x513d ^ 1) * 0x38)
            );
  f_op_msg_mng::fopMsgM_setNowAlpha
            ((fopMsgM_pane_class *)(&this->field_0x29dc + (uint)*(byte *)&this->field_0x513d * 0x38)
             ,d_menu_fmap::_4256);
  f_op_msg_mng::fopMsgM_setAlpha
            ((fopMsgM_pane_class *)(&this->field_0x29dc + (uint)*(byte *)&this->field_0x513d * 0x38)
            );
  *(byte *)&this->field_0x513d = *(byte *)&this->field_0x513d ^ 1;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Fmap_c::changeSalvageGetItem(unsigned char) */

void __thiscall dMenu_Fmap_c::changeSalvageGetItem(dMenu_Fmap_c *this,uchar param_1)

{
  char cVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  fopMsgM_pane_class *this_00;
  
  if (this->mFmapSv == (undefined *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",500,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",500,&DAT_8035fc8d);
  }
  cVar1 = this->mFmapSv[5];
  if (this->mFmapSv == (undefined *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9,&DAT_8035fc8d);
  }
  iVar3 = getGridNumToCmapDatPnt(this,(int)(char)this->mFmapSv[4] + (cVar1 + 3) * 7 + 3);
  iVar4 = dSv_player_map_c::isCompleteMap
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,
                     *(char *)(iVar3 + 1) + -1);
  if (iVar4 == 0) {
    *(undefined *)&this->field_0x513c = 0;
    this_00 = (fopMsgM_pane_class *)(&this->field_0x29dc + (uint)param_1 * 0x38);
    f_op_msg_mng::fopMsgM_setNowAlpha(this_00,d_menu_fmap::_4256);
    f_op_msg_mng::fopMsgM_setAlpha(this_00);
  }
  else {
    *(undefined *)&this->field_0x513c = 1;
    J2DPicture::changeTexture
              (*(J2DPicture **)(&this->field_0x29dc + (uint)param_1 * 0x38),
               (&d_menu_fmap::salvItemex)[*(char *)(iVar3 + 3)],0);
  }
  return;
}


/* __thiscall dMenu_Fmap_c::selCursorAnime(void) */

void __thiscall dMenu_Fmap_c::selCursorAnime(dMenu_Fmap_c *this)

{
  int iVar1;
  int iVar2;
  
  if (*(short *)&this->field_0x2a82 == 0) {
    iVar1 = 0;
    iVar2 = 4;
    do {
      *(undefined *)
       (*(int *)(&this->field_0x2a4c + (iVar1 + (*(byte *)&this->field_0x510d ^ 1) * 4) * 0x38) +
       0xaa) = 1;
      *(undefined *)
       (*(int *)(&this->field_0x2a4c + (iVar1 + (uint)*(byte *)&this->field_0x510d * 4) * 0x38) +
       0xaa) = 0;
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(byte *)&this->field_0x510d = *(byte *)&this->field_0x510d ^ 1;
    *(ushort *)&this->field_0x2a82 = (ushort)DAT_803e60d6;
    return;
  }
  *(short *)&this->field_0x2a82 = *(short *)&this->field_0x2a82 + -1;
  return;
}


/* __thiscall dMenu_Fmap_c::zoomCursorInit(void) */

void __thiscall dMenu_Fmap_c::zoomCursorInit(dMenu_Fmap_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(undefined *)&this->field_0x510e = 0;
  iVar1 = 0;
  iVar3 = 4;
  do {
    iVar2 = &this->field_0x0 + iVar1;
    *(undefined *)(*(int *)(iVar2 + 0x2c0c) + 0xaa) = 1;
    *(undefined *)(*(int *)(iVar2 + 0x2cec) + 0xaa) = 0;
    iVar1 = iVar1 + 0x38;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(ushort *)&this->field_0x2c42 = (ushort)DAT_803e60d6;
  return;
}


/* __thiscall dMenu_Fmap_c::zoomCursorAnime(void) */

void __thiscall dMenu_Fmap_c::zoomCursorAnime(dMenu_Fmap_c *this)

{
  int iVar1;
  int iVar2;
  
  if (*(short *)&this->field_0x2c42 == 0) {
    iVar1 = 0;
    iVar2 = 4;
    do {
      *(undefined *)
       (*(int *)(&this->field_0x2c0c + (iVar1 + (*(byte *)&this->field_0x510e ^ 1) * 4) * 0x38) +
       0xaa) = 1;
      *(undefined *)
       (*(int *)(&this->field_0x2c0c + (iVar1 + (uint)*(byte *)&this->field_0x510e * 4) * 0x38) +
       0xaa) = 0;
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(byte *)&this->field_0x510e = *(byte *)&this->field_0x510e ^ 1;
    *(ushort *)&this->field_0x2c42 = (ushort)DAT_803e60d6;
    return;
  }
  *(short *)&this->field_0x2c42 = *(short *)&this->field_0x2c42 + -1;
  return;
}


/* __thiscall dMenu_Fmap_c::playerPointGridAnimeInit(void) */

void __thiscall dMenu_Fmap_c::playerPointGridAnimeInit(dMenu_Fmap_c *this)

{
  *(char *)&this->field_0x510f = (char)DAT_803e60c4;
  *(undefined *)&this->field_0x5110 = 0;
  return;
}


/* __thiscall dMenu_Fmap_c::playerPointGridAnime(void) */

void __thiscall dMenu_Fmap_c::playerPointGridAnime(dMenu_Fmap_c *this)

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
  undefined uVar11;
  undefined uVar12;
  int iVar13;
  double dVar14;
  
  dVar14 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                             ((int)DAT_803e60c4,*(undefined *)&this->field_0x510f,2);
  if (*(char *)&this->field_0x5110 == '\0') {
    dVar14 = (double)(float)((double)d_menu_fmap::_4271 - dVar14);
  }
  dVar1 = (double)CONCAT44(0x43300000,(uint)DAT_803e60b6) - d_menu_fmap::_5228;
  dVar2 = (double)CONCAT44(0x43300000,(uint)DAT_803e60be - (uint)DAT_803e60b6 ^ 0x80000000) -
          d_menu_fmap::_4609;
  dVar3 = (double)CONCAT44(0x43300000,(uint)DAT_803e60b7) - d_menu_fmap::_5228;
  dVar4 = (double)CONCAT44(0x43300000,(uint)DAT_803e60bf - (uint)DAT_803e60b7 ^ 0x80000000) -
          d_menu_fmap::_4609;
  dVar5 = (double)CONCAT44(0x43300000,(uint)DAT_803e60b8) - d_menu_fmap::_5228;
  dVar6 = (double)CONCAT44(0x43300000,(uint)DAT_803e60c0 - (uint)DAT_803e60b8 ^ 0x80000000) -
          d_menu_fmap::_4609;
  uVar11 = *(undefined *)&this->field_0x5166;
  dVar7 = (double)CONCAT44(0x43300000,(uint)DAT_803e60b3) - d_menu_fmap::_5228;
  dVar8 = (double)CONCAT44(0x43300000,(uint)DAT_803e60bb - (uint)DAT_803e60b3 ^ 0x80000000) -
          d_menu_fmap::_4609;
  dVar9 = (double)CONCAT44(0x43300000,(uint)DAT_803e60b4) - d_menu_fmap::_5228;
  dVar10 = (double)CONCAT44(0x43300000,(uint)DAT_803e60bc - (uint)DAT_803e60b4 ^ 0x80000000) -
           d_menu_fmap::_4609;
  uVar12 = *(undefined *)&this->field_0x5167;
  iVar13 = *(int *)&this->field_0x2dcc;
  *(char *)(iVar13 + 0x104) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)DAT_803e60b2) - d_menu_fmap::_5228) +
                  (float)(dVar14 * (double)(float)((double)CONCAT44(0x43300000,
                                                                    (uint)DAT_803e60ba -
                                                                    (uint)DAT_803e60b2 ^ 0x80000000)
                                                  - d_menu_fmap::_4609)));
  *(char *)(iVar13 + 0x105) = (char)(int)((float)dVar7 + (float)(dVar14 * (double)(float)dVar8));
  *(char *)(iVar13 + 0x106) = (char)(int)((float)dVar9 + (float)(dVar14 * (double)(float)dVar10));
  *(undefined *)(iVar13 + 0x107) = uVar12;
  iVar13 = *(int *)&this->field_0x2dcc;
  *(char *)(iVar13 + 0x108) = (char)(int)((float)dVar1 + (float)(dVar14 * (double)(float)dVar2));
  *(char *)(iVar13 + 0x109) = (char)(int)((float)dVar3 + (float)(dVar14 * (double)(float)dVar4));
  *(char *)(iVar13 + 0x10a) = (char)(int)((float)dVar5 + (float)(dVar14 * (double)(float)dVar6));
  *(undefined *)(iVar13 + 0x10b) = uVar11;
  if (*(char *)&this->field_0x510f == '\0') {
    *(char *)&this->field_0x510f = (char)DAT_803e60c4;
    *(byte *)&this->field_0x5110 = *(byte *)&this->field_0x5110 ^ 1;
  }
  else {
    *(char *)&this->field_0x510f = *(char *)&this->field_0x510f + -1;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x801b29f4) */
/* __thiscall dMenu_Fmap_c::setDspWindAngle(void) */

void __thiscall dMenu_Fmap_c::setDspWindAngle(dMenu_Fmap_c *this)

{
  double dVar1;
  cXyz *pcVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  pcVar2 = d_kankyo_wether::dKyw_get_wind_vec();
  iVar3 = SComponent::cM_atan2s(pcVar2->x,pcVar2->z);
  dVar6 = MSL_C.PPCEABI.bare.H::fmod
                    ((double)((d_menu_fmap::_4606 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)(short)((short)iVar3 + -0x8000) ^
                                                       0x80000000) - d_menu_fmap::_4609)) /
                             d_menu_fmap::_4607),d_menu_fmap::_5261);
  dVar7 = (double)(float)dVar6;
  dVar1 = (double)CONCAT44(0x43300000,
                           (int)(d_menu_fmap::_4260 * *(float *)&this->field_0x4a9c +
                                (float)((double)CONCAT44(0x43300000,(int)DAT_803e60b0 ^ 0x80000000)
                                       - d_menu_fmap::_4609)) ^ 0x80000000) - d_menu_fmap::_4609;
  piVar4 = *(int **)&this->field_0x4a74;
  piVar4[0x27] = (int)(float)((double)CONCAT44(0x43300000,
                                               (int)(*(float *)&this->field_0x4a98 +
                                                    (float)((double)CONCAT44(0x43300000,
                                                                             (int)DAT_803e60ae ^
                                                                             0x80000000) -
                                                           d_menu_fmap::_4609)) ^ 0x80000000) -
                             d_menu_fmap::_4609);
  piVar4[0x28] = (int)(float)dVar1;
  *(undefined *)(piVar4 + 0x2a) = 0x7a;
  piVar4[0x29] = (int)(float)dVar6;
  (**(code **)(*piVar4 + 0x20))();
  dVar1 = (double)CONCAT44(0x43300000,
                           (int)(d_menu_fmap::_4260 * *(float *)&this->field_0x4ad4 +
                                (float)((double)CONCAT44(0x43300000,(int)DAT_803e60b0 ^ 0x80000000)
                                       - d_menu_fmap::_4609)) ^ 0x80000000) - d_menu_fmap::_4609;
  piVar4 = *(int **)&this->field_0x4aac;
  piVar4[0x27] = (int)(float)((double)CONCAT44(0x43300000,(int)DAT_803e60ae ^ 0x80000000) -
                             d_menu_fmap::_4609);
  piVar4[0x28] = (int)(float)dVar1;
  *(undefined *)(piVar4 + 0x2a) = 0x7a;
  piVar4[0x29] = (int)(float)dVar7;
  (**(code **)(*piVar4 + 0x20))();
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMenu_Fmap_c::windArrowColorAnime(void) */

void __thiscall dMenu_Fmap_c::windArrowColorAnime(dMenu_Fmap_c *this)

{
  float fVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  double dVar11;
  undefined local_94;
  undefined uStack147;
  undefined uStack146;
  undefined uStack145;
  undefined local_8c;
  undefined uStack139;
  undefined uStack138;
  undefined uStack137;
  uint local_78;
  uint local_74;
  double local_70;
  double local_68;
  double local_60;
  double local_58;
  double local_48;
  double local_40;
  double local_30;
  double local_28;
  double local_18;
  
  dVar11 = d_kankyo_wether::dKyw_get_wind_pow();
  sVar2 = DAT_803e60c8;
  fVar1 = d_menu_fmap::_4260 + (float)((double)d_menu_fmap::_5417 * dVar11);
  local_70 = (double)CONCAT44(0x43300000,(int)DAT_803e60c2 ^ 0x80000000);
  local_70 = local_70 - d_menu_fmap::_4609;
  iVar9 = (int)DAT_803e60c6;
  iVar8 = (int)DAT_803e60c8;
  *(short *)&this->field_0x4aaa = *(short *)&this->field_0x4aaa + 1;
  sVar7 = (short)(int)((float)local_70 - fVar1);
  iVar10 = (int)sVar7;
  iVar4 = iVar9 + iVar10 * 2;
  if ((short)(sVar2 + (short)iVar4) < *(short *)&this->field_0x4aaa) {
    *(undefined2 *)&this->field_0x4aaa = 0;
  }
  iVar3 = (int)*(short *)&this->field_0x4aaa;
  if (iVar3 < sVar7) {
    dVar11 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar10,iVar3,0);
    local_68 = (double)CONCAT44(0x43300000,_DAT_803e60a9 >> 0x18);
    local_70 = (double)CONCAT44(0x43300000,
                                (_DAT_803e60a5 >> 0x18) - (_DAT_803e60a9 >> 0x18) ^ 0x80000000);
    uVar5 = _DAT_803e60a9 >> 0x10 & 0xff;
    local_58 = (double)CONCAT44(0x43300000,uVar5);
    uVar6 = _DAT_803e60a9 >> 8 & 0xff;
    local_40 = (double)CONCAT44(0x43300000,uVar6);
    local_28 = (double)CONCAT44(0x43300000,_DAT_803e60a9 & 0xff);
    local_74 = (int)((float)(local_28 - d_menu_fmap::_5228) +
                    (float)(dVar11 * (double)(float)((double)CONCAT44(0x43300000,
                                                                      (_DAT_803e60a5 & 0xff) -
                                                                      (_DAT_803e60a9 & 0xff) ^
                                                                      0x80000000) -
                                                    d_menu_fmap::_4609))) & 0xffU |
               (uint)CONCAT21(CONCAT11((char)(int)((float)(local_68 - d_menu_fmap::_5228) +
                                                  (float)(dVar11 * (double)(float)(local_70 -
                                                                                  d_menu_fmap::_4609
                                                                                  ))),
                                       (char)(int)((float)(local_58 - d_menu_fmap::_5228) +
                                                  (float)(dVar11 * (double)(float)((double)CONCAT44(
                                                  0x43300000,
                                                  (_DAT_803e60a5 >> 0x10 & 0xff) - uVar5 ^
                                                  0x80000000) - d_menu_fmap::_4609)))),
                              (char)(int)((float)(local_40 - d_menu_fmap::_5228) +
                                         (float)(dVar11 * (double)(float)((double)CONCAT44(
                                                  0x43300000,
                                                  (_DAT_803e60a5 >> 8 & 0xff) - uVar6 ^ 0x80000000)
                                                  - d_menu_fmap::_4609)))) << 8;
  }
  else {
    if (iVar3 < iVar10 + iVar9) {
      local_74 = _DAT_803e60a5;
    }
    else {
      if (iVar3 < iVar4) {
        dVar11 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar10,iVar4 - iVar3,0);
        local_18 = (double)CONCAT44(0x43300000,_DAT_803e60a9 >> 0x18);
        uVar5 = _DAT_803e60a9 >> 0x10 & 0xff;
        local_30 = (double)CONCAT44(0x43300000,uVar5);
        uVar6 = _DAT_803e60a9 >> 8 & 0xff;
        local_48 = (double)CONCAT44(0x43300000,uVar6);
        local_60 = (double)CONCAT44(0x43300000,_DAT_803e60a9 & 0xff);
        local_68 = (double)CONCAT44(0x43300000,
                                    (_DAT_803e60a5 & 0xff) - (_DAT_803e60a9 & 0xff) ^ 0x80000000);
        local_74 = (int)((float)(local_60 - d_menu_fmap::_5228) +
                        (float)(dVar11 * (double)(float)(local_68 - d_menu_fmap::_4609))) & 0xffU |
                   (uint)CONCAT21(CONCAT11((char)(int)((float)(local_18 - d_menu_fmap::_5228) +
                                                      (float)(dVar11 * (double)(float)((double)
                                                  CONCAT44(0x43300000,
                                                           (_DAT_803e60a5 >> 0x18) -
                                                           (_DAT_803e60a9 >> 0x18) ^ 0x80000000) -
                                                  d_menu_fmap::_4609))),
                                           (char)(int)((float)(local_30 - d_menu_fmap::_5228) +
                                                      (float)(dVar11 * (double)(float)((double)
                                                  CONCAT44(0x43300000,
                                                           (_DAT_803e60a5 >> 0x10 & 0xff) - uVar5 ^
                                                           0x80000000) - d_menu_fmap::_4609)))),
                                  (char)(int)((float)(local_48 - d_menu_fmap::_5228) +
                                             (float)(dVar11 * (double)(float)((double)CONCAT44(
                                                  0x43300000,
                                                  (_DAT_803e60a5 >> 8 & 0xff) - uVar6 ^ 0x80000000)
                                                  - d_menu_fmap::_4609)))) << 8;
      }
      else {
        local_74 = _DAT_803e60a9;
      }
    }
  }
  iVar4 = (int)*(short *)&this->field_0x4aaa;
  if (iVar4 < iVar9) {
    local_78 = _DAT_803e60a5;
  }
  else {
    iVar9 = iVar10 + iVar9;
    if (iVar4 < iVar9) {
      dVar11 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar10,iVar9 - iVar4,0);
      local_18 = (double)CONCAT44(0x43300000,_DAT_803e60a9 >> 0x18);
      uVar5 = _DAT_803e60a9 >> 0x10 & 0xff;
      local_30 = (double)CONCAT44(0x43300000,uVar5);
      uVar6 = _DAT_803e60a9 >> 8 & 0xff;
      local_48 = (double)CONCAT44(0x43300000,uVar6);
      local_60 = (double)CONCAT44(0x43300000,_DAT_803e60a9 & 0xff);
      local_68 = (double)CONCAT44(0x43300000,
                                  (_DAT_803e60a5 & 0xff) - (_DAT_803e60a9 & 0xff) ^ 0x80000000);
      local_78 = (int)((float)(local_60 - d_menu_fmap::_5228) +
                      (float)(dVar11 * (double)(float)(local_68 - d_menu_fmap::_4609))) & 0xffU |
                 (uint)CONCAT21(CONCAT11((char)(int)((float)(local_18 - d_menu_fmap::_5228) +
                                                    (float)(dVar11 * (double)(float)((double)
                                                  CONCAT44(0x43300000,
                                                           (_DAT_803e60a5 >> 0x18) -
                                                           (_DAT_803e60a9 >> 0x18) ^ 0x80000000) -
                                                  d_menu_fmap::_4609))),
                                         (char)(int)((float)(local_30 - d_menu_fmap::_5228) +
                                                    (float)(dVar11 * (double)(float)((double)
                                                  CONCAT44(0x43300000,
                                                           (_DAT_803e60a5 >> 0x10 & 0xff) - uVar5 ^
                                                           0x80000000) - d_menu_fmap::_4609)))),
                                (char)(int)((float)(local_48 - d_menu_fmap::_5228) +
                                           (float)(dVar11 * (double)(float)((double)CONCAT44(
                                                  0x43300000,
                                                  (_DAT_803e60a5 >> 8 & 0xff) - uVar6 ^ 0x80000000)
                                                  - d_menu_fmap::_4609)))) << 8;
    }
    else {
      if (iVar4 < iVar8 + iVar9) {
        local_78 = _DAT_803e60a9;
      }
      else {
        dVar11 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar10,iVar4 - (iVar8 + iVar9),0);
        local_18 = (double)CONCAT44(0x43300000,_DAT_803e60a9 >> 0x18);
        uVar5 = _DAT_803e60a9 >> 0x10 & 0xff;
        local_30 = (double)CONCAT44(0x43300000,uVar5);
        uVar6 = _DAT_803e60a9 >> 8 & 0xff;
        local_48 = (double)CONCAT44(0x43300000,uVar6);
        local_60 = (double)CONCAT44(0x43300000,_DAT_803e60a9 & 0xff);
        local_68 = (double)CONCAT44(0x43300000,
                                    (_DAT_803e60a5 & 0xff) - (_DAT_803e60a9 & 0xff) ^ 0x80000000);
        local_78 = (int)((float)(local_60 - d_menu_fmap::_5228) +
                        (float)(dVar11 * (double)(float)(local_68 - d_menu_fmap::_4609))) & 0xffU |
                   (uint)CONCAT21(CONCAT11((char)(int)((float)(local_18 - d_menu_fmap::_5228) +
                                                      (float)(dVar11 * (double)(float)((double)
                                                  CONCAT44(0x43300000,
                                                           (_DAT_803e60a5 >> 0x18) -
                                                           (_DAT_803e60a9 >> 0x18) ^ 0x80000000) -
                                                  d_menu_fmap::_4609))),
                                           (char)(int)((float)(local_30 - d_menu_fmap::_5228) +
                                                      (float)(dVar11 * (double)(float)((double)
                                                  CONCAT44(0x43300000,
                                                           (_DAT_803e60a5 >> 0x10 & 0xff) - uVar5 ^
                                                           0x80000000) - d_menu_fmap::_4609)))),
                                  (char)(int)((float)(local_48 - d_menu_fmap::_5228) +
                                             (float)(dVar11 * (double)(float)((double)CONCAT44(
                                                  0x43300000,
                                                  (_DAT_803e60a5 >> 8 & 0xff) - uVar6 ^ 0x80000000)
                                                  - d_menu_fmap::_4609)))) << 8;
      }
    }
  }
  iVar9 = *(int *)&this->field_0x4a74;
  local_8c = (undefined)(local_74 >> 0x18);
  *(undefined *)(iVar9 + 0x10c) = local_8c;
  uStack139 = (undefined)(local_74 >> 0x10);
  *(undefined *)(iVar9 + 0x10d) = uStack139;
  uStack138 = (undefined)(local_74 >> 8);
  *(undefined *)(iVar9 + 0x10e) = uStack138;
  uStack137 = (undefined)local_74;
  *(undefined *)(iVar9 + 0x10f) = uStack137;
  *(undefined *)(iVar9 + 0x110) = local_8c;
  *(undefined *)(iVar9 + 0x111) = uStack139;
  *(undefined *)(iVar9 + 0x112) = uStack138;
  *(undefined *)(iVar9 + 0x113) = uStack137;
  local_94 = (undefined)(local_78 >> 0x18);
  *(undefined *)(iVar9 + 0x114) = local_94;
  uStack147 = (undefined)(local_78 >> 0x10);
  *(undefined *)(iVar9 + 0x115) = uStack147;
  uStack146 = (undefined)(local_78 >> 8);
  *(undefined *)(iVar9 + 0x116) = uStack146;
  uStack145 = (undefined)local_78;
  *(undefined *)(iVar9 + 0x117) = uStack145;
  *(undefined *)(iVar9 + 0x118) = local_94;
  *(undefined *)(iVar9 + 0x119) = uStack147;
  *(undefined *)(iVar9 + 0x11a) = uStack146;
  *(undefined *)(iVar9 + 0x11b) = uStack145;
  iVar9 = *(int *)&this->field_0x4aac;
  *(undefined *)(iVar9 + 0x10c) = local_8c;
  *(undefined *)(iVar9 + 0x10d) = uStack139;
  *(undefined *)(iVar9 + 0x10e) = uStack138;
  *(undefined *)(iVar9 + 0x10f) = uStack137;
  *(undefined *)(iVar9 + 0x110) = local_8c;
  *(undefined *)(iVar9 + 0x111) = uStack139;
  *(undefined *)(iVar9 + 0x112) = uStack138;
  *(undefined *)(iVar9 + 0x113) = uStack137;
  *(undefined *)(iVar9 + 0x114) = local_94;
  *(undefined *)(iVar9 + 0x115) = uStack147;
  *(undefined *)(iVar9 + 0x116) = uStack146;
  *(undefined *)(iVar9 + 0x117) = uStack145;
  *(undefined *)(iVar9 + 0x118) = local_94;
  *(undefined *)(iVar9 + 0x119) = uStack147;
  *(undefined *)(iVar9 + 0x11a) = uStack146;
  *(undefined *)(iVar9 + 0x11b) = uStack145;
  return;
}


/* __thiscall dMenu_Fmap_c::checkMarkAnimeInit(void) */

void __thiscall dMenu_Fmap_c::checkMarkAnimeInit(dMenu_Fmap_c *this)

{
  *(undefined *)&this->field_0x517b = DAT_803e617c;
  *(undefined *)&this->field_0x517c = 1;
  return;
}


/* __thiscall dMenu_Fmap_c::checkMarkAnime(void) */

void __thiscall dMenu_Fmap_c::checkMarkAnime(dMenu_Fmap_c *this)

{
  undefined uVar1;
  undefined uVar2;
  undefined uVar3;
  undefined uVar4;
  undefined uVar5;
  undefined uVar6;
  undefined uVar7;
  undefined uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  double dVar13;
  
  dVar13 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                             (DAT_803e617c,*(undefined *)&this->field_0x517b,2);
  if (*(char *)&this->field_0x517c == '\0') {
    dVar13 = (double)(float)((double)d_menu_fmap::_4271 - dVar13);
  }
  uVar3 = (undefined)
          (int)((float)((double)CONCAT44(0x43300000,(uint)DAT_803e617d) - d_menu_fmap::_5228) +
               (float)(dVar13 * (double)(float)((double)CONCAT44(0x43300000,
                                                                 (uint)*(byte *)&this[1].field_0x18
                                                                 - (uint)DAT_803e617d ^ 0x80000000)
                                               - d_menu_fmap::_4609)));
  uVar5 = (undefined)
          (int)((float)((double)CONCAT44(0x43300000,(uint)DAT_803e617e) - d_menu_fmap::_5228) +
               (float)(dVar13 * (double)(float)((double)CONCAT44(0x43300000,
                                                                 (uint)*(byte *)&this[1].field_0x19
                                                                 - (uint)DAT_803e617e ^ 0x80000000)
                                               - d_menu_fmap::_4609)));
  uVar6 = (undefined)
          (int)((float)((double)CONCAT44(0x43300000,(uint)DAT_803e617f) - d_menu_fmap::_5228) +
               (float)(dVar13 * (double)(float)((double)CONCAT44(0x43300000,
                                                                 (uint)*(byte *)&this[1].field_0x1a
                                                                 - (uint)DAT_803e617f ^ 0x80000000)
                                               - d_menu_fmap::_4609)));
  uVar1 = *(undefined *)&this[1].field_0x1b;
  uVar4 = (undefined)
          (int)((float)((double)CONCAT44(0x43300000,(uint)DAT_803e6181) - d_menu_fmap::_5228) +
               (float)(dVar13 * (double)(float)((double)CONCAT44(0x43300000,
                                                                 (uint)*(byte *)&this[1].field_0x14
                                                                 - (uint)DAT_803e6181 ^ 0x80000000)
                                               - d_menu_fmap::_4609)));
  uVar7 = (undefined)
          (int)((float)((double)CONCAT44(0x43300000,(uint)DAT_803e6182) - d_menu_fmap::_5228) +
               (float)(dVar13 * (double)(float)((double)CONCAT44(0x43300000,
                                                                 (uint)*(byte *)&this[1].field_0x15
                                                                 - (uint)DAT_803e6182 ^ 0x80000000)
                                               - d_menu_fmap::_4609)));
  uVar8 = (undefined)
          (int)((float)((double)CONCAT44(0x43300000,(uint)DAT_803e6183) - d_menu_fmap::_5228) +
               (float)(dVar13 * (double)(float)((double)CONCAT44(0x43300000,
                                                                 (uint)*(byte *)&this[1].field_0x16
                                                                 - (uint)DAT_803e6183 ^ 0x80000000)
                                               - d_menu_fmap::_4609)));
  uVar2 = *(undefined *)&this[1].field_0x17;
  if (*(char *)&this->field_0x517b == '\0') {
    *(undefined *)&this->field_0x517b = DAT_803e617c;
    *(byte *)&this->field_0x517c = *(byte *)&this->field_0x517c ^ 1;
  }
  else {
    *(char *)&this->field_0x517b = *(char *)&this->field_0x517b + -1;
  }
  iVar9 = 0;
  iVar12 = 3;
  do {
    iVar11 = &this->field_0x0 + iVar9;
    iVar10 = *(int *)(iVar11 + 0x46f4);
    if (*(char *)(iVar10 + 0xaa) != '\0') {
      *(undefined *)(iVar10 + 0x108) = uVar4;
      *(undefined *)(iVar10 + 0x109) = uVar7;
      *(undefined *)(iVar10 + 0x10a) = uVar8;
      *(undefined *)(iVar10 + 0x10b) = uVar2;
      *(undefined *)(iVar10 + 0x104) = uVar3;
      *(undefined *)(iVar10 + 0x105) = uVar5;
      *(undefined *)(iVar10 + 0x106) = uVar6;
      *(undefined *)(iVar10 + 0x107) = uVar1;
    }
    iVar10 = *(int *)(iVar11 + 0x479c);
    if (*(char *)(iVar10 + 0xaa) != '\0') {
      *(undefined *)(iVar10 + 0x108) = uVar4;
      *(undefined *)(iVar10 + 0x109) = uVar7;
      *(undefined *)(iVar10 + 0x10a) = uVar8;
      *(undefined *)(iVar10 + 0x10b) = uVar2;
      *(undefined *)(iVar10 + 0x104) = uVar3;
      *(undefined *)(iVar10 + 0x105) = uVar5;
      *(undefined *)(iVar10 + 0x106) = uVar6;
      *(undefined *)(iVar10 + 0x107) = uVar1;
    }
    iVar9 = iVar9 + 0x38;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  iVar9 = 0;
  iVar12 = 2;
  do {
    iVar10 = *(int *)(&this->field_0x4844 + iVar9);
    if (*(char *)(iVar10 + 0xaa) != '\0') {
      *(undefined *)(iVar10 + 0x108) = uVar4;
      *(undefined *)(iVar10 + 0x109) = uVar7;
      *(undefined *)(iVar10 + 0x10a) = uVar8;
      *(undefined *)(iVar10 + 0x10b) = uVar2;
      *(undefined *)(iVar10 + 0x104) = uVar3;
      *(undefined *)(iVar10 + 0x105) = uVar5;
      *(undefined *)(iVar10 + 0x106) = uVar6;
      *(undefined *)(iVar10 + 0x107) = uVar1;
    }
    iVar9 = iVar9 + 0x38;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  return;
}


/* __thiscall dMenu_Fmap_c::readFmapTexture(char const *) */

void __thiscall dMenu_Fmap_c::readFmapTexture(dMenu_Fmap_c *this,char *param_1)

{
  JKRArchive::readTypeResource
            (*(void **)&this->field_0x18,0x2c00,0x464d2020,param_1,
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFMapArchive);
  return;
}


/* __thiscall dMenu_Fmap_c::aramCmapDatRead(void) */

void __thiscall dMenu_Fmap_c::aramCmapDatRead(dMenu_Fmap_c *this)

{
  aramCmapDatPat_t *paVar1;
  
  paVar1 = (aramCmapDatPat_t *)
           JKRArchive::getGlbResource
                     (0x44415441,"CmapDat.bin",
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFMapResArchive);
  initCmapDatPnt(this,paVar1);
  return;
}


/* __thiscall dMenu_Fmap_c::initCmapDatPnt(aramCmapDatPat_t *) */

void __thiscall dMenu_Fmap_c::initCmapDatPnt(dMenu_Fmap_c *this,aramCmapDatPat_t *param_1)

{
  ulong uVar1;
  
  if (param_1 == (aramCmapDatPat_t *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmapSv.h",0xfc,"0");
    m_Do_printf::OSPanic("d_menu_fmapSv.h",0xfc,&DAT_8035fc8d);
  }
  else {
    *(undefined4 *)&this->field_0x287c = *(undefined4 *)param_1;
    *(aramCmapDatPat_t **)&this->field_0x2880 = param_1 + 4;
  }
  return;
}


/* __thiscall dMenu_Fmap_c::getGridNumToCmapDatPnt(int) */

char * __thiscall dMenu_Fmap_c::getGridNumToCmapDatPnt(dMenu_Fmap_c *this,int param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  pcVar2 = *(char **)&this->field_0x2880;
  iVar1 = 0;
  iVar3 = *(int *)&this->field_0x287c;
  iVar4 = iVar3;
  if (0 < iVar3) {
    do {
      if ((int)*pcVar2 == param_1 + 1) break;
      pcVar2 = pcVar2 + 0x26;
      iVar1 = iVar1 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  if (iVar1 < iVar3) {
    return pcVar2;
  }
  return (char *)0x0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x801b3904) */
/* WARNING: Removing unreachable block (ram,0x801b390c) */
/* __thiscall dMenu_Fmap_c::setDispIslandPos(signed char,
                                             signed char) */

void __thiscall dMenu_Fmap_c::setDispIslandPos(dMenu_Fmap_c *this,char param_1,char param_2)

{
  float fVar1;
  float fVar2;
  double dVar3;
  char cVar4;
  undefined3 in_register_00000010;
  uchar *in_r9;
  undefined4 uVar5;
  undefined8 in_f30;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  short local_58;
  short local_56 [3];
  undefined4 local_50;
  uint uStack76;
  undefined4 local_48;
  uint uStack68;
  undefined4 local_40;
  uint uStack60;
  undefined4 local_38;
  uint uStack52;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  cVar4 = dMap_c::getCheckPointUseGrid
                    ((dMap_c *)CONCAT31(in_register_00000010,param_1),param_2,param_2);
  if ((dMap_c *)(int)cVar4 == (dMap_c *)&DAT_ffffffff) {
    *(undefined *)(*(int *)&this->field_0x2f54 + 0xaa) = 0;
    *(undefined *)(*(int *)&this->field_0x2f8c + 0xaa) = 0;
  }
  else {
    dMap_c::getFmapChkPntPrm
              ((dMap_c *)(int)cVar4,0,(char *)0x0,(char *)local_56,&local_58,(short *)0x0,in_r9);
    dVar3 = d_menu_fmap::_4609;
    uStack76 = (int)local_56[0] ^ 0x80000000;
    local_50 = 0x43300000;
    fVar1 = (float)((double)CONCAT44(0x43300000,uStack76) - d_menu_fmap::_4609) *
            ((*(float *)&this->field_0x30c8 - d_menu_fmap::_5712) / d_menu_fmap::_4719);
    dVar7 = (double)fVar1;
    uStack68 = (int)local_58 ^ 0x80000000;
    local_48 = 0x43300000;
    fVar2 = (float)((double)CONCAT44(0x43300000,uStack68) - d_menu_fmap::_4609) *
            ((*(float *)&this->field_0x30cc - d_menu_fmap::_5712) / d_menu_fmap::_4719);
    dVar6 = (double)fVar2;
    local_40 = 0x43300000;
    *(float *)&this->field_0x5134 =
         (float)((double)CONCAT44(0x43300000,uStack76) - d_menu_fmap::_4609);
    uStack52 = (int)local_58 ^ 0x80000000;
    local_38 = 0x43300000;
    *(float *)&this->field_0x5138 = (float)((double)CONCAT44(0x43300000,uStack52) - dVar3);
    uStack60 = uStack76;
    setIslandPos(this,(fopMsgM_pane_class *)&this->field_0x2f8c,fVar1,fVar2);
    setIslandPos(this,(fopMsgM_pane_class *)&this->field_0x2f54,(float)dVar7,(float)dVar6);
    changeFmapTexture(this,param_1,param_2);
    *(undefined *)(*(int *)&this->field_0x2f54 + 0xaa) = 1;
    *(undefined *)(*(int *)&this->field_0x2f8c + 0xaa) = 1;
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return;
}


/* __thiscall dMenu_Fmap_c::setIslandPos(fopMsgM_pane_class *,
                                         float,
                                         float) */

void __thiscall
dMenu_Fmap_c::setIslandPos
          (dMenu_Fmap_c *this,fopMsgM_pane_class *param_1,float param_2,float param_3)

{
  float fVar1;
  
  fVar1 = d_menu_fmap::_4260;
  (param_1->mPosCenterOrig).x = *(float *)&this->field_0x30c8 * d_menu_fmap::_4260 + param_2;
  (param_1->mPosCenterOrig).y = *(float *)&this->field_0x30cc * fVar1 + param_3;
  (param_1->mPosCenter).x = (param_1->mPosCenterOrig).x;
  (param_1->mPosCenter).y = (param_1->mPosCenterOrig).y;
  f_op_msg_mng::fopMsgM_cposMove(param_1);
  return;
}


/* __thiscall dMenu_Fmap_c::changeFmapTexture(signed char,
                                              signed char) */

void __thiscall dMenu_Fmap_c::changeFmapTexture(dMenu_Fmap_c *this,char param_1,char param_2)

{
  int iVar1;
  char acStack72 [68];
  
  MSL_C.PPCEABI.bare.H::sprintf(acStack72,"R%02X_b.bti",(int)param_1 + (param_2 + 3) * 7 + 4);
  iVar1 = readFmapTexture(this,acStack72);
  if (iVar1 == 0) {
    *(undefined *)(*(int *)&this->field_0x2f8c + 0xaa) = 0;
    *(undefined *)(*(int *)&this->field_0x337c + 0xaa) = 0;
  }
  else {
    J2DPicture::changeTexture
              (*(J2DPicture **)&this->field_0x2f8c,*(ResTIMG **)&this->field_0x18,'\0');
    J2DPicture::changeTexture
              (*(J2DPicture **)&this->field_0x337c,*(ResTIMG **)&this->field_0x18,'\0');
  }
  return;
}


/* __thiscall dMenu_Fmap_c::setDspNormalMapLink(void) */

void __thiscall dMenu_Fmap_c::setDspNormalMapLink(dMenu_Fmap_c *this)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  fVar3 = d_menu_fmap::_4719;
  fVar2 = d_menu_fmap::_4718;
  if (*(char *)&this->field_0x517f == '\0') {
    *(undefined *)(*(int *)&this->field_0x2e04 + 0xaa) = 0;
    *(undefined *)(*(int *)&this->field_0x2e3c + 0xaa) = 0;
  }
  else {
    *(float *)&this->field_0x2e18 =
         *(float *)&this->field_0x2de0 +
         (d_menu_fmap::_4718 * *(float *)&this->field_0x511c) / d_menu_fmap::_4719;
    *(float *)&this->field_0x2e1c =
         *(float *)&this->field_0x2de4 + (fVar2 * *(float *)&this->field_0x5120) / fVar3;
    *(undefined4 *)&this->field_0x2e20 = *(undefined4 *)&this->field_0x2e18;
    *(undefined4 *)&this->field_0x2e24 = *(undefined4 *)&this->field_0x2e1c;
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)&this->field_0x2e04);
    iVar1 = *(int *)&this->field_0x5124;
    local_20 = (double)CONCAT44(0x43300000,
                                (int)(d_menu_fmap::_4260 * *(float *)&this->field_0x2e34) ^
                                0x80000000);
    local_20 = local_20 - d_menu_fmap::_4609;
    piVar4 = *(int **)&this->field_0x2e04;
    local_10 = (double)CONCAT44(0x43300000,
                                (int)(d_menu_fmap::_4260 * *(float *)&this->field_0x2e30) ^
                                0x80000000);
    piVar4[0x27] = (int)(float)(local_10 - d_menu_fmap::_4609);
    piVar4[0x28] = (int)(float)local_20;
    *(undefined *)(piVar4 + 0x2a) = 0x7a;
    piVar4[0x29] = iVar1;
    (**(code **)(*piVar4 + 0x20))();
    fVar3 = d_menu_fmap::_4719;
    fVar2 = d_menu_fmap::_4718;
    if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x10000U) == 0) {
      *(float *)&this->field_0x2e50 =
           *(float *)&this->field_0x2de0 +
           (d_menu_fmap::_4718 * *(float *)&this->field_0x5128) / d_menu_fmap::_4719;
      *(float *)&this->field_0x2e54 =
           *(float *)&this->field_0x2de4 + (fVar2 * *(float *)&this->field_0x512c) / fVar3;
      *(undefined4 *)&this->field_0x2e58 = *(undefined4 *)&this->field_0x2e50;
      *(undefined4 *)&this->field_0x2e5c = *(undefined4 *)&this->field_0x2e54;
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)&this->field_0x2e3c);
      iVar1 = *(int *)&this->field_0x5130;
      local_18 = (double)CONCAT44(0x43300000,
                                  (int)(d_menu_fmap::_4260 * *(float *)&this->field_0x2e6c) ^
                                  0x80000000);
      local_18 = local_18 - d_menu_fmap::_4609;
      piVar4 = *(int **)&this->field_0x2e3c;
      local_28 = (double)CONCAT44(0x43300000,
                                  (int)(d_menu_fmap::_4260 * *(float *)&this->field_0x2e68) ^
                                  0x80000000);
      piVar4[0x27] = (int)(float)(local_28 - d_menu_fmap::_4609);
      piVar4[0x28] = (int)(float)local_18;
      *(undefined *)(piVar4 + 0x2a) = 0x7a;
      piVar4[0x29] = iVar1;
      (**(code **)(*piVar4 + 0x20))();
    }
    else {
      *(undefined *)(*(int *)&this->field_0x2e3c + 0xaa) = 0;
    }
  }
  return;
}


/* __thiscall dMenu_Fmap_c::setDspLargeMapLink(void) */

void __thiscall dMenu_Fmap_c::setDspLargeMapLink(dMenu_Fmap_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar4 = d_menu_fmap::_5712;
  fVar3 = d_menu_fmap::_4719;
  fVar2 = d_menu_fmap::_4260;
  if (*(char *)&this->field_0x517f != '\0') {
    fVar1 = d_menu_fmap::_4719 *
            (float)((double)CONCAT44(0x43300000,(int)*(char *)&this->field_0x5119 ^ 0x80000000) -
                   d_menu_fmap::_4609);
    *(float *)&this->field_0x2ef8 =
         *(float *)&this->field_0x30c8 * d_menu_fmap::_4260 +
         (*(float *)&this->field_0x511c -
         d_menu_fmap::_4719 *
         (float)((double)CONCAT44(0x43300000,(int)*(char *)&this->field_0x5118 ^ 0x80000000) -
                d_menu_fmap::_4609)) *
         ((*(float *)&this->field_0x30c8 - d_menu_fmap::_5712) / d_menu_fmap::_4719);
    *(float *)&this->field_0x2efc =
         *(float *)&this->field_0x30cc * fVar2 +
         (*(float *)&this->field_0x5120 - fVar1) * ((*(float *)&this->field_0x30cc - fVar4) / fVar3)
    ;
    *(undefined4 *)&this->field_0x2f00 = *(undefined4 *)&this->field_0x2ef8;
    *(undefined4 *)&this->field_0x2f04 = *(undefined4 *)&this->field_0x2efc;
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)&this->field_0x2ee4);
    fVar4 = d_menu_fmap::_5712;
    fVar3 = d_menu_fmap::_4719;
    fVar2 = d_menu_fmap::_4260;
    if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x10000U) == 0) {
      fVar1 = d_menu_fmap::_4719 *
              (float)((double)CONCAT44(0x43300000,(int)*(char *)&this->field_0x511b ^ 0x80000000) -
                     d_menu_fmap::_4609);
      *(float *)&this->field_0x2f30 =
           *(float *)&this->field_0x30c8 * d_menu_fmap::_4260 +
           (*(float *)&this->field_0x5128 -
           d_menu_fmap::_4719 *
           (float)((double)CONCAT44(0x43300000,(int)*(char *)&this->field_0x511a ^ 0x80000000) -
                  d_menu_fmap::_4609)) *
           ((*(float *)&this->field_0x30c8 - d_menu_fmap::_5712) / d_menu_fmap::_4719);
      *(float *)&this->field_0x2f34 =
           *(float *)&this->field_0x30cc * fVar2 +
           (*(float *)&this->field_0x512c - fVar1) *
           ((*(float *)&this->field_0x30cc - fVar4) / fVar3);
      *(undefined4 *)&this->field_0x2f38 = *(undefined4 *)&this->field_0x2f30;
      *(undefined4 *)&this->field_0x2f3c = *(undefined4 *)&this->field_0x2f34;
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)&this->field_0x2f1c);
    }
  }
  return;
}


/* __thiscall dMenu_Fmap_c::checkDspLargeMapLink(void) */

void __thiscall dMenu_Fmap_c::checkDspLargeMapLink(dMenu_Fmap_c *this)

{
  char cVar1;
  ulong uVar2;
  undefined uVar3;
  char in_r5;
  
  if (*(char *)&this->field_0x517f == '\0') {
    *(undefined *)(*(int *)&this->field_0x2ee4 + 0xaa) = 0;
    *(undefined *)&this[1].field_0x2 = 0;
  }
  else {
    if (this->mFmapSv == (undefined *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",500,"fmapSv != 0");
      in_r5 = -0x73;
      m_Do_printf::OSPanic("d_menu_fmap.h",500);
    }
    cVar1 = this->mFmapSv[5];
    if (this->mFmapSv == (undefined *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
      in_r5 = -0x73;
      m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9);
    }
    uVar3 = dMap_c::getCheckPointUseGrid((dMap_c *)(uint)(byte)this->mFmapSv[4],cVar1,in_r5);
    *(undefined *)&this->field_0x5111 = uVar3;
    if (*(char *)&this->field_0x5112 == *(char *)&this->field_0x5111) {
      *(undefined *)&this[1].field_0x2 = 1;
    }
    else {
      *(undefined *)(*(int *)&this->field_0x2ee4 + 0xaa) = 0;
      *(undefined *)&this[1].field_0x2 = 0;
    }
  }
  dispEndSalvageLargeMark(this);
  return;
}


/* __thiscall dMenu_Fmap_c::checkDspLargeMapShip(void) */

void __thiscall dMenu_Fmap_c::checkDspLargeMapShip(dMenu_Fmap_c *this)

{
  ulong uVar1;
  
  if (*(char *)&this->field_0x517f == '\0') {
    *(undefined *)(*(int *)&this->field_0x2f1c + 0xaa) = 0;
    *(undefined *)&this[1].field_0x4 = 0;
  }
  else {
    if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x10000U) == 0) {
      if (this->mFmapSv == (undefined *)0x0) {
        uVar1 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar1,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
        m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9,&DAT_8035fc8d);
      }
      if (*(char *)&this->field_0x511a == this->mFmapSv[4]) {
        if (this->mFmapSv == (undefined *)0x0) {
          uVar1 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar1,"d_menu_fmap.h",500,"fmapSv != 0");
          m_Do_printf::OSPanic("d_menu_fmap.h",500,&DAT_8035fc8d);
        }
        if (*(char *)&this->field_0x511b == this->mFmapSv[5]) {
          *(undefined *)&this[1].field_0x4 = 1;
          return;
        }
      }
    }
    *(undefined *)(*(int *)&this->field_0x2f1c + 0xaa) = 0;
    *(undefined *)&this[1].field_0x4 = 0;
  }
  return;
}


/* __thiscall dMenu_Fmap_c::dispEndSalvageLargeMark(void) */

void __thiscall dMenu_Fmap_c::dispEndSalvageLargeMark(dMenu_Fmap_c *this)

{
  double dVar1;
  char cVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  ulong uVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  
  if (this->mFmapSv == (undefined *)0x0) {
    uVar6 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar6,"d_menu_fmap.h",500,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",500,&DAT_8035fc8d);
  }
  cVar2 = this->mFmapSv[5];
  if (this->mFmapSv == (undefined *)0x0) {
    uVar6 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar6,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9,&DAT_8035fc8d);
  }
  pcVar8 = *(char **)&this->field_0x2880;
  iVar7 = 0;
  iVar9 = *(int *)&this->field_0x287c;
  iVar10 = iVar9;
  if (0 < iVar9) {
    do {
      if ((int)*pcVar8 == (int)(char)this->mFmapSv[4] + (cVar2 + 3) * 7 + 4) break;
      pcVar8 = pcVar8 + 0x26;
      iVar7 = iVar7 + 1;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  if (iVar9 <= iVar7) {
    pcVar8 = (char *)0x0;
  }
  iVar10 = dSv_player_map_c::isCompleteMap
                     (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,pcVar8[1] + -1)
  ;
  fVar5 = d_menu_fmap::_5712;
  fVar4 = d_menu_fmap::_4719;
  fVar3 = d_menu_fmap::_4260;
  if (iVar10 == 0) {
    *(undefined *)(*(int *)&this->field_0x2fc4 + 0xaa) = 0;
  }
  else {
    dVar1 = (double)CONCAT44(0x43300000,
                             (int)*(short *)(pcVar8 + (uint)*(byte *)(this + 1) * 8 + 0xc) ^
                             0x80000000) - d_menu_fmap::_4609;
    *(float *)&this->field_0x2fd8 =
         *(float *)&this->field_0x30c8 * d_menu_fmap::_4260 +
         (float)((double)CONCAT44(0x43300000,
                                  (int)*(short *)(pcVar8 + (uint)*(byte *)(this + 1) * 8 + 10) ^
                                  0x80000000) - d_menu_fmap::_4609) *
         ((*(float *)&this->field_0x30c8 - d_menu_fmap::_5712) / d_menu_fmap::_4719);
    *(float *)&this->field_0x2fdc =
         *(float *)&this->field_0x30cc * fVar3 +
         (float)dVar1 * ((*(float *)&this->field_0x30cc - fVar5) / fVar4);
    *(undefined4 *)&this->field_0x2fe0 = *(undefined4 *)&this->field_0x2fd8;
    *(undefined4 *)&this->field_0x2fe4 = *(undefined4 *)&this->field_0x2fdc;
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)&this->field_0x2fc4);
    *(undefined *)(*(int *)&this->field_0x2fc4 + 0xaa) = 1;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x801b4618) */
/* WARNING: Removing unreachable block (ram,0x801b4608) */
/* WARNING: Removing unreachable block (ram,0x801b4610) */
/* WARNING: Removing unreachable block (ram,0x801b4620) */
/* __thiscall dMenu_Fmap_c::setDspHugeMapLink(void) */

void __thiscall dMenu_Fmap_c::setDspHugeMapLink(dMenu_Fmap_c *this)

{
  float fVar1;
  float fVar2;
  char cVar3;
  float fVar4;
  ulong uVar5;
  dMap_c *this_00;
  char in_r5;
  uchar *in_r9;
  undefined4 uVar6;
  undefined8 in_f28;
  double dVar7;
  undefined8 in_f29;
  double dVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  char local_78;
  char local_77;
  short local_76;
  short local_74 [2];
  undefined4 local_70;
  uint uStack108;
  undefined4 local_68;
  uint uStack100;
  undefined4 local_60;
  uint uStack92;
  undefined4 local_58;
  uint uStack84;
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
  if (this->mFmapSv == (undefined *)0x0) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_menu_fmap.h",0x21f,"fmapSv != 0");
    in_r5 = -0x73;
    m_Do_printf::OSPanic("d_menu_fmap.h",0x21f);
  }
  cVar3 = this->mFmapSv[3];
  if (this->mFmapSv == (undefined *)0x0) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_menu_fmap.h",0x215,"fmapSv != 0");
    in_r5 = -0x73;
    m_Do_printf::OSPanic("d_menu_fmap.h",0x215);
  }
  this_00 = (dMap_c *)
            dMap_c::getCheckPointUseGrid((dMap_c *)(uint)(byte)this->mFmapSv[2],cVar3,in_r5);
  if (this_00 != (dMap_c *)&DAT_ffffffff) {
    dMap_c::getFmapChkPntPrm
              (this_00,(int)&local_77,&local_78,(char *)local_74,&local_76,(short *)0x0,in_r9);
    if (*(char *)&this->field_0x517f == '\0') {
      *(undefined *)(*(int *)&this->field_0x32d4 + 0xaa) = 0;
      *(undefined *)&this[1].field_0x3 = 0;
      uStack108 = (int)local_74[0] ^ 0x80000000;
      local_70 = 0x43300000;
      uStack100 = (int)local_76 ^ 0x80000000;
      local_68 = 0x43300000;
      dispEndSalvageHugeMark
                (this,(float)((double)CONCAT44(0x43300000,uStack108) - d_menu_fmap::_4609),
                 (float)((double)CONCAT44(0x43300000,uStack100) - d_menu_fmap::_4609));
    }
    else {
      uStack100 = (int)local_74[0] ^ 0x80000000;
      local_68 = 0x43300000;
      uStack108 = (int)local_77 ^ 0x80000000;
      local_70 = 0x43300000;
      dVar10 = (double)((float)((double)CONCAT44(0x43300000,uStack100) - d_menu_fmap::_4609) +
                       d_menu_fmap::_4719 *
                       (float)((double)CONCAT44(0x43300000,uStack108) - d_menu_fmap::_4609));
      uStack92 = (int)local_76 ^ 0x80000000;
      local_60 = 0x43300000;
      uStack84 = (int)local_78 ^ 0x80000000;
      local_58 = 0x43300000;
      dVar9 = (double)((float)((double)CONCAT44(0x43300000,uStack92) - d_menu_fmap::_4609) +
                      d_menu_fmap::_4719 *
                      (float)((double)CONCAT44(0x43300000,uStack84) - d_menu_fmap::_4609));
      fVar1 = (float)((double)*(float *)&this->field_0x511c - dVar10);
      fVar2 = (float)((double)*(float *)&this->field_0x5120 - dVar9);
      if ((((d_menu_fmap::_5944 < fVar1) || (fVar1 < d_menu_fmap::_5945)) ||
          (d_menu_fmap::_5944 < fVar2)) || (fVar2 < d_menu_fmap::_5945)) {
        *(undefined *)&this->field_0x5168 = 0;
      }
      else {
        *(undefined *)&this->field_0x5168 = 1;
      }
      fVar4 = d_menu_fmap::_5946;
      dVar8 = (double)(*(float *)&this->field_0x3380 +
                      *(float *)&this->field_0x33a0 * d_menu_fmap::_4260);
      dVar7 = (double)(*(float *)&this->field_0x3384 +
                      *(float *)&this->field_0x33a4 * d_menu_fmap::_4260);
      *(float *)&this->field_0x32e8 =
           (float)(dVar8 + (double)(fVar1 * (*(float *)&this->field_0x33a0 / d_menu_fmap::_5946)));
      *(float *)&this->field_0x32ec =
           (float)(dVar7 + (double)(fVar2 * (*(float *)&this->field_0x33a4 / fVar4)));
      *(undefined4 *)&this->field_0x32f0 = *(undefined4 *)&this->field_0x32e8;
      *(undefined4 *)&this->field_0x32f4 = *(undefined4 *)&this->field_0x32ec;
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)&this->field_0x32d4);
      if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x10000U) == 0) {
        fVar1 = (float)((double)*(float *)&this->field_0x5128 - dVar10);
        fVar2 = (float)((double)*(float *)&this->field_0x512c - dVar9);
        if (((d_menu_fmap::_5944 < fVar1) || (fVar1 < d_menu_fmap::_5945)) ||
           ((d_menu_fmap::_5944 < fVar2 || (fVar2 < d_menu_fmap::_5945)))) {
          *(undefined *)&this[1].field_0x5 = 0;
          *(undefined *)&this[1].field_0x6 = 1;
          *(undefined *)(*(int *)&this->field_0x330c + 0xaa) = 0;
        }
        else {
          *(undefined *)&this[1].field_0x5 = 1;
          *(undefined *)&this[1].field_0x6 = 0;
        }
        fVar4 = d_menu_fmap::_5946;
        *(float *)&this->field_0x3320 =
             (float)(dVar8 + (double)(fVar1 * (*(float *)&this->field_0x33a0 / d_menu_fmap::_5946)))
        ;
        *(float *)&this->field_0x3324 =
             (float)(dVar7 + (double)(fVar2 * (*(float *)&this->field_0x33a4 / fVar4)));
        *(undefined4 *)&this->field_0x3328 = *(undefined4 *)&this->field_0x3320;
        *(undefined4 *)&this->field_0x332c = *(undefined4 *)&this->field_0x3324;
        f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)&this->field_0x330c);
      }
      uStack84 = (int)local_74[0] ^ 0x80000000;
      local_58 = 0x43300000;
      uStack92 = (int)local_76 ^ 0x80000000;
      local_60 = 0x43300000;
      dispEndSalvageHugeMark
                (this,(float)((double)CONCAT44(0x43300000,uStack84) - d_menu_fmap::_4609),
                 (float)((double)CONCAT44(0x43300000,uStack92) - d_menu_fmap::_4609));
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


/* WARNING: Removing unreachable block (ram,0x801b489c) */
/* WARNING: Removing unreachable block (ram,0x801b48a4) */
/* __thiscall dMenu_Fmap_c::dispEndSalvageHugeMark(float,
                                                   float) */

void __thiscall dMenu_Fmap_c::dispEndSalvageHugeMark(dMenu_Fmap_c *this,float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  char cVar3;
  float fVar4;
  float fVar5;
  ulong uVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  double dVar12;
  double dVar13;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar13 = (double)param_2;
  dVar12 = (double)param_1;
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (this->mFmapSv == (undefined *)0x0) {
    uVar6 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar6,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9,&DAT_8035fc8d);
  }
  cVar3 = this->mFmapSv[4];
  if (this->mFmapSv == (undefined *)0x0) {
    uVar6 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar6,"d_menu_fmap.h",500,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",500,&DAT_8035fc8d);
  }
  pcVar8 = *(char **)&this->field_0x2880;
  iVar7 = 0;
  iVar9 = *(int *)&this->field_0x287c;
  iVar10 = iVar9;
  if (0 < iVar9) {
    do {
      if ((int)*pcVar8 == (int)cVar3 + ((char)this->mFmapSv[5] + 3) * 7 + 4) break;
      pcVar8 = pcVar8 + 0x26;
      iVar7 = iVar7 + 1;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  if (iVar9 <= iVar7) {
    pcVar8 = (char *)0x0;
  }
  iVar10 = dSv_player_map_c::isCompleteMap
                     (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,pcVar8[1] + -1)
  ;
  fVar5 = d_menu_fmap::_5946;
  fVar4 = d_menu_fmap::_4260;
  if (iVar10 == 0) {
    *(undefined *)(*(int *)&this->field_0x3344 + 0xaa) = 0;
  }
  else {
    fVar1 = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                     (int)*(short *)(pcVar8 + (uint)*(byte *)(this +
                                                                                             1) * 8
                                                                    + 10) ^ 0x80000000) -
                                   d_menu_fmap::_4609) - dVar12);
    fVar2 = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                     (int)*(short *)(pcVar8 + (uint)*(byte *)(this +
                                                                                             1) * 8
                                                                    + 0xc) ^ 0x80000000) -
                                   d_menu_fmap::_4609) - dVar13);
    if ((((d_menu_fmap::_5944 < fVar1) || (fVar1 < d_menu_fmap::_5945)) ||
        (d_menu_fmap::_5944 < fVar2)) || (fVar2 < d_menu_fmap::_5945)) {
      *(undefined *)(*(int *)&this->field_0x3344 + 0xaa) = 0;
    }
    else {
      *(float *)&this->field_0x3358 =
           *(float *)&this->field_0x3380 + *(float *)&this->field_0x33a0 * d_menu_fmap::_4260 +
           fVar1 * (*(float *)&this->field_0x33a0 / d_menu_fmap::_5946);
      *(float *)&this->field_0x335c =
           *(float *)&this->field_0x3384 + *(float *)&this->field_0x33a4 * fVar4 +
           fVar2 * (*(float *)&this->field_0x33a4 / fVar5);
      *(undefined4 *)&this->field_0x3360 = *(undefined4 *)&this->field_0x3358;
      *(undefined4 *)&this->field_0x3364 = *(undefined4 *)&this->field_0x335c;
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)&this->field_0x3344);
      *(undefined *)(*(int *)&this->field_0x3344 + 0xaa) = 1;
    }
  }
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  __psq_l0(auStack24,uVar11);
  __psq_l1(auStack24,uVar11);
  return;
}


/* __thiscall dMenu_Fmap_c::checkDspHugeMapLink(void) */

void __thiscall dMenu_Fmap_c::checkDspHugeMapLink(dMenu_Fmap_c *this)

{
  char cVar1;
  ulong uVar2;
  undefined uVar3;
  char in_r5;
  
  if (*(char *)&this->field_0x517f == '\0') {
    *(undefined *)(*(int *)&this->field_0x32d4 + 0xaa) = 0;
  }
  else {
    if (this->mFmapSv == (undefined *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",500,"fmapSv != 0");
      in_r5 = -0x73;
      m_Do_printf::OSPanic("d_menu_fmap.h",500);
    }
    cVar1 = this->mFmapSv[5];
    if (this->mFmapSv == (undefined *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
      in_r5 = -0x73;
      m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9);
    }
    uVar3 = dMap_c::getCheckPointUseGrid((dMap_c *)(uint)(byte)this->mFmapSv[4],cVar1,in_r5);
    *(undefined *)&this->field_0x5111 = uVar3;
    if ((*(char *)&this->field_0x5112 == *(char *)&this->field_0x5111) &&
       (*(char *)&this->field_0x5168 != '\0')) {
      *(undefined *)&this[1].field_0x3 = 1;
    }
    else {
      *(undefined *)(*(int *)&this->field_0x32d4 + 0xaa) = 0;
      *(undefined *)&this[1].field_0x3 = 0;
    }
  }
  return;
}


/* __thiscall dMenu_Fmap_c::checkDspHugeMapShip(void) */

void __thiscall dMenu_Fmap_c::checkDspHugeMapShip(dMenu_Fmap_c *this)

{
  ulong uVar1;
  
  if (*(char *)&this->field_0x517f == '\0') {
    *(undefined *)(*(int *)&this->field_0x330c + 0xaa) = 0;
    *(undefined *)&this[1].field_0x5 = 0;
  }
  else {
    if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x10000U) == 0) {
      if (this->mFmapSv == (undefined *)0x0) {
        uVar1 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar1,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
        m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9,&DAT_8035fc8d);
      }
      if (*(char *)&this->field_0x511a == this->mFmapSv[4]) {
        if (this->mFmapSv == (undefined *)0x0) {
          uVar1 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar1,"d_menu_fmap.h",500,"fmapSv != 0");
          m_Do_printf::OSPanic("d_menu_fmap.h",500,&DAT_8035fc8d);
        }
        if (*(char *)&this->field_0x511b == this->mFmapSv[5]) {
          if (*(char *)&this[1].field_0x6 != '\0') {
            *(undefined *)&this[1].field_0x5 = 0;
            *(undefined *)(*(int *)&this->field_0x330c + 0xaa) = 0;
            return;
          }
          *(undefined *)&this[1].field_0x5 = 1;
          return;
        }
      }
    }
    *(undefined *)(*(int *)&this->field_0x330c + 0xaa) = 0;
    *(undefined *)&this[1].field_0x5 = 0;
  }
  return;
}


/* __thiscall dMenu_Fmap_c::_open(void) */

bool __thiscall dMenu_Fmap_c::_open(dMenu_Fmap_c *this)

{
  int iVar1;
  
  if (*(short *)&this->field_0x5116 == 0) {
    *(undefined *)&this[1].field_0x1 = 0;
  }
  if (*(char *)&this->field_0x5169 == '\0') {
    iVar1 = paneTransBase(this,*(short *)&this->field_0x5116 - (ushort)DAT_803e60cf,DAT_803e60d0,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e60d2 ^ 0x80000000) -
                                 d_menu_fmap::_4609),d_menu_fmap::_4256,'\0',0);
    *(short *)&this->field_0x5116 = *(short *)&this->field_0x5116 + 1;
  }
  else {
    iVar1 = 1;
  }
  if (iVar1 == 1) {
    *(undefined2 *)&this->field_0x5116 = 0;
  }
  return iVar1 == 1;
}


/* WARNING: Removing unreachable block (ram,0x801b4c34) */
/* __thiscall dMenu_Fmap_c::_close(void) */

undefined4 __thiscall dMenu_Fmap_c::_close(dMenu_Fmap_c *this)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 in_r4;
  
  bVar1 = *(byte *)&this->field_0x516b;
  if (bVar1 != 2) {
    if (1 < bVar1) {
      if (3 < bVar1) {
        return in_r4;
      }
      uVar2 = _close_fishManMode(this);
      return uVar2;
    }
    if (bVar1 != 0) {
      uVar2 = _close_warpMode(this);
      return uVar2;
    }
  }
  uVar2 = _close_normalMode(this);
  return uVar2;
}


/* __thiscall dMenu_Fmap_c::_close_normalMode(void) */

undefined4 __thiscall dMenu_Fmap_c::_close_normalMode(dMenu_Fmap_c *this)

{
  int iVar1;
  ulong uVar2;
  undefined4 uVar3;
  
  if (*(char *)&this->field_0x516a == '\0') {
    iVar1 = paneTransBase(this,*(short *)&this->field_0x5116,DAT_803e60d0,d_menu_fmap::_4256,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e60d4 ^ 0x80000000) -
                                 d_menu_fmap::_4609),'\0',1);
  }
  else {
    iVar1 = 1;
  }
  *(short *)&this->field_0x5116 = *(short *)&this->field_0x5116 + 1;
  if (iVar1 == 1) {
    if (*(char *)&this->field_0x516a == '\0') {
      if (this->mFmapSv == (undefined *)0x0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",0x1d8,"fmapSv != 0");
        m_Do_printf::OSPanic("d_menu_fmap.h",0x1d8,&DAT_8035fc8d);
      }
      *this->mFmapSv = 0;
    }
    *(undefined2 *)&this->field_0x5116 = 0;
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


/* WARNING: Removing unreachable block (ram,0x801b4da0) */
/* __thiscall dMenu_Fmap_c::_move(void) */

void __thiscall dMenu_Fmap_c::_move(dMenu_Fmap_c *this)

{
  byte bVar1;
  
  bVar1 = *(byte *)&this->field_0x516b;
  if (bVar1 == 2) {
    if ((((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 < '\0') ||
        ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 5 & 1) != 0)) ||
       ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0')) {
      *(undefined *)&this->field_0x510c = 1;
    }
    else {
      *(undefined *)&this->field_0x510c = 0;
    }
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 == 0) {
        move_normal(this);
      }
      else {
        moveMain_warpMode(this);
      }
    }
    else {
      if (bVar1 < 4) {
        movefishManMode(this);
      }
    }
  }
  return;
}


/* __thiscall dMenu_Fmap_c::_draw(void) */

void __thiscall dMenu_Fmap_c::_draw(dMenu_Fmap_c *this)

{
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    (dDlst_base_c *)&this->field_0x1c);
  if (*(char *)&this->field_0x5113 == '\x01') {
    dMenu_Fmap2_c::_draw((dMenu_Fmap2_c *)&this->field_0x24);
  }
  return;
}


/* __thiscall dMenu_Fmap_c::_delete(void) */

void __thiscall dMenu_Fmap_c::_delete(dMenu_Fmap_c *this)

{
  int *piVar1;
  
  dMenu_Fmap2_c::_delete((dMenu_Fmap2_c *)&this->field_0x24);
  piVar1 = *(int **)&this->field_0x20;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  JKernel::operator_delete(*(JKRHeap **)&this->field_0x50cc);
  JKernel::operator_delete(*(JKRHeap **)&this->field_0x18);
  if (*(JKRHeap **)&this->field_0x2884 != (JKRHeap *)0x0) {
    JKernel::operator_delete(*(JKRHeap **)&this->field_0x2884);
  }
  if (*(JKRHeap **)&this->field_0x2888 != (JKRHeap *)0x0) {
    JKernel::operator_delete(*(JKRHeap **)&this->field_0x2888);
  }
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFMapResArchive)->parent).parent.vtbl)->
            removeResourceAll)();
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFMapArchive)->parent).parent.vtbl)->
            removeResourceAll)();
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e60a0);
  return;
}


/* __thiscall dMenu_Fmap_c::FmapProcMain(void) */

void __thiscall dMenu_Fmap_c::FmapProcMain(dMenu_Fmap_c *this)

{
  ulong uVar1;
  
  if (((-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2) &&
      ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 5 & 1) == 0)) &&
     (*(char *)&this->field_0x516a == '\0')) {
    if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
      if (this->mFmapSv == (undefined *)0x0) {
        uVar1 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar1,"d_menu_fmap.h",0x1de,"fmapSv != 0");
        m_Do_printf::OSPanic("d_menu_fmap.h",0x1de,&DAT_8035fc8d);
      }
      if (this->mFmapSv[1] == '\0') goto LAB_801b4fdc;
    }
    Runtime.PPCEABI.H::__ptmf_scall
              ((PTMF *)(&d_menu_fmap::fmapProcMain + (uint)*(byte *)&this->field_0x5114 * 3),this,
               &DAT_80390000);
    windArrowColorAnime(this);
    checkMarkAnime(this);
    gShipMarkAnime(this);
    return;
  }
LAB_801b4fdc:
  *(undefined *)&this->field_0x510c = 1;
  return;
}


/* __thiscall dMenu_Fmap_c::SelectGrid(void) */

void __thiscall dMenu_Fmap_c::SelectGrid(dMenu_Fmap_c *this)

{
  undefined uVar1;
  ulong uVar2;
  int iVar3;
  char cVar4;
  
  STControl::checkTrigger(*(STControl **)&this->field_0x50cc);
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
    cVar4 = STControl::checkRightTrigger(*(STControl **)&this->field_0x50cc);
    if (cVar4 == '\0') {
      cVar4 = STControl::checkLeftTrigger(*(STControl **)&this->field_0x50cc);
      if (cVar4 == '\0') {
        cVar4 = STControl::checkUpTrigger(*(STControl **)&this->field_0x50cc);
        if (cVar4 == '\0') {
          cVar4 = STControl::checkDownTrigger(*(STControl **)&this->field_0x50cc);
          if (cVar4 != '\0') {
            if (this->mFmapSv == (undefined *)0x0) {
              uVar2 = JUTAssertion::getSDevice();
              JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",500,"fmapSv != 0");
              m_Do_printf::OSPanic("d_menu_fmap.h",500,&DAT_8035fc8d);
            }
            if ((char)this->mFmapSv[5] < '\x03') {
              if (this->mFmapSv == (undefined *)0x0) {
                uVar2 = JUTAssertion::getSDevice();
                JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",500,"fmapSv != 0");
                m_Do_printf::OSPanic("d_menu_fmap.h",500,&DAT_8035fc8d);
              }
              cVar4 = this->mFmapSv[5];
              if (this->mFmapSv == (undefined *)0x0) {
                uVar2 = JUTAssertion::getSDevice();
                JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",0x1f9,"fmapSv != 0");
                m_Do_printf::OSPanic("d_menu_fmap.h",0x1f9,&DAT_8035fc8d);
              }
              this->mFmapSv[5] = cVar4 + '\x01';
              JAIZelBasic::seStart
                        (JAIZelBasic::zel_basic,0x8c3,(cXyz *)0x0,0,0,d_menu_fmap::_4271,
                         d_menu_fmap::_4271,d_menu_fmap::_4272,d_menu_fmap::_4272,0);
              selCursorMove(this);
              islandNameChange(this);
              salvageGetItemChange(this);
            }
          }
        }
        else {
          if (this->mFmapSv == (undefined *)0x0) {
            uVar2 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",500,"fmapSv != 0");
            m_Do_printf::OSPanic("d_menu_fmap.h",500,&DAT_8035fc8d);
          }
          if (-3 < (char)this->mFmapSv[5]) {
            if (this->mFmapSv == (undefined *)0x0) {
              uVar2 = JUTAssertion::getSDevice();
              JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",500,"fmapSv != 0");
              m_Do_printf::OSPanic("d_menu_fmap.h",500,&DAT_8035fc8d);
            }
            cVar4 = this->mFmapSv[5];
            if (this->mFmapSv == (undefined *)0x0) {
              uVar2 = JUTAssertion::getSDevice();
              JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",0x1f9,"fmapSv != 0");
              m_Do_printf::OSPanic("d_menu_fmap.h",0x1f9,&DAT_8035fc8d);
            }
            this->mFmapSv[5] = cVar4 + -1;
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x8c3,(cXyz *)0x0,0,0,d_menu_fmap::_4271,
                       d_menu_fmap::_4271,d_menu_fmap::_4272,d_menu_fmap::_4272,0);
            selCursorMove(this);
            islandNameChange(this);
            salvageGetItemChange(this);
          }
        }
      }
      else {
        if (this->mFmapSv == (undefined *)0x0) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
          m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9,&DAT_8035fc8d);
        }
        if (-3 < (char)this->mFmapSv[4]) {
          if (this->mFmapSv == (undefined *)0x0) {
            uVar2 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
            m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9,&DAT_8035fc8d);
          }
          cVar4 = this->mFmapSv[4];
          if (this->mFmapSv == (undefined *)0x0) {
            uVar2 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",0x1ee,"fmapSv != 0");
            m_Do_printf::OSPanic("d_menu_fmap.h",0x1ee,&DAT_8035fc8d);
          }
          this->mFmapSv[4] = cVar4 + -1;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x8c3,(cXyz *)0x0,0,0,d_menu_fmap::_4271,
                     d_menu_fmap::_4271,d_menu_fmap::_4272,d_menu_fmap::_4272,0);
          selCursorMove(this);
          islandNameChange(this);
          salvageGetItemChange(this);
        }
      }
    }
    else {
      if (this->mFmapSv == (undefined *)0x0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
        m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9,&DAT_8035fc8d);
      }
      if ((char)this->mFmapSv[4] < '\x03') {
        if (this->mFmapSv == (undefined *)0x0) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
          m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9,&DAT_8035fc8d);
        }
        cVar4 = this->mFmapSv[4];
        if (this->mFmapSv == (undefined *)0x0) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",0x1ee,"fmapSv != 0");
          m_Do_printf::OSPanic("d_menu_fmap.h",0x1ee,&DAT_8035fc8d);
        }
        this->mFmapSv[4] = cVar4 + '\x01';
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x8c3,(cXyz *)0x0,0,0,d_menu_fmap::_4271,
                   d_menu_fmap::_4271,d_menu_fmap::_4272,d_menu_fmap::_4272,0);
        selCursorMove(this);
        islandNameChange(this);
        salvageGetItemChange(this);
      }
    }
  }
  else {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8c4,(cXyz *)0x0,0,0,d_menu_fmap::_4271,d_menu_fmap::_4271,
               d_menu_fmap::_4272,d_menu_fmap::_4272,0);
    if (this->mFmapSv == (undefined *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",500,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap.h",500,&DAT_8035fc8d);
    }
    cVar4 = this->mFmapSv[5];
    if (this->mFmapSv == (undefined *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9,&DAT_8035fc8d);
    }
    iVar3 = dSv_player_map_c::isSaveArriveGrid
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,
                       (int)(char)this->mFmapSv[4] + (cVar4 + 3) * 7 + 3);
    if (iVar3 == 0) {
      *(undefined *)&this[1].field_0x1 = 3;
    }
    else {
      *(undefined *)&this[1].field_0x1 = 1;
    }
    if (this->mFmapSv == (undefined *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9,&DAT_8035fc8d);
    }
    uVar1 = this->mFmapSv[4];
    if (this->mFmapSv == (undefined *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",0x21a,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap.h",0x21a,&DAT_8035fc8d);
    }
    this->mFmapSv[2] = uVar1;
    if (this->mFmapSv == (undefined *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",500,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap.h",500,&DAT_8035fc8d);
    }
    uVar1 = this->mFmapSv[5];
    if (this->mFmapSv == (undefined *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",0x224,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap.h",0x224,&DAT_8035fc8d);
    }
    this->mFmapSv[3] = uVar1;
    if (this->mFmapSv == (undefined *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",0x1e3,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap.h",0x1e3,&DAT_8035fc8d);
    }
    this->mFmapSv[1] = 1;
    zoom1000x1000Init(this);
    *(undefined *)&this->field_0x5164 = 0;
    if (*(char *)&this->field_0x5142 != '\0') {
      AreaTxtChgFast(this);
      *(undefined *)&this->field_0x5142 = 0;
    }
    *(undefined2 *)&this->field_0x5116 = 0;
    *(undefined *)&this->field_0x5114 = 1;
  }
  playerPointGridAnime(this);
  selCursorAnime(this);
  AreaTxtChg(this);
  salvageGetItemChg(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Fmap_c::zoom1000x1000Init(void) */

void __thiscall dMenu_Fmap_c::zoom1000x1000Init(dMenu_Fmap_c *this)

{
  char cVar1;
  char cVar2;
  char cVar3;
  ulong uVar4;
  int iVar5;
  
  if (this->mFmapSv == (undefined *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_menu_fmap.h",500,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",500,&DAT_8035fc8d);
  }
  cVar1 = this->mFmapSv[5];
  if (this->mFmapSv == (undefined *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9,&DAT_8035fc8d);
  }
  cVar2 = this->mFmapSv[4];
  if (this->mFmapSv == (undefined *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_menu_fmap.h",500,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",500,&DAT_8035fc8d);
  }
  cVar3 = this->mFmapSv[5];
  if (this->mFmapSv == (undefined *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9,&DAT_8035fc8d);
  }
  zoomMapAlphaSet(this,this->mFmapSv[4],cVar3,(fopMsgM_pane_class *)&this->field_0x2f8c,'\x14');
  checkDspLargeMapLink(this);
  checkDspLargeMapShip(this);
  if (this->mFmapSv == (undefined *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_menu_fmap.h",500,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",500,&DAT_8035fc8d);
  }
  cVar3 = this->mFmapSv[5];
  if (this->mFmapSv == (undefined *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9,&DAT_8035fc8d);
  }
  setDispIslandPos(this,this->mFmapSv[4],cVar3);
  selCursorInit(this);
  zoomCursorInit(this);
  *(undefined *)(*(int *)&this->field_0x2e74 + 0xaa) = 1;
  *(undefined *)(*(int *)&this->field_0x2eac + 0xaa) = 1;
  *(undefined *)(*(int *)&this->field_0x30a4 + 0xaa) = 1;
  iVar5 = dSv_player_map_c::isSaveArriveGrid
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,
                     (int)cVar2 + (cVar1 + 3) * 7 + 3);
  if (iVar5 == 0) {
    *(undefined *)(*(int *)&this->field_0x2f54 + 0xaa) = 0;
    *(undefined *)(*(int *)&this->field_0x2f8c + 0xaa) = 0;
    *(undefined *)(*(int *)&this->field_0x2ffc + 0xaa) = 1;
    if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ == '\0') {
      *(undefined *)(*(int *)&this->field_0x3034 + 0xaa) = 1;
    }
    *(undefined *)(*(int *)&this->field_0x306c + 0xaa) = 1;
  }
  else {
    *(undefined *)(*(int *)&this->field_0x2ffc + 0xaa) = 0;
    *(undefined *)(*(int *)&this->field_0x3034 + 0xaa) = 0;
    *(undefined *)(*(int *)&this->field_0x306c + 0xaa) = 0;
  }
  return;
}


/* __thiscall dMenu_Fmap_c::zoomMapAlphaSet(signed char,
                                            signed char,
                                            fopMsgM_pane_class *,
                                            unsigned char) */

void __thiscall
dMenu_Fmap_c::zoomMapAlphaSet
          (dMenu_Fmap_c *this,char param_1,char param_2,fopMsgM_pane_class *param_3,uchar param_4)

{
  if ((int)param_1 + (param_2 + 3) * 7 == 0x16) {
    param_3->mAlphaOrig = param_4;
  }
  else {
    param_3->mAlphaOrig = 0xff;
  }
  param_3->mAlphaOrig = 0xff;
  f_op_msg_mng::fopMsgM_setAlpha(param_3);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dMenu_Fmap_c::ZoomGridLv1In(void) */

void __thiscall dMenu_Fmap_c::ZoomGridLv1In(dMenu_Fmap_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = paneAlphaFmapCursor(this,(fopMsgM_pane_class *)&this->field_0x2a4c,
                              *(short *)&this->field_0x5116,DAT_803e60d7,'\0',1);
  iVar2 = selGridMaskAlphaCtrl(this,*(short *)&this->field_0x5116,DAT_803e60ca,'\0',0);
  iVar3 = fmapMaskAlphaCtrl(this,*(short *)&this->field_0x5116,DAT_803e60ca,'\0',0);
  iVar4 = paneTranceZoomMap(this,*(short *)&this->field_0x5116 - (ushort)DAT_803e60d8,DAT_803e60ca,
                            *(float *)&this->field_0x2e90 - *(float *)&this->field_0x30b8,
                            *(float *)&this->field_0x2e94 - *(float *)&this->field_0x30bc,
                            d_menu_fmap::_4256,d_menu_fmap::_4256,
                            *(float *)&this->field_0x2e98 / *(float *)&this->field_0x30c8,
                            d_menu_fmap::_4271,'\x02',0);
  iVar5 = paneAlphaFmapCursor(this,(fopMsgM_pane_class *)&this->field_0x2c0c,
                              *(short *)&this->field_0x5116 - (ushort)DAT_803e60d8,DAT_803e60ca,'\0'
                              ,0);
  *(short *)&this->field_0x5116 = *(short *)&this->field_0x5116 + 1;
  if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) != 0) &&
     (*(char *)&this->field_0x5164 == '\0')) {
    *(undefined *)&this->field_0x5164 = 1;
  }
  if ((((iVar1 == 1) && (iVar2 == 1)) && (iVar3 == 1)) && ((iVar4 == 1 && (iVar5 == 1)))) {
    *(undefined2 *)&this->field_0x5116 = 0;
    if (*(char *)&this[1].field_0x2 != '\0') {
      *(undefined *)(*(int *)&this->field_0x2ee4 + 0xaa) = 1;
    }
    if (*(char *)&this[1].field_0x4 != '\0') {
      *(undefined *)(*(int *)&this->field_0x2f1c + 0xaa) = 1;
    }
    *(undefined *)&this->field_0x5114 = 2;
  }
  return;
}


/* __thiscall dMenu_Fmap_c::ZoomGridLv1Proc(void) */

void __thiscall dMenu_Fmap_c::ZoomGridLv1Proc(dMenu_Fmap_c *this)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
    if (*(char *)&this->field_0x5164 == '\0') {
      if (((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') ||
         (*(char *)&this->field_0x5165 != '\0')) {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x8c5,(cXyz *)0x0,0,0,d_menu_fmap::_4271,
                   d_menu_fmap::_4271,d_menu_fmap::_4272,d_menu_fmap::_4272,0);
        if (*(char *)&this[1].field_0x2 != '\0') {
          *(undefined *)(*(int *)&this->field_0x2ee4 + 0xaa) = 0;
        }
        if (*(char *)&this[1].field_0x4 != '\0') {
          *(undefined *)(*(int *)&this->field_0x2f1c + 0xaa) = 0;
        }
        *(undefined *)&this->field_0x5165 = 0;
        zoomCursorInit(this);
        *(undefined *)&this->field_0x5114 = 3;
      }
      goto LAB_801b5f64;
    }
  }
  if (*(char *)&this[1].field_0x1 == '\x01') {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8c4,(cXyz *)0x0,0,0,d_menu_fmap::_4271,d_menu_fmap::_4271,
               d_menu_fmap::_4272,d_menu_fmap::_4272,0);
    *(undefined *)&this[1].field_0x1 = 2;
    if (this->mFmapSv == (undefined *)0x0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"d_menu_fmap.h",0x1e3,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap.h",0x1e3,&DAT_8035fc8d);
    }
    this->mFmapSv[1] = 2;
    zoom200x200Init(this);
    paneTranceZoom2Map(this,0,DAT_803e60cb,
                       *(float *)&this->field_0x5134 *
                       (*(float *)&this->field_0x3838 / d_menu_fmap::_4719),
                       *(float *)&this->field_0x5138 *
                       (*(float *)&this->field_0x383c / d_menu_fmap::_4719),d_menu_fmap::_4256,
                       d_menu_fmap::_4256,
                       *(float *)&this->field_0x2f78 / *(float *)&this->field_0x3838,
                       d_menu_fmap::_4271,'\x02',0);
    iVar2 = 0;
    iVar3 = 8;
    do {
      *(undefined *)(*(int *)(&this->field_0x2c0c + iVar2) + 0xae) = 0;
      iVar2 = iVar2 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *(undefined *)(*(int *)&this->field_0x2f8c + 0xae) = 0;
    *(undefined2 *)&this->field_0x5116 = 0;
    *(undefined *)&this->field_0x5114 = 4;
  }
  *(undefined *)&this->field_0x5164 = 0;
LAB_801b5f64:
  zoomCursorAnime(this);
  return;
}


/* __thiscall dMenu_Fmap_c::zoom200x200Init(void) */

void __thiscall dMenu_Fmap_c::zoom200x200Init(dMenu_Fmap_c *this)

{
  char cVar1;
  ulong uVar2;
  
  if (this->mFmapSv == (undefined *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",500,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",500,&DAT_8035fc8d);
  }
  cVar1 = this->mFmapSv[5];
  if (this->mFmapSv == (undefined *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_fmap.h",0x1e9,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x1e9,&DAT_8035fc8d);
  }
  zoomMapAlphaSet(this,this->mFmapSv[4],cVar1,(fopMsgM_pane_class *)&this->field_0x337c,'\x1e');
  zoomCursorInit(this);
  setDspHugeMapLink(this);
  checkDspHugeMapLink(this);
  checkDspHugeMapShip(this);
  *(undefined *)(*(int *)&this->field_0x3814 + 0xaa) = 1;
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dMenu_Fmap_c::ZoomGridLv1Out(void) */

void __thiscall dMenu_Fmap_c::ZoomGridLv1Out(dMenu_Fmap_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  
  iVar1 = selGridMaskAlphaCtrl
                    (this,*(short *)&this->field_0x5116 - (ushort)DAT_803e60cc,DAT_803e60ca,'\0',1);
  iVar2 = fmapMaskAlphaCtrl(this,*(short *)&this->field_0x5116 - (ushort)DAT_803e60cc,DAT_803e60ca,
                            '\0',1);
  iVar3 = paneTranceZoomMap(this,*(short *)&this->field_0x5116 - (ushort)DAT_803e60d8,DAT_803e60ca,
                            d_menu_fmap::_4256,d_menu_fmap::_4256,
                            *(float *)&this->field_0x2e90 - *(float *)&this->field_0x30b8,
                            *(float *)&this->field_0x2e94 - *(float *)&this->field_0x30bc,
                            d_menu_fmap::_4271,
                            *(float *)&this->field_0x2e98 / *(float *)&this->field_0x30c8,'\x02',1);
  iVar4 = paneAlphaFmapCursor(this,(fopMsgM_pane_class *)&this->field_0x2c0c,
                              *(short *)&this->field_0x5116 - (ushort)DAT_803e60d8,DAT_803e60ca,'\0'
                              ,1);
  iVar5 = paneAlphaFmapCursor(this,(fopMsgM_pane_class *)&this->field_0x2a4c,
                              *(short *)&this->field_0x5116 - (ushort)DAT_803e60cc,DAT_803e60d7,'\0'
                              ,0);
  *(short *)&this->field_0x5116 = *(short *)&this->field_0x5116 + 1;
  if ((((iVar1 == 1) && (iVar2 == 1)) && (iVar3 == 1)) && ((iVar4 == 1 && (iVar5 == 1)))) {
    *(undefined2 *)&this->field_0x5116 = 0;
    *(undefined *)(*(int *)&this->field_0x2e74 + 0xaa) = 0;
    *(undefined *)(*(int *)&this->field_0x2eac + 0xaa) = 0;
    *(undefined *)(*(int *)&this->field_0x30a4 + 0xaa) = 0;
    *(undefined *)&this[1].field_0x1 = 0;
    if (this->mFmapSv == (undefined *)0x0) {
      uVar6 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar6,"d_menu_fmap.h",0x1e3,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap.h",0x1e3,&DAT_8035fc8d);
    }
    this->mFmapSv[1] = 0;
    *(undefined *)&this->field_0x5114 = 0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Fmap_c::ZoomGridLv2In(void) */

void __thiscall dMenu_Fmap_c::ZoomGridLv2In(dMenu_Fmap_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = paneTranceZoom2Map(this,*(short *)&this->field_0x5116,DAT_803e60cb,
                             *(float *)&this->field_0x5134 *
                             (*(float *)&this->field_0x3838 / d_menu_fmap::_4719),
                             *(float *)&this->field_0x5138 *
                             (*(float *)&this->field_0x383c / d_menu_fmap::_4719),d_menu_fmap::_4256
                             ,d_menu_fmap::_4256,
                             *(float *)&this->field_0x2f78 / *(float *)&this->field_0x3838,
                             d_menu_fmap::_4271,'\x02',0);
  iVar2 = paneTranceZoomMapAlpah(this,*(short *)&this->field_0x5116,DAT_803e60cb,'\x02',1);
  *(short *)&this->field_0x5116 = *(short *)&this->field_0x5116 + 1;
  if ((iVar1 == 1) && (iVar2 == 1)) {
    *(undefined2 *)&this->field_0x5116 = 0;
    if (*(char *)&this[1].field_0x3 == '\0') {
      *(undefined *)(*(int *)&this->field_0x32d4 + 0xaa) = 0;
    }
    else {
      *(undefined *)(*(int *)&this->field_0x32d4 + 0xaa) = 1;
    }
    if (*(char *)&this[1].field_0x5 == '\0') {
      *(undefined *)(*(int *)&this->field_0x330c + 0xaa) = 0;
    }
    else {
      *(undefined *)(*(int *)&this->field_0x330c + 0xaa) = 1;
    }
    *(undefined *)&this->field_0x5114 = 5;
  }
  return;
}


/* __thiscall dMenu_Fmap_c::ZoomGridLv2Proc(void) */

void __thiscall dMenu_Fmap_c::ZoomGridLv2Proc(dMenu_Fmap_c *this)

{
  if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8c5,(cXyz *)0x0,0,0,d_menu_fmap::_4271,d_menu_fmap::_4271,
               d_menu_fmap::_4272,d_menu_fmap::_4272,0);
    if (*(char *)&this[1].field_0x3 != '\0') {
      *(undefined *)(*(int *)&this->field_0x32d4 + 0xaa) = 0;
    }
    if (*(char *)&this[1].field_0x5 != '\0') {
      *(undefined *)(*(int *)&this->field_0x330c + 0xaa) = 0;
    }
    *(undefined *)&this->field_0x5165 = 0;
    zoomCursorInit(this);
    *(undefined *)&this->field_0x5114 = 6;
  }
  zoomCursorAnime(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Fmap_c::ZoomGridLv2Out(void) */

void __thiscall dMenu_Fmap_c::ZoomGridLv2Out(dMenu_Fmap_c *this)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  
  iVar1 = paneTranceZoom2Map(this,*(short *)&this->field_0x5116,DAT_803e60cb,d_menu_fmap::_4256,
                             d_menu_fmap::_4256,
                             *(float *)&this->field_0x5134 *
                             (*(float *)&this->field_0x3838 / d_menu_fmap::_4719),
                             *(float *)&this->field_0x5138 *
                             (*(float *)&this->field_0x383c / d_menu_fmap::_4719),d_menu_fmap::_4271
                             ,*(float *)&this->field_0x2f78 / *(float *)&this->field_0x3838,'\x02',1
                            );
  iVar2 = paneTranceZoomMapAlpah(this,*(short *)&this->field_0x5116,DAT_803e60cb,'\x02',0);
  if (((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') &&
     (*(char *)&this->field_0x5165 == '\0')) {
    *(undefined *)&this->field_0x5165 = 1;
  }
  *(short *)&this->field_0x5116 = *(short *)&this->field_0x5116 + 1;
  if ((iVar1 == 1) && (iVar2 == 1)) {
    *(undefined *)&this[1].field_0x1 = 1;
    if (this->mFmapSv == (undefined *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_menu_fmap.h",0x1e3,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap.h",0x1e3,&DAT_8035fc8d);
    }
    this->mFmapSv[1] = 1;
    if (*(char *)&this[1].field_0x2 != '\0') {
      *(undefined *)(*(int *)&this->field_0x2ee4 + 0xaa) = 1;
    }
    iVar1 = 0;
    *(undefined *)(*(int *)&this->field_0x3814 + 0xaa) = 0;
    iVar2 = 8;
    do {
      *(undefined *)(*(int *)(&this->field_0x2c0c + iVar1) + 0xae) = 1;
      iVar1 = iVar1 + 0x38;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(undefined *)(*(int *)&this->field_0x2f8c + 0xae) = 1;
    *(undefined2 *)&this->field_0x5116 = 0;
    *(undefined *)&this->field_0x5114 = 2;
  }
  return;
}


/* __thiscall dMenu_Fmap_c::move_normal(void) */

void __thiscall dMenu_Fmap_c::move_normal(dMenu_Fmap_c *this)

{
  Runtime.PPCEABI.H::__ptmf_scall
            ((PTMF *)(&d_menu_fmap::mainProc + (uint)*(byte *)&this->field_0x5113 * 3),this,
             &DAT_80390000);
  return;
}


/* __thiscall dMenu_Fmap_c::FmapProc(void) */

void __thiscall dMenu_Fmap_c::FmapProc(dMenu_Fmap_c *this)

{
  ulong uVar1;
  
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) == 0) {
    FmapProcMain(this);
  }
  else {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8c6,(cXyz *)0x0,0,0,d_menu_fmap::_4271,d_menu_fmap::_4271,
               d_menu_fmap::_4272,d_menu_fmap::_4272,0);
    if (this->mFmapSv == (undefined *)0x0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"d_menu_fmap.h",0x1d8,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap.h",0x1d8,&DAT_8035fc8d);
    }
    *this->mFmapSv = 1;
    *(undefined *)&this->field_0x5113 = 1;
    *(undefined *)&this->field_0x5115 = 0;
  }
  return;
}


/* __thiscall dMenu_Fmap_c::HikakuProc(void) */

void __thiscall dMenu_Fmap_c::HikakuProc(dMenu_Fmap_c *this)

{
  Runtime.PPCEABI.H::__ptmf_scall
            ((PTMF *)(&d_menu_fmap::HikakuProcMain + (uint)*(byte *)&this->field_0x5115 * 3),this,
             &DAT_80390000);
  return;
}


/* __thiscall dMenu_Fmap_c::fmap2Open(void) */

void __thiscall dMenu_Fmap_c::fmap2Open(dMenu_Fmap_c *this)

{
  char cVar1;
  
  cVar1 = dMenu_Fmap2_c::_open((dMenu_Fmap2_c *)&this->field_0x24);
  if (cVar1 == '\x01') {
    if (*(char *)&this->field_0x5169 != '\0') {
      paneTransBase(this,0,DAT_803e60d0,d_menu_fmap::_4256,d_menu_fmap::_4256,'\0',1);
    }
    *(undefined *)&this->field_0x5115 = 1;
  }
  return;
}


/* __thiscall dMenu_Fmap_c::fmap2Move(void) */

void __thiscall dMenu_Fmap_c::fmap2Move(dMenu_Fmap_c *this)

{
  int iVar1;
  
  dMenu_Fmap2_c::_move((dMenu_Fmap2_c *)&this->field_0x24);
  if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) != 0) &&
     (iVar1 = dMenu_Fmap2_c::isLockBbutton((dMenu_Fmap2_c *)&this->field_0x24), iVar1 == 0)) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8ca,(cXyz *)0x0,0,0,d_menu_fmap::_4271,d_menu_fmap::_4271,
               d_menu_fmap::_4272,d_menu_fmap::_4272,0);
    *(undefined *)&this->field_0x5115 = 2;
    *(undefined *)&this->field_0x516a = 0;
    gShipMarkAnimeInit(this);
    return;
  }
  if (((-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3) &&
      (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2)) &&
     ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 5 & 1) == 0)) {
    return;
  }
  iVar1 = dMenu_Fmap2_c::isLockBbutton((dMenu_Fmap2_c *)&this->field_0x24);
  if (iVar1 == 0) {
    paneTransBase(this,0,DAT_803e60d0,d_menu_fmap::_4258,d_menu_fmap::_4256,'\0',0);
    *(undefined *)&this->field_0x516a = 1;
    *(undefined *)&this->field_0x5115 = 2;
  }
  return;
}


/* __thiscall dMenu_Fmap_c::fmap2Close(void) */

void __thiscall dMenu_Fmap_c::fmap2Close(dMenu_Fmap_c *this)

{
  char cVar1;
  
  cVar1 = dMenu_Fmap2_c::_close((dMenu_Fmap2_c *)&this->field_0x24);
  if (cVar1 == '\x01') {
    *(undefined *)&this->field_0x5113 = 0;
    *(undefined *)&this->field_0x5115 = 1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801b6a54) */
/* WARNING: Removing unreachable block (ram,0x801b6a4c) */
/* WARNING: Removing unreachable block (ram,0x801b6a5c) */
/* __thiscall dMenu_Fmap_c::paneTransBase(short,
                                          unsigned char,
                                          float,
                                          float,
                                          unsigned char,
                                          int) */

undefined4 __thiscall
dMenu_Fmap_c::paneTransBase
          (dMenu_Fmap_c *this,short param_1,uchar param_2,float param_3,float param_4,uchar param_5,
          int param_6)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  fopMsgM_pane_class *pfVar3;
  int iVar4;
  fopMsgM_pane_class *this_00;
  int iVar5;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar9;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar8 = (double)param_4;
  dVar9 = (double)param_3;
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
      dVar7 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_5));
      dVar9 = (double)(float)(dVar9 + (double)(float)(dVar7 * (double)(float)(dVar8 - dVar9)));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)&this->field_0x28c4,(double)d_menu_fmap::_4256,dVar9);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)&this->field_0x288c,(double)d_menu_fmap::_4256,dVar9);
      if (param_6 != 2) {
        if (param_6 == 1) {
          dVar7 = (double)(float)((double)d_menu_fmap::_4271 - dVar7);
        }
        iVar2 = 0;
        iVar5 = 0;
        do {
          iVar4 = &this->field_0x0 + iVar5;
          pfVar3 = (fopMsgM_pane_class *)(iVar4 + 0x46f4);
          f_op_msg_mng::fopMsgM_setNowAlpha(pfVar3,(float)dVar7);
          this_00 = (fopMsgM_pane_class *)(iVar4 + 0x479c);
          f_op_msg_mng::fopMsgM_setNowAlpha(this_00,(float)dVar7);
          f_op_msg_mng::fopMsgM_setAlpha(pfVar3);
          f_op_msg_mng::fopMsgM_setAlpha(this_00);
          iVar2 = iVar2 + 1;
          iVar5 = iVar5 + 0x38;
        } while (iVar2 < 3);
        iVar2 = 0;
        iVar5 = 0;
        do {
          pfVar3 = (fopMsgM_pane_class *)(&this->field_0x4844 + iVar5);
          f_op_msg_mng::fopMsgM_setNowAlpha(pfVar3,(float)dVar7);
          f_op_msg_mng::fopMsgM_setAlpha(pfVar3);
          iVar2 = iVar2 + 1;
          iVar5 = iVar5 + 0x38;
        } while (iVar2 < 2);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x288c,(float)dVar7);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)&this->field_0x288c);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x28c4,(float)dVar7);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)&this->field_0x28c4);
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


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801b6f60) */
/* WARNING: Removing unreachable block (ram,0x801b6f50) */
/* WARNING: Removing unreachable block (ram,0x801b6f40) */
/* WARNING: Removing unreachable block (ram,0x801b6f38) */
/* WARNING: Removing unreachable block (ram,0x801b6f48) */
/* WARNING: Removing unreachable block (ram,0x801b6f58) */
/* WARNING: Removing unreachable block (ram,0x801b6f68) */
/* __thiscall dMenu_Fmap_c::paneTranceZoomMap(short,
                                              unsigned char,
                                              float,
                                              float,
                                              float,
                                              float,
                                              float,
                                              float,
                                              unsigned char,
                                              int) */

undefined4 __thiscall
dMenu_Fmap_c::paneTranceZoomMap
          (dMenu_Fmap_c *this,short param_1,uchar param_2,float param_3,float param_4,float param_5,
          float param_6,float param_7,float param_8,uchar param_9,int param_10)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined3 in_register_00000018;
  int iVar6;
  undefined4 uVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  undefined8 in_f25;
  undefined8 in_f26;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar14;
  double local_a8;
  double local_a0;
  double local_98;
  double local_90;
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar14 = (double)param_7;
  dVar13 = (double)param_8;
  dVar11 = (double)param_5;
  dVar12 = (double)param_6;
  dVar9 = (double)param_4;
  dVar8 = (double)param_3;
  uVar7 = 0;
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
  if (param_1 < 0) {
    uVar3 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar3 = 1;
    }
    else {
      dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                 ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_9))
      ;
      fVar1 = (float)(dVar14 + (double)(float)(dVar10 * (double)(float)(dVar13 - dVar14)));
      dVar14 = (double)fVar1;
      f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)&this->field_0x30a4,fVar1);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)&this->field_0x30a4,
                 (double)(float)(dVar8 + (double)(float)(dVar10 * (double)(float)(dVar11 - dVar8))),
                 (double)(float)(dVar9 + (double)(float)(dVar10 * (double)(float)(dVar12 - dVar9))))
      ;
      if (param_10 == 1) {
        dVar10 = (double)(float)((double)d_menu_fmap::_4271 - dVar10);
      }
      if (*(char *)(*(int *)&this->field_0x2ee4 + 0xaa) != '\0') {
        childPaneMoveSp(this,(fopMsgM_pane_class *)&this->field_0x2ee4,
                        (fopMsgM_pane_class *)&this->field_0x30a4,(float)dVar10,(float)dVar14,
                        (float)dVar14);
        iVar5 = *(int *)&this->field_0x5124;
        local_a0 = (double)CONCAT44(0x43300000,
                                    (int)(d_menu_fmap::_4260 * *(float *)&this->field_0x2f14) ^
                                    0x80000000);
        local_a0 = local_a0 - d_menu_fmap::_4609;
        piVar4 = *(int **)&this->field_0x2ee4;
        local_90 = (double)CONCAT44(0x43300000,
                                    (int)(d_menu_fmap::_4260 * *(float *)&this->field_0x2f10) ^
                                    0x80000000);
        piVar4[0x27] = (int)(float)(local_90 - d_menu_fmap::_4609);
        piVar4[0x28] = (int)(float)local_a0;
        *(undefined *)(piVar4 + 0x2a) = 0x7a;
        piVar4[0x29] = iVar5;
        (**(code **)(*piVar4 + 0x20))();
      }
      if (*(char *)(*(int *)&this->field_0x2f1c + 0xaa) != '\0') {
        childPaneMoveSp(this,(fopMsgM_pane_class *)&this->field_0x2f1c,
                        (fopMsgM_pane_class *)&this->field_0x30a4,(float)dVar10,(float)dVar14,
                        (float)dVar14);
        iVar5 = *(int *)&this->field_0x5130;
        local_98 = (double)CONCAT44(0x43300000,
                                    (int)(d_menu_fmap::_4260 * *(float *)&this->field_0x2f4c) ^
                                    0x80000000);
        local_98 = local_98 - d_menu_fmap::_4609;
        piVar4 = *(int **)&this->field_0x2f1c;
        local_a8 = (double)CONCAT44(0x43300000,
                                    (int)(d_menu_fmap::_4260 * *(float *)&this->field_0x2f48) ^
                                    0x80000000);
        piVar4[0x27] = (int)(float)(local_a8 - d_menu_fmap::_4609);
        piVar4[0x28] = (int)(float)local_98;
        *(undefined *)(piVar4 + 0x2a) = 0x7a;
        piVar4[0x29] = iVar5;
        (**(code **)(*piVar4 + 0x20))();
      }
      iVar5 = *(int *)&this->field_0x3034;
      if (*(char *)(iVar5 + 0xaa) != '\0') {
        fVar1 = (float)((double)d_menu_fmap::_6809 * dVar14);
        fVar2 = d_menu_fmap::_4256;
        if (d_menu_fmap::_4256 < fVar1) {
          fVar2 = fVar1;
        }
        *(float *)(iVar5 + 0xe8) = fVar2;
        fVar2 = d_menu_fmap::_4256;
        if (d_menu_fmap::_4256 < fVar1) {
          fVar2 = fVar1;
        }
        *(float *)(iVar5 + 0xec) = fVar2;
        childPaneMoveSp(this,(fopMsgM_pane_class *)&this->field_0x3034,
                        (fopMsgM_pane_class *)&this->field_0x30a4,(float)dVar10,(float)dVar14,
                        (float)dVar14);
      }
      iVar5 = *(int *)&this->field_0x2ffc;
      if (*(char *)(iVar5 + 0xaa) != '\0') {
        dVar8 = (double)d_menu_fmap::_6811;
        dVar9 = (double)d_menu_fmap::_6812;
        fVar1 = d_menu_fmap::_4256;
        if (d_menu_fmap::_4256 < (float)((double)d_menu_fmap::_6810 * dVar14)) {
          fVar1 = (float)((double)d_menu_fmap::_6810 * dVar14);
        }
        *(float *)(iVar5 + 0xe8) = fVar1;
        fVar1 = d_menu_fmap::_4256;
        if (d_menu_fmap::_4256 < (float)(dVar8 * dVar14)) {
          fVar1 = (float)(dVar8 * dVar14);
        }
        *(float *)(iVar5 + 0xec) = fVar1;
        *(float *)(*(int *)&this->field_0x2ffc + 0xe4) = (float)(dVar9 * dVar14);
        childPaneMoveSp(this,(fopMsgM_pane_class *)&this->field_0x2ffc,
                        (fopMsgM_pane_class *)&this->field_0x30a4,(float)dVar10,(float)dVar14,
                        (float)dVar14);
        dDlst_2DOutFont_c::messageSet(*(dDlst_2DOutFont_c **)&this->field_0x2888,0x319b);
        uVar3 = *(undefined4 *)&this->field_0x300c;
        iVar5 = *(int *)&this->field_0x2888;
        *(undefined4 *)(iVar5 + 0x30) = *(undefined4 *)&this->field_0x3008;
        *(undefined4 *)(iVar5 + 0x34) = uVar3;
        dDlst_2DOutFont_c::move(*(dDlst_2DOutFont_c **)&this->field_0x2888);
      }
      if (*(char *)(*(int *)&this->field_0x306c + 0xaa) != '\0') {
        childPaneMoveSp(this,(fopMsgM_pane_class *)&this->field_0x306c,
                        (fopMsgM_pane_class *)&this->field_0x30a4,(float)dVar10,(float)dVar14,
                        (float)dVar14);
      }
      iVar5 = 0;
      iVar6 = 0;
      do {
        childPaneMoveSp(this,(fopMsgM_pane_class *)(&this->field_0x30dc + iVar6),
                        (fopMsgM_pane_class *)&this->field_0x30a4,(float)dVar10,(float)dVar14,
                        (float)dVar14);
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 0x38;
      } while (iVar5 < 9);
      childPaneMoveSp(this,(fopMsgM_pane_class *)&this->field_0x2f8c,
                      (fopMsgM_pane_class *)&this->field_0x30a4,(float)dVar10,(float)dVar14,
                      (float)dVar14);
      childPaneMoveSp(this,(fopMsgM_pane_class *)&this->field_0x2fc4,
                      (fopMsgM_pane_class *)&this->field_0x30a4,(float)dVar10,(float)dVar14,
                      (float)dVar14);
      childPaneMoveSp(this,(fopMsgM_pane_class *)&this->field_0x2f54,
                      (fopMsgM_pane_class *)&this->field_0x30a4,(float)dVar10,(float)dVar14,
                      (float)dVar14);
      iVar5 = 0;
      iVar6 = 0;
      do {
        childPaneMoveSp(this,(fopMsgM_pane_class *)(&this->field_0x2c0c + iVar6),
                        (fopMsgM_pane_class *)&this->field_0x30a4,(float)dVar10,d_menu_fmap::_4271,
                        d_menu_fmap::_4271);
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 0x38;
      } while (iVar5 < 8);
      if (param_10 != 2) {
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x2f8c,(float)dVar10);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)&this->field_0x2f8c);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x30a4,(float)dVar10);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)&this->field_0x30a4);
      }
      uVar3 = 0;
    }
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  __psq_l0(auStack40,uVar7);
  __psq_l1(auStack40,uVar7);
  __psq_l0(auStack56,uVar7);
  __psq_l1(auStack56,uVar7);
  __psq_l0(auStack72,uVar7);
  __psq_l1(auStack72,uVar7);
  __psq_l0(auStack88,uVar7);
  __psq_l1(auStack88,uVar7);
  __psq_l0(auStack104,uVar7);
  __psq_l1(auStack104,uVar7);
  return uVar3;
}


/* __thiscall dMenu_Fmap_c::paneTranceZoomMapAlpah(short,
                                                   unsigned char,
                                                   unsigned char,
                                                   int) */

undefined4 __thiscall
dMenu_Fmap_c::paneTranceZoomMapAlpah
          (dMenu_Fmap_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

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
          dVar2 = (double)(float)((double)d_menu_fmap::_4271 - dVar2);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x30a4,(float)dVar2);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)&this->field_0x30a4);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801b74c4) */
/* WARNING: Removing unreachable block (ram,0x801b74b4) */
/* WARNING: Removing unreachable block (ram,0x801b74a4) */
/* WARNING: Removing unreachable block (ram,0x801b749c) */
/* WARNING: Removing unreachable block (ram,0x801b74ac) */
/* WARNING: Removing unreachable block (ram,0x801b74bc) */
/* WARNING: Removing unreachable block (ram,0x801b74cc) */
/* __thiscall dMenu_Fmap_c::paneTranceZoom2Map(short,
                                               unsigned char,
                                               float,
                                               float,
                                               float,
                                               float,
                                               float,
                                               float,
                                               unsigned char,
                                               int) */

undefined4 __thiscall
dMenu_Fmap_c::paneTranceZoom2Map
          (dMenu_Fmap_c *this,short param_1,uchar param_2,float param_3,float param_4,float param_5,
          float param_6,float param_7,float param_8,uchar param_9,int param_10)

{
  undefined4 uVar1;
  int *piVar2;
  undefined3 in_register_00000018;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  undefined8 in_f25;
  undefined8 in_f26;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar11;
  double dVar12;
  double local_c8;
  double local_c0;
  double local_b8;
  double local_b0;
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar10 = (double)param_7;
  dVar11 = (double)param_8;
  dVar8 = (double)param_5;
  dVar9 = (double)param_6;
  dVar7 = (double)param_4;
  dVar12 = (double)param_3;
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
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_9));
      dVar11 = (double)(float)(dVar6 * (double)(float)(dVar11 - dVar10));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)&this->field_0x3814,
                 (double)(float)(dVar12 + (double)(float)(dVar6 * (double)(float)(dVar8 - dVar12))),
                 (double)(float)(dVar7 + (double)(float)(dVar6 * (double)(float)(dVar9 - dVar7))));
      dVar12 = (double)(float)(dVar10 + dVar11);
      f_op_msg_mng::fopMsgM_paneScaleXY
                ((fopMsgM_pane_class *)&this->field_0x3814,(float)(dVar10 + dVar11));
      if (param_10 == 1) {
        dVar6 = (double)(float)((double)d_menu_fmap::_4271 - dVar6);
      }
      if (*(char *)(*(int *)&this->field_0x32d4 + 0xaa) != '\0') {
        childPaneMoveSp(this,(fopMsgM_pane_class *)&this->field_0x32d4,
                        (fopMsgM_pane_class *)&this->field_0x3814,(float)dVar6,(float)dVar12,
                        (float)dVar12);
        iVar3 = *(int *)&this->field_0x5124;
        local_c0 = (double)CONCAT44(0x43300000,
                                    (int)(d_menu_fmap::_4260 * *(float *)&this->field_0x3304) ^
                                    0x80000000);
        local_c0 = local_c0 - d_menu_fmap::_4609;
        piVar2 = *(int **)&this->field_0x32d4;
        local_b0 = (double)CONCAT44(0x43300000,
                                    (int)(d_menu_fmap::_4260 * *(float *)&this->field_0x3300) ^
                                    0x80000000);
        piVar2[0x27] = (int)(float)(local_b0 - d_menu_fmap::_4609);
        piVar2[0x28] = (int)(float)local_c0;
        *(undefined *)(piVar2 + 0x2a) = 0x7a;
        piVar2[0x29] = iVar3;
        (**(code **)(*piVar2 + 0x20))();
      }
      if (*(char *)(*(int *)&this->field_0x330c + 0xaa) != '\0') {
        childPaneMoveSp(this,(fopMsgM_pane_class *)&this->field_0x330c,
                        (fopMsgM_pane_class *)&this->field_0x3814,(float)dVar6,(float)dVar12,
                        (float)dVar12);
        iVar3 = *(int *)&this->field_0x5130;
        local_b8 = (double)CONCAT44(0x43300000,
                                    (int)(d_menu_fmap::_4260 * *(float *)&this->field_0x333c) ^
                                    0x80000000);
        local_b8 = local_b8 - d_menu_fmap::_4609;
        piVar2 = *(int **)&this->field_0x330c;
        local_c8 = (double)CONCAT44(0x43300000,
                                    (int)(d_menu_fmap::_4260 * *(float *)&this->field_0x3338) ^
                                    0x80000000);
        piVar2[0x27] = (int)(float)(local_c8 - d_menu_fmap::_4609);
        piVar2[0x28] = (int)(float)local_b8;
        *(undefined *)(piVar2 + 0x2a) = 0x7a;
        piVar2[0x29] = iVar3;
        (**(code **)(*piVar2 + 0x20))();
      }
      childPaneMoveSp(this,(fopMsgM_pane_class *)&this->field_0x337c,
                      (fopMsgM_pane_class *)&this->field_0x3814,(float)dVar6,(float)dVar12,
                      (float)dVar12);
      childPaneMoveSp(this,(fopMsgM_pane_class *)&this->field_0x3344,
                      (fopMsgM_pane_class *)&this->field_0x3814,(float)dVar6,(float)dVar12,
                      (float)dVar12);
      iVar3 = 0;
      iVar4 = 0;
      do {
        childPaneMoveSp(this,(fopMsgM_pane_class *)(&this->field_0x384c + iVar4),
                        (fopMsgM_pane_class *)&this->field_0x3814,(float)dVar6,(float)dVar12,
                        (float)dVar12);
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x38;
      } while (iVar3 < 7);
      iVar3 = 0;
      iVar4 = 0;
      do {
        childPaneMoveSp(this,(fopMsgM_pane_class *)(&this->field_0x33b4 + iVar4),
                        (fopMsgM_pane_class *)&this->field_0x3814,(float)dVar6,(float)dVar12,
                        (float)dVar12);
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x38;
      } while (iVar3 < 5);
      local_b8 = (double)CONCAT44(0x43300000,
                                  (int)(d_menu_fmap::_4260 * *(float *)&this->field_0x341c) ^
                                  0x80000000);
      local_b8 = local_b8 - d_menu_fmap::_4609;
      piVar2 = *(int **)&this->field_0x33ec;
      local_c8 = (double)CONCAT44(0x43300000,
                                  (int)(d_menu_fmap::_4260 * *(float *)&this->field_0x3418) ^
                                  0x80000000);
      piVar2[0x27] = (int)(float)(local_c8 - d_menu_fmap::_4609);
      piVar2[0x28] = (int)(float)local_b8;
      *(undefined *)(piVar2 + 0x2a) = 0x7a;
      piVar2[0x29] = (int)d_menu_fmap::_6896;
      (**(code **)(*piVar2 + 0x20))();
      dVar7 = (double)CONCAT44(0x43300000,
                               (int)(d_menu_fmap::_4260 * *(float *)&this->field_0x34c4) ^
                               0x80000000) - d_menu_fmap::_4609;
      piVar2 = *(int **)&this->field_0x3494;
      piVar2[0x27] = (int)(float)((double)CONCAT44(0x43300000,
                                                   (int)(d_menu_fmap::_4260 *
                                                        *(float *)&this->field_0x34c0) ^ 0x80000000)
                                 - d_menu_fmap::_4609);
      piVar2[0x28] = (int)(float)dVar7;
      *(undefined *)(piVar2 + 0x2a) = 0x7a;
      piVar2[0x29] = (int)d_menu_fmap::_6896;
      (**(code **)(*piVar2 + 0x20))();
      iVar3 = 0;
      iVar4 = 0;
      do {
        childPaneMoveSp(this,(fopMsgM_pane_class *)(&this->field_0x34cc + iVar4),
                        (fopMsgM_pane_class *)&this->field_0x3814,(float)dVar6,(float)dVar12,
                        (float)dVar12);
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x38;
      } while (iVar3 < 0xf);
      if (param_10 != 2) {
        iVar3 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x337c,(float)dVar6);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)&this->field_0x337c);
          f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x3814,(float)dVar6);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)&this->field_0x3814);
          iVar3 = iVar3 + 1;
        } while (iVar3 < 4);
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
  __psq_l0(auStack88,uVar5);
  __psq_l1(auStack88,uVar5);
  __psq_l0(auStack104,uVar5);
  __psq_l1(auStack104,uVar5);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801b7590) */
/* __thiscall dMenu_Fmap_c::paneAlphaFmapCursor(fopMsgM_pane_class *,
                                                short,
                                                unsigned char,
                                                unsigned char,
                                                int) */

undefined4 __thiscall
dMenu_Fmap_c::paneAlphaFmapCursor
          (dMenu_Fmap_c *this,fopMsgM_pane_class *param_1,short param_2,uchar param_3,uchar param_4,
          int param_5)

{
  undefined4 uVar1;
  undefined3 in_register_0000001c;
  int iVar2;
  fopMsgM_pane_class *this_00;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_2 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_3 < (int)param_2) {
      uVar1 = 1;
    }
    else {
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_3,(int)param_2,CONCAT31(in_register_0000001c,param_4));
      if (param_5 != 2) {
        if (param_5 == 1) {
          dVar5 = (double)(float)((double)d_menu_fmap::_4271 - dVar5);
        }
        iVar2 = 0;
        iVar3 = 0;
        do {
          this_00 = (fopMsgM_pane_class *)((int)&param_1->mpPane + iVar3);
          f_op_msg_mng::fopMsgM_setNowAlpha(this_00,(float)dVar5);
          f_op_msg_mng::fopMsgM_setAlpha(this_00);
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 0x38;
        } while (iVar2 < 8);
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return uVar1;
}


/* WARNING: Removing unreachable block (ram,0x801b7684) */
/* __thiscall dMenu_Fmap_c::PaneAlphaSelvageItem(short,
                                                 unsigned char) */

undefined4 __thiscall
dMenu_Fmap_c::PaneAlphaSelvageItem(dMenu_Fmap_c *this,short param_1,uchar param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar3 = 0;
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
      dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease((uint)param_2,(int)param_1,0);
      iVar2 = (uint)*(byte *)&this->field_0x513d * 0x38;
      if (*(char *)(&this->field_0x2a11 + iVar2) != '\0') {
        f_op_msg_mng::fopMsgM_setNowAlpha
                  ((fopMsgM_pane_class *)(&this->field_0x29dc + iVar2),
                   (float)((double)d_menu_fmap::_4271 - dVar4));
        f_op_msg_mng::fopMsgM_setAlpha
                  ((fopMsgM_pane_class *)
                   (&this->field_0x29dc + (uint)*(byte *)&this->field_0x513d * 0x38));
      }
      if (*(char *)&this->field_0x513c == '\x01') {
        f_op_msg_mng::fopMsgM_setNowAlpha
                  ((fopMsgM_pane_class *)
                   (&this->field_0x29dc + (*(byte *)&this->field_0x513d ^ 1) * 0x38),(float)dVar4);
        f_op_msg_mng::fopMsgM_setAlpha
                  ((fopMsgM_pane_class *)
                   (&this->field_0x29dc + (*(byte *)&this->field_0x513d ^ 1) * 0x38));
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return uVar1;
}


/* __thiscall dMenu_Fmap_c::gShipMarkAnimeInit(void) */

void __thiscall dMenu_Fmap_c::gShipMarkAnimeInit(dMenu_Fmap_c *this)

{
  int iVar1;
  ushort uVar2;
  
  iVar1 = dSv_player_map_c::isOpenMap
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x23);
  if (iVar1 == 0) {
    *(undefined *)&this[1].field_0x2c = 0;
  }
  else {
    *(undefined *)&this[1].field_0x2c = 1;
    uVar2 = dSv_event_c::getEventReg
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x8803);
    if ((uVar2 & 0xff) == 3) {
      *(undefined *)&this[1].field_0x2d = 1;
    }
    else {
      *(undefined *)&this[1].field_0x2d = 0;
      *(undefined *)&this[1].field_0x2e = 0;
      if ((d_menu_fmap::_6989 <=
           d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime) ||
         ((d_menu_fmap::_4256 <=
           d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime &&
          (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime <=
           d_menu_fmap::_6896)))) {
        *(undefined *)&this[1].field_0x2e = 1;
        iVar1 = d_kankyo::dKy_moon_type_chk();
        *(undefined *)(*(int *)(&this->field_0x4f44 + iVar1 * 0x38) + 0xaa) = 1;
      }
    }
    *(undefined *)&this[1].field_0x2f = DAT_803e61b8;
    *(undefined *)&this[1].field_0x30 = 1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_Fmap_c::gShipMarkAnime(void) */

void __thiscall dMenu_Fmap_c::gShipMarkAnime(dMenu_Fmap_c *this)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  double dVar4;
  
  if (((*(char *)&this[1].field_0x2c != '\0') && (*(char *)&this[1].field_0x2d == '\0')) &&
     (*(char *)&this[1].field_0x2e != '\0')) {
    iVar2 = d_kankyo::dKy_moon_type_chk();
    dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                              (DAT_803e61b8,*(undefined *)&this[1].field_0x2f,2);
    bVar1 = DAT_803e61ba;
    if (*(char *)&this[1].field_0x30 == '\0') {
      dVar4 = (double)(float)((double)d_menu_fmap::_4271 - dVar4);
    }
    cVar3 = Runtime.PPCEABI.H::__cvt_fp2unsigned
                      ((double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                                        (uint)DAT_803e61b9 -
                                                                        (uint)DAT_803e61ba ^
                                                                        0x80000000) -
                                                      d_menu_fmap::_4609) * dVar4));
    *(byte *)(&this->field_0x4f79 + iVar2 * 0x38) = bVar1 + cVar3;
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(&this->field_0x4f44 + iVar2 * 0x38));
    if (*(char *)&this[1].field_0x2f == '\0') {
      *(undefined *)&this[1].field_0x2f = DAT_803e61b8;
      *(byte *)&this[1].field_0x30 = *(byte *)&this[1].field_0x30 ^ 1;
    }
    else {
      *(char *)&this[1].field_0x2f = *(char *)&this[1].field_0x2f + -1;
    }
  }
  return;
}


/* __thiscall dMenu_Fmap_c::_open_warpMode(void) */

undefined4 __thiscall dMenu_Fmap_c::_open_warpMode(dMenu_Fmap_c *this)

{
  double dVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  if (*(short *)&this->field_0x5116 == 0) {
    init_warpMode(this);
  }
  iVar3 = paneTransBase(this,*(short *)&this->field_0x5116,DAT_803e60d0,d_menu_fmap::_4256,
                        d_menu_fmap::_4256,'\0',0);
  *(short *)&this->field_0x5116 = *(short *)&this->field_0x5116 + 1;
  dVar1 = (double)CONCAT44(0x43300000,(uint)*(byte *)&this->field_0x5176) - d_menu_fmap::_5228;
  dVar2 = (double)CONCAT44(0x43300000,(uint)DAT_803e61a3) - d_menu_fmap::_5228;
  *(byte *)&this->field_0x5176 = *(byte *)&this->field_0x5176 + 1;
  *(byte *)&this->field_0x5176 =
       *(byte *)&this->field_0x5176 -
       (char)((uint)*(byte *)&this->field_0x5176 / ((uint)DAT_803e61a3 << 2)) *
       (char)((uint)DAT_803e61a3 << 2);
  setDspWarpBackCornerColor(this,(float)dVar1 / (float)dVar2);
  if (iVar3 == 1) {
    iVar3 = 0;
    *(undefined2 *)&this->field_0x5116 = 0;
    iVar6 = 9;
    do {
      iVar4 = *(int *)(&this->field_0x50dc + iVar3);
      *(uint *)(iVar4 + 0x20c) = *(uint *)(iVar4 + 0x20c) & 0xfffffffb;
      iVar3 = iVar3 + 4;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    *(uint *)(*(int *)&this->field_0x50d8 + 0x20c) =
         *(uint *)(*(int *)&this->field_0x50d8 + 0x20c) & 0xfffffffb;
    *(undefined *)&this->field_0x516c = 0;
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801b7cb0) */
/* __thiscall dMenu_Fmap_c::init_warpMode(void) */

void __thiscall dMenu_Fmap_c::init_warpMode(dMenu_Fmap_c *this)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  cXyz local_58;
  cXyz local_4c;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,0x8cb,(cXyz *)0x0,0,0,d_menu_fmap::_4271,d_menu_fmap::_4271,
             d_menu_fmap::_4272,d_menu_fmap::_4272,0);
  *(undefined *)&this->field_0x516b = 1;
  *(undefined *)&this[1].field_0x1 = 4;
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ != '\0') {
    *(undefined *)(*(int *)&this->field_0x4cdc + 0xaa) = 0;
    *(float *)&this->field_0x4d2c = *(float *)&this->field_0x4d2c - d_menu_fmap::_4441;
    *(undefined4 *)&this->field_0x4d34 = *(undefined4 *)&this->field_0x4d2c;
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)&this->field_0x4d14);
  }
  if (this->mFmapSv == (undefined *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap.h",0x1ff,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x1ff,&DAT_8035fc8d);
  }
  if (-4 < (char)this->mFmapSv[6]) {
    if (this->mFmapSv == (undefined *)0x0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"d_menu_fmap.h",0x20a,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap.h",0x20a,&DAT_8035fc8d);
    }
    if (-4 < (char)this->mFmapSv[7]) goto LAB_801b7bd0;
  }
  if (this->mFmapSv == (undefined *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap.h",0x204,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x204,&DAT_8035fc8d);
  }
  this->mFmapSv[6] = 0xfe;
  if (this->mFmapSv == (undefined *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap.h",0x20f,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x20f,&DAT_8035fc8d);
  }
  this->mFmapSv[7] = 0xfe;
LAB_801b7bd0:
  selCursorInit(this);
  selCursorMoveWarp(this);
  *(undefined *)&this->field_0x516d = 0;
  local_40 = d_menu_fmap::_4256;
  local_3c = d_menu_fmap::_4256;
  local_38 = d_menu_fmap::_4256;
  local_4c.x = d_menu_fmap::_4256;
  local_4c.y = d_menu_fmap::_4256;
  local_4c.z = d_menu_fmap::_4256;
  setWrapBackEmitter(this,&local_4c);
  *(uint *)(*(int *)&this->field_0x50d8 + 0x20c) =
       *(uint *)(*(int *)&this->field_0x50d8 + 0x20c) | 4;
  iVar3 = 0;
  iVar4 = 0;
  dVar6 = (double)d_menu_fmap::_4256;
  local_2c = d_menu_fmap::_4256;
  do {
    local_58.x = *(float *)((int)&DAT_803e60ec + iVar4);
    local_58.y = *(float *)((int)&DAT_803e6110 + iVar4);
    local_58.z = (float)dVar6;
    local_34 = local_58.x;
    local_30 = local_58.y;
    setWrapSpotEmitter(this,iVar3,&local_58);
    iVar2 = *(int *)(&this->field_0x50dc + iVar4);
    *(uint *)(iVar2 + 0x20c) = *(uint *)(iVar2 + 0x20c) | 4;
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar3 < 9);
  areaTextChangeAnimeInit(this);
  *(undefined *)&this->field_0x5176 = 0;
  setDspWarpBackCornerColor(this,d_menu_fmap::_4256);
  warpAreaAnime0(this);
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x801b7e08) */
/* WARNING: Removing unreachable block (ram,0x801b7e10) */
/* __thiscall dMenu_Fmap_c::selCursorMoveWarp(void) */

void __thiscall dMenu_Fmap_c::selCursorMoveWarp(dMenu_Fmap_c *this)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 in_f30;
  double y;
  undefined8 in_f31;
  double x;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (this->mFmapSv == (undefined *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap.h",0x1ff,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x1ff,&DAT_8035fc8d);
  }
  x = (double)(d_menu_fmap::_4718 *
              (float)((double)CONCAT44(0x43300000,(int)(char)this->mFmapSv[6] ^ 0x80000000) -
                     d_menu_fmap::_4609));
  if (this->mFmapSv == (undefined *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_fmap.h",0x20a,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x20a,&DAT_8035fc8d);
  }
  y = (double)(d_menu_fmap::_4718 *
              (float)((double)CONCAT44(0x43300000,(int)(char)this->mFmapSv[7] ^ 0x80000000) -
                     d_menu_fmap::_4609));
  iVar2 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(&this->field_0x2a4c + iVar3),x,y);
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar2 < 8);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return;
}


/* __thiscall dMenu_Fmap_c::_close_warpMode(void) */

bool __thiscall dMenu_Fmap_c::_close_warpMode(dMenu_Fmap_c *this)

{
  int iVar1;
  
  iVar1 = paneTransBase(this,*(short *)&this->field_0x5116,DAT_803e60d0,d_menu_fmap::_4256,
                        d_menu_fmap::_4256,'\0',1);
  *(short *)&this->field_0x5116 = *(short *)&this->field_0x5116 + 1;
  if (iVar1 == 1) {
    *(undefined2 *)&this->field_0x5116 = 0;
    *(undefined *)&this->field_0x516b = 0;
  }
  return iVar1 == 1;
}


/* __thiscall dMenu_Fmap_c::moveMain_warpMode(void) */

void __thiscall dMenu_Fmap_c::moveMain_warpMode(dMenu_Fmap_c *this)

{
  STControl::checkTrigger(*(STControl **)&this->field_0x50cc);
  Runtime.PPCEABI.H::__ptmf_scall
            ((PTMF *)(&d_menu_fmap::warpProcMain + (uint)*(byte *)&this->field_0x516c * 3),this,
             &DAT_80390000);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_Fmap_c::wrapMove(void) */

void __thiscall dMenu_Fmap_c::wrapMove(dMenu_Fmap_c *this)

{
  double dVar1;
  double dVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  ulong uVar5;
  cursorTable_t *pcVar6;
  int iVar7;
  int iVar8;
  char cVar9;
  char cVar10;
  undefined uVar11;
  int iVar12;
  undefined local_78;
  undefined uStack119;
  undefined uStack118;
  undefined uStack117;
  undefined local_74;
  undefined uStack115;
  undefined uStack114;
  undefined uStack113;
  undefined local_70;
  undefined uStack111;
  undefined uStack110;
  undefined uStack109;
  undefined local_6c;
  undefined uStack107;
  undefined uStack106;
  undefined uStack105;
  undefined auStack72 [24];
  undefined4 local_30;
  uint uStack44;
  undefined4 local_28;
  uint uStack36;
  undefined4 local_20;
  uint uStack28;
  
  if (this->mFmapSv == (undefined *)0x0) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_menu_fmap.h",0x20a,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x20a,&DAT_8035fc8d);
  }
  cVar10 = this->mFmapSv[7];
  if (this->mFmapSv == (undefined *)0x0) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_menu_fmap.h",0x1ff,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x1ff,&DAT_8035fc8d);
  }
  pcVar6 = (cursorTable_t *)getWarpAreaTablePtr(this,this->mFmapSv[6],cVar10);
  iVar7 = getWarpAreaNo(this,pcVar6);
  cVar10 = -1;
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
    if (((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') ||
       ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 5 & 1) != 0)) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8cc,(cXyz *)0x0,0,0,d_menu_fmap::_4271,d_menu_fmap::_4271,
                 d_menu_fmap::_4272,d_menu_fmap::_4272,0);
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpShip != (daShip_c *)0x0) {
        *(undefined4 *)&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpShip)->field_0x3c8 = 0xffffffff;
      }
      *(undefined *)&this->field_0x510c = 1;
      iVar7 = *(int *)&this->field_0x50d8;
      if (iVar7 != 0) {
        *(undefined4 *)(iVar7 + 0x60) = 0xffffffff;
        *(uint *)(iVar7 + 0x20c) = *(uint *)(iVar7 + 0x20c) | 1;
      }
      iVar7 = 0;
      iVar8 = 9;
      do {
        iVar12 = *(int *)(&this->field_0x50dc + iVar7);
        *(uint *)(iVar12 + 0x20c) = *(uint *)(iVar12 + 0x20c) | 4;
        iVar12 = *(int *)(&this->field_0x50dc + iVar7);
        if (iVar12 != 0) {
          *(undefined4 *)(iVar12 + 0x60) = 0xffffffff;
          *(uint *)(iVar12 + 0x20c) = *(uint *)(iVar12 + 0x20c) | 1;
        }
        iVar7 = iVar7 + 4;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    else {
      cVar9 = STControl::checkRightTrigger(*(STControl **)&this->field_0x50cc);
      if (cVar9 == '\0') {
        cVar9 = STControl::checkLeftTrigger(*(STControl **)&this->field_0x50cc);
        if (cVar9 == '\0') {
          cVar9 = STControl::checkUpTrigger(*(STControl **)&this->field_0x50cc);
          if (cVar9 == '\0') {
            cVar9 = STControl::checkDownTrigger(*(STControl **)&this->field_0x50cc);
            if (cVar9 != '\0') {
              cVar10 = getWarpAreaNoDown(this,pcVar6);
            }
          }
          else {
            cVar10 = getWarpAreaNoUp(this,pcVar6);
          }
        }
        else {
          cVar10 = getWarpAreaNoLeft(this,pcVar6);
        }
      }
      else {
        cVar10 = getWarpAreaNoRight(this,pcVar6);
      }
      if (-1 < cVar10) {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x8c3,(cXyz *)0x0,0,0,d_menu_fmap::_4271,
                   d_menu_fmap::_4271,d_menu_fmap::_4272,d_menu_fmap::_4272,0);
        uVar11 = getWarpAreaGridX(this,(int)cVar10);
        if (this->mFmapSv == (undefined *)0x0) {
          uVar5 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar5,"d_menu_fmap.h",0x204,"fmapSv != 0");
          m_Do_printf::OSPanic("d_menu_fmap.h",0x204,&DAT_8035fc8d);
        }
        this->mFmapSv[6] = uVar11;
        uVar11 = getWarpAreaGridY(this,(int)cVar10);
        if (this->mFmapSv == (undefined *)0x0) {
          uVar5 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar5,"d_menu_fmap.h",0x20f,"fmapSv != 0");
          m_Do_printf::OSPanic("d_menu_fmap.h",0x20f,&DAT_8035fc8d);
        }
        this->mFmapSv[7] = uVar11;
        areaTextChangeAnimeInit(this);
        selCursorMoveWarp(this);
        warpAreaAnime0(this);
      }
    }
  }
  else {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8cd,(cXyz *)0x0,0,0,d_menu_fmap::_4271,d_menu_fmap::_4271,
               d_menu_fmap::_4272,d_menu_fmap::_4272,0);
    if (this->mFmapSv == (undefined *)0x0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_menu_fmap.h",0x20a,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap.h",0x20a,&DAT_8035fc8d);
    }
    cVar10 = this->mFmapSv[7];
    if (this->mFmapSv == (undefined *)0x0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_menu_fmap.h",0x1ff,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap.h",0x1ff,&DAT_8035fc8d);
    }
    iVar8 = dSv_player_map_c::isSaveArriveGrid
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,
                       (int)(char)this->mFmapSv[6] + (cVar10 + 3) * 7 + 3);
    if (iVar8 == 0) {
      iVar7 = 0x44;
    }
    else {
      if (iVar7 == 7) {
        iVar7 = 0x43;
      }
      else {
        if (iVar7 == 8) {
          iVar7 = 0x42;
        }
        else {
          iVar7 = iVar7 + 0x45;
        }
      }
    }
    f_op_msg_mng::fopMsgM_selectMessageGet
              (auStack72,*(undefined4 *)&this->field_0x4d14,*(undefined4 *)&this->field_0x4cdc,
               *(undefined4 *)&this->field_0x5154,*(undefined4 *)&this->field_0x5158,
               *(undefined4 *)&this->field_0x515c,*(undefined4 *)&this->field_0x5160,iVar7);
    *(undefined *)(*(int *)&this->field_0x4f0c + 0xaa) = 1;
    *(undefined *)&this->field_0x516d = 0;
    iVar7 = *(int *)&this->field_0x4e2c;
    *(undefined *)(iVar7 + 0x108) = 0x33;
    *(undefined *)(iVar7 + 0x109) = 0x15;
    *(undefined *)(iVar7 + 0x10a) = 0;
    *(undefined *)(iVar7 + 0x10b) = 0;
    *(undefined *)(iVar7 + 0x104) = 0x76;
    *(undefined *)(iVar7 + 0x105) = 0x54;
    *(undefined *)(iVar7 + 0x106) = 0x2f;
    *(undefined *)(iVar7 + 0x107) = 0xff;
    iVar7 = *(int *)&this->field_0x4e64;
    *(undefined *)(iVar7 + 0x108) = 0x33;
    *(undefined *)(iVar7 + 0x109) = 0x15;
    *(undefined *)(iVar7 + 0x10a) = 0;
    *(undefined *)(iVar7 + 0x10b) = 0;
    *(undefined *)(iVar7 + 0x104) = 0x76;
    *(undefined *)(iVar7 + 0x105) = 0x54;
    *(undefined *)(iVar7 + 0x106) = 0x2f;
    *(undefined *)(iVar7 + 0x107) = 0xff;
    uVar3 = *(undefined4 *)&this[1].field_0x28;
    uVar4 = *(undefined4 *)&this[1].field_0x24;
    iVar7 = *(int *)&this->field_0x4d4c;
    local_6c = (undefined)((uint)uVar4 >> 0x18);
    *(undefined *)(iVar7 + 0x108) = local_6c;
    uStack107 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar7 + 0x109) = uStack107;
    uStack106 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar7 + 0x10a) = uStack106;
    uStack105 = (undefined)uVar4;
    *(undefined *)(iVar7 + 0x10b) = uStack105;
    local_70 = (undefined)((uint)uVar3 >> 0x18);
    *(undefined *)(iVar7 + 0x104) = local_70;
    uStack111 = (undefined)((uint)uVar3 >> 0x10);
    *(undefined *)(iVar7 + 0x105) = uStack111;
    uStack110 = (undefined)((uint)uVar3 >> 8);
    *(undefined *)(iVar7 + 0x106) = uStack110;
    uStack109 = (undefined)uVar3;
    *(undefined *)(iVar7 + 0x107) = uStack109;
    uVar3 = *(undefined4 *)&this[1].field_0x28;
    uVar4 = *(undefined4 *)&this[1].field_0x24;
    iVar7 = *(int *)&this->field_0x4d84;
    local_74 = (undefined)((uint)uVar4 >> 0x18);
    *(undefined *)(iVar7 + 0x108) = local_74;
    uStack115 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar7 + 0x109) = uStack115;
    uStack114 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar7 + 0x10a) = uStack114;
    uStack113 = (undefined)uVar4;
    *(undefined *)(iVar7 + 0x10b) = uStack113;
    local_78 = (undefined)((uint)uVar3 >> 0x18);
    *(undefined *)(iVar7 + 0x104) = local_78;
    uStack119 = (undefined)((uint)uVar3 >> 0x10);
    *(undefined *)(iVar7 + 0x105) = uStack119;
    uStack118 = (undefined)((uint)uVar3 >> 8);
    *(undefined *)(iVar7 + 0x106) = uStack118;
    uStack117 = (undefined)uVar3;
    *(undefined *)(iVar7 + 0x107) = uStack117;
    warpSelCursorMove(this);
    warpSelCursorAnimeInit(this);
    *(undefined *)(*(int *)&this->field_0x4c6c + 0xaa) = 1;
    *(undefined *)(*(int *)&this->field_0x4ca4 + 0xaa) = 1;
    *(undefined *)(*(int *)&this->field_0x4dbc + 0xaa) = 1;
    *(undefined *)(*(int *)&this->field_0x4e9c + 0xaa) = 1;
    *(undefined *)(*(int *)&this->field_0x4f0c + 0xaa) = 0;
    *(undefined2 *)&this->field_0x5116 = 0;
    paneAlphaWarpMsgBack(this,*(short *)&this->field_0x5116,DAT_803e60dd,'\0',0);
    uStack44 = (int)DAT_803e60e0 ^ 0x80000000;
    local_30 = 0x43300000;
    paneTranceWarpMsg(this,(fopMsgM_pane_class *)&this->field_0x4ca4,*(short *)&this->field_0x5116,
                      DAT_803e60dd,
                      (float)((double)CONCAT44(0x43300000,uStack44) - d_menu_fmap::_4609),
                      d_menu_fmap::_4256,'\0',0);
    uStack36 = (int)DAT_803e60e6 ^ 0x80000000;
    local_28 = 0x43300000;
    paneTranceWarpMsg(this,(fopMsgM_pane_class *)&this->field_0x4dbc,*(short *)&this->field_0x5116,
                      DAT_803e60dd,
                      (float)((double)CONCAT44(0x43300000,uStack36) - d_menu_fmap::_4609),
                      d_menu_fmap::_4256,'\0',0);
    uStack28 = (int)DAT_803e60e6 ^ 0x80000000;
    local_20 = 0x43300000;
    paneTranceWarpMsg(this,(fopMsgM_pane_class *)&this->field_0x4e9c,*(short *)&this->field_0x5116,
                      DAT_803e60dd,
                      (float)((double)CONCAT44(0x43300000,uStack28) - d_menu_fmap::_4609),
                      d_menu_fmap::_4256,'\0',0);
    areaTextChangeAnimeInit(this);
    iVar7 = 0;
    iVar8 = 9;
    do {
      iVar12 = *(int *)(&this->field_0x50dc + iVar7);
      *(uint *)(iVar12 + 0x20c) = *(uint *)(iVar12 + 0x20c) | 4;
      iVar7 = iVar7 + 4;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    *(undefined *)&this->field_0x516c = 1;
  }
  areaTextChangeAnime(this);
  uVar3 = *(undefined4 *)&this->field_0x4b94;
  iVar7 = *(int *)&this->field_0x2884;
  *(undefined4 *)(iVar7 + 0x30) = *(undefined4 *)&this->field_0x4b90;
  *(undefined4 *)(iVar7 + 0x34) = uVar3;
  dDlst_2DOutFont_c::move(*(dDlst_2DOutFont_c **)&this->field_0x2884);
  selCursorAnime(this);
  uStack28 = (uint)*(byte *)&this->field_0x5176;
  local_20 = 0x43300000;
  dVar1 = (double)CONCAT44(0x43300000,uStack28) - d_menu_fmap::_5228;
  uStack36 = (uint)DAT_803e61a3;
  local_28 = 0x43300000;
  dVar2 = (double)CONCAT44(0x43300000,uStack36) - d_menu_fmap::_5228;
  *(byte *)&this->field_0x5176 = *(byte *)&this->field_0x5176 + 1;
  *(byte *)&this->field_0x5176 =
       *(byte *)&this->field_0x5176 -
       (char)((uint)*(byte *)&this->field_0x5176 / ((uint)DAT_803e61a3 << 2)) *
       (char)((uint)DAT_803e61a3 << 2);
  setDspWarpBackCornerColor(this,(float)dVar1 / (float)dVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dMenu_Fmap_c::wrapSelWinFadeIn1(void) */

void __thiscall dMenu_Fmap_c::wrapSelWinFadeIn1(dMenu_Fmap_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_r29;
  
  iVar1 = paneAlphaWarpMsgBack
                    (this,*(short *)&this->field_0x5116 - (ushort)DAT_803e60db,DAT_803e60da,'\0',0);
  iVar2 = paneTranceWarpMsg(this,(fopMsgM_pane_class *)&this->field_0x4ca4,
                            *(short *)&this->field_0x5116 - (ushort)DAT_803e60de,DAT_803e60dd,
                            (float)((double)CONCAT44(0x43300000,(int)DAT_803e60e0 ^ 0x80000000) -
                                   d_menu_fmap::_4609),d_menu_fmap::_7364,'\0',0);
  if (iVar2 == 1) {
    unaff_r29 = paneTranceWarpMsg(this,(fopMsgM_pane_class *)&this->field_0x4ca4,
                                  *(short *)&this->field_0x5116 -
                                  ((ushort)DAT_803e60de + (ushort)DAT_803e60dd),DAT_803e60dd,
                                  d_menu_fmap::_7364,d_menu_fmap::_4256,'\0',2);
  }
  iVar3 = paneTranceWarpMsg(this,(fopMsgM_pane_class *)&this->field_0x4dbc,
                            *(short *)&this->field_0x5116,DAT_803e60e2,
                            (float)((double)CONCAT44(0x43300000,(int)DAT_803e60e6 ^ 0x80000000) -
                                   d_menu_fmap::_4609),d_menu_fmap::_4256,'\x01',0);
  iVar4 = paneTranceWarpMsg(this,(fopMsgM_pane_class *)&this->field_0x4e9c,
                            *(short *)&this->field_0x5116 - (ushort)DAT_803e60e5,DAT_803e60e2,
                            (float)((double)CONCAT44(0x43300000,(int)DAT_803e60e6 ^ 0x80000000) -
                                   d_menu_fmap::_4609),d_menu_fmap::_4256,'\x01',0);
  *(short *)&this->field_0x5116 = *(short *)&this->field_0x5116 + 1;
  if ((((iVar1 == 1) && (iVar2 == 1)) && (unaff_r29 == 1)) && ((iVar3 == 1 && (iVar4 == 1)))) {
    *(undefined2 *)&this->field_0x5116 = 0;
    *(undefined *)(*(int *)&this->field_0x4f0c + 0xaa) = 1;
    *(undefined *)&this->field_0x516c = 2;
  }
  return;
}


/* __thiscall dMenu_Fmap_c::wrapSelect(void) */

void __thiscall dMenu_Fmap_c::wrapSelect(dMenu_Fmap_c *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  undefined local_68;
  undefined uStack103;
  undefined uStack102;
  undefined uStack101;
  undefined local_64;
  undefined uStack99;
  undefined uStack98;
  undefined uStack97;
  undefined local_60;
  undefined uStack95;
  undefined uStack94;
  undefined uStack93;
  undefined local_5c;
  undefined uStack91;
  undefined uStack90;
  undefined uStack89;
  undefined local_38;
  undefined uStack55;
  undefined uStack54;
  undefined uStack53;
  undefined local_34;
  undefined uStack51;
  undefined uStack50;
  undefined uStack49;
  undefined local_30;
  undefined uStack47;
  undefined uStack46;
  undefined uStack45;
  undefined local_2c;
  undefined uStack43;
  undefined uStack42;
  undefined uStack41;
  
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
    if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8cf,(cXyz *)0x0,0,0,d_menu_fmap::_4271,d_menu_fmap::_4271,
                 d_menu_fmap::_4272,d_menu_fmap::_4272,0);
      *(undefined *)&this->field_0x516c = 3;
      *(undefined *)(*(int *)&this->field_0x4f0c + 0xaa) = 0;
    }
    else {
      cVar3 = STControl::checkRightTrigger(*(STControl **)&this->field_0x50cc);
      if (cVar3 == '\0') {
        cVar3 = STControl::checkLeftTrigger(*(STControl **)&this->field_0x50cc);
        if ((cVar3 != '\0') && (*(char *)&this->field_0x516d != '\0')) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x83d,(cXyz *)0x0,0,0,d_menu_fmap::_4271,
                     d_menu_fmap::_4271,d_menu_fmap::_4272,d_menu_fmap::_4272,0);
          *(undefined *)&this->field_0x516d = 0;
          warpSelCursorMove(this);
          iVar4 = *(int *)&this->field_0x4e2c;
          *(undefined *)(iVar4 + 0x108) = 0x33;
          *(undefined *)(iVar4 + 0x109) = 0x15;
          *(undefined *)(iVar4 + 0x10a) = 0;
          *(undefined *)(iVar4 + 0x10b) = 0;
          *(undefined *)(iVar4 + 0x104) = 0x76;
          *(undefined *)(iVar4 + 0x105) = 0x54;
          *(undefined *)(iVar4 + 0x106) = 0x2f;
          *(undefined *)(iVar4 + 0x107) = 0xff;
          iVar4 = *(int *)&this->field_0x4e64;
          *(undefined *)(iVar4 + 0x108) = 0x33;
          *(undefined *)(iVar4 + 0x109) = 0x15;
          *(undefined *)(iVar4 + 0x10a) = 0;
          *(undefined *)(iVar4 + 0x10b) = 0;
          *(undefined *)(iVar4 + 0x104) = 0x76;
          *(undefined *)(iVar4 + 0x105) = 0x54;
          *(undefined *)(iVar4 + 0x106) = 0x2f;
          *(undefined *)(iVar4 + 0x107) = 0xff;
          uVar1 = *(undefined4 *)&this[1].field_0x28;
          uVar2 = *(undefined4 *)&this[1].field_0x24;
          iVar4 = *(int *)&this->field_0x4d4c;
          local_5c = (undefined)((uint)uVar2 >> 0x18);
          *(undefined *)(iVar4 + 0x108) = local_5c;
          uStack91 = (undefined)((uint)uVar2 >> 0x10);
          *(undefined *)(iVar4 + 0x109) = uStack91;
          uStack90 = (undefined)((uint)uVar2 >> 8);
          *(undefined *)(iVar4 + 0x10a) = uStack90;
          uStack89 = (undefined)uVar2;
          *(undefined *)(iVar4 + 0x10b) = uStack89;
          local_60 = (undefined)((uint)uVar1 >> 0x18);
          *(undefined *)(iVar4 + 0x104) = local_60;
          uStack95 = (undefined)((uint)uVar1 >> 0x10);
          *(undefined *)(iVar4 + 0x105) = uStack95;
          uStack94 = (undefined)((uint)uVar1 >> 8);
          *(undefined *)(iVar4 + 0x106) = uStack94;
          uStack93 = (undefined)uVar1;
          *(undefined *)(iVar4 + 0x107) = uStack93;
          uVar1 = *(undefined4 *)&this[1].field_0x28;
          uVar2 = *(undefined4 *)&this[1].field_0x24;
          iVar4 = *(int *)&this->field_0x4d84;
          local_64 = (undefined)((uint)uVar2 >> 0x18);
          *(undefined *)(iVar4 + 0x108) = local_64;
          uStack99 = (undefined)((uint)uVar2 >> 0x10);
          *(undefined *)(iVar4 + 0x109) = uStack99;
          uStack98 = (undefined)((uint)uVar2 >> 8);
          *(undefined *)(iVar4 + 0x10a) = uStack98;
          uStack97 = (undefined)uVar2;
          *(undefined *)(iVar4 + 0x10b) = uStack97;
          local_68 = (undefined)((uint)uVar1 >> 0x18);
          *(undefined *)(iVar4 + 0x104) = local_68;
          uStack103 = (undefined)((uint)uVar1 >> 0x10);
          *(undefined *)(iVar4 + 0x105) = uStack103;
          uStack102 = (undefined)((uint)uVar1 >> 8);
          *(undefined *)(iVar4 + 0x106) = uStack102;
          uStack101 = (undefined)uVar1;
          *(undefined *)(iVar4 + 0x107) = uStack101;
        }
      }
      else {
        if (*(char *)&this->field_0x516d != '\x01') {
          *(undefined *)&this->field_0x516d = 1;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x83d,(cXyz *)0x0,0,0,d_menu_fmap::_4271,
                     d_menu_fmap::_4271,d_menu_fmap::_4272,d_menu_fmap::_4272,0);
          warpSelCursorMove(this);
          iVar4 = *(int *)&this->field_0x4d4c;
          *(undefined *)(iVar4 + 0x108) = 0x33;
          *(undefined *)(iVar4 + 0x109) = 0x15;
          *(undefined *)(iVar4 + 0x10a) = 0;
          *(undefined *)(iVar4 + 0x10b) = 0;
          *(undefined *)(iVar4 + 0x104) = 0x76;
          *(undefined *)(iVar4 + 0x105) = 0x54;
          *(undefined *)(iVar4 + 0x106) = 0x2f;
          *(undefined *)(iVar4 + 0x107) = 0xff;
          iVar4 = *(int *)&this->field_0x4d84;
          *(undefined *)(iVar4 + 0x108) = 0x33;
          *(undefined *)(iVar4 + 0x109) = 0x15;
          *(undefined *)(iVar4 + 0x10a) = 0;
          *(undefined *)(iVar4 + 0x10b) = 0;
          *(undefined *)(iVar4 + 0x104) = 0x76;
          *(undefined *)(iVar4 + 0x105) = 0x54;
          *(undefined *)(iVar4 + 0x106) = 0x2f;
          *(undefined *)(iVar4 + 0x107) = 0xff;
          uVar1 = *(undefined4 *)&this[1].field_0x28;
          uVar2 = *(undefined4 *)&this[1].field_0x24;
          iVar4 = *(int *)&this->field_0x4e2c;
          local_2c = (undefined)((uint)uVar2 >> 0x18);
          *(undefined *)(iVar4 + 0x108) = local_2c;
          uStack43 = (undefined)((uint)uVar2 >> 0x10);
          *(undefined *)(iVar4 + 0x109) = uStack43;
          uStack42 = (undefined)((uint)uVar2 >> 8);
          *(undefined *)(iVar4 + 0x10a) = uStack42;
          uStack41 = (undefined)uVar2;
          *(undefined *)(iVar4 + 0x10b) = uStack41;
          local_30 = (undefined)((uint)uVar1 >> 0x18);
          *(undefined *)(iVar4 + 0x104) = local_30;
          uStack47 = (undefined)((uint)uVar1 >> 0x10);
          *(undefined *)(iVar4 + 0x105) = uStack47;
          uStack46 = (undefined)((uint)uVar1 >> 8);
          *(undefined *)(iVar4 + 0x106) = uStack46;
          uStack45 = (undefined)uVar1;
          *(undefined *)(iVar4 + 0x107) = uStack45;
          uVar1 = *(undefined4 *)&this[1].field_0x28;
          uVar2 = *(undefined4 *)&this[1].field_0x24;
          iVar4 = *(int *)&this->field_0x4e64;
          local_34 = (undefined)((uint)uVar2 >> 0x18);
          *(undefined *)(iVar4 + 0x108) = local_34;
          uStack51 = (undefined)((uint)uVar2 >> 0x10);
          *(undefined *)(iVar4 + 0x109) = uStack51;
          uStack50 = (undefined)((uint)uVar2 >> 8);
          *(undefined *)(iVar4 + 0x10a) = uStack50;
          uStack49 = (undefined)uVar2;
          *(undefined *)(iVar4 + 0x10b) = uStack49;
          local_38 = (undefined)((uint)uVar1 >> 0x18);
          *(undefined *)(iVar4 + 0x104) = local_38;
          uStack55 = (undefined)((uint)uVar1 >> 0x10);
          *(undefined *)(iVar4 + 0x105) = uStack55;
          uStack54 = (undefined)((uint)uVar1 >> 8);
          *(undefined *)(iVar4 + 0x106) = uStack54;
          uStack53 = (undefined)uVar1;
          *(undefined *)(iVar4 + 0x107) = uStack53;
        }
      }
    }
  }
  else {
    if (*(char *)&this->field_0x516d == '\0') {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8ce,(cXyz *)0x0,0,0,d_menu_fmap::_4271,d_menu_fmap::_4271,
                 d_menu_fmap::_4272,d_menu_fmap::_4272,0);
      *(undefined *)&this->field_0x516c = 4;
    }
    else {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8cf,(cXyz *)0x0,0,0,d_menu_fmap::_4271,d_menu_fmap::_4271,
                 d_menu_fmap::_4272,d_menu_fmap::_4272,0);
      *(undefined *)&this->field_0x516c = 3;
    }
    *(undefined *)(*(int *)&this->field_0x4f0c + 0xaa) = 0;
  }
  warpSelCursorAnime(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dMenu_Fmap_c::wrapSelWinFadeOut(void) */

void __thiscall dMenu_Fmap_c::wrapSelWinFadeOut(dMenu_Fmap_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_r29;
  
  iVar1 = paneAlphaWarpMsgBack
                    (this,*(short *)&this->field_0x5116 - (ushort)DAT_803e60dc,DAT_803e60da,'\0',1);
  iVar2 = paneTranceWarpMsg(this,(fopMsgM_pane_class *)&this->field_0x4ca4,
                            *(short *)&this->field_0x5116 - (ushort)DAT_803e60de,DAT_803e60dd,
                            d_menu_fmap::_4256,d_menu_fmap::_7364,'\0',2);
  if (iVar2 == 1) {
    unaff_r29 = paneTranceWarpMsg(this,(fopMsgM_pane_class *)&this->field_0x4ca4,
                                  *(short *)&this->field_0x5116 -
                                  ((ushort)DAT_803e60de + (ushort)DAT_803e60dd),DAT_803e60dd,
                                  d_menu_fmap::_4256,
                                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e60e0 ^ 0x80000000
                                                          ) - d_menu_fmap::_4609),'\0',1);
  }
  iVar3 = paneTranceWarpMsg(this,(fopMsgM_pane_class *)&this->field_0x4dbc,
                            *(short *)&this->field_0x5116,DAT_803e60e2,d_menu_fmap::_4256,
                            (float)((double)CONCAT44(0x43300000,(int)DAT_803e60e6 ^ 0x80000000) -
                                   d_menu_fmap::_4609),'\0',1);
  iVar4 = paneTranceWarpMsg(this,(fopMsgM_pane_class *)&this->field_0x4e9c,
                            *(short *)&this->field_0x5116 - (ushort)DAT_803e60e5,DAT_803e60e2,
                            d_menu_fmap::_4256,
                            (float)((double)CONCAT44(0x43300000,(int)DAT_803e60e6 ^ 0x80000000) -
                                   d_menu_fmap::_4609),'\0',1);
  *(short *)&this->field_0x5116 = *(short *)&this->field_0x5116 + 1;
  if ((((iVar1 == 1) && (iVar2 == 1)) && (unaff_r29 == 1)) && ((iVar3 == 1 && (iVar4 == 1)))) {
    iVar1 = 0;
    *(undefined2 *)&this->field_0x5116 = 0;
    iVar2 = 9;
    do {
      iVar3 = *(int *)(&this->field_0x50dc + iVar1);
      *(uint *)(iVar3 + 0x20c) = *(uint *)(iVar3 + 0x20c) & 0xfffffffb;
      iVar1 = iVar1 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(undefined *)&this->field_0x516c = 0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Fmap_c::wrapSelWarp(void) */

void __thiscall dMenu_Fmap_c::wrapSelWarp(dMenu_Fmap_c *this)

{
  char cVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  cursorTable_t *pcVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar2 = paneTranceWarpMsg(this,(fopMsgM_pane_class *)&this->field_0x4dbc,
                            *(short *)&this->field_0x5116,DAT_803e60e2,d_menu_fmap::_4256,
                            (float)((double)CONCAT44(0x43300000,(int)DAT_803e60e6 ^ 0x80000000) -
                                   d_menu_fmap::_4609),'\0',1);
  iVar3 = paneTranceWarpMsg(this,(fopMsgM_pane_class *)&this->field_0x4e9c,
                            *(short *)&this->field_0x5116 - (ushort)DAT_803e60e5,DAT_803e60e2,
                            d_menu_fmap::_4256,
                            (float)((double)CONCAT44(0x43300000,(int)DAT_803e60e6 ^ 0x80000000) -
                                   d_menu_fmap::_4609),'\0',1);
  *(short *)&this->field_0x5116 = *(short *)&this->field_0x5116 + 1;
  if ((iVar2 == 1) && (iVar3 == 1)) {
    *(undefined2 *)&this->field_0x5116 = 0;
    if (this->mFmapSv == (undefined *)0x0) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar4,"d_menu_fmap.h",0x20a,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap.h",0x20a,&DAT_8035fc8d);
    }
    cVar1 = this->mFmapSv[7];
    if (this->mFmapSv == (undefined *)0x0) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar4,"d_menu_fmap.h",0x1ff,"fmapSv != 0");
      m_Do_printf::OSPanic("d_menu_fmap.h",0x1ff,&DAT_8035fc8d);
    }
    pcVar5 = (cursorTable_t *)getWarpAreaTablePtr(this,this->mFmapSv[6],cVar1);
    uVar6 = getWarpAreaNo(this,pcVar5);
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpShip != (daShip_c *)0x0) {
      *(undefined4 *)&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpShip)->field_0x3c8 = uVar6;
    }
    *(undefined *)&this->field_0x510c = 1;
    iVar2 = *(int *)&this->field_0x50d8;
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x60) = 0xffffffff;
      *(uint *)(iVar2 + 0x20c) = *(uint *)(iVar2 + 0x20c) | 1;
    }
    iVar2 = 0;
    iVar3 = 9;
    do {
      iVar7 = *(int *)(&this->field_0x50dc + iVar2);
      *(uint *)(iVar7 + 0x20c) = *(uint *)(iVar7 + 0x20c) | 4;
      iVar7 = *(int *)(&this->field_0x50dc + iVar2);
      if (iVar7 != 0) {
        *(undefined4 *)(iVar7 + 0x60) = 0xffffffff;
        *(uint *)(iVar7 + 0x20c) = *(uint *)(iVar7 + 0x20c) | 1;
      }
      iVar2 = iVar2 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}


/* __thiscall dMenu_Fmap_c::warpAreaAnime0(void) */

void __thiscall dMenu_Fmap_c::warpAreaAnime0(dMenu_Fmap_c *this)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  ulong uVar5;
  cursorTable_t *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  if (this->mFmapSv == (undefined *)0x0) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_menu_fmap.h",0x20a,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x20a,&DAT_8035fc8d);
  }
  cVar1 = this->mFmapSv[7];
  if (this->mFmapSv == (undefined *)0x0) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_menu_fmap.h",0x1ff,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x1ff,&DAT_8035fc8d);
  }
  pcVar6 = (cursorTable_t *)getWarpAreaTablePtr(this,this->mFmapSv[6],cVar1);
  iVar7 = getWarpAreaNo(this,pcVar6);
  fVar4 = d_menu_fmap::_4256;
  iVar10 = 0;
  iVar8 = 0;
  iVar11 = 9;
  do {
    uVar2 = *(undefined4 *)((int)&DAT_803e6110 + iVar8);
    iVar9 = *(int *)(&this->field_0x50dc + iVar8);
    *(undefined4 *)(iVar9 + 0x1e4) = *(undefined4 *)((int)&DAT_803e60ec + iVar8);
    *(undefined4 *)(iVar9 + 0x1e8) = uVar2;
    *(float *)(iVar9 + 0x1ec) = fVar4;
    uVar3 = DAT_803e6138;
    uVar2 = DAT_803e6134;
    if (iVar10 == iVar7) {
      iVar9 = *(int *)(&this->field_0x50dc + iVar8);
      *(undefined4 *)(iVar9 + 0x1f0) = DAT_803e6134;
      *(undefined4 *)(iVar9 + 500) = uVar2;
      *(float *)(iVar9 + 0x1f8) = fVar4;
    }
    else {
      iVar9 = *(int *)(&this->field_0x50dc + iVar8);
      *(undefined4 *)(iVar9 + 0x1f0) = DAT_803e6138;
      *(undefined4 *)(iVar9 + 500) = uVar3;
      *(float *)(iVar9 + 0x1f8) = fVar4;
    }
    iVar10 = iVar10 + 1;
    iVar8 = iVar8 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801b94cc) */
/* WARNING: Removing unreachable block (ram,0x801b94c4) */
/* WARNING: Removing unreachable block (ram,0x801b94d4) */
/* __thiscall dMenu_Fmap_c::paneTranceWarpMsg(fopMsgM_pane_class *,
                                              short,
                                              unsigned char,
                                              float,
                                              float,
                                              unsigned char,
                                              int) */

undefined4 __thiscall
dMenu_Fmap_c::paneTranceWarpMsg
          (dMenu_Fmap_c *this,fopMsgM_pane_class *param_1,short param_2,uchar param_3,float param_4,
          float param_5,uchar param_6,int param_7)

{
  undefined4 uVar1;
  undefined3 in_register_0000001c;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar5 = (double)param_5;
  dVar3 = (double)param_4;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if (param_2 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_3 < (int)param_2) {
      uVar1 = 1;
    }
    else {
      dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_3,(int)param_2,CONCAT31(in_register_0000001c,param_6));
      f_op_msg_mng::fopMsgM_paneTrans
                (param_1,(double)d_menu_fmap::_4256,
                 (double)(float)(dVar3 + (double)(float)(dVar4 * (double)(float)(dVar5 - dVar3))));
      if (param_7 != 2) {
        if (param_7 == 1) {
          dVar4 = (double)(float)((double)d_menu_fmap::_4271 - dVar4);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha(param_1,(float)dVar4);
        f_op_msg_mng::fopMsgM_setAlpha(param_1);
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  return uVar1;
}


/* __thiscall dMenu_Fmap_c::paneAlphaWarpMsgBack(short,
                                                 unsigned char,
                                                 unsigned char,
                                                 int) */

undefined4 __thiscall
dMenu_Fmap_c::paneAlphaWarpMsgBack
          (dMenu_Fmap_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

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
          dVar2 = (double)(float)((double)d_menu_fmap::_4271 - dVar2);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x4c6c,(float)dVar2);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)&this->field_0x4c6c);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


/* __thiscall dMenu_Fmap_c::warpSelCursorMove(void) */

void __thiscall dMenu_Fmap_c::warpSelCursorMove(dMenu_Fmap_c *this)

{
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)&this->field_0x4f0c,
             (double)(d_menu_fmap::_7692 *
                     (float)((double)CONCAT44(0x43300000,(uint)*(byte *)&this->field_0x516d) -
                            d_menu_fmap::_5228)),(double)d_menu_fmap::_4256);
  return;
}


/* __thiscall dMenu_Fmap_c::warpSelCursorAnimeInit(void) */

void __thiscall dMenu_Fmap_c::warpSelCursorAnimeInit(dMenu_Fmap_c *this)

{
  *(undefined *)&this->field_0x4f41 = 0;
  *(undefined2 *)&this->field_0x4f42 = 0;
  *(undefined *)&this->field_0x5144 = 0;
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)&this->field_0x4f0c);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Fmap_c::warpSelCursorAnime(void) */

void __thiscall dMenu_Fmap_c::warpSelCursorAnime(dMenu_Fmap_c *this)

{
  byte bVar1;
  char cVar2;
  double dVar3;
  
  dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                            (DAT_803e60e8,(int)*(short *)&this->field_0x4f42,0);
  bVar1 = DAT_803e60e9;
  if (*(char *)&this->field_0x5144 != '\0') {
    dVar3 = (double)(float)((double)d_menu_fmap::_4271 - dVar3);
  }
  cVar2 = Runtime.PPCEABI.H::__cvt_fp2unsigned
                    ((double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                                      (uint)DAT_803e60ea -
                                                                      (uint)DAT_803e60e9 ^
                                                                      0x80000000) -
                                                    d_menu_fmap::_4609) * dVar3));
  *(byte *)&this->field_0x4f41 = bVar1 + cVar2;
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)&this->field_0x4f0c);
  if (*(short *)&this->field_0x4f42 == 0) {
    *(ushort *)&this->field_0x4f42 = (ushort)DAT_803e60e8;
    *(byte *)&this->field_0x5144 = *(byte *)&this->field_0x5144 ^ 1;
  }
  else {
    *(short *)&this->field_0x4f42 = *(short *)&this->field_0x4f42 + -1;
  }
  return;
}


/* __thiscall dMenu_Fmap_c::getWarpAreaGridX(int) */

int __thiscall dMenu_Fmap_c::getWarpAreaGridX(dMenu_Fmap_c *this,int param_1)

{
  return (int)(char)(&d_menu_fmap::g_cursorTable)[param_1 * 7];
}


/* __thiscall dMenu_Fmap_c::getWarpAreaGridY(int) */

int __thiscall dMenu_Fmap_c::getWarpAreaGridY(dMenu_Fmap_c *this,int param_1)

{
  return (int)(char)(&DAT_8035f9b9)[param_1 * 7];
}


/* __thiscall dMenu_Fmap_c::getWarpAreaNo(cursorTable_t const *) */

int __thiscall dMenu_Fmap_c::getWarpAreaNo(dMenu_Fmap_c *this,cursorTable_t *param_1)

{
  if (param_1 == (cursorTable_t *)0x0) {
    return -1;
  }
  return (int)(char)param_1[2];
}


/* __thiscall dMenu_Fmap_c::getWarpAreaNoUp(cursorTable_t const *) */

int __thiscall dMenu_Fmap_c::getWarpAreaNoUp(dMenu_Fmap_c *this,cursorTable_t *param_1)

{
  if (param_1 == (cursorTable_t *)0x0) {
    return -1;
  }
  return (int)(char)param_1[5];
}


/* __thiscall dMenu_Fmap_c::getWarpAreaNoDown(cursorTable_t const *) */

int __thiscall dMenu_Fmap_c::getWarpAreaNoDown(dMenu_Fmap_c *this,cursorTable_t *param_1)

{
  if (param_1 == (cursorTable_t *)0x0) {
    return -1;
  }
  return (int)(char)param_1[6];
}


/* __thiscall dMenu_Fmap_c::getWarpAreaNoLeft(cursorTable_t const *) */

int __thiscall dMenu_Fmap_c::getWarpAreaNoLeft(dMenu_Fmap_c *this,cursorTable_t *param_1)

{
  if (param_1 == (cursorTable_t *)0x0) {
    return -1;
  }
  return (int)(char)param_1[3];
}


/* __thiscall dMenu_Fmap_c::getWarpAreaNoRight(cursorTable_t const *) */

int __thiscall dMenu_Fmap_c::getWarpAreaNoRight(dMenu_Fmap_c *this,cursorTable_t *param_1)

{
  if (param_1 == (cursorTable_t *)0x0) {
    return -1;
  }
  return (int)(char)param_1[4];
}


/* __thiscall dMenu_Fmap_c::getWarpAreaTablePtr(signed char,
                                                signed char) */

char * __thiscall dMenu_Fmap_c::getWarpAreaTablePtr(dMenu_Fmap_c *this,char param_1,char param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 9;
  while ((param_1 != (&d_menu_fmap::g_cursorTable)[iVar1] || (param_2 != (&DAT_8035f9b9)[iVar1]))) {
    iVar1 = iVar1 + 7;
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) {
      return (char *)0x0;
    }
  }
  return &d_menu_fmap::g_cursorTable + iVar1;
}


/* __thiscall dMenu_Fmap_c::areaTextChangeAnimeInit(void) */

void __thiscall dMenu_Fmap_c::areaTextChangeAnimeInit(dMenu_Fmap_c *this)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  ulong uVar4;
  int iVar5;
  int iVar6;
  undefined uStack38;
  undefined uStack37;
  undefined uStack34;
  undefined uStack33;
  undefined local_20;
  undefined uStack31;
  undefined local_1c;
  undefined uStack27;
  
  *(undefined *)&this->field_0x5143 = DAT_803e60cd;
  *(undefined *)&this->field_0x5140 = 0;
  **(undefined **)&this->field_0x5148 = 0;
  if (this->mFmapSv == (undefined *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_menu_fmap.h",0x20a,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x20a,&DAT_8035fc8d);
  }
  cVar1 = this->mFmapSv[7];
  if (this->mFmapSv == (undefined *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_menu_fmap.h",0x1ff,"fmapSv != 0");
    m_Do_printf::OSPanic("d_menu_fmap.h",0x1ff,&DAT_8035fc8d);
  }
  iVar6 = (int)(char)this->mFmapSv[6] + (cVar1 + 3) * 7 + 3;
  iVar5 = dSv_player_map_c::isSaveArriveGrid
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,iVar6);
  uVar3 = DAT_803e619c;
  uVar2 = DAT_803e6198;
  if (iVar5 == 0) {
    **(undefined **)&this->field_0x514c = 0;
  }
  else {
    if ((((((iVar6 == 0) || (iVar6 == 3)) || (iVar6 == 10)) || ((iVar6 == 0xc || (iVar6 == 0x13))))
        || ((iVar6 == 0x16 || ((iVar6 == 0x19 || (iVar6 - 0x27U < 2)))))) ||
       ((iVar6 == 0x2b || (iVar6 == 0x2c)))) {
      uStack34 = (undefined)((uint)DAT_803e619c >> 8);
      uStack33 = (undefined)DAT_803e619c;
      iVar5 = *(int *)&this->field_0x4b54;
      local_1c = (undefined)((uint)DAT_803e619c >> 0x18);
      *(undefined *)(iVar5 + 0xd0) = local_1c;
      uStack27 = (undefined)((uint)uVar3 >> 0x10);
      *(undefined *)(iVar5 + 0xd1) = uStack27;
      *(undefined *)(iVar5 + 0xd2) = uStack34;
      *(undefined *)(iVar5 + 0xd3) = uStack33;
    }
    else {
      uStack38 = (undefined)((uint)DAT_803e6198 >> 8);
      uStack37 = (undefined)DAT_803e6198;
      iVar5 = *(int *)&this->field_0x4b54;
      local_20 = (undefined)((uint)DAT_803e6198 >> 0x18);
      *(undefined *)(iVar5 + 0xd0) = local_20;
      uStack31 = (undefined)((uint)uVar2 >> 0x10);
      *(undefined *)(iVar5 + 0xd1) = uStack31;
      *(undefined *)(iVar5 + 0xd2) = uStack38;
      *(undefined *)(iVar5 + 0xd3) = uStack37;
    }
    f_op_msg_mng::fopMsgM_messageGet(*(undefined4 *)&this->field_0x514c,iVar6 + 0x31a6);
  }
  dDlst_2DOutFont_c::messageSet(*(dDlst_2DOutFont_c **)&this->field_0x2884,0x5f);
  f_op_msg_mng::fopMsgM_setNowAlpha
            ((fopMsgM_pane_class *)(&this->field_0x4b54 + (uint)*(byte *)&this->field_0x5140 * 0x38)
             ,d_menu_fmap::_4271);
  f_op_msg_mng::fopMsgM_setAlpha
            ((fopMsgM_pane_class *)(&this->field_0x4b54 + (uint)*(byte *)&this->field_0x5140 * 0x38)
            );
  f_op_msg_mng::fopMsgM_setNowAlpha
            ((fopMsgM_pane_class *)(&this->field_0x4b54 + (*(byte *)&this->field_0x5140 ^ 1) * 0x38)
             ,d_menu_fmap::_4256);
  f_op_msg_mng::fopMsgM_setAlpha
            ((fopMsgM_pane_class *)(&this->field_0x4b54 + (*(byte *)&this->field_0x5140 ^ 1) * 0x38)
            );
  dDlst_2DOutFont_c::setAlpha(*(dDlst_2DOutFont_c **)&this->field_0x2884,'\0');
  return;
}


/* __thiscall dMenu_Fmap_c::areaTextChangeAnime(void) */

void __thiscall dMenu_Fmap_c::areaTextChangeAnime(dMenu_Fmap_c *this)

{
  int iVar1;
  
  if (*(char *)&this->field_0x5143 == '\0') {
    iVar1 = PaneAlphaAreaTxt(this,(ushort)*(byte *)&this->field_0x5141,DAT_803e60ce,1);
    *(char *)&this->field_0x5141 = *(char *)&this->field_0x5141 + '\x01';
    if (iVar1 == 1) {
      *(byte *)&this->field_0x5140 = *(byte *)&this->field_0x5140 ^ 1;
      *(undefined *)&this->field_0x5141 = 0;
      *(undefined *)&this->field_0x5143 = DAT_803e60cd;
    }
  }
  else {
    *(char *)&this->field_0x5143 = *(char *)&this->field_0x5143 + -1;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x801b9c68) */
/* WARNING: Removing unreachable block (ram,0x801b9c70) */
/* __thiscall dMenu_Fmap_c::PaneAlphaAreaTxt(short,
                                             unsigned char,
                                             int) */

undefined4 __thiscall
dMenu_Fmap_c::PaneAlphaAreaTxt(dMenu_Fmap_c *this,short param_1,uchar param_2,int param_3)

{
  undefined4 uVar1;
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
      dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease((uint)param_2,(int)param_1,0);
      dVar4 = (double)(float)((double)d_menu_fmap::_4271 - dVar3);
      f_op_msg_mng::fopMsgM_setNowAlpha
                ((fopMsgM_pane_class *)
                 (&this->field_0x4b1c + ((uint)*(byte *)&this->field_0x5140 + param_3) * 0x38),
                 (float)((double)d_menu_fmap::_4271 - dVar3));
      if ((uint)*(byte *)&this->field_0x5140 + param_3 == 2) {
        dDlst_2DOutFont_c::setAlpha
                  (*(dDlst_2DOutFont_c **)&this->field_0x2884,
                   (uchar)(int)((double)d_menu_fmap::_7868 * dVar4));
      }
      f_op_msg_mng::fopMsgM_setNowAlpha
                ((fopMsgM_pane_class *)
                 (&this->field_0x4b1c + ((*(byte *)&this->field_0x5140 ^ 1) + param_3) * 0x38),
                 (float)dVar3);
      if ((*(byte *)&this->field_0x5140 ^ 1) + param_3 == 2) {
        dDlst_2DOutFont_c::setAlpha
                  (*(dDlst_2DOutFont_c **)&this->field_0x2884,
                   (uchar)(int)((double)d_menu_fmap::_7868 * dVar3));
      }
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(&this->field_0x4b1c + param_3 * 0x38));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(&this->field_0x4b54 + param_3 * 0x38));
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  return uVar1;
}


/* __thiscall dMenu_Fmap_c::setDspWarpBackCornerColor(float) */

void __thiscall dMenu_Fmap_c::setDspWarpBackCornerColor(dMenu_Fmap_c *this,float param_1)

{
  uint uVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  double dVar14;
  undefined uStack166;
  undefined uStack165;
  undefined uStack162;
  undefined uStack161;
  undefined uStack158;
  undefined uStack157;
  undefined uStack154;
  undefined uStack153;
  undefined local_94;
  undefined uStack147;
  undefined local_8c;
  undefined uStack139;
  undefined local_84;
  undefined uStack131;
  undefined local_7c;
  undefined uStack123;
  byte local_78 [6];
  undefined local_72;
  undefined local_71;
  undefined local_70;
  undefined local_6f;
  undefined local_6e;
  undefined local_6d;
  undefined4 local_6c;
  double local_58;
  undefined4 local_50;
  uint uStack76;
  longlong local_48;
  undefined4 local_40;
  uint uStack60;
  undefined4 local_38;
  uint uStack52;
  longlong local_30;
  undefined4 local_28;
  uint uStack36;
  undefined4 local_20;
  uint uStack28;
  longlong local_18;
  
  local_78[0] = DAT_803e61a4;
  local_78[1] = DAT_803e61a5;
  local_78[2] = DAT_803e61a6;
  local_78[3] = DAT_803e61a8;
  local_78[4] = DAT_803e61a9;
  local_78[5] = DAT_803e61aa;
  local_72 = DAT_803e61a8;
  local_71 = DAT_803e61a9;
  local_70 = DAT_803e61aa;
  local_6f = DAT_803e61a8;
  local_6e = DAT_803e61a9;
  local_6d = DAT_803e61aa;
  dVar14 = MSL_C.PPCEABI.bare.H::fmod((double)param_1,d_menu_fmap::_7962);
  uVar1 = (uint)dVar14;
  local_58 = (double)(longlong)(int)uVar1;
  uStack76 = uVar1 ^ 0x80000000;
  local_50 = 0x43300000;
  fVar4 = (float)dVar14 -
          (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - d_menu_fmap::_4609);
  iVar12 = 0;
  iVar9 = 0;
  iVar10 = 0;
  iVar13 = 4;
  do {
    iVar11 = iVar12 + 1;
    if (3 < iVar11) {
      iVar11 = 0;
    }
    uStack76 = (uint)local_78[iVar10];
    local_50 = 0x43300000;
    fVar3 = (float)((double)CONCAT44(0x43300000,(uint)local_78[iVar10]) - d_menu_fmap::_5228);
    iVar11 = iVar11 * 3;
    local_58 = (double)CONCAT44(0x43300000,(uint)local_78[iVar11]);
    iVar2 = (int)(fVar3 + fVar4 * ((float)(local_58 - d_menu_fmap::_5228) - fVar3));
    local_48 = (longlong)iVar2;
    *(char *)((int)&local_6c + iVar9) = (char)iVar2;
    uStack60 = (uint)local_78[iVar10 + 1];
    local_40 = 0x43300000;
    fVar3 = (float)((double)CONCAT44(0x43300000,(uint)local_78[iVar10 + 1]) - d_menu_fmap::_5228);
    uStack52 = (uint)local_78[iVar11 + 1];
    local_38 = 0x43300000;
    iVar2 = (int)(fVar3 + fVar4 * ((float)((double)CONCAT44(0x43300000,(uint)local_78[iVar11 + 1]) -
                                          d_menu_fmap::_5228) - fVar3));
    local_30 = (longlong)iVar2;
    *(char *)((int)&local_6c + iVar9 + 1) = (char)iVar2;
    uStack36 = (uint)local_78[iVar10 + 2];
    local_28 = 0x43300000;
    fVar3 = (float)((double)CONCAT44(0x43300000,(uint)local_78[iVar10 + 2]) - d_menu_fmap::_5228);
    uStack28 = (uint)local_78[iVar11 + 2];
    local_20 = 0x43300000;
    iVar11 = (int)(fVar3 + fVar4 * ((float)((double)CONCAT44(0x43300000,(uint)local_78[iVar11 + 2])
                                           - d_menu_fmap::_5228) - fVar3));
    local_18 = (longlong)iVar11;
    *(char *)((int)&local_6c + iVar9 + 2) = (char)iVar11;
    *(undefined *)((int)&local_6c + iVar9 + 3) = 0xff;
    iVar12 = iVar12 + 1;
    iVar9 = iVar9 + 4;
    iVar10 = iVar10 + 3;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  iVar9 = (int)(uVar1 + 2) >> 0x1f;
  uVar5 = (&local_6c)[(iVar9 * 4 | (uVar1 + 2) * 0x40000000 + iVar9 >> 0x1e) - iVar9];
  uStack154 = (undefined)((uint)uVar5 >> 8);
  uStack153 = (undefined)uVar5;
  iVar9 = (int)(uVar1 + 3) >> 0x1f;
  uVar6 = (&local_6c)[(iVar9 * 4 | (uVar1 + 3) * 0x40000000 + iVar9 >> 0x1e) - iVar9];
  uStack158 = (undefined)((uint)uVar6 >> 8);
  uStack157 = (undefined)uVar6;
  iVar9 = (int)(uVar1 + 1) >> 0x1f;
  uVar7 = (&local_6c)[(iVar9 * 4 | (uVar1 + 1) * 0x40000000 + iVar9 >> 0x1e) - iVar9];
  uStack162 = (undefined)((uint)uVar7 >> 8);
  uStack161 = (undefined)uVar7;
  iVar9 = (int)uVar1 >> 0x1f;
  uVar8 = (&local_6c)[(iVar9 * 4 | uVar1 * 0x40000000 + iVar9 >> 0x1e) - iVar9];
  uStack166 = (undefined)((uint)uVar8 >> 8);
  uStack165 = (undefined)uVar8;
  iVar9 = *(int *)&this->field_0x28c4;
  local_7c = (undefined)((uint)uVar8 >> 0x18);
  *(undefined *)(iVar9 + 0x10c) = local_7c;
  uStack123 = (undefined)((uint)uVar8 >> 0x10);
  *(undefined *)(iVar9 + 0x10d) = uStack123;
  *(undefined *)(iVar9 + 0x10e) = uStack166;
  *(undefined *)(iVar9 + 0x10f) = uStack165;
  local_84 = (undefined)((uint)uVar7 >> 0x18);
  *(undefined *)(iVar9 + 0x110) = local_84;
  uStack131 = (undefined)((uint)uVar7 >> 0x10);
  *(undefined *)(iVar9 + 0x111) = uStack131;
  *(undefined *)(iVar9 + 0x112) = uStack162;
  *(undefined *)(iVar9 + 0x113) = uStack161;
  local_8c = (undefined)((uint)uVar6 >> 0x18);
  *(undefined *)(iVar9 + 0x114) = local_8c;
  uStack139 = (undefined)((uint)uVar6 >> 0x10);
  *(undefined *)(iVar9 + 0x115) = uStack139;
  *(undefined *)(iVar9 + 0x116) = uStack158;
  *(undefined *)(iVar9 + 0x117) = uStack157;
  local_94 = (undefined)((uint)uVar5 >> 0x18);
  *(undefined *)(iVar9 + 0x118) = local_94;
  uStack147 = (undefined)((uint)uVar5 >> 0x10);
  *(undefined *)(iVar9 + 0x119) = uStack147;
  *(undefined *)(iVar9 + 0x11a) = uStack154;
  *(undefined *)(iVar9 + 0x11b) = uStack153;
  return;
}


/* __thiscall dMenu_Fmap_c::setWrapBackEmitter(cXyz) */

void __thiscall dMenu_Fmap_c::setWrapBackEmitter(dMenu_Fmap_c *this,cXyz *param_1)

{
  JPABaseEmitter *pJVar1;
  
  pJVar1 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,9,0x358,param_1
                              ,(csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1,
                              (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
  *(JPABaseEmitter **)&this->field_0x50d8 = pJVar1;
  return;
}


/* __thiscall dMenu_Fmap_c::setWrapSpotEmitter(int,
                                               cXyz) */

void __thiscall dMenu_Fmap_c::setWrapSpotEmitter(dMenu_Fmap_c *this,int param_1,cXyz *param_2)

{
  JPABaseEmitter *pJVar1;
  
  pJVar1 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,9,0x357,param_2
                              ,(csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1,
                              (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
  *(JPABaseEmitter **)(&this->field_0x50dc + param_1 * 4) = pJVar1;
  return;
}


/* __thiscall dMenu_Fmap_c::_open_fishManMode(void) */

bool __thiscall dMenu_Fmap_c::_open_fishManMode(dMenu_Fmap_c *this)

{
  int iVar1;
  
  if (*(short *)&this->field_0x5116 == 0) {
    init_fishManMode(this);
  }
  iVar1 = paneTransBase(this,*(short *)&this->field_0x5116,DAT_803e61ac,d_menu_fmap::_4256,
                        d_menu_fmap::_4256,'\0',0);
  *(short *)&this->field_0x5116 = *(short *)&this->field_0x5116 + 1;
  if (iVar1 == 1) {
    *(undefined2 *)&this->field_0x5116 = 0;
    *(undefined *)&this->field_0x5177 = 0;
  }
  return iVar1 == 1;
}


/* __thiscall dMenu_Fmap_c::_close_fishManMode(void) */

bool __thiscall dMenu_Fmap_c::_close_fishManMode(dMenu_Fmap_c *this)

{
  int iVar1;
  
  iVar1 = paneTransBase(this,*(short *)&this->field_0x5116,DAT_803e61b7,d_menu_fmap::_4256,
                        d_menu_fmap::_4256,'\0',1);
  *(short *)&this->field_0x5116 = *(short *)&this->field_0x5116 + 1;
  if (iVar1 == 1) {
    *(undefined2 *)&this->field_0x5116 = 0;
    *(undefined *)&this->field_0x516b = 0;
  }
  return iVar1 == 1;
}


/* __thiscall dMenu_Fmap_c::init_fishManMode(void) */

void __thiscall dMenu_Fmap_c::init_fishManMode(dMenu_Fmap_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(undefined *)&this->field_0x516b = 3;
  *(undefined *)&this[1].field_0x1 = 6;
  selCursorHide(this);
  iVar1 = 0;
  iVar3 = 3;
  do {
    iVar2 = &this->field_0x0 + iVar1;
    *(undefined *)(*(int *)(iVar2 + 0x46f4) + 0xaa) = 0;
    *(undefined *)(*(int *)(iVar2 + 0x479c) + 0xaa) = 0;
    iVar1 = iVar1 + 0x38;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar1 = 0;
  iVar3 = 2;
  do {
    *(undefined *)(*(int *)(&this->field_0x46f4 + iVar1) + 0xaa) = 0;
    iVar1 = iVar1 + 0x38;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar1 = 0;
  iVar3 = 8;
  do {
    *(undefined *)(*(int *)(&this->field_0x48b4 + iVar1) + 0xaa) = 0;
    iVar1 = iVar1 + 0x38;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar1 = 0;
  iVar3 = 0x31;
  do {
    *(undefined *)(*(int *)(&this->field_0x3c3c + iVar1) + 0xaa) = 0;
    iVar1 = iVar1 + 0x38;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined *)(*(int *)&this->field_0x2ee4 + 0xaa) = 0;
  *(undefined *)(*(int *)&this->field_0x2f1c + 0xaa) = 0;
  *(undefined *)(*(int *)&this->field_0x2fc4 + 0xaa) = 0;
  *(undefined *)(*(int *)&this->field_0x32d4 + 0xaa) = 0;
  *(undefined *)(*(int *)&this->field_0x330c + 0xaa) = 0;
  *(undefined *)(*(int *)&this->field_0x3344 + 0xaa) = 0;
  iVar1 = 0;
  iVar3 = 8;
  do {
    *(undefined *)(*(int *)(&this->field_0x2c0c + iVar1) + 0xaa) = 0;
    iVar1 = iVar1 + 0x38;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  playerPointGridAnimeInit(this);
  playerPointGridAnime(this);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)&this->field_0x2e74,
             (double)(d_menu_fmap::_4718 *
                     (float)((double)CONCAT44(0x43300000,
                                              (int)*(char *)&this->field_0x5118 ^ 0x80000000) -
                            d_menu_fmap::_4609)),
             (double)(d_menu_fmap::_4718 *
                     (float)((double)CONCAT44(0x43300000,
                                              (int)*(char *)&this->field_0x5119 ^ 0x80000000) -
                            d_menu_fmap::_4609)));
  setDispIslandPos(this,*(char *)&this->field_0x5118,*(char *)&this->field_0x5119);
  zoomMapAlphaSet(this,*(char *)&this->field_0x5118,*(char *)&this->field_0x5119,
                  (fopMsgM_pane_class *)&this->field_0x2f8c,'\x14');
  zoomMapAlphaSet(this,*(char *)&this->field_0x5118,*(char *)&this->field_0x5119,
                  (fopMsgM_pane_class *)&this->field_0x337c,'\x1e');
  *(undefined *)(*(int *)&this->field_0x2f54 + 0xaa) = 0;
  *(undefined *)(*(int *)&this->field_0x2f8c + 0xaa) = 0;
  *(undefined *)(*(int *)&this->field_0x337c + 0xaa) = 0;
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x4b1c,d_menu_fmap::_4256);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)&this->field_0x4b1c);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0x4ae4,*(J2DScreen **)&this->field_0x20,
             (&d_menu_fmap::hist)
             [(int)*(char *)&this->field_0x5118 + (*(char *)&this->field_0x5119 + 3) * 7 + 3]);
  *(undefined *)&this->field_0x5179 = DAT_803e61b4;
  *(undefined *)&this->field_0x517a = DAT_803e61b5;
  *(undefined *)&this->field_0x5177 = 0;
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,0x593d,(cXyz *)0x0,0,0,d_menu_fmap::_4271,d_menu_fmap::_4271,
             d_menu_fmap::_4272,d_menu_fmap::_4272,0);
  return;
}


/* __thiscall dMenu_Fmap_c::movefishManMode(void) */

void __thiscall dMenu_Fmap_c::movefishManMode(dMenu_Fmap_c *this)

{
  Runtime.PPCEABI.H::__ptmf_scall
            ((PTMF *)(&d_menu_fmap::FishManProcMain + (uint)*(byte *)&this->field_0x5177 * 3),this,
             &DAT_80390000);
  return;
}


/* __thiscall dMenu_Fmap_c::fmDispArea(void) */

void __thiscall dMenu_Fmap_c::fmDispArea(dMenu_Fmap_c *this)

{
  int iVar1;
  
  if (*(char *)&this->field_0x5179 == '\0') {
    iVar1 = *(int *)&this->field_0x4ae4;
    if (*(char *)(iVar1 + 0xaa) == '\0') {
      *(undefined *)(iVar1 + 0xaa) = 1;
    }
    else {
      *(undefined *)(iVar1 + 0xaa) = 0;
    }
    *(undefined *)&this->field_0x5179 = DAT_803e61b4;
  }
  else {
    *(char *)&this->field_0x5179 = *(char *)&this->field_0x5179 + -1;
  }
  if (*(char *)&this->field_0x517a == '\0') {
    *(undefined *)(*(int *)&this->field_0x4ae4 + 0xaa) = 0;
    dSv_player_map_c::onSaveArriveGrid
              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,
               (int)*(char *)&this->field_0x5118 + (*(char *)&this->field_0x5119 + 3) * 7 + 3);
    *(undefined *)(*(int *)&this->field_0x2e74 + 0xaa) = 1;
    *(undefined *)(*(int *)&this->field_0x2eac + 0xaa) = 1;
    *(undefined *)(*(int *)&this->field_0x30a4 + 0xaa) = 1;
    *(undefined *)(*(int *)&this->field_0x2ffc + 0xaa) = 0;
    *(undefined *)(*(int *)&this->field_0x3034 + 0xaa) = 0;
    *(undefined *)(*(int *)&this->field_0x306c + 0xaa) = 0;
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8c4,(cXyz *)0x0,0,0,d_menu_fmap::_4271,d_menu_fmap::_4271,
               d_menu_fmap::_4272,d_menu_fmap::_4272,0);
    *(undefined *)&this->field_0x5177 = 1;
  }
  else {
    *(char *)&this->field_0x517a = *(char *)&this->field_0x517a + -1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_Fmap_c::fmZoomGridLv1In(void) */

void __thiscall dMenu_Fmap_c::fmZoomGridLv1In(dMenu_Fmap_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = selGridMaskAlphaCtrl(this,*(short *)&this->field_0x5116,DAT_803e61ad,'\0',0);
  iVar2 = fmapMaskAlphaCtrl(this,*(short *)&this->field_0x5116,DAT_803e61ad,'\0',0);
  iVar3 = paneTranceZoomMap(this,*(short *)&this->field_0x5116 - (ushort)DAT_803e60d8,DAT_803e61ad,
                            *(float *)&this->field_0x2e90 - *(float *)&this->field_0x30b8,
                            *(float *)&this->field_0x2e94 - *(float *)&this->field_0x30bc,
                            d_menu_fmap::_4256,d_menu_fmap::_4256,
                            *(float *)&this->field_0x2e98 / *(float *)&this->field_0x30c8,
                            d_menu_fmap::_4271,'\x02',0);
  *(short *)&this->field_0x5116 = *(short *)&this->field_0x5116 + 1;
  if (((iVar1 == 1) && (iVar2 == 1)) && (iVar3 == 1)) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8c4,(cXyz *)0x0,0,0,d_menu_fmap::_4271,d_menu_fmap::_4271,
               d_menu_fmap::_4272,d_menu_fmap::_4272,0);
    *(undefined2 *)&this->field_0x5116 = 0;
    *(undefined *)(*(int *)&this->field_0x3814 + 0xaa) = 1;
    iVar1 = 0;
    iVar2 = 8;
    do {
      *(undefined *)(*(int *)(&this->field_0x2c0c + iVar1) + 0xae) = 0;
      iVar1 = iVar1 + 0x38;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(undefined *)(*(int *)&this->field_0x2f8c + 0xae) = 0;
    *(undefined *)&this->field_0x5177 = 2;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Fmap_c::fmZoomGridLv2In(void) */

void __thiscall dMenu_Fmap_c::fmZoomGridLv2In(dMenu_Fmap_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = paneTranceZoom2Map(this,*(short *)&this->field_0x5116,DAT_803e61b0,
                             *(float *)&this->field_0x5134 *
                             (*(float *)&this->field_0x3838 / d_menu_fmap::_4719),
                             *(float *)&this->field_0x5138 *
                             (*(float *)&this->field_0x383c / d_menu_fmap::_4719),d_menu_fmap::_4256
                             ,d_menu_fmap::_4256,
                             *(float *)&this->field_0x2f78 / *(float *)&this->field_0x3838,
                             d_menu_fmap::_4271,'\x02',0);
  iVar2 = paneTranceZoomMapAlpah(this,*(short *)&this->field_0x5116,DAT_803e61b0,'\x02',1);
  *(short *)&this->field_0x5116 = *(short *)&this->field_0x5116 + 1;
  if ((iVar1 == 1) && (iVar2 == 1)) {
    *(undefined2 *)&this->field_0x5116 = 0;
    *(undefined *)(*(int *)&this->field_0x2f54 + 0xaa) = 1;
    *(undefined *)(*(int *)&this->field_0x2f8c + 0xaa) = 1;
    *(undefined *)(*(int *)&this->field_0x337c + 0xaa) = 1;
    islandNameSet(this,'\0');
    paneAlphaZoom2Map(this,0,DAT_803e61b1,'\x02',0);
    *(undefined *)&this->field_0x5178 = DAT_803e61b2;
    *(undefined *)&this->field_0x5177 = 3;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Fmap_c::islandNameSet(unsigned char) */

void __thiscall dMenu_Fmap_c::islandNameSet(dMenu_Fmap_c *this,uchar param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined uStack54;
  undefined uStack53;
  undefined uStack50;
  undefined uStack49;
  undefined local_30;
  undefined uStack47;
  undefined local_2c;
  undefined uStack43;
  
  iVar4 = (int)*(char *)&this->field_0x5118 + (*(char *)&this->field_0x5119 + 3) * 7 + 3;
  if ((iVar4 == 0x20) &&
     (iVar3 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2d80),
     iVar3 != 0)) {
    iVar3 = 0x31d7;
  }
  else {
    iVar3 = iVar4 + 0x31a6;
  }
  uVar2 = DAT_803e619c;
  uVar1 = DAT_803e6198;
  if ((((((iVar4 == 0) || (iVar4 == 3)) || (iVar4 == 10)) || ((iVar4 == 0xc || (iVar4 == 0x13)))) ||
      ((iVar4 == 0x16 || ((iVar4 == 0x19 || (iVar4 - 0x27U < 2)))))) ||
     ((iVar4 == 0x2b || (iVar4 == 0x2c)))) {
    uStack50 = (undefined)((uint)DAT_803e619c >> 8);
    uStack49 = (undefined)DAT_803e619c;
    iVar4 = *(int *)(&this->field_0x4b1c + (uint)param_1 * 0x38);
    local_2c = (undefined)((uint)DAT_803e619c >> 0x18);
    *(undefined *)(iVar4 + 0xd0) = local_2c;
    uStack43 = (undefined)((uint)uVar2 >> 0x10);
    *(undefined *)(iVar4 + 0xd1) = uStack43;
    *(undefined *)(iVar4 + 0xd2) = uStack50;
    *(undefined *)(iVar4 + 0xd3) = uStack49;
  }
  else {
    uStack54 = (undefined)((uint)DAT_803e6198 >> 8);
    uStack53 = (undefined)DAT_803e6198;
    iVar4 = *(int *)(&this->field_0x4b1c + (uint)param_1 * 0x38);
    local_30 = (undefined)((uint)DAT_803e6198 >> 0x18);
    *(undefined *)(iVar4 + 0xd0) = local_30;
    uStack47 = (undefined)((uint)uVar1 >> 0x10);
    *(undefined *)(iVar4 + 0xd1) = uStack47;
    *(undefined *)(iVar4 + 0xd2) = uStack54;
    *(undefined *)(iVar4 + 0xd3) = uStack53;
  }
  f_op_msg_mng::fopMsgM_messageGet(*(undefined4 *)(&this->field_0x5148 + (uint)param_1 * 4),iVar3);
  return;
}


/* __thiscall dMenu_Fmap_c::fmMapWrite(void) */

void __thiscall dMenu_Fmap_c::fmMapWrite(dMenu_Fmap_c *this)

{
  int iVar1;
  
  if (*(char *)&this->field_0x5178 == '\0') {
    if (*(short *)&this->field_0x5116 == 0) {
      JAIZelBasic::subBgmStart(JAIZelBasic::zel_basic,(ulong)&DAT_8000005d);
    }
    iVar1 = paneAlphaZoom2Map(this,*(short *)&this->field_0x5116,DAT_803e61b1,'\x02',0);
    *(short *)&this->field_0x5116 = *(short *)&this->field_0x5116 + 1;
    if (iVar1 == 1) {
      *(undefined2 *)&this->field_0x5116 = 0;
      *(undefined *)&this->field_0x5178 = DAT_803e61b3;
      *(undefined *)&this->field_0x5177 = 4;
    }
  }
  else {
    *(char *)&this->field_0x5178 = *(char *)&this->field_0x5178 + -1;
  }
  return;
}


/* __thiscall dMenu_Fmap_c::fmMapWait(void) */

void __thiscall dMenu_Fmap_c::fmMapWait(dMenu_Fmap_c *this)

{
  if (*(char *)&this->field_0x5178 != '\0') {
    *(char *)&this->field_0x5178 = *(char *)&this->field_0x5178 + -1;
  }
  if (((((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
         (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3)) &&
        ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 6 & 1) == 0)) &&
       (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) == 0 &&
        ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 1 & 1) == 0)))) &&
      (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 2 & 1) == 0 &&
       (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 3 & 1) == 0 &&
        ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) == 0)))))) &&
     (*(char *)&this->field_0x5178 != '\0')) {
    return;
  }
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,0x8c5,(cXyz *)0x0,0,0,d_menu_fmap::_4271,d_menu_fmap::_4271,
             d_menu_fmap::_4272,d_menu_fmap::_4272,0);
  *(undefined *)&this->field_0x5177 = 5;
  return;
}


/* WARNING: Removing unreachable block (ram,0x801bac68) */
/* __thiscall dMenu_Fmap_c::paneAlphaZoom2Map(short,
                                              unsigned char,
                                              unsigned char,
                                              int) */

undefined4 __thiscall
dMenu_Fmap_c::paneAlphaZoom2Map
          (dMenu_Fmap_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

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
          dVar3 = (double)(float)((double)d_menu_fmap::_4271 - dVar3);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x337c,(float)dVar3);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)&this->field_0x337c);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x4b1c,(float)dVar3);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)&this->field_0x4b1c);
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Fmap_c::fmZoomGridLv2Out(void) */

void __thiscall dMenu_Fmap_c::fmZoomGridLv2Out(dMenu_Fmap_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = paneTranceZoom2Map(this,*(short *)&this->field_0x5116,DAT_803e61b0,d_menu_fmap::_4256,
                             d_menu_fmap::_4256,
                             *(float *)&this->field_0x5134 *
                             (*(float *)&this->field_0x3838 / d_menu_fmap::_4719),
                             *(float *)&this->field_0x5138 *
                             (*(float *)&this->field_0x383c / d_menu_fmap::_4719),d_menu_fmap::_4271
                             ,*(float *)&this->field_0x2f78 / *(float *)&this->field_0x3838,'\x02',1
                            );
  iVar2 = paneTranceZoomMapAlpah(this,*(short *)&this->field_0x5116,DAT_803e61b0,'\x02',0);
  *(short *)&this->field_0x5116 = *(short *)&this->field_0x5116 + 1;
  if ((iVar1 == 1) && (iVar2 == 1)) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8c5,(cXyz *)0x0,0,0,d_menu_fmap::_4271,d_menu_fmap::_4271,
               d_menu_fmap::_4272,d_menu_fmap::_4272,0);
    iVar1 = 0;
    *(undefined *)(*(int *)&this->field_0x3814 + 0xaa) = 0;
    iVar2 = 8;
    do {
      *(undefined *)(*(int *)(&this->field_0x2c0c + iVar1) + 0xae) = 1;
      iVar1 = iVar1 + 0x38;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(undefined *)(*(int *)&this->field_0x2f8c + 0xae) = 1;
    *(undefined2 *)&this->field_0x5116 = 0;
    *(undefined *)&this->field_0x5177 = 6;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Fmap_c::fmZoomGridLv1Out(void) */

void __thiscall dMenu_Fmap_c::fmZoomGridLv1Out(dMenu_Fmap_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = selGridMaskAlphaCtrl
                    (this,*(short *)&this->field_0x5116 - (ushort)DAT_803e60cc,DAT_803e60ca,'\0',1);
  iVar2 = fmapMaskAlphaCtrl(this,*(short *)&this->field_0x5116 - (ushort)DAT_803e60cc,DAT_803e60ca,
                            '\0',1);
  iVar3 = paneTranceZoomMap(this,*(short *)&this->field_0x5116 - (ushort)DAT_803e60d8,DAT_803e61af,
                            d_menu_fmap::_4256,d_menu_fmap::_4256,
                            *(float *)&this->field_0x2e90 - *(float *)&this->field_0x30b8,
                            *(float *)&this->field_0x2e94 - *(float *)&this->field_0x30bc,
                            d_menu_fmap::_4271,
                            *(float *)&this->field_0x2e98 / *(float *)&this->field_0x30c8,'\x02',1);
  *(short *)&this->field_0x5116 = *(short *)&this->field_0x5116 + 1;
  if (((iVar1 == 1) && (iVar2 == 1)) && (iVar3 == 1)) {
    *(undefined2 *)&this->field_0x5116 = 0;
    *(undefined *)(*(int *)&this->field_0x2e74 + 0xaa) = 0;
    *(undefined *)(*(int *)&this->field_0x2eac + 0xaa) = 0;
    *(undefined *)(*(int *)&this->field_0x30a4 + 0xaa) = 0;
    *(undefined *)&this->field_0x5178 = DAT_803e61b6;
    *(undefined *)&this->field_0x5177 = 7;
  }
  return;
}


/* __thiscall dMenu_Fmap_c::fmEndWait(void) */

void __thiscall dMenu_Fmap_c::fmEndWait(dMenu_Fmap_c *this)

{
  if (*(char *)&this->field_0x5178 == '\0') {
    *(undefined *)&this->field_0x510c = 1;
    return;
  }
  *(char *)&this->field_0x5178 = *(char *)&this->field_0x5178 + -1;
  return;
}


/* __thiscall dMenu_Fmap_c::_open_wallPaper(void) */

bool __thiscall dMenu_Fmap_c::_open_wallPaper(dMenu_Fmap_c *this)

{
  int iVar1;
  
  if (*(short *)&this->field_0x5116 == 0) {
    *(undefined *)&this[1].field_0x1 = 5;
    selCursorHide(this);
  }
  iVar1 = paneTransBase(this,*(short *)&this->field_0x5116,DAT_803e60d0,
                        (float)((double)CONCAT44(0x43300000,(int)DAT_803e60d2 ^ 0x80000000) -
                               d_menu_fmap::_4609),d_menu_fmap::_4256,'\0',0);
  *(short *)&this->field_0x5116 = *(short *)&this->field_0x5116 + 1;
  if (iVar1 == 1) {
    *(undefined2 *)&this->field_0x5116 = 0;
    *(undefined *)&this->field_0x516b = 2;
  }
  return iVar1 == 1;
}


/* __thiscall dMenu_Fmap_c::getButtonIconMode(void) */

uint __thiscall dMenu_Fmap_c::getButtonIconMode(dMenu_Fmap_c *this)

{
  int iVar1;
  uint uVar2;
  
  if (*(char *)&this->field_0x5113 == '\x01') {
    iVar1 = dMenu_Fmap2_c::getButtonIconMode((dMenu_Fmap2_c *)&this->field_0x24);
    uVar2 = iVar1 + 7;
  }
  else {
    if (*(char *)&this->field_0x516a == '\0') {
      uVar2 = (uint)*(byte *)&this[1].field_0x1;
    }
    else {
      iVar1 = dMenu_Fmap2_c::getButtonIconMode((dMenu_Fmap2_c *)&this->field_0x24);
      uVar2 = iVar1 + 7;
    }
  }
  return uVar2;
}


/* __thiscall dDlst_FMAP_c::draw(void) */

void __thiscall dDlst_FMAP_c::draw(dDlst_FMAP_c *this)

{
  J2DOrthoGraph *pCtx;
  
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(*(J2DScreen **)(this + 4),d_menu_fmap::_4256,d_menu_fmap::_4256,&pCtx->parent);
  return;
}


/* __thiscall dDlst_FMAP_c::~dDlst_FMAP_c(void) */

void __thiscall dDlst_FMAP_c::_dDlst_FMAP_c(dDlst_FMAP_c *this)

{
  short in_r4;
  
  if (this != (dDlst_FMAP_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_FMAP_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMf_HIO_c::~dMf_HIO_c(void) */

void __thiscall dMf_HIO_c::_dMf_HIO_c(dMf_HIO_c *this)

{
  short in_r4;
  
  if ((this != (dMf_HIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace d_menu_fmap {

void __sinit_d_menu_fmap_cpp(void)

{
  ::dMf_HIO_c::dMf_HIO_c((dMf_HIO_c *)&g_mfHIO);
  Runtime.PPCEABI.H::__register_global_object();
  fmapProcMain = _6156;
  DAT_80392394 = DAT_80392340;
  DAT_80392398 = PTR_SelectGrid_80392344;
  DAT_8039239c = _6157;
  DAT_803923a0 = DAT_8039234c;
  DAT_803923a4 = PTR_ZoomGridLv1In_80392350;
  DAT_803923a8 = _6158;
  DAT_803923ac = DAT_80392358;
  DAT_803923b0 = PTR_ZoomGridLv1Proc_8039235c;
  DAT_803923b4 = _6159;
  DAT_803923b8 = DAT_80392364;
  DAT_803923bc = PTR_ZoomGridLv1Out_80392368;
  DAT_803923c0 = _6160;
  DAT_803923c4 = DAT_80392370;
  DAT_803923c8 = PTR_ZoomGridLv2In_80392374;
  DAT_803923cc = _6161;
  DAT_803923d0 = DAT_8039237c;
  DAT_803923d4 = PTR_ZoomGridLv2Proc_80392380;
  DAT_803923d8 = _6162;
  DAT_803923dc = DAT_80392388;
  DAT_803923e0 = PTR_ZoomGridLv2Out_8039238c;
  mainProc = _6636;
  DAT_80392400 = DAT_803923e8;
  DAT_80392404 = PTR_FmapProc_803923ec;
  DAT_80392408 = _6637;
  DAT_8039240c = DAT_803923f4;
  DAT_80392410 = PTR_HikakuProc_803923f8;
  HikakuProcMain = _6656;
  DAT_8039243c = DAT_80392418;
  DAT_80392440 = PTR_fmap2Open_8039241c;
  DAT_80392444 = _6657;
  DAT_80392448 = DAT_80392424;
  DAT_8039244c = PTR_fmap2Move_80392428;
  DAT_80392450 = _6658;
  DAT_80392454 = DAT_80392430;
  DAT_80392458 = PTR_fmap2Close_80392434;
  warpProcMain = _7142;
  DAT_8039249c = DAT_80392460;
  DAT_803924a0 = PTR_wrapMove_80392464;
  DAT_803924a4 = _7143;
  DAT_803924a8 = DAT_8039246c;
  DAT_803924ac = PTR_wrapSelWinFadeIn1_80392470;
  DAT_803924b0 = _7144;
  DAT_803924b4 = DAT_80392478;
  DAT_803924b8 = PTR_wrapSelect_8039247c;
  DAT_803924bc = _7145;
  DAT_803924c0 = DAT_80392484;
  DAT_803924c4 = PTR_wrapSelWinFadeOut_80392488;
  DAT_803924c8 = _7146;
  DAT_803924cc = DAT_80392490;
  DAT_803924d0 = PTR_wrapSelWarp_80392494;
  FishManProcMain = _8086;
  DAT_80392538 = DAT_803924d8;
  DAT_8039253c = PTR_fmDispArea_803924dc;
  DAT_80392540 = _8087;
  DAT_80392544 = DAT_803924e4;
  DAT_80392548 = PTR_fmZoomGridLv1In_803924e8;
  DAT_8039254c = _8088;
  DAT_80392550 = DAT_803924f0;
  DAT_80392554 = PTR_fmZoomGridLv2In_803924f4;
  DAT_80392558 = _8089;
  DAT_8039255c = DAT_803924fc;
  DAT_80392560 = PTR_fmMapWrite_80392500;
  DAT_80392564 = _8090;
  DAT_80392568 = DAT_80392508;
  DAT_8039256c = PTR_fmMapWait_8039250c;
  DAT_80392570 = _8091;
  DAT_80392574 = DAT_80392514;
  DAT_80392578 = PTR_fmZoomGridLv2Out_80392518;
  DAT_8039257c = _8092;
  DAT_80392580 = DAT_80392520;
  DAT_80392584 = PTR_fmZoomGridLv1Out_80392524;
  DAT_80392588 = _8093;
  DAT_8039258c = DAT_8039252c;
  DAT_80392590 = PTR_fmEndWait_80392530;
  return;
}

