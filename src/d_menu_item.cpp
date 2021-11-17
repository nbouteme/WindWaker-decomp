#include <d_menu_item.h>
#include <d_menu_item.h>
#include <J2DGraph/J2DPane.h>
#include <f_op_msg_mng.h>
#include <J2DGraph/J2DTextBox.h>
#include <d_2dnumber.h>
#include <JKernel/JKRArchivePub.h>
#include <os/OSCache.h>
#include <J2DGraph/J2DPicture.h>
#include <d_lib.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_meter.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_particle.h>
#include <J2DGraph/J2DWindow.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DScreen.h>
#include <d_menu_save.h>
#include <m_Do_hostIO.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dMi_HIO_c.h>
#include <dMenu_Item_c.h>


namespace d_menu_item {
struct dMi_HIO_c g_miHIO;
}

/* __thiscall dMi_HIO_c::dMi_HIO_c(void) */

void __thiscall dMi_HIO_c::dMi_HIO_c(dMi_HIO_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  this->field_0x0 = &__vt;
  this->field_0x4c = 0xffffffff;
  this->field_0x50 = 0xffffffff;
  this->field_0x8 = d_menu_item::_4058;
  this->field_0xc = 0xf;
  iVar1 = 0;
  iVar3 = 5;
  do {
    iVar2 = (int)&this->field_0x0 + iVar1;
    *(undefined2 *)(iVar2 + 0xe) = 0;
    *(undefined2 *)(iVar2 + 0x1a) = 10;
    iVar1 = iVar1 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  this->field_0x18 = 0;
  this->field_0x24 = 1;
  this->field_0x26 = 0xff9c;
  this->field_0x28 = 0xff9c;
  this->field_0x2a = 0xffd3;
  this->field_0x2c = 0x32;
  this->field_0x2e = 0x1e;
  this->field_0x30 = 0xfffd;
  this->field_0x32 = 10;
  this->field_0x34 = 7;
  this->field_0x36 = 0xe;
  this->field_0x38 = 5;
  this->field_0x3a = 0xc;
  this->field_0x3c = 10;
  this->field_0x40 = 0x140;
  this->field_0x42 = 0xf0;
  this->field_0x3e = 200;
  this->field_0x46 = 0;
  this->field_0x48 = 0x14;
  this->field_0x44 = 0xff88;
  (this->field_0x54).r = 0xe3;
  (this->field_0x54).g = 0xff;
  (this->field_0x54).b = 0xb3;
  (this->field_0x54).a = 0xdc;
  (this->field_0x58).r = 0;
  (this->field_0x58).g = 0;
  (this->field_0x58).b = 0;
  (this->field_0x58).a = 0;
  *(undefined *)&this->field_0x5c = 0x82;
  *(undefined *)&this->field_0x4c = 0;
  *(undefined *)((int)&this->field_0x4c + 1) = 0;
  *(undefined *)((int)&this->field_0x4c + 2) = 0;
  *(undefined *)((int)&this->field_0x4c + 3) = 0xff;
  return;
}


/* __thiscall dMenu_Item_c::initialize(void) */

void __thiscall dMenu_Item_c::initialize(dMenu_Item_c *this)

{
  int iVar1;
  
  itemBitCheck(this,true);
  *(undefined2 *)(this + 0x23f8) = 0;
  *(undefined2 *)(this + 0x88e) = 10;
  *(undefined2 *)(this + 0xa4e) = 0;
  this[0x2422] = (dMenu_Item_c)0x0;
  noteInit(this);
  outFontInit(this);
  checkMove(this);
  itemNumberSet(this);
  this[0x9a4] = d_menu_item::g_miHIO._92_1_;
  *(undefined2 *)(this + 0x23fa) = 0;
  *(undefined2 *)(this + 0x23fc) = 0;
  iVar1 = *(int *)(this + 0x14d0);
  this[0x2320] = *(dMenu_Item_c *)(iVar1 + 0xf4);
  this[0x2321] = *(dMenu_Item_c *)(iVar1 + 0xf5);
  this[0x2322] = *(dMenu_Item_c *)(iVar1 + 0xf6);
  this[0x2323] = *(dMenu_Item_c *)(iVar1 + 0xf7);
  this[0x2324] = *(dMenu_Item_c *)(iVar1 + 0xf8);
  this[0x2325] = *(dMenu_Item_c *)(iVar1 + 0xf9);
  this[0x2326] = *(dMenu_Item_c *)(iVar1 + 0xfa);
  this[8999] = *(dMenu_Item_c *)(iVar1 + 0xfb);
  this[9000] = *(dMenu_Item_c *)(iVar1 + 0xfc);
  this[0x2329] = *(dMenu_Item_c *)(iVar1 + 0xfd);
  this[0x232a] = *(dMenu_Item_c *)(iVar1 + 0xfe);
  this[0x232b] = *(dMenu_Item_c *)(iVar1 + 0xff);
  this[0x232c] = *(dMenu_Item_c *)(iVar1 + 0x100);
  this[0x232d] = *(dMenu_Item_c *)(iVar1 + 0x101);
  this[0x232e] = *(dMenu_Item_c *)(iVar1 + 0x102);
  this[0x232f] = *(dMenu_Item_c *)(iVar1 + 0x103);
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x231c),*(J2DPane **)(this + 0x1460),*(J2DPane **)(this + 0xac0));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x231c),*(J2DPane **)(this + 0xac0),*(J2DPane **)(this + 0xa88));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x231c),*(J2DPane **)(this + 0xa88),*(J2DPane **)(this + 0xa50));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x231c),*(J2DPane **)(this + 0xa50),*(J2DPane **)(this + 0xa18));
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMenu_Item_c::screenSet(void) */

void __thiscall dMenu_Item_c::screenSet(dMenu_Item_c *this)

{
  uint uVar1;
  undefined4 uVar2;
  J2DScreen *pJVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  dSv_player_bag_item_c *pdVar7;
  int iVar8;
  dSv_player_item_c *pdVar9;
  dMenu_Item_c *pdVar10;
  
  uVar2 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x524f4f54);
  *(undefined4 *)(this + 0x231c) = uVar2;
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 8),*(J2DScreen **)(this + 4),0x66743135);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x40),*(J2DScreen **)(this + 4),0x66743136);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x78),*(J2DScreen **)(this + 4),0x66743137);
  iVar4 = 0;
  iVar6 = 0;
  iVar8 = 0;
  do {
    pJVar3 = (J2DScreen *)
             (**(code **)(**(int **)(this + 4) + 0x30))
                       (*(int **)(this + 4),*(undefined4 *)((int)&d_menu_item::l_ft_4080 + iVar8));
    pdVar10 = this + iVar6;
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar10 + 0xb0),pJVar3);
    pJVar3 = (J2DScreen *)
             (**(code **)(**(int **)(this + 4) + 0x30))
                       (*(int **)(this + 4),*(undefined4 *)((int)&d_menu_item::l_fd_4091 + iVar8));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar10 + 0x3f8),pJVar3);
    *(undefined2 *)(pdVar10 + 0xe6) = 0xffff;
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 0x38;
    iVar8 = iVar8 + 4;
  } while (iVar4 < 0xf);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x740),*(J2DScreen **)(this + 4),0x73747230);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x778),*(J2DScreen **)(this + 4),0x73743030);
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ != '\0') {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x778),(double)d_menu_item::_4323,
               (double)d_menu_item::_4324);
  }
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x7b0),*(J2DScreen **)(this + 4),0x6e743030);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x7e8),*(J2DScreen **)(this + 4),0x6e6b3030);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x820),*(J2DScreen **)(this + 4),0x6e6f3131);
  *(short *)(this + 0x856) = (short)(int)*(float *)(*(int *)(this + 0x820) + 0xa4);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x740),*(JUTFont **)(this + 0x2318));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x778),*(JUTFont **)(this + 0x2314));
  iVar4 = *(int *)(this + 0x740);
  *(undefined *)(iVar4 + 0xf4) = 0xff;
  *(undefined *)(iVar4 + 0xf5) = 0xff;
  *(undefined *)(iVar4 + 0xf6) = 0xff;
  *(undefined *)(iVar4 + 0xf7) = 0xff;
  iVar4 = *(int *)(this + 0x740);
  *(undefined *)(iVar4 + 0xd0) = 0;
  *(undefined *)(iVar4 + 0xd1) = 0;
  *(undefined *)(iVar4 + 0xd2) = 0;
  *(undefined *)(iVar4 + 0xd3) = 0xff;
  iVar4 = *(int *)(this + 0x740);
  *(undefined *)(iVar4 + 0xd4) = 0;
  *(undefined *)(iVar4 + 0xd5) = 0;
  *(undefined *)(iVar4 + 0xd6) = 0;
  *(undefined *)(iVar4 + 0xd7) = 0xff;
  iVar4 = *(int *)(this + 0x778);
  *(undefined *)(iVar4 + 0xf4) = 0xff;
  *(undefined *)(iVar4 + 0xf5) = 0xff;
  *(undefined *)(iVar4 + 0xf6) = 0xff;
  *(undefined *)(iVar4 + 0xf7) = 0xff;
  iVar4 = *(int *)(this + 0x778);
  *(undefined *)(iVar4 + 0xd0) = 0;
  *(undefined *)(iVar4 + 0xd1) = 0;
  *(undefined *)(iVar4 + 0xd2) = 0;
  *(undefined *)(iVar4 + 0xd3) = 0xff;
  iVar4 = *(int *)(this + 0x778);
  *(undefined *)(iVar4 + 0xd4) = 0;
  *(undefined *)(iVar4 + 0xd5) = 0;
  *(undefined *)(iVar4 + 0xd6) = 0;
  *(undefined *)(iVar4 + 0xd7) = 0xff;
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x858),*(J2DScreen **)(this + 4),0x7764);
  *(undefined *)(*(int *)(this + 0x858) + 0xaa) = 1;
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x858),*(JUTFont **)(this + 0x2314));
  dDlst_2DOutFont_c::setPane
            (*(dDlst_2DOutFont_c **)(this + 0x230c),*(JUTFont **)(this + 0x2314),
             (fopMsgM_pane_class *)(this + 0x858),(fopMsgM_pane_class *)(this + 8),
             (fopMsgM_pane_class *)(this + 0x40),(fopMsgM_pane_class *)(this + 0x78));
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x890),*(J2DScreen **)(this + 4),0x6e6d3030);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x890),*(JUTFont **)(this + 0x2314));
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x8c8),*(J2DScreen **)(this + 4),0x6e6d3031);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x8c8),*(JUTFont **)(this + 0x2314));
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
  iVar4 = 0;
  iVar6 = 0;
  iVar8 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar8 + 0xa18),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_item::l_car_4082 + iVar6));
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 4;
    iVar8 = iVar8 + 0x38;
  } while (iVar4 < 4);
  iVar4 = 0;
  iVar6 = 0;
  iVar8 = 0;
  do {
    pdVar10 = this + iVar8;
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar10 + 0xaf8),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_item::l_sin_01_4083 + iVar6));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar10 + 0xcb8),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_item::l_sin_10_4084 + iVar6));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar10 + 0xe78),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_item::l_sit_4085 + iVar6));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar10 + 0x1070),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_item::l_sik_4086 + iVar6));
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 4;
    iVar8 = iVar8 + 0x38;
  } while (iVar4 < 8);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1038),*(J2DScreen **)(this + 4),0x69743239);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1230),*(J2DScreen **)(this + 4),0x696b3239);
  iVar4 = 0;
  iVar6 = 0;
  iVar8 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar8 + 0x1268),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_item::l_sb_4087 + iVar6));
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 4;
    iVar8 = iVar8 + 0x38;
  } while (iVar4 < 9);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1460),*(J2DScreen **)(this + 4),0x626c616b);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1498),*(J2DScreen **)(this + 4),0x77647376);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x14d0),*(J2DScreen **)(this + 4),0x776b3031);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1508),*(J2DScreen **)(this + 4),0x776b3030);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1540),*(J2DScreen **)(this + 4),0x30333031);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1578),*(J2DScreen **)(this + 4),0x31333031);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x15b0),*(J2DScreen **)(this + 4),0x31333130);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x15e8),*(J2DScreen **)(this + 4),0x31343031);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1620),*(J2DScreen **)(this + 4),0x31343130);
  iVar4 = 0;
  iVar6 = 0;
  iVar8 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar8 + 0x1658),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_item::l_it_4088 + iVar6));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar8 + 0x1af0),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_item::l_ik_4089 + iVar6));
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 4;
    iVar8 = iVar8 + 0x38;
  } while (iVar4 < 0x15);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1f88),*(J2DScreen **)(this + 4),0x62776c31);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1fc0),*(J2DScreen **)(this + 4),0x62776c32);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1ff8),*(J2DScreen **)(this + 4),0x62776c33);
  *(undefined *)(*(int *)(this + 0x1f88) + 0xaa) = 0;
  *(undefined *)(*(int *)(this + 0x1fc0) + 0xaa) = 0;
  *(undefined *)(*(int *)(this + 0x1ff8) + 0xaa) = 0;
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x2030),*(J2DScreen **)(this + 4),0x63686b31);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x2068),*(J2DScreen **)(this + 4),0x63686b32);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x20a0),*(J2DScreen **)(this + 4),0x63686b33);
  iVar4 = 0;
  iVar6 = 0;
  iVar8 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar8 + 0x20d8),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_menu_item::l_ip_4090 + iVar6));
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 4;
    iVar8 = iVar8 + 0x38;
  } while (iVar4 < 6);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x2228),*(J2DScreen **)(this + 4),0x63633335);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x2260),*(J2DScreen **)(this + 4),0x63633232);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x2298),*(J2DScreen **)(this + 4),0x63633131);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x22d0),*(J2DScreen **)(this + 4),0x63633030);
  iVar8 = 0;
  iVar4 = 0;
  iVar6 = 0;
  pdVar7 = &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem;
  pdVar9 = &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem;
  do {
    if (iVar8 < 0x15) {
      uVar1 = (uint)pdVar9->mTelescopeSlot;
    }
    else {
      if (iVar8 < 0x18) {
        uVar1 = 0xff;
      }
      else {
        if (iVar8 < 0x20) {
          uVar1 = (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [iVar8 + 0xd];
        }
        else {
          if (iVar8 < 0x24) {
            uVar1 = 0xff;
          }
          else {
            if (iVar8 < 0x2c) {
              uVar1 = (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [iVar8 + 9];
            }
            else {
              if (iVar8 < 0x30) {
                uVar1 = 0xff;
              }
              else {
                if (iVar8 < 0x38) {
                  uVar1 = (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                mBits[iVar8 + 5];
                }
                else {
                  uVar1 = 0xff;
                }
              }
            }
          }
        }
      }
    }
    if (uVar1 != 0xff) {
      if (uVar1 == 0x35) {
        *(undefined *)(*(int *)(this + 0x1f88) + 0xaa) = 1;
        *(undefined *)(*(int *)(this + 0x1fc0) + 0xaa) = 1;
        *(undefined *)(*(int *)(this + 0x1ff8) + 0xaa) = 0;
        uVar1 = 0x27;
      }
      else {
        if (uVar1 == 0x36) {
          *(undefined *)(*(int *)(this + 0x1f88) + 0xaa) = 1;
          *(undefined *)(*(int *)(this + 0x1fc0) + 0xaa) = 1;
          *(undefined *)(*(int *)(this + 0x1ff8) + 0xaa) = 1;
          uVar1 = 0x27;
        }
      }
      iVar5 = iVar6 + 0x2334;
      JKRArchive::readTypeResource
                (*(void **)(this + iVar5),0xc00,0x54494d47,
                 dItem_data::item_resource[uVar1].mIconFilename,
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
      os::DCStoreRangeNoSync(*(undefined4 *)(this + iVar5),0xc00);
      J2DPicture::changeTexture
                (*(J2DPicture **)(this + iVar4 + 0x1658),*(ResTIMG **)(this + iVar5),'\0');
      J2DPicture::changeTexture
                (*(J2DPicture **)(this + iVar4 + 0x1af0),*(ResTIMG **)(this + iVar5),'\0');
    }
    iVar8 = iVar8 + 1;
    iVar4 = iVar4 + 0x38;
    iVar6 = iVar6 + 4;
    pdVar9 = (dSv_player_item_c *)&pdVar9->field_0x1;
  } while (iVar8 < 0x15);
  uVar1 = 0;
  iVar6 = 0;
  iVar4 = 0;
  do {
    if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0[uVar1 & 0xff] !=
        0xff) {
      iVar8 = iVar4 + 0x2394;
      JKRArchive::readTypeResource
                (*(void **)(this + iVar8),0xc00,0x54494d47,
                 dItem_data::item_resource[pdVar7->field_0x0[0]].mIconFilename,
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
      os::DCStoreRangeNoSync(*(undefined4 *)(this + iVar8),0xc00);
      J2DPicture::changeTexture
                (*(J2DPicture **)(this + iVar6 + 0xe78),*(ResTIMG **)(this + iVar8),'\0');
      J2DPicture::changeTexture
                (*(J2DPicture **)(this + iVar6 + 0x1070),*(ResTIMG **)(this + iVar8),'\0');
    }
    uVar1 = uVar1 + 1;
    iVar6 = iVar6 + 0x38;
    iVar4 = iVar4 + 4;
    pdVar7 = (dSv_player_bag_item_c *)(pdVar7->field_0x0 + 1);
  } while ((int)uVar1 < 8);
  JKRArchive::readTypeResource
            (*(void **)(this + 0x23b4),0xc00,0x54494d47,"cover_return.bti",
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
  os::DCStoreRangeNoSync(*(undefined4 *)(this + 0x23b4),0xc00);
  J2DPicture::changeTexture(*(J2DPicture **)(this + 0x1038),*(ResTIMG **)(this + 0x23b4),'\0');
  J2DPicture::changeTexture(*(J2DPicture **)(this + 0x1230),*(ResTIMG **)(this + 0x23b4),'\0');
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801c8aec) */
/* WARNING: Removing unreachable block (ram,0x801c8af4) */
/* __thiscall dMenu_Item_c::cursorAnime(void) */

void __thiscall dMenu_Item_c::cursorAnime(dMenu_Item_c *this)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  short unaff_r29;
  int iVar4;
  short unaff_r30;
  J2DPicture *pJVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  fVar1 = d_menu_item::_4392;
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  uVar2 = (uint)(byte)this[0x23ff];
  if (uVar2 == 0x15) {
    *(float *)(this + 0xa2c) =
         *(float *)(this + 0x14b4) - *(float *)(this + 0x14c4) * d_menu_item::_4392;
    *(float *)(this + 0xa30) = *(float *)(this + 0x14b8) + *(float *)(this + 0x14c8) * fVar1;
    *(float *)(this + 0xa64) = *(float *)(this + 0x14b4) + *(float *)(this + 0x14c4) * fVar1;
    *(float *)(this + 0xa68) = *(float *)(this + 0x14b8) + *(float *)(this + 0x14c8) * fVar1;
    *(float *)(this + 0xa9c) = *(float *)(this + 0x14b4) - *(float *)(this + 0x14c4) * fVar1;
    *(float *)(this + 0xaa0) = *(float *)(this + 0x14b8) - *(float *)(this + 0x14c8) * fVar1;
    *(float *)(this + 0xad4) = *(float *)(this + 0x14b4) + *(float *)(this + 0x14c4) * fVar1;
    *(float *)(this + 0xad8) = *(float *)(this + 0x14b8) - *(float *)(this + 0x14c8) * fVar1;
  }
  else {
    if (uVar2 < 0x18) {
      iVar3 = 0;
      iVar4 = 0;
      iVar6 = 4;
      do {
        *(float *)(this + iVar3 + 0xa2c) =
             *(float *)(this + uVar2 * 0x38 + 0x1674) + *(float *)(this + iVar4 + 0x23c0);
        *(float *)(this + iVar3 + 0xa30) =
             *(float *)(this + uVar2 * 0x38 + 0x1678) + *(float *)(this + iVar4 + 0x23d0);
        iVar3 = iVar3 + 0x38;
        iVar4 = iVar4 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    else {
      if (uVar2 == 0xff) {
        uVar2 = 8;
      }
      else {
        uVar2 = uVar2 - (byte)this[0x2400] & 0xff;
      }
      iVar3 = 0;
      iVar4 = 0;
      iVar6 = 4;
      do {
        *(float *)(this + iVar3 + 0xa2c) =
             *(float *)(this + uVar2 * 0x38 + 0xe94) + *(float *)(this + iVar4 + 0x23c0);
        *(float *)(this + iVar3 + 0xa30) =
             *(float *)(this + uVar2 * 0x38 + 0xe98) + *(float *)(this + iVar4 + 0x23d0);
        iVar3 = iVar3 + 0x38;
        iVar4 = iVar4 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  if ((int)*(short *)(this + 0xa4e) < (int)d_menu_item::g_miHIO.field_0x32) {
    iVar3 = 0;
    iVar4 = 0;
    dVar9 = (double)d_menu_item::_4393;
    dVar8 = (double)d_menu_item::_4323;
    do {
      pJVar5 = *(J2DPicture **)(this + iVar4 + 0xa18);
      pJVar5->mBlendKonstColorF[0] = (float)dVar9;
      pJVar5->mBlendKonstColorF[1] = (float)dVar8;
      pJVar5->mBlendKonstColorF[2] = (float)dVar9;
      pJVar5->mBlendKonstColorF[3] = (float)dVar9;
      J2DPicture::setBlendKonstColor(pJVar5);
      pJVar5->mBlendKonstAlphaF[0] = (float)dVar9;
      pJVar5->mBlendKonstAlphaF[1] = (float)dVar8;
      pJVar5->mBlendKonstAlphaF[2] = (float)dVar9;
      pJVar5->mBlendKonstAlphaF[3] = (float)dVar9;
      J2DPicture::setBlendKonstAlpha(pJVar5);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x38;
      unaff_r30 = d_menu_item::g_miHIO.field_0x34;
      unaff_r29 = d_menu_item::g_miHIO.field_0x34;
    } while (iVar3 < 4);
  }
  else {
    if ((int)*(short *)(this + 0xa4e) < (int)d_menu_item::g_miHIO.field_0x32 << 1) {
      iVar3 = 0;
      iVar4 = 0;
      dVar8 = (double)d_menu_item::_4323;
      dVar9 = (double)d_menu_item::_4393;
      do {
        pJVar5 = *(J2DPicture **)(this + iVar4 + 0xa18);
        pJVar5->mBlendKonstColorF[0] = (float)dVar8;
        pJVar5->mBlendKonstColorF[1] = (float)dVar9;
        pJVar5->mBlendKonstColorF[2] = (float)dVar9;
        pJVar5->mBlendKonstColorF[3] = (float)dVar9;
        J2DPicture::setBlendKonstColor(pJVar5);
        pJVar5->mBlendKonstAlphaF[0] = (float)dVar8;
        pJVar5->mBlendKonstAlphaF[1] = (float)dVar9;
        pJVar5->mBlendKonstAlphaF[2] = (float)dVar9;
        pJVar5->mBlendKonstAlphaF[3] = (float)dVar9;
        J2DPicture::setBlendKonstAlpha(pJVar5);
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x38;
        unaff_r30 = d_menu_item::g_miHIO.field_0x36;
        unaff_r29 = d_menu_item::g_miHIO.field_0x36;
      } while (iVar3 < 4);
    }
  }
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xa18),
             (double)(float)((double)CONCAT44(0x43300000,-(int)unaff_r30 ^ 0x80000000) -
                            d_menu_item::_4395),
             (double)(float)((double)CONCAT44(0x43300000,(int)unaff_r29 ^ 0x80000000) -
                            d_menu_item::_4395));
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xa50),
             (double)(float)((double)CONCAT44(0x43300000,(int)unaff_r30 ^ 0x80000000) -
                            d_menu_item::_4395),
             (double)(float)((double)CONCAT44(0x43300000,(int)unaff_r29 ^ 0x80000000) -
                            d_menu_item::_4395));
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xa88),
             (double)(float)((double)CONCAT44(0x43300000,-(int)unaff_r30 ^ 0x80000000) -
                            d_menu_item::_4395),
             (double)(float)((double)CONCAT44(0x43300000,-(int)unaff_r29 ^ 0x80000000) -
                            d_menu_item::_4395));
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xac0),
             (double)(float)((double)CONCAT44(0x43300000,(int)unaff_r30 ^ 0x80000000) -
                            d_menu_item::_4395),
             (double)(float)((double)CONCAT44(0x43300000,-(int)unaff_r29 ^ 0x80000000) -
                            d_menu_item::_4395));
  *(short *)(this + 0xa4e) = *(short *)(this + 0xa4e) + 1;
  if ((int)d_menu_item::g_miHIO.field_0x32 << 1 <= (int)*(short *)(this + 0xa4e)) {
    *(undefined2 *)(this + 0xa4e) = 0;
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  return;
}


/* __thiscall dMenu_Item_c::cursorMainMove(void) */

void __thiscall dMenu_Item_c::cursorMainMove(dMenu_Item_c *this)

{
  dMenu_Item_c dVar1;
  dMenu_Item_c dVar2;
  char cVar3;
  uint uVar4;
  
  STControl::checkTrigger(*(STControl **)(this + 0x2308));
  dVar1 = this[0x23ff];
  cVar3 = STControl::checkRightTrigger(*(STControl **)(this + 0x2308));
  if (cVar3 == '\0') {
    cVar3 = STControl::checkLeftTrigger(*(STControl **)(this + 0x2308));
    if (cVar3 != '\0') {
      dVar2 = this[0x23ff];
      uVar4 = (uint)(byte)dVar2;
      if (uVar4 != 0x15) {
        if (uVar4 == (uVar4 / 7) * 7) {
          this[0x23ff] = (dMenu_Item_c)((char)dVar2 + 6);
        }
        else {
          this[0x23ff] = (dMenu_Item_c)((char)dVar2 - 1);
        }
      }
    }
  }
  else {
    dVar2 = this[0x23ff];
    if ((byte)dVar2 != 0x15) {
      if ((uint)(byte)dVar2 % 7 == 6) {
        this[0x23ff] = (dMenu_Item_c)((char)dVar2 - 6);
      }
      else {
        this[0x23ff] = (dMenu_Item_c)((char)dVar2 + 1);
      }
    }
  }
  cVar3 = STControl::checkUpTrigger(*(STControl **)(this + 0x2308));
  if (cVar3 == '\0') {
    cVar3 = STControl::checkDownTrigger(*(STControl **)(this + 0x2308));
    if (cVar3 != '\0') {
      dVar2 = this[0x23ff];
      if (0xd < (byte)dVar2) {
        if ((0xd < (byte)dVar2) && ((byte)dVar2 < 0x15)) {
          this[0x23ff] = (dMenu_Item_c)0x15;
        }
      }
      else {
        this[0x23ff] = (dMenu_Item_c)((char)dVar2 + 7);
      }
    }
  }
  else {
    dVar2 = this[0x23ff];
    if (dVar2 == (dMenu_Item_c)0x15) {
      this[0x23ff] = (dMenu_Item_c)0xe;
    }
    else {
      if (6 < (byte)dVar2) {
        this[0x23ff] = (dMenu_Item_c)((char)dVar2 - 7);
      }
    }
  }
  if (this[0x23ff] != dVar1) {
    *(undefined2 *)(this + 0x88e) = 0;
    itemnameSet(this);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x80e,(cXyz *)0x0,0,0,d_menu_item::_4393,d_menu_item::_4393,
               d_menu_item::_4448,d_menu_item::_4448,0);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Item_c::cursorSubMove(void) */

void __thiscall dMenu_Item_c::cursorSubMove(dMenu_Item_c *this)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = (int)DAT_803e6aee;
  if (this[0x23ff] == (dMenu_Item_c)0xff) {
    uVar2 = 8;
  }
  else {
    uVar2 = (uint)(byte)((char)this[0x23ff] - (char)this[0x2400]);
  }
  STControl::checkTrigger(*(STControl **)(this + 0x2308));
  cVar1 = STControl::checkRightTrigger(*(STControl **)(this + 0x2308));
  if (cVar1 == '\0') {
    cVar1 = STControl::checkLeftTrigger(*(STControl **)(this + 0x2308));
    if ((cVar1 != '\0') && (uVar2 != (uVar2 / 3) * 3)) {
      uVar2 = uVar2 - 1;
    }
  }
  else {
    if (uVar2 % 3 != 2) {
      if ((int)uVar2 <= iVar3 + -1) {
        uVar2 = uVar2 + 1;
      }
    }
  }
  cVar1 = STControl::checkUpTrigger(*(STControl **)(this + 0x2308));
  if (cVar1 == '\0') {
    cVar1 = STControl::checkDownTrigger(*(STControl **)(this + 0x2308));
    if ((cVar1 != '\0') && ((int)(uVar2 + 3 & 0xff) <= iVar3)) {
      uVar2 = uVar2 + 3;
    }
  }
  else {
    if (2 < (uVar2 & 0xff)) {
      uVar2 = uVar2 - 3;
    }
  }
  if ((uVar2 & 0xff) != (uint)(byte)((char)this[0x23ff] - (char)this[0x2400])) {
    if ((uVar2 & 0xff) == 8) {
      if (this[0x23ff] != (dMenu_Item_c)0xff) {
        this[0x23ff] = (dMenu_Item_c)0xff;
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x80e,(cXyz *)0x0,0,0,d_menu_item::_4393,
                   d_menu_item::_4393,d_menu_item::_4448,d_menu_item::_4448,0);
      }
    }
    else {
      this[0x23ff] = (dMenu_Item_c)((char)uVar2 + (char)this[0x2400]);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x80e,(cXyz *)0x0,0,0,d_menu_item::_4393,d_menu_item::_4393,
                 d_menu_item::_4448,d_menu_item::_4448,0);
    }
    *(undefined2 *)(this + 0x88e) = 0;
    itemnameSet(this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMenu_Item_c::checkMove(void) */

void __thiscall dMenu_Item_c::checkMove(dMenu_Item_c *this)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  dMenu_Item_c *pdVar5;
  
  iVar4 = 0;
  iVar3 = 0;
  do {
    uVar2 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                        mInventorySlotIndexOnButton[iVar4];
    if (uVar2 == 0xff) {
      *(undefined *)(*(int *)(this + iVar3 + 0x2030) + 0xaa) = 0;
    }
    else {
      pdVar5 = this + iVar3;
      *(undefined *)(*(int *)(pdVar5 + 0x2030) + 0xaa) = 1;
      cVar1 = d_meter::dMeter_subWinFlag();
      if (cVar1 == '\0') {
        if (uVar2 < 0x30) {
          if (uVar2 < 0x24) {
            if (0x17 < uVar2) {
              uVar2 = f_op_msg_mng::fopMsgM_itemNum(0x24);
            }
          }
          else {
            uVar2 = f_op_msg_mng::fopMsgM_itemNum(0x2c);
          }
        }
        else {
          uVar2 = f_op_msg_mng::fopMsgM_itemNum(0x30);
        }
        *(undefined4 *)(pdVar5 + 0x204c) = *(undefined4 *)(this + (uVar2 & 0xff) * 0x38 + 0x166c);
        *(undefined4 *)(pdVar5 + 0x2050) = *(undefined4 *)(this + (uVar2 & 0xff) * 0x38 + 0x1670);
        J2DPane::insertChild
                  (*(J2DPane **)(this + 0x231c),*(J2DPane **)(this + 0x1f50),
                   *(J2DPane **)(pdVar5 + 0x2030));
      }
      else {
        if (uVar2 < 0x30) {
          if (uVar2 < 0x24) {
            if (uVar2 < 0x18) {
              *(undefined4 *)(pdVar5 + 0x204c) = *(undefined4 *)(this + uVar2 * 0x38 + 0x166c);
              *(undefined4 *)(pdVar5 + 0x2050) = *(undefined4 *)(this + uVar2 * 0x38 + 0x1670);
              J2DPane::insertChild
                        (*(J2DPane **)(this + 0x231c),*(J2DPane **)(this + 0x1f50),
                         *(J2DPane **)(pdVar5 + 0x2030));
            }
            else {
              if (this[0x2405] == (dMenu_Item_c)0x0) {
                *(undefined4 *)(pdVar5 + 0x204c) =
                     *(undefined4 *)(this + (uVar2 - 0x18 & 0xff) * 0x38 + 0xe94);
                *(undefined4 *)(pdVar5 + 0x2050) =
                     *(undefined4 *)(this + (uVar2 - 0x18 & 0xff) * 0x38 + 0xe98);
                J2DPane::insertChild
                          (*(J2DPane **)(this + 0x231c),*(J2DPane **)(this + 0x1230),
                           *(J2DPane **)(pdVar5 + 0x2030));
              }
              else {
                uVar2 = f_op_msg_mng::fopMsgM_itemNum(0x24);
                *(undefined4 *)(pdVar5 + 0x204c) =
                     *(undefined4 *)(this + (uVar2 & 0xff) * 0x38 + 0x166c);
                *(undefined4 *)(pdVar5 + 0x2050) =
                     *(undefined4 *)(this + (uVar2 & 0xff) * 0x38 + 0x1670);
                J2DPane::insertChild
                          (*(J2DPane **)(this + 0x231c),*(J2DPane **)(this + 0x1f50),
                           *(J2DPane **)(pdVar5 + 0x2030));
              }
            }
          }
          else {
            if (this[0x2405] == (dMenu_Item_c)0x1) {
              *(undefined4 *)(pdVar5 + 0x204c) =
                   *(undefined4 *)(this + (uVar2 - 0x24 & 0xff) * 0x38 + 0xe94);
              *(undefined4 *)(pdVar5 + 0x2050) =
                   *(undefined4 *)(this + (uVar2 - 0x24 & 0xff) * 0x38 + 0xe98);
              J2DPane::insertChild
                        (*(J2DPane **)(this + 0x231c),*(J2DPane **)(this + 0x1230),
                         *(J2DPane **)(pdVar5 + 0x2030));
            }
            else {
              uVar2 = f_op_msg_mng::fopMsgM_itemNum(0x2c);
              *(undefined4 *)(pdVar5 + 0x204c) =
                   *(undefined4 *)(this + (uVar2 & 0xff) * 0x38 + 0x166c);
              *(undefined4 *)(pdVar5 + 0x2050) =
                   *(undefined4 *)(this + (uVar2 & 0xff) * 0x38 + 0x1670);
              J2DPane::insertChild
                        (*(J2DPane **)(this + 0x231c),*(J2DPane **)(this + 0x1f50),
                         *(J2DPane **)(pdVar5 + 0x2030));
            }
          }
        }
        else {
          if (this[0x2405] == (dMenu_Item_c)0x2) {
            *(undefined4 *)(pdVar5 + 0x204c) =
                 *(undefined4 *)(this + (uVar2 - 0x30 & 0xff) * 0x38 + 0xe94);
            *(undefined4 *)(pdVar5 + 0x2050) =
                 *(undefined4 *)(this + (uVar2 - 0x30 & 0xff) * 0x38 + 0xe98);
            J2DPane::insertChild
                      (*(J2DPane **)(this + 0x231c),*(J2DPane **)(this + 0x1230),
                       *(J2DPane **)(pdVar5 + 0x2030));
          }
          else {
            uVar2 = f_op_msg_mng::fopMsgM_itemNum(0x30);
            *(undefined4 *)(pdVar5 + 0x204c) =
                 *(undefined4 *)(this + (uVar2 & 0xff) * 0x38 + 0x166c);
            *(undefined4 *)(pdVar5 + 0x2050) =
                 *(undefined4 *)(this + (uVar2 & 0xff) * 0x38 + 0x1670);
            J2DPane::insertChild
                      (*(J2DPane **)(this + 0x231c),*(J2DPane **)(this + 0x1f50),
                       *(J2DPane **)(pdVar5 + 0x2030));
          }
        }
      }
      *(undefined4 *)(pdVar5 + 0x2044) = *(undefined4 *)(pdVar5 + 0x204c);
      *(undefined4 *)(pdVar5 + 0x2048) = *(undefined4 *)(pdVar5 + 0x2050);
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar5 + 0x2030));
    }
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar4 < 3);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMenu_Item_c::itemplaceCheck(int) */

undefined4 __thiscall dMenu_Item_c::itemplaceCheck(dMenu_Item_c *this,int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == 3) {
    iVar2 = 0;
    iVar4 = 3;
    do {
      iVar3 = *(int *)((int)&d_menu_item::bag_4609 + iVar2);
      if (iVar3 < 0x15) {
        bVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                mStageName[iVar3];
      }
      else {
        if (iVar3 < 0x18) {
          bVar1 = 0xff;
        }
        else {
          if (iVar3 < 0x20) {
            bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [iVar3 + 0xd];
          }
          else {
            if (iVar3 < 0x24) {
              bVar1 = 0xff;
            }
            else {
              if (iVar3 < 0x2c) {
                bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [iVar3 + 9];
              }
              else {
                if (iVar3 < 0x30) {
                  bVar1 = 0xff;
                }
                else {
                  if (iVar3 < 0x38) {
                    bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [iVar3 + 5];
                  }
                  else {
                    bVar1 = 0xff;
                  }
                }
              }
            }
          }
        }
      }
      if (bVar1 != 0xff) {
        return 1;
      }
      iVar2 = iVar2 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  else {
    if (param_1 < 3) {
      if (param_1 == 1) {
        iVar2 = 0;
        iVar4 = 4;
        do {
          iVar3 = *(int *)((int)&d_menu_item::attack_4607 + iVar2);
          if (iVar3 < 0x15) {
            bVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                    mStageName[iVar3];
          }
          else {
            if (iVar3 < 0x18) {
              bVar1 = 0xff;
            }
            else {
              if (iVar3 < 0x20) {
                bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [iVar3 + 0xd];
              }
              else {
                if (iVar3 < 0x24) {
                  bVar1 = 0xff;
                }
                else {
                  if (iVar3 < 0x2c) {
                    bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [iVar3 + 9];
                  }
                  else {
                    if (iVar3 < 0x30) {
                      bVar1 = 0xff;
                    }
                    else {
                      if (iVar3 < 0x38) {
                        bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                mBits[iVar3 + 5];
                      }
                      else {
                        bVar1 = 0xff;
                      }
                    }
                  }
                }
              }
            }
          }
          if (bVar1 != 0xff) {
            return 1;
          }
          iVar2 = iVar2 + 4;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      else {
        if (param_1 < 1) {
          if (-1 < param_1) {
            iVar2 = 0;
            iVar4 = 4;
            do {
              iVar3 = *(int *)((int)&d_menu_item::event_4606 + iVar2);
              if (iVar3 < 0x15) {
                bVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                        mStageName[iVar3];
              }
              else {
                if (iVar3 < 0x18) {
                  bVar1 = 0xff;
                }
                else {
                  if (iVar3 < 0x20) {
                    bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [iVar3 + 0xd];
                  }
                  else {
                    if (iVar3 < 0x24) {
                      bVar1 = 0xff;
                    }
                    else {
                      if (iVar3 < 0x2c) {
                        bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                mBits[iVar3 + 9];
                      }
                      else {
                        if (iVar3 < 0x30) {
                          bVar1 = 0xff;
                        }
                        else {
                          if (iVar3 < 0x38) {
                            bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                    mGetItem.mBits[iVar3 + 5];
                          }
                          else {
                            bVar1 = 0xff;
                          }
                        }
                      }
                    }
                  }
                }
              }
              if (bVar1 != 0xff) {
                return 1;
              }
              iVar2 = iVar2 + 4;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
        }
        else {
          iVar2 = 0;
          iVar4 = 4;
          do {
            iVar3 = *(int *)((int)&d_menu_item::bottle_4608 + iVar2);
            if (iVar3 < 0x15) {
              bVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                      mStageName[iVar3];
            }
            else {
              if (iVar3 < 0x18) {
                bVar1 = 0xff;
              }
              else {
                if (iVar3 < 0x20) {
                  bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [iVar3 + 0xd];
                }
                else {
                  if (iVar3 < 0x24) {
                    bVar1 = 0xff;
                  }
                  else {
                    if (iVar3 < 0x2c) {
                      bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[iVar3 + 9];
                    }
                    else {
                      if (iVar3 < 0x30) {
                        bVar1 = 0xff;
                      }
                      else {
                        if (iVar3 < 0x38) {
                          bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                  mBits[iVar3 + 5];
                        }
                        else {
                          bVar1 = 0xff;
                        }
                      }
                    }
                  }
                }
              }
            }
            if (bVar1 != 0xff) {
              return 1;
            }
            iVar2 = iVar2 + 4;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
      }
    }
    else {
      if (param_1 == 5) {
        iVar2 = 0;
        iVar4 = 3;
        do {
          iVar3 = *(int *)((int)&d_menu_item::wepon2_4611 + iVar2);
          if (iVar3 < 0x15) {
            bVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                    mStageName[iVar3];
          }
          else {
            if (iVar3 < 0x18) {
              bVar1 = 0xff;
            }
            else {
              if (iVar3 < 0x20) {
                bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [iVar3 + 0xd];
              }
              else {
                if (iVar3 < 0x24) {
                  bVar1 = 0xff;
                }
                else {
                  if (iVar3 < 0x2c) {
                    bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [iVar3 + 9];
                  }
                  else {
                    if (iVar3 < 0x30) {
                      bVar1 = 0xff;
                    }
                    else {
                      if (iVar3 < 0x38) {
                        bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                mBits[iVar3 + 5];
                      }
                      else {
                        bVar1 = 0xff;
                      }
                    }
                  }
                }
              }
            }
          }
          if (bVar1 != 0xff) {
            return 1;
          }
          iVar2 = iVar2 + 4;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      else {
        if (param_1 < 5) {
          iVar2 = 0;
          iVar4 = 3;
          do {
            iVar3 = *(int *)((int)&d_menu_item::wepon1_4610 + iVar2);
            if (iVar3 < 0x15) {
              bVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                      mStageName[iVar3];
            }
            else {
              if (iVar3 < 0x18) {
                bVar1 = 0xff;
              }
              else {
                if (iVar3 < 0x20) {
                  bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [iVar3 + 0xd];
                }
                else {
                  if (iVar3 < 0x24) {
                    bVar1 = 0xff;
                  }
                  else {
                    if (iVar3 < 0x2c) {
                      bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[iVar3 + 9];
                    }
                    else {
                      if (iVar3 < 0x30) {
                        bVar1 = 0xff;
                      }
                      else {
                        if (iVar3 < 0x38) {
                          bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                  mBits[iVar3 + 5];
                        }
                        else {
                          bVar1 = 0xff;
                        }
                      }
                    }
                  }
                }
              }
            }
            if (bVar1 != 0xff) {
              return 1;
            }
            iVar2 = iVar2 + 4;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
      }
    }
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMenu_Item_c::itemDecide(void) */

void __thiscall dMenu_Item_c::itemDecide(dMenu_Item_c *this)

{
  dMenu_Item_c dVar1;
  dItem_data__ItemNo dVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  dMenu_Item_c unaff_r29;
  dMenu_Item_c unaff_r30;
  
  if ((byte)this[0x2404] != 3) {
    *(dMenu_Item_c *)
     (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mInventorySlotIndexOnButton
     + (byte)this[0x2404]) = this[0x2401];
    uVar6 = (uint)(byte)this[0x2404];
    uVar5 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                        mInventorySlotIndexOnButton[uVar6];
    if (uVar5 == 0xff) {
      d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar6] = InvalidItem;
    }
    else {
      if (uVar5 < 0x15) {
        dVar2 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                mStageName[uVar5];
      }
      else {
        if (uVar5 < 0x18) {
          dVar2 = InvalidItem;
        }
        else {
          if (uVar5 < 0x20) {
            dVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar5 + 0xd];
          }
          else {
            if (uVar5 < 0x24) {
              dVar2 = InvalidItem;
            }
            else {
              if (uVar5 < 0x2c) {
                dVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar5 + 9];
              }
              else {
                if (uVar5 < 0x30) {
                  dVar2 = InvalidItem;
                }
                else {
                  if (uVar5 < 0x38) {
                    dVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar5 + 5];
                  }
                  else {
                    dVar2 = InvalidItem;
                  }
                }
              }
            }
          }
        }
      }
      d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar6] = dVar2;
      uVar5 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                          mInventorySlotIndexOnButton[uVar6];
      if (uVar5 < 0x15) {
        bVar3 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                mStageName[uVar5];
      }
      else {
        if (uVar5 < 0x18) {
          bVar3 = 0xff;
        }
        else {
          if (uVar5 < 0x20) {
            bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar5 + 0xd];
          }
          else {
            if (uVar5 < 0x24) {
              bVar3 = 0xff;
            }
            else {
              if (uVar5 < 0x2c) {
                bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar5 + 9];
              }
              else {
                if (uVar5 < 0x30) {
                  bVar3 = 0xff;
                }
                else {
                  if (uVar5 < 0x38) {
                    bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar5 + 5];
                  }
                  else {
                    bVar3 = 0xff;
                  }
                }
              }
            }
          }
        }
      }
      if (bVar3 == 0xff) {
        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
        mInventorySlotIndexOnButton[uVar6] = -1;
      }
    }
    this[0x2404] = (dMenu_Item_c)0x3;
    if ((byte)this[0x2403] != 3) {
      *(dMenu_Item_c *)
       (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
        mInventorySlotIndexOnButton + (byte)this[0x2403]) = this[0x2402];
      uVar5 = (uint)(byte)this[0x2403];
      uVar6 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                          mInventorySlotIndexOnButton[uVar5];
      if (uVar6 == 0xff) {
        d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar5] = InvalidItem;
      }
      else {
        if (uVar6 < 0x15) {
          dVar2 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                  mStageName[uVar6];
        }
        else {
          if (uVar6 < 0x18) {
            dVar2 = InvalidItem;
          }
          else {
            if (uVar6 < 0x20) {
              dVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar6 + 0xd];
            }
            else {
              if (uVar6 < 0x24) {
                dVar2 = InvalidItem;
              }
              else {
                if (uVar6 < 0x2c) {
                  dVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar6 + 9];
                }
                else {
                  if (uVar6 < 0x30) {
                    dVar2 = InvalidItem;
                  }
                  else {
                    if (uVar6 < 0x38) {
                      dVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar6 + 5];
                    }
                    else {
                      dVar2 = InvalidItem;
                    }
                  }
                }
              }
            }
          }
        }
        d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar5] = dVar2;
        uVar6 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                            mInventorySlotIndexOnButton[uVar5];
        if (uVar6 < 0x15) {
          bVar3 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                  mStageName[uVar6];
        }
        else {
          if (uVar6 < 0x18) {
            bVar3 = 0xff;
          }
          else {
            if (uVar6 < 0x20) {
              bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar6 + 0xd];
            }
            else {
              if (uVar6 < 0x24) {
                bVar3 = 0xff;
              }
              else {
                if (uVar6 < 0x2c) {
                  bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar6 + 9];
                }
                else {
                  if (uVar6 < 0x30) {
                    bVar3 = 0xff;
                  }
                  else {
                    if (uVar6 < 0x38) {
                      bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar6 + 5];
                    }
                    else {
                      bVar3 = 0xff;
                    }
                  }
                }
              }
            }
          }
        }
        if (bVar3 == 0xff) {
          d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
          mInventorySlotIndexOnButton[uVar5] = -1;
        }
      }
      this[0x2403] = (dMenu_Item_c)0x3;
    }
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x817,(cXyz *)0x0,0,0,d_menu_item::_4393,d_menu_item::_4393,
               d_menu_item::_4448,d_menu_item::_4448,0);
  }
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 6 & 1) == 0) {
    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) == 0) {
      if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 3 & 1) != 0) {
        this[0x2404] = (dMenu_Item_c)0x2;
      }
    }
    else {
      this[0x2404] = (dMenu_Item_c)0x1;
    }
  }
  else {
    this[0x2404] = (dMenu_Item_c)0x0;
  }
  uVar5 = (uint)(byte)this[0x23ff];
  if (uVar5 < 0x15) {
    bVar3 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
            [uVar5];
  }
  else {
    if (uVar5 < 0x18) {
      bVar3 = 0xff;
    }
    else {
      if (uVar5 < 0x20) {
        bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar5 + 0xd]
        ;
      }
      else {
        if (uVar5 < 0x24) {
          bVar3 = 0xff;
        }
        else {
          if (uVar5 < 0x2c) {
            bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar5 + 9];
          }
          else {
            if (uVar5 < 0x30) {
              bVar3 = 0xff;
            }
            else {
              if (uVar5 < 0x38) {
                bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar5 + 5];
              }
              else {
                bVar3 = 0xff;
              }
            }
          }
        }
      }
    }
  }
  if (bVar3 == 0x24) {
    this[0x2405] = (dMenu_Item_c)0x0;
    subWindowInit(this);
    this[0x2404] = (dMenu_Item_c)0x3;
    this[0x2403] = (dMenu_Item_c)0x3;
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x84a,(cXyz *)0x0,0,0,d_menu_item::_4393,d_menu_item::_4393,
               d_menu_item::_4448,d_menu_item::_4448,0);
  }
  else {
    if (uVar5 < 0x15) {
      bVar3 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
              [uVar5];
    }
    else {
      if (uVar5 < 0x18) {
        bVar3 = 0xff;
      }
      else {
        if (uVar5 < 0x20) {
          bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                  [uVar5 + 0xd];
        }
        else {
          if (uVar5 < 0x24) {
            bVar3 = 0xff;
          }
          else {
            if (uVar5 < 0x2c) {
              bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar5 + 9];
            }
            else {
              if (uVar5 < 0x30) {
                bVar3 = 0xff;
              }
              else {
                if (uVar5 < 0x38) {
                  bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar5 + 5];
                }
                else {
                  bVar3 = 0xff;
                }
              }
            }
          }
        }
      }
    }
    if (bVar3 == 0x2c) {
      this[0x2405] = (dMenu_Item_c)0x1;
      subWindowInit(this);
      this[0x2404] = (dMenu_Item_c)0x3;
      this[0x2403] = (dMenu_Item_c)0x3;
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x84a,(cXyz *)0x0,0,0,d_menu_item::_4393,d_menu_item::_4393,
                 d_menu_item::_4448,d_menu_item::_4448,0);
    }
    else {
      if (uVar5 < 0x15) {
        bVar3 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                mStageName[uVar5];
      }
      else {
        if (uVar5 < 0x18) {
          bVar3 = 0xff;
        }
        else {
          if (uVar5 < 0x20) {
            bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar5 + 0xd];
          }
          else {
            if (uVar5 < 0x24) {
              bVar3 = 0xff;
            }
            else {
              if (uVar5 < 0x2c) {
                bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar5 + 9];
              }
              else {
                if (uVar5 < 0x30) {
                  bVar3 = 0xff;
                }
                else {
                  if (uVar5 < 0x38) {
                    bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar5 + 5];
                  }
                  else {
                    bVar3 = 0xff;
                  }
                }
              }
            }
          }
        }
      }
      if (bVar3 == 0x30) {
        this[0x2405] = (dMenu_Item_c)0x2;
        subWindowInit(this);
        this[0x2404] = (dMenu_Item_c)0x3;
        this[0x2403] = (dMenu_Item_c)0x3;
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x84a,(cXyz *)0x0,0,0,d_menu_item::_4393,
                   d_menu_item::_4393,d_menu_item::_4448,d_menu_item::_4448,0);
      }
      else {
        dVar1 = this[0x2404];
        if (dVar1 == (dMenu_Item_c)0x0) {
          unaff_r29 = (dMenu_Item_c)0x1;
          unaff_r30 = (dMenu_Item_c)0x2;
        }
        if (dVar1 == (dMenu_Item_c)0x1) {
          unaff_r29 = (dMenu_Item_c)0x2;
          unaff_r30 = (dMenu_Item_c)0x0;
        }
        else {
          if (dVar1 == (dMenu_Item_c)0x2) {
            unaff_r29 = (dMenu_Item_c)0x0;
            unaff_r30 = (dMenu_Item_c)0x1;
          }
        }
        if (uVar5 == (byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                           mInventorySlotIndexOnButton[(byte)unaff_r29]) {
          this[0x2403] = unaff_r29;
          this[0x2402] = *(dMenu_Item_c *)
                          (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                           mInventorySlotIndexOnButton + (byte)this[0x2404]);
          cVar4 = d_meter::dMeter_subWinFlag();
          if (cVar4 != '\0') {
            subWindowDelete(this);
          }
        }
        else {
          if (uVar5 == (byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                             mInventorySlotIndexOnButton[(byte)unaff_r30]) {
            this[0x2403] = unaff_r30;
            this[0x2402] = *(dMenu_Item_c *)
                            (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                             mInventorySlotIndexOnButton + (byte)this[0x2404]);
            cVar4 = d_meter::dMeter_subWinFlag();
            if (cVar4 != '\0') {
              subWindowDelete(this);
            }
          }
        }
        this[0x2401] = this[0x23ff];
        d_meter::dMeter_itemMoveSet(this + (uint)(byte)this[0x2401] * 0x38 + 0x1658,this[0x2404]);
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x84a,(cXyz *)0x0,0,0,d_menu_item::_4393,
                   d_menu_item::_4393,d_menu_item::_4448,d_menu_item::_4448,0);
      }
    }
  }
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMenu_Item_c::itemMove(void) */

void __thiscall dMenu_Item_c::itemMove(dMenu_Item_c *this)

{
  dItem_data__ItemNo dVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  
  cVar3 = d_meter::dMeter_itemMoveFlagCheck();
  if (cVar3 == '\x02') {
    *(dMenu_Item_c *)
     (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mInventorySlotIndexOnButton
     + (byte)this[0x2404]) = this[0x2401];
    uVar5 = (uint)(byte)this[0x2404];
    uVar4 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                        mInventorySlotIndexOnButton[uVar5];
    if (uVar4 == 0xff) {
      d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar5] = InvalidItem;
    }
    else {
      if (uVar4 < 0x15) {
        dVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                mStageName[uVar4];
      }
      else {
        if (uVar4 < 0x18) {
          dVar1 = InvalidItem;
        }
        else {
          if (uVar4 < 0x20) {
            dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar4 + 0xd];
          }
          else {
            if (uVar4 < 0x24) {
              dVar1 = InvalidItem;
            }
            else {
              if (uVar4 < 0x2c) {
                dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar4 + 9];
              }
              else {
                if (uVar4 < 0x30) {
                  dVar1 = InvalidItem;
                }
                else {
                  if (uVar4 < 0x38) {
                    dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar4 + 5];
                  }
                  else {
                    dVar1 = InvalidItem;
                  }
                }
              }
            }
          }
        }
      }
      d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar5] = dVar1;
      uVar4 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                          mInventorySlotIndexOnButton[uVar5];
      if (uVar4 < 0x15) {
        bVar2 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                mStageName[uVar4];
      }
      else {
        if (uVar4 < 0x18) {
          bVar2 = 0xff;
        }
        else {
          if (uVar4 < 0x20) {
            bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar4 + 0xd];
          }
          else {
            if (uVar4 < 0x24) {
              bVar2 = 0xff;
            }
            else {
              if (uVar4 < 0x2c) {
                bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar4 + 9];
              }
              else {
                if (uVar4 < 0x30) {
                  bVar2 = 0xff;
                }
                else {
                  if (uVar4 < 0x38) {
                    bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar4 + 5];
                  }
                  else {
                    bVar2 = 0xff;
                  }
                }
              }
            }
          }
        }
      }
      if (bVar2 == 0xff) {
        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
        mInventorySlotIndexOnButton[uVar5] = -1;
      }
    }
    this[0x2404] = (dMenu_Item_c)0x3;
    if ((byte)this[0x2403] != 3) {
      *(dMenu_Item_c *)
       (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
        mInventorySlotIndexOnButton + (byte)this[0x2403]) = this[0x2402];
      uVar4 = (uint)(byte)this[0x2403];
      uVar5 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                          mInventorySlotIndexOnButton[uVar4];
      if (uVar5 == 0xff) {
        d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar4] = InvalidItem;
      }
      else {
        if (uVar5 < 0x15) {
          dVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                  mStageName[uVar5];
        }
        else {
          if (uVar5 < 0x18) {
            dVar1 = InvalidItem;
          }
          else {
            if (uVar5 < 0x20) {
              dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar5 + 0xd];
            }
            else {
              if (uVar5 < 0x24) {
                dVar1 = InvalidItem;
              }
              else {
                if (uVar5 < 0x2c) {
                  dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar5 + 9];
                }
                else {
                  if (uVar5 < 0x30) {
                    dVar1 = InvalidItem;
                  }
                  else {
                    if (uVar5 < 0x38) {
                      dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar5 + 5];
                    }
                    else {
                      dVar1 = InvalidItem;
                    }
                  }
                }
              }
            }
          }
        }
        d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar4] = dVar1;
        uVar5 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                            mInventorySlotIndexOnButton[uVar4];
        if (uVar5 < 0x15) {
          bVar2 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                  mStageName[uVar5];
        }
        else {
          if (uVar5 < 0x18) {
            bVar2 = 0xff;
          }
          else {
            if (uVar5 < 0x20) {
              bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar5 + 0xd];
            }
            else {
              if (uVar5 < 0x24) {
                bVar2 = 0xff;
              }
              else {
                if (uVar5 < 0x2c) {
                  bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar5 + 9];
                }
                else {
                  if (uVar5 < 0x30) {
                    bVar2 = 0xff;
                  }
                  else {
                    if (uVar5 < 0x38) {
                      bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar5 + 5];
                    }
                    else {
                      bVar2 = 0xff;
                    }
                  }
                }
              }
            }
          }
        }
        if (bVar2 == 0xff) {
          d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
          mInventorySlotIndexOnButton[uVar4] = -1;
        }
      }
      this[0x2403] = (dMenu_Item_c)0x3;
    }
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x817,(cXyz *)0x0,0,0,d_menu_item::_4393,d_menu_item::_4393,
               d_menu_item::_4448,d_menu_item::_4448,0);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dMenu_Item_c::itemScale(void) */

void __thiscall dMenu_Item_c::itemScale(dMenu_Item_c *this)

{
  dMenu_Item_c dVar1;
  uint uVar2;
  dMenu_Item_c *pdVar3;
  uint uVar4;
  int iVar5;
  dMenu_Item_c *pdVar6;
  int iVar7;
  int iVar8;
  
  uVar2 = (uint)(byte)this[0x23ff];
  if (uVar2 == 0x15) {
    iVar5 = 0;
    iVar7 = 0;
    do {
      f_op_msg_mng::fopMsgM_paneScaleXY
                ((fopMsgM_pane_class *)(this + iVar7 + 0x1658),d_menu_item::_4393);
      f_op_msg_mng::fopMsgM_paneScaleXY
                ((fopMsgM_pane_class *)(this + iVar7 + 0x1af0),d_menu_item::_4393);
      iVar5 = iVar5 + 1;
      iVar7 = iVar7 + 0x38;
    } while (iVar5 < 0x15);
    iVar5 = 0;
    iVar7 = 0;
    do {
      f_op_msg_mng::fopMsgM_paneScaleXY
                ((fopMsgM_pane_class *)(this + iVar7 + 0xe78),d_menu_item::_4393);
      f_op_msg_mng::fopMsgM_paneScaleXY
                ((fopMsgM_pane_class *)(this + iVar7 + 0x1070),d_menu_item::_4393);
      iVar5 = iVar5 + 1;
      iVar7 = iVar7 + 0x38;
    } while (iVar5 < 8);
  }
  else {
    if (uVar2 < 0x30) {
      if (uVar2 < 0x24) {
        if (0x17 < uVar2) {
          uVar2 = 0x24;
        }
      }
      else {
        uVar2 = 0x2c;
      }
    }
    else {
      uVar2 = 0x30;
    }
    uVar4 = 0;
    iVar5 = 0;
    do {
      if ((uVar4 == uVar2) && (this[0x2404] == (dMenu_Item_c)0x3)) {
        pdVar6 = this + iVar5;
        f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(pdVar6 + 0x1658),DAT_803e6a74);
        f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(pdVar6 + 0x1af0),DAT_803e6a74);
        if (uVar2 == 0xc) {
          iVar7 = 0;
          iVar8 = 3;
          do {
            pdVar3 = this + iVar7;
            *(float *)(pdVar3 + 0x1fa4) =
                 *(float *)(pdVar6 + 0x1674) +
                 DAT_803e6a74 * (*(float *)(pdVar3 + 0x1f9c) - *(float *)(pdVar6 + 0x166c));
            *(float *)(pdVar3 + 0x1fa8) =
                 *(float *)(pdVar6 + 0x1678) +
                 DAT_803e6a74 * (*(float *)(pdVar3 + 0x1fa0) - *(float *)(pdVar6 + 0x1670));
            iVar7 = iVar7 + 0x38;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
      }
      else {
        f_op_msg_mng::fopMsgM_paneScaleXY
                  ((fopMsgM_pane_class *)(this + iVar5 + 0x1658),d_menu_item::_4393);
        f_op_msg_mng::fopMsgM_paneScaleXY
                  ((fopMsgM_pane_class *)(this + iVar5 + 0x1af0),d_menu_item::_4393);
      }
      uVar4 = uVar4 + 1;
      iVar5 = iVar5 + 0x38;
    } while ((int)uVar4 < 0x15);
    uVar2 = (uint)(byte)this[0x23ff];
    if (uVar2 == 0xff) {
      iVar5 = 0;
      iVar7 = 0;
      do {
        f_op_msg_mng::fopMsgM_paneScaleXY
                  ((fopMsgM_pane_class *)(this + iVar7 + 0xe78),d_menu_item::_4393);
        f_op_msg_mng::fopMsgM_paneScaleXY
                  ((fopMsgM_pane_class *)(this + iVar7 + 0x1070),d_menu_item::_4393);
        iVar5 = iVar5 + 1;
        iVar7 = iVar7 + 0x38;
      } while (iVar5 < 8);
    }
    else {
      if (0x14 < uVar2) {
        dVar1 = this[0x2400];
        iVar5 = 0;
        iVar7 = 0;
        do {
          if ((iVar5 == uVar2 - (byte)dVar1) && (this[0x2404] == (dMenu_Item_c)0x3)) {
            f_op_msg_mng::fopMsgM_paneScaleXY
                      ((fopMsgM_pane_class *)(this + iVar7 + 0xe78),DAT_803e6a74);
            f_op_msg_mng::fopMsgM_paneScaleXY
                      ((fopMsgM_pane_class *)(this + iVar7 + 0x1070),DAT_803e6a74);
          }
          else {
            f_op_msg_mng::fopMsgM_paneScaleXY
                      ((fopMsgM_pane_class *)(this + iVar7 + 0xe78),d_menu_item::_4393);
            f_op_msg_mng::fopMsgM_paneScaleXY
                      ((fopMsgM_pane_class *)(this + iVar7 + 0x1070),d_menu_item::_4393);
          }
          iVar5 = iVar5 + 1;
          iVar7 = iVar7 + 0x38;
        } while (iVar5 < 8);
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMenu_Item_c::subWindowInit(void) */

void __thiscall dMenu_Item_c::subWindowInit(dMenu_Item_c *this)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  dMenu_Item_c *pdVar6;
  int iVar7;
  
  d_meter::dMeter_subWinFlagOn();
  iVar7 = 0;
  *(undefined2 *)(this + 0x88e) = 0;
  if (this[0x2405] == (dMenu_Item_c)0x0) {
    this[0x2400] = (dMenu_Item_c)0x18;
    this[0x23ff] = this[0x2400];
    uVar5 = 0;
    iVar3 = 0;
    do {
      if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0[uVar5 & 0xff]
          == 0xff) {
        pdVar6 = this + iVar7;
        *(undefined2 *)(pdVar6 + 0xeae) = 0;
        *(undefined *)(*(int *)(pdVar6 + 0xe78) + 0xaa) = 0;
        *(undefined *)(*(int *)(pdVar6 + 0x1070) + 0xaa) = 0;
        *(undefined *)(*(int *)(pdVar6 + 0xcb8) + 0xaa) = 0;
        *(undefined *)(*(int *)(pdVar6 + 0xaf8) + 0xaa) = 0;
      }
      else {
        pdVar6 = this + iVar7;
        *(undefined2 *)(pdVar6 + 0xeae) = 1;
        iVar4 = iVar3 + 0x2394;
        JKRArchive::readTypeResource
                  (*(void **)(this + iVar4),0xc00,0x54494d47,
                   dItem_data::item_resource
                   [d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0
                    [uVar5 & 0xff]].mIconFilename,
                   d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
        os::DCStoreRangeNoSync(*(undefined4 *)(this + iVar4),0xc00);
        J2DPicture::changeTexture(*(J2DPicture **)(pdVar6 + 0xe78),*(ResTIMG **)(this + iVar4),'\0')
        ;
        J2DPicture::changeTexture
                  (*(J2DPicture **)(pdVar6 + 0x1070),*(ResTIMG **)(this + iVar4),'\0');
        *(undefined *)(*(int *)(pdVar6 + 0xe78) + 0xaa) = 1;
        *(undefined *)(*(int *)(pdVar6 + 0x1070) + 0xaa) = 1;
        *(undefined *)(*(int *)(pdVar6 + 0xcb8) + 0xaa) = 1;
        *(undefined *)(*(int *)(pdVar6 + 0xaf8) + 0xaa) = 1;
      }
      iVar4 = equipBeastItem(this,uVar5);
      bVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem)[1].field_0x0
              [iVar4 + 0xe];
      if (bVar1 == 0) {
        numberColor(this,*(J2DPane **)(this + iVar7 + 0xcb8),'\x02');
        numberColor(this,*(J2DPane **)(this + iVar7 + 0xaf8),'\x02');
      }
      else {
        if (bVar1 == 99) {
          numberColor(this,*(J2DPane **)(this + iVar7 + 0xcb8),'\x01');
          numberColor(this,*(J2DPane **)(this + iVar7 + 0xaf8),'\x01');
        }
        else {
          numberColor(this,*(J2DPane **)(this + iVar7 + 0xcb8),'\0');
          numberColor(this,*(J2DPane **)(this + iVar7 + 0xaf8),'\0');
        }
      }
      if (bVar1 < 10) {
        *(undefined *)(*(int *)(this + iVar7 + 0xcb8) + 0xaa) = 0;
      }
      else {
        numberSet(this,*(J2DPane **)(this + iVar7 + 0xcb8),bVar1 / 10);
      }
      numberSet(this,*(J2DPane **)(this + iVar7 + 0xaf8),bVar1 % 10);
      uVar5 = uVar5 + 1;
      iVar3 = iVar3 + 4;
      iVar7 = iVar7 + 0x38;
    } while ((int)uVar5 < 8);
  }
  else {
    if (this[0x2405] == (dMenu_Item_c)0x1) {
      this[0x2400] = (dMenu_Item_c)0x24;
      this[0x23ff] = (dMenu_Item_c)((char)this[0x2400] + '\x03');
      uVar5 = 0;
      iVar3 = 0;
      iVar7 = 0;
      do {
        pdVar6 = this + iVar7;
        *(undefined *)(*(int *)(pdVar6 + 0xcb8) + 0xaa) = 0;
        uVar2 = uVar5 & 0xff;
        if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0[uVar2 + 8]
            == 0xff) {
          *(undefined2 *)(pdVar6 + 0xeae) = 0;
          *(undefined *)(*(int *)(pdVar6 + 0xe78) + 0xaa) = 0;
          *(undefined *)(*(int *)(pdVar6 + 0x1070) + 0xaa) = 0;
          *(undefined *)(*(int *)(pdVar6 + 0xaf8) + 0xaa) = 0;
        }
        else {
          *(undefined2 *)(pdVar6 + 0xeae) = 1;
          iVar4 = iVar3 + 0x2394;
          JKRArchive::readTypeResource
                    (*(void **)(this + iVar4),0xc00,0x54494d47,
                     dItem_data::item_resource
                     [d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0
                      [uVar2 + 8]].mIconFilename,
                     d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
          os::DCStoreRangeNoSync(*(undefined4 *)(this + iVar4),0xc00);
          J2DPicture::changeTexture
                    (*(J2DPicture **)(pdVar6 + 0xe78),*(ResTIMG **)(this + iVar4),'\0');
          J2DPicture::changeTexture
                    (*(J2DPicture **)(pdVar6 + 0x1070),*(ResTIMG **)(this + iVar4),'\0');
          *(undefined *)(*(int *)(pdVar6 + 0xe78) + 0xaa) = 1;
          *(undefined *)(*(int *)(pdVar6 + 0x1070) + 0xaa) = 1;
          if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0[uVar2 + 8]
              == 0x82) {
            *(undefined *)(*(int *)(pdVar6 + 0xaf8) + 0xaa) = 1;
          }
          else {
            *(undefined *)(*(int *)(pdVar6 + 0xaf8) + 0xaa) = 0;
          }
        }
        bVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem)[1].field_0x0
                [uVar5 + 0x16];
        if (bVar1 == 0) {
          numberColor(this,*(J2DPane **)(pdVar6 + 0xcb8),'\x02');
          numberColor(this,*(J2DPane **)(pdVar6 + 0xaf8),'\x02');
        }
        else {
          if (bVar1 == 3) {
            numberColor(this,*(J2DPane **)(pdVar6 + 0xcb8),'\x01');
            numberColor(this,*(J2DPane **)(pdVar6 + 0xaf8),'\x01');
          }
          else {
            numberColor(this,*(J2DPane **)(pdVar6 + 0xcb8),'\0');
            numberColor(this,*(J2DPane **)(pdVar6 + 0xaf8),'\0');
          }
        }
        numberSet(this,*(J2DPane **)(pdVar6 + 0xaf8),bVar1 % 10);
        uVar5 = uVar5 + 1;
        iVar3 = iVar3 + 4;
        iVar7 = iVar7 + 0x38;
      } while ((int)uVar5 < 8);
    }
    else {
      this[0x2400] = (dMenu_Item_c)0x30;
      this[0x23ff] = (dMenu_Item_c)((char)this[0x2400] + '\x06');
      uVar5 = 0;
      iVar7 = 0;
      iVar3 = 0;
      do {
        pdVar6 = this + iVar3;
        *(undefined *)(*(int *)(pdVar6 + 0xcb8) + 0xaa) = 0;
        *(undefined *)(*(int *)(pdVar6 + 0xaf8) + 0xaa) = 0;
        if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0
            [(uVar5 & 0xff) + 0x10] == 0xff) {
          *(undefined2 *)(pdVar6 + 0xeae) = 0;
          *(undefined *)(*(int *)(pdVar6 + 0xe78) + 0xaa) = 0;
          *(undefined *)(*(int *)(pdVar6 + 0x1070) + 0xaa) = 0;
        }
        else {
          *(undefined2 *)(pdVar6 + 0xeae) = 1;
          iVar4 = iVar7 + 0x2394;
          JKRArchive::readTypeResource
                    (*(void **)(this + iVar4),0xc00,0x54494d47,
                     dItem_data::item_resource
                     [d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0
                      [(uVar5 & 0xff) + 0x10]].mIconFilename,
                     d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
          os::DCStoreRangeNoSync(*(undefined4 *)(this + iVar4),0xc00);
          J2DPicture::changeTexture
                    (*(J2DPicture **)(pdVar6 + 0xe78),*(ResTIMG **)(this + iVar4),'\0');
          J2DPicture::changeTexture
                    (*(J2DPicture **)(pdVar6 + 0x1070),*(ResTIMG **)(this + iVar4),'\0');
          *(undefined *)(*(int *)(pdVar6 + 0xe78) + 0xaa) = 1;
          *(undefined *)(*(int *)(pdVar6 + 0x1070) + 0xaa) = 1;
        }
        uVar5 = uVar5 + 1;
        iVar7 = iVar7 + 4;
        iVar3 = iVar3 + 0x38;
      } while ((int)uVar5 < 8);
    }
  }
  itemnameSet(this);
  iVar7 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneScaleXY
              ((fopMsgM_pane_class *)(this + iVar3 + 0xe78),d_menu_item::_4393);
    f_op_msg_mng::fopMsgM_paneScaleXY
              ((fopMsgM_pane_class *)(this + iVar3 + 0x1070),d_menu_item::_4393);
    iVar7 = iVar7 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar7 < 8);
  iVar7 = 0;
  iVar3 = 0;
  do {
    pdVar6 = this + iVar3;
    f_op_msg_mng::fopMsgM_setInitAlpha(pdVar6 + 0xaf8);
    f_op_msg_mng::fopMsgM_setInitAlpha(pdVar6 + 0xcb8);
    f_op_msg_mng::fopMsgM_setInitAlpha(pdVar6 + 0xe78);
    f_op_msg_mng::fopMsgM_setInitAlpha(pdVar6 + 0x1070);
    iVar7 = iVar7 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar7 < 8);
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x1038);
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x1230);
  iVar7 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_setInitAlpha(this + iVar3 + 0x1268);
    iVar7 = iVar7 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar7 < 9);
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x1460);
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x231c),*(J2DPane **)(this + 0xe40),*(J2DPane **)(this + 0xac0));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x231c),*(J2DPane **)(this + 0xac0),*(J2DPane **)(this + 0xa88));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x231c),*(J2DPane **)(this + 0xa88),*(J2DPane **)(this + 0xa50));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x231c),*(J2DPane **)(this + 0xa50),*(J2DPane **)(this + 0xa18));
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_Item_c::subWindowDelete(void) */

void __thiscall dMenu_Item_c::subWindowDelete(dMenu_Item_c *this)

{
  dMenu_Item_c dVar1;
  int iVar2;
  dMenu_Item_c *pdVar3;
  int iVar4;
  
  *(undefined2 *)(this + 0x88e) = 0;
  if (this[0x2405] == (dMenu_Item_c)0x0) {
    dVar1 = (dMenu_Item_c)f_op_msg_mng::fopMsgM_itemNum(0x24);
    this[0x23ff] = dVar1;
  }
  else {
    if (this[0x2405] == (dMenu_Item_c)0x1) {
      dVar1 = (dMenu_Item_c)f_op_msg_mng::fopMsgM_itemNum(0x2c);
      this[0x23ff] = dVar1;
    }
    else {
      dVar1 = (dMenu_Item_c)f_op_msg_mng::fopMsgM_itemNum(0x30);
      this[0x23ff] = dVar1;
    }
  }
  itemnameSet(this);
  itemScale(this);
  d_meter::dMeter_subWinFlagOff();
  iVar2 = 0;
  iVar4 = 0;
  do {
    pdVar3 = this + iVar4;
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar3 + 0xaf8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar3 + 0xcb8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar3 + 0xe78));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar3 + 0x1070));
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar2 < 8);
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1038));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1230));
  iVar2 = 0;
  iVar4 = 0;
  do {
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar4 + 0x1268));
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar2 < 9);
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1460));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x231c),*(J2DPane **)(this + 0x1460),*(J2DPane **)(this + 0xac0));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x231c),*(J2DPane **)(this + 0xac0),*(J2DPane **)(this + 0xa88));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x231c),*(J2DPane **)(this + 0xa88),*(J2DPane **)(this + 0xa50));
  J2DPane::insertChild
            (*(J2DPane **)(this + 0x231c),*(J2DPane **)(this + 0xa50),*(J2DPane **)(this + 0xa18));
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMenu_Item_c::subItemDecide(void) */

void __thiscall dMenu_Item_c::subItemDecide(dMenu_Item_c *this)

{
  dMenu_Item_c dVar1;
  dItem_data__ItemNo dVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  dMenu_Item_c unaff_r29;
  dMenu_Item_c unaff_r30;
  
  if ((byte)this[0x2404] != 3) {
    *(dMenu_Item_c *)
     (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mInventorySlotIndexOnButton
     + (byte)this[0x2404]) = this[0x2401];
    uVar6 = (uint)(byte)this[0x2404];
    uVar5 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                        mInventorySlotIndexOnButton[uVar6];
    if (uVar5 == 0xff) {
      d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar6] = InvalidItem;
    }
    else {
      if (uVar5 < 0x15) {
        dVar2 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                mStageName[uVar5];
      }
      else {
        if (uVar5 < 0x18) {
          dVar2 = InvalidItem;
        }
        else {
          if (uVar5 < 0x20) {
            dVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar5 + 0xd];
          }
          else {
            if (uVar5 < 0x24) {
              dVar2 = InvalidItem;
            }
            else {
              if (uVar5 < 0x2c) {
                dVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar5 + 9];
              }
              else {
                if (uVar5 < 0x30) {
                  dVar2 = InvalidItem;
                }
                else {
                  if (uVar5 < 0x38) {
                    dVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar5 + 5];
                  }
                  else {
                    dVar2 = InvalidItem;
                  }
                }
              }
            }
          }
        }
      }
      d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar6] = dVar2;
      uVar5 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                          mInventorySlotIndexOnButton[uVar6];
      if (uVar5 < 0x15) {
        bVar3 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                mStageName[uVar5];
      }
      else {
        if (uVar5 < 0x18) {
          bVar3 = 0xff;
        }
        else {
          if (uVar5 < 0x20) {
            bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar5 + 0xd];
          }
          else {
            if (uVar5 < 0x24) {
              bVar3 = 0xff;
            }
            else {
              if (uVar5 < 0x2c) {
                bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar5 + 9];
              }
              else {
                if (uVar5 < 0x30) {
                  bVar3 = 0xff;
                }
                else {
                  if (uVar5 < 0x38) {
                    bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar5 + 5];
                  }
                  else {
                    bVar3 = 0xff;
                  }
                }
              }
            }
          }
        }
      }
      if (bVar3 == 0xff) {
        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
        mInventorySlotIndexOnButton[uVar6] = -1;
      }
    }
    this[0x2404] = (dMenu_Item_c)0x3;
    if ((byte)this[0x2403] != 3) {
      *(dMenu_Item_c *)
       (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
        mInventorySlotIndexOnButton + (byte)this[0x2403]) = this[0x2402];
      uVar5 = (uint)(byte)this[0x2403];
      uVar6 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                          mInventorySlotIndexOnButton[uVar5];
      if (uVar6 == 0xff) {
        d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar5] = InvalidItem;
      }
      else {
        if (uVar6 < 0x15) {
          dVar2 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                  mStageName[uVar6];
        }
        else {
          if (uVar6 < 0x18) {
            dVar2 = InvalidItem;
          }
          else {
            if (uVar6 < 0x20) {
              dVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar6 + 0xd];
            }
            else {
              if (uVar6 < 0x24) {
                dVar2 = InvalidItem;
              }
              else {
                if (uVar6 < 0x2c) {
                  dVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar6 + 9];
                }
                else {
                  if (uVar6 < 0x30) {
                    dVar2 = InvalidItem;
                  }
                  else {
                    if (uVar6 < 0x38) {
                      dVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar6 + 5];
                    }
                    else {
                      dVar2 = InvalidItem;
                    }
                  }
                }
              }
            }
          }
        }
        d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar5] = dVar2;
        uVar6 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                            mInventorySlotIndexOnButton[uVar5];
        if (uVar6 < 0x15) {
          bVar3 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                  mStageName[uVar6];
        }
        else {
          if (uVar6 < 0x18) {
            bVar3 = 0xff;
          }
          else {
            if (uVar6 < 0x20) {
              bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar6 + 0xd];
            }
            else {
              if (uVar6 < 0x24) {
                bVar3 = 0xff;
              }
              else {
                if (uVar6 < 0x2c) {
                  bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar6 + 9];
                }
                else {
                  if (uVar6 < 0x30) {
                    bVar3 = 0xff;
                  }
                  else {
                    if (uVar6 < 0x38) {
                      bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar6 + 5];
                    }
                    else {
                      bVar3 = 0xff;
                    }
                  }
                }
              }
            }
          }
        }
        if (bVar3 == 0xff) {
          d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
          mInventorySlotIndexOnButton[uVar5] = -1;
        }
      }
      this[0x2403] = (dMenu_Item_c)0x3;
    }
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x817,(cXyz *)0x0,0,0,d_menu_item::_4393,d_menu_item::_4393,
               d_menu_item::_4448,d_menu_item::_4448,0);
  }
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 6 & 1) == 0) {
    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) == 0) {
      if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 3 & 1) != 0) {
        this[0x2404] = (dMenu_Item_c)0x2;
      }
    }
    else {
      this[0x2404] = (dMenu_Item_c)0x1;
    }
  }
  else {
    this[0x2404] = (dMenu_Item_c)0x0;
  }
  dVar1 = this[0x2404];
  if (dVar1 == (dMenu_Item_c)0x0) {
    unaff_r29 = (dMenu_Item_c)0x1;
    unaff_r30 = (dMenu_Item_c)0x2;
  }
  else {
    if (dVar1 == (dMenu_Item_c)0x1) {
      unaff_r29 = (dMenu_Item_c)0x2;
      unaff_r30 = (dMenu_Item_c)0x0;
    }
    else {
      if (dVar1 == (dMenu_Item_c)0x2) {
        unaff_r29 = (dMenu_Item_c)0x0;
        unaff_r30 = (dMenu_Item_c)0x1;
      }
    }
  }
  if (this[0x23ff] ==
      *(dMenu_Item_c *)
       (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
        mInventorySlotIndexOnButton + (byte)unaff_r29)) {
    this[0x2403] = unaff_r29;
    this[0x2402] = *(dMenu_Item_c *)
                    (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                     mInventorySlotIndexOnButton + (byte)this[0x2404]);
  }
  else {
    if (this[0x23ff] ==
        *(dMenu_Item_c *)
         (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
          mInventorySlotIndexOnButton + (byte)unaff_r30)) {
      this[0x2403] = unaff_r30;
      this[0x2402] = *(dMenu_Item_c *)
                      (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                       mInventorySlotIndexOnButton + (byte)this[0x2404]);
    }
  }
  this[0x2401] = this[0x23ff];
  d_meter::dMeter_itemMoveSet
            (this + ((uint)(byte)this[0x2401] - (uint)(byte)this[0x2400]) * 0x38 + 0xe78,
             this[0x2404]);
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,0x84a,(cXyz *)0x0,0,0,d_menu_item::_4393,d_menu_item::_4393,
             d_menu_item::_4448,d_menu_item::_4448,0);
  cVar4 = d_meter::dMeter_subWinFlag();
  if (cVar4 != '\0') {
    subWindowDelete(this);
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x801cb14c) */
/* __thiscall dMenu_Item_c::itemnameMove(void) */

void __thiscall dMenu_Item_c::itemnameMove(dMenu_Item_c *this)

{
  int iVar1;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  *(short *)(this + 0x88e) = *(short *)(this + 0x88e) + 1;
  if (0x82 < *(short *)(this + 0x88e)) {
    *(undefined2 *)(this + 0x88e) = 0xb;
  }
  iVar1 = (int)*(short *)(this + 0x88e);
  if (iVar1 < 0xb) {
    dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,iVar1,0);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x890),(float)dVar3);
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)(this + 0x8c8),(float)((double)d_menu_item::_4393 - dVar3));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x858));
  }
  else {
    if (iVar1 < 0x3d) {
      f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x890);
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x858));
    }
    else {
      if (iVar1 < 0x47) {
        dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,iVar1 + -0x3c,0);
        f_op_msg_mng::fopMsgM_setNowAlpha
                  ((fopMsgM_pane_class *)(this + 0x890),(float)((double)d_menu_item::_4393 - dVar3))
        ;
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x858),(float)dVar3);
      }
      else {
        if (iVar1 < 0x79) {
          f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x890));
          f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x858);
        }
        else {
          if (iVar1 < 0x83) {
            dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,iVar1 + -0x78,0);
            f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x890),(float)dVar3);
            f_op_msg_mng::fopMsgM_setNowAlpha
                      ((fopMsgM_pane_class *)(this + 0x858),
                       (float)((double)d_menu_item::_4393 - dVar3));
          }
        }
      }
    }
  }
  dDlst_2DOutFont_c::move(*(dDlst_2DOutFont_c **)(this + 0x230c));
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801cb798) */
/* WARNING: Removing unreachable block (ram,0x801cb7a0) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMenu_Item_c::itemnameSet(void) */

void __thiscall dMenu_Item_c::itemnameSet(dMenu_Item_c *this)

{
  dMenu_Item_c dVar1;
  undefined4 uVar2;
  float fVar3;
  bool bVar4;
  float fVar5;
  uint uVar6;
  ushort uVar7;
  int iVar8;
  byte bVar11;
  mesg_header *pmVar9;
  ushort *puVar10;
  ulong uVar12;
  byte *pbVar13;
  undefined4 uVar14;
  undefined8 in_f30;
  double dVar15;
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
  
  fVar5 = d_menu_item::_6598;
  uVar14 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,SUB84(in_f31,0),0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  local_5c = &fopMsgM_itemMsgGet_c::__vt;
  local_58 = 0;
  local_54 = 0;
  local_52 = 0;
  pbVar13 = (byte *)0x0;
  local_70 = d_menu_item::_6598;
  local_74 = d_menu_item::_6598;
  local_7c = d_menu_item::_6598;
  local_78 = d_menu_item::_6598;
  iVar8 = *(int *)(this + 0x858);
  fVar3 = d_menu_item::_4323;
  if (d_menu_item::_4323 < d_menu_item::_6598) {
    fVar3 = d_menu_item::_6598;
  }
  *(float *)(iVar8 + 0xe8) = fVar3;
  fVar3 = d_menu_item::_4323;
  if (d_menu_item::_4323 < fVar5) {
    fVar3 = fVar5;
  }
  *(float *)(iVar8 + 0xec) = fVar3;
  local_84 = *(float *)(*(int *)(this + 0x890) + 0xe8);
  local_80 = *(float *)(*(int *)(this + 0x890) + 0xec);
  iVar8 = *(int *)(this + 0x8c8);
  fVar3 = d_menu_item::_4323;
  if (d_menu_item::_4323 < local_84) {
    fVar3 = local_84;
  }
  *(float *)(iVar8 + 0xe8) = fVar3;
  fVar3 = d_menu_item::_4323;
  if (d_menu_item::_4323 < local_80) {
    fVar3 = local_80;
  }
  *(float *)(iVar8 + 0xec) = fVar3;
  *(undefined4 *)(*(int *)(this + 0x8c8) + 0xe0) = *(undefined4 *)(*(int *)(this + 0x890) + 0xe0);
  for (; pbVar13[*(int *)(this + 0x23e0)] != 0; pbVar13 = pbVar13 + 1) {
    pbVar13[*(int *)(this + 0x23e4)] = pbVar13[*(int *)(this + 0x23e0)];
  }
  pbVar13[*(int *)(this + 0x23e4)] = 0;
  local_64 = local_84;
  local_60 = local_80;
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x8c8),*(char **)(this + 0x23e4),(___)pbVar13);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x23e0),"");
  uVar6 = (uint)(byte)this[0x23ff];
  if (uVar6 == 0x15) {
    uVar12 = 0x1f8;
  }
  else {
    if (uVar6 < 0x15) {
      bVar11 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
               mStageName[uVar6];
    }
    else {
      if (uVar6 < 0x18) {
        bVar11 = 0xff;
      }
      else {
        if (uVar6 < 0x20) {
          bVar11 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                   [uVar6 + 0xd];
        }
        else {
          if (uVar6 < 0x24) {
            bVar11 = 0xff;
          }
          else {
            if (uVar6 < 0x2c) {
              bVar11 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                       [uVar6 + 9];
            }
            else {
              if (uVar6 < 0x30) {
                bVar11 = 0xff;
              }
              else {
                if (uVar6 < 0x38) {
                  bVar11 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                           [uVar6 + 5];
                }
                else {
                  bVar11 = 0xff;
                }
              }
            }
          }
        }
      }
    }
    if (bVar11 == 0xff) goto LAB_801cb798;
    if (uVar6 < 0x15) {
      uVar6 = (uint)(byte)(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)
                          [1].mStageName[uVar6];
    }
    else {
      if (uVar6 < 0x18) {
        uVar6 = 0xff;
      }
      else {
        if (uVar6 < 0x20) {
          uVar6 = (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar6 + 0xd];
        }
        else {
          if (uVar6 < 0x24) {
            uVar6 = 0xff;
          }
          else {
            if (uVar6 < 0x2c) {
              uVar6 = (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar6 + 9];
            }
            else {
              if (uVar6 < 0x30) {
                uVar6 = 0xff;
              }
              else {
                if (uVar6 < 0x38) {
                  uVar6 = (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                mBits[uVar6 + 5];
                }
                else {
                  uVar6 = 0xff;
                }
              }
            }
          }
        }
      }
    }
    uVar12 = SEXT24(dItem_data::item_resource[uVar6].mNameMessageId);
    if (uVar12 == 0) {
      uVar12 = 0x19c;
    }
  }
  pmVar9 = (mesg_header *)
           fopMsgM_itemMsgGet_c::getMesgHeader((fopMsgM_itemMsgGet_c *)&local_5c,uVar12);
  if (pmVar9 == (mesg_header *)0x0) {
    uVar12 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar12,"d_menu_item.cpp",0x565,"head_p");
    pbVar13 = &DAT_803604b1;
    m_Do_printf::OSPanic("d_menu_item.cpp",0x565);
  }
  local_6c = *(float *)(*(int *)(this + 0x890) + 0xec);
  local_68 = local_6c;
  puVar10 = (ushort *)fopMsgM_itemMsgGet_c::getMessage((fopMsgM_itemMsgGet_c *)&local_5c,pmVar9);
  bVar4 = false;
  uVar6 = (**(code **)(**(int **)(this + 0x2314) + 0x30))();
  local_50 = (double)CONCAT44(0x43300000,uVar6 ^ 0x80000000);
  dVar15 = (double)(local_68 / (float)(local_50 - d_menu_item::_4395));
  while (*(byte *)puVar10 != 0) {
    local_8e = 0;
    local_8f = 0;
    local_90 = 0;
    bVar11 = *(byte *)puVar10;
    uVar7 = (ushort)bVar11;
    if (uVar7 == 0x1a) {
      puVar10 = (ushort *)((byte *)((int)puVar10 + 1) + (char)*(byte *)((int)puVar10 + 1) + -1);
    }
    else {
      if ((bVar11 >> 4 == 8) || (bVar11 >> 4 == 9)) {
        local_90 = *(byte *)puVar10;
        local_8f = *(byte *)((int)puVar10 + 1);
        uVar7 = *puVar10;
        puVar10 = puVar10 + 1;
      }
      else {
        local_8f = 0;
        puVar10 = (ushort *)((int)puVar10 + 1);
        local_90 = bVar11;
      }
      local_8e = 0;
      pbVar13 = &bStack148;
      (**(code **)(**(int **)(this + 0x2314) + 0x2c))(*(int **)(this + 0x2314),uVar7);
      uVar6 = (uint)local_93;
      MSL_C.PPCEABI.bare.H::strcat(*(char **)(this + 0x23e0),(char *)&local_90);
      if (bVar4) {
        local_50 = (double)CONCAT44(0x43300000,uVar6 ^ 0x80000000);
        in_f31 = (double)(float)(in_f31 + (double)(float)((double)(float)(local_50 -
                                                                         d_menu_item::_4395) *
                                                         dVar15));
      }
      else {
        pbVar13 = local_98;
        (**(code **)(**(int **)(this + 0x2314) + 0x2c))(*(int **)(this + 0x2314),uVar7);
        local_50 = (double)CONCAT44(0x43300000,uVar6 + local_98[0] ^ 0x80000000);
        in_f31 = (double)(float)(dVar15 * (double)(float)(local_50 - d_menu_item::_4395));
        bVar4 = true;
      }
    }
  }
  iVar8 = *(int *)(this + 0x890);
  dVar15 = (double)(*(float *)(iVar8 + 0x14) - *(float *)(iVar8 + 0xc));
  if (dVar15 < in_f31) {
    uStack68 = (uint)((double)(float)((double)local_6c * dVar15) / in_f31);
    local_50 = (double)(longlong)(int)uStack68;
    uStack68 = uStack68 ^ 0x80000000;
    local_48 = 0x43300000;
    local_6c = (float)((double)CONCAT44(0x43300000,uStack68) - d_menu_item::_4395);
  }
  local_8c = local_6c;
  local_88 = local_68;
  fVar3 = d_menu_item::_4323;
  if (d_menu_item::_4323 < local_6c) {
    fVar3 = local_6c;
  }
  *(float *)(iVar8 + 0xe8) = fVar3;
  fVar3 = d_menu_item::_4323;
  if (d_menu_item::_4323 < local_68) {
    fVar3 = local_68;
  }
  *(float *)(iVar8 + 0xec) = fVar3;
  *(float *)(*(int *)(this + 0x890) + 0xe0) = d_menu_item::_4323;
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x890),*(char **)(this + 0x23e0),(___)pbVar13);
  dVar1 = this[0x23ff];
  if (dVar1 == (dMenu_Item_c)0x15) {
    dDlst_2DOutFont_c::messageSet(*(dDlst_2DOutFont_c **)(this + 0x230c),0x1fc);
  }
  else {
    if (((dVar1 == (dMenu_Item_c)0x4) || (dVar1 == (dMenu_Item_c)0xb)) ||
       (dVar1 == (dMenu_Item_c)0x12)) {
      dDlst_2DOutFont_c::messageSet(*(dDlst_2DOutFont_c **)(this + 0x230c),0x1f5);
    }
    else {
      dDlst_2DOutFont_c::messageSet(*(dDlst_2DOutFont_c **)(this + 0x230c),0x1f9);
    }
  }
  uVar2 = *(undefined4 *)(this + 0x868);
  iVar8 = *(int *)(this + 0x230c);
  *(undefined4 *)(iVar8 + 0x30) = *(undefined4 *)(this + 0x864);
  *(undefined4 *)(iVar8 + 0x34) = uVar2;
LAB_801cb798:
  __psq_l0(auStack8,uVar14);
  __psq_l1(auStack8,uVar14);
  __psq_l0(auStack24,uVar14);
  __psq_l1(auStack24,uVar14);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x801cbe9c) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall dMenu_Item_c::itemnoteSet(void) */

void __thiscall dMenu_Item_c::itemnoteSet(dMenu_Item_c *this)

{
  double dVar1;
  double dVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  byte bVar8;
  mesg_header *pmVar7;
  ulong uVar9;
  ___ _Var10;
  int iVar11;
  dMenu_Item_c *pdVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  undefined8 in_f31;
  double dVar17;
  undefined1 *local_348;
  undefined4 local_344;
  undefined2 local_340;
  undefined2 local_33e;
  undefined4 local_33c;
  undefined2 local_338;
  undefined2 local_336;
  undefined2 local_334;
  undefined2 local_332;
  undefined local_330;
  undefined local_32f;
  undefined local_32e;
  undefined local_32d;
  undefined local_32c;
  undefined local_32b;
  undefined local_32a;
  undefined local_329;
  undefined local_328;
  undefined local_327;
  undefined local_326;
  undefined local_325;
  undefined4 local_324;
  undefined2 local_320;
  undefined2 local_31e;
  undefined2 local_31c;
  undefined2 local_31a;
  undefined local_318;
  undefined local_317;
  undefined local_316;
  undefined local_315;
  undefined local_314;
  undefined local_313;
  undefined local_312;
  undefined local_311;
  undefined local_310;
  undefined local_30f;
  undefined local_30e;
  undefined local_30d;
  undefined auStack780 [8];
  undefined4 local_304;
  undefined4 *local_300;
  undefined4 local_2d0;
  undefined4 local_2cc;
  undefined4 local_2c8;
  undefined4 local_2c4;
  ___ local_2c0;
  undefined4 local_2ac;
  undefined4 local_2a8;
  undefined4 local_2a4;
  ___ local_2a0;
  int local_1f0;
  int local_1ec;
  int local_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  int local_1c8;
  int local_1c0;
  undefined4 local_1b0;
  undefined4 local_1ac;
  uint local_1a4 [15];
  int local_168 [31];
  int local_ec [24];
  byte abStack139 [24];
  undefined local_73;
  undefined local_70;
  double local_68;
  double local_60;
  double local_58;
  longlong local_50;
  double local_48;
  undefined4 local_40;
  uint uStack60;
  double local_38;
  undefined auStack8 [8];
  
  uVar16 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  local_348 = &fopMsgM_itemMsgGet_c::__vt;
  local_344 = 0;
  local_340 = 0;
  local_33e = 0;
  fopMsgM_msgDataProc_c::fopMsgM_msgDataProc_c((fopMsgM_msgDataProc_c *)auStack780);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x23e8),"");
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x23ec),"");
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x23f0),"");
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x23f4),"");
  outFontInit(this);
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ == '\0') {
    *(undefined *)(*(int *)(this + 0x740) + 0xaa) = 1;
  }
  else {
    *(undefined *)(*(int *)(this + 0x740) + 0xaa) = 0;
  }
  dVar17 = (double)*(float *)(*(int *)(this + 0x740) + 0xe8);
  local_68 = (double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U);
  dVar1 = local_68 - d_menu_item::_4395;
  fVar3 = (float)dVar1;
  local_60 = (double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U);
  dVar2 = local_60 - d_menu_item::_4395;
  iVar6 = *(int *)(this + 0x778);
  fVar4 = d_menu_item::_4323;
  if (d_menu_item::_4323 < fVar3) {
    fVar4 = fVar3;
  }
  *(float *)(iVar6 + 0xe8) = fVar4;
  fVar3 = d_menu_item::_4323;
  if (d_menu_item::_4323 < (float)dVar2) {
    fVar3 = (float)dVar2;
  }
  *(float *)(iVar6 + 0xec) = fVar3;
  local_58 = (double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000);
  *(float *)(*(int *)(this + 0x778) + 0xe4) = (float)(local_58 - d_menu_item::_4395);
  uVar5 = (uint)(byte)this[0x23ff];
  if (uVar5 < 0x15) {
    bVar8 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
            [uVar5];
  }
  else {
    if (uVar5 < 0x18) {
      bVar8 = 0xff;
    }
    else {
      if (uVar5 < 0x20) {
        bVar8 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar5 + 0xd]
        ;
      }
      else {
        if (uVar5 < 0x24) {
          bVar8 = 0xff;
        }
        else {
          if (uVar5 < 0x2c) {
            bVar8 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar5 + 9];
          }
          else {
            if (uVar5 < 0x30) {
              bVar8 = 0xff;
            }
            else {
              if (uVar5 < 0x38) {
                bVar8 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar5 + 5];
              }
              else {
                bVar8 = 0xff;
              }
            }
          }
        }
      }
    }
  }
  if (bVar8 == 0xff) {
    fopMsgM_msgDataProc_c::_fopMsgM_msgDataProc_c((fopMsgM_msgDataProc_c *)auStack780);
  }
  else {
    if (uVar5 < 0x15) {
      uVar5 = (uint)(byte)(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)
                          [1].mStageName[uVar5];
    }
    else {
      if (uVar5 < 0x18) {
        uVar5 = 0xff;
      }
      else {
        if (uVar5 < 0x20) {
          uVar5 = (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar5 + 0xd];
        }
        else {
          if (uVar5 < 0x24) {
            uVar5 = 0xff;
          }
          else {
            if (uVar5 < 0x2c) {
              uVar5 = (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar5 + 9];
            }
            else {
              if (uVar5 < 0x30) {
                uVar5 = 0xff;
              }
              else {
                if (uVar5 < 0x38) {
                  uVar5 = (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                mBits[uVar5 + 5];
                }
                else {
                  uVar5 = 0xff;
                }
              }
            }
          }
        }
      }
    }
    if (dItem_data::item_resource[uVar5].mNameMessageId == 0) {
      uVar9 = 0x264;
    }
    else {
      uVar9 = (int)dItem_data::item_resource[uVar5].mNameMessageId + 200;
    }
    pmVar7 = (mesg_header *)
             fopMsgM_itemMsgGet_c::getMesgHeader((fopMsgM_itemMsgGet_c *)&local_348,uVar9);
    if (pmVar7 == (mesg_header *)0x0) {
      uVar9 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar9,"d_menu_item.cpp",0x5f1,"head_p");
      m_Do_printf::OSPanic("d_menu_item.cpp",0x5f1,&DAT_803604b1);
    }
    local_2d0 = fopMsgM_itemMsgGet_c::getMessage((fopMsgM_itemMsgGet_c *)&local_348,pmVar7);
    fopMsgM_itemMsgGet_c::getMesgEntry((fopMsgM_itemMsgGet_c *)&local_33c,(mesg_header *)&local_348)
    ;
    local_324 = local_33c;
    local_320 = local_338;
    local_31e = local_336;
    local_31c = local_334;
    local_31a = local_332;
    local_318 = local_330;
    local_317 = local_32f;
    local_316 = local_32e;
    local_315 = local_32d;
    local_314 = local_32c;
    local_313 = local_32b;
    local_312 = local_32a;
    local_311 = local_329;
    local_310 = local_328;
    local_30f = local_327;
    local_30e = local_326;
    local_30d = local_325;
    fopMsgM_msgDataProc_c::dataInit((fopMsgM_msgDataProc_c *)auStack780);
    _Var10 = *(___ *)(this + 0x23f4);
    local_2c4 = *(undefined4 *)(this + 0x23f0);
    local_2c8 = *(undefined4 *)(this + 0x23ec);
    local_2cc = *(undefined4 *)(this + 0x23e8);
    auStack780._4_4_ = *(undefined4 *)(this + 0x2314);
    local_304 = *(undefined4 *)(this + 0x2318);
    local_1f0 = (int)*(float *)(*(int *)(this + 0x778) + 0xe0);
    local_58 = (double)(longlong)local_1f0;
    local_1e8 = (int)*(float *)(*(int *)(this + 0x740) + 0xe0);
    local_60 = (double)(longlong)local_1e8;
    local_1ec = (int)*(float *)(*(int *)(this + 0x778) + 0xe4);
    local_68 = (double)(longlong)local_1ec;
    local_300 = &local_324;
    local_1c8 = (int)dVar1;
    local_50 = (longlong)local_1c8;
    local_1c0 = (int)dVar17;
    local_48 = (double)(longlong)local_1c0;
    local_1e4 = 0x1fe;
    local_1e0 = 0x1e6;
    local_1ac = 2;
    local_1b0 = 0;
    local_73 = 1;
    local_70 = 0;
    local_2c0 = _Var10;
    local_2ac = local_2cc;
    local_2a8 = local_2c8;
    local_2a4 = local_2c4;
    local_2a0 = _Var10;
    fopMsgM_msgDataProc_c::stringLength((fopMsgM_msgDataProc_c *)auStack780);
    fopMsgM_msgDataProc_c::stringShift((fopMsgM_msgDataProc_c *)auStack780);
    fopMsgM_msgDataProc_c::iconIdxRefresh((fopMsgM_msgDataProc_c *)auStack780);
    fVar4 = d_menu_item::_4323;
    local_1dc = 0;
    uStack60 = 3U - (int)local_1dc._2_2_ ^ 0x80000000;
    local_40 = 0x43300000;
    fVar3 = (float)((double)CONCAT44(0x43300000,uStack60) - d_menu_item::_4395) *
            *(float *)(*(int *)(this + 0x778) + 0xe4) * d_menu_item::_4392;
    iVar6 = *(int *)(this + 0x740);
    *(float *)(iVar6 + 0xd8) = d_menu_item::_4323;
    *(float *)(iVar6 + 0xdc) = fVar3;
    iVar6 = *(int *)(this + 0x778);
    *(float *)(iVar6 + 0xd8) = fVar4;
    *(float *)(iVar6 + 0xdc) = fVar3;
    fopMsgM_msgDataProc_c::stringSet((fopMsgM_msgDataProc_c *)auStack780);
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x778),*(char **)(this + 0x23e8),_Var10);
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x740),*(char **)(this + 0x23ec),_Var10);
    iVar6 = (int)(*(float *)(*(int *)(this + 0x778) + 0xe4) * d_menu_item::_4392);
    local_38 = (double)(longlong)iVar6;
    iVar15 = 0;
    iVar14 = 0;
    iVar13 = 0;
    do {
      dVar1 = d_menu_item::_4395;
      uVar5 = (uint)abStack139[iVar15];
      iVar11 = *(int *)((int)local_ec + iVar13);
      if (iVar11 == -1) {
        iVar11 = 0xff;
      }
      if (((uVar5 != 0xff) && (pdVar12 = this + iVar14, *(short *)(pdVar12 + 0xe6) == -1)) &&
         (uVar5 != 0x16)) {
        local_38 = (double)CONCAT44(0x43300000,*(uint *)((int)local_1a4 + iVar13) ^ 0x80000000);
        *(float *)(pdVar12 + 0xbc) = (float)(local_38 - d_menu_item::_4395);
        uStack60 = iVar6 * ((3U - (int)local_1dc._2_2_) + *(int *)((int)local_168 + iVar13) * 2) ^
                   0x80000000;
        local_40 = 0x43300000;
        *(float *)(pdVar12 + 0xc0) = (float)((double)CONCAT44(0x43300000,uStack60) - dVar1);
        local_48 = (double)CONCAT44(0x43300000,uVar5);
        *(float *)(pdVar12 + 0xb8) = (float)(local_48 - d_menu_item::_6837);
        f_op_msg_mng::fopMsgM_outFontSet(*(undefined4 *)(pdVar12 + 0xb0),pdVar12 + 0xe6,iVar11);
      }
      iVar15 = iVar15 + 1;
      iVar14 = iVar14 + 0x38;
      iVar13 = iVar13 + 4;
    } while (iVar15 < 0xf);
    fopMsgM_msgDataProc_c::_fopMsgM_msgDataProc_c((fopMsgM_msgDataProc_c *)auStack780);
  }
  __psq_l0(auStack8,uVar16);
  __psq_l1(auStack8,uVar16);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801cbf24) */
/* __thiscall dMenu_Item_c::outFontInit(void) */

void __thiscall dMenu_Item_c::outFontInit(dMenu_Item_c *this)

{
  int *piVar1;
  int iVar2;
  dMenu_Item_c *pdVar3;
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
  dVar6 = (double)d_menu_item::_4323;
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
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Item_c::outFontMove(void) */

void __thiscall dMenu_Item_c::outFontMove(dMenu_Item_c *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  dMenu_Item_c *pdVar5;
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


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_Item_c::outFontDraw(void) */

void __thiscall dMenu_Item_c::outFontDraw(dMenu_Item_c *this)

{
  dMenu_Item_c *pdVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  do {
    pdVar1 = this + iVar3;
    if (*(short *)(pdVar1 + 0xe6) == -1) {
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar1 + 0xb0));
    }
    else {
      pdVar1[0xe5] = *(dMenu_Item_c *)(*(int *)(this + 0x778) + 0xac);
      f_op_msg_mng::fopMsgM_outFontDraw2
                (*(undefined4 *)(pdVar1 + 0xb0),*(undefined4 *)(pdVar1 + 0x3f8),
                 (int)*(float *)(pdVar1 + 0x404),(int)*(float *)(pdVar1 + 0x408),(int)DAT_803e6bb4,
                 (int)DAT_803e6bb4,pdVar1 + 0xe6,pdVar1[0xe5],(int)*(float *)(pdVar1 + 0xb8));
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar2 < 0xf);
  return;
}


/* __thiscall dMenu_Item_c::noteCheck(void) */

uint __thiscall dMenu_Item_c::noteCheck(dMenu_Item_c *this)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(1 - *(short *)(this + 0x81e));
  return uVar1 >> 5 & 0xff;
}


/* __thiscall dMenu_Item_c::noteInit(void) */

void __thiscall dMenu_Item_c::noteInit(dMenu_Item_c *this)

{
  double dVar1;
  float fVar2;
  int *piVar3;
  
  *(undefined2 *)(this + 0x81e) = 0;
  *(undefined2 *)(this + 0x7e6) = 0;
  dVar1 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x856) ^ 0x80000000) -
          d_menu_item::_4395;
  fVar2 = *(float *)(this + 0x848) * d_menu_item::_4392;
  piVar3 = *(int **)(this + 0x820);
  piVar3[0x27] = (int)(*(float *)(this + 0x844) * d_menu_item::_4392);
  piVar3[0x28] = (int)fVar2;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)(float)dVar1;
  (**(code **)(*piVar3 + 0x20))();
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x820),(double)d_menu_item::_4323,
             (double)d_menu_item::_4323);
  return;
}


/* __thiscall dMenu_Item_c::noteAppear(void) */

void __thiscall dMenu_Item_c::noteAppear(dMenu_Item_c *this)

{
  dMenu_Item_c dVar1;
  
  dVar1 = d_menu_item::g_miHIO._92_1_;
  if (*(short *)(this + 0x81e) == 1) {
    if ((int)(short)(d_menu_item::g_miHIO.field_0x38 + d_menu_item::g_miHIO.field_0x3a) <
        (int)*(short *)(this + 0x7e6)) {
      if ((short)(d_menu_item::g_miHIO.field_0x38 + d_menu_item::g_miHIO.field_0x3a) + 1 <
          (int)*(short *)(this + 0x7e6)) {
        noteClose(this);
      }
      else {
        this[0x9a5] = d_menu_item::g_miHIO._92_1_;
        this[0x9a4] = dVar1;
        if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) != 0) ||
           ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0')) {
          *(short *)(this + 0x7e6) = *(short *)(this + 0x7e6) + 1;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x816,(cXyz *)0x0,0,0,d_menu_item::_4393,
                     d_menu_item::_4393,d_menu_item::_4448,d_menu_item::_4448,0);
        }
      }
    }
    else {
      noteOpen(this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801cc4d0) */
/* WARNING: Removing unreachable block (ram,0x801cc4c8) */
/* WARNING: Removing unreachable block (ram,0x801cc4d8) */
/* __thiscall dMenu_Item_c::noteOpen(void) */

void __thiscall dMenu_Item_c::noteOpen(dMenu_Item_c *this)

{
  double dVar1;
  float fVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  double dVar8;
  undefined8 in_f29;
  double dVar9;
  undefined8 in_f30;
  double dVar10;
  undefined8 in_f31;
  double dVar11;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  iVar5 = (int)d_menu_item::g_miHIO.field_0x30;
  iVar6 = (int)(short)(d_menu_item::g_miHIO.field_0x38 + d_menu_item::g_miHIO.field_0x3a);
  dVar11 = (double)((float)((double)CONCAT44(0x43300000,
                                             (int)d_menu_item::g_miHIO.field_0x40 ^ 0x80000000) -
                           d_menu_item::_4395) - *(float *)(this + 0x834));
  dVar10 = (double)((float)((double)CONCAT44(0x43300000,
                                             (int)d_menu_item::g_miHIO.field_0x42 ^ 0x80000000) -
                           d_menu_item::_4395) - *(float *)(this + 0x838));
  dVar8 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar6,iVar6 - *(short *)(this + 0x7e6),0);
  dVar9 = (double)(float)((double)d_menu_item::_4393 - dVar8);
  if (*(short *)(this + 0x7e6) < iVar6) {
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)(this + 0x970),(float)((double)d_menu_item::_4393 - dVar8));
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x740),(float)dVar9);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x778),(float)dVar9);
  }
  else {
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x970);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x740);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x778);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x814,(cXyz *)0x0,0,0,d_menu_item::_4393,d_menu_item::_4393,
               d_menu_item::_4448,d_menu_item::_4448,0);
  }
  dVar8 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x856) ^ 0x80000000) -
          d_menu_item::_4395;
  dVar1 = (double)CONCAT44(0x43300000,iVar5 - *(short *)(this + 0x856) ^ 0x80000000) -
          d_menu_item::_4395;
  fVar2 = *(float *)(this + 0x850) * d_menu_item::_4392;
  piVar4 = *(int **)(this + 0x820);
  piVar4[0x27] = (int)(*(float *)(this + 0x84c) * d_menu_item::_4392);
  piVar4[0x28] = (int)fVar2;
  *(undefined *)(piVar4 + 0x2a) = 0x7a;
  piVar4[0x29] = (int)((float)dVar8 + (float)(dVar9 * (double)(float)dVar1));
  (**(code **)(*piVar4 + 0x20))();
  uVar3 = SEXT24(*(short *)(this + 0x7e6));
  if ((int)uVar3 < (int)d_menu_item::g_miHIO.field_0x38) {
    fVar2 = (d_menu_item::g_miHIO.field_0x8 *
            (float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - d_menu_item::_4395)) /
            (float)((double)CONCAT44(0x43300000,(int)d_menu_item::g_miHIO.field_0x38 ^ 0x80000000) -
                   d_menu_item::_4395);
  }
  else {
    dVar9 = (double)(d_menu_item::_4393 - d_menu_item::g_miHIO.field_0x8);
    dVar8 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                              ((int)d_menu_item::g_miHIO.field_0x3a,iVar6 - uVar3,0);
    fVar2 = d_menu_item::g_miHIO.field_0x8 +
            (float)(dVar9 * (double)(float)((double)d_menu_item::_4393 - dVar8));
  }
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x820),(double)(float)(dVar11 * (double)fVar2),
             (double)(float)(dVar10 * (double)fVar2));
  *(short *)(this + 0x7e6) = *(short *)(this + 0x7e6) + 1;
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  __psq_l0(auStack40,uVar7);
  __psq_l1(auStack40,uVar7);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801cc7ac) */
/* WARNING: Removing unreachable block (ram,0x801cc79c) */
/* WARNING: Removing unreachable block (ram,0x801cc794) */
/* WARNING: Removing unreachable block (ram,0x801cc7a4) */
/* WARNING: Removing unreachable block (ram,0x801cc7b4) */
/* __thiscall dMenu_Item_c::noteClose(void) */

void __thiscall dMenu_Item_c::noteClose(dMenu_Item_c *this)

{
  float fVar1;
  float fVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  int *piVar7;
  undefined4 uVar8;
  double dVar9;
  undefined8 in_f27;
  double dVar10;
  undefined8 in_f28;
  double dVar11;
  undefined8 in_f29;
  double dVar12;
  undefined8 in_f30;
  double dVar13;
  undefined8 in_f31;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  sVar5 = d_menu_item::g_miHIO.field_0x44;
  sVar4 = d_menu_item::g_miHIO.field_0x3c;
  sVar3 = d_menu_item::g_miHIO.field_0x30;
  uVar8 = 0;
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
  sVar6 = d_menu_item::g_miHIO.field_0x38 + d_menu_item::g_miHIO.field_0x3a;
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)d_menu_item::g_miHIO.field_0x40 ^ 0x80000000) -
                 d_menu_item::_4395);
  fVar2 = (float)((double)CONCAT44(0x43300000,(int)d_menu_item::g_miHIO.field_0x42 ^ 0x80000000) -
                 d_menu_item::_4395);
  dVar13 = (double)((d_menu_item::_6978 * fVar1 - *(float *)(this + 0x834)) - fVar1);
  dVar12 = (double)((d_menu_item::_6978 * fVar2 - *(float *)(this + 0x838)) - fVar2);
  dVar11 = (double)(fVar1 - *(float *)(this + 0x834));
  dVar10 = (double)(fVar2 - *(float *)(this + 0x838));
  dVar9 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                            ((int)d_menu_item::g_miHIO.field_0x3c,
                             (int)*(short *)(this + 0x7e6) - (sVar6 + 1),0);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x820),
             (double)(float)(dVar11 + (double)(float)(dVar13 * dVar9)),
             (double)(float)(dVar10 + (double)(float)(dVar12 * dVar9)));
  fVar1 = *(float *)(this + 0x850) * d_menu_item::_4392;
  piVar7 = *(int **)(this + 0x820);
  piVar7[0x27] = (int)(*(float *)(this + 0x84c) * d_menu_item::_4392);
  piVar7[0x28] = (int)fVar1;
  *(undefined *)(piVar7 + 0x2a) = 0x7a;
  piVar7[0x29] = (int)((float)((double)CONCAT44(0x43300000,(int)sVar3 ^ 0x80000000) -
                              d_menu_item::_4395) +
                      (float)(dVar9 * (double)(float)((double)CONCAT44(0x43300000,
                                                                       (int)sVar5 - (int)sVar3 ^
                                                                       0x80000000) -
                                                     d_menu_item::_4395)));
  (**(code **)(*piVar7 + 0x20))();
  *(short *)(this + 0x7e6) = *(short *)(this + 0x7e6) + 1;
  if ((short)(sVar6 + sVar4 + 1) < *(short *)(this + 0x7e6)) {
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x7b0);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x7e8);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x820);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x970));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x740));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x778));
    *(undefined2 *)(this + 0x81e) = 0;
    *(undefined2 *)(this + 0x7e6) = 0;
    dVar9 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x856) ^ 0x80000000) -
            d_menu_item::_4395;
    fVar1 = *(float *)(this + 0x850) * d_menu_item::_4392;
    piVar7 = *(int **)(this + 0x820);
    piVar7[0x27] = (int)(*(float *)(this + 0x84c) * d_menu_item::_4392);
    piVar7[0x28] = (int)fVar1;
    *(undefined *)(piVar7 + 0x2a) = 0x7a;
    piVar7[0x29] = (int)(float)dVar9;
    (**(code **)(*piVar7 + 0x20))();
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x820),(double)d_menu_item::_4323,
               (double)d_menu_item::_4323);
  }
  else {
    dVar10 = (double)(float)((double)d_menu_item::_4393 - dVar9);
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)(this + 0x7b0),(float)((double)d_menu_item::_4393 - dVar9));
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x7e8),(float)dVar10);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x820),(float)dVar10);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x970),(float)dVar10);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x740),(float)dVar10);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x778),(float)dVar10);
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  __psq_l0(auStack40,uVar8);
  __psq_l1(auStack40,uVar8);
  __psq_l0(auStack56,uVar8);
  __psq_l1(auStack56,uVar8);
  __psq_l0(auStack72,uVar8);
  __psq_l1(auStack72,uVar8);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_Item_c::mainTrans(float,
                                      float) */

void __thiscall dMenu_Item_c::mainTrans(dMenu_Item_c *this,float param_1,float param_2)

{
  int iVar1;
  int iVar2;
  double x;
  double y;
  
  y = (double)param_2;
  x = (double)param_1;
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x1498),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x14d0),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x1508),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x1540),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x1578),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x15b0),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x15e8),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x1620),x,y);
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar2 + 0x1658),x,y);
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar2 + 0x1af0),x,y);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 0x15);
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar2 + 0x1f88),x,y);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 3);
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar2 + 0x20d8),x,y);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 6);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x2228),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x2260),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x2298),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x22d0),x,y);
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar2 + 0xa18),x,y);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 4);
  iVar1 = 0;
  iVar2 = 0;
  do {
    if (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar1] != InvalidItem) {
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar2 + 0x2030),x,y);
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 3);
  return;
}


/* __thiscall dMenu_Item_c::titleTrans(float,
                                       float) */

void __thiscall dMenu_Item_c::titleTrans(dMenu_Item_c *this,float param_1,float param_2)

{
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x9e0),(double)param_1,(double)param_2);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801cca6c) */
/* __thiscall dMenu_Item_c::noteRotate(float,
                                       float) */

void __thiscall dMenu_Item_c::noteRotate(dMenu_Item_c *this,float param_1,float param_2)

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
            ((fopMsgM_pane_class *)(this + 0x820),(double)d_menu_item::_4323,(double)param_1);
  fVar1 = *(float *)(this + 0x850) * d_menu_item::_4392;
  piVar2 = *(int **)(this + 0x820);
  piVar2[0x27] = (int)(*(float *)(this + 0x84c) * d_menu_item::_4392);
  piVar2[0x28] = (int)fVar1;
  *(undefined *)(piVar2 + 0x2a) = 0x7a;
  piVar2[0x29] = (int)(float)dVar4;
  (**(code **)(*piVar2 + 0x20))();
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801ccb18) */
/* WARNING: Removing unreachable block (ram,0x801ccb20) */
/* __thiscall dMenu_Item_c::nameTrans(float,
                                      float) */

void __thiscall dMenu_Item_c::nameTrans(dMenu_Item_c *this,float param_1,float param_2)

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
  iVar2 = *(int *)(this + 0x230c);
  *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(this + 0x864);
  *(undefined4 *)(iVar2 + 0x34) = uVar1;
  dDlst_2DOutFont_c::move(*(dDlst_2DOutFont_c **)(this + 0x230c));
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x890),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x8c8),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x900),x,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x938),x,y);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x801ccd54) */
/* __thiscall dMenu_Item_c::mainOpenProc(short,
                                         short,
                                         short) */

void __thiscall
dMenu_Item_c::mainOpenProc(dMenu_Item_c *this,short param_1,short param_2,short param_3)

{
  char cVar1;
  dMenu_Item_c *pdVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar4 = (int)param_2;
  iVar3 = (int)param_1;
  if (iVar3 <= iVar4) {
    dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar4,iVar3,0);
    dVar7 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar4,iVar4 - iVar3,0);
    mainTrans(this,(float)((double)(float)((double)CONCAT44(0x43300000,(int)param_3 ^ 0x80000000) -
                                          d_menu_item::_4395) * dVar7),d_menu_item::_4323);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1498),(float)dVar6);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x14d0),(float)dVar6);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1508),(float)dVar6);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1540),(float)dVar6);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1578),(float)dVar6);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x15b0),(float)dVar6);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x15e8),(float)dVar6);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1620),(float)dVar6);
    iVar3 = 0;
    iVar4 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar4 + 0x1658),(float)dVar6);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar4 + 0x1af0),(float)dVar6);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x38;
    } while (iVar3 < 0x15);
    iVar3 = 0;
    iVar4 = 0;
    do {
      cVar1 = itemplaceCheck(this,iVar3);
      if (cVar1 != '\0') {
        f_op_msg_mng::fopMsgM_setNowAlpha
                  ((fopMsgM_pane_class *)(this + iVar4 + 0x20d8),(float)dVar6);
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x38;
    } while (iVar3 < 6);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2228),(float)dVar6);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2260),(float)dVar6);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2298),(float)dVar6);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x22d0),(float)dVar6);
    iVar3 = 0;
    iVar4 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar4 + 0xa18),(float)dVar6);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x38;
    } while (iVar3 < 4);
    iVar3 = 0;
    iVar4 = 0;
    do {
      pdVar2 = this + iVar4;
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0x1f88),(float)dVar6);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0x2030),(float)dVar6);
      if (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar3] == InvalidItem) {
        *(undefined *)(*(int *)(pdVar2 + 0x2030) + 0xaa) = 0;
      }
      else {
        *(undefined *)(*(int *)(pdVar2 + 0x2030) + 0xaa) = 1;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x38;
    } while (iVar3 < 3);
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMenu_Item_c::titleOpenProc(short,
                                          short) */

void __thiscall dMenu_Item_c::titleOpenProc(dMenu_Item_c *this,short param_1,short param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  
  sVar1 = d_menu_item::g_miHIO.field_0x28;
  iVar2 = (int)param_2;
  iVar3 = (int)param_1;
  if (iVar3 <= iVar2) {
    f_op_msg_mng::fopMsgM_valueIncrease(iVar2,iVar3,0);
    dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar2,iVar2 - iVar3,0);
    titleTrans(this,d_menu_item::_4323,
               (float)((double)(float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) -
                                      d_menu_item::_4395) * dVar4));
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x9a8);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x9e0);
    if (iVar3 == 1) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x811,(cXyz *)0x0,0,0,d_menu_item::_4393,d_menu_item::_4393,
                 d_menu_item::_4448,d_menu_item::_4448,0);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMenu_Item_c::noteOpenProc(short,
                                         short) */

void __thiscall dMenu_Item_c::noteOpenProc(dMenu_Item_c *this,short param_1,short param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  
  iVar2 = (int)d_menu_item::g_miHIO.field_0x2a;
  uVar1 = SEXT24(d_menu_item::g_miHIO.field_0x3e);
  iVar3 = (int)param_2;
  iVar4 = (int)param_1;
  if (iVar4 <= iVar3) {
    f_op_msg_mng::fopMsgM_valueIncrease(iVar3,iVar4,0);
    dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar3,iVar3 - iVar4,0);
    noteRotate(this,(float)((double)(float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) -
                                           d_menu_item::_4395) * dVar5),
               (float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x856) ^ 0x80000000) -
                      d_menu_item::_4395) +
               (float)(dVar5 * (double)(float)((double)CONCAT44(0x43300000,
                                                                iVar2 - *(short *)(this + 0x856) ^
                                                                0x80000000) - d_menu_item::_4395)));
    iVar2 = 0;
    do {
      f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x7b0);
      f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x7e8);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 6);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_Item_c::nameOpenProc(short,
                                         short) */

void __thiscall dMenu_Item_c::nameOpenProc(dMenu_Item_c *this,short param_1,short param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  
  sVar1 = d_menu_item::g_miHIO.field_0x2c;
  iVar2 = (int)param_2;
  iVar3 = (int)param_1;
  if (iVar3 <= iVar2) {
    f_op_msg_mng::fopMsgM_valueIncrease(iVar2,iVar3,0);
    dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar2,iVar2 - iVar3,0);
    nameTrans(this,d_menu_item::_4323,
              (float)((double)(float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) -
                                     d_menu_item::_4395) * dVar4));
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x890);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x900);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x938);
  }
  return;
}


/* __thiscall dMenu_Item_c::numberSet(J2DPane *,
                                      unsigned char) */

void __thiscall dMenu_Item_c::numberSet(dMenu_Item_c *this,J2DPane *param_1,uchar param_2)

{
  uint uVar1;
  
  uVar1 = (uint)param_2;
  if (9 < param_2) {
    uVar1 = 0;
  }
  J2DPicture::changeTexture((J2DPicture *)param_1,(&d_menu_item::number_7119)[uVar1],0);
  return;
}


/* __thiscall dMenu_Item_c::numberColor(J2DPane *,
                                        unsigned char) */

dMenu_Item_c * __thiscall
dMenu_Item_c::numberColor(dMenu_Item_c *this,J2DPane *param_1,uchar param_2)

{
  if (param_2 == '\x02') {
    *(undefined *)&param_1[1].mBox.mBR.y = 0xb4;
    *(undefined *)((int)&param_1[1].mBox.mBR.y + 1) = 0xb4;
    *(undefined *)((int)&param_1[1].mBox.mBR.y + 2) = 0xb4;
    *(undefined *)((int)&param_1[1].mBox.mBR.y + 3) = 0xff;
    this = (dMenu_Item_c *)0x1e1e0000;
    *(undefined *)param_1[1].mMtx.m = 0x1e;
    *(undefined *)((int)param_1[1].mMtx.m + 1) = 0x1e;
    *(undefined *)((int)param_1[1].mMtx.m + 2) = 0x1e;
    *(undefined *)((int)param_1[1].mMtx.m + 3) = 0;
  }
  else {
    if ((param_2 < 2) && (param_2 != '\0')) {
      *(undefined *)&param_1[1].mBox.mBR.y = 0xff;
      *(undefined *)((int)&param_1[1].mBox.mBR.y + 1) = 200;
      *(undefined *)((int)&param_1[1].mBox.mBR.y + 2) = 0x32;
      *(undefined *)((int)&param_1[1].mBox.mBR.y + 3) = 0xff;
      this = (dMenu_Item_c *)0x1e1e0000;
      *(undefined *)param_1[1].mMtx.m = 0x1e;
      *(undefined *)((int)param_1[1].mMtx.m + 1) = 0x1e;
      *(undefined *)((int)param_1[1].mMtx.m + 2) = 0x1e;
      *(undefined *)((int)param_1[1].mMtx.m + 3) = 0;
    }
    else {
      *(undefined *)&param_1[1].mBox.mBR.y = 0xff;
      *(undefined *)((int)&param_1[1].mBox.mBR.y + 1) = 0xff;
      *(undefined *)((int)&param_1[1].mBox.mBR.y + 2) = 0xff;
      *(undefined *)((int)&param_1[1].mBox.mBR.y + 3) = 0xff;
      *(undefined *)param_1[1].mMtx.m = 0;
      *(undefined *)((int)param_1[1].mMtx.m + 1) = 0;
      *(undefined *)((int)param_1[1].mMtx.m + 2) = 0;
      *(undefined *)((int)param_1[1].mMtx.m + 3) = 0;
    }
  }
  return this;
}


/* __thiscall dMenu_Item_c::itemNumberSet(void) */

void __thiscall dMenu_Item_c::itemNumberSet(dMenu_Item_c *this)

{
  numberSet(this,*(J2DPane **)(this + 0x1540),
            (uchar)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_);
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ ==
      (dMenu_Item_c)0x0) {
    numberColor(this,*(J2DPane **)(this + 0x1540),'\x02');
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ ==
        (dMenu_Item_c)0x3) {
      numberColor(this,*(J2DPane **)(this + 0x1540),'\x01');
    }
    else {
      numberColor(this,*(J2DPane **)(this + 0x1540),'\0');
    }
  }
  this[0x241e] = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_;
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_ ==
      (dMenu_Item_c)0x0) {
    numberColor(this,*(J2DPane **)(this + 0x1578),'\x02');
    numberColor(this,*(J2DPane **)(this + 0x15b0),'\x02');
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_ ==
        (dMenu_Item_c)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1) {
      numberColor(this,*(J2DPane **)(this + 0x1578),'\x01');
      numberColor(this,*(J2DPane **)(this + 0x15b0),'\x01');
    }
    else {
      numberColor(this,*(J2DPane **)(this + 0x1578),'\0');
      numberColor(this,*(J2DPane **)(this + 0x15b0),'\0');
    }
  }
  if ((byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_ < 10) {
    *(undefined *)(*(int *)(this + 0x15b0) + 0xaa) = 0;
  }
  else {
    numberSet(this,*(J2DPane **)(this + 0x15b0),
              (byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_ / 10)
    ;
  }
  numberSet(this,*(J2DPane **)(this + 0x1578),
            (byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_ % 10);
  this[0x241f] = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_;
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_ ==
      (dMenu_Item_c)0x0) {
    numberColor(this,*(J2DPane **)(this + 0x15e8),'\x02');
    numberColor(this,*(J2DPane **)(this + 0x1620),'\x02');
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_ ==
        (dMenu_Item_c)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2) {
      numberColor(this,*(J2DPane **)(this + 0x15e8),'\x01');
      numberColor(this,*(J2DPane **)(this + 0x1620),'\x01');
    }
    else {
      numberColor(this,*(J2DPane **)(this + 0x15e8),'\0');
      numberColor(this,*(J2DPane **)(this + 0x1620),'\0');
    }
  }
  if ((byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_ < 10) {
    *(undefined *)(*(int *)(this + 0x1620) + 0xaa) = 0;
  }
  else {
    numberSet(this,*(J2DPane **)(this + 0x1620),
              (byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_ / 10)
    ;
  }
  numberSet(this,*(J2DPane **)(this + 0x15e8),
            (byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_ % 10);
  this[0x2420] = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801cd870) */
/* WARNING: Removing unreachable block (ram,0x801cd878) */
/* WARNING: Removing unreachable block (ram,0x801cd840) */
/* WARNING: Removing unreachable block (ram,0x801cd848) */
/* WARNING: Removing unreachable block (ram,0x801cd810) */
/* WARNING: Removing unreachable block (ram,0x801cd818) */
/* WARNING: Removing unreachable block (ram,0x801cd7b4) */
/* WARNING: Removing unreachable block (ram,0x801cd784) */
/* WARNING: Removing unreachable block (ram,0x801cd78c) */
/* WARNING: Removing unreachable block (ram,0x801cd754) */
/* WARNING: Removing unreachable block (ram,0x801cd75c) */
/* WARNING: Removing unreachable block (ram,0x801cd724) */
/* WARNING: Removing unreachable block (ram,0x801cd72c) */
/* WARNING: Removing unreachable block (ram,0x801cd734) */
/* WARNING: Removing unreachable block (ram,0x801cd73c) */
/* WARNING: Removing unreachable block (ram,0x801cd764) */
/* WARNING: Removing unreachable block (ram,0x801cd76c) */
/* WARNING: Removing unreachable block (ram,0x801cd794) */
/* WARNING: Removing unreachable block (ram,0x801cd79c) */
/* WARNING: Removing unreachable block (ram,0x801cd800) */
/* WARNING: Removing unreachable block (ram,0x801cd808) */
/* WARNING: Removing unreachable block (ram,0x801cd830) */
/* WARNING: Removing unreachable block (ram,0x801cd838) */
/* WARNING: Removing unreachable block (ram,0x801cd860) */
/* WARNING: Removing unreachable block (ram,0x801cd868) */
/* WARNING: Removing unreachable block (ram,0x801cd890) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMenu_Item_c::itemCheck(int) */

void __thiscall dMenu_Item_c::itemCheck(dMenu_Item_c *this,int param_1)

{
  dMenu_Item_c dVar1;
  int iVar2;
  JPABaseEmitter *pJVar3;
  dMenu_Item_c *pdVar4;
  uint uVar5;
  dMenu_Item_c *pdVar6;
  dMenu_Item_c *pdVar7;
  cXyz local_28;
  
  if (param_1 < 0x15) {
    uVar5 = (uint)(byte)(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                        mStageName[param_1];
  }
  else {
    if (param_1 < 0x18) {
      uVar5 = 0xff;
    }
    else {
      if (param_1 < 0x20) {
        uVar5 = (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [param_1 + 0xd];
      }
      else {
        if (param_1 < 0x24) {
          uVar5 = 0xff;
        }
        else {
          if (param_1 < 0x2c) {
            uVar5 = (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [param_1 + 9];
          }
          else {
            if (param_1 < 0x30) {
              uVar5 = 0xff;
            }
            else {
              if (param_1 < 0x38) {
                uVar5 = (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[param_1 + 5];
              }
              else {
                uVar5 = 0xff;
              }
            }
          }
        }
      }
    }
  }
  if (uVar5 == 0xff) {
    *(undefined *)(*(int *)(this + param_1 * 0x38 + 0x1658) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + param_1 * 0x38 + 0x1af0) + 0xaa) = 0;
    if (param_1 == 8) {
      *(undefined *)(*(int *)(this + 0x1540) + 0xaa) = 0;
    }
    else {
      if (param_1 == 0xc) {
        *(undefined *)(*(int *)(this + 0x1578) + 0xaa) = 0;
        *(undefined *)(*(int *)(this + 0x15b0) + 0xaa) = 0;
      }
      else {
        if (param_1 == 0xd) {
          *(undefined *)(*(int *)(this + 0x15e8) + 0xaa) = 0;
          *(undefined *)(*(int *)(this + 0x1620) + 0xaa) = 0;
        }
      }
    }
  }
  else {
    iVar2 = recollectBossCheck(this);
    if ((iVar2 != 0) && (((uVar5 == 0x56 || (uVar5 == 0x58)) || (uVar5 == 0x59)))) {
      *(undefined *)(*(int *)(this + param_1 * 0x38 + 0x1658) + 0xaa) = 0;
      *(undefined *)(*(int *)(this + param_1 * 0x38 + 0x1af0) + 0xaa) = 0;
    }
    if (uVar5 == 0x35) {
      *(undefined *)(*(int *)(this + 0x1f88) + 0xaa) = 1;
      *(undefined *)(*(int *)(this + 0x1fc0) + 0xaa) = 1;
      *(undefined *)(*(int *)(this + 0x1ff8) + 0xaa) = 0;
      uVar5 = 0x27;
    }
    else {
      if (uVar5 == 0x36) {
        *(undefined *)(*(int *)(this + 0x1f88) + 0xaa) = 1;
        *(undefined *)(*(int *)(this + 0x1fc0) + 0xaa) = 1;
        *(undefined *)(*(int *)(this + 0x1ff8) + 0xaa) = 1;
        uVar5 = 0x27;
      }
      else {
        if ((uVar5 == 0x59) && (iVar2 = recollectBossCheck(this), iVar2 == 0)) {
          local_28.y = *(float *)(this + param_1 * 0x38 + 0x1678) - d_menu_item::_7631;
          local_28.x = *(float *)(this + param_1 * 0x38 + 0x1674) - d_menu_item::_7632;
          local_28.z = d_menu_item::_4323;
          if (*(int *)(this + 0x23b8) == 0) {
            pJVar3 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,9,
                                        0x2d,&local_28,(csXyz *)0x0,(cXyz *)0x0,0xff,
                                        (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0
                                        ,(cXyz *)0x0);
            *(JPABaseEmitter **)(this + 0x23b8) = pJVar3;
          }
          if (*(int *)(this + 0x23bc) == 0) {
            pJVar3 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,9,
                                        0x2d,&local_28,(csXyz *)0x0,(cXyz *)0x0,0xff,
                                        (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0
                                        ,(cXyz *)0x0);
            *(JPABaseEmitter **)(this + 0x23bc) = pJVar3;
          }
        }
      }
    }
    pdVar4 = this + param_1 * 4;
    JKRArchive::readTypeResource
              (*(void **)(pdVar4 + 0x2334),0xc00,0x54494d47,
               dItem_data::item_resource[uVar5].mIconFilename,
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
    os::DCStoreRangeNoSync(*(undefined4 *)(pdVar4 + 0x2334),0xc00);
    pdVar7 = this + param_1 * 0x38;
    J2DPicture::changeTexture(*(J2DPicture **)(pdVar7 + 0x1658),*(ResTIMG **)(pdVar4 + 0x2334),'\0')
    ;
    pdVar6 = this + param_1 * 0x38;
    J2DPicture::changeTexture(*(J2DPicture **)(pdVar6 + 0x1af0),*(ResTIMG **)(pdVar4 + 0x2334),'\0')
    ;
    if (param_1 == 8) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0x8 == PictoBox) {
        *(undefined *)(*(int *)(pdVar7 + 0x1658) + 0xaa) = 1;
        *(undefined *)(*(int *)(pdVar6 + 0x1af0) + 0xaa) = 1;
        *(undefined *)(*(int *)(this + 0x1540) + 0xaa) = 1;
      }
      else {
        if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0x8 ==
            DeluxePictoBox) {
          *(undefined *)(*(int *)(pdVar7 + 0x1658) + 0xaa) = 1;
          *(undefined *)(*(int *)(pdVar6 + 0x1af0) + 0xaa) = 1;
          *(undefined *)(*(int *)(this + 0x1540) + 0xaa) = 1;
        }
        else {
          *(undefined *)(*(int *)(pdVar7 + 0x1658) + 0xaa) = 0;
          *(undefined *)(*(int *)(pdVar6 + 0x1af0) + 0xaa) = 0;
          *(undefined *)(*(int *)(this + 0x1540) + 0xaa) = 0;
        }
      }
    }
    if (param_1 < 0x15) {
      dVar1 = *(dMenu_Item_c *)
               ((&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                mStageName + param_1);
    }
    else {
      if (param_1 < 0x18) {
        dVar1 = (dMenu_Item_c)0xff;
      }
      else {
        if (param_1 < 0x20) {
          dVar1 = *(dMenu_Item_c *)
                   (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits +
                   param_1 + 0xd);
        }
        else {
          if (param_1 < 0x24) {
            dVar1 = (dMenu_Item_c)0xff;
          }
          else {
            if (param_1 < 0x2c) {
              dVar1 = *(dMenu_Item_c *)
                       (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits +
                       param_1 + 9);
            }
            else {
              if (param_1 < 0x30) {
                dVar1 = (dMenu_Item_c)0xff;
              }
              else {
                if (param_1 < 0x38) {
                  dVar1 = *(dMenu_Item_c *)
                           (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                           + param_1 + 5);
                }
                else {
                  dVar1 = (dMenu_Item_c)0xff;
                }
              }
            }
          }
        }
      }
    }
    this[param_1 + 0x2406] = dVar1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMenu_Item_c::itemBitCheck(bool) */

void __thiscall dMenu_Item_c::itemBitCheck(dMenu_Item_c *this,bool param_1)

{
  dMenu_Item_c dVar1;
  dSv_player_item_c *pdVar2;
  int iVar3;
  
  iVar3 = 0;
  pdVar2 = &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem;
  do {
    if (iVar3 < 0x15) {
      dVar1 = *(dMenu_Item_c *)&pdVar2->mTelescopeSlot;
    }
    else {
      if (iVar3 < 0x18) {
        dVar1 = (dMenu_Item_c)0xff;
      }
      else {
        if (iVar3 < 0x20) {
          dVar1 = *(dMenu_Item_c *)
                   (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits +
                   iVar3 + 0xd);
        }
        else {
          if (iVar3 < 0x24) {
            dVar1 = (dMenu_Item_c)0xff;
          }
          else {
            if (iVar3 < 0x2c) {
              dVar1 = *(dMenu_Item_c *)
                       (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits +
                       iVar3 + 9);
            }
            else {
              if (iVar3 < 0x30) {
                dVar1 = (dMenu_Item_c)0xff;
              }
              else {
                if (iVar3 < 0x38) {
                  dVar1 = *(dMenu_Item_c *)
                           (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                           + iVar3 + 5);
                }
                else {
                  dVar1 = (dMenu_Item_c)0xff;
                }
              }
            }
          }
        }
      }
    }
    if ((this[iVar3 + 0x2406] != dVar1) || (param_1 != false)) {
      itemCheck(this,iVar3);
    }
    iVar3 = iVar3 + 1;
    pdVar2 = (dSv_player_item_c *)&pdVar2->field_0x1;
  } while (iVar3 < 0x15);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801cdc0c) */
/* WARNING: Removing unreachable block (ram,0x801cdc14) */
/* __thiscall dMenu_Item_c::arrowLightAnime(void) */

void __thiscall dMenu_Item_c::arrowLightAnime(dMenu_Item_c *this)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f30;
  double dVar5;
  undefined8 in_f31;
  longlong lVar6;
  double local_40;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  *(short *)(this + 0x1fbe) = *(short *)(this + 0x1fbe) + 1;
  if (0x77 < *(short *)(this + 0x1fbe)) {
    *(undefined2 *)(this + 0x1fbe) = 0;
  }
  iVar1 = (int)*(short *)(this + 0x1fbe);
  if (iVar1 < 0x3c) {
    dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x3c,iVar1,0);
  }
  else {
    dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x3c,0x78 - iVar1,0);
  }
  dVar5 = (double)(d_menu_item::_4393 - (float)((double)d_menu_item::_7818 * dVar4));
  local_40 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1fbc]);
  iVar1 = 0;
  iVar2 = 0;
  lVar6 = (longlong)
          (int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x1fbc]) - d_menu_item::_6837)
               - (float)((double)((float)(local_40 - d_menu_item::_6837) - d_menu_item::_7819) *
                        dVar4));
  do {
    f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(this + iVar2 + 0x1f88),(float)dVar5);
    (this + iVar2)[0x1fbd] = SUB81(lVar6,0);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 3);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMenu_Item_c::bottleFwaterCheck(void) */

int __thiscall dMenu_Item_c::bottleFwaterCheck(dMenu_Item_c *this)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = 4;
  while( true ) {
    iVar2 = iVar3 + 0xe;
    if (iVar2 < 0x15) {
      bVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[2].mStageName
              [iVar3 + 2];
    }
    else {
      if (iVar2 < 0x18) {
        bVar1 = 0xff;
      }
      else {
        if (iVar2 < 0x20) {
          bVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem)[1].mBits
                  [iVar3 + 6];
        }
        else {
          if (iVar2 < 0x24) {
            bVar1 = 0xff;
          }
          else {
            if (iVar2 < 0x2c) {
              bVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem)[1].mBits
                      [iVar3 + 2];
            }
            else {
              if (iVar2 < 0x30) {
                bVar1 = 0xff;
              }
              else {
                if (iVar2 < 0x38) {
                  bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [iVar3 + 0x13];
                }
                else {
                  bVar1 = 0xff;
                }
              }
            }
          }
        }
      }
    }
    if (bVar1 == 0x59) break;
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + -1;
    if (iVar4 == 0) {
      return 0;
    }
  }
  return iVar2;
}


/* __thiscall dMenu_Item_c::recollectBossCheck(void) */

undefined4 __thiscall dMenu_Item_c::recollectBossCheck(dMenu_Item_c *this)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                    (0x803c9d58);
  if (((*(uint *)(iVar1 + 0xc) >> 0x10 & 7) == 3) &&
     ((((iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                           (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss0"),
        iVar1 == 0 ||
        (iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                           (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss1"),
        iVar1 == 0)) ||
       (iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss2"),
       iVar1 == 0)) ||
      (iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                         (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss3"),
      iVar1 == 0)))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __thiscall dMenu_Item_c::cornerMove(void) */

void __thiscall dMenu_Item_c::cornerMove(dMenu_Item_c *this)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  float fVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  double dVar16;
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
  undefined4 local_20;
  uint uStack28;
  double local_18;
  
  local_1a0 = 0xffffffff;
  local_19c = 0xffffffff;
  local_198 = 0xffffffff;
  local_194 = 0xffffffff;
  local_1b4 = 0xffffffff;
  *(short *)(this + 0x23fa) = *(short *)(this + 0x23fa) + 1;
  if (0xef < *(short *)(this + 0x23fa)) {
    *(undefined2 *)(this + 0x23fa) = 0;
  }
  dVar16 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x3c,(int)*(short *)(this + 0x23fa) % 0x3c,2)
  ;
  sVar4 = *(short *)(this + 0x23fa);
  if (sVar4 < 0x3c) {
    uVar12 = (uint)(byte)this[0x2320];
    local_190 = (double)CONCAT44(0x43300000,uVar12);
    uVar10 = (uint)(byte)this[9000];
    uStack388 = uVar10 - uVar12 ^ 0x80000000;
    iVar9 = (int)((float)(local_190 - d_menu_item::_6837) +
                 (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack388) -
                                                 d_menu_item::_4395)));
    local_180 = (double)(longlong)iVar9;
    uVar13 = (uint)(byte)this[0x2321];
    local_178 = (double)CONCAT44(0x43300000,uVar13);
    uVar8 = (uint)(byte)this[0x2329];
    uStack364 = uVar8 - uVar13 ^ 0x80000000;
    iVar1 = (int)((float)(local_178 - d_menu_item::_6837) +
                 (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack364) -
                                                 d_menu_item::_4395)));
    local_168 = (double)(longlong)iVar1;
    uVar14 = (uint)(byte)this[0x2322];
    local_160 = (double)CONCAT44(0x43300000,uVar14);
    uVar7 = (uint)(byte)this[0x232a];
    uStack340 = uVar7 - uVar14 ^ 0x80000000;
    iVar2 = (int)((float)(local_160 - d_menu_item::_6837) +
                 (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack340) -
                                                 d_menu_item::_4395)));
    local_150 = (double)(longlong)iVar2;
    uVar15 = (uint)(byte)this[0x2323];
    local_148 = (double)CONCAT44(0x43300000,uVar15);
    uVar6 = (uint)(byte)this[0x232b];
    uStack316 = uVar6 - uVar15 ^ 0x80000000;
    uVar3 = (uint)((float)(local_148 - d_menu_item::_6837) +
                  (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack316) -
                                                  d_menu_item::_4395)));
    local_138 = (double)(longlong)(int)uVar3;
    local_1a0 = uVar3 & 0xff | (uint)CONCAT21(CONCAT11((char)iVar9,(char)iVar1),(char)iVar2) << 8;
    uVar11 = (uint)(byte)this[0x2324];
    local_130 = (double)CONCAT44(0x43300000,uVar11);
    uStack292 = uVar12 - uVar11 ^ 0x80000000;
    iVar9 = (int)((float)(local_130 - d_menu_item::_6837) +
                 (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack292) -
                                                 d_menu_item::_4395)));
    local_120 = (double)(longlong)iVar9;
    uVar12 = (uint)(byte)this[0x2325];
    local_118 = (double)CONCAT44(0x43300000,uVar12);
    uStack268 = uVar13 - uVar12 ^ 0x80000000;
    iVar1 = (int)((float)(local_118 - d_menu_item::_6837) +
                 (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack268) -
                                                 d_menu_item::_4395)));
    local_108 = (double)(longlong)iVar1;
    uVar13 = (uint)(byte)this[0x2326];
    local_100 = (double)CONCAT44(0x43300000,uVar13);
    uStack244 = uVar14 - uVar13 ^ 0x80000000;
    iVar2 = (int)((float)(local_100 - d_menu_item::_6837) +
                 (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack244) -
                                                 d_menu_item::_4395)));
    local_f0 = (double)(longlong)iVar2;
    uVar14 = (uint)(byte)this[8999];
    local_e8 = (double)CONCAT44(0x43300000,uVar14);
    uStack220 = uVar15 - uVar14 ^ 0x80000000;
    uVar3 = (uint)((float)(local_e8 - d_menu_item::_6837) +
                  (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack220) -
                                                  d_menu_item::_4395)));
    local_d8 = (double)(longlong)(int)uVar3;
    local_19c = uVar3 & 0xff | (uint)CONCAT21(CONCAT11((char)iVar9,(char)iVar1),(char)iVar2) << 8;
    local_d0 = (double)CONCAT44(0x43300000,uVar10);
    uVar15 = (uint)(byte)this[0x232c];
    uStack196 = uVar15 - uVar10 ^ 0x80000000;
    iVar9 = (int)((float)(local_d0 - d_menu_item::_6837) +
                 (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack196) -
                                                 d_menu_item::_4395)));
    local_c0 = (double)(longlong)iVar9;
    local_b8 = (double)CONCAT44(0x43300000,uVar8);
    uVar10 = (uint)(byte)this[0x232d];
    uStack172 = uVar10 - uVar8 ^ 0x80000000;
    iVar1 = (int)((float)(local_b8 - d_menu_item::_6837) +
                 (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack172) -
                                                 d_menu_item::_4395)));
    local_a8 = (double)(longlong)iVar1;
    local_a0 = (double)CONCAT44(0x43300000,uVar7);
    uVar8 = (uint)(byte)this[0x232e];
    uStack148 = uVar8 - uVar7 ^ 0x80000000;
    iVar2 = (int)((float)(local_a0 - d_menu_item::_6837) +
                 (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack148) -
                                                 d_menu_item::_4395)));
    local_90 = (double)(longlong)iVar2;
    local_88 = (double)CONCAT44(0x43300000,uVar6);
    uVar7 = (uint)(byte)this[0x232f];
    uStack124 = uVar7 - uVar6 ^ 0x80000000;
    uVar3 = (uint)((float)(local_88 - d_menu_item::_6837) +
                  (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack124) -
                                                  d_menu_item::_4395)));
    local_78 = (double)(longlong)(int)uVar3;
    local_198 = uVar3 & 0xff | (uint)CONCAT21(CONCAT11((char)iVar9,(char)iVar1),(char)iVar2) << 8;
    local_70 = (double)CONCAT44(0x43300000,uVar15);
    uStack100 = uVar11 - uVar15 ^ 0x80000000;
    iVar9 = (int)((float)(local_70 - d_menu_item::_6837) +
                 (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack100) -
                                                 d_menu_item::_4395)));
    local_60 = (double)(longlong)iVar9;
    local_58 = (double)CONCAT44(0x43300000,uVar10);
    uStack76 = uVar12 - uVar10 ^ 0x80000000;
    iVar1 = (int)((float)(local_58 - d_menu_item::_6837) +
                 (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack76) -
                                                 d_menu_item::_4395)));
    local_48 = (double)(longlong)iVar1;
    local_40 = (double)CONCAT44(0x43300000,uVar8);
    uStack52 = uVar13 - uVar8 ^ 0x80000000;
    iVar2 = (int)((float)(local_40 - d_menu_item::_6837) +
                 (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack52) -
                                                 d_menu_item::_4395)));
    local_30 = (double)(longlong)iVar2;
    local_28 = (double)CONCAT44(0x43300000,uVar7);
    uStack28 = uVar14 - uVar7 ^ 0x80000000;
    uVar3 = (uint)((float)(local_28 - d_menu_item::_6837) +
                  (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack28) -
                                                  d_menu_item::_4395)));
    local_18 = (double)(longlong)(int)uVar3;
    local_194 = uVar3 & 0xff | (uint)CONCAT21(CONCAT11((char)iVar9,(char)iVar1),(char)iVar2) << 8;
  }
  else {
    if (sVar4 < 0x78) {
      uVar12 = (uint)(byte)this[0x2320];
      local_18 = (double)CONCAT44(0x43300000,uVar12);
      uVar10 = (uint)(byte)this[9000];
      uStack28 = uVar10 - uVar12 ^ 0x80000000;
      iVar9 = (int)((float)(local_18 - d_menu_item::_6837) +
                   (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack28) -
                                                   d_menu_item::_4395)));
      local_28 = (double)(longlong)iVar9;
      uVar13 = (uint)(byte)this[0x2321];
      local_30 = (double)CONCAT44(0x43300000,uVar13);
      uVar8 = (uint)(byte)this[0x2329];
      uStack52 = uVar8 - uVar13 ^ 0x80000000;
      iVar1 = (int)((float)(local_30 - d_menu_item::_6837) +
                   (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack52) -
                                                   d_menu_item::_4395)));
      local_40 = (double)(longlong)iVar1;
      uVar14 = (uint)(byte)this[0x2322];
      local_48 = (double)CONCAT44(0x43300000,uVar14);
      uVar7 = (uint)(byte)this[0x232a];
      uStack76 = uVar7 - uVar14 ^ 0x80000000;
      iVar2 = (int)((float)(local_48 - d_menu_item::_6837) +
                   (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack76) -
                                                   d_menu_item::_4395)));
      local_58 = (double)(longlong)iVar2;
      uVar15 = (uint)(byte)this[0x2323];
      local_60 = (double)CONCAT44(0x43300000,uVar15);
      uVar6 = (uint)(byte)this[0x232b];
      uStack100 = uVar6 - uVar15 ^ 0x80000000;
      uVar3 = (uint)((float)(local_60 - d_menu_item::_6837) +
                    (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack100) -
                                                    d_menu_item::_4395)));
      local_70 = (double)(longlong)(int)uVar3;
      local_19c = uVar3 & 0xff | (uint)CONCAT21(CONCAT11((char)iVar9,(char)iVar1),(char)iVar2) << 8;
      uVar11 = (uint)(byte)this[0x2324];
      local_78 = (double)CONCAT44(0x43300000,uVar11);
      uStack124 = uVar12 - uVar11 ^ 0x80000000;
      iVar9 = (int)((float)(local_78 - d_menu_item::_6837) +
                   (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack124) -
                                                   d_menu_item::_4395)));
      local_88 = (double)(longlong)iVar9;
      uVar12 = (uint)(byte)this[0x2325];
      local_90 = (double)CONCAT44(0x43300000,uVar12);
      uStack148 = uVar13 - uVar12 ^ 0x80000000;
      iVar1 = (int)((float)(local_90 - d_menu_item::_6837) +
                   (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack148) -
                                                   d_menu_item::_4395)));
      local_a0 = (double)(longlong)iVar1;
      uVar13 = (uint)(byte)this[0x2326];
      local_a8 = (double)CONCAT44(0x43300000,uVar13);
      uStack172 = uVar14 - uVar13 ^ 0x80000000;
      iVar2 = (int)((float)(local_a8 - d_menu_item::_6837) +
                   (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack172) -
                                                   d_menu_item::_4395)));
      local_b8 = (double)(longlong)iVar2;
      uVar14 = (uint)(byte)this[8999];
      local_c0 = (double)CONCAT44(0x43300000,uVar14);
      uStack196 = uVar15 - uVar14 ^ 0x80000000;
      uVar3 = (uint)((float)(local_c0 - d_menu_item::_6837) +
                    (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack196) -
                                                    d_menu_item::_4395)));
      local_d0 = (double)(longlong)(int)uVar3;
      local_194 = uVar3 & 0xff | (uint)CONCAT21(CONCAT11((char)iVar9,(char)iVar1),(char)iVar2) << 8;
      local_d8 = (double)CONCAT44(0x43300000,uVar10);
      uVar15 = (uint)(byte)this[0x232c];
      uStack220 = uVar15 - uVar10 ^ 0x80000000;
      iVar9 = (int)((float)(local_d8 - d_menu_item::_6837) +
                   (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack220) -
                                                   d_menu_item::_4395)));
      local_e8 = (double)(longlong)iVar9;
      local_f0 = (double)CONCAT44(0x43300000,uVar8);
      uVar10 = (uint)(byte)this[0x232d];
      uStack244 = uVar10 - uVar8 ^ 0x80000000;
      iVar1 = (int)((float)(local_f0 - d_menu_item::_6837) +
                   (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack244) -
                                                   d_menu_item::_4395)));
      local_100 = (double)(longlong)iVar1;
      local_108 = (double)CONCAT44(0x43300000,uVar7);
      uVar8 = (uint)(byte)this[0x232e];
      uStack268 = uVar8 - uVar7 ^ 0x80000000;
      iVar2 = (int)((float)(local_108 - d_menu_item::_6837) +
                   (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack268) -
                                                   d_menu_item::_4395)));
      local_118 = (double)(longlong)iVar2;
      local_120 = (double)CONCAT44(0x43300000,uVar6);
      uVar7 = (uint)(byte)this[0x232f];
      uStack292 = uVar7 - uVar6 ^ 0x80000000;
      uVar3 = (uint)((float)(local_120 - d_menu_item::_6837) +
                    (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack292) -
                                                    d_menu_item::_4395)));
      local_130 = (double)(longlong)(int)uVar3;
      local_1a0 = uVar3 & 0xff | (uint)CONCAT21(CONCAT11((char)iVar9,(char)iVar1),(char)iVar2) << 8;
      local_138 = (double)CONCAT44(0x43300000,uVar15);
      uStack316 = uVar11 - uVar15 ^ 0x80000000;
      iVar9 = (int)((float)(local_138 - d_menu_item::_6837) +
                   (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack316) -
                                                   d_menu_item::_4395)));
      local_148 = (double)(longlong)iVar9;
      local_150 = (double)CONCAT44(0x43300000,uVar10);
      uStack340 = uVar12 - uVar10 ^ 0x80000000;
      iVar1 = (int)((float)(local_150 - d_menu_item::_6837) +
                   (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack340) -
                                                   d_menu_item::_4395)));
      local_160 = (double)(longlong)iVar1;
      local_168 = (double)CONCAT44(0x43300000,uVar8);
      uStack364 = uVar13 - uVar8 ^ 0x80000000;
      iVar2 = (int)((float)(local_168 - d_menu_item::_6837) +
                   (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack364) -
                                                   d_menu_item::_4395)));
      local_178 = (double)(longlong)iVar2;
      local_180 = (double)CONCAT44(0x43300000,uVar7);
      uStack388 = uVar14 - uVar7 ^ 0x80000000;
      uVar3 = (uint)((float)(local_180 - d_menu_item::_6837) +
                    (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack388) -
                                                    d_menu_item::_4395)));
      local_190 = (double)(longlong)(int)uVar3;
      local_198 = uVar3 & 0xff | (uint)CONCAT21(CONCAT11((char)iVar9,(char)iVar1),(char)iVar2) << 8;
    }
    else {
      if (sVar4 < 0xb4) {
        uVar12 = (uint)(byte)this[0x2320];
        local_18 = (double)CONCAT44(0x43300000,uVar12);
        uVar10 = (uint)(byte)this[9000];
        uStack28 = uVar10 - uVar12 ^ 0x80000000;
        iVar9 = (int)((float)(local_18 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack28) -
                                                     d_menu_item::_4395)));
        local_28 = (double)(longlong)iVar9;
        uVar13 = (uint)(byte)this[0x2321];
        local_30 = (double)CONCAT44(0x43300000,uVar13);
        uVar8 = (uint)(byte)this[0x2329];
        uStack52 = uVar8 - uVar13 ^ 0x80000000;
        iVar1 = (int)((float)(local_30 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack52) -
                                                     d_menu_item::_4395)));
        local_40 = (double)(longlong)iVar1;
        uVar14 = (uint)(byte)this[0x2322];
        local_48 = (double)CONCAT44(0x43300000,uVar14);
        uVar7 = (uint)(byte)this[0x232a];
        uStack76 = uVar7 - uVar14 ^ 0x80000000;
        iVar2 = (int)((float)(local_48 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack76) -
                                                     d_menu_item::_4395)));
        local_58 = (double)(longlong)iVar2;
        uVar15 = (uint)(byte)this[0x2323];
        local_60 = (double)CONCAT44(0x43300000,uVar15);
        uVar6 = (uint)(byte)this[0x232b];
        uStack100 = uVar6 - uVar15 ^ 0x80000000;
        uVar3 = (uint)((float)(local_60 - d_menu_item::_6837) +
                      (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack100) -
                                                      d_menu_item::_4395)));
        local_70 = (double)(longlong)(int)uVar3;
        local_194 = uVar3 & 0xff |
                    (uint)CONCAT21(CONCAT11((char)iVar9,(char)iVar1),(char)iVar2) << 8;
        uVar11 = (uint)(byte)this[0x2324];
        local_78 = (double)CONCAT44(0x43300000,uVar11);
        uStack124 = uVar12 - uVar11 ^ 0x80000000;
        iVar9 = (int)((float)(local_78 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack124) -
                                                     d_menu_item::_4395)));
        local_88 = (double)(longlong)iVar9;
        uVar12 = (uint)(byte)this[0x2325];
        local_90 = (double)CONCAT44(0x43300000,uVar12);
        uStack148 = uVar13 - uVar12 ^ 0x80000000;
        iVar1 = (int)((float)(local_90 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack148) -
                                                     d_menu_item::_4395)));
        local_a0 = (double)(longlong)iVar1;
        uVar13 = (uint)(byte)this[0x2326];
        local_a8 = (double)CONCAT44(0x43300000,uVar13);
        uStack172 = uVar14 - uVar13 ^ 0x80000000;
        iVar2 = (int)((float)(local_a8 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack172) -
                                                     d_menu_item::_4395)));
        local_b8 = (double)(longlong)iVar2;
        uVar14 = (uint)(byte)this[8999];
        local_c0 = (double)CONCAT44(0x43300000,uVar14);
        uStack196 = uVar15 - uVar14 ^ 0x80000000;
        uVar3 = (uint)((float)(local_c0 - d_menu_item::_6837) +
                      (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack196) -
                                                      d_menu_item::_4395)));
        local_d0 = (double)(longlong)(int)uVar3;
        local_198 = uVar3 & 0xff |
                    (uint)CONCAT21(CONCAT11((char)iVar9,(char)iVar1),(char)iVar2) << 8;
        local_d8 = (double)CONCAT44(0x43300000,uVar10);
        uVar15 = (uint)(byte)this[0x232c];
        uStack220 = uVar15 - uVar10 ^ 0x80000000;
        iVar9 = (int)((float)(local_d8 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack220) -
                                                     d_menu_item::_4395)));
        local_e8 = (double)(longlong)iVar9;
        local_f0 = (double)CONCAT44(0x43300000,uVar8);
        uVar10 = (uint)(byte)this[0x232d];
        uStack244 = uVar10 - uVar8 ^ 0x80000000;
        iVar1 = (int)((float)(local_f0 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack244) -
                                                     d_menu_item::_4395)));
        local_100 = (double)(longlong)iVar1;
        local_108 = (double)CONCAT44(0x43300000,uVar7);
        uVar8 = (uint)(byte)this[0x232e];
        uStack268 = uVar8 - uVar7 ^ 0x80000000;
        iVar2 = (int)((float)(local_108 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack268) -
                                                     d_menu_item::_4395)));
        local_118 = (double)(longlong)iVar2;
        local_120 = (double)CONCAT44(0x43300000,uVar6);
        uVar7 = (uint)(byte)this[0x232f];
        uStack292 = uVar7 - uVar6 ^ 0x80000000;
        uVar3 = (uint)((float)(local_120 - d_menu_item::_6837) +
                      (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack292) -
                                                      d_menu_item::_4395)));
        local_130 = (double)(longlong)(int)uVar3;
        local_19c = uVar3 & 0xff |
                    (uint)CONCAT21(CONCAT11((char)iVar9,(char)iVar1),(char)iVar2) << 8;
        local_138 = (double)CONCAT44(0x43300000,uVar15);
        uStack316 = uVar11 - uVar15 ^ 0x80000000;
        iVar9 = (int)((float)(local_138 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack316) -
                                                     d_menu_item::_4395)));
        local_148 = (double)(longlong)iVar9;
        local_150 = (double)CONCAT44(0x43300000,uVar10);
        uStack340 = uVar12 - uVar10 ^ 0x80000000;
        iVar1 = (int)((float)(local_150 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack340) -
                                                     d_menu_item::_4395)));
        local_160 = (double)(longlong)iVar1;
        local_168 = (double)CONCAT44(0x43300000,uVar8);
        uStack364 = uVar13 - uVar8 ^ 0x80000000;
        iVar2 = (int)((float)(local_168 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack364) -
                                                     d_menu_item::_4395)));
        local_178 = (double)(longlong)iVar2;
        local_180 = (double)CONCAT44(0x43300000,uVar7);
        uStack388 = uVar14 - uVar7 ^ 0x80000000;
        uVar3 = (uint)((float)(local_180 - d_menu_item::_6837) +
                      (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack388) -
                                                      d_menu_item::_4395)));
        local_190 = (double)(longlong)(int)uVar3;
        local_1a0 = uVar3 & 0xff |
                    (uint)CONCAT21(CONCAT11((char)iVar9,(char)iVar1),(char)iVar2) << 8;
      }
      else {
        uVar12 = (uint)(byte)this[0x2320];
        local_18 = (double)CONCAT44(0x43300000,uVar12);
        uVar10 = (uint)(byte)this[9000];
        uStack28 = uVar10 - uVar12 ^ 0x80000000;
        iVar9 = (int)((float)(local_18 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack28) -
                                                     d_menu_item::_4395)));
        local_28 = (double)(longlong)iVar9;
        uVar13 = (uint)(byte)this[0x2321];
        local_30 = (double)CONCAT44(0x43300000,uVar13);
        uVar8 = (uint)(byte)this[0x2329];
        uStack52 = uVar8 - uVar13 ^ 0x80000000;
        iVar1 = (int)((float)(local_30 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack52) -
                                                     d_menu_item::_4395)));
        local_40 = (double)(longlong)iVar1;
        uVar14 = (uint)(byte)this[0x2322];
        local_48 = (double)CONCAT44(0x43300000,uVar14);
        uVar7 = (uint)(byte)this[0x232a];
        uStack76 = uVar7 - uVar14 ^ 0x80000000;
        iVar2 = (int)((float)(local_48 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack76) -
                                                     d_menu_item::_4395)));
        local_58 = (double)(longlong)iVar2;
        uVar15 = (uint)(byte)this[0x2323];
        local_60 = (double)CONCAT44(0x43300000,uVar15);
        uVar6 = (uint)(byte)this[0x232b];
        uStack100 = uVar6 - uVar15 ^ 0x80000000;
        uVar3 = (uint)((float)(local_60 - d_menu_item::_6837) +
                      (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack100) -
                                                      d_menu_item::_4395)));
        local_70 = (double)(longlong)(int)uVar3;
        local_198 = uVar3 & 0xff |
                    (uint)CONCAT21(CONCAT11((char)iVar9,(char)iVar1),(char)iVar2) << 8;
        uVar11 = (uint)(byte)this[0x2324];
        local_78 = (double)CONCAT44(0x43300000,uVar11);
        uStack124 = uVar12 - uVar11 ^ 0x80000000;
        iVar9 = (int)((float)(local_78 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack124) -
                                                     d_menu_item::_4395)));
        local_88 = (double)(longlong)iVar9;
        uVar12 = (uint)(byte)this[0x2325];
        local_90 = (double)CONCAT44(0x43300000,uVar12);
        uStack148 = uVar13 - uVar12 ^ 0x80000000;
        iVar1 = (int)((float)(local_90 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack148) -
                                                     d_menu_item::_4395)));
        local_a0 = (double)(longlong)iVar1;
        uVar13 = (uint)(byte)this[0x2326];
        local_a8 = (double)CONCAT44(0x43300000,uVar13);
        uStack172 = uVar14 - uVar13 ^ 0x80000000;
        iVar2 = (int)((float)(local_a8 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack172) -
                                                     d_menu_item::_4395)));
        local_b8 = (double)(longlong)iVar2;
        uVar14 = (uint)(byte)this[8999];
        local_c0 = (double)CONCAT44(0x43300000,uVar14);
        uStack196 = uVar15 - uVar14 ^ 0x80000000;
        uVar3 = (uint)((float)(local_c0 - d_menu_item::_6837) +
                      (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack196) -
                                                      d_menu_item::_4395)));
        local_d0 = (double)(longlong)(int)uVar3;
        local_1a0 = uVar3 & 0xff |
                    (uint)CONCAT21(CONCAT11((char)iVar9,(char)iVar1),(char)iVar2) << 8;
        local_d8 = (double)CONCAT44(0x43300000,uVar10);
        uVar15 = (uint)(byte)this[0x232c];
        uStack220 = uVar15 - uVar10 ^ 0x80000000;
        iVar9 = (int)((float)(local_d8 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack220) -
                                                     d_menu_item::_4395)));
        local_e8 = (double)(longlong)iVar9;
        local_f0 = (double)CONCAT44(0x43300000,uVar8);
        uVar10 = (uint)(byte)this[0x232d];
        uStack244 = uVar10 - uVar8 ^ 0x80000000;
        iVar1 = (int)((float)(local_f0 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack244) -
                                                     d_menu_item::_4395)));
        local_100 = (double)(longlong)iVar1;
        local_108 = (double)CONCAT44(0x43300000,uVar7);
        uVar8 = (uint)(byte)this[0x232e];
        uStack268 = uVar8 - uVar7 ^ 0x80000000;
        iVar2 = (int)((float)(local_108 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack268) -
                                                     d_menu_item::_4395)));
        local_118 = (double)(longlong)iVar2;
        local_120 = (double)CONCAT44(0x43300000,uVar6);
        uVar7 = (uint)(byte)this[0x232f];
        uStack292 = uVar7 - uVar6 ^ 0x80000000;
        uVar3 = (uint)((float)(local_120 - d_menu_item::_6837) +
                      (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack292) -
                                                      d_menu_item::_4395)));
        local_130 = (double)(longlong)(int)uVar3;
        local_194 = uVar3 & 0xff |
                    (uint)CONCAT21(CONCAT11((char)iVar9,(char)iVar1),(char)iVar2) << 8;
        local_138 = (double)CONCAT44(0x43300000,uVar15);
        uStack316 = uVar11 - uVar15 ^ 0x80000000;
        iVar9 = (int)((float)(local_138 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack316) -
                                                     d_menu_item::_4395)));
        local_148 = (double)(longlong)iVar9;
        local_150 = (double)CONCAT44(0x43300000,uVar10);
        uStack340 = uVar12 - uVar10 ^ 0x80000000;
        iVar1 = (int)((float)(local_150 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack340) -
                                                     d_menu_item::_4395)));
        local_160 = (double)(longlong)iVar1;
        local_168 = (double)CONCAT44(0x43300000,uVar8);
        uStack364 = uVar13 - uVar8 ^ 0x80000000;
        iVar2 = (int)((float)(local_168 - d_menu_item::_6837) +
                     (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack364) -
                                                     d_menu_item::_4395)));
        local_178 = (double)(longlong)iVar2;
        local_180 = (double)CONCAT44(0x43300000,uVar7);
        uStack388 = uVar14 - uVar7 ^ 0x80000000;
        uVar3 = (uint)((float)(local_180 - d_menu_item::_6837) +
                      (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack388) -
                                                      d_menu_item::_4395)));
        local_190 = (double)(longlong)(int)uVar3;
        local_19c = uVar3 & 0xff |
                    (uint)CONCAT21(CONCAT11((char)iVar9,(char)iVar1),(char)iVar2) << 8;
      }
    }
  }
  local_20 = 0x43300000;
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
            (*(J2DWindow **)(this + 0x14d0),(TColor)&local_1c8,(TColor)&local_1c4,(TColor)&local_1c0
             ,(TColor)local_1bc);
  *(short *)(this + 0x23fc) = *(short *)(this + 0x23fc) + 1;
  if (0x27 < *(short *)(this + 0x23fc)) {
    *(undefined2 *)(this + 0x23fc) = 0;
  }
  iVar9 = (int)*(short *)(this + 0x23fc);
  if (iVar9 < 0x14) {
    dVar16 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x14,iVar9,0);
  }
  else {
    dVar16 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x14,0x28 - iVar9,0);
  }
  fVar5 = d_menu_item::_8013 - (float)((double)d_menu_item::_8014 * dVar16);
  iVar9 = *(int *)(this + 0x14d0);
  *(undefined *)(iVar9 + 0x104) = 0xff;
  *(char *)(iVar9 + 0x105) = (char)(int)fVar5;
  *(undefined *)(iVar9 + 0x106) = 0;
  *(undefined *)(iVar9 + 0x107) = 0xff;
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMenu_Item_c::equipBeastItem(int) */

undefined4 __thiscall dMenu_Item_c::equipBeastItem(dMenu_Item_c *this,int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0[param_1];
  uVar2 = 0;
  if (bVar1 == 0x47) {
    uVar2 = 2;
  }
  else {
    if (bVar1 < 0x47) {
      if (bVar1 == 0x45) {
        uVar2 = 0;
      }
      else {
        if (bVar1 < 0x45) {
          if (bVar1 == 0x1f) {
            uVar2 = 7;
          }
        }
        else {
          uVar2 = 1;
        }
      }
    }
    else {
      if (bVar1 == 0x4a) {
        uVar2 = 5;
      }
      else {
        if (bVar1 < 0x4a) {
          if (bVar1 < 0x49) {
            uVar2 = 3;
          }
          else {
            uVar2 = 4;
          }
        }
        else {
          if (bVar1 < 0x4c) {
            uVar2 = 6;
          }
        }
      }
    }
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dMenu_Item_c::_create(void) */

void __thiscall dMenu_Item_c::_create(dMenu_Item_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  STControl *this_01;
  void *pvVar2;
  undefined4 *puVar3;
  int iVar4;
  dMenu_Item_c *pdVar5;
  int iVar6;
  int iVar7;
  TBox2_float_ local_28;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_28.mTL.x = d_menu_item::_4323;
    local_28.mTL.y = d_menu_item::_4323;
    local_28.mBR.x = d_menu_item::_8150;
    local_28.mBR.y = d_menu_item::_8151;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_28);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 4) = this_00;
  if (*(int *)(this + 4) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_item.cpp",0xa57,"scrn != 0");
    m_Do_printf::OSPanic("d_menu_item.cpp",0xa57,&DAT_803604b1);
  }
  J2DScreen::set(*(J2DScreen **)(this + 4),"menu_item_02.blo",*(JKRArchive **)(this + 0x2310));
  this_01 = (STControl *)JKernel::operator_new(0x28);
  if (this_01 != (STControl *)0x0) {
    STControl::STControl(this_01,5,2,3,2,d_menu_item::_8152,d_menu_item::_4392,0,0x2000);
  }
  *(STControl **)(this + 0x2308) = this_01;
  if (*(int *)(this + 0x2308) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_item.cpp",0xa5b,"stick != 0");
    m_Do_printf::OSPanic("d_menu_item.cpp",0xa5b,&DAT_803604b1);
  }
  STControl::setWaitParm
            (*(STControl **)(this + 0x2308),5,2,3,2,d_menu_item::_8152,d_menu_item::_4392,0,0x800);
  pvVar2 = JKernel::operator_new(0x150);
  if (pvVar2 != (void *)0x0) {
    *(undefined4 *)((int)pvVar2 + 0x20) = 0;
    *(undefined4 *)((int)pvVar2 + 0x18) = 0;
    *(undefined4 *)((int)pvVar2 + 0x2c) = 0;
    *(undefined *)((int)pvVar2 + 0x74) = 0;
  }
  *(void **)(this + 0x230c) = pvVar2;
  if (*(int *)(this + 0x230c) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_item.cpp",0xa5f,"outFont != 0");
    m_Do_printf::OSPanic("d_menu_item.cpp",0xa5f,&DAT_803604b1);
  }
  *(undefined *)(*(int *)(this + 0x230c) + 0x74) = 1;
  puVar3 = (undefined4 *)JKernel::operator_new(0x1ba4);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = &dMenu_save_c::__vt;
    puVar3[2] = &dDlst_base_c::__vt;
    puVar3[2] = &dDlst_MenuSave_c::__vt;
  }
  *(undefined4 **)(this + 0x2330) = puVar3;
  if (*(int *)(this + 0x2330) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_item.cpp",0xa63,"dMs_c != 0");
    m_Do_printf::OSPanic("d_menu_item.cpp",0xa63,&DAT_803604b1);
  }
  *(undefined *)(*(int *)(this + 0x2330) + 0x537) = 0;
  dMenu_save_c::_create(*(dMenu_save_c **)(this + 0x2330));
  this[0x23fe] = (dMenu_Item_c)0x0;
  *(undefined4 *)(this + 0x23b8) = 0;
  *(undefined4 *)(this + 0x23bc) = 0;
  screenSet(this);
  initialize(this);
  d_menu_item::g_miHIO._4_1_ =
       mDoHIO_subRoot_c::createChild
                 (&mDoHIO_subRoot_c_803a5778,"アイテム画面",
                  (JORReflexible *)&d_menu_item::g_miHIO);
  iVar4 = 0;
  iVar7 = 0;
  iVar6 = 0;
  do {
    pdVar5 = this + iVar6;
    J2DPicture::insert(*(J2DPicture **)(pdVar5 + 0xa18),"cursor_00_02.bti",
                       (*(J2DPicture **)(pdVar5 + 0xa18))->mNumTexture,d_menu_item::_4393);
    *(float *)(this + iVar7 + 0x23c0) = *(float *)(pdVar5 + 0xa2c) - *(float *)(this + 0x166c);
    *(float *)(this + iVar7 + 0x23d0) = *(float *)(pdVar5 + 0xa30) - *(float *)(this + 0x1670);
    iVar4 = iVar4 + 1;
    iVar7 = iVar7 + 4;
    iVar6 = iVar6 + 0x38;
  } while (iVar4 < 4);
  iVar4 = 0;
  iVar6 = 0;
  do {
    J2DPicture::changeTexture(*(J2DPicture **)(this + iVar6 + 0xb0),"font_07_02.bti",0);
    f_op_msg_mng::fopMsgM_blendInit((fopMsgM_pane_class *)(this + iVar6 + 0xb0),"font_00.bti");
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 0x38;
  } while (iVar4 < 0xf);
  this[0x2400] = (dMenu_Item_c)0x0;
  this[0x2401] = (dMenu_Item_c)0x0;
  this[0x2402] = (dMenu_Item_c)0x0;
  this[0x2420] = (dMenu_Item_c)0x0;
  this[0x241f] = (dMenu_Item_c)0x0;
  this[0x241e] = (dMenu_Item_c)0x0;
  this[0x2404] = (dMenu_Item_c)0x3;
  this[0x2403] = (dMenu_Item_c)0x3;
  this[0x2405] = (dMenu_Item_c)0x3;
  iVar4 = 0;
  do {
    itemCheck(this,iVar4);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x15);
  cursorAnime(this);
  return;
}


/* __thiscall dMenu_Item_c::_delete(void) */

void __thiscall dMenu_Item_c::_delete(dMenu_Item_c *this)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = 0;
  iVar5 = 2;
  do {
    iVar4 = iVar1 + 0x23b8;
    iVar3 = *(int *)(this + iVar4);
    if (iVar3 != 0) {
      *(undefined4 *)(iVar3 + 0x60) = 0xffffffff;
      *(uint *)(iVar3 + 0x20c) = *(uint *)(iVar3 + 0x20c) | 1;
      *(uint *)(*(int *)(this + iVar4) + 0x20c) =
           *(uint *)(*(int *)(this + iVar4) + 0x20c) & 0xffffffbf;
      *(undefined4 *)(this + iVar4) = 0;
    }
    iVar1 = iVar1 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  piVar2 = *(int **)(this + 4);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2,1);
  }
  JKernel::operator_delete(*(JKRHeap **)(this + 0x2308));
  if (*(JKRHeap **)(this + 0x230c) != (JKRHeap *)0x0) {
    JKernel::operator_delete(*(JKRHeap **)(this + 0x230c));
  }
  dMenu_save_c::_delete(*(dMenu_save_c **)(this + 0x2330));
  piVar2 = *(int **)(this + 0x2330);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2,1);
  }
  (**(code **)(**(int **)(this + 0x2310) + 0x24))();
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,d_menu_item::g_miHIO._4_1_);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x801d038c) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMenu_Item_c::_move(void) */

void __thiscall dMenu_Item_c::_move(dMenu_Item_c *this)

{
  dMenu_Item_c dVar1;
  dMenu_save_c dVar2;
  float fVar3;
  float fVar4;
  byte bVar5;
  char cVar8;
  int iVar6;
  int iVar7;
  dMenu_save_c *this_00;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  dVar1 = this[0x23ff];
  itemBitCheck(this,false);
  if (this[0x23fe] != (dMenu_Item_c)0x0) {
    if (this[0x23fe] == (dMenu_Item_c)0x1) {
      this_00 = *(dMenu_save_c **)(this + 0x2330);
      dVar2 = this_00[0x531];
      if (dVar2 == (dMenu_save_c)0x2) {
        dMenu_save_c::_move(this_00);
      }
      else {
        if ((byte)dVar2 < 2) {
          if (dVar2 == (dMenu_save_c)0x0) {
            this[0x23fe] = (dMenu_Item_c)0x0;
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
      iVar6 = bottleFwaterCheck(this);
      if (iVar6 != 0) {
        iVar6 = 0;
        iVar10 = 2;
        do {
          if (*(int *)(this + iVar6 + 0x23b8) != 0) {
            *(undefined *)(*(int *)(this + iVar6 + 0x23b8) + 0x1ff) = 0;
          }
          iVar6 = iVar6 + 4;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 7;
    }
    goto LAB_801d0408;
  }
  cVar8 = noteCheck(this);
  if (cVar8 == '\0') {
    if ((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) == 0) &&
        (m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mTriggerRightLevel == 0)) &&
       (m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mTriggerLeftLevel == 0)) {
      if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
        if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
          cVar8 = d_meter::dMeter_subWinFlag();
          if (cVar8 != '\0') {
            subWindowDelete(this);
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x84b,(cXyz *)0x0,0,0,d_menu_item::_4393,
                       d_menu_item::_4393,d_menu_item::_4448,d_menu_item::_4448,0);
          }
        }
        else {
          if ((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 6 & 1) == 0) &&
              ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) == 0)) &&
             ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 3 & 1) == 0)) {
            cVar8 = d_meter::dMeter_subWinFlag();
            if (cVar8 == '\0') {
              cursorMainMove(this);
            }
            else {
              cursorSubMove(this);
            }
            itemScale(this);
            if ((this[0x23ff] != dVar1) && (dVar1 == (dMenu_Item_c)0xc)) {
              iVar6 = 0;
              iVar10 = 0;
              do {
                f_op_msg_mng::fopMsgM_paneTrans
                          ((fopMsgM_pane_class *)(this + iVar10 + 0x1f88),(double)d_menu_item::_4323
                           ,(double)d_menu_item::_4323);
                iVar6 = iVar6 + 1;
                iVar10 = iVar10 + 0x38;
              } while (iVar6 < 3);
            }
          }
          else {
            cVar8 = d_meter::dMeter_subWinFlag();
            if ((cVar8 == '\0') || (this[0x23ff] != (dMenu_Item_c)0xff)) {
              uVar9 = (uint)(byte)this[0x23ff];
              if (uVar9 != 0x15) {
                if (uVar9 < 0x15) {
                  bVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)
                          [1].mStageName[uVar9];
                }
                else {
                  if (uVar9 < 0x18) {
                    bVar5 = 0xff;
                  }
                  else {
                    if (uVar9 < 0x20) {
                      bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar9 + 0xd];
                    }
                    else {
                      if (uVar9 < 0x24) {
                        bVar5 = 0xff;
                      }
                      else {
                        if (uVar9 < 0x2c) {
                          bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                  mBits[uVar9 + 9];
                        }
                        else {
                          if (uVar9 < 0x30) {
                            bVar5 = 0xff;
                          }
                          else {
                            if (uVar9 < 0x38) {
                              bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                      mGetItem.mBits[uVar9 + 5];
                            }
                            else {
                              bVar5 = 0xff;
                            }
                          }
                        }
                      }
                    }
                  }
                }
                if (bVar5 != 0xff) {
                  cVar8 = d_meter::dMeter_subWinFlag();
                  if (cVar8 == '\0') {
                    iVar6 = recollectBossCheck(this);
                    if (iVar6 == 0) {
LAB_801cfebc:
                      itemDecide(this);
                    }
                    else {
                      uVar9 = (uint)(byte)this[0x23ff];
                      if (uVar9 < 0x15) {
                        bVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                  mReturnPlace)[1].mStageName[uVar9];
                      }
                      else {
                        if (uVar9 < 0x18) {
                          bVar5 = 0xff;
                        }
                        else {
                          if (uVar9 < 0x20) {
                            bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                    mGetItem.mBits[uVar9 + 0xd];
                          }
                          else {
                            if (uVar9 < 0x24) {
                              bVar5 = 0xff;
                            }
                            else {
                              if (uVar9 < 0x2c) {
                                bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                        mGetItem.mBits[uVar9 + 9];
                              }
                              else {
                                if (uVar9 < 0x30) {
                                  bVar5 = 0xff;
                                }
                                else {
                                  if (uVar9 < 0x38) {
                                    bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer
                                            .mGetItem.mBits[uVar9 + 5];
                                  }
                                  else {
                                    bVar5 = 0xff;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                      if (bVar5 != 0x56) {
                        if (uVar9 < 0x15) {
                          bVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                    mReturnPlace)[1].mStageName[uVar9];
                        }
                        else {
                          if (uVar9 < 0x18) {
                            bVar5 = 0xff;
                          }
                          else {
                            if (uVar9 < 0x20) {
                              bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                      mGetItem.mBits[uVar9 + 0xd];
                            }
                            else {
                              if (uVar9 < 0x24) {
                                bVar5 = 0xff;
                              }
                              else {
                                if (uVar9 < 0x2c) {
                                  bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                          mGetItem.mBits[uVar9 + 9];
                                }
                                else {
                                  if (uVar9 < 0x30) {
                                    bVar5 = 0xff;
                                  }
                                  else {
                                    if (uVar9 < 0x38) {
                                      bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.
                                              mPlayer.mGetItem.mBits[uVar9 + 5];
                                    }
                                    else {
                                      bVar5 = 0xff;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                        if (bVar5 != 0x58) {
                          if (uVar9 < 0x15) {
                            bVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                      mReturnPlace)[1].mStageName[uVar9];
                          }
                          else {
                            if (uVar9 < 0x18) {
                              bVar5 = 0xff;
                            }
                            else {
                              if (uVar9 < 0x20) {
                                bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                        mGetItem.mBits[uVar9 + 0xd];
                              }
                              else {
                                if (uVar9 < 0x24) {
                                  bVar5 = 0xff;
                                }
                                else {
                                  if (uVar9 < 0x2c) {
                                    bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer
                                            .mGetItem.mBits[uVar9 + 9];
                                  }
                                  else {
                                    if (uVar9 < 0x30) {
                                      bVar5 = 0xff;
                                    }
                                    else {
                                      if (uVar9 < 0x38) {
                                        bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.
                                                mPlayer.mGetItem.mBits[uVar9 + 5];
                                      }
                                      else {
                                        bVar5 = 0xff;
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                          if (bVar5 != 0x59) goto LAB_801cfebc;
                        }
                      }
                    }
                  }
                  else {
                    if (this[0x23ff] == (dMenu_Item_c)0xff) {
                      subWindowDelete(this);
                      JAIZelBasic::seStart
                                (JAIZelBasic::zel_basic,0x84b,(cXyz *)0x0,0,0,d_menu_item::_4393,
                                 d_menu_item::_4393,d_menu_item::_4448,d_menu_item::_4448,0);
                    }
                    else {
                      subItemDecide(this);
                    }
                  }
                }
              }
            }
            else {
              subWindowDelete(this);
              JAIZelBasic::seStart
                        (JAIZelBasic::zel_basic,0x84b,(cXyz *)0x0,0,0,d_menu_item::_4393,
                         d_menu_item::_4393,d_menu_item::_4448,d_menu_item::_4448,0);
            }
          }
        }
      }
      else {
        cVar8 = d_meter::dMeter_subWinFlag();
        if ((cVar8 == '\0') || (this[0x23ff] != (dMenu_Item_c)0xff)) {
          uVar9 = (uint)(byte)this[0x23ff];
          if (uVar9 == 0x15) {
            this[0x23fe] = (dMenu_Item_c)0x1;
            dMenu_save_c::initialize(*(dMenu_save_c **)(this + 0x2330));
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x84c,(cXyz *)0x0,0,0,d_menu_item::_4393,
                       d_menu_item::_4393,d_menu_item::_4448,d_menu_item::_4448,0);
          }
          else {
            if (uVar9 < 0x15) {
              bVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                      mStageName[uVar9];
            }
            else {
              if (uVar9 < 0x18) {
                bVar5 = 0xff;
              }
              else {
                if (uVar9 < 0x20) {
                  bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar9 + 0xd];
                }
                else {
                  if (uVar9 < 0x24) {
                    bVar5 = 0xff;
                  }
                  else {
                    if (uVar9 < 0x2c) {
                      bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar9 + 9];
                    }
                    else {
                      if (uVar9 < 0x30) {
                        bVar5 = 0xff;
                      }
                      else {
                        if (uVar9 < 0x38) {
                          bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                  mBits[uVar9 + 5];
                        }
                        else {
                          bVar5 = 0xff;
                        }
                      }
                    }
                  }
                }
              }
            }
            if (bVar5 != 0xff) {
              iVar6 = recollectBossCheck(this);
              if (iVar6 == 0) {
LAB_801cfa30:
                f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x740);
                f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x778);
                f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x7b0);
                f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x7e8);
                f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x820);
                *(undefined2 *)(this + 0x81e) = 1;
                *(undefined2 *)(this + 0x7e6) = 1;
                itemnoteSet(this);
                JAIZelBasic::seStart
                          (JAIZelBasic::zel_basic,0x8b6,(cXyz *)0x0,0,0,d_menu_item::_4393,
                           d_menu_item::_4393,d_menu_item::_4448,d_menu_item::_4448,0);
              }
              else {
                uVar9 = (uint)(byte)this[0x23ff];
                if (uVar9 < 0x15) {
                  bVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)
                          [1].mStageName[uVar9];
                }
                else {
                  if (uVar9 < 0x18) {
                    bVar5 = 0xff;
                  }
                  else {
                    if (uVar9 < 0x20) {
                      bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar9 + 0xd];
                    }
                    else {
                      if (uVar9 < 0x24) {
                        bVar5 = 0xff;
                      }
                      else {
                        if (uVar9 < 0x2c) {
                          bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                  mBits[uVar9 + 9];
                        }
                        else {
                          if (uVar9 < 0x30) {
                            bVar5 = 0xff;
                          }
                          else {
                            if (uVar9 < 0x38) {
                              bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                      mGetItem.mBits[uVar9 + 5];
                            }
                            else {
                              bVar5 = 0xff;
                            }
                          }
                        }
                      }
                    }
                  }
                }
                if (bVar5 != 0x56) {
                  if (uVar9 < 0x15) {
                    bVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)
                            [1].mStageName[uVar9];
                  }
                  else {
                    if (uVar9 < 0x18) {
                      bVar5 = 0xff;
                    }
                    else {
                      if (uVar9 < 0x20) {
                        bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                mBits[uVar9 + 0xd];
                      }
                      else {
                        if (uVar9 < 0x24) {
                          bVar5 = 0xff;
                        }
                        else {
                          if (uVar9 < 0x2c) {
                            bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                    mGetItem.mBits[uVar9 + 9];
                          }
                          else {
                            if (uVar9 < 0x30) {
                              bVar5 = 0xff;
                            }
                            else {
                              if (uVar9 < 0x38) {
                                bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                        mGetItem.mBits[uVar9 + 5];
                              }
                              else {
                                bVar5 = 0xff;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  if (bVar5 != 0x58) {
                    if (uVar9 < 0x15) {
                      bVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                mReturnPlace)[1].mStageName[uVar9];
                    }
                    else {
                      if (uVar9 < 0x18) {
                        bVar5 = 0xff;
                      }
                      else {
                        if (uVar9 < 0x20) {
                          bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                  mBits[uVar9 + 0xd];
                        }
                        else {
                          if (uVar9 < 0x24) {
                            bVar5 = 0xff;
                          }
                          else {
                            if (uVar9 < 0x2c) {
                              bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                      mGetItem.mBits[uVar9 + 9];
                            }
                            else {
                              if (uVar9 < 0x30) {
                                bVar5 = 0xff;
                              }
                              else {
                                if (uVar9 < 0x38) {
                                  bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                          mGetItem.mBits[uVar9 + 5];
                                }
                                else {
                                  bVar5 = 0xff;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                    if (bVar5 != 0x59) goto LAB_801cfa30;
                  }
                }
              }
            }
          }
        }
        else {
          subWindowDelete(this);
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x84b,(cXyz *)0x0,0,0,d_menu_item::_4393,
                     d_menu_item::_4393,d_menu_item::_4448,d_menu_item::_4448,0);
        }
      }
    }
  }
  else {
    noteAppear(this);
  }
  if (this[0x2404] != (dMenu_Item_c)0x3) {
    itemMove(this);
  }
  uVar9 = (uint)(byte)this[0x23ff];
  if (uVar9 == 0x15) {
    itemnameMove(this);
  }
  else {
    if (uVar9 < 0x15) {
      bVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
              [uVar9];
    }
    else {
      if (uVar9 < 0x18) {
        bVar5 = 0xff;
      }
      else {
        if (uVar9 < 0x20) {
          bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                  [uVar9 + 0xd];
        }
        else {
          if (uVar9 < 0x24) {
            bVar5 = 0xff;
          }
          else {
            if (uVar9 < 0x2c) {
              bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar9 + 9];
            }
            else {
              if (uVar9 < 0x30) {
                bVar5 = 0xff;
              }
              else {
                if (uVar9 < 0x38) {
                  bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar9 + 5];
                }
                else {
                  bVar5 = 0xff;
                }
              }
            }
          }
        }
      }
    }
    if (bVar5 != 0xff) {
      iVar6 = recollectBossCheck(this);
      if (iVar6 == 0) {
LAB_801d026c:
        itemnameMove(this);
        goto LAB_801d0290;
      }
      uVar9 = (uint)(byte)this[0x23ff];
      if (uVar9 < 0x15) {
        bVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                mStageName[uVar9];
      }
      else {
        if (uVar9 < 0x18) {
          bVar5 = 0xff;
        }
        else {
          if (uVar9 < 0x20) {
            bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar9 + 0xd];
          }
          else {
            if (uVar9 < 0x24) {
              bVar5 = 0xff;
            }
            else {
              if (uVar9 < 0x2c) {
                bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar9 + 9];
              }
              else {
                if (uVar9 < 0x30) {
                  bVar5 = 0xff;
                }
                else {
                  if (uVar9 < 0x38) {
                    bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar9 + 5];
                  }
                  else {
                    bVar5 = 0xff;
                  }
                }
              }
            }
          }
        }
      }
      if (bVar5 != 0x56) {
        if (uVar9 < 0x15) {
          bVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                  mStageName[uVar9];
        }
        else {
          if (uVar9 < 0x18) {
            bVar5 = 0xff;
          }
          else {
            if (uVar9 < 0x20) {
              bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar9 + 0xd];
            }
            else {
              if (uVar9 < 0x24) {
                bVar5 = 0xff;
              }
              else {
                if (uVar9 < 0x2c) {
                  bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar9 + 9];
                }
                else {
                  if (uVar9 < 0x30) {
                    bVar5 = 0xff;
                  }
                  else {
                    if (uVar9 < 0x38) {
                      bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar9 + 5];
                    }
                    else {
                      bVar5 = 0xff;
                    }
                  }
                }
              }
            }
          }
        }
        if (bVar5 != 0x58) {
          if (uVar9 < 0x15) {
            bVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                    mStageName[uVar9];
          }
          else {
            if (uVar9 < 0x18) {
              bVar5 = 0xff;
            }
            else {
              if (uVar9 < 0x20) {
                bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar9 + 0xd];
              }
              else {
                if (uVar9 < 0x24) {
                  bVar5 = 0xff;
                }
                else {
                  if (uVar9 < 0x2c) {
                    bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar9 + 9];
                  }
                  else {
                    if (uVar9 < 0x30) {
                      bVar5 = 0xff;
                    }
                    else {
                      if (uVar9 < 0x38) {
                        bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                mBits[uVar9 + 5];
                      }
                      else {
                        bVar5 = 0xff;
                      }
                    }
                  }
                }
              }
            }
          }
          if (bVar5 != 0x59) goto LAB_801d026c;
        }
      }
    }
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x890));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x8c8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x858));
  }
LAB_801d0290:
  outFontMove(this);
  cursorAnime(this);
  cornerMove(this);
  if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot == FireAndIceArrows)
     || (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot == LightArrow)) {
    arrowLightAnime(this);
  }
  checkMove(this);
  iVar6 = bottleFwaterCheck(this);
  if (iVar6 != 0) {
    iVar10 = 0;
    iVar12 = 2;
    do {
      fVar4 = d_menu_item::_4323;
      iVar11 = iVar10 + 0x23b8;
      iVar7 = *(int *)(this + iVar11);
      if (iVar7 != 0) {
        fVar3 = *(float *)(this + iVar6 * 0x38 + 0x1670) - d_menu_item::_7631;
        *(float *)(iVar7 + 0x1e4) = *(float *)(this + iVar6 * 0x38 + 0x166c) - d_menu_item::_7632;
        *(float *)(iVar7 + 0x1e8) = fVar3;
        *(float *)(iVar7 + 0x1ec) = fVar4;
        *(uint *)(*(int *)(this + iVar11) + 0x20c) =
             *(uint *)(*(int *)(this + iVar11) + 0x20c) & 0xfffffffb;
        *(undefined *)(*(int *)(this + iVar11) + 0x1ff) = 0xff;
      }
      iVar10 = iVar10 + 4;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
LAB_801d0408:
  uVar9 = (uint)(byte)this[0x23ff];
  if (uVar9 == 0x15) {
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x17;
  }
  else {
    if (uVar9 < 0x15) {
      bVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
              [uVar9];
    }
    else {
      if (uVar9 < 0x18) {
        bVar5 = 0xff;
      }
      else {
        if (uVar9 < 0x20) {
          bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                  [uVar9 + 0xd];
        }
        else {
          if (uVar9 < 0x24) {
            bVar5 = 0xff;
          }
          else {
            if (uVar9 < 0x2c) {
              bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar9 + 9];
            }
            else {
              if (uVar9 < 0x30) {
                bVar5 = 0xff;
              }
              else {
                if (uVar9 < 0x38) {
                  bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar9 + 5];
                }
                else {
                  bVar5 = 0xff;
                }
              }
            }
          }
        }
      }
    }
    if (bVar5 == 0xff) {
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
      d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
    }
    else {
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x21;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801d0f30) */
/* __thiscall dMenu_Item_c::_draw(void) */

void __thiscall dMenu_Item_c::_draw(dMenu_Item_c *this)

{
  J2DOrthoGraph *pCtx;
  double dVar1;
  double dVar2;
  int iVar3;
  dMenu_Item_c *pdVar4;
  int iVar5;
  undefined4 uVar6;
  double dVar7;
  undefined8 in_f31;
  double local_b8;
  double local_b0;
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
  if (this[0x2422] == (dMenu_Item_c)0x0) {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x740));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x778));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x7b0));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x7e8));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x820));
    dDlst_2DOutFont_c::setAlpha(*(dDlst_2DOutFont_c **)(this + 0x230c),(uchar)this[0x88d]);
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
    iVar3 = 0;
    iVar5 = 0;
    do {
      pdVar4 = this + iVar5;
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar4 + 0xaf8));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar4 + 0xcb8));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar4 + 0xe78));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar4 + 0x1070));
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x38;
    } while (iVar3 < 8);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1038));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1230));
    iVar3 = 0;
    iVar5 = 0;
    do {
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar5 + 0x1268));
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x38;
    } while (iVar3 < 9);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1460));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1498));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x14d0));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1508));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1540));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1578));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x15b0));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x15e8));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1620));
    iVar3 = 0;
    iVar5 = 0;
    do {
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar5 + 0x1658));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar5 + 0x1af0));
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x38;
    } while (iVar3 < 0x15);
    iVar3 = 0;
    iVar5 = 0;
    do {
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar5 + 0x1f88));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar5 + 0x2030));
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x38;
    } while (iVar3 < 3);
    iVar3 = 0;
    iVar5 = 0;
    do {
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar5 + 0x20d8));
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x38;
    } while (iVar3 < 6);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x2228));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x2260));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x2298));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x22d0));
  }
  else {
    dVar7 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(this + 0x23f8),0);
    dVar1 = d_menu_item::_6837;
    if ((this[0x2421] != (dMenu_Item_c)0x1) && (this[0x2421] != (dMenu_Item_c)0x2)) {
      *(char *)(*(int *)(this + 0x740) + 0xac) =
           (char)(int)((double)(float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x775]) -
                                      d_menu_item::_6837) * dVar7);
      *(char *)(*(int *)(this + 0x778) + 0xac) =
           (char)(int)((double)(float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x7ad]) - dVar1)
                      * dVar7);
      *(char *)(*(int *)(this + 0x7b0) + 0xac) =
           (char)(int)((double)(float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x7e5]) - dVar1)
                      * dVar7);
      local_b8 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x81d]);
      *(char *)(*(int *)(this + 0x7e8) + 0xac) =
           (char)(int)((double)(float)(local_b8 - dVar1) * dVar7);
      local_a8 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x855]);
      *(char *)(*(int *)(this + 0x820) + 0xac) =
           (char)(int)((double)(float)(local_a8 - dVar1) * dVar7);
      local_98 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x88d]);
      dDlst_2DOutFont_c::setAlpha
                (*(dDlst_2DOutFont_c **)(this + 0x230c),
                 (uchar)(int)((double)(float)(local_98 - dVar1) * dVar7));
      dVar1 = d_menu_item::_6837;
      local_88 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x8c5]);
      *(char *)(*(int *)(this + 0x890) + 0xac) =
           (char)(int)((double)(float)(local_88 - d_menu_item::_6837) * dVar7);
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
    dVar1 = d_menu_item::_6837;
    local_30 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x9a5]);
    *(char *)(*(int *)(this + 0x970) + 0xac) =
         (char)(int)((double)(float)(local_30 - d_menu_item::_6837) * dVar7);
    iVar3 = 0;
    iVar5 = 4;
    do {
      local_30 = (double)CONCAT44(0x43300000,(uint)(byte)(this + iVar3)[0xa4d]);
      *(char *)(*(int *)(this + iVar3 + 0xa18) + 0xac) =
           (char)(int)((double)(float)(local_30 - dVar1) * dVar7);
      dVar2 = d_menu_item::_6837;
      iVar3 = iVar3 + 0x38;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar3 = 0;
    iVar5 = 8;
    do {
      pdVar4 = this + iVar3;
      local_30 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0xb2d]);
      *(char *)(*(int *)(pdVar4 + 0xaf8) + 0xac) =
           (char)(int)((double)(float)(local_30 - dVar2) * dVar7);
      local_40 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0xced]);
      *(char *)(*(int *)(pdVar4 + 0xcb8) + 0xac) =
           (char)(int)((double)(float)(local_40 - dVar2) * dVar7);
      local_50 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0xead]);
      *(char *)(*(int *)(pdVar4 + 0xe78) + 0xac) =
           (char)(int)((double)(float)(local_50 - dVar2) * dVar7);
      local_60 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x10a5]);
      *(char *)(*(int *)(pdVar4 + 0x1070) + 0xac) =
           (char)(int)((double)(float)(local_60 - dVar2) * dVar7);
      dVar1 = d_menu_item::_6837;
      iVar3 = iVar3 + 0x38;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    local_30 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x106d]);
    *(char *)(*(int *)(this + 0x1038) + 0xac) =
         (char)(int)((double)(float)(local_30 - d_menu_item::_6837) * dVar7);
    local_40 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1265]);
    *(char *)(*(int *)(this + 0x1230) + 0xac) =
         (char)(int)((double)(float)(local_40 - dVar1) * dVar7);
    iVar3 = 0;
    iVar5 = 9;
    do {
      local_30 = (double)CONCAT44(0x43300000,(uint)(byte)(this + iVar3)[0x129d]);
      *(char *)(*(int *)(this + iVar3 + 0x1268) + 0xac) =
           (char)(int)((double)(float)(local_30 - dVar1) * dVar7);
      dVar2 = d_menu_item::_6837;
      iVar3 = iVar3 + 0x38;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    local_30 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1495]);
    *(char *)(*(int *)(this + 0x1460) + 0xac) =
         (char)(int)((double)(float)(local_30 - d_menu_item::_6837) * dVar7);
    local_40 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x14cd]);
    *(char *)(*(int *)(this + 0x1498) + 0xac) =
         (char)(int)((double)(float)(local_40 - dVar2) * dVar7);
    local_50 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1505]);
    *(char *)(*(int *)(this + 0x14d0) + 0xac) =
         (char)(int)((double)(float)(local_50 - dVar2) * dVar7);
    local_60 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x153d]);
    *(char *)(*(int *)(this + 0x1508) + 0xac) =
         (char)(int)((double)(float)(local_60 - dVar2) * dVar7);
    local_70 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1575]);
    *(char *)(*(int *)(this + 0x1540) + 0xac) =
         (char)(int)((double)(float)(local_70 - dVar2) * dVar7);
    local_80 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x15ad]);
    *(char *)(*(int *)(this + 0x1578) + 0xac) =
         (char)(int)((double)(float)(local_80 - dVar2) * dVar7);
    local_90 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x15e5]);
    *(char *)(*(int *)(this + 0x15b0) + 0xac) =
         (char)(int)((double)(float)(local_90 - dVar2) * dVar7);
    local_a0 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x161d]);
    *(char *)(*(int *)(this + 0x15e8) + 0xac) =
         (char)(int)((double)(float)(local_a0 - dVar2) * dVar7);
    local_b0 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1655]);
    *(char *)(*(int *)(this + 0x1620) + 0xac) =
         (char)(int)((double)(float)(local_b0 - dVar2) * dVar7);
    iVar3 = 0;
    iVar5 = 0x15;
    do {
      pdVar4 = this + iVar3;
      local_30 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x168d]);
      *(char *)(*(int *)(pdVar4 + 0x1658) + 0xac) =
           (char)(int)((double)(float)(local_30 - dVar2) * dVar7);
      local_40 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x1b25]);
      *(char *)(*(int *)(pdVar4 + 0x1af0) + 0xac) =
           (char)(int)((double)(float)(local_40 - dVar2) * dVar7);
      dVar1 = d_menu_item::_6837;
      iVar3 = iVar3 + 0x38;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar3 = 0;
    iVar5 = 3;
    do {
      pdVar4 = this + iVar3;
      local_30 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x1fbd]);
      *(char *)(*(int *)(pdVar4 + 0x1f88) + 0xac) =
           (char)(int)((double)(float)(local_30 - dVar1) * dVar7);
      local_40 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x2065]);
      *(char *)(*(int *)(pdVar4 + 0x2030) + 0xac) =
           (char)(int)((double)(float)(local_40 - dVar1) * dVar7);
      dVar2 = d_menu_item::_6837;
      iVar3 = iVar3 + 0x38;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar3 = 0;
    iVar5 = 6;
    do {
      local_30 = (double)CONCAT44(0x43300000,(uint)(byte)(this + iVar3)[0x210d]);
      *(char *)(*(int *)(this + iVar3 + 0x20d8) + 0xac) =
           (char)(int)((double)(float)(local_30 - dVar2) * dVar7);
      dVar1 = d_menu_item::_6837;
      iVar3 = iVar3 + 0x38;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    local_30 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x225d]);
    *(char *)(*(int *)(this + 0x2228) + 0xac) =
         (char)(int)((double)(float)(local_30 - d_menu_item::_6837) * dVar7);
    local_40 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x2295]);
    *(char *)(*(int *)(this + 0x2260) + 0xac) =
         (char)(int)((double)(float)(local_40 - dVar1) * dVar7);
    local_50 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x22cd]);
    *(char *)(*(int *)(this + 0x2298) + 0xac) =
         (char)(int)((double)(float)(local_50 - dVar1) * dVar7);
    local_60 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x2305]);
    *(char *)(*(int *)(this + 0x22d0) + 0xac) =
         (char)(int)((double)(float)(local_60 - dVar1) * dVar7);
  }
  outFontDraw(this);
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(*(J2DScreen **)(this + 4),d_menu_item::_4323,d_menu_item::_4323,&pCtx->parent);
  dMenu_save_c::_draw(*(dMenu_save_c **)(this + 0x2330));
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMenu_Item_c::_open(void) */

bool __thiscall dMenu_Item_c::_open(dMenu_Item_c *this)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  byte bVar4;
  ___ in_r5;
  int iVar5;
  dMenu_Item_c *pdVar6;
  int iVar7;
  int iVar8;
  
  sVar2 = d_menu_item::g_miHIO.field_0x26;
  if (*(short *)(this + 0x23f8) != 0) goto LAB_801d135c;
  iVar5 = 0;
  iVar8 = 0;
  iVar7 = 0;
  do {
    pdVar6 = this + iVar7;
    MSL_C.PPCEABI.bare.H::strcpy(*(char **)(pdVar6 + 0x23e0),"");
    MSL_C.PPCEABI.bare.H::strcpy(*(char **)(pdVar6 + 0x23e8),"");
    J2DTextBox::setString(*(J2DTextBox **)(this + iVar8 + 0x890),*(char **)(pdVar6 + 0x23e0),in_r5);
    iVar5 = iVar5 + 1;
    iVar8 = iVar8 + 0x38;
    iVar7 = iVar7 + 4;
  } while (iVar5 < 2);
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x778),*(char **)(this + 0x23e8),in_r5);
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x740),*(char **)(this + 0x23ec),in_r5);
  itemnameSet(this);
  if (this[0x23ff] != (dMenu_Item_c)0x15) {
    iVar5 = recollectBossCheck(this);
    if (iVar5 == 0) {
LAB_801d1258:
      itemnoteSet(this);
      uVar3 = (uint)(byte)this[0x23ff];
      if (uVar3 < 0x15) {
        bVar4 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                mStageName[uVar3];
      }
      else {
        if (uVar3 < 0x18) {
          bVar4 = 0xff;
        }
        else {
          if (uVar3 < 0x20) {
            bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar3 + 0xd];
          }
          else {
            if (uVar3 < 0x24) {
              bVar4 = 0xff;
            }
            else {
              if (uVar3 < 0x2c) {
                bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar3 + 9];
              }
              else {
                if (uVar3 < 0x30) {
                  bVar4 = 0xff;
                }
                else {
                  if (uVar3 < 0x38) {
                    bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar3 + 5];
                  }
                  else {
                    bVar4 = 0xff;
                  }
                }
              }
            }
          }
        }
      }
      if (bVar4 == 0xff) {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
        d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
      }
      else {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x21;
      }
      goto LAB_801d135c;
    }
    uVar3 = (uint)(byte)this[0x23ff];
    if (uVar3 < 0x15) {
      bVar4 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
              [uVar3];
    }
    else {
      if (uVar3 < 0x18) {
        bVar4 = 0xff;
      }
      else {
        if (uVar3 < 0x20) {
          bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                  [uVar3 + 0xd];
        }
        else {
          if (uVar3 < 0x24) {
            bVar4 = 0xff;
          }
          else {
            if (uVar3 < 0x2c) {
              bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar3 + 9];
            }
            else {
              if (uVar3 < 0x30) {
                bVar4 = 0xff;
              }
              else {
                if (uVar3 < 0x38) {
                  bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar3 + 5];
                }
                else {
                  bVar4 = 0xff;
                }
              }
            }
          }
        }
      }
    }
    if (bVar4 != 0x56) {
      if (uVar3 < 0x15) {
        bVar4 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                mStageName[uVar3];
      }
      else {
        if (uVar3 < 0x18) {
          bVar4 = 0xff;
        }
        else {
          if (uVar3 < 0x20) {
            bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar3 + 0xd];
          }
          else {
            if (uVar3 < 0x24) {
              bVar4 = 0xff;
            }
            else {
              if (uVar3 < 0x2c) {
                bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar3 + 9];
              }
              else {
                if (uVar3 < 0x30) {
                  bVar4 = 0xff;
                }
                else {
                  if (uVar3 < 0x38) {
                    bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar3 + 5];
                  }
                  else {
                    bVar4 = 0xff;
                  }
                }
              }
            }
          }
        }
      }
      if (bVar4 != 0x58) {
        if (uVar3 < 0x15) {
          bVar4 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                  mStageName[uVar3];
        }
        else {
          if (uVar3 < 0x18) {
            bVar4 = 0xff;
          }
          else {
            if (uVar3 < 0x20) {
              bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar3 + 0xd];
            }
            else {
              if (uVar3 < 0x24) {
                bVar4 = 0xff;
              }
              else {
                if (uVar3 < 0x2c) {
                  bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar3 + 9];
                }
                else {
                  if (uVar3 < 0x30) {
                    bVar4 = 0xff;
                  }
                  else {
                    if (uVar3 < 0x38) {
                      bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar3 + 5];
                    }
                    else {
                      bVar4 = 0xff;
                    }
                  }
                }
              }
            }
          }
        }
        if (bVar4 != 0x59) goto LAB_801d1258;
      }
    }
  }
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x17;
LAB_801d135c:
  *(short *)(this + 0x23f8) = *(short *)(this + 0x23f8) + 1;
  sVar1 = *(short *)(this + 0x23f8);
  if ((sVar1 < 0xb) && (0 < sVar1)) {
    if (this[0x2421] == (dMenu_Item_c)0x2) {
      mainOpenProc(this,sVar1,10,sVar2);
    }
    else {
      mainOpenProc(this,sVar1,10,-sVar2);
    }
    titleOpenProc(this,*(short *)(this + 0x23f8),10);
    noteOpenProc(this,*(short *)(this + 0x23f8),10);
    nameOpenProc(this,*(short *)(this + 0x23f8),10);
  }
  sVar2 = *(short *)(this + 0x23f8);
  if (9 < sVar2) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x813,(cXyz *)0x0,0,0,d_menu_item::_4393,d_menu_item::_4393,
               d_menu_item::_4448,d_menu_item::_4448,0);
  }
  return 9 < sVar2;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801d1cac) */
/* WARNING: Removing unreachable block (ram,0x801d1c9c) */
/* WARNING: Removing unreachable block (ram,0x801d1ca4) */
/* WARNING: Removing unreachable block (ram,0x801d1cb4) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMenu_Item_c::_close(void) */

undefined4 __thiscall dMenu_Item_c::_close(dMenu_Item_c *this)

{
  dItem_data__ItemNo dVar1;
  byte bVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  dMenu_Item_c *pdVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  undefined8 in_f28;
  double dVar14;
  undefined8 in_f29;
  double dVar15;
  undefined8 in_f30;
  double dVar16;
  undefined8 in_f31;
  double local_68;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  uVar8 = 0;
  *(short *)(this + 0x23f8) = *(short *)(this + 0x23f8) + -1;
  dVar11 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - *(short *)(this + 0x23f8),0);
  dVar15 = (double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                            (int)d_menu_item::g_miHIO.field_0x26 ^
                                                            0x80000000) - d_menu_item::_4395) *
                          dVar11);
  dVar11 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - *(short *)(this + 0x23f8),0);
  dVar14 = (double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                            (int)d_menu_item::g_miHIO.field_0x28 ^
                                                            0x80000000) - d_menu_item::_4395) *
                          dVar11);
  dVar11 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - *(short *)(this + 0x23f8),0);
  local_68 = (double)CONCAT44(0x43300000,(int)d_menu_item::g_miHIO.field_0x2c ^ 0x80000000);
  dVar16 = (double)(float)((double)(float)(local_68 - d_menu_item::_4395) * dVar11);
  dVar12 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - *(short *)(this + 0x23f8),0);
  dVar13 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(this + 0x23f8),0);
  iVar3 = 0;
  dVar11 = (double)d_menu_item::_9797;
  iVar9 = 2;
  do {
    if (*(int *)(this + iVar3 + 0x23b8) != 0) {
      *(char *)(*(int *)(this + iVar3 + 0x23b8) + 0x1ff) = (char)(int)(dVar11 * dVar13);
    }
    iVar3 = iVar3 + 4;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  if (this[0x2421] == (dMenu_Item_c)0x2) {
    mainTrans(this,(float)-dVar15,d_menu_item::_4323);
    titleTrans(this,d_menu_item::_4323,(float)dVar14);
    local_68 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x856) ^ 0x80000000);
    noteRotate(this,(float)((double)(float)((double)CONCAT44(0x43300000,
                                                             (int)d_menu_item::g_miHIO.field_0x3e ^
                                                             0x80000000) - d_menu_item::_4395) *
                           dVar12),
               (float)(local_68 - d_menu_item::_4395) +
               (float)(dVar12 * (double)(float)((double)CONCAT44(0x43300000,
                                                                 (int)d_menu_item::g_miHIO.
                                                                      field_0x2a -
                                                                 (int)*(short *)(this + 0x856) ^
                                                                 0x80000000) - d_menu_item::_4395)))
    ;
    nameTrans(this,d_menu_item::_4323,(float)dVar16);
  }
  else {
    if (this[0x2421] == (dMenu_Item_c)0x1) {
      mainTrans(this,(float)dVar15,d_menu_item::_4323);
      titleTrans(this,d_menu_item::_4323,(float)dVar14);
      local_68 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x856) ^ 0x80000000);
      noteRotate(this,(float)((double)(float)((double)CONCAT44(0x43300000,
                                                               (int)d_menu_item::g_miHIO.field_0x3e
                                                               ^ 0x80000000) - d_menu_item::_4395) *
                             dVar12),
                 (float)(local_68 - d_menu_item::_4395) +
                 (float)(dVar12 * (double)(float)((double)CONCAT44(0x43300000,
                                                                   (int)d_menu_item::g_miHIO.
                                                                        field_0x2a -
                                                                   (int)*(short *)(this + 0x856) ^
                                                                   0x80000000) - d_menu_item::_4395)
                        ));
      nameTrans(this,d_menu_item::_4323,(float)dVar16);
    }
  }
  if (*(short *)(this + 0x23f8) < 1) {
    uVar8 = 1;
    this[0x2422] = (dMenu_Item_c)0x0;
    iVar3 = 0;
    iVar9 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar9 + 0xb0));
      iVar3 = iVar3 + 1;
      iVar9 = iVar9 + 0x38;
    } while (iVar3 < 0xf);
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
    iVar3 = 0;
    iVar9 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar9 + 0xa18));
      iVar3 = iVar3 + 1;
      iVar9 = iVar9 + 0x38;
    } while (iVar3 < 4);
    iVar3 = 0;
    iVar9 = 0;
    do {
      pdVar7 = this + iVar9;
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar7 + 0xaf8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar7 + 0xcb8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar7 + 0xe78));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar7 + 0x1070));
      iVar3 = iVar3 + 1;
      iVar9 = iVar9 + 0x38;
    } while (iVar3 < 8);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1038));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1230));
    iVar3 = 0;
    iVar9 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar9 + 0x1268));
      iVar3 = iVar3 + 1;
      iVar9 = iVar9 + 0x38;
    } while (iVar3 < 9);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1460));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1498));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x14d0));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1508));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1540));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1578));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x15b0));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x15e8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1620));
    iVar3 = 0;
    iVar9 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar9 + 0x1658));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar9 + 0x1af0));
      iVar3 = iVar3 + 1;
      iVar9 = iVar9 + 0x38;
    } while (iVar3 < 0x15);
    iVar3 = 0;
    iVar9 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar9 + 0x2030));
      iVar3 = iVar3 + 1;
      iVar9 = iVar9 + 0x38;
    } while (iVar3 < 3);
    iVar3 = 0;
    iVar9 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar9 + 0x20d8));
      iVar3 = iVar3 + 1;
      iVar9 = iVar9 + 0x38;
    } while (iVar3 < 6);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x2228));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x2260));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x2298));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x22d0));
    if ((byte)this[0x2404] != 3) {
      *(dMenu_Item_c *)
       (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
        mInventorySlotIndexOnButton + (byte)this[0x2404]) = this[0x2401];
      uVar6 = (uint)(byte)this[0x2404];
      uVar5 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                          mInventorySlotIndexOnButton[uVar6];
      if (uVar5 == 0xff) {
        d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar6] = InvalidItem;
      }
      else {
        if (uVar5 < 0x15) {
          dVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                  mStageName[uVar5];
        }
        else {
          if (uVar5 < 0x18) {
            dVar1 = InvalidItem;
          }
          else {
            if (uVar5 < 0x20) {
              dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar5 + 0xd];
            }
            else {
              if (uVar5 < 0x24) {
                dVar1 = InvalidItem;
              }
              else {
                if (uVar5 < 0x2c) {
                  dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar5 + 9];
                }
                else {
                  if (uVar5 < 0x30) {
                    dVar1 = InvalidItem;
                  }
                  else {
                    if (uVar5 < 0x38) {
                      dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar5 + 5];
                    }
                    else {
                      dVar1 = InvalidItem;
                    }
                  }
                }
              }
            }
          }
        }
        d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar6] = dVar1;
        uVar5 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                            mInventorySlotIndexOnButton[uVar6];
        if (uVar5 < 0x15) {
          bVar2 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                  mStageName[uVar5];
        }
        else {
          if (uVar5 < 0x18) {
            bVar2 = 0xff;
          }
          else {
            if (uVar5 < 0x20) {
              bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar5 + 0xd];
            }
            else {
              if (uVar5 < 0x24) {
                bVar2 = 0xff;
              }
              else {
                if (uVar5 < 0x2c) {
                  bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar5 + 9];
                }
                else {
                  if (uVar5 < 0x30) {
                    bVar2 = 0xff;
                  }
                  else {
                    if (uVar5 < 0x38) {
                      bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar5 + 5];
                    }
                    else {
                      bVar2 = 0xff;
                    }
                  }
                }
              }
            }
          }
        }
        if (bVar2 == 0xff) {
          d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
          mInventorySlotIndexOnButton[uVar6] = -1;
        }
      }
      this[0x2404] = (dMenu_Item_c)0x3;
      if ((byte)this[0x2403] != 3) {
        *(dMenu_Item_c *)
         (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
          mInventorySlotIndexOnButton + (byte)this[0x2403]) = this[0x2402];
        uVar5 = (uint)(byte)this[0x2403];
        uVar6 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                            mInventorySlotIndexOnButton[uVar5];
        if (uVar6 == 0xff) {
          d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar5] = InvalidItem;
        }
        else {
          if (uVar6 < 0x15) {
            dVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                    mStageName[uVar6];
          }
          else {
            if (uVar6 < 0x18) {
              dVar1 = InvalidItem;
            }
            else {
              if (uVar6 < 0x20) {
                dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar6 + 0xd];
              }
              else {
                if (uVar6 < 0x24) {
                  dVar1 = InvalidItem;
                }
                else {
                  if (uVar6 < 0x2c) {
                    dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar6 + 9];
                  }
                  else {
                    if (uVar6 < 0x30) {
                      dVar1 = InvalidItem;
                    }
                    else {
                      if (uVar6 < 0x38) {
                        dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                mBits[uVar6 + 5];
                      }
                      else {
                        dVar1 = InvalidItem;
                      }
                    }
                  }
                }
              }
            }
          }
          d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar5] = dVar1;
          uVar6 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                              mInventorySlotIndexOnButton[uVar5];
          if (uVar6 < 0x15) {
            bVar2 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                    mStageName[uVar6];
          }
          else {
            if (uVar6 < 0x18) {
              bVar2 = 0xff;
            }
            else {
              if (uVar6 < 0x20) {
                bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar6 + 0xd];
              }
              else {
                if (uVar6 < 0x24) {
                  bVar2 = 0xff;
                }
                else {
                  if (uVar6 < 0x2c) {
                    bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar6 + 9];
                  }
                  else {
                    if (uVar6 < 0x30) {
                      bVar2 = 0xff;
                    }
                    else {
                      if (uVar6 < 0x38) {
                        bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                mBits[uVar6 + 5];
                      }
                      else {
                        bVar2 = 0xff;
                      }
                    }
                  }
                }
              }
            }
          }
          if (bVar2 == 0xff) {
            d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
            mInventorySlotIndexOnButton[uVar5] = -1;
          }
        }
        this[0x2403] = (dMenu_Item_c)0x3;
      }
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x817,(cXyz *)0x0,0,0,d_menu_item::_4393,d_menu_item::_4393,
                 d_menu_item::_4448,d_menu_item::_4448,0);
    }
    cVar4 = d_meter::dMeter_subWinFlag();
    if (cVar4 != '\0') {
      subWindowDelete(this);
    }
  }
  else {
    this[0x2422] = (dMenu_Item_c)0x1;
  }
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  __psq_l0(auStack24,uVar10);
  __psq_l1(auStack24,uVar10);
  __psq_l0(auStack40,uVar10);
  __psq_l1(auStack40,uVar10);
  __psq_l0(auStack56,uVar10);
  __psq_l1(auStack56,uVar10);
  return uVar8;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMenu_Item_c::_open2(void) */

bool __thiscall dMenu_Item_c::_open2(dMenu_Item_c *this)

{
  short sVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  byte bVar5;
  ___ in_r5;
  int iVar6;
  dMenu_Item_c *pdVar7;
  int iVar8;
  int iVar9;
  
  sVar3 = DAT_803e6afe;
  sVar2 = d_menu_item::g_miHIO.field_0x26;
  if (*(short *)(this + 0x23f8) != 0) goto LAB_801d20ec;
  iVar6 = 0;
  iVar9 = 0;
  iVar8 = 0;
  do {
    pdVar7 = this + iVar8;
    MSL_C.PPCEABI.bare.H::strcpy(*(char **)(pdVar7 + 0x23e0),"");
    MSL_C.PPCEABI.bare.H::strcpy(*(char **)(pdVar7 + 0x23e8),"");
    J2DTextBox::setString(*(J2DTextBox **)(this + iVar9 + 0x890),*(char **)(pdVar7 + 0x23e0),in_r5);
    iVar6 = iVar6 + 1;
    iVar9 = iVar9 + 0x38;
    iVar8 = iVar8 + 4;
  } while (iVar6 < 2);
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x778),*(char **)(this + 0x23e8),in_r5);
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x740),*(char **)(this + 0x23ec),in_r5);
  itemnameSet(this);
  if (this[0x23ff] != (dMenu_Item_c)0x15) {
    iVar6 = recollectBossCheck(this);
    if (iVar6 == 0) {
LAB_801d1fe8:
      itemnoteSet(this);
      uVar4 = (uint)(byte)this[0x23ff];
      if (uVar4 < 0x15) {
        bVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                mStageName[uVar4];
      }
      else {
        if (uVar4 < 0x18) {
          bVar5 = 0xff;
        }
        else {
          if (uVar4 < 0x20) {
            bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar4 + 0xd];
          }
          else {
            if (uVar4 < 0x24) {
              bVar5 = 0xff;
            }
            else {
              if (uVar4 < 0x2c) {
                bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar4 + 9];
              }
              else {
                if (uVar4 < 0x30) {
                  bVar5 = 0xff;
                }
                else {
                  if (uVar4 < 0x38) {
                    bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar4 + 5];
                  }
                  else {
                    bVar5 = 0xff;
                  }
                }
              }
            }
          }
        }
      }
      if (bVar5 == 0xff) {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
        d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
      }
      else {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x21;
      }
      goto LAB_801d20ec;
    }
    uVar4 = (uint)(byte)this[0x23ff];
    if (uVar4 < 0x15) {
      bVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
              [uVar4];
    }
    else {
      if (uVar4 < 0x18) {
        bVar5 = 0xff;
      }
      else {
        if (uVar4 < 0x20) {
          bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                  [uVar4 + 0xd];
        }
        else {
          if (uVar4 < 0x24) {
            bVar5 = 0xff;
          }
          else {
            if (uVar4 < 0x2c) {
              bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar4 + 9];
            }
            else {
              if (uVar4 < 0x30) {
                bVar5 = 0xff;
              }
              else {
                if (uVar4 < 0x38) {
                  bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar4 + 5];
                }
                else {
                  bVar5 = 0xff;
                }
              }
            }
          }
        }
      }
    }
    if (bVar5 != 0x56) {
      if (uVar4 < 0x15) {
        bVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                mStageName[uVar4];
      }
      else {
        if (uVar4 < 0x18) {
          bVar5 = 0xff;
        }
        else {
          if (uVar4 < 0x20) {
            bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar4 + 0xd];
          }
          else {
            if (uVar4 < 0x24) {
              bVar5 = 0xff;
            }
            else {
              if (uVar4 < 0x2c) {
                bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar4 + 9];
              }
              else {
                if (uVar4 < 0x30) {
                  bVar5 = 0xff;
                }
                else {
                  if (uVar4 < 0x38) {
                    bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar4 + 5];
                  }
                  else {
                    bVar5 = 0xff;
                  }
                }
              }
            }
          }
        }
      }
      if (bVar5 != 0x58) {
        if (uVar4 < 0x15) {
          bVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                  mStageName[uVar4];
        }
        else {
          if (uVar4 < 0x18) {
            bVar5 = 0xff;
          }
          else {
            if (uVar4 < 0x20) {
              bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar4 + 0xd];
            }
            else {
              if (uVar4 < 0x24) {
                bVar5 = 0xff;
              }
              else {
                if (uVar4 < 0x2c) {
                  bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar4 + 9];
                }
                else {
                  if (uVar4 < 0x30) {
                    bVar5 = 0xff;
                  }
                  else {
                    if (uVar4 < 0x38) {
                      bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar4 + 5];
                    }
                    else {
                      bVar5 = 0xff;
                    }
                  }
                }
              }
            }
          }
        }
        if (bVar5 != 0x59) goto LAB_801d1fe8;
      }
    }
  }
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x17;
LAB_801d20ec:
  *(short *)(this + 0x23f8) = *(short *)(this + 0x23f8) + 1;
  sVar1 = *(short *)(this + 0x23f8);
  if ((sVar1 <= sVar3) && (0 < sVar1)) {
    if (this[0x2421] == (dMenu_Item_c)0x2) {
      mainOpenProc(this,sVar1,sVar3,sVar2);
    }
    else {
      mainOpenProc(this,sVar1,sVar3,-sVar2);
    }
    titleOpenProc(this,*(short *)(this + 0x23f8),sVar3);
    noteOpenProc(this,*(short *)(this + 0x23f8),sVar3);
    nameOpenProc(this,*(short *)(this + 0x23f8),sVar3);
  }
  return sVar3 <= *(short *)(this + 0x23f8);
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801d2a24) */
/* WARNING: Removing unreachable block (ram,0x801d2a14) */
/* WARNING: Removing unreachable block (ram,0x801d2a1c) */
/* WARNING: Removing unreachable block (ram,0x801d2a2c) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMenu_Item_c::_close2(void) */

undefined4 __thiscall dMenu_Item_c::_close2(dMenu_Item_c *this)

{
  dItem_data__ItemNo dVar1;
  byte bVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  dMenu_Item_c *pdVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  undefined8 in_f28;
  double dVar14;
  undefined8 in_f29;
  double dVar15;
  undefined8 in_f30;
  double dVar16;
  undefined8 in_f31;
  double local_68;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  uVar8 = 0;
  *(short *)(this + 0x23f8) = *(short *)(this + 0x23f8) + -1;
  dVar11 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                             ((int)DAT_803e6afe,(int)DAT_803e6afe - (int)*(short *)(this + 0x23f8),0
                             );
  dVar15 = (double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                            (int)d_menu_item::g_miHIO.field_0x26 ^
                                                            0x80000000) - d_menu_item::_4395) *
                          dVar11);
  dVar11 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                             ((int)DAT_803e6afe,(int)DAT_803e6afe - (int)*(short *)(this + 0x23f8),0
                             );
  dVar14 = (double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                            (int)d_menu_item::g_miHIO.field_0x28 ^
                                                            0x80000000) - d_menu_item::_4395) *
                          dVar11);
  dVar11 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                             ((int)DAT_803e6afe,(int)DAT_803e6afe - (int)*(short *)(this + 0x23f8),0
                             );
  local_68 = (double)CONCAT44(0x43300000,(int)d_menu_item::g_miHIO.field_0x2c ^ 0x80000000);
  dVar16 = (double)(float)((double)(float)(local_68 - d_menu_item::_4395) * dVar11);
  dVar12 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                             ((int)DAT_803e6afe,(int)DAT_803e6afe - (int)*(short *)(this + 0x23f8),0
                             );
  dVar13 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                             ((int)DAT_803e6afe,(int)*(short *)(this + 0x23f8),0);
  iVar3 = 0;
  dVar11 = (double)d_menu_item::_9797;
  iVar9 = 2;
  do {
    if (*(int *)(this + iVar3 + 0x23b8) != 0) {
      *(char *)(*(int *)(this + iVar3 + 0x23b8) + 0x1ff) = (char)(int)(dVar11 * dVar13);
    }
    iVar3 = iVar3 + 4;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  if (this[0x2421] == (dMenu_Item_c)0x2) {
    mainTrans(this,(float)-dVar15,d_menu_item::_4323);
    titleTrans(this,d_menu_item::_4323,(float)dVar14);
    local_68 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x856) ^ 0x80000000);
    noteRotate(this,(float)((double)(float)((double)CONCAT44(0x43300000,
                                                             (int)d_menu_item::g_miHIO.field_0x3e ^
                                                             0x80000000) - d_menu_item::_4395) *
                           dVar12),
               (float)(local_68 - d_menu_item::_4395) +
               (float)(dVar12 * (double)(float)((double)CONCAT44(0x43300000,
                                                                 (int)d_menu_item::g_miHIO.
                                                                      field_0x2a -
                                                                 (int)*(short *)(this + 0x856) ^
                                                                 0x80000000) - d_menu_item::_4395)))
    ;
    nameTrans(this,d_menu_item::_4323,(float)dVar16);
  }
  else {
    if (this[0x2421] == (dMenu_Item_c)0x1) {
      mainTrans(this,(float)dVar15,d_menu_item::_4323);
      titleTrans(this,d_menu_item::_4323,(float)dVar14);
      local_68 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x856) ^ 0x80000000);
      noteRotate(this,(float)((double)(float)((double)CONCAT44(0x43300000,
                                                               (int)d_menu_item::g_miHIO.field_0x3e
                                                               ^ 0x80000000) - d_menu_item::_4395) *
                             dVar12),
                 (float)(local_68 - d_menu_item::_4395) +
                 (float)(dVar12 * (double)(float)((double)CONCAT44(0x43300000,
                                                                   (int)d_menu_item::g_miHIO.
                                                                        field_0x2a -
                                                                   (int)*(short *)(this + 0x856) ^
                                                                   0x80000000) - d_menu_item::_4395)
                        ));
      nameTrans(this,d_menu_item::_4323,(float)dVar16);
    }
  }
  if (*(short *)(this + 0x23f8) < 1) {
    uVar8 = 1;
    this[0x2422] = (dMenu_Item_c)0x0;
    iVar3 = 0;
    iVar9 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar9 + 0xb0));
      iVar3 = iVar3 + 1;
      iVar9 = iVar9 + 0x38;
    } while (iVar3 < 0xf);
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
    iVar3 = 0;
    iVar9 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar9 + 0xa18));
      iVar3 = iVar3 + 1;
      iVar9 = iVar9 + 0x38;
    } while (iVar3 < 4);
    iVar3 = 0;
    iVar9 = 0;
    do {
      pdVar7 = this + iVar9;
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar7 + 0xaf8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar7 + 0xcb8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar7 + 0xe78));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar7 + 0x1070));
      iVar3 = iVar3 + 1;
      iVar9 = iVar9 + 0x38;
    } while (iVar3 < 8);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1038));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1230));
    iVar3 = 0;
    iVar9 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar9 + 0x1268));
      iVar3 = iVar3 + 1;
      iVar9 = iVar9 + 0x38;
    } while (iVar3 < 9);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1460));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1498));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x14d0));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1508));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1540));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1578));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x15b0));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x15e8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1620));
    iVar3 = 0;
    iVar9 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar9 + 0x1658));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar9 + 0x1af0));
      iVar3 = iVar3 + 1;
      iVar9 = iVar9 + 0x38;
    } while (iVar3 < 0x15);
    iVar3 = 0;
    iVar9 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar9 + 0x1f88));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar9 + 0x2030));
      iVar3 = iVar3 + 1;
      iVar9 = iVar9 + 0x38;
    } while (iVar3 < 3);
    iVar3 = 0;
    iVar9 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar9 + 0x20d8));
      iVar3 = iVar3 + 1;
      iVar9 = iVar9 + 0x38;
    } while (iVar3 < 6);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x2228));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x2260));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x2298));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x22d0));
    if ((byte)this[0x2404] != 3) {
      *(dMenu_Item_c *)
       (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
        mInventorySlotIndexOnButton + (byte)this[0x2404]) = this[0x2401];
      uVar6 = (uint)(byte)this[0x2404];
      uVar5 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                          mInventorySlotIndexOnButton[uVar6];
      if (uVar5 == 0xff) {
        d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar6] = InvalidItem;
      }
      else {
        if (uVar5 < 0x15) {
          dVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                  mStageName[uVar5];
        }
        else {
          if (uVar5 < 0x18) {
            dVar1 = InvalidItem;
          }
          else {
            if (uVar5 < 0x20) {
              dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar5 + 0xd];
            }
            else {
              if (uVar5 < 0x24) {
                dVar1 = InvalidItem;
              }
              else {
                if (uVar5 < 0x2c) {
                  dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar5 + 9];
                }
                else {
                  if (uVar5 < 0x30) {
                    dVar1 = InvalidItem;
                  }
                  else {
                    if (uVar5 < 0x38) {
                      dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar5 + 5];
                    }
                    else {
                      dVar1 = InvalidItem;
                    }
                  }
                }
              }
            }
          }
        }
        d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar6] = dVar1;
        uVar5 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                            mInventorySlotIndexOnButton[uVar6];
        if (uVar5 < 0x15) {
          bVar2 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                  mStageName[uVar5];
        }
        else {
          if (uVar5 < 0x18) {
            bVar2 = 0xff;
          }
          else {
            if (uVar5 < 0x20) {
              bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar5 + 0xd];
            }
            else {
              if (uVar5 < 0x24) {
                bVar2 = 0xff;
              }
              else {
                if (uVar5 < 0x2c) {
                  bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar5 + 9];
                }
                else {
                  if (uVar5 < 0x30) {
                    bVar2 = 0xff;
                  }
                  else {
                    if (uVar5 < 0x38) {
                      bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar5 + 5];
                    }
                    else {
                      bVar2 = 0xff;
                    }
                  }
                }
              }
            }
          }
        }
        if (bVar2 == 0xff) {
          d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
          mInventorySlotIndexOnButton[uVar6] = -1;
        }
      }
      this[0x2404] = (dMenu_Item_c)0x3;
      if ((byte)this[0x2403] != 3) {
        *(dMenu_Item_c *)
         (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
          mInventorySlotIndexOnButton + (byte)this[0x2403]) = this[0x2402];
        uVar5 = (uint)(byte)this[0x2403];
        uVar6 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                            mInventorySlotIndexOnButton[uVar5];
        if (uVar6 == 0xff) {
          d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar5] = InvalidItem;
        }
        else {
          if (uVar6 < 0x15) {
            dVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                    mStageName[uVar6];
          }
          else {
            if (uVar6 < 0x18) {
              dVar1 = InvalidItem;
            }
            else {
              if (uVar6 < 0x20) {
                dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar6 + 0xd];
              }
              else {
                if (uVar6 < 0x24) {
                  dVar1 = InvalidItem;
                }
                else {
                  if (uVar6 < 0x2c) {
                    dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar6 + 9];
                  }
                  else {
                    if (uVar6 < 0x30) {
                      dVar1 = InvalidItem;
                    }
                    else {
                      if (uVar6 < 0x38) {
                        dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                mBits[uVar6 + 5];
                      }
                      else {
                        dVar1 = InvalidItem;
                      }
                    }
                  }
                }
              }
            }
          }
          d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar5] = dVar1;
          uVar6 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                              mInventorySlotIndexOnButton[uVar5];
          if (uVar6 < 0x15) {
            bVar2 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                    mStageName[uVar6];
          }
          else {
            if (uVar6 < 0x18) {
              bVar2 = 0xff;
            }
            else {
              if (uVar6 < 0x20) {
                bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar6 + 0xd];
              }
              else {
                if (uVar6 < 0x24) {
                  bVar2 = 0xff;
                }
                else {
                  if (uVar6 < 0x2c) {
                    bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar6 + 9];
                  }
                  else {
                    if (uVar6 < 0x30) {
                      bVar2 = 0xff;
                    }
                    else {
                      if (uVar6 < 0x38) {
                        bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                mBits[uVar6 + 5];
                      }
                      else {
                        bVar2 = 0xff;
                      }
                    }
                  }
                }
              }
            }
          }
          if (bVar2 == 0xff) {
            d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
            mInventorySlotIndexOnButton[uVar5] = -1;
          }
        }
        this[0x2403] = (dMenu_Item_c)0x3;
      }
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x817,(cXyz *)0x0,0,0,d_menu_item::_4393,d_menu_item::_4393,
                 d_menu_item::_4448,d_menu_item::_4448,0);
    }
    cVar4 = d_meter::dMeter_subWinFlag();
    if (cVar4 != '\0') {
      subWindowDelete(this);
    }
  }
  else {
    this[0x2422] = (dMenu_Item_c)0x1;
  }
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  __psq_l0(auStack24,uVar10);
  __psq_l1(auStack24,uVar10);
  __psq_l0(auStack40,uVar10);
  __psq_l1(auStack40,uVar10);
  __psq_l0(auStack56,uVar10);
  __psq_l1(auStack56,uVar10);
  return uVar8;
}


/* __thiscall dMenu_Item_c::~dMenu_Item_c(void) */

void __thiscall dMenu_Item_c::_dMenu_Item_c(dMenu_Item_c *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dMenu_Item_c *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined1 **)this = &dMenu_base_c::__vt, bVar1)) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMenu_Item_c::draw(void) */

void __thiscall dMenu_Item_c::draw(dMenu_Item_c *this)

{
  (**(code **)(*(int *)this + 0x1c))();
  return;
}


/* __thiscall dMi_HIO_c::~dMi_HIO_c(void) */

void __thiscall dMi_HIO_c::_dMi_HIO_c(dMi_HIO_c *this)

{
  short in_r4;
  
  if ((this != (dMi_HIO_c *)0x0) && (this->field_0x0 = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace d_menu_item {

void __sinit_d_menu_item_cpp(void)

{
  ::dMi_HIO_c::dMi_HIO_c(&g_miHIO);
  Runtime.PPCEABI.H::__register_global_object();
  return;
}

