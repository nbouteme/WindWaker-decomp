#include <d_menu_dmap.h>
#include <J2DGraph/J2DPicture.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <f_op_msg_mng.h>
#include <J2DGraph/J2DTextBox.h>
#include <d_menu_dmap.h>
#include <JKernel/JKRArchivePub.h>
#include <J2DGraph/J2DWindow.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <d_map.h>
#include <d_stage.h>
#include <SComponent/c_math.h>
#include <d_save.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_lib.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <MSL_C.PPCEABI.bare.H/arith.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DPane.h>
#include <J2DGraph/J2DScreen.h>
#include <m_Do_hostIO.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dMd_HIO_c.h>
#include <dMenu_Dmap_c.h>


namespace d_menu_dmap {
}

namespace d_menu_dmap {
undefined g_mdHIO;
}

/* __thiscall dMd_HIO_c::dMd_HIO_c(void) */

void __thiscall dMd_HIO_c::dMd_HIO_c(dMd_HIO_c *this)

{
  *(undefined1 **)this = &__vt;
  *(undefined4 *)(this + 0x10) = 0xffffffff;
  *(undefined4 *)(this + 0x14) = 0xffffffff;
  *(undefined4 *)(this + 0x1c) = 0xffffffff;
  *(undefined4 *)(this + 0x20) = 0xffffffff;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  *(undefined4 *)(this + 0x38) = 0xffffffff;
  *(undefined2 *)(this + 6) = 0;
  *(undefined2 *)(this + 8) = 0;
  *(undefined2 *)(this + 10) = 0xe;
  *(undefined2 *)(this + 0xc) = 0xe;
  this[0x10] = (dMd_HIO_c)0xff;
  this[0x11] = (dMd_HIO_c)0xc4;
  this[0x12] = (dMd_HIO_c)0x0;
  this[0x14] = (dMd_HIO_c)0x20;
  this[0x15] = (dMd_HIO_c)0x20;
  this[0x16] = (dMd_HIO_c)0x0;
  this[0x13] = (dMd_HIO_c)0xff;
  this[0x17] = (dMd_HIO_c)0x0;
  *(undefined2 *)(this + 0x24) = 0x10;
  *(undefined2 *)(this + 0x26) = 8;
  this[0x28] = (dMd_HIO_c)0xa8;
  this[0x29] = (dMd_HIO_c)0xa8;
  this[0x2a] = (dMd_HIO_c)0xa8;
  this[0x2c] = (dMd_HIO_c)0x40;
  this[0x2d] = (dMd_HIO_c)0x20;
  this[0x2e] = (dMd_HIO_c)0x0;
  this[0x2b] = (dMd_HIO_c)0xff;
  this[0x2f] = (dMd_HIO_c)0x0;
  *(undefined2 *)(this + 0x18) = 0x20;
  *(undefined2 *)(this + 0x1a) = 0x20;
  this[0x1c] = (dMd_HIO_c)0xff;
  this[0x1d] = (dMd_HIO_c)0xff;
  this[0x1e] = (dMd_HIO_c)0xff;
  this[0x20] = (dMd_HIO_c)0x0;
  this[0x21] = (dMd_HIO_c)0x0;
  this[0x22] = (dMd_HIO_c)0x0;
  this[0x1f] = (dMd_HIO_c)0xff;
  this[0x23] = (dMd_HIO_c)0x0;
  *(undefined2 *)(this + 0x30) = 0x10;
  *(undefined2 *)(this + 0x32) = 0x10;
  this[0x34] = (dMd_HIO_c)0xff;
  this[0x35] = (dMd_HIO_c)0x0;
  this[0x36] = (dMd_HIO_c)0xff;
  this[0x38] = (dMd_HIO_c)0x0;
  this[0x39] = (dMd_HIO_c)0x0;
  this[0x3a] = (dMd_HIO_c)0x0;
  this[0x37] = (dMd_HIO_c)0xff;
  this[0x3b] = (dMd_HIO_c)0x0;
  *(undefined2 *)(this + 0x3c) = 4;
  *(undefined2 *)(this + 0x3e) = 10;
  *(undefined2 *)(this + 0x40) = 2;
  *(undefined2 *)(this + 0x42) = 2;
  *(undefined2 *)(this + 0x44) = 2;
  *(undefined2 *)(this + 0x46) = 2;
  *(undefined2 *)(this + 0x48) = 2;
  return;
}


/* __thiscall dMenu_Dmap_c::changeFloorTexture(J2DPane *,
                                               int) */

void __thiscall dMenu_Dmap_c::changeFloorTexture(dMenu_Dmap_c *this,J2DPane *param_1,int param_2)

{
  if ((param_2 < 0) || (0x13 < param_2)) {
    param_2 = 0;
  }
  J2DPicture::changeTexture((J2DPicture *)param_1,(&d_menu_dmap::floor_name_4096)[param_2],0);
  return;
}


/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* WARNING: Removing unreachable block (ram,0x801a92b4) */
/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall dMenu_Dmap_c::screenSet(void) */

void __thiscall dMenu_Dmap_c::screenSet(dMenu_Dmap_c *this)

{
  dMenu_Dmap_c dVar1;
  dMenu_Dmap_c dVar2;
  dMenu_Dmap_c dVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  dMenu_Dmap_c *pdVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined8 in_f31;
  double dVar11;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  fopMsgM_pane_class fStack268;
  fopMsgM_pane_class fStack212;
  longlong local_98;
  longlong local_90;
  longlong local_88;
  longlong local_80;
  longlong local_78;
  longlong local_70;
  longlong local_68;
  longlong local_60;
  undefined auStack8 [8];
  
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar5 = 0;
  iVar8 = 0;
  iVar9 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar9 + 0xc),*(J2DScreen **)(this + 8),
               *(int *)((int)&d_menu_dmap::l_ft_4104 + iVar8));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar9 + 0x354),*(J2DScreen **)(this + 8),
               *(int *)((int)&d_menu_dmap::l_fd_4105 + iVar8));
    iVar5 = iVar5 + 1;
    iVar8 = iVar8 + 4;
    iVar9 = iVar9 + 0x38;
  } while (iVar5 < 0xf);
  iVar5 = 0;
  iVar8 = 0;
  iVar9 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar9 + 0x69c),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_dmap::l_car_4106 + iVar8));
    iVar5 = iVar5 + 1;
    iVar8 = iVar8 + 4;
    iVar9 = iVar9 + 0x38;
  } while (iVar5 < 4);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x77c),*(J2DScreen **)(this + 8),0x6e6d3030);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x77c),*(JUTFont **)(this + 0x14a8));
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x7b4),*(J2DScreen **)(this + 8),0x6e6d3031);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x7b4),*(JUTFont **)(this + 0x14a8));
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x7ec),*(J2DScreen **)(this + 8),0x69746e6d);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x824),*(J2DScreen **)(this + 8),0x69746e6b);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x894),*(J2DScreen **)(this + 8),0x73747230);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x8cc),*(J2DScreen **)(this + 8),0x73743030);
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ != '\0') {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x8cc),(double)d_menu_dmap::_4382,
               (double)d_menu_dmap::_4383);
  }
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x904),*(J2DScreen **)(this + 8),0x6e743030);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x93c),*(J2DScreen **)(this + 8),0x6e6b3030);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x974),*(J2DScreen **)(this + 8),0x6e6f3131);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x85c),*(J2DScreen **)(this + 8),0x6d736b30);
  local_98 = (longlong)(int)*(float *)(*(int *)(this + 0x974) + 0xa4);
  *(short *)(this + 0x9aa) = (short)(int)*(float *)(*(int *)(this + 0x974) + 0xa4);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x894),*(JUTFont **)(this + 0x14ac));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x8cc),*(JUTFont **)(this + 0x14a8));
  local_124 = 0xffffffff;
  local_120 = 0xffffffff;
  iVar5 = *(int *)(this + 0x894);
  *(undefined *)(iVar5 + 0xf4) = 0xff;
  *(undefined *)(iVar5 + 0xf5) = 0xff;
  *(undefined *)(iVar5 + 0xf6) = 0xff;
  *(undefined *)(iVar5 + 0xf7) = 0xff;
  local_12c = 0xff;
  local_128 = 0xff;
  local_16c = 0xff;
  iVar5 = *(int *)(this + 0x894);
  *(undefined *)(iVar5 + 0xd0) = 0;
  *(undefined *)(iVar5 + 0xd1) = 0;
  *(undefined *)(iVar5 + 0xd2) = 0;
  *(undefined *)(iVar5 + 0xd3) = 0xff;
  local_134 = 0xff;
  local_130 = 0xff;
  local_170 = 0xff;
  iVar5 = *(int *)(this + 0x894);
  *(undefined *)(iVar5 + 0xd4) = 0;
  *(undefined *)(iVar5 + 0xd5) = 0;
  *(undefined *)(iVar5 + 0xd6) = 0;
  *(undefined *)(iVar5 + 0xd7) = 0xff;
  local_13c = 0xffffffff;
  local_138 = 0xffffffff;
  iVar5 = *(int *)(this + 0x8cc);
  *(undefined *)(iVar5 + 0xf4) = 0xff;
  *(undefined *)(iVar5 + 0xf5) = 0xff;
  *(undefined *)(iVar5 + 0xf6) = 0xff;
  *(undefined *)(iVar5 + 0xf7) = 0xff;
  local_144 = 0xff;
  local_140 = 0xff;
  local_174 = 0xff;
  iVar5 = *(int *)(this + 0x8cc);
  *(undefined *)(iVar5 + 0xd0) = 0;
  *(undefined *)(iVar5 + 0xd1) = 0;
  *(undefined *)(iVar5 + 0xd2) = 0;
  *(undefined *)(iVar5 + 0xd3) = 0xff;
  local_14c = 0xff;
  local_148 = 0xff;
  local_178 = 0xff;
  iVar5 = *(int *)(this + 0x8cc);
  *(undefined *)(iVar5 + 0xd4) = 0;
  *(undefined *)(iVar5 + 0xd5) = 0;
  *(undefined *)(iVar5 + 0xd6) = 0;
  *(undefined *)(iVar5 + 0xd7) = 0xff;
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x9ac),*(J2DScreen **)(this + 8),0x64746c65);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x9ac),*(JUTFont **)(this + 0x14a8));
  dnameSet(this);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x9e4),*(J2DScreen **)(this + 8),0x64743030);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xa1c),*(J2DScreen **)(this + 8),0x646b3030);
  iVar5 = 0;
  iVar8 = 0;
  iVar9 = 0;
  do {
    pdVar7 = this + iVar9;
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar7 + 0xa54),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_dmap::l_it_4107 + iVar8));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar7 + 0xafc),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_dmap::l_ik_4108 + iVar8));
    iVar6 = iVar8 + 0x1afc;
    JKRArchive::readTypeResource
              (*(void **)(this + iVar6),0xc00,0x54494d47,
               *(char **)((int)&d_menu_dmap::itmTex_4114 + iVar8),
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
    J2DPicture::changeTexture(*(J2DPicture **)(pdVar7 + 0xa54),*(ResTIMG **)(this + iVar6),'\0');
    J2DPicture::changeTexture(*(J2DPicture **)(pdVar7 + 0xafc),*(ResTIMG **)(this + iVar6),'\0');
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar7 + 0xba4),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_dmap::l_ip_4109 + iVar8));
    iVar5 = iVar5 + 1;
    iVar8 = iVar8 + 4;
    iVar9 = iVar9 + 0x38;
  } while (iVar5 < 3);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xc4c),*(J2DScreen **)(this + 4),0x69703031);
  iVar5 = 0;
  iVar8 = 0;
  iVar9 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar9 + 0xc84),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_dmap::l_lnk_4110 + iVar8));
    iVar5 = iVar5 + 1;
    iVar8 = iVar8 + 4;
    iVar9 = iVar9 + 0x38;
  } while (iVar5 < 3);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xd2c),*(J2DScreen **)(this + 4),0x62657931);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xd64),*(J2DScreen **)(this + 4),0x62657932);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xd9c),*(J2DScreen **)(this + 4),0x626f7373);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xdd4),*(J2DScreen **)(this + 4),0x626f7332);
  iVar5 = 0;
  iVar8 = 0;
  iVar9 = 0;
  do {
    pdVar7 = this + iVar9;
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar7 + 0xe7c),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_dmap::l_fl_4111 + iVar8));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar7 + 0xfcc),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_dmap::l_fb_4112 + iVar8));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar7 + 0x111c),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_dmap::l_fbk_4113 + iVar8));
    iVar5 = iVar5 + 1;
    iVar8 = iVar8 + 4;
    iVar9 = iVar9 + 0x38;
  } while (iVar5 < 6);
  iVar5 = *(int *)(this + 0xfcc);
  dVar1 = *(dMenu_Dmap_c *)(iVar5 + 0xf5);
  dVar2 = *(dMenu_Dmap_c *)(iVar5 + 0xf6);
  dVar3 = *(dMenu_Dmap_c *)(iVar5 + 0xf7);
  this[0x14b8] = *(dMenu_Dmap_c *)(iVar5 + 0xf4);
  this[0x14b9] = dVar1;
  this[0x14ba] = dVar2;
  this[0x14bb] = dVar3;
  local_150 = *(undefined4 *)(*(int *)(this + 0xfcc) + 0x104);
  local_150._0_1_ = SUB41((uint)local_150 >> 0x18,0);
  this[0x14c0] = local_150._0_1_;
  local_150._1_1_ = SUB41((uint)local_150 >> 0x10,0);
  this[0x14c1] = local_150._1_1_;
  local_150._2_1_ = SUB41((uint)local_150 >> 8,0);
  this[0x14c2] = local_150._2_1_;
  this[0x14c3] = local_150._3_1_;
  local_154 = *(undefined4 *)(*(int *)(this + 0xfcc) + 0x108);
  local_154._0_1_ = SUB41((uint)local_154 >> 0x18,0);
  this[0x14c8] = local_154._0_1_;
  local_154._1_1_ = SUB41((uint)local_154 >> 0x10,0);
  this[0x14c9] = local_154._1_1_;
  local_154._2_1_ = SUB41((uint)local_154 >> 8,0);
  this[0x14ca] = local_154._2_1_;
  this[0x14cb] = local_154._3_1_;
  iVar5 = *(int *)(this + 0x10e4);
  dVar1 = *(dMenu_Dmap_c *)(iVar5 + 0xf5);
  dVar2 = *(dMenu_Dmap_c *)(iVar5 + 0xf6);
  dVar3 = *(dMenu_Dmap_c *)(iVar5 + 0xf7);
  local_11c = *(undefined4 *)(iVar5 + 0xf4);
  local_118 = *(undefined4 *)(iVar5 + 0xf8);
  local_114 = *(undefined4 *)(iVar5 + 0xfc);
  local_110 = *(undefined4 *)(iVar5 + 0x100);
  this[0x14b4] = *(dMenu_Dmap_c *)(undefined4 *)(iVar5 + 0xf4);
  this[0x14b5] = dVar1;
  this[0x14b6] = dVar2;
  this[0x14b7] = dVar3;
  local_158 = *(undefined4 *)(*(int *)(this + 0x10e4) + 0x104);
  local_158._0_1_ = SUB41((uint)local_158 >> 0x18,0);
  this[0x14bc] = local_158._0_1_;
  local_158._1_1_ = SUB41((uint)local_158 >> 0x10,0);
  this[0x14bd] = local_158._1_1_;
  local_158._2_1_ = SUB41((uint)local_158 >> 8,0);
  this[0x14be] = local_158._2_1_;
  this[0x14bf] = local_158._3_1_;
  local_15c = *(undefined4 *)(*(int *)(this + 0x10e4) + 0x108);
  local_15c._0_1_ = SUB41((uint)local_15c >> 0x18,0);
  this[0x14c4] = local_15c._0_1_;
  local_15c._1_1_ = SUB41((uint)local_15c >> 0x10,0);
  this[0x14c5] = local_15c._1_1_;
  local_15c._2_1_ = SUB41((uint)local_15c >> 8,0);
  this[0x14c6] = local_15c._2_1_;
  this[0x14c7] = local_15c._3_1_;
  iVar8 = 4;
  iVar5 = 0xe0;
  do {
    pdVar7 = this + iVar5;
    uVar4 = *(undefined4 *)(this + 0xea0);
    *(undefined4 *)(pdVar7 + 0xea8) = uVar4;
    *(undefined4 *)(pdVar7 + 0xea0) = uVar4;
    uVar4 = *(undefined4 *)(this + 0xea4);
    *(undefined4 *)(pdVar7 + 0xeac) = uVar4;
    *(undefined4 *)(pdVar7 + 0xea4) = uVar4;
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar7 + 0xe7c));
    uVar4 = *(undefined4 *)(this + 0xff0);
    *(undefined4 *)(pdVar7 + 0xff8) = uVar4;
    *(undefined4 *)(pdVar7 + 0xff0) = uVar4;
    uVar4 = *(undefined4 *)(this + 0xff4);
    *(undefined4 *)(pdVar7 + 0xffc) = uVar4;
    *(undefined4 *)(pdVar7 + 0xff4) = uVar4;
    local_188 = *(undefined4 *)(this + 0x14b8);
    local_184 = local_188;
    local_180 = local_188;
    local_17c = local_188;
    local_160 = local_188;
    J2DWindow::setContentsColor
              (*(J2DWindow **)(pdVar7 + 0xfcc),(TColor)&local_188,(TColor)&local_184,
               (TColor)&local_180,(TColor)&local_17c);
    local_164 = *(undefined4 *)(this + 0x14c0);
    iVar9 = *(int *)(pdVar7 + 0xfcc);
    local_164._0_1_ = (undefined)((uint)local_164 >> 0x18);
    *(undefined *)(iVar9 + 0x104) = local_164._0_1_;
    local_164._1_1_ = (undefined)((uint)local_164 >> 0x10);
    *(undefined *)(iVar9 + 0x105) = local_164._1_1_;
    local_164._2_1_ = (undefined)((uint)local_164 >> 8);
    *(undefined *)(iVar9 + 0x106) = local_164._2_1_;
    *(undefined *)(iVar9 + 0x107) = (undefined)local_164;
    local_168 = *(undefined4 *)(this + 0x14c8);
    iVar9 = *(int *)(pdVar7 + 0xfcc);
    local_168._0_1_ = (undefined)((uint)local_168 >> 0x18);
    *(undefined *)(iVar9 + 0x108) = local_168._0_1_;
    local_168._1_1_ = (undefined)((uint)local_168 >> 0x10);
    *(undefined *)(iVar9 + 0x109) = local_168._1_1_;
    local_168._2_1_ = (undefined)((uint)local_168 >> 8);
    *(undefined *)(iVar9 + 0x10a) = local_168._2_1_;
    *(undefined *)(iVar9 + 0x10b) = (undefined)local_168;
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar7 + 0xfcc));
    uVar4 = *(undefined4 *)(this + 0x1140);
    *(undefined4 *)(pdVar7 + 0x1148) = uVar4;
    *(undefined4 *)(pdVar7 + 0x1140) = uVar4;
    uVar4 = *(undefined4 *)(this + 0x1144);
    *(undefined4 *)(pdVar7 + 0x114c) = uVar4;
    *(undefined4 *)(pdVar7 + 0x1144) = uVar4;
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar7 + 0x111c));
    iVar8 = iVar8 + 1;
    iVar5 = iVar5 + 0x38;
  } while (iVar8 < 6);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x126c),*(J2DScreen **)(this + 4),0x66773030);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x12a4),*(J2DScreen **)(this + 4),0x66773031);
  iVar5 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6d706d6b);
  *(undefined *)(iVar5 + 0xaa) = 0;
  iVar5 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6d707032);
  *(undefined *)(iVar5 + 0xaa) = 0;
  iVar5 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6d707031);
  *(undefined *)(iVar5 + 0xaa) = 0;
  iVar5 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6d707030);
  *(undefined *)(iVar5 + 0xaa) = 0;
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x12dc),*(J2DScreen **)(this + 4),0x63633338);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1314),*(J2DScreen **)(this + 4),0x63633331);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x134c),*(J2DScreen **)(this + 4),0x63633234);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1384),*(J2DScreen **)(this + 4),0x63633137);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x13bc),*(J2DScreen **)(this + 4),0x63633130);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x13f4),*(J2DScreen **)(this + 4),0x63633035);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x142c),*(J2DScreen **)(this + 4),0x63633030);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1464),*(J2DScreen **)(this + 4),0x6d736b);
  f_op_msg_mng::fopMsgM_setPaneData(&fStack212,*(J2DScreen **)(this + 4),0x6d706d6b);
  f_op_msg_mng::fopMsgM_setPaneData(&fStack268,*(J2DScreen **)(this + 4),0x6d707031);
  this[0x1498] = (dMenu_Dmap_c)0x82;
  this[0x890] = (dMenu_Dmap_c)0x82;
  local_98 = (longlong)(int)fStack212.mPosCenterOrig.x;
  *(short *)(this + 0x1e16) = (short)(int)fStack212.mPosCenterOrig.x;
  local_90 = (longlong)(int)fStack212.mPosCenterOrig.y;
  *(short *)(this + 0x1e18) = (short)(int)fStack212.mPosCenterOrig.y;
  local_88 = (longlong)(int)fStack212.mSizeOrig.x;
  *(short *)(this + 0x1e1a) = (short)(int)fStack212.mSizeOrig.x;
  local_80 = (longlong)(int)fStack212.mSizeOrig.y;
  *(short *)(this + 0x1e1c) = (short)(int)fStack212.mSizeOrig.y;
  local_78 = (longlong)(int)fStack268.mPosCenterOrig.x;
  *(short *)(this + 0x1e1e) = (short)(int)fStack268.mPosCenterOrig.x;
  local_70 = (longlong)(int)fStack268.mPosCenterOrig.y;
  *(short *)(this + 0x1e20) = (short)(int)fStack268.mPosCenterOrig.y;
  local_68 = (longlong)(int)fStack268.mSizeOrig.x;
  *(short *)(this + 0x1e22) = (short)(int)fStack268.mSizeOrig.x;
  local_60 = (longlong)(int)fStack268.mSizeOrig.y;
  *(short *)(this + 0x1e24) = (short)(int)fStack268.mSizeOrig.y;
  iVar5 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6d707032);
  dVar11 = (double)(*(float *)(iVar5 + 0x18) - *(float *)(iVar5 + 0x10));
  iVar5 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6d707032);
  iVar8 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6d707031);
  *(short *)(this + 0x1e26) =
       (short)(int)(*(float *)(iVar8 + 0x10) - (float)((double)*(float *)(iVar5 + 0x10) + dVar11));
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  return;
}


namespace d_menu_dmap {

/* __stdcall dMap_isBossDoor(stage_tgsc_data_class *) */

undefined4 dMap_isBossDoor(char *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = MSL_C.PPCEABI.bare.H::strcmp(param_1,"door20");
  if (iVar2 == 0) {
    uVar3 = 1;
  }
  else {
    iVar2 = MSL_C.PPCEABI.bare.H::strcmp(param_1,"door12");
    if (iVar2 == 0) {
      uVar1 = (uint)(int)*(short *)(param_1 + 0x1c) >> 8 & 0xff;
      if ((uVar1 == 0xc) || ((uVar1 < 0xc && (uVar1 == 9)))) {
        return 1;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}

}

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801a98cc) */
/* __thiscall dMenu_Dmap_c::initialize(void) */

void __thiscall dMenu_Dmap_c::initialize(dMenu_Dmap_c *this)

{
  short sVar1;
  short sVar2;
  dMenu_Dmap_c dVar4;
  int *piVar3;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  float fVar11;
  double local_48;
  double local_40;
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar10 = (double)((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.
                   mCurrent.mPos.y;
  *(undefined2 *)(this + 0x7b2) = 0;
  dVar9 = (double)mapOffsetY(this);
  dVar4 = (dMenu_Dmap_c)d_map::dMap_GetFloorNo((double)(float)(dVar10 + dVar9),0x803c9d58);
  this[0x1e2f] = dVar4;
  this[0x1e30] = (dMenu_Dmap_c)0xff;
  piVar3 = (int *)d_stage::dStage_GetKeepDoorInfo();
  piVar6 = piVar3 + 1;
  for (iVar5 = 0; iVar5 < *piVar3; iVar5 = iVar5 + 1) {
    iVar7 = d_menu_dmap::dMap_isBossDoor(piVar6);
    if (iVar7 != 0) {
      dVar4 = (dMenu_Dmap_c)d_map::dMap_GetFloorNo((double)(float)piVar6[4],0x803c9d58);
      this[0x1e30] = dVar4;
    }
    piVar6 = piVar6 + 9;
  }
  d_map::dMap_GetTopBottomFloorNo
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent,this + 0x1e31,this + 0x1e32
            );
  iVar5 = (int)(char)dStage_roomControl_c::mStayNo;
  dVar9 = (double)mapOffsetY(this);
  d_map::dMap_GetFloorNoForDmap((double)(float)(dVar10 + dVar9),0x803c9d58,iVar5);
  dMap_Dmap_c::init(*(dMap_Dmap_c **)(this + 0x14a0),(EVP_PKEY_CTX *)(int)*(short *)(this + 0x1e16))
  ;
  *(ushort *)(this + 0x1e10) =
       *(short *)(this + 0x1e20) +
       ((byte)this[0x1e2f] - 0x80) * (*(short *)(this + 0x1e24) + *(short *)(this + 0x1e26));
  *(undefined2 *)(this + 0x1e0e) = 0x1e0;
  dVar9 = d_menu_dmap::_4523;
  local_48 = (double)CONCAT44(0x43300000,
                              (uint)(byte)this[0x1e32] - (uint)(byte)this[0x1e2f] ^ 0x80000000);
  *(short *)(this + 0x1e12) =
       (short)(int)((*(float *)(this + 0xfe4) - *(float *)(this + 0x101c)) *
                   (float)(local_48 - d_menu_dmap::_4523));
  if ((byte)this[0x1e30] == 0xff) {
    *(undefined2 *)(this + 0x1e14) = 0;
  }
  else {
    local_40 = (double)CONCAT44(0x43300000,
                                (uint)(byte)this[0x1e32] - (uint)(byte)this[0x1e30] ^ 0x80000000);
    *(short *)(this + 0x1e14) =
         (short)(int)((*(float *)(this + 0xfe4) - *(float *)(this + 0x101c)) *
                     (float)(local_40 - dVar9));
  }
  sVar1 = *(short *)(this + 0x1e18);
  sVar2 = *(short *)(this + 0x1e0e);
  iVar5 = *(int *)(this + 0x14a0);
  *(undefined2 *)(iVar5 + 0x35c) = *(undefined2 *)(this + 0x1e16);
  *(short *)(iVar5 + 0x35e) = sVar1 + sVar2;
  sVar1 = *(short *)(this + 0x1e10);
  sVar2 = *(short *)(this + 0x1e0e);
  iVar5 = *(int *)(this + 0x14a0);
  *(undefined2 *)(iVar5 + 0x364) = *(undefined2 *)(this + 0x1e1e);
  *(short *)(iVar5 + 0x366) = sVar1 + sVar2;
  iVar7 = 0;
  for (iVar5 = 0; iVar5 < (int)(((uint)(byte)this[0x1e31] - (uint)(byte)this[0x1e32]) + 1);
      iVar5 = iVar5 + 1) {
    changeFloorTexture(this,*(J2DPane **)(this + iVar7 + 0xe7c),
                       (uint)(byte)this[0x1e32] + iVar5 + -0x76);
    iVar7 = iVar7 + 0x38;
  }
  fVar11 = SComponent::cM_rndF(d_menu_dmap::_4515);
  *(short *)(this + 0x1e28) = (short)(int)(d_menu_dmap::_4515 + fVar11);
  fVar11 = SComponent::cM_rndF(d_menu_dmap::_4516);
  *(short *)(this + 0x1e2a) = (short)(int)(d_menu_dmap::_4515 + fVar11);
  this[0x1e33] = (dMenu_Dmap_c)0x0;
  this[0x1e34] = (dMenu_Dmap_c)0x0;
  *(undefined2 *)(this + 0xcf2) = 0;
  *(undefined2 *)(this + 0xd2a) = 0;
  *(undefined2 *)(this + 0xdd2) = 100;
  fVar11 = SComponent::cM_rndF(d_menu_dmap::_4518);
  *(short *)(this + 0xe0a) = (short)(int)(d_menu_dmap::_4517 + fVar11);
  this[0x1e36] = (dMenu_Dmap_c)0x0;
  fVar11 = SComponent::cM_rndF(d_menu_dmap::_4520);
  *(short *)(this + 0x1e2c) = (short)((int)(d_menu_dmap::_4519 + fVar11) << 1);
  fVar11 = d_menu_dmap::_4521;
  *(float *)(this + 0x1dcc) = -*(float *)(this + 0xa78) * d_menu_dmap::_4521;
  *(float *)(this + 0x1ddc) = *(float *)(this + 0xa7c) * fVar11;
  *(float *)(this + 0x1dd0) = *(float *)(this + 0xa78) * fVar11;
  *(float *)(this + 0x1de0) = *(float *)(this + 0xa7c) * fVar11;
  *(float *)(this + 0x1dd4) = -*(float *)(this + 0xa78) * fVar11;
  *(float *)(this + 0x1de4) = -*(float *)(this + 0xa7c) * fVar11;
  *(float *)(this + 0x1dd8) = *(float *)(this + 0xa78) * fVar11;
  *(float *)(this + 0x1de8) = -*(float *)(this + 0xa7c) * fVar11;
  *(float *)(this + 0x1dec) = -*(float *)(this + 0xff0) * fVar11;
  *(float *)(this + 0x1dfc) = *(float *)(this + 0xff4) * fVar11;
  *(float *)(this + 0x1df0) = *(float *)(this + 0xff0) * fVar11;
  *(float *)(this + 0x1e00) = *(float *)(this + 0xff4) * fVar11;
  *(float *)(this + 0x1df4) = -*(float *)(this + 0xff0) * fVar11;
  *(float *)(this + 0x1e04) = -*(float *)(this + 0xff4) * fVar11;
  *(float *)(this + 0x1df8) = *(float *)(this + 0xff0) * fVar11;
  *(float *)(this + 0x1e08) = -*(float *)(this + 0xff4) * fVar11;
  floorInit(this);
  itemScale(this);
  iVar5 = dSv_memBit_c::isDungeonItem
                    ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,0);
  if (iVar5 == 0) {
    *(undefined *)(*(int *)(this + 0xa54) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + 0xafc) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + 0xba4) + 0xaa) = 0;
  }
  iVar5 = dSv_memBit_c::isDungeonItem
                    ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,2);
  if (iVar5 == 0) {
    *(undefined *)(*(int *)(this + 0xa8c) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + 0xb34) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + 0xbdc) + 0xaa) = 0;
  }
  iVar5 = dSv_memBit_c::isDungeonItem
                    ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,1);
  if (iVar5 == 0) {
    *(undefined *)(*(int *)(this + 0xac4) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + 0xb6c) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + 0xc14) + 0xaa) = 0;
  }
  iVar5 = dSv_memBit_c::isDungeonItem
                    ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,1);
  if ((iVar5 == 0) || (this[0x1e30] == (dMenu_Dmap_c)0xff)) {
    *(undefined *)(*(int *)(this + 0xd9c) + 0xaa) = 0;
  }
  noteInit(this);
  if ((((this[0x1e2e] == (dMenu_Dmap_c)0x0) &&
       (iVar5 = dSv_memBit_c::isDungeonItem
                          ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,0),
       iVar5 != 0)) ||
      ((this[0x1e2e] == (dMenu_Dmap_c)0x1 &&
       (iVar5 = dSv_memBit_c::isDungeonItem
                          ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,2),
       iVar5 != 0)))) ||
     ((this[0x1e2e] == (dMenu_Dmap_c)0x2 &&
      (iVar5 = dSv_memBit_c::isDungeonItem
                         ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,1),
      iVar5 != 0)))) {
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x21;
  }
  else {
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
    d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  return;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Removing unreachable block (ram,0x801aade8) */
/* WARNING: Removing unreachable block (ram,0x801aade0) */
/* WARNING: Removing unreachable block (ram,0x801aadf0) */
/* __thiscall dMenu_Dmap_c::treasureSet(void) */

void __thiscall dMenu_Dmap_c::treasureSet(dMenu_Dmap_c *this)

{
  undefined4 uVar1;
  float fVar2;
  double dVar3;
  int iVar4;
  int *piVar5;
  ulong uVar6;
  uint uVar7;
  dMenu_Dmap_c dVar12;
  uint uVar8;
  int iVar9;
  dMenu_Dmap_c *pdVar10;
  uint uVar11;
  float *pfVar13;
  int iVar14;
  int *piVar15;
  int iVar16;
  undefined4 uVar17;
  double in_f29;
  double in_f30;
  double in_f31;
  undefined local_108;
  undefined uStack263;
  undefined uStack262;
  undefined uStack261;
  undefined local_104;
  undefined uStack259;
  undefined uStack258;
  undefined uStack257;
  undefined local_100;
  undefined uStack255;
  undefined uStack254;
  undefined uStack253;
  undefined local_fc;
  undefined uStack251;
  undefined uStack250;
  undefined uStack249;
  undefined local_f8;
  undefined uStack247;
  undefined uStack246;
  undefined uStack245;
  undefined local_f4;
  undefined uStack243;
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
  undefined local_e8;
  undefined uStack231;
  undefined uStack230;
  undefined uStack229;
  undefined local_e4;
  undefined uStack227;
  undefined uStack226;
  undefined uStack225;
  undefined local_e0;
  undefined uStack223;
  undefined uStack222;
  undefined uStack221;
  undefined local_dc;
  undefined uStack219;
  undefined uStack218;
  undefined uStack217;
  undefined local_d8;
  undefined uStack215;
  undefined uStack214;
  undefined uStack213;
  undefined local_d4;
  undefined uStack211;
  undefined uStack210;
  undefined uStack209;
  undefined local_d0;
  undefined uStack207;
  undefined uStack206;
  undefined uStack205;
  undefined local_cc;
  undefined uStack203;
  undefined uStack202;
  undefined uStack201;
  undefined local_c8;
  undefined uStack199;
  undefined uStack198;
  undefined uStack197;
  undefined local_c4;
  undefined uStack195;
  undefined uStack194;
  undefined uStack193;
  undefined local_c0;
  undefined uStack191;
  undefined uStack190;
  undefined uStack189;
  undefined local_bc;
  undefined uStack187;
  undefined uStack186;
  undefined uStack185;
  undefined local_b8;
  undefined uStack183;
  undefined uStack182;
  undefined uStack181;
  undefined local_b4;
  undefined uStack179;
  undefined uStack178;
  undefined uStack177;
  undefined local_b0;
  undefined uStack175;
  undefined uStack174;
  undefined uStack173;
  undefined local_ac;
  undefined uStack171;
  undefined uStack170;
  undefined uStack169;
  float local_a8;
  float local_a4;
  float local_a0;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar17 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,SUB84(in_f31,0),0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,SUB84(in_f30,0),0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,SUB84(in_f29,0),0);
  iVar4 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                    (0x803c9d58);
  uVar11 = (uint)(*(byte *)(iVar4 + 9) >> 1);
  iVar4 = 0;
  iVar16 = 0x20;
  do {
    this[iVar4 + 0x14e2] = (dMenu_Dmap_c)0x0;
    iVar4 = iVar4 + 0x18;
    iVar16 = iVar16 + -1;
  } while (iVar16 != 0);
  iVar4 = 0;
  iVar16 = 0x20;
  do {
    this[iVar4 + 0x17e2] = (dMenu_Dmap_c)0x0;
    iVar4 = iVar4 + 0x18;
    iVar16 = iVar16 + -1;
  } while (iVar16 != 0);
  this[0x1afa] = (dMenu_Dmap_c)0x0;
  this[0x1ae2] = (dMenu_Dmap_c)0x0;
  iVar4 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getDMap)
                    (0x803c9d58);
  if (iVar4 != 0) {
    piVar5 = (int *)(*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getDMap)
                              (0x803c9d58);
    pfVar13 = (float *)piVar5[1];
    if (*piVar5 != 1) {
      uVar6 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar6,"d_menu_dmap.cpp",0x261,"pinf->num == 1");
      m_Do_printf::OSPanic("d_menu_dmap.cpp",0x261,&DAT_8035f855);
    }
    iVar4 = *piVar5;
    if (0 < iVar4) {
      do {
        in_f31 = (double)*pfVar13;
        in_f30 = (double)pfVar13[1];
        in_f29 = (double)pfVar13[2];
        pfVar13 = pfVar13 + 4;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    iVar4 = dSv_memBit_c::isDungeonItem
                      ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,1);
    if (iVar4 != 0) {
      if ((((uVar11 == 6) &&
           (uVar7 = dSv_player_collect_c::isCollect
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,0,
                               2), uVar7 == 0)) &&
          (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mPriest.field_0xf == '\x02')) ||
         (((uVar11 == 7 &&
           (uVar7 = dSv_player_collect_c::isCollect
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,0,
                               3), uVar7 == 0)) &&
          (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mPriest.field_0xf == '\x01'))))
      {
        if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpPlayerPartnerActor == (daPy_npc_c *)0x0) {
          local_a8 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mPriest.field_0x0.x;
          local_a4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mPriest.field_0x0.y;
          local_a0 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mPriest.field_0x0.z;
        }
        else {
          local_a8 = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpPlayerPartnerActor)->parent).
                     parent.mCurrent.mPos.x;
          local_a4 = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpPlayerPartnerActor)->parent).
                     parent.mCurrent.mPos.y;
          local_a0 = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpPlayerPartnerActor)->parent).
                     parent.mCurrent.mPos.z;
        }
        dVar12 = (dMenu_Dmap_c)d_map::dMap_GetFloorNo((double)local_a4,0x803c9d58);
        if (this[0x1e2f] == dVar12) {
          this[0x1ae2] = (dMenu_Dmap_c)0x1;
          uVar1 = DAT_803e6078;
          iVar4 = *(int *)(this + 0x1acc);
          local_ac = (undefined)((uint)DAT_803e6078 >> 0x18);
          *(undefined *)(iVar4 + 0x104) = local_ac;
          uStack171 = (undefined)((uint)uVar1 >> 0x10);
          *(undefined *)(iVar4 + 0x105) = uStack171;
          uStack170 = (undefined)((uint)uVar1 >> 8);
          *(undefined *)(iVar4 + 0x106) = uStack170;
          uStack169 = (undefined)uVar1;
          *(undefined *)(iVar4 + 0x107) = uStack169;
          uVar1 = DAT_803e607c;
          iVar4 = *(int *)(this + 0x1acc);
          local_b0 = (undefined)((uint)DAT_803e607c >> 0x18);
          *(undefined *)(iVar4 + 0x108) = local_b0;
          uStack175 = (undefined)((uint)uVar1 >> 0x10);
          *(undefined *)(iVar4 + 0x109) = uStack175;
          uStack174 = (undefined)((uint)uVar1 >> 8);
          *(undefined *)(iVar4 + 0x10a) = uStack174;
          uStack173 = (undefined)uVar1;
          *(undefined *)(iVar4 + 0x10b) = uStack173;
          dVar3 = d_menu_dmap::_4523;
          *(float *)(this + 0x1ad8) =
               (float)((double)CONCAT44(0x43300000,(int)DAT_803e6074 ^ 0x80000000) -
                      d_menu_dmap::_4523);
          *(float *)(this + 0x1adc) =
               (float)((double)CONCAT44(0x43300000,(int)DAT_803e6076 ^ 0x80000000) - dVar3);
          fVar2 = d_menu_dmap::_4521;
          *(float *)(this + 0x1ad0) =
               ((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e1e) ^ 0x80000000) -
                       dVar3) + (float)((double)(float)((double)local_a8 - in_f31) / in_f29)) -
               *(float *)(this + 0x1ad8) * d_menu_dmap::_4521;
          *(float *)(this + 0x1ad4) =
               ((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e20) ^ 0x80000000) -
                       dVar3) + (float)((double)(float)((double)local_a0 - in_f30) / in_f29)) -
               *(float *)(this + 0x1adc) * fVar2;
        }
        else {
          if ((this[0x1e35] == (dMenu_Dmap_c)0x0) &&
             (uVar7 = d_map::dMap_GetFloorNo((double)local_a4,0x803c9d58),
             (byte)this[0x1e2f] - 1 == (uVar7 & 0xff))) {
            this[0x1ae2] = (dMenu_Dmap_c)0x1;
            uVar1 = DAT_803e6078;
            iVar4 = *(int *)(this + 0x1acc);
            local_b4 = (undefined)((uint)DAT_803e6078 >> 0x18);
            *(undefined *)(iVar4 + 0x104) = local_b4;
            uStack179 = (undefined)((uint)uVar1 >> 0x10);
            *(undefined *)(iVar4 + 0x105) = uStack179;
            uStack178 = (undefined)((uint)uVar1 >> 8);
            *(undefined *)(iVar4 + 0x106) = uStack178;
            uStack177 = (undefined)uVar1;
            *(undefined *)(iVar4 + 0x107) = uStack177;
            uVar1 = DAT_803e607c;
            iVar4 = *(int *)(this + 0x1acc);
            local_b8 = (undefined)((uint)DAT_803e607c >> 0x18);
            *(undefined *)(iVar4 + 0x108) = local_b8;
            uStack183 = (undefined)((uint)uVar1 >> 0x10);
            *(undefined *)(iVar4 + 0x109) = uStack183;
            uStack182 = (undefined)((uint)uVar1 >> 8);
            *(undefined *)(iVar4 + 0x10a) = uStack182;
            uStack181 = (undefined)uVar1;
            *(undefined *)(iVar4 + 0x10b) = uStack181;
            dVar3 = d_menu_dmap::_4523;
            *(float *)(this + 0x1ad8) =
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e6074 ^ 0x80000000) -
                        d_menu_dmap::_4523);
            *(float *)(this + 0x1adc) =
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e6076 ^ 0x80000000) - dVar3);
            fVar2 = d_menu_dmap::_4521;
            *(float *)(this + 0x1ad0) =
                 ((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e1e) ^ 0x80000000) -
                         dVar3) + (float)((double)(float)((double)local_a8 - in_f31) / in_f29)) -
                 *(float *)(this + 0x1ad8) * d_menu_dmap::_4521;
            *(float *)(this + 0x1ad4) =
                 (((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e20) ^ 0x80000000)
                          - dVar3) + (float)((double)(float)((double)local_a0 - in_f30) / in_f29)) -
                 *(float *)(this + 0x1adc) * fVar2) +
                 (float)((double)CONCAT44(0x43300000,
                                          (int)*(short *)(this + 0x1e24) +
                                          (int)*(short *)(this + 0x1e26) ^ 0x80000000) - dVar3);
          }
          else {
            if ((this[0x1e35] == (dMenu_Dmap_c)0x0) &&
               (uVar7 = d_map::dMap_GetFloorNo((double)local_a4,0x803c9d58),
               (byte)this[0x1e2f] + 1 == (uVar7 & 0xff))) {
              this[0x1ae2] = (dMenu_Dmap_c)0x1;
              uVar1 = DAT_803e6078;
              iVar4 = *(int *)(this + 0x1acc);
              local_bc = (undefined)((uint)DAT_803e6078 >> 0x18);
              *(undefined *)(iVar4 + 0x104) = local_bc;
              uStack187 = (undefined)((uint)uVar1 >> 0x10);
              *(undefined *)(iVar4 + 0x105) = uStack187;
              uStack186 = (undefined)((uint)uVar1 >> 8);
              *(undefined *)(iVar4 + 0x106) = uStack186;
              uStack185 = (undefined)uVar1;
              *(undefined *)(iVar4 + 0x107) = uStack185;
              uVar1 = DAT_803e607c;
              iVar4 = *(int *)(this + 0x1acc);
              local_c0 = (undefined)((uint)DAT_803e607c >> 0x18);
              *(undefined *)(iVar4 + 0x108) = local_c0;
              uStack191 = (undefined)((uint)uVar1 >> 0x10);
              *(undefined *)(iVar4 + 0x109) = uStack191;
              uStack190 = (undefined)((uint)uVar1 >> 8);
              *(undefined *)(iVar4 + 0x10a) = uStack190;
              uStack189 = (undefined)uVar1;
              *(undefined *)(iVar4 + 0x10b) = uStack189;
              dVar3 = d_menu_dmap::_4523;
              *(float *)(this + 0x1ad8) =
                   (float)((double)CONCAT44(0x43300000,(int)DAT_803e6074 ^ 0x80000000) -
                          d_menu_dmap::_4523);
              *(float *)(this + 0x1adc) =
                   (float)((double)CONCAT44(0x43300000,(int)DAT_803e6076 ^ 0x80000000) - dVar3);
              fVar2 = d_menu_dmap::_4521;
              *(float *)(this + 0x1ad0) =
                   ((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e1e) ^ 0x80000000)
                           - dVar3) + (float)((double)(float)((double)local_a8 - in_f31) / in_f29))
                   - *(float *)(this + 0x1ad8) * d_menu_dmap::_4521;
              *(float *)(this + 0x1ad4) =
                   (((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e20) ^ 0x80000000
                                             ) - dVar3) +
                    (float)((double)(float)((double)local_a0 - in_f30) / in_f29)) -
                   *(float *)(this + 0x1adc) * fVar2) -
                   (float)((double)CONCAT44(0x43300000,
                                            (int)*(short *)(this + 0x1e24) +
                                            (int)*(short *)(this + 0x1e26) ^ 0x80000000) - dVar3);
            }
          }
        }
      }
      iVar4 = d_stage::dStage_GetKeepTresureInfo();
      if (iVar4 != 0) {
        iVar4 = 0;
        piVar5 = (int *)d_stage::dStage_GetKeepTresureInfo();
        piVar15 = piVar5 + 1;
        for (iVar16 = 0; iVar16 < *piVar5; iVar16 = iVar16 + 1) {
          uVar7 = (uint)piVar15[2] >> 7 & 0x1f;
          dVar12 = (dMenu_Dmap_c)d_map::dMap_GetFloorNo((double)(float)piVar15[4],0x803c9d58);
          if ((((this[0x1e2f] == dVar12) &&
               (iVar14 = dSv_memBit_c::isTbox
                                   ((dSv_memBit_c *)
                                    &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,uVar7),
               iVar14 == 0)) && (uVar7 != 0xf)) && (uVar7 != 0x10)) {
            pdVar10 = this + iVar4;
            pdVar10[0x14e2] = (dMenu_Dmap_c)0x1;
            uVar1 = DAT_803e6054;
            iVar14 = *(int *)(pdVar10 + 0x14cc);
            local_c4 = (undefined)((uint)DAT_803e6054 >> 0x18);
            *(undefined *)(iVar14 + 0x104) = local_c4;
            uStack195 = (undefined)((uint)uVar1 >> 0x10);
            *(undefined *)(iVar14 + 0x105) = uStack195;
            uStack194 = (undefined)((uint)uVar1 >> 8);
            *(undefined *)(iVar14 + 0x106) = uStack194;
            uStack193 = (undefined)uVar1;
            *(undefined *)(iVar14 + 0x107) = uStack193;
            uVar1 = DAT_803e6058;
            iVar14 = *(int *)(pdVar10 + 0x14cc);
            local_c8 = (undefined)((uint)DAT_803e6058 >> 0x18);
            *(undefined *)(iVar14 + 0x108) = local_c8;
            uStack199 = (undefined)((uint)uVar1 >> 0x10);
            *(undefined *)(iVar14 + 0x109) = uStack199;
            uStack198 = (undefined)((uint)uVar1 >> 8);
            *(undefined *)(iVar14 + 0x10a) = uStack198;
            uStack197 = (undefined)uVar1;
            *(undefined *)(iVar14 + 0x10b) = uStack197;
            dVar3 = d_menu_dmap::_4523;
            *(float *)(pdVar10 + 0x14d8) =
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e604e ^ 0x80000000) -
                        d_menu_dmap::_4523);
            *(float *)(pdVar10 + 0x14dc) =
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e6050 ^ 0x80000000) - dVar3);
            fVar2 = d_menu_dmap::_4521;
            *(float *)(pdVar10 + 0x14d0) =
                 ((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e1e) ^ 0x80000000) -
                         dVar3) +
                 (float)((double)(float)((double)(float)piVar15[3] - in_f31) / in_f29)) -
                 *(float *)(pdVar10 + 0x14d8) * d_menu_dmap::_4521;
            *(float *)(pdVar10 + 0x14d4) =
                 ((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e20) ^ 0x80000000) -
                         dVar3) +
                 (float)((double)(float)((double)(float)piVar15[5] - in_f30) / in_f29)) -
                 *(float *)(pdVar10 + 0x14dc) * fVar2;
            iVar4 = iVar4 + 0x18;
          }
          else {
            if (((this[0x1e35] == (dMenu_Dmap_c)0x0) &&
                (uVar8 = d_map::dMap_GetFloorNo((double)(float)piVar15[4],0x803c9d58),
                (byte)this[0x1e2f] - 1 == (uVar8 & 0xff))) &&
               ((iVar14 = dSv_memBit_c::isTbox
                                    ((dSv_memBit_c *)
                                     &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,uVar7),
                iVar14 == 0 && ((uVar7 != 0xf && (uVar7 != 0x10)))))) {
              pdVar10 = this + iVar4;
              pdVar10[0x14e2] = (dMenu_Dmap_c)0x1;
              uVar1 = DAT_803e6054;
              iVar14 = *(int *)(pdVar10 + 0x14cc);
              local_cc = (undefined)((uint)DAT_803e6054 >> 0x18);
              *(undefined *)(iVar14 + 0x104) = local_cc;
              uStack203 = (undefined)((uint)uVar1 >> 0x10);
              *(undefined *)(iVar14 + 0x105) = uStack203;
              uStack202 = (undefined)((uint)uVar1 >> 8);
              *(undefined *)(iVar14 + 0x106) = uStack202;
              uStack201 = (undefined)uVar1;
              *(undefined *)(iVar14 + 0x107) = uStack201;
              uVar1 = DAT_803e6058;
              iVar14 = *(int *)(pdVar10 + 0x14cc);
              local_d0 = (undefined)((uint)DAT_803e6058 >> 0x18);
              *(undefined *)(iVar14 + 0x108) = local_d0;
              uStack207 = (undefined)((uint)uVar1 >> 0x10);
              *(undefined *)(iVar14 + 0x109) = uStack207;
              uStack206 = (undefined)((uint)uVar1 >> 8);
              *(undefined *)(iVar14 + 0x10a) = uStack206;
              uStack205 = (undefined)uVar1;
              *(undefined *)(iVar14 + 0x10b) = uStack205;
              dVar3 = d_menu_dmap::_4523;
              *(float *)(pdVar10 + 0x14d8) =
                   (float)((double)CONCAT44(0x43300000,(int)DAT_803e604e ^ 0x80000000) -
                          d_menu_dmap::_4523);
              *(float *)(pdVar10 + 0x14dc) =
                   (float)((double)CONCAT44(0x43300000,(int)DAT_803e6050 ^ 0x80000000) - dVar3);
              fVar2 = d_menu_dmap::_4521;
              *(float *)(pdVar10 + 0x14d0) =
                   ((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e1e) ^ 0x80000000)
                           - dVar3) +
                   (float)((double)(float)((double)(float)piVar15[3] - in_f31) / in_f29)) -
                   *(float *)(pdVar10 + 0x14d8) * d_menu_dmap::_4521;
              *(float *)(pdVar10 + 0x14d4) =
                   (((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e20) ^ 0x80000000
                                             ) - dVar3) +
                    (float)((double)(float)((double)(float)piVar15[5] - in_f30) / in_f29)) -
                   *(float *)(pdVar10 + 0x14dc) * fVar2) +
                   (float)((double)CONCAT44(0x43300000,
                                            (int)*(short *)(this + 0x1e24) +
                                            (int)*(short *)(this + 0x1e26) ^ 0x80000000) - dVar3);
              iVar4 = iVar4 + 0x18;
            }
            else {
              if ((((this[0x1e35] == (dMenu_Dmap_c)0x0) &&
                   (uVar8 = d_map::dMap_GetFloorNo((double)(float)piVar15[4],0x803c9d58),
                   (byte)this[0x1e2f] + 1 == (uVar8 & 0xff))) &&
                  (iVar14 = dSv_memBit_c::isTbox
                                      ((dSv_memBit_c *)
                                       &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,uVar7),
                  iVar14 == 0)) && ((uVar7 != 0xf && (uVar7 != 0x10)))) {
                pdVar10 = this + iVar4;
                pdVar10[0x14e2] = (dMenu_Dmap_c)0x1;
                uVar1 = DAT_803e6054;
                iVar14 = *(int *)(pdVar10 + 0x14cc);
                local_d4 = (undefined)((uint)DAT_803e6054 >> 0x18);
                *(undefined *)(iVar14 + 0x104) = local_d4;
                uStack211 = (undefined)((uint)uVar1 >> 0x10);
                *(undefined *)(iVar14 + 0x105) = uStack211;
                uStack210 = (undefined)((uint)uVar1 >> 8);
                *(undefined *)(iVar14 + 0x106) = uStack210;
                uStack209 = (undefined)uVar1;
                *(undefined *)(iVar14 + 0x107) = uStack209;
                uVar1 = DAT_803e6058;
                iVar14 = *(int *)(pdVar10 + 0x14cc);
                local_d8 = (undefined)((uint)DAT_803e6058 >> 0x18);
                *(undefined *)(iVar14 + 0x108) = local_d8;
                uStack215 = (undefined)((uint)uVar1 >> 0x10);
                *(undefined *)(iVar14 + 0x109) = uStack215;
                uStack214 = (undefined)((uint)uVar1 >> 8);
                *(undefined *)(iVar14 + 0x10a) = uStack214;
                uStack213 = (undefined)uVar1;
                *(undefined *)(iVar14 + 0x10b) = uStack213;
                dVar3 = d_menu_dmap::_4523;
                *(float *)(pdVar10 + 0x14d8) =
                     (float)((double)CONCAT44(0x43300000,(int)DAT_803e604e ^ 0x80000000) -
                            d_menu_dmap::_4523);
                *(float *)(pdVar10 + 0x14dc) =
                     (float)((double)CONCAT44(0x43300000,(int)DAT_803e6050 ^ 0x80000000) - dVar3);
                fVar2 = d_menu_dmap::_4521;
                *(float *)(pdVar10 + 0x14d0) =
                     ((float)((double)CONCAT44(0x43300000,
                                               (int)*(short *)(this + 0x1e1e) ^ 0x80000000) - dVar3)
                     + (float)((double)(float)((double)(float)piVar15[3] - in_f31) / in_f29)) -
                     *(float *)(pdVar10 + 0x14d8) * d_menu_dmap::_4521;
                *(float *)(pdVar10 + 0x14d4) =
                     (((float)((double)CONCAT44(0x43300000,
                                                (int)*(short *)(this + 0x1e20) ^ 0x80000000) - dVar3
                              ) +
                      (float)((double)(float)((double)(float)piVar15[5] - in_f30) / in_f29)) -
                     *(float *)(pdVar10 + 0x14dc) * fVar2) -
                     (float)((double)CONCAT44(0x43300000,
                                              (int)*(short *)(this + 0x1e24) +
                                              (int)*(short *)(this + 0x1e26) ^ 0x80000000) - dVar3);
                iVar4 = iVar4 + 0x18;
              }
            }
          }
          piVar15 = piVar15 + 8;
        }
      }
    }
    iVar4 = d_stage::dStage_GetKeepDoorInfo();
    if (iVar4 != 0) {
      iVar16 = 0;
      piVar5 = (int *)d_stage::dStage_GetKeepDoorInfo();
      piVar15 = piVar5 + 1;
      iVar4 = uVar11 * 4;
      for (iVar14 = 0; iVar14 < *piVar5; iVar14 = iVar14 + 1) {
        dVar12 = (dMenu_Dmap_c)d_map::dMap_GetFloorNo((double)(float)piVar15[4],0x803c9d58);
        if (this[0x1e2f] == dVar12) {
          iVar9 = dSv_memBit_c::isDungeonItem
                            ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,0);
          if (((iVar9 != 0) ||
              (iVar9 = dSv_memBit_c::isVisitedRoom
                                 ((dSv_memBit_c *)
                                  &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,
                                  (int)*(short *)(piVar15 + 6) & 0x3f), iVar9 != 0)) ||
             (iVar9 = dSv_memBit_c::isVisitedRoom
                                ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory
                                 ,(uint)(int)*(short *)(piVar15 + 6) >> 6 & 0x3f), iVar9 != 0)) {
            pdVar10 = this + iVar16;
            pdVar10[0x17e2] = (dMenu_Dmap_c)0x1;
            uVar1 = DAT_803e606c;
            iVar9 = *(int *)(pdVar10 + 0x17cc);
            local_dc = (undefined)((uint)DAT_803e606c >> 0x18);
            *(undefined *)(iVar9 + 0x104) = local_dc;
            uStack219 = (undefined)((uint)uVar1 >> 0x10);
            *(undefined *)(iVar9 + 0x105) = uStack219;
            uStack218 = (undefined)((uint)uVar1 >> 8);
            *(undefined *)(iVar9 + 0x106) = uStack218;
            uStack217 = (undefined)uVar1;
            *(undefined *)(iVar9 + 0x107) = uStack217;
            uVar1 = DAT_803e6070;
            iVar9 = *(int *)(pdVar10 + 0x17cc);
            local_e0 = (undefined)((uint)DAT_803e6070 >> 0x18);
            *(undefined *)(iVar9 + 0x108) = local_e0;
            uStack223 = (undefined)((uint)uVar1 >> 0x10);
            *(undefined *)(iVar9 + 0x109) = uStack223;
            uStack222 = (undefined)((uint)uVar1 >> 8);
            *(undefined *)(iVar9 + 0x10a) = uStack222;
            uStack221 = (undefined)uVar1;
            *(undefined *)(iVar9 + 0x10b) = uStack221;
            dVar3 = d_menu_dmap::_4523;
            *(float *)(pdVar10 + 0x17d8) =
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e6068 ^ 0x80000000) -
                        d_menu_dmap::_4523);
            *(float *)(pdVar10 + 0x17dc) =
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e606a ^ 0x80000000) - dVar3);
            *(undefined2 *)(pdVar10 + 0x17e0) = *(undefined2 *)((int)piVar15 + 0x1a);
            fVar2 = d_menu_dmap::_4521;
            *(float *)(pdVar10 + 0x17d0) =
                 ((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e1e) ^ 0x80000000) -
                         dVar3) +
                 (float)((double)(float)((double)(float)piVar15[3] - in_f31) / in_f29)) -
                 *(float *)(pdVar10 + 0x17d8) * d_menu_dmap::_4521;
            *(float *)(pdVar10 + 0x17d4) =
                 ((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e20) ^ 0x80000000) -
                         dVar3) +
                 (float)((double)(float)((double)(float)piVar15[5] - in_f30) / in_f29)) -
                 *(float *)(pdVar10 + 0x17dc) * fVar2;
            iVar16 = iVar16 + 0x18;
          }
        }
        else {
          if ((this[0x1e35] == (dMenu_Dmap_c)0x0) &&
             (uVar11 = d_map::dMap_GetFloorNo((double)(float)piVar15[4],0x803c9d58),
             (byte)this[0x1e2f] - 1 == (uVar11 & 0xff))) {
            iVar9 = dSv_memBit_c::isDungeonItem
                              ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,0
                              );
            if (iVar9 != 0) {
              pdVar10 = this + iVar16;
              pdVar10[0x17e2] = (dMenu_Dmap_c)0x1;
              uVar1 = DAT_803e606c;
              iVar9 = *(int *)(pdVar10 + 0x17cc);
              local_e4 = (undefined)((uint)DAT_803e606c >> 0x18);
              *(undefined *)(iVar9 + 0x104) = local_e4;
              uStack227 = (undefined)((uint)uVar1 >> 0x10);
              *(undefined *)(iVar9 + 0x105) = uStack227;
              uStack226 = (undefined)((uint)uVar1 >> 8);
              *(undefined *)(iVar9 + 0x106) = uStack226;
              uStack225 = (undefined)uVar1;
              *(undefined *)(iVar9 + 0x107) = uStack225;
              uVar1 = DAT_803e6070;
              iVar9 = *(int *)(pdVar10 + 0x17cc);
              local_e8 = (undefined)((uint)DAT_803e6070 >> 0x18);
              *(undefined *)(iVar9 + 0x108) = local_e8;
              uStack231 = (undefined)((uint)uVar1 >> 0x10);
              *(undefined *)(iVar9 + 0x109) = uStack231;
              uStack230 = (undefined)((uint)uVar1 >> 8);
              *(undefined *)(iVar9 + 0x10a) = uStack230;
              uStack229 = (undefined)uVar1;
              *(undefined *)(iVar9 + 0x10b) = uStack229;
              dVar3 = d_menu_dmap::_4523;
              *(float *)(pdVar10 + 0x17d8) =
                   (float)((double)CONCAT44(0x43300000,(int)DAT_803e6068 ^ 0x80000000) -
                          d_menu_dmap::_4523);
              *(float *)(pdVar10 + 0x17dc) =
                   (float)((double)CONCAT44(0x43300000,(int)DAT_803e606a ^ 0x80000000) - dVar3);
              *(undefined2 *)(pdVar10 + 0x17e0) = *(undefined2 *)((int)piVar15 + 0x1a);
              fVar2 = d_menu_dmap::_4521;
              *(float *)(pdVar10 + 0x17d0) =
                   ((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e1e) ^ 0x80000000)
                           - dVar3) +
                   (float)((double)(float)((double)(float)piVar15[3] - in_f31) / in_f29)) -
                   *(float *)(pdVar10 + 0x17d8) * d_menu_dmap::_4521;
              *(float *)(pdVar10 + 0x17d4) =
                   (((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e20) ^ 0x80000000
                                             ) - dVar3) +
                    (float)((double)(float)((double)(float)piVar15[5] - in_f30) / in_f29)) -
                   *(float *)(pdVar10 + 0x17dc) * fVar2) +
                   (float)((double)CONCAT44(0x43300000,
                                            (int)*(short *)(this + 0x1e24) +
                                            (int)*(short *)(this + 0x1e26) ^ 0x80000000) - dVar3);
              iVar16 = iVar16 + 0x18;
            }
          }
          else {
            if (((this[0x1e35] == (dMenu_Dmap_c)0x0) &&
                (uVar11 = d_map::dMap_GetFloorNo((double)(float)piVar15[4],0x803c9d58),
                (byte)this[0x1e2f] + 1 == (uVar11 & 0xff))) &&
               (iVar9 = dSv_memBit_c::isDungeonItem
                                  ((dSv_memBit_c *)
                                   &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,0),
               iVar9 != 0)) {
              pdVar10 = this + iVar16;
              pdVar10[0x17e2] = (dMenu_Dmap_c)0x1;
              uVar1 = DAT_803e606c;
              iVar9 = *(int *)(pdVar10 + 0x17cc);
              local_ec = (undefined)((uint)DAT_803e606c >> 0x18);
              *(undefined *)(iVar9 + 0x104) = local_ec;
              uStack235 = (undefined)((uint)uVar1 >> 0x10);
              *(undefined *)(iVar9 + 0x105) = uStack235;
              uStack234 = (undefined)((uint)uVar1 >> 8);
              *(undefined *)(iVar9 + 0x106) = uStack234;
              uStack233 = (undefined)uVar1;
              *(undefined *)(iVar9 + 0x107) = uStack233;
              uVar1 = DAT_803e6070;
              iVar9 = *(int *)(pdVar10 + 0x17cc);
              local_f0 = (undefined)((uint)DAT_803e6070 >> 0x18);
              *(undefined *)(iVar9 + 0x108) = local_f0;
              uStack239 = (undefined)((uint)uVar1 >> 0x10);
              *(undefined *)(iVar9 + 0x109) = uStack239;
              uStack238 = (undefined)((uint)uVar1 >> 8);
              *(undefined *)(iVar9 + 0x10a) = uStack238;
              uStack237 = (undefined)uVar1;
              *(undefined *)(iVar9 + 0x10b) = uStack237;
              dVar3 = d_menu_dmap::_4523;
              *(float *)(pdVar10 + 0x17d8) =
                   (float)((double)CONCAT44(0x43300000,(int)DAT_803e6068 ^ 0x80000000) -
                          d_menu_dmap::_4523);
              *(float *)(pdVar10 + 0x17dc) =
                   (float)((double)CONCAT44(0x43300000,(int)DAT_803e606a ^ 0x80000000) - dVar3);
              *(undefined2 *)(pdVar10 + 0x17e0) = *(undefined2 *)((int)piVar15 + 0x1a);
              fVar2 = d_menu_dmap::_4521;
              *(float *)(pdVar10 + 0x17d0) =
                   ((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e1e) ^ 0x80000000)
                           - dVar3) +
                   (float)((double)(float)((double)(float)piVar15[3] - in_f31) / in_f29)) -
                   *(float *)(pdVar10 + 0x17d8) * d_menu_dmap::_4521;
              *(float *)(pdVar10 + 0x17d4) =
                   (((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e20) ^ 0x80000000
                                             ) - dVar3) +
                    (float)((double)(float)((double)(float)piVar15[5] - in_f30) / in_f29)) -
                   *(float *)(pdVar10 + 0x17dc) * fVar2) -
                   (float)((double)CONCAT44(0x43300000,
                                            (int)*(short *)(this + 0x1e24) +
                                            (int)*(short *)(this + 0x1e26) ^ 0x80000000) - dVar3);
              iVar16 = iVar16 + 0x18;
            }
          }
        }
        iVar9 = dSv_memBit_c::isDungeonItem
                          ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,1);
        if ((iVar9 != 0) && (iVar9 = d_menu_dmap::dMap_isBossDoor(piVar15), iVar9 != 0)) {
          dVar12 = (dMenu_Dmap_c)d_map::dMap_GetFloorNo((double)(float)piVar15[4],0x803c9d58);
          if (this[0x1e2f] == dVar12) {
            this[0x1afa] = (dMenu_Dmap_c)0x1;
            uVar1 = DAT_803e6060;
            iVar9 = *(int *)(this + 0x1ae4);
            local_f4 = (undefined)((uint)DAT_803e6060 >> 0x18);
            *(undefined *)(iVar9 + 0x104) = local_f4;
            uStack243 = (undefined)((uint)uVar1 >> 0x10);
            *(undefined *)(iVar9 + 0x105) = uStack243;
            uStack242 = (undefined)((uint)uVar1 >> 8);
            *(undefined *)(iVar9 + 0x106) = uStack242;
            uStack241 = (undefined)uVar1;
            *(undefined *)(iVar9 + 0x107) = uStack241;
            uVar1 = DAT_803e6064;
            iVar9 = *(int *)(this + 0x1ae4);
            local_f8 = (undefined)((uint)DAT_803e6064 >> 0x18);
            *(undefined *)(iVar9 + 0x108) = local_f8;
            uStack247 = (undefined)((uint)uVar1 >> 0x10);
            *(undefined *)(iVar9 + 0x109) = uStack247;
            uStack246 = (undefined)((uint)uVar1 >> 8);
            *(undefined *)(iVar9 + 0x10a) = uStack246;
            uStack245 = (undefined)uVar1;
            *(undefined *)(iVar9 + 0x10b) = uStack245;
            dVar3 = d_menu_dmap::_4523;
            *(float *)(this + 0x1af0) =
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e605c ^ 0x80000000) -
                        d_menu_dmap::_4523);
            *(float *)(this + 0x1af4) =
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e605e ^ 0x80000000) - dVar3);
            fVar2 = d_menu_dmap::_4521;
            *(float *)(this + 0x1ae8) =
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e604a ^ 0x80000000) - dVar3) +
                 (((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e1e) ^ 0x80000000)
                          - dVar3) +
                  (float)((double)(float)((double)(float)piVar15[3] - in_f31) / in_f29)) -
                 *(float *)(this + 0x1af0) * d_menu_dmap::_4521) +
                 *(float *)(&d_menu_dmap::bossOffsetX_4530 + iVar4);
            *(float *)(this + 0x1aec) =
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e604c ^ 0x80000000) - dVar3) +
                 (((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e20) ^ 0x80000000)
                          - dVar3) +
                  (float)((double)(float)((double)(float)piVar15[5] - in_f30) / in_f29)) -
                 *(float *)(this + 0x1af4) * fVar2) +
                 *(float *)(&d_menu_dmap::bossOffsetY_4531 + iVar4);
          }
          else {
            if ((this[0x1e35] == (dMenu_Dmap_c)0x0) &&
               (uVar11 = d_map::dMap_GetFloorNo((double)(float)piVar15[4],0x803c9d58),
               (byte)this[0x1e2f] - 1 == (uVar11 & 0xff))) {
              this[0x1afa] = (dMenu_Dmap_c)0x1;
              uVar1 = DAT_803e6060;
              iVar9 = *(int *)(this + 0x1ae4);
              local_fc = (undefined)((uint)DAT_803e6060 >> 0x18);
              *(undefined *)(iVar9 + 0x104) = local_fc;
              uStack251 = (undefined)((uint)uVar1 >> 0x10);
              *(undefined *)(iVar9 + 0x105) = uStack251;
              uStack250 = (undefined)((uint)uVar1 >> 8);
              *(undefined *)(iVar9 + 0x106) = uStack250;
              uStack249 = (undefined)uVar1;
              *(undefined *)(iVar9 + 0x107) = uStack249;
              uVar1 = DAT_803e6064;
              iVar9 = *(int *)(this + 0x1ae4);
              local_100 = (undefined)((uint)DAT_803e6064 >> 0x18);
              *(undefined *)(iVar9 + 0x108) = local_100;
              uStack255 = (undefined)((uint)uVar1 >> 0x10);
              *(undefined *)(iVar9 + 0x109) = uStack255;
              uStack254 = (undefined)((uint)uVar1 >> 8);
              *(undefined *)(iVar9 + 0x10a) = uStack254;
              uStack253 = (undefined)uVar1;
              *(undefined *)(iVar9 + 0x10b) = uStack253;
              dVar3 = d_menu_dmap::_4523;
              *(float *)(this + 0x1af0) =
                   (float)((double)CONCAT44(0x43300000,(int)DAT_803e605c ^ 0x80000000) -
                          d_menu_dmap::_4523);
              *(float *)(this + 0x1af4) =
                   (float)((double)CONCAT44(0x43300000,(int)DAT_803e605e ^ 0x80000000) - dVar3);
              fVar2 = d_menu_dmap::_4521;
              *(float *)(this + 0x1ae8) =
                   (float)((double)CONCAT44(0x43300000,(int)DAT_803e604a ^ 0x80000000) - dVar3) +
                   (((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e1e) ^ 0x80000000
                                             ) - dVar3) +
                    (float)((double)(float)((double)(float)piVar15[3] - in_f31) / in_f29)) -
                   *(float *)(this + 0x1af0) * d_menu_dmap::_4521) +
                   *(float *)(&d_menu_dmap::bossOffsetX_4530 + iVar4);
              *(float *)(this + 0x1aec) =
                   (float)((double)CONCAT44(0x43300000,(int)DAT_803e604c ^ 0x80000000) - dVar3) +
                   *(float *)(&d_menu_dmap::bossOffsetY_4531 + iVar4) +
                   (((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e20) ^ 0x80000000
                                             ) - dVar3) +
                    (float)((double)(float)((double)(float)piVar15[5] - in_f30) / in_f29)) -
                   *(float *)(this + 0x1af4) * fVar2) +
                   (float)((double)CONCAT44(0x43300000,
                                            (int)*(short *)(this + 0x1e24) +
                                            (int)*(short *)(this + 0x1e26) ^ 0x80000000) - dVar3);
            }
            else {
              if ((this[0x1e35] == (dMenu_Dmap_c)0x0) &&
                 (uVar11 = d_map::dMap_GetFloorNo((double)(float)piVar15[4],0x803c9d58),
                 (byte)this[0x1e2f] + 1 == (uVar11 & 0xff))) {
                this[0x1afa] = (dMenu_Dmap_c)0x1;
                uVar1 = DAT_803e6060;
                iVar9 = *(int *)(this + 0x1ae4);
                local_104 = (undefined)((uint)DAT_803e6060 >> 0x18);
                *(undefined *)(iVar9 + 0x104) = local_104;
                uStack259 = (undefined)((uint)uVar1 >> 0x10);
                *(undefined *)(iVar9 + 0x105) = uStack259;
                uStack258 = (undefined)((uint)uVar1 >> 8);
                *(undefined *)(iVar9 + 0x106) = uStack258;
                uStack257 = (undefined)uVar1;
                *(undefined *)(iVar9 + 0x107) = uStack257;
                uVar1 = DAT_803e6064;
                iVar9 = *(int *)(this + 0x1ae4);
                local_108 = (undefined)((uint)DAT_803e6064 >> 0x18);
                *(undefined *)(iVar9 + 0x108) = local_108;
                uStack263 = (undefined)((uint)uVar1 >> 0x10);
                *(undefined *)(iVar9 + 0x109) = uStack263;
                uStack262 = (undefined)((uint)uVar1 >> 8);
                *(undefined *)(iVar9 + 0x10a) = uStack262;
                uStack261 = (undefined)uVar1;
                *(undefined *)(iVar9 + 0x10b) = uStack261;
                dVar3 = d_menu_dmap::_4523;
                *(float *)(this + 0x1af0) =
                     (float)((double)CONCAT44(0x43300000,(int)DAT_803e605c ^ 0x80000000) -
                            d_menu_dmap::_4523);
                *(float *)(this + 0x1af4) =
                     (float)((double)CONCAT44(0x43300000,(int)DAT_803e605e ^ 0x80000000) - dVar3);
                fVar2 = d_menu_dmap::_4521;
                *(float *)(this + 0x1ae8) =
                     (float)((double)CONCAT44(0x43300000,(int)DAT_803e604a ^ 0x80000000) - dVar3) +
                     (((float)((double)CONCAT44(0x43300000,
                                                (int)*(short *)(this + 0x1e1e) ^ 0x80000000) - dVar3
                              ) +
                      (float)((double)(float)((double)(float)piVar15[3] - in_f31) / in_f29)) -
                     *(float *)(this + 0x1af0) * d_menu_dmap::_4521) +
                     *(float *)(&d_menu_dmap::bossOffsetX_4530 + iVar4);
                *(float *)(this + 0x1aec) =
                     (float)((double)CONCAT44(0x43300000,(int)DAT_803e604c ^ 0x80000000) - dVar3) +
                     *(float *)(&d_menu_dmap::bossOffsetY_4531 + iVar4) +
                     ((((float)((double)CONCAT44(0x43300000,
                                                 (int)*(short *)(this + 0x1e20) ^ 0x80000000) -
                               dVar3) +
                       (float)((double)(float)((double)(float)piVar15[5] - in_f30) / in_f29)) -
                      *(float *)(this + 0x1af4) * fVar2) -
                     (float)((double)CONCAT44(0x43300000,
                                              (int)*(short *)(this + 0x1e24) +
                                              (int)*(short *)(this + 0x1e26) ^ 0x80000000) - dVar3))
                ;
              }
            }
          }
        }
        piVar15 = piVar15 + 9;
      }
    }
  }
  __psq_l0(auStack8,uVar17);
  __psq_l1(auStack8,uVar17);
  __psq_l0(auStack24,uVar17);
  __psq_l1(auStack24,uVar17);
  __psq_l0(auStack40,uVar17);
  __psq_l1(auStack40,uVar17);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801ab1e4) */
/* WARNING: Removing unreachable block (ram,0x801ab1ec) */
/* __thiscall dMenu_Dmap_c::treasureDraw(void) */

void __thiscall dMenu_Dmap_c::treasureDraw(dMenu_Dmap_c *this)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  dMenu_Dmap_c *pdVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar9 = (double)(float)((double)CONCAT44(0x43300000,
                                           (int)*(short *)(this + 0x1e10) -
                                           ((int)*(short *)(this + 0x1e20) +
                                           ((byte)this[0x1e2f] - 0x80) *
                                           ((int)*(short *)(this + 0x1e24) +
                                           (int)*(short *)(this + 0x1e26))) ^ 0x80000000) -
                         d_menu_dmap::_4523);
  dVar8 = (double)(float)(dVar9 + (double)(float)((double)CONCAT44(0x43300000,
                                                                   (int)*(short *)(this + 0x1e0e) ^
                                                                   0x80000000) - d_menu_dmap::_4523)
                         );
  iVar4 = 0;
  iVar6 = 0;
  do {
    pdVar5 = this + iVar6;
    if (pdVar5[0x14e2] != (dMenu_Dmap_c)0x0) {
      fVar1 = (float)((double)*(float *)(pdVar5 + 0x14d4) + dVar9);
      fVar2 = (float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e24) ^ 0x80000000) -
                     d_menu_dmap::_4523) * d_menu_dmap::_4521;
      if (((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e20) ^ 0x80000000U) -
                  d_menu_dmap::_4523) - fVar2 < fVar1) &&
         (fVar1 < (float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e20) ^ 0x80000000U)
                         - d_menu_dmap::_4523) + fVar2)) {
        J2DPicture::draw(*(J2DPicture **)(pdVar5 + 0x14cc),*(float *)(pdVar5 + 0x14d0),
                         (float)((double)*(float *)(pdVar5 + 0x14d4) + dVar8),
                         *(float *)(pdVar5 + 0x14d8),*(float *)(pdVar5 + 0x14dc),false,false,false);
        *(dMenu_Dmap_c *)(*(int *)(pdVar5 + 0x14cc) + 0xac) = this[0x1429];
      }
    }
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 0x18;
  } while (iVar4 < 0x20);
  iVar4 = 0;
  iVar6 = 0;
  do {
    pdVar5 = this + iVar6;
    if (pdVar5[0x17e2] != (dMenu_Dmap_c)0x0) {
      fVar1 = (float)((double)*(float *)(pdVar5 + 0x17d4) + dVar9);
      fVar2 = (float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e24) ^ 0x80000000) -
                     d_menu_dmap::_4523) * d_menu_dmap::_4521;
      if (((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e20) ^ 0x80000000U) -
                  d_menu_dmap::_4523) - fVar2 < fVar1) &&
         (fVar1 < (float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e20) ^ 0x80000000U)
                         - d_menu_dmap::_4523) + fVar2)) {
        J2DPicture::draw(*(J2DPicture **)(pdVar5 + 0x17cc),*(float *)(pdVar5 + 0x17d0),
                         (float)((double)*(float *)(pdVar5 + 0x17d4) + dVar8),
                         *(float *)(pdVar5 + 0x17d8),*(float *)(pdVar5 + 0x17dc),false,false,false);
        fVar1 = d_menu_dmap::_5038 *
                (float)((double)CONCAT44(0x43300000,(int)*(short *)(pdVar5 + 0x17e0) ^ 0x80000000) -
                       d_menu_dmap::_4523);
        fVar2 = *(float *)(pdVar5 + 0x17dc) * d_menu_dmap::_4521;
        piVar3 = *(int **)(pdVar5 + 0x17cc);
        piVar3[0x27] = (int)(*(float *)(pdVar5 + 0x17d8) * d_menu_dmap::_4521);
        piVar3[0x28] = (int)fVar2;
        *(undefined *)(piVar3 + 0x2a) = 0x7a;
        piVar3[0x29] = (int)fVar1;
        (**(code **)(*piVar3 + 0x20))();
        *(dMenu_Dmap_c *)(*(int *)(pdVar5 + 0x17cc) + 0xac) = this[0x1429];
      }
    }
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 0x18;
  } while (iVar4 < 0x20);
  if (this[0x1ae2] != (dMenu_Dmap_c)0x0) {
    fVar1 = (float)((double)*(float *)(this + 0x1ad4) + dVar9);
    fVar2 = (float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e24) ^ 0x80000000) -
                   d_menu_dmap::_4523) * d_menu_dmap::_4521;
    if (((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e20) ^ 0x80000000U) -
                d_menu_dmap::_4523) - fVar2 < fVar1) &&
       (fVar1 < (float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e20) ^ 0x80000000U) -
                       d_menu_dmap::_4523) + fVar2)) {
      J2DPicture::draw(*(J2DPicture **)(this + 0x1acc),*(float *)(this + 0x1ad0),
                       (float)((double)*(float *)(this + 0x1ad4) + dVar8),*(float *)(this + 0x1ad8),
                       *(float *)(this + 0x1adc),false,false,false);
      *(dMenu_Dmap_c *)(*(int *)(this + 0x1acc) + 0xac) = this[0x1429];
    }
  }
  if (this[0x1afa] != (dMenu_Dmap_c)0x0) {
    fVar1 = (float)((double)*(float *)(this + 0x1aec) + dVar9);
    fVar2 = (float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e24) ^ 0x80000000) -
                   d_menu_dmap::_4523) * d_menu_dmap::_4521;
    if (((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e20) ^ 0x80000000U) -
                d_menu_dmap::_4523) - fVar2 < fVar1) &&
       (fVar1 < (float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e20) ^ 0x80000000U) -
                       d_menu_dmap::_4523) + fVar2)) {
      J2DPicture::draw(*(J2DPicture **)(this + 0x1ae4),*(float *)(this + 0x1ae8),
                       (float)((double)*(float *)(this + 0x1aec) + dVar8),*(float *)(this + 0x1af0),
                       *(float *)(this + 0x1af4),false,false,false);
      *(dMenu_Dmap_c *)(*(int *)(this + 0x1ae4) + 0xac) = this[0x1429];
    }
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801ab444) */
/* __thiscall dMenu_Dmap_c::paneMove(float) */

void __thiscall dMenu_Dmap_c::paneMove(dMenu_Dmap_c *this,float param_1)

{
  int iVar1;
  dMenu_Dmap_c *pdVar2;
  int iVar3;
  undefined4 uVar4;
  double y;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  y = (double)param_1;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x9e4),(double)d_menu_dmap::_4382,y)
  ;
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0xa1c),(double)d_menu_dmap::_4382,y)
  ;
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x77c),(double)d_menu_dmap::_4382,y)
  ;
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x7b4),(double)d_menu_dmap::_4382,y)
  ;
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x824),(double)d_menu_dmap::_4382,y)
  ;
  iVar1 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + iVar3 + 0x69c),(double)d_menu_dmap::_4382,y);
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 4);
  iVar1 = 0;
  iVar3 = 0;
  do {
    pdVar2 = this + iVar3;
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(pdVar2 + 0xa54),(double)d_menu_dmap::_4382,y);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(pdVar2 + 0xafc),(double)d_menu_dmap::_4382,y);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(pdVar2 + 0xba4),(double)d_menu_dmap::_4382,y);
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 3);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0xc4c),(double)d_menu_dmap::_4382,y)
  ;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xc84),(double)d_menu_dmap::_4382,
             (double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                              (int)*(short *)(this + 0x1e12) ^
                                                              0x80000000) - d_menu_dmap::_4523) + y)
            );
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xd9c),(double)d_menu_dmap::_4382,
             (double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                              (int)*(short *)(this + 0x1e14) ^
                                                              0x80000000) - d_menu_dmap::_4523) + y)
            );
  iVar1 = 0;
  iVar3 = 0;
  do {
    pdVar2 = this + iVar3;
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(pdVar2 + 0xe7c),(double)d_menu_dmap::_4382,y);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(pdVar2 + 0xfcc),(double)d_menu_dmap::_4382,y);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(pdVar2 + 0x111c),(double)d_menu_dmap::_4382,y);
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 6);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x126c),(double)d_menu_dmap::_4382,y);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x12a4),(double)d_menu_dmap::_4382,y);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x12dc),(double)d_menu_dmap::_4382,y);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x1314),(double)d_menu_dmap::_4382,y);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x134c),(double)d_menu_dmap::_4382,y);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x1384),(double)d_menu_dmap::_4382,y);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x13bc),(double)d_menu_dmap::_4382,y);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x13f4),(double)d_menu_dmap::_4382,y);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x142c),(double)d_menu_dmap::_4382,y);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_Dmap_c::paneAlpha(float) */

void __thiscall dMenu_Dmap_c::paneAlpha(dMenu_Dmap_c *this,float param_1)

{
  int iVar1;
  dMenu_Dmap_c *pdVar2;
  int iVar3;
  double dVar4;
  
  dVar4 = (double)param_1;
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x9ac),param_1);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x9e4),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xa1c),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x7ec),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x824),(float)dVar4);
  iVar1 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x69c),(float)dVar4);
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 4);
  iVar1 = 0;
  iVar3 = 0;
  do {
    pdVar2 = this + iVar3;
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0xa54),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0xafc),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0xba4),(float)dVar4);
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xc4c),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xc84),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xd9c),(float)dVar4);
  iVar3 = 0;
  for (iVar1 = 0; iVar1 < (int)(((uint)(byte)this[0x1e31] - (uint)(byte)this[0x1e32]) + 1);
      iVar1 = iVar1 + 1) {
    pdVar2 = this + iVar3;
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0xe7c),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0xfcc),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0x111c),(float)dVar4);
    iVar3 = iVar3 + 0x38;
  }
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x126c),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x12a4),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x12dc),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1314),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x134c),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1384),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x13bc),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x13f4),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x142c),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1464),(float)dVar4);
  return;
}


/* __thiscall dMenu_Dmap_c::decAlpha(float) */

void __thiscall dMenu_Dmap_c::decAlpha(dMenu_Dmap_c *this,float param_1)

{
  double dVar1;
  double dVar2;
  int iVar3;
  dMenu_Dmap_c *pdVar4;
  int iVar5;
  double local_d8;
  double local_d0;
  double local_a8;
  double local_a0;
  double local_98;
  double local_90;
  double local_88;
  double local_80;
  double local_78;
  double local_70;
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  dVar1 = d_menu_dmap::_5151;
  iVar3 = 0;
  iVar5 = 0xf;
  do {
    local_d8 = (double)CONCAT44(0x43300000,(uint)(byte)this[iVar3 + 0x41]);
    this[iVar3 + 0x41] = SUB41((int)((float)(local_d8 - dVar1) * param_1),0);
    dVar2 = d_menu_dmap::_5151;
    iVar3 = iVar3 + 0x38;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar3 = 0;
  iVar5 = 4;
  do {
    local_d0 = (double)CONCAT44(0x43300000,(uint)(byte)this[iVar3 + 0x6d1]);
    this[iVar3 + 0x6d1] = SUB41((int)((float)(local_d0 - dVar2) * param_1),0);
    dVar1 = d_menu_dmap::_5151;
    iVar3 = iVar3 + 0x38;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  local_d0 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x7b1]);
  this[0x7b1] = SUB41((int)((float)(local_d0 - d_menu_dmap::_5151) * param_1),0);
  this[0x7e9] = SUB41((int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x7e9]) - dVar1) *
                           param_1),0);
  this[0x821] = SUB41((int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x821]) - dVar1) *
                           param_1),0);
  local_a8 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x859]);
  this[0x859] = SUB41((int)((float)(local_a8 - dVar1) * param_1),0);
  local_98 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x891]);
  this[0x891] = SUB41((int)((float)(local_98 - dVar1) * param_1),0);
  local_88 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x8c9]);
  this[0x8c9] = SUB41((int)((float)(local_88 - dVar1) * param_1),0);
  local_78 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x901]);
  this[0x901] = SUB41((int)((float)(local_78 - dVar1) * param_1),0);
  local_68 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x939]);
  this[0x939] = SUB41((int)((float)(local_68 - dVar1) * param_1),0);
  local_58 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x971]);
  this[0x971] = SUB41((int)((float)(local_58 - dVar1) * param_1),0);
  local_48 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x9a9]);
  this[0x9a9] = SUB41((int)((float)(local_48 - dVar1) * param_1),0);
  local_38 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x9e1]);
  this[0x9e1] = SUB41((int)((float)(local_38 - dVar1) * param_1),0);
  local_28 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xa19]);
  this[0xa19] = SUB41((int)((float)(local_28 - dVar1) * param_1),0);
  local_18 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xa51]);
  this[0xa51] = SUB41((int)((float)(local_18 - dVar1) * param_1),0);
  iVar3 = 0;
  iVar5 = 3;
  do {
    pdVar4 = this + iVar3;
    local_10 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0xa89]);
    pdVar4[0xa89] = SUB41((int)((float)(local_10 - dVar1) * param_1),0);
    local_20 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0xb31]);
    pdVar4[0xb31] = SUB41((int)((float)(local_20 - dVar1) * param_1),0);
    local_30 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0xbd9]);
    pdVar4[0xbd9] = SUB41((int)((float)(local_30 - dVar1) * param_1),0);
    dVar2 = d_menu_dmap::_5151;
    iVar3 = iVar3 + 0x38;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  local_10 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xc81]);
  this[0xc81] = SUB41((int)((float)(local_10 - d_menu_dmap::_5151) * param_1),0);
  local_20 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xcb9]);
  this[0xcb9] = SUB41((int)((float)(local_20 - dVar2) * param_1),0);
  local_30 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xd61]);
  this[0xd61] = SUB41((int)((float)(local_30 - dVar2) * param_1),0);
  local_40 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xd99]);
  this[0xd99] = SUB41((int)((float)(local_40 - dVar2) * param_1),0);
  local_50 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xdd1]);
  this[0xdd1] = SUB41((int)((float)(local_50 - dVar2) * param_1),0);
  iVar3 = 0;
  iVar5 = 6;
  do {
    pdVar4 = this + iVar3;
    local_10 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0xeb1]);
    pdVar4[0xeb1] = SUB41((int)((float)(local_10 - dVar2) * param_1),0);
    local_20 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x1001]);
    pdVar4[0x1001] = SUB41((int)((float)(local_20 - dVar2) * param_1),0);
    local_30 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x1151]);
    pdVar4[0x1151] = SUB41((int)((float)(local_30 - dVar2) * param_1),0);
    dVar1 = d_menu_dmap::_5151;
    iVar3 = iVar3 + 0x38;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  local_10 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x12a1]);
  this[0x12a1] = SUB41((int)((float)(local_10 - d_menu_dmap::_5151) * param_1),0);
  local_20 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x12d9]);
  this[0x12d9] = SUB41((int)((float)(local_20 - dVar1) * param_1),0);
  local_30 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1311]);
  this[0x1311] = SUB41((int)((float)(local_30 - dVar1) * param_1),0);
  local_40 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1349]);
  this[0x1349] = SUB41((int)((float)(local_40 - dVar1) * param_1),0);
  local_50 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1381]);
  this[0x1381] = SUB41((int)((float)(local_50 - dVar1) * param_1),0);
  local_60 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x13b9]);
  this[0x13b9] = SUB41((int)((float)(local_60 - dVar1) * param_1),0);
  local_70 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x13f1]);
  this[0x13f1] = SUB41((int)((float)(local_70 - dVar1) * param_1),0);
  local_80 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1429]);
  this[0x1429] = SUB41((int)((float)(local_80 - dVar1) * param_1),0);
  local_90 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1461]);
  this[0x1461] = SUB41((int)((float)(local_90 - dVar1) * param_1),0);
  local_a0 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1499]);
  this[0x1499] = SUB41((int)((float)(local_a0 - dVar1) * param_1),0);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_Dmap_c::cursorMove(void) */

void __thiscall dMenu_Dmap_c::cursorMove(dMenu_Dmap_c *this)

{
  dMenu_Dmap_c dVar1;
  dMenu_Dmap_c dVar2;
  dMenu_Dmap_c dVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  
  dVar1 = this[0x1e2e];
  dVar2 = this[0x1e2f];
  STControl::checkTrigger(*(STControl **)(this + 0x149c));
  cVar4 = STControl::checkLeftTrigger(*(STControl **)(this + 0x149c));
  if (cVar4 == '\0') {
    cVar4 = STControl::checkRightTrigger(*(STControl **)(this + 0x149c));
    if (cVar4 == '\0') {
      cVar4 = STControl::checkUpTrigger(*(STControl **)(this + 0x149c));
      if (cVar4 == '\0') {
        cVar4 = STControl::checkDownTrigger(*(STControl **)(this + 0x149c));
        if ((cVar4 != '\0') && (this[0x1e2e] == (dMenu_Dmap_c)0x3)) {
          if ((byte)this[0x1e32] < (byte)this[0x1e2f]) {
            this[0x1e2f] = (dMenu_Dmap_c)((char)this[0x1e2f] - 1);
            *(undefined2 *)(this + 0x1312) = 0xfffa;
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x80e,(cXyz *)0x0,0,0,d_menu_dmap::_5258,
                       d_menu_dmap::_5258,d_menu_dmap::_5259,d_menu_dmap::_5259,0);
          }
          else {
            this[0x1e2e] = (dMenu_Dmap_c)0x1;
            *(undefined2 *)(this + 0x1312) = 0xfffa;
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x80e,(cXyz *)0x0,0,0,d_menu_dmap::_5258,
                       d_menu_dmap::_5258,d_menu_dmap::_5259,d_menu_dmap::_5259,0);
          }
        }
      }
      else {
        if ((byte)this[0x1e2e] < 3) {
          this[0x1e2e] = (dMenu_Dmap_c)0x3;
          *(undefined2 *)(this + 0x1312) = 6;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x80e,(cXyz *)0x0,0,0,d_menu_dmap::_5258,
                     d_menu_dmap::_5258,d_menu_dmap::_5259,d_menu_dmap::_5259,0);
        }
        else {
          if ((byte)this[0x1e2f] < (byte)this[0x1e31]) {
            this[0x1e2f] = (dMenu_Dmap_c)((char)this[0x1e2f] + 1);
            *(undefined2 *)(this + 0x1312) = 6;
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x80e,(cXyz *)0x0,0,0,d_menu_dmap::_5258,
                       d_menu_dmap::_5258,d_menu_dmap::_5259,d_menu_dmap::_5259,0);
          }
        }
      }
    }
    else {
      dVar3 = this[0x1e2e];
      if (((byte)dVar3 < 3) && ((byte)dVar3 < 2)) {
        this[0x1e2e] = (dMenu_Dmap_c)((char)dVar3 + 1);
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x80e,(cXyz *)0x0,0,0,d_menu_dmap::_5258,
                   d_menu_dmap::_5258,d_menu_dmap::_5259,d_menu_dmap::_5259,0);
      }
    }
  }
  else {
    dVar3 = this[0x1e2e];
    if (((byte)dVar3 < 3) && (dVar3 != (dMenu_Dmap_c)0x0)) {
      this[0x1e2e] = (dMenu_Dmap_c)((char)dVar3 - 1);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x80e,(cXyz *)0x0,0,0,d_menu_dmap::_5258,d_menu_dmap::_5258,
                 d_menu_dmap::_5259,d_menu_dmap::_5259,0);
    }
  }
  if ((this[0x1e2e] != dVar1) || (this[0x1e2f] != dVar2)) {
    *(undefined2 *)(this + 0x7b2) = 0;
    itemnameSet(this);
    if ((byte)this[0x1e2e] < 3) {
      iVar6 = 0;
      for (iVar5 = 0; iVar5 < (int)(((uint)(byte)this[0x1e31] - (uint)(byte)this[0x1e32]) + 1);
          iVar5 = iVar5 + 1) {
        f_op_msg_mng::fopMsgM_setInitAlpha(this + iVar6 + 0xfcc);
        iVar6 = iVar6 + 0x38;
      }
    }
    itemScale(this);
    if (this[0x1e2f] != dVar2) {
      treasureSet(this);
    }
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x80e,(cXyz *)0x0,0,0,d_menu_dmap::_5258,d_menu_dmap::_5258,
               d_menu_dmap::_5259,d_menu_dmap::_5259,0);
  }
  if ((byte)this[0x1e2e] < 3) {
    if ((((this[0x1e2e] == (dMenu_Dmap_c)0x0) &&
         (iVar5 = dSv_memBit_c::isDungeonItem
                            ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,0),
         iVar5 != 0)) ||
        ((this[0x1e2e] == (dMenu_Dmap_c)0x1 &&
         (iVar5 = dSv_memBit_c::isDungeonItem
                            ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,2),
         iVar5 != 0)))) ||
       ((this[0x1e2e] == (dMenu_Dmap_c)0x2 &&
        (iVar5 = dSv_memBit_c::isDungeonItem
                           ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,1),
        iVar5 != 0)))) {
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x21;
    }
    else {
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
      d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_Dmap_c::cursorAnime(void) */

void __thiscall dMenu_Dmap_c::cursorAnime(dMenu_Dmap_c *this)

{
  int iVar1;
  short unaff_r30;
  int iVar2;
  short unaff_r31;
  
  if (*(short *)(this + 0x6d2) < 10) {
    iVar1 = 0;
    iVar2 = 0;
    do {
      J2DPicture::changeTexture(*(J2DPicture **)(this + iVar2 + 0x69c),"cursor_00_01.bti",0);
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x38;
    } while (iVar1 < 4);
    unaff_r31 = 7;
    unaff_r30 = 7;
    if (this[0x1e2e] == (dMenu_Dmap_c)0x3) {
      f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(this + 0x6d2),0);
    }
  }
  else {
    if (*(short *)(this + 0x6d2) < 0x14) {
      iVar1 = 0;
      iVar2 = 0;
      do {
        J2DPicture::changeTexture(*(J2DPicture **)(this + iVar2 + 0x69c),"cursor_00_02.bti",0);
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + 0x38;
      } while (iVar1 < 4);
      unaff_r31 = 0xe;
      unaff_r30 = 0xe;
      if (this[0x1e2e] == (dMenu_Dmap_c)0x3) {
        f_op_msg_mng::fopMsgM_valueIncrease(10,0x14 - *(short *)(this + 0x6d2),0);
      }
    }
  }
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x69c),
             (double)(float)((double)CONCAT44(0x43300000,-(int)unaff_r31 ^ 0x80000000) -
                            d_menu_dmap::_4523),
             (double)(float)((double)CONCAT44(0x43300000,(int)unaff_r30 ^ 0x80000000) -
                            d_menu_dmap::_4523));
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x6d4),
             (double)(float)((double)CONCAT44(0x43300000,(int)unaff_r31 ^ 0x80000000) -
                            d_menu_dmap::_4523),
             (double)(float)((double)CONCAT44(0x43300000,(int)unaff_r30 ^ 0x80000000) -
                            d_menu_dmap::_4523));
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x70c),
             (double)(float)((double)CONCAT44(0x43300000,-(int)unaff_r31 ^ 0x80000000) -
                            d_menu_dmap::_4523),
             (double)(float)((double)CONCAT44(0x43300000,-(int)unaff_r30 ^ 0x80000000) -
                            d_menu_dmap::_4523));
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x744),
             (double)(float)((double)CONCAT44(0x43300000,(int)unaff_r31 ^ 0x80000000) -
                            d_menu_dmap::_4523),
             (double)(float)((double)CONCAT44(0x43300000,-(int)unaff_r30 ^ 0x80000000) -
                            d_menu_dmap::_4523));
  *(short *)(this + 0x6d2) = *(short *)(this + 0x6d2) + 1;
  if (0x13 < *(short *)(this + 0x6d2)) {
    *(undefined2 *)(this + 0x6d2) = 0;
  }
  return;
}


/* __thiscall dMenu_Dmap_c::noteInit(void) */

void __thiscall dMenu_Dmap_c::noteInit(dMenu_Dmap_c *this)

{
  double dVar1;
  float fVar2;
  int *piVar3;
  
  *(undefined2 *)(this + 0x972) = 0;
  *(undefined2 *)(this + 0x93a) = 0;
  dVar1 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x9aa) ^ 0x80000000) -
          d_menu_dmap::_4523;
  fVar2 = *(float *)(this + 0x99c) * d_menu_dmap::_4521;
  piVar3 = *(int **)(this + 0x974);
  piVar3[0x27] = (int)(*(float *)(this + 0x998) * d_menu_dmap::_4521);
  piVar3[0x28] = (int)fVar2;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)(float)dVar1;
  (**(code **)(*piVar3 + 0x20))();
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x974),(double)d_menu_dmap::_4382,
             (double)d_menu_dmap::_4382);
  return;
}


/* __thiscall dMenu_Dmap_c::noteCheck(void) */

uint __thiscall dMenu_Dmap_c::noteCheck(dMenu_Dmap_c *this)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(1 - *(short *)(this + 0x972));
  return uVar1 >> 5 & 0xff;
}


/* __thiscall dMenu_Dmap_c::noteAppear(void) */

void __thiscall dMenu_Dmap_c::noteAppear(dMenu_Dmap_c *this)

{
  if (*(short *)(this + 0x972) == 1) {
    if (*(short *)(this + 0x93a) < 0x12) {
      noteOpen(this);
    }
    else {
      if (*(short *)(this + 0x93a) < 0x13) {
        if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) != 0) ||
           ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0')) {
          *(short *)(this + 0x93a) = *(short *)(this + 0x93a) + 1;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x816,(cXyz *)0x0,0,0,d_menu_dmap::_5258,
                     d_menu_dmap::_5258,d_menu_dmap::_5259,d_menu_dmap::_5259,0);
        }
      }
      else {
        noteClose(this);
      }
    }
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x801ac56c) */
/* WARNING: Removing unreachable block (ram,0x801ac564) */
/* WARNING: Removing unreachable block (ram,0x801ac574) */
/* __thiscall dMenu_Dmap_c::noteOpen(void) */

void __thiscall dMenu_Dmap_c::noteOpen(dMenu_Dmap_c *this)

{
  double dVar1;
  float fVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f29;
  double dVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
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
  dVar9 = (double)(d_menu_dmap::_5358 - *(float *)(this + 0x988));
  dVar8 = (double)(d_menu_dmap::_5359 - *(float *)(this + 0x98c));
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x11,0x11 - *(short *)(this + 0x93a),0);
  dVar7 = (double)(float)((double)d_menu_dmap::_5258 - dVar6);
  if (*(short *)(this + 0x93a) < 0x11) {
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)(this + 0x85c),(float)((double)d_menu_dmap::_5258 - dVar6));
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x894),(float)dVar7);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x8cc),(float)dVar7);
  }
  else {
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x85c);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x894);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x8cc);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x814,(cXyz *)0x0,0,0,d_menu_dmap::_5258,d_menu_dmap::_5258,
               d_menu_dmap::_5259,d_menu_dmap::_5259,0);
  }
  dVar6 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x9aa) ^ 0x80000000) -
          d_menu_dmap::_4523;
  dVar1 = (double)CONCAT44(0x43300000,-(int)*(short *)(this + 0x9aa) - 3U ^ 0x80000000) -
          d_menu_dmap::_4523;
  fVar2 = *(float *)(this + 0x9a4) * d_menu_dmap::_4521;
  piVar4 = *(int **)(this + 0x974);
  piVar4[0x27] = (int)(*(float *)(this + 0x9a0) * d_menu_dmap::_4521);
  piVar4[0x28] = (int)fVar2;
  *(undefined *)(piVar4 + 0x2a) = 0x7a;
  piVar4[0x29] = (int)((float)dVar6 + (float)(dVar7 * (double)(float)dVar1));
  (**(code **)(*piVar4 + 0x20))();
  uVar3 = SEXT24(*(short *)(this + 0x93a));
  if ((int)uVar3 < 5) {
    fVar2 = (d_menu_dmap::_5360 *
            (float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - d_menu_dmap::_4523)) /
            d_menu_dmap::_5361;
  }
  else {
    dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0xc,0x11 - uVar3,0);
    fVar2 = d_menu_dmap::_5360 + d_menu_dmap::_5362 * (float)((double)d_menu_dmap::_5258 - dVar6);
  }
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x974),(double)(float)(dVar9 * (double)fVar2),
             (double)(float)(dVar8 * (double)fVar2));
  *(short *)(this + 0x93a) = *(short *)(this + 0x93a) + 1;
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801ac7a4) */
/* WARNING: Removing unreachable block (ram,0x801ac794) */
/* WARNING: Removing unreachable block (ram,0x801ac78c) */
/* WARNING: Removing unreachable block (ram,0x801ac79c) */
/* WARNING: Removing unreachable block (ram,0x801ac7ac) */
/* __thiscall dMenu_Dmap_c::noteClose(void) */

void __thiscall dMenu_Dmap_c::noteClose(dMenu_Dmap_c *this)

{
  float fVar1;
  int *piVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f27;
  double dVar5;
  undefined8 in_f28;
  double dVar6;
  undefined8 in_f29;
  double dVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  undefined auStack72 [16];
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
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  dVar8 = (double)((d_menu_dmap::_5387 - *(float *)(this + 0x988)) - d_menu_dmap::_5358);
  dVar7 = (double)((d_menu_dmap::_5388 - *(float *)(this + 0x98c)) - d_menu_dmap::_5359);
  dVar6 = (double)(d_menu_dmap::_5358 - *(float *)(this + 0x988));
  dVar5 = (double)(d_menu_dmap::_5359 - *(float *)(this + 0x98c));
  dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,*(short *)(this + 0x93a) + -0x12,0);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x974),
             (double)(float)(dVar6 + (double)(float)(dVar8 * dVar4)),
             (double)(float)(dVar5 + (double)(float)(dVar7 * dVar4)));
  fVar1 = *(float *)(this + 0x9a4) * d_menu_dmap::_4521;
  piVar2 = *(int **)(this + 0x974);
  piVar2[0x27] = (int)(*(float *)(this + 0x9a0) * d_menu_dmap::_4521);
  piVar2[0x28] = (int)fVar1;
  *(undefined *)(piVar2 + 0x2a) = 0x7a;
  piVar2[0x29] = (int)(d_menu_dmap::_5389 + (float)((double)d_menu_dmap::_5390 * dVar4));
  (**(code **)(*piVar2 + 0x20))();
  *(short *)(this + 0x93a) = *(short *)(this + 0x93a) + 1;
  if (*(short *)(this + 0x93a) < 0x1d) {
    dVar5 = (double)(float)((double)d_menu_dmap::_5258 - dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)(this + 0x904),(float)((double)d_menu_dmap::_5258 - dVar4));
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x93c),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x974),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x85c),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x894),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x8cc),(float)dVar5);
  }
  else {
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x904);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x93c);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x974);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x85c));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x894));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x8cc));
    *(undefined2 *)(this + 0x972) = 0;
    *(undefined2 *)(this + 0x93a) = 0;
    dVar4 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x9aa) ^ 0x80000000) -
            d_menu_dmap::_4523;
    fVar1 = *(float *)(this + 0x9a4) * d_menu_dmap::_4521;
    piVar2 = *(int **)(this + 0x974);
    piVar2[0x27] = (int)(*(float *)(this + 0x9a0) * d_menu_dmap::_4521);
    piVar2[0x28] = (int)fVar1;
    *(undefined *)(piVar2 + 0x2a) = 0x7a;
    piVar2[0x29] = (int)(float)dVar4;
    (**(code **)(*piVar2 + 0x20))();
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x974),(double)d_menu_dmap::_4382,
               (double)d_menu_dmap::_4382);
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  __psq_l0(auStack56,uVar3);
  __psq_l1(auStack56,uVar3);
  __psq_l0(auStack72,uVar3);
  __psq_l1(auStack72,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x801ac8ac) */
/* __thiscall dMenu_Dmap_c::noteOpenProc(short) */

void __thiscall dMenu_Dmap_c::noteOpenProc(dMenu_Dmap_c *this,short param_1)

{
  double dVar1;
  double dVar2;
  short sVar3;
  float fVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar6 = (int)param_1;
  if (iVar6 < 0xb) {
    dVar8 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,iVar6,0);
    sVar3 = *(short *)(this + 0x9aa);
    dVar9 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - iVar6,0);
    dVar1 = (double)CONCAT44(0x43300000,-(int)sVar3 - 0x5aU ^ 0x80000000) - d_menu_dmap::_4523;
    dVar2 = (double)CONCAT44(0x43300000,(int)sVar3 ^ 0x80000000) - d_menu_dmap::_4523;
    fVar4 = *(float *)(this + 0x9a4) * d_menu_dmap::_4521;
    piVar5 = *(int **)(this + 0x974);
    piVar5[0x27] = (int)(*(float *)(this + 0x9a0) * d_menu_dmap::_4521);
    piVar5[0x28] = (int)fVar4;
    *(undefined *)(piVar5 + 0x2a) = 0x7a;
    piVar5[0x29] = (int)((float)dVar2 + (float)((double)(float)dVar1 * dVar9));
    (**(code **)(*piVar5 + 0x20))();
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x904),(float)dVar8);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x93c),(float)dVar8);
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801acdc0) */
/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall dMenu_Dmap_c::itemScale(void) */

void __thiscall dMenu_Dmap_c::itemScale(dMenu_Dmap_c *this)

{
  float fVar1;
  dMenu_Dmap_c dVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  dMenu_Dmap_c *pdVar6;
  int iVar7;
  undefined4 uVar8;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if ((byte)this[0x1e2e] < 3) {
    uVar4 = 0;
    iVar5 = 0;
    do {
      if (uVar4 == (byte)this[0x1e2e]) {
        f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(this + iVar5 + 0xa54),DAT_803e6a74)
        ;
        f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(this + iVar5 + 0xafc),DAT_803e6a74)
        ;
      }
      else {
        f_op_msg_mng::fopMsgM_paneScaleXY
                  ((fopMsgM_pane_class *)(this + iVar5 + 0xa54),d_menu_dmap::_5258);
        f_op_msg_mng::fopMsgM_paneScaleXY
                  ((fopMsgM_pane_class *)(this + iVar5 + 0xafc),d_menu_dmap::_5258);
      }
      uVar4 = uVar4 + 1;
      iVar5 = iVar5 + 0x38;
    } while ((int)uVar4 < 3);
    iVar5 = 0;
    iVar3 = 0;
    iVar7 = 4;
    do {
      *(float *)(this + iVar5 + 0x6b0) =
           *(float *)(this + (uint)(byte)this[0x1e2e] * 0x38 + 0xa68) +
           *(float *)(this + iVar3 + 0x1dcc);
      *(float *)(this + iVar5 + 0x6b4) =
           *(float *)(this + (uint)(byte)this[0x1e2e] * 0x38 + 0xa6c) +
           *(float *)(this + iVar3 + 0x1ddc);
      iVar5 = iVar5 + 0x38;
      iVar3 = iVar3 + 4;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    iVar5 = 0;
    for (iVar3 = 0; iVar3 < (int)(((uint)(byte)this[0x1e31] - (uint)(byte)this[0x1e32]) + 1);
        iVar3 = iVar3 + 1) {
      pdVar6 = this + iVar5;
      *(undefined4 *)(pdVar6 + 0xea8) = *(undefined4 *)(pdVar6 + 0xea0);
      *(undefined4 *)(pdVar6 + 0xeac) = *(undefined4 *)(pdVar6 + 0xea4);
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar6 + 0xe7c));
      *(undefined4 *)(pdVar6 + 0xff8) = *(undefined4 *)(pdVar6 + 0xff0);
      *(undefined4 *)(pdVar6 + 0xffc) = *(undefined4 *)(pdVar6 + 0xff4);
      local_68 = *(undefined4 *)(this + 0x14b8);
      local_64 = local_68;
      local_60 = local_68;
      local_5c = local_68;
      local_38 = local_68;
      J2DWindow::setContentsColor
                (*(J2DWindow **)(pdVar6 + 0xfcc),(TColor)&local_68,(TColor)&local_64,
                 (TColor)&local_60,(TColor)&local_5c);
      local_3c = *(undefined4 *)(this + 0x14c0);
      iVar7 = *(int *)(pdVar6 + 0xfcc);
      local_3c._0_1_ = (undefined)((uint)local_3c >> 0x18);
      *(undefined *)(iVar7 + 0x104) = local_3c._0_1_;
      local_3c._1_1_ = (undefined)((uint)local_3c >> 0x10);
      *(undefined *)(iVar7 + 0x105) = local_3c._1_1_;
      local_3c._2_1_ = (undefined)((uint)local_3c >> 8);
      *(undefined *)(iVar7 + 0x106) = local_3c._2_1_;
      *(undefined *)(iVar7 + 0x107) = (undefined)local_3c;
      local_40 = *(undefined4 *)(this + 0x14c8);
      iVar7 = *(int *)(pdVar6 + 0xfcc);
      local_40._0_1_ = (undefined)((uint)local_40 >> 0x18);
      *(undefined *)(iVar7 + 0x108) = local_40._0_1_;
      local_40._1_1_ = (undefined)((uint)local_40 >> 0x10);
      *(undefined *)(iVar7 + 0x109) = local_40._1_1_;
      local_40._2_1_ = (undefined)((uint)local_40 >> 8);
      *(undefined *)(iVar7 + 0x10a) = local_40._2_1_;
      *(undefined *)(iVar7 + 0x10b) = (undefined)local_40;
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar6 + 0xfcc));
      *(undefined4 *)(pdVar6 + 0x1148) = *(undefined4 *)(pdVar6 + 0x1140);
      *(undefined4 *)(pdVar6 + 0x114c) = *(undefined4 *)(pdVar6 + 0x1144);
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar6 + 0x111c));
      iVar5 = iVar5 + 0x38;
    }
    dVar10 = (double)((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.
                     mCurrent.mPos.y;
    dVar9 = (double)mapOffsetY(this);
    dVar2 = (dMenu_Dmap_c)d_map::dMap_GetFloorNo((double)(float)(dVar10 + dVar9),0x803c9d58);
    this[0x1e2f] = dVar2;
    *(ushort *)(this + 0x1e10) =
         *(short *)(this + 0x1e20) +
         ((byte)this[0x1e2f] - 0x80) * (*(short *)(this + 0x1e24) + *(short *)(this + 0x1e26));
  }
  else {
    iVar5 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_paneScaleXY
                ((fopMsgM_pane_class *)(this + iVar3 + 0xa54),d_menu_dmap::_5258);
      f_op_msg_mng::fopMsgM_paneScaleXY
                ((fopMsgM_pane_class *)(this + iVar3 + 0xafc),d_menu_dmap::_5258);
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar5 < 3);
    iVar5 = 0;
    iVar3 = 0;
    iVar7 = 4;
    do {
      *(float *)(this + iVar5 + 0x6b0) =
           *(float *)(this + ((uint)(byte)this[0x1e2f] - (uint)(byte)this[0x1e32]) * 0x38 + 0xfe8) +
           *(float *)(this + iVar3 + 0x1dec);
      *(float *)(this + iVar5 + 0x6b4) =
           *(float *)(this + ((uint)(byte)this[0x1e2f] - (uint)(byte)this[0x1e32]) * 0x38 + 0xfec) +
           *(float *)(this + iVar3 + 0x1dfc);
      iVar5 = iVar5 + 0x38;
      iVar3 = iVar3 + 4;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    iVar5 = 0;
    for (iVar3 = 0; fVar1 = d_menu_dmap::_5563,
        iVar3 < (int)(((uint)(byte)this[0x1e31] - (uint)(byte)this[0x1e32]) + 1); iVar3 = iVar3 + 1)
    {
      if ((uint)(byte)this[0x1e32] + iVar3 == (uint)(byte)this[0x1e2f]) {
        pdVar6 = this + iVar5;
        *(float *)(pdVar6 + 0xea8) = d_menu_dmap::_5563 * *(float *)(pdVar6 + 0xea0);
        *(float *)(pdVar6 + 0xeac) = fVar1 * *(float *)(pdVar6 + 0xea4);
        f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar6 + 0xe7c));
        fVar1 = d_menu_dmap::_5563;
        *(float *)(pdVar6 + 0xff8) = d_menu_dmap::_5563 * *(float *)(pdVar6 + 0xff0);
        *(float *)(pdVar6 + 0xffc) = fVar1 * *(float *)(pdVar6 + 0xff4);
        local_78 = *(undefined4 *)(this + 0x14b4);
        local_74 = local_78;
        local_70 = local_78;
        local_6c = local_78;
        local_44 = local_78;
        J2DWindow::setContentsColor
                  (*(J2DWindow **)(pdVar6 + 0xfcc),(TColor)&local_78,(TColor)&local_74,
                   (TColor)&local_70,(TColor)&local_6c);
        local_48 = *(undefined4 *)(this + 0x14bc);
        iVar7 = *(int *)(pdVar6 + 0xfcc);
        local_48._0_1_ = (undefined)((uint)local_48 >> 0x18);
        *(undefined *)(iVar7 + 0x104) = local_48._0_1_;
        local_48._1_1_ = (undefined)((uint)local_48 >> 0x10);
        *(undefined *)(iVar7 + 0x105) = local_48._1_1_;
        local_48._2_1_ = (undefined)((uint)local_48 >> 8);
        *(undefined *)(iVar7 + 0x106) = local_48._2_1_;
        *(undefined *)(iVar7 + 0x107) = (undefined)local_48;
        local_4c = *(undefined4 *)(this + 0x14c4);
        iVar7 = *(int *)(pdVar6 + 0xfcc);
        local_4c._0_1_ = (undefined)((uint)local_4c >> 0x18);
        *(undefined *)(iVar7 + 0x108) = local_4c._0_1_;
        local_4c._1_1_ = (undefined)((uint)local_4c >> 0x10);
        *(undefined *)(iVar7 + 0x109) = local_4c._1_1_;
        local_4c._2_1_ = (undefined)((uint)local_4c >> 8);
        *(undefined *)(iVar7 + 0x10a) = local_4c._2_1_;
        *(undefined *)(iVar7 + 0x10b) = (undefined)local_4c;
        f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar6 + 0xfcc));
        fVar1 = d_menu_dmap::_5563;
        *(float *)(pdVar6 + 0x1148) = d_menu_dmap::_5563 * *(float *)(pdVar6 + 0x1140);
        *(float *)(pdVar6 + 0x114c) = fVar1 * *(float *)(pdVar6 + 0x1144);
        f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar6 + 0x111c));
      }
      else {
        pdVar6 = this + iVar5;
        *(undefined4 *)(pdVar6 + 0xea8) = *(undefined4 *)(pdVar6 + 0xea0);
        *(undefined4 *)(pdVar6 + 0xeac) = *(undefined4 *)(pdVar6 + 0xea4);
        f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar6 + 0xe7c));
        *(undefined4 *)(pdVar6 + 0xff8) = *(undefined4 *)(pdVar6 + 0xff0);
        *(undefined4 *)(pdVar6 + 0xffc) = *(undefined4 *)(pdVar6 + 0xff4);
        local_88 = *(undefined4 *)(this + 0x14b8);
        local_84 = local_88;
        local_80 = local_88;
        local_7c = local_88;
        local_50 = local_88;
        J2DWindow::setContentsColor
                  (*(J2DWindow **)(pdVar6 + 0xfcc),(TColor)&local_88,(TColor)&local_84,
                   (TColor)&local_80,(TColor)&local_7c);
        local_54 = *(undefined4 *)(this + 0x14c0);
        iVar7 = *(int *)(pdVar6 + 0xfcc);
        local_54._0_1_ = (undefined)((uint)local_54 >> 0x18);
        *(undefined *)(iVar7 + 0x104) = local_54._0_1_;
        local_54._1_1_ = (undefined)((uint)local_54 >> 0x10);
        *(undefined *)(iVar7 + 0x105) = local_54._1_1_;
        local_54._2_1_ = (undefined)((uint)local_54 >> 8);
        *(undefined *)(iVar7 + 0x106) = local_54._2_1_;
        *(undefined *)(iVar7 + 0x107) = (undefined)local_54;
        local_58 = *(undefined4 *)(this + 0x14c8);
        iVar7 = *(int *)(pdVar6 + 0xfcc);
        local_58._0_1_ = (undefined)((uint)local_58 >> 0x18);
        *(undefined *)(iVar7 + 0x108) = local_58._0_1_;
        local_58._1_1_ = (undefined)((uint)local_58 >> 0x10);
        *(undefined *)(iVar7 + 0x109) = local_58._1_1_;
        local_58._2_1_ = (undefined)((uint)local_58 >> 8);
        *(undefined *)(iVar7 + 0x10a) = local_58._2_1_;
        *(undefined *)(iVar7 + 0x10b) = (undefined)local_58;
        f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar6 + 0xfcc));
        *(undefined4 *)(pdVar6 + 0x1148) = *(undefined4 *)(pdVar6 + 0x1140);
        *(undefined4 *)(pdVar6 + 0x114c) = *(undefined4 *)(pdVar6 + 0x1144);
        f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar6 + 0x111c));
      }
      iVar5 = iVar5 + 0x38;
    }
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  return;
}


/* __thiscall dMenu_Dmap_c::floorInit(void) */

void __thiscall dMenu_Dmap_c::floorInit(dMenu_Dmap_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar3 = (*(float *)(this + 0xfd4) - *(float *)(this + 0x100c)) *
          (float)((double)CONCAT44(0x43300000,
                                   6 - (((uint)(byte)this[0x1e31] - (uint)(byte)this[0x1e32]) + 1 &
                                       0xff) ^ 0x80000000) - d_menu_dmap::_4523);
  fVar1 = *(float *)(this + 0x1294);
  fVar2 = *(float *)(this + 0x12cc);
  fVar4 = fVar1 - fVar3;
  *(float *)(this + 0x129c) = fVar4;
  *(float *)(this + 0x1294) = fVar4;
  fVar3 = fVar2 - fVar3;
  *(float *)(this + 0x12d4) = fVar3;
  *(float *)(this + 0x12cc) = fVar3;
  fVar3 = d_menu_dmap::_4521;
  fVar1 = (*(float *)(this + 0x1274) + fVar1) - *(float *)(this + 0x1294) * d_menu_dmap::_4521;
  *(float *)(this + 0x128c) = fVar1;
  *(float *)(this + 0x1284) = fVar1;
  fVar1 = (*(float *)(this + 0x12ac) + fVar2) - *(float *)(this + 0x12cc) * fVar3;
  *(float *)(this + 0x12c4) = fVar1;
  *(float *)(this + 0x12bc) = fVar1;
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(this + 0x126c));
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(this + 0x12a4));
  return;
}


/* __thiscall dMenu_Dmap_c::mapMove(void) */

void __thiscall dMenu_Dmap_c::mapMove(dMenu_Dmap_c *this)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  double dVar4;
  double local_18;
  double local_10;
  
  sVar1 = *(short *)(this + 0x1312);
  if (sVar1 < 1) {
    if (sVar1 < 0) {
      *(short *)(this + 0x1312) = sVar1 + 1;
      iVar3 = MSL_C.PPCEABI.bare.H::abs((int)*(short *)(this + 0x1312));
      dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(6,6 - iVar3,0);
      local_10 = (double)CONCAT44(0x43300000,
                                  ((int)*(short *)(this + 0x1e20) +
                                  ((byte)this[0x1e2f] - 0x80) *
                                  ((int)*(short *)(this + 0x1e24) + (int)*(short *)(this + 0x1e26)))
                                  - (int)*(short *)(this + 0x1e10) ^ 0x80000000);
      *(short *)(this + 0x1e10) =
           *(short *)(this + 0x1e10) +
           (short)(int)(dVar4 * (double)(float)(local_10 - d_menu_dmap::_4523));
    }
  }
  else {
    *(short *)(this + 0x1312) = sVar1 + -1;
    dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(6,6 - *(short *)(this + 0x1312),0);
    local_18 = (double)CONCAT44(0x43300000,
                                ((int)*(short *)(this + 0x1e20) +
                                ((byte)this[0x1e2f] - 0x80) *
                                ((int)*(short *)(this + 0x1e24) + (int)*(short *)(this + 0x1e26))) -
                                (int)*(short *)(this + 0x1e10) ^ 0x80000000);
    *(short *)(this + 0x1e10) =
         *(short *)(this + 0x1e10) +
         (short)(int)(dVar4 * (double)(float)(local_18 - d_menu_dmap::_4523));
  }
  uVar2 = *(undefined2 *)(this + 0x1e10);
  iVar3 = *(int *)(this + 0x14a0);
  *(undefined2 *)(iVar3 + 0x364) = *(undefined2 *)(this + 0x1e1e);
  *(undefined2 *)(iVar3 + 0x366) = uVar2;
  return;
}


/* WARNING: Removing unreachable block (ram,0x801ad110) */
/* __thiscall dMenu_Dmap_c::mapOffsetY(void) */

double __thiscall dMenu_Dmap_c::mapOffsetY(dMenu_Dmap_c *this)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  ulong uVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar6 = (double)d_menu_dmap::_4382;
  iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                    (0x803c9d58);
  if ((((*(uint *)(iVar2 + 0xc) >> 0x10 & 7) == 3) ||
      (iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                         (0x803c9d58), (*(uint *)(iVar2 + 0xc) >> 0x10 & 7) == 6)) &&
     (iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getDMap)
                        (0x803c9d58), iVar2 != 0)) {
    piVar3 = (int *)(*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getDMap)
                              (0x803c9d58);
    iVar2 = piVar3[1];
    if (*piVar3 != 1) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar4,"d_menu_dmap.cpp",0x65b,"pinf->num == 1");
      m_Do_printf::OSPanic("d_menu_dmap.cpp",0x65b,&DAT_8035f855);
    }
    iVar1 = *piVar3;
    if (0 < iVar1) {
      do {
        dVar6 = (double)*(float *)(iVar2 + 0xc);
        iVar2 = iVar2 + 0x10;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return dVar6;
}


/* WARNING: Removing unreachable block (ram,0x801ad18c) */
/* __thiscall dMenu_Dmap_c::itemnameMove(void) */

void __thiscall dMenu_Dmap_c::itemnameMove(dMenu_Dmap_c *this)

{
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  *(short *)(this + 0x7b2) = *(short *)(this + 0x7b2) + 1;
  if (*(short *)(this + 0x7b2) < 0xb) {
    dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(this + 0x7b2),0);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x77c),(float)dVar2);
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)(this + 0x7b4),(float)((double)d_menu_dmap::_5258 - dVar2));
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801ad524) */
/* WARNING: Removing unreachable block (ram,0x801ad52c) */
/* __thiscall dMenu_Dmap_c::dnameSet(void) */

void __thiscall dMenu_Dmap_c::dnameSet(dMenu_Dmap_c *this)

{
  byte bVar1;
  float fVar2;
  bool bVar3;
  ushort uVar4;
  int iVar5;
  mesg_header *pmVar6;
  ushort *puVar7;
  uint uVar8;
  ulong uVar9;
  byte *in_r5;
  undefined4 uVar10;
  undefined8 in_f30;
  double dVar11;
  double in_f31;
  byte local_78 [4];
  byte bStack116;
  byte local_73;
  byte local_70;
  byte local_6f;
  undefined local_6e;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  undefined1 *local_5c;
  undefined4 local_58;
  undefined2 local_54;
  undefined2 local_52;
  double local_50;
  undefined4 local_48;
  uint uStack68;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,SUB84(in_f31,0),0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  local_5c = &fopMsgM_itemMsgGet_c::__vt;
  local_58 = 0;
  local_54 = 0;
  local_52 = 0;
  this[0x1dc0] = (dMenu_Dmap_c)0x0;
  iVar5 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
  switch(*(byte *)(iVar5 + 9) >> 1) {
  default:
    uVar9 = 0x59;
    break;
  case 2:
    uVar9 = 800;
    break;
  case 3:
    uVar9 = 0x59;
    break;
  case 4:
    uVar9 = 0x5a;
    break;
  case 5:
    uVar9 = 0x5b;
    break;
  case 6:
    uVar9 = 0x5c;
    break;
  case 7:
    uVar9 = 0x5d;
    break;
  case 8:
    uVar9 = 0x5e;
  }
  pmVar6 = (mesg_header *)
           fopMsgM_itemMsgGet_c::getMesgHeader((fopMsgM_itemMsgGet_c *)&local_5c,uVar9);
  if (pmVar6 == (mesg_header *)0x0) {
    uVar9 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar9,"d_menu_dmap.cpp",0x6ab,"head_p");
    in_r5 = &DAT_8035f855;
    m_Do_printf::OSPanic("d_menu_dmap.cpp",0x6ab);
  }
  local_64 = *(float *)(*(int *)(this + 0x9ac) + 0xec);
  local_60 = local_64;
  puVar7 = (ushort *)fopMsgM_itemMsgGet_c::getMessage((fopMsgM_itemMsgGet_c *)&local_5c,pmVar6);
  bVar3 = false;
  uVar8 = (**(code **)(**(int **)(this + 0x14a8) + 0x30))();
  local_50 = (double)CONCAT44(0x43300000,uVar8 ^ 0x80000000);
  dVar11 = (double)(local_60 / (float)(local_50 - d_menu_dmap::_4523));
  while (*(byte *)puVar7 != 0) {
    local_6e = 0;
    local_6f = 0;
    local_70 = 0;
    bVar1 = *(byte *)puVar7;
    uVar4 = (ushort)bVar1;
    if (uVar4 == 0x1a) {
      puVar7 = (ushort *)((byte *)((int)puVar7 + 1) + (char)*(byte *)((int)puVar7 + 1) + -1);
    }
    else {
      if ((bVar1 >> 4 == 8) || (bVar1 >> 4 == 9)) {
        local_70 = *(byte *)puVar7;
        local_6f = *(byte *)((int)puVar7 + 1);
        uVar4 = *puVar7;
        puVar7 = puVar7 + 1;
      }
      else {
        local_6f = 0;
        puVar7 = (ushort *)((int)puVar7 + 1);
        local_70 = bVar1;
      }
      local_6e = 0;
      in_r5 = &bStack116;
      (**(code **)(**(int **)(this + 0x14a8) + 0x2c))(*(int **)(this + 0x14a8),uVar4);
      uVar8 = (uint)local_73;
      MSL_C.PPCEABI.bare.H::strcat((char *)(this + 0x1dc0),(char *)&local_70);
      if (bVar3) {
        local_50 = (double)CONCAT44(0x43300000,uVar8 ^ 0x80000000);
        in_f31 = (double)(float)(in_f31 + (double)(float)((double)(float)(local_50 -
                                                                         d_menu_dmap::_4523) *
                                                         dVar11));
      }
      else {
        in_r5 = local_78;
        (**(code **)(**(int **)(this + 0x14a8) + 0x2c))(*(int **)(this + 0x14a8),uVar4);
        local_50 = (double)CONCAT44(0x43300000,uVar8 + local_78[0] ^ 0x80000000);
        in_f31 = (double)(float)(dVar11 * (double)(float)(local_50 - d_menu_dmap::_4523));
        bVar3 = true;
      }
    }
  }
  iVar5 = *(int *)(this + 0x9ac);
  if ((double)(*(float *)(iVar5 + 0x14) - *(float *)(iVar5 + 0xc)) < in_f31) {
    uStack68 = (uint)((double)(local_64 *
                              (*(float *)(*(int *)(this + 0x77c) + 0x14) -
                              *(float *)(*(int *)(this + 0x77c) + 0xc))) / in_f31);
    local_50 = (double)(longlong)(int)uStack68;
    uStack68 = uStack68 ^ 0x80000000;
    local_48 = 0x43300000;
    local_64 = (float)((double)CONCAT44(0x43300000,uStack68) - d_menu_dmap::_4523);
  }
  local_6c = local_64;
  local_68 = local_60;
  fVar2 = d_menu_dmap::_4382;
  if (d_menu_dmap::_4382 < local_64) {
    fVar2 = local_64;
  }
  *(float *)(iVar5 + 0xe8) = fVar2;
  fVar2 = d_menu_dmap::_4382;
  if (d_menu_dmap::_4382 < local_60) {
    fVar2 = local_60;
  }
  *(float *)(iVar5 + 0xec) = fVar2;
  *(float *)(*(int *)(this + 0x9ac) + 0xe0) = d_menu_dmap::_4382;
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x9ac),(char *)(this + 0x1dc0),(___)in_r5);
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  __psq_l0(auStack24,uVar10);
  __psq_l1(auStack24,uVar10);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801ad9dc) */
/* WARNING: Removing unreachable block (ram,0x801ad670) */
/* WARNING: Removing unreachable block (ram,0x801ad9e4) */
/* __thiscall dMenu_Dmap_c::itemnameSet(void) */

void __thiscall dMenu_Dmap_c::itemnameSet(dMenu_Dmap_c *this)

{
  dMenu_Dmap_c dVar1;
  byte bVar2;
  float fVar3;
  bool bVar4;
  ushort uVar5;
  int iVar6;
  mesg_header *pmVar7;
  ushort *puVar8;
  uint uVar9;
  byte *pbVar10;
  ulong uVar11;
  undefined4 uVar12;
  undefined8 in_f30;
  double dVar13;
  double in_f31;
  byte local_88 [4];
  byte bStack132;
  byte local_83;
  byte local_80;
  byte local_7f;
  undefined local_7e;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  undefined1 *local_5c;
  undefined4 local_58;
  undefined2 local_54;
  undefined2 local_52;
  double local_50;
  undefined4 local_48;
  uint uStack68;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar12 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,SUB84(in_f31,0),0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  local_5c = &fopMsgM_itemMsgGet_c::__vt;
  local_58 = 0;
  local_54 = 0;
  local_52 = 0;
  uVar11 = 0;
  pbVar10 = (byte *)0x0;
  local_74 = *(float *)(*(int *)(this + 0x77c) + 0xe8);
  local_70 = *(float *)(*(int *)(this + 0x77c) + 0xec);
  iVar6 = *(int *)(this + 0x7b4);
  fVar3 = d_menu_dmap::_4382;
  if (d_menu_dmap::_4382 < local_74) {
    fVar3 = local_74;
  }
  *(float *)(iVar6 + 0xe8) = fVar3;
  fVar3 = d_menu_dmap::_4382;
  if (d_menu_dmap::_4382 < local_70) {
    fVar3 = local_70;
  }
  *(float *)(iVar6 + 0xec) = fVar3;
  *(undefined4 *)(*(int *)(this + 0x7b4) + 0xe0) = *(undefined4 *)(*(int *)(this + 0x77c) + 0xe0);
  for (; pbVar10[*(int *)(this + 0x1da8)] != 0; pbVar10 = pbVar10 + 1) {
    pbVar10[*(int *)(this + 0x1dac)] = pbVar10[*(int *)(this + 0x1da8)];
  }
  pbVar10[*(int *)(this + 0x1dac)] = 0;
  local_64 = local_74;
  local_60 = local_70;
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x7b4),*(char **)(this + 0x1dac),(___)pbVar10);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x1da8),"");
  dVar1 = this[0x1e2e];
  if (dVar1 == (dMenu_Dmap_c)0x1) {
    iVar6 = dSv_memBit_c::isDungeonItem
                      ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,2);
    if (iVar6 != 0) {
      uVar11 = SEXT24(dItem_data::item_resource[78].mNameMessageId);
    }
  }
  else {
    if (dVar1 == (dMenu_Dmap_c)0x0) {
      iVar6 = dSv_memBit_c::isDungeonItem
                        ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,0);
      if (iVar6 != 0) {
        uVar11 = SEXT24(dItem_data::item_resource[76].mNameMessageId);
      }
    }
    else {
      if (((byte)dVar1 < 3) &&
         (iVar6 = dSv_memBit_c::isDungeonItem
                            ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,1),
         iVar6 != 0)) {
        uVar11 = SEXT24(dItem_data::item_resource[77].mNameMessageId);
      }
    }
  }
  if (uVar11 == 0) {
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x77c),*(char **)(this + 0x1da8),(___)pbVar10);
  }
  else {
    pmVar7 = (mesg_header *)
             fopMsgM_itemMsgGet_c::getMesgHeader((fopMsgM_itemMsgGet_c *)&local_5c,uVar11);
    if (pmVar7 == (mesg_header *)0x0) {
      uVar11 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar11,"d_menu_dmap.cpp",0x729,"head_p");
      pbVar10 = &DAT_8035f855;
      m_Do_printf::OSPanic("d_menu_dmap.cpp",0x729);
    }
    local_6c = *(float *)(*(int *)(this + 0x77c) + 0xec);
    local_68 = local_6c;
    puVar8 = (ushort *)fopMsgM_itemMsgGet_c::getMessage((fopMsgM_itemMsgGet_c *)&local_5c,pmVar7);
    bVar4 = false;
    uVar9 = (**(code **)(**(int **)(this + 0x14a8) + 0x30))();
    local_50 = (double)CONCAT44(0x43300000,uVar9 ^ 0x80000000);
    dVar13 = (double)(local_68 / (float)(local_50 - d_menu_dmap::_4523));
    while (*(byte *)puVar8 != 0) {
      local_7e = 0;
      local_7f = 0;
      local_80 = 0;
      bVar2 = *(byte *)puVar8;
      uVar5 = (ushort)bVar2;
      if (uVar5 == 0x1a) {
        puVar8 = (ushort *)((byte *)((int)puVar8 + 1) + (char)*(byte *)((int)puVar8 + 1) + -1);
      }
      else {
        if ((bVar2 >> 4 == 8) || (bVar2 >> 4 == 9)) {
          local_80 = *(byte *)puVar8;
          local_7f = *(byte *)((int)puVar8 + 1);
          uVar5 = *puVar8;
          puVar8 = puVar8 + 1;
        }
        else {
          local_7f = 0;
          puVar8 = (ushort *)((int)puVar8 + 1);
          local_80 = bVar2;
        }
        local_7e = 0;
        pbVar10 = &bStack132;
        (**(code **)(**(int **)(this + 0x14a8) + 0x2c))(*(int **)(this + 0x14a8),uVar5);
        uVar9 = (uint)local_83;
        MSL_C.PPCEABI.bare.H::strcat(*(char **)(this + 0x1da8),(char *)&local_80);
        if (bVar4) {
          local_50 = (double)CONCAT44(0x43300000,uVar9 ^ 0x80000000);
          in_f31 = (double)(float)(in_f31 + (double)(float)((double)(float)(local_50 -
                                                                           d_menu_dmap::_4523) *
                                                           dVar13));
        }
        else {
          pbVar10 = local_88;
          (**(code **)(**(int **)(this + 0x14a8) + 0x2c))(*(int **)(this + 0x14a8),uVar5);
          local_50 = (double)CONCAT44(0x43300000,uVar9 + local_88[0] ^ 0x80000000);
          in_f31 = (double)(float)(dVar13 * (double)(float)(local_50 - d_menu_dmap::_4523));
          bVar4 = true;
        }
      }
    }
    iVar6 = *(int *)(this + 0x77c);
    dVar13 = (double)(*(float *)(iVar6 + 0x14) - *(float *)(iVar6 + 0xc));
    if (dVar13 < in_f31) {
      uStack68 = (uint)((double)(float)((double)local_6c * dVar13) / in_f31);
      local_50 = (double)(longlong)(int)uStack68;
      uStack68 = uStack68 ^ 0x80000000;
      local_48 = 0x43300000;
      local_6c = (float)((double)CONCAT44(0x43300000,uStack68) - d_menu_dmap::_4523);
    }
    local_7c = local_6c;
    local_78 = local_68;
    fVar3 = d_menu_dmap::_4382;
    if (d_menu_dmap::_4382 < local_6c) {
      fVar3 = local_6c;
    }
    *(float *)(iVar6 + 0xe8) = fVar3;
    fVar3 = d_menu_dmap::_4382;
    if (d_menu_dmap::_4382 < local_68) {
      fVar3 = local_68;
    }
    *(float *)(iVar6 + 0xec) = fVar3;
    *(float *)(*(int *)(this + 0x77c) + 0xe0) = d_menu_dmap::_4382;
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x77c),*(char **)(this + 0x1da8),(___)pbVar10);
  }
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  __psq_l0(auStack24,uVar12);
  __psq_l1(auStack24,uVar12);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x801adba8) */
/* WARNING: Removing unreachable block (ram,0x801adfe4) */
/* __thiscall dMenu_Dmap_c::itemnoteSet(void) */

void __thiscall dMenu_Dmap_c::itemnoteSet(dMenu_Dmap_c *this)

{
  double dVar1;
  double dVar2;
  float fVar3;
  dMenu_Dmap_c dVar4;
  float fVar5;
  int iVar6;
  mesg_header *pmVar7;
  undefined4 uVar8;
  dMenu_Dmap_c *pdVar9;
  ___ _Var10;
  int iVar11;
  uint uVar12;
  dMenu_Dmap_c *pdVar13;
  int iVar14;
  int iVar15;
  ulong uVar16;
  uint uVar17;
  undefined4 uVar18;
  undefined8 in_f31;
  double dVar19;
  undefined1 *local_a8;
  undefined4 local_a4;
  undefined2 local_a0;
  undefined2 local_9e;
  undefined4 local_9c;
  undefined2 local_98;
  undefined2 local_96;
  undefined2 local_94;
  undefined2 local_92;
  undefined local_90;
  undefined local_8f;
  undefined local_8e;
  undefined local_8d;
  undefined local_8c;
  undefined local_8b;
  undefined local_8a;
  undefined local_89;
  undefined local_88;
  undefined local_87;
  undefined local_86;
  undefined local_85;
  undefined4 local_84;
  undefined2 local_80;
  undefined2 local_7e;
  undefined2 local_7c;
  undefined2 local_7a;
  undefined local_78;
  undefined local_77;
  undefined local_76;
  undefined local_75;
  undefined local_74;
  undefined local_73;
  undefined local_72;
  undefined local_71;
  undefined local_70;
  undefined local_6f;
  undefined local_6e;
  undefined local_6d;
  double local_68;
  double local_60;
  double local_58;
  longlong local_50;
  double local_48;
  undefined4 local_40;
  uint uStack60;
  double local_38;
  undefined auStack8 [8];
  
  uVar18 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  local_a8 = &fopMsgM_itemMsgGet_c::__vt;
  local_a4 = 0;
  local_a0 = 0;
  local_9e = 0;
  uVar16 = 0;
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x1db0),"");
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x1db4),"");
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x1db8),"");
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x1dbc),"");
  outFontInit(this);
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ == '\0') {
    *(undefined *)(*(int *)(this + 0x894) + 0xaa) = 1;
  }
  else {
    *(undefined *)(*(int *)(this + 0x894) + 0xaa) = 0;
  }
  dVar19 = (double)*(float *)(*(int *)(this + 0x894) + 0xe8);
  local_68 = (double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U);
  dVar1 = local_68 - d_menu_dmap::_4523;
  fVar3 = (float)dVar1;
  local_60 = (double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U);
  dVar2 = local_60 - d_menu_dmap::_4523;
  iVar6 = *(int *)(this + 0x8cc);
  fVar5 = d_menu_dmap::_4382;
  if (d_menu_dmap::_4382 < fVar3) {
    fVar5 = fVar3;
  }
  *(float *)(iVar6 + 0xe8) = fVar5;
  fVar3 = d_menu_dmap::_4382;
  if (d_menu_dmap::_4382 < (float)dVar2) {
    fVar3 = (float)dVar2;
  }
  *(float *)(iVar6 + 0xec) = fVar3;
  local_58 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000);
  *(float *)(*(int *)(this + 0x8cc) + 0xe4) = (float)(local_58 - d_menu_dmap::_4523);
  dVar4 = this[0x1e2e];
  if (dVar4 == (dMenu_Dmap_c)0x1) {
    iVar6 = dSv_memBit_c::isDungeonItem
                      ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,2);
    if (iVar6 != 0) {
      uVar16 = (int)dItem_data::item_resource[78].mNameMessageId + 200;
    }
  }
  else {
    if (dVar4 == (dMenu_Dmap_c)0x0) {
      iVar6 = dSv_memBit_c::isDungeonItem
                        ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,0);
      if (iVar6 != 0) {
        uVar16 = (int)dItem_data::item_resource[76].mNameMessageId + 200;
      }
    }
    else {
      if (((byte)dVar4 < 3) &&
         (iVar6 = dSv_memBit_c::isDungeonItem
                            ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,1),
         iVar6 != 0)) {
        uVar16 = (int)dItem_data::item_resource[77].mNameMessageId + 200;
      }
    }
  }
  if (uVar16 != 0) {
    pmVar7 = (mesg_header *)
             fopMsgM_itemMsgGet_c::getMesgHeader((fopMsgM_itemMsgGet_c *)&local_a8,uVar16);
    if (pmVar7 == (mesg_header *)0x0) {
      uVar16 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar16,"d_menu_dmap.cpp",0x7b2,"head_p");
      m_Do_printf::OSPanic("d_menu_dmap.cpp",0x7b2,&DAT_8035f855);
    }
    uVar8 = fopMsgM_itemMsgGet_c::getMessage((fopMsgM_itemMsgGet_c *)&local_a8,pmVar7);
    fopMsgM_itemMsgGet_c::getMesgEntry((fopMsgM_itemMsgGet_c *)&local_9c,(mesg_header *)&local_a8);
    local_84 = local_9c;
    local_80 = local_98;
    local_7e = local_96;
    local_7c = local_94;
    local_7a = local_92;
    local_78 = local_90;
    local_77 = local_8f;
    local_76 = local_8e;
    local_75 = local_8d;
    local_74 = local_8c;
    local_73 = local_8b;
    local_72 = local_8a;
    local_71 = local_89;
    local_70 = local_88;
    local_6f = local_87;
    local_6e = local_86;
    local_6d = local_85;
    fopMsgM_msgDataProc_c::dataInit((fopMsgM_msgDataProc_c *)(this + 0x1b08));
    *(undefined4 *)(this + 0x1b44) = uVar8;
    _Var10 = *(___ *)(this + 0x1dbc);
    *(undefined4 *)(this + 0x1b68) = *(undefined4 *)(this + 0x1db0);
    *(undefined4 *)(this + 0x1b48) = *(undefined4 *)(this + 0x1db0);
    *(undefined4 *)(this + 0x1b6c) = *(undefined4 *)(this + 0x1db4);
    *(undefined4 *)(this + 0x1b4c) = *(undefined4 *)(this + 0x1db4);
    *(undefined4 *)(this + 0x1b70) = *(undefined4 *)(this + 0x1db8);
    *(undefined4 *)(this + 0x1b50) = *(undefined4 *)(this + 0x1db8);
    *(___ *)(this + 0x1b74) = _Var10;
    *(___ *)(this + 0x1b54) = _Var10;
    *(undefined4 *)(this + 0x1b0c) = *(undefined4 *)(this + 0x14a8);
    *(undefined4 *)(this + 0x1b10) = *(undefined4 *)(this + 0x14ac);
    local_58 = (double)(longlong)(int)*(float *)(*(int *)(this + 0x8cc) + 0xe0);
    *(int *)(this + 0x1c24) = (int)*(float *)(*(int *)(this + 0x8cc) + 0xe0);
    local_60 = (double)(longlong)(int)*(float *)(*(int *)(this + 0x894) + 0xe0);
    *(int *)(this + 0x1c2c) = (int)*(float *)(*(int *)(this + 0x894) + 0xe0);
    local_68 = (double)(longlong)(int)*(float *)(*(int *)(this + 0x8cc) + 0xe4);
    *(int *)(this + 0x1c28) = (int)*(float *)(*(int *)(this + 0x8cc) + 0xe4);
    *(undefined4 **)(this + 0x1b14) = &local_84;
    iVar6 = (int)dVar1;
    local_50 = (longlong)iVar6;
    *(int *)(this + 0x1c4c) = iVar6;
    local_48 = (double)(longlong)(int)dVar19;
    *(int *)(this + 0x1c54) = (int)dVar19;
    *(undefined4 *)(this + 0x1c30) = 0x1fe;
    *(undefined4 *)(this + 0x1c34) = 0x1e6;
    *(undefined4 *)(this + 0x1c68) = 2;
    *(undefined4 *)(this + 0x1c64) = 0;
    this[0x1da1] = (dMenu_Dmap_c)0x1;
    this[0x1da4] = (dMenu_Dmap_c)0x0;
    fopMsgM_msgDataProc_c::stringLength((fopMsgM_msgDataProc_c *)(this + 0x1b08));
    fopMsgM_msgDataProc_c::stringShift((fopMsgM_msgDataProc_c *)(this + 0x1b08));
    fopMsgM_msgDataProc_c::iconIdxRefresh((fopMsgM_msgDataProc_c *)(this + 0x1b08));
    uVar8 = *(undefined4 *)(this + 0x1c38);
    *(undefined4 *)(this + 0x1c38) = 0;
    fVar5 = d_menu_dmap::_4382;
    uVar17 = 3 - (int)(short)uVar8;
    uStack60 = uVar17 ^ 0x80000000;
    local_40 = 0x43300000;
    fVar3 = (float)((double)CONCAT44(0x43300000,uStack60) - d_menu_dmap::_4523) *
            *(float *)(*(int *)(this + 0x8cc) + 0xe4) * d_menu_dmap::_4521;
    iVar6 = *(int *)(this + 0x894);
    *(float *)(iVar6 + 0xd8) = d_menu_dmap::_4382;
    *(float *)(iVar6 + 0xdc) = fVar3;
    iVar6 = *(int *)(this + 0x8cc);
    *(float *)(iVar6 + 0xd8) = fVar5;
    *(float *)(iVar6 + 0xdc) = fVar3;
    fopMsgM_msgDataProc_c::stringSet((fopMsgM_msgDataProc_c *)(this + 0x1b08));
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x8cc),*(char **)(this + 0x1db0),_Var10);
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x894),*(char **)(this + 0x1db4),_Var10);
    fVar3 = *(float *)(*(int *)(this + 0x8cc) + 0xe4) * d_menu_dmap::_4521;
    iVar15 = 0;
    iVar14 = 0;
    iVar6 = 0;
    do {
      dVar1 = d_menu_dmap::_4523;
      uVar12 = (uint)(byte)this[iVar15 + 0x1d89];
      pdVar9 = this + iVar6;
      iVar11 = *(int *)(pdVar9 + 0x1d28);
      if (iVar11 == -1) {
        iVar11 = 0xff;
      }
      if (((uVar12 != 0xff) && (pdVar13 = this + iVar14, *(short *)(pdVar13 + 0x42) == -1)) &&
         (uVar12 != 0x16)) {
        local_38 = (double)CONCAT44(0x43300000,*(uint *)(pdVar9 + 0x1c70) ^ 0x80000000);
        *(float *)(pdVar13 + 0x18) = (float)(local_38 - d_menu_dmap::_4523);
        uStack60 = (int)fVar3 * (uVar17 + *(int *)(pdVar9 + 0x1cac) * 2) ^ 0x80000000;
        local_40 = 0x43300000;
        *(float *)(pdVar13 + 0x1c) = (float)((double)CONCAT44(0x43300000,uStack60) - dVar1);
        local_48 = (double)CONCAT44(0x43300000,uVar12);
        *(float *)(pdVar13 + 0x14) = (float)(local_48 - d_menu_dmap::_5151);
        f_op_msg_mng::fopMsgM_outFontSet(*(undefined4 *)(pdVar13 + 0xc),pdVar13 + 0x42,iVar11);
      }
      iVar15 = iVar15 + 1;
      iVar14 = iVar14 + 0x38;
      iVar6 = iVar6 + 4;
    } while (iVar15 < 0xf);
  }
  __psq_l0(auStack8,uVar18);
  __psq_l1(auStack8,uVar18);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801ae06c) */
/* __thiscall dMenu_Dmap_c::outFontInit(void) */

void __thiscall dMenu_Dmap_c::outFontInit(dMenu_Dmap_c *this)

{
  int *piVar1;
  int iVar2;
  dMenu_Dmap_c *pdVar3;
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
  dVar6 = (double)d_menu_dmap::_4382;
  do {
    pdVar3 = this + iVar4;
    *(undefined2 *)(pdVar3 + 0x42) = 0xffff;
    piVar1 = *(int **)(pdVar3 + 0xc);
    piVar1[0x29] = (int)(float)dVar6;
    (**(code **)(*piVar1 + 0x20))();
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar3 + 0xc));
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar2 < 0xf);
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* __thiscall dMenu_Dmap_c::linkAnime(void) */

void __thiscall dMenu_Dmap_c::linkAnime(dMenu_Dmap_c *this)

{
  float fVar1;
  
  *(short *)(this + 0xcf2) = *(short *)(this + 0xcf2) + 1;
  *(short *)(this + 0xd2a) = *(short *)(this + 0xd2a) + 1;
  if (*(short *)(this + 0x1e2a) < *(short *)(this + 0xcf2)) {
    *(undefined2 *)(this + 0xcf2) = 0;
    if (this[0x1e34] == (dMenu_Dmap_c)0x0) {
      *(undefined2 *)(this + 0x1e2a) = 5;
      this[0x1e34] = (dMenu_Dmap_c)0x1;
    }
    else {
      fVar1 = SComponent::cM_rndF(d_menu_dmap::_4516);
      *(short *)(this + 0x1e2a) = (short)(int)(d_menu_dmap::_4515 + fVar1);
      this[0x1e34] = (dMenu_Dmap_c)0x0;
    }
  }
  if (*(short *)(this + 0x1e28) < *(short *)(this + 0xd2a)) {
    *(undefined2 *)(this + 0xd2a) = 0;
    fVar1 = SComponent::cM_rndF(d_menu_dmap::_4515);
    *(short *)(this + 0x1e28) = (short)(int)(d_menu_dmap::_4515 + fVar1);
    if (this[0x1e33] == (dMenu_Dmap_c)0x0) {
      this[0x1e33] = (dMenu_Dmap_c)0x1;
    }
    else {
      this[0x1e33] = (dMenu_Dmap_c)0x0;
    }
  }
  if (this[0x1e34] == (dMenu_Dmap_c)0x0) {
    J2DPicture::changeTexture(*(J2DPicture **)(this + 0xcbc),"link_eye1.bti",0);
  }
  else {
    J2DPicture::changeTexture(*(J2DPicture **)(this + 0xcbc),"link_eye2.bti",0);
  }
  if (this[0x1e33] == (dMenu_Dmap_c)0x0) {
    J2DPicture::changeTexture(*(J2DPicture **)(this + 0xcf4),"link_mouth1.bti",0);
  }
  else {
    J2DPicture::changeTexture(*(J2DPicture **)(this + 0xcf4),"link_mouth2.bti",0);
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x801ae534) */
/* __thiscall dMenu_Dmap_c::bossAnime(void) */

void __thiscall dMenu_Dmap_c::bossAnime(dMenu_Dmap_c *this)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined8 in_f31;
  double dVar10;
  float fVar11;
  short asStack106 [6];
  short local_5e;
  short local_5c;
  short local_5a;
  short local_58;
  short local_56;
  short local_54;
  short local_52;
  short local_50;
  short local_4e;
  short local_4c;
  undefined4 local_48;
  short local_44;
  short local_40;
  short local_3c [4];
  short local_34;
  short local_30;
  short local_2c;
  double local_28;
  undefined auStack8 [8];
  
  sVar1 = DAT_803e6080;
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar10 = (double)d_menu_dmap::_4382;
  iVar7 = 3;
  puVar2 = (undefined4 *)&UNK_8035f710;
  puVar3 = (undefined4 *)&local_4c;
  do {
    puVar6 = puVar3;
    puVar5 = puVar2;
    uVar4 = puVar5[2];
    puVar6[1] = puVar5[1];
    puVar6[2] = uVar4;
    iVar7 = iVar7 + -1;
    puVar2 = puVar5 + 2;
    puVar3 = puVar6 + 2;
  } while (iVar7 != 0);
  puVar6[3] = puVar5[3];
  *(undefined2 *)(puVar6 + 4) = *(undefined2 *)(puVar5 + 4);
  local_48._0_2_ = DAT_803e6080;
  local_48._2_2_ = DAT_803e6082;
  local_44 = DAT_803e6084;
  local_40 = DAT_803e6086;
  local_3c[0] = DAT_803e6088;
  local_3c[2] = DAT_803e608a;
  local_34 = DAT_803e608c;
  asStack106[1] = DAT_803e6080;
  iVar7 = 2;
  iVar8 = 0xe;
  do {
    *(short *)((int)asStack106 + iVar7 + 2) =
         *(short *)((int)asStack106 + iVar7) + *(short *)((int)&local_48 + iVar7);
    iVar7 = iVar7 + 2;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  *(short *)(this + 0xdd2) = *(short *)(this + 0xdd2) + 1;
  iVar7 = (int)*(short *)(this + 0xdd2);
  if (iVar7 < *(short *)(this + 0xe0a)) {
    iVar8 = (int)local_54;
    if (iVar7 < iVar8) {
      if (iVar7 < sVar1) {
        dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease((int)local_48._0_2_,iVar7,0);
        dVar10 = (double)(float)((double)d_menu_dmap::_6120 * dVar10);
      }
      else {
        if (iVar7 < asStack106[2]) {
          dVar10 = (double)d_menu_dmap::_6120;
        }
        else {
          if (iVar7 < asStack106[3]) {
            dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                       ((int)local_44,asStack106[3] - iVar7,0);
            dVar10 = (double)(float)((double)d_menu_dmap::_6120 * dVar10);
          }
          else {
            if (iVar7 < asStack106[4]) {
              dVar10 = (double)d_menu_dmap::_4382;
            }
            else {
              if (iVar7 < asStack106[5]) {
                dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                           ((int)local_40,asStack106[5] - iVar7,0);
                dVar10 = (double)(float)((double)d_menu_dmap::_6120 * dVar10);
              }
              else {
                if (iVar7 < local_5e) {
                  dVar10 = (double)d_menu_dmap::_6120;
                }
                else {
                  if (iVar7 < local_5c) {
                    dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                               ((int)local_3c[0],local_5c - iVar7,0);
                    dVar10 = (double)(float)((double)d_menu_dmap::_6120 * dVar10);
                  }
                  else {
                    if (iVar7 < local_5a) {
                      dVar10 = (double)d_menu_dmap::_4382;
                    }
                    else {
                      if (iVar7 < local_58) {
                        dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                                   ((int)local_3c[2],local_58 - iVar7,0);
                        dVar10 = (double)(float)((double)d_menu_dmap::_6120 * dVar10);
                      }
                      else {
                        if (iVar7 < local_56) {
                          dVar10 = (double)d_menu_dmap::_6120;
                        }
                        else {
                          if (iVar7 < iVar8) {
                            dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                                       ((int)local_34,iVar8 - iVar7,0);
                            dVar10 = (double)(float)((double)d_menu_dmap::_6120 * dVar10);
                          }
                          else {
                            if (iVar7 < local_52) {
                              dVar10 = (double)d_menu_dmap::_4382;
                            }
                            else {
                              if (iVar7 < local_50) {
                                dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                                           ((int)local_30,local_50 - iVar7,0);
                                dVar10 = (double)(float)((double)d_menu_dmap::_6120 * dVar10);
                              }
                              else {
                                if (iVar7 < local_4e) {
                                  dVar10 = (double)d_menu_dmap::_6120;
                                }
                                else {
                                  if (iVar7 < local_4c) {
                                    dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                                               ((int)local_2c,local_4c - iVar7,0);
                                    dVar10 = (double)(float)((double)d_menu_dmap::_6120 * dVar10);
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
  }
  else {
    *(undefined2 *)(this + 0xdd2) = 0;
    fVar11 = SComponent::cM_rndF(d_menu_dmap::_4518);
    *(short *)(this + 0xe0a) = (short)(int)(d_menu_dmap::_4517 + fVar11);
  }
  local_28 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x1e14) ^ 0x80000000);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xd9c),(double)d_menu_dmap::_4382,
             (double)(float)((double)(float)(local_28 - d_menu_dmap::_4523) - dVar10));
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xdd4),(double)d_menu_dmap::_4382,
             (double)(float)((double)d_menu_dmap::_6120 * dVar10));
  bossEyeAnime(this);
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801ae640) */
/* __thiscall dMenu_Dmap_c::bossEyeAnime(void) */

void __thiscall dMenu_Dmap_c::bossEyeAnime(dMenu_Dmap_c *this)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  float fVar6;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar1 = *(ushort *)(this + 0x1e2c);
  iVar2 = (int)(short)(((short)uVar1 >> 1) + (ushort)((short)uVar1 < 0 && (uVar1 & 1) != 0));
  *(short *)(this + 0xd62) = *(short *)(this + 0xd62) + 1;
  if (this[0x1e36] == (dMenu_Dmap_c)0x0) {
    dVar5 = (double)d_menu_dmap::_4382;
  }
  else {
    iVar3 = (int)*(short *)(this + 0xd62);
    if (iVar3 < iVar2) {
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar2,iVar3,2);
    }
    else {
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar2,*(short *)(this + 0x1e2c) - iVar3,2)
      ;
    }
  }
  if (*(short *)(this + 0xd62) == *(short *)(this + 0x1e2c)) {
    *(undefined2 *)(this + 0xd62) = 0;
    fVar6 = SComponent::cM_rndF(d_menu_dmap::_4520);
    *(short *)(this + 0x1e2c) = (short)((int)(d_menu_dmap::_4519 + fVar6) << 1);
    if (this[0x1e36] == (dMenu_Dmap_c)0x0) {
      this[0x1e36] = (dMenu_Dmap_c)0x1;
    }
    else {
      this[0x1e36] = (dMenu_Dmap_c)0x0;
    }
  }
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xd2c),(float)dVar5);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xd64),(float)dVar5);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_Dmap_c::_create(void) */

void __thiscall dMenu_Dmap_c::_create(dMenu_Dmap_c *this)

{
  J2DPane *pJVar1;
  ulong uVar2;
  STControl *this_00;
  undefined **ppuVar3;
  J2DPicture *pJVar4;
  int iVar5;
  dMenu_Dmap_c *pdVar6;
  int iVar7;
  TBox2_float_ local_38;
  TBox2_float_ local_28;
  
  pJVar1 = (J2DPane *)JKernel::operator_new(0xd4);
  if (pJVar1 != (J2DPane *)0x0) {
    local_28.mTL.x = d_menu_dmap::_4382;
    local_28.mTL.y = d_menu_dmap::_4382;
    local_28.mBR.x = d_menu_dmap::_5387;
    local_28.mBR.y = d_menu_dmap::_5388;
    J2DPane::J2DPane(pJVar1,(J2DPane *)0x0,true,0x726f6f74,&local_28);
    pJVar1->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)pJVar1[1].mMagic = 0xffffffff;
    *(undefined *)&pJVar1[1].vtbl = 0;
  }
  *(J2DPane **)(this + 4) = pJVar1;
  if (*(int *)(this + 4) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_dmap.cpp",0x910,"scrn != 0");
    m_Do_printf::OSPanic("d_menu_dmap.cpp",0x910,&DAT_8035f855);
  }
  J2DScreen::set(*(J2DScreen **)(this + 4),"menu_map_d.blo",*(JKRArchive **)(this + 0x14a4));
  pJVar1 = (J2DPane *)JKernel::operator_new(0xd4);
  if (pJVar1 != (J2DPane *)0x0) {
    local_38.mTL.x = d_menu_dmap::_4382;
    local_38.mTL.y = d_menu_dmap::_4382;
    local_38.mBR.x = d_menu_dmap::_5387;
    local_38.mBR.y = d_menu_dmap::_5388;
    J2DPane::J2DPane(pJVar1,(J2DPane *)0x0,true,0x726f6f74,&local_38);
    pJVar1->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)pJVar1[1].mMagic = 0xffffffff;
    *(undefined *)&pJVar1[1].vtbl = 0;
  }
  *(J2DPane **)(this + 8) = pJVar1;
  if (*(int *)(this + 8) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_dmap.cpp",0x914,"scrn2 != 0");
    m_Do_printf::OSPanic("d_menu_dmap.cpp",0x914,&DAT_8035f855);
  }
  J2DScreen::set(*(J2DScreen **)(this + 8),"menu_explanation.blo",*(JKRArchive **)(this + 0x14a4));
  this_00 = (STControl *)JKernel::operator_new(0x28);
  if (this_00 != (STControl *)0x0) {
    STControl::STControl(this_00,5,2,3,2,d_menu_dmap::_6221,d_menu_dmap::_4521,0,0x2000);
  }
  *(STControl **)(this + 0x149c) = this_00;
  if (*(int *)(this + 0x149c) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_dmap.cpp",0x918,"stick != 0");
    m_Do_printf::OSPanic("d_menu_dmap.cpp",0x918,&DAT_8035f855);
  }
  ppuVar3 = (undefined **)JKernel::operator_new(0x620,0x20);
  if (ppuVar3 != (undefined **)0x0) {
    *ppuVar3 = (undefined *)&dDlst_base_c::__vt;
    *ppuVar3 = (undefined *)&dMap_Dmap_c::__vt;
  }
  *(undefined ***)(this + 0x14a0) = ppuVar3;
  if (*(int *)(this + 0x14a0) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_dmap.cpp",0x91b,"dmap_c != 0");
    m_Do_printf::OSPanic("d_menu_dmap.cpp",0x91b,&DAT_8035f855);
  }
  *(undefined4 *)(*(int *)(this + 0x14a0) + 0x2a0) = *(undefined4 *)(this + 0x14a4);
  iVar5 = 0;
  iVar7 = 0;
  do {
    pJVar4 = (J2DPicture *)JKernel::operator_new(0x124);
    if (pJVar4 != (J2DPicture *)0x0) {
      J2DPicture::J2DPicture(pJVar4,"treasurebox.bti");
    }
    pdVar6 = this + iVar7;
    *(J2DPicture **)(pdVar6 + 0x14cc) = pJVar4;
    if (*(int *)(pdVar6 + 0x14cc) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_dmap.cpp",0x921,"treasure_p[i].ppane != 0");
      m_Do_printf::OSPanic("d_menu_dmap.cpp",0x921,&DAT_8035f855);
    }
    pdVar6[0x14e2] = (dMenu_Dmap_c)0x0;
    iVar5 = iVar5 + 1;
    iVar7 = iVar7 + 0x18;
  } while (iVar5 < 0x20);
  iVar5 = 0;
  iVar7 = 0;
  do {
    pJVar4 = (J2DPicture *)JKernel::operator_new(0x124);
    if (pJVar4 != (J2DPicture *)0x0) {
      J2DPicture::J2DPicture(pJVar4,"black_white_3.bti");
    }
    pdVar6 = this + iVar7;
    *(J2DPicture **)(pdVar6 + 0x17cc) = pJVar4;
    if (*(int *)(pdVar6 + 0x17cc) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_dmap.cpp",0x927,"door_p[i].ppane != 0");
      m_Do_printf::OSPanic("d_menu_dmap.cpp",0x927,&DAT_8035f855);
    }
    pdVar6[0x17e2] = (dMenu_Dmap_c)0x0;
    iVar5 = iVar5 + 1;
    iVar7 = iVar7 + 0x18;
  } while (iVar5 < 0x20);
  pJVar4 = (J2DPicture *)JKernel::operator_new(0x124);
  if (pJVar4 != (J2DPicture *)0x0) {
    J2DPicture::J2DPicture(pJVar4,"f_otmicon.bti");
  }
  *(J2DPicture **)(this + 0x1acc) = pJVar4;
  if (*(int *)(this + 0x1acc) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_dmap.cpp",0x92c,"npc_p.ppane != 0");
    m_Do_printf::OSPanic("d_menu_dmap.cpp",0x92c,&DAT_8035f855);
  }
  this[0x1ae2] = (dMenu_Dmap_c)0x0;
  pJVar4 = (J2DPicture *)JKernel::operator_new(0x124);
  if (pJVar4 != (J2DPicture *)0x0) {
    J2DPicture::J2DPicture(pJVar4,"boss_small.bti");
  }
  *(J2DPicture **)(this + 0x1ae4) = pJVar4;
  if (*(int *)(this + 0x1ae4) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_dmap.cpp",0x930,"boss_p.ppane != 0");
    m_Do_printf::OSPanic("d_menu_dmap.cpp",0x930,&DAT_8035f855);
  }
  this[0x1afa] = (dMenu_Dmap_c)0x0;
  *(undefined2 *)(this + 0x1e0c) = 0;
  this[0x1e2e] = (dMenu_Dmap_c)0x3;
  *(undefined2 *)(this + 0x1e10) = 0;
  this[0x1e35] = (dMenu_Dmap_c)0x1;
  MSL_C.PPCEABI.bare.H::strcpy((char *)(this + 0x1dc0),"");
  screenSet(this);
  initialize(this);
  treasureSet(this);
  DAT_803e6048 = mDoHIO_subRoot_c::createChild
                           (&mDoHIO_subRoot_c_803a5778,"ダンジョンマップ画面",
                            (JORReflexible *)&d_menu_dmap::g_mdHIO);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Dmap_c::_delete(void) */

void __thiscall dMenu_Dmap_c::_delete(dMenu_Dmap_c *this)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = *(int **)(this + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  piVar1 = *(int **)(this + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  JKernel::operator_delete(*(JKRHeap **)(this + 0x149c));
  piVar1 = *(int **)(this + 0x14a0);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  iVar2 = 0;
  iVar3 = 0;
  do {
    piVar1 = *(int **)(this + iVar3 + 0x14cc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1,1);
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x18;
  } while (iVar2 < 0x20);
  iVar2 = 0;
  iVar3 = 0;
  do {
    piVar1 = *(int **)(this + iVar3 + 0x17cc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1,1);
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x18;
  } while (iVar2 < 0x20);
  piVar1 = *(int **)(this + 0x1acc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  piVar1 = *(int **)(this + 0x1ae4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  (**(code **)(**(int **)(this + 0x14a4) + 0x24))();
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e6048);
  return;
}


/* __thiscall dMenu_Dmap_c::_move(void) */

void __thiscall dMenu_Dmap_c::_move(dMenu_Dmap_c *this)

{
  char cVar2;
  int iVar1;
  
  cVar2 = noteCheck(this);
  if (cVar2 == '\0') {
    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 4 & 1) == 0) {
      if (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3) {
        if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
          cursorMove(this);
        }
        else {
          if ((((this[0x1e2e] == (dMenu_Dmap_c)0x0) &&
               (iVar1 = dSv_memBit_c::isDungeonItem
                                  ((dSv_memBit_c *)
                                   &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,0),
               iVar1 != 0)) ||
              ((this[0x1e2e] == (dMenu_Dmap_c)0x1 &&
               (iVar1 = dSv_memBit_c::isDungeonItem
                                  ((dSv_memBit_c *)
                                   &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,2),
               iVar1 != 0)))) ||
             ((this[0x1e2e] == (dMenu_Dmap_c)0x2 &&
              (iVar1 = dSv_memBit_c::isDungeonItem
                                 ((dSv_memBit_c *)
                                  &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,1), iVar1 != 0
              )))) {
            f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x894);
            f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x8cc);
            f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x904);
            f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x93c);
            f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x974);
            *(undefined2 *)(this + 0x972) = 1;
            *(undefined2 *)(this + 0x93a) = 1;
            itemnoteSet(this);
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x8b6,(cXyz *)0x0,0,0,d_menu_dmap::_5258,
                       d_menu_dmap::_5258,d_menu_dmap::_5259,d_menu_dmap::_5259,0);
          }
        }
      }
    }
  }
  else {
    noteAppear(this);
  }
  if (*(short *)(this + 0x7b2) < 10) {
    itemnameMove(this);
  }
  mapMove(this);
  linkAnime(this);
  bossAnime(this);
  cursorAnime(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_Dmap_c::_draw(void) */

void __thiscall dMenu_Dmap_c::_draw(dMenu_Dmap_c *this)

{
  J2DOrthoGraph *pCtx;
  int iVar1;
  dMenu_Dmap_c *pdVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar3 + 0xc));
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 0xf);
  iVar1 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x69c));
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 4);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x77c));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x7b4));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x7ec));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x824));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x85c));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x894));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x8cc));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x904));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x93c));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x974));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x9ac));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x9e4));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xa1c));
  iVar1 = 0;
  iVar3 = 0;
  do {
    pdVar2 = this + iVar3;
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar2 + 0xa54));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar2 + 0xafc));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar2 + 0xba4));
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 3);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xc4c));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xc84));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xd2c));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xd64));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xd9c));
  iVar1 = 0;
  iVar3 = 0;
  do {
    pdVar2 = this + iVar3;
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar2 + 0xe7c));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar2 + 0xfcc));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar2 + 0x111c));
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 6);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x126c));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x12a4));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x12dc));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1314));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x134c));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1384));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x13bc));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x13f4));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x142c));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1464));
  *(dMenu_Dmap_c *)(*(int *)(this + 0x14a0) + 0x2b6) = this[0x1429];
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(*(J2DScreen **)(this + 4),d_menu_dmap::_4382,d_menu_dmap::_4382,&pCtx->parent);
  (**(code **)(**(int **)(this + 0x14a0) + 0xc))();
  treasureDraw(this);
  J2DScreen::draw(*(J2DScreen **)(this + 8),d_menu_dmap::_4382,d_menu_dmap::_4382,&pCtx->parent);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x801af274) */
/* __thiscall dMenu_Dmap_c::_open(void) */

bool __thiscall dMenu_Dmap_c::_open(dMenu_Dmap_c *this)

{
  short sVar1;
  short sVar2;
  ___ in_r5;
  int iVar3;
  dMenu_Dmap_c *pdVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (*(short *)(this + 0x1e0c) == 0) {
    iVar3 = 0;
    iVar6 = 0;
    iVar5 = 0;
    do {
      pdVar4 = this + iVar5;
      MSL_C.PPCEABI.bare.H::strcpy(*(char **)(pdVar4 + 0x1da8),"");
      MSL_C.PPCEABI.bare.H::strcpy(*(char **)(pdVar4 + 0x1db0),"");
      J2DTextBox::setString
                (*(J2DTextBox **)(this + iVar6 + 0x77c),*(char **)(pdVar4 + 0x1da8),in_r5);
      iVar3 = iVar3 + 1;
      iVar6 = iVar6 + 0x38;
      iVar5 = iVar5 + 4;
    } while (iVar3 < 2);
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x8cc),*(char **)(this + 0x1db0),in_r5);
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x894),*(char **)(this + 0x1db4),in_r5);
    itemnameSet(this);
    itemnoteSet(this);
  }
  *(short *)(this + 0x1e0c) = *(short *)(this + 0x1e0c) + 1;
  if (*(short *)(this + 0x1e0c) < 0xb) {
    dVar9 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(this + 0x1e0c),0);
    dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - *(short *)(this + 0x1e0c),0);
    dVar8 = (double)d_menu_dmap::_5388;
    *(short *)(this + 0x1e0e) = (short)(int)(dVar8 * dVar10);
    paneMove(this,(float)(dVar8 * dVar10));
    sVar1 = *(short *)(this + 0x1e18);
    sVar2 = *(short *)(this + 0x1e0e);
    iVar3 = *(int *)(this + 0x14a0);
    *(undefined2 *)(iVar3 + 0x35c) = *(undefined2 *)(this + 0x1e16);
    *(short *)(iVar3 + 0x35e) = sVar1 + sVar2;
    sVar1 = *(short *)(this + 0x1e10);
    sVar2 = *(short *)(this + 0x1e0e);
    iVar3 = *(int *)(this + 0x14a0);
    *(undefined2 *)(iVar3 + 0x364) = *(undefined2 *)(this + 0x1e1e);
    *(short *)(iVar3 + 0x366) = sVar1 + sVar2;
    paneAlpha(this,(float)dVar9);
    noteOpenProc(this,*(short *)(this + 0x1e0c));
    this[0x1e35] = (dMenu_Dmap_c)0x1;
  }
  sVar1 = *(short *)(this + 0x1e0c);
  if (9 < sVar1) {
    this[0x1e35] = (dMenu_Dmap_c)0x0;
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x813,(cXyz *)0x0,0,0,d_menu_dmap::_5258,d_menu_dmap::_5258,
               d_menu_dmap::_5259,d_menu_dmap::_5259,0);
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return 9 < sVar1;
}


/* WARNING: Removing unreachable block (ram,0x801af398) */
/* __thiscall dMenu_Dmap_c::_close(void) */

bool __thiscall dMenu_Dmap_c::_close(dMenu_Dmap_c *this)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  *(short *)(this + 0x1e0c) = *(short *)(this + 0x1e0c) + -1;
  sVar1 = *(short *)(this + 0x1e0c);
  if (sVar1 < 1) {
    paneMove(this,d_menu_dmap::_5388);
    decAlpha(this,d_menu_dmap::_4382);
    this[0x1e35] = (dMenu_Dmap_c)0x0;
  }
  else {
    dVar7 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)sVar1,0);
    dVar8 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - *(short *)(this + 0x1e0c),0);
    dVar6 = (double)d_menu_dmap::_5388;
    *(short *)(this + 0x1e0e) = (short)(int)(dVar6 * dVar8);
    paneMove(this,(float)(dVar6 * dVar8));
    sVar2 = *(short *)(this + 0x1e18);
    sVar3 = *(short *)(this + 0x1e0e);
    iVar4 = *(int *)(this + 0x14a0);
    *(undefined2 *)(iVar4 + 0x35c) = *(undefined2 *)(this + 0x1e16);
    *(short *)(iVar4 + 0x35e) = sVar2 + sVar3;
    sVar2 = *(short *)(this + 0x1e10);
    sVar3 = *(short *)(this + 0x1e0e);
    iVar4 = *(int *)(this + 0x14a0);
    *(undefined2 *)(iVar4 + 0x364) = *(undefined2 *)(this + 0x1e1e);
    *(short *)(iVar4 + 0x366) = sVar2 + sVar3;
    d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
    decAlpha(this,(float)dVar7);
    this[0x1e35] = (dMenu_Dmap_c)0x1;
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return sVar1 < 1;
}


/* __thiscall dMenu_Dmap_c::~dMenu_Dmap_c(void) */

void __thiscall dMenu_Dmap_c::_dMenu_Dmap_c(dMenu_Dmap_c *this)

{
  short in_r4;
  
  if (this != (dMenu_Dmap_c *)0x0) {
    *(undefined1 **)this = &__vt;
    fopMsgM_msgDataProc_c::_fopMsgM_msgDataProc_c((fopMsgM_msgDataProc_c *)(this + 0x1b08));
    if ((this != (dMenu_Dmap_c *)0x0) &&
       (*(undefined1 **)this = &dMenu_base_c::__vt, this != (dMenu_Dmap_c *)0x0)) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMenu_Dmap_c::draw(void) */

void __thiscall dMenu_Dmap_c::draw(dMenu_Dmap_c *this)

{
  (**(code **)(*(int *)this + 0x1c))();
  return;
}


/* __thiscall dMd_HIO_c::~dMd_HIO_c(void) */

void __thiscall dMd_HIO_c::_dMd_HIO_c(dMd_HIO_c *this)

{
  short in_r4;
  
  if ((this != (dMd_HIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace d_menu_dmap {

void __sinit_d_menu_dmap_cpp(void)

{
  ::dMd_HIO_c::dMd_HIO_c((dMd_HIO_c *)&g_mdHIO);
  Runtime.PPCEABI.H::__register_global_object();
  return;
}

