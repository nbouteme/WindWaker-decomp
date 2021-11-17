#include <d_menu_collect.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <f_op_msg_mng.h>
#include <J2DGraph/J2DTextBox.h>
#include <d_2dnumber.h>
#include <d_save.h>
#include <JKernel/JKRArchivePub.h>
#include <os/OSCache.h>
#include <J2DGraph/J2DPicture.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <d_menu_collect.h>
#include <d_lib.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <MSL_C.PPCEABI.bare.H/arith.h>
#include <J2DGraph/J2DWindow.h>
#include <J2DGraph/J2DPane.h>
#include <JAZelAudio/JAIZelInst.h>
#include <m_Do_audio.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DScreen.h>
#include <d_menu_option.h>
#include <d_menu_save.h>
#include <m_Do_hostIO.h>
#include <d_particle.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dMenu_Option_c.h>
#include <dMc_HIO_c.h>
#include <dMenu_Collect_c.h>
#include <dMenu_base_c.h>


namespace d_menu_collect {
undefined g_mcHIO;
}

/* __thiscall dMc_HIO_c::dMc_HIO_c(void) */

void __thiscall dMc_HIO_c::dMc_HIO_c(dMc_HIO_c *this)

{
  *(undefined1 **)this = &__vt;
  *(undefined4 *)(this + 0x58) = 0xffffffff;
  *(undefined2 *)(this + 0x46) = 0x28;
  *(undefined2 *)(this + 0x48) = 10;
  *(undefined2 *)(this + 0x4a) = 0x78;
  *(undefined2 *)(this + 0x4c) = 100;
  *(float *)(this + 0x54) = d_menu_collect::_4054;
  this[0x5c] = (dMc_HIO_c)0xff;
  this[0x5d] = (dMc_HIO_c)0x46;
  this[0x52] = (dMc_HIO_c)0x82;
  *(undefined2 *)(this + 0x4e) = 0xfa;
  *(undefined2 *)(this + 0x50) = 0x14;
  this[0x58] = (dMc_HIO_c)0xff;
  this[0x59] = (dMc_HIO_c)0xaa;
  this[0x5a] = (dMc_HIO_c)0x0;
  this[0x5b] = (dMc_HIO_c)0x0;
  *(undefined2 *)(this + 0x44) = 0xd;
  return;
}


/* WARNING: Inlined function: FUN_80328f0c */
/* WARNING: Inlined function: FUN_80328f58 */
/* WARNING: Removing unreachable block (ram,0x8019cb3c) */
/* __thiscall dMenu_Collect_c::screenSet(void) */

void __thiscall dMenu_Collect_c::screenSet(dMenu_Collect_c *this)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  dMenu_Collect_c *pdVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined8 in_f31;
  double dVar9;
  char acStack136 [16];
  double local_78;
  double local_70;
  double local_68;
  double local_60;
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar2 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x524f4f54);
  *(undefined4 *)(this + 0x2478) = uVar2;
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 8),*(J2DScreen **)(this + 4),0x66743135);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x40),*(J2DScreen **)(this + 4),0x66743136);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x78),*(J2DScreen **)(this + 4),0x66743137);
  iVar3 = 0;
  iVar6 = 0;
  iVar7 = 0;
  do {
    pdVar5 = this + iVar7;
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar5 + 0xb0),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_collect::l_ft_4058 + iVar6));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar5 + 0x3f8),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_collect::l_fd_4059 + iVar6));
    *(undefined2 *)(pdVar5 + 0xe6) = 0xffff;
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 0x38;
  } while (iVar3 < 0xf);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x740),*(J2DScreen **)(this + 4),0x73747230);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x778),*(J2DScreen **)(this + 4),0x73743030);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x7b0),*(J2DScreen **)(this + 4),0x6e743030);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x7e8),*(J2DScreen **)(this + 4),0x6e6b3030);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x820),*(J2DScreen **)(this + 4),0x6e6f3131);
  local_78 = (double)(longlong)(int)*(float *)(*(int *)(this + 0x820) + 0xa4);
  *(short *)(this + 0x856) = (short)(int)*(float *)(*(int *)(this + 0x820) + 0xa4);
  if (0xb4 < *(short *)(this + 0x856)) {
    *(short *)(this + 0x856) = *(short *)(this + 0x856) + -0x168;
  }
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x740),*(JUTFont **)(this + 0x2474));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x778),*(JUTFont **)(this + 0x2470));
  iVar3 = *(int *)(this + 0x740);
  *(undefined *)(iVar3 + 0xf4) = 0xff;
  *(undefined *)(iVar3 + 0xf5) = 0xff;
  *(undefined *)(iVar3 + 0xf6) = 0xff;
  *(undefined *)(iVar3 + 0xf7) = 0xff;
  iVar3 = *(int *)(this + 0x740);
  *(undefined *)(iVar3 + 0xd0) = 0;
  *(undefined *)(iVar3 + 0xd1) = 0;
  *(undefined *)(iVar3 + 0xd2) = 0;
  *(undefined *)(iVar3 + 0xd3) = 0xff;
  iVar3 = *(int *)(this + 0x740);
  *(undefined *)(iVar3 + 0xd4) = 0;
  *(undefined *)(iVar3 + 0xd5) = 0;
  *(undefined *)(iVar3 + 0xd6) = 0;
  *(undefined *)(iVar3 + 0xd7) = 0xff;
  iVar3 = *(int *)(this + 0x778);
  *(undefined *)(iVar3 + 0xf4) = 0xff;
  *(undefined *)(iVar3 + 0xf5) = 0xff;
  *(undefined *)(iVar3 + 0xf6) = 0xff;
  *(undefined *)(iVar3 + 0xf7) = 0xff;
  iVar3 = *(int *)(this + 0x778);
  *(undefined *)(iVar3 + 0xd0) = 0;
  *(undefined *)(iVar3 + 0xd1) = 0;
  *(undefined *)(iVar3 + 0xd2) = 0;
  *(undefined *)(iVar3 + 0xd3) = 0xff;
  iVar3 = *(int *)(this + 0x778);
  *(undefined *)(iVar3 + 0xd4) = 0;
  *(undefined *)(iVar3 + 0xd5) = 0;
  *(undefined *)(iVar3 + 0xd6) = 0;
  *(undefined *)(iVar3 + 0xd7) = 0xff;
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x858),*(J2DScreen **)(this + 4),0x7764);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x858),*(JUTFont **)(this + 0x2470));
  dDlst_2DOutFont_c::setPane
            (*(dDlst_2DOutFont_c **)(this + 0x2460),*(JUTFont **)(this + 0x2470),
             (fopMsgM_pane_class *)(this + 0x858),(fopMsgM_pane_class *)(this + 8),
             (fopMsgM_pane_class *)(this + 0x40),(fopMsgM_pane_class *)(this + 0x78));
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x890),*(J2DScreen **)(this + 4),0x6e6d3030);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x890),*(JUTFont **)(this + 0x2470));
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x8c8),*(J2DScreen **)(this + 4),0x6e6d3031);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x8c8),*(JUTFont **)(this + 0x2470));
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x900),*(J2DScreen **)(this + 4),0x69746e6d);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x938),*(J2DScreen **)(this + 4),0x69746e6b);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x970),*(J2DScreen **)(this + 4),0x6d736b30);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x9a8),*(J2DScreen **)(this + 4),0x746c3030);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x9e0),*(J2DScreen **)(this + 4),0x746b3030);
  iVar3 = 0;
  iVar6 = 0;
  iVar7 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar7 + 0xa18),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_collect::l_car_4060 + iVar6));
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 0x38;
  } while (iVar3 < 4);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xaf8),*(J2DScreen **)(this + 4),0x77647376);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xb30),*(J2DScreen **)(this + 4),0x77646f70);
  iVar3 = 0;
  iVar6 = 0;
  iVar7 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar7 + 0xb68),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_collect::l_wk_4077 + iVar6));
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 0x38;
  } while (iVar3 < 4);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xc48),*(J2DScreen **)(this + 4),0x6e756d31);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xc80),*(J2DScreen **)(this + 4),0x6e756d32);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xcb8),*(J2DScreen **)(this + 4),0x6e756d63);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xcf0),*(J2DScreen **)(this + 4),0x636d6170);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xd28),*(J2DScreen **)(this + 4),0x776b31);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xd60),*(J2DScreen **)(this + 4),0x776b30);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xd98),*(J2DScreen **)(this + 4),0x7472696d);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xdd0),*(J2DScreen **)(this + 4),0x7472696c);
  *(undefined *)(*(int *)(this + 0xd98) + 0xaa) = 1;
  *(undefined *)(*(int *)(this + 0xdd0) + 0xaa) = 1;
  iVar3 = 0;
  iVar6 = 0;
  iVar7 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar7 + 0xe08),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_collect::l_tri_4061 + iVar6));
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 0x38;
  } while (iVar3 < 8);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xfc8),*(J2DScreen **)(this + 4),0x74726962);
  iVar3 = 0;
  iVar6 = 0;
  iVar7 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar7 + 0x1000),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_collect::l_sit_4062 + iVar6));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar7 + 0x10a8),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_collect::l_sik_4063 + iVar6));
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 0x38;
  } while (iVar3 < 3);
  iVar3 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1480);
  dVar9 = d_menu_collect::_4290;
  fVar1 = d_menu_collect::_4287;
  if (iVar3 != 0) {
    local_78 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x106c]);
    iVar3 = (int)((float)(local_78 - d_menu_collect::_4290) * d_menu_collect::_4287);
    local_70 = (double)(longlong)iVar3;
    this[0x106c] = SUB41(iVar3,0);
    local_68 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1114]);
    iVar3 = (int)((float)(local_68 - dVar9) * fVar1);
    local_60 = (double)(longlong)iVar3;
    this[0x1114] = SUB41(iVar3,0);
  }
  iVar3 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1440);
  dVar9 = d_menu_collect::_4290;
  fVar1 = d_menu_collect::_4287;
  if (iVar3 != 0) {
    local_60 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x10a4]);
    iVar3 = (int)((float)(local_60 - d_menu_collect::_4290) * d_menu_collect::_4287);
    local_68 = (double)(longlong)iVar3;
    this[0x10a4] = SUB41(iVar3,0);
    local_70 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x114c]);
    iVar3 = (int)((float)(local_70 - dVar9) * fVar1);
    local_78 = (double)(longlong)iVar3;
    this[0x114c] = SUB41(iVar3,0);
  }
  iVar3 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1410);
  dVar9 = d_menu_collect::_4290;
  fVar1 = d_menu_collect::_4287;
  if (iVar3 != 0) {
    local_60 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1034]);
    iVar3 = (int)((float)(local_60 - d_menu_collect::_4290) * d_menu_collect::_4287);
    local_68 = (double)(longlong)iVar3;
    this[0x1034] = SUB41(iVar3,0);
    local_70 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x10dc]);
    iVar3 = (int)((float)(local_70 - dVar9) * fVar1);
    local_78 = (double)(longlong)iVar3;
    this[0x10dc] = SUB41(iVar3,0);
  }
  iVar3 = 0;
  iVar6 = 0;
  iVar7 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar7 + 0x1150),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_collect::l_ci_4064 + iVar6));
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 0x38;
  } while (iVar3 < 0xb);
  iVar3 = 0;
  iVar6 = 0;
  iVar7 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar7 + 0x13b8),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_collect::l_htp_4065 + iVar6));
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 0x38;
  } while (iVar3 < 3);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1460),*(J2DScreen **)(this + 4),0x68747062);
  iVar3 = 0;
  iVar6 = 0;
  iVar7 = 0;
  dVar9 = (double)d_menu_collect::_4054;
  do {
    pdVar5 = this + iVar7;
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar5 + 0x1498),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_collect::l_tit_4066 + iVar6));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar5 + 0x15e8),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_collect::l_tik_4067 + iVar6));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar5 + 0x17a8),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_collect::l_cn_4068 + iVar6));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar5 + 0x18f8),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_collect::l_wn_4069 + iVar6));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar5 + 0x1a48),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_collect::l_i0_4070 + iVar6));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar5 + 0x1b98),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_collect::l_i1_4071 + iVar6));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar5 + 0x1ce8),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_collect::l_bs_4072 + iVar6));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar5 + 0x1e38),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_collect::l_hmb_4073 + iVar6));
    *(float *)(pdVar5 + 0x190c) = (float)((double)*(float *)(pdVar5 + 0x190c) - dVar9);
    *(float *)(pdVar5 + 0x1910) = (float)((double)*(float *)(pdVar5 + 0x1910) - dVar9);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(pdVar5 + 0x18f8),(double)d_menu_collect::_4288,
               (double)d_menu_collect::_4288);
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 0x38;
  } while (iVar3 < 6);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1738),*(J2DScreen **)(this + 4),0x69313131);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 6000),*(J2DScreen **)(this + 4),0x69313232);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1f88),*(J2DScreen **)(this + 4),0x63633433);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1fc0),*(J2DScreen **)(this + 4),0x63633332);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1ff8),*(J2DScreen **)(this + 4),0x63633231);
  iVar3 = 0;
  iVar6 = 0;
  iVar7 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar7 + 0x2030),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_collect::l_wit_4074 + iVar6));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar7 + 0x2148),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_collect::l_wik_4075 + iVar6));
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 0x38;
  } while (iVar3 < 5);
  iVar3 = 0;
  iVar6 = 0;
  iVar7 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar7 + 0x2260),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_collect::l_ip_4076 + iVar6));
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 0x38;
  } while (iVar3 < 5);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x2378),*(J2DScreen **)(this + 4),0x69703030);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x23b0),*(J2DScreen **)(this + 4),0x63633134);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x23e8),*(J2DScreen **)(this + 4),0x63633037);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x2420),*(J2DScreen **)(this + 4),0x63633030);
  JKRArchive::readTypeResource
            (*(void **)(this + 0x2498),0xc00,0x54494d47,"baton.bti",
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
  os::DCStoreRangeNoSync(*(undefined4 *)(this + 0x2498),0xc00);
  JKRArchive::readTypeResource
            (*(void **)(this + 0x249c),0xc00,0x54494d47,"cmap_treasure2.bti",
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
  os::DCStoreRangeNoSync(*(undefined4 *)(this + 0x249c),0xc00);
  iVar3 = 0;
  iVar6 = 0;
  do {
    J2DPicture::changeTexture
              (*(J2DPicture **)(this + iVar6 + 0x1498),*(ResTIMG **)(this + 0x2498),'\0');
    J2DPicture::changeTexture
              (*(J2DPicture **)(this + iVar6 + 0x15e8),*(ResTIMG **)(this + 0x2498),'\0');
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 0x38;
  } while (iVar3 < 6);
  J2DPicture::changeTexture(*(J2DPicture **)(this + 0xcf0),*(ResTIMG **)(this + 0x249c),'\0');
  iVar3 = 0;
  iVar6 = 0;
  iVar7 = 0;
  do {
    iVar4 = iVar7 + 0x24a0;
    JKRArchive::readTypeResource
              (*(void **)(this + iVar4),0xc00,0x54494d47,
               *(char **)((int)&d_menu_collect::triTex_4147 + iVar7),
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
    os::DCStoreRangeNoSync(*(undefined4 *)(this + iVar4),0xc00);
    J2DPicture::changeTexture
              (*(J2DPicture **)(this + iVar6 + 0xe08),*(ResTIMG **)(this + iVar4),'\0');
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 0x38;
    iVar7 = iVar7 + 4;
  } while (iVar3 < 8);
  *(undefined2 *)(this + 0xf1e) = 0xffff;
  *(float *)(this + 0x27a8) = *(float *)(this + 0xefc) - *(float *)(this + 0xfdc);
  *(float *)(this + 0x27ac) = *(float *)(this + 0xf00) - *(float *)(this + 0xfe0);
  iVar3 = 0;
  iVar6 = 0;
  iVar7 = 0;
  do {
    iVar4 = iVar7 + 0x24c0;
    JKRArchive::readTypeResource
              (*(void **)(this + iVar4),0xc00,0x54494d47,
               *(char **)((int)&d_menu_collect::symTex_4153 + iVar7),
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
    os::DCStoreRangeNoSync(*(undefined4 *)(this + iVar4),0xc00);
    J2DPicture::changeTexture
              (*(J2DPicture **)(this + iVar6 + 0x1000),*(ResTIMG **)(this + iVar4),'\0');
    J2DPicture::changeTexture
              (*(J2DPicture **)(this + iVar6 + 0x10a8),*(ResTIMG **)(this + iVar4),'\0');
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 0x38;
    iVar7 = iVar7 + 4;
  } while (iVar3 < 3);
  iVar3 = 0;
  iVar7 = 0;
  iVar6 = 0;
  do {
    iVar4 = iVar6 + 0x24cc;
    JKRArchive::readTypeResource
              (*(void **)(this + iVar4),0xc00,0x54494d47,
               *(char **)((int)&d_menu_collect::wepTex_4159 + iVar6),
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
    os::DCStoreRangeNoSync(*(undefined4 *)(this + iVar4),0xc00);
    J2DPicture::changeTexture
              (*(J2DPicture **)(this + iVar7 + 0x2030),*(ResTIMG **)(this + iVar4),'\0');
    J2DPicture::changeTexture
              (*(J2DPicture **)(this + iVar7 + 0x2148),*(ResTIMG **)(this + iVar4),'\0');
    iVar3 = iVar3 + 1;
    iVar7 = iVar7 + 0x38;
    iVar6 = iVar6 + 4;
  } while (iVar3 < 5);
  iVar3 = dSv_player_map_c::getCollectMapNum
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap);
  MSL_C.PPCEABI.bare.H::sprintf(acStack136,"rupy_num_%02d.bti",iVar3 / 10);
  J2DPicture::changeTexture(*(J2DPicture **)(this + 0xc48),acStack136,0);
  iVar3 = dSv_player_map_c::getCollectMapNum
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap);
  MSL_C.PPCEABI.bare.H::sprintf(acStack136,"rupy_num_%02d.bti",iVar3 % 10);
  J2DPicture::changeTexture(*(J2DPicture **)(this + 0xc80),acStack136,0);
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  return;
}


/* __thiscall dMenu_Collect_c::initialize(void) */

void __thiscall dMenu_Collect_c::initialize(dMenu_Collect_c *this)

{
  int iVar1;
  int iVar2;
  
  *(undefined2 *)(this + 0x27e2) = 0;
  this[0x27f2] = (dMenu_Collect_c)0x0;
  *(undefined4 *)(this + 0x27dc) = 0;
  *(undefined2 *)(this + 0x88e) = 10;
  *(undefined2 *)(this + 0xa4e) = 0;
  *(undefined2 *)(this + 0xa86) = 0;
  *(undefined2 *)(this + 0x27e4) = 0;
  iVar1 = 0;
  iVar2 = 6;
  do {
    *(undefined2 *)(this + iVar1 + 0x14ce) = 0;
    iVar1 = iVar1 + 0x38;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined2 *)(this + 0x161e) = 0;
  iVar1 = 0;
  iVar2 = 6;
  do {
    *(undefined2 *)(this + iVar1 + 0x1e6e) = 0;
    iVar1 = iVar1 + 0x38;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined2 *)(this + 0x14ce) = 0;
  this[0x27ea] = (dMenu_Collect_c)0x0;
  this[0x27ec] = (dMenu_Collect_c)0x0;
  this[0x27ee] = (dMenu_Collect_c)0x0;
  this[0x27ef] = (dMenu_Collect_c)0x0;
  tactGuideHide(this);
  if (((byte)this[0x27ed] < 6) &&
     (iVar1 = dSv_player_collect_c::isTact
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                         (uchar)this[0x27ed]), iVar1 != 0)) {
    iVar1 = 0;
    iVar2 = 6;
    do {
      *(undefined2 *)(this + iVar1 + 0x1e6e) = 1;
      iVar1 = iVar1 + 0x38;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    tactGuideShow(this,(uchar)this[0x27ed],false);
  }
  else {
    tactBaseShow(this);
  }
  if (((byte)this[0x27ed] < 0xe) || (0x12 < (byte)this[0x27ed])) {
    collectPriority(this);
  }
  else {
    weponPriority(this);
  }
  noteInit(this);
  outFontInit(this);
  itemBitCheck(this);
  this[0x9a4] = (dMenu_Collect_c)0x82;
  *(undefined2 *)(this + 0x27e6) = 0;
  *(undefined2 *)(this + 0x27e8) = 0;
  iVar1 = *(int *)(this + 0xba0);
  this[0x2488] = *(dMenu_Collect_c *)(iVar1 + 0xf4);
  this[0x2489] = *(dMenu_Collect_c *)(iVar1 + 0xf5);
  this[0x248a] = *(dMenu_Collect_c *)(iVar1 + 0xf6);
  this[0x248b] = *(dMenu_Collect_c *)(iVar1 + 0xf7);
  this[0x248c] = *(dMenu_Collect_c *)(iVar1 + 0xf8);
  this[0x248d] = *(dMenu_Collect_c *)(iVar1 + 0xf9);
  this[0x248e] = *(dMenu_Collect_c *)(iVar1 + 0xfa);
  this[0x248f] = *(dMenu_Collect_c *)(iVar1 + 0xfb);
  this[0x2490] = *(dMenu_Collect_c *)(iVar1 + 0xfc);
  this[0x2491] = *(dMenu_Collect_c *)(iVar1 + 0xfd);
  this[0x2492] = *(dMenu_Collect_c *)(iVar1 + 0xfe);
  this[0x2493] = *(dMenu_Collect_c *)(iVar1 + 0xff);
  this[0x2494] = *(dMenu_Collect_c *)(iVar1 + 0x100);
  this[0x2495] = *(dMenu_Collect_c *)(iVar1 + 0x101);
  this[0x2496] = *(dMenu_Collect_c *)(iVar1 + 0x102);
  this[0x2497] = *(dMenu_Collect_c *)(iVar1 + 0x103);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8019d518) */
/* WARNING: Removing unreachable block (ram,0x8019d520) */
/* __thiscall dMenu_Collect_c::cursorAnime(void) */

void __thiscall dMenu_Collect_c::cursorAnime(dMenu_Collect_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  short unaff_r30;
  int iVar7;
  short unaff_r31;
  J2DPicture *pJVar8;
  int iVar9;
  undefined4 uVar10;
  undefined8 in_f30;
  double dVar11;
  undefined8 in_f31;
  double dVar12;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  fVar1 = d_menu_collect::_4287;
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  switch(this[0x27ed]) {
  case (dMenu_Collect_c)0x0:
  case (dMenu_Collect_c)0x1:
  case (dMenu_Collect_c)0x2:
  case (dMenu_Collect_c)0x3:
  case (dMenu_Collect_c)0x4:
  case (dMenu_Collect_c)0x5:
    iVar6 = 0;
    iVar7 = 0;
    iVar9 = 4;
    do {
      *(float *)(this + iVar6 + 0xa2c) =
           *(float *)(this + (uint)(byte)this[0x27ed] * 0x38 + 0x14b4) +
           *(float *)(this + iVar7 + 0x2788);
      *(float *)(this + iVar6 + 0xa30) =
           *(float *)(this + (uint)(byte)this[0x27ed] * 0x38 + 0x14b8) +
           *(float *)(this + iVar7 + 0x2798);
      iVar6 = iVar6 + 0x38;
      iVar7 = iVar7 + 4;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    break;
  case (dMenu_Collect_c)0x6:
    *(float *)(this + 0xa2c) =
         *(float *)(this + 0xb4c) - *(float *)(this + 0xb5c) * d_menu_collect::_4287;
    *(float *)(this + 0xa30) = *(float *)(this + 0xb50) + *(float *)(this + 0xb60) * fVar1;
    *(float *)(this + 0xa64) = *(float *)(this + 0xb4c) + *(float *)(this + 0xb5c) * fVar1;
    *(float *)(this + 0xa68) = *(float *)(this + 0xb50) + *(float *)(this + 0xb60) * fVar1;
    *(float *)(this + 0xa9c) = *(float *)(this + 0xb4c) - *(float *)(this + 0xb5c) * fVar1;
    *(float *)(this + 0xaa0) = *(float *)(this + 0xb50) - *(float *)(this + 0xb60) * fVar1;
    *(float *)(this + 0xad4) = *(float *)(this + 0xb4c) + *(float *)(this + 0xb5c) * fVar1;
    *(float *)(this + 0xad8) = *(float *)(this + 0xb50) - *(float *)(this + 0xb60) * fVar1;
    break;
  case (dMenu_Collect_c)0x7:
    *(float *)(this + 0xa2c) =
         *(float *)(this + 0xb14) - *(float *)(this + 0xb24) * d_menu_collect::_4287;
    *(float *)(this + 0xa30) = *(float *)(this + 0xb18) + *(float *)(this + 0xb28) * fVar1;
    *(float *)(this + 0xa64) = *(float *)(this + 0xb14) + *(float *)(this + 0xb24) * fVar1;
    *(float *)(this + 0xa68) = *(float *)(this + 0xb18) + *(float *)(this + 0xb28) * fVar1;
    *(float *)(this + 0xa9c) = *(float *)(this + 0xb14) - *(float *)(this + 0xb24) * fVar1;
    *(float *)(this + 0xaa0) = *(float *)(this + 0xb18) - *(float *)(this + 0xb28) * fVar1;
    *(float *)(this + 0xad4) = *(float *)(this + 0xb14) + *(float *)(this + 0xb24) * fVar1;
    *(float *)(this + 0xad8) = *(float *)(this + 0xb18) - *(float *)(this + 0xb28) * fVar1;
    break;
  case (dMenu_Collect_c)0x8:
    iVar6 = 0;
    iVar7 = 0;
    iVar9 = 4;
    do {
      *(float *)(this + iVar6 + 0xa2c) =
           *(float *)(this + 0x1434) + *(float *)(this + iVar7 + 0x2788);
      *(float *)(this + iVar6 + 0xa30) =
           *(float *)(this + 0x1438) + *(float *)(this + iVar7 + 0x2798);
      iVar6 = iVar6 + 0x38;
      iVar7 = iVar7 + 4;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    break;
  case (dMenu_Collect_c)0x9:
    iVar6 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x908);
    if ((iVar6 == 0) &&
       (iVar6 = dSv_player_map_c::getCollectMapNum
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap),
       fVar1 = d_menu_collect::_4287, iVar6 == 0)) {
      *(float *)(this + 0xa2c) =
           *(float *)(this + 0xd7c) - *(float *)(this + 0xd8c) * d_menu_collect::_4287;
      *(float *)(this + 0xa30) = *(float *)(this + 0xd80) + *(float *)(this + 0xd90) * fVar1;
      *(float *)(this + 0xa64) = *(float *)(this + 0xd7c) + *(float *)(this + 0xd8c) * fVar1;
      *(float *)(this + 0xa68) = *(float *)(this + 0xd80) + *(float *)(this + 0xd90) * fVar1;
      *(float *)(this + 0xa9c) = *(float *)(this + 0xd7c) - *(float *)(this + 0xd8c) * fVar1;
      *(float *)(this + 0xaa0) = *(float *)(this + 0xd80) - *(float *)(this + 0xd90) * fVar1;
      *(float *)(this + 0xad4) = *(float *)(this + 0xd7c) + *(float *)(this + 0xd8c) * fVar1;
      *(float *)(this + 0xad8) = *(float *)(this + 0xd80) - *(float *)(this + 0xd90) * fVar1;
    }
    else {
      iVar6 = 0;
      iVar7 = 0;
      iVar9 = 4;
      do {
        *(float *)(this + iVar6 + 0xa2c) =
             *(float *)(this + 0xd0c) + *(float *)(this + iVar7 + 0x2788);
        *(float *)(this + iVar6 + 0xa30) =
             *(float *)(this + 0xd10) + *(float *)(this + iVar7 + 0x2798);
        iVar6 = iVar6 + 0x38;
        iVar7 = iVar7 + 4;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    break;
  case (dMenu_Collect_c)0xa:
    *(float *)(this + 0xa2c) =
         *(float *)(this + 0xf04) - *(float *)(this + 0xff4) * d_menu_collect::_4287;
    *(float *)(this + 0xa30) = *(float *)(this + 0xf08) + *(float *)(this + 0xff8) * fVar1;
    *(float *)(this + 0xa64) = *(float *)(this + 0xf04) + *(float *)(this + 0xff4) * fVar1;
    *(float *)(this + 0xa68) = *(float *)(this + 0xf08) + *(float *)(this + 0xff8) * fVar1;
    *(float *)(this + 0xa9c) = *(float *)(this + 0xf04) - *(float *)(this + 0xff4) * fVar1;
    *(float *)(this + 0xaa0) = *(float *)(this + 0xf08) - *(float *)(this + 0xff8) * fVar1;
    *(float *)(this + 0xad4) = *(float *)(this + 0xf04) + *(float *)(this + 0xff4) * fVar1;
    *(float *)(this + 0xad8) = *(float *)(this + 0xf08) - *(float *)(this + 0xff8) * fVar1;
    break;
  case (dMenu_Collect_c)0xb:
  case (dMenu_Collect_c)0xc:
  case (dMenu_Collect_c)0xd:
    iVar6 = 0;
    iVar7 = 0;
    iVar9 = 4;
    do {
      *(float *)(this + iVar6 + 0xa2c) =
           *(float *)(this + (uint)(byte)this[0x27ed] * 0x38 + 0xdb4) +
           *(float *)(this + iVar7 + 0x2788);
      *(float *)(this + iVar6 + 0xa30) =
           *(float *)(this + (uint)(byte)this[0x27ed] * 0x38 + 0xdb8) +
           *(float *)(this + iVar7 + 0x2798);
      iVar6 = iVar6 + 0x38;
      iVar7 = iVar7 + 4;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    break;
  case (dMenu_Collect_c)0xe:
  case (dMenu_Collect_c)0xf:
  case (dMenu_Collect_c)0x10:
  case (dMenu_Collect_c)0x11:
  case (dMenu_Collect_c)0x12:
    iVar6 = 0;
    iVar7 = 0;
    iVar9 = 4;
    do {
      *(float *)(this + iVar6 + 0xa2c) =
           *(float *)(this + (uint)(byte)this[0x27ed] * 0x38 + 0x1d3c) +
           *(float *)(this + iVar7 + 0x2788);
      *(float *)(this + iVar6 + 0xa30) =
           *(float *)(this + (uint)(byte)this[0x27ed] * 0x38 + 0x1d40) +
           *(float *)(this + iVar7 + 0x2798);
      iVar6 = iVar6 + 0x38;
      iVar7 = iVar7 + 4;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    break;
  case (dMenu_Collect_c)0x13:
    fVar1 = (*(float *)(this + 0x1524) + *(float *)(this + 0x155c)) * d_menu_collect::_4287;
    fVar2 = ((*(float *)(this + 0x15bc) + *(float *)(this + 0x15dc)) - *(float *)(this + 0x14a4)) *
            d_menu_collect::_4287;
    fVar3 = *(float *)(this + 0x14c8) * d_menu_collect::_4287;
    fVar4 = fVar1 - fVar2;
    *(float *)(this + 0xa2c) = fVar4;
    fVar5 = *(float *)(this + 0x14b8) + fVar3;
    *(float *)(this + 0xa30) = fVar5;
    fVar1 = fVar1 + fVar2;
    *(float *)(this + 0xa64) = fVar1;
    *(float *)(this + 0xa68) = fVar5;
    *(float *)(this + 0xa9c) = fVar4;
    fVar3 = *(float *)(this + 0x14b8) - fVar3;
    *(float *)(this + 0xaa0) = fVar3;
    *(float *)(this + 0xad4) = fVar1;
    *(float *)(this + 0xad8) = fVar3;
    break;
  case (dMenu_Collect_c)0x14:
    *(float *)(this + 0xa2c) =
         *(float *)(this + 0x132c) - *(float *)(this + 0x133c) * d_menu_collect::_4287;
    *(float *)(this + 0xa30) = *(float *)(this + 0x1330) + *(float *)(this + 0x1340) * fVar1;
    *(float *)(this + 0xa64) = *(float *)(this + 0x132c) + *(float *)(this + 0x133c) * fVar1;
    *(float *)(this + 0xa68) = *(float *)(this + 0x1330) + *(float *)(this + 0x1340) * fVar1;
    *(float *)(this + 0xa9c) = *(float *)(this + 0x132c) - *(float *)(this + 0x133c) * fVar1;
    *(float *)(this + 0xaa0) = *(float *)(this + 0x1330) - *(float *)(this + 0x1340) * fVar1;
    *(float *)(this + 0xad4) = *(float *)(this + 0x132c) + *(float *)(this + 0x133c) * fVar1;
    *(float *)(this + 0xad8) = *(float *)(this + 0x1330) - *(float *)(this + 0x1340) * fVar1;
  }
  if (*(short *)(this + 0xa4e) < 10) {
    iVar6 = 0;
    iVar7 = 0;
    dVar12 = (double)d_menu_collect::_4440;
    dVar11 = (double)d_menu_collect::_4288;
    do {
      pJVar8 = *(J2DPicture **)(this + iVar7 + 0xa18);
      pJVar8->mBlendKonstColorF[0] = (float)dVar12;
      pJVar8->mBlendKonstColorF[1] = (float)dVar11;
      pJVar8->mBlendKonstColorF[2] = (float)dVar12;
      pJVar8->mBlendKonstColorF[3] = (float)dVar12;
      J2DPicture::setBlendKonstColor(pJVar8);
      pJVar8->mBlendKonstAlphaF[0] = (float)dVar12;
      pJVar8->mBlendKonstAlphaF[1] = (float)dVar11;
      pJVar8->mBlendKonstAlphaF[2] = (float)dVar12;
      pJVar8->mBlendKonstAlphaF[3] = (float)dVar12;
      J2DPicture::setBlendKonstAlpha(pJVar8);
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 0x38;
    } while (iVar6 < 4);
    unaff_r31 = 7;
    unaff_r30 = 7;
  }
  else {
    if (*(short *)(this + 0xa4e) < 0x14) {
      iVar6 = 0;
      iVar7 = 0;
      dVar11 = (double)d_menu_collect::_4288;
      dVar12 = (double)d_menu_collect::_4440;
      do {
        pJVar8 = *(J2DPicture **)(this + iVar7 + 0xa18);
        pJVar8->mBlendKonstColorF[0] = (float)dVar11;
        pJVar8->mBlendKonstColorF[1] = (float)dVar12;
        pJVar8->mBlendKonstColorF[2] = (float)dVar12;
        pJVar8->mBlendKonstColorF[3] = (float)dVar12;
        J2DPicture::setBlendKonstColor(pJVar8);
        pJVar8->mBlendKonstAlphaF[0] = (float)dVar11;
        pJVar8->mBlendKonstAlphaF[1] = (float)dVar12;
        pJVar8->mBlendKonstAlphaF[2] = (float)dVar12;
        pJVar8->mBlendKonstAlphaF[3] = (float)dVar12;
        J2DPicture::setBlendKonstAlpha(pJVar8);
        iVar6 = iVar6 + 1;
        iVar7 = iVar7 + 0x38;
      } while (iVar6 < 4);
      unaff_r31 = 0xe;
      unaff_r30 = 0xe;
    }
  }
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xa18),
             (double)(float)((double)CONCAT44(0x43300000,-(int)unaff_r31 ^ 0x80000000) -
                            d_menu_collect::_4443),
             (double)(float)((double)CONCAT44(0x43300000,(int)unaff_r30 ^ 0x80000000) -
                            d_menu_collect::_4443));
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xa50),
             (double)(float)((double)CONCAT44(0x43300000,(int)unaff_r31 ^ 0x80000000) -
                            d_menu_collect::_4443),
             (double)(float)((double)CONCAT44(0x43300000,(int)unaff_r30 ^ 0x80000000) -
                            d_menu_collect::_4443));
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xa88),
             (double)(float)((double)CONCAT44(0x43300000,-(int)unaff_r31 ^ 0x80000000) -
                            d_menu_collect::_4443),
             (double)(float)((double)CONCAT44(0x43300000,-(int)unaff_r30 ^ 0x80000000) -
                            d_menu_collect::_4443));
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xac0),
             (double)(float)((double)CONCAT44(0x43300000,(int)unaff_r31 ^ 0x80000000) -
                            d_menu_collect::_4443),
             (double)(float)((double)CONCAT44(0x43300000,-(int)unaff_r30 ^ 0x80000000) -
                            d_menu_collect::_4443));
  *(short *)(this + 0xa4e) = *(short *)(this + 0xa4e) + 1;
  if (0x13 < *(short *)(this + 0xa4e)) {
    *(undefined2 *)(this + 0xa4e) = 0;
  }
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  __psq_l0(auStack24,uVar10);
  __psq_l1(auStack24,uVar10);
  return;
}


/* __thiscall dMenu_Collect_c::stickDirection(unsigned char) */

undefined4 __thiscall dMenu_Collect_c::stickDirection(dMenu_Collect_c *this,uchar param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xff;
  switch(param_1) {
  case '\0':
  case '\x03':
  case '\a':
    goto switchD_8019d564_caseD_0;
  case '\x01':
    return 1;
  case '\x02':
    return 5;
  case '\x04':
    uVar1 = 7;
switchD_8019d564_caseD_0:
    return uVar1;
  case '\x05':
    return 0;
  case '\x06':
    return 6;
  case '\b':
    return 3;
  case '\t':
    return 2;
  case '\n':
    return 4;
  default:
    return uVar1;
  }
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x8019e550) */
/* WARNING: Removing unreachable block (ram,0x8019e444) */
/* __thiscall dMenu_Collect_c::cursorMainMove(void) */

int __thiscall dMenu_Collect_c::cursorMainMove(dMenu_Collect_c *this)

{
  dMenu_Collect_c dVar1;
  dMenu_Collect_c dVar2;
  bool bVar3;
  uchar uVar5;
  char cVar6;
  byte bVar7;
  int iVar4;
  uint uVar8;
  dMenu_Collect_c *pdVar9;
  int iVar10;
  dMenu_Collect_c dVar11;
  int iVar12;
  undefined4 uVar13;
  double dVar14;
  undefined8 in_f31;
  double dVar15;
  dMenu_Collect_c local_48 [4];
  undefined local_44;
  undefined local_43;
  undefined auStack8 [8];
  
  uVar13 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  bVar7 = 0xff;
  uVar5 = STControl::checkTrigger(*(STControl **)(this + 0x2458));
  dVar1 = this[0x27ed];
  iVar10 = 0;
  cVar6 = STControl::checkRightTrigger(*(STControl **)(this + 0x2458));
  if (cVar6 == '\0') {
    cVar6 = STControl::checkLeftTrigger(*(STControl **)(this + 0x2458));
    if (cVar6 != '\0') {
      iVar10 = 1;
    }
  }
  else {
    iVar10 = 1;
  }
  cVar6 = STControl::checkUpTrigger(*(STControl **)(this + 0x2458));
  if (cVar6 == '\0') {
    cVar6 = STControl::checkDownTrigger(*(STControl **)(this + 0x2458));
    if (cVar6 != '\0') {
      iVar10 = 1;
    }
  }
  else {
    iVar10 = 1;
  }
  if (iVar10 != 0) {
    bVar7 = stickDirection(this,uVar5);
  }
  dVar11 = (dMenu_Collect_c)0xff;
  if (bVar7 != 0xff) {
    bVar3 = false;
    uVar8 = (uint)(byte)this[0x27ed];
    dVar11 = *(dMenu_Collect_c *)(&d_menu_collect::item_4486 + (uint)bVar7 + uVar8 * 8);
    switch(dVar11) {
    case (dMenu_Collect_c)0x0:
      if (uVar8 < 6) {
        if ((uVar8 == (byte)dVar11) ||
           (iVar4 = dSv_player_collect_c::isTact
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                               (uchar)dVar11), iVar4 == 0)) {
          if ((bVar7 == 0) || (bVar7 == 1)) {
            dVar11 = (dMenu_Collect_c)0xe;
          }
          else {
            if ((bVar7 == 5) || (bVar7 == 6)) {
              local_48[0] = (dMenu_Collect_c)0x1;
              local_48[1] = (dMenu_Collect_c)0x2;
              local_48[2] = (dMenu_Collect_c)0x3;
              local_48[3] = (dMenu_Collect_c)0x4;
              local_44 = 5;
              iVar4 = 0;
              pdVar9 = local_48;
              do {
                dVar2 = *pdVar9;
                iVar12 = dSv_player_collect_c::isTact
                                   (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                     mCollect,(uchar)dVar2);
                if (iVar12 != 0) {
                  bVar3 = true;
                  dVar11 = dVar2;
                  break;
                }
                iVar4 = iVar4 + 1;
                pdVar9 = pdVar9 + 1;
              } while (iVar4 < 5);
              if (!bVar3) {
                dVar11 = (dMenu_Collect_c)0xa;
              }
            }
          }
        }
      }
      else {
        local_48[0] = (dMenu_Collect_c)0x0;
        local_48[1] = (dMenu_Collect_c)0x1;
        local_48[2] = (dMenu_Collect_c)0x2;
        local_48[3] = (dMenu_Collect_c)0x3;
        local_44 = 4;
        local_43 = 5;
        iVar4 = 0;
        pdVar9 = local_48;
        do {
          dVar2 = *pdVar9;
          iVar12 = dSv_player_collect_c::isTact
                             (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                              (uchar)dVar2);
          if (iVar12 != 0) {
            bVar3 = true;
            dVar11 = dVar2;
            break;
          }
          iVar4 = iVar4 + 1;
          pdVar9 = pdVar9 + 1;
        } while (iVar4 < 6);
        if (!bVar3) {
          dVar11 = (dMenu_Collect_c)0x13;
        }
      }
      break;
    case (dMenu_Collect_c)0x1:
      if (uVar8 < 6) {
        if ((uVar8 == (byte)dVar11) ||
           (iVar4 = dSv_player_collect_c::isTact
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                               (uchar)dVar11), iVar4 == 0)) {
          if ((bVar7 == 0) || (bVar7 == 1)) {
            local_48[0] = (dMenu_Collect_c)0x0;
            iVar4 = dSv_player_collect_c::isTact
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                               '\0');
            dVar11 = local_48[0];
            if (iVar4 == 0) {
              dVar11 = (dMenu_Collect_c)0xe;
            }
          }
          else {
            if ((bVar7 == 5) || (bVar7 == 6)) {
              local_48[0] = (dMenu_Collect_c)0x2;
              local_48[1] = (dMenu_Collect_c)0x3;
              local_48[2] = (dMenu_Collect_c)0x4;
              local_48[3] = (dMenu_Collect_c)0x5;
              iVar4 = 0;
              pdVar9 = local_48;
              do {
                dVar2 = *pdVar9;
                iVar12 = dSv_player_collect_c::isTact
                                   (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                     mCollect,(uchar)dVar2);
                if (iVar12 != 0) {
                  bVar3 = true;
                  dVar11 = dVar2;
                  break;
                }
                iVar4 = iVar4 + 1;
                pdVar9 = pdVar9 + 1;
              } while (iVar4 < 4);
              if (!bVar3) {
                dVar11 = (dMenu_Collect_c)0xa;
              }
            }
          }
        }
      }
      else {
        local_48[0] = (dMenu_Collect_c)0x1;
        local_48[1] = (dMenu_Collect_c)0x0;
        local_48[2] = (dMenu_Collect_c)0x2;
        local_48[3] = (dMenu_Collect_c)0x3;
        local_44 = 4;
        local_43 = 5;
        iVar4 = 0;
        pdVar9 = local_48;
        do {
          dVar2 = *pdVar9;
          iVar12 = dSv_player_collect_c::isTact
                             (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                              (uchar)dVar2);
          if (iVar12 != 0) {
            bVar3 = true;
            dVar11 = dVar2;
            break;
          }
          iVar4 = iVar4 + 1;
          pdVar9 = pdVar9 + 1;
        } while (iVar4 < 6);
        if (!bVar3) {
          dVar11 = (dMenu_Collect_c)0x13;
        }
      }
      break;
    case (dMenu_Collect_c)0x2:
      if (uVar8 < 6) {
        if ((uVar8 == (byte)dVar11) ||
           (iVar4 = dSv_player_collect_c::isTact
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                               (uchar)dVar11), iVar4 == 0)) {
          if ((bVar7 == 0) || (bVar7 == 1)) {
            local_48[0] = (dMenu_Collect_c)0x1;
            local_48[1] = (dMenu_Collect_c)0x0;
            iVar4 = 0;
            pdVar9 = local_48;
            do {
              dVar2 = *pdVar9;
              iVar12 = dSv_player_collect_c::isTact
                                 (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect
                                  ,(uchar)dVar2);
              if (iVar12 != 0) {
                bVar3 = true;
                dVar11 = dVar2;
                break;
              }
              iVar4 = iVar4 + 1;
              pdVar9 = pdVar9 + 1;
            } while (iVar4 < 2);
            if (!bVar3) {
              dVar11 = (dMenu_Collect_c)0xe;
            }
          }
          else {
            if ((bVar7 == 5) || (bVar7 == 6)) {
              local_48[0] = (dMenu_Collect_c)0x3;
              local_48[1] = (dMenu_Collect_c)0x4;
              local_48[2] = (dMenu_Collect_c)0x5;
              iVar4 = 0;
              pdVar9 = local_48;
              do {
                dVar2 = *pdVar9;
                iVar12 = dSv_player_collect_c::isTact
                                   (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                     mCollect,(uchar)dVar2);
                if (iVar12 != 0) {
                  bVar3 = true;
                  dVar11 = dVar2;
                  break;
                }
                iVar4 = iVar4 + 1;
                pdVar9 = pdVar9 + 1;
              } while (iVar4 < 3);
              if (!bVar3) {
                dVar11 = (dMenu_Collect_c)0xa;
              }
            }
          }
        }
      }
      else {
        local_48[0] = (dMenu_Collect_c)0x2;
        local_48[1] = (dMenu_Collect_c)0x1;
        local_48[2] = (dMenu_Collect_c)0x3;
        local_48[3] = (dMenu_Collect_c)0x0;
        local_44 = 4;
        local_43 = 5;
        iVar4 = 0;
        pdVar9 = local_48;
        do {
          dVar2 = *pdVar9;
          iVar12 = dSv_player_collect_c::isTact
                             (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                              (uchar)dVar2);
          if (iVar12 != 0) {
            bVar3 = true;
            dVar11 = dVar2;
            break;
          }
          iVar4 = iVar4 + 1;
          pdVar9 = pdVar9 + 1;
        } while (iVar4 < 6);
        if (!bVar3) {
          dVar11 = (dMenu_Collect_c)0x13;
        }
      }
      break;
    case (dMenu_Collect_c)0x3:
      if (uVar8 < 6) {
        if ((uVar8 == (byte)dVar11) ||
           (iVar4 = dSv_player_collect_c::isTact
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                               (uchar)dVar11), iVar4 == 0)) {
          if ((bVar7 == 0) || (bVar7 == 1)) {
            local_48[0] = (dMenu_Collect_c)0x2;
            local_48[1] = (dMenu_Collect_c)0x1;
            local_48[2] = (dMenu_Collect_c)0x0;
            iVar4 = 0;
            pdVar9 = local_48;
            do {
              dVar2 = *pdVar9;
              iVar12 = dSv_player_collect_c::isTact
                                 (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect
                                  ,(uchar)dVar2);
              if (iVar12 != 0) {
                bVar3 = true;
                dVar11 = dVar2;
                break;
              }
              iVar4 = iVar4 + 1;
              pdVar9 = pdVar9 + 1;
            } while (iVar4 < 3);
            if (!bVar3) {
              dVar11 = (dMenu_Collect_c)0xe;
            }
          }
          else {
            if ((bVar7 == 5) || (bVar7 == 6)) {
              local_48[0] = (dMenu_Collect_c)0x4;
              local_48[1] = (dMenu_Collect_c)0x5;
              iVar4 = 0;
              pdVar9 = local_48;
              do {
                dVar2 = *pdVar9;
                iVar12 = dSv_player_collect_c::isTact
                                   (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                     mCollect,(uchar)dVar2);
                if (iVar12 != 0) {
                  bVar3 = true;
                  dVar11 = dVar2;
                  break;
                }
                iVar4 = iVar4 + 1;
                pdVar9 = pdVar9 + 1;
              } while (iVar4 < 2);
              if (!bVar3) {
                dVar11 = (dMenu_Collect_c)0xa;
              }
            }
          }
        }
      }
      else {
        local_48[0] = (dMenu_Collect_c)0x3;
        local_48[1] = (dMenu_Collect_c)0x2;
        local_48[2] = (dMenu_Collect_c)0x4;
        local_48[3] = (dMenu_Collect_c)0x1;
        local_44 = 5;
        local_43 = 0;
        iVar4 = 0;
        pdVar9 = local_48;
        do {
          dVar2 = *pdVar9;
          iVar12 = dSv_player_collect_c::isTact
                             (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                              (uchar)dVar2);
          if (iVar12 != 0) {
            bVar3 = true;
            dVar11 = dVar2;
            break;
          }
          iVar4 = iVar4 + 1;
          pdVar9 = pdVar9 + 1;
        } while (iVar4 < 6);
        if (!bVar3) {
          dVar11 = (dMenu_Collect_c)0x13;
        }
      }
      break;
    case (dMenu_Collect_c)0x4:
      if (uVar8 < 6) {
        if ((uVar8 == (byte)dVar11) ||
           (iVar4 = dSv_player_collect_c::isTact
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                               (uchar)dVar11), iVar4 == 0)) {
          if ((bVar7 == 0) || (bVar7 == 1)) {
            local_48[0] = (dMenu_Collect_c)0x3;
            local_48[1] = (dMenu_Collect_c)0x2;
            local_48[2] = (dMenu_Collect_c)0x1;
            local_48[3] = (dMenu_Collect_c)0x0;
            iVar4 = 0;
            pdVar9 = local_48;
            do {
              dVar2 = *pdVar9;
              iVar12 = dSv_player_collect_c::isTact
                                 (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect
                                  ,(uchar)dVar2);
              if (iVar12 != 0) {
                bVar3 = true;
                dVar11 = dVar2;
                break;
              }
              iVar4 = iVar4 + 1;
              pdVar9 = pdVar9 + 1;
            } while (iVar4 < 4);
            if (!bVar3) {
              dVar11 = (dMenu_Collect_c)0xe;
            }
          }
          else {
            if ((bVar7 == 5) || (bVar7 == 6)) {
              local_48[0] = (dMenu_Collect_c)0x5;
              iVar4 = dSv_player_collect_c::isTact
                                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                                 '\x05');
              dVar11 = local_48[0];
              if (iVar4 == 0) {
                dVar11 = (dMenu_Collect_c)0xa;
              }
            }
          }
        }
      }
      else {
        local_48[0] = (dMenu_Collect_c)0x4;
        local_48[1] = (dMenu_Collect_c)0x3;
        local_48[2] = (dMenu_Collect_c)0x5;
        local_48[3] = (dMenu_Collect_c)0x2;
        local_44 = 1;
        local_43 = 0;
        iVar4 = 0;
        pdVar9 = local_48;
        do {
          dVar2 = *pdVar9;
          iVar12 = dSv_player_collect_c::isTact
                             (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                              (uchar)dVar2);
          if (iVar12 != 0) {
            bVar3 = true;
            dVar11 = dVar2;
            break;
          }
          iVar4 = iVar4 + 1;
          pdVar9 = pdVar9 + 1;
        } while (iVar4 < 6);
        if (!bVar3) {
          dVar11 = (dMenu_Collect_c)0x13;
        }
      }
      break;
    case (dMenu_Collect_c)0x5:
      if (uVar8 < 6) {
        if ((uVar8 == (byte)dVar11) ||
           (iVar4 = dSv_player_collect_c::isTact
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                               (uchar)dVar11), iVar4 == 0)) {
          if ((bVar7 == 0) || (bVar7 == 1)) {
            local_48[0] = (dMenu_Collect_c)0x4;
            local_48[1] = (dMenu_Collect_c)0x3;
            local_48[2] = (dMenu_Collect_c)0x2;
            local_48[3] = (dMenu_Collect_c)0x1;
            local_44 = 0;
            iVar4 = 0;
            pdVar9 = local_48;
            do {
              dVar2 = *pdVar9;
              iVar12 = dSv_player_collect_c::isTact
                                 (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect
                                  ,(uchar)dVar2);
              if (iVar12 != 0) {
                bVar3 = true;
                dVar11 = dVar2;
                break;
              }
              iVar4 = iVar4 + 1;
              pdVar9 = pdVar9 + 1;
            } while (iVar4 < 5);
            if (!bVar3) {
              dVar11 = (dMenu_Collect_c)0xe;
            }
          }
          else {
            if ((bVar7 == 5) || (bVar7 == 6)) {
              dVar11 = (dMenu_Collect_c)0xa;
            }
          }
        }
      }
      else {
        local_48[0] = (dMenu_Collect_c)0x5;
        local_48[1] = (dMenu_Collect_c)0x4;
        local_48[2] = (dMenu_Collect_c)0x3;
        local_48[3] = (dMenu_Collect_c)0x2;
        local_44 = 1;
        local_43 = 0;
        iVar4 = 0;
        pdVar9 = local_48;
        do {
          dVar2 = *pdVar9;
          iVar12 = dSv_player_collect_c::isTact
                             (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                              (uchar)dVar2);
          if (iVar12 != 0) {
            bVar3 = true;
            dVar11 = dVar2;
            break;
          }
          iVar4 = iVar4 + 1;
          pdVar9 = pdVar9 + 1;
        } while (iVar4 < 6);
        if (!bVar3) {
          dVar11 = (dMenu_Collect_c)0x13;
        }
      }
      break;
    case (dMenu_Collect_c)0xb:
      if (((uVar8 == 0xb) || (uVar8 == 0xc)) || (uVar8 == 0xd)) {
        if ((uVar8 == (byte)dVar11) ||
           (iVar4 = dSv_player_collect_c::isSymbol
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                               (char)dVar11 - 0xb), iVar4 == 0)) {
          if (bVar7 == 1) {
            dVar11 = (dMenu_Collect_c)0x9;
          }
          else {
            if ((bVar7 == 5) || (bVar7 == 6)) {
              dVar11 = (dMenu_Collect_c)0x11;
            }
            else {
              if ((bVar7 == 0) || (bVar7 == 7)) {
                dVar11 = (dMenu_Collect_c)0xa;
              }
            }
          }
        }
      }
      else {
        local_48[0] = (dMenu_Collect_c)0xb;
        local_48[1] = (dMenu_Collect_c)0xc;
        local_48[2] = (dMenu_Collect_c)0xd;
        iVar4 = 0;
        pdVar9 = local_48;
        do {
          dVar2 = *pdVar9;
          iVar12 = dSv_player_collect_c::isSymbol
                             (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                              (char)dVar2 - 0xb);
          if (iVar12 != 0) {
            bVar3 = true;
            dVar11 = dVar2;
            break;
          }
          iVar4 = iVar4 + 1;
          pdVar9 = pdVar9 + 1;
        } while (iVar4 < 3);
        if (!bVar3) {
          dVar11 = (dMenu_Collect_c)0x14;
        }
      }
      break;
    case (dMenu_Collect_c)0xc:
      if (((uVar8 == 0xb) || (uVar8 == 0xc)) || (uVar8 == 0xd)) {
        if ((uVar8 == (byte)dVar11) ||
           (iVar4 = dSv_player_collect_c::isSymbol
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                               (char)dVar11 - 0xb), iVar4 == 0)) {
          if (bVar7 == 1) {
            dVar11 = (dMenu_Collect_c)0x9;
          }
          else {
            if ((bVar7 == 5) || (bVar7 == 6)) {
              iVar4 = dSv_player_collect_c::isSymbol
                                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                                 '\0');
              dVar11 = (dMenu_Collect_c)0xb;
              if (iVar4 == 0) {
                dVar11 = (dMenu_Collect_c)0x11;
              }
            }
            else {
              if ((bVar7 == 0) || (bVar7 == 7)) {
                iVar4 = dSv_player_collect_c::isSymbol
                                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                    mCollect,'\0');
                dVar11 = (dMenu_Collect_c)0xb;
                if (iVar4 == 0) {
                  dVar11 = (dMenu_Collect_c)0xa;
                }
              }
            }
          }
        }
      }
      else {
        local_48[0] = (dMenu_Collect_c)0xc;
        local_48[1] = (dMenu_Collect_c)0xb;
        local_48[2] = (dMenu_Collect_c)0xd;
        iVar4 = 0;
        pdVar9 = local_48;
        do {
          dVar2 = *pdVar9;
          iVar12 = dSv_player_collect_c::isSymbol
                             (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                              (char)dVar2 - 0xb);
          if (iVar12 != 0) {
            bVar3 = true;
            dVar11 = dVar2;
            break;
          }
          iVar4 = iVar4 + 1;
          pdVar9 = pdVar9 + 1;
        } while (iVar4 < 3);
        if (!bVar3) {
          dVar11 = (dMenu_Collect_c)0x14;
        }
      }
      break;
    case (dMenu_Collect_c)0xd:
      if (((uVar8 == 0xb) || (uVar8 == 0xc)) || (uVar8 == 0xd)) {
        if ((uVar8 == (byte)dVar11) ||
           (iVar4 = dSv_player_collect_c::isSymbol
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                               (char)dVar11 - 0xb), iVar4 == 0)) {
          if (bVar7 == 1) {
            iVar4 = dSv_player_collect_c::isSymbol
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                               '\x01');
            dVar11 = (dMenu_Collect_c)0xc;
            if (iVar4 == 0) {
              dVar11 = (dMenu_Collect_c)0x9;
            }
          }
          else {
            if ((bVar7 == 5) || (bVar7 == 6)) {
              dVar11 = (dMenu_Collect_c)0x11;
            }
            else {
              if ((bVar7 == 0) || (bVar7 == 7)) {
                iVar4 = dSv_player_collect_c::isSymbol
                                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                    mCollect,'\0');
                dVar11 = (dMenu_Collect_c)0xb;
                if (iVar4 == 0) {
                  dVar11 = (dMenu_Collect_c)0x9;
                }
              }
            }
          }
        }
      }
      else {
        local_48[0] = (dMenu_Collect_c)0xd;
        local_48[1] = (dMenu_Collect_c)0xc;
        local_48[2] = (dMenu_Collect_c)0xb;
        iVar4 = 0;
        pdVar9 = local_48;
        do {
          dVar2 = *pdVar9;
          iVar12 = dSv_player_collect_c::isSymbol
                             (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                              (char)dVar2 - 0xb);
          if (iVar12 != 0) {
            bVar3 = true;
            dVar11 = dVar2;
            break;
          }
          iVar4 = iVar4 + 1;
          pdVar9 = pdVar9 + 1;
        } while (iVar4 < 3);
        if (!bVar3) {
          dVar11 = (dMenu_Collect_c)0x14;
        }
      }
    }
  }
  if (dVar11 != (dMenu_Collect_c)0xff) {
    this[0x27ed] = dVar11;
  }
  dVar11 = this[0x27ed];
  if (dVar11 != dVar1) {
    if ((((((byte)dVar11 < 0xe) || (0x12 < (byte)dVar11)) && (0xd < (byte)dVar1)) &&
        ((byte)dVar1 < 0x13)) ||
       ((((byte)dVar1 < 0xe || (0x12 < (byte)dVar1)) &&
        ((0xd < (byte)dVar11 && ((byte)dVar11 < 0x13)))))) {
      *(undefined2 *)(this + 0xa86) = 10;
    }
    tactGuideHide(this);
    if (((byte)this[0x27ed] < 6) &&
       (iVar4 = dSv_player_collect_c::isTact
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                           (uchar)this[0x27ed]), iVar4 != 0)) {
      iVar4 = 0;
      iVar12 = 6;
      do {
        *(undefined2 *)(this + iVar4 + 0x1e6e) = 1;
        iVar4 = iVar4 + 0x38;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
      tactGuideShow(this,(uchar)this[0x27ed],true);
    }
    else {
      tactBaseShow(this);
    }
    *(undefined2 *)(this + 0x88e) = 0;
    itemnameSet(this);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x80e,(cXyz *)0x0,0,0,d_menu_collect::_4440,
               d_menu_collect::_4440,d_menu_collect::_5050,d_menu_collect::_5050,0);
  }
  dVar1 = this[0x27ed];
  if ((byte)dVar1 < 8) {
    cVar6 = collectItemGetCheck(this,(uchar)dVar1);
    if (cVar6 == '\0') {
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
      d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
    }
    else {
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x17;
    }
  }
  else {
    cVar6 = collectItemGetCheck(this,(uchar)dVar1);
    if (cVar6 == '\0') {
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
      d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
    }
    else {
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x21;
    }
  }
  if (*(short *)(this + 0xa86) != 0) {
    dVar15 = (double)d_menu_collect::_5051;
    *(short *)(this + 0xa86) = *(short *)(this + 0xa86) + -1;
    iVar4 = MSL_C.PPCEABI.bare.H::abs(5 - *(short *)(this + 0xa86));
    dVar14 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)(short)(5 - (short)iVar4),0);
    dVar14 = (double)(float)(dVar15 * dVar14);
    mainTrans(this,(float)-dVar14,d_menu_collect::_4288);
    subTrans(this,(float)dVar14,d_menu_collect::_4288);
    if (*(short *)(this + 0xa86) == 5) {
      if (((byte)this[0x27ed] < 0xe) || (0x12 < (byte)this[0x27ed])) {
        collectPriority(this);
      }
      else {
        weponPriority(this);
      }
    }
  }
  __psq_l0(auStack8,uVar13);
  __psq_l1(auStack8,uVar13);
  return iVar10;
}


/* __thiscall dMenu_Collect_c::noteCheck(void) */

uint __thiscall dMenu_Collect_c::noteCheck(dMenu_Collect_c *this)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(1 - *(short *)(this + 0x81e));
  return uVar1 >> 5 & 0xff;
}


/* __thiscall dMenu_Collect_c::noteInit(void) */

void __thiscall dMenu_Collect_c::noteInit(dMenu_Collect_c *this)

{
  double dVar1;
  float fVar2;
  int *piVar3;
  
  *(undefined2 *)(this + 0x81e) = 0;
  *(undefined2 *)(this + 0x7e6) = 0;
  dVar1 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x856) ^ 0x80000000) -
          d_menu_collect::_4443;
  fVar2 = *(float *)(this + 0x848) * d_menu_collect::_4287;
  piVar3 = *(int **)(this + 0x820);
  piVar3[0x27] = (int)(*(float *)(this + 0x844) * d_menu_collect::_4287);
  piVar3[0x28] = (int)fVar2;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)(float)dVar1;
  (**(code **)(*piVar3 + 0x20))();
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x820),(double)d_menu_collect::_4288,
             (double)d_menu_collect::_4288);
  return;
}


/* __thiscall dMenu_Collect_c::noteAppear(void) */

void __thiscall dMenu_Collect_c::noteAppear(dMenu_Collect_c *this)

{
  dMenu_Collect_c dVar1;
  dMenu_Collect_c *pdVar2;
  
  if (*(short *)(this + 0x81e) == 1) {
    if (*(short *)(this + 0x7e6) < 0x12) {
      noteOpen(this);
    }
    else {
      if (*(short *)(this + 0x7e6) < 0x13) {
        this[0x9a5] = (dMenu_Collect_c)0x82;
        this[0x9a4] = (dMenu_Collect_c)0x82;
        if (this[0x27eb] != (dMenu_Collect_c)0x0) {
          pdVar2 = this + *(short *)(this + 0x27e0) * 0x38;
          dVar1 = (dMenu_Collect_c)
                  fopMsgM_msgDataProc_c::selectCheckYoko
                            ((fopMsgM_msgDataProc_c *)(this + 0x24e0),*(J2DPane **)(pdVar2 + 0xb0),
                             (int)*(float *)(pdVar2 + 0xcc),(int)*(float *)(pdVar2 + 0xd0),
                             (int)(*(float *)(pdVar2 + 0xbc) - *(float *)(pdVar2 + 0xcc)));
          this[0x27f0] = dVar1;
          if (this[0x27f0] != this[0x27f1]) {
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x83d,(cXyz *)0x0,0,0,d_menu_collect::_4440,
                       d_menu_collect::_4440,d_menu_collect::_5050,d_menu_collect::_5050,0);
            this[0x27f1] = this[0x27f0];
          }
        }
        if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
          if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
            *(short *)(this + 0x7e6) = *(short *)(this + 0x7e6) + 1;
            if (this[0x27ed] == (dMenu_Collect_c)0x12) {
              JAIZelBasic::seStart
                        (JAIZelBasic::zel_basic,0x84b,(cXyz *)0x0,0,0,d_menu_collect::_4440,
                         d_menu_collect::_4440,d_menu_collect::_5050,d_menu_collect::_5050,0);
            }
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x816,(cXyz *)0x0,0,0,d_menu_collect::_4440,
                       d_menu_collect::_4440,d_menu_collect::_5050,d_menu_collect::_5050,0);
          }
        }
        else {
          if (this[0x27ed] == (dMenu_Collect_c)0x12) {
            if (this[0x27f0] == (dMenu_Collect_c)0x0) {
              dSv_player_collect_c::onCollect
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,4,1);
              JAIZelBasic::seStart
                        (JAIZelBasic::zel_basic,0x8b7,(cXyz *)0x0,0,0,d_menu_collect::_4440,
                         d_menu_collect::_4440,d_menu_collect::_5050,d_menu_collect::_5050,0);
            }
            else {
              dSv_player_collect_c::offCollect
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,4,'\x01'
                        );
              JAIZelBasic::seStart
                        (JAIZelBasic::zel_basic,0x8b8,(cXyz *)0x0,0,0,d_menu_collect::_4440,
                         d_menu_collect::_4440,d_menu_collect::_5050,d_menu_collect::_5050,0);
            }
          }
          *(short *)(this + 0x7e6) = *(short *)(this + 0x7e6) + 1;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x816,(cXyz *)0x0,0,0,d_menu_collect::_4440,
                     d_menu_collect::_4440,d_menu_collect::_5050,d_menu_collect::_5050,0);
        }
      }
      else {
        noteClose(this);
      }
    }
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x8019ea74) */
/* WARNING: Removing unreachable block (ram,0x8019ea6c) */
/* WARNING: Removing unreachable block (ram,0x8019ea7c) */
/* __thiscall dMenu_Collect_c::noteOpen(void) */

void __thiscall dMenu_Collect_c::noteOpen(dMenu_Collect_c *this)

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
  dVar9 = (double)(d_menu_collect::_5148 - *(float *)(this + 0x834));
  dVar8 = (double)(d_menu_collect::_5149 - *(float *)(this + 0x838));
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x11,0x11 - *(short *)(this + 0x7e6),0);
  dVar7 = (double)(float)((double)d_menu_collect::_4440 - dVar6);
  if (*(short *)(this + 0x7e6) < 0x11) {
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)(this + 0x970),(float)((double)d_menu_collect::_4440 - dVar6));
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x740),(float)dVar7);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x778),(float)dVar7);
  }
  else {
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x970);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x740);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x778);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x814,(cXyz *)0x0,0,0,d_menu_collect::_4440,
               d_menu_collect::_4440,d_menu_collect::_5050,d_menu_collect::_5050,0);
  }
  dVar6 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x856) ^ 0x80000000) -
          d_menu_collect::_4443;
  dVar1 = (double)CONCAT44(0x43300000,-(int)*(short *)(this + 0x856) - 3U ^ 0x80000000) -
          d_menu_collect::_4443;
  fVar2 = *(float *)(this + 0x850) * d_menu_collect::_4287;
  piVar4 = *(int **)(this + 0x820);
  piVar4[0x27] = (int)(*(float *)(this + 0x84c) * d_menu_collect::_4287);
  piVar4[0x28] = (int)fVar2;
  *(undefined *)(piVar4 + 0x2a) = 0x7a;
  piVar4[0x29] = (int)((float)dVar6 + (float)(dVar7 * (double)(float)dVar1));
  (**(code **)(*piVar4 + 0x20))();
  uVar3 = SEXT24(*(short *)(this + 0x7e6));
  if ((int)uVar3 < 5) {
    fVar2 = (d_menu_collect::_5150 *
            (float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - d_menu_collect::_4443)) /
            d_menu_collect::_5151;
  }
  else {
    dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0xc,0x11 - uVar3,0);
    fVar2 = d_menu_collect::_5150 +
            d_menu_collect::_5152 * (float)((double)d_menu_collect::_4440 - dVar6);
  }
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x820),(double)(float)(dVar9 * (double)fVar2),
             (double)(float)(dVar8 * (double)fVar2));
  *(short *)(this + 0x7e6) = *(short *)(this + 0x7e6) + 1;
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8019eca4) */
/* WARNING: Removing unreachable block (ram,0x8019ec94) */
/* WARNING: Removing unreachable block (ram,0x8019ec8c) */
/* WARNING: Removing unreachable block (ram,0x8019ec9c) */
/* WARNING: Removing unreachable block (ram,0x8019ecac) */
/* __thiscall dMenu_Collect_c::noteClose(void) */

void __thiscall dMenu_Collect_c::noteClose(dMenu_Collect_c *this)

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
  dVar8 = (double)((d_menu_collect::_5177 - *(float *)(this + 0x834)) - d_menu_collect::_5148);
  dVar7 = (double)((d_menu_collect::_5178 - *(float *)(this + 0x838)) - d_menu_collect::_5149);
  dVar6 = (double)(d_menu_collect::_5148 - *(float *)(this + 0x834));
  dVar5 = (double)(d_menu_collect::_5149 - *(float *)(this + 0x838));
  dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,*(short *)(this + 0x7e6) + -0x12,0);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x820),
             (double)(float)(dVar6 + (double)(float)(dVar8 * dVar4)),
             (double)(float)(dVar5 + (double)(float)(dVar7 * dVar4)));
  fVar1 = *(float *)(this + 0x850) * d_menu_collect::_4287;
  piVar2 = *(int **)(this + 0x820);
  piVar2[0x27] = (int)(*(float *)(this + 0x84c) * d_menu_collect::_4287);
  piVar2[0x28] = (int)fVar1;
  *(undefined *)(piVar2 + 0x2a) = 0x7a;
  piVar2[0x29] = (int)(d_menu_collect::_5179 + (float)((double)d_menu_collect::_5180 * dVar4));
  (**(code **)(*piVar2 + 0x20))();
  *(short *)(this + 0x7e6) = *(short *)(this + 0x7e6) + 1;
  if (*(short *)(this + 0x7e6) < 0x1d) {
    dVar5 = (double)(float)((double)d_menu_collect::_4440 - dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)(this + 0x7b0),(float)((double)d_menu_collect::_4440 - dVar4));
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x7e8),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x820),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x970),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x740),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x778),(float)dVar5);
  }
  else {
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x7b0);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x7e8);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x820);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x970));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x740));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x778));
    *(undefined2 *)(this + 0x81e) = 0;
    *(undefined2 *)(this + 0x7e6) = 0;
    dVar4 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x856) ^ 0x80000000) -
            d_menu_collect::_4443;
    fVar1 = *(float *)(this + 0x850) * d_menu_collect::_4287;
    piVar2 = *(int **)(this + 0x820);
    piVar2[0x27] = (int)(*(float *)(this + 0x84c) * d_menu_collect::_4287);
    piVar2[0x28] = (int)fVar1;
    *(undefined *)(piVar2 + 0x2a) = 0x7a;
    piVar2[0x29] = (int)(float)dVar4;
    (**(code **)(*piVar2 + 0x20))();
    noteInit(this);
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


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMenu_Collect_c::mainTrans(float,
                                         float) */

void __thiscall dMenu_Collect_c::mainTrans(dMenu_Collect_c *this,float param_1,float param_2)

{
  int iVar1;
  int iVar2;
  dMenu_Collect_c *pdVar3;
  int iVar4;
  double x;
  double y;
  
  y = (double)param_2;
  x = (double)param_1;
  iVar2 = 0;
  iVar4 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar4 + 0xa18),x,y);
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar2 < 4);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0xaf8),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0xb30),x,y);
  iVar2 = 0;
  iVar4 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar4 + 0xb68),x,y);
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar2 < 4);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0xc48),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0xc80),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0xcb8),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0xcf0),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0xd28),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0xd60),x,y);
  iVar2 = 0;
  iVar4 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar4 + 0xe08),x,y);
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar2 < 8);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0xfc8),x,y);
  iVar2 = 0;
  iVar4 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar4 + 0x1000),x,y);
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar4 + 0x10a8),x,y);
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar2 < 3);
  iVar2 = 0;
  iVar4 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar4 + 0x1150),x,y);
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar2 < 0xb);
  iVar2 = 0;
  iVar4 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar4 + 0x13b8),x,y);
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar2 < 3);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x1460),x,y);
  iVar2 = 0;
  iVar4 = 0;
  do {
    pdVar3 = this + iVar4;
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(pdVar3 + 0x1498),x,y);
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(pdVar3 + 0x15e8),x,y);
    if ((((byte)this[0x27ed] < 6) &&
        (iVar1 = dSv_player_collect_c::isTact
                           (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                            (uchar)this[0x27ed]), iVar1 != 0)) &&
       (this[0x27ee] != (dMenu_Collect_c)0x5)) {
      tactTrans(this,(uchar)this[0x27ed],(float)x,(float)y);
    }
    else {
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(pdVar3 + 0x17a8),x,y);
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(pdVar3 + 0x18f8),x,y);
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(pdVar3 + 0x1a48),x,y);
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(pdVar3 + 0x1b98),x,y);
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(pdVar3 + 0x1ce8),x,y);
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(pdVar3 + 0x1e38),x,y);
    }
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar2 < 6);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x1738),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 6000),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x1ff8),x,y);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_Collect_c::subTrans(float,
                                        float) */

void __thiscall dMenu_Collect_c::subTrans(dMenu_Collect_c *this,float param_1,float param_2)

{
  int iVar1;
  dMenu_Collect_c *pdVar2;
  int iVar3;
  double x;
  double y;
  
  y = (double)param_2;
  x = (double)param_1;
  iVar1 = 0;
  iVar3 = 0;
  do {
    pdVar2 = this + iVar3;
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(pdVar2 + 0x2030),x,y);
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(pdVar2 + 0x2148),x,y);
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(pdVar2 + 0x2260),x,y);
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 5);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x2378),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x2420),x,y);
  return;
}


/* __thiscall dMenu_Collect_c::titleTrans(float,
                                          float) */

void __thiscall dMenu_Collect_c::titleTrans(dMenu_Collect_c *this,float param_1,float param_2)

{
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x9e0),(double)param_1,(double)param_2);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8019f128) */
/* __thiscall dMenu_Collect_c::noteRotate(float,
                                          float) */

void __thiscall dMenu_Collect_c::noteRotate(dMenu_Collect_c *this,float param_1,float param_2)

{
  float fVar1;
  int *piVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar4 = (double)param_2;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x820),(double)d_menu_collect::_4288,(double)param_1);
  fVar1 = *(float *)(this + 0x850) * d_menu_collect::_4287;
  piVar2 = *(int **)(this + 0x820);
  piVar2[0x27] = (int)(*(float *)(this + 0x84c) * d_menu_collect::_4287);
  piVar2[0x28] = (int)fVar1;
  *(undefined *)(piVar2 + 0x2a) = 0x7a;
  piVar2[0x29] = (int)(float)dVar4;
  (**(code **)(*piVar2 + 0x20))();
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8019f1a4) */
/* WARNING: Removing unreachable block (ram,0x8019f1ac) */
/* __thiscall dMenu_Collect_c::nameTrans(float,
                                         float) */

void __thiscall dMenu_Collect_c::nameTrans(dMenu_Collect_c *this,float param_1,float param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  double x;
  double y;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  y = (double)param_2;
  x = (double)param_1;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x858),x,y);
  uVar1 = *(undefined4 *)(this + 0x868);
  iVar2 = *(int *)(this + 0x2460);
  *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(this + 0x864);
  *(undefined4 *)(iVar2 + 0x34) = uVar1;
  dDlst_2DOutFont_c::move(*(dDlst_2DOutFont_c **)(this + 0x2460));
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x938),x,y);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8019f47c) */
/* __thiscall dMenu_Collect_c::mainOpenProc(short,
                                            short,
                                            short) */

void __thiscall
dMenu_Collect_c::mainOpenProc(dMenu_Collect_c *this,short param_1,short param_2,short param_3)

{
  int iVar1;
  dMenu_Collect_c *pdVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar1 = (int)param_2;
  iVar3 = (int)param_1;
  if (iVar3 <= iVar1) {
    dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar1,iVar3,0);
    dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar1,iVar1 - iVar3,0);
    mainTrans(this,(float)((double)(float)((double)CONCAT44(0x43300000,(int)param_3 ^ 0x80000000) -
                                          d_menu_collect::_4443) * dVar6),d_menu_collect::_4288);
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar3 + 0xa18),(float)dVar5);
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xaf8),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xb30),(float)dVar5);
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar3 + 0xb68),(float)dVar5);
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xc48),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xc80),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xcb8),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xcf0),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xd28),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xd60),(float)dVar5);
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar3 + 0xe08),(float)dVar5);
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 8);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xfc8),(float)dVar5);
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x1000),(float)dVar5);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x10a8),(float)dVar5);
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 3);
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x1150),(float)dVar5);
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 0xb);
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x13b8),(float)dVar5);
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 3);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1460),(float)dVar5);
    iVar1 = 0;
    iVar3 = 0;
    do {
      pdVar2 = this + iVar3;
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0x1498),(float)dVar5);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0x15e8),(float)dVar5);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0x17a8),(float)dVar5);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0x18f8),(float)dVar5);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0x1a48),(float)dVar5);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0x1b98),(float)dVar5);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0x1ce8),(float)dVar5);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0x1e38),(float)dVar5);
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 6);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1738),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 6000),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1f88),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1fc0),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1ff8),(float)dVar5);
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8019f594) */
/* __thiscall dMenu_Collect_c::subOpenProc(short,
                                           short,
                                           short) */

void __thiscall
dMenu_Collect_c::subOpenProc(dMenu_Collect_c *this,short param_1,short param_2,short param_3)

{
  int iVar1;
  dMenu_Collect_c *pdVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar1 = (int)param_2;
  iVar3 = (int)param_1;
  if (iVar3 <= iVar1) {
    dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar1,iVar3,0);
    dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar1,iVar1 - iVar3,0);
    subTrans(this,(float)((double)(float)((double)CONCAT44(0x43300000,(int)param_3 ^ 0x80000000) -
                                         d_menu_collect::_4443) * dVar6),d_menu_collect::_4288);
    iVar1 = 0;
    iVar3 = 0;
    do {
      pdVar2 = this + iVar3;
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0x2030),(float)dVar5);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0x2148),(float)dVar5);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0x2260),(float)dVar5);
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2378),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x23b0),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x23e8),(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2420),(float)dVar5);
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_Collect_c::titleOpenProc(short,
                                             short) */

void __thiscall dMenu_Collect_c::titleOpenProc(dMenu_Collect_c *this,short param_1,short param_2)

{
  int iVar1;
  int iVar2;
  double dVar3;
  
  iVar1 = (int)param_2;
  iVar2 = (int)param_1;
  if (iVar2 <= iVar1) {
    f_op_msg_mng::fopMsgM_valueIncrease(iVar1,iVar2,0);
    dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar1,iVar1 - iVar2,0);
    titleTrans(this,d_menu_collect::_4288,(float)((double)d_menu_collect::_5339 * dVar3));
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x9a8);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x9e0);
    if (iVar2 == 1) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x811,(cXyz *)0x0,0,0,d_menu_collect::_4440,
                 d_menu_collect::_4440,d_menu_collect::_5050,d_menu_collect::_5050,0);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Collect_c::noteOpenProc(short,
                                            short) */

void __thiscall dMenu_Collect_c::noteOpenProc(dMenu_Collect_c *this,short param_1,short param_2)

{
  int iVar1;
  int iVar2;
  double dVar3;
  
  iVar1 = (int)param_2;
  iVar2 = (int)param_1;
  if (iVar2 <= iVar1) {
    f_op_msg_mng::fopMsgM_valueIncrease(iVar1,iVar2,0);
    dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar1,iVar1 - iVar2,0);
    noteRotate(this,(float)((double)d_menu_collect::_5351 * dVar3),
               (float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x856) ^ 0x80000000) -
                      d_menu_collect::_4443) +
               (float)(dVar3 * (double)(float)((double)CONCAT44(0x43300000,
                                                                0x2dU - (int)*(short *)(this + 0x856
                                                                                       ) ^
                                                                0x80000000) - d_menu_collect::_4443)
                      ));
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x7b0);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x7e8);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Collect_c::nameOpenProc(short,
                                            short) */

void __thiscall dMenu_Collect_c::nameOpenProc(dMenu_Collect_c *this,short param_1,short param_2)

{
  int iVar1;
  int iVar2;
  double dVar3;
  
  iVar1 = (int)param_2;
  iVar2 = (int)param_1;
  if (iVar2 <= iVar1) {
    f_op_msg_mng::fopMsgM_valueIncrease(iVar1,iVar2,0);
    dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar1,iVar1 - iVar2,0);
    nameTrans(this,d_menu_collect::_4288,(float)((double)d_menu_collect::_5363 * dVar3));
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x890);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x900);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x938);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dMenu_Collect_c::itemBitCheck(void) */

void __thiscall dMenu_Collect_c::itemBitCheck(dMenu_Collect_c *this)

{
  double dVar1;
  float fVar2;
  int iVar3;
  dMenu_Collect_c dVar5;
  uint uVar4;
  dMenu_Collect_c *pdVar6;
  int iVar7;
  uchar *puVar8;
  int iVar9;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64 [5];
  undefined4 local_50;
  undefined4 local_3c;
  undefined4 local_38;
  uint uStack52;
  undefined4 local_30;
  uint uStack44;
  
  iVar9 = 0;
  iVar7 = 0;
  do {
    iVar3 = dSv_player_collect_c::isTact
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                       (&d_menu_collect::melody_5367)[iVar9]);
    if (iVar3 == 0) {
      *(undefined *)(*(int *)(this + iVar7 + 0x1498) + 0xaa) = 0;
      *(undefined *)(*(int *)(this + iVar7 + 0x15e8) + 0xaa) = 0;
      if (iVar9 == 3) {
        *(undefined *)(*(int *)(this + 0x1738) + 0xaa) = 0;
      }
      else {
        if (iVar9 == 4) {
          *(undefined *)(*(int *)(this + 6000) + 0xaa) = 0;
        }
      }
    }
    else {
      *(undefined *)(*(int *)(this + iVar7 + 0x1498) + 0xaa) = 1;
      *(undefined *)(*(int *)(this + iVar7 + 0x15e8) + 0xaa) = 1;
      if (iVar9 == 3) {
        *(undefined *)(*(int *)(this + 0x1738) + 0xaa) = 1;
      }
      else {
        if (iVar9 == 4) {
          *(undefined *)(*(int *)(this + 6000) + 0xaa) = 1;
        }
      }
    }
    iVar9 = iVar9 + 1;
    iVar7 = iVar7 + 0x38;
  } while (iVar9 < 6);
  iVar9 = 0;
  iVar7 = 0;
  iVar3 = 3;
  do {
    if (iVar9 < (int)((ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                              mMaxHp & 3)) {
      *(undefined *)(*(int *)(this + iVar7 + 0x13b8) + 0xaa) = 1;
    }
    else {
      *(undefined *)(*(int *)(this + iVar7 + 0x13b8) + 0xaa) = 0;
    }
    iVar9 = iVar9 + 1;
    iVar7 = iVar7 + 0x38;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar7 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x908);
  if ((iVar7 == 0) &&
     (iVar7 = dSv_player_map_c::getCollectMapNum
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap), iVar7 == 0
     )) {
    *(undefined *)(*(int *)(this + 0xc48) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + 0xc80) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + 0xcb8) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + 0xcf0) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + 0xd28) + 0xaa) = 0;
  }
  else {
    *(undefined *)(*(int *)(this + 0xc48) + 0xaa) = 1;
    *(undefined *)(*(int *)(this + 0xc80) + 0xaa) = 1;
    *(undefined *)(*(int *)(this + 0xcb8) + 0xaa) = 1;
    *(undefined *)(*(int *)(this + 0xcf0) + 0xaa) = 1;
    *(undefined *)(*(int *)(this + 0xd28) + 0xaa) = 1;
  }
  dVar5 = (dMenu_Collect_c)
          dSv_player_collect_c::getTriforceNum
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect);
  this[0x27f3] = dVar5;
  if (((byte)this[0x27f3] == 8) && (this[0x27ee] != (dMenu_Collect_c)0x5)) {
    if (*(short *)(this + 0xf1e) != 8) {
      iVar9 = 0;
      iVar7 = 0;
      iVar3 = 8;
      do {
        if (iVar9 == 4) {
          *(undefined *)(*(int *)(this + iVar7 + 0xe08) + 0xaa) = 1;
        }
        else {
          *(undefined *)(*(int *)(this + iVar7 + 0xe08) + 0xaa) = 0;
        }
        iVar9 = iVar9 + 1;
        iVar7 = iVar7 + 0x38;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      J2DPicture::changeTexture(*(J2DPicture **)(this + 0xee8),"triforce.bti",0);
      iVar7 = JKRArchive::getGlbResource(0x54494d47,"triforce.bti",*(JKRArchive **)(this + 0x2464));
      *(undefined4 *)(this + 0xefc) = *(undefined4 *)(this + 0xfdc);
      *(undefined4 *)(this + 0xf00) = *(undefined4 *)(this + 0xfe0);
      *(undefined4 *)(this + 0xf04) = *(undefined4 *)(this + 0xfe4);
      *(undefined4 *)(this + 0xf08) = *(undefined4 *)(this + 0xfe8);
      fVar2 = d_menu_collect::_5660;
      dVar1 = d_menu_collect::_4290;
      uStack52 = (uint)*(ushort *)(iVar7 + 2);
      local_38 = 0x43300000;
      *(float *)(this + 0xf14) =
           d_menu_collect::_5660 *
           (float)((double)CONCAT44(0x43300000,uStack52) - d_menu_collect::_4290);
      uStack44 = (uint)*(ushort *)(iVar7 + 4);
      local_30 = 0x43300000;
      *(float *)(this + 0xf18) = fVar2 * (float)((double)CONCAT44(0x43300000,uStack44) - dVar1);
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(this + 0xee8));
      *(ushort *)(this + 0xf1e) = (ushort)(byte)this[0x27f3];
    }
  }
  else {
    if ((ushort)(byte)this[0x27f3] != *(ushort *)(this + 0xf1e)) {
      JKRArchive::readTypeResource
                (*(void **)(this + 0x24b0),0xc00,0x54494d47,"triforce_04.bti",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
      os::DCStoreRangeNoSync(*(undefined4 *)(this + 0x24b0),0xc00);
      J2DPicture::changeTexture(*(J2DPicture **)(this + 0xee8),*(ResTIMG **)(this + 0x24b0),'\0');
      *(float *)(this + 0xefc) = *(float *)(this + 0xfdc) - *(float *)(this + 0x27a8);
      *(float *)(this + 0xf00) = *(float *)(this + 0xfe0) - *(float *)(this + 0x27ac);
      *(float *)(this + 0xf04) = *(float *)(this + 0xfe4) - *(float *)(this + 0x27a8);
      *(float *)(this + 0xf08) = *(float *)(this + 0xfe8) - *(float *)(this + 0x27ac);
      *(undefined4 *)(this + 0xf14) = *(undefined4 *)(this + 0xf0c);
      *(undefined4 *)(this + 0xf18) = *(undefined4 *)(this + 0xf10);
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(this + 0xee8));
    }
    iVar7 = 0;
    iVar9 = 0;
    puVar8 = "";
    do {
      iVar3 = dSv_player_collect_c::isTriforce
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,*puVar8)
      ;
      if (iVar3 == 0) {
        *(undefined *)(*(int *)(this + iVar9 + 0xe08) + 0xaa) = 0;
      }
      else {
        *(undefined *)(*(int *)(this + iVar9 + 0xe08) + 0xaa) = 1;
      }
      iVar7 = iVar7 + 1;
      iVar9 = iVar9 + 0x38;
      puVar8 = puVar8 + 1;
    } while (iVar7 < 8);
    *(ushort *)(this + 0xf1e) = (ushort)(byte)this[0x27f3];
  }
  iVar7 = 0;
  iVar9 = 0;
  do {
    iVar3 = dSv_player_collect_c::isSymbol
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                       (&d_menu_collect::symbol_5369)[iVar7]);
    if (iVar3 == 0) {
      *(undefined *)(*(int *)(this + iVar9 + 0x1000) + 0xaa) = 0;
      *(undefined *)(*(int *)(this + iVar9 + 0x10a8) + 0xaa) = 0;
    }
    else {
      *(undefined *)(*(int *)(this + iVar9 + 0x1000) + 0xaa) = 1;
      *(undefined *)(*(int *)(this + iVar9 + 0x10a8) + 0xaa) = 1;
    }
    iVar7 = iVar7 + 1;
    iVar9 = iVar9 + 0x38;
  } while (iVar7 < 3);
  iVar7 = 0;
  iVar9 = 0;
  do {
    uVar4 = dSv_player_collect_c::isCollect
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                       (uint)(byte)(&d_menu_collect::collect_5370)[iVar7],0);
    if ((((uVar4 == 0) &&
         (uVar4 = dSv_player_collect_c::isCollect
                            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                             (uint)(byte)(&d_menu_collect::collect_5370)[iVar7],1), uVar4 == 0)) &&
        (uVar4 = dSv_player_collect_c::isCollect
                           (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                            (uint)(byte)(&d_menu_collect::collect_5370)[iVar7],2), uVar4 == 0)) &&
       (uVar4 = dSv_player_collect_c::isCollect
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                           (uint)(byte)(&d_menu_collect::collect_5370)[iVar7],3), uVar4 == 0)) {
      pdVar6 = this + iVar9;
      *(undefined *)(*(int *)(pdVar6 + 0x2030) + 0xaa) = 0;
      *(undefined *)(*(int *)(pdVar6 + 0x2148) + 0xaa) = 0;
      *(undefined *)(*(int *)(pdVar6 + 0x2260) + 0xaa) = 0;
    }
    else {
      pdVar6 = this + iVar9;
      *(undefined *)(*(int *)(pdVar6 + 0x2030) + 0xaa) = 1;
      *(undefined *)(*(int *)(pdVar6 + 0x2148) + 0xaa) = 1;
      *(undefined *)(*(int *)(pdVar6 + 0x2260) + 0xaa) = 1;
    }
    iVar7 = iVar7 + 1;
    iVar9 = iVar9 + 0x38;
  } while (iVar7 < 5);
  uVar4 = dSv_player_collect_c::isCollect
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,4,0);
  if ((uVar4 == 0) ||
     (uVar4 = dSv_player_collect_c::isCollect
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,4,1),
     uVar4 != 0)) {
    local_50 = 0xffb400ff;
    local_74 = 0xffb400ff;
    local_78 = 0xffb400ff;
    local_7c = 0xffb400ff;
    local_80 = 0xffb400ff;
    J2DWindow::setContentsColor
              (*(J2DWindow **)(this + 0x2340),(TColor)&local_80,(TColor)&local_7c,(TColor)&local_78,
               (TColor)&local_74);
    iVar7 = *(int *)(this + 0x2340);
    *(undefined *)(iVar7 + 0x104) = 0xff;
    *(undefined *)(iVar7 + 0x105) = 0xb4;
    *(undefined *)(iVar7 + 0x106) = 0;
    *(undefined *)(iVar7 + 0x107) = 0xff;
    iVar7 = *(int *)(this + 0x2340);
    *(undefined *)(iVar7 + 0x108) = 0x50;
    *(undefined *)(iVar7 + 0x109) = 0x50;
    *(undefined *)(iVar7 + 0x10a) = 0;
    *(undefined *)(iVar7 + 0x10b) = 0;
  }
  else {
    local_3c = 0x505000ff;
    local_64[0] = 0x505000ff;
    local_68 = 0x505000ff;
    local_6c = 0x505000ff;
    local_70 = 0x505000ff;
    J2DWindow::setContentsColor
              (*(J2DWindow **)(this + 0x2340),(TColor)&local_70,(TColor)&local_6c,(TColor)&local_68,
               (TColor)local_64);
    iVar7 = *(int *)(this + 0x2340);
    *(undefined *)(iVar7 + 0x104) = 0x50;
    *(undefined *)(iVar7 + 0x105) = 0x50;
    *(undefined *)(iVar7 + 0x106) = 0x50;
    *(undefined *)(iVar7 + 0x107) = 0xff;
    iVar7 = *(int *)(this + 0x2340);
    *(undefined *)(iVar7 + 0x108) = 0x50;
    *(undefined *)(iVar7 + 0x109) = 0x50;
    *(undefined *)(iVar7 + 0x10a) = 0x50;
    *(undefined *)(iVar7 + 0x10b) = 0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dMenu_Collect_c::itemScale(void) */

void __thiscall dMenu_Collect_c::itemScale(dMenu_Collect_c *this)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = (uint)(byte)this[0x27ed];
  uVar4 = 0;
  iVar3 = 0;
  do {
    if (uVar4 != 10) {
      if ((int)uVar4 < 10) {
        if ((int)uVar4 < 6) {
          if (-1 < (int)uVar4) {
            if (uVar4 == uVar5) {
              f_op_msg_mng::fopMsgM_paneScaleXY
                        ((fopMsgM_pane_class *)(this + iVar3 + 0x1498),DAT_803e6a74);
              f_op_msg_mng::fopMsgM_paneScaleXY
                        ((fopMsgM_pane_class *)(this + iVar3 + 0x15e8),DAT_803e6a74);
            }
            else {
              f_op_msg_mng::fopMsgM_paneScaleXY
                        ((fopMsgM_pane_class *)(this + iVar3 + 0x1498),d_menu_collect::_4440);
              f_op_msg_mng::fopMsgM_paneScaleXY
                        ((fopMsgM_pane_class *)(this + iVar3 + 0x15e8),d_menu_collect::_4440);
            }
            if (uVar5 == 3) {
              J2DPane::insertChild
                        (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x1498),
                         *(J2DPane **)(this + 0x1738));
              f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(this + 0x1738),DAT_803e6a74);
              piVar2 = *(int **)(this + 0x1738);
              fVar1 = *(float *)(this + 0x1768) * d_menu_collect::_4287;
              piVar2[0x27] = (int)(*(float *)(this + 0x1764) * d_menu_collect::_4287);
              piVar2[0x28] = (int)fVar1;
              *(undefined *)(piVar2 + 0x2a) = 0x7a;
              (**(code **)(*piVar2 + 0x20))();
            }
            else {
              J2DPane::insertChild
                        (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x1700),
                         *(J2DPane **)(this + 0x1738));
              f_op_msg_mng::fopMsgM_paneScaleXY
                        ((fopMsgM_pane_class *)(this + 0x1738),d_menu_collect::_4440);
              piVar2 = *(int **)(this + 0x1738);
              fVar1 = *(float *)(this + 0x1768) * d_menu_collect::_4287;
              piVar2[0x27] = (int)(*(float *)(this + 0x1764) * d_menu_collect::_4287);
              piVar2[0x28] = (int)fVar1;
              *(undefined *)(piVar2 + 0x2a) = 0x7a;
              (**(code **)(*piVar2 + 0x20))();
            }
            if (uVar5 == 4) {
              J2DPane::insertChild
                        (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x1498),
                         *(J2DPane **)(this + 6000));
              f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(this + 6000),DAT_803e6a74);
              piVar2 = *(int **)(this + 6000);
              fVar1 = *(float *)(this + 0x17a0) * d_menu_collect::_4287;
              piVar2[0x27] = (int)(*(float *)(this + 0x179c) * d_menu_collect::_4287);
              piVar2[0x28] = (int)fVar1;
              *(undefined *)(piVar2 + 0x2a) = 0x7a;
              (**(code **)(*piVar2 + 0x20))();
            }
            else {
              J2DPane::insertChild
                        (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x1700),
                         *(J2DPane **)(this + 6000));
              f_op_msg_mng::fopMsgM_paneScaleXY
                        ((fopMsgM_pane_class *)(this + 6000),d_menu_collect::_4440);
              piVar2 = *(int **)(this + 6000);
              fVar1 = *(float *)(this + 0x17a0) * d_menu_collect::_4287;
              piVar2[0x27] = (int)(*(float *)(this + 0x179c) * d_menu_collect::_4287);
              piVar2[0x28] = (int)fVar1;
              *(undefined *)(piVar2 + 0x2a) = 0x7a;
              (**(code **)(*piVar2 + 0x20))();
            }
          }
        }
        else {
          if (8 < (int)uVar4) {
            if (uVar4 == uVar5) {
              f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(this + 0xcf0),DAT_803e6a74);
              f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(this + 0xcf0),DAT_803e6a74);
            }
            else {
              f_op_msg_mng::fopMsgM_paneScaleXY
                        ((fopMsgM_pane_class *)(this + 0xcf0),d_menu_collect::_4440);
              f_op_msg_mng::fopMsgM_paneScaleXY
                        ((fopMsgM_pane_class *)(this + 0xcf0),d_menu_collect::_4440);
            }
          }
        }
      }
      else {
        if ((int)uVar4 < 0x13) {
          if ((int)uVar4 < 0xe) {
            if (uVar4 == uVar5) {
              f_op_msg_mng::fopMsgM_paneScaleXY
                        ((fopMsgM_pane_class *)(this + (uVar4 - 0xb) * 0x38 + 0x1000),DAT_803e6a74);
              f_op_msg_mng::fopMsgM_paneScaleXY
                        ((fopMsgM_pane_class *)(this + (uVar4 - 0xb) * 0x38 + 0x10a8),DAT_803e6a74);
            }
            else {
              f_op_msg_mng::fopMsgM_paneScaleXY
                        ((fopMsgM_pane_class *)(this + (uVar4 - 0xb) * 0x38 + 0x1000),
                         d_menu_collect::_4440);
              f_op_msg_mng::fopMsgM_paneScaleXY
                        ((fopMsgM_pane_class *)(this + (uVar4 - 0xb) * 0x38 + 0x10a8),
                         d_menu_collect::_4440);
            }
          }
          else {
            if (uVar4 == uVar5) {
              f_op_msg_mng::fopMsgM_paneScaleXY
                        ((fopMsgM_pane_class *)(this + (uVar4 - 0xe) * 0x38 + 0x2030),DAT_803e6a74);
              f_op_msg_mng::fopMsgM_paneScaleXY
                        ((fopMsgM_pane_class *)(this + (uVar4 - 0xe) * 0x38 + 0x2148),DAT_803e6a74);
            }
            else {
              f_op_msg_mng::fopMsgM_paneScaleXY
                        ((fopMsgM_pane_class *)(this + (uVar4 - 0xe) * 0x38 + 0x2030),
                         d_menu_collect::_4440);
              f_op_msg_mng::fopMsgM_paneScaleXY
                        ((fopMsgM_pane_class *)(this + (uVar4 - 0xe) * 0x38 + 0x2148),
                         d_menu_collect::_4440);
            }
          }
        }
      }
    }
    uVar4 = uVar4 + 1;
    iVar3 = iVar3 + 0x38;
  } while ((int)uVar4 < 0x15);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Collect_c::collectPriority(void) */

void __thiscall dMenu_Collect_c::collectPriority(dMenu_Collect_c *this)

{
  int iVar1;
  int iVar2;
  
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0xa18),*(J2DPane **)(this + 0xaf8));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0xaf8),*(J2DPane **)(this + 0xb30));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0xb30),*(J2DPane **)(this + 0xc10));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0xc10),*(J2DPane **)(this + 0xbd8));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0xbd8),*(J2DPane **)(this + 0xba0));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0xba0),*(J2DPane **)(this + 0xb68));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0xb68),*(J2DPane **)(this + 0xc48));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0xc48),*(J2DPane **)(this + 0xc80));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0xc80),*(J2DPane **)(this + 0xcb8));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0xcb8),*(J2DPane **)(this + 0xcf0));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0xcf0),*(J2DPane **)(this + 0xd28));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0xd28),*(J2DPane **)(this + 0xd60));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0xd60),*(J2DPane **)(this + 0xd98));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0xd98),*(J2DPane **)(this + 0xdd0));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0xdd0),*(J2DPane **)(this + 0xe08));
  iVar1 = 1;
  iVar2 = 0x38;
  do {
    J2DPane::insertChild
              (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + iVar2 + 0xdd0),
               *(J2DPane **)(this + iVar2 + 0xe08));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 8);
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0xf90),*(J2DPane **)(this + 0xfc8));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0xfc8),*(J2DPane **)(this + 0x1000));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x1000),*(J2DPane **)(this + 0x1038))
  ;
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x1038),*(J2DPane **)(this + 0x1070))
  ;
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x1070),*(J2DPane **)(this + 0x10a8))
  ;
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x10a8),*(J2DPane **)(this + 0x10e0))
  ;
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x10e0),*(J2DPane **)(this + 0x1118))
  ;
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x1118),*(J2DPane **)(this + 0x1150))
  ;
  iVar1 = 1;
  iVar2 = 0x38;
  do {
    J2DPane::insertChild
              (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + iVar2 + 0x1118),
               *(J2DPane **)(this + iVar2 + 0x1150));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 0xb);
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x1380),*(J2DPane **)(this + 0x13b8))
  ;
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x13b8),*(J2DPane **)(this + 0x13f0))
  ;
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x13f0),*(J2DPane **)(this + 0x1428))
  ;
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x1428),*(J2DPane **)(this + 0x1460))
  ;
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x1460),*(J2DPane **)(this + 0x1498))
  ;
  iVar1 = 1;
  iVar2 = 0x38;
  do {
    J2DPane::insertChild
              (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + iVar2 + 0x1460),
               *(J2DPane **)(this + iVar2 + 0x1498));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 6);
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x15b0),*(J2DPane **)(this + 0x15e8))
  ;
  iVar1 = 1;
  iVar2 = 0x38;
  do {
    J2DPane::insertChild
              (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + iVar2 + 0x15b0),
               *(J2DPane **)(this + iVar2 + 0x15e8));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 6);
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x1700),*(J2DPane **)(this + 0x1738))
  ;
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x1738),*(J2DPane **)(this + 6000));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 6000),*(J2DPane **)(this + 0x17a8));
  iVar1 = 1;
  iVar2 = 0x38;
  do {
    J2DPane::insertChild
              (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + iVar2 + 6000),
               *(J2DPane **)(this + iVar2 + 0x17a8));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 6);
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x18c0),*(J2DPane **)(this + 0x18f8))
  ;
  iVar1 = 1;
  iVar2 = 0x38;
  do {
    J2DPane::insertChild
              (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + iVar2 + 0x18c0),
               *(J2DPane **)(this + iVar2 + 0x18f8));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 6);
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x1a10),*(J2DPane **)(this + 0x1a48))
  ;
  iVar1 = 1;
  iVar2 = 0x38;
  do {
    J2DPane::insertChild
              (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + iVar2 + 0x1a10),
               *(J2DPane **)(this + iVar2 + 0x1a48));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 6);
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x1b60),*(J2DPane **)(this + 0x1b98))
  ;
  iVar1 = 1;
  iVar2 = 0x38;
  do {
    J2DPane::insertChild
              (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + iVar2 + 0x1b60),
               *(J2DPane **)(this + iVar2 + 0x1b98));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 6);
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x1cb0),*(J2DPane **)(this + 0x1ce8))
  ;
  iVar1 = 1;
  iVar2 = 0x38;
  do {
    J2DPane::insertChild
              (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + iVar2 + 0x1cb0),
               *(J2DPane **)(this + iVar2 + 0x1ce8));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 6);
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x1e00),*(J2DPane **)(this + 0x1e38))
  ;
  iVar1 = 1;
  iVar2 = 0x38;
  do {
    J2DPane::insertChild
              (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + iVar2 + 0x1e00),
               *(J2DPane **)(this + iVar2 + 0x1e38));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 6);
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x1f50),*(J2DPane **)(this + 0x1ff8))
  ;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Collect_c::weponPriority(void) */

void __thiscall dMenu_Collect_c::weponPriority(dMenu_Collect_c *this)

{
  int iVar1;
  int iVar2;
  
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0xa18),*(J2DPane **)(this + 0x2030));
  iVar1 = 1;
  iVar2 = 0x38;
  do {
    J2DPane::insertChild
              (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + iVar2 + 0x1ff8),
               *(J2DPane **)(this + iVar2 + 0x2030));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 5);
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x2110),*(J2DPane **)(this + 0x2148))
  ;
  iVar1 = 1;
  iVar2 = 0x38;
  do {
    J2DPane::insertChild
              (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + iVar2 + 0x2110),
               *(J2DPane **)(this + iVar2 + 0x2148));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 5);
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x2228),*(J2DPane **)(this + 0x2260))
  ;
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x2260),*(J2DPane **)(this + 0x2298))
  ;
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x2298),*(J2DPane **)(this + 0x22d0))
  ;
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x22d0),*(J2DPane **)(this + 0x2308))
  ;
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x2308),*(J2DPane **)(this + 0x2340))
  ;
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x2340),*(J2DPane **)(this + 0x2378))
  ;
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x2478),*(J2DPane **)(this + 0x2378),*(J2DPane **)(this + 0x2420))
  ;
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x801a0a24) */
/* WARNING: Removing unreachable block (ram,0x801a0a2c) */
/* __thiscall dMenu_Collect_c::tactGuideShow(unsigned char,
                                             bool) */

void __thiscall dMenu_Collect_c::tactGuideShow(dMenu_Collect_c *this,uchar param_1,bool param_2)

{
  double dVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  dMenu_Collect_c *pdVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  double dVar11;
  undefined8 in_f30;
  double x;
  undefined8 in_f31;
  long local_68 [6];
  double local_50;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  x = (double)d_menu_collect::_4288;
  iVar9 = (uint)param_1 * 4;
  if (*(int *)(&d_menu_collect::tact_beat + iVar9) == 3) {
    x = (double)(d_menu_collect::_5911 * (*(float *)(this + 0x17f4) - *(float *)(this + 0x17bc)));
  }
  else {
    if (*(int *)(&d_menu_collect::tact_beat + iVar9) == 4) {
      x = (double)(*(float *)(this + 0x17f4) - *(float *)(this + 0x17bc));
    }
  }
  iVar5 = 0;
  iVar7 = 0;
  iVar8 = 0;
  do {
    dVar11 = (double)JAIZelInst::getMelodyPattern
                               (&mDoAud_zelAudio_c::mTact,(uint)param_1,iVar5,
                                (long *)((int)local_68 + iVar8));
    local_50 = (double)(longlong)(int)dVar11;
    pdVar6 = this + iVar7;
    *(short *)(pdVar6 + 0x14ce) = (short)(int)dVar11;
    if ((param_2 != false) && (iVar5 < *(int *)(&d_menu_collect::tact_beat + iVar9))) {
      f_op_msg_mng::fopMsgM_setInitAlpha(pdVar6 + 0x17a8);
      f_op_msg_mng::fopMsgM_setInitAlpha(pdVar6 + 0x18f8);
      f_op_msg_mng::fopMsgM_setInitAlpha(pdVar6 + 0x1a48);
      f_op_msg_mng::fopMsgM_setInitAlpha(pdVar6 + 0x1b98);
      f_op_msg_mng::fopMsgM_setInitAlpha(pdVar6 + 0x1ce8);
      f_op_msg_mng::fopMsgM_setInitAlpha(pdVar6 + 0x1e38);
    }
    if (iVar5 < *(int *)(&d_menu_collect::tact_beat + iVar9)) {
      *(undefined *)(*(int *)(pdVar6 + 0x1e38) + 0xaa) = 1;
    }
    iVar5 = iVar5 + 1;
    iVar7 = iVar7 + 0x38;
    iVar8 = iVar8 + 4;
  } while (iVar5 < 6);
  iVar7 = 0;
  iVar5 = 0;
  dVar11 = (double)(float)((double)d_menu_collect::_5912 + x);
  for (iVar8 = 0; iVar8 < *(int *)(&d_menu_collect::tact_beat + iVar9); iVar8 = iVar8 + 1) {
    pdVar6 = this + iVar5;
    if (*(short *)(pdVar6 + 0x1e6e) == 1) {
      local_50 = (double)CONCAT44(0x43300000,
                                  (int)*(short *)(&d_menu_collect::rotate_angle_5852 +
                                                 *(int *)((int)local_68 + iVar7) * 2) ^ 0x80000000);
      dVar1 = local_50 - d_menu_collect::_4443;
      fVar2 = *(float *)(pdVar6 + 0x1a70) * d_menu_collect::_4287;
      piVar4 = *(int **)(pdVar6 + 0x1a48);
      piVar4[0x27] = (int)(*(float *)(pdVar6 + 0x1a6c) * d_menu_collect::_4287);
      piVar4[0x28] = (int)fVar2;
      *(undefined *)(piVar4 + 0x2a) = 0x7a;
      piVar4[0x29] = (int)(float)dVar1;
      (**(code **)(*piVar4 + 0x20))();
      if (*(int *)((int)local_68 + iVar7) == 0) {
        *(undefined *)(*(int *)(pdVar6 + 0x17a8) + 0xaa) = 1;
        *(undefined *)(*(int *)(pdVar6 + 0x18f8) + 0xaa) = 1;
        *(undefined *)(*(int *)(pdVar6 + 0x1a48) + 0xaa) = 1;
        *(undefined *)(*(int *)(pdVar6 + 0x1b98) + 0xaa) = 1;
        *(undefined *)(*(int *)(pdVar6 + 0x1ce8) + 0xaa) = 1;
        *(undefined *)(*(int *)(pdVar6 + 0x1e38) + 0xaa) = 1;
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(pdVar6 + 0x17a8),x,(double)d_menu_collect::_4288);
      }
      else {
        *(undefined *)(*(int *)(pdVar6 + 0x17a8) + 0xaa) = 1;
        *(undefined *)(*(int *)(pdVar6 + 0x18f8) + 0xaa) = 1;
        *(undefined *)(*(int *)(pdVar6 + 0x1a48) + 0xaa) = 1;
        *(undefined *)(*(int *)(pdVar6 + 0x1b98) + 0xaa) = 0;
        *(undefined *)(*(int *)(pdVar6 + 0x1ce8) + 0xaa) = 1;
        *(undefined *)(*(int *)(pdVar6 + 0x1e38) + 0xaa) = 1;
        iVar3 = *(int *)((int)local_68 + iVar7);
        if (iVar3 == 3) {
          f_op_msg_mng::fopMsgM_paneTrans
                    ((fopMsgM_pane_class *)(pdVar6 + 0x17a8),x,(double)d_menu_collect::_5912);
        }
        else {
          if (iVar3 < 3) {
            if (iVar3 == 1) {
              f_op_msg_mng::fopMsgM_paneTrans
                        ((fopMsgM_pane_class *)(pdVar6 + 0x17a8),x,(double)d_menu_collect::_5913);
            }
            else {
              if (0 < iVar3) {
                f_op_msg_mng::fopMsgM_paneTrans
                          ((fopMsgM_pane_class *)(pdVar6 + 0x17a8),dVar11,
                           (double)d_menu_collect::_4288);
              }
            }
          }
          else {
            if (iVar3 < 5) {
              f_op_msg_mng::fopMsgM_paneTrans
                        ((fopMsgM_pane_class *)(pdVar6 + 0x17a8),
                         (double)(float)(x - (double)d_menu_collect::_5912),
                         (double)d_menu_collect::_4288);
            }
          }
        }
      }
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(pdVar6 + 0x18f8),x,(double)d_menu_collect::_4288);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(pdVar6 + 0x1a48),x,(double)d_menu_collect::_4288);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(pdVar6 + 0x1b98),x,(double)d_menu_collect::_4288);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(pdVar6 + 0x1ce8),x,(double)d_menu_collect::_4288);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(pdVar6 + 0x1e38),x,(double)d_menu_collect::_4288);
    }
    iVar7 = iVar7 + 4;
    iVar5 = iVar5 + 0x38;
  }
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  __psq_l0(auStack24,uVar10);
  __psq_l1(auStack24,uVar10);
  return;
}


/* __thiscall dMenu_Collect_c::tactDemoMode(unsigned char) */

void __thiscall dMenu_Collect_c::tactDemoMode(dMenu_Collect_c *this,uchar param_1)

{
  short sVar1;
  char cVar3;
  int iVar2;
  int iVar4;
  int iVar5;
  short local_18 [4];
  short local_10;
  short local_e;
  short local_c;
  short local_a;
  
  local_18[0] = 0;
  local_18[1] = *(short *)(this + 0x14ce);
  local_18[2] = local_18[1] + *(short *)(this + 0x1506);
  local_18[3] = local_18[2] + *(short *)(this + 0x153e);
  local_10 = local_18[3] + *(short *)(this + 0x1576);
  local_e = local_10 + *(short *)(this + 0x15ae);
  local_c = local_e + *(short *)(this + 0x15e6);
  local_a = local_c + 10;
  cVar3 = cursorMainMove(this);
  if (cVar3 == '\0') {
    sVar1 = *(short *)(this + 0x161e);
    if (sVar1 < local_c) {
      *(short *)(this + 0x161e) = sVar1 + 1;
      iVar2 = 0;
      iVar4 = 0;
      iVar5 = 6;
      do {
        if (*(short *)(this + 0x161e) < *(short *)((int)local_18 + iVar4)) {
          *(undefined2 *)(this + iVar2 + 0x1e6e) = 0;
        }
        else {
          *(undefined2 *)(this + iVar2 + 0x1e6e) = 1;
        }
        iVar2 = iVar2 + 0x38;
        iVar4 = iVar4 + 2;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      tactGuideShow(this,(uchar)this[0x27ed],true);
    }
    else {
      if (sVar1 < local_a) {
        *(short *)(this + 0x161e) = sVar1 + 1;
        iVar2 = 0;
        iVar4 = 6;
        do {
          *(undefined2 *)(this + iVar2 + 0x1e6e) = 1;
          iVar2 = iVar2 + 0x38;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      else {
        iVar2 = 0;
        iVar4 = 6;
        do {
          *(undefined2 *)(this + iVar2 + 0x1e6e) = 0;
          iVar2 = iVar2 + 0x38;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        *(undefined2 *)(this + 0x161e) = 0;
        tactGuideShow(this,(uchar)this[0x27ed],true);
        this[0x27ee] = (dMenu_Collect_c)0x2;
      }
    }
  }
  else {
    itemScale(this);
    cVar3 = collectItemGetCheck(this,(uchar)this[0x27ed]);
    if (cVar3 == '\0') {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x890));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x8c8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x858));
    }
    else {
      itemnameMove(this);
    }
    JAIZelInst::melodyStop(&mDoAud_zelAudio_c::mTact);
    outFontMove(this);
    this[0x27ee] = (dMenu_Collect_c)0x0;
  }
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 7;
  return;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Removing unreachable block (ram,0x801a131c) */
/* WARNING: Removing unreachable block (ram,0x801a1324) */
/* __thiscall dMenu_Collect_c::tactPlayMode(unsigned char) */

void __thiscall dMenu_Collect_c::tactPlayMode(dMenu_Collect_c *this,uchar param_1)

{
  double dVar1;
  short sVar2;
  bool bVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  dMenu_Collect_c *pdVar11;
  int iVar12;
  undefined4 uVar13;
  double dVar14;
  undefined8 in_f30;
  double x;
  undefined8 in_f31;
  long local_78 [6];
  double local_60;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar13 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  x = (double)d_menu_collect::_4288;
  iVar12 = (uint)param_1 * 4;
  iVar6 = *(int *)(&d_menu_collect::tact_beat + iVar12);
  if (*(short *)(this + 0x161e) < iVar6) {
    if (iVar6 == 3) {
      x = (double)(d_menu_collect::_5911 * (*(float *)(this + 0x17f4) - *(float *)(this + 0x17bc)));
      JAIZelInst::setBeat(&mDoAud_zelAudio_c::mTact,0);
    }
    else {
      if (iVar6 == 4) {
        x = (double)(*(float *)(this + 0x17f4) - *(float *)(this + 0x17bc));
        JAIZelInst::setBeat(&mDoAud_zelAudio_c::mTact,4);
      }
      else {
        JAIZelInst::setBeat(&mDoAud_zelAudio_c::mTact,2);
      }
    }
    iVar6 = 0;
    iVar9 = 0;
    iVar10 = 0;
    do {
      dVar14 = (double)JAIZelInst::getMelodyPattern
                                 (&mDoAud_zelAudio_c::mTact,(uint)param_1,iVar6,
                                  (long *)((int)local_78 + iVar10));
      local_60 = (double)(longlong)(int)dVar14;
      pdVar11 = this + iVar9;
      *(short *)(pdVar11 + 0x14ce) = (short)(int)dVar14;
      if (iVar6 < *(int *)(&d_menu_collect::tact_beat + iVar12)) {
        if (iVar6 < *(short *)(this + 0x161e)) {
          f_op_msg_mng::fopMsgM_setInitAlpha(pdVar11 + 0x17a8);
          f_op_msg_mng::fopMsgM_setInitAlpha(pdVar11 + 0x18f8);
          f_op_msg_mng::fopMsgM_setInitAlpha(pdVar11 + 0x1a48);
          f_op_msg_mng::fopMsgM_setInitAlpha(pdVar11 + 0x1b98);
          f_op_msg_mng::fopMsgM_setInitAlpha(pdVar11 + 0x1ce8);
        }
        else {
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(pdVar11 + 0x17a8),d_menu_collect::_4287);
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(pdVar11 + 0x18f8),d_menu_collect::_4287);
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(pdVar11 + 0x1a48),d_menu_collect::_4287);
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(pdVar11 + 0x1b98),d_menu_collect::_4287);
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(pdVar11 + 0x1ce8),d_menu_collect::_4287);
        }
        f_op_msg_mng::fopMsgM_setInitAlpha(pdVar11 + 0x1e38);
      }
      if (iVar6 < *(int *)(&d_menu_collect::tact_beat + iVar12)) {
        *(undefined *)(*(int *)(pdVar11 + 0x1e38) + 0xaa) = 1;
      }
      iVar6 = iVar6 + 1;
      iVar9 = iVar9 + 0x38;
      iVar10 = iVar10 + 4;
    } while (iVar6 < 6);
    iVar6 = m_Do_audio::mDoAud_getTactDirection(0,*(undefined4 *)(this + 0x27dc));
    bVar3 = false;
    if (iVar6 == *(int *)(this + 0x27dc)) {
      if (iVar6 == 0) {
        if ((0 < *(short *)(this + 0x27e4)) &&
           (*(short *)(this + 0x27e4) = *(short *)(this + 0x27e4) + -1,
           *(short *)(this + 0x27e4) == 0)) {
          bVar3 = true;
        }
      }
      else {
        *(undefined2 *)(this + 0x27e4) = 0;
      }
    }
    else {
      *(int *)(this + 0x27dc) = iVar6;
      if (iVar6 == 0) {
        if (local_78[*(short *)(this + 0x161e)] == 0) {
          *(undefined2 *)(this + 0x27e4) = DAT_803e6018;
        }
        else {
          *(undefined2 *)(this + 0x27e4) = 0;
        }
      }
      else {
        bVar3 = true;
        *(undefined2 *)(this + 0x27e4) = 0;
      }
    }
    if (bVar3) {
      JAIZelInst::judge(&mDoAud_zelAudio_c::mTact,(int)*(short *)(this + 0x161e),
                        *(long *)(this + 0x27dc));
      if (*(int *)(this + 0x27dc) == local_78[*(short *)(this + 0x161e)]) {
        *(undefined2 *)(this + *(short *)(this + 0x161e) * 0x38 + 0x1e6e) = 1;
        *(short *)(this + 0x161e) = *(short *)(this + 0x161e) + 1;
        if ((int)*(short *)(this + 0x161e) == *(int *)(&d_menu_collect::tact_beat + iVar12)) {
          *(undefined2 *)(this + 0x27e4) = 10;
        }
        iVar9 = 0;
        iVar6 = 0;
        dVar14 = (double)(float)((double)d_menu_collect::_5912 + x);
        for (iVar10 = 0; iVar10 < *(int *)(&d_menu_collect::tact_beat + iVar12); iVar10 = iVar10 + 1
            ) {
          pdVar11 = this + iVar6;
          if (*(short *)(pdVar11 + 0x1e6e) == 1) {
            local_60 = (double)CONCAT44(0x43300000,
                                        (int)*(short *)(&d_menu_collect::rotate_angle_6007 +
                                                       *(int *)((int)local_78 + iVar9) * 2) ^
                                        0x80000000);
            dVar1 = local_60 - d_menu_collect::_4443;
            fVar4 = *(float *)(pdVar11 + 0x1a70) * d_menu_collect::_4287;
            piVar7 = *(int **)(pdVar11 + 0x1a48);
            piVar7[0x27] = (int)(*(float *)(pdVar11 + 0x1a6c) * d_menu_collect::_4287);
            piVar7[0x28] = (int)fVar4;
            *(undefined *)(piVar7 + 0x2a) = 0x7a;
            piVar7[0x29] = (int)(float)dVar1;
            (**(code **)(*piVar7 + 0x20))();
            if (*(int *)((int)local_78 + iVar9) == 0) {
              *(undefined *)(*(int *)(pdVar11 + 0x17a8) + 0xaa) = 1;
              *(undefined *)(*(int *)(pdVar11 + 0x18f8) + 0xaa) = 1;
              *(undefined *)(*(int *)(pdVar11 + 0x1a48) + 0xaa) = 1;
              *(undefined *)(*(int *)(pdVar11 + 0x1b98) + 0xaa) = 1;
              *(undefined *)(*(int *)(pdVar11 + 0x1ce8) + 0xaa) = 1;
              *(undefined *)(*(int *)(pdVar11 + 0x1e38) + 0xaa) = 1;
              f_op_msg_mng::fopMsgM_paneTrans
                        ((fopMsgM_pane_class *)(pdVar11 + 0x17a8),x,(double)d_menu_collect::_4288);
            }
            else {
              *(undefined *)(*(int *)(pdVar11 + 0x17a8) + 0xaa) = 1;
              *(undefined *)(*(int *)(pdVar11 + 0x18f8) + 0xaa) = 1;
              *(undefined *)(*(int *)(pdVar11 + 0x1a48) + 0xaa) = 1;
              *(undefined *)(*(int *)(pdVar11 + 0x1b98) + 0xaa) = 0;
              *(undefined *)(*(int *)(pdVar11 + 0x1ce8) + 0xaa) = 1;
              *(undefined *)(*(int *)(pdVar11 + 0x1e38) + 0xaa) = 1;
              iVar5 = *(int *)((int)local_78 + iVar9);
              if (iVar5 == 3) {
                f_op_msg_mng::fopMsgM_paneTrans
                          ((fopMsgM_pane_class *)(pdVar11 + 0x17a8),x,(double)d_menu_collect::_5912)
                ;
              }
              else {
                if (iVar5 < 3) {
                  if (iVar5 == 1) {
                    f_op_msg_mng::fopMsgM_paneTrans
                              ((fopMsgM_pane_class *)(pdVar11 + 0x17a8),x,
                               (double)d_menu_collect::_5913);
                  }
                  else {
                    if (0 < iVar5) {
                      f_op_msg_mng::fopMsgM_paneTrans
                                ((fopMsgM_pane_class *)(pdVar11 + 0x17a8),dVar14,
                                 (double)d_menu_collect::_4288);
                    }
                  }
                }
                else {
                  if (iVar5 < 5) {
                    f_op_msg_mng::fopMsgM_paneTrans
                              ((fopMsgM_pane_class *)(pdVar11 + 0x17a8),
                               (double)(float)(x - (double)d_menu_collect::_5912),
                               (double)d_menu_collect::_4288);
                  }
                }
              }
            }
            f_op_msg_mng::fopMsgM_paneTrans
                      ((fopMsgM_pane_class *)(pdVar11 + 0x18f8),x,(double)d_menu_collect::_4288);
            f_op_msg_mng::fopMsgM_paneTrans
                      ((fopMsgM_pane_class *)(pdVar11 + 0x1a48),x,(double)d_menu_collect::_4288);
            f_op_msg_mng::fopMsgM_paneTrans
                      ((fopMsgM_pane_class *)(pdVar11 + 0x1b98),x,(double)d_menu_collect::_4288);
            f_op_msg_mng::fopMsgM_paneTrans
                      ((fopMsgM_pane_class *)(pdVar11 + 0x1ce8),x,(double)d_menu_collect::_4288);
            f_op_msg_mng::fopMsgM_paneTrans
                      ((fopMsgM_pane_class *)(pdVar11 + 0x1e38),x,(double)d_menu_collect::_4288);
            f_op_msg_mng::fopMsgM_setInitAlpha(pdVar11 + 0x17a8);
            f_op_msg_mng::fopMsgM_setInitAlpha((fopMsgM_pane_class *)(pdVar11 + 0x18f8));
            f_op_msg_mng::fopMsgM_setInitAlpha((fopMsgM_pane_class *)(pdVar11 + 0x1a48));
            f_op_msg_mng::fopMsgM_setInitAlpha((fopMsgM_pane_class *)(pdVar11 + 0x1b98));
            f_op_msg_mng::fopMsgM_setInitAlpha((fopMsgM_pane_class *)(pdVar11 + 0x1ce8));
          }
          iVar9 = iVar9 + 4;
          iVar6 = iVar6 + 0x38;
        }
      }
      else {
        iVar6 = 0;
        iVar12 = 6;
        do {
          *(undefined2 *)(this + iVar6 + 0x1e6e) = 0;
          iVar6 = iVar6 + 0x38;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
        *(undefined2 *)(this + 0x161e) = 0;
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x8f7,(cXyz *)0x0,0,0,d_menu_collect::_4440,
                   d_menu_collect::_4440,d_menu_collect::_5050,d_menu_collect::_5050,0);
      }
    }
    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
      cVar8 = cursorMainMove(this);
      if (cVar8 != '\0') {
        itemScale(this);
        cVar8 = collectItemGetCheck(this,(uchar)this[0x27ed]);
        if (cVar8 == '\0') {
          f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x890));
          f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x8c8));
          f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x858));
        }
        else {
          itemnameMove(this);
        }
        outFontMove(this);
        this[0x27ee] = (dMenu_Collect_c)0x0;
      }
    }
    else {
      this[0x27ee] = (dMenu_Collect_c)0x1;
      *(undefined2 *)(this + 0x161e) = 0;
      tactGuideHide(this);
      iVar12 = 0;
      iVar6 = 0;
      iVar9 = 6;
      do {
        if (iVar12 < *(int *)(&d_menu_collect::tact_beat + (uint)(byte)this[0x27ed] * 4)) {
          *(undefined *)(*(int *)(this + iVar6 + 0x1e38) + 0xaa) = 1;
        }
        iVar12 = iVar12 + 1;
        iVar6 = iVar6 + 0x38;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      JAIZelInst::melodyPlay(&mDoAud_zelAudio_c::mTact,(uint)(byte)this[0x27ed]);
    }
  }
  else {
    sVar2 = *(short *)(this + 0x27e4);
    *(short *)(this + 0x27e4) = sVar2 + -1;
    if ((short)(sVar2 + -1) < 1) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8f6,(cXyz *)0x0,0,0,d_menu_collect::_4440,
                 d_menu_collect::_4440,d_menu_collect::_5050,d_menu_collect::_5050,0);
      iVar6 = 0;
      iVar12 = 6;
      do {
        *(undefined2 *)(this + iVar6 + 0x1e6e) = 0;
        iVar6 = iVar6 + 0x38;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
      *(undefined2 *)(this + 0x161e) = 0;
      tactGuideShow(this,(uchar)this[0x27ed],true);
      this[0x27ee] = (dMenu_Collect_c)0x2;
    }
  }
  __psq_l0(auStack8,uVar13);
  __psq_l1(auStack8,uVar13);
  __psq_l0(auStack24,uVar13);
  __psq_l1(auStack24,uVar13);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x801a1570) */
/* WARNING: Removing unreachable block (ram,0x801a1560) */
/* WARNING: Removing unreachable block (ram,0x801a1568) */
/* WARNING: Removing unreachable block (ram,0x801a1578) */
/* __thiscall dMenu_Collect_c::tactTrans(unsigned char,
                                         float,
                                         float) */

void __thiscall
dMenu_Collect_c::tactTrans(dMenu_Collect_c *this,uchar param_1,float param_2,float param_3)

{
  int iVar1;
  int iVar2;
  dMenu_Collect_c *pdVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  double dVar7;
  double y;
  undefined8 in_f28;
  undefined8 in_f29;
  double x;
  undefined8 in_f30;
  undefined8 in_f31;
  double x_00;
  long local_88 [6];
  longlong local_70;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  y = (double)param_3;
  x = (double)param_2;
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  if (*(int *)(&d_menu_collect::tact_beat + (uint)param_1 * 4) == 3) {
    x = (double)(float)(x + (double)(d_menu_collect::_5911 *
                                    (*(float *)(this + 0x17f4) - *(float *)(this + 0x17bc))));
  }
  else {
    if (*(int *)(&d_menu_collect::tact_beat + (uint)param_1 * 4) == 4) {
      x = (double)(float)(x + (double)(*(float *)(this + 0x17f4) - *(float *)(this + 0x17bc)));
    }
  }
  iVar2 = 0;
  iVar4 = 0;
  iVar5 = 0;
  do {
    dVar7 = (double)JAIZelInst::getMelodyPattern
                              (&mDoAud_zelAudio_c::mTact,(uint)param_1,iVar2,
                               (long *)((int)local_88 + iVar5));
    local_70 = (longlong)(int)dVar7;
    *(short *)(this + iVar4 + 0x14ce) = (short)(int)dVar7;
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x38;
    iVar5 = iVar5 + 4;
  } while (iVar2 < 6);
  iVar5 = 0;
  iVar4 = 0;
  x_00 = (double)(float)((double)d_menu_collect::_5912 + x);
  dVar7 = (double)(float)((double)d_menu_collect::_5912 + y);
  for (iVar2 = 0; iVar2 < *(int *)(&d_menu_collect::tact_beat + (uint)param_1 * 4);
      iVar2 = iVar2 + 1) {
    iVar1 = *(int *)((int)local_88 + iVar4);
    if (iVar1 == 2) {
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar5 + 0x17a8),x_00,y);
    }
    else {
      if (iVar1 < 2) {
        if (iVar1 == 0) {
          f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar5 + 0x17a8),x,y);
        }
        else {
          if (-1 < iVar1) {
            f_op_msg_mng::fopMsgM_paneTrans
                      ((fopMsgM_pane_class *)(this + iVar5 + 0x17a8),x,
                       (double)(float)(y - (double)d_menu_collect::_5912));
          }
        }
      }
      else {
        if (iVar1 == 4) {
          f_op_msg_mng::fopMsgM_paneTrans
                    ((fopMsgM_pane_class *)(this + iVar5 + 0x17a8),
                     (double)(float)(x - (double)d_menu_collect::_5912),y);
        }
        else {
          if (iVar1 < 4) {
            f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar5 + 0x17a8),x,dVar7);
          }
        }
      }
    }
    pdVar3 = this + iVar5;
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(pdVar3 + 0x18f8),x,y);
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(pdVar3 + 0x1a48),x,y);
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(pdVar3 + 0x1b98),x,y);
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(pdVar3 + 0x1ce8),x,y);
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(pdVar3 + 0x1e38),x,y);
    iVar5 = iVar5 + 0x38;
    iVar4 = iVar4 + 4;
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


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMenu_Collect_c::tactBaseShow(void) */

void __thiscall dMenu_Collect_c::tactBaseShow(dMenu_Collect_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + iVar2 + 0x1e38),(double)d_menu_collect::_4288,
               (double)d_menu_collect::_4288);
    *(undefined *)(*(int *)(this + iVar2 + 0x1e38) + 0xaa) = 1;
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 6);
  return;
}


/* __thiscall dMenu_Collect_c::cornerMove(void) */

void __thiscall dMenu_Collect_c::cornerMove(dMenu_Collect_c *this)

{
  int iVar1;
  uint uVar2;
  double dVar3;
  short sVar4;
  float fVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  double dVar17;
  uint local_1c8;
  uint local_1c4;
  uint local_1c0;
  uint local_1bc [2];
  undefined4 local_1b4;
  uint local_1b0;
  uint local_1ac;
  uint local_1a8;
  uint local_1a4;
  uint local_1a0;
  uint local_19c;
  uint local_198;
  uint local_194;
  double local_190;
  undefined4 local_188;
  uint uStack388;
  double local_180;
  double local_178;
  undefined4 local_170;
  uint uStack364;
  double local_168;
  double local_160;
  undefined4 local_158;
  uint uStack340;
  double local_150;
  double local_148;
  undefined4 local_140;
  uint uStack316;
  double local_138;
  double local_130;
  undefined4 local_128;
  uint uStack292;
  double local_120;
  double local_118;
  undefined4 local_110;
  uint uStack268;
  double local_108;
  double local_100;
  undefined4 local_f8;
  uint uStack244;
  double local_f0;
  double local_e8;
  undefined4 local_e0;
  uint uStack220;
  double local_d8;
  double local_d0;
  undefined4 local_c8;
  uint uStack196;
  double local_c0;
  double local_b8;
  undefined4 local_b0;
  uint uStack172;
  double local_a8;
  double local_a0;
  undefined4 local_98;
  uint uStack148;
  double local_90;
  double local_88;
  undefined4 local_80;
  uint uStack124;
  double local_78;
  double local_70;
  undefined4 local_68;
  uint uStack100;
  double local_60;
  double local_58;
  undefined4 local_50;
  uint uStack76;
  double local_48;
  double local_40;
  undefined4 local_38;
  uint uStack52;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  
  local_1a0 = 0xffffffff;
  local_19c = 0xffffffff;
  local_198 = 0xffffffff;
  local_194 = 0xffffffff;
  local_1b4 = 0xffffffff;
  *(short *)(this + 0x27e6) = *(short *)(this + 0x27e6) + 1;
  if (0xef < *(short *)(this + 0x27e6)) {
    *(undefined2 *)(this + 0x27e6) = 0;
  }
  dVar17 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x3c,(int)*(short *)(this + 0x27e6) % 0x3c,2)
  ;
  sVar4 = *(short *)(this + 0x27e6);
  if (sVar4 < 0x3c) {
    uVar13 = (uint)(byte)this[0x2488];
    local_190 = (double)CONCAT44(0x43300000,uVar13);
    uVar11 = (uint)(byte)this[0x2490];
    uStack388 = uVar11 - uVar13 ^ 0x80000000;
    iVar8 = (int)((float)(local_190 - d_menu_collect::_4290) +
                 (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack388) -
                                                 d_menu_collect::_4443)));
    local_180 = (double)(longlong)iVar8;
    uVar14 = (uint)(byte)this[0x2489];
    local_178 = (double)CONCAT44(0x43300000,uVar14);
    uVar9 = (uint)(byte)this[0x2491];
    uStack364 = uVar9 - uVar14 ^ 0x80000000;
    iVar10 = (int)((float)(local_178 - d_menu_collect::_4290) +
                  (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack364) -
                                                  d_menu_collect::_4443)));
    local_168 = (double)(longlong)iVar10;
    uVar15 = (uint)(byte)this[0x248a];
    local_160 = (double)CONCAT44(0x43300000,uVar15);
    uVar7 = (uint)(byte)this[0x2492];
    uStack340 = uVar7 - uVar15 ^ 0x80000000;
    iVar1 = (int)((float)(local_160 - d_menu_collect::_4290) +
                 (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack340) -
                                                 d_menu_collect::_4443)));
    local_150 = (double)(longlong)iVar1;
    uVar16 = (uint)(byte)this[0x248b];
    local_148 = (double)CONCAT44(0x43300000,uVar16);
    uVar6 = (uint)(byte)this[0x2493];
    uStack316 = uVar6 - uVar16 ^ 0x80000000;
    uVar2 = (uint)((float)(local_148 - d_menu_collect::_4290) +
                  (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack316) -
                                                  d_menu_collect::_4443)));
    local_138 = (double)(longlong)(int)uVar2;
    local_1a0 = uVar2 & 0xff | (uint)CONCAT21(CONCAT11((char)iVar8,(char)iVar10),(char)iVar1) << 8;
    uVar12 = (uint)(byte)this[0x248c];
    local_130 = (double)CONCAT44(0x43300000,uVar12);
    uStack292 = uVar13 - uVar12 ^ 0x80000000;
    iVar8 = (int)((float)(local_130 - d_menu_collect::_4290) +
                 (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack292) -
                                                 d_menu_collect::_4443)));
    local_120 = (double)(longlong)iVar8;
    uVar13 = (uint)(byte)this[0x248d];
    local_118 = (double)CONCAT44(0x43300000,uVar13);
    uStack268 = uVar14 - uVar13 ^ 0x80000000;
    iVar10 = (int)((float)(local_118 - d_menu_collect::_4290) +
                  (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack268) -
                                                  d_menu_collect::_4443)));
    local_108 = (double)(longlong)iVar10;
    uVar14 = (uint)(byte)this[0x248e];
    local_100 = (double)CONCAT44(0x43300000,uVar14);
    uStack244 = uVar15 - uVar14 ^ 0x80000000;
    iVar1 = (int)((float)(local_100 - d_menu_collect::_4290) +
                 (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack244) -
                                                 d_menu_collect::_4443)));
    local_f0 = (double)(longlong)iVar1;
    uVar15 = (uint)(byte)this[0x248f];
    local_e8 = (double)CONCAT44(0x43300000,uVar15);
    uStack220 = uVar16 - uVar15 ^ 0x80000000;
    uVar2 = (uint)((float)(local_e8 - d_menu_collect::_4290) +
                  (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack220) -
                                                  d_menu_collect::_4443)));
    local_d8 = (double)(longlong)(int)uVar2;
    local_19c = uVar2 & 0xff | (uint)CONCAT21(CONCAT11((char)iVar8,(char)iVar10),(char)iVar1) << 8;
    local_d0 = (double)CONCAT44(0x43300000,uVar11);
    uVar16 = (uint)(byte)this[0x2494];
    uStack196 = uVar16 - uVar11 ^ 0x80000000;
    iVar8 = (int)((float)(local_d0 - d_menu_collect::_4290) +
                 (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack196) -
                                                 d_menu_collect::_4443)));
    local_c0 = (double)(longlong)iVar8;
    local_b8 = (double)CONCAT44(0x43300000,uVar9);
    uVar11 = (uint)(byte)this[0x2495];
    uStack172 = uVar11 - uVar9 ^ 0x80000000;
    iVar10 = (int)((float)(local_b8 - d_menu_collect::_4290) +
                  (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack172) -
                                                  d_menu_collect::_4443)));
    local_a8 = (double)(longlong)iVar10;
    local_a0 = (double)CONCAT44(0x43300000,uVar7);
    uVar9 = (uint)(byte)this[0x2496];
    uStack148 = uVar9 - uVar7 ^ 0x80000000;
    iVar1 = (int)((float)(local_a0 - d_menu_collect::_4290) +
                 (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack148) -
                                                 d_menu_collect::_4443)));
    local_90 = (double)(longlong)iVar1;
    local_88 = (double)CONCAT44(0x43300000,uVar6);
    uVar7 = (uint)(byte)this[0x2497];
    uStack124 = uVar7 - uVar6 ^ 0x80000000;
    uVar2 = (uint)((float)(local_88 - d_menu_collect::_4290) +
                  (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack124) -
                                                  d_menu_collect::_4443)));
    local_78 = (double)(longlong)(int)uVar2;
    local_198 = uVar2 & 0xff | (uint)CONCAT21(CONCAT11((char)iVar8,(char)iVar10),(char)iVar1) << 8;
    local_70 = (double)CONCAT44(0x43300000,uVar16);
    uStack100 = uVar12 - uVar16 ^ 0x80000000;
    iVar8 = (int)((float)(local_70 - d_menu_collect::_4290) +
                 (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack100) -
                                                 d_menu_collect::_4443)));
    local_60 = (double)(longlong)iVar8;
    local_58 = (double)CONCAT44(0x43300000,uVar11);
    uStack76 = uVar13 - uVar11 ^ 0x80000000;
    iVar10 = (int)((float)(local_58 - d_menu_collect::_4290) +
                  (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack76) -
                                                  d_menu_collect::_4443)));
    local_48 = (double)(longlong)iVar10;
    local_40 = (double)CONCAT44(0x43300000,uVar9);
    uStack52 = uVar14 - uVar9 ^ 0x80000000;
    iVar1 = (int)((float)(local_40 - d_menu_collect::_4290) +
                 (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack52) -
                                                 d_menu_collect::_4443)));
    local_30 = (double)(longlong)iVar1;
    local_28 = (double)CONCAT44(0x43300000,uVar7);
    local_20 = (double)CONCAT44(0x43300000,uVar15 - uVar7 ^ 0x80000000);
    uVar2 = (uint)((float)(local_28 - d_menu_collect::_4290) +
                  (float)(dVar17 * (double)(float)(local_20 - d_menu_collect::_4443)));
    local_18 = (double)(longlong)(int)uVar2;
    local_194 = uVar2 & 0xff | (uint)CONCAT21(CONCAT11((char)iVar8,(char)iVar10),(char)iVar1) << 8;
  }
  else {
    if (sVar4 < 0x78) {
      uVar13 = (uint)(byte)this[0x2488];
      local_18 = (double)CONCAT44(0x43300000,uVar13);
      uVar11 = (uint)(byte)this[0x2490];
      local_20 = (double)CONCAT44(0x43300000,uVar11 - uVar13 ^ 0x80000000);
      iVar8 = (int)((float)(local_18 - d_menu_collect::_4290) +
                   (float)(dVar17 * (double)(float)(local_20 - d_menu_collect::_4443)));
      local_28 = (double)(longlong)iVar8;
      uVar14 = (uint)(byte)this[0x2489];
      local_30 = (double)CONCAT44(0x43300000,uVar14);
      uVar9 = (uint)(byte)this[0x2491];
      uStack52 = uVar9 - uVar14 ^ 0x80000000;
      iVar10 = (int)((float)(local_30 - d_menu_collect::_4290) +
                    (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack52) -
                                                    d_menu_collect::_4443)));
      local_40 = (double)(longlong)iVar10;
      uVar15 = (uint)(byte)this[0x248a];
      local_48 = (double)CONCAT44(0x43300000,uVar15);
      uVar7 = (uint)(byte)this[0x2492];
      uStack76 = uVar7 - uVar15 ^ 0x80000000;
      iVar1 = (int)((float)(local_48 - d_menu_collect::_4290) +
                   (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack76) -
                                                   d_menu_collect::_4443)));
      local_58 = (double)(longlong)iVar1;
      uVar16 = (uint)(byte)this[0x248b];
      local_60 = (double)CONCAT44(0x43300000,uVar16);
      uVar6 = (uint)(byte)this[0x2493];
      uStack100 = uVar6 - uVar16 ^ 0x80000000;
      uVar2 = (uint)((float)(local_60 - d_menu_collect::_4290) +
                    (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack100) -
                                                    d_menu_collect::_4443)));
      local_70 = (double)(longlong)(int)uVar2;
      local_19c = uVar2 & 0xff | (uint)CONCAT21(CONCAT11((char)iVar8,(char)iVar10),(char)iVar1) << 8
      ;
      uVar12 = (uint)(byte)this[0x248c];
      local_78 = (double)CONCAT44(0x43300000,uVar12);
      uStack124 = uVar13 - uVar12 ^ 0x80000000;
      iVar8 = (int)((float)(local_78 - d_menu_collect::_4290) +
                   (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack124) -
                                                   d_menu_collect::_4443)));
      local_88 = (double)(longlong)iVar8;
      uVar13 = (uint)(byte)this[0x248d];
      local_90 = (double)CONCAT44(0x43300000,uVar13);
      uStack148 = uVar14 - uVar13 ^ 0x80000000;
      iVar10 = (int)((float)(local_90 - d_menu_collect::_4290) +
                    (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack148) -
                                                    d_menu_collect::_4443)));
      local_a0 = (double)(longlong)iVar10;
      uVar14 = (uint)(byte)this[0x248e];
      local_a8 = (double)CONCAT44(0x43300000,uVar14);
      uStack172 = uVar15 - uVar14 ^ 0x80000000;
      iVar1 = (int)((float)(local_a8 - d_menu_collect::_4290) +
                   (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack172) -
                                                   d_menu_collect::_4443)));
      local_b8 = (double)(longlong)iVar1;
      uVar15 = (uint)(byte)this[0x248f];
      local_c0 = (double)CONCAT44(0x43300000,uVar15);
      uStack196 = uVar16 - uVar15 ^ 0x80000000;
      uVar2 = (uint)((float)(local_c0 - d_menu_collect::_4290) +
                    (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack196) -
                                                    d_menu_collect::_4443)));
      local_d0 = (double)(longlong)(int)uVar2;
      local_194 = uVar2 & 0xff | (uint)CONCAT21(CONCAT11((char)iVar8,(char)iVar10),(char)iVar1) << 8
      ;
      local_d8 = (double)CONCAT44(0x43300000,uVar11);
      uVar16 = (uint)(byte)this[0x2494];
      uStack220 = uVar16 - uVar11 ^ 0x80000000;
      iVar8 = (int)((float)(local_d8 - d_menu_collect::_4290) +
                   (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack220) -
                                                   d_menu_collect::_4443)));
      local_e8 = (double)(longlong)iVar8;
      local_f0 = (double)CONCAT44(0x43300000,uVar9);
      uVar11 = (uint)(byte)this[0x2495];
      uStack244 = uVar11 - uVar9 ^ 0x80000000;
      iVar10 = (int)((float)(local_f0 - d_menu_collect::_4290) +
                    (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack244) -
                                                    d_menu_collect::_4443)));
      local_100 = (double)(longlong)iVar10;
      local_108 = (double)CONCAT44(0x43300000,uVar7);
      uVar9 = (uint)(byte)this[0x2496];
      uStack268 = uVar9 - uVar7 ^ 0x80000000;
      iVar1 = (int)((float)(local_108 - d_menu_collect::_4290) +
                   (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack268) -
                                                   d_menu_collect::_4443)));
      local_118 = (double)(longlong)iVar1;
      local_120 = (double)CONCAT44(0x43300000,uVar6);
      uVar7 = (uint)(byte)this[0x2497];
      uStack292 = uVar7 - uVar6 ^ 0x80000000;
      uVar2 = (uint)((float)(local_120 - d_menu_collect::_4290) +
                    (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack292) -
                                                    d_menu_collect::_4443)));
      local_130 = (double)(longlong)(int)uVar2;
      local_1a0 = uVar2 & 0xff | (uint)CONCAT21(CONCAT11((char)iVar8,(char)iVar10),(char)iVar1) << 8
      ;
      local_138 = (double)CONCAT44(0x43300000,uVar16);
      uStack316 = uVar12 - uVar16 ^ 0x80000000;
      iVar8 = (int)((float)(local_138 - d_menu_collect::_4290) +
                   (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack316) -
                                                   d_menu_collect::_4443)));
      local_148 = (double)(longlong)iVar8;
      local_150 = (double)CONCAT44(0x43300000,uVar11);
      uStack340 = uVar13 - uVar11 ^ 0x80000000;
      iVar10 = (int)((float)(local_150 - d_menu_collect::_4290) +
                    (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack340) -
                                                    d_menu_collect::_4443)));
      local_160 = (double)(longlong)iVar10;
      local_168 = (double)CONCAT44(0x43300000,uVar9);
      uStack364 = uVar14 - uVar9 ^ 0x80000000;
      iVar1 = (int)((float)(local_168 - d_menu_collect::_4290) +
                   (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack364) -
                                                   d_menu_collect::_4443)));
      local_178 = (double)(longlong)iVar1;
      local_180 = (double)CONCAT44(0x43300000,uVar7);
      uStack388 = uVar15 - uVar7 ^ 0x80000000;
      uVar2 = (uint)((float)(local_180 - d_menu_collect::_4290) +
                    (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack388) -
                                                    d_menu_collect::_4443)));
      local_190 = (double)(longlong)(int)uVar2;
      local_198 = uVar2 & 0xff | (uint)CONCAT21(CONCAT11((char)iVar8,(char)iVar10),(char)iVar1) << 8
      ;
    }
    else {
      if (sVar4 < 0xb4) {
        uVar13 = (uint)(byte)this[0x2488];
        local_18 = (double)CONCAT44(0x43300000,uVar13);
        uVar11 = (uint)(byte)this[0x2490];
        local_20 = (double)CONCAT44(0x43300000,uVar11 - uVar13 ^ 0x80000000);
        iVar8 = (int)((float)(local_18 - d_menu_collect::_4290) +
                     (float)(dVar17 * (double)(float)(local_20 - d_menu_collect::_4443)));
        local_28 = (double)(longlong)iVar8;
        uVar14 = (uint)(byte)this[0x2489];
        local_30 = (double)CONCAT44(0x43300000,uVar14);
        uVar9 = (uint)(byte)this[0x2491];
        uStack52 = uVar9 - uVar14 ^ 0x80000000;
        iVar10 = (int)((float)(local_30 - d_menu_collect::_4290) +
                      (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack52) -
                                                      d_menu_collect::_4443)));
        local_40 = (double)(longlong)iVar10;
        uVar15 = (uint)(byte)this[0x248a];
        local_48 = (double)CONCAT44(0x43300000,uVar15);
        uVar7 = (uint)(byte)this[0x2492];
        uStack76 = uVar7 - uVar15 ^ 0x80000000;
        iVar1 = (int)((float)(local_48 - d_menu_collect::_4290) +
                     (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack76) -
                                                     d_menu_collect::_4443)));
        local_58 = (double)(longlong)iVar1;
        uVar16 = (uint)(byte)this[0x248b];
        local_60 = (double)CONCAT44(0x43300000,uVar16);
        uVar6 = (uint)(byte)this[0x2493];
        uStack100 = uVar6 - uVar16 ^ 0x80000000;
        uVar2 = (uint)((float)(local_60 - d_menu_collect::_4290) +
                      (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack100) -
                                                      d_menu_collect::_4443)));
        local_70 = (double)(longlong)(int)uVar2;
        local_194 = uVar2 & 0xff |
                    (uint)CONCAT21(CONCAT11((char)iVar8,(char)iVar10),(char)iVar1) << 8;
        uVar12 = (uint)(byte)this[0x248c];
        local_78 = (double)CONCAT44(0x43300000,uVar12);
        uStack124 = uVar13 - uVar12 ^ 0x80000000;
        iVar8 = (int)((float)(local_78 - d_menu_collect::_4290) +
                     (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack124) -
                                                     d_menu_collect::_4443)));
        local_88 = (double)(longlong)iVar8;
        uVar13 = (uint)(byte)this[0x248d];
        local_90 = (double)CONCAT44(0x43300000,uVar13);
        uStack148 = uVar14 - uVar13 ^ 0x80000000;
        iVar10 = (int)((float)(local_90 - d_menu_collect::_4290) +
                      (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack148) -
                                                      d_menu_collect::_4443)));
        local_a0 = (double)(longlong)iVar10;
        uVar14 = (uint)(byte)this[0x248e];
        local_a8 = (double)CONCAT44(0x43300000,uVar14);
        uStack172 = uVar15 - uVar14 ^ 0x80000000;
        iVar1 = (int)((float)(local_a8 - d_menu_collect::_4290) +
                     (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack172) -
                                                     d_menu_collect::_4443)));
        local_b8 = (double)(longlong)iVar1;
        uVar15 = (uint)(byte)this[0x248f];
        local_c0 = (double)CONCAT44(0x43300000,uVar15);
        uStack196 = uVar16 - uVar15 ^ 0x80000000;
        uVar2 = (uint)((float)(local_c0 - d_menu_collect::_4290) +
                      (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack196) -
                                                      d_menu_collect::_4443)));
        local_d0 = (double)(longlong)(int)uVar2;
        local_198 = uVar2 & 0xff |
                    (uint)CONCAT21(CONCAT11((char)iVar8,(char)iVar10),(char)iVar1) << 8;
        local_d8 = (double)CONCAT44(0x43300000,uVar11);
        uVar16 = (uint)(byte)this[0x2494];
        uStack220 = uVar16 - uVar11 ^ 0x80000000;
        iVar8 = (int)((float)(local_d8 - d_menu_collect::_4290) +
                     (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack220) -
                                                     d_menu_collect::_4443)));
        local_e8 = (double)(longlong)iVar8;
        local_f0 = (double)CONCAT44(0x43300000,uVar9);
        uVar11 = (uint)(byte)this[0x2495];
        uStack244 = uVar11 - uVar9 ^ 0x80000000;
        iVar10 = (int)((float)(local_f0 - d_menu_collect::_4290) +
                      (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack244) -
                                                      d_menu_collect::_4443)));
        local_100 = (double)(longlong)iVar10;
        local_108 = (double)CONCAT44(0x43300000,uVar7);
        uVar9 = (uint)(byte)this[0x2496];
        uStack268 = uVar9 - uVar7 ^ 0x80000000;
        iVar1 = (int)((float)(local_108 - d_menu_collect::_4290) +
                     (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack268) -
                                                     d_menu_collect::_4443)));
        local_118 = (double)(longlong)iVar1;
        local_120 = (double)CONCAT44(0x43300000,uVar6);
        uVar7 = (uint)(byte)this[0x2497];
        uStack292 = uVar7 - uVar6 ^ 0x80000000;
        uVar2 = (uint)((float)(local_120 - d_menu_collect::_4290) +
                      (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack292) -
                                                      d_menu_collect::_4443)));
        local_130 = (double)(longlong)(int)uVar2;
        local_19c = uVar2 & 0xff |
                    (uint)CONCAT21(CONCAT11((char)iVar8,(char)iVar10),(char)iVar1) << 8;
        local_138 = (double)CONCAT44(0x43300000,uVar16);
        uStack316 = uVar12 - uVar16 ^ 0x80000000;
        iVar8 = (int)((float)(local_138 - d_menu_collect::_4290) +
                     (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack316) -
                                                     d_menu_collect::_4443)));
        local_148 = (double)(longlong)iVar8;
        local_150 = (double)CONCAT44(0x43300000,uVar11);
        uStack340 = uVar13 - uVar11 ^ 0x80000000;
        iVar10 = (int)((float)(local_150 - d_menu_collect::_4290) +
                      (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack340) -
                                                      d_menu_collect::_4443)));
        local_160 = (double)(longlong)iVar10;
        local_168 = (double)CONCAT44(0x43300000,uVar9);
        uStack364 = uVar14 - uVar9 ^ 0x80000000;
        iVar1 = (int)((float)(local_168 - d_menu_collect::_4290) +
                     (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack364) -
                                                     d_menu_collect::_4443)));
        local_178 = (double)(longlong)iVar1;
        local_180 = (double)CONCAT44(0x43300000,uVar7);
        uStack388 = uVar15 - uVar7 ^ 0x80000000;
        uVar2 = (uint)((float)(local_180 - d_menu_collect::_4290) +
                      (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack388) -
                                                      d_menu_collect::_4443)));
        local_190 = (double)(longlong)(int)uVar2;
        local_1a0 = uVar2 & 0xff |
                    (uint)CONCAT21(CONCAT11((char)iVar8,(char)iVar10),(char)iVar1) << 8;
      }
      else {
        uVar13 = (uint)(byte)this[0x2488];
        local_18 = (double)CONCAT44(0x43300000,uVar13);
        uVar11 = (uint)(byte)this[0x2490];
        local_20 = (double)CONCAT44(0x43300000,uVar11 - uVar13 ^ 0x80000000);
        iVar8 = (int)((float)(local_18 - d_menu_collect::_4290) +
                     (float)(dVar17 * (double)(float)(local_20 - d_menu_collect::_4443)));
        local_28 = (double)(longlong)iVar8;
        uVar14 = (uint)(byte)this[0x2489];
        local_30 = (double)CONCAT44(0x43300000,uVar14);
        uVar9 = (uint)(byte)this[0x2491];
        uStack52 = uVar9 - uVar14 ^ 0x80000000;
        iVar10 = (int)((float)(local_30 - d_menu_collect::_4290) +
                      (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack52) -
                                                      d_menu_collect::_4443)));
        local_40 = (double)(longlong)iVar10;
        uVar15 = (uint)(byte)this[0x248a];
        local_48 = (double)CONCAT44(0x43300000,uVar15);
        uVar7 = (uint)(byte)this[0x2492];
        uStack76 = uVar7 - uVar15 ^ 0x80000000;
        iVar1 = (int)((float)(local_48 - d_menu_collect::_4290) +
                     (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack76) -
                                                     d_menu_collect::_4443)));
        local_58 = (double)(longlong)iVar1;
        uVar16 = (uint)(byte)this[0x248b];
        local_60 = (double)CONCAT44(0x43300000,uVar16);
        uVar6 = (uint)(byte)this[0x2493];
        uStack100 = uVar6 - uVar16 ^ 0x80000000;
        uVar2 = (uint)((float)(local_60 - d_menu_collect::_4290) +
                      (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack100) -
                                                      d_menu_collect::_4443)));
        local_70 = (double)(longlong)(int)uVar2;
        local_198 = uVar2 & 0xff |
                    (uint)CONCAT21(CONCAT11((char)iVar8,(char)iVar10),(char)iVar1) << 8;
        uVar12 = (uint)(byte)this[0x248c];
        local_78 = (double)CONCAT44(0x43300000,uVar12);
        uStack124 = uVar13 - uVar12 ^ 0x80000000;
        iVar8 = (int)((float)(local_78 - d_menu_collect::_4290) +
                     (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack124) -
                                                     d_menu_collect::_4443)));
        local_88 = (double)(longlong)iVar8;
        uVar13 = (uint)(byte)this[0x248d];
        local_90 = (double)CONCAT44(0x43300000,uVar13);
        uStack148 = uVar14 - uVar13 ^ 0x80000000;
        iVar10 = (int)((float)(local_90 - d_menu_collect::_4290) +
                      (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack148) -
                                                      d_menu_collect::_4443)));
        local_a0 = (double)(longlong)iVar10;
        uVar14 = (uint)(byte)this[0x248e];
        local_a8 = (double)CONCAT44(0x43300000,uVar14);
        uStack172 = uVar15 - uVar14 ^ 0x80000000;
        iVar1 = (int)((float)(local_a8 - d_menu_collect::_4290) +
                     (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack172) -
                                                     d_menu_collect::_4443)));
        local_b8 = (double)(longlong)iVar1;
        uVar15 = (uint)(byte)this[0x248f];
        local_c0 = (double)CONCAT44(0x43300000,uVar15);
        uStack196 = uVar16 - uVar15 ^ 0x80000000;
        uVar2 = (uint)((float)(local_c0 - d_menu_collect::_4290) +
                      (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack196) -
                                                      d_menu_collect::_4443)));
        local_d0 = (double)(longlong)(int)uVar2;
        local_1a0 = uVar2 & 0xff |
                    (uint)CONCAT21(CONCAT11((char)iVar8,(char)iVar10),(char)iVar1) << 8;
        local_d8 = (double)CONCAT44(0x43300000,uVar11);
        uVar16 = (uint)(byte)this[0x2494];
        uStack220 = uVar16 - uVar11 ^ 0x80000000;
        iVar8 = (int)((float)(local_d8 - d_menu_collect::_4290) +
                     (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack220) -
                                                     d_menu_collect::_4443)));
        local_e8 = (double)(longlong)iVar8;
        local_f0 = (double)CONCAT44(0x43300000,uVar9);
        uVar11 = (uint)(byte)this[0x2495];
        uStack244 = uVar11 - uVar9 ^ 0x80000000;
        iVar10 = (int)((float)(local_f0 - d_menu_collect::_4290) +
                      (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack244) -
                                                      d_menu_collect::_4443)));
        local_100 = (double)(longlong)iVar10;
        local_108 = (double)CONCAT44(0x43300000,uVar7);
        uVar9 = (uint)(byte)this[0x2496];
        uStack268 = uVar9 - uVar7 ^ 0x80000000;
        iVar1 = (int)((float)(local_108 - d_menu_collect::_4290) +
                     (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack268) -
                                                     d_menu_collect::_4443)));
        local_118 = (double)(longlong)iVar1;
        local_120 = (double)CONCAT44(0x43300000,uVar6);
        uVar7 = (uint)(byte)this[0x2497];
        uStack292 = uVar7 - uVar6 ^ 0x80000000;
        uVar2 = (uint)((float)(local_120 - d_menu_collect::_4290) +
                      (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack292) -
                                                      d_menu_collect::_4443)));
        local_130 = (double)(longlong)(int)uVar2;
        local_194 = uVar2 & 0xff |
                    (uint)CONCAT21(CONCAT11((char)iVar8,(char)iVar10),(char)iVar1) << 8;
        local_138 = (double)CONCAT44(0x43300000,uVar16);
        uStack316 = uVar12 - uVar16 ^ 0x80000000;
        iVar8 = (int)((float)(local_138 - d_menu_collect::_4290) +
                     (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack316) -
                                                     d_menu_collect::_4443)));
        local_148 = (double)(longlong)iVar8;
        local_150 = (double)CONCAT44(0x43300000,uVar11);
        uStack340 = uVar13 - uVar11 ^ 0x80000000;
        iVar10 = (int)((float)(local_150 - d_menu_collect::_4290) +
                      (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack340) -
                                                      d_menu_collect::_4443)));
        local_160 = (double)(longlong)iVar10;
        local_168 = (double)CONCAT44(0x43300000,uVar9);
        uStack364 = uVar14 - uVar9 ^ 0x80000000;
        iVar1 = (int)((float)(local_168 - d_menu_collect::_4290) +
                     (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack364) -
                                                     d_menu_collect::_4443)));
        local_178 = (double)(longlong)iVar1;
        local_180 = (double)CONCAT44(0x43300000,uVar7);
        uStack388 = uVar15 - uVar7 ^ 0x80000000;
        uVar2 = (uint)((float)(local_180 - d_menu_collect::_4290) +
                      (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack388) -
                                                      d_menu_collect::_4443)));
        local_190 = (double)(longlong)(int)uVar2;
        local_19c = uVar2 & 0xff |
                    (uint)CONCAT21(CONCAT11((char)iVar8,(char)iVar10),(char)iVar1) << 8;
      }
    }
  }
  local_38 = 0x43300000;
  local_50 = 0x43300000;
  local_68 = 0x43300000;
  local_80 = 0x43300000;
  local_98 = 0x43300000;
  local_b0 = 0x43300000;
  local_c8 = 0x43300000;
  local_e0 = 0x43300000;
  local_f8 = 0x43300000;
  local_110 = 0x43300000;
  local_128 = 0x43300000;
  local_140 = 0x43300000;
  local_158 = 0x43300000;
  local_170 = 0x43300000;
  local_188 = 0x43300000;
  local_1b0 = local_1a0;
  local_1ac = local_19c;
  local_1a8 = local_198;
  local_1a4 = local_194;
  local_1bc[0] = local_194;
  local_1c0 = local_198;
  local_1c4 = local_19c;
  local_1c8 = local_1a0;
  J2DWindow::setContentsColor
            (*(J2DWindow **)(this + 0xba0),(TColor)&local_1c8,(TColor)&local_1c4,(TColor)&local_1c0,
             (TColor)local_1bc);
  *(short *)(this + 0x27e8) = *(short *)(this + 0x27e8) + 1;
  if ((int)DAT_803e6024 << 1 <= (int)*(short *)(this + 0x27e8)) {
    *(undefined2 *)(this + 0x27e8) = 0;
  }
  iVar10 = (int)*(short *)(this + 0x27e8);
  iVar8 = (int)DAT_803e6024;
  if (iVar10 < iVar8) {
    dVar17 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar8,iVar10,0);
  }
  else {
    dVar17 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar8,iVar8 * 2 - iVar10,0);
  }
  local_18 = (double)CONCAT44(0x43300000,(uint)DAT_803e602c);
  local_28 = (double)CONCAT44(0x43300000,(uint)DAT_803e602d);
  fVar5 = d_menu_collect::_6283 -
          (float)((double)(d_menu_collect::_6283 - (float)(local_28 - d_menu_collect::_4290)) *
                 dVar17);
  dVar3 = (double)CONCAT44(0x43300000,(uint)DAT_803e602e) - d_menu_collect::_4290;
  iVar8 = *(int *)(this + 0xba0);
  *(char *)(iVar8 + 0x104) =
       (char)(int)(d_menu_collect::_6282 -
                  (float)((double)(d_menu_collect::_6282 - (float)(local_18 - d_menu_collect::_4290)
                                  ) * dVar17));
  *(char *)(iVar8 + 0x105) = (char)(int)fVar5;
  *(char *)(iVar8 + 0x106) = (char)(int)-(float)(-(double)(float)dVar3 * dVar17);
  *(undefined *)(iVar8 + 0x107) = 0xff;
  return;
}


/* __thiscall dMenu_Collect_c::triforceAnime(unsigned char) */

void __thiscall dMenu_Collect_c::triforceAnime(dMenu_Collect_c *this,uchar param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  double local_18;
  double local_10;
  
  iVar3 = (int)DAT_803e6022;
  *(short *)(this + 0xe06) = *(short *)(this + 0xe06) + 1;
  iVar1 = iVar3 * 2;
  if (iVar1 <= *(short *)(this + 0xe06)) {
    *(undefined2 *)(this + 0xe06) = 0;
  }
  iVar2 = (int)*(short *)(this + 0xe06);
  if (iVar2 < iVar3) {
    dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar3,iVar2,0);
    local_18 = (double)CONCAT44(0x43300000,(uint)param_1);
    this[0xe05] = SUB41((int)((double)(float)(local_18 - d_menu_collect::_4290) * dVar4),0);
  }
  else {
    if (iVar2 < iVar1) {
      dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar3,iVar1 - iVar2,0);
      local_10 = (double)CONCAT44(0x43300000,(uint)param_1);
      this[0xe05] = SUB41((int)((double)(float)(local_10 - d_menu_collect::_4290) * dVar4),0);
    }
  }
  return;
}


/* __thiscall dMenu_Collect_c::tactGuideHide(void) */

void __thiscall dMenu_Collect_c::tactGuideHide(dMenu_Collect_c *this)

{
  int iVar1;
  dMenu_Collect_c *pdVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = 6;
  do {
    pdVar2 = this + iVar1;
    *(undefined2 *)(pdVar2 + 0x1e6e) = 0;
    *(undefined *)(*(int *)(pdVar2 + 0x17a8) + 0xaa) = 0;
    *(undefined *)(*(int *)(pdVar2 + 0x18f8) + 0xaa) = 0;
    *(undefined *)(*(int *)(pdVar2 + 0x1a48) + 0xaa) = 0;
    *(undefined *)(*(int *)(pdVar2 + 0x1b98) + 0xaa) = 0;
    *(undefined *)(*(int *)(pdVar2 + 0x1ce8) + 0xaa) = 0;
    *(undefined *)(*(int *)(pdVar2 + 0x1e38) + 0xaa) = 0;
    iVar1 = iVar1 + 0x38;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801a2b04) */
/* WARNING: Removing unreachable block (ram,0x801a2c88) */
/* __thiscall dMenu_Collect_c::itemnameMove(void) */

void __thiscall dMenu_Collect_c::itemnameMove(dMenu_Collect_c *this)

{
  dMenu_Collect_c dVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar1 = this[0x27ed];
  if ((dVar1 == (dMenu_Collect_c)0x12) || (((byte)dVar1 < 0x12 && ((byte)dVar1 < 8)))) {
    *(short *)(this + 0x88e) = *(short *)(this + 0x88e) + 1;
    if (0x82 < *(short *)(this + 0x88e)) {
      *(undefined2 *)(this + 0x88e) = 0xb;
    }
    iVar2 = (int)*(short *)(this + 0x88e);
    if (iVar2 < 0xb) {
      dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,iVar2,0);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x890),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlpha
                ((fopMsgM_pane_class *)(this + 0x8c8),(float)((double)d_menu_collect::_4440 - dVar4)
                );
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x858));
    }
    else {
      if (iVar2 < 0x3d) {
        f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x890);
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x858));
      }
      else {
        if (iVar2 < 0x47) {
          dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,iVar2 + -0x3c,0);
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(this + 0x890),
                     (float)((double)d_menu_collect::_4440 - dVar4));
          f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x858),(float)dVar4);
        }
        else {
          if (iVar2 < 0x79) {
            f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x890));
            f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x858);
          }
          else {
            if (iVar2 < 0x83) {
              dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,iVar2 + -0x78,0);
              f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x890),(float)dVar4);
              f_op_msg_mng::fopMsgM_setNowAlpha
                        ((fopMsgM_pane_class *)(this + 0x858),
                         (float)((double)d_menu_collect::_4440 - dVar4));
            }
          }
        }
      }
    }
    dDlst_2DOutFont_c::move(*(dDlst_2DOutFont_c **)(this + 0x2460));
  }
  else {
    if (*(short *)(this + 0x88e) < 10) {
      *(short *)(this + 0x88e) = *(short *)(this + 0x88e) + 1;
    }
    if (*(short *)(this + 0x88e) < 0xb) {
      dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(this + 0x88e),0);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x890),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlpha
                ((fopMsgM_pane_class *)(this + 0x8c8),(float)((double)d_menu_collect::_4440 - dVar4)
                );
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x858));
    }
    else {
      f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x890);
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x8c8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x858));
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801a3684) */
/* WARNING: Removing unreachable block (ram,0x801a368c) */
/* __thiscall dMenu_Collect_c::itemnameSet(void) */

void __thiscall dMenu_Collect_c::itemnameSet(dMenu_Collect_c *this)

{
  byte bVar1;
  undefined4 uVar2;
  float fVar3;
  bool bVar4;
  float fVar5;
  ushort uVar6;
  int iVar7;
  mesg_header *pmVar8;
  ushort *puVar9;
  uint uVar10;
  byte *pbVar11;
  ulong uVar12;
  undefined4 uVar13;
  undefined8 in_f30;
  double dVar14;
  double in_f31;
  byte local_98 [4];
  byte bStack148;
  byte local_93;
  byte local_90;
  byte local_8f;
  undefined local_8e;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
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
  
  fVar5 = d_menu_collect::_6788;
  uVar13 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,SUB84(in_f31,0),0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  local_5c = &fopMsgM_itemMsgGet_c::__vt;
  local_58 = 0;
  local_54 = 0;
  local_52 = 0;
  uVar12 = 0;
  pbVar11 = (byte *)0x0;
  local_70 = d_menu_collect::_6788;
  local_74 = d_menu_collect::_6788;
  local_7c = d_menu_collect::_6788;
  local_78 = d_menu_collect::_6788;
  iVar7 = *(int *)(this + 0x858);
  fVar3 = d_menu_collect::_4288;
  if (d_menu_collect::_4288 < d_menu_collect::_6788) {
    fVar3 = d_menu_collect::_6788;
  }
  *(float *)(iVar7 + 0xe8) = fVar3;
  fVar3 = d_menu_collect::_4288;
  if (d_menu_collect::_4288 < fVar5) {
    fVar3 = fVar5;
  }
  *(float *)(iVar7 + 0xec) = fVar3;
  local_84 = *(float *)(*(int *)(this + 0x890) + 0xe8);
  local_80 = *(float *)(*(int *)(this + 0x890) + 0xec);
  iVar7 = *(int *)(this + 0x8c8);
  fVar3 = d_menu_collect::_4288;
  if (d_menu_collect::_4288 < local_84) {
    fVar3 = local_84;
  }
  *(float *)(iVar7 + 0xe8) = fVar3;
  fVar3 = d_menu_collect::_4288;
  if (d_menu_collect::_4288 < local_80) {
    fVar3 = local_80;
  }
  *(float *)(iVar7 + 0xec) = fVar3;
  *(undefined4 *)(*(int *)(this + 0x8c8) + 0xe0) = *(undefined4 *)(*(int *)(this + 0x890) + 0xe0);
  for (; pbVar11[*(int *)(this + 0x27b0)] != 0; pbVar11 = pbVar11 + 1) {
    pbVar11[*(int *)(this + 0x27b4)] = pbVar11[*(int *)(this + 0x27b0)];
  }
  pbVar11[*(int *)(this + 0x27b4)] = 0;
  local_64 = local_84;
  local_60 = local_80;
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x8c8),*(char **)(this + 0x27b4),(___)pbVar11);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x27b0),"");
  if (this[0x27ee] == (dMenu_Collect_c)0x5) {
    uVar12 = SEXT24((short)((byte)this[0x27ed] + 0x1c2));
  }
  else {
    switch(this[0x27ed]) {
    case (dMenu_Collect_c)0x0:
      iVar7 = dSv_player_collect_c::isTact
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
      if (iVar7 != 0) {
        uVar12 = SEXT24(dItem_data::item_resource[109].mNameMessageId);
        dDlst_2DOutFont_c::messageSet(*(dDlst_2DOutFont_c **)(this + 0x2460),0x1fa);
        uVar2 = *(undefined4 *)(this + 0x868);
        iVar7 = *(int *)(this + 0x2460);
        *(undefined4 *)(iVar7 + 0x30) = *(undefined4 *)(this + 0x864);
        *(undefined4 *)(iVar7 + 0x34) = uVar2;
      }
      break;
    case (dMenu_Collect_c)0x1:
      iVar7 = dSv_player_collect_c::isTact
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x01');
      if (iVar7 != 0) {
        uVar12 = SEXT24(dItem_data::item_resource[110].mNameMessageId);
        dDlst_2DOutFont_c::messageSet(*(dDlst_2DOutFont_c **)(this + 0x2460),0x1fa);
        uVar2 = *(undefined4 *)(this + 0x868);
        iVar7 = *(int *)(this + 0x2460);
        *(undefined4 *)(iVar7 + 0x30) = *(undefined4 *)(this + 0x864);
        *(undefined4 *)(iVar7 + 0x34) = uVar2;
      }
      break;
    case (dMenu_Collect_c)0x2:
      iVar7 = dSv_player_collect_c::isTact
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x02');
      if (iVar7 != 0) {
        uVar12 = SEXT24(dItem_data::item_resource[112].mNameMessageId);
        dDlst_2DOutFont_c::messageSet(*(dDlst_2DOutFont_c **)(this + 0x2460),0x1fa);
        uVar2 = *(undefined4 *)(this + 0x868);
        iVar7 = *(int *)(this + 0x2460);
        *(undefined4 *)(iVar7 + 0x30) = *(undefined4 *)(this + 0x864);
        *(undefined4 *)(iVar7 + 0x34) = uVar2;
      }
      break;
    case (dMenu_Collect_c)0x3:
      iVar7 = dSv_player_collect_c::isTact
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x03');
      if (iVar7 != 0) {
        uVar12 = SEXT24(dItem_data::item_resource[113].mNameMessageId);
        dDlst_2DOutFont_c::messageSet(*(dDlst_2DOutFont_c **)(this + 0x2460),0x1fa);
        uVar2 = *(undefined4 *)(this + 0x868);
        iVar7 = *(int *)(this + 0x2460);
        *(undefined4 *)(iVar7 + 0x30) = *(undefined4 *)(this + 0x864);
        *(undefined4 *)(iVar7 + 0x34) = uVar2;
      }
      break;
    case (dMenu_Collect_c)0x4:
      iVar7 = dSv_player_collect_c::isTact
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x04');
      if (iVar7 != 0) {
        uVar12 = SEXT24(dItem_data::item_resource[114].mNameMessageId);
        dDlst_2DOutFont_c::messageSet(*(dDlst_2DOutFont_c **)(this + 0x2460),0x1fa);
        uVar2 = *(undefined4 *)(this + 0x868);
        iVar7 = *(int *)(this + 0x2460);
        *(undefined4 *)(iVar7 + 0x30) = *(undefined4 *)(this + 0x864);
        *(undefined4 *)(iVar7 + 0x34) = uVar2;
      }
      break;
    case (dMenu_Collect_c)0x5:
      iVar7 = dSv_player_collect_c::isTact
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x05');
      if (iVar7 != 0) {
        uVar12 = SEXT24(dItem_data::item_resource[111].mNameMessageId);
        dDlst_2DOutFont_c::messageSet(*(dDlst_2DOutFont_c **)(this + 0x2460),0x1fa);
        uVar2 = *(undefined4 *)(this + 0x868);
        iVar7 = *(int *)(this + 0x2460);
        *(undefined4 *)(iVar7 + 0x30) = *(undefined4 *)(this + 0x864);
        *(undefined4 *)(iVar7 + 0x34) = uVar2;
      }
      break;
    case (dMenu_Collect_c)0x6:
      uVar12 = 0x19d;
      dDlst_2DOutFont_c::messageSet(*(dDlst_2DOutFont_c **)(this + 0x2460),0x1fb);
      uVar2 = *(undefined4 *)(this + 0x868);
      iVar7 = *(int *)(this + 0x2460);
      *(undefined4 *)(iVar7 + 0x30) = *(undefined4 *)(this + 0x864);
      *(undefined4 *)(iVar7 + 0x34) = uVar2;
      break;
    case (dMenu_Collect_c)0x7:
      uVar12 = 0x1f8;
      dDlst_2DOutFont_c::messageSet(*(dDlst_2DOutFont_c **)(this + 0x2460),0x1fc);
      uVar2 = *(undefined4 *)(this + 0x868);
      iVar7 = *(int *)(this + 0x2460);
      *(undefined4 *)(iVar7 + 0x30) = *(undefined4 *)(this + 0x864);
      *(undefined4 *)(iVar7 + 0x34) = uVar2;
      break;
    case (dMenu_Collect_c)0x8:
      if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxHp & 3U) != 0) {
        uVar12 = SEXT24(dItem_data::item_resource[7].mNameMessageId);
      }
      break;
    case (dMenu_Collect_c)0x9:
      iVar7 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x908);
      if ((iVar7 != 0) ||
         (iVar7 = dSv_player_map_c::getCollectMapNum
                            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap),
         iVar7 != 0)) {
        uVar12 = 0x1f7;
      }
      break;
    case (dMenu_Collect_c)0xa:
      iVar7 = dSv_player_collect_c::getTriforceNum
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect);
      if (iVar7 == 8) {
        uVar12 = 0x1c4;
      }
      else {
        iVar7 = dSv_player_collect_c::getTriforceNum
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect);
        if (iVar7 == 0) {
          uVar12 = 0;
        }
        else {
          uVar12 = SEXT24(dItem_data::item_resource[97].mNameMessageId);
        }
      }
      break;
    case (dMenu_Collect_c)0xb:
      iVar7 = dSv_player_collect_c::isSymbol
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
      if (iVar7 != 0) {
        uVar12 = SEXT24(dItem_data::item_resource[105].mNameMessageId);
      }
      break;
    case (dMenu_Collect_c)0xc:
      iVar7 = dSv_player_collect_c::isSymbol
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x01');
      if (iVar7 != 0) {
        uVar12 = SEXT24(dItem_data::item_resource[106].mNameMessageId);
      }
      break;
    case (dMenu_Collect_c)0xd:
      iVar7 = dSv_player_collect_c::isSymbol
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x02');
      if (iVar7 != 0) {
        uVar12 = SEXT24(dItem_data::item_resource[107].mNameMessageId);
      }
      break;
    case (dMenu_Collect_c)0xe:
      uVar12 = SEXT24(dItem_data::item_resource
                      [d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                       mEquippedSword].mNameMessageId);
      if (uVar12 == 0) {
        uVar12 = 0;
      }
      break;
    case (dMenu_Collect_c)0xf:
      uVar12 = SEXT24(dItem_data::item_resource
                      [d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                       mEquippedShield].mNameMessageId);
      if (uVar12 == 0) {
        uVar12 = 0;
      }
      break;
    case (dMenu_Collect_c)0x10:
      uVar12 = SEXT24(dItem_data::item_resource
                      [d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                       mEquippedBracelets].mNameMessageId);
      if (uVar12 == 0) {
        uVar12 = 0;
      }
      break;
    case (dMenu_Collect_c)0x11:
      pbVar11 = (byte *)0x0;
      uVar10 = dSv_player_collect_c::isCollect
                         (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,3,0);
      if (uVar10 != 0) {
        uVar12 = SEXT24(dItem_data::item_resource[66].mNameMessageId);
      }
      break;
    case (dMenu_Collect_c)0x12:
      pbVar11 = (byte *)0x0;
      uVar10 = dSv_player_collect_c::isCollect
                         (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,4,0);
      if (uVar10 != 0) {
        uVar12 = SEXT24(dItem_data::item_resource[67].mNameMessageId);
        dDlst_2DOutFont_c::messageSet(*(dDlst_2DOutFont_c **)(this + 0x2460),0x1fd);
        uVar2 = *(undefined4 *)(this + 0x868);
        iVar7 = *(int *)(this + 0x2460);
        *(undefined4 *)(iVar7 + 0x30) = *(undefined4 *)(this + 0x864);
        *(undefined4 *)(iVar7 + 0x34) = uVar2;
      }
      break;
    case (dMenu_Collect_c)0x13:
      iVar7 = dSv_player_collect_c::isTact
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
      if ((((iVar7 == 0) &&
           (iVar7 = dSv_player_collect_c::isTact
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                               '\x01'), iVar7 == 0)) &&
          ((iVar7 = dSv_player_collect_c::isTact
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                               '\x02'), iVar7 == 0 &&
           ((iVar7 = dSv_player_collect_c::isTact
                               (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                                '\x03'), iVar7 == 0 &&
            (iVar7 = dSv_player_collect_c::isTact
                               (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                                '\x04'), iVar7 == 0)))))) &&
         (iVar7 = dSv_player_collect_c::isTact
                            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                             '\x05'), iVar7 == 0)) {
        uVar12 = 0;
      }
      else {
        uVar12 = 0;
      }
      break;
    case (dMenu_Collect_c)0x14:
      iVar7 = dSv_player_collect_c::isSymbol
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
      if (((iVar7 == 0) &&
          (iVar7 = dSv_player_collect_c::isSymbol
                             (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                              '\x01'), iVar7 == 0)) &&
         (iVar7 = dSv_player_collect_c::isSymbol
                            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                             '\x02'), iVar7 == 0)) {
        uVar12 = 0;
      }
      else {
        uVar12 = 0;
      }
    }
  }
  if (uVar12 == 0) {
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x890),*(char **)(this + 0x27b0),(___)pbVar11);
  }
  else {
    pmVar8 = (mesg_header *)
             fopMsgM_itemMsgGet_c::getMesgHeader((fopMsgM_itemMsgGet_c *)&local_5c,uVar12);
    if (pmVar8 == (mesg_header *)0x0) {
      uVar12 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar12,"d_menu_collect.cpp",0xbd1,"head_p");
      pbVar11 = &DAT_8035f4b6;
      m_Do_printf::OSPanic("d_menu_collect.cpp",0xbd1);
    }
    local_6c = *(float *)(*(int *)(this + 0x890) + 0xec);
    local_68 = local_6c;
    puVar9 = (ushort *)fopMsgM_itemMsgGet_c::getMessage((fopMsgM_itemMsgGet_c *)&local_5c,pmVar8);
    bVar4 = false;
    uVar10 = (**(code **)(**(int **)(this + 0x2470) + 0x30))();
    local_50 = (double)CONCAT44(0x43300000,uVar10 ^ 0x80000000);
    dVar14 = (double)(local_68 / (float)(local_50 - d_menu_collect::_4443));
    while (*(byte *)puVar9 != 0) {
      local_8e = 0;
      local_8f = 0;
      local_90 = 0;
      bVar1 = *(byte *)puVar9;
      uVar6 = (ushort)bVar1;
      if (uVar6 == 0x1a) {
        puVar9 = (ushort *)((byte *)((int)puVar9 + 1) + (char)*(byte *)((int)puVar9 + 1) + -1);
      }
      else {
        if ((bVar1 >> 4 == 8) || (bVar1 >> 4 == 9)) {
          local_90 = *(byte *)puVar9;
          local_8f = *(byte *)((int)puVar9 + 1);
          uVar6 = *puVar9;
          puVar9 = puVar9 + 1;
        }
        else {
          local_8f = 0;
          puVar9 = (ushort *)((int)puVar9 + 1);
          local_90 = bVar1;
        }
        local_8e = 0;
        pbVar11 = &bStack148;
        (**(code **)(**(int **)(this + 0x2470) + 0x2c))(*(int **)(this + 0x2470),uVar6);
        uVar10 = (uint)local_93;
        MSL_C.PPCEABI.bare.H::strcat(*(char **)(this + 0x27b0),(char *)&local_90);
        if (bVar4) {
          local_50 = (double)CONCAT44(0x43300000,uVar10 ^ 0x80000000);
          in_f31 = (double)(float)(in_f31 + (double)(float)((double)(float)(local_50 -
                                                                           d_menu_collect::_4443) *
                                                           dVar14));
        }
        else {
          pbVar11 = local_98;
          (**(code **)(**(int **)(this + 0x2470) + 0x2c))(*(int **)(this + 0x2470),uVar6);
          local_50 = (double)CONCAT44(0x43300000,uVar10 + local_98[0] ^ 0x80000000);
          in_f31 = (double)(float)(dVar14 * (double)(float)(local_50 - d_menu_collect::_4443));
          bVar4 = true;
        }
      }
    }
    iVar7 = *(int *)(this + 0x890);
    dVar14 = (double)(*(float *)(iVar7 + 0x14) - *(float *)(iVar7 + 0xc));
    if (dVar14 < in_f31) {
      uStack68 = (uint)((double)(float)((double)local_6c * dVar14) / in_f31);
      local_50 = (double)(longlong)(int)uStack68;
      uStack68 = uStack68 ^ 0x80000000;
      local_48 = 0x43300000;
      local_6c = (float)((double)CONCAT44(0x43300000,uStack68) - d_menu_collect::_4443);
    }
    local_8c = local_6c;
    local_88 = local_68;
    fVar3 = d_menu_collect::_4288;
    if (d_menu_collect::_4288 < local_6c) {
      fVar3 = local_6c;
    }
    *(float *)(iVar7 + 0xe8) = fVar3;
    fVar3 = d_menu_collect::_4288;
    if (d_menu_collect::_4288 < local_68) {
      fVar3 = local_68;
    }
    *(float *)(iVar7 + 0xec) = fVar3;
    *(float *)(*(int *)(this + 0x890) + 0xe0) = d_menu_collect::_4288;
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x890),*(char **)(this + 0x27b0),(___)pbVar11);
  }
  __psq_l0(auStack8,uVar13);
  __psq_l1(auStack8,uVar13);
  __psq_l0(auStack24,uVar13);
  __psq_l1(auStack24,uVar13);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x801a42b0) */
/* __thiscall dMenu_Collect_c::itemnoteSet(void) */

void __thiscall dMenu_Collect_c::itemnoteSet(dMenu_Collect_c *this)

{
  double dVar1;
  double dVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  mesg_header *pmVar6;
  undefined4 uVar7;
  dMenu_Collect_c *pdVar8;
  undefined2 *puVar9;
  ___ _Var10;
  int iVar11;
  uint uVar12;
  dMenu_Collect_c *pdVar13;
  J2DPicture *this_00;
  int iVar14;
  int iVar15;
  ulong uVar16;
  uint uVar17;
  int iVar18;
  undefined4 uVar19;
  undefined8 in_f31;
  double dVar20;
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
  
  uVar19 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  local_a8 = &fopMsgM_itemMsgGet_c::__vt;
  local_a4 = 0;
  local_a0 = 0;
  local_9e = 0;
  uVar16 = 0;
  iVar18 = 0;
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ == '\0') {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x778),(double)d_menu_collect::_4288,
               (double)d_menu_collect::_4288);
  }
  else {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x778),(double)d_menu_collect::_4288,
               (double)d_menu_collect::_7299);
  }
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x27b8),"");
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x27bc),"");
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x27c0),"");
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x27c4),"");
  outFontInit(this);
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ == '\0') {
    *(undefined *)(*(int *)(this + 0x740) + 0xaa) = 1;
  }
  else {
    *(undefined *)(*(int *)(this + 0x740) + 0xaa) = 0;
  }
  dVar20 = (double)*(float *)(*(int *)(this + 0x740) + 0xe8);
  local_68 = (double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U);
  dVar1 = local_68 - d_menu_collect::_4443;
  fVar3 = (float)dVar1;
  local_60 = (double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U);
  dVar2 = local_60 - d_menu_collect::_4443;
  iVar5 = *(int *)(this + 0x778);
  fVar4 = d_menu_collect::_4288;
  if (d_menu_collect::_4288 < fVar3) {
    fVar4 = fVar3;
  }
  *(float *)(iVar5 + 0xe8) = fVar4;
  fVar3 = d_menu_collect::_4288;
  if (d_menu_collect::_4288 < (float)dVar2) {
    fVar3 = (float)dVar2;
  }
  *(float *)(iVar5 + 0xec) = fVar3;
  local_58 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000);
  *(float *)(*(int *)(this + 0x778) + 0xe4) = (float)(local_58 - d_menu_collect::_4443);
  switch(this[0x27ed]) {
  case (dMenu_Collect_c)0x0:
    iVar18 = dSv_player_collect_c::isTact
                       (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
    if (iVar18 != 0) {
      uVar16 = (int)dItem_data::item_resource[109].mNameMessageId + 200;
    }
    break;
  case (dMenu_Collect_c)0x1:
    iVar18 = dSv_player_collect_c::isTact
                       (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x01');
    if (iVar18 != 0) {
      uVar16 = (int)dItem_data::item_resource[110].mNameMessageId + 200;
    }
    break;
  case (dMenu_Collect_c)0x2:
    iVar18 = dSv_player_collect_c::isTact
                       (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x02');
    if (iVar18 != 0) {
      uVar16 = (int)dItem_data::item_resource[111].mNameMessageId + 200;
    }
    break;
  case (dMenu_Collect_c)0x3:
    iVar18 = dSv_player_collect_c::isTact
                       (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x03');
    if (iVar18 != 0) {
      uVar16 = (int)dItem_data::item_resource[112].mNameMessageId + 200;
    }
    break;
  case (dMenu_Collect_c)0x4:
    iVar18 = dSv_player_collect_c::isTact
                       (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x04');
    if (iVar18 != 0) {
      uVar16 = (int)dItem_data::item_resource[113].mNameMessageId + 200;
    }
    break;
  case (dMenu_Collect_c)0x5:
    iVar18 = dSv_player_collect_c::isTact
                       (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x05');
    if (iVar18 != 0) {
      uVar16 = (int)dItem_data::item_resource[114].mNameMessageId + 200;
    }
    break;
  case (dMenu_Collect_c)0x6:
    uVar16 = 0x265;
    break;
  case (dMenu_Collect_c)0x7:
    uVar16 = 0x2c0;
    break;
  case (dMenu_Collect_c)0x8:
    if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxHp & 3U) != 0) {
      uVar16 = (int)dItem_data::item_resource[7].mNameMessageId + 200;
    }
    break;
  case (dMenu_Collect_c)0x9:
    iVar18 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x908)
    ;
    if ((iVar18 != 0) ||
       (iVar18 = dSv_player_map_c::getCollectMapNum
                           (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap),
       iVar18 != 0)) {
      uVar16 = 0x2bf;
    }
    break;
  case (dMenu_Collect_c)0xa:
    iVar5 = 0;
    do {
      iVar14 = dSv_player_collect_c::isTriforce
                         (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                          (uchar)iVar5);
      if (iVar14 != 0) {
        iVar18 = iVar18 + 1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 8);
    if (0 < iVar18) {
      if (iVar18 == 8) {
        uVar16 = 0x28c;
      }
      else {
        uVar16 = (int)dItem_data::item_resource[97].mNameMessageId + 200;
      }
    }
    break;
  case (dMenu_Collect_c)0xb:
    iVar18 = dSv_player_collect_c::isSymbol
                       (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
    if (iVar18 != 0) {
      uVar16 = (int)dItem_data::item_resource[105].mNameMessageId + 200;
    }
    break;
  case (dMenu_Collect_c)0xc:
    iVar18 = dSv_player_collect_c::isSymbol
                       (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x01');
    if (iVar18 != 0) {
      uVar16 = (int)dItem_data::item_resource[106].mNameMessageId + 200;
    }
    break;
  case (dMenu_Collect_c)0xd:
    iVar18 = dSv_player_collect_c::isSymbol
                       (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x02');
    if (iVar18 != 0) {
      uVar16 = (int)dItem_data::item_resource[107].mNameMessageId + 200;
    }
    break;
  case (dMenu_Collect_c)0xe:
    if (dItem_data::item_resource
        [d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedSword].
        mNameMessageId == 0) {
      uVar16 = 0x25c;
    }
    else {
      uVar16 = (int)dItem_data::item_resource
                    [d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                     mEquippedSword].mNameMessageId + 200;
    }
    break;
  case (dMenu_Collect_c)0xf:
    if (dItem_data::item_resource
        [d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedShield].
        mNameMessageId == 0) {
      uVar16 = 0x25c;
    }
    else {
      uVar16 = (int)dItem_data::item_resource
                    [d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                     mEquippedShield].mNameMessageId + 200;
    }
    break;
  case (dMenu_Collect_c)0x10:
    if (dItem_data::item_resource
        [d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedBracelets].
        mNameMessageId == 0) {
      uVar16 = 0x25c;
    }
    else {
      uVar16 = (int)dItem_data::item_resource
                    [d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                     mEquippedBracelets].mNameMessageId + 200;
    }
    break;
  case (dMenu_Collect_c)0x11:
    uVar17 = dSv_player_collect_c::isCollect
                       (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,3,0);
    if (uVar17 != 0) {
      uVar16 = (int)dItem_data::item_resource[66].mNameMessageId + 200;
    }
    break;
  case (dMenu_Collect_c)0x12:
    uVar17 = dSv_player_collect_c::isCollect
                       (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,4,0);
    if (uVar17 != 0) {
      uVar16 = (int)dItem_data::item_resource[67].mNameMessageId + 200;
    }
    break;
  case (dMenu_Collect_c)0x13:
    iVar18 = dSv_player_collect_c::isTact
                       (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
    if ((((iVar18 == 0) &&
         (iVar18 = dSv_player_collect_c::isTact
                             (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                              '\x01'), iVar18 == 0)) &&
        ((iVar18 = dSv_player_collect_c::isTact
                             (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                              '\x02'), iVar18 == 0 &&
         ((iVar18 = dSv_player_collect_c::isTact
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                               '\x03'), iVar18 == 0 &&
          (iVar18 = dSv_player_collect_c::isTact
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                               '\x04'), iVar18 == 0)))))) &&
       (iVar18 = dSv_player_collect_c::isTact
                           (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                            '\x05'), iVar18 == 0)) {
      uVar16 = 0;
    }
    else {
      uVar16 = 0x25c;
    }
    break;
  case (dMenu_Collect_c)0x14:
    iVar18 = dSv_player_collect_c::isSymbol
                       (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
    if (((iVar18 == 0) &&
        (iVar18 = dSv_player_collect_c::isSymbol
                            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                             '\x01'), iVar18 == 0)) &&
       (iVar18 = dSv_player_collect_c::isSymbol
                           (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                            '\x02'), iVar18 == 0)) {
      uVar16 = 0;
    }
    else {
      uVar16 = 0x25c;
    }
  }
  if (uVar16 != 0) {
    pmVar6 = (mesg_header *)
             fopMsgM_itemMsgGet_c::getMesgHeader((fopMsgM_itemMsgGet_c *)&local_a8,uVar16);
    if (pmVar6 == (mesg_header *)0x0) {
      uVar16 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar16,"d_menu_collect.cpp",0xcd3,"head_p");
      m_Do_printf::OSPanic("d_menu_collect.cpp",0xcd3,&DAT_8035f4b6);
    }
    uVar7 = fopMsgM_itemMsgGet_c::getMessage((fopMsgM_itemMsgGet_c *)&local_a8,pmVar6);
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
    fopMsgM_msgDataProc_c::dataInit((fopMsgM_msgDataProc_c *)(this + 0x24e0));
    *(undefined4 *)(this + 0x251c) = uVar7;
    _Var10 = *(___ *)(this + 0x27c4);
    *(undefined4 *)(this + 0x2540) = *(undefined4 *)(this + 0x27b8);
    *(undefined4 *)(this + 0x2520) = *(undefined4 *)(this + 0x27b8);
    *(undefined4 *)(this + 0x2544) = *(undefined4 *)(this + 0x27bc);
    *(undefined4 *)(this + 0x2524) = *(undefined4 *)(this + 0x27bc);
    *(undefined4 *)(this + 0x2548) = *(undefined4 *)(this + 0x27c0);
    *(undefined4 *)(this + 0x2528) = *(undefined4 *)(this + 0x27c0);
    *(___ *)(this + 0x254c) = _Var10;
    *(___ *)(this + 0x252c) = _Var10;
    *(undefined4 *)(this + 0x24e4) = *(undefined4 *)(this + 0x2470);
    *(undefined4 *)(this + 0x24e8) = *(undefined4 *)(this + 0x2474);
    local_58 = (double)(longlong)(int)*(float *)(*(int *)(this + 0x778) + 0xe0);
    *(int *)(this + 0x25fc) = (int)*(float *)(*(int *)(this + 0x778) + 0xe0);
    local_60 = (double)(longlong)(int)*(float *)(*(int *)(this + 0x740) + 0xe0);
    *(int *)(this + 0x2604) = (int)*(float *)(*(int *)(this + 0x740) + 0xe0);
    local_68 = (double)(longlong)(int)*(float *)(*(int *)(this + 0x778) + 0xe4);
    *(int *)(this + 0x2600) = (int)*(float *)(*(int *)(this + 0x778) + 0xe4);
    *(undefined4 **)(this + 0x24ec) = &local_84;
    iVar18 = (int)dVar1;
    local_50 = (longlong)iVar18;
    *(int *)(this + 0x2624) = iVar18;
    local_48 = (double)(longlong)(int)dVar20;
    *(int *)(this + 0x262c) = (int)dVar20;
    *(undefined4 *)(this + 0x2608) = 0x1fe;
    *(undefined4 *)(this + 0x260c) = 0x1e6;
    *(undefined4 *)(this + 0x2640) = 2;
    *(undefined4 *)(this + 0x263c) = 0;
    this[0x2779] = (dMenu_Collect_c)0x1;
    this[0x277c] = (dMenu_Collect_c)0x0;
    fopMsgM_msgDataProc_c::stringLength((fopMsgM_msgDataProc_c *)(this + 0x24e0));
    fopMsgM_msgDataProc_c::stringShift((fopMsgM_msgDataProc_c *)(this + 0x24e0));
    fopMsgM_msgDataProc_c::iconIdxRefresh((fopMsgM_msgDataProc_c *)(this + 0x24e0));
    uVar7 = *(undefined4 *)(this + 0x2610);
    *(undefined4 *)(this + 0x2610) = 0;
    fVar4 = d_menu_collect::_4288;
    uVar17 = 3 - (int)(short)uVar7;
    uStack60 = uVar17 ^ 0x80000000;
    local_40 = 0x43300000;
    fVar3 = (float)((double)CONCAT44(0x43300000,uStack60) - d_menu_collect::_4443) *
            *(float *)(*(int *)(this + 0x778) + 0xe4) * d_menu_collect::_4287;
    iVar18 = *(int *)(this + 0x740);
    *(float *)(iVar18 + 0xd8) = d_menu_collect::_4288;
    *(float *)(iVar18 + 0xdc) = fVar3;
    iVar18 = *(int *)(this + 0x778);
    *(float *)(iVar18 + 0xd8) = fVar4;
    *(float *)(iVar18 + 0xdc) = fVar3;
    fopMsgM_msgDataProc_c::stringSet((fopMsgM_msgDataProc_c *)(this + 0x24e0));
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x778),*(char **)(this + 0x27b8),_Var10);
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x740),*(char **)(this + 0x27bc),_Var10);
    iVar18 = (int)(*(float *)(*(int *)(this + 0x778) + 0xe4) * d_menu_collect::_4287);
    iVar15 = 0;
    iVar14 = 0;
    iVar5 = 0;
    do {
      dVar1 = d_menu_collect::_4443;
      uVar12 = (uint)(byte)this[iVar15 + 0x2761];
      pdVar8 = this + iVar5;
      iVar11 = *(int *)(pdVar8 + 0x2700);
      if (iVar11 == -1) {
        iVar11 = 0xff;
      }
      if (uVar12 != 0xff) {
        pdVar13 = this + iVar14;
        puVar9 = (undefined2 *)(pdVar13 + 0xe6);
        if (*(short *)(pdVar13 + 0xe6) == -1) {
          if (uVar12 == 0x14) {
            if (this[0x27eb] == (dMenu_Collect_c)0x0) {
              *(short *)(this + 0x27e0) = (short)iVar15;
              *puVar9 = 0;
            }
            dVar1 = d_menu_collect::_4443;
            local_38 = (double)CONCAT44(0x43300000,*(uint *)(pdVar8 + 0x2648) ^ 0x80000000);
            *(float *)(this + *(short *)(this + 0x27e0) * 0x38 + 0xcc) =
                 (float)(local_38 - d_menu_collect::_4443);
            *(float *)(this + *(short *)(this + 0x27e0) * 0x38 + 0xd0) =
                 (float)((double)CONCAT44(0x43300000,
                                          iVar18 * (uVar17 + *(int *)(pdVar8 + 0x2684) * 2) ^
                                          0x80000000) - dVar1);
            this[0x27eb] = (dMenu_Collect_c)0x1;
          }
          else {
            if (uVar12 == 0x15) {
              if (this[0x27eb] == (dMenu_Collect_c)0x0) {
                this[0x27eb] = (dMenu_Collect_c)0x1;
                this[0x27f0] = (dMenu_Collect_c)0x0;
                *(short *)(this + 0x27e0) = (short)iVar15;
                *puVar9 = 0;
              }
              else {
                this[0x27f0] = (dMenu_Collect_c)0x1;
              }
              dVar1 = d_menu_collect::_4443;
              local_38 = (double)CONCAT44(0x43300000,*(uint *)(pdVar8 + 0x2648) ^ 0x80000000);
              *(float *)(this + *(short *)(this + 0x27e0) * 0x38 + 0xbc) =
                   (float)(local_38 - d_menu_collect::_4443);
              uStack60 = iVar18 * (uVar17 + *(int *)(pdVar8 + 0x2684) * 2) ^ 0x80000000;
              local_40 = 0x43300000;
              *(float *)(this + *(short *)(this + 0x27e0) * 0x38 + 0xc0) =
                   (float)((double)CONCAT44(0x43300000,uStack60) - dVar1);
              f_op_msg_mng::fopMsgM_blendDraw
                        (this + *(short *)(this + 0x27e0) * 0x38 + 0xb0,"font_10.bti");
              this_00 = *(J2DPicture **)(this + *(short *)(this + 0x27e0) * 0x38 + 0xb0);
              this_00->mBlendKonstColorF[0] = d_menu_collect::_4288;
              fVar3 = d_menu_collect::_4440;
              this_00->mBlendKonstColorF[1] = d_menu_collect::_4440;
              this_00->mBlendKonstColorF[2] = fVar3;
              this_00->mBlendKonstColorF[3] = fVar3;
              J2DPicture::setBlendKonstColor(this_00);
              this_00->mBlendKonstAlphaF[0] = d_menu_collect::_4288;
              fVar3 = d_menu_collect::_4440;
              this_00->mBlendKonstAlphaF[1] = d_menu_collect::_4440;
              this_00->mBlendKonstAlphaF[2] = fVar3;
              this_00->mBlendKonstAlphaF[3] = fVar3;
              J2DPicture::setBlendKonstAlpha(this_00);
              if (this[0x27ed] == (dMenu_Collect_c)0x12) {
                uVar12 = dSv_player_collect_c::isCollect
                                   (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                     mCollect,4,1);
                if (uVar12 == 0) {
                  this[0x27f0] = (dMenu_Collect_c)0x1;
                  this[0x275d] = (dMenu_Collect_c)0x1;
                }
                else {
                  this[0x27f0] = (dMenu_Collect_c)0x0;
                  this[0x275d] = (dMenu_Collect_c)0x0;
                }
              }
              this[0x27f1] = this[0x27f0];
            }
            else {
              if (uVar12 != 0x16) {
                local_38 = (double)CONCAT44(0x43300000,*(uint *)(pdVar8 + 0x2648) ^ 0x80000000);
                *(float *)(pdVar13 + 0xbc) = (float)(local_38 - d_menu_collect::_4443);
                uStack60 = iVar18 * (uVar17 + *(int *)(pdVar8 + 0x2684) * 2) ^ 0x80000000;
                local_40 = 0x43300000;
                *(float *)(pdVar13 + 0xc0) = (float)((double)CONCAT44(0x43300000,uStack60) - dVar1);
                local_48 = (double)CONCAT44(0x43300000,uVar12);
                *(float *)(pdVar13 + 0xb8) = (float)(local_48 - d_menu_collect::_4290);
                f_op_msg_mng::fopMsgM_outFontSet(*(undefined4 *)(pdVar13 + 0xb0),puVar9,iVar11);
              }
            }
          }
        }
      }
      iVar15 = iVar15 + 1;
      iVar14 = iVar14 + 0x38;
      iVar5 = iVar5 + 4;
    } while (iVar15 < 0xf);
  }
  __psq_l0(auStack8,uVar19);
  __psq_l1(auStack8,uVar19);
  return;
}


/* __thiscall dMenu_Collect_c::itemSet(void) */

void __thiscall dMenu_Collect_c::itemSet(dMenu_Collect_c *this)

{
  uint uVar1;
  
  uVar1 = dSv_player_collect_c::isCollect
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,0,3);
  if (uVar1 == 0) {
    uVar1 = dSv_player_collect_c::isCollect
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,0,2);
    if (uVar1 == 0) {
      uVar1 = dSv_player_collect_c::isCollect
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,0,1);
      if (uVar1 == 0) {
        uVar1 = dSv_player_collect_c::isCollect
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,0,0);
        if (uVar1 != 0) {
          JKRArchive::readTypeResource
                    (*(void **)(this + 0x24cc),0xc00,0x54494d47,"sword_00.bti",
                     d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
          os::DCStoreRangeNoSync(*(undefined4 *)(this + 0x24cc),0xc00);
          J2DPicture::changeTexture
                    (*(J2DPicture **)(this + 0x2030),*(ResTIMG **)(this + 0x24cc),'\0');
          J2DPicture::changeTexture
                    (*(J2DPicture **)(this + 0x2148),*(ResTIMG **)(this + 0x24cc),'\0');
        }
      }
      else {
        JKRArchive::readTypeResource
                  (*(void **)(this + 0x24cc),0xc00,0x54494d47,"sword_01.bti",
                   d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
        os::DCStoreRangeNoSync(*(undefined4 *)(this + 0x24cc),0xc00);
        J2DPicture::changeTexture(*(J2DPicture **)(this + 0x2030),*(ResTIMG **)(this + 0x24cc),'\0')
        ;
        J2DPicture::changeTexture(*(J2DPicture **)(this + 0x2148),*(ResTIMG **)(this + 0x24cc),'\0')
        ;
      }
    }
    else {
      JKRArchive::readTypeResource
                (*(void **)(this + 0x24cc),0xc00,0x54494d47,"sword_02.bti",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
      os::DCStoreRangeNoSync(*(undefined4 *)(this + 0x24cc),0xc00);
      J2DPicture::changeTexture(*(J2DPicture **)(this + 0x2030),*(ResTIMG **)(this + 0x24cc),'\0');
      J2DPicture::changeTexture(*(J2DPicture **)(this + 0x2148),*(ResTIMG **)(this + 0x24cc),'\0');
    }
  }
  else {
    JKRArchive::readTypeResource
              (*(void **)(this + 0x24cc),0xc00,0x54494d47,"sword_03.bti",
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
    os::DCStoreRangeNoSync(*(undefined4 *)(this + 0x24cc),0xc00);
    J2DPicture::changeTexture(*(J2DPicture **)(this + 0x2030),*(ResTIMG **)(this + 0x24cc),'\0');
    J2DPicture::changeTexture(*(J2DPicture **)(this + 0x2148),*(ResTIMG **)(this + 0x24cc),'\0');
  }
  uVar1 = dSv_player_collect_c::isCollect
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,1,1);
  if (uVar1 == 0) {
    uVar1 = dSv_player_collect_c::isCollect
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,1,0);
    if (uVar1 != 0) {
      JKRArchive::readTypeResource
                (*(void **)(this + 0x24d0),0xc00,0x54494d47,"shield_00.bti",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
      os::DCStoreRangeNoSync(*(undefined4 *)(this + 0x24d0),0xc00);
      J2DPicture::changeTexture(*(J2DPicture **)(this + 0x2030),*(ResTIMG **)(this + 0x24cc),'\0');
      J2DPicture::changeTexture(*(J2DPicture **)(this + 0x2148),*(ResTIMG **)(this + 0x24cc),'\0');
    }
  }
  else {
    JKRArchive::readTypeResource
              (*(void **)(this + 0x24d0),0xc00,0x54494d47,"shield_01.bti",
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
    os::DCStoreRangeNoSync(*(undefined4 *)(this + 0x24d0),0xc00);
    J2DPicture::changeTexture(*(J2DPicture **)(this + 0x2030),*(ResTIMG **)(this + 0x24cc),'\0');
    J2DPicture::changeTexture(*(J2DPicture **)(this + 0x2148),*(ResTIMG **)(this + 0x24cc),'\0');
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801a4638) */
/* __thiscall dMenu_Collect_c::outFontInit(void) */

void __thiscall dMenu_Collect_c::outFontInit(dMenu_Collect_c *this)

{
  int *piVar1;
  int iVar2;
  dMenu_Collect_c *pdVar3;
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
  dVar6 = (double)d_menu_collect::_4288;
  do {
    pdVar3 = this + iVar4;
    *(undefined2 *)(pdVar3 + 0xe6) = 0xffff;
    piVar1 = *(int **)(pdVar3 + 0xb0);
    piVar1[0x29] = (int)(float)dVar6;
    (**(code **)(*piVar1 + 0x20))();
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar3 + 0xb0));
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar2 < 0xf);
  *(undefined2 *)(this + 0x27e0) = 0xffff;
  this[0x27eb] = (dMenu_Collect_c)0x0;
  this[0x27f0] = (dMenu_Collect_c)0x0;
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Collect_c::outFontMove(void) */

void __thiscall dMenu_Collect_c::outFontMove(dMenu_Collect_c *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  dMenu_Collect_c *pdVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = 0;
  iVar7 = 0;
  do {
    pdVar5 = this + iVar7;
    if (*(short *)(pdVar5 + 0xe6) == -1) {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar5 + 0xb0));
    }
    else {
      *(float *)(pdVar5 + 0x404) =
           *(float *)(pdVar5 + 0xbc) +
           *(float *)(this + 0x784) + *(float *)(this + 0x82c) + *(float *)(this + 0x7bc);
      *(float *)(pdVar5 + 0x408) =
           *(float *)(pdVar5 + 0xc0) +
           *(float *)(this + 0x788) + *(float *)(this + 0x830) + *(float *)(this + 0x7c0);
      if ((iVar6 == *(short *)(this + 0x27e0)) && (this[0x27f0] == (dMenu_Collect_c)0x0)) {
        *(float *)(pdVar5 + 0x404) =
             *(float *)(pdVar5 + 0x404) - (*(float *)(pdVar5 + 0xbc) - *(float *)(pdVar5 + 0xcc));
      }
      fVar1 = *(float *)(this + 0x840);
      fVar2 = *(float *)(pdVar5 + 0x408);
      iVar3 = *(int *)(*(int *)(this + 0x820) + 0xa4);
      piVar4 = *(int **)(pdVar5 + 0x3f8);
      piVar4[0x27] = (int)(*(float *)(this + 0x83c) - *(float *)(pdVar5 + 0x404));
      piVar4[0x28] = (int)(fVar1 - fVar2);
      *(undefined *)(piVar4 + 0x2a) = 0x7a;
      piVar4[0x29] = iVar3;
      (**(code **)(*piVar4 + 0x20))();
    }
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + 0x38;
  } while (iVar6 < 0xf);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMenu_Collect_c::outFontDraw(void) */

void __thiscall dMenu_Collect_c::outFontDraw(dMenu_Collect_c *this)

{
  int iVar1;
  dMenu_Collect_c *pdVar2;
  int iVar3;
  double local_30;
  double local_28;
  
  iVar1 = 0;
  iVar3 = 0;
  do {
    pdVar2 = this + iVar3;
    if (*(short *)(pdVar2 + 0xe6) == -1) {
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar2 + 0xb0));
    }
    else {
      pdVar2[0xe5] = *(dMenu_Collect_c *)(*(int *)(this + 0x778) + 0xac);
      if (iVar1 == *(short *)(this + 0x27e0)) {
        local_30 = (double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U);
        local_28 = (double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U);
        fopMsgM_msgDataProc_c::selectArrow
                  ((fopMsgM_msgDataProc_c *)(this + 0x24e0),*(J2DPicture **)(pdVar2 + 0xb0),
                   (float)(local_30 - d_menu_collect::_4443),
                   (float)(local_28 - d_menu_collect::_4443));
        (**(code **)(**(int **)(pdVar2 + 0x3f8) + 0x10))
                  ((double)*(float *)(pdVar2 + 0x404),(double)*(float *)(pdVar2 + 0x408));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar2 + 0xb0));
      }
      else {
        f_op_msg_mng::fopMsgM_outFontDraw2
                  (*(undefined4 *)(pdVar2 + 0xb0),*(undefined4 *)(pdVar2 + 0x3f8),
                   (int)*(float *)(pdVar2 + 0x404),(int)*(float *)(pdVar2 + 0x408),(int)DAT_803e6bb4
                   ,(int)DAT_803e6bb4,pdVar2 + 0xe6,pdVar2[0xe5],(int)*(float *)(pdVar2 + 0xb8));
      }
    }
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 0xf);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMenu_Collect_c::collectItemGetCheck(unsigned char) */

bool __thiscall dMenu_Collect_c::collectItemGetCheck(dMenu_Collect_c *this,uchar param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  switch((uint)param_1) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
    iVar2 = dSv_player_collect_c::isTact
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,param_1);
    bVar3 = iVar2 != 0;
    break;
  case 6:
  case 7:
    bVar3 = true;
    break;
  case 8:
    bVar3 = (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxHp & 3U) != 0;
    break;
  case 9:
    iVar2 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x908);
    if ((iVar2 == 0) &&
       (iVar2 = dSv_player_map_c::getCollectMapNum
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap),
       iVar2 == 0)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    break;
  case 10:
    iVar2 = 0;
    do {
      iVar1 = dSv_player_collect_c::isTriforce
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                         (uchar)iVar2);
      if (iVar1 != 0) {
        return true;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
    bVar3 = false;
    break;
  case 0xb:
  case 0xc:
  case 0xd:
    iVar2 = dSv_player_collect_c::isSymbol
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                       param_1 + 0xf5);
    bVar3 = iVar2 != 0;
    break;
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
    bVar3 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem)[2].field_0x0
            [param_1] != 0;
    break;
  default:
    bVar3 = false;
  }
  return bVar3;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dMenu_Collect_c::_create(void) */

void __thiscall dMenu_Collect_c::_create(dMenu_Collect_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  STControl *pSVar2;
  void *pvVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  dMenu_Collect_c *pdVar9;
  int iVar10;
  int iVar11;
  TBox2_float_ local_28;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_28.mTL.x = d_menu_collect::_4288;
    local_28.mTL.y = d_menu_collect::_4288;
    local_28.mBR.x = d_menu_collect::_5177;
    local_28.mBR.y = d_menu_collect::_5178;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_28);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
    this_00->vtbl = (J2DPane__vtable *)&MyScreen::__vt;
  }
  *(J2DPane **)(this + 4) = this_00;
  if (*(int *)(this + 4) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_collect.cpp",0xe4a,"scrn != 0");
    m_Do_printf::OSPanic("d_menu_collect.cpp",0xe4a,&DAT_8035f4b6);
  }
  J2DScreen::set(*(J2DScreen **)(this + 4),"menu_collect_01.blo",*(JKRArchive **)(this + 0x2464));
  pSVar2 = (STControl *)JKernel::operator_new(0x28);
  if (pSVar2 != (STControl *)0x0) {
    STControl::STControl(pSVar2,5,2,3,2,d_menu_collect::_7616,d_menu_collect::_4287,0,0x2000);
  }
  *(STControl **)(this + 0x2458) = pSVar2;
  if (*(int *)(this + 0x2458) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_collect.cpp",0xe4e,"stick != 0");
    m_Do_printf::OSPanic("d_menu_collect.cpp",0xe4e,&DAT_8035f4b6);
  }
  pSVar2 = (STControl *)JKernel::operator_new(0x28);
  if (pSVar2 != (STControl *)0x0) {
    STControl::STControl(pSVar2,5,2,3,2,d_menu_collect::_7616,d_menu_collect::_4287,0,0x2000);
    pSVar2->vtbl = (undefined *)&CSTControl::__vt;
  }
  *(STControl **)(this + 0x245c) = pSVar2;
  if (*(int *)(this + 0x245c) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_collect.cpp",0xe51,"cstick != 0");
    m_Do_printf::OSPanic("d_menu_collect.cpp",0xe51,&DAT_8035f4b6);
  }
  STControl::setWaitParm
            (*(STControl **)(this + 0x2458),5,2,3,2,d_menu_collect::_7616,d_menu_collect::_4287,0,
             0x800);
  pvVar3 = JKernel::operator_new(0x150);
  if (pvVar3 != (void *)0x0) {
    *(undefined4 *)((int)pvVar3 + 0x20) = 0;
    *(undefined4 *)((int)pvVar3 + 0x18) = 0;
    *(undefined4 *)((int)pvVar3 + 0x2c) = 0;
    *(undefined *)((int)pvVar3 + 0x74) = 0;
  }
  *(void **)(this + 0x2460) = pvVar3;
  if (*(int *)(this + 0x2460) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_collect.cpp",0xe55,"outFont != 0");
    m_Do_printf::OSPanic("d_menu_collect.cpp",0xe55,&DAT_8035f4b6);
  }
  *(undefined *)(*(int *)(this + 0x2460) + 0x74) = 1;
  puVar4 = (undefined4 *)JKernel::operator_new(0xe44);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = &dMenu_Option_c::__vt;
  }
  *(undefined4 **)(this + 0x2780) = puVar4;
  if (*(int *)(this + 0x2780) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_collect.cpp",0xe59,"dMo_c != 0");
    m_Do_printf::OSPanic("d_menu_collect.cpp",0xe59,&DAT_8035f4b6);
  }
  *(undefined4 *)(*(int *)(this + 0x2780) + 0xd28) = *(undefined4 *)(this + 0x2468);
  uVar6 = *(undefined4 *)(this + 0x2474);
  iVar5 = *(int *)(this + 0x2780);
  *(undefined4 *)(iVar5 + 0xd2c) = *(undefined4 *)(this + 0x2470);
  *(undefined4 *)(iVar5 + 0xd30) = uVar6;
  uVar8 = *(undefined4 *)(this + 0x27c4);
  uVar7 = *(undefined4 *)(this + 0x27c0);
  uVar6 = *(undefined4 *)(this + 0x27bc);
  iVar5 = *(int *)(this + 0x2780);
  *(undefined4 *)(iVar5 + 0xd38) = *(undefined4 *)(this + 0x27b8);
  *(undefined4 *)(iVar5 + 0xd3c) = uVar6;
  *(undefined4 *)(iVar5 + 0xd40) = uVar7;
  *(undefined4 *)(iVar5 + 0xd44) = uVar8;
  dMenu_Option_c::_create(*(dMenu_Option_c **)(this + 0x2780));
  puVar4 = (undefined4 *)JKernel::operator_new(0x1ba4);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = &dMenu_save_c::__vt;
    puVar4[2] = &dDlst_base_c::__vt;
    puVar4[2] = &dDlst_MenuSave_c::__vt;
  }
  *(undefined4 **)(this + 0x2784) = puVar4;
  if (*(int *)(this + 0x2784) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_collect.cpp",0xe63,"dMs_c != 0");
    m_Do_printf::OSPanic("d_menu_collect.cpp",0xe63,&DAT_8035f4b6);
  }
  *(undefined *)(*(int *)(this + 0x2784) + 0x537) = 1;
  dMenu_save_c::_create(*(dMenu_save_c **)(this + 0x2784));
  screenSet(this);
  initialize(this);
  iVar5 = 0;
  iVar11 = 3;
  do {
    *(undefined4 *)(this + iVar5 + 0x247c) = 0;
    iVar5 = iVar5 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  DAT_803e6032 = mDoHIO_subRoot_c::createChild
                           (&mDoHIO_subRoot_c_803a5778,"コレクト画面",
                            (JORReflexible *)&d_menu_collect::g_mcHIO);
  iVar5 = 0;
  iVar10 = 0;
  iVar11 = 0;
  do {
    pdVar9 = this + iVar11;
    J2DPicture::insert(*(J2DPicture **)(pdVar9 + 0xa18),"cursor_00_02.bti",
                       (*(J2DPicture **)(pdVar9 + 0xa18))->mNumTexture,d_menu_collect::_4440);
    *(float *)(this + iVar10 + 0x2788) = *(float *)(pdVar9 + 0xa2c) - *(float *)(this + 0x14ac);
    *(float *)(this + iVar10 + 0x2798) = *(float *)(pdVar9 + 0xa30) - *(float *)(this + 0x14b0);
    iVar5 = iVar5 + 1;
    iVar10 = iVar10 + 4;
    iVar11 = iVar11 + 0x38;
  } while (iVar5 < 4);
  iVar5 = 0;
  iVar11 = 0;
  do {
    J2DPicture::changeTexture(*(J2DPicture **)(this + iVar11 + 0xb0),"font_07_02.bti",0);
    f_op_msg_mng::fopMsgM_blendInit((fopMsgM_pane_class *)(this + iVar11 + 0xb0),"font_00.bti");
    iVar5 = iVar5 + 1;
    iVar11 = iVar11 + 0x38;
  } while (iVar5 < 0xf);
  cursorAnime(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMenu_Collect_c::_create3(void) */

void __thiscall dMenu_Collect_c::_create3(dMenu_Collect_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  STControl *pSVar2;
  void *pvVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  TBox2_float_ local_28;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_28.mTL.x = d_menu_collect::_4288;
    local_28.mTL.y = d_menu_collect::_4288;
    local_28.mBR.x = d_menu_collect::_5177;
    local_28.mBR.y = d_menu_collect::_5178;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_28);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
    this_00->vtbl = (J2DPane__vtable *)&MyScreen::__vt;
  }
  *(J2DPane **)(this + 4) = this_00;
  if (*(int *)(this + 4) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_collect.cpp",0xe8f,"scrn != 0");
    m_Do_printf::OSPanic("d_menu_collect.cpp",0xe8f,&DAT_8035f4b6);
  }
  J2DScreen::set(*(J2DScreen **)(this + 4),"menu_collect_01.blo",*(JKRArchive **)(this + 0x2464));
  pSVar2 = (STControl *)JKernel::operator_new(0x28);
  if (pSVar2 != (STControl *)0x0) {
    STControl::STControl(pSVar2,5,2,3,2,d_menu_collect::_7616,d_menu_collect::_4287,0,0x2000);
  }
  *(STControl **)(this + 0x2458) = pSVar2;
  if (*(int *)(this + 0x2458) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_collect.cpp",0xe93,"stick != 0");
    m_Do_printf::OSPanic("d_menu_collect.cpp",0xe93,&DAT_8035f4b6);
  }
  pSVar2 = (STControl *)JKernel::operator_new(0x28);
  if (pSVar2 != (STControl *)0x0) {
    STControl::STControl(pSVar2,5,2,3,2,d_menu_collect::_7616,d_menu_collect::_4287,0,0x2000);
    pSVar2->vtbl = (undefined *)&CSTControl::__vt;
  }
  *(STControl **)(this + 0x245c) = pSVar2;
  if (*(int *)(this + 0x245c) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_collect.cpp",0xe96,"cstick != 0");
    m_Do_printf::OSPanic("d_menu_collect.cpp",0xe96,&DAT_8035f4b6);
  }
  STControl::setWaitParm
            (*(STControl **)(this + 0x2458),5,2,3,2,d_menu_collect::_7616,d_menu_collect::_4287,0,
             0x800);
  pvVar3 = JKernel::operator_new(0x150);
  if (pvVar3 != (void *)0x0) {
    *(undefined4 *)((int)pvVar3 + 0x20) = 0;
    *(undefined4 *)((int)pvVar3 + 0x18) = 0;
    *(undefined4 *)((int)pvVar3 + 0x2c) = 0;
    *(undefined *)((int)pvVar3 + 0x74) = 0;
  }
  *(void **)(this + 0x2460) = pvVar3;
  if (*(int *)(this + 0x2460) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_collect.cpp",0xe9a,"outFont != 0");
    m_Do_printf::OSPanic("d_menu_collect.cpp",0xe9a,&DAT_8035f4b6);
  }
  puVar4 = (undefined4 *)JKernel::operator_new(0xe44);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = &dMenu_Option_c::__vt;
  }
  *(undefined4 **)(this + 0x2780) = puVar4;
  if (*(int *)(this + 0x2780) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_collect.cpp",0xe9d,"dMo_c != 0");
    m_Do_printf::OSPanic("d_menu_collect.cpp",0xe9d,&DAT_8035f4b6);
  }
  *(undefined4 *)(*(int *)(this + 0x2780) + 0xd28) = *(undefined4 *)(this + 0x2468);
  uVar6 = *(undefined4 *)(this + 0x2474);
  iVar5 = *(int *)(this + 0x2780);
  *(undefined4 *)(iVar5 + 0xd2c) = *(undefined4 *)(this + 0x2470);
  *(undefined4 *)(iVar5 + 0xd30) = uVar6;
  uVar8 = *(undefined4 *)(this + 0x27c4);
  uVar7 = *(undefined4 *)(this + 0x27c0);
  uVar6 = *(undefined4 *)(this + 0x27bc);
  iVar5 = *(int *)(this + 0x2780);
  *(undefined4 *)(iVar5 + 0xd38) = *(undefined4 *)(this + 0x27b8);
  *(undefined4 *)(iVar5 + 0xd3c) = uVar6;
  *(undefined4 *)(iVar5 + 0xd40) = uVar7;
  *(undefined4 *)(iVar5 + 0xd44) = uVar8;
  dMenu_Option_c::_create(*(dMenu_Option_c **)(this + 0x2780));
  puVar4 = (undefined4 *)JKernel::operator_new(0x1ba4);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = &dMenu_save_c::__vt;
    puVar4[2] = &dDlst_base_c::__vt;
    puVar4[2] = &dDlst_MenuSave_c::__vt;
  }
  *(undefined4 **)(this + 0x2784) = puVar4;
  if (*(int *)(this + 0x2784) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_collect.cpp",0xea6,"dMs_c != 0");
    m_Do_printf::OSPanic("d_menu_collect.cpp",0xea6,&DAT_8035f4b6);
  }
  *(undefined *)(*(int *)(this + 0x2784) + 0x537) = 1;
  dMenu_save_c::_create(*(dMenu_save_c **)(this + 0x2784));
  screenSet(this);
  *(undefined2 *)(this + 0x27e2) = 0;
  this[0x27f2] = (dMenu_Collect_c)0x0;
  *(undefined4 *)(this + 0x27dc) = 0;
  *(undefined2 *)(this + 0x88e) = 10;
  *(undefined2 *)(this + 0x27e4) = 0;
  this[0x27ea] = (dMenu_Collect_c)0x0;
  this[0x27ec] = (dMenu_Collect_c)0x0;
  this[0x27ee] = (dMenu_Collect_c)0x5;
  this[0x27ef] = (dMenu_Collect_c)0x0;
  tactGuideHide(this);
  tactBaseShow(this);
  noteInit(this);
  outFontInit(this);
  itemBitCheck(this);
  this[0x9a4] = (dMenu_Collect_c)0x82;
  *(undefined2 *)(this + 0x27e6) = 0;
  *(undefined2 *)(this + 0x27e8) = 0;
  iVar5 = *(int *)(this + 0xba0);
  this[0x2488] = *(dMenu_Collect_c *)(iVar5 + 0xf4);
  this[0x2489] = *(dMenu_Collect_c *)(iVar5 + 0xf5);
  this[0x248a] = *(dMenu_Collect_c *)(iVar5 + 0xf6);
  this[0x248b] = *(dMenu_Collect_c *)(iVar5 + 0xf7);
  this[0x248c] = *(dMenu_Collect_c *)(iVar5 + 0xf8);
  this[0x248d] = *(dMenu_Collect_c *)(iVar5 + 0xf9);
  this[0x248e] = *(dMenu_Collect_c *)(iVar5 + 0xfa);
  this[0x248f] = *(dMenu_Collect_c *)(iVar5 + 0xfb);
  this[0x2490] = *(dMenu_Collect_c *)(iVar5 + 0xfc);
  this[0x2491] = *(dMenu_Collect_c *)(iVar5 + 0xfd);
  this[0x2492] = *(dMenu_Collect_c *)(iVar5 + 0xfe);
  this[0x2493] = *(dMenu_Collect_c *)(iVar5 + 0xff);
  this[0x2494] = *(dMenu_Collect_c *)(iVar5 + 0x100);
  this[0x2495] = *(dMenu_Collect_c *)(iVar5 + 0x101);
  this[0x2496] = *(dMenu_Collect_c *)(iVar5 + 0x102);
  this[0x2497] = *(dMenu_Collect_c *)(iVar5 + 0x103);
  iVar5 = 0;
  iVar9 = 3;
  do {
    *(undefined4 *)(this + iVar5 + 0x247c) = 0;
    iVar5 = iVar5 + 4;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  DAT_803e6032 = mDoHIO_subRoot_c::createChild
                           (&mDoHIO_subRoot_c_803a5778,"コレクト画面",
                            (JORReflexible *)&d_menu_collect::g_mcHIO);
  iVar5 = 0;
  iVar9 = 4;
  do {
    *(undefined *)(*(int *)(this + iVar5 + 0xa18) + 0xaa) = 0;
    iVar5 = iVar5 + 0x38;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  iVar5 = 0;
  iVar9 = 0;
  do {
    J2DPicture::changeTexture(*(J2DPicture **)(this + iVar9 + 0xb0),"font_07_02.bti",0);
    f_op_msg_mng::fopMsgM_blendInit((fopMsgM_pane_class *)(this + iVar9 + 0xb0),"font_00.bti");
    iVar5 = iVar5 + 1;
    iVar9 = iVar9 + 0x38;
  } while (iVar5 < 0xf);
  return;
}


/* __thiscall dMenu_Collect_c::_delete(void) */

void __thiscall dMenu_Collect_c::_delete(dMenu_Collect_c *this)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = *(int **)(this + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  JKernel::operator_delete(*(JKRHeap **)(this + 0x2458));
  JKernel::operator_delete(*(JKRHeap **)(this + 0x245c));
  if (*(JKRHeap **)(this + 0x2460) != (JKRHeap *)0x0) {
    JKernel::operator_delete(*(JKRHeap **)(this + 0x2460));
  }
  dMenu_Option_c::_delete(*(dMenu_Option_c **)(this + 0x2780));
  piVar1 = *(int **)(this + 0x2780);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  dMenu_save_c::_delete(*(dMenu_save_c **)(this + 0x2784));
  piVar1 = *(int **)(this + 0x2784);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  iVar2 = 0;
  iVar5 = 3;
  do {
    iVar4 = iVar2 + 0x247c;
    iVar3 = *(int *)(this + iVar4);
    if (iVar3 != 0) {
      *(undefined4 *)(iVar3 + 0x60) = 0xffffffff;
      *(uint *)(iVar3 + 0x20c) = *(uint *)(iVar3 + 0x20c) | 1;
      *(uint *)(*(int *)(this + iVar4) + 0x20c) =
           *(uint *)(*(int *)(this + iVar4) + 0x20c) & 0xffffffbf;
      *(undefined4 *)(this + iVar4) = 0;
    }
    iVar2 = iVar2 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  (**(code **)(**(int **)(this + 0x2464) + 0x24))();
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e6032);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801a5994) */
/* WARNING: Removing unreachable block (ram,0x801a5a00) */
/* __thiscall dMenu_Collect_c::_move(void) */

void __thiscall dMenu_Collect_c::_move(dMenu_Collect_c *this)

{
  dMenu_Collect_c dVar1;
  dMenu_save_c dVar2;
  dMenu_Option_c dVar3;
  char cVar6;
  int iVar4;
  uint uVar5;
  dMenu_save_c *this_00;
  dMenu_Option_c *this_01;
  int iVar7;
  int iVar8;
  
  itemBitCheck(this);
  if (this[0x27f3] == (dMenu_Collect_c)0x8) {
    triforceAnime(this,DAT_803e6026);
  }
  dVar1 = this[0x27ee];
  if (dVar1 == (dMenu_Collect_c)0x0) {
    cVar6 = noteCheck(this);
    if (cVar6 == '\0') {
      if ((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) == 0) &&
          (m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mTriggerLeftLevel == 0)) &&
         (m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mTriggerRightLevel == 0)) {
        if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
          if (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3) {
            cursorMainMove(this);
            itemScale(this);
          }
        }
        else {
          if (((byte)this[0x27ed] < 6) &&
             (iVar4 = dSv_player_collect_c::isTact
                                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,
                                 (uchar)this[0x27ed]), iVar4 != 0)) {
            this[0x27ee] = (dMenu_Collect_c)0x1;
            *(undefined2 *)(this + 0x161e) = 0;
            tactGuideHide(this);
            iVar7 = 0;
            iVar4 = 0;
            iVar8 = 6;
            do {
              if (iVar7 < *(int *)(&d_menu_collect::tact_beat + (uint)(byte)this[0x27ed] * 4)) {
                *(undefined *)(*(int *)(this + iVar4 + 0x1e38) + 0xaa) = 1;
              }
              iVar7 = iVar7 + 1;
              iVar4 = iVar4 + 0x38;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
            JAIZelInst::melodyPlay(&mDoAud_zelAudio_c::mTact,(uint)(byte)this[0x27ed]);
          }
          else {
            dVar1 = this[0x27ed];
            if (dVar1 == (dMenu_Collect_c)0x6) {
              this[0x27ee] = (dMenu_Collect_c)0x4;
              dMenu_Option_c::initialize(*(dMenu_Option_c **)(this + 0x2780));
              JAIZelBasic::seStart
                        (JAIZelBasic::zel_basic,0x84c,(cXyz *)0x0,0,0,d_menu_collect::_4440,
                         d_menu_collect::_4440,d_menu_collect::_5050,d_menu_collect::_5050,0);
            }
            else {
              if (dVar1 == (dMenu_Collect_c)0x7) {
                this[0x27ee] = (dMenu_Collect_c)0x3;
                dMenu_save_c::initialize(*(dMenu_save_c **)(this + 0x2784));
                JAIZelBasic::seStart
                          (JAIZelBasic::zel_basic,0x84c,(cXyz *)0x0,0,0,d_menu_collect::_4440,
                           d_menu_collect::_4440,d_menu_collect::_5050,d_menu_collect::_5050,0);
              }
              else {
                if ((dVar1 == (dMenu_Collect_c)0x11) &&
                   (uVar5 = dSv_player_collect_c::isCollect
                                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                        mCollect,3,0), uVar5 != 0)) {
                  dSv_player_collect_c::onCollect
                            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,3,1)
                  ;
                }
              }
            }
          }
          dVar1 = this[0x27ed];
          if (((((9 < (byte)dVar1) && ((byte)dVar1 < 0x13)) ||
               ((dVar1 == (dMenu_Collect_c)0x8 &&
                ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxHp & 3U) !=
                 0)))) ||
              ((dVar1 == (dMenu_Collect_c)0x9 &&
               ((iVar4 = dSv_event_c::isEventBit
                                   (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x908),
                iVar4 != 0 ||
                (iVar4 = dSv_player_map_c::getCollectMapNum
                                   (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap),
                iVar4 != 0)))))) &&
             (cVar6 = collectItemGetCheck(this,(uchar)this[0x27ed]), cVar6 != '\0')) {
            f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x740);
            f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x778);
            f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x7b0);
            f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x7e8);
            f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x820);
            *(undefined2 *)(this + 0x81e) = 1;
            *(undefined2 *)(this + 0x7e6) = 1;
            itemnoteSet(this);
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x8b6,(cXyz *)0x0,0,0,d_menu_collect::_4440,
                       d_menu_collect::_4440,d_menu_collect::_5050,d_menu_collect::_5050,0);
          }
        }
      }
    }
    else {
      noteAppear(this);
    }
    cVar6 = collectItemGetCheck(this,(uchar)this[0x27ed]);
    if (cVar6 == '\0') {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x890));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x8c8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x858));
    }
    else {
      itemnameMove(this);
    }
    outFontMove(this);
  }
  else {
    if (dVar1 == (dMenu_Collect_c)0x1) {
      tactDemoMode(this,(uchar)this[0x27ed]);
      itemnameMove(this);
    }
    else {
      if (dVar1 == (dMenu_Collect_c)0x2) {
        tactPlayMode(this,(uchar)this[0x27ed]);
        itemnameMove(this);
      }
      else {
        if (dVar1 == (dMenu_Collect_c)0x3) {
          this_00 = *(dMenu_save_c **)(this + 0x2784);
          dVar2 = this_00[0x531];
          if (dVar2 == (dMenu_save_c)0x2) {
            dMenu_save_c::_move(this_00);
          }
          else {
            if ((byte)dVar2 < 2) {
              if (dVar2 == (dMenu_save_c)0x0) {
                this[0x27ee] = (dMenu_Collect_c)0x0;
              }
              else {
                dMenu_save_c::_open(this_00);
              }
            }
            else {
              if ((byte)dVar2 < 4) {
                dMenu_save_c::_close(this_00);
              }
            }
          }
          d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 7;
        }
        else {
          if (dVar1 == (dMenu_Collect_c)0x4) {
            this_01 = *(dMenu_Option_c **)(this + 0x2780);
            dVar3 = this_01[0xe40];
            if (dVar3 == (dMenu_Option_c)0x2) {
              dMenu_Option_c::_move(this_01);
            }
            else {
              if ((byte)dVar3 < 2) {
                if (dVar3 == (dMenu_Option_c)0x0) {
                  this[0x27ee] = (dMenu_Collect_c)0x0;
                }
                else {
                  dMenu_Option_c::_open(this_01);
                }
              }
              else {
                if ((byte)dVar3 < 4) {
                  dMenu_Option_c::_close(this_01);
                }
              }
            }
            d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 7;
          }
        }
      }
    }
  }
  if ((this[0x27ee] != (dMenu_Collect_c)0x4) && (this[0x27ee] != (dMenu_Collect_c)0x3)) {
    cursorAnime(this);
    cornerMove(this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Collect_c::_move3(void) */

void __thiscall dMenu_Collect_c::_move3(dMenu_Collect_c *this)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  
  sVar5 = DAT_803e6020;
  sVar4 = DAT_803e601e;
  sVar3 = DAT_803e601c;
  sVar2 = DAT_803e601a;
  sVar6 = DAT_803e601a + DAT_803e601c;
  sVar7 = sVar6 + DAT_803e601e;
  sVar8 = sVar7 + DAT_803e6020;
  *(short *)(this + 0x27e2) = *(short *)(this + 0x27e2) + 1;
  sVar1 = *(short *)(this + 0x27e2);
  if (sVar2 < sVar1) {
    if (sVar6 < sVar1) {
      if (sVar7 < sVar1) {
        if ((sVar1 <= sVar8) &&
           (animeStep4(this,sVar5,sVar1 - sVar7), *(short *)(this + 0x27e2) == sVar8)) {
          this[0x27ee] = (dMenu_Collect_c)0x0;
        }
      }
      else {
        animeStep3(this,sVar4,sVar1 - sVar6);
      }
    }
    else {
      animeStep2(this,sVar3,sVar1 - sVar2);
    }
  }
  else {
    if (sVar1 == 1) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x908,(cXyz *)0x0,0,0,d_menu_collect::_4440,
                 d_menu_collect::_4440,d_menu_collect::_5050,d_menu_collect::_5050,0);
    }
    animeStep1(this,sVar2,*(short *)(this + 0x27e2));
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801a68cc) */
/* __thiscall dMenu_Collect_c::_draw(void) */

void __thiscall dMenu_Collect_c::_draw(dMenu_Collect_c *this)

{
  J2DOrthoGraph *pCtx;
  double dVar1;
  double dVar2;
  int iVar3;
  dMenu_Collect_c *pdVar4;
  int iVar5;
  undefined4 uVar6;
  double dVar7;
  undefined8 in_f31;
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
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (this[0x27ea] == (dMenu_Collect_c)0x0) {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x740));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x778));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x7b0));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x7e8));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x820));
    dDlst_2DOutFont_c::setAlpha(*(dDlst_2DOutFont_c **)(this + 0x2460),(uchar)this[0x88d]);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x890));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x8c8));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x900));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x938));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x970));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x9a8));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x9e0));
    iVar3 = 0;
    iVar5 = 0;
    do {
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar5 + 0xa18));
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x38;
    } while (iVar3 < 4);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xaf8));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xb30));
    iVar3 = 0;
    iVar5 = 0;
    do {
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar5 + 0xb68));
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x38;
    } while (iVar3 < 4);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xc48));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xc80));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xcb8));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xcf0));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xd28));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xd60));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xd98));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xdd0));
    iVar3 = 0;
    iVar5 = 0;
    do {
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar5 + 0xe08));
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x38;
    } while (iVar3 < 8);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xfc8));
    iVar3 = 0;
    iVar5 = 0;
    do {
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar5 + 0x1000));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar5 + 0x10a8));
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x38;
    } while (iVar3 < 3);
    iVar3 = 0;
    iVar5 = 0;
    do {
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar5 + 0x1150));
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x38;
    } while (iVar3 < 0xb);
    iVar3 = 0;
    iVar5 = 0;
    do {
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar5 + 0x13b8));
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x38;
    } while (iVar3 < 3);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1460));
    iVar3 = 0;
    iVar5 = 0;
    do {
      pdVar4 = this + iVar5;
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar4 + 0x1498));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar4 + 0x15e8));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar4 + 0x17a8));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar4 + 0x18f8));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar4 + 0x1a48));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar4 + 0x1b98));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar4 + 0x1ce8));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar4 + 0x1e38));
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x38;
    } while (iVar3 < 6);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1738));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 6000));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1f88));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1fc0));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1ff8));
    iVar3 = 0;
    iVar5 = 0;
    do {
      pdVar4 = this + iVar5;
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar4 + 0x2030));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar4 + 0x2148));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar4 + 0x2260));
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x38;
    } while (iVar3 < 5);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x2378));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x23b0));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x23e8));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x2420));
  }
  else {
    dVar7 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(this + 0x27e2),0);
    dVar1 = d_menu_collect::_4290;
    if ((this[0x27ec] != (dMenu_Collect_c)0x1) && (this[0x27ec] != (dMenu_Collect_c)0x2)) {
      *(char *)(*(int *)(this + 0x740) + 0xac) =
           (char)(int)((double)(float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x775]) -
                                      d_menu_collect::_4290) * dVar7);
      *(char *)(*(int *)(this + 0x778) + 0xac) =
           (char)(int)((double)(float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x7ad]) - dVar1)
                      * dVar7);
      *(char *)(*(int *)(this + 0x7b0) + 0xac) =
           (char)(int)((double)(float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x7e5]) - dVar1)
                      * dVar7);
      *(char *)(*(int *)(this + 0x7e8) + 0xac) =
           (char)(int)((double)(float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x81d]) - dVar1)
                      * dVar7);
      local_a8 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x855]);
      *(char *)(*(int *)(this + 0x820) + 0xac) =
           (char)(int)((double)(float)(local_a8 - dVar1) * dVar7);
      local_98 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x88d]);
      dDlst_2DOutFont_c::setAlpha
                (*(dDlst_2DOutFont_c **)(this + 0x2460),
                 (uchar)(int)((double)(float)(local_98 - dVar1) * dVar7));
      dVar1 = d_menu_collect::_4290;
      local_88 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x8c5]);
      *(char *)(*(int *)(this + 0x890) + 0xac) =
           (char)(int)((double)(float)(local_88 - d_menu_collect::_4290) * dVar7);
      local_78 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x8fd]);
      *(char *)(*(int *)(this + 0x8c8) + 0xac) =
           (char)(int)((double)(float)(local_78 - dVar1) * dVar7);
      local_68 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x935]);
      *(char *)(*(int *)(this + 0x900) + 0xac) =
           (char)(int)((double)(float)(local_68 - dVar1) * dVar7);
      local_58 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x96d]);
      *(char *)(*(int *)(this + 0x938) + 0xac) =
           (char)(int)((double)(float)(local_58 - dVar1) * dVar7);
      local_48 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x9dd]);
      *(char *)(*(int *)(this + 0x9a8) + 0xac) =
           (char)(int)((double)(float)(local_48 - dVar1) * dVar7);
      local_38 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xa15]);
      *(char *)(*(int *)(this + 0x9e0) + 0xac) =
           (char)(int)((double)(float)(local_38 - dVar1) * dVar7);
    }
    dVar1 = d_menu_collect::_4290;
    local_30 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x9a5]);
    *(char *)(*(int *)(this + 0x970) + 0xac) =
         (char)(int)((double)(float)(local_30 - d_menu_collect::_4290) * dVar7);
    iVar3 = 0;
    iVar5 = 4;
    do {
      local_30 = (double)CONCAT44(0x43300000,(uint)(byte)(this + iVar3)[0xa4d]);
      *(char *)(*(int *)(this + iVar3 + 0xa18) + 0xac) =
           (char)(int)((double)(float)(local_30 - dVar1) * dVar7);
      dVar2 = d_menu_collect::_4290;
      iVar3 = iVar3 + 0x38;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    local_30 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xb2d]);
    *(char *)(*(int *)(this + 0xaf8) + 0xac) =
         (char)(int)((double)(float)(local_30 - d_menu_collect::_4290) * dVar7);
    local_40 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xb65]);
    *(char *)(*(int *)(this + 0xb30) + 0xac) =
         (char)(int)((double)(float)(local_40 - dVar2) * dVar7);
    iVar3 = 0;
    iVar5 = 4;
    do {
      local_30 = (double)CONCAT44(0x43300000,(uint)(byte)(this + iVar3)[0xb9d]);
      *(char *)(*(int *)(this + iVar3 + 0xb68) + 0xac) =
           (char)(int)((double)(float)(local_30 - dVar2) * dVar7);
      dVar1 = d_menu_collect::_4290;
      iVar3 = iVar3 + 0x38;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    local_30 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xc7d]);
    *(char *)(*(int *)(this + 0xc48) + 0xac) =
         (char)(int)((double)(float)(local_30 - d_menu_collect::_4290) * dVar7);
    local_40 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xcb5]);
    *(char *)(*(int *)(this + 0xc80) + 0xac) =
         (char)(int)((double)(float)(local_40 - dVar1) * dVar7);
    local_50 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xced]);
    *(char *)(*(int *)(this + 0xcb8) + 0xac) =
         (char)(int)((double)(float)(local_50 - dVar1) * dVar7);
    local_60 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xd25]);
    *(char *)(*(int *)(this + 0xcf0) + 0xac) =
         (char)(int)((double)(float)(local_60 - dVar1) * dVar7);
    local_70 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xd5d]);
    *(char *)(*(int *)(this + 0xd28) + 0xac) =
         (char)(int)((double)(float)(local_70 - dVar1) * dVar7);
    local_80 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xd95]);
    *(char *)(*(int *)(this + 0xd60) + 0xac) =
         (char)(int)((double)(float)(local_80 - dVar1) * dVar7);
    local_90 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xdcd]);
    *(char *)(*(int *)(this + 0xd98) + 0xac) =
         (char)(int)((double)(float)(local_90 - dVar1) * dVar7);
    local_a0 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xe05]);
    *(char *)(*(int *)(this + 0xdd0) + 0xac) =
         (char)(int)((double)(float)(local_a0 - dVar1) * dVar7);
    iVar3 = 0;
    iVar5 = 8;
    do {
      local_30 = (double)CONCAT44(0x43300000,(uint)(byte)(this + iVar3)[0xe3d]);
      *(char *)(*(int *)(this + iVar3 + 0xe08) + 0xac) =
           (char)(int)((double)(float)(local_30 - dVar1) * dVar7);
      dVar2 = d_menu_collect::_4290;
      iVar3 = iVar3 + 0x38;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    local_30 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xffd]);
    *(char *)(*(int *)(this + 0xfc8) + 0xac) =
         (char)(int)((double)(float)(local_30 - d_menu_collect::_4290) * dVar7);
    iVar3 = 0;
    iVar5 = 3;
    do {
      pdVar4 = this + iVar3;
      local_30 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x1035]);
      *(char *)(*(int *)(pdVar4 + 0x1000) + 0xac) =
           (char)(int)((double)(float)(local_30 - dVar2) * dVar7);
      local_40 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x10dd]);
      *(char *)(*(int *)(pdVar4 + 0x10a8) + 0xac) =
           (char)(int)((double)(float)(local_40 - dVar2) * dVar7);
      dVar1 = d_menu_collect::_4290;
      iVar3 = iVar3 + 0x38;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar3 = 0;
    iVar5 = 0xb;
    do {
      local_30 = (double)CONCAT44(0x43300000,(uint)(byte)(this + iVar3)[0x1185]);
      *(char *)(*(int *)(this + iVar3 + 0x1150) + 0xac) =
           (char)(int)((double)(float)(local_30 - dVar1) * dVar7);
      dVar2 = d_menu_collect::_4290;
      iVar3 = iVar3 + 0x38;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar3 = 0;
    iVar5 = 3;
    do {
      local_30 = (double)CONCAT44(0x43300000,(uint)(byte)(this + iVar3)[0x13ed]);
      *(char *)(*(int *)(this + iVar3 + 0x13b8) + 0xac) =
           (char)(int)((double)(float)(local_30 - dVar2) * dVar7);
      dVar1 = d_menu_collect::_4290;
      iVar3 = iVar3 + 0x38;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    local_30 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1495]);
    *(char *)(*(int *)(this + 0x1460) + 0xac) =
         (char)(int)((double)(float)(local_30 - d_menu_collect::_4290) * dVar7);
    iVar3 = 0;
    iVar5 = 6;
    do {
      pdVar4 = this + iVar3;
      local_30 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x14cd]);
      *(char *)(*(int *)(pdVar4 + 0x1498) + 0xac) =
           (char)(int)((double)(float)(local_30 - dVar1) * dVar7);
      local_40 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x161d]);
      *(char *)(*(int *)(pdVar4 + 0x15e8) + 0xac) =
           (char)(int)((double)(float)(local_40 - dVar1) * dVar7);
      local_50 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x17dd]);
      *(char *)(*(int *)(pdVar4 + 0x17a8) + 0xac) =
           (char)(int)((double)(float)(local_50 - dVar1) * dVar7);
      local_60 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x192d]);
      *(char *)(*(int *)(pdVar4 + 0x18f8) + 0xac) =
           (char)(int)((double)(float)(local_60 - dVar1) * dVar7);
      local_70 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x1a7d]);
      *(char *)(*(int *)(pdVar4 + 0x1a48) + 0xac) =
           (char)(int)((double)(float)(local_70 - dVar1) * dVar7);
      local_80 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x1bcd]);
      *(char *)(*(int *)(pdVar4 + 0x1b98) + 0xac) =
           (char)(int)((double)(float)(local_80 - dVar1) * dVar7);
      local_90 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x1d1d]);
      *(char *)(*(int *)(pdVar4 + 0x1ce8) + 0xac) =
           (char)(int)((double)(float)(local_90 - dVar1) * dVar7);
      local_a0 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x1e6d]);
      *(char *)(*(int *)(pdVar4 + 0x1e38) + 0xac) =
           (char)(int)((double)(float)(local_a0 - dVar1) * dVar7);
      dVar2 = d_menu_collect::_4290;
      iVar3 = iVar3 + 0x38;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    local_30 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x176d]);
    *(char *)(*(int *)(this + 0x1738) + 0xac) =
         (char)(int)((double)(float)(local_30 - d_menu_collect::_4290) * dVar7);
    local_40 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x17a5]);
    *(char *)(*(int *)(this + 6000) + 0xac) = (char)(int)((double)(float)(local_40 - dVar2) * dVar7)
    ;
    local_50 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1fbd]);
    *(char *)(*(int *)(this + 0x1f88) + 0xac) =
         (char)(int)((double)(float)(local_50 - dVar2) * dVar7);
    local_60 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1ff5]);
    *(char *)(*(int *)(this + 0x1fc0) + 0xac) =
         (char)(int)((double)(float)(local_60 - dVar2) * dVar7);
    local_70 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x202d]);
    *(char *)(*(int *)(this + 0x1ff8) + 0xac) =
         (char)(int)((double)(float)(local_70 - dVar2) * dVar7);
    iVar3 = 0;
    iVar5 = 5;
    do {
      pdVar4 = this + iVar3;
      local_30 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x2065]);
      *(char *)(*(int *)(pdVar4 + 0x2030) + 0xac) =
           (char)(int)((double)(float)(local_30 - dVar2) * dVar7);
      local_40 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x217d]);
      *(char *)(*(int *)(pdVar4 + 0x2148) + 0xac) =
           (char)(int)((double)(float)(local_40 - dVar2) * dVar7);
      local_50 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x2295]);
      *(char *)(*(int *)(pdVar4 + 0x2260) + 0xac) =
           (char)(int)((double)(float)(local_50 - dVar2) * dVar7);
      dVar1 = d_menu_collect::_4290;
      iVar3 = iVar3 + 0x38;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    local_30 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x23ad]);
    *(char *)(*(int *)(this + 0x2378) + 0xac) =
         (char)(int)((double)(float)(local_30 - d_menu_collect::_4290) * dVar7);
    local_40 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x23e5]);
    *(char *)(*(int *)(this + 0x23b0) + 0xac) =
         (char)(int)((double)(float)(local_40 - dVar1) * dVar7);
    local_50 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x241d]);
    *(char *)(*(int *)(this + 0x23e8) + 0xac) =
         (char)(int)((double)(float)(local_50 - dVar1) * dVar7);
    local_60 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x2455]);
    *(char *)(*(int *)(this + 0x2420) + 0xac) =
         (char)(int)((double)(float)(local_60 - dVar1) * dVar7);
  }
  outFontDraw(this);
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(*(J2DScreen **)(this + 4),d_menu_collect::_4288,d_menu_collect::_4288,
                  &pCtx->parent);
  dMenu_Option_c::_draw(*(dMenu_Option_c **)(this + 0x2780));
  dMenu_save_c::_draw(*(dMenu_save_c **)(this + 0x2784));
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x801a69b8) */
/* __thiscall dMenu_Collect_c::_open(void) */

bool __thiscall dMenu_Collect_c::_open(dMenu_Collect_c *this)

{
  dMenu_Collect_c dVar1;
  short sVar2;
  char cVar3;
  ___ in_r5;
  int iVar4;
  dMenu_Collect_c *pdVar5;
  int iVar6;
  int iVar7;
  
  if (*(short *)(this + 0x27e2) == 0) {
    iVar4 = 0;
    iVar7 = 0;
    iVar6 = 0;
    do {
      pdVar5 = this + iVar6;
      MSL_C.PPCEABI.bare.H::strcpy(*(char **)(pdVar5 + 0x27b0),"");
      MSL_C.PPCEABI.bare.H::strcpy(*(char **)(pdVar5 + 0x27b8),"");
      J2DTextBox::setString
                (*(J2DTextBox **)(this + iVar7 + 0x890),*(char **)(pdVar5 + 0x27b0),in_r5);
      iVar4 = iVar4 + 1;
      iVar7 = iVar7 + 0x38;
      iVar6 = iVar6 + 4;
    } while (iVar4 < 2);
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x778),*(char **)(this + 0x27b8),in_r5);
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x740),*(char **)(this + 0x27bc),in_r5);
    itemnameSet(this);
    itemnoteSet(this);
    itemSet(this);
    dVar1 = this[0x27ed];
    if ((byte)dVar1 < 8) {
      cVar3 = collectItemGetCheck(this,(uchar)dVar1);
      if (cVar3 == '\0') {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
        d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
      }
      else {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x17;
      }
    }
    else {
      cVar3 = collectItemGetCheck(this,(uchar)dVar1);
      if (cVar3 == '\0') {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
        d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
      }
      else {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x21;
      }
    }
  }
  *(short *)(this + 0x27e2) = *(short *)(this + 0x27e2) + 1;
  sVar2 = *(short *)(this + 0x27e2);
  if (sVar2 < 0xb) {
    if (this[0x27ec] == (dMenu_Collect_c)0x2) {
      mainOpenProc(this,sVar2,10,-100);
      subOpenProc(this,*(short *)(this + 0x27e2),10,-100);
    }
    else {
      mainOpenProc(this,sVar2,10,100);
      subOpenProc(this,*(short *)(this + 0x27e2),10,100);
    }
    titleOpenProc(this,*(short *)(this + 0x27e2),10);
    noteOpenProc(this,*(short *)(this + 0x27e2),10);
    nameOpenProc(this,*(short *)(this + 0x27e2),10);
  }
  sVar2 = *(short *)(this + 0x27e2);
  if (9 < sVar2) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x813,(cXyz *)0x0,0,0,d_menu_collect::_4440,
               d_menu_collect::_4440,d_menu_collect::_5050,d_menu_collect::_5050,0);
  }
  return 9 < sVar2;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dMenu_Collect_c::_open3(void) */

bool __thiscall dMenu_Collect_c::_open3(dMenu_Collect_c *this)

{
  short sVar1;
  ___ in_r5;
  int iVar2;
  dMenu_Collect_c *pdVar3;
  int iVar4;
  int iVar5;
  
  if (*(short *)(this + 0x27e2) == 0) {
    iVar2 = 0;
    iVar5 = 0;
    iVar4 = 0;
    do {
      pdVar3 = this + iVar4;
      MSL_C.PPCEABI.bare.H::strcpy(*(char **)(pdVar3 + 0x27b0),"");
      MSL_C.PPCEABI.bare.H::strcpy(*(char **)(pdVar3 + 0x27b8),"");
      J2DTextBox::setString
                (*(J2DTextBox **)(this + iVar5 + 0x890),*(char **)(pdVar3 + 0x27b0),in_r5);
      iVar2 = iVar2 + 1;
      iVar5 = iVar5 + 0x38;
      iVar4 = iVar4 + 4;
    } while (iVar2 < 2);
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x778),*(char **)(this + 0x27b8),in_r5);
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x740),*(char **)(this + 0x27bc),in_r5);
    this[0x27ed] = (dMenu_Collect_c)0x1;
    itemnameSet(this);
    itemnoteSet(this);
    itemSet(this);
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x3e;
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 0x3e;
  }
  *(short *)(this + 0x27e2) = *(short *)(this + 0x27e2) + 1;
  if (*(short *)(this + 0x27e2) < 0xb) {
    mainOpenProc(this,*(short *)(this + 0x27e2),10,100);
    subOpenProc(this,*(short *)(this + 0x27e2),10,100);
    titleOpenProc(this,*(short *)(this + 0x27e2),10);
    noteOpenProc(this,*(short *)(this + 0x27e2),10);
    nameOpenProc(this,*(short *)(this + 0x27e2),10);
  }
  sVar1 = *(short *)(this + 0x27e2);
  if (9 < sVar1) {
    *(undefined2 *)(this + 0x27e2) = 0;
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x813,(cXyz *)0x0,0,0,d_menu_collect::_4440,
               d_menu_collect::_4440,d_menu_collect::_5050,d_menu_collect::_5050,0);
  }
  return 9 < sVar1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801a71c4) */
/* WARNING: Removing unreachable block (ram,0x801a71b4) */
/* WARNING: Removing unreachable block (ram,0x801a71ac) */
/* WARNING: Removing unreachable block (ram,0x801a71bc) */
/* WARNING: Removing unreachable block (ram,0x801a71cc) */
/* __thiscall dMenu_Collect_c::_close(void) */

undefined4 __thiscall dMenu_Collect_c::_close(dMenu_Collect_c *this)

{
  int iVar1;
  dMenu_Collect_c *pdVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f27;
  double dVar7;
  undefined8 in_f28;
  double dVar8;
  undefined8 in_f29;
  double dVar9;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar10;
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
  uVar4 = 0;
  *(short *)(this + 0x27e2) = *(short *)(this + 0x27e2) + -1;
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - *(short *)(this + 0x27e2),0);
  dVar9 = (double)(float)((double)d_menu_collect::_5339 * dVar6);
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - *(short *)(this + 0x27e2),0);
  dVar8 = (double)(float)((double)d_menu_collect::_5339 * dVar6);
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - *(short *)(this + 0x27e2),0);
  dVar7 = (double)(float)((double)d_menu_collect::_5339 * dVar6);
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - *(short *)(this + 0x27e2),0);
  dVar10 = (double)(float)((double)d_menu_collect::_5363 * dVar6);
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - *(short *)(this + 0x27e2),0);
  if (this[0x27ec] == (dMenu_Collect_c)0x2) {
    mainTrans(this,(float)-dVar9,d_menu_collect::_4288);
    subTrans(this,(float)-dVar8,d_menu_collect::_4288);
    titleTrans(this,d_menu_collect::_4288,(float)dVar7);
    noteRotate(this,(float)((double)d_menu_collect::_5351 * dVar6),
               (float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x856) ^ 0x80000000) -
                      d_menu_collect::_4443) +
               (float)((double)(float)((double)CONCAT44(0x43300000,
                                                        0x2dU - (int)*(short *)(this + 0x856) ^
                                                        0x80000000) - d_menu_collect::_4443) * dVar6
                      ));
    nameTrans(this,d_menu_collect::_4288,(float)dVar10);
  }
  else {
    if (this[0x27ec] == (dMenu_Collect_c)0x1) {
      mainTrans(this,(float)dVar9,d_menu_collect::_4288);
      subTrans(this,(float)dVar8,d_menu_collect::_4288);
      titleTrans(this,d_menu_collect::_4288,(float)dVar7);
      noteRotate(this,(float)((double)d_menu_collect::_5351 * dVar6),
                 (float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x856) ^ 0x80000000) -
                        d_menu_collect::_4443) +
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          0x2dU - (int)*(short *)(this + 0x856) ^
                                                          0x80000000) - d_menu_collect::_4443) *
                        dVar6));
      nameTrans(this,d_menu_collect::_4288,(float)dVar10);
    }
  }
  if (*(short *)(this + 0x27e2) < 1) {
    uVar4 = 1;
    iVar3 = 0;
    this[0x27ea] = (dMenu_Collect_c)0x0;
    d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
    iVar1 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0xb0));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 0xf);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x740));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x778));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x7b0));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x7e8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x820));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x858));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x890));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x8c8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x900));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x938));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x970));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x9a8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x9e0));
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0xa18));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 4);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xaf8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xb30));
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0xb68));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 4);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xc48));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xc80));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xcb8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xcf0));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xd28));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xd60));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xd98));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xdd0));
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0xe08));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 8);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xfc8));
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0x1000));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0x10a8));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 3);
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0x1150));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 0xb);
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0x13b8));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 3);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1460));
    iVar1 = 0;
    iVar3 = 0;
    do {
      pdVar2 = this + iVar3;
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x1498));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x15e8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x17a8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x18f8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x1a48));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x1b98));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x1ce8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x1e38));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 6);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1738));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 6000));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1f88));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1fc0));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1ff8));
    iVar1 = 0;
    iVar3 = 0;
    do {
      pdVar2 = this + iVar3;
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x2030));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x2148));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x2260));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 5);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x2378));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x23b0));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x23e8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x2420));
  }
  else {
    this[0x27ea] = (dMenu_Collect_c)0x1;
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
  return uVar4;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801a76e8) */
/* WARNING: Removing unreachable block (ram,0x801a76d8) */
/* WARNING: Removing unreachable block (ram,0x801a76d0) */
/* WARNING: Removing unreachable block (ram,0x801a76e0) */
/* WARNING: Removing unreachable block (ram,0x801a76f0) */
/* __thiscall dMenu_Collect_c::_close3(void) */

undefined4 __thiscall dMenu_Collect_c::_close3(dMenu_Collect_c *this)

{
  int iVar1;
  dMenu_Collect_c *pdVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f27;
  double dVar7;
  undefined8 in_f28;
  double dVar8;
  undefined8 in_f29;
  double dVar9;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar10;
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
  uVar4 = 0;
  *(short *)(this + 0x27e2) = *(short *)(this + 0x27e2) + -1;
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - *(short *)(this + 0x27e2),0);
  dVar9 = (double)(float)((double)d_menu_collect::_5339 * dVar6);
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - *(short *)(this + 0x27e2),0);
  dVar8 = (double)(float)((double)d_menu_collect::_5339 * dVar6);
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - *(short *)(this + 0x27e2),0);
  dVar7 = (double)(float)((double)d_menu_collect::_5339 * dVar6);
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - *(short *)(this + 0x27e2),0);
  dVar10 = (double)(float)((double)d_menu_collect::_5363 * dVar6);
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - *(short *)(this + 0x27e2),0);
  if (this[0x27ec] == (dMenu_Collect_c)0x2) {
    mainTrans(this,(float)-dVar9,d_menu_collect::_4288);
    subTrans(this,(float)-dVar8,d_menu_collect::_4288);
    titleTrans(this,d_menu_collect::_4288,(float)dVar7);
    noteRotate(this,(float)((double)d_menu_collect::_5351 * dVar6),
               (float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x856) ^ 0x80000000) -
                      d_menu_collect::_4443) +
               (float)((double)(float)((double)CONCAT44(0x43300000,
                                                        0x2dU - (int)*(short *)(this + 0x856) ^
                                                        0x80000000) - d_menu_collect::_4443) * dVar6
                      ));
    nameTrans(this,d_menu_collect::_4288,(float)dVar10);
  }
  else {
    if (this[0x27ec] == (dMenu_Collect_c)0x1) {
      mainTrans(this,(float)dVar9,d_menu_collect::_4288);
      subTrans(this,(float)dVar8,d_menu_collect::_4288);
      titleTrans(this,d_menu_collect::_4288,(float)dVar7);
      noteRotate(this,(float)((double)d_menu_collect::_5351 * dVar6),
                 (float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x856) ^ 0x80000000) -
                        d_menu_collect::_4443) +
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          0x2dU - (int)*(short *)(this + 0x856) ^
                                                          0x80000000) - d_menu_collect::_4443) *
                        dVar6));
      nameTrans(this,d_menu_collect::_4288,(float)dVar10);
    }
  }
  if (*(short *)(this + 0x27e2) < 1) {
    uVar4 = 1;
    iVar3 = 0;
    this[0x27ea] = (dMenu_Collect_c)0x0;
    d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
    iVar1 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0xb0));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 0xf);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x740));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x778));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x7b0));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x7e8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x820));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x858));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x890));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x8c8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x900));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x938));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x970));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x9a8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x9e0));
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0xa18));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 4);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xaf8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xb30));
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0xb68));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 4);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xc48));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xc80));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xcb8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xcf0));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xd28));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xd60));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xd98));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xdd0));
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0xe08));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 8);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xfc8));
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0x1000));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0x10a8));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 3);
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0x1150));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 0xb);
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0x13b8));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 3);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1460));
    iVar1 = 0;
    iVar3 = 0;
    do {
      pdVar2 = this + iVar3;
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x1498));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x15e8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x17a8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x18f8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x1a48));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x1b98));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x1ce8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x1e38));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 6);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1738));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 6000));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1f88));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1fc0));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1ff8));
    iVar1 = 0;
    iVar3 = 0;
    do {
      pdVar2 = this + iVar3;
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x2030));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x2148));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x2260));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 5);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x2378));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x23b0));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x23e8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x2420));
  }
  else {
    this[0x27ea] = (dMenu_Collect_c)0x1;
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
  return uVar4;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMenu_Collect_c::animeStep1(short,
                                          short) */

void __thiscall dMenu_Collect_c::animeStep1(dMenu_Collect_c *this,short param_1,short param_2)

{
  float fVar1;
  JPABaseEmitter *pJVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  double dVar6;
  cXyz local_58;
  cXyz local_4c;
  cXyz local_40;
  longlong local_30;
  undefined4 local_28;
  uint uStack36;
  double local_20;
  
  iVar4 = (int)param_1;
  iVar5 = (int)param_2;
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar4,iVar5,0);
  local_30 = (longlong)(int)((double)d_menu_collect::_6282 * dVar6);
  this[0xe05] = SUB41((int)((double)d_menu_collect::_6282 * dVar6),0);
  uStack36 = (uint)DAT_803e6030;
  local_28 = 0x43300000;
  iVar3 = (int)((double)(float)((double)CONCAT44(0x43300000,uStack36) - d_menu_collect::_4290) *
               dVar6);
  local_20 = (double)(longlong)iVar3;
  this[0xdcd] = SUB41(iVar3,0);
  if (iVar4 + -8 == iVar5) {
    local_40.y = *(float *)(this + 0xfb0) - d_menu_collect::_5149;
    local_40.x = *(float *)(this + 0xfac) - d_menu_collect::_5148;
    local_40.z = d_menu_collect::_4288;
    if (*(int *)(this + 0x2484) == 0) {
      pJVar2 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,9,0x2d,
                                  &local_40,(csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,
                                  -1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
      *(JPABaseEmitter **)(this + 0x2484) = pJVar2;
      *(undefined *)(*(int *)(this + 0x2484) + 0x1ff) = 0xff;
    }
  }
  else {
    if (iVar4 + -4 == iVar5) {
      local_4c.y = *(float *)(this + 0xe60) - d_menu_collect::_5149;
      local_4c.x = *(float *)(this + 0xe5c) - d_menu_collect::_5148;
      local_4c.z = d_menu_collect::_4288;
      if (*(int *)(this + 0x2480) == 0) {
        pJVar2 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,9,0x2d,
                                    &local_4c,(csXyz *)0x0,(cXyz *)0x0,0xff,
                                    (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                                    (cXyz *)0x0);
        *(JPABaseEmitter **)(this + 0x2480) = pJVar2;
        *(undefined *)(*(int *)(this + 0x2480) + 0x1ff) = 0xff;
      }
    }
  }
  if (param_1 == param_2) {
    iVar4 = 0;
    iVar3 = 0;
    iVar5 = 8;
    do {
      if (iVar4 == 4) {
        *(undefined *)(*(int *)(this + iVar3 + 0xe08) + 0xaa) = 1;
      }
      else {
        *(undefined *)(*(int *)(this + iVar3 + 0xe08) + 0xaa) = 0;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x38;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    J2DPicture::changeTexture(*(J2DPicture **)(this + 0xee8),"triforce.bti",0);
    iVar3 = JKRArchive::getGlbResource(0x54494d47,"triforce.bti",*(JKRArchive **)(this + 0x2464));
    *(undefined4 *)(this + 0xefc) = *(undefined4 *)(this + 0xfdc);
    *(undefined4 *)(this + 0xf00) = *(undefined4 *)(this + 0xfe0);
    *(undefined4 *)(this + 0xf04) = *(undefined4 *)(this + 0xfe4);
    *(undefined4 *)(this + 0xf08) = *(undefined4 *)(this + 0xfe8);
    fVar1 = d_menu_collect::_5660;
    dVar6 = d_menu_collect::_4290;
    local_20 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(iVar3 + 2));
    *(float *)(this + 0xf14) = d_menu_collect::_5660 * (float)(local_20 - d_menu_collect::_4290);
    uStack36 = (uint)*(ushort *)(iVar3 + 4);
    local_28 = 0x43300000;
    *(float *)(this + 0xf18) = fVar1 * (float)((double)CONCAT44(0x43300000,uStack36) - dVar6);
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(this + 0xee8));
    local_58.y = *(float *)(this + 0xf78) - d_menu_collect::_5149;
    local_58.x = *(float *)(this + 0xf74) - d_menu_collect::_5148;
    local_58.z = d_menu_collect::_4288;
    if (*(int *)(this + 0x247c) == 0) {
      pJVar2 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,9,0x2d,
                                  &local_58,(csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,
                                  -1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
      *(JPABaseEmitter **)(this + 0x247c) = pJVar2;
      *(undefined *)(*(int *)(this + 0x247c) + 0x1ff) = 0xff;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801a7b48) */
/* WARNING: Removing unreachable block (ram,0x801a7b50) */
/* __thiscall dMenu_Collect_c::animeStep2(short,
                                          short) */

void __thiscall dMenu_Collect_c::animeStep2(dMenu_Collect_c *this,short param_1,short param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  iVar1 = (int)param_1;
  iVar2 = (int)param_2;
  dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar1,iVar2,0);
  dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar1,iVar1 - iVar2,2);
  f_op_msg_mng::fopMsgM_paneScaleXY
            ((fopMsgM_pane_class *)(this + 0xd98),
             d_menu_collect::_4440 + (float)((double)(DAT_803e6028 - d_menu_collect::_4440) * dVar4)
            );
  this[0xdcd] = SUB41((int)((double)(float)((double)CONCAT44(0x43300000,(uint)DAT_803e6030) -
                                           d_menu_collect::_4290) * dVar5),0);
  if (iVar1 == iVar2) {
    this[0x27ed] = (dMenu_Collect_c)0x2;
    itemnameSet(this);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x890));
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x8c8);
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x801a7c94) */
/* WARNING: Removing unreachable block (ram,0x801a7c9c) */
/* __thiscall dMenu_Collect_c::animeStep3(short,
                                          short) */

void __thiscall dMenu_Collect_c::animeStep3(dMenu_Collect_c *this,short param_1,short param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  double dVar10;
  double dVar11;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined4 local_58;
  undefined2 local_54;
  float local_50;
  float local_4c;
  float local_48;
  longlong local_40;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  iVar7 = (int)param_1;
  dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar7,iVar7 - param_2,1);
  dVar11 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar7,(int)param_2,2);
  local_40 = (longlong)(int)((double)d_menu_collect::_6282 * dVar10);
  this[0xe05] = SUB41((int)((double)d_menu_collect::_6282 * dVar10),0);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x890),(float)dVar11);
  f_op_msg_mng::fopMsgM_setNowAlpha
            ((fopMsgM_pane_class *)(this + 0x8c8),(float)((double)d_menu_collect::_4440 - dVar11));
  fVar3 = d_menu_collect::_5149;
  fVar2 = d_menu_collect::_5148;
  fVar1 = d_menu_collect::_4288;
  local_58 = d_menu_collect::_8592;
  local_54 = DAT_803faddc;
  iVar7 = 0;
  iVar4 = 0;
  local_48 = d_menu_collect::_4288;
  iVar8 = 3;
  do {
    local_4c = *(float *)(this + *(short *)((int)&local_58 + iVar4) * 0x38 + 0xe28) - fVar3;
    local_50 = *(float *)(this + *(short *)((int)&local_58 + iVar4) * 0x38 + 0xe24) - fVar2;
    iVar6 = iVar7 + 0x247c;
    iVar5 = *(int *)(this + iVar6);
    if (iVar5 != 0) {
      *(float *)(iVar5 + 0x1e4) = local_50;
      *(float *)(iVar5 + 0x1e8) = local_4c;
      *(float *)(iVar5 + 0x1ec) = fVar1;
      *(uint *)(*(int *)(this + iVar6) + 0x20c) =
           *(uint *)(*(int *)(this + iVar6) + 0x20c) & 0xfffffffb;
      *(undefined *)(*(int *)(this + iVar6) + 0x1ff) = 0xff;
    }
    iVar7 = iVar7 + 4;
    iVar4 = iVar4 + 2;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  return;
}


/* __thiscall dMenu_Collect_c::animeStep4(short,
                                          short) */

void __thiscall dMenu_Collect_c::animeStep4(dMenu_Collect_c *this,short param_1,short param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)(short)((param_1 >> 2) + (ushort)(param_1 < 0 && (param_1 & 3U) != 0));
  iVar1 = (int)param_2;
  if (iVar1 == iVar2) {
    if (*(int *)(this + 0x247c) != 0) {
      *(undefined *)(*(int *)(this + 0x247c) + 0x1ff) = 0;
    }
  }
  else {
    if (iVar1 == iVar2 << 1) {
      if (*(int *)(this + 0x2480) != 0) {
        *(undefined *)(*(int *)(this + 0x2480) + 0x1ff) = 0;
      }
    }
    else {
      if ((iVar1 == iVar2 * 3) && (*(int *)(this + 0x2484) != 0)) {
        *(undefined *)(*(int *)(this + 0x2484) + 0x1ff) = 0;
      }
    }
  }
  triforceAnime(this,DAT_803e6031);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x801a7e38) */
/* __thiscall dMenu_Collect_c::_open2(void) */

bool __thiscall dMenu_Collect_c::_open2(dMenu_Collect_c *this)

{
  dMenu_Collect_c dVar1;
  short sVar2;
  short sVar3;
  char cVar4;
  ___ in_r5;
  int iVar5;
  dMenu_Collect_c *pdVar6;
  int iVar7;
  int iVar8;
  
  sVar3 = DAT_803e6afe;
  if (*(short *)(this + 0x27e2) == 0) {
    iVar5 = 0;
    iVar8 = 0;
    iVar7 = 0;
    do {
      pdVar6 = this + iVar7;
      MSL_C.PPCEABI.bare.H::strcpy(*(char **)(pdVar6 + 0x27b0),"");
      MSL_C.PPCEABI.bare.H::strcpy(*(char **)(pdVar6 + 0x27b8),"");
      J2DTextBox::setString
                (*(J2DTextBox **)(this + iVar8 + 0x890),*(char **)(pdVar6 + 0x27b0),in_r5);
      iVar5 = iVar5 + 1;
      iVar8 = iVar8 + 0x38;
      iVar7 = iVar7 + 4;
    } while (iVar5 < 2);
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x778),*(char **)(this + 0x27b8),in_r5);
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x740),*(char **)(this + 0x27bc),in_r5);
    itemnameSet(this);
    itemnoteSet(this);
    itemSet(this);
    dVar1 = this[0x27ed];
    if ((byte)dVar1 < 8) {
      cVar4 = collectItemGetCheck(this,(uchar)dVar1);
      if (cVar4 == '\0') {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
        d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
      }
      else {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x17;
      }
    }
    else {
      cVar4 = collectItemGetCheck(this,(uchar)dVar1);
      if (cVar4 == '\0') {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
        d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
      }
      else {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x21;
      }
    }
  }
  *(short *)(this + 0x27e2) = *(short *)(this + 0x27e2) + 1;
  sVar2 = *(short *)(this + 0x27e2);
  if (sVar2 <= sVar3) {
    if (this[0x27ec] == (dMenu_Collect_c)0x2) {
      mainOpenProc(this,sVar2,sVar3,-100);
      subOpenProc(this,*(short *)(this + 0x27e2),sVar3,-100);
    }
    else {
      mainOpenProc(this,sVar2,sVar3,100);
      subOpenProc(this,*(short *)(this + 0x27e2),sVar3,100);
    }
    titleOpenProc(this,*(short *)(this + 0x27e2),sVar3);
    noteOpenProc(this,*(short *)(this + 0x27e2),sVar3);
    nameOpenProc(this,*(short *)(this + 0x27e2),sVar3);
  }
  return sVar3 <= *(short *)(this + 0x27e2);
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801a848c) */
/* WARNING: Removing unreachable block (ram,0x801a847c) */
/* WARNING: Removing unreachable block (ram,0x801a8474) */
/* WARNING: Removing unreachable block (ram,0x801a8484) */
/* WARNING: Removing unreachable block (ram,0x801a8494) */
/* __thiscall dMenu_Collect_c::_close2(void) */

undefined4 __thiscall dMenu_Collect_c::_close2(dMenu_Collect_c *this)

{
  int iVar1;
  dMenu_Collect_c *pdVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f27;
  double dVar7;
  undefined8 in_f28;
  double dVar8;
  undefined8 in_f29;
  double dVar9;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar10;
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
  uVar4 = 0;
  *(short *)(this + 0x27e2) = *(short *)(this + 0x27e2) + -1;
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                            ((int)DAT_803e6afe,(int)DAT_803e6afe - (int)*(short *)(this + 0x27e2),0)
  ;
  dVar9 = (double)(float)((double)d_menu_collect::_5339 * dVar6);
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                            ((int)DAT_803e6afe,(int)DAT_803e6afe - (int)*(short *)(this + 0x27e2),0)
  ;
  dVar8 = (double)(float)((double)d_menu_collect::_5339 * dVar6);
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                            ((int)DAT_803e6afe,(int)DAT_803e6afe - (int)*(short *)(this + 0x27e2),0)
  ;
  dVar7 = (double)(float)((double)d_menu_collect::_5339 * dVar6);
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                            ((int)DAT_803e6afe,(int)DAT_803e6afe - (int)*(short *)(this + 0x27e2),0)
  ;
  dVar10 = (double)(float)((double)d_menu_collect::_5363 * dVar6);
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                            ((int)DAT_803e6afe,(int)DAT_803e6afe - (int)*(short *)(this + 0x27e2),0)
  ;
  if (this[0x27ec] == (dMenu_Collect_c)0x2) {
    mainTrans(this,(float)-dVar9,d_menu_collect::_4288);
    subTrans(this,(float)-dVar8,d_menu_collect::_4288);
    titleTrans(this,d_menu_collect::_4288,(float)dVar7);
    noteRotate(this,(float)((double)d_menu_collect::_5351 * dVar6),
               (float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x856) ^ 0x80000000) -
                      d_menu_collect::_4443) +
               (float)((double)(float)((double)CONCAT44(0x43300000,
                                                        0x2dU - (int)*(short *)(this + 0x856) ^
                                                        0x80000000) - d_menu_collect::_4443) * dVar6
                      ));
    nameTrans(this,d_menu_collect::_4288,(float)dVar10);
  }
  else {
    if (this[0x27ec] == (dMenu_Collect_c)0x1) {
      mainTrans(this,(float)dVar9,d_menu_collect::_4288);
      subTrans(this,(float)dVar8,d_menu_collect::_4288);
      titleTrans(this,d_menu_collect::_4288,(float)dVar7);
      noteRotate(this,(float)((double)d_menu_collect::_5351 * dVar6),
                 (float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x856) ^ 0x80000000) -
                        d_menu_collect::_4443) +
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          0x2dU - (int)*(short *)(this + 0x856) ^
                                                          0x80000000) - d_menu_collect::_4443) *
                        dVar6));
      nameTrans(this,d_menu_collect::_4288,(float)dVar10);
    }
  }
  if (*(short *)(this + 0x27e2) < 1) {
    uVar4 = 1;
    iVar3 = 0;
    this[0x27ea] = (dMenu_Collect_c)0x0;
    d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
    iVar1 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0xb0));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 0xf);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x740));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x778));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x7b0));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x7e8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x820));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x858));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x890));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x8c8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x900));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x938));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x970));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x9a8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x9e0));
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0xa18));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 4);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xaf8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xb30));
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0xb68));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 4);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xc48));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xc48));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xc80));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xcf0));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xd28));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xd60));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xd98));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xdd0));
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0xe08));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 8);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xfc8));
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0x1000));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0x10a8));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 3);
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0x1150));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 0xb);
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0x13b8));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 3);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1460));
    iVar1 = 0;
    iVar3 = 0;
    do {
      pdVar2 = this + iVar3;
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x1498));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x15e8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x17a8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x18f8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x1a48));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x1b98));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x1ce8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x1e38));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 6);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1738));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 6000));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1f88));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1fc0));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1ff8));
    iVar1 = 0;
    iVar3 = 0;
    do {
      pdVar2 = this + iVar3;
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x2030));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x2148));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x2260));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 5);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x2378));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x23b0));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x23e8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x2420));
  }
  else {
    this[0x27ea] = (dMenu_Collect_c)0x1;
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
  return uVar4;
}


/* __thiscall dMenu_Option_c::~dMenu_Option_c(void) */

void __thiscall dMenu_Option_c::_dMenu_Option_c(dMenu_Option_c *this)

{
  short in_r4;
  
  if ((this != (dMenu_Option_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dMenu_Collect_c::~dMenu_Collect_c(void) */

void __thiscall dMenu_Collect_c::_dMenu_Collect_c(dMenu_Collect_c *this)

{
  short in_r4;
  
  if (this != (dMenu_Collect_c *)0x0) {
    *(undefined1 **)this = &__vt;
    fopMsgM_msgDataProc_c::_fopMsgM_msgDataProc_c((fopMsgM_msgDataProc_c *)(this + 0x24e0));
    if ((this != (dMenu_Collect_c *)0x0) &&
       (*(undefined1 **)this = &dMenu_base_c::__vt, this != (dMenu_Collect_c *)0x0)) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMenu_Collect_c::draw(void) */

void __thiscall dMenu_Collect_c::draw(dMenu_Collect_c *this)

{
  (**(code **)(*(int *)this + 0x1c))();
  return;
}


/* __thiscall dMenu_base_c::~dMenu_base_c(void) */

void __thiscall dMenu_base_c::_dMenu_base_c(dMenu_base_c *this)

{
  short in_r4;
  
  if (this != (dMenu_base_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dMenu_base_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMenu_base_c::_create(void) */

void __thiscall dMenu_base_c::_create(dMenu_base_c *this)

{
  return;
}


/* __thiscall dMenu_base_c::_delete(void) */

void __thiscall dMenu_base_c::_delete(dMenu_base_c *this)

{
  return;
}


/* __thiscall dMenu_base_c::_move(void) */

void __thiscall dMenu_base_c::_move(dMenu_base_c *this)

{
  return;
}


/* __thiscall dMenu_base_c::_draw(void) */

void __thiscall dMenu_base_c::_draw(dMenu_base_c *this)

{
  return;
}


/* __thiscall dMenu_base_c::draw(void) */

void __thiscall dMenu_base_c::draw(dMenu_base_c *this)

{
  return;
}


/* __thiscall dMc_HIO_c::~dMc_HIO_c(void) */

void __thiscall dMc_HIO_c::_dMc_HIO_c(dMc_HIO_c *this)

{
  short in_r4;
  
  if ((this != (dMc_HIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace d_menu_collect {

void __sinit_d_menu_collect_cpp(void)

{
  ::dMc_HIO_c::dMc_HIO_c((dMc_HIO_c *)&g_mcHIO);
  Runtime.PPCEABI.H::__register_global_object();
  return;
}

